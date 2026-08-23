"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_2d_prm_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_2d_prm_params * )(p->params);
#
#   assert(params->N > 1);

from libxc_codegen import *  # noqa: F401, F403

params_a_c = param_default("c")

define('xc_dimensions_2d')

prm_q = Float('3.9274')

# 2.258

# Equation (4)

@helper
def beta(rs):
    return prm_q/(sqrt(pi)*rs)

# phi_m1(rs) = phi(rs) - 1, written cancellation-free so it stays
# precise as phi -> 1 (large beta). Then phi is derived from phi_m1
# so the two can never drift out of sync if beta is overridden in a
# derived functional. The extra "+1" can pick up a 1 - close-to-1
# cancellation at small beta, where phi -> 0, but the resulting
# precision (~16 - log10(beta) digits) is plenty for any sensible
# density regime.

@helper
def phi_m1(rs):
    return -sqrt(pi)/(Integer(2)*beta(rs) + sqrt(pi))

@helper
def phi(rs):
    return phi_m1(rs) + Integer(1)

# original version has (phi-1)^2

@helper
def f0(rs):
    return (
        + sqrt(pi)*beta(rs)*phi_m1(rs)/(Integer(2)*sqrt(Integer(2) + params_a_c))
        + phi(rs)*phi_m1(rs)/(Integer(2) + params_a_c)
        + sqrt(pi)*phi(rs)*phi(rs)/(Integer(4)*beta(rs)*(Integer(2) + params_a_c)**Float('1.5'))
        + sqrt(pi)*beta(rs)*phi_m1(rs)/sqrt(Integer(1) + params_a_c)
        + phi(rs)/(Integer(1) + params_a_c)
    )

def f(rs, z):
    return f0(rs)*pi/(Integer(2)*prm_q*prm_q)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_2d_prm_params"
