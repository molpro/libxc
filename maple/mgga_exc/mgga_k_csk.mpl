(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_k_csk_params *params;

  assert(p->params != NULL);
  params = (mgga_k_csk_params * )(p->params);
*)


(* Equation (21) *)
csk_z  := (p, q) -> 20/9*q - 40/27*p:

(* Equation (22) *)
csk_f0 := (p, q, z) ->  1 + 5*p/3 + csk_zI(z):

(*
   I(z) contains exp(-1/|z|^a), numerically challenging for small |z|; we
   truncate near z=0 (I -> 1) and for large -z (I -> 0, the step function).
   What enters the energy is the PRODUCT z*I(z).  In the exp branch I(z) ~
   1/|z| is tiny, so forming z*(tiny) destroys all accuracy in the 2nd
   derivative at large |z| (the near-empty channel).  We instead evaluate the
   product directly in the algebraically-identical, cancellation-free form
      z*I(z) = -(-expm1(-u)*|z|^a)^(1/a),   u = 1/|z|^a,
   whose base -expm1(-u)/u -> 1 as |z| -> infinity, so no small-times-large
   cancellation occurs.
*)
csk_zI_negz := z ->
  -(-xc_expm1(-1/m_abs(z)^params_a_csk_a) * m_abs(z)^params_a_csk_a)^(1/params_a_csk_a):
csk_I_cutoff_small := (-log(XC_EPSILON))^(-1/params_a_csk_a):
csk_I_cutoff_large := (-log(1 - XC_EPSILON))^(-1/params_a_csk_a):

csk_zI := z -> my_piecewise5(
      z < -csk_I_cutoff_large, 0,
      z > -csk_I_cutoff_small, z,
      csk_zI_negz(m_max(m_min(z, -csk_I_cutoff_small), -csk_I_cutoff_large))
  ):

(* p = mgga_p(xs) = s^2 is fed directly (mgga_kinetic_p) so the sigma
   derivatives are cancellation-free *)
csk_f := (p, u) ->
  csk_f0(p, mgga_q(u), csk_z(p, mgga_q(u))):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_kinetic_p(csk_f, rs, z, xs0, xs1, u0, u1):
