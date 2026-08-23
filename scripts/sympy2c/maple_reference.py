#!/usr/bin/env python3
"""Arbitrary-precision reference generator -- the Maple-native counterpart
of eval_reference.py.

The committed regression references in testsuite/regression are only
double-precision (they come from the compiled C build), so they cannot
serve as an arbitrary-precision authority. This tool evaluates the
canonical Maple sources (maple/<family>_exc/<name>.mpl) directly in
Maple's own arbitrary-precision arithmetic, mirroring the work_*.c
kernel reconstruction (rs, z, xt, xs, u, t from rho/sigma/lapl/tau) and
the libxc out-field layout, so its values are directly comparable to the
build and to eval_reference's mpmath truth.

It is an *independent* cross-check: eval_reference evaluates the SymPy
(python/) source, this evaluates the Maple (.mpl) source; agreement
between the two pins the value regardless of which codegen path produced
the build.

Requires Maple on PATH (or at /opt/maple<year>/bin/maple). Usage:

    python3 maple_reference.py mgga_x_mscan --system Li --spin 2 \
        --max-order 1 --digits 50

Derivative fields (vrho/vsigma/...) are Maple diff() of n_total*f w.r.t.
the libxc variables -- the same chain rule eval_reference applies.
"""

import argparse
import os
import re
import shutil
import subprocess
import sys
from itertools import combinations_with_replacement

_HERE = os.path.dirname(os.path.abspath(__file__))
_REPO = os.path.abspath(os.path.join(_HERE, "..", ".."))
_MAPLE_DIR = os.path.join(_REPO, "maple")
_SRC = os.path.join(_REPO, "src")

# Per-functional Maple lines injected after the .mpl include (see _build_driver)
# that REPLACE a slow-to-evaluate definition with an equivalent one -- same math,
# only cheaper for the oracle. gga_x_wpbeh windows two order-24 Taylor series
# (wpbeh_EG_poly, term2345_series) around s=0; my_piecewise3 is eager, so the
# .mpl re-expands them on every finite-difference evaluation. Expand each ONCE
# instead: the s-only wpbeh_EG series is a plain precomputed polynomial, and the
# w-dependent term2345 series is memoised per w value (`option remember`). Because
# standalone wpbeh is PBEh (omega=0), w = nu simplifies to 0 and the memoised
# series is computed a single time. Cuts order-2 generation from ~150 to ~35
# s/point. The definitions mirror the .mpl's exactly (k=0..22 drops the spurious
# ~1e-9/s^2 principal part; the piecewise/clamp collapse matches term2345_series).
_ORACLE_OVERRIDES = {
    "gga_x_wpbeh": [
        "_wpbeh_EGpoly := convert(eval(series(to_elementary(wpbeh_EG_orig(st)), "
        "st=0, 24), csgn=1), polynom):",
        "wpbeh_EG_poly := proc(s) local k; "
        "eval(add(coeff(_wpbeh_EGpoly, st, k)*st^k, k=0..22), st=s) end proc:",
        "_wpbeh_t2345 := proc(w) option remember; convert(series(eval("
        "term2345(w, ss), [my_piecewise3 = ((c,a,b)->b), m_min = ((a,b)->a), "
        "m_max = ((a,b)->a)]), ss=0, 24), polynom) end proc:",
        "term2345_series := proc(w, s) eval(_wpbeh_t2345(w), ss=s) end proc:",
    ],
}
if _HERE not in sys.path:
    sys.path.insert(0, _HERE)

# Reuse eval_reference's robust C-source parsing (params + thresholds).
import eval_reference as _er                                    # noqa: E402

_FAMILY_SUBDIRS = ("lda_exc", "gga_exc", "mgga_exc",
                   "lda_vxc", "gga_vxc", "mgga_vxc")

# libxc out-field layout per family/order: (field, per-group deriv counts).
# rho / sigma / lapl / tau groups; sizes depend on spin.
def _build_fields():
    """Per-family/order out-field layout {family: {order: [(field, per-group
    deriv-count tuple)]}} built from libxc_codegen's canonical field tables
    (the single source of truth, covering orders 0-4) rather than a local
    duplicate -- so the kxc/lxc field names and group distributions always
    match eval_reference / the build."""
    import libxc_codegen as L
    out = {"lda": {}, "gga": {}, "mgga": {}}
    for o in range(5):
        out["lda"][o] = [(n, (o,)) for n in L.LDA_FIELDS.get(o, [])]
        out["gga"][o] = [(n, (a, b)) for n, a, b in L.GGA_FIELDS.get(o, [])]
        out["mgga"][o] = [(n, (a, b, c, d))
                          for n, a, b, c, d in L.MGGA_FIELDS.get(o, [])]
    return out


# libxc out-field layout per family/order: (field, per-group deriv counts).
# rho / sigma / lapl / tau groups; sizes depend on spin.
_FIELDS = _build_fields()


def _find_mpl(name):
    for sub in _FAMILY_SUBDIRS:
        p = os.path.join(_MAPLE_DIR, sub, name + ".mpl")
        if os.path.exists(p):
            return sub.split("_")[0], p
    raise FileNotFoundError(f"no maple source for {name}")


def _resolve(name):
    """Map a (possibly variant) registered functional name to
    (base, c_path, reg_name):

      base     -- the base .mpl name (== the base src/*.c basename) whose
                  `f := ...` is evaluated;
      c_path   -- the src/*.c file that defines this functional's params;
      reg_name -- the registered name used to anchor the param/init lookup.

    For a directly-named functional all three coincide. Many functionals are
    only registered as variants of a shared base .mpl (gga_k_pbe2/3/4 live in
    gga_k_mpbe.c and use gga_k_mpbe.mpl; gga_k_pg1 in gga_k_pg.c) -- there the
    base comes from whichever src/*.c defines xc_func_info_<name>."""
    import glob
    self_c = os.path.join(_SRC, name + ".c")
    has_mpl = any(os.path.exists(os.path.join(_MAPLE_DIR, sub, name + ".mpl"))
                  for sub in _FAMILY_SUBDIRS)
    if has_mpl and os.path.exists(self_c):
        return name, self_c, name
    # Match the struct DEFINITION (not the extern decls / registry-array
    # references in the autogenerated funcs_*.c files).
    defn = re.compile(r"xc_func_info_type\s+xc_func_info_"
                      + re.escape(name) + r"\s*=")
    for cf in sorted(glob.glob(os.path.join(_SRC, "*.c"))):
        if os.path.basename(cf).startswith("funcs_"):
            continue
        try:
            text = open(cf).read()
        except OSError:
            continue
        if defn.search(text):
            return os.path.splitext(os.path.basename(cf))[0], cf, name
    return name, self_c, name


def _mpl_param_overrides(base):
    """Single-line `params_a_<x> := <value>` assignments made UNCONDITIONALLY
    (outside any $ifdef) at the top of the base .mpl. They express the
    functional's own intent and must be re-asserted AFTER its $includes:
    we $define every included functional's <inc>_params guard, so an
    included $ifdef block would otherwise clobber them -- e.g.
    hyb_mgga_x_dldf sets kappa/mu before $include gga_x_pbe, whose block
    then resets them to PBE's defaults. The value may be a util.mpl macro
    (mgga_x_m08: params_a_rpbe_mu := MU_GE), re-emitted verbatim."""
    def collect(name):
        try:
            _, path = _find_mpl(name)
        except FileNotFoundError:
            return {}
        out, depth = {}, 0
        for line in open(path):
            s = line.strip()
            if s.startswith(("$ifdef", "$ifndef")):
                depth += 1
                continue
            if s.startswith("$endif"):
                depth = max(0, depth - 1)
                continue
            if depth:
                continue
            # value may be a number or a util.mpl macro (MU_GE/KAPPA_PBE); take
            # the single-line RHS verbatim, but not a function definition (->).
            m = re.match(r"params_a_(\w+)\s*:=\s*([^:]+?)\s*:\s*$", s)
            if m and "->" not in m.group(2):
                out["params_a_" + m.group(1)] = m.group(2)
        return out

    # Collect from the included files too (m11 includes m08, whose rpbe_kappa/
    # rpbe_mu overrides would otherwise be clobbered by the deeper gga_x_rpbe
    # $ifdef block with nothing re-asserting them). The base wins on conflicts.
    result = {}
    for nm in sorted(_included(base)) + [base]:
        result.update(collect(nm))
    return result


def _included(name, seen=None):
    """Recursively collect the functionals a .mpl $includes (quoted or
    angle-bracket form), so their `$ifdef <X>_params` default blocks can be
    activated. Excludes util."""
    if seen is None:
        seen = set()
    try:
        _, path = _find_mpl(name)
    except FileNotFoundError:
        return seen
    for inc in re.findall(r'\$include\s+[<"](\w+)\.mpl[>"]', open(path).read()):
        if inc != "util" and inc not in seen:
            seen.add(inc)
            _included(inc, seen)
    return seen


