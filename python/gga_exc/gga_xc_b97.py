"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_xc_b97_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_xc_b97_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c_x = param_default("c_x")
params_a_c_ss = param_default("c_ss")
params_a_c_ab = param_default("c_ab")

define('lda_c_pw_params')
include('lda_c_pw')

define('lda_x_params')
include('lda_x')

include('b97')

def f(rs, z, xt, xs0, xs1):
    return (
        + b97_f(f_lda_x, Float('0.004'), params_a_c_x, Integer(0), maple_list([Integer(0), Integer(0), Integer(0), Integer(0), Integer(0)]),
        rs, z, xs0, xs1)
        + b97_f(f_pw, Float('0.2'), params_a_c_ss, Float('0.006'), params_a_c_ab,
        rs, z, xs0, xs1)
    )

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_xc_b97_params"
