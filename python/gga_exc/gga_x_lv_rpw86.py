"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_x_rpw86_params')
include('gga_x_pw86')

lv_alpha = Float('0.02178')

lv_beta = Float('1.15')

lv_muLV = Float('0.8491')/Integer(9)

# lv_f0 = lv_A + lv_B*pw86_f0.  lv_A and lv_B are bounded rationals, but
# at a near-empty spin channel the reduced gradient s -> infinity
# (s ~ 1e10), and the s^6 denominators' high derivatives overflow
# (v2rho2 -> inf) even though the values are fine.  They are rational
# (poles at |s| = (1/lv_alpha)^(1/6) ~ 1.9), so their large-s expansion
# converges; switch to it above a cutoff (pw86_f0 itself stays finite and
# is left direct).  enforce_smooth_lr clamps both branches so neither is
# evaluated in its diverging region.

@helper
def lv_A(s):
    return (Integer(1) + lv_muLV*s**Integer(2))/(Integer(1) + lv_alpha*s**Integer(6))

@helper
def lv_B(s):
    return lv_alpha*s**Integer(6)/(lv_beta + lv_alpha*s**Integer(6))

lv_cut = Integer(100)

@helper
def lv_f0(s):
    return (
        + enforce_smooth_lr(lv_A, s, lv_cut, Integer(10))
        + enforce_smooth_lr(lv_B, s, lv_cut, Integer(10))*pw86_f0(s)
    )

@helper
def lv_f(x):
    return lv_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(lv_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
