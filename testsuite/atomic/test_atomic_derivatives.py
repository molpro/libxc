"""Physical consistency tests for the XC potential (vxc) and kernel (fxc).

For every functional a uniform density-scaling response on real atomic densities
checks that the analytic derivatives libxc returns reproduce finite differences
of the energy (vxc) and of the potential fold (fxc). See
atomic_derivatives_common.py for the identities.

These are the physical, basis-folded complement to the pointwise regression
tests; they cannot probe the density tail (it is suppressed by the exponential
decay), which is exactly what the unweighted pointwise tests are for.

The reference densities come from the vendored koga_hf module.
"""
import os
import sys

import numpy as np
import pytest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_derivatives_common as adc  # noqa: E402

# Slow (~20 min for the whole tier): deselected from the default run by the
# `-m 'not atomic'` addopts in pyproject.toml. Run with `pytest -m atomic`.
pytestmark = [
    pytest.mark.atomic,
    pytest.mark.skipif(
        not adc.have_atomicorbitals(),
        reason="embedded reference-density data (koga_hf_data.json) missing",
    ),
]

# Analytic fold and finite difference are both computed by this build and agree
# to the finite-difference floor (typically ~1e-9). The tolerance is kept loose
# to absorb the finite-difference truncation of functionals with a large third
# derivative and the ~zero responses of the one-electron H atom (whose 1e-6-level
# correlation is physically negligible); genuine inconsistencies are ~1e-2.
RTOL = 1e-3
ATOL = 1e-5

# These fail through the Fermi-hole-curvature guard, not through the
# deorbitalization: the deorbitalize chain rule is exact at every order.
#
# work_mgga_inc.c enforces a positive Fermi hole curvature by clamping
# sigma <- min(sigma, 8*rho*tau) whenever XC_FLAGS_ENFORCE_FHC is set (which is
# the default, for every functional). Only the *value* is clamped: the kernel
# then differentiates as if rho, sigma and tau were independent, although in the
# clamped region sigma_eff = 8*rho*tau. So d/dsigma should vanish and d/drho,
# d/dtau should pick up the clamp, and neither happens -- the kernel instead
# multiplies an O(1) df/dalpha by an unclamped d(alpha)/d(tau) ~ 1/rho^(5/3).
# The energy is unaffected, which is why only fxc shows it.
#
# The deorbitalized functionals reach the clamp because PC07 undershoots the von
# Weizsaecker bound in the tail (tau~ = 0.56*tau_W there), and the atomic
# quadrature weight r^2 amplifies that single grid point into the whole error.
# Orbital tau always satisfies tau >= tau_W, so all-electron mGGAs never hit it --
# but PAW/pseudopotential densities do, so plain SCAN/TPSS are affected too.
#
# Chaining the clamp in the harness cannot fix this: alpha == 0 identically in the
# clamped region, so reconstructing d(alpha)/d(rho) = 0 from the kernel's partials
# cancels ~1e25 terms (17 digits at order 2, more beyond). The clamp has to be
# applied symbolically in the codegen, where alpha collapses to 0 before
# differentiation. Deferred to the post-7.1 refactor.
FHC_CLAMP_FXC_BUG = {
    "mgga_x_scanl", "mgga_x_revscanl", "mgga_x_r2scanl",
    "mgga_c_scanl", "mgga_c_r2scanl",
    "mgga_c_scanl_vv10", "mgga_c_scanl_rvv10",
    "mgga_c_r2scanl_vv10", "mgga_c_r2scanl_rvv10",
    "mgga_xc_r2scanl_vv10",
}

# Genuine fxc/energy inconsistencies flagged by this test, to be investigated.
# The VWN3 spin-stiffness interpolation is ~4% off at polarized N; anything built
# on it (e.g. the b3lyp3 hybrid) inherits it. VWN3 is independently known to be
# numerically ill-behaved (sharp features/oscillations: Lehtola & Marques,
# J. Chem. Phys. 157, 174114 (2022)), which is what its 2nd derivative exposes.
KNOWN_FXC_INCONSISTENT = {
    "lda_c_vwn_3",
    "hyb_gga_xc_b3lyp3",
}

