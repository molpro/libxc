(*
 Copyright (C) 2022 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_c_ccalda_params *params;

  assert(p->params != NULL);
  params = (mgga_c_ccalda_params * ) (p->params);
*)

$include "mgga_c_cc.mpl"

(* equation 7; note that CCaLDA uses non-spin-polarized quantities
unlike many other meta-GGAs.  Takes the SQUARED reduced gradient xt2 = xt^2
so the opaque boundary is rational in sigma (see mgga_c_cc.mpl). *)
ccalda_alpha := (z, xt2, ts0, ts1) ->
  (t_total(z, ts0, ts1) - xt2/8) / K_FACTOR_C * 2^(2/3):

(* equation 10. KEEP IN SYNC: ccalda_f_alpha and
   ccalda_one_minus_f_alpha are paired -- algebraic identity
     1 - (1+c)*a/(1+c*a) = (1 - a)/(1 + c*a).
   At alpha -> 1 the direct 1 - close-to-1 form cancels, so the
   one_minus sibling routes through (1-a)/(1+c*a) instead. *)
ccalda_f_alpha           := a -> (1 + params_a_c) * a / (1 + params_a_c * a):
ccalda_one_minus_f_alpha := a -> (1 - a) / (1 + params_a_c * a):

(* functional is defined by equation 9 *)
f_ccalda := (rs, z, xt, ts0, ts1) ->
  + ccalda_f_alpha          (ccalda_alpha(z, xt^2, ts0, ts1))*f_cc(rs, z, xt, ts0, ts1)
  + ccalda_one_minus_f_alpha(ccalda_alpha(z, xt^2, ts0, ts1))*f_pw(rs, z):

f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) ->
  f_ccalda(rs, z, xt, ts0, ts1):
