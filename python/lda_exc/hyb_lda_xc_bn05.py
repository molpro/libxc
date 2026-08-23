"""
 Copyright (C) 2017 M.A.L. Marques
               2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

include('lda_x_yukawa')
define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

bn05_A = Float('3.4602')

bn05_C0 = Float('3.2')

bn05_C1 = -Float('0.9')

def f(rs, z):
    return f_lda_x_yukawa(rs, z) + f_pw(rs, z)*bn05_A/(bn05_C0 + bn05_C1*rs + rs**Integer(2))

TYPE = "lda_exc"
