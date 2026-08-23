"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_scan_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_scan_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c1 = param_default("c1")
params_a_d = param_default("d")
params_a_c2 = param_default("c2")
params_a_k1 = param_default("k1")

# The interpolating functions are nasty for a -> 1, so we need to
# truncate them. The natural choice is to cut off the functions to
# zero when the exponential term reaches machine epsilon.
#
# The left cutoff is |log epsilon|/(|log epsilon| + c1) < 1
# and the right one is (|log epsilon| + c2)/|log epsilon| > 1,
# so we don't even really need the step function.

@helper
def scan_f_alpha_left0(a):
    return exp(-params_a_c1*a/(Integer(1) - a))

scan_f_alpha_left_cutoff = -log(XC_EPSILON)/(-log(XC_EPSILON) + params_a_c1)

@helper
def scan_f_alpha_left(a):
    return my_piecewise3(a > scan_f_alpha_left_cutoff, Integer(0), scan_f_alpha_left0(m_min(scan_f_alpha_left_cutoff, a)))

@helper
def scan_f_alpha_right0(a):
    return -params_a_d*exp(params_a_c2/(Integer(1) - a))

scan_f_alpha_right_cutoff = (-log(XC_EPSILON/m_abs(params_a_d)) + params_a_c2)/(-log(XC_EPSILON/m_abs(params_a_d)))

@helper
def scan_f_alpha_right(a):
    return my_piecewise3(a < scan_f_alpha_right_cutoff, Integer(0), scan_f_alpha_right0(m_max(scan_f_alpha_right_cutoff, a)))

@helper
def scan_f_alpha(a):
    return (
        my_piecewise3(
        a <= Integer(1), scan_f_alpha_left(a), scan_f_alpha_right(a)
        )
    )

# 1 - k1/(k1 + x) = x/(k1 + x); algebraic identity, cancellation-
# free at small x where the direct form computes 1 - close-to-1.

@helper
def scan_h1x(x):
    return Integer(1) + params_a_k1*x/(params_a_k1 + x)

scan_b2 = sqrt(Integer(5913)/Integer(405000))

scan_b1 = (Integer(511)/Integer(13500))/(Integer(2)*scan_b2)

scan_b3 = Integer(1)/Integer(2)

scan_b4 = MU_GE**Integer(2)/params_a_k1 - Integer(1606)/Integer(18225) - scan_b1**Integer(2)

@helper
def scan_y(x, a):
    return (
        MU_GE*mgga_p(x) + scan_b4*mgga_p(x)**Integer(2)*exp(-scan_b4*mgga_p(x)/MU_GE)
        + (scan_b1*mgga_p(x) + scan_b2*(Integer(1) - a)*exp(-scan_b3*(Integer(1) - a)**Integer(2)))**Integer(2)
    )

scan_a1 = Float('4.9479')

@helper
def scan_gx(x):
    return -xc_expm1(-scan_a1/sqrt(gga_s(x)))

scan_h0x = Float('1.174')

# The enhancement factor as a function of the iso-orbital indicator alpha.
# Taking alpha as the argument (rather than tau) lets a deorbitalized variant
# supply an alpha that its kinetic-energy functional yields directly, without
# the round trip through tau and the cancellation against tau_W that it
# entails.  scan_f recovers the orbital-dependent form.

@helper
def scan_f_a(x, a):
    return (scan_h1x(scan_y(x, a))*(Integer(1) - scan_f_alpha(a)) + scan_h0x*scan_f_alpha(a))*scan_gx(x)

@helper
def scan_f(x, u, t):
    return scan_f_a(x, mgga_alpha(x, t))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(scan_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_scan_params"
