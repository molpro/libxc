"""
 Copyright (C) 2025 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

include('mgga_x_mscan')
include('mgga_c_scan')

@helper
def mscan_f(rs, z, xt, xs0, xs1, ts0, ts1):
    return (
        f_pbe(rs, z, xt, xs0, xs1) + scan_f_alpha(mscan_alpha(rs, z, xt**Integer(2), xs0**Integer(2), xs1**Integer(2), ts0, ts1))*(
        + scan_e0(rs, z, gga_s_total(xt))
        - f_pbe(rs, z, xt, xs0, xs1)
        )
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return mscan_f(rs, z, xt, xs0, xs1, ts0, ts1)

TYPE = "mgga_exc"
