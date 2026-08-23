/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_GGA_K_GDS08     591 /* Combined analytical theory with Monte Carlo sampling */
#define XC_GGA_K_GHDS10    592 /* As GDS08 but for an electron gas with spin */
#define XC_GGA_K_GHDS10R   593 /* Reparametrized GHDS10 */
#define XC_GGA_K_TKVLN     594 /* Trickey, Karasiev, and Vela */

typedef struct {
  double lambda, gamma;         /* TF-lambda-vW base */
  double A, B, C;               /* Ghiringhelli-Delle Site LDA correction */
} gga_k_gds08_params;

#define N_PAR 5
static const char *names[N_PAR] = {"_lambda", "_gamma", "_A", "_B", "_C"};
static const char *desc[N_PAR]  = {
  "TF-lambda-vW lambda coefficient",
  "TF-lambda-vW gamma coefficient",
  "linear term",
  "term proportional to the logarithm of the density",
  "term proportional to the square of the logarithm of the density"
};

static const double par_gds08[N_PAR]   = {1.0, 0.0, 0.860,      0.224,      0.0};
static const double par_ghds10[N_PAR]  = {1.0, 1.0, 1.02,       0.163,      0.0};
static const double par_ghds10r[N_PAR] = {1.0, 1.0, 0.61434e-1, 0.61317e-2, 0.0};
static const double par_tkvln[N_PAR]   = {1.0, 1.0, 0.45960e-1, 0.65545e-2, 0.23131e-3};

static void
gga_k_gds08_init(xc_func_type *p)
{
  assert(p!=NULL && p->params == NULL);
  p->params = libxc_malloc_flags(sizeof(gga_k_gds08_params), p->info->flags);
}

#include "maple2c/gga_exc/gga_k_gds08.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_k_gds08 = {
  XC_GGA_K_GDS08,
  XC_KINETIC,
  "Combined analytical theory with Monte Carlo sampling",
  XC_FAMILY_GGA,
  {&xc_ref_Ghiringhelli2008_073104, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, names, desc, par_gds08, set_ext_params_cpy},
  gga_k_gds08_init, NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_k_ghds10 = {
  XC_GGA_K_GHDS10,
  XC_KINETIC,
  "As GDS08 but for an electron gas with spin",
  XC_FAMILY_GGA,
  {&xc_ref_Ghiringhelli2010_014106, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, names, desc, par_ghds10, set_ext_params_cpy},
  gga_k_gds08_init, NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_k_ghds10r = {
  XC_GGA_K_GHDS10R,
  XC_KINETIC,
  "Reparametrized GHDS10",
  XC_FAMILY_GGA,
  {&xc_ref_Trickey2011_075146, &xc_ref_Ghiringhelli2010_014106, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, names, desc, par_ghds10r, set_ext_params_cpy},
  gga_k_gds08_init, NULL,
  NULL, &work_gga, NULL
};

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_k_tkvln = {
  XC_GGA_K_TKVLN,
  XC_KINETIC,
  "Trickey, Karasiev, and Vela",
  XC_FAMILY_GGA,
  {&xc_ref_Trickey2011_075146, &xc_ref_Ghiringhelli2010_014106, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {N_PAR, names, desc, par_tkvln, set_ext_params_cpy},
  gga_k_gds08_init, NULL,
  NULL, &work_gga, NULL
};
