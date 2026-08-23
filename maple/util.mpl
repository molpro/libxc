(*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*)

# Minimum and maximum functions that I can differentiate

m_min := (x1, x2) -> my_piecewise3(x1 > x2, x2, x1):
m_max := (x1, x2) -> my_piecewise3(x1 > x2, x1, x2):
m_abs := (x)      -> my_piecewise3(x >= 0, x, -x):

# Teach maple to differentiate piecewise functions

`diff/my_piecewise3` :=
    proc(c, x1, x2, x) my_piecewise3(c, diff(x1, x), diff(x2, x)) end proc:

`diff/my_piecewise5` :=
    proc(c1, x1, c2, x2, x3, x) my_piecewise5(c1, diff(x1, x), c2, diff(x2, x), diff(x3,x)) end proc:

# This is the derivative of xc_E1_scaled = -exp(x)*Ei(-x) = exp(x)E1(x)

`diff/xc_E1_scaled` :=
  proc(y, x) (xc_E1_scaled(y) - 1/y) * diff(y, x) end proc:

# The derivative of xc_erfcx = exp(x^2)*erfc(x) = 2*x*xc_erfcx(x) - 2/sqrt(Pi)
`diff/xc_erfcx` :=
  proc(y, x) (2*y*xc_erfcx(y) - 2/sqrt(Pi)) * diff(y, x) end proc:

# Precision-preserving variants of exp/log/asinh/atanh near their
# fixed points, mapped on the C side to the libm expm1/log1p/asinh/
# atanh.  Maple's `arcsinh` / `arctanh` expand to log(x + sqrt(x^2+1))
# / (1/2)*log((1+x)/(1-x)) at codegen time, which reintroduces a
# log(close-to-1) cancellation at small x -- use the xc_* wrappers
# in the .mpl sources instead so the emitted C calls libm directly.
#   xc_expm1(y) := exp(y) - 1                d/dx = (xc_expm1(y) + 1) * dy/dx
#   xc_log1p(y) := log(1 + y)                d/dx = dy/dx / (1 + y)
#   xc_asinh(y) := log(y + sqrt(y^2 + 1))    d/dx = dy/dx / sqrt(1 + y^2)
#   xc_atanh(y) := (1/2)*log((1+y)/(1-y))    d/dx = dy/dx / ((1+y)*(1-y))
# (the denominator is kept factored as (1+y)*(1-y) so the floor near
#  |y| -> 1 is computed as a product of two cancellation-free factors,
#  not as 1 - y^2 which would itself cancel.)
# xc_x_minus_log1p(y) := y - log(1 + y); no libm equivalent, custom
# implementation in src/util.c with Taylor branch for small |y|.
#   d/dx [y - log(1+y)] = (1 - 1/(1+y)) * dy/dx = y/(1+y) * dy/dx
`diff/xc_expm1` :=
  proc(y, x) (xc_expm1(y) + 1) * diff(y, x) end proc:
`diff/xc_log1p` :=
  proc(y, x) diff(y, x) / (1 + y) end proc:
`diff/xc_asinh` :=
  proc(y, x) diff(y, x) / sqrt(1 + y^2) end proc:
`diff/xc_atanh` :=
  proc(y, x) diff(y, x) / ((1 + y) * (1 - y)) end proc:
`diff/xc_x_minus_log1p` :=
  proc(y, x) y / (1 + y) * diff(y, x) end proc:

# Maple's taylor()/series() have no series knowledge of the inert
# wrappers above (they only carry diff rules), so expanding an
# expression that contains them -- especially around a removable
# singularity -- fails with "does not have a taylor expansion".
# to_elementary() substitutes each wrapper by its Maple-native
# equivalent for use *inside* a taylor/series call: the expansion is
# purely symbolic there, so the numerical-stability reason for the
# wrappers does not apply, and the resulting polynomial is exact.
to_elementary := proc(expr)
  eval(expr, [
    xc_expm1         = (q -> exp(q) - 1),
    xc_log1p         = (q -> ln(1 + q)),
    xc_asinh         = (q -> arcsinh(q)),
    xc_atanh         = (q -> arctanh(q)),
    xc_x_minus_log1p = (q -> q - ln(1 + q)),
    my_dilog         = (q -> polylog(2, q)),
    m_recexp         = (q -> exp(-1/q)),
    m_one_minus_recexp = (q -> 1 - exp(-1/q)),
    xc_erfcx         = (q -> exp(q^2)*erfc(q)),
    xc_E1_scaled     = (q -> exp(q)*Ei(1, q))
  ])
end proc:

# The function exp(-1/x) is used in some functionals but it is ill-behaved for x -> 0
m_recexp := x -> my_piecewise3(x <= -1/log(XC_EPSILON), 0, exp(-1/m_max(-1/log(XC_EPSILON),x))):

# 1 - exp(-1/x), the complement of m_recexp.  This is the numerically
# stable way to write factors of the form g = 1 - exp(-b/sqrt(s))
# (SCAN-type non-uniform-scaling / iso-orbital corrections, e.g. COACH
# exchange NUSC and LAK exchange): it combines BOTH safeguards that the
# two naive forms each only get half of --
#   * the guard at x -> 0 (small argument): the piecewise returns the
#     constant 1, so the x -> 0 limit (g -> 1) carries no 0*inf = NaN
#     into the derivatives, exactly like m_recexp's 0 branch;
#   * the expm1 at x -> infinity (large argument): -xc_expm1(-1/x) keeps
#     the small-g limit (1 - exp(-small)) cancellation-free, which the
#     plain `1 - m_recexp(x)` subtraction loses.
# Prefer this over `1 - m_recexp(x)` wherever the g (not the 1 - g) form
# is needed.
m_one_minus_recexp := x -> my_piecewise3(x <= -1/log(XC_EPSILON), 1, -xc_expm1(-1/m_max(-1/log(XC_EPSILON),x))):

# a series of useful definitions

M_C         := 137.0359996287515: (* speed of light *)

X2S         := 1/(2*(6*Pi^2)^(1/3)):
XT2S        := 1/(2*(3*Pi^2)^(1/3)): (* total density gradient to s *)
X2S_2D      := 1/(2*(4*Pi)^(1/2)):

X_FACTOR_C    := 3/8*(3/Pi)^(1/3)*4^(2/3):
X_FACTOR_2D_C := 8/(3*sqrt(Pi)):
K_FACTOR_C    := 3/10*(6*Pi^2)^(2/3):

MU_GE       := 10/81:
MU_PBE      := 0.06672455060314922*(Pi^2)/3:
KAPPA_PBE   := 0.8040:

# generic conversion functions

$ifdef xc_dimensions_1d
DIMENSIONS   := 1:
RS_FACTOR    := 1/2:
$elif xc_dimensions_2d
DIMENSIONS   := 2:
RS_FACTOR    := 1/sqrt(Pi):
LDA_X_FACTOR := -X_FACTOR_2D_C:
$else
DIMENSIONS   := 3:
RS_FACTOR    := (3/(4*Pi))^(1/3):
LDA_X_FACTOR := -X_FACTOR_C:
$endif

r_ws       := n  -> RS_FACTOR/n^(1/DIMENSIONS):
n_total    := rs -> (RS_FACTOR/rs)^DIMENSIONS:

n_spin     := (rs, z) -> simplify((1 + z)*n_total(rs)/2):
sigma_spin := (rs, z, xs) -> simplify(xs^2*n_spin(rs, z)^(8/3)):
# total reduced kinetic energy, tau_total/rho_total^(5/3), assembled from
# the per-spin reduced values ts0, ts1 via the spin-scaling
# ((1 +- z)/2)^(5/3) = rho_s/rho_total to the 5/3.  That factor is
# non-analytic at full polarization: its second z-derivative diverges like
# (1 +- z)^(-1/3) as z -> -+1, so d^2/drho^2 of any functional built on
# t_total blows up to inf and the codegen's products give 0*inf = NaN at an
# empty spin channel.  Route the powers through opz_pow_n, which clamps
# 1 +- z away from 0 (value-identical above p_a_zeta_threshold, finite
# derivatives below it) -- this fixes the shared one-spin-zero v2rho2 NaN
# across the meta-GGA correlations.
t_total    := (z, ts0, ts1) ->
  (ts0*opz_pow_n(z, 5/3) + ts1*opz_pow_n(-z, 5/3))/2^(5/3):
u_total    := (z, us0, us1) -> t_total(z, us0, us1):

# useful formulas that enter several functionals follow

# von Weizsäcker term. Takes the SQUARED total reduced gradient xt2 = xt^2, not
# xt: xt2 = sigma_total/rho_total^(8/3) is rational in sigma, so a functional
# linear in the vW term (lp90, zlp, cs) has v2sigma2 exactly zero and stays
# cancellation-free. Passing xt would route the sigma chain rule through
# d(sqrt(sigma)), whose 1/sigma terms cancel only in exact arithmetic and blow up
# at a small gradient. Callers pass xt^2 across their (opaque helper) boundary.
t_vw := (z, xt2, us0, us1) -> (xt2 - u_total(z, us0, us1))/8:

# Screening for extreme values of zeta
z_thr := z -> my_piecewise5(
  1 + z <= p_a_zeta_threshold, p_a_zeta_threshold - 1,
  1 - z <= p_a_zeta_threshold, 1 - p_a_zeta_threshold,
  z):

opz_pow_n := (z, n) -> my_piecewise3(1 + z <= p_a_zeta_threshold, (p_a_zeta_threshold)^n, (1 + z)^n):

# 1 - z^n for a positive integer n, written in cancellation-free form
# via the cyclotomic / geometric-series identity
#   1 - z^n = (1 - z) * (1 + z + z^2 + ... + z^(n-1))
# and for even n the stronger factorisation
#   1 - z^(2m) = (1 - z)(1 + z) * (1 + z^2 + z^4 + ... + z^(2m-2)).
# The point of this helper is the even-n case: with z in [-1, 1] both
# (1 - z) and (1 + z) can be small (at z = +1 and z = -1 respectively),
# and only the (1 - z)(1 + z) decomposition keeps both boundaries
# cancellation-free. The odd-n branch is provided for completeness;
# there 1 - z^n at z = -1 equals 2 (no cancellation), so only z = +1
# is rescued by the (1 - z) factor.
# Maple evaluates the `add` at parse time, so the emitted C is the
# fully spelled-out polynomial -- no runtime loop.
one_minus_z_pow_n := proc(z, n) local k;
  if not type(n, integer) or n < 1 then
    error "n must be a positive integer; got %1", n
  end if;
  if type(n, even) then
    (1 - z)*(1 + z) * add(z^(2*k), k = 0..(n-2)/2)
  else
    (1 - z) * add(z^k, k = 0..n-1)
  end if
end proc:

# (1 + z)^n - 1 via expm1(n*log1p(z)), cancellation-free near z = 0.  The
# m_max clamps the log1p argument at the piecewise boundary: it only acts
# where the constant branch is already selected (value unchanged), but
# stops maple2c's CSE from hoisting the unselected log1p(-1) = -inf and
# 1/(1+z) = inf (at full polarization z -> -1) into the derivatives -- the
# shared meta-GGA full-polarization v2rho2 NaN via the PW92 f_zeta.
opz_pow_n_m1 := (z, n) -> my_piecewise3(1 + z <= p_a_zeta_threshold, (p_a_zeta_threshold)^n - 1, xc_expm1(n*xc_log1p(m_max(z, p_a_zeta_threshold - 1)))):

