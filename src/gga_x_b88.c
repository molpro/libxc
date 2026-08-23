/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_GGA_X_B88          106 /* Becke 88 */
#define XC_GGA_X_OPTB88_VDW   139 /* Becke 88 reoptimized to be used with vdW functional of Dion et al */
#define XC_GGA_X_MB88         149 /* Modified Becke 88 for proton transfer */
#define XC_GGA_X_EB88         271 /* Non-empirical (excogitated) B88 functional of Becke and Elliott */
#define XC_GGA_X_LLP          350 /* Lee, Lee & Parr reparametrization of B88 */
#define XC_GGA_X_B88M         570 /* Becke 88 reoptimized to be used with mgga_c_tau1 */
#define XC_GGA_X_B88_6311G    179 /* Becke 88 reoptimized with 6-311G** basis set */
#define XC_GGA_X_DF3_OPT1     346 /* Becke 88 reoptimized by Chakraborty et al for use with vdW functional */

typedef struct{
  double beta, gamma;
} gga_x_b88_params;


static void
gga_x_b88_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc_flags(sizeof(gga_x_b88_params), p->info->flags);
}

#define B88_N_PAR 2
static const char  *b88_names[B88_N_PAR]  = {"_beta", "_gamma"};
static const char  *b88_desc[B88_N_PAR]   = {
  "beta/X_FACTOR_C is the coefficient of the gradient expansion",
  "gamma should be 6 to get the right asymptotics of Ex"};
static const double b88_values[B88_N_PAR] =
  {0.0042, 6.0};
static const double b88_optb88_values[B88_N_PAR] =
  {0.00336865923905927, 6.98131700797731};
static const double b88_mb88_values[B88_N_PAR] =
  {0.0011, 6.0};
static const double b88_eb88_values[B88_N_PAR] =
  {0.0039685026299204986870L, 6.0}; /* 0.0050/M_CBRT2 */
static const double b88_llp_values[B88_N_PAR] =
  {X_FACTOR_C*0.0043952, 0.0253/(X_FACTOR_C*0.0043952)};
static const double b88_b88m_values[B88_N_PAR] =
  {0.0045, 6.0};
static const double b88_6311g_values[B88_N_PAR] =
  {0.0051, 6.0};
static const double b88_df3_opt1_values[B88_N_PAR] =
  {MU_GE*X_FACTOR_C*X2S*X2S, 1.0/(1.10*X_FACTOR_C*X2S)};

#include "maple2c/gga_exc/gga_x_b88.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_b88 = {
  XC_GGA_X_B88,
  XC_EXCHANGE,
  "Becke 88",
  XC_FAMILY_GGA,
  {&xc_ref_Becke1988_3098, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {B88_N_PAR, b88_names, b88_desc, b88_values, set_ext_params_cpy},
  gga_x_b88_init, NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_optb88_vdw = {
  XC_GGA_X_OPTB88_VDW,
  XC_EXCHANGE,
  "opt-Becke 88 for vdW",
  XC_FAMILY_GGA,
  {&xc_ref_Klimes2010_022201, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {B88_N_PAR, b88_names, b88_desc, b88_optb88_values, set_ext_params_cpy},
  gga_x_b88_init, NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_mb88 = {
  XC_GGA_X_MB88,
  XC_EXCHANGE,
  "Modified Becke 88 for proton transfer",
  XC_FAMILY_GGA,
  {&xc_ref_Tognetti2009_14415, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {B88_N_PAR, b88_names, b88_desc, b88_mb88_values, set_ext_params_cpy},
  gga_x_b88_init, NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_eb88 = {
  XC_GGA_X_EB88,
  XC_EXCHANGE,
  "Non-empirical (excogitated) B88 functional of Becke and Elliott",
  XC_FAMILY_GGA,
  {&xc_ref_Elliott2009_1485, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {B88_N_PAR, b88_names, b88_desc, b88_eb88_values, set_ext_params_cpy},
  gga_x_b88_init,  NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_llp = {
  XC_GGA_X_LLP,
  XC_EXCHANGE,
  "Lee, Lee & Parr reparametrization of B88",
  XC_FAMILY_GGA,
  {&xc_ref_Lee1991_768, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {B88_N_PAR, b88_names, b88_desc, b88_llp_values, set_ext_params_cpy},
  gga_x_b88_init,  NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_b88m = {
  XC_GGA_X_B88M,
  XC_EXCHANGE,
  "Becke 88 reoptimized to be used with tau1",
  XC_FAMILY_GGA,
  {&xc_ref_Proynov2000_10013, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {B88_N_PAR, b88_names, b88_desc, b88_b88m_values, set_ext_params_cpy},
  gga_x_b88_init,  NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_b88_6311g = {
  XC_GGA_X_B88_6311G,
  XC_EXCHANGE,
  "Becke 88 reoptimized with the 6-311G** basis set",
  XC_FAMILY_GGA,
  {&xc_ref_Ugalde1994_423, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {B88_N_PAR, b88_names, b88_desc, b88_6311g_values, set_ext_params_cpy},
  gga_x_b88_init,  NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_df3_opt1 = {
  XC_GGA_X_DF3_OPT1,
  XC_EXCHANGE,
  "Becke 88 reoptimized by Chakraborty et al for use with vdW functional",
  XC_FAMILY_GGA,
  {&xc_ref_Chakraborty2020_5893, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {B88_N_PAR, b88_names, b88_desc, b88_df3_opt1_values, set_ext_params_cpy},
  gga_x_b88_init,  NULL,
  NULL, &work_gga, NULL
};
