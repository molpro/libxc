"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_c_m05_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_m05_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma_ss = param_default("gamma_ss")
params_a_css = param_default("css")
params_a_gamma_ab = param_default("gamma_ab")
params_a_cab = param_default("cab")

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

include('b97')

# The parallel and perpendicular components of the energy

@helper
def m05_comp(rs, z, spin, xs, t):
    return (
        + lda_stoll_par(f_pw, rs,  z)
        * b97_g(params_a_gamma_ss, params_a_css, xs)
        * Fermi_D_corrected(xs, t)
    )

@helper
def m05_fpar(rs, z, xs0, xs1, t0, t1):
    return (
        + m05_comp(rs,  z,  Integer(1), xs0, t0)
        + m05_comp(rs, -z, -Integer(1), xs1, t1)
    )

@helper
def m05_fperp(rs, z, xs0, xs1, t0, t1):
    return (
        + lda_stoll_perp(f_pw, rs,  z)
        * b97_g(params_a_gamma_ab, params_a_cab, sqrt(xs0**Integer(2) + xs1**Integer(2)))
    )

@helper
def m05_f(rs, z, xs0, xs1, t0, t1):
    return (
        + m05_fpar (rs, z, xs0, xs1, t0, t1)
        + m05_fperp(rs, z, xs0, xs1, t0, t1)
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return m05_f(rs, z, xs0, xs1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_m05_params"
