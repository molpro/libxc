"""
Bridge between the existing functional definitions and the AD engine.

Loads a python/<family>/<name>.py math module, resolves its @helpers, assembles
f in libxc's input variables exactly as the legacy emitter does, inlines the
helper sym-functions to a pure SymPy expression, and runs ad_engine on it.

This is the development-time correctness harness (validate() checks the AD
partials against sp.diff). The production gate -- comparing the engine's emitted
C against the current generated C -- and the LDA/GGA/MGGA variable assembly will
be shared with libxc_codegen's _emit_* when the engine is wired into compile.py;
for now the assembly is mirrored here for the families already supported.
"""
import importlib.util
import os
import re
import sys

import sympy as sp

_HERE = os.path.dirname(os.path.abspath(__file__))
_REPO = os.path.abspath(os.path.join(_HERE, "..", ".."))
_PY = os.path.join(_REPO, "python")
for _p in [_PY, os.path.join(_REPO, "scripts"), _HERE] + \
        [os.path.join(_PY, d) for d in os.listdir(_PY)
         if os.path.isdir(os.path.join(_PY, d))]:
    if _p not in sys.path:
        sys.path.insert(0, _p)

import libxc_codegen as L          # noqa: E402
import ad_engine as AE             # noqa: E402


def _apply_replace(mod, text):
    """Apply the module's REPLACE regex post-process rules to the emitted C,
    mirroring libxc_codegen (the legacy emitter). These rename special-function
    heads that survive into frozen my_piecewise3 conditions -- e.g. mbrxc_x( ->
    xc_mgga_x_mbrxc_get_x( -- which _C_UNARY maps for DAG nodes but not for the
    SymPy-ccode'd condition text."""
    for pattern, replacement in getattr(mod, "REPLACE", []):
        text = re.sub(pattern, replacement, text)
    return text


def _load(name):
    for fam in os.listdir(_PY):
        path = os.path.join(_PY, fam, f"{name}.py")
        if os.path.isfile(path):
            spec = importlib.util.spec_from_file_location(name, path)
            mod = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(mod)
            return mod, fam
    # Variant with no own math module (e.g. mgga_x_bj06, registered in
    # mgga_x_tb09.c and reusing tb09's kernel): resolve its base math module
    # and family from the defining src file's maple2c include.
    import eval_reference as ER
    _, _, fam_dir, math_name = ER._resolve_source(name)
    if fam_dir and math_name != name:
        path = os.path.join(_PY, fam_dir, f"{math_name}.py")
        if os.path.isfile(path):
            spec = importlib.util.spec_from_file_location(math_name, path)
            mod = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(mod)
            return mod, fam_dir
    raise FileNotFoundError(name)


def _resolve(mod, order):
    L._MODULE_HAS_EXCHANGE = False
    L._GEN_MAX_ORDER = order
    for obj in list(vars(mod).values()):
        if getattr(obj, "_is_helper_proxy", False):
            obj._resolve()


def _inline(expr):
    """Replace every @helper sym-function by its (recursively inlined) body."""
    funcs = [a for a in expr.atoms(sp.Function) if hasattr(type(a), "helper")]
    if not funcs:
        return expr
    reps = {}
    for fa in funcs:
        h = type(fa).helper
        mi = type(fa).multiindex
        body = h._derivs[mi] if mi in h._derivs else h.expr
        reps[fa] = _inline(body.xreplace(dict(zip(h.args, fa.args))))
    return expr.xreplace(reps)


def _fold_const_piecewise(expr):
    """Collapse my_piecewise3/5 whose branch conditions are decided solely by the
    thresholds. zeta_threshold and dens_threshold are always in (0, 1), so a
    condition like `1 <= zeta_threshold` is constant-False and the piecewise is
    just its else branch -- but the generator carries the thresholds as opaque
    symbols, so without this the whole (e.g. unpol z=0) `opz_pow_n(z_thr(0))`
    tree is emitted as an inlined symbolic 'constant' and duplicated at every
    use. We decide a condition only when (a) it depends on no non-threshold
    variable and (b) it agrees at both ends of (0, 1) -- sound for the
    monotone-in-threshold relationals these screens use -- so density/zeta
    screens that genuinely depend on rho stay intact. Bottom-up so nested
    clamps (z_thr inside opz_pow_n) fold before their parent's condition."""
    thr = [s for s in expr.free_symbols if "threshold" in getattr(s, "name", "")]
    if not thr:
        return expr
    lo = {s: sp.Float("1e-300") for s in thr}
    hi = {s: sp.Float(1) - sp.Float("1e-12") for s in thr}
    mp = {}
    for f in expr.atoms(sp.Function):
        n = type(f).__name__
        if n in ("my_piecewise3", "my_piecewise5"):
            mp[n] = type(f)

    def decide(cond):
        if not hasattr(cond, "free_symbols"):
            return None
        if any("threshold" not in getattr(s, "name", "") for s in cond.free_symbols):
            return None
        a, b = cond.subs(lo), cond.subs(hi)
        if a == sp.true and b == sp.true:
            return True
        if a == sp.false and b == sp.false:
            return False
        return None

    def rec(e):
        if not e.args:
            return e
        e = e.func(*[rec(a) for a in e.args])
        if e.func is mp.get("my_piecewise3"):
            cond, t, f = e.args
            d = decide(cond)
            return t if d is True else f if d is False else e
        if e.func is mp.get("my_piecewise5"):
            c1, x1, c2, x2, x3 = e.args
            d1 = decide(c1)
            if d1 is True:
                return x1
            if d1 is False:
                d2 = decide(c2)
                if d2 is True:
                    return x2
                if d2 is False:
                    return x3
        return e

    return rec(expr)


