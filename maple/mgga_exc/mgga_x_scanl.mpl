(*
 Copyright (C) 2019 Daniel Mejia-Rodriguez
               2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_x_scanl_params *params;

  assert(p->params != NULL);
  params = (mgga_x_scanl_params * )(p->params);
*)

$include "mgga_x_scan.mpl"
$include "mgga_k_pc07.mpl"

(* Deorbitalization: the orbital kinetic energy density is replaced by a
   kinetic-energy functional evaluated on the same spin channel,
   tau_s = rho_s * ked(rho_s, sigma_ss, lapl_s).  SCAN depends on tau only
   through the iso-orbital indicator alpha = (tau - tau_W)/tau_unif, and PC07
   yields that indicator directly as pc07_alpha: its von Weizsaecker term is
   identically the tau_W that alpha subtracts (K_FACTOR_C*pc07_f_W(x) = x^2/8),
   so the two cancel analytically.

   Feeding pc07_alpha to scan_f_a therefore evaluates alpha as a product rather
   than as a difference of two large, nearly equal numbers.  The runtime
   composition instead assembles tau = rho*ked and lets work_mgga subtract tau_W
   from it, which loses ~log10(tau/alpha) digits -- growing without bound in the
   density tail, where tau converges onto tau_W.  The orbital tau never appears,
   so the t argument is unused. *)
scanl_f := (x, u, t) -> scan_f_a(x, mgga_alpha_deorb(pc07_alpha(x, u))):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_exchange(scanl_f, rs, z, xs0, xs1, u0, u1, t0, t1):
