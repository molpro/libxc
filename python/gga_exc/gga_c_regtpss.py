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

# in the paper we have beta_a = 0.066725

beta_a = Float('0.066724550603149220')

beta_b = Float('0.1')

beta_c = Float('0.1778')

# we redefine beta here

# this is the Hu and Langreth expression

@helper
def mbeta(rs, t):
    return beta_a*(Integer(1) + beta_b*rs)/(Integer(1) + beta_c*rs)

TYPE = "gga_exc"
