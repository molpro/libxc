"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

define('mgga_x_revtpss_params')
include('mgga_x_tpss')

reg_c = Integer(3)

reg_d = Float('1.475')

@helper
def reg_f_a(a):
    return (Integer(1) - a)**Integer(3)/(Integer(1) + (reg_d*a)**Integer(2))**(Integer(3)/Integer(2))

# Eq. (12). Note that alpha = 0 => t = x^2/8

@helper
def reg_f(x, u, t):
    return tpss_f(x, u, t) + reg_f_a(mgga_alpha(x, t))*exp(-reg_c*X2S**Integer(2)*x**Integer(2))*(tpss_f(x, u, x**Integer(2)/Integer(8)) - tpss_f(x, u, t))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(reg_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
