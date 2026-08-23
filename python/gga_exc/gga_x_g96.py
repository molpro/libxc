"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

g96_c1 = Integer(1)/Integer(137)

@helper
def f_g96(x):
    return Integer(1) + g96_c1/X_FACTOR_C * x**(Integer(3)/Integer(2))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(f_g96, rs, z, xs0, xs1)

TYPE = "gga_exc"
