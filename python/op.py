"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

op_a1 = Float('1.5214')

op_a2 = Float('0.5764')

op_b1 = Float('1.1284')

op_b2 = Float('0.3183')

# This wrapper is to avoid overflows in the OP functionals. The
# energy is not affected, since the value is only changed for
# densities that are screened away.

@helper
def op_b88_zab(f_x, rs, z, xs0, xs1):
    return (
        my_piecewise3(
        m_abs(b88_zab(Integer(1), op_enhancement, rs, z, xs0, xs1)) < XC_EPSILON,
        XC_EPSILON,
        b88_zab(Integer(1), op_enhancement, rs, z, xs0, xs1)
        )
    )

@helper
def op_beta(rs, z, xs0, xs1):
    return op_qab/op_b88_zab(op_enhancement, rs, z, xs0, xs1)

@helper
def op_f_s(rs, z, xt, xs0, xs1):
    return (
        - one_minus_z_pow_n(z, Integer(2))*n_total(rs)/Float('4.0')
        * (op_a1*op_beta(rs, z, xs0, xs1) + op_a2)
        / (op_beta(rs, z, xs0, xs1)**Integer(4) + op_b1*op_beta(rs, z, xs0, xs1)**Integer(3) + op_b2*op_beta(rs, z, xs0, xs1)**Integer(2))
    )

@helper
def op_f(rs, z, xt, xs0, xs1):
    return my_piecewise3(Or(Integer(1) - m_abs(z) <= p_a_zeta_threshold, (And(screen_dens(rs,z), screen_dens(rs,-z)))), Integer(0), op_f_s(rs, z_thr(z), xt, xs0, xs1))

def f(rs, z, xt, xs0, xs1):
    return op_f(rs, z, xt, xs0, xs1)
