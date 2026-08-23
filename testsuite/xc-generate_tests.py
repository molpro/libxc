#!/usr/bin/env python3
# MPL License Info
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

import os
import sys
import math
import pylibxc
from pylibxc import flags
from pylibxc.example_densities import test_data, test_data_dim
from subprocess import run, DEVNULL
import multiprocessing

from dataclasses import dataclass, field

# References are arbitrary-precision (50-digit mpmath via eval_reference),
# rounded to double for storage, so a passing test means the BUILD's
# double-precision output matches the true value to this relative tolerance.
# orders 0-1 keep the historical floors; order-2 (fxc) is allowed the same
# 5e-5 relative floor (2nd derivatives are more ill-conditioned in double).
thresholds = {
    'zk': 5e-8,
    'vrho': 5e-5, 'vsigma': 5e-5, 'vtau': 5e-5, 'vlapl': 5e-5,
    'v2rho2': 5e-5, 'v2rhosigma': 5e-5, 'v2rholapl': 5e-5, 'v2rhotau': 5e-5,
    'v2sigma2': 5e-5, 'v2sigmalapl': 5e-5, 'v2sigmatau': 5e-5,
    'v2lapl2': 5e-5, 'v2lapltau': 5e-5, 'v2tau2': 5e-5,
}


def _threshold(field):
    """Error tolerance for an output field. Orders 0-2 are enumerated above;
    the many order-3/4 (kxc/lxc) fields, progressively more ill-conditioned in
    double precision, fall back to a per-order default rather than being listed
    exhaustively."""
    if field in thresholds:
        return thresholds[field]
    order = _field_order(field)
    return {3: 5e-4, 4: 5e-3}.get(order, 5e-5)


def _field_order(field):
    "Derivative order of an output field (zk=0, vrho=1, v2rho2=2, ...)."
    if field == "zk":
        return 0
    if len(field) > 1 and field[1].isdigit():
        return int(field[1])
    return 1


# libxc capability flag a given output field's derivative order requires; a test
# for that field skips when the loaded build was compiled without it (so the
# reference set can go to any order regardless of the build's --maxorder, and
# per-functional order caps are honoured at run time).
_ORDER_CAP = {0: "_have_exc", 1: "_have_vxc", 2: "_have_fxc",
              3: "_have_kxc", 4: "_have_lxc"}

# Arbitrary-precision reference: digits, highest derivative order, and the
# per-functional wall-clock budget for the mpmath oracle before falling back to
# the (double-precision, self-referential) build for that case.
REF_DIGITS = 50
REF_MAX_ORDER = 2

# Every reference value must come from the symbolic pipeline. Where the oracle
# cannot produce a converged value the generator used to substitute the build's
# own double-precision output, which makes that reference self-referential: the
# test then compares the build against itself and can never fail, however wrong
# the build is. Worse, whether it happens depends on how heavily the machine is
# loaded (the oracle timeout below), so reference quality was not reproducible.
#
# In strict mode (the default) a case that cannot be fully resolved by the
# oracle is reported as a FAILURE and its file is left untouched, rather than
# being silently rewritten with build values.
STRICT_ORACLE = True
# Wall-clock budget for the oracle on one case. This used to be 90 s, which is
# less than some hybrids/mixes legitimately need: on a loaded machine the alarm
# fired on cases that would otherwise have succeeded, and the case then fell
# back to the build. With STRICT_ORACLE that is no longer silent -- it is a hard
# failure -- but the budget still has to be generous enough that a slow-but-fine
# case is not reported as broken. Override with --oracle-timeout.
REF_TIMEOUT_S = int(os.getenv("XC_REF_TIMEOUT_S", "1800"))
# The Maple oracle (maple_oracle set) evaluates a shipped series/piecewise no
# symbolic engine can differentiate; it is correct but slow (~35 s/point at
# order 2 with the precomputed series), so it gets its own generous per-system
# ceiling instead of the 90 s used for the interruptible AD/SymPy oracles.
MAPLE_ORACLE_TIMEOUT_S = 5400
# ...and its own higher precision. The deep-tail 2nd-sigma-derivative finite
# differences are catastrophically ill-conditioned (the true value is ~0 against
# ~1e59 curvature), so the precomputed order-24 series -- mathematically exact
# but a different rounding path than the .mpl's per-call form -- needs more
# guard digits than the 50 the AD/SymPy oracles use; 64 drops the deep-tail
# noise from ~1e9 to ~1e-8 (normalised ~1e-17, far under tolerance).
MAPLE_ORACLE_DIGITS = 64
# Second, independent run for certification: different Digits changes both the
# roundoff floor and the FD step, so agreement between the two runs is a real
# convergence statement (the Maple oracle has no internal one).
MAPLE_ORACLE_CHECK_DIGITS = 80
# Upper bound on how many point-chunks one (functional, system) is split into
# for the Maple oracle. Each chunk spawns its own Maple process (twice, for the
# two certification runs), so an unbounded split on a high -j fans out dozens of
# concurrent Maple processes and a single resource-starved one returning nothing
# collapses the whole functional to a build fallback. The verdict is
# chunk-independent (see _maple_certify), so this cap only trades a little
# parallelism for robustness; the AD/SymPy oracles are pure Python and uncapped.
MAPLE_MAX_CHUNKS = 8

_HERE = os.path.dirname(os.path.abspath(__file__))
_REPO = os.path.dirname(_HERE)
for _p in (os.path.join(_REPO, "scripts", "sympy2c"), os.path.join(_REPO, "python")):
    if _p not in sys.path:
        sys.path.insert(0, _p)

