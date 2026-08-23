"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_tau_hcth_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_tau_hcth_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_cx_local = param_default("cx_local")
params_a_cx_nlocal = param_default("cx_nlocal")

hcth_coeff_a = maple_list([Integer(0), Integer(1), Integer(0), -Integer(2), Integer(0), Integer(1)])

# Equation (29)

hcth_gamX = Float('0.004')

@helper
def hcth_ux(x):
    return b97_u(hcth_gamX, x**Integer(2))

@helper
def hcth_gxl(x):
    return sum((params_a_cx_local [i]*hcth_ux(x)**(i-Integer(1))) for i in range(Integer(1), (Integer(4)) + Integer(1)))

@helper
def hcth_gxnl(x):
    return sum((params_a_cx_nlocal[i]*hcth_ux(x)**(i-Integer(1))) for i in range(Integer(1), (Integer(4)) + Integer(1)))

@helper
def hcth_f(x, u, t):
    return hcth_gxl(x) + hcth_gxnl(x)*mgga_series_w(hcth_coeff_a, Integer(6), t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(hcth_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_tau_hcth_params"
