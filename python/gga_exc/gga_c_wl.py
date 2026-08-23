"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

a = -Float('0.74860')

b = Float('0.06001')

c = Float('3.60073')

d = Float('0.90000')

@helper
def f_num(z, xt):
    return sqrt(one_minus_z_pow_n(z, Integer(2)))*(a + b*xt)

@helper
def f_den(rs, xs0, xs1):
    return c + d*(xs0 + xs1) + rs

def f(rs, zeta, xt, xs0, xs1):
    return f_num(zeta, xt)/f_den(rs, xs0, xs1)

TYPE = "gga_exc"
