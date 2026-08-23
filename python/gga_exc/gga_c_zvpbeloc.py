"""
 Copyright (C) 2017 M.A.L. Marques
               2025 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

params_a_alpha = param_default("alpha")
params_a_omega = param_default("omega")

include('gga_c_zvpbeint')
include('gga_c_pbeloc')

params_a_alpha = Float('0.5')
params_a_omega = Integer(2)

# text below equation 8

@helper
def zvpbeloc_kv(rs):
    return Integer(2)*(Integer(3)/(Integer(4)*pi**Integer(4)))**(Integer(1)/Integer(18)) * n_total(rs)**(Integer(1)/Integer(9))

# redefine nu of zbpbeint, text below equation 8. nu = |nabla n| / (2 kv rho); x = |nabla n| / rho^(4/3)

@helper
def zvpbeint_nu(rs, z, xt):
    return xt * n_total(rs)**(Integer(1)/Integer(3)) / (Integer(2) * zvpbeloc_kv(rs))

# Note that f_pbe here is, in fact, pbeloc

def f(rs, z, xt, xs0, xs1):
    return zvpbeint_ff(rs, z, xt) * f_pbe(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
