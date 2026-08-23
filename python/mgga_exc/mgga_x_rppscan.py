"""
 Copyright (C) 2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_rppscan_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_rppscan_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_eta = param_default("eta")

include('mgga_x_scan')
include('mgga_x_r2scan')
include('mgga_x_rscan')

# r++SCAN is obtained from rSCAN by replacing the definition of alpha

@helper
def rscan_alpha(rs, z, x, t):
    return mgga_alpha_reg(x, t, params_a_eta)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_rppscan_params"
