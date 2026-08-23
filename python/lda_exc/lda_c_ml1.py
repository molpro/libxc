"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_ml1_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_ml1_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_fc = param_default("fc")
params_a_q = param_default("q")

ml1_C = Float('6.187335')

ml1_b = maple_list([Float('2.763169'), Float('1.757515'), Float('1.741397'), Float('0.568985'), Float('1.572202'), Float('1.885389')])

@helper
def ml1_alpha(z):
    return params_a_fc*(opz_pow_n(z, params_a_q) + opz_pow_n(-z, params_a_q))

@helper
def ml1_beta(z):
    return one_minus_z_pow_n(z, Integer(2))**(Integer(1)/Integer(3))/((Integer(1) + z)**(Integer(1)/Integer(3)) + (Integer(1) - z)**(Integer(1)/Integer(3)))

# From the paper: "Note that the antiparailel-spin correlation length
# diverges when the spin-polarization parameter tends to 1", which means
# that Q diverges for a ferromagnetic density

@helper
def ml1_k(rs, z):
    return ml1_C*n_total(rs)**(Integer(1)/Integer(3)) * ml1_alpha(z)*ml1_beta(z)

# Eq. 32

@helper
def ml1_Q(rs, z):
    return (
        - ml1_b[Integer(1)]/(Integer(1) + ml1_b[Integer(2)]*ml1_k(rs, z))
        + ml1_b[Integer(3)]*xc_log1p(ml1_b[Integer(4)]/ml1_k(rs, z))/ml1_k(rs, z)
        + ml1_b[Integer(5)]/ml1_k(rs, z)
        - ml1_b[Integer(6)]/ml1_k(rs, z)**Integer(2)
    )

# screen for small spin densities to avoid divergences in the
# potentials.  Note that beta is zero for any polarized density and
# the whole expression for alpha*beta is symmetric in z.  Note also
# that in the expression for Q one divides by k that is zero for
# ferromagnetic densities.

# there is a factor of 1/2 wrong in Eq. 31 as explained in the Erratum

# With the formula below we can reproduce exactly the values of Table I.
# Note that in the Erratum the authors afirm that all the results are correct,
# and only the formulas had misspells.

@helper
def ml1_f(rs, z):
    return (
        n_total(rs) *
        my_piecewise3(Integer(1) - m_abs(z) <= p_a_zeta_threshold, Integer(0), one_minus_z_pow_n(z, Integer(2))/Integer(4) * ml1_Q(rs, z_thr(z)))
    )

def f(rs, z):
    return ml1_f(rs, z)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_ml1_params"
