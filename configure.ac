## Copyright (C) 2002-2006 M. Marques, A. Castro, A. Rubio, G. Bertsch
##               2019 X. Andrade
##               2020 Susi Lehtola
##
## This Source Code Form is subject to the terms of the Mozilla Public
## License, v. 2.0. If a copy of the MPL was not distributed with this
## file, You can obtain one at http://mozilla.org/MPL/2.0/.
##

AC_INIT([libxc],[7.1.2],[https://gitlab.com/libxc/libxc/],[libxc],[https://libxc.gitlab.io/])
AC_CONFIG_SRCDIR([src/xc.h])
AM_INIT_AUTOMAKE

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Check if libm needs to be explicitly linked
AC_SEARCH_LIBS([sinh], [m])
AC_SEARCH_LIBS([atan2], [m])
AC_SEARCH_LIBS([tanh], [m])
AC_SEARCH_LIBS([cosh], [m])
AC_SEARCH_LIBS([sin], [m])
AC_SEARCH_LIBS([atan], [m])
AC_SEARCH_LIBS([exp], [m])
AC_SEARCH_LIBS([cos], [m])
AC_SEARCH_LIBS([log], [m])
AC_SEARCH_LIBS([pow], [m])
AC_SEARCH_LIBS([round], [m])
AC_SEARCH_LIBS([sqrt], [m])
AC_SEARCH_LIBS([erf], [m])

# Library versioning (C:R:A == current:revision:age)
# See the libtool manual for an explanation of the numbers
#
# libxc-2.0.0   1:0:0
# libxc-2.0.1   1:1:0
# libxc-2.0.2   1:2:0
# libxc-2.0.3   1:3:0
# libxc-2.1.0   2:0:1
# libxc-2.1.1   2:1:1
# libxc-2.1.2   2:2:1
# libxc-2.1.3   2:3:1
# libxc-2.2.0   3:0:0
# libxc-2.2.1   3:1:0
# libxc-2.2.3   3:3:0
# libxc-3.0.0   4:0:0
# libxc-3.0.1   4:1:0
# libxc-4.0.0   5:0:0
# libxc-4.0.1   5:1:0
# libxc-4.0.2   5:2:0
# libxc-4.0.3   5:3:0
# libxc-4.0.4   5:4:0
# libxc-4.0.5   5:5:0
# libxc-4.1.0   6:0:1
# libxc-4.1.1   6:1:1
# libxc-4.2.0   7:0:2
# libxc-4.2.1   7:1:2
# libxc-4.2.2   7:2:2
# libxc-4.2.3   7:3:2
# libxc-4.3.0   8:0:3
# libxc-4.3.2   8:1:3
# libxc-4.3.2   8:2:3
# libxc-4.3.3   8:3:3
# libxc-4.3.4   8:4:3
# libxc-5.0.0   9:0:0
# libxc-5.1.0  10:0:1
# libxc-5.1.1  10:1:1
# libxc-5.1.2  10:2:1
# libxc-5.1.3  10:3:1
# libxc-5.1.4  10:4:1
# libxc-5.1.5  10:5:1
# libxc-5.1.6  10:6:1
# libxc-5.1.7  10:7:1
# libxc-5.2.0  11:0:2
# libxc-5.2.1  11:1:2
# libxc-5.2.2  11:2:2
# libxc-5.2.3  11:3:2
# libxc-6.0.0  12:0:0
# libxc-6.1.0  13:0:1
# libxc-6.2.0  14:0:2
# libxc-6.2.1  14:1:2
# libxc-6.2.2  14:2:2
# libxc-7.0.0  15:0:0
# libxc-7.1.0  16:0:1
# libxc-7.1.1  16:1:1
# libxc-7.1.2  16:2:1
# 
# Note that libtool versioning was not used prior to libxc-2.0.
# Because of this, we will start counting at 1.
#
# How to update library version number
# ====================================
# 
# C: increment if the interface has additions, changes, removals.
#
# R: increment any time the source changes; set to 0 if you
# incremented CURRENT
#
# A: increment if any interfaces have been added; set to 0 if any
# interfaces have been removed. removal has precedence over adding,
# so set to 0 if both happened.

XC_CURRENT=16
XC_REVISION=2
XC_AGE=1

XC_LT_VERSION="${XC_CURRENT}:${XC_REVISION}:${XC_AGE}"
AC_SUBST(XC_LT_VERSION)

# Split VERSION into XC_VERSION_MAJOR and XC_VERSION_MINOR
# Follows AX_SPLIT_VERSION macro from AC-Archive
# Rhys Ulerich <rhys.ulerich@gmail.com>
AC_PROG_SED
XC_MAJOR_VERSION=`echo "$VERSION" | $SED 's/\([[^.]][[^.]]*\).*/\1/'`
XC_MINOR_VERSION=`echo "$VERSION" | $SED 's/[[^.]][[^.]]*.\([[^.]][[^.]]*\).*/\1/'`
XC_MICRO_VERSION=`echo "$VERSION" | $SED 's/[[^.]][[^.]]*.[[^.]][[^.]]*.\(.*\)/\1/'`
AC_SUBST(XC_MAJOR_VERSION)
AC_SUBST(XC_MINOR_VERSION)
AC_SUBST(XC_MICRO_VERSION)


# Installation prefix by default
AC_PREFIX_DEFAULT([/opt/etsf])

# Default to a shared-only build: the Python test suite ctypes-loads libxc.so,
# so `./configure && make && make check` cannot work without it. CMake already
# defaults to shared for the same reason.
AC_DISABLE_STATIC
LT_PREREQ([2.2])
LT_INIT

AC_ARG_VAR([XC_TEST_FLAGS], [Flags that are passed to functional initialization])

# enable cuda first, since this is required for the compiler selection
AC_ARG_ENABLE(cuda, AS_HELP_STRING([--enable-cuda], [CUDA support]))
AC_ARG_ENABLE(hip, AS_HELP_STRING([--enable-hip], [HIP support]))

if test x"${enable_cuda}" = x"yes" ; then
  if test x"${enable_hip}" = x"yes" ; then
    AC_MSG_ERROR([Can only either CUDA or HIP, not both])
  fi
  AC_DEFINE(HAVE_CUDA, 1, [defined if cuda support is enabled])
  : "${XC_TEST_FLAGS="XC_FLAGS_ON_DEVICE"}"
else
  : "${XC_TEST_FLAGS="XC_FLAGS_ON_HOST"}"
fi

if test x"${enable_hip}" = x"yes" ; then
  AC_DEFINE(HAVE_CUDA, 1, [defined if cuda support is enabled])
  AC_DEFINE(HAVE_HIP, 1, [defined if hip support is enabled])
  : "${XC_TEST_FLAGS="XC_FLAGS_ON_DEVICE"}"
else
  : "${XC_TEST_FLAGS="XC_FLAGS_ON_HOST"}"
fi

AM_CONDITIONAL([HAVE_CUDA], [test x"${enable_cuda}" = x"yes" -o x"${enable_hip}" = x"yes"])
AM_CONDITIONAL([HAVE_HIP], [test x"${enable_hip}" = x"yes"])

# Checks for programs.
AC_PROG_CC

# 32-bit x86 defaults to 387 math, which keeps intermediates in 80-bit
# registers and rounds them on spill, so results depend on register allocation
# rather than on the arithmetic: on i686 the regression suite misses
# gga_x_hjs_pbe's v2sigma2 by 2x its tolerance and mgga_x_2d_prhg07_prp10's
# v2rho2 by 2000x. Ask for SSE2 instead, which is what every 64-bit target
# already uses. (-fexcess-precision=standard fixes the semantics without
# requiring SSE2, but makes GCC pathological on the larger generated kernels --
# gga_x_wpbeh.c alone did not finish compiling in 46 minutes.)
#
# The cost is a Pentium 4 / Athlon 64 baseline on 32-bit x86 only; x86-64
# already implies SSE2 and other architectures are untouched.
AC_CANONICAL_HOST
AS_CASE([$host_cpu],
  [i?86], [
    AC_MSG_CHECKING([whether $CC accepts -msse2 -mfpmath=sse])
    acx_save_cflags="${CFLAGS}"
    CFLAGS="${CFLAGS} -msse2 -mfpmath=sse"
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[]], [[double x = 1.0; return x == 0.0;]])],
      [AC_MSG_RESULT([yes])
       AC_MSG_NOTICE([32-bit x86: using SSE2 math instead of 387])],
      [AC_MSG_RESULT([no])
       CFLAGS="${acx_save_cflags}"
       AC_MSG_WARN([32-bit x86 without SSE2: x87 excess precision will make some second derivatives disagree with the reference values])])
  ])

