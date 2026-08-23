/*
  Copyright (C) 2006-2021 M.A.L. Marques
                2018-2021 Susi Lehtola
                2019 X. Andrade

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

/* initializes the mixing */
void
xc_mix_init(xc_func_type *p, int n_funcs, const int *funcs_id, const double *mix_coef)
{
  int ii;
  int flags;

  assert(p != NULL);
  assert(p->func_aux == NULL && p->mix_coef == NULL);
  flags = p->info->flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST);

  /* allocate structures needed for mixed functional */
  p->n_func_aux = n_funcs;
  p->mix_coef   = (double *) libxc_malloc_flags(n_funcs*sizeof(double), flags);
  p->func_aux   = (xc_func_type **) libxc_malloc_flags(n_funcs*sizeof(xc_func_type *), flags);

  for(ii=0; ii<n_funcs; ii++){
    p->mix_coef[ii] = mix_coef[ii];
    p->func_aux[ii] = (xc_func_type *) libxc_malloc_flags(sizeof(xc_func_type), flags);
    xc_func_init_flags (p->func_aux[ii], funcs_id[ii], p->nspin, flags);
  }

  /* The available derivatives of a mixed functional are the lowest common
     denominator of its components: the mix can supply a derivative order only
     if EVERY component supplies it (and only up to what was compiled in, which
     each component's flags already reflect). Conversely the mix needs the
     Laplacian or tau if ANY component does. Derive both from the components
     here rather than trusting the hard-coded info flags -- p->info is a
     per-instance copy (see xc_func_init in functionals.c), so narrowing its
     flags is safe and local to this functional. */
  {
    int have  = XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC |
                XC_FLAGS_HAVE_KXC | XC_FLAGS_HAVE_LXC;
    int needs = 0;
    for(ii=0; ii<n_funcs; ii++){
      have  &= p->func_aux[ii]->info->flags;
      needs |= p->func_aux[ii]->info->flags &
               (XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_NEEDS_TAU);
    }
    p->info->flags &= ~(XC_FLAGS_HAVE_EXC | XC_FLAGS_HAVE_VXC | XC_FLAGS_HAVE_FXC |
                        XC_FLAGS_HAVE_KXC | XC_FLAGS_HAVE_LXC |
                        XC_FLAGS_NEEDS_LAPLACIAN | XC_FLAGS_NEEDS_TAU);
    p->info->flags |= have | needs;
  }

  /* initialize variables */
  p->cam_alpha = 0.0;
  p->cam_beta  = 0.0;
  p->cam_omega = 0.0;
  p->nlc_b     = 0.0;
  p->nlc_C     = 0.0;
}

#ifdef HAVE_CUDA
__global__ static void add_to_mix_gpu(size_t np, double * dst, double coeff, const double *src){
  size_t ip = blockIdx.x * blockDim.x + threadIdx.x;
  if(ip < np) dst[ip] += coeff*src[ip];
}
#endif

static void add_to_mix(size_t np, double * dst, double coeff, const double *src, int flags){
  if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_DEVICE) {
#ifdef HAVE_CUDA
    size_t nblocks = np/CUDA_BLOCK_SIZE;
    if(np != nblocks*CUDA_BLOCK_SIZE) nblocks++;
    add_to_mix_gpu<<<nblocks, CUDA_BLOCK_SIZE>>>(np, dst, coeff, src);
    libxc_check_device_err(cudaPeekAtLastError());
#else
    fprintf(stderr, "%s:%d: in %s: libxc was compiled without GPU support\n", __FILE__, __LINE__, __func__);
    abort();
#endif
  } else if ((flags & (XC_FLAGS_ON_DEVICE | XC_FLAGS_ON_HOST)) == XC_FLAGS_ON_HOST) {
    size_t ip;
    for(ip = 0; ip < np; ip++) dst[ip] += coeff*src[ip];
  } else {
    fprintf(stderr, "%s:%d: in %s: neither XC_FLAGS_ON_DEVICE nor XC_FLAGS_ON_HOST is set\n", __FILE__, __LINE__, __func__);
    abort();
  }
}

