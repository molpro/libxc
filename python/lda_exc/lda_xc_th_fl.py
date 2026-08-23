"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_xc_th_fl_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_xc_th_fl_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_n = param_default("n")
params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_d = param_default("d")

params_a_n = Integer(4)

params_a_a = maple_list([ Integer(7)/Integer(6),  Integer(8)/Integer(6),  Integer(9)/Integer(6), Integer(10)/Integer(6) ])

params_a_b = maple_list([Integer(0), Integer(0), Integer(0), Integer(0)])
params_a_c = maple_list([Integer(0), Integer(0), Integer(0), Integer(0)])
params_a_d = maple_list([Integer(0), Integer(0), Integer(0), Integer(0)])

include('th')

def f(rs, z):
    return f_th(rs, z, Integer(0), Integer(0), Integer(0))

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_xc_th_fl_params"
