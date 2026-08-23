"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

a = -Integer(1)

b = Float('11.8')

c = Float('0.150670')

d = Float('11.02e-3')/RS_FACTOR

# I added an m_abs() to this equation, as otherwise the f_num is
# complex for negative values of z. Of course it is not clear at all
# what was the original intential of Wilson, or if he even considered
# this problem.

@helper
def f_num(z):
    return a*sqrt(Integer(1) - m_min(m_max(m_abs(z), xc_reduced_floor), Integer(1) - xc_reduced_floor)**(Integer(5)/Integer(3)))

@helper
def f_den(rs, xt):
    return b + c*xt**(Integer(51)/Integer(16)) + d*xt**Integer(2)*rs + rs

# Equation (25)

def f(rs, z, xt, xs0, xs1):
    return f_num(z)/f_den(rs, xt)

TYPE = "gga_exc"
