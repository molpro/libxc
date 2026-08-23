"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_n12_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_n12_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_CC_0_ = param_default("CC_0_")
params_a_CC_1_ = param_default("CC_1_")
params_a_CC_2_ = param_default("CC_2_")
params_a_CC_3_ = param_default("CC_3_")

n12_omega_x = Float('2.5')

n12_gamma_x = Float('0.004')

@helper
def n12_rss(rs, z):
    return rs * Integer(2)**(Integer(1)/Integer(3)) * opz_pow_n(z,-Integer(1)/Integer(3))

@helper
def n12_vx(rs):
    return Integer(1)/(Integer(1) + (Integer(1)/(RS_FACTOR*n12_omega_x))*rs)

@helper
def n12_ux(x):
    return b97_u(n12_gamma_x, x**Integer(2))

@helper
def n12_FN12(rs, z, x):
    return (
        + sum((params_a_CC_0_[i+Integer(1)]*n12_ux(x)**i) for i in range(Integer(0), (Integer(3)) + Integer(1)))
        + sum((params_a_CC_1_[i+Integer(1)]*n12_ux(x)**i) for i in range(Integer(0), (Integer(3)) + Integer(1))) * n12_vx(n12_rss(rs, z))
        + sum((params_a_CC_2_[i+Integer(1)]*n12_ux(x)**i) for i in range(Integer(0), (Integer(3)) + Integer(1))) * n12_vx(n12_rss(rs, z))**Integer(2)
        + sum((params_a_CC_3_[i+Integer(1)]*n12_ux(x)**i) for i in range(Integer(0), (Integer(3)) + Integer(1))) * n12_vx(n12_rss(rs, z))**Integer(3)
    )

def f(rs, z, xt, xs0, xs1):
    return gga_exchange_nsp(n12_FN12, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_n12_params"
