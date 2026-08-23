(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* SCAN f_alpha parameters. mgga_c_scan has no params struct, so these
   bakes must be in scope when the includes below are evaluated (Python
   is eager, unlike Maple). The $ifndef guard lets an includer such as
   mgga_c_revscan override these values: set its own first, then
   $define the sentinel before $include "mgga_c_scan.mpl". *)
$ifndef _mgga_c_scan_f_alpha_baked
$define _mgga_c_scan_f_alpha_baked
params_a_c1 := 0.64:
params_a_c2 := 1.5:
params_a_d  := 0.7:
$endif

$include "gga_c_scan_e0.mpl"
$include "mgga_x_scan.mpl"

scan_b1c := 0.0285764:
scan_b2c := 0.0889:
scan_b3c := 0.125541:
scan_eclda0 := rs -> -scan_b1c/(1 + scan_b2c*sqrt(rs) + scan_b3c*rs):

scan_chi_infty := 0.12802585262625815:
(* scan_g_infty = 1/(1 + 4*chi*s^2)^(1/4); appears in the paper only
   as `1 - scan_g_infty`, so we emit that form directly through
   expm1/log1p for cancellation-free evaluation at small 4*chi*s^2. *)
scan_one_minus_g_infty := s -> -xc_expm1(-(1/4)*xc_log1p(4*scan_chi_infty*s^2)):

(* in the paper it is 2.3631 *)
scan_G_cnst := 2.363:
scan_Gc := z -> (1 - scan_G_cnst*(2^(1/3) - 1)*f_zeta(z))*one_minus_z_pow_n(z, 12):

scan_H0 := (rs, s) ->
  scan_b1c*xc_log1p(xc_expm1(-scan_eclda0(rs)/scan_b1c)*scan_one_minus_g_infty(s)):
scan_e0 := (rs, z, s) ->
  (scan_eclda0(rs) + scan_H0(rs, s))*scan_Gc(z):

(* alpha is the shared mgga_alpha_total from util.mpl *)

(* parameters of f_alpha are baked above, before the $include's *)

(* As a function of the iso-orbital indicator, so that a deorbitalized variant
   can supply the alpha its kinetic energy functional yields directly; see
   mgga_c_scanl.mpl.  Named scan_c_f_a to avoid colliding with the exchange
   kernel's scan_f_a, which arrives with the $include above. *)
scan_c_f_a := (rs, z, xt, xs0, xs1, a) ->
  f_pbe(rs, z, xt, xs0, xs1) + scan_f_alpha(a)*(
    + scan_e0(rs, z, gga_s_total(xt))
    - f_pbe(rs, z, xt, xs0, xs1)
  ):

scan_f := (rs, z, xt, xs0, xs1, ts0, ts1) ->
  scan_c_f_a(rs, z, xt, xs0, xs1, mgga_alpha_total(z, xt, ts0, ts1)):

f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) ->
  scan_f(rs, z, xt, xs0, xs1, ts0, ts1):
