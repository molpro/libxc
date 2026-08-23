"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_optx_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_optx_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_gamma = param_default("gamma")

@helper
def optx_f(x):
    return params_a_a + params_a_b*(params_a_gamma*x**Integer(2)/(Integer(1) + params_a_gamma*x**Integer(2)))**Integer(2)

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(optx_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_optx_params"