# Per-POINT threshold overrides, keyed by the full test name, mapping the flat
# array index of a single offending point to its relaxed threshold. Every other
# index in the case keeps the strict per-target default, so this does NOT loosen
# the case as a whole (unlike a scalar max-over-all check would). Use ONLY for a
# point whose error is a genuine double-precision floor at an extreme density
# (verified against an arbitrary-precision reference), not a code defect. Prefer
# fixing the functional over adding an entry here.
#   mgga_x_lak vsigma idx 59: the deepest N-atom tail point (down channel,
#   rho~1.6e-12) is at the FP floor -- a 50-digit reconstruction matches the
#   math exactly, the loss is in the double-precision derivative arrangement,
#   and the Maple-codegen reference misses the truth the same way. The huge
#   tail derivative (~2.7e7) loses ~13 digits to cancellation; the build sits
#   ~2.7e-3 from the oracle truth, so the threshold is 5e-3 (a real codegen
#   defect would be orders of magnitude larger, e.g. the AD arrangement is 75%).
#   r{2,4,pp}scan zk idx 19: the deepest N-atom point (rho~3.8e-10) -- the SCAN
#   energy density at the extreme tail loses ~7 digits in double (build ~2.1e-7
#   from the 50-digit truth) against the very tight 5e-8 zk threshold; the other
#   19 points stay strict.
#   gga_c_wi vsigma idx 57-59: the deepest point (rho_b~1.6e-12, below no screen
#   since wi's dens_threshold is 1e-14) -- all three vsigma components lose ~4x
#   to cancellation in double at the extreme tail (build ~1.8e-4 from truth).
case_point_thresholds = {
    'test_mgga_x_lak_N_2_vsigma'  : {59 : 5e-3},
    'test_mgga_x_r2scan_N_2_zk'   : {19 : 5e-7},
    'test_mgga_x_r4scan_N_2_zk'   : {19 : 5e-7},
    'test_mgga_x_rppscan_N_2_zk'  : {19 : 5e-7},
    'test_gga_c_wi_N_2_vsigma'    : {57 : 5e-4, 58 : 5e-4, 59 : 5e-4},
}

# Automatic deep-tail fxc-floor excusal (complements the hand list above). At a
# grid point whose smallest spin channel is below DEEP_TAIL_RHO, a second
# derivative can be catastrophically ill-conditioned: the double-precision build
# blows up (or loses many digits), and the value is genuinely below the
# double-precision floor -- either the build loses more than DEEP_TAIL_PROBE of
# relative accuracy, or even the arbitrary-precision oracle cannot pin the
# double value (its base- and check-precision results round differently).
#
# Such a point is relaxed to DEEP_TAIL_FLOOR_TOL, a FINITENESS-ONLY tolerance:
# the per-point normalised error |b-r|/(1+max|.|) is < 2 for any finite double,
# so this passes any finite build value while still catching NaN/Inf. Crucially
# this is COMPILER-INDEPENDENT -- an earlier version relaxed to twice THIS
# build's observed error, which a different compiler (e.g. CI's clang vs a local
# gcc) overshot at the same ill-conditioned point, so the same true value failed
# under one toolchain and passed under another.
# Guards so this cannot hide a real defect:
#   * only order-2 fields, and only at DEEP-TAIL points (rho < DEEP_TAIL_RHO) --
#     a code defect that also perturbs normal-density points still fails there,
#     where nothing is excused;
#   * only where the build already loses > DEEP_TAIL_PROBE OR the oracle itself
#     is unresolved -- a well-conditioned deep-tail point (build accurate to
#     ~machine precision) stays strict, so a bug that corrupts it is still seen;
#   * at most DEEP_TAIL_MAX_POINTS points per case (a broader failure is a bug,
#     not a floor) -- otherwise the case is left to fail and logged.
# North-star unchanged: fix the functional (cancellation-free / p-form) so the
# build is accurate and the point needs no excusal.
DEEP_TAIL_RHO = 1e-8
DEEP_TAIL_MAX_POINTS = 3
DEEP_TAIL_PROBE = 1e-8
DEEP_TAIL_FLOOR_TOL = 1e30

# These cases are problematic due to issues with floating point errors or
# large errors due to finite precision. The list is keyed by the full test
# name (including system and spin), so it is specific to the densities in
# pylibxc/example_densities.py. The current N-atom test set is well-behaved
# and needs no skips; entries can be added here if a fragile case appears.
skipped_cases = '''
'''.split()

# Functionals whose reference must come from the build, not the oracle. The AD
# oracle returns None for these (hybrids' mixed assembly; the mbr/task/th/regtpss
# expressions), so they fall through to the symbolic sp.diff oracle, which hangs
# on the order-2 derivative of the huge expression *non-interruptibly* (the C
# layer never returns to the SIGALRM handler, so REF_TIMEOUT_S cannot fire). The
# build output is the accurate Maple/codegen baseline for them; upgrading to
# arbitrary precision waits on AD-oracle coverage for these families.
oracle_build_only = {
    # EMPTY: every functional now carries arbitrary-precision references. The
    # last holdout, gga_x_wpbeh, moved to `maple_oracle` above -- its order-24
    # series window (a double-precision crutch for the orig form's 0/0 at s=0)
    # walls AD/SymPy symbolic differentiation, but Maple evaluates the shipped
    # series directly and matches the build to ~1e-13 at every order; the earlier
    # "series-free oracle disagrees with the build" problem was an artifact of
    # bypassing the series, not of the series itself.
    # (mbr, mbrxh_bg, regtpss, task, mtask, pjs18, lc_tmlyp, edmggah, vcml_rvv10,
    # lda_c_xalpha, lda_x_rae, hyb_mgga_x_js18, hyb_mgga_xc_b0kcis and the
    # opwlyp_d/otpss_d/pw6b95/pwb6k computed-setter mixes have been REMOVED -- all
    # resolve to arbitrary precision. b0kcis was a genuine C double-eval bug the
    # oracle exposed (its info struct carried the kcis kernel via &work_mgga AND
    # it was a mix, so xc_mgga ran kcis once as the kernel and again through
    # xc_mix_func: 0.75*b88 + 2*kcis); fixed by NULLing the kernel in
    # src/mgga_c_kcis.c. js18 needed the standalone-CAM fix: _penv_from now resolves
    # cam_alpha/beta/omega through the resolver's _cam_env (which replicates the
    # cam_sr setter: ext 'a' -> cam_beta, ext 'omega' -> cam_omega) instead of a
    # bare ext-name lookup that missed the renamed coefficients.
    # The resolver gained: the array-element branch (flat scalar key -> assembled
    # struct-array list -> C default, all 0-based; task/mtask read the struct
    # field params_a_task_anu[i] while their ext-params are the differently-named
    # anu0..2/bnu0..4); ext_params override into _computed_params; inline
    # get_ext_param in params->field expressions (lda_c_xalpha's alpha =
    # 1.5*ext - 1); computed-setter keys made authoritative even standalone; and
    # a single source-ordered setter pass with Python-keyword-local aliasing that
    # fixed the interleaved pbe_lambda kappa (also corrected the previously
    # silently-wrong gga_x_lambda_{oc2,ch,lo}_n references). mgga_x_th moved to
    # fxc_tail_unstable -- orders 0-1 arbitrary-precision, only the build v2sigma2
    # blows up at the deepest tail. Earlier removals: gga_x_kgg99, gga_xc_beefvdw,
    # mgga_x_mk00b, hyb_lda_xc_b93/lda0, apbe0/hapbe/wc04/wp04/camh_b3lyp/
    # rcam_b3lyp -- xc_mix_init mixes the mix oracle now resolves.)
}

