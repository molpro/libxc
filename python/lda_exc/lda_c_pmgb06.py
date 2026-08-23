"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

alpha = (Integer(4)/(Integer(9)*pi))**(Integer(1)/Integer(3))

# Eq. (46) of Phys. Rev. A 73, 032506 (2006)
# I am not sure if this is the on-top pair correlation functional
# intended by the authors

g0_C = Float('0.08193')

g0_D = -Float('0.01277')

g0_E = Float('0.001859')

g0_dd = Float('0.7524')

g0_aHD = -alpha*(pi**Integer(2) + Integer(6)*log(Integer(2)) - Integer(3))/(Integer(5) * pi)

g0_B = -Integer(2)*g0_aHD - g0_dd

# KEEP IN SYNC: pmgb_g0, its polynomial part pmgb_g0_poly, and the
# pmgb_g0_m_half helper below.  pmgb_g0_poly has no constant term.

@helper
def pmgb_g0_poly(rs):
    return -g0_B*rs + g0_C*rs**Integer(2) + g0_D*rs**Integer(3) + g0_E*rs**Integer(4)

@helper
def pmgb_g0(rs):
    return (Integer(1) + pmgb_g0_poly(rs))*exp(-g0_dd*rs)/Integer(2)

# g0(rs) - 1/2, cancellation-free at small rs (high density) via
# (1+Q)*exp(-d*rs) - 1 = Q + (1+Q)*expm1(-d*rs).

@helper
def pmgb_g0_m_half(rs):
    return (
        (pmgb_g0_poly(rs)
        + (Integer(1) + pmgb_g0_poly(rs))*xc_expm1(-g0_dd*rs))/Integer(2)
    )

# text between eqs (23) and (24).
# pmgb_gc0 = g0(rs) - (1-z^2)/2 = (g0(rs) - 1/2) + z^2/2
#          = pmgb_g0_m_half(rs) + z^2/2,
# which fixes both the rs -> 0 cancellation (g0 -> 1/2) and is exact
# at z -> 0.

@helper
def pmgb_gc0(rs, z):
    return pmgb_g0_m_half(rs) + z**Integer(2)/Integer(2)

# Eq. (14)

@helper
def pmgb_phi(n, z):
    return (opz_pow_n(z,n/Integer(3)) + opz_pow_n(-z,n/Integer(3)))/Integer(2)

# Eq. (22)

pmgb_Q_a = Float('5.84605')

pmgb_Q_c = Float('3.91744')

pmgb_Q_d = Float('3.44851')

pmgb_Q_b = pmgb_Q_d - Integer(3)*pi*alpha/(Integer(4)*log(Integer(2)) - Integer(4))

# Algebraic identity:
# log(num/den) = log1p((num - den)/den).
# At small x both num and den approach 1, so log(num/den) is the
# catastrophic log-of-close-to-1.  The matching `1 + pmgb_Q_a*x`
# terms cancel exactly in num - den; the subtraction is written
# symbolically against pmgb_Q_num/_den helpers so the polynomials
# stay single-source -- Maple simplifies before codegen, so the
# emitted C is still cancellation-free and any future retuning of
# num/den flows through automatically.

@helper
def pmgb_Q_num(x):
    return Integer(1) + pmgb_Q_a*x + pmgb_Q_b*x**Integer(2) + pmgb_Q_c*x**Integer(3)

@helper
def pmgb_Q_den(x):
    return Integer(1) + pmgb_Q_a*x + pmgb_Q_d*x**Integer(2)

@helper
def pmgb_Q(x):
    return (
        ((Integer(2)*log(Integer(2)) - Integer(2))/pi**Integer(2)) * xc_log1p(
        (pmgb_Q_num(x) - pmgb_Q_den(x)) / pmgb_Q_den(x)
        )
    )

# Eq. (31)

@helper
def pmgb_b0(rs):
    return Float('0.784949')*rs

# Eq. (32)

@helper
def pmgb_gpp1(rs):
    return (
        (Integer(2)**(Integer(5)/Integer(3))/(Integer(5)*alpha**Integer(2)*rs**Integer(2))) *
        (Integer(1) - Float('0.02267')*rs)/(Integer(1) + Float('0.4319')*rs + Float('0.04')*rs**Integer(2))
    )

# Eq. (33)

