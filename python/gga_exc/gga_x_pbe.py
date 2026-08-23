"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_pbe_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_pbe_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")
params_a_mu = param_default("mu")

# standard PBE
if defined('gga_x_pbe_params'):
  params_a_kappa = Float('0.8040')
  params_a_mu = Float('0.2195149727645171')

# PBE_SOL
if defined('gga_x_pbe_sol_params'):
  params_a_kappa = Float('0.8040')
  params_a_mu = MU_GE

if defined('gga_x_pbe_tca_params'):
  params_a_kappa = Float('1.227')
  params_a_mu = Float('0.2195149727645171')

# 1 - kappa/(kappa + mu*s^2) = mu*s^2/(kappa + mu*s^2); algebraic
# identity, cancellation-free at small s where the direct form
# computes 1 - close-to-1.

@helper
def pbe_f0(s):
    return Integer(1) + params_a_kappa*params_a_mu*s**Integer(2)/(params_a_kappa + params_a_mu*s**Integer(2))

@helper
def pbe_f(x):
    return pbe_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(pbe_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_pbe_params"