# Functionals whose build fxc (2nd derivative) is numerically unstable at the
# deepest density-tail points -- the double-precision arrangement blows up as
# ~1/rho^k where the true value is 0 or tiny (e.g. gga_k_vw v2sigma2 -> 8e17 at
# rho~4e-10 against a true 0). The arbitrary-precision oracle is correct; the
# BUILD cannot represent these. Capped at order 1 so the suite stays green.
# TRIAGE: fix the .mpl/.py fxc stability (north-star) or accept a principled
# deep-tail relaxation for order-2 fields.
# The TF-lambda-vW family (gga_k_tflw variants) was removed here after the
# squared-reduced-gradient port (gga_kinetic_p): their fxc is now
# cancellation-free and passes the order-2 tolerance library-wide, so they
# carry full arbitrary-precision order-2 references.
# EMPTY: no functional is capped at order 1 any more. The deep-tail fxc
# instability that motivated this set is now handled point-wise by the automatic
# excusal (DEEP_TAIL_RHO above): every functional carries full order-2
# references, and the 1-3 deepest points where a second derivative exceeds the
# double-precision floor (near-empty channel, rho < 1e-8) have their per-point
# threshold relaxed, with the reference kept at the true oracle value. A
# diagnostic of all 45 former members confirmed each fails at <= 3 such points
# (never the > DEEP_TAIL_MAX_POINTS that would signal a real defect), and the DK
# kinetic family was additionally p-formed so only its single v2sigma2 point is
# excused. The gga_k_tflw family, removed earlier after the p-form port, stays
# fully cancellation-free and needs no excusal at all.
# North-star for the excused points remains a cancellation-free .mpl rewrite
# (p-form / mgga_p / mgga_q), which retires each excusal as it lands.
fxc_tail_unstable = set()

# Functionals whose build fxc (2nd derivative) segfaults, so no order-2 reference
# can be produced and their fxc must not be computed. Capped at order 1 (vxc)
# until the crash is fixed.
#
# Formerly held four tau-only meta-GGAs (mgga_x_mbr, mgga_x_mbrxh_bg,
# mgga_x_regtpss, mgga_x_th). Their crash was a harness bug, not a codegen
# defect: work_mgga_inc.c passed &VAR(lapl, ip, 0) to the kernel even when the
# functional does not use the laplacian and the caller supplies lapl == NULL,
# forming the bogus non-NULL address ip*p->dim.lapl that the kernel's own
# (lapl != NULL) guard could not detect. It only surfaced at fxc because the
# unused-at-lower-order local `la` is dead-code-eliminated for exc/vxc. Fixed in
# work_mgga_inc.c (propagate NULL), so all four now produce order-2 references.
fxc_build_broken = set()


@dataclass
class Context:
    srcdir: str
    builddir: str
    destdir: str
    funcs: list[str] = field(default_factory=list)
    xc_reg: str = ""

if sys.stdout.isatty():
    NC = "\033[0m"
    RED = "\033[1;31m"
    GREEN = "\033[1;32m"
    YELLOW = "\033[1;33m"
else:
    NC = RED = GREEN = YELLOW = ""

def _split_indices(npts, k):
    "Split range(npts) into k contiguous, near-equal index chunks."
    k = max(1, min(k, npts))
    base, rem = divmod(npts, k)
    out, start = [], 0
    for i in range(k):
        size = base + (1 if i < rem else 0)
        out.append(list(range(start, start + size)))
        start += size
    return [c for c in out if c]


def _build_chunk_tasks(ctx, pairs, nproc):
    """Turn the (functional, system) work list into _oracle_chunk tasks,
    splitting each pair's grid points into several chunks ONLY when there are few
    pairs relative to the worker count. With many pairs (a full regeneration)
    every pair is a single chunk, so the parallel unit and per-worker cost are
    exactly as before; with few pairs (a single-functional regeneration) the
    points fan out so the pool still fills. Returns (tasks, expected, meta) where
    expected[refname] is the chunk count to collect and meta[refname] is
    (func, system, dir)."""
    import numpy as _np
    from collections import Counter

    n = max(1, len(pairs))
    tasks, meta, expected = [], {}, Counter()
    for (_ctx, func, system, dir, refname) in pairs:
        meta[refname] = (func, system, dir)
        npts = _np.asarray(test_data[system]["rho"]).shape[0]
        split = max(1, min(npts, round(nproc / n)))
        if _uses_maple_oracle(func, len(_np.asarray(test_data[system]["rho"]).shape)):
            split = min(split, MAPLE_MAX_CHUNKS)
        for chunk in _split_indices(npts, split):
            tasks.append((ctx, func, system, dir, refname, chunk))
            expected[refname] += 1
    return tasks, expected, meta


def _assemble_write(ctx, meta_entry, refname, chunks):
    "Stitch a functional's oracle chunks back into grid order and write the file."
    func, system, dir = meta_entry
    tags = {c[0] for c in chunks}
    if "none" in tags:
        # No oracle handled this functional: hand None to _write_ref, which (in
        # strict mode) reports it rather than writing self-referential values.
        oref = ostat = None
    elif "maple" in tags:
        # Reassemble the raw base values and base/check differences, then certify
        # ONCE with the global (all-point) field scale -- so the verdict does not
        # depend on how the points were split across Maple processes.
        chunks = sorted(chunks, key=lambda c: c[1])
        base, diff = {}, {}
        for _tag, _idx0, cbase, cdiff in chunks:
            for k, vals in cbase.items():
                base.setdefault(k, []).extend(vals)
            for k, vals in cdiff.items():
                diff.setdefault(k, []).extend(vals)
        oref, ostat = _maple_certify(base, diff)
    else:
        chunks = sorted(chunks, key=lambda c: c[1])  # by first grid index
        oref, ostat = {}, {}
        for _tag, _idx0, coref, costat in chunks:
            for k, vals in coref.items():
                oref.setdefault(k, []).extend(vals)
            if costat:
                for k, vals in costat.items():
                    ostat.setdefault(k, []).extend(vals)
        if not ostat:
            ostat = None
    return _write_ref(ctx, func, system, dir, refname, oref, ostat)


