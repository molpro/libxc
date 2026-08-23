(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_k_dk_params *params;

  assert(p->params != NULL);
  params = (gga_k_dk_params * )(p->params);
*)

(* The enhancement is even in the reduced gradient x (only x^(2*(i-1))
   terms), so it is a rational function of p = x^2.  Feeding p directly
   through gga_kinetic_p (which passes xs^2) makes the sigma derivatives
   cancellation-free -- the x = sqrt(sigma)/rho^(4/3) route otherwise loses
   all precision in the deep-tail second derivative. *)
dk_f := p ->
  add(params_a_aa[i]*p^(i-1), i=1..5) /
  add(params_a_bb[i]*p^(i-1), i=1..5):

f := (rs, zeta, xt, xs0, xs1) -> gga_kinetic_p(dk_f, rs, zeta, xs0, xs1):
