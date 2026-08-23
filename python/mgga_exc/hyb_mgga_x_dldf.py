"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")
params_a_mu = param_default("mu")

params_a_kappa = Float('4.8827323')
params_a_mu = Float('0.3511128')
include('gga_x_pbe')

dldf_a = maple_list([Integer(1), -Float('0.1637571'), -Float('0.1880028'), -Float('0.4490609'), -Float('0.0082359')])

dldf_csi_HF = Integer(1) - Float('0.6144129')

@helper
def dldf_f(x, u, t):
    return + dldf_csi_HF*pbe_f(x)*mgga_series_w(dldf_a, Integer(5), t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(dldf_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
