"""
 Copyright (C) 2019 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

include('mgga_x_tm')
include('lda_x_erf')

# See text after eq 7

@helper
def js18_H(x):
    return (Integer(2)*tm_lambda - Integer(1))**Integer(2) * tm_p(x)

# See text after eq 7

@helper
def js18_G(x, t):
    return (
        (Integer(3)*(tm_lambda**Integer(2) - tm_lambda + Integer(1)/Integer(2))*(t - K_FACTOR_C - x**Integer(2)/Integer(72)) - (t - K_FACTOR_C)
        + Integer(7)/Integer(18)*(Integer(2)*tm_lambda - Integer(1))**Integer(2)*x**Integer(2))/K_FACTOR_C
    )

# not to run into problems with erfs and exp; floor precision-relatively
# (cf. wpbeh's aux4) rather than with a hardcoded 1e-10

@helper
def js18_A(rs, z, x):
    return m_max(xc_reduced_floor, a_cnst*rs/(tm_f0(x)*opz_pow_n(z,Integer(1)/Integer(3))))

@helper
def js18_DME_SR(rs, z, x, t):
    return (
        + attenuation_erf   (js18_A(rs, z, x))/tm_f0(x)**Integer(2)
        + attenuation_erf_f2(js18_A(rs, z, x))*Integer(7)*js18_G(x, t)/(Integer(9)*tm_f0(x)**Integer(4))
        + attenuation_erf_f3(js18_A(rs, z, x))*Integer(245)*js18_H(x)/(Integer(54)*tm_f0(x)**Integer(4))
    )

@helper
def pjs18_f(rs, z, x, u, t):
    return js18_DME_SR(rs, z, x, t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange_nsp(pjs18_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
