## Process this file with automake to produce Makefile.in

## Copyright (C) 2025 libxc developers
##
## This Source Code Form is subject to the terms of the Mozilla Public
## License, v. 2.0. If a copy of the MPL was not distributed with this
## file, You can obtain one at http://mozilla.org/MPL/2.0/.
##

# Skip the Fortran examples in GPU builds: libxc is compiled with
# relocatable device code (nvcc -dc / hipcc -fgpu-rdc), so its archive
# contains __cudaRegisterLinkedBinary_* symbols that are only resolved
# by nvcc/hipcc's device-link step. gfortran can't perform that step,
# so the Fortran examples fail to link. (HAVE_CUDA covers both CUDA
# and HIP — see configure.ac.)
if BUILD_FORTRAN_EXAMPLES
  AM_FCFLAGS = -I$(top_builddir)/src

  noinst_PROGRAMS = basic xcinfo

  basic_SOURCES  = basic.f90
  basic_LDADD    = $(top_builddir)/src/libxcf03.la $(top_builddir)/src/libxc.la

  xcinfo_SOURCES = xcinfo.f90
  xcinfo_LDADD   = $(top_builddir)/src/libxcf03.la $(top_builddir)/src/libxc.la
endif # BUILD_FORTRAN_EXAMPLES

CLEANFILES = *~ *.bak