#define is_mgga(id)   ((id) == XC_FAMILY_MGGA || (id) == XC_FAMILY_HYB_MGGA)
#define is_gga(id)    ((id) == XC_FAMILY_GGA  || (id) == XC_FAMILY_HYB_GGA || is_mgga(id))
#define is_lda(id)    ((id) == XC_FAMILY_LDA  || (id) == XC_FAMILY_HYB_LDA ||  is_gga(id))
#define safe_free(pt, flags) if(pt != NULL) libxc_free_flags(pt, flags)
#define sum_var(VAR) add_to_mix(np*dim->VAR, VAR, func->mix_coef[ii], x ## VAR, func->info->flags);

void
xc_mix_func(const xc_func_type *func, size_t np,
            const double *rho, const double *sigma, const double *lapl, const double *tau,
            double *zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA double *, ))
{
  traceRangePush(__func__);
  const xc_func_type *aux;
  double *xzk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA *, x);
  int ii;

  const xc_dimensions *dim = &(func->dim);

  /* The mix's available derivatives (lowest common denominator) and its
     Laplacian/tau requirements are derived from the components in
     xc_mix_init, so the info flags are authoritative here -- no recomputation
     needed. The per-component compatibility asserts below still verify that
     invariant. */

  /* Check compatibility of the individual components */
  for(ii=0; ii<func->n_func_aux; ii++){
    aux = func->func_aux[ii];
    /* Sanity check: if component is GGA or meta-GGA, mix functional
       must also be GGA or meta-GGA */
    if(is_gga(aux->info->family))
      assert(is_gga(func->info->family));
    if(is_mgga(aux->info->family) && !is_mgga(func->info->family))
      assert(is_mgga(func->info->family));
    /* Sanity checks: if mix functional has higher derivatives, these
       must also exist in the individual components */
    if(func->info->flags & XC_FLAGS_HAVE_VXC)
      assert(aux->info->flags & XC_FLAGS_HAVE_VXC);
    if(func->info->flags & XC_FLAGS_HAVE_FXC)
      assert(aux->info->flags & XC_FLAGS_HAVE_FXC);
    if(func->info->flags & XC_FLAGS_HAVE_KXC)
      assert(aux->info->flags & XC_FLAGS_HAVE_KXC);
    if(func->info->flags & XC_FLAGS_HAVE_LXC)
      assert(aux->info->flags & XC_FLAGS_HAVE_LXC);
  }

  /* prepare buffers that will hold the results from the individual functionals */
  xzk MGGA_OUT_PARAMS_NO_EXC(=, x) = NULL;

  /* allocate buffers */
  xc_mgga_vars_allocate_all_flags(func->info->family, np, dim,
                            zk != NULL, vrho != NULL, v2rho2 != NULL, v3rho3 != NULL, v4rho4 != NULL,
                            &xzk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA &, x), func->info->flags);

  /* Proceed by computing the mix */
  for(ii=0; ii<func->n_func_aux; ii++){
    aux = func->func_aux[ii];

    /* Evaluate the functional */
    switch(aux->info->family){
    case XC_FAMILY_LDA:
    case XC_FAMILY_HYB_LDA:
      xc_lda(aux, np, rho,
             xzk LDA_OUT_PARAMS_NO_EXC(XC_COMMA, x));
      break;
    case XC_FAMILY_GGA:
    case XC_FAMILY_HYB_GGA:
      xc_gga(aux, np, rho, sigma,
             xzk GGA_OUT_PARAMS_NO_EXC(XC_COMMA, x));
      break;
    case XC_FAMILY_MGGA:
    case XC_FAMILY_HYB_MGGA:
      xc_mgga(aux, np, rho, sigma, lapl, tau,
              xzk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA, x));
      break;
    }

    /* Do the mixing */
    if(zk != NULL) {
      sum_var(zk);
    }

 #if XC_MAXORDER >= 1
    if(vrho != NULL) {
      sum_var(vrho);

      if(is_gga(aux->info->family)) {
        sum_var(vsigma);
      }

      if(is_mgga(aux->info->family)) {
        if(aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) {
          sum_var(vlapl);
        }
        if(aux->info->flags & XC_FLAGS_NEEDS_TAU) {
          sum_var(vtau);
        }
      }
    }

