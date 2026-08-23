"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

include('gga_x_ityh')

# Override both halves of the ityh_attenuation pair so they stay
# matched (see KEEP IN SYNC note in gga_x_ityh.mpl).  Replacing only
# ityh_attenuation would leave ityh_one_minus_attenuation pointing
# at the erf primitive, which is wrong here.

@helper
def ityh_attenuation(a):
    return attenuation_yukawa(a)

@helper
def ityh_one_minus_attenuation(a):
    return one_minus_attenuation_yukawa(a)

TYPE = "gga_exc"
