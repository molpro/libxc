"""
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_bkl_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_bkl_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_kappa = param_default("kappa")
params_a_alpha = param_default("alpha")
params_a_mu1 = param_default("mu1")
params_a_beta = param_default("beta")

@helper
def bkl_f0(s):
    return Integer(1) + params_a_gamma*params_a_kappa*(exp(-params_a_alpha*params_a_mu1*s**Integer(2)) - exp(-params_a_beta*params_a_mu1*s**Integer(2)))

@helper
def bkl_f(x):
    return bkl_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(bkl_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_bkl_params"
