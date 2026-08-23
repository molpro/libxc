"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_x_sloc_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_x_sloc_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a = param_default("a")
params_a_b = param_default("b")

# https://onlinelibrary.wiley.com/doi/full/10.1002/qua.25312

@helper
def f_sloc(rs, z):
    return (
        -params_a_a/(Integer(2)*(params_a_b + Integer(1))) * n_total(rs)**params_a_b *
        (opz_pow_n(z,params_a_b + Integer(1)) + opz_pow_n(-z,params_a_b + Integer(1)))
    )

def f(rs, z):
    return f_sloc(rs, z)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_x_sloc_params"
