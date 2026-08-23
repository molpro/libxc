"""
 Copyright (C) 2020 Daniel Mejia-Rodriguez
               2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_c_r2scanl_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_r2scanl_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_eta = param_default("eta")

# r2SCAN correlation's regularization parameter is not exposed by the
# deorbitalized functional (which takes only PC07's a and b), so bake it at
# r2SCAN's default before the $include -- param_default() keeps a value the
# includer has already bound.
params_a_eta = Float('0.001')

include('mgga_c_r2scan')
include('mgga_k_pc07')

# Deorbitalized r2SCAN correlation.  As in mgga_c_scanl.mpl the indicator is
# built from the total tau, so the substitution leaves the spin-vW residue that
# mgga_alpha_total_deorb_reg carries explicitly, while the dominant
# tau-against-tau_W cancellation vanishes analytically.  The orbital tau never
# enters, so ts0/ts1 are unused.

@helper
def r2scanl_c_f(rs, z, xt, xs0, xs1, us0, us1):
    return (
        r2scan_c_f_a(rs, z, xt,
        mgga_alpha_total_deorb_reg(z, xt, xs0, xs1,
        pc07_alpha(xs0, us0), pc07_alpha(xs1, us1), params_a_eta))
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return r2scanl_c_f(rs, z, xt, xs0, xs1, us0, us1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_r2scanl_params"
