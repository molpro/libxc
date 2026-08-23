/*
 Copyright (C) 2006-2007 M.A.L. Marques
 Copyright (C) 2019 X. Andrade

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef _LDA_H
#define _LDA_H

#include "config.h"

/* These are generic header files that are needed basically everywhere */
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef HAVE_CUDA
#ifdef HAVE_HIP
#include <hip/hip_runtime.h>
#include <hip/hip_runtime_api.h>
// https://rocm.docs.amd.com/projects/HIPIFY/en/latest/reference/tables/CUDA_Runtime_API_functions_supported_by_HIP.html
#define cudaError hipError_t
#define cudaError_t hipError_t
#define cudaFree hipFree
#define cudaGetErrorString hipGetErrorString
#define cudaMalloc hipMalloc
#define cudaMallocManaged hipMallocManaged
#define cudaMemcpy hipMemcpy
#define cudaMemcpy2D hipMemcpy2D
#define cudaMemcpyDefault hipMemcpyDefault
#define cudaMemoryTypeDevice hipMemoryTypeDevice
#define cudaMemoryTypeHost hipMemoryTypeHost
#define cudaMemoryTypeManaged hipMemoryTypeManaged
#define cudaMemset hipMemset
#define cudaPeekAtLastError hipPeekAtLastError
#define cudaPointerAttributes hipPointerAttribute_t
#define cudaPointerGetAttributes hipPointerGetAttributes
#define cudaSuccess hipSuccess
// https://rocm.docs.amd.com/projects/HIP/en/latest/how-to/hip_porting_guide.html#identifying-host-or-device-compilation-pass
#ifdef __HIP_DEVICE_COMPILE__
#define __CUDA_ARCH__
#endif
#else
#include <cuda.h>
#endif
#endif

#include "xc.h"
#include "xc_funcs_worker.h"

/* we include the references also */
#include "references.h"

/* need config to figure out what needs to be defined or not */
#include "config.h"

#ifdef HAVE_CUDA
#define GPU_FUNCTION __host__ __device__
#define GPU_DEVICE_FUNCTION __host__ __device__
#define CUDA_BLOCK_SIZE 256
#else
#define GPU_FUNCTION
#define GPU_DEVICE_FUNCTION
#endif

/* __CUDA_ARCH__ is only defined during the device compilation pass */
#ifdef __CUDA_ARCH__
#define GPU_DATA __device__
#else
#define GPU_DATA
#endif

#if defined(__CUDACC__)
#define FORCE_INLINE __forceinline__
#elif defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
#define FORCE_INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER) && !defined(__INTEL_COMPILER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE inline /* :( */
#endif

/* https://gcc.gnu.org/wiki/Visibility */
#if defined(__GNUC__) && (__GNUC__ + 0) >= 4
#define DLL_LOCAL __attribute__ ((visibility ("hidden")))
#else
#define DLL_LOCAL
#endif

/* Token paste through one level of expansion, so XC_CAT(f_k, _KMAX) yields
   f_k2 rather than f_k_KMAX. Used by the generated code to name the
   per-order variant of a helper. */
#define XC_CAT_(a, b) a ## b
#define XC_CAT(a, b) XC_CAT_(a, b)

/* Highest derivative order this build compiles, as a number. Set by the
   configuration from --enable-maxorder / -DMAXORDER; this is the single
   knob the library tests against.

   XC_DONT_COMPILE_<ORDER> is the deprecated spelling. It is no longer used
   internally, but a hand-passed -DXC_DONT_COMPILE_FXC still lowers the
   ceiling here so downstream builds that set it keep working. Delete this
   block once that compatibility is no longer wanted. */
#ifndef XC_MAXORDER
#  define XC_MAXORDER 4
#endif

