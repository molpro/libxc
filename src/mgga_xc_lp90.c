/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_MGGA_XC_LP90          564 /* Lee & Parr, Eq. (60) */

#define N_PAR 3
static const char  *names[N_PAR]  = {"_c0", "_d0", "_k"};
static const char  *desc[N_PAR]   = {
  "Coefficient of first term in eq. 60",
  "Coefficient of second term in eq. 60",
  "Kappa coefficient in denominators"
};

static const double lp90_values[N_PAR] =
  {0.80569, 2.4271e-2, 4.0743e-3};

typedef struct{
  double c0, d0, k;
} mgga_xc_lp90_params;

static void
mgga_xc_lp90_init(xc_func_type *p)
{
  mgga_xc_lp90_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc_flags(sizeof(mgga_xc_lp90_params), p->info->flags);
  params = (mgga_xc_lp90_params *) (p->params);
}

#include "maple2c/mgga_exc/mgga_xc_lp90.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_xc_lp90 = {
  XC_MGGA_XC_LP90,
  XC_EXCHANGE_CORRELATION,
  "Lee & Parr, Eq. (60)",
  XC_FAMILY_MGGA,
  {&xc_ref_Lee1990_193, &xc_ref_Zhao1993_918, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_LAPLACIAN | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, names, desc, lp90_values, set_ext_params_cpy},
  mgga_xc_lp90_init, NULL,
  NULL, NULL, &work_mgga,
};
