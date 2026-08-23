/*
 Copyright (C) 2006-2021 M.A.L. Marques
               2015-2021 Susi Lehtola
               2019 X. Andrade

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#include <stdio.h>

#ifdef __has_include
#if __has_include(<execinfo.h>)
#include <execinfo.h>
#include <unistd.h>
#define HAVE_EXECINFO
#endif
#endif

#ifdef HAVE_EXECINFO
#define abort_with_backtrace() do {                     \
    void *buf[512];                                     \
    int n = backtrace(buf, sizeof(buf) / sizeof(*buf)); \
    backtrace_symbols_fd(buf, n, STDOUT_FILENO);        \
    abort();                                            \
  } while (0)
#else
#define abort_with_backtrace() do { abort(); } while (0)
#endif

/* x - log(1 + x): cancellation-free at small x (where the direct
   form loses precision in x - x + x^2/2 - x^3/3 + ...) and falls
   back to the direct evaluation outside the cancellation regime. */
GPU_FUNCTION double
xc_x_minus_log1p(double x)
{
  if(fabs(x) < 0.25) {
    /* Taylor series x - log(1 + x) = sum_{k>=2} (-1)^k x^k / k.
       Evaluated by Horner from the highest term down so the tail
       contribution is accumulated before the leading x^2/2.  We
       carry the series out to k = 24, giving truncation error
       < 0.25^25 / 25 ~ 3.6e-17 (below DBL_EPSILON) at the cutoff. */
    double s = 0.0;
    int k;
    for(k = 24; k >= 2; k--)
      s = (k & 1 ? -1.0 : 1.0) / k + s * x;
    return s * x * x;
  }
  return x - log1p(x);
}

const char *get_kind(const xc_func_type *func) {
  switch(func->info->kind) {
   case(XC_EXCHANGE):
      return "XC_EXCHANGE";

    case(XC_CORRELATION):
      return "XC_CORRELATION";

    case(XC_EXCHANGE_CORRELATION):
      return "XC_EXCHANGE_CORRELATION";

    case(XC_KINETIC):
      return "XC_KINETIC";

    default:
      printf("Internal error in get_kind.\n");
      return "";
  }
}

const char *get_family(const xc_func_type *func) {
  switch(func->info->family) {
    case(XC_FAMILY_UNKNOWN):
      return "XC_FAMILY_UNKNOWN";

    case(XC_FAMILY_LDA):
      return "XC_FAMILY_LDA";

    case(XC_FAMILY_HYB_LDA):
      return "XC_FAMILY_HYB_LDA";

    case(XC_FAMILY_GGA):
      return "XC_FAMILY_GGA";

    case(XC_FAMILY_HYB_GGA):
      return "XC_FAMILY_HYB_GGA";

    case(XC_FAMILY_MGGA):
      return "XC_FAMILY_MGGA";

    case(XC_FAMILY_HYB_MGGA):
      return "XC_FAMILY_HYB_MGGA";

    case(XC_FAMILY_LCA):
      return "XC_FAMILY_LCA";

    case(XC_FAMILY_OEP):
      return "XC_FAMILY_OEP";

    default:
      printf("Internal error in get_family.\n");
      return "";
  }
}

/* this function checks if it should use the default or
   the user assigned value for an external parameter */
double
get_ext_param(const xc_func_type *func, const double *values, int index)
{
  assert(index >= 0 && index < func->info->ext_params.n);
  return func->ext_params[index];
}

/* Abort with a clear message when an output is requested (out_ptr != NULL)
   that the functional does not implement.  Centralises the per-order check
   shared verbatim by the lda/gga/mgga sanity checks, so the error policy
   lives in one place. */
void
xc_require_implementation(const void *out_ptr, int flags, int have_flag,
                          const char *fname, const char *deriv)
{
  if(out_ptr != NULL && !(flags & have_flag)){
    fprintf(stderr,
            "Functional '%s' does not provide an implementation of %s\n",
            fname, deriv);
    abort();
  }
}

