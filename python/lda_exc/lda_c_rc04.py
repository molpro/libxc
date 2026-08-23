"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

AA = -Float('0.655868')

BB = Float('4.888270')

CC = Float('3.177037')

DD = Float('0.897889')

@helper
def phi(z):
    return Integer(1)/Integer(2)*(opz_pow_n(z,Integer(2)/Integer(3)) + opz_pow_n(-z,Integer(2)/Integer(3)))

@helper
def f_rc04(rs, zeta):
    return phi(zeta)**Integer(3) * (AA*atan(BB + CC*rs) + DD)/rs

def f(rs, zeta):
    return f_rc04(rs, zeta)

TYPE = "lda_exc"
