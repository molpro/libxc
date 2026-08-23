"""
 Copyright (C) 2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_ft98_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_ft98_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a1 = param_default("a1")
params_a_b1 = param_default("b1")
params_a_a2 = param_default("a2")
params_a_b2 = param_default("b2")
params_a_a = param_default("a")
params_a_b = param_default("b")

qt = Symbol("qt")

# eq. 23

@helper
def ft98_f1(xi):
    return (Integer(1) + params_a_a1*xi)**(Integer(1)/Integer(2)) / (Integer(1) + params_a_b1*xi)**(Integer(3)/Integer(4))

# eq. 24a

# eq. 24b

@helper
def ft98_q1(xi, chi):
    return (xi-chi)**Integer(2) / (Integer(1) + xi)**Integer(2)

# eq. 24c

@helper
def ft98_q2_orig(q3):
    return Integer(1)/(q3 + (Integer(1) + q3**Integer(2))**(Integer(1)/Integer(2)))

# handle small-|q| and very negative q regions separately.
#
# The small-q expansion is
# 1 - q + 1/2 q^2 - 1/8 q^4 + ...
#
# which is accurate to epsilon when q ~ epsilon^(1/4)

@helper
def ft98_q2term_smallq(q3):
    return maple_eval(convert(maple_taylor(ft98_q2_orig(qt), qt, Integer(0), Integer(9)), polynom), qt, q3)

ft98_q2_cutoff_smallq = XC_EPSILON**(Integer(1)/Integer(4))

# when q->-infty, there's danger for overflow.
#
# The expansion at -infty is
#
# -2q - 1/(2q) + 1/(8q^3) - ...
#
# which will be accurate when q < -epsilon^(-1/4)

@helper
def ft98_q2term_minfty(q3):
    return maple_eval(convert(maple_taylor(ft98_q2_orig(qt), qt, -infinity, Integer(9)), polynom), qt, q3)

ft98_q2_cutoff_minfty = -XC_EPSILON**(-Integer(1)/Integer(4))

# assemble the result. Linting the argument for the original argument
# is tricky since the arguments have several branches:
#
# q <= minfty: ft98_q2term_minfty
# minfty <= q <= -smallq: ft98_q2_orig
# -smallq <= q <= +smallq: ft98_q2_smallq
# smallq <= q: ft98_q2_orig

@helper
def ft98_q20(q3):
    return (
        my_piecewise5(
        q3 < ft98_q2_cutoff_minfty, ft98_q2term_minfty(q3),
        m_abs(q3) < ft98_q2_cutoff_smallq, ft98_q2term_smallq(q3),
        ft98_q2_orig(m_max(q3, ft98_q2_cutoff_minfty))
        )
    )

# eq. 24d

@helper
def ft98_q3(xi, chi):
    return xi**Integer(2) - chi**Integer(2) - params_a_b2

@helper
def ft98_q2(xi, chi):
    return ((params_a_b2**Integer(2)+Integer(1))**(Integer(1)/Integer(2)) - params_a_b2)*ft98_q20(ft98_q3(xi, chi))

@helper
def ft98_f2(xi, chi):
    return (Integer(1) + params_a_a2*ft98_q1(xi, chi)) * (Integer(1) + ft98_q2(xi, chi)) / (Integer(1) + (Integer(2)**(Integer(1)/Integer(3)) - Integer(1)) * ft98_q2(xi, chi))**Integer(3)

# eq. 12

@helper
def ft98_f0(xi, chi):
    return sqrt((Integer(1) + params_a_a*ft98_f1(xi)*xi + params_a_b*ft98_f2(xi, chi)*(xi-chi)**Integer(2))/(Integer(1) + Integer(36)*LDA_X_FACTOR**Integer(2)*params_a_b*xi))

#
# eq. 4: the xi variable is simply libxc's x^2
# eq. 5: the chi variable is libxc's u variable

@helper
def ft98_f(x, u, t):
    return ft98_f0(x**Integer(2), u)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(ft98_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_ft98_params"
