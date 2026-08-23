"""
 Copyright (C) 2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

# Data in table 1

@helper
def w20_a0(z):
    return my_piecewise3(Eq(z, Integer(0)), (Integer(1)-log(Integer(2)))/pi**Integer(2), (Integer(1)-log(Integer(2)))/(Integer(2)*pi**Integer(2)))

@helper
def w20_a1(z):
    return my_piecewise3(Eq(z, Integer(0)), (Integer(9)*pi/Integer(4))**(-Integer(1)/Integer(3)) * Integer(1)/(Integer(4)*pi**Integer(3)) * ( Integer(7)*pi**Integer(2)/Integer(6) - Integer(12)*log(Integer(2)) - Integer(1) ), Integer(2)**(-Integer(4)/Integer(3)) * (Integer(9)*pi/Integer(4))**(-Integer(1)/Integer(3)) * Integer(1)/(Integer(4)*pi**Integer(3)) * ( Integer(13)*pi**Integer(2)/Integer(12) - Integer(12)*log(Integer(2)) + Integer(1)/Integer(2) ))

@helper
def w20_b0(z):
    return my_piecewise3(Eq(z, Integer(0)), -Float('0.071100') + log(Integer(2))/Integer(6) - Integer(3)/(Integer(4)*pi**Integer(2))*evalf(zeta(Integer(3))), -Float('0.049917') + log(Integer(2))/Integer(6) - Integer(3)/(Integer(4)*pi**Integer(2))*evalf(zeta(Integer(3))))

@helper
def w20_b1(z):
    # Compare eq 12 to eqs 15 and 16
    return my_piecewise3(Eq(z, Integer(0)), -Float('0.01'), Integer(0))

w20_f0 = -Float('0.9')

w20_f1 = Float('1.5')

w20_f2 = Integer(0)

# eq 6

@helper
def w20_cs(z):
    return Integer(3)/Integer(10)*(Integer(9)*pi/Integer(4))**(Integer(2)/Integer(3)) * Integer(1)/Integer(2)*(opz_pow_n(z, Integer(5)/Integer(3)) + opz_pow_n(-z, Integer(5)/Integer(3)))

# eq 7

@helper
def w20_cx(z):
    return -Integer(3)/(Integer(4)*pi)*(Integer(9)*pi/Integer(4))**(Integer(1)/Integer(3)) * Integer(1)/Integer(2)*(opz_pow_n(z, Integer(4)/Integer(3)) + opz_pow_n(-z, Integer(4)/Integer(3)))

# eq 8

# eqs 9 and 11 only differ by the f_i - c_j(z) term.
# Algebraic identity:
# 1 - (-expm1(-y)) = 1 + expm1(-y) = exp(-y),
# so collecting the exp(-2 b0/a0) terms gives
# exp(-2 b0/a0) * exp(-(rs/100)^2) - 2*(-expm1(-(rs/100)^2))*cfterm/a0
# = exp(-2 b0/a0 - (rs/100)^2) - ...
# which removes the partial cancellation between the leading
# exp(-2 b0/a0) and the same term hidden inside the second piece
# at large rs (where -expm1 -> 1).

@helper
def w20_DF(rs, z, cfterm):
    return (
        + exp(-Integer(2)*w20_b0(z)/w20_a0(z) - (rs/Integer(100))**Integer(2))
        - Integer(2)*(-xc_expm1(-(rs/Integer(100))**Integer(2)))*cfterm/w20_a0(z)
    )

# eq 10

@helper
def w20_E(rs, z):
    return - Integer(2)*(-xc_expm1(-(rs/Integer(100))**Integer(2)))*w20_f1 / w20_a0(z)

# eq 12, rewritten in terms of a decaying exponential to avoid overflow

@helper
def w20_G(rs, z):
    return rs*exp(-(rs/Integer(100))**Integer(2)) / (exp(-(rs/Integer(100))**Integer(2)) + Integer(10)*rs**(Integer(5)/Integer(4))) * ( -w20_a1(z)*xc_log1p(Integer(1)/rs) + w20_b1(z) )

@helper
def w20_ec(rs, z):
    return -w20_a0(z)/Integer(2) * xc_log1p(w20_DF(rs,z,w20_f0-w20_cx(z))/rs + w20_E(rs,z)/rs**(Integer(3)/Integer(2)) + w20_DF(rs,z,w20_f2-w20_cs(z))/rs**Integer(2)) + w20_G(rs,z)

# eq 17

@helper
def f_w20(rs, zeta):
    return w20_ec(rs,Integer(0)) + (w20_ec(rs,Integer(1)) - w20_ec(rs,Integer(0)))*f_zeta(zeta)

def f(rs, zeta):
    return f_w20(rs, zeta)

TYPE = "lda_exc"
