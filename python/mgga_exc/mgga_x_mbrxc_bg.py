"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# replace: "mbrxc_x\(" -> "xc_mgga_x_mbrxc_get_x("

from libxc_codegen import *  # noqa: F401, F403

y = Symbol("y")

mbrxc_a1 = Float('0.074746')

mbrxc_a2 = Float('0.147')

mbrxc_a3 = Float('0.0032')

# This is the derivative of f = (1+x)^(5/3)*exp(-2/3*x)/(x - 3) = (32*Pi)^(2/3)/(6*Q)

@helper
def mbrxc_aux_dfdx(x):
    return -Integer(2)/Integer(3) * (Integer(1) + x)**(Integer(2)/Integer(3)) * exp(-Integer(2)*x/Integer(3)) * (x**Integer(2) - Integer(3)*x + Integer(6)) / (x - Integer(3))**Integer(2)

class mbrxc_x(Function):
    def fdiff(self, argindex=1):
        Q, = self.args
        if argindex == 1:
            return - (Integer(32)*pi)**(Integer(2)/Integer(3))/Integer(6) * Integer(1)/(Q**Integer(2) * mbrxc_aux_dfdx(mbrxc_x(Q)))
        return 0

@helper
def mbrxc_Q(x, t):
    return mbrxc_a1*(Integer(2)*t) - K_FACTOR_C + mbrxc_a2*x**Integer(2) + mbrxc_a3*x**Integer(4)

# The numerator 8 - exp(-x)*(x^2+5x+8) cancels at small x.
# Algebraic identity:
# 8 - exp(-x)*(x^2+5x+8)
# = 8 - (1 + (exp(-x) - 1))*(x^2+5x+8)
# = 8 - (x^2+5x+8) - xc_expm1(-x)*(x^2+5x+8)
# = -x*(x+5) - xc_expm1(-x)*(x^2+5x+8),
# which is cancellation-free at all x (and reproduces the leading
# 3x at small x: -5x + (-x)*8 = -5x + 8x = 3x).  The direct form
# is now full-precision everywhere, so the Taylor branch is kept
# only for derivative correctness at x = 0 exactly (where
# xc_expm1(-x)/x would be 0/0); the boundary mismatch at the
# cutoff is now at the ULP level.

@helper
def mbrxc_v0(x):
    return - (Integer(32)*pi)**(Integer(1)/Integer(3))/(Integer(8)*X_FACTOR_C) * exp(x/Integer(3))*(-x*(x+Integer(5)) - xc_expm1(-x)*(x**Integer(2) + Integer(5)*x + Integer(8)))/(x*(Integer(1) + x)**(Integer(1)/Integer(3)))

# With the cancellation-free rewrite above, direct mbrxc_v0 is now
# precise at all x > 0, so the Taylor branch is needed only to
# handle the formal 0/0 at x = 0 in xc_expm1(-x)/x and to keep
# derivatives correct at the boundary.  Tightened to cutoff
# sqrt(XC_EPSILON) with Maple order 7 (degree-6 polynomial): at
# the boundary the 4th derivative truncation is
# 7*6*5*4 * c_7 * sqrt(eps)^3 ~ O(840) * eps^(3/2) ~ 4e-21,
# well below XC_EPSILON * |actual 4th derivative ~ O(1)|.

# series() through to_elementary: the 1/x factor is a removable
# singularity (the numerator vanishes at x=0) that taylor() refuses,
# and mbrxc_v0 carries the inert xc_expm1 wrapper -- to_elementary
# makes it native so series() can expand through the singularity.

@helper
def mbrxc_v_smallq(x):
    return maple_eval(convert(maple_series(to_elementary(mbrxc_v0(y)), y, Integer(0), Integer(7)), polynom), y, x)

mbrxc_v_cutoff = sqrt(XC_EPSILON)

@helper
def mbrxc_v(x):
    return my_piecewise3(x < mbrxc_v_cutoff, mbrxc_v_smallq(x), mbrxc_v0(m_max(x, mbrxc_v_cutoff)))

@helper
def mbrxc_f(x, u, t):
    return - mbrxc_v(mbrxc_x(mbrxc_Q(x, t)))/Integer(2)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(mbrxc_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
REPLACE = [
    ('mbrxc_x\\(', 'xc_mgga_x_mbrxc_get_x('),
]