#if   defined(XC_DONT_COMPILE_VXC)
#  define XC_MAXORDER_DEPRECATED_CAP 0
#elif defined(XC_DONT_COMPILE_FXC)
#  define XC_MAXORDER_DEPRECATED_CAP 1
#elif defined(XC_DONT_COMPILE_KXC)
#  define XC_MAXORDER_DEPRECATED_CAP 2
#elif defined(XC_DONT_COMPILE_LXC)
#  define XC_MAXORDER_DEPRECATED_CAP 3
#else
#  define XC_MAXORDER_DEPRECATED_CAP 4
#endif

#if XC_MAXORDER_DEPRECATED_CAP < XC_MAXORDER
#  undef XC_MAXORDER
#  define XC_MAXORDER XC_MAXORDER_DEPRECATED_CAP
#endif

/* This takes care of disabling specific derivatives from the info structures */
#define XC_FLAGS_I_HAVE_EXC XC_FLAGS_HAVE_EXC

#if XC_MAXORDER < 1
# define XC_FLAGS_I_HAVE_VXC 0
#else
# define XC_FLAGS_I_HAVE_VXC XC_FLAGS_HAVE_VXC
#endif

#if XC_MAXORDER < 2
# define XC_FLAGS_I_HAVE_FXC 0
#else
# define XC_FLAGS_I_HAVE_FXC XC_FLAGS_HAVE_FXC
#endif

#if XC_MAXORDER < 3
# define XC_FLAGS_I_HAVE_KXC 0
#else
# define XC_FLAGS_I_HAVE_KXC XC_FLAGS_HAVE_KXC
#endif

#if XC_MAXORDER < 4
# define XC_FLAGS_I_HAVE_LXC 0
#else
# define XC_FLAGS_I_HAVE_LXC XC_FLAGS_HAVE_LXC
#endif

#define XC_FLAGS_I_HAVE_ALL (XC_FLAGS_HAVE_EXC   | XC_FLAGS_I_HAVE_VXC | \
                             XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | \
                             XC_FLAGS_I_HAVE_LXC)

/* Useful mathematical expressions */
#ifndef M_E
# define M_E            2.7182818284590452354   /* e */
#endif
#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif
#ifndef M_SQRT2
# define M_SQRT2        1.41421356237309504880  /* sqrt(2) */
#endif
/* The remaining <math.h> constants are POSIX, not ISO C, so they are
   absent under a strict compiler. The SymPy code generator emits them
   for recognised constant subexpressions (e.g. M_LN2 for log(2)). */
#ifndef M_LOG2E
# define M_LOG2E        1.4426950408889634074   /* log_2(e) */
#endif
#ifndef M_LOG10E
# define M_LOG10E       0.43429448190325182765  /* log_10(e) */
#endif
#ifndef M_LN2
# define M_LN2          0.69314718055994530942  /* log(2) */
#endif
#ifndef M_LN10
# define M_LN10         2.30258509299404568402  /* log(10) */
#endif
#ifndef M_PI_2
# define M_PI_2         1.57079632679489661923  /* pi/2 */
#endif
#ifndef M_PI_4
# define M_PI_4         0.78539816339744830962  /* pi/4 */
#endif
#ifndef M_1_PI
# define M_1_PI         0.31830988618379067154  /* 1/pi */
#endif
#ifndef M_2_PI
# define M_2_PI         0.63661977236758134308  /* 2/pi */
#endif
#ifndef M_2_SQRTPI
# define M_2_SQRTPI     1.12837916709551257390  /* 2/sqrt(pi) */
#endif
#ifndef M_SQRT1_2
# define M_SQRT1_2      0.70710678118654752440  /* 1/sqrt(2) */
#endif

