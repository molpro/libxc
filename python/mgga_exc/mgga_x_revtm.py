"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

include('mgga_x_tm')

# revtm uses the tpss definition of qtilde

tm_b = Float('0.4')

@helper
def tm_qtilde(x, t):
    return (
        Integer(9)/Integer(20) * (mgga_alpha(x, t) - Integer(1))/sqrt(Integer(1) + tm_b*mgga_alpha(x, t)*(mgga_alpha(x, t) - Integer(1)))
        + Integer(2)*tm_p(x)/Integer(3)
    )

TYPE = "mgga_exc"
