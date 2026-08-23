"""
 Copyright (C) 2023 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_epc17_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_epc17_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_c = param_default("c")

# Equation (13)

@helper
def epc17_E(rho_ep):
    return -rho_ep / (params_a_a - params_a_b*sqrt(rho_ep) + params_a_c * rho_ep)

# Energy density; require significant proton and electron density

@helper
def f_epc17(rs, zeta):
    return my_piecewise3(And(screen_dens(rs,zeta), screen_dens(rs,-zeta)), Integer(0), epc17_E(n_spin(rs, z_thr(zeta)) * n_spin(rs, z_thr(-zeta))) / n_total(rs))

def f(rs, zeta):
    return f_epc17(rs, zeta)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_epc17_params"
