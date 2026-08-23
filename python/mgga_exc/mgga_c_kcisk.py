"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

include('mgga_c_kcis')

kcisk_p = Float('0.193')

kcisk_gcnst = Integer(20)/(Integer(3)*pi*(Integer(6)*pi**Integer(2))**(Integer(1)/Integer(3)))

# Eqs. (27)

# There was a "bug" in the reference implementation of Stefan Kurth. The
# f_pw was calculated for an unpolarized density instead of a polarized one.
# Here, we follow the original code.

@helper
def kcisk_gamma0(rs):
    return m_max(Integer(0), kcis_beta + Integer(2)**(Integer(1)/Integer(3))*kcisk_gcnst*f_pw(Integer(2)**(Integer(1)/Integer(3))*rs, Integer(0))/n_total(rs)**(Integer(1)/Integer(3)))

@helper
def kcisk_gamma1(rs):
    return m_max(Integer(0), kcis_beta + kcisk_gcnst*f_pw(rs, Integer(0))/n_total(rs)**(Integer(1)/Integer(3)))

# Eq. (19) and (22)

# There seems to be a misspel in Eq. (22) regarding the "1 +". This follows the
# reference implementation of Stefan Kurth

@helper
def kcis_gga0(rs, xt):
    return (
        f_pw(rs, Integer(0)) /
        (Integer(1) + kcisk_p*xc_log1p(kcisk_gamma0(rs)*kcis_t(rs, xt)**Integer(2)/(kcisk_p*m_abs(f_pw(rs, Integer(0)))) ))
    )

@helper
def kcis_gga1(rs, xt):
    return (
        f_pw(rs, Integer(1)) /
        (Integer(1) + kcisk_p*xc_log1p(Integer(2)**(-Integer(1)/Integer(3))*kcisk_gamma1(rs)*kcis_t(rs, xt)**Integer(2)/(kcisk_p*m_abs(f_pw(rs, Integer(1)))) ))
    )

TYPE = "mgga_exc"
