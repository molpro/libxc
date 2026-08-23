"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_n = param_default("n")
params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_d = param_default("d")
params_a_omega = param_default("omega")

params_a_n = Integer(19)

params_a_a = maple_list([ Integer(13)/Integer(12), Integer(7)/Integer(6),  Integer(8)/Integer(6),  Integer(9)/Integer(6), Integer(10)/Integer(6), Integer(17)/Integer(12), Integer(9)/Integer(6), Integer(10)/Integer(6), Integer(11)/Integer(6), Integer(10)/Integer(6), Integer(11)/Integer(6), Integer(12)/Integer(6), Integer(10)/Integer(6), Integer(11)/Integer(6), Integer(12)/Integer(6),  Integer(7)/Integer(6), Integer(8)/Integer(6),  Integer(9)/Integer(6), Integer(10)/Float('6.0') ])

params_a_b = maple_list([Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(1), Integer(1), Integer(1), Integer(1)])
params_a_c = maple_list([Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(1), Integer(1), Integer(1), Integer(1), Integer(2), Integer(2), Integer(2), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0)])
params_a_d = maple_list([Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(0), Integer(1), Integer(1), Integer(1), Integer(0), Integer(0), Integer(0), Integer(0)])

params_a_omega = maple_list([ +Float('0.678831e+00'), -Float('0.175821e+01'), +Float('0.127676e+01'), -Float('0.160789e+01'), +Float('0.365610e+00'), -Float('0.181327e+00'), +Float('0.146973e+00'), +Float('0.147141e+00'), -Float('0.716917e-01'), -Float('0.407167e-01'), +Float('0.214625e-01'), -Float('0.768156e-03'), +Float('0.310377e-01'), -Float('0.720326e-01'), +Float('0.446562e-01'), -Float('0.266802e+00'), +Float('0.150822e+01'), -Float('0.194515e+01'), +Float('0.679078e+00') ])

include('th')

def f(rs, z, xt, xs0, xs1):
    return f_th(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
