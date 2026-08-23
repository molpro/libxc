"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_mu = param_default("mu")
params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_e = param_default("e")

params_a_mu = MU_GE
params_a_b = Float('0.4')
params_a_c = Float('2.14951')
params_a_e = Float('1.987')

vt84_gamma = Float('0.000023')

@helper
def tpss_ff(z):
    return Integer(3)

@helper
def tpss_kappa(x, t):
    return Integer(1)/(vt84_gamma/params_a_mu**Integer(2) + vt84_gamma/params_a_mu + Integer(1))

include('tpss_x')

# Equation (8)

@helper
def vt84_f(x, u, t):
    return (
        Integer(1)
        + tpss_fx(x, t)*exp(-vt84_gamma*tpss_fx(x, t)/params_a_mu)/(Integer(1) + tpss_fx(x, t))
        + (-xc_expm1(-vt84_gamma*tpss_fx(x, t)**Integer(2)/params_a_mu**Integer(2)))*(params_a_mu/tpss_fx(x, t) - Integer(1))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(vt84_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
