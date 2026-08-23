"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('xc_dimensions_2d')

_2d_pbe_kappa = Float('0.4604')

_2d_pbe_mu = Float('0.354546875')

@helper
def _2d_pbe_f0(s):
    return Integer(1) + _2d_pbe_kappa*_2d_pbe_mu*s**Integer(2)/(_2d_pbe_kappa + _2d_pbe_mu*s**Integer(2))

@helper
def _2d_pbe_f(x):
    return _2d_pbe_f0(X2S_2D*x)

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(_2d_pbe_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
