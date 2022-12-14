/*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_MGGA_K_GEA4      628 /* Fourth-order gradient expansion */

#include "maple2c/mgga_exc/mgga_k_gea4.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_k_gea4 = {
  XC_MGGA_K_GEA4,
  XC_KINETIC,
  "Fourth-order gradient expansion",
  XC_FAMILY_MGGA,
  {&xc_ref_Hodges1973_1428, NULL, NULL, NULL, NULL},
  XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_3D | MAPLE2C_FLAGS,
  1e-15,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, NULL, &work_mgga
};
