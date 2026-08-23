"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_lp96_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_lp96_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_C1 = param_default("C1")
params_a_C2 = param_default("C2")
params_a_C3 = param_default("C3")
params_a_C4 = param_default("C4")

def f(rs, zeta):
    return params_a_C1 + params_a_C2*n_total(rs)**(-Integer(1)/Integer(3)) + params_a_C3*n_total(rs)**(-Integer(2)/Integer(3)) + params_a_C4*n_total(rs)**(-Integer(1))

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_lp96_params"
