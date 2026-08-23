"""
Hash-consed DAG + Taylor-mode forward AD for libxc code generation.

The legacy path differentiates the assembled SymPy expression with repeated
``sp.diff``. The k-th derivative of a product is intrinsically large, so the
intermediate tree grows ~exponentially in the derivative order even though the
final CSE'd C is small -- this is what makes the high-order generation of
helper-heavy correlation functionals take hours.

This engine avoids materialising that tree. The computation is lowered to a
hash-consed straight-line DAG, and every requested mixed partial is built by
Taylor-mode forward AD *over the DAG*: each derivative quantity is a new node
referencing existing nodes (incremental common-subexpression elimination), so
intermediates never expand. The emitted program is the DAG itself -- already
CSE'd.

Each unary function's jet recurrence is derived from the identity
``D_i w = f'(u) * D_i u`` matched coefficient-wise, where ``D_i`` is the partial
in variable i; this generalises cleanly to mixed partials. f'(u) is either an
independently computable jet (erf, log1p) or, for the exp/Riccati family
(exp, expm1, tanh), depends on the lower-order coefficients already in hand.

This module is intentionally standalone and dependency-light (just SymPy); the
``__main__`` self-test validates every rule against ``sp.diff`` numerically.
Helper inlining, libxc input-variable mapping, and C emission build on top.
"""
import itertools
import math
from fractions import Fraction
from math import factorial, prod

import sympy as sp

# Elementary rewrites of the libxc special-function heads, used only to evaluate
# constant-argument occurrences (e.g. my_dilog(-1) = Li_2(-1)) in the mpmath
# reference path -- sympy's .evalf leaves the custom heads symbolic otherwise.
_CONST_SPECIAL = {
    "my_dilog": lambda a: sp.polylog(2, a),
    "xc_erfcx": lambda a: sp.exp(a ** 2) * sp.erfc(a),
    "xc_E1_scaled": lambda a: sp.exp(a) * sp.expint(1, a),
    "xc_log1p": lambda a: sp.log(1 + a),
    "xc_expm1": lambda a: sp.exp(a) - 1,
    "x_minus_log1p": lambda a: a - sp.log(1 + a),
    "sech": lambda a: 1 / sp.cosh(a),
}


def _eval_const_specials(v, digits):
    """sp.N(v, digits) with constant-argument special-function heads lowered to
    elementary so they evaluate numerically (my_dilog(-1), xc_erfcx(2), ...).

    Folds to a fixpoint: heads can nest (xc_expm1(5*xc_log1p(0)/3)), and lowering
    the inner one turns the outer argument into a fresh constant, so a single
    pass over the original atoms would step past the newly-constant outer head
    and leave a residual it cannot mpf()."""
    changed = True
    while changed:
        changed = False
        for fn in list(v.atoms(sp.Function)):
            rep = _CONST_SPECIAL.get(type(fn).__name__)
            if rep is not None and all(getattr(x, "is_number", False)
                                       for x in fn.args):
                new = v.subs(fn, rep(*fn.args))
                if new != v:
                    v = new
                    changed = True
    return sp.N(v, digits)


class _Poison:
    """A node value that failed to evaluate.  DAG.evaluate assigns one
    instead of aborting, because the node may sit in a select branch whose
    guard exists precisely to skip it; the carried exception resurfaces only
    when a live consumer touches the value."""
    __slots__ = ("exc",)

    def __init__(self, exc):
        self.exc = exc


def _cond_node_refs(cond, out):
    """Collect the DAG node indices a lowered condition tree reads."""
    if not isinstance(cond, tuple):
        return
    tag = cond[0]
    if tag == "rel":
        out.append(cond[2])
        out.append(cond[3])
    elif tag in ("and", "or"):
        for child in cond[1]:
            _cond_node_refs(child, out)
    elif tag == "not":
        _cond_node_refs(cond[1], out)


