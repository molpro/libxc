"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

htbs_s1 = Float('0.6')

htbs_s2 = Float('2.6')

# The equations to solve in order to obtain the coeficients cc are
# G(s1) = 0
# G(s2) = 1
# G'(s1) = 0
# G'(s2) = 0
# G''(s1) = 0
# G''(s2) = 0

htbs_cc0 = htbs_s1**Integer(3)*(htbs_s1**Integer(2) - Integer(5)*htbs_s1*htbs_s2 + Integer(10)*htbs_s2**Integer(2))/(htbs_s1 - htbs_s2)**Integer(5)

htbs_cc1 = -Integer(30)*htbs_s1**Integer(2)*htbs_s2**Integer(2)/(htbs_s1 - htbs_s2)**Integer(5)

htbs_cc2 = Integer(30)*htbs_s1*htbs_s2*(htbs_s1 + htbs_s2)/(htbs_s1 - htbs_s2)**Integer(5)

htbs_cc3 = -Integer(10)*(htbs_s1**Integer(2) + Integer(4)*htbs_s1*htbs_s2 + htbs_s2**Integer(2))/(htbs_s1 - htbs_s2)**Integer(5)

htbs_cc4 = Integer(15)*(htbs_s1 + htbs_s2)/(htbs_s1 - htbs_s2)**Integer(5)

htbs_cc5 = -Integer(6)/(htbs_s1 - htbs_s2)**Integer(5)

define('gga_x_rpbe_params')

include('gga_x_rpbe')

include('gga_x_wc')

@helper
def htbs_g(s):
    return htbs_cc0 + htbs_cc1*s + htbs_cc2*s**Integer(2) + htbs_cc3*s**Integer(3) + htbs_cc4*s**Integer(4) + htbs_cc5*s**Integer(5)

@helper
def htbs_f0(s):
    return (
        my_piecewise5(
        s <= htbs_s1, wc_f0(s), s >= htbs_s2, rpbe_f0(s), htbs_g(s)*rpbe_f0(s) + (Integer(1) - htbs_g(s))*wc_f0(s)
        )
    )

@helper
def htbs_f(x):
    return htbs_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(htbs_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
