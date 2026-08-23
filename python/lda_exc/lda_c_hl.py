"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_hl_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_hl_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_hl_r = param_default("hl_r")
params_a_hl_c = param_default("hl_c")

if defined('lda_c_vbh_params'):
  params_a_hl_r = maple_list([Integer(30), Float('75.0')])
  params_a_hl_c = maple_list([Float('0.0252'), Float('0.0127')])

@helper
def hl_xx(k, rs):
    return rs/params_a_hl_r[k]

@helper
def hl_f0(k, rs):
    return (
        -params_a_hl_c[k]*
        ((Integer(1) + hl_xx(k, rs)**Integer(3))*xc_log1p(Integer(1)/hl_xx(k, rs)) - hl_xx(k, rs)**Integer(2) + Integer(1)/Integer(2)*hl_xx(k, rs) - Integer(1)/Integer(3))
    )

@helper
def hl_f(rs, zeta):
    return hl_f0(Integer(1), rs) + f_zeta(zeta)*(hl_f0(Integer(2), rs) - hl_f0(Integer(1), rs))

def f(rs, zeta):
    return hl_f(rs, zeta)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_hl_params"