# ---------------------------------------------------------------------------
# Hash-consed DAG of straight-line operations.
# Leaves are variables; constants carry an exact SymPy value (rationals and
# functional parameters). Identical (op, args, data) tuples collapse to one
# node, so the DAG is CSE'd by construction.
# ---------------------------------------------------------------------------
class DAG:
    def __init__(self):
        self.op, self.l, self.r, self.k = [], [], [], []
        self._hc = {}
        self._leaves = {}
        # Frozen piecewise conditions are not differentiated, but their value
        # expressions should still share the arithmetic DAG used by branches.
        self._condition_cache = {}
        self._condition_value_memo = {}
        self.ZERO = self.const(sp.Integer(0))
        self.ONE = self.const(sp.Integer(1))

    def _node(self, op, l=-1, r=-1, k=None):
        key = (op, l, r, k)
        j = self._hc.get(key)
        if j is not None:
            return j
        j = len(self.op)
        self.op.append(op)
        self.l.append(l)
        self.r.append(r)
        self.k.append(k)
        self._hc[key] = j
        return j

    # -- leaves and constants --
    def const(self, value):
        return self._node("const", k=sp.sympify(value))

    def leaf(self, sym):
        if sym not in self._leaves:
            self._leaves[sym] = self._node("leaf", k=sym)
        return self._leaves[sym]

    def _cval(self, a):
        return self.k[a] if self.op[a] == "const" else None

    # -- arithmetic with constant folding and the 0/1 identities --
    def add(self, a, b):
        if a == self.ZERO:
            return b
        if b == self.ZERO:
            return a
        ca, cb = self._cval(a), self._cval(b)
        if ca is not None and cb is not None:
            return self.const(ca + cb)
        if b < a:
            a, b = b, a
        return self._node("add", a, b)

    def mul(self, a, b):
        if a == self.ZERO or b == self.ZERO:
            return self.ZERO
        if a == self.ONE:
            return b
        if b == self.ONE:
            return a
        ca, cb = self._cval(a), self._cval(b)
        if ca is not None and cb is not None:
            return self.const(ca * cb)
        if b < a:
            a, b = b, a
        return self._node("mul", a, b)

    def cmul(self, c, a):
        """Multiply node a by an exact constant c (rational/SymPy)."""
        c = sp.sympify(c)
        if c == 0:
            return self.ZERO
        if c == 1:
            return a
        cv = self._cval(a)
        if cv is not None:
            return self.const(c * cv)
        return self._node("cmul", a, k=c)

    def sub(self, a, b):
        return self.add(a, self.cmul(-1, b))

    def div(self, a, b):
        if a == self.ZERO:
            return self.ZERO
        if b == self.ONE:
            return a
        ca, cb = self._cval(a), self._cval(b)
        if ca is not None and cb is not None:
            return self.const(ca / cb)
        return self._node("div", a, b)

    def powc(self, a, p):
        """a raised to a constant power p."""
        p = sp.sympify(p)
        if p == 0:
            return self.ONE
        if p == 1:
            return a
        cv = self._cval(a)
        if cv is not None:
            return self.const(cv ** p)
        return self._node("powc", a, k=p)

    def unary(self, op, a):
        return self._node(op, a)

    @staticmethod
    def _br_root_float(Q, kind, prec=None):
        """Becke-Roussel inverse root (bracket + bisection). ``prec=None`` is the
        float self-test oracle; ``prec`` set runs in mpmath at ``prec+30`` digits
        for the arbitrary-precision reference. Mirrors eval_reference's
        _br89_x_mpmath / _mbrxc_x_mpmath."""
        if prec is not None:
            import mpmath
            mpmath.mp.dps = int(prec) + 30
            Q = mpmath.mpf(Q)
            two, three, five = mpmath.mpf(2), mpmath.mpf(3), mpmath.mpf(5)
            tiny = mpmath.mpf(10) ** (-(int(prec) + 12))
            if kind == "br89_x":
                if abs(Q) < tiny:
                    return two
                rhs = (two / 3) * mpmath.pi ** (two / 3) / Q
                f = lambda x: x * mpmath.exp(-2 * x / 3) - rhs * (x - 2)
                a, b = (two, 1 / rhs + 2) if rhs > 0 else (mpmath.mpf(0), two)
            else:
                if abs(Q) < tiny:
                    return three
                rhs = (32 * mpmath.pi) ** (two / 3) / (6 * Q)
                f = lambda x: (1 + x) ** (five / 3) * mpmath.exp(-2 * x / 3) \
                    - rhs * (x - 3)
                a, b = (three, 2 / rhs + 3) if rhs > 0 else (mpmath.mpf(0), three)
            fa = f(a)
            for _ in range(int((int(prec) + 30) * 3.34) + 20):
                m = (a + b) / 2
                fm = f(m)
                if fa * fm <= 0:
                    b = m
                else:
                    a, fa = m, fm
            return (a + b) / 2
        if kind == "br89_x":
            if abs(Q) < 4.4e-16:
                return 2.0
            rhs = (2.0 / 3.0) * math.pi ** (2.0 / 3.0) / Q
            f = lambda x: x * math.exp(-2 * x / 3) - rhs * (x - 2)
            a, b = (2.0, 1.0 / rhs + 2.0) if rhs > 0 else (0.0, 2.0)
        else:                                                   # mbrxc_x
            if abs(Q) < 4.4e-16:
                return 3.0
            rhs = (32 * math.pi) ** (2.0 / 3.0) / (6 * Q)
            f = lambda x: (1 + x) ** (5.0 / 3.0) * math.exp(-2 * x / 3) \
                - rhs * (x - 3)
            a, b = (3.0, 2.0 / rhs + 3.0) if rhs > 0 else (0.0, 3.0)
        fa = f(a)
        for _ in range(80):
            m = 0.5 * (a + b)
            fm = f(m)
            if fa * fm <= 0:
                b = m
            else:
                a, fa = m, fm
        return 0.5 * (a + b)

    def select(self, cond, a, b):
        """Frozen-condition branch select.

        ``cond`` is normally a compact lowered condition tree, but a raw SymPy
        Boolean remains accepted for generic callers and backwards-compatible
        self-tests.  Conditions are never differentiated.
        """
        if a == b:
            return a
        return self._node("select", a, b, k=cond)

    # -- numeric evaluation (self-test oracle / arbitrary-precision reference) --
    def evaluate(self, var_env, param_env=None, prec=None):
        """Numerically evaluate every DAG node -- values AND the Taylor-jet
        nodes built by ``to_jet`` -- in one pass. With ``prec=None`` this is the
        Python-float/``math`` self-test oracle. With ``prec`` set it runs in
        mpmath at ``prec`` decimal digits (working precision ``prec+30``), so
        the same jet nodes yield arbitrary-precision derivatives: the fast
        reference generator. Leaf/param values in ``*_env`` must then be mpf."""
        param_env = param_env or {}
        cond_env = {**var_env, **param_env}
        saved_dps = None
        if prec is None:
            F = math
            zero = 0.0

            def num(e):
                return float(e) if e.is_number else float(e.subs(param_env))
        else:
            import mpmath as F
            wp = int(prec) + 30
            # Scope the precision: leaking a raised mp.dps to the caller is
            # the pattern that masked the ambient-precision parameter bug.
            saved_dps = F.mp.dps
            F.mp.dps = wp
            zero = F.mpf(0)

            def num(e):
                v = e if e.is_number else e.subs(param_env)
                r = sp.N(v, wp + 5)
                if r.atoms(sp.Function):
                    # residual special-function constant (e.g. my_dilog(-1) =
                    # Li_2(-1)); lower to elementary so mpmath can evaluate it.
                    r = _eval_const_specials(v, wp + 5)
                return F.mpf(str(r))

        # The node array is topologically ordered, so a dead select branch is
        # evaluated BEFORE the select that discards it -- a guarded 1/x at
        # x = 0 used to abort the whole evaluation even though the guard
        # exists precisely to skip it. Mirror the emitted C instead (a
        # ternary evaluates both branches; IEEE non-trapping carries the
        # dead NaN away): a node that raises is assigned a _Poison carrying
        # the exception, every op consuming a poison propagates it (the
        # arithmetic/F.* call rejects the foreign type, landing in the same
        # handler), and only a select whose condition or LIVE branch is
        # poisoned surfaces the original error -- at the caller, when the
        # value is actually used.
        val = [zero] * len(self.op)
        try:
            for i, o in enumerate(self.op):
                try:
                    val[i] = self._eval_node(i, o, val, var_env, cond_env,
                                             num, F, prec)
                except Exception as e:
                    poison = None
                    for j in (self.l[i], self.r[i]):
                        if (isinstance(j, int) and 0 <= j < i
                                and isinstance(val[j], _Poison)):
                            poison = val[j]      # keep the root cause
                            break
                    val[i] = poison if poison is not None else _Poison(e)
        finally:
            if saved_dps is not None:
                F.mp.dps = saved_dps
        return val

    def _eval_node(self, i, o, val, var_env, cond_env, num, F, prec):
        if o == "select":
            # A poisoned value inside the CONDITION is a genuine failure:
            # the guard itself cannot be decided.  Re-raise the root cause
            # rather than letting the comparison die on the foreign type.
            refs = []
            _cond_node_refs(self.k[i], refs)
            for j in refs:
                if isinstance(val[j], _Poison):
                    raise val[j].exc
            cond = _eval_condition(self.k[i], val, cond_env)
            chosen = val[self.l[i]] if cond else val[self.r[i]]
            if isinstance(chosen, _Poison):
                raise chosen.exc             # live branch genuinely failed
            return chosen
        if o == "const":
            return num(self.k[i])
        if o == "leaf":
            return var_env[self.k[i]]
        # Reject poisoned inputs up front so the propagation handler in
        # evaluate() keeps the ROOT exception rather than a downstream
        # type error.
        for j in (self.l[i], self.r[i]):
            if isinstance(j, int) and isinstance(val[j], _Poison):
                raise val[j].exc
        if o == "add":
            return val[self.l[i]] + val[self.r[i]]
        if o == "mul":
            return val[self.l[i]] * val[self.r[i]]
        if o == "cmul":
            return num(self.k[i]) * val[self.l[i]]
        if o == "div":
            return val[self.l[i]] / val[self.r[i]]
        if o == "powc":
            return val[self.l[i]] ** num(self.k[i])
        if o == "exp":
            return F.exp(val[self.l[i]])
        if o == "log":
            return F.log(val[self.l[i]])
        if o == "expm1":
            return F.expm1(val[self.l[i]])
        if o == "log1p":
            return F.log1p(val[self.l[i]])
        if o == "tanh":
            return F.tanh(val[self.l[i]])
        if o == "erf":
            return F.erf(val[self.l[i]])
        if o == "erfc":
            return F.erfc(val[self.l[i]])
        if o == "atan":
            return F.atan(val[self.l[i]])
        if o == "asinh":
            return F.asinh(val[self.l[i]])
        if o == "atanh":
            return F.atanh(val[self.l[i]])
        if o == "x_minus_log1p":
            return val[self.l[i]] - F.log1p(val[self.l[i]])
        if o == "sin":
            return F.sin(val[self.l[i]])
        if o == "cos":
            return F.cos(val[self.l[i]])
        if o == "sinh":
            return F.sinh(val[self.l[i]])
        if o == "cosh":
            return F.cosh(val[self.l[i]])
        if o == "atan2":
            return F.atan2(val[self.l[i]], val[self.r[i]])
        if o in ("br89_x", "mbrxc_x"):
            return self._br_root_float(val[self.l[i]], o, prec)
        if o in ("br89_x_d1", "br89_x_d2", "br89_x_d3", "br89_x_d4",
                 "mbrxc_x_d1", "mbrxc_x_d2", "mbrxc_x_d3", "mbrxc_x_d4"):
            k = int(o[-1])
            return _br_jet(val[self.l[i]], k, o[:-3], prec)[k]
        if o == "LambertW":
            return _lambertw_jet(val[self.l[i]], 0, prec)[0]
        if o in ("LambertW_d1", "LambertW_d2", "LambertW_d3", "LambertW_d4"):
            k = int(o[-1])
            return _lambertw_jet(val[self.l[i]], k, prec)[k]
        if o == "xc_E1_scaled":
            return _e1_scaled_jet(val[self.l[i]], 0, prec)[0]
        if o in ("xc_E1_scaled_d1", "xc_E1_scaled_d2",
                 "xc_E1_scaled_d3", "xc_E1_scaled_d4"):
            k = int(o[-1])
            return _e1_scaled_jet(val[self.l[i]], k, prec)[k]
        if o == "sign":
            v = val[self.l[i]]
            return (math.copysign(1.0, v) if prec is None
                    else (F.mpf(1) if v >= 0 else F.mpf(-1)))
        if o == "xc_erfcx":
            return _erfcx_jet(val[self.l[i]], 0, prec)[0]
        if o in ("xc_erfcx_d1", "xc_erfcx_d2", "xc_erfcx_d3", "xc_erfcx_d4"):
            k = int(o[-1])
            return _erfcx_jet(val[self.l[i]], k, prec)[k]
        if o in ("xc_bessel_I0", "xc_bessel_I1"):
            import mpmath
            b = mpmath.besseli(0 if o.endswith("I0") else 1, val[self.l[i]])
            return float(b) if prec is None else b
        if o == "sech":
            return 1 / F.cosh(val[self.l[i]])
        if o == "my_dilog":
            return _dilog_jet(val[self.l[i]], 0, prec)[0]
        if o in ("my_dilog_d1", "my_dilog_d2", "my_dilog_d3", "my_dilog_d4"):
            k = int(o[-1])
            return _dilog_jet(val[self.l[i]], k, prec)[k]
        raise ValueError(f"eval: unknown op {o}")

    def size(self):
        return len(self.op)


# ---------------------------------------------------------------------------
# Multi-index machinery.
# ---------------------------------------------------------------------------
def multi_indices(n, order):
    """All length-n multi-indices of total degree <= order, sorted by total."""
    out = []
    for tot in range(order + 1):
        for combo in itertools.combinations_with_replacement(range(n), tot):
            a = [0] * n
            for k in combo:
                a[k] += 1
            out.append(tuple(a))
    return out


def _below(alpha):
    return itertools.product(*[range(a + 1) for a in alpha])


def _sub(a, b):
    return tuple(x - y for x, y in zip(a, b))


def _first_nonzero(a):
    for i, x in enumerate(a):
        if x:
            return i
    return -1


class Jet:
    """Sparse multi-index -> DAG node, holding Taylor coefficients
    a[alpha] = (D^alpha f) / alpha!."""

    __slots__ = ("d", "c")

    def __init__(self, dag):
        self.d = dag
        self.c = {}

    def get(self, alpha):
        return self.c.get(alpha, self.d.ZERO)

    def put(self, alpha, node):
        if node != self.d.ZERO:
            self.c[alpha] = node


# ---------------------------------------------------------------------------
# Jet construction rules.
# ---------------------------------------------------------------------------
def jet_const(d, value, n):
    J = Jet(d)
    J.put((0,) * n, d.const(value))
    return J


def jet_leaf(d, sym, pos, n):
    J = Jet(d)
    J.put((0,) * n, d.leaf(sym))
    J.put(tuple(1 if i == pos else 0 for i in range(n)), d.ONE)
    return J


def jet_add(d, U, V, idx):
    W = Jet(d)
    for a in idx:
        W.put(a, d.add(U.get(a), V.get(a)))
    return W


def jet_mul(d, U, V, idx):
    W = Jet(d)
    for a in idx:
        s = d.ZERO
        for b in _below(a):
            s = d.add(s, d.mul(U.get(b), V.get(_sub(a, b))))
        W.put(a, s)
    return W


def _chain(d, U, P, w0, idx):
    """w with w[0]=w0 and D_i w = (df/du)*D_i u given the jet P=df/du (known)."""
    n = len(idx[0])
    W = Jet(d)
    W.put((0,) * n, w0)
    for a in idx:
        if sum(a) == 0:
            continue
        i = _first_nonzero(a)
        s = d.ZERO
        rng = [range(a[k] + (0 if k == i else 1)) for k in range(n)]  # b_i<=a_i-1
        for b in itertools.product(*rng):
            s = d.add(s, d.cmul(a[i] - b[i], d.mul(P.get(b), U.get(_sub(a, b)))))
        W.put(a, d.cmul(Fraction(1, a[i]), s))
    return W


