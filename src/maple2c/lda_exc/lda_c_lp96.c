/*
  Generated from python/lda_exc/lda_c_lp96.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_lp96
*/

#ifndef _LDA_C_LP96_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_LP96_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_LP96_HELPER_BODIES
#include "lda_c_lp96.c"
#undef _LDA_C_LP96_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_LP96_HELPER_BODIES
#include "lda_c_lp96.c"
#undef _LDA_C_LP96_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_LP96_HELPER_BODIES
#include "lda_c_lp96.c"
#undef _LDA_C_LP96_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_LP96_HELPER_BODIES
#include "lda_c_lp96.c"
#undef _LDA_C_LP96_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_LP96_HELPER_BODIES
#include "lda_c_lp96.c"
#undef _LDA_C_LP96_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_lp96.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_LP96_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_c_lp96_params *params = (const lda_c_lp96_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = params->C1 + params->C4/na + params->C2/xc_powr(na, 1, 3) + params->C3/xc_powr(na, 2, 3);
  const double zk = _t1;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t2 = params->C4/(na * na);
  const double _t3 = params->C3/xc_powr(na, 5, 3);
  const double _t4 = params->C2/xc_powr(na, 4, 3);
  const double dF_dna = _t1 + na*(-_t2 - 0.2e1 / 0.3e1*_t3 - 0.1e1 / 0.3e1*_t4);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t5 = params->C4/(na * na * na);
  const double _t6 = params->C3/xc_powr(na, 8, 3);
  const double _t7 = params->C2/xc_powr(na, 7, 3);
  const double d2F_dna2 = -0.2e1*_t2 - 0.4e1 / 0.3e1*_t3 - 0.2e1 / 0.3e1*_t4 + na*(0.2e1*_t5 + (0.10e2 / 0.9e1)*_t6 + (0.4e1 / 0.9e1)*_t7);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t8 = params->C4/(na * na * na * na);
  const double _t9 = params->C3/xc_powr(na, 11, 3);
  const double _t10 = params->C2/xc_powr(na, 10, 3);
  const double d3F_dna3 = 0.6e1*_t5 + (0.10e2 / 0.3e1)*_t6 + (0.4e1 / 0.3e1)*_t7 + na*(-0.28e2 / 0.27e2*_t10 - 0.6e1*_t8 - 0.80e2 / 0.27e2*_t9);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = -0.112e3 / 0.27e2*_t10 - 0.24e2*_t8 - 0.320e3 / 0.27e2*_t9 + na*(0.24e2*params->C4/xc_powi(na, 5) + (0.280e3 / 0.81e2)*params->C2/xc_powr(na, 13, 3) + (0.880e3 / 0.81e2)*params->C3/xc_powr(na, 14, 3));
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = params->C1 + params->C4/_t1 + params->C2/xc_powr(_t1, 1, 3) + params->C3/xc_powr(_t1, 2, 3);
  const double zk = _t2;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t3 = params->C4/(_t1 * _t1);
  const double _t4 = params->C2/xc_powr(_t1, 4, 3);
  const double _t5 = params->C3/xc_powr(_t1, 5, 3);
  const double _t6 = _t1*(-_t3 - 0.1e1 / 0.3e1*_t4 - 0.2e1 / 0.3e1*_t5) + _t2;
  const double dF_dna = _t6;
  const double dF_dnb = _t6;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t7 = params->C2/xc_powr(_t1, 7, 3);
  const double _t8 = params->C3/xc_powr(_t1, 8, 3);
  const double _t9 = params->C4/(_t1 * _t1 * _t1);
  const double _t10 = _t1*((0.4e1 / 0.9e1)*_t7 + (0.10e2 / 0.9e1)*_t8 + 0.2e1*_t9) - 0.2e1*_t3 - 0.2e1 / 0.3e1*_t4 - 0.4e1 / 0.3e1*_t5;
  const double d2F_dna2 = _t10;
  const double d2F_dna_dnb = _t10;
  const double d2F_dnb2 = _t10;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t11 = params->C2/xc_powr(_t1, 10, 3);
  const double _t12 = params->C3/xc_powr(_t1, 11, 3);
  const double _t13 = params->C4/(_t1 * _t1 * _t1 * _t1);
  const double _t14 = _t1*(-0.28e2 / 0.27e2*_t11 - 0.80e2 / 0.27e2*_t12 - 0.6e1*_t13) + (0.4e1 / 0.3e1)*_t7 + (0.10e2 / 0.3e1)*_t8 + 0.6e1*_t9;
  const double d3F_dna3 = _t14;
  const double d3F_dna2_dnb = _t14;
  const double d3F_dna_dnb2 = _t14;
  const double d3F_dnb3 = _t14;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t15 = _t1*(0.24e2*params->C4/xc_powi(_t1, 5) + (0.280e3 / 0.81e2)*params->C2/xc_powr(_t1, 13, 3) + (0.880e3 / 0.81e2)*params->C3/xc_powr(_t1, 14, 3)) - 0.112e3 / 0.27e2*_t11 - 0.320e3 / 0.27e2*_t12 - 0.24e2*_t13;
  const double d4F_dna4 = _t15;
  const double d4F_dna3_dnb = _t15;
  const double d4F_dna2_dnb2 = _t15;
  const double d4F_dna_dnb3 = _t15;
  const double d4F_dnb4 = _t15;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif