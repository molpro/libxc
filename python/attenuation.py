"""
 Copyright (C) 2017 M.A.L. Marques
               2020-2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

# NOTE: the implementations in this file are for short-range exchange functionals.
# The naming merely implicates which type of kernel is used.

# error function:
# Toulouse et al, Int. J. Quantum Chem. 100, 1047 (2004); doi:10.1002/qua.20259
# Tawada et al, J. Chem. Phys. 120, 8425 (2004); doi:10.1063/1.1688752
#
# The implementation follows Tawada et al.

@helper
def att_erf_aux1(a):
    return sqrt(pi)*erf(Integer(1)/(Integer(2)*a))

@helper
def att_erf_aux2(a):
    return xc_expm1(-Integer(1)/(Integer(4)*a**Integer(2)))

@helper
def att_erf_aux3(a):
    return Integer(2)*a**Integer(2)*att_erf_aux2(a) + Integer(1)/Integer(2)

# This is the full function, which is numerically unstable for large a

@helper
def attenuation_erf0(a):
    return Integer(1) - Integer(8)/Integer(3)*a*(att_erf_aux1(a) + Integer(2)*a*(att_erf_aux2(a) - att_erf_aux3(a)))

# The cutoff and order are determined by check_attenuation.mpl

@helper
def attenuation_erf(a):
    return enforce_smooth_lr(attenuation_erf0, a, Float('1.35'), Integer(16))

# Cancellation-free 1 - attenuation_erf.  The direct subtraction
# loses precision at small a (high density / small omega) where
# attenuation_erf -> 1; this primitive evaluates the explicit
# 8/3 a (...)  form that the original 1 - 8/3 a (...) cancels
# into.  The smooth-large-a wrap reuses the same cutoff/order as
# attenuation_erf so the two stay matched.

@helper
def one_minus_attenuation_erf0(a):
    return Integer(8)/Integer(3)*a*(att_erf_aux1(a) + Integer(2)*a*(att_erf_aux2(a) - att_erf_aux3(a)))

@helper
def one_minus_attenuation_erf(a):
    return enforce_smooth_lr(one_minus_attenuation_erf0, a, Float('1.35'), Integer(16))

# These are for hyb_mgga_x_js18 and hyb_mgga_x_pjs18. This is the
# bracket in eqn (10) in Patra et al, 2018

@helper
def attenuation_erf_f20(a):
    return (
        Integer(1) + Integer(24)*a**Integer(2)*( (Integer(20)*a**Integer(2) - Integer(64)*a**Integer(4))*exp(-Integer(1)/(Integer(4)*a**Integer(2)))
        - Integer(3) - Integer(36)*a**Integer(2) + Integer(64)*a**Integer(4)
        + Integer(10)*a*sqrt(pi)*erf(Integer(1)/(Integer(2)*a)))
    )

# The cutoff and order are determined by check_attenuation.mpl

@helper
def attenuation_erf_f2(a):
    return enforce_smooth_lr(attenuation_erf_f20, a, Float('0.27'), Integer(46))

# This is eqn (11) in Patra et al, 2018

@helper
def attenuation_erf_f30(a):
    return (
        Integer(1) + Integer(8)/Integer(7)*a*(
        (-Integer(8)*a + Integer(256)*a**Integer(3) - Integer(576)*a**Integer(5) + Integer(3840)*a**Integer(7) - Integer(122880)*a**Integer(9))*exp(-Integer(1)/(Integer(4)*a**Integer(2)))
        + Integer(24)*a**Integer(3)*(-Integer(35) + Integer(224)*a**Integer(2) - Integer(1440)*a**Integer(4) + Integer(5120)*a**Integer(6))
        + Integer(2)*sqrt(pi)*(-Integer(2) + Integer(60)*a**Integer(2))*erf(Integer(1)/(Integer(2)*a)))
    )

# The cutoff and order are determined by check_attenuation.mpl

@helper
def attenuation_erf_f3(a):
    return enforce_smooth_lr(attenuation_erf_f30, a, Float('0.32'), Integer(38))

# erf_gau - screening function = + 2 mu/sqrt(pi) exp(-mu^2 r^2)
# Song et al, J. Chem. Phys. 127, 154109 (2007); doi:10.1063/1.2790017
# You can recover the result in Int. J. Quantum Chem. 100, 1047 (2004)
# by putting a = a/sqrt(3) and multiplying the whole attenuation function by -sqrt(3)

@helper
def attenuation_gau0(a):
    return -Integer(8)/Integer(3)*a*(att_erf_aux1(a) + Integer(2)*a*att_erf_aux2(a)*(Integer(1) - Integer(8)*a**Integer(2)) - Integer(4)*a)

# The cutoff and order are determined by check_attenuation.mpl

@helper
def attenuation_gau(a):
    return enforce_smooth_lr(attenuation_gau0, a, Float('2.07'), Integer(14))

# yukawa
# Akinaga and Ten-no, Chem. Phys. Lett. 462, 348 (2008); doi:10.1016/j.cplett.2008.07.103

@helper
def att_yuk_aux1(a):
    return atan2(Integer(1), a)

@helper
def att_yuk_aux2(a):
    return xc_log1p(Integer(1)/a**Integer(2))

@helper
def att_yuk_aux3(a):
    return a**Integer(2) + Integer(1)

@helper
def attenuation_yukawa0(a):
    return Integer(1) - Integer(8)/Integer(3)*a*(att_yuk_aux1(a) + a/Integer(4)*(Integer(1) - (att_yuk_aux3(a) + Integer(2))*att_yuk_aux2(a)))

# The cutoff and order are determined by check_attenuation.mpl

@helper
def attenuation_yukawa(a):
    return enforce_smooth_lr(attenuation_yukawa0, a, Float('1.92'), Integer(36))

# Cancellation-free 1 - attenuation_yukawa.  Mirrors
# one_minus_attenuation_erf: the direct subtraction cancels at
# small a (high density) where attenuation_yukawa -> 1; this
# primitive evaluates the explicit 8/3 a (...) form.

@helper
def one_minus_attenuation_yukawa0(a):
    return Integer(8)/Integer(3)*a*(att_yuk_aux1(a) + a/Integer(4)*(Integer(1) - (att_yuk_aux3(a) + Integer(2))*att_yuk_aux2(a)))

@helper
def one_minus_attenuation_yukawa(a):
    return enforce_smooth_lr(one_minus_attenuation_yukawa0, a, Float('1.92'), Integer(36))
