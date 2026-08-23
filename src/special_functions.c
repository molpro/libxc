/*
 Copyright (C) 2006-2007 M.A.L. Marques
 Copyright (C) 2019 X. Andrade

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

/*
  Lambert W function.
  adapted from the Fortran code of Rickard Armiento

  Corless, Gonnet, Hare, Jeffrey, and Knuth (1996),
         Adv. in Comp. Math. 5(4):329-359.
*/

GPU_FUNCTION double LambertW(double z)
{
  double w;
  int i;

  /* Sanity check - function is only defined for z >= -1/e */
  if(z + 1.0/M_E < -10*XC_EPSILON) {
#ifndef HAVE_CUDA
    fprintf(stderr,"Error - Lambert function called with argument z = %e.\n",z);
    abort();
#endif
  } else if(z < -1.0/M_E)
    /* Value of W(x) at x=-1/e is -1 */
    return -1.0;

  /* If z is small, go with the first terms of the power expansion
     (if z smaller than cube root of epsilon, z^4 will be zero to
     machine precision).
   */
  if(fabs(z) < CBRT(XC_EPSILON))
    return z - z*z + 1.5*z*z*z;

  /* Initial guess. */
  if(z <= -0.3140862435046707) { /* Point where sqrt and Taylor polynomials match */
    /* Near the branching point: first terms in eqn (4.22) */
    w = sqrt(2.0*M_E*z + 2.0) - 1.0;

  } else if(z <= 1.149876485041417) { /* Point where Taylor and log expansion match */

    /* Taylor series around origin */
    w = z - z*z + 1.5*z*z*z;

  } else {
    /* Asymptotic expansion */
    double lnz = log(z);

    w = lnz - log(lnz);
  }

  /* Find result through iteration. Halley converges cubically, so
     even from a modest initial guess full floating-point precision
     is reached in a handful of steps; the loop budget is generous.
     Termination at 2*XC_EPSILON*(1+|w|) rather than the historical
     100*XC_EPSILON gets us the last six bits at the cost of (at
     most) one extra Halley step. */
  for(i=0; i<20; i++){
    double expmw, dw;
    expmw = exp(-w);

    /* Halley's equation, (5.9) in Corless et al */
    if( w != -1.0 )
      dw = - (w - z*expmw) / ( w + 1.0 - (w + 2.0)/(2.0*w + 2.0)*(w - z*expmw) );
    else
      dw = 0.0;

    w += dw;
    if(fabs(dw) < 2.0*XC_EPSILON*(1.0 + fabs(w)))
      return w;
  }

  /* Convergence to the tight tolerance is not always attainable in the
     immediate neighbourhood of the branch point z -> -1/e.  There W(z)
     -> -1 and the argument z, held as a double, no longer pins down
     1 + e*z to full relative precision, so neither Halley's correction
     nor any other scheme operating on z can reach the last bits; the
     Halley denominator w + 1 - ... also nearly cancels.  Rather than
     discard the iterate we return the best one obtained, which is still
     accurate to ~10 significant digits of W in this region (the
     input-conditioning limit).  Callers that need full precision in
     W(z)+1 near the branch point should work in the 1 + e*z variable
     instead (cf. the log1p/expm1 idiom). */
  return w;
}

/* LambertW W(z) and its derivatives out[0..n]. Rather than differentiate the
   implicit relation, reverse the trivial series of the inverse z(w) = w e^w
   (z^(k)(w) = e^w (k+w), coefficients positive for w > -1, so no cancellation):
   out[0] = W(z), then series-reversion gives the derivatives. Emitted by the AD
   codegen (jet_compose) as an isolated helper. */
