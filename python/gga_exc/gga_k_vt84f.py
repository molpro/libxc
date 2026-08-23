"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_k_vt84f_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_k_vt84f_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_mu = param_default("mu")
params_a_alpha = param_default("alpha")

st = Symbol("st")

# Equation (5)

@helper
def vt84f_f0_orig(s):
    return Integer(1) - params_a_mu*s**Integer(2)*exp(-params_a_alpha*s**Integer(2))/(Integer(1)+params_a_mu*s**Integer(2)) + (-xc_expm1(-params_a_alpha*s**Integer(4))) * (s**(-Integer(2)) - Integer(1)) + Integer(5)*s**Integer(2)/Integer(3)

# The 1/s^2 factor would give 0*infinity at s = 0, so the Taylor
# branch handles that limit; the rest of the function is well-
# behaved.  Even-only series, so order 7 (degree-6 polynomial,
# 3 nonzero coefficients) drops the 4th derivative truncation to
# 8*7*6*5 * c_8 * sqrt(eps)^4 ~ O(1680) * eps^2 ~ 8e-29 below
# XC_EPSILON * |actual 4th derivative ~ O(1)|.

# series() (not taylor) through to_elementary: the s^(-2) factor is a
# removable singularity that taylor() refuses, and the expression
# carries the inert xc_expm1 wrapper -- to_elementary makes it native
# so series() can expand it.

@helper
def vt84f_f0_series(s):
    return maple_eval(convert(maple_series(to_elementary(vt84f_f0_orig(st)), st, Integer(0), Integer(7)), polynom), st, s)

# Glue the functions together

@helper
def vt84f_f0(s):
    return my_piecewise3(s <= sqrt(XC_EPSILON), vt84f_f0_series(s), vt84f_f0_orig(m_max(s, sqrt(XC_EPSILON))))

# Convert from x to s

@helper
def vt84f_f(x):
    return vt84f_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_kinetic(vt84f_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_k_vt84f_params"
