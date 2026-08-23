"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_sogga11_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_sogga11_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_mu = param_default("mu")
params_a_kappa = param_default("kappa")
params_a_a = param_default("a")
params_a_b = param_default("b")

sogga11_alpha = params_a_mu*X2S*X2S/params_a_kappa

@helper
def sogga11_f0(x):
    return sogga11_alpha*x**Integer(2)/(Integer(1) + sogga11_alpha*x**Integer(2))

@helper
def sogga11_f1(x):
    return -xc_expm1(-sogga11_alpha*x**Integer(2))

@helper
def sogga11_f(x):
    return sum((params_a_a[i]*sogga11_f0(x)**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1))) + sum((params_a_b[i]*sogga11_f1(x)**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1)))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(sogga11_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_sogga11_params"
