"""
SymPy-based code generator for libxc functionals (prototype).

Mirrors the pieces of scripts/maple2c.py that we need for an LDA prototype:

* `my_piecewise3` - kept symbolic; its derivative rule matches Maple's
  (`diff/my_piecewise3`): the condition is treated as a frozen branch
  selector, only the two branches are differentiated.
* `opz_pow_n(z, n)` - expanded inline into `my_piecewise3` exactly as Maple's
  util.mpl does, so the generated C uses the same zeta_threshold guard.
* `LibxcCPrinter` - a sympy C99 printer extended to emit `POW_1_3(x)` for
  cube roots, `M_CBRT3 / M_CBRTPI` for the symbolic 3^(1/3) and pi^(1/3)
  constants, `my_piecewise3(...)` for the Function, and to map the placeholder
  symbols (`rho0`, `params_alpha`, ...) to libxc's C names.
* `cse_emit` - driver that runs sympy.cse with t1,t2,... labels and prints
  declarations + assignments in the same shape as the maple2c output.
"""

from __future__ import annotations

import re
from itertools import product

import math

import sympy as sp
from sympy.printing.c import C99CodePrinter


# ---------------------------------------------------------------------------
# Symbolic helpers matching maple/util.mpl
# ---------------------------------------------------------------------------

class my_piecewise3(sp.Function):
    """Three-arg piecewise: my_piecewise3(cond, then_val, else_val).

    Mirrors Maple's `my_piecewise3` and its `diff/my_piecewise3` rule:
    the condition is a frozen branch selector and is *not* differentiated;
    derivatives apply termwise to the two branches.
    """

    nargs = 3

    @classmethod
    def eval(cls, c, t, e):
        # A condition that has collapsed to a constant selects one branch
        # outright. Folding it keeps the result an ordinary (real)
        # expression instead of an opaque Function that SymPy refuses to
        # compare ("Invalid comparison of non-real ...").
        if c is sp.true:
            return t
        if c is sp.false:
            return e
        if t == e:
            # Both branches identical: the condition is irrelevant. Also lets a
            # screened term whose value branch was zeroed (then == else == 0,
            # e.g. an exchange wrapper turned off for the split) fold to 0.
            return t

    def _eval_is_real(self):
        # Both branches are real-valued physical quantities, so the
        # selector is real too. Declaring it lets SymPy compare
        # expressions that contain a my_piecewise3.
        return True

    def _eval_derivative(self, s):
        c, t, e = self.args
        return my_piecewise3(c, sp.diff(t, s), sp.diff(e, s))


class my_piecewise5(sp.Function):
    """Five-arg piecewise: my_piecewise5(c1, t1, c2, t2, e).

    Returns t1 if c1, else t2 if c2, else e. Conditions are frozen.
    """

    nargs = 5

    @classmethod
    def eval(cls, c1, t1, c2, t2, e):
        # Fold a constant first condition (see my_piecewise3.eval).
        if c1 is sp.true:
            return t1
        if c1 is sp.false:
            return my_piecewise3(c2, t2, e)

    def _eval_is_real(self):
        return True

    def _eval_derivative(self, s):
        c1, t1, c2, t2, e = self.args
        return my_piecewise5(
            c1, sp.diff(t1, s), c2, sp.diff(t2, s), sp.diff(e, s)
        )


# Placeholder symbols for libxc runtime quantities. The C printer rewrites
# these to the actual member access expressions.
dens_threshold = sp.Symbol("dens_threshold", positive=True)
zeta_threshold = sp.Symbol("zeta_threshold", positive=True)
cam_omega = sp.Symbol("cam_omega", positive=True)
cam_alpha = sp.Symbol("cam_alpha", real=True)
cam_beta = sp.Symbol("cam_beta", real=True)
params_alpha = sp.Symbol("params_alpha", positive=True)

def _is_small_threshold(s):
    """A positive parameter named like a screening threshold -- a cutoff known
    to lie in (0, 1) (zeta_threshold, dens_threshold, p_a_*_threshold, ...).
    A condition over only such symbols folds to a constant when smallness alone
    decides it -- e.g. at z=0 the clamp 1 <= zeta_threshold is always false,
    pruning dead spin-polarization branches."""
    return (getattr(s, "is_Symbol", False) and bool(s.is_positive)
            and "threshold" in getattr(s, "name", ""))


# ---------------------------------------------------------------------------
# C printing
# ---------------------------------------------------------------------------

# Largest |n| for which x**n is emitted as nested squaring rather than a
# pow() call. pow() never wins on speed -- even a 23-multiply flat chain
# beats it 4x -- so this only bounds how much text a single power may
# expand to. The generated tree currently reaches |n| = 57.
_MAX_INT_POW = 64

# At or below this a flat product is emitted inline, matching what the
# generator produced before; above it xc_powi() keeps the source compact.
_FLAT_POW = 4


class LibxcCPrinter(C99CodePrinter):
    """C99 printer that emits libxc's macros and member-access conventions."""

    # Map symbol name -> C expression text. Extra maps can be supplied
    # via the `extra_symbol_map` constructor kwarg.
    BASE_SYMBOL_MAP = {
        "params_alpha": "params->alpha",
        "dens_threshold": "p->dens_threshold",
        "zeta_threshold": "p->zeta_threshold",
        "cam_omega": "p->cam_omega",
        "cam_alpha": "p->cam_alpha",
        "cam_beta": "p->cam_beta",
        "rho0": "rho[0]",
        "rho1": "rho[1]",
        "sigma0": "sigma[0]",
        "sigma1": "sigma[1]",
        "sigma2": "sigma[2]",
        "M_CBRT3": "M_CBRT3",
        "M_CBRTPI": "M_CBRTPI",
        "M_CBRT2": "M_CBRT2",
        "M_CBRT6": "M_CBRT6",
    }

    def __init__(self, settings=None, extra_symbol_map=None):
        super().__init__(settings)
        self.symbol_map = dict(self.BASE_SYMBOL_MAP)
        if extra_symbol_map:
            self.symbol_map.update(extra_symbol_map)

    def _print_Symbol(self, expr):
        return self.symbol_map.get(expr.name, expr.name)

    @staticmethod
    def _is_enclosed(s):
        """True if s is wrapped in one balanced outer paren pair, i.e. the '('
        at position 0 matches the ')' at the end. A bare `s.startswith("(")` is
        NOT enough: `(1/2)*x + 1/2` starts with '(' (its first factor) yet is an
        unenclosed Add, so multiplying it by a POW_1_3 chain without wrapping
        binds only the trailing term -- the SCAN alpha-indicator bug."""
        if not (s.startswith("(") and s.endswith(")")):
            return False
        depth = 0
        for i, c in enumerate(s):
            if c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
                if depth == 0:
                    return i == len(s) - 1
        return False

    @staticmethod
    def _is_atomic_call(s):
        """True if s is exactly one function call NAME(...) whose opening
        paren closes at the very end, so it binds tighter than any operator
        and needs no wrapping. A PREFIX test is not enough: "POW_1_3(x) + y"
        and "M_CBRT2 * x + y" start like atoms but are unenclosed sums --
        squaring one of those without parens emits mathematically wrong C."""
        m = re.match(r"[A-Za-z_][A-Za-z0-9_]*\(", s)
        if not m or not s.endswith(")"):
            return False
        depth = 0
        for i in range(m.end() - 1, len(s)):
            if s[i] == "(":
                depth += 1
            elif s[i] == ")":
                depth -= 1
                if depth == 0:
                    return i == len(s) - 1
        return False

    @staticmethod
    def _powi(inner, n):
        """C text for x**n with n a positive integer.

        Up to 4 a flat product is what the generator has always emitted, so
        keep it -- switching would rewrite every small power in the tree for
        no gain, and the two measure the same at these sizes. Above that call
        util.h's xc_powi, which keeps the source compact (`xc_powi(rs, 21)`
        rather than a 21-term product) and which both gcc and clang unroll to
        the minimal multiplication chain for a constant exponent."""
        if n <= 0:
            return "0.1e1"
        if n == 1:
            return inner
        if n <= _FLAT_POW:
            return "(" + " * ".join([inner] * n) + ")"
        return f"xc_powi({inner}, {n})"

    def _pow_base(self, base):
        """Printed base, parenthesized unless it is already atomic.

        A bare array access (rho[0], sigma[2], ...) is atomic, but a compound
        expression that merely starts with one -- "rho[0] + rho[1]", which
        arises when the inputs are inlined rather than read into locals -- is
        not, and must be wrapped."""
        inner = self._print(base)
        atomic_access = (inner.endswith("]") and inner.count("[") == 1
                         and " " not in inner
                         and inner.split("[", 1)[0] in
                         ("rho", "sigma", "lapl", "tau"))
        if (inner.isidentifier() or self._is_enclosed(inner)
                or self._is_atomic_call(inner) or atomic_access):
            return inner
        return f"({inner})"

    def _print_Pow(self, expr):
        base, exp = expr.base, expr.exp
        # Recognize special bases
        if base == sp.Integer(3) and exp == sp.Rational(1, 3):
            return "M_CBRT3"
        if base == sp.pi and exp == sp.Rational(1, 3):
            return "M_CBRTPI"
        if base == sp.Integer(2) and exp == sp.Rational(1, 3):
            return "M_CBRT2"
        # Common n/3 powers of pi -> M_CBRTPI chains (avoid POW_1_3(M_PI))
        if base == sp.pi and exp.is_Rational and exp.q == 3:
            p = int(exp.p)
            whole, rem = divmod(abs(p), 3)
            parts = ["M_PI"] * whole + ["M_CBRTPI"] * rem
            body = " * ".join(parts) if parts else "0.1e1"
            if p < 0:
                return f"(0.1e1 / ({body}))"
            return f"({body})" if len(parts) > 1 else parts[0]
        # Rational powers -> one xc_powr() call. util.h decides how to
        # evaluate it: one root applied once, at most one division, and the
        # right thing when cbrt() is unavailable. Emitting the decomposition
        # inline instead spread a single power over an expression like
        # (POW_1_3(na) / (na * na * na * na)) and duplicated the choice of
        # form at every call site.
        if exp.is_Rational and exp.q in (2, 3, 4, 6) \
                and abs(int(exp.p)) <= exp.q * _MAX_INT_POW:
            return f"xc_powr({self._print(base)}, {int(exp.p)}, {int(exp.q)})"
        # Integer powers -> multiplication. GCC will not do this for us: at
        # -O3 it expands only pow(x, 2.0); everything else survives as a
        # library call unless -ffast-math is on, which this library cannot use.
        if exp.is_Integer and 0 < int(exp) <= _MAX_INT_POW:
            return self._powi(self._pow_base(base), int(exp))
        if exp.is_Integer and -_MAX_INT_POW <= int(exp) < 0:
            n = -int(exp)
            if n <= _FLAT_POW:
                return "(0.1e1 / " + self._powi(self._pow_base(base), n) + ")"
            return f"xc_powi({self._pow_base(base)}, {int(exp)})"
        return super()._print_Pow(expr)

    def _print_Function(self, expr):
        if expr.func.__name__ == "my_piecewise3":
            c, t, e = expr.args
            return (
                f"my_piecewise3({self._print(c)}, "
                f"{self._print(t)}, {self._print(e)})"
            )
        if expr.func.__name__ == "my_piecewise5":
            c1, t1, c2, t2, e = expr.args
            return (
                f"my_piecewise5({self._print(c1)}, {self._print(t1)}, "
                f"{self._print(c2)}, {self._print(t2)}, {self._print(e)})"
            )
        return super()._print_Function(expr)

    # Maple-style numeric literal: 0.3e1 not 3.0
    def _print_Float(self, expr):
        s = super()._print_Float(expr)
        return s

    def _print_Integer(self, expr):
        # Print integer constants using Maple's 0.<digits>e<exp> form so the
        # output stays close to the reference. Only used inside expressions.
        n = int(expr)
        if n == 0:
            return "0"
        if n == 1:
            return "0.1e1"
        if n == -1:
            return "-0.1e1"
        sign = "-" if n < 0 else ""
        m = abs(n)
        exp = len(str(m))
        return f"{sign}0.{m}e{exp}"

    def _print_Rational(self, expr):
        # a/b -> 0.a e<...> / 0.b e<...>
        return f"{self._print(sp.Integer(expr.p))} / {self._print(sp.Integer(expr.q))}"

    def _print_Le(self, expr):
        return f"{self._print(expr.lhs)} <= {self._print(expr.rhs)}"

    def _print_BooleanTrue(self, expr):
        return "1"

    def _print_BooleanFalse(self, expr):
        return "0"


# ---------------------------------------------------------------------------
# CSE driver
# ---------------------------------------------------------------------------

def _simplify_cond(c, cmemo=None):
    """Canonicalize a Le/Lt/Ge/Gt as cancel(lhs - rhs) <relop> 0, and fold it to
    a constant when it involves only bounded threshold params (each known to lie
    in (0,1)) and no physical variable -- e.g. at z=0 the full-polarization clamp
    1 <= zeta_threshold is always false.  This prunes the dead spin-polarization
    branches in the spin-restricted (z=0) path; my_piecewise3.eval then drops the
    selected-away branch.

    Memoized by condition (cmemo): kernel-inlined kernels reuse the same screen
    condition at many DISTINCT piecewise nodes, and the cancel/together
    canonicalization here is the dominant codegen cost on TPSS-class functionals
    (it dropped mgga_c_tpss order-1 from >280s to ~the no-cancel floor)."""
    if cmemo is not None:
        hit = cmemo.get(c)
        if hit is not None:
            return hit
        out = _simplify_cond_impl(c)
        cmemo[c] = out
        return out
    return _simplify_cond_impl(c)


def _simplify_cond_impl(c):
    if c.func not in (sp.Le, sp.Lt, sp.Ge, sp.Gt):
        return c
    diff = sp.cancel(sp.together(c.lhs - c.rhs))
    cond = c.func(diff, sp.S.Zero)
    syms = cond.free_symbols
    if syms and all(_is_small_threshold(s) for s in syms):
        # Only bounded thresholds remain. Probe two well-separated small values
        # per threshold; fold only if every combination agrees on one truth
        # value, so smallness (not the exact value) is what decides.
        order = list(syms)
        results = {cond.subs(dict(zip(order, vals)))
                   for vals in product((sp.Rational(1, 10**6),
                                        sp.Rational(1, 10**12)),
                                       repeat=len(order))}
        if results == {sp.true}:
            return sp.true
        if results == {sp.false}:
            return sp.false
    return cond


