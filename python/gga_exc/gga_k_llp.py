"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_k_llp_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_k_llp_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")
params_a_gamma = param_default("gamma")

@helper
def llp_f(x):
    return Float('1.0') + params_a_beta/X_FACTOR_C*x**Integer(2)/(Float('1.0') + params_a_gamma*params_a_beta*x*xc_asinh(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_kinetic(llp_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_k_llp_params"
