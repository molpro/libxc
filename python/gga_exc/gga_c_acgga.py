"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

cac = Float('1.467')

mtau = Float('4.5')

@helper
def bcgp_pt(t):
    return t*sqrt((mtau + t)/(mtau + cac*t))

define('gga_c_pbe_params')

include('gga_c_pbe')

# override definition of tp

@helper
def tp(rs, z, xt):
    return bcgp_pt(tt(rs, z, xt))

TYPE = "gga_exc"
