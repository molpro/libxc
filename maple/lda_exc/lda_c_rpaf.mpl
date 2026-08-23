(*
 Copyright (C) 2025 Angel Rosado, Mario Benites, Efstratios Manousakis

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)

(* ring-diagram series fit *)
chip := z ->  (1+z)^(1/3):
chim := z ->  (1-z)^(1/3):
chi  := z ->  chip(z) + chim(z):
d0   :=      -0.803:
d1   := z ->  0.8822 + 0.1648*z^2 + 0.0432*z^4:

c0   := z -> -0.1423 + 0.0036*z^2 + 0.1971*(chi(z)-2) - 0.0326*(chi(z)^2-4) - 0.0177*(chi(z)^3-8):

(* chip(z)^3 = 1+z and chim(z)^3 = 1-z, so the two log terms are
   (1+-z)*log(chi+-(z)/chi(z)); each is a bounded x*log(x)-type quantity whose
   limit is 0 at full polarization (z -> +-1), where chim/chip vanishes and the
   bare log diverges. Guard those two branches so they return the finite limit
   instead of 0*log(0) = NaN; my_piecewise3 is lazy, so the log is never
   evaluated in the excluded branch. *)
cl   := z ->  1/(2*Pi^2)*(2 - log(4) + chi(z)*chip(z)*chim(z)
              + my_piecewise3(1 + z <= p_a_zeta_threshold, 0, (1+z)*log(chip(z)/chi(z)))
              + my_piecewise3(1 - z <= p_a_zeta_threshold, 0, (1-z)*log(chim(z)/chi(z)))):
a2   := z ->  90.76 + 192.62*(chi(z)-2) - 3956.38*(log(chi(z))/chi(z)-log(2)/2):
b2   := z ->  54.55 + 149.46*(chi(z)-2) - 2070.06*(log(chi(z))/chi(z)-log(2)/2):

(* b0(z) is the closed form fixed by the rs -> 0 constraints (Benites, Rosado &
   Manousakis, Phys. Rev. B 110, 195151 (2024), Eqs. (43)-(44) -> Eq. (48)).
   Its denominator 2*log(b2) - 1.75*log(a2) vanishes wherever b2(z) = a2(z)^(7/8),
   and the independently fitted a2(z), b2(z) (Eqs. (56)-(57)) cross that curve at
   z = 0.510437 and z = 0.998640. The numerator does not vanish there, so b0 --
   and hence a0 and epsilon_r -- have genuine, non-removable poles at those two
   polarizations, with b0 changing sign in between. This is a property of the
   published fit, reproduced faithfully here; it makes spin-polarized energies
   grid-dependent (non-convergent under radial quadrature) near those zeta. *)
b0   := z ->  (2*c0(z)+cl(z)*log(a2(z)))/(2*log(b2(z))-1.75*log(a2(z))):
a0   := z -> -0.5*(cl(z)+1.75*b0(z)):

a1   := z ->  d1(z)/a2(z):
b1   := z ->  d0/b2(z):
epsilon_r := (rs, z) -> (a0(z)+a1(z)*rs)*log(1+a2(z)/rs^2) + (b0(z)+b1(z)*rs)*log(1+b2(z)/rs^1.75):

(* kite-diagram series fit *)
AA0  := z ->  0.04836:
AA1  := z ->  0.10215 - 0.05028*z^2 - 0.01283*z^4:
AA2  := z -> -0.01382 + 0.00016*z^2 + 0.00808*z^4:
AA3  := z ->  0.46529 + 0.05868*z^2 - 0.32923*z^4:
AA4  := z ->  0.00364 - 0.00259*z^2 - 0.00021*z^4:
epsilon_2b := (rs, z) -> AA0(z)/(1+AA1(z)*rs) + AA2(z)*rs*log( 1 + 1/(AA3(z)*rs+AA4(z)*rs^1.5) ):

(* dividing by two to convert from Rydberg to Hartree *)
f := (rs, z) -> ( epsilon_r(rs, z) + epsilon_2b(rs, z) )/2:
