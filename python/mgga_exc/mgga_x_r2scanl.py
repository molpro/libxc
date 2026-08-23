"""
 Copyright (C) 2020 Daniel Mejia-Rodriguez
               2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_r2scanl_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_r2scanl_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_eta = param_default("eta")

include('mgga_x_r2scan')
include('mgga_k_pc07')

# Deorbitalized r2SCAN: the iso-orbital indicator is taken from PC07 rather
# than from the orbital kinetic energy density.  r2SCAN regularizes alpha with
# the denominator K_FACTOR_C + eta*x^2/8, but the numerator is the same
# tau - tau_W, so the von Weizsaecker term still cancels analytically and the
# indicator remains a product.  See mgga_x_scanl.mpl.  The orbital tau never
# enters, so the t argument is unused.

@helper
def r2scanl_f(x, u, t):
    return r2scan_f_a(x, mgga_alpha_deorb_reg(x, pc07_alpha(x, u), params_a_eta))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(r2scanl_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_r2scanl_params"