def jet_exp(d, U, idx, value_op="exp"):
    """w = exp(u): here df/du = w itself, so the recurrence is self-referential
    but only on strictly-lower-order coefficients (so well-defined)."""
    n = len(idx[0])
    z = (0,) * n
    W = Jet(d)
    W.put(z, d.unary(value_op, U.get(z)))
    for a in idx:
        if sum(a) == 0:
            continue
        i = _first_nonzero(a)
        s = d.ZERO
        rng = [range(a[k] + (0 if k == i else 1)) for k in range(n)]
        for b in itertools.product(*rng):
            s = d.add(s, d.cmul(a[i] - b[i], d.mul(W.get(b), U.get(_sub(a, b)))))
        W.put(a, d.cmul(Fraction(1, a[i]), s))
    return W


def jet_expm1(d, U, idx):
    """Derivatives equal exp's; only the value coefficient uses expm1 (the
    cancellation-free form for u -> 0)."""
    W = jet_exp(d, U, idx)
    W.c[(0,) * len(idx[0])] = d.unary("expm1", U.get((0,) * len(idx[0])))
    return W


def jet_log(d, U, idx, value_op="log", inner=None):
    """w = log(u): u*D_i w = D_i u. inner overrides the argument used for the
    value op (log1p passes u-1 ... handled by caller)."""
    n = len(idx[0])
    z = (0,) * n
    u0 = U.get(z)
    W = Jet(d)
    W.put(z, d.unary(value_op, inner if inner is not None else u0))
    for a in idx:
        if sum(a) == 0:
            continue
        i = _first_nonzero(a)
        s = d.cmul(a[i], U.get(a))
        rng = [range(a[k] + (0 if k == i else 1)) for k in range(n)]
        for b in itertools.product(*rng):
            if sum(b) == 0:
                continue
            s = d.sub(s, d.cmul(a[i] - b[i], d.mul(U.get(b), W.get(_sub(a, b)))))
        W.put(a, d.div(d.cmul(Fraction(1, a[i]), s), u0))
    return W


def jet_log1p(d, V, idx):
    """w = log(1+v). Same recurrence as log on u=1+v, but the value coefficient
    is xc_log1p(v) (cancellation-free for v -> 0)."""
    n = len(idx[0])
    one = jet_const(d, 1, n)
    U = jet_add(d, one, V, idx)            # u = 1 + v
    return jet_log(d, U, idx, value_op="log1p", inner=V.get((0,) * n))


def jet_powc(d, U, p, idx):
    """w = u**p: u*D_i w = p*(D_i u)*w."""
    p = sp.sympify(p)
    n = len(idx[0])
    z = (0,) * n
    # Non-negative integer powers are smooth everywhere (in particular at u=0,
    # e.g. w=0 when omega=0 in screened functionals); build them by repeated
    # multiplication so the jet never divides by u0 (the recurrence below is
    # u*D_i w = p*(D_i u)*w, which is 0/0 at u0=0). This keeps u**k well-defined
    # at u=0 instead of leaking NaN into derivatives.
    # sp.Float(2.0).is_integer is None, not True -- test the VALUE, so a
    # float-literal integer exponent also takes the smooth path instead of
    # the u0-dividing recurrence (NaN at u0 = 0 where u**2 is exact).
    if (p.is_integer or (p.is_number and p.is_real and p == int(p))) and p >= 0:
        k = int(p)
        if k == 0:
            return jet_const(d, 1, n)
        W = U
        for _ in range(k - 1):
            W = jet_mul(d, W, U, idx)
        return W
    u0 = U.get(z)
    W = Jet(d)
    W.put(z, d.powc(u0, p))
    for a in idx:
        if sum(a) == 0:
            continue
        i = _first_nonzero(a)
        rng1 = [range(1, a[i] + 1) if k == i else range(a[k] + 1) for k in range(n)]
        s1 = d.ZERO
        for g in itertools.product(*rng1):
            s1 = d.add(s1, d.cmul(g[i], d.mul(U.get(g), W.get(_sub(a, g)))))
        rng2 = [range(a[k] + (0 if k == i else 1)) for k in range(n)]
        s2 = d.ZERO
        for g in itertools.product(*rng2):
            if sum(g) == 0:
                continue
            s2 = d.add(s2, d.cmul(a[i] - g[i], d.mul(U.get(g), W.get(_sub(a, g)))))
        num = d.sub(d.cmul(p, s1), s2)
        W.put(a, d.div(d.cmul(Fraction(1, a[i]), num), u0))
    return W


def jet_tanh(d, U, idx):
    """w = tanh(u): df/du = 1 - w**2 (Riccati). P depends only on lower-order
    coefficients of w, so it is built on the fly."""
    n = len(idx[0])
    z = (0,) * n
    W = Jet(d)
    W.put(z, d.unary("tanh", U.get(z)))

    def P(beta):                            # (1 - w*w)[beta]
        s = d.ZERO
        for g in _below(beta):
            s = d.add(s, d.mul(W.get(g), W.get(_sub(beta, g))))
        base = d.ONE if sum(beta) == 0 else d.ZERO
        return d.sub(base, s)

    for a in idx:
        if sum(a) == 0:
            continue
        i = _first_nonzero(a)
        s = d.ZERO
        rng = [range(a[k] + (0 if k == i else 1)) for k in range(n)]
        for b in itertools.product(*rng):
            s = d.add(s, d.cmul(a[i] - b[i], d.mul(P(b), U.get(_sub(a, b)))))
        W.put(a, d.cmul(Fraction(1, a[i]), s))
    return W


def jet_erf(d, U, idx, sign=1):
    """w = erf(u) (sign=+1) or erfc(u) (sign=-1): df/du = sign*2/sqrt(pi)*exp(-u^2)."""
    n = len(idx[0])
    z = (0,) * n
    u2 = jet_mul(d, U, U, idx)
    negu2 = Jet(d)
    for a in idx:
        negu2.put(a, d.cmul(-1, u2.get(a)))
    E = jet_exp(d, negu2, idx)
    coeff = sp.sympify(sign) * 2 / sp.sqrt(sp.pi)
    P = Jet(d)
    for a in idx:
        P.put(a, d.cmul(coeff, E.get(a)))
    w0 = d.unary("erf" if sign == 1 else "erfc", U.get(z))
    return _chain(d, U, P, w0, idx)


def _one_pm_u2(d, U, idx, sign):
    """jet of 1 + sign*u^2."""
    n = len(idx[0])
    u2 = jet_mul(d, U, U, idx)
    W = jet_const(d, 1, n)
    out = Jet(d)
    for a in idx:
        out.put(a, d.add(W.get(a), d.cmul(sign, u2.get(a))))
    return out


def jet_atan(d, U, idx):
    """w = atan(u): df/du = 1/(1+u^2)."""
    P = jet_powc(d, _one_pm_u2(d, U, idx, 1), sp.Integer(-1), idx)
    return _chain(d, U, P, d.unary("atan", U.get((0,) * len(idx[0]))), idx)


def jet_asinh(d, U, idx):
    """w = asinh(u): df/du = (1+u^2)^(-1/2)."""
    P = jet_powc(d, _one_pm_u2(d, U, idx, 1), sp.Rational(-1, 2), idx)
    return _chain(d, U, P, d.unary("asinh", U.get((0,) * len(idx[0]))), idx)


def jet_atanh(d, U, idx):
    """w = atanh(u): df/du = 1/(1-u^2)."""
    P = jet_powc(d, _one_pm_u2(d, U, idx, -1), sp.Integer(-1), idx)
    return _chain(d, U, P, d.unary("atanh", U.get((0,) * len(idx[0]))), idx)


def jet_x_minus_log1p(d, U, idx):
    """w = u - log1p(u): df/du = u/(1+u); value uses the cancellation-free form."""
    n = len(idx[0])
    inv = jet_powc(d, jet_add(d, jet_const(d, 1, n), U, idx), sp.Integer(-1), idx)
    P = jet_mul(d, U, inv, idx)
    return _chain(d, U, P, d.unary("x_minus_log1p", U.get((0,) * n)), idx)


def _jet_circ(d, U, idx, s0, c0, c_sign):
    """Coupled pair S,C with S' = C*u' and C' = c_sign*S*u'. Built together in
    increasing order (each coefficient uses only lower-order ones).
      sin/cos:  S=sin, C=cos, c_sign=-1
      sinh/cosh: S=sinh, C=cosh, c_sign=+1"""
    n = len(idx[0])
    z = (0,) * n
    S, C = Jet(d), Jet(d)
    S.put(z, s0)
    C.put(z, c0)
    for a in idx:
        if sum(a) == 0:
            continue
        i = _first_nonzero(a)
        rng = [range(a[k] + (0 if k == i else 1)) for k in range(n)]
        ss = cc = d.ZERO
        for b in itertools.product(*rng):
            coeff = a[i] - b[i]
            ss = d.add(ss, d.cmul(coeff, d.mul(C.get(b), U.get(_sub(a, b)))))
            cc = d.add(cc, d.cmul(coeff, d.mul(S.get(b), U.get(_sub(a, b)))))
        S.put(a, d.cmul(Fraction(1, a[i]), ss))
        C.put(a, d.cmul(Fraction(c_sign, a[i]), cc))
    return S, C


def jet_sin(d, U, idx):
    z = (0,) * len(idx[0])
    return _jet_circ(d, U, idx, d.unary("sin", U.get(z)),
                     d.unary("cos", U.get(z)), -1)[0]


def jet_cos(d, U, idx):
    z = (0,) * len(idx[0])
    return _jet_circ(d, U, idx, d.unary("sin", U.get(z)),
                     d.unary("cos", U.get(z)), -1)[1]


def jet_cosh(d, U, idx):
    z = (0,) * len(idx[0])
    return _jet_circ(d, U, idx, d.unary("sinh", U.get(z)),
                     d.unary("cosh", U.get(z)), 1)[1]


def jet_atan2(d, Y, X, idx):
    """w = atan2(y, x): derivatives equal those of atan(y/x) (the quadrant
    offset is locally constant); only the value coefficient takes the
    correct-quadrant atan2."""
    z = (0,) * len(idx[0])
    ratio = jet_mul(d, Y, jet_powc(d, X, sp.Integer(-1), idx), idx)
    W = jet_atan(d, ratio, idx)
    W.c[z] = d._node("atan2", Y.get(z), X.get(z))
    return W