def _assemble(mod, fam):
    """Return (f_expr, libxc_variable_symbols), spin-polarised."""
    eg = sp.Rational(4, 3)
    na, nb = sp.symbols("na nb", positive=True)
    nt = na + nb
    rs = L.RS_FACTOR / nt ** sp.Rational(1, 3)
    z = (na - nb) / nt
    if fam == "lda_exc":
        return mod.f(rs, z), [na, nb]
    if fam == "gga_exc":
        gaa, gbb = sp.symbols("gaa gbb", positive=True)
        gab = sp.Symbol("gab")
        st = gaa + 2 * gab + gbb
        f = mod.f(rs, z, sp.sqrt(st) / nt ** eg,
                  sp.sqrt(gaa) / na ** eg, sp.sqrt(gbb) / nb ** eg)
        return f, [na, nb, gaa, gab, gbb]
    if fam == "mgga_exc":
        ek = sp.Rational(5, 3)
        gaa, gbb = sp.symbols("gaa gbb", positive=True)
        gab = sp.Symbol("gab")
        la, lb = sp.symbols("la lb")
        ta, tb = sp.symbols("ta tb", positive=True)
        st = gaa + 2 * gab + gbb
        f = mod.f(rs, z, sp.sqrt(st) / nt ** eg,
                  sp.sqrt(gaa) / na ** eg, sp.sqrt(gbb) / nb ** eg,
                  la / na ** ek, lb / nb ** ek, ta / na ** ek, tb / nb ** ek)
        return f, [na, nb, gaa, gab, gbb, la, lb, ta, tb]
    raise NotImplementedError(f"family {fam} not yet bridged")


# xc_* heads map to the FP-stable jet rules; my_piecewise3 to the select rule.
def _funcs_for(expr):
    heads = {type(a).__name__: type(a) for a in expr.atoms(sp.Function)}
    funcs = {}
    if "my_piecewise3" in heads:
        funcs[heads["my_piecewise3"]] = (
            lambda d, e, s, idx, m, rec:
            AE.jet_piecewise3(
                d, AE.lower_condition(d, e.args[0], s, funcs),
                rec(e.args[1]), rec(e.args[2]), idx))
    if "my_piecewise5" in heads:
        # t1 if c1 else (t2 if c2 else e) -- nested selects.
        funcs[heads["my_piecewise5"]] = (
            lambda d, e, s, idx, m, rec:
            AE.jet_piecewise3(
                d, AE.lower_condition(d, e.args[0], s, funcs), rec(e.args[1]),
                AE.jet_piecewise3(
                    d, AE.lower_condition(d, e.args[2], s, funcs),
                    rec(e.args[3]), rec(e.args[4]), idx),
                idx))
    for nm, rule in (("xc_expm1", AE.jet_expm1), ("xc_log1p", AE.jet_log1p),
                     ("xc_asinh", AE.jet_asinh), ("xc_atanh", AE.jet_atanh),
                     ("xc_x_minus_log1p", AE.jet_x_minus_log1p)):
        if nm in heads:
            funcs[heads[nm]] = (lambda d, e, s, idx, m, rec, _r=rule:
                                _r(d, rec(e.args[0]), idx))
    return funcs, heads


def build(name, order):
    """Lower a functional to (dag, jet, idx, vars, expr). The partial for
    multi-index alpha is alpha! * dag.evaluate(...)[jet.get(alpha)]."""
    mod, fam = _load(name)
    _apply_dimension(mod)
    _resolve(mod, order)
    f, vs = _assemble(mod, fam)
    fx = _fold_const_piecewise(_inline(f))
    funcs, _ = _funcs_for(fx)
    idx = AE.multi_indices(len(vs), order)
    d = AE.DAG()
    J = AE.to_jet(d, fx, vs, idx, {}, funcs=funcs)
    return d, J, idx, vs, fx


def validate(name, order, point=None, params=None):
    """Check the AD partials against sp.diff at a numeric point. Returns the
    max relative error. (The sp.diff oracle is slow -- that is the blowup the
    engine avoids -- so prefer low order for routine checks.)"""
    import time
    from math import factorial, prod
    d, J, idx, vs, fx = build(name, order)

    # AD == sp.diff for any consistent parameter values; map the few that have a
    # natural range and give every other parameter a deterministic small value.
    import random
    pvals = {"params_a_alpha": 1.8, "params_a_omega": 4.5,
             "params_a_beta": 0.06672455, "params_a_gamma": 0.031091,
             "zeta_threshold": 1e-12, "dens_threshold": 1e-12, **(params or {})}
    param_env = {}
    for s in fx.free_symbols:
        if s in vs:
            continue
        if str(s) in pvals:
            param_env[s] = pvals[str(s)]
        else:
            param_env[s] = random.Random(str(s)).uniform(0.2, 0.9)
    if point is None:
        defaults = {"na": 0.7, "nb": 0.4, "gaa": 0.3, "gbb": 0.2, "gab": 0.1,
                    "la": 0.05, "lb": 0.03, "ta": 0.9, "tb": 0.6}
        point = {s: defaults.get(str(s), 0.5) for s in vs}
    full = {**point, **param_env}

    t0 = time.perf_counter()
    val = d.evaluate(point, param_env)
    ad_ms = (time.perf_counter() - t0) * 1e3

    heads = {type(a).__name__: type(a) for a in fx.atoms(sp.Function)}
    ox = fx
    if "xc_expm1" in heads:
        ox = ox.replace(heads["xc_expm1"], lambda a: sp.exp(a) - 1)
    if "xc_log1p" in heads:
        ox = ox.replace(heads["xc_log1p"], lambda a: sp.log(1 + a))
    cache = {(0,) * len(vs): ox}

    def deriv(a):
        if a in cache:
            return cache[a]
        i = next(k for k, v in enumerate(a) if v)
        pa = list(a)
        pa[i] -= 1
        e = sp.diff(deriv(tuple(pa)), vs[i])
        cache[a] = e
        return e

    err = 0.0
    for a in idx:
        ref = float(deriv(a).subs(full))
        got = float(prod(factorial(k) for k in a)) * val[J.get(a)]
        err = max(err, abs(got - ref) / (abs(ref) + 1e-12))
    print(f"{name} order {order}: {len(idx)} partials  nodes={d.size()}  "
          f"AD={ad_ms:.1f}ms  maxrelerr={err:.2e}  "
          f"{'PASS' if err < 1e-9 else 'FAIL'}")
    return err


