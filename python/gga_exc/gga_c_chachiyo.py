"""
 Copyright (C) 2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_chachiyo_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_chachiyo_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_h = param_default("h")

# Functional is based on Chachiyo correlation with modified spin scaling
include('lda_c_chachiyo_mod')

# Reduced gradient parameter

@helper
def cha_t(rs, xt):
    return (pi/Integer(3))**(Integer(1)/Integer(6)) / Integer(4) * n_total(rs)**(Integer(1)/Integer(6)) * xt

# The full functional that agrees with the given reference values is

@helper
def f_chachiyo_gga(rs, z, xt, xs0, xs1):
    return f_chachiyo(rs, z) * (Integer(1) + cha_t(rs, xt)**Integer(2))**(params_a_h / f_chachiyo(rs, z))

def f(rs, z, xt, xs0, xs1):
    return f_chachiyo_gga(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_chachiyo_params"
