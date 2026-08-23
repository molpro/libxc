#!/usr/bin/env python3
"""
Compile a python/<family>/<name>.py math definition to
src/maple2c/<family>/<name>.c.

Usage:
    python3 scripts/sympy2c/compile.py <name> [output.c]
    python3 scripts/sympy2c/compile.py --all          # regenerate every .py
    python3 scripts/sympy2c/compile.py --all -j 8     # ... 8-way parallel

If output.c is omitted, defaults to src/maple2c/<family>/<name>.c.
"""

import argparse
import importlib.util
import os
import subprocess
import sys
import time
from argparse import BooleanOptionalAction
from concurrent.futures import ThreadPoolExecutor, as_completed

_HERE = os.path.dirname(os.path.abspath(__file__))
_REPO = os.path.abspath(os.path.join(_HERE, "..", ".."))
_PYTHON_DIR = os.path.join(_REPO, "python")
_SCRIPTS_DIR = os.path.join(_REPO, "scripts")

# Make `from libxc_codegen import *` resolvable inside math files, and
# `from <name> import *` ($include of another functional / library
# module) resolvable across the python/ family subdirectories.
sys.path.insert(0, _PYTHON_DIR)
for _entry in sorted(os.listdir(_PYTHON_DIR)):
    _sub = os.path.join(_PYTHON_DIR, _entry)
    if os.path.isdir(_sub):
        sys.path.insert(0, _sub)
import libxc_codegen  # noqa: E402


def _find_math_file(name):
    for family in os.listdir(_PYTHON_DIR):
        candidate = os.path.join(_PYTHON_DIR, family, f"{name}.py")
        if os.path.isfile(candidate):
            return family, candidate
    raise FileNotFoundError(f"no python/<family>/{name}.py found")


