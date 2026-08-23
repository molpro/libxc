"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

include('lda_c_rc04')

msigma = Float('1.43')

malpha = Float('2.30')

@helper
def Bs(s):
    return Integer(1)/(Integer(1) + msigma*s**malpha)

@helper
def f_tcs(rs, z, xt):
    return f_rc04(rs, z)*Bs(gga_s_total(xt))

def f(rs, z, xt, xs0, xs1):
    return f_tcs(rs, z, xt)

TYPE = "gga_exc"
