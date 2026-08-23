## [7.1.2] - 2026-07-20

Performance and accuracy release: the generated code no longer evaluates integer and simple rational powers through `pow()`, which is both several times slower and, for a few exponents, less accurate than the arithmetic it replaces.

### Fixed
- Integer and rational powers in the generated sources went through `pow()` — 11881 calls, for exponents as ordinary as `rs**5` and `x*sqrt(x)`, with integer exponents reaching |n| = 57. No compiler will clean this up: at `-O3` gcc expands `pow(x, 2.0)` and nothing else, and only `-ffast-math`, which libxc cannot use, removes the rest. Measured per evaluation, `pow()` costs ~37 ns against ~2 ns for the equivalent arithmetic, and `pow(x, -1/2)` 36.7 ns against 11.9 ns for `1/sqrt(x)` (!818).
- Accuracy of several rational powers. A root is now applied once, with the integer part taken separately, rather than raising the root to a power — which multiplies its half-ulp error by the exponent. `x**(5/3)`, the Thomas–Fermi exponent and one of the most common in the library, halves its error from 9.5 to 4.6 ulp; `x**(2/3)` from 9.1 to 4.9. Swept over every rational exponent with denominator 2, 3, 4 or 6 and |numerator| ≤ 13, all forms now land between 0.9 and 5.9 ulp (!818).

### Changed
- Two helpers in `util.h`, `xc_powi(x, n)` and `xc_powr(x, p, q)`, now carry the power evaluation for the generated code; both fold to optimal inline code for constant exponents on gcc and clang. The Maple pipeline's fixed-exponent macros — `POW_2`, `POW_3`, `POW_1_2`, `POW_1_3`, `POW_1_4`, `POW_3_2`, `POW_2_3`, `POW_4_3`, `POW_5_3`, `POW_7_3` — had no users left and are gone; use `CBRT` for the cube root. These are internal (`util.h` is not installed), so nothing in the public API changes (!818).

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
- `src/maple2c/mgga_exc/mgga_x_mvsb.c`, generated code for a functional removed earlier, along with two `.maple_backup` files committed by accident. None were built, but they were shipping in `make dist` (!818).

## [7.1.1] - 2026-07-19

Bugfix release: a large performance regression in the range-separated functionals, floating-point exceptions in debug builds, a regression in the deprecated derivative-order switches, an incorrect functional, and a Fortran example fix.

### Changed
- Internally, the derivative order is now carried as a single number, `XC_MAXORDER`, instead of the four `XC_DONT_COMPILE_VXC`/`FXC`/`KXC`/`LXC` booleans the configuration expanded it into — one of which, `XC_DONT_COMPILE_EXC`, was never defined by anything. The `--enable-maxorder` / `-DMAXORDER` options and the deprecated `--disable-*xc` / `-DDISABLE_*XC` switches are unaffected. A build hand-passing `-DXC_DONT_COMPILE_FXC` in its own flags still lowers the compiled order, though that spelling is deprecated (!818).
- The test suite checks two code-generation invariants directly, without a build: that regenerating a functional is reproducible, and that each helper's result array matches the slots the helper writes (!818).

