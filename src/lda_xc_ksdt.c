/*
 Copyright (C) 2014 Orbital-free DFT group at University of Florida, USA

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

/***********************************************************************
  Exchange and correlation free energy density and potential as
  parametrized by
    Valentin V. Karasiev, Travis Sjostrom, James Dufty, and S. B. Trickey
  Ported to C and libxc by Lazaro Calderin and Miguel Marques
************************************************************************/

#define XC_LDA_XC_KSDT     259    /* Karasiev et al. parametrization */
#define XC_LDA_XC_GDSMFB   577    /* Groth et al. parametrization */
#define XC_LDA_XC_CORRKSDT 318    /* Karasiev et al. corrected parametrization */

typedef struct{
  double T;            /* In units of k_B */
  double thetaParam;  /* This takes into account the difference between t and theta_0 */

  double b[2][5], c[2][3], d[2][5],  e[2][5];
} lda_xc_ksdt_params;

static const lda_xc_ksdt_params par_ksdt = {
  0.0,  /* T */
  0.0,  /* thetaParam */
  {     /* b5 = Sqrt[3/2]/(lambda)*b3 */
    {0.2839970,  48.9321540, 0.3709190, 61.0953570, 0.871837422702767684673873513724},
    {0.3290010, 111.5983080, 0.5370530,105.0866630, 1.26233194679913807935662124247}
  }, {  /* c */
    {0.8700890, 0.1930770, 2.4146440},
    {0.8489300, 0.1679520, 0.0888200}
  }, {  /* d */
    {0.5798240,  94.5374540,  97.8396030,  59.9399990, 24.3880370},
    {0.5513300, 180.2131590, 134.4862310, 103.8616950, 17.7507100}
  }, { /* e */
    {0.2120360, 16.7312490, 28.4857920,  34.0288760, 17.2355150},
    {0.1531240, 19.5439450, 43.4003370, 120.2551450, 15.6628360}
  }
};

static const lda_xc_ksdt_params par_corrksdt = {
  0.0,  /* T */
  0.0,  /* thetaParam */
  {     /* b5 = Sqrt[3/2]/(lambda)*b3 */
    {0.342554, 9.141315, 0.448483, 18.553096, 1.05414999729322402165649834296},
    {0.3290010, 111.5983080, 0.5370530,105.0866630, 1.26233194679913807935662124247}
  }, {  /* c */
    {0.875130, -0.256320,  0.953988},
    {0.8489300, 0.1679520, 0.0888200}
  }, {  /* d */
    {0.725917,    2.237347,    0.280748,    4.185911,   0.692183},
    {0.5513300, 180.2131590, 134.4862310, 103.8616950, 17.7507100}
  }, { /* e */
    {0.255415,   0.931933,   0.115398,   17.234117,   0.451437},
    {0.1531240, 19.5439450, 43.4003370, 120.2551450, 15.6628360}
  }
};

/* see https://github.com/agbonitz/xc_functional */
static const lda_xc_ksdt_params par_gdsmfb = {
  0.0 , /* T */
  0.0,  /* thetaParam */
  {     /* b5 = Sqrt[3/2]/(lambda)*b3 */
    {0.34369020, 7.82159531356, 0.300483986662, 15.8443467125, 0.70628138352268528131},
    {0.84987704, 3.04033012073, 0.0775730131248, 7.57703592489, 0.22972614201992673860}
  }, {  /* c */
    {0.87594420, -0.2301308435510, 1.0},
    {0.91126873, -0.0307957123308, 1.0}
  }, {  /* d */
    {0.72700876, 2.38264734144, 0.302212372510, 4.39347718395, 0.729951339845},
    {1.48658718, 4.92684905511, 0.0849387225179, 8.3269821188, 0.218864952126}
  }, { /* e */
    {0.25388214, 0.815795138599, 0.0646844410481, 15.0984620477, 0.230761357474},
    {0.27454097, 0.400994856555, 2.88773194962, 6.33499237092, 24.823008753}
  }
};

static void
lda_xc_ksdt_init(xc_func_type *p)
{
  lda_xc_ksdt_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc(sizeof(lda_xc_ksdt_params));
  params = (lda_xc_ksdt_params *)(p->params);

  switch(p->info->number){
  case XC_LDA_XC_KSDT:
    libxc_memcpy(params, &par_ksdt, sizeof(lda_xc_ksdt_params));
    break;
  case XC_LDA_XC_GDSMFB:
    libxc_memcpy(params, &par_gdsmfb, sizeof(lda_xc_ksdt_params));
    break;
  case XC_LDA_XC_CORRKSDT:
    libxc_memcpy(params, &par_corrksdt, sizeof(lda_xc_ksdt_params));
    break;
  default:
    fprintf(stderr, "Internal error in lda_xc_ksdt\n");
    exit(1);
  }
}

#include "maple2c/lda_exc/lda_xc_ksdt.c"
#include "work_lda.c"

static const char  *T_names[]  = {"T"};
static const char  *T_desc[]   = {"Temperature"};
static const double T_values[] = {0.0};

static void
T_set_ext_params(xc_func_type *p, const double *ext_params)
{
  lda_xc_ksdt_params *params;

  assert(p != NULL && p->params != NULL);
  params = (lda_xc_ksdt_params *) (p->params);

  /* the temperature is in units of k_B */
  params->T = get_ext_param(p, ext_params, 0);
  if(params->T < 1e-8) params->T = 1e-8;
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_xc_ksdt = {
  XC_LDA_XC_KSDT,
  XC_EXCHANGE_CORRELATION,
  "Karasiev, Sjostrom, Dufty & Trickey",
  XC_FAMILY_LDA,
  {&xc_ref_Karasiev2014_076403, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {1, T_names, T_desc, T_values, T_set_ext_params},
  lda_xc_ksdt_init, NULL,
  &work_lda, NULL, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_xc_gdsmfb = {
  XC_LDA_XC_GDSMFB,
  XC_EXCHANGE_CORRELATION,
  "Groth, Dornheim, Sjostrom, Malone, Foulkes, Bonitz",
  XC_FAMILY_LDA,
  {&xc_ref_Groth2017_135001, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {1, T_names, T_desc, T_values, T_set_ext_params},
  lda_xc_ksdt_init, NULL,
  &work_lda, NULL, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_lda_xc_corrksdt = {
  XC_LDA_XC_CORRKSDT,
  XC_EXCHANGE_CORRELATION,
  "Corrected KSDT by Karasiev, Dufty and Trickey",
  XC_FAMILY_LDA,
  {&xc_ref_Karasiev2018_076401, &xc_ref_Karasiev2014_076403, &xc_ref_lda_xc_corrksdt_note, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {1, T_names, T_desc, T_values, T_set_ext_params},
  lda_xc_ksdt_init, NULL,
  &work_lda, NULL, NULL
};
