"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

# eqn (5).  For |y| < 1, log((1+y)/(1-y)) = 2*atanh(y), so the
# outer (1 - y^2) factor pairs as (1+y)*(1-y)*atanh(y)/y -- routed
# through xc_atanh, which avoids the log-of-close-to-1 cancellation
# at small y.  In the |y| > 1 branch we keep the original log form
# (its argument is a moderate ratio there), but still write the
# coefficient as (1+y)*(1-y) so the cancellation at |y| -> 1+ is
# computed as a product of two cancellation-free factors instead of
# 1 - y^2 -- which would itself cancel as 1 - close-to-1.

@helper
def meyer_feta(y):
    return (
        Integer(1)/Integer(2)*(Integer(1) + (Integer(1) + y)*(Integer(1) - y)*my_piecewise3(m_abs(y) < Integer(1),
        xc_atanh(y)/y,
        log((Integer(1) + y)/m_abs(Integer(1) - y))/(Integer(2)*y)))
    )

# eqn (7)

@helper
def meyer_lambda(y):
    return (Integer(1) - meyer_feta(y)) / (Integer(3) * y**Integer(2) * meyer_feta(y))

# enhancement factor from eqn (1)

@helper
def meyer_f(x):
    return Integer(1) + meyer_lambda(gga_s(x)/Integer(6))*x**Integer(2)/(Integer(8)*K_FACTOR_C)

def f(rs, zeta, xt, xs0, xs1):
    return gga_kinetic(meyer_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
