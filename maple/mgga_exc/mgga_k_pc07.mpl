(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_k_pc07_params *params;

  assert(p->params != NULL);
  params = (mgga_k_pc07_params * ) (p->params);
*)


(* Equation (15) redefined with decaying exponentials to avoid inf/inf situations *)
pc07_fab0 := z -> exp(-params_a_pc07_a*params_a_pc07_b/z) * (1+exp(-params_a_pc07_a/(params_a_pc07_a-z)))^params_a_pc07_b/(exp(-params_a_pc07_a/z) + exp(-params_a_pc07_a/(params_a_pc07_a-z)))^params_a_pc07_b:
(* The function is ill-behaving at z=0 and z=a.
   However, it also goes to 0 and 1 very quickly near these points.
   pc07_fab0(params_a_pc07_a/40) is ~ 1.6e-17, which is smaller than machine epsilon.
*)
pc07_thr := 1/40:
pc07_zlo := pc07_thr*params_a_pc07_a:
pc07_zhi := (1-pc07_thr)*params_a_pc07_a:
pc07_fab := z -> my_piecewise5(z<=pc07_zlo, 0, z>=pc07_zhi, 1, pc07_fab0( m_min(pc07_zhi, m_max(pc07_zlo, z)) ) ):

(* Equation (7) *)
pc07_Delta := (x, u) ->
  8*mgga_q(u)^2/81 - mgga_p(x)*mgga_q(u)/9 + 8*mgga_p(x)^2/243:

pc07_f_W    := x -> 5*mgga_p(x)/3:

(* Equation (8) *)
pc07_GE4  := (x, u) ->
  1 + 5*mgga_p(x)/27 + 20*mgga_q(u)/9 + pc07_Delta(x, u):

(* Equation (11) *)
pc07_S     := (x, u) -> sqrt(1 + pc07_Delta(x, u)^2/(1 + pc07_f_W(x))^2):
pc07_GE4_M := (x, u) -> pc07_GE4(x, u)/pc07_S(x, u):

(* GE4 - f_W with the leading gradient term removed analytically:
   5*p/27 - 5*p/3 = -40*p/27, so the difference is a polynomial with no
   cancellation against f_W. *)
pc07_B := (x, u) -> 1 - 40*mgga_p(x)/27 + 20*mgga_q(u)/9:

(* Equation (17), split so that the part of the KED which exceeds the von
   Weizsaecker limit is available on its own.

   K_FACTOR_C*pc07_f_W(x) is identically x^2/8, the reduced tau_W that
   mgga_alpha subtracts back off.  A functional deorbitalized with this KED
   therefore has

     alpha = (K_FACTOR_C*pc07_f(x,u) - x^2/8)/K_FACTOR_C = pc07_alpha(x, u)

   exactly.  Exposing pc07_alpha lets such a functional take it directly,
   instead of assembling tau and subtracting tau_W from it again -- a
   cancellation that costs ~log10(tau/alpha) digits, growing without bound in
   the density tail where tau converges onto tau_W.  It also makes alpha >= 0
   by construction, since pc07_fab vanishes below its lower cutoff.

   Written directly, GE4_M - f_W is a difference of two large, nearly equal
   numbers: GE4_M approaches f_W from above as p grows, so the tail loses
   ~log10(f_W/z) digits.  Multiplying through by the conjugate GE4 + f_W*S
   moves the subtraction into

     GE4^2 - f_W^2*S^2 = Delta^2*(1 + 2*f_W)/(1 + f_W)^2
                       + 2*Delta*B + B^2 + 2*f_W*(Delta + B),   B = GE4 - f_W - Delta,

   where the leading Delta^2 terms have been combined analytically
   (1 - f_W^2/(1+f_W)^2 = (1 + 2*f_W)/(1 + f_W)^2) and nothing large is
   subtracted.  This holds full precision into the deep tail. *)
pc07_z := (x, u) ->
  ( pc07_Delta(x, u)^2*(1 + 2*pc07_f_W(x))/(1 + pc07_f_W(x))^2
    + 2*pc07_Delta(x, u)*pc07_B(x, u) + pc07_B(x, u)^2
    + 2*pc07_f_W(x)*(pc07_Delta(x, u) + pc07_B(x, u)) )
  / ( pc07_S(x, u)*(pc07_GE4(x, u) + pc07_f_W(x)*pc07_S(x, u)) ):

pc07_alpha := (x, u) -> pc07_z(x, u)*pc07_fab(pc07_z(x, u)):

pc07_f := (x, u) -> pc07_f_W(x) + pc07_alpha(x, u):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_kinetic(pc07_f, rs, z, xs0, xs1, u0, u1):
