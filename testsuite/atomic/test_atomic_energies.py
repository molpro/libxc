"""Atomic exchange-correlation energy regression tests at the quadrature limit.

Each functional that provides an energy density is evaluated on the accurate
Koga Hartree-Fock densities of the probe atoms of Lehtola and Marques
(J. Chem. Phys. 157, 174114 (2022)) and integrated to a total energy. Every
atom is evaluated at its own tabulated radial-quadrature convergence point (the
atoms converge at different rates), and the result is checked against the
converged reference in references/. This complements the pointwise regression
tests: it exercises the functionals on real atomic densities with exponential
tails, so it also guards against deep-tail energy instabilities.

Functionals whose atomic quadrature never converges to microhartree (the
pathological band -- SCAN-family kin, JK, CC06, ...) are recorded but only
checked for finiteness: their reference value is not reproducible across
platforms. References are produced by generate_atomic_energies.py. The
reference densities come from the vendored koga_hf module.
"""
import glob
import os
import sys

import numpy as np
import pytest

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_energies_common as aoc  # noqa: E402
import atomic_convergence as ac  # noqa: E402
import model_convergence as mc  # noqa: E402

# Slow (~20 min for the whole tier): deselected from the default run by the
# `-m 'not atomic'` addopts in pyproject.toml. Run with `pytest -m atomic`.
pytestmark = [
    pytest.mark.atomic,
    pytest.mark.skipif(
        not aoc.have_atomicorbitals(),
        reason="embedded reference-density data (koga_hf_data.json) missing",
    ),
]

REF_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "references")

# The reference and the test integrate the same quantity on the same (per-atom
# converged) grid, so on the reference platform they agree to ~machine
# precision; these tolerances absorb cross-compiler floating-point differences
# in the integral (rtol) while the absolute floor handles atoms whose energy is
# ~0 (e.g. correlation of the one-electron probe).
RTOL = 1e-6
ATOL = 1e-8


def _reference_functionals():
    files = sorted(glob.glob(os.path.join(REF_DIR, "*.dat")))
    return [os.path.splitext(os.path.basename(f))[0] for f in files]


def _load_reference(func):
    """[(atom, spin, npts, converged, E_xc), ...] from the reference file."""
    rows = []
    with open(os.path.join(REF_DIR, func + ".dat")) as fh:
        for line in fh:
            if line.startswith("#") or not line.strip():
                continue
            atom, spin, npts, conv, energy = line.split()
            rows.append((atom, spin, int(npts), bool(int(conv)), float(energy)))
    return rows


if aoc.have_atomicorbitals():
    import pylibxc
    _AVAILABLE = set(pylibxc.util.xc_available_functional_names())
else:  # pragma: no cover - the whole module is skipped
    _AVAILABLE = set()


@pytest.mark.parametrize("func", _reference_functionals())
def test_atomic_energy(func):
    if func not in _AVAILABLE:
        pytest.skip(f"{func} not available in this build")
    fevals = {s: pylibxc.LibXCFunctional(func, s) for s in aoc.SPINS}
    if not fevals["unpolarized"]._have_exc:
        pytest.skip(f"{func} has no energy density in this build")

    # 3D functionals are probed on atoms, 1D/2D on model quantum wires/dots.
    dim = mc.dimensionality(func)
    sweep = ac.get_sweep() if dim == 3 else mc.get_sweep(dim)
    rows = _load_reference(func)

    # Group by (spin, npts) so each grid is evaluated once per spin.
    want = {}
    for atom, spin, npts, conv, energy in rows:
        want.setdefault((spin, npts), []).append((atom, conv, energy))

    got = {}
    for (spin, npts), items in want.items():
        e = sweep.energies(fevals[spin], spin, npts)
        for atom, conv, energy in items:
            got[(atom, spin)] = e[atom]

    mismatches = []
    for atom, spin, npts, conv, expected in rows:
        if not np.isfinite(expected):
            continue  # deep-tail instability in the reference; nothing to check
        g = got[(atom, spin)]
        if not conv:
            # Pathological quadrature: the reference value is not reproducible,
            # only require the energy to stay finite (guards NaN/inf blow-ups).
            if not np.isfinite(g):
                mismatches.append(f"  {atom:4s} {spin:11s} non-finite energy "
                                  f"{g} at {npts} points (pathological)")
            continue
        if not np.isclose(g, expected, rtol=RTOL, atol=ATOL):
            mismatches.append(
                f"  {atom:4s} {spin:11s} got {g: .10e} ref {expected: .10e} "
                f"(dE {g - expected: .2e}, {npts} points)")

    assert not mismatches, (
        f"{func}: atomic energy mismatch on {len(mismatches)} case(s):\n"
        + "\n".join(mismatches))
