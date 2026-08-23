/*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/*
  Characterization tests for the stable public API surface: version,
  init/end, the info accessors, name<->number mapping, a known-value
  evaluation, and registry integrity across every functional.  These pin
  current behaviour as a safety net for the planned API restructuring;
  exhaustive per-signature coverage is deferred until the new API settles.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include <xc_funcs.h>

#include "xc-nodialog.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static int fails = 0;
#define CHECK(cond, msg)                                                       \
  do {                                                                         \
    if (!(cond)) {                                                             \
      printf("FAIL: %s\n", (msg));                                             \
      fails++;                                                                 \
    }                                                                          \
  } while (0)

static void test_version(void) {
  int major = -1, minor = -1, micro = -1;
  xc_version(&major, &minor, &micro);
  CHECK(major >= 0 && minor >= 0 && micro >= 0, "version components non-negative");
  CHECK(major >= 6, "version major is current (>=6)");
  const char *vs = xc_version_string();
  CHECK(vs != NULL && vs[0] != '\0', "version string non-empty");
}

static void test_init_end(void) {
  xc_func_type f;
  CHECK(xc_func_init(&f, XC_LDA_X, XC_UNPOLARIZED) == 0, "init LDA_X succeeds");
  CHECK(xc_func_get_info(&f) != NULL, "get_info non-null after init");
  xc_func_end(&f);

  xc_func_type g;
  CHECK(xc_func_init(&g, -12345, XC_UNPOLARIZED) != 0, "init of invalid id fails");
}

static void test_info_accessors(void) {
  xc_func_type f;
  if (xc_func_init(&f, XC_LDA_X, XC_UNPOLARIZED) != 0) {
    printf("FAIL: info: LDA_X init\n");
    fails++;
    return;
  }
  const xc_func_info_type *info = xc_func_get_info(&f);
  CHECK(xc_func_info_get_number(info) == XC_LDA_X, "info number == XC_LDA_X");
  CHECK(xc_func_info_get_kind(info) == XC_EXCHANGE, "info kind == XC_EXCHANGE");
  CHECK(xc_func_info_get_family(info) == XC_FAMILY_LDA, "info family == XC_FAMILY_LDA");
  CHECK(xc_func_info_get_name(info) != NULL &&
            strcmp(xc_func_info_get_name(info), "Slater exchange") == 0,
        "info name == 'Slater exchange'");
  CHECK((xc_func_info_get_flags(info) & XC_FLAGS_HAVE_EXC) != 0, "info has HAVE_EXC");
  CHECK(xc_func_info_get_references(info, 0) != NULL, "info reference 0 non-null");
  xc_func_end(&f);
}

static void test_name_number_roundtrip(void) {
  CHECK(xc_functional_get_number("lda_x") == XC_LDA_X,
        "functional_get_number('lda_x') == XC_LDA_X");
  char *name = xc_functional_get_name(XC_LDA_X);
  CHECK(name != NULL && strcmp(name, "lda_x") == 0,
        "functional_get_name(XC_LDA_X) == 'lda_x'");
  free(name);
}

static void test_eval_lda_x(void) {
  /* analytic spin-unpolarized Slater exchange:
       eps_x = -(3/4)(3/pi)^(1/3) rho^(1/3),  v_x = (4/3) eps_x  */
  xc_func_type f;
  if (xc_func_init(&f, XC_LDA_X, XC_UNPOLARIZED) != 0) {
    printf("FAIL: eval: LDA_X init\n");
    fails++;
    return;
  }
  const double Cx = 0.75 * cbrt(3.0 / M_PI);
  const double rho[] = {0.3, 0.7, 2.5};
  int i;
  for (i = 0; i < 3; i++) {
    double r = rho[i], zk = 0, vrho = 0;
    xc_lda_exc_vxc(&f, 1, &r, &zk, &vrho);
    double exc_ref = -Cx * cbrt(r);
    double vrho_ref = (4.0 / 3.0) * exc_ref;
    CHECK(fabs(zk - exc_ref) <= 1e-12 * fabs(exc_ref), "LDA_X exc matches analytic");
    CHECK(fabs(vrho - vrho_ref) <= 1e-12 * fabs(vrho_ref), "LDA_X vrho matches analytic");
  }
  xc_func_end(&f);
}

static void test_all_functionals_have_info(void) {
  int n = xc_number_of_functionals();
  CHECK(n > 0, "number_of_functionals > 0");
  int *list = (int *)malloc(n * sizeof(int));
  xc_available_functional_numbers(list);
  int bad = 0, i;
  for (i = 0; i < n; i++) {
    xc_func_type f;
    if (xc_func_init(&f, list[i], XC_UNPOLARIZED) != 0 &&
        xc_func_init(&f, list[i], XC_POLARIZED) != 0) {
      printf("FAIL: functional %d cannot be initialized\n", list[i]);
      bad++;
      continue;
    }
    const xc_func_info_type *info = xc_func_get_info(&f);
    if (info == NULL || xc_func_info_get_name(info) == NULL ||
        xc_func_info_get_number(info) != list[i]) {
      printf("FAIL: functional %d has inconsistent info\n", list[i]);
      bad++;
    }
    xc_func_end(&f);
  }
  free(list);
  CHECK(bad == 0, "all available functionals init and expose consistent info");
  printf("  (checked %d functionals)\n", n);
}

int main(void) {
  xc_test_no_dialogs();
  test_version();
  test_init_end();
  test_info_accessors();
  test_name_number_roundtrip();
  test_eval_lda_x();
  test_all_functionals_have_info();
  printf("public API: %d failure(s)\n", fails);
  return fails ? 1 : 0;
}
