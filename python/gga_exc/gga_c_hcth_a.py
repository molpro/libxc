"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

gamma_ss = Float('0.2')

cc_ss = maple_list([Float('0.0136823'), Float('0.268920'), -Float('0.550769'),  Float('1.03947'), Float('0.0')])

gamma_ab = Float('0.006')

cc_ab = maple_list([Float('0.836897'),  Float('1.72051'),  -Float('2.78498'),  -Float('4.57504'), Float('0.0')])

include('lda_c_vwn')

include('b97')

def f(rs, z, xt, xs0, xs1):
    return (
        b97_f(f_vwn, gamma_ss, cc_ss, gamma_ab, cc_ab,
        rs, z, xs0, xs1)
    )

TYPE = "gga_exc"
