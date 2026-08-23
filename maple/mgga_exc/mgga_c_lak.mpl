(*
 Copyright (C) 2025 Timo Lebeda and Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

$define lda_c_pw_params
$define lda_c_pw_modified_params
$include "lda_c_pw.mpl"
$include "mgga_x_lak.mpl"

(* parameters from page 4 of SI *)
lak_mu_a := -lak_mu_ax/2:
lak_b1c := 0.0468:
lak_b2c := 0.205601:
lak_chi_zero := 1.55344:
lak_b3c := 2.85:
lak_ac := 10:

(* SI eq 3 *)
lak_Ax := -3/4 * (3/Pi)^(1/3):

(* SI eq 12 *)
lak_ec_rszta := (rs, z, xt, a) -> lak_e0(rs, z, gga_s_total(xt)) + (1-lak_fc(rs, a)) * (lak_e1(rs, z, tt(rs, z, xt)) - lak_e0(rs, z, gga_s_total(xt))) * lak_gnum(gga_s_total(xt)):

(* SI eq 13 *)
lak_e0 := (rs, z, s) -> (lak_eclda0(rs) + lak_H0(rs, s))*lak_Gc(z):

(* SI eq 14 *)
lak_eclda0 := rs -> -lak_b1c / (1 + lak_b2c*rs):

(* SI eq 15 *)
lak_H0 := (rs, s) -> lak_b1c*log(m_max(XC_MIN,1 + lak_w0(rs)*(-xc_expm1(-(1/4)*xc_log1p(4*lak_chi_zero*s^2))))):

(* SI eq 16 *)
lak_w0 := rs -> xc_expm1(-lak_eclda0(rs)/lak_b1c):

(* SI eq 17 *)
lak_G_cnst := 2.3631:
lak_Gc := z -> (1 - lak_G_cnst*(2^(1/3) - 1)*f_zeta(z))*one_minus_z_pow_n(z, 12):

(* SI eq 19; the expression is ill-behaved for alpha->0 i.e. alpha tilde -> infinity.
   Series at infinity is 1 - 4/(pi^2 x) + 16/(3 pi^4 x^3) - 64/(5 pi^6 x^5) + ...
   (odd 1/x powers only).  Order 6 (terms up to 1/x^5) gives 4th
   derivative truncation 7*6*5*4 * c_7 / x_c^11 ~ O(840) * eps^11
   at x_c = 1/eps -- absurdly below XC_EPSILON * |actual 4th
   derivative ~ eps^5|, plenty of margin. *)
lak_fc0 := x -> 2/Pi * arctan(Pi/2 * x):
lak_fc_taylor := x -> eval(convert(eval(series(lak_fc0(y),y=infinity,6),csgn=1),polynom),y=x):
lak_fc_piecewise := x -> my_piecewise3(x >= 1/XC_EPSILON, lak_fc_taylor(m_max(x, 1/XC_EPSILON)), lak_fc0(m_min(x,1/XC_EPSILON))):
(* further extends fc(alpha) to negative alpha *)
lak_fc := (rs, a) -> my_piecewise3(a < 0, 2+lak_fc_piecewise(lak_fcGE2(rs)*m_abs(lak_at(rs,a))), lak_fc_piecewise(lak_fcGE2(rs)*lak_at(rs,a))):

(* SI eq 20 *)
lak_at := (rs, a) -> (a-1)/(m_max(rs*a, XC_EPSILON)):

(* SI eq 21 *)
lak_fcGE2 := rs -> lak_beta_at(rs) / (m_min(f_pw(rs,0)-lak_eclda0(rs), -XC_EPSILON)):

(* SI eq 22 *)
lak_beta_at := rs -> -lak_Ac * lak_mu_ac(rs):

(* SI eq 23 *)
lak_mu_ac := rs -> lak_Cma(rs)*lak_mu_a - lak_mu_ax:

(* SI eq 24 *)
lak_e1 := (rs, z, t) -> f_pw(rs, z) + lak_H1(rs, z, t):

(* SI eq 25 (&26-28) *)
lak_H1 := (rs, z, t) -> my_piecewise3(lak_beta_t(rs) >=0, lak_H1p(rs,z,t), lak_H1m(rs,z,t) ):

(* SI eq 27 *)
lak_ct := z -> (3*Pi^2/16)^(2/3) / mphi(z)^2:

(* SI eq 29; note that equation is wrong in the SI - argument of ct is missing *)
lak_beta_t := rs -> lak_Ac / lak_ct(0) * lak_mu_sc(rs):

(* SI eq 30 *)
lak_Ac := RS_FACTOR * lak_Ax:

(* SI eq 31 *)
lak_mu_sc := rs -> MU_GE * (lak_Cma(rs)*(1+6*lak_mu_a) - (1+6*lak_mu_ax)):

(* SI eq 33 *)
lak_H1p := (rs, z, t) -> lak_gamma*mphi(z)^3*log(m_max(1 + lak_w1(rs,z) * lak_one_minus_g1p(rs, z, t) * (lak_one_minus_g2(rs, z, t) + lak_g3p(rs, z, t)), XC_MIN)):

(* SI eq 34 *)
lak_H1m := (rs, z, t) -> lak_gamma*mphi(z)^3*log(m_max(1 + lak_w1(rs,z) * (1 - lak_g1m(rs, z, t)) * (lak_one_minus_g2(rs, z, t) - lak_g3m(rs, z, t)), XC_MIN)):

(* SI eq 35 *)
lak_gamma := (1 - log(2))/Pi^2:

(* SI eq 36, note that SI has missing parentheses: phi zeta should be phi(zeta) *)
lak_w1 := (rs, z) -> xc_expm1(-f_pw(rs, z)/(lak_gamma*mphi(z)^3)):

(* SI eq 37; lak_g1p = (m_max(1 + 4At^2, eps))^(-1/4) only ever appears
   as `1 - lak_g1p`, so we go straight to that form via expm1/log1p.
   lak_g1m is kept because its consumer still needs `(1 - lak_g1m)` as
   a separate quantity (the clamp regime can drive it large/negative
   in a way that doesn't fit the expm1 pattern cleanly). *)
lak_one_minus_g1p := (rs, z, t) -> -xc_expm1(-(1/4)*xc_log1p(4*lak_A(rs,z)*t^2)):
lak_g1m := (rs, z, t) -> (m_max(1 - 4*lak_A(rs,z)*t^2, XC_EPSILON))^(-1/4):

(* SI eq 38; lak_g2 = 1/(1 + X^2) only appears as `1 - lak_g2`, so we
   write that as X^2/(1 + X^2) directly -- algebraic identity, no
   cancellation. *)
lak_one_minus_g2 := (rs, z, t) -> (lak_A(rs,z)*t^2)^2/(1 + (lak_A(rs,z)*t^2)^2):

(* SI eq 39 *)
lak_g3p := (rs, z, t) -> (m_max(1 + lak_ac*lak_A(rs,z)*t^2, XC_EPSILON))^(-1):

(* SI eq 40 *)
lak_g3m := (rs, z, t) -> (m_max(1 - (lak_w1(rs,z)+lak_b3c) * lak_A(rs,z) * t^2, XC_EPSILON))^(-1):

(* SI eq 41 *)
lak_A := (rs, z) -> lak_beta_t(rs) / (lak_gamma*lak_w1(rs,z)):

(* SI eq 62 *)
lak_Cma := rs -> lak_Cs0 * (1 + 0.1*rs^0.65) / ( (1 + 0.065*rs^0.9)*(1 + 0.03*rs^1.2) ):

(* Constant in SI main text after eq 62 *)
lak_Cs0 := -16*Pi*(3*Pi^2)^(1/3)*2.568/(3000*MU_GE):

(* Build the functional; alpha is the shared mgga_alpha_total from util.mpl *)
lak_ec := (rs, z, xt, xs0, xs1, ts0, ts1) -> lak_ec_rszta(rs, z, xt, mgga_alpha_total(z, xt, ts0, ts1)):
f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) -> lak_ec(rs, z, xt, xs0, xs1, ts0, ts1):
