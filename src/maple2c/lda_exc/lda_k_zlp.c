/*
  Generated from python/lda_exc/lda_k_zlp.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_k_zlp
*/

#ifndef _LDA_K_ZLP_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_K_ZLP_KERNEL_BODY
#define _KMAX 0
#define _LDA_K_ZLP_HELPER_BODIES
#include "lda_k_zlp.c"
#undef _LDA_K_ZLP_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_K_ZLP_HELPER_BODIES
#include "lda_k_zlp.c"
#undef _LDA_K_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_K_ZLP_HELPER_BODIES
#include "lda_k_zlp.c"
#undef _LDA_K_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_K_ZLP_HELPER_BODIES
#include "lda_k_zlp.c"
#undef _LDA_K_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_K_ZLP_HELPER_BODIES
#include "lda_k_zlp.c"
#undef _LDA_K_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_k_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_K_ZLP_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_m1_k, _KMAX)(const xc_func_type *p, double z, double n, double *out) {

  const double _t1 = z + 0.1e1 <= p->zeta_threshold;
  const double _t2 = pow(p->zeta_threshold, n);
  const double _t3 = p->zeta_threshold - 0.1e1;
  const double _t4 = z > _t3;
  const double _t5 = my_piecewise3(_t4, z, _t3);
  const double _t6 = xc_log1p(_t5);
  const double _t7 = _t6*n;
  const double _t8 = xc_expm1(_t7);
#if _KMAX >= 1
  const double _t9 = log(p->zeta_threshold);
  const double _t10 = _t8 + 0.1e1;
  const double _t11 = _t10*_t6;
  const double _t12 = _t5 + 0.1e1;
  const double _t13 = my_piecewise3(_t4, 0.1e1, 0);
  const double _t14 = _t13/_t12;
  const double _t15 = _t10*_t14;
#endif
#if _KMAX >= 2
  const double _t16 = _t10*(_t6 * _t6);
  const double _t17 = (_t13 * _t13)/(_t12 * _t12);
  const double _t18 = _t10*_t17;
  const double _t19 = _t18*n;
  const double _t20 = (n * n);
#endif
#if _KMAX >= 3
  const double _t21 = _t10*(_t6 * _t6 * _t6);
  const double _t22 = 0.2e1*_t11;
  const double _t23 = _t14*_t16;
  const double _t24 = _t18*_t7;
  const double _t25 = _t17*_t20;
  const double _t26 = (_t13 * _t13 * _t13)/(_t12 * _t12 * _t12);
  const double _t27 = _t10*_t26;
  const double _t28 = 0.2e1*_t27;
  const double _t29 = (n * n * n);
  const double _t30 = _t10*_t29;
  const double _t31 = 0.3e1*_t20;
  const double _t32 = _t27*_t31;
#endif
#if _KMAX >= 4
  const double _t33 = 0.6e1*n;
  const double _t34 = _t11*_t26;
  const double _t35 = (_t13 * _t13 * _t13 * _t13)/(_t12 * _t12 * _t12 * _t12);
  const double _t36 = _t10*_t35;
