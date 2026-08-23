(*
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

tm_lambda := 0.6866:
tm_beta   := 79.873:

(* below Equation (6) *)
tm_p  := x -> (gga_s(x))^2:
tm_y  := x -> (2*tm_lambda - 1)^2 * tm_p(x):

(* Equation (7) *)
tm_f0 := x -> (1 + 10*(70*tm_y(x)/27) + tm_beta*tm_y(x)^2)^(1/10):

(* after Equation (9).  Algebraic identity (let c = tm_lambda^2 -
   tm_lambda + 1/2):
     1 - (t - 3c*(t - K - x^2/72))/K
       = 1 - t/K + 3c*t/K - 3c - 3c*x^2/(72 K)
       = (1 - 3c)*(1 - t/K) - 3c*x^2/(72 K)
       = (1 - 3c)*(K - t)/K - 3c*x^2/(72 K).
   At the uniform-gas limit t -> K the residual K - t is computed as
   a direct subtraction (exact by Sterbenz for t within a factor 2 of
   K), so (K - t)/K is relative-accurate -- unlike both the original
   1 - close-to-1 form and the intermediate 1 - t/K form, which round
   t/K to ~1 and lose the low bits of the small residual. *)
tm_R  := (x, t) -> (1 - 3*(tm_lambda^2 - tm_lambda + 1/2))*(K_FACTOR_C - t)/K_FACTOR_C \
   + 595*(2*tm_lambda - 1)^2 * tm_p(x)/54 \
   - 3*(tm_lambda^2 - tm_lambda + 1/2)*x^2/(72*K_FACTOR_C):

tm_fx_DME := (x, t) -> 1/tm_f0(x)^2 + 7*tm_R(x, t)/(9*tm_f0(x)^4):


(* after Equation (11) *)
tm_qtilde := (x, t) -> 9/20*(mgga_alpha(x, t) - 1) + 2*tm_p(x)/3:

(* Ratio tW/t; we have to make sure it's 1 at maximum *)
tm_tratio := (x, t) -> m_min(1.0, x^2/(8*t)):

tm_fx_SC := (x, t) -> (1 + 10*( \
       + (MU_GE + 50*tm_p(x)/729)*tm_p(x) + 146*tm_qtilde(x, t)^2/2025 \
       - 73*tm_qtilde(x,t)/405*(3/5*tm_tratio(x,t))*(1 - tm_tratio(x,t)))
       )^(1/10):

(* Equation 10 and below.
   KEEP IN SYNC: tm_w and tm_one_minus_w must stay paired.
   Algebraic identity (with r = tm_tratio):
     1 - r^2*(1+3r)/(1+r^3)^2
       = (1 + r^3)^2 - r^2*(1 + 3r)) / (1 + r^3)^2
       = (1 - r^2 - r^3 + r^6) / (1 + r^3)^2
       = (1 - r)*(1 + r - r^3 - r^4 - r^5) / (1 + r^3)^2.
   The factored form is cancellation-free at r -> 1 (iso-orbital limit),
   where tm_w in fact slightly overshoots 1 so the direct form
   1 - close-to-1 loses several digits in the small residual. *)
tm_w           := (x,t)-> (tm_tratio(x,t)^2 + 3*tm_tratio(x,t)^3)/(1 + tm_tratio(x,t)^3)^2:
tm_one_minus_w := (x,t)->
  (1 - tm_tratio(x,t))
  * (1 + tm_tratio(x,t) - tm_tratio(x,t)^3 - tm_tratio(x,t)^4 - tm_tratio(x,t)^5)
  / (1 + tm_tratio(x,t)^3)^2:

tm_f := (x, u, t) -> tm_w(x,t)*tm_fx_DME(x, t) + tm_one_minus_w(x,t)*tm_fx_SC(x, t):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) -> mgga_exchange(tm_f, rs, z, xs0, xs1, u0, u1, t0, t1):