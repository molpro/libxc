"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_k_ol2_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_k_ol2_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_aa = param_default("aa")
params_a_bb = param_default("bb")
params_a_cc = param_default("cc")

# The third terms in Equations (14) and (15) are wrong.
# The expression below reproduces the OL2 results in Table I.

@helper
def ol2_f(x):
    return (
        + params_a_aa
        + params_a_bb*x**Integer(2)/Float('72.0')
        + params_a_cc*x/(Integer(2)**(Integer(1)/Integer(3)) + Integer(4)*x)
    )

def f(rs, zeta, xt, xs0, xs1):
    return gga_kinetic(ol2_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_k_ol2_params"
