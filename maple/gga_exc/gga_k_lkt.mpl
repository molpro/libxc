(*
 Copyright (C) 2020 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_k_lkt_params *params;

  assert(p->params != NULL);
  params = (gga_k_lkt_params * )(p->params);
*)

(* LKT kinetic enhancement F(s) = 1/cosh(a*s) + (5/3) s^2, s = gga_s(xs).
   Written as a function of p = xs^2 and evaluated through gga_kinetic_p, which
   differentiates with respect to p (rational in sigma) rather than xs, so no
   half-integer powers of sigma enter. Two stability points:

   (1) The gradient-expansion (von Weizsaecker) term (5/3) s^2 = (5 X2S^2/3) p
       is LINEAR in p, and p is linear in sigma, so its second and higher sigma
       derivatives are EXACTLY zero -- the generated v2sigma2 is a literal 0.
       Feeding s (which carries sqrt(sigma)) makes it instead a difference of
       two ~1/(sigma*rho) terms that cancels only in exact arithmetic, losing
       all accuracy at the density tail (compiler-dependently).

   (2) 1/cosh(a*s) = 1/cosh(a*X2S*sqrt(p)) is evaluated in the overflow-free
       form 2*t/(1 + t^2), t = exp(-a*X2S*sqrt(p)) in (0, 1]; the literal
       cosh(...)^k in the derivative denominators (k up to 5) would otherwise
       overflow double precision at the tail. This term genuinely depends on s,
       not s^2, but it is exp-suppressed to a clean zero there, so it needs no
       further care. *)
lkt_arg := p -> params_a_a*X2S*sqrt(p):
lkt_f   := p -> 2*exp(-lkt_arg(p))/(1 + exp(-2*lkt_arg(p))) + 5*X2S^2/3*p:

f := (rs, z, xt, xs0, xs1) -> gga_kinetic_p(lkt_f, rs, z, xs0, xs1):
