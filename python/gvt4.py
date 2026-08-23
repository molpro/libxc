"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

@helper
def gvt4_gamm(alpha, x, z):
    return Integer(1) + alpha*(x**Integer(2) + z)

@helper
def gtv4(alpha, dd, x, z):
    return (
        dd[Integer(1)]/gvt4_gamm(alpha, x, z) +
        (dd[Integer(2)]*x**Integer(2) + dd[Integer(3)]*z)/gvt4_gamm(alpha, x, z)**Integer(2) +
        (dd[Integer(4)]*x**Integer(4) + dd[Integer(5)]*x**Integer(2)*z + dd[Integer(6)]*z**Integer(2))/gvt4_gamm(alpha, x, z)**Integer(3)
    )
