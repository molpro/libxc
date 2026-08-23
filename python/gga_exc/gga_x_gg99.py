"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# replace: "my_dilog\(" -> "xc_dilogarithm("

from libxc_codegen import *  # noqa: F401, F403

w = Symbol("w")

# d/dx Li_2(g) = -log(1 - g)/g * dg/dx; route log(1 - g) through
# xc_log1p so the derivative stays precise at g -> 0.

class my_dilog(Function):
    def fdiff(self, argindex=1):
        g, = self.args
        if argindex == 1:
            return -xc_log1p(-g)/g * Integer(1)
        return 0

gg99_a = Integer(3)**(Integer(1)/Integer(4))/(Integer(2)*sqrt(Integer(2))*pi**(Integer(3)/Integer(2)))

gg99_b = Integer(4)*sqrt(Integer(3))*pi**Integer(3)

# Equation 22 in the paper, i.e.
# the solution of x = 2*Pi*sinh(r)/(3*cosh(r))^(1/3)

@helper
def gg99_r_branch1(x):
    return xc_asinh( (gg99_a * x * sqrt(x**Integer(2) + (gg99_b + sqrt(gg99_b**Integer(2) - x**Integer(6)))**(Integer(2)/Integer(3)))) / (gg99_b + sqrt(gg99_b**Integer(2) - x**Integer(6)))**(Integer(1)/Integer(6)) )

# The second branch is from Andrew Gilbert via email

@helper
def gg99_r_branch2(x):
    return xc_asinh(sqrt(x**Integer(3)*(Integer(3)/gg99_b)*cos(atan(sqrt(Integer(1)/(gg99_b**Integer(2))*x**Integer(6)-Integer(1)))/Integer(3))))

# Glue the pieces together. The min and max are required
# to avoid float exceptions

@helper
def gg99_r(x):
    return (
        my_piecewise3(x < gg99_b**(Integer(1)/Integer(3)),
        gg99_r_branch1(m_min(x, gg99_b**(Integer(1)/Integer(3)) - Float('1e-10'))),
        gg99_r_branch2(m_max(x, gg99_b**(Integer(1)/Integer(3)) + Float('1e-10')))
        )
    )

# Equation 21.  The numerator
# Pi^2 - 12 r log1p(exp(-2r)) + 12 dilog(-exp(-2r))
# collapses to 0 at r = 0 (both constants are pi^2: dilog(-1) =
# -pi^2/12).  Taylor expansion at r = 0 starts with 12*log(2)*r, so
# the direct form loses ~ log10(pi^2/(12*log(2)*r)) digits of
# precision.  Use a Taylor branch for r < 1/4 (where the series
# converges and order 16 gives 4th-derivative ULP) and the direct
# form otherwise.

@helper
def gg99_f0_num_orig(r):
    return pi**Integer(2) - Integer(12)*r*xc_log1p(exp(-Integer(2)*r)) + Integer(12)*my_dilog(-exp(-Integer(2)*r))

@helper
def gg99_f0_num_taylor(r):
    return maple_eval(convert(maple_series(to_elementary(gg99_f0_num_orig(w)), w, Integer(0), Integer(16)), polynom), w, r)

@helper
def gg99_f0_num(r):
    return (
        my_piecewise3(r < Integer(1)/Integer(4),
        gg99_f0_num_taylor(r),
        gg99_f0_num_orig(r))
    )

@helper
def gg99_f0(r):
    return gg99_f0_num(r) / (Integer(2)*Integer(3)**(Integer(1)/Integer(3))*pi*r*sech(r)**(Integer(2)/Integer(3))) / X_FACTOR_C

# Assemble the function

@helper
def gg99_f(x):
    return gg99_f0(gg99_r(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(gg99_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
REPLACE = [
    ('my_dilog\\(', 'xc_dilogarithm('),
]
