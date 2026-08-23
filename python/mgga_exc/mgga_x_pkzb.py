"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

pkzb_a2 = Integer(146)/Integer(2025)

pkzb_a3 = -Integer(73)/Integer(405)

pkzb_a4 = Float('0.131957187845257783631757384393')

# DD + 100/(81*81*kappa)

pkzb_kappa = Float('0.804')

# completed square: a2*qt^2+a3*qt*p+a4*p^2 = a2*(qt+a3/(2*a2)*p)^2 + (a4-a3^2/(4*a2))*p^2,
# a sum of positive terms -- cancellation-free at large reduced gradient

@helper
def pkzb_xx(p, qt):
    return MU_GE*p + pkzb_a2*(qt + pkzb_a3/(Integer(2)*pkzb_a2)*p)**Integer(2) + (pkzb_a4 - pkzb_a3**Integer(2)/(Integer(4)*pkzb_a2))*p**Integer(2)

# qt(x, t) is the second argument of pkzb_xx in pkzb_f; isolated so
# the f-expression below shows only one occurrence.

# p = s^2 = X2S^2*x^2 is fed directly (mgga_exchange_p) so the sigma
# derivatives are cancellation-free

@helper
def pkzb_qt(p, t):
    return Integer(6)*X2S**Integer(2)*t - Integer(9)/Integer(20) - p/Integer(12)

# Algebraic identity:
# 1 + kappa - kappa^2/(kappa + X) = 1 + kappa*X/(kappa + X);
# the direct form computes kappa - close-to-kappa at small X
# (high density) and loses precision in the constant 1 + kappa
# that emerges from the cancellation.  The single-fraction form
# is cancellation-free and identical to the standard PBE
# enhancement structure.

@helper
def pkzb_f(p, u, t):
    return (
        Integer(1) + pkzb_kappa*pkzb_xx(p, pkzb_qt(p, t))/
        (pkzb_kappa + pkzb_xx(p, pkzb_qt(p, t)))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange_p(pkzb_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