from itertools import combinations_with_replacement as _cwr

_LDA_FIELD = {0: "zk", 1: "vrho", 2: "v2rho2", 3: "v3rho3", 4: "v4rho4"}
_ORD = ["exc", "vxc", "fxc", "kxc", "lxc"]
# Per-order compile guard, used by the order-graded kernel-tail emitters below
# to wrap each (order, spin) self-#include in `#if XC_MAXORDER >= <order>`.

def _emit_kernel_tail_graded(d, named, leaf_names, pr, pstruct, max_order):
    """Order-graded kernel-tail emitter.

    `named` is the FULL output list for orders 0..max_order (one entry per
    (value, node, field, comp, order)). Returns (preamble, body) where body is
    one graded function body: the order-0 temporaries and writes are always
    present; each higher order K's temporaries and writes are wrapped in
    `#if _KMAX >= K`. Compiling the body with _KMAX=J thus yields exactly the
    order-J kernel (all outputs up to order J), so one body serves every order.
    """
    named = [t for t in named if t[1] != d.ZERO]
    blocks = AE.emit_c(
        d, leaf_names,
        [(f"const double {cv}", nd, o) for cv, nd, fld, comp, o in named],
        ccode=pr.doprint, graded=True)
    writes = {K: [] for K in range(max_order + 1)}
    for cv, nd, fld, comp, o in named:
        writes[o].append(
            f"  if(out->{fld} != NULL) out->{fld}[ip*p->dim.{fld} + {comp}] += {cv};")

    def seg(K):
        parts = [blocks.get(K, ""), "\n".join(writes[K])]
        return "\n".join(p for p in parts if p)

    body_parts = [seg(0)]
    for K in range(1, max_order + 1):
        inner = seg(K)
        if inner.strip():
            body_parts.append(f"#if _KMAX >= {K}\n{inner}\n#endif")
    body = "\n".join(p for p in body_parts if p)
    if pstruct:
        # params may be referenced only in a higher-order block that a low-order
        # kernel preprocesses away, so mark it used unconditionally.
        preamble = (f"  assert(p->params != NULL);\n"
                    f"  const {pstruct} *params = "
                    f"(const {pstruct} *)(p->params);\n  (void)params;\n")
    else:
        preamble = ""
    return preamble, body


import contextlib  # noqa: E402


@contextlib.contextmanager
def _screen_dens_mode():
    """Enable spin-density screening (screen_dens emits the _screen_dens(z)
    marker) for the enclosed block. Used around BOTH _resolve (so @helper bodies
    bake the marker -- the only way to reach screens inside helpers like OP's
    b88_zab) and the mod.f assembly call (top-level screens)."""
    L._SCREEN_DENS_MODE = True
    try:
        yield
    finally:
        L._SCREEN_DENS_MODE = False


def _resolve_screen_dens(f, na, nb, nt):
    """Resolve every _screen_dens(zform) marker on the fully inlined expression
    (so it reaches screens buried in @helpers). Polarized (nb given): replace by
    the RAW channel density -- na for the +z channel, nb for -z, by the sign of
    the z_thr-stripped zform -- so the floored empty-channel screen is exact
    rather than the cancelling (1 +/- z)*nt/2. GUARDED: only do this when the raw
    density actually EQUALS the reconstruction at a consistent generic point
    (z = (na-nb)/nt), confirming zform is a genuine channel zeta. Some functionals
    call screen_dens with a non-channel zeta where (1+z)*nt/2 is the intended
    density (e.g. gga_c_op_pw91); for those the guard fails and we keep the
    reconstruction -- no regression. Unpolarized (nb None): z=0, no cancellation,
    always the reconstruction. Only the SCREEN is rewritten; energy n_spin is
    untouched."""
    sd = L._screen_dens_marker
    is_marker = lambda e: getattr(e, "is_Function", False) and e.func is sd
    recon = lambda zform: (1 + zform) * nt / 2
    if nb is None:
        return f.replace(is_marker, lambda e: recon(e.args[0]))
    z = sp.Symbol("_z_screen_marker", real=True)
    # consistent generic point: z = (na - nb)/nt = (0.7-0.3)/1.0 = 0.4. The
    # threshold symbols get a tiny positive value so any inlined z_thr clamp
    # (a my_piecewise5 over p_a_zeta_threshold) folds: at z=0.4 the clamp's
    # conditions are concretely false and my_piecewise3.eval reduces it to 0.4.
    # Without this the clamp stays symbolic, float() raises, and the screen
    # falls back to the cancelling reconstruction -- the empty-channel leak.
    gen = {z: sp.Float("0.4"), na: sp.Float("0.7"), nb: sp.Float("0.3"),
           L.p_a_zeta_threshold: sp.Float("1e-12"),
           L.p_a_dens_threshold: sp.Float("1e-12")}
    strip = lambda e: e.replace(
        lambda x: getattr(x, "is_Function", False) and x.func.__name__ == "z_thr",
        lambda x: x.args[0])

    def pick(e):
        zform = e.args[0]
        zz = strip(zform)
        try:
            sval = float(zz.subs(gen))
            recon_g = float(recon(zz).subs(gen))
        except (TypeError, ValueError):
            return recon(zform)
        raw = na if sval > 0 else nb if sval < 0 else (na + nb) / 2
        if abs(float(raw.subs(gen)) - recon_g) < 1e-9 * (abs(recon_g) + 1.0):
            return raw
        return recon(zform)

    return f.replace(is_marker, pick)


