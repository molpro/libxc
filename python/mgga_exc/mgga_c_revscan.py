"""
 Copyright (C) 2017 M.A.L. Marques
               2022 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_c1 = param_default("c1")
params_a_c2 = param_default("c2")
params_a_d = param_default("d")

# revSCAN f_alpha parameters: bake before $include "mgga_c_scan.mpl"
# so the scan helpers see these values, and $define the sentinel
# that suppresses mgga_c_scan's own bake of the SCAN defaults.
params_a_c1 = Float('1.131')
params_a_c2 = Float('1.7')
params_a_d = Float('1.37')
define('_mgga_c_scan_f_alpha_baked')

include('mgga_c_scan')

# Override the SCAN definitions of scan_e0_one_minus_g (eq 1) and
# scan_one_minus_g_infty (eq 2). revSCAN replaces each by a sum of
# two (1 + cX)^(-p) terms, so 1 - g splits into two (-1/2)*expm1
# contributions.

@helper
def scan_e0_one_minus_g(rs, z, t):
    return (
        -(Integer(1)/Integer(2))*xc_expm1(-(Integer(1)/Integer(4))*xc_log1p(Integer(8)*A(rs, z, t)*t**Integer(2)))
        -(Integer(1)/Integer(2))*xc_expm1(-(Integer(1)/Integer(8))*xc_log1p(Integer(80)*A(rs, z, t)**Integer(2)*t**Integer(4)))
    )

@helper
def scan_one_minus_g_infty(s):
    return (
        -(Integer(1)/Integer(2))*xc_expm1(-(Integer(1)/Integer(4))*xc_log1p(Integer(8)*scan_chi_infty*s**Integer(2)))
        -(Integer(1)/Integer(2))*xc_expm1(-(Integer(1)/Integer(8))*xc_log1p(Integer(80)*scan_chi_infty**Integer(2)*s**Integer(4)))
    )

# the new correlation parameters

scan_b1c = Float('0.030197')

scan_b2c = Float('0.06623')

scan_b3c = Float('0.16672')

TYPE = "mgga_exc"
