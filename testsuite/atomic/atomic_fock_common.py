"""Atomic XC Fock- and kernel-matrix consistency tests.

The occupations of the atomic shells are treated as parameters. Writing the
density as a sum of shell contributions,

    rho(c) = sum_a c_a rho_a,   sigma(c) = |grad rho(c)|^2,   tau, lapl analogous,

every shell density rho_a is spherically symmetric, so rho(c) integrates on the
same radial grid as the energy. The derivatives of E_xc with respect to the
occupations are the XC Fock/response matrices in the shell basis:

    F_a  = dE/dc_a                  (order 1, from vxc -- the XC Fock matrix)
    K_ab = d^2E/dc_a dc_b           (order 2, from fxc -- the response kernel)

each checked against a finite difference of the order below. F_a is the diagonal
XC Fock matrix element <a|v_xc|a>; K is a full (off-diagonal) shell x shell
matrix. Both spin treatments are covered; a shell occupation scales both spin
channels of that shell by their actual occupations.

This is the basis-resolved complement to the uniform-scaling response of
atomic_derivatives_common.py: the same vxc/fxc channels, but exercised in the
matrix-element combinations a real Fock build uses.

The 1D/2D functionals are handled the same way on their own model bases: the
harmonic-oscillator levels of a quantum wire (1D) / dot (2D) play the role of
the atomic shells (FockBatch vs ModelFockBatch); the physics core is shared.
"""
import os
import sys
from math import pi

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_energies_common as aoc  # noqa: E402
import koga_hf  # noqa: E402

# Atoms spanning the shell structures cheaply: closed 1s (He), open 2p / spin
# polarized (N), closed 3s3p (Ar), and a 3d block (Kr).
FOCK_ATOMS = ["HE", "N", "AR", "KR"]

GRID_POINTS = 500
FD_STEP = 1.0e-4

# tau angular factor per l block (koga_hf.get_densities convention)
_ANG = {"s": 0.0, "p": 2.0, "d": 6.0, "f": 12.0}

# Model shell fillings: three lowest levels/shells, spin polarized (up fills one
# more than dn) so the polarized path is exercised.
_MODEL_OCC = {"up": [1, 1, 1], "dn": [1, 1, 0]}


def _atom_shells(atom, r):
    """Per occupied (n,l) shell: label and its [up, dn] density contributions.

    Mirrors koga_hf.Atom.get_densities but keeps each shell separate: fields[k]
    = [up_array, dn_array] for k in den/grd/tau/lap; grd is d(rho)/dr (radial).
    """
    a = koga_hf.Atom(atom)
    shells = []
    for b in ("s", "p", "d", "f"):
        exp = getattr(a, b + "_exp")
        if exp is None:
            continue
        n = getattr(a, b + "_n")
        coef = getattr(a, b + "_coef")
        occ = getattr(a, b + "_occ")
        o, do, ddo = a.get_orbitals(n, exp, coef, r)
        ang = _ANG[b]
        for i in range(o.shape[0]):
            up, dn = float(occ[0][i]), float(occ[1][i])
            if up + dn == 0.0:
                continue
            oi, doi, ddoi = o[i], do[i], ddo[i]
            den = oi**2 / (4 * pi)
            grd = (oi * doi) / (2 * pi)
            tau = (doi**2 + ang * (oi / r)**2) / (8 * pi)
            lap = (oi * ddoi + doi**2 + 2 * oi * doi / r) / (2 * pi)
            shells.append((f"{b}{i + 1}", {
                "den": [up * den, dn * den], "grd": [up * grd, dn * grd],
                "tau": [up * tau, dn * tau], "lap": [up * lap, dn * lap]}))
    return shells


def _col(ret, key, shape):
    if key not in ret:
        return np.zeros(shape)
    a = np.asarray(ret[key])
    return a.reshape(-1) if isinstance(shape, int) else a.reshape(shape)


