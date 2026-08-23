"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

include('vwn')

@helper
def f_vwn(rs, z):
    return (
        + f_aux(A_vwn[Integer(1)], b_vwn[Integer(1)], c_vwn[Integer(1)], x0_vwn[Integer(1)], rs)
        + f_aux(A_vwn[Integer(3)], b_vwn[Integer(3)], c_vwn[Integer(3)], x0_vwn[Integer(3)], rs)*f_zeta(z)*one_minus_z_pow_n(z, Integer(4))/fpp_vwn
        +  DMC(rs, z)*f_zeta(z)*z**Integer(4)
    )

def f(rs, z):
    return f_vwn(rs, z)

TYPE = "lda_exc"
