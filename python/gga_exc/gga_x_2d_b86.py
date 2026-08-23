"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('xc_dimensions_2d')

_2d_b86_beta = Float('0.002105')

_2d_b86_gamma = Float('0.000119')

@helper
def _2d_b86_f(x):
    return (Integer(1) + _2d_b86_beta*x**Integer(2))/(Integer(1) + _2d_b86_gamma*x**Integer(2))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(_2d_b86_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
