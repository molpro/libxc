"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_e = param_default("e")
params_a_mu = param_default("mu")

# Equation (7) from the paper

@helper
def tpss_z(x, t):
    return x**Integer(2)/(Integer(8)*t)

@helper
def tpss_qb(x, t):
    return (
        \
        Integer(9)/Integer(20) * (mgga_alpha(x, t) - Integer(1))/sqrt(Integer(1) + params_a_b*mgga_alpha(x, t)*(mgga_alpha(x, t) - Integer(1))) \
        + Integer(2)*mgga_p(x)/Integer(3)
    )

# Equation (10) in all its glory

@helper
def tpss_fxnum(x, t):
    return (
        \
        + (MU_GE + params_a_c*tpss_z(x, t)**tpss_ff(tpss_z(x, t))/(Integer(1) + tpss_z(x, t)**Integer(2))**Integer(2))*mgga_p(x) \
        + Integer(146)/Integer(2025) * tpss_qb(x, t)**Integer(2) \
        - Integer(73)/Integer(405) * tpss_qb(x, t) * sqrt(Integer(1)/Integer(2)*(Integer(9)/Integer(25)*tpss_z(x, t)**Integer(2) + mgga_p(x)**Integer(2))) \
        + MU_GE**Integer(2)/tpss_kappa(x, t) * mgga_p(x)**Integer(2) \
        + Integer(2)*sqrt(params_a_e)*MU_GE*Integer(9)/Integer(25)*tpss_z(x, t)**Integer(2) \
        + params_a_e*params_a_mu*mgga_p(x)**Integer(3)
    )

@helper
def tpss_fxden(x):
    return (
        \
        (Integer(1) + sqrt(params_a_e)*mgga_p(x))**Integer(2)
    )

@helper
def tpss_fx(x, t):
    return tpss_fxnum(x, t)/tpss_fxden(x)
