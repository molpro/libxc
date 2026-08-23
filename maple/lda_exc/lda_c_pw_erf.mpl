(*
 2018 Authored by Andrea Kreppel
 2022 Edited by Henryk Laqua

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.

 Short-range (erfc) Perdew Wang correlation functional according to
 S. Paziani, S. Moroni, P. Gori-Giorgi, and G. B. Bachelet.,  Phys. Rev. B 73, 155111 (2006).
 DOI:10.1103/PhysRevB.73.155111
*)


(* type: lda_exc *)

#$define lda_x_params
$define lda_c_pw_params
#$include "lda_x.mpl"
$include "lda_c_pw.mpl"

(*params*)
lda_c_pw_erf_mu := p_a_cam_omega:
lda_c_pw_erf_b0 := rs -> 0.784949*rs:
lda_c_pw_erf_alpha := (4/(9*Pi))^(1/3):

(* params below eq. (22)*)
lda_c_pw_erf_ac := 5.84605:
lda_c_pw_erf_bc := lda_c_pw_erf_d - 3*Pi*lda_c_pw_erf_alpha/(4*ln(2)-4):
lda_c_pw_erf_c := 3.91744:
lda_c_pw_erf_d := 3.44851:
(*eq. (22).  Algebraic identity:
     log(num/den) = log(1 + (num - den)/den) = log1p((num - den)/den).
   At small x both num and den approach 1, so log(num/den) is the
   catastrophic log-of-close-to-1.  The matching `1 + ac*x` terms
   cancel exactly in num - den; the subtraction is written
   symbolically against the lda_c_pw_erf_Q_num/_den helpers so the
   polynomials stay single-source -- Maple simplifies before codegen,
   so the emitted C is still cancellation-free and any future
   retuning of num/den flows through automatically. *)
lda_c_pw_erf_Q_num := x -> 1 + lda_c_pw_erf_ac*x + lda_c_pw_erf_bc*x^2 + lda_c_pw_erf_c*x^3:
lda_c_pw_erf_Q_den := x -> 1 + lda_c_pw_erf_ac*x + lda_c_pw_erf_d*x^2:
lda_c_pw_erf_Q := x -> (2*ln(2)-2)*xc_log1p(
  (lda_c_pw_erf_Q_num(x) - lda_c_pw_erf_Q_den(x)) / lda_c_pw_erf_Q_den(x))/Pi^2:

(*eq. (14)*)
lda_c_pw_erf_phin := (n,z) -> 1/2*(opz_pow_n(z, n/3) + opz_pow_n(-z, n/3)):

(*eq. (32) *)
lda_c_pw_erf_g1 := rs -> 2^(5/3)*(1-0.02267*rs)/(5*lda_c_pw_erf_alpha^2*rs^2*(1+0.4319*rs+0.04*rs^2)):
(*g(0,rs,zeta) below eq.(23).
  KEEP IN SYNC: g0, its polynomial part g0_poly, and g0c.
  g0 = 1/2*(1 + g0_poly)*exp(-d*rs) with g0_poly having no constant
  term, so g0c = g0 - 1/2 cancels to O(rs) at small rs (high
  density).  Identity (1+Q)*exp(-d*rs) - 1 = Q + (1+Q)*expm1(-d*rs)
  gives the cancellation-free form below. *)
lda_c_pw_erf_g0_poly := rs -> 0.0207*rs + 0.08193*rs^2 - 0.01277*rs^3 + 0.001859*rs^4:
lda_c_pw_erf_g0 := rs -> 1/2*(1 + lda_c_pw_erf_g0_poly(rs))*exp(-0.7524*rs):
(*g_c(0,rs,zeta) below eq.(23) *)
lda_c_pw_erf_g0c := rs -> 1/2*(lda_c_pw_erf_g0_poly(rs)
  + (1 + lda_c_pw_erf_g0_poly(rs))*xc_expm1(-0.7524*rs)):

