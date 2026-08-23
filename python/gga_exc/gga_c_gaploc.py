"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

include('gga_c_gapc')

# The two parameters were fixed by fitting to the exact correlation
# energy per particle of the He atom

gaploc_b = Float('14.709046')

gaploc_a1 = Float('6.54613') + Integer(2)

@helper
def gaploc_alpha(t):
    return (gaploc_a1 + Integer(3)*t**Integer(3))/(Integer(1) + t**Integer(3))

# override definition of gap_G

# The pre-factor is completely different from the one in
# Equation (7). I used the "gfac" from the original code.

@helper
def gap_G(rs, z, xt, par):
    return (
        (Integer(9)*pi/Integer(4))**(Integer(2)/Integer(3))/Float('2.0')
        * gga_s_total(xt)**(gaploc_alpha(gap_t(rs, z, xt)))/rs**Integer(2)
        * (gaploc_b + gga_s_total(xt)**Integer(2))/(Integer(1) + gga_s_total(xt)**(gaploc_alpha(gap_t(rs, z, xt))))
    )

TYPE = "gga_exc"
