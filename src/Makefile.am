## Process this file with automake to produce Makefile.in

## Copyright (C) 2002 M. Marques, A. Castro, A. Rubio, G. Bertsch
##
## This Source Code Form is subject to the terms of the Mozilla Public
## License, v. 2.0. If a copy of the MPL was not distributed with this
## file, You can obtain one at http://mozilla.org/MPL/2.0/.
##

SUBDIRS = maple2c

if HAVE_CUDA
if HAVE_HIP
else
#this is a hack for nvcc, this should be improved.
CC+="-dc"
endif
endif

bin_PROGRAMS = xc-info
noinst_PROGRAMS = genwiki xc-sanity xc-threshold

xc_info_SOURCES = xc-info.c
xc_info_LDADD = libxc.la -lm
xc_info_LDFLAGS =

xc_threshold_SOURCES = xc-threshold.c
xc_threshold_LDADD = libxc.la -lm
xc_threshold_LDFLAGS =

genwiki_SOURCES = genwiki.c
genwiki_LDADD = libxc.la -lm
genwiki_LDFLAGS =

xc_sanity_SOURCES = xc-sanity.c
xc_sanity_LDADD = libxc.la -lm
xc_sanity_LDFLAGS =

lib_LTLIBRARIES = libxc.la

include $(srcdir)/sources.mk
libxc_la_SOURCES = $(libxc_la_FUNC_SOURCES)
libxc_la_LDFLAGS = -version-info $(XC_LT_VERSION)
libxc_la_LIBADD = $(NVCC_LIBS)

if COMPILE_FORTRAN
  lib_LTLIBRARIES += libxcf03.la

  libxcf03_la_SOURCES = libxcf03.f90

  # libtool stuff
  libxcf03_la_LDFLAGS = -version-info $(XC_LT_VERSION)
  libxcf03_la_LIBADD = libxc.la
endif

noinst_HEADERS = \
	string_f.h references.h util.h \
	work_lda.c work_lda_inc.c work_gga.c work_gga_inc.c	\
	work_mgga.c work_mgga_inc.c \
	libxc_master.F90 \
        funcs_lda.c funcs_hyb_lda.c funcs_gga.c funcs_hyb_gga.c funcs_mgga.c funcs_hyb_mgga.c funcs_key.c \
	libxc_inc.f90
include_HEADERS = xc.h xc_funcs.h xc_funcs_removed.h xc_funcs_worker.h

# Machine-readable functional database emitted by 'make funcs'
# (scripts/get_functional_info.py). Tracked and shipped so downstream
# documentation tooling (e.g. the wiki functional list) can consume it,
# including the atomic-quadrature convergence characterisation.
EXTRA_DIST = libxc_docs.json

## declare fortran modules so they are installed
fmoddir = @FMODDIR@
fmod_DATA =

if COMPILE_FORTRAN

# Double precision modules are always compiled
if F90_MOD_UPPERCASE
  XCF03LIBMODS = XC_F03_LIB_M.@ax_cv_f90_modext@ XC_F03_FUNCS_M.@ax_cv_f90_modext@
else
  XCF03LIBMODS = xc_f03_lib_m.@ax_cv_f90_modext@ xc_f03_funcs_m.@ax_cv_f90_modext@
endif
fmod_DATA += $(XCF03LIBMODS)

endif # COMPILE_FORTRAN


CLEANFILES = *~ *.bak *.mod *.il *.d *.pc* ifc*

xc_f.o : xc_f_inc.c

funcs: $(srcdir)/../scripts/get_functional_info.py
	$(srcdir)/../scripts/get_functional_info.py --srcdir=$(srcdir)

LTPREF = $(subst xc_f.lo,,$(firstword $(am_libxcf03_la_OBJECTS)))
# Surprisingly, libtool/automake do not seem to provide a macro or variable for what the object names will be,
# so we have to extract it ourselves. LTPREF=libxcf03_la-, or blank for older libtool/automake versions.
# Produces these warnings on some systems. Does not seem to matter.
#src/Makefile.am:140: subst xc_f.lo,,$(firstword $(am_libxcf03_la_OBJECTS: non-POSIX variable name
#src/Makefile.am:140: (probably a GNU make extension)

LTPREF03 = $(subst libxcf03.lo,,$(firstword $(libxcf03_la_OBJECTS)))
libxcf03.f90 : libxc_master.F90 libxc_inc.f90
	@FCCPP@ @CPPFLAGS@ $(AM_CPPFLAGS) -I$(top_builddir)/src $(srcdir)/libxc_master.F90 > $(top_builddir)/src/libxcf03.f90
	@if [ "@F90_ACCEPTS_LINE_NUMBERS@" = "no" ]; then \
		grep -v "^#" $(top_builddir)/src/libxcf03.f90 > $(top_builddir)/src/libxcf03.f91; \
		mv -f $(top_builddir)/src/libxcf03.f91 $(top_builddir)/src/libxcf03.f90; \
	fi

$(XCF03LIBMODS) : $(LTPREF03)libxcf03.lo