GPU_FUNCTION
void xc_lambertw_jet(double z, int n, double *out)
{
  double w = LambertW(z), ew, a1, a2, a3, a4;
  out[0] = w;
  if (n < 1) return;
  ew = exp(w);
  a1 = ew * (1.0 + w);            /* a_k = coeff of (w-w0)^k in z(w) = e^w(k+w)/k! */
  out[1] = 1.0 / a1;             /* W'(z) = b_1 */
  if (n >= 2) {
    a2 = ew * (2.0 + w) / 2.0;
    out[2] = 2.0 * (-a2 / (a1 * a1 * a1));
    if (n >= 3) {
      a3 = ew * (3.0 + w) / 6.0;
      out[3] = 6.0 * (2.0 * a2 * a2 - a1 * a3) / pow(a1, 5);
      if (n >= 4) {
        a4 = ew * (4.0 + w) / 24.0;
        out[4] = 24.0 * (5.0 * a1 * a2 * a3 - a1 * a1 * a4 - 5.0 * a2 * a2 * a2)
                 / pow(a1, 7);
      }
    }
  }
}

GPU_FUNCTION double xc_lambertw_d1(double z){double o[2]; xc_lambertw_jet(z,1,o); return o[1];}
GPU_FUNCTION double xc_lambertw_d2(double z){double o[3]; xc_lambertw_jet(z,2,o); return o[2];}
GPU_FUNCTION double xc_lambertw_d3(double z){double o[4]; xc_lambertw_jet(z,3,o); return o[3];}
GPU_FUNCTION double xc_lambertw_d4(double z){double o[5]; xc_lambertw_jet(z,4,o); return o[4];}

/*
  Compute the dilogarithm, a form of spence-s function.

  based on the SLATEC routine by W. Fullerton
*/

GPU_DATA
static const double pi26 = 1.644934066848226436472415166646025189219;

GPU_DATA
static const double spencs[38] =
  {
    +.1527365598892405872946684910028e+0,
    +.8169658058051014403501838185271e-1,
    +.5814157140778730872977350641182e-2,
    +.5371619814541527542247889005319e-3,
    +.5724704675185826233210603054782e-4,
    +.6674546121649336343607835438589e-5,
    +.8276467339715676981584391689011e-6,
    +.1073315673030678951270005873354e-6,
    +.1440077294303239402334590331513e-7,
    +.1984442029965906367898877139608e-8,
    +.2794005822163638720201994821615e-9,
    +.4003991310883311823072580445908e-10,
    +.5823462892044638471368135835757e-11,
    +.8576708692638689278097914771224e-12,
    +.1276862586280193045989483033433e-12,
    +.1918826209042517081162380416062e-13,
    +.2907319206977138177795799719673e-14,
    +.4437112685276780462557473641745e-15,
    +.6815727787414599527867359135607e-16,
    +.1053017386015574429547019416644e-16,
    +.1635389806752377100051821734570e-17,
    +.2551852874940463932310901642581e-18,
    +.3999020621999360112770470379519e-19,
    +.6291501645216811876514149171199e-20,
    +.9933827435675677643803887752533e-21,
    +.1573679570749964816721763805866e-21,
    +.2500595316849476129369270954666e-22,
    +.3984740918383811139210663253333e-23,
    +.6366473210082843892691326293333e-24,
    +.1019674287239678367077061973333e-24,
    +.1636881058913518841111074133333e-25,
    +.2633310439417650117345279999999e-26,
    +.4244811560123976817224362666666e-27,
    +.6855411983680052916824746666666e-28,
    +.1109122433438056434018986666666e-28,
    +.1797431304999891457365333333333e-29,
    +.2917505845976095173290666666666e-30,
    +.4742646808928671061333333333333e-31
  };