(*eq. (33) *)
lda_c_pw_erf_D2 := rs -> exp(-0.547*rs)*(-0.388*rs+0.676*rs^2)/rs^2:
(*eq. (34) *)
lda_c_pw_erf_D3 := rs -> exp(-0.31*rs)*(-4.95*rs+rs^2)/rs^3:

(*eq. (30) *)
lda_c_pw_erf_C2 := (rs,z) -> -3*one_minus_z_pow_n(z, 2)*lda_c_pw_erf_g0c(rs)/(8*rs^3):
lda_c_pw_erf_C3 := (rs,z) -> -one_minus_z_pow_n(z, 2)*lda_c_pw_erf_g0(rs)/(sqrt(2*Pi)*rs^3):
lda_c_pw_erf_C4 := (rs,z) -> -9*lda_c_pw_erf_c4_l(rs,z)/(64*rs^3):
lda_c_pw_erf_C5 := (rs,z) -> -9*lda_c_pw_erf_c5_l(rs,z)/(40*sqrt(2*Pi)*rs^3):

(*eq. (28) *)
lda_c_pw_erf_c4_l := (rs,z) -> ((1+z)/2)^2 * lda_c_pw_erf_g1(rs*(2/(1+z))^(1/3)) + ((1-z)/2)^2 * lda_c_pw_erf_g1(rs*(2/(1-z))^(1/3)) + one_minus_z_pow_n(z, 2)*lda_c_pw_erf_D2(rs)-lda_c_pw_erf_phin(8,z)/(5*lda_c_pw_erf_alpha^2*rs^2):
(*eq. (29) *)
lda_c_pw_erf_c5_l := (rs,z) -> ((1+z)/2)^2 * lda_c_pw_erf_g1(rs*(2/(1+z))^(1/3)) + ((1-z)/2)^2 * lda_c_pw_erf_g1(rs*(2/(1-z))^(1/3)) + one_minus_z_pow_n(z, 2)*lda_c_pw_erf_D3(rs):

(*params below eq. 29*)
lda_c_pw_erf_a1 := (rs,z) -> 4*lda_c_pw_erf_b0(rs)^6*lda_c_pw_erf_C3(rs,z) + lda_c_pw_erf_b0(rs)^8*lda_c_pw_erf_C5(rs,z):
lda_c_pw_erf_a2 := (rs,z) -> 4*lda_c_pw_erf_b0(rs)^6*lda_c_pw_erf_C2(rs,z) + lda_c_pw_erf_b0(rs)^8*lda_c_pw_erf_C4(rs,z) + 6*lda_c_pw_erf_b0(rs)^4*f_pw(rs,z):
lda_c_pw_erf_a3 := (rs,z) -> lda_c_pw_erf_b0(rs)^8*lda_c_pw_erf_C3(rs,z):
lda_c_pw_erf_a4 := (rs,z) -> lda_c_pw_erf_b0(rs)^8*lda_c_pw_erf_C2(rs,z) + 4*lda_c_pw_erf_b0(rs)^6*f_pw(rs,z):
lda_c_pw_erf_a5 := (rs,z) -> lda_c_pw_erf_b0(rs)^8*f_pw(rs,z):

(*eq. 26)*)
lda_c_pw_erf_f := (rs,z) -> f_pw(rs,z)-(lda_c_pw_erf_phin(2,z)^3*lda_c_pw_erf_Q(lda_c_pw_erf_mu*sqrt(rs)/(lda_c_pw_erf_phin(2,z))) + lda_c_pw_erf_a1(rs,z)*lda_c_pw_erf_mu^3 + lda_c_pw_erf_a2(rs,z)*lda_c_pw_erf_mu^4 + lda_c_pw_erf_a3(rs,z)*lda_c_pw_erf_mu^5 + lda_c_pw_erf_a4(rs,z)*lda_c_pw_erf_mu^6 + lda_c_pw_erf_a5(rs,z)*lda_c_pw_erf_mu^8 )/((1+lda_c_pw_erf_b0(rs)^2*lda_c_pw_erf_mu^2)^4):
f := (rs,z) -> lda_c_pw_erf_f(rs,z):
