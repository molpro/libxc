"""Quadrature convergence of 1D and 2D functionals on model densities.

The atomic probe of atomic_convergence.py is three-dimensional, so it cannot
characterise the 1D and 2D functionals (a handful of model-system functionals:
1D quantum wires, 2D parabolic quantum dots). Those are exercised here on the
densities they were designed for: harmonic-oscillator orbitals, whose density,
gradient, Laplacian and kinetic-energy density are all closed form. The
Gaussian tail still drives the reduced gradient s -> infinity, so a functional
with pathological large-s behaviour shows the same slow convergence there as on
an atom.

The radial nodes are reused from the 3D grid generator with the
dimension-appropriate Jacobian (1D: dx over |x|>=0 doubled; 2D: 2*pi*r*dr), so
the point counts -- and hence the convergence bands -- are directly comparable
to the atomic tier.
"""
import os
import sys
from math import pi, sqrt

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_energies_common as aoc  # noqa: E402
import atomic_convergence as ac  # noqa: E402

# Confinement strengths omega, the model "systems" (analogous to the atoms);
# each probes a different density scale / reduced-gradient range.
OMEGAS = [0.5, 2.0, 8.0]


def _label(omega):
    return f"w{omega:g}"


def _gauss_fields(dim, omega, r, n_occ):
    """Density fields of n_occ electrons in the dim-D harmonic ground orbital.

    phi = C exp(-omega r^2 / 2), normalised in dim dimensions. Returns the
    channel density and its sigma/lapl/tau contributions (all per given
    occupation), evaluated on the radial nodes r (r = |x| in 1D).
    """
    c2 = (omega / pi) ** (dim / 2.0)          # |C|^2, so phi^2 = c2 exp(-w r^2)
    phi2 = c2 * np.exp(-omega * r * r)
    rho = n_occ * phi2
    # grad rho = -2 omega r rho  =>  |grad rho|^2
    sigma = 4.0 * omega * omega * r * r * rho * rho
    # laplacian in dim dims: lap phi^2 = 2 phi^2 (2 w^2 r^2 - dim w)
    lapl = 2.0 * rho * (2.0 * omega * omega * r * r - dim * omega)
    # tau = 1/2 sum |grad phi_i|^2 = 1/2 omega^2 r^2 rho
    tau = 0.5 * omega * omega * r * r * rho
    return rho, sigma, lapl, tau


def _system_input(dim, omega, r, spin):
    """pylibxc input for a model system: 2-electron singlet (unpolarized) or a
    1-electron fully polarized doublet (polarized)."""
    if spin == "unpolarized":
        rho, sigma, lapl, tau = _gauss_fields(dim, omega, r, 2.0)
        return {"rho": rho, "sigma": sigma, "lapl": lapl, "tau": tau}
    ru, su, lu, tu = _gauss_fields(dim, omega, r, 1.0)  # spin-up: one electron
    z = np.zeros_like(ru)
    return {"rho": np.stack((ru, z), axis=1),
            "sigma": np.stack((su, z, z), axis=1),
            "lapl": np.stack((lu, z), axis=1),
            "tau": np.stack((tu, z), axis=1)}


class ModelSweep:
    """Model-system densities on every grid for one dimensionality (1 or 2)."""

    def __init__(self, dim, grids=ac.GRIDS, omegas=OMEGAS):
        self.dim = dim
        self.grids = list(grids)
        self.atoms = [_label(w) for w in omegas]   # "systems", named like atoms
        self._omega = dict(zip(self.atoms, omegas))
        ao = aoc._import_ao()
        self.per_grid = {}
        for n in self.grids:
            _, r, wt = ao.GridGenerator.make_grid(n)
            npts = r.size
            # recover the pure radial weight (make_grid folds in the 3D r^2),
            # then apply the dim-D Jacobian.
            w_rad = wt / (r * r)
            if dim == 1:
                jac = 2.0 * w_rad                    # |x| in [0, inf), doubled
            else:
                jac = 2.0 * pi * r * w_rad           # 2D: 2 pi r dr
            slices = {a: slice(i * npts, (i + 1) * npts)
                      for i, a in enumerate(self.atoms)}
            weight = np.tile(jac, len(self.atoms))
            inputs, rho_total = {}, {}
            for spin in aoc.SPINS:
                per = [_system_input(dim, self._omega[a], r, spin)
                       for a in self.atoms]
                keys = per[0].keys()
                inp = {k: np.concatenate([p[k] for p in per], axis=0)
                       for k in keys}
                inputs[spin] = inp
                rho = inp["rho"]
                rho_total[spin] = rho if rho.ndim == 1 else rho.sum(axis=1)
            self.per_grid[n] = (slices, weight, inputs, rho_total)

    def energies(self, feval, spin, n):
        slices, weight, inputs, rho_total = self.per_grid[n]
        ret = feval.compute(inputs[spin], do_exc=True, do_vxc=False)
        zk = np.asarray(ret["zk"]).reshape(rho_total[spin].shape)
        integrand = zk * rho_total[spin] * weight
        return {a: float(integrand[slices[a]].sum()) for a in self.atoms}


def classify(sweep, func):
    """Convergence classification of a 1D/2D functional (see ac.classify)."""
    import pylibxc
    per_case = {}
    n0_func = 0
    converged = True
    for spin in aoc.SPINS:
        feval = pylibxc.LibXCFunctional(func, spin)
        if not feval._have_exc:
            return None
        e_by_grid = {n: sweep.energies(feval, spin, n) for n in sweep.grids}
        for a in sweep.atoms:
            n0, eref = ac._atom_n0(e_by_grid, sweep.grids, a)
            per_case[(spin, a)] = (n0, eref)
            if n0 is None:
                converged = False
            elif converged:
                n0_func = max(n0_func, n0)
    n0 = n0_func if converged else None
    return {"n0": n0, "band": ac.convergence_band(n0), "per_case": per_case}


_SWEEPS = {}


def get_sweep(dim):
    if dim not in _SWEEPS:
        _SWEEPS[dim] = ModelSweep(dim)
    return _SWEEPS[dim]


def dimensionality(func):
    """1, 2 or 3 from the functional's flags (None if it has no energy)."""
    import pylibxc
    from pylibxc import flags
    f = pylibxc.LibXCFunctional(func, "unpolarized")
    if not f._have_exc:
        return None
    fl = f.get_flags()
    if fl & flags.XC_FLAGS_3D:
        return 3
    if fl & flags.XC_FLAGS_2D:
        return 2
    if fl & flags.XC_FLAGS_1D:
        return 1
    return None


def _main(argv):
    import pylibxc
    funcs = argv or sorted(pylibxc.util.xc_available_functional_names())
    sweeps = {1: get_sweep(1), 2: get_sweep(2)}
    print(f"{'functional':28s} {'dim':>3s} {'N0':>6s}  band")
    for func in funcs:
        dim = dimensionality(func)
        if dim not in (1, 2):
            continue
        res = classify(sweeps[dim], func)
        n0 = res["n0"]
        print(f"{func:28s} {dim:>3d} {('inf' if n0 is None else n0):>6}  "
              f"{res['band']}")


if __name__ == "__main__":
    _main(sys.argv[1:])
