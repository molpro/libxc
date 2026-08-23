"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc

from libxc_codegen import *  # noqa: F401, F403

a = maple_list([Float('0.4581652932831429'), Float('2.217058676663745'),  Float('0.7405551735357053'), Float('0.01968227878617998') ])

ap = maple_list([Float('0.119086804055547'),  Float('0.6157402568883345'), Float('0.1574201515892867'), Float('0.003532336663397157')])

b = maple_list([Float('1.0000000000000000'), Float('4.504130959426697'),  Float('1.110667363742916'),  Float('0.02359291751427506') ])

bp = maple_list([Float('0.000000000000000'),  Float('0.2673612973836267'), Float('0.2052004607777787'), Float('0.004200005045691381')])

def f(rs, zeta):
    return (
        - sum(((a[i] + f_zeta(zeta)*ap[i])*rs**(i-Integer(1))) for i in range(Integer(1), (Integer(4)) + Integer(1))) /
        sum(((b[i] + f_zeta(zeta)*bp[i])*rs**i) for i in range(Integer(1), (Integer(4)) + Integer(1)))
    )

TYPE = "lda_exc"
