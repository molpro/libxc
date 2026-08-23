"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_rlda_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_rlda_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_prefactor = param_default("prefactor")

# the derivation with prefactor=4/5 can be found in
# S. K. Ghosh and R. G. Parr, Phys. Rev. A 34, 785 (1986) and
# F. R. Manby and P. J. Knowles, J. Chem. Phys. 112, 7002 (2000)

rlda_a1 = (Integer(5)/Integer(4)) * Integer(3)*pi * params_a_prefactor/X_FACTOR_C

# the functional is inherently unstable but that's how it is

@helper
def rlda_f(x, u, t):
    return rlda_a1/(Integer(2)*t - u/Integer(4))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(rlda_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_rlda_params"
