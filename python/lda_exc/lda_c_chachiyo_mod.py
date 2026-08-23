"""
 Copyright (C) 2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: lda_exc
# prefix:
#   lda_c_chachiyo_mod_params *params;
#
#   assert(p->params != NULL);
#   params = (lda_c_chachiyo_mod_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

# Functional is based on Chachiyo correlation
include('lda_c_chachiyo')
# .. but with a different scaling function.
# Algebraic identity:
# 1 - g^3 = (1 - g)*(1 + g + g^2),
# 1 - g   = -(opz_pow_n_m1(z, 2/3) + opz_pow_n_m1(-z, 2/3))/2,
# so g_zeta = 2*(1 - g^3)
# = -(opz_pow_n_m1(z, 2/3) + opz_pow_n_m1(-z, 2/3)) * (1 + g + g^2),
# which is cancellation-free at z = 0 where g -> 1 and the direct
# 1 - g^3 form computes 1 - close-to-1.

@helper
def g(z):
    return (opz_pow_n(z,Integer(2)/Integer(3)) + opz_pow_n(-z,Integer(2)/Integer(3)))/Integer(2)

@helper
def g_zeta(zeta):
    return -(opz_pow_n_m1(zeta, Integer(2)/Integer(3)) + opz_pow_n_m1(-zeta, Integer(2)/Integer(3)))*(Integer(1) + g(zeta) + g(zeta)**Integer(2))

@helper
def f_chachiyo(rs, zeta):
    return e0(rs) + (e1(rs) - e0(rs))*g_zeta(zeta)

def f(rs, zeta):
    return f_chachiyo(rs, zeta)

TYPE = "lda_exc"
PARAMS_STRUCT = "lda_c_chachiyo_mod_params"
