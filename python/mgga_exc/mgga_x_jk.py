"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_jk_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_jk_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

include('gga_x_b88')

# equation 11

@helper
def y(x, u):
    return x**Integer(2) - u

# equation 24. The paper's "gBecke(x) = b88_f(x) - 1" is just
# b88_f_m1(x); use it directly without the (1 + tiny) - 1 cancellation.

@helper
def jk_f(x, u, t):
    return Integer(1) + b88_f_m1(x)/(Integer(1) + Integer(2)*y(x,u)/x**Integer(2))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(jk_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_jk_params"