def jet_piecewise3(d, cond, T, E, idx):
    """my_piecewise3(cond, then, else): termwise branch select per coefficient,
    the condition frozen (not differentiated)."""
    W = Jet(d)
    for a in idx:
        W.put(a, d.select(cond, T.get(a), E.get(a)))
    return W


def _jet_scale(d, U, c, idx):
    """c * U for an exact constant c."""
    W = Jet(d)
    for a in idx:
        W.put(a, d.cmul(c, U.get(a)))
    return W


def _jet_shift(d, U, c, idx):
    """U + c (constant added to the value coefficient only)."""
    n = len(idx[0])
    z = (0,) * n
    W = Jet(d)
    for a in idx:
        W.put(a, U.get(a))
    W.put(z, d.add(U.get(z), d.const(c)))
    return W


def jet_compose(d, derivs, U, idx):
    """w = f(u), given the derivative VALUES f^(k)(u0) as DAG nodes derivs[0..N]
    (produced by a numerically stable C jet-helper) rather than an inline,
    cancellation-prone recurrence. Substitutes u's centred jet into f's Taylor
    series: w = sum_k derivs[k]/k! * (u - u0)^k. Each (u-u0)^k has order >= k so
    the sum is finite. This is the Faa-di-Bruno composition used by the Q3
    special-function helpers (erfcx, E1_scaled, dilog, Becke-Roussel, LambertW)."""
    import math
    n = len(idx[0])
    z = (0,) * n
    maxord = max(sum(a) for a in idx)
    Uc = Jet(d)                       # centred inner jet: u - u0
    for a in idx:
        Uc.put(a, d.ZERO if sum(a) == 0 else U.get(a))
    W = Jet(d)
    for a in idx:
        W.put(a, d.ZERO)
    W.put(z, derivs[0])
    Upow = None                       # (u - u0)^k
    for k in range(1, maxord + 1):
        Upow = Uc if k == 1 else jet_mul(d, Upow, Uc, idx)
        coef = d.cmul(Fraction(1, math.factorial(k)), derivs[k])
        for a in idx:
            if sum(a) < k:
                continue
            W.put(a, d.add(W.get(a), d.mul(coef, Upow.get(a))))
    return W


# Special functions emitted as stable C jet-helpers (Q3): the value op plus
# xc_<name>_d1..dN cancellation-free derivative ops, composed with the inner
# jet via jet_compose -- replaces the inline, cancellation-prone recurrence.
_COMPOSE_JETS = {"xc_erfcx", "xc_E1_scaled", "my_dilog", "LambertW",
                 "br89_x", "mbrxc_x"}


def _erfcx_jet(z, n, prec=None):
    """erfcx(z) and derivatives 0..n, numerically stable: asymptotic series for
    z > 8 (where the recurrence 2z*erfcx - 2/sqrt(pi) cancels), the recurrence
    from an accurate erfcx(z) below. Mirrors the emitted C xc_erfcx_jet.
    ``prec`` set -> mpmath at prec+30 digits (mpf's huge exponent range makes
    exp(z^2)*erfc(z) safe for all realistic z; the recurrence is exact)."""
    if prec is not None:
        import mpmath
        mpmath.mp.dps = int(prec) + 30
        z = mpmath.mpf(z)
        out = [mpmath.mpf(0)] * (n + 1)
        out[0] = mpmath.exp(z * z) * mpmath.erfc(z)
        if n >= 1:
            out[1] = 2 * z * out[0] - 2 / mpmath.sqrt(mpmath.pi)
        for k in range(1, n):
            out[k + 1] = 2 * z * out[k] + 2 * k * out[k - 1]
        return out
    out = [0.0] * (n + 1)
    if z > 8.0:
        s = math.sqrt(math.pi)
        for k in range(n + 1):
            ssum, am = 0.0, 1.0
            for m in range(12):
                coef = am
                for j in range(1, k + 1):
                    coef *= (2 * m + j)
                if k & 1:
                    coef = -coef
                ssum += coef / z ** (2 * m + 1 + k)
                am *= -(2 * m + 1) / 2.0
            out[k] = ssum / s
    else:
        out[0] = math.exp(z * z) * math.erfc(z)
        if n >= 1:
            out[1] = 2.0 * z * out[0] - 2.0 / math.sqrt(math.pi)
        for k in range(1, n):
            out[k + 1] = 2.0 * z * out[k] + 2.0 * k * out[k - 1]
    return out


def _e1_scaled_val(z):
    """e^z E_1(z): series for z < 1, continued fraction otherwise (mirrors the
    DAG eval and the C xc_expint_e1_impl)."""
    if z < 1.0:
        s, t, k = 0.0, 1.0, 1
        while k < 60:
            t *= -z / k
            s += t / k
            k += 1
        return math.exp(z) * (-0.5772156649015329 - math.log(z) - s)
    cf = 0.0
    for k in range(40, 0, -1):
        cf = k / (1 + k / (z + cf))
    return 1.0 / (z + cf)


def _e1_scaled_jet(z, n, prec=None):
    """e^z E_1(z) and derivatives 0..n, stable: optimal-truncation asymptotic
    for z > 18 (where the E1_scaled - 1/z recurrence cancels), the recurrence
    E1s^(k) = E1s^(k-1) + (-1)^k (k-1)!/z^k from an accurate value below.
    Mirrors the emitted C xc_E1_scaled_jet. ``prec`` set -> mpmath at prec+30
    digits (value from mpmath.e1; the recurrence is exact)."""
    if prec is not None:
        import mpmath
        mpmath.mp.dps = int(prec) + 30
        z = mpmath.mpf(z)
        out = [mpmath.mpf(0)] * (n + 1)
        out[0] = mpmath.exp(z) * mpmath.e1(z)
        fk = mpmath.mpf(1)
        for k in range(1, n + 1):
            out[k] = out[k - 1] + (-1 if (k & 1) else 1) * fk / z ** k
            fk *= k
        return out
    out = [0.0] * (n + 1)
    if z > 18.0:
        for k in range(n + 1):
            ssum, prev, num = 0.0, float("inf"), float(math.factorial(k))
            for m in range(60):
                term = num / z ** (m + 1 + k)
                if m & 1:
                    term = -term
                if abs(term) > prev:
                    break
                ssum += term
                prev = abs(term)
                num *= (m + k + 1)
            out[k] = -ssum if (k & 1) else ssum
    else:
        out[0] = _e1_scaled_val(z)
        fk = 1.0
        for k in range(1, n + 1):
            out[k] = out[k - 1] + (-1.0 if (k & 1) else 1.0) * fk / z ** k
            fk *= k
    return out


def _dilog_jet(q, n, prec=None):
    """Li_2(q) and derivatives 0..n via the power series
    Li_2^(k) = sum_{m>=max(1,k)} [m!/(m-k)!]/m^2 * q^(m-k), cancellation-free for
    q in (0,1) (the elementary derivative forms cancel near q=0). Mirrors the
    emitted C xc_dilogarithm_jet (value out[0] there uses xc_dilogarithm).
    ``prec`` set -> mpmath at prec+30 digits (value from mpmath.polylog; the
    derivative series is exact)."""
    # The series converges only inside the unit disc, and near |q| = 1 it
    # needs ~digits*ln(10)/|ln q| terms.  The iteration caps below are NOT a
    # convergence criterion: a capped partial sum is precision-independent, so
    # a base- and a check-precision run would agree on the same wrong value
    # and convergence certification would bless it.  Refuse loudly instead.
    if prec is not None:
        import mpmath
        wp = int(prec) + 30
        mpmath.mp.dps = wp
        q = mpmath.mpf(q)
        if abs(q) >= 1:
            raise ValueError(f"dilog derivative series diverges at |q| >= 1 (q = {q})")
        out = [mpmath.mpf(0)] * (n + 1)
        out[0] = mpmath.polylog(2, q)
        tol = mpmath.mpf(10) ** (-(wp))
        for k in range(1, n + 1):
            s, qp, m = mpmath.mpf(0), q ** (k - k), k          # qp = q^0 = 1
            converged = False
            while m < 2000000:
                coef = mpmath.mpf(1)
                for j in range(k):
                    coef *= (m - j)
                term = coef / (m * m) * qp
                s += term
                if abs(term) < tol * (abs(s) + tol) and m > k + 2:
                    converged = True
                    break
                qp *= q
                m += 1
            if not converged:
                raise ValueError(
                    f"dilog derivative series did not converge at q = {q} "
                    f"(order {k}, {wp} digits)")
            out[k] = s
        return out
    if abs(q) >= 1:
        raise ValueError(f"dilog derivative series diverges at |q| >= 1 (q = {q})")
    out = [0.0] * (n + 1)
    for k in range(n + 1):
        m0 = max(1, k)
        s, qp, m = 0.0, q ** (m0 - k), m0
        converged = False
        while m < 100000:
            coef = 1.0
            for j in range(k):
                coef *= (m - j)
            term = coef / (m * m) * qp
            s += term
            if abs(term) < 1e-17 * abs(s) and m > k + 2:
                converged = True
                break
            qp *= q
            m += 1
        if not converged:
            raise ValueError(
                f"dilog derivative series did not converge at q = {q} (order {k})")
        out[k] = s
    return out


