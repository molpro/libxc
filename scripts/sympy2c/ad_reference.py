"""Fast arbitrary-precision reference values via Taylor-mode AD (mpmath).

Drop-in alternative to eval_reference's symbolic (sp.diff + evalf) oracle: it
reuses ad_bridge's functional assembly (same na/nb/gaa/... variables and rs/z/xt
maps as eval_reference and libxc), lowers to the hash-consed AD DAG, and
evaluates every Taylor-jet node in mpmath (ad_engine.DAG.evaluate(prec=...)).
Because AD is polynomial-time, the tpss/scan-class functionals -- hours under
symbolic sp.diff -- take milliseconds here, at the same arbitrary precision.

`evaluate_converged` mirrors eval_reference's signature and output
({field: [[per-channel] per point]}, {field: [[status] ...]}), so the test
generator can prefer it and fall back to the symbolic oracle then the build.

Scope: energy (*_exc) functionals to arbitrary derivative order (each output
field read from the Taylor jet and rescaled by the multi-index factorial, since
the jet stores coefficients d^a f / a! while libxc reports the derivative d^a f).
vxc-direct functionals expose only order-1 (the potential is f itself).
"""
import sys as _sys
_HERE = __file__.rsplit("/", 1)[0]
for _p in (_HERE, _HERE.rsplit("/", 2)[0] + "/python"):
    if _p not in _sys.path:
        _sys.path.insert(0, _p)

import ast
import re
import sympy as sp
import ad_bridge as AB
import ad_engine as AE
import eval_reference as ER


