/*
 Copyright (C) 2015 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_MGGA_X_SA_TPSS          542 /* TPSS with correct surface asymptotics */

#include "maple2c/mgga_exc/mgga_x_sa_tpss.c"
#include "work_mgga.c"

#ifdef __cplusplus
extern "C"
#endif
const xc_func_info_type xc_func_info_mgga_x_sa_tpss = {
  XC_MGGA_X_SA_TPSS,
  XC_EXCHANGE,
  "TPSS with correct surface asymptotics",
  XC_FAMILY_MGGA,
  {&xc_ref_Constantin2016_115127, NULL, NULL, NULL, NULL},
  /* The kappa of this functional, sqrt(alpha+1)/sqrt(a+log(alpha+b)),
     is real only for the iso-orbital indicator alpha >= 0, i.e. when the
     Fermi-hole curvature 1 - xs^2/(8 ts) is non-negative.  Enforce it so
     that unphysical inputs with sigma > 8 rho tau (which would drive
     alpha below the sqrt/log domain and produce NaNs) are clamped to the
     physical boundary; physical densities satisfy alpha >= 0 and are
     unaffected. */
  XC_FLAGS_3D | XC_FLAGS_NEEDS_TAU | XC_FLAGS_ENFORCE_FHC | MAPLE2C_FLAGS,
  1e-15,
  {0, NULL, NULL, NULL, NULL},
  NULL, NULL,
  NULL, NULL, &work_mgga,
};
