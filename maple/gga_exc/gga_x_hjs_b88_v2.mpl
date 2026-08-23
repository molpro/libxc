(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_x_hjs_params *params;

  assert(p->params != NULL);
  params = (gga_x_hjs_params * )(p->params);
*)

$include "gga_x_hjs.mpl"

hjs2_xi := 1/(exp(20) - 1):
(* (exp(-s) + xi)/(1 + xi) = 1 + expm1(-s)/(1 + xi); at small s this
   would otherwise cancel down to -s/(1+xi). Routed through log1p so
   the small-argument behaviour is exact. *)
hjs2_fs := s -> -xc_log1p(xc_expm1(-s)/(1 + hjs2_xi)):

hjs_fx := (rs, z, x) -> hjs_f1(rs, z, hjs2_fs(gga_s(x))):
