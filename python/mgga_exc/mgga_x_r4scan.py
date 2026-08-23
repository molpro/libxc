"""
 Copyright (C) 2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_r4scan_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_r4scan_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_eta = param_default("eta")
params_a_k1 = param_default("k1")
params_a_da4 = param_default("da4")
params_a_dp4 = param_default("dp4")

include('mgga_x_r2scan')

# r4SCAN is obtained from r2SCAN by replacing the enhancement factor

# df2 ~= -0.9353000875519996

@helper
def df2(ff):
    return sum((i*ff[Integer(9)-i]) for i in range(Integer(1), (Integer(8)) + Integer(1)))

# df4 ~=  0.8500359204920018

@helper
def df4(ff):
    return sum(((i-Integer(1))*(i-Integer(2))*ff[Integer(9)-i]) for i in range(Integer(2), (Integer(8)) + Integer(1)))

# eq 53

Cn = (Integer(20)/Integer(27) + params_a_eta*Integer(5)/Integer(3))

# eq 61

@helper
def Caa(ff):
    return Integer(73)/Integer(5000) - df4(ff)/Integer(2)*(scan_h0x-Integer(1))

# eq 62

@helper
def Cpa(ff):
    return Integer(511)/Integer(13500) - Integer(73)/Integer(1500)*params_a_eta - df2(ff)*(Cn*C2(ff)+MU_GE)

# eq 63

@helper
def Cpp(ff):
    return Integer(146)/Integer(2025)*(params_a_eta*Integer(3)/Integer(4) + Integer(2)/Integer(3))**Integer(2) - Integer(73)/Integer(405)*(params_a_eta*Integer(3)/Integer(4) + Integer(2)/Integer(3)) + (Cn * C2(ff) + MU_GE)**Integer(2) / params_a_k1

# eq 59

# eq 60

@helper
def r4scan_dFdamp(p, a):
    return Integer(2)*a**Integer(2)/(Integer(1)+a**Integer(4)) * exp(-(Integer(1)-a)**Integer(2)/params_a_da4**Integer(2) - p**Integer(2)/params_a_dp4**Integer(4))

@helper
def r4scan_dF(ff, p, a):
    return (C2(ff) * ((Integer(1)-a)-Cn*p) + Caa(ff)*(Integer(1)-a)**Integer(2) + Cpa(ff)*p*(Integer(1)-a) + Cpp(ff)*p**Integer(2))*r4scan_dFdamp(p,a)

@helper
def r4scan_f(x, u, t):
    return (scan_h1x(r2scan_x(mgga_p(x), rscan_fx)) + r2scan_f_alpha(mgga_alpha_reg(x, t, params_a_eta), rscan_fx) * (scan_h0x - scan_h1x(r2scan_x(mgga_p(x), rscan_fx))) + r4scan_dF(rscan_fx, mgga_p(x), mgga_alpha_reg(x, t, params_a_eta)))*scan_gx(x)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(r4scan_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_r4scan_params"
