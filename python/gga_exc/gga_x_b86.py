"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_b86_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_b86_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")
params_a_gamma = param_default("gamma")
params_a_omega = param_default("omega")

if defined('gga_x_b86_mgc_params'):
  params_a_beta = Float('0.00375')/X_FACTOR_C
  params_a_gamma = Float('0.007')
  params_a_omega = Integer(4)/Integer(5)

@helper
def b86_f(x):
    return Integer(1) + params_a_beta*x**Integer(2)/(Integer(1) + params_a_gamma*x**Integer(2))**params_a_omega

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(b86_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_b86_params"
