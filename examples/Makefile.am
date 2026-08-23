## Process this file with automake to produce Makefile.in

## Copyright (C) 2025 libxc developers
##
## This Source Code Form is subject to the terms of the Mozilla Public
## License, v. 2.0. If a copy of the MPL was not distributed with this
## file, You can obtain one at http://mozilla.org/MPL/2.0/.
##

SUBDIRS = fortran

AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_builddir)/src
LDADD       = $(top_builddir)/src/libxc.la -lm

noinst_PROGRAMS = basic get_refs

basic_SOURCES    = basic.c
get_refs_SOURCES = get_refs.c

# The .cu / .hip sources are stored as .c so automake's standard rules
# pick them up; CC is nvcc (with -x cu) or hipcc (with -x hip) in these
# builds, so the GPU-specific syntax compiles correctly.
if HAVE_CUDA
  noinst_PROGRAMS += cuda_example
  cuda_example_SOURCES = cuda.c
  cuda_example_LDADD   = $(top_builddir)/src/libxc.la -lm -lcudart
endif # HAVE_CUDA

if HAVE_HIP
  noinst_PROGRAMS += rocm_example
  rocm_example_SOURCES = rocm.c
  rocm_example_LDADD   = $(top_builddir)/src/libxc.la -lm
endif # HAVE_HIP

CLEANFILES = *~ *.bak
