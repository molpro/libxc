"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_ssb_sw_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_ssb_sw_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_A = param_default("A")
params_a_B = param_default("B")
params_a_C = param_default("C")
params_a_D = param_default("D")
params_a_E = param_default("E")

@helper
def ssb_sw_f0(s):
    return (
        params_a_A
        + params_a_B*s**Integer(2)/(Integer(1) + params_a_C*s**Integer(2))
        - params_a_D*s**Integer(2)/(Integer(1) + params_a_E*s**Integer(4))
    )

@helper
def ssb_sw_f(x):
    return ssb_sw_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(ssb_sw_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_ssb_sw_params"