def _lambertw_jet(z, n, prec=None):
    """LambertW W(z) and derivatives 0..n via series reversion of the inverse
    z(w) = w e^w (z^(k)(w) = e^w (k+w), no cancellation for w > -1). Mirrors the
    emitted C xc_lambertw_jet. ``prec`` set -> mpmath at prec+30 digits (value
    from mpmath.lambertw principal branch; the reversion formulas are exact)."""
    if prec is not None:
        import mpmath
        mpmath.mp.dps = int(prec) + 30
        z = mpmath.mpf(z)
        out = [mpmath.mpf(0)] * (n + 1)
        w = mpmath.re(mpmath.lambertw(z))
        out[0] = w
        if n < 1:
            return out
        ew = mpmath.exp(w)
        a1 = ew * (1 + w)
        out[1] = 1 / a1
        if n >= 2:
            a2 = ew * (2 + w) / 2
            out[2] = 2 * (-a2 / a1 ** 3)
        if n >= 3:
            a3 = ew * (3 + w) / 6
            out[3] = 6 * (2 * a2 * a2 - a1 * a3) / a1 ** 5
        if n >= 4:
            a4 = ew * (4 + w) / 24
            out[4] = 24 * (5 * a1 * a2 * a3 - a1 * a1 * a4
                           - 5 * a2 * a2 * a2) / a1 ** 7
        return out
    out = [0.0] * (n + 1)
    w = math.log(1 + z) if z > -0.3 else -1.0
    for _ in range(60):
        ew = math.exp(w)
        w -= (w * ew - z) / (ew * (w + 1))
    out[0] = w
    if n < 1:
        return out
    ew = math.exp(w)
    a1 = ew * (1.0 + w)
    out[1] = 1.0 / a1
    if n >= 2:
        a2 = ew * (2.0 + w) / 2.0
        out[2] = 2.0 * (-a2 / a1 ** 3)
        if n >= 3:
            a3 = ew * (3.0 + w) / 6.0
            out[3] = 6.0 * (2.0 * a2 * a2 - a1 * a3) / a1 ** 5
            if n >= 4:
                a4 = ew * (4.0 + w) / 24.0
                out[4] = 24.0 * (5.0 * a1 * a2 * a3 - a1 * a1 * a4
                                 - 5.0 * a2 * a2 * a2) / a1 ** 7
    return out


def _br_jet(Q, n, kind, prec=None):
    """Becke-Roussel inverse x(Q) and derivatives 0..n via series reversion.

    The inverse is defined by G(x) = K/Q, with G(x) = P(x) e^{-2x/3}/(x-c)
    (P = x for br89, (1+x)^(5/3) for mbrxc; c = 2, 3). Hence x(Q) is the
    inverse of Q(x) = K/G(x), NOT of F(x) = K G(x): reversing F would give
    d x/d(K G) = 1/F'(x), off from the wanted d x/dQ by a factor of the
    chain -K^2/Q^2 (and its higher-order analogues). Build the jet of
    Q(x) = K/G(x) from the elementary factor jets (reciprocal series, no
    cancellation) and reverse THAT. Matches the .py br89_x fdiff rule
    d x/dQ = -K/(Q^2 G'(x)) and the compiled-C br89_aux_dfdx derivative.
    ``prec`` set -> mpmath at prec+30 digits (root + reversion all in mpf)."""
    if prec is not None:
        import mpmath
        mpmath.mp.dps = int(prec) + 30
        mpf = mpmath.mpf
        x0 = DAG._br_root_float(Q, kind, prec)
        out = [x0] + [mpf(0)] * n
        if n < 1:
            return out
        if kind == "br89_x":
            K, c = (mpf(2) / 3) * mpmath.pi ** (mpf(2) / 3), mpf(2)
            P = [x0, mpf(1), mpf(0), mpf(0), mpf(0)]
        else:
            K, c = (32 * mpmath.pi) ** (mpf(2) / 3) / 6, mpf(3)
            o1, p, bc, P = 1 + x0, mpf(5) / 3, mpf(1), []
            for k in range(n + 1):
                P.append(o1 ** (p - k) * bc)
                bc *= (p - k) / (k + 1)
        e0, t, E = mpmath.exp(-2 * x0 / 3), mpf(1), []
        for k in range(n + 1):
            E.append(e0 * t)
            t *= -(mpf(2) / 3) / (k + 1)
        dd, dk, R = x0 - c, 1 / (x0 - c), []
        for k in range(n + 1):
            R.append(dk)
            dk *= -1 / dd

        def jmul(A, B):
            return [sum((A[j] * B[k - j] for j in range(k + 1)), mpf(0))
                    for k in range(n + 1)]
        G = jmul(jmul(P[:n + 1], E), R)         # jet of G(x) = P e^{-2x/3}/(x-c)
        H = [mpf(0)] * (n + 1)                  # jet of 1/G(x) (reciprocal series)
        H[0] = 1 / G[0]
        for k in range(1, n + 1):
            H[k] = -sum(G[j] * H[k - j] for j in range(1, k + 1)) / G[0]
        FF = [K * h for h in H]                 # jet of Q(x) = K/G(x); reverse it
        a1 = FF[1]
        out[1] = 1 / a1
        if n >= 2:
            out[2] = 2 * (-FF[2] / a1 ** 3)
        if n >= 3:
            out[3] = 6 * (2 * FF[2] ** 2 - a1 * FF[3]) / a1 ** 5
        if n >= 4:
            out[4] = 24 * (5 * a1 * FF[2] * FF[3] - a1 ** 2 * FF[4]
                           - 5 * FF[2] ** 3) / a1 ** 7
        return out
    x0 = DAG._br_root_float(Q, kind)
    out = [x0] + [0.0] * n
    if n < 1:
        return out
    if kind == "br89_x":
        K, c, P = (2.0 / 3.0) * math.pi ** (2.0 / 3.0), 2.0, [x0, 1.0, 0.0, 0.0, 0.0]
    else:
        K, c = (32.0 * math.pi) ** (2.0 / 3.0) / 6.0, 3.0
        o1, p, bc, P = 1.0 + x0, 5.0 / 3.0, 1.0, []
        for k in range(n + 1):
            P.append(o1 ** (p - k) * bc); bc *= (p - k) / (k + 1)
    e0, t, E = math.exp(-2 * x0 / 3), 1.0, []
    for k in range(n + 1):
        E.append(e0 * t); t *= -(2.0 / 3.0) / (k + 1)
    dd, dk, R = x0 - c, 1.0 / (x0 - c), []
    for k in range(n + 1):
        R.append(dk); dk *= -1.0 / dd

    def jmul(A, B):
        return [sum(A[j] * B[k - j] for j in range(k + 1)) for k in range(n + 1)]
    G = jmul(jmul(P[:n + 1], E), R)         # jet of G(x) = P e^{-2x/3}/(x-c)
    H = [0.0] * (n + 1)                     # jet of 1/G(x) (reciprocal series)
    H[0] = 1.0 / G[0]
    for k in range(1, n + 1):
        H[k] = -sum(G[j] * H[k - j] for j in range(1, k + 1)) / G[0]
    FF = [K * h for h in H]                 # jet of Q(x) = K/G(x); reverse it
    a1 = FF[1]
    out[1] = 1.0 / a1
    if n >= 2:
        out[2] = 2.0 * (-FF[2] / a1 ** 3)
    if n >= 3:
        out[3] = 6.0 * (2 * FF[2] ** 2 - a1 * FF[3]) / a1 ** 5
    if n >= 4:
        out[4] = 24.0 * (5 * a1 * FF[2] * FF[3] - a1 ** 2 * FF[4]
                         - 5 * FF[2] ** 3) / a1 ** 7
    return out


def jet_besselI(d, U, idx, order):
    """w = I_order(u), order in {0, 1}: the modified Bessel functions, coupled by
    I0' = I1 and I1' = I0 - I1/u. Build (I0, I1) together order by order (each
    coefficient uses only lower-order ones), return the requested one. Matches
    the SymPy BesselI.fdiff the legacy path differentiates."""
    n = len(idx[0])
    z = (0,) * n
    I0, I1 = Jet(d), Jet(d)
    I0.put(z, d.unary("xc_bessel_I0", U.get(z)))
    I1.put(z, d.unary("xc_bessel_I1", U.get(z)))
    maxord = max(sum(a) for a in idx)
    for m in range(1, maxord + 1):
        sub = [a for a in idx if sum(a) <= m - 1]
        # P0 = dI0/du = I1 ; P1 = dI1/du = I0 - I1/u
        P0 = I1
        P1 = jet_add(d, I0,
                     _jet_scale(d, jet_mul(d, I1,
                                           jet_powc(d, U, sp.Integer(-1), sub),
                                           sub), -1, sub), sub)
        for a in idx:
            if sum(a) != m:
                continue
            i = _first_nonzero(a)
            s0 = s1 = d.ZERO
            rng = [range(a[k] + (0 if k == i else 1)) for k in range(n)]
            for b in itertools.product(*rng):
                c = a[i] - b[i]
                ua = U.get(_sub(a, b))
                s0 = d.add(s0, d.cmul(c, d.mul(P0.get(b), ua)))
                s1 = d.add(s1, d.cmul(c, d.mul(P1.get(b), ua)))
            I0.put(a, d.cmul(Fraction(1, a[i]), s0))
            I1.put(a, d.cmul(Fraction(1, a[i]), s1))
    return I0 if order == 0 else I1


def jet_sech(d, U, idx):
    """w = sech(u) = 1/cosh(u). Built as the reciprocal of the cosh jet, so the
    value coefficient emits as pow(cosh(u), -1) (no dedicated sech C routine)."""
    z = (0,) * len(idx[0])
    C = _jet_circ(d, U, idx, d.unary("sinh", U.get(z)),
                  d.unary("cosh", U.get(z)), 1)[1]          # cosh jet
    return jet_powc(d, C, sp.Integer(-1), idx)


def jet_acsch(d, U, idx):
    """w = acsch(u) = asinh(1/u): reuse the asinh jet on the reciprocal. Value
    emits as xc_asinh(pow(u, -1)); no dedicated acsch C routine needed."""
    return jet_asinh(d, jet_powc(d, U, sp.Integer(-1), idx), idx)


def jet_abs(d, U, idx):
    """w = |u|. Away from u=0 (the non-differentiable point, where sp.diff also
    gives sign(u)*u') the absolute value equals sign(u0)*u AS A FUNCTION, so the
    whole jet is sign(u0) (a frozen copysign) times U -- value included
    (sign(u0)*u0 = |u0|)."""
    s = d.unary("sign", U.get((0,) * len(idx[0])))
    W = Jet(d)
    for a in idx:
        W.put(a, d.mul(s, U.get(a)))
    return W


