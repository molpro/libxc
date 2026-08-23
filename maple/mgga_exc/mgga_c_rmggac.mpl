(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

$include "mgga_c_scan.mpl"

(* Override definition of beta *)
mbeta := (rs, t) -> 0.066725:

rmggac_gamma1 := 0.08:
rmggac_gamma2 := 0.3:
rmggac_g := (alpha, s) ->
  (1 + rmggac_gamma1)*alpha/(rmggac_gamma1 + alpha + rmggac_gamma2*s^2):

(* Algebraic identity:
     1 - 3 g^3/(1 + g^3 + g^6)
       = (1 + g^3 + g^6 - 3 g^3)/(1 + g^3 + g^6)
       = (1 - g^3)^2/(1 + g^3 + g^6),
   which is cancellation-free at g = 1 where f2 -> 1 and the direct
   1 - close-to-1 form loses precision. *)
rmggac_f2 := (alpha, s) ->
  3*rmggac_g(alpha, s)^3/(1 + rmggac_g(alpha, s)^3 + rmggac_g(alpha, s)^6):
rmggac_f1 := (alpha, s) ->
  (1 - rmggac_g(alpha, s)^3)^2/(1 + rmggac_g(alpha, s)^3 + rmggac_g(alpha, s)^6):

rmggac_gamma := 0.031091:
(* from mmga_c_r2scan *)
rmggac_w1 := (rs, z) -> xc_expm1(-f_pw(rs, z)/(rmggac_gamma*mphi(z)^3)):
rmggac_H1 := (rs, z, t) -> rmggac_gamma*mphi(z)^3*xc_log1p(rmggac_w1(rs, z) * scan_e0_one_minus_g(rs, z, t)):

rmggac_eps1 := (rs, z, t) ->
  (f_pw(rs, z) +  rmggac_H1(rs, z, t)):

rmggac_alpha := (z, xt, ts0, ts1) ->
  (t_total(z, ts0, ts1) - xt^2/4)/(2**(1/3)*K_FACTOR_C):

rmggac_f := (rs, z, xt, xs0, xs1, ts0, ts1) ->
  + scan_e0(rs, z, gga_s_total(xt))
      * rmggac_f1(rmggac_alpha(z, xt, ts0, ts1), gga_s_total(xt))
  + rmggac_eps1(rs, z, tp(rs, z, xt))
      * rmggac_f2(rmggac_alpha(z, xt, ts0, ts1), gga_s_total(xt)):

(* the functional is written for the other convention for tau *)
f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) ->
  rmggac_f(rs, z, xt, xs0, xs1, 2*ts0, 2*ts1):
