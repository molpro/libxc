/*
 Copyright (C) 2006-2018 M.A.L. Marques
 Copyright (C) 2019 X. Andrade

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

/**
 * @file work_gga_inc.c
 * @brief This file is to be included in GGA functionals.
 */

#if defined(XC_CHECK_NUMERICS) && defined(HAVE_FEENABLEEXCEPT)
#include <fenv.h>
/* feenableexcept is GNU-only and its declaration in <fenv.h> is gated
   on _GNU_SOURCE, which we can't reliably set late from inside an
   include file. Declare it manually instead. */
extern int feenableexcept(int);
#endif

/* macro to simpligy accessing the variables */
#define VAR(var, ip, index)        var[ip*p->dim.var + index]
#define WORK_GGA_(order, spin)     work_gga_ ## order ## _ ## spin
#define WORK_GGA_GPU_(order, spin) work_gga_gpu_ ## order ## _ ## spin
#define WORK_GGA_KERNEL_(order, spin) work_gga_kernel_ ## order ## _ ## spin
#define FUNC_(order, spin)         func_     ## order ## _ ## spin

/* we need double escaping of the preprocessor macros */
#define WORK_GGA(order, spin)     WORK_GGA_(order, spin)
#define WORK_GGA_GPU(order, spin) WORK_GGA_GPU_(order, spin)
#define WORK_GGA_KERNEL(order, spin) WORK_GGA_KERNEL_(order, spin)
#define FUNC(order, spin)         FUNC_(order, spin)

GPU_DEVICE_FUNCTION FORCE_INLINE static void
WORK_GGA_KERNEL(ORDER_TXT, SPIN_TXT)
(const XC(func_type) *p, size_t ip, const double *rho, const double *sigma,
         xc_gga_out_params *out)
{
  double dens;
  double my_rho[2] = {0.0, 0.0};
  double my_sigma[3] = {0.0, 0.0, 0.0};

  /* Screen low density */
  dens = (p->nspin == XC_POLARIZED) ? VAR(rho, ip, 0) + VAR(rho, ip, 1) : VAR(rho, ip, 0);
  if(dens < p->dens_threshold)
    return;

  /* sanity check of input parameters */
  my_rho[0] = m_max(p->dens_threshold, VAR(rho, ip, 0));
  my_sigma[0] = m_max(p->sigma_threshold * p->sigma_threshold, VAR(sigma, ip, 0));
  if(p->nspin == XC_POLARIZED){
    double s_ave;

    my_rho[1] = m_max(p->dens_threshold, VAR(rho, ip, 1));
    my_sigma[2] = m_max(p->sigma_threshold * p->sigma_threshold, VAR(sigma, ip, 2));

    my_sigma[1] = VAR(sigma, ip, 1);
    s_ave = 0.5*(my_sigma[0] + my_sigma[2]);
    /* | grad n |^2 = |grad n_up + grad n_down|^2 > 0 */
    my_sigma[1] = (my_sigma[1] >= -s_ave ? my_sigma[1] : -s_ave);
    /* Since |grad n_up - grad n_down|^2 > 0 we also have */
    my_sigma[1] = (my_sigma[1] <= +s_ave ? my_sigma[1] : +s_ave);
  }

  FUNC(ORDER_TXT, SPIN_TXT)(p, ip, my_rho, my_sigma, out);
}

#ifdef HAVE_CUDA
__global__ static void
WORK_GGA_GPU(ORDER_TXT, SPIN_TXT)(const XC(func_type) *p, size_t np,
const double *rho, const double *sigma, xc_gga_out_params *out)
{
  size_t ip = blockIdx.x*blockDim.x + threadIdx.x;
  if (ip >= np) return;
  WORK_GGA_KERNEL(ORDER_TXT, SPIN_TXT)(p, ip, rho, sigma, out);
}
#endif

