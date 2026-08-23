"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_x_b86_mgc_params')
include('gga_x_b86')

cab = Float('0.63')

css = Float('0.96')

# Equation 50, same-spin correlation.
# Identity: 1 - 2*log1p(z/2)/z = (z - 2*log1p(z/2))/z
# = 2*(z/2 - log1p(z/2))/z
# = 2*xc_x_minus_log1p(z/2)/z,
# so the Becke cancellation 1 - close-to-1 at small z (where
# 2*log1p(z/2)/z -> 1) is gone.

@helper
def b88_css(rs, z, xs, ts):
    return (
        - Float('0.01') * (Integer(1) + z)**(Integer(8)/Integer(3)) * Integer(2)**(-Integer(8)/Integer(3)) * n_total(rs)**(Integer(5)/Integer(3)) * (Integer(2)*ts - xs**Integer(2)/Integer(4))
        * b88_zss(css, b86_f, rs, z, xs)**Integer(4)
        * Integer(2)*xc_x_minus_log1p(b88_zss(css, b86_f, rs, z, xs)/Integer(2))
        / b88_zss(css, b86_f, rs, z, xs)
    )

# Same-spin correlation overall

@helper
def b88_par(rs, z, xs0, xs1, ts0, ts1):
    return (
        + my_piecewise3(screen_dens(rs,  z), Integer(0), b88_css(rs, z_thr( z), xs0, ts0))
        + my_piecewise3(screen_dens(rs, -z), Integer(0), b88_css(rs, z_thr(-z), xs1, ts1))
    )

# Equation 49, opposite-spin correlation.
# z - log1p(z) = xc_x_minus_log1p(z), Taylor branch for small z so
# the catastrophic cancellation against the leading z is gone.

@helper
def b88_cab(rs, z, xs0, xs1):
    return (
        - Float('0.8') * one_minus_z_pow_n(z, Integer(2))/Integer(4) * n_total(rs)
        * b88_zab(cab, b86_f, rs, z, xs0, xs1)
        * xc_x_minus_log1p(b88_zab(cab, b86_f, rs, z, xs0, xs1))
    )

# Whole functional

@helper
def b88_c_f(rs, z, xs0, xs1, ts0, ts1):
    return (
        + b88_cab(rs,  z, xs0, xs1)
        + b88_par(rs,  z, xs0, xs1, ts0, ts1)
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return b88_c_f(rs, z, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