# Default unary rules, keyed by SymPy function head. Extra/overriding rules
# (e.g. the functional-specific xc_expm1/xc_log1p/my_piecewise3 heads) are
# passed in via `funcs`; an n-ary handler receives the whole expression and a
# `recur` callback to lower its sub-expressions.
_UNARY_JETS = {
    sp.exp: jet_exp,
    sp.log: jet_log,
    sp.tanh: jet_tanh,
    sp.erf: lambda d, A, idx: jet_erf(d, A, idx, sign=1),
    sp.erfc: lambda d, A, idx: jet_erf(d, A, idx, sign=-1),
    sp.atan: jet_atan,
    sp.asinh: jet_asinh,
    sp.atanh: jet_atanh,
    sp.sin: jet_sin,
    sp.cos: jet_cos,
    sp.cosh: jet_cosh,
    sp.sech: jet_sech,
    sp.acsch: jet_acsch,
    sp.Abs: jet_abs,
}


def to_jet(d, expr, syms, idx, memo, funcs=None):
    """Lower a SymPy expression to its jet (memoised on subexpression identity,
    which is what gives the DAG its sharing).

    funcs maps a SymPy function head to an n-ary handler
    ``handler(dag, expr, syms, idx, memo, recur) -> Jet`` (recur lowers a
    sub-expression); it overrides the built-in unary rules."""
    funcs = funcs or {}
    if expr in memo:
        return memo[expr]
    n = len(syms)

    def recur(e):
        return to_jet(d, e, syms, idx, memo, funcs)

    if not expr.has(*syms):
        # No active variable: a constant (number, pi, parameter, or any pure
        # constant subexpression) -- a single const leaf, derivative 0.
        J = jet_const(d, expr, n)
    elif expr.is_Symbol:
        J = jet_leaf(d, expr, syms.index(expr), n)
    elif expr.is_Add:
        J = jet_const(d, 0, n)
        for t in expr.args:
            J = jet_add(d, J, recur(t), idx)
    elif expr.is_Mul:
        J = jet_const(d, 1, n)
        for t in expr.args:
            J = jet_mul(d, J, recur(t), idx)
    elif expr.is_Pow:
        base, e = expr.args
        if not e.has(*syms):                # constant exponent (number or param)
            J = jet_powc(d, recur(base), e, idx)
        else:                               # variable exponent: u**v = exp(v*log(u))
            J = recur(sp.exp(e * sp.log(base)))
    elif expr.func in funcs:
        J = funcs[expr.func](d, expr, syms, idx, memo, recur)
    elif expr.func is sp.atan2:                # 2-argument atan2(y, x)
        J = jet_atan2(d, recur(expr.args[0]), recur(expr.args[1]), idx)
    elif getattr(expr.func, "__name__", None) == "BesselI":
        # BesselI(order, arg): order is a literal 0 or 1; jet over the argument.
        J = jet_besselI(d, recur(expr.args[1]), idx, int(expr.args[0]))
    elif expr.func in _UNARY_JETS:
        J = _UNARY_JETS[expr.func](d, recur(expr.args[0]), idx)
    elif getattr(expr.func, "__name__", None) in _COMPOSE_JETS:
        # Q3: stable C jet-helper composition -- f(g)'s jet from f's
        # cancellation-free derivative values (value op + xc_<name>_dk) and g's
        # jet, instead of an inline cancelling recurrence.
        nm = expr.func.__name__
        Q = recur(expr.args[0])
        Q0 = Q.get((0,) * len(idx[0]))
        maxord = max(sum(a) for a in idx)
        derivs = [d.unary(nm, Q0)] + [
            d.unary("%s_d%d" % (nm, k), Q0) for k in range(1, maxord + 1)]
        J = jet_compose(d, derivs, Q, idx)
    else:
        raise ValueError(f"unsupported function {expr.func} in {expr}")
    memo[expr] = J
    return J




_REL_OPS = {
    sp.StrictLessThan: "<",
    sp.LessThan: "<=",
    sp.StrictGreaterThan: ">",
    sp.GreaterThan: ">=",
    sp.Equality: "==",
    sp.Unequality: "!=",
}


def lower_condition(dag, cond, syms, funcs=None):
    """Lower a frozen Boolean condition to a compact tree over DAG nodes.

    Piecewise predicates are intentionally not differentiated.  However, if
    their arithmetic is retained as an opaque SymPy expression, it bypasses
    DAG CSE and can be emitted repeatedly as enormous C conditions.  This
    lowers only zero-order values, with a separate memo, and preserves the
    original Boolean / short-circuit structure.
    """
    cached = dag._condition_cache.get(cond)
    if cached is not None:
        return cached

    zero = (0,) * len(syms)

    def value_node(expr):
        return to_jet(dag, expr, syms, [zero], dag._condition_value_memo,
                      funcs).get(zero)

    if cond is sp.true or cond is True:
        out = ("const", True)
    elif cond is sp.false or cond is False:
        out = ("const", False)
    elif type(cond) in _REL_OPS:
        out = ("rel", _REL_OPS[type(cond)],
               value_node(cond.lhs), value_node(cond.rhs))
    elif cond.func is sp.And:
        out = ("and", tuple(lower_condition(dag, a, syms, funcs)
                             for a in cond.args))
    elif cond.func is sp.Or:
        out = ("or", tuple(lower_condition(dag, a, syms, funcs)
                            for a in cond.args))
    elif cond.func is sp.Not:
        out = ("not", lower_condition(dag, cond.args[0], syms, funcs))
    else:
        # Preserve uncommon Boolean constructs verbatim rather than guessing at
        # their evaluation semantics.  They simply do not benefit from DAG CSE.
        out = ("raw", cond)

    dag._condition_cache[cond] = out
    return out


def _condition_nodes(cond):
    """Return arithmetic DAG nodes referenced by a lowered condition tree."""
    if not isinstance(cond, tuple):
        return ()
    tag = cond[0]
    if tag == "rel":
        return (cond[2], cond[3])
    if tag in ("and", "or"):
        return tuple(n for child in cond[1] for n in _condition_nodes(child))
    if tag == "not":
        return _condition_nodes(cond[1])
    return ()


def _eval_condition(cond, values, env):
    """Evaluate either a lowered condition tree or a legacy SymPy Boolean."""
    if not isinstance(cond, tuple):
        return bool(cond.subs(env))

    tag = cond[0]
    if tag == "const":
        return cond[1]
    if tag == "rel":
        a, b = values[cond[2]], values[cond[3]]
        return {
            "<": a < b, "<=": a <= b, ">": a > b, ">=": a >= b,
            "==": a == b, "!=": a != b,
        }[cond[1]]
    if tag == "and":
        return all(_eval_condition(child, values, env) for child in cond[1])
    if tag == "or":
        return any(_eval_condition(child, values, env) for child in cond[1])
    if tag == "not":
        return not _eval_condition(cond[1], values, env)
    if tag == "raw":
        return bool(cond[1].subs(env))
    raise ValueError(f"unknown condition tag {tag}")


def derivatives(expr, syms, order):
    """Return (dag, jet, idx): the DAG and the jet of every mixed partial of
    `expr` in `syms` up to total `order`. The partial D^alpha = alpha! * a[alpha]."""
    d = DAG()
    idx = multi_indices(len(syms), order)
    J = to_jet(d, expr, list(syms), idx, {})
    return d, J, idx


# ---------------------------------------------------------------------------
# C emission. The DAG is already a CSE'd straight-line program, so each node
# becomes one assignment; leaves and constants are inlined.
# ---------------------------------------------------------------------------
_C_UNARY = {"exp": "exp", "log": "log", "expm1": "xc_expm1", "log1p": "xc_log1p",
            "tanh": "tanh", "erf": "erf", "erfc": "erfc",
            "atan": "atan", "asinh": "xc_asinh", "atanh": "xc_atanh",
            "x_minus_log1p": "xc_x_minus_log1p",
            "sin": "sin", "cos": "cos", "sinh": "sinh", "cosh": "cosh",
            "br89_x": "xc_mgga_x_br89_get_x",
            "mbrxc_x": "xc_mgga_x_mbrxc_get_x",
            "br89_x_d1": "xc_br89_x_d1", "br89_x_d2": "xc_br89_x_d2",
            "br89_x_d3": "xc_br89_x_d3", "br89_x_d4": "xc_br89_x_d4",
            "mbrxc_x_d1": "xc_mbrxc_x_d1", "mbrxc_x_d2": "xc_mbrxc_x_d2",
            "mbrxc_x_d3": "xc_mbrxc_x_d3", "mbrxc_x_d4": "xc_mbrxc_x_d4",
            "my_dilog": "xc_dilogarithm",
            "my_dilog_d1": "xc_dilogarithm_d1",
            "my_dilog_d2": "xc_dilogarithm_d2",
            "my_dilog_d3": "xc_dilogarithm_d3",
            "my_dilog_d4": "xc_dilogarithm_d4",
            "LambertW": "LambertW",
            "LambertW_d1": "xc_lambertw_d1", "LambertW_d2": "xc_lambertw_d2",
            "LambertW_d3": "xc_lambertw_d3", "LambertW_d4": "xc_lambertw_d4",
            "xc_E1_scaled": "xc_E1_scaled",
            "xc_E1_scaled_d1": "xc_E1_scaled_d1",
            "xc_E1_scaled_d2": "xc_E1_scaled_d2",
            "xc_E1_scaled_d3": "xc_E1_scaled_d3",
            "xc_E1_scaled_d4": "xc_E1_scaled_d4",
            "xc_erfcx": "xc_erfcx",
            "xc_erfcx_d1": "xc_erfcx_d1", "xc_erfcx_d2": "xc_erfcx_d2",
            "xc_erfcx_d3": "xc_erfcx_d3", "xc_erfcx_d4": "xc_erfcx_d4",
            "xc_bessel_I0": "xc_bessel_I0", "xc_bessel_I1": "xc_bessel_I1"}


def emit_c(dag, leaf_names, outputs, ccode=None, prefix="t", graded=False):
    """Emit straight-line C for ``outputs`` (list of ``(lhs, node_id)``).

    The arithmetic DAG already performs CSE.  A node is normally materialised
    when it has multiple uses; additionally, sufficiently large single-use
    subexpressions are materialised to keep compiler-facing C expressions
    bounded.  Lowered Piecewise conditions contribute their arithmetic nodes
    to the same reachability and sharing analysis.

    When ``graded`` is true each output is a triple ``(lhs, node_id, order)``
    and the function returns a ``{order: c_text}`` dict instead of one string.
    Each materialised temporary is placed in the block of the MINIMUM derivative
    order among the outputs that transitively consume it -- so a per-order
    kernel that computes outputs up to order J needs exactly the temporaries in
    blocks <= J.  Blocks are emitted in ascending order with ascending node id
    within a block, which is topologically valid: every ancestor of a node that
    feeds an order-m output also feeds it, hence has min-order <= m.
    """
    ccode = ccode or sp.ccode
    # Normalise: outputs may carry a trailing per-output derivative order when
    # graded.  Downstream (lhs, nid) iterations use out_nodes; grading uses the
    # orders.
    out_nodes = [(t[0], t[1]) for t in outputs]
    out_orders = [(t[2] if len(t) > 2 else 0) for t in outputs]
    needed = set()
    stack = [nid for _, nid in out_nodes]
    while stack:
        i = stack.pop()
        if i in needed:
            continue
        needed.add(i)
        if dag.l[i] >= 0:
            stack.append(dag.l[i])
        if dag.r[i] >= 0:
            stack.append(dag.r[i])
        if dag.op[i] == "select":
            stack.extend(_condition_nodes(dag.k[i]))

    # Reference count over the needed sub-DAG (child edges + output uses).
    internal = lambda j: dag.op[j] not in ("const", "leaf")
    # Small integer/root powers expand to multiplication/sqrt/division, which
    # references the base more than once.  Count those extra uses so an inlined
    # base cannot accidentally be duplicated in emitted C.
    _POW_MUL = {sp.Integer(2): 2, sp.Integer(3): 3, sp.Integer(-2): 2}

    refcnt = {i: 0 for i in needed}
    for i in needed:
        children = [dag.l[i], dag.r[i]]
        if dag.op[i] == "select":
            children.extend(_condition_nodes(dag.k[i]))
        for child in children:
            if child >= 0 and child in needed and internal(child):
                refcnt[child] += 1
    for i in needed:
        if dag.op[i] == "powc" and dag.k[i] in _POW_MUL:
            base = dag.l[i]
            if base in refcnt and internal(base):
                refcnt[base] += _POW_MUL[dag.k[i]] - 1
    for _, nid in out_nodes:
        if nid in needed and internal(nid):
            refcnt[nid] += 1

    # Estimate the fully inlined C size in one topological pass.  Exact values
    # above the cap are not needed, so saturation keeps the pass linear.
    _MAX_INLINE_C_EXPR_CHARS = 8192
    _SIZE_CAP = _MAX_INLINE_C_EXPR_CHARS + 1

    def cap(n):
        return min(n, _SIZE_CAP)

    def condition_size(cond):
        if not isinstance(cond, tuple):
            return cap(len(ccode(cond)))
        tag = cond[0]
        if tag == "const":
            return 1
        if tag == "rel":
            return cap(inline_size[cond[2]] + len(cond[1]) +
                       inline_size[cond[3]] + 2)
        if tag in ("and", "or"):
            return cap(sum(condition_size(child) for child in cond[1]) +
                       4 * max(len(cond[1]) - 1, 0) + 2)
        if tag == "not":
            return cap(3 + condition_size(cond[1]))
        if tag == "raw":
            return cap(len(ccode(cond[1])))
        raise ValueError(f"unknown condition tag {tag}")

    inline_size = {}
    for i in range(dag.size()):
        if i not in needed:
            continue
        op = dag.op[i]
        if op == "const":
            inline_size[i] = cap(len(ccode(dag.k[i])) + 2)
        elif op == "leaf":
            inline_size[i] = cap(len(leaf_names[dag.k[i]]))
        elif op in ("add", "mul", "div"):
            inline_size[i] = cap(inline_size[dag.l[i]] + 3 +
                                 inline_size[dag.r[i]])
        elif op == "cmul":
            inline_size[i] = cap(len(ccode(dag.k[i])) + 7 +
                                 inline_size[dag.l[i]])
        elif op == "powc":
            p = dag.k[i]
            base = inline_size[dag.l[i]]
            if p == sp.Integer(-1):
                inline_size[i] = cap(6 + base)
            elif p == sp.Integer(2):
                inline_size[i] = cap(3 + 2 * base)
            elif p == sp.Integer(3):
                inline_size[i] = cap(6 + 3 * base)
            elif p == sp.Integer(-2):
                inline_size[i] = cap(10 + 2 * base)
            elif p in (sp.Rational(1, 2), sp.Rational(-1, 2)):
                inline_size[i] = cap(10 + base)
            else:
                inline_size[i] = cap(6 + base + len(ccode(p)))
        elif op in _C_UNARY:
            inline_size[i] = cap(len(_C_UNARY[op]) + 2 +
                                 inline_size[dag.l[i]])
        elif op == "atan2":
            inline_size[i] = cap(9 + inline_size[dag.l[i]] +
                                 inline_size[dag.r[i]])
        elif op == "sign":
            inline_size[i] = cap(16 + inline_size[dag.l[i]])
        elif op == "select":
            inline_size[i] = cap(condition_size(dag.k[i]) + 10 +
                                 inline_size[dag.l[i]] + inline_size[dag.r[i]])
        else:
            raise ValueError(f"emit: unknown op {op}")

    materialised = {
        i for i in needed
        if internal(i) and
        (refcnt[i] >= 2 or inline_size[i] > _MAX_INLINE_C_EXPR_CHARS)
    }

    def condition_ref(cond):
        if not isinstance(cond, tuple):
            return ccode(cond)
        tag = cond[0]
        if tag == "const":
            return "1" if cond[1] else "0"
        if tag == "rel":
            return f"{ref(cond[2])} {cond[1]} {ref(cond[3])}"
        if tag == "and":
            return "(" + " && ".join(condition_ref(child) for child in cond[1]) + ")"
        if tag == "or":
            return "(" + " || ".join(condition_ref(child) for child in cond[1]) + ")"
        if tag == "not":
            return f"!({condition_ref(cond[1])})"
        if tag == "raw":
            return ccode(cond[1])
        raise ValueError(f"unknown condition tag {tag}")

    def rhs_of(i):
        op = dag.op[i]
        if op == "add":
            return f"{ref(dag.l[i])} + {ref(dag.r[i])}"
        if op == "mul":
            return f"{ref(dag.l[i])} * {ref(dag.r[i])}"
        if op == "div":
            return f"{ref(dag.l[i])} / {ref(dag.r[i])}"
        if op == "cmul":
            return f"({ccode(dag.k[i])}) * {ref(dag.l[i])}"
        if op == "powc":
            p = dag.k[i]
            base = ref(dag.l[i])
            if p == sp.Integer(-1):
                return f"1.0 / {base}"
            if p == sp.Integer(2):
                return f"{base} * {base}"
            if p == sp.Integer(3):
                return f"{base} * {base} * {base}"
            if p == sp.Integer(-2):
                return f"1.0 / ({base} * {base})"
            if p == sp.Rational(1, 2):
                return f"sqrt({base})"
            if p == sp.Rational(-1, 2):
                return f"1.0 / sqrt({base})"
            return f"pow({base}, {ccode(p)})"
        if op in _C_UNARY:
            return f"{_C_UNARY[op]}({ref(dag.l[i])})"
        if op == "atan2":
            return f"atan2({ref(dag.l[i])}, {ref(dag.r[i])})"
        if op == "sign":
            return f"copysign(1.0, {ref(dag.l[i])})"
        if op == "select":
            return f"(({condition_ref(dag.k[i])}) ? {ref(dag.l[i])} : {ref(dag.r[i])})"
        raise ValueError(f"emit: unknown op {op}")

    def ref(i):
        op = dag.op[i]
        if op == "const":
            return f"({ccode(dag.k[i])})"
        if op == "leaf":
            return leaf_names[dag.k[i]]
        if i in materialised:
            return f"{prefix}{i}"
        return f"({rhs_of(i)})"

    if graded:
        # Min-consumer-order per needed node, by reverse DFS from each output.
        # Processing outputs by ascending order means a node, once assigned, is
        # never revisited with a lower order -- so each node is set once.
        maxK = max(out_orders) if out_orders else 0
        node_order = {}
        for (_, nid), order in sorted(zip(out_nodes, out_orders),
                                      key=lambda t: t[1]):
            stk = [nid]
            while stk:
                j = stk.pop()
                if j in node_order:      # already set to <= order (ascending)
                    continue
                node_order[j] = order
                if dag.l[j] >= 0:
                    stk.append(dag.l[j])
                if dag.r[j] >= 0:
                    stk.append(dag.r[j])
                if dag.op[j] == "select":
                    stk.extend(_condition_nodes(dag.k[j]))
        blocks = {K: [] for K in range(maxK + 1)}
        for i in range(dag.size()):
            if i in materialised:
                blocks[node_order.get(i, maxK)].append(
                    f"  const double {prefix}{i} = {rhs_of(i)};")
        for (lhs, nid), order in zip(out_nodes, out_orders):
            blocks[order].append(f"  {lhs} = {ref(nid)};")
        return {K: "\n".join(blocks[K]) for K in range(maxK + 1)}

    lines = []
    for i in range(dag.size()):
        if i in materialised:
            lines.append(f"  const double {prefix}{i} = {rhs_of(i)};")
    for lhs, nid in out_nodes:
        lines.append(f"  {lhs} = {ref(nid)};")
    return "\n".join(lines)


