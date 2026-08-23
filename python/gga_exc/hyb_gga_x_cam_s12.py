"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   hyb_gga_x_cam_s12_params *params;
#
#   assert(p->params != NULL);
#   params = (hyb_gga_x_cam_s12_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

include('gga_x_s12')
include('gga_x_ityh')

# use the bx-free body of s12g_f directly (see gga_x_s12.mpl)

@helper
def ityh_enhancement(xs):
    return s12g_f_inner(xs)

# Algebraic identity:
# 1 - alpha - beta*att_erf = (1 - alpha - beta) + beta*(1 - att_erf).
# At high density (small attenuation argument) att_erf -> 1 and
# the direct form computes 1 - alpha - beta*close-to-1, which
# cancels down to beta*epsilon when alpha + beta = 1.  Routing
# through ityh_one_minus_f_aa removes that cancellation.

@helper
def cam_s12_f(rs, z, xs):
    return (
        ityh_enhancement(xs) *
        ((Integer(1) - p_a_cam_alpha - p_a_cam_beta)
        + p_a_cam_beta*ityh_one_minus_f_aa(rs, z, xs))
    )

def f(rs, z, xt, xs0, xs1):
    return gga_exchange_nsp(cam_s12_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "hyb_gga_x_cam_s12_params"
