(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_k_pgslb_params *params;

  assert(p->params != NULL);
  params = (mgga_k_pgslb_params * )(p->params);
*)

# Equation (4) and (8)
(* p = mgga_p(xs) = s^2 is fed directly (mgga_kinetic_p) so the sigma
   derivatives are cancellation-free *)
pgslb_f0 := (s2, q) -> 5/3*s2 + exp(-params_a_pgslb_mu * s2) + params_a_pgslb_beta*q^2:
pgslb_f := (p, u) -> pgslb_f0(p, X2S^2*u):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_kinetic_p(pgslb_f, rs, z, xs0, xs1, u0, u1):

