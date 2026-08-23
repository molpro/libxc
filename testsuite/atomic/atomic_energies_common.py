"""Shared low-level helpers for the atomic exchange-correlation tests.

Evaluates libxc functionals on accurate Hartree-Fock atomic densities from the
AtomicOrbitals package (Koga et al. Slater-orbital tabulations, ~microhartree
accuracy for H-Xe). The XC energy is the radial integral

    E_xc = integral zk(r) rho(r) dV = sum_i zk_i rho_i (4 pi wt_i),

where the AtomicOrbitals grid weight wt already carries the r^2 Jacobian.

This module owns only the pieces shared by the energy and derivative tiers:
providing the reference-density evaluator, building a functional's pylibxc
input from an atom's tabulated densities, and the spin/threshold constants. The
energy tier drives its own radial-grid sweep (atomic_convergence.py); the
derivative tier builds its own fixed-grid batch (atomic_derivatives_common.py).

The Hartree-Fock densities and the radial grid come from koga_hf.py, a native
(vendored) evaluator with the Koga Z=1-54 wavefunctions embedded, so the tier
ships with libxc and needs no external package.
"""
import os
import sys

import numpy as np

_HERE = os.path.dirname(os.path.abspath(__file__))
if _HERE not in sys.path:
    sys.path.insert(0, _HERE)
import koga_hf  # noqa: E402

# Radial grid for the derivative tier. Those tests compare the analytic
# derivatives to finite differences on the *same* grid, so the check is a
# per-point identity and does not depend on quadrature convergence; a few
# hundred points is plenty.
GRID_POINTS = 500

SPINS = ("unpolarized", "polarized")


def have_atomicorbitals():
    """True if the embedded reference-density data is available (always)."""
    return koga_hf.available()


def _import_ao():
    """The reference-density module (Atom + GridGenerator, koga_hf)."""
    return koga_hf


def _atom_input(ao, atom, r, spin):
    d0, d1, g0, g1, t0, t1, l0, l1 = ao.Atom(atom).get_densities(r)
    if spin == "unpolarized":
        return {"rho": d0 + d1, "sigma": (g0 + g1) ** 2,
                "lapl": l0 + l1, "tau": t0 + t1}
    return {"rho": np.stack((d0, d1), axis=1),
            "sigma": np.stack((g0 * g0, g0 * g1, g1 * g1), axis=1),
            "lapl": np.stack((l0, l1), axis=1),
            "tau": np.stack((t0, t1), axis=1)}
