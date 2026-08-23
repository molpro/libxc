"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_x_pbe_sol_params')
include('gga_x_pbe')

q1d_a = Float('0.06525')

@helper
def q1d_f1(s):
    return pbe_f0(s) + (s**Integer(2) + s**Integer(4))/(Integer(1) + s**Integer(4) + s**Integer(6))*(-pbe_f0(s)*s**Integer(2) + q1d_a)

@helper
def q1d_f(x):
    return q1d_f1(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(q1d_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
