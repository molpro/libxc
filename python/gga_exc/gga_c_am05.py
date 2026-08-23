"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_am05_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_am05_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_alpha = param_default("alpha")

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

# Algebraic identity:
# XX + gamma*(1 - XX)
# = 1/(1 + alpha s^2) + gamma * alpha s^2 / (1 + alpha s^2)
# = (1 + gamma * alpha s^2) / (1 + alpha s^2).
# The original 1 - XX(s) cancels 1 - close-to-1 at small s
# (high density); the single-fraction form is cancellation-free.

@helper
def ff(s):
    return (Integer(1) + params_a_gamma*params_a_alpha*s**Integer(2))/(Integer(1) + params_a_alpha*s**Integer(2))

def f(rs, z, xt, xs0, xs1):
    return (
        f_pw(rs, z)*(
        + opz_pow_n( z,Integer(1))/Integer(2) * ff(X2S*xs0)
        + opz_pow_n(-z,Integer(1))/Integer(2) * ff(X2S*xs1)
        )
    )

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_am05_params"
