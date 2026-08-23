"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_ol2_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_ol2_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

include('gga_k_ol2')

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(ol2_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_ol2_params"
