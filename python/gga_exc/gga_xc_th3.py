"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_xc_th3_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_xc_th3_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_n = param_default("n")
params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_d = param_default("d")

params_a_n = Integer(19)

params_a_a = maple_list([ Integer(7)/Integer(6),  Integer(8)/Integer(6),  Integer(9)/Integer(6), Integer(10)/Integer(6), Integer(17)/Integer(12), Integer(9)/Integer(6), Integer(10)/Integer(6), Integer(11)/Integer(6), Integer(10)/Integer(6), Integer(11)/Integer(6), Integer(12)/Integer(6), Integer(10)/Integer(6), Integer(11)/Integer(6), Integer(12)/Integer(6),  Integer(7)/Integer(6),  Integer(8)/Integer(6), Integer(9)/Integer(6), Integer(10)/Integer(6), Integer(13)/Float('12.0') ])

params_a_b = maple_list([Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(1), Integer(1), Integer(1), Integer(1), Integer(0)])
params_a_c = maple_list([Integer(0), Integer(0), Integer(0), Integer(0), Integer(1), Integer(1), Integer(1), Integer(1), Integer(2), Integer(2), Integer(2), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0)])
params_a_d = maple_list([Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(1), Integer(1), Integer(1), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0)])

include('th')

def f(rs, z, xt, xs0, xs1):
    return f_th(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_xc_th3_params"
