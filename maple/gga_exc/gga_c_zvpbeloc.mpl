(*
 Copyright (C) 2017 M.A.L. Marques
               2025 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

$include "gga_c_zvpbeint.mpl"
$include "gga_c_pbeloc.mpl"

params_a_alpha := 0.5:
params_a_omega := 2:

(* text below equation 8 *)
zvpbeloc_kv := (rs) ->
  2*(3/(4*Pi^4))^(1/18) * n_total(rs)^(1/9):
(* redefine nu of zbpbeint, text below equation 8. nu = |nabla n| / (2 kv rho); x = |nabla n| / rho^(4/3) *)
zvpbeint_nu := (rs, z, xt) ->
  xt * n_total(rs)^(1/3) / (2 * zvpbeloc_kv(rs)):

(* Note that f_pbe here is, in fact, pbeloc *)
f  := (rs, z, xt, xs0, xs1) ->
  zvpbeint_ff(rs, z, xt) * f_pbe(rs, z, xt, xs0, xs1):
