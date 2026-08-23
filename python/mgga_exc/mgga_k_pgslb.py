"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_k_pgslb_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_k_pgslb_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_pgslb_mu = param_default("pgslb_mu")
params_a_pgslb_beta = param_default("pgslb_beta")

# Equation (4) and (8)
# p = mgga_p(xs) = s^2 is fed directly (mgga_kinetic_p) so the sigma
# derivatives are cancellation-free

@helper
def pgslb_f0(s2, q):
    return Integer(5)/Integer(3)*s2 + exp(-params_a_pgslb_mu * s2) + params_a_pgslb_beta*q**Integer(2)

@helper
def pgslb_f(p, u):
    return pgslb_f0(p, X2S**Integer(2)*u)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_kinetic_p(pgslb_f, rs, z, xs0, xs1, u0, u1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_k_pgslb_params"
