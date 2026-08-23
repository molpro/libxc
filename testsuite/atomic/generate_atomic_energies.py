#!/usr/bin/env python3
"""Generate reference atomic exchange-correlation energies at the quadrature limit.

For every functional that provides an energy density (``_have_exc``) the atomic
XC energy is converged with respect to the radial quadrature on the accurate
Koga Hartree-Fock densities of the probe atoms of Lehtola and Marques
(J. Chem. Phys. 157, 174114 (2022)). For each atom and spin treatment the
convergence point N0 -- the smallest grid above which every finer grid agrees
with the finest to microhartree -- is found (atomic_convergence.py), and the
converged energy is tabulated together with that per-atom point count. A
functional that never converges is recorded but its energies are not asserted
by the test (the reference platform value is not reproducible).

One reference file per functional is written to references/, plus a single
convergence.json mapping each functional to its convergence band; the latter
feeds the verbal convergence characterisation in the functional documentation.

    PYTHONPATH=<repo-root> python3 atomic/generate_atomic_energies.py
"""
import glob
import json
import os
import sys

import numpy as np
import pylibxc

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import atomic_energies_common as aoc  # noqa: E402
import atomic_convergence as ac  # noqa: E402
import model_convergence as mc  # noqa: E402
import fock_convergence as fc  # noqa: E402

# Functionals excluded from the reference set entirely. Non-convergence is NOT
# a reason to skip: functionals whose atomic quadrature never converges to
# microhartree are written with conv=0 (the "pathological" band) and only
# finiteness-checked by the test. This set is for functionals that cannot be
# evaluated on the probe systems at all.
SKIP = set()

# Provenance line for the reference header, per dimensionality.
PROBE = {
    3: "probe atoms (3D): Lehtola & Marques, J. Chem. Phys. 157, 174114 (2022)",
    2: "probe systems (2D): harmonic-oscillator quantum dots",
    1: "probe systems (1D): harmonic-oscillator quantum wires",
}

REF_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "references")
CLASS_JSON = os.path.join(REF_DIR, "convergence.json")


def main(only=None):
    if not aoc.have_atomicorbitals():
        sys.exit("embedded reference-density data (koga_hf_data.json) missing")
    os.makedirs(REF_DIR, exist_ok=True)
    if not only:  # full run replaces the whole reference set
        for stale in glob.glob(os.path.join(REF_DIR, "*.dat")):
            os.remove(stale)

    sweep3d = ac.SweepBatch()
    sweeps = {3: sweep3d, 2: mc.get_sweep(2), 1: mc.get_sweep(1)}
    print(f"3D grids: {sweep3d.grids} x atoms {sweep3d.atoms}; "
          f"libxc {pylibxc.util.xc_version_string()}")

    funcs = sorted(only) if only else \
        sorted(pylibxc.util.xc_available_functional_names())
    classification = {}
    n_written = n_skipped = n_fock = 0
    nan_funcs, patho_funcs = [], []
    for func in funcs:
        if func in SKIP:
            continue
        dim_e = mc.dimensionality(func)   # energy: None if no energy density
        dim_f = fc.dimensionality(func)   # Fock:   None if no potential
        if dim_e is None and dim_f is None:
            n_skipped += 1
            continue
        entry = {"dim": dim_e if dim_e is not None else dim_f,
                 "n0": None, "band": None, "fock_n0": None, "fock_band": None}

        # --- energy band + converged reference file ---
        if dim_e is not None:
            try:
                res = (ac.classify if dim_e == 3 else mc.classify)(
                    sweeps[dim_e], func)
            except Exception as exc:  # pragma: no cover - defensive
                print(f"  {func}: energy classify failed ({exc})",
                      file=sys.stderr)
                res = None
            if res is not None:
                entry["n0"], entry["band"] = res["n0"], res["band"]
                sweep = sweeps[dim_e]
                any_nan = False
                with open(os.path.join(REF_DIR, func + ".dat"), "w") as fh:
                    fh.write(f"# {dim_e}D exchange-correlation energies "
                             "(Hartree) at the radial-quadrature convergence "
                             "limit\n")
                    fh.write(f"# functional: {func}\n")
                    fh.write(f"# {PROBE[dim_e]}\n")
                    n0 = res["n0"]
                    n0_txt = "never converges" if n0 is None \
                        else f"N0 = {n0} radial points"
                    fh.write(f"# convergence: {res['band']} ({n0_txt})\n")
                    fh.write("# system  spin         npts  converged  E_xc\n")
                    for atom in sweep.atoms:
                        for spin in aoc.SPINS:
                            cn0, eref = res["per_case"][(spin, atom)]
                            conv = cn0 is not None
                            npts = cn0 if conv else sweep.grids[-1]
                            if not np.isfinite(eref):
                                any_nan = True
                            fh.write(f"{atom:6s} {spin:12s} {npts:5d} "
                                     f"{int(conv):9d} {eref: .10e}\n")
                n_written += 1
                if any_nan:
                    nan_funcs.append(func)
                if res["band"] == "pathological":
                    patho_funcs.append(func)

        # --- Fock-matrix band (also classifies the model potentials) ---
        if dim_f is not None:
            try:
                fres = fc.classify(fc.get_sweep(dim_f), func)
            except Exception as exc:  # pragma: no cover - defensive
                print(f"  {func}: Fock classify failed ({exc})", file=sys.stderr)
                fres = None
            if fres is not None:
                entry["fock_n0"], entry["fock_band"] = fres["n0"], fres["band"]
                n_fock += 1

        classification[func] = entry

    if only:
        # Partial run: merge the recomputed entries into the existing
        # classification so the metadata stays consistent with the full set.
        try:
            with open(CLASS_JSON) as fh:
                merged = json.load(fh)
        except (OSError, ValueError):
            merged = {}
        merged.update(classification)
        classification = merged
    with open(CLASS_JSON, "w") as fh:
        json.dump(classification, fh, indent=1, sort_keys=True)

    print(f"wrote {n_written} functional reference files; "
          f"{n_fock} Fock-matrix bands; skipped {n_skipped}")
    print(f"pathological (never converges to microhartree): {len(patho_funcs)}")
    if patho_funcs:
        print("  " + " ".join(patho_funcs))
    if nan_funcs:
        print(f"{len(nan_funcs)} functionals produced non-finite energies on "
              f"some probe atom (tail instability): " + " ".join(nan_funcs))


if __name__ == "__main__":
    main(only=sys.argv[1:] or None)
