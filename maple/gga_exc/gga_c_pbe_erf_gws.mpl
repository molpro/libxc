(*
 2018 Authored by Andrea Kreppel
 2022 Edited by Henryk Laqua

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.

 Short-range PBE correlation functional Goll/Werner/Stoll
 Goll, Werner, Stoll Phys. Chem. Chem. Phys. 7, (2005) 3917.
*)

(* type: gga_exc *)

(* prefix:
  gga_c_pbe_erf_gws_params *params;

  assert(p->params != NULL);
  params = (gga_c_pbe_erf_gws_params * )(p->params);
*)

$define lda_c_pw_params
$include "lda_c_pw_erf.mpl"
$include "lda_c_pw.mpl"

(*default parameters*)
$ifdef gga_c_pbe_erf_gws_params
params_a_beta  := 0.06672455060314922:
params_a_gamma := 0.031090690869654895034:
params_a_a_c    := 2.78
$endif

(*params*)
pbe_c_erf_gws_gamma := params_a_gamma:
pbe_c_erf_gws_beta_orig := params_a_beta:
pbe_c_erf_gws_a_c := params_a_a_c:

pbe_c_erf_gws_kS := (rs) -> (3/(4*Pi*n_total(rs)))^(1/3):

(*eq. (6)*)
pbe_c_erf_gws_beta := (rs, z) -> pbe_c_erf_gws_beta_orig * (lda_c_pw_erf_f(rs,z)/f_pw(rs,z))^pbe_c_erf_gws_a_c:

(* third eq. of eq. (6): A = beta/(gamma*E), E = expm1(...).  A diverges where
   the attenuated LDA correlation lda_c_pw_erf_f crosses zero (E -> 0), which the
   plain (always-negative) f_pw never does -- so H below keeps E in the
   numerator instead of forming A, staying finite and pole-free there. *)
pbe_c_erf_gws_E := (rs, z) -> xc_expm1(-lda_c_pw_erf_f(rs,z)/((mphi(z)^3)*pbe_c_erf_gws_gamma)):
pbe_c_erf_gws_A := (rs, z) -> pbe_c_erf_gws_beta(rs, z)/(pbe_c_erf_gws_gamma*pbe_c_erf_gws_E(rs, z)):

(* second eq. of eq. (6).  The H argument (beta t^2/gamma)(1+A t^2)/(1+A t^2+A^2 t^4),
   multiplied top and bottom by (gamma E)^2, is the algebraically identical
   beta t^2 E (gamma E + beta t^2)/(gamma^2 E^2 + gamma beta t^2 E + beta^2 t^4),
   whose denominator has discriminant -3 gamma^2 beta^2 t^4 < 0 (strictly
   positive, never zero) and whose numerator carries an E factor -- so it is
   finite at the E=0 crossing where the A form is 0/0 -> NaN. *)
pbe_c_erf_gws_H := (rs, z, t) -> pbe_c_erf_gws_gamma*(mphi(z)^3)*xc_log1p(
  pbe_c_erf_gws_beta(rs,z)*t^2*pbe_c_erf_gws_E(rs,z)
    *(pbe_c_erf_gws_gamma*pbe_c_erf_gws_E(rs,z) + pbe_c_erf_gws_beta(rs,z)*t^2)
  /(pbe_c_erf_gws_gamma^2*pbe_c_erf_gws_E(rs,z)^2
    + pbe_c_erf_gws_gamma*pbe_c_erf_gws_beta(rs,z)*t^2*pbe_c_erf_gws_E(rs,z)
    + pbe_c_erf_gws_beta(rs,z)^2*t^4)):

(* first eq. of eq. (6)*)
f := (rs, z, xt, xs0, xs1) -> lda_c_pw_erf_f(rs,z) + pbe_c_erf_gws_H(rs, z, tt(rs,z,xt)):

