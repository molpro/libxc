(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* These numbers are taken from the original reference, but divided by
     two to convert from Rydbergs to Hartrees *)

A_vwn  := [ 0.0310907, 0.01554535, -1/(6*Pi^2)]:
b_vwn  := [ 3.72744,   7.06042,    1.13107  ]:
c_vwn  := [12.9352,   18.0578,    13.0045   ]:
x0_vwn := [-0.10498,  -0.32500,   -0.0047584]:

A_rpa  := [ 0.0310907,  0.01554535,  -1/(6*Pi^2)]:
b_rpa  := [13.0720,    20.1231,      1.06835  ]:
c_rpa  := [42.7198,   101.578,      11.4813   ]:
x0_rpa := [-0.409286,  -0.743294,   -0.228344 ]:

Q_vwn  := (b, c)     -> sqrt(4*c - b^2):
f1_vwn := (b, c)     -> 2*b/Q_vwn(b, c):
f2_vwn := (b, c, x0) -> b*x0/(x0^2 + b*x0 + c):
f3_vwn := (b, c, x0) -> 2*(2*x0 + b)/Q_vwn(b, c):

fpp_vwn := 4/(9*(2^(1/3) - 1)):

fx_vwn := (b, c, rs) -> rs + b*sqrt(rs) + c:

(* At large rs, fx_vwn(b, c, rs) ~ rs, so rs/fx_vwn -> 1 and
   (sqrt(rs) - x0)^2/fx_vwn -> 1: log of close-to-1.  Both are
   routed through xc_log1p of (num - den)/den.  The numerator
   subtractions are written symbolically against fx_vwn so the
   formula stays single-source -- Maple simplifies the leading `rs`
   away before codegen (e.g. rs - fx_vwn(b, c, rs) collapses to
   -b*sqrt(rs) - c), so the emitted C is still cancellation-free
   and any future retuning of fx_vwn flows through automatically. *)
f_aux := (A, b, c, x0, rs) -> A*(
  + xc_log1p((rs - fx_vwn(b, c, rs))/fx_vwn(b, c, rs))
  + (f1_vwn(b, c) - f2_vwn(b, c, x0)*f3_vwn(b, c, x0))*arctan(Q_vwn(b, c)/(2*sqrt(rs) + b))
  - f2_vwn(b, c, x0)*xc_log1p(((sqrt(rs) - x0)^2 - fx_vwn(b, c, rs))/fx_vwn(b, c, rs))
):

DMC  := (rs, z) ->
    + f_aux(A_vwn[2], b_vwn[2], c_vwn[2], x0_vwn[2], rs)
    - f_aux(A_vwn[1], b_vwn[1], c_vwn[1], x0_vwn[1], rs):

DRPA := (rs, z) ->
    + f_aux(A_rpa[2], b_rpa[2], c_rpa[2], x0_rpa[2], rs)
    - f_aux(A_rpa[1], b_rpa[1], c_rpa[1], x0_rpa[1], rs):