GPU_FUNCTION
double xc_dilogarithm(const double x)
{
  const int nspenc = 38;
  double aux, dspenc;

  if (x > 2.0){
    aux = log(x);
    dspenc = 2.0*pi26 - 0.5*aux*aux;
    if(x < FLT_RADIX/DBL_EPSILON)
      dspenc -= (1.0 + xc_cheb_eval(4.0/x - 1.0, spencs, nspenc))/x;

  }else if (x > 1.0){
    aux = x - 1.0;
    dspenc = pi26 - 0.5*log(x)*log(aux*aux/x)
      + aux*(1.0 + xc_cheb_eval(4.0*aux/x-1.0, spencs, nspenc))/x;

  }else if (x > 0.5){
     if (x == 1.0)
       /* Li_2(1) = pi^2 / 6. The general branch below collapses to
          this analytically as x -> 1, but in floating point the
          log(1 - x) factor sends it to -inf; the guard short-
          circuits that and also fixes a real bug -- the original
          code left dspenc uninitialized in this branch and returned
          whatever was on the stack. */
       dspenc = pi26;
     else
       dspenc = pi26 - log(x)*log(1.0 - x)
	 - (1.0 - x)*(1.0 + xc_cheb_eval(4.0*(1.0 - x)-1.0, spencs, nspenc));

  }else if (x >= 0.0){
    dspenc = x*(1.0 + xc_cheb_eval(4.0*x - 1.0, spencs, nspenc));

  }else if (x > -1.0){
    aux = log(1.0 - x);
    dspenc = -0.5*aux*aux - x*(1.0+ xc_cheb_eval(4.0*x/(x-1.0)-1.0, spencs, nspenc))/(x-1.0);

  }else{
    aux = log(1.0 - x);
    dspenc = -pi26 - 0.50*aux*(2.00*log(-x) - aux);

    if (x > -FLT_RADIX/DBL_EPSILON)
      dspenc += (1.0 + xc_cheb_eval(4.0/(1.0-x)-1.0, spencs, nspenc))/(1.0 - x);
  }

  return dspenc;
}

/* dilog (Li_2) and its derivatives out[0..n]. The elementary derivative forms
   (Li_2' = -ln(1-q)/q, etc.) cancel near q=0 (removable singularities), so for
   the derivatives use the power series
     Li_2^(k)(q) = sum_{m>=k} [m!/(m-k)!]/m^2 * q^(m-k),
   which is cancellation-free for q in (0,1) (all-positive terms); the value
   out[0] uses the accurate xc_dilogarithm. Emitted by the AD codegen
   (jet_compose) so special-function derivatives are isolated helpers. */
GPU_FUNCTION
void xc_dilogarithm_jet(double q, int n, double *out)
{
  int k, m, j;
  out[0] = xc_dilogarithm(q);
  for (k = 1; k <= n; k++) {
    double s = 0.0, term, qp = 1.0;          /* qp = q^(m-k), starts q^0 */
    for (m = k; m < 100000; m++) {
      double coef = 1.0;
      for (j = 0; j < k; j++) coef *= (double)(m - j);   /* m!/(m-k)! */
      term = coef / ((double)m * (double)m) * qp;
      s += term;
      if (fabs(term) < 1e-17 * fabs(s) && m > k + 2) break;
      qp *= q;
    }
    out[k] = s;
  }
}

GPU_FUNCTION double xc_dilogarithm_d1(double q){double o[2]; xc_dilogarithm_jet(q,1,o); return o[1];}
GPU_FUNCTION double xc_dilogarithm_d2(double q){double o[3]; xc_dilogarithm_jet(q,2,o); return o[2];}
GPU_FUNCTION double xc_dilogarithm_d3(double q){double o[4]; xc_dilogarithm_jet(q,3,o); return o[3];}
GPU_FUNCTION double xc_dilogarithm_d4(double q){double o[5]; xc_dilogarithm_jet(q,4,o); return o[4];}

/* Becke-Roussel inverses x(Q) defined implicitly by G(x) = K/Q, with
   G(x) = P(x) e^{-2x/3}/(x-c). Thus x(Q) inverts Q(x) = K/G(x), NOT
   F(x) = K G(x): the derivatives are obtained by reversing the series of
   Q(x) = K/G(x) (built from the elementary factor jets and a reciprocal
   series -- no cancellation), given the root x0 from the existing solver.
   Reversing F instead would yield d x/d(K G) = 1/F'(x), off from d x/dQ by
   a chain factor -K^2/Q^2. Emitted by the AD codegen (jet_compose) as
   isolated helpers. */
static GPU_FUNCTION
void xc_br_jmul(const double *A, const double *B, double *C, int n) {
  int k, j;
  for (k = 0; k <= n; k++) {
    double s = 0.0;
    for (j = 0; j <= k; j++) s += A[j] * B[k - j];
    C[k] = s;
  }
}

