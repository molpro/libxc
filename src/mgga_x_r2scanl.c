/*
 Copyright (C) 2019 Daniel Mejia-Rodriguez
               2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "xc_funcs.h"

#define XC_MGGA_X_R2SCANL       718 /* Deorbitalized r^2SCAN exchange */

/* The deorbitalization is performed symbolically in
   maple/mgga_exc/mgga_x_r2scanl.mpl: r2SCAN's iso-orbital indicator is taken
   from PC07 rather than assembled from a kinetic energy density at run time.
   Both parents' parameters therefore live in one struct. */
typedef struct{
  double c1, c2, d, k1;   /* r2SCAN */
  double eta, dp2;
  double pc07_a, pc07_b;  /* PC07 */
} mgga_x_r2scanl_params;

#define N_PAR 8
static const char *names[N_PAR] = {"_c1", "_c2", "_d", "_k1", "_eta", "_dp2", "_a", "_b"};
static const char *desc[N_PAR] = {"c1 parameter", "c2 parameter", "d parameter",
  "k1 parameter", "eta parameter", "dp2 parameter", "a parameter", "b parameter"};

static const double par_r2scanl[N_PAR] = {0.667, 0.8, 1.24, 0.065, 0.001, 0.361, 1.784720, 0.258304};

static void
mgga_x_r2scanl_init(xc_func_type *p)
{
  assert(p != NULL && p->params == NULL);
  p->params = libxc_malloc_flags(sizeof(mgga_x_r2scanl_params), p->info->flags);
}

#include "maple2c/mgga_exc/mgga_x_r2scanl.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_r2scanl = {
  XC_MGGA_X_R2SCANL,
  XC_EXCHANGE,
  "Deorbitalized re-regularized SCAN (r2SCAN-L) exchange",
  XC_FAMILY_MGGA,
  {&xc_ref_Mejia2020_121109, &xc_ref_Furness2020_8208, &xc_ref_Furness2020_9248, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_r2scanl, set_ext_params_cpy},
  mgga_x_r2scanl_init, NULL,
  NULL, NULL, &work_mgga
};

