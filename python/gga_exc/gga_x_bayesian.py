"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc

from libxc_codegen import *  # noqa: F401, F403

bayesian_theta0 = Float('1.0008')

bayesian_theta1 = Float('0.1926')

bayesian_theta2 = Float('1.8962')

@helper
def bayesian_f0(s):
    return s**Integer(2)/(Integer(1) + s)**Integer(2)

@helper
def bayesian_f(x):
    return bayesian_theta0 + bayesian_f0(gga_s(x))* (bayesian_theta1 + bayesian_f0(gga_s(x)) * bayesian_theta2)

def f(rs, zeta, xt, xs0, xs1):
    return gga_exchange(bayesian_f, rs, zeta, xs0, xs1)

TYPE = "gga_exc"
