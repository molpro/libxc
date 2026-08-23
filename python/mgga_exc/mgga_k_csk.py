"""
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_k_csk_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_k_csk_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_csk_a = param_default("csk_a")

# Equation (21)

@helper
def csk_z(p, q):
    return Integer(20)/Integer(9)*q - Integer(40)/Integer(27)*p

# Equation (22)

#
# I(z) contains exp(-1/|z|^a), numerically challenging for small |z|; we
# truncate near z=0 (I -> 1) and for large -z (I -> 0, the step function).
# What enters the energy is the PRODUCT z*I(z).  In the exp branch I(z) ~
# 1/|z| is tiny, so forming z*(tiny) destroys all accuracy in the 2nd
# derivative at large |z| (the near-empty channel).  We instead evaluate the
# product directly in the algebraically-identical, cancellation-free form
# z*I(z) = -(-expm1(-u)*|z|^a)^(1/a),   u = 1/|z|^a,
# whose base -expm1(-u)/u -> 1 as |z| -> infinity, so no small-times-large
# cancellation occurs.

@helper
def csk_zI_negz(z):
    return -(-xc_expm1(-Integer(1)/m_abs(z)**params_a_csk_a) * m_abs(z)**params_a_csk_a)**(Integer(1)/params_a_csk_a)

csk_I_cutoff_small = (-log(XC_EPSILON))**(-Integer(1)/params_a_csk_a)

csk_I_cutoff_large = (-log(Integer(1) - XC_EPSILON))**(-Integer(1)/params_a_csk_a)

@helper
def csk_zI(z):
    return (
        my_piecewise5(
        z < -csk_I_cutoff_large, Integer(0),
        z > -csk_I_cutoff_small, z,
        csk_zI_negz(m_max(m_min(z, -csk_I_cutoff_small), -csk_I_cutoff_large))
        )
    )

@helper
def csk_f0(p, q, z):
    return Integer(1) + Integer(5)*p/Integer(3) + csk_zI(z)

# p = mgga_p(xs) = s^2 is fed directly (mgga_kinetic_p) so the sigma
# derivatives are cancellation-free

@helper
def csk_f(p, u):
    return csk_f0(p, mgga_q(u), csk_z(p, mgga_q(u)))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_kinetic_p(csk_f, rs, z, xs0, xs1, u0, u1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_k_csk_params"