def _clean_screen(na, nb, nt, build):
    """Assemble the polarized channel with spin-density screening: build(z) runs
    with _SCREEN_DENS_MODE on (set by the generator around _resolve too, so
    helper-internal screens get the marker), and after inlining each
    _screen_dens marker resolves to the raw channel density na/nb. Exact at the
    floored empty channel, unlike the (1 +/- z)*nt/2 reconstruction. The real
    z = (na - nb)/nt is substituted everywhere else."""
    z = sp.Symbol("_z_screen_marker", real=True)
    with _screen_dens_mode():
        raw = build(z)
    f = _resolve_screen_dens(_inline(raw), na, nb, nt)
    return f.subs(z, (na - nb) / nt)


def _apply_dimension(mod):
    """Set libxc_codegen's dimension globals from the module's XC_DIMENSIONS_*
    macro (1D/2D functionals) so RS_FACTOR, the exchange/kinetic exponents, and
    the dimension-sensitive library helpers (lda_x_spin, ...) match. Must run
    before _resolve (helpers bake in the dimension) and the assembly. Returns
    the saved globals for _restore_dimension."""
    dim = L._detect_dimension(mod)
    saved = L._set_dimension(dim)
    mod.DIMENSIONS, mod.RS_FACTOR, mod.LDA_X_FACTOR = (
        L.DIMENSIONS, L.RS_FACTOR, L.LDA_X_FACTOR)
    return dim, saved


def _inv_dim():
    return sp.Rational(1, L.DIMENSIONS)


def _assemble_lda(mod, spin):
    na = sp.Symbol("na", positive=True)
    if spin == "unpol":
        rs = L.RS_FACTOR / na ** _inv_dim()
        with _screen_dens_mode():
            raw = mod.f(rs, sp.S.Zero)
        return _resolve_screen_dens(_inline(raw), na, None, na), [na], na
    nb = sp.Symbol("nb", positive=True)
    nt = na + nb
    rs = L.RS_FACTOR / nt ** _inv_dim()
    f = _clean_screen(na, nb, nt, lambda z: mod.f(rs, z))
    return f, [na, nb], nt


def generate_lda(name, max_order):
    """Emit a full src/maple2c LDA .c via the AD engine: func_<order>_<spin>
    kernels that compute every output up to their order from one flat inlined
    CSE'd DAG. zk = f; the potentials are derivatives of the energy density
    n_total*f."""
    from math import factorial, prod
    mod, fam = _load(name)
    if fam != "lda_exc":
        raise ValueError("generate_lda is LDA-only")
    pstruct = getattr(mod, "PARAMS_STRUCT", None)
    _apply_dimension(mod)
    with _screen_dens_mode():
        _resolve(mod, max_order)
    ihave = ["XC_FLAGS_I_HAVE_EXC", "XC_FLAGS_I_HAVE_VXC", "XC_FLAGS_I_HAVE_FXC",
             "XC_FLAGS_I_HAVE_KXC", "XC_FLAGS_I_HAVE_LXC"]
    spin_bodies = {}
    preamble = ""
    for spin in ("unpol", "pol"):
        f, vs, nt = _assemble_lda(mod, spin)
        fx = _fold_const_piecewise(_inline(f))
        funcs, _ = _funcs_for(fx)
        n = len(vs)
        idx = AE.multi_indices(n, max_order)
        d = AE.DAG()
        memo = {}
        fj = AE.to_jet(d, fx, vs, idx, memo, funcs)
        nfj = AE.to_jet(d, nt * fx, vs, idx, memo, funcs)
        pr = L._ParamPrefixPrinter(
            extra_symbol_map={str(s): f"rho[{i}]" for i, s in enumerate(vs)})
        leaf_names = {s: pr.doprint(s) for s in vs}
        # Full output list across all orders, emitted ONCE as one graded body.
        named = []          # (cvar, node, field, comp, order)
        for o in range(max_order + 1):
            for j, combo in enumerate(_cwr(range(n), o)):
                a = [0] * n
                for c in combo:
                    a[c] += 1
                a = tuple(a)
                node = (fj.get(a) if o == 0
                        else d.cmul(prod(factorial(t) for t in a), nfj.get(a)))
                named.append((f"r{o}_{j}", node, _LDA_FIELD[o], j, o))
        preamble, body = _emit_kernel_tail_graded(
            d, named, leaf_names, pr, pstruct, max_order)
        spin_bodies[spin] = body

    guard = f"_{name.upper()}_KERNEL_BODY"
    header = (f"/*\n  Generated from python/lda_exc/{name}.py via the AD engine\n"
              f"  (scripts/sympy2c/ad_bridge.py generate_lda). Do not edit.\n*/\n\n")
    fp = [f"#ifndef {guard}",
          f"#define maple2c_order {max_order}",
          f"#define MAPLE2C_FLAGS ({' | '.join(ihave[:max_order + 1])})",
          "",
          f"#define {guard}"]
    for T in range(max_order + 1):
        for spin in ("unpol", "pol"):
            fp += [f"#if XC_MAXORDER >= {T}",
                   f"#define _KMAX {T}",
                   f"#define _SPIN_UNPOL {1 if spin == 'unpol' else 0}",
                   f"#define FUNC_NAME func_{_ORD[T]}_{spin}",
                   f'#include "{name}.c"',
                   "#undef _KMAX",
                   "#undef _SPIN_UNPOL",
                   "#undef FUNC_NAME",
                   "#endif"]
    bp = ["#else  /* re-inclusion: one graded body -> (FUNC_NAME, _KMAX, _SPIN_UNPOL) */",
          "GPU_DEVICE_FUNCTION static inline void",
          "FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, "
          "xc_lda_out_params *out)",
          "{",
          preamble.rstrip("\n"),
          "#if _SPIN_UNPOL",
          spin_bodies["unpol"],
          "#else",
          spin_bodies["pol"],
          "#endif",
          "}",
          "#endif"]
    text = header + "\n".join(fp) + "\n\n" + "\n".join(bp) + "\n"
    return _apply_replace(mod, text)


