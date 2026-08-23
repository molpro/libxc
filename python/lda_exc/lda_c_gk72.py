"""
 Copyright (C) 2020 Miguel Marques
               2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

# eq 21

@helper
def f_ls(rs, zeta):
    return Float('0.0311')*log(rs) - Float('0.048') + Float('0.009')*rs*log(rs) - Float('0.01')*rs

# eq 22: note that the paper appears to have a wrong overall sign;
# this expression leads to a continuous interpolation and agreement with
# Fig. 1 of the paper. It also appears that Fig. 1 has been scaled by 10

@helper
def f_ms(rs, zeta):
    return -Float('0.06156') + Float('0.01898')*log(rs)

# eq 20

@helper
def f_hs(rs, zeta):
    return -Float('0.438')/rs + Float('1.325')/rs**(Integer(3)/Integer(2)) - Float('1.47')/rs**Integer(2) - Float('0.4')/rs**(Integer(5)/Integer(2))

def f(rs, zeta):
    return (
        my_piecewise5(
        rs < Float('0.7'), f_ls(rs, zeta),  rs < Integer(10),  f_ms(rs, zeta), f_hs(rs, zeta))
    )

TYPE = "lda_exc"