# See Eq. (9) of Perdew1992_13244. Written as the sum of two
# (1 +- z)^n - 1 contributions so f_zeta(0) = 0 is exact in
# floating point (no cancellation against the `- 2`).
# KEEP IN SYNC: f_zeta and one_minus_f_zeta.  f_zeta hits 1 at
# z = +- 1, so the direct 1 - f_zeta form is the 1 - close-to-1
# cancellation at full spin polarization.  Algebraic identity:
#   (1 + z)^a = 2^a * (1 + opz_pow_n_m1((z-1)/2, a))
#   (1 - z)^a = 2^a * (1 + opz_pow_n_m1((-z-1)/2, a))
# so
#   1 - f_zeta(z)
#     = (2^(4/3) - (1+z)^(4/3) - (1-z)^(4/3)) / (2^(4/3) - 2)
#     = -2^(4/3) * (1 + opz_pow_n_m1((z-1)/2, 4/3)
#                     + opz_pow_n_m1((-z-1)/2, 4/3))
#       / (2^(4/3) - 2).
# The halved-argument opz_pow_n_m1 helpers stay precise as their
# arguments approach 0 (corresponding to z = +- 1), eliminating
# the cancellation.
f_zeta           := z -> (opz_pow_n_m1(z,4/3) + opz_pow_n_m1(-z,4/3))/(2^(4/3) - 2):
one_minus_f_zeta := z -> -2^(4/3)
  * (1 + opz_pow_n_m1((z-1)/2, 4/3) + opz_pow_n_m1((-z-1)/2, 4/3))
  /(2^(4/3) - 2):
# f_zeta_2d and mphi are derived from their cancellation-free `_m1`
# primitives. Any future derived functional that wants to override the
# spin-scaling function MUST override the `_m1` form -- redefining
# only f_zeta_2d / mphi leaves the `_m1` companion stale, which would
# silently break any consumer reaching for `_m1` (e.g. lda_c_2d_amgb's
# ex6 expansion uses f_zeta_2d_m1 directly to avoid the
# 1 + small - 1 cancellation around z = 0).
f_zeta_2d_m1 := z -> (opz_pow_n_m1(z,3/2) + opz_pow_n_m1(-z,3/2))/2:
f_zeta_2d    := z -> 1 + f_zeta_2d_m1(z):

mphi_m1 := z -> (opz_pow_n_m1(z,2/3) + opz_pow_n_m1(-z,2/3))/2:
mphi    := z -> 1 + mphi_m1(z):
tt   := (rs, z, xt) -> xt/(4*2^(1/3)*mphi(z)*sqrt(rs)):

# in the paper it is beta_a = 0.066725
beta_Hu_Langreth := rs -> 0.066724550603149220*(1 + 0.1*rs)/(1 + 0.1778*rs):

# Generate exchange and kinetic functionals from the expression for the
# enhancement factor
lda_x_spin := (rs, z) -> simplify(LDA_X_FACTOR*opz_pow_n(z,1 + 1/DIMENSIONS)*2^(-1-1/DIMENSIONS)*(RS_FACTOR/rs)):
lda_k_spin := (rs, z) -> simplify(K_FACTOR_C*opz_pow_n(z,5/3)*2^(-5/3)*(RS_FACTOR/rs)^2):

# Separable LDA exchange (both screened channels). No enhancement -- LDA has no
# reduced gradient -- so unlike gga/mgga_exchange it takes no func.
lda_exchange := (rs, z) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs,  z))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, -z)):

# Screen out small densities as well as the zero component from fully spin polarized densities due to terms of the form (1+z)^{-n}
screen_dens := (rs, z) -> (n_spin(rs,  z) <= p_a_dens_threshold):

# For most functionals zeta screening occurs inside the funcitonal,
#  but for B88 and B94 correlation need to screen out also outside
screen_dens_zeta := (rs, z) -> screen_dens(rs, z) or (1 + z <= p_a_zeta_threshold):

