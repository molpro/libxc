"""
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

b = Symbol("b")

# parameters from page 3

lak_h0x = Float('1.174')

lak_mu_ax = -(Integer(97) + Integer(3)*lak_h0x + sqrt((Integer(3)*lak_h0x)**Integer(2) + Integer(74166)*lak_h0x - Integer(64175)))/Integer(1200)

lak_nu_a = (Integer(73)-Integer(50)*lak_mu_ax)/Integer(5000)

lak_mu_sx = (Integer(10)+Integer(60)*lak_mu_ax)/Integer(81)

lak_nu_s = -(Integer(1606) - Integer(50)*lak_mu_ax)/Integer(18225)

lak_bx = Float('4.9479')

lak_ax = Float('1.1')

lak_anum = Integer(5)

# SI eq 2

# SI eq 4. lak_one_minus_gx (= m_recexp) is the cancellation-free
# 1 - gx form, used in lak_hx_ge4 below.  lak_gx uses the matching
# m_one_minus_recexp so gx itself is cancellation-free at large s
# (where gx -> 0).  m_one_minus_recexp and m_recexp share the same
# guard/clamp and are exact complements, so the two cannot drift.

@helper
def lak_one_minus_gx(s):
    return m_recexp(sqrt(s)/lak_bx)

@helper
def lak_gx(s):
    return m_one_minus_recexp(sqrt(s)/lak_bx)

# SI eq 5. This term has poor behavior around a=0, so we have to do
# a series expansion.  Odd-only series in a (terms 1, a, a^3, a^5,
# ...), so order 6 (degree-5 polynomial) suffices for 4th
# derivative ULP at the XC_EPSILON cutoff: truncation 4th deriv
# is 7*6*5*4 * c_7 * eps^3 ~ O(840) * eps^3 ~ 8e-46, far below
# XC_EPSILON * |actual 4th derivative ~ O(1)|.

# SI eq 6

lak_c1 = lak_mu_ax/(lak_h0x-Integer(1))

# SI eq 7

lak_c2 = (lak_mu_ax + lak_nu_a)/(lak_h0x-Integer(1))

@helper
def lak_fx0(a):
    return Integer(2)/pi * atan(pi/Integer(2)*(lak_c1*(a-Integer(1))/a + lak_c2*(a-Integer(1))**Integer(2)))

@helper
def lak_fx_taylor(a):
    return maple_eval(convert(maple_eval(maple_series(lak_fx0(b), b, Integer(0), Integer(6)), csgn, -Integer(1)),polynom), b, a)

@helper
def lak_fx(a):
    return my_piecewise3(a <= XC_EPSILON, lak_fx_taylor(a), lak_fx0(m_max(a,XC_EPSILON)))

# SI eq 8

# SI eq 9; uses lak_one_minus_gx so the 1 - close-to-1 cancellation
# at large s (where lak_gx -> 1) is gone.

@helper
def lak_hx_ge4(s):
    return Integer(1) + lak_mu_sx*s**Integer(2) + lak_nu_s*s**Integer(4) + lak_h0x*lak_one_minus_gx(s)

# SI eq 10

@helper
def lak_kx(s):
    return m_recexp((s/lak_ax)**Integer(2) * (Integer(1)+s**Integer(2)))

@helper
def lak_h1x(s):
    return lak_hx_ge4(s) + lak_kx(s)*(lak_ax - lak_hx_ge4(s))

# SI eq 11

@helper
def lak_gnum(s):
    return m_one_minus_recexp((s/lak_anum)**Integer(2))

@helper
def lak_fsa(s, a):
    return lak_h0x*lak_gx(s) + (Integer(1)-lak_fx(a))*(lak_h1x(s)-lak_h0x)*lak_gnum(s)

# Build the functional

@helper
def lak_f(x, u, t):
    return lak_fsa(x*X2S, mgga_alpha_safe(x,t))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(lak_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
