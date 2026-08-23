"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_optc_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_optc_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c1 = param_default("c1")
params_a_c2 = param_default("c2")

include('gga_c_pw91')

@helper
def optc_f2(rs, z, xt, xs0, xs1):
    return (
        + f_pw91(rs*(Integer(2)/(Integer(1) + z))**(Integer(1)/Integer(3)),  Integer(1), xs0, xs0, Integer(0))*opz_pow_n( z,Integer(1))/Integer(2)
        + f_pw91(rs*(Integer(2)/(Integer(1) - z))**(Integer(1)/Integer(3)), -Integer(1), xs1, Integer(0), xs1)*opz_pow_n(-z,Integer(1))/Integer(2)
    )

def f(rs, z, xt, xs0, xs1):
    return + params_a_c1*f_pw91(rs, z, xt, xs0, xs1) + (params_a_c2 - params_a_c1)*optc_f2(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_optc_params"
