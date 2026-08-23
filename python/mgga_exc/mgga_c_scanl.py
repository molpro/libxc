"""
 Copyright (C) 2019 Daniel Mejia-Rodriguez
               2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_c_scanl_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_scanl_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

include('mgga_c_scan')
include('mgga_k_pc07')

# Deorbitalized SCAN correlation.  Unlike the exchange case the indicator is
# built from the *total* tau against the von Weizsaecker term of the *total*
# density, so the substitution leaves the spin-vW residue that
# mgga_alpha_total_deorb carries explicitly; the dominant tau-against-tau_W
# cancellation still vanishes analytically.  The orbital tau never enters, so
# ts0/ts1 are unused.

@helper
def scanl_c_f(rs, z, xt, xs0, xs1, us0, us1):
    return (
        scan_c_f_a(rs, z, xt, xs0, xs1,
        mgga_alpha_total_deorb(z, xt, xs0, xs1,
        pc07_alpha(xs0, us0), pc07_alpha(xs1, us1)))
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return scanl_c_f(rs, z, xt, xs0, xs1, us0, us1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_scanl_params"
