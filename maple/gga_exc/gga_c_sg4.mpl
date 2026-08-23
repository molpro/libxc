(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

params_a_tscale := 1:
params_a_beta  := 0:
params_a_alpha := 0.8:
$include "gga_c_zpbeint.mpl"

(* parameters for beta of SG4, b0 = 3 mu^MGE2/pi^2, mu^MGE2 = 0.26
   The first author (L. Constantin) suggested to use mu^MGE2 = 0.260
   in both exchange and correlation *)
sg4_b0    := 3*0.26/Pi^2:
sg4_sigma := 0.07:

(* we redefine beta here *)
mbeta := (rs, t) -> sg4_b0 + sg4_sigma*t*(-xc_expm1(-rs^2)):