def _penv_from(free_symbols, vs, name, mod, spin=2, ext_params=None, cam=None):
    """Parameter environment for the AD DAG: the shared parameter resolver's
    defaults (variant / init-hardcoded / computed / list / ext-params) and
    thresholds, keyed by the free symbols of the assembled expression. A symbol
    left unbound maps to None -> the caller returns (the case cannot be AD'd).

    ``ext_params`` ({ext_param_name: value}) are the ACTUAL ext-params a mix
    constituent was instantiated with; when given, the resolver's values are
    authoritative and override the module defaults."""
    pv = {str(k): v for k, v in ER._read_parameters(name, mod).items()}
    # Fill any parameter ER._read_parameters misses -- notably scalar variant
    # ext-params such as params_a_pg_mu (pg1) or params_a_csk_a (csk1), whose
    # value lives only in the C ext-params default array -- from the single
    # authoritative resolver in maple_reference, so the AD, symbolic, and Maple
    # engines share ONE parameter resolution. setdefault: never override a value
    # the existing path already bound -- UNLESS ext_params were imposed, in which
    # case the resolver has the correct (reparametrised) values and wins.
    try:
        import maple_reference as _MR
        _ck = _MR.computed_param_keys(name, spin)
        for _k, _v in _MR.resolved_params(name, spin, ext_params).items():
            # resolved_params wins when ext-params were imposed, or when the key
            # is one a custom set_ext_params COMPUTES (the module bakes the raw
            # ext default, but the setter derives a different struct value --
            # lda_c_xalpha's alpha); otherwise defer to the module's binding.
            if ext_params or _k in _ck:
                pv[_k] = _v
            else:
                pv.setdefault(_k, _v)
    except Exception:
        pass
    macro = ER._macro_env()
    dthr = ER._read_dens_threshold(name)
    penv_src = {}
    for s in free_symbols:
        if s in vs:
            continue
        nm = str(s)
        if nm in pv and pv[nm] is not None:
            penv_src[s] = pv[nm]
        elif nm == "zeta_threshold":
            penv_src[s] = 1e-15
        elif nm == "dens_threshold":
            penv_src[s] = dthr
        elif nm == "XC_EPSILON":
            penv_src[s] = 2.220446049250313e-16     # = DBL_EPSILON
        elif nm in macro:
            penv_src[s] = macro[nm]
        elif nm in ("cam_omega", "cam_alpha", "cam_beta"):
            # Range-separation coefficients. A CAM mix imposes its own omega
            # (and alpha/beta) on the SR/LR constituent, so use the passed cam
            # when given; otherwise the pure short-range exchange GGAs
            # (hjs/ityh/wpbeh/...) copy the "omega" ext_param into cam_omega, so
            # read it from the ext_params block.
            if cam is not None:
                penv_src[s] = {"cam_omega": cam[0], "cam_alpha": cam[1],
                               "cam_beta": cam[2]}[nm]
            else:
                # Standalone CAM functional: the resolver's _cam_env replicates
                # the C cam setter, mapping the (often differently-named)
                # ext-params onto cam_alpha/beta/omega -- e.g. js18's cam_sr
                # setter puts ext 'a' into cam_beta and ext 'omega' into
                # cam_omega, which a bare get('beta')/get('omega') would miss.
                cenv = {}
                try:
                    import maple_reference as _MR
                    cenv = _MR._cam_env(name, spin)
                except Exception:
                    pass
                penv_src[s] = cenv.get(
                    nm, ER._ext_param_values(name).get(nm[len("cam_"):]))
        else:
            # Array-parameter element params_a_X[i] (0-based: _Param.__getitem__
            # already maps Maple's 1-based subscript down). Three resolvers, in
            # order of directness:
            #  1. the assembled struct-array list params_a_X, indexed 0-based --
            #     always in struct declaration order, so unambiguous;
            #  2. the flat scalar key params_a_X<i>, as a fallback if no list was
            #     assembled;
            #  3. the raw C ext-params default array under the name X<i>.
            # The list MUST come first: the flat scalar key silently mis-maps
            # when the C ext-param scalars are 1-indexed while the struct field
            # (and therefore the .mpl's access) is 0-based -- gga_k_lgap's struct
            # mu[3] <- ext-params mu1/mu2/mu3, so DAG params_a_mu[1] would re-key
            # to params_a_mu1 (the s^1 coefficient) instead of the s^2 one. Only
            # tpss's C0_c happened to be safe because ITS scalars are 0-indexed
            # (C0_c0..C0_c3). The list carries any mix ext_params override too.
            m = re.match(r"params_a_(.+)\[(\d+)\]$", nm)
            idx = int(m.group(2)) if m else None
            lst = pv.get("params_a_" + m.group(1)) if m else None
            flat = ("params_a_" + m.group(1) + str(idx)) if m else None
            val = None
            if isinstance(lst, str) and lst.lstrip().startswith("["):
                try:
                    arr = ast.literal_eval(lst)
                    if 0 <= idx < len(arr):
                        val = arr[idx]
                except (ValueError, SyntaxError):
                    pass
            if val is None and flat is not None and pv.get(flat) is not None:
                val = pv[flat]
            if val is None and m is not None:
                ev = ER._ext_param_values(name)
                key = m.group(1) + str(idx)
                val = ev[key] if (ev and key in ev) else None
            penv_src[s] = val
    return penv_src


