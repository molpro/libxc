"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

# eq 26

a1 = -Float('0.0357')

a2 = Float('0.0562')

b1 = -Float('0.0311')

b2 = Float('2.39')

# eq 25

# log((rs/RS_FACTOR + b2)/(rs/RS_FACTOR)) = log(1 + b2*RS_FACTOR/rs);
# routed through log1p so large rs (small b2*RS_FACTOR/rs) keeps
# precision.

def f(rs, zeta):
    return (
        a1/(Integer(1) + a2*rs/RS_FACTOR)
        + b1*xc_log1p(b2*RS_FACTOR/rs)
    )

TYPE = "lda_exc"
