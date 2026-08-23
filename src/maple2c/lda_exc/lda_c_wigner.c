/*
  Generated from python/lda_exc/lda_c_wigner.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_wigner
*/

#ifndef _LDA_C_WIGNER_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_WIGNER_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_WIGNER_HELPER_BODIES
#include "lda_c_wigner.c"
#undef _LDA_C_WIGNER_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_WIGNER_HELPER_BODIES
#include "lda_c_wigner.c"
#undef _LDA_C_WIGNER_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_WIGNER_HELPER_BODIES
#include "lda_c_wigner.c"
#undef _LDA_C_WIGNER_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_WIGNER_HELPER_BODIES
#include "lda_c_wigner.c"
#undef _LDA_C_WIGNER_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_WIGNER_HELPER_BODIES
#include "lda_c_wigner.c"
#undef _LDA_C_WIGNER_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_wigner.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_WIGNER_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_c_wigner_params *params = (const lda_c_wigner_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = _t1/M_CBRTPI;
  const double _t3 = _t2/xc_powr(na, 1, 3);
  const double _t4 = (0.1e1 / 0.2e1)*_t3 + params->b;
  const double _t5 = params->a/_t4;
  const double zk = _t5;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t6 = (0.1e1 / (_t4 * _t4));
  const double dF_dna = (0.1e1 / 0.6e1)*_t3*_t6*params->a + _t5;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t7 = (0.1e1 / 0.9e1)*params->a;
  const double _t8 = _t2*_t6;
  const double _t9 = xc_powr(0.6e1, 2, 3)*params->a/((M_CBRTPI * M_CBRTPI)*(_t4 * _t4 * _t4));
  const double _t10 = (0.1e1 / 0.18e2)*_t9;
  const double d2F_dna2 = _t10/xc_powr(na, 5, 3) + _t7*_t8/xc_powr(na, 4, 3);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t11 = (0.1e1 / M_PI);
  const double _t12 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t13 = _t8*params->a;
  const double d3F_dna3 = -_t10/xc_powr(na, 8, 3) + (0.1e1 / 0.6e1)*_t11*_t12*params->a/(na * na * na) - 0.4e1 / 0.27e2*_t13/xc_powr(na, 7, 3);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _t1*_t7/((M_PI * M_CBRTPI)*xc_powi(_t4, 5)*xc_powr(na, 13, 3)) - 0.2e1 / 0.3e1*_t11*_t12*params->a/(na * na * na * na) + (0.28e2 / 0.81e2)*_t13/xc_powr(na, 10, 3) + (0.8e1 / 0.81e2)*_t9/xc_powr(na, 11, 3);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = (0.1e1 / (_t1 * _t1));
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = _t3/M_CBRTPI;
  const double _t5 = params->b + (0.1e1 / 0.2e1)*_t4/xc_powr(_t1, 1, 3);
  const double _t6 = params->a/_t5;
  const double _t7 = 0.4e1*_t6;
  const double _t8 = _t2*_t7;
  const double _t9 = _t8*na;
  const double _t10 = _t9*nb;
  const double zk = _t10;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t11 = _t7/_t1;
  const double _t12 = _t4/(_t5 * _t5);
  const double _t13 = _t12/xc_powr(_t1, 7, 3);
  const double _t14 = (0.2e1 / 0.3e1)*params->a;
  const double _t15 = _t13*_t14;
  const double _t16 = _t15*na;
  const double _t17 = -_t10 + _t16*nb;
  const double dF_dna = _t11*nb + _t17;
  const double dF_dnb = _t11*na + _t17;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t18 = 0.8e1*_t6;
  const double _t19 = _t18*_t2;
  const double _t20 = (0.4e1 / 0.3e1)*params->a;
  const double _t21 = _t13*_t20;
  const double _t22 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t23 = _t18*_t22;
  const double _t24 = _t23*na;
  const double _t25 = _t12*params->a;
  const double _t26 = _t25/xc_powr(_t1, 10, 3);
  const double _t27 = (0.20e2 / 0.9e1)*_t26;
  const double _t28 = _t27*na;
  const double _t29 = xc_powr(0.6e1, 2, 3)/((M_CBRTPI * M_CBRTPI)*(_t5 * _t5 * _t5));
  const double _t30 = _t29/xc_powr(_t1, 11, 3);
  const double _t31 = _t30*params->a;
  const double _t32 = (0.2e1 / 0.9e1)*_t31;
  const double _t33 = _t32*na;
  const double _t34 = _t24*nb - _t28*nb + _t33*nb;
  const double d2F_dna2 = -_t19*nb + _t21*nb + _t34;
  const double d2F_dna_dnb = _t11 + _t15*nb + _t16 + _t34 - _t8*nb - _t9;
  const double d2F_dnb2 = -_t19*na + _t21*na + _t34;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t35 = _t22*_t6;
  const double _t36 = 0.24e2*_t35;
  const double _t37 = (0.20e2 / 0.3e1)*_t26;
  const double _t38 = _t14*_t30;
  const double _t39 = _t6/(_t1 * _t1 * _t1 * _t1);
  const double _t40 = _t39*nb;
  const double _t41 = 0.24e2*_t40;
  const double _t42 = xc_powi(_t1, -5);
  const double _t43 = _t42*nb;
  const double _t44 = _t43*na;
  const double _t45 = 0.1e1/(M_PI*(_t5 * _t5 * _t5 * _t5));
  const double _t46 = _t45*params->a;
  const double _t47 = (0.2e1 / 0.3e1)*_t46;
  const double _t48 = na*nb;
  const double _t49 = _t29*params->a;
  const double _t50 = _t49/xc_powr(_t1, 14, 3);
  const double _t51 = _t25/xc_powr(_t1, 13, 3);
  const double _t52 = -_t41*na + _t44*_t47 - 0.14e2 / 0.9e1*_t48*_t50 + (0.236e3 / 0.27e2)*_t48*_t51;
  const double _t53 = 0.16e2*_t35;
  const double _t54 = (0.40e2 / 0.9e1)*_t26;
  const double _t55 = (0.4e1 / 0.9e1)*_t31;
  const double _t56 = -_t19 + _t21 + _t52;
  const double d3F_dna3 = _t36*nb - _t37*nb + _t38*nb + _t52;
  const double d3F_dna2_dnb = _t24 - _t28 + _t33 + _t53*nb - _t54*nb + _t55*nb + _t56;
  const double d3F_dna_dnb2 = _t23*nb - _t27*nb + _t32*nb + _t53*na - _t54*na + _t55*na + _t56;
  const double d3F_dnb3 = _t36*na - _t37*na + _t38*na + _t52;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t57 = _t43*_t46;
  const double _t58 = _t50*nb;
  const double _t59 = _t51*nb;
  const double _t60 = 0.96e2*_t44*_t6 - 0.8e1*_t46*_t48/xc_powi(_t1, 6) - 0.3392e4 / 0.81e2*_t25*_t48/xc_powr(_t1, 16, 3) + (0.824e3 / 0.81e2)*_t48*_t49/xc_powr(_t1, 17, 3) + (0.4e1 / 0.9e1)*_t3*_t48*params->a/((M_PI * M_CBRTPI)*xc_powr(_t1, 19, 3)*xc_powi(_t5, 5));
  const double _t61 = _t39*na;
  const double _t62 = _t42*na;
  const double _t63 = _t50*na;
  const double _t64 = _t51*na;
  const double _t65 = _t36 - _t37 + _t38 + _t60;
  const double _t66 = _t20*_t45;
  const double _t67 = _t46*_t62;
  const double d4F_dna4 = -0.96e2*_t40 + (0.8e1 / 0.3e1)*_t57 - 0.56e2 / 0.9e1*_t58 + (0.944e3 / 0.27e2)*_t59 + _t60;
  const double d4F_dna3_dnb = -0.72e2*_t40 + _t47*_t62 + 0.2e1*_t57 - 0.14e2 / 0.3e1*_t58 + (0.236e3 / 0.9e1)*_t59 - 0.24e2*_t61 - 0.14e2 / 0.9e1*_t63 + (0.236e3 / 0.27e2)*_t64 + _t65;
  const double d4F_dna2_dnb2 = -0.80e2 / 0.9e1*_t26 + (0.8e1 / 0.9e1)*_t31 + 0.32e2*_t35 - 0.48e2*_t40 + _t43*_t66 - 0.28e2 / 0.9e1*_t58 + (0.472e3 / 0.27e2)*_t59 + _t60 - 0.48e2*_t61 + _t62*_t66 - 0.28e2 / 0.9e1*_t63 + (0.472e3 / 0.27e2)*_t64;
  const double d4F_dna_dnb3 = -_t41 + (0.2e1 / 0.3e1)*_t57 - 0.14e2 / 0.9e1*_t58 + (0.236e3 / 0.27e2)*_t59 - 0.72e2*_t61 - 0.14e2 / 0.3e1*_t63 + (0.236e3 / 0.9e1)*_t64 + _t65 + 0.2e1*_t67;
  const double d4F_dnb4 = _t60 - 0.96e2*_t61 - 0.56e2 / 0.9e1*_t63 + (0.944e3 / 0.27e2)*_t64 + (0.8e1 / 0.3e1)*_t67;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif