/*
 Copyright (C) 2025 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_MGGA_X_MSCAN          333 /* Modified MSCAN exchange of Desmarais, Erba, Vignale, and Pittalis */

typedef struct{
  double c1, c2, d, k1;
} mgga_x_mscan_params;

#define N_PAR 4
static const char *mscan_names[N_PAR] = {"_c1", "_c2", "_d", "_k1"};
static const char *mscan_desc[N_PAR] = {"c1 parameter", "c2 parameter", "d parameter",
                                            "k1 parameter"};

static const double par_mscan[N_PAR] = {0.667, 0.8, 1.24, 0.065};

static void
mgga_x_mscan_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc_flags(sizeof(mgga_x_mscan_params), p->info->flags);
}

#include "maple2c/mgga_exc/mgga_x_mscan.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_mscan = {
  XC_MGGA_X_MSCAN,
  XC_EXCHANGE,
  "Modified SCAN (mSCAN) exchange of Desmarais, Erba, Vignale, and Pittalis",
  XC_FAMILY_MGGA,
  {&xc_ref_Desmarais2025_106402, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_TAU | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, mscan_names, mscan_desc, par_mscan, set_ext_params_cpy},
  mgga_x_mscan_init, NULL,
  NULL, NULL, &work_mgga
};
