"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

@helper
def thakkar_f0(x):
    return Integer(1) + Float('0.0055')*x**Integer(2)/(Integer(1) + Float('0.0253')*x*xc_asinh(x))

@helper
def thakkar_f1(x):
    return -Float('0.072')*x/(Integer(1) + Integer(2)*Integer(4)**(Integer(1)/Integer(3))*x)

@helper
def thakkar_f(x):
    return thakkar_f0(x) + thakkar_f1(x)

def f(rs, zeta, xt, xs0, xs1):
    return gga_kinetic(thakkar_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
