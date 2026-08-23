"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_gdme_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_gdme_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_AA = param_default("AA")
params_a_BB = param_default("BB")
params_a_a = param_default("a")

gdme_at = (params_a_AA + Integer(3)/Integer(5)*params_a_BB)*Integer(2)**(Integer(1)/Integer(3))/(X_FACTOR_C*(Integer(3)*pi**Integer(2))**(Integer(2)/Integer(3)))

gdme_bt = params_a_BB/(X_FACTOR_C*Integer(2)**(Integer(1)/Integer(3))*(Integer(3)*pi**Integer(2))**(Integer(4)/Integer(3)))

@helper
def gdme_f(x, u, t):
    return gdme_at + gdme_bt*((params_a_a**Integer(2) - params_a_a + Integer(1)/Integer(2))*u - Integer(2)*t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(gdme_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_gdme_params"
