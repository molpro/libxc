# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What is libxc

Libxc is a portable, well-tested library of exchange-correlation (XC) functionals for density-functional theory (DFT). It provides a C API with Fortran 2003 and Python (ctypes/NumPy) bindings, and GPU support via CUDA/HIP.

## Build

### Autotools (primary)
```bash
autoreconf -i   # only needed when configure.ac or Makefile.am changed
./configure --prefix=/path/to/install
make
make check      # run full test suite
make install
```

Notable `configure` flags:
- `--enable-maxorder=N` — highest derivative order to compile (0 exc, 1 vxc, 2 fxc, 3 kxc, 4 lxc; default 2). Replaces the deprecated `--disable-{vxc,fxc,kxc,lxc}`
- `--enable-cuda` / `--enable-hip` — GPU support (NVIDIA / AMD)

### CMake (alternative)
```bash
cmake -H. -Bobjdir
cd objdir && make
ctest           # or: make test
make install
```

## Tests

Test data lives in `testsuite/`. The suite uses pytest driven through the Autotools/CMake `check`/`test` targets.

Run the full suite:
```bash
make check          # Autotools
ctest               # CMake
```

Regenerate regression test data after changing or adding a functional:
```bash
cd testsuite && ./xc-generate_tests.py
```

## Code architecture

### Functional families
Functionals are grouped into four families: **LDA** (local density approximation), **GGA** (generalized gradient approximation), **meta-GGA**, and **hybrid**. Each family has its own evaluation harness (`src/work_lda.c`, `src/work_gga.c`, `src/work_mgga.c`).

### Code-generation pipeline (Maple → C)
Since v4, all functional math is defined symbolically in Maple and converted to C automatically:

1. `maple/FAMILY_exc/NAME.mpl` — Maple source defining `f(rs, z)` (or `f(rho, sigma, ...)` for GGA/meta-GGA). A few functionals additionally provide a direct potential definition under `maple/FAMILY_vxc/`.
2. `scripts/maple2c.py` — converts the Maple file to a single C file `src/maple2c/FAMILY_exc/NAME.c` containing all requested derivative orders (`exc`, `vxc`, `fxc`, `kxc`, `lxc` are emitted into the same file, gated on `--maxorder`).
3. The handwritten `src/NAME.c` file simply `#include`s the generated C and the appropriate `work_*.c` harness

Run the conversion (pass just the functional name — the script auto-locates it under `maple/FAMILY_exc/` or `maple/FAMILY_vxc/`):
```bash
python3 scripts/maple2c.py --functional=lda_x --maxorder=4
```

### Structure of a functional source file (`src/*.c`)
Each functional file contains:
1. `#define XC_FAMILY_NAME  ID  /* description */` macros mapping name to numeric ID
2. A parameter struct (e.g. `lda_x_params`) and an `init` function that sets defaults
3. `#include "maple2c/family_exc/name.c"` — pulls in the generated math
4. `#include "work_lda.c"` (or `work_gga.c`, `work_mgga.c`) — evaluation harness
5. A `const xc_func_info_type xc_func_info_FAMILY_NAME = { ... }` registry entry

### Auto-generated files — do not edit directly
- `src/xc_funcs.h` — all functional IDs
- `src/funcs_lda.c`, `src/funcs_gga.c`, `src/funcs_mgga.c`, `src/funcs_hyb_*.c` — functional registries
- `src/references.h`, `src/references.c` — bibliography
- `src/libxc_inc.f90` — Fortran interface
- `src/maple2c/` — C code generated from Maple

Regenerate the functional list and bibliography after edits:
```bash
# From inside src/:
make funcs
# Or directly:
python3 scripts/get_functional_info.py --srcdir=.

# Bibliography (requires libxc.bib):
make references
# Or:
python3 scripts/get_references.py libxc.bib
```

## Adding a new functional

1. Write the Maple definition in `maple/FAMILY_exc/NAME.mpl` and add it to that directory's `Makefile.am` (`FAMILY_order_4` or `FAMILY_order_3` list, depending on the highest derivative order supported)
2. Generate C: `python3 scripts/maple2c.py --functional=NAME --maxorder=4`, then add the generated `src/maple2c/FAMILY_exc/NAME.c` to `src/maple2c/FAMILY_exc/Makefile.am`
3. Create `src/NAME.c` with the `#define`, parameter struct, `init`, `#include` lines, and `xc_func_info_type` (follow an existing functional of the same family as a template)
4. Add the new `src/NAME.c` to `src/sources.mk` (one entry, keep alphabetical order within each family block); run `autoreconf -i` to regenerate `src/Makefile.in` — CMakeLists.txt reads `sources.mk` automatically
5. Regenerate the functional list: `cd src && make funcs`
6. Update bibliography: `make references`
7. Regenerate test data: `cd testsuite && ./xc-generate_tests.py`
8. Run `make check` to verify

## Code style

The project uses a clang-format config (`.clang-format`) based on LLVM style:
- 2-space indentation, 80-column limit, tabs never used
- Format a file: `clang-format -i src/myfile.c`
