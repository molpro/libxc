"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_hjs_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_hjs_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a = param_default("a")
params_a_b = param_default("b")

hjs_AA = Float('0.757211')

hjs_BB = -Float('0.106364')

hjs_CC = -Float('0.118649')

hjs_DD = Float('0.609650')

@helper
def hjs_fH(s):
    return sum((params_a_a[i]*s**(Integer(1)+i)) for i in range(Integer(1), (Integer(6)) + Integer(1)))/(Integer(1) + sum((params_a_b[i]*s**i) for i in range(Integer(1), (Integer(9)) + Integer(1))))

# The m_max functions are necessary as in some cases the arguments of the
# sqrt become negative

@helper
def hjs_zeta(s):
    return m_max(s**Integer(2)*hjs_fH(s), xc_reduced_floor)

@helper
def hjs_eta(s):
    return m_max(hjs_AA + hjs_zeta(s), xc_reduced_floor)

@helper
def hjs_lambda(s):
    return hjs_DD + hjs_zeta(s)

# KEEP IN SYNC: hjs_chi and hjs_one_minus_chi.  Conjugate rationalization
# 1 - nu/sqrt(lambda + nu^2) = (sqrt(lambda + nu^2) - nu)/sqrt(lambda + nu^2)
# = lambda/((sqrt(lambda + nu^2) + nu)*sqrt(lambda + nu^2)),
# cancellation-free at nu -> infinity (low density) where chi -> 1
# and the direct 1 - close-to-1 form loses precision.  The
# polynomial factors below in hjs_f1 also share (1-chi)^k structure:
# 2 - 3*chi + chi^3  = (1-chi)^2*(2+chi)
# 8 - 15*chi + 10*chi^3 - 3*chi^5 = (1-chi)^3*(8 + 9*chi + 3*chi^2)
# so factor them through hjs_one_minus_chi as well.

@helper
def hjs_chi(rs, z, s):
    return nu(rs, z)/sqrt(hjs_lambda(s) + nu(rs, z)**Integer(2))

@helper
def hjs_one_minus_chi(rs, z, s):
    return (
        hjs_lambda(s)
        / ((sqrt(hjs_lambda(s) + nu(rs, z)**Integer(2)) + nu(rs, z))*sqrt(hjs_lambda(s) + nu(rs, z)**Integer(2)))
    )

@helper
def hjs_fF(rs, z, s):
    return Integer(1) - s**Integer(2)/(Integer(27)*hjs_CC*(Integer(1) + s**Integer(2)/Integer(4))) - hjs_zeta(s)/(Integer(2)*hjs_CC)

# sqrt(zeta) - sqrt(eta) = (zeta - eta)/(sqrt(zeta) + sqrt(eta)),
# cancellation-free at large s where eta - zeta = AA (constant) gets
# swamped by the absolute magnitudes.

@helper
def hjs_fG(rs, z, s):
    return (
        - Integer(2)/Integer(5)  * hjs_CC*hjs_fF(rs, z, s)*hjs_lambda(s)
        - Integer(4)/Integer(15) * hjs_BB*hjs_lambda(s)**Integer(2)
        - Integer(6)/Integer(5)  * hjs_AA*hjs_lambda(s)**Integer(3)
        - hjs_lambda(s)**(Integer(7)/Integer(2))*(Integer(4)/Integer(5)*sqrt(pi) + Integer(12)/Integer(5)*(hjs_zeta(s) - hjs_eta(s))/(sqrt(hjs_zeta(s)) + sqrt(hjs_eta(s))))
    )

# In hjs_f1:
# - sqrt(zeta + nu^2) - sqrt(eta + nu^2)  ->  (zeta - eta)/(sum)
# - log((nu + sqrt(zeta+nu^2))/(nu + sqrt(lambda+nu^2)))  ->
# xc_log1p((sqrt(zeta+nu^2) - sqrt(lambda+nu^2))/(nu + sqrt(lambda+nu^2)))
# with the sqrt subtraction in turn rationalized to
# (zeta - lambda)/(sum).
# The log-of-close-to-1 cancels at large nu (high density) where
# sqrt(zeta + nu^2) and sqrt(lambda + nu^2) both approach nu, so
# the ratio approaches 1.  Same idea for the eta log.

@helper
def hjs_f1(rs, z, s):
    return (
        + hjs_AA
        - Integer(4)/Integer(9) * hjs_BB*hjs_one_minus_chi(rs, z, s)/hjs_lambda(s)
        - Integer(2)/Integer(9) * hjs_CC*hjs_fF(rs, z, s)*hjs_one_minus_chi(rs, z, s)**Integer(2)*(Integer(2) + hjs_chi(rs, z, s))/hjs_lambda(s)**Integer(2)
        - Integer(1)/Integer(9) * hjs_fG(rs, z, s)*hjs_one_minus_chi(rs, z, s)**Integer(3)*(Integer(8) + Integer(9)*hjs_chi(rs, z, s) + Integer(3)*hjs_chi(rs, z, s)**Integer(2))/hjs_lambda(s)**Integer(3)
        + Integer(2)*nu(rs, z)*(hjs_zeta(s) - hjs_eta(s))
        /(sqrt(hjs_zeta(s) + nu(rs, z)**Integer(2)) + sqrt(hjs_eta(s) + nu(rs, z)**Integer(2)))
        + Integer(2)*hjs_zeta(s)*xc_log1p(
        (hjs_zeta(s) - hjs_lambda(s))
        /((sqrt(hjs_zeta(s) + nu(rs, z)**Integer(2)) + sqrt(hjs_lambda(s) + nu(rs, z)**Integer(2)))
        *(nu(rs, z) + sqrt(hjs_lambda(s) + nu(rs, z)**Integer(2)))))
        - Integer(2)*hjs_eta(s)*xc_log1p(
        (hjs_eta(s) - hjs_lambda(s))
        /((sqrt(hjs_eta(s) + nu(rs, z)**Integer(2)) + sqrt(hjs_lambda(s) + nu(rs, z)**Integer(2)))
        *(nu(rs, z) + sqrt(hjs_lambda(s) + nu(rs, z)**Integer(2)))))
    )

@helper
def hjs_fx(rs, z, x):
    return hjs_f1(rs, z, gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange_nsp(hjs_fx, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_hjs_params"
