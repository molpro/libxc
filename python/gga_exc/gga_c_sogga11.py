"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_sogga11_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_sogga11_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_sogga11_a = param_default("sogga11_a")
params_a_sogga11_b = param_default("sogga11_b")

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

mbeta = Float('15.75592')*Float('0.004235')

# the usual value of 0.066726

malpha = mbeta/(Integer(16)*Integer(2)**(Integer(2)/Integer(3)))

@helper
def sogga11_yy(rs, z, xt):
    return -malpha*mphi(z)*xt**Integer(2)/(rs*f_pw(rs, z))

@helper
def sogga11_f0(rs, z, xt):
    return sogga11_yy(rs, z, xt)/(Integer(1) + sogga11_yy(rs, z, xt))

@helper
def sogga11_f1(rs, z, xt):
    return -xc_expm1(-sogga11_yy(rs, z, xt))

@helper
def sogga11_t0(rs, z, xt):
    return sum((params_a_sogga11_a[i]*sogga11_f0(rs, z, xt)**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1)))

@helper
def sogga11_t1(rs, z, xt):
    return sum((params_a_sogga11_b[i]*sogga11_f1(rs, z, xt)**(i-Integer(1))) for i in range(Integer(1), (Integer(6)) + Integer(1)))

@helper
def sogga11_f(rs, z, xt, xs0, xs1):
    return f_pw(rs, z)*(sogga11_t0(rs, z, xt) + sogga11_t1(rs, z, xt))

def f(rs, z, xt, xs0, xs1):
    return sogga11_f(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_sogga11_params"
