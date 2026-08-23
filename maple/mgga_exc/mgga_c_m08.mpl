(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_c_m08_params *params;

  assert(p->params != NULL);
  params = (mgga_c_m08_params * )(p->params);
*)


$define lda_c_pw_params
$define lda_c_pw_modified_params
$include "lda_c_pw.mpl"

$define gga_c_pbe_params
$include "gga_c_pbe.mpl"

(* the prefactor of t was chosen to get the right K_FACTOR_C in mgga_series_w *)
(* The second term's coefficient is f_pbe - f_pw, i.e. the PBE
   gradient correction.  Use f_pbe_grad (defined in gga_c_pbe.mpl)
   directly: forming f_pbe - f_pw here would catastrophically cancel
   when the gradient correction is small (f_pbe -> f_pw).  Routing
   through the gga_c_pbe.mpl helper keeps it single-source -- if the
   PBE composition changes, this follows automatically. *)
m08_f := (rs, z, xt, xs0, xs1, ts0, ts1) ->
  + mgga_series_w(params_a_m08_a, 12, 2^(2/3)*t_total(z, ts0, ts1))
    * f_pw(rs, z)
  + mgga_series_w(params_a_m08_b, 12, 2^(2/3)*t_total(z, ts0, ts1))
    * f_pbe_grad(rs, z, xt, xs0, xs1):

f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) ->
  m08_f(rs, z, xt, xs0, xs1, ts0, ts1):
