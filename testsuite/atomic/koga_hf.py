"""Native evaluation of Hartree-Fock atomic densities on a radial grid.

Self-contained replacement for the AtomicOrbitals package so the atomic test
tier ships with libxc and needs no submodule. The Slater-orbital evaluation and
the Ahlrichs-M3 / modified-Gauss-Chebyshev radial grid are vendored verbatim
(so the numerics are bit-identical to the reference implementation), and the
Koga Hartree-Fock wavefunction tabulations for Z=1-54 (H-Xe) are embedded in
koga_hf_data.json.

Provenance and license: the code and the data-handling are taken from
AtomicOrbitals by James Furness and Susi Lehtola
(https://github.com/JFurness1/AtomicOrbitals), released into the public domain
under CC0. The tabulated wavefunctions are the analytic Hartree-Fock Slater
orbitals of Koga et al. (Z=1-54), supplied by A. J. Thakkar; cite

    T. Koga, K. Kanayama, S. Watanabe, A. J. Thakkar,
    Int. J. Quantum Chem. 71, 491 (1999); and
    T. Koga, K. Kanayama, T. Watanabe, T. Imai, A. J. Thakkar,
    Theor. Chem. Acc. 104, 411 (2000).

API mirrors what the tests use: ``Atom(sym).get_densities(r)`` and
``GridGenerator.make_grid(n)``.
"""
import json
import os
from math import factorial, log, pi

import numpy as np

_HERE = os.path.dirname(os.path.abspath(__file__))
with open(os.path.join(_HERE, "koga_hf_data.json")) as _fh:
    _DATA = json.load(_fh)


def available():
    """True if the embedded wavefunction data is present (always)."""
    return bool(_DATA)


def _shell(entry):
    if entry is None:
        return (None, None, None, [np.zeros(0), np.zeros(0)])
    n = np.asarray(entry["n"], dtype=int)
    exp = np.asarray(entry["exp"], dtype=float)
    coef = np.asarray(entry["coef"], dtype=float)
    occ = [np.asarray(entry["occ"][0], dtype=float),
           np.asarray(entry["occ"][1], dtype=float)]
    return n, exp, coef, occ