def _build(name, spin, max_order, ext_params=None, cam=None):
    """Assemble (dag, fj, nfj, idx, vs, groups, penv_template, family, potjets).

    ``potjets`` is None for an energy (*_exc) functional; for a *_vxc functional
    the math file's f is the POTENTIAL itself, so f is None and ``potjets`` is
    the per-spin-channel order-0 value jets [up] / [up, dn] whose evaluation is
    the vrho reference (no zk, no differentiation at the reference order)."""
    _, fam_full = AB._load(name)
    is_vxc = fam_full.endswith("_vxc")
    fam = fam_full.split("_")[0]                  # "lda_exc"/"mgga_vxc" -> "lda"
    # Load via eval_reference so the parameter-default block binds numerically
    # (init-hardcoded / computed / list params like PBE's BB, PW92's a[i] that a
    # plain import leaves as free symbols); mirrors what ER.evaluate evaluates.
    # When ext-params are imposed (a reparametrised mix constituent), do NOT
    # activate that block -- it would bake the DEFAULT ext-params as Floats and
    # shadow the override. Leave every parameter symbolic instead, so _penv_from
    # binds them all from the override-aware shared resolver.
    mod = ER._import_functional(
        name, macro_name=("__ext_override__" if ext_params else name))
    AB._apply_dimension(mod)
    AB._resolve(mod, max_order)
    sp_s = "pol" if spin == 2 else "unpol"
    d = AE.DAG()
    memo = {}
    if is_vxc:
        pots, groups = AB._assemble_vxc(mod, sp_s, fam)
        vs = [s for g in groups for s in g]
        # f IS the potential, so it is already libxc's order-1 output (vrho).
        # Every order-2 output is therefore a FIRST derivative of f: v2rho2 =
        # dv/drho, v2rhosigma = dv/dsigma, and so on. Carry the jet one order
        # below the requested one.
        idx = AE.multi_indices(len(vs), max(0, max_order - 1))
        potjets, free = [], set()
        for pot in pots:
            px = AB._fold_const_piecewise(AB._inline(pot))
            funcs, _ = AB._funcs_for(px)
            potjets.append(AE.to_jet(d, px, vs, idx, memo, funcs=funcs))
            free |= px.free_symbols
        penv_src = _penv_from(free, vs, name, mod, spin, ext_params, cam)
        return d, None, None, idx, vs, groups, penv_src, fam, potjets
    if fam == "lda":
        f, rho_s, nt = AB._assemble_lda(mod, sp_s)
        groups = [rho_s, [], [], []]
    elif fam == "gga":
        f, rho_s, sig_s, nt = AB._assemble_gga_spin(mod, sp_s)
        groups = [rho_s, sig_s, [], []]
    else:
        f, rho_s, sig_s, lap_s, tau_s, nt = AB._assemble_mgga_spin(mod, sp_s)
        groups = [rho_s, sig_s, lap_s, tau_s]
    vs = [s for g in groups for s in g]
    fx = AB._fold_const_piecewise(AB._inline(f))
    funcs, _ = AB._funcs_for(fx)
    idx = AE.multi_indices(len(vs), max_order)
    fj = AE.to_jet(d, fx, vs, idx, memo, funcs=funcs)
    nfj = AE.to_jet(d, nt * fx, vs, idx, memo, funcs=funcs)
    penv_src = _penv_from(fx.free_symbols, vs, name, mod, spin, ext_params, cam)
    return d, fj, nfj, idx, vs, groups, penv_src, fam, None


def _energy_field_layout(fam, groups, vs, max_order):
    """Output-field layout for an energy (*_exc) functional, orders 0..max_order.

    Returns ``[(field_name, order, [(multi_index, alpha_fact) per component])]``
    where each multi-index is over ``vs`` (the flattened variable list). zk
    (order 0) is a single component read from the f jet; every higher field is
    read from the n*f jet. Field names and per-group derivative counts come from
    libxc_codegen's FIELDS tables (so they match the build's output layout), and
    the per-component channel combinations from eval_reference._partials -- the
    same source the symbolic oracle uses.

    ``alpha_fact`` is the multi-index factorial prod(a_i!): to_jet stores Taylor
    COEFFICIENTS d^a f / a!, while libxc's output field is the derivative d^a f
    itself, so the jet value is scaled back up by a!."""
    import libxc_codegen as L
    from math import factorial, prod
    layout = []
    for o in range(max_order + 1):
        if fam == "lda":
            descs = [(L.LDA_FIELDS[o][0], (o,))]
        elif fam == "gga":
            descs = [(f, (oR, oS)) for f, oR, oS in L.GGA_FIELDS[o]]
        else:
            descs = [(d[0], tuple(d[1:])) for d in L.MGGA_FIELDS[o]]
        for field_name, counts in descs:
            comps = []
            for partial in ER._partials(counts, groups):
                midx = [0] * len(vs)
                for gi, idxs in enumerate(partial):
                    for i in idxs:
                        midx[vs.index(groups[gi][i])] += 1
                comps.append((tuple(midx), prod(factorial(c) for c in midx)))
            layout.append((field_name, o, comps))
    return layout


