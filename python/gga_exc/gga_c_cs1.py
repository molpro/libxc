"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

cs1_gamma = Float('0.006')

# as in B88

cs1_d = Float('0.349')

# as in CS

cs1_C1 = -Float('0.018897')

cs1_C2 = Float('0.155240')

cs1_C3 = -Float('0.159068')

cs1_C4 = Float('0.007953')

# Equation (24) corrected in Equation (8) in Proynov2006_436

@helper
def cs1_ess(rs, z, xs):
    return (
        + opz_pow_n(z,Integer(1))/Integer(2) * n_spin(rs, z)**(Integer(1)/Integer(3))/(n_spin(rs, z)**(Integer(1)/Integer(3)) + cs1_d)
        * (cs1_C1 + cs1_C2*cs1_gamma**Integer(2)*xs**Integer(4)/(Integer(1) + cs1_gamma*xs**Integer(2))**Integer(2))
    )

# Equation (25) corrected in Equation (6) in Proynov2006_436

@helper
def cs1_eab(rs, z, xt):
    return (
        + one_minus_z_pow_n(z, Integer(2))/Integer(4) * Integer(1)/(Integer(1) + cs1_d*n_total(rs)**(-Integer(1)/Integer(3)))
        * (cs1_C3 + cs1_C4*cs1_gamma**Integer(2)*xt**Integer(4)/(Integer(1) + cs1_gamma*xt**Integer(2))**Integer(2))
    )

@helper
def f_cs1(rs, z, xt, xs0, xs1):
    return (
        + cs1_eab(rs,  z, xt)
        + cs1_ess(rs,  z, xs0)
        + cs1_ess(rs, -z, xs1)
    )

def f(rs, z, xt, xs0, xs1):
    return f_cs1(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
