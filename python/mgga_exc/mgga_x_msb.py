"""
 Copyright (C) 2017 M.A.L. Marques
 Copyright (C) 2018 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_msb_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_msb_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c = param_default("c")

include('mgga_x_ms')

# eq (5) in the paper

@helper
def msb_beta(x, t):
    return mgga_alpha(x, t)*K_FACTOR_C/(t + K_FACTOR_C)

# eq (14) in the supplement is f(2*beta) with the same shape as ms_fa,
# so reuse the shared ms_fa (which also carries the magnitude clamp)
# instead of duplicating it.

# Use ms_f0_delta for the cancellation-free f0(p, c) - f0(p, 0).

@helper
def msb_f(x, u, t):
    return (
        ms_f0(X2S**Integer(2)*x**Integer(2), Integer(0)) + \
        ms_fa(Integer(2)*msb_beta(x,t))*ms_f0_delta(X2S**Integer(2)*x**Integer(2), params_a_c)
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(msb_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_msb_params"
