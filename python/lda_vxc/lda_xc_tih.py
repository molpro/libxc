"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_vxc

from libxc_codegen import *  # noqa: F401, F403

tih_par = maple_list([ -Float('1.0953'), -Float('0.0334789'), Float('0.414661'), -Float('0.152399'), -Float('0.354691'), Float('0.0390837'), -Float('0.0748531'), -Float('0.136598'), -Float('1.41063'), Float('0.00496577'), Float('0.48315'), Float('4.02905'), -Float('0.420166'), Float('0.0104352'), -Float('1.47409'), -Float('0.442455'), Float('0.625039'), Float('1.30351'), Float('1.37026'), -Float('1.29598'), -Float('1.04305'), -Float('0.909651'), -Float('0.991782'), -Float('0.915745'), Float('1.95026') ])

@helper
def tih_zj(j, n):
    return tanh(tih_par[Integer(2)*j-Integer(1)] + tih_par[Integer(2)*j]*n)

@helper
def tih_vxc(n):
    return tih_par[Integer(17)] + sum((tih_par[i]*tih_zj(i-Integer(17), n)) for i in range(Integer(18), (Integer(25)) + Integer(1)))

def f(rs, z):
    return tih_vxc(n_total(rs))

TYPE = "lda_vxc"
