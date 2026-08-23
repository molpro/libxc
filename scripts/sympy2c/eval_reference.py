#!/usr/bin/env python3
"""Arbitrary-precision reference values for libxc functionals.

Evaluate a functional's energy density and any of its derivatives
symbolically (via sympy) and numerically at user-controlled precision
(via mpmath, through sympy.evalf). Intended as a ground-truth
generator for the C codegen -- independent of both Maple's emitter
and libxc's double-precision pipeline.

Two top-level entry points:

* ``evaluate(name, spin, rho, sigma=..., lapl=..., tau=...,
              precision=50, max_order=2)``
  -- compute at a single precision. Returns a dict
  ``{field: [[val_per_channel] per point]}``.

* ``evaluate_converged(name, ..., max_order=2, base_precision=50,
                       check_precision=100, max_precision=400)``
  -- compute at ``base_precision`` and at ``check_precision``; for any
  point/channel where the two rounded-to-double values disagree, bump
  the precision (doubling) and retry just those points until they
  converge or ``max_precision`` is reached. Returns
  ``(refs, status)`` where ``status[field][ip][k]`` is ``"ok"`` or
  the failure precision.

The evaluator inlines every @helper application back into a single
symbolic tree, then differentiates and evaluates with ``.evalf(N)``.
Both work_*_inc.c-style input clipping (rho >= dens_threshold,
sigma_ss >= sigma_threshold^2) and the off-diagonal-sigma clamp are
applied before evaluation, so the comparison target matches what a
correct kernel emits at the same point. dens_threshold defaults to
the per-functional value declared in src/<name>.c (parsed at first
call); pass an explicit ``dens_threshold=`` to override.
"""

import argparse
import importlib
import math
import os
import re
import sys
from itertools import combinations_with_replacement

_HERE = os.path.dirname(os.path.abspath(__file__))
_PYTHON = os.path.abspath(os.path.join(_HERE, "..", "..", "python"))
_SRC = os.path.abspath(os.path.join(_HERE, "..", "..", "src"))
for path in (_PYTHON, _HERE):
    if path not in sys.path:
        sys.path.insert(0, path)
for sub in ("lda_exc", "lda_vxc",
            "gga_exc", "gga_vxc",
            "mgga_exc", "mgga_vxc"):
    p = os.path.join(_PYTHON, sub)
    if os.path.isdir(p) and p not in sys.path:
        sys.path.insert(0, p)

import sympy as sp                                            # noqa: E402

import libxc_codegen as L                                     # noqa: E402
from sympy2c import dens_threshold as _dens_thr_sym           # noqa: E402
from sympy2c import zeta_threshold as _zeta_thr_sym           # noqa: E402
from sympy2c import (cam_omega as _cam_omega_sym,             # noqa: E402
                     cam_alpha as _cam_alpha_sym,
                     cam_beta as _cam_beta_sym)


# C-side macro constants that flow through the kernel expression as
# named SymPy symbols and need numeric values for evalf. Matches the
# definitions in src/util.h (the standard libm cbrt of 3 / pi, IEEE
# double-precision epsilon and minimum normal).
_C_CONSTANTS = {
    L._M_CBRT3: sp.Rational(3) ** sp.Rational(1, 3),
    L._M_CBRTPI: sp.pi ** sp.Rational(1, 3),
    L.XC_EPSILON: sp.Float("2.2204460492503131e-16", 80),
    L.XC_MIN: sp.Float("2.2250738585072014e-308", 80),
}


# --------------------------------------------------------------------------
# Per-functional dens_threshold lookup (parsed from src/<name>.c).
# --------------------------------------------------------------------------

_THRESHOLD_CACHE = {}
_PARAMS_CACHE = {}


_MACRO_ENV = None


def _macro_env():
    """Return a namespace of the numeric ``#define`` macros declared in
    ``src/util.h`` (plus the standard math constants) so that parameter
    default values written as C macros or arithmetic expressions -- e.g.
    ``MU_PBE`` or ``0.066725*M_PI*M_PI/3`` -- can be evaluated rather
    than silently dropped."""
    global _MACRO_ENV
    if _MACRO_ENV is not None:
        return _MACRO_ENV
    env = {"M_PI": math.pi, "M_E": math.e}
    util = os.path.join(_SRC, "util.h")
    if os.path.exists(util):
        with open(util) as f:
            text = f.read()
        # value token: starts with a digit or sign, runs until whitespace
        # or the start of a comment; long-double "L" suffixes are stripped
        for m in re.finditer(
                r"#define\s+(\w+)\s+([-+0-9][0-9.eE+\-]*)L?\b", text):
            try:
                env[m.group(1)] = float(m.group(2))
            except ValueError:
                pass
    _MACRO_ENV = env
    return env


def _eval_param_value(s):
    """Evaluate a single C parameter default initializer to a float,
    resolving util.h macros and simple arithmetic. Returns ``None`` when
    the value cannot be resolved (the caller keeps the positional slot so
    the names/values zip stays aligned)."""
    s = re.sub(r"(?<=[0-9.])L\b", "", s.strip())
    if not s:
        return None
    try:
        return float(s)
    except ValueError:
        pass
    try:
        return float(eval(s, {"__builtins__": {}}, _macro_env()))
    except Exception:
        return None


def _read_c_array(text, arrname):
    """Return the brace-delimited initializer body of the C array named
    ``arrname`` in ``text`` (``static`` optional, ``const char *`` or
    ``const double``), or ``None`` if not declared."""
    m = re.search(
        r"(?:static\s+)?(?:const\s+)?(?:char\s*\*\s*|double\s+)"
        + re.escape(arrname) + r"\s*\[[^]]*\]\s*=\s*\{([^}]*)\}",
        text)
    return m.group(1) if m else None


_SOURCE_CACHE = {}


