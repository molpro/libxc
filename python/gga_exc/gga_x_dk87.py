"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_dk87_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_dk87_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a1 = param_default("a1")
params_a_alpha = param_default("alpha")
params_a_b1 = param_default("b1")

dk87_betag = Integer(7)/(Integer(432)*pi*(Integer(6)*pi**Integer(2))**(Integer(1)/Integer(3)))/X_FACTOR_C

@helper
def dk87_f(x):
    return Integer(1) + dk87_betag*x**Integer(2)*(Integer(1) + params_a_a1*x**params_a_alpha)/(Integer(1) + params_a_b1*x**Integer(2))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(dk87_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_dk87_params"
