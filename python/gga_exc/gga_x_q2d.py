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

q2d_cc = Integer(100)

q2d_c1 = Float('0.5217')

@helper
def q2d_f1(s):
    return pbe_f0(s)*(q2d_cc - s**Integer(4)) + q2d_c1*s**Float('3.5')*(Integer(1) + s**Integer(2))

@helper
def q2d_f2(s):
    return q2d_cc + s**Integer(6)

@helper
def q2d_f(x):
    return q2d_f1(gga_s(x))/q2d_f2(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(q2d_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
