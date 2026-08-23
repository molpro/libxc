"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_k_tf_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_k_tf_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_ax = param_default("ax")

@helper
def f_zeta_k(z):
    return Integer(1)/Integer(2)*(opz_pow_n(z,Integer(5)/Integer(3)) + opz_pow_n(-z,Integer(5)/Integer(3)))

def f(rs, zeta):
    return params_a_ax*f_zeta_k(zeta)/rs**Integer(2)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_k_tf_params"
