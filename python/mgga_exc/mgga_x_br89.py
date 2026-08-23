"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_br89_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_br89_params * ) (p->params);
# replace: "br89_x\(" -> "xc_mgga_x_br89_get_x("

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_at = param_default("at")

# This is the derivative of f = x*exp(-2.0/3.0*x)/(x - 2) = y = 2*Pi^(2/3)/(3*Q)

@helper
def br89_aux_dfdx(x):
    return -Integer(2)/Integer(3) * exp(-Integer(2)*x/Integer(3)) * (x**Integer(2) - Integer(2)*x + Integer(3)) / (x - Integer(2))**Integer(2)

class br89_x(Function):
    def fdiff(self, argindex=1):
        Q, = self.args
        if argindex == 1:
            return -Integer(2)/Integer(3) * pi**(Integer(2)/Integer(3)) * Integer(1)/(Q**Integer(2) * br89_aux_dfdx(br89_x(Q)))
        return 0

@helper
def br89_Q(x, u, t):
    return (u - Integer(4)*params_a_gamma*t + params_a_gamma*x**Integer(2)/Integer(2))/Integer(6)

br89_min_Q = Float('5.0e-13')

@helper
def br89_cQ(Q):
    return (
        my_piecewise3(m_abs(Q) < br89_min_Q,
        my_piecewise3(Q > Integer(0), br89_min_Q, -br89_min_Q), Q)
    )

# Algebraic identity:
# 1 - exp(-x)*(1 + x/2) = -x/2 + (1 + x/2)*(1 - exp(-x)),
# so (1 - exp(-x)*(1+x/2))/x = (1 + x/2)*(-xc_expm1(-x))/x - 1/2.
# The original form computes 1 - close-to-1 at small x; the
# rewritten form is the sum of two O(1) pieces with no
# catastrophic cancellation, while reproducing the same large-x
# limit (-> 1/x).

@helper
def br89_v(x):
    return -Integer(2)*pi**(Integer(1)/Integer(3))/X_FACTOR_C * exp(x/Integer(3))*((Integer(1) + x/Integer(2))*(-xc_expm1(-x))/x - Integer(1)/Integer(2))

@helper
def br89_mx(Q):
    return br89_x(Q)

@helper
def br89_f(x, u, t):
    return (
        - br89_v(br89_mx(br89_cQ(br89_Q(x, u, t))))/Integer(2) *
        (Integer(1) + params_a_at*mgga_series_w(maple_list([Integer(0), Integer(1), Integer(0), -Integer(2), Integer(0), Integer(1)]), Integer(6), t))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(br89_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_br89_params"
REPLACE = [
    ('br89_x\\(', 'xc_mgga_x_br89_get_x('),
]
