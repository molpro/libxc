(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_c_ccdf_params *params;

  assert(p->params != NULL);
  params = (gga_c_ccdf_params * )(p->params);
*)

(* Equation (26). The sigmoid factor `1 - c3/(1 + exp(-c4*(...)))`
   is rewritten in algebraically-equivalent form
     ((1 - c3) + exp(-c4*(...))) / (1 + exp(-c4*(...)))
   so the `1 - close-to-1` cancellation when c3 is close to 1 and the
   exponent argument is large/negative is gone. *)
f_ccdf  := (rs, z, xt, xs0, xs1) ->
  params_a_c1 / (1 + params_a_c2*n_total(rs)^(-1/3)) * ((1 - params_a_c3) + exp(-params_a_c4*(gga_s_total(xt) - params_a_c5)))/(1 + exp(-params_a_c4*(gga_s_total(xt) - params_a_c5))):

f  := (rs, z, xt, xs0, xs1) -> f_ccdf(rs, z, xt, xs0, xs1):