# The energy of these functionals is not smooth under uniform density scaling --
# an internal threshold/branch is crossed as xi varies, giving a spurious
# finite-difference reference (FD ~ 100x the analytic derivative). The scaling
# response test does not apply to them. All three are also numerically
# ill-behaved on the atomic quadrature (Lehtola & Marques, J. Chem. Phys. 157,
# 174114 (2022)): op_pw91 "extremely ill-behaved", lp96 "very slow, sharp
# features".
NONSMOOTH_UNDER_SCALING = {
    "gga_c_op_pw91", "lda_c_lp96_b", "lda_k_lp96_b",
}

if adc.have_atomicorbitals():
    import pylibxc
    from pylibxc import flags
    _FUNCS = sorted(pylibxc.util.xc_available_functional_names())
else:  # pragma: no cover
    _FUNCS = []


def _check(func, order):
    batch = adc.get_batch()
    h = adc.FD_STEP
    mism = []
    for spin in adc.SPINS:
        feval = pylibxc.LibXCFunctional(func, spin)
        # The test compares the derivatives against the energy, so it needs a
        # genuine 3D energy: skip model potentials (no energy) and 1D/2D
        # functionals (the atomic densities are 3D).
        if not feval._have_exc:
            pytest.skip(f"{func}: no energy density (model potential)")
        if not (feval.get_flags() & flags.XC_FLAGS_3D):
            pytest.skip(f"{func}: not a 3D functional")
        if func in NONSMOOTH_UNDER_SCALING:
            pytest.skip(f"{func}: energy not smooth under density scaling")
        if order == 1 and not feval._have_vxc:
            pytest.skip(f"{func}: no vxc in this build")
        if order == 2 and not feval._have_fxc:
            pytest.skip(f"{func}: no fxc in this build")
        if order == 1:
            analytic = batch.vxc_fold(feval, spin, 1.0)
            ep = batch.energy(feval, spin, 1 + h)
            em = batch.energy(feval, spin, 1 - h)
            fd = {a: (ep[a] - em[a]) / (2 * h) for a in batch.atoms}
        else:
            analytic = batch.fxc_fold(feval, spin)
            vp = batch.vxc_fold(feval, spin, 1 + h)
            vm = batch.vxc_fold(feval, spin, 1 - h)
            fd = {a: (vp[a] - vm[a]) / (2 * h) for a in batch.atoms}
        for atom in batch.atoms:
            a_, f_ = analytic[atom], fd[atom]
            if not (np.isfinite(a_) and np.isfinite(f_)):
                continue
            if not np.isclose(a_, f_, rtol=RTOL, atol=ATOL):
                mism.append(f"  {atom:4s} {spin:11s} analytic {a_: .8e} "
                            f"FD {f_: .8e} (d {a_ - f_: .2e})")
    label = "vxc" if order == 1 else "fxc"
    assert not mism, (f"{func}: {label} inconsistent with the energy on "
                      f"{len(mism)} case(s):\n" + "\n".join(mism))


@pytest.mark.parametrize("func", _FUNCS)
def test_atomic_vxc(func):
    _check(func, 1)


@pytest.mark.parametrize("func", _FUNCS)
def test_atomic_fxc(func):
    if func in FHC_CLAMP_FXC_BUG:
        pytest.xfail("fxc inconsistent with energy: the Fermi-hole-curvature "
                     "clamp in work_mgga_inc.c is not propagated to the "
                     "derivatives (see the note above; not a deorbitalize bug)")
    if func in KNOWN_FXC_INCONSISTENT:
        pytest.xfail("fxc inconsistent with the energy (to investigate)")
    _check(func, 2)
