"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_gx_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_gx_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c0 = param_default("c0")
params_a_c1 = param_default("c1")
params_a_alphainf = param_default("alphainf")

if defined('mgga_x_gx_params'):
  params_a_c0 = Float('0.827411')
  params_a_c1 = -Float('0.643560')
  params_a_alphainf = Float('0.852')

gx_cx0 = Integer(4)/Integer(3)*(Integer(2)/pi)**(Integer(1)/Integer(3))

gx_cx1 = X_FACTOR_C

@helper
def gx_gx0(a):
    return (
        + gx_cx0/gx_cx1
        + a*(params_a_c0 + params_a_c1*a)/(Float('1.0') + (params_a_c0 + params_a_c1 - Integer(1))*a) * (Integer(1) - gx_cx0/gx_cx1)
    )

@helper
def gx_gx1(a):
    return Integer(1) + (Integer(1) - params_a_alphainf)*(Integer(1) - a)/(Integer(1) + a)

# gx_gx0 and gx_gx1 both equal 1 at a = 1, so this switch is C0

@helper
def gx_f_a(a):
    return my_piecewise3(a < Integer(1), gx_gx0(a), gx_gx1(a))

@helper
def gx_f(x, u, t):
    return gx_f_a(mgga_alpha(x, t))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(gx_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_gx_params"
