"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_vxc
# replace: "BesselI\(0, " -> "xc_bessel_I0("
# replace: "BesselI\(1, " -> "xc_bessel_I1("

from libxc_codegen import *  # noqa: F401, F403

define('xc_dimensions_2d')
include('mgga_x_2d_prhg07')

# floor the Fermi curvature (tau - tau_W) precision-relatively (xc_reduced_floor)

@helper
def prp10_f(rs, z, x, u, t):
    return (
        -(X_FACTOR_2D_C*prhg07_v(prhg07_y(prhg07_C(x, u, t)))
        - (Integer(2)*sqrt(Integer(2))/(Integer(3)*pi)) * sqrt(Integer(2)*m_max(t - x**Integer(2)/Integer(8), xc_reduced_floor)))*n_spin(rs, z)**(Integer(1)/Integer(2))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return prp10_f(rs, z, xs0, u0, t0)

TYPE = "mgga_vxc"
REPLACE = [
    ('BesselI\\(0, ', 'xc_bessel_I0('),
    ('BesselI\\(1, ', 'xc_bessel_I1('),
]
