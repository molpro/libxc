"""
 Copyright (C) 2017 M.A.L. Marques
               2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_p86_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_p86_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_aa = param_default("aa")
params_a_bb = param_default("bb")
params_a_malpha = param_default("malpha")
params_a_mbeta = param_default("mbeta")
params_a_mgamma = param_default("mgamma")
params_a_mdelta = param_default("mdelta")
params_a_ftilde = param_default("ftilde")

define('lda_c_pz_params')
include('lda_c_pz')

# Equation (4)

@helper
def p86_DD(z):
    return sqrt(opz_pow_n(z,Integer(5)/Integer(3)) + opz_pow_n(-z,Integer(5)/Integer(3)))/sqrt(Integer(2))

# Equation (6)

@helper
def p86_CC(rs):
    return (
        + params_a_aa
        + (params_a_bb + params_a_malpha*rs + params_a_mbeta*rs**Integer(2))/(Integer(1) + params_a_mgamma*rs + params_a_mdelta*rs**Integer(2) + Float('1.0e4')*params_a_mbeta*rs**Integer(3))
    )

p86_CCinf = params_a_aa + params_a_bb

# Equation (9)

@helper
def p86_x1(rs, xt):
    return xt/sqrt(rs/RS_FACTOR)

@helper
def p86_mPhi(rs, xt):
    return params_a_ftilde*(p86_CCinf/p86_CC(rs))*p86_x1(rs, xt)

# Equation (8)

@helper
def p86_H(rs, z, xt):
    return p86_x1(rs, xt)**Integer(2)*exp(-p86_mPhi(rs, xt))*p86_CC(rs)/p86_DD(z)

@helper
def f_p86(rs, z, xt, xs0, xs1):
    return f_pz(rs, z) + p86_H(rs, z, xt)

def f(rs, z, xt, xs0, xs1):
    return f_p86(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_p86_params"
