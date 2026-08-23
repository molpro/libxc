(*
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_x_eel_params *params;

  assert(p->params != NULL);
  params = (mgga_x_eel_params * )(p->params);
*)

$include "mgga_x_scan.mpl"

(* Equation 14. The original form was
     scan_h0x*(1 - piecewise(x > x0, exp(-c*(x-x0)^(-1/4)), 0))
   which cancels 1 - close-to-1 at large x where (x-x0)^(-1/4) -> 0.
   Routed through expm1 in the right branch and the constant 1 in the
   left branch -- same value, no cancellation. *)
eel_G := x -> scan_h0x*my_piecewise3(x>params_a_x0, -xc_expm1(-params_a_c*(m_max(x-params_a_x0,0))^(-1/4)), 1):

(* Equation 22 *)
eel_k := a0 -> (1-scan_h0x)/( eel_G(3*a0*tanh(1/a0)/5) - scan_h0x):

(* Equation 19 *)
eel_atilde := a -> params_a_a0 * tanh(a / params_a_a0):

(* Equation 20 *)
eel_Fx := (s,a) -> eel_k(params_a_a0)*(eel_G(s^2 + 3*eel_atilde(a)/5) - eel_G(s^2)) + eel_G(s^2):

(* Conversion to libxc parameters *)
eel_f   := (x, u, t) -> eel_Fx(gga_s(x), mgga_alpha(x,t)):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) -> mgga_exchange(eel_f, rs, z, xs0, xs1, u0, u1, t0, t1):
