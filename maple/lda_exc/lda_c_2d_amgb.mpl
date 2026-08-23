(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)

$define xc_dimensions_2d

amgb_aa := [ -0.1925,     0.117331,    0.0234188 ]:
amgb_bb := [  0.0863136, -3.394e-2,   -0.037093  ]:
amgb_cc := [  0.0572384, -7.66765e-3,  0.0163618 ]:
amgb_ee := [  1.0022,     0.4133,      1.424301  ]:
amgb_ff := [ -0.02069,    0,         0       ]:
amgb_gg := [  0.33997,    6.68467e-2,  0       ]:
amgb_hh := [  1.747e-2,   7.799e-4,    1.163099  ]:

amgb_ax = -4/(3*Pi*sqrt(2)):
amgb_beta := 1.3386:

amgb_dd := [seq(-amgb_aa[i]*amgb_hh[i], i=1..3)]:

amgb_alpha := (i, rs) -> amgb_aa[i]
  + (amgb_bb[i]*rs + amgb_cc[i]*rs^2 + amgb_dd[i]*rs^3)
  * xc_log1p(1/(amgb_ee[i]*rs + amgb_ff[i]*rs^1.5 + amgb_gg[i]*rs^2 + amgb_hh[i]*rs^3)):

(* f_zeta_2d_m1(z) Taylor at z = 0 starts as 3z^2/8 + 3z^4/128 +
   7z^6/1024 + ..., so the direct
     f_zeta_2d_m1(z) - 3z^2/8 - 3z^4/128
   cancels to O(z^6) at small z, losing log10(3z^2/8 / (7z^6/1024))
   ~ 2*log10(1/z) - 1 digits.  Use a Maple Taylor polynomial of the
   residual for |z| < 1/2 (where the series converges fast enough to
   stay ULP-accurate with reasonable order) and the direct form
   otherwise.  Order 32 (4 derivatives + ~26 series terms) keeps the
   4th-derivative truncation below XC_EPSILON at the cutoff. *)
amgb_ex6_residual_orig   := z -> f_zeta_2d_m1(z) - 3/8*z^2 - 3/128*z^4:
(* For the series input we use the elementary form of f_zeta_2d_m1,
   ((1+z)^(3/2) + (1-z)^(3/2))/2 - 1.  This equals f_zeta_2d_m1 in its
   generic branch (the opz_pow_n_m1 clamp only fires at z -> -1, never
   at the z=0 expansion point), and is needed because the inert
   opz_pow_n_m1 / my_piecewise3 inside f_zeta_2d_m1 cannot be series-
   expanded by Maple. *)
amgb_ex6_residual_taylor := z -> eval(convert(series(
  ((1+w)^(3/2) + (1-w)^(3/2))/2 - 1 - 3/8*w^2 - 3/128*w^4, w=0, 32), polynom), w=z):
amgb_ex6_residual        := z -> my_piecewise3(m_abs(z) < 1/2,
  amgb_ex6_residual_taylor(z),
  amgb_ex6_residual_orig(z)):

amgb_ex6 := (rs, z) -> -4*sqrt(2)/(3*Pi*rs) * amgb_ex6_residual(z):

f_amgb := (rs, z) ->
  amgb_alpha(1, rs) + amgb_alpha(2, rs)*z^2 + amgb_alpha(3, rs)*z^4 + xc_expm1(-amgb_beta*rs)*amgb_ex6(rs, z):

f := (rs, z) -> f_amgb(rs, z):
