(*
 Copyright (C) 2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
$include "mgga_c_scan.mpl"

(* interpolation function, defined in main text *)
rregtm_gamma1 := 0.2:
rregtm_g := a -> (1 + rregtm_gamma1)*a / (rregtm_gamma1 + a):
rregtm_f2g := g -> 3*g^3 / (1 + g^3 + g^6):
rregtm_f2 := a -> rregtm_f2g(rregtm_g(a)):

(* equation 3: eps_c = eps_c^0 f_1(a) + eps_c^1 f_2(a) = eps_c^0 + f_2 (eps_c^1 - eps_c^0),
   with eps_c^0 = scan_e0 (the SCAN alpha=0 single-orbital branch; f_2(0)=0 -> eps_c^0)
   and eps_c^1 = f_pbe (PW92 + H1^PBE = PBE correlation; f_2(1)=1 -> eps_c^1).
   (mgga_c_scan reaches the same limits via scan_f_alpha running 1->0; rregtm_f2
   runs 0->1, so the branches sit the other way round.) *)
rregtm_f := (rs, z, xt, xs0, xs1, ts0, ts1) ->
  scan_e0(rs, z, gga_s_total(xt)) + rregtm_f2(mgga_alpha_total(z, xt, ts0, ts1))*(
    + f_pbe(rs, z, xt, xs0, xs1)
    - scan_e0(rs, z, gga_s_total(xt))
  ):

f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) ->
  rregtm_f(rs, z, xt, xs0, xs1, ts0, ts1):
