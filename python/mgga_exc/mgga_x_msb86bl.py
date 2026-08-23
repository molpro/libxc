"""
 Copyright (C) 2017 M.A.L. Marques
 Copyright (C) 2018 Susi Lehtola
 Copyright (C) 2024 Dogukan Yilmaz

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_msb86bl_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_msb86bl_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")
params_a_eta = param_default("eta")
params_a_c = param_default("c")

# MS-B86b-l uses the shared ms_fa (with its magnitude clamp) and the
# regularized iso-orbital indicator mgga_alpha_reg; only its B86b-style
# f0 (4/5 power) differs from MS, so keep just that here.
# (The 2019 Smeets et al. paper drops the cube in eq (3).)
include('mgga_x_ms')

@helper
def msb86bl_f0(p, c):
    return Integer(1) + (MU_GE*p + c)/(Integer(1) + (MU_GE*p + c)/params_a_kappa)**(Integer(4)/Integer(5))

@helper
def msb86bl_f(x, u, t):
    return (
        msb86bl_f0(X2S**Integer(2)*x**Integer(2), Integer(0)) + \
        ms_fa(mgga_alpha_reg(x, t, params_a_eta))*(msb86bl_f0(X2S**Integer(2)*x**Integer(2), params_a_c) - msb86bl_f0(X2S**Integer(2)*x**Integer(2), Integer(0)))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(msb86bl_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_msb86bl_params"
