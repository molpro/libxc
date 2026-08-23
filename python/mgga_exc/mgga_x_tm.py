"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

tm_lambda = Float('0.6866')

tm_beta = Float('79.873')

# below Equation (6)

@helper
def tm_p(x):
    return (gga_s(x))**Integer(2)

@helper
def tm_y(x):
    return (Integer(2)*tm_lambda - Integer(1))**Integer(2) * tm_p(x)

# Equation (7)

@helper
def tm_f0(x):
    return (Integer(1) + Integer(10)*(Integer(70)*tm_y(x)/Integer(27)) + tm_beta*tm_y(x)**Integer(2))**(Integer(1)/Integer(10))

# after Equation (9).  Algebraic identity (let c = tm_lambda^2 -
# tm_lambda + 1/2):
# 1 - (t - 3c*(t - K - x^2/72))/K
# = 1 - t/K + 3c*t/K - 3c - 3c*x^2/(72 K)
# = (1 - 3c)*(1 - t/K) - 3c*x^2/(72 K)
# = (1 - 3c)*(K - t)/K - 3c*x^2/(72 K).
# At the uniform-gas limit t -> K the residual K - t is computed as
# a direct subtraction (exact by Sterbenz for t within a factor 2 of
# K), so (K - t)/K is relative-accurate -- unlike both the original
# 1 - close-to-1 form and the intermediate 1 - t/K form, which round
# t/K to ~1 and lose the low bits of the small residual.

@helper
def tm_R(x, t):
    return (
        (Integer(1) - Integer(3)*(tm_lambda**Integer(2) - tm_lambda + Integer(1)/Integer(2)))*(K_FACTOR_C - t)/K_FACTOR_C \
        + Integer(595)*(Integer(2)*tm_lambda - Integer(1))**Integer(2) * tm_p(x)/Integer(54) \
        - Integer(3)*(tm_lambda**Integer(2) - tm_lambda + Integer(1)/Integer(2))*x**Integer(2)/(Integer(72)*K_FACTOR_C)
    )

@helper
def tm_fx_DME(x, t):
    return Integer(1)/tm_f0(x)**Integer(2) + Integer(7)*tm_R(x, t)/(Integer(9)*tm_f0(x)**Integer(4))

# after Equation (11)

@helper
def tm_qtilde(x, t):
    return Integer(9)/Integer(20)*(mgga_alpha(x, t) - Integer(1)) + Integer(2)*tm_p(x)/Integer(3)

# Ratio tW/t; we have to make sure it's 1 at maximum

@helper
def tm_tratio(x, t):
    return m_min(Float('1.0'), x**Integer(2)/(Integer(8)*t))

@helper
def tm_fx_SC(x, t):
    return (
        (Integer(1) + Integer(10)*( \
        + (MU_GE + Integer(50)*tm_p(x)/Integer(729))*tm_p(x) + Integer(146)*tm_qtilde(x, t)**Integer(2)/Integer(2025) \
        - Integer(73)*tm_qtilde(x,t)/Integer(405)*(Integer(3)/Integer(5)*tm_tratio(x,t))*(Integer(1) - tm_tratio(x,t)))
        )**(Integer(1)/Integer(10))
    )

# Equation 10 and below.
# KEEP IN SYNC: tm_w and tm_one_minus_w must stay paired.
# Algebraic identity (with r = tm_tratio):
# 1 - r^2*(1+3r)/(1+r^3)^2
# = (1 + r^3)^2 - r^2*(1 + 3r)) / (1 + r^3)^2
# = (1 - r^2 - r^3 + r^6) / (1 + r^3)^2
# = (1 - r)*(1 + r - r^3 - r^4 - r^5) / (1 + r^3)^2.
# The factored form is cancellation-free at r -> 1 (iso-orbital limit),
# where tm_w in fact slightly overshoots 1 so the direct form
# 1 - close-to-1 loses several digits in the small residual.

@helper
def tm_w(x, t):
    return (tm_tratio(x,t)**Integer(2) + Integer(3)*tm_tratio(x,t)**Integer(3))/(Integer(1) + tm_tratio(x,t)**Integer(3))**Integer(2)

@helper
def tm_one_minus_w(x, t):
    return (
        (Integer(1) - tm_tratio(x,t))
        * (Integer(1) + tm_tratio(x,t) - tm_tratio(x,t)**Integer(3) - tm_tratio(x,t)**Integer(4) - tm_tratio(x,t)**Integer(5))
        / (Integer(1) + tm_tratio(x,t)**Integer(3))**Integer(2)
    )

@helper
def tm_f(x, u, t):
    return tm_w(x,t)*tm_fx_DME(x, t) + tm_one_minus_w(x,t)*tm_fx_SC(x, t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(tm_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
