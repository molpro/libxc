/*
  Generated from python/lda_vxc/lda_xc_tih.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_xc_tih
*/

#ifndef _LDA_XC_TIH_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_XC_TIH_KERNEL_BODY
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_XC_TIH_HELPER_BODIES
#include "lda_xc_tih.c"
#undef _LDA_XC_TIH_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_XC_TIH_HELPER_BODIES
#include "lda_xc_tih.c"
#undef _LDA_XC_TIH_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_XC_TIH_HELPER_BODIES
#include "lda_xc_tih.c"
#undef _LDA_XC_TIH_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_XC_TIH_HELPER_BODIES
#include "lda_xc_tih.c"
#undef _LDA_XC_TIH_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_xc_tih.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_xc_tih.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_xc_tih.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_xc_tih.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_xc_tih.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_xc_tih.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_xc_tih.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_xc_tih.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_XC_TIH_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(tih_vxc_k, _KMAX)(const xc_func_type *p, double n, double *out) {

  const double _t1 = tanh(0.0049657700000000004*n - 1.4106300000000001);
  const double _t2 = tanh(0.0104352*n - 0.42016599999999998);
  const double _t3 = tanh(0.033478899999999999*n + 1.0952999999999999);
  const double _t4 = tanh(0.039083699999999999*n - 0.35469099999999998);
  const double _t5 = tanh(0.136598*n + 0.074853100000000006);
  const double _t6 = tanh(0.15239900000000001*n - 0.414661);
  const double _t7 = tanh(0.44245499999999999*n + 1.4740899999999999);
  const double _t8 = tanh(4.0290499999999998*n + 0.48315000000000002);
#if _KMAX >= 1
  const double _t9 = (_t1 * _t1);
  const double _t10 = (_t2 * _t2);
  const double _t11 = (_t3 * _t3);
  const double _t12 = (_t4 * _t4);
  const double _t13 = (_t5 * _t5);
  const double _t14 = (_t6 * _t6);
  const double _t15 = (_t7 * _t7);
  const double _t16 = (_t8 * _t8);
#endif
#if _KMAX >= 2
  const double _t17 = 0.0099315400000000009 - 0.0099315400000000009*_t9;
  const double _t18 = 0.0045171176462700004*_t17;
  const double _t19 = 0.020870400000000001 - 0.020870400000000001*_t10;
  const double _t20 = 0.0095559822240000002*_t19;
  const double _t21 = 0.066957799999999998 - 0.066957799999999998*_t11;
  const double _t22 = 0.043640080938999994*_t21;
  const double _t23 = 0.078167399999999998 - 0.078167399999999998*_t12;
  const double _t24 = 0.050651693525999998*_t23;
  const double _t25 = 0.27319599999999999 - 0.27319599999999999*_t13;
  const double _t26 = 0.1424785439*_t25;
  const double _t27 = 0.30479800000000001 - 0.30479800000000001*_t14;
  const double _t28 = 0.20882625374000002*_t27;
  const double _t29 = 0.88490999999999997 - 0.88490999999999997*_t15;
  const double _t30 = 0.86290228830000004*_t29;
  const double _t31 = 8.0580999999999996 - 8.0580999999999996*_t16;
  const double _t32 = 3.9959392670999998*_t31;
#endif
#if _KMAX >= 3
  const double _t33 = 4.4861934588636363e-5*_t17;
  const double _t34 = 0.00019943717140776961*_t19;
  const double _t35 = 0.0029220438114973737*_t21;
  const double _t36 = 0.0039593111885242518*_t23;
  const double _t37 = 0.063649824487444523*_t27;
  const double _t38 = 0.763590863939553*_t29;
  const double _t39 = 32.199678208218508*_t31;
  const double _t40 = 0.0049657700000000004 - 0.0049657700000000004*_t9;
  const double _t41 = 0.0104352 - 0.0104352*_t10;
  const double _t42 = 0.033478899999999999 - 0.033478899999999999*_t11;
  const double _t43 = 0.039083699999999999 - 0.039083699999999999*_t12;
  const double _t44 = 0.136598 - 0.136598*_t13;
  const double _t45 = 0.15239900000000001 - 0.15239900000000001*_t14;
  const double _t46 = 0.44245499999999999 - 0.44245499999999999*_t15;
  const double _t47 = 4.0290499999999998 - 4.0290499999999998*_t16;
