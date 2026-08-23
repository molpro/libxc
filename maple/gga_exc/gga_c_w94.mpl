(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)

a := -1:
b := 11.8:
c :=  0.150670:
d := 11.02e-3/RS_FACTOR:

(* I added an m_abs() to this equation, as otherwise the f_num is
   complex for negative values of z. Of course it is not clear at all
   what was the original intential of Wilson, or if he even considered
   this problem. *)
if evalb(Polarization = "unpol") then
    f_num := z -> a:
else
    (* clamp |z| into [floor, 1-floor]: the lower floor avoids the float
       exception in derivatives > 2 (|z|^(5/3) is non-smooth at z=0); the
       upper cap keeps 1 - |z|^(5/3) > 0 so the sqrt stays real when |z|
       rounds to >= 1 at full spin polarization (otherwise sqrt(neg)=NaN). *)
    f_num := z -> a*sqrt(1 - m_min(m_max(m_abs(z), xc_reduced_floor), 1 - xc_reduced_floor)^(5/3)):
end if:
f_den := (rs, xt) -> b + c*xt^(51/16) + d*xt^2*rs + rs:

(* Equation (25) *)
f := (rs, z, xt, xs0, xs1) ->
  f_num(z)/f_den(rs, xt):

