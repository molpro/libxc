/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_GGA_X_2D_B88        127 /* Becke 88 in 2D */

#include "maple2c/gga_exc/gga_x_2d_b88.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_2d_b88 = {
  XC_GGA_X_2D_B88,
  XC_EXCHANGE,
  "Becke 88 in 2D",
  XC_FAMILY_GGA,
  {&xc_ref_Vilhena2014, NULL, NULL, NULL, NULL},
  XC_FLAGS_2D | MAPLE2C_FLAGS,
  1e-15,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, &work_gga, NULL
};
