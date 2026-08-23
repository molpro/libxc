(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* replace: "mbrxc_x\(" -> "xc_mgga_x_mbrxc_get_x(" *)

mbrxc_a1 := 0.074746:
mbrxc_a2 := 0.147:
mbrxc_a3 := 0.0032:

(* This is the derivative of f = (1+x)^(5/3)*exp(-2/3*x)/(x - 3) = (32*Pi)^(2/3)/(6*Q) *)
mbrxc_aux_dfdx := x -> -2/3 * (1 + x)^(2/3) * exp(-2*x/3) * (x^2 - 3*x + 6) / (x - 3)^2:

`diff/mbrxc_x` := proc(Q, g)
  - (32*Pi)^(2/3)/6 * diff(Q, g)/(Q^2 * mbrxc_aux_dfdx(mbrxc_x(Q)))
end proc:

mbrxc_Q := (x, t) ->
        mbrxc_a1*(2*t) - K_FACTOR_C + mbrxc_a2*x^2 + mbrxc_a3*x^4:

(* The numerator 8 - exp(-x)*(x^2+5x+8) cancels at small x.
   Algebraic identity:
     8 - exp(-x)*(x^2+5x+8)
       = 8 - (1 + (exp(-x) - 1))*(x^2+5x+8)
       = 8 - (x^2+5x+8) - xc_expm1(-x)*(x^2+5x+8)
       = -x*(x+5) - xc_expm1(-x)*(x^2+5x+8),
   which is cancellation-free at all x (and reproduces the leading
   3x at small x: -5x + (-x)*8 = -5x + 8x = 3x).  The direct form
   is now full-precision everywhere, so the Taylor branch is kept
   only for derivative correctness at x = 0 exactly (where
   xc_expm1(-x)/x would be 0/0); the boundary mismatch at the
   cutoff is now at the ULP level. *)
mbrxc_v0 := x ->
  - (32*Pi)^(1/3)/(8*X_FACTOR_C) * exp(x/3)*(-x*(x+5) - xc_expm1(-x)*(x^2 + 5*x + 8))/(x*(1 + x)^(1/3)):

(* With the cancellation-free rewrite above, direct mbrxc_v0 is now
   precise at all x > 0, so the Taylor branch is needed only to
   handle the formal 0/0 at x = 0 in xc_expm1(-x)/x and to keep
   derivatives correct at the boundary.  Tightened to cutoff
   sqrt(XC_EPSILON) with Maple order 7 (degree-6 polynomial): at
   the boundary the 4th derivative truncation is
     7*6*5*4 * c_7 * sqrt(eps)^3 ~ O(840) * eps^(3/2) ~ 4e-21,
   well below XC_EPSILON * |actual 4th derivative ~ O(1)|. *)
(* series() through to_elementary: the 1/x factor is a removable
   singularity (the numerator vanishes at x=0) that taylor() refuses,
   and mbrxc_v0 carries the inert xc_expm1 wrapper -- to_elementary
   makes it native so series() can expand through the singularity. *)
mbrxc_v_smallq := x -> eval(convert(series(to_elementary(mbrxc_v0(y)), y = 0, 7), polynom), y=x):
mbrxc_v_cutoff := sqrt(XC_EPSILON):
mbrxc_v := x -> my_piecewise3(x < mbrxc_v_cutoff, mbrxc_v_smallq(x), mbrxc_v0(m_max(x, mbrxc_v_cutoff))):

mbrxc_f := (x, u, t) ->
  - mbrxc_v(mbrxc_x(mbrxc_Q(x, t)))/2:

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_exchange(mbrxc_f, rs, z, xs0, xs1, u0, u1, t0, t1):
