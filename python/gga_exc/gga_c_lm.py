"""
 Copyright (C) 2017 M.A.L. Marques
               2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_lm_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_lm_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_lm_f = param_default("lm_f")

define('lda_c_vbh_params')
include('lda_c_hl')

# Constant after equation (2.25) in Hu-Langreth. It is equal to the
# numerical constant in equation (12) of the Langreth-Mehl paper,
# 4.28e-3, once one accounts for the factor 2 from the conversion
# from Rydberg to Hartree

lm_J = pi/(Integer(16)*(Integer(3)*pi**Integer(2))**(Integer(4)/Integer(3)))

# Equation (2.23) in Hu-Langreth

@helper
def lm_d(z):
    return sqrt(opz_pow_n(z, Integer(5)/Integer(3)) + opz_pow_n(-z, Integer(5)/Integer(3)))/sqrt(Integer(2))

# F parameter, see after eqn (2.25) in Hu-Langreth; this yields
# 0.26181 which is rounds to 0.262 given by Langreth and Mehl. Hu and
# Langreth say the external parameter f = 0.15 for comparison with LM,
# but that f = 0.17 is preferable

lm_F = Integer(2)*sqrt(Integer(3))*params_a_lm_f / (Integer(2)*(Integer(3)/pi)**(Integer(1)/Integer(6)))

# First term in eqn (2.25) in Hu-Langreth

@helper
def lm_t1(z, xs0, xs1):
    return -Integer(7)/(Integer(9)*Integer(2)**(Integer(5)/Integer(3))) * (xs0**Integer(2)*opz_pow_n(z, Integer(4)/Integer(3)) + xs1**Integer(2)*opz_pow_n(-z, Integer(4)/Integer(3)))

# Second term in eqn (2.25) in Hu-Langreth

@helper
def lm_t2(rs, z, xt):
    return Integer(2)/lm_d(z) * exp(-lm_F*xt*n_total(rs)**(Integer(1)/Integer(6))) * xt**Integer(2)

def f(rs, z, xt, xs0, xs1):
    return (
        + hl_f(rs, z)
        + lm_J*(lm_t1(z, xs0, xs1) + lm_t2(rs, z, xt))*n_total(rs)**(Integer(1)/Integer(3))
    )

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_lm_params"