#if XC_MAXORDER >= 2
    if(v2rho2 != NULL){
      sum_var(v2rho2);

      if(is_gga(aux->info->family)) {
        sum_var(v2rhosigma);
        sum_var(v2sigma2);
      }

      if(is_mgga(aux->info->family)) {
        if(aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) {
          sum_var(v2rholapl);
          sum_var(v2sigmalapl);
          sum_var(v2lapl2);
        }
        if(aux->info->flags & XC_FLAGS_NEEDS_TAU) {
          sum_var(v2rhotau);
          sum_var(v2sigmatau);
          sum_var(v2tau2);
        }
        if((aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) && (aux->info->flags & XC_FLAGS_NEEDS_TAU)) {
          sum_var(v2lapltau);
        }
      }
    }

#if XC_MAXORDER >= 3
    if(v3rho3 != NULL){
      sum_var(v3rho3);

      if(is_gga(aux->info->family)) {
        sum_var(v3rho2sigma);
        sum_var(v3rhosigma2);
        sum_var(v3sigma3);
      }

      if(is_mgga(aux->info->family)) {
        if(aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) {
          sum_var(v3rho2lapl);
          sum_var(v3rhosigmalapl);
          sum_var(v3rholapl2);
          sum_var(v3sigma2lapl);
          sum_var(v3sigmalapl2);
          sum_var(v3lapl3);
        }
        if(aux->info->flags & XC_FLAGS_NEEDS_TAU) {
          sum_var(v3rho2tau);
          sum_var(v3rhosigmatau);
          sum_var(v3rhotau2);
          sum_var(v3sigma2tau);
          sum_var(v3sigmatau2);
          sum_var(v3tau3);
        }
        if((aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) && (aux->info->flags & XC_FLAGS_NEEDS_TAU)) {
          sum_var(v3rholapltau);
          sum_var(v3sigmalapltau);
          sum_var(v3lapl2tau);
          sum_var(v3lapltau2);
        }
      }
    }

#if XC_MAXORDER >= 4
    if(v4rho4 != NULL){
      sum_var(v4rho4);

      if(is_gga(aux->info->family)) {
        sum_var(v4rho3sigma);
        sum_var(v4rho2sigma2);
        sum_var(v4rhosigma3);
        sum_var(v4sigma4);
      }
      if(is_mgga(aux->info->family)) {
        if(aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) {
          sum_var(v4rho3lapl);
          sum_var(v4rho2sigmalapl);
          sum_var(v4rho2lapl2);
          sum_var(v4rhosigma2lapl);
          sum_var(v4rhosigmalapl2);
          sum_var(v4rholapl3);
          sum_var(v4sigma3lapl);
          sum_var(v4sigma2lapl2);
          sum_var(v4sigmalapl3);
          sum_var(v4lapl4);
        }
        if(aux->info->flags & XC_FLAGS_NEEDS_TAU) {
          sum_var(v4rho3tau);
          sum_var(v4rho2sigmatau);
          sum_var(v4rho2tau2);
          sum_var(v4rhosigma2tau);
          sum_var(v4rhosigmatau2);
          sum_var(v4rhotau3);
          sum_var(v4sigma3tau);
          sum_var(v4sigma2tau2);
          sum_var(v4sigmatau3);
          sum_var(v4tau4);
        }
        if((aux->info->flags & XC_FLAGS_NEEDS_LAPLACIAN) && (aux->info->flags & XC_FLAGS_NEEDS_TAU)) {
          sum_var(v4rho2lapltau);
          sum_var(v4rhosigmalapltau);
          sum_var(v4rholapl2tau);
          sum_var(v4rholapltau2);
          sum_var(v4sigma2lapltau);
          sum_var(v4sigmalapl2tau);
          sum_var(v4sigmalapltau2);
          sum_var(v4lapl3tau);
          sum_var(v4lapl2tau2);
          sum_var(v4lapltau3);
        }
      }
    }