def _integral_funcs(base):
    """Numerical-integration helpers (int1/int2/fd_int0/...) and their lower
    bounds, gathered from <base>.mpl and its includes. Each such helper has a
    ``diff/<name>`` derivative rule -- which IS the integrand, since
    diff(t,t)=1 -- and a ``replace: "<name>\\(" -> "xc_integrate(func, p, <LB>,``
    rule giving the lower bound. The .mpl gives the Maple oracle no *value* for
    these (only the diff rule), so without this they stay symbolic and evalf
    fails. Returns {name: lower_bound_str}."""
    out = {}
    for nm in dict.fromkeys([base] + sorted(_included(base))):
        try:
            _, path = _find_mpl(nm)
        except FileNotFoundError:
            continue
        txt = open(path).read()
        diffs = set(re.findall(r"`diff/(\w+)`\s*:=", txt))
        for m in re.finditer(
                r'replace:\s*"(\w+)\\?\(".*?xc_integrate\(\s*\w+\s*,'
                r'[^,]+,\s*([0-9.eE+-]+)', txt):
            if m.group(1) in diffs:
                out.setdefault(m.group(1), m.group(2))  # base's bound wins
    return out


def _maple_exe():
    exe = shutil.which("maple")
    if exe:
        return exe
    import glob
    cands = sorted(glob.glob("/opt/maple*/bin/maple"), reverse=True)
    if cands:
        return cands[0]
    raise FileNotFoundError("maple not found on PATH or /opt/maple*/bin")


