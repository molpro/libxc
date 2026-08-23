"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_r2scan_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_r2scan_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c1 = param_default("c1")
params_a_eta = param_default("eta")
params_a_dp2 = param_default("dp2")

include('mgga_x_rscan')
include('mgga_x_scan')

# eqn S6

# f(alpha) replaced with a polynomial for alpha in [0, 2.5], eqn S7

@helper
def r2scan_f_alpha_neg(a):
    return exp(-params_a_c1*a/(Integer(1) - a))

@helper
def r2scan_f_alpha(a, ff):
    return my_piecewise5(a <= Integer(0), r2scan_f_alpha_neg(m_min(a, Integer(0))), a <= Float('2.5'), rscan_f_alpha_small(m_min(a, Float('2.5')), ff), rscan_f_alpha_large(m_max(a, Float('2.5'))))

# eqn S11

Cn = Integer(20)/Integer(27) + params_a_eta*Integer(5)/Integer(3)

# eqn S12

@helper
def C2(ff):
    return -sum((i*ff[Integer(9)-i]) for i in range(Integer(1), (Integer(8)) + Integer(1))) * (Integer(1)-scan_h0x)

# eqn S10; this is analogous to scan_y

@helper
def r2scan_x(p, ff):
    return (Cn*C2(ff)*exp(-p**Integer(2)/params_a_dp2**Integer(4))+MU_GE)*p

# The enhancement factor as a function of the (regularized) iso-orbital
# indicator.  Taking alpha as the argument lets a deorbitalized variant supply
# the alpha its kinetic energy functional yields directly, rather than
# reconstructing it from tau; see mgga_x_scanl.mpl.

@helper
def r2scan_f_a(x, a):
    return (
        (scan_h1x(r2scan_x(mgga_p(x), rscan_fx))
        + r2scan_f_alpha(a, rscan_fx) * (scan_h0x - scan_h1x(r2scan_x(mgga_p(x), rscan_fx))))*scan_gx(x)
    )

@helper
def r2scan_f(x, u, t):
    return r2scan_f_a(x, mgga_alpha_reg(x, t, params_a_eta))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(r2scan_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_r2scan_params"
