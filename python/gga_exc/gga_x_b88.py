"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_b88_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_b88_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")
params_a_gamma = param_default("gamma")

if defined('gga_x_b88_params'):
  params_a_beta = Float('0.0042')
  params_a_gamma = Float('6.0')

# The enhancement-minus-one is the precision-preserving primitive --
# computing it directly avoids the (1 + tiny) - 1 cancellation that
# shows up if a consumer needs b88_f(x) - 1 at small x. b88_f is then
# the trivial 1 + b88_f_m1, so the pair stays in sync.

@helper
def b88_f_m1(x):
    return params_a_beta/X_FACTOR_C*x**Integer(2)/(Integer(1) + params_a_gamma*params_a_beta*x*xc_asinh(x))

@helper
def b88_f(x):
    return Integer(1) + b88_f_m1(x)

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(b88_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_b88_params"