def _resolve_source(name):
    """Locate the src/*.c file that DEFINES ``xc_func_info_<name>`` and the
    SymPy math module it uses. Several functionals share one source: e.g.
    mgga_x_bj06/rpp09 are defined in mgga_x_tb09.c (with their own ext_params
    structs) and reuse tb09's kernel, and gga_x_lbm lives in gga_x_lb.c. Return
    ``(src_path, text, fam_dir, math_name)`` where ``fam_dir/math_name`` come
    from that file's ``#include "maple2c/<fam>/<math>.c"`` -- the python/ module
    to evaluate. Falls back to the own-name file / own-name module when nothing
    more specific is found. The own-name file is tried first, so the common
    one-functional-per-file case never scans the tree."""
    if name in _SOURCE_CACHE:
        return _SOURCE_CACHE[name]
    define_re = re.compile(r"xc_func_info_" + re.escape(name) + r"\b\s*=")
    own = os.path.join(_SRC, name + ".c")
    src_path = text = None
    if os.path.exists(own):
        with open(own) as f:
            t = f.read()
        if define_re.search(t):
            src_path, text = own, t
    if text is None:
        import glob
        for path in sorted(glob.glob(os.path.join(_SRC, "*.c"))):
            with open(path) as f:
                t = f.read()
            if define_re.search(t):
                src_path, text = path, t
                break
    if text is None:                       # never defined -> own-file guess
        src_path = own
        text = open(own).read() if os.path.exists(own) else ""
    inc = re.search(r'#include\s+"maple2c/(\w+)/(\w+)\.c"', text)
    fam_dir, math_name = (inc.group(1), inc.group(2)) if inc else (None, name)
    res = (src_path, text, fam_dir, math_name)
    _SOURCE_CACHE[name] = res
    return res


def _import_functional(name, macro_name=None):
    """Import the functional's python module with the requested functional's
    OWN parameter-default block activated. The generated .py guards default
    params behind `if defined('<name>_params')` -- the analog of Maple's
    $ifdef block -- which a plain import leaves inactive, so params declared
    only there (lda_c_pw's params_a_a PW92 coefficient lists) stay unbound
    symbols. Pre-injecting the macro before exec mirrors maple_reference's
    `$define <name>_params`.

    `macro_name` (default `name`) is the functional whose block to activate;
    it differs from `name` when a variant evaluates its base module -- there
    we must NOT activate the base's own block (which would bake the base's
    defaults), leaving the params symbolic for the caller to override."""
    import importlib.util
    macro_name = macro_name or name
    path = None
    for sub in ("lda_exc", "gga_exc", "mgga_exc",
                "lda_vxc", "gga_vxc", "mgga_vxc"):
        cand = os.path.join(_PYTHON, sub, name + ".py")
        if os.path.isfile(cand):
            path = cand
            break
    if path is None:
        # Variant registered in a shared src file (e.g. mgga_x_bj06 in
        # mgga_x_tb09.c) has no own math module: evaluate its base module,
        # keeping macro_name == name so the base's default block is NOT
        # activated -- the variant's params come from _read_parameters instead.
        _, _, fam_dir, math_name = _resolve_source(name)
        if fam_dir and math_name != name:
            cand = os.path.join(_PYTHON, fam_dir, math_name + ".py")
            if os.path.isfile(cand):
                path = cand
    if path is None:
        return importlib.import_module(name)
    spec = importlib.util.spec_from_file_location(name, path)
    mod = importlib.util.module_from_spec(spec)
    mod.__dict__["_macro_" + macro_name + "_params"] = True
    sys.modules[name] = mod
    spec.loader.exec_module(mod)
    return mod


def _read_parameters(name, mod):
    """Return ``{params_a_<paramname>_symbol: default_value}`` for the
    parameters declared in ``src/<name>.c``. The names and default-value
    C arrays are linked through the ext_params block of the
    ``xc_func_info_<name>`` struct -- ``{N_PAR, <names>, <desc>,
    <values>, set_ext_params...}`` -- rather than guessed from a naming
    convention, because the values array may be called ``<prefix>_values``
    or ``par_<name>`` (both are in wide use) and a single functional file
    holds one such block per variant. The substituent keys are the actual
    ``_Param`` instances bound in the functional module (subclass of
    ``sp.Symbol`` with real=True), looked up by name -- a plain
    ``sp.Symbol`` would not match for subs because SymPy distinguishes
    objects by class + assumptions."""
    key = name
    if key in _PARAMS_CACHE:
        return _PARAMS_CACHE[key]
    _, text, _, _ = _resolve_source(name)
    out = {}
    if text:
        # Anchor on this functional's own func_info struct so the right
        # variant's default values are picked (e.g. gga_x_pbe vs the
        # pbe_*_values variants that share pbe_names).
        anchor = re.search(
            r"xc_func_info_" + re.escape(name) + r"\b", text)
        tail = text[anchor.start():] if anchor else text
        block = re.search(
            r"\{\s*\w+\s*,\s*(\w+)\s*,\s*\w+\s*,\s*(\w+)\s*,"
            r"\s*set_ext_params",
            tail)
        if block:
            names_body = _read_c_array(text, block.group(1))
            values_body = _read_c_array(text, block.group(2))
            if names_body is not None and values_body is not None:
                names = [s.strip().strip('"').lstrip("_")
                         for s in names_body.split(",") if s.strip()]
                values = [_eval_param_value(s)
                          for s in values_body.split(",")]
                for n, v in zip(names, values):
                    if v is None:
                        continue
                    sym = getattr(mod, "params_a_" + n, None)
                    if isinstance(sym, sp.Symbol):
                        out[sym] = sp.Float(v, 80)
        # Fallback: params set directly in init() as `params->NAME = VALUE;`
        # rather than through an ext_params block (e.g. gga_x_lb/lbm). When the
        # values sit in a `switch(p->info->number){ case XC_<NAME>: ... }` that
        # selects per variant, restrict to this functional's case block.
        if not out:
            macro = "XC_" + name.upper()
            case_m = re.search(
                r"case\s+" + re.escape(macro) + r"\s*:(.*?)\bbreak\s*;",
                text, re.DOTALL)
            scope = case_m.group(1) if case_m else text
            for pm in re.finditer(r"params->(\w+)\s*=\s*([^;]+);", scope):
                v = _eval_param_value(pm.group(2))
                if v is None:
                    continue
                sym = getattr(mod, "params_a_" + pm.group(1), None)
                if isinstance(sym, sp.Symbol):
                    out[sym] = sp.Float(v, 80)
    _PARAMS_CACHE[key] = out
    return out


