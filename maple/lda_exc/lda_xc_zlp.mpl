(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)

a0 := 0.93222*RS_FACTOR:
kk := 9.47362e-3*RS_FACTOR:

(* 1 - kk*log1p(rs/kk)/rs = kk*(rs/kk - log1p(rs/kk))/rs
                          = kk*xc_x_minus_log1p(rs/kk)/rs,
   cancellation-free at small rs (where the bracket -> 0 as
   close-to-1 - 1).  At the typical density regime rs/kk is large
   (kk ~ 6e-3, rs >~ 0.1), but the rewrite is cleaner regardless. *)
f := (rs, zeta) -> -a0*kk*xc_x_minus_log1p(rs/kk)/rs^2:
