"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

a0 = Float('0.93222')*RS_FACTOR

kk = Float('9.47362e-3')*RS_FACTOR

# 1 - kk*log1p(rs/kk)/rs = kk*(rs/kk - log1p(rs/kk))/rs
# = kk*xc_x_minus_log1p(rs/kk)/rs,
# cancellation-free at small rs (where the bracket -> 0 as
# close-to-1 - 1).  At the typical density regime rs/kk is large
# (kk ~ 6e-3, rs >~ 0.1), but the rewrite is cleaner regardless.

def f(rs, zeta):
    return -a0*kk*xc_x_minus_log1p(rs/kk)/rs**Integer(2)

TYPE = "lda_exc"
