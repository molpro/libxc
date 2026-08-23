"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_m06l_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_m06l_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_d = param_default("d")
params_a_a = param_default("a")

define('gga_x_pbe_params')
include('gga_x_pbe')
include('gvt4')

m06_alpha = Float('0.00186726')

m06_coeff_d = params_a_d

# there is a factor if 2 in the definition of z, as in Theor. Chem. Account 120, 215 (2008)

# A MINUS was missing in Eq. (7) of the paper

@helper
def m06_f(x, u, t):
    return (
        + pbe_f(x)*mgga_series_w(params_a_a, Integer(12), t)
        + gtv4(m06_alpha, m06_coeff_d, x, Integer(2)*(t - K_FACTOR_C))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(m06_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_m06l_params"
