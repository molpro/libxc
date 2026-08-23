"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_br89_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_br89_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_at = param_default("at")

include('mgga_x_br89')

# This is only used in B00
params_a_at = Integer(0)

@helper
def br89_y(Q):
    return Integer(2)*pi**(Integer(2)/Integer(3))/(Integer(3)*Q)

# lower piece

pgk_a1 = Float('1.5255251812009530')

pgk_a2 = Float('0.4576575543602858')

pgk_a3 = Float('0.4292036732051034')

pgk_b = maple_list([Float('0.4771976183772063'), -Float('1.7799813494556270'), Float('3.8433841862302150'), -Float('9.5912050880518490'), Float('2.1730180285916720'), -Float('30.425133851603660')])

pgk_c = maple_list([Float('0.7566445420735584'), -Float('2.6363977871370960'), Float('5.4745159964232880'), -Float('12.657308127108290'), Float('4.1250584725121360'), -Float('30.425133957163840')])

pgk_d = maple_list([Float('0.00004435009886795587'), Float('0.58128653604457910'), Float('66.742764515940610'), Float('434.26780897229770'), Float('824.7765766052239000'), Float('1657.9652731582120')])

pgk_e = maple_list([Float('0.00003347285060926091'), Float('0.47917931023971350'), Float('62.392268338574240'), Float('463.14816427938120'), Float('785.2360350104029000'), Float('1657.962968223273000000')])

pgk_UB = Float('2.085749716493756')

@helper
def pgk_x_lower(y):
    return (
        (-atan(pgk_a1*y + pgk_a2) + pgk_a3) *
        sum((pgk_c[i]*y**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1)))/sum((pgk_b[i]*y**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1)))
    )

@helper
def pgk_x_upper(y):
    return (
        (acsch(pgk_UB*y) + Integer(2)) *
        sum((pgk_d[i]*y**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1)))/sum((pgk_e[i]*y**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1)))
    )

@helper
def br89_mx(Q):
    return (
        my_piecewise3(
        br89_y(Q) <= Integer(0),
        pgk_x_lower(m_min(br89_y(Q), -br89_min_Q)),
        pgk_x_upper(m_max(br89_y(Q),  br89_min_Q))
        )
    )

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_br89_params"
