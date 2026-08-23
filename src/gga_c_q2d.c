/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_GGA_C_Q2D          47 /* Chiodo et al  */

#include "maple2c/gga_exc/gga_c_q2d.c"
#include "work_gga.c"

/* q2d evaluates the 2D-AMGB correlation at rs2D ~ 1/rho, so its
   derivatives form a 1/rho^32 intermediate that overflows once rho^32
   drops below DBL_MIN (0*inf = NaN where the small-gradient weight
   q2d_fac -> 0).  Floor the density at the overflow boundary
   DBL_MIN^(1/32) with a safety factor.  Computed here in the constructor,
   not as a struct literal, so it tracks the floating-point range -- a
   const initializer cannot call pow(). */
static void
gga_c_q2d_init(xc_func_type *p)
{
  p->dens_threshold  = 2.0 * pow(DBL_MIN, 1.0/32.0);
  p->sigma_threshold = pow(p->dens_threshold, 4.0/3.0);
}

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_c_q2d = {
  XC_GGA_C_Q2D,
  XC_CORRELATION,
  "Chiodo et al",
  XC_FAMILY_GGA,
  {&xc_ref_Chiodo2012_126402, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  0.0, /* dens_threshold is set precision-relatively in gga_c_q2d_init */
  {0, NULL, NULL, NULL, NULL},
  gga_c_q2d_init, NULL,
  NULL, &work_gga, NULL
};

