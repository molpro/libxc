"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_d = param_default("d")
params_a_C0_c = param_default("C0_c")

include('gga_c_pbeloc')

params_a_C0_c = maple_list([Float('0.35'), Float('0.87'), Float('0.50'), Float('2.26')])
params_a_d = Float('4.5')
include('tpss_c')

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return + tpss_f(f_pbe, rs, z, xt, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
