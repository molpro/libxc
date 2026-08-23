"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

# p = s^2 is fed directly (mgga_kinetic_p) so the sigma derivatives are
# cancellation-free

@helper
def gea2_f0(p, q):
    return Integer(1) + Integer(5)/Integer(27)*p + Integer(20)/Integer(9)*q

@helper
def gea2_f(p, u):
    return gea2_f0(p, mgga_q(u))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_kinetic_p(gea2_f, rs, z, xs0, xs1, u0, u1)

TYPE = "mgga_exc"