#we may need to set the linker for the cuda case, so pass that to automake
if test x"$CCLD" = x ; then
   CCLD=$CC
fi
AC_SUBST(CCLD)

# When the C compiler is nvcc, every object file gets CUDA runtime stub
# code injected (cudaPeekAtLastError when --enable-cuda, plus
# __cudaRegisterFatBinary etc. unconditionally), so consumers that link
# through a non-nvcc driver (e.g. the gfortran-linked Fortran example)
# need an explicit -lcudart. Detect that case and propagate the dep,
# including the CUDA library directory derived from the nvcc location.
NVCC_LIBS=
case "$CC" in
  *nvcc*)
    nvcc_bin=${CC%% *}
    nvcc_path=`command -v "$nvcc_bin" 2>/dev/null`
    NVCC_LIBS="-lcudart"
    if test -n "$nvcc_path" ; then
      nvcc_libdir=`dirname "$nvcc_path"`/../lib64
      if test -d "$nvcc_libdir" ; then
        NVCC_LIBS="-L$nvcc_libdir -lcudart"
      fi
    fi
    ;;
esac
AC_SUBST([NVCC_LIBS])

AC_LANG_PREPROC
AM_PROG_CC_C_O
AC_C_INLINE

# Checks for header files.
AC_FUNC_ALLOCA

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_SIZEOF(void*)