/* x**n for a compile-time integer n, as binary powering.

   The generated sources reach |n| = 57, and pow() is never the right way to
   evaluate those: it stays a library call at -O3 (only pow(x, 2.0) is expanded,
   and -fno-math-errno barely helps -- only -ffast-math removes them, which this
   library cannot use), costing ~37 ns against ~2 ns here.

   Written as a helper rather than emitted inline so the generated code stays
   readable: `xc_powi(rs, 21)` instead of a 21-term product. With a constant
   exponent both gcc and clang unroll this completely -- n = 21 becomes six
   multiplications, the minimal addition chain for 21, with no call and no
   branch. The argument is evaluated once, unlike the POW_* macros above.

   Fewer roundings than a flat product, so it is also the more accurate form;
   measured against pow() over x in [1e-3, 1e3] the worst deviation is under
   3 ulp. Negative n divides once at the end rather than raising 1/x, which
   would amplify the reciprocal's error n-fold. */
GPU_FUNCTION static inline double xc_powi(double x, int n) {
  unsigned m = (n < 0) ? (unsigned)(-n) : (unsigned)n;
  double r = 1.0, b = x;
  while (m) {
    if (m & 1u) r *= b;
    m >>= 1u;
    if (m) b *= b;
  }
  return (n < 0) ? 1.0/r : r;
}

/* Only the cube root itself is kept. The fixed-fraction macros that used to
   sit here -- POW_2_3, POW_4_3, POW_5_3, POW_7_3, POW_3_2, POW_1_2, POW_1_4 --
   came from the Maple pipeline's regex rewrites and had no users left. Two of
   them spelled a form the generator no longer emits because it is needlessly
   lossy: POW_5_3 as x*cbrt(x)*cbrt(x) costs 9.5 ulp against 4.6 for
   x*x/cbrt(x), and POW_2_3 as cbrt(x)*cbrt(x) costs 9.1 against 4.9 for
   x/cbrt(x), since applying a root twice takes its error twice. The printer
   now composes these per exponent; see LibxcCPrinter._frac_part. */
#ifdef HAVE_CBRT
#define CBRT(x)    cbrt(x)
#else
#define CBRT(x) pow((x), 1.0/3.0)
#endif

/* this is the piecewise function used in maple */
/* x**(p/q) with p/q in lowest terms, q in {1,2,3,4,6}. */
GPU_FUNCTION static inline double xc_powr(double x, int p, int q) {
  int neg = (p < 0), a = neg ? -p : p;
  int k = a % q, whole = a / q;
  /* No special case when cbrt() is missing: CBRT() then costs a pow(x, 1/3),
     but composing from it still beats pow(x, p/q) with a compound exponent.
     p/q is not representable, and d(x**e)/de = x**e ln x turns that error into
     ~19 ulp at 13/3, against ~4 for the composed form. */
  double root;
  switch (q) {
  case 1:  return xc_powi(x, p);
  case 2:  root = sqrt(x);            break;
  case 3:  root = CBRT(x);            break;
  case 4:  root = sqrt(sqrt(x));      break;
  case 6:  root = sqrt(CBRT(x));      break;
  default: return pow(x, (double)p / (double)q);
  }
  /* One root, applied once, and at most one division. */
  if (k == 0)
    return xc_powi(x, neg ? -whole : whole);
  if (k == 1)
    return neg ? 1.0 / (xc_powi(x, whole) * root) : xc_powi(x, whole) * root;
  /* k == q-1: x**(k/q) = x / root */
  return neg ? root / xc_powi(x, whole + 1) : xc_powi(x, whole + 1) / root;
}


#define my_piecewise3(c, x1, x2) ((c) ? (x1) : (x2))
#define my_piecewise5(c1, x1, c2, x2, x3) ((c1) ? (x1) : ((c2) ? (x2) : (x3)))

/* Computes nderiv derivatives of B-spline Nip(u) */
GPU_FUNCTION void xc_bspline(int i, int p, double u, int nderiv, const double *U, double *ders);

