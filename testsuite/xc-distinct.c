/*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/*
  Guard against two functionals accidentally computing the identical
  functional (e.g. a copy-paste leaving one evaluating the wrong base, or
  a parameter array duplicated from another).  Every functional is
  fingerprinted by its energy density zk at a fixed battery of points
  spanning extreme reduced gradient / iso-orbital indicator / spin
  polarization, plus its exact-exchange/range parameters (cam_*).  This is
  invariant to helper names and code structure -- it compares the actual
  mathematics, which textual duplication checks cannot.

  Functionals that *legitimately* share this fingerprint are allow-listed
  below (the difference lives somewhere zk + cam cannot see -- a nonlocal
  VV10 term, or a runtime-N-dependent parameter).  Any unexpected
  collision fails the test.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>
#include <xc_funcs.h>

#include "xc-nodialog.h"
#define NP 16
static const double P[NP][9] = {
 {0.5,0.3, 0.10,0.05,0.04, 0.2,0.1, 0.30,0.20},
 {1.0,0.8, 0.30,0.20,0.15, 0.1,0.1, 0.80,0.60},
 {0.2,0.2, 0.02,0.02,0.02, 0.05,0.05, 0.10,0.10},
 {2.0,0.1, 0.50,0.05,0.02, 0.3,0.05, 1.50,0.10},
 {0.1,0.05,0.010,0.004,0.003,0.02,0.01,0.05,0.02},
 {1.5,1.5, 0.40,0.40,0.40, 0.2,0.2, 1.00,1.00},
 {0.7,0.4, 0.20,0.10,0.08, 0.15,0.08,0.40,0.25},
 {3.0,2.0, 1.00,0.60,0.40, 0.5,0.3, 2.00,1.40},
 {0.5,0.3, 5.00,1.00,2.00, 1.0,0.5, 5.00,3.00},
 {0.05,0.02,2.00,0.30,0.50,-0.5,-0.2,0.30,0.10},
 {2.0,1.8, 0.01,0.005,0.008,0.05,0.05,8.00,7.00},
 {1.0,0.001,0.30,0.0003,0.0001,0.1,0.001,0.50,0.001},
 {0.3,0.3, 8.00,8.00,8.00, 2.0,2.0, 0.50,0.50},
 {5.0,3.0, 0.10,0.05,0.04, 1.0,0.6, 0.20,0.10},
 {0.01,0.008,0.001,0.0005,0.0004,0.005,0.004,0.01,0.008},
 {1.2,0.9, 3.00,1.00,2.00,-1.0,-0.5,2.00,1.50},
};

/* Groups of functionals that may legitimately share a zk+cam fingerprint.
   Each line is one space-separated group; difference is non-semilocal. */
static const char *allow[] = {
  /* gamma-TFvW kinetic forms: gamma depends on the electron number, which
     defaults to 0, so they all reduce to von Weizsaecker */
  "gga_k_vw gga_k_ludena gga_k_gp85",
  /* HFLYP semilocal part is just LYP correlation */
  "gga_c_lyp hyb_gga_xc_hflyp",
  /* range-separated hybrid = same semilocal + exact exchange */
  "lda_x_erf hyb_lda_x_erf",
  "gga_x_pbe_erf_gws hyb_gga_x_pbe_erf_gws",
  /* VV10 adds a nonlocal correlation term not present in zk */
  "mgga_c_scan mgga_c_scan_rvv10 mgga_c_scan_vv10",
  "mgga_c_scanl mgga_c_scanl_rvv10 mgga_c_scanl_vv10",
  "mgga_c_revscan mgga_c_revscan_vv10",
  "hyb_gga_xc_lc_vv10 hyb_gga_xc_lc_wpbe08_whs",
  /* HSEsol is the HJS-PBEsol screened hybrid under another name */
  "hyb_gga_xc_hjs_pbe_sol hyb_gga_xc_hse_sol",
  /* opB3LYP (Lu 2015) and revB3LYP (Lu 2013) were independently optimized
     to the identical coefficients a0=0.20, ax=0.67, ac=0.84 */
  "hyb_gga_xc_opb3lyp hyb_gga_xc_revb3lyp",
};

/* allow-group index for a name, or -1 if not listed */
static int allow_id(const char *name) {
  size_t i;
  for (i = 0; i < sizeof(allow) / sizeof(allow[0]); i++) {
    const char *p = allow[i];
    size_t n = strlen(name);
    while ((p = strstr(p, name)) != NULL) {
      char before = (p == allow[i]) ? ' ' : p[-1];
      char after = p[n];
      if ((before == ' ') && (after == ' ' || after == '\0'))
        return (int)i;
      p += n;
    }
  }
  return -1;
}

#define MAXF 1024
static int    fid[MAXF];
static char  *fname[MAXF];
static char  *ffp[MAXF];
static int    nf = 0;

static int cmp_fp(const void *a, const void *b) {
  return strcmp(ffp[*(const int *)a], ffp[*(const int *)b]);
}

int main(void) {
  xc_test_no_dialogs();
  int n = xc_number_of_functionals();
  int *list = (int *)malloc(n * sizeof(int));
  xc_available_functional_numbers(list);
  int i;
  for (i = 0; i < n && nf < MAXF; i++) {
    int id = list[i], j, dup = 0;
    for (j = 0; j < nf; j++)
      if (fid[j] == id) { dup = 1; break; }
    if (dup) continue; /* enumeration lists a few ids twice */
    xc_func_type f;
    if (xc_func_init(&f, id, XC_POLARIZED) != 0) continue;
    const xc_func_info_type *info = xc_func_get_info(&f);
    if (!(xc_func_info_get_flags(info) & XC_FLAGS_HAVE_EXC)) { xc_func_end(&f); continue; }
    int fam = xc_func_info_get_family(info), p, known = 1;
    char buf[8192]; int off = 0;
    for (p = 0; p < NP; p++) {
      double rho[2] = {P[p][0], P[p][1]}, sig[3] = {P[p][2], P[p][3], P[p][4]},
             lap[2] = {P[p][5], P[p][6]}, tau[2] = {P[p][7], P[p][8]}, zk = 0;
      if (fam == XC_FAMILY_LDA || fam == XC_FAMILY_HYB_LDA)
        xc_lda_exc(&f, 1, rho, &zk);
      else if (fam == XC_FAMILY_GGA || fam == XC_FAMILY_HYB_GGA)
        xc_gga_exc(&f, 1, rho, sig, &zk);
      else if (fam == XC_FAMILY_MGGA || fam == XC_FAMILY_HYB_MGGA)
        xc_mgga_exc(&f, 1, rho, sig, lap, tau, &zk);
      else { known = 0; break; }
      off += snprintf(buf + off, sizeof(buf) - off,
                      isfinite(zk) ? "%.10e," : "nan,", zk);
    }
    if (known) {
      off += snprintf(buf + off, sizeof(buf) - off, "cam:%.6e,%.6e,%.6e",
                      f.cam_alpha, f.cam_beta, f.cam_omega);
      fid[nf] = id;
      fname[nf] = xc_functional_get_name(id);
      ffp[nf] = (char *)malloc(strlen(buf) + 1);
      strcpy(ffp[nf], buf);
      nf++;
    }
    xc_func_end(&f);
  }
  free(list);

  int *ord = (int *)malloc(nf * sizeof(int));
  for (i = 0; i < nf; i++) ord[i] = i;
  qsort(ord, nf, sizeof(int), cmp_fp);

  int nbad = 0, g0 = 0;
  for (i = 1; i <= nf; i++) {
    if (i < nf && strcmp(ffp[ord[i]], ffp[ord[g0]]) == 0) continue;
    if (i - g0 > 1) { /* a group of identical fingerprints */
      int j, base = allow_id(fname[ord[g0]]), ok = (base >= 0);
      for (j = g0 + 1; j < i; j++)
        if (allow_id(fname[ord[j]]) != base) ok = 0;
      if (!ok) {
        printf("UNEXPECTED identical functionals:");
        for (j = g0; j < i; j++) printf(" %s(%d)", fname[ord[j]], fid[ord[j]]);
        printf("\n");
        nbad++;
      }
    }
    g0 = i;
  }
  printf("distinct-values check: %d functionals, %d unexpected collision group(s)\n",
         nf, nbad);
  return nbad ? 1 : 0;
}
