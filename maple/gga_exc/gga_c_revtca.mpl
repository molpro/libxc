(*
 Copyright (C) 2017 M.A.L. Marques
               2022 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

$include "gga_c_tca.mpl"

(* Taylor expansion of sinc(x) at x=0.  Even-only series, so order 7
   (degree-6 polynomial, terms 1, y^2, y^4, y^6) is sufficient for
   4th-derivative ULP at the eps^(1/4) cutoff: truncation 4th deriv
   is 8*7*6*5 * (1/9!) * (eps^(1/4))^4 ~ 1e-18, well below
   XC_EPSILON * |sinc''''(0) ~ 1/5| ~ 4e-17. *)
sinc := x -> sin(x)/x:
sinc_taylor := x -> eval(convert(taylor(sinc(y),y=0,7),polynom),y=x):

(* Switch to Taylor when x^4 ~ epsilon, i.e. x ~ eps^(1/4). *)
sinc_cutoff := XC_EPSILON^(1/4):
msinc := x -> my_piecewise3(x <= sinc_cutoff, sinc_taylor(x), sinc(m_max(x, sinc_cutoff))):

revtca_aa := Pi*(9*Pi/4)^(1/3):
(* 1 - z^4*(1 - msinc^2) = (1 - z^4) + z^4*msinc^2; the (1 - z^4)
   factor is routed through one_minus_z_pow_n so the spin-boundary
   cancellation is gone, and the residual `z^4*msinc^2` no longer
   contains the catastrophic `1 - msinc^2` at small argument where
   msinc -> 1. *)
revtca_fD := (rs, z, s) -> one_minus_z_pow_n(z, 4) + z^4*msinc(revtca_aa*s/rs)^2:

f := (rs, z, xt, xs0, xs1) ->
  f_tcs(rs, z, xt)*revtca_fD(rs, z, gga_s_total(xt)):
