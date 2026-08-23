"""
 Copyright (C) 2017 M.A.L. Marques
               2022 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_chachiyo_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_chachiyo_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_ap = param_default("ap")
params_a_bp = param_default("bp")
params_a_cp = param_default("cp")
params_a_af = param_default("af")
params_a_bf = param_default("bf")
params_a_cf = param_default("cf")

@helper
def e0(rs):
    return params_a_ap*xc_log1p(params_a_bp/rs + params_a_cp/rs**Integer(2))

@helper
def e1(rs):
    return params_a_af*xc_log1p(params_a_bf/rs + params_a_cf/rs**Integer(2))

@helper
def f_chachiyo(rs, zeta):
    return e0(rs) + (e1(rs) - e0(rs))*f_zeta(zeta)

def f(rs, zeta):
    return f_chachiyo(rs, zeta)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_chachiyo_params"
