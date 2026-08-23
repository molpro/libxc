/*
  Generated from python/gga_exc/gga_c_zpbeint.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_zpbeint
*/

#ifndef _GGA_C_ZPBEINT_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_ZPBEINT_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_ZPBEINT_HELPER_BODIES
#include "gga_c_zpbeint.c"
#undef _GGA_C_ZPBEINT_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_ZPBEINT_HELPER_BODIES
#include "gga_c_zpbeint.c"
#undef _GGA_C_ZPBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_ZPBEINT_HELPER_BODIES
#include "gga_c_zpbeint.c"
#undef _GGA_C_ZPBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_ZPBEINT_HELPER_BODIES
#include "gga_c_zpbeint.c"
#undef _GGA_C_ZPBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_ZPBEINT_HELPER_BODIES
#include "gga_c_zpbeint.c"
#undef _GGA_C_ZPBEINT_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_zpbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_ZPBEINT_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = 0.01328816518*rs + 0.062181399999999998;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = (rs * rs);
  const double _t6 = 0.10186556948*_t3 + 0.47231125997999995*_t4 + 0.030651699315999998*_t5 + 0.22308199064000001*rs;
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = xc_log1p(_t7);
  const double _t9 = _t2*_t8;
  const double _t10 = 0.029729725187999999*_t3 + 0.3497952466*_t4 + 0.016775784198*_t5 + 0.12236585478000001*rs;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_log1p(_t11);
  const double _t13 = -0.00375733525*rs - 0.0337738;
  const double _t14 = 0.58482236226346462*_t13;
  const double _t15 = _t12*_t14;
  const double _t16 = (zeta * zeta * zeta * zeta);
  const double _t17 = 0.0063885170359999997*rs + 0.031090699999999999;
  const double _t18 = -_t17;
  const double _t19 = 0.10465751433999999*_t3 + 0.43896648423000001*_t4 + 0.019436972918999998*_t5 + 0.19269083139000001*rs;
  const double _t20 = (0.1e1 / _t19);
  const double _t21 = xc_log1p(_t20);
  const double _t22 = _t15 + _t18*_t21 - _t9;
  const double _t23 = _t16*_t22;
#if _KMAX >= 1
  const double _t24 = _hc0[0]*_t22;
  const double _t25 = (zeta * zeta * zeta);
  const double _t26 = 0.4e1*_t25;
  const double _t27 = 0.0021973736767207854*_t12;
  const double _t28 = sqrt(rs);
  const double _t29 = (0.1e1 / _t4);
  const double _t30 = -0.15698627151*_t28 - 0.219483242115*_t29 - 0.038873945837999996*rs - 0.19269083139000001;
  const double _t31 = (0.1e1 / (_t19 * _t19));
  const double _t32 = _t20 + 0.1e1;
  const double _t33 = (0.1e1 / _t32);
  const double _t34 = -0.044594587781999998*_t28 - 0.1748976233*_t29 - 0.033551568396000001*rs - 0.12236585478000001;
  const double _t35 = (0.1e1 / (_t10 * _t10));
  const double _t36 = _t11 + 0.1e1;
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = _t7 + 0.1e1;
  const double _t39 = (0.1e1 / _t38);
  const double _t40 = _t39/(_t6 * _t6);
  const double _t41 = -0.15279835421999999*_t28 - 0.23615562998999998*_t29 - 0.061303398631999996*rs - 0.22308199064000001;
  const double _t42 = _t2*_t41;
  const double _t43 = _t40*_t42 - 0.01328816518*_t8;
  const double _t44 = 0.58482236226346462*_t13*_t34*_t35*_t37 + _t18*_t30*_t31*_t33 - 0.0063885170359999997*_t21 - _t27 - _t43;
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
  const double _t54 = 0.026576330360000001*_t40*_t41;
  const double _t55 = 0.0043947473534415708*_t47;
  const double _t56 = (0.1e1 / _t28);
  const double _t57 = xc_powr(rs, -3, 2);
  const double _t58 = -0.076399177109999994*_t56 + 0.11807781499499999*_t57 - 0.061303398631999996;
  const double _t59 = _t40*_t58;
  const double _t60 = _t2*_t59;
  const double _t61 = -0.022297293890999999*_t56 + 0.08744881165*_t57 - 0.033551568396000001;
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
  const double _t76 = -0.30559670843999998*_t28 - 0.47231125997999995*_t29 - 0.12260679726399999*rs - 0.44616398128000001;
  const double _t77 = _t42*_t76;
  const double _t78 = _t75*_t77;
  const double _t79 = _t37/(_t10 * _t10 * _t10);
  const double _t80 = -0.089189175563999995*_t28 - 0.3497952466*_t29 - 0.067103136792000001*rs - 0.24473170956000001;
  const double _t81 = _t34*_t80;
  const double _t82 = _t79*_t81;
  const double _t83 = _t14*_t82;
  const double _t84 = _t31*_t33;
  const double _t85 = -0.078493135754999999*_t56 + 0.1097416210575*_t57 - 0.038873945837999996;
  const double _t86 = _t84*_t85;
  const double _t87 = 0.0021973736767207854*rs + 0.019751673498613801;
  const double _t88 = (0.1e1 / (_t19 * _t19 * _t19 * _t19));
  const double _t89 = (0.1e1 / (_t32 * _t32));
  const double _t90 = (_t30 * _t30);
  const double _t91 = _t89*_t90;
  const double _t92 = _t88*_t91;
  const double _t93 = _t2*_t64;
  const double _t94 = _t33/(_t19 * _t19 * _t19);
  const double _t95 = -0.31397254301999999*_t28 - 0.43896648423000001*_t29 - 0.077747891675999992*rs - 0.38538166278000002;
  const double _t96 = _t18*_t30;
  const double _t97 = _t95*_t96;
  const double _t98 = _t17*_t92 + _t18*_t86 - 0.012777034071999999*_t30*_t84 + _t54 - _t55 - _t60 + _t63 + _t67*_t93 + _t73*_t87 - _t78 + _t83 + _t94*_t97;
  const double _t99 = _t16*_t98;
#endif
#if _KMAX >= 3
  const double _t100 = 0.24e2*_t24;
  const double _t101 = _t22*_t49;
  const double _t102 = 0.36e2*_hc0[1];
  const double _t103 = 0.12e2*_hc0[2];
  const double _t104 = _t25*_t44;
  const double _t105 = _hc0[0]*_t98;
  const double _t106 = 0.039864495540000003*_t59;
  const double _t107 = 0.0065921210301623562*_t62;
  const double _t108 = (0.1e1 / _t3);
  const double _t109 = xc_powr(rs, -5, 2);
  const double _t110 = 0.038199588554999997*_t108 - 0.17711672249249999*_t109;
  const double _t111 = _t110*_t40;
  const double _t112 = _t111*_t2;
  const double _t113 = 0.039864495540000003*_t68;
  const double _t114 = 0.011148646945499999*_t108 - 0.13117321747499999*_t109;
  const double _t115 = _t114*_t46;
  const double _t116 = _t115*_t14;
  const double _t117 = 0.0065921210301623562*_t73;
  const double _t118 = 0.026576330360000001*rs + 0.1243628;
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
  const double _t129 = 1.1696447245269292*_t13;
  const double _t130 = _t128*_t129;
  const double _t131 = _t41*_t75;
  const double _t132 = 0.039864495540000003*_t131*_t76;
  const double _t133 = 0.0065921210301623562*_t82;
  const double _t134 = -0.15279835421999999*_t56 + 0.23615562998999998*_t57 - 0.12260679726399999;
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
  const double _t145 = -0.044594587781999998*_t56 + 0.1748976233*_t57 - 0.067103136792000001;
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
  const double _t157 = -0.61119341687999995*_t28 - 0.94462251995999991*_t29 - 0.24521359452799998*rs - 0.89232796256000002;
  const double _t158 = xc_powi(_t6, -5);
  const double _t159 = _t158*_t67;
  const double _t160 = _t159*_t2;
  const double _t161 = _t157*_t160;
  const double _t162 = _t160*_t76;
  const double _t163 = -0.17837835112799999*_t28 - 0.6995904932*_t29 - 0.134206273584*rs - 0.48946341912000002;
  const double _t164 = xc_powi(_t10, -5);
  const double _t165 = _t164*_t72;
  const double _t166 = _t14*_t165;
  const double _t167 = _t163*_t166;
  const double _t168 = _t166*_t80;
  const double _t169 = -0.45839506265999996*_t28 - 0.70846688996999996*_t29 - 0.18391019589599999*rs - 0.66924597192000002;
  const double _t170 = _t169*_t39;
  const double _t171 = _t170*_t64;
  const double _t172 = _t171*_t77;
  const double _t173 = -0.13378376334600001*_t28 - 0.52469286989999997*_t29 - 0.100654705188*rs - 0.36709756434000002;
  const double _t174 = _t173*_t37*_t69;
  const double _t175 = _t174*_t81;
  const double _t176 = _hc0[0]*_t14;
  const double _t177 = 0.039246567877499999*_t108 - 0.16461243158625*_t109;
  const double _t178 = _t177*_t84;
  const double _t179 = (_t30 * _t30 * _t30);
  const double _t180 = (0.1e1 / (_t32 * _t32 * _t32));
  const double _t181 = xc_powi(_t19, -6);
  const double _t182 = _t180*_t181;
  const double _t183 = _t179*_t182;
  const double _t184 = _t30*_t94;
  const double _t185 = -0.15698627151*_t56 + 0.219483242115*_t57 - 0.077747891675999992;
  const double _t186 = _t185*_t96;
  const double _t187 = _t88*_t89;
  const double _t188 = _t187*_t85;
  const double _t189 = _t94*_t95;
  const double _t190 = _t189*_t85;
  const double _t191 = 0.2e1*_t18;
  const double _t192 = -0.62794508603999999*_t28 - 0.87793296846000002*_t29 - 0.15549578335199998*rs - 0.77076332556000005;
  const double _t193 = xc_powi(_t19, -5);
  const double _t194 = _t193*_t91;
  const double _t195 = _t18*_t194;
  const double _t196 = -0.47095881452999999*_t28 - 0.65844972634499999*_t29 - 0.11662183751399999*rs - 0.57807249417000006;
  const double _t197 = _t196*_t33*_t88;
  const double _t198 = _t14*_t175;
  const double _t199 = _t106 - _t107 - _t112 - _t113 + _t116 + _t117 + _t118*_t123 + _t128*(-0.0043947473534415708*rs - 0.039503346997227602) + _t132 - _t133 - _t136 + _t139 + _t140 - _t144 - _t149 - _t151 + _t153 + _t156 + _t161 + _t162 - _t167 - _t168 - _t172 + _t178*_t18 + _t183*(-0.012777034071999999*rs - 0.062181399999999998) - 0.019165551108000001*_t184*_t95 - _t186*_t187 + _t186*_t94 - _t188*_t96 + _t190*_t191 - _t192*_t195 - _t195*_t95 + _t197*_t97 + _t198 - 0.019165551108000001*_t86 + 0.019165551108000001*_t92;
  const double _t200 = _t16*_t199;
#endif
#if _KMAX >= 4
  const double _t201 = 0.053152660720000001*_t111;
  const double _t202 = 0.0087894947068831416*_t115;
  const double _t203 = pow(rs, -2.5);
  const double _t204 = xc_powr(rs, -7, 2);
  const double _t205 = _t2*_t40*(-0.057299382832499995*_t203 + 0.44279180623124997*_t204);
  const double _t206 = 0.10630532144*_t123;
  const double _t207 = _t14*_t46*(-0.016722970418250001*_t203 + 0.32793304368749998*_t204);
  const double _t208 = 0.017578989413766283*_t128;
  const double _t209 = (_t58 * _t58)*_t65;
  const double _t210 = _t146*(_t61 * _t61);
  const double _t211 = 0.079728991080000006*rs + 0.37308839999999999;
  const double _t212 = (_t41 * _t41 * _t41 * _t41)/((_t38 * _t38 * _t38 * _t38)*xc_powi(_t6, 8));
  const double _t213 = (_t34 * _t34 * _t34 * _t34)/(xc_powi(_t10, 8)*(_t36 * _t36 * _t36 * _t36));
  const double _t214 = 0.053152660720000001*_t134;
  const double _t215 = _t137*_t41;
  const double _t216 = _t214*_t215;
  const double _t217 = 0.053152660720000001*_t215*_t58;
  const double _t218 = _t131*_t214;
  const double _t219 = 0.10630532144*_t142;
  const double _t220 = 0.0087894947068831416*_t34;
  const double _t221 = _t145*_t220;
  const double _t222 = _t146*_t221;
  const double _t223 = _t150*_t220;
  const double _t224 = _t221*_t79;
  const double _t225 = 0.017578989413766283*_t155;
  const double _t226 = _t134*_t58;
  const double _t227 = _t226*_t65*_t93;
  const double _t228 = 0.3e1*_t2;
  const double _t229 = _t226*_t228*_t75;
  const double _t230 = _t14*_t145;
  const double _t231 = _t150*_t230;
  const double _t232 = 1.7544670867903939*_t13;
  const double _t233 = _t232*_t61;
  const double _t234 = _t152*_t233;
  const double _t235 = 0.076399177109999994*_t108 - 0.35423344498499998*_t109;
  const double _t236 = _t135*_t235;
  const double _t237 = 0.032486556321720157*_t28 + 0.050209200311905303*_t29 + 0.013033754993878433*rs + 0.047429605444920545;
  const double _t238 = 0.016243278160860079*_t28 + 0.025104600155952651*_t29 + 0.0065168774969392163*rs + 0.023714802722460272;
  const double _t239 = 0.2e1*_t110*_t138;
  const double _t240 = _t138*_t235;
  const double _t241 = _t110*_t141*_t228;
  const double _t242 = _t114*_t129*_t146*_t34;
  const double _t243 = 0.022297293890999999*_t108 - 0.26234643494999998*_t109;
  const double _t244 = _t148*_t243;
  const double _t245 = _t114*_t154*_t232;
  const double _t246 = _t147*_t243*_t79;
  const double _t247 = 0.0087894947068831416*_t165;
  const double _t248 = _hc0[0]*_t163;
  const double _t249 = _hc0[0]*_t80;
  const double _t250 = -0.22919753132999998*_t56 + 0.35423344498499998*_t57 - 0.18391019589599999;
  const double _t251 = _t122*_t143*_t66;
  const double _t252 = _t250*_t251;
  const double _t253 = _t134*_t251;
  const double _t254 = _t251*_t58;
  const double _t255 = _t160*(-0.30559670843999998*_t56 + 0.47231125997999995*_t57 - 0.24521359452799998);
  const double _t256 = 0.2e1*_t134;
  const double _t257 = _t160*_t256;
  const double _t258 = -0.066891881673000003*_t56 + 0.26234643494999998*_t57 - 0.100654705188;
  const double _t259 = _t127*_t71;
  const double _t260 = _t129*_t259;
  const double _t261 = _t258*_t260;
  const double _t262 = _t145*_t260;
  const double _t263 = _t129*_t61;
  const double _t264 = _t259*_t263;
  const double _t265 = _t166*(-0.089189175563999995*_t56 + 0.3497952466*_t57 - 0.134206273584);
  const double _t266 = _t129*_t145;
  const double _t267 = _t165*_t266;
  const double _t268 = _t119*_t120*_t143/xc_powi(_t6, 7);
  const double _t269 = _t268*(-0.91679012531999993*_t28 - 1.4169337799399999*_t29 - 0.36782039179199999*rs - 1.33849194384);
  const double _t270 = _t157*_t268;
  const double _t271 = _t268*_t76;
  const double _t272 = _t124*_t125*_t129/xc_powi(_t10, 7);
  const double _t273 = _t272*(-0.26756752669200001*_t28 - 1.0493857397999999*_t29 - 0.201309410376*rs - 0.73419512868000003);
  const double _t274 = _t163*_t272;
  const double _t275 = _t272*_t80;
  const double _t276 = 0.053152660720000001*_t171*_t41*_t76;
  const double _t277 = 0.0087894947068831416*_t175;
  const double _t278 = _t250*_t39*_t64*_t77;
  const double _t279 = _t158*_t65;
  const double _t280 = _t157*_t42;
  const double _t281 = _t256*_t279*_t280;
  const double _t282 = _t134*_t279*_t77;
  const double _t283 = _t279*_t58;
  const double _t284 = _t280*_t283;
  const double _t285 = 0.2e1*_t283*_t77;
  const double _t286 = _t171*_t256*_t42;
  const double _t287 = 0.3e1*_t170*_t58*_t76*_t93;
  const double _t288 = _t266*_t34;
  const double _t289 = _t164*_t70;
  const double _t290 = _t248*_t289;
  const double _t291 = _t289*_t81;
  const double _t292 = _t230*_t291;
  const double _t293 = _t147*_t61;
  const double _t294 = _t263*_t291;
  const double _t295 = _t258*_t69;
  const double _t296 = _t37*_t81;
  const double _t297 = _t176*_t296;
  const double _t298 = _t174*_t288;
  const double _t299 = _t174*_t233;
  const double _t300 = -0.76399177109999994*_t28 - 1.1807781499499999*_t29 - 0.30651699315999997*rs - 1.1154099531999999;
  const double _t301 = _t121*_t157*_t2*_t300*_t67;
  const double _t302 = _t121*_t2*_t67*_t76;
  const double _t303 = _t300*_t302;
  const double _t304 = _t169*_t302;
  const double _t305 = -0.22297293890999997*_t28 - 0.87448811650000002*_t29 - 0.16775784197999999*rs - 0.61182927389999997;
  const double _t306 = _t126*_t163*_t305*_t72;
  const double _t307 = _t126*_t72*_t80;
  const double _t308 = _t176*_t307;
  const double _t309 = _t157*_t158*_t170*_t77;
  const double _t310 = _t163*_t164*_t173;
  const double _t311 = 0.025554068143999999*_t30;
  const double _t312 = _t18*_t185;
  const double _t313 = _t96*(0.078493135754999999*_t108 - 0.32922486317249999*_t109);
  const double _t314 = 0.3e1*_t18;
  const double _t315 = -0.235479407265*_t56 + 0.32922486317249999*_t57 - 0.11662183751399999;
  const double _t316 = _t182*_t90;
  const double _t317 = _t191*_t316;
  const double _t318 = _t179*_t180*_t191/xc_powi(_t19, 7);
  const double _t319 = _t197*_t95;
  const double _t320 = _t33*_t97;
  const double _t321 = _t163*_t289;
  const double _t322 = _t14*_t296;
  const double _t323 = _t193*_t89;
  const double _t324 = 0.2e1*_t186;
  const double _t325 = _t323*_t85;
  const double _t326 = _t14*_t307;
  const double _t327 = -0.78493135754999999*_t28 - 1.0974162105750001*_t29 - 0.19436972918999998*rs - 0.96345415695000003;
  const double _t328 = _t18*_t181*_t91;
  const double _t329 = _t328*_t95;
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
  const double d4f_drs4 = 3.5089341735807877*_hc0[0]*_t13*_t213 + _hc0[0]*_t16*(-_t14*_t306 + _t159*_t237 + _t159*_t238 + _t165*(-0.0015678555730620984*_t28 - 0.0061490469369671664*_t29 - 0.0011796053312970788*rs - 0.0043021361315681648) + _t165*(-0.00078392778653104919*_t28 - 0.0030745234684835832*_t29 - 0.0005898026656485394*rs - 0.0021510680657840824) + _t17*_t187*(_t85 * _t85) - _t173*_t326 - 0.2e1*_t177*_t187*_t96 + _t177*_t189*_t314 - 0.025554068143999999*_t178 + _t18*_t84*(-0.058869851816249999*_t203 + 0.41153107896562502*_t204) - 0.051108136287999997*_t183 - 0.025554068143999999*_t184*_t185 + _t185*_t187*_t311 - 0.2e1*_t185*_t195 - _t185*_t323*_t97 - _t187*_t313 + _t188*_t311 - _t188*_t312 - 0.051108136287999997*_t190 + _t192*_t193*_t196*_t320 + _t192*_t318 - _t192*_t323*_t324 - _t192*_t325*_t96 - _t192*_t327*_t328 + _t194*(-0.016046551519356102*_t28 - 0.022434758901891044*_t29 - 0.0039735498438816684*rs - 0.019696138544256298) + _t194*(-0.0080232757596780512*_t28 - 0.011217379450945522*_t29 - 0.0019867749219408342*rs - 0.0098480692721281491) - _t195*(-0.31397254301999999*_t56 + 0.43896648423000001*_t57 - 0.15549578335199998) - _t196*_t329 + _t197*_t324 + _t201 - _t202 - _t205 + _t206 + _t207 - _t208 + _t209*_t93 + _t210*_t87 - _t211*_t212 + _t213*(0.013184242060324712*rs + 0.11851004099168281) - _t216 - _t217 + _t218 + _t219 + _t222 + _t223 - _t224 - _t225 + _t227 - _t229 - _t231 + _t234 - _t236 + _t239 + _t240 - _t241 - _t242 - _t244 + _t245 + _t246 - _t252 - _t253 - _t254 + _t255 + _t257 + _t261 + _t262 + _t264 - _t265 - _t267 - _t269 - _t270 - _t271 + _t273 + _t274 + _t275 + _t276 - _t277 - _t278 + _t281 + _t282 + _t284 + _t285 - _t286 - _t287 - _t288*_t321 - _t292 - _t293*_t321 - _t294 + _t295*_t322 + _t298 + _t299*_t80 + _t301 + _t303 + _t304 - _t305*_t326 - _t309 + _t310*_t322 - _t311*_t319 + 0.2e1*_t312*_t316 + 0.3e1*_t312*_t85*_t94 + _t313*_t94 + _t314*_t319*_t85 + _t315*_t317 + _t315*_t320*_t88 + _t317*_t85 + _t318*_t95 + _t318*(-0.94191762905999998*_t28 - 1.31689945269*_t29 - 0.23324367502799997*rs - 1.1561449883400001) - 0.2e1*_t325*_t97 - _t327*_t329 + (_t30 * _t30 * _t30 * _t30)*(0.038331102216000001*rs + 0.18654419999999999)/(xc_powi(_t19, 8)*(_t32 * _t32 * _t32 * _t32))) + _hc0[0]*_t202 - _hc0[0]*_t207 + _hc0[0]*_t208 - _hc0[0]*_t222 - _hc0[0]*_t223 + _hc0[0]*_t224 + _hc0[0]*_t225 + _hc0[0]*_t231 - _hc0[0]*_t234 + _hc0[0]*_t242 + _hc0[0]*_t244 - _hc0[0]*_t245 - _hc0[0]*_t246 - _hc0[0]*_t261 - _hc0[0]*_t262 - _hc0[0]*_t264 + _hc0[0]*_t265 + _hc0[0]*_t267 - _hc0[0]*_t273 - _hc0[0]*_t274 - _hc0[0]*_t275 + _hc0[0]*_t277 + _hc0[0]*_t292 + _hc0[0]*_t294 - _hc0[0]*_t298 + _t1*_t209*_t64 - _t159*_t237 - _t159*_t238 + _t173*_t308 + _t176*_t210 + _t176*_t306 - _t201 + _t205 - _t206 + _t211*_t212 + _t216 + _t217 - _t218 - _t219 - _t227 + _t229 + _t236 - _t239 - _t240 + _t241 - _t247*_t248 - _t247*_t249 - _t249*_t299 + _t252 + _t253 + _t254 - _t255 - _t257 + _t269 + _t270 + _t271 - _t276 + _t278 - _t281 - _t282 - _t284 - _t285 + _t286 + _t287 + _t288*_t290 + _t290*_t293 - _t295*_t297 - _t297*_t310 - _t301 - _t303 - _t304 + _t305*_t308 + _t309;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeta_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {
  const gga_c_zpbeint_params *params = (const gga_c_zpbeint_params *)(p->params);


  const double f = params->beta;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_drs = 0;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = 0;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = 0;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = 0;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = 0;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = 0;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = 0;
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = 0;
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = 0;
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = 0;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tp_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t3 = _t1/_t2;
  const double _t4 = xc_powr(rs, -1, 2);
  const double _t5 = (0.1e1 / 0.8e1)*_t4;
  const double _t6 = _t3*_t5;
#if _KMAX >= 1
  const double _t7 = -0.1e1 / 0.2e1*_hc0[2] + (0.1e1 / 0.2e1)*_hc1[2];
  const double _t8 = _t1/(_t2 * _t2);
  const double _t9 = _t5*_t8;
  const double _t10 = _t7*_t9;
  const double _t11 = xc_powr(rs, -3, 2);
  const double _t12 = (0.1e1 / 0.16e2)*_t11;
  const double _t13 = _t12*_t3;
#endif
#if _KMAX >= 2
  const double _t14 = -0.1e1 / 0.2e1*_hc0[5] - 0.1e1 / 0.2e1*_hc1[5];
  const double _t15 = _t14*_t9;
  const double _t16 = -_hc0[2] + _hc1[2];
  const double _t17 = _t1/(_t2 * _t2 * _t2);
  const double _t18 = _t16*_t17;
  const double _t19 = _t5*_t7;
  const double _t20 = _t18*_t19;
  const double _t21 = _t12*_t8;
  const double _t22 = _t21*_t7;
  const double _t23 = (0.3e1 / 0.32e2)/xc_powr(rs, 5, 2);
  const double _t24 = _t23*_t3;
#endif
#if _KMAX >= 3
  const double _t25 = -0.1e1 / 0.2e1*_hc0[9] + (0.1e1 / 0.2e1)*_hc1[9];
  const double _t26 = _t25*_t9;
  const double _t27 = _t18*_t4;
  const double _t28 = (0.1e1 / 0.4e1)*_t14*_t27;
  const double _t29 = -_hc0[5] - _hc1[5];
  const double _t30 = _t17*_t19;
  const double _t31 = _t29*_t30;
  const double _t32 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t33 = -0.3e1 / 0.2e1*_hc0[2] + (0.3e1 / 0.2e1)*_hc1[2];
  const double _t34 = _t1*_t32*_t33;
  const double _t35 = _t16*_t19;
  const double _t36 = _t34*_t35;
  const double _t37 = _t14*_t21;
  const double _t38 = _t12*_t7;
  const double _t39 = _t18*_t38;
  const double _t40 = _t23*_t8;
  const double _t41 = _t40*_t7;
  const double _t42 = (0.15e2 / 0.64e2)/xc_powr(rs, 7, 2);
  const double _t43 = _t3*_t42;
#endif
#if _KMAX >= 4
  const double _t44 = _t25*xt;
  const double _t45 = _t17*_t29;
  const double _t46 = _t14*xt;
  const double _t47 = (0.3e1 / 0.8e1)*_t4*_t46;
  const double _t48 = _t16*_t34;
  const double _t49 = _t1*_t35*xt;
  const double _t50 = _t7*xt;
  const double _t51 = _t38*xt;
#endif

  const double f = _t6*xt;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t6;
  out[1] = df_dxt;
  const double df_dz = _t10*xt;
  out[2] = df_dz;
  const double df_drs = -_t13*xt;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = 0;
  out[4] = d2f_dxt2;
  const double d2f_dz_dxt = _t10;
  out[5] = d2f_dz_dxt;
  const double d2f_dz2 = _t15*xt + _t20*xt;
  out[6] = d2f_dz2;
  const double d2f_drs_dxt = -_t13;
  out[7] = d2f_drs_dxt;
  const double d2f_drs_dz = -_t22*xt;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _t24*xt;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0;
  out[10] = d3f_dxt3;
  const double d3f_dz_dxt2 = 0;
  out[11] = d3f_dz_dxt2;
  const double d3f_dz2_dxt = _t15 + _t20;
  out[12] = d3f_dz2_dxt;
  const double d3f_dz3 = _t26*xt + _t28*xt + _t31*xt + _t36*xt;
  out[13] = d3f_dz3;
  const double d3f_drs_dxt2 = 0;
  out[14] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxt = -_t22;
  out[15] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = -_t37*xt - _t39*xt;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dxt = _t24;
  out[17] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _t41*xt;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = -_t43*xt;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = 0;
  out[20] = d4f_dxt4;
  const double d4f_dz_dxt3 = 0;
  out[21] = d4f_dz_dxt3;
  const double d4f_dz2_dxt2 = 0;
  out[22] = d4f_dz2_dxt2;
  const double d4f_dz3_dxt = _t26 + _t28 + _t31 + _t36;
  out[23] = d4f_dz3_dxt;
  const double d4f_dz4 = (0.3e1 / 0.8e1)*_t27*_t44 + (0.1e1 / 0.4e1)*_t29*_t34*_t4*_t50 + _t30*xt*(-_hc0[9] + _hc1[9]) + _t32*_t49*(-0.3e1 / 0.2e1*_hc0[5] - 0.3e1 / 0.2e1*_hc1[5]) + _t45*_t47 + _t47*_t48 + _t9*xt*(-0.1e1 / 0.2e1*_hc0[14] - 0.1e1 / 0.2e1*_hc1[14]) + _t33*_t49*(-0.2e1*_hc0[2] + 0.2e1*_hc1[2])/xc_powi(_t2, 5);
  out[24] = d4f_dz4;
  const double d4f_drs_dxt3 = 0;
  out[25] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxt2 = 0;
  out[26] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxt = -_t37 - _t39;
  out[27] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = -0.1e1 / 0.8e1*_t11*_t18*_t46 - _t21*_t44 - _t45*_t51 - _t48*_t51;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dxt2 = 0;
  out[29] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxt = _t41;
  out[30] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = _t18*_t23*_t50 + _t40*_t46;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dxt = -_t43;
  out[32] = d4f_drs3_dxt;
  const double d4f_drs3_dz = -_t42*_t50*_t8;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = (0.105e3 / 0.128e3)*_t3*xt/xc_powr(rs, 9, 2);
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(A_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, 0, 0, _hc3);
  const double _t1 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t2 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t3 = (M_PI * M_PI);
  const double _t4 = 0.1e1 - M_LN2;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t3*_t5;
  const double _t7 = _t2*_t6;
  const double _t8 = xc_expm1(-_hc2[0]*_t7);
  const double _t9 = _hc3[0]*_t6;
#if _KMAX >= 1
  const double _t10 = _t8 + 0.1e1;
  const double _t11 = _t10/(_t8 * _t8);
  const double _t12 = _hc2[1]*_t7;
  const double _t13 = -0.3e1 / 0.2e1*_hc0[2] + (0.3e1 / 0.2e1)*_hc1[2];
  const double _t14 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t15 = _t14*_t6;
  const double _t16 = _hc2[0]*_t15;
  const double _t17 = _t13*_t16;
  const double _t18 = -_t12 - _t17;
  const double _t19 = _t11*_t18*_t9;
  const double _t20 = _hc3[0]*_t11;
  const double _t21 = _hc2[2]*_t20;
  const double _t22 = (M_PI * M_PI * M_PI * M_PI)/(_t4 * _t4);
  const double _t23 = _t2*_t22;
  const double _t24 = _t21*_t23;
#endif
#if _KMAX >= 2
  const double _t25 = (_t18 * _t18);
  const double _t26 = _t11*_t9;
  const double _t27 = _t25*_t26;
  const double _t28 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t29 = (_t10 * _t10);
  const double _t30 = _hc2[3]*_t7;
  const double _t31 = -0.3e1 / 0.2e1*_hc0[5] - 0.3e1 / 0.2e1*_hc1[5];
  const double _t32 = _t16*_t31;
  const double _t33 = _hc2[1]*_t15;
  const double _t34 = 0.2e1*_t13;
  const double _t35 = xc_powi(_t1, -5);
  const double _t36 = _t13*_t35;
  const double _t37 = -0.2e1*_hc0[2] + 0.2e1*_hc1[2];
  const double _t38 = _hc2[0]*_t6;
  const double _t39 = _t37*_t38;
  const double _t40 = _t36*_t39;
  const double _t41 = -_t30 - _t32 - _t33*_t34 - _t40;
  const double _t42 = _t26*_t41;
  const double _t43 = _t20*_t23;
  const double _t44 = _hc2[4]*_t43;
  const double _t45 = _t14*_t22;
  const double _t46 = _t21*_t45;
  const double _t47 = _t18*_t24;
  const double _t48 = _hc2[2]*_t18;
  const double _t49 = _t28*_t29;
  const double _t50 = 0.2e1*_t49;
  const double _t51 = _hc3[0]*_t50;
  const double _t52 = _t23*_t51;
  const double _t53 = _t48*_t52;
  const double _t54 = _hc2[5]*_t43;
  const double _t55 = ((_hc2[2]) * (_hc2[2]));
  const double _t56 = _t20*_t55;
  const double _t57 = xc_powi(_t1, -6);
  const double _t58 = xc_powi(M_PI, 6)/(_t4 * _t4 * _t4);
  const double _t59 = _t57*_t58;
  const double _t60 = _t56*_t59;
  const double _t61 = _hc3[0]*_t59;
  const double _t62 = _t55*_t61;
  const double _t63 = _t50*_t62;
#endif
#if _KMAX >= 3
  const double _t64 = (_t18 * _t18 * _t18);
  const double _t65 = (_t10 * _t10 * _t10)/(_t8 * _t8 * _t8 * _t8);
  const double _t66 = 0.6e1*_t65;
  const double _t67 = _t64*_t66*_t9;
  const double _t68 = -0.2e1*_t12 - 0.2e1*_t17;
  const double _t69 = 0.4e1*_t33;
  const double _t70 = _t35*_t39;
  const double _t71 = -_t13*_t69 - 0.2e1*_t30 - 0.2e1*_t32 - _t34*_t70;
  const double _t72 = _hc2[6]*_t7;
  const double _t73 = -0.3e1 / 0.2e1*_hc0[9] + (0.3e1 / 0.2e1)*_hc1[9];
  const double _t74 = _t16*_t73;
  const double _t75 = _t31*_t33;
  const double _t76 = _hc2[3]*_t15;
  const double _t77 = 0.3e1*_t13;
  const double _t78 = -0.2e1*_hc0[5] - 0.2e1*_hc1[5];
  const double _t79 = _t36*_t38;
  const double _t80 = _t31*_t70;
  const double _t81 = _hc2[1]*_t6;
  const double _t82 = _t36*_t37;
  const double _t83 = 0.3e1*_t82;
  const double _t84 = -0.5e1 / 0.2e1*_hc0[2] + (0.5e1 / 0.2e1)*_hc1[2];
  const double _t85 = _t57*_t84;
  const double _t86 = _t13*_t39;
  const double _t87 = -_t72 - _t74 - 0.3e1*_t75 - _t76*_t77 - _t78*_t79 - 0.2e1*_t80 - _t81*_t83 - _t85*_t86;
  const double _t88 = _hc2[7]*_t43;
  const double _t89 = _t31*_t46;
  const double _t90 = _t20*_t45;
  const double _t91 = _hc2[4]*_t90;
  const double _t92 = _t21*_t22;
  const double _t93 = 0.2e1*_t18;
  const double _t94 = _hc2[4]*_t18;
  const double _t95 = 0.4e1*_t49;
  const double _t96 = _hc3[0]*_t23;
  const double _t97 = _t95*_t96;
  const double _t98 = _hc2[2]*_t52;
  const double _t99 = _t25*_t98;
  const double _t100 = _hc2[2]*_t96;
  const double _t101 = _t25*_t66;
  const double _t102 = _t100*_t101;
  const double _t103 = _t18*_t34;
  const double _t104 = 0.4e1*_t13;
  const double _t105 = _hc3[0]*_t49;
  const double _t106 = _t105*_t45;
  const double _t107 = _t104*_t106;
  const double _t108 = _hc2[8]*_t43;
  const double _t109 = _t21*_t59;
  const double _t110 = 0.2e1*_t109;
  const double _t111 = _t61*_t95;
  const double _t112 = _hc2[2]*_t111;
  const double _t113 = _hc2[5]*_t90;
  const double _t114 = xc_powi(_t1, -7);
  const double _t115 = -0.3e1*_hc0[2] + 0.3e1*_hc1[2];
  const double _t116 = _t114*_t115;
  const double _t117 = _t56*_t58;
  const double _t118 = _t116*_t117;
  const double _t119 = _t116*_t58;
  const double _t120 = _t51*_t55;
  const double _t121 = _hc2[5]*_t52;
  const double _t122 = _t121*_t18;
  const double _t123 = _t18*_t63;
  const double _t124 = _t62*_t66;
  const double _t125 = _t124*_t18;
  const double _t126 = _hc2[9]*_t43;
  const double _t127 = ((_hc2[2]) * (_hc2[2]) * (_hc2[2]));
  const double _t128 = xc_powi(M_PI, 8);
  const double _t129 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t130 = _t128*_t129/xc_powi(_t1, 9);
  const double _t131 = _t127*_t130;
  const double _t132 = _t131*_t20;
  const double _t133 = 0.3e1*_t109;
  const double _t134 = _hc2[5]*_t133;
  const double _t135 = 0.6e1*_t49;
  const double _t136 = _t135*_t61;
  const double _t137 = _hc2[2]*_t136;
  const double _t138 = _hc2[5]*_t137;
  const double _t139 = _hc3[0]*_t131;
  const double _t140 = _t135*_t139;
  const double _t141 = _t139*_t66;
#endif
#if _KMAX >= 4
  const double _t142 = (_t18 * _t18 * _t18 * _t18);
  const double _t143 = xc_powi(_t8, -5);
  const double _t144 = (_t10 * _t10 * _t10 * _t10);
  const double _t145 = -0.3e1*_t12 - 0.3e1*_t17;
  const double _t146 = (_t68 * _t68);
  const double _t147 = (_t41 * _t41);
  const double _t148 = 0.6e1*_t13;
  const double _t149 = -_t148*_t33 - 0.3e1*_t30 - 0.3e1*_t32 - 0.3e1*_t40;
  const double _t150 = _t25*_t66*_t9;
  const double _t151 = 0.6e1*_t76;
  const double _t152 = _t38*_t78;
  const double _t153 = _t152*_t34;
  const double _t154 = 0.6e1*_t82;
  const double _t155 = _t39*_t85;
  const double _t156 = -_t13*_t151 - _t153*_t35 - _t154*_t81 - _t155*_t34 - 0.2e1*_t72 - 0.2e1*_t74 - 0.6e1*_t75 - 0.4e1*_t80;
  const double _t157 = _t31*_t35;
  const double _t158 = _t37*_t81;
  const double _t159 = _t36*_t78;
  const double _t160 = 0.3e1*_t31;
  const double _t161 = _t37*_t92;
  const double _t162 = _t20*_t22;
  const double _t163 = 0.3e1*_t18;
  const double _t164 = 0.3e1*_t44;
  const double _t165 = _t135*_t96;
  const double _t166 = _t100*_t64;
  const double _t167 = 0.24e2*_t143*_t144;
  const double _t168 = _hc2[4]*_t165;
  const double _t169 = 0.18e2*_hc2[4];
  const double _t170 = _t169*_t65;
  const double _t171 = _t46*_t77;
  const double _t172 = _hc3[0]*_t45;
  const double _t173 = _hc2[2]*_t25;
  const double _t174 = _t106*_t148;
  const double _t175 = 0.18e2*_t65;
  const double _t176 = _hc2[2]*_t41;
  const double _t177 = _t48*_t96;
  const double _t178 = _t177*_t66;
  const double _t179 = ((_hc2[4]) * (_hc2[4]));
  const double _t180 = _t20*_t59;
  const double _t181 = _hc2[4]*_t119;
  const double _t182 = _t114*(-0.3e1*_hc0[5] - 0.3e1*_hc1[5]);
  const double _t183 = 0.8e1*_hc2[2];
  const double _t184 = _t120*_t58;
  const double _t185 = _t115*(-0.7e1 / 0.2e1*_hc0[2] + (0.7e1 / 0.2e1)*_hc1[2])/xc_powi(_t1, 8);
  const double _t186 = 0.4e1*_t109;
  const double _t187 = _t49*_t61;
  const double _t188 = _t183*_t187;
  const double _t189 = _hc2[4]*_t48;
  const double _t190 = _hc3[0]*_t119;
  const double _t191 = _t190*_t55;
  const double _t192 = _t18*_t191;
  const double _t193 = 0.3e1*_t180;
  const double _t194 = _hc2[4]*_hc2[5];
  const double _t195 = _t130*_t56;
  const double _t196 = _t130*_t55;
  const double _t197 = _t105*_t196;
  const double _t198 = _hc3[0]*_t196;
  const double _t199 = _t127*_t128*_t129*(-0.9e1 / 0.2e1*_hc0[2] + (0.9e1 / 0.2e1)*_hc1[2])/xc_powi(_t1, 10);
  const double _t200 = _hc3[0]*_t199;
  const double _t201 = _hc2[5]*_t48;
  const double _t202 = _t139*_t18;
  const double _t203 = ((_hc2[5]) * (_hc2[5]));
  const double _t204 = xc_powi(M_PI, 10)*((_hc2[2]) * (_hc2[2]) * (_hc2[2]) * (_hc2[2]))/(xc_powi(_t1, 12)*xc_powi(_t4, 5));
  const double _t205 = _hc3[0]*_t204;
  const double _t206 = 0.36e2*_t65;
#endif

  const double f = _t9/_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_dz = -_t19;
  out[2] = df_dz;
  const double df_drs = _t24;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = 0;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = 0.2e1*_hc3[0]*_t25*_t28*_t29*_t3*_t5 - _t27 - _t42;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = 0;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _t13*_t46 + _t44 + _t47 - _t53;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _t54 - _t60 + _t63;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = 0;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = 0;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = 0.2e1*_hc3[0]*_t18*_t28*_t29*_t3*_t41*_t5 + 0.2e1*_hc3[0]*_t18*_t28*_t29*_t3*_t5*_t71 + 0.2e1*_hc3[0]*_t25*_t28*_t29*_t3*_t5*_t68 + 0.2e1*_hc3[0]*_t28*_t29*_t3*_t5*_t64 - _t19*_t41 - _t19*_t71 - _t26*_t64 - _t26*_t87 - _t67;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = 0;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = 0;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _t102 + _t103*_t46 - _t107*_t48 + _t24*_t25 + _t24*_t41 + _t34*_t91 - _t41*_t98 + _t44*_t93 - _t53*_t68 + _t82*_t92 + _t88 + _t89 - _t94*_t97 - _t99;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = 0;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = -_hc2[4]*_t110 + _hc2[4]*_t112 + _t108 + _t113*_t13 - _t118 + _t119*_t120 - _t122 + _t123 - _t125 + _t18*_t54 - _t18*_t60 + _t63*_t68;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _t126 + _t132 - _t134 + _t138 - _t140 + _t141;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[20] = d4f_dt4;
  const double d4f_dz_dt3 = 0;
  out[21] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = 0;
  out[22] = d4f_dz2_dt2;
  const double d4f_dz3_dt = 0;
  out[23] = d4f_dz3_dt;
  const double d4f_dz4 = 0.24e2*_hc3[0]*_t142*_t143*_t144*_t3*_t5 + 0.2e1*_hc3[0]*_t142*_t28*_t29*_t3*_t5 + 0.2e1*_hc3[0]*_t146*_t25*_t28*_t29*_t3*_t5 + 0.2e1*_hc3[0]*_t147*_t28*_t29*_t3*_t5 + 0.2e1*_hc3[0]*_t149*_t25*_t28*_t29*_t3*_t5 + 0.2e1*_hc3[0]*_t156*_t18*_t28*_t29*_t3*_t5 + 0.2e1*_hc3[0]*_t18*_t28*_t29*_t3*_t41*_t5*_t68 + 0.4e1*_hc3[0]*_t18*_t28*_t29*_t3*_t5*_t68*_t71 + 0.4e1*_hc3[0]*_t18*_t28*_t29*_t3*_t5*_t87 + 0.2e1*_hc3[0]*_t25*_t28*_t29*_t3*_t41*_t5 + 0.4e1*_hc3[0]*_t25*_t28*_t29*_t3*_t5*_t71 + 0.2e1*_hc3[0]*_t28*_t29*_t3*_t41*_t5*_t71 + 0.2e1*_hc3[0]*_t28*_t29*_t3*_t5*_t64*_t68 - _t142*_t26 - _t142*_t66*_t9 - _t145*_t67 - _t147*_t26 - _t149*_t150 - _t149*_t27 - _t150*_t41 - _t150*_t71 - _t156*_t19 - 0.2e1*_t19*_t87 - _t26*(-_hc2[10]*_t7 - _hc2[3]*_t154*_t6 - _hc2[6]*_t104*_t15 - _t104*_t158*_t85 - _t116*_t84*_t86 - _t151*_t31 - 0.3e1*_t152*_t157 - _t153*_t85 - _t155*_t160 - 0.8e1*_t157*_t158 - 0.4e1*_t159*_t81 - _t16*(-0.3e1 / 0.2e1*_hc0[14] - 0.3e1 / 0.2e1*_hc1[14]) - _t57*_t86*(-0.5e1 / 0.2e1*_hc0[5] - 0.5e1 / 0.2e1*_hc1[5]) - _t69*_t73 - 0.3e1*_t70*_t73 - _t79*(-0.2e1*_hc0[9] + 0.2e1*_hc1[9])) - _t27*_t41 - _t27*_t71 - _t42*_t71 - _t67*_t68;
  out[24] = d4f_dz4;
  const double d4f_drs_dt3 = 0;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dz_dt2 = 0;
  out[26] = d4f_drs_dz_dt2;
  const double d4f_drs_dz2_dt = 0;
  out[27] = d4f_drs_dz2_dt;
  const double d4f_drs_dz3 = _hc2[11]*_t43 + _hc2[4]*_t162*_t83 - _hc2[7]*_t165*_t18 + _hc2[7]*_t77*_t90 + _t102*_t145 + _t102*_t68 - _t105*_t154*_t22*_t48 - 0.12e2*_t106*_t13*_t94 + _t13*_t161*_t85 + _t13*_t172*_t173*_t175 - _t135*_t172*_t31*_t48 - _t146*_t53 + _t148*_t90*_t94 + 0.2e1*_t157*_t161 + _t159*_t92 + _t160*_t91 + _t163*_t88 + _t163*_t89 + _t164*_t25 + _t164*_t41 - _t165*_t68*_t94 - _t166*_t167 + _t166*_t66 - _t168*_t25 - _t168*_t41 + _t170*_t25*_t96 + _t171*_t25 + _t171*_t41 - _t173*_t174 - _t174*_t176 - _t174*_t48*_t68 - _t176*_t68*_t97 - _t177*_t71*_t95 + _t178*_t41 + _t178*_t71 + _t18*_t83*_t92 + _t24*_t64 + _t24*_t87 + _t41*_t47 - _t41*_t53 + _t46*_t73 + _t47*_t71 - _t64*_t98 - _t68*_t99 - _t87*_t98;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = 0;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dz_dt = 0;
  out[30] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz2 = _hc2[12]*_t43 + _hc2[4]*_t188*_t68 + _hc2[5]*_t101*_t96 - _hc2[5]*_t107*_t18 + _hc2[5]*_t162*_t82 - _hc2[7]*_t110 + _hc2[7]*_t112 - _hc2[8]*_t18*_t97 + _hc2[8]*_t34*_t90 - _t101*_t62 + _t103*_t113 + _t105*_t181*_t183 + _t108*_t93 + _t111*_t179 + _t113*_t31 - _t117*_t182 - _t117*_t185 - _t118*_t93 - _t121*_t25 - _t121*_t41 - _t122*_t68 + _t123*_t68 - _t124*_t41 - _t125*_t145 - _t125*_t68 + _t146*_t63 + _t167*_t25*_t62 - 0.2e1*_t179*_t180 - 0.4e1*_t181*_t21 + _t182*_t184 + _t184*_t185 - _t186*_t94 + 0.8e1*_t187*_t189 - 0.24e2*_t189*_t61*_t65 + _t191*_t68*_t95 - 0.12e2*_t192*_t65 + _t192*_t95 + _t25*_t54 - _t25*_t60 + _t25*_t63 + _t41*_t54 - _t41*_t60 + _t41*_t63 + _t63*_t71;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dt = 0;
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dz = _hc2[13]*_t43 + _hc2[2]*_hc2[5]*_t135*_t190 + 0.3e1*_hc2[4]*_t195 - 0.3e1*_hc2[5]*_t119*_t21 - _hc2[8]*_t133 + _hc2[8]*_t137 + _hc2[9]*_t13*_t90 - _hc2[9]*_t18*_t52 + _t126*_t18 + _t132*_t18 - _t134*_t18 - _t135*_t200 + _t136*_t194 + _t136*_t201 + _t138*_t68 - _t140*_t68 + _t141*_t145 - _t167*_t202 - _t169*_t197 + _t170*_t198 - _t175*_t201*_t61 + _t175*_t202 - _t193*_t194 + _t199*_t20 + _t200*_t66 - _t202*_t50;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = _hc2[14]*_t43 + 0.6e1*_hc2[5]*_t195 - 0.36e2*_hc2[5]*_t197 + _hc2[5]*_t198*_t206 - _hc2[9]*_t186 + _hc2[9]*_t188 + _t136*_t203 + _t167*_t205 - _t193*_t203 - _t20*_t204 - _t205*_t206 + 0.14e2*_t205*_t49;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f1_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(A_k, _KMAX)(p, rs, z, t, _hc0);
  const double _t1 = (t * t);
  const double _t2 = (t * t * t * t);
#if _KMAX >= 1
  const double _t3 = (t * t * t);
  const double _t4 = 0.4e1*_t3;
#endif
#if _KMAX >= 2
  const double _t5 = 0.12e2*_t1;
  const double _t6 = 0.8e1*_t3;
#endif
#if _KMAX >= 3
  const double _t7 = 0.24e2*_hc0[0];
  const double _t8 = 0.36e2*_t1;
  const double _t9 = 0.12e2*_t3;
#endif
#if _KMAX >= 4
  const double _t10 = 0.24e2*t;
#endif

  const double f = _hc0[0]*_t2 + _t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[0]*_t4 + _hc0[1]*_t2 + 0.2e1*t;
  out[1] = df_dt;
  const double df_dz = _hc0[2]*_t2;
  out[2] = df_dz;
  const double df_drs = _hc0[3]*_t2;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[0]*_t5 + _hc0[1]*_t6 + _hc0[4]*_t2 + 0.2e1;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = _hc0[2]*_t4 + _hc0[5]*_t2;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = _hc0[6]*_t2;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = _hc0[3]*_t4 + _hc0[7]*_t2;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _hc0[8]*_t2;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[9]*_t2;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[1]*_t8 + _hc0[10]*_t2 + _hc0[4]*_t9 + _t7*t;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = _hc0[11]*_t2 + _hc0[2]*_t5 + _hc0[5]*_t6;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = _hc0[12]*_t2 + _hc0[6]*_t4;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = _hc0[13]*_t2;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = _hc0[14]*_t2 + _hc0[3]*_t5 + _hc0[7]*_t6;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = _hc0[15]*_t2 + _hc0[8]*_t4;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _hc0[16]*_t2;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = _hc0[17]*_t2 + _hc0[9]*_t4;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _hc0[18]*_t2;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[19]*_t2;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.96e2*_hc0[1]*t + 0.16e2*_hc0[10]*_t3 + _hc0[20]*_t2 + 0.72e2*_hc0[4]*_t1 + _t7;
  out[20] = d4f_dt4;
  const double d4f_dz_dt3 = _hc0[11]*_t9 + _hc0[2]*_t10 + _hc0[21]*_t2 + _hc0[5]*_t8;
  out[21] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = _hc0[12]*_t6 + _hc0[22]*_t2 + _hc0[6]*_t5;
  out[22] = d4f_dz2_dt2;
  const double d4f_dz3_dt = _hc0[13]*_t4 + _hc0[23]*_t2;
  out[23] = d4f_dz3_dt;
  const double d4f_dz4 = _hc0[24]*_t2;
  out[24] = d4f_dz4;
  const double d4f_drs_dt3 = _hc0[14]*_t9 + _hc0[25]*_t2 + _hc0[3]*_t10 + _hc0[7]*_t8;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dz_dt2 = _hc0[15]*_t6 + _hc0[26]*_t2 + _hc0[8]*_t5;
  out[26] = d4f_drs_dz_dt2;
  const double d4f_drs_dz2_dt = _hc0[16]*_t4 + _hc0[27]*_t2;
  out[27] = d4f_drs_dz2_dt;
  const double d4f_drs_dz3 = _hc0[28]*_t2;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = _hc0[17]*_t6 + _hc0[29]*_t2 + _hc0[9]*_t5;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dz_dt = _hc0[18]*_t4 + _hc0[30]*_t2;
  out[30] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz2 = _hc0[31]*_t2;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dt = _hc0[19]*_t4 + _hc0[32]*_t2;
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dz = _hc0[33]*_t2;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[34]*_t2;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f2_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(A_k, _KMAX)(p, rs, z, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f1_k, _KMAX)(p, rs, z, t, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, 0, 0, _hc2);
  const double _t1 = _hc0[0]*_hc1[0] + 0.1e1;
  const double _t2 = (M_PI * M_PI)*_hc2[0]/(0.1e1 - M_LN2);
  const double _t3 = _t2/_t1;
#if _KMAX >= 1
  const double _t4 = _hc0[0]*_hc1[1];
  const double _t5 = _hc0[1]*_hc1[0];
  const double _t6 = -_t4 - _t5;
  const double _t7 = _t2/(_t1 * _t1);
  const double _t8 = _hc1[0]*_t7;
  const double _t9 = _hc0[0]*_hc1[2];
  const double _t10 = _hc0[2]*_hc1[0];
  const double _t11 = -_t10 - _t9;
  const double _t12 = _hc0[0]*_hc1[3];
  const double _t13 = _hc0[3]*_hc1[0];
  const double _t14 = -_t12 - _t13;
#endif
#if _KMAX >= 2
  const double _t15 = 0.2e1*_hc1[1];
  const double _t16 = _t6*_t7;
  const double _t17 = _hc0[0]*_hc1[4];
  const double _t18 = _hc0[4]*_hc1[0];
  const double _t19 = _hc0[1]*_hc1[1];
  const double _t20 = -_t17 - _t18 - 0.2e1*_t19;
  const double _t21 = _t2/(_t1 * _t1 * _t1);
  const double _t22 = _hc1[0]*_t21;
  const double _t23 = -0.2e1*_t4 - 0.2e1*_t5;
  const double _t24 = _t23*_t6;
  const double _t25 = _hc1[1]*_t7;
  const double _t26 = _hc0[0]*_hc1[5];
  const double _t27 = _hc0[1]*_hc1[2];
  const double _t28 = _hc0[2]*_hc1[1];
  const double _t29 = _hc0[5]*_hc1[0];
  const double _t30 = -_t26 - _t27 - _t28 - _t29;
  const double _t31 = _t11*_t22;
  const double _t32 = 0.2e1*_hc1[2];
  const double _t33 = _t11*_t7;
  const double _t34 = _hc0[0]*_hc1[6];
  const double _t35 = _hc0[6]*_hc1[0];
  const double _t36 = 0.2e1*_hc0[2];
  const double _t37 = -_hc1[2]*_t36 - _t34 - _t35;
  const double _t38 = -0.2e1*_t10 - 0.2e1*_t9;
  const double _t39 = _hc0[0]*_hc1[7];
  const double _t40 = _hc0[1]*_hc1[3];
  const double _t41 = _hc0[3]*_hc1[1];
  const double _t42 = _hc0[7]*_hc1[0];
  const double _t43 = -_t39 - _t40 - _t41 - _t42;
  const double _t44 = _t14*_t22;
  const double _t45 = _hc1[2]*_t7;
  const double _t46 = _hc0[0]*_hc1[8];
  const double _t47 = _hc0[2]*_hc1[3];
  const double _t48 = _hc0[3]*_hc1[2];
  const double _t49 = _hc0[8]*_hc1[0];
  const double _t50 = -_t46 - _t47 - _t48 - _t49;
  const double _t51 = 0.2e1*_hc1[3];
  const double _t52 = _t14*_t7;
  const double _t53 = _hc0[0]*_hc1[9];
  const double _t54 = _hc0[9]*_hc1[0];
  const double _t55 = 0.2e1*_hc0[3];
  const double _t56 = -_hc1[3]*_t55 - _t53 - _t54;
  const double _t57 = -0.2e1*_t12 - 0.2e1*_t13;
#endif
#if _KMAX >= 3
  const double _t58 = 0.3e1*_t16;
  const double _t59 = 0.3e1*_hc1[1];
  const double _t60 = _t20*_t7;
  const double _t61 = _hc0[0]*_hc1[10];
  const double _t62 = _hc0[10]*_hc1[0];
  const double _t63 = _hc0[1]*_hc1[4];
  const double _t64 = _hc0[4]*_hc1[1];
  const double _t65 = -_t61 - _t62 - 0.3e1*_t63 - 0.3e1*_t64;
  const double _t66 = _t21*_t24;
  const double _t67 = -0.2e1*_t17 - 0.2e1*_t18 - 0.4e1*_t19;
  const double _t68 = _t22*_t6;
  const double _t69 = _t22*_t23;
  const double _t70 = 0.2e1*_t69;
  const double _t71 = -0.3e1*_t4 - 0.3e1*_t5;
  const double _t72 = _t2/(_t1 * _t1 * _t1 * _t1);
  const double _t73 = _hc1[0]*_t72;
  const double _t74 = _t71*_t73;
  const double _t75 = 0.2e1*_hc1[5];
  const double _t76 = _t30*_t7;
  const double _t77 = _t11*_t21;
  const double _t78 = _t23*_t77;
  const double _t79 = _hc0[0]*_hc1[11];
  const double _t80 = _hc0[11]*_hc1[0];
  const double _t81 = _hc0[2]*_hc1[4];
  const double _t82 = _hc0[4]*_hc1[2];
  const double _t83 = 0.2e1*_hc0[1];
  const double _t84 = 0.2e1*_hc0[5];
  const double _t85 = -_hc1[1]*_t84 - _hc1[5]*_t83 - _t79 - _t80 - _t81 - _t82;
  const double _t86 = _t11*_t74;
  const double _t87 = _hc1[1]*_t38;
  const double _t88 = _hc0[0]*_hc1[12];
  const double _t89 = _hc0[1]*_hc1[6];
  const double _t90 = _hc0[12]*_hc1[0];
  const double _t91 = _hc0[6]*_hc1[1];
  const double _t92 = -_hc1[2]*_t84 - _hc1[5]*_t36 - _t88 - _t89 - _t90 - _t91;
  const double _t93 = _t22*_t38;
  const double _t94 = -0.2e1*_t26 - 0.2e1*_t27 - 0.2e1*_t28 - 0.2e1*_t29;
  const double _t95 = 0.3e1*_t33;
  const double _t96 = 0.3e1*_hc1[2];
  const double _t97 = _t37*_t7;
  const double _t98 = _hc0[0]*_hc1[13];
  const double _t99 = _hc0[13]*_hc1[0];
  const double _t100 = 0.3e1*_hc0[2];
  const double _t101 = -_hc0[6]*_t96 - _hc1[6]*_t100 - _t98 - _t99;
  const double _t102 = _t38*_t77;
  const double _t103 = 0.4e1*_hc0[2];
  const double _t104 = -_hc1[2]*_t103 - 0.2e1*_t34 - 0.2e1*_t35;
  const double _t105 = 0.2e1*_t93;
  const double _t106 = -0.3e1*_t10 - 0.3e1*_t9;
  const double _t107 = _t106*_t73;
  const double _t108 = _t11*_t38;
  const double _t109 = 0.2e1*_hc1[7];
  const double _t110 = _hc1[3]*_t7;
  const double _t111 = _t43*_t7;
  const double _t112 = _t14*_t21;
  const double _t113 = _t112*_t23;
  const double _t114 = _hc0[0]*_hc1[14];
  const double _t115 = _hc0[14]*_hc1[0];
  const double _t116 = _hc0[3]*_hc1[4];
  const double _t117 = _hc0[4]*_hc1[3];
  const double _t118 = 0.2e1*_hc0[7];
  const double _t119 = -_hc1[1]*_t118 - _hc1[7]*_t83 - _t114 - _t115 - _t116 - _t117;
  const double _t120 = _t14*_t74;
  const double _t121 = _hc1[2]*_t112;
  const double _t122 = _hc1[3]*_t77;
  const double _t123 = _hc0[0]*_hc1[15];
  const double _t124 = _hc0[1]*_hc1[8];
  const double _t125 = _hc0[15]*_hc1[0];
  const double _t126 = _hc0[2]*_hc1[7];
  const double _t127 = _hc0[3]*_hc1[5];
  const double _t128 = _hc0[5]*_hc1[3];
  const double _t129 = _hc0[7]*_hc1[2];
  const double _t130 = _hc0[8]*_hc1[1];
  const double _t131 = -_t123 - _t124 - _t125 - _t126 - _t127 - _t128 - _t129 - _t130;
  const double _t132 = 0.2e1*_hc1[8];
  const double _t133 = _t50*_t7;
  const double _t134 = _t112*_t38;
  const double _t135 = _hc0[0]*_hc1[16];
  const double _t136 = _hc0[16]*_hc1[0];
  const double _t137 = _hc0[3]*_hc1[6];
  const double _t138 = _hc0[6]*_hc1[3];
  const double _t139 = 0.2e1*_hc0[8];
  const double _t140 = -_hc1[2]*_t139 - _hc1[8]*_t36 - _t135 - _t136 - _t137 - _t138;
  const double _t141 = _t107*_t14;
  const double _t142 = _hc1[1]*_t112;
  const double _t143 = _hc0[0]*_hc1[17];
  const double _t144 = _hc0[1]*_hc1[9];
  const double _t145 = _hc0[17]*_hc1[0];
  const double _t146 = _hc0[9]*_hc1[1];
  const double _t147 = -_hc1[3]*_t118 - _hc1[7]*_t55 - _t143 - _t144 - _t145 - _t146;
  const double _t148 = _t22*_t57;
  const double _t149 = -0.2e1*_t39 - 0.2e1*_t40 - 0.2e1*_t41 - 0.2e1*_t42;
  const double _t150 = _hc0[0]*_hc1[18];
  const double _t151 = _hc0[18]*_hc1[0];
  const double _t152 = _hc0[2]*_hc1[9];
  const double _t153 = _hc0[9]*_hc1[2];
  const double _t154 = -_hc1[3]*_t139 - _hc1[8]*_t55 - _t150 - _t151 - _t152 - _t153;
  const double _t155 = -0.2e1*_t46 - 0.2e1*_t47 - 0.2e1*_t48 - 0.2e1*_t49;
  const double _t156 = 0.3e1*_t52;
  const double _t157 = 0.3e1*_hc1[3];
  const double _t158 = _t56*_t7;
  const double _t159 = _hc0[0]*_hc1[19];
  const double _t160 = _hc0[19]*_hc1[0];
  const double _t161 = 0.3e1*_hc0[3];
  const double _t162 = -_hc0[9]*_t157 - _hc1[9]*_t161 - _t159 - _t160;
  const double _t163 = _t112*_t57;
  const double _t164 = 0.4e1*_hc0[3];
  const double _t165 = -_hc1[3]*_t164 - 0.2e1*_t53 - 0.2e1*_t54;
  const double _t166 = 0.2e1*_t148;
  const double _t167 = -0.3e1*_t12 - 0.3e1*_t13;
  const double _t168 = _t14*_t73;
  const double _t169 = _t168*_t57;
#endif
#if _KMAX >= 4
  const double _t170 = 0.6e1*_hc1[4];
  const double _t171 = 0.4e1*_hc1[1];
  const double _t172 = 0.4e1*_hc0[1];
  const double _t173 = _hc1[1]*_t21;
  const double _t174 = _t20*_t23;
  const double _t175 = _t6*_t67;
  const double _t176 = -0.2e1*_t61 - 0.2e1*_t62 - 0.6e1*_t63 - 0.6e1*_t64;
  const double _t177 = 0.3e1*_t69;
  const double _t178 = _t22*_t67;
  const double _t179 = 0.3e1*_t20;
  const double _t180 = _t71*_t72;
  const double _t181 = _t180*_t24;
  const double _t182 = -0.3e1*_t17 - 0.3e1*_t18 - 0.6e1*_t19;
  const double _t183 = _t182*_t73;
  const double _t184 = _t23*_t74;
  const double _t185 = 0.2e1*_t74;
  const double _t186 = _hc1[0]*_t2/xc_powi(_t1, 5);
  const double _t187 = _t186*(-0.4e1*_t4 - 0.4e1*_t5);
  const double _t188 = _t187*_t71;
  const double _t189 = 0.3e1*_hc1[5];
  const double _t190 = _hc1[4]*_t7;
  const double _t191 = 0.3e1*_t30;
  const double _t192 = 0.3e1*_t78;
  const double _t193 = _hc1[2]*_t21;
  const double _t194 = _t67*_t77;
  const double _t195 = _t174*_t21;
  const double _t196 = _t7*_t85;
  const double _t197 = _t23*_t30;
  const double _t198 = 0.6e1*_t173;
  const double _t199 = _t11*_t23;
  const double _t200 = _t180*_t199;
  const double _t201 = 0.2e1*_t86;
  const double _t202 = 0.3e1*_hc0[1];
  const double _t203 = 0.3e1*_hc0[5];
  const double _t204 = 0.2e1*_t33;
  const double _t205 = 0.2e1*_t16;
  const double _t206 = 0.4e1*_hc1[5];
  const double _t207 = _hc1[4]*_t38;
  const double _t208 = _t23*_t37;
  const double _t209 = _t15*_t21;
  const double _t210 = _t7*_t92;
  const double _t211 = _t30*_t38;
  const double _t212 = _t77*_t94;
  const double _t213 = 0.4e1*_hc1[2];
  const double _t214 = _t197*_t21;
  const double _t215 = _t108*_t180;
  const double _t216 = -_hc0[5]*_t171 - _hc1[5]*_t172 - 0.2e1*_t79 - 0.2e1*_t80 - 0.2e1*_t81 - 0.2e1*_t82;
  const double _t217 = _t22*_t94;
  const double _t218 = 0.2e1*_t217;
  const double _t219 = 0.4e1*_hc0[5];
  const double _t220 = _hc1[6]*_t7;
  const double _t221 = _t104*_t77;
  const double _t222 = _t37*_t38;
  const double _t223 = _t21*_t96;
  const double _t224 = _t106*_t72;
  const double _t225 = _t224*_t87;
  const double _t226 = _t104*_t22;
  const double _t227 = -_hc1[2]*_t219 - _hc1[5]*_t103 - 0.2e1*_t88 - 0.2e1*_t89 - 0.2e1*_t90 - 0.2e1*_t91;
  const double _t228 = _t107*_t11;
  const double _t229 = -0.3e1*_t26 - 0.3e1*_t27 - 0.3e1*_t28 - 0.3e1*_t29;
  const double _t230 = _t108*_t73;
  const double _t231 = _t106*_t108;
  const double _t232 = 0.6e1*_hc1[6];
  const double _t233 = 0.6e1*_hc1[2];
  const double _t234 = -_hc0[2]*_t232 - _hc0[6]*_t233 - 0.2e1*_t98 - 0.2e1*_t99;
  const double _t235 = 0.3e1*_t93;
  const double _t236 = _t108*_t224;
  const double _t237 = -_hc0[2]*_t233 - 0.3e1*_t34 - 0.3e1*_t35;
  const double _t238 = 0.2e1*_t104;
  const double _t239 = _t186*(-0.4e1*_t10 - 0.4e1*_t9);
  const double _t240 = 0.3e1*_hc1[7];
  const double _t241 = 0.3e1*_t43;
  const double _t242 = _hc1[3]*_t21;
  const double _t243 = _t112*_t67;
  const double _t244 = _t119*_t7;
  const double _t245 = _t23*_t43;
  const double _t246 = _t14*_t23;
  const double _t247 = _t180*_t246;
  const double _t248 = _t168*_t182;
  const double _t249 = 0.2e1*_t120;
  const double _t250 = 0.3e1*_hc0[7];
  const double _t251 = _t23*_t50;
  const double _t252 = _t209*_t38;
  const double _t253 = _t112*_t94;
  const double _t254 = _t21*_t32;
  const double _t255 = _hc1[2]*_t14;
  const double _t256 = _t180*_t255;
  const double _t257 = _hc1[3]*_t180;
  const double _t258 = _t14*_t38;
  const double _t259 = _t180*_t258;
  const double _t260 = _t131*_t7;
  const double _t261 = _t38*_t43;
  const double _t262 = _hc1[6]*_t112;
  const double _t263 = _t168*_t38;
  const double _t264 = _t38*_t50;
  const double _t265 = _t106*_t258;
  const double _t266 = 0.3e1*_hc1[8];
  const double _t267 = 0.3e1*_t50;
  const double _t268 = _t104*_t112;
  const double _t269 = _t21*_t51;
  const double _t270 = _t140*_t7;
  const double _t271 = _t21*_t264;
  const double _t272 = _t14*_t224;
  const double _t273 = _t272*_t38;
  const double _t274 = 0.3e1*_hc0[8];
  const double _t275 = 0.2e1*_t52;
  const double _t276 = 0.4e1*_hc1[7];
  const double _t277 = _t21*_t56;
  const double _t278 = _t15*_t277;
  const double _t279 = _t147*_t7;
  const double _t280 = _t43*_t57;
  const double _t281 = _t112*_t149;
  const double _t282 = 0.4e1*_hc1[3];
  const double _t283 = _t14*_t57;
  const double _t284 = _t180*_t283;
  const double _t285 = _t23*_t56;
  const double _t286 = _t22*_t43;
  const double _t287 = 0.2e1*_t149;
  const double _t288 = 0.4e1*_hc0[7];
  const double _t289 = _t50*_t57;
  const double _t290 = _hc1[1]*_t57;
  const double _t291 = _t38*_t56;
  const double _t292 = _t22*_t50;
  const double _t293 = _t106*_t283;
  const double _t294 = 0.4e1*_hc1[8];
  const double _t295 = _t277*_t32;
  const double _t296 = _t154*_t7;
  const double _t297 = _t112*_t155;
  const double _t298 = _t272*_t57;
  const double _t299 = 0.2e1*_t155;
  const double _t300 = 0.2e1*_t107;
  const double _t301 = 0.4e1*_hc0[8];
  const double _t302 = 0.3e1*_hc1[9];
  const double _t303 = _t157*_t277;
  const double _t304 = _t157*_t21;
  const double _t305 = _t167*_t72;
  const double _t306 = _t14*_t305;
  const double _t307 = _t22*_t56;
  const double _t308 = _t56*_t57;
  const double _t309 = _t167*_t73;
  const double _t310 = _t167*_t168;
  const double _t311 = _t167*_t283;
  const double _t312 = 0.6e1*_hc1[9];
  const double _t313 = 0.6e1*_hc1[3];
#endif

  const double f = _hc1[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t3 + _t6*_t8;
  out[1] = df_dt;
  const double df_dz = _hc1[2]*_t3 + _t11*_t8;
  out[2] = df_dz;
  const double df_drs = _hc1[3]*_t3 + _t14*_t8;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[4]*_t3 + _t15*_t16 + _t20*_t8 + _t22*_t24;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = _hc1[2]*_t16 + _hc1[5]*_t3 + _t11*_t25 + _t23*_t31 + _t30*_t8;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = _hc1[6]*_t3 + _t31*_t38 + _t32*_t33 + _t37*_t8;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = _hc1[3]*_t16 + _hc1[7]*_t3 + _t14*_t25 + _t23*_t44 + _t43*_t8;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _hc1[3]*_t33 + _hc1[8]*_t3 + _t14*_t45 + _t38*_t44 + _t50*_t8;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[9]*_t3 + _t44*_t57 + _t51*_t52 + _t56*_t8;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc1[10]*_t3 + _hc1[4]*_t58 + _t20*_t70 + _t24*_t74 + _t59*_t60 + _t59*_t66 + _t65*_t8 + _t67*_t68;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = _hc1[11]*_t3 + _hc1[2]*_t66 + _hc1[4]*_t33 + _t15*_t76 + _t15*_t78 + _t16*_t75 + _t20*_t45 + _t23*_t86 + _t30*_t70 + _t31*_t67 + _t8*_t85;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = _hc1[12]*_t3 + _hc1[6]*_t16 + _t25*_t37 + _t30*_t93 + _t31*_t94 + _t32*_t76 + _t32*_t78 + _t33*_t75 + _t37*_t69 + _t38*_t86 + _t77*_t87 + _t8*_t92;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = _hc1[13]*_t3 + _hc1[6]*_t95 + _t101*_t8 + _t102*_t96 + _t104*_t31 + _t105*_t37 + _t107*_t108 + _t96*_t97;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = _hc1[14]*_t3 + _hc1[3]*_t66 + _hc1[4]*_t52 + _t109*_t16 + _t110*_t20 + _t111*_t15 + _t113*_t15 + _t119*_t8 + _t120*_t23 + _t43*_t70 + _t44*_t67;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = _hc1[15]*_t3 + _hc1[5]*_t52 + _hc1[7]*_t33 + _hc1[8]*_t16 + _t110*_t30 + _t112*_t87 + _t120*_t38 + _t121*_t23 + _t122*_t23 + _t131*_t8 + _t25*_t50 + _t43*_t45 + _t43*_t93 + _t44*_t94 + _t50*_t69;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _hc1[16]*_t3 + _hc1[6]*_t52 + _t104*_t44 + _t105*_t50 + _t110*_t37 + _t122*_t38 + _t132*_t33 + _t133*_t32 + _t134*_t32 + _t140*_t8 + _t141*_t38;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = _hc1[17]*_t3 + _hc1[9]*_t16 + _t109*_t52 + _t111*_t51 + _t113*_t51 + _t120*_t57 + _t142*_t57 + _t147*_t8 + _t148*_t43 + _t149*_t44 + _t25*_t56 + _t56*_t69;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _hc1[18]*_t3 + _hc1[9]*_t33 + _t121*_t57 + _t132*_t52 + _t133*_t51 + _t134*_t51 + _t141*_t57 + _t148*_t50 + _t154*_t8 + _t155*_t44 + _t45*_t56 + _t56*_t93;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[19]*_t3 + _hc1[9]*_t156 + _t157*_t158 + _t157*_t163 + _t162*_t8 + _t165*_t44 + _t166*_t56 + _t167*_t169;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.4e1*_hc1[10]*_t16 + _hc1[20]*_t3 + _t170*_t60 + _t170*_t66 + _t171*_t175*_t21 + _t171*_t181 + _t171*_t65*_t7 + 0.8e1*_t173*_t174 + _t175*_t185 + _t176*_t68 + _t177*_t65 + _t178*_t179 + _t179*_t184 + _t183*_t24 + _t188*_t24 + _t8*(-_hc0[0]*_hc1[20] - _hc0[10]*_t171 - _hc0[20]*_hc1[0] - _hc0[4]*_t170 - _hc1[10]*_t172);
  out[20] = d4f_dt4;
  const double d4f_dz_dt3 = _hc1[10]*_t33 + _hc1[11]*_t58 + _hc1[2]*_t181 + _hc1[21]*_t3 + _hc1[4]*_t192 + _t175*_t193 + _t176*_t31 + _t177*_t85 + _t178*_t191 + _t183*_t199 + _t184*_t191 + _t188*_t199 + _t189*_t60 + _t189*_t66 + _t190*_t191 + _t194*_t59 + _t195*_t32 + _t196*_t59 + _t197*_t198 + _t200*_t59 + _t201*_t67 + _t45*_t65 + _t8*(-_hc0[0]*_hc1[21] - _hc0[10]*_hc1[2] - _hc0[11]*_t59 - _hc0[2]*_hc1[10] - _hc0[21]*_hc1[0] - _hc0[4]*_t189 - _hc1[11]*_t202 - _hc1[4]*_t203);
  out[21] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = _hc1[11]*_t204 + _hc1[12]*_t205 + _hc1[22]*_t3 + _hc1[6]*_t60 + _hc1[6]*_t66 + _t108*_t183 + _t108*_t188 + _t15*_t210 + _t15*_t212 + _t15*_t215 + _t178*_t37 + _t185*_t211 + _t190*_t37 + _t194*_t32 + _t196*_t32 + _t200*_t32 + _t201*_t94 + _t206*_t76 + _t206*_t78 + _t207*_t77 + _t208*_t209 + _t208*_t74 + _t209*_t211 + _t213*_t214 + _t216*_t31 + _t218*_t30 + _t70*_t92 + _t8*(-_hc0[0]*_hc1[22] - _hc0[11]*_t32 - _hc0[12]*_t15 - _hc0[22]*_hc1[0] - _hc0[4]*_hc1[6] - _hc0[6]*_hc1[4] - _hc1[11]*_t36 - _hc1[12]*_t83 - _hc1[5]*_t219) + _t85*_t93;
  out[22] = d4f_dz2_dt2;
  const double d4f_dz3_dt = _hc1[1]*_t221 + _hc1[12]*_t95 + _hc1[13]*_t16 + _hc1[23]*_t3 + _hc1[6]*_t192 + _t101*_t25 + _t101*_t69 + _t102*_t189 + _t104*_t86 + _t105*_t92 + _t107*_t211 + _t11*_t225 + _t185*_t222 + _t187*_t231 + _t189*_t97 + _t191*_t220 + _t208*_t223 + _t209*_t222 + _t210*_t96 + _t211*_t223 + _t212*_t96 + _t215*_t96 + _t218*_t37 + _t226*_t30 + _t227*_t31 + _t228*_t94 + _t229*_t230 + _t8*(-_hc0[0]*_hc1[23] - _hc0[1]*_hc1[13] - _hc0[12]*_t96 - _hc0[13]*_hc1[1] - _hc0[23]*_hc1[0] - _hc0[6]*_t189 - _hc1[12]*_t100 - _hc1[6]*_t203);
  out[23] = d4f_dz3_dt;
  const double d4f_dz4 = 0.4e1*_hc1[13]*_t33 + _hc1[24]*_t3 + _t101*_t213*_t7 + _t101*_t235 + _t102*_t232 + 0.3e1*_t107*_t222 + 0.8e1*_t193*_t222 + _t213*_t221 + _t213*_t236 + 0.3e1*_t226*_t37 + _t228*_t238 + _t230*_t237 + _t231*_t239 + _t232*_t97 + _t234*_t31 + _t8*(-_hc0[0]*_hc1[24] - _hc0[13]*_t213 - _hc0[24]*_hc1[0] - _hc0[6]*_t232 - _hc1[13]*_t103);
  out[24] = d4f_dz4;
  const double d4f_drs_dt3 = _hc1[10]*_t52 + _hc1[14]*_t58 + _hc1[25]*_t3 + _hc1[3]*_t181 + 0.3e1*_hc1[4]*_t113 + _t110*_t65 + _t119*_t177 + _t175*_t242 + _t176*_t44 + _t178*_t241 + _t184*_t241 + _t188*_t246 + _t190*_t241 + _t195*_t51 + _t198*_t245 + _t23*_t248 + _t240*_t60 + _t240*_t66 + _t243*_t59 + _t244*_t59 + _t247*_t59 + _t249*_t67 + _t8*(-_hc0[0]*_hc1[25] - _hc0[10]*_hc1[3] - _hc0[14]*_t59 - _hc0[25]*_hc1[0] - _hc0[3]*_hc1[10] - _hc0[4]*_t240 - _hc1[14]*_t202 - _hc1[4]*_t250);
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dz_dt2 = _hc1[11]*_t52 + _hc1[14]*_t33 + _hc1[15]*_t205 + _hc1[26]*_t3 + _hc1[8]*_t60 + _hc1[8]*_t66 + _t109*_t76 + _t109*_t78 + _t110*_t85 + _t111*_t75 + _t112*_t207 + _t113*_t75 + _t119*_t45 + _t119*_t93 + _t121*_t67 + _t122*_t67 + _t131*_t70 + _t15*_t253 + _t15*_t259 + _t15*_t260 + _t178*_t50 + _t185*_t261 + _t188*_t258 + _t190*_t50 + _t199*_t257 + _t209*_t251 + _t214*_t51 + _t216*_t44 + _t218*_t43 + _t23*_t256 + _t245*_t254 + _t248*_t38 + _t249*_t94 + _t251*_t74 + _t252*_t43 + _t8*(-_hc0[0]*_hc1[26] - _hc0[11]*_hc1[3] - _hc0[14]*_hc1[2] - _hc0[15]*_t15 - _hc0[2]*_hc1[14] - _hc0[26]*_hc1[0] - _hc0[3]*_hc1[11] - _hc0[4]*_hc1[8] - _hc0[8]*_hc1[4] - _hc1[15]*_t83 - _hc1[5]*_t118 - _hc1[7]*_t84);
  out[26] = d4f_drs_dz_dt2;
  const double d4f_drs_dz2_dt = _hc1[12]*_t52 + _hc1[15]*_t204 + _hc1[16]*_t16 + _hc1[27]*_t3 + _hc1[7]*_t102 + _hc1[7]*_t97 + _t104*_t120 + _t104*_t142 + _t105*_t131 + _t107*_t261 + _t108*_t257 + _t110*_t92 + _t122*_t94 + _t132*_t76 + _t132*_t78 + _t133*_t75 + _t134*_t75 + _t14*_t225 + _t140*_t25 + _t140*_t69 + _t141*_t94 + _t185*_t264 + _t187*_t265 + _t208*_t242 + _t211*_t242 + _t218*_t50 + _t220*_t43 + _t226*_t43 + _t227*_t44 + _t229*_t263 + _t23*_t262 + _t251*_t254 + _t252*_t50 + _t253*_t32 + _t254*_t261 + _t259*_t32 + _t260*_t32 + _t8*(-_hc0[0]*_hc1[27] - _hc0[1]*_hc1[16] - _hc0[12]*_hc1[3] - _hc0[15]*_t32 - _hc0[16]*_hc1[1] - _hc0[27]*_hc1[0] - _hc0[3]*_hc1[12] - _hc0[6]*_hc1[7] - _hc0[7]*_hc1[6] - _hc1[15]*_t36 - _hc1[5]*_t139 - _hc1[8]*_t84);
  out[27] = d4f_drs_dz2_dt;
  const double d4f_drs_dz3 = _hc1[13]*_t52 + _hc1[16]*_t95 + _hc1[28]*_t3 + _hc1[3]*_t236 + _t101*_t110 + _t102*_t266 + _t104*_t122 + _t107*_t267*_t38 + _t140*_t235 + _t141*_t238 + _t220*_t267 + _t222*_t269 + _t226*_t267 + _t233*_t271 + _t234*_t44 + _t237*_t263 + _t239*_t265 + 0.3e1*_t262*_t38 + _t266*_t97 + _t268*_t96 + _t270*_t96 + _t273*_t96 + _t8*(-_hc0[0]*_hc1[28] - _hc0[13]*_hc1[3] - _hc0[16]*_t96 - _hc0[28]*_hc1[0] - _hc0[3]*_hc1[13] - _hc0[6]*_t266 - _hc1[16]*_t100 - _hc1[6]*_t274);
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = _hc1[14]*_t275 + _hc1[17]*_t205 + _hc1[29]*_t3 + _hc1[4]*_t163 + _hc1[9]*_t60 + _hc1[9]*_t66 + _t111*_t276 + _t113*_t276 + _t119*_t148 + _t120*_t287 + _t147*_t70 + _t15*_t279 + _t15*_t281 + _t15*_t284 + _t169*_t182 + _t178*_t56 + _t185*_t280 + _t188*_t283 + _t190*_t56 + _t209*_t280 + _t21*_t245*_t282 + _t23*_t278 + _t243*_t51 + _t244*_t51 + _t247*_t51 + _t285*_t74 + _t286*_t287 + _t44*(-_hc0[7]*_t171 - _hc1[7]*_t172 - 0.2e1*_t114 - 0.2e1*_t115 - 0.2e1*_t116 - 0.2e1*_t117) + _t8*(-_hc0[0]*_hc1[29] - _hc0[14]*_t51 - _hc0[17]*_t15 - _hc0[29]*_hc1[0] - _hc0[4]*_hc1[9] - _hc0[9]*_hc1[4] - _hc1[14]*_t55 - _hc1[17]*_t83 - _hc1[7]*_t288);
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dz_dt = _hc1[15]*_t275 + _hc1[17]*_t33 + _hc1[18]*_t16 + _hc1[30]*_t3 + _hc1[5]*_t158 + _hc1[5]*_t163 + _hc1[9]*_t76 + _hc1[9]*_t78 + _t107*_t280 + _t109*_t133 + _t109*_t134 + _t111*_t132 + _t113*_t132 + _t120*_t155 + _t121*_t149 + _t131*_t148 + _t141*_t149 + _t142*_t155 + _t147*_t45 + _t147*_t93 + _t149*_t292 + _t154*_t25 + _t154*_t69 + _t155*_t286 + _t169*_t229 + _t173*_t289 + _t187*_t293 + _t193*_t280 + _t193*_t285 + _t217*_t56 + _t251*_t269 + _t253*_t51 + _t256*_t57 + _t259*_t51 + _t260*_t51 + _t261*_t269 + _t272*_t290 + _t277*_t87 + _t289*_t74 + _t291*_t74 + _t44*(-0.2e1*_t123 - 0.2e1*_t124 - 0.2e1*_t125 - 0.2e1*_t126 - 0.2e1*_t127 - 0.2e1*_t128 - 0.2e1*_t129 - 0.2e1*_t130) + _t8*(-_hc0[0]*_hc1[30] - _hc0[1]*_hc1[18] - _hc0[15]*_t51 - _hc0[17]*_hc1[2] - _hc0[18]*_hc1[1] - _hc0[2]*_hc1[17] - _hc0[30]*_hc1[0] - _hc0[5]*_hc1[9] - _hc0[9]*_hc1[5] - _hc1[15]*_t55 - _hc1[7]*_t139 - _hc1[8]*_t118);
  out[30] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz2 = _hc1[16]*_t275 + _hc1[18]*_t204 + _hc1[31]*_t3 + _hc1[9]*_t102 + _hc1[9]*_t97 + _t105*_t154 + _t107*_t291 + _t133*_t294 + _t134*_t294 + _t140*_t148 + _t141*_t299 + _t169*_t237 + _t220*_t56 + _t226*_t56 + _t239*_t293 + _t254*_t289 + _t262*_t57 + _t268*_t51 + _t270*_t51 + _t271*_t282 + _t273*_t51 + _t289*_t300 + _t292*_t299 + _t295*_t38 + _t296*_t32 + _t297*_t32 + _t298*_t32 + _t44*(-_hc0[8]*_t213 - _hc1[8]*_t103 - 0.2e1*_t135 - 0.2e1*_t136 - 0.2e1*_t137 - 0.2e1*_t138) + _t8*(-_hc0[0]*_hc1[31] - _hc0[16]*_t51 - _hc0[18]*_t32 - _hc0[31]*_hc1[0] - _hc0[6]*_hc1[9] - _hc0[9]*_hc1[6] - _hc1[16]*_t55 - _hc1[18]*_t36 - _hc1[8]*_t301);
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dt = _hc1[17]*_t156 + _hc1[19]*_t16 + _hc1[32]*_t3 + _t111*_t302 + _t113*_t302 + _t120*_t165 + _t142*_t165 + _t147*_t166 + _t149*_t310 + _t157*_t279 + _t157*_t281 + _t157*_t284 + _t158*_t240 + _t162*_t25 + _t162*_t69 + _t163*_t240 + _t165*_t286 + _t169*(-0.3e1*_t39 - 0.3e1*_t40 - 0.3e1*_t41 - 0.3e1*_t42) + _t185*_t308 + _t187*_t311 + _t23*_t303 + _t278*_t57 + _t280*_t304 + _t280*_t309 + _t287*_t307 + _t290*_t306 + _t44*(-_hc1[3]*_t288 - _hc1[7]*_t164 - 0.2e1*_t143 - 0.2e1*_t144 - 0.2e1*_t145 - 0.2e1*_t146) + _t8*(-_hc0[0]*_hc1[32] - _hc0[1]*_hc1[19] - _hc0[17]*_t157 - _hc0[19]*_hc1[1] - _hc0[32]*_hc1[0] - _hc0[9]*_t240 - _hc1[17]*_t161 - _hc1[9]*_t250);
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dz = _hc1[18]*_t156 + _hc1[19]*_t33 + _hc1[33]*_t3 + _t121*_t165 + _t133*_t302 + _t134*_t302 + _t141*_t165 + _t154*_t166 + _t155*_t310 + _t157*_t296 + _t157*_t297 + _t157*_t298 + _t158*_t266 + _t162*_t45 + _t162*_t93 + _t163*_t266 + _t165*_t292 + _t169*(-0.3e1*_t46 - 0.3e1*_t47 - 0.3e1*_t48 - 0.3e1*_t49) + _t239*_t311 + _t255*_t305*_t57 + _t289*_t304 + _t289*_t309 + _t295*_t57 + _t299*_t307 + _t300*_t308 + _t303*_t38 + _t44*(-_hc1[3]*_t301 - _hc1[8]*_t164 - 0.2e1*_t150 - 0.2e1*_t151 - 0.2e1*_t152 - 0.2e1*_t153) + _t8*(-_hc0[0]*_hc1[33] - _hc0[18]*_t157 - _hc0[19]*_hc1[2] - _hc0[2]*_hc1[19] - _hc0[33]*_hc1[0] - _hc0[9]*_t266 - _hc1[18]*_t161 - _hc1[9]*_t274);
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = 0.4e1*_hc1[19]*_t52 + _hc1[34]*_t3 + _t112*_t165*_t282 + 0.3e1*_t148*_t162 + _t158*_t312 + _t162*_t282*_t7 + _t163*_t312 + 0.3e1*_t165*_t307 + 0.2e1*_t165*_t310 + _t169*(-_hc0[3]*_t313 - 0.3e1*_t53 - 0.3e1*_t54) + _t186*_t311*(-0.4e1*_t12 - 0.4e1*_t13) + 0.8e1*_t242*_t308 + _t282*_t306*_t57 + 0.3e1*_t308*_t309 + _t44*(-_hc0[3]*_t312 - _hc0[9]*_t313 - 0.2e1*_t159 - 0.2e1*_t160) + _t8*(-_hc0[0]*_hc1[34] - _hc0[19]*_t282 - _hc0[34]*_hc1[0] - _hc0[9]*_t312 - _hc1[19]*_t164);
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fH_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f2_k, _KMAX)(p, rs, z, t, _hc2);
  const double _t1 = xc_log1p(_hc2[0]);
  const double _t2 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t3 = (_t2 * _t2 * _t2);
  const double _t4 = (0.1e1 / (M_PI * M_PI));
  const double _t5 = 0.1e1 - M_LN2;
  const double _t6 = _t4*_t5;
  const double _t7 = _t3*_t6;
#if _KMAX >= 1
  const double _t8 = _hc2[0] + 0.1e1;
  const double _t9 = (0.1e1 / _t8);
  const double _t10 = _t7*_t9;
  const double _t11 = (0.3e1 / 0.2e1)*_hc0[2] - 0.3e1 / 0.2e1*_hc1[2];
  const double _t12 = (_t2 * _t2);
  const double _t13 = _t12*_t6;
  const double _t14 = _t1*_t13;
#endif
#if _KMAX >= 2
  const double _t15 = ((_hc2[1]) * (_hc2[1]));
  const double _t16 = (0.1e1 / (_t8 * _t8));
  const double _t17 = _t16*_t7;
  const double _t18 = _hc2[1]*_t17;
  const double _t19 = _t11*_t13;
  const double _t20 = _hc2[1]*_t9;
  const double _t21 = ((_hc2[2]) * (_hc2[2]));
  const double _t22 = (0.3e1 / 0.2e1)*_hc0[5] + (0.3e1 / 0.2e1)*_hc1[5];
  const double _t23 = _hc0[2] - _hc1[2];
  const double _t24 = _t11*_t23*_t6;
  const double _t25 = _t1*_t2;
  const double _t26 = _t19*_t9;
  const double _t27 = 0.2e1*_t26;
  const double _t28 = _hc2[2]*_t17;
  const double _t29 = ((_hc2[3]) * (_hc2[3]));
#endif
#if _KMAX >= 3
  const double _t30 = 0.3e1*_t18;
  const double _t31 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t32 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t33 = _t32*_t7;
  const double _t34 = 0.2e1*_t33;
  const double _t35 = 0.2e1*_hc2[5];
  const double _t36 = _t15*_t34;
  const double _t37 = _t16*_t19;
  const double _t38 = _t21*_t34;
  const double _t39 = _t13*_t22;
  const double _t40 = _hc2[1]*_t37;
  const double _t41 = 0.2e1*_hc2[2];
  const double _t42 = _t2*_t24;
  const double _t43 = 0.3e1*_hc2[6];
  const double _t44 = ((_hc2[2]) * (_hc2[2]) * (_hc2[2]));
  const double _t45 = (0.3e1 / 0.2e1)*_hc0[9] - 0.3e1 / 0.2e1*_hc1[9];
  const double _t46 = _hc0[5] + _hc1[5];
  const double _t47 = _t25*_t6;
  const double _t48 = _t11*_t47;
  const double _t49 = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  const double _t50 = _t1*_t24;
  const double _t51 = _t22*_t23;
  const double _t52 = 0.2e1*_t51;
  const double _t53 = _t39*_t9;
  const double _t54 = 0.3e1*_t53;
  const double _t55 = 0.3e1*_t37;
  const double _t56 = _t42*_t9;
  const double _t57 = 0.3e1*_hc2[2];
  const double _t58 = 0.2e1*_hc2[7];
  const double _t59 = _hc2[3]*_t17;
  const double _t60 = _hc2[3]*_t37;
  const double _t61 = 0.2e1*_hc2[8];
  const double _t62 = _hc2[3]*_t9;
  const double _t63 = _t29*_t34;
  const double _t64 = 0.3e1*_t59;
  const double _t65 = ((_hc2[3]) * (_hc2[3]) * (_hc2[3]));
#endif
#if _KMAX >= 4
  const double _t66 = 0.6e1*_t7/(_t8 * _t8 * _t8 * _t8);
  const double _t67 = 0.3e1*_t17;
  const double _t68 = _hc2[5]*_t67;
  const double _t69 = _t31*_t66;
  const double _t70 = _hc2[4]*_t17;
  const double _t71 = 0.2e1*_t18;
  const double _t72 = 0.2e1*_t28;
  const double _t73 = 0.2e1*_t17;
  const double _t74 = _t15*_t66;
  const double _t75 = _t16*_t39;
  const double _t76 = _t37*_t41;
  const double _t77 = _t16*_t42;
  const double _t78 = 0.3e1*_hc2[12];
  const double _t79 = 0.6e1*_hc2[6];
  const double _t80 = _hc2[2]*_t33;
  const double _t81 = _t44*_t66;
  const double _t82 = 0.6e1*_hc2[5];
  const double _t83 = _t21*_t33;
  const double _t84 = _t13*_t45;
  const double _t85 = _t11*_t46;
  const double _t86 = _t2*_t6;
  const double _t87 = _t20*_t86;
  const double _t88 = _t57*_t75;
  const double _t89 = _t24*_t49;
  const double _t90 = _hc2[2]*_t37;
  const double _t91 = _t19*_t32;
  const double _t92 = 0.6e1*_t21;
  const double _t93 = _t91*_t92;
  const double _t94 = 0.3e1*_t56;
  const double _t95 = _t57*_t77;
  const double _t96 = 0.4e1*_hc2[13];
  const double _t97 = 0.12e2*_hc2[6];
  const double _t98 = _t1*_t49*_t6;
  const double _t99 = 0.3e1*_t47;
  const double _t100 = 0.4e1*_hc2[2]*_t9;
  const double _t101 = _t85*_t86;
  const double _t102 = _hc2[7]*_t67;
  const double _t103 = _hc2[5]*_t73;
  const double _t104 = _hc2[6]*_t17;
  const double _t105 = _hc2[1]*_hc2[3];
  const double _t106 = _t21*_t66;
  const double _t107 = 0.3e1*_hc2[16];
  const double _t108 = _hc2[8]*_t67;
  const double _t109 = 0.6e1*_hc2[8];
  const double _t110 = 0.2e1*_t59;
  const double _t111 = _t65*_t66;
#endif

  const double f = _t1*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc2[1]*_t10;
  out[1] = df_dt;
  const double df_dz = _hc2[2]*_t10 + _t11*_t14;
  out[2] = df_dz;
  const double df_drs = _hc2[3]*_t10;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc2[4]*_t3*_t4*_t5*_t9 - _t15*_t17;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = -_hc2[2]*_t18 + _hc2[5]*_t10 + _t19*_t20;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = _hc2[2]*_t27 + _hc2[6]*_t10 + _t14*_t22 - _t17*_t21 + _t24*_t25;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = -_hc2[3]*_t18 + _hc2[7]*_t3*_t4*_t5*_t9;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _hc2[3]*_t26 - _hc2[3]*_t28 + _hc2[8]*_t10;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc2[9]*_t3*_t4*_t5*_t9 - _t17*_t29;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc2[10]*_t10 - _hc2[4]*_t30 + _t31*_t34;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = _hc2[11]*_t10 + _hc2[2]*_t36 + _hc2[4]*_t26 - _hc2[4]*_t28 - _t15*_t37 - _t18*_t35;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = _hc2[1]*_t38 + _hc2[12]*_t10 + _hc2[5]*_t27 - _hc2[6]*_t18 + _t20*_t39 + _t20*_t42 - _t28*_t35 - _t40*_t41;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = _hc2[13]*_t10 + _hc2[2]*_t54 + _t14*_t45 - _t21*_t55 + _t26*_t43 - _t28*_t43 + _t34*_t44 + _t46*_t48 + _t47*_t52 + _t49*_t50 + _t56*_t57;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = _hc2[14]*_t10 + _hc2[3]*_t36 - _hc2[4]*_t59 - _t18*_t58;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = 0.2e1*_hc2[1]*_hc2[2]*_hc2[3]*_t3*_t32*_t4*_t5 - _hc2[1]*_t60 + _hc2[15]*_t3*_t4*_t5*_t9 - _hc2[5]*_t59 + _hc2[7]*_t11*_t12*_t4*_t5*_t9 - _hc2[7]*_t28 - _hc2[8]*_t18;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _hc2[16]*_t10 + _hc2[3]*_t38 + _hc2[3]*_t53 - _hc2[6]*_t59 + _hc2[8]*_t27 - _t28*_t61 - _t41*_t60 + _t42*_t62;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = _hc2[1]*_t63 + _hc2[17]*_t10 - _hc2[9]*_t18 - _t58*_t59;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _hc2[18]*_t10 + _hc2[2]*_t63 + _hc2[9]*_t26 - _hc2[9]*_t28 - _t29*_t37 - _t59*_t61;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc2[19]*_t10 - _hc2[9]*_t64 + _t34*_t65;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = -((_hc2[1]) * (_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t66 - 0.4e1*_hc2[10]*_t18 + _hc2[20]*_t3*_t4*_t5*_t9 - ((_hc2[4]) * (_hc2[4]))*_t67 + 0.12e2*_hc2[4]*_t15*_t3*_t32*_t4*_t5;
  out[20] = d4f_dt4;
  const double d4f_dz_dt3 = 0.6e1*_hc2[1]*_hc2[2]*_hc2[4]*_t3*_t32*_t4*_t5 - _hc2[1]*_hc2[4]*_t55 + _hc2[10]*_t11*_t12*_t4*_t5*_t9 - _hc2[10]*_t28 - _hc2[11]*_t30 - _hc2[2]*_t69 + _hc2[21]*_t3*_t4*_t5*_t9 - _hc2[4]*_t68 + 0.6e1*_hc2[5]*_t15*_t3*_t32*_t4*_t5 + 0.2e1*_t11*_t12*_t31*_t32*_t4*_t5;
  out[21] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = 0.8e1*_hc2[1]*_hc2[2]*_hc2[5]*_t3*_t32*_t4*_t5 + 0.2e1*_hc2[11]*_t11*_t12*_t4*_t5*_t9 - _hc2[11]*_t72 - _hc2[12]*_t71 + 0.4e1*_hc2[2]*_t11*_t12*_t15*_t32*_t4*_t5 + _hc2[22]*_t3*_t4*_t5*_t9 + _hc2[4]*_t11*_t2*_t23*_t4*_t5*_t9 + _hc2[4]*_t12*_t22*_t4*_t5*_t9 + 0.2e1*_hc2[4]*_t21*_t3*_t32*_t4*_t5 - _hc2[4]*_t76 - ((_hc2[5]) * (_hc2[5]))*_t73 - 0.4e1*_hc2[5]*_t40 + 0.2e1*_hc2[6]*_t15*_t3*_t32*_t4*_t5 - _hc2[6]*_t70 - _t15*_t75 - _t15*_t77 - _t21*_t74;
  out[22] = d4f_dz2_dt2;
  const double d4f_dz3_dt = _hc2[1]*_t79*_t80 - _hc2[1]*_t81 - _hc2[1]*_t88 + _hc2[1]*_t93 - _hc2[1]*_t95 - _hc2[13]*_t18 + _hc2[23]*_t10 + _hc2[5]*_t54 + _hc2[5]*_t94 - _hc2[6]*_t68 + _t20*_t84 + _t20*_t89 + _t26*_t78 - _t28*_t78 - _t40*_t43 + _t52*_t87 + _t82*_t83 - _t82*_t90 + _t85*_t87;
  out[23] = d4f_dz3_dt;
  const double d4f_dz4 = -((_hc2[2]) * (_hc2[2]) * (_hc2[2]) * (_hc2[2]))*_t66 + 0.8e1*_hc2[2]*_t51*_t86*_t9 + _hc2[24]*_t10 - ((_hc2[6]) * (_hc2[6]))*_t67 + _t100*_t101 + _t100*_t84 + _t100*_t89 + _t14*((0.3e1 / 0.2e1)*_hc0[14] + (0.3e1 / 0.2e1)*_hc1[14]) + _t22*_t46*_t99 + _t23*_t45*_t99 + _t26*_t96 - _t28*_t96 + 0.8e1*_t44*_t91 + _t48*(_hc0[9] - _hc1[9]) + _t50*((0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5]) + 0.3e1*_t51*_t98 + _t53*_t79 + _t56*_t79 - _t75*_t92 - _t77*_t92 + _t83*_t97 + 0.2e1*_t85*_t98 - _t90*_t97;
  out[24] = d4f_dz4;
  const double d4f_drs_dt3 = 0.6e1*_hc2[1]*_hc2[3]*_hc2[4]*_t3*_t32*_t4*_t5 - _hc2[10]*_t59 - _hc2[14]*_t30 + _hc2[25]*_t3*_t4*_t5*_t9 - _hc2[3]*_t69 - _hc2[4]*_t102 + 0.6e1*_hc2[7]*_t15*_t3*_t32*_t4*_t5;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dz_dt2 = 0.4e1*_hc2[1]*_hc2[2]*_hc2[7]*_t3*_t32*_t4*_t5 + 0.4e1*_hc2[1]*_hc2[3]*_hc2[5]*_t3*_t32*_t4*_t5 - _hc2[11]*_t59 + _hc2[14]*_t11*_t12*_t4*_t5*_t9 - _hc2[14]*_t28 - _hc2[15]*_t71 + 0.2e1*_hc2[2]*_hc2[3]*_hc2[4]*_t3*_t32*_t4*_t5 - _hc2[2]*_hc2[3]*_t74 + _hc2[26]*_t3*_t4*_t5*_t9 + 0.2e1*_hc2[3]*_t11*_t12*_t15*_t32*_t4*_t5 - _hc2[4]*_t60 - _hc2[7]*_t103 + 0.2e1*_hc2[8]*_t15*_t3*_t32*_t4*_t5 - _hc2[8]*_t70 - _t40*_t58;
  out[26] = d4f_drs_dz_dt2;
  const double d4f_drs_dz2_dt = 0.4e1*_hc2[1]*_hc2[2]*_hc2[3]*_t11*_t12*_t32*_t4*_t5 + 0.4e1*_hc2[1]*_hc2[2]*_hc2[8]*_t3*_t32*_t4*_t5 + 0.2e1*_hc2[1]*_hc2[3]*_hc2[6]*_t3*_t32*_t4*_t5 - _hc2[12]*_t59 + 0.2e1*_hc2[15]*_t11*_t12*_t4*_t5*_t9 - _hc2[15]*_t72 - _hc2[16]*_t18 + 0.4e1*_hc2[2]*_hc2[3]*_hc2[5]*_t3*_t32*_t4*_t5 + _hc2[27]*_t3*_t4*_t5*_t9 - _hc2[7]*_t104 + _hc2[7]*_t11*_t2*_t23*_t4*_t5*_t9 + _hc2[7]*_t12*_t22*_t4*_t5*_t9 + 0.2e1*_hc2[7]*_t21*_t3*_t32*_t4*_t5 - _hc2[8]*_t103 - _t105*_t106 - _t105*_t75 - _t105*_t77 - _t35*_t60 - _t40*_t61 - _t58*_t90;
  out[27] = d4f_drs_dz2_dt;
  const double d4f_drs_dz3 = -_hc2[13]*_t59 + _hc2[28]*_t10 + _hc2[3]*_t79*_t80 - _hc2[3]*_t81 - _hc2[3]*_t88 + _hc2[3]*_t93 - _hc2[3]*_t95 - _hc2[6]*_t108 + _hc2[8]*_t54 + _hc2[8]*_t94 + _t101*_t62 + _t107*_t26 - _t107*_t28 + _t109*_t83 - _t109*_t90 - _t43*_t60 + _t52*_t62*_t86 + _t62*_t84 + _t62*_t89;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = 0.8e1*_hc2[1]*_hc2[3]*_hc2[7]*_t3*_t32*_t4*_t5 - _hc2[14]*_t110 - _hc2[17]*_t71 + _hc2[29]*_t3*_t4*_t5*_t9 + 0.2e1*_hc2[4]*_t29*_t3*_t32*_t4*_t5 - ((_hc2[7]) * (_hc2[7]))*_t73 + 0.2e1*_hc2[9]*_t15*_t3*_t32*_t4*_t5 - _hc2[9]*_t70 - _t29*_t74;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dz_dt = 0.2e1*_hc2[1]*_hc2[2]*_hc2[9]*_t3*_t32*_t4*_t5 - _hc2[1]*_hc2[2]*_t29*_t66 + 0.4e1*_hc2[1]*_hc2[3]*_hc2[8]*_t3*_t32*_t4*_t5 + 0.2e1*_hc2[1]*_t11*_t12*_t29*_t32*_t4*_t5 - _hc2[15]*_t110 + _hc2[17]*_t11*_t12*_t4*_t5*_t9 - _hc2[17]*_t28 - _hc2[18]*_t18 + 0.4e1*_hc2[2]*_hc2[3]*_hc2[7]*_t3*_t32*_t4*_t5 + _hc2[30]*_t3*_t4*_t5*_t9 - _hc2[5]*_hc2[9]*_t17 + 0.2e1*_hc2[5]*_t29*_t3*_t32*_t4*_t5 - _hc2[7]*_hc2[8]*_t73 - _hc2[9]*_t40 - _t58*_t60;
  out[30] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz2 = -_hc2[16]*_t110 + 0.2e1*_hc2[18]*_t11*_t12*_t4*_t5*_t9 - _hc2[18]*_t72 + 0.8e1*_hc2[2]*_hc2[3]*_hc2[8]*_t3*_t32*_t4*_t5 + 0.4e1*_hc2[2]*_t11*_t12*_t29*_t32*_t4*_t5 + _hc2[31]*_t3*_t4*_t5*_t9 + 0.2e1*_hc2[6]*_t29*_t3*_t32*_t4*_t5 - ((_hc2[8]) * (_hc2[8]))*_t73 - 0.4e1*_hc2[8]*_t60 - _hc2[9]*_t104 + _hc2[9]*_t11*_t2*_t23*_t4*_t5*_t9 + _hc2[9]*_t12*_t22*_t4*_t5*_t9 + 0.2e1*_hc2[9]*_t21*_t3*_t32*_t4*_t5 - _hc2[9]*_t76 - _t106*_t29 - _t29*_t75 - _t29*_t77;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dt = 0.6e1*_hc2[1]*_hc2[3]*_hc2[9]*_t3*_t32*_t4*_t5 - _hc2[1]*_t111 - _hc2[17]*_t64 - _hc2[19]*_t18 + _hc2[32]*_t3*_t4*_t5*_t9 + 0.6e1*_hc2[7]*_t29*_t3*_t32*_t4*_t5 - _hc2[9]*_t102;
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dz = -_hc2[18]*_t64 + _hc2[19]*_t11*_t12*_t4*_t5*_t9 - _hc2[19]*_t28 + 0.6e1*_hc2[2]*_hc2[3]*_hc2[9]*_t3*_t32*_t4*_t5 - _hc2[2]*_t111 - _hc2[3]*_hc2[9]*_t55 + _hc2[33]*_t3*_t4*_t5*_t9 + 0.6e1*_hc2[8]*_t29*_t3*_t32*_t4*_t5 - _hc2[9]*_t108 + 0.2e1*_t11*_t12*_t32*_t4*_t5*_t65;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = -0.4e1*_hc2[19]*_t59 - ((_hc2[3]) * (_hc2[3]) * (_hc2[3]) * (_hc2[3]))*_t66 + _hc2[34]*_t3*_t4*_t5*_t9 - ((_hc2[9]) * (_hc2[9]))*_t67 + 0.12e2*_hc2[9]*_t29*_t3*_t32*_t4*_t5;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ff_k, _KMAX)(const xc_func_type *p, double z, double t, double *out) {
  const gga_c_zpbeint_params *params = (const gga_c_zpbeint_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  const double _t1 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t2 = (t * t * t);
  const double _t3 = _t2*params->alpha;
  const double _t4 = pow(_t1, _t3);
#if _KMAX >= 1
  const double _t5 = log(_t1);
  const double _t6 = _t4*params->alpha;
  const double _t7 = _t5*_t6;
  const double _t8 = (t * t);
  const double _t9 = 0.3e1*_t8;
  const double _t10 = (0.1e1 / _t1);
  const double _t11 = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  const double _t12 = _t10*_t11;
  const double _t13 = _t3*_t4;
#endif
#if _KMAX >= 2
  const double _t14 = 0.6e1*_t7;
  const double _t15 = ((params->alpha) * (params->alpha));
  const double _t16 = _t15*(t * t * t * t);
  const double _t17 = (_t5 * _t5);
  const double _t18 = 0.9e1*_t17;
  const double _t19 = _t18*_t4;
  const double _t20 = _t12*_t6;
  const double _t21 = _t15*_t4;
  const double _t22 = _t12*_t21;
  const double _t23 = xc_powi(t, 5);
  const double _t24 = 0.3e1*_t5;
  const double _t25 = _t23*_t24;
  const double _t26 = xc_powi(t, 6);
  const double _t27 = _t15*_t26;
  const double _t28 = (_t11 * _t11);
  const double _t29 = pow(_t1, _t3 - 0.2e1)*_t28;
  const double _t30 = (0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5];
  const double _t31 = _t10*_t13;
  const double _t32 = (0.1e1 / (_t1 * _t1));
  const double _t33 = _t11*_t32;
  const double _t34 = -_t11;
  const double _t35 = _t13*_t34;
#endif
#if _KMAX >= 3
  const double _t36 = _t17*_t21;
  const double _t37 = (_t5 * _t5 * _t5);
  const double _t38 = ((params->alpha) * (params->alpha) * (params->alpha));
  const double _t39 = _t38*_t4;
  const double _t40 = _t37*_t39;
  const double _t41 = 0.6e1*_t20;
  const double _t42 = 0.24e2*_t16*_t4*_t5;
  const double _t43 = _t38*xc_powi(t, 7);
  const double _t44 = _t19*_t43;
  const double _t45 = _t15*_t23;
  const double _t46 = 0.6e1*_t45;
  const double _t47 = _t6*_t9;
  const double _t48 = _t10*_t30;
  const double _t49 = _t29*_t5;
  const double _t50 = xc_powi(t, 8);
  const double _t51 = _t38*_t50;
  const double _t52 = 0.3e1*_t51;
  const double _t53 = _t33*_t34;
  const double _t54 = _t21*_t25;
  const double _t55 = (_t34 * _t34 * _t34);
  const double _t56 = pow(_t1, _t3 - 0.3e1);
  const double _t57 = _t27*_t56;
  const double _t58 = xc_powi(t, 9);
  const double _t59 = _t38*_t58;
  const double _t60 = (_t11 * _t11 * _t11);
  const double _t61 = _t56*_t60;
  const double _t62 = (0.1e1 / 0.2e1)*_hc0[9] - 0.1e1 / 0.2e1*_hc1[9];
  const double _t63 = -_hc0[2] + _hc1[2];
  const double _t64 = _t28*_t57;
  const double _t65 = _hc0[5] + _hc1[5];
  const double _t66 = _t27*_t4;
  const double _t67 = _t32*_t66;
  const double _t68 = _t11*_t67;
  const double _t69 = -_t30;
  const double _t70 = _t13*_t33;
  const double _t71 = _t30*_t32;
  const double _t72 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t73 = _t11*_t72;
  const double _t74 = _t35*_t73;
#endif
#if _KMAX >= 4
  const double _t75 = ((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha));
  const double _t76 = _t4*_t75;
  const double _t77 = 0.6e1*_t6;
  const double _t78 = _t77*t;
  const double _t79 = _t55*_t56;
  const double _t80 = _t10*_t62;
  const double _t81 = _t28*_t56;
  const double _t82 = _t5*_t52;
  const double _t83 = _t33*_t65;
  const double _t84 = 0.6e1*_t21*_t23;
  const double _t85 = _t34*_t71;
  const double _t86 = _t33*_t69;
  const double _t87 = _t30*_t33;
  const double _t88 = _t63*_t73;
  const double _t89 = _t34*_t88;
  const double _t90 = _t24*_t39*_t50;
  const double _t91 = pow(_t1, _t3 - 0.4e1);
  const double _t92 = _t59*_t91;
  const double _t93 = _t59*_t81;
  const double _t94 = _t27*_t55*_t91;
  const double _t95 = _t60*_t92;
  const double _t96 = -0.3e1 / 0.2e1*_hc0[2] + (0.3e1 / 0.2e1)*_hc1[2];
  const double _t97 = -_t65;
  const double _t98 = 0.3e1*_t35;
  const double _t99 = _t13*_t69;
  const double _t100 = _t63*_t96;
  const double _t101 = _t66*_t73;
  const double _t102 = _t101*_t65;
  const double _t103 = _t101*_t30;
#endif

  const double f = _t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t7*_t9;
  out[1] = df_dt;
  const double df_dz = _t12*_t13;
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t14*t + _t16*_t19;
  out[3] = d2f_dt2;
  const double d2f_dz_dt = _t20*_t9 + _t22*_t25;
  out[4] = d2f_dz_dt;
  const double d2f_dz2 = _t27*_t29 + _t30*_t31 + _t33*_t35;
  out[5] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t14 + 0.54e2*_t2*_t36 + 0.27e2*_t26*_t40;
  out[6] = d3f_dt3;
  const double d3f_dz_dt2 = _t12*_t42 + _t12*_t44 + _t41*t;
  out[7] = d3f_dz_dt2;
  const double d3f_dz2_dt = _t29*_t46 + _t47*_t48 + _t47*_t53 + _t48*_t54 + _t49*_t52 + _t53*_t54;
  out[8] = d3f_dz2_dt;
  const double d3f_dz3 = _t30*_t68 + _t31*_t62 + 0.2e1*_t35*_t71 + _t55*_t57 + _t59*_t61 + _t63*_t64 + _t63*_t74 + _t65*_t68 + _t69*_t70;
  out[9] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.324e3*_t23*_t40 + 0.180e3*_t36*_t8 + 0.81e2*(_t5 * _t5 * _t5 * _t5)*_t50*_t76;
  out[10] = d4f_dt4;
  const double d4f_dz_dt3 = 0.135e3*_t12*_t17*_t26*_t39 + 0.27e2*_t12*_t37*_t58*_t76 + 0.114e3*_t2*_t22*_t5 + _t41;
  out[11] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = 0.30e2*_t16*_t29 + _t18*_t29*_t75*xc_powi(t, 10) + _t42*_t48 + _t42*_t53 + 0.42e2*_t43*_t49 + _t44*_t48 + _t44*_t53 + _t48*_t78 + _t53*_t78;
  out[12] = d4f_dz2_dt2;
  const double d4f_dz3_dt = _t24*_t61*_t75*xc_powi(t, 11) + _t45*_t81*(-0.6e1*_hc0[2] + 0.6e1*_hc1[2]) + _t46*_t79 + _t47*_t80 + _t47*_t86 + _t47*_t89 + _t5*_t84*_t85 + 0.9e1*_t51*_t61 + _t54*_t80 + _t54*_t86 + _t54*_t89 + _t63*_t81*_t82 + _t77*_t8*_t85 + _t79*_t82 + _t83*_t84 + _t83*_t90 + _t84*_t87 + _t87*_t90;
  out[13] = d4f_dz3_dt;
  const double d4f_dz4 = _t100*_t27*_t28*_t91 + _t102*_t34 + 0.2e1*_t102*_t63 + 0.2e1*_t103*_t34 + _t103*_t63 + (_t11 * _t11 * _t11 * _t11)*_t75*_t91*xc_powi(t, 12) + (_t30 * _t30)*_t67 + _t30*_t63*_t72*_t98 + _t30*_t65*_t67 + _t30*_t93 + _t31*((0.1e1 / 0.2e1)*_hc0[14] + (0.1e1 / 0.2e1)*_hc1[14]) + _t32*_t62*_t98 - (_t34 * _t34 * _t34 * _t34)*_t92 + 0.2e1*_t62*_t68 - _t62*_t70 + _t63*_t94 + _t63*_t95 + 0.2e1*_t64*_t97 + _t65*_t93 + _t68*(_hc0[9] - _hc1[9]) + 0.3e1*_t71*_t99 + _t74*_t97 + 0.2e1*_t88*_t99 + _t93*((0.3e1 / 0.2e1)*_hc0[5] + (0.3e1 / 0.2e1)*_hc1[5]) + _t94*_t96 + _t95*_t96 + _t100*_t11*_t35/(_t1 * _t1 * _t1 * _t1);
  out[14] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tp_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {

  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = (0.1e1 / 0.8e1)*_t1/xc_powr(rs, 1, 2);
#if _KMAX >= 1
  const double _t3 = (0.1e1 / 0.16e2)*_t1/xc_powr(rs, 3, 2);
#endif
#if _KMAX >= 2
  const double _t4 = (0.3e1 / 0.32e2)*_t1/xc_powr(rs, 5, 2);
#endif
#if _KMAX >= 3
  const double _t5 = (0.15e2 / 0.64e2)*_t1/xc_powr(rs, 7, 2);
#endif

  const double f = _t2*xt;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t2;
  out[1] = df_dxt;
  const double df_drs = -_t3*xt;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = 0;
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = -_t3;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = _t4*xt;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0;
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = 0;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = _t4;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = -_t5*xt;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = 0;
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = 0;
  out[11] = d4f_drs_dxt3;
  const double d4f_drs2_dxt2 = 0;
  out[12] = d4f_drs2_dxt2;
  const double d4f_drs3_dxt = -_t5;
  out[13] = d4f_drs3_dxt;
  const double d4f_drs4 = (0.105e3 / 0.128e3)*_t1*xt/xc_powr(rs, 9, 2);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 0.01328816518*rs + 0.062181399999999998;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = 0.10186556948*_t3 + 0.47231125997999995*_t4 + 0.030651699315999998*(rs * rs) + 0.22308199064000001*rs;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = xc_log1p(_t6);
#if _KMAX >= 1
  const double _t8 = sqrt(rs);
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = -0.15279835421999999*_t8 - 0.23615562998999998*_t9 - 0.061303398631999996*rs - 0.22308199064000001;
  const double _t11 = (0.1e1 / (_t5 * _t5));
  const double _t12 = _t6 + 0.1e1;
  const double _t13 = (0.1e1 / _t12);
#endif
#if _KMAX >= 2
  const double _t14 = _t11*_t13;
  const double _t15 = (0.1e1 / _t8);
  const double _t16 = xc_powr(rs, -3, 2);
  const double _t17 = -0.076399177109999994*_t15 + 0.11807781499499999*_t16 - 0.061303398631999996;
  const double _t18 = _t14*_t17;
  const double _t19 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t20 = (0.1e1 / (_t12 * _t12));
  const double _t21 = (_t10 * _t10);
  const double _t22 = _t20*_t21;
  const double _t23 = _t19*_t22;
  const double _t24 = _t13/(_t5 * _t5 * _t5);
  const double _t25 = -0.30559670843999998*_t8 - 0.47231125997999995*_t9 - 0.12260679726399999*rs - 0.44616398128000001;
  const double _t26 = _t10*_t2;
  const double _t27 = _t25*_t26;
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / _t3);
  const double _t29 = xc_powr(rs, -5, 2);
  const double _t30 = 0.038199588554999997*_t28 - 0.17711672249249999*_t29;
  const double _t31 = _t14*_t30;
  const double _t32 = (_t10 * _t10 * _t10);
  const double _t33 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t34 = xc_powi(_t5, -6);
  const double _t35 = _t33*_t34;
  const double _t36 = _t32*_t35;
  const double _t37 = _t10*_t24;
  const double _t38 = -0.15279835421999999*_t15 + 0.23615562998999998*_t16 - 0.12260679726399999;
  const double _t39 = _t26*_t38;
  const double _t40 = _t19*_t20;
  const double _t41 = _t17*_t40;
  const double _t42 = _t24*_t25;
  const double _t43 = _t17*_t42;
  const double _t44 = 0.2e1*_t2;
  const double _t45 = -0.61119341687999995*_t8 - 0.94462251995999991*_t9 - 0.24521359452799998*rs - 0.89232796256000002;
  const double _t46 = xc_powi(_t5, -5);
  const double _t47 = _t22*_t46;
  const double _t48 = _t2*_t47;
  const double _t49 = -0.45839506265999996*_t8 - 0.70846688996999996*_t9 - 0.18391019589599999*rs - 0.66924597192000002;
  const double _t50 = _t13*_t19*_t49;
#endif
#if _KMAX >= 4
  const double _t51 = 0.053152660720000001*_t10;
  const double _t52 = _t2*_t38;
  const double _t53 = _t26*(0.076399177109999994*_t28 - 0.35423344498499998*_t29);
  const double _t54 = 0.3e1*_t2;
  const double _t55 = -0.22919753132999998*_t15 + 0.35423344498499998*_t16 - 0.18391019589599999;
  const double _t56 = _t21*_t35;
  const double _t57 = _t44*_t56;
  const double _t58 = _t32*_t33*_t44/xc_powi(_t5, 7);
  const double _t59 = _t25*_t50;
  const double _t60 = _t13*_t27;
  const double _t61 = _t20*_t46;
  const double _t62 = 0.2e1*_t39;
  const double _t63 = _t17*_t61;
  const double _t64 = -0.76399177109999994*_t8 - 1.1807781499499999*_t9 - 0.30651699315999997*rs - 1.1154099531999999;
  const double _t65 = _t2*_t22*_t25*_t34;
#endif

  const double f = _t2*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t11*_t13*_t2 - 0.01328816518*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1*_t23 - 0.026576330360000001*_t10*_t14 + _t18*_t2 + _t24*_t27;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.039864495540000003*_t18 + _t2*_t31 + 0.039864495540000003*_t23 + _t24*_t39 - 0.039864495540000003*_t25*_t37 - _t25*_t48 - _t26*_t41 + _t27*_t50 + _t36*(-0.026576330360000001*rs - 0.1243628) - _t39*_t40 + _t43*_t44 - _t45*_t48;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t1*(_t17 * _t17)*_t40 + (_t10 * _t10 * _t10 * _t10)*(0.079728991080000006*rs + 0.37308839999999999)/((_t12 * _t12 * _t12 * _t12)*xc_powi(_t5, 8)) + _t14*_t2*(-0.057299382832499995*pow(rs, -2.5) + 0.44279180623124997/xc_powr(rs, 7, 2)) + 0.3e1*_t17*_t24*_t52 + _t17*_t54*_t59 + _t17*_t57 + _t19*_t55*_t60 - _t2*_t22*_t34*_t45*_t64 + _t24*_t53 + _t25*_t58 - 0.2e1*_t26*_t30*_t40 - _t26*_t45*_t63 - _t27*_t38*_t61 - 0.2e1*_t27*_t63 + _t30*_t42*_t54 - 0.053152660720000001*_t31 - 0.10630532144*_t36 - 0.053152660720000001*_t37*_t38 + _t38*_t40*_t51 - 0.2e1*_t38*_t48 - _t40*_t53 + _t41*_t51 - _t41*_t52 - 0.10630532144*_t43 + _t45*_t46*_t49*_t60 + _t45*_t58 - _t45*_t61*_t62 + _t47*(-0.032486556321720157*_t8 - 0.050209200311905303*_t9 - 0.013033754993878433*rs - 0.047429605444920545) + _t47*(-0.016243278160860079*_t8 - 0.025104600155952651*_t9 - 0.0065168774969392163*rs - 0.023714802722460272) - _t48*(-0.30559670843999998*_t15 + 0.47231125997999995*_t16 - 0.24521359452799998) - _t49*_t65 + _t50*_t62 - _t51*_t59 + 0.2e1*_t52*_t56 + _t55*_t57 + _t58*(-0.91679012531999993*_t8 - 1.4169337799399999*_t9 - 0.36782039179199999*rs - 1.33849194384) - _t64*_t65;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(A_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, 0, 0, _hc1);
  const double _t1 = 0.1e1 - M_LN2;
  const double _t2 = (M_PI * M_PI)/_t1;
  const double _t3 = xc_expm1(-_hc0[0]*_t2);
#if _KMAX >= 1
  const double _t4 = _hc0[1]*_hc1[0];
  const double _t5 = _t3 + 0.1e1;
  const double _t6 = _t5/(_t3 * _t3);
  const double _t7 = _t4*_t6;
  const double _t8 = (M_PI * M_PI * M_PI * M_PI)/(_t1 * _t1);
#endif
#if _KMAX >= 2
  const double _t9 = _hc1[0]*_t6;
  const double _t10 = _t8*_t9;
  const double _t11 = xc_powi(M_PI, 6)/(_t1 * _t1 * _t1);
  const double _t12 = ((_hc0[1]) * (_hc0[1]));
  const double _t13 = _t12*_t9;
  const double _t14 = _hc1[0]*_t12;
  const double _t15 = (_t5 * _t5)/(_t3 * _t3 * _t3);
  const double _t16 = _t11*_t15;
#endif
#if _KMAX >= 3
  const double _t17 = xc_powi(M_PI, 8)/(_t1 * _t1 * _t1 * _t1);
  const double _t18 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t17;
  const double _t19 = 0.3e1*_t11;
  const double _t20 = 0.6e1*_hc0[2];
  const double _t21 = _t16*_t4;
  const double _t22 = 0.6e1*_hc1[0];
  const double _t23 = _t18*_t22;
  const double _t24 = (_t5 * _t5 * _t5)/(_t3 * _t3 * _t3 * _t3);
#endif
#if _KMAX >= 4
  const double _t25 = ((_hc0[2]) * (_hc0[2]));
  const double _t26 = xc_powi(M_PI, 10)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))/xc_powi(_t1, 5);
  const double _t27 = _hc1[0]*_t26;
  const double _t28 = 0.36e2*_t24;
  const double _t29 = _hc0[2]*_t14*_t17;
#endif

  const double f = _hc1[0]*_t2/_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_drs = _t7*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = 0;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _hc0[2]*_t10 - _t11*_t13 + 0.2e1*_t14*_t16;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = 0;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = 0;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = -_hc0[2]*_t19*_t7 + _hc0[3]*_t10 - _t15*_t23 + _t18*_t9 + _t20*_t21 + _t23*_t24;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = 0;
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = 0;
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = 0;
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = -0.4e1*_hc0[3]*_t11*_t7 + 0.8e1*_hc0[3]*_t21 + _hc0[4]*_t10 + _t13*_t17*_t20 + 0.14e2*_t15*_t27 - 0.36e2*_t15*_t29 + _t16*_t22*_t25 - _t19*_t25*_t9 - _t26*_t9 - _t27*_t28 + 0.24e2*_t27*(_t5 * _t5 * _t5 * _t5)/xc_powi(_t3, 5) + _t28*_t29;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f1_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(A_z0_k, _KMAX)(p, rs, t, _hc0);
  const double _t1 = (t * t);
  const double _t2 = (t * t * t * t);
#if _KMAX >= 1
  const double _t3 = (t * t * t);
  const double _t4 = 0.4e1*_t3;
#endif
#if _KMAX >= 2
  const double _t5 = 0.12e2*_t1;
  const double _t6 = 0.8e1*_t3;
#endif
#if _KMAX >= 3
  const double _t7 = 0.24e2*_hc0[0];
  const double _t8 = 0.36e2*_t1;
  const double _t9 = 0.12e2*_t3;
#endif

  const double f = _hc0[0]*_t2 + _t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[0]*_t4 + _hc0[1]*_t2 + 0.2e1*t;
  out[1] = df_dt;
  const double df_drs = _hc0[2]*_t2;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[0]*_t5 + _hc0[1]*_t6 + _hc0[3]*_t2 + 0.2e1;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = _hc0[2]*_t4 + _hc0[4]*_t2;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _hc0[5]*_t2;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[1]*_t8 + _hc0[3]*_t9 + _hc0[6]*_t2 + _t7*t;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _hc0[2]*_t5 + _hc0[4]*_t6 + _hc0[7]*_t2;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = _hc0[5]*_t4 + _hc0[8]*_t2;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = _hc0[9]*_t2;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.96e2*_hc0[1]*t + _hc0[10]*_t2 + 0.72e2*_hc0[3]*_t1 + 0.16e2*_hc0[6]*_t3 + _t7;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = _hc0[11]*_t2 + 0.24e2*_hc0[2]*t + _hc0[4]*_t8 + _hc0[7]*_t9;
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = _hc0[12]*_t2 + _hc0[5]*_t5 + _hc0[8]*_t6;
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = _hc0[13]*_t2 + _hc0[9]*_t4;
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = _hc0[14]*_t2;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f2_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(A_z0_k, _KMAX)(p, rs, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f1_z0_k, _KMAX)(p, rs, t, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, 0, 0, _hc2);
  const double _t1 = _hc0[0]*_hc1[0] + 0.1e1;
  const double _t2 = (M_PI * M_PI)*_hc2[0]/(0.1e1 - M_LN2);
  const double _t3 = _t2/_t1;
#if _KMAX >= 1
  const double _t4 = _hc0[0]*_hc1[1];
  const double _t5 = _hc0[1]*_hc1[0];
  const double _t6 = -_t4 - _t5;
  const double _t7 = _t2/(_t1 * _t1);
  const double _t8 = _hc1[0]*_t7;
  const double _t9 = _hc0[0]*_hc1[2];
  const double _t10 = _hc0[2]*_hc1[0];
  const double _t11 = -_t10 - _t9;
#endif
#if _KMAX >= 2
  const double _t12 = 0.2e1*_hc1[1];
  const double _t13 = _t6*_t7;
  const double _t14 = _hc0[0]*_hc1[3];
  const double _t15 = _hc0[3]*_hc1[0];
  const double _t16 = _hc0[1]*_hc1[1];
  const double _t17 = -_t14 - _t15 - 0.2e1*_t16;
  const double _t18 = _t2/(_t1 * _t1 * _t1);
  const double _t19 = _hc1[0]*_t18;
  const double _t20 = -0.2e1*_t4 - 0.2e1*_t5;
  const double _t21 = _t20*_t6;
  const double _t22 = _t11*_t7;
  const double _t23 = _hc1[2]*_t7;
  const double _t24 = _hc0[0]*_hc1[4];
  const double _t25 = _hc0[1]*_hc1[2];
  const double _t26 = _hc0[2]*_hc1[1];
  const double _t27 = _hc0[4]*_hc1[0];
  const double _t28 = -_t24 - _t25 - _t26 - _t27;
  const double _t29 = _t11*_t19;
  const double _t30 = 0.2e1*_hc1[2];
  const double _t31 = _hc0[0]*_hc1[5];
  const double _t32 = _hc0[5]*_hc1[0];
  const double _t33 = 0.2e1*_hc0[2];
  const double _t34 = -_hc1[2]*_t33 - _t31 - _t32;
  const double _t35 = -0.2e1*_t10 - 0.2e1*_t9;
#endif
#if _KMAX >= 3
  const double _t36 = 0.3e1*_hc1[3];
  const double _t37 = 0.3e1*_hc1[1];
  const double _t38 = _t17*_t7;
  const double _t39 = _hc0[0]*_hc1[6];
  const double _t40 = _hc0[6]*_hc1[0];
  const double _t41 = _hc0[1]*_hc1[3];
  const double _t42 = _hc0[3]*_hc1[1];
  const double _t43 = -_t39 - _t40 - 0.3e1*_t41 - 0.3e1*_t42;
  const double _t44 = _t18*_t21;
  const double _t45 = -0.2e1*_t14 - 0.2e1*_t15 - 0.4e1*_t16;
  const double _t46 = _t19*_t6;
  const double _t47 = _t19*_t20;
  const double _t48 = 0.2e1*_t47;
  const double _t49 = -0.3e1*_t4 - 0.3e1*_t5;
  const double _t50 = _t2/(_t1 * _t1 * _t1 * _t1);
  const double _t51 = _hc1[0]*_t50;
  const double _t52 = _t49*_t51;
  const double _t53 = 0.2e1*_hc1[4];
  const double _t54 = _t28*_t7;
  const double _t55 = _hc1[2]*_t18;
  const double _t56 = _t11*_t18;
  const double _t57 = _t20*_t56;
  const double _t58 = _hc0[0]*_hc1[7];
  const double _t59 = _hc0[2]*_hc1[3];
  const double _t60 = _hc0[3]*_hc1[2];
  const double _t61 = _hc0[7]*_hc1[0];
  const double _t62 = 0.2e1*_hc0[1];
  const double _t63 = 0.2e1*_hc0[4];
  const double _t64 = -_hc1[1]*_t63 - _hc1[4]*_t62 - _t58 - _t59 - _t60 - _t61;
  const double _t65 = _t11*_t52;
  const double _t66 = _hc1[5]*_t7;
  const double _t67 = _t34*_t7;
  const double _t68 = _t35*_t56;
  const double _t69 = _t19*_t34;
  const double _t70 = _hc0[0]*_hc1[8];
  const double _t71 = _hc0[1]*_hc1[5];
  const double _t72 = _hc0[5]*_hc1[1];
  const double _t73 = _hc0[8]*_hc1[0];
  const double _t74 = -_hc1[2]*_t63 - _hc1[4]*_t33 - _t70 - _t71 - _t72 - _t73;
  const double _t75 = _t19*_t35;
  const double _t76 = -0.2e1*_t24 - 0.2e1*_t25 - 0.2e1*_t26 - 0.2e1*_t27;
  const double _t77 = 0.3e1*_t22;
  const double _t78 = 0.3e1*_hc1[2];
  const double _t79 = _hc0[0]*_hc1[9];
  const double _t80 = _hc0[9]*_hc1[0];
  const double _t81 = 0.3e1*_hc0[2];
  const double _t82 = 0.3e1*_hc0[5];
  const double _t83 = -_hc1[2]*_t82 - _hc1[5]*_t81 - _t79 - _t80;
  const double _t84 = 0.4e1*_hc0[2];
  const double _t85 = -_hc1[2]*_t84 - 0.2e1*_t31 - 0.2e1*_t32;
  const double _t86 = 0.2e1*_t69;
  const double _t87 = -0.3e1*_t10 - 0.3e1*_t9;
  const double _t88 = _t11*_t51;
  const double _t89 = _t35*_t88;
#endif
#if _KMAX >= 4
  const double _t90 = 0.6e1*_hc1[3];
  const double _t91 = 0.4e1*_hc1[1];
  const double _t92 = 0.4e1*_hc0[1];
  const double _t93 = _t18*_t20;
  const double _t94 = _t17*_t93;
  const double _t95 = _t45*_t6;
  const double _t96 = -0.2e1*_t39 - 0.2e1*_t40 - 0.6e1*_t41 - 0.6e1*_t42;
  const double _t97 = 0.3e1*_t47;
  const double _t98 = _t19*_t45;
  const double _t99 = 0.3e1*_t17;
  const double _t100 = _t21*_t49;
  const double _t101 = _t100*_t50;
  const double _t102 = -0.3e1*_t14 - 0.3e1*_t15 - 0.6e1*_t16;
  const double _t103 = _t20*_t52;
  const double _t104 = 0.2e1*_t52;
  const double _t105 = _hc1[0]*_t2/xc_powi(_t1, 5);
  const double _t106 = _t105*(-0.4e1*_t4 - 0.4e1*_t5);
  const double _t107 = 0.3e1*_hc1[7];
  const double _t108 = 0.3e1*_hc1[4];
  const double _t109 = _t45*_t56;
  const double _t110 = _t64*_t7;
  const double _t111 = _t28*_t93;
  const double _t112 = _t11*_t50;
  const double _t113 = _t20*_t49;
  const double _t114 = _t112*_t113;
  const double _t115 = 0.3e1*_t28;
  const double _t116 = 0.3e1*_hc0[4];
  const double _t117 = _t106*_t11;
  const double _t118 = 0.4e1*_hc1[4];
  const double _t119 = _t12*_t34;
  const double _t120 = _t7*_t74;
  const double _t121 = _t18*_t35;
  const double _t122 = _t121*_t28;
  const double _t123 = _t56*_t76;
  const double _t124 = 0.4e1*_hc1[2];
  const double _t125 = _t35*_t49;
  const double _t126 = _t112*_t125;
  const double _t127 = _t19*_t28;
  const double _t128 = 0.2e1*_t76;
  const double _t129 = 0.4e1*_hc0[4];
  const double _t130 = _t7*_t83;
  const double _t131 = _t56*_t85;
  const double _t132 = _t35*_t87;
  const double _t133 = _t112*_t132;
  const double _t134 = _t34*_t35;
  const double _t135 = _t132*_t51;
  const double _t136 = _t87*_t88;
  const double _t137 = 0.6e1*_hc1[5];
  const double _t138 = 0.6e1*_hc1[2];
#endif

  const double f = _hc1[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t3 + _t6*_t8;
  out[1] = df_dt;
  const double df_drs = _hc1[2]*_t3 + _t11*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[3]*_t3 + _t12*_t13 + _t17*_t8 + _t19*_t21;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = _hc1[1]*_t22 + _hc1[4]*_t3 + _t20*_t29 + _t23*_t6 + _t28*_t8;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _hc1[5]*_t3 + _t22*_t30 + _t29*_t35 + _t34*_t8;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc1[6]*_t3 + _t13*_t36 + _t17*_t48 + _t21*_t52 + _t37*_t38 + _t37*_t44 + _t43*_t8 + _t45*_t46;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _hc1[3]*_t22 + _hc1[7]*_t3 + _t12*_t54 + _t12*_t57 + _t13*_t53 + _t17*_t23 + _t20*_t65 + _t21*_t55 + _t28*_t48 + _t29*_t45 + _t64*_t8;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = _hc1[1]*_t67 + _hc1[1]*_t68 + _hc1[8]*_t3 + _t20*_t69 + _t22*_t53 + _t28*_t75 + _t29*_t76 + _t30*_t54 + _t30*_t57 + _t35*_t65 + _t6*_t66 + _t74*_t8;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = _hc1[5]*_t77 + _hc1[9]*_t3 + _t29*_t85 + _t35*_t86 + _t67*_t78 + _t68*_t78 + _t8*_t83 + _t87*_t89;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.8e1*_hc1[1]*_t94 + _hc1[10]*_t3 + 0.4e1*_hc1[6]*_t13 + _t100*_t106 + _t101*_t91 + _t102*_t21*_t51 + _t103*_t99 + _t104*_t95 + _t18*_t91*_t95 + _t38*_t90 + _t43*_t7*_t91 + _t43*_t97 + _t44*_t90 + _t46*_t96 + _t8*(-_hc0[0]*_hc1[10] - _hc0[10]*_hc1[0] - _hc0[3]*_t90 - _hc0[6]*_t91 - _hc1[6]*_t92) + _t98*_t99;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = 0.6e1*_hc1[1]*_t111 + _hc1[11]*_t3 + _hc1[2]*_t101 + _hc1[6]*_t22 + _t102*_t20*_t88 + _t103*_t115 + _t107*_t13 + _t108*_t38 + _t108*_t44 + _t109*_t37 + _t110*_t37 + _t113*_t117 + _t114*_t37 + _t115*_t98 + _t23*_t43 + _t29*_t96 + _t30*_t94 + _t36*_t54 + _t36*_t57 + 0.2e1*_t45*_t65 + _t55*_t95 + _t64*_t97 + _t8*(-_hc0[0]*_hc1[11] - _hc0[1]*_t107 - _hc0[11]*_hc1[0] - _hc0[2]*_hc1[6] - _hc0[3]*_t108 - _hc0[6]*_hc1[2] - _hc0[7]*_t37 - _hc1[3]*_t116);
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = _hc1[12]*_t3 + _hc1[3]*_t67 + _hc1[3]*_t68 + _hc1[5]*_t44 + 0.2e1*_hc1[7]*_t22 + 0.2e1*_hc1[8]*_t13 + _t102*_t89 + _t103*_t34 + _t104*_t28*_t35 + _t109*_t30 + _t110*_t30 + _t111*_t124 + _t114*_t30 + _t117*_t125 + _t118*_t54 + _t118*_t57 + _t119*_t93 + _t12*_t120 + _t12*_t122 + _t12*_t123 + _t12*_t126 + _t127*_t128 + _t128*_t65 + _t17*_t66 + _t29*(-_hc0[4]*_t91 - _hc1[4]*_t92 - 0.2e1*_t58 - 0.2e1*_t59 - 0.2e1*_t60 - 0.2e1*_t61) + _t45*_t69 + _t48*_t74 + _t64*_t75 + _t8*(-_hc0[0]*_hc1[12] - _hc0[12]*_hc1[0] - _hc0[3]*_hc1[5] - _hc0[5]*_hc1[3] - _hc0[7]*_t30 - _hc0[8]*_t12 - _hc1[4]*_t129 - _hc1[7]*_t33 - _hc1[8]*_t62);
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = _hc1[1]*_t130 + _hc1[1]*_t131 + _hc1[1]*_t133 + _hc1[13]*_t3 + 0.3e1*_hc1[5]*_t57 + _hc1[8]*_t77 + _hc1[9]*_t13 + _t104*_t134 + _t108*_t67 + _t108*_t68 + _t115*_t66 + _t117*_t132 + _t119*_t121 + _t120*_t78 + _t122*_t78 + _t123*_t78 + _t126*_t78 + _t127*_t85 + _t135*_t28 + _t136*_t76 + _t29*(-_hc1[2]*_t129 - _hc1[4]*_t84 - 0.2e1*_t70 - 0.2e1*_t71 - 0.2e1*_t72 - 0.2e1*_t73) + _t34*_t78*_t93 + _t47*_t83 + _t65*_t85 + 0.2e1*_t74*_t75 + _t76*_t86 + _t8*(-_hc0[0]*_hc1[13] - _hc0[1]*_hc1[9] - _hc0[13]*_hc1[0] - _hc0[8]*_t78 - _hc0[9]*_hc1[1] - _hc1[4]*_t82 - _hc1[5]*_t116 - _hc1[8]*_t81) + _t89*(-0.3e1*_t24 - 0.3e1*_t25 - 0.3e1*_t26 - 0.3e1*_t27);
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = _hc1[14]*_t3 + 0.4e1*_hc1[9]*_t22 + _t105*_t11*_t132*(-0.4e1*_t10 - 0.4e1*_t9) + _t124*_t130 + _t124*_t131 + _t124*_t133 + 0.8e1*_t134*_t55 + 0.3e1*_t135*_t34 + 0.2e1*_t136*_t85 + _t137*_t67 + _t137*_t68 + _t29*(-_hc0[2]*_t137 - _hc0[5]*_t138 - 0.2e1*_t79 - 0.2e1*_t80) + 0.3e1*_t69*_t85 + 0.3e1*_t75*_t83 + _t8*(-_hc0[0]*_hc1[14] - _hc0[14]*_hc1[0] - _hc0[5]*_t137 - _hc0[9]*_t124 - _hc1[9]*_t84) + _t89*(-_hc0[2]*_t138 - 0.3e1*_t31 - 0.3e1*_t32);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fH_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f2_z0_k, _KMAX)(p, rs, t, _hc0);
  const double _t1 = (0.1e1 / (M_PI * M_PI));
  const double _t2 = 0.1e1 - M_LN2;
  const double _t3 = _t1*_t2;
#if _KMAX >= 1
  const double _t4 = _hc0[0] + 0.1e1;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t3*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = ((_hc0[1]) * (_hc0[1]));
  const double _t8 = _t3/(_t4 * _t4);
  const double _t9 = _hc0[2]*_t8;
  const double _t10 = ((_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 3
  const double _t11 = 0.3e1*_t8;
  const double _t12 = _hc0[1]*_t11;
  const double _t13 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t14 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t15 = 0.2e1*_t14*_t3;
  const double _t16 = 0.2e1*_t8;
  const double _t17 = _hc0[1]*_t16;
  const double _t18 = _hc0[5]*_t8;
  const double _t19 = 0.2e1*_t9;
  const double _t20 = 0.3e1*_t9;
  const double _t21 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 4
  const double _t22 = _hc0[1]*_t8;
  const double _t23 = 0.6e1*_t3/(_t4 * _t4 * _t4 * _t4);
#endif

  const double f = _t3*xc_log1p(_hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1]*_t6;
  out[1] = df_dt;
  const double df_drs = _hc0[2]*_t6;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[3]*_t1*_t2*_t5 - _t7*_t8;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = -_hc0[1]*_t9 + _hc0[4]*_t1*_t2*_t5;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _hc0[5]*_t1*_t2*_t5 - _t10*_t8;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = -_hc0[3]*_t12 + _hc0[6]*_t6 + _t13*_t15;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _hc0[2]*_t15*_t7 - _hc0[3]*_t9 - _hc0[4]*_t17 + _hc0[7]*_t6;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = _hc0[1]*_t10*_t15 - _hc0[1]*_t18 - _hc0[4]*_t19 + _hc0[8]*_t6;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = -_hc0[5]*_t20 + _hc0[9]*_t6 + _t15*_t21;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = -((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t23 + _hc0[10]*_t1*_t2*_t5 - ((_hc0[3]) * (_hc0[3]))*_t11 + 0.12e2*_hc0[3]*_t1*_t14*_t2*_t7 - 0.4e1*_hc0[6]*_t22;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = 0.6e1*_hc0[1]*_hc0[2]*_hc0[3]*_t1*_t14*_t2 + _hc0[11]*_t1*_t2*_t5 - _hc0[2]*_t13*_t23 - _hc0[3]*_hc0[4]*_t11 + 0.6e1*_hc0[4]*_t1*_t14*_t2*_t7 - _hc0[6]*_t9 - _hc0[7]*_t12;
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = 0.8e1*_hc0[1]*_hc0[2]*_hc0[4]*_t1*_t14*_t2 + _hc0[12]*_t1*_t2*_t5 + 0.2e1*_hc0[3]*_t1*_t10*_t14*_t2 - _hc0[3]*_t18 - ((_hc0[4]) * (_hc0[4]))*_t16 + 0.2e1*_hc0[5]*_t1*_t14*_t2*_t7 - _hc0[7]*_t19 - _hc0[8]*_t17 - _t10*_t23*_t7;
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = 0.6e1*_hc0[1]*_hc0[2]*_hc0[5]*_t1*_t14*_t2 - _hc0[1]*_t21*_t23 + _hc0[13]*_t1*_t2*_t5 + 0.6e1*_hc0[4]*_t1*_t10*_t14*_t2 - 0.3e1*_hc0[4]*_t18 - _hc0[8]*_t20 - _hc0[9]*_t22;
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = _hc0[14]*_t1*_t2*_t5 - ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t23 - ((_hc0[5]) * (_hc0[5]))*_t11 + 0.12e2*_hc0[5]*_t1*_t10*_t14*_t2 - 0.4e1*_hc0[9]*_t9;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ff_z0_k, _KMAX)(const xc_func_type *p, double t, double *out) {
  const gga_c_zpbeint_params *params = (const gga_c_zpbeint_params *)(p->params);


  const double f = 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[2] = d2f_dt2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[3] = d3f_dt3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[4] = d4f_dt4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_c_zpbeint_params *params = (const gga_c_zpbeint_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)/xc_powr(na, 1, 3);
  const double _t5 = _t3*_t4;
  const double _t6 = xc_powr(gaa, 1, 2);
  const double _t7 = xc_powr(na, -4, 3);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tp_z0_k, _KMAX)(p, _t5, _t6*_t7, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(fH_z0_k, _KMAX)(p, _t5, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ff_z0_k, _KMAX)(p, 0, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, _t5, _hc3);
  const double _t8 = _hc1[0]*_hc2[0] + _hc3[0];
  const double zk = _t8;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t9 = (0.1e1 / 0.6e1)*_t7;
  const double _t10 = _t3*_t9;
  const double _t12 = xc_powr(na, -7, 3);
  const double _t13 = (0.4e1 / 0.3e1)*_t12;
  const double _t17 = (0.1e1 / _t6);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tp_z0_k, _KMAX)(p, _t5, 0, _hc4);
  const double _t11 = _hc4[1]*_t6;
  const double _t14 = _hc0[2]*_t3;
  const double _t15 = -_t11*_t13 - _t14*_t9;
  const double _t16 = _hc2[0]*(_hc1[1]*_t15 - _hc1[2]*_t10);
  const double _t18 = _hc4[1]*_t17;
  const double _t19 = _hc1[1]*_hc2[0];
  const double dF_dna = _t8 + na*(-_hc3[1]*_t10 + _t16);
  const double dF_dgaa = _t18*_t19*_t4;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t21 = (0.2e1 / 0.9e1)*_t12;
  const double _t22 = _t21*_t3;
  const double _t23 = xc_powr(0.6e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  const double _t25 = xc_powr(na, -8, 3);
  const double _t26 = (0.1e1 / 0.36e2)*_t25;
  const double _t30 = xc_powr(na, -10, 3);
  const double _t31 = (0.28e2 / 0.9e1)*_t30;
  const double _t34 = xc_powr(na, -11, 3);
  const double _t35 = (0.2e1 / 0.9e1)*_t34;
  const double _t36 = _t13*_t6;
  const double _t42 = (0.1e1 / 0.12e2)*_t25;
  const double _t43 = _t3*_t42;
  const double _t45 = (0.2e1 / 0.3e1)*_t12;
  const double _t50 = xc_powr(gaa, -3, 2);
  const double _t55 = (0.1e1 / gaa);
  const double _t20 = _hc3[1]*_t3;
  const double _t24 = _hc3[2]*_t23;
  const double _t27 = _hc1[4]*_t15 - _hc1[5]*_t10;
  const double _t28 = _hc1[3]*_t15;
  const double _t29 = -_hc1[4]*_t10 + _t28;
  const double _t32 = _hc4[4]*_t6;
  const double _t33 = _t3*_t32;
  const double _t37 = -_hc0[5]*_t10 - _hc4[4]*_t36;
  const double _t38 = -_t10*_t37 + _t11*_t31 + _t14*_t21 + _t33*_t35;
  const double _t39 = _hc2[0]*(_hc1[1]*_t38 + _hc1[2]*_t22 - _t10*_t27 + _t15*_t29);
  const double _t40 = _t18*_t7;
  const double _t41 = (0.1e1 / 0.2e1)*_t40;
  const double _t44 = _t18*_t43;
  const double _t46 = _hc4[4]*_t17;
  const double _t47 = -_t18*_t45 - _t43*_t46;
  const double _t48 = _hc2[0]*(_hc1[1]*_t47 - _hc1[4]*_t44 + _t28*_t41);
  const double _t49 = _t19*_t7;
  const double _t51 = _hc4[1]*_t50;
  const double _t52 = (0.1e1 / 0.4e1)*_t51;
  const double _t53 = _t49*_t52;
  const double _t54 = ((_hc4[1]) * (_hc4[1]));
  const double d2F_dna2 = 0.2e1*_t16 - 0.1e1 / 0.3e1*_t20*_t7 + na*(_hc3[1]*_t22 + _t24*_t26 + _t39);
  const double d2F_dna_dgaa = _t19*_t41 + _t48*na;
  const double d2F_dgaa2 = na*((0.1e1 / 0.4e1)*_hc1[3]*_hc2[0]*_t25*_t54*_t55 - _t53);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t56 = (0.1e1 / (na * na * na * na));
  const double _t59 = (0.14e2 / 0.27e2)*_t30;
  const double _t61 = _t3*_t59;
  const double _t62 = (0.4e1 / 0.9e1)*_t12*_t3;
  const double _t64 = xc_powr(na, -13, 3);
  const double _t65 = (0.280e3 / 0.27e2)*_t64;
  const double _t66 = xc_powr(na, -14, 3);
  const double _t67 = (0.28e2 / 0.27e2)*_t66;
  const double _t71 = _t3*_t35;
  const double _t85 = (0.1e1 / 0.9e1)*_t34;
  const double _t86 = _t3*_t85;
  const double _t87 = (0.14e2 / 0.9e1)*_t30;
  const double _t88 = _t17*_t45;
  const double _t89 = _t17*_t43;
  const double _t101 = (0.1e1 / 0.24e2)*_t25;
  const double _t102 = _t101*_t3;
  const double _t105 = _t3*_t55;
  const double _t106 = (0.1e1 / 0.24e2)*_t105;
  const double _t107 = (0.1e1 / 0.3e1)*_t12;
  const double _t113 = xc_powr(gaa, -5, 2);
  const double _t116 = (0.1e1 / (gaa * gaa));
  const double _t117 = (0.3e1 / 0.8e1)*_t116;
  const double _t57 = _hc3[3]/M_PI;
  const double _t58 = _t56*_t57;
  const double _t60 = _t24*_t34;
  const double _t63 = 0.2e1*_t38;
  const double _t68 = _hc4[8]*_t23;
  const double _t69 = _hc4[4]*_t22 + _t26*_t68;
  const double _t70 = _hc4[8]*_t6;
  const double _t72 = -_hc0[9]*_t10 - _hc4[8]*_t36;
  const double _t73 = _hc0[5]*_t22 - _t10*_t72 + _t31*_t32 + _t70*_t71;
  const double _t74 = (0.4e1 / 0.9e1)*_t1*_t12*_t2*_t37 - _t10*_t73 - _t11*_t65 - _t14*_t59 - _t33*_t67 - _t36*_t69;
  const double _t75 = _hc1[8]*_t15 - _hc1[9]*_t10;
  const double _t76 = _hc1[7]*_t15;
  const double _t77 = -_hc1[8]*_t10 + _t76;
  const double _t78 = _hc1[4]*_t38 + _hc1[5]*_t22 - _t10*_t75 + _t15*_t77;
  const double _t79 = _hc1[6]*_t15;
  const double _t80 = -_hc1[7]*_t10 + _t79;
  const double _t81 = _hc1[3]*_t38;
  const double _t82 = _hc1[4]*_t22 - _t10*_t77 + _t15*_t80 + _t81;
  const double _t83 = _hc1[1]*_t74 - _hc1[2]*_t61 - _t10*_t78 + _t15*_t82 + _t27*_t62 + _t29*_t63;
  const double _t84 = _hc1[4]*_t18;
  const double _t90 = -_hc4[4]*_t88 - _hc4[8]*_t89;
  const double _t91 = -_t10*_t90 + _t18*_t87 + _t46*_t71;
  const double _t92 = _hc1[4]*_t47 - _hc1[8]*_t44 + _t41*_t76;
  const double _t93 = _hc1[3]*_t47;
  const double _t94 = -_hc1[7]*_t44 + _t41*_t79 + _t93;
  const double _t95 = _hc1[1]*_t91 - _t10*_t92 + _t15*_t94 + _t29*_t47 + _t41*_t81 + _t84*_t86;
  const double _t96 = _hc2[0]*na;
  const double _t97 = _t25*_t54;
  const double _t98 = _t55*_t97;
  const double _t99 = (0.1e1 / 0.4e1)*_t98;
  const double _t100 = _hc1[3]*_hc2[0];
  const double _t103 = _t102*_t51;
  const double _t104 = _hc1[7]*_t54*_t56;
  const double _t108 = _hc4[4]*_t50;
  const double _t109 = _t108*_t3;
  const double _t110 = _t101*_t109 + _t107*_t51;
  const double _t111 = _t52*_t7;
  const double _t112 = _hc1[1]*_t110 + _hc1[4]*_t103 - _t104*_t106 - _t111*_t28 + _t40*_t93 + _t79*_t99;
  const double _t114 = _hc4[1]*_t113;
  const double _t115 = (0.3e1 / 0.8e1)*_t114;
  const double _t118 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]));
  const double _t119 = _t118*_t50;
  const double _t120 = (0.1e1 / 0.8e1)*_t119*_t56;
  const double _t121 = _hc1[6]*_hc2[0];
  const double _t122 = -_t100*_t117*_t97 + _t115*_t49 + _t120*_t121;
  const double d3F_dna3 = _t20*_t45 + _t24*_t42 + 0.3e1*_t39 + na*(_hc2[0]*_t83 - _t20*_t59 - 0.1e1 / 0.36e2*_t58 - 0.1e1 / 0.9e1*_t60);
  const double d3F_dna2_dgaa = 0.2e1*_t48 + _t95*_t96;
  const double d3F_dna_dgaa2 = _t100*_t99 + _t112*_t96 - _t53;
  const double d3F_dgaa3 = _t122*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t123 = xc_powi(na, -5);
  const double _t124 = xc_powr(na, -16, 3);
  const double _t125 = (0.140e3 / 0.81e2)*_t64;
  const double _t126 = _t3*_t45;
  const double _t137 = _t3*_t66;
  const double _t145 = (0.1e1 / 0.16e2)*_t3;
  const double _t146 = _t145*_t25;
  const double _t127 = _hc4[13]*_t23*_t26 + _hc4[8]*_t22;
  const double _t128 = _hc1[12]*_t15;
  const double _t129 = -_hc1[13]*_t10 + _t128;
  const double _t130 = _hc1[11]*_t15;
  const double _t131 = -_hc1[12]*_t10 + _t130;
  const double _t132 = _hc1[7]*_t38;
  const double _t133 = _hc1[8]*_t22 - _t10*_t129 + _t131*_t15 + _t132;
  const double _t134 = _hc1[3]*_t74;
  const double _t135 = _hc1[10]*_t15;
  const double _t136 = _hc1[6]*_t38;
  const double _t138 = _t18*_t86;
  const double _t139 = _hc1[7]*_t47;
  const double _t140 = -_hc1[12]*_t44 + _t130*_t41 + _t139;
  const double _t141 = _hc1[3]*_t91;
  const double _t142 = _hc1[6]*_t47;
  const double _t143 = _t106*_t54*_t56;
  const double _t144 = _hc1[3]*_t110;
  const double d4F_dna4 = 0.4e1*_hc2[0]*_t83 - 0.56e2 / 0.27e2*_t20*_t30 - 0.1e1 / 0.9e1*_t58 - 0.4e1 / 0.9e1*_t60 + na*(_hc2[0]*(_hc1[1]*(-_t10*(-_hc0[5]*_t61 + (0.4e1 / 0.9e1)*_t1*_t12*_t2*_t72 - _t10*(_hc0[9]*_t22 + _hc4[13]*_t6*_t71 - _t10*(-_hc0[14]*_t10 - _hc4[13]*_t36) + _t31*_t70) - _t127*_t36 - _t3*_t67*_t70 - _t32*_t65) + (0.3640e4 / 0.81e2)*_t11*_t124 + _t125*_t14 + _t126*_t73 - _t3*_t37*_t87 + (0.28e2 / 0.3e1)*_t30*_t6*_t69 + (0.140e3 / 0.27e2)*_t33/xc_powr(na, 17, 3) - _t36*(-_hc4[4]*_t61 - _t10*_t127 - 0.2e1 / 0.27e2*_t34*_t68)) + _hc1[2]*_t125*_t3 - _t10*(_hc1[4]*_t74 - _hc1[5]*_t61 - _t10*(_hc1[8]*_t38 + _hc1[9]*_t22 - _t10*(_hc1[13]*_t15 - _hc1[14]*_t10) + _t129*_t15) + _t133*_t15 + _t62*_t75 + _t63*_t77) + _t126*_t78 + _t15*(-_hc1[4]*_t61 - _t10*_t133 + _t134 + _t15*(_hc1[7]*_t22 - _t10*_t131 + _t136 + _t15*(-_hc1[11]*_t10 + _t135)) + _t62*_t77 + _t63*_t80) - _t27*_t3*_t87 + 0.3e1*_t29*_t74 + 0.3e1*_t38*_t82) + (0.1e1 / 0.216e3)*_hc3[4]*_t1*_t124/(M_PI * M_CBRTPI) + (0.2e1 / 0.9e1)*_t123*_t57 + _t125*_t20 + (0.40e2 / 0.81e2)*_t24*_t66);
  const double d4F_dna3_dgaa = 0.3e1*_hc2[0]*_t95 + _t96*(_hc1[1]*((0.4e1 / 0.9e1)*_t1*_t12*_t2*_t90 - _t10*(_hc4[8]*_t17*_t71 - _t10*(-_hc4[13]*_t89 - _hc4[8]*_t88) + _t46*_t87) - 0.7e1 / 0.9e1*_t137*_t46 - 0.140e3 / 0.27e2*_t18*_t64 - _t69*_t88) - _t10*(_hc1[4]*_t91 + _hc1[8]*_t138 - _t10*(-_hc1[13]*_t44 + _hc1[8]*_t47 + _t128*_t41) + _t132*_t41 + _t140*_t15 + _t47*_t77) + _t134*_t41 - 0.7e1 / 0.27e2*_t137*_t84 + _t15*(_hc1[7]*_t138 - _t10*_t140 + _t136*_t41 + _t141 + _t15*(-_hc1[11]*_t44 + _t135*_t41 + _t142) + _t47*_t80) + 0.2e1*_t29*_t91 + _t47*_t82 + _t62*_t92 + _t63*_t94);
  const double d4F_dna2_dgaa2 = 0.2e1*_hc2[0]*_t112 + _t96*(_hc1[1]*(-_t10*(_hc4[8]*_t102*_t50 + _t107*_t108) - _t109*_t85 - 0.7e1 / 0.9e1*_t30*_t51) - 0.1e1 / 0.18e2*_hc1[4]*_t3*_t34*_t51 + (0.1e1 / 0.18e2)*_hc1[7]*_t105*_t123*_t54 - _t10*(-_hc1[12]*_t143 + _hc1[4]*_t110 + _hc1[8]*_t103 - _t111*_t76 + _t130*_t99 + _t139*_t40) + _t110*_t29 - _t111*_t81 + _t136*_t99 + _t141*_t40 + _t15*(-_hc1[11]*_t143 + _hc1[7]*_t103 - _t111*_t79 + _t135*_t99 + _t142*_t40 + _t144) + 0.2e1*_t47*_t94);
  const double d4F_dna_dgaa3 = _t122 + _t96*(_hc1[1]*(-_hc4[4]*_t113*_t146 - 0.1e1 / 0.2e1*_t114*_t12) - 0.1e1 / 0.48e2*_hc1[11]*_t119*_t124*_t3 - _hc1[4]*_t114*_t146 + _t104*_t116*_t145 + _t115*_t28*_t7 - _t117*_t79*_t97 + _t120*_t135 + (0.3e1 / 0.4e1)*_t142*_t98 + (0.3e1 / 0.2e1)*_t144*_t40 - 0.3e1 / 0.4e1*_t51*_t7*_t93);
  const double d4F_dgaa4 = na*((0.1e1 / 0.16e2)*_hc1[10]*_hc2[0]*((_hc4[1]) * (_hc4[1]) * (_hc4[1]) * (_hc4[1]))*_t116*_t124 + (0.15e2 / 0.16e2)*_hc1[3]*_hc2[0]*_t25*_t54/(gaa * gaa * gaa) - 0.15e2 / 0.16e2*_hc4[1]*_t49/xc_powr(gaa, 7, 2) - 0.3e1 / 0.8e1*_t113*_t118*_t121*_t56);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gab = sigma[1];
  const double gbb = sigma[2];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = _t5/xc_powr(_t1, 1, 3);
  const double _t7 = na - nb;
  const double _t8 = (0.1e1 / _t1);
  const double _t9 = _t7*_t8;
  const double _t10 = xc_powr(_t1, -4, 3);
  const double _t11 = gaa + 0.2e1*gab + gbb;
  const double _t12 = xc_powr(_t11, 1, 2);
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(tp_k, _KMAX)(p, _t6, _t9, _t10*_t12, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(fH_k, _KMAX)(p, _t6, _t9, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(ff_k, _KMAX)(p, _t9, _hc0[0], _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, _t6, _t9, _hc3);
  const double _t13 = _hc1[0]*_hc2[0] + _hc3[0];
  const double zk = _t13;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t14 = (0.1e1 / 0.6e1)*_t10;
  const double _t15 = _t14*_t4;
  const double _t17 = (0.1e1 / (_t1 * _t1));
  const double _t18 = _t17*_t7;
  const double _t19 = -_t18 + _t8;
  const double _t20 = xc_powr(_t1, -7, 3);
  const double _t22 = (0.4e1 / 0.3e1)*_t12;
  const double _t33 = -_t18 - _t8;
  const double _t41 = (0.1e1 / _t12);
  const double _t42 = _t10*_t41;
  double _hc4[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(tp_k, _KMAX)(p, _t6, _t9, 0, _hc4);
  const double _t16 = -_hc3[2]*_t15;
  const double _t21 = _hc4[1]*_t20;
  const double _t23 = _hc0[3]*_t4;
  const double _t24 = _t14*_t23 + _t21*_t22;
  const double _t25 = _hc0[2]*_t19 - _t24;
  const double _t26 = _hc2[1]*_t25 + _hc2[2]*_t19;
  const double _t27 = _hc1[0]*_t26;
  const double _t28 = -_hc1[3]*_t15;
  const double _t29 = _hc1[1]*_t25 + _hc1[2]*_t19 + _t28;
  const double _t30 = _hc2[0]*_t29;
  const double _t31 = _hc3[1]*_t19;
  const double _t32 = _t27 + _t30 + _t31;
  const double _t34 = _hc0[2]*_t33 - _t24;
  const double _t35 = _hc2[1]*_t34 + _hc2[2]*_t33;
  const double _t36 = _hc1[0]*_t35;
  const double _t37 = _hc1[1]*_t34 + _hc1[2]*_t33 + _t28;
  const double _t38 = _hc2[0]*_t37;
  const double _t39 = _hc3[1]*_t33;
  const double _t40 = _t36 + _t38 + _t39;
  const double _t43 = _hc4[1]*_t42;
  const double _t44 = _hc2[1]*_t43;
  const double _t45 = _hc1[0]*_t44;
  const double _t46 = _hc1[1]*_t43;
  const double _t47 = _hc2[0]*_t46;
  const double _t48 = (0.1e1 / 0.2e1)*_t45 + (0.1e1 / 0.2e1)*_t47;
  const double _t49 = _t1*_t48;
  const double _t50 = _t45 + _t47;
  const double dF_dna = _t1*(_t16 + _t32) + _t13;
  const double dF_dnb = _t1*(_t16 + _t40) + _t13;
  const double dF_dgaa = _t49;
  const double dF_dgab = _t1*_t50;
  const double dF_dgbb = _t49;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t52 = (0.1e1 / 0.3e1)*_t10;
  const double _t54 = (0.2e1 / 0.9e1)*_t20;
  const double _t55 = _t4*_t54;
  const double _t57 = 0.2e1*_t17;
  const double _t58 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t59 = 0.2e1*_t58;
  const double _t60 = _t59*_t7;
  const double _t61 = -_t57 + _t60;
  const double _t66 = _t20*_t22;
  const double _t75 = xc_powr(_t1, -10, 3);
  const double _t76 = (0.28e2 / 0.9e1)*_t75;
  const double _t126 = _t57 + _t60;
  const double _t141 = xc_powr(_t1, -8, 3);
  const double _t151 = _t141*_t4;
  const double _t152 = (0.1e1 / 0.12e2)*_t151;
  const double _t164 = (0.1e1 / 0.6e1)*_t151;
  const double _t190 = xc_powr(_t11, -3, 2);
  const double _t191 = _t10*_t190;
  const double _t51 = _hc3[2]*_t4;
  const double _t53 = -_t51*_t52;
  const double _t56 = _hc3[2]*_t55;
  const double _t62 = _hc2[4]*_t25 + _hc2[5]*_t19;
  const double _t63 = _hc2[4]*_t19;
  const double _t64 = _hc2[3]*_t25;
  const double _t65 = _t63 + _t64;
  const double _t67 = _hc0[8]*_t15 + _hc4[5]*_t66;
  const double _t68 = _hc0[6]*_t19 - _t67;
  const double _t69 = -_hc4[7]*_t15;
  const double _t70 = _hc4[5]*_t19;
  const double _t71 = _t69 + _t70;
  const double _t72 = _hc0[9]*_t15 + _hc4[7]*_t66;
  const double _t73 = _hc0[8]*_t19 - _t72;
  const double _t74 = _hc4[1]*_t12;
  const double _t77 = _t23*_t54 + _t74*_t76;
  const double _t78 = _hc0[2]*_t61 - _t15*_t73 + _t19*_t68 - _t66*_t71 + _t77;
  const double _t79 = _hc2[1]*_t78 + _hc2[2]*_t61 + _t19*_t62 + _t25*_t65;
  const double _t80 = _hc1[0]*_t79;
  const double _t81 = _hc1[3]*_t55;
  const double _t82 = -_hc1[9]*_t15;
  const double _t83 = _hc1[7]*_t25 + _hc1[8]*_t19 + _t82;
  const double _t84 = -_hc1[8]*_t15;
  const double _t85 = _hc1[5]*_t25 + _hc1[6]*_t19 + _t84;
  const double _t86 = -_hc1[7]*_t15;
  const double _t87 = _hc1[5]*_t19;
  const double _t88 = _hc1[4]*_t25;
  const double _t89 = _t86 + _t87 + _t88;
  const double _t90 = _hc1[1]*_t78 + _hc1[2]*_t61 - _t15*_t83 + _t19*_t85 + _t25*_t89 + _t81;
  const double _t91 = _hc2[0]*_t90;
  const double _t92 = _hc3[1]*_t61;
  const double _t93 = -_hc3[4]*_t15;
  const double _t94 = _hc3[3]*_t19 + _t93;
  const double _t95 = _t19*_t94;
  const double _t96 = _t26*_t29;
  const double _t97 = -_hc3[5]*_t15;
  const double _t98 = _hc3[4]*_t19 + _t97;
  const double _t99 = -_t15*_t98 + _t80 + _t91 + _t92 + _t95 + 0.2e1*_t96;
  const double _t100 = _hc2[4]*_t34 + _hc2[5]*_t33;
  const double _t101 = _hc2[4]*_t33;
  const double _t102 = _hc2[3]*_t34;
  const double _t103 = _t101 + _t102;
  const double _t104 = _hc0[6]*_t33 - _t67;
  const double _t105 = _hc4[5]*_t33;
  const double _t106 = _t105 + _t69;
  const double _t107 = _hc0[8]*_t33 - _t72;
  const double _t108 = -_t106*_t66 - _t107*_t15 + _t77;
  const double _t109 = _hc0[2]*_t60 + _t104*_t19 + _t108;
  const double _t110 = _hc2[1]*_t109 + _hc2[2]*_t60 + _t100*_t19 + _t103*_t25;
  const double _t111 = _hc1[0]*_t110;
  const double _t112 = _hc1[5]*_t34 + _hc1[6]*_t33 + _t84;
  const double _t113 = _hc1[5]*_t33;
  const double _t114 = _hc1[4]*_t34;
  const double _t115 = _t113 + _t114 + _t86;
  const double _t116 = _hc1[7]*_t34 + _hc1[8]*_t33 + _t82;
  const double _t117 = -_t116*_t15 + _t81;
  const double _t118 = _hc1[1]*_t109 + _hc1[2]*_t60 + _t112*_t19 + _t115*_t25 + _t117;
  const double _t119 = _hc2[0]*_t118;
  const double _t120 = _hc3[3]*_t33 + _t93;
  const double _t121 = _t120*_t19;
  const double _t122 = _t26*_t37;
  const double _t123 = _t29*_t35;
  const double _t124 = _hc3[4]*_t33 + _t97;
  const double _t125 = -_t124*_t15 + _t56;
  const double _t127 = _hc0[2]*_t126 + _t104*_t33 + _t108;
  const double _t128 = _hc2[1]*_t127 + _hc2[2]*_t126 + _t100*_t33 + _t103*_t34;
  const double _t129 = _hc1[0]*_t128;
  const double _t130 = _hc1[1]*_t127 + _hc1[2]*_t126 + _t112*_t33 + _t115*_t34 + _t117;
  const double _t131 = _hc2[0]*_t130;
  const double _t132 = _hc3[1]*_t126;
  const double _t133 = _t120*_t33;
  const double _t134 = 0.2e1*_t35;
  const double _t135 = _t129 + _t131 + _t132 + _t133 + _t134*_t37;
  const double _t136 = _t26*_t46;
  const double _t137 = _t29*_t44;
  const double _t138 = _t43*_t63;
  const double _t139 = _t43*_t64;
  const double _t140 = _t21*_t41;
  const double _t142 = _hc4[7]*_t41;
  const double _t143 = _t142*_t4;
  const double _t144 = _t141*_t143;
  const double _t145 = (0.2e1 / 0.3e1)*_t140 + (0.1e1 / 0.12e2)*_t144;
  const double _t146 = (0.1e1 / 0.2e1)*_hc4[5]*_t10*_t19*_t41 - _t145;
  const double _t147 = _hc2[1]*_t146 + (0.1e1 / 0.2e1)*_t138 + (0.1e1 / 0.2e1)*_t139;
  const double _t148 = _hc1[0]*_t147;
  const double _t149 = _hc4[1]*_t41;
  const double _t150 = _hc1[7]*_t149;
  const double _t153 = -_t150*_t152;
  const double _t154 = _t43*_t87;
  const double _t155 = _t43*_t88;
  const double _t156 = _hc1[1]*_t146 + _t153 + (0.1e1 / 0.2e1)*_t154 + (0.1e1 / 0.2e1)*_t155;
  const double _t157 = _hc2[0]*_t156;
  const double _t158 = (0.1e1 / 0.2e1)*_t136 + (0.1e1 / 0.2e1)*_t137 + _t148 + _t157;
  const double _t159 = _t1*_t158 + _t48;
  const double _t160 = (0.4e1 / 0.3e1)*_t140 + (0.1e1 / 0.6e1)*_t144;
  const double _t161 = _hc4[5]*_t10*_t19*_t41 - _t160;
  const double _t162 = _hc2[1]*_t161 + _t138 + _t139;
  const double _t163 = _hc1[0]*_t162;
  const double _t165 = -_t150*_t164;
  const double _t166 = _hc1[1]*_t161 + _t154 + _t155 + _t165;
  const double _t167 = _hc2[0]*_t166;
  const double _t168 = _t136 + _t137;
  const double _t169 = _t163 + _t167 + _t168;
  const double _t170 = _t35*_t46;
  const double _t171 = _t37*_t44;
  const double _t172 = _t101*_t43;
  const double _t173 = _t102*_t43;
  const double _t174 = (0.1e1 / 0.2e1)*_hc4[5]*_t10*_t33*_t41 - _t145;
  const double _t175 = _hc2[1]*_t174 + (0.1e1 / 0.2e1)*_t172 + (0.1e1 / 0.2e1)*_t173;
  const double _t176 = _hc1[0]*_t175;
  const double _t177 = _t113*_t43;
  const double _t178 = _t114*_t43;
  const double _t179 = _hc1[1]*_t174 + _t153 + (0.1e1 / 0.2e1)*_t177 + (0.1e1 / 0.2e1)*_t178;
  const double _t180 = _hc2[0]*_t179;
  const double _t181 = (0.1e1 / 0.2e1)*_t170 + (0.1e1 / 0.2e1)*_t171 + _t176 + _t180;
  const double _t182 = _t1*_t181 + _t48;
  const double _t183 = _hc4[5]*_t10*_t33*_t41 - _t160;
  const double _t184 = _hc2[1]*_t183 + _t172 + _t173;
  const double _t185 = _hc1[0]*_t184;
  const double _t186 = _hc1[1]*_t183 + _t165 + _t177 + _t178;
  const double _t187 = _hc2[0]*_t186;
  const double _t188 = _t170 + _t171;
  const double _t189 = _t185 + _t187 + _t188;
  const double _t192 = _hc4[1]*_t191;
  const double _t193 = _hc2[1]*_t192;
  const double _t194 = _hc1[0]*_t193;
  const double _t195 = _hc1[1]*_t192;
  const double _t196 = _hc2[0]*_t195;
  const double _t197 = ((_hc4[1]) * (_hc4[1]));
  const double _t198 = _t197/_t11;
  const double _t199 = _t141*_t198;
  const double _t200 = _hc2[3]*_t199;
  const double _t201 = _hc1[0]*_t200;
  const double _t202 = _hc1[1]*_hc2[1];
  const double _t203 = _t199*_t202;
  const double _t204 = _hc1[4]*_t199;
  const double _t205 = _hc2[0]*_t204;
  const double _t206 = -0.1e1 / 0.4e1*_t194 - 0.1e1 / 0.4e1*_t196 + (0.1e1 / 0.4e1)*_t201 + (0.1e1 / 0.2e1)*_t203 + (0.1e1 / 0.4e1)*_t205;
  const double _t207 = _t1*_t206;
  const double _t208 = -0.1e1 / 0.2e1*_t194 - 0.1e1 / 0.2e1*_t196 + (0.1e1 / 0.2e1)*_t201 + _t203 + (0.1e1 / 0.2e1)*_t205;
  const double _t209 = _t1*_t208;
  const double _t210 = -_t194 - _t196 + _t201 + 0.2e1*_t203 + _t205;
  const double d2F_dna2 = _t1*(_t56 + _t99) + 0.2e1*_t27 + 0.2e1*_t30 + 0.2e1*_t31 + _t53;
  const double d2F_dna_dnb = _t1*(_hc3[1]*_t60 + _t111 + _t119 + _t121 + _t122 + _t123 + _t125) + _t32 + _t40 + _t53;
  const double d2F_dnb2 = _t1*(_t125 + _t135) + 0.2e1*_t36 + 0.2e1*_t38 + 0.2e1*_t39 + _t53;
  const double d2F_dna_dgaa = _t159;
  const double d2F_dna_dgab = _t1*_t169 + _t50;
  const double d2F_dna_dgbb = _t159;
  const double d2F_dnb_dgaa = _t182;
  const double d2F_dnb_dgab = _t1*_t189 + _t50;
  const double d2F_dnb_dgbb = _t182;
  const double d2F_dgaa2 = _t207;
  const double d2F_dgaa_dgab = _t209;
  const double d2F_dgaa_dgbb = _t207;
  const double d2F_dgab2 = _t1*_t210;
  const double d2F_dgab_dgbb = _t209;
  const double d2F_dgbb2 = _t207;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 1] += d2F_dna_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 4] += d2F_dnb_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 1] += d2F_dgaa_dgab;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 2] += d2F_dgaa_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 3] += d2F_dgab2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 4] += d2F_dgab_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t211 = (0.2e1 / 0.3e1)*_t20;
  const double _t213 = _t10*_t5;
  const double _t214 = (0.14e2 / 0.27e2)*_t75;
  const double _t216 = (0.4e1 / 0.9e1)*_t20;
  const double _t217 = _t216*_t4;
  const double _t219 = 0.6e1*_t58;
  const double _t220 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t221 = _t220*_t7;
  const double _t222 = 0.6e1*_t221;
  const double _t223 = _t219 - _t222;
  const double _t224 = 0.2e1*_t61;
  const double _t244 = _t12*_t76;
  const double _t254 = (0.56e2 / 0.9e1)*_t75;
  const double _t260 = xc_powr(_t1, -13, 3);
  const double _t261 = (0.280e3 / 0.27e2)*_t260;
  const double _t268 = _t214*_t4;
  const double _t313 = -_t222 + 0.2e1*_t58;
  const double _t376 = 0.4e1*_t58;
  const double _t379 = _t376*_t7;
  const double _t409 = -_t219 - _t222;
  const double _t410 = 0.2e1*_t126;
  const double _t412 = _t12*_t254;
  const double _t437 = _t151*_t41;
  const double _t438 = (0.1e1 / 0.12e2)*_t437;
  const double _t441 = _t211*_t41;
  const double _t445 = (0.14e2 / 0.9e1)*_t75;
  const double _t446 = xc_powr(_t1, -11, 3);
  const double _t452 = _t4*_t446;
  const double _t478 = (0.4e1 / 0.3e1)*_t20;
  const double _t479 = (0.1e1 / 0.6e1)*_t437;
  const double _t482 = _t41*_t478;
  const double _t592 = (0.1e1 / 0.24e2)*_t151;
  const double _t603 = (0.1e1 / 0.24e2)*_t4;
  const double _t688 = xc_powr(_t11, -5, 2);
  const double _t693 = (0.1e1 / (_t11 * _t11));
  const double _t212 = _t211*_t51;
  const double _t215 = -_t214*_t51;
  const double _t218 = _t217*_t98;
  const double _t225 = 0.2e1*_t78;
  const double _t226 = _hc2[8]*_t25 + _hc2[9]*_t19;
  const double _t227 = _hc2[8]*_t19;
  const double _t228 = _hc2[7]*_t25;
  const double _t229 = _t227 + _t228;
  const double _t230 = _hc2[4]*_t78 + _hc2[5]*_t61 + _t19*_t226 + _t229*_t25;
  const double _t231 = _hc2[4]*_t61;
  const double _t232 = _hc2[7]*_t19;
  const double _t233 = _hc2[6]*_t25;
  const double _t234 = _t232 + _t233;
  const double _t235 = _hc2[3]*_t78;
  const double _t236 = _t19*_t229 + _t231 + _t234*_t25 + _t235;
  const double _t237 = _hc0[16]*_t15 + _hc4[12]*_t66;
  const double _t238 = _hc0[13]*_t19 - _t237;
  const double _t239 = -_hc4[15]*_t15;
  const double _t240 = _hc4[12]*_t19;
  const double _t241 = _t239 + _t240;
  const double _t242 = _hc0[18]*_t15 + _hc4[15]*_t66;
  const double _t243 = _hc0[16]*_t19 - _t242;
  const double _t245 = _hc0[8]*_t55 + _hc4[5]*_t244;
  const double _t246 = _hc0[6]*_t61 - _t15*_t243 + _t19*_t238 - _t241*_t66 + _t245;
  const double _t247 = _hc4[7]*_t55;
  const double _t248 = _hc4[5]*_t61;
  const double _t249 = -_hc4[17]*_t15;
  const double _t250 = _hc4[15]*_t19;
  const double _t251 = _t249 + _t250;
  const double _t252 = -_t15*_t251 + _t19*_t241 + _t247 + _t248;
  const double _t253 = _t12*_t71;
  const double _t255 = _hc0[19]*_t15 + _hc4[17]*_t66;
  const double _t256 = _hc0[18]*_t19 - _t255;
  const double _t257 = _hc0[9]*_t55 + _hc4[7]*_t244;
  const double _t258 = _hc0[8]*_t61 - _t15*_t256 + _t19*_t243 - _t251*_t66 + _t257;
  const double _t259 = _t4*_t73;
  const double _t262 = _t261*_t74;
  const double _t263 = _t214*_t23;
  const double _t264 = -_t262 - _t263;
  const double _t265 = _hc0[2]*_t223 - _t15*_t258 + _t19*_t246 + _t216*_t259 + _t224*_t68 - _t252*_t66 + _t253*_t254 + _t264;
  const double _t266 = _hc2[1]*_t265 + _hc2[2]*_t223 + _t19*_t230 + _t224*_t62 + _t225*_t65 + _t236*_t25;
  const double _t267 = _hc1[0]*_t266;
  const double _t269 = -_hc1[3]*_t268;
  const double _t270 = _hc1[9]*_t55;
  const double _t271 = -_hc1[19]*_t15;
  const double _t272 = _hc1[17]*_t25 + _hc1[18]*_t19 + _t271;
  const double _t273 = -_hc1[18]*_t15;
  const double _t274 = _hc1[15]*_t25 + _hc1[16]*_t19 + _t273;
  const double _t275 = -_hc1[17]*_t15;
  const double _t276 = _hc1[15]*_t19;
  const double _t277 = _hc1[14]*_t25;
  const double _t278 = _t275 + _t276 + _t277;
  const double _t279 = _hc1[7]*_t78 + _hc1[8]*_t61 - _t15*_t272 + _t19*_t274 + _t25*_t278 + _t270;
  const double _t280 = _hc1[8]*_t55;
  const double _t281 = -_hc1[16]*_t15;
  const double _t282 = _hc1[12]*_t25 + _hc1[13]*_t19 + _t281;
  const double _t283 = -_hc1[15]*_t15;
  const double _t284 = _hc1[12]*_t19;
  const double _t285 = _hc1[11]*_t25;
  const double _t286 = _t283 + _t284 + _t285;
  const double _t287 = _hc1[5]*_t78 + _hc1[6]*_t61 - _t15*_t274 + _t19*_t282 + _t25*_t286 + _t280;
  const double _t288 = _hc1[7]*_t55;
  const double _t289 = _hc1[5]*_t61;
  const double _t290 = -_hc1[14]*_t15;
  const double _t291 = _hc1[11]*_t19;
  const double _t292 = _hc1[10]*_t25;
  const double _t293 = _t290 + _t291 + _t292;
  const double _t294 = _hc1[4]*_t78;
  const double _t295 = -_t15*_t278 + _t19*_t286 + _t25*_t293 + _t288 + _t289 + _t294;
  const double _t296 = _hc1[1]*_t265 + _hc1[2]*_t223 - _t15*_t279 + _t19*_t287 + _t217*_t83 + _t224*_t85 + _t225*_t89 + _t25*_t295 + _t269;
  const double _t297 = _hc2[0]*_t296;
  const double _t298 = _hc3[1]*_t223;
  const double _t299 = _hc3[4]*_t55;
  const double _t300 = -_hc3[8]*_t15;
  const double _t301 = _hc3[7]*_t19 + _t300;
  const double _t302 = -_hc3[7]*_t15;
  const double _t303 = _hc3[6]*_t19 + _t302;
  const double _t304 = _hc3[3]*_t61 - _t15*_t301 + _t19*_t303 + _t299;
  const double _t305 = _t19*_t304;
  const double _t306 = _t26*_t90;
  const double _t307 = _t29*_t79;
  const double _t308 = _hc3[5]*_t55;
  const double _t309 = -_hc3[9]*_t15;
  const double _t310 = _hc3[8]*_t19 + _t309;
  const double _t311 = _hc3[4]*_t61 - _t15*_t310 + _t19*_t301 + _t308;
  const double _t312 = -_t15*_t311 + _t224*_t94 + _t267 + _t297 + _t298 + _t305 + 0.3e1*_t306 + 0.3e1*_t307;
  const double _t314 = _hc3[1]*_t313;
  const double _t315 = _t120*_t61;
  const double _t316 = _hc3[7]*_t33 + _t300;
  const double _t317 = _hc3[8]*_t33 + _t309;
  const double _t318 = -_t15*_t317 + _t308;
  const double _t319 = _hc3[4]*_t60 + _t19*_t316 + _t318;
  const double _t320 = _hc3[6]*_t33 + _t302;
  const double _t321 = -_t15*_t316 + _t299;
  const double _t322 = _hc3[3]*_t60 + _t19*_t320 + _t321;
  const double _t323 = _t19*_t322;
  const double _t324 = 0.2e1*_t110;
  const double _t325 = _t37*_t79;
  const double _t326 = 0.2e1*_t26;
  const double _t327 = _t35*_t90;
  const double _t328 = _hc2[8]*_t34 + _hc2[9]*_t33;
  const double _t329 = _hc2[8]*_t33;
  const double _t330 = _hc2[7]*_t34;
  const double _t331 = _t329 + _t330;
  const double _t332 = _hc2[4]*_t109 + _hc2[5]*_t60 + _t19*_t328 + _t25*_t331;
  const double _t333 = _hc2[7]*_t33;
  const double _t334 = _hc2[6]*_t34;
  const double _t335 = _t333 + _t334;
  const double _t336 = _hc2[3]*_t109;
  const double _t337 = _hc2[4]*_t60 + _t19*_t331 + _t25*_t335 + _t336;
  const double _t338 = _hc0[13]*_t33 - _t237;
  const double _t339 = _hc4[12]*_t33;
  const double _t340 = _t239 + _t339;
  const double _t341 = _hc0[16]*_t33 - _t242;
  const double _t342 = -_t15*_t341 + _t245 - _t340*_t66;
  const double _t343 = _hc0[6]*_t60 + _t19*_t338 + _t342;
  const double _t344 = _hc4[15]*_t33;
  const double _t345 = _t249 + _t344;
  const double _t346 = -_t15*_t345 + _t247;
  const double _t347 = _hc4[5]*_t60 + _t19*_t340 + _t346;
  const double _t348 = _hc0[18]*_t33 - _t255;
  const double _t349 = -_t15*_t348 + _t257 - _t345*_t66;
  const double _t350 = _hc0[8]*_t60 + _t19*_t341 + _t349;
  const double _t351 = _hc0[2]*_t313 + _t104*_t61 + _t106*_t244 + _t107*_t55 - _t15*_t350 + _t19*_t343 + _t244*_t71 + _t264 - _t347*_t66 + _t55*_t73 + _t60*_t68;
  const double _t352 = _hc2[1]*_t351 + _hc2[2]*_t313 + _t100*_t61 + _t103*_t78 + _t109*_t65 + _t19*_t332 + _t25*_t337 + _t60*_t62;
  const double _t353 = _hc1[0]*_t352;
  const double _t354 = _hc1[15]*_t34 + _hc1[16]*_t33 + _t273;
  const double _t355 = _hc1[15]*_t33;
  const double _t356 = _hc1[14]*_t34;
  const double _t357 = _t275 + _t355 + _t356;
  const double _t358 = _hc1[17]*_t34 + _hc1[18]*_t33 + _t271;
  const double _t359 = -_t15*_t358 + _t270;
  const double _t360 = _hc1[7]*_t109 + _hc1[8]*_t60 + _t19*_t354 + _t25*_t357 + _t359;
  const double _t361 = _hc1[12]*_t34 + _hc1[13]*_t33 + _t281;
  const double _t362 = _hc1[12]*_t33;
  const double _t363 = _hc1[11]*_t34;
  const double _t364 = _t283 + _t362 + _t363;
  const double _t365 = -_t15*_t354 + _t280;
  const double _t366 = _hc1[5]*_t109 + _hc1[6]*_t60 + _t19*_t361 + _t25*_t364 + _t365;
  const double _t367 = _hc1[4]*_t109;
  const double _t368 = _hc1[11]*_t33;
  const double _t369 = _hc1[10]*_t34;
  const double _t370 = _t290 + _t368 + _t369;
  const double _t371 = -_t15*_t357 + _t288;
  const double _t372 = _hc1[5]*_t60 + _t19*_t364 + _t25*_t370 + _t367 + _t371;
  const double _t373 = _hc1[1]*_t351 + _hc1[2]*_t313 + _t109*_t89 + _t112*_t61 + _t115*_t78 + _t116*_t55 - _t15*_t360 + _t19*_t366 + _t25*_t372 + _t269 + _t55*_t83 + _t60*_t85;
  const double _t374 = _hc2[0]*_t373;
  const double _t375 = _t124*_t4;
  const double _t377 = _hc3[1]*_t376;
  const double _t378 = 0.2e1*_t111 + 0.2e1*_t119 + 0.2e1*_t121 + 0.2e1*_t122 + 0.2e1*_t123 + _t377*_t7;
  const double _t380 = 0.2e1*_t109;
  const double _t381 = _hc2[4]*_t127 + _hc2[5]*_t126 + _t328*_t33 + _t331*_t34;
  const double _t382 = _hc2[4]*_t126;
  const double _t383 = _hc2[3]*_t127;
  const double _t384 = _t33*_t331 + _t335*_t34 + _t382 + _t383;
  const double _t385 = _hc4[5]*_t126;
  const double _t386 = _t33*_t340 + _t346 + _t385;
  const double _t387 = _t386*_t66;
  const double _t388 = _hc0[8]*_t126 + _t33*_t341 + _t349;
  const double _t389 = _t15*_t388;
  const double _t390 = _hc0[6]*_t126 + _t33*_t338 + _t342;
  const double _t391 = -_hc0[2]*_t222 - _hc0[2]*_t59 + 0.4e1*_t104*_t58*_t7 + (0.56e2 / 0.9e1)*_t106*_t12*_t75 + (0.4e1 / 0.9e1)*_t107*_t2*_t20*_t3 + _t19*_t390 - _t262 - _t263 - _t387 - _t389;
  const double _t392 = _hc2[1]*_t391 - _hc2[2]*_t222 - _hc2[2]*_t59 + _t100*_t379 + _t103*_t380 + _t19*_t381 + _t25*_t384;
  const double _t393 = _hc1[0]*_t392;
  const double _t394 = _hc1[5]*_t127 + _hc1[6]*_t126 + _t33*_t361 + _t34*_t364 + _t365;
  const double _t395 = _hc1[4]*_t127;
  const double _t396 = _hc1[5]*_t126;
  const double _t397 = _t33*_t364 + _t34*_t370 + _t371 + _t395 + _t396;
  const double _t398 = _hc1[7]*_t127 + _hc1[8]*_t126 + _t33*_t354 + _t34*_t357 + _t359;
  const double _t399 = _t116*_t217 - _t15*_t398 + _t269;
  const double _t400 = _hc1[1]*_t391 - _hc1[2]*_t222 - _hc1[2]*_t59 + _t112*_t379 + _t115*_t380 + _t19*_t394 + _t25*_t397 + _t399;
  const double _t401 = _hc2[0]*_t400;
  const double _t402 = _hc3[3]*_t126 + _t320*_t33 + _t321;
  const double _t403 = _t19*_t402;
  const double _t404 = _t130*_t26;
  const double _t405 = _t128*_t29;
  const double _t406 = _hc3[4]*_t126 + _t316*_t33 + _t318;
  const double _t407 = _t124*_t217 - _t15*_t406 + _t215;
  const double _t408 = -_t124*_t213 + _t212;
  const double _t411 = 0.2e1*_t127;
  const double _t413 = _hc0[2]*_t409 + _t104*_t410 + _t106*_t412 + _t107*_t217 + _t264 + _t33*_t390 - _t387 - _t389;
  const double _t414 = _hc2[1]*_t413 + _hc2[2]*_t409 + _t100*_t410 + _t103*_t411 + _t33*_t381 + _t34*_t384;
  const double _t415 = _hc1[0]*_t414;
  const double _t416 = _hc1[1]*_t413 + _hc1[2]*_t409 + _t112*_t410 + _t115*_t411 + _t33*_t394 + _t34*_t397 + _t399;
  const double _t417 = _hc2[0]*_t416;
  const double _t418 = _hc3[1]*_t409;
  const double _t419 = _t33*_t402;
  const double _t420 = 0.3e1*_t35;
  const double _t421 = 0.3e1*_t37;
  const double _t422 = _t120*_t410 + _t128*_t421 + _t130*_t420 + _t415 + _t417 + _t418 + _t419;
  const double _t423 = 0.6e1*_t35;
  const double _t424 = 0.2e1*_t29;
  const double _t425 = _t46*_t79;
  const double _t426 = _t44*_t90;
  const double _t427 = _t231*_t43;
  const double _t428 = _t227*_t43;
  const double _t429 = _t228*_t43;
  const double _t430 = _hc2[4]*_t146 + (0.1e1 / 0.2e1)*_t428 + (0.1e1 / 0.2e1)*_t429;
  const double _t431 = _t232*_t43;
  const double _t432 = _t233*_t43;
  const double _t433 = _hc2[3]*_t146;
  const double _t434 = (0.1e1 / 0.2e1)*_t431 + (0.1e1 / 0.2e1)*_t432 + _t433;
  const double _t435 = _t235*_t43;
  const double _t436 = _hc4[5]*_t41;
  const double _t439 = _hc4[15]*_t438 + _t211*_t436;
  const double _t440 = (0.1e1 / 0.2e1)*_hc4[12]*_t10*_t19*_t41 - _t439;
  const double _t442 = _t248*_t42;
  const double _t443 = _hc4[17]*_t438 + _hc4[7]*_t441;
  const double _t444 = (0.1e1 / 0.2e1)*_hc4[15]*_t10*_t19*_t41 - _t443;
  const double _t447 = _t143*_t446;
  const double _t448 = _t149*_t445 + (0.1e1 / 0.9e1)*_t447;
  const double _t449 = -_t15*_t444 + _t19*_t440 - _t441*_t71 + (0.1e1 / 0.2e1)*_t442 + _t448;
  const double _t450 = _hc2[1]*_t449 + _t146*_t65 + _t19*_t430 + _t25*_t434 + (0.1e1 / 0.2e1)*_t427 + (0.1e1 / 0.2e1)*_t435;
  const double _t451 = _hc1[0]*_t450;
  const double _t453 = _t150*_t452;
  const double _t454 = (0.1e1 / 0.9e1)*_t453;
  const double _t455 = _t289*_t43;
  const double _t456 = _t149*_t152;
  const double _t457 = -_hc1[17]*_t456;
  const double _t458 = _t276*_t43;
  const double _t459 = _t277*_t43;
  const double _t460 = _hc1[7]*_t146 + _t457 + (0.1e1 / 0.2e1)*_t458 + (0.1e1 / 0.2e1)*_t459;
  const double _t461 = -_hc1[15]*_t456;
  const double _t462 = _t284*_t43;
  const double _t463 = _t285*_t43;
  const double _t464 = _hc1[5]*_t146 + _t461 + (0.1e1 / 0.2e1)*_t462 + (0.1e1 / 0.2e1)*_t463;
  const double _t465 = -_hc1[14]*_t456;
  const double _t466 = _t291*_t43;
  const double _t467 = _t292*_t43;
  const double _t468 = _hc1[4]*_t146;
  const double _t469 = _t465 + (0.1e1 / 0.2e1)*_t466 + (0.1e1 / 0.2e1)*_t467 + _t468;
  const double _t470 = _t294*_t43;
  const double _t471 = _hc1[1]*_t449 + _t146*_t89 - _t15*_t460 + _t19*_t464 + _t25*_t469 + _t454 + (0.1e1 / 0.2e1)*_t455 + (0.1e1 / 0.2e1)*_t470;
  const double _t472 = _hc2[0]*_t471;
  const double _t473 = _t147*_t424 + _t156*_t326 + (0.1e1 / 0.2e1)*_t425 + (0.1e1 / 0.2e1)*_t426 + _t451 + _t472;
  const double _t474 = _t1*_t473 + 0.2e1*_t148 + 0.2e1*_t157 + _t168;
  const double _t475 = _hc2[4]*_t161 + _t428 + _t429;
  const double _t476 = _hc2[3]*_t161;
  const double _t477 = _t431 + _t432 + _t476;
  const double _t480 = _hc4[15]*_t479 + _t436*_t478;
  const double _t481 = _hc4[12]*_t10*_t19*_t41 - _t480;
  const double _t483 = _hc4[17]*_t479 + _hc4[7]*_t482;
  const double _t484 = _hc4[15]*_t10*_t19*_t41 - _t483;
  const double _t485 = _t149*_t76 + (0.2e1 / 0.9e1)*_t447;
  const double _t486 = -_t15*_t484 + _t19*_t481 + _t442 - _t482*_t71 + _t485;
  const double _t487 = _hc2[1]*_t486 + _t161*_t65 + _t19*_t475 + _t25*_t477 + _t427 + _t435;
  const double _t488 = _hc1[0]*_t487;
  const double _t489 = (0.2e1 / 0.9e1)*_t453;
  const double _t490 = _t149*_t164;
  const double _t491 = -_hc1[17]*_t490;
  const double _t492 = _hc1[7]*_t161 + _t458 + _t459 + _t491;
  const double _t493 = -_hc1[15]*_t490;
  const double _t494 = _hc1[5]*_t161 + _t462 + _t463 + _t493;
  const double _t495 = -_hc1[14]*_t490;
  const double _t496 = _hc1[4]*_t161;
  const double _t497 = _t466 + _t467 + _t495 + _t496;
  const double _t498 = _hc1[1]*_t486 - _t15*_t492 + _t161*_t89 + _t19*_t494 + _t25*_t497 + _t455 + _t470 + _t489;
  const double _t499 = _hc2[0]*_t498;
  const double _t500 = _t162*_t424 + _t166*_t326 + _t425 + _t426 + _t488 + _t499;
  const double _t501 = _t147*_t37;
  const double _t502 = _t175*_t29;
  const double _t503 = _t156*_t35;
  const double _t504 = _t179*_t26;
  const double _t505 = _t110*_t46;
  const double _t506 = _t118*_t44;
  const double _t507 = _t149*_t260;
  const double _t508 = _hc2[4]*_t507;
  const double _t509 = _t508*_t7;
  const double _t510 = _t329*_t43;
  const double _t511 = _t330*_t43;
  const double _t512 = _hc2[4]*_t174 + (0.1e1 / 0.2e1)*_t510 + (0.1e1 / 0.2e1)*_t511;
  const double _t513 = _t333*_t43;
  const double _t514 = _t334*_t43;
  const double _t515 = _hc2[3]*_t174;
  const double _t516 = (0.1e1 / 0.2e1)*_t513 + (0.1e1 / 0.2e1)*_t514 + _t515;
  const double _t517 = _t336*_t43;
  const double _t518 = (0.1e1 / 0.2e1)*_hc4[12]*_t10*_t33*_t41 - _t439;
  const double _t519 = _t260*_t436;
  const double _t520 = _t519*_t7;
  const double _t521 = (0.1e1 / 0.2e1)*_hc4[15]*_t10*_t33*_t41 - _t443;
  const double _t522 = -_t106*_t441 - _t15*_t521 + _t448;
  const double _t523 = _t19*_t518 + _t520 + _t522;
  const double _t524 = _hc2[1]*_t523 + _t103*_t146 + _t19*_t512 + _t25*_t516 + _t509 + (0.1e1 / 0.2e1)*_t517;
  const double _t525 = _hc1[0]*_t524;
  const double _t526 = _t362*_t43;
  const double _t527 = _t363*_t43;
  const double _t528 = _hc1[5]*_t174 + _t461 + (0.1e1 / 0.2e1)*_t526 + (0.1e1 / 0.2e1)*_t527;
  const double _t529 = _t368*_t43;
  const double _t530 = _t369*_t43;
  const double _t531 = _hc1[4]*_t174;
  const double _t532 = _t465 + (0.1e1 / 0.2e1)*_t529 + (0.1e1 / 0.2e1)*_t530 + _t531;
  const double _t533 = _hc1[5]*_t507;
  const double _t534 = _t533*_t7;
  const double _t535 = _t367*_t43;
  const double _t536 = _t355*_t43;
  const double _t537 = _t356*_t43;
  const double _t538 = _hc1[7]*_t174 + _t457 + (0.1e1 / 0.2e1)*_t536 + (0.1e1 / 0.2e1)*_t537;
  const double _t539 = -_t15*_t538 + _t454;
  const double _t540 = _hc1[1]*_t523 + _t115*_t146 + _t19*_t528 + _t25*_t532 + _t534 + (0.1e1 / 0.2e1)*_t535 + _t539;
  const double _t541 = _hc2[0]*_t540;
  const double _t542 = _t1*(_t501 + _t502 + _t503 + _t504 + (0.1e1 / 0.2e1)*_t505 + (0.1e1 / 0.2e1)*_t506 + _t525 + _t541) + _t158 + _t181;
  const double _t543 = _hc2[4]*_t183 + _t510 + _t511;
  const double _t544 = _hc2[3]*_t183;
  const double _t545 = _t513 + _t514 + _t544;
  const double _t546 = _hc4[12]*_t10*_t33*_t41 - _t480;
  const double _t547 = _hc4[15]*_t10*_t33*_t41 - _t483;
  const double _t548 = -_t106*_t482 - _t15*_t547 + _t485;
  const double _t549 = _t19*_t546 + 0.2e1*_t520 + _t548;
  const double _t550 = _hc2[1]*_t549 + _t103*_t161 + _t19*_t543 + _t25*_t545 + 0.2e1*_t509 + _t517;
  const double _t551 = _hc1[0]*_t550;
  const double _t552 = _hc1[5]*_t183 + _t493 + _t526 + _t527;
  const double _t553 = _hc1[4]*_t183;
  const double _t554 = _t495 + _t529 + _t530 + _t553;
  const double _t555 = _hc1[7]*_t183 + _t491 + _t536 + _t537;
  const double _t556 = -_t15*_t555 + _t489;
  const double _t557 = _hc1[1]*_t549 + _t115*_t161 + _t19*_t552 + _t25*_t554 + 0.2e1*_t534 + _t535 + _t556;
  const double _t558 = _hc2[0]*_t557;
  const double _t559 = _t186*_t26;
  const double _t560 = _t166*_t35;
  const double _t561 = _t184*_t29;
  const double _t562 = _t162*_t37;
  const double _t563 = _t505 + _t506;
  const double _t564 = 0.2e1*_t37;
  const double _t565 = _t128*_t46;
  const double _t566 = _t130*_t44;
  const double _t567 = _t382*_t43;
  const double _t568 = _t383*_t43;
  const double _t569 = _t385*_t42;
  const double _t570 = _t33*_t518 + _t522 + (0.1e1 / 0.2e1)*_t569;
  const double _t571 = _hc2[1]*_t570 + _t103*_t174 + _t33*_t512 + _t34*_t516 + (0.1e1 / 0.2e1)*_t567 + (0.1e1 / 0.2e1)*_t568;
  const double _t572 = _hc1[0]*_t571;
  const double _t573 = _t395*_t43;
  const double _t574 = _t396*_t43;
  const double _t575 = _hc1[1]*_t570 + _t115*_t174 + _t33*_t528 + _t34*_t532 + _t539 + (0.1e1 / 0.2e1)*_t573 + (0.1e1 / 0.2e1)*_t574;
  const double _t576 = _hc2[0]*_t575;
  const double _t577 = _t134*_t179 + _t175*_t564 + (0.1e1 / 0.2e1)*_t565 + (0.1e1 / 0.2e1)*_t566 + _t572 + _t576;
  const double _t578 = _t1*_t577 + 0.2e1*_t176 + 0.2e1*_t180 + _t188;
  const double _t579 = _t33*_t546 + _t548 + _t569;
  const double _t580 = _hc2[1]*_t579 + _t103*_t183 + _t33*_t543 + _t34*_t545 + _t567 + _t568;
  const double _t581 = _hc1[0]*_t580;
  const double _t582 = _hc1[1]*_t579 + _t115*_t183 + _t33*_t552 + _t34*_t554 + _t556 + _t573 + _t574;
  const double _t583 = _hc2[0]*_t582;
  const double _t584 = _t134*_t186 + _t184*_t564 + _t565 + _t566 + _t581 + _t583;
  const double _t585 = _t192*_t63;
  const double _t586 = _t199*_t232;
  const double _t587 = _t192*_t64;
  const double _t588 = _t199*_t233;
  const double _t589 = _t191*_t70;
  const double _t590 = _t190*_t21;
  const double _t591 = _hc4[7]*_t190;
  const double _t593 = (0.1e1 / 0.3e1)*_t590 + _t591*_t592;
  const double _t594 = -0.1e1 / 0.4e1*_t589 + _t593;
  const double _t595 = _t43*_t433;
  const double _t596 = _hc2[1]*_t594 - 0.1e1 / 0.4e1*_t585 + (0.1e1 / 0.4e1)*_t586 - 0.1e1 / 0.4e1*_t587 + (0.1e1 / 0.4e1)*_t588 + _t595;
  const double _t597 = _hc1[0]*_t596;
  const double _t598 = _t43*_t468;
  const double _t599 = _t192*_t88;
  const double _t600 = _t192*_t87;
  const double _t601 = _t199*_t292;
  const double _t602 = _t199*_t291;
  const double _t604 = _hc1[14]*_t220;
  const double _t605 = _t198*_t604;
  const double _t606 = _hc4[1]*_t190;
  const double _t607 = _hc1[7]*_t606;
  const double _t608 = _t592*_t607 - _t603*_t605;
  const double _t609 = _hc1[1]*_t594 + _t598 - 0.1e1 / 0.4e1*_t599 - 0.1e1 / 0.4e1*_t600 + (0.1e1 / 0.4e1)*_t601 + (0.1e1 / 0.4e1)*_t602 + _t608;
  const double _t610 = _hc2[0]*_t609;
  const double _t611 = _t195*_t26;
  const double _t612 = _t193*_t29;
  const double _t613 = _t204*_t26;
  const double _t614 = _t200*_t29;
  const double _t615 = _t147*_t46 + _t156*_t44;
  const double _t616 = _t597 + _t610 - 0.1e1 / 0.4e1*_t611 - 0.1e1 / 0.4e1*_t612 + (0.1e1 / 0.4e1)*_t613 + (0.1e1 / 0.4e1)*_t614 + _t615;
  const double _t617 = _t1*_t616 + _t206;
  const double _t618 = _t151*_t591;
  const double _t619 = (0.2e1 / 0.3e1)*_t590 + (0.1e1 / 0.12e2)*_t618;
  const double _t620 = -0.1e1 / 0.2e1*_t589 + _t619;
  const double _t621 = (0.1e1 / 0.2e1)*_t43;
  const double _t622 = _hc2[1]*_t620 + _t476*_t621 - 0.1e1 / 0.2e1*_t585 + (0.1e1 / 0.2e1)*_t586 - 0.1e1 / 0.2e1*_t587 + (0.1e1 / 0.2e1)*_t588 + _t595;
  const double _t623 = _hc1[0]*_t622;
  const double _t624 = _t4*_t605;
  const double _t625 = _t152*_t607 - 0.1e1 / 0.12e2*_t624;
  const double _t626 = _hc1[1]*_t620 + _t496*_t621 + _t598 - 0.1e1 / 0.2e1*_t599 - 0.1e1 / 0.2e1*_t600 + (0.1e1 / 0.2e1)*_t601 + (0.1e1 / 0.2e1)*_t602 + _t625;
  const double _t627 = _hc2[0]*_t626;
  const double _t628 = _t162*_t46;
  const double _t629 = _t166*_t44;
  const double _t630 = -0.1e1 / 0.2e1*_t611 - 0.1e1 / 0.2e1*_t612 + (0.1e1 / 0.2e1)*_t613 + (0.1e1 / 0.2e1)*_t614;
  const double _t631 = _t615 + _t623 + _t627 + (0.1e1 / 0.2e1)*_t628 + (0.1e1 / 0.2e1)*_t629 + _t630;
  const double _t632 = _t1*_t631 + _t208;
  const double _t633 = (0.4e1 / 0.3e1)*_t590 + (0.1e1 / 0.6e1)*_t618;
  const double _t634 = -_t589 + _t633;
  const double _t635 = 0.2e1*_t43;
  const double _t636 = _hc2[1]*_t634 + _t476*_t635 - _t585 + _t586 - _t587 + _t588;
  const double _t637 = _hc1[0]*_t636;
  const double _t638 = _t164*_t607 - 0.1e1 / 0.6e1*_t624;
  const double _t639 = _hc1[1]*_t634 + _t496*_t635 - _t599 - _t600 + _t601 + _t602 + _t638;
  const double _t640 = _hc2[0]*_t639;
  const double _t641 = -_t611 - _t612 + _t613 + _t614;
  const double _t642 = 0.2e1*_t628 + 0.2e1*_t629 + _t637 + _t640 + _t641;
  const double _t643 = _t101*_t192;
  const double _t644 = _t199*_t333;
  const double _t645 = _t102*_t192;
  const double _t646 = _t199*_t334;
  const double _t647 = _t105*_t191;
  const double _t648 = _t593 - 0.1e1 / 0.4e1*_t647;
  const double _t649 = _t43*_t515;
  const double _t650 = _hc2[1]*_t648 - 0.1e1 / 0.4e1*_t643 + (0.1e1 / 0.4e1)*_t644 - 0.1e1 / 0.4e1*_t645 + (0.1e1 / 0.4e1)*_t646 + _t649;
  const double _t651 = _hc1[0]*_t650;
  const double _t652 = _t43*_t531;
  const double _t653 = _t114*_t192;
  const double _t654 = _t113*_t192;
  const double _t655 = _t199*_t369;
  const double _t656 = _t199*_t368;
  const double _t657 = _hc1[1]*_t648 + _t608 + _t652 - 0.1e1 / 0.4e1*_t653 - 0.1e1 / 0.4e1*_t654 + (0.1e1 / 0.4e1)*_t655 + (0.1e1 / 0.4e1)*_t656;
  const double _t658 = _hc2[0]*_t657;
  const double _t659 = _t195*_t35;
  const double _t660 = _t193*_t37;
  const double _t661 = _t204*_t35;
  const double _t662 = _t200*_t37;
  const double _t663 = _t175*_t46;
  const double _t664 = _t179*_t44;
  const double _t665 = _t663 + _t664;
  const double _t666 = _t651 + _t658 - 0.1e1 / 0.4e1*_t659 - 0.1e1 / 0.4e1*_t660 + (0.1e1 / 0.4e1)*_t661 + (0.1e1 / 0.4e1)*_t662 + _t665;
  const double _t667 = _t1*_t666 + _t206;
  const double _t668 = _t619 - 0.1e1 / 0.2e1*_t647;
  const double _t669 = _hc2[1]*_t668 + _t544*_t621 - 0.1e1 / 0.2e1*_t643 + (0.1e1 / 0.2e1)*_t644 - 0.1e1 / 0.2e1*_t645 + (0.1e1 / 0.2e1)*_t646 + _t649;
  const double _t670 = _hc1[0]*_t669;
  const double _t671 = _hc1[1]*_t668 + _t553*_t621 + _t625 + _t652 - 0.1e1 / 0.2e1*_t653 - 0.1e1 / 0.2e1*_t654 + (0.1e1 / 0.2e1)*_t655 + (0.1e1 / 0.2e1)*_t656;
  const double _t672 = _hc2[0]*_t671;
  const double _t673 = _t184*_t46;
  const double _t674 = _t186*_t44;
  const double _t675 = -0.1e1 / 0.2e1*_t659 - 0.1e1 / 0.2e1*_t660 + (0.1e1 / 0.2e1)*_t661 + (0.1e1 / 0.2e1)*_t662;
  const double _t676 = _t665 + _t670 + _t672 + (0.1e1 / 0.2e1)*_t673 + (0.1e1 / 0.2e1)*_t674 + _t675;
  const double _t677 = _t1*_t676 + _t208;
  const double _t678 = _t633 - _t647;
  const double _t679 = _hc2[1]*_t678 + _t544*_t635 - _t643 + _t644 - _t645 + _t646;
  const double _t680 = _hc1[0]*_t679;
  const double _t681 = _hc1[1]*_t678 + _t553*_t635 + _t638 - _t653 - _t654 + _t655 + _t656;
  const double _t682 = _hc2[0]*_t681;
  const double _t683 = 0.2e1*_t184;
  const double _t684 = 0.2e1*_t186;
  const double _t685 = -_t659 - _t660 + _t661 + _t662;
  const double _t686 = _t44*_t684 + _t46*_t683 + _t680 + _t682 + _t685;
  const double _t687 = (0.3e1 / 0.8e1)*_hc2[1];
  const double _t689 = _hc4[1]*_t10*_t688;
  const double _t690 = _hc1[0]*_t689;
  const double _t691 = (0.3e1 / 0.8e1)*_hc1[1];
  const double _t692 = _hc2[0]*_t689;
  const double _t694 = _t141*_t197;
  const double _t695 = _t693*_t694;
  const double _t696 = (0.3e1 / 0.8e1)*_t695;
  const double _t697 = _hc1[0]*_hc2[3];
  const double _t698 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]));
  const double _t699 = _t220*_t698;
  const double _t700 = _t190*_t699;
  const double _t701 = _hc2[6]*_t700;
  const double _t702 = _hc1[0]*_t701;
  const double _t703 = _t202*_t695;
  const double _t704 = _hc2[3]*_t700;
  const double _t705 = _hc1[10]*_t700;
  const double _t706 = _hc2[0]*_t705;
  const double _t707 = _hc1[4]*_hc2[0];
  const double _t708 = _hc1[4]*_t700;
  const double _t709 = _t687*_t690 + _t687*_t708 + _t691*_t692 + _t691*_t704 - _t696*_t697 - _t696*_t707 + (0.1e1 / 0.8e1)*_t702 - 0.3e1 / 0.4e1*_t703 + (0.1e1 / 0.8e1)*_t706;
  const double _t710 = _t1*_t709;
  const double _t711 = (0.3e1 / 0.4e1)*_hc2[1];
  const double _t712 = (0.3e1 / 0.4e1)*_hc1[1];
  const double _t713 = (0.3e1 / 0.4e1)*_t695;
  const double _t714 = _t690*_t711 + _t692*_t712 - _t697*_t713 + (0.1e1 / 0.4e1)*_t702 - 0.3e1 / 0.2e1*_t703 + _t704*_t712 + (0.1e1 / 0.4e1)*_t706 - _t707*_t713 + _t708*_t711;
  const double _t715 = _t1*_t714;
  const double _t716 = (0.3e1 / 0.2e1)*_hc2[1];
  const double _t717 = (0.3e1 / 0.2e1)*_hc1[1];
  const double _t718 = (0.3e1 / 0.2e1)*_t695;
  const double _t719 = _t690*_t716 + _t692*_t717 - _t697*_t718 + (0.1e1 / 0.2e1)*_t702 - 0.3e1*_t703 + _t704*_t717 + (0.1e1 / 0.2e1)*_t706 - _t707*_t718 + _t708*_t716;
  const double _t720 = _t1*_t719;
  const double _t721 = 0.3e1*_hc2[1];
  const double _t722 = 0.3e1*_hc1[1];
  const double _t723 = 0.3e1*_t695;
  const double _t724 = _t690*_t721 + _t692*_t722 - _t697*_t723 + _t702 - 0.6e1*_t703 + _t704*_t722 + _t706 - _t707*_t723 + _t708*_t721;
  const double d3F_dna3 = _t1*(_t215 + _t218 + _t312) + _t212 - _t213*_t98 + 0.3e1*_t80 + 0.3e1*_t91 + 0.3e1*_t92 + 0.3e1*_t95 + 0.6e1*_t96;
  const double d3F_dna2_dnb = _t1*(_t118*_t326 + _t124*_t55 - _t15*_t319 + _t215 + _t29*_t324 + _t314 + _t315 + _t323 + _t325 + _t327 + _t353 + _t374 + _t55*_t98 + _t60*_t94) + _t212 - _t375*_t52 + _t378 + _t99;
  const double d3F_dna_dnb2 = _t1*(-_hc3[1]*_t222 - _hc3[1]*_t59 + _t118*_t134 + _t120*_t379 + _t324*_t37 + _t393 + _t401 + _t403 + _t404 + _t405 + _t407) + _t135 + _t378 + _t408;
  const double d3F_dnb3 = _t1*(_t407 + _t422) + 0.3e1*_t129 + 0.3e1*_t131 + 0.3e1*_t132 + 0.3e1*_t133 + _t37*_t423 + _t408;
  const double d3F_dna2_dgaa = _t474;
  const double d3F_dna2_dgab = _t1*_t500 + 0.2e1*_t163 + 0.2e1*_t167 + _t326*_t46 + _t424*_t44;
  const double d3F_dna2_dgbb = _t474;
  const double d3F_dna_dnb_dgaa = _t542;
  const double d3F_dna_dnb_dgab = _t1*(_t551 + _t558 + _t559 + _t560 + _t561 + _t562 + _t563) + _t169 + _t189;
  const double d3F_dna_dnb_dgbb = _t542;
  const double d3F_dnb2_dgaa = _t578;
  const double d3F_dnb2_dgab = _t1*_t584 + _t134*_t46 + 0.2e1*_t185 + 0.2e1*_t187 + _t44*_t564;
  const double d3F_dnb2_dgbb = _t578;
  const double d3F_dna_dgaa2 = _t617;
  const double d3F_dna_dgaa_dgab = _t632;
  const double d3F_dna_dgaa_dgbb = _t617;
  const double d3F_dna_dgab2 = _t1*_t642 + _t210;
  const double d3F_dna_dgab_dgbb = _t632;
  const double d3F_dna_dgbb2 = _t617;
  const double d3F_dnb_dgaa2 = _t667;
  const double d3F_dnb_dgaa_dgab = _t677;
  const double d3F_dnb_dgaa_dgbb = _t667;
  const double d3F_dnb_dgab2 = _t1*_t686 + _t210;
  const double d3F_dnb_dgab_dgbb = _t677;
  const double d3F_dnb_dgbb2 = _t667;
  const double d3F_dgaa3 = _t710;
  const double d3F_dgaa2_dgab = _t715;
  const double d3F_dgaa2_dgbb = _t710;
  const double d3F_dgaa_dgab2 = _t720;
  const double d3F_dgaa_dgab_dgbb = _t715;
  const double d3F_dgaa_dgbb2 = _t710;
  const double d3F_dgab3 = _t1*_t724;
  const double d3F_dgab2_dgbb = _t720;
  const double d3F_dgab_dgbb2 = _t715;
  const double d3F_dgbb3 = _t710;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 1] += d3F_dna2_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 2] += d3F_dna2_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 3] += d3F_dna_dnb_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 4] += d3F_dna_dnb_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 5] += d3F_dna_dnb_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 6] += d3F_dnb2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 7] += d3F_dnb2_dgab;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 1] += d3F_dna_dgaa_dgab;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 2] += d3F_dna_dgaa_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 3] += d3F_dna_dgab2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 4] += d3F_dna_dgab_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 7] += d3F_dnb_dgaa_dgab;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 8] += d3F_dnb_dgaa_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 9] += d3F_dnb_dgab2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 10] += d3F_dnb_dgab_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 1] += d3F_dgaa2_dgab;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 2] += d3F_dgaa2_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 3] += d3F_dgaa_dgab2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 4] += d3F_dgaa_dgab_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 5] += d3F_dgaa_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 6] += d3F_dgab3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 7] += d3F_dgab2_dgbb;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 8] += d3F_dgab_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t727 = (0.16e2 / 0.9e1)*_t20;
  const double _t728 = (0.2e1 / 0.3e1)*_t10*_t4;
  const double _t729 = (0.140e3 / 0.81e2)*_t260;
  const double _t731 = 0.24e2*_t220;
  const double _t732 = xc_powi(_t1, -5);
  const double _t733 = 0.24e2*_t7*_t732;
  const double _t734 = -_t731 + _t733;
  const double _t735 = _t4*_t445;
  const double _t736 = 0.3e1*_t223;
  const double _t737 = _t211*_t4;
  const double _t738 = 0.3e1*_t61;
  const double _t787 = _t12*_t261;
  const double _t800 = (0.28e2 / 0.3e1)*_t12*_t75;
  const double _t806 = xc_powr(_t1, -16, 3);
  const double _t859 = 0.12e2*_t220;
  const double _t860 = _t733 - _t859;
  const double _t861 = 0.2e1*_t313;
  const double _t892 = (0.28e2 / 0.27e2)*_t75;
  const double _t930 = _t4*_t892;
  const double _t947 = _t219*_t7;
  const double _t950 = _t58*_t7;
  const double _t951 = _t4*_t52;
  const double _t998 = 0.18e2*_t221;
  const double _t1017 = _t731 + _t733;
  const double _t1018 = 0.3e1*_t409;
  const double _t1019 = 0.3e1*_t126;
  const double _t1035 = _t41*_t452;
  const double _t1036 = (0.1e1 / 0.9e1)*_t1035;
  const double _t1045 = xc_powr(_t1, -14, 3);
  const double _t1109 = (0.2e1 / 0.9e1)*_t1035;
  const double _t1162 = _t260*_t7;
  const double _t1163 = _t1162*_t41;
  const double _t1233 = _t7*_t806;
  const double _t1299 = (0.1e1 / 0.3e1)*_t20;
  const double _t1300 = _t190*_t592;
  const double _t1359 = _t151*_t190;
  const double _t1360 = (0.1e1 / 0.12e2)*_t1359;
  const double _t1379 = (0.1e1 / 0.6e1)*_t1359;
  const double _t1566 = _t141*_t5;
  const double _t725 = -0.56e2 / 0.27e2*_t51*_t75;
  const double _t726 = _t4*_t98;
  const double _t730 = _t51*_t729;
  const double _t739 = _hc3[5]*_t268;
  const double _t740 = -_t739;
  const double _t741 = _hc3[9]*_t55;
  const double _t742 = -_hc3[14]*_t15;
  const double _t743 = -_hc3[13]*_t15;
  const double _t744 = _hc3[12]*_t19 + _t743;
  const double _t745 = _hc3[8]*_t55;
  const double _t746 = -_hc3[12]*_t15;
  const double _t747 = _hc3[11]*_t19 + _t746;
  const double _t748 = _hc3[7]*_t61 - _t15*_t744 + _t19*_t747 + _t745;
  const double _t749 = _hc3[4]*_t268;
  const double _t750 = -_t749;
  const double _t751 = _hc3[7]*_t55;
  const double _t752 = -_hc3[11]*_t15;
  const double _t753 = 0.4e1*_t29;
  const double _t754 = 0.4e1*_t26;
  const double _t755 = 0.3e1*_t78;
  const double _t756 = 0.3e1*_t265;
  const double _t757 = _hc2[13]*_t19;
  const double _t758 = _hc2[12]*_t25;
  const double _t759 = _t757 + _t758;
  const double _t760 = _hc2[8]*_t61;
  const double _t761 = _hc2[12]*_t19;
  const double _t762 = _hc2[11]*_t25;
  const double _t763 = _t761 + _t762;
  const double _t764 = _hc2[7]*_t78;
  const double _t765 = _t19*_t759 + _t25*_t763 + _t760 + _t764;
  const double _t766 = _hc2[4]*_t223;
  const double _t767 = _hc2[7]*_t61;
  const double _t768 = _hc2[11]*_t19;
  const double _t769 = _hc2[10]*_t25;
  const double _t770 = _hc2[6]*_t78;
  const double _t771 = _hc2[3]*_t265;
  const double _t772 = _hc0[28]*_t15 + _hc4[23]*_t66;
  const double _t773 = -_hc4[27]*_t15;
  const double _t774 = _hc4[23]*_t19 + _t773;
  const double _t775 = _hc0[31]*_t15 + _hc4[27]*_t66;
  const double _t776 = _hc0[28]*_t19 - _t775;
  const double _t777 = _hc0[16]*_t55 + _hc4[12]*_t244;
  const double _t778 = _hc4[15]*_t55;
  const double _t779 = _hc4[12]*_t61;
  const double _t780 = -_hc4[30]*_t15;
  const double _t781 = _hc4[27]*_t19 + _t780;
  const double _t782 = -_t15*_t781 + _t19*_t774 + _t778 + _t779;
  const double _t783 = _hc0[33]*_t15 + _hc4[30]*_t66;
  const double _t784 = _hc0[31]*_t19 - _t783;
  const double _t785 = _hc0[18]*_t55 + _hc4[15]*_t244;
  const double _t786 = _hc0[16]*_t61 - _t15*_t784 + _t19*_t776 - _t66*_t781 + _t785;
  const double _t788 = _hc4[5]*_t787;
  const double _t789 = _hc0[8]*_t268;
  const double _t790 = -_t788 - _t789;
  const double _t791 = _t253*_t260;
  const double _t792 = _hc4[7]*_t268;
  const double _t793 = -_t792;
  const double _t794 = _hc4[5]*_t223;
  const double _t795 = _hc4[17]*_t55;
  const double _t796 = _hc4[15]*_t61;
  const double _t797 = -_hc4[32]*_t15;
  const double _t798 = _hc4[30]*_t19 + _t797;
  const double _t799 = -_t15*_t798 + _t19*_t781 + _t795 + _t796;
  const double _t801 = _hc0[34]*_t15 + _hc4[32]*_t66;
  const double _t802 = _hc0[19]*_t55 + _hc4[17]*_t244;
  const double _t803 = _hc4[7]*_t787;
  const double _t804 = _hc0[9]*_t268;
  const double _t805 = -_t803 - _t804;
  const double _t807 = _t23*_t729 + (0.3640e4 / 0.81e2)*_t74*_t806;
  const double _t808 = _hc0[2]*_t734 - _t15*(_hc0[8]*_t223 - _t15*(_hc0[18]*_t61 - _t15*(_hc0[33]*_t19 - _t801) + _t19*_t784 - _t66*_t798 + _t802) + _t19*_t786 + _t217*_t256 + _t224*_t243 + _t251*_t412 - _t66*_t799 + _t805) + _t19*(_hc0[6]*_t223 - _t15*_t786 + _t19*(_hc0[13]*_t61 - _t15*_t776 + _t19*(_hc0[24]*_t19 - _t772) - _t66*_t774 + _t777) + _t217*_t243 + _t224*_t238 + _t241*_t412 - _t66*_t782 + _t790) + _t246*_t738 + _t252*_t800 + _t258*_t737 - _t259*_t445 - _t66*(-_t15*_t799 + _t19*_t782 + _t217*_t251 + _t224*_t241 + _t793 + _t794) + _t68*_t736 - 0.280e3 / 0.9e1*_t791 + _t807;
  const double _t809 = _hc1[3]*_t4*_t729;
  const double _t810 = -_hc1[9]*_t268;
  const double _t811 = _hc1[19]*_t55;
  const double _t812 = -_hc1[34]*_t15;
  const double _t813 = -_hc1[33]*_t15;
  const double _t814 = _hc1[30]*_t25 + _hc1[31]*_t19 + _t813;
  const double _t815 = -_hc1[32]*_t15;
  const double _t816 = _hc1[30]*_t19;
  const double _t817 = _hc1[29]*_t25;
  const double _t818 = _t815 + _t816 + _t817;
  const double _t819 = _hc1[18]*_t55;
  const double _t820 = -_hc1[31]*_t15;
  const double _t821 = _hc1[27]*_t25 + _hc1[28]*_t19 + _t820;
  const double _t822 = -_hc1[30]*_t15;
  const double _t823 = _hc1[27]*_t19;
  const double _t824 = _hc1[26]*_t25;
  const double _t825 = _t822 + _t823 + _t824;
  const double _t826 = _hc1[15]*_t78 + _hc1[16]*_t61 - _t15*_t814 + _t19*_t821 + _t25*_t825 + _t819;
  const double _t827 = _hc1[17]*_t55;
  const double _t828 = _hc1[15]*_t61;
  const double _t829 = -_hc1[29]*_t15;
  const double _t830 = _hc1[26]*_t19;
  const double _t831 = _hc1[25]*_t25;
  const double _t832 = _t829 + _t830 + _t831;
  const double _t833 = _hc1[14]*_t78;
  const double _t834 = -_t15*_t818 + _t19*_t825 + _t25*_t832 + _t827 + _t828 + _t833;
  const double _t835 = -_hc1[8]*_t268;
  const double _t836 = _hc1[16]*_t55;
  const double _t837 = -_hc1[28]*_t15;
  const double _t838 = -_hc1[27]*_t15;
  const double _t839 = _hc1[23]*_t19;
  const double _t840 = _hc1[22]*_t25;
  const double _t841 = _t838 + _t839 + _t840;
  const double _t842 = _hc1[15]*_t55;
  const double _t843 = _hc1[12]*_t61;
  const double _t844 = -_hc1[26]*_t15;
  const double _t845 = _hc1[22]*_t19;
  const double _t846 = _hc1[21]*_t25;
  const double _t847 = _t844 + _t845 + _t846;
  const double _t848 = _hc1[11]*_t78;
  const double _t849 = -_t15*_t825 + _t19*_t841 + _t25*_t847 + _t842 + _t843 + _t848;
  const double _t850 = -_hc1[7]*_t268;
  const double _t851 = _hc1[5]*_t223;
  const double _t852 = _hc1[14]*_t55;
  const double _t853 = _hc1[11]*_t61;
  const double _t854 = -_hc1[25]*_t15;
  const double _t855 = _hc1[21]*_t19;
  const double _t856 = _hc1[20]*_t25;
  const double _t857 = _hc1[10]*_t78;
  const double _t858 = _hc1[4]*_t265;
  const double _t862 = 0.2e1*_t351;
  const double _t863 = _hc2[13]*_t34 + _hc2[14]*_t33;
  const double _t864 = _hc2[13]*_t33;
  const double _t865 = _hc2[12]*_t34;
  const double _t866 = _t864 + _t865;
  const double _t867 = _hc2[12]*_t33;
  const double _t868 = _hc2[11]*_t34;
  const double _t869 = _t867 + _t868;
  const double _t870 = _hc2[7]*_t109;
  const double _t871 = _hc2[8]*_t60 + _t19*_t866 + _t25*_t869 + _t870;
  const double _t872 = _hc2[4]*_t313;
  const double _t873 = _hc2[11]*_t33;
  const double _t874 = _hc2[10]*_t34;
  const double _t875 = _t873 + _t874;
  const double _t876 = _hc2[6]*_t109;
  const double _t877 = _hc2[3]*_t351;
  const double _t878 = _hc0[24]*_t33 - _t772;
  const double _t879 = _hc4[23]*_t33 + _t773;
  const double _t880 = _hc0[28]*_t33 - _t775;
  const double _t881 = -_t15*_t880 - _t66*_t879 + _t777;
  const double _t882 = _hc4[27]*_t33 + _t780;
  const double _t883 = -_t15*_t882 + _t778;
  const double _t884 = _hc4[12]*_t60 + _t19*_t879 + _t883;
  const double _t885 = _hc0[31]*_t33 - _t783;
  const double _t886 = -_t15*_t885 - _t66*_t882 + _t785;
  const double _t887 = _hc0[16]*_t60 + _t19*_t880 + _t886;
  const double _t888 = _hc4[5]*_t313;
  const double _t889 = _hc4[30]*_t33 + _t797;
  const double _t890 = -_t15*_t889 + _t795;
  const double _t891 = _hc4[15]*_t60 + _t19*_t882 + _t890;
  const double _t893 = -_t15*(_hc0[33]*_t33 - _t801) - _t66*_t889 + _t802;
  const double _t894 = _t217*_t350 + _t347*_t412 + _t807;
  const double _t895 = _hc0[2]*_t860 + _t104*_t223 - _t106*_t787 - _t107*_t268 - _t15*(_hc0[8]*_t313 - _t15*(_hc0[18]*_t60 + _t19*_t885 + _t893) + _t19*_t887 + _t243*_t60 + _t244*_t251 + _t244*_t345 + _t256*_t55 + _t341*_t61 + _t348*_t55 - _t66*_t891 + _t805) + _t19*(_hc0[6]*_t313 - _t15*_t887 + _t19*(_hc0[13]*_t60 + _t19*_t878 + _t881) + _t238*_t60 + _t241*_t244 + _t243*_t55 + _t244*_t340 + _t338*_t61 + _t341*_t55 - _t66*_t884 + _t790) + _t224*_t343 + _t244*_t252 + _t246*_t60 + _t258*_t55 - _t259*_t892 - _t66*(-_t15*_t891 + _t19*_t884 + _t241*_t60 + _t251*_t55 + _t340*_t61 + _t345*_t55 + _t793 + _t888) + _t68*_t861 - 0.560e3 / 0.27e2*_t791 + _t894;
  const double _t896 = _hc1[27]*_t34 + _hc1[28]*_t33 + _t820;
  const double _t897 = _hc1[27]*_t33;
  const double _t898 = _hc1[26]*_t34;
  const double _t899 = _t822 + _t897 + _t898;
  const double _t900 = _hc1[30]*_t34 + _hc1[31]*_t33 + _t813;
  const double _t901 = -_t15*_t900 + _t819;
  const double _t902 = _hc1[15]*_t109 + _hc1[16]*_t60 + _t19*_t896 + _t25*_t899 + _t901;
  const double _t903 = _hc1[23]*_t34 + _hc1[24]*_t33 + _t837;
  const double _t904 = _hc1[23]*_t33;
  const double _t905 = _hc1[22]*_t34;
  const double _t906 = _t838 + _t904 + _t905;
  const double _t907 = -_t15*_t896 + _t836;
  const double _t908 = _hc1[11]*_t109;
  const double _t909 = _hc1[22]*_t33;
  const double _t910 = _hc1[21]*_t34;
  const double _t911 = _t844 + _t909 + _t910;
  const double _t912 = -_t15*_t899 + _t842;
  const double _t913 = _hc1[12]*_t60 + _t19*_t906 + _t25*_t911 + _t908 + _t912;
  const double _t914 = _hc1[5]*_t313;
  const double _t915 = _hc1[14]*_t109;
  const double _t916 = _hc1[26]*_t33;
  const double _t917 = _hc1[25]*_t34;
  const double _t918 = _t829 + _t916 + _t917;
  const double _t919 = _hc1[30]*_t33;
  const double _t920 = _hc1[29]*_t34;
  const double _t921 = _t815 + _t919 + _t920;
  const double _t922 = -_t15*_t921 + _t827;
  const double _t923 = _hc1[15]*_t60 + _t19*_t899 + _t25*_t918 + _t915 + _t922;
  const double _t924 = _hc1[10]*_t109;
  const double _t925 = _hc1[21]*_t33;
  const double _t926 = _hc1[20]*_t34;
  const double _t927 = _t854 + _t925 + _t926;
  const double _t928 = -_t15*_t918 + _t852;
  const double _t929 = _hc1[4]*_t351;
  const double _t931 = -_t15*(_hc1[32]*_t34 + _hc1[33]*_t33 + _t812) + _t811;
  const double _t932 = _t217*_t360 + _t809;
  const double _t933 = _hc3[11]*_t33 + _t746;
  const double _t934 = _hc3[12]*_t33 + _t743;
  const double _t935 = -_t15*_t934 + _t745;
  const double _t936 = _hc3[7]*_t60 + _t19*_t933 + _t935;
  const double _t937 = _hc3[10]*_t33 + _t752;
  const double _t938 = -_t15*_t933 + _t751;
  const double _t939 = 0.3e1*_t26;
  const double _t940 = 0.3e1*_t29;
  const double _t941 = 0.3e1*_t118;
  const double _t942 = 0.3e1*_t110;
  const double _t943 = -_t15*(_hc3[13]*_t33 + _t742) + _t741;
  const double _t944 = _t217*_t319 + _t730;
  const double _t945 = 0.6e1*_t26;
  const double _t946 = 0.6e1*_t110;
  const double _t948 = _hc3[1]*_t859;
  const double _t949 = 0.8e1*_t120;
  const double _t952 = 0.4e1*_t37;
  const double _t953 = 0.4e1*_t118;
  const double _t954 = _hc3[1]*_t733;
  const double _t955 = _hc2[2]*_t733;
  const double _t956 = _hc2[8]*_t127 + _hc2[9]*_t126 + _t33*_t863 + _t34*_t866;
  const double _t957 = _hc2[8]*_t126;
  const double _t958 = _hc2[7]*_t127;
  const double _t959 = _t33*_t866 + _t34*_t869 + _t957 + _t958;
  const double _t960 = _hc2[7]*_t126;
  const double _t961 = _hc2[6]*_t127;
  const double _t962 = _t33*_t869 + _t34*_t875 + _t960 + _t961;
  const double _t963 = _hc2[3]*_t391;
  const double _t964 = _hc0[2]*_t733;
  const double _t965 = _hc4[12]*_t126;
  const double _t966 = _t33*_t879 + _t883 + _t965;
  const double _t967 = _t66*_t966;
  const double _t968 = _hc0[16]*_t126 + _t33*_t880 + _t886;
  const double _t969 = _t15*_t968;
  const double _t970 = _hc0[13]*_t126 + _t33*_t878 + _t881;
  const double _t971 = _t106*_t12*_t260;
  const double _t972 = _hc4[15]*_t126;
  const double _t973 = _t33*_t882 + _t890 + _t972;
  const double _t974 = _t15*_t973;
  const double _t975 = _t66*_t973;
  const double _t976 = _t15*(_hc0[18]*_t126 + _t33*_t885 + _t893);
  const double _t977 = _t104*_t861 - _t107*_t930 - _t15*(-_hc0[8]*_t222 - _hc0[8]*_t59 + (0.56e2 / 0.9e1)*_t12*_t345*_t75 + _t19*_t968 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t348 + 0.4e1*_t341*_t58*_t7 - _t803 - _t804 - _t975 - _t976) + _t19*(-_hc0[6]*_t222 - _hc0[6]*_t59 + (0.56e2 / 0.9e1)*_t12*_t340*_t75 + _t19*_t970 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t341 + 0.4e1*_t338*_t58*_t7 - _t788 - _t789 - _t967 - _t969) - _t214*_t259 - _t222*_t68 + _t244*_t386 - _t253*_t261 + _t343*_t379 + _t388*_t55 + _t390*_t61 - _t59*_t68 - _t66*(-_hc4[5]*_t222 - _hc4[5]*_t59 + _t19*_t966 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t345 + 0.4e1*_t340*_t58*_t7 - _t792 - _t974) + _t894 + _t964 - 0.560e3 / 0.27e2*_t971;
  const double _t978 = _hc1[2]*_t733;
  const double _t979 = _hc1[12]*_t127 + _hc1[13]*_t126 + _t33*_t903 + _t34*_t906 + _t907;
  const double _t980 = _hc1[11]*_t127;
  const double _t981 = _hc1[12]*_t126;
  const double _t982 = _t33*_t906 + _t34*_t911 + _t912 + _t980 + _t981;
  const double _t983 = _hc1[15]*_t127 + _hc1[16]*_t126 + _t33*_t896 + _t34*_t899 + _t901;
  const double _t984 = -_t15*_t983 + _t217*_t354 + _t835;
  const double _t985 = _hc1[4]*_t391;
  const double _t986 = _hc1[10]*_t127;
  const double _t987 = _hc1[11]*_t126;
  const double _t988 = _t33*_t911 + _t34*_t927 + _t928 + _t986 + _t987;
  const double _t989 = _hc1[14]*_t127;
  const double _t990 = _hc1[15]*_t126;
  const double _t991 = _t33*_t899 + _t34*_t918 + _t922 + _t989 + _t990;
  const double _t992 = -_t15*_t991 + _t217*_t357 + _t850;
  const double _t993 = -_t15*(_hc1[17]*_t127 + _hc1[18]*_t126 + _t33*_t900 + _t34*_t921 + _t931) + _t217*_t358 + _t810;
  const double _t994 = _hc3[7]*_t126 + _t33*_t933 + _t935;
  const double _t995 = _t15*_t994;
  const double _t996 = _hc3[6]*_t126 + _t33*_t937 + _t938;
  const double _t997 = _t15*(_hc3[8]*_t126 + _t33*_t934 + _t943);
  const double _t999 = 0.3e1*_t109;
  const double _t1000 = 0.3e1*_t391;
  const double _t1001 = _hc2[4]*_t413 + _hc2[5]*_t409 + _t328*_t410 + _t33*_t956 + _t331*_t411 + _t34*_t959;
  const double _t1002 = _hc2[4]*_t409;
  const double _t1003 = _hc2[3]*_t413;
  const double _t1004 = _t1002 + _t1003 + _t33*_t959 + _t331*_t410 + _t335*_t411 + _t34*_t962;
  const double _t1005 = _hc0[6]*_t409 + _t217*_t341 + _t33*_t970 + _t338*_t410 + _t340*_t412 + _t790 - _t967 - _t969;
  const double _t1006 = _hc4[5]*_t409;
  const double _t1007 = -_t107*_t735 - _t15*(_hc0[8]*_t409 + _t217*_t348 + _t33*_t968 + _t341*_t410 + _t345*_t412 + _t805 - _t975 - _t976) + _t386*_t800 + _t388*_t737 - _t66*(_t1006 + _t217*_t345 + _t33*_t966 + _t340*_t410 + _t793 - _t974) + _t807 - 0.280e3 / 0.9e1*_t971;
  const double _t1008 = _hc0[2]*_t859 + _t1005*_t19 + _t1007 - _t104*_t219 - _t104*_t998 + _t390*_t947 + _t964;
  const double _t1009 = _hc1[5]*_t413 + _hc1[6]*_t409 + _t33*_t979 + _t34*_t982 + _t361*_t410 + _t364*_t411 + _t984;
  const double _t1010 = _hc1[4]*_t413;
  const double _t1011 = _hc1[5]*_t409;
  const double _t1012 = _t1010 + _t1011 + _t33*_t982 + _t34*_t988 + _t364*_t410 + _t370*_t411 + _t992;
  const double _t1013 = -_t116*_t735 - _t15*(_hc1[7]*_t413 + _hc1[8]*_t409 + _t33*_t983 + _t34*_t991 + _t354*_t410 + _t357*_t411 + _t993) + _t398*_t737 + _t809;
  const double _t1014 = _hc3[3]*_t409 + _t217*_t316 + _t320*_t410 + _t33*_t996 + _t750 - _t995;
  const double _t1015 = -_t15*(_hc3[4]*_t409 + _t217*_t317 + _t316*_t410 + _t33*_t994 + _t740 - _t997) - _t375*_t445 + _t406*_t737 + _t730;
  const double _t1016 = _t375*_t727 - _t406*_t728 + _t725;
  const double _t1020 = 0.3e1*_t127;
  const double _t1021 = 0.3e1*_t413;
  const double _t1022 = _hc0[2]*_t1017 + _t1005*_t33 + _t1007 + _t1018*_t104 + _t1019*_t390;
  const double _t1023 = 0.6e1*_t29;
  const double _t1024 = 0.3e1*_t79;
  const double _t1025 = 0.3e1*_t90;
  const double _t1026 = _t266*_t46;
  const double _t1027 = _t296*_t44;
  const double _t1028 = _t43*_t766;
  const double _t1029 = 0.2e1*_t449;
  const double _t1030 = _t43*_t771;
  const double _t1031 = _hc4[12]*_t441 + _hc4[27]*_t438;
  const double _t1032 = _t42*_t779;
  const double _t1033 = _hc4[15]*_t441 + _hc4[30]*_t438;
  const double _t1034 = (0.1e1 / 0.2e1)*_hc4[27]*_t10*_t19*_t41 - _t1033;
  const double _t1037 = _hc4[15]*_t1036 + _t436*_t445;
  const double _t1038 = _t41*_t71;
  const double _t1039 = _t1038*_t76;
  const double _t1040 = _t42*_t794;
  const double _t1041 = _t42*_t796;
  const double _t1042 = _hc4[17]*_t441 + _hc4[32]*_t438;
  const double _t1043 = _hc4[17]*_t1036 + _t142*_t445;
  const double _t1044 = (0.140e3 / 0.27e2)*_t507;
  const double _t1046 = _t1045*_t143;
  const double _t1047 = (0.7e1 / 0.27e2)*_t1046;
  const double _t1048 = -_t1044 - _t1047;
  const double _t1049 = _t1039 + (0.1e1 / 0.2e1)*_t1040 + _t1048 - _t15*(_t1034*_t19 + (0.1e1 / 0.2e1)*_t1041 + _t1043 - _t15*((0.1e1 / 0.2e1)*_hc4[30]*_t10*_t19*_t41 - _t1042) - _t251*_t441) + _t19*((0.1e1 / 0.2e1)*_t1032 - _t1034*_t15 + _t1037 + _t19*((0.1e1 / 0.2e1)*_hc4[23]*_t10*_t19*_t41 - _t1031) - _t241*_t441) + _t217*_t444 + _t224*_t440 - _t252*_t441;
  const double _t1050 = _t43*_t760;
  const double _t1051 = _t43*_t757;
  const double _t1052 = _t43*_t758;
  const double _t1053 = _t43*_t761;
  const double _t1054 = _t43*_t762;
  const double _t1055 = _hc2[7]*_t146;
  const double _t1056 = (0.1e1 / 0.2e1)*_t1053 + (0.1e1 / 0.2e1)*_t1054 + _t1055;
  const double _t1057 = _t43*_t764;
  const double _t1058 = _t43*_t767;
  const double _t1059 = _t43*_t768;
  const double _t1060 = _t43*_t769;
  const double _t1061 = _hc2[6]*_t146;
  const double _t1062 = _t43*_t770;
  const double _t1063 = _hc2[3]*_t449;
  const double _t1064 = _t1045*_t150*_t4;
  const double _t1065 = -0.7e1 / 0.27e2*_t1064;
  const double _t1066 = _t43*_t851;
  const double _t1067 = _t43*_t858;
  const double _t1068 = _t149*_t452;
  const double _t1069 = (0.1e1 / 0.9e1)*_t1068;
  const double _t1070 = _hc1[17]*_t1069;
  const double _t1071 = _t43*_t828;
  const double _t1072 = -_hc1[32]*_t456;
  const double _t1073 = _t43*_t816;
  const double _t1074 = _t43*_t817;
  const double _t1075 = -_hc1[30]*_t456;
  const double _t1076 = _t43*_t823;
  const double _t1077 = _t43*_t824;
  const double _t1078 = _hc1[15]*_t146 + _t1075 + (0.1e1 / 0.2e1)*_t1076 + (0.1e1 / 0.2e1)*_t1077;
  const double _t1079 = -_hc1[29]*_t456;
  const double _t1080 = _t43*_t830;
  const double _t1081 = _t43*_t831;
  const double _t1082 = _hc1[14]*_t146;
  const double _t1083 = _t1079 + (0.1e1 / 0.2e1)*_t1080 + (0.1e1 / 0.2e1)*_t1081 + _t1082;
  const double _t1084 = _t43*_t833;
  const double _t1085 = _hc1[15]*_t1069;
  const double _t1086 = _t43*_t843;
  const double _t1087 = -_hc1[27]*_t456;
  const double _t1088 = _t43*_t839;
  const double _t1089 = _t43*_t840;
  const double _t1090 = -_hc1[26]*_t456;
  const double _t1091 = _t43*_t845;
  const double _t1092 = _t43*_t846;
  const double _t1093 = _hc1[11]*_t146;
  const double _t1094 = _t1090 + (0.1e1 / 0.2e1)*_t1091 + (0.1e1 / 0.2e1)*_t1092 + _t1093;
  const double _t1095 = _t43*_t848;
  const double _t1096 = _hc1[14]*_t1069;
  const double _t1097 = _t43*_t853;
  const double _t1098 = -_hc1[25]*_t456;
  const double _t1099 = _t43*_t855;
  const double _t1100 = _t43*_t856;
  const double _t1101 = _hc1[10]*_t146;
  const double _t1102 = _t43*_t857;
  const double _t1103 = _hc1[4]*_t449;
  const double _t1104 = _t1*(_hc1[0]*(_hc2[1]*_t1049 + (0.1e1 / 0.2e1)*_t1028 + _t1029*_t65 + (0.1e1 / 0.2e1)*_t1030 + _t146*_t236 + _t19*(_hc2[4]*_t449 + (0.1e1 / 0.2e1)*_t1050 + _t1056*_t25 + (0.1e1 / 0.2e1)*_t1057 + _t146*_t229 + _t19*(_hc2[8]*_t146 + (0.1e1 / 0.2e1)*_t1051 + (0.1e1 / 0.2e1)*_t1052)) + _t224*_t430 + _t225*_t434 + _t25*(_t1056*_t19 + (0.1e1 / 0.2e1)*_t1058 + (0.1e1 / 0.2e1)*_t1062 + _t1063 + _t146*_t234 + _t25*((0.1e1 / 0.2e1)*_t1059 + (0.1e1 / 0.2e1)*_t1060 + _t1061))) + _hc2[0]*(_hc1[1]*_t1049 + _t1029*_t89 + _t1065 + (0.1e1 / 0.2e1)*_t1066 + (0.1e1 / 0.2e1)*_t1067 + _t146*_t295 - _t15*(_hc1[7]*_t449 + _t1070 + (0.1e1 / 0.2e1)*_t1071 + _t1078*_t19 + _t1083*_t25 + (0.1e1 / 0.2e1)*_t1084 + _t146*_t278 - _t15*(_hc1[17]*_t146 + _t1072 + (0.1e1 / 0.2e1)*_t1073 + (0.1e1 / 0.2e1)*_t1074)) + _t19*(_hc1[5]*_t449 - _t1078*_t15 + _t1085 + (0.1e1 / 0.2e1)*_t1086 + _t1094*_t25 + (0.1e1 / 0.2e1)*_t1095 + _t146*_t286 + _t19*(_hc1[12]*_t146 + _t1087 + (0.1e1 / 0.2e1)*_t1088 + (0.1e1 / 0.2e1)*_t1089)) + _t217*_t460 + _t224*_t464 + _t225*_t469 + _t25*(-_t1083*_t15 + _t1094*_t19 + _t1096 + (0.1e1 / 0.2e1)*_t1097 + (0.1e1 / 0.2e1)*_t1102 + _t1103 + _t146*_t293 + _t25*(_t1098 + (0.1e1 / 0.2e1)*_t1099 + (0.1e1 / 0.2e1)*_t1100 + _t1101))) + _t1024*_t156 + _t1025*_t147 + (0.1e1 / 0.2e1)*_t1026 + (0.1e1 / 0.2e1)*_t1027 + _t450*_t940 + _t471*_t939) + _t1023*_t147 + _t156*_t945 + (0.3e1 / 0.2e1)*_t425 + (0.3e1 / 0.2e1)*_t426 + 0.3e1*_t451 + 0.3e1*_t472;
  const double _t1105 = 0.2e1*_t486;
  const double _t1106 = _hc4[12]*_t482 + _hc4[27]*_t479;
  const double _t1107 = _hc4[15]*_t482 + _hc4[30]*_t479;
  const double _t1108 = _hc4[27]*_t10*_t19*_t41 - _t1107;
  const double _t1110 = _hc4[15]*_t1109 + _t436*_t76;
  const double _t1111 = _hc4[17]*_t482 + _hc4[32]*_t479;
  const double _t1112 = _hc4[17]*_t1109 + _t142*_t76;
  const double _t1113 = _t149*_t261;
  const double _t1114 = (0.14e2 / 0.27e2)*_t1046;
  const double _t1115 = -_t1113 - _t1114;
  const double _t1116 = _t1038*_t254 + _t1040 + _t1115 - _t15*(_t1041 + _t1108*_t19 + _t1112 - _t15*(_hc4[30]*_t10*_t19*_t41 - _t1111) - _t251*_t482) + _t19*(_t1032 - _t1108*_t15 + _t1110 + _t19*(_hc4[23]*_t10*_t19*_t41 - _t1106) - _t241*_t482) + _t217*_t484 + _t224*_t481 - _t252*_t482;
  const double _t1117 = _hc2[7]*_t161;
  const double _t1118 = _t1053 + _t1054 + _t1117;
  const double _t1119 = _hc2[6]*_t161;
  const double _t1120 = _hc2[3]*_t486;
  const double _t1121 = -0.14e2 / 0.27e2*_t1064;
  const double _t1122 = (0.2e1 / 0.9e1)*_t1068;
  const double _t1123 = _hc1[17]*_t1122;
  const double _t1124 = -_hc1[32]*_t490;
  const double _t1125 = -_hc1[30]*_t490;
  const double _t1126 = _hc1[15]*_t161 + _t1076 + _t1077 + _t1125;
  const double _t1127 = -_hc1[29]*_t490;
  const double _t1128 = _hc1[14]*_t161;
  const double _t1129 = _t1080 + _t1081 + _t1127 + _t1128;
  const double _t1130 = _hc1[15]*_t1122;
  const double _t1131 = -_hc1[27]*_t490;
  const double _t1132 = -_hc1[26]*_t490;
  const double _t1133 = _hc1[11]*_t161;
  const double _t1134 = _t1091 + _t1092 + _t1132 + _t1133;
  const double _t1135 = _hc1[14]*_t1122;
  const double _t1136 = -_hc1[25]*_t490;
  const double _t1137 = _hc1[10]*_t161;
  const double _t1138 = _hc1[4]*_t486;
  const double _t1139 = 0.2e1*_t118;
  const double _t1140 = _t352*_t46;
  const double _t1141 = _t373*_t44;
  const double _t1142 = _t43*_t872;
  const double _t1143 = _t43*_t877;
  const double _t1144 = _t507*_t7;
  const double _t1145 = _hc2[8]*_t1144;
  const double _t1146 = _t43*_t864;
  const double _t1147 = _t43*_t865;
  const double _t1148 = _hc2[8]*_t174 + (0.1e1 / 0.2e1)*_t1146 + (0.1e1 / 0.2e1)*_t1147;
  const double _t1149 = _t43*_t867;
  const double _t1150 = _t43*_t868;
  const double _t1151 = _hc2[7]*_t174;
  const double _t1152 = (0.1e1 / 0.2e1)*_t1149 + (0.1e1 / 0.2e1)*_t1150 + _t1151;
  const double _t1153 = _t43*_t870;
  const double _t1154 = _hc2[7]*_t1144;
  const double _t1155 = _t43*_t873;
  const double _t1156 = _t43*_t874;
  const double _t1157 = _hc2[6]*_t174;
  const double _t1158 = (0.1e1 / 0.2e1)*_t1155 + (0.1e1 / 0.2e1)*_t1156 + _t1157;
  const double _t1159 = _t43*_t876;
  const double _t1160 = _hc2[3]*_t523;
  const double _t1161 = (0.1e1 / 0.2e1)*_hc4[23]*_t10*_t33*_t41 - _t1031;
  const double _t1164 = _hc4[12]*_t1163;
  const double _t1165 = (0.1e1 / 0.2e1)*_hc4[27]*_t10*_t33*_t41 - _t1033;
  const double _t1166 = _t1037 - _t1165*_t15 - _t340*_t441;
  const double _t1167 = _t106*_t41;
  const double _t1168 = _t42*_t888;
  const double _t1169 = _hc4[15]*_t1163;
  const double _t1170 = _t1043 - _t15*((0.1e1 / 0.2e1)*_hc4[30]*_t10*_t33*_t41 - _t1042) - _t345*_t441;
  const double _t1171 = _t1038*_t445 + _t1048 + _t1167*_t445 + (0.1e1 / 0.2e1)*_t1168 - _t15*(_t1165*_t19 + _t1169 + _t1170) + _t19*(_t1161*_t19 + _t1164 + _t1166) - _t347*_t441 + _t440*_t60 + _t444*_t55 + _t518*_t61 + _t521*_t55;
  const double _t1172 = _t43*_t914;
  const double _t1173 = _t43*_t929;
  const double _t1174 = _t43*_t897;
  const double _t1175 = _t43*_t898;
  const double _t1176 = _hc1[15]*_t174 + _t1075 + (0.1e1 / 0.2e1)*_t1174 + (0.1e1 / 0.2e1)*_t1175;
  const double _t1177 = _t43*_t916;
  const double _t1178 = _t43*_t917;
  const double _t1179 = _hc1[14]*_t174;
  const double _t1180 = _t1079 + (0.1e1 / 0.2e1)*_t1177 + (0.1e1 / 0.2e1)*_t1178 + _t1179;
  const double _t1181 = _hc1[15]*_t1144;
  const double _t1182 = _t43*_t915;
  const double _t1183 = _t43*_t919;
  const double _t1184 = _t43*_t920;
  const double _t1185 = _t1070 - _t15*(_hc1[17]*_t174 + _t1072 + (0.1e1 / 0.2e1)*_t1183 + (0.1e1 / 0.2e1)*_t1184);
  const double _t1186 = _t43*_t904;
  const double _t1187 = _t43*_t905;
  const double _t1188 = _hc1[12]*_t174 + _t1087 + (0.1e1 / 0.2e1)*_t1186 + (0.1e1 / 0.2e1)*_t1187;
  const double _t1189 = _t43*_t909;
  const double _t1190 = _t43*_t910;
  const double _t1191 = _hc1[11]*_t174;
  const double _t1192 = _t1090 + (0.1e1 / 0.2e1)*_t1189 + (0.1e1 / 0.2e1)*_t1190 + _t1191;
  const double _t1193 = _hc1[12]*_t1144;
  const double _t1194 = _t43*_t908;
  const double _t1195 = _t1085 - _t1176*_t15;
  const double _t1196 = _hc1[4]*_t523;
  const double _t1197 = _t43*_t925;
  const double _t1198 = _t43*_t926;
  const double _t1199 = _hc1[10]*_t174;
  const double _t1200 = _t1098 + (0.1e1 / 0.2e1)*_t1197 + (0.1e1 / 0.2e1)*_t1198 + _t1199;
  const double _t1201 = _hc1[11]*_t1144;
  const double _t1202 = _t43*_t924;
  const double _t1203 = _t1096 - _t1180*_t15;
  const double _t1204 = 0.2e1*_t501 + 0.2e1*_t502 + 0.2e1*_t503 + 0.2e1*_t504 + 0.2e1*_t525 + 0.2e1*_t541 + _t563;
  const double _t1205 = _t1*(_hc1[0]*(_hc2[1]*_t1171 + _t103*_t449 + _t109*_t434 + (0.1e1 / 0.2e1)*_t1142 + (0.1e1 / 0.2e1)*_t1143 + _t146*_t337 + _t19*(_hc2[4]*_t523 + _t1145 + _t1148*_t19 + _t1152*_t25 + (0.1e1 / 0.2e1)*_t1153 + _t146*_t331) + _t25*(_t1152*_t19 + _t1154 + _t1158*_t25 + (0.1e1 / 0.2e1)*_t1159 + _t1160 + _t146*_t335) + _t430*_t60 + _t512*_t61 + _t516*_t78 + _t523*_t65) + _hc2[0]*(_hc1[1]*_t1171 + _t1065 + _t109*_t469 + _t115*_t449 + (0.1e1 / 0.2e1)*_t1172 + (0.1e1 / 0.2e1)*_t1173 + _t146*_t372 - _t15*(_hc1[7]*_t523 + _t1176*_t19 + _t1180*_t25 + _t1181 + (0.1e1 / 0.2e1)*_t1182 + _t1185 + _t146*_t357) + _t19*(_hc1[5]*_t523 + _t1188*_t19 + _t1192*_t25 + _t1193 + (0.1e1 / 0.2e1)*_t1194 + _t1195 + _t146*_t364) + _t25*(_t1192*_t19 + _t1196 + _t1200*_t25 + _t1201 + (0.1e1 / 0.2e1)*_t1202 + _t1203 + _t146*_t370) + _t460*_t55 + _t464*_t60 + _t523*_t89 + _t528*_t61 + _t532*_t78 + _t538*_t55) + _t1139*_t147 + (0.1e1 / 0.2e1)*_t1140 + (0.1e1 / 0.2e1)*_t1141 + _t156*_t324 + _t175*_t90 + _t179*_t79 + _t326*_t540 + _t35*_t471 + _t37*_t450 + _t424*_t524) + _t1204 + _t473;
  const double _t1206 = _hc2[8]*_t183 + _t1146 + _t1147;
  const double _t1207 = _hc2[7]*_t183;
  const double _t1208 = _t1149 + _t1150 + _t1207;
  const double _t1209 = _hc2[6]*_t183;
  const double _t1210 = _t1155 + _t1156 + _t1209;
  const double _t1211 = _hc2[3]*_t549;
  const double _t1212 = _t1167*_t76;
  const double _t1213 = _hc4[23]*_t10*_t33*_t41 - _t1106;
  const double _t1214 = _hc4[27]*_t10*_t33*_t41 - _t1107;
  const double _t1215 = _t1110 - _t1214*_t15 - _t340*_t482;
  const double _t1216 = _t1112 - _t15*(_hc4[30]*_t10*_t33*_t41 - _t1111) - _t345*_t482;
  const double _t1217 = _t1039 + _t1115 + _t1168 + _t1212 - _t15*(0.2e1*_t1169 + _t1214*_t19 + _t1216) + _t19*(0.2e1*_t1164 + _t1213*_t19 + _t1215) - _t347*_t482 + _t481*_t60 + _t484*_t55 + _t546*_t61 + _t547*_t55;
  const double _t1218 = _hc1[15]*_t183 + _t1125 + _t1174 + _t1175;
  const double _t1219 = _hc1[14]*_t183;
  const double _t1220 = _t1127 + _t1177 + _t1178 + _t1219;
  const double _t1221 = _t1123 - _t15*(_hc1[17]*_t183 + _t1124 + _t1183 + _t1184);
  const double _t1222 = _hc1[12]*_t183 + _t1131 + _t1186 + _t1187;
  const double _t1223 = _hc1[11]*_t183;
  const double _t1224 = _t1132 + _t1189 + _t1190 + _t1223;
  const double _t1225 = _t1130 - _t1218*_t15;
  const double _t1226 = _hc1[4]*_t549;
  const double _t1227 = _hc1[10]*_t183;
  const double _t1228 = _t1136 + _t1197 + _t1198 + _t1227;
  const double _t1229 = _t1135 - _t1220*_t15;
  const double _t1230 = _t1139*_t44 + _t324*_t46 + 0.2e1*_t551 + 0.2e1*_t558 + 0.2e1*_t559 + 0.2e1*_t560 + 0.2e1*_t561 + 0.2e1*_t562;
  const double _t1231 = _t392*_t46;
  const double _t1232 = _t400*_t44;
  const double _t1234 = _t1233*_t149;
  const double _t1235 = 0.3e1*_t1234;
  const double _t1236 = 0.2e1*_t523;
  const double _t1237 = _t43*_t963;
  const double _t1238 = _t1233*_t436;
  const double _t1239 = _t386*_t441;
  const double _t1240 = _t42*_t972;
  const double _t1241 = _t15*(_t1165*_t33 + _t1170 + (0.1e1 / 0.2e1)*_t1240);
  const double _t1242 = _t42*_t965;
  const double _t1243 = _t1161*_t33 + _t1166 + (0.1e1 / 0.2e1)*_t1242;
  const double _t1244 = -_t1044 - _t1047 + (0.28e2 / 0.9e1)*_t106*_t41*_t75 - 0.3e1*_t1238 - _t1239 - _t1241 + _t1243*_t19 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t521 + 0.4e1*_t518*_t58*_t7 - _t519;
  const double _t1245 = _t43*_t957;
  const double _t1246 = _t43*_t958;
  const double _t1247 = _hc2[4]*_t570 + _t1148*_t33 + _t1152*_t34 + (0.1e1 / 0.2e1)*_t1245 + (0.1e1 / 0.2e1)*_t1246 + _t174*_t331;
  const double _t1248 = _t43*_t960;
  const double _t1249 = _t43*_t961;
  const double _t1250 = _hc2[3]*_t570;
  const double _t1251 = _t1152*_t33 + _t1158*_t34 + (0.1e1 / 0.2e1)*_t1248 + (0.1e1 / 0.2e1)*_t1249 + _t1250 + _t174*_t335;
  const double _t1252 = _t43*_t980;
  const double _t1253 = _t43*_t981;
  const double _t1254 = _hc1[5]*_t570 + _t1188*_t33 + _t1192*_t34 + _t1195 + (0.1e1 / 0.2e1)*_t1252 + (0.1e1 / 0.2e1)*_t1253 + _t174*_t364;
  const double _t1255 = _hc1[4]*_t570;
  const double _t1256 = _t43*_t986;
  const double _t1257 = _t43*_t987;
  const double _t1258 = _t1192*_t33 + _t1200*_t34 + _t1203 + _t1255 + (0.1e1 / 0.2e1)*_t1256 + (0.1e1 / 0.2e1)*_t1257 + _t174*_t370;
  const double _t1259 = _t43*_t985;
  const double _t1260 = _t43*_t989;
  const double _t1261 = _t43*_t990;
  const double _t1262 = _t1065 - _t15*(_hc1[7]*_t570 + _t1176*_t33 + _t1180*_t34 + _t1185 + (0.1e1 / 0.2e1)*_t1260 + (0.1e1 / 0.2e1)*_t1261 + _t174*_t357) + _t217*_t538;
  const double _t1263 = _t1*(_hc1[0]*(_hc2[1]*_t1244 - _hc2[4]*_t1235 + _t103*_t1236 + (0.1e1 / 0.2e1)*_t1237 + _t1247*_t19 + _t1251*_t25 + _t146*_t384 + _t379*_t512 + _t380*_t516 - _t508) + _hc2[0]*(_hc1[1]*_t1244 - _hc1[5]*_t1235 + _t115*_t1236 + _t1254*_t19 + _t1258*_t25 + (0.1e1 / 0.2e1)*_t1259 + _t1262 + _t146*_t397 + _t379*_t528 + _t380*_t532 - _t533) + _t1139*_t175 + (0.1e1 / 0.2e1)*_t1231 + (0.1e1 / 0.2e1)*_t1232 + _t128*_t156 + _t130*_t147 + _t134*_t540 + _t179*_t324 + _t26*_t575 + _t29*_t571 + _t524*_t564) + _t1204 + _t577;
  const double _t1264 = 0.6e1*_t1234;
  const double _t1265 = 0.2e1*_t549;
  const double _t1266 = _t386*_t482;
  const double _t1267 = _t15*(_t1214*_t33 + _t1216 + _t1240);
  const double _t1268 = _t1213*_t33 + _t1215 + _t1242;
  const double _t1269 = (0.56e2 / 0.9e1)*_t106*_t41*_t75 - _t1113 - _t1114 - 0.6e1*_t1238 - _t1266 - _t1267 + _t1268*_t19 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t547 - 0.2e1*_t519 + 0.4e1*_t546*_t58*_t7;
  const double _t1270 = _hc2[4]*_t579 + _t1206*_t33 + _t1208*_t34 + _t1245 + _t1246 + _t183*_t331;
  const double _t1271 = _hc2[3]*_t579;
  const double _t1272 = _t1208*_t33 + _t1210*_t34 + _t1248 + _t1249 + _t1271 + _t183*_t335;
  const double _t1273 = _hc1[5]*_t579 + _t1222*_t33 + _t1224*_t34 + _t1225 + _t1252 + _t1253 + _t183*_t364;
  const double _t1274 = _hc1[4]*_t579;
  const double _t1275 = _t1224*_t33 + _t1228*_t34 + _t1229 + _t1256 + _t1257 + _t1274 + _t183*_t370;
  const double _t1276 = _t1121 - _t15*(_hc1[7]*_t579 + _t1218*_t33 + _t1220*_t34 + _t1221 + _t1260 + _t1261 + _t183*_t357) + _t217*_t555;
  const double _t1277 = 0.6e1*_t37;
  const double _t1278 = 0.3e1*_t128;
  const double _t1279 = 0.3e1*_t130;
  const double _t1280 = _t414*_t46;
  const double _t1281 = _t416*_t44;
  const double _t1282 = _t1002*_t43;
  const double _t1283 = 0.2e1*_t570;
  const double _t1284 = _t1003*_t43;
  const double _t1285 = _t1006*_t42;
  const double _t1286 = _t1048 + _t1212 - _t1239 - _t1241 + _t1243*_t33 + (0.1e1 / 0.2e1)*_t1285 + _t217*_t521 + _t410*_t518;
  const double _t1287 = _t1010*_t43;
  const double _t1288 = _t1011*_t43;
  const double _t1289 = _t1*(_hc1[0]*(_hc2[1]*_t1286 + _t103*_t1283 + _t1247*_t33 + _t1251*_t34 + (0.1e1 / 0.2e1)*_t1282 + (0.1e1 / 0.2e1)*_t1284 + _t174*_t384 + _t410*_t512 + _t411*_t516) + _hc2[0]*(_hc1[1]*_t1286 + _t115*_t1283 + _t1254*_t33 + _t1258*_t34 + _t1262 + (0.1e1 / 0.2e1)*_t1287 + (0.1e1 / 0.2e1)*_t1288 + _t174*_t397 + _t410*_t528 + _t411*_t532) + _t1278*_t179 + _t1279*_t175 + (0.1e1 / 0.2e1)*_t1280 + (0.1e1 / 0.2e1)*_t1281 + _t420*_t575 + _t421*_t571) + _t1277*_t175 + _t179*_t423 + (0.3e1 / 0.2e1)*_t565 + (0.3e1 / 0.2e1)*_t566 + 0.3e1*_t572 + 0.3e1*_t576;
  const double _t1290 = 0.2e1*_t579;
  const double _t1291 = _t1115 + _t1167*_t254 - _t1266 - _t1267 + _t1268*_t33 + _t1285 + _t217*_t547 + _t410*_t546;
  const double _t1292 = _t192*_t231;
  const double _t1293 = _t199*_t767;
  const double _t1294 = 0.2e1*_t146;
  const double _t1295 = _t192*_t235;
  const double _t1296 = _t199*_t770;
  const double _t1297 = _t191*_t240;
  const double _t1298 = _hc4[5]*_t190;
  const double _t1301 = _hc4[15]*_t1300 + _t1298*_t1299;
  const double _t1302 = _t191*_t248;
  const double _t1303 = _t191*_t250;
  const double _t1304 = _hc4[17]*_t1300 + _hc4[7]*_t1299*_t190;
  const double _t1305 = _t452*_t591;
  const double _t1306 = (0.1e1 / 0.18e2)*_t1305 + (0.7e1 / 0.9e1)*_t606*_t75;
  const double _t1307 = -0.1e1 / 0.4e1*_t1302 - _t1306 - _t15*(-0.1e1 / 0.4e1*_t1303 + _t1304) + _t19*(-0.1e1 / 0.4e1*_t1297 + _t1301) + (0.1e1 / 0.3e1)*_t190*_t20*_t71;
  const double _t1308 = _t1063*_t43;
  const double _t1309 = _t192*_t227;
  const double _t1310 = _t199*_t761;
  const double _t1311 = _t192*_t228;
  const double _t1312 = _t199*_t762;
  const double _t1313 = _t1055*_t43;
  const double _t1314 = _t192*_t232;
  const double _t1315 = _t199*_t768;
  const double _t1316 = _t192*_t233;
  const double _t1317 = _t199*_t769;
  const double _t1318 = _hc2[3]*_t594;
  const double _t1319 = _t1061*_t43;
  const double _t1320 = _t1093*_t43;
  const double _t1321 = _t192*_t285;
  const double _t1322 = _t192*_t284;
  const double _t1323 = _t199*_t846;
  const double _t1324 = _t199*_t845;
  const double _t1325 = _t198*_t220;
  const double _t1326 = _t1325*_t603;
  const double _t1327 = _t592*_t606;
  const double _t1328 = _hc1[15]*_t1327 - _hc1[26]*_t1326;
  const double _t1329 = _hc1[4]*_t594;
  const double _t1330 = _t1101*_t43;
  const double _t1331 = _t192*_t292;
  const double _t1332 = _t192*_t291;
  const double _t1333 = _t199*_t856;
  const double _t1334 = _t199*_t855;
  const double _t1335 = _hc1[14]*_t1327 - _hc1[25]*_t1326;
  const double _t1336 = _t1082*_t43;
  const double _t1337 = _t192*_t277;
  const double _t1338 = _t192*_t276;
  const double _t1339 = _t199*_t831;
  const double _t1340 = _t199*_t830;
  const double _t1341 = _hc1[17]*_t1327 - _hc1[29]*_t1326;
  const double _t1342 = _t1103*_t43;
  const double _t1343 = _t192*_t294;
  const double _t1344 = _t192*_t289;
  const double _t1345 = _t199*_t857;
  const double _t1346 = _t199*_t853;
  const double _t1347 = _t452*_t607;
  const double _t1348 = _hc1[14]*_t198*_t4*_t732;
  const double _t1349 = -0.1e1 / 0.18e2*_t1347 + (0.1e1 / 0.18e2)*_t1348;
  const double _t1350 = _t195*_t79;
  const double _t1351 = _t193*_t90;
  const double _t1352 = _t204*_t79;
  const double _t1353 = _t200*_t90;
  const double _t1354 = _t44*_t471 + _t450*_t46;
  const double _t1355 = 0.2e1*_t147;
  const double _t1356 = 0.2e1*_t156;
  const double _t1357 = _t1355*_t46 + _t1356*_t44;
  const double _t1358 = _t1*(_hc1[0]*(_hc2[1]*_t1307 - 0.1e1 / 0.4e1*_t1292 + (0.1e1 / 0.4e1)*_t1293 + _t1294*_t434 - 0.1e1 / 0.4e1*_t1295 + (0.1e1 / 0.4e1)*_t1296 + _t1308 + _t19*(_hc2[4]*_t594 - 0.1e1 / 0.4e1*_t1309 + (0.1e1 / 0.4e1)*_t1310 - 0.1e1 / 0.4e1*_t1311 + (0.1e1 / 0.4e1)*_t1312 + _t1313) + _t25*(-0.1e1 / 0.4e1*_t1314 + (0.1e1 / 0.4e1)*_t1315 - 0.1e1 / 0.4e1*_t1316 + (0.1e1 / 0.4e1)*_t1317 + _t1318 + _t1319) + _t594*_t65) + _hc2[0]*(_hc1[1]*_t1307 + _t1294*_t469 + _t1342 - 0.1e1 / 0.4e1*_t1343 - 0.1e1 / 0.4e1*_t1344 + (0.1e1 / 0.4e1)*_t1345 + (0.1e1 / 0.4e1)*_t1346 + _t1349 - _t15*(_hc1[7]*_t594 + _t1336 - 0.1e1 / 0.4e1*_t1337 - 0.1e1 / 0.4e1*_t1338 + (0.1e1 / 0.4e1)*_t1339 + (0.1e1 / 0.4e1)*_t1340 + _t1341) + _t19*(_hc1[5]*_t594 + _t1320 - 0.1e1 / 0.4e1*_t1321 - 0.1e1 / 0.4e1*_t1322 + (0.1e1 / 0.4e1)*_t1323 + (0.1e1 / 0.4e1)*_t1324 + _t1328) + _t25*(_t1329 + _t1330 - 0.1e1 / 0.4e1*_t1331 - 0.1e1 / 0.4e1*_t1332 + (0.1e1 / 0.4e1)*_t1333 + (0.1e1 / 0.4e1)*_t1334 + _t1335) + _t594*_t89) - 0.1e1 / 0.4e1*_t1350 - 0.1e1 / 0.4e1*_t1351 + (0.1e1 / 0.4e1)*_t1352 + (0.1e1 / 0.4e1)*_t1353 + _t1354 + 0.4e1*_t147*_t156 + _t326*_t609 + _t424*_t596) + _t1357 + 0.2e1*_t597 + 0.2e1*_t610 + _t630;
  const double _t1361 = _hc4[15]*_t1360 + _t1298*_t211;
  const double _t1362 = _hc4[17]*_t1360 + _hc4[7]*_t190*_t211;
  const double _t1363 = (0.1e1 / 0.9e1)*_t1305 + _t445*_t606;
  const double _t1364 = -0.1e1 / 0.2e1*_t1302 - _t1363 - _t15*(-0.1e1 / 0.2e1*_t1303 + _t1362) + _t19*(-0.1e1 / 0.2e1*_t1297 + _t1361) + (0.2e1 / 0.3e1)*_t190*_t20*_t71;
  const double _t1365 = _hc2[3]*_t620;
  const double _t1366 = _t1325*_t4;
  const double _t1367 = (0.1e1 / 0.12e2)*_t1366;
  const double _t1368 = _t152*_t606;
  const double _t1369 = _hc1[15]*_t1368 - _hc1[26]*_t1367;
  const double _t1370 = _hc1[4]*_t620;
  const double _t1371 = _hc1[14]*_t1368 - _hc1[25]*_t1367;
  const double _t1372 = _hc1[17]*_t1368 - _hc1[29]*_t1367;
  const double _t1373 = -0.1e1 / 0.9e1*_t1347 + (0.1e1 / 0.9e1)*_t1348;
  const double _t1374 = _t46*_t487;
  const double _t1375 = _t44*_t498;
  const double _t1376 = _t1*(_hc1[0]*(_hc2[1]*_t1364 + _t1120*_t621 - 0.1e1 / 0.2e1*_t1292 + (0.1e1 / 0.2e1)*_t1293 - 0.1e1 / 0.2e1*_t1295 + (0.1e1 / 0.2e1)*_t1296 + _t1308 + _t146*_t477 + _t161*_t434 + _t19*(_hc2[4]*_t620 + _t1117*_t621 - 0.1e1 / 0.2e1*_t1309 + (0.1e1 / 0.2e1)*_t1310 - 0.1e1 / 0.2e1*_t1311 + (0.1e1 / 0.2e1)*_t1312 + _t1313) + _t25*(_t1119*_t621 - 0.1e1 / 0.2e1*_t1314 + (0.1e1 / 0.2e1)*_t1315 - 0.1e1 / 0.2e1*_t1316 + (0.1e1 / 0.2e1)*_t1317 + _t1319 + _t1365) + _t620*_t65) + _hc2[0]*(_hc1[1]*_t1364 + _t1138*_t621 + _t1342 - 0.1e1 / 0.2e1*_t1343 - 0.1e1 / 0.2e1*_t1344 + (0.1e1 / 0.2e1)*_t1345 + (0.1e1 / 0.2e1)*_t1346 + _t1373 + _t146*_t497 - _t15*(_hc1[7]*_t620 + _t1128*_t621 + _t1336 - 0.1e1 / 0.2e1*_t1337 - 0.1e1 / 0.2e1*_t1338 + (0.1e1 / 0.2e1)*_t1339 + (0.1e1 / 0.2e1)*_t1340 + _t1372) + _t161*_t469 + _t19*(_hc1[5]*_t620 + _t1133*_t621 + _t1320 - 0.1e1 / 0.2e1*_t1321 - 0.1e1 / 0.2e1*_t1322 + (0.1e1 / 0.2e1)*_t1323 + (0.1e1 / 0.2e1)*_t1324 + _t1369) + _t25*(_t1137*_t621 + _t1330 - 0.1e1 / 0.2e1*_t1331 - 0.1e1 / 0.2e1*_t1332 + (0.1e1 / 0.2e1)*_t1333 + (0.1e1 / 0.2e1)*_t1334 + _t1370 + _t1371) + _t620*_t89) - 0.1e1 / 0.2e1*_t1350 - 0.1e1 / 0.2e1*_t1351 + (0.1e1 / 0.2e1)*_t1352 + (0.1e1 / 0.2e1)*_t1353 + _t1354 + _t1355*_t166 + _t1356*_t162 + (0.1e1 / 0.2e1)*_t1374 + (0.1e1 / 0.2e1)*_t1375 + _t326*_t626 + _t424*_t622) + _t1357 + 0.2e1*_t623 + 0.2e1*_t627 + _t628 + _t629 + _t641;
  const double _t1377 = 0.4e1*_t162;
  const double _t1378 = 0.2e1*_t161;
  const double _t1380 = _hc4[15]*_t1379 + _t1298*_t478;
  const double _t1381 = _hc4[17]*_t1379 + _hc4[7]*_t190*_t478;
  const double _t1382 = (0.2e1 / 0.9e1)*_t1305 + _t606*_t76;
  const double _t1383 = -_t1302 - _t1382 - _t15*(-_t1303 + _t1381) + _t19*(-_t1297 + _t1380) + (0.4e1 / 0.3e1)*_t190*_t20*_t71;
  const double _t1384 = _hc2[3]*_t634;
  const double _t1385 = (0.1e1 / 0.6e1)*_t1366;
  const double _t1386 = _t164*_t606;
  const double _t1387 = _hc1[15]*_t1386 - _hc1[26]*_t1385;
  const double _t1388 = _hc1[4]*_t634;
  const double _t1389 = _hc1[14]*_t1386 - _hc1[25]*_t1385;
  const double _t1390 = _hc1[17]*_t1386 - _hc1[29]*_t1385;
  const double _t1391 = -0.2e1 / 0.9e1*_t1347 + (0.2e1 / 0.9e1)*_t1348;
  const double _t1392 = _t1162*_t606;
  const double _t1393 = _hc2[4]*_t1392;
  const double _t1394 = _t198*_t7/xc_powr(_t1, 17, 3);
  const double _t1395 = _hc2[7]*_t1394;
  const double _t1396 = _t192*_t336;
  const double _t1397 = _t199*_t876;
  const double _t1398 = _t191*_t339;
  const double _t1399 = _t1301 - 0.1e1 / 0.4e1*_t1398;
  const double _t1400 = _t1162*_t1298;
  const double _t1401 = _t191*_t344;
  const double _t1402 = -0.1e1 / 0.3e1*_t106*_t190*_t20 + _t1306 + _t15*(_t1304 - 0.1e1 / 0.4e1*_t1401);
  const double _t1403 = _t1399*_t19 - 0.1e1 / 0.2e1*_t1400 - _t1402;
  const double _t1404 = _t1160*_t43;
  const double _t1405 = _t192*_t329;
  const double _t1406 = _t199*_t867;
  const double _t1407 = _t192*_t330;
  const double _t1408 = _t199*_t868;
  const double _t1409 = _t1151*_t43;
  const double _t1410 = _hc2[4]*_t648 - 0.1e1 / 0.4e1*_t1405 + (0.1e1 / 0.4e1)*_t1406 - 0.1e1 / 0.4e1*_t1407 + (0.1e1 / 0.4e1)*_t1408 + _t1409;
  const double _t1411 = _t192*_t333;
  const double _t1412 = _t199*_t873;
  const double _t1413 = _t192*_t334;
  const double _t1414 = _t199*_t874;
  const double _t1415 = _hc2[3]*_t648;
  const double _t1416 = _t1157*_t43;
  const double _t1417 = -0.1e1 / 0.4e1*_t1411 + (0.1e1 / 0.4e1)*_t1412 - 0.1e1 / 0.4e1*_t1413 + (0.1e1 / 0.4e1)*_t1414 + _t1415 + _t1416;
  const double _t1418 = _t1191*_t43;
  const double _t1419 = _t192*_t363;
  const double _t1420 = _t192*_t362;
  const double _t1421 = _t199*_t910;
  const double _t1422 = _t199*_t909;
  const double _t1423 = _hc1[5]*_t648 + _t1328 + _t1418 - 0.1e1 / 0.4e1*_t1419 - 0.1e1 / 0.4e1*_t1420 + (0.1e1 / 0.4e1)*_t1421 + (0.1e1 / 0.4e1)*_t1422;
  const double _t1424 = _hc1[4]*_t648;
  const double _t1425 = _t1199*_t43;
  const double _t1426 = _t192*_t369;
  const double _t1427 = _t192*_t368;
  const double _t1428 = _t199*_t926;
  const double _t1429 = _t199*_t925;
  const double _t1430 = _t1335 + _t1424 + _t1425 - 0.1e1 / 0.4e1*_t1426 - 0.1e1 / 0.4e1*_t1427 + (0.1e1 / 0.4e1)*_t1428 + (0.1e1 / 0.4e1)*_t1429;
  const double _t1431 = _t1196*_t43;
  const double _t1432 = _hc1[11]*_t1394;
  const double _t1433 = _hc1[5]*_t1392;
  const double _t1434 = _t192*_t367;
  const double _t1435 = _t199*_t924;
  const double _t1436 = _t1179*_t43;
  const double _t1437 = _t192*_t356;
  const double _t1438 = _t192*_t355;
  const double _t1439 = _t199*_t917;
  const double _t1440 = _t199*_t916;
  const double _t1441 = _t1349 - _t15*(_hc1[7]*_t648 + _t1341 + _t1436 - 0.1e1 / 0.4e1*_t1437 - 0.1e1 / 0.4e1*_t1438 + (0.1e1 / 0.4e1)*_t1439 + (0.1e1 / 0.4e1)*_t1440);
  const double _t1442 = _t110*_t195;
  const double _t1443 = _t118*_t193;
  const double _t1444 = _t110*_t204;
  const double _t1445 = _t118*_t200;
  const double _t1446 = _t44*_t540 + _t46*_t524;
  const double _t1447 = _t1*(_hc1[0]*(_hc2[1]*_t1403 + _t103*_t594 + _t1294*_t516 - 0.1e1 / 0.2e1*_t1393 + (0.1e1 / 0.2e1)*_t1395 - 0.1e1 / 0.4e1*_t1396 + (0.1e1 / 0.4e1)*_t1397 + _t1404 + _t1410*_t19 + _t1417*_t25) + _hc2[0]*(_hc1[1]*_t1403 + _t115*_t594 + _t1294*_t532 + _t1423*_t19 + _t1430*_t25 + _t1431 + (0.1e1 / 0.2e1)*_t1432 - 0.1e1 / 0.2e1*_t1433 - 0.1e1 / 0.4e1*_t1434 + (0.1e1 / 0.4e1)*_t1435 + _t1441) + _t1355*_t179 + _t1356*_t175 - 0.1e1 / 0.4e1*_t1442 - 0.1e1 / 0.4e1*_t1443 + (0.1e1 / 0.4e1)*_t1444 + (0.1e1 / 0.4e1)*_t1445 + _t1446 + _t26*_t657 + _t29*_t650 + _t35*_t609 + _t37*_t596) + _t616 + _t666;
  const double _t1448 = _t1361 - 0.1e1 / 0.2e1*_t1398;
  const double _t1449 = -0.2e1 / 0.3e1*_t106*_t190*_t20 + _t1363 + _t15*(_t1362 - 0.1e1 / 0.2e1*_t1401);
  const double _t1450 = -_t1400 + _t1448*_t19 - _t1449;
  const double _t1451 = _hc2[4]*_t668 + _t1207*_t621 - 0.1e1 / 0.2e1*_t1405 + (0.1e1 / 0.2e1)*_t1406 - 0.1e1 / 0.2e1*_t1407 + (0.1e1 / 0.2e1)*_t1408 + _t1409;
  const double _t1452 = _hc2[3]*_t668;
  const double _t1453 = _t1209*_t621 - 0.1e1 / 0.2e1*_t1411 + (0.1e1 / 0.2e1)*_t1412 - 0.1e1 / 0.2e1*_t1413 + (0.1e1 / 0.2e1)*_t1414 + _t1416 + _t1452;
  const double _t1454 = _hc1[5]*_t668 + _t1223*_t621 + _t1369 + _t1418 - 0.1e1 / 0.2e1*_t1419 - 0.1e1 / 0.2e1*_t1420 + (0.1e1 / 0.2e1)*_t1421 + (0.1e1 / 0.2e1)*_t1422;
  const double _t1455 = _hc1[4]*_t668;
  const double _t1456 = _t1227*_t621 + _t1371 + _t1425 - 0.1e1 / 0.2e1*_t1426 - 0.1e1 / 0.2e1*_t1427 + (0.1e1 / 0.2e1)*_t1428 + (0.1e1 / 0.2e1)*_t1429 + _t1455;
  const double _t1457 = _t1373 - _t15*(_hc1[7]*_t668 + _t1219*_t621 + _t1372 + _t1436 - 0.1e1 / 0.2e1*_t1437 - 0.1e1 / 0.2e1*_t1438 + (0.1e1 / 0.2e1)*_t1439 + (0.1e1 / 0.2e1)*_t1440);
  const double _t1458 = _t46*_t550;
  const double _t1459 = _t44*_t557;
  const double _t1460 = _t1*(_hc1[0]*(_hc2[1]*_t1450 + _t103*_t620 + _t1211*_t621 - _t1393 + _t1395 - 0.1e1 / 0.2e1*_t1396 + (0.1e1 / 0.2e1)*_t1397 + _t1404 + _t1451*_t19 + _t1453*_t25 + _t146*_t545 + _t161*_t516) + _hc2[0]*(_hc1[1]*_t1450 + _t115*_t620 + _t1226*_t621 + _t1431 + _t1432 - _t1433 - 0.1e1 / 0.2e1*_t1434 + (0.1e1 / 0.2e1)*_t1435 + _t1454*_t19 + _t1456*_t25 + _t1457 + _t146*_t554 + _t161*_t532) - 0.1e1 / 0.2e1*_t1442 - 0.1e1 / 0.2e1*_t1443 + (0.1e1 / 0.2e1)*_t1444 + (0.1e1 / 0.2e1)*_t1445 + _t1446 + (0.1e1 / 0.2e1)*_t1458 + (0.1e1 / 0.2e1)*_t1459 + _t147*_t186 + _t156*_t184 + _t162*_t179 + _t166*_t175 + _t26*_t671 + _t29*_t669 + _t35*_t626 + _t37*_t622) + _t631 + _t676;
  const double _t1461 = _t1380 - _t1398;
  const double _t1462 = -0.4e1 / 0.3e1*_t106*_t190*_t20 + _t1382 + _t15*(_t1381 - _t1401);
  const double _t1463 = -0.2e1*_t1400 + _t1461*_t19 - _t1462;
  const double _t1464 = _hc2[4]*_t678 + _t1207*_t635 - _t1405 + _t1406 - _t1407 + _t1408;
  const double _t1465 = _hc2[3]*_t678;
  const double _t1466 = _t1209*_t635 - _t1411 + _t1412 - _t1413 + _t1414 + _t1465;
  const double _t1467 = _hc1[5]*_t678 + _t1223*_t635 + _t1387 - _t1419 - _t1420 + _t1421 + _t1422;
  const double _t1468 = _hc1[4]*_t678;
  const double _t1469 = _t1227*_t635 + _t1389 - _t1426 - _t1427 + _t1428 + _t1429 + _t1468;
  const double _t1470 = _t1391 - _t15*(_hc1[7]*_t678 + _t1219*_t635 + _t1390 - _t1437 - _t1438 + _t1439 + _t1440);
  const double _t1471 = _t192*_t382;
  const double _t1472 = _t199*_t960;
  const double _t1473 = 0.2e1*_t174;
  const double _t1474 = _t192*_t383;
  const double _t1475 = _t199*_t961;
  const double _t1476 = _t191*_t385;
  const double _t1477 = _t1399*_t33 - _t1402 - 0.1e1 / 0.4e1*_t1476;
  const double _t1478 = _t1250*_t43;
  const double _t1479 = _t1255*_t43;
  const double _t1480 = _t192*_t395;
  const double _t1481 = _t192*_t396;
  const double _t1482 = _t199*_t986;
  const double _t1483 = _t199*_t987;
  const double _t1484 = _t128*_t195;
  const double _t1485 = _t130*_t193;
  const double _t1486 = _t128*_t204;
  const double _t1487 = _t130*_t200;
  const double _t1488 = _t44*_t575 + _t46*_t571;
  const double _t1489 = 0.2e1*_t663 + 0.2e1*_t664;
  const double _t1490 = _t1*(_hc1[0]*(_hc2[1]*_t1477 + _t103*_t648 + _t1410*_t33 + _t1417*_t34 - 0.1e1 / 0.4e1*_t1471 + (0.1e1 / 0.4e1)*_t1472 + _t1473*_t516 - 0.1e1 / 0.4e1*_t1474 + (0.1e1 / 0.4e1)*_t1475 + _t1478) + _hc2[0]*(_hc1[1]*_t1477 + _t115*_t648 + _t1423*_t33 + _t1430*_t34 + _t1441 + _t1473*_t532 + _t1479 - 0.1e1 / 0.4e1*_t1480 - 0.1e1 / 0.4e1*_t1481 + (0.1e1 / 0.4e1)*_t1482 + (0.1e1 / 0.4e1)*_t1483) + _t134*_t657 - 0.1e1 / 0.4e1*_t1484 - 0.1e1 / 0.4e1*_t1485 + (0.1e1 / 0.4e1)*_t1486 + (0.1e1 / 0.4e1)*_t1487 + _t1488 + 0.4e1*_t175*_t179 + _t564*_t650) + _t1489 + 0.2e1*_t651 + 0.2e1*_t658 + _t675;
  const double _t1491 = _t1448*_t33 - _t1449 - 0.1e1 / 0.2e1*_t1476;
  const double _t1492 = _t46*_t580;
  const double _t1493 = _t44*_t582;
  const double _t1494 = _t1*(_hc1[0]*(_hc2[1]*_t1491 + _t103*_t668 + _t1271*_t621 + _t1451*_t33 + _t1453*_t34 - 0.1e1 / 0.2e1*_t1471 + (0.1e1 / 0.2e1)*_t1472 - 0.1e1 / 0.2e1*_t1474 + (0.1e1 / 0.2e1)*_t1475 + _t1478 + _t174*_t545 + _t183*_t516) + _hc2[0]*(_hc1[1]*_t1491 + _t115*_t668 + _t1274*_t621 + _t1454*_t33 + _t1456*_t34 + _t1457 + _t1479 - 0.1e1 / 0.2e1*_t1480 - 0.1e1 / 0.2e1*_t1481 + (0.1e1 / 0.2e1)*_t1482 + (0.1e1 / 0.2e1)*_t1483 + _t174*_t554 + _t183*_t532) + _t134*_t671 - 0.1e1 / 0.2e1*_t1484 - 0.1e1 / 0.2e1*_t1485 + (0.1e1 / 0.2e1)*_t1486 + (0.1e1 / 0.2e1)*_t1487 + _t1488 + (0.1e1 / 0.2e1)*_t1492 + (0.1e1 / 0.2e1)*_t1493 + _t175*_t684 + _t179*_t683 + _t564*_t669) + _t1489 + 0.2e1*_t670 + 0.2e1*_t672 + _t673 + _t674 + _t685;
  const double _t1495 = 0.4e1*_t184;
  const double _t1496 = 0.2e1*_t183;
  const double _t1497 = _t1461*_t33 - _t1462 - _t1476;
  const double _t1498 = _t26*_t689;
  const double _t1499 = _t26*_t705;
  const double _t1500 = _hc1[4]*_t26;
  const double _t1501 = _t29*_t689;
  const double _t1502 = _hc2[3]*_t29;
  const double _t1503 = _t29*_t701;
  const double _t1504 = _t147*_t195;
  const double _t1505 = _t147*_t204;
  const double _t1506 = _t156*_t193;
  const double _t1507 = _t156*_t200;
  const double _t1508 = _t46*_t596;
  const double _t1509 = _t44*_t609;
  const double _t1510 = (0.3e1 / 0.8e1)*_t689;
  const double _t1511 = _t700*_t768;
  const double _t1512 = _t700*_t769;
  const double _t1513 = _t21*_t688;
  const double _t1514 = _hc4[7]*_t688;
  const double _t1515 = _t151*_t1514;
  const double _t1516 = (0.1e1 / 0.2e1)*_t1513 + (0.1e1 / 0.16e2)*_t1515;
  const double _t1517 = (0.3e1 / 0.8e1)*_hc4[5]*_t10*_t19*_t688 - _t1516;
  const double _t1518 = _t192*_t433;
  const double _t1519 = _t1318*_t43;
  const double _t1520 = _t1061*_t199;
  const double _t1521 = _t192*_t468;
  const double _t1522 = _t700*_t856;
  const double _t1523 = _t700*_t855;
  const double _t1524 = _t1329*_t43;
  const double _t1525 = _t1101*_t199;
  const double _t1526 = _hc1[7]*_hc4[1]*_t688;
  const double _t1527 = _t151*_t1526;
  const double _t1528 = _hc1[25]*_t190*_t698*_t806;
  const double _t1529 = _t1528*_t4;
  const double _t1530 = _t197*_t604*_t693;
  const double _t1531 = _t1530*_t4;
  const double _t1532 = -0.1e1 / 0.16e2*_t1527 - 0.1e1 / 0.48e2*_t1529 + (0.1e1 / 0.16e2)*_t1531;
  const double _t1533 = _t1*(_hc1[0]*(_hc2[1]*_t1517 + _t1510*_t63 + _t1510*_t64 + (0.1e1 / 0.8e1)*_t1511 + (0.1e1 / 0.8e1)*_t1512 - 0.3e1 / 0.4e1*_t1518 + (0.3e1 / 0.2e1)*_t1519 + (0.3e1 / 0.4e1)*_t1520 - _t232*_t696 - _t233*_t696) + _hc2[0]*(_hc1[1]*_t1517 + _t1510*_t87 + _t1510*_t88 - 0.3e1 / 0.4e1*_t1521 + (0.1e1 / 0.8e1)*_t1522 + (0.1e1 / 0.8e1)*_t1523 + (0.3e1 / 0.2e1)*_t1524 + (0.3e1 / 0.4e1)*_t1525 + _t1532 - _t291*_t696 - _t292*_t696) + _t1498*_t691 + (0.1e1 / 0.8e1)*_t1499 - _t1500*_t696 + _t1501*_t687 - _t1502*_t696 + (0.1e1 / 0.8e1)*_t1503 - 0.3e1 / 0.4e1*_t1504 + (0.3e1 / 0.4e1)*_t1505 - 0.3e1 / 0.4e1*_t1506 + (0.3e1 / 0.4e1)*_t1507 + (0.3e1 / 0.2e1)*_t1508 + (0.3e1 / 0.2e1)*_t1509) + _t709;
  const double _t1534 = _t1513 + (0.1e1 / 0.8e1)*_t1515;
  const double _t1535 = (0.3e1 / 0.4e1)*_hc4[5]*_t10*_t19*_t688 - _t1534;
  const double _t1536 = _t1365*_t43;
  const double _t1537 = _t192*_t476;
  const double _t1538 = _t1119*_t199;
  const double _t1539 = (0.3e1 / 0.4e1)*_t689;
  const double _t1540 = -_t1518 + _t1520;
  const double _t1541 = _t1370*_t43;
  const double _t1542 = _t192*_t496;
  const double _t1543 = _t1137*_t199;
  const double _t1544 = -_t1521 + _t1525;
  const double _t1545 = -0.1e1 / 0.8e1*_t1527 - _t1528*_t603 + (0.1e1 / 0.8e1)*_t1531;
  const double _t1546 = _t46*_t622;
  const double _t1547 = _t44*_t626;
  const double _t1548 = _t162*_t195;
  const double _t1549 = _t166*_t193;
  const double _t1550 = _t162*_t204;
  const double _t1551 = _t166*_t200;
  const double _t1552 = -_t1504 + _t1505 - _t1506 + _t1507;
  const double _t1553 = _t1*(_hc1[0]*(_hc2[1]*_t1535 + (0.1e1 / 0.4e1)*_t1511 + (0.1e1 / 0.4e1)*_t1512 + _t1519 + _t1536 - 0.1e1 / 0.4e1*_t1537 + (0.1e1 / 0.4e1)*_t1538 + _t1539*_t63 + _t1539*_t64 + _t1540 - _t232*_t713 - _t233*_t713) + _hc2[0]*(_hc1[1]*_t1535 + (0.1e1 / 0.4e1)*_t1522 + (0.1e1 / 0.4e1)*_t1523 + _t1524 + _t1539*_t87 + _t1539*_t88 + _t1541 - 0.1e1 / 0.4e1*_t1542 + (0.1e1 / 0.4e1)*_t1543 + _t1544 + _t1545 - _t291*_t713 - _t292*_t713) + _t1498*_t712 + (0.1e1 / 0.4e1)*_t1499 - _t1500*_t713 + _t1501*_t711 - _t1502*_t713 + (0.1e1 / 0.4e1)*_t1503 + _t1508 + _t1509 + _t1546 + _t1547 - 0.1e1 / 0.4e1*_t1548 - 0.1e1 / 0.4e1*_t1549 + (0.1e1 / 0.4e1)*_t1550 + (0.1e1 / 0.4e1)*_t1551 + _t1552) + _t714;
  const double _t1554 = 0.2e1*_t1513 + (0.1e1 / 0.4e1)*_t1515;
  const double _t1555 = (0.3e1 / 0.2e1)*_hc4[5]*_t10*_t19*_t688 - _t1554;
  const double _t1556 = (0.3e1 / 0.2e1)*_t689;
  const double _t1557 = -0.1e1 / 0.4e1*_t1527 - 0.1e1 / 0.12e2*_t1529 + (0.1e1 / 0.4e1)*_t1531;
  const double _t1558 = _t46*_t636;
  const double _t1559 = _t44*_t639;
  const double _t1560 = _t1*(_hc1[0]*(_hc2[1]*_t1555 + _t1384*_t621 + (0.1e1 / 0.2e1)*_t1511 + (0.1e1 / 0.2e1)*_t1512 + 0.2e1*_t1536 - _t1537 + _t1538 + _t1540 + _t1556*_t63 + _t1556*_t64 - _t232*_t718 - _t233*_t718) + _hc2[0]*(_hc1[1]*_t1555 + _t1388*_t621 + (0.1e1 / 0.2e1)*_t1522 + (0.1e1 / 0.2e1)*_t1523 + 0.2e1*_t1541 - _t1542 + _t1543 + _t1544 + _t1556*_t87 + _t1556*_t88 + _t1557 - _t291*_t718 - _t292*_t718) + _t1498*_t717 + (0.1e1 / 0.2e1)*_t1499 - _t1500*_t718 + _t1501*_t716 - _t1502*_t718 + (0.1e1 / 0.2e1)*_t1503 + 0.2e1*_t1546 + 0.2e1*_t1547 - _t1548 - _t1549 + _t1550 + _t1551 + _t1552 + (0.1e1 / 0.2e1)*_t1558 + (0.1e1 / 0.2e1)*_t1559) + _t719;
  const double _t1561 = _hc1[1]*_t689;
  const double _t1562 = _hc1[4]*_t695;
  const double _t1563 = _hc2[1]*_t689;
  const double _t1564 = _hc2[3]*_t695;
  const double _t1565 = 0.3e1*_t689;
  const double _t1567 = 0.4e1*_t1513 + _t1514*_t1566;
  const double _t1568 = 0.3e1*_hc4[5]*_t10*_t19*_t688 - _t1567;
  const double _t1569 = 0.3e1*_t43;
  const double _t1570 = -_t1526*_t1566 - 0.1e1 / 0.6e1*_t1529 + _t1530*_t5;
  const double _t1571 = _t35*_t689;
  const double _t1572 = _t35*_t705;
  const double _t1573 = _hc1[4]*_t35;
  const double _t1574 = _t37*_t689;
  const double _t1575 = _hc2[3]*_t37;
  const double _t1576 = _t37*_t701;
  const double _t1577 = _t175*_t195;
  const double _t1578 = _t175*_t204;
  const double _t1579 = _t179*_t193;
  const double _t1580 = _t179*_t200;
  const double _t1581 = _t46*_t650;
  const double _t1582 = _t44*_t657;
  const double _t1583 = _t700*_t873;
  const double _t1584 = _t700*_t874;
  const double _t1585 = (0.3e1 / 0.8e1)*_hc4[5]*_t10*_t33*_t688 - _t1516;
  const double _t1586 = _t192*_t515;
  const double _t1587 = _t1415*_t43;
  const double _t1588 = _t1157*_t199;
  const double _t1589 = _t192*_t531;
  const double _t1590 = _t700*_t926;
  const double _t1591 = _t700*_t925;
  const double _t1592 = _t1424*_t43;
  const double _t1593 = _t1199*_t199;
  const double _t1594 = _t1*(_hc1[0]*(_hc2[1]*_t1585 + _t101*_t1510 + _t102*_t1510 + (0.1e1 / 0.8e1)*_t1583 + (0.1e1 / 0.8e1)*_t1584 - 0.3e1 / 0.4e1*_t1586 + (0.3e1 / 0.2e1)*_t1587 + (0.3e1 / 0.4e1)*_t1588 - _t333*_t696 - _t334*_t696) + _hc2[0]*(_hc1[1]*_t1585 + _t113*_t1510 + _t114*_t1510 + _t1532 - 0.3e1 / 0.4e1*_t1589 + (0.1e1 / 0.8e1)*_t1590 + (0.1e1 / 0.8e1)*_t1591 + (0.3e1 / 0.2e1)*_t1592 + (0.3e1 / 0.4e1)*_t1593 - _t368*_t696 - _t369*_t696) + _t1571*_t691 + (0.1e1 / 0.8e1)*_t1572 - _t1573*_t696 + _t1574*_t687 - _t1575*_t696 + (0.1e1 / 0.8e1)*_t1576 - 0.3e1 / 0.4e1*_t1577 + (0.3e1 / 0.4e1)*_t1578 - 0.3e1 / 0.4e1*_t1579 + (0.3e1 / 0.4e1)*_t1580 + (0.3e1 / 0.2e1)*_t1581 + (0.3e1 / 0.2e1)*_t1582) + _t709;
  const double _t1595 = (0.3e1 / 0.4e1)*_hc4[5]*_t10*_t33*_t688 - _t1534;
  const double _t1596 = _t1452*_t43;
  const double _t1597 = _t192*_t544;
  const double _t1598 = _t1209*_t199;
  const double _t1599 = -_t1586 + _t1588;
  const double _t1600 = _t1455*_t43;
  const double _t1601 = _t192*_t553;
  const double _t1602 = _t1227*_t199;
  const double _t1603 = -_t1589 + _t1593;
  const double _t1604 = _t46*_t669;
  const double _t1605 = _t44*_t671;
  const double _t1606 = _t184*_t195;
  const double _t1607 = _t186*_t193;
  const double _t1608 = _t184*_t204;
  const double _t1609 = _t186*_t200;
  const double _t1610 = -_t1577 + _t1578 - _t1579 + _t1580;
  const double _t1611 = _t1*(_hc1[0]*(_hc2[1]*_t1595 + _t101*_t1539 + _t102*_t1539 + (0.1e1 / 0.4e1)*_t1583 + (0.1e1 / 0.4e1)*_t1584 + _t1587 + _t1596 - 0.1e1 / 0.4e1*_t1597 + (0.1e1 / 0.4e1)*_t1598 + _t1599 - _t333*_t713 - _t334*_t713) + _hc2[0]*(_hc1[1]*_t1595 + _t113*_t1539 + _t114*_t1539 + _t1545 + (0.1e1 / 0.4e1)*_t1590 + (0.1e1 / 0.4e1)*_t1591 + _t1592 + _t1600 - 0.1e1 / 0.4e1*_t1601 + (0.1e1 / 0.4e1)*_t1602 + _t1603 - _t368*_t713 - _t369*_t713) + _t1571*_t712 + (0.1e1 / 0.4e1)*_t1572 - _t1573*_t713 + _t1574*_t711 - _t1575*_t713 + (0.1e1 / 0.4e1)*_t1576 + _t1581 + _t1582 + _t1604 + _t1605 - 0.1e1 / 0.4e1*_t1606 - 0.1e1 / 0.4e1*_t1607 + (0.1e1 / 0.4e1)*_t1608 + (0.1e1 / 0.4e1)*_t1609 + _t1610) + _t714;
  const double _t1612 = (0.3e1 / 0.2e1)*_hc4[5]*_t10*_t33*_t688 - _t1554;
  const double _t1613 = _t46*_t679;
  const double _t1614 = _t44*_t681;
  const double _t1615 = _t1*(_hc1[0]*(_hc2[1]*_t1612 + _t101*_t1556 + _t102*_t1556 + _t1465*_t621 + (0.1e1 / 0.2e1)*_t1583 + (0.1e1 / 0.2e1)*_t1584 + 0.2e1*_t1596 - _t1597 + _t1598 + _t1599 - _t333*_t718 - _t334*_t718) + _hc2[0]*(_hc1[1]*_t1612 + _t113*_t1556 + _t114*_t1556 + _t1468*_t621 + _t1557 + (0.1e1 / 0.2e1)*_t1590 + (0.1e1 / 0.2e1)*_t1591 + 0.2e1*_t1600 - _t1601 + _t1602 + _t1603 - _t368*_t718 - _t369*_t718) + _t1571*_t717 + (0.1e1 / 0.2e1)*_t1572 - _t1573*_t718 + _t1574*_t716 - _t1575*_t718 + (0.1e1 / 0.2e1)*_t1576 + 0.2e1*_t1604 + 0.2e1*_t1605 - _t1606 - _t1607 + _t1608 + _t1609 + _t1610 + (0.1e1 / 0.2e1)*_t1613 + (0.1e1 / 0.2e1)*_t1614) + _t719;
  const double _t1616 = 0.3e1*_hc4[5]*_t10*_t33*_t688 - _t1567;
  const double _t1617 = _hc4[1]*_t10/xc_powr(_t11, 7, 2);
  const double _t1618 = (0.15e2 / 0.16e2)*_t1617;
  const double _t1619 = _hc1[0]*_hc2[1];
  const double _t1620 = _hc1[1]*_hc2[0];
  const double _t1621 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]) * (_hc4[1]))*_t693*_t806;
  const double _t1622 = _hc1[0]*_hc2[10]*_t1621;
  const double _t1623 = _t694/(_t11 * _t11 * _t11);
  const double _t1624 = (0.15e2 / 0.16e2)*_t1623;
  const double _t1625 = _t688*_t699;
  const double _t1626 = (0.3e1 / 0.8e1)*_t1625;
  const double _t1627 = _hc1[0]*_hc2[6];
  const double _t1628 = _t1623*_t202;
  const double _t1629 = (0.9e1 / 0.8e1)*_t1625;
  const double _t1630 = _hc1[1]*_hc2[3];
  const double _t1631 = _hc1[1]*_hc2[6]*_t1621;
  const double _t1632 = _hc1[10]*_hc2[0];
  const double _t1633 = _hc1[10]*_hc2[1]*_t1621;
  const double _t1634 = _hc1[20]*_hc2[0]*_t1621;
  const double _t1635 = _hc1[4]*_hc2[1];
  const double _t1636 = _hc1[4]*_hc2[3]*_t1621;
  const double _t1637 = _t1*(-_t1618*_t1619 - _t1618*_t1620 + (0.1e1 / 0.16e2)*_t1622 + _t1624*_t697 + _t1624*_t707 - _t1626*_t1627 - _t1626*_t1632 + (0.15e2 / 0.8e1)*_t1628 - _t1629*_t1630 - _t1629*_t1635 + (0.1e1 / 0.4e1)*_t1631 + (0.1e1 / 0.4e1)*_t1633 + (0.1e1 / 0.16e2)*_t1634 + (0.3e1 / 0.8e1)*_t1636);
  const double _t1638 = (0.15e2 / 0.8e1)*_t1617;
  const double _t1639 = (0.15e2 / 0.8e1)*_t1623;
  const double _t1640 = (0.3e1 / 0.4e1)*_t1625;
  const double _t1641 = (0.9e1 / 0.4e1)*_t1625;
  const double _t1642 = _t1*(-_t1619*_t1638 - _t1620*_t1638 + (0.1e1 / 0.8e1)*_t1622 - _t1627*_t1640 + (0.15e2 / 0.4e1)*_t1628 - _t1630*_t1641 + (0.1e1 / 0.2e1)*_t1631 - _t1632*_t1640 + (0.1e1 / 0.2e1)*_t1633 + (0.1e1 / 0.8e1)*_t1634 - _t1635*_t1641 + (0.3e1 / 0.4e1)*_t1636 + _t1639*_t697 + _t1639*_t707);
  const double _t1643 = (0.15e2 / 0.4e1)*_t1617;
  const double _t1644 = (0.15e2 / 0.4e1)*_t1623;
  const double _t1645 = (0.3e1 / 0.2e1)*_t1625;
  const double _t1646 = (0.9e1 / 0.2e1)*_t1625;
  const double _t1647 = _t1*(-_t1619*_t1643 - _t1620*_t1643 + (0.1e1 / 0.4e1)*_t1622 - _t1627*_t1645 + (0.15e2 / 0.2e1)*_t1628 - _t1630*_t1646 + _t1631 - _t1632*_t1645 + _t1633 + (0.1e1 / 0.4e1)*_t1634 - _t1635*_t1646 + (0.3e1 / 0.2e1)*_t1636 + _t1644*_t697 + _t1644*_t707);
  const double _t1648 = (0.15e2 / 0.2e1)*_t1617;
  const double _t1649 = (0.15e2 / 0.2e1)*_t1623;
  const double _t1650 = 0.3e1*_t1625;
  const double _t1651 = 0.9e1*_t1625;
  const double _t1652 = _t1*(-_t1619*_t1648 - _t1620*_t1648 + (0.1e1 / 0.2e1)*_t1622 - _t1627*_t1650 + 0.15e2*_t1628 - _t1630*_t1651 + 0.2e1*_t1631 - _t1632*_t1650 + 0.2e1*_t1633 + (0.1e1 / 0.2e1)*_t1634 - _t1635*_t1651 + 0.3e1*_t1636 + _t1649*_t697 + _t1649*_t707);
  const double _t1653 = 0.15e2*_t1617;
  const double _t1654 = 0.15e2*_t1623;
  const double _t1655 = 0.6e1*_t1625;
  const double _t1656 = 0.18e2*_t1625;
  const double d4F_dna4 = _t1*(_hc1[0]*(_hc2[1]*_t808 + _hc2[2]*_t734 + _t19*(_hc2[4]*_t265 + _hc2[5]*_t223 + _t19*(_hc2[8]*_t78 + _hc2[9]*_t61 + _t19*(_hc2[13]*_t25 + _hc2[14]*_t19) + _t25*_t759) + _t224*_t226 + _t225*_t229 + _t25*_t765) + _t230*_t738 + _t236*_t755 + _t25*(_t19*_t765 + _t224*_t229 + _t225*_t234 + _t25*(_t19*_t763 + _t25*(_t768 + _t769) + _t767 + _t770) + _t766 + _t771) + _t62*_t736 + _t65*_t756) + _hc2[0]*(_hc1[1]*_t808 + _hc1[2]*_t734 - _t15*(_hc1[7]*_t265 + _hc1[8]*_t223 - _t15*(_hc1[17]*_t78 + _hc1[18]*_t61 - _t15*(_hc1[32]*_t25 + _hc1[33]*_t19 + _t812) + _t19*_t814 + _t25*_t818 + _t811) + _t19*_t826 + _t217*_t272 + _t224*_t274 + _t225*_t278 + _t25*_t834 + _t810) + _t19*(_hc1[5]*_t265 + _hc1[6]*_t223 - _t15*_t826 + _t19*(_hc1[12]*_t78 + _hc1[13]*_t61 - _t15*_t821 + _t19*(_hc1[23]*_t25 + _hc1[24]*_t19 + _t837) + _t25*_t841 + _t836) + _t217*_t274 + _t224*_t282 + _t225*_t286 + _t25*_t849 + _t835) + _t25*(-_t15*_t834 + _t19*_t849 + _t217*_t278 + _t224*_t286 + _t225*_t293 + _t25*(-_t15*_t832 + _t19*_t847 + _t25*(_t854 + _t855 + _t856) + _t852 + _t853 + _t857) + _t850 + _t851 + _t858) + _t279*_t737 + _t287*_t738 + _t295*_t755 - _t735*_t83 + _t736*_t85 + _t756*_t89 + _t809) + _hc3[1]*_t734 - _t15*(_hc3[4]*_t223 - _t15*(_hc3[8]*_t61 - _t15*(_hc3[13]*_t19 + _t742) + _t19*_t744 + _t741) + _t19*_t748 + _t217*_t310 + _t224*_t301 + _t740) + _t19*(_hc3[3]*_t223 - _t15*_t748 + _t19*(_hc3[6]*_t61 - _t15*_t747 + _t19*(_hc3[10]*_t19 + _t752) + _t751) + _t217*_t301 + _t224*_t303 + _t750) + _t266*_t753 + _t296*_t754 + _t304*_t738 + _t311*_t737 + _t730 - _t735*_t98 + _t736*_t94 + 0.6e1*_t79*_t90) + 0.4e1*_t267 + 0.4e1*_t297 + 0.4e1*_t298 + 0.4e1*_t305 + 0.12e2*_t306 + 0.12e2*_t307 - _t311*_t728 + 0.8e1*_t61*_t94 + _t725 + _t726*_t727;
  const double d4F_dna3_dnb = _t1*(_hc1[0]*(_hc2[1]*_t895 + _hc2[2]*_t860 + _t100*_t223 + _t103*_t265 + _t109*_t236 + _t19*(_hc2[4]*_t351 + _hc2[5]*_t313 + _t109*_t229 + _t19*(_hc2[8]*_t109 + _hc2[9]*_t60 + _t19*_t863 + _t25*_t866) + _t226*_t60 + _t25*_t871 + _t328*_t61 + _t331*_t78) + _t224*_t332 + _t225*_t337 + _t230*_t60 + _t25*(_t109*_t234 + _t19*_t871 + _t229*_t60 + _t25*(_hc2[7]*_t60 + _t19*_t869 + _t25*_t875 + _t876) + _t331*_t61 + _t335*_t78 + _t872 + _t877) + _t62*_t861 + _t65*_t862) + _hc2[0]*(_hc1[1]*_t895 + _hc1[2]*_t860 + _t109*_t295 + _t112*_t223 + _t115*_t265 - _t116*_t268 - _t15*(_hc1[7]*_t351 + _hc1[8]*_t313 + _t109*_t278 - _t15*(_hc1[17]*_t109 + _hc1[18]*_t60 + _t19*_t900 + _t25*_t921 + _t931) + _t19*_t902 + _t25*_t923 + _t272*_t55 + _t274*_t60 + _t354*_t61 + _t357*_t78 + _t358*_t55 + _t810) + _t19*(_hc1[5]*_t351 + _hc1[6]*_t313 + _t109*_t286 - _t15*_t902 + _t19*(_hc1[12]*_t109 + _hc1[13]*_t60 + _t19*_t903 + _t25*_t906 + _t907) + _t25*_t913 + _t274*_t55 + _t282*_t60 + _t354*_t55 + _t361*_t61 + _t364*_t78 + _t835) + _t224*_t366 + _t225*_t372 + _t25*(_t109*_t293 - _t15*_t923 + _t19*_t913 + _t25*(_hc1[11]*_t60 + _t19*_t911 + _t25*_t927 + _t924 + _t928) + _t278*_t55 + _t286*_t60 + _t357*_t55 + _t364*_t61 + _t370*_t78 + _t850 + _t914 + _t929) + _t279*_t55 + _t287*_t60 - _t83*_t930 + _t85*_t861 + _t862*_t89 + _t932) + _hc3[1]*_t860 + _t120*_t223 - _t124*_t268 - _t15*(_hc3[4]*_t313 - _t15*(_hc3[8]*_t60 + _t19*_t934 + _t943) + _t19*_t936 + _t301*_t60 + _t310*_t55 + _t316*_t61 + _t317*_t55 + _t740) + _t19*(_hc3[3]*_t313 - _t15*_t936 + _t19*(_hc3[6]*_t60 + _t19*_t937 + _t938) + _t301*_t55 + _t303*_t60 + _t316*_t55 + _t320*_t61 + _t750) + _t224*_t322 + _t266*_t37 + _t296*_t35 + _t304*_t60 + _t311*_t55 + _t352*_t940 + _t373*_t939 - _t726*_t892 + _t79*_t941 + _t861*_t94 + _t90*_t942 + _t944) + _t118*_t945 + (0.10e2 / 0.9e1)*_t20*_t726 + _t211*_t375 - _t213*_t319 + _t29*_t946 + _t312 + 0.3e1*_t314 + 0.3e1*_t315 + 0.3e1*_t323 + 0.3e1*_t325 + 0.3e1*_t327 + 0.3e1*_t353 + 0.3e1*_t374 + _t725 + _t94*_t947;
  const double d4F_dna2_dnb2 = _t1*(_hc1[0]*(_hc2[1]*_t977 + _t100*_t861 + _t103*_t862 + _t19*(_hc2[4]*_t391 - _hc2[5]*_t222 - _hc2[5]*_t59 + _t19*_t956 + _t25*_t959 + _t328*_t379 + _t331*_t380) - _t222*_t62 + _t25*(-_hc2[4]*_t222 - _hc2[4]*_t59 + _t19*_t959 + _t25*_t962 + _t331*_t379 + _t335*_t380 + _t963) + _t332*_t379 + _t337*_t380 + _t381*_t61 + _t384*_t78 + _t391*_t65 - _t59*_t62 + _t955) + _hc2[0]*(_hc1[1]*_t977 + _t112*_t861 + _t115*_t862 - _t116*_t930 - _t15*(_hc1[7]*_t391 - _hc1[8]*_t222 - _hc1[8]*_t59 + _t19*_t983 + _t25*_t991 + _t354*_t379 + _t357*_t380 + _t993) + _t19*(_hc1[5]*_t391 - _hc1[6]*_t222 - _hc1[6]*_t59 + _t19*_t979 + _t25*_t982 + _t361*_t379 + _t364*_t380 + _t984) - _t222*_t85 + _t25*(-_hc1[5]*_t222 - _hc1[5]*_t59 + _t19*_t982 + _t25*_t988 + _t364*_t379 + _t370*_t380 + _t985 + _t992) - _t268*_t83 + _t366*_t379 + _t372*_t380 + _t391*_t89 + _t394*_t61 + _t397*_t78 + _t398*_t55 - _t59*_t85 + _t932 + _t978) + _t110*_t953 + _t120*_t861 + _t128*_t90 + _t130*_t79 + _t134*_t373 - _t15*(-_hc3[4]*_t222 - _hc3[4]*_t59 + _t19*_t994 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t317 + 0.4e1*_t316*_t58*_t7 - _t739 - _t997) + _t19*(-_hc3[3]*_t222 - _hc3[3]*_t59 + _t19*_t996 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t316 + 0.4e1*_t320*_t58*_t7 - _t749 - _t995) - _t222*_t94 - _t268*_t98 + _t322*_t379 + _t326*_t400 + _t352*_t564 - _t375*_t892 + _t392*_t424 + _t402*_t61 + _t406*_t55 - _t59*_t94 + _t944 + _t954) + _t110*_t753 + _t110*_t952 + _t118*_t754 + _t218 + 0.2e1*_t314 + 0.2e1*_t315 - _t319*_t951 + 0.2e1*_t323 + 0.2e1*_t325 + 0.2e1*_t327 + _t35*_t953 + 0.2e1*_t353 + 0.2e1*_t374 + _t375*_t478 - _t377 + _t379*_t94 + 0.2e1*_t393 + 0.2e1*_t401 + 0.2e1*_t403 + 0.2e1*_t404 + 0.2e1*_t405 - _t406*_t951 - _t7*_t948 + _t725 + _t949*_t950;
  const double d4F_dna_dnb3 = -_hc3[1]*_t219 - _hc3[1]*_t998 + _t1*(_hc1[0]*(_hc2[1]*_t1008 + _hc2[2]*_t859 - _t100*_t219 - _t100*_t998 + _t1000*_t103 + _t1001*_t19 + _t1004*_t25 + _t381*_t947 + _t384*_t999 + _t955) + _hc2[0]*(_hc1[1]*_t1008 + _hc1[2]*_t859 + _t1000*_t115 + _t1009*_t19 + _t1012*_t25 + _t1013 - _t112*_t219 - _t112*_t998 + _t394*_t947 + _t397*_t999 + _t978) + _t1014*_t19 + _t1015 - _t120*_t219 - _t120*_t998 + _t128*_t941 + _t130*_t942 + _t26*_t416 + _t29*_t414 + _t392*_t421 + _t400*_t420 + _t402*_t947 + _t948 + _t954) + _t1016 + _t118*_t423 + 0.12e2*_t120*_t950 + _t37*_t946 + 0.3e1*_t393 + 0.3e1*_t401 + 0.3e1*_t403 + 0.3e1*_t404 + 0.3e1*_t405 + _t422;
  const double d4F_dnb4 = _t1*(_hc1[0]*(_hc2[1]*_t1022 + _hc2[2]*_t1017 + _t100*_t1018 + _t1001*_t33 + _t1004*_t34 + _t1019*_t381 + _t1020*_t384 + _t1021*_t103) + _hc2[0]*(_hc1[1]*_t1022 + _hc1[2]*_t1017 + _t1009*_t33 + _t1012*_t34 + _t1013 + _t1018*_t112 + _t1019*_t394 + _t1020*_t397 + _t1021*_t115) + _hc3[1]*_t1017 + _t1014*_t33 + _t1015 + _t1018*_t120 + _t1019*_t402 + 0.6e1*_t128*_t130 + 0.4e1*_t35*_t416 + _t414*_t952) + _t1016 + _t126*_t949 + 0.12e2*_t128*_t37 + 0.12e2*_t130*_t35 + 0.4e1*_t415 + 0.4e1*_t417 + 0.4e1*_t418 + 0.4e1*_t419;
  const double d4F_dna3_dgaa = _t1104;
  const double d4F_dna3_dgab = _t1*(_hc1[0]*(_hc2[1]*_t1116 + _t1028 + _t1030 + _t1105*_t65 + _t161*_t236 + _t19*(_hc2[4]*_t486 + _t1050 + _t1057 + _t1118*_t25 + _t161*_t229 + _t19*(_hc2[8]*_t161 + _t1051 + _t1052)) + _t224*_t475 + _t225*_t477 + _t25*(_t1058 + _t1062 + _t1118*_t19 + _t1120 + _t161*_t234 + _t25*(_t1059 + _t1060 + _t1119))) + _hc2[0]*(_hc1[1]*_t1116 + _t1066 + _t1067 + _t1105*_t89 + _t1121 - _t15*(_hc1[7]*_t486 + _t1071 + _t1084 + _t1123 + _t1126*_t19 + _t1129*_t25 - _t15*(_hc1[17]*_t161 + _t1073 + _t1074 + _t1124) + _t161*_t278) + _t161*_t295 + _t19*(_hc1[5]*_t486 + _t1086 + _t1095 - _t1126*_t15 + _t1130 + _t1134*_t25 + _t161*_t286 + _t19*(_hc1[12]*_t161 + _t1088 + _t1089 + _t1131)) + _t217*_t492 + _t224*_t494 + _t225*_t497 + _t25*(_t1097 + _t1102 - _t1129*_t15 + _t1134*_t19 + _t1135 + _t1138 + _t161*_t293 + _t25*(_t1099 + _t1100 + _t1136 + _t1137))) + _t1024*_t166 + _t1025*_t162 + _t1026 + _t1027 + _t487*_t940 + _t498*_t939) + _t1023*_t162 + _t1024*_t46 + _t1025*_t44 + _t166*_t945 + 0.3e1*_t488 + 0.3e1*_t499;
  const double d4F_dna3_dgbb = _t1104;
  const double d4F_dna2_dnb_dgaa = _t1205;
  const double d4F_dna2_dnb_dgab = _t1*(_hc1[0]*(_hc2[1]*_t1217 + _t103*_t486 + _t109*_t477 + _t1142 + _t1143 + _t161*_t337 + _t19*(_hc2[4]*_t549 + 0.2e1*_t1145 + _t1153 + _t1206*_t19 + _t1208*_t25 + _t161*_t331) + _t25*(0.2e1*_t1154 + _t1159 + _t1208*_t19 + _t1210*_t25 + _t1211 + _t161*_t335) + _t475*_t60 + _t543*_t61 + _t545*_t78 + _t549*_t65) + _hc2[0]*(_hc1[1]*_t1217 + _t109*_t497 + _t1121 + _t115*_t486 + _t1172 + _t1173 - _t15*(_hc1[7]*_t549 + 0.2e1*_t1181 + _t1182 + _t1218*_t19 + _t1220*_t25 + _t1221 + _t161*_t357) + _t161*_t372 + _t19*(_hc1[5]*_t549 + 0.2e1*_t1193 + _t1194 + _t1222*_t19 + _t1224*_t25 + _t1225 + _t161*_t364) + _t25*(0.2e1*_t1201 + _t1202 + _t1224*_t19 + _t1226 + _t1228*_t25 + _t1229 + _t161*_t370) + _t492*_t55 + _t494*_t60 + _t549*_t89 + _t55*_t555 + _t552*_t61 + _t554*_t78) + _t1139*_t162 + _t1140 + _t1141 + _t166*_t324 + _t184*_t90 + _t186*_t79 + _t326*_t557 + _t35*_t498 + _t37*_t487 + _t424*_t550) + _t1230 + _t500;
  const double d4F_dna2_dnb_dgbb = _t1205;
  const double d4F_dna_dnb2_dgaa = _t1263;
  const double d4F_dna_dnb2_dgab = _t1*(_hc1[0]*(_hc2[1]*_t1269 - _hc2[4]*_t1264 + _t103*_t1265 + _t1237 + _t1270*_t19 + _t1272*_t25 + _t161*_t384 + _t379*_t543 + _t380*_t545 - 0.2e1*_t508) + _hc2[0]*(_hc1[1]*_t1269 - _hc1[5]*_t1264 + _t115*_t1265 + _t1259 + _t1273*_t19 + _t1275*_t25 + _t1276 + _t161*_t397 + _t379*_t552 + _t380*_t554 - 0.2e1*_t533) + _t1139*_t184 + _t1231 + _t1232 + _t128*_t166 + _t130*_t162 + _t134*_t557 + _t186*_t324 + _t26*_t582 + _t29*_t580 + _t550*_t564) + _t1230 + _t584;
  const double d4F_dna_dnb2_dgbb = _t1263;
  const double d4F_dnb3_dgaa = _t1289;
  const double d4F_dnb3_dgab = _t1*(_hc1[0]*(_hc2[1]*_t1291 + _t103*_t1290 + _t1270*_t33 + _t1272*_t34 + _t1282 + _t1284 + _t183*_t384 + _t410*_t543 + _t411*_t545) + _hc2[0]*(_hc1[1]*_t1291 + _t115*_t1290 + _t1273*_t33 + _t1275*_t34 + _t1276 + _t1287 + _t1288 + _t183*_t397 + _t410*_t552 + _t411*_t554) + _t1278*_t186 + _t1279*_t184 + _t1280 + _t1281 + _t420*_t582 + _t421*_t580) + _t1277*_t184 + _t1278*_t46 + _t1279*_t44 + _t186*_t423 + 0.3e1*_t581 + 0.3e1*_t583;
  const double d4F_dnb3_dgbb = _t1289;
  const double d4F_dna2_dgaa2 = _t1358;
  const double d4F_dna2_dgaa_dgab = _t1376;
  const double d4F_dna2_dgaa_dgbb = _t1358;
  const double d4F_dna2_dgab2 = _t1*(_hc1[0]*(_hc2[1]*_t1383 + _t1120*_t635 - _t1292 + _t1293 - _t1295 + _t1296 + _t1378*_t477 + _t19*(_hc2[4]*_t634 + _t1117*_t635 - _t1309 + _t1310 - _t1311 + _t1312) + _t25*(_t1119*_t635 - _t1314 + _t1315 - _t1316 + _t1317 + _t1384) + _t634*_t65) + _hc2[0]*(_hc1[1]*_t1383 + _t1138*_t635 - _t1343 - _t1344 + _t1345 + _t1346 + _t1378*_t497 + _t1391 - _t15*(_hc1[7]*_t634 + _t1128*_t635 - _t1337 - _t1338 + _t1339 + _t1340 + _t1390) + _t19*(_hc1[5]*_t634 + _t1133*_t635 - _t1321 - _t1322 + _t1323 + _t1324 + _t1387) + _t25*(_t1137*_t635 - _t1331 - _t1332 + _t1333 + _t1334 + _t1388 + _t1389) + _t634*_t89) - _t1350 - _t1351 + _t1352 + _t1353 + 0.2e1*_t1374 + 0.2e1*_t1375 + _t1377*_t166 + _t326*_t639 + _t424*_t636) + _t1377*_t46 - _t193*_t424 - _t195*_t326 + _t200*_t424 + _t204*_t326 + 0.4e1*_t629 + 0.2e1*_t637 + 0.2e1*_t640;
  const double d4F_dna2_dgab_dgbb = _t1376;
  const double d4F_dna2_dgbb2 = _t1358;
  const double d4F_dna_dnb_dgaa2 = _t1447;
  const double d4F_dna_dnb_dgaa_dgab = _t1460;
  const double d4F_dna_dnb_dgaa_dgbb = _t1447;
  const double d4F_dna_dnb_dgab2 = _t1*(_hc1[0]*(_hc2[1]*_t1463 + _t103*_t634 + _t1211*_t635 + _t1378*_t545 - 0.2e1*_t1393 + 0.2e1*_t1395 - _t1396 + _t1397 + _t1464*_t19 + _t1466*_t25) + _hc2[0]*(_hc1[1]*_t1463 + _t115*_t634 + _t1226*_t635 + _t1378*_t554 + 0.2e1*_t1432 - 0.2e1*_t1433 - _t1434 + _t1435 + _t1467*_t19 + _t1469*_t25 + _t1470) - _t1442 - _t1443 + _t1444 + _t1445 + 0.2e1*_t1458 + 0.2e1*_t1459 + _t162*_t684 + _t166*_t683 + _t26*_t681 + _t29*_t679 + _t35*_t639 + _t37*_t636) + _t642 + _t686;
  const double d4F_dna_dnb_dgab_dgbb = _t1460;
  const double d4F_dna_dnb_dgbb2 = _t1447;
  const double d4F_dnb2_dgaa2 = _t1490;
  const double d4F_dnb2_dgaa_dgab = _t1494;
  const double d4F_dnb2_dgaa_dgbb = _t1490;
  const double d4F_dnb2_dgab2 = _t1*(_hc1[0]*(_hc2[1]*_t1497 + _t103*_t678 + _t1271*_t635 + _t1464*_t33 + _t1466*_t34 - _t1471 + _t1472 - _t1474 + _t1475 + _t1496*_t545) + _hc2[0]*(_hc1[1]*_t1497 + _t115*_t678 + _t1274*_t635 + _t1467*_t33 + _t1469*_t34 + _t1470 - _t1480 - _t1481 + _t1482 + _t1483 + _t1496*_t554) + _t134*_t681 - _t1484 - _t1485 + _t1486 + _t1487 + 0.2e1*_t1492 + 0.2e1*_t1493 + _t1495*_t186 + _t564*_t679) - _t134*_t195 + _t134*_t204 + _t1495*_t46 - _t193*_t564 + _t200*_t564 + 0.4e1*_t674 + 0.2e1*_t680 + 0.2e1*_t682;
  const double d4F_dnb2_dgab_dgbb = _t1494;
  const double d4F_dnb2_dgbb2 = _t1490;
  const double d4F_dna_dgaa3 = _t1533;
  const double d4F_dna_dgaa2_dgab = _t1553;
  const double d4F_dna_dgaa2_dgbb = _t1533;
  const double d4F_dna_dgaa_dgab2 = _t1560;
  const double d4F_dna_dgaa_dgab_dgbb = _t1553;
  const double d4F_dna_dgaa_dgbb2 = _t1533;
  const double d4F_dna_dgab3 = _t1*(_hc1[0]*(_hc2[1]*_t1568 + _t1384*_t1569 + _t1511 + _t1512 - 0.3e1*_t1537 + 0.3e1*_t1538 + _t1565*_t63 + _t1565*_t64 - _t232*_t723 - _t233*_t723) + _hc2[0]*(_hc1[1]*_t1568 + _t1388*_t1569 + _t1522 + _t1523 - 0.3e1*_t1542 + 0.3e1*_t1543 + _t1565*_t87 + _t1565*_t88 + _t1570 - _t291*_t723 - _t292*_t723) + _t1499 + _t1503 - 0.3e1*_t1548 - 0.3e1*_t1549 + 0.3e1*_t1550 + 0.3e1*_t1551 + 0.3e1*_t1558 + 0.3e1*_t1559 + _t1561*_t939 - _t1562*_t939 + _t1563*_t940 - _t1564*_t940) + _t724;
  const double d4F_dna_dgab2_dgbb = _t1560;
  const double d4F_dna_dgab_dgbb2 = _t1553;
  const double d4F_dna_dgbb3 = _t1533;
  const double d4F_dnb_dgaa3 = _t1594;
  const double d4F_dnb_dgaa2_dgab = _t1611;
  const double d4F_dnb_dgaa2_dgbb = _t1594;
  const double d4F_dnb_dgaa_dgab2 = _t1615;
  const double d4F_dnb_dgaa_dgab_dgbb = _t1611;
  const double d4F_dnb_dgaa_dgbb2 = _t1594;
  const double d4F_dnb_dgab3 = _t1*(_hc1[0]*(_hc2[1]*_t1616 + _t101*_t1565 + _t102*_t1565 + _t1465*_t1569 + _t1583 + _t1584 - 0.3e1*_t1597 + 0.3e1*_t1598 - _t333*_t723 - _t334*_t723) + _hc2[0]*(_hc1[1]*_t1616 + _t113*_t1565 + _t114*_t1565 + _t1468*_t1569 + _t1570 + _t1590 + _t1591 - 0.3e1*_t1601 + 0.3e1*_t1602 - _t368*_t723 - _t369*_t723) + _t1561*_t420 - _t1562*_t420 + _t1563*_t421 - _t1564*_t421 + _t1572 + _t1576 - 0.3e1*_t1606 - 0.3e1*_t1607 + 0.3e1*_t1608 + 0.3e1*_t1609 + 0.3e1*_t1613 + 0.3e1*_t1614) + _t724;
  const double d4F_dnb_dgab2_dgbb = _t1615;
  const double d4F_dnb_dgab_dgbb2 = _t1611;
  const double d4F_dnb_dgbb3 = _t1594;
  const double d4F_dgaa4 = _t1637;
  const double d4F_dgaa3_dgab = _t1642;
  const double d4F_dgaa3_dgbb = _t1637;
  const double d4F_dgaa2_dgab2 = _t1647;
  const double d4F_dgaa2_dgab_dgbb = _t1642;
  const double d4F_dgaa2_dgbb2 = _t1637;
  const double d4F_dgaa_dgab3 = _t1652;
  const double d4F_dgaa_dgab2_dgbb = _t1647;
  const double d4F_dgaa_dgab_dgbb2 = _t1642;
  const double d4F_dgaa_dgbb3 = _t1637;
  const double d4F_dgab4 = _t1*(-_t1619*_t1653 - _t1620*_t1653 + _t1622 - _t1627*_t1655 + 0.30e2*_t1628 - _t1630*_t1656 + 0.4e1*_t1631 - _t1632*_t1655 + 0.4e1*_t1633 + _t1634 - _t1635*_t1656 + 0.6e1*_t1636 + _t1654*_t697 + _t1654*_t707);
  const double d4F_dgab3_dgbb = _t1652;
  const double d4F_dgab2_dgbb2 = _t1647;
  const double d4F_dgab_dgbb3 = _t1642;
  const double d4F_dgbb4 = _t1637;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 1] += d4F_dna3_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 2] += d4F_dna3_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 3] += d4F_dna2_dnb_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 4] += d4F_dna2_dnb_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 5] += d4F_dna2_dnb_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 6] += d4F_dna_dnb2_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 7] += d4F_dna_dnb2_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 8] += d4F_dna_dnb2_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 9] += d4F_dnb3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 10] += d4F_dnb3_dgab;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 1] += d4F_dna2_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 2] += d4F_dna2_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 3] += d4F_dna2_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 4] += d4F_dna2_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 7] += d4F_dna_dnb_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 8] += d4F_dna_dnb_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 9] += d4F_dna_dnb_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 10] += d4F_dna_dnb_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 13] += d4F_dnb2_dgaa_dgab;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 14] += d4F_dnb2_dgaa_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 15] += d4F_dnb2_dgab2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 16] += d4F_dnb2_dgab_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 1] += d4F_dna_dgaa2_dgab;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 2] += d4F_dna_dgaa2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 3] += d4F_dna_dgaa_dgab2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 4] += d4F_dna_dgaa_dgab_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 5] += d4F_dna_dgaa_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 6] += d4F_dna_dgab3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 7] += d4F_dna_dgab2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 8] += d4F_dna_dgab_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 11] += d4F_dnb_dgaa2_dgab;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 12] += d4F_dnb_dgaa2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 13] += d4F_dnb_dgaa_dgab2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 14] += d4F_dnb_dgaa_dgab_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 15] += d4F_dnb_dgaa_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 16] += d4F_dnb_dgab3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 17] += d4F_dnb_dgab2_dgbb;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 18] += d4F_dnb_dgab_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 1] += d4F_dgaa3_dgab;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 2] += d4F_dgaa3_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 3] += d4F_dgaa2_dgab2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 4] += d4F_dgaa2_dgab_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 5] += d4F_dgaa2_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 6] += d4F_dgaa_dgab3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 7] += d4F_dgaa_dgab2_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 8] += d4F_dgaa_dgab_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 9] += d4F_dgaa_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 10] += d4F_dgab4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 11] += d4F_dgab3_dgbb;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 12] += d4F_dgab2_dgbb2;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 13] += d4F_dgab_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif