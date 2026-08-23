"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_ak13_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_ak13_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_B1 = param_default("B1")
params_a_B2 = param_default("B2")

@helper
def ak13_f0(s):
    return Integer(1) + params_a_B1*s*xc_log1p(s) + params_a_B2*s*xc_log1p(xc_log1p(s))

@helper
def ak13_f(x):
    return ak13_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(ak13_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_ak13_params"