#endif
#endif
#endif
#endif
  } /* end functional loop */

  /* deallocate internal buffers */
  xc_mgga_vars_free_all_flags(xzk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA, x), aux->info->flags);
  traceRangePop(); // __func__
}

int
xc_num_aux_funcs(const xc_func_type *p) {
  assert(p != NULL);
  return p->n_func_aux;
}

void
xc_aux_func_ids(const xc_func_type *p, int *ids) {
  int i;
  for(i=0; i<p->n_func_aux;i++)
    ids[i] = p->func_aux[i]->info->number;
}

void
xc_aux_func_weights(const xc_func_type *p, double *weights) {
  int i;
  for(i=0; i<p->n_func_aux;i++)
    weights[i] = p->mix_coef[i];
}


/* mgga output-variable allocation, and single-functional evaluation.
   These were previously in deorbitalize_func.c but are shared
   infrastructure -- xc_mix_func() and xc-sanity.c use them too -- so they
   moved here when the run-time deorbitalization was replaced by symbolic
   composition. */
/* Due to the fact that some functionals do not depend on tau or lapl,
   some variables may remain uninitialized when evaluating the ked or
   mgga functionals. Therefore, *all* variables should be explicitly
   initialized to zero here!
*/

void
xc_mgga_vars_allocate_all_flags(int family, size_t np, const xc_dimensions *dim,
                     int do_zk, int do_vrho, int do_v2rho2, int do_v3rho3, int do_v4rho4,
                     double **zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA double **, ), int flags)
{
  traceRangePush(__func__);

  /* allocate buffers */
  if(do_zk){
    *zk = (double *) libxc_malloc_flags(sizeof(double)*np*dim->zk, flags);
    libxc_memset_flags(*zk, 0, dim->zk*np*sizeof(double), flags);
  }

#if XC_MAXORDER >= 1
  if(do_vrho){
    *vrho = (double *) libxc_malloc_flags(sizeof(double)*np*dim->vrho, flags);
    libxc_memset_flags(*vrho,   0, dim->vrho  *np*sizeof(double), flags);
    if(is_gga(family)){
      *vsigma = (double *) libxc_malloc_flags(sizeof(double)*np*dim->vsigma, flags);
      libxc_memset_flags(*vsigma, 0, dim->vsigma*np*sizeof(double), flags);
    }
    if(is_mgga(family)){
      *vlapl = (double *) libxc_malloc_flags(sizeof(double)*np*dim->vlapl, flags);
      libxc_memset_flags(*vlapl,  0, dim->vlapl *np*sizeof(double), flags);
      *vtau  = (double *) libxc_malloc_flags(sizeof(double)*np*dim->vtau, flags);
      libxc_memset_flags(*vtau,   0, dim->vtau  *np*sizeof(double), flags);
    }
  }

#if XC_MAXORDER >= 2
  if(do_v2rho2){
    *v2rho2 = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2rho2, flags);
     libxc_memset_flags(*v2rho2,     0, dim->v2rho2     *np*sizeof(double), flags);
    if(is_gga(family)){
      *v2rhosigma  = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2rhosigma, flags);
      libxc_memset_flags(*v2rhosigma, 0, dim->v2rhosigma *np*sizeof(double), flags);
      *v2sigma2    = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2sigma2, flags);
      libxc_memset_flags(*v2sigma2,   0, dim->v2sigma2   *np*sizeof(double), flags);
    }
    if(is_mgga(family)){
      *v2rholapl   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2rholapl, flags);
      libxc_memset_flags(*v2rholapl,   0, dim->v2rholapl  *np*sizeof(double), flags);
      *v2rhotau    = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2rhotau, flags);
      libxc_memset_flags(*v2rhotau,   0, dim->v2rhotau   *np*sizeof(double), flags);
      *v2sigmalapl = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2sigmalapl, flags);
      libxc_memset_flags(*v2sigmalapl, 0, dim->v2sigmalapl*np*sizeof(double), flags);
      *v2sigmatau  = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2sigmatau, flags);
      libxc_memset_flags(*v2sigmatau, 0, dim->v2sigmatau *np*sizeof(double), flags);
      *v2lapl2     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2lapl2, flags);
      libxc_memset_flags(*v2lapl2,     0, dim->v2lapl2    *np*sizeof(double), flags);
      *v2lapltau   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2lapltau, flags);
      libxc_memset_flags(*v2lapltau,   0, dim->v2lapltau  *np*sizeof(double), flags);
      *v2tau2      = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v2tau2, flags);
      libxc_memset_flags(*v2tau2,     0, dim->v2tau2     *np*sizeof(double), flags);
    }
  }

