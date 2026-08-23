"""
 Copyright (C) 2017 M.A.L. Marques
               2022 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   hyb_mgga_xc_gas22_params *params;
#
#   assert(p->params != NULL);
#   params = (hyb_mgga_xc_gas22_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c_x = param_default("c_x")
params_a_c_ss = param_default("c_ss")
params_a_c_os = param_default("c_os")

# the functional form is nearly identical to wb97mv
include('hyb_mgga_xc_wb97mv')

# these definitions must come after inserting the file

# Longest equation has 5 parameters

b97mv_par_n = Integer(5)

# More accurate value from the ipynb notebook

b97mv_gamma_x = Float('0.003840616724010807')

b97mv_par_x = maple_list([ maple_list([ params_a_c_x[Integer(1)], Integer(0), Integer(0)]), maple_list([ params_a_c_x[Integer(2)], Integer(0), Integer(1)]), maple_list([ params_a_c_x[Integer(3)], Integer(1), Integer(0)]), maple_list([ Integer(0), Integer(0), Integer(0)]), maple_list([ Integer(0), Integer(0), Integer(0)]) ])

# More accurate value from the ipynb notebook

b97mv_gamma_ss = Float('0.46914023462026644')

b97mv_par_ss = maple_list([ maple_list([ params_a_c_ss[Integer(1)], Integer(0), Integer(1)]), maple_list([ params_a_c_ss[Integer(2)], Integer(1), Integer(0)]), maple_list([ params_a_c_ss[Integer(3)], Integer(2), Integer(0)]), maple_list([ params_a_c_ss[Integer(4)], Integer(0), Integer(6)]), maple_list([ params_a_c_ss[Integer(5)], Integer(4), Integer(6)]) ])

# the peculiarity of GAS22 is that it uses a slightly different expansion for
# the anti-parallel part of the correlation in terms of xt and not of ux

@helper
def b97mv_ux_os(mgamma, x):
    return x

b97mv_par_os = maple_list([ maple_list([ params_a_c_os[Integer(1)], Integer(0), Integer(0)]), maple_list([ params_a_c_os[Integer(2)], Integer(2), Integer(0)]), maple_list([ params_a_c_os[Integer(3)], Integer(6), Integer(0)]), maple_list([ params_a_c_os[Integer(4)], Integer(6), Integer(2)/Integer(3)]), maple_list([ params_a_c_os[Integer(5)], Integer(2), Integer(2)/Integer(3)]) ])

TYPE = "mgga_exc"
PARAMS_STRUCT = "hyb_mgga_xc_gas22_params"
