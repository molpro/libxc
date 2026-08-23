"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

define('lda_c_pw_params')
include('lda_c_pw')

define('lda_x_params')
include('lda_x')

cc06_cnst = (Integer(3)/(Integer(4)*pi))**(Integer(2)/Integer(3))

cc06_alpha = -Float('0.0007')

cc06_beta = Float('0.0080')*cc06_cnst

cc06_gamma = Float('0.026') *cc06_cnst

@helper
def cc06_f(rs, z, us0, us1):
    return (
        (f_lda_x(rs, z) + f_pw(rs, z))*(Integer(1) +
        (cc06_alpha + cc06_beta*u_total(z, us0, us1))/(Integer(1) + cc06_gamma*u_total(z, us0, us1))
        )
    )

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return cc06_f(rs, z, us0, us1)

TYPE = "mgga_exc"
