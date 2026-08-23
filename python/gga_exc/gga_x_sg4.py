"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

sg4_mu1 = Float('0.042')

sg4_mu2 = Float('0.26') - sg4_mu1

sg4_nu_MGE4 = -Float('0.195')

sg4_k2 = -sg4_mu2**Integer(2)/sg4_nu_MGE4

sg4_k1 = Float('0.804') - sg4_k2

# Algebraic identities (with A = mu1*s^2/k1):
# (1 - A)/(1 - A^5) = 1/(1 + A + A^2 + A^3 + A^4)     [cyclotomic]
# then
# k1 + k2 - k1/(1+A+...+A^4) - k2/(1 + mu2*s^2/k2)
# = k1*(A + A^2 + A^3 + A^4)/(1+A+A^2+A^3+A^4)
# + mu2*s^2/(1 + mu2*s^2/k2)
# = mu1*s^2*(1 + A + A^2 + A^3)/(1 + A + A^2 + A^3 + A^4)
# + mu2*s^2/(1 + mu2*s^2/k2).
# Both pieces are O(s^2) at small s, so the rewrite removes the
# 1 + k1 + k2 - close-to-(k1+k2) cancellation of the direct form.

@helper
def sg4_A(s):
    return sg4_mu1*s**Integer(2)/sg4_k1

@helper
def sg4_f0(s):
    return (
        Integer(1)
        + sg4_mu1*s**Integer(2)*(Integer(1) + sg4_A(s) + sg4_A(s)**Integer(2) + sg4_A(s)**Integer(3))
        / (Integer(1) + sg4_A(s) + sg4_A(s)**Integer(2) + sg4_A(s)**Integer(3) + sg4_A(s)**Integer(4))
        + sg4_mu2*s**Integer(2)/(Integer(1) + sg4_mu2*s**Integer(2)/sg4_k2)
    )

@helper
def sg4_f(x):
    return sg4_f0(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(sg4_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
