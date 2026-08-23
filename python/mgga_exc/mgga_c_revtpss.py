"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_c_revtpss_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_revtpss_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

include('gga_c_regtpss')
include('tpss_c')

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return + tpss_f(f_pbe, rs, z, xt, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_revtpss_params"
