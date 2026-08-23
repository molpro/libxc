"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_x_pbe_params')
include('gga_x_pbe')
include('gga_x_sfat')

@helper
def ityh_enhancement(xs):
    return pbe_f(xs)

TYPE = "gga_exc"
