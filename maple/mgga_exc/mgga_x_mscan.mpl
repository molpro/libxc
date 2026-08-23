(*
 Copyright (C) 2025 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* mscan depends on the total reduced gradient xt, so it does not obey
   exact spin scaling; keep it off the spin-density evaluation path. *)
(* spin_scaled: false *)

(* prefix:
  mgga_x_mscan_params *params;

  assert(p->params != NULL);
  params = (mgga_x_mscan_params * )(p->params);
*)

$include "mgga_x_scan.mpl"

(* compute sigma1 from the SQUARED reduced gradients xt2, xs02, xs12.
   mscan_sigma1/mscan_alpha are opaque helpers, so taking the squares keeps
   them rational in sigma: the alpha recomputation (the bulk of mscan's
   size) no longer chains its high-order derivatives through sqrt(sigma).
   The genuine sqrt(xt) survives only in scan_gx below, as in base SCAN. *)
mscan_sigma1 := proc(rs, z, xt2, xs02, xs12)
  local sigma0, sigma1, sigma2:
  (* xs02 = sigma0/na^(8/3) *)
  sigma0 := xs02*n_spin(rs,z)^(8/3):
  (* xs12 = sigma2/nb^(8/3) *)
  sigma2 := xs12*n_spin(rs,-z)^(8/3):
  (* xt2 = (sigma0 + 2*sigma1 + sigma2)/(na+nb)^(8/3) *)
  sigma1 := (n_total(rs)^(8/3)*xt2 - sigma0 - sigma2)/2:
  return sigma1:
end proc:

(* Redefine scaled gradient; since this is now the total density the factor is different *)
scan_gx := x -> -xc_expm1(-scan_a1/sqrt(XT2S*x)):
(* modified SCAN alpha, eq 15 *)
mscan_alpha := (rs, z, xt2, xs02, xs12, t0, t1) -> (n_spin(rs,z)^(8/3)*t0 + n_spin(rs,-z)^(8/3)*t1 - mscan_sigma1(rs, z, xt2, xs02, xs12)/4) / (K_FACTOR_C * (n_spin(rs,z)^(8/3) + n_spin(rs,-z)^(8/3))):

mscan_f   := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) -> (scan_h1x(scan_y(xt, mscan_alpha(rs, z, xt^2, xs0^2, xs1^2, t0, t1)))*(1 - scan_f_alpha(mscan_alpha(rs, z, xt^2, xs0^2, xs1^2, t0, t1)))
  + scan_h0x*scan_f_alpha(mscan_alpha(rs, z, xt^2, xs0^2, xs1^2, t0, t1)))*scan_gx(xt):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) -> mscan_f(rs, z_thr( z), xt, xs0, xs1, u0, u1, t0, t1)*(my_piecewise3(screen_dens(rs, z), 0, lda_x_spin(rs, z_thr(z))) + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, z_thr(-z)))):

