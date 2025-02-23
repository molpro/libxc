/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "xc_funcs.h"

#define XC_HYB_GGA_XC_B1WC      412  /* Becke 1-parameter mixture of WC and PBE          */
#define XC_HYB_GGA_XC_B1LYP     416  /* Becke 1-parameter mixture of B88 and LYP         */
#define XC_HYB_GGA_XC_B1PW91    417  /* Becke 1-parameter mixture of B88 and PW91        */
#define XC_HYB_GGA_XC_MPW1LYP   483  /* Becke 1-parameter mixture of mPW91 and LYP       */
#define XC_HYB_GGA_XC_MPW1PBE   484  /* Becke 1-parameter mixture of mPW91 and PBE       */
#define XC_HYB_GGA_XC_MPW1PW    418  /* Becke 1-parameter mixture of mPW91 and PW91      */
#define XC_HYB_GGA_XC_MPW1K     405  /* mixture of mPW91 and PW91 optimized for kinetics */
#define XC_HYB_GGA_XC_BHANDH    435  /* Becke half-and-half or BHLYP                     */
#define XC_HYB_GGA_XC_BHANDHLYP 436  /* Becke half-and-half with B88 exchange            */
#define XC_HYB_GGA_XC_MPWLYP1M  453  /* MPW with 1 par. for metals/LYP                   */
#define XC_HYB_GGA_XC_BLYP35    499  /* Becke 1-parameter mixture for mixed-valence systems */

#define N_PAR 1
static const char  *names[N_PAR] = {"_cx"};
static const char  *desc[N_PAR]  = {
  "Fraction of exact exchange"
};

static void
set_ext_params(xc_func_type *p, const double *ext_params)
{
  double cx;

  assert(p != NULL);

  cx = get_ext_param(p, ext_params, 0);

  p->mix_coef[0] = 1-cx;

  p->cam_alpha = cx;
  p->cam_omega = 0.0;
}

static const double par_b1wc[N_PAR] = {0.16};
static const double par_quarter[N_PAR] = {0.25};
static const double par_mpw1k[N_PAR] = {0.428};
static const double par_half[N_PAR] = {0.50};
static const double par_b35[N_PAR] = {0.35};
static const double par_mpwlyp1m[N_PAR] = {0.05};

void
xc_hyb_gga_xc_b1wc_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_WC, XC_GGA_C_PBE};
  static double funcs_coef[2] = {1.0, 1.0};

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_b1wc = {
  XC_HYB_GGA_XC_B1WC,
  XC_EXCHANGE_CORRELATION,
  "B1WC",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Bilc2008_165107, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_b1wc, set_ext_params},
  xc_hyb_gga_xc_b1wc_init,
  NULL, NULL, NULL, NULL
};


void
xc_hyb_gga_xc_b1lyp_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_B88, XC_GGA_C_LYP};
  static double funcs_coef[2] = {1.0, 1.0};

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_b1lyp = {
  XC_HYB_GGA_XC_B1LYP,
  XC_EXCHANGE_CORRELATION,
  "B1LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Adamo1997_242, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_quarter, set_ext_params},
  xc_hyb_gga_xc_b1lyp_init,
  NULL, NULL, NULL, NULL
};

void
xc_hyb_gga_xc_b1pw91_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_B88, XC_GGA_C_PW91};
  static double funcs_coef[2] = {1.0, 1.0};

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_b1pw91 = {
  XC_HYB_GGA_XC_B1PW91,
  XC_EXCHANGE_CORRELATION,
  "B1PW91",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Adamo1997_242, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_quarter, set_ext_params},
  xc_hyb_gga_xc_b1pw91_init,
  NULL, NULL, NULL, NULL
};