_EXTVALS_CACHE = {}


def _ext_param_values(name):
    """``{stripped_ext_param_name: default_value}`` for every entry of the
    functional's ext_params block, array elements included. Some functionals
    store an array parameter as individual scalars (e.g. tpss keeps its C0_c[4]
    as C0_c0..C0_c3) while the .py accesses the array ``params_a_C0_c[i]``;
    _read_parameters binds only entries with a matching module symbol, so those
    array elements are dropped there. Callers resolving ``params_a_X[i]`` use
    this name-keyed view instead."""
    if name in _EXTVALS_CACHE:
        return _EXTVALS_CACHE[name]
    _, text, _, _ = _resolve_source(name)
    out = {}
    if text:
        anchor = re.search(r"xc_func_info_" + re.escape(name) + r"\b", text)
        tail = text[anchor.start():] if anchor else text
        block = re.search(
            r"\{\s*\w+\s*,\s*(\w+)\s*,\s*\w+\s*,\s*(\w+)\s*,\s*set_ext_params",
            tail)
        if block:
            nb = _read_c_array(text, block.group(1))
            vb = _read_c_array(text, block.group(2))
            if nb is not None and vb is not None:
                names = [s.strip().strip('"').lstrip("_")
                         for s in nb.split(",") if s.strip()]
                values = [_eval_param_value(s) for s in vb.split(",")]
                for n, v in zip(names, values):
                    if v is not None:
                        out[n] = v
    _EXTVALS_CACHE[name] = out
    return out


def _read_dens_threshold(name):
    """Return the per-functional dens_threshold declared in
    ``src/<name>.c`` (the 7th positional initializer of the
    xc_func_info_<name> struct). Falls back to 1e-20 if the file or
    pattern isn't found."""
    if name in _THRESHOLD_CACHE:
        return _THRESHOLD_CACHE[name]
    _, text, _, _ = _resolve_source(name)
    val = 1e-20
    if text:
        # Strip C comments first: a block comment between XC_FLAGS and the
        # dens_threshold literal (e.g. gga_c_op_pw91's multi-line note, which
        # itself contains "1e-10" and commas) otherwise defeats the regex below
        # and the value silently falls back to 1e-20 -- for op_pw91 that turns
        # off the down-channel density screen the build applies at 1e-10, so the
        # oracle stops screening near-empty tail channels and emits references
        # thousands of times off (N pt19: -149879 vs the build's correct -58.5).
        text = re.sub(r"/\*.*?\*/", " ", text, flags=re.DOTALL)
        text = re.sub(r"//[^\n]*", " ", text)
        # The struct body holds nested {} for the references-init, so
        # match the XC_FLAGS line directly inside the struct rather
        # than trying to balance braces. The dens_threshold is the
        # very next field after XC_FLAGS.
        # Word-boundary anchor so a functional does NOT match a longer sibling
        # sharing its name as a prefix (e.g. gga_c_wi vs gga_c_wi0, whose
        # thresholds differ): a plain substring find() would pick the first,
        # reading the wrong dens_threshold.
        am = re.search(r"xc_func_info_" + re.escape(name) + r"\b", text)
        idx = am.start() if am else -1
        if idx >= 0:
            after = text[idx:idx + 4000]
            m = re.search(
                r"XC_FLAGS_[^;]*?,\s*([\d.eE+\-]+)\s*,",
                after, flags=re.DOTALL)
            if m:
                try:
                    val = float(m.group(1))
                except ValueError:
                    pass
        # A few functionals override dens_threshold in their init() with a
        # computed value (e.g. gga_c_q2d: 2*DBL_MIN**(1/32)); that overrides
        # the struct default the build uses, so honour it here too.
        mo = re.search(r"p->dens_threshold\s*=\s*([^;]+);", text)
        if mo:
            try:
                val = float(eval(
                    mo.group(1).replace("DBL_MIN",
                                        repr(sys.float_info.min)),
                    {"__builtins__": {}}, {"pow": pow}))
            except Exception:
                pass
    _THRESHOLD_CACHE[name] = val
    return val


# --------------------------------------------------------------------------
# Helper inlining + my_piecewise lowering: same machinery as compile_module
# uses for kernel emission, factored out so numerical evaluation walks the
# same tree the C kernel would have walked.
# --------------------------------------------------------------------------

def _br89_x_mpmath(Q):
    """Becke-Roussel inverse: root of x*exp(-2x/3) = rhs*(x-2),
    rhs = (2/3)*pi^(2/3)/Q, on the same bracket libxc's get_x uses."""
    import mpmath
    Q = mpmath.mpf(Q)
    if abs(Q) < 2 * mpmath.mpf("2.220446049250313e-16"):
        return mpmath.mpf(2)
    rhs = (mpmath.mpf(2) / 3) * mpmath.pi ** (mpmath.mpf(2) / 3) / Q
    f = lambda x: x * mpmath.e ** (-2 * x / 3) - rhs * (x - 2)
    a, b = (mpmath.mpf(2), 1 / rhs + 2) if rhs > 0 else (mpmath.mpf(0),
                                                         mpmath.mpf(2))
    return mpmath.findroot(f, (a, b), solver="anderson")


