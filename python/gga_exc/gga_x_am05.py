"""
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_x_am05_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_x_am05_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_c = param_default("c")
params_a_alpha = param_default("alpha")

am05_d = Float('28.23705740248932030511071641312341561894')

# POW(CBRT(4/3) * 2*M_PI/3, 4)

@helper
def am05_csi(s):
    return (Integer(3)/Integer(2) * LambertW(s**(Integer(3)/Integer(2)) / (Integer(2)*sqrt(Integer(6)))))**(Integer(2)/Integer(3))

@helper
def am05_fb(s):
    return pi/Integer(3) * s/(am05_csi(s) * (am05_d + am05_csi(s)**Integer(2))**(Integer(1)/Integer(4)))

@helper
def am05_flaa(s):
    return (Integer(1) + params_a_c*s**Integer(2))/(Integer(1) + params_a_c*s**Integer(2)/am05_fb(s))

# KEEP IN SYNC: am05_XX and am05_one_minus_XX are paired.
# Algebraic identities (with A = alpha*s^2):
# XX           = 1 - A/(1+A) = 1/(1+A)
# 1 - XX       =     A/(1+A)
# so the direct 1 - A/(1+A) form cancels at large s (A -> infty,
# the fraction -> 1), and 1 - XX cancels at small s (XX -> 1).
# Both are written in their cancellation-free single-fraction
# form below.

@helper
def am05_XX(s):
    return Integer(1)/(Integer(1) + params_a_alpha*s**Integer(2))

@helper
def am05_one_minus_XX(s):
    return params_a_alpha*s**Integer(2)/(Integer(1) + params_a_alpha*s**Integer(2))

@helper
def am05_f(x):
    return am05_XX(gga_s(x)) + am05_one_minus_XX(gga_s(x))*am05_flaa(gga_s(x))

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(am05_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_am05_params"
