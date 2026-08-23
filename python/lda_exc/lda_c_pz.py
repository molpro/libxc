"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_pz_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_pz_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_beta1 = param_default("beta1")
params_a_beta2 = param_default("beta2")
params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_d = param_default("d")

if defined('lda_c_pz_params'):
  params_a_gamma = maple_list([-Float('0.1423'), -Float('0.0843')])
  params_a_beta1 = maple_list([ Float('1.0529'), Float('1.3981')])
  params_a_beta2 = maple_list([ Float('0.3334'), Float('0.2611')])
  params_a_a = maple_list([ Float('0.0311'), Float('0.01555')])
  params_a_b = maple_list([-Float('0.048'), -Float('0.0269')])
  params_a_c = maple_list([ Float('0.0020'), Float('0.0007')])
  params_a_d = maple_list([-Float('0.0116'), -Float('0.0048')])

# Equation C3

@helper
def ec_low(i, rs):
    return (
        params_a_gamma[i] / \
        (Integer(1) + params_a_beta1[i]*sqrt(rs) + params_a_beta2[i]*rs)
    )

# Equation [1].C5

@helper
def ec_high(i, rs):
    return (
        params_a_a[i]*log(rs) + params_a_b[i] \
        + params_a_c[i]*rs*log(rs) + params_a_d[i]*rs
    )

@helper
def ec(i, x):
    return my_piecewise3(x >= Integer(1), ec_low(i, x), ec_high(i, x))

@helper
def f_pz(rs, zeta):
    return (
        \
        ec(Integer(1), rs) + (ec(Integer(2), rs) - ec(Integer(1), rs))*f_zeta(zeta)
    )

def f(rs, zeta):
    return f_pz(rs, zeta)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_pz_params"
