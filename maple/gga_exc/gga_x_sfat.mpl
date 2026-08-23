(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

$include "gga_x_ityh.mpl"

(* Override both halves of the ityh_attenuation pair so they stay
   matched (see KEEP IN SYNC note in gga_x_ityh.mpl).  Replacing only
   ityh_attenuation would leave ityh_one_minus_attenuation pointing
   at the erf primitive, which is wrong here. *)
ityh_attenuation           := a -> attenuation_yukawa(a):
ityh_one_minus_attenuation := a -> one_minus_attenuation_yukawa(a):

