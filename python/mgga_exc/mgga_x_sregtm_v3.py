"""
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

# v3-sregTM (Francisco, Cancio & Trickey, J. Chem. Phys. 159, 214102
# (2023)): v2 with the gradient-expansion-compliant eps_p = 0.58568
# instead of 0.5.  Redefine z_rev with the new eps_p; the v1/v2 overrides
# reference it by name, so they pick this up.
include('mgga_x_sregtm_v2')

@helper
def sregtm_zrev(a, p):
    return (Integer(5)*p + Float('0.58568'))/(Integer(5)*p + Integer(3)*m_max(a, Integer(0)) + Float('0.58568'))

TYPE = "mgga_exc"
