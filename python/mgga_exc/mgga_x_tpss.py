"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_tpss_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_tpss_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_e = param_default("e")
params_a_kappa = param_default("kappa")
params_a_mu = param_default("mu")
params_a_BLOC_a = param_default("BLOC_a")
params_a_BLOC_b = param_default("BLOC_b")

if defined('mgga_x_revtpss_params'):
  params_a_b = Float('0.40')
  params_a_c = Float('2.35203946')
  params_a_e = Float('2.16769874')
  params_a_kappa = Float('0.804')
  params_a_mu = Float('0.14')
  params_a_BLOC_a = Float('3.0')
  params_a_BLOC_b = Float('0.0')

@helper
def tpss_ff(z):
    return params_a_BLOC_a + params_a_BLOC_b*z

@helper
def tpss_kappa(x, t):
    return params_a_kappa

include('tpss_x')

# Equation (5)

# Paper has tpss_f = 1 + kappa*(1 - a1) where a1 = kappa/(kappa + fx).
# Inlined here as 1 + kappa*fx/(kappa + fx); algebraic identity, no
# 1 - close-to-1 cancellation at small fx.

@helper
def tpss_f(x, u, t):
    return Integer(1) + tpss_kappa(x, t)*tpss_fx(x, t)/(tpss_kappa(x, t) + tpss_fx(x, t))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(tpss_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_tpss_params"
