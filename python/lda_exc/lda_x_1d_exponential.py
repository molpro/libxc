"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# replace: "int1\(" -> "xc_integrate(func1, NULL, 1e-20, "
# replace: "int2\(" -> "xc_integrate(func2, NULL, 1e-20, "
# prefix:
#   lda_x_1d_exponential_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_x_1d_exponential_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")

define('xc_dimensions_1d')

@helper
def x1d_inter(x):
    return xc_E1_scaled(x**Integer(2))

class int1(Function):
    def fdiff(self, argindex=1):
        g, = self.args
        if argindex == 1:
            return Integer(1) * x1d_inter(g)
        return 0

class int2(Function):
    def fdiff(self, argindex=1):
        g, = self.args
        if argindex == 1:
            return Integer(1) * x1d_inter(g)*g
        return 0

@helper
def x1d_R(rs):
    return pi*params_a_beta/(Integer(2)*rs)

@helper
def x1d_fs(rs, z):
    return (
        -((Integer(1) + z)*int1((Integer(1) + z)*x1d_R(rs)) - int2((Integer(1) + z)*x1d_R(rs))/x1d_R(rs))
        / (Float('4.0')*pi*params_a_beta)
    )

@helper
def x1d_f(rs, z):
    return (
        + my_piecewise3(screen_dens_zeta(rs,  z), Integer(0), x1d_fs(rs, z_thr( z)))
        + my_piecewise3(screen_dens_zeta(rs, -z), Integer(0), x1d_fs(rs, z_thr(-z)))
    )

def f(rs, z):
    return x1d_f(rs, z)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_x_1d_exponential_params"
REPLACE = [
    ('int1\\(', 'xc_integrate(func1, NULL, 1e-20, '),
    ('int2\\(', 'xc_integrate(func2, NULL, 1e-20, '),
]
