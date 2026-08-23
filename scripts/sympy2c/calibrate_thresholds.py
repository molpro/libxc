#!/usr/bin/env python3
"""Per-functional, per-order density floor calibrated against the arbitrary-
precision oracle.

For each functional and each derivative order n >= 2, walk the density down a
physically representative decay tail and compare the double-precision build to
the converged arbitrary-precision reference. rho_n(F) is the highest density at
which the per-point relative error crosses DIVERGENCE_TOL -- below it the n-th
derivative is not representable in double precision and should be floored to 0.
exc/vxc (orders 0-1) are never floored (the potential's tail is physical).

The tail model is an exponential density rho ~ exp(-a r):
    sigma = |grad rho|^2 = a^2 rho^2,   tau = sigma/(8 rho) (von Weizsaecker),
    lapl  = a^2 rho (far-tail Laplacian).
The decay constant a = 2 sqrt(2 I) is set by the ionization potential I. The
reduced gradient s = X2S a rho^(-1/3) grows with a at every density, so the
density at which the build breaks increases monotonically with a: the CONSERVATIVE
envelope over atoms/molecules/crystals is the largest realistic a (fastest tail,
smallest s screened away). DECAY_A default 3.0 (I ~ 1.1 Ha) is a safe upper
bound; real HOMO ionization potentials rarely exceed that.
"""
import sys
import numpy as np
import pylibxc
import ad_reference as ADR

DIVERGENCE_TOL = 1e-7
DECAY_A = 3.0                  # conservative tail decay constant a = 2 sqrt(2 I)
BASE_PREC = 40
X2S = 1.0 / (2.0 * (3.0 * np.pi**2) ** (1.0 / 3.0))

_ORDER_FIELDS = {
    2: ["v2rho2", "v2rhosigma", "v2sigma2", "v2rholapl", "v2rhotau",
        "v2sigmalapl", "v2sigmatau", "v2lapl2", "v2lapltau", "v2tau2"],
    3: ["v3rho3", "v3rho2sigma", "v3rhosigma2", "v3sigma3"],
    4: ["v4rho4", "v4rho3sigma", "v4rho2sigma2", "v4rhosigma3", "v4sigma4"],
}


def _family(name):
    if name.startswith(("mgga_", "hyb_mgga_")):
        return "mgga"
    if name.startswith(("gga_", "hyb_gga_")):
        return "gga"
    return "lda"


def calibrate(name, nspin=1, npts=120, max_order=2, a=DECAY_A):
    fam = _family(name)
    rho = np.logspace(1.0, -14.0, npts)
    a2 = a * a
    inp = {"rho": rho}
    if fam in ("gga", "mgga"):
        inp["sigma"] = a2 * rho**2
    if fam == "mgga":
        inp["tau"] = (a2 / 8.0) * rho
        inp["lapl"] = a2 * rho

    feval = pylibxc.LibXCFunctional(name, nspin)
    feval.set_dens_threshold(1e-30)          # expose the raw precision limit
    out = feval.compute(inp, do_exc=True, do_vxc=True, do_fxc=max_order >= 2,
                        do_kxc=max_order >= 3, do_lxc=max_order >= 4)

    # oracle with the same (near-zero) threshold
    import eval_reference as ER
    ER._read_dens_threshold = lambda _n: 1e-30
    refs, stat = ADR.evaluate_converged(
        name, nspin, rho.reshape(-1, 1),
        sigma=inp.get("sigma", np.zeros_like(rho)).reshape(-1, 1) if fam != "lda" else None,
        lapl=inp["lapl"].reshape(-1, 1) if fam == "mgga" else None,
        tau=inp["tau"].reshape(-1, 1) if fam == "mgga" else None,
        max_order=max_order, base_precision=BASE_PREC)
    if not refs:
        return None

    s = X2S * np.sqrt(inp.get("sigma", np.zeros_like(rho))) / rho ** (4.0 / 3.0)
    result = {}
    for order in range(2, max_order + 1):
        worst_rho = 0.0
        worst_s = 0.0
        for field in _ORDER_FIELDS[order]:
            if field not in out or field not in refs:
                continue
            b = np.asarray(out[field]).reshape(npts, -1)
            o = np.array([[refs[field][ip][ic] for ic in range(len(refs[field][ip]))]
                          for ip in range(npts)])
            nc = o.shape[1]
            # Per-component oracle status ("ok" = base/check precision agree). A
            # non-"ok" component is ill-conditioned (oracle can't fully vouch) --
            # ignore it: the breakage ONSET, where the true value is still large,
            # is "ok" and sets the floor; the deeper unresolved points are lower
            # density and never raise it.
            ok = (np.array([[stat[field][ip][ic] == "ok" for ic in range(nc)]
                            for ip in range(npts)])
                  if stat and field in stat else np.ones((npts, nc), bool))
            denom = np.maximum(np.maximum(np.abs(b), np.abs(o)), 1e-300)
            rel = np.where(ok, np.abs(b - o) / denom, 0.0)
            bad = np.any(rel > DIVERGENCE_TOL, axis=1)
            if bad.any():
                # highest-density breakage: floor everything at or below it
                r_bad = float(rho[bad].max())
                if r_bad > worst_rho:
                    worst_rho = r_bad
                    worst_s = float(s[bad][np.argmax(rho[bad])])
        result[order] = (worst_rho, worst_s)
    return result


if __name__ == "__main__":
    names = sys.argv[1:] or ["gga_c_pbe"]
    print(f"{'functional':24} {'order':>5} {'rho_floor':>12} {'s@floor':>10}")
    print("-" * 56)
    for name in names:
        try:
            res = calibrate(name)
        except Exception as e:
            print(f"{name:24}   ERROR: {e}")
            continue
        if res is None:
            print(f"{name:24}   (oracle produced no reference)")
            continue
        for order, (r, s) in res.items():
            tag = f"{r:12.2e}" if r > 0 else f"{'none':>12}"
            print(f"{name:24} {order:5d} {tag} {s:10.1f}")
