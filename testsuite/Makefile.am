## Process this file with automake to produce Makefile.in

## Copyright (C) 2002 M. Marques, A. Castro, A. Rubio, G. Bertsch
##
## This Source Code Form is subject to the terms of the Mozilla Public
## License, v. 2.0. If a copy of the MPL was not distributed with this
## file, You can obtain one at http://mozilla.org/MPL/2.0/.
##

SUBDIRS = general

noinst_PROGRAMS = xc-get_data xc-wellbehaved
check_PROGRAMS = xc-special-functions xc-api xc-distinct
dist_noinst_SCRIPTS = xc-generate_tests.py xc-special-functions-gen.py

# This disables running tests in parallel in automake (which is not needed since pytest does it anyway) to get the output in stdout
AUTOMAKE_OPTIONS = serial-tests
TESTS = xc-run_pytest xc-special-functions xc-api xc-distinct
TESTS_ENVIRONMENT = PYTHONPATH='$(abs_srcdir)/../:$(PYTHONPATH)'; export PYTHONPATH; LD_LIBRARY_PATH='$(abs_top_builddir)/src/.libs/:$(LD_LIBRARY_PATH)'; export LD_LIBRARY_PATH; XC_TEST_FLAGS='$(XC_TEST_FLAGS)'; export XC_TEST_FLAGS; echo "Set PYTHONPATH=$$PYTHONPATH and LD_LIBRARY_PATH=$$LD_LIBRARY_PATH";

xc_get_data_SOURCES = xc-get_data.c
xc_get_data_LDADD = -L../src/ -lxc -lm
xc_get_data_CPPFLAGS = -I$(srcdir)/../src/ -I$(top_builddir)/src

xc_wellbehaved_SOURCES = xc-wellbehaved.c
xc_wellbehaved_LDADD = -L../src/ -lxc -lm
xc_wellbehaved_CPPFLAGS = -I$(srcdir)/../src/ -I$(top_builddir)/src

xc_special_functions_SOURCES = xc-special-functions.c
xc_special_functions_LDADD = -L../src/ -lxc -lm
xc_special_functions_CPPFLAGS = -I$(srcdir) -I$(srcdir)/../src/ -I$(top_builddir)/src

xc_api_SOURCES = xc-api.c
xc_api_LDADD = -L../src/ -lxc -lm
xc_api_CPPFLAGS = -I$(srcdir)/../src/ -I$(top_builddir)/src

xc_distinct_SOURCES = xc-distinct.c
xc_distinct_LDADD = -L../src/ -lxc -lm
xc_distinct_CPPFLAGS = -I$(srcdir)/../src/ -I$(top_builddir)/src

dist_noinst_DATA = CMakeLists.txt $(srcdir)/df_repo/*.data $(srcdir)/regression/*/*.py $(srcdir)/xc-special-functions-data.h $(srcdir)/xc-nodialog.h $(srcdir)/atomic/*.py $(srcdir)/atomic/koga_hf_data.json $(srcdir)/atomic/references/*.dat $(srcdir)/atomic/references/convergence.json $(srcdir)/test_codegen_determinism.py $(srcdir)/test_math_utilities.py

# Delete temporary working directories from testsuite runs, if they are older than MINTIME (in minutes)
MINTIME=600
# note: beginning line with '-' means ignore the exit status of the command
clean-local:
	-if test "x$$tmpdir" == "x"; then tmpdir=/tmp; fi; \
	find $$tmpdir -name 'libxc*' -type d -mmin +$(MINTIME) -exec rm -rf {} \; 2> /dev/null

CLEANFILES = *~ *.bak

.PHONY: clean clean-local
