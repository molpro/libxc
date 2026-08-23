"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_cap_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_cap_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_alphaoAx = param_default("alphaoAx")
params_a_c = param_default("c")

@helper
def cap_f0(s):
    return Integer(1) - params_a_alphaoAx*s*xc_log1p(s)/(Integer(1) + params_a_c*xc_log1p(s))

@helper
def cap_f(x):
    return cap_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(cap_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_cap_params"
