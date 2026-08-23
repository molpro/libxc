"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

# The third terms in Equations (14) and (15) are wrong.
# The expression below reproduces the OL1 results in Table I.

@helper
def ol1_f(x):
    return Integer(1) + (x**Integer(2)/Integer(72) + Float('0.00677')*Integer(2)**(Integer(1)/Integer(3))*x)/K_FACTOR_C

def f(rs, zeta, xt, xs0, xs1):
    return gga_kinetic(ol1_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
