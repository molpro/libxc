"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

# This was checked against code kindly provided by Emil Proynov

# Equations (24)

a_24_i = maple_list([-Float('113.693369789727190'), Float('24.00502151278711440'), Float('49.34131295839670750'), -Float('23.8242372168379302'), Float('0.944080741695104794'), Float('0.000293039144178338')])

b_24_i = maple_list([-Float('109.74263493216910'), Float('16.2663129444242415'), Float('54.4034331373908366'), -Float('25.154009904187990'), Float('1.0')])

# den_b vanishes at rs ~ 22.74 (the dilute tail), giving f_r a pole there;
# screen the rational at that point. f_r is otherwise FP-stable across its whole
# domain -- no cancellation, smooth at rs=0 -- so no Taylor branch is needed.

DETOL = Float('0.1e-11')

@helper
def f_r_num(rs):
    return sum((a_24_i[i]*rs**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1)))

@helper
def f_r_den(rs):
    return sum((b_24_i[i]*rs**(i-Integer(1))) for i in range(Integer(1), (Integer(5)) + Integer(1)))

@helper
def f_r(rs):
    return my_piecewise3(m_abs(f_r_den(rs)) <= DETOL, Integer(0), f_r_num(rs)/f_r_den(rs))

# Equations (25)

c_25_i = maple_list([-Float('0.32481568604919886'), Float('1.180131465463191050'), -Float('1.42693041498421640'), Float('0.580344063812247980'), -Float('0.01099122367291440')])

d_25_i = maple_list([-Float('0.57786103193239430'), Float('2.09708505883490736'), -Float('2.52188183586948180'), Float('1.0')])

# den_d has no root in z in [-1,1] (nearest at z=1.037), so f_s has no pole and
# needs no screen; the mild ~3-digit cancellation as z->1 leaves value and
# derivatives accurate, so no Taylor branch either.

@helper
def f_s_num(z):
    return sum((c_25_i[i]*z**(i-Integer(1))) for i in range(Integer(1), (Integer(5)) + Integer(1)))

@helper
def f_s_den(z):
    return sum((d_25_i[i]*z**(i-Integer(1))) for i in range(Integer(1), (Integer(4)) + Integer(1)))

@helper
def f_s(z):
    return f_s_num(z)/f_s_den(z)

# Equation (23)

# The factor 1.28 is absent from the paper, but it is in the original code. See erratum

@helper
def ss(rs, z):
    return f_r(rs)*f_s(z)*Float('1.28')

# Equation (22)

@helper
def alpha_z(rs, z):
    return Integer(2)/(opz_pow_n(z,ss(rs, z)) + opz_pow_n(-z,ss(rs, z)))

# Equation (21)

eta6 = Float('0.41081146652128')

eta7 = Float('0.599343256903515')

eta8 = Float('1.70939476802168')

eta9 = Float('0.077123208419481')

eta10 = Float('0.46958449007619')

@helper
def alpha_n(rs):
    return (
        + eta6
        + eta7*exp( -eta8*rs**(Integer(1)/Integer(3)))*rs**(Integer(2)/Integer(3))
        + eta9*exp(-eta10*rs**(Integer(1)/Integer(3)))*rs**(Integer(1)/Integer(3))
    )

# Equation (20)

@helper
def alpha_eff(rs, z):
    return alpha_n(rs)*alpha_z(rs, z)

# Equation (19)

eta1 = Float('0.538074483500437')

eta2 = -Float('2.226094990985190')

eta3 = Float('0.837303782322808')

eta4 = Float('2.619709858963178')

eta5 = Float('1.036657594643520')

@helper
def beta_eff(rs):
    return (
        + eta1
        + eta2*exp(-eta3*rs**(Integer(1)/Integer(3)))*rs**(Integer(1)/Integer(4))
        + eta4*exp(-eta5*rs**(Integer(1)/Integer(3)))*rs**(Integer(1)/Integer(3))
    )

# Equation (15), see erratum

ax = (Integer(3)*pi**Integer(2))**(Integer(1)/Integer(3))

@helper
def k_fs(rs, z):
    return ax*RS_FACTOR/rs * opz_pow_n(z,Integer(1)/Integer(3))

# Floor the screening wave vectors at K_TOL (the Q functions have 1/k, 1/k^2
# poles that blow up as k->0 in the dilute / strongly-polarized limit), as in
# Proynov's reference code.

K_TOL = Float('0.1e-10')

# Equation (17)

@helper
def k_uu(rs, z):
    return m_max(alpha_eff(rs,  z)*k_fs(rs,  z), K_TOL)

@helper
def k_dd(rs, z):
    return m_max(alpha_eff(rs, -z)*k_fs(rs, -z), K_TOL)

# Equation (18)

