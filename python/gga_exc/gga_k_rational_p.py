"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_k_rational_p_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_k_rational_p_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_C2 = param_default("C2")
params_a_p = param_default("p")

@helper
def rational_p_f0(s):
    return (Integer(1) + params_a_C2/params_a_p * s**Integer(2))**(-params_a_p)

@helper
def rational_p_f(x):
    return rational_p_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_kinetic(rational_p_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_k_rational_p_params"
