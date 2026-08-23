"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_ev93_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_ev93_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a1 = param_default("a1")
params_a_a2 = param_default("a2")
params_a_a3 = param_default("a3")
params_a_b1 = param_default("b1")
params_a_b2 = param_default("b2")
params_a_b3 = param_default("b3")

@helper
def ev93_f0(s):
    return (Integer(1) + params_a_a1*s**Integer(2) + params_a_a2*s**Integer(4) + params_a_a3*s**Integer(6))/(Integer(1) + params_a_b1*s**Integer(2) + params_a_b2*s**Integer(4) + params_a_b3*s**Integer(6))

@helper
def ev93_f(x):
    return ev93_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(ev93_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_ev93_params"
