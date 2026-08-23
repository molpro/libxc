"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_hjs_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_hjs_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

include('gga_x_hjs')

hjs2_xi = Integer(1)/(exp(Integer(20)) - Integer(1))

# (exp(-s) + xi)/(1 + xi) = 1 + expm1(-s)/(1 + xi); at small s this
# would otherwise cancel down to -s/(1+xi). Routed through log1p so
# the small-argument behaviour is exact.

@helper
def hjs2_fs(s):
    return -xc_log1p(xc_expm1(-s)/(Integer(1) + hjs2_xi))

@helper
def hjs_fx(rs, z, x):
    return hjs_f1(rs, z, hjs2_fs(gga_s(x)))

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_hjs_params"