def _mbrxc_x_mpmath(Q):
    """Modified Becke-Roussel inverse (mgga_x_mbrxc_bg): root of
    (1+x)^(5/3)*exp(-2x/3) = rhs*(x-3), rhs = (32*pi)^(2/3)/(6*Q)."""
    import mpmath
    Q = mpmath.mpf(Q)
    if abs(Q) < 2 * mpmath.mpf("2.220446049250313e-16"):
        return mpmath.mpf(3)
    rhs = (32 * mpmath.pi) ** (mpmath.mpf(2) / 3) / (6 * Q)
    f = lambda x: (1 + x) ** (mpmath.mpf(5) / 3) * mpmath.e ** (-2 * x / 3) \
        - rhs * (x - 3)
    a, b = (mpmath.mpf(3), 2 / rhs + 3) if rhs > 0 else (mpmath.mpf(0),
                                                         mpmath.mpf(3))
    return mpmath.findroot(f, (a, b), solver="anderson")


_ORIG_ENSURE_ORDER = None   # uncapped Helper.ensure_order, set by evaluate()


def _inline_helpers(expr, _cache=None):
    if _cache is None:
        _cache = {}
    if not isinstance(expr, sp.Basic) or expr.is_Atom:
        return expr
    # Memoize on the sub-expression: deep helper chains (op_f -> op_f_s ->
    # op_beta -> b88_zab, ...) reuse the same sub-trees in many places, and
    # without hash-consing each is re-inlined independently -> exponential
    # blowup (op_pw91 order-0 was > 150s). With the cache it is seconds.
    cached = _cache.get(expr)
    if cached is not None:
        return cached
    cls = expr.func
    if isinstance(expr, sp.Function) and hasattr(cls, "helper"):
        helper = cls.helper
        # ensure_order may be monkeypatched to cap the eager __init__ build at
        # the OUTPUT order; this on-demand call must still reach the order the
        # value itself needs (r2scan's alpha-interpolation references a helper
        # (1,0) derivative even for the order-0 output) -- use the uncapped
        # ensure if one was published.
        (_ORIG_ENSURE_ORDER or type(helper).ensure_order)(
            helper, sum(cls.multiindex))
        body = helper._derivs[cls.multiindex]
        sub = dict(zip(helper.args, expr.args))
        body = body.xreplace(sub)
        result = _inline_helpers(body, _cache)
    else:
        new_args = tuple(_inline_helpers(a, _cache) for a in expr.args)
        if any(na is not oa for na, oa in zip(new_args, expr.args)):
            result = expr.func(*new_args)
        else:
            result = expr
    _cache[expr] = result
    return result


def _lower_piecewise(expr, _cache=None):
    # Memoized like _inline_helpers: the inlined op-class trees share sub-trees
    # heavily, so without hash-consing the same nodes are re-lowered through
    # every parent path (exponential on op_pw91). With the cache it is seconds.
    if _cache is None:
        _cache = {}
    if not isinstance(expr, sp.Basic) or expr.is_Atom:
        return expr
    cached = _cache.get(expr)
    if cached is not None:
        return cached
    new_args = tuple(_lower_piecewise(a, _cache) for a in expr.args)
    f = expr.func
    if f is L.my_piecewise3:
        c, t, e = new_args
        # evaluate=False skips SymPy's per-construction condition
        # simplification, which on inlined op-class expressions
        # cascades through dozens of nested piecewise rewrites and
        # blows the construction time up by orders of magnitude. We
        # only need the structure (lambdify will discharge the
        # numerical branch at evaluation time).
        result = sp.Piecewise((t, c), (e, True), evaluate=False)
    elif f is L.my_piecewise5:
        c1, t1, c2, t2, e = new_args
        result = sp.Piecewise((t1, c1), (t2, c2), (e, True),
                              evaluate=False)
    elif any(na is not oa for na, oa in zip(new_args, expr.args)):
        result = f(*new_args)
    else:
        result = expr
    _cache[expr] = result
    return result


# --------------------------------------------------------------------------
# Build the kernel-level outputs (all mixed partials up to max_order).
# --------------------------------------------------------------------------

def _kernel_outputs(mod, spin, max_order):
    """Return ``(rho_syms, sigma_syms, lapl_syms, tau_syms, fields)``
    where ``fields`` is an ordered dict ``{name: [expr_per_combo]}``
    mirroring libxc's xc_*_out_params layout (zk + vrho + vsigma + ...
    for orders 0..max_order)."""
    family = mod.TYPE.split("_")[0]                  # lda / gga / mgga
    dim = L._detect_dimension(mod)
    inv_dim = sp.Rational(1, dim)
    exp_grad = sp.Integer(1) + inv_dim
    exp_kin = sp.Integer(1) + 2 * inv_dim
    saved = L._set_dimension(dim)
    try:
        return _build_outputs(mod, family, spin, max_order,
                              inv_dim, exp_grad, exp_kin)
    finally:
        L._restore_dimension(saved)


