"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

define('xc_dimensions_2d')

ax = -Integer(4)/Integer(3)*sqrt(Integer(2))/pi

def f(rs, z):
    return ax*f_zeta_2d(z)/rs

TYPE = "lda_exc"
