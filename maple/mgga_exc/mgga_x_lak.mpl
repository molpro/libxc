(*
 Copyright (C) 2024 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* parameters from page 3 *)
lak_h0x := 1.174:
lak_mu_ax := -(97 + 3*lak_h0x + sqrt((3*lak_h0x)^2 + 74166*lak_h0x - 64175))/1200:
lak_nu_a := (73-50*lak_mu_ax)/5000:
lak_mu_sx := (10+60*lak_mu_ax)/81:
lak_nu_s := -(1606 - 50*lak_mu_ax)/18225:
lak_bx := 4.9479:
lak_ax := 1.1:
lak_anum := 5:

(* SI eq 2 *)
lak_fsa   := (s, a) -> lak_h0x*lak_gx(s) + (1-lak_fx(a))*(lak_h1x(s)-lak_h0x)*lak_gnum(s):
(* SI eq 4. lak_one_minus_gx (= m_recexp) is the cancellation-free
   1 - gx form, used in lak_hx_ge4 below.  lak_gx uses the matching
   m_one_minus_recexp so gx itself is cancellation-free at large s
   (where gx -> 0).  m_one_minus_recexp and m_recexp share the same
   guard/clamp and are exact complements, so the two cannot drift. *)
lak_one_minus_gx := s -> m_recexp(sqrt(s)/lak_bx):
lak_gx           := s -> m_one_minus_recexp(sqrt(s)/lak_bx):

(* SI eq 5. This term has poor behavior around a=0, so we have to do
   a series expansion.  Odd-only series in a (terms 1, a, a^3, a^5,
   ...), so order 6 (degree-5 polynomial) suffices for 4th
   derivative ULP at the XC_EPSILON cutoff: truncation 4th deriv
   is 7*6*5*4 * c_7 * eps^3 ~ O(840) * eps^3 ~ 8e-46, far below
   XC_EPSILON * |actual 4th derivative ~ O(1)|. *)
lak_fx0 := a -> 2/Pi * arctan(Pi/2*(lak_c1*(a-1)/a + lak_c2*(a-1)^2)):
lak_fx_taylor := a -> eval(convert(eval(series(lak_fx0(b),b=0,6),csgn=-1),polynom),b=a):
lak_fx := a -> my_piecewise3(a <= XC_EPSILON, lak_fx_taylor(a), lak_fx0(m_max(a,XC_EPSILON))):
(* SI eq 6 *)
lak_c1 := lak_mu_ax/(lak_h0x-1):
(* SI eq 7 *)
lak_c2 := (lak_mu_ax + lak_nu_a)/(lak_h0x-1):
(* SI eq 8 *)
lak_h1x := s -> lak_hx_ge4(s) + lak_kx(s)*(lak_ax - lak_hx_ge4(s)):
(* SI eq 9; uses lak_one_minus_gx so the 1 - close-to-1 cancellation
   at large s (where lak_gx -> 1) is gone. *)
lak_hx_ge4 := s -> 1 + lak_mu_sx*s^2 + lak_nu_s*s^4 + lak_h0x*lak_one_minus_gx(s):
(* SI eq 10 *)
lak_kx := s -> m_recexp((s/lak_ax)^2 * (1+s^2)):
(* SI eq 11 *)
lak_gnum := s -> m_one_minus_recexp((s/lak_anum)^2):

(* Build the functional *)
lak_f   := (x, u, t) -> lak_fsa(x*X2S, mgga_alpha_safe(x,t)):
f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) -> mgga_exchange(lak_f, rs, z, xs0, xs1, u0, u1, t0, t1):
