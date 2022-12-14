/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_GGA_X_Q1D         734 /* Functional for quasi-1D systems  */

#include "maple2c/gga_exc/gga_x_q1d.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_q1d = {
  XC_GGA_X_Q1D,
  XC_EXCHANGE,
  "Functional for quasi-1D systems",
  XC_FAMILY_GGA,
  {&xc_ref_Urso2021_1, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, &work_gga, NULL
};
