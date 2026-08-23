(*
 Copyright (C) 2017 M.A.L. Marques
               2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* replace: "my_dilog\(" -> "xc_dilogarithm(" *)

(* d/dx Li_2(g) = -log(1 - g)/g * dg/dx; route log(1 - g) through
   xc_log1p so the derivative stays precise at g -> 0. *)
`diff/my_dilog` := proc(g, x) -xc_log1p(-g)/g * diff(g, x) end proc:

gg99_a := 3^(1/4)/(2*sqrt(2)*Pi^(3/2)):
gg99_b := 4*sqrt(3)*Pi^3:

(* Equation 22 in the paper, i.e.
   the solution of x = 2*Pi*sinh(r)/(3*cosh(r))^(1/3) *)

gg99_r_branch1 := x -> xc_asinh( (gg99_a * x * sqrt(x^2 + (gg99_b + sqrt(gg99_b^2 - x^6))^(2/3))) / (gg99_b + sqrt(gg99_b^2 - x^6))^(1/6) ):

(* The second branch is from Andrew Gilbert via email *)

gg99_r_branch2 := x-> xc_asinh(sqrt(x^3*(3/gg99_b)*cos(arctan(sqrt(1/(gg99_b^2)*x^6-1))/3))):

(* Glue the pieces together. The min and max are required
   to avoid float exceptions *)
gg99_r := x -> my_piecewise3(x < gg99_b^(1/3),
  gg99_r_branch1(m_min(x, gg99_b^(1/3) - 1e-10)),
  gg99_r_branch2(m_max(x, gg99_b^(1/3) + 1e-10))
  ):

(* Equation 21.  The numerator
     Pi^2 - 12 r log1p(exp(-2r)) + 12 dilog(-exp(-2r))
   collapses to 0 at r = 0 (both constants are pi^2: dilog(-1) =
   -pi^2/12).  Taylor expansion at r = 0 starts with 12*log(2)*r, so
   the direct form loses ~ log10(pi^2/(12*log(2)*r)) digits of
   precision.  Use a Taylor branch for r < 1/4 (where the series
   converges and order 16 gives 4th-derivative ULP) and the direct
   form otherwise. *)
gg99_f0_num_orig   := r -> Pi^2 - 12*r*xc_log1p(exp(-2*r)) + 12*my_dilog(-exp(-2*r)):
gg99_f0_num_taylor := r -> eval(convert(series(to_elementary(gg99_f0_num_orig(w)), w=0, 16), polynom), w=r):
gg99_f0_num        := r -> my_piecewise3(r < 1/4,
  gg99_f0_num_taylor(r),
  gg99_f0_num_orig(r)):

gg99_f0 := r -> gg99_f0_num(r) / (2*3^(1/3)*Pi*r*sech(r)^(2/3)) / X_FACTOR_C:

(* Assemble the function *)
gg99_f := x -> gg99_f0(gg99_r(x)):

f := (rs, zeta, xt, xs0, xs1) ->
  gga_exchange(gg99_f, rs, zeta, xs0, xs1):