class _ShellFock:
    """Shared physics from a per-shell density decomposition.

    A subclass sets self.r, self.weight, self.atoms (system labels) and
    self.shells (system -> list of (label, {den/grd/tau/lap: [up, dn]})). The
    energy, Fock matrix (order 1) and response kernel (order 2) then follow
    identically in any dimension, since sigma = (d rho/dr)^2 and the quadrature
    weight already carry the dimensionality.
    """

    def labels(self, atom):
        return [lbl for lbl, _ in self.shells[atom]]

    def occ0(self, atom):
        return np.ones(len(self.shells[atom]))

    # ---- density assembly from shell occupations c ----------------------
    def _fields(self, atom, c):
        up = {k: np.zeros_like(self.r) for k in ("den", "grd", "tau", "lap")}
        dn = {k: np.zeros_like(self.r) for k in ("den", "grd", "tau", "lap")}
        for (_, f), ca in zip(self.shells[atom], c):
            for k in up:
                up[k] = up[k] + ca * f[k][0]
                dn[k] = dn[k] + ca * f[k][1]
        return up, dn

    def _input(self, atom, spin, c):
        up, dn = self._fields(atom, c)
        if spin == "unpolarized":
            g = up["grd"] + dn["grd"]
            return {"rho": up["den"] + dn["den"], "sigma": g * g,
                    "tau": up["tau"] + dn["tau"], "lapl": up["lap"] + dn["lap"]}
        gu, gd = up["grd"], dn["grd"]
        return {"rho": np.stack((up["den"], dn["den"]), axis=1),
                "sigma": np.stack((gu * gu, gu * gd, gd * gd), axis=1),
                "tau": np.stack((up["tau"], dn["tau"]), axis=1),
                "lapl": np.stack((up["lap"], dn["lap"]), axis=1)}

    def _integrate(self, integrand):
        return float(np.dot(integrand, self.weight))

    # ---- order 0: energy ------------------------------------------------
    def energy(self, feval, spin, atom, c):
        inp = self._input(atom, spin, c)
        zk = np.asarray(feval.compute(inp, do_exc=True, do_vxc=False)["zk"]).ravel()
        rho = inp["rho"]
        rho_tot = rho if rho.ndim == 1 else rho.sum(axis=1)
        return self._integrate(zk * rho_tot)

    # ---- shell directions in libxc input space at occupations c ---------
    def _directions(self, atom, spin, c):
        """delta_a = d(rho,sigma,tau,lapl)/dc_a at c, per shell a."""
        up, dn = self._fields(atom, c)
        dirs = []
        for _, f in self.shells[atom]:
            if spin == "unpolarized":
                gtot = up["grd"] + dn["grd"]
                gA = f["grd"][0] + f["grd"][1]
                dirs.append({"R": f["den"][0] + f["den"][1],
                             "S": 2 * gtot * gA,
                             "T": f["tau"][0] + f["tau"][1],
                             "L": f["lap"][0] + f["lap"][1],
                             "gA": gA})
            else:
                gu, gd = up["grd"], dn["grd"]
                au, ad = f["grd"][0], f["grd"][1]
                dirs.append({
                    "R": (f["den"][0], f["den"][1]),
                    "S": (2 * gu * au, gu * ad + gd * au, 2 * gd * ad),
                    "T": (f["tau"][0], f["tau"][1]),
                    "L": (f["lap"][0], f["lap"][1]),
                    "gu": au, "gd": ad})
        return dirs

    # ---- order 1: Fock matrix (diagonal <a|v_xc|a>) ---------------------
    def fock(self, feval, spin, atom, c):
        inp = self._input(atom, spin, c)
        ret = feval.compute(inp, do_exc=False, do_vxc=True)
        N = self.r.size
        dirs = self._directions(atom, spin, c)
        out = []
        if spin == "unpolarized":
            vr, vs = _col(ret, "vrho", N), _col(ret, "vsigma", N)
            vt, vl = _col(ret, "vtau", N), _col(ret, "vlapl", N)
            for d in dirs:
                out.append(self._integrate(
                    vr * d["R"] + vs * d["S"] + vt * d["T"] + vl * d["L"]))
        else:
            vr = _col(ret, "vrho", (N, 2)); vs = _col(ret, "vsigma", (N, 3))
            vt = _col(ret, "vtau", (N, 2)); vl = _col(ret, "vlapl", (N, 2))
            for d in dirs:
                R, S, T, L = d["R"], d["S"], d["T"], d["L"]
                out.append(self._integrate(
                    vr[:, 0] * R[0] + vr[:, 1] * R[1]
                    + vs[:, 0] * S[0] + vs[:, 1] * S[1] + vs[:, 2] * S[2]
                    + vt[:, 0] * T[0] + vt[:, 1] * T[1]
                    + vl[:, 0] * L[0] + vl[:, 1] * L[1]))
        return np.array(out)

    # ---- order 2: response kernel K_ab (bilinear fxc contraction) -------
    def kernel(self, feval, spin, atom, c):
        inp = self._input(atom, spin, c)
        ret = feval.compute(inp, do_exc=False, do_vxc=True, do_fxc=True)
        N = self.r.size
        dirs = self._directions(atom, spin, c)
        n = len(dirs)
        K = np.zeros((n, n))
        bil = self._bilinear_unpol if spin == "unpolarized" else self._bilinear_pol
        for a in range(n):
            for b in range(a, n):
                K[a, b] = K[b, a] = self._integrate(bil(ret, N, dirs[a], dirs[b]))
        return K

    def _bilinear_unpol(self, ret, N, da, db):
        g = lambda k: _col(ret, k, N)  # noqa: E731
        Ra, Sa, Ta, La = da["R"], da["S"], da["T"], da["L"]
        Rb, Sb, Tb, Lb = db["R"], db["S"], db["T"], db["L"]
        s2 = 2 * da["gA"] * db["gA"]                     # d^2 sigma / dc_a dc_b
        return (g("v2rho2") * Ra * Rb
                + g("v2rhosigma") * (Ra * Sb + Sa * Rb)
                + g("v2rhotau") * (Ra * Tb + Ta * Rb)
                + g("v2rholapl") * (Ra * Lb + La * Rb)
                + g("v2sigma2") * Sa * Sb
                + g("v2sigmatau") * (Sa * Tb + Ta * Sb)
                + g("v2sigmalapl") * (Sa * Lb + La * Sb)
                + g("v2tau2") * Ta * Tb
                + g("v2lapltau") * (Ta * Lb + La * Tb)
                + g("v2lapl2") * La * Lb
                + g("vsigma") * s2)

    def _bilinear_pol(self, ret, N, da, db):
        C = lambda k, m: _col(ret, k, (N, m))  # noqa: E731

        def bil2(v2, a, b):   # symmetric 2x2 block
            return (v2[:, 0] * a[0] * b[0] + v2[:, 1] * (a[0] * b[1] + a[1] * b[0])
                    + v2[:, 2] * a[1] * b[1])

        def bil3(v2, a, b):   # symmetric 3x3 block
            return (v2[:, 0] * a[0] * b[0] + v2[:, 1] * (a[0] * b[1] + a[1] * b[0])
                    + v2[:, 2] * (a[0] * b[2] + a[2] * b[0]) + v2[:, 3] * a[1] * b[1]
                    + v2[:, 4] * (a[1] * b[2] + a[2] * b[1]) + v2[:, 5] * a[2] * b[2])

        def offb(v2, aX, aY, bX, bY, nx, ny):  # cross block X(nx) x Y(ny)
            s = 0.0
            for i in range(nx):
                for j in range(ny):
                    s = s + v2[:, i * ny + j] * (aX[i] * bY[j] + aY[j] * bX[i])
            return s

        Ra, Sa, Ta, La = da["R"], da["S"], da["T"], da["L"]
        Rb, Sb, Tb, Lb = db["R"], db["S"], db["T"], db["L"]
        vsig = C("vsigma", 3)
        s2 = (2 * da["gu"] * db["gu"], da["gu"] * db["gd"] + da["gd"] * db["gu"],
              2 * da["gd"] * db["gd"])
        return (bil2(C("v2rho2", 3), Ra, Rb) + bil3(C("v2sigma2", 6), Sa, Sb)
                + bil2(C("v2lapl2", 3), La, Lb) + bil2(C("v2tau2", 3), Ta, Tb)
                + offb(C("v2rhosigma", 6), Ra, Sa, Rb, Sb, 2, 3)
                + offb(C("v2rholapl", 4), Ra, La, Rb, Lb, 2, 2)
                + offb(C("v2rhotau", 4), Ra, Ta, Rb, Tb, 2, 2)
                + offb(C("v2sigmalapl", 6), Sa, La, Sb, Lb, 3, 2)
                + offb(C("v2sigmatau", 6), Sa, Ta, Sb, Tb, 3, 2)
                + offb(C("v2lapltau", 4), La, Ta, Lb, Tb, 2, 2)
                + vsig[:, 0] * s2[0] + vsig[:, 1] * s2[1] + vsig[:, 2] * s2[2])


