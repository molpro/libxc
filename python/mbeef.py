"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

mbeef_k = Float('6.5124')

# PBEsol transformation

@helper
def mbeef_xi(p):
    return Integer(2)*p/(mbeef_k + p) - Integer(1)

# expansion is better than 1e-13 for large a

@helper
def mbeef_xj0(a):
    return -one_minus_z_pow_n(a, Integer(2))**Integer(3)/(Integer(1) + a**Integer(3)*(Integer(1) + a**Integer(3)))

@helper
def mbeef_xj(a):
    return enforce_smooth_lr(mbeef_xj0, a, Float('1e4'), Integer(4))

# with(orthopoly)

@helper
def mbeef_expansion(x, t):
    return (
        sum((sum((+ mbeef_coefs[i][j]
        * legendre(j-Integer(1), mbeef_xi(X2S**Integer(2)*x**Integer(2)))
        * legendre(i-Integer(1), mbeef_xj(mgga_alpha(x, t)))) for i in range(Integer(1), (mbeef_n) + Integer(1)))) for j in range(Integer(1), (mbeef_n) + Integer(1)))
    )