def simplify_conditions(expr):
    """Walk expr; canonicalize each my_piecewise3/5 condition so coordinate
    cancellations (e.g. (1 - (rho_a-rho_b)/(rho_a+rho_b)) -> 2*rho_b/(rho_a+rho_b))
    collapse to a floating-point-safe screening expression.

    Memoized over the expression DAG: kernel-inlined expressions share the same
    subtrees at many points, and an un-memoized tree walk revisits each shared
    subtree once per reference (exponential on heavily-shared TPSS-class kernels).
    The memo makes it linear in the number of distinct subexpressions; rebuilding
    is skipped where no child changed, so unchanged branches stay identical."""
    return _simplify_conditions(expr, {}, {})


def _simplify_conditions(expr, memo, cmemo):
    if not isinstance(expr, sp.Basic):
        return expr
    cached = memo.get(expr)
    if cached is not None:
        return cached
    if expr.func is my_piecewise3:
        c, t, e = expr.args
        out = my_piecewise3(_simplify_cond(c, cmemo),
                            _simplify_conditions(t, memo, cmemo),
                            _simplify_conditions(e, memo, cmemo))
    elif expr.func is my_piecewise5:
        c1, t1, c2, t2, e = expr.args
        out = my_piecewise5(
            _simplify_cond(c1, cmemo), _simplify_conditions(t1, memo, cmemo),
            _simplify_cond(c2, cmemo), _simplify_conditions(t2, memo, cmemo),
            _simplify_conditions(e, memo, cmemo))
    elif expr.args:
        new_args = [_simplify_conditions(a, memo, cmemo) for a in expr.args]
        out = (expr if all(n is o for n, o in zip(new_args, expr.args))
               else expr.func(*new_args))
    else:
        out = expr
    memo[expr] = out
    return out