def _assemble_gga_spin(mod, spin):
    idim = _inv_dim()
    eg = sp.Integer(1) + idim          # reduced-gradient exponent (4/3 in 3D)
    na = sp.Symbol("na", positive=True)
    if spin == "unpol":
        gaa = sp.Symbol("gaa", positive=True)
        rs = L.RS_FACTOR / na ** idim
        xt = sp.sqrt(gaa) / na ** eg
        xs = sp.sqrt(gaa / 4) / (na / 2) ** eg
        with _screen_dens_mode():
            raw = mod.f(rs, sp.S.Zero, xt, xs, xs)
        f = _resolve_screen_dens(_inline(raw), na, None, na)
        return f, [na], [gaa], na
    nb = sp.Symbol("nb", positive=True)
    gaa, gbb = sp.symbols("gaa gbb", positive=True)
    gab = sp.Symbol("gab")
    nt = na + nb
    rs = L.RS_FACTOR / nt ** idim
    f = _clean_screen(na, nb, nt, lambda z: mod.f(
        rs, z, sp.sqrt(gaa + 2 * gab + gbb) / nt ** eg,
        sp.sqrt(gaa) / na ** eg, sp.sqrt(gbb) / nb ** eg))
    return f, [na, nb], [gaa, gab, gbb], nt


def generate_gga(name, max_order):
    """Emit a full src/maple2c GGA .c via the AD engine. Each derivative splits
    into a rho-part and a sigma-part (GGA_FIELDS); zk = f, the rest are
    derivatives of n_total*f, mapped to out-><field>[ip*dim+component]."""
    from math import factorial, prod
    mod, fam = _load(name)
    if fam != "gga_exc":
        raise ValueError("generate_gga is GGA-only")
    pstruct = getattr(mod, "PARAMS_STRUCT", None)
    _apply_dimension(mod)
    with _screen_dens_mode():
        _resolve(mod, max_order)
    ihave = ["XC_FLAGS_I_HAVE_EXC", "XC_FLAGS_I_HAVE_VXC", "XC_FLAGS_I_HAVE_FXC",
             "XC_FLAGS_I_HAVE_KXC", "XC_FLAGS_I_HAVE_LXC"]
    spin_bodies = {}
    preamble = ""
    for spin in ("unpol", "pol"):
        f, rho_s, sig_s, nt = _assemble_gga_spin(mod, spin)
        vs = rho_s + sig_s
        n_rho, n_sigma, n = len(rho_s), len(sig_s), len(rho_s) + len(sig_s)
        fx = _fold_const_piecewise(_inline(f))
        funcs, _ = _funcs_for(fx)
        idx = AE.multi_indices(n, max_order)
        d = AE.DAG()
        memo = {}
        fj = AE.to_jet(d, fx, vs, idx, memo, funcs)
        nfj = AE.to_jet(d, nt * fx, vs, idx, memo, funcs)
        smap = {str(rho_s[i]): f"rho[{i}]" for i in range(n_rho)}
        smap.update({str(sig_s[j]): f"sigma[{j}]" for j in range(n_sigma)})
        pr = L._ParamPrefixPrinter(extra_symbol_map=smap)
        leaf_names = {s: pr.doprint(s) for s in vs}
        # Full output list across all orders, emitted ONCE as one graded body.
        named = []          # (cvar, node, field, comp, order)
        for o in range(max_order + 1):
            for field, oR, oS in L.GGA_FIELDS[o]:
                for k, (ridx, sidx) in enumerate(
                        L._mixed_partials([oR, oS], [n_rho, n_sigma])):
                    a = [0] * n
                    for i in ridx:
                        a[i] += 1
                    for j in sidx:
                        a[n_rho + j] += 1
                    a = tuple(a)
                    node = (fj.get(a) if o == 0
                            else d.cmul(prod(factorial(t) for t in a), nfj.get(a)))
                    named.append((f"r{o}_{field}_{k}", node, field, k, o))
        preamble, body = _emit_kernel_tail_graded(
            d, named, leaf_names, pr, pstruct, max_order)
        spin_bodies[spin] = body

    guard = f"_{name.upper()}_KERNEL_BODY"
    header = (f"/*\n  Generated from python/gga_exc/{name}.py via the AD engine\n"
              f"  (scripts/sympy2c/ad_bridge.py generate_gga). Do not edit.\n*/\n\n")
    fp = [f"#ifndef {guard}",
          f"#define maple2c_order {max_order}",
          f"#define MAPLE2C_FLAGS ({' | '.join(ihave[:max_order + 1])})",
          "",
          f"#define {guard}"]
    for T in range(max_order + 1):
        for spin in ("unpol", "pol"):
            fp += [f"#if XC_MAXORDER >= {T}",
                   f"#define _KMAX {T}",
                   f"#define _SPIN_UNPOL {1 if spin == 'unpol' else 0}",
                   f"#define FUNC_NAME func_{_ORD[T]}_{spin}",
                   f'#include "{name}.c"',
                   "#undef _KMAX",
                   "#undef _SPIN_UNPOL",
                   "#undef FUNC_NAME",
                   "#endif"]
    bp = ["#else  /* re-inclusion: one graded body -> (FUNC_NAME, _KMAX, _SPIN_UNPOL) */",
          "GPU_DEVICE_FUNCTION static inline void",
          "FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, "
          "const double *sigma, xc_gga_out_params *out)",
          "{",
          preamble.rstrip("\n"),
          "#if _SPIN_UNPOL",
          spin_bodies["unpol"],
          "#else",
          spin_bodies["pol"],
          "#endif",
          "}",
          "#endif"]
    text = header + "\n".join(fp) + "\n\n" + "\n".join(bp) + "\n"
    return _apply_replace(mod, text)


