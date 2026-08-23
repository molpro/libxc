"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

rge2_kappa = Float('0.8040')

# Algebraic identity:
# kappa*(1 - kappa/den) = kappa*(den - kappa)/den;
# the subtraction is written symbolically against rge2_den so the
# polynomial stays single-source -- Maple simplifies the leading
# `rge2_kappa` away (den - rge2_kappa = MU_GE*t + MU_GE^2*t^2/kappa)
# before codegen, so the emitted C is cancellation-free at small s
# where the direct 1 - kappa/den form computes 1 - close-to-1
# (mirroring the PBE enhancement structure).

# The enhancement depends on the reduced gradient only through t = s^2, so it
# is fed the squared reduced gradient (gga_exchange_p): t = s^2 = X2S^2*p with
# p = xs^2 rational in sigma keeps the sigma derivatives cancellation-free.

@helper
def rge2_den(t):
    return rge2_kappa + Integer(1)*MU_GE*t + MU_GE**Integer(2)*t**Integer(2)/rge2_kappa

@helper
def rge2_f0(t):
    return Integer(1) + rge2_kappa*(rge2_den(t) - rge2_kappa)/rge2_den(t)

@helper
def rge2_f(p):
    return rge2_f0(X2S**Integer(2) * p)

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange_p(rge2_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
