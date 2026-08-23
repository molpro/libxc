"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_fd_lb94_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_fd_lb94_params * )(p->params);
# replace: "fd_int0\(" -> "xc_integrate(func0, &(params->beta), 0.0, "
# replace: "fd_int1\(" -> "xc_integrate(func1, &(params->beta), 0.0, "

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")

fd_beta = params_a_beta

fd_csi = Integer(2)**(Integer(1)/Integer(3))

# log(x + sqrt(x^2 + 1)) is the closed form for asinh(x); use the
# xc_asinh wrapper so the codegen emits a direct asinh() call --
# Maple's `arcsinh` would re-expand to the log+sqrt closed form
# which reintroduces the log(close-to-1) cancellation at small x.

@helper
def fd_f_inter(n, t):
    return (
        -Integer(3)/Integer(4) * fd_beta*fd_csi*log(t)**n /
        (Integer(1) + Integer(3)*fd_beta*fd_csi*t*xc_asinh(fd_csi*t))
    )

class fd_int0(Function):
    def fdiff(self, argindex=1):
        g, = self.args
        if argindex == 1:
            return Integer(1) * fd_f_inter(Integer(0), g)
        return 0

class fd_int1(Function):
    def fdiff(self, argindex=1):
        g, = self.args
        if argindex == 1:
            return Integer(1) * fd_f_inter(Integer(1), g)
        return 0

@helper
def fd_f(x):
    return Integer(1) - x/X_FACTOR_C*(fd_int0(x/fd_csi)*log(x/fd_csi) - fd_int1(x/fd_csi))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(fd_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_fd_lb94_params"
REPLACE = [
    ('fd_int0\\(', 'xc_integrate(func0, &(params->beta), 0.0, '),
    ('fd_int1\\(', 'xc_integrate(func1, &(params->beta), 0.0, '),
]
