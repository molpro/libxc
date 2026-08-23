"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

# Equations are from the Appendix of Kurth1999_889

include('gga_c_gapc')

gap_par0[10] = Float('0.06483')*((Integer(9)*pi)/Integer(4))**(Integer(2)/Integer(3))

# this is approximately equal to 0.23878

# Eq. (A4)

@helper
def kcis_G(rs, xt):
    return xt**Integer(2)*n_total(rs)**(Integer(2)/Integer(3))/Integer(8)

# Eq. (A9)

@helper
def kcis_t(rs, xt):
    return Integer(2)**(Integer(2)/Integer(3))*xt/(Integer(8)*sqrt(rs))

kcis_beta = Float('0.066725')

# Eq. (A7)

@helper
def kcis_gga0(rs, xt):
    return f_pw(rs, Integer(0))/(Integer(1) + kcis_beta*xc_log1p(kcis_t(rs, xt)**Integer(2)/m_abs(f_pw(rs, Integer(0)))))

# Eq. (A8)

@helper
def kcis_gga1(rs, xt):
    return f_pw(rs, Integer(1))/(Integer(1) + kcis_beta*xc_log1p(Integer(2)**(-Integer(1)/Integer(3))*kcis_t(rs, xt)**Integer(2)/m_abs(f_pw(rs, Integer(1)))))

# Eq. (A5)

# The polarized parameters are the same as the unpolarized ones

# except that c_1, c_2, c_3 are multiplied by 0.7. 1.5, and 2.59 respectively

@helper
def kcis_eps_0(rs, xt):
    return (
        + (kcis_gga0(rs, xt) + gap_c1(rs, Integer(0), gap_par0)*kcis_G(rs, xt))
        / (Integer(1) + gap_c2(rs, Integer(0), gap_par0)*kcis_G(rs, xt) + gap_c3(rs, Integer(0), gap_par0)*kcis_G(rs, xt)**Integer(2))
    )

# Eq. (A6)

@helper
def kcis_eps_1(rs, xt):
    return (
        + (kcis_gga1(rs, xt) + Float('0.7')*gap_c1(rs, Integer(0), gap_par0)*kcis_G(rs, xt))
        / (Integer(1) + Float('1.5')*gap_c2(rs, Integer(0), gap_par0)*kcis_G(rs, xt) + Float('2.59')*gap_c3(rs, Integer(0), gap_par0)*kcis_G(rs, xt)**Integer(2))
    )

# Eq. (A2)

@helper
def gap_f(rs, z, xt):
    return (
        + kcis_eps_0(rs, xt)
        + f_zeta(z)*(kcis_eps_1(rs, xt) - kcis_eps_0(rs, xt))
    )

# Eq. (A1)

@helper
def kcis_f(rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        + gap_f(rs, z, xt)
        - xs0**Integer(2)/(Integer(8)*ts0) * opz_pow_n( z,Integer(1))/Integer(2) * gap_f(rs*(Integer(2)/(Integer(1) + z))**(Integer(1)/Integer(3)),  Integer(1), xs0)
        - xs1**Integer(2)/(Integer(8)*ts1) * opz_pow_n(-z,Integer(1))/Integer(2) * gap_f(rs*(Integer(2)/(Integer(1) - z))**(Integer(1)/Integer(3)), -Integer(1), xs1)
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return kcis_f(rs, z, xt, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
