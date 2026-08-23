"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

# The B97 function g (b97_u is the shared bounded gradient variable)

@helper
def b97_g(gamma, cc, x):
    return sum((cc[i]*b97_u(gamma, x**Integer(2))**(i-Integer(1))) for i in range(Integer(1), (Integer(5)) + Integer(1)))

# The parallel and perpendicular components of the energy

@helper
def b97_fpar(lda_func, mgamma, cc, rs, z, xs0, xs1):
    return (
        + lda_stoll_par(lda_func, rs,  z) * b97_g(mgamma, cc, xs0)
        + lda_stoll_par(lda_func, rs, -z) * b97_g(mgamma, cc, xs1)
    )

@helper
def b97_fperp(lda_func, mgamma, cc, rs, z, xs0, xs1):
    return lda_stoll_perp(lda_func, rs, z) * b97_g(mgamma, cc, sqrt(xs0**Integer(2) + xs1**Integer(2))/sqrt(Integer(2)))

@helper
def b97_f(lda_func, gamma_ss, cc_ss, gamma_ab, cc_ab, rs, z, xs0, xs1):
    return (
        + b97_fpar (lda_func, gamma_ss, cc_ss, rs, z, xs0, xs1)
        + b97_fperp(lda_func, gamma_ab, cc_ab, rs, z, xs0, xs1)
    )