#if XC_MAXORDER >= 3
  if(do_v3rho3){
    *v3rho3      = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rho3, flags);
    libxc_memset_flags(*v3rho3,        0, dim->v3rho3       *np*sizeof(double), flags);
    if(is_gga(family)){
      *v3rho2sigma = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rho2sigma, flags);
      libxc_memset_flags(*v3rho2sigma,   0, dim->v3rho2sigma  *np*sizeof(double), flags);
      *v3rhosigma2 = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rhosigma2, flags);
      libxc_memset_flags(*v3rhosigma2,   0, dim->v3rhosigma2  *np*sizeof(double), flags);
      *v3sigma3    = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3sigma3, flags);
      libxc_memset_flags(*v3sigma3,      0, dim->v3sigma3     *np*sizeof(double), flags);
    }
    if(is_mgga(family)){
      *v3rho2lapl     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rho2lapl, flags);
      libxc_memset_flags(*v3rho2lapl,     0, dim->v3rho2lapl    *np*sizeof(double), flags);
      *v3rho2tau      = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rho2tau, flags);
      libxc_memset_flags(*v3rho2tau,     0, dim->v3rho2tau    *np*sizeof(double), flags);
      *v3rhosigmalapl = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rhosigmalapl, flags);
      libxc_memset_flags(*v3rhosigmalapl, 0, dim->v3rhosigmalapl*np*sizeof(double), flags);
      *v3rhosigmatau  = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rhosigmatau, flags);
      libxc_memset_flags(*v3rhosigmatau, 0, dim->v3rhosigmatau*np*sizeof(double), flags);
      *v3rholapl2     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rholapl2, flags);
      libxc_memset_flags(*v3rholapl2,     0, dim->v3rholapl2    *np*sizeof(double), flags);
      *v3rholapltau   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rholapltau, flags);
      libxc_memset_flags(*v3rholapltau,   0, dim->v3rholapltau  *np*sizeof(double), flags);
      *v3rhotau2      = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3rhotau2, flags);
      libxc_memset_flags(*v3rhotau2,     0, dim->v3rhotau2    *np*sizeof(double), flags);
      *v3sigma2lapl   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3sigma2lapl, flags);
      libxc_memset_flags(*v3sigma2lapl,   0, dim->v3sigma2lapl  *np*sizeof(double), flags);
      *v3sigma2tau    = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3sigma2tau, flags);
      libxc_memset_flags(*v3sigma2tau,   0, dim->v3sigma2tau  *np*sizeof(double), flags);
      *v3sigmalapl2   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3sigmalapl2, flags);
      libxc_memset_flags(*v3sigmalapl2,   0, dim->v3sigmalapl2  *np*sizeof(double), flags);
      *v3sigmalapltau = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3sigmalapltau, flags);
      libxc_memset_flags(*v3sigmalapltau, 0, dim->v3sigmalapltau*np*sizeof(double), flags);
      *v3sigmatau2    = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3sigmatau2, flags);
      libxc_memset_flags(*v3sigmatau2,   0, dim->v3sigmatau2  *np*sizeof(double), flags);
      *v3lapl3        = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3lapl3, flags);
      libxc_memset_flags(*v3lapl3,        0, dim->v3lapl3       *np*sizeof(double), flags);
      *v3lapl2tau     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3lapl2tau, flags);
      libxc_memset_flags(*v3lapl2tau,     0, dim->v3lapl2tau    *np*sizeof(double), flags);
      *v3lapltau2     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3lapltau2, flags);
      libxc_memset_flags(*v3lapltau2,     0, dim->v3lapltau2    *np*sizeof(double), flags);
      *v3tau3         = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v3tau3, flags);
      libxc_memset_flags(*v3tau3,        0, dim->v3tau3       *np*sizeof(double), flags);
    }
  }

