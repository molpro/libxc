(*
 Copyright (C) 2025 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

$include "mgga_x_mscan.mpl"
$include "mgga_c_scan.mpl"

mscan_f := (rs, z, xt, xs0, xs1, ts0, ts1) ->
  f_pbe(rs, z, xt, xs0, xs1) + scan_f_alpha(mscan_alpha(rs, z, xt^2, xs0^2, xs1^2, ts0, ts1))*(
    + scan_e0(rs, z, gga_s_total(xt))
    - f_pbe(rs, z, xt, xs0, xs1)
  ):

f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) ->
  mscan_f(rs, z, xt, xs0, xs1, ts0, ts1):
