"""
 Copyright (C) 2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   hyb_gga_xc_case21_params *params;
#
#   assert(p->params != NULL);
#   params = (hyb_gga_xc_case21_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gammax = param_default("gammax")
params_a_gammac = param_default("gammac")
params_a_ax = param_default("ax")

# exchange-correlation functional: the correlation part does not obey
# exact spin scaling, so keep the whole functional off the
# spin-density evaluation path.
# spin_scaled: false

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')
include('lda_x')

# Teach maple to differentiate the B spline functions

class xbspline(Function):
    def fdiff(self, argindex=1):
        u, ider, params = self.args
        if argindex == 1:
            return xbspline(u, ider+Integer(1), params) * Integer(1)
        return 0

class cbspline(Function):
    def fdiff(self, argindex=1):
        u, ider, params = self.args
        if argindex == 1:
            return cbspline(u, ider+Integer(1), params) * Integer(1)
        return 0

# text after eq 3, B86-type descriptor for exchange

@helper
def case21_ux0(s):
    return params_a_gammax*s**Integer(2)/(Integer(1) + params_a_gammax*s**Integer(2))

# enhancement function, eq 6

@helper
def case21_fx(x):
    return xbspline(case21_ux0(gga_s(x)), Integer(0), params)

# exchange energy, eq 3

@helper
def case21_Ex(rs, z, xs0, xs1):
    return gga_exchange(case21_fx, rs, z, xs0, xs1)

# eq 5

@helper
def case21_t(rs, z, xs0, xs1):
    return (pi/Integer(3))**(Integer(1)/Integer(6)) * (xs0*n_spin(rs, z)**(Integer(4)/Integer(3)) + xs1*n_spin(rs, -z)**(Integer(4)/Integer(3)))/( Integer(4) * n_total(rs)**(Integer(7)/Integer(6)) * mphi(z))

# text before eq 5

@helper
def case21_uc(rs, z, xs0, xs1):
    return (-mphi(z)**Integer(3) * case21_t(rs, z, xs0, xs1)**Integer(2)) / (-mphi(z)**Integer(3) * case21_t(rs, z, xs0, xs1)**Integer(2) + params_a_gammac*f_pw(rs, z))

# correlation energy, eqs 4 and 6

@helper
def case21_Ec(rs, z, xs0, xs1):
    return cbspline(case21_uc(rs, z, xs0, xs1), Integer(0), params)*f_pw(rs, z)

# whole functional

@helper
def f_case21(rs, z, xt, xs0, xs1):
    return (Integer(1)-params_a_ax)*case21_Ex(rs, z, xs0, xs1) + case21_Ec(rs, z, xs0, xs1)

def f(rs, z, xt, xs0, xs1):
    return f_case21(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "hyb_gga_xc_case21_params"
