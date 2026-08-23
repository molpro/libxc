"""
 Copyright (C) 2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_s12_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_s12_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_A = param_default("A")
params_a_B = param_default("B")
params_a_C = param_default("C")
params_a_D = param_default("D")
params_a_E = param_default("E")
params_a_bx = param_default("bx")

# the bx-free body, factored out so cam_s12 can use it directly
# (where the bx would otherwise cancel symbolically -- SymPy does
# not see through the opaque helper application).

@helper
def s12g_f_inner(x):
    return params_a_A + params_a_B*((params_a_C*x**Integer(2) + params_a_D*x**Integer(4))/(Integer(1) + params_a_C*x**Integer(2) + params_a_D*x**Integer(4)))*(params_a_E*x**Integer(2)/(Integer(1) + params_a_E*x**Integer(2)))

@helper
def s12g_f(x):
    return params_a_bx*s12g_f_inner(x)

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(s12g_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_s12_params"