def _assemble_mgga_spin(mod, spin):
    idim = _inv_dim()
    eg = sp.Integer(1) + idim          # reduced-gradient exponent (4/3 in 3D)
    ek = sp.Integer(1) + 2 * idim      # kinetic/laplacian exponent (5/3 in 3D)
    na = sp.Symbol("na", positive=True)
    if spin == "unpol":
        gaa = sp.Symbol("gaa", positive=True)
        la = sp.Symbol("la")
        ta = sp.Symbol("ta", positive=True)
        rs = L.RS_FACTOR / na ** idim
        xs = sp.sqrt(gaa / 4) / (na / 2) ** eg
        u = (la / 2) / (na / 2) ** ek
        t = (ta / 2) / (na / 2) ** ek
        with _screen_dens_mode():
            raw = mod.f(rs, sp.S.Zero, sp.sqrt(gaa) / na ** eg,
                        xs, xs, u, u, t, t)
        f = _resolve_screen_dens(_inline(raw), na, None, na)
        return f, [na], [gaa], [la], [ta], na
    nb = sp.Symbol("nb", positive=True)
    gaa, gbb = sp.symbols("gaa gbb", positive=True)
    gab = sp.Symbol("gab")
    la, lb = sp.symbols("la lb")
    ta, tb = sp.symbols("ta tb", positive=True)
    nt = na + nb
    rs = L.RS_FACTOR / nt ** idim
    f = _clean_screen(na, nb, nt, lambda z: mod.f(
        rs, z, sp.sqrt(gaa + 2 * gab + gbb) / nt ** eg,
        sp.sqrt(gaa) / na ** eg, sp.sqrt(gbb) / nb ** eg,
        la / na ** ek, lb / nb ** ek, ta / na ** ek, tb / nb ** ek))
    return f, [na, nb], [gaa, gab, gbb], [la, lb], [ta, tb], nt


def generate_mgga(name, max_order):
    """Emit a full src/maple2c MGGA .c via the AD engine: func_<order>_<spin>(p,
    ip, rho, sigma, lapl, tau, out) kernels. Derivatives split across the four
    variable groups (MGGA_FIELDS); zk = f, the rest are derivatives of
    n_total*f."""
    from math import factorial, prod
    mod, fam = _load(name)
    if fam != "mgga_exc":
        raise ValueError("generate_mgga is MGGA-only")
    pstruct = getattr(mod, "PARAMS_STRUCT", None)
    _apply_dimension(mod)
    with _screen_dens_mode():
        _resolve(mod, max_order)
    ihave = ["XC_FLAGS_I_HAVE_EXC", "XC_FLAGS_I_HAVE_VXC", "XC_FLAGS_I_HAVE_FXC",
             "XC_FLAGS_I_HAVE_KXC", "XC_FLAGS_I_HAVE_LXC"]
    spin_bodies = {}
    preamble = ""
    for spin in ("unpol", "pol"):
        f, rho_s, sig_s, lap_s, tau_s, nt = _assemble_mgga_spin(mod, spin)
        groups = [rho_s, sig_s, lap_s, tau_s]
        vs = rho_s + sig_s + lap_s + tau_s
        nvars = tuple(len(g) for g in groups)
        offs = [0]
        for g in groups:
            offs.append(offs[-1] + len(g))
        n = len(vs)
        fx = _fold_const_piecewise(_inline(f))
        funcs, _ = _funcs_for(fx)
        idx = AE.multi_indices(n, max_order)
        d = AE.DAG()
        memo = {}
        fj = AE.to_jet(d, fx, vs, idx, memo, funcs)
        nfj = AE.to_jet(d, nt * fx, vs, idx, memo, funcs)
        arrs = ["rho", "sigma", "lapl", "tau"]
        smap = {}
        for gi, g in enumerate(groups):
            for j, s in enumerate(g):
                smap[str(s)] = f"{arrs[gi]}[{j}]"
        pr = L._ParamPrefixPrinter(extra_symbol_map=smap)
        leaf_names = {s: pr.doprint(s) for s in vs}
        # Full output list across all orders 0..max_order, emitted ONCE as one
        # order-graded body (each order's temps/writes wrapped in #if _KMAX>=K).
        named = []
        for o in range(max_order + 1):
            for field, oR, oS, oL, oT in L.MGGA_FIELDS[o]:
                for k, combo in enumerate(
                        L._mgga_partials((oR, oS, oL, oT), nvars)):
                    a = [0] * n
                    for gi, gidx in enumerate(combo):
                        for i in gidx:
                            a[offs[gi] + i] += 1
                    a = tuple(a)
                    node = (fj.get(a) if o == 0
                            else d.cmul(prod(factorial(t) for t in a), nfj.get(a)))
                    named.append((f"r{o}_{field}_{k}", node, field, k, o))
        preamble, body = _emit_kernel_tail_graded(
            d, named, leaf_names, pr, pstruct, max_order)
        spin_bodies[spin] = body

    # One self-including file. The first pass defines maple2c_order/flags then
    # re-includes this file once per (order, spin) with _KMAX/_SPIN_UNPOL/
    # FUNC_NAME set; each re-inclusion takes the #else branch and expands the
    # single graded body into a concrete func_<order>_<spin>. Storing one body
    # per spin instead of four nested per-order copies is the on-disk win.
    guard = f"_{name.upper()}_KERNEL_BODY"
    header = (f"/*\n  Generated from python/mgga_exc/{name}.py via the AD engine\n"
              f"  (scripts/sympy2c/ad_bridge.py generate_mgga). Do not edit.\n*/\n\n")
    fp = [f"#ifndef {guard}",
          f"#define maple2c_order {max_order}",
          f"#define MAPLE2C_FLAGS ({' | '.join(ihave[:max_order + 1])})",
          "",
          f"#define {guard}"]
    for T in range(max_order + 1):
        for spin in ("unpol", "pol"):
            fp += [f"#if XC_MAXORDER >= {T}",
                   f"#define _KMAX {T}",
                   f"#define _SPIN_UNPOL {1 if spin == 'unpol' else 0}",
                   f"#define FUNC_NAME func_{_ORD[T]}_{spin}",
                   f'#include "{name}.c"',
                   "#undef _KMAX",
                   "#undef _SPIN_UNPOL",
                   "#undef FUNC_NAME",
                   "#endif"]
    bp = ["#else  /* re-inclusion: one graded body -> (FUNC_NAME, _KMAX, _SPIN_UNPOL) */",
          "GPU_DEVICE_FUNCTION static inline void",
          "FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, "
          "const double *sigma, const double *lapl, const double *tau, "
          "xc_mgga_out_params *out)",
          "{",
          preamble.rstrip("\n"),
          "#if _SPIN_UNPOL",
          spin_bodies["unpol"],
          "#else",
          spin_bodies["pol"],
          "#endif",
          "}",
          "#endif"]
    text = header + "\n".join(fp) + "\n\n" + "\n".join(bp) + "\n"
    return _apply_replace(mod, text)


