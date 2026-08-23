/*
  Generated from python/lda_exc/lda_xc_1d_ehwlrg.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_xc_1d_ehwlrg
*/

#ifndef _LDA_XC_1D_EHWLRG_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_XC_1D_EHWLRG_KERNEL_BODY
#define _KMAX 0
#define _LDA_XC_1D_EHWLRG_HELPER_BODIES
#include "lda_xc_1d_ehwlrg.c"
#undef _LDA_XC_1D_EHWLRG_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_XC_1D_EHWLRG_HELPER_BODIES
#include "lda_xc_1d_ehwlrg.c"
#undef _LDA_XC_1D_EHWLRG_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_XC_1D_EHWLRG_HELPER_BODIES
#include "lda_xc_1d_ehwlrg.c"
#undef _LDA_XC_1D_EHWLRG_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_XC_1D_EHWLRG_HELPER_BODIES
#include "lda_xc_1d_ehwlrg.c"
#undef _LDA_XC_1D_EHWLRG_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_XC_1D_EHWLRG_HELPER_BODIES
#include "lda_xc_1d_ehwlrg.c"
#undef _LDA_XC_1D_EHWLRG_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_xc_1d_ehwlrg.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_XC_1D_EHWLRG_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_xc_1d_ehwlrg_params *params = (const lda_xc_1d_ehwlrg_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = pow(na, params->alpha);
  const double _t2 = (na * na);
  const double _t3 = _t1*(_t2*params->a3 + na*params->a2 + params->a1);
  const double zk = _t3;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t4 = 0.2e1*na*params->a3;
  const double _t5 = _t1*(_t4 + params->a2);
  const double _t6 = _t3*params->alpha;
  const double dF_dna = _t3 + _t5*na + _t6;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t7 = 0.2e1*_t5;
  const double _t8 = (0.1e1 / na);
  const double _t9 = ((params->alpha) * (params->alpha));
  const double _t10 = _t3*_t9;
  const double d2F_dna2 = _t1*_t4 + _t10*_t8 + _t6*_t8 + _t7*params->alpha + _t7;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t11 = _t1*params->a3;
  const double _t12 = 0.6e1*_t11;
  const double _t13 = 0.3e1*_t5;
  const double _t14 = _t8*params->alpha;
  const double _t15 = _t8*_t9;
  const double _t16 = (0.1e1 / _t2);
  const double _t17 = ((params->alpha) * (params->alpha) * (params->alpha));
  const double _t18 = _t17*_t3;
  const double d3F_dna3 = _t12*params->alpha + _t12 + _t13*_t14 + _t13*_t15 + _t16*_t18 - _t16*_t6;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t19 = 0.12e2*_t11;
  const double _t20 = 0.4e1*_t16*_t5;
  const double _t21 = (0.1e1 / (na * na * na));
  const double _t22 = 0.2e1*_t21;
  const double d4F_dna4 = -_t10*_t21 + _t14*_t19 + _t15*_t19 + _t17*_t20 - _t18*_t22 - _t20*params->alpha + _t21*_t3*((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha)) + _t22*_t6;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = pow(_t1, params->alpha);
  const double _t3 = (_t1 * _t1);
  const double _t4 = _t2*(_t1*params->a2 + _t3*params->a3 + params->a1);
  const double zk = _t4;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t5 = _t2*(params->a2 + params->a3*(0.2e1*na + 0.2e1*nb));
  const double _t6 = _t4*params->alpha;
  const double _t7 = _t1*_t5 + _t4 + _t6;
  const double dF_dna = _t7;
  const double dF_dnb = _t7;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t8 = _t2*params->a3;
  const double _t9 = 0.2e1*_t5;
  const double _t10 = (0.1e1 / _t1);
  const double _t11 = ((params->alpha) * (params->alpha));
  const double _t12 = _t11*_t4;
  const double _t13 = 0.2e1*_t1*_t8 + _t10*_t12 + _t10*_t6 + _t9*params->alpha + _t9;
  const double d2F_dna2 = _t13;
  const double d2F_dna_dnb = _t13;
  const double d2F_dnb2 = _t13;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t14 = 0.6e1*_t8;
  const double _t15 = 0.3e1*_t5;
  const double _t16 = _t10*params->alpha;
  const double _t17 = _t10*_t11;
  const double _t18 = (0.1e1 / _t3);
  const double _t19 = ((params->alpha) * (params->alpha) * (params->alpha));
  const double _t20 = _t19*_t4;
  const double _t21 = _t14*params->alpha + _t14 + _t15*_t16 + _t15*_t17 + _t18*_t20 - _t18*_t6;
  const double d3F_dna3 = _t21;
  const double d3F_dna2_dnb = _t21;
  const double d3F_dna_dnb2 = _t21;
  const double d3F_dnb3 = _t21;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t22 = 0.12e2*_t8;
  const double _t23 = 0.4e1*_t18*_t5;
  const double _t24 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t25 = 0.2e1*_t24;
  const double _t26 = -_t12*_t24 + _t16*_t22 + _t17*_t22 + _t19*_t23 - _t20*_t25 - _t23*params->alpha + _t24*_t4*((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha)) + _t25*_t6;
  const double d4F_dna4 = _t26;
  const double d4F_dna3_dnb = _t26;
  const double d4F_dna2_dnb2 = _t26;
  const double d4F_dna_dnb3 = _t26;
  const double d4F_dnb4 = _t26;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif