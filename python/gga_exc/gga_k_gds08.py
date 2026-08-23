"""
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_k_gds08_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_k_gds08_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_gamma = param_default("gamma")
params_a_lambda = param_default("lambda")
params_a_A = param_default("A")
params_a_B = param_default("B")
params_a_C = param_default("C")

# TF-lambda-vW base enhancement (as in gga_k_tflw), fed the squared reduced
# gradient (gga_kinetic_p) so the sigma derivatives are cancellation-free.

@helper
def gds08_base(p):
    return params_a_gamma + (params_a_lambda/Integer(8))*p/K_FACTOR_C

# Ghiringhelli-Delle Site LDA correction.  This was previously a separate
# auxiliary functional (lda_k_gds08_worker) combined at runtime through
# xc_mix_init; it is a partial term with no standalone meaning, so it is
# folded in here and the auxiliary functional retired.

@helper
def gds08_ws(rs, z):
    return (
        (Integer(1) + z)/Integer(2) * (
        + params_a_A
        + params_a_B*log(Integer(2)*n_spin(rs, z))
        + params_a_C*log(Integer(2)*n_spin(rs, z))**Integer(2)
        )
    )

@helper
def gds08_worker(rs, z):
    return (
        + my_piecewise3(screen_dens(rs,  z), Integer(0), gds08_ws(rs, z_thr( z)))
        + my_piecewise3(screen_dens(rs, -z), Integer(0), gds08_ws(rs, z_thr(-z)))
    )

def f(rs, z, xt, xs0, xs1):
    return gga_kinetic_p(gds08_base, rs, z, xs0, xs1) + gds08_worker(rs, z)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_k_gds08_params"
