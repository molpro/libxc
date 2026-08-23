"""
 Copyright (C) 2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

include('mgga_x_tm')

reg_c = Integer(3)

reg_d = Float('1.475')

# text after equation 11

@helper
def regtm_f(a, p):
    return (Integer(1) - a)**Integer(3)/(Integer(1) + (reg_d*a)**Integer(2))**(Integer(3)/Integer(2)) * exp(-reg_c*p)

# equation 11

@helper
def regtm_zp(a, p):
    return Integer(1) / (Integer(1) + Integer(3)/Integer(5)*(a/(p+regtm_f(a,p))))

# equation 13.
# KEEP IN SYNC: regtm_w and regtm_one_minus_w share the same algebraic
# identity as tm_w/tm_one_minus_w in mgga_x_tm.mpl.

@helper
def regtm_w(zp):
    return (zp**Integer(2) + Integer(3)*zp**Integer(3)) / (Integer(1) + zp**Integer(3))**Integer(2)

@helper
def regtm_one_minus_w(zp):
    return (Integer(1) - zp)*(Integer(1) + zp - zp**Integer(3) - zp**Integer(4) - zp**Integer(5)) / (Integer(1) + zp**Integer(3))**Integer(2)

# Collect all the pieces together; override both halves of the tm_w
# pair so the SC weighting in tm_f stays cancellation-free.

@helper
def tm_w(x, t):
    return regtm_w          (regtm_zp(mgga_alpha(x, t), tm_p(x)))

@helper
def tm_one_minus_w(x, t):
    return regtm_one_minus_w(regtm_zp(mgga_alpha(x, t), tm_p(x)))

TYPE = "mgga_exc"
