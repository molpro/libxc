(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)

$define lda_c_pw_params
$define lda_c_pw_modified_params
$include "lda_c_pw.mpl"

alpha := (4/(9*Pi))^(1/3):

# Eq. (46) of Phys. Rev. A 73, 032506 (2006)
# I am not sure if this is the on-top pair correlation functional
# intended by the authors
g0_C    :=  0.08193:
g0_D    := -0.01277:
g0_E    :=  0.001859:
g0_dd   :=  0.7524:
g0_aHD  := -alpha*(Pi^2 + 6*log(2) - 3)/(5 * Pi):
g0_B    := -2*g0_aHD - g0_dd:
# KEEP IN SYNC: pmgb_g0, its polynomial part pmgb_g0_poly, and the
# pmgb_g0_m_half helper below.  pmgb_g0_poly has no constant term.
pmgb_g0_poly := rs -> -g0_B*rs + g0_C*rs^2 + g0_D*rs^3 + g0_E*rs^4:
pmgb_g0 := rs ->
        (1 + pmgb_g0_poly(rs))*exp(-g0_dd*rs)/2:
# g0(rs) - 1/2, cancellation-free at small rs (high density) via
# (1+Q)*exp(-d*rs) - 1 = Q + (1+Q)*expm1(-d*rs).
pmgb_g0_m_half := rs -> (pmgb_g0_poly(rs)
        + (1 + pmgb_g0_poly(rs))*xc_expm1(-g0_dd*rs))/2:

# text between eqs (23) and (24).
# pmgb_gc0 = g0(rs) - (1-z^2)/2 = (g0(rs) - 1/2) + z^2/2
#          = pmgb_g0_m_half(rs) + z^2/2,
# which fixes both the rs -> 0 cancellation (g0 -> 1/2) and is exact
# at z -> 0.
pmgb_gc0 := (rs, z) -> pmgb_g0_m_half(rs) + z^2/2:

# Eq. (14)
pmgb_phi := (n, z) ->
         (opz_pow_n(z,n/3) + opz_pow_n(-z,n/3))/2:

# Eq. (22)
pmgb_Q_a := 5.84605:
pmgb_Q_c := 3.91744:
pmgb_Q_d := 3.44851:
pmgb_Q_b := pmgb_Q_d - 3*Pi*alpha/(4*log(2) - 4):

(* Algebraic identity:
     log(num/den) = log1p((num - den)/den).
   At small x both num and den approach 1, so log(num/den) is the
   catastrophic log-of-close-to-1.  The matching `1 + pmgb_Q_a*x`
   terms cancel exactly in num - den; the subtraction is written
   symbolically against pmgb_Q_num/_den helpers so the polynomials
   stay single-source -- Maple simplifies before codegen, so the
   emitted C is still cancellation-free and any future retuning of
   num/den flows through automatically. *)
pmgb_Q_num := x -> 1 + pmgb_Q_a*x + pmgb_Q_b*x^2 + pmgb_Q_c*x^3:
pmgb_Q_den := x -> 1 + pmgb_Q_a*x + pmgb_Q_d*x^2:
pmgb_Q := x ->
       ((2*log(2) - 2)/Pi^2) * xc_log1p(
        (pmgb_Q_num(x) - pmgb_Q_den(x)) / pmgb_Q_den(x)
       ):

# Eq. (31)
pmgb_b0 := (rs) -> 0.784949*rs:

# Eq. (32)
pmgb_gpp1 := (rs) -> (2^(5/3)/(5*alpha^2*rs^2)) *
          (1 - 0.02267*rs)/(1 + 0.4319*rs + 0.04*rs^2):

# Eq. (33)
pmgb_D2 := (rs) -> (-0.388*rs + 0.676*rs^2)*exp(-0.547*rs)/rs^2:

# Eq. (34)
pmgb_D3 := (rs) -> (-4.95*rs + rs^2)*exp(-0.31*rs)/rs^3:

# Eq. (28)
pmgb_cc4 := (rs, z) ->
       + (opz_pow_n( z,2)/4) * pmgb_gpp1(rs*(2/(1 + z))^(1/3))
       + (opz_pow_n(-z,2)/4) * pmgb_gpp1(rs*(2/(1 - z))^(1/3))
       + one_minus_z_pow_n(z, 2) * pmgb_D2(rs)
       - pmgb_phi(8, z)/(5*alpha^2*rs^2):

# Eq. (29)
pmgb_cc5 := (rs, z) ->
       + (opz_pow_n( z,2)/4) * pmgb_gpp1(rs*(2/(1 + z))^(1/3))
       + (opz_pow_n(-z,2)/4) * pmgb_gpp1(rs*(2/(1 - z))^(1/3))
       + one_minus_z_pow_n(z, 2) * pmgb_D3(rs):

# Eq. (30)
pmgb_C2 := (rs, z) ->
        -3*one_minus_z_pow_n(z, 2)*pmgb_gc0(rs,z)/(8*rs^3):

pmgb_C3 := (rs, z) ->
        -one_minus_z_pow_n(z, 2)*pmgb_g0(rs)/(sqrt(2*Pi)*rs^3):

pmgb_C4 := (rs, z) ->
        -9*pmgb_cc4(rs, z)/(64*rs^3):

pmgb_C5 := (rs, z) ->
        -9*pmgb_cc5(rs, z)/(40*sqrt(2*Pi)*rs^3):

pmgb_a1 := (rs, z) ->
        4*pmgb_b0(rs)^6*pmgb_C3(rs, z) + pmgb_b0(rs)^8*pmgb_C5(rs, z):

pmgb_a2 := (rs, z) ->
        4*pmgb_b0(rs)^6*pmgb_C2(rs, z) + pmgb_b0(rs)^8*pmgb_C4(rs, z)
        + 6*pmgb_b0(rs)^4*f_pw(rs, z):

pmgb_a3 := (rs, z) ->
        pmgb_b0(rs)^8*pmgb_C3(rs, z):

pmgb_a4 := (rs, z) ->
        pmgb_b0(rs)^8*pmgb_C2(rs, z) + 4*pmgb_b0(rs)^6*f_pw(rs, z):

pmgb_a5 := (rs, z) ->
        pmgb_b0(rs)^8*f_pw(rs, z):

# Eq. (26)
pmgb_ec_LR := (rs, z) -> (
           + pmgb_phi(2, z)^3*pmgb_Q(p_a_cam_omega*sqrt(rs)/pmgb_phi(2, z))
           + pmgb_a1(rs, z)*p_a_cam_omega^3
           + pmgb_a2(rs, z)*p_a_cam_omega^4
           + pmgb_a3(rs, z)*p_a_cam_omega^5
           + pmgb_a4(rs, z)*p_a_cam_omega^6
           + pmgb_a5(rs, z)*p_a_cam_omega^8
           )/(1 + pmgb_b0(rs)^2*p_a_cam_omega^2)^4:

f := (rs, z) -> pmgb_ec_LR(rs, z):