def _import_math(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


# Per-functional derivative-order caps. A name absent here is generated to the
# requested order (default ceiling 4). Two kinds of cap, each justified per
# functional below:
#
#   DIFFERENTIABILITY caps -- the functional has a genuine continuity limit: a
#   piecewise junction whose branches match to only finite order, so derivatives
#   beyond that are discontinuous (meaningless). These are PERMANENT.
#
#   PERFORMANCE caps -- the functional is C-infinity (differentiable to order 4)
#   but order-4 (lxc) sp.diff generation is multi-hour or infeasible (the cost is
#   cse_main on the huge order-4 expression, not the differentiation). lxc is the
#   rarest/most-fragile/most-expensive derivative, so cap at kxc until the
#   CSE-speed work lands. These are REMOVABLE once CSE is fast. (Recorded
#   generation time is the order-4 sp.diff wall time from a full run.)
_ORDER_CAPS = {
    # --- Differentiability caps (permanent) ---
    "gga_x_wpbeh": 2,    # erf-attenuation junction; 3rd+ deriv discontinuous (analysis #37)
    "lda_c_pk09": 3,     # junction continuity limit (analysis #37)
    "mgga_c_b94": 3,     # junction continuity limit (analysis #37)
    # rSCAN regularized-interpolation family: the degree-7 alpha-interpolation
    # polynomial is matched to the SCAN switch to only finite order at its
    # piecewise junction(s), so higher derivatives jump there.
    "mgga_x_rscan": 3,   # rscan_f_alpha: C3 at alpha=2.5 (poly|exp); 4th deriv jumps (-8.19 vs +0.62)
    "mgga_c_rscan": 3,   # same rscan_f_alpha switch; C3
    "mgga_x_r2scan": 2,  # r2scan_f_alpha: C2 at alpha=0 (neg-exp|poly); kxc jumps (verified: kxc(0-)=-1.7e-5 vs kxc(0+)=+4.7e-3)
    "mgga_c_r2scan": 2,  # same r2scan_f_alpha switch; C2 at alpha=0
    "mgga_x_r4scan": 2,  # r2scan_f_alpha + smooth r4 correction; C2 at alpha=0
    #
    # --- Performance caps (C-infinity, but order-4 sp.diff is still multi-hour) ---
    # The CSE speedup and AD fallback genuinely retired MOST former performance
    # caps -- mgga_c_pkzb (181s), gga_x_hjs (107s), gga_x_hjs_b88_v2 (104s),
    # mgga_c_scan (237s), mgga_c_revscan (242s) now reach order 4 in minutes and
    # stay uncapped. But five remain 50-92+ minutes at order 4 (measured), which
    # dominates the regeneration tail; lxc is rarely exercised for these
    # correlation functionals, so cap them at kxc. Lift an entry here (not the
    # differentiability block above) if a future speedup makes it cheap.
    "gga_c_gapc": 3,       # order-4 sp.diff ~197 min (slowest in the library)
    "gga_c_pbe_vwn": 3,    # order-4 sp.diff ~53 min
    "mgga_c_tpss": 3,      # TPSS correlation; order-4 sp.diff ~87 min
    "mgga_c_revtpss": 3,   # revTPSS correlation; order-4 sp.diff ~88 min
    "mgga_c_tpssloc": 3,   # TPSSloc correlation; order-4 sp.diff ~92 min
    #
    # --- Size cap ---
    # hyb_mgga_xc_coach: p-forming its B97 fitting helpers (passing the squared
    # reduced gradient across the opaque boundary) makes order-4 sp.diff COMPLETE
    # without the AD fallback (9.6 MB AD -> 4.0 MB sp.diff), but the sp.diff body
    # is still ~7x its sibling hyb_mgga_xc_wb97mv (0.66 MB) and the authors' ~0.55
    # MB reference. Measured: the gap is NOT the derivative count (identical
    # 7-variable order-4 tensor; laplacian derivs are cheap zeros) and NOT Legendre
    # expansion (opaque Legendre jets buy only ~1.45x because CSE already recovers
    # the shared v-powers) -- it is the reduced-variable chain rule, which needs a
    # generator change, not a source change. lxc is not exercised for a
    # range-separated hybrid, so cap the disproportionate order-4 body at kxc.
    "hyb_mgga_xc_coach": 3,
    # mgga_x_mscan: C-infinity (original SCAN exp switch), but unlike base
    # mgga_x_scan (0.07 MB) it RECOMPUTES a modified alpha from the gradients
    # (mscan_alpha via mscan_sigma1's cross-gradient), a composite of xt/xs0/xs1/
    # t0/t1 whose order-4 derivatives are intrinsically large. P-forming the
    # opaque helpers (squared reduced gradients) removed the sqrt(sigma) blow-up
    # (2.7 -> 1.5 MB) but not the composite itself. lxc is rarely used; cap at kxc.
    "mgga_x_mscan": 3,
}


def compile_one(name, output=None, spin_density=True, maxorder=1, use_ad=False):
    cap = _ORDER_CAPS.get(name)
    capped = cap is not None and cap < maxorder
    if capped:
        maxorder = cap
    family, src = _find_math_file(name)
    if output is None:
        output = os.path.join(_REPO, "src", "maple2c", family, f"{name}.c")
    t0 = time.perf_counter()
    if use_ad:
        # Hash-consed DAG Taylor-mode AD path (scripts/sympy2c/ad_bridge.py).
        # Supported for the exc-defined LDA/GGA/MGGA families; other families
        # (vxc-direct, hybrids) still need the legacy path.
        import ad_bridge
        gen = {"lda_exc": ad_bridge.generate_lda,
               "gga_exc": ad_bridge.generate_gga,
               "mgga_exc": ad_bridge.generate_mgga}.get(family)
        if gen is None:
            raise NotImplementedError(
                f"--ad: the AD engine does not yet support family '{family}'")
        # Generate fully BEFORE opening the file, so a generation failure leaves
        # the existing .c untouched instead of truncating it to an empty file.
        text = gen(name, maxorder)
        with open(output, "w") as fh:
            fh.write(text)
        note = f"  [capped at order {cap}]" if capped else ""
        print(f"wrote {output} ({time.perf_counter() - t0:.1f}s) [AD]{note}")
        return
    mod = _import_math(src, name)
    libxc_codegen.compile_module(mod, output, max_order=maxorder,
                                 spin_density=spin_density)
    note = f"  [capped at order {cap}]" if capped else ""
    print(f"wrote {output} ({time.perf_counter() - t0:.1f}s){note}")


def compile_all(spin_density=True, maxorder=1, jobs=None, timeout=None,
                use_ad=False, ad_timeout=None):
    """Regenerate every functional in parallel.

    Each functional is compiled in its own subprocess, up to `jobs` at a
    time; per-functional code generation is heavy and independent, so it
    parallelises cleanly. The sp.diff attempt is capped at `timeout` seconds
    -- a PROBE: sp.diff explodes on a handful of functionals (op_ family,
    mgga_c_tpss, wpbeh) and must not stall the run, so on timeout it falls
    back to the (polynomial-time) AD engine. The AD attempt has its own,
    deliberately more generous, `ad_timeout` because legitimate AD generation
    of the heaviest functionals is slow but finite (wpbeh ~230s). A None
    timeout disables that cap. Keeping the two separate is what lets a single
    `--all` run BOTH bound runaway sp.diff AND let slow AD finish -- with one
    shared cap, a value large enough for AD would never catch an sp.diff hang,
    and a value small enough to catch it would kill legitimate AD.
"""
    names = []
    for family in sorted(os.listdir(_PYTHON_DIR)):
        family_dir = os.path.join(_PYTHON_DIR, family)
        if not os.path.isdir(family_dir):
            continue
        for fname in sorted(os.listdir(family_dir)):
            if fname.endswith(".py") and fname != "__init__.py":
                names.append(fname[:-3])
    jobs = jobs or os.cpu_count() or 1

    tasks = [("func", n) for n in names]

    def _run(task):
        _, item = task
        label = item

        def _cmd(ad):
            c = [sys.executable, os.path.abspath(__file__), item,
                 "--maxorder", str(maxorder)]
            if not spin_density:
                c.append("--no-spin-density")
            if ad:
                c.append("--ad")
            return c
        t0 = time.perf_counter()
        try:
            r = subprocess.run(_cmd(use_ad), capture_output=True,
                               text=True, timeout=timeout)
        except subprocess.TimeoutExpired:
            # sp.diff explodes on deeply-nested helper chains (the op_
            # family) at high order -- fall back to the Taylor-mode AD
            # engine, which stays polynomial. The default sp.diff path
            # is kept for the feasible bulk (5-7x smaller code).
            if use_ad:
                return (label, False, f"timeout (>{timeout}s)",
                        time.perf_counter() - t0)
            try:
                r = subprocess.run(_cmd(True), capture_output=True,
                                   text=True, timeout=ad_timeout)
            except subprocess.TimeoutExpired:
                return (label, False,
                        f"timeout even with AD (>{ad_timeout}s)",
                        time.perf_counter() - t0)
            dt = time.perf_counter() - t0
            if r.returncode == 0:
                return label, True, "[AD fallback]", dt
            last = (r.stderr.strip().splitlines()
                    or ["(no error output)"])[-1]
            return label, False, f"[AD] {last}", dt
        dt = time.perf_counter() - t0
        if r.returncode == 0:
            return label, True, "", dt
        last = (r.stderr.strip().splitlines() or ["(no error output)"])[-1]
        return label, False, last, dt
    ok, failed, t_all = 0, [], time.perf_counter()
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = {pool.submit(_run, t): t for t in tasks}
        for fut in as_completed(futures):
            name, success, err, dt = fut.result()
            if success:
                ok += 1
                print(f"  ok    {name}  ({dt:.1f}s)", flush=True)
            else:
                failed.append(name)
                print(f"  FAIL  {name}: {err}  ({dt:.1f}s)", flush=True)
    print(f"\ncompiled {ok} ok, {len(failed)} failed "
          f"(jobs={jobs}, maxorder={maxorder}, "
          f"wall {time.perf_counter() - t_all:.1f}s)")
    if failed:
        print("failed: " + " ".join(sorted(failed)))
    return len(failed)


def main():
    # Line-buffer stdout so progress (per-functional "wrote"/"ok"/"FAIL" lines)
    # is flushed on every newline when redirected to a file or pipe, rather than
    # held in a block buffer until the run ends.
    try:
        sys.stdout.reconfigure(line_buffering=True)
    except (AttributeError, ValueError):
        pass
    ap = argparse.ArgumentParser()
    ap.add_argument("name", nargs="?", help="functional name (e.g. lda_x)")
    ap.add_argument("output", nargs="?", help="explicit output path")
    ap.add_argument("--all", action="store_true",
                    help="regenerate every functional under python/")
    # Exchange / kinetic-energy functionals obey exact spin scaling, so
    # each spin channel can be evaluated from its own same-spin density.
    # On by default; --no-spin-density restores the legacy (rs, zeta) path.
    ap.add_argument("--spin-density", default=True, action=BooleanOptionalAction,
                    help="use the spin-density evaluation path for "
                         "spin-scaled (exchange / kinetic) functionals")
    # Highest derivative order to generate (mirrors maple2c.py --maxorder).
    # Defaults to 4 -- the order the checked-in generated tree is built at.
    # The old default of 1 made the generated files' own "regenerate via
    # compile.py <name>" instruction silently strip the fxc/kxc/lxc kernels
    # from an order-4 file.
    ap.add_argument("--maxorder", type=int, default=4,
                    help="highest derivative order to generate "
                         "(0=exc, 1=+vxc, 2=+fxc, 3=+kxc, 4=+lxc; default 4)")
    ap.add_argument("-j", "--jobs", type=int, default=None,
                    help="parallel jobs for --all (default: CPU count)")
    ap.add_argument("--timeout", type=float, default=300,
                    help="sp.diff PROBE timeout in seconds for --all: on "
                         "expiry the functional falls back to the AD engine "
                         "(default 300; the feasible bulk generates in well "
                         "under this, while sp.diff explodes -- effectively "
                         "forever -- on op_/tpss/wpbeh). 0 = no probe cap, "
                         "which DISABLES the AD fallback (use only with --ad)")
    ap.add_argument("--ad-timeout", type=float, default=0,
                    help="timeout in seconds for the AD fallback attempt "
                         "(0 = none, the default; legitimate AD generation of "
                         "the heaviest functionals, e.g. wpbeh, is slow but "
                         "finite, so it is given an unbounded budget)")
    ap.add_argument("--ad", action="store_true",
                    help="use the hash-consed DAG Taylor-mode AD engine "
                         "(ad_bridge) instead of the legacy sp.diff path; "
                         "currently supports the exc-defined LDA/GGA/MGGA "
                         "families")
    args = ap.parse_args()

    if args.all:
        # compile_all returns the failure count; a run with failures must not
        # exit 0, or `compile.py --all && make` proceeds on stale files.
        sys.exit(1 if compile_all(
            spin_density=args.spin_density, maxorder=args.maxorder,
            jobs=args.jobs, timeout=(args.timeout or None),
            use_ad=args.ad, ad_timeout=(args.ad_timeout or None)) else 0)
    elif args.name:
        compile_one(args.name, args.output, spin_density=args.spin_density,
                    maxorder=args.maxorder, use_ad=args.ad)
    else:
        ap.error("specify a name or --all")


if __name__ == "__main__":
    main()
