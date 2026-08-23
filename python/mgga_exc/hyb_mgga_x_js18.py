"""
 Copyright (C) 2019 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

include('hyb_mgga_x_pjs18')

# This expression (10) has \tilde A, and not A.
# Use tm_one_minus_w (defined in mgga_x_tm.mpl) for the SC weight so
# the iso-orbital cancellation is gone.

@helper
def js18_f_SR(rs, z, x, t):
    return (
        tm_w(x, t)*js18_DME_SR(rs, z, x, t)
        + tm_one_minus_w(x, t)*attenuation_erf(a_cnst*rs/opz_pow_n(z,Integer(1)/Integer(3)))*tm_fx_SC(x, t)
    )

@helper
def js18_f(rs, z, x, u, t):
    return -p_a_cam_beta*js18_f_SR(rs, z, x, t) + tm_f(x, u, t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange_nsp(js18_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
