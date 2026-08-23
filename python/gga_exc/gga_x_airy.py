"""
 Copyright (C) 2017 M.A.L. Marques
               2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_airy_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_airy_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a1 = param_default("a1")
params_a_a2 = param_default("a2")
params_a_a3 = param_default("a3")
params_a_a4 = param_default("a4")
params_a_a5 = param_default("a5")
params_a_a6 = param_default("a6")
params_a_a7 = param_default("a7")
params_a_a8 = param_default("a8")
params_a_a9 = param_default("a9")
params_a_a10 = param_default("a10")

# eq 18

@helper
def airy_f0(s):
    return params_a_a1 * s**params_a_a2/(Integer(1) + params_a_a3 * s**params_a_a2)**params_a_a4 + (Integer(1) - params_a_a5*s**params_a_a6 + params_a_a7*s**params_a_a8)/(Integer(1) + params_a_a9*s**params_a_a10)

@helper
def airy_f(x):
    return airy_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(airy_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_airy_params"