@helper
def k_ud(rs, z):
    return (
        m_max(beta_eff(rs)
        * Integer(2)*k_fs(rs, z)*k_fs(rs, -z)/(k_fs(rs, z) + k_fs(rs, -z)), K_TOL)
    )

# Table III

a1 = Float('0.1846304394851914')

a2 = Float('5.93965654951900799')

a3 = Float('2.36958012866641818')

a4 = Float('.51188865525958770e-1')

a5 = Float('.9576892532004281e-1')

a6 = Float('.283592616144882565e-1')

a7 = Float('.226274169979695208e-1')

a8 = Float('.531736155271654809e-2')

a9 = Float('.1915378506400854')

a10 = Float('.1473137771194929')

a11 = Float('.1528250938350897')

a12 = Float('1.01508307543839117')

a13 = Float('.7641254691754473e-1')

a14 = Float('.898537460263473410')

a15 = Float('.1795667349750801e-1')

a16 = Float('.3461820740347690e-1')

a17 = Float('.3591334699501599e-1')

a18 = Float('.222017353476155799')

c1 = Float('132.479090287794355')

c2 = Float('32.4014708516771368')

c3 = Float('22.5664453162503806')

c4 = Float('11.2832226581251903')

c5 = Float('.401060523940960082')

c6 = evalf(Float('0.32'))

c7 = Float('.751988482389300153e-1')

c8 = Float('116.935042647480910')

c9 = Float('29.6240023046901289')

c10 = Float('.482257181994472723')

c11 = Float('.246903981179097557')

c12 = evalf(Integer(1)/Integer(2))

c13 = Float('.410709696778185459')

c14 = Float('.105323524476768857')

c15 = Float('14.5650971711659670')

c16 = Float('.781250000000000000')

c17 = Float('.623347313127238558')

c18 = Float('.146484374999999999')

c19 = Float('111.811548105797788')

c20 = Float('.160041105570901272')

c21 = evalf(Float('.78125'))

c22 = Float('.32086695060795739')

c23 = Float('13.2844495072998436')

c24 = Float('.268418671319107341')

c25 = Float('.471060597934991862')

c26 = evalf(Integer(1)/Integer(4))

c27 = Float('.252882919616989509')

c28 = Float('.720485831127149779e-1')

c29 = Float('42.6490544891031073')

# Definitions in the beginning of the appendix

@helper
def D_1(k):
    return a6*k**Integer(2) + a7*k + a8

@helper
def D_2(k):
    return a1*k**Integer(2) + a10*k + a16

@helper
def D_3(k):
    return a5*k**Integer(2) + a13*k + a15

@helper
def D_4(k):
    return a9*k**Integer(2) + a11*k + a17

@helper
def D_5(k):
    return c5*k**Integer(2) + c6*k + c7

@helper
def D_6(k):
    return c12*k**Integer(2) + c13*k + c14

@helper
def D_7(k):
    return c16*k**Integer(2) + c17*k + c18

@helper
def D_8(k):
    return sqrt(c26*k**Integer(2) + c27*k + c28)

# Equation (10)

@helper
def Q_1ud(k):
    return (
        Integer(1)/D_1(k) * (
        - atan(a2*k + a3)*D_2(k)/k - log(D_1(k))*D_3(k)/k
        + log(k)*D_4(k)/k - a4*k + a12 + a14/k + a18/k**Integer(2)
        )
    )

# Equation (11)

@helper
def Q_2ud(k):
    return (
        - c1/k - c2/k**Integer(2) - c3*log(k)/k + c4*log(D_5(k))/k
        + c8*atan(a2*k + a3)/k + c9*log(k + c10)/k - c11/k*log(D_6(k))
    )

# Equation (12)

@helper
def Q_3ud(k):
    return (
        + c19*atan(c20/(c21*k + c22))/k - c23*xc_atanh((c24 + c25*k)/D_8(k))/k
        - c15*log(D_7(k))/k - c29*D_8(k)/k**Integer(2)
    )

# Equation (9)

@helper
def ec_opp(rs, z):
    return one_minus_z_pow_n(z, Integer(2))/Integer(4)*(Q_1ud(k_ud(rs, z)) + Q_2ud(k_ud(rs, z)) + Q_3ud(k_ud(rs, z)))

# Equation (13)

@helper
def ec_par(rs, z):
    return (
        + opz_pow_n( z,Integer(2))/Integer(8)*(Q_1ud(k_uu(rs, z)) + Q_2ud(k_uu(rs, z)) + Q_3ud(k_uu(rs, z)))
        + opz_pow_n(-z,Integer(2))/Integer(8)*(Q_1ud(k_dd(rs, z)) + Q_2ud(k_dd(rs, z)) + Q_3ud(k_dd(rs, z)))
    )

def f(rs, z):
    return n_total(rs)*(ec_opp(rs, z) + ec_par(rs, z))

TYPE = "lda_exc"
