"""
 Copyright (C) 2017 M.A.L. Marques
               2022 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

y = Symbol("y")

include('gga_c_tca')

# Taylor expansion of sinc(x) at x=0.  Even-only series, so order 7
# (degree-6 polynomial, terms 1, y^2, y^4, y^6) is sufficient for
# 4th-derivative ULP at the eps^(1/4) cutoff: truncation 4th deriv
# is 8*7*6*5 * (1/9!) * (eps^(1/4))^4 ~ 1e-18, well below
# XC_EPSILON * |sinc''''(0) ~ 1/5| ~ 4e-17.

@helper
def sinc(x):
    return sin(x)/x

@helper
def sinc_taylor(x):
    return maple_eval(convert(maple_taylor(sinc(y), y, Integer(0), Integer(7)),polynom), y, x)

# Switch to Taylor when x^4 ~ epsilon, i.e. x ~ eps^(1/4).

sinc_cutoff = XC_EPSILON**(Integer(1)/Integer(4))

@helper
def msinc(x):
    return my_piecewise3(x <= sinc_cutoff, sinc_taylor(x), sinc(m_max(x, sinc_cutoff)))

revtca_aa = pi*(Integer(9)*pi/Integer(4))**(Integer(1)/Integer(3))

# 1 - z^4*(1 - msinc^2) = (1 - z^4) + z^4*msinc^2; the (1 - z^4)
# factor is routed through one_minus_z_pow_n so the spin-boundary
# cancellation is gone, and the residual `z^4*msinc^2` no longer
# contains the catastrophic `1 - msinc^2` at small argument where
# msinc -> 1.

@helper
def revtca_fD(rs, z, s):
    return one_minus_z_pow_n(z, Integer(4)) + z**Integer(4)*msinc(revtca_aa*s/rs)**Integer(2)

def f(rs, z, xt, xs0, xs1):
    return f_tcs(rs, z, xt)*revtca_fD(rs, z, gga_s_total(xt))

TYPE = "gga_exc"
