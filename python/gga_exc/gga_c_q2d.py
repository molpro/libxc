"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_c_pbe_params')
include('gga_c_pbe')

include('lda_c_2d_amgb')
undef('xc_dimensions_2d')

rs2D_factor = Float('1.704')

q2d_dd = Float('1e6')

@helper
def q2d_rs2D(rs, xt):
    return rs2D_factor*rs*sqrt(X2S*xt)/RS_FACTOR

# KEEP IN SYNC: q2d_fac and q2d_one_minus_fac partition unity.
# 1 - t^4*(1+t^2)/(dd + t^6) = (dd - t^4)/(dd + t^6), algebraically
# equivalent and cancellation-free as q2d_fac -> 1 at moderate-to-
# large t (where the direct form computes 1 - close-to-1).

@helper
def q2d_fac(t):
    return (t**Integer(4) + t**Integer(6))/(q2d_dd + t**Integer(6))

@helper
def q2d_one_minus_fac(t):
    return (q2d_dd - t**Integer(4))/(q2d_dd + t**Integer(6))

@helper
def q2d_f(rs, z, xt, xs0, xs1):
    return q2d_one_minus_fac(tt(rs, z, xt))*f_pbe(rs, z, xt, xs0, xs1) + q2d_fac(tt(rs, z, xt))*f_amgb(q2d_rs2D(rs, xt), z)

def f(rs, z, xt, xs0, xs1):
    return q2d_f(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
