"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

include('mgga_c_scan')

# Override definition of beta

@helper
def mbeta(rs, t):
    return Float('0.066725')

rmggac_gamma1 = Float('0.08')

rmggac_gamma2 = Float('0.3')

@helper
def rmggac_g(alpha, s):
    return (Integer(1) + rmggac_gamma1)*alpha/(rmggac_gamma1 + alpha + rmggac_gamma2*s**Integer(2))

# Algebraic identity:
# 1 - 3 g^3/(1 + g^3 + g^6)
# = (1 + g^3 + g^6 - 3 g^3)/(1 + g^3 + g^6)
# = (1 - g^3)^2/(1 + g^3 + g^6),
# which is cancellation-free at g = 1 where f2 -> 1 and the direct
# 1 - close-to-1 form loses precision.

@helper
def rmggac_f2(alpha, s):
    return Integer(3)*rmggac_g(alpha, s)**Integer(3)/(Integer(1) + rmggac_g(alpha, s)**Integer(3) + rmggac_g(alpha, s)**Integer(6))

@helper
def rmggac_f1(alpha, s):
    return (Integer(1) - rmggac_g(alpha, s)**Integer(3))**Integer(2)/(Integer(1) + rmggac_g(alpha, s)**Integer(3) + rmggac_g(alpha, s)**Integer(6))

rmggac_gamma = Float('0.031091')

# from mmga_c_r2scan

@helper
def rmggac_w1(rs, z):
    return xc_expm1(-f_pw(rs, z)/(rmggac_gamma*mphi(z)**Integer(3)))

@helper
def rmggac_H1(rs, z, t):
    return rmggac_gamma*mphi(z)**Integer(3)*xc_log1p(rmggac_w1(rs, z) * scan_e0_one_minus_g(rs, z, t))

@helper
def rmggac_eps1(rs, z, t):
    return (f_pw(rs, z) +  rmggac_H1(rs, z, t))

@helper
def rmggac_alpha(z, xt, ts0, ts1):
    return (t_total(z, ts0, ts1) - xt**Integer(2)/Integer(4))/(Integer(2)**(Integer(1)/Integer(3))*K_FACTOR_C)

@helper
def rmggac_f(rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        + scan_e0(rs, z, gga_s_total(xt))
        * rmggac_f1(rmggac_alpha(z, xt, ts0, ts1), gga_s_total(xt))
        + rmggac_eps1(rs, z, tp(rs, z, xt))
        * rmggac_f2(rmggac_alpha(z, xt, ts0, ts1), gga_s_total(xt))
    )

# the functional is written for the other convention for tau

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return rmggac_f(rs, z, xt, xs0, xs1, Integer(2)*ts0, Integer(2)*ts1)

TYPE = "mgga_exc"
