(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)
(* prefix:
  lda_xc_th_fl_params *params;

  assert(p->params != NULL);
  params = (lda_xc_th_fl_params * )(p->params);
*)

params_a_n := 4:

params_a_a := [
    7/6,  8/6,  9/6, 10/6
]:

params_a_b := [0, 0, 0, 0]:
params_a_c := [0, 0, 0, 0]:
params_a_d := [0, 0, 0, 0]:

$include "th.mpl"

f := (rs, z) -> f_th(rs, z, 0, 0, 0):
