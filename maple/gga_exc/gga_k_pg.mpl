(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_k_pg_params *params;

  assert(p->params != NULL);
  params = (gga_k_pg_params * )(p->params);
*)

(* p = xs^2 is fed directly (gga_kinetic_p) so the sigma derivatives are
   cancellation-free; the physical squared reduced gradient is s^2 = X2S^2*p *)
pg_f0 := s2 -> 5/3*s2 + exp(-params_a_pg_mu * s2):
pg_f := p -> pg_f0(X2S^2*p):

f := (rs, z, xt, xs0, xs1) -> gga_kinetic_p(pg_f, rs, z, xs0, xs1):