#if XC_MAXORDER >= 4
  if(do_v4rho4){
    *v4rho4            = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho4, flags);
    libxc_memset_flags(*v4rho4,         0, dim->v4rho4        *np*sizeof(double), flags);
    if(is_gga(family)){
      *v4rho3sigma       = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho3sigma, flags);
      libxc_memset_flags(*v4rho3sigma,    0, dim->v4rho3sigma   *np*sizeof(double), flags);
      *v4rho2sigma2      = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho2sigma2, flags);
      libxc_memset_flags(*v4rho2sigma2,   0, dim->v4rho2sigma2  *np*sizeof(double), flags);
      *v4rhosigma3       = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rhosigma3, flags);
      libxc_memset_flags(*v4rhosigma3,    0, dim->v4rhosigma3   *np*sizeof(double), flags);
      *v4sigma4          = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigma4, flags);
      libxc_memset_flags(*v4sigma4,       0, dim->v4sigma4      *np*sizeof(double), flags);
    }
    if(is_mgga(family)){
      *v4rho3lapl        = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho3lapl, flags);
      libxc_memset_flags(*v4rho3lapl,        0, dim->v4rho3lapl       *np*sizeof(double), flags);
      *v4rho3tau         = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho3tau, flags);
      libxc_memset_flags(*v4rho3tau,      0, dim->v4rho3tau     *np*sizeof(double), flags);
      *v4rho2sigmalapl   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho2sigmalapl, flags);
      libxc_memset_flags(*v4rho2sigmalapl,   0, dim->v4rho2sigmalapl  *np*sizeof(double), flags);
      *v4rho2sigmatau    = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho2sigmatau, flags);
      libxc_memset_flags(*v4rho2sigmatau, 0, dim->v4rho2sigmatau*np*sizeof(double), flags);
      *v4rho2lapl2       = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho2lapl2, flags);
      libxc_memset_flags(*v4rho2lapl2,       0, dim->v4rho2lapl2      *np*sizeof(double), flags);
      *v4rho2lapltau     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho2lapltau, flags);
      libxc_memset_flags(*v4rho2lapltau,     0, dim->v4rho2lapltau    *np*sizeof(double), flags);
      *v4rho2tau2        = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rho2tau2, flags);
      libxc_memset_flags(*v4rho2tau2,     0, dim->v4rho2tau2    *np*sizeof(double), flags);
      *v4rhosigma2lapl   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rhosigma2lapl, flags);
      libxc_memset_flags(*v4rhosigma2lapl,   0, dim->v4rhosigma2lapl  *np*sizeof(double), flags);
      *v4rhosigma2tau    = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rhosigma2tau, flags);
      libxc_memset_flags(*v4rho2sigmatau, 0, dim->v4rho2sigmatau*np*sizeof(double), flags);
      *v4rhosigmalapl2   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rhosigmalapl2, flags);
      libxc_memset_flags(*v4rhosigmalapl2,   0, dim->v4rhosigmalapl2  *np*sizeof(double), flags);
      *v4rhosigmalapltau = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rhosigmalapltau, flags);
      libxc_memset_flags(*v4rhosigmalapltau, 0, dim->v4rhosigmalapltau*np*sizeof(double), flags);
      *v4rhosigmatau2    = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rhosigmatau2, flags);
      libxc_memset_flags(*v4rhosigmatau2, 0, dim->v4rhosigmatau2*np*sizeof(double), flags);
      *v4rholapl3        = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rholapl3, flags);
      libxc_memset_flags(*v4rholapl3,        0, dim->v4rholapl3       *np*sizeof(double), flags);
      *v4rholapl2tau     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rholapl2tau, flags);
      libxc_memset_flags(*v4rholapl2tau,     0, dim->v4rholapl2tau    *np*sizeof(double), flags);
      *v4rholapltau2     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rholapltau2, flags);
      libxc_memset_flags(*v4rholapltau2,     0, dim->v4rholapltau2    *np*sizeof(double), flags);
      *v4rhotau3         = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4rhotau3, flags);
      libxc_memset_flags(*v4rhotau3,      0, dim->v4rhotau3     *np*sizeof(double), flags);
      *v4sigma3lapl      = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigma3lapl, flags);
      libxc_memset_flags(*v4sigma3lapl,      0, dim->v4sigma3lapl     *np*sizeof(double), flags);
      *v4sigma3tau       = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigma3tau, flags);
      libxc_memset_flags(*v4sigma3tau,    0, dim->v4sigma3tau   *np*sizeof(double), flags);
      *v4sigma2lapl2     = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigma2lapl2, flags);
      libxc_memset_flags(*v4sigma2lapl2,     0, dim->v4sigma2lapl2    *np*sizeof(double), flags);
      *v4sigma2lapltau   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigma2lapltau, flags);
      libxc_memset_flags(*v4sigma2lapltau,   0, dim->v4sigma2lapltau  *np*sizeof(double), flags);
      *v4sigma2tau2      = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigma2tau2, flags);
      libxc_memset_flags(*v4sigma2tau2,   0, dim->v4sigma2tau2  *np*sizeof(double), flags);
      *v4sigmalapl3      = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigmalapl3, flags);
      libxc_memset_flags(*v4sigmalapl3,      0, dim->v4sigmalapl3     *np*sizeof(double), flags);
      *v4sigmalapl2tau   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigmalapl2tau, flags);
      libxc_memset_flags(*v4sigmalapl2tau,   0, dim->v4sigmalapl2tau  *np*sizeof(double), flags);
      *v4sigmalapltau2   = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigmalapltau2, flags);
      libxc_memset_flags(*v4sigmalapl2tau,   0, dim->v4sigmalapl2tau  *np*sizeof(double), flags);
      *v4sigmatau3       = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4sigmatau3, flags);
      libxc_memset_flags(*v4sigmatau3,    0, dim->v4sigmatau3   *np*sizeof(double), flags);
      *v4lapl4           = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4lapl4, flags);
      libxc_memset_flags(*v4lapl4,           0, dim->v4lapl4          *np*sizeof(double), flags);
      *v4lapl3tau        = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4lapl3tau, flags);
      libxc_memset_flags(*v4lapl3tau,        0, dim->v4lapl3tau       *np*sizeof(double), flags);
      *v4lapl2tau2       = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4lapl2tau2, flags);
      libxc_memset_flags(*v4lapl2tau2,       0, dim->v4lapl2tau2      *np*sizeof(double), flags);
      *v4lapltau3        = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4lapltau3, flags);
      libxc_memset_flags(*v4lapltau3,        0, dim->v4lapltau3       *np*sizeof(double), flags);
      *v4tau4            = (double *) libxc_malloc_flags(sizeof(double)*np*dim->v4tau4, flags);
      libxc_memset_flags(*v4tau4,         0, dim->v4tau4        *np*sizeof(double), flags);
    }
  }
