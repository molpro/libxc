"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

gvt4_alpha = Float('0.00186726')

gvt4_coeff_d = maple_list([-Float('9.800683e-01'), -Float('3.556788e-03'), Float('6.250326e-03'), -Float('2.354518e-05'), -Float('1.282732e-04'), Float('3.574822e-04')])

include('gvt4')

@helper
def gvt4_f(x, u, t):
    return -gtv4(gvt4_alpha, gvt4_coeff_d, x, Integer(2)*(t - K_FACTOR_C))/X_FACTOR_C

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(gvt4_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
