"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

pbea_mu = Float('0.00361218645365094697')

pbea_alpha = Float('0.52')

# 1 - (1+X)^(-alpha) = -expm1(-alpha*log1p(X)); preserves precision
# at small X where the direct form would cancel down to alpha*X.

@helper
def pbea_f(x):
    return Integer(1) + KAPPA_PBE*(-xc_expm1(-pbea_alpha*xc_log1p(pbea_mu*x**Integer(2)/(pbea_alpha*KAPPA_PBE))))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(pbea_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
