"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_mvs_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_mvs_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_e1 = param_default("e1")
params_a_c1 = param_default("c1")
params_a_k0 = param_default("k0")
params_a_b = param_default("b")

# equation 10

@helper
def mvs_fa(a):
    return (Integer(1) - a) / ((Integer(1) + params_a_e1*a**Integer(2))**Integer(2) + params_a_c1*a**Integer(4))**(Integer(1)/Integer(4))

# eq 7; alpha is the shared mgga_alpha

@helper
def mvs_f(x, u, t):
    return (
        (Integer(1) + params_a_k0*mvs_fa(mgga_alpha(x,t)))
        / (Integer(1) + params_a_b*(gga_s(x))**Integer(4))**(Integer(1)/Integer(8))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(mvs_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_mvs_params"