/* Copy n parameters, assumes that p->params is just a series of doubles
   so it can be accessed as a array, and and copies
   ext_params to this. */
static void copy_params(xc_func_type *p, const double *ext_params, int nparams) {
  double *params;
  int ii;

  assert(nparams >= 0);
  if(nparams) {
    /* Some functionals only set the hybrid parameters which require no extra storage */
    assert(p->params != NULL);
    params = (double *) (p->params);
    for(ii=0; ii<nparams; ii++)
      params[ii] = get_ext_param(p, ext_params, ii);
  }
}

/* Just copy the parameters */
void
set_ext_params_cpy(xc_func_type *p, const double *ext_params)
{
  int nparams;
  assert(p != NULL);
  nparams = p->info->ext_params.n;
  copy_params(p, ext_params, nparams);
}

/* Each set_ext_params_cpy_<base> copies the leading parameters (all but
   the NTRAILING consumed by the base setter) and then applies the base
   setter; generate them from the base + NTRAILING instead of repeating the
   boilerplate. */
#define SET_EXT_PARAMS_CPY(base, ntrailing)                                  \
  void set_ext_params_cpy_##base(xc_func_type *p, const double *ext_params) { \
    assert(p != NULL);                                                       \
    copy_params(p, ext_params, p->info->ext_params.n - (ntrailing));         \
    set_ext_params_##base(p, ext_params);                                    \
  }

/*
   Copies parameters and sets the screening parameter, which should be
   the last parameter of the functional.
*/
void
set_ext_params_omega(xc_func_type *p, const double *ext_params)
{
  int nparams;
  assert(p != NULL);
  nparams = p->info->ext_params.n - 1;

  p->cam_omega = get_ext_param(p, ext_params, nparams);
}

SET_EXT_PARAMS_CPY(omega, 1)

/*
   Copies parameters and sets the exact exchange coefficient, which
   should be the last parameter of the functional.
*/
void
set_ext_params_exx(xc_func_type *p, const double *ext_params)
{
  int nparams;
  assert(p != NULL);
  nparams = p->info->ext_params.n - 1;

  p->cam_alpha = get_ext_param(p, ext_params, nparams);
}

SET_EXT_PARAMS_CPY(exx, 1)

/*
   Copies parameters and sets the HYB coefficients, which
   should be the three last parameters of the functional.
*/
void
set_ext_params_cam(xc_func_type *p, const double *ext_params)
{
  int nparams;
  assert(p != NULL);
  nparams = p->info->ext_params.n - 3;

  p->cam_alpha = get_ext_param(p, ext_params, nparams);
  p->cam_beta = get_ext_param(p, ext_params, nparams + 1);
  p->cam_omega = get_ext_param(p, ext_params, nparams + 2);
}

SET_EXT_PARAMS_CPY(cam, 3)

void
set_ext_params_camy(xc_func_type *p, const double *ext_params)
{
  set_ext_params_cam(p, ext_params);
}

void
set_ext_params_cpy_camy(xc_func_type *p, const double *ext_params)
{
  set_ext_params_cpy_cam(p, ext_params);
}

/*
  Short-range-only version
*/
void
set_ext_params_cam_sr(xc_func_type *p, const double *ext_params)
{
  int nparams;
  assert(p != NULL);
  nparams = p->info->ext_params.n - 2;

  p->cam_beta = get_ext_param(p, ext_params, nparams);
  p->cam_omega = get_ext_param(p, ext_params, nparams + 1);
}

SET_EXT_PARAMS_CPY(cam_sr, 2)

/* Long-range corrected functionals typically only have one parameter: the range separation parameter */
void
set_ext_params_lc(xc_func_type *p, const double *ext_params)
{
  int nparams;
  assert(p != NULL);
  nparams = p->info->ext_params.n - 1;

  p->cam_alpha = 1.0;
  p->cam_beta = -1.0;
  p->cam_omega = get_ext_param(p, ext_params, nparams);
}

SET_EXT_PARAMS_CPY(lc, 1)

void
set_ext_params_lcy(xc_func_type *p, const double *ext_params)
{
  set_ext_params_lc(p, ext_params);
}

void
set_ext_params_cpy_lcy(xc_func_type *p, const double *ext_params)
{
  set_ext_params_cpy_lc(p, ext_params);
}

void (libxc_check_device_err)(const int err, const char *file, int line, const char *func) {
#ifdef HAVE_CUDA
  cudaError_t cuerr = (cudaError_t)err;
  if (cuerr != cudaSuccess) {
    fprintf(stderr, "%s\n", cudaGetErrorString(cuerr));
    abort_with_backtrace();
  }
#endif
}

void (libxc_check_device_ptr)(const void *ptr, const char *file, int line, const char *func) {
#ifdef HAVE_CUDA
  struct cudaPointerAttributes attrs;
  memset(&attrs, 0, sizeof(attrs));
  libxc_check_device_err(cudaPointerGetAttributes(&attrs, ptr));
  switch (attrs.type) {
#ifndef HAVE_HIP
  case cudaMemoryTypeUnregistered:
    fprintf(stderr, "%s:%d: in %s: cannot use pointer %p of type cudaMemoryTypeUnregistered here\n", file, line, func, ptr);
    abort_with_backtrace();
#endif
  case cudaMemoryTypeHost:
    fprintf(stderr, "%s:%d: in %s: cannot use pointer %p of type cudaMemoryTypeHost here\n", file, line, func, ptr);
    abort_with_backtrace();
  case cudaMemoryTypeDevice:
    break; // all good
  case cudaMemoryTypeManaged:
    break; // all good
  default:
    fprintf(stderr, "%s:%d: in %s: cannot use pointer %p of type unknown here\n", file, line, func, ptr);
    abort_with_backtrace();
  }
#endif
}

/* choose memory managemend on gpu or cpu at runtime */
void libxc_free_flags(void *ptr, int flags){
  if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_DEVICE) {
#ifdef HAVE_CUDA
    libxc_check_device_ptr(ptr);
    libxc_check_device_err(cudaFree(ptr));
#else
    fprintf(stderr, "%s:%d: in %s: libxc was compiled without GPU support\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
#endif
  } else if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_HOST) {
    free(ptr);
  } else {
    fprintf(stderr, "%s:%d: in %s: neither XC_FLAGS_ON_DEVICE nor XC_FLAGS_ON_HOST is set\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
  }
}


void* libxc_malloc_flags(size_t size, int flags){
  void* mem = NULL;
  if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_DEVICE) {
#ifdef HAVE_CUDA
    libxc_check_device_err(cudaMallocManaged(&mem, size));
#else
    fprintf(stderr, "%s:%d: in %s: libxc was compiled without GPU support\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
#endif
  } else if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_HOST) {
    mem = malloc(size);
  } else {
    fprintf(stderr, "%s:%d: in %s: neither XC_FLAGS_ON_DEVICE nor XC_FLAGS_ON_HOST is set\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
  }
  return mem;
}


void* libxc_calloc_flags(size_t size1, size_t size2, int flags) {
  void* mem = NULL;
  if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_DEVICE) {
#ifdef HAVE_CUDA
    libxc_check_device_err(cudaMallocManaged(&mem, size1*size2));
    libxc_check_device_err(cudaMemset(mem, 0, size1*size2));
#else
    fprintf(stderr, "%s:%d: in %s: libxc was compiled without GPU support\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
#endif
  } else if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_HOST) {
    mem = calloc(size1, size2);
  } else {
    fprintf(stderr, "%s:%d: in %s: neither XC_FLAGS_ON_DEVICE nor XC_FLAGS_ON_HOST is set\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
  }
  return mem;
}

void libxc_memset_flags(void* mem, int value, size_t size, int flags){
  if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_DEVICE) {
#ifdef HAVE_CUDA
    libxc_check_device_ptr(mem);
    libxc_check_device_err(cudaMemset(mem, value, size));
#else
    fprintf(stderr, "%s:%d: in %s: libxc was compiled without GPU support\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
#endif
  } else if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_HOST) {
    memset(mem, value, size);
  } else {
    fprintf(stderr, "%s:%d: in %s: neither XC_FLAGS_ON_DEVICE nor XC_FLAGS_ON_HOST is set\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
  }
}

