(*
 2018 Authored by Andrea Kreppel
 2022 Edited by Henryk Laqua
 2024 Numerical stability by Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.

 Short-range PBE exchange functional Goll/Werner/Stoll
 E. Goll, H.-J. Werner, and H. Stoll., Phys. Chem. Chem. Phys. 7, 3917 (2005).
 DOI:10.1039/B509242F
*)

(* type: gga_exc *)

(* short-range LDA is the basis of short-range PBE*)
$include "lda_x_erf.mpl"

(*
 in short-range PBE, the constant b is now mu-dependent.
*)

(* coefficients given in the text below eq. (4) *)
pbe_x_erf_gws_c1_b := x -> 1 + 22*x^2 + 144*x^4:
pbe_x_erf_gws_c2_b := x -> 2*x^2*(-7+72*x^2):
pbe_x_erf_gws_c3_b := x -> -864*x^4*(-1+2*x^2):
pbe_x_erf_gws_c4_b := x -> x^2*(-3 - 24*x^2 + 32*x^4 + 8*x*sqrt(Pi)*erf(1/(2*x))):

(* rewrite eq. (4) in terms of exp(-1/(4 mu^2)) so we can screen the ill-behaving term *)
invexp_b := mu_t -> m_recexp(4*(mu_t)^2):
(* the same factor in closed (native exp) form; m_recexp is the guarded
   version of this, but series() cannot expand m_recexp's piecewise body,
   so the large-mu_t expansion uses this form *)
invexp_b_closed := mu_t -> exp(-1/(4*(mu_t)^2)):
(* b as a function of mu_t and the value of the exp(-1/(4 mu^2)) factor,
   so the same formula serves both the runtime form (guarded m_recexp)
   and the large-mu_t series (native exp, which series() can expand --
   m_recexp evaluates to a piecewise that it cannot). *)
pbe_x_erf_gws_bb := (mu_t, ie) -> ( -pbe_x_erf_gws_c1_b(mu_t)*ie + pbe_x_erf_gws_c2_b(mu_t) )/( pbe_x_erf_gws_c3_b(mu_t)*ie + 54*pbe_x_erf_gws_c4_b(mu_t) ):
pbe_x_erf_gws_b := mu_t -> pbe_x_erf_gws_bb(mu_t, invexp_b(mu_t)):

(*
 special case b(0) == 7/81
*)
pbe_x_erf_gws_b_piece0 := 7/81:


(*fixed (not mu, rs,z dependent) PBE parameters*)
(* prefix:
  gga_x_pbe_erf_gws_params *params;
  assert(p->params != NULL);
  params = (gga_x_pbe_erf_gws_params * )(p->params);
*)

(*default parameters*)
$ifdef gga_x_pbe_erf_gws_params
params_a_kappa := 0.8040:
params_a_b_PBE := 0.2195149727645171:
params_a_ax    := 19.0:
$endif

pbe_x_erf_gws_kappa_fx := (rs,z) -> params_a_kappa: (* we may want to extent this to a version with a density-depended kappa later *)
pbe_x_erf_gws_x_b_orig := params_a_b_PBE:
pbe_x_erf_gws_ax := params_a_ax:

(* For large mu_t the denominator of pbe_x_erf_gws_b,
     c3*exp(-1/(4 mu^2)) + 54*c4,
   is the difference of two terms that both grow like mu^6 but nearly
   cancel (the true b is O(1/mu^2)).  At very low densities mu_t = nu/2
   becomes large (~1e2 and beyond): the two ~mu^6 terms reach ~1e36 and
   cancel away every available digit, so b is computed as a spurious
   infinity, which multiplied by the underflowed exp(-ax mu^2) factor
   gives inf*0 = NaN.

   Replace the large-mu_t branch by the Maple-generated, cancellation-free
   expansion of b for large mu_t, glued to the guarded m_recexp form below
   the cutoff.  b is actually analytic at mu_t = infinity (the 1/mu_t^6
   numerator/denominator parts cancel, b -> 1/(72 mu_t^2)), so expand via
   the substitution mu_t = 1/u and an ordinary Taylor series at u = 0
   (asympt at infinity fails on the erf/exp combination); to_elementary
   turns the inert m_recexp into native exp so series() can expand it.
   The branches clamp their argument with m_max/m_min so neither is
   evaluated in the diverging region (cf. enforce_smooth_lr). *)
pbe_x_erf_gws_b_asymp := a ->
  eval(convert(series(pbe_x_erf_gws_bb(1/u, invexp_b_closed(1/u)), u=0, 18),
    polynom), u=1/a):

pbe_x_erf_gws_b_smooth := mu_t -> my_piecewise3(mu_t >= 2,
  pbe_x_erf_gws_b_asymp(m_max(mu_t, 2)),
  pbe_x_erf_gws_b(m_min(mu_t, 2))):

(* modified b from eq. (5) *)
pbe_x_erf_gws_b_mod := mu_t -> pbe_x_erf_gws_x_b_orig/pbe_x_erf_gws_b_piece0
  * pbe_x_erf_gws_b_smooth(mu_t) * exp(-pbe_x_erf_gws_ax*mu_t^2):

# we emplow nu/2 (spin-nu) instead of nu
nu_2 := (rs,z) -> nu(rs,z)/2:

(* second part of eq. (3).  NB: unlike the rest of the PBE family this
   one keeps the original 1 + kappa*(1 - kappa/(kappa + b s^2)) form
   rather than the cancellation-free 1 + kappa*b s^2/(kappa + b s^2):
   the cancellation-free form puts the transcendental b (= b_mod, with
   erf/exp inside) in the numerator, which trips a content/content
   error in Maple 2025's simplify() of the spin-scaled f below.  The
   cancellation here is energy-only and ~eps (the enhancement is
   1 + small, and the potential is built by symbolic differentiation,
   which drops the additive constants regardless), so the original
   form loses nothing measurable. *)
pbe_x_erf_gws_Fx := (rs,z,s) -> 1 + pbe_x_erf_gws_kappa_fx(rs,z)*(1 - pbe_x_erf_gws_kappa_fx(rs,z)/(pbe_x_erf_gws_kappa_fx(rs,z) + pbe_x_erf_gws_b_mod(nu_2(rs,z))*s^2)):

$include "lda_x_erf.mpl"
(* first part of eq. (3) *)
f_pbe_x_erf_gws_spin := (rs, z, xs) -> lda_x_erf_spin(rs,z)*pbe_x_erf_gws_Fx(rs,z,xs*X2S):

rs_a := (rs,z) -> simplify(r_ws(n_spin(rs,z))):
rs_b := (rs,z) -> simplify(r_ws(n_spin(rs,-z))):
f := (rs, z, xt, xs0, xs1) -> simplify((
+ my_piecewise3(screen_dens(rs, z),0,f_pbe_x_erf_gws_spin(rs_a(rs,z),1,xs0)*n_spin(rs, z))
+ my_piecewise3(screen_dens(rs,-z),0,f_pbe_x_erf_gws_spin(rs_b(rs,z),1,xs1)*n_spin(rs,-z))
)/n_total(rs)):
