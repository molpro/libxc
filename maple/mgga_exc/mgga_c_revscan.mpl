(*
 Copyright (C) 2017 M.A.L. Marques
               2022 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* revSCAN f_alpha parameters: bake before $include "mgga_c_scan.mpl"
   so the scan helpers see these values, and $define the sentinel
   that suppresses mgga_c_scan's own bake of the SCAN defaults. *)
params_a_c1 := 1.131:
params_a_c2 := 1.7:
params_a_d  := 1.37:
$define _mgga_c_scan_f_alpha_baked

$include "mgga_c_scan.mpl"

(* Override the SCAN definitions of scan_e0_one_minus_g (eq 1) and
   scan_one_minus_g_infty (eq 2). revSCAN replaces each by a sum of
   two (1 + cX)^(-p) terms, so 1 - g splits into two (-1/2)*expm1
   contributions. *)
scan_e0_one_minus_g := (rs, z, t) ->
       -(1/2)*xc_expm1(-(1/4)*xc_log1p(8*A(rs, z, t)*t^2))
       -(1/2)*xc_expm1(-(1/8)*xc_log1p(80*A(rs, z, t)^2*t^4)):
scan_one_minus_g_infty := s ->
       -(1/2)*xc_expm1(-(1/4)*xc_log1p(8*scan_chi_infty*s^2))
       -(1/2)*xc_expm1(-(1/8)*xc_log1p(80*scan_chi_infty^2*s^4)):

(* the new correlation parameters *)
scan_b1c :=  0.030197:
scan_b2c :=  0.06623:
scan_b3c :=  0.16672:
