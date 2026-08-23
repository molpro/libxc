(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* One should be able to simplify this by evaluating explicitly the Stoll
   decomposition of the exchange functional *)

$define lda_c_pw_params
$define lda_c_pw_modified_params
$include "lda_c_pw.mpl"

(* the bounded gradient variable is the shared b97_u (util.mpl);
   the ss/os wrappers exist so they can be redefined (e.g. GAS22) *)
b97mv_ux_ss := (mgamma, x) -> b97_u(mgamma, x^2):
b97mv_ux_os := (mgamma, x) -> b97_u(mgamma, x^2):

(* article uses t = 2 tau convention.
   wx_os is bounded in [-1, 1], but the naive rational form
     (K*(ts0+ts1) - 2*ts0*ts1)/(K*(ts0+ts1) + 2*ts0*ts1)
   has a numerator and denominator that both scale as ts0*ts1.  When this
   factor is raised to a high power (par_os uses power 6) the code
   generator distributes the exponent over the quotient, computing
   numerator^6 / denominator^6 separately; for a large reduced tau
   (ts ~ 1e26, e.g. a tiny density with a huge kinetic energy density)
   ts0*ts1 ~ 1e52 and (1e52)^6 overflows the double range, giving
   inf/inf = NaN even though the factor itself is ~ (-1)^6 = 1.

   Rewrite it in terms of the per-spin bounded quantities
     p_i = ts_i/(K + ts_i)   in [0, 1),
     w_i = (K - ts_i)/(K + ts_i) in (-1, 1],
   so that
     wx_os = (p0*w1 + p1*w0)/(p0 + p1)
   with numerator in [-2, 2] and denominator in [0, 2).  The value is
   algebraically identical, but now the base of the power is O(1) and
   cannot overflow even when the exponent is distributed.  This form is
   also free of the ts0 = ts1 = K cancellation of the original. *)
b97mv_p  := t -> t/(K_FACTOR_C + t):
b97mv_ww := t -> (K_FACTOR_C - t)/(K_FACTOR_C + t):
b97mv_wx_ss := (t, dummy) -> b97mv_ww(t):
b97mv_wx_os := (ts0, ts1) ->
  (b97mv_p(ts0)*b97mv_ww(ts1) + b97mv_p(ts1)*b97mv_ww(ts0))
  /(b97mv_p(ts0) + b97mv_p(ts1)):

(* this is the generic Taylor expansion in wx and ux *)
b97mv_g := (mgamma, wx, ux, cc, n, xs, ts0, ts1) ->
  add(cc[i][1]*wx(ts0, ts1)^cc[i][2]*ux(mgamma, xs)^cc[i][3], i=1..n):

(* parallel contribution to correlation *)
b97mv_fpar  := (rs, z, xs0, xs1, ts0, ts1) ->
  + lda_stoll_par(f_pw, rs,  z) * b97mv_g(b97mv_gamma_ss, b97mv_wx_ss, b97mv_ux_ss, b97mv_par_ss, b97mv_par_n, xs0, ts0, 0)
  + lda_stoll_par(f_pw, rs, -z) * b97mv_g(b97mv_gamma_ss, b97mv_wx_ss, b97mv_ux_ss, b97mv_par_ss, b97mv_par_n, xs1, ts1, 0):

(* anti-parallel contribution *)
b97mv_fos := (rs, z, xs0, xs1, ts0, ts1) ->
  lda_stoll_perp(f_pw, rs, z)
  * b97mv_g(b97mv_gamma_os, b97mv_wx_os, b97mv_ux_os, b97mv_par_os, b97mv_par_n, sqrt(xs0^2 + xs1^2)/sqrt(2), ts0, ts1):

(* the functional is the sum of parallel and anti-parallel contributions *)
b97mv_f :=  (rs, z, xs0, xs1, ts0, ts1) ->
  + b97mv_fpar(rs, z, xs0, xs1, ts0, ts1)
  + b97mv_fos(rs, z, xs0, xs1, ts0, ts1):
