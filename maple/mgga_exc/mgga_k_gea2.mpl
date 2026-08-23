(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)


# p = s^2 is fed directly (mgga_kinetic_p) so the sigma derivatives are
# cancellation-free
gea2_f0 := (p, q) -> 1 + 5/27*p + 20/9*q:
gea2_f := (p, u) ->
  gea2_f0(p, mgga_q(u)):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_kinetic_p(gea2_f, rs, z, xs0, xs1, u0, u1):
