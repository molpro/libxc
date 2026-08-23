"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_c_x = param_default("c_x")
params_a_c_ss = param_default("c_ss")
params_a_c_ab = param_default("c_ab")

define('lda_c_pw_params')
include('lda_c_pw')

define('lda_x_params')
include('lda_x')

b98_gamma_x = Float('0.11')

b98_gamma_ss = Float('1.6')

b98_gamma_ab = Float('0.14')

params_a_c_x = maple_list([Float('0.8085'),  Float('0.6682'), Float('0.1420')])

params_a_c_ss = maple_list([Float('0.2606'), -Float('0.9608'), Float('0.9023')])

params_a_c_ab = maple_list([Float('1.2033'), -Float('2.2717'), Float('0.9596')])

# 1 - (t - x^2/8 - u/4)/K = (K - t + x^2/8 + u/4)/K.  At the uniform-
# gas limit t -> K (x = u = 0) the K - t residual is a direct
# subtraction (exact by Sterbenz near the limit), avoiding the
# 1 - close-to-1 cancellation of the original form.

@helper
def b98_q(x, u, t):
    return (K_FACTOR_C - t + x**Integer(2)/Integer(8) + u/Integer(4))/K_FACTOR_C

@helper
def b98_g(gamma, cc, q):
    return sum((cc[i]*(gamma*q/sqrt(Integer(1) + gamma**Integer(2)*q**Integer(2)))**(i-Integer(1))) for i in range(Integer(1), (Integer(3)) + Integer(1)))

@helper
def b98_f(rs, z, xs0, xs1, us0, us1, ts0, ts1):
    return (
        + lda_x_spin(rs,  z)
        * b98_g( b98_gamma_x, params_a_c_x, b98_q(xs0, us0, ts0))
        + lda_x_spin(rs, -z)
        * b98_g( b98_gamma_x, params_a_c_x, b98_q(xs1, us1, ts1))
        + lda_stoll_par(f_pw, rs,  z)
        * b98_g(b98_gamma_ss, params_a_c_ss, b98_q(xs0, us0, ts0)) * Fermi_D(xs0, ts0)
        + lda_stoll_par(f_pw, rs, -z)
        * b98_g(b98_gamma_ss, params_a_c_ss, b98_q(xs1, us1, ts1)) * Fermi_D(xs1, ts1)
        + lda_stoll_perp(f_pw, rs, z)
        * b98_g(b98_gamma_ab, params_a_c_ab, (b98_q(xs0, us0, ts0) + b98_q(xs1, us1, ts1))/Integer(2))
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return b98_f(rs, z, xs0, xs1, us0, us1, ts0, ts1)

TYPE = "mgga_exc"
