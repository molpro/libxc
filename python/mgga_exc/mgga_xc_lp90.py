"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_xc_lp90_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_xc_lp90_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c0 = param_default("c0")
params_a_d0 = param_default("d0")
params_a_k = param_default("k")

# Equation (60)
# lp90_f is an opaque helper taking the squared reduced gradient xt2 = xt^2
# (t_vw takes the square; see maple/util.mpl) so the vW term stays
# cancellation-free -- lp90 is linear in it and v2sigma2 is exactly zero.

@helper
def lp90_f(rs, z, xt2, us0, us1):
    return - (params_a_c0 + params_a_d0*t_vw(z, xt2, us0, us1))/(rs/RS_FACTOR + params_a_k)

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return lp90_f(rs, z, xt**Integer(2), us0, us1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_xc_lp90_params"
