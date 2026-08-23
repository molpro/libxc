(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

$define gga_x_rpw86_params
$include "gga_x_pw86.mpl"

lv_alpha := 0.02178:
lv_beta  := 1.15:
lv_muLV   := 0.8491/9:

(* lv_f0 = lv_A + lv_B*pw86_f0.  lv_A and lv_B are bounded rationals, but
   at a near-empty spin channel the reduced gradient s -> infinity
   (s ~ 1e10), and the s^6 denominators' high derivatives overflow
   (v2rho2 -> inf) even though the values are fine.  They are rational
   (poles at |s| = (1/lv_alpha)^(1/6) ~ 1.9), so their large-s expansion
   converges; switch to it above a cutoff (pw86_f0 itself stays finite and
   is left direct).  enforce_smooth_lr clamps both branches so neither is
   evaluated in its diverging region. *)
lv_A := s -> (1 + lv_muLV*s^2)/(1 + lv_alpha*s^6):
lv_B := s -> lv_alpha*s^6/(lv_beta + lv_alpha*s^6):
lv_cut := 100:
lv_f0 := s ->
   + enforce_smooth_lr(lv_A, s, lv_cut, 10)
   + enforce_smooth_lr(lv_B, s, lv_cut, 10)*pw86_f0(s):

lv_f  := x -> lv_f0(gga_s(x)):

f := (rs, z, xt, xs0, xs1) -> gga_exchange(lv_f, rs, z, xs0, xs1):
