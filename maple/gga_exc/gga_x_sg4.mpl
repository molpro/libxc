(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

sg4_mu1     := 0.042:
sg4_mu2     := 0.26 - sg4_mu1:
sg4_nu_MGE4 := -0.195:
sg4_k2      := -sg4_mu2^2/sg4_nu_MGE4:
sg4_k1      := 0.804 - sg4_k2:

(* Algebraic identities (with A = mu1*s^2/k1):
     (1 - A)/(1 - A^5) = 1/(1 + A + A^2 + A^3 + A^4)     [cyclotomic]
   then
     k1 + k2 - k1/(1+A+...+A^4) - k2/(1 + mu2*s^2/k2)
       = k1*(A + A^2 + A^3 + A^4)/(1+A+A^2+A^3+A^4)
         + mu2*s^2/(1 + mu2*s^2/k2)
       = mu1*s^2*(1 + A + A^2 + A^3)/(1 + A + A^2 + A^3 + A^4)
         + mu2*s^2/(1 + mu2*s^2/k2).
   Both pieces are O(s^2) at small s, so the rewrite removes the
   1 + k1 + k2 - close-to-(k1+k2) cancellation of the direct form. *)
sg4_A  := s -> sg4_mu1*s^2/sg4_k1:
sg4_f0 := s -> 1
   + sg4_mu1*s^2*(1 + sg4_A(s) + sg4_A(s)^2 + sg4_A(s)^3)
              / (1 + sg4_A(s) + sg4_A(s)^2 + sg4_A(s)^3 + sg4_A(s)^4)
   + sg4_mu2*s^2/(1 + sg4_mu2*s^2/sg4_k2):
sg4_f:= x -> sg4_f0(gga_s(x)):

f := (rs, zeta, xt, xs0, xs1) -> gga_exchange(sg4_f, rs, zeta, xs0, xs1):
