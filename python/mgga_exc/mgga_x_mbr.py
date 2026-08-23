"""
 Copyright (C) 2020 M.A.L. Marques
               2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_mbr_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_mbr_params * ) (p->params);
# replace: "br89_x\(" -> "xc_mgga_x_br89_get_x("

from libxc_codegen import *  # noqa: F401, F403

params_a_at = param_default("at")
params_a_lambda = param_default("lambda")
params_a_beta = param_default("beta")
params_a_gamma = param_default("gamma")

include('mgga_x_br89')

params_a_at = Integer(0)

# Equation 15. The three equations below are from mgga_x_tm.mpl; note
# that the numerical factors in the denominator in eqn 15 just
# correspond to going from 'x' to 's'.

@helper
def tm_p(x):
    return (gga_s(x))**Integer(2)

@helper
def tm_y(x):
    return (Integer(2)*params_a_lambda - Integer(1))**Integer(2) * tm_p(x)

# This is tm_f0(x)^2 - 1 from eq. 15 in the paper, with
# tm_f0 = (1 + (700/27)*y + beta*y^2)^(1/10) so that
# tm_f0^2 - 1 = (1 + (700/27)*y + beta*y^2)^(1/5) - 1.
# Routed through expm1(log1p(.)/5) so the (1+epsilon)^(1/5) - 1
# cancellation at small x is exact -- the direct form computes
# 1 - close-to-1.  tm_f0 itself isn't used in mbr (only mbr_Q
# needs the squared-m1 quantity), so we keep just the helper.

@helper
def tm_f0_squared_m1(x):
    return xc_expm1(xc_log1p((Integer(700)/Integer(27))*tm_y(x) + params_a_beta*tm_y(x)**Integer(2))/Integer(5))

# definition below equation 16

@helper
def mbr_D(ts, xs):
    return Integer(2)*ts - Integer(1)/Integer(4) * (Integer(2)*params_a_lambda - Integer(1))**Integer(2) * xs**Integer(2)

# k_\sigma is not defined in the paper, but Subrata Jana
# said on GitLab that k_\sigma = (6\pi^2\rho_\sigma)^{1/3}

k_sigma = (Integer(6)*pi**Integer(2))**(Integer(1)/Integer(3))

# Equation 18. Note that there's a typo in the paper: since Becke's
# tau is two times the kinetic energy density, there should be a factor
# of two in front of tau uniform as well.

@helper
def br89_Q(x, u, t):
    return (
        Integer(1)/Integer(6)*(
        + Integer(6)*(params_a_lambda**Integer(2) - params_a_lambda + Integer(1)/Integer(2))*(Integer(2)*t - Integer(2)*K_FACTOR_C - Integer(1)/Integer(36)*x**Integer(2))
        + Integer(6)/Integer(5)*k_sigma**Integer(2)*tm_f0_squared_m1(x)
        - Integer(2)*params_a_gamma*mbr_D(t, x)
        )
    )

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_mbr_params"
REPLACE = [
    ('br89_x\\(', 'xc_mgga_x_br89_get_x('),
]
