#!/usr/bin/env python3
"""Regenerate pylibxc/example_densities.py.

The test densities come from model systems with closed-form wave
functions, one per spatial dimension, so that every functional is
exercised on data that actually lives in its own dimensionality
(libxc carries XC_FLAGS_1D / _2D / _3D per functional):

* 3D -- neutral nitrogen (N: 1s2 2s2 2p3, 4S) from the tabulated Koga
  et al. (k99l) Slater-type wave function, parsed by AtomicOrbitals.
* 2D -- a parabolic quantum dot: the isotropic 2D harmonic oscillator,
  the canonical system behind the 2D(EG)/quantum-dot functionals
  (AMGB, PRM, PRHG07, ...).
* 1D -- a 1D harmonic well: the 1D harmonic oscillator.

Each system is set up open-shell so that, like nitrogen, it provides a
genuinely spin-polarized case (nspin=2) and, by summing the spin
channels, an unpolarized one (nspin=1).

Row layout (9 cols): [rho_up, rho_dn, sigma_uu, sigma_ud, sigma_dd,
                      lapl_up, lapl_dn, tau_up, tau_dn]
with sigma = grad(rho).grad(rho), lapl = laplacian(rho), and the
libxc kinetic-energy-density convention tau = 1/2 sum_i |grad phi_i|^2.
"""
import os
import sys

import numpy as np

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "atomic"))
from koga_hf import Atom  # vendored Koga HF densities (was AtomicOrbitals)

# Geometric radial grids from the core to the density tail.
RADII_3D = np.geomspace(0.01, 10.0, 20)
RADII_HO = np.geomspace(0.05, 5.0, 20)

# Harmonic-oscillator occupations (mirroring the open p-shell of N: each
# spin channel keeps a rotationally symmetric set of orbitals so the
# channel density stays radial). 1D: occupied levels n. 2D: occupied
# Cartesian levels (n_x, n_y); filling the whole n_x+n_y=1 shell keeps
# the density radial.
HO1D_OCC = {"up": [0, 1], "dn": [0]}
HO2D_OCC = {"up": [(0, 0), (1, 0), (0, 1)], "dn": [(0, 0)]}


def ho_states(x, nmax):
    """Normalized 1D harmonic-oscillator eigenfunctions psi_n(x) and
    their first two derivatives, for n = 0 .. nmax.

    Uses the normalized three-term recurrence for psi_n, the ladder
    relation psi_n' = sqrt(n/2) psi_{n-1} - sqrt((n+1)/2) psi_{n+1},
    and psi_n'' = (x^2 - (2n+1)) psi_n (the Schroedinger equation).
    """
    x = np.asarray(x, dtype=float)
    # psi_n for n = 0 .. nmax+1 (one extra level for the derivative ladder)
    psi = [np.zeros_like(x) for _ in range(nmax + 2)]
    psi[0] = np.pi ** (-0.25) * np.exp(-0.5 * x * x)
    if nmax + 1 >= 1:
        psi[1] = np.sqrt(2.0) * x * psi[0]
    for n in range(1, nmax + 1):
        psi[n + 1] = np.sqrt(2.0 / (n + 1)) * x * psi[n] \
            - np.sqrt(n / (n + 1)) * psi[n - 1]

    d1 = [np.zeros_like(x) for _ in range(nmax + 1)]
    d2 = [np.zeros_like(x) for _ in range(nmax + 1)]
    for n in range(nmax + 1):
        below = np.sqrt(n / 2.0) * psi[n - 1] if n >= 1 else 0.0
        d1[n] = below - np.sqrt((n + 1) / 2.0) * psi[n + 1]
        d2[n] = (x * x - (2 * n + 1)) * psi[n]
    return psi, d1, d2


def ho1d_signed(x, occ):
    """rho, signed grad(rho), lapl(rho), tau for a 1D HO spin channel."""
    nmax = max(occ)
    psi, d1, d2 = ho_states(x, nmax)
    rho = sum(psi[n] ** 2 for n in occ)
    grad = sum(2.0 * psi[n] * d1[n] for n in occ)
    lapl = sum(2.0 * (d1[n] ** 2 + psi[n] * d2[n]) for n in occ)
    tau = sum(0.5 * d1[n] ** 2 for n in occ)
    return rho, grad, lapl, tau