# non-separable GGA exchange
gga_exchange_nsp := (func, rs, z, xs0, xs1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs, z_thr( z))*func(rs, z_thr( z), xs0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, z_thr(-z))*func(rs, z_thr(-z), xs1)):
# GGA exchange
gga_exchange := (func, rs, z, xs0, xs1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs, z_thr( z))*func(xs0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, z_thr(-z))*func(xs1)):
# GGA kinetic energy
gga_kinetic := (func, rs, z, xs0, xs1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_k_spin(rs, z_thr( z))*func(xs0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_k_spin(rs, z_thr(-z))*func(xs1)):

# GGA exchange / kinetic energy with the enhancement expressed in the SQUARE of
# the reduced gradient: func receives xs^2 instead of xs.  For a functional that
# depends on the reduced gradient only through xs^2 (the physical
# gradient-expansion variable) this keeps every sigma derivative
# cancellation-free: the kernel substitutes xs = sqrt(sigma)/rho^k, so
# xs^2 = sigma/rho^(2k) is rational in sigma and the opaque enhancement is
# differentiated with respect to it, so no half-integer power of sigma
# (1/sqrt(sigma), 1/sigma^(3/2), ...) enters.  Feeding xs itself routes the chain
# rule through d(sqrt(sigma)) and the resulting 1/sigma^(k/2) terms cancel only
# in exact arithmetic, destroying all accuracy in the 2nd and higher derivatives
# at low density.
gga_exchange_p := (func, rs, z, xs0, xs1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs, z_thr( z))*func(xs0^2))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, z_thr(-z))*func(xs1^2)):
gga_kinetic_p := (func, rs, z, xs0, xs1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_k_spin(rs, z_thr( z))*func(xs0^2))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_k_spin(rs, z_thr(-z))*func(xs1^2)):
# non-separable variant (func also receives rs, z)
gga_exchange_nsp_p := (func, rs, z, xs0, xs1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs, z_thr( z))*func(rs, z_thr( z), xs0^2))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, z_thr(-z))*func(rs, z_thr(-z), xs1^2)):

