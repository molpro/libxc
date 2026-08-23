(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: gga_exc *)
(* prefix:
  gga_x_pw91_params *params;

  assert(p->params != NULL);
  params = (gga_x_pw91_params * )(p->params);
*)

$ifdef gga_x_pw91_params
params_a_a     :=   0.19645:
params_a_b     :=   7.7956:
params_a_c     :=   0.2743:
params_a_d     :=  -0.1508:
params_a_f     :=   0.004:
params_a_alpha := 100:
params_a_expo  :=   4:
$endif

pw91_num := s -> (params_a_c + params_a_d*exp(-params_a_alpha*s^2))*s^2
         - params_a_f*s^params_a_expo:
pw91_den := s -> 1 + s*params_a_a*xc_asinh(params_a_b*s) + params_a_f*s^params_a_expo:

# pw91_f = 1 + pw91_num/pw91_den = (pw91_den + pw91_num)/pw91_den. The
# +params_a_f*s^expo in the denominator and -params_a_f*s^expo in the numerator
# cancel analytically, so forming the combined numerator directly is a
# mathematically identical but cancellation-free arrangement. The 1 + num/den
# form loses all precision at large s, where num/den -> -1 and the true
# enhancement is a tiny positive number (e.g. the gga_c_op_pw91 N-atom tail,
# where the huge 1/pw91_f amplifies the lost digits into a ~2500x error).
pw91_fnum := s -> 1 + s*params_a_a*xc_asinh(params_a_b*s)
          + (params_a_c + params_a_d*exp(-params_a_alpha*s^2))*s^2:

pw91_f  := x -> pw91_fnum(gga_s(x))/pw91_den(gga_s(x)):

f := (rs, z, xt, xs0, xs1) -> gga_exchange(pw91_f, rs, z, xs0, xs1):