#define M_SQRTPI        1.772453850905516027298167483341145182798
#define M_CBRTPI        1.464591887561523263020142527263790391739
#define M_SQRT3         1.732050807568877293527446341505872366943
#define M_CBRT2         1.259921049894873164767210607278228350570
#define M_CBRT3         1.442249570307408382321638310780109588392
#define M_CBRT4         1.587401051968199474751705639272308260391
#define M_CBRT5         1.709975946676696989353108872543860109868
#define M_CBRT6         1.817120592832139658891211756327260502428
#define M_CBRT7         1.912931182772389101199116839548760282862
#define M_CBRT9         2.080083823051904114530056824357885386338

/* Very useful macros */
#ifndef m_min
#define m_min(x,y)  (((x)<(y)) ? (x) : (y))
#endif
#ifndef m_max
#define m_max(x,y)  (((x)<(y)) ? (y) : (x))
#endif

/* some useful constants */
#define LOG_DBL_MIN        (log(DBL_MIN))
#define LOG_DBL_MAX        (log(DBL_MAX))
#define SQRT_DBL_EPSILON   (sqrt(DBL_EPSILON))

/* Precision-abstract floating-point limits. The libxc functional
   sources (both Maple and SymPy) should refer to these names rather
   than DBL_*; a future single-precision or extended-precision build
   would only redefine these macros, leaving every functional source
   unchanged. For now they map to the IEEE-double constants. */
#ifndef XC_EPSILON
#define XC_EPSILON         DBL_EPSILON
#endif
#ifndef XC_MIN
#define XC_MIN             DBL_MIN
#endif
#ifndef XC_MAX
#define XC_MAX             DBL_MAX
#endif
#ifndef LOG_XC_MIN
#define LOG_XC_MIN         LOG_DBL_MIN
#endif
#ifndef LOG_XC_MAX
#define LOG_XC_MAX         LOG_DBL_MAX
#endif
#ifndef SQRT_XC_EPSILON
#define SQRT_XC_EPSILON    SQRT_DBL_EPSILON
#endif

/* special functions */
#define Heaviside(x) (((x) >= 0) ? 1.0 : 0.0)
GPU_FUNCTION double LambertW(double z);
GPU_FUNCTION double xc_dilogarithm(const double x);
#define xc_E1_scaled(x) xc_expint_e1_impl(x, 1)
/* expm1 / log1p / asinh / atanh wrappers: precision-preserving near
   their respective fixed points.  Used by opz_pow_n_m1 and any other
   helper that wants `(1+z)^n - 1` without the `1+small - 1`
   cancellation, the closed-form log(x + sqrt(x^2 + 1)) without the
   `log(close-to-1)` cancellation at small x, or
   (1/2)*log((1+x)/(1-x)) without the same. */
/* Cast the argument to double: maple2c constant-folds the argument of
   these inert wrappers to an integer literal in some branches (e.g.
   opz_pow_n_m1(0,n) emits xc_log1p(0)), and CUDA/C++ then sees an
   ambiguous overload between log1p(double) and log1p(float) for an int
   argument.  The cast is a no-op for the usual double arguments. */
#define xc_expm1(x) expm1((double)(x))
#define xc_log1p(x) log1p((double)(x))
#define xc_asinh(x) asinh((double)(x))
#define xc_atanh(x) atanh((double)(x))

/* x - log(1 + x), evaluated by Taylor series for small x so the
   x - x cancellation in the leading term doesn't lose precision.
   No libm equivalent; implemented in util.c. */
GPU_FUNCTION double xc_x_minus_log1p(double x);

/* we define this function here, so it can be properly inlined by all compilers */
GPU_FUNCTION
static inline double
xc_cheb_eval(const double x, const double *cs, const int N)
{
  int i;
  double twox, b0, b1, b2;

  b2 = b1 = b0 = 0.0;

  twox = 2.0*x;
  for(i=N-1; i>=0; i--){
    b2 = b1;
    b1 = b0;
    b0 = twox*b1 - b2 + cs[i];
  }

  return 0.5*(b0 - b2);
}

