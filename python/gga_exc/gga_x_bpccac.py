"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_x_pbe_tca_params')
include('gga_x_pbe')

define('gga_x_pw91_params')
include('gga_x_pw91')

bpccac_malpha = Integer(1)

bpccac_mbeta = Integer(19)

# The non-spin-polarized x is used in Equation (3), while the spin-polarized
# x_sigma was used in the original implementation of the functional.
# The implementation below uses x_sigma.

@helper
def bpccac_fab(x):
    return Integer(1)/(Integer(1) + exp(-bpccac_malpha*(x - bpccac_mbeta)))

@helper
def bpccac_f(x):
    return (Integer(1) - bpccac_fab(x))*pbe_f(x) + bpccac_fab(x)*pw91_f(x)

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(bpccac_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
