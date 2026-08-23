"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_c_vsxc_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_vsxc_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_alpha_ss = param_default("alpha_ss")
params_a_dss = param_default("dss")
params_a_alpha_ab = param_default("alpha_ab")
params_a_dab = param_default("dab")

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

include('gvt4')

@helper
def vsxc_comp(rs, z, spin, xs, ts):
    return (
        + lda_stoll_par(f_pw, rs,  z)
        * gtv4(params_a_alpha_ss, params_a_dss, xs, Integer(2)*(ts - K_FACTOR_C))
        * Fermi_D(xs, ts)
    )

# The parallel and perpendicular components of the energy

@helper
def vsxc_fpar(rs, z, xs0, xs1, ts0, ts1):
    return (
        + vsxc_comp(rs,  z,  Integer(1), xs0, ts0)
        + vsxc_comp(rs, -z, -Integer(1), xs1, ts1)
    )

@helper
def vsxc_fperp(rs, z, xs0, xs1, ts0, ts1):
    return (
        + lda_stoll_perp(f_pw, rs,  z)
        * gtv4(params_a_alpha_ab, params_a_dab, sqrt(xs0**Integer(2) + xs1**Integer(2)), Integer(2)*(ts0 + ts1 - Integer(2)*K_FACTOR_C))
    )

@helper
def vsxc_f(rs, z, xs0, xs1, ts0, ts1):
    return (
        + vsxc_fpar (rs, z, xs0, xs1, ts0, ts1)
        + vsxc_fperp(rs, z, xs0, xs1, ts0, ts1)
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return vsxc_f(rs, z, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_vsxc_params"
