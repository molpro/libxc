"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

# These numbers are taken from the original reference, but divided by
# two to convert from Rydbergs to Hartrees

A_vwn = maple_list([ Float('0.0310907'), Float('0.01554535'), -Integer(1)/(Integer(6)*pi**Integer(2))])

b_vwn = maple_list([ Float('3.72744'),   Float('7.06042'),    Float('1.13107')  ])

c_vwn = maple_list([Float('12.9352'),   Float('18.0578'),    Float('13.0045')   ])

x0_vwn = maple_list([-Float('0.10498'),  -Float('0.32500'),   -Float('0.0047584')])

A_rpa = maple_list([ Float('0.0310907'),  Float('0.01554535'),  -Integer(1)/(Integer(6)*pi**Integer(2))])

b_rpa = maple_list([Float('13.0720'),    Float('20.1231'),      Float('1.06835')  ])

c_rpa = maple_list([Float('42.7198'),   Float('101.578'),      Float('11.4813')   ])

x0_rpa = maple_list([-Float('0.409286'),  -Float('0.743294'),   -Float('0.228344') ])

@helper
def Q_vwn(b, c):
    return sqrt(Integer(4)*c - b**Integer(2))

@helper
def f1_vwn(b, c):
    return Integer(2)*b/Q_vwn(b, c)

@helper
def f2_vwn(b, c, x0):
    return b*x0/(x0**Integer(2) + b*x0 + c)

@helper
def f3_vwn(b, c, x0):
    return Integer(2)*(Integer(2)*x0 + b)/Q_vwn(b, c)

fpp_vwn = Integer(4)/(Integer(9)*(Integer(2)**(Integer(1)/Integer(3)) - Integer(1)))

@helper
def fx_vwn(b, c, rs):
    return rs + b*sqrt(rs) + c

# At large rs, fx_vwn(b, c, rs) ~ rs, so rs/fx_vwn -> 1 and
# (sqrt(rs) - x0)^2/fx_vwn -> 1: log of close-to-1.  Both are
# routed through xc_log1p of (num - den)/den.  The numerator
# subtractions are written symbolically against fx_vwn so the
# formula stays single-source -- Maple simplifies the leading `rs`
# away before codegen (e.g. rs - fx_vwn(b, c, rs) collapses to
# -b*sqrt(rs) - c), so the emitted C is still cancellation-free
# and any future retuning of fx_vwn flows through automatically.

@helper
def f_aux(A, b, c, x0, rs):
    return (
        A*(
        + xc_log1p((rs - fx_vwn(b, c, rs))/fx_vwn(b, c, rs))
        + (f1_vwn(b, c) - f2_vwn(b, c, x0)*f3_vwn(b, c, x0))*atan(Q_vwn(b, c)/(Integer(2)*sqrt(rs) + b))
        - f2_vwn(b, c, x0)*xc_log1p(((sqrt(rs) - x0)**Integer(2) - fx_vwn(b, c, rs))/fx_vwn(b, c, rs))
        )
    )

@helper
def DMC(rs, z):
    return (
        + f_aux(A_vwn[Integer(2)], b_vwn[Integer(2)], c_vwn[Integer(2)], x0_vwn[Integer(2)], rs)
        - f_aux(A_vwn[Integer(1)], b_vwn[Integer(1)], c_vwn[Integer(1)], x0_vwn[Integer(1)], rs)
    )

@helper
def DRPA(rs, z):
    return (
        + f_aux(A_rpa[Integer(2)], b_rpa[Integer(2)], c_rpa[Integer(2)], x0_rpa[Integer(2)], rs)
        - f_aux(A_rpa[Integer(1)], b_rpa[Integer(1)], c_rpa[Integer(1)], x0_rpa[Integer(1)], rs)
    )
