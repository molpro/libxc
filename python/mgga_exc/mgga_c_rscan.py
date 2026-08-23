"""
 Copyright (C) 2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_alphar = param_default("alphar")
params_a_taur = param_default("taur")
params_a_d = param_default("d")
params_a_c2 = param_default("c2")

include('mgga_c_scan')

# Coefficients of the rSCAN switching function from SI, in reversed(!) order: 7, 6, ..., 0

rscan_fc = maple_list([-Float('0.051848879792'), Float('0.516884468372'), -Float('1.915710236206'), Float('3.061560252175'), -Float('1.535685604549'), -Float('0.4352'), -Float('0.64'), Integer(1)])

@helper
def np53(rs):
    return n_total(rs)**(Integer(5)/Integer(3))

# First regularization: tau^u -> tau^u + tau^r

# Second regularization: alpha -> alpha^3/(alpha^2 + alpha_r)

# f(alpha) replaced with a polynomial for alpha in [0, 2.5]

@helper
def rscan_f_alpha_small(a, ff):
    return sum((ff[Integer(8)-i]*a**i) for i in range(Integer(0), (Integer(7)) + Integer(1)))

@helper
def rscan_f_alpha_large(a):
    return -params_a_d*exp(params_a_c2/(Integer(1) - a))

@helper
def rscan_f_alpha(a, ff):
    return my_piecewise3( a <= Float('2.5'), rscan_f_alpha_small(m_min(a, Float('2.5')),ff), rscan_f_alpha_large(m_max(a, Float('2.5'))) )

# set parameters of f_alpha

params_a_alphar = Float('1e-3')

params_a_taur = Float('1e-4')

@helper
def rscan_alpha0(rs, z, xt, ts0, ts1):
    return (np53(rs)*m_max(t_total(z, ts0, ts1) - xt**Integer(2)/Integer(8), Integer(0)))/((K_FACTOR_C*np53(rs) + Integer(2)**(Integer(2)/Integer(3))*params_a_taur)*t_total(z, Integer(1), Integer(1)))

@helper
def rscan_alpha(rs, z, xt, ts0, ts1):
    return rscan_alpha0(rs, z, xt, ts0, ts1)**Integer(3)/(rscan_alpha0(rs, z, xt, ts0, ts1)**Integer(2) + params_a_alphar)

@helper
def rscan_f(rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        f_pbe(rs, z, xt, xs0, xs1) + rscan_f_alpha(rscan_alpha(rs, z, xt, ts0, ts1), rscan_fc)*(
        + scan_e0(rs, z, gga_s_total(xt))
        - f_pbe(rs, z, xt, xs0, xs1)
        )
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return rscan_f(rs, z, xt, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
