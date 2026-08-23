"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_m05_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_m05_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_csi_HF = param_default("csi_HF")
params_a_a = param_default("a")

define('gga_x_pbe_params')
include('gga_x_pbe')

@helper
def m05_f(x, u, t):
    return + params_a_csi_HF*pbe_f(x)*mgga_series_w(params_a_a, Integer(12), t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(m05_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_m05_params"