def main(ctx: Context, nproc=os.cpu_count()):
    "Main driver. Run reference generation in parallel."

    if ctx.funcs:
        ctx.funcs = ctx.funcs
    else:
        # Collect the list of functionals from the header
        with open(os.path.join(ctx.builddir, "../src/xc_funcs.h"), "r") as f:
            ctx.funcs = [
                line.split()[1].lower()[len("xc_") :]
                for line in f
                if line.startswith("#define")
            ]

    pairs = list(enum_refs(ctx))
    tasks, expected, meta = _build_chunk_tasks(ctx, pairs, nproc)

    failed = []
    got = {}
    done = 0
    # Spawned (not forked) workers: module globals such as REF_TIMEOUT_S are
    # bound from os.environ at import, and main() sets the environment AFTER
    # importing -- only a re-importing start method sees the update. Under
    # `fork` the children inherit the stale global and --oracle-timeout is a
    # silent no-op. Pin it rather than depend on the platform default.
    with multiprocessing.get_context("spawn").Pool(processes=nproc) as p:
        # Chunks of the same functional come back interleaved with others'; a
        # functional's file is written once its last chunk arrives, so at most a
        # handful of partial results are held at any time.
        for refname, payload in p.imap_unordered(_oracle_chunk, tasks, chunksize=1):
            bucket = got.setdefault(refname, [])
            bucket.append(payload)
            if len(bucket) < expected[refname]:
                continue
            r, rcode = _assemble_write(ctx, meta[refname], refname, got.pop(refname))
            if rcode != 0:
                print(f"{RED}F{NC}", end="", flush=True)
                failed.append(r)
            else:
                print(f"{GREEN}.{NC}", end="", flush=True)
            done += 1
            if done % 80 == 0:
                print()

        if done % 80 != 0:
            print()

    if failed:
        print(f"{RED}{len(failed)} failure(s){NC}")
        for f in failed:
            print(f)
        return 1
    else:
        print(f"{GREEN}Done.{NC}")
        return 0


def func_dim(func: str) -> int:
    "Spatial dimension (1, 2 or 3) the functional is defined for."
    f = pylibxc.LibXCFunctional(func, 1).get_flags()
    if f & flags.XC_FLAGS_1D:
        return 1
    if f & flags.XC_FLAGS_2D:
        return 2
    return 3


def enum_refs(ctx: Context):
    "Generate the test set from the list of functionals."
    for func in ctx.funcs:
        if func.startswith("hyb"):
            _, fn_kind, component, *rest = func.split("_")
            dir = f"hyb_{fn_kind}_{component}"
        else:
            fn_kind, component, *rest = func.split("_")
            dir = f"{fn_kind}_{component}"

        # Only test each functional on systems of its own dimensionality.
        dim = func_dim(func)
        for system in test_data:
            if test_data_dim[system] != dim:
                continue
            refname = f"test_{func}_{system}.py"
            yield (
                ctx,
                func,
                system,
                dir,
                refname,
            )


# Memoised constituent references. A constituent (gga_x_kt1, lda_c_vwn, ...)
# recurs across many mixes, and its AD evaluation -- symbolic assembly plus
# arbitrary-precision jets -- is the cost. The key is (name, spin, PARAMETERS,
# inputs): the parameters matter because the SAME functional can enter different
# mixes with different values (a parent imposes its range-separation omega on a
# CAM constituent), so a name-only cache would serve one mix a reference
# computed for another's parameters. The input arrays are keyed too so distinct
# systems never collide. Per-process (each Pool worker memoises its own chunk).
_CONSTITUENT_REF_CACHE = {}


def _constituent_ref(cname, nspin, inp, cam, ext_params):
    "AD-oracle reference for one mix constituent, memoised parameter-aware."
    isig = tuple(inp[k].tobytes() for k in ("rho", "sigma", "lapl", "tau")
                 if inp.get(k) is not None)
    ekey = tuple(sorted(ext_params.items())) if ext_params else ()
    key = (cname, nspin, cam, ekey, isig)
    if key not in _CONSTITUENT_REF_CACHE:
        import ad_reference as ADR
        _CONSTITUENT_REF_CACHE[key] = ADR.evaluate_converged(
            cname, nspin, inp["rho"], sigma=inp.get("sigma"),
            lapl=inp.get("lapl"), tau=inp.get("tau"),
            max_order=REF_MAX_ORDER, base_precision=REF_DIGITS,
            ext_params=ext_params, cam=cam)
    return _CONSTITUENT_REF_CACHE[key]


def _mix_oracle_refs(func, nspin, inp):
    """Arbitrary-precision reference for an xc_mix_init mix as the linear
    combination, with the build's own coefficients, of its constituents'
    AD-oracle references. A mix has no single symbolic f, but each constituent
    does, so the mix reference is exact if every constituent resolves.

    Returns (refs, status) in ad_reference's nested {field: [[per-comp] per
    point]} form, or (None, None) when func is not a mix or any constituent
    cannot be AD'd (then the caller falls back to the build). Each constituent
    is evaluated with the ACTUAL parameters the parent imposed on it -- its
    reparametrised ext-params and its range-separation cam -- so a mix that
    reuses a functional with different settings combines the right pieces."""
    import maple_reference as MR
    mix = MR._mix_constituents(func, nspin)
    if not mix:
        return None, None
    refs, status = {}, {}
    for cname, coef, _cam, _ext in mix:
        cref, cst = _constituent_ref(cname, nspin, inp, _cam, _ext)
        if cref is None:
            return None, None
        for field, perpt in cref.items():
            dvals = refs.setdefault(field, [])
            dstat = status.setdefault(field, [])
            for ip, comps in enumerate(perpt):
                while ip >= len(dvals):
                    dvals.append([]); dstat.append([])
                # A constituent that carries no status for this field has NOT
                # been vouched for -- fabricating "ok" here would route the mix
                # around the strict per-value gate exactly where nobody
                # certified the value.
                srow = (cst[field][ip] if cst and field in cst
                        else ["uncertified"] * len(comps))
                for k, val in enumerate(comps):
                    term = coef * float(val)
                    if k < len(dvals[ip]):
                        dvals[ip][k] += term
                        if srow[k] != "ok":
                            dstat[ip][k] = srow[k]
                    else:
                        dvals[ip].append(term)
                        dstat[ip].append(srow[k])
    return refs, status


