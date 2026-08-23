/*
 Copyright (C) 2019 Daniel Mejia-Rodriguez
               2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "xc_funcs.h"

#define XC_MGGA_X_SCANL         700 /* Deorbitalized SCAN exchange */
#define XC_MGGA_X_REVSCANL      701 /* Deorbitalized revSCAN exchange */

/* The deorbitalization is performed symbolically in
   maple/mgga_exc/mgga_x_scanl.mpl: SCAN's iso-orbital indicator is taken
   straight from PC07 instead of being assembled from a kinetic energy density
   at run time.  Both parents' parameters therefore live in one struct. */
typedef struct{
  double c1, c2, d, k1;   /* SCAN */
  double pc07_a, pc07_b;  /* PC07 */
} mgga_x_scanl_params;

#define N_PAR 6
static const char *names[N_PAR] = {
  "_c1", "_c2", "_d", "_k1", /* parameters of scan */
  "_a", "_b"                 /* parameters of pc07 */
};
static const char *desc[N_PAR] = {
  "scan c1", "scan c2", "scan d", "scan k1",
  "pc07 a", "pc07 b"
};

static const double par_scanl[N_PAR] = {
  0.667, 0.8, 1.24, 0.065,
  1.784720, 0.258304
};
static const double par_revscanl[N_PAR] = {
  0.607, 0.7, 1.37, 0.065,
  1.784720, 0.258304
};

static void
mgga_x_scanl_init(xc_func_type *p)
{
  assert(p != NULL && p->params == NULL);
  p->params = libxc_malloc_flags(sizeof(mgga_x_scanl_params), p->info->flags);
}

#include "maple2c/mgga_exc/mgga_x_scanl.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_scanl = {
  XC_MGGA_X_SCANL,
  XC_EXCHANGE,
  "Deorbitalized SCAN (SCAN-L) exchange",
  XC_FAMILY_MGGA,
  {&xc_ref_Mejia2017_052512, &xc_ref_Mejia2018_115161, &xc_ref_Sun2015_036402, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_scanl, set_ext_params_cpy},
  mgga_x_scanl_init, NULL,
  NULL, NULL, &work_mgga
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_revscanl = {
  XC_MGGA_X_REVSCANL,
  XC_EXCHANGE,
  "Deorbitalized revised SCAN (revSCAN-L) exchange",
  XC_FAMILY_MGGA,
  {&xc_ref_Mejia2017_052512, &xc_ref_Mejia2018_115161, &xc_ref_Mezei2018_2469, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_revscanl, set_ext_params_cpy},
  mgga_x_scanl_init, NULL,
  NULL, NULL, &work_mgga
};
