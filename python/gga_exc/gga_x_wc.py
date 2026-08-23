"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

wc_mu = Float('0.2195149727645171')

wc_c = (Integer(146)/Integer(2025))*(Integer(4)/Integer(9)) - (Integer(73)/Integer(405))*(Integer(2)/Integer(3)) + (wc_mu - MU_GE)

wc_kappa = KAPPA_PBE

# wc_f0_aux_m_kappa := wc_f0_aux - wc_kappa; wc_f0_aux is then
# wc_kappa + wc_f0_aux_m_kappa. With this primitive, wc_f0 =
# 1 + wc_kappa*(1 - wc_kappa/wc_f0_aux) collapses to
# 1 + wc_kappa*wc_f0_aux_m_kappa/wc_f0_aux, which is cancellation-
# free at small s where the direct form computes 1 - close-to-1.

@helper
def wc_f0_aux_m_kappa(s):
    return MU_GE * s**Integer(2) + (wc_mu - MU_GE) * s**Integer(2) * exp(-s**Integer(2)) + xc_log1p(wc_c * s**Integer(4))

@helper
def wc_f0_aux(s):
    return wc_kappa + wc_f0_aux_m_kappa(s)

@helper
def wc_f0(s):
    return Integer(1) + wc_kappa*wc_f0_aux_m_kappa(s)/wc_f0_aux(s)

@helper
def wc_f(x):
    return wc_f0(gga_s(x))

def f(rs, z, xt, xs0, xs1):
    return gga_exchange(wc_f, rs, z, xs0, xs1)

TYPE = "gga_exc"
