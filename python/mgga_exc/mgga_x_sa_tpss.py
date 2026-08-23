"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_e = param_default("e")
params_a_mu = param_default("mu")

sa_a = Float('2.413')

sa_b = Float('0.348')

params_a_b = Float('0.40')

params_a_c = Float('1.59096')

params_a_e = Float('1.537')

params_a_mu = Float('0.21951')

# Equation (8); alpha is the shared mgga_alpha (note arg order t,x)

@helper
def tpss_ff(z):
    return Integer(2)

@helper
def tpss_kappa(x, t):
    return (
        Integer(2)*pi/(Integer(3)*sqrt(Integer(5))) * \
        sqrt(mgga_alpha(x, t) + Integer(1))/sqrt(sa_a + log(mgga_alpha(x, t) + sa_b))
    )

include('tpss_x')

# Paper has sa_f = 1 + kappa*(1 - a1) where a1 = kappa/(kappa + fx).
# Inlined as 1 + kappa*fx/(kappa + fx); algebraic identity,
# cancellation-free at small fx where the direct form computes
# 1 - close-to-1. (sa_a1 is dropped -- it had no other consumers.)

@helper
def sa_f(x, u, t):
    return Integer(1) + tpss_kappa(x, t)*tpss_fx(x, t)/(tpss_kappa(x, t) + tpss_fx(x, t))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(sa_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
