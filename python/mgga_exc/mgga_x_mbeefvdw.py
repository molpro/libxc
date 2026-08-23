"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

mbeef_n = Integer(5)

mbeef_coefs = maple_list([ maple_list([ Float('1.17114923e+00'),  Float('1.15594371e-01'), -Float('5.32167416e-02'), -Float('2.01131648e-02'),  Float('1.41417107e-03')]), maple_list([-Float('6.76157938e-02'),  Float('4.53837246e-02'), -Float('2.22650139e-02'),  Float('1.92374554e-02'),  Float('9.19317034e-07')]), maple_list([ Float('1.48659502e-02'),  Float('3.18024096e-02'), -Float('5.21818079e-03'),  Float('1.33707403e-07'), -Float('5.00749348e-07')]), maple_list([ Float('1.40794142e-03'), -Float('6.08338264e-03'), -Float('6.57949254e-07'), -Float('5.49909413e-08'),  Float('5.74317889e-08')]), maple_list([ Float('1.41530486e-04'), -Float('1.00478906e-07'),  Float('2.01895739e-07'),  Float('3.97324768e-09'), -Float('3.40722258e-09')]) ])

include('mbeef')

@helper
def mbeefvdw_f(x, u, t):
    return mbeef_expansion(x, t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(mbeefvdw_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
