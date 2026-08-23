"""
 Copyright (C) 2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_rscan_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_rscan_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_taur = param_default("taur")
params_a_alphar = param_default("alphar")
params_a_d = param_default("d")
params_a_c2 = param_default("c2")

include('mgga_x_scan')

# Coefficients of the rSCAN switching function from SI, in reversed(!) order: 7, 6, ..., 0

rscan_fx = maple_list([-Float('0.023185843322'), Float('0.234528941479'), -Float('0.887998041597'), Float('1.451297044490'), -Float('0.663086601049'), -Float('0.4445555'), -Float('0.667'), Integer(1)])

@helper
def np53(rs, z):
    return n_spin(rs,z)**(Integer(5)/Integer(3))

# First regularization: tau^u -> tau^u + tau_r.
# tau_r gets scaled by 2^(2/3) due to the spin scaling.

@helper
def rscan_alpha0(rs, z, x, t):
    return (np53(rs,z)*m_max(t - x**Integer(2)/Integer(8), Integer(0)))/(np53(rs,z)*K_FACTOR_C + params_a_taur/Integer(2))

# Second regularization: alpha -> alpha^3/(alpha^2 + alpha_r)

@helper
def rscan_alpha(rs, z, x, t):
    return rscan_alpha0(rs, z, x, t)**Integer(3)/(rscan_alpha0(rs, z, x ,t)**Integer(2) + params_a_alphar)

# f(alpha) replaced with a polynomial for alpha in [0, 2.5]

@helper
def rscan_f_alpha_small(a, ff):
    return sum((ff[Integer(8)-i]*a**i) for i in range(Integer(0), (Integer(7)) + Integer(1)))

@helper
def rscan_f_alpha_large(a):
    return -params_a_d*exp(params_a_c2/(Integer(1) - a))

@helper
def rscan_f_alpha(a, ff):
    return my_piecewise3(a <= Float('2.5'), rscan_f_alpha_small(m_min(a, Float('2.5')), ff), rscan_f_alpha_large(m_max(a, Float('2.5'))))

@helper
def rscan_f(rs, z, x, u, t):
    return (
        (scan_h1x(scan_y(x, rscan_alpha(rs, z, x, t)))*(Integer(1) - rscan_f_alpha(rscan_alpha(rs, z, x, t), rscan_fx))
        + scan_h0x*rscan_f_alpha(rscan_alpha(rs, z, x, t), rscan_fx))*scan_gx(x)
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange_nsp(rscan_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_rscan_params"
