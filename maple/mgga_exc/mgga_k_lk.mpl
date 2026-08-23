(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_k_lk_params *params;

  assert(p->params != NULL);
  params = (mgga_k_lk_params * ) (p->params);
*)


(* Equation (10) *)
lk_delta := (p, q) -> 8/81*q^2 - 1/9*p*q + 8/243*p^2:
(* Equation (15). Algebraic identity:
     1 - 1/(1 + a) = a/(1 + a)
   so 2 - 1/(1+a) - 1/(1+b) = a/(1+a) + b/(1+b), which is
   cancellation-free at small x1, x2 (where the original form
   subtracts two close-to-1 quantities from 2). *)
lk_f0 := (x1, x2) -> 1 + params_a_kappa*(
     x1/(params_a_kappa + x1) + x2/(params_a_kappa + x2)):
(* Equation (16) *)
lk_x1 := (p, q) -> 5/27*p + lk_delta(p,q) + (5/27*p)^2/params_a_kappa:
(* Equation (17) *)
lk_x2 := (p, q) -> 2*(5/27*p)*lk_delta(p,q)/params_a_kappa + (5/27*p)^3/params_a_kappa^2:

(* Full functional.  p = s^2 is fed directly (mgga_kinetic_p) so the sigma
   derivatives are cancellation-free. *)
lk_f := (p, u) ->
  lk_f0(lk_x1(p, mgga_q(u)), lk_x2(p, mgga_q(u))):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_kinetic_p(lk_f, rs, z, xs0, xs1, u0, u1):
