"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_mpbe_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_mpbe_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a = param_default("a")
params_a_c1 = param_default("c1")
params_a_c2 = param_default("c2")
params_a_c3 = param_default("c3")

@helper
def mpbe_f0(s):
    return s**Integer(2)/(Integer(1) + params_a_a*s**Integer(2))

@helper
def mpbe_f(x):
    return (
        Integer(1)
        + params_a_c1*mpbe_f0(gga_s(x))
        + params_a_c2*mpbe_f0(gga_s(x))**Integer(2)
        + params_a_c3*mpbe_f0(gga_s(x))**Integer(3)
    )

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(mpbe_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_mpbe_params"
