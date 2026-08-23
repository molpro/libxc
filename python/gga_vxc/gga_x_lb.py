"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_vxc
# prefix:
#   gga_x_lb_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_lb_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")
params_a_gamma = param_default("gamma")
params_a_alpha = param_default("alpha")

@helper
def lb_f0(rs, z, x):
    return (
        -my_piecewise3(x < Integer(300),
        params_a_beta*x**Integer(2)/(Integer(1) + Integer(3)*params_a_beta*x*xc_asinh(params_a_gamma*x)),
        x/(Integer(3)*log(Integer(2)*params_a_gamma*x)))
    )

@helper
def lb_f(rs, z, x):
    return (params_a_alpha*(Integer(4)/Integer(3))*LDA_X_FACTOR + lb_f0(rs, z, x))*n_spin(rs, z)**(Integer(1)/Integer(3))

def f(rs, z, xt, xs0, xs1):
    return lb_f(rs, z, xs0)

TYPE = "gga_vxc"
PARAMS_STRUCT = "gga_x_lb_params"