GPU_FUNCTION double xc_bessel_I0_scaled(const double x);
GPU_FUNCTION double xc_bessel_I0(const double x);
GPU_FUNCTION double xc_bessel_I1_scaled(const double x);
GPU_FUNCTION double xc_bessel_I1(const double x);
GPU_FUNCTION double xc_bessel_K0_scaled(const double x);
GPU_FUNCTION double xc_bessel_K0(const double x);
GPU_FUNCTION double xc_bessel_K1_scaled(const double x);
GPU_FUNCTION double xc_bessel_K1(const double x);

GPU_FUNCTION double xc_expint_e1_impl(double x, const int scale);
GPU_FUNCTION static inline double expint_e1(const double x)         { return  xc_expint_e1_impl( x, 0); }
GPU_FUNCTION static inline double expint_e1_scaled(const double x)  { return  xc_expint_e1_impl( x, 1); }
GPU_FUNCTION static inline double expint_Ei(const double x)         { return -xc_expint_e1_impl(-x, 0); }
#define Ei(x) expint_Ei(x)
GPU_FUNCTION static inline double expint_Ei_scaled(const double x)  { return -xc_expint_e1_impl(-x, 1); }

GPU_FUNCTION double xc_erfcx(double x);
/* erfcx(z) and derivatives 0..n (cancellation-free); xc_erfcx_dk = the k-th */
GPU_FUNCTION void xc_erfcx_jet(double z, int n, double *out);
GPU_FUNCTION double xc_erfcx_d1(double z);
GPU_FUNCTION double xc_erfcx_d2(double z);
GPU_FUNCTION double xc_erfcx_d3(double z);
GPU_FUNCTION double xc_erfcx_d4(double z);
/* e^z E_1(z) and derivatives 0..n (cancellation-free); xc_E1_scaled_dk = k-th */
GPU_FUNCTION void xc_E1_scaled_jet(double z, int n, double *out);
GPU_FUNCTION double xc_E1_scaled_d1(double z);
GPU_FUNCTION double xc_E1_scaled_d2(double z);
GPU_FUNCTION double xc_E1_scaled_d3(double z);
GPU_FUNCTION double xc_E1_scaled_d4(double z);
/* dilog (Li_2) and derivatives 0..n (series-based, cancellation-free) */
GPU_FUNCTION void xc_dilogarithm_jet(double q, int n, double *out);
GPU_FUNCTION double xc_dilogarithm_d1(double q);
GPU_FUNCTION double xc_dilogarithm_d2(double q);
GPU_FUNCTION double xc_dilogarithm_d3(double q);
GPU_FUNCTION double xc_dilogarithm_d4(double q);
/* LambertW W(z) and derivatives 0..n (series-reversion, cancellation-free) */
GPU_FUNCTION void xc_lambertw_jet(double z, int n, double *out);
GPU_FUNCTION double xc_lambertw_d1(double z);
GPU_FUNCTION double xc_lambertw_d2(double z);
GPU_FUNCTION double xc_lambertw_d3(double z);
GPU_FUNCTION double xc_lambertw_d4(double z);

/* integration */
typedef void integr_fn(double *x, int n, const void *ex);

GPU_FUNCTION double xc_integrate(integr_fn func, const void *ex, double a, double b);

/* root finding */
typedef double xc_brent_f(double, void *);

GPU_FUNCTION
double xc_math_brent(xc_brent_f f, double lower_bound, double upper_bound,
                     double TOL, double MAX_ITER, void *f_params);


typedef struct xc_functional_key_t {
  char name[256];
  int  number;
} xc_functional_key_t;


#define M_C 137.0359996287515 /* speed of light */

