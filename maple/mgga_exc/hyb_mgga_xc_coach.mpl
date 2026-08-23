(*
 Copyright (C) 2026 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

(* type: mgga_exc *)

(* COACH range-separated hybrid meta-GGA of Liang and Head-Gordon.

   E_x = E_x^{SL,sr} + c_x,sr * E_x,sr^HF + c_x,lr * E_x,lr^HF
   E_c = E_c,ss^SL  + E_c,os^SL                (+ VV10, + external D4-ATM)

   The Hartree-Fock pieces and the range separation are handled through
   the CAM machinery (c_x,lr = cam_alpha, c_x,sr = cam_alpha + cam_beta,
   omega = cam_omega); D4-ATM is an external dispersion correction that
   is outside the scope of libxc.  Here we implement the semi-local part:

   - short-range LDA exchange (erf attenuation) times a B97-type fitting
     factor g_x that is Legendre in v = 2 beta - 1 and monomial in u_x;
   - same-spin / opposite-spin correlation built on the SCAN alpha = 1
     (revised-PBE-like) base energy density via a Stoll decomposition,
     with a 2 beta self-correlation-correction factor on the same-spin
     part.  *)

(* short-range LDA exchange; uses p_a_cam_omega for the attenuation. *)
$include "lda_x_erf.mpl"

(* SCAN alpha = 1 correlation building blocks: f_pw (PW92), mphi, mgamma,
   tt (SCAN reduced gradient t), and A with the Hu-Langreth rs-dependent
   beta, all pulled in through the regTPSS chain. *)
$include "gga_c_scan_e0.mpl"

(* Legendre polynomials P_n on [-1, 1] via the orthopoly package (the
   same way mbeef / beefvdw pull theirs in). *)
with(orthopoly):

(* ----- nonlinearity parameters ----- *)
coach_gamma_x  := 0.004:
coach_gamma_ss := 0.01:
coach_gamma_os := 0.006:

(* SCAN non-uniform-scaling-correction (NUSC) factor on exchange,
   g_x(s) = 1 - exp(-a1 s^(-1/2)) with a1 = 13.815 and s = xs (eq. 33).
   This multiplies the SR-LDA exchange enhancement to enforce the
   non-uniform density-scaling constraint; it suppresses exchange in the
   large-gradient (low-density) tails.  Uses the guarded, cancellation-
   free m_one_minus_recexp (1 - exp(-1/x)) with x = sqrt(xs)/a1, so
   1/x = a1/sqrt(xs).  The outer sqrt gives dx/dxs = 1/(2 a1 sqrt(xs)) ->
   infinity at xs = 0 (empty channel at full polarization), leaking
   0*infinity into fxc.  mgga_exchange_erf fixes the LDA-base spin scaling
   but not this enhancement-side singularity, so floor xs at xc_reduced_floor
   here (verified: dropping it reintroduces the full-polarization fxc NaN). *)
coach_nusc := xs -> m_one_minus_recexp(sqrt(m_max(xs, xc_reduced_floor))/13.815):

(* iso-orbital indicator beta = (tau - tau_W)/(tau + tau_UEG).  libxc
   uses the tau = (1/2) sum |grad phi|^2 convention, so in the reduced
   variables of work_mgga (ts = tau_sigma/rho_sigma^(5/3)) we have
   tau_W/rho_sigma^(5/3) = xs^2/8 and tau_UEG/rho_sigma^(5/3) =
   K_FACTOR_C.  (The paper's eqs. 16-17 use the factor-of-two larger
   tau = sum |grad phi|^2 convention, but beta is invariant since the
   factor cancels between numerator and denominator.)  With the work_mgga
   sigma clamp xs^2 <= 8 ts this keeps beta in [0, 1) and hence
   v = 2 beta - 1 in [-1, 1), where the Legendre expansion is well
   behaved. *)
(* coach_beta/coach_v take the SQUARED reduced gradient xs2 = xs^2, so the
   opaque fitting helpers below are rational in sigma (see maple/util.mpl
   b97_u, t_vw): the sigma-derivatives never chain through sqrt(sigma). *)
coach_beta := (xs2, ts) -> (ts - xs2/8)/(ts + K_FACTOR_C):
coach_v    := (xs2, ts) -> 2*coach_beta(xs2, ts) - 1:

(* SCAN alpha = 1 (revised-PBE-like) correlation energy per particle.
   H1 = gamma phi^3 log(1 + w1 (1 - g(A t^2))), g = (1 + 4 A t^2)^(-1/4),
   w1 = exp(-eps_c^LSDA/(gamma phi^3)) - 1, A = beta(rs)/(gamma w1).
   A, tt, mphi, mgamma, f_pw come from the include chain; the gradient
   enters through the SCAN reduced gradient inside tt(rs, z, xt).  The
   1 - g and w1 terms are written through expm1/log1p. *)
coach_w1          := (rs, z)    -> xc_expm1(-f_pw(rs, z)/(mgamma*mphi(z)^3)):
coach_H1          := (rs, z, t) ->
  mgamma*mphi(z)^3*xc_log1p(coach_w1(rs, z)*scan_e0_one_minus_g(rs, z, t)):
coach_ec1 := (rs, z, xt, xs0, xs1) ->
  f_pw(rs, z) + coach_H1(rs, z, tt(rs, z, xt)):

(* ----- nonzero expansion coefficients [c_ij, i, j] ----- *)
(* exchange: i = Legendre order in v, j = monomial order in u *)
coach_cx := [
  [  0.7080650005052257,    0,  0], [  5.973423554868972,    0,  2],
  [-17.33477136180401,      0,  3], [ 25.0,                  0,  5],
  [-13.303231846931668,     0,  7], [ -0.20577489944575586,  1,  0],
  [ -0.10779574940300828,   2,  0], [  5.491317004106042,    2,  2],
  [ -6.658515516611359,     2,  3], [  1.839797240566924,    3,  1],
  [ -7.509521330876057,     3,  2], [ 18.654513589197446,    3,  3],
  [-12.139029019506687,     3,  4], [  0.20195969717314624,  4,  0],
  [  0.2600717991008879,    5,  0], [ -3.463397249605392,    5,  2],
  [  3.75514691066743,      5,  3], [  0.2402820743898442,   6,  0],
  [ -0.8660852096125707,    6,  1], [  0.10480172805257999,  7,  0],
  [ -0.5657722952687481,    7,  1], [ -0.43586821950068677,  8,  1],
  [  0.9891478454228174,    8,  4], [ -0.09350557083826855,  9,  0],
  [  0.2557276229171211,    9,  1], [ -0.7171538898115716,   9,  2],
  [ -0.034948386270515386, 10,  0], [ -0.03464312342837082, 11,  0],
  [  0.20050993281346377,  11,  1], [ -0.3773473250434576,  11,  2]
]:
coach_nx := 30:

(* same-spin: i = Legendre order in v, j = monomial order in u *)
coach_css := [
  [ -0.3039405655250467,    0,  0], [ -1.2900096158738523,   0,  1],
  [ 17.715459474491766,     0,  4], [-13.929080028872658,    0,  7],
  [ -1.8711635396581212,    1,  0], [-10.122833804966692,    1,  1],
  [ 22.05988705553151,      1,  2], [ -1.8278556540465263,   2,  0],
  [  6.994998018578696,     2,  1], [ -8.349141007699943,    2,  4],
  [ -2.226676731002602,     3,  1], [ -2.7311170048590196,   3,  2],
  [ -1.4633617968363573,    5,  0], [ -0.8348281349925031,   7,  0],
  [  0.4818154118907339,    8,  0], [ -3.3444231176840256,   8,  1],
  [  6.986341349369924,     8,  2], [ 14.980984577715752,    8,  3],
  [-25.0,                   8,  4], [  1.5676639733349753,  11,  3]
]:
coach_nss := 20:

(* opposite-spin: i = Legendre order in w, j = Legendre order in u *)
coach_cos := [
  [  2.0330833570991405,    0,  0], [ -3.071472897617402,    0,  5],
  [ -1.9671740896453935,    0,  7], [ -3.124170248419258,    1,  0],
  [  7.594716450411337,     1,  1], [  4.618674090063557,    2,  4],
  [  2.572431599509026,     3,  7], [ -1.120055362237976,    4,  4],
  [ -2.5762282779751264,    4,  7], [ -1.4299548850828665,   5,  1],
  [-20.76844377770899,      5,  4], [ 25.0,                  5,  5],
  [-22.533887529213906,     5,  6], [  9.590467389102345,    5,  7],
  [  4.4188486804036184,    6,  4], [  4.293474773028771,    8,  4],
  [ -1.5286479621022213,    9,  2], [  2.3555422987546892,   9,  7],
  [  0.7896380110221484,   10,  0], [ -1.9225815901087469,  10,  3],
  [  2.229310613916473,    11,  1], [ -1.5811003317333285,  11,  6],
  [  1.1456216634190832,   11,  7]
]:
coach_nos := 23:

(* ----- fitting factors ----- *)
(* exchange / same-spin: Legendre in v, monomial in u *)
coach_g_lv := (mgamma, cc, n, xs2, ts) ->
  add(cc[i][1]*P(cc[i][2], coach_v(xs2, ts))*b97_u(mgamma, xs2)^cc[i][3], i=1..n):

(* opposite-spin reduced gradient u_ab from s_ab^2 = (s_a^2 + s_b^2)/2;
   takes the SQUARED per-spin reduced gradients xs02 = xs0^2, xs12 = xs1^2 *)
coach_uos := (xs02, xs12) ->
  coach_gamma_os*(xs02 + xs12)/2/(1 + coach_gamma_os*(xs02 + xs12)/2):

(* opposite-spin kinetic variable w = (t_ab - 1)/(t_ab + 1),
   t_ab = (t_a + t_b)/2, t_sigma = tau_sigma^UEG/tau_sigma = K/ts (the
   ratio is convention-independent).  This coincides with wB97M-V's wx_os.

   wos is bounded in [-1, 1], but the naive rational form
     (K*(ts0+ts1) - 2*ts0*ts1)/(K*(ts0+ts1) + 2*ts0*ts1)
   has numerator and denominator that both scale as ts0*ts1.  When the
   Legendre polynomials P(n, wos) raise this to a power, the code
   generator distributes the exponent over the quotient, computing the
   numerator and denominator powers separately; for a large reduced tau
   (ts ~ 1e26, e.g. a tiny density with a huge kinetic energy density)
   ts0*ts1 ~ 1e52 and its high powers overflow the double range, giving
   inf/inf = NaN even though wos itself is ~ -1.

   Rewrite it via the per-spin bounded quantities
     p_i = ts_i/(K + ts_i)   in [0, 1),
     w_i = (K - ts_i)/(K + ts_i) in (-1, 1],
   so that wos = (p0*w1 + p1*w0)/(p0 + p1), with the base of every power
   now O(1).  Algebraically identical, but overflow-free. *)
coach_p  := t -> t/(K_FACTOR_C + t):
coach_wos := (ts0, ts1) ->
  (coach_p(ts0)*mgga_w(ts1) + coach_p(ts1)*mgga_w(ts0))
  /(coach_p(ts0) + coach_p(ts1)):

coach_g_os := (cc, n, ts0, ts1, xs02, xs12) ->
  add(cc[i][1]*P(cc[i][2], coach_wos(ts0, ts1))
      *P(cc[i][3], coach_uos(xs02, xs12)), i=1..n):

(* ----- exchange: short-range LDA exchange (spin-scaled via mgga_exchange_erf)
   times the B97-type g_x and the NUSC factor ----- *)
coach_fx_enh := (xs, u, ts) ->
  coach_g_lv(coach_gamma_x, coach_cx, coach_nx, xs^2, ts) * coach_nusc(xs):
coach_fx := (rs, z, xs0, xs1, ts0, ts1) ->
  mgga_exchange_erf(coach_fx_enh, rs, z, xs0, xs1, 0, 0, ts0, ts1):

(* ----- same-spin correlation: Stoll parallel base, SCC factor 2 beta ----- *)
(* Screen each per-spin term as a whole.  gga_stoll_par screens itself, but the
   2 beta and g_lv factors multiply it from outside; at an empty spin channel
   their reduced-gradient derivatives diverge, so the screened product is 0*NaN
   in fxc.  Wrapping the full term in the density screen masks the empty channel,
   exactly as mgga_exchange does for the coach_fx exchange term. *)
coach_fss := (rs, z, xs0, xs1, ts0, ts1) ->
  + my_piecewise3(screen_dens_zeta(rs,  z), 0,
      gga_stoll_par(coach_ec1, rs,  z, xs0,  1)
      * (2*coach_beta(xs0^2, ts0)) * coach_g_lv(coach_gamma_ss, coach_css, coach_nss, xs0^2, ts0))
  + my_piecewise3(screen_dens_zeta(rs, -z), 0,
      gga_stoll_par(coach_ec1, rs, -z, xs1, -1)
      * (2*coach_beta(xs1^2, ts1)) * coach_g_lv(coach_gamma_ss, coach_css, coach_nss, xs1^2, ts1)):

(* ----- opposite-spin correlation: Stoll perpendicular base ----- *)
coach_ec_os := (rs, z, xt, xs0, xs1) ->
  + coach_ec1(rs, z, xt, xs0, xs1)
  - gga_stoll_par(coach_ec1, rs,  z, xs0,  1)
  - gga_stoll_par(coach_ec1, rs, -z, xs1, -1):

coach_fos := (rs, z, xt, xs0, xs1, ts0, ts1) ->
  coach_ec_os(rs, z, xt, xs0, xs1)
    * coach_g_os(coach_cos, coach_nos, ts0, ts1, xs0^2, xs1^2):

f := (rs, z, xt, xs0, xs1, us0, us1, ts0, ts1) ->
  + coach_fx(rs, z, xs0, xs1, ts0, ts1)
  + coach_fss(rs, z, xs0, xs1, ts0, ts1)
  + coach_fos(rs, z, xt, xs0, xs1, ts0, ts1):
