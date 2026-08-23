#!/usr/bin/env python3
"""Diagnostic: atomic-quadrature convergence curves of the XC energy.

Reproduces Lehtola & Marques, J. Chem. Phys. 157, 174114 (2022), Figs 2-6:
|E_xc(N) - E_xc(Nref)| versus the number of radial quadrature points N, one
line per probe atom (3D functionals) or model quantum wire/dot (1D/2D). A
horizontal line marks the microhartree convergence target.

This is an optional diagnostic -- it needs matplotlib and is not part of the
test suite. It reuses the same densities and grids as the convergence
classification, so a dense N sweep is used here (finer than the doubling
sequence the classifier needs) to show the oscillatory noise structure.

    PYTHONPATH=<repo-root> python3 atomic/plot_convergence.py mgga_x_scan lda_x
    PYTHONPATH=<repo-root> python3 atomic/plot_convergence.py --spin polarized r2scan
"""
import argparse
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_convergence as ac  # noqa: E402
import model_convergence as mc  # noqa: E402

_SWEEP_CACHE = {}


def _sweep_for(dim, grids):
    key = (dim, grids)
    if key not in _SWEEP_CACHE:
        _SWEEP_CACHE[key] = (ac.SweepBatch(grids=list(grids)) if dim == 3
                             else mc.ModelSweep(dim, grids=list(grids)))
    return _SWEEP_CACHE[key]


def plot(func, spin, grids, outdir, plt):
    import pylibxc
    dim = mc.dimensionality(func)
    if dim is None:
        print(f"{func}: no energy density (model potential); skipping")
        return
    sweep = _sweep_for(dim, grids)
    feval = pylibxc.LibXCFunctional(func, spin)
    e = {n: sweep.energies(feval, spin, n) for n in grids}
    nref = grids[-1]

    fig, ax = plt.subplots(figsize=(6.0, 4.0))
    for a in sweep.atoms:
        dE = [abs(e[n][a] - e[nref][a]) for n in grids[:-1]]
        ax.semilogy(grids[:-1], dE, marker=".", ms=4, lw=1, label=a)
    ax.axhline(ac.CONV_ATOL, color="k", ls="--", lw=0.8,
               label=f"{ac.CONV_ATOL:g} Ha")
    kind = {3: "atoms", 2: "2D quantum dots", 1: "1D quantum wires"}[dim]
    ax.set_xlabel("radial quadrature points $N$")
    ax.set_ylabel(r"$|E_{xc}(N) - E_{xc}(N_{\mathrm{ref}})|$  (Hartree)")
    ax.set_title(f"{func}  ({kind}, {spin})")
    ax.legend(fontsize=8, ncol=2)
    fig.tight_layout()
    path = os.path.join(outdir, f"{func}_{spin}.png")
    fig.savefig(path, dpi=120)
    plt.close(fig)
    print("wrote", path)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("functionals", nargs="+")
    p.add_argument("--spin", default="unpolarized",
                   choices=["unpolarized", "polarized"])
    p.add_argument("--step", type=int, default=50,
                   help="spacing of the dense N sweep (default 50)")
    p.add_argument("--nmax", type=int, default=2500,
                   help="finest grid / reference N (default 2500)")
    p.add_argument("--out", default="convergence_plots",
                   help="output directory (default ./convergence_plots)")
    args = p.parse_args()

    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
    except ImportError:
        sys.exit("matplotlib is required for the convergence plots "
                 "(pip install matplotlib)")

    os.makedirs(args.out, exist_ok=True)
    grids = tuple([25] + list(range(args.step, args.nmax + 1, args.step)))
    for func in args.functionals:
        plot(func, args.spin, grids, args.out, plt)


if __name__ == "__main__":
    main()
