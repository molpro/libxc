"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_1d_css_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_1d_css_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_para = param_default("para")
params_a_ferro = param_default("ferro")

define('xc_dimensions_1d')

# factor of 2 is the conversion from Ry to Hartree

@helper
def f_aux(a, rs):
    return (
        -(rs + a[Integer(5)]*rs**Integer(2))*xc_log1p(a[Integer(8)]*rs + a[Integer(9)]*rs**a[Integer(10)])
        / (Integer(2)*(a[Integer(1)] + a[Integer(2)]*rs + a[Integer(3)]*rs**a[Integer(6)] + a[Integer(4)]*rs**a[Integer(7)]))
    )

def f(rs, z):
    return f_aux(params_a_para, rs) + (f_aux(params_a_ferro, rs) - f_aux(params_a_para, rs))*z**Integer(2)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_1d_css_params"
