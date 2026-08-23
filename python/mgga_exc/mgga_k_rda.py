"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_k_rda_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_k_rda_params * ) (p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_A0 = param_default("A0")
params_a_A1 = param_default("A1")
params_a_a = param_default("a")
params_a_beta1 = param_default("beta1")
params_a_A2 = param_default("A2")
params_a_b = param_default("b")
params_a_beta2 = param_default("beta2")
params_a_A3 = param_default("A3")
params_a_c = param_default("c")
params_a_beta3 = param_default("beta3")

# Equation (61)

@helper
def rda_k4(s, p, b):
    return sqrt(s**Integer(4) + b*p**Integer(2))

# Equation (63)

@helper
def rda_k2(s, p, b):
    return s**Integer(2) + b*p

# Equation (71); first term is von Weiszäcker according to equation (13)

@helper
def rda_f0(s, p):
    return (
        Integer(5)/Integer(3)*s**Integer(2) + params_a_A0
        + params_a_A1 * (rda_k4(s,p,params_a_a) / (Integer(1) + params_a_beta1*rda_k4(s,p,params_a_a)))**Integer(2)
        + params_a_A2 * (rda_k4(s,p,params_a_b) / (Integer(1) + params_a_beta2*rda_k4(s,p,params_a_b)))**Integer(4)
        + params_a_A3 * (rda_k2(s,p,params_a_c) / (Integer(1) + params_a_beta3*rda_k2(s,p,params_a_c)))
    )

# Complete functional

@helper
def rda_f(xs, us):
    return rda_f0(gga_s(xs), mgga_q(us))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_kinetic(rda_f, rs, z, xs0, xs1, u0, u1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_k_rda_params"