def _build_outputs(mod, family, spin, max_order,
                   inv_dim, exp_grad, exp_kin):
    if spin == 1:
        na = sp.Symbol("na", positive=True)
        rho_syms = [na]
        ntot = na
    else:
        na = sp.Symbol("na", positive=True)
        nb = sp.Symbol("nb", positive=True)
        rho_syms = [na, nb]
        ntot = na + nb

    sigma_syms = lapl_syms = tau_syms = []

    if family == "lda":
        if spin == 1:
            z_expr = sp.S.Zero
        else:
            z_expr = (na - nb) / ntot
        rs_expr = L.RS_FACTOR / ntot ** inv_dim
        f_expr = mod.f(rs_expr, z_expr)
    else:
        if spin == 1:
            gaa = sp.Symbol("gaa", positive=True)
            sigma_syms = [gaa]
        else:
            gaa = sp.Symbol("gaa", positive=True)
            gab = sp.Symbol("gab", real=True)
            gbb = sp.Symbol("gbb", positive=True)
            sigma_syms = [gaa, gab, gbb]
        rs_expr = L.RS_FACTOR / ntot ** inv_dim
        if spin == 1:
            z_expr = sp.S.Zero
            xt_expr = sp.sqrt(gaa) / na ** exp_grad
            xs0_expr = sp.sqrt(gaa / 4) / (na / 2) ** exp_grad
            xs1_expr = xs0_expr
        else:
            z_expr = (na - nb) / ntot
            xt_expr = (sp.sqrt(gaa + 2 * gab + gbb)
                       / ntot ** exp_grad)
            xs0_expr = sp.sqrt(gaa) / na ** exp_grad
            xs1_expr = sp.sqrt(gbb) / nb ** exp_grad
        if family == "gga":
            f_expr = mod.f(rs_expr, z_expr, xt_expr, xs0_expr, xs1_expr)
        else:                                        # mgga
            if spin == 1:
                la = sp.Symbol("la", real=True)
                ta = sp.Symbol("ta", positive=True)
                lapl_syms = [la]
                tau_syms = [ta]
                u0_expr = (la / 2) / (na / 2) ** exp_kin
                t0_expr = (ta / 2) / (na / 2) ** exp_kin
                u1_expr, t1_expr = u0_expr, t0_expr
            else:
                la = sp.Symbol("la", real=True)
                lb = sp.Symbol("lb", real=True)
                ta = sp.Symbol("ta", positive=True)
                tb = sp.Symbol("tb", positive=True)
                lapl_syms = [la, lb]
                tau_syms = [ta, tb]
                u0_expr = la / na ** exp_kin
                u1_expr = lb / nb ** exp_kin
                t0_expr = ta / na ** exp_kin
                t1_expr = tb / nb ** exp_kin
            f_expr = mod.f(rs_expr, z_expr, xt_expr, xs0_expr, xs1_expr,
                           u0_expr, u1_expr, t0_expr, t1_expr)

    # to_elementary lowers the xc_* / m_* primitives (xc_expm1, xc_log1p,
    # my_dilog, xc_erfcx, ...) to plain SymPy so lambdify('mpmath') can
    # evaluate them, and so their derivatives are taken in elementary form
    # rather than leaving an unknown function head behind.
    f_expr = _lower_piecewise(L.to_elementary(_inline_helpers(f_expr)))
    nf = ntot * f_expr

    # Build the per-family field table.
    groups = [rho_syms]
    if family != "lda":
        groups.append(sigma_syms)
    if family == "mgga":
        groups.extend([lapl_syms, tau_syms])

    if family == "lda":
        family_fields = L.LDA_FIELDS
    elif family == "gga":
        family_fields = L.GGA_FIELDS
    else:
        family_fields = L.MGGA_FIELDS

    fields = {}
    field_partials = {}
    for o in range(max_order + 1):
        if family == "lda":
            field_descs = [(L.LDA_FIELDS[o][0],) + (o,)]
        elif family == "gga":
            field_descs = [(f,) + (oR, oS)
                           for f, oR, oS in L.GGA_FIELDS[o]]
        else:
            field_descs = L.MGGA_FIELDS[o]
        for desc in field_descs:
            field_name = desc[0]
            counts = desc[1:]
            exprs = []
            partials = []
            for partial in _partials(counts, groups):
                expr = nf if o > 0 else f_expr
                for grp, idxs in zip(groups, partial):
                    for i in idxs:
                        expr = sp.diff(expr, grp[i])
                # A custom-fdiff Function reintroduces, into the derivative,
                # heads the order-0 lowering at f_expr could not have reached:
                # @helper bodies (br89_x -> br89_aux_dfdx) and xc_* special
                # functions (my_dilog's fdiff -> xc_log1p). Re-run the lowering
                # pipeline when any such head is present. The expensive part is
                # _inline_helpers (deep op_* chains), so gate it on an actual
                # un-inlined helper; to_elementary + _lower_piecewise are cheap
                # tree-walks and always safe to re-apply.
                if o > 0:
                    heads = expr.atoms(sp.Function)
                    if any(hasattr(type(a), "helper") for a in heads):
                        expr = _inline_helpers(expr)
                    if any(hasattr(type(a), "helper")
                           or type(a).__name__.startswith("xc_")
                           or type(a).__name__ == "my_dilog" for a in heads):
                        expr = _lower_piecewise(L.to_elementary(expr))
                exprs.append(expr)
                partials.append(partial)
            fields[field_name] = exprs
            field_partials[field_name] = partials
    return rho_syms, sigma_syms, lapl_syms, tau_syms, fields, field_partials


def _partials(counts, groups):
    """Yield every (rho-idx-tuple, sigma-idx-tuple, ...) combination of
    mixed partials whose per-group orders match `counts`."""
    per_group = [list(combinations_with_replacement(range(len(g)), c))
                 for g, c in zip(groups, counts)]
    # Cartesian product via nested loops
    out = [()]
    for col in per_group:
        out = [prev + (c,) for prev in out for c in col]
    yield from out


# work_mgga_inc.c clamps tau to a fixed floor (functionals.c default 1e-20)
# for XC_FLAGS_NEEDS_TAU; harmless to apply unconditionally since a
# tau-independent functional has zero tau derivatives anyway.
_TAU_THRESHOLD = 1e-20


