"""Atomic XC Fock- and kernel-matrix consistency tests.

Treating the atomic shell occupations as parameters, the XC Fock matrix
(F_a = dE/dc_a, from vxc) and the response kernel (K_ab = d2E/dc_a dc_b, from
fxc) are assembled analytically in the shell basis and checked against a finite
difference of the order below (the energy for the Fock matrix, the Fock matrix
for the kernel). This is the basis-resolved complement to the uniform-scaling
response of test_atomic_derivatives.py: the same vxc/fxc channels, exercised in
the matrix-element combinations a Fock build actually uses. See
atomic_fock_common.py for the identities.
"""
import os
import sys

import numpy as np
import pytest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_fock_common as afc  # noqa: E402
import model_convergence as mc  # noqa: E402

# Slow (~20 min for the whole tier): deselected from the default run by the
# `-m 'not atomic'` addopts in pyproject.toml. Run with `pytest -m atomic`.
pytestmark = [
    pytest.mark.atomic,
    pytest.mark.skipif(
        not afc.aoc.have_atomicorbitals(),
        reason="embedded reference-density data (koga_hf_data.json) missing",
    ),
]

# Analytic matrix and finite difference are both computed by this build; the
# loose tolerance absorbs the finite-difference truncation of functionals with a
# large next derivative (e.g. SCAN). Genuine inconsistencies are ~1e-2.
RTOL = 1e-3
ATOL = 1e-5

# The energy of these functionals is not smooth under occupation scaling (an
# internal threshold/branch is crossed), so the finite-difference reference is
# spurious. The first three mirror test_atomic_derivatives.NONSMOOTH_UNDER_SCALING;
# prhg07's Laplacian-dependent form is kinked at the polarized quantum-dot
# density (verified: the analytic vxc is correct -- the central-difference
# reference converges to it only at O(h), the signature of a kink, not O(h^2)).
NONSMOOTH = {"gga_c_op_pw91", "lda_c_lp96_b", "lda_k_lp96_b",
             "mgga_x_2d_prhg07"}

# The kernel uses fxc, so it inherits the fxc inconsistencies that
# test_atomic_derivatives.py already flags: the deorbitalized second-order chain
# rule (vxc/Fock is correct, so order 1 still passes) and VWN3.
DEORBITALIZED_FXC_BUG = {
    "mgga_x_scanl", "mgga_x_revscanl", "mgga_x_r2scanl",
    "mgga_c_scanl", "mgga_c_r2scanl",
    "mgga_c_scanl_vv10", "mgga_c_scanl_rvv10",
    "mgga_c_r2scanl_vv10", "mgga_c_r2scanl_rvv10",
    "mgga_xc_r2scanl_vv10",
}
KNOWN_FXC_INCONSISTENT = {"lda_c_vwn_3", "hyb_gga_xc_b3lyp3"}

# mgga_x_jk has a denominator that can vanish -- the paper's poster child of
# numerical instability (Lehtola & Marques 2022). Its third derivative is so
# large that the finite-difference kernel reference is unreliable on the heavier
# atoms (the analytic kernel does agree with FD where the latter is reliable),
# so the fxc kernel cannot be validated this way.
UNSTABLE_KERNEL = {"mgga_x_jk"}

if afc.aoc.have_atomicorbitals():
    import pylibxc
    _FUNCS = sorted(pylibxc.util.xc_available_functional_names())
else:  # pragma: no cover
    _FUNCS = []


def _check(func, order):
    # 3D functionals use the atomic shells; 1D/2D use the harmonic-oscillator
    # wire/dot levels as their basis.
    dim = mc.dimensionality(func)
    if dim is None:
        pytest.skip(f"{func}: no energy density (model potential)")
    batch = afc.get_batch() if dim == 3 else afc.get_model_batch(dim)
    h = afc.FD_STEP
    mism = []
    for spin in afc.aoc.SPINS:
        feval = pylibxc.LibXCFunctional(func, spin)
        if func in NONSMOOTH:
            pytest.skip(f"{func}: energy not smooth under occupation scaling")
        if order == 1 and not feval._have_vxc:
            pytest.skip(f"{func}: no vxc in this build")
        if order == 2 and not feval._have_fxc:
            pytest.skip(f"{func}: no fxc in this build")
        for atom in batch.atoms:
            c0 = batch.occ0(atom)
            n = len(c0)
            eye = np.eye(n)
            if order == 1:
                ana = batch.fock(feval, spin, atom, c0)
                fd = np.array([
                    (batch.energy(feval, spin, atom, c0 + h * eye[a])
                     - batch.energy(feval, spin, atom, c0 - h * eye[a])) / (2 * h)
                    for a in range(n)])
            else:
                ana = batch.kernel(feval, spin, atom, c0)
                fd = np.zeros((n, n))
                for b in range(n):
                    fp = batch.fock(feval, spin, atom, c0 + h * eye[b])
                    fm = batch.fock(feval, spin, atom, c0 - h * eye[b])
                    fd[:, b] = (fp - fm) / (2 * h)
            if not (np.all(np.isfinite(ana)) and np.all(np.isfinite(fd))):
                continue
            if not np.allclose(ana, fd, rtol=RTOL, atol=ATOL):
                d = np.max(np.abs(ana - fd))
                mism.append(f"  {atom:3s} {spin:11s} max|dev|={d:.2e}")
    label = "Fock" if order == 1 else "kernel"
    assert not mism, (f"{func}: {label} inconsistent with the energy on "
                      f"{len(mism)} case(s):\n" + "\n".join(mism))


@pytest.mark.parametrize("func", _FUNCS)
def test_atomic_fock(func):
    _check(func, 1)


@pytest.mark.parametrize("func", _FUNCS)
def test_atomic_kernel(func):
    if func in DEORBITALIZED_FXC_BUG:
        pytest.xfail("deorbitalized fxc inconsistent with energy "
                     "(vxc/Fock is correct)")
    if func in KNOWN_FXC_INCONSISTENT:
        pytest.xfail("fxc inconsistent with the energy (to investigate)")
    if func in UNSTABLE_KERNEL:
        pytest.skip("numerically unstable; finite-difference kernel reference "
                    "unreliable")
    _check(func, 2)