def _brace_block(text, open_idx):
    """Return the contents of the {...} block whose opening brace is at
    text[open_idx]."""
    depth = 0
    for i in range(open_idx, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return text[open_idx + 1:i]
    return text[open_idx + 1:]


def _local_macros(text):
    """Macro env for resolving a functional's parameter defaults: util.h's
    numeric macros plus the file-LOCAL #defines (e.g. gga_k_dk's KINX/KINS,
    which are defined in terms of util.h's X2S). Iterates so locals defined
    via one another resolve."""
    env = dict(_er._macro_env())
    defs = [(n, re.split(r"/\*|//", v)[0].strip())
            for n, v in re.findall(r"#define\s+(\w+)\s+(.+)", text)]
    for _ in range(len(defs) + 1):
        progress = False
        for n, v in defs:
            if n in env or not v:
                continue
            try:
                env[n] = float(eval(v, {"__builtins__": {}}, env))
                progress = True
            except Exception:
                pass
        if not progress:
            break
    return env


def _eval_param(s, env):
    """Evaluate a C parameter initializer against the given macro env."""
    # collapse multi-line initializers (a trailing-operator line break is
    # legal C but a syntax error for Python's eval)
    s = re.sub(r"\s+", " ", s.strip())
    s = re.sub(r"(?<=[0-9.])L\b", "", s)
    if not s:
        return None
    try:
        return float(eval(s, {"__builtins__": {}}, env))
    except Exception:
        return None


def _init_params(name, text):
    """Parameters hard-coded in the C *_init function as `params->X = <val>;`
    (the common libxc pattern for non-ext_params functionals, e.g. mpbe).
    If the init switches on p->info->number, narrow to this functional's
    XC_<NAME> case."""
    out = {}
    env = _local_macros(text)
    # The init may not be named <name>_init -- functionals that share an init
    # reference it in the registry (e.g. gga_k_apbeint uses gga_k_apbe_init).
    init_name = name + "_init"
    if not re.search(r"\b" + re.escape(init_name) + r"\s*\(", text):
        anchor = re.search(r"xc_func_info_" + re.escape(name) + r"\b", text)
        tail = text[anchor.start():] if anchor else text
        rm = re.search(r"\b(\w+_init)\s*,", tail)
        if rm:
            init_name = rm.group(1)
    m = re.search(r"\b" + re.escape(init_name) + r"\s*\([^)]*\)\s*\{", text)
    if not m:
        return out
    body = _brace_block(text, m.end() - 1)
    enum = "XC_" + name.upper()
    cm = re.search(r"case\s+" + re.escape(enum) + r"\s*:(.*?)"
                   r"(?:\bbreak\b|\bcase\s+XC_|\bdefault\s*:)", body, re.S)
    scope = cm.group(1) if cm else body
    for am in re.finditer(r"params->(\w+)\s*=\s*([^;]+);", scope):
        v = _eval_param(am.group(2).strip(), env)
        if v is not None:
            out["params_a_" + am.group(1)] = repr(float(v))
    # Array params copied element-wise from a static table in a loop
    # (th3: `for(ii..) params->omega[ii] = omega_TH3[ii];`). Read the table
    # into a Maple list -- the .mpl indexes params_a_<field>[i].
    for am in re.finditer(
            r"params->(\w+)\s*\[\s*\w+\s*\]\s*=\s*(\w+)\s*\[\s*\w+\s*\]",
            scope):
        field, arr = am.group(1), am.group(2)
        ab = _er._read_c_array(text, arr)
        if ab is None:
            continue
        ab = re.sub(r"/\*.*?\*/", "", ab, flags=re.S)
        vals = [_eval_param(s, env) for s in ab.split(",") if s.strip()]
        if vals and None not in vals:
            out.setdefault("params_a_" + field, "[" + ", ".join(
                repr(float(v)) for v in vals) + "]")
    return out


def _cam_env(reg, spin):
    """{cam_omega, cam_alpha, cam_beta} the build resolves for reg, for use
    when a custom set_ext_params computes a struct field from them (s12h:
    bx = 1 - cam_alpha). Global hybrids report the exact-exchange fraction
    via get_hyb_exx_coef rather than _have_cam."""
    try:
        import pylibxc
        f = pylibxc.LibXCFunctional(reg, spin)
    except Exception:
        return {}
    if getattr(f, "_have_cam", False):
        try:
            o, a, b = f.get_cam_coef()
        except Exception:
            o, a, b = (getattr(f, "_cam_omega", 0.0),
                       getattr(f, "_cam_alpha", 0.0),
                       getattr(f, "_cam_beta", 0.0))
        return {"cam_omega": o, "cam_alpha": a, "cam_beta": b}
    try:
        return {"cam_omega": 0.0, "cam_alpha": float(f.get_hyb_exx_coef()),
                "cam_beta": 0.0}
    except Exception:
        return {}


def _computed_params(reg, text, cam=None, ext_override=None):
    """Params produced by a CUSTOM set_ext_params function that computes the
    struct fields from the ext-param inputs rather than copying them (e.g.
    gga_k_tflw's N_set_ext_params: gamma = 1 - 1.412/CBRT(N) from the
    electron-count input N; s12h's bx = 1 - cam_alpha). Replicates the
    pre-switch defaults plus this functional's `case XC_<REG>:` assignments,
    using the ext-param array's default values and (for cam-derived fields)
    the resolved cam coefficients. Returns {} for set_ext_params_cpy.

    ``ext_override`` ({ext_param_name: value}) supplies the ACTUAL ext-param
    INPUTS a mix imposed on this constituent, so the computed fields are derived
    from the imposed values (mpw91's alpha from the imposed bt) rather than the
    defaults."""
    import math
    anchor = re.search(r"xc_func_info_" + re.escape(reg) + r"\b", text)
    if not anchor:
        return {}
    blk = re.search(r"\{\s*[^,{}]+\s*,\s*(\w+)\s*,\s*\w+\s*,\s*(\w+)\s*,\s*(\w*set_ext_params\w*)\s*\}",
                    text[anchor.start():])
    if not blk:
        return {}
    values_arr, setter = blk.group(2), blk.group(3)
    if setter.endswith("set_ext_params_cpy"):
        return {}
    fm = re.search(r"\b" + re.escape(setter) + r"\s*\([^)]*\)\s*\{", text)
    if not fm:
        return {}
    body = _brace_block(text, fm.end() - 1)
    env = dict(_local_macros(text))
    env.update({"CBRT": lambda x: math.copysign(abs(x) ** (1.0 / 3.0), x),
                "cbrt": lambda x: math.copysign(abs(x) ** (1.0 / 3.0), x),
                "pow": pow, "sqrt": math.sqrt, "log": math.log,
                "exp": math.exp, "M_PI": math.pi, "M_E": math.e})
    # ext-param inputs: NAME = get_ext_param(p, ext_params, idx). The imposed
    # ext_override (matched to the ext-param name at that index) wins over the
    # C default, so computed fields derive from what the mix actually set.
    dv = _er._read_c_array(text, values_arr)
    dvals = [_eval_param(s, env) for s in dv.split(",")] if dv else []
    nb = _er._read_c_array(text, blk.group(1))
    enames = [s.strip().strip('"').lstrip("_")
              for s in nb.split(",")] if nb else []
    def _gep(idx):
        """Value of ext-param index idx: the imposed override (matched by name)
        wins over the C default array."""
        if ext_override and idx < len(enames) and enames[idx] in ext_override:
            return float(ext_override[enames[idx]])
        if idx < len(dvals) and dvals[idx] is not None:
            return dvals[idx]
        return None

    for vm in re.finditer(
            r"(\w+)\s*=\s*get_ext_param\s*\([^;]*?,\s*(\d+)\s*\)", body):
        val = _gep(int(vm.group(2)))
        if val is not None:
            env[vm.group(1)] = val
    # file-local scalar consts declared-and-initialised (double C0 = ...)
    for lm in re.finditer(r"\bdouble\s+(\w+)\s*=\s*([^;]+);", body):
        v = _eval_param(lm.group(2), env)
        if v is not None:
            env[lm.group(1)] = v
    # M_CBRT2 and friends: libxc-global math macros a setter may use
    # (pbe_lambda's params->kappa = lambda/M_CBRT2 - 1) that _local_macros
    # cannot see because they are not defined in this .c file.
    env.setdefault("M_CBRT2", 2.0 ** (1.0 / 3.0))
    env.setdefault("M_SQRT2", 2.0 ** 0.5)
    # local scalars declared without an initialiser (mpw91: `double bt, beta;`
    # then `beta = 5.0*pow(...)`; pbe_lambda: `double lambda, N;`).
    locals_decl = set()
    for dm in re.finditer(r"\bdouble\s+([\w,\s]+);", body):
        for nm in dm.group(1).split(","):
            nm = nm.strip()
            if nm and "[" not in nm:
                locals_decl.add(nm)
    # A C local can be spelled as a Python keyword (pbe_lambda: `double lambda`),
    # which would make _eval_param's eval() choke; alias those to a safe name in
    # both the env and the expressions that read them.
    import keyword as _kw
    _mangle = {nm: nm + "_loc" for nm in locals_decl if _kw.iskeyword(nm)}
    # pre-switch defaults, then this functional's case (which overrides them)
    sw = body.find("switch")
    pre = body[:sw] if sw >= 0 else body
    cm = re.search(r"case\s+XC_" + reg.upper() + r"\s*:(.*?)"
                   r"(?:\bbreak\b|\bcase\s+XC_|\}\s*$)", body, re.S)
    scope = pre + (cm.group(1) if cm else "")
    cam = cam or {}
    pvals = {}
    # A setter that first COPIES the ext-params (set_ext_params_cpy) and then
    # tweaks a field in place (lspbe: mu += alpha*(1+kappa)) needs each struct
    # field seeded with its ext-param default, so the compound assignment starts
    # from the copied value rather than 0. Struct field name == ext-param name.
    if re.search(r"\bset_ext_params_cpy\s*\(", body):
        for _nm, _dv in zip(enames, dvals):
            if _nm and _dv is not None:
                env.setdefault(_nm, _dv)
                pvals.setdefault(_nm, _dv)

    def _subst(expr):
        # inline get_ext_param(p, ext_params, idx) reads (lda_c_xalpha:
        # params->alpha = 1.5*get_ext_param(...,0) - 1.0), honouring any imposed
        # override; range-separation p->cam_*; and params->field back-references
        # (pbe_lambda's local lambda reads params->lambda already assigned above)
        # -- from pvals, else the bare field name captured in env.
        expr = re.sub(r"get_ext_param\s*\([^;]*?,\s*(\d+)\s*\)",
                      lambda g: repr(_gep(int(g.group(1)))
                                     if _gep(int(g.group(1))) is not None
                                     else 0.0), expr)
        expr = re.sub(r"\bp->(cam_\w+)",
                      lambda g: repr(cam.get(g.group(1), 0.0)), expr)
        expr = re.sub(r"params->\s*(\w+)",
                      lambda g: repr(pvals.get(g.group(1),
                                               env.get(g.group(1), 0.0))), expr)
        for _nm, _alias in _mangle.items():
            expr = re.sub(r"\b" + _nm + r"\b", _alias, expr)
        return expr

    # Single source-ordered pass over both params->field assignments and local
    # scalar assignments, so an interleaved setter resolves (pbe_lambda:
    # params->lambda = ext; lambda = f(params->lambda, N); params->kappa =
    # g(lambda)). A local feeds later fields; a field is recorded in pvals AND
    # env so a subsequent statement can read it back.
    for am in re.finditer(
            r"(?:params->\s*(\w+)|(?<![>\w.])(\w+))\s*([-+*/]?=)\s*([^;=]+);", scope):
        fld, loc, op = am.group(1), am.group(2), am.group(3)
        if loc is not None and loc not in locals_decl:
            continue                              # not a tracked local; skip
        v = _eval_param(_subst(am.group(4)), env)
        if v is None:
            continue
        key = fld or loc
        if op != "=":                             # compound X op= rhs
            cur = (pvals.get(fld) if fld is not None
                   else env.get(_mangle.get(key, key)))
            if cur is None:
                cur = env.get(key)
            if cur is None:
                continue
            v = {"+=": cur + v, "-=": cur - v,
                 "*=": cur * v, "/=": cur / v}[op]
        if fld is not None:
            pvals[fld] = v
        env[_mangle.get(key, key)] = v
    return {"params_a_" + k: repr(v) for k, v in pvals.items()}


def _struct_fields(name, text):
    """Field names (and array sizes) of the C `<name>_params` struct, in
    declaration order. These are what the .mpl refers to (params_a_<field>),
    which can differ from the user-facing ext_params *names* array -- e.g.
    gga_k_pg's struct field is pg_mu but its ext_params name is just 'mu'."""
    m = re.search(r"typedef\s+struct\s*\{(.*?)\}\s*" + re.escape(name)
                  + r"_params\s*;", text, re.S)
    if not m:
        # The struct typedef name need not match the base .mpl name (wb97's
        # .mpl is hyb_gga_xc_wb97 but its struct is gga_xc_wb97_params;
        # wb97mv -> hyb_mgga_xc_wb97_mv_params). Fall back to the sole
        # *_params typedef in the file.
        structs = re.findall(r"typedef\s+struct\s*\{(.*?)\}\s*\w+_params\s*;",
                             text, re.S)
        if len(structs) != 1:
            return None
        m = re.match(r"(.*)", structs[0], re.S)
    fields = []
    for fm in re.finditer(r"(?:double|float|int|FLOAT)\s+([\w,\s\[\]]+?)\s*;",
                          m.group(1)):
        for decl in fm.group(1).split(","):
            dm = re.match(r"(\w+)\s*(?:\[(\d+)\])?\s*(?:\[(\d+)\])?$",
                          decl.strip())
            if not dm:
                continue
            if dm.group(3):                       # 2D: name[rows][cols]
                fields.append((dm.group(1),
                               (int(dm.group(2)), int(dm.group(3)))))
            else:
                fields.append((dm.group(1),
                               int(dm.group(2)) if dm.group(2) else 1))
    return fields


def _params(name, c_path=None, base=None, spin=2, ext_override=None):
    """{maple_name: value_string} for functional `name`. Sources, in order:
    the set_ext_params defaults (reusing eval_reference's <prefix>_values /
    par_<name> parsing), then the C *_init hard-coded `params->X = <val>`
    defaults (for functionals without ext_params). Array params split into
    flat scalars are assembled into Maple lists last.

    `c_path` is the src/*.c file to read (defaults to src/<name>.c); `base`
    is the base struct/.mpl name (defaults to `name`). They differ for a
    variant sharing a base .mpl -- the ext_params block is anchored on the
    registered `name` (xc_func_info_<name>) but the struct typedef uses
    `base` (gga_k_mpbe_params for gga_k_pbe2).

    `ext_override` is {ext_param_name: value} of the ACTUAL ext-params a
    functional was instantiated with (a mix reparametrises a constituent, e.g.
    edf1 uses gga_x_b88 twice with different beta). When given, those values
    replace the C defaults, so both the ext-name symbol (params_a_beta) and the
    struct-field symbol it aliases get the imposed value."""
    fname = c_path or os.path.join(_SRC, name + ".c")
    base = base or name
    out = {}
    if not os.path.exists(fname):
        return out
    text = open(fname).read()
    env = _local_macros(text)
    anchor = re.search(r"xc_func_info_" + re.escape(name) + r"\b", text)
    tail = text[anchor.start():] if anchor else text
    # 5th field is the setter; accept a prefixed name (cam_s12's
    # s12h_set_ext_params, which is still a standard cpy-cam copy setter).
    block = re.search(
        r"\{\s*[^,{}]+\s*,\s*(\w+)\s*,\s*\w+\s*,\s*(\w+)\s*,\s*\w*set_ext_params",
        tail)
    if block:
        nb = _er._read_c_array(text, block.group(1))
        vb = _er._read_c_array(text, block.group(2))
        if nb is not None and vb is not None:
            # strip C comments embedded in the array bodies: /* ... */ blocks
            # (par_n12_sx's leading note) and // line comments (par_cf22d's
            # per-group `// a000-a005` labels) that would otherwise glue onto
            # an adjacent value and make it unparseable
            nb = re.sub(r"/\*.*?\*/", "", nb, flags=re.S)
            vb = re.sub(r"/\*.*?\*/", "", vb, flags=re.S)
            nb = re.sub(r"//[^\n]*", "", nb)
            vb = re.sub(r"//[^\n]*", "", vb)
            names = [s.strip().strip('"').lstrip("_")
                     for s in nb.split(",") if s.strip()]
            vals = [_eval_param(s, env) for s in vb.split(",")]
            if ext_override:
                # replace the C defaults with the imposed values (matched on the
                # ext-param name); everything below maps these onto the symbols
                vals = [float(ext_override[n]) if n in ext_override else v
                        for n, v in zip(names, vals)]
            for n, v in zip(names, vals):
                if v is not None:
                    out["params_a_" + n] = repr(float(v))
            # Also map the values onto the struct FIELD names (what the .mpl
            # uses), array-aware -- handles ext_params names that differ from
            # the struct fields (gga_k_pg: 'mu' vs pg_mu) and array fields.
            fields = _struct_fields(base, text)
            if fields:
                i = 0
                for fld, sz in fields:
                    if isinstance(sz, tuple):     # 2D: CC[4][4] -> per-row list
                        rows, cols = sz
                        chunk = vals[i:i + rows * cols]
                        i += rows * cols
                        if len(chunk) == rows * cols and None not in chunk:
                            # the .mpl indexes 2D params row-by-row as
                            # params_a_<fld>_<r>_[col] (1-based Maple list)
                            for r in range(rows):
                                row = chunk[r * cols:(r + 1) * cols]
                                out.setdefault(
                                    f"params_a_{fld}_{r}_", "[" + ", ".join(
                                        repr(float(c)) for c in row) + "]")
                        continue
                    chunk = vals[i:i + sz]
                    i += sz
                    if sz == 1 and chunk and chunk[0] is not None:
                        out.setdefault("params_a_" + fld, repr(float(chunk[0])))
                    elif sz > 1 and len(chunk) == sz and None not in chunk:
                        out.setdefault("params_a_" + fld, "[" + ", ".join(
                            repr(float(c)) for c in chunk) + "]")
    # Fill in any params hard-coded in the *_init (don't override ext_params).
    for k, v in _init_params(name, text).items():
        out.setdefault(k, v)
    # Params produced by a custom set_ext_params that computes (not copies)
    # the struct fields from the ext-param inputs (gga_k_tflw's absp/gr/...,
    # s12h's bx = 1 - cam_alpha). These OVERRIDE the contiguous struct mapping
    # above, which would otherwise mis-assign a computed field (s12h: the 6th
    # ext-param 'alpha' wrongly lands on the struct's bx slot).
    for k, v in _computed_params(name, text, _cam_env(name, spin),
                                 ext_override).items():
        out[k] = v
    # Some functionals split an array parameter into flat ext_params scalars
    # (e.g. TPSS's C0_c -> C0_c0,C0_c1,C0_c2,C0_c3) but the .mpl uses it as a
    # Maple list `params_a_C0_c` (indexed cc[i]). When the functional has no
    # $ifdef block to assemble it, build the list here from a base whose
    # suffixes are contiguous from 0.
    # Only assemble params_a_<X> when <X> is an actual struct field (TPSS's
    # C0_c). Otherwise the suffixed ext-param NAMES (sogga11's a0..a5, whose
    # real struct field is the prefixed sogga11_a already built above) would
    # synthesize a bare params_a_a that COLLIDES with a param an included
    # functional legitimately uses (lda_c_pw's params_a_a PW92 coefficient),
    # silently corrupting it.
    sfields = _struct_fields(base, text)
    field_names = {f for f, _ in sfields} if sfields else None
    import collections
    grp = collections.defaultdict(dict)
    for k, v in list(out.items()):
        m = re.match(r"(params_a_.+?)(\d+)$", k)
        if m:
            grp[m.group(1)][int(m.group(2))] = v
    for asm, idxv in grp.items():
        if field_names is not None and asm[len("params_a_"):] not in field_names:
            continue
        idxs = sorted(idxv)
        if len(idxs) >= 2 and idxs == list(range(len(idxs))):
            out[asm] = "[" + ", ".join(idxv[i] for i in idxs) + "]"
    return out


def _groups(spin):
    if spin == 1:
        return [["na"], ["gaa"], ["la"], ["ta"]]
    return [["na", "nb"], ["gaa", "gab", "gbb"], ["la", "lb"], ["ta", "tb"]]


def _components(counts, groups):
    """Every mixed-partial component (list of maple var names to diff by)
    for a field with the given per-group derivative counts -- the libxc
    component order (combinations_with_replacement per group)."""
    per = [list(combinations_with_replacement(range(len(g)), c))
           for g, c in zip(groups, counts)]
    combos = [()]
    for col in per:
        combos = [prev + (c,) for prev in combos for c in col]
    out = []
    for combo in combos:
        vars_ = []
        for grp, idxs in zip(groups, combo):
            vars_ += [grp[i] for i in idxs]
        out.append(vars_)
    return out


_PRIMITIVE_LAYER = r"""
xc_expm1 := x -> exp(x) - 1:
xc_log1p := x -> ln(1 + x):
xc_asinh := x -> arcsinh(x):
xc_atanh := x -> arctanh(x):
xc_erfcx := x -> exp(x^2)*erfc(x):
xc_x_minus_log1p := x -> x - ln(1 + x):
xc_E1_scaled := z -> exp(z)*Ei(1, z):
my_dilog := x -> dilog(1 - x):
my_piecewise3 := (c,a,b) -> piecewise(c, a, b):
my_piecewise5 := (c1,a1,c2,a2,b) -> piecewise(c1, a1, c2, a2, b):
m_min := (a,b) -> min(a,b):
m_max := (a,b) -> max(a,b):
m_abs := x -> abs(x):
# Becke-Roussel inverse: solve x*exp(-2x/3) = rhs*(x-2),
# rhs = (2/3)*Pi^(2/3)/Q, on the same bracket libxc's get_x uses.
# (mgga_x_br89 et al. call br89_x, which codegen maps to the C solver.)
br89_x := proc(QQ) local rhs, x1, x2, q;
  q := evalf(QQ);
  if not type(q, numeric) then return 'br89_x'(QQ) end if;
  if abs(q) < 2*XC_EPSILON then return 2.0 end if;
  rhs := evalf((2/3)*Pi^(2/3)/q);
  if rhs > 0 then x1 := 2.0; x2 := 1.0/rhs + 2.0 else x1 := 0.0; x2 := 2.0 end if;
  fsolve(x*exp(-2*x/3) - rhs*(x - 2.0), x = x1 .. x2)
end proc:
# Modified Becke-Roussel inverse (mgga_x_mbrxc_bg): (1+x)^(5/3)*exp(-2x/3)
# = rhs*(x-3), rhs = (32*Pi)^(2/3)/(6*Q).
mbrxc_x := proc(QQ) local rhs, x1, x2, q;
  q := evalf(QQ);
  if not type(q, numeric) then return 'mbrxc_x'(QQ) end if;
  if abs(q) < 2*XC_EPSILON then return 3.0 end if;
  rhs := evalf((32*Pi)^(2/3)/(6*q));
  if rhs > 0 then x1 := 3.0; x2 := 2.0/rhs + 3.0 else x1 := 0.0; x2 := 3.0 end if;
  fsolve((1+x)^(5/3)*exp(-2*x/3) - rhs*(x - 3.0), x = x1 .. x2)
end proc:
"""


def _build_driver(base, reg, family, spin, max_order, digits, dens_thr,
                  zeta_thr, params, points, dim, fd, cam=None):
    groups = _groups(spin)
    L = ["Digits := %d:" % digits, "interface(warnlevel=0):",
         _PRIMITIVE_LAYER.strip(),
         "p_a_zeta_threshold := %r:" % zeta_thr,
         "p_a_dens_threshold := %r:" % dens_thr,
         "XC_EPSILON := 0.22204460492503131e-15:"]
    if cam is not None:
        omega, alpha, beta = cam
        L += ["p_a_cam_omega := %r:" % float(omega),
              "p_a_cam_alpha := %r:" % float(alpha),
              "p_a_cam_beta := %r:" % float(beta)]
    # Scalar params before the include (so an $ifdef block can override them
    # and we re-assert afterwards). LIST params are assigned only AFTER the
    # include: a list assigned up front makes an included file's higher-index
    # access (e.g. gas22's c_os[5] vs the included wb97mv referencing c_os[6],
    # which it then overrides) an out-of-range error -- at codegen time those
    # indices stay symbolic, so we defer to mimic that.
    for k, v in params.items():
        if "[" not in k and not v.lstrip().startswith("["):
            L.append(f"{k} := {v}:")
    L.append('$include <util.mpl>')
    # Activate the default-parameter blocks. 16 functionals (lda_c_pw,
    # gga_c_pbe, ...) define their defaults -- often as 1-indexed Maple lists --
    # inside a `$ifdef <name>_params` guard; $define-ing it lets the .mpl set
    # them correctly (the scalar ext_params emitted above can't express the
    # array-valued ones). This must cover not just the top functional but
    # everything it $includes -- e.g. mgga_c_tpss includes gga_c_pbe but does
    # not $define gga_c_pbe_params itself, so PBE's beta would stay symbolic and
    # f non-numeric. No-op for functionals without such a block (e.g. mscan).
    for nm in dict.fromkeys([base, reg] + sorted(_included(base))):
        L.append(f'$define {nm}_params')
    L.append(f'$include <{base}.mpl>')

    # Re-assert this functional's own scalar params AFTER the includes so they
    # override an included base's block defaults -- e.g. gga_c_zpbeint sets
    # beta=0.052 but $include gga_c_pbe would otherwise reset beta to PBE's
    # 0.0667. Only plain scalars: the array-list params (and [N]-indexed forms)
    # are owned by the .mpl blocks and must not be clobbered here.
    for k, v in params.items():
        if "[" not in k and not v.lstrip().startswith("["):
            L.append(f"{k} := {v}:")
    # Likewise re-assert the base .mpl's OWN unconditional params_a_X literals
    # (e.g. hyb_mgga_x_dldf's kappa/mu set before $include gga_x_pbe), which an
    # included $ifdef block would otherwise clobber.
    for k, v in _mpl_param_overrides(base).items():
        L.append(f"{k} := {v}:")
    # LIST params (Maple lists) assigned after the include -- see the
    # scalar-vs-list note above. These are the ext_params arrays the .mpl
    # indexes as params_a_<x>[i]; assigning them now (when the included
    # files' symbolic higher-index uses have already been overridden) is
    # both correct and avoids out-of-range during the include.
    for k, v in params.items():
        if v.lstrip().startswith("["):
            L.append(f"{k} := {v}:")

    # Precompute-once overrides for slow series windows (see _ORACLE_OVERRIDES).
    for line in _ORACLE_OVERRIDES.get(base, []):
        L.append(line)

    # Numerical-integration helpers (xc_integrate): the .mpl gives these only a
    # `diff/<name>` derivative rule (consumed by codegen), with no value -- so
    # evalf(int1(b)) stays symbolic and fprintf fails. Define them here, after
    # the include (so the diff rule and its integrand, e.g. x1d_inter, are
    # bound), as the numerical integral of the integrand `diff/<name>`(t,t)
    # (= integrand(t), since diff(t,t)=1) from the replace-rule lower bound.
    for nm, lb in _integral_funcs(base).items():
        L.append(f"{nm} := proc(bb) local tt; "
                 f"evalf(Int(`diff/{nm}`(tt, tt), tt = {lb} .. bb)) end proc:")

    # Re-assert the functional's true dimension AFTER its includes: some
    # functionals (e.g. gga_c_q2d) $include a 2D piece and toggle
    # xc_dimensions_2d, which can leave RS_FACTOR/DIMENSIONS/LDA_X_FACTOR
    # at the wrong dimension. util.mpl helpers read these globals at call
    # time, so re-asserting here fixes the reconstruction. (X_FACTOR_C /
    # X_FACTOR_2D_C are util.mpl constants.)
    if dim == 1:
        # util.mpl's 1D block sets only DIMENSIONS/RS_FACTOR (no LDA_X_FACTOR).
        L += ["DIMENSIONS := 1:", "RS_FACTOR := 1/2:"]
        inv, eg, ek = "1", "2", "3"
    elif dim == 2:
        L += ["DIMENSIONS := 2:", "RS_FACTOR := 1/sqrt(Pi):",
              "LDA_X_FACTOR := -X_FACTOR_2D_C:"]
        inv, eg, ek = "1/2", "3/2", "2"
    else:
        L += ["DIMENSIONS := 3:", "RS_FACTOR := (3/(4*Pi))^(1/3):",
              "LDA_X_FACTOR := -X_FACTOR_C:"]
        inv, eg, ek = "1/3", "4/3", "5/3"

    # raw-variable kernel reconstruction, mirroring work_*.c
    if spin == 1:
        L += ["ntot := na:", "zz := 0:",
              f"rs := RS_FACTOR/ntot^({inv}):"]
        if family != "lda":
            L += [f"xt := sqrt(gaa)/na^({eg}):",
                  f"xs0 := sqrt(gaa/4)/(na/2)^({eg}):", "xs1 := xs0:"]
        if family == "mgga":
            L += [f"u0 := (la/2)/(na/2)^({ek}):", "u1 := u0:",
                  f"t0 := (ta/2)/(na/2)^({ek}):", "t1 := t0:"]
    else:
        L += ["ntot := na+nb:", "zz := (na-nb)/ntot:",
              f"rs := RS_FACTOR/ntot^({inv}):"]
        if family != "lda":
            L += [f"xt := sqrt(gaa+2*gab+gbb)/ntot^({eg}):",
                  f"xs0 := sqrt(gaa)/na^({eg}):",
                  f"xs1 := sqrt(gbb)/nb^({eg}):"]
        if family == "mgga":
            L += [f"u0 := la/na^({ek}):", f"u1 := lb/nb^({ek}):",
                  f"t0 := ta/na^({ek}):", f"t1 := tb/nb^({ek}):"]
    call = {"lda": "f(rs,zz)",
            "gga": "f(rs,zz,xt,xs0,xs1)",
            "mgga": "f(rs,zz,xt,xs0,xs1,u0,u1,t0,t1)"}[family]
    L.append(f"zk := {call}:")
    L.append(f"nf := ntot*({call}):")

    allvars = sum(groups, [])
    field_layout = [(field, _components(counts, groups))
                    for o in range(max_order + 1)
                    for field, counts in _FIELDS[family][o]]

    if fd:
        # Finite-difference derivatives of the energy density nf = n_total*f
        # w.r.t. the raw libxc variables. Central differences capture the full
        # chain rule (rs/z/xt/xs/u/t all depend on the densities) and avoid
        # Maple's slow symbolic diff (which times out on the SCAN/r2SCAN class).
        # A relative step of 1e-20 with Digits>=40 leaves ~20+ accurate digits
        # in E(+h)-E(-h), far beyond the 5e-8 comparison threshold.
        _emit_fd(L, field_layout, points, allvars, digits)
        return "\n".join(L) + "\n", None

    # symbolic field-component expressions, in libxc order
    eid = 0
    comp_exprs = []
    for field, comps in field_layout:
        for comp in comps:
            eid += 1
            base = "nf" if comp else "zk"
            if comp:
                L.append(f"e{eid} := diff({base}, {', '.join(comp)}):")
            else:
                L.append(f"e{eid} := {base}:")
            comp_exprs.append((field, eid))
    for ip, vals in enumerate(points):
        sub = ", ".join(f"{v}={vals[v]!r}" for v in allvars if v in vals)
        for field, eid in comp_exprs:
            L.append(
                f'printf("R %d %s %d %%.18e\\n", '
                f'evalf(subs({sub}, e{eid}))):' % (ip, field, eid))
    return "\n".join(L) + "\n", comp_exprs


# Minimal symmetric central-difference stencils for the n-th derivative:
# {n: (offsets, coeffs, denom)} -> d^n f/dx^n ~ sum(coeffs[j]*f(x+offset[j]*h))
# / (denom * h^n). A mixed partial is the tensor product of these per variable.
_CENTRAL = {
    1: ([1, -1], [1, -1], 2),
    2: ([1, 0, -1], [1, -2, 1], 1),
    3: ([2, 1, -1, -2], [1, -2, 2, -1], 2),
    4: ([2, 1, 0, -1, -2], [1, -4, 6, -4, 1], 1),
}


def _emit_fd(L, field_layout, points, allvars, digits=50):
    """Emit per-point central-difference stencils for each field component, to
    arbitrary order: a component is a multi-index of raw variables, grouped by
    variable into per-variable derivative orders, and the stencil is the tensor
    product of the 1-D central differences (_CENTRAL).

    The perturbations base+j*h are Maple expression strings so the step is
    added at Maple's working precision. The relative step is order-aware:
    10^(-digits/(n+2)) balances the O(h^2) truncation against the O(eps/h^n)
    roundoff of the 1/h^n stencil (a fixed 1e-20 underflows at order >= 3)."""
    import itertools
    from collections import Counter
    for ip, vals in enumerate(points):
        base = {v: vals[v] for v in allvars if v in vals}

        def hval(w, n):
            rel = 10.0 ** (-digits / (n + 2.0))
            a = abs(base[w])
            return repr(a * rel if a > 0 else rel)

        def pert(w, offset, h):                  # Maple expr 'base + offset*h'
            return f"({base[w]!r}+({offset})*{h})"

        def at(over):                            # over: {var: maple_expr_str}
            parts = [f"{k}={over.get(k, repr(base[k]))}" for k in base]
            # eval (not bare subs) so any numerically-resolvable procedure
            # frozen during the symbolic nf build -- e.g. br89_x, which holds
            # itself unevaluated for symbolic args -- re-fires once subs makes
            # its argument numeric.
            return "eval(subs(" + ", ".join(parts) + ", nf))"

        for field, comps in field_layout:
            for comp in comps:
                if not comp:                                  # zk
                    sub = ", ".join(f"{k}={v!r}" for k, v in base.items())
                    expr = f"evalf(eval(subs({sub}, zk)))"
                else:
                    # group the multi-index into per-variable orders and form
                    # the tensor product of the 1-D central differences
                    counts = Counter(comp)
                    cvars = list(counts)
                    sten = [_CENTRAL[counts[w]] for w in cvars]
                    hs = [hval(w, counts[w]) for w in cvars]
                    denom = " * ".join(
                        [str(s[2]) for s in sten]
                        + [f"({h})^{counts[w]}" for w, h in zip(cvars, hs)])
                    terms = []
                    for combo in itertools.product(
                            *[range(len(s[0])) for s in sten]):
                        coef = 1
                        for k, j in enumerate(combo):
                            coef *= sten[k][1][j]
                        if coef == 0:
                            continue
                        over = {cvars[k]: pert(cvars[k], sten[k][0][j], hs[k])
                                for k, j in enumerate(combo)}
                        terms.append(f"({coef})*{at(over)}")
                    expr = f"evalf(({' + '.join(terms)})/({denom}))"
                L.append(f'printf("R %d %s 0 %%.18e\\n", {expr}):'
                         % (ip, field))


def _point_vars(family, spin, inp, ip, dens_thr):
    """Map a test-data point to the maple raw-variable values, applying
    the EXACT per-channel clipping eval_reference / work_*.c use: rho
    floored to dens_thr, sigma diagonal to dens_thr**(8/3), the
    off-diagonal sigma clamped to +/- the diagonal average, tau and lapl
    left raw. Matching this is essential -- a wrong floor at extreme-low
    density makes the tool disagree with the build/eval_reference (the
    q2d / r2scan-pt6 false positives)."""
    import numpy as np
    sig_thr = dens_thr ** (4.0 / 3.0)
    s2thr = sig_thr * sig_thr
    # Index the raw arrays directly: unpolarised rho is (npts,) and polarised
    # (npts, 2) -- both index as [ip]. (np.atleast_2d turns the unpolarised
    # (npts,) into (1, npts), collapsing every point onto point 0.)
    rho = np.asarray(inp["rho"])
    r = rho[ip]
    v = {}
    if spin == 1:
        v["na"] = max(dens_thr, float(r if r.ndim == 0 else r[0]))
    else:
        v["na"] = max(dens_thr, float(r[0]))
        v["nb"] = max(dens_thr, float(r[1]))
    if family != "lda":
        sg = np.asarray(inp["sigma"])[ip]
        if spin == 1:
            v["gaa"] = max(s2thr, float(sg if sg.ndim == 0 else sg[0]))
        else:
            gaa = max(s2thr, float(sg[0]))
            gbb = max(s2thr, float(sg[2]))
            s_ave = 0.5 * (gaa + gbb)
            gab = max(-s_ave, min(s_ave, float(sg[1])))
            v["gaa"], v["gab"], v["gbb"] = gaa, gab, gbb
    if family == "mgga":
        la = np.asarray(inp["lapl"])[ip]
        ta = np.asarray(inp["tau"])[ip]
        if spin == 1:
            v["la"] = float(la if la.ndim == 0 else la[0])
            v["ta"] = float(ta if ta.ndim == 0 else ta[0])
        else:
            v["la"], v["lb"] = float(la[0]), float(la[1])
            v["ta"], v["tb"] = float(ta[0]), float(ta[1])
    return v


def _cam_coef(reg, spin):
    """(cam_omega, cam_alpha, cam_beta) the build resolves for `reg`, or None if
    it cannot be instantiated. Read from pylibxc so every range-separation setter
    shape is honoured exactly. A screened functional whose omega is a plain
    ext-param (gga_x_wpbeh -> 0 (PBEh), gga_x_hjs_pbe -> 0.11) does NOT carry the
    XC_FLAGS_HYB_CAM flag, but the build still resolves cam_omega/alpha/beta into
    the func struct -- read them straight from there so p_a_cam_* stays numeric
    in the driver instead of leaving f symbolic. (0, 0, 0) for a functional that
    does not use range separation is harmless: the .mpl never reads p_a_cam_*."""
    try:
        import pylibxc
        f = pylibxc.LibXCFunctional(reg, spin)
    except Exception:
        return None
    if getattr(f, "_have_cam", False):
        try:
            return f.get_cam_coef()
        except Exception:
            pass
    try:
        st = f.xc_func.contents
        return (st.cam_omega, st.cam_alpha, st.cam_beta)
    except Exception:
        return None


def _has_mpl(name):
    return any(os.path.exists(os.path.join(_MAPLE_DIR, sub, name + ".mpl"))
               for sub in _FAMILY_SUBDIRS)


def _mix_constituents(reg, spin):
    """For a C 'mix' hybrid (xc_mix_init: a linear combination of constituent
    functionals, e.g. B3LYP = 0.08 lda_x + 0.72 gga_x_b88 + 0.19 lda_c_vwn_rpa
    + 0.81 gga_c_lyp), return [(constituent_name, coef, cam, ext_params), ...]
    read straight from the built functional's func_aux/mix_coef. None if not a
    mix.

    ``ext_params`` is {ext_param_name: value} of the constituent's ACTUAL
    instantiated ext-params (read with xc_func_get_ext_params), not its
    defaults -- a mix may reparametrise a constituent (edf1 uses gga_x_b88
    twice with different beta), and combining both with default beta is wrong."""
    try:
        import ctypes
        import pylibxc
        from pylibxc.structs import xc_func_type
        core = pylibxc.core
        getname = core.xc_functional_get_name
        getname.restype = ctypes.c_char_p
        getname.argtypes = [ctypes.c_int]
        n_ext = core.xc_func_info_get_n_ext_params
        n_ext.restype = ctypes.c_int
        n_ext.argtypes = [ctypes.c_void_p]
        ext_name = core.xc_func_info_get_ext_params_name
        ext_name.restype = ctypes.c_char_p
        ext_name.argtypes = [ctypes.c_void_p, ctypes.c_int]
        get_ext = core.xc_func_get_ext_params
        get_ext.restype = None
        get_ext.argtypes = [ctypes.c_void_p, ctypes.POINTER(ctypes.c_double)]
        f = pylibxc.LibXCFunctional(reg, spin)
        st = f.xc_func.contents
        n = st.n_func_aux
        if not n:
            return None
        # the func_aux array (xc_func_type**) is exposed by the binding under
        # the mislabelled void* field named 'xc_func_type'.
        arr = ctypes.cast(st.xc_func_type,
                          ctypes.POINTER(ctypes.POINTER(xc_func_type)))
        out = []
        for i in range(n):
            c = arr[i].contents
            num = c.info.contents.number
            # each constituent carries its own resolved range-separation
            # (the parent imposes omega on the SR/LR pieces of a CAM mix)
            cam = (float(c.cam_omega), float(c.cam_alpha), float(c.cam_beta))
            info_ptr = ctypes.cast(c.info, ctypes.c_void_p)
            nx = n_ext(info_ptr)
            ext = {}
            if nx:
                vbuf = (ctypes.c_double * nx)()
                get_ext(ctypes.cast(arr[i], ctypes.c_void_p), vbuf)
                for j in range(nx):
                    ext[ext_name(info_ptr, j).decode().lstrip("_")] = float(vbuf[j])
            out.append((getname(num).decode(), float(st.mix_coef[i]), cam, ext))
        return out
    except Exception:
        return None


def _generate_mix(mix, spin, system, max_order, digits, fd, timeout=600,
                  point_indices=None):
    """Arbitrary-precision reference for a mix hybrid: evaluate each
    constituent's .mpl and linearly combine the per-field/per-point
    components with the build's coefficients. A constituent missing a field
    that another supplies (an LDA piece has no vsigma) contributes 0 there."""
    combined, npts, errs = {}, 0, []
    for cname, coef, cam, ext in mix:
        # ext matters: a mix may instantiate the SAME constituent twice with
        # different ext-params (HSE uses gga_x_wpbeh at omega=0 and at
        # omega=omega_PBE; they differ by nothing else), so evaluating both
        # with the constituent's defaults would silently collapse the mix.
        res, npts, cerr = generate(cname, spin, system, max_order, digits, fd,
                                   cam_override=cam, ext_override=ext,
                                   timeout=timeout, point_indices=point_indices)
        errs += [f"[{cname}] {e}" for e in cerr]
        for field, perpt in res.items():
            dst = combined.setdefault(field, {})
            for ip, comps in perpt.items():
                acc = dst.setdefault(ip, [])
                for k, val in enumerate(comps):
                    term = coef * float(val)
                    if k < len(acc):
                        acc[k] += term
                    else:
                        acc.append(term)
    # back to the string form the comparison path expects
    results = {f: {ip: [repr(x) for x in comps] for ip, comps in pp.items()}
               for f, pp in combined.items()}
    return results, npts, errs


def generate(name, spin, system, max_order, digits, fd=True, cam_override=None,
             timeout=600, ext_override=None, point_indices=None):
    # C 'mix' hybrids (B3LYP etc.) have no math .mpl of their own: their energy
    # is a linear combination of constituent functionals assembled in C. Check
    # this FIRST -- _resolve can otherwise land on an unrelated multi-functional
    # .c whose basename has an (irrelevant) .mpl (apbe0's registry entry lives
    # in gga_c_zvpbeloc.c).
    mix = _mix_constituents(name, spin)
    if mix:
        return _generate_mix(mix, spin, system, max_order, digits, fd, timeout,
                             point_indices=point_indices)
    base, c_path, reg = _resolve(name)
    family, _ = _find_mpl(base)
    from pylibxc.example_densities import test_data
    inp = test_data[system]
    import numpy as np
    npts = np.asarray(inp["rho"]).shape[0]
    # A caller may request a contiguous SUBSET of the system's grid points (the
    # generator fans a single functional's points across several Maple processes
    # for parallelism). The emitted per-point index is the driver-local
    # enumerate() position over `points`, so a subset simply yields npts=len(sel)
    # values in the subset's own order -- the caller stitches the chunks back
    # together in grid order.
    sel = range(npts) if point_indices is None else list(point_indices)
    dens_thr = _er._read_dens_threshold(base)
    points = [_point_vars(family, spin, inp, ip, dens_thr)
              for ip in sel]
    npts = len(points)
    zeta_thr = 1e-15
    params = _params(reg, c_path, base, spin, ext_override=ext_override)
    # Range-separation / hybrid coefficients (p_a_cam_omega/alpha/beta in the
    # .mpl) are set by per-functional C setters (xc_hyb_init_*, the cam_sr/lc
    # ext-params setters) -- too many shapes to replay, so read the exact
    # values the build resolved to straight from pylibxc. cam_override lets a
    # mix parent impose its range-separation omega on a constituent.
    cam = cam_override or _cam_coef(reg, spin)
    # dimension marker may be mid-name (lda_c_1d_loos) or a suffix (lda_x_2d)
    dim = (1 if re.search(r"_1d(_|$)", reg)
           else 2 if re.search(r"_2d(_|$)", reg) else 3)
    driver, comp_exprs = _build_driver(
        base, reg, family, spin, max_order, digits, dens_thr, zeta_thr,
        params, points, dim, fd, cam)
    import tempfile
    fd, path = tempfile.mkstemp(suffix=".mpl")
    os.write(fd, driver.encode())
    os.close(fd)
    incs = []
    for sub in _FAMILY_SUBDIRS:
        incs += ["-I", os.path.join(_MAPLE_DIR, sub)]
    incs += ["-I", _MAPLE_DIR]
    try:
        r = subprocess.run([_maple_exe()] + incs + ["-q", "-u", path],
                           capture_output=True, text=True, timeout=timeout)
    finally:
        os.remove(path)
    # collect: results[field][ip] = [components...]
    results = {}
    for m in re.finditer(r"^R (\d+) (\w+) (\d+) (\S+)", r.stdout, re.M):
        ip, field, _eid, val = int(m.group(1)), m.group(2), 0, m.group(4)
        results.setdefault(field, {}).setdefault(ip, []).append(val)
    errs = [ln for ln in (r.stdout + r.stderr).splitlines()
            if ln.lstrip().startswith("Error")]
    return results, npts, errs


def _stored_refs(name, system, spin):
    """{field: flat list of values} from the regression test file, or {}."""
    import glob
    cands = glob.glob(os.path.join(
        _REPO, "testsuite", "regression", "*",
        f"test_{name}_{system}.py"))
    out = {}
    if not cands:
        return out
    txt = open(cands[0]).read()
    pat = (r"def test_%s_%s_%d_(\w+)\(\):.*?asarray\(\[(.*?)\]\)"
           % (re.escape(name), re.escape(system), spin))
    for m in re.finditer(pat, txt, re.S):
        field, body = m.group(1), m.group(2)
        try:
            out[field] = [float("nan") if "nan" in v else float(v)
                          for v in body.split(",") if v.strip()]
        except ValueError:
            pass
    return out


def _compare(name, system, spin, max_order, digits, fd=True):
    import numpy as np
    import pylibxc
    from pylibxc.example_densities import test_data
    try:
        results, npts, errs = generate(name, spin, system, max_order, digits,
                                       fd)
    except FileNotFoundError:
        # No .mpl source: a hand-coded C functional (e.g. gga_k_gds08) that is
        # not part of the Maple->C codegen pipeline. Nothing to adjudicate.
        print(f"{name}: no maple source (hand-coded C); skipped")
        return
    if errs:
        sys.stderr.write("maple errors:\n  " + "\n  ".join(errs[:6]) + "\n")
    # The base .mpl name may not be the registered functional name -- many
    # are registered as <base>1 (e.g. gga_k_pg -> gga_k_pg1). Try the base,
    # then the <base>1 variant (which uses the base .mpl + the default params
    # this tool reads), for both the build and the stored ref.
    out = {}
    for bn in (name, name + "1"):
        refs = _stored_refs(bn, system, spin)
        try:
            func = pylibxc.LibXCFunctional(bn, spin)
            flags = func.get_flags()
            # Kinetic functionals expose the energy via zk too but may not set
            # HAVE_EXC; request exc whenever the maple gives zk.
            fl = pylibxc.flags
            has = lambda bit: bool(flags & bit)
            out = func.compute(
                test_data[system],
                do_exc=has(fl.XC_FLAGS_HAVE_EXC) or "zk" in results,
                do_vxc=max_order >= 1 and has(fl.XC_FLAGS_HAVE_VXC),
                do_fxc=max_order >= 2 and has(fl.XC_FLAGS_HAVE_FXC),
                do_kxc=max_order >= 3 and has(fl.XC_FLAGS_HAVE_KXC),
                do_lxc=max_order >= 4 and has(fl.XC_FLAGS_HAVE_LXC))
            break
        except KeyError:
            continue
    thr = 5e-8
    print(f"{name}  {system}  spin={spin}  (Maple {digits}-digit truth "
          f"vs build vs stored ref)")
    verdicts = {}
    for field in sorted(results, key=lambda f: (len(f), f)):
        truth = [float(x) for ip in range(npts)
                 for x in results[field].get(ip, [])]
        build = (np.asarray(out[field]).flatten().tolist()
                 if out.get(field) is not None else [None] * len(truth))
        ref = refs.get(field, [None] * len(truth))
        for i, t in enumerate(truth):
            b = build[i] if i < len(build) else None
            r = ref[i] if i < len(ref) else None
            db = abs(b - t) if b is not None else None
            dr = abs(r - t) if r is not None else None
            tag = "?"
            if b is not None:
                bok = db <= thr * (1 + abs(t))
                if dr is None:                  # no stored ref: build vs truth
                    tag = "ok" if bok else "BUILD-WRONG"
                else:
                    rok = dr <= thr * (1 + abs(t))
                    tag = ("ok" if bok and rok else
                           "BUILD-WRONG" if rok and not bok else
                           "REF-STALE" if bok and not rok else
                           "BOTH-OFF")
                # A finite-difference stencil that straddles a screen/clamp
                # junction (empty channel floored exactly to dens_threshold)
                # returns the secant across the jump -- a huge value while the
                # build takes the one-sided screened derivative (~0). Flag
                # these so they don't masquerade as real build disagreements.
                if (fd and tag != "ok"
                        and abs(t) > 1e3 * (abs(b) + abs(r or 0) + 1e-30)):
                    tag = "FD-ARTIFACT"
            verdicts[tag] = verdicts.get(tag, 0) + 1
            if tag not in ("ok",):
                fb = f"{b:.6e}" if b is not None else "--"
                fr = f"{r:.6e}" if r is not None else "--"
                print(f"  {field}[{i}] truth={t:.10e} build={fb} "
                      f"ref={fr}  -> {tag}")
    print("verdict tally:", dict(sorted(verdicts.items())))


# Per-functional derivative-order caps (mirror of compile.py's _ORDER_CAPS).
# Everything else certifies to order 4.
_ORDER_CAPS = {
    # differentiability caps (genuine Cn limits -- see compile.py for per-functional rationale)
    "gga_x_wpbeh": 2, "lda_c_pk09": 3, "mgga_c_b94": 3,
    "mgga_x_rscan": 3, "mgga_c_rscan": 3,            # rscan_f_alpha: C3 at alpha=2.5
    "mgga_x_r2scan": 2, "mgga_c_r2scan": 2, "mgga_x_r4scan": 2,  # r2scan_f_alpha: C2 at alpha=0
    # performance caps (C-inf but order-4 sp.diff multi-hour/infeasible -> cap at kxc)
    "mgga_c_tpss": 3, "mgga_c_revtpss": 3, "mgga_c_tpssloc": 3,
    "gga_c_gapc": 3, "hyb_mgga_xc_coach": 3,
    "mgga_c_pkzb": 3, "gga_c_pbe_vwn": 3, "mgga_c_revscan": 3,
    "mgga_c_rppscan": 3, "mgga_c_scan": 3,
    "gga_c_q2d": 3, "mgga_c_mscan": 3, "gga_c_zvpbeloc": 3,
    "gga_c_sg4": 3, "gga_c_acggap": 3, "mgga_c_rregtm": 3,
    "gga_c_zvpbeint": 3, "gga_c_acgga": 3, "gga_c_zpbeint": 3,
    "mgga_x_mscan": 3,
}


def _cross(name, system, spin, max_order, digits, fd=True):
    """Cross-check the two INDEPENDENT arbitrary-precision oracles -- Maple on
    the .mpl vs mpmath on the SymPy expression graph -- field/point/channel by
    channel. Neither uses the compiled C, so agreement certifies that the
    SymPy formulation's symbolic math equals Maple's (the foundation of "SymPy
    is as good as Maple"). Honours each functional's order cap."""
    import numpy as np
    from pylibxc.example_densities import test_data
    cap = _ORDER_CAPS.get(name)
    order = min(max_order, cap) if cap is not None else max_order
    # Range-separated functionals need a cam_omega; a base-only one (gga_x_ityh)
    # has none registered, so default to a test omega -- both oracles use the
    # SAME value, which certifies the attenuation math regardless of the value.
    cam = _cam_coef(name, spin) or (0.3, 0.0, 0.0)
    try:
        mres, npts, merrs = generate(name, spin, system, order, digits, fd,
                                     cam_override=cam)
    except FileNotFoundError:
        print(f"{name}: no maple source; skipped")
        return
    if not mres:
        print(f"{name}: Maple oracle produced nothing"
              + (f" ({merrs[0]})" if merrs else ""))
        return
    inp = test_data[system]
    ncol = ({"rho": 1, "sigma": 1, "lapl": 1, "tau": 1} if spin == 1
            else {"rho": 2, "sigma": 3, "lapl": 2, "tau": 2})
    kw = {"rho": inp["rho"].reshape(-1, ncol["rho"]).tolist()}
    for k in ("sigma", "lapl", "tau"):
        if k in inp:
            kw[k] = inp[k].reshape(-1, ncol[k]).tolist()
    # Give the mpmath oracle the SAME robust params and base module the Maple
    # oracle used: maple_reference._params resolves ext/init/computed/variant
    # params and _resolve maps a variant to its base .py.
    base, c_path, reg = _resolve(name)
    mparams = _params(reg, c_path, base, spin)
    dens_thr = _er._read_dens_threshold(base)
    try:
        eres = _er.evaluate(name, spin, max_order=order, precision=digits,
                            module=base, param_overrides=mparams,
                            dens_threshold=dens_thr, cam=cam, **kw)
    except Exception as e:
        print(f"{name}: mpmath oracle failed: {e}")
        return
    # FD-achievable precision degrades with derivative order (the 1/h^n
    # stencil amplifies roundoff, severely so at the extreme-density points
    # where high-order derivatives are enormous). A genuine math divergence
    # is O(1) at many points, so these order-scaled tolerances still catch a
    # real bug while absorbing FD precision loss. Orders 0-2 stay strict.
    def _ford(field):
        if field == "zk":
            return 0
        return int(field[1]) if field[1:2].isdigit() else 1
    # Order 0 (function equality) and orders 1-2 are the rigorous, reliable
    # range; orders 3-4 FD is precision-limited at extreme density, so their
    # tolerance only asserts no O(1) divergence (a real math bug).
    _TOL = {0: 1e-9, 1: 1e-7, 2: 1e-7, 3: 1e-3, 4: 1e-2}
    verdicts = {}
    for field in sorted(mres, key=lambda f: (len(f), f)):
        epts = eres.get(field)
        thr = _TOL[_ford(field)]
        for ip in range(npts):
            mvals = [float(x) for x in mres[field].get(ip, [])]
            evals = epts[ip] if epts is not None and ip < len(epts) else []
            for k, mv in enumerate(mvals):
                ev = evals[k] if k < len(evals) else None
                if ev is None or (isinstance(ev, float)
                                  and (ev != ev or abs(ev) == float("inf"))):
                    tag = "?"
                elif abs(mv - ev) <= thr * (1 + abs(ev)):
                    tag = "ok"
                elif fd and abs(mv) > 1e3 * (abs(ev) + 1e-30):
                    # the FD Maple stencil straddled a density-floor/screen
                    # junction (the mpmath oracle takes the exact one-sided
                    # derivative); a secant across the jump, not a real
                    # math disagreement
                    tag = "FD-ARTIFACT"
                else:
                    tag = "DIFF"
                verdicts[tag] = verdicts.get(tag, 0) + 1
                if tag == "DIFF":
                    print(f"  DIFF {field}[{ip}][{k}] maple={mv:.10e} "
                          f"mpmath={ev:.10e}  reldev="
                          f"{abs(mv - ev) / (abs(ev) + 1e-300):.2e}")
    print(f"{name}  order<={order}  (Maple vs mpmath) cross tally:",
          dict(sorted(verdicts.items())))


def _main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name")
    ap.add_argument("--system", default="H")
    ap.add_argument("--spin", type=int, default=2, choices=(1, 2))
    ap.add_argument("--max-order", type=int, default=1)
    ap.add_argument("--digits", type=int, default=50)
    ap.add_argument("--compare", action="store_true",
                    help="adjudicate Maple truth vs the build and the "
                         "stored regression reference")
    ap.add_argument("--cross", action="store_true",
                    help="cross-check the Maple oracle against the mpmath "
                         "(SymPy-expression) oracle -- build-free proof that "
                         "the SymPy math equals Maple's, to each order cap")
    ap.add_argument("--symbolic", action="store_true",
                    help="use exact Maple symbolic diff for derivatives "
                         "instead of the default finite differences (slower; "
                         "times out on the SCAN/r2SCAN class)")
    args = ap.parse_args()
    fd = not args.symbolic
    if args.cross:
        _cross(args.name, args.system, args.spin, args.max_order,
               args.digits, fd)
        return
    if args.compare:
        _compare(args.name, args.system, args.spin, args.max_order,
                 args.digits, fd)
        return
    results, npts, errs = generate(args.name, args.spin, args.system,
                                   args.max_order, args.digits, fd)
    if errs:
        sys.stderr.write("maple errors:\n  " + "\n  ".join(errs[:6]) + "\n")
    for field in sorted(results, key=lambda f: (len(f), f)):
        print(f"{field}:")
        for ip in range(npts):
            comps = results[field].get(ip, [])
            print("  [%d] %s" % (ip, "  ".join(comps)))


_RESOLVED_PARAMS_CACHE = {}


def resolved_params(name, spin=2, ext_override=None):
    """Shared parameter-resolution entry point.

    Returns the fully-resolved parameter values for ``name`` keyed by symbol
    name (e.g. ``'params_a_pg_mu' -> '1.0'``), covering variant specialization,
    init-hardcoded, computed, list, and ext-params-default parameters. This is
    THE single authoritative resolver: the AD (ad_reference) and symbolic
    (eval_reference) engines call it too, so all three agree instead of each
    carrying a divergent hand-copied resolver. Returns ``{}`` on any failure so
    callers can fall back gracefully.

    ``ext_override`` ({ext_param_name: value}) supplies the ACTUAL ext-params a
    functional was instantiated with -- used for a mix constituent the parent
    reparametrised -- and is part of the cache key."""
    ekey = tuple(sorted(ext_override.items())) if ext_override else ()
    key = (name, spin, ekey)
    if key not in _RESOLVED_PARAMS_CACHE:
        try:
            base, c_path, reg = _resolve(name)
            _RESOLVED_PARAMS_CACHE[key] = dict(
                _params(reg, c_path, base, spin, ext_override))
        except Exception:
            _RESOLVED_PARAMS_CACHE[key] = {}
    return _RESOLVED_PARAMS_CACHE[key]


_COMPUTED_KEYS_CACHE = {}


def computed_param_keys(name, spin=2):
    """Keys whose value a CUSTOM (non-cpy) set_ext_params COMPUTES from the
    ext-param inputs rather than copying them (lda_c_xalpha's struct alpha =
    1.5*ext_alpha - 1). For these the resolver -- not the functional module's
    baked ext-param default -- is authoritative even when the functional is
    evaluated standalone, so a caller must override its own default rather than
    setdefault. Returns an empty set for plain set_ext_params_cpy functionals."""
    if name not in _COMPUTED_KEYS_CACHE:
        try:
            base, c_path, reg = _resolve(name)
            text = open(c_path).read()
            _COMPUTED_KEYS_CACHE[name] = set(
                _computed_params(reg, text, _cam_env(reg, spin)).keys())
        except Exception:
            _COMPUTED_KEYS_CACHE[name] = set()
    return _COMPUTED_KEYS_CACHE[name]


if __name__ == "__main__":
    _main()
