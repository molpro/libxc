(*
 Copyright (C) 2019 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: lda_exc *)
(* prefix:
  lda_c_chachiyo_mod_params *params;

  assert(p->params != NULL);
  params = (lda_c_chachiyo_mod_params * )(p->params);
*)

(* Functional is based on Chachiyo correlation *)
$include "lda_c_chachiyo.mpl"
(* .. but with a different scaling function.
   Algebraic identity:
     1 - g^3 = (1 - g)*(1 + g + g^2),
     1 - g   = -(opz_pow_n_m1(z, 2/3) + opz_pow_n_m1(-z, 2/3))/2,
   so g_zeta = 2*(1 - g^3)
            = -(opz_pow_n_m1(z, 2/3) + opz_pow_n_m1(-z, 2/3)) * (1 + g + g^2),
   which is cancellation-free at z = 0 where g -> 1 and the direct
   1 - g^3 form computes 1 - close-to-1. *)
g := z -> (opz_pow_n(z,2/3) + opz_pow_n(-z,2/3))/2:
g_zeta := zeta ->
  -(opz_pow_n_m1(zeta, 2/3) + opz_pow_n_m1(-zeta, 2/3))*(1 + g(zeta) + g(zeta)^2):

f_chachiyo := (rs, zeta) -> e0(rs) + (e1(rs) - e0(rs))*g_zeta(zeta):
f := (rs, zeta) -> f_chachiyo(rs, zeta):
