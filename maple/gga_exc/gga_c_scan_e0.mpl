(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

$define gga_c_pbe_params
$include "gga_c_regtpss.mpl"

(* scan_e0_g = (1 + 4*A*t^2)^(-1/4); appears in the paper only as
   `1 - scan_e0_g`, so we go straight to that form via expm1/log1p
   for cancellation-free evaluation at small 4*A*t^2. *)
scan_e0_one_minus_g := (rs, z, t) -> -xc_expm1(-(1/4)*xc_log1p(4*A(rs, z, t)*t^2)):
f2 := (rs, z, t) -> mbeta(rs, t)*scan_e0_one_minus_g(rs, z, t)/(mgamma*A(rs, z, t)):
