"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_pw86_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_pw86_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_aa = param_default("aa")
params_a_bb = param_default("bb")
params_a_cc = param_default("cc")

if defined('gga_x_rpw86_params'):
  params_a_aa = Integer(15)*Float('0.1234')
  params_a_bb = Float('17.33')
  params_a_cc = Float('0.163')

@helper
def pw86_f0(s):
    return (Integer(1) + params_a_aa*s**Integer(2) + params_a_bb*s**Integer(4) + params_a_cc*s**Integer(6))**(Integer(1)/Integer(15))

@helper
def pw86_f(x):
    return pw86_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(pw86_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_pw86_params"
