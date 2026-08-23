"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# replace: "mbrxc_x\(" -> "xc_mgga_x_mbrxc_get_x("

from libxc_codegen import *  # noqa: F401, F403

include('mgga_x_mbrxc_bg')

mggac_b1 = Float('3.712')

mggac_b2 = Float('2.0')

mggac_b4 = Float('0.1')

mggac_b3 = Float('2.595') + Float('0.5197')*mggac_b4 + Float('0.559')*mggac_b2

mggac_b5 = -Integer(3)*mggac_b3

# new definition of Q. The rest of the functional remains the same

# We have Lambda = (32 Pi^2)^(2/3)/(6 Q)

@helper
def mbrxc_Q(x, t):
    return (
        + (Integer(32)*pi)**(Integer(2)/Integer(3))/Integer(6)
        * (Integer(1) + mggac_b4*mgga_alpha_safe(x, t) + mggac_b5*mgga_alpha_safe(x, t)**Integer(2))
        / (mggac_b1 + mggac_b2*mgga_alpha_safe(x, t) + mggac_b3*mgga_alpha_safe(x, t)**Integer(2))
    )

TYPE = "mgga_exc"
REPLACE = [
    ('mbrxc_x\\(', 'xc_mgga_x_mbrxc_get_x('),
]