# ---------------------------------------------------------------------------
# Self-test: every rule against sp.diff, numerically at a random point.
# ---------------------------------------------------------------------------
def _selftest():
    import random
    random.seed(7)
    x, y, z, u, w = sp.symbols("x y z u w", positive=True)

    cases = [
        ("exp(x+y)", sp.exp(x + y), [x, y]),
        ("log(1+x+x*y+y**2)", sp.log(1 + x + x * y + y**2), [x, y]),
        ("(x*y+x**2)**(3/2)", (x * y + x**2) ** sp.Rational(3, 2), [x, y]),
        ("tanh(x*y+y)", sp.tanh(x * y + y), [x, y]),
        ("erf(x+y**2)", sp.erf(x + y**2), [x, y]),
        ("erfc(x*y)", sp.erfc(x * y), [x, y]),
        ("atan(x*y+x)", sp.atan(x * y + x), [x, y]),
        ("asinh(x*y+y**2)", sp.asinh(x * y + y**2), [x, y]),
        ("atanh(x*y/3)", sp.atanh(x * y / 3), [x, y]),
        ("sin(x*y+x)", sp.sin(x * y + x), [x, y]),
        ("cos(x**2+y)", sp.cos(x**2 + y), [x, y]),
        ("cosh(x*y)", sp.cosh(x * y), [x, y]),
        ("atan2(x+y,x*y+1)", sp.atan2(x + y, x * y + 1), [x, y]),
        ("expm1(-x*y)", sp.exp(-x * y) - 1, [x, y]),          # value via expm1 rule below
        ("log1p(x+y**2)", sp.log(1 + x + y**2), [x, y]),
        ("nested 4-var",
         sp.exp(-(x**2 + y**2 + z**2 + u**2) ** sp.Rational(3, 4))
         * sp.log(1 + x + y + z + u + x * y) * sp.tanh(z + u),
         [x, y, z, u]),
    ]
    # route the expm1/log1p test exprs through their stable rules explicitly
    expm1f = sp.Function("xc_expm1")
    log1pf = sp.Function("xc_log1p")
    extra = {expm1f: lambda d, e, s, idx, m, rec: jet_expm1(d, rec(e.args[0]), idx),
             log1pf: lambda d, e, s, idx, m, rec: jet_log1p(d, rec(e.args[0]), idx)}

    print(f"{'case':24} {'n':>2} {'idx':>4} {'nodes':>6}  maxrelerr")
    worst = 0.0
    for name, expr, vs in cases:
        order = 4
        d = DAG()
        idx = multi_indices(len(vs), order)
        # for the stable-form cases, swap in the xc_* function head
        texpr = expr
        if name.startswith("expm1"):
            texpr = expm1f(-vs[0] * vs[1])
        elif name.startswith("log1p"):
            texpr = log1pf(vs[0] + vs[1] ** 2)
        J = to_jet(d, texpr, vs, idx, {}, funcs=extra)
        env = {s: random.uniform(0.3, 0.8) for s in vs}
        val = d.evaluate(env)
        # reference derivatives from the plain expr (expm1/log1p == their plain forms)
        cache = {(0,) * len(vs): expr}

        def deriv(a):
            if a in cache:
                return cache[a]
            i = _first_nonzero(a)
            pa = list(a)
            pa[i] -= 1
            e = sp.diff(deriv(tuple(pa)), vs[i])
            cache[a] = e
            return e

        err = 0.0
        for a in idx:
            ref = float(deriv(a).evalf(subs=env))
            got = float(prod(factorial(k) for k in a)) * val[J.get(a)]
            err = max(err, abs(got - ref) / (abs(ref) + 1e-10))
        worst = max(worst, err)
        print(f"{name:24} {len(vs):>2} {len(idx):>4} {d.size():>6}  {err:.2e}")
    print(f"\nworst relative error: {worst:.2e}  "
          f"{'PASS' if worst < 1e-9 else 'FAIL'}")
    return worst < 1e-9


def _emit_test():
    """Emit C for a real-shaped expression, compile it, and check the compiled
    partials against sp.diff."""
    import ctypes
    import os
    import random
    import subprocess
    import tempfile
    random.seed(11)
    x, y, z, u = sp.symbols("x y z u", positive=True)
    syms = [x, y, z, u]
    expr = (sp.exp(-(x**2 + y**2 + z**2 + u**2) ** sp.Rational(3, 4))
            * sp.log(1 + x + y + z + u + x * y) * sp.tanh(z + u))
    order = 2
    d, J, idx = derivatives(expr, syms, order)
    outputs = [(f"out[{k}]", d.cmul(prod(factorial(t) for t in a), J.get(a)))
               for k, a in enumerate(idx)]
    leaf_names = {s: f"v[{i}]" for i, s in enumerate(syms)}
    body = emit_c(d, leaf_names, outputs)
    src = ("#include <math.h>\n"
           "void fn(const double* v, double* out) {\n" + body + "\n}\n")
    env = {s: random.uniform(0.3, 0.8) for s in syms}
    with tempfile.TemporaryDirectory() as td:
        cpath, sopath = os.path.join(td, "a.c"), os.path.join(td, "a.so")
        with open(cpath, "w") as fh:
            fh.write(src)
        subprocess.run(["gcc", "-shared", "-fPIC", "-O2", "-o", sopath, cpath,
                        "-lm"], check=True)
        lib = ctypes.CDLL(sopath)
        lib.fn.argtypes = [ctypes.POINTER(ctypes.c_double),
                           ctypes.POINTER(ctypes.c_double)]
        vin = (ctypes.c_double * len(syms))(*[env[s] for s in syms])
        out = (ctypes.c_double * len(idx))()
        lib.fn(vin, out)
    cache = {(0,) * len(syms): expr}

    def deriv(a):
        if a in cache:
            return cache[a]
        i = _first_nonzero(a)
        pa = list(a)
        pa[i] -= 1
        e = sp.diff(deriv(tuple(pa)), syms[i])
        cache[a] = e
        return e

    err = max(abs(out[k] - float(deriv(a).evalf(subs=env)))
              / (abs(float(deriv(a).evalf(subs=env))) + 1e-10)
              for k, a in enumerate(idx))
    print(f"emit+compile: {len(idx)} partials, C vs sp.diff maxrelerr={err:.2e}  "
          f"{'PASS' if err < 1e-9 else 'FAIL'}")
    return err < 1e-9


def _selftest_special():
    """Finite-difference check of the special-function jets whose value ops are
    not plain SymPy heads (so the sp.diff oracle of _selftest cannot reach
    them): the implicit inverses (br89_x, mbrxc_x, LambertW, xc_E1_scaled,
    xc_erfcx), my_dilog, sech, acsch, Abs, BesselI. Each jet is built on a
    smooth argument, evaluated through the DAG, and compared against central
    finite differences of the function's numeric value. Order-3 central
    differences are ~1e-3-limited, so that is the pass bar."""
    import math
    import mpmath
    x, y = sp.symbols("x y")

    def li2(q):
        s, t, k = 0.0, q, 1
        while k < 400:
            s += t / (k * k); t *= q; k += 1
            if abs(t) < 1e-18:
                break
        return s

    def e1s(q):                                # e^q E_1(q), q > 0
        if q < 1:
            s, t, k = 0.0, 1.0, 1
            while k < 60:
                t *= -q / k; s += t / k; k += 1
            return math.exp(q) * (-0.5772156649015329 - math.log(q) - s)
        cf = 0.0
        for k in range(40, 0, -1):
            cf = k / (1 + k / (q + cf))
        return 1.0 / (q + cf)

    Q = 0.6 + 0.4 * x + 0.3 * y + 0.1 * x * y          # smooth, O(1), > 0
    Qs = -0.2 - 0.1 * x - 0.15 * y - 0.05 * x * y      # in (-1, 1) for Li_2
    F = sp.Function
    cases = [
        ("sech", sp.sech(Q), lambda q: 1 / math.cosh(q), Q),
        ("acsch", sp.acsch(Q), lambda q: math.asinh(1 / q), Q),
        ("Abs", sp.Abs(Q), abs, Q),
        ("LambertW", sp.LambertW(Q), lambda q: float(mpmath.lambertw(q)), Q),
        ("my_dilog", F("my_dilog")(Qs), li2, Qs),
        ("xc_E1_scaled", F("xc_E1_scaled")(Q), e1s, Q),
        ("xc_erfcx", F("xc_erfcx")(Q), lambda q: math.exp(q * q) * math.erfc(q), Q),
        ("br89_x", F("br89_x")(Q), lambda q: DAG._br_root_float(q, "br89_x"), Q),
        ("mbrxc_x", F("mbrxc_x")(Q), lambda q: DAG._br_root_float(q, "mbrxc_x"), Q),
        ("BesselI0", F("BesselI")(0, Q), lambda q: float(mpmath.besseli(0, q)), Q),
    ]
    x0, y0, h = 0.7, 0.6, 1e-3
    print(f"{'special jet':16} worst jet-vs-FD")
    worst_all = 0.0
    for label, jexpr, ref, qexpr in cases:
        d, J, idx = derivatives(jexpr, [x, y], 3)
        val = d.evaluate({x: x0, y: y0})
        qf = sp.lambdify((x, y), qexpr, "math")

        def f(a, b, _r=ref, _q=qf):
            return _r(_q(a, b))

        def fd(ax, ay):
            def dx(g):
                return lambda a, b: (g(a + h, b) - g(a - h, b)) / (2 * h)

            def dy(g):
                return lambda a, b: (g(a, b + h) - g(a, b - h)) / (2 * h)
            g = f
            for _ in range(ax):
                g = dx(g)
            for _ in range(ay):
                g = dy(g)
            return g(x0, y0)
        worst = 0.0
        for a in idx:
            if sum(a) == 0:
                continue
            dv = factorial(a[0]) * factorial(a[1]) * val[J.get(a)]
            r = fd(a[0], a[1])
            # A near-linear function (Abs(Q)=Q here) has ~0 high-order
            # derivatives, so the central-difference noise (~1e-6) divided by a
            # ~0 true value would dwarf the real error -- skip those.
            if abs(dv) < 1e-5 and abs(r) < 1e-3:
                continue
            worst = max(worst, abs(dv - r) / max(abs(r), 1e-6))
        worst_all = max(worst_all, worst)
        print(f"  {label:14} {worst:.1e}")
    ok = worst_all < 5e-3
    print(f"special jets (FD-limited ~1e-3): worst={worst_all:.1e}  "
          f"{'PASS' if ok else 'FAIL'}")
    return ok


if __name__ == "__main__":
    import sys
    ok = _selftest()
    print()
    ok = _selftest_special() and ok
    print()
    ok = _emit_test() and ok
    sys.exit(0 if ok else 1)
