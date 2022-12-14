/*
 Copyright (C) 2006-2009 J.I.J. Ojajarvi

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_MGGA_X_2D_PRHG07_PRP10   211   /* PRGH07 with PRP10 correction */

#define XC_NO_EXC
#include "maple2c/mgga_vxc/mgga_x_2d_prp10.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_2d_prhg07_prp10 = {
  XC_MGGA_X_2D_PRHG07_PRP10,
  XC_EXCHANGE,
  "PRHG07 with Pittalis-Rasanen-Proetto 2010 correction",
  XC_FAMILY_MGGA,
  {&xc_ref_Pittalis2007_235314, &xc_ref_Pittalis2010_115108, NULL, NULL, NULL},
  XC_FLAGS_DEVELOPMENT | XC_FLAGS_2D | XC_FLAGS_NEEDS_LAPLACIAN | MAPLE2C_FLAGS,
  1.0e-23,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, NULL, &work_mgga,
};

