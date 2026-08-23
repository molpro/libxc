"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

define('xc_dimensions_1d')

eta0 = -log(sqrt(Integer(2)*pi)) + Integer(3)/Integer(4)

eta1 = Float('0.359933')

eps0 = -pi**Integer(2)/Integer(360)

eps1 = Float('0.00845')

kappa = Float('0.414254')

c0 = kappa*eta0

c1 = Integer(4)*kappa*eta0 + kappa*sqrt(kappa)*eta1

c2 = Integer(5)*eps0 + eps1/kappa

c3 = eps1

# (sqrt(1 + X) - 1)/X = 1/(sqrt(1 + X) + 1) via conjugate
# multiplication; cancellation-free at small X (where the original
# would lose precision computing sqrt(close-to-1) - 1).

@helper
def t(rs):
    return Integer(2)/(sqrt(Integer(1) + Integer(4)*kappa*rs) + Integer(1))

def f(rs, z):
    return t(rs)**Integer(2)*(c0*(Integer(1) - t(rs))**Integer(3) + c1*t(rs)*(Integer(1) - t(rs))**Integer(2) + c2*t(rs)**Integer(2)*(Integer(1) - t(rs)) + c3*t(rs)**Integer(3))

TYPE = "lda_exc"
