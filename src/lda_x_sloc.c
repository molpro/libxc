/*
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_LDA_X_SLOC   692   /* simple local model for Slater potential */
#define XC_LDA_X_T_SLOC 337   /* SLOC reparametrization for band gaps */

typedef struct{
  double a;       /* prefactor */
  double b;       /* exponent */
} lda_x_sloc_params;

static void
lda_x_sloc_init(xc_func_type *p)
{
  assert(p != NULL && p->params == NULL);
  p->params = libxc_malloc_flags(sizeof(lda_x_sloc_params), p->info->flags);
}

#include "maple2c/lda_exc/lda_x_sloc.c"
#include "work_lda.c"

static const char  *sloc_names[]  = {"_a", "_b"};
static const char  *sloc_desc[]   = {"Prefactor", "Exponent"};
static const double sloc_values[] = {1.67, 0.3};
static const double sloc_t_values[] = {1.775, 0.260};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_x_sloc = {
  XC_LDA_X_SLOC,
  XC_EXCHANGE,
  "simple local model for Slater potential",
  XC_FAMILY_LDA,
  {&xc_ref_Finzel2017_40, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {2, sloc_names, sloc_desc, sloc_values, set_ext_params_cpy},
  lda_x_sloc_init, NULL,
  &work_lda, NULL, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_x_t_sloc = {
  XC_LDA_X_T_SLOC,
  XC_EXCHANGE,
  "SLOC reparametrization for band gaps",
  XC_FAMILY_LDA,
  {&xc_ref_Borlido2020_96, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {2, sloc_names, sloc_desc, sloc_t_values, set_ext_params_cpy},
  lda_x_sloc_init, NULL,
  &work_lda, NULL, NULL
};