def ho2d_signed(r, occ):
    """rho, signed drho/dr, lapl(rho), tau for a 2D HO spin channel,
    evaluated along the ray (x=r, y=0). Each channel density is radial by
    construction, so this ray is the full radial profile; the gradient
    and laplacian come from the exact x/y partials of the product
    orbitals (drho/dy = 0 on the ray by symmetry)."""
    nmax = max(max(a, b) for a, b in occ)
    px, d1x, d2x = ho_states(r, nmax)
    py, d1y, d2y = ho_states(0.0, nmax)
    py = [float(v) for v in py]
    d1y = [float(v) for v in d1y]
    d2y = [float(v) for v in d2y]
    rho = sum((px[a] * py[b]) ** 2 for a, b in occ)
    drdx = sum(2.0 * px[a] * d1x[a] * py[b] ** 2 for a, b in occ)
    d2_x = sum(2.0 * (d1x[a] ** 2 + px[a] * d2x[a]) * py[b] ** 2 for a, b in occ)
    d2_y = sum(2.0 * px[a] ** 2 * (d1y[b] ** 2 + py[b] * d2y[b]) for a, b in occ)
    tau = sum(0.5 * ((d1x[a] * py[b]) ** 2 + (px[a] * d1y[b]) ** 2)
              for a, b in occ)
    # drho/dy = 0 along the y=0 ray by symmetry, so |grad rho| = |drho/dx|.
    return rho, drdx, d2_x + d2_y, tau


def n_rows(atom="N", r=RADII_3D):
    d0, d1, g0, g1, t0, t1, l0, l1 = Atom(atom).get_densities(r)
    out = []
    for i in range(len(r)):
        out += [d0[i], d1[i], g0[i] * g0[i], g0[i] * g1[i], g1[i] * g1[i],
                l0[i], l1[i], t0[i], t1[i]]
    return out


def ho_rows(grid, chan_fn, occ):
    up = chan_fn(grid, occ["up"])
    dn = chan_fn(grid, occ["dn"])
    d0, g0, l0, t0 = up
    d1, g1, l1, t1 = dn
    out = []
    for i in range(len(grid)):
        out += [d0[i], d1[i],
                g0[i] * g0[i], g0[i] * g1[i], g1[i] * g1[i],
                l0[i], l1[i], t0[i], t1[i]]
    return out


HEADER = '''from .array_backend import array_namespace
from .testing import asarray

'''

FOOTER = '''
def test_input(data, nspin):
    \'\'\'Prepares pylibxc compatible input from the density data\'\'\'
    inp = {}
    ns = array_namespace(data)

    rhoa = (data[:,0])
    rhob = (data[:,1])
    sigmaaa = (data[:,2])
    sigmaab = (data[:,3])
    sigmabb = (data[:,4])
    lapla = (data[:,5])
    laplb = (data[:,6])
    taua = (data[:,7])
    taub = (data[:,8])

    if nspin == 1:
        inp["rho"] = rhoa+rhob
        inp["sigma"] = sigmaaa + sigmabb + 2*sigmaab
        inp["lapl"] = lapla+laplb
        inp["tau"] = taua+taub
    else:
        inp["rho"] = ns.stack((rhoa, rhob), axis=1)
        inp["sigma"] = ns.stack((sigmaaa, sigmaab, sigmabb), axis=1)
        inp["lapl"] = ns.stack((lapla, laplb), axis=1)
        inp["tau"] = ns.stack((taua, taub), axis=1)

    return inp

# Test data keyed by system name, with the spatial dimension each system
# lives in. xc-generate_tests.py routes every functional to the systems
# whose dimension matches the functional's XC_FLAGS_1D/_2D/_3D flag.
test_data = {}
test_data['N'] = test_input(N_data, 2)
test_data['N_restr'] = test_input(N_data, 1)
test_data['HO2D'] = test_input(HO2D_data, 2)
test_data['HO2D_restr'] = test_input(HO2D_data, 1)
test_data['HO1D'] = test_input(HO1D_data, 2)
test_data['HO1D_restr'] = test_input(HO1D_data, 1)

# Spatial dimension of each system (3D atom, 2D quantum dot, 1D well).
test_data_dim = {
    'N': 3, 'N_restr': 3,
    'HO2D': 2, 'HO2D_restr': 2,
    'HO1D': 1, 'HO1D_restr': 1,
}
'''


def emit_array(name, data, comment):
    npts = len(data) // 9
    return "# %s\n%s_data = asarray([%s]).reshape((%d, 9))\n" % (
        comment, name, ", ".join("%.16e" % v for v in data), npts)


def main():
    arrays = [
        emit_array("N", n_rows(),
                   "3D: N atom (k99l Slater wave function)"),
        emit_array("HO2D", ho_rows(RADII_HO, ho2d_signed, HO2D_OCC),
                   "2D: parabolic quantum dot (2D harmonic oscillator)"),
        emit_array("HO1D", ho_rows(RADII_HO, ho1d_signed, HO1D_OCC),
                   "1D: harmonic well (1D harmonic oscillator)"),
    ]
    out = HEADER + "\n".join(arrays) + FOOTER
    dest = os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir,
                        "pylibxc", "example_densities.py")
    dest = os.path.abspath(dest)
    with open(dest, "w") as f:
        f.write(out)
    print("wrote %s (3D/2D/1D model systems, %d grid points each)"
          % (dest, len(RADII_HO)))


if __name__ == "__main__":
    main()
