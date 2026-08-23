"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('lda_c_pw_params')
include('lda_c_pw')

pw91_C_c0 = Float('4.235e-3')

pw91_alpha = Float('0.09')

pw91_nu = Integer(16)/pi * (Integer(3)*pi**Integer(2))**(Integer(1)/Integer(3))

pw91_beta = pw91_nu*pw91_C_c0

pw91_c1 = pw91_beta**Integer(2)/(Integer(2)*pw91_alpha)

pw91_c2 = Integer(2)*pw91_alpha/pw91_beta

# Equation (14)

@helper
def A(rs, z):
    return pw91_c2/xc_expm1(-Integer(2)*pw91_alpha*f_pw(rs, z)/(mphi(z)**Integer(3)*pw91_beta**Integer(2)))

# Equation (13)

@helper
def H0(rs, z, t):
    return (
        pw91_c1*mphi(z)**Integer(3)*xc_log1p(
        pw91_c2*(t**Integer(2) + A(rs, z)*t**Integer(4)) / (Integer(1) + A(rs, z)*t**Integer(2) + A(rs, z)**Integer(2)*t**Integer(4))
        )
    )

# Pade parametrized form of C-xc found in
# M Rasolt & DJW Geldart, Phys. Rev. B 34, 1325 (1986)

RS_a = maple_list([Float('2.568'), Float('23.266'), Float('0.007389')])

RS_b = maple_list([Integer(1), Float('8.723'), Float('0.472')])

@helper
def RG_C_xc(rs):
    return (RS_a[Integer(1)] + RS_a[Integer(2)]*rs + RS_a[Integer(3)]*rs**Integer(2))/(Integer(1000)*(RS_b[Integer(1)] + RS_b[Integer(2)]*rs + RS_b[Integer(3)]*rs**Integer(2)))

# Equation (15)

C_xc0 = Float('2.568e-3')

C_x = -Float('0.001667')

h_a1 = -Integer(100) * Integer(4)/pi * (Integer(4)/(Integer(9)*pi))**(Integer(1)/Integer(3))

@helper
def H1(rs, z, t):
    return (
        pw91_nu * (RG_C_xc(rs) - C_xc0 - Integer(3)*C_x/Integer(7))
        * mphi(z)**Integer(3)*t**Integer(2)*exp(h_a1*rs*mphi(z)**Integer(4)*t**Integer(2))
    )

@helper
def f_pw91(rs, z, xt, xs0, xs1):
    return f_pw(rs, z) + H0(rs, z, tt(rs, z, xt)) + H1(rs, z, tt(rs, z, xt))

def f(rs, z, xt, xs0, xs1):
    return f_pw91(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
