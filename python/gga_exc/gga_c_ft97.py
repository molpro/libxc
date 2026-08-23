"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

C0 = (Integer(1) - log(Integer(2)))/(Integer(2)*pi**Integer(2))

# Equation (9)

C1 = Integer(4)*C0/Integer(3)

# Equations (13), (28), (33)

C2 = RS_FACTOR

# Equation (8)

C3 = C2/Integer(3)

# several cutoffs

big = Float('1.0e4')

cutoff = Float('1.0e7')

ei_xmax = Float('7.0183341467e+02')

# Equation (39)

kssp0_k0 = Float('1.291551074')

kssp0_k1 = Float('0.349064173')

kssp0_r1 = Float('0.08327588')

@helper
def kssp0(rs):
    return kssp0_k0 - kssp0_k1*(-xc_expm1(-kssp0_r1*rs**(Integer(4)/Integer(5))))

# Equation (45)

fssp_A1 = Float('1.622118767')

fssp_A2 = Float('0.489958076')

fssp_A3 = Float('1.379021941')

@helper
def fssp(rs, gr):
    return (Integer(1) + fssp_A1*gr + fssp_A2**Integer(2)*gr**Integer(2))*exp(-fssp_A2**Integer(2)*gr**Integer(2))/sqrt(Integer(1) + fssp_A3*gr/rs)

# Equation (34)

fa_a1 = Float('0.939016')

fa_a2 = Float('1.733170')

@helper
def f_factor(rs):
    return exp(-rs**Integer(2)/(fa_a1*sqrt(rs) + fa_a2*rs)**Integer(2))

# Equation (40)

kss0_k0 = Float('1.200801774')

kss0_k1 = Float('0.859614445')

kss0_k2 = -Float('0.812904345')

kss0_r1 = Float('1.089338848')

kss0_r2 = Float('0.655638823')

# gr is unused -- kss0 depends only on rs

@helper
def kss0(rs):
    return (
        + kss0_k0
        + kss0_k1*(-xc_expm1(-kss0_r1*sqrt(rs)))
        + kss0_k2*(-xc_expm1(-kss0_r2*rs**(Integer(2)/Integer(5))))
    )

fss_A4 = Float('4.946281353')

fss_A5 = Float('3.600612059')

@helper
def fss(rs, gr):
    return (Integer(1) + fss_A4**Integer(2)*gr**Integer(2))*exp(-fss_A4**Integer(2)*gr**Integer(2))/sqrt(Integer(1) + fss_A5*gr/rs)

# Equation (15)

@helper
def eq15(mu):
    return (Integer(3) + Integer(2)*(sqrt(mu) + mu))/(Integer(3) + Integer(6)*(sqrt(mu) + mu))

@helper
def f_eab(mu):
    return C0*(-xc_E1_scaled(mu)*(Integer(1) + Integer(2)*mu*eq15(mu)) + Integer(2)*eq15(mu))

# Equation (13)

#
# This is numerically suboptimal - the max function cuts off f_eab to
# around 10^-6. This is too large. The other possibility that was used
# before in the code was to put term to zero if mu > ei_xmax

@helper
def mu_ba(rsa, ga2):
    return C1*rsa/m_max(kssp0(rsa)**Integer(2)*fssp(rsa, ga2)**Integer(2), Float('1e-60'))

@helper
def term1(rsa, z, ga2):
    return (
        my_piecewise3(mu_ba(rsa, ga2) >= cutoff, Integer(0),
        f_eab(mu_ba(rsa, ga2))*(Integer(1) - z)/Integer(2))
    )

@helper
def mu_aa(rsa, ga2):
    return C1*rsa/m_max(kss0(rsa)**Integer(2)*fss(rsa, ga2)**Integer(2), Float('1e-60'))

@helper
def term2(rsa, z, ga2):
    return (
        my_piecewise3(mu_aa(rsa, ga2) >= cutoff, Integer(0),
        f_eab(mu_aa(rsa, ga2))*f_factor(rsa)*(Integer(1) + z)/Integer(2))
    )

@helper
def f_ft97(rs, z, xs):
    return (
        + term1(rs*(Integer(2)/(Integer(1) + z))**(Integer(1)/Integer(3)), z, C3**Integer(2)*xs**Integer(2))
        + term2(rs*(Integer(2)/(Integer(1) + z))**(Integer(1)/Integer(3)), z, C3**Integer(2)*xs**Integer(2))
    )

def f(rs, z, xt, xs0, xs1):
    return f_ft97(rs, z, xs0) + f_ft97(rs, -z, xs1)

TYPE = "gga_exc"
