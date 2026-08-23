"""
 Copyright (C) 2017 M.A.L. Marques
               2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

define('lda_x_params')
include('lda_x')
include('attenuation')

a_cnst = (Integer(4)/(Integer(9)*pi))**(Integer(1)/Integer(3))*p_a_cam_omega/Integer(2)

lda_x_ax = -RS_FACTOR*X_FACTOR_C/Integer(2)**(Integer(4)/Integer(3))

@helper
def lda_x_yukawa_spin(rs, z):
    return lda_x_ax*opz_pow_n(z,Integer(4)/Integer(3))/rs * attenuation_yukawa(a_cnst*rs/opz_pow_n(z,Integer(1)/Integer(3)))

@helper
def f_lda_x_yukawa(rs, z):
    return lda_x_yukawa_spin(rs, z) + lda_x_yukawa_spin(rs, -z)

def f(rs, z):
    return f_lda_x_yukawa(rs, z)

TYPE = "lda_exc"
