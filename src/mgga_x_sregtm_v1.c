/*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_MGGA_X_SREGTM_V1  772 /* Simplified regularized Tao-Mo exchange, variant 1 */

#include "maple2c/mgga_exc/mgga_x_sregtm_v1.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_sregtm_v1 = {
  XC_MGGA_X_SREGTM_V1,
  XC_EXCHANGE,
  "Simplified regularized Tao-Mo exchange (v1)",
  XC_FAMILY_MGGA,
  {&xc_ref_Francisco2023_214102, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_NEEDS_TAU | MAPLE2C_FLAGS,
  1e-15,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, NULL, &work_mgga
};