#endif

  const double f = my_piecewise3(_t1, _t2 - 0.1e1, _t8);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = my_piecewise3(_t1, _t2*_t9, _t11);
  out[1] = df_dn;
  const double df_dz = my_piecewise3(_t1, 0, _t15*n);
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = my_piecewise3(_t1, _t2*(_t9 * _t9), _t16);
  out[3] = d2f_dn2;
  const double d2f_dz_dn = my_piecewise3(_t1, 0, _t15*_t7 + _t15);
  out[4] = d2f_dz_dn;
  const double d2f_dz2 = my_piecewise3(_t1, 0, _t18*_t20 - _t19);
  out[5] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = my_piecewise3(_t1, _t2*(_t9 * _t9 * _t9), _t21);
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t1, 0, _t14*_t22 + _t23*n);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t1, 0, _t11*_t25 - _t18 + 0.2e1*_t19 - _t24);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t1, 0, _t26*_t30 + _t28*n - _t32);
  out[9] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dn4 = my_piecewise3(_t1, _t2*(_t9 * _t9 * _t9 * _t9), _t10*(_t6 * _t6 * _t6 * _t6));
  out[10] = d4f_dn4;
  const double d4f_dz_dn3 = my_piecewise3(_t1, 0, _t14*_t21*n + 0.3e1*_t23);
  out[11] = d4f_dz_dn3;
  const double d4f_dz2_dn2 = my_piecewise3(_t1, 0, -_t16*_t17*n + _t16*_t25 - _t17*_t22 + 0.2e1*_t18 + 0.4e1*_t24);
  out[12] = d4f_dz2_dn2;
  const double d4f_dz3_dn = my_piecewise3(_t1, 0, -_t27*_t33 + _t28*_t7 + _t28 + _t29*_t34 - _t31*_t34 + _t32);
  out[13] = d4f_dz3_dn;
  const double d4f_dz4 = my_piecewise3(_t1, 0, 0.11e2*_t20*_t36 - 0.6e1*_t30*_t35 - _t33*_t36 + _t36*(n * n * n * n));
  out[14] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_zeta_k_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.5e1 / 0.3e1, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5];
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = (0.1e1 / 0.2e1)*_hc0[9] - 0.1e1 / 0.2e1*_hc1[9];
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.1e1 / 0.2e1)*_hc0[14] + (0.1e1 / 0.2e1)*_hc1[14];
  out[4] = d4f_dz4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(na, 1, 3);
  const double _t2 = 510.20408163265301/_t1;
  const double _t3 = xc_x_minus_log1p(_t2);
  const double _t4 = xc_powr(0.6e1, 2, 3);
  const double _t5 = M_CBRTPI;
  const double _t6 = _t4*_t5;
  const double zk = 0.0021149706666666662*_t3*_t6*na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t7 = _t2 + 0.1e1;
  const double _t8 = _t6/_t7;
  const double dF_dna = -183.51473922902485*_t1*_t8 + 0.0042299413333333324*_t3*_t4*_t5*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t9 = _t6/(_t7 * _t7);
  const double d2F_dna2 = 0.0042299413333333324*_t3*_t4*_t5 - 428.201058201058*_t8/xc_powr(na, 2, 3) - 31209.989664800141*_t9/na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t10 = 10615642.743129298*_t6/(_t7 * _t7 * _t7);
  const double d3F_dna3 = -_t10/xc_powr(na, 7, 3) - 81.56210632401104*_t8/xc_powr(na, 5, 3) - 41613.31955306686*_t9/(na * na);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _t10/xc_powr(na, 10, 3) - 5416144256.6986208*_t6/((_t7 * _t7 * _t7 * _t7)*xc_powr(na, 11, 3)) + 135.93684387335173*_t8/xc_powr(na, 8, 3) + 69355.532588444767*_t9/(na * na * na);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = xc_powr(_t2, 1, 3);
  const double _t6 = 510.20408163265301/_t5;
  const double _t7 = xc_x_minus_log1p(_t6);
  const double _t8 = xc_powr(0.6e1, 2, 3);
  const double _t9 = M_CBRTPI;
  const double _t10 = _t8*_t9;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k_k, _KMAX)(p, _t4, _hc0);
  const double _t11 = _hc0[0]*_t10;
  const double _t12 = _t11*_t7;
  const double _t13 = 0.0021149706666666662*_t12;
  const double zk = _t13*_t2;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t14 = -_t3;
  const double _t15 = (_t2 * _t2);
  const double _t16 = (0.1e1 / _t15);
  const double _t17 = _t1*_t16;
  const double _t18 = -_t14 - _t17;
  const double _t19 = _t10*_t7;
  const double _t22 = 0.0021149706666666662*_t15;
  const double _t23 = 0.2e1*na;
  const double _t24 = 0.2e1*nb;
  const double _t25 = _t23 + _t24;
  const double _t26 = _t6 + 0.1e1;
  const double _t27 = (0.1e1 / _t26);
  const double _t31 = -_t17 - _t3;
  const double _t20 = _hc0[1]*_t19;
  const double _t21 = _t18*_t20;
  const double _t28 = _t11*_t27;
  const double _t29 = 183.51473922902485*_t28;
  const double _t30 = _t13*_t25 - _t29*_t5;
  const double _t32 = _t20*_t31;
  const double dF_dna = _t21*_t22 + _t30;
  const double dF_dnb = _t22*_t32 + _t30;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t33 = 0.2e1*_t16;
  const double _t34 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t35 = 0.2e1*_t1*_t34;
  const double _t36 = -_t33 + _t35;
  const double _t38 = (_t18 * _t18);
  const double _t41 = _t10*_t27;
  const double _t45 = xc_powr(_t2, -2, 3);
  const double _t46 = 61.17157974300828*_t45;
  const double _t47 = (0.1e1 / (_t26 * _t26));
  const double _t50 = xc_powr(_t2, -5, 3);
  const double _t51 = _t25*_t50;
  const double _t53 = 0.0021149706666666662*_t25;
  const double _t57 = _t18*_t31;
  const double _t58 = _t33 + _t35;
  const double _t60 = (_t31 * _t31);
  const double _t37 = _t20*_t36;
  const double _t39 = _hc0[2]*_t19;
  const double _t40 = _t38*_t39;
  const double _t42 = _hc0[1]*_t41;
  const double _t43 = _t42*_t5;
  const double _t44 = _t18*_t43;
  const double _t48 = _t11*_t47;
  const double _t49 = 31209.989664800141*_t48;
  const double _t52 = 0.0042299413333333324*_t12 - _t28*_t46 - _t29*_t51 - _t3*_t49;
  const double _t54 = 0.0042299413333333324*_t20;
  const double _t55 = _t31*_t43;
  const double _t56 = _t22*_t39;
  const double _t59 = _t20*_t58;
  const double _t61 = _t39*_t60;
  const double d2F_dna2 = 0.0042299413333333324*_t21*_t25 + _t22*_t37 + _t22*_t40 - 367.02947845804971*_t44 + _t52;
  const double d2F_dna_dnb = _t21*_t53 + _t32*_t53 + _t4*_t54 - 183.51473922902485*_t44 + _t52 - 183.51473922902485*_t55 + _t56*_t57;
  const double d2F_dnb2 = _t22*_t59 + _t22*_t61 + 0.0042299413333333324*_t25*_t32 + _t52 - 367.02947845804971*_t55;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t62 = 0.6e1*_t34;
  const double _t63 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t64 = _t1*_t63;
  const double _t65 = 0.6e1*_t64;
  const double _t66 = _t62 - _t65;
  const double _t68 = _t19*_t22;
  const double _t69 = (_t18 * _t18 * _t18);
  const double _t71 = 0.0063449119999999986*_t25;
  const double _t73 = 183.51473922902483*_t45;
  const double _t76 = _t41*_t5;
  const double _t77 = 550.54421768707459*_t76;
  const double _t78 = _t18*_t3;
  const double _t82 = 0.4e1*_t16;
  const double _t83 = 0.4e1*_t1*_t34;
  const double _t84 = -_t82 + _t83;
  const double _t87 = xc_powr(_t2, -7, 3);
  const double _t88 = (0.1e1 / (_t26 * _t26 * _t26));
  const double _t92 = 693.27790375409381*_t50;
  const double _t94 = xc_powr(_t2, -8, 3);
  const double _t96 = _t25*_t34;
  const double _t100 = 122.34315948601656*_t45;
  const double _t101 = 183.51473922902485*_t76;
  const double _t103 = _t3*_t31;
  const double _t105 = 0.2e1*_t34 - _t65;
  const double _t107 = -_t1*_t16;
  const double _t108 = _t107 + _t14;
  const double _t111 = 367.02947845804971*_t76;
  const double _t115 = _t107 + _t3;
  const double _t116 = -_t62 - _t65;
  const double _t117 = (_t31 * _t31 * _t31);
  const double _t120 = _t82 + _t83;
  const double _t67 = _t20*_t22;
  const double _t70 = _hc0[3]*_t69;
  const double _t72 = _t18*_t42;
  const double _t74 = _t36*_t43;
  const double _t75 = _hc0[2]*_t38;
  const double _t79 = _hc0[1]*_t10;
  const double _t80 = _t47*_t79;
  const double _t81 = 93629.96899440042*_t80;
  const double _t85 = _t18*_t56;
  const double _t86 = _t51*_t72;
  const double _t89 = _t11*_t88;
  const double _t90 = 10615642.743129298*_t89;
  const double _t91 = _t87*_t90;
  const double _t93 = _t28*_t92;
  const double _t95 = _t28*_t94;
  const double _t97 = _t49*_t96;
  const double _t98 = 20806.65977653343*_t16*_t48 + 305.85789871504142*_t25*_t95 - _t91 - _t93 - _t97;
  const double _t99 = _t31*_t42;
  const double _t102 = 31209.989664800141*_t80;
  const double _t104 = 62419.979329600283*_t80;
  const double _t106 = _t51*_t99;
  const double _t109 = _t42*_t94;
  const double _t110 = _hc0[2]*_t57;
  const double _t112 = -20806.65977653343*_hc0[0]*_t16*_t47*_t8*_t9 - 305.85789871504142*_hc0[0]*_t25*_t27*_t8*_t9*_t94 - 0.0042299413333333324*_hc0[2]*_t18*_t25*_t31*_t7*_t8*_t9 + 734.05895691609942*_t1*_t109 + _t110*_t111 + _t91 + _t93 + _t97;
  const double _t113 = _t43*_t58;
  const double _t114 = _hc0[2]*_t60;
  const double _t118 = _hc0[3]*_t117;
  const double _t119 = _t31*_t56;
  const double d3F_dna3 = 0.012689823999999997*_t21 + _t36*_t85 + _t37*_t71 + _t40*_t71 + _t66*_t67 + _t68*_t70 - _t72*_t73 - 550.54421768707459*_t74 - _t75*_t77 - _t78*_t81 + _t84*_t85 - 550.54421768707459*_t86 + _t98;
  const double d3F_dna2_dnb = 0.0084598826666666647*_hc0[1]*_t1*_t25*_t34*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[1]*_t105*_t15*_t7*_t8*_t9 + 0.0084598826666666647*_hc0[1]*_t18*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[1]*_t25*_t36*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[1]*_t31*_t7*_t8*_t9 + 0.0084598826666666647*_hc0[2]*_t1*_t18*_t3*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t15*_t31*_t36*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t25*_t38*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t108*_t15*_t38*_t7*_t8*_t9 - _t100*_t72 - _t101*_t75 - _t102*_t103 - _t104*_t78 - 183.51473922902485*_t106 - _t112 - _t46*_t99 - 183.51473922902485*_t74 - 367.02947845804971*_t86;
  const double d3F_dna_dnb2 = 0.0042299413333333324*_hc0[1]*_t1*_t25*_t34*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[1]*_t18*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[1]*_t25*_t58*_t7*_t8*_t9 + 0.0084598826666666647*_hc0[1]*_t31*_t7*_t8*_t9 + 0.0084598826666666647*_hc0[2]*_t1*_t3*_t31*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t15*_t18*_t58*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t25*_t60*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t115*_t15*_t60*_t7*_t8*_t9 - _t100*_t99 - _t101*_t114 - _t102*_t78 - _t103*_t104 - 367.02947845804971*_t106 - _t112 - 183.51473922902485*_t113 - _t17*_t54 - _t3*_t54 - _t46*_t72 - 183.51473922902485*_t86;
  const double d3F_dnb3 = -_t103*_t81 - 550.54421768707459*_t106 - 550.54421768707459*_t113 - _t114*_t77 + _t116*_t67 + _t118*_t68 + _t119*_t120 + _t119*_t58 + 0.012689823999999997*_t32 + _t59*_t71 + _t61*_t71 - _t73*_t99 + _t98;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t121 = 0.24e2*_t63;
  const double _t122 = 0.24e2*_t1/xc_powi(_t2, 5);
  const double _t126 = 0.0084598826666666647*_t25;
  const double _t129 = 367.02947845804965*_t45;
  const double _t132 = 187259.93798880087*_t3;
  const double _t134 = _t10*_t47;
  const double _t138 = 734.05895691609942*_t76;
  const double _t139 = 0.12e2*_t34;
  const double _t140 = 0.12e2*_t63;
  const double _t141 = _t1*_t140;
  const double _t142 = 0.6e1*_t16;
  const double _t143 = 0.6e1*na - 0.6e1*nb;
  const double _t146 = 0.4e1*na - 0.4e1*nb;
  const double _t147 = _t23 - _t24;
  const double _t148 = _t147*_t34 - _t33;
  const double _t150 = _t18*_t84;
  const double _t152 = _t18*_t36;
  const double _t155 = 1101.0884353741492*_t51;
  const double _t157 = xc_powr(_t2, -10, 3);
  const double _t158 = xc_powr(_t2, -11, 3);
  const double _t166 = 93629.968994400435*_t3;
  const double _t168 = 183.51473922902485*_t45;
  const double _t169 = 550.54421768707459*_t51;
  const double _t172 = _t108*_t38;
  const double _t175 = _t1*_t41*_t94;
  const double _t178 = _t31*_t96;
  const double _t190 = 31209.989664800141*_t3;
  const double _t192 = 183.51473922902485*_t51;
  const double _t195 = _t115*_t60;
  const double _t197 = _t25*_t64;
  const double _t198 = _t18*_t96;
  const double _t199 = _t147*_t34 + _t33;
  const double _t123 = _hc0[4]*_t68;
  const double _t124 = 0.0084598826666666647*_t20;
  const double _t125 = _t124*_t25;
  const double _t127 = _t79*_t87*_t88;
  const double _t128 = _t127*_t18;
  const double _t130 = _t36*_t42;
  const double _t131 = _t41*_t75;
  const double _t133 = _t36*_t80;
  const double _t135 = _t134*_t75;
  const double _t136 = _t50*_t72;
  const double _t137 = _t43*_t66;
  const double _t144 = _hc0[3]*_t68;
  const double _t145 = _t144*_t38;
  const double _t149 = 0.0042299413333333324*_t15*_t39;
  const double _t151 = _t126*_t39;
  const double _t153 = _t109*_t25;
  const double _t154 = _t18*_t80*_t96;
  const double _t156 = _hc0[2]*_t138;
  const double _t159 = 5416144256.6986208*_t11*_t158/(_t26 * _t26 * _t26 * _t26);
  const double _t160 = 221937.70428302322*_t34*_t48;
  const double _t161 = _t25*_t90/xc_powr(_t2, 13, 3);
  const double _t162 = 815.6210632401104*_t158*_t25*_t28;
  const double _t163 = 31846928.229387898*_t157*_t89 - _t159 - _t160 - _t161 - _t162 + 145646.61843573398*_t25*_t48*_t63 + 1767.1789703535726*_t95;
  const double _t164 = _t127*_t31;
  const double _t165 = _t1*_t42;
  const double _t167 = _t105*_t43;
  const double _t170 = _hc0[2]*_t31*_t36;
  const double _t171 = _hc0[3]*_t77;
  const double _t173 = _t165*_t25/xc_powr(_t2, 14, 3);
  const double _t174 = _hc0[2]*_t18;
  const double _t176 = _t174*_t175;
  const double _t177 = _hc0[2]*_t101;
  const double _t179 = _t64*_t80;
  const double _t180 = _t110*_t41;
  const double _t181 = _hc0[2]*_t31;
  const double _t182 = _t134*_t181*_t78;
  const double _t183 = -31846928.229387898*_hc0[0]*_t157*_t8*_t88*_t9 - 145646.61843573398*_hc0[0]*_t25*_t47*_t63*_t8*_t9 - 1767.1789703535726*_hc0[0]*_t27*_t8*_t9*_t94 + _t159 + _t160 + _t161 + _t162;
  const double _t184 = -0.025379647999999994*_hc0[1]*_t1*_t34*_t7*_t8*_t9 - 0.012689823999999997*_hc0[2]*_t18*_t31*_t7*_t8*_t9 + _t169*_t180 + 187259.93798880084*_t179 + _t180*_t73 + 93629.96899440042*_t182 + _t183;
  const double _t185 = 0.0084598826666666647*_t39;
  const double _t186 = _t50*_t99;
  const double _t187 = _t42*_t58;
  const double _t188 = _t114*_t41;
  const double _t189 = _t102*_t3;
  const double _t191 = _t114*_t134;
  const double _t193 = _t174*_t58;
  const double _t194 = _hc0[3]*_t111;
  const double _t196 = _t175*_t181;
  const double _t200 = _t116*_t43;
  const double _t201 = 0.012689823999999997*_t39;
  const double _t202 = _t101*_t181;
  const double _t203 = _t31*_t80;
  const double _t204 = _t144*_t60;
  const double _t205 = _t151*_t31;
  const double _t206 = _t156*_t31;
  const double d4F_dna4 = _t123*(_t18 * _t18 * _t18 * _t18) + _t125*_t66 + _t126*_t19*_t70 - 42462570.972517192*_t128 - _t129*_t130 - _t129*_t131 - _t130*_t155 - _t131*_t155 - _t132*_t133 - _t132*_t135 - 2773.1116150163757*_t136 - 734.05895691609942*_t137 - _t138*_t70 + _t145*_t148 + _t145*(-_t142 + _t143*_t34) + _t145*(_t146*_t34 - _t82) + _t149*_t18*_t66 + _t150*_t151 - _t150*_t156 + _t151*_t152 - _t152*_t156 + 1223.4315948601657*_t153*_t18 - 124839.95865920058*_t154 + 83226.63910613372*_t16*_t18*_t80 + _t163 + (_t36 * _t36)*_t56 + _t36*_t56*_t84 + 0.025379647999999994*_t37 + 0.025379647999999994*_t40 + _t67*(-_t121 + _t122) + _t85*(_t139 - _t141);
  const double d4F_dna3_dnb = 0.0063449119999999986*_hc0[1]*_t105*_t25*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[1]*_t15*_t7*_t8*_t9*(_t122 - _t140) + 62419.979329600283*_hc0[1]*_t16*_t18*_t47*_t8*_t9 + 20806.65977653343*_hc0[1]*_t16*_t31*_t47*_t8*_t9 + 917.57369614512436*_hc0[1]*_t18*_t25*_t27*_t8*_t9*_t94 + 305.85789871504142*_hc0[1]*_t25*_t27*_t31*_t8*_t9*_t94 + 0.0021149706666666662*_hc0[1]*_t25*_t66*_t7*_t8*_t9 + 0.012689823999999997*_hc0[1]*_t36*_t7*_t8*_t9 + 0.025379647999999994*_hc0[2]*_t1*_t18*_t25*_t34*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[2]*_t1*_t3*_t36*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[2]*_t1*_t3*_t7*_t8*_t84*_t9 + 0.0021149706666666662*_hc0[2]*_t105*_t15*_t18*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t15*_t18*_t7*_t8*_t9*(-_t141 + 0.4e1*_t34) + 0.0021149706666666662*_hc0[2]*_t15*_t31*_t66*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t18*_t25*_t36*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t18*_t25*_t7*_t8*_t84*_t9 + 0.0063449119999999986*_hc0[2]*_t25*_t31*_t36*_t7*_t8*_t9 + 0.012689823999999997*_hc0[2]*_t38*_t7*_t8*_t9 + 0.012689823999999997*_hc0[3]*_t1*_t3*_t38*_t7*_t8*_t9 + 0.0063449119999999986*_hc0[3]*_t108*_t25*_t38*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t15*_t18*_t31*_t36*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t15*_t18*_t31*_t7*_t8*_t84*_t9 + 0.0021149706666666662*_hc0[3]*_t25*_t69*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[4]*_t108*_t15*_t69*_t7*_t8*_t9 - _t101*_t70 - _t102*_t178 - 31846928.229387894*_t128 - _t130*_t168 - _t130*_t169 - _t131*_t168 - _t131*_t169 - _t133*_t166 - _t135*_t166 - 2079.8337112622817*_t136 - 183.51473922902485*_t137 - _t150*_t177 - _t152*_t177 - 93629.968994400435*_t154 - 367.02947845804965*_t158*_t165 - 10615642.743129298*_t164 - 550.54421768707459*_t167 - _t170*_t77 - _t171*_t172 - 1101.0884353741492*_t173 - 2202.1768707482984*_t176 - _t184 - _t92*_t99;
  const double d4F_dna2_dnb2 = 1712.8042328042318*_hc0[1]*_t1*_t158*_t27*_t8*_t9 + 0.084598826666666654*_hc0[1]*_t1*_t34*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[1]*_t105*_t25*_t7*_t8*_t9 + 41613.31955306686*_hc0[1]*_t16*_t18*_t47*_t8*_t9 + 41613.31955306686*_hc0[1]*_t16*_t31*_t47*_t8*_t9 + 611.71579743008283*_hc0[1]*_t18*_t25*_t27*_t8*_t9*_t94 + 611.71579743008283*_hc0[1]*_t25*_t27*_t31*_t8*_t9*_t94 + 734.05895691609942*_hc0[1]*_t27*_t8*_t9*_t94 + 0.0042299413333333324*_hc0[1]*_t36*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[1]*_t58*_t7*_t8*_t9 + 0.016919765333333329*_hc0[2]*(_t1 * _t1)*_t63*_t7*_t8*_t9 + 0.0084598826666666647*_hc0[2]*_t1*_t18*_t25*_t34*_t7*_t8*_t9 + 0.016919765333333329*_hc0[2]*_t1*_t25*_t31*_t34*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[2]*_t105*_t15*_t31*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t15*_t36*_t58*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[2]*_t18*_t25*_t58*_t7*_t8*_t9 + 0.016919765333333329*_hc0[2]*_t18*_t31*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[2]*_t25*_t31*_t36*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[2]*_t38*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[2]*_t60*_t7*_t8*_t9 + 0.016919765333333329*_hc0[3]*_t1*_t18*_t3*_t31*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[3]*_t108*_t25*_t38*_t7*_t8*_t9 + 0.0042299413333333324*_hc0[3]*_t115*_t25*_t60*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t148*_t15*_t60*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t15*_t199*_t38*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[4]*_t15*_t38*_t60*_t7*_t8*_t9 - _t104*_t178 - _t104*_t198 - _t111*_t170 - _t111*_t193 - _t124*_t96 - 21231285.486258596*_t128 - _t130*_t192 - _t130*_t46 - _t131*_t192 - _t131*_t46 - _t135*_t190 - 1386.5558075081876*_t136 - 21231285.486258596*_t164 - 367.02947845804971*_t167 - _t17*_t18*_t185 - _t172*_t194 - 1468.1179138321988*_t173 - 1468.1179138321988*_t176 - 249679.91731840113*_t179 - 244.68631897203312*_t180*_t45 - 734.05895691609942*_t180*_t51 - 124839.95865920057*_t182 - _t183 - _t185*_t78 - 1386.5558075081876*_t186 - _t187*_t192 - _t187*_t46 - _t188*_t192 - _t188*_t46 - _t189*_t36 - _t189*_t58 - _t190*_t191 - _t194*_t195 - 1468.1179138321988*_t196 - 0.025379647999999994*_t197*_t20;
  const double d4F_dna_dnb3 = 2202.1768707482979*_hc0[1]*_t1*_t158*_t27*_t8*_t9 + 0.0021149706666666662*_hc0[1]*_t116*_t25*_t7*_t8*_t9 + 20806.65977653343*_hc0[1]*_t16*_t18*_t47*_t8*_t9 + 62419.97932960029*_hc0[1]*_t16*_t31*_t47*_t8*_t9 + 0.0084598826666666647*_hc0[1]*_t16*_t7*_t8*_t9 + 305.85789871504142*_hc0[1]*_t18*_t25*_t27*_t8*_t9*_t94 + 917.57369614512425*_hc0[1]*_t25*_t27*_t31*_t8*_t9*_t94 + 1101.0884353741492*_hc0[1]*_t27*_t8*_t9*_t94 + 0.012689823999999997*_hc0[1]*_t58*_t7*_t8*_t9 + 0.012689823999999997*_hc0[2]*_t1*_t25*_t31*_t34*_t7*_t8*_t9 + 0.012689823999999997*_hc0[2]*_t1*_t3*_t58*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t116*_t15*_t18*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t120*_t25*_t31*_t7*_t8*_t9 + 0.0063449119999999986*_hc0[2]*_t18*_t25*_t58*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[2]*_t25*_t31*_t58*_t7*_t8*_t9 + 0.012689823999999997*_hc0[2]*_t60*_t7*_t8*_t9 + 0.012689823999999997*_hc0[3]*_t1*_t3*_t60*_t7*_t8*_t9 + 0.0063449119999999986*_hc0[3]*_t115*_t25*_t60*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t117*_t25*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t120*_t15*_t18*_t31*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[3]*_t15*_t18*_t31*_t58*_t7*_t8*_t9 + 0.0021149706666666662*_hc0[4]*_t115*_t117*_t15*_t7*_t8*_t9 - _t101*_t118 - _t102*_t198 - _t103*_t201 - _t120*_t202 - 10615642.743129298*_t128 - 31846928.229387894*_t164 - _t169*_t187 - _t169*_t188 - _t17*_t201*_t31 - _t171*_t195 - 734.05895691609942*_t173 - _t178*_t81 - _t184 - 2079.8337112622817*_t186 - _t187*_t73 - _t188*_t73 - 93629.96899440042*_t191*_t3 - _t193*_t77 - 2202.1768707482984*_t196 - 0.012689823999999997*_t197*_t20 - 183.51473922902485*_t200 - _t202*_t58 - _t3*_t58*_t81 - _t54*_t96 - _t72*_t92;
  const double d4F_dnb4 = _t116*_t125 + _t116*_t149*_t31 + _t118*_t126*_t19 - _t118*_t138 + _t119*(-_t139 - _t141) + _t120*_t205 - _t120*_t206 + _t120*_t56*_t58 + _t123*(_t31 * _t31 * _t31 * _t31) - _t129*_t187 - _t129*_t188 - _t132*_t191 - _t132*_t58*_t80 + 1223.4315948601657*_t153*_t31 - _t155*_t187 - _t155*_t188 + 83226.63910613372*_t16*_t203 + _t163 - 42462570.972517192*_t164 - 2773.1116150163757*_t186 + _t199*_t204 - 734.05895691609942*_t200 - 124839.95865920058*_t203*_t96 + _t204*(_t142 + _t143*_t34) + _t204*(_t146*_t34 + _t82) + _t205*_t58 - _t206*_t58 + _t56*(_t58 * _t58) + 0.025379647999999994*_t59 + 0.025379647999999994*_t61 + _t67*(_t121 + _t122);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif