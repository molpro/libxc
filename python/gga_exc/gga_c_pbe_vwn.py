"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_pbe_vwn_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_pbe_vwn_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")
params_a_gamma = param_default("gamma")
params_a_BB = param_default("BB")

include('lda_c_vwn')
if defined('gga_c_pbe_params'):
  params_a_beta = Float('0.06672455060314922')
  params_a_gamma = (Integer(1) - log(Integer(2)))/pi**Integer(2)
  params_a_BB = Integer(1)

mgamma = params_a_gamma

@helper
def mbeta(rs, t):
    return params_a_beta

BB = params_a_BB

@helper
def tp(rs, z, xt):
    return tt(rs, z, xt)

# Equation (8)

@helper
def A(rs, z, t):
    return mbeta(rs, t)/(mgamma*xc_expm1(-f_vwn(rs, z)/(mgamma*mphi(z)**Integer(3))))

# Equation (7)

@helper
def f1(rs, z, t):
    return t**Integer(2) + BB*A(rs, z, t)*t**Integer(4)

@helper
def f2(rs, z, t):
    return mbeta(rs, t)*f1(rs, z, t)/(mgamma*(Integer(1) + A(rs, z, t)*f1(rs, z, t)))

@helper
def fH(rs, z, t):
    return mgamma*mphi(z)**Integer(3)*xc_log1p(f2(rs, z, t))

@helper
def f_pbe(rs, z, xt, xs0, xs1):
    return f_vwn(rs, z) + fH(rs, z, tp(rs, z, xt))

def f(rs, z, xt, xs0, xs1):
    return f_pbe(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_pbe_vwn_params"
