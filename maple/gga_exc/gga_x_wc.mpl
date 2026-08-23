(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

wc_mu    := 0.2195149727645171:
wc_c     := (146/2025)*(4/9) - (73/405)*(2/3) + (wc_mu - MU_GE):
wc_kappa := KAPPA_PBE:

(* wc_f0_aux_m_kappa := wc_f0_aux - wc_kappa; wc_f0_aux is then
   wc_kappa + wc_f0_aux_m_kappa. With this primitive, wc_f0 =
   1 + wc_kappa*(1 - wc_kappa/wc_f0_aux) collapses to
   1 + wc_kappa*wc_f0_aux_m_kappa/wc_f0_aux, which is cancellation-
   free at small s where the direct form computes 1 - close-to-1. *)
wc_f0_aux_m_kappa := s -> MU_GE * s^2 + (wc_mu - MU_GE) * s^2 * exp(-s^2) + xc_log1p(wc_c * s^4):
wc_f0_aux         := s -> wc_kappa + wc_f0_aux_m_kappa(s):
wc_f0             := s -> 1 + wc_kappa*wc_f0_aux_m_kappa(s)/wc_f0_aux(s):
wc_f   := x -> wc_f0(gga_s(x)):

f := (rs, z, xt, xs0, xs1) -> gga_exchange(wc_f, rs, z, xs0, xs1):
