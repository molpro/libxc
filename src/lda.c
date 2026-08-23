/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "funcs_lda.c"
#include "funcs_hyb_lda.c"

void
xc_lda_sanity_check(const xc_func_info_type *info, int order, xc_lda_out_params *out)
{
  traceRangePush(__func__);

  /* sanity check */
  if(order < 0 || order > 4){
    fprintf(stderr, "Order of derivatives '%d' not implemented\n",
	    order);
    abort();
  }

  xc_require_implementation(out->zk,     info->flags, XC_FLAGS_HAVE_EXC, info->name, "Exc");
  xc_require_implementation(out->vrho,   info->flags, XC_FLAGS_HAVE_VXC, info->name, "vxc");
  xc_require_implementation(out->v2rho2, info->flags, XC_FLAGS_HAVE_FXC, info->name, "fxc");
  xc_require_implementation(out->v3rho3, info->flags, XC_FLAGS_HAVE_KXC, info->name, "kxc");

  traceRangePop(); // __func__
}


void
xc_lda_initalize(const xc_func_type *func, size_t np, xc_lda_out_params *out)
{
  traceRangePush(__func__);

  const xc_dimensions *dim = &(func->dim);

  /* initialize output */
  if(out->zk != NULL)
    libxc_memset_flags(out->zk,     0, np*sizeof(double)*dim->zk, func->info->flags);

  if(out->vrho != NULL)
    libxc_memset_flags(out->vrho,   0, np*sizeof(double)*dim->vrho, func->info->flags);

  if(out->v2rho2 != NULL)
    libxc_memset_flags(out->v2rho2, 0, np*sizeof(double)*dim->v2rho2, func->info->flags);

  if(out->v3rho3 != NULL)
    libxc_memset_flags(out->v3rho3, 0, np*sizeof(double)*dim->v3rho3, func->info->flags);

  if(out->v4rho4 != NULL)
    libxc_memset_flags(out->v4rho4, 0, np*sizeof(double)*dim->v4rho4, func->info->flags);

  traceRangePop(); // __func__
}


/* get the lda functional */
void
xc_lda_new(const xc_func_type *func, int order, size_t np, const double *rho,
       xc_lda_out_params *out)
{
  traceRangePush(__func__);

  xc_lda_sanity_check(func->info, order, out);
  xc_lda_initalize(func, np, out);

  /* call the LDA routines */
  traceRangePush("evaluate_functional");
  if(func->info->lda != NULL){
    if(func->nspin == XC_UNPOLARIZED){
      if(func->info->lda->unpol[order] != NULL)
        func->info->lda->unpol[order](func, np, rho, out);
    }else{
      if(func->info->lda->pol[order] != NULL)
        func->info->lda->pol[order](func, np, rho, out);
    }
  }
  traceRangePop(); // "evaluate_functional"

  if(func->mix_coef != NULL)
    xc_mix_func(func, np, rho, NULL, NULL, NULL, out->zk, out->vrho, NULL, NULL, NULL,
                out->v2rho2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                out->v3rho3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                out->v4rho4, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                NULL, NULL, NULL, NULL, NULL);

  traceRangePop(); // __func__
}

/* old API */
void
xc_lda(const xc_func_type *p, size_t np, const double *rho, double *zk, double *vrho, double *v2rho2, double *v3rho3, double *v4rho4)
{
  int order = -1;

  if(zk     != NULL) order = 0;
  if(vrho   != NULL) order = 1;
  if(v2rho2 != NULL) order = 2;
  if(v3rho3 != NULL) order = 3;
  if(v4rho4 != NULL) order = 4;

  if(order < 0) return;

  xc_lda_out_params out;
  memset(&out, 0, sizeof(xc_lda_out_params));
  out.zk     = zk;
  out.vrho   = vrho;
  out.v2rho2 = v2rho2;
  out.v3rho3 = v3rho3;
  out.v4rho4 = v4rho4;

  xc_lda_new(p, order, np, rho, &out);
}


/* specializations -- generated from a table (see gga.c for the rationale) */
#define LDA_P0 double *zk
#define LDA_P1 double *vrho
#define LDA_P2 double *v2rho2
#define LDA_P3 double *v3rho3
#define LDA_P4 double *v4rho4
#define LDA_A0 out.zk = zk;
#define LDA_A1 out.vrho = vrho;
#define LDA_A2 out.v2rho2 = v2rho2;
#define LDA_A3 out.v3rho3 = v3rho3;
#define LDA_A4 out.v4rho4 = v4rho4;

#define XC_LDA_WRAPPER(suffix, order, ASGN, ...)                             \
  void xc_lda_##suffix(const xc_func_type *p, size_t np, const double *rho,  \
                       __VA_ARGS__) {                                        \
    xc_lda_out_params out;                                                   \
    memset(&out, 0, sizeof(xc_lda_out_params));                            \
    ASGN                                                                     \
    xc_lda_new(p, order, np, rho, &out);                                     \
  }

XC_LDA_WRAPPER(exc,             0, LDA_A0,                        LDA_P0)
XC_LDA_WRAPPER(vxc,             1, LDA_A1,                        LDA_P1)
XC_LDA_WRAPPER(fxc,             2, LDA_A2,                        LDA_P2)
XC_LDA_WRAPPER(kxc,             3, LDA_A3,                        LDA_P3)
XC_LDA_WRAPPER(lxc,             4, LDA_A4,                        LDA_P4)
XC_LDA_WRAPPER(exc_vxc,         1, LDA_A0 LDA_A1,                 LDA_P0, LDA_P1)
XC_LDA_WRAPPER(vxc_fxc,         2, LDA_A1 LDA_A2,                 LDA_P1, LDA_P2)
XC_LDA_WRAPPER(exc_vxc_fxc,     2, LDA_A0 LDA_A1 LDA_A2,         LDA_P0, LDA_P1, LDA_P2)
XC_LDA_WRAPPER(vxc_fxc_kxc,     3, LDA_A1 LDA_A2 LDA_A3,         LDA_P1, LDA_P2, LDA_P3)
XC_LDA_WRAPPER(exc_vxc_fxc_kxc, 3, LDA_A0 LDA_A1 LDA_A2 LDA_A3, LDA_P0, LDA_P1, LDA_P2, LDA_P3)

#undef LDA_P0
#undef LDA_P1
#undef LDA_P2
#undef LDA_P3
#undef LDA_P4
#undef LDA_A0
#undef LDA_A1
#undef LDA_A2
#undef LDA_A3
#undef LDA_A4
#undef XC_LDA_WRAPPER
