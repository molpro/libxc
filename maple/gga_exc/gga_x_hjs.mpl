(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_x_hjs_params *params;

  assert(p->params != NULL);
  params = (gga_x_hjs_params * )(p->params);
*)

hjs_AA :=  0.757211:
hjs_BB := -0.106364:
hjs_CC := -0.118649:
hjs_DD :=  0.609650:

hjs_fH := s -> add(params_a_a[i]*s^(1+i), i=1..6)/(1 + add(params_a_b[i]*s^i, i=1..9)):

(* The m_max functions are necessary as in some cases the arguments of the
   sqrt become negative *)
hjs_zeta   := s -> m_max(s^2*hjs_fH(s), xc_reduced_floor):
hjs_eta    := s -> m_max(hjs_AA + hjs_zeta(s), xc_reduced_floor):
hjs_lambda := s -> hjs_DD + hjs_zeta(s):
(* KEEP IN SYNC: hjs_chi and hjs_one_minus_chi.  Conjugate rationalization
     1 - nu/sqrt(lambda + nu^2) = (sqrt(lambda + nu^2) - nu)/sqrt(lambda + nu^2)
                                = lambda/((sqrt(lambda + nu^2) + nu)*sqrt(lambda + nu^2)),
   cancellation-free at nu -> infinity (low density) where chi -> 1
   and the direct 1 - close-to-1 form loses precision.  The
   polynomial factors below in hjs_f1 also share (1-chi)^k structure:
     2 - 3*chi + chi^3  = (1-chi)^2*(2+chi)
     8 - 15*chi + 10*chi^3 - 3*chi^5 = (1-chi)^3*(8 + 9*chi + 3*chi^2)
   so factor them through hjs_one_minus_chi as well. *)
hjs_chi           := (rs, z, s) -> nu(rs, z)/sqrt(hjs_lambda(s) + nu(rs, z)^2):
hjs_one_minus_chi := (rs, z, s) -> hjs_lambda(s)
  / ((sqrt(hjs_lambda(s) + nu(rs, z)^2) + nu(rs, z))*sqrt(hjs_lambda(s) + nu(rs, z)^2)):

hjs_fF := (rs, z, s) ->
  1 - s^2/(27*hjs_CC*(1 + s^2/4)) - hjs_zeta(s)/(2*hjs_CC):

(* sqrt(zeta) - sqrt(eta) = (zeta - eta)/(sqrt(zeta) + sqrt(eta)),
   cancellation-free at large s where eta - zeta = AA (constant) gets
   swamped by the absolute magnitudes. *)
hjs_fG := (rs, z, s) ->
  - 2/5  * hjs_CC*hjs_fF(rs, z, s)*hjs_lambda(s)
  - 4/15 * hjs_BB*hjs_lambda(s)^2
  - 6/5  * hjs_AA*hjs_lambda(s)^3
  - hjs_lambda(s)^(7/2)*(4/5*sqrt(Pi) + 12/5*(hjs_zeta(s) - hjs_eta(s))/(sqrt(hjs_zeta(s)) + sqrt(hjs_eta(s)))):

(* In hjs_f1:
   - sqrt(zeta + nu^2) - sqrt(eta + nu^2)  ->  (zeta - eta)/(sum)
   - log((nu + sqrt(zeta+nu^2))/(nu + sqrt(lambda+nu^2)))  ->
       xc_log1p((sqrt(zeta+nu^2) - sqrt(lambda+nu^2))/(nu + sqrt(lambda+nu^2)))
     with the sqrt subtraction in turn rationalized to
       (zeta - lambda)/(sum).
   The log-of-close-to-1 cancels at large nu (high density) where
   sqrt(zeta + nu^2) and sqrt(lambda + nu^2) both approach nu, so
   the ratio approaches 1.  Same idea for the eta log. *)
hjs_f1 := (rs, z, s) ->
   + hjs_AA
   - 4/9 * hjs_BB*hjs_one_minus_chi(rs, z, s)/hjs_lambda(s)
   - 2/9 * hjs_CC*hjs_fF(rs, z, s)*hjs_one_minus_chi(rs, z, s)^2*(2 + hjs_chi(rs, z, s))/hjs_lambda(s)^2
   - 1/9 * hjs_fG(rs, z, s)*hjs_one_minus_chi(rs, z, s)^3*(8 + 9*hjs_chi(rs, z, s) + 3*hjs_chi(rs, z, s)^2)/hjs_lambda(s)^3
   + 2*nu(rs, z)*(hjs_zeta(s) - hjs_eta(s))
     /(sqrt(hjs_zeta(s) + nu(rs, z)^2) + sqrt(hjs_eta(s) + nu(rs, z)^2))
   + 2*hjs_zeta(s)*xc_log1p(
       (hjs_zeta(s) - hjs_lambda(s))
       /((sqrt(hjs_zeta(s) + nu(rs, z)^2) + sqrt(hjs_lambda(s) + nu(rs, z)^2))
         *(nu(rs, z) + sqrt(hjs_lambda(s) + nu(rs, z)^2))))
   - 2*hjs_eta(s)*xc_log1p(
       (hjs_eta(s) - hjs_lambda(s))
       /((sqrt(hjs_eta(s) + nu(rs, z)^2) + sqrt(hjs_lambda(s) + nu(rs, z)^2))
         *(nu(rs, z) + sqrt(hjs_lambda(s) + nu(rs, z)^2)))):

hjs_fx := (rs, z, x) -> hjs_f1(rs, z, gga_s(x)):

f := (rs, z, xt, xs0, xs1) -> gga_exchange_nsp(hjs_fx, rs, z, xs0, xs1):