#endif

  const double f = -0.90965099999999999*_t1 - 0.91574500000000003*_t2 - 1.3035099999999999*_t3 - 1.2959799999999999*_t4 + 1.04305*_t5 - 1.37026*_t6 - 1.9502600000000001*_t7 - 0.99178200000000005*_t8 + 0.62503900000000001;
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = 0.0095559822240000002*_t10 + 0.043640080938999994*_t11 + 0.050651693525999998*_t12 - 0.1424785439*_t13 + 0.20882625374000002*_t14 + 0.86290228830000004*_t15 + 3.9959392670999998*_t16 + 0.0045171176462700004*_t9 - 5.0335541395752701;
  out[1] = df_dn;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = _t1*_t18 + _t2*_t20 + _t22*_t3 + _t24*_t4 - _t26*_t5 + _t28*_t6 + _t30*_t7 + _t32*_t8;
  out[2] = d2f_dn2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = -_t10*_t34 - _t11*_t35 - _t12*_t36 + 0.038924568279304399*_t13*_t25 - _t14*_t37 - _t15*_t38 - _t16*_t39 + _t18*_t40 + _t20*_t41 + _t22*_t42 + _t24*_t43 - _t26*_t44 + _t28*_t45 + _t30*_t46 + _t32*_t47 - _t33*_t9;
  out[3] = d3f_dn3;
#endif
#if _KMAX >= 4
  const double d4f_dn4 = 4.4554809784442562e-7*(_t1 * _t1 * _t1)*_t17 - 6.7292901882954541e-5*_t1*(_t17 * _t17) - _t1*_t33*_t40 - 0.00029915575711165441*(_t19 * _t19)*_t2 + 4.1623335421487151e-6*_t19*(_t2 * _t2 * _t2) - _t2*_t34*_t41 - 0.0043830657172460605*(_t21 * _t21)*_t3 + 0.00019565362512147884*_t21*(_t3 * _t3 * _t3) - 0.0059389667827863778*(_t23 * _t23)*_t4 + 0.00030948906139785059*_t23*(_t4 * _t4 * _t4) + 0.058386852418956595*(_t25 * _t25)*_t5 + 0.038924568279304399*_t25*_t44*_t5 - 0.010634036355632844*_t25*(_t5 * _t5 * _t5) - 0.095474736731166784*(_t27 * _t27)*_t6 + 0.019400339204124116*_t27*(_t6 * _t6 * _t6) - 1.1453862959093295*(_t29 * _t29)*_t7 + 0.67570919140874985*_t29*(_t7 * _t7 * _t7) - _t3*_t35*_t42 - 48.299517312327765*(_t31 * _t31)*_t8 + 259.46822696964557*_t31*(_t8 * _t8 * _t8) - _t36*_t4*_t43 - _t37*_t45*_t6 - _t38*_t46*_t7 - _t39*_t47*_t8;
  out[4] = d4f_dn4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tih_vxc_k, _KMAX)(p, na, _hc0);
  const double vrho_0 = _hc0[0];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += vrho_0;
#if _KMAX >= 2
  const double v2rho2_0 = _hc0[1];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += v2rho2_0;
#endif
#if _KMAX >= 3
  const double v3rho3_0 = _hc0[2];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += v3rho3_0;
#endif
#if _KMAX >= 4
  const double v4rho4_0 = _hc0[3];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += v4rho4_0;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tih_vxc_k, _KMAX)(p, na + nb, _hc0);
  const double vrho_0 = _hc0[0];
  const double vrho_1 = _hc0[0];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += vrho_0;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += vrho_1;
#if _KMAX >= 2
  const double v2rho2_0 = _hc0[1];
  const double v2rho2_1 = _hc0[1];
  const double v2rho2_2 = _hc0[1];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += v2rho2_0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += v2rho2_1;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += v2rho2_2;
#endif
#if _KMAX >= 3
  const double v3rho3_0 = _hc0[2];
  const double v3rho3_1 = _hc0[2];
  const double v3rho3_2 = _hc0[2];
  const double v3rho3_3 = _hc0[2];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += v3rho3_0;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += v3rho3_1;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += v3rho3_2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += v3rho3_3;
#endif
#if _KMAX >= 4
  const double v4rho4_0 = _hc0[3];
  const double v4rho4_1 = _hc0[3];
  const double v4rho4_2 = _hc0[3];
  const double v4rho4_3 = _hc0[3];
  const double v4rho4_4 = _hc0[3];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += v4rho4_0;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += v4rho4_1;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += v4rho4_2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += v4rho4_3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += v4rho4_4;
#endif
#endif
}
#endif