"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

@helper
def pearson_f0(s):
    return Integer(1) + Integer(5)/Integer(27)*s**Integer(2)/(Integer(1) + s**Integer(6))

@helper
def pearson_f(x):
    return pearson_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_kinetic(pearson_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
