"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_ft97_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_ft97_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta0 = param_default("beta0")
params_a_beta1 = param_default("beta1")
params_a_beta2 = param_default("beta2")

@helper
def ft97_beta(rs, z, xs):
    return (
        params_a_beta0
        + params_a_beta1*sigma_spin(rs, z, xs)/(params_a_beta2 + sigma_spin(rs, z, xs))
    )

@helper
def ft97_fx(rs, z, xs):
    return (
        Integer(1) + ft97_beta(rs, z, xs)*xs**Integer(2) /
        (X_FACTOR_C*sqrt(Integer(1) + Integer(9)*xs**Integer(2)*ft97_beta(rs, z, xs)**Integer(2)*xc_asinh(xs**Integer(2))**Integer(2)))
    )

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange_nsp(ft97_fx, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_ft97_params"
