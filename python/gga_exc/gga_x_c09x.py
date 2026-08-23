"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

c09x_mu = Float('0.0617')

c09x_kappa = Float('1.245')

c09x_alpha = Float('0.0483')

@helper
def c09x_f0(s):
    return Integer(1) + c09x_mu*s**Integer(2)*exp(-c09x_alpha*s**Integer(2)) + c09x_kappa*(-xc_expm1(-Integer(1)/Integer(2)*c09x_alpha*s**Integer(2)))

@helper
def c09x_f(x):
    return c09x_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(c09x_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