void libxc_memcpy_flags(void *__restrict dest, void const *__restrict src, const size_t size, int flags){
  if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_DEVICE) {
#ifdef HAVE_CUDA
    libxc_check_device_err(cudaMemcpy(dest, src, size, cudaMemcpyDefault));
#else
    fprintf(stderr, "%s:%d: in %s: libxc was compiled without GPU support\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
#endif
  } else if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_HOST) {
    memcpy(dest, src, size);
  } else {
    fprintf(stderr, "%s:%d: in %s: neither XC_FLAGS_ON_DEVICE nor XC_FLAGS_ON_HOST is set\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
  }
}

void libxc_memcpy_2d_flags(void *__restrict dst, size_t dpitch, void const *__restrict src, size_t spitch, size_t width, size_t height, int flags) {
  if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_DEVICE) {
#ifdef HAVE_CUDA
    libxc_check_device_err(cudaMemcpy2D(dst, dpitch, src, spitch, width, height, cudaMemcpyDefault));
#else
    fprintf(stderr, "%s:%d: in %s: libxc was compiled without GPU support\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
#endif
  } else if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_HOST) {
    const char*__restrict src_row = (const char*)src;
    char*__restrict dst_row = (char *)dst;
    for (size_t row = 0; row < height; ++row) {
      memcpy(dst_row, src_row, width);
      src_row += spitch;
      dst_row += dpitch;
    }
  } else {
    fprintf(stderr, "%s:%d: in %s: neither XC_FLAGS_ON_DEVICE nor XC_FLAGS_ON_HOST is set\n", __FILE__, __LINE__, __func__);
    abort_with_backtrace();
  }
}

/* these functional handle the internal counters
   used to move along the input and output arrays.
   We have to pay particular attention to the spin,
   of course. */
void
internal_counters_set_lda(int nspin, xc_dimensions *dim)
{
  dim->rho = dim->vrho = nspin;
  dim->zk  = 1;
  if(nspin == XC_UNPOLARIZED){
    dim->v2rho2 = dim->v3rho3 = dim->v4rho4 = 1;
  }else{
    dim->v2rho2 = 3;
    dim->v3rho3 = 4;
    dim->v4rho4 = 5;
  }
}

void
internal_counters_set_gga(int nspin, xc_dimensions *dim)
{
  internal_counters_set_lda(nspin, dim);

  if(nspin == XC_UNPOLARIZED){
    dim->sigma  = dim->vsigma = 1;
    dim->v2rhosigma  = dim->v2sigma2 = 1;
    dim->v3rho2sigma = dim->v3rhosigma2 = dim->v3sigma3 = 1;
    dim->v4rho3sigma = dim->v4rho2sigma2 = dim->v4rhosigma3 = dim->v4sigma4 = 1;

  }else{
    dim->sigma = dim->vsigma = 3;

    dim->v2rhosigma        = 2*3;
    dim->v2sigma2          = 6;

    dim->v3rho2sigma       = 3*3;
    dim->v3rhosigma2       = 2*6;
    dim->v3sigma3          = 10;

    dim->v4rho3sigma       = 4*3;
    dim->v4rho2sigma2      = 3*6;
    dim->v4rhosigma3       = 2*10;
    dim->v4sigma4          = 15;
  }
}

void
internal_counters_set_mgga(int nspin, xc_dimensions *dim)
{
  internal_counters_set_gga(nspin, dim);
  dim->lapl = dim->vlapl = nspin;
  dim->tau  = dim->vtau  = nspin;

  if(nspin == XC_UNPOLARIZED){
    dim->v2lapl2 = dim->v2tau2 = 1;
    dim->v2rholapl = dim->v2rhotau = dim->v2lapltau = 1;
    dim->v2sigmalapl = dim->v2sigmatau = 1;

    dim->v3lapl3 = dim->v3tau3 = dim->v3rho2lapl = dim->v3rho2tau = dim->v3rholapl2 = 1;
    dim->v3rhotau2 = dim->v3lapl2tau = dim->v3lapltau2 = dim->v3rholapltau = 1;
    dim->v3sigmalapl2 = dim->v3sigmatau2 = dim->v3sigma2lapl = dim->v3sigma2tau = 1;
    dim->v3rhosigmalapl = dim->v3rhosigmatau = dim->v3sigmalapltau = 1;

    dim->v4rho4 = dim->v4rho3sigma = dim->v4rho3lapl = dim->v4rho3tau = dim->v4rho2sigma2 = 1;
    dim->v4rho2sigmalapl = dim->v4rho2sigmatau = dim->v4rho2lapl2 = dim->v4rho2lapltau = 1;
    dim->v4rho2tau2 = dim->v4rhosigma3 = dim->v4rhosigma2lapl = dim->v4rhosigma2tau = 1;
    dim->v4rhosigmalapl2 = dim->v4rhosigmalapltau = dim->v4rhosigmatau2 = 1;
    dim->v4rholapl3 = dim->v4rholapl2tau = dim->v4rholapltau2 = dim->v4rhotau3 = 1;
    dim->v4sigma4 = dim->v4sigma3lapl = dim->v4sigma3tau = dim->v4sigma2lapl2 = 1;
    dim->v4sigma2lapltau = dim->v4sigma2tau2 = dim->v4sigmalapl3 = dim->v4sigmalapl2tau = 1;
    dim->v4sigmalapltau2 = dim->v4sigmatau3 = dim->v4lapl4 = dim->v4lapl3tau = 1;
    dim->v4lapl2tau2 = dim->v4lapltau3 = dim->v4tau4 =1;
  }else{
    dim->vlapl             = 2;
    dim->vtau              = 2;

    /* in total: 30 */
    dim->v2rholapl         = 2*2;
    dim->v2rhotau          = 2*2;
    dim->v2sigmalapl       = 3*2;
    dim->v2sigmatau        = 3*2;
    dim->v2lapl2           = 3;
    dim->v2lapltau         = 2*2;
    dim->v2tau2            = 3;

    /* in total: 130 */
    dim->v3rho2lapl        = 3*2;
    dim->v3rho2tau         = 3*2;
    dim->v3rhosigmalapl    = 2*3*2;
    dim->v3rhosigmatau     = 2*3*2;
    dim->v3rholapl2        = 2*3;
    dim->v3rholapltau      = 2*2*2;
    dim->v3rhotau2         = 2*3;
    dim->v3sigma2lapl      = 6*2;
    dim->v3sigma2tau       = 6*2;
    dim->v3sigmalapl2      = 3*3;
    dim->v3sigmalapltau    = 3*2*2;
    dim->v3sigmatau2       = 3*3;
    dim->v3lapl3           = 4;
    dim->v3lapl2tau        = 3*2;
    dim->v3lapltau2        = 2*3;
    dim->v3tau3            = 4;

    /* in total: 425 */
    dim->v4rho3lapl        = 4*2;
    dim->v4rho3tau         = 4*2;
    dim->v4rho2sigmalapl   = 3*3*2;
    dim->v4rho2sigmatau    = 3*3*2;
    dim->v4rho2lapl2       = 3*3;
    dim->v4rho2lapltau     = 3*2*2;
    dim->v4rho2tau2        = 3*3;
    dim->v4rhosigma2lapl   = 2*6*2;
    dim->v4rhosigma2tau    = 2*6*2;
    dim->v4rhosigmalapl2   = 2*3*3;
    dim->v4rhosigmalapltau = 2*3*2*2;
    dim->v4rhosigmatau2    = 2*3*3;
    dim->v4rholapl3        = 2*4;
    dim->v4rholapl2tau     = 2*3*2;
    dim->v4rholapltau2     = 2*2*3;
    dim->v4rhotau3         = 2*4;
    dim->v4sigma3lapl      = 10*2;
    dim->v4sigma3tau       = 10*2;
    dim->v4sigma2lapl2     = 6*3;
    dim->v4sigma2lapltau   = 6*2*2;
    dim->v4sigma2tau2      = 6*3;
    dim->v4sigmalapl3      = 3*4;
    dim->v4sigmalapl2tau   = 3*3*2;
    dim->v4sigmalapltau2   = 3*2*3;
    dim->v4sigmatau3       = 3*4;
    dim->v4lapl4           = 5;
    dim->v4lapl3tau        = 4*2;
    dim->v4lapl2tau2       = 3*3;
    dim->v4lapltau3        = 2*4;
    dim->v4tau4            = 5;
  }
}