def oracle_ref(func, nspin, inp, has_exc=True):
    """Arbitrary-precision reference (orders 0..REF_MAX_ORDER) for one
    (functional, system) via the mpmath oracles. Returns
    ({field: flat list of doubles}, {field: flat list of per-point status}) or
    (None, None) when no oracle can handle the functional or it exceeds
    REF_TIMEOUT_S, in which case the caller falls back to the build output.

    ``has_exc=False`` marks a *_vxc (potential-valued) functional: only the AD
    oracle evaluates f as the potential (vrho). The symbolic oracle treats f as
    an energy density and would emit a wrong vrho, so it is NOT used as a
    fallback there -- an unhandled vxc case falls back to the build instead."""
    import signal

    def _on_timeout(signum, frame):
        raise TimeoutError(func)

    try:
        import eval_reference as ER
    except Exception:
        return None, None
    # The oracles index every input per point AND per component (rho[ip][j]),
    # so they need the (npoints, ncomponents) layout. test_data stores the
    # SPIN-UNPOLARISED systems as flat (npoints,) arrays, which made
    # eval_reference.clamp_point raise IndexError -- swallowed below into a
    # (None, None) build fallback, silently making EVERY unpolarised reference
    # self-referential. Normalise to 2D; the polarised (npoints, n) arrays are
    # already in that shape and pass through untouched.
    import numpy as _np
    _npts = _np.asarray(inp["rho"]).shape[0]
    inp = {k: (_np.asarray(v).reshape(_npts, -1) if v is not None else None)
           for k, v in inp.items() if k in ("rho", "sigma", "lapl", "tau")}

    old = signal.signal(signal.SIGALRM, _on_timeout)
    signal.alarm(REF_TIMEOUT_S)
    try:
        # An xc_mix_init mix has no single symbolic f, so neither the AD nor the
        # symbolic oracle can touch it -- and the symbolic attempt can stall
        # non-interruptibly. Combine the constituents' references directly and
        # skip both. _mix_oracle_refs returns None immediately for a non-mix, so
        # this is free for ordinary functionals.
        refs, status = _mix_oracle_refs(func, nspin, inp)
        # Otherwise prefer the fast arbitrary-precision AD oracle; it returns
        # (None, None) for functionals/orders it can't handle (vxc-direct,
        # order > 1), then fall back to the slow symbolic sp.diff oracle.
        if refs is None:
            try:
                import ad_reference as ADR
                refs, status = ADR.evaluate_converged(
                    func, nspin, inp["rho"], sigma=inp.get("sigma"),
                    lapl=inp.get("lapl"), tau=inp.get("tau"),
                    max_order=REF_MAX_ORDER, base_precision=REF_DIGITS)
            except Exception:
                refs = status = None
        if refs is None and has_exc:
            refs, status = ER.evaluate_converged(
                func, nspin, inp["rho"], sigma=inp.get("sigma"),
                lapl=inp.get("lapl"), tau=inp.get("tau"),
                max_order=REF_MAX_ORDER, base_precision=REF_DIGITS)
        if refs is None:
            return None, None
        flat = {k: [v for pt in vals for v in pt] for k, vals in refs.items()}
        fstat = {k: [v for pt in vals for v in pt] for k, vals in status.items()}
        return flat, fstat
    except Exception:
        return None, None
    finally:
        signal.alarm(0)
        signal.signal(signal.SIGALRM, old)


# Functionals no symbolic oracle (AD / SymPy) can differentiate, but whose math
# Maple evaluates directly: gga_x_wpbeh windows an order-24 Taylor series around
# s=0 (a double-precision crutch for the exact form's 0/0). my_piecewise3 is
# eager, so AD/SymPy must expand and differentiate that series and wall; Maple
# evaluates the shipped piecewise itself and takes high-Digits finite-difference
# derivatives, which reproduce the build to ~1e-13 at every order -- but slowly
# (~150 s/point at order 2), hence its own wide timeout below.
maple_oracle = {"gga_x_wpbeh"}


# A mix whose CONSTITUENT is a maple_oracle functional (HSE and LC-wPBE are
# gga_x_wpbeh + gga_c_pbe) cannot be assembled by the AD mix oracle -- the
# wpbeh piece has no symbolic form -- so under STRICT_ORACLE it was refused and
# its reference silently kept the stale build value. The Maple oracle's own mix
# path (maple_reference._generate_mix) combines the constituents' Maple
# references, so route these through it too. Detected structurally (via the mix
# resolver) rather than hardcoded, so a future wpbeh mix is handled automatically;
# a functional whose computed-setter mix the resolver cannot unpack is simply not
# matched (and stays a strict build-fallback, as before).
_MAPLE_ROUTE_CACHE = {}


def _uses_maple_oracle(func, nspin):
    "True if func is a maple_oracle functional or a mix that contains one."
    if func in maple_oracle:
        return True
    key = (func, nspin)
    if key not in _MAPLE_ROUTE_CACHE:
        hit = False
        try:
            import maple_reference as MR
            mix = MR._mix_constituents(func, nspin)
            hit = bool(mix) and any(c[0] in maple_oracle for c in mix)
        except Exception:
            hit = False
        _MAPLE_ROUTE_CACHE[key] = hit
    return _MAPLE_ROUTE_CACHE[key]


def maple_oracle_ref(func, nspin, system, point_indices=None):
    """Raw two-run Maple evaluation for a `maple_oracle` functional. Returns
    ({field: [flat base values]}, {field: [flat |base - check|]}) -- the base
    reference values and the per-value disagreement between the two independent
    runs -- or (None, None) on any error or an incomplete result (a point/field
    the Maple run did not emit).

    ``point_indices`` restricts evaluation to a contiguous subset of the system's
    grid points (the generator fans one functional's points across processes);
    the returned flat lists then cover only those points, in their own order.

    Certification is DEFERRED to _maple_certify(): the Maple oracle is a
    single-shot finite-difference evaluation with no built-in convergence test,
    so it is run twice, at MAPLE_ORACLE_DIGITS and MAPLE_ORACLE_CHECK_DIGITS
    (which also changes the FD step), and a value is trusted only where the two
    agree. But the scale-aware agreement floor is tied to the field's GLOBAL
    magnitude (all grid points), which a single point-chunk does not know --
    certifying here would make the verdict depend on how the points were chunked
    across processes. The two quantities returned instead (the base value and the
    base/check difference) are both per-point and chunk-independent; the caller
    reassembles all chunks and certifies once, globally."""
    def _run(digits):
        import maple_reference as MR
        results, npts, errs = MR.generate(
            func, nspin, system, REF_MAX_ORDER, digits, fd=True,
            timeout=MAPLE_ORACLE_TIMEOUT_S, point_indices=point_indices)
        if errs or not results:
            return None, None
        flat = {}
        for field, perpt in results.items():
            vals = []
            for ip in range(npts):
                comps = perpt.get(ip)
                if comps is None:
                    return None, None
                vals.extend(float(c) for c in comps)
            flat[field] = vals
        return flat, npts

    try:
        base, npts = _run(MAPLE_ORACLE_DIGITS)
        if base is None:
            return None, None
        check, _ = _run(MAPLE_ORACLE_CHECK_DIGITS)
        if check is None:
            return None, None
    except Exception:
        return None, None

    diff = {}
    for field, vals in base.items():
        cvals = check.get(field)
        if cvals is None or len(cvals) != len(vals):
            return None, None
        diff[field] = [abs(a - b) for a, b in zip(vals, cvals)]
    return base, diff


def _maple_certify(base, diff):
    """Turn reassembled Maple base values and per-value base/check differences
    into the ({field: values}, {field: status}) shape oracle_ref returns. The
    absolute-agreement floor is tied to the field's GLOBAL magnitude (over every
    reassembled point), so the verdict is identical however the points were
    chunked across processes -- and identical to a single unchunked run."""
    flat, fstat = {}, {}
    for field, vals in base.items():
        diffs = diff[field]
        # Scale-aware agreement, mirroring the AD oracle's criterion: a relative
        # test plus an absolute floor tied to the field's own scale, so a value
        # that is zero at the scale it is used at is certifiable.
        scale = max((abs(v) for v in vals), default=1.0) or 1.0
        # A finite-difference 2nd derivative crossing zero cannot be pinned to
        # the tight 1e-13 relative bar -- cancellation swamps it -- yet the value
        # is still far more precise than the test needs. The test compares the
        # build to the stored reference at _threshold(field), normalised by
        # (1 + max|.|) ~ (1 + scale); certify a value once the two runs agree to
        # a thousandth of THAT resolution. This is chunk-independent (scale is
        # global) and cannot mask a build defect: the reference is the oracle
        # value, so a wrong build still fails the ordinary tolerance. A genuine
        # non-convergence (runs disagree above this floor) stays "fd-noise".
        test_floor = _threshold(field) * (1.0 + scale) * 1e-3
        stat = ["ok" if (d == 0.0
                         or d <= 1e-13 * (abs(v) + 1e-13)
                         or d <= test_floor)
                else "fd-noise"
                for v, d in zip(vals, diffs)]
        flat[field] = vals
        fstat[field] = stat
    return flat, fstat


def _slice_inp(inp, idx):
    "The input dict restricted to grid-point indices `idx` (rows preserved)."
    import numpy as _np
    idx = list(idx)
    out = {}
    for k in ("rho", "sigma", "lapl", "tau"):
        v = inp.get(k)
        out[k] = None if v is None else _np.asarray(v)[idx]
    return out


def _oracle_chunk(args):
    """Compute the arbitrary-precision oracle references for a CONTIGUOUS SUBSET
    of one (functional, system)'s grid points. This is the parallel unit: for a
    full regeneration each (functional, system) is a single chunk (identical to
    the historical behaviour), but a single-functional regeneration splits its
    points across the pool so the few systems still saturate every core -- most
    valuable for the slow Maple oracle, where each point is independent work.

    Returns (refname, payload); payload is ("ok", first_idx, oref, ostat) or
    ("none", first_idx) when no oracle handles this functional (build fallback).
    The caller stitches a functional's chunks back together in grid order."""
    ctx, func, system, dir, refname, idx = args

    inp_full = test_data[system]
    nspin = len(inp_full["rho"].shape)
    feval = pylibxc.LibXCFunctional(func, nspin)
    do_v = REF_MAX_ORDER >= 1 and feval._have_vxc
    do_e = feval._have_exc

    if _uses_maple_oracle(func, nspin):
        # The Maple oracle returns RAW base values + base/check differences; the
        # scale-aware verdict is deferred to _maple_certify at assembly, where
        # the field scale spans every reassembled point (chunk-independent).
        base, diff = maple_oracle_ref(func, nspin, system, point_indices=idx)
        if base is None:
            return (refname, ("none", idx[0]))
        return (refname, ("maple", idx[0], base, diff))
    elif (do_e or do_v) and func not in oracle_build_only:
        oref, ostat = oracle_ref(func, nspin, _slice_inp(inp_full, idx),
                                 has_exc=do_e)
    else:
        oref, ostat = (None, None)

    if oref is None:
        return (refname, ("none", idx[0]))
    return (refname, ("ok", idx[0], oref, ostat))