### Fixed
- Performance regression in HSE06 and WPBEH, reported at roughly 10-43x by CP2K. A helper written as the usual two-regime piecewise — each branch's argument clamped into its own valid domain — was emitted as *two unconditional calls* plus a select that discarded one result, so every grid point paid for both regimes. `GGA_X_WPBEH` was the worst case, evaluating a ~2400-line series expansion alongside the closed form it was not using. The code generator now determines which branch a call's results are read under and emits the call behind a real branch when the helper is expensive; the same pass also skips helper evaluation at density-screened points. Measured 2.4-4.9x on WPBEH and HSE06 against 7.1.0, together with the change below (#630, !815).
- Every derivative order now evaluates only the helper slots it needs. The kernels were already compiled once per order and dispatched on the call, but all orders shared a single copy of each helper, which computed and reserved space for every slot the build compiled: an energy-only call ran a five-argument helper to all 21 slots of a `MAXORDER=2` build to read one of them. Helpers are now order-graded the same way the kernels are, so the cost of a call scales with the derivative order requested instead of being flat (!818).
- The code generator produced different output on every run. Two passes iterated an unordered set, so helpers with no dependencies between them — any topological order is valid — came out shuffled, and regenerating a functional on the same machine gave a different file each time. Generation is now reproducible; this normalizes the affected helpers to definition order once (!818).
- Spurious `sqrt(sigma_ss)` in the spin-scaled exchange channel: helpers depending on the reduced gradient only through its square are now automatically emitted in "p form" by the code generator, so the chain rule no longer routes through `d(sqrt(sigma))`. This removes the resulting `1/sigma^(k/2)` terms — which cancel only in exact arithmetic — from the higher derivatives of the affected meta-GGA exchange functionals, fixing a SIGFPE in debug builds (notably `HYB_MGGA_XC_WB97M_V`) and improving accuracy in the low-density tail (#629, !812).
- SIGFPE in `xc_E1_scaled_jet` for large arguments: the asymptotic series evaluated `pow(z, m+1+k)`, which overflows before the series is truncated. The terms are now generated by a ratio recurrence with optimal truncation (#629, !811).
- LDA_C_RPAF: corrected the `cL` log coefficient (a transcription typo confirmed by the author), which made the correlation energy per particle positive at spin-polarized points. The functional additionally has genuine poles at zeta ~ 0.510 and ~ 0.999 that stem from the published parametrization itself; these are now documented in the source (!810).
- The deprecated `DISABLE_VXC`/`DISABLE_FXC`/`DISABLE_KXC`/`DISABLE_LXC` CMake options and `--disable-{vxc,fxc,kxc,lxc}` configure switches acted only as caps on the new `MAXORDER` (default 2), so e.g. `--disable-lxc` silently built order 2 instead of the documented order 3. They again set the derivative order from the highest order not disabled (!809).
- Fortran basic example: use the `c_size_t` kind for `np` (!808).
- 32-bit x86 builds used the 387 unit, which keeps intermediates in 80-bit registers and rounds them on spill, so results depended on register allocation rather than on the arithmetic: on i686 the regression suite missed `GGA_X_HJS_PBE`'s `v2sigma2` by twice its tolerance and `MGGA_X_2D_PRHG07_PRP10`'s `v2rho2` by a factor of 2000. Both build systems now probe for `-msse2 -mfpmath=sse` and use it, which is the arithmetic every 64-bit target already gets. This makes SSE2 (Pentium 4 / Athlon 64 and later) the effective baseline for 32-bit x86; a compiler without it warns rather than failing (!818).

## [7.1.0] - 2026-07-17

This release introduces significant improvements to GPU support (which previously didn't work at all), build systems, and the Python interface, alongside new functionals, several functional bug fixes and renames, and an overhaul of the test suite and bibliography. Under the hood, the code-generation pipeline gained a SymPy-based backend with arbitrary-precision reference oracles, together with an extensive floating-point-stability sweep of the functional sources.

> **Looking ahead to 8.0.0.** The next major release will feature a complete redesign of the API around a C++ core, together with support for new classes of functionals such as local hybrids and double hybrids. As part of that transition the Autotools build system will be removed; new and existing projects are encouraged to migrate to the CMake build now.

### Added
- Runtime switching mechanism between CPU and GPU implementations via a new API with a single function accepting a flags parameter, while maintaining full API (and ABI!) compatibility with the previous version. Resolves the CUDA build always running on the GPU (#135, !711, !718, !722, !726).
- Support for HIP (ROCm) as an alternative to CUDA for GPU acceleration (!725).
- Backend-agnostic array interface to pylibxc, supporting NumPy, CuPy, JAX, and possibly other array backends; brings GPU support to pylibxc (#598, !743).
- DLPack support in the pylibxc array backend (!745).
- CUDA and HIP examples demonstrating device-side functional evaluation; examples are now compiled as part of the build.
- AddressSanitizer support in CI for the gcc_cmake_python job and a new CI job for Intel oneAPI.
- Optional profiling ranges (NVTX for CUDA and ROCTX for HIP) for expensive evaluation paths (CMake only; profiling support is disabled by default) (!759).
- Getter/setter API for default functional flags with matching Fortran bindings.
- Build-information variables exported to downstream CMake consumers.
- Test suite rewritten using pytest, with documentation of test thresholds and skipped test cases (!680).
- XC_CHECK_NUMERICS option and re-enabled floating-point-exception trapping in the work harnesses (CMake) (!771).
- CMake FORTRAN_MODULE_INSTALL_DIR option to control where the Fortran module is installed (!772).
- New functionals:
  - LDA_C: BJ89 (Barbiellini & Jarlborg 1989) (#613, !762); LP96_B (Liu-Parr 4-parameter correlation) (#615, !765); RPAF (Random-Phase-Approximation-based functional) (!792).
  - LDA_K: LP96_B (Liu-Parr 4-parameter kinetic) (#615, !765).
  - LDA_X: t-SLOC (SLOC reparametrization for band gaps) (#609, !757).
  - GGA_C: BKL1, BKL2 (and corresponding new external parameter in GGA_C_PBE) (!692).
  - GGA_X: t-PBE1, t-PBE2 (PBE reparametrizations for band gaps) (#606, !754); LLP (Lee-Lee-Parr reparametrization of B88) (#614, !764).
  - GGA_XC: DLB97 (dispersionless-optimized B97) (#569, !689).
  - MGGA_C: LAK (Lebeda-Aschebrock-Kümmel) (#524, !709); MSCAN (#572, !712).
  - MGGA_X: MSCAN (modified/magnetic SCAN) (#572, !705); SREGTM_V1/V2/V3 (simplified regularized Tao-Mo exchange) (#492, !783).
  - MGGA_XC: t-HLE17 (HLE17 reparametrization for band gaps) (#610, !758).
  - HYB_GGA_XC: cQTP25 (core-electron ionization energies) (#588, !720).
  - HYB_LDA_XC: B93 (Becke's original half-and-half functional) (#547, !674).
  - HYB_MGGA_X: WR2SCAN (range-separated r2SCAN exchange) (#552, !678).
  - HYB_MGGA_XC: COACH (Head-Gordon's range-separated hybrid meta-GGA) (#605, !780).
  - DF3 family of functionals for vdW-DF (GGA_X_DF3_OPT1, GGA_X_DF3_OPT2) (#211, !755).
  - pi-M06-2X functional family (!681).
- External parameters for MGGA_XC_LP90 (!687).
- BHLYP alias for HYB_GGA_XC_BHANDHLYP (!675).

### Changed
- Bump minimum CMake version to 3.21.
- Refactored implementation of functional evaluation to reduce code duplication using DRY principles, including a common shorthand for the xt → s conversion and removal of variable-length array declarations (!704, !706, !707).
- Replaced duplicated source lists in CMake and Autotools by a common file.
- Simplified CMake configuration by removing ENABLE_GENERIC and ENABLE_XHOST options.
- Enhanced DISABLE_*XC options to accept lists of specific source files instead of all functionals. Allows disabling expensive derivatives selectively (e.g., DISABLE_LXC for specific files). Intended for experts and packagers.
- Updated CI pipeline configuration to improve testing coverage; merge-request pipelines now use workflow:rules (!685, !744).
- In CMake dynamic linking is now the default and CUDA static-linking handling was corrected.
- Dropped the deprecated `xc-consistency` tool.
- GPU support (CUDA and HIP) is no longer marked experimental.
- Overhauled the internal code-generation pipeline: the functional math is now generated through a SymPy-based backend backed by arbitrary-precision reference oracles, the whole functional library and its regression references were regenerated, and the Maple/SymPy sources went through an extensive floating-point-stability sweep (cancellation-free reduced-gradient forms, stable special-function evaluation) so that functionals are accurate to the working precision independent of the compiler; a few functionals whose highest derivatives are non-differentiable, disproportionately large, or prohibitively expensive to generate are capped below the 4th derivative. Adds a CI job that verifies the committed generated files match their sources, plus physical vxc/fxc and Fock/kernel consistency tests (#262, #564; !766, !777, !779, !795, !803, !806).
- Modernised the C math utilities: tanh-sinh quadrature and a dilogarithm fix (!775).
- Functional renames (old names retained as aliases where applicable):
  - GGA_XC_TH_FL → LDA_XC_TH_FL (it is an LDA functional) (#596, !733).
  - MGGA_X_MK00 → MGGA_X_GP86 (use the original authors' names) (#595, !732).
  - LDA_C_1D_CSC → LDA_C_1D_CSS (#576, !728).
- HYB_LDA_X_ERF correctly flagged as a hybrid functional (#544, !673).
- Updated value of β in MGGA_C_MSCAN per request of the authors (!742).
- d0 parameter of MGGA_XC_LP90 corrected per Zhao et al. (1993) (!687).
- µ^MGE2 in GGA_C_SG4 changed to 0.26 (#584, !753).
- Both `zk` and `exc` are now printed in test output.
- Maple version is still dumped to source when the Maple license is approaching expiry (!710).
- Bibliography overhaul: uniform two-dash page-range style, fixed non-ASCII character, removed tddft.org links from source, consistent acronym usage, and corrected author names (Thakkar, Brémond, Brual Jr, Gunnarsson, Della Sala, Jemmer, Vilhena). Added P86 erratum, r2SCAN01 reference, GGA_X_BKL final reference (#541, !676), and a page number for the Libxc entry; VSXC reference corrected to point at the erratum.

### Deprecated
- The Autotools build system is deprecated and will be removed in 8.0.0; use the CMake build system instead.

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
- Legacy memory management functions that are now unused. (ABI breaking) (!749).
- MGGA_X_MS2BS, MGGA_X_MVSB and MGGA_X_MVSBS: removed, as they appear only in a preprint (not the final article) and involved an unclear/incorrect substitution; the duplicate entries in `xc_funcs_removed.h` were also cleaned up (#594, #617; !730, !778).

### Fixed
- Deorbitalize function now works correctly on GPU (!747, !748).
- Use correct malloc/memset/free functions for host and device variables throughout the entire code; do not call `libxc_memset` on local host variables (!697, !702, !726, !774).
- Replace `libxc_free` with `free` in Fortran bindings, making the Fortran library independent of internal functions.
- Fortran interface bug (#575, !701).
- Renamed/removed functionals are still recognized by the build scripts, `funcs_key`, and the Fortran headers, preserving backwards compatibility (#599, !739).
- GGA_X_BPCCAC: bug fix (#540, !693).
- GGA_K_OL1, GGA_K_OL2, GGA_X_OL2: corrected to match the original paper (#593, !727).
- GGA_C_ZVPBELOC: corrected the nu function (#573, !708).
- LDA_C_1D_LOOS: corrected coefficients (#577, !751).
- GGA_X_ERF_GWS: rewritten to be numerically stable, eliminating floating-point errors and NaNs (#560, !683).
- GGA_X_WPBEH: the low-gradient interpolation switch now uses exact Ernzerhof-Gustavsson constants, fixing inconsistent HSE06 molecular gradients (#627, !806).
- GGA_C_WI: typos in parameter values fixed (#549, !677).
- MGGA_XC_OTPSS_D: correlation parameters corrected to match the erratum (#587, !721).
- XB1K and X1B95: corrected the a1 coefficient and the DFT exchange prefactor (#618, !785).
- MGGA_X_2D_PRP10: added the missing XC_NEEDS_TAU flag (#620, !791).
- HYB_MGGA_XC_B0KCIS: no longer double-counts correlation (the mix functional was also invoking the meta-GGA kernel) (#622, !796).
- LDA_C_PW_ERF: available derivative orders are no longer hardcoded (#623, !796).
- LDA_XC_KSDT / corrKSDT: restored the missing 2^(1/3) factor in the b5 coefficient of the zeta=1 branch (!802).
- LDA_C_PK09: fixed NaNs; added an lda_exchange() helper for consistency (!784).
- Deorbitalized SCAN-L functionals: higher derivatives corrected via symbolic deorbitalization (!805).
- Available-derivative and NEEDS_* flags for mixed/hybrid functionals are now derived from their components (!797).
- LambertW: return the best iterate instead of 0.0 on non-convergence (!782).
- BHLYP: identified as BHandHLYP rather than BHandH; alias added (!675).
- MGGA_XC_LP90: comment fix (#567, !686).
- `genwiki.c` updated to match the new family API (!673).
- `xc-reset-regression` script fixed after a prior refactor broke it (!731).
- Success checks added for two `malloc` calls.
- Missing Python files added to install paths.
- Removed use of a deprecated Autoconf macro.
- Enable new pytest tests for CMake build system (!741).
- Replaced several fatal `exit(EXIT_FAILURE)` paths with `abort()` to improve debugging diagnostics (!752, !760).

## [7.0.0] - 2024-10-09

This release introduces 23 new functionals, and fixes correctness issues in 5 functionals included in earlier releases.

Importantly, the release introduces the XC_FLAGS_NEEDS_TAU flag for meta-GGAs, and moves the control of the enforcement of the Fermi hole curvature to a runtime option, controlled by the XC_FLAGS_ENFORCE_FHC flag. If Libxc is compiled with the --disable-fhc flag, XC_FLAGS_ENFORCE_FHC defaults to false, and the library works exactly as before. The function xc_func_set_fhc_enforcement() was added to control the enforcement of the Fermi hole curvature. Thanks to these changes, long standing issues with support for codes relying on the projector augmented wave (PAW) approach have been resolved.

In addition, functionals' parameter values are now persistent. In previous versions, where calling e.g. xc_func_set_ext_params_name() would set the named parameter to the desired value - and all other parameters to their default values. Starting from Libxc 7.0.0, the other parameter values remain at their earlier values.

The duplicate copy of libxcf03 under the name libxcf90, introduced to temporarily work around an erroneus change made in Libxc 5.0.0 has been removed. Libxc 5.0.0 renamed the Fortran 2003 interface library libxcf03 to libxcf90, even though a different library called libxcf90 which predated iso_c_binding existed before in Libxc. The Fortran 2003 interface libxcf03 has been available in Libxc at least since version 3.0.0, and was only briefly removed in Libxc 5.0.0, which also had other severe bugs that led to incorrect results. Any codes using libxcf90 while assuming the Fortran 2003 API should be rewritten to use libxcf03 instead, since unlike libxcf90 which had a different API in older versions of Libxc, the API of libxcf03 has been stable for at least 8 years.

Another change to the Fortran interface is that the list of functionals has been split off into a separate module, xc_f03_funcs_m, in analogy to the C headers. Functional names should not be hardcoded in downstream codes; functional IDs should be parsed from human readable keywords like GGA_X_PBE by functionality included in Libxc (xc_functional_get_number() function). Similarly, e.g. hybrid functional coefficients should also not be hardcoded downstream, as these can be queried from Libxc.

### Fixed
- LDA_C_RPA (issue #539): term -0.017*rs instead of -0.018*rs as in original paper
- GGA_X_SSB_SW (issue #535): a=1.0515 instead of 1.05151, c=0.254443 instead of 0.254433
- GGA_X_LAG (issue #533): LDA exchange contribution missing
- GGA_X_HCTH_A (issue #530): wrong sign for gradient contributions
- GGA_X_FD_LB94 and GGA_X_FD_REVLB94 (issue #531): several issues in the definition of the functionals
- MGGA_X_TASK (!658): improved numerical stability

### Added
- GGA_C: PBE_ERF_GWS (!542)
- GGA_X: BKL1 and BKL2 (!649), PBE_ERF_GWS (!542)
- HYB_GGA_XC: OPB3LYP (!630)
- HYB_GGA_X: PBE_ERF_GWS (!542)
- HYB_LDA_X: ERF (!542)
- HYB_MGGA_X: CF22D (!646)
- LDA_C: EPC17 and EPC17_2 (!623), EPC18_1 and EPC18_2 (!624), PW_ERF (!542)
- MGGA_C: CF22D (!646)
- MGGA_X: EEL (!627); LAK (!652); and MSB86BL, MSPBEL, MSRPBEL, RMSB86BL, RMSPBEL, and RMSRPBEL (!648)


## [6.2.2] - 2023-06-14

Hotfix to fix the dimension of some of the fourth derivative arrays.

### Fixed
- Dimension of v4rhosigma2lapl, v4rhosigma2tau, v4rhosigmatau2, v4sigma3tau arrays was wrong (#472)

## [6.2.1] - 2023-06-13

Hotfix to disable use of host-specific instructions by default in CMake.

### Fixed
- CMake employed ENABLE_XHOST=ON by default, resulting in binaries specific to the host processor (#471)

## [6.2.0] - 2023-05-26

This is again a bugfix release, which also adds some functionals.

### Fixed
- CMake does not link standard math library in shared xc library (#465)
- Taylor expansions used in GGA_C_REVTCA, GGA_K_VT84F, MGGA_X_FT98 were not of sufficient to guarantee accuracy of all derivatives (#449)
- Replaced hard cutoff in MGGA_X_MBRXC_BG with a Taylor expansion (!607)
- StandardMathLibraryC.cmake reusing variable names (!585)

### Added
- Machine learned functionals from Kovacs et al, kindly contributed by Peter Kovacs (!600 and !614)


## [6.1.0] - 2023-01-10

This is a bugfix release, which also adds some functionals.

### Fixed
- Memory allocation in xc-regression (!591)
- MGGA_C_REVSCAN was implemented incorrectly (#429)
- Missing comma in MGGA_XC_B97M_V (#437)

### Added
- HYB_GGA functionals: XC_RELPBE0
- HYB_MGGA functionals: XC_GAS22, XC_R2SCANH, XC_R2SCAN0, XC_R2SCAN50

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
- GGA_X_HERMAN was incorrect: the functional is really a meta-GGA but its form was unclear and it seems numerically unstable (#399)


## [6.0.0] - 2022-10-14

This release changes the internal handling of derivatives in Libxc.
Instead of the previous code where the same driver was used to
evaluate all derivatives (controlled by an if statement in the
innermost loop), in this version specialized versions of the Maple
kernels are generated for all targeted numbers of derivatives as well
as spin-polarized vs spin-unpolarized calculations. Moreover, array
access has been improved, resulting in significant speedups on GPUs.

### Fixed
- LDA_C_KARASIEV and LDA_C_KARASIEV_MOD were implemented incorrectly (#382).

### Added
- GGA functionals: XC_B97_3C, X_PBE_GAUSSIAN, C_PBE_GAUSSIAN, X_PBE_MOD, X_NCAPR
- HYB_GGA functionals: XC_B3P86_NWCHEM
- MGGA functionals: C_TPSS_GAUSSIAN, C_CC, C_CCALDA, X_VCML, XC_VCML_RVV10
- HYB_MGGA functionals: XC_BR3P86
- functions to extract BibTeX reference keys from functionals

## [5.2.3] - 2022-05-16

### Fixed
- Fix compile issue with CUDA.

## [5.2.2] - 2022-02-01

### Fixed
- Some Maple sources had not been properly backported from the changed API in master which caused compile failures in 5.2.1 (#379)

## [5.2.1] - 2022-01-31

### Fixed
- Maple code in repository was incorrect for hyb_gga_x_cam_s12 (#372)
- Cleanup of reference handling in Fortran interface caused infinite loop (#374)

## [5.2.0] - 2022-01-21

### Fixed
- Clarified documentation of lda_x_erf and lda_x_yukawa (#362)
- C header should not depend on availability of derivatives in
  binaries (!522)
- Wrong flags with PGI compiler in CMake (#361)
- No automatic generation of sources at configure time; no
  recompilation necessary anymore when sources have not changed (#358)
- Interchanged parameter descriptions in wB97 style functionals (#363)
- lda_c_pmgb06 functional was missing a factor 1-z^2 (#360)
- Long lines in f90 include files (!517)
- Improved handling of null pointers in Fortran frontend (!515)
- hyb_mgga_xc_lc_tmlyp was tagged an exchange instead of an
  exchange-correlation functional (!527)

### Added
- MGGA functionals: x_ft98 (!512)
- Enforcement of Fermi curvature can now be turned off as a compile
  time option (#354)
- Components of mixed functionals like B3LYP can now be queried from
  C, Fortran and Python (#369)

## [5.1.7] - 2021-10-25

### Fixed
- References should not be updated automatically
- xc_version.h is now usable in Fortran
- Unnecessary external parameters removed from MGGA_X_RSCAN, MGGA_X_R2SCAN, and MGGA_X_R2SCANL

### Added
- LDA functionals: XC_CORRKSDT
- HYB_GGA functionals: X_CAM_S12G, X_CAM_S12H, XC_CASE21
- MGGA functionals: X_R2SCAN01, X_R4SCAN, X_RPPSCAN, C_RPPSCAN

## [5.1.6] - 2021-09-07

### Fixed
- Setting of _dev flag in pylibxc frontend
- CMake tests are now prefixed with the project name
- All elements of xc_dimensions are now properly initialized
- xc-run_testsuite no longer prints out garbage when run on a single functional

### Added
- GGA functionals: X_Q1D
- MGGA functionals: C_R2SCAN01, C_RREGTM, X_MCML, C_RMGGAC

## [5.1.5] - 2021-06-10

### Fixed
- Implementation of LDA_XC_BN05 which lacked 100% long-range exact exchange since it was introduced; functional is now called HYB_LDA_XC_BN05
- CMake did not generate XC_MICRO_VERSION macro

### Added
- LDA functionals: X_YUKAWA

## [5.1.4] - 2021-05-10

### Fixed
- Implementation of GGA_XC_LB07 which lacked 100% long-range exact exchange since it was introduced; functional is now called HYB_GGA_XC_LB07
- HYB_MGGA_X_JS18 was broken in 5.1.2 and 5.1.3 due to bug in port of Maple code from master branch
- HYB_GGA_XC_CAP0 erroneously had 75% of exact exchange instead of 25% since libxc 5.0.0
- MGGA_X_2D_PRHG07 was marked as a 3D functional instead of a 2D functional
- Libxc can now be compiled as energy-only without any derivatives
- More CUDA build fixes

### Added
- HYB_GGA functionals: XC_B3LYP3, XC_PBE_2X, XC_PBE38, XC_MCAM_B3LYP
- MGGA functionals: X_MTASK
- pylibxc can now be installed directly by CMake

## [5.1.3] - 2021-03-30

### Fixed
- Some fixes to CUDA compilation.
- HYB_GGA_XC_LC_BLYP_EA was not tagged as a hybrid functional.
- The automatically generated list of functionals on the webpage was missing hybrid functionals for the 5.1.x series.

## [5.1.2] - 2021-02-12

### Fixed
- A memory leak in libxcf90
- NaNs and overflows in GGA_C_OP_* introduced in 5.1.1 due to inconsistent screening of the density
- Missing CMake files from the tddft.org tarball

## [5.1.1] - 2021-02-09

### Added
- LDA functionals: C_W20
- GGA functionals: C_LYPR
- HYB_GGA functionals: XC_LC_BLYP_EA, XC_LC_BLYPR
- MGGA functionals: X_REGTM
- HYB_MGGA functionals: XC_LC_TMLYP

### Fixed
- A memory leak in the Fortran interface
- MGGA_X_REGTPSS was implemented incorrectly
- HYB_GGA_XC_LC_BLYP used a range separation parameter of 0.3 instead of 0.33; HYB_GGA_XC_LC_BLYP_EA corresponds to the earlier implementation
- Improvements to numerical stability of TPSS correlation functionals

## [5.1.0] - 2021-01-19

### Added
- Functions xc_reference() and xc_reference_doi() to get the up-to-date citation to Libxc
- GGA functionals: C_P86_FT, C_CCDF, C_P86_FT, K_LGAP, K_LGAP_GE, K_LKT, K_PBE2, K_PG1, K_RATIONAL_P, K_TFVW_OPT, K_VT84F, X_REVSSB_D, C_P86VWN, C_P86VWN_FT, X_PW91_MOD, X_ITYH_PBE, X_ITYH_OPTX
- HYB_GGA functionals: XC_CAMH_B3LYP, XC_WB97X_D3, XC_WHPBE0, XC_LC_BOP, XC_HFLYP, XC_B3P86_NWCHEM, XC_LC_PBEOP, XC_CAM_O3LYP
- MGGA functionals: C_B94, C_HLTAPW, C_M06_SX, X_R2SCAN, C_R2SCAN, X_R2SCANL, C_R2SCANL, K_CSK1, K_CSK4, K_CSK_LOC1, K_CSK_LOC4, K_GEA2, K_GEA4, K_L04, K_L06, K_PC07_OPT, K_PGSL025, K_RDA, X_HLTA, X_JK, X_MBR, X_MS2_REV, X_TH, C_KCISK
- HYB_MGGA functionals:  XC_B94_HYB, X_M06_SX, XC_TPSS0

### Fixed
- Bugs in worker functions affecting all GGAs and meta-GGAs
- Several issues affecting kinetic energy functionals due to the use of inconsistent thresholds
- Incorrect definition of GGA_XC_KT3
- Incorrect implementation of GGA_X_OL1 and GGA_X_OL2
- Incorrect implementation of GGA_K_PERDEW
- Incorrect calculation of opposite-spin potentials for the ferromagnetic case
- Implementation of MGGA_X_MS2B still corresponded to the original preprint, not the final published version
- Numerical stability of range-separated functionals
- Several numerical overflow errors, affecting especially the SCAN family of functionals
- Incorrect definition of MGGA_C_B88, which was using B88 exchange instead of B86 exchange as supposed
- Missing minus sign in a coefficient of GGA_XC_HCTH_P76
- HYB_MGGA_X_PJS18 and HYB_MGGA_X_JS18 due to typo in the original publications
- Functional form of GGA_C_LM
- Bug in expint_E1 that had a huge effect on GGA_C_FT97


### Changed
- The renaming libxcf03 -> libxcf90 of 5.0.0 was reverted, as it proved to be problematic in downstream codes
- All numerical thresholds are now adjustable
- The threshold for the reduced gradient is now initialized based on the density threshold, instead of a hard-coded definition
- The CMake build system now generates pkgconfig files for the Fortran libraries

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
- The GGA functionals LCGAU, LCGAU_CORE, and LC2GAU, since the implementation was not complete; the functionals have range-separation terms that cannot be described by the infrastructure in the version 5 series. The correct implementations are included in the version 6 branch

## [5.0.0] - 2020-04-06

### Added
- Framework to include worker functionals. These functionals are not intended to be use on their own, but as part of other functionals.
- LDA functionals: C_PMGB06, XC_BN05, XC_TIH, C_UPW92, C_RPW92, X_SLOC
- HYB_LDA functionals: XC_LDA0, XC_CAM_LDA0
- GGA functionals: X_LSPBE, X_LSRPBE, XC_KT3, XC_LB07, K_GDS08, K_GHDS10, K_GHDS10R, K_TKVLN, X_OPTB86B_VDW, C_ACGGAP, X_FD_LB94, X_FD_REVLB94, C_ZVPBELOC, X_B88_6311G, X_NCAP, X_ECMV92, C_CHACHIYO, C_PBE_VWN, X_S12G, X_LCGAU, X_LCGAU_CORE, X_LC2GAU, C_MGGAC
- HYB_GGA: XC_LC_WPBE_WHS, XC_LC_WPBEH_WHS, XC_LC_WPBE08_WHS, XC_LC_WPBESOL_WHS, XC_APF, XC_CAM_QTP_00, XC_CAM_QTP_02, XC_LC_QTP, XC_APBE0, XC_HAPBE, XC_WC04, XC_WP04, XC_CAM_PBEH, XC_CAMY_PBEH, XC_QTP17, XC_LC_BLYP, X_S12H, XC_BLYP35
- MGGA functionals: X_RTPSS, X_MS2B, X_MS2BS, X_MVSB, X_MVSBS, C_TM, X_BR89_1, X_BR89_EXPLICIT_1, C_REVM11, X_REGTPSS, X_2D_JS17, X_RSCAN, C_RSCAN, X_TLDA, X_EDMGGA, X_GDME_NV, X_GDME_0, X_GDME_KOS, X_GDME_VT, X_REVTM, C_REVTM, C_REVM06, X_SCANL, X_REVSCANL, C_SCANL, C_SCANL_RVV10, C_SCANL_VV10, X_MBRXH_BG, X_MBRXC_BG, X_TASK, X_MGGAC
- HYB_MGGA functionals: X_REVM11, XC_RCAM_B3LYP, X_JS18, X_PJS18, XC_B3LYP_MCM1, XC_B3LYP_MCM2, X_REVM06
- Worker functionals: LDA_K_GDS08_WORKER.
- Correction to the Fermi_D term in MGGA_C_M05, MGGA_C_M05_2X, and MGGA_C_DLDF to avoid divergences when the kinetic energy density is zero, but not the density. This is similar to the correction proposed in from JCP 127, 214103 (2007). The correction is controlled by the `Fermi_D_cnst` external parameter, and its default value is 1e-10.
- Access to the internal parameters of several functionals. This is done using the same functions as for the external parameters.
- All functionals are now handled by Maple.
- Up to 4th-order for almost all functionals, and interface to access them.
- Printing of supported derivatives by the xc-info utility.
- New flag XC_FLAG_HAVE_ALL to indicate functionals that include all the currently available derivatives (exc, vxc, fxc, kxc, and lxc).
- Added the possibility of selectively disabling the compilation of vxc, fxc, kxc, and lxc to both Autotools and CMake build systems. By default kxc and lxc are not compiled. This allows for faster compilation times.
- Initial implementation of a GPU version of libxc

### Changed
- External parameters structure to include the name of the parameter. The name of the internal parameters is prepended with an underscore.
- Several functionals were modified to improve numerical stability. There are no more NaN or Infinities.
- Variable np is now size_t (8 bytes)
- Maple framework to generate the C code. In the new framework, the whole functional is handled by Maple, allowing the introduction of a unpolarized, ferromagnetic, and polarized case such that limiting cases are better handled.
- Integer type to c_int type in all Fortran 2003 interfaces.
- MGGA_C_TPSS to enforce z = tW/t <= 1 condition.
- XC_GGA_C_BCGP to XC_GGA_C_ACGGA, upon request by Antonio Cancio, keeping the old constant for backward compatibility.

### Fixed
- Missing terms in LDA_XC_KSDT and LDA_XC_GDSMFB.
- Incorrect parameter of GGA_C_GAPC.
- Incorrect definition of MGGA_C_KCIS.
- Incorrect definition of GGA_C_OPTC.

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
- xc_mix_func function from public API.
- obsolete custom Fortran interface libxcf90 replaced with the 2003 version (libxcf03) that employs standard iso_c_binding to wrap the C functions to Fortran.

## [4.3.4] - 2019-03-04

### Fixed
- Bug in XC_HYB_GGA_XC_CAM_QTP_01. Functional erroneously had 81% LYP and 19% VWN5, whereas it is supposed to have 80% LYP and 20% VWN5 correlation.
- Bug in GGA_X_2D_B88. The value of beta was wrong.
- Bug in HSE12 and HSE12s. Range separation parameter were incorrect.

## Changed
- Authors list.

## [4.3.3] - 2019-02-11

### Fixed
- Missing pylibxc/version.py file from tarball.
- Incompatible code with Python 3 in setup.py.

## [4.3.2] - 2019-02-07

### Fixed
- Incorrect version number in Python interfaces.
- CMake build of Fortran interfaces. The build was failing due to non-existent file.
- NaN issues in MGGA_X_TM.

### Changed
- Handling of version number in Python interfaces.

## [4.3.1] - 2019-02-05

### Fixed
- Inclusion of xc_mgga_c_pkzb_set_params function in the public API, as this function does not exist anymore.

## [4.3.0] - 2019-01-30

### Added
- Several set_params functions to the API. These functions were removed from the API in version 4.0.0 and will be removed again in version 5.0.0, where they will be replaced by a more generic API.

### Fixed
- Several issues that prevented compilation on Windows.
- Inclusion of config.h in the xc.h header file.
- Incorrect SOVERSION with CMake builds.
- Use of non-POSIX function `strdup`.
- Installation of Fortran module files with CMake.
- Installation of pkg-config `.pc` file with CMake.

### Deprecated
- Forrtran 90 bindings. These are replaced by the Fortran 2003 bindings and should be removed in version 5.0.0.

## [4.2.3] - 2018-07-02

### Added
- Installation of a libxc.pc file by CMake.
- Versioned shared library when buildbing with CMake.

### Fixed
- Timeout when generating the xc_func.h file with CMake.

## [4.2.2] - 2018-06-25

### Added
- Missing testsuite/CMakeLists.txt file from the tarball.

## [4.2.1] - 2018-06-06

### Added
- Compilation of Fortran interfaces with CMake.

## [4.2.0] - 2018-06-04

### Added
- GGA functionals: X_CHACHIYO, K_EXP4, K_PBE3, K_PBE4.
- HYB_MGGA: XC_B98.
- pkgconfig files for the Fortran interfaces.
- Missing regression tests for MGGA_X_BR89_EXPLICIT and LDA_C_GK72.

## [4.1.1] - 2018-05-08

### Fixed
- Missing python and CMake files from the tarball.

## [4.1.0] - 2018-05-07

### Added
- LDA functionals: C_GK72, C_KARASIEV, K_LP96.
- MGGA functionals: X_BR89_EXPLICIT, X_REVSCAN, C_SCAN_VV10, C_REVSCAN, C_REVSCAN_VV10.
- HYB_MGGA functionals: X_REVSCAN0.
- Optional Python interface.
- Functions to get the list of available functionals to the Fortran interfaces.

### Changed
- License from LGPL to the Mozilla Public License 2 (MPL2).
- CPP for Fortran sources macro, so that `cpp -C -freestanding` is used instead of `cpp -ansi`.
- XC_LDA_C_LP_A and XC_LDA_C_LP_A to XC_LDA_XC_LP_A and XC_LDA_XC_LP_A, as they are exchange-correlation functionals, keeping the old constant for backward compatibility.

### Fixed
- Bug in GGA_X_PBEPOW

## [4.0.5] - 2018-05-04

### Fixed
- Compilation with the PGI compiler.
- Compilation with GCC 6.3.0 on Power8.
- NaNs returned by MGGA_X_TM for large densities.
- Small bug in maple2C script.
- Bug in MGGA_X_MVS. This also affected HYB_MGGA_X_MVSH.

### Changed
- Improved documentation for range-separation parameters.


## [4.0.4] - 2018-01-17

### Fixed
- Incorrect XC_CORRELATION flag in the XC_LDA_K_ZLP, XC_LDA_X_RAE, and XC_GGA_XC_HLE16 functionals.
- Incorrect XC_EXCHANGE flag in the XC_GGA_C_SG4, XC_GGA_C_PBE_MOL, and XC_GGA_C_TM_PBE functionals.
- Incorrect XC_EXCHANGE_CORRELATION flag in the XC_MGGA_C_SCAN_RVV10 functional.
- Incorrect XC_FAMILY_MGGA family in the HYB_MGGA_XC_B0KCIS functional.

## [4.0.3] - 2017-11-20

### Fixed
- Generation of libxc_docs.txt file.

### Added
- Missing C to Fortran interface for `xc_f90_nlc_coef`.

## [3.0.1] - 2017-11-20

### Fixed
- Added missing MGGA_C_SCAN implementation (fix crash in 3.0.0).
- Uninitialized cam_omega, cam_alpha, and cam_beta parameters for LDA functionals.
- Flags defined in the Fortran 90 interface.
- Several references.
- Bugs in MGGA_X_MK00 and GGA_X_B86_R.
- Behavior for small tau in MGGA_XC_B97M_V and HYB_MGGA_XC_wB97M_V.
- Incorrect exchange mixing for HYB_GGA_X_CAP0.
- Description of several functionals.

### Added
- Missing C to Fortran interface for `xc_f90_nlc_coef`.
- Missing interfaces for the set_params functions in the Fortran 90 interface.

## [4.0.2] - 2017-11-03

### Fixed
- Range-separation parameter in HSE functionals was not accessible through the `xc_func_set_ext_params` function.
- Incorrect XC_CORRELATION flags in the XC_LDA_XC_1D_EHWLRG functionals.
- Example programs.
- Inconsistencies in the README files concerning the different build systems.

## [4.0.1] - 2017-09-28

### Added
- XC_FLAGS_DEVELOPMENT flag to XC_MGGA_C_KCIS, XC_HYB_MGGA_XC_B0KCIS, XC_HYB_MGGA_XC_MPW1KCIS, XC_HYB_MGGA_XC_MPWKCIS1K, XC_HYB_MGGA_XC_PBE1KCIS, and XC_HYB_MGGA_XC_TPSS1KCIS.

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
- XC_FLAGS_DEVELOPMENT flag from MGGA_C_SCAN.

### Fixed
- Name of several Minnesota functionals to reflect the new interface.
- Missing braces in initialization of XC_MGGA_X_MN12_L, XC_HYB_MGGA_X_MN12_SX, XC_MGGA_X_MN15_L, and XC_HYB_MGGA_X_MN15.

## [4.0.0] - 2017-09-24

### Added
- LDA functionals: C_CHACHIYO, C_PK09, X_REL, XC_GDSMFB.
- GGA functionals: X_EB88, X_BEEFVDW, C_PBE_MOL, C_BMK, C_TAU_HCTH, C_HYB_TAU_HCTH, XC_BEEFVDW, K_ABSP3, K_ABSP4.
- HYB_GGA functionals: XC_LC_WPBE, XC_PBE_MOL0, XC_PBE_SOL0, XC_PBEB0, XC_PBE_MOLB0, XC_HSE12, XC_HSE12S, XC_HSE12, XC_HSE_SOL, XC_KMLYP.
- MGGA functionals: X_BMK, X_B00, C_SCAN, C_SCAN_RVV10, C_REVM06_L.
- HYB_MGGA functionals: X_TAU_HCTH.
- New generic function `xc_func_set_ext_params` to set external parameters. This replaces the functional specific functions `xc_*_set_par`.
- CMake based build system. It is not intended to replace the Autotools based build system, but rather to make it easier to integrate Libxc in projects that use CMake.
- New interface to hybrid Minnesota exchange functionals HYB_MGGA_X_M05, HYB_MGGA_X_M05_2X, HYB_MGGA_X_M06_2X, HYB_MGGA_X_M06_HF, HYB_MGGA_X_M06, HYB_MGGA_X_M08_SO, HYB_MGGA_X_M08_HF, HYB_MGGA_X_M11.
- Function `xc_func_set_dens_threshold` to set the threshold for small densities. All quantities  are evaluated to zero when the density is smaller than this threshold.
- New utility `xc-threshold` to evaluate the behavior of a given functional in the limit of small densities for a variety of test cases. This is particularly useful in choosing the appropriate density threshold to be set by `xc_func_set_dens_threshold`.
- File **KNOWN_ISSUES** with a list of issues affecting some functionals that we are aware of.
- XC_FLAGS_NEEDS_LAPLACIAN flag to signal MGGA functionals that depend on the laplacian of the density.
- New **xc_funcs_removed.h** header file containing the ID's of removed functionals for backward compatibility.
- Several missing functions and flags from the Fortran interfaces.
- Functions to get the list of available functionals (`xc_number_of_functionals`, `xc_maximum_name_length`, `xc_available_functional_numbers`, and `xc_available_functional_names`).

### Changed
- All functionals have been reimplemented using Maple to generate the corresponding C code.
- Updated default density thresholds for all functionals.
- Tests from the test suite are now separated by the derivative order (exc, vxc, and fxc). This allows to more easily identify the reason for failed tests and to set different tolerances for the different quantities.
- Split LDA_X into LDA_X and LDA_X_REL (see added functionals above). This replaces the external parameter that allowed to choose between the relativistic and non-relativistic versions of the functional.
- GGA_X_BGCP and GGA_C_BGCP to GGA_X_BCGP and GGA_C_BCGP, respectively, keeping the old constants for backward compatibility.
- MGGA_C_CC06 to MGGA_XC_CC06, as the functional includes an exchange part, keeping the old constant for backward compatibility.

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
- Helper functionals that could be used in error instead of the true hybrid functional: MGGA_X_M05, MGGA_X_M05_2X, MGGA_X_M06_2X, MGGA_X_M06_HF, MGGA_X_M06, MGGA_X_M08_SO, MGGA_X_M08_HF, MGGA_X_M11.
- Exchange-correlation functional wrappers: HYB_MGGA_XC_M05, HYB_MGGA_XC_M05_2X, HYB_MGGA_XC_M06_2X, HYB_MGGA_XC_M06_HF, HYB_MGGA_XC_M06, HYB_MGGA_XC_M08_SO, HYB_MGGA_XC_M08_HF, HYB_MGGA_XC_M11. Replaced by e.g. the combination HYB_MGGA_X_M11+MGGA_C_M11.
- Functional specific functions `xc_*_set_par` to set external parameters.
- Single precision version.

### Fixed
- Bug in HYB_GGA_XC_CAP0.


## [3.0.0] - 2016-04-21
### Added
- Micro version number to version function and version header file.
- Version_string function, which returns the version number in the following format: `major.minor.micro`
- Fortran 2003 interface using the iso_c_bindings module.
- lda_vxc_fxc, gga_vxc_fxc, and mgga_vxc_fxc functions to Fortran 90 interface.
- LDA functionals: XC_ZLP, XC_KSDT.
- GGA functionals: X_LAMBDA_LO_N, X_LAMBDA_CH_N, X_LAMBDA_OC2_N, X_EV93, C_BGCP, X_BGCP, X_GAM, X_PBEFE, X_HCTH_A, C_GAM, C_PBEFE, C_OP_PW91, X_CAP.
- HYB_GGA functionals: XC_B3LYPs, XC_LRC_WPBEH, XC_LRC_WPBE, XC_WB97, XC_WB97X, XC_WB97X_V, XC_CAMY_B3LYP, XC_LC_VV10, XC_HPBEINT, XC_EDF2, XC_B3LYP5, XC_LCY_PBE, XC_LCY_BLYP, XC_CAP0.
- MGGA functionals: X_MBEEF, X_MBEEFVDW, X_MVS, X_SCAN, C_TPSSLOC, C_DLDF, X_MN15_L, C_MN15_L, C_MN15 XC_ZLP, XC_B97M_V.
- HYB_MGGA functionals: X_DLDF, X_MVSH, X_SCAN0, X_MN15, XC_M08_HX, XC_M08_SO, XC_WB97M_V, XC_B97_1p.

### Changed
- GGA_XC_HCTH_A to GGA_C_HCTH_A, as it does not include exchange (it uses a different form for exchange than the other functionals from the HCTH family), keeping the old constant for backward compatibility.
- GGA_C_VPBE to GGA_C_regTPSS, as that is the name used in the paper, keeping the old constant for backward compatibility.

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
* Helper functionals that can be used in error instead of the true hybrid functional: GGA_XC_B97, GGA_XC_B97_1, GGA_XC_B97_2, GGA_XC_B97_K, GGA_XC_B97_3, GGA_XC_SB98_1a, GGA_XC_SB98_1b, GGA_XC_SB98_1c, GGA_XC_SB98_2a, GGA_XC_SB98_2b, GGA_XC_SB98_2c, GGA_XC_WB97, GGA_XC_WB97X, GGA_XC_WB97X_V, GGA_C_WB97X_D, MGGA_X_MN12_SX.

### Fixed
- Incorrect family for XC_HYB_MGGA_X_MS2H, which was incorrectly defined as a normal MGGA (XC_MGGA_X_MS2H).
- Bugs in GGA_C_HCTH_A, GGA_XC_TH_FL, GGA_XC_TH_FC, GGA_XC_TH_FCFO, GGA_XC_TH_FCO, GGA_XC_TH1, GGA_XC_TH2, GGA_XC_TH3, GGA_XC_TH4, MGGA_X_M11, MGGA_X_M11_L, HYB_MGGA_X_MS2H.


## [2.1.3] and [2.2.3] - 2016-04-21
### Fixed
- Bugs in GGA_X_N12, GGA_C_N12, GGA_C_N12_SX, all the GGA_X_HJS_*, GGA_X_VMT84_GE, HYB_GGA_X_N12_SX, all the HYB_GGA_XC_HJS_*, HYB_GGA_XC_O3LYP, HYB_GGA_XC_X3LYP.
- Bugs in second derivatives of GGA_X_B88, GGA_X_OPTB88_VDW, GGA_X_MB88, GGA_K_LLP, GGA_K_FR_B88, GGA_K_THAKKAR.
- Build with gcc 6.


## [2.1.2] and [2.2.2] - 2015-02-19
### Fixed
- Bug in unpolarized version of GGA_X_LB and GGA_X_LBM.
- Bugs in MGGA_C_REVTPSS, MGGA_C_M08_HX, MGGA_C_M08_SO, MGGA_C_M11, MGGA_C_M11_L.
- Missing variable initialization that could cause Libxc to return wrong mixing parameters for all HYB_GGA and HYB_MGGA.


## [2.1.1] and [2.2.1] - 2014-10-30
### Fixed
- Several bugs in the build system.
- Bugs in GGA_X_SOGGA11, HYB_GGA_X_SOGGA11_X, HYB_GGA_XC_CAM_B3LYP, HYB_GGA_XC_TUNED_CAM_B3LYP.


## [2.2.0] - 2014-03-21
### Changed
- Fortran bindings are now in a separate library (libxcf90).


## [2.1.0] - 2014-03-21
### Added
- New testsuite.
- xc_f90_functional_get_name and xc_f90_functional_get_number Fortran wrappers.
- GGA functionals: C_VPBE, C_PBEINT, C_ZPBESOL, C_ZPBEINT, C_Q2D, C_N12, C_N12_SX, X_LV_RPW86, X_N12, X_VMT_GE, X_VMT_PBE, X_VMT84_PBE, X_VMT84_GE, X_PBEINT, X_PBE_TCA, X_SFAT, X_AK13, X_PBE_MOL, X_Q2D, XC_OBLYP_D, XC_OPWLYP_D, XC_OPBE_D, K_MEYER, K_REVAPBE, K_APBEINT, K_REVAPBEINT, K_TFVW.
- MGGA functionals: C_M08_HX, C_M08_SO, C_M11, C_M11_L, C_MN12_L, C_MN12_SX, C_CC06, X_MS0, X_MS1, X_MS2, X_MS2H, C_REVTPSS, X_MN12_L, X_MN12_SX, X_MK00, X_MK00B, X_BLOC, X_MODTPSS, XC_OTPSS_D, XC_TPSSLYP1W.
- HYB_GGA functionals:  X_N12_SX, XC_MPWLYP1M, XC_REVB3LYP.
- HYB_MGGA functionals: X_M11, X_M11_L, XC_CAMY_BLYP, XC_PWB6K, XC_PW6B95, XC_HYB_MGGA_XC_REVTPSSH, XC_HYB_MGGA_XC_TPSSH.
- Kxc for the following functionals GGA functionals: X_B86, X_B88, X_OPTB88_VDW, X_MB88, X_PBE, X_PBE_R, X_PBE_SOL, X_XPBE, X_PBE_JSJR, X_PBEK1_VDW, X_RGE2, X_APBE, X_PBEINT, X_PBE_TCA, X_WC, X_G96, X_RPBE, X_HTBS, X_PW86, X_PW91, X_AIRY, X_LAG, X_B86_MGC, X_BPCCAC, X_BAYESIAN, X_C09X, X_AM05, X_LG93, X_DK87_R1, X_DK87_R2, X_LV_RPW86, X_OPTX, X_SOGGA11, X_SSB_SW, X_VMT_PBE, X_VMT_GE, X_VMT84_PBE, X_VMT84_PBE, K_LLP, K_FR_B88, K_THAKKAR, K_APBE, K_REVAPBE, K_TW1, K_TW2, K_TW3, K_TW4, K_APBEINT, K_REVAPBEINT.
- Kxc for HYB_GGA_X_SOGGA11_X.

### Changed
- GGA_K_ABSR(1,2) to GGA_K_ABSP(1,2), keeping the old constants for backward compatibility.


## [2.0.3] - 2014-02-18
### Fixed
- Bugs in GGA_X_PBEA, MGGA_X_BR89, MGGA_X_BJ06, MGGA_X_TB09, MGGA_X_RPP09.
- Bug affecting second and third derivatives with spin-polarization of LDA_XC_TETER93.
- Non-initialized variable in the MGGA correlations, which could sometimes cause problems.

## [2.0.2] - 2013-07-10
### Fixed
- Bug in GGA_C_C09X.
* Non-initialized variables in LDA exchange that could sometimes cause problems.
* Some other small bugs.

## [2.0.1] - 2013-01-21
### Fixed
- Bug in all the B97-like GGA functionals.
- Bugs in MGGA_C_TPSS, MGGA_C_PKZB, MGGA_C_VSXC, MGGA_C_BC95.
- Numerical problems in the following functionals: GGA_C_WL, GGA_X_HJS, MGGA_C_OPTC, MGGA_C_TPSS, MGGA_C_PKZB.


## [2.0.0] - 2012-11-28
### Added
- Function and header file to get version number.
- LDA functionals: C_VWN1, C_VWN2, C_VWN3, C_VWN4, C_RC04.
- GGA functionals: C_OP, C_FT97, C_SPBE, X_SSB_SW, X_SSB, X_SSB_D, XC_HCTH_A, XC_B97_GGA1, XC_HCTH_P14, XC_HCTH_P76, XC_HCTH_407P, X_BPCCAC, C_LTA, C_revLTA, X_HJS.
- HYB_GGA functionals: XC_TUNED_CAM_B3LYP, XC_BHANDH, XC_CAM-B3LYP, XC_HSE
- MGGA: C_BC95, X_PKZB, C_PKZB, X_M05, C_M05, X_M05_2X, C_M05_2X, X_M06, C_M06, X_M06-L, C_M06-L, XC_M06-HF, C_M06-HF, X_M06-2x, C_M06-2x, X_M08_HX, X_M08_SO.
- HYB_MGGA functionals: XC_M05, XC_M05_2X, XC_BX88B95, XC_BX86B95, XC_PWX86B95, XC_BB1K, XC_MPW1B95, XC_MPWB1K, XC_X1B95, XC_XB1K.


### Changed
- Definition of tau in the metaGGAs. Now tau is the exact kinetic energy density (with the factor 1/2 included).
- Default interpolation of LDA_C_VWN.
- xc_hyb_gga_exx_coef function to xc_hyb_exx_coef.

### Fixed
- Several bugs.


## [1.2.0] - 2012-03-22
### Added
- GGA functionals: C_SOGGA11, X_SOGGA11, X_C09X, XC_TH1, XC_TH2, XC_TH3, XC_TH4, C_LM (spin-polarized), C_WI0, X_SOGGA, XC_MOHLYP, XC_MOHLYP2, X_AIRY, X_HTBS, etc.
- fxc to GGA_C_WI, GGA_C_WL, GGA_C_AM05, GGA_C_LYP, LDA_C_1D_CSC, etc.
- Regression tests.

### Changed
- xc_gga_exx_coef function to xc_hyb_gga_exx_coef.

- The pytest suite was registered with ctest as a single test, so a run reported one pass/fail line after a couple of minutes and could not use `ctest -j` at all. It is now one test per regression family, plus the API/util tests and the code-generation invariants: 21 tests in place of 1, the same 10541 tests, and 16 s of wall clock instead of 148 s. `xc-run_pytest` takes paths and defaults to `-q`, so a passing run shows what ran; with no arguments it behaves as before. The atomic tier stays opt-in — run it with `pytest -m atomic testsuite/atomic` (!817).

### Removed
- LCA functionals.

### Fixed
- Several bugs.


## [1.1.0] - 2011-05-12
### Added
- New framework for GGA_C to make easier introducing new functionals.
- fxc to several metaGGAs.
- LDA functionals: C_GOMBAS, K_LP, K_TF
- GGA functionals: X_APBE, X_MB88, X_OL2, X_HERMAN, C_APBE, C_WL, K_THAKKAR, K_TW1, K_TW2, K_TW3, K_TW4, K_APBE, K_LC94, K_PERDEW, K_VSK, K_VJKS, K_ERNZERHOF, K_DK, K_OL2, K_OL1, K_FR_PW86, K_FR_B88, K_LLP, K_PEARSON, K_VW, K_GE2, K_GOLDEN, K_YT65, K_BALTIN, K_LIEB, K_ABSR1, K_ABSR2, K_GR, K_LUDENA, K_GP85.
- MGGA functionals: X_2D_PRHG07, X_2D_PRHG07_PRP10.

### Fixed
- Many bugs.
- Several functionals when the input density is zero.


## [1.0.0] - 2010-07-09
### Added
- LDA fucntionals: X, X_2D, X_1D, C_WIGNER, C_RPA, C_HL, C_GL, C_XALPHA, C_VWN, C_VWN_RPA, C_PZ, C_PZ_MOD, C_OB_PZ, C_PW, C_PW_MOD, C_OB_PW, C_2D_AMGB, C_2D_PRM, C_vBH, C_1D_CSC, C_ML1, C_ML2, XC_TETER93.
- GGA functionals: X_PBE, X_PBE_R, X_B86, X_B86_R, X_B86_MGC, X_B88, X_G96, X_PW86, X_PW91, X_OPTX, X_DK87_R1, X_DK87_R2, X_LG93, X_FT97_A, X_FT97_B, X_PBE_SOL, X_RPBE, X_WC, X_mPW91, X_AM05, X_PBEA, X_MPBE, X_XPBE, X_2D_B86_MGC, X_BAYESIAN, X_PBE_JSJR, X_2D_B88, X_2D_B86, X_2D_PBE, X_OPTB88_VDW, X_PBEK1_VDW, X_OPTPBE_VDW, X_RGE2, C_PBE, C_LYP, C_P86, C_PBE_SOL, C_PW91, C_AM05, C_XPBE, C_LM, C_PBE_JRGX, C_RGE2, XC_LB, XC_HCTH_93, XC_HCTH_120, XC_HCTH_147, XC_HCTH_407, XC_EDF1, XC_XLYP, XC_B97, XC_B97_1, XC_B97_2, XC_B97_D, XC_B97_K, XC_B97_3, XC_PBE1W, XC_MPWLYP1W, XC_PBELYP1W, XC_SB98_1a, XC_SB98_1b, XC_SB98_1c, XC_SB98_2a, XC_SB98_2b, XC_SB98_2c, XC_B3PW91.
- HYB_GGA functionals: XC_B3LYP, XC_B3P86, XC_O3LYP, XC_mPW1K, XC_PBEH, XC_B97, XC_B97_1, XC_B97_2, XC_X3LYP, XC_B1WC, XC_B97_K, XC_B97_3, XC_mPW3PW, XC_B1LYP, XC_B1PW91, XC_mPW1PW, XC_mPW3LYP, XC_SB98_1a, XC_SB98_1b, XC_SB98_1c, XC_SB98_2a, XC_SB98_2b, XC_SB98_2c.
- MGGA functionals: X_LTA, X_TPSS, X_M06L, X_GVT4, X_TAU_HCTH, X_BR89, X_BJ06, X_TB09, X_RPP09, C_TPSS, C_VSXC.
- LCA functionals: OMC, LCH.
