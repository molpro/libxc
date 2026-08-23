"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# replace: "br89_x\(" -> "xc_mgga_x_br89_get_x("

from libxc_codegen import *  # noqa: F401, F403

params_a_at = param_default("at")

include('mgga_x_br89')

mbrxh_a1 = Float('0.23432')

mbrxh_a2 = Float('0.089')

mbrxh_a3 = Float('0.0053')

params_a_at = Integer(0)

# new definition of Q. The rest of the functional remains the same

@helper
def br89_Q(x, u, t):
    return mbrxh_a1*(Integer(2)*t) - K_FACTOR_C + mbrxh_a2*x**Integer(2) + mbrxh_a3*x**Integer(4)

TYPE = "mgga_exc"
REPLACE = [
    ('br89_x\\(', 'xc_mgga_x_br89_get_x('),
]
