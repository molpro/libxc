"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_rpbe_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_rpbe_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_rpbe_kappa = param_default("rpbe_kappa")
params_a_rpbe_mu = param_default("rpbe_mu")

if defined('gga_x_rpbe_params'):
  params_a_rpbe_kappa = KAPPA_PBE
  params_a_rpbe_mu = MU_PBE

@helper
def rpbe_f0(s):
    return (
        Integer(1) + params_a_rpbe_kappa * (
        -xc_expm1(-params_a_rpbe_mu*s**Integer(2)/params_a_rpbe_kappa)
        )
    )

@helper
def rpbe_f(x):
    return rpbe_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(rpbe_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_rpbe_params"
