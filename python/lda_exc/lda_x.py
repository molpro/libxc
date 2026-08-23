"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_x_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_x_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_alpha = param_default("alpha")

if defined('lda_x_params'):
  params_a_alpha = Integer(1)

@helper
def f_lda_x(rs, z):
    return params_a_alpha*lda_exchange(rs, z)

def f(rs, z):
    return f_lda_x(rs, z)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_x_params"
