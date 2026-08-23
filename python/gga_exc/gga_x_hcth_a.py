"""
 Copyright (C) 2017 M.A.L. Marques
               2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_hcth_a_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_hcth_a_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_c0 = param_default("c0")
params_a_c1 = param_default("c1")
params_a_beta = param_default("beta")
params_a_c2 = param_default("c2")

beta = Symbol("beta")

# eq 31

@helper
def hcth_b88x(beta, x):
    return beta*x**Integer(2)/(Integer(1)+params_a_gamma*beta*x*xc_asinh(x))

# eq 30

@helper
def hcth_a_f(x):
    return params_a_c0 - params_a_c1/X_FACTOR_C*hcth_b88x(params_a_beta,x) - params_a_c2/X_FACTOR_C*maple_eval(diff(hcth_b88x(beta,x),beta), beta, params_a_beta)

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(hcth_a_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_hcth_a_params"
