"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_xc_ksdt_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_xc_ksdt_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_T = param_default("T")
params_a_thetaParam = param_default("thetaParam")
params_a_b_0_ = param_default("b_0_")
params_a_c_0_ = param_default("c_0_")
params_a_d_0_ = param_default("d_0_")
params_a_e_0_ = param_default("e_0_")
params_a_b_1_ = param_default("b_1_")
params_a_c_1_ = param_default("c_1_")
params_a_d_1_ = param_default("d_1_")
params_a_e_1_ = param_default("e_1_")

g = maple_list([Integer(2)/Integer(3), -Float('0.0139261'), Float('0.183208')])

l = maple_list([Float('1.064009'), Float('0.572565')])

@helper
def alpha(t, rs):
    return Integer(2) - (g[Integer(1)] + g[Integer(2)]*rs)/(Integer(1) + g[Integer(3)]*rs)*exp(-t*(l[Integer(1)] + l[Integer(2)]*t*sqrt(rs)))

# Generalised f_zeta with parametric malpha exponent; routed through
# opz_pow_n_m1 so the (1+small)^malpha + (1-small)^malpha - 2
# cancellation around z = 0 is exact.
# KEEP IN SYNC: phi and one_minus_phi.  Algebraic identity:
# (1+z)^a = 2^a*(1 + opz_pow_n_m1((z-1)/2, a))
# (1-z)^a = 2^a*(1 + opz_pow_n_m1((-z-1)/2, a))
# so
# 1 - phi(a, z) = (2^a - (1+z)^a - (1-z)^a)/(2^a - 2)
# = -2^a*(1 + opz_pow_n_m1((z-1)/2, a) + opz_pow_n_m1((-z-1)/2, a))
# /(2^a - 2).
# The halved-argument opz_pow_n_m1 helpers route through xc_expm1/
# xc_log1p with the (1+z)/2 -> 0 (i.e. z -> -1) and (1-z)/2 -> 0
# (i.e. z -> +1) limits cancellation-free, fixing the iso-spin
# 1 - close-to-1 cancellation in the direct phi form.

@helper
def phi(malpha, z):
    return (opz_pow_n_m1(z, malpha) + opz_pow_n_m1(-z, malpha))/(Integer(2)**malpha - Integer(2))

@helper
def one_minus_phi(malpha, z):
    return (
        -Integer(2)**malpha
        * (Integer(1) + opz_pow_n_m1((z-Integer(1))/Integer(2), malpha) + opz_pow_n_m1((-z-Integer(1))/Integer(2), malpha))
        /(Integer(2)**malpha - Integer(2))
    )

lambda_ = (Integer(4)/(Integer(9)*pi))**(Integer(1)/Integer(3))

a0 = Integer(1)/(pi*lambda_)

a = maple_list([Float('0.750'), Float('3.043630'), -Float('0.0922700'), Float('1.703500'), Float('8.310510'), Float('5.11050')])

@helper
def aa(t):
    return a0*tanh(Integer(1)/t)*(a[Integer(1)] + a[Integer(2)]*t**Integer(2) + a[Integer(3)]*t**Integer(3) + a[Integer(4)]*t**Integer(4))/(Integer(1) + a[Integer(5)]*t**Integer(2) + a[Integer(6)]*t**Integer(4))

@helper
def bb(b, t):
    return tanh(Integer(1)/sqrt(t))*(b[Integer(1)] + b[Integer(2)]*t**Integer(2) + b[Integer(3)]*t**Integer(4))/(Integer(1) + b[Integer(4)]*t**Integer(2) + b[Integer(5)]*t**Integer(4))

@helper
def dd(d, t):
    return bb(d, t)

@helper
def ee(e, t):
    return tanh(Integer(1)/t)*(e[Integer(1)] + e[Integer(2)]*t**Integer(2) + e[Integer(3)]*t**Integer(4))/(Integer(1) + e[Integer(4)]*t**Integer(2) + e[Integer(5)]*t**Integer(4))

@helper
def cc(c, e, t):
    return (c[Integer(1)] + c[Integer(2)]*exp(-c[Integer(3)]/t))*ee(e, t)

@helper
def fxc(omega, b, c, d, e, rs, t):
    return -(omega*aa(t) + bb(b, t)*sqrt(rs) + cc(c, e, t)*rs)/(rs*(Integer(1) + dd(d, t)*sqrt(rs) + ee(e, t)*rs))

# (T/T_F)*opz_pow_n(z,2/3)

@helper
def mtt(rs, z):
    return Integer(2)*(Integer(4)/(Integer(9)*pi))**(Integer(2)/Integer(3))*params_a_T*rs**Integer(2)*(Integer(1) + params_a_thetaParam*z)**(Integer(2)/Integer(3))

def f(rs, z):
    return (
        + fxc(Integer(1),
        params_a_b_0_, params_a_c_0_, params_a_d_0_, params_a_e_0_,
        rs, mtt(rs, z))*one_minus_phi(alpha(mtt(rs, z), rs), z)
        + fxc(Integer(2)**(Integer(1)/Integer(3)),
        params_a_b_1_, params_a_c_1_, params_a_d_1_, params_a_e_1_,
        rs, mtt(rs, z)/Integer(2)**(Integer(2)/Integer(3)))*phi(alpha(mtt(rs, z), rs), z)
    )

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_xc_ksdt_params"
