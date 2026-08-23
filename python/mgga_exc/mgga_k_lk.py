"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_k_lk_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_k_lk_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")

# Equation (10)

@helper
def lk_delta(p, q):
    return Integer(8)/Integer(81)*q**Integer(2) - Integer(1)/Integer(9)*p*q + Integer(8)/Integer(243)*p**Integer(2)

# Equation (15). Algebraic identity:
# 1 - 1/(1 + a) = a/(1 + a)
# so 2 - 1/(1+a) - 1/(1+b) = a/(1+a) + b/(1+b), which is
# cancellation-free at small x1, x2 (where the original form
# subtracts two close-to-1 quantities from 2).

@helper
def lk_f0(x1, x2):
    return (
        Integer(1) + params_a_kappa*(
        x1/(params_a_kappa + x1) + x2/(params_a_kappa + x2))
    )

# Equation (16)

@helper
def lk_x1(p, q):
    return Integer(5)/Integer(27)*p + lk_delta(p,q) + (Integer(5)/Integer(27)*p)**Integer(2)/params_a_kappa

# Equation (17)

@helper
def lk_x2(p, q):
    return Integer(2)*(Integer(5)/Integer(27)*p)*lk_delta(p,q)/params_a_kappa + (Integer(5)/Integer(27)*p)**Integer(3)/params_a_kappa**Integer(2)

# Full functional.  p = s^2 is fed directly (mgga_kinetic_p) so the sigma
# derivatives are cancellation-free.

@helper
def lk_f(p, u):
    return lk_f0(lk_x1(p, mgga_q(u)), lk_x2(p, mgga_q(u)))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_kinetic_p(lk_f, rs, z, xs0, xs1, u0, u1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_k_lk_params"
