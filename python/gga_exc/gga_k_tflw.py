"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_k_tflw_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_k_tflw_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_lambda = param_default("lambda")

@helper
def tflw_f(p):
    return params_a_gamma + (params_a_lambda/Integer(8))*p/K_FACTOR_C

def f(rs, zeta, xt, xs0, xs1):
    return gga_kinetic_p(tflw_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_k_tflw_params"
