"""
 Copyright (C) 2017 M.A.L. Marques
 Copyright (C) 2018 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_rtpss_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_rtpss_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")

# These are used within the tpss_x routine

@helper
def tpss_ff(z):
    return Integer(2)

@helper
def tpss_kappa(x, t):
    return params_a_kappa

include('tpss_x')

# Equation (6)

@helper
def rtpss_f(x, u, t):
    return Integer(1) + tpss_kappa(x, t)*(-xc_expm1(-tpss_fx(x, t)/tpss_kappa(x,t)))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(rtpss_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_rtpss_params"
