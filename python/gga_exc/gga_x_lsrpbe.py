"""
 Copyright (C) 2017 M.A.L. Marques
 Copyright (C) 2018 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_lsrpbe_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_lsrpbe_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")
params_a_mu = param_default("mu")
params_a_alpha = param_default("alpha")

@helper
def lsrpbe_f0(s):
    return (
        Integer(1) + params_a_kappa * (
        -xc_expm1(-params_a_mu*s**Integer(2)/params_a_kappa)
        ) - (params_a_kappa+Integer(1))*(-xc_expm1(-params_a_alpha*s**Integer(2)))
    )

@helper
def lsrpbe_f(x):
    return lsrpbe_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(lsrpbe_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_lsrpbe_params"
