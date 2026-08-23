"""
 Copyright (C) 2025 Timo Lebeda and Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

y = Symbol("y")

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')
include('mgga_x_lak')

# parameters from page 4 of SI

lak_mu_a = -lak_mu_ax/Integer(2)

lak_b1c = Float('0.0468')

lak_b2c = Float('0.205601')

lak_chi_zero = Float('1.55344')

lak_b3c = Float('2.85')

lak_ac = Integer(10)

# SI eq 3

lak_Ax = -Integer(3)/Integer(4) * (Integer(3)/pi)**(Integer(1)/Integer(3))

# SI eq 12

# SI eq 13

# SI eq 14

@helper
def lak_eclda0(rs):
    return -lak_b1c / (Integer(1) + lak_b2c*rs)

# SI eq 15

# SI eq 16

@helper
def lak_w0(rs):
    return xc_expm1(-lak_eclda0(rs)/lak_b1c)

@helper
def lak_H0(rs, s):
    return lak_b1c*log(m_max(XC_MIN,Integer(1) + lak_w0(rs)*(-xc_expm1(-(Integer(1)/Integer(4))*xc_log1p(Integer(4)*lak_chi_zero*s**Integer(2))))))

# SI eq 17

lak_G_cnst = Float('2.3631')

@helper
def lak_Gc(z):
    return (Integer(1) - lak_G_cnst*(Integer(2)**(Integer(1)/Integer(3)) - Integer(1))*f_zeta(z))*one_minus_z_pow_n(z, Integer(12))

@helper
def lak_e0(rs, z, s):
    return (lak_eclda0(rs) + lak_H0(rs, s))*lak_Gc(z)

# SI eq 19; the expression is ill-behaved for alpha->0 i.e. alpha tilde -> infinity.
# Series at infinity is 1 - 4/(pi^2 x) + 16/(3 pi^4 x^3) - 64/(5 pi^6 x^5) + ...
# (odd 1/x powers only).  Order 6 (terms up to 1/x^5) gives 4th
# derivative truncation 7*6*5*4 * c_7 / x_c^11 ~ O(840) * eps^11
# at x_c = 1/eps -- absurdly below XC_EPSILON * |actual 4th
# derivative ~ eps^5|, plenty of margin.

@helper
def lak_fc0(x):
    return Integer(2)/pi * atan(pi/Integer(2) * x)

@helper
def lak_fc_taylor(x):
    return maple_eval(convert(maple_eval(maple_series(lak_fc0(y), y, infinity, Integer(6)), csgn, Integer(1)),polynom), y, x)

@helper
def lak_fc_piecewise(x):
    return my_piecewise3(x >= Integer(1)/XC_EPSILON, lak_fc_taylor(m_max(x, Integer(1)/XC_EPSILON)), lak_fc0(m_min(x,Integer(1)/XC_EPSILON)))

# further extends fc(alpha) to negative alpha

# SI eq 20

@helper
def lak_at(rs, a):
    return (a-Integer(1))/(m_max(rs*a, XC_EPSILON))

# SI eq 21

# SI eq 22

# SI eq 23

# SI eq 24

# SI eq 25 (&26-28)

# SI eq 27

@helper
def lak_ct(z):
    return (Integer(3)*pi**Integer(2)/Integer(16))**(Integer(2)/Integer(3)) / mphi(z)**Integer(2)

# SI eq 29; note that equation is wrong in the SI - argument of ct is missing

# SI eq 30

lak_Ac = RS_FACTOR * lak_Ax

# SI eq 31

# SI eq 33

# SI eq 34

# SI eq 35

lak_gamma = (Integer(1) - log(Integer(2)))/pi**Integer(2)

# SI eq 36, note that SI has missing parentheses: phi zeta should be phi(zeta)

@helper
def lak_w1(rs, z):
    return xc_expm1(-f_pw(rs, z)/(lak_gamma*mphi(z)**Integer(3)))

# SI eq 37; lak_g1p = (m_max(1 + 4At^2, eps))^(-1/4) only ever appears
# as `1 - lak_g1p`, so we go straight to that form via expm1/log1p.
# lak_g1m is kept because its consumer still needs `(1 - lak_g1m)` as
# a separate quantity (the clamp regime can drive it large/negative
# in a way that doesn't fit the expm1 pattern cleanly).

# SI eq 38; lak_g2 = 1/(1 + X^2) only appears as `1 - lak_g2`, so we
# write that as X^2/(1 + X^2) directly -- algebraic identity, no
# cancellation.

# SI eq 39

# SI eq 40

# SI eq 41

# SI eq 62

# Constant in SI main text after eq 62

lak_Cs0 = -Integer(16)*pi*(Integer(3)*pi**Integer(2))**(Integer(1)/Integer(3))*Float('2.568')/(Integer(3000)*MU_GE)

@helper
def lak_Cma(rs):
    return lak_Cs0 * (Integer(1) + Float('0.1')*rs**Float('0.65')) / ( (Integer(1) + Float('0.065')*rs**Float('0.9'))*(Integer(1) + Float('0.03')*rs**Float('1.2')) )

@helper
def lak_mu_ac(rs):
    return lak_Cma(rs)*lak_mu_a - lak_mu_ax

@helper
def lak_beta_at(rs):
    return -lak_Ac * lak_mu_ac(rs)

@helper
def lak_fcGE2(rs):
    return lak_beta_at(rs) / (m_min(f_pw(rs,Integer(0))-lak_eclda0(rs), -XC_EPSILON))

@helper
def lak_fc(rs, a):
    return my_piecewise3(a < Integer(0), Integer(2)+lak_fc_piecewise(lak_fcGE2(rs)*m_abs(lak_at(rs,a))), lak_fc_piecewise(lak_fcGE2(rs)*lak_at(rs,a)))

@helper
def lak_mu_sc(rs):
    return MU_GE * (lak_Cma(rs)*(Integer(1)+Integer(6)*lak_mu_a) - (Integer(1)+Integer(6)*lak_mu_ax))

@helper
def lak_beta_t(rs):
    return lak_Ac / lak_ct(Integer(0)) * lak_mu_sc(rs)

@helper
def lak_A(rs, z):
    return lak_beta_t(rs) / (lak_gamma*lak_w1(rs,z))

@helper
def lak_one_minus_g1p(rs, z, t):
    return -xc_expm1(-(Integer(1)/Integer(4))*xc_log1p(Integer(4)*lak_A(rs,z)*t**Integer(2)))

@helper
def lak_g1m(rs, z, t):
    return (m_max(Integer(1) - Integer(4)*lak_A(rs,z)*t**Integer(2), XC_EPSILON))**(-Integer(1)/Integer(4))

@helper
def lak_one_minus_g2(rs, z, t):
    return (lak_A(rs,z)*t**Integer(2))**Integer(2)/(Integer(1) + (lak_A(rs,z)*t**Integer(2))**Integer(2))

@helper
def lak_g3p(rs, z, t):
    return (m_max(Integer(1) + lak_ac*lak_A(rs,z)*t**Integer(2), XC_EPSILON))**(-Integer(1))

@helper
def lak_H1p(rs, z, t):
    return lak_gamma*mphi(z)**Integer(3)*log(m_max(Integer(1) + lak_w1(rs,z) * lak_one_minus_g1p(rs, z, t) * (lak_one_minus_g2(rs, z, t) + lak_g3p(rs, z, t)), XC_MIN))

@helper
def lak_g3m(rs, z, t):
    return (m_max(Integer(1) - (lak_w1(rs,z)+lak_b3c) * lak_A(rs,z) * t**Integer(2), XC_EPSILON))**(-Integer(1))

@helper
def lak_H1m(rs, z, t):
    return lak_gamma*mphi(z)**Integer(3)*log(m_max(Integer(1) + lak_w1(rs,z) * (Integer(1) - lak_g1m(rs, z, t)) * (lak_one_minus_g2(rs, z, t) - lak_g3m(rs, z, t)), XC_MIN))

@helper
def lak_H1(rs, z, t):
    return my_piecewise3(lak_beta_t(rs) >=Integer(0), lak_H1p(rs,z,t), lak_H1m(rs,z,t) )

@helper
def lak_e1(rs, z, t):
    return f_pw(rs, z) + lak_H1(rs, z, t)

@helper
def lak_ec_rszta(rs, z, xt, a):
    return lak_e0(rs, z, gga_s_total(xt)) + (Integer(1)-lak_fc(rs, a)) * (lak_e1(rs, z, tt(rs, z, xt)) - lak_e0(rs, z, gga_s_total(xt))) * lak_gnum(gga_s_total(xt))

# Build the functional; alpha is the shared mgga_alpha_total from util.mpl

@helper
def lak_ec(rs, z, xt, xs0, xs1, ts0, ts1):
    return lak_ec_rszta(rs, z, xt, mgga_alpha_total(z, xt, ts0, ts1))

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return lak_ec(rs, z, xt, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
