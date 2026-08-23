(*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* Simplified, regularized Tao-Mo exchange (sregTM),
   H. Francisco, A. C. Cancio, S. B. Trickey,
   J. Chem. Phys. 159, 214102 (2023).

   sregTM reuses the regularized Tao-Mo exchange machinery but replaces the
   regTM z' regularizer (which has unphysical behaviour) with the simple
   rational regularizer z_rev (Eq. 27),
       z_rev(a, p) = (5 p + eps_p) / (5 p + 3 a + eps_p),
   here with eps_p = 0.5.  a = alpha is the iso-orbital indicator and
   p = s^2.  alpha is clamped non-negative (it is >= 0 physically; this
   keeps the denominator positive and z_rev in (0, 1]). *)
$include "mgga_x_regtm.mpl"

sregtm_zrev := (a, p) -> (5*p + 0.5)/(5*p + 3*m_max(a, 0) + 0.5):

(* v1-sregTM: z_rev enters only the DME/SC switch w; F_x^SC keeps the
   ordinary z (= tm_tratio), paralleling regTM's use of z' in w and z in
   the SC term.  Reuse regTM's cancellation-safe w / (1-w) pair. *)
tm_w           := (x, t) -> regtm_w          (sregtm_zrev(mgga_alpha(x, t), tm_p(x))):
tm_one_minus_w := (x, t) -> regtm_one_minus_w(sregtm_zrev(mgga_alpha(x, t), tm_p(x))):
