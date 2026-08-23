"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# replace: "BesselI\(0, " -> "xc_bessel_I0("
# replace: "BesselI\(1, " -> "xc_bessel_I1("

from libxc_codegen import *  # noqa: F401, F403

define('xc_dimensions_2d')

@helper
def prhg07_C(x, u, t):
    return (u - Integer(4)*t + x**Integer(2)/Integer(2))/Integer(4)

# This is the solution of solve((y-1)*exp(y) = x/Pi)

@helper
def prhg07_y(x):
    return LambertW(m_max(x/pi, -Float('0.9999999999')) * exp(-Integer(1))) + Integer(1)

@helper
def prhg07_v(y):
    return pi/X_FACTOR_2D_C * BesselI(Integer(0), y/Integer(2))

@helper
def prhg07_f(x, u, t):
    return prhg07_v(prhg07_y(prhg07_C(x, u, t)))/Integer(2)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(prhg07_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
REPLACE = [
    ('BesselI\\(0, ', 'xc_bessel_I0('),
    ('BesselI\\(1, ', 'xc_bessel_I1('),
]
