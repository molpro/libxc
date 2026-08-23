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
#   mgga_x_msrpbel_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_msrpbel_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")
params_a_eta = param_default("eta")
params_a_c = param_default("c")

# MS-RPBE-l uses the shared ms_fa (with its magnitude clamp) and the
# regularized iso-orbital indicator mgga_alpha_reg; only its RPBE-style
# f0 (exp form) differs from MS, so keep just that here.
# (The 2019 Smeets et al. paper drops the cube in eq (3).)
include('mgga_x_ms')

# KEEP IN SYNC: msrpbel_f0 and msrpbel_f0_delta share the same
# kappa/MU_GE/exp structure.  Algebraic identity:
# f0(p, c) - f0(p, 0)
# = kappa*[(-expm1(-(MU_GE p + c)/kappa)) - (-expm1(-MU_GE p/kappa))]
# = kappa*exp(-MU_GE p/kappa)*(-expm1(-c/kappa));
# the direct difference cancels at large p where both f0 values
# saturate to 1 + kappa.  If either piece is retuned, update both.

@helper
def msrpbel_f0(p, c):
    return Integer(1) + params_a_kappa*(-xc_expm1(-(MU_GE*p + c)/params_a_kappa))

@helper
def msrpbel_f0_delta(p, c):
    return params_a_kappa*exp(-MU_GE*p/params_a_kappa)*(-xc_expm1(-c/params_a_kappa))

@helper
def msrpbel_f(x, u, t):
    return (
        msrpbel_f0(X2S**Integer(2)*x**Integer(2), Integer(0)) + \
        ms_fa(mgga_alpha_reg(x, t, params_a_eta))*msrpbel_f0_delta(X2S**Integer(2)*x**Integer(2), params_a_c)
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(msrpbel_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_msrpbel_params"
