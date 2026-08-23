(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_c_r2scan_params *params;

  assert(p->params != NULL);
  params = (mgga_c_r2scan_params * )(p->params);
*)

$include "mgga_c_rscan.mpl"
$define lda_c_pw_params
$define lda_c_pw_modified_params
$include "lda_c_pw.mpl"

(* These come from pbe correlation *)
params_a_gamma := (1 - log(2))/Pi^2:
mgamma := params_a_gamma:

(* r2scan values *)
params_a_dp2 := 0.361:

(* Equation (S6) *)

(* Equation (S26) *)
r2scan_f_alpha_neg := a -> exp(-params_a_c1*a/(1 - a)):
r2scan_f_alpha := (a, ff) -> my_piecewise5(
  a <= 0, r2scan_f_alpha_neg(m_min(a, 0)),
  a <= 2.5, rscan_f_alpha_small(m_min(a, 2.5), ff),
  rscan_f_alpha_large(m_max(a, 2.5))):

(* Equation (S28) *)
r2scan_d := z -> (opz_pow_n(z,5/3) + opz_pow_n(-z,5/3))/2:

(* Equation (S33): beta(rs), this is the same as in gga_c_regtpss *)
beta_a := 0.066724550603149220:
beta_b := 0.1:
beta_c := 0.1778:
mbeta := (rs) -> beta_a*(1 + beta_b*rs)/(1 + beta_c*rs):

(* Equation (S30) *)
w1 := (rs, z) -> xc_expm1(-f_pw(rs, z)/(mgamma*mphi(z)^3)):

(* Equation (S27); note that the paper indexes starting from zero *)
r2scan_dfc2 := ff -> add(i*ff[8-i], i=1..7):

(* According to James Furness, this is LSDA0 - see also Equation (S25) *)
r2scan_elsda0 := (rs, z) -> scan_eclda0(rs)*scan_Gc(z):
(* while LSDA1 is just Perdew-Wang *)
r2scan_elsda1 := (rs, z) -> f_pw(rs, z):

(* Derivatives wrt rs *)
r2scan_delsda0 := (rs, z) -> eval(diff(r2scan_elsda0(x1, x2), x1), [x1=rs, x2=z]):
r2scan_delsda1 := (rs, z) -> eval(diff(r2scan_elsda1(x1, x2), x1), [x1=rs, x2=z]):

(* Equation (S34) *)
r2scan_dy := (rs, z, s) -> r2scan_dfc2(rscan_fc)/(27 * mgamma * r2scan_d(z) * mphi(z)^3 * w1(rs, z)) * (
    + 20*rs*(r2scan_delsda0(rs, z) - r2scan_delsda1(rs, z))
    - 45*params_a_eta*(r2scan_elsda0(rs, z) - r2scan_elsda1(rs, z))
  ) * s^2*exp(-s^4/params_a_dp2^4):

(* Equation (S32) *)
r2scan_y := (rs, z, t) -> mbeta(rs)*t^2/(mgamma*w1(rs, z)):

(* Equation (S31). r2scan_g = 1/(1 + 4Y)^(1/4) appears only as
   `1 - r2scan_g`, so we go straight to that form below. *)

(* Equation (S29). The factor (1 - r2scan_g) = 1 - (1 + 4Y)^(-1/4)
   is routed through expm1/log1p so the small-Y limit doesn't lose
   precision in `1 - close-to-1`. *)
r2scan_one_minus_g := (rs, z, s, t) -> -xc_expm1(-(1/4)*xc_log1p(4*(r2scan_y(rs, z, t) - r2scan_dy(rs, z, s)))):
fH := (rs, z, s, t) -> mgamma*mphi(z)^3*xc_log1p(w1(rs, z)*r2scan_one_minus_g(rs, z, s, t)):

(* Now we can build ec1 from (S24) *)
r2scan_ec1 := (rs, z, s, t) -> f_pw(rs, z) + fH(rs, z, s, t):

(* Equation (S35)-(S41) are same as SCAN *)
r2scan_ec0 := (rs, z, s) -> scan_e0(rs, z, s):

(* and the functional itself.  r2scan_c_f_a takes the iso-orbital indicator, so
   that a deorbitalized variant can pass the alpha its kinetic energy functional
   yields directly; see mgga_c_r2scanl.mpl.  Named to avoid colliding with the
   exchange kernel's r2scan_f_a. *)
r2scan_c_f_a := (rs, z, xt, a) ->
  r2scan_ec1(rs, z, gga_s_total(xt), tt(rs, z, xt)) + r2scan_f_alpha(a, rscan_fc)*(
    + r2scan_ec0(rs, z, gga_s_total(xt)) - r2scan_ec1(rs, z, gga_s_total(xt), tt(rs, z, xt))):

r2scan_f := (rs, z, xt, xs0, xs1, ts0, ts1) ->
  r2scan_c_f_a(rs, z, xt, mgga_alpha_total_reg(z, xt, ts0, ts1, params_a_eta)):

f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) ->
  r2scan_f(rs, z, xt, xs0, xs1, ts0, ts1):
