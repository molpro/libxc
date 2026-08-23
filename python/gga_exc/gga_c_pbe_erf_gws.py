"""
 2018 Authored by Andrea Kreppel
 2022 Edited by Henryk Laqua

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.

 Short-range PBE correlation functional Goll/Werner/Stoll
 Goll, Werner, Stoll Phys. Chem. Chem. Phys. 7, (2005) 3917.
"""

# type: gga_exc
# prefix:
#   gga_c_pbe_erf_gws_params *params;
#
#   assert(p->params != NULL);
#   params = (gga_c_pbe_erf_gws_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_beta = param_default("beta")
params_a_gamma = param_default("gamma")
params_a_a_c = param_default("a_c")

define('lda_c_pw_params')
include('lda_c_pw_erf')
include('lda_c_pw')

# default parameters
if defined('gga_c_pbe_erf_gws_params'):
  params_a_beta = Float('0.06672455060314922')
  params_a_gamma = Float('0.031090690869654895034')
  params_a_a_c = Float('2.78')

# params

pbe_c_erf_gws_gamma = params_a_gamma

pbe_c_erf_gws_beta_orig = params_a_beta

pbe_c_erf_gws_a_c = params_a_a_c

@helper
def pbe_c_erf_gws_kS(rs):
    return (Integer(3)/(Integer(4)*pi*n_total(rs)))**(Integer(1)/Integer(3))

# eq. (6)

@helper
def pbe_c_erf_gws_beta(rs, z):
    return pbe_c_erf_gws_beta_orig * (lda_c_pw_erf_f(rs,z)/f_pw(rs,z))**pbe_c_erf_gws_a_c

# third eq. of eq. (6): A = beta/(gamma*E), E = expm1(...).  A diverges where
# the attenuated LDA correlation lda_c_pw_erf_f crosses zero (E -> 0), which the
# plain (always-negative) f_pw never does -- so H below keeps E in the
# numerator instead of forming A, staying finite and pole-free there.

@helper
def pbe_c_erf_gws_E(rs, z):
    return xc_expm1(-lda_c_pw_erf_f(rs,z)/((mphi(z)**Integer(3))*pbe_c_erf_gws_gamma))

@helper
def pbe_c_erf_gws_A(rs, z):
    return pbe_c_erf_gws_beta(rs, z)/(pbe_c_erf_gws_gamma*pbe_c_erf_gws_E(rs, z))

# second eq. of eq. (6).  The H argument (beta t^2/gamma)(1+A t^2)/(1+A t^2+A^2 t^4),
# multiplied top and bottom by (gamma E)^2, is the algebraically identical
# beta t^2 E (gamma E + beta t^2)/(gamma^2 E^2 + gamma beta t^2 E + beta^2 t^4),
# whose denominator has discriminant -3 gamma^2 beta^2 t^4 < 0 (strictly
# positive, never zero) and whose numerator carries an E factor -- so it is
# finite at the E=0 crossing where the A form is 0/0 -> NaN.

@helper
def pbe_c_erf_gws_H(rs, z, t):
    return (
        pbe_c_erf_gws_gamma*(mphi(z)**Integer(3))*xc_log1p(
        pbe_c_erf_gws_beta(rs,z)*t**Integer(2)*pbe_c_erf_gws_E(rs,z)
        *(pbe_c_erf_gws_gamma*pbe_c_erf_gws_E(rs,z) + pbe_c_erf_gws_beta(rs,z)*t**Integer(2))
        /(pbe_c_erf_gws_gamma**Integer(2)*pbe_c_erf_gws_E(rs,z)**Integer(2)
        + pbe_c_erf_gws_gamma*pbe_c_erf_gws_beta(rs,z)*t**Integer(2)*pbe_c_erf_gws_E(rs,z)
        + pbe_c_erf_gws_beta(rs,z)**Integer(2)*t**Integer(4)))
    )

# first eq. of eq. (6)

def f(rs, z, xt, xs0, xs1):
    return lda_c_pw_erf_f(rs,z) + pbe_c_erf_gws_H(rs, z, tt(rs,z,xt))

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_c_pbe_erf_gws_params"
