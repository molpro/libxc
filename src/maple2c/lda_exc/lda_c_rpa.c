/*
  Generated from python/lda_exc/lda_c_rpa.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_rpa
*/

#ifndef _LDA_C_RPA_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_RPA_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_RPA_HELPER_BODIES
#include "lda_c_rpa.c"
#undef _LDA_C_RPA_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_RPA_HELPER_BODIES
#include "lda_c_rpa.c"
#undef _LDA_C_RPA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_RPA_HELPER_BODIES
#include "lda_c_rpa.c"
#undef _LDA_C_RPA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_RPA_HELPER_BODIES
#include "lda_c_rpa.c"
#undef _LDA_C_RPA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_RPA_HELPER_BODIES
#include "lda_c_rpa.c"
#undef _LDA_C_RPA_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_RPA_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3)/M_CBRTPI;
  const double _t2 = _t1/xc_powr(na, 1, 3);
  const double _t3 = log((0.1e1 / 0.2e1)*_t2);
  const double _t4 = 0.017999999999999999*_t3 - 0.035999999999999997;
  const double _t5 = (0.1e1 / 0.4e1)*_t2*_t4 + 0.031099999999999999*_t3 - 0.048000000000000001;
  const double zk = _t5;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t6 = (0.1e1 / na);
  const double _t7 = _t1/xc_powr(na, 4, 3);
  const double _t8 = _t4*_t7;
  const double dF_dna = _t5 + na*(-0.010366666666666666*_t6 - 0.0014999999999999998*_t7 - 0.1e1 / 0.12e2*_t8);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t9 = (0.1e1 / (na * na));
  const double _t10 = _t1/xc_powr(na, 7, 3);
  const double _t11 = _t10*_t4;
  const double d2F_dna2 = -0.020733333333333333*_t6 - 0.0029999999999999996*_t7 - 0.1e1 / 0.6e1*_t8 + na*(0.0024999999999999996*_t10 + (0.1e1 / 0.9e1)*_t11 + 0.010366666666666666*_t9);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t12 = (0.1e1 / (na * na * na));
  const double _t13 = _t1/xc_powr(na, 10, 3);
  const double _t14 = _t13*_t4;
  const double d3F_dna3 = 0.0074999999999999989*_t10 + (0.1e1 / 0.3e1)*_t11 + 0.031099999999999999*_t9 + na*(-0.020733333333333333*_t12 - 0.0064999999999999988*_t13 - 0.7e1 / 0.27e2*_t14);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t15 = _t1/xc_powr(na, 13, 3);
  const double d4F_dna4 = -0.082933333333333331*_t12 - 0.025999999999999995*_t13 - 0.28e2 / 0.27e2*_t14 + na*((0.70e2 / 0.81e2)*_t15*_t4 + 0.02322222222222222*_t15 + 0.062199999999999998/(na * na * na * na));
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3)/M_CBRTPI;
  const double _t3 = _t2/xc_powr(_t1, 1, 3);
  const double _t4 = log((0.1e1 / 0.2e1)*_t3);
  const double _t5 = 0.017999999999999999*_t4 - 0.035999999999999997;
  const double _t6 = (0.1e1 / 0.4e1)*_t3*_t5 + 0.031099999999999999*_t4 - 0.048000000000000001;
  const double zk = _t6;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t7 = (0.1e1 / _t1);
  const double _t8 = _t2/xc_powr(_t1, 4, 3);
  const double _t9 = _t5*_t8;
  const double _t10 = _t1*(-0.010366666666666666*_t7 - 0.0014999999999999998*_t8 - 0.1e1 / 0.12e2*_t9) + _t6;
  const double dF_dna = _t10;
  const double dF_dnb = _t10;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t11 = (0.1e1 / (_t1 * _t1));
  const double _t12 = _t2/xc_powr(_t1, 7, 3);
  const double _t13 = _t12*_t5;
  const double _t14 = _t1*(0.010366666666666666*_t11 + 0.0024999999999999996*_t12 + (0.1e1 / 0.9e1)*_t13) - 0.020733333333333333*_t7 - 0.0029999999999999996*_t8 - 0.1e1 / 0.6e1*_t9;
  const double d2F_dna2 = _t14;
  const double d2F_dna_dnb = _t14;
  const double d2F_dnb2 = _t14;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t15 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t16 = _t2/xc_powr(_t1, 10, 3);
  const double _t17 = _t16*_t5;
  const double _t18 = _t1*(-0.020733333333333333*_t15 - 0.0064999999999999988*_t16 - 0.7e1 / 0.27e2*_t17) + 0.031099999999999999*_t11 + 0.0074999999999999989*_t12 + (0.1e1 / 0.3e1)*_t13;
  const double d3F_dna3 = _t18;
  const double d3F_dna2_dnb = _t18;
  const double d3F_dna_dnb2 = _t18;
  const double d3F_dnb3 = _t18;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t19 = _t2/xc_powr(_t1, 13, 3);
  const double _t20 = _t1*((0.70e2 / 0.81e2)*_t19*_t5 + 0.02322222222222222*_t19 + 0.062199999999999998/(_t1 * _t1 * _t1 * _t1)) - 0.082933333333333331*_t15 - 0.025999999999999995*_t16 - 0.28e2 / 0.27e2*_t17;
  const double d4F_dna4 = _t20;
  const double d4F_dna3_dnb = _t20;
  const double d4F_dna2_dnb2 = _t20;
  const double d4F_dna_dnb3 = _t20;
  const double d4F_dnb4 = _t20;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif