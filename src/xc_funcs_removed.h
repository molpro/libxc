/*
 Copyright (C) 2016 M. Oliveira

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/* !!! N.B. the data is replicated in the Fortran interface !!! */

/* These are old names kept for compatibility */
#define XC_LDA_C_1D_CSC        18 /* typo; the acronym is CSS not CSC */
#define XC_LDA_X_1D            21 /* The default was soft-Coulomb */
#define XC_GGA_X_BGCP          38
#define XC_GGA_C_BGCP          39 /* renamed to gga_c_acgga by request of authors */
#define XC_GGA_C_BCGP          39 /* This was a misspel */
#define XC_GGA_C_VPBE          83
#define XC_MGGA_X_MK00        230 /* renamed to mgga_x_gp86 for original authors */
#define XC_GGA_K_ABSR1        506
#define XC_GGA_K_ABSR2        507
#define XC_HYB_GGA_XC_BHLYP   436

/* End parsed compatibility section */

/* These were converted to all caps */
#define XC_LDA_C_vBH           17
#define XC_HYB_GGA_XC_B97_1p  266
#define XC_HYB_GGA_XC_mPW1K   405
#define XC_HYB_GGA_XC_mPW1PW  418
#define XC_HYB_GGA_XC_SB98_1a 420
#define XC_HYB_GGA_XC_SB98_1b 421
#define XC_HYB_GGA_XC_SB98_1c 422
#define XC_HYB_GGA_XC_SB98_2a 423
#define XC_HYB_GGA_XC_SB98_2b 424
#define XC_HYB_GGA_XC_SB98_2c 425
#define XC_HYB_GGA_XC_B3LYPs  459
#define XC_GGA_X_PBEpow       539

/* These functionals were misspecified */
#define XC_GGA_XC_LB          160 /* exchange not exchange-correlation */
#define XC_MGGA_C_CC06        229 /* exchange-correlation not correlation */
#define MGGA_X_MS2BS          301 /* functional only in preprint, not in final article; description unclear */
#define MGGA_X_MVSB           302 /* functional only in preprint, not in final article; description unclear */
#define MGGA_X_MVSBS          303 /* functional only in preprint, not in final article; description unclear */
#define XC_LDA_C_LP_A         547 /* exchange-correlation not correlation */
#define XC_LDA_C_LP_B         548 /* exchange-correlation not correlation */
#define XC_MGGA_C_LP90        564 /* exchange-correlation not correlation */

/* These are functionals that were removed for one reason or another */
#define XC_GGA_X_HERMAN        104 /* The real functional is a meta-GGA whose form is not clear */
#define XC_GGA_XC_B97          167 /* Becke 97                                 */
#define XC_GGA_XC_B97_1        168 /* Becke 97-1                               */
#define XC_GGA_XC_B97_2        169 /* Becke 97-2                               */
#define XC_GGA_XC_B97_K        171 /* Boese-Martin for Kinetics                */
#define XC_GGA_XC_B97_3        172 /* Becke 97-3                               */
#define XC_GGA_XC_SB98_1a      176 /* Schmider-Becke 98 parameterization 1a    */
#define XC_GGA_XC_SB98_1b      177 /* Schmider-Becke 98 parameterization 1b    */
#define XC_GGA_XC_SB98_1c      178 /* Schmider-Becke 98 parameterization 1c    */
#define XC_GGA_XC_SB98_2a      179 /* Schmider-Becke 98 parameterization 2a    */
#define XC_GGA_XC_SB98_2b      180 /* Schmider-Becke 98 parameterization 2b    */
#define XC_GGA_XC_SB98_2c      181 /* Schmider-Becke 98 parameterization 2c    */
#define XC_MGGA_X_M05          214 /* Worker for M05 functional                */
#define XC_MGGA_X_M05_2X       215 /* Worker for M05-2X functional             */
#define XC_MGGA_X_M06_HF       216 /* Worker for M06-HF functional             */
#define XC_MGGA_X_M06          217 /* Worker for M06 functional                */
#define XC_MGGA_X_M06_2X       218 /* Worker for M06-2X functional             */
#define XC_MGGA_X_M08_HX       219 /* Worker for M08-HX functional             */
#define XC_MGGA_X_M08_SO       220 /* Worker for M08-SO functional             */
#define XC_MGGA_X_M11          225 /* Worker for M11 functional                */
#define XC_MGGA_X_MN12_SX      228 /* Worker for MN12-SX functional            */
#define XC_GGA_XC_WB97         251 /* Chai and Head-Gordon                     */
#define XC_GGA_XC_WB97X        252 /* Chai and Head-Gordon                     */
#define XC_GGA_XC_WB97X_V      253 /* Mardirossian and Head-Gordon             */
#define XC_GGA_XC_WB97X_D      256 /* Chai and Head-Gordon                     */
#define XC_HYB_GGA_XC_OPB3LYP  454 /* This is literally the same functional as revB3LYP, from the same author, published 2 years later */
#define XC_HYB_MGGA_XC_M08_HX  460 /* M08-HX functional from Minnesota         */
#define XC_HYB_MGGA_XC_M08_SO  461 /* M08-SO functional from Minnesota         */
#define XC_HYB_MGGA_XC_M11     462 /* M11    functional from Minnesota         */
