"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

mbeef_n = Integer(8)

mbeef_coefs = maple_list([ maple_list([ Float('1.18029330e+00'),  Float('8.53027860e-03'), -Float('1.02312143e-01'),  Float('6.85757490e-02'), -Float('6.61294786e-03'), -Float('2.84176163e-02'),  Float('5.54283363e-03'),  Float('3.95434277e-03') ]), maple_list([ -Float('1.98479086e-03'),  Float('1.00339208e-01'), -Float('4.34643460e-02'), -Float('1.82177954e-02'), Float('1.62638575e-02'), -Float('8.84148272e-03'), -Float('9.57417512e-03'),  Float('9.40675747e-03') ]), maple_list([ Float('6.37590839e-03'), -Float('8.79090772e-03'), -Float('1.50103636e-02'),  Float('2.80678872e-02'), -Float('1.82911291e-02'), -Float('1.88495102e-02'),  Float('1.69805915e-07'), -Float('2.76524680e-07') ]), maple_list([ Float('1.44642135e-03'), -Float('3.03347141e-03'),  Float('2.93253041e-03'), -Float('8.45508103e-03'), Float('6.31891628e-03'), -Float('8.96771404e-03'), -Float('2.65114646e-08'),  Float('5.05920757e-08') ]), maple_list([ Float('6.65511484e-04'),  Float('1.19130546e-03'),  Float('1.82906057e-03'),  Float('3.39308972e-03'), -Float('7.90811707e-08'),  Float('1.62238741e-07'), -Float('4.16393106e-08'),  Float('5.54588743e-08') ]), maple_list([ -Float('1.16063796e-04'),  Float('8.22139896e-04'), -Float('3.51041030e-04'),  Float('8.96739466e-04'), Float('2.09603871e-08'), -Float('3.76702959e-08'),  Float('2.36391411e-08'), -Float('3.38128188e-08') ]), maple_list([ -Float('5.54173599e-06'), -Float('5.14204676e-05'),  Float('6.68980219e-09'), -Float('2.16860568e-08'), Float('9.12223751e-09'), -Float('1.38472194e-08'),  Float('6.94482484e-09'), -Float('7.74224962e-09') ]), maple_list([ Float('7.36062570e-07'), -Float('9.40351563e-06'), -Float('2.23014657e-09'),  Float('6.74910119e-09'), -Float('4.93824365e-09'),  Float('8.50272392e-09'), -Float('6.91592964e-09'),  Float('8.88525527e-09') ]) ])

include('mbeef')

@helper
def mbeef_f(x, u, t):
    return mbeef_expansion(x, t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(mbeef_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