# Need BASH to run tests
AC_CHECK_PROG([BASH_SHELL],[bash],[yes])

# Check for presence of some C99 libm functions
AC_CHECK_LIB([m],[cbrt],[AC_DEFINE([HAVE_CBRT],[1],[libm includes cbrt])])
AC_CHECK_LIB([m],[feenableexcept],[AC_DEFINE([HAVE_FEENABLEEXCEPT],[1],[libm includes feenableexcept])])

AC_ARG_WITH([custom-fmoddir],
	    [AS_HELP_STRING([--with-custom-fmoddir=DIR],
			    [Instalation directory for Fortran module files (includedir by default)])],
	    [AC_SUBST([FMODDIR],["$withval"])],
	    [AC_SUBST([FMODDIR],['${includedir}'])])

# Highest derivative order to build:
#   0 = energy (exc) only, 1 = +vxc, 2 = +fxc, 3 = +kxc, 4 = +lxc.
AC_ARG_ENABLE([maxorder],
	      AS_HELP_STRING([--enable-maxorder@<:@=N@:>@],
	        [highest derivative order to build: 0 exc, 1 vxc, 2 fxc, 3 kxc, 4 lxc (default 2)]),
	      [maxorder=$enableval], [maxorder=2])

# Deprecated per-order switches, kept as aliases for one release. Pre-7.1 the
# built order was the highest one NOT disabled; reproduce that by deriving the
# order from the disabled orders (from the full order 4) and overriding the
# default, so --disable-lxc gives 3 (and --enable-kxc --disable-lxc gives 3).
dep_used=no
depmax=4
AC_ARG_ENABLE([lxc], AS_HELP_STRING([--disable-lxc], [deprecated; use --enable-maxorder=3]),
	      [AS_IF([test x"$enableval" = x"no"],
	         [dep_used=yes; AS_IF([test "$depmax" -gt 3], [depmax=3])])])
AC_ARG_ENABLE([kxc], AS_HELP_STRING([--disable-kxc], [deprecated; use --enable-maxorder=2]),
	      [AS_IF([test x"$enableval" = x"no"],
	         [dep_used=yes; AS_IF([test "$depmax" -gt 2], [depmax=2])])])
AC_ARG_ENABLE([fxc], AS_HELP_STRING([--disable-fxc], [deprecated; use --enable-maxorder=1]),
	      [AS_IF([test x"$enableval" = x"no"],
	         [dep_used=yes; AS_IF([test "$depmax" -gt 1], [depmax=1])])])
AC_ARG_ENABLE([vxc], AS_HELP_STRING([--disable-vxc], [deprecated; use --enable-maxorder=0]),
	      [AS_IF([test x"$enableval" = x"no"],
	         [dep_used=yes; depmax=0])])
AS_IF([test "$dep_used" = "yes"],
      [AC_MSG_WARN([--disable-*xc are deprecated; use --enable-maxorder=$depmax]); maxorder=$depmax])

AS_CASE([$maxorder], [0|1|2|3|4], [],
        [AC_MSG_ERROR([--enable-maxorder must be an integer 0..4 (got '$maxorder')])])
AC_MSG_NOTICE([building derivatives up to order $maxorder])
AC_DEFINE_UNQUOTED(XC_MAXORDER, $maxorder, [highest derivative order compiled])

AC_ARG_ENABLE([fhc],
	      AS_HELP_STRING([--disable-fhc], [do not enforce Fermi hole curvature]),
	      [ac_cv_build_fhc=$enableval],
	      [ac_cv_build_fhc=yes])
