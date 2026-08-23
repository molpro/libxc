"""
 Copyright (C) 2017 M.A.L. Marques
 Copyright (C) 2018 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_ms_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_ms_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_b = param_default("b")
params_a_kappa = param_default("kappa")
params_a_c = param_default("c")

# MS interpolation function f(a) = (1-a^2)^3/(1 + a^3 + b a^6).  The
# iso-orbital indicator a is physically O(1), but at a tiny density with
# a huge kinetic-energy density it can reach ~1e26, where f has long
# saturated (-> -1/params_a_b) yet its high derivatives overflow:
# a^6 ~ 1e156 and the quotient's derivative powers (up to a^30 at 4th
# order) exceed DBL_MAX, giving 0*inf = NaN.  Clamp |a| to a large but
# safe bound (f is saturated far below it; a^30 stays < DBL_MAX).  This
# ms_fa is shared via the include with mgga_x_msb and the MS*l family,
# so the clamp also covers msb's f(2*beta).

ms_amax = Float('1e6')

@helper
def ms_fa_raw(a):
    return one_minus_z_pow_n(a, Integer(2))**Integer(3) / (Integer(1) + a**Integer(3) + params_a_b*a**Integer(6))

@helper
def ms_fa(a):
    return ms_fa_raw(m_max(-ms_amax, m_min(a, ms_amax)))

# KEEP IN SYNC: ms_f0 and ms_f0_delta share the same kappa/MU_GE
# structure.  Algebraic identity (with A = MU_GE*p):
# f0(p, c) - f0(p, 0)
# = kappa*[(A + c)/(kappa + A + c) - A/(kappa + A)]
# = kappa^2*c / [(kappa + A + c)*(kappa + A)];
# the direct difference cancels at large p where both f0 values
# saturate to 1 + kappa.  If either piece is retuned, update both.

@helper
def ms_f0(p, c):
    return Integer(1) + params_a_kappa*((MU_GE*p + c)/(params_a_kappa + MU_GE*p + c))

@helper
def ms_f0_delta(p, c):
    return (
        params_a_kappa**Integer(2)*c
        / ((params_a_kappa + MU_GE*p + c)*(params_a_kappa + MU_GE*p))
    )

@helper
def ms_f(x, u, t):
    return (
        ms_f0(X2S**Integer(2)*x**Integer(2), Integer(0)) + \
        ms_fa(mgga_alpha(x,t))*ms_f0_delta(X2S**Integer(2)*x**Integer(2), params_a_c)
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(ms_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_ms_params"
