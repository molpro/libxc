"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

include('op')

# Xalpha

op_qab = Float('2.5654')

@helper
def op_enhancement(xs):
    return Integer(1)

TYPE = "gga_exc"
