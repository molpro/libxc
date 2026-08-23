"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_kt_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_kt_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_delta = param_default("delta")

# The enhancement depends on the reduced gradient only through xs^2, so it is
# fed the squared reduced gradient (gga_exchange_nsp_p): p = xs^2 is rational in
# sigma, which keeps the sigma derivatives cancellation-free.

@helper
def kt_fx(rs, z, p):
    return Integer(1) - params_a_gamma/X_FACTOR_C*n_spin(rs, z)**(Integer(4)/Integer(3))*p/(n_spin(rs, z)**(Integer(4)/Integer(3)) + params_a_delta)

# we want energy per particle

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange_nsp_p(kt_fx, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_kt_params"