@helper
def pmgb_D2(rs):
    return (-Float('0.388')*rs + Float('0.676')*rs**Integer(2))*exp(-Float('0.547')*rs)/rs**Integer(2)

# Eq. (34)

@helper
def pmgb_D3(rs):
    return (-Float('4.95')*rs + rs**Integer(2))*exp(-Float('0.31')*rs)/rs**Integer(3)

# Eq. (28)

@helper
def pmgb_cc4(rs, z):
    return (
        + (opz_pow_n( z,Integer(2))/Integer(4)) * pmgb_gpp1(rs*(Integer(2)/(Integer(1) + z))**(Integer(1)/Integer(3)))
        + (opz_pow_n(-z,Integer(2))/Integer(4)) * pmgb_gpp1(rs*(Integer(2)/(Integer(1) - z))**(Integer(1)/Integer(3)))
        + one_minus_z_pow_n(z, Integer(2)) * pmgb_D2(rs)
        - pmgb_phi(Integer(8), z)/(Integer(5)*alpha**Integer(2)*rs**Integer(2))
    )

# Eq. (29)

@helper
def pmgb_cc5(rs, z):
    return (
        + (opz_pow_n( z,Integer(2))/Integer(4)) * pmgb_gpp1(rs*(Integer(2)/(Integer(1) + z))**(Integer(1)/Integer(3)))
        + (opz_pow_n(-z,Integer(2))/Integer(4)) * pmgb_gpp1(rs*(Integer(2)/(Integer(1) - z))**(Integer(1)/Integer(3)))
        + one_minus_z_pow_n(z, Integer(2)) * pmgb_D3(rs)
    )

# Eq. (30)

@helper
def pmgb_C2(rs, z):
    return -Integer(3)*one_minus_z_pow_n(z, Integer(2))*pmgb_gc0(rs,z)/(Integer(8)*rs**Integer(3))

@helper
def pmgb_C3(rs, z):
    return -one_minus_z_pow_n(z, Integer(2))*pmgb_g0(rs)/(sqrt(Integer(2)*pi)*rs**Integer(3))

@helper
def pmgb_C4(rs, z):
    return -Integer(9)*pmgb_cc4(rs, z)/(Integer(64)*rs**Integer(3))

@helper
def pmgb_C5(rs, z):
    return -Integer(9)*pmgb_cc5(rs, z)/(Integer(40)*sqrt(Integer(2)*pi)*rs**Integer(3))

@helper
def pmgb_a1(rs, z):
    return Integer(4)*pmgb_b0(rs)**Integer(6)*pmgb_C3(rs, z) + pmgb_b0(rs)**Integer(8)*pmgb_C5(rs, z)

@helper
def pmgb_a2(rs, z):
    return (
        Integer(4)*pmgb_b0(rs)**Integer(6)*pmgb_C2(rs, z) + pmgb_b0(rs)**Integer(8)*pmgb_C4(rs, z)
        + Integer(6)*pmgb_b0(rs)**Integer(4)*f_pw(rs, z)
    )

@helper
def pmgb_a3(rs, z):
    return pmgb_b0(rs)**Integer(8)*pmgb_C3(rs, z)

@helper
def pmgb_a4(rs, z):
    return pmgb_b0(rs)**Integer(8)*pmgb_C2(rs, z) + Integer(4)*pmgb_b0(rs)**Integer(6)*f_pw(rs, z)

@helper
def pmgb_a5(rs, z):
    return pmgb_b0(rs)**Integer(8)*f_pw(rs, z)

# Eq. (26)

@helper
def pmgb_ec_LR(rs, z):
    return (
        (
        + pmgb_phi(Integer(2), z)**Integer(3)*pmgb_Q(p_a_cam_omega*sqrt(rs)/pmgb_phi(Integer(2), z))
        + pmgb_a1(rs, z)*p_a_cam_omega**Integer(3)
        + pmgb_a2(rs, z)*p_a_cam_omega**Integer(4)
        + pmgb_a3(rs, z)*p_a_cam_omega**Integer(5)
        + pmgb_a4(rs, z)*p_a_cam_omega**Integer(6)
        + pmgb_a5(rs, z)*p_a_cam_omega**Integer(8)
        )/(Integer(1) + pmgb_b0(rs)**Integer(2)*p_a_cam_omega**Integer(2))**Integer(4)
    )

def f(rs, z):
    return pmgb_ec_LR(rs, z)

TYPE = "lda_exc"
