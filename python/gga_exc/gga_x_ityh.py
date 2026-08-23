"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

define('gga_x_b88_params')
include('gga_x_b88')
include('lda_x_erf')

@helper
def ityh_enhancement(xs):
    return b88_f(xs)

# KEEP IN SYNC: ityh_attenuation and ityh_one_minus_attenuation are
# the SR/LR halves of the same kernel.  If a consumer overrides
# ityh_attenuation it must also override ityh_one_minus_attenuation
# with the matching one_minus_* primitive.

@helper
def ityh_attenuation(a):
    return attenuation_erf(a)

@helper
def ityh_one_minus_attenuation(a):
    return one_minus_attenuation_erf(a)

@helper
def ityh_k_GGA(rs, z, xs):
    return sqrt(Integer(9)*pi/(Integer(2)*X_FACTOR_C*ityh_enhancement(xs))) * n_spin(rs, z)**(Integer(1)/Integer(3))

@helper
def ityh_aa(rs, z, xs):
    return p_a_cam_omega/(Integer(2)*ityh_k_GGA(rs, z, xs))

@helper
def ityh_f_aa(rs, z, xs):
    return ityh_attenuation(ityh_aa(rs, z, xs))

@helper
def ityh_one_minus_f_aa(rs, z, xs):
    return ityh_one_minus_attenuation(ityh_aa(rs, z, xs))

@helper
def ityh_f(rs, z, xs):
    return ityh_f_aa(rs, z, xs) * ityh_enhancement(xs)

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange_nsp(ityh_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
