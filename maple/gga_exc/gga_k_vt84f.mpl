(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_k_vt84f_params *params;

  assert(p->params != NULL);
  params = (gga_k_vt84f_params * ) (p->params);
*)

(* Equation (5) *)
vt84f_f0_orig := s -> 1 - params_a_mu*s^2*exp(-params_a_alpha*s^2)/(1+params_a_mu*s^2) + (-xc_expm1(-params_a_alpha*s^4)) * (s^(-2) - 1) + 5*s^2/3:
(* The 1/s^2 factor would give 0*infinity at s = 0, so the Taylor
   branch handles that limit; the rest of the function is well-
   behaved.  Even-only series, so order 7 (degree-6 polynomial,
   3 nonzero coefficients) drops the 4th derivative truncation to
     8*7*6*5 * c_8 * sqrt(eps)^4 ~ O(1680) * eps^2 ~ 8e-29 below
   XC_EPSILON * |actual 4th derivative ~ O(1)|. *)
(* series() (not taylor) through to_elementary: the s^(-2) factor is a
   removable singularity that taylor() refuses, and the expression
   carries the inert xc_expm1 wrapper -- to_elementary makes it native
   so series() can expand it. *)
vt84f_f0_series := s -> eval(convert(series(to_elementary(vt84f_f0_orig(st)), st = 0, 7), polynom), st=s):
(* Glue the functions together *)
vt84f_f0 := s-> my_piecewise3(s <= sqrt(XC_EPSILON), vt84f_f0_series(s), vt84f_f0_orig(m_max(s, sqrt(XC_EPSILON)))):

(* Convert from x to s *)
vt84f_f := x -> vt84f_f0(gga_s(x)):

f := (rs, z, xt, xs0, xs1) ->
  gga_kinetic(vt84f_f, rs, z, xs0, xs1):