# Assembled-DAG cache. _build re-runs the whole symbolic assembly (import,
# inline, fold, lower to the Taylor-jet DAG) -- the dominant cost -- and it is
# INPUT-INDEPENDENT: the DAG, jets, variable/parameter environment and family
# depend only on (name, spin, max_order), not on the density point, so the same
# assembly serves every system. Reusing it is safe because DAG.evaluate reads
# the structural condition caches but computes node VALUES into its own per-call
# map (no input state is written back). The key is parameter-aware through the
# functional name: a variant carries its own name (hence its own resolved
# parameters), so two variants of one base never share an entry.
_BUILD_CACHE = {}


def _build_cached(name, spin, max_order, ext_params=None, cam=None):
    key = (name, spin, max_order,
           tuple(sorted(ext_params.items())) if ext_params else (), cam)
    if key not in _BUILD_CACHE:
        _BUILD_CACHE[key] = _build(name, spin, max_order, ext_params, cam)
    return _BUILD_CACHE[key]


def evaluate(name, spin, rho, sigma=None, lapl=None, tau=None,
             precision=50, max_order=1, ext_params=None, cam=None,
             **_ignored):
    """Return {field: [[per-channel] per point]} of mpf values, or None if AD
    cannot handle this functional / order."""
    try:
        d, fj, nfj, idx, vs, groups, penv_src, fam, potjets = _build_cached(
            name, spin, max_order, ext_params, cam)
    except Exception:
        return None
    if any(v is None for v in penv_src.values()):
        return None
    import mpmath
    # Raise the working precision BEFORE the parameters are converted. mpf()
    # rounds to the *ambient* mp.dps, which in a fresh process is the mpmath
    # default of 15 -- so every parameter would be silently truncated to 15
    # significant digits and the whole arbitrary-precision evaluation would run
    # on them. (ad_engine raises mp.dps too, but only once it is inside
    # d.evaluate(), by which point penv has already been rounded. It used to
    # LEAK the raised dps -- why only the FIRST call in a process was wrong and
    # every later one looked fine; d.evaluate now restores its caller's dps,
    # so the raise here is the only one penv can rely on.)
    #
    # For a well-conditioned functional the 1e-16 perturbation is invisible.
    # For an ill-conditioned one it is not: mgga_c_tpss's potential has a
    # condition number ~1e13 w.r.t. the density, which turns it into a ~1e-2
    # relative error in vrho. Match ad_engine's guard digits.
    mpmath.mp.dps = int(precision) + 30
    # A parameter that did not resolve to a plain number (e.g. a default left as
    # a symbolic expression) means this functional cannot be AD'd here; bail so
    # the caller falls back rather than crashing in mpf().
    penv = {}
    for s, v in penv_src.items():
        try:
            penv[s] = mpmath.mpf(str(v))
        except (ValueError, TypeError):
            return None
    npts = len(rho)
    # work_*_inc.c input clamping / screening: reuse eval_reference's shared
    # helper so this oracle screens and clamps identically to the build (and to
    # the symbolic oracle). Without it the raw analytic value at an unclamped
    # tail density leaks a spurious nonzero reference (e.g. q2d/2d_amgb pt19
    # where the build screens to 0, or mbeefvdw where the sigma clamp shifts the
    # value ~25%).
    n_rho, n_sig = len(groups[0]), len(groups[1])
    n_lap, n_tau = len(groups[2]), len(groups[3])
    dthr = ER._read_dens_threshold(name)
    sig_thr = dthr ** (4.0 / 3.0)
    s2thr = sig_thr * sig_thr
    zero = (0,) * len(vs)
    if potjets is not None:
        # *_vxc: f IS the potential, so it is libxc's order-1 output (vrho) and
        # there is no energy density to differentiate. Consequently:
        #
        #   vrho        = f
        #   vsigma/vlapl/vtau = 0   (not determined by the potential alone)
        #   v2rho2      = dv/drho,  v2rhosigma = dv/dsigma,
        #   v2rholapl   = dv/dlapl, v2rhotau   = dv/dtau
        #   v2sigma2, v2sigmalapl, v2sigmatau, v2lapl2, v2lapltau, v2tau2 = 0
        #
        # which is exactly what the build emits. One potjet per channel.
        nrho, nsig = len(groups[0]), len(groups[1])
        nlap, ntau = len(groups[2]), len(groups[3])
        npot = len(potjets)

        def unit(k):
            e = [0] * len(vs)
            e[k] = 1
            return tuple(e)

        # (field, per-point component count, group index the second slot runs
        # over, offset of that group in vs). None group => an all-zero field.
        mixed = []
        if max_order >= 2:
            if nsig:
                mixed.append(("v2rhosigma", 1, nrho))
            if nlap:
                mixed.append(("v2rholapl", 2, nrho + nsig))
            if ntau:
                mixed.append(("v2rhotau", 3, nrho + nsig + nlap))
        zero_fields = []
        if nsig:
            zero_fields.append(("vsigma", nsig))
        if nlap:
            zero_fields.append(("vlapl", nlap))
        if ntau:
            zero_fields.append(("vtau", ntau))
        if max_order >= 2:
            if nsig:
                zero_fields += [("v2sigma2", 6 if spin == 2 else 1)]
                if nlap:
                    zero_fields += [("v2sigmalapl", 6 if spin == 2 else 1)]
                if ntau:
                    zero_fields += [("v2sigmatau", 6 if spin == 2 else 1)]
            if nlap:
                zero_fields += [("v2lapl2", 3 if spin == 2 else 1)]
                if ntau:
                    zero_fields += [("v2lapltau", 4 if spin == 2 else 1)]
            if ntau:
                zero_fields += [("v2tau2", 3 if spin == 2 else 1)]

        out = {"vrho": []}
        if max_order >= 2:
            out["v2rho2"] = []
        for fld, _g, _o in mixed:
            out[fld] = []
        for fld, _n in zero_fields:
            out[fld] = []

        for p in range(npts):
            screened, vr, vsg, vl, vt, _ = ER.clamp_point(
                p, rho, sigma, lapl, tau, nrho, nsig, nlap, ntau,
                spin, dthr, s2thr)
            if screened:
                out["vrho"].append([mpmath.mpf(0)] * npot)
                if max_order >= 2:
                    out["v2rho2"].append(
                        [mpmath.mpf(0)] * (1 if nrho == 1 else 3))
                for fld, gi, off in mixed:
                    out[fld].append([mpmath.mpf(0)] * (npot * len(groups[gi])))
                for fld, n in zero_fields:
                    out[fld].append([mpmath.mpf(0)] * n)
                continue
            clamped_vals = [vr, vsg, vl, vt]
            point = {}
            for gi, grp in enumerate(groups):
                for i, ch in enumerate(grp):
                    point[ch] = mpmath.mpf(str(clamped_vals[gi][i]))
            try:
                val = d.evaluate(point, penv, prec=precision)
            except Exception:
                return None
            out["vrho"].append([val[pj.get(zero)] for pj in potjets])
            # v2rho2 is symmetric in its two rho slots: libxc stores (aa, ab, bb),
            # not the full npot x nrho product the mixed fields below use.
            if max_order >= 2:
                if nrho == 1:
                    out["v2rho2"].append([val[potjets[0].get(unit(0))]])
                else:
                    out["v2rho2"].append([
                        val[potjets[0].get(unit(0))],   # d v_a / d rho_a
                        val[potjets[0].get(unit(1))],   # d v_a / d rho_b
                        val[potjets[1].get(unit(1))],   # d v_b / d rho_b
                    ])
            # libxc lays the mixed order-2 fields out with the rho channel as
            # the outer index and the other variable as the inner one, which is
            # the order these nested loops produce.
            for fld, gi, off in mixed:
                row = []
                for pj in potjets:
                    for k in range(len(groups[gi])):
                        row.append(val[pj.get(unit(off + k))])
                out[fld].append(row)
            for fld, n in zero_fields:
                out[fld].append([mpmath.mpf(0)] * n)
        return out
    # Output fields for orders 0..max_order: zk from the f jet, every derivative
    # field from the n*f jet, indexed by the mixed-partial multi-indices that
    # match libxc's output layout. Both jets are evaluated at the (floored)
    # inputs, so the k-th partial IS the build's d^k(n*f)/d(input)^k -- the build
    # differentiates the floored kernel too, it does not chain-rule the floors.
    layout = _energy_field_layout(fam, groups, vs, max_order)
    out = {fld: [] for fld, _, _ in layout}
    for p in range(npts):
        (screened, vals_rho, vals_sigma, vals_lapl, vals_tau,
         _clamped) = ER.clamp_point(
            p, rho, sigma, lapl, tau, n_rho, n_sig, n_lap, n_tau, spin,
            dthr, s2thr)
        if screened:
            for fld, _o, comps in layout:
                out[fld].append([mpmath.mpf(0)] * len(comps))
            continue
        clamped_vals = [vals_rho, vals_sigma, vals_lapl, vals_tau]
        point = {}
        for gi, grp in enumerate(groups):
            for i, ch in enumerate(grp):
                point[ch] = mpmath.mpf(str(clamped_vals[gi][i]))
        try:
            val = d.evaluate(point, penv, prec=precision)
        except Exception:
            return None
        for fld, o, comps in layout:
            jet = fj if o == 0 else nfj
            out[fld].append([val[jet.get(midx)] * fact for midx, fact in comps])
    return out


