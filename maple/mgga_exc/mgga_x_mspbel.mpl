(*
 Copyright (C) 2017 M.A.L. Marques
 Copyright (C) 2018 Susi Lehtola
 Copyright (C) 2024 Dogukan Yilmaz

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_x_mspbel_params *params;

  assert(p->params != NULL);
  params = (mgga_x_mspbel_params * ) (p->params);
*)

(* MS-PBE-l is plain MS with the regularized iso-orbital indicator
   mgga_alpha_reg.  Its f0 = 1 + A/(1 + A/kappa) = 1 + kappa A/(kappa + A)
   (A = MU_GE*p) is algebraically identical to ms_f0, and its f0-delta to
   ms_f0_delta, and its fa to ms_fa -- so reuse all of them via the
   include (which also brings the ms_fa magnitude clamp) rather than
   duplicating.  (The 2019 Smeets et al. paper drops the cube in eq (3).) *)
$include "mgga_x_ms.mpl"

mspbel_f := (x, u, t) -> ms_f0(X2S^2*x^2, 0) + \
  ms_fa(mgga_alpha_reg(x, t, params_a_eta))*ms_f0_delta(X2S^2*x^2, params_a_c):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_exchange(mspbel_f, rs, z, xs0, xs1, u0, u1, t0, t1):
