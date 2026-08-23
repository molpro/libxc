"""Atomic Fock-matrix quadrature convergence -- a second facility diagnostic.

The energy-convergence band (atomic_convergence.py) measures how quickly the XC
*energy* converges with the radial grid. The XC *potential* is a derivative of
the energy, so it is more tail-sensitive and can converge more slowly (SCAN is
the striking example). This module classifies the convergence of the atomic XC
Fock matrix elements F_a = <a|v_xc|a> the same way, giving a second band.

Because it needs only vxc (not the energy), it also classifies the model
potentials (Becke-Johnson, Tran-Blaha, van Leeuwen-Baerends, ...) that have no
energy band at all. 3D functionals use the atomic shells; 1D/2D use the
harmonic-oscillator wire/dot shells, exactly as the energy tier.
"""
import os
import sys
from math import pi

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_energies_common as aoc  # noqa: E402
import atomic_convergence as ac  # noqa: E402
import atomic_fock_common as afc  # noqa: E402


def _make_batch(dim, n):
    """A bare _ShellFock on an n-point grid: atoms (3D) or one HO system (1D/2D)."""
    b = afc._ShellFock.__new__(afc._ShellFock)
    ao = aoc._import_ao()
    _, r, wt = ao.GridGenerator.make_grid(n)
    b.r = r
    if dim == 3:
        b.weight = 4.0 * pi * wt
        b.atoms = list(ac.CONV_ATOMS)
        b.shells = {a: afc._atom_shells(a, r) for a in b.atoms}
    else:
        w_rad = wt / (r * r)
        b.weight = 2.0 * w_rad if dim == 1 else 2.0 * pi * r * w_rad
        b.atoms = [f"HO{dim}D"]
        b.shells = {b.atoms[0]: afc._model_shells(dim, r)}
    return b


def dimensionality(func):
    """1/2/3 from the flags for any functional with a potential (else None)."""
    import pylibxc
    from pylibxc import flags
    f = pylibxc.LibXCFunctional(func, "unpolarized")
    if not f._have_vxc:
        return None
    fl = f.get_flags()
    if fl & flags.XC_FLAGS_3D:
        return 3
    if fl & flags.XC_FLAGS_2D:
        return 2
    if fl & flags.XC_FLAGS_1D:
        return 1
    return None


class FockSweep:
    """Per-grid _ShellFock batches for one dimensionality, built once."""

    def __init__(self, dim, grids=ac.GRIDS):
        self.dim = dim
        self.grids = list(grids)
        self.batch = {n: _make_batch(dim, n) for n in self.grids}

    def fock_vector(self, feval, spin, n):
        b = self.batch[n]
        # concatenate the Fock matrices of every system into one vector
        return np.concatenate([b.fock(feval, spin, s, b.occ0(s))
                               for s in b.atoms])


def _fock_n0(f_by_grid, grids):
    """Smallest grid above which the whole Fock vector is converged to CONV_ATOL."""
    ref = f_by_grid[grids[-1]]
    coarse = grids[:-1]
    for i, n in enumerate(coarse):
        if all(np.max(np.abs(f_by_grid[m] - ref)) <= ac.CONV_ATOL
               for m in coarse[i:]):
            return n
    return None


def classify(sweep, func):
    """{'n0', 'band'} for the Fock matrix, or None if the functional has no vxc.

    N0 is the max over spins and probe systems; None (pathological) if any case
    fails to converge to microhartree within the sweep.
    """
    import pylibxc
    n0_func = 0
    converged = True
    for spin in aoc.SPINS:
        feval = pylibxc.LibXCFunctional(func, spin)
        if not feval._have_vxc:
            return None
        f_by_grid = {n: sweep.fock_vector(feval, spin, n) for n in sweep.grids}
        n0 = _fock_n0(f_by_grid, sweep.grids)
        if n0 is None:
            converged = False
        elif converged:
            n0_func = max(n0_func, n0)
    n0 = n0_func if converged else None
    return {"n0": n0, "band": ac.convergence_band(n0)}


_SWEEPS = {}


def get_sweep(dim):
    if dim not in _SWEEPS:
        _SWEEPS[dim] = FockSweep(dim)
    return _SWEEPS[dim]


def _main(argv):
    import pylibxc
    funcs = argv or sorted(pylibxc.util.xc_available_functional_names())
    print(f"{'functional':30s} {'dim':>3s} {'N0':>6s}  fock band")
    for func in funcs:
        dim = dimensionality(func)
        if dim is None:
            continue
        res = classify(get_sweep(dim), func)
        n0 = res["n0"]
        print(f"{func:30s} {dim:>3d} {('inf' if n0 is None else n0):>6}  "
              f"{res['band']}")


if __name__ == "__main__":
    _main(sys.argv[1:])
