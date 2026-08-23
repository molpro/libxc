"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

lg93_ad = Float('1e-8')

lg93_b = Float('0.024974')

lg93_a2 = (lg93_ad + Float('0.1234'))/lg93_b

lg93_a4 = Float('29.790')

lg93_a6 = Float('22.417')

lg93_a8 = Float('12.119')

lg93_a10 = Float('1570.1')

lg93_a12 = Float('55.944')

@helper
def lg93_f0(s):
    return (
        Integer(1) + lg93_a2*s**Integer(2) + lg93_a4*s**Integer(4)
        + lg93_a6*s**Integer(6) + lg93_a8*s**Integer(8) + lg93_a10*s**Integer(10) + lg93_a12*s**Integer(12)
    )

@helper
def lg93_f1(s):
    return lg93_f0(s)**lg93_b/(Integer(1) + lg93_ad*s**Integer(2))

@helper
def lg93_f(x):
    return lg93_f1(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(lg93_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
