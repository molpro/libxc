/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_GGA_X_C09X         158 /* C09x to be used with the VdW of Rutgers-Chalmers     */

#include "maple2c/gga_exc/gga_x_c09x.c"
#include "work_gga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_gga_x_c09x = {
  XC_GGA_X_C09X,
  XC_EXCHANGE,
  "C09x to be used with the VdW of Rutgers-Chalmers",
  XC_FAMILY_GGA,
  {&xc_ref_Cooper2010_161104, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, &work_gga, NULL
};