def clamp_point(ip, rho, sigma, lapl, tau, n_rho, n_sigma, n_lapl, n_tau,
                spin, dens_threshold, s2thr, tau_threshold=_TAU_THRESHOLD):
    """Replicate work_*_inc.c input clamping for one grid point.

    Returns ``(screened, vals_rho, vals_sigma, vals_lapl, vals_tau,
    clamped)``. ``screened`` is True when the total density is below
    ``dens_threshold`` and the build leaves every output at its
    zero-initialised value. ``vals_*`` are the per-channel inputs after the
    m_max floors / off-diagonal-sigma clamp. ``clamped`` is the set of
    ``(group_idx, var_idx)`` pairs whose input sits on its floor -- the build
    clamps each such input, so d(output)/d(clamped input) is exactly 0 there
    (group order 0=rho, 1=sigma, 2=lapl, 3=tau). Both oracles (symbolic
    evaluate() below and ad_reference) go through this so they screen and
    clamp identically to the build.
    """
    screened = sum(rho[ip][j] for j in range(n_rho)) < dens_threshold
    vals_rho = [max(dens_threshold, rho[ip][j]) for j in range(n_rho)]
    vals_sigma = []
    if n_sigma:
        vals_sigma = [0.0] * n_sigma
        diag_idx = [j for j in range(n_sigma) if j != 1]
        for j in diag_idx:
            raw = sigma[ip][j] if sigma is not None else 0.0
            vals_sigma[j] = max(s2thr, raw)
        if spin == 2 and n_sigma == 3:
            s_ave = 0.5 * (vals_sigma[0] + vals_sigma[2])
            raw = sigma[ip][1] if sigma is not None else 0.0
            vals_sigma[1] = max(-s_ave, min(s_ave, raw))
    vals_lapl = [lapl[ip][j] if lapl is not None else 0.0
                 for j in range(n_lapl)]
    vals_tau = [max(tau_threshold, tau[ip][j]) if tau is not None else 0.0
                for j in range(n_tau)]
    # Derivatives are NOT zeroed. work_*_inc.c floors each input to its m_max
    # threshold and hands the FLOORED values to the kernel, then reports
    # d(f)/d(floored input) with no chain rule back through the m_max -- so the
    # build's floored-channel derivative is generally nonzero (gga_c_op_pw91 N
    # pt19 vrho_b = -283.6, where rho_b is floored to 1e-10 but still enters the
    # coupled (1-z^2)*n_total prefactor). Evaluating the (screened) functional
    # expression at the floored inputs reproduces this exactly: where the build
    # returns 0 it is because an internal my_piecewise3 screen makes that
    # channel's term a constant (e.g. separable exchange like mgga_x_r2scan,
    # whose screened down term differentiates to 0 on its own), not because the
    # build zeros the derivative wholesale. An empty `clamped` set is returned
    # for backward compatibility with callers that still unpack it.
    clamped = set()
    return screened, vals_rho, vals_sigma, vals_lapl, vals_tau, clamped


# --------------------------------------------------------------------------
# Public API
# --------------------------------------------------------------------------

