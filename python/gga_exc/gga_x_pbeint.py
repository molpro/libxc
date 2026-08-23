"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_pbeint_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_pbeint_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_muGE = param_default("muGE")
params_a_muPBE = param_default("muPBE")
params_a_alpha = param_default("alpha")
params_a_kappa = param_default("kappa")

@helper
def pbeint_mu(s):
    return (
        params_a_muGE + (params_a_muPBE - params_a_muGE)* \
        params_a_alpha*s**Integer(2)/(Integer(1) + params_a_alpha * s**Integer(2))
    )

# this is the gga_x_pbe expression

@helper
def pbeint_f0(s):
    return Integer(1) + params_a_kappa*pbeint_mu(s)*s**Integer(2)/(params_a_kappa + pbeint_mu(s)*s**Integer(2))

@helper
def pbeint_f(x):
    return pbeint_f0(X2S * x)

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(pbeint_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_pbeint_params"
