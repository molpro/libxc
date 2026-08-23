"""Physical consistency tests for the functional derivatives (vxc, fxc).

The XC potential and kernel are validated against the energy on real atomic
densities through a uniform density-scaling response. With

    rho_xi = xi rho,  sigma_xi = xi^2 sigma,  tau_xi = xi tau,  lapl_xi = xi lapl,

the analytic derivatives assembled from libxc must reproduce finite differences
of the energy along xi:

    dE/dxi|_1   = integral ( vrho.rho + 2 vsigma.sigma + vtau.tau + vlapl.lapl )   (vxc)
    d2E/dxi^2|_1 = integral ( direction^T . fxc . direction + vsigma.2sigma )      (fxc)

Both fold every derivative channel as it actually enters a calculation, so --
like any matrix element -- the exponentially decaying density suppresses the
tail; these tests are the physical complement to the unweighted pointwise
tests, not a substitute (they cannot see tail pathology).

The check is a per-density identity, so a small set of atoms spanning the s/p/d
shells and light-to-heavy nuclei is enough; all of them are concatenated into a
single pylibxc call per functional.
"""
import os
import sys
from math import pi

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_energies_common as aoc  # noqa: E402

have_atomicorbitals = aoc.have_atomicorbitals
SPINS = aoc.SPINS

# Representative atoms: 1-electron H, closed s (He), open s (Li), spin-polarized
# half-filled p (N), closed p (Ne, Ar) and heavy Kr/Xe.
DERIV_ATOMS = ["H", "HE", "LI", "N", "NE", "AR", "KR", "XE"]

FD_STEP = 1e-4


def _col(ret, key, shape):
    if key not in ret:
        return np.zeros(shape)
    a = np.asarray(ret[key])
    if isinstance(shape, int):        # unpolarized: normalise (N,1)/(N,) -> (N,)
        return a.reshape(-1)
    return a.reshape(shape[0], shape[1])


class DerivBatch:
    """All DERIV_ATOMS concatenated, for one pylibxc call per functional/spin."""

    def __init__(self):
        ao = aoc._import_ao()
        _, r, wt = ao.GridGenerator.make_grid(aoc.GRID_POINTS)
        npts = r.size
        self.atoms = list(DERIV_ATOMS)
        self.slices = {a: slice(i * npts, (i + 1) * npts)
                       for i, a in enumerate(self.atoms)}
        self.weight = np.tile(4.0 * pi * wt, len(self.atoms))
        self.base = {}
        for spin in SPINS:
            per_atom = [aoc._atom_input(ao, a, r, spin) for a in self.atoms]
            keys = per_atom[0].keys()
            self.base[spin] = {k: np.concatenate([p[k] for p in per_atom], axis=0)
                               for k in keys}

    def _scaled(self, spin, xi):
        b = self.base[spin]
        return {"rho": xi * b["rho"], "sigma": xi * xi * b["sigma"],
                "tau": xi * b["tau"], "lapl": xi * b["lapl"]}

    def _per_atom(self, integrand):
        return {a: float(np.dot(integrand[self.slices[a]], self.weight[self.slices[a]]))
                for a in self.atoms}

    def energy(self, feval, spin, xi):
        inp = self._scaled(spin, xi)
        zk = np.asarray(feval.compute(inp, do_exc=True, do_vxc=False)["zk"]).ravel()
        rho = inp["rho"]
        rho_total = rho if rho.ndim == 1 else rho.sum(axis=1)
        return self._per_atom(zk * rho_total)

    def vxc_fold(self, feval, spin, xi):
        """Per-atom analytic dE/dxi along the scaling path at scaling xi."""
        b = self.base[spin]
        inp = self._scaled(spin, xi)
        ret = feval.compute(inp, do_exc=False, do_vxc=True)
        unpol = b["rho"].ndim == 1
        if unpol:
            N = b["rho"].shape[0]
            val = (_col(ret, "vrho", N) * b["rho"]
                   + _col(ret, "vsigma", N) * 2 * xi * b["sigma"]
                   + _col(ret, "vtau", N) * b["tau"]
                   + _col(ret, "vlapl", N) * b["lapl"])
        else:
            N = b["rho"].shape[0]
            val = ((_col(ret, "vrho", (N, 2)) * b["rho"]).sum(1)
                   + (_col(ret, "vsigma", (N, 3)) * 2 * xi * b["sigma"]).sum(1)
                   + (_col(ret, "vtau", (N, 2)) * b["tau"]).sum(1)
                   + (_col(ret, "vlapl", (N, 2)) * b["lapl"]).sum(1))
        return self._per_atom(val)

    def fxc_fold(self, feval, spin):
        """Per-atom analytic d2E/dxi^2 at xi=1 (scaling contraction of fxc)."""
        b = self.base[spin]
        ret = feval.compute(b, do_exc=False, do_vxc=True, do_fxc=True)
        q = (_fxc_quadratic_unpol(ret, b) if b["rho"].ndim == 1
             else _fxc_quadratic_pol(ret, b))
        return self._per_atom(q)


