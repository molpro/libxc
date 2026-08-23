"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

# constants from text in section 2

pbetrans_kappa_pbe = Float('0.814')

# This is probably a misprint in the manuscript as KAPPA_PBE is 0.8040

pbetrans_kappa_revpbe = Float('1.227')

pbetrans_mu = Float('0.219')

# parameters from section 4

pbetrans_alpha = Integer(2)*(Integer(3)*pi**Integer(2))**(Integer(1)/Integer(3))

pbetrans_beta = Integer(3)

# eq 3

@helper
def pbetrans_fermi(s):
    return Integer(1)/(Integer(1)+exp(-pbetrans_alpha*(s-pbetrans_beta)))

# eq 5

@helper
def pbetrans_kappa(s):
    return (Integer(1)-pbetrans_fermi(s))*pbetrans_kappa_revpbe + pbetrans_fermi(s)*pbetrans_kappa_pbe

# eq 4

@helper
def pbetrans_f0(s):
    return Integer(1) + pbetrans_kappa(s)*(Integer(1) - pbetrans_kappa(s)/(pbetrans_kappa(s) + pbetrans_mu*s**Integer(2)))

@helper
def pbetrans_f(x):
    return pbetrans_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(pbetrans_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
