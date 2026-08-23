"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

@helper
def f_zeta_k(z):
    return Integer(1)/Integer(2)*(opz_pow_n(z,Integer(5)/Integer(3)) + opz_pow_n(-z,Integer(5)/Integer(3)))

c1 = Float('3.2372')*RS_FACTOR

c2 = Float('0.00196')*RS_FACTOR

# 1 - c2/rs*log1p(rs/c2) = c2/rs * xc_x_minus_log1p(rs/c2);
# cancellation-free at small rs.

def f(rs, zeta):
    return (
        c1*f_zeta_k(zeta)/rs**Integer(2)
        * c2/rs*xc_x_minus_log1p(rs/c2)
    )

TYPE = "lda_exc"