def _fxc_quadratic_unpol(ret, b):
    rho, sig, tau, lap = b["rho"], b["sigma"], b["tau"], b["lapl"]
    dR, dS, dT, dL = rho, 2 * sig, tau, lap
    N = rho.shape[0]
    def G(k): return _col(ret, k, N)
    return (G("v2rho2") * dR * dR + 2 * G("v2rhosigma") * dR * dS
            + 2 * G("v2rhotau") * dR * dT + 2 * G("v2rholapl") * dR * dL
            + G("v2sigma2") * dS * dS + 2 * G("v2sigmatau") * dS * dT
            + 2 * G("v2sigmalapl") * dS * dL + G("v2tau2") * dT * dT
            + 2 * G("v2lapltau") * dT * dL + G("v2lapl2") * dL * dL
            + G("vsigma") * 2 * sig)


def _fxc_quadratic_pol(ret, b):
    N = b["rho"].shape[0]
    dR, dS, dT, dL = b["rho"], 2 * b["sigma"], b["tau"], b["lapl"]
    C = lambda k, n: _col(ret, k, (N, n))

    def sym2(v2, d):
        return v2[:, 0] * d[:, 0] ** 2 + 2 * v2[:, 1] * d[:, 0] * d[:, 1] + v2[:, 2] * d[:, 1] ** 2

    def sym3(v2, d):
        return (v2[:, 0] * d[:, 0] ** 2 + 2 * v2[:, 1] * d[:, 0] * d[:, 1]
                + 2 * v2[:, 2] * d[:, 0] * d[:, 2] + v2[:, 3] * d[:, 1] ** 2
                + 2 * v2[:, 4] * d[:, 1] * d[:, 2] + v2[:, 5] * d[:, 2] ** 2)

    def off(v2, da, db, na, nb):
        s = 0.0
        for i in range(na):
            for j in range(nb):
                s = s + v2[:, i * nb + j] * da[:, i] * db[:, j]
        return 2 * s

    return (sym2(C("v2rho2", 3), dR) + sym3(C("v2sigma2", 6), dS)
            + sym2(C("v2lapl2", 3), dL) + sym2(C("v2tau2", 3), dT)
            + off(C("v2rhosigma", 6), dR, dS, 2, 3)
            + off(C("v2rholapl", 4), dR, dL, 2, 2)
            + off(C("v2rhotau", 4), dR, dT, 2, 2)
            + off(C("v2sigmalapl", 6), dS, dL, 3, 2)
            + off(C("v2sigmatau", 6), dS, dT, 3, 2)
            + off(C("v2lapltau", 4), dL, dT, 2, 2)
            + (C("vsigma", 3) * 2 * b["sigma"]).sum(1))


_BATCH = None


def get_batch():
    global _BATCH
    if _BATCH is None:
        _BATCH = DerivBatch()
    return _BATCH
