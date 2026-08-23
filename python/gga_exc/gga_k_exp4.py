"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

exp4_a1 = Float('199.81')

exp4_a2 = Float('4.3476')

exp4_c1 = Float('0.8524')

exp4_c2 = Float('1.2264')

# This is Eq. (40) of the paper.

@helper
def exp4_f0(s):
    return exp4_c1*(-xc_expm1(-exp4_a1*s**Integer(2))) + exp4_c2*(-xc_expm1(-exp4_a2*s**Integer(4)))

@helper
def exp4_f(x):
    return exp4_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_kinetic(exp4_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
