"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_xc_b97_mv_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_xc_b97_mv_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c_x = param_default("c_x")
params_a_c_ss = param_default("c_ss")
params_a_c_os = param_default("c_os")

b97mv_par_n = Integer(5)

b97mv_gamma_x = Float('0.004')

b97mv_par_x = maple_list([ maple_list([params_a_c_x[Integer(1)], Integer(0), Integer(0)]), maple_list([params_a_c_x[Integer(2)], Integer(0), Integer(1)]), maple_list([params_a_c_x[Integer(3)], Integer(0), Integer(2)]), maple_list([params_a_c_x[Integer(4)], Integer(1), Integer(0)]), maple_list([params_a_c_x[Integer(5)], Integer(1), Integer(1)]) ])

b97mv_gamma_ss = Float('0.2')

b97mv_par_ss = maple_list([ maple_list([params_a_c_ss[Integer(1)], Integer(0), Integer(0)]), maple_list([params_a_c_ss[Integer(2)], Integer(0), Integer(2)]), maple_list([params_a_c_ss[Integer(3)], Integer(1), Integer(0)]), maple_list([params_a_c_ss[Integer(4)], Integer(3), Integer(2)]), maple_list([params_a_c_ss[Integer(5)], Integer(4), Integer(2)]) ])

b97mv_gamma_os = Float('0.006')

b97mv_par_os = maple_list([ maple_list([params_a_c_os[Integer(1)], Integer(0), Integer(0)]), maple_list([params_a_c_os[Integer(2)], Integer(0), Integer(1)]), maple_list([params_a_c_os[Integer(3)], Integer(0), Integer(3)]), maple_list([params_a_c_os[Integer(4)], Integer(1), Integer(0)]), maple_list([params_a_c_os[Integer(5)], Integer(3), Integer(2)]) ])

define('lda_x_params')

include('lda_x')

include('b97mv')

# Exchange: the B97-type enhancement of the per-spin LDA exchange, routed
# through the shared spin-scaled mgga_exchange wrapper (was hand-rolled as
# b97mv_f_aux). The enhancement uses the reduced gradient and tau, not the
# laplacian, so the u argument is unused.

@helper
def b97mv_fx(x, u, t):
    return b97mv_g(b97mv_gamma_x, b97mv_wx_ss, b97mv_ux_ss, b97mv_par_x, b97mv_par_n, x, t, Integer(0))

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return (
        + mgga_exchange(b97mv_fx, rs, z, xs0, xs1, us0, us1, ts0, ts1)
        + b97mv_f(rs, z, xs0, xs1, ts0, ts1)
    )

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_xc_b97_mv_params"
