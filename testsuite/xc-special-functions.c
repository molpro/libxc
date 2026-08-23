/*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/*
  Accuracy unit test for libxc's hand-rolled special functions.  These are
  not exposed through the Python interface, so this is their only direct
  test.  The reference values in xc-special-functions-data.h are computed
  with mpmath; regenerate them with

      python3 xc-special-functions-gen.py > xc-special-functions-data.h
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

/* internal special functions (declared in util.h, linked from libxc) */
double LambertW(double z);
double xc_dilogarithm(double x);
double xc_expint_e1_impl(double x, int scale);
double xc_bessel_I0(double x), xc_bessel_I1(double x);
double xc_bessel_K0(double x), xc_bessel_K1(double x);
double xc_bessel_I0_scaled(double x), xc_bessel_I1_scaled(double x);
double xc_bessel_K0_scaled(double x), xc_bessel_K1_scaled(double x);
double xc_erfcx(double x);

#include "xc-special-functions-data.h"

#include "xc-nodialog.h"
static double eval(const char *n, double x) {
  if (!strcmp(n, "lambertw")) return LambertW(x);
  if (!strcmp(n, "dilog"))    return xc_dilogarithm(x);
  if (!strcmp(n, "e1"))       return xc_expint_e1_impl(x, 0);
  if (!strcmp(n, "e1s"))      return xc_expint_e1_impl(x, 1);
  if (!strcmp(n, "I0"))       return xc_bessel_I0(x);
  if (!strcmp(n, "I1"))       return xc_bessel_I1(x);
  if (!strcmp(n, "I0s"))      return xc_bessel_I0_scaled(x);
  if (!strcmp(n, "I1s"))      return xc_bessel_I1_scaled(x);
  if (!strcmp(n, "K0"))       return xc_bessel_K0(x);
  if (!strcmp(n, "K1"))       return xc_bessel_K1(x);
  if (!strcmp(n, "K0s"))      return xc_bessel_K0_scaled(x);
  if (!strcmp(n, "K1s"))      return xc_bessel_K1_scaled(x);
  if (!strcmp(n, "erfcx"))    return xc_erfcx(x);
  fprintf(stderr, "unknown function %s\n", n);
  return NAN;
}

int main(void) {
  xc_test_no_dialogs();
  const double tol = 1e-12;
  int i, n = (int)(sizeof(xc_sf_cases) / sizeof(xc_sf_cases[0])), nfail = 0;
  for (i = 0; i < n; i++) {
    double v = eval(xc_sf_cases[i].name, xc_sf_cases[i].x);
    double r = xc_sf_cases[i].ref;
    double denom = fabs(r) > 1e-300 ? fabs(r) : 1.0;
    double rel = fabs(v - r) / denom;
    if (isnan(v) || isinf(v) || rel > tol) {
      printf("FAIL %-9s(%.6g) = %.17g  ref %.17g  rel %.3e\n",
             xc_sf_cases[i].name, xc_sf_cases[i].x, v, r, rel);
      nfail++;
    }
  }
  printf("special functions: %d cases, %d failures (rel tol %.0e)\n", n, nfail,
         tol);
  return nfail ? 1 : 0;
}