# non-separable meta-GGA exchange
mgga_exchange_nsp := (func, rs, z, xs0, xs1, u0, u1, t0, t1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs, z_thr( z))*func(rs, z_thr( z), xs0, u0, t0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, z_thr(-z))*func(rs, z_thr(-z), xs1, u1, t1)):
# meta-GGA exchange
mgga_exchange := (func, rs, z, xs0, xs1, u0, u1, t0, t1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs, z_thr( z))*func(xs0, u0, t0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, z_thr(-z))*func(xs1, u1, t1)):
# meta-GGA kinetic energy
mgga_kinetic := (func, rs, z, xs0, xs1, u0, u1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_k_spin(rs, z_thr( z))*func(xs0, u0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_k_spin(rs, z_thr(-z))*func(xs1, u1)):

# meta-GGA exchange / kinetic energy with the reduced gradient passed as the
# squared value p = mgga_p(xs) = s^2 instead of xs.  p = X2S^2*sigma/rho^(8/3)
# is rational in sigma (the sqrt folds), so the opaque enhancement is
# differentiated with respect to it and the sigma derivatives stay
# cancellation-free (see gga_exchange_p).  Laplacian u and tau t carry no sqrt
# and are passed unchanged.  Use for functionals even in the reduced gradient.
mgga_exchange_p := (func, rs, z, xs0, xs1, u0, u1, t0, t1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_spin(rs, z_thr( z))*func(mgga_p(xs0), u0, t0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_spin(rs, z_thr(-z))*func(mgga_p(xs1), u1, t1)):
mgga_kinetic_p := (func, rs, z, xs0, xs1, u0, u1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_k_spin(rs, z_thr( z))*func(mgga_p(xs0), u0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_k_spin(rs, z_thr(-z))*func(mgga_p(xs1), u1)):

# Range-separated (erf-attenuated) exchange.  The per-channel short-range LDA
# base lda_x_erf_spin(rs, z) is opz_pow_n-safe at full polarization, so unlike
# the hand-rolled (1+-z)/2 * lda_x_erf_spin(rs*(2/(1-+z))^(1/3), 1) form it has
# no spurious 1/(1-+z) pole.  Requires lda_x_erf.mpl to be included.
gga_exchange_erf := (func, rs, z, xs0, xs1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_erf_spin(rs, z_thr( z))*func(xs0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_erf_spin(rs, z_thr(-z))*func(xs1)):
mgga_exchange_erf := (func, rs, z, xs0, xs1, u0, u1, t0, t1) ->
  + my_piecewise3(screen_dens(rs,  z), 0, lda_x_erf_spin(rs, z_thr( z))*func(xs0, u0, t0))
  + my_piecewise3(screen_dens(rs, -z), 0, lda_x_erf_spin(rs, z_thr(-z))*func(xs1, u1, t1)):

# This is the Stoll decomposition in our language
lda_stoll_par  := (lda_func, rs, z) ->
  my_piecewise3(screen_dens_zeta(rs,  z), 0, opz_pow_n(z, 1)/2 * lda_func(rs*2^(1/3)*opz_pow_n(z, -1/3), 1)):

lda_stoll_perp := (lda_func, rs, z) ->
  + lda_func(rs, z)
  - lda_stoll_par(lda_func, rs,  z)
  - lda_stoll_par(lda_func, rs, -z):

gga_stoll_par  := (gga_func, rs, z, xs, spin) ->
  my_piecewise3(screen_dens_zeta(rs, z), 0,
    gga_func(rs*2^(1/3)*opz_pow_n(z,-1/3), spin, xs, xs*(1 + spin)/2, xs*(1 - spin)/2) * opz_pow_n(z,1)/2):

# Curvature of the Fermi hole (without the current term).
# Single-fraction form is cancellation-free at the iso-orbital limit
# xs^2/(8*ts) -> 1 where the direct 1 - close-to-1 cancels.
Fermi_D := (xs, ts) -> (8*ts - xs^2)/(8*ts):

# correction to Fermi_D similar to the one found in
#  JCP 127, 214103 (2007); doi: https://doi.org/10.1063/1.2800011
Fermi_D_corrected := (xs, ts) -> Fermi_D(xs, ts) * (-xc_expm1(-4*ts^2/params_a_Fermi_D_cnst^2)):

# Becke function used in several correlation functionals
b88_R_F := (f_x, rs, z, xs) -> 1/(2*X_FACTOR_C*n_spin(rs, z)^(1/3)*f_x(xs)):
b88_zss := (css, f_x, rs, z, xs) -> 2*css*b88_R_F(f_x, rs, z, xs):
b88_zab := (cab, f_x, rs, z, xs0, xs1) -> cab*(
  + my_piecewise3(screen_dens(rs,  z), 0, b88_R_F(f_x, rs, z_thr( z), xs0))
  + my_piecewise3(screen_dens(rs, -z), 0, b88_R_F(f_x, rs, z_thr(-z), xs1))
  ):

# The meta-GGA version
b94_R_F := (f_x, rs, z, xs, us, ts) -> 1/(2*X_FACTOR_C*n_spin(rs, z)^(1/3)*f_x(xs,us,ts)):
b94_zss := (css, f_x, rs, z, xs, us, ts) -> 2*css*b94_R_F(f_x, rs, z, xs, us, ts):
b94_zab := (cab, f_x, rs, z, xs0, xs1, us0, us1, ts0, ts1) -> cab*(
  + my_piecewise3(screen_dens(rs,  z), 0, b94_R_F(f_x, rs, z_thr( z), xs0, us0, ts0))
  + my_piecewise3(screen_dens(rs, -z), 0, b94_R_F(f_x, rs, z_thr(-z), xs1, us1, ts1))
  ):

# Power series often used in mggas
mgga_w := t -> (K_FACTOR_C - t)/(K_FACTOR_C + t):
# shared reduced density gradient s = X2S x, its square p = s^2,
# and reduced Laplacian q = X2S^2 u
gga_s := x -> X2S*x:
gga_s_total := xt -> XT2S*xt:
mgga_p := x -> gga_s(x)^2:
mgga_q := u -> X2S^2*u:
mgga_series_w := (a, n, t) -> add(a[i]*mgga_w(t)^(i-1), i=1..n):

# Used in screened functionals
kF := (rs, z) -> (3*Pi^2)^(1/3) * opz_pow_n(z,1/3) * RS_FACTOR/rs:
nu := (rs, z) -> p_a_cam_omega/kF(rs, z):

(* Precision-relative floor for a vanishing reduced quantity that then
   feeds a log / division / sqrt (so it must stay strictly positive, with
   enough digits left after any cancellation, yet large enough that its
   inverse powers in up to 4th derivatives do not overflow).  This
   replaces hard-coded ~1e-10 floors, which silently assume double
   precision and would not scale to higher precision (task #31):
   XC_EPSILON^(2/3) is ~3.7e-11 in double and shrinks with the working
   precision.  (1/floor^5 ~ 1e52 << DBL_MAX, so safe through 4th order.) *)
xc_reduced_floor := XC_EPSILON^(2/3):

(* meta-GGA iso-orbital indicator alpha = (tau - tau_W)/tau_unif, in
   libxc reduced units tau_W -> x^2/8, tau_unif -> K_FACTOR_C.  Arises in
   many functionals (TPSS-, SCAN-, MS-type, ...).  mgga_alpha_reg uses the
   regularized denominator K_FACTOR_C + eta*x^2/8 (the "l"/regularized
   variants).  These give the bare definition; a nonnegativity safeguard
   (e.g. m_max(0, .)) or a magnitude clamp is the caller's choice, since
   different functionals need different guards. *)
mgga_alpha     := (x, t)      -> (t - x^2/8)/K_FACTOR_C:
mgga_alpha_reg := (x, t, eta) -> (t - x^2/8)/(K_FACTOR_C + eta*x^2/8):

(* Deorbitalized counterparts.  A kinetic energy functional written as an
   enhancement over the von Weizsaecker limit, tau_ked = tau_W + tau_unif*a,
   yields the iso-orbital indicator directly as `a`: since K_FACTOR_C*f_W(x) is
   identically x^2/8, the tau_W that mgga_alpha subtracts is exactly the one the
   KED added, and the two cancel analytically.  Passing `a` therefore avoids
   forming tau and subtracting tau_W back off it -- a cancellation that costs
   ~log10(tau/alpha) digits and grows without bound in the density tail, where
   tau converges onto tau_W.  mgga_alpha_deorb is the identity, and exists so
   that the substitution is stated rather than implied. *)
mgga_alpha_deorb     := (a)         -> a:
mgga_alpha_deorb_reg := (x, a, eta) -> K_FACTOR_C*a/(K_FACTOR_C + eta*x^2/8):

(* The correlation counterpart.  mgga_alpha_total measures the *total* tau
   against the von Weizsaecker term of the *total* density, so substituting a
   per-spin KED leaves a residue: t_total is linear in its last two arguments,
   and K_FACTOR_C*f_W(xs) = xs^2/8, hence

     t_total(z, ts0, ts1) - xt^2/8
        = [t_total(z, xs0^2, xs1^2) - xt^2]/8 + K_FACTOR_C*t_total(z, a0, a1).

   The first bracket is sum_s |grad rho_s|^2/rho_s - |grad rho|^2/rho, which is
   |rho_1*grad rho_0 - rho_0*grad rho_1|^2/(rho_0*rho_1*rho) >= 0 and vanishes
   identically when the spin densities are proportional (in particular for a
   spin-unrestricted density, where it collapses symbolically).  The dominant
   tau-against-tau_W cancellation is gone; what remains is a difference of two
   von Weizsaecker terms, which is genuinely small rather than a large-minus-
   large. *)
mgga_alpha_total_deorb := (z, xt, xs0, xs1, a0, a1) ->
  ((t_total(z, xs0^2, xs1^2) - xt^2)/8 + K_FACTOR_C*t_total(z, a0, a1))
  /(K_FACTOR_C*t_total(z, 1, 1)):

(* ... and with the regularized denominator (the r2SCAN family). *)
mgga_alpha_total_deorb_reg := (z, xt, xs0, xs1, a0, a1, eta) ->
  ((t_total(z, xs0^2, xs1^2) - xt^2)/8 + K_FACTOR_C*t_total(z, a0, a1))
  /(K_FACTOR_C*t_total(z, 1, 1) + eta*xt^2/8):
(* nonnegativity-safeguarded form (LAK/TASK family): (t/K)*(1 - x^2/(8t))
   = mgga_alpha, but with the Fermi-hole-curvature factor floored so alpha
   stays positive when x^2/8 > t.  (Floor is the precision-relative
   xc_reduced_floor.)
   TODO: this in-functional floor enforces the same constraint as the
   harness XC_FLAGS_ENFORCE_FHC flag (which clamps sigma to 8*rho*tau so
   that 1 - x^2/(8t) >= 0; used e.g. by mgga_x_sa_tpss).  Compare the two
   approaches and pick one consistently -- ideally route all alpha >= 0
   needs through the FHC enforcement rather than per-functional floors. *)
mgga_alpha_safe := (x, t) -> (t/K_FACTOR_C)*m_max((8*t - x^2)/(8*t), xc_reduced_floor):

(* Spin-resolved (total) form used by the meta-GGA correlations: tau and
   tau_unif are summed over spin via t_total, with the reduced total
   gradient xt.  mgga_alpha_total_reg adds the regularized denominator. *)
mgga_alpha_total     := (z, xt, ts0, ts1)      -> (t_total(z, ts0, ts1) - xt^2/8)/(K_FACTOR_C*t_total(z, 1, 1)):
mgga_alpha_total_reg := (z, xt, ts0, ts1, eta) -> (t_total(z, ts0, ts1) - xt^2/8)/(K_FACTOR_C*t_total(z, 1, 1) + eta*xt^2/8):

(* B97-type bounded reduced-gradient variable u = gamma s^2/(1 + gamma s^2)
   in [0, 1).  Shared by the B97 family (b97, b97mv), MN12, tau-HCTH, N12,
   COACH; each binds its own gamma.  Takes the SQUARED reduced gradient x2
   (= s^2), so the opaque boundary is rational in sigma and derivatives do
   not chain through sqrt(sigma) (cf. t_vw, mgga_p). *)
b97_u := (mgamma, x2) -> mgamma*x2/(1 + mgamma*x2):


(* Maple 2020 has a bug where series aren't computed to the order requested; this circumvents that *)
padding_order := 30:

(* Cap polynomial expansion to given order (throws out the padded terms, if any) *)
throw_out_large_n := proc(X,n) select(t -> abs(degree(t,{b}))<=n, X); end proc:

(* Function that makes f(a) smooth for a->infty *)
enforce_smooth_lr := proc(f, a, a_cutoff, expansion_order);
  (* Calculate large-a expansion *)
  f_large := a -> eval(throw_out_large_n(convert(series(f(b), b=infinity, expansion_order+padding_order), polynom), expansion_order), b=a):
  (* Return the series expansion for large a; also remove any numerical overflows from the original branch  *)
  my_piecewise3(a >= a_cutoff, f_large(m_max(a, a_cutoff)), f(m_min(a, a_cutoff))):
end proc:
