"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_wi_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_wi_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_k = param_default("k")
params_a_c = param_default("c")
params_a_d = param_default("d")

@helper
def f_num(xt):
    return params_a_a + params_a_b*xt**Integer(2)*exp(-params_a_k*xt**Integer(2))

@helper
def f_den(rs, xt):
    return params_a_c + rs*(Integer(1) + params_a_d*(Integer(4)*pi/Integer(3))**(Integer(1)/Integer(3))*xt**(Integer(7)/Integer(2)))

def f(rs, zeta, xt, xs0, xs1):
    return f_num(xt)/f_den(rs, xt)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_wi_params"
