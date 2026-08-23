"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_k_apbe_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_k_apbe_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

include('gga_x_pbe')

def f(rs, z, xt, xs0, xs1):
    return gga_kinetic(pbe_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_k_apbe_params"
