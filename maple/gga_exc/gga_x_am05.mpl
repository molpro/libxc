(*
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_x_am05_params *params;

  assert(p->params != NULL);
  params = (gga_x_am05_params * )(p->params);
*)

am05_d     := 28.23705740248932030511071641312341561894: (* POW(CBRT(4/3) * 2*M_PI/3, 4) *)

am05_csi  := s -> (3/2 * LambertW(s^(3/2) / (2*sqrt(6))))^(2/3):
am05_fb   := s -> Pi/3 * s/(am05_csi(s) * (am05_d + am05_csi(s)^2)^(1/4)):
am05_flaa := s -> (1 + params_a_c*s^2)/(1 + params_a_c*s^2/am05_fb(s)):
(* KEEP IN SYNC: am05_XX and am05_one_minus_XX are paired.
   Algebraic identities (with A = alpha*s^2):
     XX           = 1 - A/(1+A) = 1/(1+A)
     1 - XX       =     A/(1+A)
   so the direct 1 - A/(1+A) form cancels at large s (A -> infty,
   the fraction -> 1), and 1 - XX cancels at small s (XX -> 1).
   Both are written in their cancellation-free single-fraction
   form below. *)
am05_XX           := s -> 1/(1 + params_a_alpha*s^2):
am05_one_minus_XX := s -> params_a_alpha*s^2/(1 + params_a_alpha*s^2):

am05_f    := x ->  am05_XX(gga_s(x)) + am05_one_minus_XX(gga_s(x))*am05_flaa(gga_s(x)):

f := (rs, zeta, xt, xs0, xs1) -> gga_exchange(am05_f, rs, zeta, xs0, xs1):
