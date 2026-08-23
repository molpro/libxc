"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_pbe_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_pbe_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")
params_a_gamma = param_default("gamma")
params_a_BB = param_default("BB")
params_a_tscale = param_default("tscale")

define('lda_c_pw_params')
define('lda_c_pw_modified_params')
include('lda_c_pw')

if defined('gga_c_pbe_params'):
  params_a_beta = Float('0.06672455060314922')
  params_a_gamma = (Integer(1) - log(Integer(2)))/pi**Integer(2)
  params_a_BB = Integer(1)
  params_a_tscale = Integer(1)

mgamma = params_a_gamma

@helper
def mbeta(rs, t):
    return params_a_beta

BB = params_a_BB

@helper
def tp(rs, z, xt):
    return params_a_tscale*tt(rs, z, xt)

# Equation (8)

@helper
def A(rs, z, t):
    return mbeta(rs, t)/(mgamma*xc_expm1(-f_pw(rs, z)/(mgamma*mphi(z)**Integer(3))))

# Helpers for equation (7)
#
# This is the factor in the numerator of the second term, once you
# pull in the t^2 factor in front of the fraction

@helper
def f1(rs, z, t):
    return t**Integer(2) + BB*A(rs, z, t)*t**Integer(4)

# and this is the whole second term

@helper
def f2(rs, z, t):
    return mbeta(rs, t)*f1(rs, z, t)/(mgamma*(Integer(1) + A(rs, z, t)*f1(rs, z, t)))

# Equation (7)

@helper
def fH(rs, z, t):
    return mgamma*mphi(z)**Integer(3)*xc_log1p(f2(rs, z, t))

# The gradient correction f_pbe - f_pw, as a function of the full
# GGA argument list.  Exposed as a named helper so consumers that
# need the gradient part alone (e.g. mgga_c_m08, which interpolates
# the pieces of PBE correlation with tau-dependent weights) can take
# it directly instead of forming f_pbe - f_pw, which catastrophically
# cancels when the gradient correction is small.  f_pbe is derived
# from it so the two stay single-source.

@helper
def f_pbe_grad(rs, z, xt, xs0, xs1):
    return fH(rs, z, tp(rs, z, xt))

@helper
def f_pbe(rs, z, xt, xs0, xs1):
    return f_pw(rs, z) + f_pbe_grad(rs, z, xt, xs0, xs1)

def f(rs, z, xt, xs0, xs1):
    return f_pbe(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_pbe_params"
