"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_c_r2scan_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_r2scan_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_dp2 = param_default("dp2")
params_a_c1 = param_default("c1")
params_a_eta = param_default("eta")

x1 = Symbol("x1")
x2 = Symbol("x2")

include('mgga_c_rscan')
define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

# These come from pbe correlation
params_a_gamma = (Integer(1) - log(Integer(2)))/pi**Integer(2)

mgamma = params_a_gamma

# r2scan values

params_a_dp2 = Float('0.361')

# Equation (S6)

# Equation (S26)

@helper
def r2scan_f_alpha_neg(a):
    return exp(-params_a_c1*a/(Integer(1) - a))

@helper
def r2scan_f_alpha(a, ff):
    return (
        my_piecewise5(
        a <= Integer(0), r2scan_f_alpha_neg(m_min(a, Integer(0))),
        a <= Float('2.5'), rscan_f_alpha_small(m_min(a, Float('2.5')), ff),
        rscan_f_alpha_large(m_max(a, Float('2.5'))))
    )

# Equation (S28)

@helper
def r2scan_d(z):
    return (opz_pow_n(z,Integer(5)/Integer(3)) + opz_pow_n(-z,Integer(5)/Integer(3)))/Integer(2)

# Equation (S33): beta(rs), this is the same as in gga_c_regtpss

beta_a = Float('0.066724550603149220')

beta_b = Float('0.1')

beta_c = Float('0.1778')

@helper
def mbeta(rs):
    return beta_a*(Integer(1) + beta_b*rs)/(Integer(1) + beta_c*rs)

# Equation (S30)

@helper
def w1(rs, z):
    return xc_expm1(-f_pw(rs, z)/(mgamma*mphi(z)**Integer(3)))

# Equation (S27); note that the paper indexes starting from zero

@helper
def r2scan_dfc2(ff):
    return sum((i*ff[Integer(8)-i]) for i in range(Integer(1), (Integer(7)) + Integer(1)))

# According to James Furness, this is LSDA0 - see also Equation (S25)

@helper
def r2scan_elsda0(rs, z):
    return scan_eclda0(rs)*scan_Gc(z)

# while LSDA1 is just Perdew-Wang

@helper
def r2scan_elsda1(rs, z):
    return f_pw(rs, z)

# Derivatives wrt rs

@helper
def r2scan_delsda0(rs, z):
    return maple_eval(diff(r2scan_elsda0(x1, x2), x1), x1, rs, x2, z)

@helper
def r2scan_delsda1(rs, z):
    return maple_eval(diff(r2scan_elsda1(x1, x2), x1), x1, rs, x2, z)

# Equation (S34)

@helper
def r2scan_dy(rs, z, s):
    return (
        r2scan_dfc2(rscan_fc)/(Integer(27) * mgamma * r2scan_d(z) * mphi(z)**Integer(3) * w1(rs, z)) * (
        + Integer(20)*rs*(r2scan_delsda0(rs, z) - r2scan_delsda1(rs, z))
        - Integer(45)*params_a_eta*(r2scan_elsda0(rs, z) - r2scan_elsda1(rs, z))
        ) * s**Integer(2)*exp(-s**Integer(4)/params_a_dp2**Integer(4))
    )

# Equation (S32)

@helper
def r2scan_y(rs, z, t):
    return mbeta(rs)*t**Integer(2)/(mgamma*w1(rs, z))

# Equation (S31). r2scan_g = 1/(1 + 4Y)^(1/4) appears only as
# `1 - r2scan_g`, so we go straight to that form below.

# Equation (S29). The factor (1 - r2scan_g) = 1 - (1 + 4Y)^(-1/4)
# is routed through expm1/log1p so the small-Y limit doesn't lose
# precision in `1 - close-to-1`.

@helper
def r2scan_one_minus_g(rs, z, s, t):
    return -xc_expm1(-(Integer(1)/Integer(4))*xc_log1p(Integer(4)*(r2scan_y(rs, z, t) - r2scan_dy(rs, z, s))))

@helper
def fH(rs, z, s, t):
    return mgamma*mphi(z)**Integer(3)*xc_log1p(w1(rs, z)*r2scan_one_minus_g(rs, z, s, t))

# Now we can build ec1 from (S24)

@helper
def r2scan_ec1(rs, z, s, t):
    return f_pw(rs, z) + fH(rs, z, s, t)

# Equation (S35)-(S41) are same as SCAN

@helper
def r2scan_ec0(rs, z, s):
    return scan_e0(rs, z, s)

# and the functional itself.  r2scan_c_f_a takes the iso-orbital indicator, so
# that a deorbitalized variant can pass the alpha its kinetic energy functional
# yields directly; see mgga_c_r2scanl.mpl.  Named to avoid colliding with the
# exchange kernel's r2scan_f_a.

@helper
def r2scan_c_f_a(rs, z, xt, a):
    return (
        r2scan_ec1(rs, z, gga_s_total(xt), tt(rs, z, xt)) + r2scan_f_alpha(a, rscan_fc)*(
        + r2scan_ec0(rs, z, gga_s_total(xt)) - r2scan_ec1(rs, z, gga_s_total(xt), tt(rs, z, xt)))
    )

@helper
def r2scan_f(rs, z, xt, xs0, xs1, ts0, ts1):
    return r2scan_c_f_a(rs, z, xt, mgga_alpha_total_reg(z, xt, ts0, ts1, params_a_eta))

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return r2scan_f(rs, z, xt, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_r2scan_params"
