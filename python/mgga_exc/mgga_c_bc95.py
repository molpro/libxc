"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_c_bc95_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_bc95_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_css = param_default("css")
params_a_copp = param_default("copp")

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

# The B97 function g

@helper
def bc95_gpar(xs, ts):
    return ts*Fermi_D(xs, ts)/(K_FACTOR_C*(Integer(1) + params_a_css*xs**Integer(2))**Integer(2))

@helper
def bc95_gperp(xs0, xs1):
    return Integer(1)/(Integer(1) + params_a_copp*(xs0**Integer(2) + xs1**Integer(2)))

# The parallel and perpendicular components of the energy

@helper
def bc95_fpar(rs, z, xs0, xs1, ts0, ts1):
    return (
        + lda_stoll_par(f_pw, rs,  z) * bc95_gpar(xs0, ts0)
        + lda_stoll_par(f_pw, rs, -z) * bc95_gpar(xs1, ts1)
    )

@helper
def bc95_fperp(rs, z, xs0, xs1):
    return lda_stoll_perp(f_pw, rs, z) * bc95_gperp(xs0, xs1)

@helper
def f_bc95(rs, z, xs0, xs1, ts0, ts1):
    return (
        + bc95_fpar (rs, z, xs0, xs1, ts0, ts1)
        + bc95_fperp(rs, z, xs0, xs1)
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return f_bc95(rs, z, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_bc95_params"
