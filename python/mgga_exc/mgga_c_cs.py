"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

cs_a = -Float('0.04918')

cs_b = Float('0.132')

cs_c = Float('0.2533')/RS_FACTOR

cs_d = Float('0.349')/RS_FACTOR

@helper
def cs_thf(z, u, t):
    return opz_pow_n(z,Integer(8)/Integer(3))*Integer(2)**(-Integer(8)/Integer(3))*(t - u/Integer(8))

# This is Equation (15) of Lee1988_785

# Note that gamma = 1 - z^2

# f_cs is an opaque helper taking the squared reduced gradient xt2 = xt^2 (t_vw
# takes the square; see maple/util.mpl) so its vW term stays cancellation-free.

@helper
def f_cs(rs, z, xt2, xs0, xs1, u0, u1, t0, t1):
    return (
        cs_a*one_minus_z_pow_n(z, Integer(2))/(Integer(1) + cs_d*rs) * (Integer(1) + Integer(2)*cs_b*exp(-cs_c*rs)*(
        cs_thf(z, u0, t0) + cs_thf(-z, u1, t1) - t_vw(z, xt2, u0, u1)
        ))
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return f_cs(rs, z, xt**Integer(2), xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
