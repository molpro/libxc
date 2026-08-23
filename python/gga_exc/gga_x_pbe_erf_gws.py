"""
 2018 Authored by Andrea Kreppel
 2022 Edited by Henryk Laqua
 2024 Numerical stability by Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.

 Short-range PBE exchange functional Goll/Werner/Stoll
 E. Goll, H.-J. Werner, and H. Stoll., Phys. Chem. Chem. Phys. 7, 3917 (2005).
 DOI:10.1039/B509242F
"""

# type: gga_exc
# prefix:
#   gga_x_pbe_erf_gws_params *params;
#   assert(p->params != NULL);
#   params = (gga_x_pbe_erf_gws_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_kappa = param_default("kappa")
params_a_b_PBE = param_default("b_PBE")
params_a_ax = param_default("ax")

u = Symbol("u")

# short-range LDA is the basis of short-range PBE
include('lda_x_erf')

#
# in short-range PBE, the constant b is now mu-dependent.

# coefficients given in the text below eq. (4)

@helper
def pbe_x_erf_gws_c1_b(x):
    return Integer(1) + Integer(22)*x**Integer(2) + Integer(144)*x**Integer(4)

@helper
def pbe_x_erf_gws_c2_b(x):
    return Integer(2)*x**Integer(2)*(-Integer(7)+Integer(72)*x**Integer(2))

@helper
def pbe_x_erf_gws_c3_b(x):
    return -Integer(864)*x**Integer(4)*(-Integer(1)+Integer(2)*x**Integer(2))

@helper
def pbe_x_erf_gws_c4_b(x):
    return x**Integer(2)*(-Integer(3) - Integer(24)*x**Integer(2) + Integer(32)*x**Integer(4) + Integer(8)*x*sqrt(pi)*erf(Integer(1)/(Integer(2)*x)))

# rewrite eq. (4) in terms of exp(-1/(4 mu^2)) so we can screen the ill-behaving term

@helper
def invexp_b(mu_t):
    return m_recexp(Integer(4)*(mu_t)**Integer(2))

# the same factor in closed (native exp) form; m_recexp is the guarded
# version of this, but series() cannot expand m_recexp's piecewise body,
# so the large-mu_t expansion uses this form

@helper
def invexp_b_closed(mu_t):
    return exp(-Integer(1)/(Integer(4)*(mu_t)**Integer(2)))

# b as a function of mu_t and the value of the exp(-1/(4 mu^2)) factor,
# so the same formula serves both the runtime form (guarded m_recexp)
# and the large-mu_t series (native exp, which series() can expand --
# m_recexp evaluates to a piecewise that it cannot).

@helper
def pbe_x_erf_gws_bb(mu_t, ie):
    return ( -pbe_x_erf_gws_c1_b(mu_t)*ie + pbe_x_erf_gws_c2_b(mu_t) )/( pbe_x_erf_gws_c3_b(mu_t)*ie + Integer(54)*pbe_x_erf_gws_c4_b(mu_t) )

@helper
def pbe_x_erf_gws_b(mu_t):
    return pbe_x_erf_gws_bb(mu_t, invexp_b(mu_t))

#
# special case b(0) == 7/81

pbe_x_erf_gws_b_piece0 = Integer(7)/Integer(81)

# fixed (not mu, rs,z dependent) PBE parameters

# default parameters

if defined('gga_x_pbe_erf_gws_params'):
  params_a_kappa = Float('0.8040')
  params_a_b_PBE = Float('0.2195149727645171')
  params_a_ax = Float('19.0')

@helper
def pbe_x_erf_gws_kappa_fx(rs, z):
    return params_a_kappa

# we may want to extent this to a version with a density-depended kappa later

pbe_x_erf_gws_x_b_orig = params_a_b_PBE

pbe_x_erf_gws_ax = params_a_ax

# For large mu_t the denominator of pbe_x_erf_gws_b,
# c3*exp(-1/(4 mu^2)) + 54*c4,
# is the difference of two terms that both grow like mu^6 but nearly
# cancel (the true b is O(1/mu^2)).  At very low densities mu_t = nu/2
# becomes large (~1e2 and beyond): the two ~mu^6 terms reach ~1e36 and
# cancel away every available digit, so b is computed as a spurious
# infinity, which multiplied by the underflowed exp(-ax mu^2) factor
# gives inf*0 = NaN.
#
# Replace the large-mu_t branch by the Maple-generated, cancellation-free
# expansion of b for large mu_t, glued to the guarded m_recexp form below
# the cutoff.  b is actually analytic at mu_t = infinity (the 1/mu_t^6
# numerator/denominator parts cancel, b -> 1/(72 mu_t^2)), so expand via
# the substitution mu_t = 1/u and an ordinary Taylor series at u = 0
# (asympt at infinity fails on the erf/exp combination); to_elementary
# turns the inert m_recexp into native exp so series() can expand it.
# The branches clamp their argument with m_max/m_min so neither is
# evaluated in the diverging region (cf. enforce_smooth_lr).

@helper
def pbe_x_erf_gws_b_asymp(a):
    return (
        maple_eval(convert(maple_series(pbe_x_erf_gws_bb(Integer(1)/u, invexp_b_closed(Integer(1)/u)), u, Integer(0), Integer(18)),
        polynom), u, Integer(1)/a)
    )

@helper
def pbe_x_erf_gws_b_smooth(mu_t):
    return (
        my_piecewise3(mu_t >= Integer(2),
        pbe_x_erf_gws_b_asymp(m_max(mu_t, Integer(2))),
        pbe_x_erf_gws_b(m_min(mu_t, Integer(2))))
    )

# modified b from eq. (5)

@helper
def pbe_x_erf_gws_b_mod(mu_t):
    return (
        pbe_x_erf_gws_x_b_orig/pbe_x_erf_gws_b_piece0
        * pbe_x_erf_gws_b_smooth(mu_t) * exp(-pbe_x_erf_gws_ax*mu_t**Integer(2))
    )

# we emplow nu/2 (spin-nu) instead of nu

@helper
def nu_2(rs, z):
    return nu(rs,z)/Integer(2)

# second part of eq. (3).  NB: unlike the rest of the PBE family this
# one keeps the original 1 + kappa*(1 - kappa/(kappa + b s^2)) form
# rather than the cancellation-free 1 + kappa*b s^2/(kappa + b s^2):
# the cancellation-free form puts the transcendental b (= b_mod, with
# erf/exp inside) in the numerator, which trips a content/content
# error in Maple 2025's simplify() of the spin-scaled f below.  The
# cancellation here is energy-only and ~eps (the enhancement is
# 1 + small, and the potential is built by symbolic differentiation,
# which drops the additive constants regardless), so the original
# form loses nothing measurable.

@helper
def pbe_x_erf_gws_Fx(rs, z, s):
    return Integer(1) + pbe_x_erf_gws_kappa_fx(rs,z)*(Integer(1) - pbe_x_erf_gws_kappa_fx(rs,z)/(pbe_x_erf_gws_kappa_fx(rs,z) + pbe_x_erf_gws_b_mod(nu_2(rs,z))*s**Integer(2)))

include('lda_x_erf')

# first part of eq. (3)

@helper
def f_pbe_x_erf_gws_spin(rs, z, xs):
    return lda_x_erf_spin(rs,z)*pbe_x_erf_gws_Fx(rs,z,xs*X2S)

@helper
def rs_a(rs, z):
    return simplify(r_ws(n_spin(rs,z)))

@helper
def rs_b(rs, z):
    return simplify(r_ws(n_spin(rs,-z)))

def f(rs, z, xt, xs0, xs1):
    return (
        simplify((
        + my_piecewise3(screen_dens(rs, z),Integer(0),f_pbe_x_erf_gws_spin(rs_a(rs,z),Integer(1),xs0)*n_spin(rs, z))
        + my_piecewise3(screen_dens(rs,-z),Integer(0),f_pbe_x_erf_gws_spin(rs_b(rs,z),Integer(1),xs1)*n_spin(rs,-z))
        )/n_total(rs))
    )

TYPE = "gga_exc"
PARAMS_STRUCT = "gga_x_pbe_erf_gws_params"
