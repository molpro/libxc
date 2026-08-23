"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

@helper
def gea4_f0(s, q):
    return Integer(1) + Integer(5)/Integer(27)*s**Integer(2) + Integer(20)/Integer(9)*q + Integer(8)/Integer(81)*q**Integer(2) - Integer(1)/Integer(9)*s**Integer(2)*q + Integer(8)/Integer(243)*s**Integer(4)

@helper
def gea4_f(x, u):
    return gea4_f0(gga_s(x), mgga_q(u))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_kinetic(gea4_f, rs, z, xs0, xs1, u0, u1)

TYPE = "mgga_exc"
