"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

define('xc_dimensions_2d')

js17_lambda = Float('0.74')

js17_beta = Float('30.0')

#
# Notes:
# rho -> 2 rho_sigma, from the spin sum rule
# tsu2d_unif_sigma/n_sigma^2 = 4 Pi, tau is missing 1/2 in paper

# Eq. (18)

@helper
def js17_ff(s):
    return (Integer(1) + Integer(90)*(Integer(2)*js17_lambda - Integer(1))**Integer(2)*s**Integer(2) + js17_beta*(Integer(2)*js17_lambda - Integer(1))**Integer(4)*s**Integer(4))**(Integer(1)/Integer(15))

# Eq. (23).  Algebraic identity (let c = js17_lambda^2 - js17_lambda
# + 1/2):
# 1 + (3c*(t - 4 Pi) - t)/(4 Pi) = (1 - 3c)*(4 Pi - t)/(4 Pi),
# at the 2D uniform-gas limit t -> 4 Pi the residual 4 Pi - t is a
# direct subtraction (exact by Sterbenz near the limit), so it stays
# relative-accurate, unlike the 1 - close-to-1 forms.

@helper
def js17_R(s, t):
    return (
        + (Integer(1) - Integer(3)*(js17_lambda**Integer(2) - js17_lambda + Integer(1)/Integer(2)))*(Integer(4)*pi - t)/(Integer(4)*pi)
        + Integer(128)/Integer(21)*(Integer(2)*js17_lambda - Integer(1))**Integer(2)*s**Integer(2)
    )

@helper
def js17_f(x, u, t):
    return (
        Integer(1)/js17_ff(X2S_2D*x)
        + Integer(2)/Integer(5) * js17_R(X2S_2D*x, t)/js17_ff(X2S_2D*x)**Integer(3)
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(js17_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
