/*
 Copyright (C) 2006-2007 M.A.L. Marques
 Copyright (C) 2019 X. Andrade

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_LDA_XC_TH_FL        196 /* Tozer and Handy v. FL  */

typedef struct{
  double omega[4];
} lda_xc_th_fl_params;

#define N_PAR 4
static const char  *names[N_PAR] =
  {"_w[0]",  "_w[1]",  "_w[2]",  "_w[3]"};
static const char  *desc[N_PAR]   =
  {"w[0]",  "w[1]",  "w[2]",  "w[3]"};

static const double omega_TH_FL[N_PAR] =
  {-0.106141e01, +0.898203e00, -0.134439e01, +0.302369e00};

static void
lda_xc_th_fl_init(xc_func_type *p)
{
  assert(p->params == NULL);
  p->params = libxc_malloc_flags(sizeof(lda_xc_th_fl_params), p->info->flags);
}

#include "maple2c/lda_exc/lda_xc_th_fl.c"
#include "work_lda.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_xc_th_fl = {
  XC_LDA_XC_TH_FL,
  XC_EXCHANGE_CORRELATION,
  "Tozer and Handy v. FL",
  XC_FAMILY_LDA,
  {&xc_ref_Tozer1998_2545, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, names, desc, omega_TH_FL, set_ext_params_cpy},
  lda_xc_th_fl_init, NULL,
  &work_lda, NULL, NULL
};
