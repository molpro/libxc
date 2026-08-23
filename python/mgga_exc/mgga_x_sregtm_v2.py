"""
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

# v2-sregTM (Francisco, Cancio & Trickey, J. Chem. Phys. 159, 214102
# (2023)): like v1 but z_rev is used in the strongly-constrained term
# F_x^SC as well, i.e. z_rev replaces the ordinary z everywhere.  This is
# the variant the authors prefer (simpler and slightly better overall).
# Build on v1 and just redirect the z (= tm_tratio) entering F_x^SC.
include('mgga_x_sregtm_v1')

@helper
def tm_tratio(x, t):
    return sregtm_zrev(mgga_alpha(x, t), tm_p(x))

TYPE = "mgga_exc"