def _assemble_vxc(mod, spin, family):
    """Assemble the potential channels of a *_vxc functional.

    The math file's ``f(...)`` is the exchange-correlation POTENTIAL itself
    (vrho), not an energy density -- there is no zk, and at the reference order
    (VXC = the lowest output) no differentiation is needed: the vrho reference
    is simply f evaluated. Returns ``(pots, groups)`` where ``pots`` is
    ``[pot_up]`` (unpol) or ``[pot_up, pot_dn]`` (pol) and ``groups`` is the
    per-variable-group symbol lists ``[rho, sigma, lapl, tau]`` (as in the
    energy assemblers). The spin-down potential is the up potential with the two
    spin channels exchanged, matching libxc_codegen._emit_vxc's
    ``f(rs, -z, xt, xs1, xs0, u1, u0, t1, t0)`` and the same reduced-variable
    maps.
    """
    idim = _inv_dim()
    eg = sp.Integer(1) + idim
    ek = sp.Integer(1) + 2 * idim
    na = sp.Symbol("na", positive=True)
    if spin == "unpol":
        rs = L.RS_FACTOR / na ** idim
        gaa = sp.Symbol("gaa", positive=True)
        la = sp.Symbol("la")
        ta = sp.Symbol("ta", positive=True)
        xs = sp.sqrt(gaa / 4) / (na / 2) ** eg
        if family == "lda":
            build = lambda z: mod.f(rs, z)
            groups = [[na], [], [], []]
        elif family == "gga":
            build = lambda z: mod.f(rs, z, sp.sqrt(gaa) / na ** eg, xs, xs)
            groups = [[na], [gaa], [], []]
        else:
            u = (la / 2) / (na / 2) ** ek
            t = (ta / 2) / (na / 2) ** ek
            build = lambda z: mod.f(rs, z, sp.sqrt(gaa) / na ** eg, xs, xs,
                                    u, u, t, t)
            groups = [[na], [gaa], [la], [ta]]
        with _screen_dens_mode():
            raw = build(sp.S.Zero)
        pot_up = _resolve_screen_dens(_inline(raw), na, None, na)
        return [pot_up], groups
    nb = sp.Symbol("nb", positive=True)
    nt = na + nb
    rs = L.RS_FACTOR / nt ** idim
    gaa, gbb = sp.symbols("gaa gbb", positive=True)
    gab = sp.Symbol("gab")
    la, lb = sp.symbols("la lb")
    ta, tb = sp.symbols("ta tb", positive=True)
    if family == "lda":
        build = lambda z: mod.f(rs, z)
        groups = [[na, nb], [], [], []]
        swap = {na: nb, nb: na}
    elif family == "gga":
        xt = sp.sqrt(gaa + 2 * gab + gbb) / nt ** eg
        build = lambda z: mod.f(rs, z, xt,
                                sp.sqrt(gaa) / na ** eg, sp.sqrt(gbb) / nb ** eg)
        groups = [[na, nb], [gaa, gab, gbb], [], []]
        swap = {na: nb, nb: na, gaa: gbb, gbb: gaa}
    else:
        xt = sp.sqrt(gaa + 2 * gab + gbb) / nt ** eg
        build = lambda z: mod.f(rs, z, xt,
                                sp.sqrt(gaa) / na ** eg, sp.sqrt(gbb) / nb ** eg,
                                la / na ** ek, lb / nb ** ek,
                                ta / na ** ek, tb / nb ** ek)
        groups = [[na, nb], [gaa, gab, gbb], [la, lb], [ta, tb]]
        swap = {na: nb, nb: na, gaa: gbb, gbb: gaa, la: lb, lb: la, ta: tb,
                tb: ta}
    pot_up = _clean_screen(na, nb, nt, build)
    # Down channel = up with the two spin channels exchanged (gab is symmetric,
    # rs and xt are total-density quantities, so both are swap-invariant); this
    # equals f(rs, -z, xt, xs1, xs0, u1, u0, t1, t0).
    pot_dn = pot_up.subs(swap, simultaneous=True)
    return [pot_up, pot_dn], groups