#endif
#endif
#endif
#endif

  traceRangePop(); // __func__
}

void
xc_mgga_vars_free_all_flags(double *zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA double *, ), int flags)
{
  traceRangePush(__func__);

/* mix_func.c already defines safe_free above; this file-local variant (with a
   do/while guard) is what the relocated xc_mgga_vars_free_all_flags body uses.
   Undef first so the redefinition does not warn; #undef'd again at the end. */
#undef safe_free
#define safe_free(pt, flags) do { if(pt != NULL) libxc_free_flags(pt, flags); } while (0)
  /* deallocate internal buffers */
  safe_free(zk, flags);
#if XC_MAXORDER >= 1
  safe_free(vrho, flags);
  safe_free(vsigma, flags);
  safe_free(vlapl, flags);
  safe_free(vtau, flags);

#if XC_MAXORDER >= 2
  safe_free(v2rho2, flags); safe_free(v2rhosigma, flags); safe_free(v2rholapl, flags); safe_free(v2rhotau, flags);
  safe_free(v2sigma2, flags); safe_free(v2sigmalapl, flags); safe_free(v2sigmatau, flags);
  safe_free(v2lapl2, flags); safe_free(v2lapltau, flags); safe_free(v2tau2, flags);

#if XC_MAXORDER >= 3
  safe_free(v3rho3, flags); safe_free(v3rho2sigma, flags); safe_free(v3rho2lapl, flags); safe_free(v3rho2tau, flags);
  safe_free(v3rhosigma2, flags); safe_free(v3rhosigmalapl, flags); safe_free(v3rhosigmatau, flags);
  safe_free(v3rholapl2, flags); safe_free(v3rholapltau, flags); safe_free(v3rhotau2, flags);
  safe_free(v3sigma3, flags); safe_free(v3sigma2lapl, flags); safe_free(v3sigma2tau, flags);
  safe_free(v3sigmalapl2, flags); safe_free(v3sigmalapltau, flags); safe_free(v3sigmatau2, flags);
  safe_free(v3lapl3, flags); safe_free(v3lapl2tau, flags); safe_free(v3lapltau2, flags); safe_free(v3tau3, flags);

#if XC_MAXORDER >= 4
  safe_free(v4rho4, flags); safe_free(v4rho3sigma, flags); safe_free(v4rho3lapl, flags); safe_free(v4rho3tau, flags);
  safe_free(v4rho2sigma2, flags); safe_free(v4rho2sigmalapl, flags); safe_free(v4rho2sigmatau, flags);
  safe_free(v4rho2lapl2, flags); safe_free(v4rho2lapltau, flags); safe_free(v4rho2tau2, flags);
  safe_free(v4rhosigma3, flags); safe_free(v4rhosigma2lapl, flags); safe_free(v4rhosigma2tau, flags);
  safe_free(v4rhosigmalapl2, flags); safe_free(v4rhosigmalapltau, flags); safe_free(v4rhosigmatau2, flags);
  safe_free(v4rholapl3, flags); safe_free(v4rholapl2tau, flags); safe_free(v4rholapltau2, flags); safe_free(v4rhotau3, flags);
  safe_free(v4sigma4, flags); safe_free(v4sigma3lapl, flags); safe_free(v4sigma3tau, flags); safe_free(v4sigma2lapl2, flags);
  safe_free(v4sigma2lapltau, flags); safe_free(v4sigma2tau2, flags); safe_free(v4sigmalapl3, flags); safe_free(v4sigmalapl2tau, flags);
  safe_free(v4sigmalapltau2, flags); safe_free(v4sigmatau3, flags); safe_free(v4lapl4, flags); safe_free(v4lapl3tau, flags);
  safe_free(v4lapl2tau2, flags); safe_free(v4lapltau3, flags); safe_free(v4tau4, flags);
#endif
#endif
#endif
#endif
#undef safe_free

  traceRangePop(); // __func__
}

void
xc_mgga_evaluate_functional(const xc_func_type *func, size_t np,
                            const double *rho, const double *sigma, const double *lapl, const double *tau,
                            double *zk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA double *, ))
{
  traceRangePush(__func__);

  double *mzk = NULL;

  if(func->info->flags & XC_FLAGS_HAVE_EXC)
    mzk = zk;
  
  /* Evaluate the functional */
  switch(func->info->family){
  case XC_FAMILY_LDA:
  case XC_FAMILY_HYB_LDA:
    xc_lda(func, np, rho,
           mzk LDA_OUT_PARAMS_NO_EXC(XC_COMMA, ));
    break;
  case XC_FAMILY_GGA:
  case XC_FAMILY_HYB_GGA:
    xc_gga(func, np, rho, sigma,
           mzk GGA_OUT_PARAMS_NO_EXC(XC_COMMA, ));
    break;
  case XC_FAMILY_MGGA:
  case XC_FAMILY_HYB_MGGA:
    xc_mgga(func, np, rho, sigma, lapl, tau,
            mzk MGGA_OUT_PARAMS_NO_EXC(XC_COMMA, ));
    break;
  }

  traceRangePop(); // __func__
}
