(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* This is the definition in the paper. The enhancement is LINEAR in the
   reduced gradient squared x^2, so feeding p = s^2 = X2S^2*x^2 through
   mgga_exchange_p (x^2 = p/X2S^2) makes every sigma derivative
   cancellation-free -- in particular d^2/dsigma^2 is identically zero,
   where the x = sqrt(sigma) route otherwise produced ~1e6 of pure
   deep-tail roundoff. *)
th_f0 := (p, u, t) -> -27*Pi/(10*t) * (1 + 7*(p/X2S^2)/(108*t)):

(* Since we write this as an enhancement functional, we need to divide
   out the LDA prefactor. The paper also defines tau without one half *)
th_f := (p, u, t) -> -th_f0(p,u,2*t) / X_FACTOR_C:

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_exchange_p(th_f, rs, z, xs0, xs1, u0, u1, t0, t1):
