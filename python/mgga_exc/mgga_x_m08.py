"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_m08_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_m08_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_rpbe_kappa = param_default("rpbe_kappa")
params_a_rpbe_mu = param_default("rpbe_mu")
params_a_kappa = param_default("kappa")
params_a_mu = param_default("mu")
params_a_a = param_default("a")
params_a_b = param_default("b")

params_a_rpbe_kappa = Float('0.552')
params_a_rpbe_mu = MU_GE
include('gga_x_rpbe')

params_a_kappa = KAPPA_PBE
params_a_mu = Float('0.21951')
include('gga_x_pbe')

@helper
def m08_f0(a, b, x, t):
    return (
        + pbe_f(x) *mgga_series_w(a, Integer(12), t)
        + rpbe_f(x)*mgga_series_w(b, Integer(12), t)
    )

@helper
def m08_f(x, u, t):
    return m08_f0(params_a_a, params_a_b, x, t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(m08_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_m08_params"