static void
WORK_GGA(ORDER_TXT, SPIN_TXT)
(const XC(func_type) *p, size_t np, const double *rho, const double *sigma,
         xc_gga_out_params *out)
{
  traceRangePush(__func__);
#if defined(XC_CHECK_NUMERICS) && defined(HAVE_FEENABLEEXCEPT)
  /* Trap floating-point errors so divisions by zero and invalid ops in
     the functional evaluation raise SIGFPE immediately. Platforms
     without feenableexcept (macOS, Windows, ...) still get the
     post-loop NaN/Inf scan below. */
  feenableexcept(FE_DIVBYZERO | FE_INVALID);
#endif


  if ((p->info->flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_DEVICE) {
#ifdef HAVE_CUDA
    libxc_check_device_ptr(rho);
    libxc_check_device_ptr(sigma);

    //make a copy of 'p' and 'out' since they might be in host-only memory
    xc_func_type *pgpu;
    xc_gga_out_params *outgpu;
    libxc_check_device_err(cudaMalloc(&pgpu, sizeof(*pgpu)));
    libxc_check_device_err(cudaMalloc(&outgpu, sizeof(*outgpu)));
    libxc_check_device_err(cudaMemcpy(pgpu, p, sizeof(*pgpu), cudaMemcpyDefault));
    libxc_check_device_err(cudaMemcpy(outgpu, out, sizeof(*outgpu), cudaMemcpyDefault));

    size_t nblocks = np/CUDA_BLOCK_SIZE;
    if(np != nblocks*CUDA_BLOCK_SIZE) nblocks++;

    WORK_GGA_GPU(ORDER_TXT, SPIN_TXT)<<<nblocks, CUDA_BLOCK_SIZE>>>
      (pgpu, np, rho, sigma, outgpu);
    libxc_check_device_err(cudaPeekAtLastError());

    libxc_check_device_err(cudaFree(pgpu));
    libxc_check_device_err(cudaFree(outgpu));
#else
    fprintf(stderr, "%s:%d: in %s: libxc was compiled without GPU support\n", __FILE__, __LINE__, __func__);
    abort();
#endif
  } else if ((p->info->flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_HOST) {
    for (size_t ip = 0; ip < np; ip++) {
      WORK_GGA_KERNEL(ORDER_TXT, SPIN_TXT)(p, ip, rho, sigma, out);
    }
  } else {
    fprintf(stderr, "%s:%d: in %s: neither XC_FLAGS_ON_DEVICE nor XC_FLAGS_ON_HOST is set\n", __FILE__, __LINE__, __func__);
    abort();
  }

  /* check for NaNs / Infs that survived the FPE trap (or the platform
     lacks feenableexcept, e.g. macOS) and print a reproducer line */
#ifdef XC_CHECK_NUMERICS
  for(size_t ip = 0; ip < np; ip++){
    const xc_dimensions *dim = &(p->dim);
    int ii, is_OK = 1;

    if(out->zk != NULL)
      is_OK = is_OK & isfinite(out->VAR(zk, ip, 0));

    if(out->vrho != NULL){
      for(ii=0; ii < dim->vrho; ii++)
        is_OK = is_OK && isfinite(out->VAR(vrho, ip, ii));
      for(ii=0; ii < dim->vsigma; ii++)
        is_OK = is_OK && isfinite(out->VAR(vsigma, ip, ii));
    }

    if(!is_OK){
      printf("Problem in the evaluation of the functional\n");
      if(p->nspin == XC_UNPOLARIZED){
        printf("./xc-get_data %d 1 %le 0.0 %le 0.0 0.0 0.0 0.0 0.0 0.0\n",
               p->info->number, VAR(rho, ip, 0), VAR(sigma, ip, 0));
      }else{
        printf("./xc-get_data %d 2 %le %le %le %le %le 0.0 0.0 0.0 0.0\n",
               p->info->number, VAR(rho, ip, 0), VAR(rho, ip, 1),
               VAR(sigma, ip, 0), VAR(sigma, ip, 1), VAR(sigma, ip, 2));
      }
    }
  }   /* for(ip) */
#endif
  traceRangePop(); // __func__
}
