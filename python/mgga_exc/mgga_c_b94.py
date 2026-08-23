"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_c_b94_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_b94_params * ) (p->params);
# replace: "br89_x\(" -> "xc_mgga_x_br89_get_x("

from libxc_codegen import *  # noqa: F401, F403

params_a_at = param_default("at")
params_a_css = param_default("css")
params_a_cab = param_default("cab")

define('mgga_x_br89_params')
include('mgga_x_br89')

# This is a fake parameter in libxc
params_a_at = Integer(0)

# Equation 9, same-spin correlation.
# Identity: 1 - 2*log1p(z/2)/z = 2*xc_x_minus_log1p(z/2)/z,
# cancellation-free at small z (where 2*log1p(z/2)/z -> 1).

@helper
def b94_css(rs, z, xs, us, ts):
    return (
        - Float('0.01') * (Integer(1) + z)**(Integer(8)/Integer(3)) * Integer(2)**(-Integer(8)/Integer(3)) * n_total(rs)**(Integer(5)/Integer(3)) * (Integer(2)*ts - xs**Integer(2)/Integer(4))
        * b94_zss(params_a_css, br89_f, rs, z, xs, us, ts)**Integer(4)
        * Integer(2)*xc_x_minus_log1p(b94_zss(params_a_css, br89_f, rs, z, xs, us, ts)/Integer(2))
        / b94_zss(params_a_css, br89_f, rs, z, xs, us, ts)
    )

# Same-spin correlation overall

@helper
def b94_par(rs, z, xs0, xs1, us0, us1, ts0, ts1):
    return (
        + my_piecewise3(screen_dens(rs,  z), Integer(0), b94_css(rs, z_thr( z), xs0, us0, ts0))
        + my_piecewise3(screen_dens(rs, -z), Integer(0), b94_css(rs, z_thr(-z), xs1, us1, ts1))
    )

# Equation 8, opposite-spin correlation.
# z - log1p(z) = xc_x_minus_log1p(z), Taylor branch at small z.

@helper
def b94_cab(rs, z, xs0, xs1, us0, us1, ts0, ts1):
    return (
        - Float('0.8') * one_minus_z_pow_n(z, Integer(2))/Integer(4) * n_total(rs)
        * b94_zab(params_a_cab, br89_f, rs, z, xs0, xs1, us0, us1, ts0, ts1)
        * xc_x_minus_log1p(b94_zab(params_a_cab, br89_f, rs, z, xs0, xs1, us0, us1, ts0, ts1))
    )

# Whole functional

@helper
def b94_c_f(rs, z, xs0, xs1, us0, us1, ts0, ts1):
    return (
        + b94_cab(rs,  z, xs0, xs1, us0, us1, ts0, ts1)
        + b94_par(rs,  z, xs0, xs1, us0, us1, ts0, ts1)
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return b94_c_f(rs, z, xs0, xs1, us0, us1, ts0, ts1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_b94_params"
REPLACE = [
    ('br89_x\\(', 'xc_mgga_x_br89_get_x('),
]
