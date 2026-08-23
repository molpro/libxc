"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

define('mgga_x_gx_params')
include('mgga_x_gx')

pbe_gx_mu = Float('0.001015549')

@helper
def pbe_gx(x):
    return Integer(1)/(Integer(1) + pbe_gx_mu*x**Integer(2))

@helper
def pbe_gx_f(x, u, t):
    return gx_f_a(mgga_alpha(x, t)) * pbe_gx(x)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(pbe_gx_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
