/*
  Generated from python/lda_exc/lda_c_gombas.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_gombas
*/

#ifndef _LDA_C_GOMBAS_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_GOMBAS_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_GOMBAS_HELPER_BODIES
#include "lda_c_gombas.c"
#undef _LDA_C_GOMBAS_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_GOMBAS_HELPER_BODIES
#include "lda_c_gombas.c"
#undef _LDA_C_GOMBAS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_GOMBAS_HELPER_BODIES
#include "lda_c_gombas.c"
#undef _LDA_C_GOMBAS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_GOMBAS_HELPER_BODIES
#include "lda_c_gombas.c"
#undef _LDA_C_GOMBAS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_GOMBAS_HELPER_BODIES
#include "lda_c_gombas.c"
#undef _LDA_C_GOMBAS_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_gombas.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_GOMBAS_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(na, 1, 3);
  const double _t2 = 2.3899999999999997*_t1;
  const double _t3 = 0.1e1 + 0.056199999999999993/_t1;
  const double _t4 = 0.031099999999999999*xc_log1p(_t2) + 0.035700000000000003/_t3;
  const double zk = -_t4;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t5 = xc_powr(na, -4, 3);
  const double _t6 = (0.1e1 / (_t3 * _t3));
  const double _t7 = _t5*_t6;
  const double _t8 = _t2 + 0.1e1;
  const double _t9 = (0.1e1 / _t8);
  const double _t10 = _t9/xc_powr(na, 2, 3);
  const double dF_dna = -_t4 + na*(-0.024776333333333327*_t10 - 0.00066878*_t7);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t11 = xc_powr(na, -8, 3);
  const double _t12 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t13 = _t11*_t12;
  const double _t14 = xc_powr(na, -7, 3);
  const double _t15 = _t14*_t6;
  const double _t16 = _t9/xc_powr(na, 5, 3);
  const double _t17 = (0.1e1 / (_t8 * _t8));
  const double _t18 = _t17*_t5;
  const double d2F_dna2 = -0.049552666666666655*_t10 - 0.00133756*_t7 + na*(-2.505695733333333e-5*_t13 + 0.00089170666666666667*_t15 + 0.016517555555555549*_t16 + 0.019738478888888879*_t18);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t19 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t20 = _t19/(na * na * na * na);
  const double _t21 = xc_powr(na, -11, 3);
  const double _t22 = xc_powr(na, -10, 3);
  const double _t23 = _t22*_t6;
  const double _t24 = _t11*_t9;
  const double _t25 = _t14*_t17;
  const double _t26 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t27 = _t26/(na * na);
  const double d3F_dna3 = -7.5170871999999985e-5*_t13 + 0.00267512*_t15 + 0.049552666666666648*_t16 + 0.059215436666666635*_t18 + na*(0.0001002278293333333*_t12*_t21 - 1.4082010021333329e-6*_t20 - 0.0020806488888888892*_t23 - 0.02752925925925925*_t24 - 0.039476957777777759*_t25 - 0.031449976362962942*_t27);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = 0.00040091131733333322*_t12*_t21 - 5.6328040085333316e-6*_t20 - 0.0083225955555555568*_t23 - 0.110117037037037*_t24 - 0.15790783111111101*_t25 - 0.12579990545185177*_t27 + na*(0.075165443507481416*_t11/(_t8 * _t8 * _t8 * _t8) - 0.00044545701925925913*_t12/xc_powr(na, 14, 3) + 0.11404454469135798*_t17*_t22 + 1.1265608017066661e-5*_t19/xc_powi(na, 5) + 0.073411358024691328*_t21*_t9 + 0.12579990545185177*_t26/(na * na * na) + 0.0069354962962962976*_t6/xc_powr(na, 13, 3) - 1.0552119509319107e-7/(xc_powi(_t3, 5)*xc_powr(na, 16, 3)));
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(_t1, 1, 3);
  const double _t3 = 2.3899999999999997*_t2;
  const double _t4 = 0.1e1 + 0.056199999999999993/_t2;
  const double _t5 = 0.031099999999999999*xc_log1p(_t3) + 0.035700000000000003/_t4;
  const double zk = -_t5;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t6 = (0.1e1 / (_t4 * _t4));
  const double _t7 = xc_powr(_t1, -4, 3);
  const double _t8 = _t6*_t7;
  const double _t9 = _t3 + 0.1e1;
  const double _t10 = (0.1e1 / _t9);
  const double _t11 = _t10/xc_powr(_t1, 2, 3);
  const double _t12 = _t1*(-0.024776333333333327*_t11 - 0.00066878*_t8) - _t5;
  const double dF_dna = _t12;
  const double dF_dnb = _t12;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t13 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t14 = xc_powr(_t1, -8, 3);
  const double _t15 = _t13*_t14;
  const double _t16 = xc_powr(_t1, -7, 3);
  const double _t17 = _t16*_t6;
  const double _t18 = _t10/xc_powr(_t1, 5, 3);
  const double _t19 = (0.1e1 / (_t9 * _t9));
  const double _t20 = _t19*_t7;
  const double _t21 = _t1*(-2.505695733333333e-5*_t15 + 0.00089170666666666667*_t17 + 0.016517555555555549*_t18 + 0.019738478888888879*_t20) - 0.049552666666666655*_t11 - 0.00133756*_t8;
  const double d2F_dna2 = _t21;
  const double d2F_dna_dnb = _t21;
  const double d2F_dnb2 = _t21;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t22 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t23 = _t22/(_t1 * _t1 * _t1 * _t1);
  const double _t24 = xc_powr(_t1, -11, 3);
  const double _t25 = xc_powr(_t1, -10, 3);
  const double _t26 = _t25*_t6;
  const double _t27 = _t10*_t14;
  const double _t28 = _t16*_t19;
  const double _t29 = (0.1e1 / (_t9 * _t9 * _t9));
  const double _t30 = _t29/(_t1 * _t1);
  const double _t31 = _t1*(0.0001002278293333333*_t13*_t24 - 1.4082010021333329e-6*_t23 - 0.0020806488888888892*_t26 - 0.02752925925925925*_t27 - 0.039476957777777759*_t28 - 0.031449976362962942*_t30) - 7.5170871999999985e-5*_t15 + 0.00267512*_t17 + 0.049552666666666648*_t18 + 0.059215436666666635*_t20;
  const double d3F_dna3 = _t31;
  const double d3F_dna2_dnb = _t31;
  const double d3F_dna_dnb2 = _t31;
  const double d3F_dnb3 = _t31;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t32 = _t1*(0.073411358024691328*_t10*_t24 + 0.075165443507481416*_t14/(_t9 * _t9 * _t9 * _t9) + 0.11404454469135798*_t19*_t25 + 0.12579990545185177*_t29/(_t1 * _t1 * _t1) + 1.1265608017066661e-5*_t22/xc_powi(_t1, 5) + 0.0069354962962962976*_t6/xc_powr(_t1, 13, 3) - 0.00044545701925925913*_t13/xc_powr(_t1, 14, 3) - 1.0552119509319107e-7/(xc_powr(_t1, 16, 3)*xc_powi(_t4, 5))) + 0.00040091131733333322*_t13*_t24 - 5.6328040085333316e-6*_t23 - 0.0083225955555555568*_t26 - 0.110117037037037*_t27 - 0.15790783111111101*_t28 - 0.12579990545185177*_t30;
  const double d4F_dna4 = _t32;
  const double d4F_dna3_dnb = _t32;
  const double d4F_dna2_dnb2 = _t32;
  const double d4F_dna_dnb3 = _t32;
  const double d4F_dnb4 = _t32;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif