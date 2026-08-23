"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_c_pbe_params')
include('gga_c_pbe')

pbeloc_b0 = Float('0.0375')

pbeloc_a = Float('0.08')

# we redefine beta here

@helper
def mbeta(rs, t):
    return pbeloc_b0 + pbeloc_a*t**Integer(2)*(-xc_expm1(-rs**Integer(2)))

TYPE = "gga_exc"
