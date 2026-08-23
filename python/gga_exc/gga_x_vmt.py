"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_vmt_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_vmt_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_mu = param_default("mu")
params_a_alpha = param_default("alpha")

@helper
def vmt_f0(s):
    return Integer(1) + params_a_mu*s**Integer(2)*exp(-params_a_alpha*s**Integer(2))/(Integer(1) + params_a_mu*s**Integer(2))

@helper
def vmt_f(x):
    return vmt_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(vmt_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_vmt_params"
