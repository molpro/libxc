"""
 Copyright (C) 2018 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

# x has a different definition in the Chachiyo paper

@helper
def chachiyo_x(x):
    return Integer(2)/Integer(9) * (pi/Integer(3))**(Integer(1)/Integer(3)) * (Integer(2)**(-Integer(1)/Integer(3)) * x)

# equation 1.  log(x + 1) routed through xc_log1p so the small-x
# limit -- where the log is itself O(x) and used in both numerator
# and denominator -- doesn't lose precision in the log evaluation.

@helper
def chachiyo_f0(x):
    return (Integer(3)*x**Integer(2) + pi**Integer(2)*xc_log1p(x)) / ((Integer(3)*x + pi**Integer(2))*xc_log1p(x))

@helper
def chachiyo_f(x):
    return chachiyo_f0(chachiyo_x(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(chachiyo_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
