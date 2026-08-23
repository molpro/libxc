(*
 Copyright (C) 2019 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)
(* prefix:
  mgga_x_task_params *params;

  assert(p->params != NULL);
  params = (mgga_x_task_params * )(p->params);
*)


task_gx := x -> m_one_minus_recexp(x^(1/4)/params_a_task_c):

# expand (not simplify) the Chebyshev sums: Maple 2025's simplify()
# throws an internal "content/content" error on these during the
# codegen derivative processing, while expand() produces the same
# expanded polynomial without tripping it.
task_hx1 := r -> expand(add(params_a_task_anu[i+1]*ChebyshevT(i, (r - 1)/(r + 1)), i=0..2)):

task_fx  := r -> expand(add(params_a_task_bnu[i+1]*ChebyshevT(i, (r - 1)/(r + 1)), i=0..4)):

task_f0 := (s, a) -> params_a_task_h0x*task_gx(s^2) +
  (1.0 - task_fx(a))*(task_hx1(s^2) - params_a_task_h0x)*task_gx(s^2)^params_a_task_d:

task_f := (x, u, t) -> task_f0(gga_s(x), mgga_alpha_safe(x, t)):

f := (rs, z, xt, xs0, xs1, u0, u1, t0, t1) ->
  mgga_exchange(task_f, rs, z, xs0, xs1, u0, u1, t0, t1):