#define RS_FACTOR      0.6203504908994000166680068120477781673508     /* (3/(4*Pi))^1/3        */
#define X_FACTOR_C     0.9305257363491000250020102180716672510262     /* 3/8*cur(3/pi)*4^(2/3) */
#define X_FACTOR_2D_C  1.504505556127350098528211870828726895584      /* 8/(3*sqrt(pi))        */
#define K_FACTOR_C     4.557799872345597137288163759599305358515      /* 3/10*(6*pi^2)^(2/3)   */
#define MU_GE          0.1234567901234567901234567901234567901235     /* 10/81                 */
#define MU_PBE         0.2195149727645171 /* mu = beta*pi^2/3, beta = 0.06672455060314922 */
#define X2S            0.1282782438530421943003109254455883701296     /* 1/(2*(6*pi^2)^(1/3))  */
#define X2S_2D         0.1410473958869390717370198628901931464610     /* 1/(2*(4*pi)^(1/2))    */
#define FZETAFACTOR    0.5198420997897463295344212145564567011405     /* 2^(4/3) - 2           */

#define RS(x)          (RS_FACTOR/CBRT(x))
#define FZETA(x)       ((pow(1.0 + (x),  4.0/3.0) + pow(1.0 - (x),  4.0/3.0) - 2.0)/FZETAFACTOR)
#define DFZETA(x)      ((CBRT(1.0 + (x)) - CBRT(1.0 - (x)))*(4.0/3.0)/FZETAFACTOR)
#define D2FZETA(x)     ((4.0/9.0)/FZETAFACTOR)* \
  (fabs(x)==1.0 ? (FLT_MAX) : (pow(1.0 + (x), -2.0/3.0) + pow(1.0 - (x), -2.0/3.0)))
#define D3FZETA(x)     (-(8.0/27.0)/FZETAFACTOR)* \
  (fabs(x)==1.0 ? (FLT_MAX) : (pow(1.0 + (x), -5.0/3.0) - pow(1.0 - (x), -5.0/3.0)))


/* Functions to handle the internal counters */

void internal_counters_set_lda (int nspin, xc_dimensions *dim);
void internal_counters_set_gga (int nspin, xc_dimensions *dim);
void internal_counters_set_mgga(int nspin, xc_dimensions *dim);


/* Allocation of the output variables, and single-functional evaluation
   (shared by the mix machinery and xc-sanity; defined in mix_func.c) */
void xc_mgga_vars_allocate_all_flags
  (int family, size_t np, const xc_dimensions *dim,
   int do_zk, int do_vrho, int do_v2rho2, int do_v3rho3, int do_v4rho4,
   double **zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA double **, ), int flags);
void xc_mgga_vars_free_all_flags
  (double *zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA double *, ), int flags);
void xc_mgga_evaluate_functional
  (const xc_func_type *func, size_t np,
   const double *rho, const double *sigma, const double *lapl, const double *tau,
   double *zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA double *, ));

/* Functionals that are defined as mixtures of others */
void xc_mix_init(xc_func_type *p, int n_funcs, const int *funcs_id, const double *mix_coef);
void xc_mix_func
  (const xc_func_type *func, size_t np,
   const double *rho, const double *sigma, const double *lapl, const double *tau,
   double *zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA double *, ));

/* Hybrid functional intializers. The order of arguments is the same
   as in the external parameter setters.
 */
void xc_hyb_init_hybrid(xc_func_type *p, double alpha);
void xc_hyb_init_sr  (xc_func_type *p, double beta, double omega);
void xc_hyb_init_cam (xc_func_type *p, double alpha, double beta, double omega);
void xc_hyb_init_camy(xc_func_type *p, double alpha, double beta, double omega);

/* Some useful functions */
const char *get_kind(const xc_func_type *func);
const char *get_family(const xc_func_type *func);
double get_ext_param(const xc_func_type *func, const double *values, int index);
void xc_require_implementation(const void *out_ptr, int flags, int have_flag,
                               const char *fname, const char *deriv);
