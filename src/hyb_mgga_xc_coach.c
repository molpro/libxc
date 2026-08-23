/*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_HYB_MGGA_XC_COACH   771 /* Liang and Head-Gordon */

static void
hyb_mgga_xc_coach_init(xc_func_type *p)
{
  /* The 73 semi-local expansion coefficients are baked into the
     generated code at their trained values, so the trained
     range-separation / Hartree-Fock mixing parameters are likewise
     fixed here rather than exposed as external parameters:
       c_x,lr = cam_alpha = 1,
       c_x,sr = cam_alpha + cam_beta = 0.22878980716640696,
       omega  = cam_omega = 0.27.
     The two-body VV10 dispersion is handled by libxc; the three-body
     D4-ATM correction is an external dispersion term. */
  xc_hyb_init_cam(p, 1.0, -0.77121019283359304, 0.27);

  p->nlc_b = 5.5;
  p->nlc_C = 0.01;
}

#include "maple2c/mgga_exc/hyb_mgga_xc_coach.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_hyb_mgga_xc_coach = {
  XC_HYB_MGGA_XC_COACH,
  XC_EXCHANGE_CORRELATION,
  "COACH exchange-correlation functional",
  XC_FAMILY_HYB_MGGA,
  {&xc_ref_Liang2026, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HYB_CAM | XC_FLAGS_NEEDS_TAU | XC_FLAGS_VV10 | MAPLE2C_FLAGS,
  1e-13,
  {0, NULL, NULL, NULL, NULL},
  hyb_mgga_xc_coach_init, NULL,
  NULL, NULL, &work_mgga,
};
