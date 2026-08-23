/*
 Copyright (C) 2026 Susi Lehtola
 Copyright (C) 2009 M.A.L. Marques (previous QUADPACK-based version)

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/*
  Adaptive numerical quadrature via the tanh-sinh (double-exponential)
  rule of Takahasi & Mori, "Double exponential formulas for numerical
  integration" (Publ. RIMS Kyoto, 1974). See also Bailey, Jeyabalan &
  Li, "A comparison of three high-precision quadrature schemes"
  (Experimental Mathematics 14:317, 2005) for a modern treatment.

  Tanh-sinh transforms x in [a, b] to t in R via

      x(t) = (a + b)/2 + (b - a)/2 * tanh(pi/2 * sinh(t))                  ,

  whose integrand decays double-exponentially as |t| -> infty. The
  trapezoidal rule in t therefore converges *exponentially* in the
  number of evaluations for smooth integrands and handles algebraic
  endpoint singularities naturally. For the libxc callers (FT97,
  FD-LB94, 1D-exponential, 1D-soft) -- all smooth finite-domain
  integrands -- a target precision of 2*XC_EPSILON is reached in
  O(50-100) evaluations.

  Refinement uses the standard halving identity for tanh-sinh: at
  level n+1 the abscissae at even k duplicate level n's, so

      T(h/2) = T(h)/2 + (h/2) * sum_{k odd} w(k h/2) * f(x(k h/2))

  and only the new odd-k contributions need a fresh f evaluation.

  Replaces an earlier QUADPACK DQAGSE-based implementation (~1100
  lines, adapted from the R Project) whose epsabs/epsrel defaults
  were 1e-10 -- six orders looser than double precision can
  represent. The new code targets 2*XC_EPSILON throughout.
*/

#include "util.h"

/* Maximum levels of refinement. h_min = 2^-MAX_LEVELS; for the
   integrands libxc passes, convergence to 2*XC_EPSILON typically
   reaches level 6-8, so 12 is generous. */
#define XC_TANH_SINH_MAX_LEVELS 12

/* The half-width of the trapezoidal grid in t is the largest value
   for which tanh(pi/2 * sinh(t_max)) is still strictly less than 1 in
   the working floating-point precision. The condition

       1 - tanh(pi/2 * sinh(t)) > XC_EPSILON
   <=> exp(-pi * sinh(t)) > XC_EPSILON
   <=> t < asinh(-log(XC_EPSILON) / pi)

   gives t_max ~= 3.1 in IEEE double, ~= 2.3 in float, ~= 3.4 in
   long double, etc. Beyond t_max the abscissa rounds to exactly a
   or b and libxc integrands like FT97's xc_E1_scaled(x^2) would
   abort. The double-exponential weight pi/2 * cosh(t) /
   cosh^2(pi/2 * sinh(t)) is itself below XC_EPSILON well before
   t_max, so the missing tail contributes nothing meaningful.

   asinh(-log(eps)/pi) is computed once at function entry; modern
   compilers fold the constant in -O2 builds. */
#define XC_TANH_SINH_T_MAX  (asinh(-log(XC_EPSILON) / M_PI))

GPU_FUNCTION double xc_integrate(integr_fn func, const void *ex, double a, double b)
{
  const double tol = 2.0 * XC_EPSILON;
  const double pi_2 = M_PI / 2.0;
  const double mid = 0.5 * (a + b);
  const double rad = 0.5 * (b - a);

  double h, T_prev, T;
  double pts[2];
  int level, k;

  if(rad == 0.0)
    return 0.0;

  /* Level 0: h = 1. The k = 0 abscissa lies at t = 0, x = mid, with
     weight pi/2. */
  h = 1.0;
  pts[0] = mid;
  func(pts, 1, ex);
  T = pi_2 * pts[0];

  /* k != 0 contributions at level 0. The transform is symmetric in
     t, so we evaluate +k and -k together. */
  for(k = 1;; k++) {
    double t = k * h;
    double sh, ch, psh, cpsh, w, xt;
    if(t > XC_TANH_SINH_T_MAX)
      break;
    sh = sinh(t);
    ch = cosh(t);
    psh = pi_2 * sh;
    cpsh = cosh(psh);
    w = pi_2 * ch / (cpsh * cpsh);
    xt = rad * tanh(psh);
    pts[0] = mid + xt;
    pts[1] = mid - xt;
    func(pts, 2, ex);
    T += w * (pts[0] + pts[1]);
    /* tail check: once the weight is well below relative tolerance,
       further terms cannot move the integral inside the target. */
    if(w * (fabs(pts[0]) + fabs(pts[1])) <= tol * (1.0 + fabs(T)))
      break;
  }
  T *= h;
  T_prev = T;

  /* Refinement: halve h until the result stops moving. */
  for(level = 1; level <= XC_TANH_SINH_MAX_LEVELS; level++) {
    double new_terms = 0.0;
    double scale;
    h *= 0.5;
    for(k = 1;; k += 2) {
      double t = k * h;
      double sh, ch, psh, cpsh, w, xt;
      if(t > XC_TANH_SINH_T_MAX)
        break;
      sh = sinh(t);
      ch = cosh(t);
      psh = pi_2 * sh;
      cpsh = cosh(psh);
      w = pi_2 * ch / (cpsh * cpsh);
      xt = rad * tanh(psh);
      pts[0] = mid + xt;
      pts[1] = mid - xt;
      func(pts, 2, ex);
      new_terms += w * (pts[0] + pts[1]);
      if(w * (fabs(pts[0]) + fabs(pts[1])) <= tol * (1.0 + fabs(T)))
        break;
    }
    T = 0.5 * T + h * new_terms;
    scale = 1.0 + fabs(T) + fabs(T_prev);
    /* Tanh-sinh converges quadratically in the log of the error per
       halving level, so the *next* level's error is approximately
       (T - T_prev)^2 / scale, i.e. we should not declare convergence
       at |dT| ~ tol*scale but at |dT| ~ sqrt(tol*scale*scale) =
       scale*sqrt(tol). Stop instead when the squared-difference
       extrapolation predicts an error well below the target. */
    if(level >= 2
       && fabs(T - T_prev) * fabs(T - T_prev)
            <= tol * scale * scale)
      return rad * T;
    T_prev = T;
  }

  /* Did not meet the requested tolerance within the refinement
     budget; return the final estimate (still much better than the
     1e-10 the old QUADPACK defaults asked for). */
  return rad * T;
}
