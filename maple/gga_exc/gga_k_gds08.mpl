(*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_k_gds08_params *params;

  assert(p->params != NULL);
  params = (gga_k_gds08_params * )(p->params);
*)

(* TF-lambda-vW base enhancement (as in gga_k_tflw), fed the squared reduced
   gradient (gga_kinetic_p) so the sigma derivatives are cancellation-free. *)
gds08_base := p -> params_a_gamma + (params_a_lambda/8)*p/K_FACTOR_C:

(* Ghiringhelli-Delle Site LDA correction.  This was previously a separate
   auxiliary functional (lda_k_gds08_worker) combined at runtime through
   xc_mix_init; it is a partial term with no standalone meaning, so it is
   folded in here and the auxiliary functional retired. *)
gds08_ws := (rs, z) -> (1 + z)/2 * (
  + params_a_A
  + params_a_B*log(2*n_spin(rs, z))
  + params_a_C*log(2*n_spin(rs, z))^2
):
gds08_worker := (rs, z) ->
  + my_piecewise3(screen_dens(rs,  z), 0, gds08_ws(rs, z_thr( z)))
  + my_piecewise3(screen_dens(rs, -z), 0, gds08_ws(rs, z_thr(-z))):

f := (rs, z, xt, xs0, xs1) ->
  gga_kinetic_p(gds08_base, rs, z, xs0, xs1) + gds08_worker(rs, z):