class FockBatch(_ShellFock):
    """3D atoms: shells from the Koga Slater orbitals, spherical radial grid."""

    def __init__(self):
        ao = aoc._import_ao()
        _, r, wt = ao.GridGenerator.make_grid(GRID_POINTS)
        self.r = r
        self.weight = 4.0 * pi * wt
        self.atoms = list(FOCK_ATOMS)
        self.shells = {a: _atom_shells(a, r) for a in self.atoms}


# --- 1D/2D harmonic-oscillator model bases -------------------------------
def _ho_states(x, nmax):
    """Normalized 1D HO eigenfunctions psi_n and their first two derivatives,
    n = 0..nmax, via the standard recurrences (as in gen_example_densities.py)."""
    x = np.asarray(x, dtype=float)
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


def _ho1d_shell(x, level):
    """(den, grd, lap, tau) of one 1D HO level (occupation 1)."""
    psi, d1, d2 = _ho_states(x, level)
    n = level
    return (psi[n]**2, 2.0 * psi[n] * d1[n],
            2.0 * (d1[n]**2 + psi[n] * d2[n]), 0.5 * d1[n]**2)


def _ho2d_shell(r, shell):
    """(den, drho/dr, lap, tau) of one full 2D HO shell (n_x+n_y=shell) along the
    y=0 ray. A filled shell is rotationally symmetric, so the ray is the radial
    profile and |grad rho| = |drho/dx| there."""
    levels = [(a, shell - a) for a in range(shell + 1)]
    px, d1x, d2x = _ho_states(r, shell)
    py, d1y, d2y = _ho_states(0.0, shell)
    py = [float(v) for v in py]
    d1y = [float(v) for v in d1y]
    d2y = [float(v) for v in d2y]
    den = sum((px[a] * py[b])**2 for a, b in levels)
    grd = sum(2.0 * px[a] * d1x[a] * py[b]**2 for a, b in levels)
    d2_x = sum(2.0 * (d1x[a]**2 + px[a] * d2x[a]) * py[b]**2 for a, b in levels)
    d2_y = sum(2.0 * px[a]**2 * (d1y[b]**2 + py[b] * d2y[b]) for a, b in levels)
    tau = sum(0.5 * ((d1x[a] * py[b])**2 + (px[a] * d1y[b])**2) for a, b in levels)
    return den, grd, d2_x + d2_y, tau


