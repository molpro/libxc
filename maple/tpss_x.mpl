(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* Equation (7) from the paper *)

tpss_z := (x, t) -> x^2/(8*t):

tpss_qb    := (x, t) -> \
      9/20 * (mgga_alpha(x, t) - 1)/sqrt(1 + params_a_b*mgga_alpha(x, t)*(mgga_alpha(x, t) - 1)) \
      + 2*mgga_p(x)/3:

(* Equation (10) in all its glory *)
tpss_fxnum := (x, t) -> \
      + (MU_GE + params_a_c*tpss_z(x, t)^tpss_ff(tpss_z(x, t))/(1 + tpss_z(x, t)^2)^2)*mgga_p(x) \
      + 146/2025 * tpss_qb(x, t)^2 \
      - 73/405 * tpss_qb(x, t) * sqrt(1/2*(9/25*tpss_z(x, t)^2 + mgga_p(x)^2)) \
      + MU_GE^2/tpss_kappa(x, t) * mgga_p(x)^2 \
      + 2*sqrt(params_a_e)*MU_GE*9/25*tpss_z(x, t)^2 \
      + params_a_e*params_a_mu*mgga_p(x)^3:

tpss_fxden := x -> \
      (1 + sqrt(params_a_e)*mgga_p(x))^2:

tpss_fx    := (x, t) -> tpss_fxnum(x, t)/tpss_fxden(x):
