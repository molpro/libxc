"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_lta_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_lta_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_ltafrac = param_default("ltafrac")

@helper
def lta_f(x, u, t):
    return (t/K_FACTOR_C)**(Integer(4)*params_a_ltafrac/Integer(5))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(lta_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_lta_params"
