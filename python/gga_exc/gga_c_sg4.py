"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_tscale = param_default("tscale")
params_a_beta = param_default("beta")
params_a_alpha = param_default("alpha")

params_a_tscale = Integer(1)
params_a_beta = Integer(0)
params_a_alpha = Float('0.8')
include('gga_c_zpbeint')

# parameters for beta of SG4, b0 = 3 mu^MGE2/pi^2, mu^MGE2 = 0.26
# The first author (L. Constantin) suggested to use mu^MGE2 = 0.260
# in both exchange and correlation

sg4_b0 = Integer(3)*Float('0.26')/pi**Integer(2)

sg4_sigma = Float('0.07')

# we redefine beta here

@helper
def mbeta(rs, t):
    return sg4_b0 + sg4_sigma*t*(-xc_expm1(-rs**Integer(2)))

TYPE = "gga_exc"