void set_ext_params_cpy  (xc_func_type *p, const double *ext_params);
void set_ext_params_omega(xc_func_type *p, const double *ext_params);
void set_ext_params_cpy_omega(xc_func_type *p, const double *ext_params);
void set_ext_params_exx(xc_func_type *p, const double *ext_params);
void set_ext_params_cpy_exx(xc_func_type *p, const double *ext_params);
void set_ext_params_cam(xc_func_type *p, const double *ext_params);
void set_ext_params_cpy_cam(xc_func_type *p, const double *ext_params);
void set_ext_params_camy(xc_func_type *p, const double *ext_params);
void set_ext_params_cpy_camy(xc_func_type *p, const double *ext_params);
void set_ext_params_cam_sr(xc_func_type *p, const double *ext_params);
void set_ext_params_cpy_cam_sr(xc_func_type *p, const double *ext_params);
void set_ext_params_lc(xc_func_type *p, const double *ext_params);
void set_ext_params_cpy_lc(xc_func_type *p, const double *ext_params);
void set_ext_params_lcy(xc_func_type *p, const double *ext_params);
void set_ext_params_cpy_lcy(xc_func_type *p, const double *ext_params);

GPU_FUNCTION
double xc_mgga_x_br89_get_x(double Q);
GPU_FUNCTION double xc_mgga_x_mbrxc_get_x(double Q);
/* Becke-Roussel inverses and derivatives 0..n (series-reversion of the
   defining function; cancellation-free). xc_<fn>_dk = the k-th derivative. */
GPU_FUNCTION void xc_br89_x_jet(double Q, int n, double *out);
GPU_FUNCTION double xc_br89_x_d1(double Q);
GPU_FUNCTION double xc_br89_x_d2(double Q);
GPU_FUNCTION double xc_br89_x_d3(double Q);
GPU_FUNCTION double xc_br89_x_d4(double Q);
GPU_FUNCTION void xc_mbrxc_x_jet(double Q, int n, double *out);
GPU_FUNCTION double xc_mbrxc_x_d1(double Q);
GPU_FUNCTION double xc_mbrxc_x_d2(double Q);
GPU_FUNCTION double xc_mbrxc_x_d3(double Q);
GPU_FUNCTION double xc_mbrxc_x_d4(double Q);

/* memory managemend on cpu or gpu depending on flags */

DLL_LOCAL void (libxc_check_device_err)(const int err, const char *file, int line, const char *func);
#define libxc_check_device_err(err) (libxc_check_device_err)((err), __FILE__, __LINE__, __func__)

DLL_LOCAL void (libxc_check_device_ptr)(const void *ptr, const char *file, int line, const char *func);
#define libxc_check_device_ptr(ptr) (libxc_check_device_ptr)((ptr), __FILE__, __LINE__, __func__)

DLL_LOCAL void libxc_free_flags(void *ptr, int flags);

DLL_LOCAL void * libxc_malloc_flags(size_t size, int flags);

DLL_LOCAL void * libxc_calloc_flags(size_t size1, size_t size2, int flags);

DLL_LOCAL void libxc_memset_flags(void* mem, int value, size_t size, int flags);

DLL_LOCAL void libxc_memcpy_flags(void *__restrict dest, void const *__restrict src, const size_t size, int flags);

DLL_LOCAL void libxc_memcpy_2d_flags(void *__restrict dst, size_t dpitch, void const *__restrict src, size_t spitch, size_t width, size_t height, int flags);

// performance profiling

#if defined(XC_PROFILING) && defined(HAVE_HIP)
#include <rocprofiler-sdk-roctx/roctx.h>
#define traceRangePush(...) roctxRangePush(__VA_ARGS__)
#define traceRangePop(...) roctxRangePop(__VA_ARGS__)
#elif defined(XC_PROFILING) && defined(HAVE_CUDA)
#include <nvtx3/nvToolsExt.h>
#define traceRangePush(...) nvtxRangePush(__VA_ARGS__)
#define traceRangePop(...) nvtxRangePop(__VA_ARGS__)
#else
#define traceRangePush(...) do {} while (0)
#define traceRangePop(...) do {} while (0)
#endif

#endif
