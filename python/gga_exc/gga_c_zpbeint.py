"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_zpbeint_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_zpbeint_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_BB = param_default("BB")
params_a_tscale = param_default("tscale")
params_a_alpha = param_default("alpha")

params_a_gamma = (Integer(1) - log(Integer(2)))/pi**Integer(2)
params_a_BB = Integer(1)
params_a_tscale = Integer(1)
include('gga_c_pbe')

@helper
def ff(z, t):
    return mphi(z)**(params_a_alpha*t**Integer(3))

def f(rs, z, xt, xs0, xs1):
    return f_pw(rs, z) + ff(z, tp(rs, z, xt))*fH(rs, z, tp(rs, z, xt))

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_zpbeint_params"