if test x"${ac_cv_build_fhc}" = x"yes"; then
  AC_DEFINE(XC_ENFORCE_FERMI_HOLE_CURVATURE, 1, [defined if Fermi hole curvature is enforced])
fi

AC_ARG_ENABLE(check-numerics,
              AS_HELP_STRING([--enable-check-numerics],
                             [check functional outputs for NaN/Inf and (where supported) trap FPEs during evaluation]))
if test x"${enable_check_numerics}" = x"yes" ; then
  AC_DEFINE(XC_CHECK_NUMERICS, 1, [defined if functional-evaluation numerics checks are enabled])
fi

# build/install fortran bits unless --disable-fortran is used
AC_ARG_ENABLE([fortran],
	      AS_HELP_STRING([--disable-fortran], [don't build/install fortran components]),
	      [ac_cv_build_fortran=$enableval],
	      [ac_cv_build_fortran=yes])
AM_CONDITIONAL([ENABLE_FORTRAN], [test $ac_cv_build_fortran = yes])

if test $ac_cv_build_fortran = yes; then
  HAVE_FORTRAN=1
  AC_DEFINE(HAVE_FORTRAN, [1], [Defined if libxc is compiled with fortran support])

  dnl try to find out what is the default FORTRAN 90 compiler
  acx_save_fcflags="${FCFLAGS}"
  AC_PROG_FC([], [Fortran 90])
  if test x"$FC" = x; then
    AC_MSG_ERROR([could not find Fortran 90 compiler])
  fi

  AC_LANG_PUSH(Fortran)
  AC_FC_SRCEXT(f90)
  FCFLAGS="${acx_save_fcflags}"

  dnl Fortran default flags
  ACX_FCFLAGS

  dnl libxc needs the preprocessor. The result goes to FCCPP
  ACX_FCCPP

  dnl how Fortran mangles function names
  AC_FC_WRAPPERS

  dnl check whether we have or not a compiler that allows for very long lines...
  ACX_LONG_FORTRAN_LINES

  dnl check whether the Fortran 90 compiler accepts line markers cast by the preprocessor.
  ACX_F90_ACCEPTS_LINE_NUMBERS

  AX_F90_MODULE_EXTENSION

  dnl Need to know the size of a Fortran integer
  ACX_FC_INTEGER_SIZE
  ACX_CC_FORTRAN_INT

  dnl check whether the Fortran compiler supports Fortran 2003 iso_c_binding
  ACX_FC_ISO_C_BINDING([], [AC_MSG_ERROR([Could not find Fortran 2003 iso_c_binding. Fortran 2003 interface can not be compiled.])])

AC_LANG_POP([Fortran])
else
  HAVE_FORTRAN=0
fi
AC_SUBST(ax_cv_f90_modext)
AM_CONDITIONAL(F90_MOD_UPPERCASE, [test x$ax_f90_mod_uppercase = xyes])
AM_CONDITIONAL(COMPILE_FORTRAN, test x${HAVE_FORTRAN} = x1)
AM_CONDITIONAL([COMPILE_FORTRAN03], [test x$ac_cv_build_fortran03 = xyes])
AM_CONDITIONAL([BUILD_FORTRAN_EXAMPLES],
  [test x${HAVE_FORTRAN} = x1 -a x"${enable_cuda}" != x"yes" -a x"${enable_hip}" != x"yes"])


AC_CONFIG_FILES([Makefile
  xc_version.h
  src/Makefile
  src/maple2c/Makefile
  src/maple2c/lda_exc/Makefile
  src/maple2c/lda_vxc/Makefile
  src/maple2c/gga_exc/Makefile
  src/maple2c/gga_vxc/Makefile
  src/maple2c/mgga_exc/Makefile
  src/maple2c/mgga_vxc/Makefile
  testsuite/Makefile
  testsuite/general/Makefile
  pkgconfig/Makefile
  pkgconfig/libxc.pc
  pkgconfig/libxcf03.pc
  scripts/Makefile
  maple/Makefile
  maple/lda_exc/Makefile
  maple/lda_vxc/Makefile
  maple/gga_exc/Makefile
  maple/gga_vxc/Makefile
  maple/mgga_exc/Makefile
  maple/mgga_vxc/Makefile
  pylibxc/Makefile
  cmake/Makefile
  examples/Makefile
  examples/fortran/Makefile
])

AC_OUTPUT

AC_MSG_WARN([
  The Autotools build system is deprecated and will be removed in libxc 8.0.0.
  Please migrate to the CMake build system.])