def _model_shells(dim, r):
    shell_fn = _ho1d_shell if dim == 1 else _ho2d_shell
    up, dn = _MODEL_OCC["up"], _MODEL_OCC["dn"]
    shells = []
    for i in range(len(up)):
        den, grd, lap, tau = shell_fn(r, i)
        f = {"den": [up[i] * den, dn[i] * den],
             "grd": [up[i] * grd, dn[i] * grd],
             "tau": [up[i] * tau, dn[i] * tau],
             "lap": [up[i] * lap, dn[i] * lap]}
        shells.append((f"n{i}", f))
    return shells


class ModelFockBatch(_ShellFock):
    """1D quantum wire / 2D quantum dot: shells are harmonic-oscillator levels.

    Reuses the 3D grid nodes with the dimension's Jacobian (1D: 2 dx over
    |x|>=0; 2D: 2 pi r dr), exactly as model_convergence.py.
    """

    def __init__(self, dim):
        ao = aoc._import_ao()
        _, r, wt = ao.GridGenerator.make_grid(GRID_POINTS)
        w_rad = wt / (r * r)
        self.r = r
        self.weight = 2.0 * w_rad if dim == 1 else 2.0 * pi * r * w_rad
        self.atoms = [f"HO{dim}D"]
        self.shells = {self.atoms[0]: _model_shells(dim, r)}


_BATCH = None
_MODEL = {}


def get_batch():
    global _BATCH
    if _BATCH is None:
        _BATCH = FockBatch()
    return _BATCH


def get_model_batch(dim):
    if dim not in _MODEL:
        _MODEL[dim] = ModelFockBatch(dim)
    return _MODEL[dim]
