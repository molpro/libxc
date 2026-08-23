"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_aa = param_default("aa")
params_a_bb = param_default("bb")
params_a_cc = param_default("cc")

include('gga_x_pw86')

params_a_aa = Float('2.208')
params_a_bb = Float('9.27')
params_a_cc = Float('0.2')

def f(rs, z, xt, xs0, xs1):
    return gga_kinetic(pw86_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
