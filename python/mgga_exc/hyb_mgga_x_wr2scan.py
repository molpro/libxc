"""
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_wr2scan_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_wr2scan_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

include('mgga_x_r2scan')
include('lda_x_erf')

# Lukas Wittmann confirmed that the factor 1-ax is missing in the supporting information; the fraction of short-range exact exchange is alpha*HF + beta*srHF so we include 1-alpha-beta here

@helper
def wr2scan_f(rs, z, x, u, t):
    return (Float('1.0')-p_a_cam_alpha-p_a_cam_beta)*attenuation_erf(a_cnst*rs/opz_pow_n(z,Integer(1)/Integer(3))) * r2scan_f(x, u, t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange_nsp(wr2scan_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_wr2scan_params"