void
xc_hyb_gga_xc_mpw1pw_init(xc_func_type *p)
{
  int   funcs_id  [2] = {XC_GGA_X_MPW91, 0};
  double funcs_coef[2] = {1.0, 1.0};

  switch(p->info->number) {
  case(XC_HYB_GGA_XC_MPW1LYP):
    funcs_id[1]=XC_GGA_C_LYP;
    break;
  case(XC_HYB_GGA_XC_MPW1PBE):
    funcs_id[1]=XC_GGA_C_PBE;
    break;
  case(XC_HYB_GGA_XC_MPW1PW):
    funcs_id[1]=XC_GGA_C_PW91;
    break;
  default:
    fprintf(stderr,"Error in hyb_gga_xc_mpw1pw_init\n");
    fflush(stderr);
    exit(1);
  }

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_mpw1lyp = {
  XC_HYB_GGA_XC_MPW1LYP,
  XC_EXCHANGE_CORRELATION,
  "mPW1LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Adamo1998_664, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_quarter, set_ext_params},
  xc_hyb_gga_xc_mpw1pw_init,
  NULL, NULL, NULL, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_mpw1pbe = {
  XC_HYB_GGA_XC_MPW1PBE,
  XC_EXCHANGE_CORRELATION,
  "mPW1PBE",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Adamo1998_664, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_quarter, set_ext_params},
  xc_hyb_gga_xc_mpw1pw_init,
  NULL, NULL, NULL, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_mpw1pw = {
  XC_HYB_GGA_XC_MPW1PW,
  XC_EXCHANGE_CORRELATION,
  "mPW1PW",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Adamo1998_664, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_quarter, set_ext_params},
  xc_hyb_gga_xc_mpw1pw_init,
  NULL, NULL, NULL, NULL
};


void
xc_hyb_gga_xc_mpw1k_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_MPW91, XC_GGA_C_PW91};
  static double funcs_coef[2] = {1.0, 1.0};

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_mpw1k = {
  XC_HYB_GGA_XC_MPW1K,
  XC_EXCHANGE_CORRELATION,
  "mPW1K",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Lynch2000_4811, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_mpw1k, set_ext_params},
  xc_hyb_gga_xc_mpw1k_init,
  NULL, NULL, NULL, NULL
};


void
xc_hyb_gga_xc_bhandh_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_LDA_X, XC_GGA_C_LYP};
  static double funcs_coef[2] = {1.0, 1.0};

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_bhandh = {
  XC_HYB_GGA_XC_BHANDH,
  XC_EXCHANGE_CORRELATION,
  "BHandH i.e. BHLYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Becke1993_1372, &xc_ref_gaussianimplementation, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_half, set_ext_params},
  xc_hyb_gga_xc_bhandh_init,
  NULL, NULL, NULL, NULL
};


void
xc_hyb_gga_xc_bhandhlyp_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_B88, XC_GGA_C_LYP};
  static double funcs_coef[2] = {1.0, 1.0};

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_bhandhlyp = {
  XC_HYB_GGA_XC_BHANDHLYP,
  XC_EXCHANGE_CORRELATION,
  "BHandHLYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Becke1993_1372, &xc_ref_gaussianimplementation, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_half, set_ext_params},
  xc_hyb_gga_xc_bhandhlyp_init,
  NULL, NULL, NULL, NULL
};


void
xc_hyb_gga_xc_blyp35_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_B88, XC_GGA_C_LYP};
  static double funcs_coef[2] = {1.0, 1.0};

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_blyp35 = {
  XC_HYB_GGA_XC_BLYP35,
  XC_EXCHANGE_CORRELATION,
  "BLYP35",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Renz2009_16292, &xc_ref_Kaupp2011_16973, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_b35, set_ext_params},
  xc_hyb_gga_xc_blyp35_init,
  NULL, NULL, NULL, NULL
};


void
xc_hyb_gga_xc_mpwlyp1m_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_MPW91, XC_GGA_C_LYP};
  static double funcs_coef[2] = {1.0, 1.0};

  xc_mix_init(p, 2, funcs_id, funcs_coef);
  xc_hyb_init_hybrid(p, 0.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_gga_xc_mpwlyp1m = {
  XC_HYB_GGA_XC_MPWLYP1M,
  XC_EXCHANGE_CORRELATION,
  "MPW with 1 par. for metals/LYP",
  XC_FAMILY_HYB_GGA,
  {&xc_ref_Schultz2005_11127, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-15,
  {N_PAR, names, desc, par_mpwlyp1m, set_ext_params},
  xc_hyb_gga_xc_mpwlyp1m_init,
  NULL, NULL, NULL, NULL
};
