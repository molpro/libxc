"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

beefvdw_coeffs = maple_list([ Float('1.516501714e0'),   Float('4.413532099e-1'), -Float('9.182135241e-2'), -Float('2.352754331e-2'), Float('3.418828455e-2'),  Float('2.411870076e-3'), -Float('1.416381352e-2'),  Float('6.975895581e-4'), Float('9.859205137e-3'), -Float('6.737855051e-3'), -Float('1.573330824e-3'),  Float('5.036146253e-3'), -Float('2.569472453e-3'), -Float('9.874953976e-4'),  Float('2.033722895e-3'), -Float('8.018718848e-4'), -Float('6.688078723e-4'),  Float('1.030936331e-3'), -Float('3.673838660e-4'), -Float('4.213635394e-4'), Float('5.761607992e-4'), -Float('8.346503735e-5'), -Float('4.458447585e-4'),  Float('4.601290092e-4'), -Float('5.231775398e-6'), -Float('4.239570471e-4'),  Float('3.750190679e-4'),  Float('2.114938125e-5'), -Float('1.904911565e-4'),  Float('7.384362421e-5') ])

beefvdw_k = Integer(4)

@helper
def beefvdw_xi(p):
    return Integer(2)*p/(beefvdw_k + p) - Integer(1)

# with(orthopoly)

@helper
def beefvdw_f(x):
    return sum((beefvdw_coeffs[i]*legendre(i-Integer(1), beefvdw_xi(X2S**Integer(2)*x**Integer(2)))) for i in range(Integer(1), (Integer(30)) + Integer(1)))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(beefvdw_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
