"""Atomic-quadrature convergence classification of the XC energy.

For a fixed density the total XC energy of a functional must converge quickly
to the radial-quadrature limit for the functional to be usable in practice.
Many recent functionals do not: the SCAN family and others need thousands of
radial points, or never reach microhartree precision at all (Lehtola and
Marques, J. Chem. Phys. 157, 174114 (2022)).

This module reproduces that measurement from the current build. For each
functional it integrates E_xc on the accurate Koga Hartree-Fock densities of
the paper's probe atoms over a doubling sequence of radial grids and finds the
convergence point N0: the smallest grid above which *every* finer grid in the
sequence agrees with the finest to CONV_ATOL, for every probe atom (the atom
that converges slowest sets N0). N0 is then mapped to a verbal band.

N0 is both the well-behavedness diagnostic (a pathological functional never
converges -> N0 is None) and the honest grid at which to store a physically
converged reference energy for the regression test.
"""
import os
import sys
from math import pi

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_energies_common as aoc  # noqa: E402

# Doubling sequence of radial grids; the finest is the reference for |dE|.
GRIDS = [25, 50, 100, 200, 400, 800, 1600, 3200]

# The atoms studied in Lehtola & Marques (2022). Different atoms converge
# differently for a given functional, so N0 is taken over all of them.
CONV_ATOMS = ["LI", "N", "NE", "NA", "P", "AR"]

# Convergence criterion: microhartree, the accuracy target for total energies
# and the threshold used in the reference paper.
CONV_ATOL = 1.0e-6


def convergence_band(n0):
    """Verbal characterisation of a functional's quadrature convergence.

    n0 is the convergence point in radial points (None if the functional never
    converges within the sweep). Bands follow the practical grid sizes at which
    quantum-chemistry codes evaluate functionals of increasing difficulty.
    """
    if n0 is None:
        return "pathological"
    if n0 < 50:
        return "trivial"
    if n0 < 150:
        return "normal"
    if n0 < 350:
        return "medium"
    if n0 < 1000:
        return "hard"
    return "pathological"


class SweepBatch:
    """Probe-atom densities on every grid, concatenated for one call per grid."""

    def __init__(self, grids=GRIDS, atoms=CONV_ATOMS):
        ao = aoc._import_ao()
        self.grids = list(grids)
        self.atoms = list(atoms)
        self.per_grid = {}
        for n in self.grids:
            _, r, wt = ao.GridGenerator.make_grid(n)
            npts = r.size
            slices = {a: slice(i * npts, (i + 1) * npts)
                      for i, a in enumerate(self.atoms)}
            weight = np.tile(4.0 * pi * wt, len(self.atoms))
            inputs, rho_total = {}, {}
            for spin in aoc.SPINS:
                per_atom = [aoc._atom_input(ao, a, r, spin) for a in self.atoms]
                keys = per_atom[0].keys()
                inp = {k: np.concatenate([p[k] for p in per_atom], axis=0)
                       for k in keys}
                inputs[spin] = inp
                rho = inp["rho"]
                rho_total[spin] = rho if rho.ndim == 1 else rho.sum(axis=1)
            self.per_grid[n] = (slices, weight, inputs, rho_total)

    def energies(self, feval, spin, n):
        """Integrated XC energy per probe atom on the n-point grid."""
        slices, weight, inputs, rho_total = self.per_grid[n]
        ret = feval.compute(inputs[spin], do_exc=True, do_vxc=False)
        zk = np.asarray(ret["zk"]).reshape(rho_total[spin].shape)
        integrand = zk * rho_total[spin] * weight
        return {a: float(integrand[slices[a]].sum()) for a in self.atoms}


def _atom_n0(energies_by_grid, grids, atom):
    """Convergence point and its energy for one atom.

    Returns (n0, E(n0)): n0 is the smallest grid above which every finer grid
    up to the finest agrees with the finest to CONV_ATOL. The tabulated energy
    is the value *at n0* -- converged to microhartree by construction and the
    grid the regression test re-evaluates, so the comparison is same-grid and
    reproducible. If the atom never converges, returns (None, E(finest)).
    """
    eref = energies_by_grid[grids[-1]][atom]
    coarse = grids[:-1]
    for i, n in enumerate(coarse):
        if all(abs(energies_by_grid[m][atom] - eref) <= CONV_ATOL
               for m in coarse[i:]):
            return n, energies_by_grid[n][atom]
    return None, eref


def classify(sweep, func):
    """Return {'n0', 'band', 'per_atom': {atom: (n0, E_converged)}} or None.

    None if the functional cannot be characterised on 3D atomic densities: it
    has no energy density (a model potential) or it is a 1D/2D functional (the
    probe atoms are 3D -- 1D/2D functionals must be checked on 1D/2D data). N0
    for the functional is the max over probe atoms and spins; None
    (pathological) if any probe case fails to converge within the sweep.
    """
    import pylibxc
    from pylibxc import flags
    per_case = {}
    n0_func = 0
    converged = True
    for spin in aoc.SPINS:
        feval = pylibxc.LibXCFunctional(func, spin)
        if not feval._have_exc:
            return None
        if not (feval.get_flags() & flags.XC_FLAGS_3D):
            return None  # 1D/2D functional: wrong data for the 3D atomic probe
        e_by_grid = {n: sweep.energies(feval, spin, n) for n in sweep.grids}
        for atom in sweep.atoms:
            n0, eref = _atom_n0(e_by_grid, sweep.grids, atom)
            per_case[(spin, atom)] = (n0, eref)
            if n0 is None:
                converged = False
            elif converged:
                n0_func = max(n0_func, n0)
    n0 = n0_func if converged else None
    return {"n0": n0, "band": convergence_band(n0), "per_case": per_case}


_SWEEP = None


def get_sweep():
    """Cached SweepBatch (build the probe densities only once per process)."""
    global _SWEEP
    if _SWEEP is None:
        _SWEEP = SweepBatch()
    return _SWEEP


def _main(argv):
    import pylibxc
    funcs = argv or sorted(pylibxc.util.xc_available_functional_names())
    sweep = SweepBatch()
    print(f"{'functional':32s} {'N0':>6s}  band")
    for func in funcs:
        res = classify(sweep, func)
        if res is None:
            print(f"{func:32s} {'--':>6s}  (model potential, no energy)")
            continue
        n0 = res["n0"]
        print(f"{func:32s} {('inf' if n0 is None else n0):>6}  {res['band']}")


if __name__ == "__main__":
    _main(sys.argv[1:])