static GPU_FUNCTION
void xc_br_reversion_jet(double x0, const double *P, double c, double K,
                         int n, double *out) {
  double E[5], R[5], A[5], G[5], H[5], FF[5], e0, t, dd, dk, a1, s;
  int k, j;
  out[0] = x0;
  if (n < 1) return;
  e0 = exp(-2.0 * x0 / 3.0); t = 1.0;     /* e^{-2x/3} jet: coeff_k = e0*(-2/3)^k/k! */
  for (k = 0; k <= n; k++) { E[k] = e0 * t; t *= -(2.0 / 3.0) / (double)(k + 1); }
  dd = x0 - c; dk = 1.0 / dd;             /* 1/(x-c) jet: coeff_k = (-1)^k/(x0-c)^(k+1) */
  for (k = 0; k <= n; k++) { R[k] = dk; dk *= -1.0 / dd; }
  xc_br_jmul(P, E, A, n); xc_br_jmul(A, R, G, n);  /* G[k] = coeff of (x-x0)^k in G(x) */
  H[0] = 1.0 / G[0];                      /* H = 1/G(x): reciprocal series (no cancel) */
  for (k = 1; k <= n; k++) {
    s = 0.0;
    for (j = 1; j <= k; j++) s += G[j] * H[k - j];
    H[k] = -s / G[0];
  }
  for (k = 0; k <= n; k++) FF[k] = K * H[k];  /* FF[k] = coeff of (x-x0)^k in Q(x)=K/G */
  a1 = FF[1];                             /* series reversion of Q(x) -> out[k]=x^(k)(Q) */
  out[1] = 1.0 / a1;
  if (n >= 2) out[2] = 2.0 * (-FF[2] / (a1 * a1 * a1));
  if (n >= 3) out[3] = 6.0 * (2.0 * FF[2] * FF[2] - a1 * FF[3]) / pow(a1, 5);
  if (n >= 4) out[4] = 24.0 * (5.0 * a1 * FF[2] * FF[3] - a1 * a1 * FF[4]
                               - 5.0 * FF[2] * FF[2] * FF[2]) / pow(a1, 7);
}

GPU_FUNCTION
void xc_br89_x_jet(double Q, int n, double *out) {
  double x0 = xc_mgga_x_br89_get_x(Q);
  double K = (2.0 / 3.0) * pow(M_PI, 2.0 / 3.0);
  double P[5] = {x0, 1.0, 0.0, 0.0, 0.0};            /* P(x) = x */
  xc_br_reversion_jet(x0, P, 2.0, K, n, out);
}

GPU_FUNCTION
void xc_mbrxc_x_jet(double Q, int n, double *out) {
  double x0 = xc_mgga_x_mbrxc_get_x(Q);
  double K = pow(32.0 * M_PI, 2.0 / 3.0) / 6.0;
  double P[5], o1 = 1.0 + x0, p = 5.0 / 3.0, bc = 1.0; /* P(x) = (1+x)^(5/3) */
  int k;
  for (k = 0; k <= n; k++) { P[k] = pow(o1, p - (double)k) * bc; bc *= (p - (double)k) / (double)(k + 1); }
  xc_br_reversion_jet(x0, P, 3.0, K, n, out);
}

GPU_FUNCTION double xc_br89_x_d1(double Q){double o[2]; xc_br89_x_jet(Q,1,o); return o[1];}
GPU_FUNCTION double xc_br89_x_d2(double Q){double o[3]; xc_br89_x_jet(Q,2,o); return o[2];}
GPU_FUNCTION double xc_br89_x_d3(double Q){double o[4]; xc_br89_x_jet(Q,3,o); return o[3];}
GPU_FUNCTION double xc_br89_x_d4(double Q){double o[5]; xc_br89_x_jet(Q,4,o); return o[4];}
GPU_FUNCTION double xc_mbrxc_x_d1(double Q){double o[2]; xc_mbrxc_x_jet(Q,1,o); return o[1];}
GPU_FUNCTION double xc_mbrxc_x_d2(double Q){double o[3]; xc_mbrxc_x_jet(Q,2,o); return o[2];}
GPU_FUNCTION double xc_mbrxc_x_d3(double Q){double o[4]; xc_mbrxc_x_jet(Q,3,o); return o[3];}
GPU_FUNCTION double xc_mbrxc_x_d4(double Q){double o[5]; xc_mbrxc_x_jet(Q,4,o); return o[4];}