def evaluate(name, spin, rho, sigma=None, lapl=None, tau=None,
             precision=50, max_order=2,
             dens_threshold=None, zeta_threshold=1e-15,
             module=None, param_overrides=None, cam=None):
    """Evaluate the functional ``name`` at the given grid points and
    return a ``{field: [[val_per_channel] per point]}`` dict with the
    values rounded from mpmath precision to Python float (double).

    If ``dens_threshold`` is ``None``, the per-functional default in
    ``src/<name>.c`` is used (matches what the C kernel sees once
    work_*_inc.c has clipped). ``max_order`` chooses the highest
    derivative order to emit; libxc supports up to 4 (lxc) but
    generation cost grows combinatorially.

    Performance note: per-output expressions are pre-substituted with
    the threshold / parameter / C-constant values and lambdified to
    mpmath. The compile cost runs once per output and then per-point
    evaluation is essentially a numeric function call -- two orders
    of magnitude faster than ``expr.subs(...).evalf(precision)`` on
    complex GGAs and mGGAs that have ~10k symbolic nodes after helper
    inlining."""
    import mpmath
    from sympy.utilities.lambdify import lambdify

    if dens_threshold is None:
        dens_threshold = _read_dens_threshold(name)

    # The @helper proxies build their Helper objects with a hardcoded
    # max_order=4. For order-4 derivatives along a deep helper chain
    # (e.g. op_b88's f -> op_f -> op_f_s -> op_beta -> b88_zab) the
    # eager ensure_order(4) call in Helper.__init__ takes 10-20s of
    # symbolic-diff work that test-reference generation does not need.
    # Cap it at the requested order for the duration of this call.
    import helper as _helper_mod
    global _ORIG_ENSURE_ORDER
    _orig_ensure_order = _helper_mod.Helper.ensure_order
    _ORIG_ENSURE_ORDER = _orig_ensure_order   # for _inline_helpers' on-demand

    def _capped_ensure_order(self, order):
        return _orig_ensure_order(self, min(order, max_order))
    _helper_mod.Helper.ensure_order = _capped_ensure_order
    try:
        # `module` lets a variant evaluate its base .py (gga_x_mpw91 has no
        # module of its own -- it is gga_x_pw91 with mpw91's parameters).
        mod = _import_functional(module or name, macro_name=name)
        for obj in list(vars(mod).values()):
            if getattr(obj, "_is_helper_proxy", False):
                obj._resolve()
        rho_syms, sigma_syms, lapl_syms, tau_syms, fields, field_partials = \
            _kernel_outputs(mod, spin, max_order)
    finally:
        _helper_mod.Helper.ensure_order = _orig_ensure_order

    threshold_subs = {
        _dens_thr_sym: sp.Float(dens_threshold, precision),
        _zeta_thr_sym: sp.Float(zeta_threshold, precision),
    }
    threshold_subs.update(_C_CONSTANTS)
    threshold_subs.update(_read_parameters(name, mod))
    # Range-separation coefficients (p_a_cam_omega/alpha/beta) for the
    # attenuated functionals, matching what the Maple oracle injects.
    if cam is not None:
        o, a, b = cam
        threshold_subs[_cam_omega_sym] = sp.Float(o, precision)
        threshold_subs[_cam_alpha_sym] = sp.Float(a, precision)
        threshold_subs[_cam_beta_sym] = sp.Float(b, precision)
    # Externally-resolved parameter values (the cross-check passes
    # maple_reference's fully-resolved params, covering init-hardcoded,
    # computed and variant params this module's ext_params block can't). A
    # scalar overrides the module's _Param symbol; a "[a, b, ...]" list
    # overrides the indexed array symbols params_a_<name>[i] (0-based, as
    # _Param.__getitem__ renders them).
    if param_overrides:
        for pname, pval in param_overrides.items():
            sval = pval.strip()
            if sval.startswith("["):
                for i, item in enumerate(sval[1:-1].split(",")):
                    try:
                        v = float(item)
                    except ValueError:
                        continue
                    key = sp.Symbol(f"{pname}[{i}]", real=True)
                    threshold_subs[key] = sp.Float(v, precision)
            else:
                try:
                    v = float(sval)
                except ValueError:
                    continue
                sym = getattr(mod, pname, None)
                key = (sym if isinstance(sym, sp.Symbol)
                       else sp.Symbol(pname, real=True))
                threshold_subs[key] = sp.Float(v, precision)

    arg_syms = (list(rho_syms) + list(sigma_syms)
                + list(lapl_syms) + list(tau_syms))

    # Compile each output to a numeric mpmath callable. The
    # threshold / param / C-constant substitutions happen at compile
    # time so the runtime call only takes the per-point arrays.
    # ``xreplace`` is used rather than ``subs`` because the substitutes
    # are bare symbol -> value (no algebraic simplification needed) and
    # xreplace is O(tree) versus subs's O(tree * #substitutes); the
    # difference is ~10x on the kernel-level expressions we evaluate.
    # to_elementary lowers a few primitives to special functions whose head
    # lambdify('mpmath') does not auto-map (xc_E1_scaled -> Ei(1,q), a 2-arg
    # generalized exponential integral = mpmath.expint; Bessel I/K). Supply
    # them explicitly so the callable resolves.
    _special = {
        "Ei": (lambda *a: mpmath.expint(*a) if len(a) == 2 else mpmath.ei(*a)),
        "BesselI": mpmath.besseli,
        "BesselK": mpmath.besselk,
        # my_dilog(q) = Li_2(q); some functionals (gg99) declare their own
        # my_dilog Function head that to_elementary's shared-object map misses.
        "my_dilog": (lambda z: mpmath.polylog(2, z)),
        # Becke-Roussel inverse: the C numerical root xc_mgga_x_br89_get_x,
        # solved here with mpmath on libxc's exact bracket (matches
        # maple_reference's fsolve proc).
        "br89_x": _br89_x_mpmath,
        "mbrxc_x": _mbrxc_x_mpmath,
    }
    compiled = {}
    for field, exprs in fields.items():
        compiled[field] = [
            lambdify(arg_syms, e.xreplace(threshold_subs),
                     modules=[_special, "mpmath"])
            for e in exprs]

    sig_thr = float(
        (sp.Float(dens_threshold, precision) ** sp.Rational(4, 3))
        .evalf(precision))
    s2thr = sig_thr * sig_thr
    tau_threshold = _TAU_THRESHOLD

    saved_dps = mpmath.mp.dps
    mpmath.mp.dps = precision

    def to_mpf(v):
        return mpmath.mpf(v)

    out = {field: [] for field in fields}
    try:
        for ip in range(len(rho)):
            (screened, vals_rho, vals_sigma, vals_lapl, vals_tau,
             clamped) = clamp_point(
                ip, rho, sigma, lapl, tau, len(rho_syms), len(sigma_syms),
                len(lapl_syms), len(tau_syms), spin, dens_threshold, s2thr,
                tau_threshold)
            if screened:
                # work_*_inc.c screens the whole point (dens < dens_threshold):
                # the kernel leaves every output at its zero-initialised value.
                for field in fields:
                    out[field].append([0.0] * len(compiled[field]))
                continue
            args = tuple(to_mpf(v)
                         for v in vals_rho + vals_sigma + vals_lapl
                         + vals_tau)
            for field in fields:
                point_vals = []
                for fn, partial in zip(compiled[field],
                                       field_partials[field]):
                    # Zero any derivative taken w.r.t. a clamped input.
                    if any((gi, vi) in clamped
                           for gi, idxs in enumerate(partial)
                           for vi in idxs):
                        point_vals.append(0.0)
                        continue
                    # Evaluate and convert under separate handlers: fn() can
                    # itself raise TypeError (an mpc reaching a relational in a
                    # lambdified Piecewise condition has no ordering), and a
                    # single handler around both used to fall through to the
                    # mpc-conversion path with `v` still bound to the PREVIOUS
                    # component's value -- appending the wrong number
                    # identically at every precision, invisible to convergence
                    # certification.
                    try:
                        v = fn(*args)
                    except (TypeError, ValueError, ZeroDivisionError):
                        point_vals.append(float("nan"))
                        continue
                    try:
                        point_vals.append(float(v))
                    except TypeError:
                        # polylog/Ei/erfcx return an mpc even for real arguments
                        # whose result is real (mpc rejects float() even with a
                        # zero imag part); take the real part when the imaginary
                        # part is negligible rather than failing to nan.
                        try:
                            re = mpmath.mpf(v.real)
                            im = abs(mpmath.mpf(v.imag))
                            point_vals.append(float(re)
                                              if im <= 1e-18 + 1e-12 * abs(re)
                                              else float("nan"))
                        except (TypeError, ValueError, AttributeError):
                            point_vals.append(float("nan"))
                    except (ValueError, ZeroDivisionError):
                        point_vals.append(float("nan"))
                out[field].append(point_vals)
    finally:
        mpmath.mp.dps = saved_dps
    return out


def evaluate_converged(name, spin, rho, sigma=None, lapl=None, tau=None,
                       max_order=2, base_precision=50,
                       check_precision=100, max_precision=400,
                       relative_tol=1e-14, absolute_tol=0.0,
                       dens_threshold=None, zeta_threshold=1e-15,
                       verbose=False):
    """Compute references at ``base_precision`` and ``check_precision``;
    where they disagree at the requested ``relative_tol`` (default
    1e-14, well below double precision), double the precision and
    retry until convergence or ``max_precision`` is exceeded.

    The ``relative_tol`` is the gap between successive-precision
    values, not the absolute precision of the result -- once two
    consecutive precisions agree at 1e-14 relative, further digits
    don't move the double-precision rounded value. Use a smaller tol
    if you want bit-identical doubles; the default is the right
    "ground truth" criterion for a libxc-style numerical comparison
    where the downstream test tolerance is ~5e-8 to 5e-5.

    Returns ``(refs, status)`` where ``refs`` is the converged values
    dict and ``status`` is a parallel dict marking each point/channel as
    ``"ok"`` (converged within tol) or the precision at which the
    check was last attempted (i.e. it never converged below
    max_precision -- the value in ``refs`` is then the highest-
    precision sample we got, still useful unless the disagreement is
    catastrophic). Tests should treat unconverged points as
    precision-sensitive and either skip them or relax their
    tolerance."""
    def call(prec):
        return evaluate(name, spin, rho, sigma=sigma, lapl=lapl, tau=tau,
                        precision=prec, max_order=max_order,
                        dens_threshold=dens_threshold,
                        zeta_threshold=zeta_threshold)

    def agree(a, b):
        if a != a or b != b:
            return a != a and b != b           # both NaN -> agree
        if a == b:
            return True
        # Mirror libxc's test denominator: 1 + max(|a|, |b|). Small
        # values (where +1 dominates) get an effectively-absolute
        # tolerance; large values (where max term dominates) get
        # relative. This is the natural "ground-truth" criterion for
        # comparing against a test downstream that uses the same
        # formula.
        scale = 1.0 + max(abs(a), abs(b))
        return abs(a - b) <= max(absolute_tol, relative_tol * scale)

    if verbose:
        print(f"  evaluate {name} at P={base_precision}...", flush=True)
    refs_lo = call(base_precision)
    if verbose:
        print(f"  evaluate {name} at P={check_precision}...", flush=True)
    refs_hi = call(check_precision)

    status = {f: [["ok"] * len(refs_lo[f][ip])
                  for ip in range(len(refs_lo[f]))]
              for f in refs_lo}

    def collect_disagreements(refs_a, refs_b):
        bad = []
        for f in refs_a:
            for ip in range(len(refs_a[f])):
                for k in range(len(refs_a[f][ip])):
                    if not agree(refs_a[f][ip][k], refs_b[f][ip][k]):
                        bad.append((f, ip, k))
        return bad

    bad = collect_disagreements(refs_lo, refs_hi)
    refs = refs_hi
    prec = check_precision
    while bad and prec * 2 <= max_precision:
        prec *= 2
        if verbose:
            print(f"  {len(bad)} disagreements at P={prec // 2}; "
                  f"re-checking at P={prec}", flush=True)
        refs_next = call(prec)
        bad = collect_disagreements(refs, refs_next)
        refs = refs_next
    for f, ip, k in bad:
        status[f][ip][k] = prec
    return refs, status


def _main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name", help="functional name, e.g. gga_c_cs1")
    ap.add_argument("--spin", type=int, default=2, choices=(1, 2))
    ap.add_argument("--system", default="H",
                    help="key from pylibxc.example_densities.test_data")
    ap.add_argument("--max-order", type=int, default=2,
                    help="highest derivative order (0=zk, 1=+vxc, 2=+fxc, "
                         "3=+kxc, 4=+lxc)")
    ap.add_argument("--precision", type=int, default=50,
                    help="single-precision evaluation (skip convergence)")
    ap.add_argument("--converge", action="store_true",
                    help="run the convergence-check workflow instead of "
                         "single-precision")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    from pylibxc.example_densities import test_data
    inp = test_data[args.system]
    # Restricted systems are stored flat (N,), unrestricted as (N,ncol).
    # Reshape to (N, nchannel) for the spin so evaluate() can index
    # rho[ip][channel] uniformly.
    ncol = ({"rho": 1, "sigma": 1, "lapl": 1, "tau": 1} if args.spin == 1
            else {"rho": 2, "sigma": 3, "lapl": 2, "tau": 2})
    kw = {"rho": inp["rho"].reshape(-1, ncol["rho"]).tolist()}
    for k in ("sigma", "lapl", "tau"):
        if k in inp:
            kw[k] = inp[k].reshape(-1, ncol[k]).tolist()

    if args.converge:
        refs, status = evaluate_converged(
            args.name, args.spin, max_order=args.max_order,
            verbose=args.verbose, **kw)
    else:
        refs = evaluate(args.name, args.spin, precision=args.precision,
                        max_order=args.max_order, **kw)
        status = None

    for field, points in refs.items():
        print(f"{field}:")
        for ip, vals in enumerate(points):
            line = "  ".join(f"{v: .9e}" if isinstance(v, float)
                             else repr(v) for v in vals)
            tag = ""
            if status is not None:
                bad = [k for k, s in enumerate(status[field][ip])
                       if s != "ok"]
                if bad:
                    tag = f"  [unconverged at: {bad}]"
            print(f"  [{ip}] {line}{tag}")


if __name__ == "__main__":
    _main()
