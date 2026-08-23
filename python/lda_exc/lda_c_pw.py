"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_pw_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_pw_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_fz20 = param_default("fz20")
params_a_pp = param_default("pp")
params_a_a = param_default("a")
params_a_alpha1 = param_default("alpha1")
params_a_beta1 = param_default("beta1")
params_a_beta2 = param_default("beta2")
params_a_beta3 = param_default("beta3")
params_a_beta4 = param_default("beta4")

if defined('lda_c_pw_params'):
  params_a_pp = maple_list([Integer(1), Integer(1), Integer(1)])
  params_a_a = maple_list([Float('0.031091'), Float('0.015545'), Float('0.016887')])
  params_a_alpha1 = maple_list([Float('0.21370'), Float('0.20548'), Float('0.11125')])
  params_a_beta1 = maple_list([Float('7.5957'), Float('14.1189'), Float('10.357')])
  params_a_beta2 = maple_list([Float('3.5876'), Float('6.1977'), Float('3.6231')])
  params_a_beta3 = maple_list([Float('1.6382'), Float('3.3662'), Float('0.88026')])
  params_a_beta4 = maple_list([Float('0.49294'), Float('0.62517'), Float('0.49671')])
  params_a_fz20 = Float('1.709921')

if defined('lda_c_pw_modified_params'):
  params_a_a = maple_list([Float('0.0310907'), Float('0.01554535'), Float('0.0168869')])
  params_a_fz20 = Float('1.709920934161365617563962776245')

# Equation (10)

@helper
def g_aux(k, rs):
    return (
        params_a_beta1[k]*sqrt(rs) + params_a_beta2[k]*rs
        + params_a_beta3[k]*rs**Float('1.5') + params_a_beta4[k]*rs**(params_a_pp[k] + Integer(1))
    )

@helper
def g(k, rs):
    return (
        -Integer(2)*params_a_a[k]*(Integer(1) + params_a_alpha1[k]*rs)
        * xc_log1p(Integer(1)/(Integer(2)*params_a_a[k]*g_aux(k, rs)))
    )

# Equation (8)

# Attention, the function g parametrizes -alpha

@helper
def f_pw(rs, zeta):
    return (
        g(Integer(1), rs) + zeta**Integer(4)*f_zeta(zeta)*(g(Integer(2), rs) - g(Integer(1), rs) + g(Integer(3), rs)/params_a_fz20)
        - f_zeta(zeta)*g(Integer(3), rs)/params_a_fz20
    )

def f(rs, zeta):
    return f_pw(rs, zeta)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_pw_params"
