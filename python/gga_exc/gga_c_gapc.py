"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_a = param_default("a")

define('lda_c_pw_params')
include('lda_c_pw')

# Parameters from Table 6
# a1, a2, a3
# b3, b4, b5, b6, b7
# params_a_a of lda_c_pw
# pre-factor of C = 0.06483*((9*Pi)/4)^(2/3)

gap_par0 = maple_list([ Float('0.04953'), Float('1.07924'), Float('0.07928'), -Float('2.504e-2'), Float('7.026e-3'), -Float('1.268e-3'), Float('1.136e-4'), -Float('3.841e-6'), Float('0.031091'), Float('0.23878') ])

gap_par1 = maple_list([ Float('0.0471985'), Float('1.49676'), Float('0.00179054'), -Float('3.24091e-2'), Float('9.99978e-3'), -Float('1.93483e-3'), Float('1.79118e-4'), -Float('6.15798e-6'), Float('0.015545'), Float('0.064535') ])

# Equation (20): e'(rs)

@helper
def gap_eps_1(rs, par):
    return par[Integer(1)]*rs**(Integer(3)/Integer(2))/(Integer(1) + sqrt(rs)*(par[Integer(2)] + par[Integer(3)]*sqrt(rs) + par[Integer(1)]*rs))

# Equation (21): e''(rs)

@helper
def gap_eps_2(rs, par):
    return sum((par[i+Integer(1)]*rs**i) for i in range(Integer(3), (Integer(7)) + Integer(1)))

# Equation (19)

@helper
def gap_C(rs, par):
    return par[Integer(10)]/rs**Integer(2)

# Equation (17)

@helper
def gap_c2(rs, z, par):
    return (
        + (Integer(2)*f_pw(rs, z)*gap_eps_1(rs, par) - gap_C(rs, par)*gap_eps_2(rs, par))
        / (Integer(2)*(gap_C(rs, par)*gap_eps_1(rs, par) - f_pw(rs, z)**Integer(2)))
    )

# Equation (18)

@helper
def gap_c3(rs, z, par):
    return (
        - (Integer(2)*gap_eps_1(rs, par)**Integer(2) - f_pw(rs, z)*gap_eps_2(rs, par))
        / (Integer(2)*(gap_C(rs, par)*gap_eps_1(rs, par) - f_pw(rs, z)**Integer(2)))
    )

# Equation (16)

@helper
def gap_c1(rs, z, par):
    return - gap_C(rs, par) * gap_c3(rs, z, par)

# after Equation (6): a = 30 is a parameter fixed by minimizing the
# variance of the correlation energy error for the noble gas atoms He,
# Ne, and Ar

gap_par_a = Integer(30)

# Equation (6)

@helper
def gap_H(rs, t, par):
    return (gap_par_a  + par[Integer(9)]*rs*log(rs)*t**Integer(2)/beta_Hu_Langreth(rs))/(gap_par_a + t**Integer(2))

@helper
def gap_t(rs, z, xt):
    return xt*n_total(rs)**(Integer(1)/Integer(6))/(Integer(4)*mphi(z)*(Integer(3)/pi)**(Integer(1)/Integer(6)))

# Gap function, Equation (5)

@helper
def gap_G(rs, z, xt, par):
    return (
        + mphi(z)**Integer(3)*beta_Hu_Langreth(rs)*gap_t(rs, z, xt)**Integer(2)
        * gap_H(rs, gap_t(rs, z, xt), par)
        / (gap_c1(rs, z, par) - gap_c2(rs, z, par)*f_pw(rs, z))
    )

# Correlation energy per particle, Equation (4)

@helper
def gap_eps(rs, z, xt, par):
    return (
        + (f_pw(rs, z) + gap_c1(rs, z, par)*gap_G(rs, z, xt, par))
        / (Integer(1) + gap_c2(rs, z, par)*gap_G(rs, z, xt, par) + gap_c3(rs, z, par)*gap_G(rs, z, xt, par)**Integer(2))
    )

# Total energy, Equation (2)

@helper
def f_gap(rs, z, xt):
    return (
        + gap_eps(rs, Integer(0), xt, gap_par0)
        + f_zeta(z)*(gap_eps(rs, Integer(1), xt, gap_par1) - gap_eps(rs, Integer(0), xt, gap_par0))
    )

def f(rs, z, xt, xs0, xs1):
    return f_gap(rs, z, xt)

TYPE = "gga_exc"