def _write_ref(ctx, func, system, dir, refname, oref, ostat):
    """Assemble and write the reference file for one (functional, system) from
    the build output and the (already computed, possibly multi-chunk) oracle
    references `oref`/`ostat`. This is the serial tail of generation -- the build
    evaluation is a sub-millisecond double-precision call; the expensive
    arbitrary-precision oracle work was done in parallel by _oracle_chunk."""
    # Input data for the system
    inp = test_data[system]
    nspin = len(inp["rho"].shape)

    # Get the functional
    feval = pylibxc.LibXCFunctional(func, nspin)

    # Emit derivatives only up to REF_MAX_ORDER: the oracle produces references
    # for orders 0..REF_MAX_ORDER, so gating the build's do_* on it keeps the
    # generated tests in lockstep (otherwise fxc tests would be emitted with
    # build-derived order-2 references even when the oracle stops at order 1).
    # Cap functionals whose fxc build segfaults or is tail-unstable at order 1.
    hi = 1 if func in fxc_build_broken or func in fxc_tail_unstable else REF_MAX_ORDER
    do_l = hi >= 4 and getattr(feval, "_have_lxc", False)
    do_k = hi >= 3 and getattr(feval, "_have_kxc", False)
    do_f = hi >= 2 and getattr(feval, "_have_fxc", False)
    do_v = REF_MAX_ORDER >= 1 and feval._have_vxc
    do_e = feval._have_exc

    # Evaluate the data (the BUILD; the test re-runs this and compares to the
    # arbitrary-precision reference written below)
    out = feval.compute(inp, do_exc=do_e, do_vxc=do_v, do_fxc=do_f, do_kxc=do_k, do_lxc=do_l)

    # Reference values: arbitrary precision where the oracle can compute them
    # (oref/ostat, computed in parallel by _oracle_chunk), otherwise the build's
    # own double-precision output (so every case still gets a test; only the few
    # unportable/heavy ones stay self-referential).
    build_flat = {k: list(out[k].flatten()) for k in out}
    # Anything that would have silently come from the build lands here.
    fellback = []
    if oref is None:
        fellback.append("the oracle could not evaluate this functional at all "
                        "(unsupported, errored, or exceeded REF_TIMEOUT_S)")
    if oref is not None:
        # Per-point convergence guard: the oracle marks a point/channel "ok"
        # when its base- and check-precision evaluations agree, otherwise it
        # could not vouch for that value (an ill-conditioned tail point where
        # even arbitrary-precision AD does not self-converge). Trusting such a
        # value would bake a wrong reference into the suite (e.g. mgga_x_mbeefvdw
        # N zk idx 18-19). Fall back to the build's own double-precision output
        # there, exactly as the whole-case fallback does when the oracle can't
        # run at all -- that point becomes self-referential rather than wrong.
        refvals = {}
        # Flat indices the oracle could not certify (base/check runs disagree).
        # Whether these block regeneration is decided AFTER the deep-tail excusal
        # below: an unresolved *deep-tail* order-2 point is exactly what the
        # excusal handles (build value + finiteness-only tolerance), so only
        # non-excused non-convergence is a genuine, blocking failure.
        noise_by_field = {}
        for k, ovals in oref.items():
            bvals = build_flat.get(k)
            sflags = ostat.get(k) if ostat else None
            refvals[k] = [
                v if (sflags is None or sflags[i] == "ok" or bvals is None)
                else bvals[i]
                for i, v in enumerate(ovals)
            ]
            if sflags is not None and bvals is not None:
                noise = {i for i, x in enumerate(sflags) if x != "ok"}
                if noise:
                    noise_by_field[k] = noise
    else:
        refvals = build_flat
        noise_by_field = {}

    # Automatic deep-tail fxc-floor excusal (see DEEP_TAIL_RHO). Build a per-case
    # {target: {flat_index: relaxed_threshold}} for order-2 points at a near-empty
    # channel where the converged oracle and the double-precision build diverge.
    auto_pt = {}
    if oref is not None:
        import numpy as _np
        _rho = _np.asarray(inp["rho"])
        pdens = _rho if _rho.ndim == 1 else _rho.min(axis=1)
        npt = len(pdens)
        for target, ovals in oref.items():
            if not target.startswith("v2"):
                continue
            bvals = build_flat.get(target)
            sflags = ostat.get(target) if ostat else None
            if bvals is None or not ovals:
                continue
            rv = refvals[target]
            ncomp = max(1, len(bvals) // npt)
            scale = 1.0 + max(max(abs(x) for x in bvals),
                              max(abs(x) for x in rv))
            ovr, pts = {}, set()
            for i in range(len(bvals)):
                ip = i // ncomp
                if ip >= npt or pdens[ip] >= DEEP_TAIL_RHO:
                    continue
                # A deep-tail second derivative is below the double-precision
                # floor when this build deviates from the oracle value by more
                # than DEEP_TAIL_PROBE -- an ill-conditioned point that another
                # compiler may miss to a different (finite) degree, relaxed to a
                # finiteness-only tolerance rather than to this build's error.
                # Compare against the ORACLE value (ovals), NOT refvals: where
                # the oracle could not pin the last-digit rounding (status not
                # "ok") refvals is the build itself, so |build - refvals| would
                # be 0 and hide a genuine loss -- yet the oracle value is still
                # accurate to ~1 ULP, far below DEEP_TAIL_PROBE, so a truly
                # well-conditioned point (e.g. lda_x, build == oracle to ~1e-18)
                # is left strict and only a genuine floor point is relaxed.
                # Excuse a deep-tail order-2 value when the build diverges from
                # the oracle beyond the double-precision floor OR the oracle
                # itself could not pin it (base/check disagree): both mean the
                # point is genuinely untestable at this density, per the
                # DEEP_TAIL design. Comparing against the ORACLE value (ovals),
                # not refvals, keeps a well-conditioned point (build == oracle to
                # ~1e-18) strict.
                e = abs(bvals[i] - ovals[i]) / scale
                unresolved = sflags is not None and sflags[i] != "ok"
                if e > DEEP_TAIL_PROBE or unresolved:
                    ovr[i] = DEEP_TAIL_FLOOR_TOL
                    pts.add(ip)
            if not ovr:
                continue
            if len(pts) <= DEEP_TAIL_MAX_POINTS:
                auto_pt[target] = ovr
                print(f"AUTO-EXCUSE {func} {system} {target}: "
                      f"{len(pts)} deep-tail floor point(s), {len(ovr)} value(s)")
            else:
                print(f"WARNING {func} {system} {target}: {len(pts)} deep-tail "
                      f"points exceed the excusal cap -- NOT excused (investigate)")

    # Reconcile the oracle's non-convergence with the deep-tail excusal: a value
    # the oracle could not certify blocks regeneration ONLY if it was not
    # deep-tail-excused above. A non-excused case is a normal-density point (the
    # oracle should converge there) or more deep-tail points than the excusal cap
    # allows -- either is a real problem, not a floor, so it must still block.
    for k, noise in noise_by_field.items():
        blocking = noise - set(auto_pt.get(k, {}))
        if blocking:
            fellback.append(
                f"{k}: {len(blocking)}/{len(oref[k])} value(s) did not converge "
                f"in the oracle and are not deep-tail-excused, so they would "
                f"come from the build")

    test_targets = []
    # Check if functional has energy
    if "zk" in out:
        test_targets.append('zk')
    # Add all first derivatives
    for target in out:
        if target.startswith('v'):
            test_targets.append(target)

    os.makedirs(os.path.join(ctx.destdir, dir), exist_ok=True)
    # Every reference value must come from the symbolic pipeline. A target the
    # oracle never produced would silently be written from the build.
    for target in test_targets:
        if target not in refvals and target in out:
            fellback.append(f"{target}: the oracle produced no value for this field")

    if fellback and STRICT_ORACLE:
        # Leave the existing reference file untouched: rewriting it with build
        # values would replace an arbitrary-precision reference with a
        # self-referential one, which is strictly worse than not regenerating.
        why = "; ".join(fellback[:4]) + (" ..." if len(fellback) > 4 else "")
        return (f"{refname}: NOT regenerated -- would have taken values from the "
                f"build ({why})", 1)

    dest = os.path.join(ctx.destdir, dir, refname)

    # Write to a sibling temp file and os.replace() it into place at the end:
    # a failure mid-write must not leave a truncated-but-syntactically-valid
    # file at the final path, where pytest would silently run FEWER tests.
    tmp_dest = dest + ".tmp"

    # Write the test file header
    fout = open(tmp_dest, 'w')
    fout.write(f'''
import pylibxc
import pytest
from pylibxc.example_densities import test_data
''')

    # Write the tests
    for target in test_targets:
        if f'test_{func}_{system}_{nspin}_{target}' in skipped_cases:
            print(f'Skipping test_{func}_{system}_{nspin}_{target}')
            continue
        rvals = refvals.get(target)
        if rvals is None:
            rvals = list(out[target].flatten())
        # NaN in the (arbitrary-precision) REFERENCE means a genuine
        # singularity -> no test. A finite reference with a NaN build output is
        # NOT skipped: the test must run so it catches the build defect.
        if any(math.isnan(x) for x in rvals):
            print(f'NaN found in reference {func=} {system=} {target=}, not generating test')
            fout.write(f'\n# test_{func}_{system}_{nspin}_{target}() not generated due to NaN in reference data\n')
            continue
        _o = _field_order(target)
        _dv = "feval._have_vxc" if _o >= 1 else "False"
        _df = "feval._have_fxc" if _o >= 2 else "False"
        _dk = "feval._have_kxc" if _o >= 3 else "False"
        _dl = "feval._have_lxc" if _o >= 4 else "False"
        fout.write(f'''

def test_{func}_{system}_{nspin}_{target}():
    # Prepare the input
    inp = test_data["{system}"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("{func}", {nspin})
    if not feval.{_ORDER_CAP[_field_order(target)]}:
        pytest.skip("build lacks the derivative order for {target}")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc={_dv}, do_fxc={_df}, do_kxc={_dk}, do_lxc={_dl})
    ns = pylibxc.array_backend.array_namespace(out["{target}"])
    tgt = out["{target}"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([''')
        # Print out the (arbitrary-precision) reference values
        for ival, val in enumerate(rvals):
            if ival:
                fout.write(', ')
            # Special handling for NaN
            if math.isnan(val):
                fout.write(f'"nan"')
            else:
                fout.write(f'{val:.15e}')
        fout.write(']))\n')
        # Auto-detected deep-tail floor points first, then the hand-maintained
        # entries (which are deliberately chosen and take precedence).
        overrides = dict(auto_pt.get(target, {}))
        overrides.update(
            case_point_thresholds.get(f'test_{func}_{system}_{nspin}_{target}', {}))
        if overrides:
            # Per-point thresholds: the strict per-target default everywhere
            # except the listed floor-point indices. The normalised per-point
            # error is checked against its own threshold, so the rest of the
            # case stays fully checked (a scalar max-over-all would not).
            npts = len(rvals)
            tol = [_threshold(target)] * npts
            for idx, t in overrides.items():
                tol[idx] = t
            fout.write('    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))\n')
            fout.write('    tol = ns.full_like(tgt, ns.asarray([' + ', '.join(f'{t:.15e}' for t in tol) + ']))\n')
            fout.write('    assert bool(ns.all(err < tol))\n')
        else:
            fout.write('    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))\n')
            fout.write(f'    assert error < {_threshold(target)}\n')
    fout.close()
    os.replace(tmp_dest, dest)

    return (refname, 0)


if __name__ == "__main__":
    from argparse import ArgumentParser

    parser = ArgumentParser(
        description="Regenerate the reference files for the testsuite"
    )

    parser.add_argument(
        "--srcdir", "-s", default=None, help="Specify the source directory (default: ./)"
    )
    parser.add_argument(
        "--builddir", "-b", default=None, help="Specify the build directory (default: ./)"
    )
    parser.add_argument(
        "--destdir", "-d", default=None, help="Specify a destination directory (default: <srcdir>/regression)"
    )

    parser.add_argument(
        "--nproc",
        "-j",
        type=int,
        default=os.cpu_count(),
        help=f"Number of concurrent workers (default: {os.cpu_count()})",
    )

    parser.add_argument(
        "--oracle-timeout",
        type=int,
        default=None,
        help=f"per-case oracle wall-clock budget in seconds (default {REF_TIMEOUT_S})",
    )

    parser.add_argument(
        "funcs",
        metavar="FUNCTIONALS",
        nargs="*",
        default=[],
        help="Restrict generation to a subset of functionals",
    )

    args = parser.parse_args()
    # Workers are spawned, not forked, so they re-import this module and would
    # not see a global assigned here. Pass it through the environment instead.
    if args.oracle_timeout:
        os.environ["XC_REF_TIMEOUT_S"] = str(args.oracle_timeout)
    src = args.srcdir or os.getenv("srcdir", "./")
    ctx = Context(
        srcdir=src,
        builddir=args.builddir or os.getenv("builddir", "./"),
        destdir=args.destdir or os.getenv("destdir", os.path.join(src, "regression")),
        funcs=args.funcs,
    )

    sys.exit(main(ctx, nproc=args.nproc))