/** Computes nderiv derivatives of B-spline Nip(u)

    The algorithm follows the textbook presentation in the NURBS
    book, 2nd edition, by Les Piegl and Wayne Tiller.

    Input variables:
    - i: function index
    - p: spline order
    - u: argument
    - nderiv: number of derivatives to calculate (zero for just the function itself)
    - U: knots
    Output variables:
    - ders: array [Nip(u), Nip'(u), Nip''(u), ..., Nip^(nderiv)(u)]
*/
GPU_FUNCTION void
xc_bspline(int i, int p, double u, int nderiv, const double *U, double *ders) {

  /* Initialize output array */
  memset(ders, 0, (nderiv+1)*sizeof(double));

  /* Check locality of support */
  if(u < U[i] || u >= U[i+p+1]) {
    return;
  }

  /* Arrays need static sizes for stack allocation */
#define PMAX 8
  assert(p<PMAX);

  /* Array of normalized B splines, use dense storage for simpler code */
  double N[PMAX][PMAX];
  memset(N, 0, PMAX*PMAX*sizeof(double));

  /* Initialize zeroth-degree functions: piecewise constants */
  for(int j=0; j<=p; j++) {
    N[0][j] = (u >= U[i+j] && u < U[i+j+1]) ? 1.0 : 0.0;
  }

  /* Fill out table of B splines */
  for(int k=1; k<=p; k++) {
    double saved = (N[k-1][0] == 0.0) ? 0.0 : ((u-U[i])*N[k-1][0])/(U[i+k]-U[i]);

    for(int j=0; j<=p-k; j++) {
      double Ul = U[i+j+1];
      double Ur = U[i+j+k+1];
      if(N[k-1][j+1] == 0.0) {
        N[k][j] = saved;
        saved = 0.0;
      } else {
        double temp = N[k-1][j+1] / (Ur-Ul);
        N[k][j] = saved + (Ur-u)*temp;
        saved = (u-Ul)*temp;
      }
    }
  }

  /* Function value */
  ders[0] = N[p][0];
  if(nderiv==0)
    return;

  /* Helper memory */
  assert(nderiv<=4);
  double ND[5]; /* dimension nderiv+1 */
  int maxk = (nderiv < p) ? nderiv : p;

  /* Compute derivatives */
  for(int k=1; k<=maxk; k++) {
    /* Load appropriate column */
    memset(ND, 0, (nderiv+1)*sizeof(double));
    for(int j=0; j<=k; j++)
      ND[j] = N[p-k][j];

    /* Compute table */
    for(int jj=1; jj<=k; jj++) {
      double saved = (ND[0] == 0.0) ? 0.0 : ND[0]/(U[i+p-k+jj]-U[i]);

      for(int j=0; j<=k-jj; j++) {
        double Ul = U[i+j+1];
        /* the -k term is missing in the book */
        double Ur = U[i+j+p-k+jj+1];
        if(ND[j+1] == 0.0) {
          ND[j] = (p-k+jj)*saved;
          saved = 0.0;
        } else {
          double temp = ND[j+1]/(Ur-Ul);
          ND[j] = (p-k+jj)*(saved-temp);
          saved = temp;
        }
      }
    }
    /* k:th derivative is */
    ders[k] = ND[0];
  }
}
