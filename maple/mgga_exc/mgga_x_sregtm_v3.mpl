(*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* v3-sregTM (Francisco, Cancio & Trickey, J. Chem. Phys. 159, 214102
   (2023)): v2 with the gradient-expansion-compliant eps_p = 0.58568
   instead of 0.5.  Redefine z_rev with the new eps_p; the v1/v2 overrides
   reference it by name, so they pick this up. *)
$include "mgga_x_sregtm_v2.mpl"

sregtm_zrev := (a, p) -> (5*p + 0.58568)/(5*p + 3*m_max(a, 0) + 0.58568):
