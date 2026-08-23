"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_pw91_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_pw91_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_d = param_default("d")
params_a_f = param_default("f")
params_a_alpha = param_default("alpha")
params_a_expo = param_default("expo")

if defined('gga_x_pw91_params'):
  params_a_a = Float('0.19645')
  params_a_b = Float('7.7956')
  params_a_c = Float('0.2743')
  params_a_d = -Float('0.1508')
  params_a_f = Float('0.004')
  params_a_alpha = Integer(100)
  params_a_expo = Integer(4)

@helper
def pw91_num(s):
    return (
        (params_a_c + params_a_d*exp(-params_a_alpha*s**Integer(2)))*s**Integer(2)
        - params_a_f*s**params_a_expo
    )

@helper
def pw91_den(s):
    return Integer(1) + s*params_a_a*xc_asinh(params_a_b*s) + params_a_f*s**params_a_expo

# pw91_f = 1 + pw91_num/pw91_den = (pw91_den + pw91_num)/pw91_den. The
# +params_a_f*s^expo in the denominator and -params_a_f*s^expo in the numerator
# cancel analytically, so forming the combined numerator directly is a
# mathematically identical but cancellation-free arrangement. The 1 + num/den
# form loses all precision at large s, where num/den -> -1 and the true
# enhancement is a tiny positive number (e.g. the gga_c_op_pw91 N-atom tail,
# where the huge 1/pw91_f amplifies the lost digits into a ~2500x error).

@helper
def pw91_fnum(s):
    return (
        Integer(1) + s*params_a_a*xc_asinh(params_a_b*s)
        + (params_a_c + params_a_d*exp(-params_a_alpha*s**Integer(2)))*s**Integer(2)
    )

@helper
def pw91_f(x):
    return pw91_fnum(gga_s(x))/pw91_den(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(pw91_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_pw91_params"
