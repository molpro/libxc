"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_vmt84_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_vmt84_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_alpha = param_default("alpha")

include('gga_x_vmt')

# Algebraic simplification: with e = exp(-alpha*s^4),
# (1-e)/s^2 + (e-1) = (1-e)*(1/s^2 - 1) = (1-e)*(1-s^2)/s^2
# so the original `-1 + e` cancellation (which was = expm1(-alpha*s^4))
# is folded into the single expm1 factor.

@helper
def vmt84_f0(s):
    return -xc_expm1(-params_a_alpha*s**Integer(4))*(Integer(1) - s**Integer(2))/s**Integer(2)

@helper
def vmt84_f(x):
    return vmt_f(x) + vmt84_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(vmt84_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_vmt84_params"
