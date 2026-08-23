"""
 2018 Authored by Andrea Kreppel
 2022 Edited by Henryk Laqua

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.

 Short-range (erfc) Perdew Wang correlation functional according to
 S. Paziani, S. Moroni, P. Gori-Giorgi, and G. B. Bachelet.,  Phys. Rev. B 73, 155111 (2006).
 DOI:10.1103/PhysRevB.73.155111
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

#$define lda_x_params
define('lda_c_pw_params')
#$include "lda_x.mpl"
include('lda_c_pw')

# params

lda_c_pw_erf_mu = p_a_cam_omega

@helper
def lda_c_pw_erf_b0(rs):
    return Float('0.784949')*rs

lda_c_pw_erf_alpha = (Integer(4)/(Integer(9)*pi))**(Integer(1)/Integer(3))

# params below eq. (22)

lda_c_pw_erf_ac = Float('5.84605')

lda_c_pw_erf_c = Float('3.91744')

lda_c_pw_erf_d = Float('3.44851')

lda_c_pw_erf_bc = lda_c_pw_erf_d - Integer(3)*pi*lda_c_pw_erf_alpha/(Integer(4)*log(Integer(2))-Integer(4))

# eq. (22).  Algebraic identity:
# log(num/den) = log(1 + (num - den)/den) = log1p((num - den)/den).
# At small x both num and den approach 1, so log(num/den) is the
# catastrophic log-of-close-to-1.  The matching `1 + ac*x` terms
# cancel exactly in num - den; the subtraction is written
# symbolically against the lda_c_pw_erf_Q_num/_den helpers so the
# polynomials stay single-source -- Maple simplifies before codegen,
# so the emitted C is still cancellation-free and any future
# retuning of num/den flows through automatically.

@helper
def lda_c_pw_erf_Q_num(x):
    return Integer(1) + lda_c_pw_erf_ac*x + lda_c_pw_erf_bc*x**Integer(2) + lda_c_pw_erf_c*x**Integer(3)

@helper
def lda_c_pw_erf_Q_den(x):
    return Integer(1) + lda_c_pw_erf_ac*x + lda_c_pw_erf_d*x**Integer(2)

@helper
def lda_c_pw_erf_Q(x):
    return (
        (Integer(2)*log(Integer(2))-Integer(2))*xc_log1p(
        (lda_c_pw_erf_Q_num(x) - lda_c_pw_erf_Q_den(x)) / lda_c_pw_erf_Q_den(x))/pi**Integer(2)
    )

# eq. (14)

@helper
def lda_c_pw_erf_phin(n, z):
    return Integer(1)/Integer(2)*(opz_pow_n(z, n/Integer(3)) + opz_pow_n(-z, n/Integer(3)))

# eq. (32)

@helper
def lda_c_pw_erf_g1(rs):
    return Integer(2)**(Integer(5)/Integer(3))*(Integer(1)-Float('0.02267')*rs)/(Integer(5)*lda_c_pw_erf_alpha**Integer(2)*rs**Integer(2)*(Integer(1)+Float('0.4319')*rs+Float('0.04')*rs**Integer(2)))

# g(0,rs,zeta) below eq.(23).
# KEEP IN SYNC: g0, its polynomial part g0_poly, and g0c.
# g0 = 1/2*(1 + g0_poly)*exp(-d*rs) with g0_poly having no constant
# term, so g0c = g0 - 1/2 cancels to O(rs) at small rs (high
# density).  Identity (1+Q)*exp(-d*rs) - 1 = Q + (1+Q)*expm1(-d*rs)
# gives the cancellation-free form below.

@helper
def lda_c_pw_erf_g0_poly(rs):
    return Float('0.0207')*rs + Float('0.08193')*rs**Integer(2) - Float('0.01277')*rs**Integer(3) + Float('0.001859')*rs**Integer(4)

@helper
def lda_c_pw_erf_g0(rs):
    return Integer(1)/Integer(2)*(Integer(1) + lda_c_pw_erf_g0_poly(rs))*exp(-Float('0.7524')*rs)

# g_c(0,rs,zeta) below eq.(23)

@helper
def lda_c_pw_erf_g0c(rs):
    return (
        Integer(1)/Integer(2)*(lda_c_pw_erf_g0_poly(rs)
        + (Integer(1) + lda_c_pw_erf_g0_poly(rs))*xc_expm1(-Float('0.7524')*rs))
    )

# eq. (33)

@helper
def lda_c_pw_erf_D2(rs):
    return exp(-Float('0.547')*rs)*(-Float('0.388')*rs+Float('0.676')*rs**Integer(2))/rs**Integer(2)

# eq. (34)

@helper
def lda_c_pw_erf_D3(rs):
    return exp(-Float('0.31')*rs)*(-Float('4.95')*rs+rs**Integer(2))/rs**Integer(3)

# eq. (30)

@helper
def lda_c_pw_erf_C2(rs, z):
    return -Integer(3)*one_minus_z_pow_n(z, Integer(2))*lda_c_pw_erf_g0c(rs)/(Integer(8)*rs**Integer(3))

@helper
def lda_c_pw_erf_C3(rs, z):
    return -one_minus_z_pow_n(z, Integer(2))*lda_c_pw_erf_g0(rs)/(sqrt(Integer(2)*pi)*rs**Integer(3))

# eq. (28)

@helper
def lda_c_pw_erf_c4_l(rs, z):
    return ((Integer(1)+z)/Integer(2))**Integer(2) * lda_c_pw_erf_g1(rs*(Integer(2)/(Integer(1)+z))**(Integer(1)/Integer(3))) + ((Integer(1)-z)/Integer(2))**Integer(2) * lda_c_pw_erf_g1(rs*(Integer(2)/(Integer(1)-z))**(Integer(1)/Integer(3))) + one_minus_z_pow_n(z, Integer(2))*lda_c_pw_erf_D2(rs)-lda_c_pw_erf_phin(Integer(8),z)/(Integer(5)*lda_c_pw_erf_alpha**Integer(2)*rs**Integer(2))

@helper
def lda_c_pw_erf_C4(rs, z):
    return -Integer(9)*lda_c_pw_erf_c4_l(rs,z)/(Integer(64)*rs**Integer(3))

# eq. (29)

@helper
def lda_c_pw_erf_c5_l(rs, z):
    return ((Integer(1)+z)/Integer(2))**Integer(2) * lda_c_pw_erf_g1(rs*(Integer(2)/(Integer(1)+z))**(Integer(1)/Integer(3))) + ((Integer(1)-z)/Integer(2))**Integer(2) * lda_c_pw_erf_g1(rs*(Integer(2)/(Integer(1)-z))**(Integer(1)/Integer(3))) + one_minus_z_pow_n(z, Integer(2))*lda_c_pw_erf_D3(rs)

@helper
def lda_c_pw_erf_C5(rs, z):
    return -Integer(9)*lda_c_pw_erf_c5_l(rs,z)/(Integer(40)*sqrt(Integer(2)*pi)*rs**Integer(3))

# params below eq. 29

@helper
def lda_c_pw_erf_a1(rs, z):
    return Integer(4)*lda_c_pw_erf_b0(rs)**Integer(6)*lda_c_pw_erf_C3(rs,z) + lda_c_pw_erf_b0(rs)**Integer(8)*lda_c_pw_erf_C5(rs,z)

@helper
def lda_c_pw_erf_a2(rs, z):
    return Integer(4)*lda_c_pw_erf_b0(rs)**Integer(6)*lda_c_pw_erf_C2(rs,z) + lda_c_pw_erf_b0(rs)**Integer(8)*lda_c_pw_erf_C4(rs,z) + Integer(6)*lda_c_pw_erf_b0(rs)**Integer(4)*f_pw(rs,z)

@helper
def lda_c_pw_erf_a3(rs, z):
    return lda_c_pw_erf_b0(rs)**Integer(8)*lda_c_pw_erf_C3(rs,z)

@helper
def lda_c_pw_erf_a4(rs, z):
    return lda_c_pw_erf_b0(rs)**Integer(8)*lda_c_pw_erf_C2(rs,z) + Integer(4)*lda_c_pw_erf_b0(rs)**Integer(6)*f_pw(rs,z)

@helper
def lda_c_pw_erf_a5(rs, z):
    return lda_c_pw_erf_b0(rs)**Integer(8)*f_pw(rs,z)

# eq. 26)

@helper
def lda_c_pw_erf_f(rs, z):
    return f_pw(rs,z)-(lda_c_pw_erf_phin(Integer(2),z)**Integer(3)*lda_c_pw_erf_Q(lda_c_pw_erf_mu*sqrt(rs)/(lda_c_pw_erf_phin(Integer(2),z))) + lda_c_pw_erf_a1(rs,z)*lda_c_pw_erf_mu**Integer(3) + lda_c_pw_erf_a2(rs,z)*lda_c_pw_erf_mu**Integer(4) + lda_c_pw_erf_a3(rs,z)*lda_c_pw_erf_mu**Integer(5) + lda_c_pw_erf_a4(rs,z)*lda_c_pw_erf_mu**Integer(6) + lda_c_pw_erf_a5(rs,z)*lda_c_pw_erf_mu**Integer(8) )/((Integer(1)+lda_c_pw_erf_b0(rs)**Integer(2)*lda_c_pw_erf_mu**Integer(2))**Integer(4))

def f(rs, z):
    return lda_c_pw_erf_f(rs,z)

TYPE = "lda_exc"