# libxc input-array names for the engine's variable symbols.
_LIBXC_VAR_MAP = {"na": "rho[0]", "nb": "rho[1]",
                  "gaa": "sigma[0]", "gab": "sigma[1]", "gbb": "sigma[2]",
                  "la": "lapl[0]", "lb": "lapl[1]", "ta": "tau[0]", "tb": "tau[1]"}


def _param_env(fx, vs, params=None):
    import random
    pvals = {"params_a_alpha": 1.8, "params_a_omega": 4.5,
             "params_a_beta": 0.06672455, "params_a_gamma": 0.031091,
             "zeta_threshold": 1e-12, "dens_threshold": 1e-12, **(params or {})}
    env = {}
    for s in fx.free_symbols:
        if s in vs:
            continue
        # `in`, not `.get() or`: a legitimate 0.0 parameter is falsy, and the
        # `or` form silently substituted a random value for it.
        name = str(s)
        env[s] = (pvals[name] if name in pvals
                  else random.Random(name).uniform(0.2, 0.9))
    return env


def _default_point(vs):
    defaults = {"na": 0.7, "nb": 0.4, "gaa": 0.3, "gbb": 0.2, "gab": 0.1,
                "la": 0.05, "lb": 0.03, "ta": 0.9, "tb": 0.6}
    return {s: defaults.get(str(s), 0.5) for s in vs}


def emit_check(name, order, params=None):
    """Emit C for every order-<=`order` partial, compile it, and check the
    compiled output against the engine's own evaluation (which validate() has
    in turn checked against sp.diff). Confirms emit_c is correct on the real
    functional's constructs. Restricted to scalar-parameter functionals."""
    import ctypes
    import os as _os
    import subprocess
    import tempfile
    from math import factorial, prod
    d, J, idx, vs, fx = build(name, order)
    params_syms = sorted((s for s in fx.free_symbols if s not in vs), key=str)
    penv = _param_env(fx, vs, params)
    point = _default_point(vs)

    # Sanitise array-parameter names (params_a_b_0_[0]) to valid C identifiers
    # for the standalone test; the real libxc emission rewrites params_a_* to
    # params->member[i] via LibxcCPrinter.
    def _san(nm):
        return nm.replace("[", "_").replace("]", "_")

    def _ccode(e):
        return sp.ccode(e).replace("[", "_").replace("]", "_")

    outputs = [(f"out[{k}]", d.cmul(prod(factorial(t) for t in a), J.get(a)))
               for k, a in enumerate(idx)]
    body = AE.emit_c(d, {s: str(s) for s in vs}, outputs, ccode=_ccode)
    args = list(vs) + params_syms
    decl = ", ".join(f"double {_san(str(s))}" for s in args)
    src = ("#include <math.h>\n#ifndef M_PI\n#define M_PI 3.14159265358979323846\n"
           "#endif\n"
           "static inline double xc_expm1(double x){return expm1(x);}\n"
           "static inline double xc_log1p(double x){return log1p(x);}\n"
           "void k(" + decl + ", double* out) {\n" + body + "\n}\n")

    with tempfile.TemporaryDirectory() as td:
        cp, so = _os.path.join(td, "k.c"), _os.path.join(td, "k.so")
        with open(cp, "w") as fh:
            fh.write(src)
        subprocess.run(["gcc", "-shared", "-fPIC", "-O2", "-o", so, cp, "-lm"],
                       check=True)
        lib = ctypes.CDLL(so)
        lib.k.argtypes = [ctypes.c_double] * len(args) + [ctypes.POINTER(ctypes.c_double)]
        cargs = [point[s] for s in vs] + [penv[s] for s in params_syms]
        out = (ctypes.c_double * len(idx))()
        lib.k(*cargs, out)

    val = d.evaluate(point, penv)
    err = max(abs(out[k] - prod(factorial(t) for t in a) * val[J.get(a)])
              / (abs(prod(factorial(t) for t in a) * val[J.get(a)]) + 1e-12)
              for k, a in enumerate(idx))
    print(f"{name} order {order}: emit+compile {len(idx)} partials, "
          f"{len(src.splitlines())} lines C, compiled-vs-engine maxrelerr={err:.2e}  "
          f"{'PASS' if err < 1e-9 else 'FAIL'}")
    return err


if __name__ == "__main__":
    name = sys.argv[1] if len(sys.argv) > 1 else "gga_c_zvpbeint"
    order = int(sys.argv[2]) if len(sys.argv) > 2 else 1
    mode = sys.argv[3] if len(sys.argv) > 3 else "validate"
    fn = emit_check if mode == "emit" else validate
    sys.exit(0 if fn(name, order) < 1e-9 else 1)
