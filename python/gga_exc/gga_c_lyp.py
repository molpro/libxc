"""
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: gga_exc
# prefix:
#   gga_c_lyp_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_lyp_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_b = param_default("b")
params_a_c = param_default("c")
params_a_d = param_default("d")
params_a_a = param_default("a")

lyp_Cf = Integer(3)/Integer(10) * (Integer(3)*pi**Integer(2))**(Integer(2)/Integer(3))

@helper
def lyp_omega(rr):
    return params_a_b*exp(-params_a_c*rr)/(Integer(1) + params_a_d*rr)

@helper
def lyp_delta(rr):
    return (params_a_c + params_a_d/(Integer(1) + params_a_d*rr))*rr

lyp_aux6 = Integer(1)/Integer(2)**(Integer(8)/Integer(3))

lyp_aux4 = lyp_aux6/Integer(4)

lyp_aux5 = lyp_aux4/(Integer(9)*Integer(2))

@helper
def lyp_t1(rr, z):
    return -one_minus_z_pow_n(z, Integer(2))/(Integer(1) + params_a_d*rr)

# The gradient terms enter only through the SQUARE of the reduced gradient, so
# the helpers take xt^2/xs0^2/xs1^2 rather than xt/xs0/xs1. The square is
# rational in sigma (sqrt(sigma) folds), so differentiating the opaque helper
# with respect to sigma stays cancellation-free; passing the bare reduced
# gradient routes the chain rule through d(sqrt(sigma)), whose 1/sigma terms
# cancel only in exact arithmetic and lose all precision at a small gradient --
# catastrophically here, where LYP is linear in sigma and v2sigma2 is exactly
# zero.

@helper
def lyp_t2(rr, z, xt2):
    return -xt2*(one_minus_z_pow_n(z, Integer(2))*(Integer(47) - Integer(7)*lyp_delta(rr))/(Integer(4)*Integer(18)) - Integer(2)/Integer(3))

@helper
def lyp_t3(z):
    return -lyp_Cf/Integer(2)*one_minus_z_pow_n(z, Integer(2))*(opz_pow_n(z,Integer(8)/Integer(3)) + opz_pow_n(-z,Integer(8)/Integer(3)))

@helper
def lyp_t4(rr, z, xs02, xs12):
    return lyp_aux4*one_minus_z_pow_n(z, Integer(2))*(Integer(5)/Integer(2) - lyp_delta(rr)/Integer(18))*(xs02*opz_pow_n(z,Integer(8)/Integer(3)) + xs12*opz_pow_n(-z,Integer(8)/Integer(3)))

@helper
def lyp_t5(rr, z, xs02, xs12):
    return lyp_aux5*one_minus_z_pow_n(z, Integer(2))*(lyp_delta(rr) - Integer(11))*(xs02*opz_pow_n(z,Integer(11)/Integer(3)) + xs12*opz_pow_n(-z,Integer(11)/Integer(3)))

@helper
def lyp_t6(z, xs02, xs12):
    return (
        -lyp_aux6*(Integer(2)/Integer(3)*(xs02*opz_pow_n(z,Integer(8)/Integer(3)) + xs12*opz_pow_n(-z,Integer(8)/Integer(3)))
        -opz_pow_n(z,Integer(2))*xs12*opz_pow_n(-z,Integer(8)/Integer(3))/Integer(4) - opz_pow_n(-z,Integer(2))*xs02*opz_pow_n(z,Integer(8)/Integer(3))/Integer(4))
    )

@helper
def f_lyp_rr(rr, z, xt, xs0, xs1):
    return (
        params_a_a*(lyp_t1(rr, z) + lyp_omega(rr)*(
        + lyp_t2(rr, z, xt**Integer(2)) + lyp_t3(z) + lyp_t4(rr, z, xs0**Integer(2), xs1**Integer(2))
        + lyp_t5(rr, z, xs0**Integer(2), xs1**Integer(2)) + lyp_t6(z, xs0**Integer(2), xs1**Integer(2))
        ))
    )

# rr = rs/RS_FACTOR is equal to n_total(rs)^(-1/3)

@helper
def f_lyp(rs, z, xt, xs0, xs1):
    return f_lyp_rr(rs/RS_FACTOR, z, xt, xs0, xs1)

def f(rs, z, xt, xs0, xs1):
    return f_lyp(rs, z, xt, xs0, xs1)

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_lyp_params"
