"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_k_lgap_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_k_lgap_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")
params_a_mu = param_default("mu")

# Equation (20)

@helper
def lgap_f0(s):
    return Integer(1) + params_a_kappa*(-xc_expm1(-sum((params_a_mu[i]*s**(i)) for i in range(Integer(1), (Integer(3)) + Integer(1)))))

@helper
def lgap_f(x):
    return lgap_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_kinetic(lgap_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_k_lgap_params"
