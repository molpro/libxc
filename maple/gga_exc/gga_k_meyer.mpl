(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

(* eqn (5).  For |y| < 1, log((1+y)/(1-y)) = 2*atanh(y), so the
   outer (1 - y^2) factor pairs as (1+y)*(1-y)*atanh(y)/y -- routed
   through xc_atanh, which avoids the log-of-close-to-1 cancellation
   at small y.  In the |y| > 1 branch we keep the original log form
   (its argument is a moderate ratio there), but still write the
   coefficient as (1+y)*(1-y) so the cancellation at |y| -> 1+ is
   computed as a product of two cancellation-free factors instead of
   1 - y^2 -- which would itself cancel as 1 - close-to-1. *)
meyer_feta := y -> 1/2*(1 + (1 + y)*(1 - y)*my_piecewise3(m_abs(y) < 1,
  xc_atanh(y)/y,
  log((1 + y)/m_abs(1 - y))/(2*y))):

(* eqn (7) *)
meyer_lambda := y -> (1 - meyer_feta(y)) / (3 * y^2 * meyer_feta(y)):

(* enhancement factor from eqn (1) *)
meyer_f := x -> 1 + meyer_lambda(gga_s(x)/6)*x^2/(8*K_FACTOR_C):

f := (rs, zeta, xt, xs0, xs1) -> gga_kinetic(meyer_f, rs, zeta, xs0, xs1):