def evaluate_converged(name, spin, rho, sigma=None, lapl=None, tau=None,
                       max_order=1, base_precision=50, check_precision=100,
                       max_precision=400, ext_params=None, cam=None,
                       **_ignored):
    """AD reference with a self-convergence guard: evaluate at base_precision and
    check_precision; a value passes only if the two agree to ~base_precision
    relative digits. Returns ({field: [[double per-channel] per point]},
    {field: [[status] ...]}) with double-rounded values (matching
    eval_reference), or (None, None) when AD cannot handle the case.

    ``ext_params`` ({ext_param_name: value}) forces the ext-params (a mix
    constituent the parent reparametrised) instead of the functional's own
    defaults."""
    lo = evaluate(name, spin, rho, sigma, lapl, tau, precision=base_precision,
                  max_order=max_order, ext_params=ext_params, cam=cam)
    if lo is None:
        return None, None
    hi = evaluate(name, spin, rho, sigma, lapl, tau, precision=check_precision,
                  max_order=max_order, ext_params=ext_params, cam=cam)
    if hi is None:
        return None, None
    import mpmath
    mpmath.mp.dps = check_precision + 10
    thr = mpmath.mpf(10) ** (-(base_precision - 2))
    refs, status = {}, {}
    for fld in lo:
        # The purpose of the guard is to certify the value we are about to write
        # as a DOUBLE. A purely relative test cannot do that for a value whose
        # true magnitude is zero: there the evaluation is pure cancellation
        # noise whose floor tracks the working precision (e.g. 1e-131 at 100
        # digits, 1e-231 at 200), so base and check precision never agree
        # relatively, however far the precision is pushed -- yet every one of
        # those values is zero to a double, and the reference is fine.
        #
        # So certify against the scale the test actually compares at: the field's
        # own largest magnitude. A value is converged if base and check agree
        # relatively, OR if they agree to far below the double-precision
        # resolution of that scale. A genuinely uncertain value (the oracle
        # disagreeing at, say, 1e-3 relative on an O(1) quantity) still fails.
        scale = mpmath.mpf(1)
        for pt_hi in hi[fld]:
            for b in pt_hi:
                scale = max(scale, abs(mpmath.mpf(b)))
        abs_thr = scale * mpmath.mpf(10) ** (-20)
        refs[fld], status[fld] = [], []
        for pt_lo, pt_hi in zip(lo[fld], hi[fld]):
            rrow, srow = [], []
            for a, b in zip(pt_lo, pt_hi):
                a, b = mpmath.mpf(a), mpmath.mpf(b)
                ok = (a == b) or abs(a - b) <= thr * (abs(b) + thr) \
                    or abs(a - b) <= abs_thr
                rrow.append(float(b))
                # Status convention matches eval_reference.evaluate_converged:
                # "ok" when base and check precision agree, otherwise the
                # check precision at which they still disagreed (a value the
                # caller must not trust -- see xc-generate_tests' build
                # fallback).
                srow.append("ok" if ok else int(check_precision))
            refs[fld].append(rrow)
            status[fld].append(srow)
    return refs, status
