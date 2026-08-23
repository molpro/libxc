/*
  Generated from python/lda_exc/lda_c_pw_erf.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_pw_erf
*/

#ifndef _LDA_C_PW_ERF_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_PW_ERF_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_PW_ERF_HELPER_BODIES
#include "lda_c_pw_erf.c"
#undef _LDA_C_PW_ERF_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_PW_ERF_HELPER_BODIES
#include "lda_c_pw_erf.c"
#undef _LDA_C_PW_ERF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_PW_ERF_HELPER_BODIES
#include "lda_c_pw_erf.c"
#undef _LDA_C_PW_ERF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_PW_ERF_HELPER_BODIES
#include "lda_c_pw_erf.c"
#undef _LDA_C_PW_ERF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_PW_ERF_HELPER_BODIES
#include "lda_c_pw_erf.c"
#undef _LDA_C_PW_ERF_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_pw_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_PW_ERF_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_gen_k, _KMAX)(const xc_func_type *p, double z, double n, double *out) {

  const double _t1 = z + 0.1e1;
  const double _t2 = _t1 <= p->zeta_threshold;
  const double _t3 = pow(p->zeta_threshold, n);
  const double _t4 = pow(_t1, n);
#if _KMAX >= 1
  const double _t5 = log(p->zeta_threshold);
  const double _t6 = log(_t1);
  const double _t7 = _t4*_t6;
  const double _t8 = (0.1e1 / _t1);
  const double _t9 = _t4*_t8;
  const double _t10 = _t9*n;
#endif
#if _KMAX >= 2
  const double _t11 = _t4*(_t6 * _t6);
  const double _t12 = _t7*_t8;
  const double _t13 = (0.1e1 / (_t1 * _t1));
  const double _t14 = _t13*_t4;
  const double _t15 = _t14*n;
  const double _t16 = (n * n);
#endif
#if _KMAX >= 3
  const double _t17 = (_t6 * _t6 * _t6);
  const double _t18 = _t11*_t8;
  const double _t19 = _t13*_t7;
  const double _t20 = _t19*n;
  const double _t21 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t22 = _t21*_t4;
  const double _t23 = 0.2e1*_t22;
  const double _t24 = (n * n * n);
  const double _t25 = 0.3e1*_t16;
  const double _t26 = _t22*_t25;
#endif
#if _KMAX >= 4
  const double _t27 = _t11*_t13;
  const double _t28 = 0.6e1*n;
  const double _t29 = _t21*_t7;
  const double _t30 = _t4/(_t1 * _t1 * _t1 * _t1);
#endif

  const double f = my_piecewise3(_t2, _t3, _t4);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = my_piecewise3(_t2, _t3*_t5, _t7);
  out[1] = df_dn;
  const double df_dz = my_piecewise3(_t2, 0, _t10);
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = my_piecewise3(_t2, _t3*(_t5 * _t5), _t11);
  out[3] = d2f_dn2;
  const double d2f_dz_dn = my_piecewise3(_t2, 0, _t12*n + _t9);
  out[4] = d2f_dz_dn;
  const double d2f_dz2 = my_piecewise3(_t2, 0, _t14*_t16 - _t15);
  out[5] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = my_piecewise3(_t2, _t3*(_t5 * _t5 * _t5), _t17*_t4);
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t2, 0, 0.2e1*_t12 + _t18*n);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t2, 0, -_t14 + 0.2e1*_t15 + _t16*_t19 - _t20);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t2, 0, _t22*_t24 + _t23*n - _t26);
  out[9] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dn4 = my_piecewise3(_t2, _t3*(_t5 * _t5 * _t5 * _t5), _t4*(_t6 * _t6 * _t6 * _t6));
  out[10] = d4f_dn4;
  const double d4f_dz_dn3 = my_piecewise3(_t2, 0, _t10*_t17 + 0.3e1*_t18);
  out[11] = d4f_dz_dn3;
  const double d4f_dz2_dn2 = my_piecewise3(_t2, 0, 0.2e1*_t14 + _t16*_t27 - 0.2e1*_t19 + 0.4e1*_t20 - _t27*n);
  out[12] = d4f_dz2_dn2;
  const double d4f_dz3_dn = my_piecewise3(_t2, 0, -_t22*_t28 + _t23 + _t24*_t29 - _t25*_t29 + _t26 + 0.2e1*_t29*n);
  out[13] = d4f_dz3_dn;
  const double d4f_dz4 = my_piecewise3(_t2, 0, 0.11e2*_t16*_t30 - 0.6e1*_t24*_t30 - _t28*_t30 + _t30*(n * n * n * n));
  out[14] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_zeta_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (0.1e1 / (-0.2e1 + 0.2e1*M_CBRT2));
  const double _t2 = z + 0.1e1 <= p->zeta_threshold;
  const double _t3 = xc_powr(p->zeta_threshold, 4, 3) - 0.1e1;
  const double _t4 = p->zeta_threshold - 0.1e1;
  const double _t5 = z > _t4;
  const double _t6 = my_piecewise3(_t5, z, _t4);
  const double _t7 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t6));
  const double _t8 = 0.1e1 - z <= p->zeta_threshold;
  const double _t9 = -z;
  const double _t10 = _t9 > _t4;
  const double _t11 = my_piecewise3(_t10, _t9, _t4);
  const double _t12 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t11));
#if _KMAX >= 1
  const double _t13 = my_piecewise3(_t5, 0.1e1, 0);
  const double _t14 = _t6 + 0.1e1;
  const double _t15 = _t7 + 0.1e1;
  const double _t16 = my_piecewise3(_t10, -0.1e1, 0);
  const double _t17 = _t11 + 0.1e1;
  const double _t18 = _t12 + 0.1e1;
#endif

  const double f = _t1*(my_piecewise3(_t2, _t3, _t7) + my_piecewise3(_t8, _t3, _t12));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*_t13*_t15/_t14) + my_piecewise3(_t8, 0, (0.4e1 / 0.3e1)*_t16*_t18/_t17));
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)*(_t13 * _t13)*_t15/(_t14 * _t14)) + my_piecewise3(_t8, 0, (0.4e1 / 0.9e1)*(_t16 * _t16)*_t18/(_t17 * _t17)));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t1*(my_piecewise3(_t2, 0, -0.8e1 / 0.27e2*(_t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, -0.8e1 / 0.27e2*(_t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17)));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t1*(my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)*(_t13 * _t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, (0.40e2 / 0.81e2)*(_t16 * _t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17 * _t17)));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = 0.0132882934*rs + 0.062182000000000001;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = (rs * rs);
  const double _t6 = 0.1018665524*_t3 + 0.4723158174*_t4 + 0.030651995080000001*_t5 + 0.2230841432*rs;
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = xc_log1p(_t7);
  const double _t9 = _t2*_t8;
  const double _t10 = 0.029729901239999999*_t3 + 0.34979731799999997*_t4 + 0.016775883539999998*_t5 + 0.12236657939999999*rs;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_log1p(_t11);
  const double _t13 = -0.0037573575*rs - 0.033773999999999998;
  const double _t14 = 0.58482233974552045*_t13;
  const double _t15 = _t12*_t14;
  const double _t16 = (zeta * zeta * zeta * zeta);
  const double _t17 = 0.0063883732000000002*rs + 0.03109;
  const double _t18 = -_t17;
  const double _t19 = 0.104655158*_t3 + 0.438956601*_t4 + 0.019436535299999998*_t5 + 0.19268649300000001*rs;
  const double _t20 = (0.1e1 / _t19);
  const double _t21 = xc_log1p(_t20);
  const double _t22 = _t15 + _t18*_t21 - _t9;
  const double _t23 = _t16*_t22;
#if _KMAX >= 1
  const double _t24 = _hc0[0]*_t22;
  const double _t25 = (zeta * zeta * zeta);
  const double _t26 = 0.4e1*_t25;
  const double _t27 = 0.0021973866044103793*_t12;
  const double _t28 = sqrt(rs);
  const double _t29 = (0.1e1 / _t4);
  const double _t30 = -0.15698273699999998*_t28 - 0.2194783005*_t29 - 0.038873070599999997*rs - 0.19268649300000001;
  const double _t31 = (0.1e1 / (_t19 * _t19));
  const double _t32 = _t20 + 0.1e1;
  const double _t33 = (0.1e1 / _t32);
  const double _t34 = -0.04459485186*_t28 - 0.17489865899999998*_t29 - 0.033551767079999996*rs - 0.12236657939999999;
  const double _t35 = (0.1e1 / (_t10 * _t10));
  const double _t36 = _t11 + 0.1e1;
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = _t7 + 0.1e1;
  const double _t39 = (0.1e1 / _t38);
  const double _t40 = _t39/(_t6 * _t6);
  const double _t41 = -0.15279982860000002*_t28 - 0.2361579087*_t29 - 0.061303990160000002*rs - 0.2230841432;
  const double _t42 = _t2*_t41;
  const double _t43 = _t40*_t42 - 0.0132882934*_t8;
  const double _t44 = 0.58482233974552045*_t13*_t34*_t35*_t37 + _t18*_t30*_t31*_t33 - 0.0063883732000000002*_t21 - _t27 - _t43;
  const double _t45 = _t16*_t44;
  const double _t46 = _t35*_t37;
  const double _t47 = _t34*_t46;
  const double _t48 = _t14*_t47;
#endif
#if _KMAX >= 2
  const double _t49 = (zeta * zeta);
  const double _t50 = 0.12e2*_t49;
  const double _t51 = _t22*_t25;
  const double _t52 = 0.8e1*_hc0[1];
  const double _t53 = _hc0[0]*_t44;
  const double _t54 = 0.0265765868*_t40*_t41;
  const double _t55 = 0.0043947732088207587*_t47;
  const double _t56 = (0.1e1 / _t28);
  const double _t57 = xc_powr(rs, -3, 2);
  const double _t58 = -0.07639991430000001*_t56 + 0.11807895435*_t57 - 0.061303990160000002;
  const double _t59 = _t40*_t58;
  const double _t60 = _t2*_t59;
  const double _t61 = -0.02229742593*_t56 + 0.087449329499999992*_t57 - 0.033551767079999996;
  const double _t62 = _t46*_t61;
  const double _t63 = _t14*_t62;
  const double _t64 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t65 = (0.1e1 / (_t38 * _t38));
  const double _t66 = (_t41 * _t41);
  const double _t67 = _t65*_t66;
  const double _t68 = _t64*_t67;
  const double _t69 = (0.1e1 / (_t10 * _t10 * _t10 * _t10));
  const double _t70 = (0.1e1 / (_t36 * _t36));
  const double _t71 = (_t34 * _t34);
  const double _t72 = _t70*_t71;
  const double _t73 = _t69*_t72;
  const double _t74 = _t14*_t73;
  const double _t75 = _t39/(_t6 * _t6 * _t6);
  const double _t76 = -0.30559965720000004*_t28 - 0.4723158174*_t29 - 0.12260798032*rs - 0.4461682864;
  const double _t77 = _t42*_t76;
  const double _t78 = _t75*_t77;
  const double _t79 = _t37/(_t10 * _t10 * _t10);
  const double _t80 = -0.089189703719999999*_t28 - 0.34979731799999997*_t29 - 0.067103534159999992*rs - 0.24473315879999999;
  const double _t81 = _t34*_t80;
  const double _t82 = _t79*_t81;
  const double _t83 = _t14*_t82;
  const double _t84 = _t31*_t33;
  const double _t85 = -0.078491368499999992*_t56 + 0.10973915025*_t57 - 0.038873070599999997;
  const double _t86 = _t84*_t85;
  const double _t87 = 0.0021973866044103793*rs + 0.019751789702565206;
  const double _t88 = (0.1e1 / (_t19 * _t19 * _t19 * _t19));
  const double _t89 = (0.1e1 / (_t32 * _t32));
  const double _t90 = (_t30 * _t30);
  const double _t91 = _t89*_t90;
  const double _t92 = _t88*_t91;
  const double _t93 = _t2*_t64;
  const double _t94 = _t33/(_t19 * _t19 * _t19);
  const double _t95 = -0.31396547399999997*_t28 - 0.438956601*_t29 - 0.077746141199999994*rs - 0.38537298600000003;
  const double _t96 = _t18*_t30;
  const double _t97 = _t95*_t96;
  const double _t98 = _t17*_t92 + _t18*_t86 - 0.0127767464*_t30*_t84 + _t54 - _t55 - _t60 + _t63 + _t67*_t93 + _t73*_t87 - _t78 + _t83 + _t94*_t97;
  const double _t99 = _t16*_t98;
#endif
#if _KMAX >= 3
  const double _t100 = 0.24e2*_t24;
  const double _t101 = _t22*_t49;
  const double _t102 = 0.36e2*_hc0[1];
  const double _t103 = 0.12e2*_hc0[2];
  const double _t104 = _t25*_t44;
  const double _t105 = _hc0[0]*_t98;
  const double _t106 = 0.039864880200000001*_t59;
  const double _t107 = 0.006592159813231138*_t62;
  const double _t108 = (0.1e1 / _t3);
  const double _t109 = xc_powr(rs, -5, 2);
  const double _t110 = 0.038199957150000005*_t108 - 0.17711843152500001*_t109;
  const double _t111 = _t110*_t40;
  const double _t112 = _t111*_t2;
  const double _t113 = 0.039864880200000001*_t68;
  const double _t114 = 0.011148712965*_t108 - 0.13117399424999998*_t109;
  const double _t115 = _t114*_t46;
  const double _t116 = _t115*_t14;
  const double _t117 = 0.006592159813231138*_t73;
  const double _t118 = 0.0265765868*rs + 0.124364;
  const double _t119 = (_t41 * _t41 * _t41);
  const double _t120 = (0.1e1 / (_t38 * _t38 * _t38));
  const double _t121 = xc_powi(_t6, -6);
  const double _t122 = _t120*_t121;
  const double _t123 = _t119*_t122;
  const double _t124 = (_t34 * _t34 * _t34);
  const double _t125 = (0.1e1 / (_t36 * _t36 * _t36));
  const double _t126 = xc_powi(_t10, -6);
  const double _t127 = _t125*_t126;
  const double _t128 = _t124*_t127;
  const double _t129 = 1.1696446794910409*_t13;
  const double _t130 = _t128*_t129;
  const double _t131 = _t41*_t75;
  const double _t132 = 0.039864880200000001*_t131*_t76;
  const double _t133 = 0.006592159813231138*_t82;
  const double _t134 = -0.15279982860000002*_t56 + 0.2361579087*_t57 - 0.12260798032;
  const double _t135 = _t42*_t75;
  const double _t136 = _t134*_t135;
  const double _t137 = _t64*_t65;
  const double _t138 = _t137*_t42;
  const double _t139 = _t134*_t138;
  const double _t140 = _t138*_t58;
  const double _t141 = _t75*_t76;
  const double _t142 = _t141*_t58;
  const double _t143 = 0.2e1*_t2;
  const double _t144 = _t142*_t143;
  const double _t145 = -0.04459485186*_t56 + 0.17489865899999998*_t57 - 0.067103534159999992;
  const double _t146 = _t69*_t70;
  const double _t147 = _t14*_t34;
  const double _t148 = _t146*_t147;
  const double _t149 = _t145*_t148;
  const double _t150 = _t146*_t61;
  const double _t151 = _t147*_t150;
  const double _t152 = _t145*_t79;
  const double _t153 = _t147*_t152;
  const double _t154 = _t79*_t80;
  const double _t155 = _t154*_t61;
  const double _t156 = _t129*_t155;
  const double _t157 = -0.61119931440000008*_t28 - 0.94463163480000001*_t29 - 0.24521596064000001*rs - 0.89233657280000001;
  const double _t158 = xc_powi(_t6, -5);
  const double _t159 = _t158*_t67;
  const double _t160 = _t159*_t2;
  const double _t161 = _t157*_t160;
  const double _t162 = _t160*_t76;
  const double _t163 = -0.17837940744*_t28 - 0.69959463599999994*_t29 - 0.13420706831999998*rs - 0.48946631759999998;
  const double _t164 = xc_powi(_t10, -5);
  const double _t165 = _t164*_t72;
  const double _t166 = _t14*_t165;
  const double _t167 = _t163*_t166;
  const double _t168 = _t166*_t80;
  const double _t169 = -0.45839948580000006*_t28 - 0.70847372610000003*_t29 - 0.18391197048000002*rs - 0.66925242959999998;
  const double _t170 = _t169*_t39;
  const double _t171 = _t170*_t64;
  const double _t172 = _t171*_t77;
  const double _t173 = -0.13378455557999999*_t28 - 0.52469597699999992*_t29 - 0.10065530123999999*rs - 0.36709973819999997;
  const double _t174 = _t173*_t37*_t69;
  const double _t175 = _t174*_t81;
  const double _t176 = _hc0[0]*_t14;
  const double _t177 = 0.039245684249999996*_t108 - 0.16460872537499999*_t109;
  const double _t178 = _t177*_t84;
  const double _t179 = (_t30 * _t30 * _t30);
  const double _t180 = (0.1e1 / (_t32 * _t32 * _t32));
  const double _t181 = xc_powi(_t19, -6);
  const double _t182 = _t180*_t181;
  const double _t183 = _t179*_t182;
  const double _t184 = _t30*_t94;
  const double _t185 = -0.15698273699999998*_t56 + 0.2194783005*_t57 - 0.077746141199999994;
  const double _t186 = _t185*_t96;
  const double _t187 = _t88*_t89;
  const double _t188 = _t187*_t85;
  const double _t189 = _t94*_t95;
  const double _t190 = _t189*_t85;
  const double _t191 = 0.2e1*_t18;
  const double _t192 = -0.62793094799999993*_t28 - 0.877913202*_t29 - 0.15549228239999999*rs - 0.77074597200000006;
  const double _t193 = xc_powi(_t19, -5);
  const double _t194 = _t193*_t91;
  const double _t195 = _t18*_t194;
  const double _t196 = -0.47094821099999995*_t28 - 0.65843490149999995*_t29 - 0.11661921179999998*rs - 0.57805947899999999;
  const double _t197 = _t196*_t33*_t88;
  const double _t198 = _t14*_t175;
  const double _t199 = _t106 - _t107 - _t112 - _t113 + _t116 + _t117 + _t118*_t123 + _t128*(-0.0043947732088207587*rs - 0.039503579405130412) + _t132 - _t133 - _t136 + _t139 + _t140 - _t144 - _t149 - _t151 + _t153 + _t156 + _t161 + _t162 - _t167 - _t168 - _t172 + _t178*_t18 + _t183*(-0.0127767464*rs - 0.062179999999999999) - 0.019165119600000002*_t184*_t95 - _t186*_t187 + _t186*_t94 - _t188*_t96 + _t190*_t191 - _t192*_t195 - _t195*_t95 + _t197*_t97 + _t198 - 0.019165119600000002*_t86 + 0.019165119600000002*_t92;
  const double _t200 = _t16*_t199;
#endif
#if _KMAX >= 4
  const double _t201 = 0.053153173599999999*_t111;
  const double _t202 = 0.0087895464176415174*_t115;
  const double _t203 = pow(rs, -2.5);
  const double _t204 = xc_powr(rs, -7, 2);
  const double _t205 = _t2*_t40*(-0.057299935725000008*_t203 + 0.44279607881250005*_t204);
  const double _t206 = 0.1063063472*_t123;
  const double _t207 = _t14*_t46*(-0.016723069447499999*_t203 + 0.32793498562499995*_t204);
  const double _t208 = 0.017579092835283035*_t128;
  const double _t209 = (_t58 * _t58)*_t65;
  const double _t210 = _t146*(_t61 * _t61);
  const double _t211 = 0.079729760400000002*rs + 0.37309199999999998;
  const double _t212 = (_t41 * _t41 * _t41 * _t41)/((_t38 * _t38 * _t38 * _t38)*xc_powi(_t6, 8));
  const double _t213 = (_t34 * _t34 * _t34 * _t34)/(xc_powi(_t10, 8)*(_t36 * _t36 * _t36 * _t36));
  const double _t214 = 0.053153173599999999*_t134;
  const double _t215 = _t137*_t41;
  const double _t216 = _t214*_t215;
  const double _t217 = 0.053153173599999999*_t215*_t58;
  const double _t218 = _t131*_t214;
  const double _t219 = 0.1063063472*_t142;
  const double _t220 = 0.0087895464176415174*_t34;
  const double _t221 = _t145*_t220;
  const double _t222 = _t146*_t221;
  const double _t223 = _t150*_t220;
  const double _t224 = _t221*_t79;
  const double _t225 = 0.017579092835283035*_t155;
  const double _t226 = _t134*_t58;
  const double _t227 = _t226*_t65*_t93;
  const double _t228 = 0.3e1*_t2;
  const double _t229 = _t226*_t228*_t75;
  const double _t230 = _t14*_t145;
  const double _t231 = _t150*_t230;
  const double _t232 = 1.7544670192365612*_t13;
  const double _t233 = _t232*_t61;
  const double _t234 = _t152*_t233;
  const double _t235 = 0.07639991430000001*_t108 - 0.35423686305000002*_t109;
  const double _t236 = _t135*_t235;
  const double _t237 = 0.032487183262504181*_t28 + 0.050210169272576204*_t29 + 0.013034006525388686*rs + 0.047430520763667439;
  const double _t238 = 0.01624359163125209*_t28 + 0.025105084636288102*_t29 + 0.0065170032626943432*rs + 0.023715260381833719;
  const double _t239 = 0.2e1*_t110*_t138;
  const double _t240 = _t138*_t235;
  const double _t241 = _t110*_t141*_t228;
  const double _t242 = _t114*_t129*_t146*_t34;
  const double _t243 = 0.02229742593*_t108 - 0.26234798849999996*_t109;
  const double _t244 = _t148*_t243;
  const double _t245 = _t114*_t154*_t232;
  const double _t246 = _t147*_t243*_t79;
  const double _t247 = 0.0087895464176415174*_t165;
  const double _t248 = _hc0[0]*_t163;
  const double _t249 = _hc0[0]*_t80;
  const double _t250 = -0.22919974290000003*_t56 + 0.35423686305000002*_t57 - 0.18391197048000002;
  const double _t251 = _t122*_t143*_t66;
  const double _t252 = _t250*_t251;
  const double _t253 = _t134*_t251;
  const double _t254 = _t251*_t58;
  const double _t255 = _t160*(-0.30559965720000004*_t56 + 0.4723158174*_t57 - 0.24521596064000001);
  const double _t256 = 0.2e1*_t134;
  const double _t257 = _t160*_t256;
  const double _t258 = -0.066892277789999996*_t56 + 0.26234798849999996*_t57 - 0.10065530123999999;
  const double _t259 = _t127*_t129*_t71;
  const double _t260 = _t258*_t259;
  const double _t261 = _t145*_t259;
  const double _t262 = _t259*_t61;
  const double _t263 = _t166*(-0.089189703719999999*_t56 + 0.34979731799999997*_t57 - 0.13420706831999998);
  const double _t264 = _t129*_t145;
  const double _t265 = _t165*_t264;
  const double _t266 = _t119*_t120*_t143/xc_powi(_t6, 7);
  const double _t267 = _t266*(-0.91679897160000012*_t28 - 1.4169474522000001*_t29 - 0.36782394096000004*rs - 1.3385048592);
  const double _t268 = _t157*_t266;
  const double _t269 = _t266*_t76;
  const double _t270 = _t124*_t125*_t129/xc_powi(_t10, 7);
  const double _t271 = _t270*(-0.26756911115999998*_t28 - 1.0493919539999998*_t29 - 0.20131060247999999*rs - 0.73419947639999994);
  const double _t272 = _t163*_t270;
  const double _t273 = _t270*_t80;
  const double _t274 = 0.053153173599999999*_t171*_t41*_t76;
  const double _t275 = 0.0087895464176415174*_t175;
  const double _t276 = _t250*_t39*_t64*_t77;
  const double _t277 = _t158*_t65;
  const double _t278 = _t157*_t42;
  const double _t279 = _t256*_t277*_t278;
  const double _t280 = _t134*_t277*_t77;
  const double _t281 = _t277*_t58;
  const double _t282 = _t278*_t281;
  const double _t283 = 0.2e1*_t281*_t77;
  const double _t284 = _t171*_t256*_t42;
  const double _t285 = 0.3e1*_t170*_t58*_t76*_t93;
  const double _t286 = _t264*_t34;
  const double _t287 = _t164*_t70;
  const double _t288 = _t286*_t287;
  const double _t289 = _t230*_t287*_t81;
  const double _t290 = _t287*_t61;
  const double _t291 = _t147*_t290;
  const double _t292 = _t129*_t290*_t81;
  const double _t293 = _t258*_t69;
  const double _t294 = _t37*_t81;
  const double _t295 = _t176*_t294;
  const double _t296 = _t174*_t286;
  const double _t297 = _t174*_t233;
  const double _t298 = _t121*_t2*_t67*(-0.76399914300000016*_t28 - 1.1807895435*_t29 - 0.3065199508*rs - 1.115420716);
  const double _t299 = _t157*_t298;
  const double _t300 = _t298*_t76;
  const double _t301 = _t121*_t169*_t2*_t67*_t76;
  const double _t302 = _t126*_t72*(-0.22297425930000001*_t28 - 0.87449329499999995*_t29 - 0.16775883539999997*rs - 0.61183289699999999);
  const double _t303 = _t176*_t302;
  const double _t304 = _t126*_t173*_t72*_t80;
  const double _t305 = _t157*_t158*_t170*_t77;
  const double _t306 = _t163*_t164*_t173;
  const double _t307 = 0.025553492800000001*_t30;
  const double _t308 = _t18*_t185;
  const double _t309 = _t96*(0.078491368499999992*_t108 - 0.32921745074999997*_t109);
  const double _t310 = 0.3e1*_t18;
  const double _t311 = -0.23547410549999997*_t56 + 0.32921745074999997*_t57 - 0.11661921179999998;
  const double _t312 = _t182*_t90;
  const double _t313 = _t191*_t312;
  const double _t314 = _t179*_t180*_t191/xc_powi(_t19, 7);
  const double _t315 = _t197*_t95;
  const double _t316 = _t33*_t97;
  const double _t317 = _t14*_t294;
  const double _t318 = _t193*_t89;
  const double _t319 = 0.2e1*_t186;
  const double _t320 = _t318*_t85;
  const double _t321 = _t14*_t302;
  const double _t322 = -0.78491368499999992*_t28 - 1.0973915025000001*_t29 - 0.19436535299999999*rs - 0.96343246500000013;
  const double _t323 = _t18*_t181*_t91;
  const double _t324 = _t323*_t95;
#endif

  const double f = -_hc0[0]*_t15 + _hc0[0]*_t23 + _t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = -_hc0[1]*_t15 + _hc0[1]*_t23 + _t24*_t26;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t27 + _hc0[0]*_t45 - _hc0[0]*_t48 + _t43;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = -_hc0[2]*_t15 + _hc0[2]*_t23 + _t24*_t50 + _t51*_t52;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t27 + _hc0[1]*_t45 - _hc0[1]*_t48 + _t26*_t53;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[0]*_t55 - _hc0[0]*_t63 + _hc0[0]*_t74 - _hc0[0]*_t83 + _hc0[0]*_t99 + _t1*_t68 - _t54 + _t60 + _t78;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = -_hc0[3]*_t15 + _hc0[3]*_t23 + _t100*zeta + _t101*_t102 + _t103*_t51;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc0[2]*_t27 + _hc0[2]*_t45 - _hc0[2]*_t48 + _t104*_t52 + _t50*_t53;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc0[1]*_t55 - _hc0[1]*_t63 + _hc0[1]*_t74 - _hc0[1]*_t83 + _hc0[1]*_t99 + _t105*_t26;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = _hc0[0]*_t107 - _hc0[0]*_t116 - _hc0[0]*_t117 - _hc0[0]*_t130 + _hc0[0]*_t133 + _hc0[0]*_t149 + _hc0[0]*_t151 - _hc0[0]*_t153 - _hc0[0]*_t156 + _hc0[0]*_t167 + _hc0[0]*_t168 + _hc0[0]*_t200 - _t106 + _t112 + _t113 - _t118*_t123 - _t132 + _t136 - _t139 - _t140 + _t144 - _t161 - _t162 + _t172 - _t175*_t176;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = 0.96e2*_hc0[1]*_t22*zeta + 0.72e2*_hc0[2]*_t101 + 0.16e2*_hc0[3]*_t51 - _hc0[4]*_t15 + _hc0[4]*_t23 + _t100;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = _hc0[3]*_t27 + _hc0[3]*_t45 - _hc0[3]*_t48 + _t102*_t44*_t49 + _t103*_t104 + 0.24e2*_t53*zeta;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = _hc0[2]*_t55 - _hc0[2]*_t63 + _hc0[2]*_t74 - _hc0[2]*_t83 + _hc0[2]*_t99 + _t105*_t50 + _t25*_t52*_t98;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = _hc0[0]*_t199*_t26 + _hc0[1]*_t107 - _hc0[1]*_t116 - _hc0[1]*_t117 - _hc0[1]*_t130 + _hc0[1]*_t133 + _hc0[1]*_t149 + _hc0[1]*_t151 - _hc0[1]*_t153 - _hc0[1]*_t156 + _hc0[1]*_t167 + _hc0[1]*_t168 - _hc0[1]*_t198 + _hc0[1]*_t200;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = 3.5089340384731225*_hc0[0]*_t13*_t213 + _hc0[0]*_t16*(-_t14*_t304 + _t159*_t237 + _t159*_t238 - _t163*_t288 - _t163*_t291 - _t163*_t321 + _t165*(-0.0015678740816452686*_t28 - 0.0061491195266550206*_t29 - 0.0011796192565742263*rs - 0.0043021869184172654) + _t165*(-0.00078393704082263429*_t28 - 0.0030745597633275103*_t29 - 0.00058980962828711315*rs - 0.0021510934592086327) + _t17*_t187*(_t85 * _t85) - 0.2e1*_t177*_t187*_t96 + _t177*_t189*_t310 - 0.025553492800000001*_t178 + _t18*_t84*(-0.058868526374999994*_t203 + 0.41152181343749994*_t204) - 0.051106985600000002*_t183 - 0.025553492800000001*_t184*_t185 + _t185*_t187*_t307 - 0.2e1*_t185*_t195 - _t185*_t318*_t97 - _t187*_t309 + _t188*_t307 - _t188*_t308 - 0.051106985600000002*_t190 + _t192*_t193*_t196*_t316 + _t192*_t314 - _t192*_t318*_t319 - _t192*_t320*_t96 - _t192*_t322*_t323 + _t194*(-0.016045828958615175*_t28 - 0.022433748686331946*_t29 - 0.0039733709187639663*rs - 0.019695251646131003) + _t194*(-0.0080229144793075875*_t28 - 0.011216874343165973*_t29 - 0.0019866854593819832*rs - 0.0098476258230655016) - _t195*(-0.31396547399999997*_t56 + 0.438956601*_t57 - 0.15549228239999999) - _t196*_t324 + _t197*_t319 + _t201 - _t202 - _t205 + _t206 + _t207 - _t208 + _t209*_t93 + _t210*_t87 - _t211*_t212 + _t213*(0.013184319626462274*rs + 0.11851073821539124) - _t216 - _t217 + _t218 + _t219 + _t222 + _t223 - _t224 - _t225 + _t227 - _t229 - _t231 + _t234 - _t236 + _t239 + _t240 - _t241 - _t242 - _t244 + _t245 + _t246 - _t252 - _t253 - _t254 + _t255 + _t257 + _t260 + _t261 + _t262 - _t263 - _t265 - _t267 - _t268 - _t269 + _t271 + _t272 + _t273 + _t274 - _t275 - _t276 + _t279 + _t280 + _t282 + _t283 - _t284 - _t285 - _t289 - _t292 + _t293*_t317 + _t296 + _t297*_t80 + _t299 + _t300 + _t301 - _t305 + _t306*_t317 - _t307*_t315 + 0.2e1*_t308*_t312 + 0.3e1*_t308*_t85*_t94 + _t309*_t94 + _t310*_t315*_t85 + _t311*_t313 + _t311*_t316*_t88 + _t313*_t85 + _t314*_t95 + _t314*(-0.9418964219999999*_t28 - 1.3168698029999999*_t29 - 0.23323842359999997*rs - 1.156118958) - 0.2e1*_t320*_t97 - _t321*_t80 - _t322*_t324 + (_t30 * _t30 * _t30 * _t30)*(0.038330239200000005*rs + 0.18653999999999998)/(xc_powi(_t19, 8)*(_t32 * _t32 * _t32 * _t32))) + _hc0[0]*_t202 - _hc0[0]*_t207 + _hc0[0]*_t208 - _hc0[0]*_t222 - _hc0[0]*_t223 + _hc0[0]*_t224 + _hc0[0]*_t225 + _hc0[0]*_t231 - _hc0[0]*_t234 + _hc0[0]*_t242 + _hc0[0]*_t244 - _hc0[0]*_t245 - _hc0[0]*_t246 - _hc0[0]*_t260 - _hc0[0]*_t261 - _hc0[0]*_t262 + _hc0[0]*_t263 + _hc0[0]*_t265 - _hc0[0]*_t271 - _hc0[0]*_t272 - _hc0[0]*_t273 + _hc0[0]*_t275 + _hc0[0]*_t289 + _hc0[0]*_t292 - _hc0[0]*_t296 + _t1*_t209*_t64 - _t159*_t237 - _t159*_t238 + _t163*_t303 + _t176*_t210 + _t176*_t304 - _t201 + _t205 - _t206 + _t211*_t212 + _t216 + _t217 - _t218 - _t219 - _t227 + _t229 + _t236 - _t239 - _t240 + _t241 - _t247*_t248 - _t247*_t249 + _t248*_t288 + _t248*_t291 - _t249*_t297 + _t252 + _t253 + _t254 - _t255 - _t257 + _t267 + _t268 + _t269 - _t274 + _t276 - _t279 - _t280 - _t282 - _t283 + _t284 + _t285 - _t293*_t295 - _t295*_t306 - _t299 - _t300 - _t301 + _t303*_t80 + _t305;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {


  const double f = 0.78494900000000001*rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.78494900000000001;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_Q_num_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);
  const double _t2 = xc_powr(0.2e1, 2, 3)*M_CBRT3*(M_CBRTPI * M_CBRTPI)/(-0.4e1 + 0.4e1*M_LN2);
  const double _t3 = 3.4485100000000002 - _t2;

  const double f = _t1*_t3 + 3.91744*(x * x * x) + 5.84605*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 11.752320000000001*_t1 + 0.2e1*_t3*x + 5.84605;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.2e1*_t2 + 23.504640000000002*x + 6.8970200000000004;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 23.504640000000002;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_Q_den_k, _KMAX)(const xc_func_type *p, double x, double *out) {


  const double f = 3.4485100000000002*(x * x) + 5.84605*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 6.8970200000000004*x + 5.84605;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 6.8970200000000004;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_Q_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_Q_den_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_Q_num_k, _KMAX)(p, x, _hc1);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = -_hc0[0] + _hc1[0];
  const double _t3 = _t1*_t2;
  const double _t4 = (-0.2e1 + 0.2e1*M_LN2)/(M_PI * M_PI);
#if _KMAX >= 1
  const double _t5 = -_hc0[1] + _hc1[1];
  const double _t6 = _t1*_t5;
  const double _t7 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t8 = _t2*_t7;
  const double _t9 = -_hc0[1]*_t8 + _t6;
  const double _t10 = _t3 + 0.1e1;
  const double _t11 = _t4/_t10;
#endif
#if _KMAX >= 2
  const double _t12 = -_t9;
  const double _t13 = _t4/(_t10 * _t10);
  const double _t14 = _t13*_t9;
  const double _t15 = -_hc0[2] + _hc1[2];
  const double _t16 = _t1*_t15;
  const double _t17 = _hc0[1]*_t7;
  const double _t18 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t19 = ((_hc0[1]) * (_hc0[1]));
  const double _t20 = _t18*_t19;
  const double _t21 = _t2*_t20;
  const double _t22 = -_hc0[2]*_t8 + _t16 - 0.2e1*_t17*_t5 + 0.2e1*_t21;
#endif
#if _KMAX >= 3
  const double _t23 = 0.2e1*_hc0[1]*_t2*_t7 - 0.2e1*_t6;
  const double _t24 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t25 = _t12*_t24*_t4*_t9;
  const double _t26 = _hc0[2]*_t7;
  const double _t27 = 0.6e1*_t2;
  const double _t28 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t29 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t28;
  const double _t30 = _hc0[1]*_hc0[2]*_t18*_t27 + _hc1[3]*_t1 - 0.3e1*_t15*_t17 + 0.6e1*_t20*_t5 - 0.3e1*_t26*_t5 - _t27*_t29;
  const double _t31 = -_t22;
  const double _t32 = _t12*_t13;
#endif
#if _KMAX >= 4
  const double _t33 = 0.3e1*_t22;
  const double _t34 = _t23*_t24*_t4;
#endif

  const double f = _t4*xc_log1p(_t3);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t11*_t9;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _t11*_t22 + _t12*_t14;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _t11*_t30 + _t14*_t31 + 0.2e1*_t22*_t32 + _t23*_t25;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t11*(0.24e2*_hc0[1]*_hc0[2]*_t18*_t5 + 0.6e1*((_hc0[2]) * (_hc0[2]))*_t18*_t2 - 0.36e2*_hc0[2]*_t19*_t2*_t28 - 0.4e1*_hc1[3]*_t17 + 0.12e2*_t15*_t18*_t19 - 0.6e1*_t15*_t26 - 0.24e2*_t29*_t5 + 0.24e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t2/xc_powi((_hc0[0]), 5)) + _t12*_t33*_t34 + _t13*_t31*_t33 - _t14*_t30 + _t25*(0.4e1*_hc0[1]*_t5*_t7 + 0.2e1*_hc0[2]*_t2*_t7 - 0.2e1*_t16 - 0.4e1*_t21) + 0.3e1*_t30*_t32 + 0.2e1*_t31*_t34*_t9 + _t12*_t23*_t4*_t9*(0.3e1*_hc0[1]*_t2*_t7 - 0.3e1*_t6)/(_t10 * _t10 * _t10 * _t10);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_phin_k, _KMAX)(const xc_func_type *p, double n, double z, double *out) {

  const double _t1 = (0.1e1 / 0.3e1)*n;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_gen_k, _KMAX)(p, z, _t1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_gen_k, _KMAX)(p, -z, _t1, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  out[1] = df_dz;
  const double df_dn = (0.1e1 / 0.6e1)*_hc0[1] + (0.1e1 / 0.6e1)*_hc1[1];
  out[2] = df_dn;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5];
  out[3] = d2f_dz2;
  const double d2f_dn_dz = (0.1e1 / 0.6e1)*_hc0[4] - 0.1e1 / 0.6e1*_hc1[4];
  out[4] = d2f_dn_dz;
  const double d2f_dn2 = (0.1e1 / 0.18e2)*_hc0[3] + (0.1e1 / 0.18e2)*_hc1[3];
  out[5] = d2f_dn2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = (0.1e1 / 0.2e1)*_hc0[9] - 0.1e1 / 0.2e1*_hc1[9];
  out[6] = d3f_dz3;
  const double d3f_dn_dz2 = (0.1e1 / 0.6e1)*_hc0[8] + (0.1e1 / 0.6e1)*_hc1[8];
  out[7] = d3f_dn_dz2;
  const double d3f_dn2_dz = (0.1e1 / 0.18e2)*_hc0[7] - 0.1e1 / 0.18e2*_hc1[7];
  out[8] = d3f_dn2_dz;
  const double d3f_dn3 = (0.1e1 / 0.54e2)*_hc0[6] + (0.1e1 / 0.54e2)*_hc1[6];
  out[9] = d3f_dn3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.1e1 / 0.2e1)*_hc0[14] + (0.1e1 / 0.2e1)*_hc1[14];
  out[10] = d4f_dz4;
  const double d4f_dn_dz3 = (0.1e1 / 0.6e1)*_hc0[13] - 0.1e1 / 0.6e1*_hc1[13];
  out[11] = d4f_dn_dz3;
  const double d4f_dn2_dz2 = (0.1e1 / 0.18e2)*_hc0[12] + (0.1e1 / 0.18e2)*_hc1[12];
  out[12] = d4f_dn2_dz2;
  const double d4f_dn3_dz = (0.1e1 / 0.54e2)*_hc0[11] - 0.1e1 / 0.54e2*_hc1[11];
  out[13] = d4f_dn3_dz;
  const double d4f_dn4 = (0.1e1 / 0.162e3)*_hc0[10] + (0.1e1 / 0.162e3)*_hc1[10];
  out[14] = d4f_dn4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = 0.040000000000000001*_t1 + 0.43190000000000001*rs + 0.1e1;
  const double _t4 = xc_powr(0.6e1, 1, 3);
  const double _t5 = (M_CBRTPI * M_CBRTPI);
  const double _t6 = _t4*_t5;
  const double _t7 = _t6/_t3;
  const double _t8 = _t2*_t7;
  const double _t9 = 0.1e1 - 0.022669999999999999*rs;
  const double _t10 = (0.3e1 / 0.5e1)*_t9;
#if _KMAX >= 1
  const double _t11 = (0.1e1 / (rs * rs * rs));
  const double _t12 = _t11*_t7;
  const double _t13 = -0.080000000000000002*rs - 0.43190000000000001;
  const double _t14 = (0.1e1 / (_t3 * _t3));
#endif
#if _KMAX >= 2
  const double _t15 = _t14*_t6;
  const double _t16 = _t15*_t2;
  const double _t17 = (0.1e1 / (rs * rs * rs * rs));
  const double _t18 = _t17*_t7;
  const double _t19 = (0.18e2 / 0.5e1)*_t9;
  const double _t20 = _t11*_t15;
  const double _t21 = _t6/(_t3 * _t3 * _t3);
  const double _t22 = _t2*_t21;
  const double _t23 = -0.16*rs - 0.86380000000000001;
  const double _t24 = _t13*_t23;
  const double _t25 = _t22*_t24;
#endif
#if _KMAX >= 3
  const double _t26 = xc_powi(rs, -5);
  const double _t27 = _t26*_t7;
  const double _t28 = _t22*_t9;
  const double _t29 = 0.096000000000000002*_t28;
  const double _t30 = _t11*_t21;
  const double _t31 = _t24*_t30;
  const double _t32 = -0.23999999999999999*rs - 1.2957000000000001;
  const double _t33 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
#endif
#if _KMAX >= 4
  const double _t34 = _t15*_t17;
  const double _t35 = 0.0087052799999999993*_t22;
  const double _t36 = 0.76800000000000002*_t30;
  const double _t37 = _t23*_t9;
  const double _t38 = _t13*_t9;
  const double _t39 = _t2*_t33*_t6;
  const double _t40 = _t32*_t39;
  const double _t41 = _t24*_t9;
  const double _t42 = _t32*_t6;
#endif

  const double f = _t10*_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.6e1 / 0.5e1*_t12*_t9 + (0.3e1 / 0.5e1)*_t13*_t14*_t2*_t4*_t5*_t9 - 0.013602*_t8;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t10*_t25 + 0.054407999999999998*_t12 - 0.027203999999999999*_t13*_t16 - 0.12e2 / 0.5e1*_t13*_t20*_t9 - 0.048000000000000001*_t16*_t9 + _t18*_t19;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.16322399999999998*_t11*_t13*_t14*_t4*_t5 + 0.28800000000000003*_t11*_t14*_t4*_t5*_t9 + (0.54e2 / 0.5e1)*_t13*_t14*_t17*_t4*_t5*_t9 + (0.3e1 / 0.5e1)*_t13*_t2*_t23*_t32*_t33*_t4*_t5*_t9 - _t13*_t29 + 0.0032644799999999997*_t14*_t2*_t4*_t5 - 0.244836*_t18 - _t19*_t31 - _t23*_t29 - 0.040805999999999995*_t25 - 0.72e2 / 0.5e1*_t27*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t10*_t2*_t24*_t42*(-0.32000000000000001*rs - 1.7276)/xc_powi(_t3, 5) - 0.24e2 / 0.5e1*_t11*_t33*_t41*_t42 - 0.97934399999999999*_t13*_t34 + _t13*_t35 - 0.288e3 / 0.5e1*_t15*_t26*_t38 + (0.108e3 / 0.5e1)*_t17*_t21*_t41 - 0.026115840000000001*_t20 + _t23*_t35 - 0.054407999999999998*_t24*_t40 + 1.3057920000000001*_t27 + 0.023040000000000001*_t28 + 0.32644799999999996*_t31 - 1.7280000000000002*_t34*_t9 + _t36*_t37 + _t36*_t38 - 0.14400000000000002*_t37*_t40 - 0.192*_t38*_t40 - 0.14399999999999999*_t39*_t41 + 0.72e2*_t7*_t9/xc_powi(rs, 6);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_g0_poly_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (rs * rs * rs);

  const double f = 0.081930000000000003*_t1 - 0.01277*_t2 + 0.001859*(rs * rs * rs * rs) + 0.0207*rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.038309999999999997*_t1 + 0.0074359999999999999*_t2 + 0.16386000000000001*rs + 0.0207;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.022308000000000001*_t1 - 0.076619999999999994*rs + 0.16386000000000001;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.044616000000000003*rs - 0.076619999999999994;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.044616000000000003;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_g0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0_poly_k, _KMAX)(p, rs, _hc0);
  const double _t1 = exp(-0.75239999999999996*rs);
  const double _t2 = _t1*((0.1e1 / 0.2e1)*_hc0[0] + 0.1e1 / 0.2e1);
#if _KMAX >= 1
  const double _t3 = (0.1e1 / 0.2e1)*_t1;
#endif
#if _KMAX >= 2
  const double _t4 = _hc0[1]*_t1;
#endif
#if _KMAX >= 3
  const double _t5 = _hc0[2]*_t1;
#endif

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[1]*_t3 - 0.75239999999999996*_t2;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[2]*_t3 + 0.5661057599999999*_t2 - 0.75239999999999996*_t4;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[3]*_t3 - 0.42593797382399989*_t2 + 0.84915863999999985*_t4 - 1.1286*_t5;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -1.5047999999999999*_hc0[3]*_t1 + _hc0[4]*_t3 + 0.3204757315051775*_t2 - 0.85187594764799979*_t4 + 1.6983172799999999*_t5;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_g0c_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0_poly_k, _KMAX)(p, rs, _hc0);
  const double _t1 = xc_expm1(-0.75239999999999996*rs);
  const double _t2 = (0.1e1 / 0.2e1)*_hc0[0] + 0.1e1 / 0.2e1;
#if _KMAX >= 1
  const double _t3 = (0.1e1 / 0.2e1)*_hc0[1];
  const double _t4 = -0.75239999999999996*_t1 - 0.75239999999999996;
#endif
#if _KMAX >= 2
  const double _t5 = (0.1e1 / 0.2e1)*_hc0[2];
  const double _t6 = 0.5661057599999999*_t1 + 0.5661057599999999;
#endif
#if _KMAX >= 3
  const double _t7 = (0.1e1 / 0.2e1)*_hc0[3];
  const double _t8 = -0.42593797382399989*_t1 - 0.42593797382399989;
#endif
#if _KMAX >= 4
  const double _t9 = (0.1e1 / 0.2e1)*_hc0[4];
#endif

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + _t1*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t1*_t3 + _t2*_t4 + _t3;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[1]*_t4 + _t1*_t5 + _t2*_t6 + _t5;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.3e1 / 0.2e1)*_hc0[1]*_t6 + (0.3e1 / 0.2e1)*_hc0[2]*_t4 + _t1*_t7 + _t2*_t8 + _t7;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.2e1*_hc0[1]*_t8 + 0.3e1*_hc0[2]*_t6 + 0.2e1*_hc0[3]*_t4 + _t1*_t9 + _t2*(0.3204757315051775*_t1 + 0.3204757315051775) + _t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_D2_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = 0.67600000000000005*_t1 - 0.38800000000000001*rs;
  const double _t3 = (0.1e1 / _t1);
  const double _t4 = exp(-0.54700000000000004*rs);
  const double _t5 = _t3*_t4;
  const double _t6 = _t2*_t5;
#if _KMAX >= 1
  const double _t7 = 1.3520000000000001*rs - 0.38800000000000001;
  const double _t8 = (0.1e1 / (rs * rs * rs));
  const double _t9 = _t4*_t8;
  const double _t10 = _t2*_t9;
#endif
#if _KMAX >= 2
  const double _t11 = _t5*_t7;
  const double _t12 = _t7*_t9;
  const double _t13 = (0.1e1 / (rs * rs * rs * rs));
  const double _t14 = _t13*_t4;
  const double _t15 = _t14*_t2;
#endif
#if _KMAX >= 3
  const double _t16 = _t4/xc_powi(rs, 5);
  const double _t17 = _t16*_t2;
#endif

  const double f = _t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.2e1*_t10 + _t3*_t4*_t7 - 0.54700000000000004*_t6;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 2.1880000000000002*_t10 - 1.0940000000000001*_t11 - 0.4e1*_t12 + 0.6e1*_t15 + 1.3520000000000001*_t5 + 0.29920900000000006*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -1.7952540000000003*_t10 + 0.18e2*_t13*_t4*_t7 - 9.8460000000000001*_t15 - 0.24e2*_t17 + 0.89762700000000017*_t3*_t4*_t7 + 6.5640000000000001*_t4*_t7*_t8 - 2.2186320000000004*_t5 - 0.16366732300000003*_t6 - 8.1120000000000001*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 1.3093385840000002*_t10 - 0.65466929200000012*_t11 - 7.1810160000000014*_t12 - 39.384*_t14*_t7 + 48.671999999999997*_t14 + 10.771524000000003*_t15 - 0.96e2*_t16*_t7 + 52.512*_t17 + 0.120e3*_t2*_t4/xc_powi(rs, 6) + 2.4271834080000008*_t5 + 0.089526025681000029*_t6 + 17.749056000000003*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_D3_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs) - 4.9500000000000002*rs;
  const double _t2 = (0.1e1 / (rs * rs * rs));
  const double _t3 = exp(-0.31*rs);
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
#if _KMAX >= 1
  const double _t6 = 0.2e1*rs - 4.9500000000000002;
  const double _t7 = (0.1e1 / (rs * rs * rs * rs));
  const double _t8 = _t3*_t7;
  const double _t9 = _t1*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = _t4*_t6;
  const double _t11 = _t6*_t8;
  const double _t12 = xc_powi(rs, -5);
  const double _t13 = _t12*_t3;
  const double _t14 = _t1*_t13;
#endif
#if _KMAX >= 3
  const double _t15 = _t3/xc_powi(rs, 6);
  const double _t16 = _t1*_t15;
#endif

  const double f = _t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2*_t3*_t6 - 0.31*_t5 - 0.3e1*_t9;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.62*_t10 - 0.6e1*_t11 + 0.12e2*_t14 + 0.2e1*_t4 + 0.096100000000000005*_t5 + 1.8599999999999999*_t9;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.36e2*_t12*_t3*_t6 - 11.16*_t14 - 0.60e2*_t16 + 0.2883*_t2*_t3*_t6 + 5.5800000000000001*_t3*_t6*_t7 - 1.8599999999999999*_t4 - 0.029791000000000002*_t5 - 0.18e2*_t8 - 0.8649*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.360e3*_t1*_t3/xc_powi(rs, 7) - 0.11916399999999999*_t10 - 3.4596*_t11 - 44.640000000000001*_t13*_t6 + 0.144e3*_t13 + 6.9192*_t14 - 0.240e3*_t15*_t6 + 74.400000000000006*_t16 + 1.1532*_t4 + 0.0092352100000000006*_t5 + 22.32*_t8 + 0.35749200000000003*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a5_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc1);
  const double _t1 = xc_powi((_hc0[0]), 8);
#if _KMAX >= 1
  const double _t2 = xc_powi((_hc0[0]), 7)*_hc0[1];
  const double _t3 = 0.8e1*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = 0.16e2*_t2;
  const double _t5 = xc_powi((_hc0[0]), 6)*((_hc0[1]) * (_hc0[1]));
  const double _t6 = 0.56e2*_t5;
#endif
#if _KMAX >= 3
  const double _t7 = 0.24e2*_t2;
  const double _t8 = xc_powi((_hc0[0]), 5)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t9 = 0.336e3*_t8;
  const double _t10 = 0.168e3*_t5;
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc1[1]*_t1;
  out[1] = df_dz;
  const double df_drs = _hc1[0]*_t3 + _hc1[2]*_t1;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc1[3]*_t1;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc1[1]*_t3 + _hc1[4]*_t1;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[0]*_t6 + _hc1[2]*_t4 + _hc1[5]*_t1;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc1[6]*_t1;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc1[3]*_t3 + _hc1[7]*_t1;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc1[1]*_t6 + _hc1[4]*_t4 + _hc1[8]*_t1;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[0]*_t9 + _hc1[2]*_t10 + _hc1[5]*_t7 + _hc1[9]*_t1;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc1[10]*_t1;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc1[11]*_t1 + _hc1[6]*_t3;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc1[12]*_t1 + _hc1[3]*_t6 + _hc1[7]*_t4;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc1[1]*_t9 + _hc1[13]*_t1 + _hc1[4]*_t10 + _hc1[8]*_t7;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.1680e4*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0] + _hc1[14]*_t1 + 0.1344e4*_hc1[2]*_t8 + 0.336e3*_hc1[5]*_t5 + 0.32e2*_hc1[9]*_t2;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 0.0132882934*rs + 0.062182000000000001;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = 0.1018665524*_t3 + 0.4723158174*_t4 + 0.030651995080000001*(rs * rs) + 0.2230841432*rs;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = xc_log1p(_t6);
#if _KMAX >= 1
  const double _t8 = sqrt(rs);
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = -0.15279982860000002*_t8 - 0.2361579087*_t9 - 0.061303990160000002*rs - 0.2230841432;
  const double _t11 = (0.1e1 / (_t5 * _t5));
  const double _t12 = _t6 + 0.1e1;
  const double _t13 = (0.1e1 / _t12);
#endif
#if _KMAX >= 2
  const double _t14 = _t11*_t13;
  const double _t15 = (0.1e1 / _t8);
  const double _t16 = xc_powr(rs, -3, 2);
  const double _t17 = -0.07639991430000001*_t15 + 0.11807895435*_t16 - 0.061303990160000002;
  const double _t18 = _t14*_t17;
  const double _t19 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t20 = (0.1e1 / (_t12 * _t12));
  const double _t21 = (_t10 * _t10);
  const double _t22 = _t20*_t21;
  const double _t23 = _t19*_t22;
  const double _t24 = _t13/(_t5 * _t5 * _t5);
  const double _t25 = -0.30559965720000004*_t8 - 0.4723158174*_t9 - 0.12260798032*rs - 0.4461682864;
  const double _t26 = _t10*_t2;
  const double _t27 = _t25*_t26;
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / _t3);
  const double _t29 = xc_powr(rs, -5, 2);
  const double _t30 = 0.038199957150000005*_t28 - 0.17711843152500001*_t29;
  const double _t31 = _t14*_t30;
  const double _t32 = (_t10 * _t10 * _t10);
  const double _t33 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t34 = xc_powi(_t5, -6);
  const double _t35 = _t33*_t34;
  const double _t36 = _t32*_t35;
  const double _t37 = _t10*_t24;
  const double _t38 = -0.15279982860000002*_t15 + 0.2361579087*_t16 - 0.12260798032;
  const double _t39 = _t26*_t38;
  const double _t40 = _t19*_t20;
  const double _t41 = _t17*_t40;
  const double _t42 = _t24*_t25;
  const double _t43 = _t17*_t42;
  const double _t44 = 0.2e1*_t2;
  const double _t45 = -0.61119931440000008*_t8 - 0.94463163480000001*_t9 - 0.24521596064000001*rs - 0.89233657280000001;
  const double _t46 = xc_powi(_t5, -5);
  const double _t47 = _t22*_t46;
  const double _t48 = _t2*_t47;
  const double _t49 = -0.45839948580000006*_t8 - 0.70847372610000003*_t9 - 0.18391197048000002*rs - 0.66925242959999998;
  const double _t50 = _t13*_t19*_t49;
#endif
#if _KMAX >= 4
  const double _t51 = 0.053153173599999999*_t10;
  const double _t52 = _t2*_t38;
  const double _t53 = _t26*(0.07639991430000001*_t28 - 0.35423686305000002*_t29);
  const double _t54 = 0.3e1*_t2;
  const double _t55 = -0.22919974290000003*_t15 + 0.35423686305000002*_t16 - 0.18391197048000002;
  const double _t56 = _t21*_t35;
  const double _t57 = _t44*_t56;
  const double _t58 = _t32*_t33*_t44/xc_powi(_t5, 7);
  const double _t59 = _t25*_t50;
  const double _t60 = _t13*_t27;
  const double _t61 = _t20*_t46;
  const double _t62 = 0.2e1*_t39;
  const double _t63 = _t17*_t61;
  const double _t64 = _t2*_t22*_t34*(-0.76399914300000016*_t8 - 1.1807895435*_t9 - 0.3065199508*rs - 1.115420716);
#endif

  const double f = _t2*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t11*_t13*_t2 - 0.0132882934*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1*_t23 - 0.0265765868*_t10*_t14 + _t18*_t2 + _t24*_t27;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.039864880200000001*_t18 + _t2*_t31 + 0.039864880200000001*_t23 + _t24*_t39 - 0.039864880200000001*_t25*_t37 - _t25*_t48 - _t26*_t41 + _t27*_t50 + _t36*(-0.0265765868*rs - 0.124364) - _t39*_t40 + _t43*_t44 - _t45*_t48;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t1*(_t17 * _t17)*_t40 + (_t10 * _t10 * _t10 * _t10)*(0.079729760400000002*rs + 0.37309199999999998)/((_t12 * _t12 * _t12 * _t12)*xc_powi(_t5, 8)) + _t14*_t2*(-0.057299935725000008*pow(rs, -2.5) + 0.44279607881250005/xc_powr(rs, 7, 2)) + 0.3e1*_t17*_t24*_t52 + _t17*_t54*_t59 + _t17*_t57 + _t19*_t55*_t60 - _t2*_t22*_t25*_t34*_t49 + _t24*_t53 + _t25*_t58 - _t25*_t64 - 0.2e1*_t26*_t30*_t40 - _t26*_t45*_t63 - _t27*_t38*_t61 - 0.2e1*_t27*_t63 + _t30*_t42*_t54 - 0.053153173599999999*_t31 - 0.1063063472*_t36 - 0.053153173599999999*_t37*_t38 + _t38*_t40*_t51 - 0.2e1*_t38*_t48 - _t40*_t53 + _t41*_t51 - _t41*_t52 - 0.1063063472*_t43 + _t45*_t46*_t49*_t60 + _t45*_t58 - _t45*_t61*_t62 - _t45*_t64 + _t47*(-0.032487183262504181*_t8 - 0.050210169272576204*_t9 - 0.013034006525388686*rs - 0.047430520763667439) + _t47*(-0.01624359163125209*_t8 - 0.025105084636288102*_t9 - 0.0065170032626943432*rs - 0.023715260381833719) - _t48*(-0.30559965720000004*_t15 + 0.4723158174*_t16 - 0.24521596064000001) + _t50*_t62 - _t51*_t59 + 0.2e1*_t52*_t56 + _t55*_t57 + _t58*(-0.91679897160000012*_t8 - 1.4169474522000001*_t9 - 0.36782394096000004*rs - 1.3385048592);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_c_pw_erf_a5_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = xc_powi((_hc0[0]), 8);
#if _KMAX >= 1
  const double _t2 = xc_powi((_hc0[0]), 7)*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi((_hc0[0]), 6)*((_hc0[1]) * (_hc0[1]));
#endif
#if _KMAX >= 3
  const double _t4 = xc_powi((_hc0[0]), 5)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.8e1*_hc1[0]*_t2 + _hc1[1]*_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.56e2*_hc1[0]*_t3 + 0.16e2*_hc1[1]*_t2 + _hc1[2]*_t1;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.336e3*_hc1[0]*_t4 + 0.168e3*_hc1[1]*_t3 + 0.24e2*_hc1[2]*_t2 + _hc1[3]*_t1;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.1680e4*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0] + 0.1344e4*_hc1[1]*_t4 + 0.336e3*_hc1[2]*_t3 + 0.32e2*_hc1[3]*_t2 + _hc1[4]*_t1;
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = M_CBRTPI;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = xc_powr(na, -1, 3);
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = _t4*_t6;
  const double _t8 = xc_powr(0.12e2, 1, 3);
  const double _t9 = _t3*_t8;
  const double _t10 = xc_powr(M_PI, 1, 6);
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_powr(0.2e1, 2, 3)*xc_powr(0.3e1, 1, 6)*_t11*p->cam_omega;
  const double _t14 = ((p->cam_omega) * (p->cam_omega));
  const double _t17 = xc_powi((p->cam_omega), 8);
  const double _t19 = xc_powr(0.2e1, 1, 2);
  const double _t20 = xc_powr(M_PI, 1, 2);
  const double _t21 = _t19*_t20;
  const double _t23 = xc_powi((p->cam_omega), 5);
  const double _t26 = xc_powi((p->cam_omega), 6);
  const double _t30 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t36 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t39 = xc_powr(0.3e1, 2, 3);
  const double _t40 = (M_PI * M_CBRTPI);
  const double _t41 = _t39*_t40;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, _t7, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0_k, _KMAX)(p, _t7, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t6*_t9, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_D3_k, _KMAX)(p, _t7, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, _t7, _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0c_k, _KMAX)(p, _t7, _hc5);
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_D2_k, _KMAX)(p, _t7, _hc6);
  double _hc7[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_a5_z0_k, _KMAX)(p, _t7, _hc7);
  double _hc8[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_Q_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t12/xc_powr(na, 1, 6), _hc8);
  const double _t13 = ((_hc0[0]) * (_hc0[0]));
  const double _t15 = _t13*_t14 + 0.1e1;
  const double _t16 = (0.1e1 / (_t15 * _t15 * _t15 * _t15));
  const double _t18 = xc_powi((_hc0[0]), 8);
  const double _t22 = _t18*_t21;
  const double _t24 = _hc1[0]*_t23;
  const double _t25 = (0.2e1 / 0.3e1)*_t22*_t24;
  const double _t27 = xc_powi((_hc0[0]), 6);
  const double _t28 = M_PI*_hc5[0];
  const double _t29 = (0.1e1 / 0.2e1)*_t18*_t28;
  const double _t31 = (0.8e1 / 0.3e1)*_hc1[0]*_t21*_t27;
  const double _t32 = (0.1e1 / 0.2e1)*_hc2[0];
  const double _t33 = _hc3[0] + _t32;
  const double _t34 = (0.3e1 / 0.20e2)*_t22;
  const double _t35 = _t33*_t34;
  const double _t37 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t38 = 0.2e1*_t27*_t28;
  const double _t42 = _hc6[0] + _t32 - 0.1e1 / 0.5e1*_t41*xc_powr(na, 2, 3);
  const double _t43 = M_PI*_t18;
  const double _t44 = (0.3e1 / 0.16e2)*_t43;
  const double _t45 = _t42*_t44;
  const double _t46 = _hc7[0]*_t17 + _hc8[0] - _t25*na + _t26*(0.4e1*_hc4[0]*_t27 - _t29*na) + _t30*(-_t31*na - _t35*na) + _t36*(0.6e1*_hc4[0]*_t37 - _t38*na - _t45*na);
  const double _t47 = _hc4[0] - _t16*_t46;
  const double zk = _t47;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t48 = xc_powr(na, -4, 3);
  const double _t49 = _t4*_t48;
  const double _t50 = (0.1e1 / 0.6e1)*_t49;
  const double _t59 = xc_powr(0.2e1, 5, 6);
  const double _t60 = M_CBRT3;
  const double _t61 = _t59*_t60;
  const double _t62 = _t10*_t61;
  const double _t71 = (M_CBRTPI * M_CBRTPI);
  double _hc9[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, 0, _hc9);
  const double _t51 = (0.4e1 / 0.3e1)*_hc9[1];
  const double _t52 = xc_powi(_t15, -5);
  const double _t53 = _t14*_t52;
  const double _t54 = _hc0[0]*_t53;
  const double _t55 = _t49*_t54;
  const double _t56 = _t46*_t55;
  const double _t57 = _hc7[1]*_t17;
  const double _t58 = _hc8[1]*_t12;
  const double _t63 = _hc1[1]*_t62;
  const double _t64 = _t18*_t23;
  const double _t65 = _t63*_t64;
  const double _t66 = xc_powi((_hc0[0]), 7);
  const double _t67 = _hc9[1]*_t66;
  const double _t68 = _t62*_t67;
  const double _t69 = _t5*_t68;
  const double _t70 = _hc4[1]*_t49;
  const double _t72 = 0.4e1*_hc4[0];
  const double _t73 = _t49*_t72;
  const double _t74 = xc_powi((_hc0[0]), 5);
  const double _t75 = _hc9[1]*_t74;
  const double _t76 = _hc2[1]*_t9;
  const double _t77 = (0.1e1 / 0.12e2)*_t48*_t76;
  const double _t78 = -_hc3[1]*_t50 - _t77;
  const double _t79 = _t34*na;
  const double _t80 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t81 = _hc9[1]*_t80;
  const double _t82 = -_hc6[1]*_t50 - 0.2e1 / 0.15e2*_t41*_t5 - _t77;
  const double _t83 = _t44*na;
  const double _t84 = (0.8e1 / 0.9e1)*_t24*_t69 - _t25 + _t26*((0.2e1 / 0.3e1)*_hc5[0]*_hc9[1]*_t1*_t5*_t66*_t71 + (0.1e1 / 0.12e2)*_hc5[1]*_t1*_t18*_t5*_t71 - 0.2e1 / 0.3e1*_t27*_t70 - _t29 - _t73*_t75) + _t30*((0.8e1 / 0.3e1)*_hc1[0]*_hc9[1]*_t10*_t5*_t59*_t60*_t74 + (0.4e1 / 0.9e1)*_hc1[1]*_t10*_t27*_t5*_t59*_t60 + (0.1e1 / 0.5e1)*_hc9[1]*_t10*_t33*_t5*_t59*_t60*_t66 - _t31 - _t35 - _t78*_t79) + _t36*(0.2e1*_hc5[0]*_hc9[1]*_t1*_t5*_t71*_t74 + (0.1e1 / 0.3e1)*_hc5[1]*_t1*_t27*_t5*_t71 + (0.1e1 / 0.4e1)*_hc9[1]*_t1*_t42*_t5*_t66*_t71 - _t37*_t70 - _t38 - _t45 - _t73*_t81 - _t82*_t83) + (0.1e1 / 0.9e1)*_t5*_t65 - _t50*_t57 - 0.1e1 / 0.12e2*_t58/xc_powr(na, 7, 6);
  const double _t85 = _t16*_t84;
  const double dF_dna = _t47 + na*(-_hc4[1]*_t50 - _t51*_t56 - _t85);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t87 = xc_powr(na, -7, 3);
  const double _t88 = (0.2e1 / 0.9e1)*_t87;
  const double _t89 = _t4*_t88;
  const double _t90 = xc_powr(0.6e1, 2, 3);
  const double _t91 = (0.1e1 / _t71);
  const double _t92 = xc_powr(na, -8, 3);
  const double _t93 = _t91*_t92;
  const double _t94 = (0.1e1 / 0.36e2)*_t93;
  const double _t95 = _t90*_t94;
  const double _t96 = _t4*_t87;
  const double _t99 = _t90*_t93;
  const double _t112 = xc_powr(na, -5, 3);
  const double _t113 = xc_powr(0.2e1, 1, 6);
  const double _t114 = _t11*_t113*_t39;
  const double _t118 = _t112*_t114;
  const double _t131 = _t1*_t71;
  const double _t135 = _t2*_t90;
  const double _t138 = (0.16e2 / 0.3e1)*_t96;
  const double _t143 = (0.4e1 / 0.3e1)*_t99;
  const double _t145 = _t112*_t135;
  const double _t86 = (0.8e1 / 0.3e1)*_hc9[1];
  const double _t97 = _hc9[1]*_t54;
  const double _t98 = _t46*_t97;
  const double _t100 = _t46*_t99;
  const double _t101 = ((_hc9[1]) * (_hc9[1]));
  const double _t102 = _t101*_t53;
  const double _t103 = _t100*_t102;
  const double _t104 = _t101*_t13;
  const double _t105 = xc_powi(_t15, -6);
  const double _t106 = _t105*_t36;
  const double _t107 = _t104*_t106;
  const double _t108 = _t100*_t107;
  const double _t109 = _t55*_t84;
  const double _t110 = _hc8[2]*_t14;
  const double _t111 = _hc7[2]*_t17;
  const double _t115 = _hc1[2]*_t114;
  const double _t116 = _t115*_t64;
  const double _t117 = (0.1e1 / 0.27e2)*_t116;
  const double _t119 = _hc1[1]*_t118;
  const double _t120 = _t23*_t67;
  const double _t121 = (0.16e2 / 0.27e2)*_t120;
  const double _t122 = _t48*_t68;
  const double _t123 = _t112*_t27;
  const double _t124 = _t101*_t114;
  const double _t125 = _t123*_t124;
  const double _t126 = (0.56e2 / 0.27e2)*_t24;
  const double _t127 = _hc4[1]*_t4;
  const double _t128 = _t127*_t87;
  const double _t129 = (0.8e1 / 0.9e1)*_t27;
  const double _t130 = (0.1e1 / 0.18e2)*_t18;
  const double _t132 = _hc5[1]*_t131;
  const double _t133 = _t132*_t48;
  const double _t134 = _hc4[2]*_t99;
  const double _t136 = _hc5[2]*_t135;
  const double _t137 = _t112*_t136;
  const double _t139 = _hc4[0]*_t75;
  const double _t140 = _hc9[1]*_t131;
  const double _t141 = _t140*_t66;
  const double _t142 = _t141*_t48;
  const double _t144 = _hc4[1]*_t75;
  const double _t146 = _hc5[1]*_t145;
  const double _t147 = _hc4[0]*_t101*_t37;
  const double _t148 = _t101*_t135;
  const double _t149 = _t123*_t148;
  const double _t150 = (0.4e1 / 0.27e2)*_t115;
  const double _t151 = (0.16e2 / 0.9e1)*_t75;
  const double _t152 = _t101*_t37;
  const double _t153 = (0.40e2 / 0.9e1)*_hc1[0];
  const double _t154 = _t152*_t153;
  const double _t155 = (0.7e1 / 0.15e2)*_t33;
  const double _t156 = _hc3[1]*_t4;
  const double _t157 = xc_powr(0.18e2, 1, 3)*_hc2[2];
  const double _t158 = _t157*_t94 + (0.1e1 / 0.9e1)*_t76*_t87;
  const double _t159 = _hc3[2]*_t95 + _t156*_t88 + _t158;
  const double _t160 = (0.4e1 / 0.3e1)*_t37;
  const double _t161 = (0.2e1 / 0.9e1)*_t27;
  const double _t162 = (0.1e1 / 0.6e1)*_t37;
  const double _t163 = _hc4[0]*_t80;
  const double _t164 = _hc9[1]*_t163;
  const double _t165 = _hc5[0]*_t140*_t74;
  const double _t166 = _hc4[1]*_t81;
  const double _t167 = _hc4[0]*_t104;
  const double _t168 = (0.5e1 / 0.3e1)*_t152;
  const double _t169 = _t141*_t82;
  const double _t170 = _hc6[1]*_t89 + _hc6[2]*_t95 + _t158 + (0.2e1 / 0.45e2)*_t41*_t48;
  const double _t171 = (0.1e1 / 0.72e2)*_t110*_t96 + _t111*_t95 - _t112*_t117 - _t119*_t121 + (0.16e2 / 0.27e2)*_t122*_t24 - _t125*_t126 + _t26*((0.4e1 / 0.9e1)*_hc5[0]*_t142 - 0.7e1 / 0.9e1*_hc5[0]*_t149 + _t128*_t129 + _t130*_t133 + (0.1e1 / 0.9e1)*_t134*_t27 - 0.1e1 / 0.72e2*_t137*_t18 + _t138*_t139 + _t143*_t144 - 0.2e1 / 0.9e1*_t146*_t67 + (0.10e2 / 0.3e1)*_t147*_t99) + _t30*((0.16e2 / 0.9e1)*_hc1[0]*_hc9[1]*_t10*_t48*_t59*_t60*_t74 + (0.8e1 / 0.27e2)*_hc1[1]*_t10*_t27*_t48*_t59*_t60 + (0.2e1 / 0.15e2)*_hc9[1]*_t10*_t33*_t48*_t59*_t60*_t66 + (0.2e1 / 0.5e1)*_hc9[1]*_t10*_t5*_t59*_t60*_t66*_t78 - _t118*_t154 - _t119*_t151 - _t123*_t150 - _t125*_t155 - _t159*_t79 - 0.3e1 / 0.10e2*_t22*_t78) + _t36*(-_hc5[0]*_t145*_t168 + _t128*_t160 + _t133*_t161 + _t134*_t162 - 0.1e1 / 0.18e2*_t137*_t27 + _t138*_t164 + (0.1e1 / 0.6e1)*_t142*_t42 + _t143*_t166 - 0.2e1 / 0.3e1*_t146*_t75 - 0.7e1 / 0.24e2*_t149*_t42 + (0.4e1 / 0.3e1)*_t165*_t48 + 0.2e1*_t167*_t99 + _t169*_t6 - _t170*_t83 - 0.3e1 / 0.8e1*_t43*_t82) + (0.2e1 / 0.27e2)*_t48*_t65 + _t57*_t89 + (0.7e1 / 0.72e2)*_t58/xc_powr(na, 13, 6);
  const double _t172 = _t16*_t171;
  const double d2F_dna2 = -_t56*_t86 - 0.1e1 / 0.3e1*_t70 - 0.2e1*_t85 + na*(_hc4[1]*_t89 + _hc4[2]*_t95 + (0.2e1 / 0.9e1)*_t103 - 0.20e2 / 0.9e1*_t108 - _t109*_t86 - _t172 + (0.16e2 / 0.9e1)*_t96*_t98);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t173 = (0.1e1 / M_PI);
  const double _t174 = (0.1e1 / (na * na * na * na));
  const double _t175 = (0.1e1 / 0.36e2)*_t174;
  const double _t176 = _t173*_t175;
  const double _t177 = xc_powr(na, -10, 3);
  const double _t178 = (0.14e2 / 0.27e2)*_t177;
  const double _t179 = _t178*_t4;
  const double _t180 = xc_powr(na, -11, 3);
  const double _t181 = (0.1e1 / 0.9e1)*_t180;
  const double _t182 = _t90*_t91;
  const double _t183 = _t181*_t182;
  const double _t185 = (0.112e3 / 0.27e2)*_t177;
  const double _t187 = _t180*_t182;
  const double _t191 = (0.80e2 / 0.3e1)*_t174;
  const double _t192 = _t173*_t191;
  const double _t198 = (0.1e1 / _t20);
  const double _t201 = (0.1e1 / (na * na * na));
  const double _t202 = _t19*_t198;
  const double _t203 = _t201*_t202;
  const double _t205 = _t203*_t23;
  const double _t210 = _t114*_t92;
  const double _t227 = _t173*_t174;
  const double _t230 = (0.112e3 / 0.9e1)*_t177;
  const double _t233 = (0.16e2 / 0.3e1)*_t187;
  const double _t184 = ((_hc9[1]) * (_hc9[1]) * (_hc9[1]));
  const double _t186 = _t4*_t98;
  const double _t188 = _t102*_t187;
  const double _t189 = _t188*_t46;
  const double _t190 = _t184*_t80;
  const double _t193 = _t26/xc_powi(_t15, 7);
  const double _t194 = _t193*_t46;
  const double _t195 = _t107*_t84*_t99;
  const double _t196 = _hc9[1]*_t171*_t55;
  const double _t197 = _hc7[3]*_t17;
  const double _t199 = xc_powr(0.3e1, 1, 2)*_hc8[3]*_t198*_t30;
  const double _t200 = _t110*_t4;
  const double _t204 = _hc1[3]*_t64;
  const double _t206 = _hc1[2]*_t67;
  const double _t207 = _t201*_t74;
  const double _t208 = _t184*_t207;
  const double _t209 = _hc1[1]*_t101*_t27;
  const double _t211 = _hc1[1]*_t210;
  const double _t212 = _t68*_t87;
  const double _t213 = _t27*_t92;
  const double _t214 = _t124*_t213;
  const double _t215 = _hc4[3]*_t173;
  const double _t216 = _t174*_t215;
  const double _t217 = (0.1e1 / 0.9e1)*_t216;
  const double _t218 = _t174*_t74;
  const double _t219 = _hc4[2]*_hc9[1];
  const double _t220 = 0.2e1*_t219;
  const double _t221 = _t127*_t177;
  const double _t222 = (0.56e2 / 0.27e2)*_t221;
  const double _t223 = _t132*_t18;
  const double _t224 = _hc4[2]*_t182;
  const double _t225 = _t180*_t224;
  const double _t226 = (0.4e1 / 0.9e1)*_t225;
  const double _t228 = _t184*_t227;
  const double _t229 = _hc4[1]*_t227;
  const double _t231 = _t139*_t4;
  const double _t232 = _hc5[0]*_t141;
  const double _t234 = _hc1[3]*_t27;
  const double _t235 = _hc1[2]*_t202;
  const double _t236 = _hc1[0]*_t190;
  const double _t237 = _hc1[1]*_t152*_t202;
  const double _t238 = _t202*_t33;
  const double _t239 = _hc2[3]*_t173;
  const double _t240 = _t157*_t91;
  const double _t241 = _t175*_t239 + (0.7e1 / 0.27e2)*_t177*_t76 + _t181*_t240;
  const double _t242 = -_hc3[2]*_t183 - _hc3[3]*_t176 - _t156*_t178 - _t241;
  const double _t243 = _t132*_t27;
  const double _t244 = _t164*_t4;
  const double _t245 = _t141*_t42;
  const double _t246 = -_hc6[1]*_t179 - _hc6[2]*_t183 - _hc6[3]*_t176 - _t241 - 0.8e1 / 0.135e3*_t41*_t87;
  const double _t247 = -_t111*_t183 + _t117*_t92 + _t121*_t211 + _t126*_t214 - _t176*_t197 - 0.7e1 / 0.144e3*_t177*_t200 - _t179*_t57 - 0.1e1 / 0.432e3*_t199/xc_powr(na, 7, 2) + (0.56e2 / 0.9e1)*_t202*_t208*_t24 + (0.1e1 / 0.54e2)*_t203*_t204 + (0.4e1 / 0.9e1)*_t205*_t206 + (0.28e2 / 0.9e1)*_t205*_t209 - 0.64e2 / 0.81e2*_t212*_t24 + _t26*((0.7e1 / 0.9e1)*_hc5[0]*_t101*_t2*_t27*_t90*_t92 + (0.14e2 / 0.3e1)*_hc5[0]*_t184*_t201*_t74 + (0.2e1 / 0.9e1)*_hc5[1]*_hc9[1]*_t2*_t66*_t90*_t92 + (0.7e1 / 0.3e1)*_hc5[1]*_t101*_t201*_t27 + (0.1e1 / 0.3e1)*_hc5[2]*_hc9[1]*_t201*_t66 + (0.1e1 / 0.72e2)*_hc5[2]*_t18*_t2*_t90*_t92 + (0.1e1 / 0.72e2)*_hc5[3]*_t18*_t201 - _t144*_t233 - 0.40e2 / 0.3e1*_t147*_t187 - 0.10e2*_t152*_t229 - 0.40e2 / 0.3e1*_t163*_t228 - _t173*_t218*_t220 - _t217*_t27 - _t222*_t27 - 0.2e1 / 0.27e2*_t223*_t87 - _t226*_t27 - _t230*_t231 - 0.16e2 / 0.27e2*_t232*_t87) + _t30*(-0.64e2 / 0.27e2*_hc1[0]*_t62*_t75*_t87 + (0.2e1 / 0.5e1)*_t122*_t78 - 0.7e1 / 0.5e1*_t125*_t78 + _t150*_t213 + _t151*_t211 + _t154*_t210 + _t155*_t214 - 0.9e1 / 0.20e2*_t159*_t22 + (0.3e1 / 0.5e1)*_t159*_t69 + (0.20e2 / 0.3e1)*_t201*_t237 + (0.2e1 / 0.27e2)*_t203*_t234 + (0.80e2 / 0.9e1)*_t203*_t236 + _t207*_t235*_t51 + (0.7e1 / 0.5e1)*_t208*_t238 - _t242*_t79 - 0.32e2 / 0.81e2*_t27*_t63*_t87 - 0.8e1 / 0.45e2*_t33*_t68*_t87) + _t36*(-_hc0[0]*_t228*_t72 + (0.5e1 / 0.3e1)*_hc5[0]*_t101*_t2*_t37*_t90*_t92 + (0.20e2 / 0.3e1)*_hc5[0]*_t184*_t201*_t80 + (0.2e1 / 0.3e1)*_hc5[1]*_hc9[1]*_t2*_t74*_t90*_t92 + 0.5e1*_hc5[1]*_t101*_t201*_t37 + _hc5[2]*_hc9[1]*_t201*_t74 + (0.1e1 / 0.18e2)*_hc5[2]*_t2*_t27*_t90*_t92 + (0.1e1 / 0.18e2)*_hc5[3]*_t201*_t27 + (0.3e1 / 0.4e1)*_hc9[1]*_t1*_t170*_t5*_t66*_t71 + (0.1e1 / 0.2e1)*_hc9[1]*_t1*_t48*_t66*_t71*_t82 + (0.7e1 / 0.24e2)*_t101*_t2*_t27*_t42*_t90*_t92 - 0.6e1*_t104*_t229 - 0.7e1 / 0.8e1*_t149*_t82 - _t162*_t216 - 0.16e2 / 0.9e1*_t165*_t87 - _t166*_t233 - 0.8e1*_t167*_t187 - 0.9e1 / 0.16e2*_t170*_t43 + (0.7e1 / 0.4e1)*_t184*_t201*_t42*_t74 - _t220*_t227*_t80 - 0.28e2 / 0.9e1*_t221*_t37 - 0.2e1 / 0.3e1*_t225*_t37 - _t230*_t244 - 0.8e1 / 0.27e2*_t243*_t87 - _t245*_t88 - _t246*_t83) - 0.91e2 / 0.432e3*_t58/xc_powr(na, 19, 6) - 0.8e1 / 0.81e2*_t65*_t87;
  const double _t248 = _t16*_t247;
  const double d3F_dna3 = -0.8e1*_hc9[1]*_t109 + (0.2e1 / 0.3e1)*_t103 - 0.20e2 / 0.3e1*_t108 + (0.2e1 / 0.3e1)*_t128 + (0.1e1 / 0.12e2)*_t134 + _t138*_t98 - 0.3e1*_t172 + na*((0.16e2 / 0.3e1)*_hc0[0]*_hc9[1]*_t1*_t14*_t3*_t52*_t84*_t87 + (0.20e2 / 0.3e1)*_hc0[0]*_t105*_t173*_t174*_t184*_t36*_t46 - _hc4[1]*_t179 - _hc4[2]*_t183 - _hc4[3]*_t176 + (0.80e2 / 0.9e1)*_t101*_t105*_t13*_t180*_t36*_t46*_t90*_t91 + (0.2e1 / 0.3e1)*_t101*_t14*_t52*_t84*_t90*_t91*_t92 - _t185*_t186 - 0.8e1 / 0.9e1*_t189 - _t190*_t192*_t194 - 0.20e2 / 0.3e1*_t195 - 0.4e1*_t196 - _t248);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t249 = (0.448e3 / 0.27e2)*_t177;
  const double _t251 = xc_powi(na, -5);
  const double _t252 = (0.2e1 / 0.9e1)*_t251;
  const double _t253 = _t173*_t252;
  const double _t254 = 0.1e1/(_t40*xc_powr(na, 16, 3));
  const double _t255 = (0.1e1 / 0.216e3)*_t254;
  const double _t256 = _t1*_t255;
  const double _t257 = xc_powr(na, -13, 3);
  const double _t258 = (0.140e3 / 0.81e2)*_t257;
  const double _t259 = xc_powr(na, -14, 3);
  const double _t260 = (0.40e2 / 0.81e2)*_t259;
  const double _t261 = _t182*_t260;
  const double _t262 = _t173*_t251;
  const double _t266 = _t257*_t4;
  const double _t268 = _t1*_t254;
  const double _t270 = _t182*_t259;
  const double _t272 = _t270*_t36;
  const double _t276 = _t258*_t4;
  const double _t277 = _t174*_t202;
  const double _t278 = _t23*_t277;
  const double _t281 = _t61/xc_powr(M_PI, 5, 6);
  const double _t283 = _t114*_t180;
  const double _t285 = _t257*_t281;
  const double _t308 = (0.1120e4 / 0.27e2)*_t257;
  const double _t310 = (0.640e3 / 0.27e2)*_t270;
  const double _t311 = _t135*_t180;
  const double _t250 = (0.320e3 / 0.3e1)*_t228*_t80;
  const double _t263 = _t184*_t262;
  const double _t264 = _hc0[0]*_t263;
  const double _t265 = _t106*_t46;
  const double _t267 = ((_hc9[1]) * (_hc9[1]) * (_hc9[1]) * (_hc9[1]));
  const double _t269 = _t267*_t268;
  const double _t271 = _t262*_t80;
  const double _t273 = _hc0[0]*_t184;
  const double _t274 = _t106*_t84;
  const double _t275 = (0.16e2 / 0.3e1)*_hc9[1];
  const double _t279 = _t184*_t218;
  const double _t280 = _t18*_t257;
  const double _t282 = _hc1[4]*_t281;
  const double _t284 = _hc1[1]*_t283;
  const double _t286 = _hc1[3]*_t285;
  const double _t287 = _t180*_t27;
  const double _t288 = _t124*_t287;
  const double _t289 = _t257*_t37;
  const double _t290 = _t267*_t289;
  const double _t291 = _t281*_t290;
  const double _t292 = _t184*_t74;
  const double _t293 = _hc1[1]*_t285;
  const double _t294 = _t257*_t27;
  const double _t295 = _t101*_t294;
  const double _t296 = _hc5[3]*_t174;
  const double _t297 = _hc5[2]*_hc9[1];
  const double _t298 = _t215*_t251;
  const double _t299 = _hc5[0]*_t184;
  const double _t300 = _hc5[1]*_t101*_t174;
  const double _t301 = 0.16e2*_t219;
  const double _t302 = _hc4[4]*_t268;
  const double _t303 = _hc5[4]*_t4;
  const double _t304 = _t224*_t259;
  const double _t305 = _t136*_t180;
  const double _t306 = _hc4[1]*_t262;
  const double _t307 = (0.4e1 / 0.9e1)*_hc4[3]*_t268;
  const double _t309 = _hc5[3]*_t266;
  const double _t312 = _hc5[1]*_t311;
  const double _t313 = _hc4[0]*_t269;
  const double _t314 = _hc4[1]*_t268;
  const double _t315 = _hc4[2]*_t268;
  const double _t316 = _t290*_t4;
  const double _t317 = _hc5[1]*_t266;
  const double _t318 = _t148*_t287;
  const double _t319 = _t13*_t267;
  const double _t320 = _hc2[4]*_t255*_t8 + _t239*_t252 + _t240*_t260 + (0.70e2 / 0.81e2)*_t257*_t76;
  const double d4F_dna4 = (0.64e2 / 0.3e1)*_hc0[0]*_hc9[1]*_t1*_t14*_t3*_t52*_t84*_t87 + (0.80e2 / 0.3e1)*_hc0[0]*_t105*_t173*_t174*_t184*_t36*_t46 + (0.320e3 / 0.9e1)*_t101*_t105*_t13*_t180*_t36*_t46*_t90*_t91 + (0.8e1 / 0.3e1)*_t101*_t14*_t52*_t84*_t90*_t91*_t92 - _t186*_t249 - 0.32e2 / 0.9e1*_t189 - _t194*_t250 - 0.80e2 / 0.3e1*_t195 - 0.16e2*_t196 - _t217 - _t222 - _t226 - 0.4e1*_t248 + na*(_hc4[2]*_t261 + _hc4[3]*_t253 + _hc4[4]*_t256 + _t102*_t143*_t171 + (0.320e3 / 0.81e2)*_t102*_t270*_t46 - 0.3200e4 / 0.81e2*_t104*_t105*_t272*_t46 + (0.320e3 / 0.9e1)*_t104*_t187*_t274 - 0.40e2 / 0.3e1*_t107*_t171*_t99 + _t127*_t258 + (0.80e2 / 0.3e1)*_t13*_t194*_t269 - _t16*(-0.28e2 / 0.27e2*_hc1[2]*_t23*_t281*_t295 + _hc7[4]*_t17*_t256 + (0.1e1 / 0.5184e4)*_hc8[4]*_t272 + _t111*_t261 - 0.16e2 / 0.243e3*_t116*_t180 - 0.256e3 / 0.243e3*_t120*_t284 - 0.8e1 / 0.81e2*_t120*_t286 + (0.448e3 / 0.243e3)*_t177*_t24*_t68 + (0.56e2 / 0.243e3)*_t177*_t65 + _t197*_t253 + (0.7e1 / 0.432e3)*_t199/xc_powr(na, 9, 2) + (0.511e3 / 0.2592e4)*_t200*_t257 - 0.224e3 / 0.9e1*_t202*_t24*_t279 - 0.2e1 / 0.27e2*_t204*_t277 - 0.16e2 / 0.9e1*_t206*_t278 - 0.112e3 / 0.9e1*_t209*_t278 - 0.1e1 / 0.324e3*_t23*_t280*_t282 - 0.112e3 / 0.27e2*_t23*_t292*_t293 - 0.896e3 / 0.243e3*_t24*_t288 - 0.140e3 / 0.27e2*_t24*_t291 + _t26*(-0.35e2 / 0.9e1*_hc5[0]*_t316 - 0.112e3 / 0.81e2*_hc5[0]*_t318 - 0.7e1 / 0.9e1*_hc5[2]*_t295*_t4 + (0.560e3 / 0.81e2)*_t127*_t294 + _t129*_t298 + (0.20e2 / 0.3e1)*_t13*_t313 - _t130*_t296 + _t144*_t310 + (0.1600e4 / 0.27e2)*_t147*_t270 + 0.80e2*_t152*_t306 + (0.10e2 / 0.3e1)*_t152*_t315 + (0.320e3 / 0.3e1)*_t163*_t263 - 0.4e1 / 0.3e1*_t174*_t297*_t66 + (0.14e2 / 0.81e2)*_t177*_t223 + (0.112e3 / 0.81e2)*_t177*_t232 - 0.2e1 / 0.81e2*_t18*_t305 + (0.80e2 / 0.9e1)*_t190*_t314 - 0.56e2 / 0.3e1*_t218*_t299 + _t231*_t308 + _t262*_t301*_t74 - 0.28e2 / 0.3e1*_t27*_t300 + (0.1e1 / 0.54e2)*_t27*_t302 + (0.160e3 / 0.81e2)*_t27*_t304 - 0.1e1 / 0.432e3*_t280*_t303 - 0.28e2 / 0.9e1*_t292*_t317 + _t307*_t75 - 0.2e1 / 0.27e2*_t309*_t67 - 0.32e2 / 0.81e2*_t312*_t67) + _t276*_t57 + _t30*((0.448e3 / 0.81e2)*_hc1[0]*_hc9[1]*_t10*_t177*_t59*_t60*_t74 - 0.640e3 / 0.81e2*_hc1[0]*_t152*_t283 + (0.224e3 / 0.243e3)*_hc1[1]*_t10*_t177*_t27*_t59*_t60 - 0.20e2 / 0.9e1*_hc1[2]*_t152*_t285 + (0.4e1 / 0.5e1)*_hc9[1]*_t10*_t159*_t48*_t59*_t60*_t66 + (0.56e2 / 0.135e3)*_hc9[1]*_t10*_t177*_t33*_t59*_t60*_t66 + (0.4e1 / 0.5e1)*_hc9[1]*_t10*_t242*_t5*_t59*_t60*_t66 + (0.28e2 / 0.15e2)*_t101*_t11*_t113*_t27*_t39*_t78*_t92 - 0.64e2 / 0.243e3*_t115*_t287 - 0.14e2 / 0.5e1*_t125*_t159 - _t153*_t285*_t319 + (0.28e2 / 0.5e1)*_t184*_t19*_t198*_t201*_t74*_t78 - 0.160e3 / 0.27e2*_t190*_t293 - _t191*_t237 - 0.32e2 / 0.45e2*_t212*_t78 - _t218*_t235*_t275 - 0.3e1 / 0.5e1*_t22*_t242 - 0.8e1 / 0.27e2*_t234*_t277 - 0.320e3 / 0.9e1*_t236*_t277 - 0.28e2 / 0.5e1*_t238*_t279 - 0.1e1 / 0.81e2*_t282*_t294 - 0.256e3 / 0.81e2*_t284*_t75 - 0.8e1 / 0.27e2*_t286*_t75 - 0.112e3 / 0.135e3*_t288*_t33 - 0.7e1 / 0.6e1*_t291*_t33 - _t79*(_hc3[2]*_t261 + _hc3[3]*_t253 + _hc3[4]*_t256 + _t156*_t258 + _t320)) + _t36*(0.32e2*_hc4[0]*_t264 - 0.80e2 / 0.27e2*_hc5[0]*_t152*_t311 - 0.10e2 / 0.3e1*_hc5[0]*_t266*_t319 - _hc5[2]*_t168*_t266 + 0.48e2*_t104*_t306 + 0.2e1*_t104*_t315 + (0.280e3 / 0.27e2)*_t127*_t289 + _t141*_t246*_t5 + _t142*_t170 + (0.7e1 / 0.6e1)*_t148*_t213*_t82 - 0.7e1 / 0.4e1*_t149*_t170 + _t160*_t298 - _t161*_t296 + _t165*_t185 + _t166*_t310 + (0.320e3 / 0.9e1)*_t167*_t270 - 0.8e1 / 0.9e1*_t169*_t87 + (0.56e2 / 0.81e2)*_t177*_t243 + _t178*_t245 - 0.40e2 / 0.9e1*_t190*_t317 - _t191*_t299*_t80 + 0.7e1*_t208*_t82 - 0.4e1*_t218*_t297 + _t244*_t308 - 0.3e1 / 0.4e1*_t246*_t43 - 0.8e1 / 0.81e2*_t27*_t305 + _t271*_t301 + (0.8e1 / 0.3e1)*_t273*_t314 - 0.7e1*_t279*_t42 - 0.1e1 / 0.108e3*_t294*_t303 - 0.20e2*_t300*_t37 + (0.1e1 / 0.36e2)*_t302*_t37 + (0.80e2 / 0.27e2)*_t304*_t37 + _t307*_t81 - 0.2e1 / 0.9e1*_t309*_t75 - 0.32e2 / 0.27e2*_t312*_t75 + (0.2e1 / 0.3e1)*_t313 - 0.35e2 / 0.24e2*_t316*_t42 - 0.14e2 / 0.27e2*_t318*_t42 - _t83*(_hc6[1]*_t276 + _hc6[2]*_t261 + _hc6[3]*_t253 + _hc6[4]*_t256 + (0.56e2 / 0.405e3)*_t177*_t41 + _t320)) + (0.1729e4 / 0.2592e4)*_t58/xc_powr(na, 25, 6)) + (0.32e2 / 0.3e1)*_t171*_t96*_t97 + (0.640e3 / 0.3e1)*_t184*_t194*_t271 - 0.32e2 / 0.9e1*_t188*_t84 + _t192*_t273*_t274 - _t193*_t250*_t84 - _t247*_t275*_t55 - _t249*_t4*_t84*_t97 - 0.160e3 / 0.3e1*_t264*_t265 - 0.10e2 / 0.9e1*_t265*_t269 + (0.1120e4 / 0.81e2)*_t266*_t98 - 0.560e3 / 0.9e1*_t17*_t269*_t37*_t46/xc_powi(_t15, 8));
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(_t1, -1, 3);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = M_CBRTPI;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t3*_t5;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = _t2*_t7;
  const double _t9 = na - nb;
  const double _t10 = (0.1e1 / _t1);
  const double _t11 = _t10*_t9;
  const double _t12 = xc_powr(0.2e1, 2, 3);
  const double _t13 = xc_powr(0.3e1, 1, 6);
  const double _t14 = xc_powr(M_PI, 1, 6);
  const double _t15 = (0.1e1 / _t14);
  const double _t16 = _t12*_t13*_t15*p->cam_omega;
  const double _t18 = xc_powr(_t1, -1, 6);
  const double _t19 = (0.1e1 / 0.2e1)*_t18;
  const double _t21 = ((p->cam_omega) * (p->cam_omega));
  const double _t25 = xc_powi((p->cam_omega), 8);
  const double _t26 = na*nb;
  const double _t28 = xc_powi((p->cam_omega), 5);
  const double _t30 = xc_powr(0.2e1, 1, 2);
  const double _t31 = xc_powr(M_PI, 1, 2);
  const double _t32 = _t30*_t31;
  const double _t37 = xc_powi((p->cam_omega), 6);
  const double _t39 = 0.2e1*nb;
  const double _t44 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t48 = (0.1e1 / (_t1 * _t1));
  const double _t49 = 0.4e1*_t48;
  const double _t52 = (0.1e1 / 0.2e1)*_t11;
  const double _t53 = _t52 + 0.1e1 / 0.2e1;
  const double _t54 = (_t53 * _t53);
  const double _t55 = 0.1e1 / 0.2e1 - _t52;
  const double _t56 = (_t55 * _t55);
  const double _t61 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t67 = xc_powr(0.3e1, 2, 3);
  const double _t69 = xc_powr(_t1, 2, 3);
  const double _t70 = (M_PI * M_CBRTPI);
  const double _t71 = (0.1e1 / 0.5e1)*_t70;
  const double _t72 = _t69*_t71;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, _t8, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t7/xc_powr(na, 1, 3), _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g1_k, _KMAX)(p, _t7/xc_powr(nb, 1, 3), _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_D3_k, _KMAX)(p, _t8, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0_k, _KMAX)(p, _t8, _hc4);
  double _hc5[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, _t8, _t11, _hc5);
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_D2_k, _KMAX)(p, _t8, _hc6);
  double _hc7[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_phin_k, _KMAX)(p, 0.8e1, _t11, _hc7);
  double _hc8[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_g0c_k, _KMAX)(p, _t8, _hc8);
  double _hc9[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_a5_k, _KMAX)(p, _t8, _t11, _hc9);
  double _hc10[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_c_pw_erf_phin_k, _KMAX)(p, 0.2e1, _t11, _hc10);
  const double _t17 = _t16/_hc10[0];
  const double _t20 = ((_hc0[0]) * (_hc0[0]));
  const double _t22 = _t20*_t21 + 0.1e1;
  const double _t23 = (0.1e1 / (_t22 * _t22 * _t22 * _t22));
  const double _t24 = ((_hc10[0]) * (_hc10[0]) * (_hc10[0]));
  const double _t27 = _hc4[0]*_t10;
  const double _t29 = xc_powi((_hc0[0]), 8);
  const double _t33 = _t29*_t32;
  const double _t34 = _t28*_t33;
  const double _t35 = (0.8e1 / 0.3e1)*_t34;
  const double _t36 = _t27*_t35;
  const double _t38 = xc_powi((_hc0[0]), 6);
  const double _t40 = M_PI*_t29;
  const double _t41 = _hc8[0]*_t10;
  const double _t42 = _t40*_t41;
  const double _t43 = _t39*_t42;
  const double _t45 = _t32*_t38;
  const double _t46 = (0.32e2 / 0.3e1)*_t45;
  const double _t47 = _t27*_t46;
  const double _t50 = _hc3[0]*_t49;
  const double _t51 = _t50*nb;
  const double _t57 = _hc1[0]*_t54 + _hc2[0]*_t56;
  const double _t58 = _t51*na + _t57;
  const double _t59 = (0.3e1 / 0.20e2)*_t33;
  const double _t60 = _t58*_t59;
  const double _t62 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t63 = M_PI*_t38;
  const double _t64 = 0.8e1*_t63;
  const double _t65 = _t41*_t64;
  const double _t66 = _t65*nb;
  const double _t68 = _hc7[0]*_t67;
  const double _t73 = _hc6[0]*_t49*na*nb + _t57 - _t68*_t72;
  const double _t74 = (0.3e1 / 0.16e2)*_t40;
  const double _t75 = _t73*_t74;
  double _hc11[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_Q_k, _KMAX)(p, _t17*_t19, _hc11);
  const double _t76 = _hc11[0]*_t24 + _hc9[0]*_t25 - _t26*_t36 + _t37*(0.4e1*_hc5[0]*_t38 - _t43*na) + _t44*(-_t1*_t60 - _t26*_t47) + _t61*(0.6e1*_hc5[0]*_t62 - _t1*_t75 - _t66*na);
  const double _t77 = _hc5[0] - _t23*_t76;
  const double zk = _t77;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t79 = xc_powr(_t1, -4, 3);
  const double _t80 = (0.1e1 / 0.6e1)*_t79;
  const double _t85 = _t6*_t79;
  const double _t90 = -_t10;
  const double _t91 = _t48*_t9;
  const double _t92 = _t90 + _t91;
  const double _t93 = -_t92;
  const double _t96 = (0.1e1 / 0.6e1)*_t6;
  const double _t100 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t101 = 0.8e1*_t100;
  const double _t104 = xc_powr(_t1, -10, 3);
  const double _t105 = _t104*_t6;
  const double _t106 = (0.2e1 / 0.3e1)*_t105;
  const double _t114 = xc_powr(0.2e1, 5, 6);
  const double _t115 = M_CBRT3;
  const double _t116 = _t114*_t115;
  const double _t117 = _t116*_t14;
  const double _t119 = (0.1e1 / 0.5e1)*_t2;
  const double _t121 = (0.16e2 / 0.9e1)*_t26;
  const double _t122 = xc_powr(_t1, -7, 3);
  const double _t123 = _t117*_t122;
  const double _t135 = _t101*nb;
  const double _t138 = (0.2e1 / 0.15e2)*_t2;
  const double _t139 = _t106*nb;
  const double _t149 = (M_CBRTPI * M_CBRTPI);
  const double _t150 = _t149*_t3;
  const double _t161 = 0.2e1*_t48;
  const double _t164 = _t6*_t80;
  const double _t166 = xc_powr(_t1, -7, 6);
  const double _t167 = (0.1e1 / 0.12e2)*_t166;
  const double _t180 = (0.4e1 / 0.9e1)*_t122;
  const double _t187 = (0.32e2 / 0.9e1)*_t28;
  const double _t193 = _t10 + _t91;
  const double _t194 = -_t193;
  const double _t196 = xc_powr(nb, -4, 3);
  const double _t197 = _t196*_t96;
  const double _t204 = 0.2e1*na;
  const double _t78 = _hc5[2]*_t6;
  const double _t81 = _t78*_t80;
  const double _t82 = xc_powi(_t22, -5);
  const double _t83 = _t21*_t82;
  const double _t94 = _hc1[0]*_t53;
  const double _t95 = _hc2[0]*_t55;
  const double _t97 = _hc1[1]/xc_powr(na, 4, 3);
  const double _t98 = _t96*_t97;
  const double _t99 = _t54*_t98;
  const double _t102 = _hc3[0]*na;
  const double _t103 = _t101*_t102;
  const double _t107 = _hc3[1]*na;
  const double _t108 = _t106*_t107;
  const double _t109 = -_t103*nb - _t108*nb;
  const double _t110 = _t109 + _t51 + _t92*_t95 + _t93*_t94 - _t99;
  const double _t111 = _t110*_t59;
  const double _t112 = xc_powi((_hc0[0]), 7);
  const double _t120 = _hc4[0]*_t48;
  const double _t124 = _hc4[1]*_t123;
  const double _t125 = xc_powi((_hc0[0]), 5);
  const double _t128 = _hc4[0]*_t123;
  const double _t130 = -_t81;
  const double _t131 = _hc5[1]*_t93 + _t130;
  const double _t132 = 0.6e1*_t62;
  const double _t133 = _hc7[1]*_t67;
  const double _t134 = _t133*_t72;
  const double _t136 = _hc6[0]*na;
  const double _t137 = _t68*_t70;
  const double _t140 = _hc6[1]*na;
  const double _t141 = _t135*_t136 + _t137*_t138 + _t139*_t140;
  const double _t142 = _hc1[0]*_t53*_t93 + _hc2[0]*_t55*_t92 + 0.4e1*_hc6[0]*_t48*nb - _t134*_t93 - _t141 - _t99;
  const double _t143 = _t142*_t74;
  const double _t144 = 0.4e1*_hc5[0];
  const double _t145 = _t144*_t85;
  const double _t146 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t148 = _hc8[0]*na;
  const double _t154 = _hc8[1]*_t150;
  const double _t155 = _t122*_t154;
  const double _t156 = _t155*_t26;
  const double _t158 = _t122*_t148;
  const double _t160 = 0.4e1*_t38;
  const double _t162 = _hc8[0]*_t40;
  const double _t165 = -_hc9[2]*_t164;
  const double _t168 = _t167*_t17;
  const double _t169 = ((_hc10[0]) * (_hc10[0]));
  const double _t170 = (0.1e1 / _t169);
  const double _t171 = _t16*_t170;
  const double _t172 = _hc10[1]*_t171;
  const double _t173 = _t172*_t19;
  const double _t174 = -_t168 - _t173*_t93;
  const double _t177 = _hc10[1]*_t169;
  const double _t178 = 0.3e1*_t177;
  const double _t179 = _t120*_t35;
  const double _t181 = _hc4[1]*_t117;
  const double _t182 = _t180*_t181;
  const double _t183 = _t26*_t29;
  const double _t184 = _t183*_t28;
  const double _t195 = _hc2[1]*_t56;
  const double _t198 = _t195*_t197;
  const double _t199 = _t109 + _t193*_t95 + _t194*_t94 - _t198 + _t50*na;
  const double _t200 = _t199*_t59;
  const double _t201 = _hc5[1]*_t194 + _t130;
  const double _t202 = _hc1[0]*_t194*_t53 + _hc2[0]*_t193*_t55 + 0.4e1*_hc6[0]*_t48*na - _t134*_t194 - _t141 - _t198;
  const double _t203 = _t202*_t74;
  const double _t205 = -_t168 - _t173*_t194;
  double _hc12[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_c_pw_erf_b0_k, _KMAX)(p, 0, _hc12);
  const double _t84 = _t76*_t83;
  const double _t86 = _hc0[0]*_hc12[1];
  const double _t87 = _t85*_t86;
  const double _t88 = _t84*_t87;
  const double _t89 = _t81 + (0.4e1 / 0.3e1)*_t88;
  const double _t113 = _hc12[1]*_t112;
  const double _t118 = _t113*_t117;
  const double _t126 = _hc12[1]*_t125;
  const double _t127 = (0.32e2 / 0.3e1)*_t126;
  const double _t129 = _t118*_t119*_t58 + _t120*_t26*_t46 + _t121*_t124*_t38 + _t127*_t128*_t26 - _t60;
  const double _t147 = _hc12[1]*_t146;
  const double _t151 = _t113*_t150;
  const double _t152 = _t151*_t2;
  const double _t153 = (0.1e1 / 0.4e1)*_t152;
  const double _t157 = _t126*_t150;
  const double _t159 = -_t145*_t147 + _t148*_t48*_t64*nb + _t153*_t73 + (0.4e1 / 0.3e1)*_t156*_t38 + 0.8e1*_t157*_t158*nb - _t75;
  const double _t163 = -_t126*_t145 + (0.8e1 / 0.3e1)*_t151*_t158*nb + (0.1e1 / 0.3e1)*_t156*_t29 + _t161*_t162*na*nb;
  const double _t175 = _hc11[1]*_t24;
  const double _t176 = _hc11[0]*_t93;
  const double _t185 = _t113*_t123;
  const double _t186 = _hc4[0]*_t185;
  const double _t188 = _t186*_t187;
  const double _t189 = _t179*_t26 + _t182*_t184 + _t188*_t26;
  const double _t190 = _t174*_t175 + _t176*_t178 + _t189 + _t25*(_hc9[1]*_t93 + _t165) - _t36*nb + _t37*(_t131*_t160 + _t163 - _t43) + _t44*(-_t1*_t111 + _t129 - _t47*nb) + _t61*(-_t1*_t143 + _t131*_t132 + _t159 - _t66);
  const double _t191 = _t190*_t23;
  const double _t192 = -_hc5[1]*_t93 + _t191;
  const double _t206 = _hc11[0]*_t178;
  const double _t207 = _t175*_t205 + _t189 + _t194*_t206 + _t25*(_hc9[1]*_t194 + _t165) - _t36*na + _t37*(_t160*_t201 + _t163 - _t204*_t42) + _t44*(-_t1*_t200 + _t129 - _t47*na) + _t61*(-_t1*_t203 + _t132*_t201 + _t159 - _t65*na);
  const double _t208 = _t207*_t23;
  const double _t209 = -_hc5[1]*_t194 + _t208;
  const double dF_dna = _t1*(-_t192 - _t89) + _t77;
  const double dF_dnb = _t1*(-_t209 - _t89) + _t77;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t211 = 0.16e2*_t100;
  const double _t213 = (0.4e1 / 0.3e1)*_t105;
  const double _t215 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t216 = 0.24e2*_t215;
  const double _t218 = xc_powr(_t1, -14, 3);
  const double _t219 = xc_powr(0.6e1, 2, 3);
  const double _t220 = (0.1e1 / _t149);
  const double _t221 = _t219*_t220;
  const double _t222 = _t218*_t221;
  const double _t224 = (0.1e1 / 0.9e1)*na;
  const double _t226 = xc_powr(_t1, -13, 3);
  const double _t227 = _t226*_t6;
  const double _t228 = (0.32e2 / 0.9e1)*_t227;
  const double _t231 = _t100*_t9;
  const double _t232 = 0.2e1*_t231;
  const double _t233 = -_t161 + _t232;
  const double _t234 = (0.1e1 / 0.2e1)*_t10;
  const double _t235 = (0.1e1 / 0.2e1)*_t91;
  const double _t236 = -_t234 + _t235;
  const double _t237 = -_t236;
  const double _t239 = -_t233;
  const double _t242 = xc_powr(na, -8, 3);
  const double _t243 = (0.1e1 / 0.36e2)*_t221;
  const double _t244 = _t242*_t243;
  const double _t246 = xc_powr(na, -7, 3);
  const double _t247 = (0.2e1 / 0.9e1)*_t6;
  const double _t248 = _t246*_t247;
  const double _t250 = (0.1e1 / 0.3e1)*_t6;
  const double _t251 = _t250*_t93;
  const double _t256 = xc_powr(_t1, -5, 3);
  const double _t258 = xc_powr(0.2e1, 1, 6);
  const double _t259 = _t15*_t258*_t67;
  const double _t266 = xc_powr(_t1, -11, 3);
  const double _t273 = _t259*_t266;
  const double _t280 = (0.160e3 / 0.9e1)*_t26;
  const double _t285 = (0.2e1 / 0.9e1)*_t122;
  const double _t297 = _t71*xc_powr(0.3e1*na + 0.3e1*nb, 2, 3);
  const double _t298 = (_t93 * _t93);
  const double _t303 = (0.4e1 / 0.15e2)*_t2;
  const double _t304 = (0.2e1 / 0.45e2)*_t79;
  const double _t310 = xc_powr(_t1, -8, 3);
  const double _t315 = _t219*_t4;
  const double _t322 = (0.40e2 / 0.9e1)*nb;
  const double _t326 = _t266*_t315;
  const double _t338 = 0.4e1*nb;
  const double _t345 = (0.10e2 / 0.9e1)*_t26;
  const double _t356 = _t285*_t6;
  const double _t363 = (0.1e1 / 0.6e1)*_t166;
  const double _t365 = xc_powr(_t1, -13, 6);
  const double _t371 = _t16*_t18;
  const double _t372 = _t298*_t371;
  const double _t380 = 0.3e1*_t233;
  const double _t396 = (0.64e2 / 0.9e1)*_t28;
  const double _t429 = _t122*_t6;
  const double _t430 = (0.16e2 / 0.9e1)*_t429;
  const double _t432 = (0.1e1 / 0.3e1)*_t79;
  const double _t438 = _t234 + _t235;
  const double _t439 = -_t438;
  const double _t441 = _t194*_t53;
  const double _t453 = _t67*_t72;
  const double _t467 = _t194*_t93;
  const double _t469 = xc_powr(_t1, -19, 6);
  const double _t481 = 0.6e1*_t100;
  const double _t482 = _t481*_t9;
  const double _t489 = _t161 + _t232;
  const double _t491 = -_t489;
  const double _t494 = xc_powr(nb, -8, 3);
  const double _t495 = _t243*_t494;
  const double _t496 = xc_powr(nb, -7, 3);
  const double _t497 = _t247*_t496;
  const double _t507 = (_t194 * _t194);
  const double _t518 = 0.3e1*_t489;
  const double _t210 = (0.3e1 / 0.10e2)*_t33;
  const double _t212 = _hc3[0]*_t211;
  const double _t214 = _hc3[1]*_t213;
  const double _t217 = _t102*_t216;
  const double _t223 = _hc3[2]*_t222;
  const double _t225 = _t223*_t224;
  const double _t229 = _t107*_t228;
  const double _t230 = _t217*nb + _t225*nb + _t229*nb;
  const double _t238 = _hc1[0]*_t93;
  const double _t240 = _hc2[0]*_t92;
  const double _t241 = _hc1[2]*_t54;
  const double _t245 = _hc1[1]*_t54;
  const double _t249 = _t53*_t97;
  const double _t252 = _t233*_t94 + _t236*_t240 + _t237*_t238 + _t239*_t95 + _t241*_t244 + _t245*_t248 - _t249*_t251;
  const double _t253 = -_t212*nb - _t214*nb + _t230 + _t252;
  const double _t254 = _t253*_t59;
  const double _t260 = _t259*_t38;
  const double _t262 = (0.7e1 / 0.15e2)*_t58;
  const double _t263 = _hc4[0]*_t45;
  const double _t264 = (0.64e2 / 0.3e1)*_t263;
  const double _t265 = _t100*_t264;
  const double _t267 = _t266*_t38;
  const double _t268 = _t259*_t267;
  const double _t269 = _hc4[2]*_t268;
  const double _t270 = (0.16e2 / 0.27e2)*_t269;
  const double _t271 = _t181*_t38;
  const double _t272 = _t104*_t271;
  const double _t274 = _hc4[1]*_t273;
  const double _t281 = _hc4[0]*_t104;
  const double _t286 = _t285*_t78;
  const double _t287 = _hc5[1]*_t233;
  const double _t288 = -_hc5[4]*_t164;
  const double _t289 = _hc5[3]*_t93 + _t288;
  const double _t290 = _t289*_t93;
  const double _t291 = -_hc5[5]*_t164;
  const double _t292 = _hc5[4]*_t93 + _t291;
  const double _t293 = -_t164*_t292 + _t287 + _t290;
  const double _t294 = _t286 + _t293;
  const double _t295 = (0.3e1 / 0.8e1)*_t40;
  const double _t296 = _hc6[0]*_t211;
  const double _t299 = _hc7[3]*_t298;
  const double _t300 = _hc6[1]*_t213;
  const double _t301 = _t133*_t70;
  const double _t302 = _t301*_t93;
  const double _t305 = _hc6[2]*_t222*_t224*nb + _t136*_t216*nb + _t137*_t304 + _t140*_t228*nb;
  const double _t306 = -_t134*_t233 + _t252 - _t296*nb - _t297*_t299 - _t300*nb - _t302*_t303 + _t305;
  const double _t307 = _t306*_t74;
  const double _t309 = 0.8e1*_t131;
  const double _t311 = _hc8[0]*_t63;
  const double _t312 = _t211*_t311;
  const double _t313 = _t312*na;
  const double _t316 = _t315*_t38;
  const double _t317 = (0.7e1 / 0.24e2)*_t316;
  const double _t318 = _t256*_t317;
  const double _t319 = _hc8[2]*_t315;
  const double _t320 = _t266*_t319;
  const double _t321 = (0.2e1 / 0.9e1)*_t320*_t38;
  const double _t323 = _t154*_t38;
  const double _t324 = _t104*_t323;
  const double _t325 = _t322*_t324;
  const double _t333 = _t104*_t148;
  const double _t339 = _t100*_t162;
  const double _t340 = _t338*_t339;
  const double _t341 = _t29*_t320;
  const double _t342 = (0.1e1 / 0.18e2)*_t341;
  const double _t343 = _t154*_t29;
  const double _t344 = _t104*_t343;
  const double _t346 = _hc8[1]*_t326;
  const double _t349 = _t267*_t315;
  const double _t357 = _hc9[2]*_t356;
  const double _t358 = -_hc9[5]*_t164;
  const double _t359 = _hc9[4]*_t93 + _t358;
  const double _t360 = -_hc9[4]*_t164;
  const double _t361 = _hc9[3]*_t93 + _t360;
  const double _t362 = _t172*_t93;
  const double _t364 = _t362*_t363;
  const double _t366 = _t17*_t365;
  const double _t367 = (0.7e1 / 0.72e2)*_t366;
  const double _t368 = ((_hc10[1]) * (_hc10[1]));
  const double _t369 = (0.1e1 / _t24);
  const double _t370 = _t368*_t369;
  const double _t373 = _t370*_t372;
  const double _t374 = _hc10[3]*_t298;
  const double _t375 = _t171*_t19;
  const double _t376 = _t367 + _t373 - _t374*_t375;
  const double _t377 = -_t173*_t233 + _t364 + _t376;
  const double _t378 = (_t174 * _t174);
  const double _t382 = 0.3e1*_t169;
  const double _t386 = _hc10[0]*_t368;
  const double _t390 = _t174*_t93;
  const double _t391 = (0.16e2 / 0.3e1)*_t34;
  const double _t392 = _t120*_t391;
  const double _t393 = (0.8e1 / 0.9e1)*_t124;
  const double _t394 = _t29*nb;
  const double _t395 = _t28*_t394;
  const double _t398 = _t100*_t391;
  const double _t399 = _hc4[0]*_t398;
  const double _t400 = _t104*_t181;
  const double _t401 = (0.40e2 / 0.27e2)*_t400;
  const double _t402 = _hc4[2]*_t259;
  const double _t403 = _t266*_t402;
  const double _t423 = xc_powi(_t22, -6);
  const double _t424 = _t423*_t61;
  const double _t434 = _hc5[4]*_t194 + _t291;
  const double _t435 = _t164*_t434;
  const double _t436 = _hc5[3]*_t194 + _t288;
  const double _t440 = _t232*_t95;
  const double _t442 = _t441*_t98;
  const double _t443 = _hc2[1]*_t55;
  const double _t444 = _t197*_t443;
  const double _t445 = _t444*_t92;
  const double _t446 = -_hc3[0]*_t135 - _hc3[1]*_t139 - _t103 - _t108 + _t230 + _t232*_t94 + _t238*_t439 + _t240*_t438 - _t440 - _t442 - _t445 + _t50;
  const double _t447 = _t1*_t59;
  const double _t448 = _t436*_t93;
  const double _t449 = _t286 - _t435;
  const double _t450 = _hc5[1]*_t232 + _t448 + _t449;
  const double _t451 = (0.2e1 / 0.5e1)*_t301;
  const double _t452 = _t194*_t301;
  const double _t454 = _hc7[3]*_t453;
  const double _t455 = _t454*_t93;
  const double _t456 = 0.2e1*_hc1[0]*_t100*_t53*_t9 + _hc1[0]*_t439*_t93 + _hc2[0]*_t438*_t92 - _hc6[0]*_t135 + 0.24e2*_hc6[0]*_t215*na*nb + 0.4e1*_hc6[0]*_t48 - _hc6[1]*_t139 + (0.32e2 / 0.9e1)*_hc6[1]*_t226*_t3*_t5*na*nb + (0.1e1 / 0.9e1)*_hc6[2]*_t218*_t219*_t220*na*nb + (0.2e1 / 0.45e2)*_hc7[0]*_t67*_t70*_t79 - _t101*_t136 - _t106*_t140 - _t122*_t451*_t9 - _t138*_t302 - _t138*_t452 - _t194*_t455 - _t440 - _t442 - _t445;
  const double _t457 = _t1*_t74;
  const double _t460 = _hc9[3]*_t194 + _t360;
  const double _t461 = _hc9[4]*_t194 + _t358;
  const double _t462 = -_t164*_t461 + _t357;
  const double _t463 = _t172*_t194;
  const double _t464 = _t370*_t371;
  const double _t465 = _t464*_t93;
  const double _t466 = _t194*_t465;
  const double _t468 = _hc10[3]*_t375;
  const double _t470 = _t172*_t469;
  const double _t471 = _t470*_t9;
  const double _t472 = _t367 - _t471;
  const double _t473 = _t167*_t362 + _t167*_t463 + _t466 - _t467*_t468 + _t472;
  const double _t476 = _t205*_t93;
  const double _t483 = _t29*na;
  const double _t484 = _t28*_t483;
  const double _t485 = _hc4[0]*na;
  const double _t490 = _hc1[0]*_t439;
  const double _t492 = _hc2[0]*_t438;
  const double _t493 = _hc2[2]*_t56;
  const double _t498 = _t196*_t443;
  const double _t499 = _t250*_t498;
  const double _t500 = _t193*_t492 - _t193*_t499 + _t194*_t490 + _t195*_t497 + _t489*_t94 + _t491*_t95 + _t493*_t495;
  const double _t501 = -_t212*na - _t214*na + _t230 + _t500;
  const double _t502 = _t501*_t59;
  const double _t503 = _hc5[1]*_t489;
  const double _t504 = _t194*_t436;
  const double _t505 = _t503 + _t504;
  const double _t506 = _t449 + _t505;
  const double _t508 = _hc7[3]*_t507;
  const double _t509 = -_t134*_t489 - _t296*na - _t297*_t508 - _t300*na - _t303*_t452 + _t305 + _t500;
  const double _t510 = _t509*_t74;
  const double _t511 = 0.8e1*_t201;
  const double _t512 = _t363*_t463;
  const double _t513 = _t464*_t507;
  const double _t514 = _hc10[3]*_t507;
  const double _t515 = _t367 - _t375*_t514 + _t513;
  const double _t516 = -_t173*_t489 + _t512 + _t515;
  const double _t517 = (_t205 * _t205);
  const double _t255 = ((_hc12[1]) * (_hc12[1]));
  const double _t257 = _t255*_t256;
  const double _t261 = _t257*_t260;
  const double _t275 = _t126*_t274;
  const double _t276 = (0.64e2 / 0.9e1)*_t275;
  const double _t277 = _t255*_t62;
  const double _t278 = _t273*_t277;
  const double _t279 = _hc4[0]*_t278;
  const double _t282 = _t117*_t126;
  const double _t283 = _t281*_t282;
  const double _t284 = -0.2e1 / 0.15e2*_hc12[1]*_t112*_t114*_t115*_t14*_t58*_t79 + _t26*_t265 + _t26*_t270 + (0.160e3 / 0.27e2)*_t26*_t272 + _t26*_t276 + (0.320e3 / 0.9e1)*_t26*_t283 + _t261*_t262 + _t279*_t280;
  const double _t308 = _t147*_t85;
  const double _t314 = _t255*_t73;
  const double _t327 = _hc8[1]*_t126;
  const double _t328 = _t326*_t327;
  const double _t329 = (0.8e1 / 0.3e1)*_t328;
  const double _t330 = _t277*_t326;
  const double _t331 = (0.20e2 / 0.3e1)*_t330;
  const double _t332 = _t148*_t331;
  const double _t334 = _t157*_t333;
  const double _t335 = (0.80e2 / 0.3e1)*_t334;
  const double _t336 = -0.16e2 / 0.3e1*_hc12[1]*_hc5[0]*_t122*_t146*_t3*_t5 - 0.1e1 / 0.6e1*_hc12[1]*_t112*_t149*_t3*_t73*_t79 - 0.2e1*_hc5[0]*_t20*_t219*_t220*_t255*_t310 + _t26*_t321 + _t26*_t329 + _t313*nb + _t314*_t318 + _t325*na + _t332*nb + _t335*nb;
  const double _t337 = _t126*_t85;
  const double _t347 = _t113*_t346;
  const double _t348 = (0.8e1 / 0.9e1)*_t347;
  const double _t350 = _t148*_t255;
  const double _t351 = _t349*_t350;
  const double _t352 = (0.28e2 / 0.9e1)*_t351;
  const double _t353 = _t151*_t333;
  const double _t354 = (0.80e2 / 0.9e1)*_t353;
  const double _t355 = -0.16e2 / 0.3e1*_hc12[1]*_hc5[0]*_t122*_t125*_t3*_t5 - 0.10e2 / 0.3e1*_hc5[0]*_t219*_t220*_t255*_t310*_t62 + _t26*_t342 + _t26*_t348 + _t340*na + _t344*_t345 + _t352*nb + _t354*nb;
  const double _t379 = _hc11[2]*_t24;
  const double _t381 = _hc11[0]*_t177;
  const double _t383 = _hc10[3]*_hc11[0];
  const double _t384 = _t298*_t383;
  const double _t385 = 0.6e1*_hc11[0];
  const double _t387 = _t385*_t386;
  const double _t388 = 0.6e1*_hc11[1];
  const double _t389 = _t177*_t388;
  const double _t397 = _t186*_t396;
  const double _t404 = _t118*_t28;
  const double _t405 = _t281*_t404;
  const double _t406 = _t255*_t268;
  const double _t407 = _t28*_t406;
  const double _t408 = _hc4[0]*_t407;
  const double _t409 = _t113*_t28;
  const double _t410 = _t274*_t409;
  const double _t411 = (0.64e2 / 0.27e2)*_t410;
  const double _t412 = -_t184*_t401 - 0.4e1 / 0.27e2*_t184*_t403 - _t26*_t399 - 0.320e3 / 0.27e2*_t26*_t405 - 0.224e3 / 0.27e2*_t26*_t408 - _t26*_t411;
  const double _t413 = _t175*_t377 + _t25*(_hc9[1]*_t233 - _t164*_t359 + _t357 + _t361*_t93) + _t298*_t387 + _t37*((0.16e2 / 0.3e1)*_hc12[1]*_hc8[0]*_t112*_t122*_t149*_t3*nb + 0.4e1*M_PI*_hc8[0]*_t29*_t48*nb + (0.2e1 / 0.3e1)*_hc8[1]*_t122*_t149*_t29*_t3*nb + 0.4e1*_t294*_t38 - _t309*_t337 - _t355) + _t378*_t379 + _t380*_t381 + _t382*_t384 + _t389*_t390 + _t392*nb + _t393*_t395 + _t397*nb + _t412 + _t44*((0.64e2 / 0.3e1)*_hc12[1]*_hc4[0]*_t114*_t115*_t122*_t125*_t14*nb + (0.2e1 / 0.5e1)*_hc12[1]*_t110*_t112*_t114*_t115*_t14*_t2 + (0.64e2 / 0.3e1)*_hc4[0]*_t30*_t31*_t38*_t48*nb + (0.32e2 / 0.9e1)*_hc4[1]*_t114*_t115*_t122*_t14*_t38*nb - _t1*_t254 - _t110*_t210 - _t284) + _t61*(0.16e2*_hc12[1]*_hc8[0]*_t122*_t125*_t149*_t3*nb + (0.1e1 / 0.2e1)*_hc12[1]*_t112*_t142*_t149*_t2*_t3 + 0.16e2*M_PI*_hc8[0]*_t38*_t48*nb + (0.8e1 / 0.3e1)*_hc8[1]*_t122*_t149*_t3*_t38*nb - _t1*_t307 - _t142*_t295 + 0.6e1*_t294*_t62 - _t308*_t309 - _t336);
  const double _t414 = _t23*_t413;
  const double _t415 = -_t414;
  const double _t416 = _t83*_t87;
  const double _t417 = _t190*_t416;
  const double _t418 = -0.8e1 / 0.3e1*_t417;
  const double _t419 = _t255*_t310;
  const double _t420 = _t221*_t419;
  const double _t421 = _t420*_t84;
  const double _t422 = _t20*_t420;
  const double _t425 = _t424*_t76;
  const double _t426 = _t422*_t425;
  const double _t427 = (0.20e2 / 0.9e1)*_t426;
  const double _t428 = _t84*_t86;
  const double _t431 = (0.2e1 / 0.9e1)*_t421 - _t427 + _t428*_t430;
  const double _t433 = _t432*_t78 + (0.8e1 / 0.3e1)*_t88;
  const double _t437 = _t207*_t416;
  const double _t458 = 0.4e1*_t308;
  const double _t459 = 0.4e1*_t337;
  const double _t474 = _t174*_t379;
  const double _t475 = _hc11[1]*_t178;
  const double _t477 = _t194*_t475;
  const double _t478 = _hc10[3]*_t176;
  const double _t479 = _t382*_t478;
  const double _t480 = _t387*_t93;
  const double _t486 = _t185*_t485;
  const double _t487 = _t174*_t477 + _t175*_t473 + _t179*na + _t179*nb + _t182*_t395 + _t182*_t484 + _t187*_t486 + _t188*nb + _t194*_t479 + _t194*_t480 + _t205*_t474 + _t25*(_hc9[1]*_t232 + _t460*_t93 + _t462) - _t36 + _t37*((0.8e1 / 0.3e1)*_hc12[1]*_hc8[0]*_t112*_t122*_t149*_t3*na + (0.8e1 / 0.3e1)*_hc12[1]*_hc8[0]*_t112*_t122*_t149*_t3*nb + 0.2e1*M_PI*_hc8[0]*_t29*_t48*na + 0.2e1*M_PI*_hc8[0]*_t29*_t48*nb + (0.1e1 / 0.3e1)*_hc8[1]*_t122*_t149*_t29*_t3*na + (0.1e1 / 0.3e1)*_hc8[1]*_t122*_t149*_t29*_t3*nb - _t131*_t459 - _t201*_t459 - _t355 + 0.4e1*_t38*_t450 - 0.2e1*_t42) + _t381*_t482 + _t412 + _t44*((0.32e2 / 0.3e1)*_hc12[1]*_hc4[0]*_t114*_t115*_t122*_t125*_t14*na + (0.32e2 / 0.3e1)*_hc12[1]*_hc4[0]*_t114*_t115*_t122*_t125*_t14*nb + (0.1e1 / 0.5e1)*_hc12[1]*_t110*_t112*_t114*_t115*_t14*_t2 + (0.1e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t199*_t2 + (0.32e2 / 0.3e1)*_hc4[0]*_t30*_t31*_t38*_t48*na + (0.32e2 / 0.3e1)*_hc4[0]*_t30*_t31*_t38*_t48*nb + (0.16e2 / 0.9e1)*_hc4[1]*_t114*_t115*_t122*_t14*_t38*na + (0.16e2 / 0.9e1)*_hc4[1]*_t114*_t115*_t122*_t14*_t38*nb - _t111 - _t200 - _t284 - _t446*_t447 - _t47) + _t475*_t476 + _t61*(0.8e1*_hc12[1]*_hc8[0]*_t122*_t125*_t149*_t3*na + 0.8e1*_hc12[1]*_hc8[0]*_t122*_t125*_t149*_t3*nb + (0.1e1 / 0.4e1)*_hc12[1]*_t112*_t142*_t149*_t2*_t3 + (0.1e1 / 0.4e1)*_hc12[1]*_t112*_t149*_t2*_t202*_t3 + 0.8e1*M_PI*_hc8[0]*_t38*_t48*na + 0.8e1*M_PI*_hc8[0]*_t38*_t48*nb + (0.4e1 / 0.3e1)*_hc8[1]*_t122*_t149*_t3*_t38*na + (0.4e1 / 0.3e1)*_hc8[1]*_t122*_t149*_t3*_t38*nb - _t131*_t458 - _t143 - _t201*_t458 - _t203 - _t336 + 0.6e1*_t450*_t62 - _t456*_t457 - _t65);
  const double _t488 = _t23*_t487;
  const double _t519 = _t382*_t383;
  const double _t520 = _t194*_t389;
  const double _t521 = _t175*_t516 + _t205*_t520 + _t25*(_hc9[1]*_t489 + _t194*_t460 + _t462) + _t37*((0.16e2 / 0.3e1)*_hc12[1]*_hc8[0]*_t112*_t122*_t149*_t3*na + 0.4e1*M_PI*_hc8[0]*_t29*_t48*na + (0.2e1 / 0.3e1)*_hc8[1]*_t122*_t149*_t29*_t3*na - _t337*_t511 - _t355 + 0.4e1*_t38*_t506) + _t379*_t517 + _t381*_t518 + _t387*_t507 + _t392*na + _t393*_t484 + _t396*_t486 + _t412 + _t44*((0.64e2 / 0.3e1)*_hc12[1]*_hc4[0]*_t114*_t115*_t122*_t125*_t14*na + (0.2e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t199*_t2 + (0.64e2 / 0.3e1)*_hc4[0]*_t30*_t31*_t38*_t48*na + (0.32e2 / 0.9e1)*_hc4[1]*_t114*_t115*_t122*_t14*_t38*na - _t1*_t502 - _t199*_t210 - _t284) + _t507*_t519 + _t61*(0.16e2*_hc12[1]*_hc8[0]*_t122*_t125*_t149*_t3*na + (0.1e1 / 0.2e1)*_hc12[1]*_t112*_t149*_t2*_t202*_t3 + 0.16e2*M_PI*_hc8[0]*_t38*_t48*na + (0.8e1 / 0.3e1)*_hc8[1]*_t122*_t149*_t3*_t38*na - _t1*_t510 - _t202*_t295 - _t308*_t511 - _t336 + 0.6e1*_t506*_t62);
  const double _t522 = _t23*_t521;
  const double _t523 = -_t522;
  const double _t524 = -0.8e1 / 0.3e1*_t437;
  const double d2F_dna2 = 0.2e1*_hc5[1]*_t93 + _t1*(_t294 + _t415 + _t418 + _t431) - 0.2e1*_t191 - _t433;
  const double d2F_dna_dnb = _t1*((0.16e2 / 0.9e1)*_hc0[0]*_hc12[1]*_t122*_t21*_t3*_t5*_t76*_t82 + 0.2e1*_hc5[1]*_t100*_t9 + (0.2e1 / 0.9e1)*_hc5[2]*_t122*_t3*_t5 + (0.2e1 / 0.9e1)*_t21*_t219*_t220*_t255*_t310*_t76*_t82 - 0.4e1 / 0.3e1*_t417 - _t427 - _t435 + _t436*_t93 - 0.4e1 / 0.3e1*_t437 - _t488) - _t192 - _t209 - _t433;
  const double d2F_dnb2 = 0.2e1*_hc5[1]*_t194 + _t1*(_t431 + _t506 + _t523 + _t524) - 0.2e1*_t208 - _t433;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t525 = (0.14e2 / 0.27e2)*_t104;
  const double _t528 = _t215*_t9;
  const double _t529 = 0.6e1*_t528;
  const double _t530 = -_t481 + _t529;
  const double _t531 = -_t530;
  const double _t532 = _t231 - _t48;
  const double _t533 = -_t532;
  const double _t534 = 0.2e1*_t233;
  const double _t537 = 0.2e1*_t236;
  const double _t540 = (0.1e1 / (na * na * na * na));
  const double _t541 = (0.1e1 / M_PI);
  const double _t542 = (0.1e1 / 0.36e2)*_t541;
  const double _t543 = _t540*_t542;
  const double _t545 = xc_powr(na, -10, 3);
  const double _t546 = (0.14e2 / 0.27e2)*_t6;
  const double _t547 = _t545*_t546;
  const double _t549 = xc_powr(na, -11, 3);
  const double _t550 = (0.1e1 / 0.9e1)*_t221;
  const double _t551 = _t549*_t550;
  const double _t558 = _t7*_t93;
  const double _t560 = _t53*_t93;
  const double _t562 = (0.1e1 / 0.12e2)*_t221;
  const double _t563 = _t242*_t562;
  const double _t565 = (0.2e1 / 0.3e1)*_t6;
  const double _t566 = _t246*_t565;
  const double _t567 = xc_powi(_t1, -5);
  const double _t568 = 0.96e2*_t567;
  const double _t570 = xc_powi(_t1, -6);
  const double _t571 = _t570*nb;
  const double _t575 = xc_powr(_t1, -16, 3);
  const double _t576 = _t575*_t6;
  const double _t577 = (0.524e3 / 0.27e2)*_t576;
  const double _t579 = xc_powr(_t1, -17, 3);
  const double _t580 = _t221*_t579;
  const double _t587 = (0.160e3 / 0.9e1)*_t104;
  const double _t594 = (0.2e1 / 0.5e1)*_t79;
  const double _t596 = (0.3e1 / 0.5e1)*_t2;
  const double _t601 = (0.1e1 / _t31);
  const double _t602 = _t30*_t601;
  const double _t607 = 0.64e2*_t26;
  const double _t613 = _t26*_t567;
  const double _t614 = _t602*_t613;
  const double _t617 = _t218*_t26;
  const double _t621 = _t226*_t26;
  const double _t623 = _t259*_t617;
  const double _t644 = (_t93 * _t93 * _t93);
  const double _t647 = (0.2e1 / 0.5e1)*_t2;
  const double _t648 = _t67*_t70;
  const double _t650 = 0.4e1*_t231;
  const double _t651 = -_t49 + _t650;
  const double _t653 = (0.8e1 / 0.135e3)*_t122;
  const double _t683 = 0.8e1*_t266;
  const double _t699 = 0.48e2*_t215;
  const double _t702 = (0.112e3 / 0.9e1)*_t105;
  const double _t704 = _t567*nb;
  const double _t708 = _t218*nb;
  const double _t709 = _t315*_t708;
  const double _t711 = _t226*nb;
  const double _t714 = 0.12e2*_t100;
  const double _t719 = (0.10e2 / 0.3e1)*nb;
  const double _t727 = 0.12e2*_t215;
  const double _t730 = _t221*_t266;
  const double _t733 = _t218*_t315;
  const double _t738 = _t525*_t6;
  const double _t741 = _t180*_t6;
  const double _t760 = 0.3e1*_t371;
  const double _t761 = _t16*_t166;
  const double _t769 = (0.1e1 / 0.3e1)*_t166;
  const double _t775 = 0.3e1*_t531;
  const double _t784 = -_t48*_t9;
  const double _t785 = _t10 + _t784;
  const double _t806 = _t567*_t602;
  const double _t834 = _t7*_t79;
  const double _t835 = (0.2e1 / 0.3e1)*_t122;
  const double _t836 = (0.16e2 / 0.3e1)*_t429;
  const double _t838 = -0.2e1*_t100 + _t529;
  const double _t839 = -_t838;
  const double _t844 = (0.2e1 / 0.9e1)*nb;
  const double _t846 = (0.64e2 / 0.9e1)*_t227;
  const double _t864 = (0.2e1 / 0.15e2)*_t79;
  const double _t866 = (0.4e1 / 0.15e2)*_t79;
  const double _t886 = _t784 + _t90;
  const double _t887 = _t298*_t886;
  const double _t904 = (0.40e2 / 0.9e1)*na;
  const double _t918 = 0.4e1*na;
  const double _t920 = (0.10e2 / 0.9e1)*na;
  const double _t921 = (0.1e1 / 0.9e1)*nb;
  const double _t933 = xc_powr(_t1, -25, 6);
  const double _t936 = _t194*_t233;
  const double _t938 = _t9*_t93;
  const double _t975 = 0.12e2*_t231;
  const double _t1008 = _t231 + _t48;
  const double _t1009 = -_t1008;
  const double _t1010 = 0.2e1*_t100;
  const double _t1014 = (0.2e1 / 0.9e1)*na;
  const double _t1015 = _t196*_t438;
  const double _t1016 = _t1015*_t250;
  const double _t1018 = _t489*_t53;
  const double _t1020 = _t194*_t439;
  const double _t1035 = _t507*_t785;
  const double _t1037 = _t194*_t9;
  const double _t1044 = (0.10e2 / 0.9e1)*nb;
  const double _t1057 = 0.18e2*_t528;
  const double _t1075 = _t481 + _t529;
  const double _t1076 = -_t1075;
  const double _t1079 = 0.2e1*_t489;
  const double _t1082 = (0.1e1 / (nb * nb * nb * nb));
  const double _t1083 = _t1082*_t542;
  const double _t1085 = xc_powr(nb, -10, 3);
  const double _t1086 = _t1085*_t546;
  const double _t1088 = xc_powr(nb, -11, 3);
  const double _t1089 = _t1088*_t550;
  const double _t1102 = (_t194 * _t194 * _t194);
  const double _t1103 = _t49 + _t650;
  const double _t1104 = _t1103*_t194;
  const double _t1112 = _t194*_t489;
  const double _t1118 = 0.3e1*_t1076;
  const double _t526 = _t525*_t78;
  const double _t527 = (0.9e1 / 0.20e2)*_t33;
  const double _t535 = _hc1[0]*_t237;
  const double _t536 = _hc2[0]*_t239;
  const double _t538 = 0.72e2*_hc3[0]*_t215;
  const double _t539 = _hc1[3]*_t54;
  const double _t544 = _t539*_t543;
  const double _t548 = _t245*_t547;
  const double _t552 = _t241*_t551;
  const double _t553 = (0.1e1 / 0.3e1)*_hc3[2]*_t222;
  const double _t554 = (0.32e2 / 0.3e1)*_hc3[1]*_t227;
  const double _t555 = _t249*_t7;
  const double _t556 = _t233*_t555;
  const double _t557 = _t237*_t97;
  const double _t559 = _t557*_t558;
  const double _t561 = _hc1[2]*_t560;
  const double _t564 = _hc1[1]*_t560;
  const double _t569 = _t102*_t568;
  const double _t572 = _hc3[3]*_t541;
  const double _t573 = (0.1e1 / 0.9e1)*_t572;
  const double _t574 = _t571*_t573;
  const double _t578 = _t107*_t577;
  const double _t581 = _hc3[2]*_t580;
  const double _t582 = -_t345*_t581 - _t569*nb - _t574*na - _t578*nb;
  const double _t583 = _t238*_t532 + _t240*_t533 + _t530*_t95 + _t531*_t94 + _t534*_t535 + _t536*_t537 + _t538*nb - _t544 - _t548 - _t552 + _t553*nb + _t554*nb - _t556 - _t559 + _t561*_t563 + _t564*_t566 + _t582;
  const double _t584 = _t583*_t59;
  const double _t585 = _t100*_t263;
  const double _t586 = 0.64e2*_t585;
  const double _t588 = _t38*nb;
  const double _t589 = _t181*_t588;
  const double _t590 = (0.16e2 / 0.9e1)*_hc4[2];
  const double _t591 = _t268*_t590;
  const double _t603 = _t58*_t602;
  const double _t609 = _t26*_t38;
  const double _t610 = _hc4[3]*_t602;
  const double _t611 = _t567*_t610;
  const double _t612 = (0.8e1 / 0.27e2)*_t611;
  const double _t616 = (0.112e3 / 0.27e2)*_hc4[2];
  const double _t618 = _t260*_t617;
  const double _t620 = _hc4[0]*_t614;
  const double _t626 = -_t526;
  const double _t627 = _t292*_t6;
  const double _t628 = _hc5[1]*_t531;
  const double _t629 = _hc5[4]*_t356;
  const double _t630 = -_hc5[8]*_t164;
  const double _t631 = _hc5[7]*_t93 + _t630;
  const double _t632 = -_hc5[7]*_t164;
  const double _t633 = _hc5[6]*_t93 + _t632;
  const double _t634 = _hc5[3]*_t233 - _t164*_t631 + _t629 + _t633*_t93;
  const double _t635 = _t634*_t93;
  const double _t636 = _hc5[5]*_t356;
  const double _t637 = -_hc5[9]*_t164;
  const double _t638 = _hc5[8]*_t93 + _t637;
  const double _t639 = _hc5[4]*_t233 - _t164*_t638 + _t631*_t93 + _t636;
  const double _t640 = _t164*_t639;
  const double _t641 = _t289*_t534 + _t628 + _t635 - _t640;
  const double _t642 = _t180*_t627 + _t626 + _t641;
  const double _t643 = (0.9e1 / 0.16e2)*_t40;
  const double _t645 = _hc7[6]*_t297;
  const double _t646 = _t2*_t451;
  const double _t649 = _t299*_t648;
  const double _t652 = _t136*_t568;
  const double _t654 = _hc6[3]*_t541;
  const double _t655 = (0.1e1 / 0.9e1)*_t571*_t654;
  const double _t656 = _hc6[2]*_t580;
  const double _t657 = _t140*_t577;
  const double _t658 = _t137*_t653 + _t345*_t656 + _t652*nb + _t655*na + _t657*nb;
  const double _t659 = 0.2e1*_hc1[0]*_t233*_t237 + _hc1[0]*_t53*_t531 + _hc1[0]*_t532*_t93 + (0.2e1 / 0.3e1)*_hc1[1]*_t246*_t3*_t5*_t53*_t93 + (0.1e1 / 0.12e2)*_hc1[2]*_t219*_t220*_t242*_t53*_t93 + 0.2e1*_hc2[0]*_t236*_t239 + _hc2[0]*_t530*_t55 + _hc2[0]*_t533*_t92 + 0.72e2*_hc6[0]*_t215*nb + (0.32e2 / 0.3e1)*_hc6[1]*_t226*_t3*_t5*nb + (0.1e1 / 0.3e1)*_hc6[2]*_t218*_t219*_t220*nb + (0.2e1 / 0.15e2)*_hc7[1]*_t67*_t70*_t79*_t93 - _t134*_t531 - _t233*_t455 - _t233*_t646 - _t455*_t651 - _t544 - _t548 - _t552 - _t556 - _t559 - _t644*_t645 - _t647*_t649 - _t658;
  const double _t660 = _t659*_t74;
  const double _t661 = _t100*_t311;
  const double _t662 = 0.48e2*_t661;
  const double _t665 = 0.12e2*_t294;
  const double _t666 = _t131*_t20;
  const double _t668 = _t131*_t429;
  const double _t670 = (0.40e2 / 0.3e1)*_t324;
  const double _t671 = (0.7e1 / 0.8e1)*_t316;
  const double _t674 = _t267*_t319;
  const double _t675 = (0.2e1 / 0.3e1)*_t674;
  const double _t677 = _hc8[0]*nb;
  const double _t678 = _t104*_t677;
  const double _t680 = 0.20e2*_t62;
  const double _t681 = _t326*_t680;
  const double _t690 = _hc8[3]*_t567;
  const double _t691 = _t690*nb;
  const double _t692 = _t38*_t691;
  const double _t694 = _hc8[2]*_t567;
  const double _t700 = _t26*_t311;
  const double _t705 = _t148*_t704;
  const double _t706 = _t218*_t319;
  const double _t712 = _t148*_t711;
  const double _t715 = _t162*_t714;
  const double _t720 = (0.1e1 / 0.6e1)*_t341;
  const double _t725 = (0.40e2 / 0.3e1)*_hc5[0];
  const double _t726 = _t29*_t691;
  const double _t728 = _t162*na;
  const double _t739 = _hc9[2]*_t738;
  const double _t740 = -_t739;
  const double _t742 = _hc9[5]*_t356;
  const double _t743 = -_hc9[9]*_t164;
  const double _t744 = _hc9[8]*_t93 + _t743;
  const double _t745 = -_hc9[8]*_t164;
  const double _t746 = _hc9[7]*_t93 + _t745;
  const double _t747 = _hc9[4]*_t233 - _t164*_t744 + _t742 + _t746*_t93;
  const double _t748 = _hc9[4]*_t356;
  const double _t749 = -_hc9[7]*_t164;
  const double _t750 = _hc9[6]*_t93 + _t749;
  const double _t751 = _hc9[3]*_t233 - _t164*_t746 + _t748 + _t750*_t93;
  const double _t752 = _t17*_t469;
  const double _t753 = (0.91e2 / 0.432e3)*_t752;
  const double _t754 = _t362*_t365;
  const double _t755 = _hc10[6]*_t644;
  const double _t756 = (0.1e1 / ((_hc10[0]) * (_hc10[0]) * (_hc10[0]) * (_hc10[0])));
  const double _t757 = ((_hc10[1]) * (_hc10[1]) * (_hc10[1]));
  const double _t758 = _t644*_t757;
  const double _t759 = _t756*_t758;
  const double _t762 = _t370*_t761;
  const double _t763 = _t298*_t762;
  const double _t764 = _t468*_t93;
  const double _t765 = 0.3e1*_hc10[1]*_hc10[3]*_t12*_t13*_t15*_t18*_t369*_t644*p->cam_omega + (0.1e1 / 0.4e1)*_hc10[1]*_t12*_t13*_t15*_t166*_t170*_t233*p->cam_omega + (0.1e1 / 0.4e1)*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t298*p->cam_omega + _t12*_t13*_t15*_t18*_t233*_t368*_t369*_t93*p->cam_omega + _t12*_t13*_t15*_t18*_t368*_t369*_t651*_t93*p->cam_omega - _t173*_t531 - _t233*_t764 - _t375*_t755 - _t651*_t764 - _t753 - 0.7e1 / 0.24e2*_t754 - _t759*_t760 - 0.1e1 / 0.2e1*_t763;
  const double _t766 = (_t174 * _t174 * _t174);
  const double _t768 = _t172*_t18;
  const double _t770 = (0.7e1 / 0.36e2)*_t366;
  const double _t771 = _t171*_t18;
  const double _t772 = _t374*_t771;
  const double _t773 = 0.2e1*_t373 + _t770 - _t772;
  const double _t774 = -_t233*_t768 + _t362*_t769 + _t773;
  const double _t777 = _t169*_t380;
  const double _t779 = 0.9e1*_t177;
  const double _t780 = _t377*_t779;
  const double _t782 = _t233*_t779;
  const double _t786 = _t779*_t785;
  const double _t787 = 0.9e1*_t169;
  const double _t788 = -_t168 - _t173*_t785;
  const double _t791 = 0.18e2*_hc10[0];
  const double _t792 = _hc10[1]*_t791;
  const double _t794 = _t298*_t386;
  const double _t795 = 0.18e2*_t794;
  const double _t796 = _hc4[0]*_t34;
  const double _t797 = _t211*_t796;
  const double _t798 = _t28*_t29;
  const double _t799 = _t400*_t798;
  const double _t800 = _t395*_t403;
  const double _t805 = _t215*_t796;
  const double _t807 = _t218*_t402;
  const double _t811 = _t181*_t798;
  const double _t819 = -0.4e1 / 0.9e1*_t122*_t292*_t3*_t5;
  const double _t828 = xc_powi(_t22, -7);
  const double _t840 = _hc3[0]*nb;
  const double _t841 = _t231*_t240;
  const double _t842 = _hc2[0]*_t236;
  const double _t843 = _t232*_t842;
  const double _t845 = _hc3[1]*nb;
  const double _t847 = _t439*_t97;
  const double _t848 = _t251*_t847;
  const double _t849 = _t239*_t444;
  const double _t850 = _hc2[1]*_t92;
  const double _t851 = _t197*_t850;
  const double _t852 = _t236*_t851;
  const double _t853 = _hc1[2]*_t441;
  const double _t854 = _hc1[1]*_t441;
  const double _t855 = _t249*_t565;
  const double _t856 = _t231*_t855;
  const double _t857 = -_t212 - _t214 + _t582;
  const double _t858 = _t217 + _t223*_t844 + _t225 + _t229 + _t231*_t238 + _t232*_t535 + _t233*_t490 + _t239*_t492 + _t244*_t853 + _t248*_t854 + _t699*_t840 + _t838*_t95 + _t839*_t94 - _t841 - _t843 + _t845*_t846 - _t848 - _t849 - _t852 - _t856 + _t857;
  const double _t859 = (0.128e3 / 0.3e1)*_t585;
  const double _t860 = _t104*_t589;
  const double _t861 = _t272*na;
  const double _t862 = (0.32e2 / 0.27e2)*_t269;
  const double _t868 = (0.320e3 / 0.9e1)*_t485;
  const double _t873 = (0.32e2 / 0.9e1)*_t38;
  const double _t875 = _hc5[1]*_t839;
  const double _t876 = _t233*_t436;
  const double _t877 = _hc5[7]*_t194 + _t630;
  const double _t878 = _hc5[8]*_t194 + _t637;
  const double _t879 = -_t164*_t878 + _t636;
  const double _t880 = _hc5[4]*_t232 + _t877*_t93 + _t879;
  const double _t881 = _hc5[6]*_t194 + _t632;
  const double _t882 = -_t164*_t877 + _t629;
  const double _t883 = _hc5[3]*_t232 + _t881*_t93 + _t882;
  const double _t884 = _t883*_t93;
  const double _t885 = -_t164*_t880 + _t232*_t289 + _t292*_t356 + _t356*_t434 + _t626 + _t875 + _t876 + _t884;
  const double _t888 = _t138*_t301;
  const double _t889 = _t104*_t301;
  const double _t890 = (0.8e1 / 0.15e2)*_t889;
  const double _t891 = _t194*_t454;
  const double _t892 = _hc7[3]*_t648;
  const double _t893 = _t122*_t892;
  const double _t894 = (0.4e1 / 0.5e1)*_t893;
  const double _t895 = _t894*_t93;
  const double _t896 = _t892*_t93;
  const double _t897 = _t194*_t896;
  const double _t898 = _t296 + _t300 + _t303*_t897 + _t658;
  const double _t899 = 0.2e1*_hc1[0]*_t100*_t237*_t9 + _hc1[0]*_t100*_t9*_t93 + _hc1[0]*_t233*_t439 + _hc1[0]*_t53*_t839 + (0.2e1 / 0.9e1)*_hc1[1]*_t194*_t246*_t3*_t5*_t53 + (0.1e1 / 0.36e2)*_hc1[2]*_t194*_t219*_t220*_t242*_t53 + _hc2[0]*_t239*_t438 + _hc2[0]*_t55*_t838 + 0.24e2*_hc6[0]*_t215*na + 0.48e2*_hc6[0]*_t215*nb + (0.32e2 / 0.9e1)*_hc6[1]*_t226*_t3*_t5*na + (0.64e2 / 0.9e1)*_hc6[1]*_t226*_t3*_t5*nb + (0.1e1 / 0.9e1)*_hc6[2]*_t218*_t219*_t220*na + (0.2e1 / 0.9e1)*_hc6[2]*_t218*_t219*_t220*nb + (0.2e1 / 0.45e2)*_hc7[1]*_t194*_t67*_t70*_t79 + (0.4e1 / 0.45e2)*_hc7[1]*_t67*_t70*_t79*_t93 - _t134*_t839 - _t138*_t649 - _t233*_t888 - _t233*_t891 - _t645*_t887 - _t841 - _t843 - _t848 - _t849 - _t852 - _t856 - _t890*_t9 - _t895*_t9 - _t898;
  const double _t900 = 0.32e2*_t661;
  const double _t902 = _t20*_t201;
  const double _t903 = (0.80e2 / 0.9e1)*_t324;
  const double _t905 = (0.7e1 / 0.12e2)*_t316;
  const double _t907 = (0.4e1 / 0.9e1)*_t674;
  const double _t910 = _t201*_t836;
  const double _t913 = (0.8e1 / 0.3e1)*_t38;
  const double _t915 = 0.8e1*_t450;
  const double _t916 = _hc8[0]*_t122;
  const double _t919 = (0.20e2 / 0.9e1)*_t344;
  const double _t926 = _hc9[7]*_t194 + _t745;
  const double _t927 = _hc9[8]*_t194 + _t743;
  const double _t928 = -_t164*_t927 + _t742;
  const double _t929 = _hc9[4]*_t232 + _t926*_t93 + _t928;
  const double _t930 = _hc9[6]*_t194 + _t749;
  const double _t931 = -_t164*_t926 + _t748;
  const double _t932 = _hc9[3]*_t232 + _t93*_t930 + _t931;
  const double _t934 = (0.7e1 / 0.36e2)*_t754;
  const double _t935 = _t365*_t463;
  const double _t937 = _hc10[6]*_t887;
  const double _t939 = _hc10[3]*_t171;
  const double _t940 = _t469*_t939;
  const double _t941 = 0.2e1*_t940;
  const double _t942 = _t757*_t887;
  const double _t943 = _t756*_t760;
  const double _t944 = _t467*_t762;
  const double _t945 = -0.1e1 / 0.6e1*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t194*_t93*p->cam_omega + _t753 + (0.1e1 / 0.3e1)*_t944;
  const double _t946 = 0.3e1*_hc10[1]*_hc10[3]*_t12*_t13*_t15*_t18*_t298*_t369*_t886*p->cam_omega + (0.1e1 / 0.12e2)*_hc10[1]*_t12*_t13*_t15*_t166*_t170*_t233*p->cam_omega + (0.1e1 / 0.3e1)*_hc10[1]*_t12*_t13*_t15*_t170*_t9*_t933*p->cam_omega + (0.1e1 / 0.12e2)*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t298*p->cam_omega + _t12*_t13*_t15*_t18*_t194*_t233*_t368*_t369*p->cam_omega + 0.4e1*_t12*_t13*_t15*_t368*_t369*_t469*_t9*_t93*p->cam_omega - _t173*_t839 - _t375*_t937 - _t468*_t936 - 0.1e1 / 0.6e1*_t763 - _t934 - 0.7e1 / 0.72e2*_t935 - _t938*_t941 - _t942*_t943 - _t945;
  const double _t947 = _hc10[3]*_t771;
  const double _t948 = _t364 + 0.2e1*_t466 - _t467*_t947 - 0.2e1*_t471 + _t512 + _t770;
  const double _t950 = -_t168 - _t173*_t886;
  const double _t956 = _t178*_t886;
  const double _t962 = 0.6e1*_t950;
  const double _t965 = 0.6e1*_t177;
  const double _t966 = _t174*_t205;
  const double _t969 = _hc10[3]*_t169;
  const double _t970 = _t390*_t969;
  const double _t972 = _t194*_t386;
  const double _t981 = _t100*_t796;
  const double _t982 = (0.32e2 / 0.3e1)*_t981;
  const double _t983 = (0.80e2 / 0.27e2)*_t400;
  const double _t984 = _t403*_t484;
  const double _t1006 = _t434*_t6;
  const double _t1011 = _t1010*_t94;
  const double _t1012 = _t529*_t94;
  const double _t1013 = _t492*_t650;
  const double _t1017 = _t1016*_t850;
  const double _t1019 = _t1018*_t98;
  const double _t1021 = _t1020*_t98;
  const double _t1022 = _hc2[2]*_t55;
  const double _t1023 = _t1022*_t495;
  const double _t1024 = _t443*_t497;
  const double _t1025 = _t498*_t565;
  const double _t1026 = _t1008*_t238 + _t1009*_t240 + _t1010*_t95 - _t1011 - _t1012 - _t1013 + _t1014*_t223 - _t1017 - _t1019 + _t102*_t699 - _t1021 + _t1023*_t92 + _t1024*_t92 + _t1025*_t231 + _t107*_t846 + _t216*_t840 + _t223*_t921 + _t228*_t845 + _t490*_t650 + _t529*_t95 + _t857;
  const double _t1029 = _hc5[3]*_t489 + _t194*_t881 + _t882;
  const double _t1030 = _hc5[4]*_t489 + _t194*_t877 + _t879;
  const double _t1031 = _t1030*_t164;
  const double _t1032 = _t1031 - 0.4e1 / 0.9e1*_t122*_t3*_t434*_t5 + _t526;
  const double _t1033 = _hc5[1]*_t1010 + _hc5[1]*_t529 - 0.4e1*_t100*_t436*_t9 - _t1029*_t93 + _t1032;
  const double _t1034 = -_t1033;
  const double _t1036 = _t508*_t648;
  const double _t1038 = 0.4e1*_hc1[0]*_t100*_t439*_t9 + _hc1[0]*_t1008*_t93 + 0.2e1*_hc2[0]*_t100*_t55 + _hc2[0]*_t1009*_t92 + 0.6e1*_hc2[0]*_t215*_t55*_t9 + (0.2e1 / 0.3e1)*_hc2[1]*_t100*_t196*_t3*_t5*_t55*_t9 + (0.2e1 / 0.9e1)*_hc2[1]*_t3*_t496*_t5*_t55*_t92 + (0.1e1 / 0.36e2)*_hc2[2]*_t219*_t220*_t494*_t55*_t92 + 0.48e2*_hc6[0]*_t215*na + 0.24e2*_hc6[0]*_t215*nb + (0.64e2 / 0.9e1)*_hc6[1]*_t226*_t3*_t5*na + (0.32e2 / 0.9e1)*_hc6[1]*_t226*_t3*_t5*nb + (0.2e1 / 0.9e1)*_hc6[2]*_t218*_t219*_t220*na + (0.1e1 / 0.9e1)*_hc6[2]*_t218*_t219*_t220*nb + (0.2e1 / 0.3e1)*_hc7[1]*_t104*_t67*_t70*_t9 + (0.2e1 / 0.5e1)*_hc7[1]*_t122*_t67*_t70 + (0.4e1 / 0.45e2)*_hc7[1]*_t194*_t67*_t70*_t79 + (0.2e1 / 0.45e2)*_hc7[1]*_t67*_t70*_t79*_t93 - _t1011 - _t1012 - _t1013 - _t1017 - _t1019 - _t1021 - _t1035*_t645 - _t1036*_t138 - _t1037*_t894 - _t455*_t489 - _t489*_t888 - _t898;
  const double _t1041 = _t131*_t836;
  const double _t1042 = _t201*_t429;
  const double _t1046 = _hc9[4]*_t489 + _t194*_t926 + _t928;
  const double _t1047 = _t1046*_t164;
  const double _t1048 = _hc9[3]*_t489 + _t194*_t930 + _t931;
  const double _t1049 = _t507*_t762;
  const double _t1050 = (0.7e1 / 0.36e2)*_t935;
  const double _t1051 = _hc10[6]*_t1035;
  const double _t1052 = _t1035*_t757;
  const double _t1053 = 0.3e1*_hc10[1]*_hc10[3]*_t12*_t13*_t15*_t18*_t369*_t507*_t785*p->cam_omega + (0.1e1 / 0.12e2)*_hc10[1]*_t12*_t13*_t15*_t166*_t170*_t489*p->cam_omega + _hc10[1]*_t12*_t13*_t15*_t170*_t469*p->cam_omega + (0.10e2 / 0.3e1)*_hc10[1]*_t12*_t13*_t15*_t170*_t9*_t933*p->cam_omega + (0.1e1 / 0.12e2)*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t507*p->cam_omega - _t1037*_t941 - 0.1e1 / 0.6e1*_t1049 - _t1050 - _t1051*_t375 - _t1052*_t943 + _t12*_t13*_t15*_t18*_t368*_t369*_t489*_t93*p->cam_omega + 0.4e1*_t12*_t13*_t15*_t194*_t368*_t369*_t469*_t9*p->cam_omega - _t489*_t764 - 0.7e1 / 0.72e2*_t754 - _t945;
  const double _t1060 = _t178*_t785;
  const double _t1061 = _t169*_t518;
  const double _t1064 = _t386*_t507;
  const double _t1065 = _t194*_t965;
  const double _t1069 = _t231*_t972;
  const double _t1077 = _hc1[0]*_t1008;
  const double _t1078 = _hc2[0]*_t1009;
  const double _t1080 = 0.2e1*_t492;
  const double _t1081 = _hc2[3]*_t56;
  const double _t1084 = _t1081*_t1083;
  const double _t1087 = _t1086*_t195;
  const double _t1090 = _t1089*_t493;
  const double _t1091 = _t491*_t498*_t7;
  const double _t1092 = _hc2[1]*_t1015;
  const double _t1093 = _t1092*_t193*_t7;
  const double _t1094 = _t1022*_t193;
  const double _t1095 = _t193*_t443;
  const double _t1096 = _t1075*_t95 + _t1076*_t94 + _t1077*_t194 + _t1078*_t193 + _t1079*_t490 + _t1080*_t491 - _t1084 - _t1087 - _t1090 - _t1091 - _t1093 + _t1094*_t494*_t562 + _t1095*_t496*_t565 + _t538*na + _t553*na + _t554*na + _t582;
  const double _t1097 = _t1096*_t59;
  const double _t1098 = _t271*_t587;
  const double _t1099 = _hc5[1]*_t1076;
  const double _t1100 = _t1029*_t194;
  const double _t1101 = -_t1031 + _t1079*_t436 + _t1099 + _t1100 + _t434*_t741 + _t626;
  const double _t1105 = _hc1[0]*_t1008*_t194 + _hc1[0]*_t1076*_t53 + 0.2e1*_hc1[0]*_t439*_t489 + _hc2[0]*_t1009*_t193 + _hc2[0]*_t1075*_t55 + 0.2e1*_hc2[0]*_t438*_t491 + (0.2e1 / 0.3e1)*_hc2[1]*_t193*_t3*_t496*_t5*_t55 + (0.1e1 / 0.12e2)*_hc2[2]*_t193*_t219*_t220*_t494*_t55 + 0.72e2*_hc6[0]*_t215*na + (0.32e2 / 0.3e1)*_hc6[1]*_t226*_t3*_t5*na + (0.1e1 / 0.3e1)*_hc6[2]*_t218*_t219*_t220*na + (0.2e1 / 0.15e2)*_hc7[1]*_t194*_t67*_t70*_t79 - _t1036*_t647 - _t1076*_t134 - _t1084 - _t1087 - _t1090 - _t1091 - _t1093 - _t1102*_t645 - _t1104*_t454 - _t489*_t646 - _t489*_t891 - _t658;
  const double _t1106 = _t1105*_t74;
  const double _t1107 = 0.12e2*_t506;
  const double _t1108 = (0.10e2 / 0.3e1)*_t344;
  const double _t1109 = _hc10[6]*_t1102;
  const double _t1110 = _t1102*_t757;
  const double _t1111 = _t1110*_t756;
  const double _t1113 = 0.3e1*_hc10[1]*_hc10[3]*_t1102*_t12*_t13*_t15*_t18*_t369*p->cam_omega + (0.1e1 / 0.4e1)*_hc10[1]*_t12*_t13*_t15*_t166*_t170*_t489*p->cam_omega + (0.1e1 / 0.4e1)*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t507*p->cam_omega - 0.1e1 / 0.2e1*_t1049 - _t1076*_t173 + _t1103*_t12*_t13*_t15*_t18*_t194*_t368*_t369*p->cam_omega - _t1104*_t468 - _t1109*_t375 - _t1111*_t760 - _t1112*_t468 + _t12*_t13*_t15*_t18*_t194*_t368*_t369*_t489*p->cam_omega - _t753 - 0.7e1 / 0.24e2*_t935;
  const double _t1114 = (_t205 * _t205 * _t205);
  const double _t1115 = _t514*_t771;
  const double _t1116 = -_t1115 + 0.2e1*_t513 + _t770;
  const double _t1117 = _t1116 + _t463*_t769 - _t489*_t768;
  const double _t1120 = _t194*_t779;
  const double _t1121 = _t489*_t779;
  const double _t1122 = _t779*_t886;
  const double _t1123 = _t514*_t787;
  const double _t1124 = 0.18e2*_t1064;
  const double _t592 = _t110*_t261;
  const double _t593 = _t110*_t118;
  const double _t595 = _t118*_t253;
  const double _t597 = (0.320e3 / 0.3e1)*_t283;
  const double _t598 = (0.160e3 / 0.3e1)*_t279;
  const double _t599 = (0.64e2 / 0.3e1)*_t126;
  const double _t600 = _t274*_t599;
  const double _t604 = ((_hc12[1]) * (_hc12[1]) * (_hc12[1]));
  const double _t605 = _t125*_t604;
  const double _t606 = _t100*_t605;
  const double _t608 = (0.8e1 / 0.45e2)*_t185;
  const double _t615 = _hc4[1]*_t277*_t602;
  const double _t619 = _t146*_t604;
  const double _t622 = _hc4[1]*_t126;
  const double _t624 = _hc4[0]*_t282;
  const double _t625 = (0.1120e4 / 0.9e1)*_hc4[0]*_t277*_t623 + (0.16e2 / 0.3e1)*_hc4[2]*_t126*_t614 + _t215*_t263*_t607 + _t260*_t262*_t419 + (0.1888e4 / 0.81e2)*_t271*_t621 - _t58*_t608 + (0.7e1 / 0.5e1)*_t603*_t606 + _t609*_t612 + (0.80e2 / 0.3e1)*_t613*_t615 + _t616*_t618 + (0.320e3 / 0.9e1)*_t619*_t620 + (0.3776e4 / 0.27e2)*_t621*_t624 + (0.448e3 / 0.9e1)*_t622*_t623;
  const double _t663 = _t151*_t79;
  const double _t664 = (0.1e1 / 0.2e1)*_t663;
  const double _t667 = _t420*_t666;
  const double _t669 = _t147*_t668;
  const double _t672 = _t142*_t255;
  const double _t673 = _t256*_t672;
  const double _t676 = (0.3e1 / 0.4e1)*_t152;
  const double _t679 = _t157*_t678;
  const double _t682 = _t255*_t677;
  const double _t684 = _t315*_t327;
  const double _t685 = _t683*_t684;
  const double _t686 = _t605*_t73;
  const double _t687 = _t541*_t604;
  const double _t688 = _t215*_t687;
  const double _t689 = _hc0[0]*_t688;
  const double _t693 = _hc5[0]*_t20*_t255;
  const double _t695 = _t126*_t694*na;
  const double _t696 = _hc8[1]*_t255;
  const double _t697 = _t567*_t696;
  const double _t698 = _t26*_t697;
  const double _t701 = _hc5[0]*_t147;
  const double _t703 = _t151*_t73;
  const double _t707 = _t218*_t684;
  const double _t710 = _t148*_t277;
  const double _t713 = (0.7e1 / 0.4e1)*_t100*_t686 - _t144*_t689 + (0.944e3 / 0.9e1)*_t157*_t712 - _t221*_t683*_t693 + (0.56e2 / 0.3e1)*_t26*_t707 - _t285*_t703 + _t317*_t419*_t73 + (0.472e3 / 0.27e2)*_t323*_t621 + _t338*_t695 + (0.14e2 / 0.9e1)*_t609*_t706 + (0.80e2 / 0.3e1)*_t619*_t705 + _t680*_t698 + (0.2e1 / 0.9e1)*_t692*na + _t699*_t700 - _t701*_t702 + (0.140e3 / 0.3e1)*_t709*_t710;
  const double _t716 = _t420*_t62;
  const double _t717 = _t131*_t716;
  const double _t718 = 0.16e2*_t126;
  const double _t721 = _t151*_t678;
  const double _t722 = _t349*_t682;
  const double _t723 = (0.8e1 / 0.3e1)*_t347;
  const double _t724 = _t146*_t688;
  const double _t729 = _hc5[0]*_t126;
  const double _t731 = _t277*_t730;
  const double _t732 = _t113*_t694;
  const double _t734 = _hc8[1]*_t113;
  const double _t735 = _t733*_t734;
  const double _t736 = _t316*_t350;
  const double _t737 = (0.944e3 / 0.27e2)*_t151*_t712 + (0.7e1 / 0.18e2)*_t183*_t706 + (0.4e1 / 0.3e1)*_t26*_t732 + (0.56e2 / 0.9e1)*_t26*_t735 + (0.118e3 / 0.27e2)*_t343*_t621 + (0.28e2 / 0.3e1)*_t38*_t698 + (0.56e2 / 0.3e1)*_t605*_t705 - _t702*_t729 + (0.196e3 / 0.9e1)*_t708*_t736 - _t724*_t725 - _t725*_t731 + (0.1e1 / 0.18e2)*_t726*na + _t727*_t728*nb;
  const double _t767 = _hc11[3]*_t24;
  const double _t776 = _hc11[0]*_t382;
  const double _t778 = _hc11[1]*_t93;
  const double _t781 = _hc11[1]*_t174;
  const double _t783 = _hc11[2]*_t378;
  const double _t789 = _hc11[1]*_t788;
  const double _t790 = _t374*_t789;
  const double _t793 = _t383*_t792;
  const double _t801 = (0.320e3 / 0.9e1)*_t405;
  const double _t802 = (0.224e3 / 0.9e1)*_t408;
  const double _t803 = _t113*_t396;
  const double _t804 = _t274*_t803;
  const double _t808 = _t255*_t609;
  const double _t809 = _t28*_t808;
  const double _t810 = _t28*_t605;
  const double _t812 = _hc4[1]*_t409;
  const double _t813 = _t255*_t28;
  const double _t814 = _hc4[0]*_t813;
  const double _t815 = _hc4[0]*_t404;
  const double _t816 = (0.112e3 / 0.9e1)*_hc4[1]*_t806*_t809 + _hc4[2]*_t121*_t409*_t806 + (0.2e1 / 0.27e2)*_t184*_t611 + (0.28e2 / 0.27e2)*_t184*_t807 + 0.16e2*_t26*_t805 + (0.1568e4 / 0.27e2)*_t618*_t814 + (0.224e3 / 0.9e1)*_t620*_t810 + (0.472e3 / 0.81e2)*_t621*_t811 + (0.3776e4 / 0.81e2)*_t621*_t815 + (0.448e3 / 0.27e2)*_t623*_t812;
  const double _t817 = _t175*_t765 + _t233*_t480 + _t25*(_hc9[1]*_t531 - _t164*_t747 + _t359*_t741 + _t361*_t534 + _t740 + _t751*_t93) - _t322*_t799 + _t37*(_t160*_t642 - _t337*_t665 - _t344*_t719 + _t668*_t718 - _t715*nb + 0.10e2*_t717 - _t720*nb - 0.80e2 / 0.3e1*_t721 - 0.28e2 / 0.3e1*_t722 - _t723*nb + _t737) + _t377*_t474 + _t381*_t775 + _t385*_t758 + _t44*(-_t1*_t584 - _t253*_t527 - _t586*nb - _t587*_t589 - _t591*nb - 0.7e1 / 0.5e1*_t592 + _t593*_t594 + _t595*_t596 - _t597*nb - _t598*nb - _t600*nb + _t625) + _t474*_t774 + _t478*_t777 + _t479*_t651 + _t480*_t651 + _t61*(-_t1*_t660 + _t132*_t642 + _t142*_t664 - _t306*_t643 + _t306*_t676 - _t308*_t665 - _t662*nb + 0.6e1*_t667 + 0.16e2*_t669 - _t670*nb - _t671*_t673 - _t675*nb - 0.80e2*_t679 - _t681*_t682 - _t685*nb + _t713) + _t644*_t793 + _t755*_t776 + _t766*_t767 + _t778*_t780 + _t781*_t782 + _t783*_t786 + _t787*_t790 + _t789*_t795 - _t797*nb - 0.4e1 / 0.9e1*_t800 - _t801*nb - _t802*nb - _t804*nb + _t816;
  const double _t818 = _t23*_t817;
  const double _t820 = _t413*_t416;
  const double _t821 = _t422*_t424;
  const double _t822 = _t190*_t821;
  const double _t823 = -0.16e2 / 0.3e1*_hc0[0]*_hc12[1]*_t122*_t190*_t21*_t3*_t5*_t82 - 0.2e1 / 0.3e1*_t190*_t21*_t219*_t220*_t255*_t310*_t82 + (0.20e2 / 0.3e1)*_t822;
  const double _t824 = _t255*_t730;
  const double _t825 = _t824*_t84;
  const double _t826 = (0.8e1 / 0.9e1)*_t825;
  const double _t827 = (0.80e2 / 0.3e1)*_t76;
  const double _t829 = _t37*_t724*_t828;
  const double _t830 = _t827*_t829;
  const double _t831 = _t105*_t428;
  const double _t832 = (0.112e3 / 0.27e2)*_t831;
  const double _t833 = -0.20e2 / 0.3e1*_hc0[0]*_t215*_t423*_t541*_t604*_t61*_t76 - 0.80e2 / 0.9e1*_t20*_t219*_t220*_t255*_t266*_t423*_t61*_t76 + _t826 + _t830 + _t832;
  const double _t837 = (0.2e1 / 0.3e1)*_t421 - 0.20e2 / 0.3e1*_t426 + _t428*_t836 + _t78*_t835;
  const double _t863 = _t199*_t261;
  const double _t865 = _t118*_t199;
  const double _t867 = _t283*nb;
  const double _t869 = _t104*_t282;
  const double _t870 = _t279*nb;
  const double _t871 = _t278*_t485;
  const double _t872 = (0.128e3 / 0.9e1)*_t275;
  const double _t874 = _t118*_t446*_t647 + _t124*_t873 + _t128*_t599 - _t210*_t446 + _t264*_t48 + _t625;
  const double _t901 = 0.2e1*_t420;
  const double _t906 = _t202*_t255;
  const double _t908 = _t151*_t432;
  const double _t909 = _t151*_t80;
  const double _t911 = (0.40e2 / 0.3e1)*_t330;
  const double _t912 = (0.16e2 / 0.3e1)*_t328;
  const double _t914 = (0.1e1 / 0.2e1)*_t152;
  const double _t917 = _t150*_t718*_t916 + _t155*_t913 - _t295*_t456 - _t308*_t915 + 0.16e2*_t311*_t48 + _t456*_t914 + _t713;
  const double _t922 = (0.10e2 / 0.3e1)*_t716;
  const double _t923 = _t151*_t587;
  const double _t924 = (0.16e2 / 0.9e1)*_t347;
  const double _t925 = (0.16e2 / 0.3e1)*_t151*_t916 + _t162*_t49 - _t337*_t915 + _t343*_t835 + _t737;
  const double _t949 = _t205*_t379;
  const double _t951 = _t378*_t767;
  const double _t952 = _t385*_t757;
  const double _t953 = _t298*_t952;
  const double _t954 = _hc11[1]*_t205;
  const double _t955 = _t177*_t954;
  const double _t957 = _t194*_t383;
  const double _t958 = _hc11[1]*_t950;
  const double _t959 = _t382*_t958;
  const double _t960 = _hc10[6]*_t776;
  const double _t961 = _t194*_t387;
  const double _t963 = _hc11[1]*_t794;
  const double _t964 = _t389*_t93;
  const double _t967 = _hc11[2]*_t966;
  const double _t968 = _t93*_t967;
  const double _t971 = _t194*_t388;
  const double _t973 = 0.12e2*_hc11[1];
  const double _t974 = _t972*_t973;
  const double _t976 = _t177*_t781;
  const double _t977 = _t169*_t478;
  const double _t978 = _t384*_t792;
  const double _t979 = _t176*_t386;
  const double _t980 = 0.24e2*_t979;
  const double _t985 = _t405*nb;
  const double _t986 = _t408*nb;
  const double _t987 = _t104*_t404;
  const double _t988 = _t485*_t987;
  const double _t989 = _t407*_t485;
  const double _t990 = (0.128e3 / 0.27e2)*_t410;
  const double _t991 = _t392 + _t393*_t798 + _t397 + _t816;
  const double _t992 = _t175*_t946 + _t206*_t839 + _t231*_t980 + _t233*_t961 + _t25*(_hc9[1]*_t839 - _t164*_t929 + _t232*_t361 + _t233*_t460 + _t356*_t359 + _t356*_t461 + _t740 + _t93*_t932) + _t37*(_t126*_t910 + _t127*_t668 - _t135*_t162 + _t160*_t885 + _t201*_t922 - _t294*_t459 - _t339*_t918 - _t341*_t921 - _t342*na - _t344*_t920 - _t348*na - _t352 - _t354 - _t677*_t923 + (0.20e2 / 0.3e1)*_t717 - 0.56e2 / 0.9e1*_t722 - _t919*nb - _t924*nb + _t925) + _t374*_t959 + _t377*_t477 + _t377*_t949 + _t380*_t955 + _t390*_t974 - _t395*_t983 - _t398*_t485 - _t401*_t484 - _t411*na + _t44*(_t119*_t595 - _t254 - _t265*na - _t270*na - _t276*na - _t447*_t858 - 0.14e2 / 0.15e2*_t592 + _t593*_t866 - _t859*nb - 0.320e3 / 0.27e2*_t860 - 0.160e3 / 0.27e2*_t861 - _t862*nb - 0.7e1 / 0.15e2*_t863 + _t864*_t865 - 0.640e3 / 0.9e1*_t867 - _t868*_t869 - 0.320e3 / 0.9e1*_t870 - 0.160e3 / 0.9e1*_t871 - _t872*nb + _t874) + _t473*_t964 + _t474*_t948 + _t61*(_t132*_t885 + _t142*_t908 + _t147*_t910 + _t153*_t306 + _t202*_t909 - _t294*_t458 - _t307 - _t313 - _t318*_t906 - _t321*na - _t324*_t904 - _t329*na - _t332 - _t335 - _t457*_t899 + 0.4e1*_t667 + (0.32e2 / 0.3e1)*_t669 - _t673*_t905 - _t677*_t911 - 0.160e3 / 0.3e1*_t679 - _t900*nb + _t901*_t902 - _t903*nb - _t907*nb - _t912*nb + _t917) + _t777*_t957 + _t783*_t956 - 0.8e1 / 0.27e2*_t800 + _t886*_t953 + _t886*_t978 + _t887*_t960 + _t950*_t951 + _t962*_t963 + _t965*_t968 + _t970*_t971 + _t975*_t976 + _t975*_t977 - _t982*nb - 0.4e1 / 0.27e2*_t984 - 0.640e3 / 0.27e2*_t985 - 0.448e3 / 0.27e2*_t986 - 0.320e3 / 0.27e2*_t988 - 0.224e3 / 0.27e2*_t989 - _t990*nb + _t991;
  const double _t993 = _t23*_t992;
  const double _t994 = _t420*_t83;
  const double _t995 = _t207*_t994;
  const double _t996 = _t190*_t994;
  const double _t997 = (0.20e2 / 0.3e1)*_t689;
  const double _t998 = _t207*_t821;
  const double _t999 = _t416*_t487;
  const double _t1000 = (0.8e1 / 0.3e1)*_t999;
  const double _t1001 = _t83*_t86;
  const double _t1002 = _t1001*_t207;
  const double _t1003 = _t1001*_t190;
  const double _t1004 = _t20*_t824;
  const double _t1005 = _t1004*_t425;
  const double _t1007 = _hc5[1]*_t650 + 0.2e1*_t448 - 0.2e1*_t488;
  const double _t1027 = _t118*_t501;
  const double _t1028 = _t485*_t869;
  const double _t1039 = _t420*_t902;
  const double _t1040 = _t256*_t906;
  const double _t1043 = _t1042*_t147;
  const double _t1045 = _t201*_t716;
  const double _t1054 = _t517*_t767;
  const double _t1055 = 0.2e1*_t949;
  const double _t1056 = _t507*_t952;
  const double _t1058 = _t475*_t93;
  const double _t1059 = _hc11[2]*_t517;
  const double _t1062 = _t382*_t789;
  const double _t1063 = _t388*_t788;
  const double _t1066 = _t969*_t971;
  const double _t1067 = _t169*_t957;
  const double _t1068 = 0.24e2*_hc11[0];
  const double _t1070 = _t1035*_t793 + _t1035*_t960 + _t1053*_t175 + _t1054*_t788 + _t1055*_t473 + _t1056*_t785 - _t1057*_t381 + _t1058*_t516 + _t1059*_t1060 + _t1061*_t478 + _t1062*_t514 + _t1063*_t1064 + _t1065*_t967 + _t1066*_t476 + _t1067*_t975 + _t1068*_t1069 + _t25*(-_hc9[1]*_t1010 - _hc9[1]*_t529 + 0.4e1*_t100*_t460*_t9 - _t1047 + _t1048*_t93 + (0.4e1 / 0.9e1)*_t122*_t3*_t461*_t5 - _t739) + _t37*(-_t101*_t728 + _t1034*_t160 + _t1041*_t126 + _t1042*_t127 - _t1044*_t344 + (0.20e2 / 0.3e1)*_t1045 + _t131*_t922 - _t148*_t923 - _t224*_t341 - _t340 - _t342*nb - _t348*nb - 0.56e2 / 0.9e1*_t351 - _t459*_t506 - 0.80e2 / 0.9e1*_t721 - 0.28e2 / 0.9e1*_t722 - _t919*na - _t924*na + _t925) - _t381*_t481 - _t395*_t401 - _t399*nb - _t411*nb + _t44*(-_t1026*_t447 + _t1027*_t119 - 0.640e3 / 0.9e1*_t1028 - _t265*nb - _t270*nb - _t276*nb - _t278*_t868 - _t502 - 0.7e1 / 0.15e2*_t592 + _t593*_t864 - _t859*na - 0.160e3 / 0.27e2*_t860 - 0.320e3 / 0.27e2*_t861 - _t862*na - 0.14e2 / 0.15e2*_t863 + _t865*_t866 - 0.320e3 / 0.9e1*_t867 - 0.160e3 / 0.9e1*_t870 - _t872*na + _t874) + _t473*_t520 + _t474*_t516 + _t476*_t974 + _t480*_t489 - _t484*_t983 + _t518*_t976 + _t61*(_t1034*_t132 - _t1038*_t457 + 0.4e1*_t1039 - _t1040*_t905 + _t1041*_t147 + (0.32e2 / 0.3e1)*_t1043 + _t142*_t909 - _t148*_t911 + _t153*_t509 + _t202*_t908 - _t312*nb - _t318*_t672 - _t321*nb - _t325 - _t329*nb - _t331*_t677 - 0.160e3 / 0.3e1*_t334 - _t458*_t506 - _t510 + _t666*_t901 - 0.80e2 / 0.3e1*_t679 - _t900*na - _t903*na - _t907*na - _t912*na + _t917) - 0.4e1 / 0.27e2*_t800 + _t955*_t975 - _t982*na - 0.8e1 / 0.27e2*_t984 - 0.320e3 / 0.27e2*_t985 - 0.224e3 / 0.27e2*_t986 - 0.640e3 / 0.27e2*_t988 - 0.448e3 / 0.27e2*_t989 - _t990*na + _t991;
  const double _t1071 = _t1070*_t23;
  const double _t1072 = _t416*_t521;
  const double _t1073 = -_t434*_t834 + _t837;
  const double _t1074 = (0.20e2 / 0.3e1)*_t998;
  const double _t1119 = _hc11[1]*_t516;
  const double _t1125 = _t1059*_t1122 + _t1061*_t957 + _t1102*_t793 + _t1102*_t952 + _t1102*_t960 + _t1103*_t961 + _t1104*_t519 + _t1113*_t175 + _t1114*_t767 + _t1117*_t949 + _t1118*_t381 + _t1119*_t1120 + _t1121*_t954 + _t1123*_t958 + _t1124*_t958 + _t25*(_hc9[1]*_t1076 - _t1047 + _t1048*_t194 + _t1079*_t460 + _t461*_t741 + _t740) + _t37*(_t1042*_t718 + 0.10e2*_t1045 + _t1101*_t160 - _t1107*_t337 - _t1108*na - 0.28e2 / 0.3e1*_t351 - 0.80e2 / 0.3e1*_t353 - _t715*na - _t720*na - _t723*na + _t737) + _t44*(-_t1*_t1097 + _t1027*_t596 - 0.320e3 / 0.3e1*_t1028 - _t1098*na - _t501*_t527 - _t586*na - _t591*na + _t594*_t865 - _t600*na + _t625 - 0.7e1 / 0.5e1*_t863 - 0.160e3 / 0.3e1*_t871) + _t489*_t961 + _t516*_t949 + _t61*(-_t1*_t1106 + 0.6e1*_t1039 - _t1040*_t671 + 0.16e2*_t1043 + _t1101*_t132 - _t1107*_t308 + _t202*_t664 - 0.80e2*_t334 - _t350*_t681 - _t509*_t643 + _t509*_t676 - _t662*na - _t670*na - _t675*na - _t685*na + _t713) - _t797*na - _t799*_t904 - _t804*na + _t816 - _t868*_t987 - 0.4e1 / 0.9e1*_t984 - 0.224e3 / 0.9e1*_t989;
  const double _t1126 = _t1125*_t23;
  const double _t1127 = -_hc5[1]*_t1076 - _t1029*_t194 + _t1126 - 0.2e1*_t436*_t489;
  const double d3F_dna3 = _t1*(_hc5[1]*_t531 + 0.2e1*_t233*_t289 - _t526 + _t634*_t93 - _t640 - _t818 - _t819 - 0.4e1*_t820 - _t823 - _t833) + 0.3e1*_t287 + 0.3e1*_t290 - _t292*_t834 - 0.3e1*_t414 - 0.8e1*_t417 + _t837;
  const double d3F_dna2_dnb = _t1*(-_t1000 + _t1002*_t430 + (0.32e2 / 0.9e1)*_t1003*_t429 + (0.80e2 / 0.9e1)*_t1005 + _t425*_t997 - 0.4e1 / 0.3e1*_t820 - 0.40e2 / 0.9e1*_t822 - _t826 - _t830 - _t832 + _t885 - _t993 + (0.2e1 / 0.9e1)*_t995 + (0.4e1 / 0.9e1)*_t996 - 0.20e2 / 0.9e1*_t998) - _t1006*_t432 + _t1007 + _t293 + _t415 - 0.16e2 / 0.3e1*_t417 + _t524 + _t837;
  const double d3F_dna_dnb2 = _t1*((0.16e2 / 0.9e1)*_hc0[0]*_hc12[1]*_t122*_t190*_t21*_t3*_t5*_t82 + (0.32e2 / 0.9e1)*_hc0[0]*_hc12[1]*_t122*_t207*_t21*_t3*_t5*_t82 - _t1000 - _t1033 - _t1071 - 0.4e1 / 0.3e1*_t1072 + (0.2e1 / 0.9e1)*_t190*_t21*_t219*_t220*_t255*_t310*_t82 + (0.4e1 / 0.9e1)*_t207*_t21*_t219*_t220*_t255*_t310*_t82 - 0.20e2 / 0.9e1*_t822 - _t833 - 0.40e2 / 0.9e1*_t998) + _t1007 + _t1073 + _t418 - 0.16e2 / 0.3e1*_t437 + _t505 + _t523;
  const double d3F_dnb3 = _t1*((0.16e2 / 0.3e1)*_hc0[0]*_hc12[1]*_t122*_t207*_t21*_t3*_t5*_t82 - _t1032 - 0.4e1*_t1072 - _t1074 - _t1127 + (0.2e1 / 0.3e1)*_t207*_t21*_t219*_t220*_t255*_t310*_t82 - _t833) + _t1073 - 0.8e1*_t437 + 0.3e1*_t503 + 0.3e1*_t504 - 0.3e1*_t522;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t1129 = 0.384e3*_t567;
  const double _t1130 = (0.4e1 / 0.9e1)*_t571;
  const double _t1131 = (0.2096e4 / 0.27e2)*_t576;
  const double _t1132 = 0.480e3*_t571;
  const double _t1133 = xc_powi(_t1, -7);
  const double _t1134 = _t1133*_t121;
  const double _t1135 = xc_powr(_t1, -22, 3);
  const double _t1136 = (0.1e1 / _t70);
  const double _t1137 = _t1136*_t3;
  const double _t1138 = (0.1e1 / 0.54e2)*_t1135*_t1137*_t26;
  const double _t1139 = xc_powr(_t1, -20, 3);
  const double _t1140 = (0.772e3 / 0.81e2)*_t1139*_t221*_t26;
  const double _t1141 = xc_powr(_t1, -19, 3);
  const double _t1142 = _t1141*_t6;
  const double _t1143 = _t1142*nb;
  const double _t1144 = (0.9680e4 / 0.81e2)*_t1143;
  const double _t1146 = _t567*_t9;
  const double _t1147 = 0.24e2*_t1146;
  const double _t1148 = _t1147 - _t216;
  const double _t1149 = 0.3e1*_t100;
  const double _t1150 = 0.3e1*_t528;
  const double _t1151 = -_t1149 + _t1150;
  const double _t1153 = (0.2e1 / 0.9e1)*_t541;
  const double _t1155 = (0.1e1 / 0.9e1)*_t541;
  const double _t1156 = (0.1e1 / 0.216e3)*_t1137;
  const double _t1157 = (0.40e2 / 0.81e2)*_t221;
  const double _t1158 = (0.140e3 / 0.81e2)*_t6;
  const double _t1159 = (0.56e2 / 0.27e2)*_t6;
  const double _t1160 = (0.4e1 / 0.3e1)*_t6;
  const double _t1161 = _t1160*_t233;
  const double _t1162 = (0.4e1 / 0.9e1)*_t221;
  const double _t1163 = (0.1e1 / 0.6e1)*_t221;
  const double _t1166 = _t237*_t93;
  const double _t1174 = _t116/xc_powr(M_PI, 5, 6);
  const double _t1176 = _t571*na;
  const double _t1178 = _t1176*_t602;
  const double _t1180 = _t1141*_t1174;
  const double _t1183 = _t26*_t579;
  const double _t1185 = _t26*_t575;
  const double _t1186 = _t1180*_t26;
  const double _t1190 = _t1183*_t259;
  const double _t1192 = (0.140e3 / 0.81e2)*_t226;
  const double _t1195 = _t6*_t835;
  const double _t1213 = (_t93 * _t93 * _t93 * _t93);
  const double _t1217 = (0.8e1 / 0.15e2)*_t2;
  const double _t1221 = (_t233 * _t233);
  const double _t1222 = 0.6e1*_t48;
  const double _t1223 = 0.6e1*na - 0.6e1*nb;
  const double _t1224 = _t100*_t1223 - _t1222;
  const double _t1226 = -_t338 + _t918;
  const double _t1227 = _t100*_t1226 - _t49;
  const double _t1228 = _t204 - _t39;
  const double _t1229 = _t100*_t1228 - _t161;
  const double _t1232 = _t531*_t93;
  const double _t1234 = _t727*_t9;
  const double _t1235 = -_t1234 + _t714;
  const double _t1244 = (0.8e1 / 0.9e1)*_t122;
  const double _t1252 = 0.192e3*_t567;
  const double _t1265 = _t1142*_t26;
  const double _t1274 = _t579*nb;
  const double _t1317 = (0.7e1 / 0.12e2)*_t365;
  const double _t1328 = _t1213*_t371;
  const double _t1340 = _t233*_t93;
  const double _t1342 = _t651*_t93;
  const double _t1355 = 0.6e1*_t371;
  const double _t1359 = (0.1e1 / 0.2e1)*_t166;
  const double _t1372 = 0.12e2*_t531;
  const double _t1393 = _t602*_t704;
  const double _t1401 = _t218*_t259;
  const double _t1417 = (0.32e2 / 0.3e1)*_t429;
  const double _t1429 = (0.2e1 / 0.3e1)*_t85;
  const double _t1437 = _t1147 - _t727;
  const double _t1438 = -_t100 + _t1150;
  const double _t1439 = -_t1438;
  const double _t1440 = -_t1437;
  const double _t1441 = 0.288e3*_t567;
  const double _t1442 = 0.2e1*_t839;
  const double _t1445 = (0.1e1 / 0.3e1)*_t571;
  const double _t1446 = _t570*na;
  const double _t1447 = (0.524e3 / 0.9e1)*_t576;
  const double _t1453 = _t196*_t250;
  const double _t1458 = _t439*_t93;
  const double _t1461 = _t1160*_t231;
  const double _t1474 = _t644*_t886;
  const double _t1475 = 0.4e1*_t100 - _t1234;
  const double _t1476 = _t651*_t9;
  const double _t1478 = _t233*_t9;
  const double _t1482 = _t298*_t9;
  const double _t1486 = _t104*_t9;
  const double _t1487 = _t194*_t651;
  const double _t1488 = _t1487*_t93;
  const double _t1517 = (0.7e1 / 0.24e2)*_t365;
  const double _t1518 = (0.1e1 / 0.4e1)*_t166;
  const double _t1522 = _t933*_t938;
  const double _t1524 = _t194*_t531;
  const double _t1525 = _t1482*_t469;
  const double _t1542 = _t380*_t467;
  const double _t1545 = _t16*_t469;
  const double _t1561 = _t785*_t886;
  const double _t1607 = _t806*na;
  const double _t1615 = _t226*na;
  const double _t1634 = 0.96e2*_t215;
  const double _t1636 = (0.4e1 / 0.9e1)*_t222;
  const double _t1637 = (0.128e3 / 0.9e1)*_t227;
  const double _t1638 = (0.1048e4 / 0.27e2)*_t576;
  const double _t1640 = (_t9 * _t9);
  const double _t1641 = _t1640*_t570;
  const double _t1642 = 0.4e1*_t1641;
  const double _t1645 = _t100*_t6;
  const double _t1658 = (0.1120e4 / 0.27e2)*_t227;
  const double _t1674 = (0.28e2 / 0.27e2)*_t105;
  const double _t1681 = _t298*_t507;
  const double _t1682 = _t100*_t1228 + _t161;
  const double _t1683 = _t1229*_t507;
  const double _t1687 = _t194*_t839;
  const double _t1688 = _t1037*_t93;
  const double _t1699 = _t1640/xc_powr(_t1, 37, 6);
  const double _t1700 = (0.7e1 / 0.72e2)*_t365;
  const double _t1706 = _t1037*_t933;
  const double _t1708 = _t489*_t93;
  const double _t1717 = 0.24e2*_t1688;
  const double _t1724 = 0.36e2*_t528;
  const double _t1727 = 0.6e1*_t194;
  const double _t1736 = 0.24e2*_t231;
  const double _t1748 = _t432*_t6;
  const double _t1752 = (0.14e2 / 0.9e1)*_t105;
  const double _t1758 = (0.10e2 / 0.3e1)*na;
  const double _t1759 = _t1149 + _t1150;
  const double _t1760 = -_t1759;
  const double _t1762 = _t1009*_t196;
  const double _t1763 = _t1163*_t494;
  const double _t1769 = _t1102*_t785;
  const double _t1772 = _t489*_t9;
  const double _t1773 = _t507*_t9;
  const double _t1782 = _t1773*_t469;
  const double _t1785 = _t467*_t518;
  const double _t1786 = _t1104*_t93;
  const double _t1788 = 0.54e2*_t528;
  const double _t1797 = _t1147 + _t216;
  const double _t1798 = _t1160*_t491;
  const double _t1802 = (_t194 * _t194 * _t194 * _t194);
  const double _t1803 = (_t489 * _t489);
  const double _t1805 = _t100*_t1226 + _t49;
  const double _t1806 = _t100*_t1223 + _t1222;
  const double _t1808 = _t1076*_t194;
  const double _t1809 = -_t1234 - _t714;
  const double _t1810 = _t1809*_t194;
  const double _t1811 = _t1103*_t489;
  const double _t1128 = (0.3e1 / 0.5e1)*_t33;
  const double _t1145 = _hc3[2]*_t1140 + _hc3[4]*_t1138 + _t102*_t1132 + _t107*_t1144 + _t1134*_t572;
  const double _t1152 = _hc1[0]*_t532;
  const double _t1154 = _hc1[3]*_t53;
  const double _t1164 = _hc1[2]*_t1163*_t242;
  const double _t1165 = _t1164*_t53;
  const double _t1167 = _hc1[1]*_t246;
  const double _t1168 = _t1167*_t53;
  const double _t1169 = _hc1[4]*_t1156*_t54/xc_powr(na, 16, 3) + _t1148*_t94 - _t1148*_t95 - _t1151*_t238 + _t1151*_t240 + _t1152*_t380 + _t1153*_t539/xc_powi(na, 5) - _t1154*_t1155*_t540*_t93 + _t1157*_t241/xc_powr(na, 14, 3) + _t1158*_t245/xc_powr(na, 13, 3) - _t1159*_t545*_t564 + _t1160*_t1166*_t1167 + _t1161*_t1168 - _t1161*_t557 - _t1162*_t549*_t561 + _t1164*_t1166 + _t1165*_t233 + 0.3e1*_t530*_t842 - _t531*_t855 - _t532*_t565*_t93*_t97 + 0.3e1*_t533*_t536 + _t535*_t775;
  const double _t1177 = _t1176*_t610;
  const double _t1179 = _hc4[2]*_t1178;
  const double _t1181 = _hc4[4]*_t1180;
  const double _t1182 = _hc4[0]*_t1178;
  const double _t1184 = _t1183*_t260;
  const double _t1187 = _hc4[3]*_t1186;
  const double _t1189 = _hc4[1]*_t1186;
  const double _t1193 = _t1192*_t78;
  const double _t1194 = _t104*_t627;
  const double _t1196 = _hc5[5]*_t738;
  const double _t1197 = -_t1196;
  const double _t1198 = _hc5[9]*_t356;
  const double _t1199 = -_hc5[14]*_t164;
  const double _t1200 = -_hc5[13]*_t164;
  const double _t1201 = _hc5[12]*_t93 + _t1200;
  const double _t1202 = _hc5[8]*_t356;
  const double _t1203 = -_hc5[12]*_t164;
  const double _t1204 = _hc5[11]*_t93 + _t1203;
  const double _t1205 = _hc5[7]*_t233 - _t1201*_t164 + _t1202 + _t1204*_t93;
  const double _t1206 = _hc5[4]*_t738;
  const double _t1207 = -_t1206;
  const double _t1208 = _hc5[7]*_t356;
  const double _t1209 = -_hc5[11]*_t164;
  const double _t1210 = _hc5[1]*_t1148 + _t1193 - 0.14e2 / 0.9e1*_t1194 + _t1195*_t639 - _t164*(_hc5[4]*_t531 + _t1197 + _t1205*_t93 - _t164*(_hc5[8]*_t233 + _t1198 + _t1201*_t93 - _t164*(_hc5[13]*_t93 + _t1199)) + _t534*_t631 + _t638*_t741) + _t289*_t775 + _t380*_t634 + _t93*(_hc5[3]*_t531 - _t1205*_t164 + _t1207 + _t534*_t633 + _t631*_t741 + _t93*(_hc5[6]*_t233 - _t1204*_t164 + _t1208 + _t93*(_hc5[10]*_t93 + _t1209)));
  const double _t1211 = (0.3e1 / 0.4e1)*_t40;
  const double _t1212 = _hc6[0]*nb;
  const double _t1214 = _hc7[10]*_t297;
  const double _t1215 = _hc6[1]*nb;
  const double _t1216 = _t122*_t302;
  const double _t1218 = _t1217*_t301;
  const double _t1219 = _hc7[6]*_t648;
  const double _t1220 = _t1219*_t644;
  const double _t1225 = _t298*_t645;
  const double _t1230 = _t233*_t301;
  const double _t1231 = _t1217*_t896;
  const double _t1233 = (0.2e1 / 0.5e1)*_t69*_t892;
  const double _t1236 = _t233*_t454;
  const double _t1237 = _hc6[2]*_t1140 + _hc6[4]*_t1138 + (0.56e2 / 0.405e3)*_t104*_t137 + _t1132*_t136 + _t1134*_t654 + _t1144*_t140;
  const double _t1242 = (0.7e1 / 0.4e1)*_t316;
  const double _t1245 = _t105*_t131;
  const double _t1246 = (0.448e3 / 0.9e1)*_t1245;
  const double _t1248 = _hc8[3]*_t1176;
  const double _t1249 = _t1248*_t913;
  const double _t1250 = _hc8[2]*_t1176;
  const double _t1253 = _t1252*_t700;
  const double _t1256 = _t148*_t571;
  const double _t1260 = _hc8[4]*_t1142;
  const double _t1261 = (0.1e1 / 0.27e2)*_t1260*_t609;
  const double _t1262 = _t319*_t579;
  const double _t1263 = (0.824e3 / 0.81e2)*_t1262*_t609;
  const double _t1264 = (0.6784e4 / 0.81e2)*_t1185*_t323;
  const double _t1266 = _hc8[3]*_t1265;
  const double _t1269 = _t1143*_t148;
  const double _t1271 = _hc8[1]*_t1265;
  const double _t1276 = _t148*_t575*nb;
  const double _t1282 = (0.2e1 / 0.3e1)*_t1248*_t29;
  const double _t1284 = 0.48e2*_t704*_t728;
  const double _t1287 = (0.1e1 / 0.108e3)*_t1260*_t183;
  const double _t1288 = (0.206e3 / 0.81e2)*_t1262*_t183;
  const double _t1289 = (0.1696e4 / 0.81e2)*_t1185*_t343;
  const double _t1298 = _hc9[2]*_t1192*_t6;
  const double _t1299 = _t105*_t359;
  const double _t1300 = _hc9[5]*_t738;
  const double _t1301 = -_t1300;
  const double _t1302 = _hc9[9]*_t356;
  const double _t1303 = -_hc9[14]*_t164;
  const double _t1304 = -_hc9[13]*_t164;
  const double _t1305 = _hc9[12]*_t93 + _t1304;
  const double _t1306 = _hc9[8]*_t356;
  const double _t1307 = -_hc9[12]*_t164;
  const double _t1308 = _hc9[11]*_t93 + _t1307;
  const double _t1309 = _hc9[7]*_t233 - _t1305*_t164 + _t1306 + _t1308*_t93;
  const double _t1310 = _hc9[4]*_t738;
  const double _t1311 = -_t1310;
  const double _t1312 = _hc9[7]*_t356;
  const double _t1313 = -_hc9[11]*_t164;
  const double _t1314 = (0.1729e4 / 0.2592e4)*_t17*_t933;
  const double _t1315 = _t470*_t93;
  const double _t1316 = _t172*_t233;
  const double _t1318 = _t172*_t769;
  const double _t1319 = _hc10[10]*_t375;
  const double _t1320 = _t171*_t374;
  const double _t1321 = _t171*_t755;
  const double _t1322 = _hc10[3]*_t644;
  const double _t1323 = _hc10[1]*_t369;
  const double _t1324 = _t1322*_t1323*_t761;
  const double _t1325 = _hc10[6]*_t1213;
  const double _t1326 = _t1323*_t371;
  const double _t1327 = 0.4e1*_t1326;
  const double _t1329 = 0.12e2*((_hc10[1]) * (_hc10[1]) * (_hc10[1]) * (_hc10[1]))/xc_powi((_hc10[0]), 5);
  const double _t1330 = _t759*_t761;
  const double _t1331 = _t16*_t370;
  const double _t1332 = _t1331*_t298;
  const double _t1333 = _t1332*_t365;
  const double _t1334 = ((_hc10[3]) * (_hc10[3]));
  const double _t1335 = _t1213*_t1334;
  const double _t1336 = _t369*_t760;
  const double _t1337 = 0.18e2*_t756;
  const double _t1338 = _t1337*_t368;
  const double _t1339 = _hc10[3]*_t1338;
  const double _t1341 = _t769*_t939;
  const double _t1343 = (0.2e1 / 0.3e1)*_t762;
  const double _t1344 = 0.2e1*_t464;
  const double _t1345 = _t233*_t468;
  const double _t1346 = _t233*_t464;
  const double _t1347 = _hc10[6]*_t298;
  const double _t1348 = _t1347*_t375;
  const double _t1349 = _hc10[1]*_t1336;
  const double _t1350 = _t1349*_t374;
  const double _t1351 = _t756*_t757;
  const double _t1352 = 0.3e1*_t1351*_t372;
  const double _t1354 = (0.91e2 / 0.216e3)*_t752;
  const double _t1356 = _t93*_t947;
  const double _t1358 = (0.7e1 / 0.24e2)*_t366;
  const double _t1360 = _t172*_t785;
  const double _t1361 = _t1229*_t768;
  const double _t1362 = -_t1229*_t173 + _t1360*_t363 + _t376;
  const double _t1366 = 0.36e2*_t368;
  const double _t1373 = 0.12e2*_t177;
  const double _t1377 = 0.18e2*_t177;
  const double _t1378 = _t1377*_t377;
  const double _t1381 = 0.18e2*_t169;
  const double _t1382 = _hc10[0]*_hc10[1];
  const double _t1385 = _t1373*_t390;
  const double _t1388 = _t386*_t390;
  const double _t1389 = 0.24e2*_t1388;
  const double _t1390 = 0.72e2*_t1382;
  const double _t1391 = _t805*nb;
  const double _t1392 = _t610*_t704*_t798;
  const double _t1394 = _hc4[2]*_t1393;
  const double _t1395 = _t395*_t807;
  const double _t1397 = _hc4[1]*_t1393*_t38;
  const double _t1399 = _t711*_t811;
  const double _t1425 = _t37*_t828;
  const double _t1430 = _t122*_t627;
  const double _t1432 = (0.56e2 / 0.27e2)*_t104*_t78;
  const double _t1443 = _hc2[0]*_t232*_t533;
  const double _t1444 = _t232*_t536;
  const double _t1448 = _t1154*_t194*_t543;
  const double _t1449 = _t547*_t854;
  const double _t1450 = _t555*_t839;
  const double _t1451 = _t233*_t7*_t847;
  const double _t1452 = _hc2[1]*_t239;
  const double _t1454 = _t1452*_t1453*_t236;
  const double _t1455 = _t444*_t530;
  const double _t1456 = _t533*_t851;
  const double _t1457 = _t551*_t853;
  const double _t1459 = _t231*_t557*_t6;
  const double _t1460 = _t231*_t558*_t97;
  const double _t1464 = _hc5[11]*_t194 + _t1203;
  const double _t1465 = _hc5[12]*_t194 + _t1200;
  const double _t1466 = _t1202 - _t1465*_t164;
  const double _t1467 = _hc5[7]*_t232 + _t1464*_t93 + _t1466;
  const double _t1468 = _hc5[10]*_t194 + _t1209;
  const double _t1469 = _t1208 - _t1464*_t164;
  const double _t1470 = _t1198 - _t164*(_hc5[13]*_t194 + _t1199);
  const double _t1471 = _t1193 + _t741*_t880;
  const double _t1472 = _hc5[1]*_t1437 - 0.28e2 / 0.27e2*_t1194 + _t1442*_t289 + _t1471 - _t164*(_hc5[4]*_t839 + _t1197 + _t1467*_t93 - _t164*(_hc5[8]*_t232 + _t1465*_t93 + _t1470) + _t232*_t631 + _t233*_t877 + _t356*_t638 + _t356*_t878) + _t232*_t634 + _t356*_t639 - _t434*_t738 + _t436*_t531 + _t534*_t883 + _t93*(_hc5[3]*_t839 + _t1207 - _t1467*_t164 + _t232*_t633 + _t233*_t881 + _t356*_t631 + _t356*_t877 + _t93*(_hc5[6]*_t232 + _t1468*_t93 + _t1469));
  const double _t1473 = _t1446*_t654;
  const double _t1477 = (0.2e1 / 0.5e1)*_t893;
  const double _t1479 = _t892*_t936;
  const double _t1480 = _t1219*_t887;
  const double _t1481 = _t138*_t896;
  const double _t1483 = _t1219*_t122;
  const double _t1484 = (0.6e1 / 0.5e1)*_t1483;
  const double _t1485 = (0.8e1 / 0.5e1)*_t892;
  const double _t1489 = _hc7[6]*_t453;
  const double _t1490 = _t1489*_t93;
  const double _t1491 = -0.72e2*_hc6[0]*_t215 - 0.480e3*_hc6[0]*_t570*na*nb - 0.9680e4 / 0.81e2*_hc6[1]*_t1141*_t3*_t5*na*nb - 0.32e2 / 0.3e1*_hc6[1]*_t226*_t3*_t5 - 0.772e3 / 0.81e2*_hc6[2]*_t1139*_t219*_t220*na*nb - 0.1e1 / 0.3e1*_hc6[2]*_t218*_t219*_t220 - 0.16e2 / 0.9e1*_hc6[3]*_t1133*_t541*na*nb - 0.1e1 / 0.54e2*_hc6[4]*_t1135*_t1136*_t3*na*nb - 0.56e2 / 0.405e3*_hc7[0]*_t104*_t67*_t70 - 0.2e1 / 0.15e2*_hc7[3]*_t194*_t67*_t70*_t79*_t93;
  const double _t1494 = 0.12e2*_t885;
  const double _t1496 = (0.112e3 / 0.3e1)*_t1245;
  const double _t1497 = _t201*_t702;
  const double _t1499 = _hc8[0]*_t104;
  const double _t1508 = _hc9[11]*_t194 + _t1307;
  const double _t1509 = _hc9[12]*_t194 + _t1304;
  const double _t1510 = _t1306 - _t1509*_t164;
  const double _t1511 = _hc9[7]*_t232 + _t1508*_t93 + _t1510;
  const double _t1512 = _hc9[10]*_t194 + _t1313;
  const double _t1513 = _t1312 - _t1508*_t164;
  const double _t1514 = _t1302 - _t164*(_hc9[13]*_t194 + _t1303);
  const double _t1515 = _t1298 + _t741*_t929;
  const double _t1516 = _t172*_t9/xc_powr(_t1, 31, 6);
  const double _t1519 = _t1518*_t172;
  const double _t1520 = _t167*_t172;
  const double _t1521 = _t194*_t470;
  const double _t1523 = _t1522*_t939;
  const double _t1526 = _t1337*_t16*_t757;
  const double _t1527 = _hc10[6]*_t171;
  const double _t1528 = 0.3e1*_t1527;
  const double _t1529 = _t1331*_t1522;
  const double _t1530 = _t1331*_t469;
  const double _t1531 = _t1334*_t1336;
  const double _t1532 = _t1329*_t371;
  const double _t1533 = _t762*_t936;
  const double _t1534 = (0.1e1 / 0.6e1)*_t762;
  const double _t1535 = _t936*_t939;
  const double _t1536 = _t171*_t937;
  const double _t1537 = _t167*_t939;
  const double _t1538 = _t756*_t761;
  const double _t1539 = _t1538*_t942;
  const double _t1540 = _t1339*_t371;
  const double _t1541 = _t757*_t943;
  const double _t1543 = _t1351*_t371;
  const double _t1544 = _t755*_t886;
  const double _t1546 = _t1323*_t1545;
  const double _t1547 = 0.18e2*_t1546*_t9;
  const double _t1548 = _t1323*_t761;
  const double _t1549 = _t1548*_t374*_t886;
  const double _t1550 = _hc10[6]*_t375;
  const double _t1551 = _t1550*_t93;
  const double _t1552 = _hc10[3]*_t1349;
  const double _t1553 = _hc10[3]*_t1326;
  const double _t1554 = _t467*_t939;
  const double _t1555 = _t1331*_t467;
  const double _t1556 = _t1314 + _t1317*_t1555 - _t1517*_t1554;
  const double _t1557 = 0.4e1*_t940;
  const double _t1558 = _t1355*_t756;
  const double _t1559 = -0.1e1 / 0.3e1*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t194*_t93*p->cam_omega + _t1354 + (0.2e1 / 0.3e1)*_t944;
  const double _t1562 = _t1561*_t464;
  const double _t1567 = _t1360*_t167 + _t1520*_t886 - _t1561*_t468 + _t1562 + _t472;
  const double _t1571 = _t231*_t757;
  const double _t1573 = _t174*_t178*_t194;
  const double _t1574 = _hc10[3]*_t476;
  const double _t1587 = _hc10[3]*_t787;
  const double _t1588 = _t1587*_t194;
  const double _t1593 = 0.18e2*_t972;
  const double _t1594 = 0.18e2*_t386;
  const double _t1596 = _t1381*_t231;
  const double _t1598 = _t805*na;
  const double _t1600 = _t699*_t796;
  const double _t1601 = _t1382*_t886;
  const double _t1602 = _t1382*_t231;
  const double _t1603 = 0.108e3*_t1602;
  const double _t1604 = _t611*_t798;
  const double _t1605 = _t484*_t611;
  const double _t1609 = _t484*_t807;
  const double _t1611 = _t38*na;
  const double _t1612 = _t1611*_t806;
  const double _t1616 = _t1615*_t811;
  const double _t1620 = _t403*_t798;
  const double _t1635 = (0.2e1 / 0.9e1)*_t572;
  const double _t1639 = (0.20e2 / 0.9e1)*_t581;
  const double _t1643 = _t1147*_t95;
  const double _t1644 = _hc1[2]*_t244;
  const double _t1646 = _hc1[1]*_t248;
  const double _t1647 = _hc1[0]*_t1642 + _hc2[0]*_t1642 + _hc2[1]*_t196*_t231*_t236*_t565 + _hc2[2]*_t236*_t495*_t92 - _t100*_t238 + _t100*_t240 - _t1008*_t251*_t97 - _t1010*_t535 + _t1010*_t842 - _t1016*_t1452 + _t1018*_t1644 + _t1018*_t1646 + _t1020*_t1644 + _t1020*_t1646 + _t1023*_t239 + _t1024*_t239 + _t1077*_t233 + _t1078*_t239 + _t1080*_t838 + _t1147*_t94 - _t1150*_t238 + _t1150*_t240 + _t1442*_t490 + _t1453*_t231*_t850 - _t1461*_t847 - _t1643 + (0.2e1 / 0.3e1)*_t1645*_t249 + _t236*_t497*_t850 + 0.2e1*_t249*_t528*_t6 - _t499*_t838 - _t529*_t535 + _t529*_t842;
  const double _t1650 = _t690*na;
  const double _t1651 = _hc8[2]*_t704;
  const double _t1652 = _hc5[0]*_t567;
  const double _t1653 = _t148*_t567;
  const double _t1654 = _t567*_t677;
  const double _t1659 = _t148*_t226;
  const double _t1660 = _t226*_t677;
  const double _t1663 = _t105*_t201;
  const double _t1665 = (0.64e2 / 0.3e1)*_t450;
  const double _t1670 = _hc5[1]*_t1147;
  const double _t1671 = _hc5[7]*_t489 + _t1464*_t194 + _t1466;
  const double _t1672 = _t164*_t1671;
  const double _t1673 = _hc5[6]*_t489 + _t1468*_t194 + _t1469;
  const double _t1675 = _t164*(_hc5[8]*_t489 + _t1465*_t194 + _t1470);
  const double _t1676 = -_t1010*_t289 + _t1029*_t233 + _t1030*_t356 + _t1442*_t436 + _t1471 - _t164*(-_hc5[4]*_t1010 - _hc5[4]*_t529 + 0.4e1*_t100*_t877*_t9 - _t1196 + (0.4e1 / 0.9e1)*_t122*_t3*_t5*_t878 + _t1671*_t93 - _t1675) + _t1670 - _t1674*_t434 - _t289*_t529 - _t525*_t627 + _t650*_t883 + _t93*(-_hc5[3]*_t1010 - _hc5[3]*_t529 + 0.4e1*_t100*_t881*_t9 - _t1206 + (0.4e1 / 0.9e1)*_t122*_t3*_t5*_t877 - _t1672 + _t1673*_t93);
  const double _t1677 = _hc6[3]*_t1153;
  const double _t1678 = _t226*_t301*_t9;
  const double _t1679 = (0.20e2 / 0.9e1)*_t656;
  const double _t1680 = _t122*_t452;
  const double _t1684 = _t301*_t489;
  const double _t1685 = _t489*_t896;
  const double _t1686 = _t1035*_t1219;
  const double _t1689 = _t218*_t316;
  const double _t1693 = _hc9[1]*_t1147;
  const double _t1694 = _hc9[7]*_t489 + _t1508*_t194 + _t1510;
  const double _t1695 = _t164*_t1694;
  const double _t1696 = _hc9[6]*_t489 + _t1512*_t194 + _t1513;
  const double _t1697 = _t164*(_hc9[8]*_t489 + _t1509*_t194 + _t1514);
  const double _t1698 = _t172*_t933;
  const double _t1701 = _t172*_t489;
  const double _t1702 = _t172*_t363;
  const double _t1703 = _t171*_t514;
  const double _t1704 = _t1331*_t507;
  const double _t1705 = _t1704*_t365;
  const double _t1707 = _t1331*_t1706;
  const double _t1709 = _t1708*_t939;
  const double _t1710 = _t1051*_t171;
  const double _t1711 = _t1052*_t1538;
  const double _t1712 = _t1708*_t762;
  const double _t1713 = _hc10[3]*_t1035;
  const double _t1714 = _t1548*_t1713;
  const double _t1715 = _hc10[6]*_t1327;
  const double _t1716 = _t1349*_t514;
  const double _t1719 = -_t1682*_t173 + _t1702*_t886 + _t515;
  const double _t1720 = _t177*_t377;
  const double _t1721 = _t382*_t514;
  const double _t1732 = _t194*_t969;
  const double _t1733 = 0.12e2*_t1732;
  const double _t1735 = 0.24e2*_t972;
  const double _t1737 = _t1736*_t177;
  const double _t1739 = _t1382*_t1713;
  const double _t1740 = _hc4[2]*_t1607;
  const double _t1750 = _t436*_t481;
  const double _t1751 = _t1057*_t436;
  const double _t1753 = _t1752*_t434;
  const double _t1754 = _t164*(_hc5[4]*_t1076 + _t1079*_t877 + _t1197 + _t1671*_t194 - _t1675 + _t741*_t878);
  const double _t1755 = _hc5[3]*_t1076 + _t1079*_t881 + _t1207 - _t1672 + _t1673*_t194 + _t741*_t877;
  const double _t1757 = _t1446*_t572;
  const double _t1761 = _hc2[3]*_t55;
  const double _t1764 = _t1022*_t1763;
  const double _t1765 = _t443*_t496;
  const double _t1766 = -0.6e1*_hc1[0]*_t100*_t1008*_t9 - _hc1[0]*_t1760*_t93 - 0.12e2*_hc1[0]*_t215*_t53 - 0.24e2*_hc1[0]*_t53*_t567*_t9 - 0.6e1*_hc2[0]*_t100*_t438 - _hc2[0]*_t1759*_t92 - 0.18e2*_hc2[0]*_t215*_t438*_t9 - 0.2e1*_hc2[1]*_t100*_t196*_t3*_t438*_t5*_t9 - 0.2e1 / 0.3e1*_hc2[1]*_t3*_t438*_t496*_t5*_t92 - 0.1e1 / 0.12e2*_hc2[2]*_t219*_t220*_t438*_t494*_t92 + _t1008*_t194*_t98 + _t1022*_t1089*_t92 + _t1057*_t490 + _t1076*_t53*_t98 + _t1078*_t482 + _t1083*_t1761*_t92 + _t1086*_t443*_t92 + _t1150*_t498*_t6 + _t1461*_t1765 + _t1643 + _t1645*_t498 + _t1762*_t7*_t850 + _t1764*_t231 + _t250*_t489*_t847 + _t481*_t490 + _t727*_t95;
  const double _t1767 = _t1030*_t1195 + _t1193 - _t1753 - _t1754;
  const double _t1768 = _hc5[1]*_t727 + _t1029*_t482 + _t1670 - _t1750 - _t1751 + _t1755*_t93 + _t1767;
  const double _t1770 = _t1102*_t1219;
  const double _t1771 = _t138*_t892;
  const double _t1774 = 0.12e2*_t1034;
  const double _t1776 = (0.112e3 / 0.3e1)*_t1663;
  const double _t1777 = _t131*_t702;
  const double _t1778 = _hc9[3]*_t1076 + _t1079*_t930 + _t1311 - _t1695 + _t1696*_t194 + _t741*_t926;
  const double _t1779 = _t1046*_t1195 + _t1298 - _t164*(_hc9[4]*_t1076 + _t1079*_t926 + _t1301 + _t1694*_t194 - _t1697 + _t741*_t927) - _t1752*_t461;
  const double _t1780 = _t1111*_t761;
  const double _t1781 = _t1109*_t171;
  const double _t1783 = _hc10[3]*_t1102;
  const double _t1784 = _t1548*_t1783;
  const double _t1795 = _hc10[6]*_t507;
  const double _t1796 = _t1030*_t1429;
  const double _t1799 = _hc2[1]*_t193;
  const double _t1800 = _hc1[0]*_t1760*_t194 + _hc2[0]*_t1759*_t193 + _hc2[2]*_t1763*_t193*_t438 + _hc2[4]*_t1156*_t56/xc_powr(nb, 16, 3) - _t1025*_t1075 + 0.3e1*_t1075*_t492 + _t1077*_t518 + 0.3e1*_t1078*_t491 + _t1081*_t1153/xc_powi(nb, 5) - _t1082*_t1155*_t1761*_t193 - _t1085*_t1095*_t1159 - _t1088*_t1094*_t1162 - _t1092*_t1798 + _t1118*_t490 + _t1157*_t493/xc_powr(nb, 14, 3) + _t1158*_t195/xc_powr(nb, 13, 3) + _t1160*_t1799*_t438*_t496 - _t1762*_t1799*_t565 + _t1764*_t491 + _t1765*_t1798 + _t1797*_t94 - _t1797*_t95;
  const double _t1801 = _hc5[1]*_t1797 + _t1029*_t518 + _t1118*_t436 + _t1755*_t194 + _t1767;
  const double _t1804 = _t507*_t645;
  const double _t1807 = _t1217*_t892;
  const double _t1812 = (0.448e3 / 0.9e1)*_t1663;
  const double _t1813 = _t1795*_t375;
  const double _t1814 = _t1541*_t507;
  const double _t1815 = _t1682*_t768;
  const double _t1817 = _t1373*_t194;
  const double _t1818 = _t1381*_t514;
  const double _t1820 = 0.36e2*_t1064;
  const double _t1170 = _t253*_t261;
  const double _t1171 = _t110*_t185;
  const double _t1172 = ((_hc12[1]) * (_hc12[1]) * (_hc12[1]) * (_hc12[1]));
  const double _t1173 = _t1172*_t62;
  const double _t1175 = _t1173*_t1174;
  const double _t1188 = _t1172*_t20;
  const double _t1191 = -0.56e2 / 0.135e3*_hc12[1]*_t104*_t112*_t114*_t115*_t14*_t58 + _hc4[0]*_t1180*_t1188*_t280 + (0.65920e5 / 0.81e2)*_hc4[0]*_t1190*_t277 + (0.6592e4 / 0.243e3)*_hc4[2]*_t1184 + (0.80e2 / 0.9e1)*_hc4[2]*_t1186*_t277 + (0.7e1 / 0.6e1)*_t1175*_t226*_t58 + 0.320e3*_t1176*_t615 + _t1177*_t873 + 0.64e2*_t1179*_t126 + (0.4e1 / 0.81e2)*_t1181*_t609 + (0.1280e4 / 0.3e1)*_t1182*_t619 + (0.27136e5 / 0.243e3)*_t1185*_t271 + (0.54272e5 / 0.81e2)*_t1185*_t624 + (0.32e2 / 0.27e2)*_t1187*_t126 + (0.640e3 / 0.27e2)*_t1189*_t619 + (0.26368e5 / 0.81e2)*_t1190*_t622 + (0.28e2 / 0.5e1)*_t215*_t603*_t605 + 0.256e3*_t263*_t613 + (0.112e3 / 0.135e3)*_t406*_t58;
  const double _t1238 = _t131*_t689;
  const double _t1239 = 0.16e2*_t308;
  const double _t1240 = _t666*_t824;
  const double _t1241 = _t257*_t306;
  const double _t1243 = _t142*_t151;
  const double _t1247 = 0.7e1*_t215*_t686;
  const double _t1251 = 0.48e2*_t1250*_t126;
  const double _t1254 = _t1176*_t696;
  const double _t1255 = 0.240e3*_t1254*_t62;
  const double _t1257 = 0.320e3*_t1256*_t619;
  const double _t1258 = (0.14e2 / 0.27e2)*_t314*_t349;
  const double _t1259 = (0.35e2 / 0.24e2)*_t1173*_t227*_t73;
  const double _t1267 = (0.8e1 / 0.9e1)*_t126*_t1266;
  const double _t1268 = (0.20e2 / 0.3e1)*_hc8[2]*_t1265*_t277;
  const double _t1270 = (0.40e2 / 0.3e1)*_t1188*_t1269;
  const double _t1272 = (0.160e3 / 0.9e1)*_t1271*_t619;
  const double _t1273 = (0.3296e4 / 0.27e2)*_t1183*_t684;
  const double _t1275 = (0.8240e4 / 0.27e2)*_t1274*_t315*_t710;
  const double _t1277 = (0.13568e5 / 0.27e2)*_t1276*_t157;
  const double _t1278 = -0.32e2*_hc0[0]*_hc5[0]*_t541*_t567*_t604 - 0.1120e4 / 0.27e2*_hc12[1]*_hc5[0]*_t146*_t226*_t3*_t5 - 0.14e2 / 0.27e2*_hc12[1]*_t104*_t112*_t149*_t3*_t73 - 0.2e1 / 0.3e1*_hc5[0]*_t1136*_t1172*_t3*_t575 - 0.320e3 / 0.9e1*_hc5[0]*_t20*_t218*_t219*_t220*_t255 + _t1247 + _t1249 + _t1251 + _t1253 + _t1255 + _t1257 + _t1258 + _t1259 + _t1261 + _t1263 + _t1264 + _t1267 + _t1268 + _t1270 + _t1272 + _t1273 + _t1275 + _t1277;
  const double _t1279 = _t131*_t724;
  const double _t1280 = _t718*_t85;
  const double _t1281 = _t131*_t731;
  const double _t1283 = 0.16e2*_t113*_t1250;
  const double _t1285 = 0.112e3*_t1254*_t38;
  const double _t1286 = 0.224e3*_t1256*_t605;
  const double _t1290 = (0.8e1 / 0.27e2)*_t113*_t1266;
  const double _t1291 = (0.28e2 / 0.9e1)*_hc8[2]*_t1142*_t808;
  const double _t1292 = (0.112e3 / 0.9e1)*_t1271*_t605;
  const double _t1293 = (0.140e3 / 0.9e1)*_t1173*_t1269;
  const double _t1294 = (0.3296e4 / 0.81e2)*_t1183*_t315*_t734;
  const double _t1295 = (0.11536e5 / 0.81e2)*_t1274*_t736;
  const double _t1296 = (0.13568e5 / 0.81e2)*_t1276*_t151;
  const double _t1297 = -0.1120e4 / 0.27e2*_hc12[1]*_hc5[0]*_t125*_t226*_t3*_t5 - 0.20e2 / 0.3e1*_hc5[0]*_t1136*_t1172*_t20*_t3*_t575 - 0.320e3 / 0.3e1*_hc5[0]*_t146*_t541*_t567*_t604 - 0.1600e4 / 0.27e2*_hc5[0]*_t218*_t219*_t220*_t255*_t62 + _t1282 + _t1283 + _t1284 + _t1285 + _t1286 + _t1287 + _t1288 + _t1289 + _t1290 + _t1291 + _t1292 + _t1293 + _t1294 + _t1295 + _t1296;
  const double _t1353 = _hc11[4]*_t24;
  const double _t1357 = _t379*_t774;
  const double _t1363 = _hc10[10]*_t776;
  const double _t1364 = _hc11[0]*_t791;
  const double _t1365 = _hc11[1]*_t758;
  const double _t1367 = _t1366*_t383;
  const double _t1368 = _t383*_t777;
  const double _t1369 = _t298*_t960;
  const double _t1370 = _t233*_t387;
  const double _t1371 = _t385*_t969;
  const double _t1374 = _hc11[3]*_t766;
  const double _t1375 = 0.12e2*_t789;
  const double _t1376 = _hc11[1]*_t233;
  const double _t1379 = _t1377*_t783;
  const double _t1380 = _hc11[1]*_t374;
  const double _t1383 = _t1068*_t1382;
  const double _t1384 = _hc11[2]*_t774;
  const double _t1386 = _hc11[2]*_t377;
  const double _t1387 = _hc11[1]*_t651;
  const double _t1396 = (0.448e3 / 0.9e1)*_t813;
  const double _t1398 = _hc4[0]*_t1393*_t810;
  const double _t1400 = _t259*_t708*_t812;
  const double _t1402 = _t1401*_t814;
  const double _t1403 = _t1402*_t588;
  const double _t1404 = _t711*_t815;
  const double _t1405 = _hc4[1]*_t813;
  const double _t1406 = -0.560e3 / 0.27e2*_hc4[0]*_t1141*_t1175*_t26*_t28 - 0.8e1 / 0.9e1*_t1177*_t798 - 0.448e3 / 0.3e1*_t1178*_t1405*_t38 - 0.64e2 / 0.3e1*_t1179*_t409 - _t1180*_t616*_t809 - 0.1e1 / 0.81e2*_t1181*_t184 - 0.896e3 / 0.3e1*_t1182*_t810 - 0.92288e5 / 0.243e3*_t1184*_t814 - 0.54272e5 / 0.243e3*_t1185*_t815 - 0.32e2 / 0.81e2*_t1187*_t409 - 0.448e3 / 0.27e2*_t1189*_t810 - 0.26368e5 / 0.243e3*_t1190*_t812 - 0.6784e4 / 0.243e3*_t181*_t184*_t575 - 0.1648e4 / 0.243e3*_t184*_t402*_t579 - _t567*_t607*_t796;
  const double _t1407 = (0.320e3 / 0.3e1)*_t829;
  const double _t1408 = _t824*_t83;
  const double _t1409 = _t1408*_t190;
  const double _t1410 = _t413*_t994;
  const double _t1411 = _t424*_t689;
  const double _t1412 = (0.80e2 / 0.3e1)*_t190;
  const double _t1413 = _t1003*_t105;
  const double _t1414 = _t413*_t821;
  const double _t1415 = _t416*_t817;
  const double _t1416 = _t1001*_t413;
  const double _t1418 = _t1004*_t424;
  const double _t1419 = _t1418*_t190;
  const double _t1420 = _hc0[0]*_t687;
  const double _t1421 = (0.160e3 / 0.3e1)*_t1420*_t425*_t567;
  const double _t1422 = _t1137*_t1172*_t575;
  const double _t1423 = (0.10e2 / 0.9e1)*_t1422*_t425;
  const double _t1424 = _t222*_t255;
  const double _t1426 = (0.3200e4 / 0.81e2)*_t1424*_t20*_t425;
  const double _t1427 = (0.560e3 / 0.9e1)*_t1422*_t25*_t62*_t76/xc_powi(_t22, 8);
  const double _t1428 = -_t1421 + _t1422*_t1425*_t20*_t827 - _t1423 + (0.320e3 / 0.81e2)*_t1424*_t84 + (0.640e3 / 0.3e1)*_t1425*_t146*_t567*_t687*_t76 - _t1426 - _t1427 + (0.1120e4 / 0.81e2)*_t227*_t428;
  const double _t1431 = _t1003*_t429;
  const double _t1433 = _t1407*_t76;
  const double _t1434 = (0.32e2 / 0.9e1)*_t825;
  const double _t1435 = (0.448e3 / 0.27e2)*_t831;
  const double _t1436 = (0.320e3 / 0.9e1)*_t1005 + _t1411*_t827 - _t1432 - _t1433 - _t1434 - _t1435;
  const double _t1462 = _t261*_t446;
  const double _t1463 = -0.2e1 / 0.5e1*_hc12[1]*_t112*_t114*_t115*_t14*_t446*_t79 + _t1098 + _t1191 + (0.7e1 / 0.5e1)*_t1462 + _t586 + _t591 + _t597 + _t598 + _t600;
  const double _t1492 = _t201*_t689;
  const double _t1493 = _t1420*_t727;
  const double _t1495 = _t151*_t202;
  const double _t1498 = _hc8[0]*_t255;
  const double _t1500 = _t1499*_t157;
  const double _t1501 = _t257*_t456;
  const double _t1502 = -0.1e1 / 0.2e1*_hc12[1]*_t112*_t149*_t3*_t456*_t79 - 0.16e2*_hc12[1]*_t122*_t146*_t3*_t450*_t5 + _t1278 + _t1498*_t681 + 0.80e2*_t1500 + _t1501*_t671 - 0.6e1*_t20*_t219*_t220*_t255*_t310*_t450 + _t662 + _t670 + _t675 + _t685;
  const double _t1503 = _t201*_t724;
  const double _t1504 = _t201*_t731;
  const double _t1505 = _t1498*_t349;
  const double _t1506 = _t1499*_t151;
  const double _t1507 = -0.16e2*_hc12[1]*_t122*_t125*_t3*_t450*_t5 + _t1108 + _t1297 + (0.28e2 / 0.3e1)*_t1505 + (0.80e2 / 0.3e1)*_t1506 - 0.10e2*_t219*_t220*_t255*_t310*_t450*_t62 + _t715 + _t720 + _t723;
  const double _t1560 = _t377*_t379;
  const double _t1563 = _t767*_t966;
  const double _t1564 = _t93*_t952;
  const double _t1565 = _t1564*_t194;
  const double _t1566 = _hc11[1]*_t473;
  const double _t1568 = _t1334*_t1364;
  const double _t1569 = _hc11[1]*_t1567;
  const double _t1570 = 0.36e2*_hc11[0];
  const double _t1572 = _t1570*_t1571;
  const double _t1575 = _hc11[1]*_t1574;
  const double _t1576 = _hc10[6]*_t176;
  const double _t1577 = _t1576*_t382;
  const double _t1578 = _t1576*_t194;
  const double _t1579 = _t386*_t388;
  const double _t1580 = _t1579*_t476;
  const double _t1581 = _t169*_t383;
  const double _t1582 = _t1581*_t482;
  const double _t1583 = _hc11[2]*_t390;
  const double _t1584 = _hc11[2]*_t476;
  const double _t1585 = _hc11[3]*_t378;
  const double _t1586 = _t377*_t778;
  const double _t1589 = _hc11[2]*_t788*_t950;
  const double _t1590 = _t1561*_t783;
  const double _t1591 = _hc11[0]*_t386;
  const double _t1592 = _t1591*_t975;
  const double _t1595 = _hc11[1]*_t231;
  const double _t1597 = _hc11[0]*_t1596;
  const double _t1599 = _t478*_t792;
  const double _t1606 = _t1394*_t409;
  const double _t1608 = _t409*_t590;
  const double _t1610 = _t1397*_t813;
  const double _t1613 = _t1405*_t1612;
  const double _t1614 = _t485*_t806*_t810;
  const double _t1617 = _t1401*_t812*na;
  const double _t1618 = _t1402*_t1611;
  const double _t1619 = _t1615*_t815;
  const double _t1621 = -0.4e1 / 0.9e1*_t1620 - _t797 - 0.40e2 / 0.9e1*_t799 - _t801 - _t802 - _t804;
  const double _t1622 = _t190*_t829;
  const double _t1623 = _t1411*_t190;
  const double _t1624 = _t207*_t829;
  const double _t1625 = _t1408*_t207;
  const double _t1626 = _t487*_t994;
  const double _t1627 = _t416*_t992;
  const double _t1628 = _t1002*_t105;
  const double _t1629 = _t487*_t821;
  const double _t1630 = (0.20e2 / 0.3e1)*_t1629;
  const double _t1631 = _t1001*_t487;
  const double _t1632 = _t1418*_t207;
  const double _t1633 = 0.8e1*_t999;
  const double _t1648 = _t261*_t501;
  const double _t1649 = _t185*_t199;
  const double _t1655 = _t697*na;
  const double _t1656 = _t696*_t704;
  const double _t1657 = _hc5[0]*_t1422;
  const double _t1661 = _t277*_t733;
  const double _t1662 = (0.224e3 / 0.9e1)*_t147;
  const double _t1664 = _t824*_t902;
  const double _t1666 = _t147*_t836;
  const double _t1667 = _t20*_t901;
  const double _t1668 = _t255*_t318;
  const double _t1669 = 0.8e1*_t308;
  const double _t1690 = (0.224e3 / 0.9e1)*_t126;
  const double _t1691 = _t126*_t836;
  const double _t1692 = 0.8e1*_t337;
  const double _t1718 = _t379*_t473;
  const double _t1722 = 0.12e2*_t1591;
  const double _t1723 = 0.12e2*_t958;
  const double _t1725 = _hc11[2]*_t174;
  const double _t1726 = _hc11[2]*_t205;
  const double _t1728 = _hc11[3]*_t517*_t788;
  const double _t1729 = _t388*_t489;
  const double _t1730 = 0.12e2*_t954;
  const double _t1731 = _t473*_t778;
  const double _t1734 = _hc10[6]*_t1383;
  const double _t1738 = _t1595*_t476;
  const double _t1741 = _t1740*_t409;
  const double _t1742 = 0.72e2*_t1146*_t381 + _t1406;
  const double _t1743 = _t521*_t994;
  const double _t1744 = _t1411*_t207;
  const double _t1745 = _t521*_t821;
  const double _t1746 = _t1070*_t416;
  const double _t1747 = _t1001*_t521;
  const double _t1749 = -0.80e2 / 0.3e1*_hc0[0]*_t215*_t423*_t541*_t604*_t61*_t76 + _t1432 + _t1433 + _t1434 + _t1435 - 0.320e3 / 0.9e1*_t20*_t219*_t220*_t255*_t266*_t423*_t61*_t76;
  const double _t1756 = _t1125*_t416;
  const double _t1775 = _t257*_t509;
  const double _t1787 = _hc11[3]*_t1114;
  const double _t1789 = _t1584*_t178;
  const double _t1790 = _hc10[3]*_t781;
  const double _t1791 = _t516*_t778;
  const double _t1792 = _t1059*_t1561;
  const double _t1793 = _t1119*_t1377;
  const double _t1794 = _t1059*_t1377;
  const double _t1816 = _t507*_t960;
  const double _t1819 = _hc11[1]*_t1719;
  const double _t1821 = _t1726*_t1817;
  const double _t1822 = _t507*_t793;
  const double d4F_dna4 = _t1*(_t1210 - _t1407*_t190 - 0.32e2 / 0.9e1*_t1409 + (0.4e1 / 0.3e1)*_t1410 + _t1411*_t1412 - 0.448e3 / 0.27e2*_t1413 - 0.40e2 / 0.3e1*_t1414 - 0.16e2 / 0.3e1*_t1415 + _t1416*_t1417 + (0.320e3 / 0.9e1)*_t1419 + _t1428 - _t23*(_t1148*_t206 + _t1213*_t1363 + _t1213*_t1367 + _t1221*_t387 + _t1221*_t519 + _t1224*_t1369 + _t1224*_t953 + _t1224*_t978 + _t1227*_t1369 + _t1227*_t953 + _t1227*_t978 + _t1229*_t1369 + _t1229*_t1379 + _t1229*_t953 + _t1229*_t978 + _t1232*_t1371 + _t1235*_t479 + _t1235*_t480 + _t1322*_t1390*_t789 + _t1325*_t1383 + _t1335*_t1364 + _t1353*(_t174 * _t174 * _t174 * _t174) + _t1357*_t377 + _t1362*_t1380*_t1381 + _t1362*_t951 + 0.36e2*_t1362*_t963 + 0.24e2*_t1365*_t788 + _t1368*_t651 + _t1370*_t651 + _t1372*_t976 + _t1372*_t979 + _t1373*_t1374*_t785 + _t1373*_t765*_t778 + _t1375*_t169*_t755 + _t1376*_t1378 + _t1376*_t1389 + 0.12e2*_t1376*_t970 + _t1381*_t374*_t783 + _t1384*_t1385 + _t1385*_t1386 + _t1387*_t1389 + 0.64e2*_t1391 + (0.8e1 / 0.27e2)*_t1392 + _t1394*_t803 + (0.112e3 / 0.27e2)*_t1395 + _t1396*_t1397 + (0.896e3 / 0.9e1)*_t1398 + (0.1888e4 / 0.81e2)*_t1399 + (0.1792e4 / 0.27e2)*_t1400 + (0.6272e4 / 0.27e2)*_t1403 + (0.15104e5 / 0.81e2)*_t1404 + _t1406 + _t175*(-_t1148*_t173 - _t1213*_t1319 + _t1221*_t464 - _t1221*_t468 - _t1224*_t1348 + _t1224*_t1350 - _t1224*_t1352 - _t1227*_t1348 + _t1227*_t1350 - _t1227*_t1352 - _t1229*_t1348 + _t1229*_t1350 - _t1229*_t1352 + _t1232*_t1344 - _t1232*_t947 + _t1235*_t465 - _t1235*_t764 + _t1314 + (0.91e2 / 0.108e3)*_t1315 - _t1316*_t1317 - _t1317*_t1320 + _t1318*_t531 + _t1321*_t769 - 0.2e1*_t1324 + _t1325*_t1327 + _t1328*_t1329 - _t1328*_t1339 + 0.2e1*_t1330 + (0.7e1 / 0.6e1)*_t1333 + _t1335*_t1336 + _t1340*_t1341 - _t1340*_t1343 + _t1341*_t1342 - _t1342*_t1343 - _t1345*_t651 + _t1346*_t651) + _t25*(_hc9[1]*_t1148 + _t1195*_t747 + _t1298 - 0.14e2 / 0.9e1*_t1299 - _t164*(_hc9[4]*_t531 + _t1301 + _t1309*_t93 - _t164*(_hc9[8]*_t233 + _t1302 + _t1305*_t93 - _t164*(_hc9[13]*_t93 + _t1303)) + _t534*_t746 + _t741*_t744) + _t361*_t775 + _t380*_t751 + _t93*(_hc9[3]*_t531 - _t1309*_t164 + _t1311 + _t534*_t750 + _t741*_t746 + _t93*(_hc9[6]*_t233 - _t1308*_t164 + _t1312 + _t93*(_hc9[10]*_t93 + _t1313)))) + _t37*((0.3776e4 / 0.27e2)*_hc12[1]*_hc8[0]*_t112*_t149*_t226*_t3*nb + (0.224e3 / 0.9e1)*_hc12[1]*_hc8[1]*_t112*_t218*_t219*_t4*nb + (0.16e2 / 0.3e1)*_hc12[1]*_hc8[2]*_t112*_t567*nb + 0.32e2*_hc12[1]*_t122*_t125*_t294*_t3*_t5 + (0.224e3 / 0.3e1)*_hc8[0]*_t125*_t567*_t604*nb + 0.48e2*M_PI*_hc8[0]*_t215*_t29*nb + (0.784e3 / 0.9e1)*_hc8[0]*_t218*_t219*_t255*_t38*_t4*nb + (0.472e3 / 0.27e2)*_hc8[1]*_t149*_t226*_t29*_t3*nb + (0.112e3 / 0.3e1)*_hc8[1]*_t255*_t38*_t567*nb + (0.14e2 / 0.9e1)*_hc8[2]*_t218*_t219*_t29*_t4*nb + (0.2e1 / 0.9e1)*_hc8[3]*_t29*_t567*nb + 0.4e1*_t1210*_t38 - _t1246*_t126 - 0.160e3 / 0.3e1*_t1279 - _t1280*_t642 - 0.160e3 / 0.3e1*_t1281 - _t1297 + 0.20e2*_t219*_t220*_t255*_t294*_t310*_t62) + (_t377 * _t377)*_t379 + _t44*((0.15104e5 / 0.27e2)*_hc12[1]*_hc4[0]*_t114*_t115*_t125*_t14*_t226*nb + (0.1792e4 / 0.9e1)*_hc12[1]*_hc4[1]*_t125*_t15*_t218*_t258*_t67*nb + (0.64e2 / 0.3e1)*_hc12[1]*_hc4[2]*_t125*_t30*_t567*_t601*nb + (0.4e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t2*_t583 + (0.4e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t253*_t79 + (0.1280e4 / 0.9e1)*_hc4[0]*_t146*_t30*_t567*_t601*_t604*nb + (0.4480e4 / 0.9e1)*_hc4[0]*_t15*_t218*_t255*_t258*_t62*_t67*nb + 0.256e3*_hc4[0]*_t215*_t30*_t31*_t38*nb + (0.7552e4 / 0.81e2)*_hc4[1]*_t114*_t115*_t14*_t226*_t38*nb + (0.320e3 / 0.3e1)*_hc4[1]*_t255*_t30*_t567*_t601*_t62*nb + (0.448e3 / 0.27e2)*_hc4[2]*_t15*_t218*_t258*_t38*_t67*nb + (0.32e2 / 0.27e2)*_hc4[3]*_t30*_t38*_t567*_t601*nb + (0.28e2 / 0.5e1)*_t100*_t110*_t125*_t30*_t601*_t604 + (0.28e2 / 0.15e2)*_t110*_t15*_t255*_t258*_t310*_t38*_t67 - _t1128*_t583 - 0.14e2 / 0.5e1*_t1170 - 0.32e2 / 0.45e2*_t1171 - _t1191 - _t447*(-_t1129*_t840 - _t1130*_t572 - _t1131*_t845 + _t1145 + _t1169 - _t322*_t581)) + 0.2e1*_t474*_t765 + _t474*(0.6e1*_hc10[1]*_hc10[3]*_t12*_t13*_t15*_t18*_t369*_t644*p->cam_omega + (0.1e1 / 0.2e1)*_hc10[1]*_t12*_t13*_t15*_t166*_t170*_t233*p->cam_omega + (0.1e1 / 0.2e1)*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t298*p->cam_omega + 0.2e1*_t12*_t13*_t15*_t18*_t233*_t368*_t369*_t93*p->cam_omega + 0.2e1*_t12*_t13*_t15*_t18*_t368*_t369*_t651*_t93*p->cam_omega - _t1354 - _t1355*_t759 - _t1356*_t233 - _t1356*_t651 - _t531*_t768 - 0.7e1 / 0.12e2*_t754 - _t755*_t771 - _t763) + _t61*((0.3776e4 / 0.9e1)*_hc12[1]*_hc8[0]*_t125*_t149*_t226*_t3*nb + (0.224e3 / 0.3e1)*_hc12[1]*_hc8[1]*_t125*_t218*_t219*_t4*nb + 0.16e2*_hc12[1]*_hc8[2]*_t125*_t567*nb + _hc12[1]*_t112*_t149*_t2*_t3*_t659 + _hc12[1]*_t112*_t149*_t3*_t306*_t79 + 0.32e2*_hc12[1]*_t122*_t146*_t294*_t3*_t5 + (0.320e3 / 0.3e1)*_hc8[0]*_t146*_t567*_t604*nb + 0.192e3*M_PI*_hc8[0]*_t215*_t38*nb + (0.560e3 / 0.3e1)*_hc8[0]*_t218*_t219*_t255*_t4*_t62*nb + (0.1888e4 / 0.27e2)*_hc8[1]*_t149*_t226*_t3*_t38*nb + 0.80e2*_hc8[1]*_t255*_t567*_t62*nb + (0.56e2 / 0.9e1)*_hc8[2]*_t218*_t219*_t38*_t4*nb + (0.8e1 / 0.9e1)*_hc8[3]*_t38*_t567*nb + 0.7e1*_t100*_t125*_t142*_t604 + 0.6e1*_t1210*_t62 - _t1211*_t659 - 0.16e2*_t1238 - _t1239*_t642 - 0.32e2*_t1240 - _t1241*_t1242 - _t1243*_t1244 - _t1246*_t147 - _t1278 + (0.7e1 / 0.6e1)*_t142*_t219*_t255*_t310*_t38*_t4 + 0.12e2*_t20*_t219*_t220*_t255*_t294*_t310 - _t457*(-_t1129*_t1212 - _t1130*_t654 - _t1131*_t1215 - _t1148*_t134 + _t1169 - _t1213*_t1214 - 0.32e2 / 0.135e3*_t1216 - _t1217*_t1220 - _t1218*_t531 - _t1221*_t454 - _t1224*_t1225 - _t1225*_t1227 - _t1225*_t1229 + _t1230*_t866 - _t1231*_t233 - _t1231*_t651 - _t1232*_t1233 - _t1235*_t455 - _t1236*_t651 + _t1237 - _t322*_t656 + _t649*_t866)) + _t651*_t970*_t973 + 0.36e2*_t783*_t794 + _t951*(_t1318*_t785 - _t1361 + _t773) + _t951*(_t1358 + _t1359*_t1360 - 0.3e1 / 0.2e1*_t1361 + 0.3e1*_t373 - 0.3e1 / 0.2e1*_t772))) - _t1412*_t821 - _t1429*_t639 + (0.16e2 / 0.9e1)*_t1430 + (0.64e2 / 0.3e1)*_t1431 + _t1436 + 0.8e1*_t233*_t289 + 0.4e1*_t628 + 0.4e1*_t635 - 0.4e1*_t818 - 0.16e2*_t820 + (0.8e1 / 0.3e1)*_t996;
  const double d4F_dna3_dnb = _t1*(-_t1003*_t702 - 0.8e1 / 0.3e1*_t1409 + (0.2e1 / 0.3e1)*_t1410 + _t1412*_t1418 - 0.20e2 / 0.3e1*_t1414 - 0.4e1 / 0.3e1*_t1415 + _t1416*_t836 + _t1428 + _t1472 - 0.80e2*_t1622 + 0.20e2*_t1623 - 0.80e2 / 0.3e1*_t1624 - 0.8e1 / 0.9e1*_t1625 + (0.2e1 / 0.3e1)*_t1626 - 0.4e1*_t1627 - 0.112e3 / 0.27e2*_t1628 - _t1630 + _t1631*_t836 + (0.80e2 / 0.9e1)*_t1632 + _t207*_t424*_t997 - _t23*(_t1067*_t775 + _t1322*_t792*_t958 + _t1347*_t1597 + _t1353*_t766*_t950 + _t1357*_t473 + _t1363*_t1474 + _t1365*_t962 + _t1367*_t1474 + _t1374*_t956 + _t1378*_t1595 + _t1379*_t231 + _t1380*_t1567*_t787 + _t1383*_t1544 + _t1384*_t1573 + _t1386*_t1573 + _t1387*_t1574*_t382 + 0.72e2*_t1388*_t1595 + (0.28e2 / 0.9e1)*_t1395 + (0.224e3 / 0.3e1)*_t1398 + (0.472e3 / 0.27e2)*_t1399 + (0.448e3 / 0.9e1)*_t1400 + (0.1568e4 / 0.9e1)*_t1403 + (0.3776e4 / 0.27e2)*_t1404 + _t1406 + _t1437*_t206 + _t1474*_t1568 + _t1475*_t479 + _t1475*_t480 + _t1487*_t1564 + _t1487*_t1577 + _t1487*_t1599 + _t1560*_t473 + _t1563*_t377 + _t1563*_t774 + _t1565*_t233 + _t1566*_t782 + _t1569*_t795 + _t1572*_t298 + _t1575*_t777 + _t1578*_t777 + _t1580*_t233 + _t1580*_t651 + _t1582*_t233 + _t1582*_t651 + _t1583*_t779*_t948 + _t1584*_t780 + _t1585*_t786*_t950 + _t1586*_t1588 + _t1586*_t1593 + _t1587*_t1590 + _t1587*_t781*_t936 + _t1589*_t374*_t787 + _t1589*_t795 + _t1590*_t1594 + _t1592*_t233 + _t1592*_t651 + _t1593*_t233*_t781 + 0.36e2*_t1595*_t970 + 0.16e2*_t1598 + _t1599*_t936 + _t1600*nb + 0.54e2*_t1601*_t790 + _t1603*_t384 + _t1604*_t844 + (0.2e1 / 0.27e2)*_t1605 + (0.16e2 / 0.3e1)*_t1606 + _t1607*_t1608 + (0.28e2 / 0.27e2)*_t1609 + (0.112e3 / 0.3e1)*_t1610 + (0.112e3 / 0.9e1)*_t1613 + (0.224e3 / 0.9e1)*_t1614 + (0.472e3 / 0.81e2)*_t1616 + (0.448e3 / 0.27e2)*_t1617 + (0.1568e4 / 0.27e2)*_t1618 + (0.3776e4 / 0.81e2)*_t1619 + _t1621 + _t175*((0.91e2 / 0.144e3)*_t1315 - _t1316*_t1517 + _t1317*_t1332 - _t1319*_t1474 - _t1320*_t1517 + _t1321*_t167 - 0.1e1 / 0.2e1*_t1324 + _t1327*_t1544 + (0.1e1 / 0.2e1)*_t1330 - _t1340*_t1534 + _t1340*_t1537 - _t1342*_t1534 + _t1342*_t1537 - _t1437*_t173 + _t1474*_t1531 + _t1474*_t1532 - _t1474*_t1540 + _t1475*_t465 - _t1475*_t764 + 0.2e1*_t1476*_t1530 - _t1476*_t940 - _t1478*_t940 - _t1488*_t1541 - _t1488*_t1550 + _t1488*_t1552 - 0.7e1 / 0.12e2*_t1516 + _t1518*_t1535 + _t1518*_t1536 + _t1519*_t839 + _t1520*_t531 + (0.91e2 / 0.432e3)*_t1521 + _t1523 + _t1524*_t464 - _t1524*_t468 - _t1525*_t1526 - _t1525*_t1528 - 0.2e1*_t1529 + _t1530*_t534*_t9 - 0.1e1 / 0.2e1*_t1533 + (0.3e1 / 0.2e1)*_t1539 - _t1542*_t1543 + _t1542*_t1553 + _t1547*_t374 - 0.3e1 / 0.2e1*_t1549 - _t1551*_t936 + _t1556 + _t465*_t839 - _t764*_t839) + _t25*(_hc9[1]*_t1437 - 0.28e2 / 0.27e2*_t1299 + _t1442*_t361 + _t1515 - _t164*(_hc9[4]*_t839 + _t1301 + _t1511*_t93 - _t164*(_hc9[8]*_t232 + _t1509*_t93 + _t1514) + _t232*_t746 + _t233*_t926 + _t356*_t744 + _t356*_t927) + _t232*_t751 + _t356*_t747 + _t460*_t531 - _t461*_t738 + _t534*_t932 + _t93*(_hc9[3]*_t839 + _t1311 - _t1511*_t164 + _t232*_t750 + _t233*_t930 + _t356*_t746 + _t356*_t926 + _t93*(_hc9[6]*_t232 + _t1512*_t93 + _t1513))) + _t37*((0.944e3 / 0.27e2)*_hc12[1]*_hc8[0]*_t112*_t149*_t226*_t3*na + (0.944e3 / 0.9e1)*_hc12[1]*_hc8[0]*_t112*_t149*_t226*_t3*nb + (0.56e2 / 0.9e1)*_hc12[1]*_hc8[1]*_t112*_t218*_t219*_t4*na + (0.56e2 / 0.3e1)*_hc12[1]*_hc8[1]*_t112*_t218*_t219*_t4*nb + (0.4e1 / 0.3e1)*_hc12[1]*_hc8[2]*_t112*_t567*na + 0.4e1*_hc12[1]*_hc8[2]*_t112*_t567*nb + 0.16e2*_hc12[1]*_t122*_t125*_t294*_t3*_t5 + (0.56e2 / 0.3e1)*_hc8[0]*_t125*_t567*_t604*na + 0.56e2*_hc8[0]*_t125*_t567*_t604*nb + 0.12e2*M_PI*_hc8[0]*_t215*_t29*na + 0.36e2*M_PI*_hc8[0]*_t215*_t29*nb + (0.196e3 / 0.9e1)*_hc8[0]*_t218*_t219*_t255*_t38*_t4*na + (0.196e3 / 0.3e1)*_hc8[0]*_t218*_t219*_t255*_t38*_t4*nb + (0.118e3 / 0.27e2)*_hc8[1]*_t149*_t226*_t29*_t3*na + (0.118e3 / 0.9e1)*_hc8[1]*_t149*_t226*_t29*_t3*nb + (0.28e2 / 0.3e1)*_hc8[1]*_t255*_t38*_t567*na + 0.28e2*_hc8[1]*_t255*_t38*_t567*nb + (0.7e1 / 0.18e2)*_hc8[2]*_t218*_t219*_t29*_t4*na + (0.7e1 / 0.6e1)*_hc8[2]*_t218*_t219*_t29*_t4*nb + (0.1e1 / 0.18e2)*_hc8[3]*_t29*_t567*na + (0.1e1 / 0.6e1)*_hc8[3]*_t29*_t567*nb - _t126*_t1496 - _t126*_t1497 - 0.40e2*_t1279 - 0.40e2*_t1281 + 0.4e1*_t1472*_t38 - _t1494*_t337 - 0.40e2 / 0.3e1*_t1503 - 0.40e2 / 0.3e1*_t1504 - _t1507 + 0.10e2*_t219*_t220*_t255*_t294*_t310*_t62 - _t459*_t642) + _t44*((0.3776e4 / 0.27e2)*_hc12[1]*_hc4[0]*_t114*_t115*_t125*_t14*_t226*na + (0.3776e4 / 0.9e1)*_hc12[1]*_hc4[0]*_t114*_t115*_t125*_t14*_t226*nb + (0.448e3 / 0.9e1)*_hc12[1]*_hc4[1]*_t125*_t15*_t218*_t258*_t67*na + (0.448e3 / 0.3e1)*_hc12[1]*_hc4[1]*_t125*_t15*_t218*_t258*_t67*nb + (0.16e2 / 0.3e1)*_hc12[1]*_hc4[2]*_t125*_t30*_t567*_t601*na + 0.16e2*_hc12[1]*_hc4[2]*_t125*_t30*_t567*_t601*nb + (0.1e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t2*_t583 + (0.3e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t2*_t858 + (0.2e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t253*_t79 + (0.320e3 / 0.9e1)*_hc4[0]*_t146*_t30*_t567*_t601*_t604*na + (0.320e3 / 0.3e1)*_hc4[0]*_t146*_t30*_t567*_t601*_t604*nb + (0.1120e4 / 0.9e1)*_hc4[0]*_t15*_t218*_t255*_t258*_t62*_t67*na + (0.1120e4 / 0.3e1)*_hc4[0]*_t15*_t218*_t255*_t258*_t62*_t67*nb + 0.64e2*_hc4[0]*_t215*_t30*_t31*_t38*na + 0.192e3*_hc4[0]*_t215*_t30*_t31*_t38*nb + (0.1888e4 / 0.81e2)*_hc4[1]*_t114*_t115*_t14*_t226*_t38*na + (0.1888e4 / 0.27e2)*_hc4[1]*_t114*_t115*_t14*_t226*_t38*nb + (0.80e2 / 0.3e1)*_hc4[1]*_t255*_t30*_t567*_t601*_t62*na + 0.80e2*_hc4[1]*_t255*_t30*_t567*_t601*_t62*nb + (0.112e3 / 0.27e2)*_hc4[2]*_t15*_t218*_t258*_t38*_t67*na + (0.112e3 / 0.9e1)*_hc4[2]*_t15*_t218*_t258*_t38*_t67*nb + (0.8e1 / 0.27e2)*_hc4[3]*_t30*_t38*_t567*_t601*na + (0.8e1 / 0.9e1)*_hc4[3]*_t30*_t38*_t567*_t601*nb + (0.21e2 / 0.5e1)*_t100*_t110*_t125*_t30*_t601*_t604 + (0.7e1 / 0.5e1)*_t100*_t125*_t199*_t30*_t601*_t604 + (0.7e1 / 0.5e1)*_t110*_t15*_t255*_t258*_t310*_t38*_t67 - 0.7e1 / 0.5e1*_t1170 - 0.8e1 / 0.15e2*_t1171 - _t1463 + (0.7e1 / 0.15e2)*_t15*_t199*_t255*_t258*_t310*_t38*_t67 - _t199*_t608 - _t447*(_hc1[0]*_t232*_t233 + _hc1[1]*_t1458*_t566 + _hc1[2]*_t1458*_t563 + _hc2[0]*_t537*_t838 + _t1145 + _t1152*_t232 + _t1165*_t231 + _t1168*_t1461 + _t1437*_t94 + _t1438*_t240 + _t1439*_t238 + _t1440*_t95 - _t1441*_t840 + _t1442*_t535 - _t1443 - _t1444 - _t1445*_t572 - _t1446*_t573 - _t1447*_t845 - _t1448 - _t1449 - _t1450 - _t1451 - _t1454 - _t1455 - _t1456 - _t1457 - _t1459 - _t1460 + _t490*_t531 + _t492*_t530 + _t538 + _t553 + _t554 - _t569 - _t578 - _t581*_t719 - _t581*_t920) - _t527*_t858 - _t584) + _t474*_t946 + _t474*(0.6e1*_hc10[1]*_hc10[3]*_t12*_t13*_t15*_t18*_t298*_t369*_t886*p->cam_omega + (0.1e1 / 0.6e1)*_hc10[1]*_t12*_t13*_t15*_t166*_t170*_t233*p->cam_omega + (0.2e1 / 0.3e1)*_hc10[1]*_t12*_t13*_t15*_t170*_t9*_t933*p->cam_omega + (0.1e1 / 0.6e1)*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t298*p->cam_omega - _t1050 + 0.2e1*_t12*_t13*_t15*_t18*_t194*_t233*_t368*_t369*p->cam_omega + 0.8e1*_t12*_t13*_t15*_t368*_t369*_t469*_t9*_t93*p->cam_omega - _t1557*_t938 - _t1558*_t942 - _t1559 - 0.7e1 / 0.18e2*_t754 - 0.1e1 / 0.3e1*_t763 - _t768*_t839 - _t771*_t937 - _t936*_t947) + _t477*_t765 + _t479*_t839 + _t480*_t839 + _t531*_t961 + _t61*((0.944e3 / 0.9e1)*_hc12[1]*_hc8[0]*_t125*_t149*_t226*_t3*na + (0.944e3 / 0.3e1)*_hc12[1]*_hc8[0]*_t125*_t149*_t226*_t3*nb + (0.56e2 / 0.3e1)*_hc12[1]*_hc8[1]*_t125*_t218*_t219*_t4*na + 0.56e2*_hc12[1]*_hc8[1]*_t125*_t218*_t219*_t4*nb + 0.4e1*_hc12[1]*_hc8[2]*_t125*_t567*na + 0.12e2*_hc12[1]*_hc8[2]*_t125*_t567*nb + (0.1e1 / 0.4e1)*_hc12[1]*_t112*_t149*_t2*_t3*_t659 + (0.3e1 / 0.4e1)*_hc12[1]*_t112*_t149*_t2*_t3*_t899 + (0.1e1 / 0.2e1)*_hc12[1]*_t112*_t149*_t3*_t306*_t79 + 0.16e2*_hc12[1]*_t122*_t146*_t294*_t3*_t5 + (0.80e2 / 0.3e1)*_hc8[0]*_t146*_t567*_t604*na + 0.80e2*_hc8[0]*_t146*_t567*_t604*nb + 0.48e2*M_PI*_hc8[0]*_t215*_t38*na + 0.144e3*M_PI*_hc8[0]*_t215*_t38*nb + (0.140e3 / 0.3e1)*_hc8[0]*_t218*_t219*_t255*_t4*_t62*na + 0.140e3*_hc8[0]*_t218*_t219*_t255*_t4*_t62*nb + (0.472e3 / 0.27e2)*_hc8[1]*_t149*_t226*_t3*_t38*na + (0.472e3 / 0.9e1)*_hc8[1]*_t149*_t226*_t3*_t38*nb + 0.20e2*_hc8[1]*_t255*_t567*_t62*na + 0.60e2*_hc8[1]*_t255*_t567*_t62*nb + (0.14e2 / 0.9e1)*_hc8[2]*_t218*_t219*_t38*_t4*na + (0.14e2 / 0.3e1)*_hc8[2]*_t218*_t219*_t38*_t4*nb + (0.2e1 / 0.9e1)*_hc8[3]*_t38*_t567*na + (0.2e1 / 0.3e1)*_hc8[3]*_t38*_t567*nb + (0.21e2 / 0.4e1)*_t100*_t125*_t142*_t604 + (0.7e1 / 0.4e1)*_t100*_t125*_t202*_t604 - _t1004*_t511 - 0.24e2*_t1240 - _t1241*_t671 - _t1243*_t835 - _t131*_t1493 + (0.7e1 / 0.8e1)*_t142*_t219*_t255*_t310*_t38*_t4 - _t147*_t1496 - _t147*_t1497 + 0.6e1*_t1472*_t62 - 0.4e1*_t1492 - _t1494*_t308 - _t1495*_t285 - _t1502 + 0.6e1*_t20*_t219*_t220*_t255*_t294*_t310 + (0.7e1 / 0.24e2)*_t202*_t219*_t255*_t310*_t38*_t4 - _t457*(0.2e1*_hc1[0]*_t100*_t233*_t9 + 0.2e1*_hc1[0]*_t100*_t532*_t9 + _hc1[0]*_t1437*_t53 + _hc1[0]*_t1439*_t93 + 0.2e1*_hc1[0]*_t237*_t839 + _hc1[0]*_t439*_t531 + (0.4e1 / 0.3e1)*_hc1[1]*_t100*_t246*_t3*_t5*_t53*_t9 + (0.2e1 / 0.3e1)*_hc1[1]*_t246*_t3*_t439*_t5*_t93 + (0.1e1 / 0.6e1)*_hc1[2]*_t100*_t219*_t220*_t242*_t53*_t9 + (0.1e1 / 0.12e2)*_hc1[2]*_t219*_t220*_t242*_t439*_t93 + _hc2[0]*_t1438*_t92 + _hc2[0]*_t1440*_t55 + 0.2e1*_hc2[0]*_t236*_t838 + _hc2[0]*_t438*_t530 + (0.4e1 / 0.15e2)*_hc7[1]*_t226*_t67*_t70*_t9 + (0.2e1 / 0.15e2)*_hc7[1]*_t233*_t67*_t70*_t79 + (0.2e1 / 0.15e2)*_hc7[3]*_t298*_t67*_t70*_t79 - _t1212*_t1441 - _t1214*_t1474 - _t1215*_t1447 - 0.8e1 / 0.45e2*_t1216 - _t1220*_t138 - _t134*_t1437 - _t1443 - _t1444 - _t1445*_t654 - _t1448 - _t1449 - _t1450 - _t1451 - _t1454 - _t1455 - _t1456 - _t1457 - _t1459 - _t1460 - 0.1e1 / 0.9e1*_t1473 - _t1475*_t455 - _t1476*_t1477 - _t1477*_t1478 - _t1479*_t647 - _t1480*_t647 - _t1481*_t233 - _t1481*_t651 - _t1482*_t1484 - _t1485*_t1486*_t93 - _t1488*_t1489 - _t1490*_t936 - _t1491 - _t452*_t653 - _t455*_t839 - _t531*_t888 - _t531*_t891 - _t646*_t839 - _t652 - _t656*_t719 - _t656*_t920 - _t657) - _t458*_t642 - _t643*_t899 - _t660) + _t755*_t959 + _t765*_t949 + _t775*_t955 + _t778*_t779*_t946 + _t779*_t781*_t839 + _t782*_t967 + _t787*_t789*_t937 + 0.18e2*_t789*_t942 + _t951*(_t1358 + _t1360*_t1518 + _t1519*_t886 - 0.3e1 / 0.2e1*_t1561*_t947 + 0.3e1*_t1562 - 0.3e1*_t471))) + _t1002*_t836 + _t1006*_t835 - _t1074 + (0.10e2 / 0.9e1)*_t1430 + 0.16e2*_t1431 + _t1436 - _t1633 + _t190*_t83*_t901 + _t289*_t482 + _t641 - _t818 - 0.8e1*_t820 - 0.20e2*_t822 - _t834*_t880 + 0.3e1*_t875 + 0.3e1*_t876 + 0.3e1*_t884 - 0.3e1*_t993 + (0.2e1 / 0.3e1)*_t995;
  const double d4F_dna2_dnb2 = (0.32e2 / 0.3e1)*_hc0[0]*_hc12[1]*_t122*_t190*_t21*_t3*_t5*_t82 + (0.32e2 / 0.3e1)*_hc0[0]*_hc12[1]*_t122*_t207*_t21*_t3*_t5*_t82 - 0.4e1*_hc5[1]*_t100 - _hc5[1]*_t1234 + 0.2e1*_hc5[1]*_t839 + _t1*(-0.16e2 / 0.9e1*_t1409 + (0.2e1 / 0.9e1)*_t1410 - 0.224e3 / 0.27e2*_t1413 - 0.20e2 / 0.9e1*_t1414 + _t1416*_t430 + (0.160e3 / 0.9e1)*_t1419 + _t1428 - 0.160e3 / 0.3e1*_t1622 + (0.40e2 / 0.3e1)*_t1623 - 0.160e3 / 0.3e1*_t1624 - 0.16e2 / 0.9e1*_t1625 + (0.8e1 / 0.9e1)*_t1626 - 0.8e1 / 0.3e1*_t1627 - 0.224e3 / 0.27e2*_t1628 - 0.80e2 / 0.9e1*_t1629 + (0.64e2 / 0.9e1)*_t1631*_t429 + (0.160e3 / 0.9e1)*_t1632 + _t1676 + (0.2e1 / 0.9e1)*_t1743 + (0.40e2 / 0.3e1)*_t1744 - 0.20e2 / 0.9e1*_t1745 - 0.8e1 / 0.3e1*_t1746 + _t1747*_t430 - _t23*(_hc11[1]*_t1362*_t1721 + _hc11[1]*_t169*_t937*_t962 + _hc11[1]*_t1720*_t518 - _t100*_t980 + _t1051*_t1063*_t169 + _t1052*_t1375 + _t1053*_t964 + _t1054*_t1362 + _t1055*_t946 + _t1056*_t1229 + _t1059*_t1229*_t178 + _t1059*_t374*_t382 + 0.6e1*_t1059*_t794 + _t1064*_t1362*_t388 + 0.6e1*_t1064*_t783 + _t1065*_t1725*_t948 + _t1066*_t205*_t233 + 0.48e2*_t1069*_t781 + _t1119*_t177*_t380 + _t1353*_t378*_t517 + _t1363*_t1681 + _t1366*_t384*_t507 + _t1368*_t489 + _t1369*_t1682 + _t1370*_t489 + _t1371*_t1687 + _t1373*_t1584*_t473 + _t1380*_t1719*_t382 + _t1388*_t489*_t973 + 0.32e2*_t1391 + (0.4e1 / 0.27e2)*_t1392 + (0.56e2 / 0.27e2)*_t1395 + (0.448e3 / 0.9e1)*_t1398 + (0.944e3 / 0.81e2)*_t1399 + (0.896e3 / 0.27e2)*_t1400 + (0.3136e4 / 0.27e2)*_t1403 + (0.7552e4 / 0.81e2)*_t1404 + _t1560*_t516 + 0.2e1*_t1563*_t948 + _t1566*_t1737 + _t1568*_t1681 + 0.48e2*_t1571*_t176*_t194 + _t1578*_t169*_t1736 + 0.24e2*_t1581*_t1641 + _t1583*_t516*_t965 + _t1585*_t177*_t886*_t962 + 0.48e2*_t1591*_t1641 + 0.32e2*_t1598 + 0.36e2*_t1601*_t374*_t958 + 0.144e3*_t1602*_t194*_t478 + (0.4e1 / 0.27e2)*_t1605 + (0.32e2 / 0.9e1)*_t1606 + (0.56e2 / 0.27e2)*_t1609 + (0.224e3 / 0.9e1)*_t1610 + (0.224e3 / 0.9e1)*_t1613 + (0.448e3 / 0.9e1)*_t1614 + (0.944e3 / 0.81e2)*_t1616 + (0.896e3 / 0.27e2)*_t1617 + (0.3136e4 / 0.27e2)*_t1618 + (0.7552e4 / 0.81e2)*_t1619 - 0.16e2 / 0.27e2*_t1620 + _t1681*_t1734 + _t1682*_t178*_t783 + _t1682*_t953 + _t1682*_t978 + _t1683*_t793 + _t1683*_t960 + _t1687*_t1722 + _t1718*_t948 + _t1719*_t388*_t794 + _t1719*_t951 + _t1720*_t1726*_t1727 + _t1721*_t783 + _t1723*_t942 - _t1724*_t976 - _t1724*_t977 + _t1728*_t785*_t965 + _t1729*_t970 + _t1730*_t233*_t972 + _t1731*_t1733 + _t1731*_t1735 + _t1732*_t1736*_t781 + _t1733*_t968 + _t1735*_t968 + _t1737*_t967 + 0.48e2*_t1738*_t386 + 0.24e2*_t1738*_t969 + 0.36e2*_t1739*_t789 + (0.32e2 / 0.9e1)*_t1741 + _t1742 + _t175*(_hc10[3]*_t1546*_t1717 + _t1229*_t1716 + _t1314 + (0.91e2 / 0.216e3)*_t1315 - _t1316*_t1700 - _t1319*_t1681 - _t1320*_t1700 + 0.8e1*_t1331*_t1699 + (0.7e1 / 0.36e2)*_t1333 - _t1338*_t371*_t374*_t507 - _t1345*_t489 + _t1346*_t489 - _t1348*_t1682 + _t1350*_t1682 - _t1351*_t1545*_t1717 - _t1352*_t1682 + _t1442*_t194*_t464 - 0.124e3 / 0.9e1*_t1516 + (0.91e2 / 0.216e3)*_t1521 + (0.20e2 / 0.3e1)*_t1523 - 0.4e1*_t1527*_t1688*_t469 - 0.40e2 / 0.3e1*_t1529 - 0.4e1*_t1530*_t93 + _t1531*_t1681 + _t1532*_t1681 - 0.1e1 / 0.3e1*_t1533 + _t1535*_t363 + _t1536*_t363 + _t1539 - _t1541*_t1683 - _t1549 - _t1550*_t1683 - 0.7e1 / 0.18e2*_t1554*_t365 + (0.7e1 / 0.9e1)*_t1555*_t365 + _t1681*_t1715 - _t1687*_t947 - 0.1e1 / 0.3e1*_t1698 - 0.4e1*_t1699*_t939 - _t1700*_t1701 - _t1700*_t1703 + _t1702*_t839 + (0.7e1 / 0.36e2)*_t1705 - 0.4e1 / 0.3e1*_t1707 + _t1709*_t363 + _t1710*_t363 + _t1711 - 0.1e1 / 0.3e1*_t1712 - _t1714 + (0.2e1 / 0.3e1)*_t194*_t9*_t933*_t939 + _t93*_t941) + _t205*_t389*_t839 + _t25*(-_t1010*_t361 + _t1046*_t356 + _t1048*_t233 + _t1442*_t460 + _t1515 - _t164*(-_hc9[4]*_t1010 - _hc9[4]*_t529 + 0.4e1*_t100*_t9*_t926 + (0.4e1 / 0.9e1)*_t122*_t3*_t5*_t927 - _t1300 + _t1694*_t93 - _t1697) - _t1674*_t461 + _t1693 - _t359*_t738 - _t361*_t529 + _t650*_t932 + _t93*(-_hc9[3]*_t1010 - _hc9[3]*_t529 + 0.4e1*_t100*_t9*_t930 + (0.4e1 / 0.9e1)*_t122*_t3*_t5*_t926 - _t1310 - _t1695 + _t1696*_t93)) + _t37*((0.1600e4 / 0.27e2)*_hc5[0]*_t222*_t277 - _t1034*_t1692 + (0.8e1 / 0.3e1)*_t113*_t1651 - _t1245*_t1690 + _t126*_t1665*_t429 - 0.80e2 / 0.3e1*_t1279 - 0.80e2 / 0.3e1*_t1281 - _t1282 - _t1283 - _t1284 - _t1285 - _t1286 - _t1287 - _t1288 - _t1289 - _t1290 - _t1291 - _t1292 - _t1293 - _t1294 - _t1295 - _t1296 + (0.320e3 / 0.3e1)*_t146*_t1652*_t687 - 0.80e2 / 0.3e1*_t1503 - 0.80e2 / 0.3e1*_t1504 - 0.112e3 / 0.9e1*_t1505 - 0.320e3 / 0.9e1*_t1506 + (0.1888e4 / 0.27e2)*_t151*_t1659 + (0.1888e4 / 0.27e2)*_t151*_t1660 + _t160*_t1676 + (0.236e3 / 0.27e2)*_t1615*_t343 - _t162*_t211 + _t162*_t216*nb + (0.1e1 / 0.9e1)*_t1650*_t29 + (0.112e3 / 0.3e1)*_t1653*_t605 + (0.112e3 / 0.3e1)*_t1654*_t605 + (0.56e2 / 0.3e1)*_t1655*_t38 + (0.56e2 / 0.3e1)*_t1656*_t38 + (0.20e2 / 0.3e1)*_t1657*_t20 + _t1658*_t729 - _t1663*_t1690 + (0.392e3 / 0.9e1)*_t1689*_t350 + (0.392e3 / 0.9e1)*_t1689*_t682 + _t1691*_t294 + _t1691*_t506 - _t1692*_t885 + _t216*_t728 + _t294*_t922 - 0.2e1 / 0.9e1*_t341 + (0.236e3 / 0.27e2)*_t343*_t711 - 0.40e2 / 0.9e1*_t344 - 0.32e2 / 0.9e1*_t347 + (0.7e1 / 0.9e1)*_t394*_t706 + (0.40e2 / 0.3e1)*_t450*_t716 + (0.7e1 / 0.9e1)*_t483*_t706 + _t506*_t922 + (0.112e3 / 0.9e1)*_t709*_t734 + (0.1e1 / 0.9e1)*_t726 + (0.8e1 / 0.3e1)*_t732*na + (0.112e3 / 0.9e1)*_t735*na) - 0.1280e4 / 0.27e2*_t405 - 0.896e3 / 0.27e2*_t408 - 0.256e3 / 0.27e2*_t410 + _t44*((0.7552e4 / 0.27e2)*_hc12[1]*_hc4[0]*_t114*_t115*_t125*_t14*_t226*na + (0.7552e4 / 0.27e2)*_hc12[1]*_hc4[0]*_t114*_t115*_t125*_t14*_t226*nb + (0.896e3 / 0.9e1)*_hc12[1]*_hc4[1]*_t125*_t15*_t218*_t258*_t67*na + (0.896e3 / 0.9e1)*_hc12[1]*_hc4[1]*_t125*_t15*_t218*_t258*_t67*nb + (0.32e2 / 0.3e1)*_hc12[1]*_hc4[2]*_t125*_t30*_t567*_t601*na + (0.32e2 / 0.3e1)*_hc12[1]*_hc4[2]*_t125*_t30*_t567*_t601*nb + (0.2e1 / 0.5e1)*_hc12[1]*_t1026*_t112*_t114*_t115*_t14*_t2 + (0.2e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t2*_t858 + (0.2e1 / 0.15e2)*_hc12[1]*_t112*_t114*_t115*_t14*_t253*_t79 + (0.8e1 / 0.15e2)*_hc12[1]*_t112*_t114*_t115*_t14*_t446*_t79 + (0.2e1 / 0.15e2)*_hc12[1]*_t112*_t114*_t115*_t14*_t501*_t79 + (0.640e3 / 0.9e1)*_hc4[0]*_t146*_t30*_t567*_t601*_t604*na + (0.640e3 / 0.9e1)*_hc4[0]*_t146*_t30*_t567*_t601*_t604*nb + (0.2240e4 / 0.9e1)*_hc4[0]*_t15*_t218*_t255*_t258*_t62*_t67*na + (0.2240e4 / 0.9e1)*_hc4[0]*_t15*_t218*_t255*_t258*_t62*_t67*nb + 0.128e3*_hc4[0]*_t215*_t30*_t31*_t38*na + 0.128e3*_hc4[0]*_t215*_t30*_t31*_t38*nb + (0.3776e4 / 0.81e2)*_hc4[1]*_t114*_t115*_t14*_t226*_t38*na + (0.3776e4 / 0.81e2)*_hc4[1]*_t114*_t115*_t14*_t226*_t38*nb + (0.160e3 / 0.3e1)*_hc4[1]*_t255*_t30*_t567*_t601*_t62*na + (0.160e3 / 0.3e1)*_hc4[1]*_t255*_t30*_t567*_t601*_t62*nb + (0.224e3 / 0.27e2)*_hc4[2]*_t15*_t218*_t258*_t38*_t67*na + (0.224e3 / 0.27e2)*_hc4[2]*_t15*_t218*_t258*_t38*_t67*nb + (0.16e2 / 0.27e2)*_hc4[3]*_t30*_t38*_t567*_t601*na + (0.16e2 / 0.27e2)*_hc4[3]*_t30*_t38*_t567*_t601*nb + (0.14e2 / 0.5e1)*_t100*_t110*_t125*_t30*_t601*_t604 + (0.14e2 / 0.5e1)*_t100*_t125*_t199*_t30*_t601*_t604 - _t1026*_t210 + (0.14e2 / 0.15e2)*_t110*_t15*_t255*_t258*_t310*_t38*_t67 - 0.7e1 / 0.15e2*_t1170 - 0.16e2 / 0.45e2*_t1171 - _t1191 - 0.28e2 / 0.15e2*_t1462 + (0.14e2 / 0.15e2)*_t15*_t199*_t255*_t258*_t310*_t38*_t67 - 0.7e1 / 0.15e2*_t1648 - 0.16e2 / 0.45e2*_t1649 - _t210*_t858 - 0.64e2 / 0.27e2*_t269 - 0.640e3 / 0.27e2*_t272 - 0.256e3 / 0.9e1*_t275 - 0.640e3 / 0.9e1*_t279 - 0.1280e4 / 0.9e1*_t283 - _t447*(_hc3[0]*_t1634 + _hc3[1]*_t1637 + _hc3[2]*_t1636 - _t102*_t1252 - _t107*_t1638 + _t1145 - _t1252*_t840 - _t1446*_t1635 - _t1635*_t571 - _t1638*_t845 - _t1639*na - _t1639*nb + _t1647) - 0.256e3 / 0.3e1*_t585) + _t474*(0.6e1*_hc10[1]*_hc10[3]*_t12*_t13*_t15*_t18*_t369*_t507*_t785*p->cam_omega + (0.1e1 / 0.6e1)*_hc10[1]*_t12*_t13*_t15*_t166*_t170*_t489*p->cam_omega + 0.2e1*_hc10[1]*_t12*_t13*_t15*_t170*_t469*p->cam_omega + (0.20e2 / 0.3e1)*_hc10[1]*_t12*_t13*_t15*_t170*_t9*_t933*p->cam_omega + (0.1e1 / 0.6e1)*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t507*p->cam_omega - _t1037*_t1557 - 0.1e1 / 0.3e1*_t1049 - _t1051*_t771 - _t1052*_t1558 + 0.2e1*_t12*_t13*_t15*_t18*_t368*_t369*_t489*_t93*p->cam_omega + 0.8e1*_t12*_t13*_t15*_t194*_t368*_t369*_t469*_t9*p->cam_omega - _t1356*_t489 - _t1559 - _t934 - 0.7e1 / 0.18e2*_t935) + _t520*_t946 - 0.72e2*_t528*_t979 + _t61*(-0.80e2 / 0.3e1*_hc8[0]*_t330 - _t1034*_t1669 - _t1038*_t295 + _t1038*_t914 - 0.8e1*_t1238 - 0.16e2*_t1240 - _t1243*_t180 - _t1245*_t1662 - _t1247 - _t1249 - _t1251 - _t1253 - _t1255 - _t1257 - _t1258 - _t1259 + 0.8e1*_t126*_t1651 - _t1261 - _t1263 - _t1264 - _t1267 - _t1268 - _t127*_t346 - _t1270 - _t1272 - _t1273 - _t1275 - _t1277 + _t132*_t1676 + _t142*_t419*_t905 + (0.7e1 / 0.2e1)*_t142*_t606 + 0.32e2*_t1420*_t1652 + _t147*_t1665*_t429 + (0.280e3 / 0.3e1)*_t148*_t1661 - 0.8e1*_t1492 - _t1495*_t180 - 0.320e3 / 0.3e1*_t1500 - 0.7e1 / 0.6e1*_t1501*_t316 + (0.1888e4 / 0.9e1)*_t157*_t1659 + (0.1888e4 / 0.9e1)*_t157*_t1660 + (0.28e2 / 0.9e1)*_t1611*_t706 + (0.944e3 / 0.27e2)*_t1615*_t323 + _t1634*_t311*na + _t1634*_t311*nb + (0.4e1 / 0.9e1)*_t1650*_t38 + (0.160e3 / 0.3e1)*_t1653*_t619 + (0.160e3 / 0.3e1)*_t1654*_t619 + 0.40e2*_t1655*_t62 + 0.40e2*_t1656*_t62 + (0.2e1 / 0.3e1)*_t1657 + _t1658*_t701 + (0.280e3 / 0.3e1)*_t1661*_t677 - _t1662*_t1663 - 0.16e2*_t1664 + _t1666*_t294 + _t1666*_t506 + _t1667*_t294 + _t1667*_t506 - _t1668*_t306 - _t1668*_t509 - _t1669*_t885 + _t202*_t419*_t905 + (0.7e1 / 0.2e1)*_t202*_t606 + (0.320e3 / 0.9e1)*_t222*_t693 - _t295*_t899 + _t306*_t909 - 0.8e1 / 0.9e1*_t320*_t38 + (0.944e3 / 0.27e2)*_t323*_t711 - 0.160e3 / 0.9e1*_t324 + _t422*_t915 + (0.2e1 / 0.3e1)*_t456*_t663 - _t457*(_hc6[0]*_t1634 + _hc6[1]*_t1637 + _hc6[2]*_t1636 + _t1036*_t304 - 0.16e2 / 0.15e2*_t1037*_t104*_t892 - _t1212*_t1252 - _t1214*_t1681 - _t1215*_t1638 - 0.16e2 / 0.135e3*_t1216 - _t1225*_t1682 + _t1230*_t304 - _t1233*_t1687 - _t1236*_t489 + _t1237 - _t1252*_t136 - _t140*_t1638 - _t1446*_t1677 - _t1479*_t303 - _t1480*_t303 - 0.8e1 / 0.5e1*_t1483*_t1688 - _t1485*_t1640*_t575 + (0.4e1 / 0.3e1)*_t1486*_t896 + _t1647 - _t1677*_t571 - 0.128e3 / 0.45e2*_t1678 - _t1679*na - _t1679*nb - 0.16e2 / 0.135e3*_t1680 - _t1683*_t645 + _t1684*_t304 - _t1685*_t303 - _t1686*_t303 - _t301*_t303*_t839 + _t304*_t649 + (0.8e1 / 0.45e2)*_t79*_t897 + _t890 + _t895) + _t509*_t909 + _t525*_t703 + (0.28e2 / 0.9e1)*_t588*_t706 - 0.64e2*_t661 + (0.112e3 / 0.3e1)*_t684*_t708 + (0.4e1 / 0.9e1)*_t692 + 0.8e1*_t695 + (0.112e3 / 0.3e1)*_t707*na + _t899*_t914) - _t714*_t976 - _t714*_t977 - 0.160e3 / 0.27e2*_t799 - 0.64e2 / 0.3e1*_t981)) + 0.4e1*_t100*_t289*_t9 + 0.8e1*_t100*_t436*_t9 + 0.2e1*_t1029*_t93 - _t1030*_t1748 - 0.2e1*_t1071 - 0.8e1 / 0.3e1*_t1072 + (0.4e1 / 0.3e1)*_t122*_t3*_t434*_t5 - _t1748*_t880 - _t1749 + (0.4e1 / 0.3e1)*_t190*_t21*_t219*_t220*_t255*_t310*_t82 + (0.4e1 / 0.3e1)*_t207*_t21*_t219*_t220*_t255*_t310*_t82 + 0.2e1*_t233*_t436 - _t819 - 0.8e1 / 0.3e1*_t820 - 0.40e2 / 0.3e1*_t822 + 0.2e1*_t883*_t93 - 0.2e1*_t993 - 0.40e2 / 0.3e1*_t998 - 0.32e2 / 0.3e1*_t999;
  const double d4F_dna_dnb3 = 0.16e2*_hc0[0]*_hc12[1]*_t122*_t207*_t21*_t3*_t5*_t82 - _hc5[1]*_t1057 - _hc5[1]*_t481 + _t1*((0.16e2 / 0.3e1)*_hc0[0]*_hc12[1]*_t122*_t21*_t3*_t487*_t5*_t82 + (0.16e2 / 0.3e1)*_hc0[0]*_hc12[1]*_t122*_t21*_t3*_t5*_t521*_t82 + (0.1120e4 / 0.81e2)*_hc0[0]*_hc12[1]*_t21*_t226*_t3*_t5*_t76*_t82 + (0.20e2 / 0.3e1)*_hc0[0]*_t190*_t215*_t423*_t541*_t604*_t61 + 0.20e2*_hc0[0]*_t207*_t215*_t423*_t541*_t604*_t61 + 0.12e2*_hc5[1]*_t215 + 0.24e2*_hc5[1]*_t567*_t9 + (0.140e3 / 0.81e2)*_hc5[2]*_t226*_t3*_t5 + 0.6e1*_t100*_t1029*_t9 - _t1002*_t702 + (0.2e1 / 0.3e1)*_t1030*_t122*_t3*_t5 + (0.80e2 / 0.3e1)*_t1136*_t1172*_t20*_t3*_t37*_t575*_t76*_t828 - 0.8e1 / 0.9e1*_t1409 - _t1412*_t829 - 0.112e3 / 0.27e2*_t1413 - _t1421 - _t1423 - _t1426 - _t1427 + (0.640e3 / 0.3e1)*_t146*_t37*_t541*_t567*_t604*_t76*_t828 - 0.80e2*_t1624 - 0.8e1 / 0.3e1*_t1625 - _t1630 - 0.20e2 / 0.3e1*_t1745 - 0.4e1*_t1746 - _t1750 - _t1751 - _t1753 - _t1754 + _t1755*_t93 - 0.4e1 / 0.3e1*_t1756 + (0.80e2 / 0.9e1)*_t190*_t20*_t219*_t220*_t255*_t266*_t423*_t61 + (0.80e2 / 0.3e1)*_t20*_t207*_t219*_t220*_t255*_t266*_t423*_t61 + (0.320e3 / 0.81e2)*_t21*_t218*_t219*_t220*_t255*_t76*_t82 + (0.2e1 / 0.3e1)*_t21*_t219*_t220*_t255*_t310*_t487*_t82 + (0.2e1 / 0.3e1)*_t21*_t219*_t220*_t255*_t310*_t521*_t82 - _t23*(_hc11[1]*_t1053*_t1120 + _hc11[1]*_t1594*_t476*_t489 - _t100*_t1381*_t957 - _t100*_t1570*_t972 - 0.18e2*_t100*_t955 + _t1014*_t1604 + _t1051*_t787*_t958 + 0.18e2*_t1052*_t958 + 0.3e1*_t1053*_t949 + 0.3e1*_t1054*_t1567 + _t1058*_t1113 + _t1060*_t1787 + _t1061*_t1578 + _t1061*_t1790*_t194 + _t1062*_t1109 + _t1063*_t1110 - _t1067*_t1788 + 0.72e2*_t1069*_t954 + _t1076*_t480 + _t1104*_t1564 + _t1104*_t1577 + _t1104*_t1579*_t174 + _t1104*_t1599 + _t1104*_t1790*_t382 + _t1112*_t1599 + _t1113*_t474 + _t1114*_t1353*_t788 + _t1117*_t1563 + _t1117*_t1789 + _t1118*_t976 + _t1118*_t977 + _t1120*_t1725*_t516 + _t1121*_t1566 + _t1121*_t967 + _t1122*_t1728 + _t1123*_t1569 + _t1123*_t1589 + _t1124*_t1569 + _t1124*_t1589 + _t1363*_t1769 + _t1367*_t1769 + _t1377*_t1726*_t194*_t473 + 0.16e2*_t1391 + (0.2e1 / 0.27e2)*_t1392 + _t1393*_t1608 + (0.28e2 / 0.27e2)*_t1395 + (0.224e3 / 0.9e1)*_t1398 + (0.472e3 / 0.81e2)*_t1399 + (0.448e3 / 0.27e2)*_t1400 + (0.1568e4 / 0.27e2)*_t1403 + (0.3776e4 / 0.81e2)*_t1404 + _t1563*_t516 + _t1565*_t489 + _t1568*_t1769 + _t1570*_t231*_t386*_t489 + _t1572*_t507 + _t1575*_t489*_t787 + _t1587*_t1792 + _t1588*_t1791 - 0.108e3*_t1591*_t194*_t528 + _t1593*_t1791 + _t1594*_t1792 + _t1596*_t383*_t489 + _t1597*_t1795 + _t1600*na + _t1603*_t383*_t507 + (0.28e2 / 0.9e1)*_t1609 + (0.112e3 / 0.9e1)*_t1610 + (0.112e3 / 0.3e1)*_t1613 + (0.224e3 / 0.3e1)*_t1614 + (0.472e3 / 0.27e2)*_t1616 + (0.448e3 / 0.9e1)*_t1617 + (0.1568e4 / 0.9e1)*_t1618 + (0.3776e4 / 0.27e2)*_t1619 + _t1621 + 0.3e1*_t1718*_t516 + _t1729*_t174*_t972 + 0.36e2*_t1732*_t231*_t954 + _t1734*_t1769 + 0.54e2*_t1739*_t958 + (0.16e2 / 0.3e1)*_t1741 + _t1742 + _t175*(_t1076*_t1520 + _t1076*_t465 - _t1076*_t764 - _t1104*_t1534 + _t1104*_t1537 - _t1104*_t1551 - _t1112*_t1534 + _t1112*_t1537 - _t1112*_t1551 + (0.91e2 / 0.432e3)*_t1315 + _t1317*_t1704 - _t1319*_t1769 - 0.169e3 / 0.12e2*_t1516 - _t1517*_t1701 - _t1517*_t1703 + _t1518*_t1709 + _t1518*_t1710 + (0.91e2 / 0.144e3)*_t1521 - _t1526*_t1782 - _t1528*_t1782 - _t1530*_t1727 + 0.6e1*_t1530*_t1772 + _t1531*_t1769 + _t1532*_t1769 - _t1540*_t1769 - _t1541*_t1786 - _t1543*_t1785 + _t1547*_t514 + _t1552*_t1786 + _t1553*_t1785 + _t1556 + _t167*_t1781 - 0.13e2 / 0.2e1*_t1698 + 0.10e2*_t1706*_t939 - 0.20e2*_t1707 + (0.3e1 / 0.2e1)*_t1711 - 0.1e1 / 0.2e1*_t1712 - 0.3e1 / 0.2e1*_t1714 + _t1715*_t1769 + (0.1e1 / 0.2e1)*_t1780 - 0.1e1 / 0.2e1*_t1784 + 0.3e1*_t194*_t940 - _t518*_t9*_t940) + _t1783*_t789*_t792 - _t1788*_t955 + _t1789*_t516 + _t1793*_t231 + _t1794*_t231 + 0.36e2*_t215*_t381 + _t25*(_hc9[1]*_t727 + _t1048*_t482 - _t1057*_t460 + _t1693 + _t1778*_t93 + _t1779 - _t460*_t481) + _t37*((0.944e3 / 0.9e1)*_hc12[1]*_hc8[0]*_t112*_t149*_t226*_t3*na + (0.944e3 / 0.27e2)*_hc12[1]*_hc8[0]*_t112*_t149*_t226*_t3*nb + (0.56e2 / 0.3e1)*_hc12[1]*_hc8[1]*_t112*_t218*_t219*_t4*na + (0.56e2 / 0.9e1)*_hc12[1]*_hc8[1]*_t112*_t218*_t219*_t4*nb + 0.4e1*_hc12[1]*_hc8[2]*_t112*_t567*na + (0.4e1 / 0.3e1)*_hc12[1]*_hc8[2]*_t112*_t567*nb + 0.16e2*_hc12[1]*_t122*_t125*_t3*_t5*_t506 + 0.56e2*_hc8[0]*_t125*_t567*_t604*na + (0.56e2 / 0.3e1)*_hc8[0]*_t125*_t567*_t604*nb + 0.36e2*M_PI*_hc8[0]*_t215*_t29*na + 0.12e2*M_PI*_hc8[0]*_t215*_t29*nb + (0.196e3 / 0.3e1)*_hc8[0]*_t218*_t219*_t255*_t38*_t4*na + (0.196e3 / 0.9e1)*_hc8[0]*_t218*_t219*_t255*_t38*_t4*nb + (0.118e3 / 0.9e1)*_hc8[1]*_t149*_t226*_t29*_t3*na + (0.118e3 / 0.27e2)*_hc8[1]*_t149*_t226*_t29*_t3*nb + 0.28e2*_hc8[1]*_t255*_t38*_t567*na + (0.28e2 / 0.3e1)*_hc8[1]*_t255*_t38*_t567*nb + (0.7e1 / 0.6e1)*_hc8[2]*_t218*_t219*_t29*_t4*na + (0.7e1 / 0.18e2)*_hc8[2]*_t218*_t219*_t29*_t4*nb + (0.1e1 / 0.6e1)*_hc8[3]*_t29*_t567*na + (0.1e1 / 0.18e2)*_hc8[3]*_t29*_t567*nb - _t1101*_t459 - _t126*_t1776 - _t126*_t1777 - 0.40e2 / 0.3e1*_t1279 - 0.40e2 / 0.3e1*_t1281 - 0.40e2*_t1503 - 0.40e2*_t1504 - _t1507 + 0.4e1*_t1768*_t38 - _t1774*_t337 + 0.10e2*_t219*_t220*_t255*_t310*_t506*_t62) + _t44*((0.3776e4 / 0.9e1)*_hc12[1]*_hc4[0]*_t114*_t115*_t125*_t14*_t226*na + (0.3776e4 / 0.27e2)*_hc12[1]*_hc4[0]*_t114*_t115*_t125*_t14*_t226*nb + (0.448e3 / 0.3e1)*_hc12[1]*_hc4[1]*_t125*_t15*_t218*_t258*_t67*na + (0.448e3 / 0.9e1)*_hc12[1]*_hc4[1]*_t125*_t15*_t218*_t258*_t67*nb + 0.16e2*_hc12[1]*_hc4[2]*_t125*_t30*_t567*_t601*na + (0.16e2 / 0.3e1)*_hc12[1]*_hc4[2]*_t125*_t30*_t567*_t601*nb + (0.3e1 / 0.5e1)*_hc12[1]*_t1026*_t112*_t114*_t115*_t14*_t2 + (0.1e1 / 0.5e1)*_hc12[1]*_t1096*_t112*_t114*_t115*_t14*_t2 + (0.2e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t501*_t79 + (0.320e3 / 0.3e1)*_hc4[0]*_t146*_t30*_t567*_t601*_t604*na + (0.320e3 / 0.9e1)*_hc4[0]*_t146*_t30*_t567*_t601*_t604*nb + (0.1120e4 / 0.3e1)*_hc4[0]*_t15*_t218*_t255*_t258*_t62*_t67*na + (0.1120e4 / 0.9e1)*_hc4[0]*_t15*_t218*_t255*_t258*_t62*_t67*nb + 0.192e3*_hc4[0]*_t215*_t30*_t31*_t38*na + 0.64e2*_hc4[0]*_t215*_t30*_t31*_t38*nb + (0.1888e4 / 0.27e2)*_hc4[1]*_t114*_t115*_t14*_t226*_t38*na + (0.1888e4 / 0.81e2)*_hc4[1]*_t114*_t115*_t14*_t226*_t38*nb + 0.80e2*_hc4[1]*_t255*_t30*_t567*_t601*_t62*na + (0.80e2 / 0.3e1)*_hc4[1]*_t255*_t30*_t567*_t601*_t62*nb + (0.112e3 / 0.9e1)*_hc4[2]*_t15*_t218*_t258*_t38*_t67*na + (0.112e3 / 0.27e2)*_hc4[2]*_t15*_t218*_t258*_t38*_t67*nb + (0.8e1 / 0.9e1)*_hc4[3]*_t30*_t38*_t567*_t601*na + (0.8e1 / 0.27e2)*_hc4[3]*_t30*_t38*_t567*_t601*nb + (0.7e1 / 0.5e1)*_t100*_t110*_t125*_t30*_t601*_t604 + (0.21e2 / 0.5e1)*_t100*_t125*_t199*_t30*_t601*_t604 - _t1026*_t527 - _t1097 + (0.7e1 / 0.15e2)*_t110*_t15*_t255*_t258*_t310*_t38*_t67 - _t110*_t608 - _t1463 + (0.7e1 / 0.5e1)*_t15*_t199*_t255*_t258*_t310*_t38*_t67 - 0.7e1 / 0.5e1*_t1648 - 0.8e1 / 0.15e2*_t1649 - _t447*(0.72e2*_hc3[0]*_t215 + 0.480e3*_hc3[0]*_t570*na*nb + (0.9680e4 / 0.81e2)*_hc3[1]*_t1141*_t3*_t5*na*nb + (0.32e2 / 0.3e1)*_hc3[1]*_t226*_t3*_t5 + (0.772e3 / 0.81e2)*_hc3[2]*_t1139*_t219*_t220*na*nb + (0.1e1 / 0.3e1)*_hc3[2]*_t218*_t219*_t220 + (0.16e2 / 0.9e1)*_hc3[3]*_t1133*_t541*na*nb + (0.1e1 / 0.54e2)*_hc3[4]*_t1135*_t1136*_t3*na*nb - _t102*_t1441 - _t1044*_t581 - _t107*_t1447 - 0.1e1 / 0.3e1*_t1757 - _t1758*_t581 - _t1766 - _t568*_t840 - _t574 - _t577*_t845)) + _t61*((0.944e3 / 0.3e1)*_hc12[1]*_hc8[0]*_t125*_t149*_t226*_t3*na + (0.944e3 / 0.9e1)*_hc12[1]*_hc8[0]*_t125*_t149*_t226*_t3*nb + 0.56e2*_hc12[1]*_hc8[1]*_t125*_t218*_t219*_t4*na + (0.56e2 / 0.3e1)*_hc12[1]*_hc8[1]*_t125*_t218*_t219*_t4*nb + 0.12e2*_hc12[1]*_hc8[2]*_t125*_t567*na + 0.4e1*_hc12[1]*_hc8[2]*_t125*_t567*nb + (0.3e1 / 0.4e1)*_hc12[1]*_t1038*_t112*_t149*_t2*_t3 + (0.1e1 / 0.4e1)*_hc12[1]*_t1105*_t112*_t149*_t2*_t3 + (0.1e1 / 0.2e1)*_hc12[1]*_t112*_t149*_t3*_t509*_t79 + 0.16e2*_hc12[1]*_t122*_t146*_t3*_t5*_t506 + 0.80e2*_hc8[0]*_t146*_t567*_t604*na + (0.80e2 / 0.3e1)*_hc8[0]*_t146*_t567*_t604*nb + 0.144e3*M_PI*_hc8[0]*_t215*_t38*na + 0.48e2*M_PI*_hc8[0]*_t215*_t38*nb + 0.140e3*_hc8[0]*_t218*_t219*_t255*_t4*_t62*na + (0.140e3 / 0.3e1)*_hc8[0]*_t218*_t219*_t255*_t4*_t62*nb + (0.472e3 / 0.9e1)*_hc8[1]*_t149*_t226*_t3*_t38*na + (0.472e3 / 0.27e2)*_hc8[1]*_t149*_t226*_t3*_t38*nb + 0.60e2*_hc8[1]*_t255*_t567*_t62*na + 0.20e2*_hc8[1]*_t255*_t567*_t62*nb + (0.14e2 / 0.3e1)*_hc8[2]*_t218*_t219*_t38*_t4*na + (0.14e2 / 0.9e1)*_hc8[2]*_t218*_t219*_t38*_t4*nb + (0.2e1 / 0.3e1)*_hc8[3]*_t38*_t567*na + (0.2e1 / 0.9e1)*_hc8[3]*_t38*_t567*nb + (0.7e1 / 0.4e1)*_t100*_t125*_t142*_t604 + (0.21e2 / 0.4e1)*_t100*_t125*_t202*_t604 - _t1004*_t309 - _t1038*_t643 - _t1101*_t458 - _t1106 - 0.4e1*_t1238 - _t1243*_t285 + (0.7e1 / 0.24e2)*_t142*_t219*_t255*_t310*_t38*_t4 - _t147*_t1776 - _t147*_t1777 - _t1493*_t201 - _t1495*_t835 - _t1502 - 0.24e2*_t1664 + 0.6e1*_t1768*_t62 - _t1774*_t308 - _t1775*_t671 + 0.6e1*_t20*_t219*_t220*_t255*_t310*_t506 + (0.7e1 / 0.8e1)*_t202*_t219*_t255*_t310*_t38*_t4 - _t457*((0.2e1 / 0.15e2)*_hc7[1]*_t489*_t67*_t70*_t79 + 0.2e1*_hc7[3]*_t104*_t194*_t67*_t70*_t9 + (0.6e1 / 0.5e1)*_hc7[3]*_t122*_t194*_t67*_t70 + (0.2e1 / 0.15e2)*_hc7[3]*_t507*_t67*_t70*_t79 - _t1044*_t656 - _t1076*_t455 - _t1076*_t888 - _t1104*_t1490 - _t1104*_t1771 - _t1112*_t1490 - _t1112*_t1771 - _t1212*_t568 - _t1214*_t1769 - _t1215*_t577 - _t136*_t1441 - _t138*_t1770 - _t140*_t1447 - 0.1e1 / 0.3e1*_t1473 - _t1484*_t1773 - _t1491 - 0.32e2 / 0.15e2*_t1678 - 0.8e1 / 0.45e2*_t1680 - _t1685*_t647 - _t1686*_t647 - _t1758*_t656 - _t1766 - 0.6e1 / 0.5e1*_t1772*_t893 - _t302*_t653 - _t655 - 0.8e1 / 0.5e1*_t889)))) + 0.12e2*_t100*_t436*_t9 + 0.3e1*_t1029*_t93 - 0.3e1*_t1071 - 0.8e1*_t1072 - _t1127 + (0.16e2 / 0.9e1)*_t122*_t3*_t434*_t5 - _t1633 - _t1749 - _t1796 + 0.2e1*_t207*_t21*_t219*_t220*_t255*_t310*_t82 - _t823 - 0.20e2*_t998;
  const double d4F_dnb4 = _t1*(-_t1407*_t207 + _t1417*_t1747 + _t1428 - 0.32e2 / 0.9e1*_t1625 - 0.448e3 / 0.27e2*_t1628 + (0.320e3 / 0.9e1)*_t1632 + (0.4e1 / 0.3e1)*_t1743 + (0.80e2 / 0.3e1)*_t1744 - 0.40e2 / 0.3e1*_t1745 - 0.16e2 / 0.3e1*_t1756 + _t1801 - _t23*(_hc11[1]*_t1113*_t1817 + _hc4[1]*_t1396*_t1612 + _t1054*_t1719 + _t1054*(_t1116 + _t1318*_t886 - _t1815) + _t1054*(-0.3e1 / 0.2e1*_t1115 + _t1358 + _t1359*_t172*_t886 - 0.3e1 / 0.2e1*_t1815 + 0.3e1*_t513) + _t1055*_t1113 + _t1056*_t1682 + _t1056*_t1805 + _t1056*_t1806 + _t1059*_t1818 + _t1059*_t1820 + _t1061*_t1103*_t383 + 0.12e2*_t1076*_t955 + _t1104*_t1730*_t969 + 0.24e2*_t1104*_t386*_t954 + _t1109*_t169*_t1723 + 0.24e2*_t1110*_t958 + _t1117*_t1821 + _t1117*_t379*_t516 + _t1353*(_t205 * _t205 * _t205 * _t205) + _t1363*_t1802 + _t1367*_t1802 + _t1371*_t1808 + _t1373*_t1787*_t886 + _t1390*_t1783*_t958 + _t1406 + _t1568*_t1802 + 0.64e2*_t1598 + (0.112e3 / 0.27e2)*_t1609 + (0.896e3 / 0.9e1)*_t1614 + (0.1888e4 / 0.81e2)*_t1616 + (0.1792e4 / 0.27e2)*_t1617 + (0.6272e4 / 0.27e2)*_t1618 + (0.15104e5 / 0.81e2)*_t1619 + _t1682*_t1794 + _t1682*_t1816 + _t1682*_t1822 + _t1722*_t1808 + _t1730*_t1732*_t489 + _t1734*_t1802 + _t1735*_t489*_t954 + _t1740*_t803 + _t175*(_t1076*_t1318 + _t1104*_t1341 - _t1104*_t1343 + _t1112*_t1341 - _t1112*_t1343 + _t1314 - _t1317*_t1701 - _t1317*_t1703 - _t1319*_t1802 + _t1344*_t1808 + (0.91e2 / 0.108e3)*_t1521 + _t1531*_t1802 + _t1532*_t1802 - _t1540*_t1802 + _t1682*_t1716 - _t1682*_t1813 - _t1682*_t1814 + (0.7e1 / 0.6e1)*_t1705 + _t1715*_t1802 + _t1716*_t1805 + _t1716*_t1806 - _t173*_t1797 + 0.2e1*_t1780 + _t1781*_t769 - 0.2e1*_t1784 + _t1803*_t464 - _t1803*_t468 - _t1805*_t1813 - _t1805*_t1814 - _t1806*_t1813 - _t1806*_t1814 - _t1808*_t947 + _t1810*_t464 - _t1810*_t468 + _t1811*_t464 - _t1811*_t468) + _t1793*_t489 + _t1797*_t206 + _t1803*_t387 + _t1803*_t519 + _t1805*_t1816 + _t1805*_t1822 + _t1806*_t1816 + _t1806*_t1822 + _t1809*_t961 + _t1810*_t519 + _t1811*_t387 + _t1818*_t1819 + _t1819*_t1820 + _t1821*_t516 + _t25*(_hc9[1]*_t1797 + _t1048*_t518 + _t1118*_t460 + _t1778*_t194 + _t1779) + _t37*((0.3776e4 / 0.27e2)*_hc12[1]*_hc8[0]*_t112*_t149*_t226*_t3*na + (0.224e3 / 0.9e1)*_hc12[1]*_hc8[1]*_t112*_t218*_t219*_t4*na + (0.16e2 / 0.3e1)*_hc12[1]*_hc8[2]*_t112*_t567*na + 0.32e2*_hc12[1]*_t122*_t125*_t3*_t5*_t506 + (0.224e3 / 0.3e1)*_hc8[0]*_t125*_t567*_t604*na + 0.48e2*M_PI*_hc8[0]*_t215*_t29*na + (0.784e3 / 0.9e1)*_hc8[0]*_t218*_t219*_t255*_t38*_t4*na + (0.472e3 / 0.27e2)*_hc8[1]*_t149*_t226*_t29*_t3*na + (0.112e3 / 0.3e1)*_hc8[1]*_t255*_t38*_t567*na + (0.14e2 / 0.9e1)*_hc8[2]*_t218*_t219*_t29*_t4*na + (0.2e1 / 0.9e1)*_hc8[3]*_t29*_t567*na - _t1101*_t1280 - _t126*_t1812 - _t1297 - 0.160e3 / 0.3e1*_t1503 - 0.160e3 / 0.3e1*_t1504 + 0.4e1*_t1801*_t38 + 0.20e2*_t219*_t220*_t255*_t310*_t506*_t62) + _t379*(_t516 * _t516) + _t44*((0.15104e5 / 0.27e2)*_hc12[1]*_hc4[0]*_t114*_t115*_t125*_t14*_t226*na + (0.1792e4 / 0.9e1)*_hc12[1]*_hc4[1]*_t125*_t15*_t218*_t258*_t67*na + (0.64e2 / 0.3e1)*_hc12[1]*_hc4[2]*_t125*_t30*_t567*_t601*na + (0.4e1 / 0.5e1)*_hc12[1]*_t1096*_t112*_t114*_t115*_t14*_t2 + (0.4e1 / 0.5e1)*_hc12[1]*_t112*_t114*_t115*_t14*_t501*_t79 + (0.1280e4 / 0.9e1)*_hc4[0]*_t146*_t30*_t567*_t601*_t604*na + (0.4480e4 / 0.9e1)*_hc4[0]*_t15*_t218*_t255*_t258*_t62*_t67*na + 0.256e3*_hc4[0]*_t215*_t30*_t31*_t38*na + (0.7552e4 / 0.81e2)*_hc4[1]*_t114*_t115*_t14*_t226*_t38*na + (0.320e3 / 0.3e1)*_hc4[1]*_t255*_t30*_t567*_t601*_t62*na + (0.448e3 / 0.27e2)*_hc4[2]*_t15*_t218*_t258*_t38*_t67*na + (0.32e2 / 0.27e2)*_hc4[3]*_t30*_t38*_t567*_t601*na + (0.28e2 / 0.5e1)*_t100*_t125*_t199*_t30*_t601*_t604 - _t1096*_t1128 - _t1191 + (0.28e2 / 0.15e2)*_t15*_t199*_t255*_t258*_t310*_t38*_t67 - 0.14e2 / 0.5e1*_t1648 - 0.32e2 / 0.45e2*_t1649 - _t447*(-_t102*_t1129 - _t107*_t1131 + _t1145 - 0.4e1 / 0.9e1*_t1757 + _t1800 - _t581*_t904)) + _t484*_t612 + _t61*((0.3776e4 / 0.9e1)*_hc12[1]*_hc8[0]*_t125*_t149*_t226*_t3*na + (0.224e3 / 0.3e1)*_hc12[1]*_hc8[1]*_t125*_t218*_t219*_t4*na + 0.16e2*_hc12[1]*_hc8[2]*_t125*_t567*na + _hc12[1]*_t1105*_t112*_t149*_t2*_t3 + _hc12[1]*_t112*_t149*_t3*_t509*_t79 + 0.32e2*_hc12[1]*_t122*_t146*_t3*_t5*_t506 + (0.320e3 / 0.3e1)*_hc8[0]*_t146*_t567*_t604*na + 0.192e3*M_PI*_hc8[0]*_t215*_t38*na + (0.560e3 / 0.3e1)*_hc8[0]*_t218*_t219*_t255*_t4*_t62*na + (0.1888e4 / 0.27e2)*_hc8[1]*_t149*_t226*_t3*_t38*na + 0.80e2*_hc8[1]*_t255*_t567*_t62*na + (0.56e2 / 0.9e1)*_hc8[2]*_t218*_t219*_t38*_t4*na + (0.8e1 / 0.9e1)*_hc8[3]*_t38*_t567*na + 0.7e1*_t100*_t125*_t202*_t604 - _t1101*_t1239 - _t1105*_t1211 - _t1242*_t1775 - _t1244*_t1495 - _t1278 - _t147*_t1812 - 0.16e2*_t1492 - 0.32e2*_t1664 + 0.6e1*_t1801*_t62 + 0.12e2*_t20*_t219*_t220*_t255*_t310*_t506 + (0.7e1 / 0.6e1)*_t202*_t219*_t255*_t310*_t38*_t4 - _t457*(_t1036*_t866 - _t1076*_t1218 - _t1104*_t1807 - _t1112*_t1807 - _t1129*_t136 - _t1131*_t140 - _t1214*_t1802 - _t1217*_t1770 - _t1233*_t1808 + _t1237 - _t134*_t1797 - 0.4e1 / 0.9e1*_t1473 - 0.32e2 / 0.135e3*_t1680 - _t1682*_t1804 + _t1684*_t866 + _t1800 - _t1803*_t454 - _t1804*_t1805 - _t1804*_t1806 - _t1810*_t454 - _t1811*_t454 - _t656*_t904)) + _t949*(0.6e1*_hc10[1]*_hc10[3]*_t1102*_t12*_t13*_t15*_t18*_t369*p->cam_omega + (0.1e1 / 0.2e1)*_hc10[1]*_t12*_t13*_t15*_t166*_t170*_t489*p->cam_omega + (0.1e1 / 0.2e1)*_hc10[3]*_t12*_t13*_t15*_t166*_t170*_t507*p->cam_omega - _t1049 - _t1076*_t768 + 0.2e1*_t1103*_t12*_t13*_t15*_t18*_t194*_t368*_t369*p->cam_omega - _t1104*_t947 - _t1109*_t771 - _t1111*_t1355 - _t1112*_t947 + 0.2e1*_t12*_t13*_t15*_t18*_t194*_t368*_t369*_t489*p->cam_omega - _t1354 - 0.7e1 / 0.12e2*_t935))) + (0.64e2 / 0.3e1)*_t1002*_t429 + (0.16e2 / 0.9e1)*_t1006*_t122 - 0.16e2*_t1072 + 0.4e1*_t1099 + 0.4e1*_t1100 - 0.4e1*_t1126 + _t1436 - _t1796 + 0.8e1*_t436*_t489 + (0.8e1 / 0.3e1)*_t995 - 0.80e2 / 0.3e1*_t998;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif