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
        + f_aux(A_rpa[Integer(1)], b_rpa[Integer(1)], c_rpa[Integer(1)], x0_rpa[Integer(1)], rs)*one_minus_f_zeta(z)
        + f_aux(A_rpa[Integer(2)], b_rpa[Integer(2)], c_rpa[Integer(2)], x0_rpa[Integer(2)], rs)*f_zeta(z)
    )

def f(rs, z):
    return f_vwn(rs, z)

TYPE = "lda_exc"
