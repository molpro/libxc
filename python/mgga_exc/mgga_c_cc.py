"""
 Copyright (C) 2022 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

# equation 2 in Lebeda 2022, tau_W / tau.  cc_z and cc_one_minus_z are
# opaque helpers taking the SQUARED reduced gradient xt2 = xt^2 (rational
# in sigma), so the sigma-derivatives never chain through sqrt(sigma).
# f_cc is affine in xt2 (t_total is tau-based), hence v2sigma2 is exactly
# zero -- the same class as lyp/zlp/cs (see maple/util.mpl t_vw).

@helper
def cc_z(z, xt2, ts0, ts1):
    return xt2 / (Integer(8)*t_total(z, ts0, ts1))

# The Pauli kinetic deficit 1 - tw/t; KEEP IN SYNC with cc_z.
# Computing 1 - cc_z directly cancels at the iso-orbital limit, so
# this form (a single fraction) is the cancellation-free primitive.

@helper
def cc_one_minus_z(z, xt2, ts0, ts1):
    return (Integer(8)*t_total(z, ts0, ts1) - xt2)/(Integer(8)*t_total(z, ts0, ts1))

# equation 9 in Schmidt 2014, equation 6 in Lebeda 2022.
# Algebraic identity:
# 1 - cc_z*z^2 = (1 - z^2) + z^2*(1 - cc_z),
# so the fully-polarized iso-orbital corner -- where cc_z -> 1 and
# z^2 -> 1 and the direct form computes 1 - close-to-1 -- splits into
# two cancellation-free pieces.

@helper
def f_cc(rs, z, xt, ts0, ts1):
    return (one_minus_z_pow_n(z, Integer(2)) + z**Integer(2)*cc_one_minus_z(z, xt**Integer(2), ts0, ts1))*f_pw(rs, z)

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return f_cc(rs, z, xt, ts0, ts1)

TYPE = "mgga_exc"