class Atom:
    """Hartree-Fock density of a neutral atom (symbol, upper- or lower-case)."""

    def __init__(self, element):
        self.element = element
        u_atom = element.upper()
        if u_atom not in _DATA:
            raise KeyError('Error: Atom data for "{:}" missing'.format(element))
        d = _DATA[u_atom]
        self.nuclear_charge = d["Z"]
        self.s_n, self.s_exp, self.s_coef, self.s_occ = _shell(d["s"])
        self.p_n, self.p_exp, self.p_coef, self.p_occ = _shell(d["p"])
        self.d_n, self.d_exp, self.d_coef, self.d_occ = _shell(d["d"])
        self.f_n, self.f_exp, self.f_coef, self.f_occ = _shell(d["f"])

    def get_densities(self, r):
        """(den, grd, tau, lap) x (spin 0, spin 1) on the radial points r."""
        if np.isscalar(r):
            r = np.array([r])
        assert np.min(r) > 0, "Error: distances must be non-zero and positive."

        if self.s_exp is not None:
            oS, doS, ddoS = self.get_orbitals(self.s_n, self.s_exp, self.s_coef, r)
            den_0 = np.sum(self.s_occ[0][:, None] * oS**2, axis=0)
            den_1 = np.sum(self.s_occ[1][:, None] * oS**2, axis=0)
            grd_0 = np.sum(self.s_occ[0][:, None] * (oS * doS), axis=0)
            grd_1 = np.sum(self.s_occ[1][:, None] * (oS * doS), axis=0)
            tau_0 = np.sum(self.s_occ[0][:, None] * doS**2, axis=0)
            tau_1 = np.sum(self.s_occ[1][:, None] * doS**2, axis=0)
            lap_s = oS * ddoS + doS**2 + 2 * oS * doS / r
            lap_0 = np.sum(self.s_occ[0][:, None] * lap_s, axis=0)
            lap_1 = np.sum(self.s_occ[1][:, None] * lap_s, axis=0)
        else:
            den_0 = np.zeros(r.shape); den_1 = np.zeros(r.shape)
            grd_0 = np.zeros(r.shape); grd_1 = np.zeros(r.shape)
            tau_0 = np.zeros(r.shape); tau_1 = np.zeros(r.shape)
            lap_0 = np.zeros(r.shape); lap_1 = np.zeros(r.shape)

        if self.p_exp is not None:
            oP, doP, ddoP = self.get_orbitals(self.p_n, self.p_exp, self.p_coef, r)
            den_0 += np.sum(self.p_occ[0][:, None] * oP**2, axis=0)
            den_1 += np.sum(self.p_occ[1][:, None] * oP**2, axis=0)
            grd_0 += np.sum(self.p_occ[0][:, None] * oP * doP, axis=0)
            grd_1 += np.sum(self.p_occ[1][:, None] * oP * doP, axis=0)
            tau_0 += np.sum(self.p_occ[0][:, None] * (doP**2 + 2 * (oP / r)**2), axis=0)
            tau_1 += np.sum(self.p_occ[1][:, None] * (doP**2 + 2 * (oP / r)**2), axis=0)
            lap_p = oP * ddoP + doP**2 + 2 * oP * doP / r
            lap_0 += np.sum(self.p_occ[0][:, None] * lap_p, axis=0)
            lap_1 += np.sum(self.p_occ[1][:, None] * lap_p, axis=0)

        if self.d_exp is not None:
            oD, doD, ddoD = self.get_orbitals(self.d_n, self.d_exp, self.d_coef, r)
            den_0 += np.sum(self.d_occ[0][:, None] * oD**2, axis=0)
            den_1 += np.sum(self.d_occ[1][:, None] * oD**2, axis=0)
            grd_0 += np.sum(self.d_occ[0][:, None] * oD * doD, axis=0)
            grd_1 += np.sum(self.d_occ[1][:, None] * oD * doD, axis=0)
            tau_0 += np.sum(self.d_occ[0][:, None] * (doD**2 + 6 * (oD / r)**2), axis=0)
            tau_1 += np.sum(self.d_occ[1][:, None] * (doD**2 + 6 * (oD / r)**2), axis=0)
            lap_d = oD * ddoD + doD**2 + 2 * oD * doD / r
            lap_0 += np.sum(self.d_occ[0][:, None] * lap_d, axis=0)
            lap_1 += np.sum(self.d_occ[1][:, None] * lap_d, axis=0)

        if self.f_exp is not None:
            oF, doF, ddoF = self.get_orbitals(self.f_n, self.f_exp, self.f_coef, r)
            den_0 += np.sum(self.f_occ[0][:, None] * oF**2, axis=0)
            den_1 += np.sum(self.f_occ[1][:, None] * oF**2, axis=0)
            grd_0 += np.sum(self.f_occ[0][:, None] * oF * doF, axis=0)
            grd_1 += np.sum(self.f_occ[1][:, None] * oF * doF, axis=0)
            tau_0 += np.sum(self.f_occ[0][:, None] * (doF**2 + 12 * (oF / r)**2), axis=0)
            tau_1 += np.sum(self.f_occ[1][:, None] * (doF**2 + 12 * (oF / r)**2), axis=0)
            lap_f = oF * ddoF + doF**2 + 2 * oF * doF / r
            lap_0 += np.sum(self.f_occ[0][:, None] * lap_f, axis=0)
            lap_1 += np.sum(self.f_occ[1][:, None] * lap_f, axis=0)

        den_0 /= 4 * pi; den_1 /= 4 * pi
        grd_0 /= 2 * pi; grd_1 /= 2 * pi
        tau_0 /= 8 * pi; tau_1 /= 8 * pi
        lap_0 /= 2 * pi; lap_1 /= 2 * pi
        return den_0, den_1, grd_0, grd_1, tau_0, tau_1, lap_0, lap_1

    def get_orbitals(self, q_numbers, exponents, coefficients, r):
        f = self.G(q_numbers, exponents, r)
        df = self.DG(q_numbers, exponents, r, f)
        ddf = self.DDG(q_numbers, exponents, r, f)
        of = np.einsum('ij,jk->ik', coefficients, f)
        dof = np.einsum('ij,jk->ik', coefficients, df)
        ddof = np.einsum('ij,jk->ik', coefficients, ddf)
        return of, dof, ddof

    def G(self, n, zeta, r):
        """Radial Slater orbital R(r) = N r^{n-1} exp(-zeta r)."""
        FACTORS = np.array([factorial(2 * nn) for nn in range(1, max(n) + 1)])**(-0.5)
        n_facs = FACTORS[n - 1]
        c = n_facs * (2.0 * zeta)**(n + 0.5)
        rn = np.power.outer(r, (n - 1))
        es = np.einsum('j,ij->ji', c, rn)
        pw = np.exp(-np.outer(zeta, r))
        return es * pw

    def DG(self, n, e, r, f):
        """R'(r) = [(n-1)/r - zeta] R(r)."""
        pre = -e[:, None] + np.divide.outer((n - 1), r)
        return pre * f

    def DDG(self, n, e, r, f):
        """R''(r) = {[(n-1)/r - zeta]^2 - (n-1)/r^2} R(r)."""
        pre = (-e[:, None] + np.divide.outer((n - 1), r))**2
        pre -= np.divide.outer((n - 1), r**2)
        return pre * f


class GridGenerator:
    """Ahlrichs-M3 radial grid with modified Gauss-Chebyshev quadrature."""

    @staticmethod
    def make_grid(n, method='ahlrichsm3', R=1.0, quad='chebyshev2_mod'):
        if method not in ('ahlrichsm3', 'krack') or quad != 'chebyshev2_mod':
            raise ValueError('only the ahlrichsm3 / chebyshev2_mod grid is '
                             'vendored')
        n, r, wt = GridGenerator.radial_ahlrichs(n)
        r = r[wt != 0.0]
        wt = wt[wt != 0.0]
        n = len(r)
        r = r * R
        wt = wt * R**3
        return n, r, wt

    @staticmethod
    def chebyshev2_modified(n):
        """Modified Gauss-Chebyshev of the 2nd kind on [-1, 1] (Perez-Jorda)."""
        oonpp = 1.0 / (n + 1.0)
        ivec = np.asarray([i for i in range(1, n + 1)])
        angles = ivec * pi * oonpp
        sines = np.sin(angles)
        cosines = np.cos(angles)
        sinesq = np.power(sines, 2)
        sinecos = np.multiply(sines, cosines)
        w = 16.0 / 3.0 / (n + 1.0) * np.power(sinesq, 2)
        x = 1.0 - 2.0 * ivec * oonpp + 2 / pi * np.multiply(1.0 + 2.0 / 3.0 * sinesq, sinecos)
        return n, x, w

    @staticmethod
    def radial_ahlrichs(n):
        """Treutler-Ahlrichs M3 (alpha=0) transform of the Chebyshev rule."""
        n, x, w = GridGenerator.chebyshev2_modified(n)
        r = 1.0 / log(2.0) * np.log(2.0 / (1.0 - x))
        dr = 1.0 / (log(2.0) * (1 - x))
        wr = w * dr * r**2
        return n, np.flip(r), np.flip(wr)
