"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_mn12_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_mn12_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c = param_default("c")

define('lda_x_params')
include('lda_x')

mn12_omega_x = Float('2.5')

mn12_gamma_x = Float('0.004')

@helper
def mn12_vx(rs, z):
    return Integer(1)/(Integer(1) + rs/(mn12_omega_x*RS_FACTOR)*(Integer(2)/(Integer(1) + z))**(Integer(1)/Integer(3)))

@helper
def mn12_ux(x):
    return b97_u(mn12_gamma_x, x**Integer(2))

@helper
def mn12_wx(t):
    return (K_FACTOR_C - t)/(K_FACTOR_C + t)

@helper
def mn12_pol1(t):
    return (
        params_a_c[ Integer(1)] + params_a_c[ Integer(2)]*mn12_wx(t) + params_a_c[ Integer(3)]*mn12_wx(t)**Integer(2) + params_a_c[ Integer(4)]*mn12_wx(t)**Integer(3)
        + params_a_c[ Integer(5)]*mn12_wx(t)**Integer(4) + params_a_c[ Integer(6)]*mn12_wx(t)**Integer(5)
    )

@helper
def mn12_pol2(t):
    return (
        params_a_c[ Integer(7)] + params_a_c[ Integer(8)]*mn12_wx(t) + params_a_c[ Integer(9)]*mn12_wx(t)**Integer(2) + params_a_c[Integer(10)]*mn12_wx(t)**Integer(3)
        + params_a_c[Integer(11)]*mn12_wx(t)**Integer(4)
    )

@helper
def mn12_pol3(t):
    return params_a_c[Integer(12)] + params_a_c[Integer(13)]*mn12_wx(t) + params_a_c[Integer(14)]*mn12_wx(t)**Integer(2) + params_a_c[Integer(15)]*mn12_wx(t)**Integer(3)

@helper
def mn12_pol4(t):
    return params_a_c[Integer(16)] + params_a_c[Integer(17)]*mn12_wx(t) + params_a_c[Integer(18)]*mn12_wx(t)**Integer(2)

@helper
def mn12_pol5(t):
    return (
        params_a_c[Integer(19)] + params_a_c[Integer(20)]*mn12_wx(t) + params_a_c[Integer(21)]*mn12_wx(t)**Integer(2) + params_a_c[Integer(22)]*mn12_wx(t)**Integer(3)
        + params_a_c[Integer(23)]*mn12_wx(t)**Integer(4)
    )

@helper
def mn12_pol6(t):
    return params_a_c[Integer(24)] + params_a_c[Integer(25)]*mn12_wx(t) + params_a_c[Integer(26)]*mn12_wx(t)**Integer(2) + params_a_c[Integer(27)]*mn12_wx(t)**Integer(3)

@helper
def mn12_pol7(t):
    return params_a_c[Integer(28)] + params_a_c[Integer(29)]*mn12_wx(t) + params_a_c[Integer(30)]*mn12_wx(t)**Integer(2)

@helper
def mn12_pol8(t):
    return params_a_c[Integer(31)] + params_a_c[Integer(32)]*mn12_wx(t) + params_a_c[Integer(33)]*mn12_wx(t)**Integer(2) + params_a_c[Integer(34)]*mn12_wx(t)**Integer(3)

@helper
def mn12_pol9(t):
    return params_a_c[Integer(35)] + params_a_c[Integer(36)]*mn12_wx(t) + params_a_c[Integer(37)]*mn12_wx(t)**Integer(2)

@helper
def mn12_pol10(t):
    return params_a_c[Integer(38)] + params_a_c[Integer(39)]*mn12_wx(t) + params_a_c[Integer(40)]*mn12_wx(t)**Integer(2)

@helper
def mn12_f(rs, z, x, u, t):
    return (
        + mn12_pol1(t)
        + mn12_pol2(t)*mn12_ux(x)
        + mn12_pol3(t)*mn12_ux(x)**Integer(2)
        + mn12_pol4(t)*mn12_ux(x)**Integer(3)
        + mn12_pol5(t)*mn12_vx(rs, z)
        + mn12_pol6(t)*mn12_ux(x)*mn12_vx(rs, z)
        + mn12_pol7(t)*mn12_ux(x)**Integer(2)*mn12_vx(rs, z)
        + mn12_pol8(t)*mn12_vx(rs, z)**Integer(2)
        + mn12_pol9(t)*mn12_ux(x)*mn12_vx(rs, z)**Integer(2)
        + mn12_pol10(t)*mn12_vx(rs, z)**Integer(3)
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange_nsp(mn12_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_mn12_params"
