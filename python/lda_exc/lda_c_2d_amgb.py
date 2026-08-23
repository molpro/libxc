"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

w = Symbol("w")

define('xc_dimensions_2d')

amgb_aa = maple_list([ -Float('0.1925'),     Float('0.117331'),    Float('0.0234188') ])

amgb_bb = maple_list([  Float('0.0863136'), -Float('3.394e-2'),   -Float('0.037093')  ])

amgb_cc = maple_list([  Float('0.0572384'), -Float('7.66765e-3'),  Float('0.0163618') ])

amgb_ee = maple_list([  Float('1.0022'),     Float('0.4133'),      Float('1.424301')  ])

amgb_ff = maple_list([ -Float('0.02069'),    Integer(0),         Integer(0)       ])

amgb_gg = maple_list([  Float('0.33997'),    Float('6.68467e-2'),  Integer(0)       ])

amgb_hh = maple_list([  Float('1.747e-2'),   Float('7.799e-4'),    Float('1.163099')  ])

amgb_ax = -Integer(4)/(Integer(3)*pi*sqrt(Integer(2)))

amgb_beta = Float('1.3386')

amgb_dd = maple_list([(-amgb_aa[i]*amgb_hh[i]) for i in range(Integer(1), (Integer(3)) + Integer(1))])

@helper
def amgb_alpha(i, rs):
    return (
        amgb_aa[i]
        + (amgb_bb[i]*rs + amgb_cc[i]*rs**Integer(2) + amgb_dd[i]*rs**Integer(3))
        * xc_log1p(Integer(1)/(amgb_ee[i]*rs + amgb_ff[i]*rs**Float('1.5') + amgb_gg[i]*rs**Integer(2) + amgb_hh[i]*rs**Integer(3)))
    )

# f_zeta_2d_m1(z) Taylor at z = 0 starts as 3z^2/8 + 3z^4/128 +
# 7z^6/1024 + ..., so the direct
# f_zeta_2d_m1(z) - 3z^2/8 - 3z^4/128
# cancels to O(z^6) at small z, losing log10(3z^2/8 / (7z^6/1024))
# ~ 2*log10(1/z) - 1 digits.  Use a Maple Taylor polynomial of the
# residual for |z| < 1/2 (where the series converges fast enough to
# stay ULP-accurate with reasonable order) and the direct form
# otherwise.  Order 32 (4 derivatives + ~26 series terms) keeps the
# 4th-derivative truncation below XC_EPSILON at the cutoff.

@helper
def amgb_ex6_residual_orig(z):
    return f_zeta_2d_m1(z) - Integer(3)/Integer(8)*z**Integer(2) - Integer(3)/Integer(128)*z**Integer(4)

# For the series input we use the elementary form of f_zeta_2d_m1,
# ((1+z)^(3/2) + (1-z)^(3/2))/2 - 1.  This equals f_zeta_2d_m1 in its
# generic branch (the opz_pow_n_m1 clamp only fires at z -> -1, never
# at the z=0 expansion point), and is needed because the inert
# opz_pow_n_m1 / my_piecewise3 inside f_zeta_2d_m1 cannot be series-
# expanded by Maple.

@helper
def amgb_ex6_residual_taylor(z):
    return maple_eval(convert(maple_series(((Integer(1)+w)**(Integer(3)/Integer(2)) + (Integer(1)-w)**(Integer(3)/Integer(2)))/Integer(2) - Integer(1) - Integer(3)/Integer(8)*w**Integer(2) - Integer(3)/Integer(128)*w**Integer(4), w, Integer(0), Integer(32)), polynom), w, z)

@helper
def amgb_ex6_residual(z):
    return (
        my_piecewise3(m_abs(z) < Integer(1)/Integer(2),
        amgb_ex6_residual_taylor(z),
        amgb_ex6_residual_orig(z))
    )

@helper
def amgb_ex6(rs, z):
    return -Integer(4)*sqrt(Integer(2))/(Integer(3)*pi*rs) * amgb_ex6_residual(z)

@helper
def f_amgb(rs, z):
    return amgb_alpha(Integer(1), rs) + amgb_alpha(Integer(2), rs)*z**Integer(2) + amgb_alpha(Integer(3), rs)*z**Integer(4) + xc_expm1(-amgb_beta*rs)*amgb_ex6(rs, z)

def f(rs, z):
    return f_amgb(rs, z)

TYPE = "lda_exc"
