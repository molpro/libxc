"""
 Copyright (C) 2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_ncap_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_ncap_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_mu = param_default("mu")
params_a_alpha = param_default("alpha")
params_a_zeta = param_default("zeta")
params_a_beta = param_default("beta")

@helper
def ncap_f0(s):
    return Integer(1) + params_a_mu*tanh(s)*xc_asinh(s)*( Integer(1) + params_a_alpha*((Integer(1)-params_a_zeta)*s*xc_log1p(s) + params_a_zeta*s))/(Integer(1) + params_a_beta*tanh(s)*xc_asinh(s))

@helper
def ncap_f(x):
    return ncap_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(ncap_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_ncap_params"
