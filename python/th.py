"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""


from libxc_codegen import *  # noqa: F401, F403

params_a_n = param_default("n")
params_a_omega = param_default("omega")
params_a_a = param_default("a")
params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_d = param_default("d")

@helper
def XX(z, xs):
    return xs*opz_pow_n(z,Integer(4)/Integer(3))*Integer(2)**(-Integer(4)/Integer(3))

@helper
def YY(z, xt, xs0, xs1):
    return Integer(2)*(XX(z, xs0)**Integer(2) + XX(-z, xs1)**Integer(2)) - xt**Integer(2)

@helper
def f_th(rs, z, xt, xs0, xs1):
    return (
        sum((params_a_omega[i]
        * (n_spin(rs, z)**params_a_a[i] + n_spin(rs, -z)**params_a_a[i])
        * z**(Integer(2)*params_a_b[i])
        * Integer(1)/Integer(2)*(XX(z, xs0)**params_a_c[i] + XX(-z, xs1)**params_a_c[i])
        * YY(z, xt, xs0, xs1)**params_a_d[i]) for i in range(Integer(1), (params_a_n) + Integer(1)))/n_total(rs)
    )
