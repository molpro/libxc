"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_c_pbe_params')
include('gga_c_pbe')

pkzb_c = Float('0.53')

@helper
def pkzb_perp(rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        + (Integer(1) + pkzb_c*(t_total(z, xs0**Integer(2), xs1**Integer(2))/(Integer(8)*t_total(z, ts0, ts1)))**Integer(2))
        * f_pbe(rs, z, xt, xs0, xs1)
    )

@helper
def pkzb_par(rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        - (Integer(1) + pkzb_c)*(
        + (xs0**Integer(2)/(Integer(8)*ts0))**Integer(2)*gga_stoll_par(f_pbe, rs,  z, xs0,  Integer(1))
        + (xs1**Integer(2)/(Integer(8)*ts1))**Integer(2)*gga_stoll_par(f_pbe, rs, -z, xs1, -Integer(1))
        )
    )

@helper
def pkzb_f(rs, z, xt, xs0, xs1, ts0, ts1):
    return pkzb_perp(rs, z, xt, xs0, xs1, ts0, ts1) + pkzb_par(rs, z, xt, xs0, xs1, ts0, ts1)

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return pkzb_f(rs, z, xt, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
