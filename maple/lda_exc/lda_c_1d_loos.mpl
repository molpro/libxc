(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)

$define xc_dimensions_1d

eta0 := -log(sqrt(2*Pi)) + 3/4:
eta1 := 0.359933:
eps0 := -Pi^2/360:
eps1 := 0.00845:

kappa := 0.414254:

c0 := kappa*eta0:
c1 := 4*kappa*eta0 + kappa*sqrt(kappa)*eta1:
c2 := 5*eps0 + eps1/kappa:
c3 := eps1:

(* (sqrt(1 + X) - 1)/X = 1/(sqrt(1 + X) + 1) via conjugate
   multiplication; cancellation-free at small X (where the original
   would lose precision computing sqrt(close-to-1) - 1). *)
t := rs -> 2/(sqrt(1 + 4*kappa*rs) + 1):

f := (rs, z) ->
  t(rs)^2*(c0*(1 - t(rs))^3 + c1*t(rs)*(1 - t(rs))^2 + c2*t(rs)^2*(1 - t(rs)) + c3*t(rs)^3):
