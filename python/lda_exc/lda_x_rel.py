"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_alpha = param_default("alpha")

t = Symbol("t")

params_a_alpha = Integer(1)
include('lda_x')

@helper
def beta(rs):
    return (Integer(9)*pi/Integer(4))**(Integer(1)/Integer(3))/(rs*M_C)

# Stable bracket = b*sqrt(1+b^2) - arcsinh(b).  Direct evaluation
# has a catastrophic small-b cancellation:
# b*sqrt(1+b^2) = b + b^3/2 - b^5/8 + ...
# arcsinh(b)    = b - b^3/6 + 3 b^5/40 - ...
# difference    = 2 b^3/3 - b^5/5 + 3 b^7/28 - 5 b^9/72 + ...
# No algebraic rewrite eliminates the cancellation, so Taylor is
# used in the small-b regime.  Boundary chosen for ULP-level match
# between the two branches:
# direct at b = 1/2 loses log10(0.5 / 0.078) ~ 0.8 digits,
# leaving ~6 ULPs of imprecision in the difference;
# Taylor truncation ratio at large k asymptotes to b^2 = 1/4 per
# term, so order 58 (terms up to b^57, ~28 nonzero) drops the
# truncation to ~ 0.25^28 = 3.5e-18 relative -- well below ULP.
# The series radius of convergence is 1 (singularities at b = +-i),
# so the cutoff cannot be pushed up to 1 without an explosion in
# the order needed; 1/2 is the natural balance.

@helper
def lda_x_rel_bracket_taylor(b):
    return maple_eval(convert(maple_taylor(t*sqrt(Integer(1)+t**Integer(2)) - asinh(t), t, Integer(0), Integer(58)), polynom), t, b)

@helper
def lda_x_rel_bracket(b):
    return (
        my_piecewise3(b < Integer(1)/Integer(2),
        lda_x_rel_bracket_taylor(b),
        b*sqrt(Integer(1) + b**Integer(2)) - xc_asinh(b))
    )

@helper
def phi(rs):
    return Integer(1) - Float('1.5')*(lda_x_rel_bracket(beta(rs))/beta(rs)**Integer(2))**Integer(2)

def f(rs, z):
    return f_lda_x(rs, z)*phi(rs)

TYPE = "lda_exc"
