"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_vxc
# prefix:
#   mgga_x_tb09_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_tb09_params * ) (p->params);
# replace: "br89_x\(" -> "xc_mgga_x_br89_get_x("

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_c = param_default("c")
params_a_alpha = param_default("alpha")

include('mgga_x_br89')

params_a_gamma = Float('0.8')

tb09_c_HEG = (Integer(3)*params_a_c - Integer(2))*sqrt(Integer(5)/Integer(12))/(pi)

# floor the Fermi curvature (tau - alpha*tau_W) precision-relatively (xc_reduced_floor)

@helper
def tb09_f(rs, z, x, u, t):
    return (
        (params_a_c*X_FACTOR_C*br89_v(br89_x(br89_cQ(br89_Q(x, u, t))))
        + tb09_c_HEG*sqrt(Integer(2)*m_max(t - params_a_alpha*x**Integer(2)/Integer(8), xc_reduced_floor)))*n_spin(rs, z)**(Integer(1)/Integer(3))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return tb09_f(rs, z, xs0, u0, t0)

TYPE = "mgga_vxc"
PARAMS_STRUCT = "mgga_x_tb09_params"
REPLACE = [
    ('br89_x\\(', 'xc_mgga_x_br89_get_x('),
]
