/*
  Generated from python/lda_exc/lda_xc_th_fl.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_xc_th_fl
*/

#ifndef _LDA_XC_TH_FL_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_XC_TH_FL_KERNEL_BODY
#define _KMAX 0
#define _LDA_XC_TH_FL_HELPER_BODIES
#include "lda_xc_th_fl.c"
#undef _LDA_XC_TH_FL_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_XC_TH_FL_HELPER_BODIES
#include "lda_xc_th_fl.c"
#undef _LDA_XC_TH_FL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_XC_TH_FL_HELPER_BODIES
#include "lda_xc_th_fl.c"
#undef _LDA_XC_TH_FL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_XC_TH_FL_HELPER_BODIES
#include "lda_xc_th_fl.c"
#undef _LDA_XC_TH_FL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_XC_TH_FL_HELPER_BODIES
#include "lda_xc_th_fl.c"
#undef _LDA_XC_TH_FL_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_xc_th_fl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_XC_TH_FL_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_xc_th_fl_params *params = (const lda_xc_th_fl_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(na, 5, 3);
  const double _t2 = M_CBRT2*params->omega[3];
  const double _t3 = xc_powr(na, 3, 2);
  const double _t4 = xc_powr(0.2e1, 1, 2)*params->omega[2];
  const double _t5 = xc_powr(na, 4, 3);
  const double _t6 = xc_powr(0.2e1, 2, 3)*params->omega[1];
  const double _t7 = xc_powr(0.2e1, 5, 6)*params->omega[0];
  const double zk = ((0.1e1 / 0.2e1)*_t1*_t2 + (0.1e1 / 0.2e1)*_t3*_t4 + (0.1e1 / 0.2e1)*_t5*_t6 + (0.1e1 / 0.2e1)*_t7*xc_powr(na, 7, 6))/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t8 = xc_powr(na, 2, 3);
  const double _t9 = xc_powr(na, 1, 2);
  const double _t10 = xc_powr(na, 1, 3);
  const double dF_dna = (0.2e1 / 0.3e1)*_t10*_t6 + (0.5e1 / 0.6e1)*_t2*_t8 + (0.3e1 / 0.4e1)*_t4*_t9 + (0.7e1 / 0.12e2)*_t7*xc_powr(na, 1, 6);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.3e1 / 0.8e1)*_t4/_t9 + (0.2e1 / 0.9e1)*_t6/_t8 + (0.7e1 / 0.72e2)*_t7/xc_powr(na, 5, 6) + (0.5e1 / 0.9e1)*_t2/_t10;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = -0.5e1 / 0.27e2*_t2/_t5 - 0.35e2 / 0.432e3*_t7/xc_powr(na, 11, 6) - 0.3e1 / 0.16e2*_t4/_t3 - 0.4e1 / 0.27e2*_t6/_t1;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.20e2 / 0.81e2)*_t2/xc_powr(na, 7, 3) + (0.9e1 / 0.32e2)*_t4/xc_powr(na, 5, 2) + (0.20e2 / 0.81e2)*_t6/xc_powr(na, 8, 3) + (0.385e3 / 0.2592e4)*_t7/xc_powr(na, 17, 6);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = xc_powr(na, 4, 3);
  const double _t2 = xc_powr(nb, 4, 3);
  const double _t3 = xc_powr(na, 3, 2);
  const double _t4 = xc_powr(nb, 3, 2);
  const double _t5 = xc_powr(na, 5, 3);
  const double _t6 = xc_powr(nb, 5, 3);
  const double zk = (params->omega[0]*(xc_powr(na, 7, 6) + xc_powr(nb, 7, 6)) + params->omega[1]*(_t1 + _t2) + params->omega[2]*(_t3 + _t4) + params->omega[3]*(_t5 + _t6))/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t7 = (0.7e1 / 0.6e1)*params->omega[0];
  const double _t8 = xc_powr(na, 1, 3);
  const double _t9 = (0.4e1 / 0.3e1)*params->omega[1];
  const double _t10 = xc_powr(na, 1, 2);
  const double _t11 = (0.3e1 / 0.2e1)*params->omega[2];
  const double _t12 = xc_powr(na, 2, 3);
  const double _t13 = (0.5e1 / 0.3e1)*params->omega[3];
  const double _t14 = xc_powr(nb, 1, 3);
  const double _t15 = xc_powr(nb, 1, 2);
  const double _t16 = xc_powr(nb, 2, 3);
  const double dF_dna = _t10*_t11 + _t12*_t13 + _t7*xc_powr(na, 1, 6) + _t8*_t9;
  const double dF_dnb = _t11*_t15 + _t13*_t16 + _t14*_t9 + _t7*xc_powr(nb, 1, 6);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t17 = (0.7e1 / 0.36e2)*params->omega[0];
  const double _t18 = (0.4e1 / 0.9e1)*params->omega[1];
  const double _t19 = (0.3e1 / 0.4e1)*params->omega[2];
  const double _t20 = (0.10e2 / 0.9e1)*params->omega[3];
  const double d2F_dna2 = _t17/xc_powr(na, 5, 6) + _t20/_t8 + _t18/_t12 + _t19/_t10;
  const double d2F_dnb2 = _t17/xc_powr(nb, 5, 6) + _t18/_t16 + _t19/_t15 + _t20/_t14;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t21 = (0.35e2 / 0.216e3)*params->omega[0];
  const double _t22 = (0.8e1 / 0.27e2)*params->omega[1];
  const double _t23 = (0.3e1 / 0.8e1)*params->omega[2];
  const double _t24 = (0.10e2 / 0.27e2)*params->omega[3];
  const double d3F_dna3 = -_t21/xc_powr(na, 11, 6) - _t22/_t5 - _t23/_t3 - _t24/_t1;
  const double d3F_dnb3 = -_t21/xc_powr(nb, 11, 6) - _t22/_t6 - _t23/_t4 - _t24/_t2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t25 = (0.385e3 / 0.1296e4)*params->omega[0];
  const double _t26 = (0.40e2 / 0.81e2)*params->omega[1];
  const double _t27 = (0.9e1 / 0.16e2)*params->omega[2];
  const double _t28 = (0.40e2 / 0.81e2)*params->omega[3];
  const double d4F_dna4 = _t25/xc_powr(na, 17, 6) + _t26/xc_powr(na, 8, 3) + _t27/xc_powr(na, 5, 2) + _t28/xc_powr(na, 7, 3);
  const double d4F_dnb4 = _t25/xc_powr(nb, 17, 6) + _t26/xc_powr(nb, 8, 3) + _t27/xc_powr(nb, 5, 2) + _t28/xc_powr(nb, 7, 3);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif