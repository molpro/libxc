/*
  Generated from python/lda_exc/lda_xc_zlp.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_xc_zlp
*/

#ifndef _LDA_XC_ZLP_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_XC_ZLP_KERNEL_BODY
#define _KMAX 0
#define _LDA_XC_ZLP_HELPER_BODIES
#include "lda_xc_zlp.c"
#undef _LDA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_XC_ZLP_HELPER_BODIES
#include "lda_xc_zlp.c"
#undef _LDA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_XC_ZLP_HELPER_BODIES
#include "lda_xc_zlp.c"
#undef _LDA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_XC_ZLP_HELPER_BODIES
#include "lda_xc_zlp.c"
#undef _LDA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_XC_ZLP_HELPER_BODIES
#include "lda_xc_zlp.c"
#undef _LDA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_XC_ZLP_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = 105.55627099250339*_t1;
  const double _t3 = xc_x_minus_log1p(_t2);
  const double _t4 = _t3*xc_powr(na, 2, 3);
  const double zk = -0.0088314980364000012*_t4;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t5 = _t2 + 0.1e1;
  const double _t6 = (0.1e1 / _t5);
  const double dF_dna = -0.014719163394000003*_t4 + 32.800555648210505*_t6;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t7 = xc_powr(na, -4, 3);
  const double _t8 = (0.1e1 / (_t5 * _t5));
  const double d2F_dna2 = -0.0098127755960000021*_t1*_t3 + 54.667592747017508*_t6/na + 1154.1014469023985*_t7*_t8;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t9 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t10 = xc_powr(na, -7, 3);
  const double d3F_dna3 = 384.70048230079942*_t10*_t8 + 0.0032709251986666674*_t3*_t7 - 18.2225309156725*_t6/(na * na) + 81215.096721379887*_t9/xc_powr(na, 8, 3);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = -0.0043612335982222226*_t10*_t3 + 24.296707887563329*_t6/(na * na * na) - 1538.8019292031977*_t8/xc_powr(na, 10, 3) - 189501.89234988642*_t9/xc_powr(na, 11, 3) + 8572762.7582043484/((_t5 * _t5 * _t5 * _t5)*(na * na * na * na));
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(_t1, -1, 3);
  const double _t3 = 105.55627099250339*_t2;
  const double _t4 = xc_x_minus_log1p(_t3);
  const double _t5 = xc_powr(_t1, 2, 3)*_t4;
  const double zk = -0.0088314980364000012*_t5;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t6 = _t3 + 0.1e1;
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = -0.014719163394000003*_t5 + 32.800555648210505*_t7;
  const double dF_dna = _t8;
  const double dF_dnb = _t8;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t9 = xc_powr(_t1, -4, 3);
  const double _t10 = (0.1e1 / (_t6 * _t6));
  const double _t11 = 1154.1014469023985*_t10*_t9 - 0.0098127755960000021*_t2*_t4 + 54.667592747017508*_t7/_t1;
  const double d2F_dna2 = _t11;
  const double d2F_dna_dnb = _t11;
  const double d2F_dnb2 = _t11;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t12 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t13 = xc_powr(_t1, -7, 3);
  const double _t14 = 384.70048230079942*_t10*_t13 + 0.0032709251986666674*_t4*_t9 - 18.2225309156725*_t7/(_t1 * _t1) + 81215.096721379887*_t12/xc_powr(_t1, 8, 3);
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
  const double _t15 = -0.0043612335982222226*_t13*_t4 + 24.296707887563329*_t7/(_t1 * _t1 * _t1) + 8572762.7582043484/((_t1 * _t1 * _t1 * _t1)*(_t6 * _t6 * _t6 * _t6)) - 1538.8019292031977*_t10/xc_powr(_t1, 10, 3) - 189501.89234988642*_t12/xc_powr(_t1, 11, 3);
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