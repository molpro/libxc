/*
  Generated from python/gga_exc/gga_c_zvpbeloc.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_zvpbeloc
*/

#ifndef _GGA_C_ZVPBELOC_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_ZVPBELOC_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_ZVPBELOC_HELPER_BODIES
#include "gga_c_zvpbeloc.c"
#undef _GGA_C_ZVPBELOC_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_ZVPBELOC_HELPER_BODIES
#include "gga_c_zvpbeloc.c"
#undef _GGA_C_ZVPBELOC_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_ZVPBELOC_HELPER_BODIES
#include "gga_c_zvpbeloc.c"
#undef _GGA_C_ZVPBELOC_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_ZVPBELOC_HELPER_BODIES
#include "gga_c_zvpbeloc.c"
#undef _GGA_C_ZVPBELOC_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_ZVPBELOC_HELPER_BODIES
#include "gga_c_zvpbeloc.c"
#undef _GGA_C_ZVPBELOC_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_zvpbeloc.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_ZVPBELOC_HELPER_BODIES)

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

  const double _t1 = (t * t);
  const double _t2 = (rs * rs);
  const double _t3 = xc_expm1(-_t2);
#if _KMAX >= 1
  const double _t4 = 0.16*_t3;
  const double _t5 = _t3 + 0.1e1;
  const double _t6 = _t1*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = 0.32000000000000001*_t5*rs;
#endif
#if _KMAX >= 3
  const double _t8 = 0.64000000000000001*_t2*_t5;
  const double _t9 = 0.95999999999999996*_t6;
  const double _t10 = (rs * rs * rs);
#endif
#if _KMAX >= 4
  const double _t11 = _t5*t;
#endif

  const double f = -0.080000000000000002*_t1*_t3 + 0.037499999999999999;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_t4*t;
  out[1] = df_dt;
  const double df_drs = 0.16*_t6*rs;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_t4;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = _t7*t;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = 0.16*_t1*_t5 - 0.32000000000000001*_t2*_t6;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _t7;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = 0.32000000000000001*_t5*t - _t8*t;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = 0.64000000000000001*_t10*_t6 - _t9*rs;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = 0;
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = 0.32000000000000001*_t3 - _t8 + 0.32000000000000001;
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = 1.28*_t10*_t11 - 1.9199999999999999*_t11*rs;
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = 3.8399999999999999*_t1*_t2*_t5 - 1.28*_t6*(rs * rs * rs * rs) - _t9;
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
  XC_CAT(mbeta_k, _KMAX)(p, rs, t, _hc3);
  const double _t1 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t2 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t3 = (M_PI * M_PI);
  const double _t4 = 0.1e1 - M_LN2;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t3*_t5;
  const double _t7 = _t2*_t6;
  const double _t8 = xc_expm1(-_hc2[0]*_t7);
  const double _t9 = _t6/_t8;
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
  const double _t19 = _hc3[0]*_t6;
  const double _t20 = _t11*_t18*_t19;
  const double _t21 = _hc3[0]*_t11;
  const double _t22 = _hc2[2]*_t21;
  const double _t23 = (M_PI * M_PI * M_PI * M_PI)/(_t4 * _t4);
  const double _t24 = _t2*_t23;
  const double _t25 = _t22*_t24;
#endif
#if _KMAX >= 2
  const double _t26 = _t11*_t6;
  const double _t27 = _hc3[1]*_t18;
  const double _t28 = _t26*_t27;
  const double _t29 = (_t18 * _t18);
  const double _t30 = _t11*_t19;
  const double _t31 = _t29*_t30;
  const double _t32 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t33 = (_t10 * _t10);
  const double _t34 = _hc2[3]*_t7;
  const double _t35 = -0.3e1 / 0.2e1*_hc0[5] - 0.3e1 / 0.2e1*_hc1[5];
  const double _t36 = _t16*_t35;
  const double _t37 = _hc2[1]*_t15;
  const double _t38 = 0.2e1*_t13;
  const double _t39 = xc_powi(_t1, -5);
  const double _t40 = _t13*_t39;
  const double _t41 = -0.2e1*_hc0[2] + 0.2e1*_hc1[2];
  const double _t42 = _hc2[0]*_t6;
  const double _t43 = _t41*_t42;
  const double _t44 = _t40*_t43;
  const double _t45 = -_t34 - _t36 - _t37*_t38 - _t44;
  const double _t46 = _t30*_t45;
  const double _t47 = _hc3[1]*_t11;
  const double _t48 = _hc2[2]*_t24;
  const double _t49 = _t47*_t48;
  const double _t50 = _t21*_t24;
  const double _t51 = _hc2[4]*_t50;
  const double _t52 = _t14*_t23;
  const double _t53 = _t13*_t52;
  const double _t54 = _t18*_t26;
  const double _t55 = _hc3[2]*_t54;
  const double _t56 = _t18*_t25;
  const double _t57 = _hc3[0]*_t48;
  const double _t58 = _t32*_t33;
  const double _t59 = 0.2e1*_t58;
  const double _t60 = _t18*_t59;
  const double _t61 = _t57*_t60;
  const double _t62 = _hc2[5]*_t50;
  const double _t63 = _t11*_t48;
  const double _t64 = 0.2e1*_t63;
  const double _t65 = _hc3[2]*_t64;
  const double _t66 = ((_hc2[2]) * (_hc2[2]));
  const double _t67 = _t21*_t66;
  const double _t68 = xc_powi(_t1, -6);
  const double _t69 = xc_powi(M_PI, 6)/(_t4 * _t4 * _t4);
  const double _t70 = _t68*_t69;
  const double _t71 = _t67*_t70;
  const double _t72 = _t66*_t70;
  const double _t73 = _t59*_t72;
  const double _t74 = _hc3[0]*_t73;
#endif
#if _KMAX >= 3
  const double _t75 = _hc3[1]*_t26;
  const double _t76 = (_t18 * _t18 * _t18);
  const double _t77 = (_t10 * _t10 * _t10)/(_t8 * _t8 * _t8 * _t8);
  const double _t78 = 0.6e1*_t77;
  const double _t79 = _t19*_t76*_t78;
  const double _t80 = -0.2e1*_t12 - 0.2e1*_t17;
  const double _t81 = 0.4e1*_t37;
  const double _t82 = _t39*_t43;
  const double _t83 = -_t13*_t81 - 0.2e1*_t34 - 0.2e1*_t36 - _t38*_t82;
  const double _t84 = _hc2[6]*_t7;
  const double _t85 = -0.3e1 / 0.2e1*_hc0[9] + (0.3e1 / 0.2e1)*_hc1[9];
  const double _t86 = _t16*_t85;
  const double _t87 = _t35*_t37;
  const double _t88 = _hc2[3]*_t15;
  const double _t89 = 0.3e1*_t13;
  const double _t90 = -0.2e1*_hc0[5] - 0.2e1*_hc1[5];
  const double _t91 = _t40*_t42;
  const double _t92 = 0.2e1*_t35;
  const double _t93 = _hc2[1]*_t6;
  const double _t94 = _t40*_t41;
  const double _t95 = 0.3e1*_t94;
  const double _t96 = -0.5e1 / 0.2e1*_hc0[2] + (0.5e1 / 0.2e1)*_hc1[2];
  const double _t97 = _t68*_t96;
  const double _t98 = _t13*_t43;
  const double _t99 = -_t82*_t92 - _t84 - _t86 - 0.3e1*_t87 - _t88*_t89 - _t90*_t91 - _t93*_t95 - _t97*_t98;
  const double _t100 = _hc3[3]*_t11;
  const double _t101 = _t100*_t48;
  const double _t102 = _t24*_t47;
  const double _t103 = _hc2[2]*_t53;
  const double _t104 = _t27*_t59;
  const double _t105 = _t104*_t48;
  const double _t106 = _hc2[7]*_t50;
  const double _t107 = _t35*_t52;
  const double _t108 = _t107*_t22;
  const double _t109 = _t38*_t52;
  const double _t110 = _hc2[4]*_t21;
  const double _t111 = _t23*_t94;
  const double _t112 = _hc3[2]*_t26;
  const double _t113 = _t29*_t59;
  const double _t114 = _t113*_t6;
  const double _t115 = _hc3[2]*_t114;
  const double _t116 = 0.2e1*_t18;
  const double _t117 = 0.4e1*_t58;
  const double _t118 = _hc3[0]*_t117;
  const double _t119 = _hc2[4]*_t24;
  const double _t120 = _t119*_t18;
  const double _t121 = _t113*_t57;
  const double _t122 = _t29*_t78;
  const double _t123 = _t122*_t57;
  const double _t124 = _t22*_t52;
  const double _t125 = _hc3[0]*_t18;
  const double _t126 = 0.4e1*_t13;
  const double _t127 = _hc2[2]*_t52*_t58;
  const double _t128 = _t126*_t127;
  const double _t129 = _t45*_t59;
  const double _t130 = _hc3[4]*_t64;
  const double _t131 = _hc3[1]*_t73;
  const double _t132 = _hc2[8]*_t50;
  const double _t133 = _hc3[2]*_t11;
  const double _t134 = 0.2e1*_t119;
  const double _t135 = _hc2[4]*_t70;
  const double _t136 = 0.2e1*_t135;
  const double _t137 = _hc2[2]*_t135;
  const double _t138 = _hc2[5]*_t53;
  const double _t139 = _hc2[2]*_t109;
  const double _t140 = xc_powi(_t1, -7);
  const double _t141 = -0.3e1*_hc0[2] + 0.3e1*_hc1[2];
  const double _t142 = _t140*_t141;
  const double _t143 = _t142*_t69;
  const double _t144 = _t143*_t67;
  const double _t145 = _t143*_t66;
  const double _t146 = _t145*_t59;
  const double _t147 = _t18*_t48;
  const double _t148 = _t117*_t147;
  const double _t149 = _hc3[2]*_t148;
  const double _t150 = _hc2[5]*_t24;
  const double _t151 = _hc3[0]*_t150;
  const double _t152 = _t151*_t60;
  const double _t153 = _t18*_t74;
  const double _t154 = _t72*_t78;
  const double _t155 = _t125*_t154;
  const double _t156 = _hc2[9]*_t50;
  const double _t157 = 0.3e1*_t63;
  const double _t158 = _hc3[5]*_t157;
  const double _t159 = 0.3e1*_t133;
  const double _t160 = _t150*_t159;
  const double _t161 = ((_hc2[2]) * (_hc2[2]) * (_hc2[2]));
  const double _t162 = xc_powi(M_PI, 8);
  const double _t163 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t164 = _t162*_t163/xc_powi(_t1, 9);
  const double _t165 = _t161*_t164;
  const double _t166 = _t165*_t21;
  const double _t167 = _hc2[5]*_t70;
  const double _t168 = 0.3e1*_t167;
  const double _t169 = _t168*_t22;
  const double _t170 = _t159*_t72;
  const double _t171 = 0.6e1*_t58;
  const double _t172 = _hc3[0]*_t171;
  const double _t173 = _hc2[2]*_t167;
  const double _t174 = _t172*_t173;
  const double _t175 = _t171*_t72;
  const double _t176 = _hc3[2]*_t175;
  const double _t177 = _hc3[0]*_t165;
  const double _t178 = _t171*_t177;
  const double _t179 = _t177*_t78;
#endif
#if _KMAX >= 4
  const double _t180 = _hc3[3]*_t26;
  const double _t181 = (_t18 * _t18 * _t18 * _t18);
  const double _t182 = xc_powi(_t8, -5);
  const double _t183 = (_t10 * _t10 * _t10 * _t10);
  const double _t184 = -0.3e1*_t12 - 0.3e1*_t17;
  const double _t185 = (_t80 * _t80);
  const double _t186 = (_t45 * _t45);
  const double _t187 = 0.6e1*_t13;
  const double _t188 = -_t187*_t37 - 0.3e1*_t34 - 0.3e1*_t36 - 0.3e1*_t44;
  const double _t189 = _t19*_t29*_t78;
  const double _t190 = 0.6e1*_t88;
  const double _t191 = _t42*_t90;
  const double _t192 = _t191*_t38;
  const double _t193 = 0.6e1*_t94;
  const double _t194 = _t43*_t97;
  const double _t195 = -_t13*_t190 - _t192*_t39 - _t193*_t93 - _t194*_t38 - 0.4e1*_t35*_t82 - 0.2e1*_t84 - 0.2e1*_t86 - 0.6e1*_t87;
  const double _t196 = _t35*_t39;
  const double _t197 = _t41*_t93;
  const double _t198 = _t40*_t90;
  const double _t199 = _t100*_t24;
  const double _t200 = _hc2[2]*_t47;
  const double _t201 = _hc3[4]*_t26;
  const double _t202 = _t11*_t27;
  const double _t203 = _hc3[1]*_t48;
  const double _t204 = _t107*_t21;
  const double _t205 = 0.3e1*_hc2[4];
  const double _t206 = _t52*_t89;
  const double _t207 = _t22*_t23;
  const double _t208 = _t207*_t41;
  const double _t209 = _hc3[2]*_t6;
  const double _t210 = _t209*_t59;
  const double _t211 = _t76*_t78;
  const double _t212 = 0.3e1*_t18;
  const double _t213 = 0.3e1*_t51;
  const double _t214 = _t172*_t18;
  const double _t215 = _t57*_t76;
  const double _t216 = 0.24e2*_t182*_t183;
  const double _t217 = _t119*_t172;
  const double _t218 = _hc3[0]*_t29;
  const double _t219 = 0.18e2*_t77;
  const double _t220 = _t218*_t219;
  const double _t221 = _t124*_t89;
  const double _t222 = 0.12e2*_t58;
  const double _t223 = _t127*_t187;
  const double _t224 = _t125*_t58;
  const double _t225 = _hc2[2]*_t23;
  const double _t226 = _hc3[0]*_t45;
  const double _t227 = _t18*_t210;
  const double _t228 = _t45*_t48;
  const double _t229 = _t118*_t80;
  const double _t230 = _t18*_t57;
  const double _t231 = _t230*_t78;
  const double _t232 = _hc3[4]*_t11;
  const double _t233 = _t133*_t24;
  const double _t234 = 0.2e1*_hc2[7];
  const double _t235 = _t22*_t70;
  const double _t236 = ((_hc2[4]) * (_hc2[4]))*_t70;
  const double _t237 = _hc2[2]*_t70;
  const double _t238 = _t133*_t52;
  const double _t239 = _hc2[2]*_t238;
  const double _t240 = _t109*_t21;
  const double _t241 = 0.4e1*_t22;
  const double _t242 = _t67*_t69;
  const double _t243 = _t140*(-0.3e1*_hc0[5] - 0.3e1*_hc1[5]);
  const double _t244 = _hc2[4]*_t58;
  const double _t245 = _hc2[2]*_t143;
  const double _t246 = _hc3[0]*_t66;
  const double _t247 = _t246*_t59*_t69;
  const double _t248 = _t141*(-0.7e1 / 0.2e1*_hc0[2] + (0.7e1 / 0.2e1)*_hc1[2])/xc_powi(_t1, 8);
  const double _t249 = _hc3[5]*_t26;
  const double _t250 = 0.4e1*_t133;
  const double _t251 = _hc3[2]*_t58;
  const double _t252 = 0.8e1*_t251;
  const double _t253 = _hc2[8]*_t24;
  const double _t254 = _t118*_t18;
  const double _t255 = 0.8e1*_t58;
  const double _t256 = _t137*_t255;
  const double _t257 = _t125*_t77;
  const double _t258 = _t29*_t48;
  const double _t259 = _hc3[2]*_t117;
  const double _t260 = _hc3[2]*_t77;
  const double _t261 = _hc3[0]*_t72;
  const double _t262 = 0.3e1*_t232;
  const double _t263 = _hc3[1]*_t165;
  const double _t264 = _hc3[5]*_t11;
  const double _t265 = 0.3e1*_t21;
  const double _t266 = _hc2[5]*_t135;
  const double _t267 = _t164*_t67;
  const double _t268 = _t164*_t246;
  const double _t269 = _t161*_t162*_t163*(-0.9e1 / 0.2e1*_hc0[2] + (0.9e1 / 0.2e1)*_hc1[2])/xc_powi(_t1, 10);
  const double _t270 = _hc3[2]*_t171;
  const double _t271 = _hc2[9]*_hc3[0];
  const double _t272 = _t177*_t18;
  const double _t273 = 0.6e1*_t264;
  const double _t274 = 0.4e1*_hc2[9];
  const double _t275 = ((_hc2[5]) * (_hc2[5]))*_t70;
  const double _t276 = xc_powi(M_PI, 10)*((_hc2[2]) * (_hc2[2]) * (_hc2[2]) * (_hc2[2]))/(xc_powi(_t1, 12)*xc_powi(_t4, 5));
  const double _t277 = 0.24e2*_t165;
  const double _t278 = _hc3[0]*_t276;
  const double _t279 = 0.36e2*_t77;
  const double _t280 = _hc2[5]*_t268;
#endif

  const double f = _hc3[0]*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc3[1]*_t9;
  out[1] = df_dt;
  const double df_dz = -_t20;
  out[2] = df_dz;
  const double df_drs = _hc3[2]*_t9 + _t25;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc3[3]*_t9;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = -_t28;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = 0.2e1*_hc3[0]*_t29*_t3*_t32*_t33*_t5 - _t31 - _t46;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = _hc3[4]*_t9 + _t49;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _t22*_t53 + _t51 - _t55 + _t56 - _t61;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc3[5]*_t9 + _t62 + _t65 - _t71 + _t74;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = -_hc3[3]*_t54;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = 0.2e1*_hc3[1]*_t29*_t3*_t32*_t33*_t5 - _t29*_t75 - _t45*_t75;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = 0.2e1*_hc3[0]*_t18*_t3*_t32*_t33*_t45*_t5 + 0.2e1*_hc3[0]*_t18*_t3*_t32*_t33*_t5*_t83 + 0.2e1*_hc3[0]*_t29*_t3*_t32*_t33*_t5*_t80 + 0.2e1*_hc3[0]*_t3*_t32*_t33*_t5*_t76 - _t20*_t45 - _t20*_t83 - _t30*_t76 - _t30*_t99 - _t79;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = _hc3[7]*_t9 + _t101;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = _hc2[4]*_t102 - _hc3[4]*_t54 + _t103*_t47 - _t105 + _t27*_t63;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _t106 + _t108 + _t109*_t110 + _t111*_t22 - _t112*_t29 - _t112*_t45 + _t115 + _t116*_t51 - _t118*_t120 - _t121 + _t123 + _t124*_t18*_t38 - _t125*_t128 - _t129*_t57 + _t25*_t29 + _t25*_t45 - _t61*_t80;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = _hc2[5]*_t102 + _hc3[8]*_t9 + _t130 + _t131 - _t47*_t72;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _hc3[0]*_t146 - _hc3[5]*_t54 + _t118*_t137 + _t132 + _t133*_t134 + _t133*_t139 - _t136*_t22 + _t138*_t21 - _t144 - _t149 - _t152 + _t153 - _t155 + _t18*_t62 + _t18*_t65 - _t18*_t71 + _t74*_t80;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc3[9]*_t9 + _t156 + _t158 + _t160 + _t166 - _t169 - _t170 + _t174 + _t176 - _t178 + _t179;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[20] = d4f_dt4;
  const double d4f_dz_dt3 = 0;
  out[21] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = 0.2e1*_hc3[3]*_t29*_t3*_t32*_t33*_t5 - _t180*_t29 - _t180*_t45;
  out[22] = d4f_dz2_dt2;
  const double d4f_dz3_dt = 0.2e1*_hc3[1]*_t18*_t3*_t32*_t33*_t45*_t5 + 0.2e1*_hc3[1]*_t18*_t3*_t32*_t33*_t5*_t83 + 0.2e1*_hc3[1]*_t29*_t3*_t32*_t33*_t5*_t80 + 0.2e1*_hc3[1]*_t3*_t32*_t33*_t5*_t76 - _hc3[1]*_t6*_t76*_t78 - _t28*_t45 - _t28*_t83 - _t75*_t76 - _t75*_t99;
  out[23] = d4f_dz3_dt;
  const double d4f_dz4 = 0.2e1*_hc3[0]*_t18*_t195*_t3*_t32*_t33*_t5 + 0.2e1*_hc3[0]*_t18*_t3*_t32*_t33*_t45*_t5*_t80 + 0.4e1*_hc3[0]*_t18*_t3*_t32*_t33*_t5*_t80*_t83 + 0.4e1*_hc3[0]*_t18*_t3*_t32*_t33*_t5*_t99 + 0.24e2*_hc3[0]*_t181*_t182*_t183*_t3*_t5 + 0.2e1*_hc3[0]*_t181*_t3*_t32*_t33*_t5 + 0.2e1*_hc3[0]*_t185*_t29*_t3*_t32*_t33*_t5 + 0.2e1*_hc3[0]*_t186*_t3*_t32*_t33*_t5 + 0.2e1*_hc3[0]*_t188*_t29*_t3*_t32*_t33*_t5 + 0.2e1*_hc3[0]*_t29*_t3*_t32*_t33*_t45*_t5 + 0.4e1*_hc3[0]*_t29*_t3*_t32*_t33*_t5*_t83 + 0.2e1*_hc3[0]*_t3*_t32*_t33*_t45*_t5*_t83 + 0.2e1*_hc3[0]*_t3*_t32*_t33*_t5*_t76*_t80 - _t181*_t19*_t78 - _t181*_t30 - _t184*_t79 - _t186*_t30 - _t188*_t189 - _t188*_t31 - _t189*_t45 - _t189*_t83 - _t195*_t20 - 0.2e1*_t20*_t99 - _t30*(-_hc2[10]*_t7 - _hc2[3]*_t193*_t6 - _hc2[6]*_t126*_t15 - _t126*_t197*_t97 - _t142*_t96*_t98 - _t16*(-0.3e1 / 0.2e1*_hc0[14] - 0.3e1 / 0.2e1*_hc1[14]) - _t190*_t35 - 0.3e1*_t191*_t196 - _t192*_t97 - 0.3e1*_t194*_t35 - 0.8e1*_t196*_t197 - 0.4e1*_t198*_t93 - _t68*_t98*(-0.5e1 / 0.2e1*_hc0[5] - 0.5e1 / 0.2e1*_hc1[5]) - _t81*_t85 - 0.3e1*_t82*_t85 - _t91*(-0.2e1*_hc0[9] + 0.2e1*_hc1[9])) - _t31*_t45 - _t31*_t83 - _t46*_t83 - _t79*_t80;
  out[24] = d4f_dz4;
  const double d4f_drs_dt3 = 0;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dz_dt2 = _hc2[4]*_t199 - _hc3[3]*_t48*_t60 - _hc3[7]*_t54 + _t100*_t103 + _t101*_t18;
  out[26] = d4f_drs_dz_dt2;
  const double d4f_drs_dz2_dt = _hc2[4]*_t109*_t47 + _hc2[7]*_t102 + _hc3[4]*_t114 - _t105*_t80 + _t107*_t200 + _t111*_t200 - _t113*_t203 - _t117*_t119*_t27 + _t122*_t203 - _t128*_t27 - _t129*_t203 + _t134*_t202 + _t139*_t202 - _t201*_t29 - _t201*_t45 + _t29*_t49 + _t45*_t49;
  out[27] = d4f_drs_dz2_dt;
  const double d4f_drs_dz3 = _hc2[11]*_t50 - _hc2[2]*_t107*_t214 - _hc2[4]*_t125*_t222*_t53 + _hc2[7]*_t206*_t21 - _hc2[7]*_t214*_t24 + _t103*_t220 + _t106*_t212 + _t108*_t212 + _t110*_t18*_t187*_t52 + _t110*_t23*_t95 - _t112*_t76 - _t112*_t99 + _t115*_t80 - _t117*_t230*_t83 + _t119*_t220 - _t120*_t172*_t80 - _t121*_t80 + _t123*_t184 + _t123*_t80 + _t124*_t85 - _t125*_t223*_t80 + _t13*_t208*_t97 + _t18*_t207*_t95 - _t185*_t61 - _t193*_t224*_t225 + _t198*_t207 + _t204*_t205 + _t208*_t39*_t92 - _t209*_t211 + _t210*_t76 + _t211*_t57 + _t213*_t29 + _t213*_t45 - _t215*_t216 - _t215*_t59 - _t217*_t29 - _t217*_t45 - _t218*_t223 + _t221*_t29 + _t221*_t45 - _t223*_t226 + _t227*_t45 + _t227*_t83 - _t228*_t229 + _t231*_t45 + _t231*_t83 + _t25*_t76 + _t25*_t99 - _t45*_t55 + _t45*_t56 - _t45*_t61 - _t55*_t83 + _t56*_t83 - _t57*_t59*_t99;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = _hc2[5]*_t199 + _hc3[12]*_t9 + _hc3[3]*_t73 + _hc3[7]*_t64 - _t100*_t72;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dz_dt = _hc2[8]*_t102 + _hc3[1]*_t117*_t137 + _hc3[1]*_t146 - _hc3[4]*_t148 - _hc3[8]*_t54 - _t104*_t150 + _t130*_t18 + _t131*_t80 + _t134*_t232 - _t136*_t200 + _t138*_t47 + _t139*_t232 - _t145*_t47 + _t150*_t202 - _t154*_t27 - _t202*_t72 + _t27*_t73;
  out[30] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz2 = _hc2[12]*_t50 + _hc2[4]*_t126*_t238 - _hc2[4]*_t143*_t241 + _hc2[5]*_t111*_t21 - _hc2[5]*_t126*_t224*_t52 + _hc2[5]*_t18*_t240 + _hc2[5]*_t204 + _hc2[7]*_t118*_t237 + _hc2[8]*_t240 + 0.8e1*_hc3[0]*_t244*_t245 + _hc3[0]*_t256*_t80 + _hc3[5]*_t114 - _t103*_t18*_t252 - _t113*_t151 + _t113*_t261 + _t116*_t132 - _t116*_t144 + _t118*_t236 + _t120*_t250 - _t120*_t252 + _t122*_t151 - _t122*_t261 + _t125*_t256 + _t126*_t18*_t239 - _t129*_t151 + _t133*_t225*_t38*_t39*_t41 - _t135*_t18*_t241 - 0.24e2*_t137*_t257 + _t145*_t229 + _t145*_t254 - 0.12e2*_t145*_t257 - _t149*_t80 - _t152*_t80 + _t153*_t80 - _t154*_t226 - _t155*_t184 - _t155*_t80 + _t185*_t74 - 0.2e1*_t21*_t236 + _t216*_t218*_t72 - _t228*_t259 + _t233*_t234 - _t234*_t235 + _t239*_t92 - _t242*_t243 - _t242*_t248 + _t243*_t247 + _t247*_t248 - _t249*_t29 - _t249*_t45 - _t253*_t254 - _t258*_t259 + 0.12e2*_t258*_t260 + _t29*_t62 + _t29*_t65 - _t29*_t71 + _t45*_t62 + _t45*_t65 - _t45*_t71 + _t45*_t74 + _t74*_t83;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dt = _hc2[9]*_t102 + _hc3[1]*_t171*_t173 + _hc3[13]*_t9 + _hc3[4]*_t175 + _hc3[8]*_t157 + _t150*_t262 + _t165*_t47 - _t168*_t200 - _t171*_t263 - _t262*_t72 + _t263*_t78;
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dz = _hc2[13]*_t50 + _hc2[2]*_t206*_t264 + _hc2[4]*_t219*_t268 + _hc2[5]*_t133*_t206 - 0.3e1*_hc2[5]*_t143*_t22 + _hc2[5]*_t172*_t245 + _hc2[8]*_t172*_t237 - 0.3e1*_hc2[8]*_t235 + _hc2[9]*_t21*_t53 + _hc3[0]*_t269*_t78 - _hc3[5]*_t147*_t171 - _hc3[9]*_t54 + 0.3e1*_t119*_t264 - _t125*_t173*_t219 - 0.6e1*_t133*_t137 + 0.12e2*_t137*_t251 - _t145*_t159 + _t145*_t270 - _t150*_t18*_t270 + _t156*_t18 + _t158*_t18 + _t159*_t253 + _t160*_t18 + _t166*_t18 - _t169*_t18 - _t170*_t18 + _t172*_t266 - _t172*_t269 + _t174*_t18 + _t174*_t80 + _t176*_t18 + _t176*_t80 - _t177*_t60 - _t178*_t80 + _t179*_t184 - 0.18e2*_t18*_t260*_t72 + _t205*_t267 + _t21*_t269 - _t216*_t272 + _t219*_t272 - _t24*_t271*_t60 - 0.18e2*_t244*_t268 - _t265*_t266;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = _hc2[14]*_t50 + 0.6e1*_hc2[5]*_t267 + _hc3[14]*_t9 + _hc3[5]*_t222*_t72 + 0.4e1*_hc3[9]*_t63 - 0.12e2*_t133*_t173 + _t150*_t273 + _t165*_t250 + _t172*_t275 + 0.24e2*_t173*_t251 - _t21*_t276 + _t216*_t278 + _t233*_t274 - _t235*_t274 + _t237*_t255*_t271 - _t251*_t277 + _t260*_t277 - _t265*_t275 - _t273*_t72 - _t278*_t279 + 0.14e2*_t278*_t58 + _t279*_t280 - 0.36e2*_t280*_t58;
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
  XC_CAT(mbeta_k, _KMAX)(p, rs, t, _hc2);
  const double _t1 = _hc0[0]*_hc1[0] + 0.1e1;
  const double _t2 = (M_PI * M_PI)/(0.1e1 - M_LN2);
  const double _t3 = _t2/_t1;
  const double _t4 = _hc1[0]*_t3;
#if _KMAX >= 1
  const double _t5 = _hc2[0]*_t3;
  const double _t6 = _t2/(_t1 * _t1);
  const double _t7 = _hc1[0]*_t6;
  const double _t8 = _hc0[0]*_hc1[1];
  const double _t9 = _hc0[1]*_hc1[0];
  const double _t10 = -_t8 - _t9;
  const double _t11 = _hc2[0]*_t10;
  const double _t12 = _hc0[0]*_hc1[2];
  const double _t13 = _hc0[2]*_hc1[0];
  const double _t14 = -_t12 - _t13;
  const double _t15 = _hc2[0]*_t7;
  const double _t16 = _hc0[0]*_hc1[3];
  const double _t17 = _hc0[3]*_hc1[0];
  const double _t18 = -_t16 - _t17;
#endif
#if _KMAX >= 2
  const double _t19 = 0.2e1*_hc1[1];
  const double _t20 = _hc2[1]*_t3;
  const double _t21 = _hc2[1]*_t7;
  const double _t22 = 0.2e1*_t21;
  const double _t23 = _t11*_t6;
  const double _t24 = _hc0[0]*_hc1[4];
  const double _t25 = _hc0[4]*_hc1[0];
  const double _t26 = _hc0[1]*_hc1[1];
  const double _t27 = -_t24 - _t25 - 0.2e1*_t26;
  const double _t28 = _t2/(_t1 * _t1 * _t1);
  const double _t29 = _hc1[0]*_t28;
  const double _t30 = -0.2e1*_t8 - 0.2e1*_t9;
  const double _t31 = _t11*_t30;
  const double _t32 = _hc2[0]*_t6;
  const double _t33 = _hc1[1]*_t14;
  const double _t34 = _hc0[0]*_hc1[5];
  const double _t35 = _hc0[1]*_hc1[2];
  const double _t36 = _hc0[2]*_hc1[1];
  const double _t37 = _hc0[5]*_hc1[0];
  const double _t38 = -_t34 - _t35 - _t36 - _t37;
  const double _t39 = _hc2[0]*_t29;
  const double _t40 = _t14*_t30;
  const double _t41 = 0.2e1*_hc1[2];
  const double _t42 = _t14*_t32;
  const double _t43 = _hc0[0]*_hc1[6];
  const double _t44 = _hc0[6]*_hc1[0];
  const double _t45 = 0.2e1*_hc0[2];
  const double _t46 = -_hc1[2]*_t45 - _t43 - _t44;
  const double _t47 = -0.2e1*_t12 - 0.2e1*_t13;
  const double _t48 = _t39*_t47;
  const double _t49 = _hc2[2]*_t3;
  const double _t50 = _hc2[2]*_t7;
  const double _t51 = _t18*_t32;
  const double _t52 = _hc0[0]*_hc1[7];
  const double _t53 = _hc0[1]*_hc1[3];
  const double _t54 = _hc0[3]*_hc1[1];
  const double _t55 = _hc0[7]*_hc1[0];
  const double _t56 = -_t52 - _t53 - _t54 - _t55;
  const double _t57 = _t18*_t39;
  const double _t58 = _hc0[0]*_hc1[8];
  const double _t59 = _hc0[2]*_hc1[3];
  const double _t60 = _hc0[3]*_hc1[2];
  const double _t61 = _hc0[8]*_hc1[0];
  const double _t62 = -_t58 - _t59 - _t60 - _t61;
  const double _t63 = 0.2e1*_hc1[3];
  const double _t64 = 0.2e1*_t50;
  const double _t65 = _hc0[0]*_hc1[9];
  const double _t66 = _hc0[9]*_hc1[0];
  const double _t67 = 0.2e1*_hc0[3];
  const double _t68 = -_hc1[3]*_t67 - _t65 - _t66;
  const double _t69 = -0.2e1*_t16 - 0.2e1*_t17;
#endif
#if _KMAX >= 3
  const double _t70 = 0.3e1*_hc1[1];
  const double _t71 = _hc2[3]*_t3;
  const double _t72 = 0.3e1*_t20;
  const double _t73 = _hc2[3]*_t7;
  const double _t74 = 0.3e1*_t73;
  const double _t75 = _hc2[1]*_t6;
  const double _t76 = _t10*_t75;
  const double _t77 = 0.6e1*_hc1[1];
  const double _t78 = 0.3e1*_t23;
  const double _t79 = 0.3e1*_t21;
  const double _t80 = _t27*_t32;
  const double _t81 = _hc0[0]*_hc1[10];
  const double _t82 = _hc0[10]*_hc1[0];
  const double _t83 = _hc0[1]*_hc1[4];
  const double _t84 = _hc0[4]*_hc1[1];
  const double _t85 = -_t81 - _t82 - 0.3e1*_t83 - 0.3e1*_t84;
  const double _t86 = _t10*_t30;
  const double _t87 = _hc2[1]*_t29;
  const double _t88 = 0.3e1*_t87;
  const double _t89 = _t28*_t31;
  const double _t90 = -0.2e1*_t24 - 0.2e1*_t25 - 0.4e1*_t26;
  const double _t91 = _t11*_t29;
  const double _t92 = _t30*_t39;
  const double _t93 = 0.2e1*_t92;
  const double _t94 = -0.3e1*_t8 - 0.3e1*_t9;
  const double _t95 = _t2/(_t1 * _t1 * _t1 * _t1);
  const double _t96 = _hc1[0]*_t95;
  const double _t97 = _t94*_t96;
  const double _t98 = 0.2e1*_t20;
  const double _t99 = _t14*_t75;
  const double _t100 = 0.2e1*_hc1[5];
  const double _t101 = _t32*_t38;
  const double _t102 = 0.2e1*_t87;
  const double _t103 = _hc2[0]*_t28;
  const double _t104 = _t103*_t40;
  const double _t105 = _t14*_t39;
  const double _t106 = _hc0[0]*_hc1[11];
  const double _t107 = _hc0[11]*_hc1[0];
  const double _t108 = _hc0[2]*_hc1[4];
  const double _t109 = _hc0[4]*_hc1[2];
  const double _t110 = 0.2e1*_hc0[1];
  const double _t111 = 0.2e1*_hc0[5];
  const double _t112 = -_hc1[1]*_t111 - _hc1[5]*_t110 - _t106 - _t107 - _t108 - _t109;
  const double _t113 = _hc2[0]*_t97;
  const double _t114 = _hc1[1]*_t32;
  const double _t115 = _t14*_t47;
  const double _t116 = _t103*_t47;
  const double _t117 = _hc0[0]*_hc1[12];
  const double _t118 = _hc0[1]*_hc1[6];
  const double _t119 = _hc0[12]*_hc1[0];
  const double _t120 = _hc0[6]*_hc1[1];
  const double _t121 = -_hc1[2]*_t111 - _hc1[5]*_t45 - _t117 - _t118 - _t119 - _t120;
  const double _t122 = -0.2e1*_t34 - 0.2e1*_t35 - 0.2e1*_t36 - 0.2e1*_t37;
  const double _t123 = 0.3e1*_t42;
  const double _t124 = 0.3e1*_hc1[2];
  const double _t125 = _t32*_t46;
  const double _t126 = _hc0[0]*_hc1[13];
  const double _t127 = _hc0[13]*_hc1[0];
  const double _t128 = 0.3e1*_hc0[2];
  const double _t129 = -_hc0[6]*_t124 - _hc1[6]*_t128 - _t126 - _t127;
  const double _t130 = _t103*_t115;
  const double _t131 = 0.4e1*_hc0[2];
  const double _t132 = -_hc1[2]*_t131 - 0.2e1*_t43 - 0.2e1*_t44;
  const double _t133 = 0.2e1*_t48;
  const double _t134 = -0.3e1*_t12 - 0.3e1*_t13;
  const double _t135 = _hc2[0]*_t96;
  const double _t136 = _t134*_t135;
  const double _t137 = _hc2[4]*_t3;
  const double _t138 = _hc2[4]*_t7;
  const double _t139 = 0.2e1*_t138;
  const double _t140 = _t18*_t75;
  const double _t141 = _hc2[2]*_t6;
  const double _t142 = _t10*_t141;
  const double _t143 = 0.2e1*_hc1[7];
  const double _t144 = _t32*_t56;
  const double _t145 = _hc2[2]*_t29;
  const double _t146 = _t18*_t87;
  const double _t147 = 0.2e1*_t146;
  const double _t148 = _t103*_t30;
  const double _t149 = _t148*_t18;
  const double _t150 = _hc0[0]*_hc1[14];
  const double _t151 = _hc0[14]*_hc1[0];
  const double _t152 = _hc0[3]*_hc1[4];
  const double _t153 = _hc0[4]*_hc1[3];
  const double _t154 = 0.2e1*_hc0[7];
  const double _t155 = -_hc1[1]*_t154 - _hc1[7]*_t110 - _t150 - _t151 - _t152 - _t153;
  const double _t156 = _t113*_t18;
  const double _t157 = _hc1[2]*_t3;
  const double _t158 = _t14*_t7;
  const double _t159 = _hc1[2]*_t18;
  const double _t160 = _hc1[2]*_t141;
  const double _t161 = _hc1[3]*_t14;
  const double _t162 = _hc1[2]*_t32;
  const double _t163 = _hc1[3]*_t32;
  const double _t164 = _hc1[1]*_t18;
  const double _t165 = _hc0[0]*_hc1[15];
  const double _t166 = _hc0[1]*_hc1[8];
  const double _t167 = _hc0[15]*_hc1[0];
  const double _t168 = _hc0[2]*_hc1[7];
  const double _t169 = _hc0[3]*_hc1[5];
  const double _t170 = _hc0[5]*_hc1[3];
  const double _t171 = _hc0[7]*_hc1[2];
  const double _t172 = _hc0[8]*_hc1[1];
  const double _t173 = -_t165 - _t166 - _t167 - _t168 - _t169 - _t170 - _t171 - _t172;
  const double _t174 = _t14*_t141;
  const double _t175 = 0.2e1*_hc1[8];
  const double _t176 = _t32*_t62;
  const double _t177 = _t116*_t18;
  const double _t178 = _hc0[0]*_hc1[16];
  const double _t179 = _hc0[16]*_hc1[0];
  const double _t180 = _hc0[3]*_hc1[6];
  const double _t181 = _hc0[6]*_hc1[3];
  const double _t182 = 0.2e1*_hc0[8];
  const double _t183 = -_hc1[2]*_t182 - _hc1[8]*_t45 - _t178 - _t179 - _t180 - _t181;
  const double _t184 = _t136*_t18;
  const double _t185 = _hc2[5]*_t3;
  const double _t186 = 0.2e1*_t49;
  const double _t187 = _hc2[5]*_t7;
  const double _t188 = _t141*_t18;
  const double _t189 = _t103*_t69;
  const double _t190 = _t145*_t30;
  const double _t191 = 0.2e1*_t18;
  const double _t192 = _hc0[0]*_hc1[17];
  const double _t193 = _hc0[1]*_hc1[9];
  const double _t194 = _hc0[17]*_hc1[0];
  const double _t195 = _hc0[9]*_hc1[1];
  const double _t196 = -_hc1[3]*_t154 - _hc1[7]*_t67 - _t192 - _t193 - _t194 - _t195;
  const double _t197 = _t39*_t69;
  const double _t198 = -0.2e1*_t52 - 0.2e1*_t53 - 0.2e1*_t54 - 0.2e1*_t55;
  const double _t199 = _t145*_t47;
  const double _t200 = _hc0[0]*_hc1[18];
  const double _t201 = _hc0[18]*_hc1[0];
  const double _t202 = _hc0[2]*_hc1[9];
  const double _t203 = _hc0[9]*_hc1[2];
  const double _t204 = -_hc1[3]*_t182 - _hc1[8]*_t67 - _t200 - _t201 - _t202 - _t203;
  const double _t205 = -0.2e1*_t58 - 0.2e1*_t59 - 0.2e1*_t60 - 0.2e1*_t61;
  const double _t206 = 0.3e1*_hc1[3];
  const double _t207 = 0.3e1*_t49;
  const double _t208 = 0.3e1*_t187;
  const double _t209 = 0.6e1*_hc1[3];
  const double _t210 = 0.3e1*_t51;
  const double _t211 = 0.3e1*_t50;
  const double _t212 = _t32*_t68;
  const double _t213 = _hc0[0]*_hc1[19];
  const double _t214 = _hc0[19]*_hc1[0];
  const double _t215 = 0.3e1*_hc0[3];
  const double _t216 = -_hc0[9]*_t206 - _hc1[9]*_t215 - _t213 - _t214;
  const double _t217 = _t18*_t69;
  const double _t218 = 0.3e1*_t145;
  const double _t219 = _t18*_t189;
  const double _t220 = 0.4e1*_hc0[3];
  const double _t221 = -_hc1[3]*_t220 - 0.2e1*_t65 - 0.2e1*_t66;
  const double _t222 = 0.2e1*_t197;
  const double _t223 = -0.3e1*_t16 - 0.3e1*_t17;
  const double _t224 = _t135*_t217;
#endif
#if _KMAX >= 4
  const double _t225 = 0.4e1*_hc1[10];
  const double _t226 = 0.6e1*_hc1[4];
  const double _t227 = 0.12e2*_hc1[1];
  const double _t228 = _hc2[3]*_t6;
  const double _t229 = _t10*_t228;
  const double _t230 = _t27*_t75;
  const double _t231 = 0.4e1*_hc1[1];
  const double _t232 = _hc2[3]*_t29;
  const double _t233 = _hc2[1]*_t28;
  const double _t234 = _t233*_t86;
  const double _t235 = 0.4e1*_hc0[1];
  const double _t236 = 0.8e1*_t27;
  const double _t237 = _t30*_t87;
  const double _t238 = _t11*_t90;
  const double _t239 = _t238*_t28;
  const double _t240 = -0.2e1*_t81 - 0.2e1*_t82 - 0.6e1*_t83 - 0.6e1*_t84;
  const double _t241 = 0.3e1*_t92;
  const double _t242 = _t39*_t90;
  const double _t243 = 0.3e1*_t27;
  const double _t244 = _hc2[1]*_t97;
  const double _t245 = _t94*_t95;
  const double _t246 = _t245*_t31;
  const double _t247 = -0.3e1*_t24 - 0.3e1*_t25 - 0.6e1*_t26;
  const double _t248 = _t113*_t30;
  const double _t249 = 0.2e1*_t97;
  const double _t250 = _hc1[0]*_t2/xc_powi(_t1, 5);
  const double _t251 = _t250*(-0.4e1*_t8 - 0.4e1*_t9);
  const double _t252 = _t251*_t94;
  const double _t253 = 0.3e1*_hc1[5];
  const double _t254 = _t14*_t228;
  const double _t255 = 0.3e1*_t99;
  const double _t256 = 0.6e1*_t76;
  const double _t257 = _t38*_t75;
  const double _t258 = _hc1[4]*_t32;
  const double _t259 = 0.3e1*_t38;
  const double _t260 = 0.3e1*_t40;
  const double _t261 = _t233*_t30;
  const double _t262 = 0.3e1*_hc1[4];
  const double _t263 = _t14*_t90;
  const double _t264 = _t103*_t90;
  const double _t265 = _t14*_t264;
  const double _t266 = _t148*_t27;
  const double _t267 = _t112*_t32;
  const double _t268 = 0.6e1*_t237;
  const double _t269 = _t148*_t38;
  const double _t270 = _hc2[0]*_t245;
  const double _t271 = _t270*_t40;
  const double _t272 = _t135*_t247;
  const double _t273 = 0.2e1*_t113;
  const double _t274 = 0.3e1*_hc0[1];
  const double _t275 = 0.3e1*_hc0[5];
  const double _t276 = _hc2[0]*_t252;
  const double _t277 = 0.2e1*_t42;
  const double _t278 = 0.2e1*_t23;
  const double _t279 = 0.4e1*_hc1[5];
  const double _t280 = 0.2e1*_t76;
  const double _t281 = _t46*_t75;
  const double _t282 = 0.4e1*_hc1[2];
  const double _t283 = _t115*_t233;
  const double _t284 = _t233*_t40;
  const double _t285 = _t30*_t46;
  const double _t286 = _t148*_t46;
  const double _t287 = _t121*_t32;
  const double _t288 = _t47*_t87;
  const double _t289 = 0.2e1*_t38;
  const double _t290 = _t122*_t14;
  const double _t291 = _t116*_t38;
  const double _t292 = _t103*_t290;
  const double _t293 = _t115*_t270;
  const double _t294 = -_hc0[5]*_t231 - _hc1[5]*_t235 - 0.2e1*_t106 - 0.2e1*_t107 - 0.2e1*_t108 - 0.2e1*_t109;
  const double _t295 = _t122*_t39;
  const double _t296 = _t113*_t47;
  const double _t297 = 0.4e1*_hc0[5];
  const double _t298 = _hc1[6]*_t32;
  const double _t299 = _t132*_t14;
  const double _t300 = _t103*_t132;
  const double _t301 = 0.2e1*_t46;
  const double _t302 = _t116*_t46;
  const double _t303 = _hc2[1]*_t96;
  const double _t304 = _t115*_t134;
  const double _t305 = _t33*_t47;
  const double _t306 = _hc2[0]*_t95;
  const double _t307 = _t134*_t306;
  const double _t308 = _t132*_t39;
  const double _t309 = -_hc1[2]*_t297 - _hc1[5]*_t131 - 0.2e1*_t117 - 0.2e1*_t118 - 0.2e1*_t119 - 0.2e1*_t120;
  const double _t310 = _t136*_t47;
  const double _t311 = -0.3e1*_t34 - 0.3e1*_t35 - 0.3e1*_t36 - 0.3e1*_t37;
  const double _t312 = _t115*_t135;
  const double _t313 = _hc2[0]*_t304;
  const double _t314 = 0.6e1*_hc1[6];
  const double _t315 = 0.6e1*_hc1[2];
  const double _t316 = -_hc0[2]*_t314 - _hc0[6]*_t315 - 0.2e1*_t126 - 0.2e1*_t127;
  const double _t317 = 0.3e1*_t48;
  const double _t318 = 0.3e1*_t46;
  const double _t319 = -_hc0[2]*_t315 - 0.3e1*_t43 - 0.3e1*_t44;
  const double _t320 = 0.2e1*_t136;
  const double _t321 = _t250*(-0.4e1*_t12 - 0.4e1*_t13);
  const double _t322 = _hc2[7]*_t3;
  const double _t323 = 0.3e1*_t137;
  const double _t324 = 0.3e1*_hc1[7];
  const double _t325 = _t10*_t7;
  const double _t326 = _t18*_t228;
  const double _t327 = _hc2[4]*_t6;
  const double _t328 = _t10*_t327;
  const double _t329 = 0.3e1*_t138;
  const double _t330 = _t141*_t27;
  const double _t331 = _t56*_t75;
  const double _t332 = 0.3e1*_t56;
  const double _t333 = _t18*_t232;
  const double _t334 = 0.3e1*_t30;
  const double _t335 = _hc2[4]*_t29;
  const double _t336 = 0.3e1*_t335;
  const double _t337 = _t18*_t261;
  const double _t338 = _hc2[2]*_t28;
  const double _t339 = _t338*_t86;
  const double _t340 = _t145*_t90;
  const double _t341 = 0.2e1*_t190;
  const double _t342 = _t18*_t264;
  const double _t343 = _t155*_t32;
  const double _t344 = _t148*_t56;
  const double _t345 = _hc2[2]*_t97;
  const double _t346 = _t18*_t334;
  const double _t347 = _t270*_t30;
  const double _t348 = _t18*_t272;
  const double _t349 = 0.2e1*_t156;
  const double _t350 = 0.3e1*_hc0[7];
  const double _t351 = 0.2e1*_t137;
  const double _t352 = _t14*_t327;
  const double _t353 = _t62*_t75;
  const double _t354 = _t141*_t38;
  const double _t355 = _hc1[2]*_t10;
  const double _t356 = _t30*_t338;
  const double _t357 = _hc1[4]*_t18;
  const double _t358 = _t18*_t19;
  const double _t359 = _t233*_t47;
  const double _t360 = _t338*_t40;
  const double _t361 = _t62*_t87;
  const double _t362 = 0.2e1*_t56;
  const double _t363 = _t19*_t62;
  const double _t364 = _t116*_t56;
  const double _t365 = _t103*_t122;
  const double _t366 = _t191*_t47;
  const double _t367 = _t358*_t47;
  const double _t368 = _t173*_t32;
  const double _t369 = _t18*_t47;
  const double _t370 = _t141*_t46;
  const double _t371 = _t115*_t29;
  const double _t372 = _t161*_t47;
  const double _t373 = _hc1[6]*_t18;
  const double _t374 = _t18*_t41;
  const double _t375 = 0.2e1*_t62;
  const double _t376 = _t148*_t62;
  const double _t377 = _t134*_t303;
  const double _t378 = _t164*_t307;
  const double _t379 = _t135*_t369;
  const double _t380 = _hc2[0]*_t134;
  const double _t381 = _t369*_t380;
  const double _t382 = 0.3e1*_t174;
  const double _t383 = 0.3e1*_hc1[8];
  const double _t384 = 0.3e1*_t62;
  const double _t385 = _t115*_t338;
  const double _t386 = _t18*_t300;
  const double _t387 = _t183*_t32;
  const double _t388 = _t116*_t62;
  const double _t389 = _hc2[2]*_t96;
  const double _t390 = _t307*_t369;
  const double _t391 = 0.3e1*_hc0[8];
  const double _t392 = _hc2[8]*_t3;
  const double _t393 = 0.4e1*_hc1[7];
  const double _t394 = _t18*_t7;
  const double _t395 = _t18*_t327;
  const double _t396 = _hc2[5]*_t6;
  const double _t397 = _t10*_t396;
  const double _t398 = 0.2e1*_t51;
  const double _t399 = 0.4e1*_hc1[3];
  const double _t400 = 0.2e1*_t188;
  const double _t401 = _t68*_t75;
  const double _t402 = 0.4e1*_t56;
  const double _t403 = _t141*_t56;
  const double _t404 = _hc2[5]*_t29;
  const double _t405 = 0.4e1*_t18;
  const double _t406 = _t233*_t69;
  const double _t407 = _t18*_t356;
  const double _t408 = _t102*_t68;
  const double _t409 = _t148*_t68;
  const double _t410 = _t196*_t32;
  const double _t411 = _t56*_t69;
  const double _t412 = _t189*_t56;
  const double _t413 = _t103*_t198;
  const double _t414 = _t217*_t270;
  const double _t415 = _t18*_t63;
  const double _t416 = _t39*_t56;
  const double _t417 = 0.2e1*_t198;
  const double _t418 = 0.4e1*_hc0[7];
  const double _t419 = _t141*_t62;
  const double _t420 = _t116*_t68;
  const double _t421 = _t189*_t62;
  const double _t422 = _t103*_t164;
  const double _t423 = _t103*_t159;
  const double _t424 = _t145*_t191;
  const double _t425 = _t159*_t69;
  const double _t426 = _t39*_t62;
  const double _t427 = _t62*_t69;
  const double _t428 = _t217*_t380;
  const double _t429 = _t14*_t396;
  const double _t430 = 0.4e1*_hc1[8];
  const double _t431 = _t338*_t369;
  const double _t432 = _t204*_t32;
  const double _t433 = _t103*_t205;
  const double _t434 = _t134*_t389;
  const double _t435 = _t217*_t307;
  const double _t436 = 0.2e1*_t205;
  const double _t437 = 0.4e1*_hc0[8];
  const double _t438 = _hc2[9]*_t3;
  const double _t439 = _t18*_t396;
  const double _t440 = 0.6e1*_t188;
  const double _t441 = 0.3e1*_hc1[9];
  const double _t442 = _t141*_t68;
  const double _t443 = _t217*_t338;
  const double _t444 = _t18*_t206;
  const double _t445 = 0.3e1*_t68;
  const double _t446 = _t189*_t68;
  const double _t447 = _t145*_t69;
  const double _t448 = _t18*_t198;
  const double _t449 = _t217*_t223;
  const double _t450 = _t223*_t306;
  const double _t451 = 0.3e1*_t217;
  const double _t452 = _t39*_t68;
  const double _t453 = _t68*_t69;
  const double _t454 = _t135*_t223;
  const double _t455 = _hc2[0]*_t449;
  const double _t456 = _t18*_t205;
  const double _t457 = 0.4e1*_hc1[19];
  const double _t458 = 0.6e1*_hc1[9];
  const double _t459 = 0.12e2*_hc1[3];
#endif

  const double f = _hc2[0]*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t5 + _hc2[1]*_t4 + _t11*_t7;
  out[1] = df_dt;
  const double df_dz = _hc1[2]*_t5 + _t14*_t15;
  out[2] = df_dz;
  const double df_drs = _hc1[3]*_t5 + _hc2[2]*_t4 + _t15*_t18;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[4]*_t5 + _hc2[3]*_t4 + _t10*_t22 + _t15*_t27 + _t19*_t20 + _t19*_t23 + _t29*_t31;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = _hc1[2]*_t20 + _hc1[2]*_t23 + _hc1[5]*_t5 + _t14*_t21 + _t15*_t38 + _t32*_t33 + _t39*_t40;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = _hc1[6]*_t5 + _t14*_t48 + _t15*_t46 + _t41*_t42;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = _hc1[1]*_t49 + _hc1[1]*_t51 + _hc1[3]*_t20 + _hc1[3]*_t23 + _hc1[7]*_t5 + _hc2[4]*_t4 + _t10*_t50 + _t15*_t56 + _t18*_t21 + _t30*_t57;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _hc1[2]*_t49 + _hc1[2]*_t51 + _hc1[3]*_t42 + _hc1[8]*_t5 + _t14*_t50 + _t15*_t62 + _t18*_t48;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[9]*_t5 + _hc2[5]*_t4 + _t15*_t68 + _t18*_t64 + _t49*_t63 + _t51*_t63 + _t57*_t69;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc1[10]*_t5 + _hc1[4]*_t72 + _hc1[4]*_t78 + _t10*_t74 + _t15*_t85 + _t27*_t79 + _t27*_t93 + _t31*_t97 + _t70*_t71 + _t70*_t80 + _t70*_t89 + _t76*_t77 + _t86*_t88 + _t90*_t91;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = _hc1[11]*_t5 + _hc1[2]*_t71 + _hc1[2]*_t80 + _hc1[2]*_t89 + _hc1[4]*_t42 + _hc1[5]*_t98 + _t100*_t23 + _t101*_t19 + _t102*_t40 + _t104*_t19 + _t105*_t90 + _t112*_t15 + _t113*_t40 + _t14*_t73 + _t19*_t99 + _t22*_t38 + _t38*_t93 + _t41*_t76;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = _hc1[12]*_t5 + _hc1[6]*_t20 + _hc1[6]*_t23 + _t100*_t42 + _t101*_t41 + _t104*_t41 + _t105*_t122 + _t113*_t115 + _t114*_t46 + _t115*_t87 + _t116*_t33 + _t121*_t15 + _t21*_t46 + _t38*_t48 + _t41*_t99 + _t46*_t92;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = _hc1[13]*_t5 + _hc1[6]*_t123 + _t105*_t132 + _t115*_t136 + _t124*_t125 + _t124*_t130 + _t129*_t15 + _t133*_t46;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = _hc1[14]*_t5 + _hc1[3]*_t71 + _hc1[3]*_t80 + _hc1[3]*_t89 + _hc1[4]*_t49 + _hc1[4]*_t51 + _hc1[7]*_t98 + _hc2[7]*_t4 + _t10*_t139 + _t137*_t19 + _t140*_t19 + _t142*_t19 + _t143*_t23 + _t144*_t19 + _t145*_t86 + _t147*_t30 + _t149*_t19 + _t15*_t155 + _t156*_t30 + _t18*_t73 + _t22*_t56 + _t27*_t50 + _t56*_t93 + _t57*_t90 + _t63*_t76;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = _hc1[15]*_t5 + _hc1[5]*_t49 + _hc1[5]*_t51 + _hc1[7]*_t42 + _hc1[8]*_t20 + _hc1[8]*_t23 + _hc2[4]*_t157 + _hc2[4]*_t158 + _t10*_t160 + _t114*_t62 + _t116*_t164 + _t122*_t57 + _t141*_t33 + _t145*_t40 + _t146*_t47 + _t148*_t159 + _t148*_t161 + _t15*_t173 + _t156*_t47 + _t159*_t75 + _t161*_t75 + _t162*_t56 + _t163*_t38 + _t21*_t62 + _t38*_t50 + _t48*_t56 + _t62*_t92;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _hc1[16]*_t5 + _hc1[6]*_t49 + _hc1[6]*_t51 + _t115*_t145 + _t116*_t161 + _t132*_t57 + _t133*_t62 + _t15*_t183 + _t163*_t46 + _t174*_t41 + _t175*_t42 + _t176*_t41 + _t177*_t41 + _t184*_t47 + _t46*_t50;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = _hc1[1]*_t185 + _hc1[17]*_t5 + _hc1[7]*_t186 + _hc1[9]*_t20 + _hc1[9]*_t23 + _hc2[8]*_t4 + _t10*_t187 + _t114*_t68 + _t137*_t63 + _t139*_t18 + _t140*_t63 + _t142*_t63 + _t143*_t51 + _t144*_t63 + _t146*_t69 + _t149*_t63 + _t15*_t196 + _t156*_t69 + _t164*_t189 + _t188*_t19 + _t190*_t191 + _t197*_t56 + _t198*_t57 + _t21*_t68 + _t56*_t64 + _t68*_t92;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _hc1[18]*_t5 + _hc1[8]*_t186 + _hc1[9]*_t42 + _hc2[5]*_t157 + _hc2[5]*_t158 + _t15*_t204 + _t159*_t189 + _t162*_t68 + _t174*_t63 + _t175*_t51 + _t176*_t63 + _t177*_t63 + _t184*_t69 + _t188*_t41 + _t191*_t199 + _t197*_t62 + _t205*_t57 + _t48*_t68 + _t62*_t64;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[19]*_t5 + _hc1[9]*_t207 + _hc1[9]*_t210 + _hc2[9]*_t4 + _t15*_t216 + _t18*_t208 + _t185*_t206 + _t188*_t209 + _t206*_t212 + _t206*_t219 + _t211*_t68 + _t217*_t218 + _t221*_t57 + _t222*_t68 + _t223*_t224;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc1[1]*_t148*_t236 + _hc1[20]*_t5 + 0.12e2*_hc1[4]*_t76 + 0.4e1*_t10*_t87*_t90 + _t15*(-_hc0[0]*_hc1[20] - _hc0[10]*_t231 - _hc0[20]*_hc1[0] - _hc0[4]*_t226 - _hc1[10]*_t235) + _t20*_t225 + 0.4e1*_t21*_t85 + _t225*_t23 + _t226*_t71 + _t226*_t80 + _t226*_t89 + _t227*_t229 + _t227*_t230 + _t227*_t234 + _t231*_t239 + _t231*_t246 + _t231*_t32*_t85 + 0.6e1*_t232*_t86 + _t236*_t237 + _t238*_t249 + _t240*_t91 + _t241*_t85 + _t242*_t243 + _t243*_t248 + 0.4e1*_t244*_t86 + _t247*_t31*_t96 + _t252*_t31 + 0.6e1*_t27*_t73;
  out[20] = d4f_dt4;
  const double d4f_dz_dt3 = _hc1[10]*_t42 + _hc1[11]*_t72 + _hc1[11]*_t78 + _hc1[2]*_t239 + _hc1[2]*_t246 + _hc1[21]*_t5 + _hc1[4]*_t255 + _hc1[5]*_t256 + _t104*_t262 + _t105*_t240 + _t112*_t241 + _t112*_t79 + _t124*_t229 + _t124*_t230 + _t124*_t234 + _t15*(-_hc0[0]*_hc1[21] - _hc0[10]*_hc1[2] - _hc0[11]*_t70 - _hc0[2]*_hc1[10] - _hc0[21]*_hc1[0] - _hc0[4]*_t253 - _hc1[11]*_t274 - _hc1[4]*_t275) + _t162*_t85 + _t232*_t260 + _t242*_t259 + _t244*_t260 + _t248*_t259 + _t253*_t71 + _t253*_t80 + _t253*_t89 + _t254*_t70 + _t257*_t77 + _t258*_t259 + 0.6e1*_t261*_t33 + _t263*_t273 + _t263*_t88 + _t265*_t70 + _t266*_t41 + _t267*_t70 + _t268*_t38 + _t269*_t77 + _t271*_t70 + _t272*_t40 + _t276*_t40 + _t38*_t74;
  out[21] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = _hc1[11]*_t277 + _hc1[12]*_t278 + _hc1[12]*_t98 + _hc1[22]*_t5 + _hc1[4]*_t130 + _hc1[6]*_t280 + _hc1[6]*_t71 + _hc1[6]*_t80 + _hc1[6]*_t89 + _hc2[1]*_t115*_t249 + _t101*_t279 + _t102*_t285 + _t102*_t290 + _t104*_t279 + _t105*_t294 + _t112*_t48 + _t113*_t285 + _t115*_t232 + _t115*_t272 + _t115*_t276 + _t121*_t22 + _t121*_t93 + _t15*(-_hc0[0]*_hc1[22] - _hc0[11]*_t41 - _hc0[12]*_t19 - _hc0[22]*_hc1[0] - _hc0[4]*_hc1[6] - _hc0[6]*_hc1[4] - _hc1[11]*_t45 - _hc1[12]*_t110 - _hc1[5]*_t297) + _t19*_t281 + _t19*_t283 + _t19*_t286 + _t19*_t287 + _t19*_t291 + _t19*_t292 + _t19*_t293 + _t242*_t46 + _t254*_t41 + _t257*_t282 + _t258*_t46 + _t265*_t41 + _t267*_t41 + _t269*_t282 + _t271*_t41 + _t273*_t290 + _t279*_t99 + _t282*_t284 + _t288*_t289 + _t289*_t295 + _t289*_t296 + _t46*_t73;
  out[22] = d4f_dz2_dt2;
  const double d4f_dz3_dt = _hc1[12]*_t123 + _hc1[13]*_t20 + _hc1[13]*_t23 + _hc1[23]*_t5 + 0.3e1*_hc1[6]*_t104 + _hc1[6]*_t255 + _t105*_t309 + _t113*_t299 + _t114*_t129 + _t121*_t133 + _t124*_t281 + _t124*_t283 + _t124*_t286 + _t124*_t287 + _t124*_t291 + _t124*_t292 + _t124*_t293 + _t125*_t253 + _t129*_t21 + _t129*_t92 + _t130*_t253 + _t136*_t290 + _t15*(-_hc0[0]*_hc1[23] - _hc0[1]*_hc1[13] - _hc0[12]*_t124 - _hc0[13]*_hc1[1] - _hc0[23]*_hc1[0] - _hc0[6]*_t253 - _hc1[12]*_t128 - _hc1[6]*_t275) + _t19*_t302 + _t251*_t313 + _t259*_t298 + _t288*_t301 + _t295*_t301 + _t296*_t301 + _t299*_t87 + _t300*_t33 + _t303*_t304 + _t305*_t307 + _t308*_t38 + _t310*_t38 + _t311*_t312;
  out[23] = d4f_dz3_dt;
  const double d4f_dz4 = 0.4e1*_hc1[13]*_t42 + 0.8e1*_hc1[2]*_t302 + _hc1[24]*_t5 + _t103*_t282*_t299 + _t105*_t316 + _t125*_t314 + _t129*_t282*_t32 + _t129*_t317 + _t130*_t314 + _t15*(-_hc0[0]*_hc1[24] - _hc0[13]*_t282 - _hc0[24]*_hc1[0] - _hc0[6]*_t314 - _hc1[13]*_t131) + _t282*_t304*_t306 + _t299*_t320 + _t308*_t318 + _t310*_t318 + _t312*_t319 + _t313*_t321;
  out[24] = d4f_dz4;
  const double d4f_drs_dt3 = _hc1[10]*_t49 + _hc1[10]*_t51 + _hc1[14]*_t72 + _hc1[14]*_t78 + _hc1[25]*_t5 + _hc1[3]*_t239 + _hc1[3]*_t246 + _hc1[4]*_t323 + _hc1[7]*_t256 + 0.3e1*_hc2[7]*_t325 + _t10*_t340 + _t140*_t262 + _t142*_t262 + 0.3e1*_t146*_t90 + _t149*_t262 + _t15*(-_hc0[0]*_hc1[25] - _hc0[10]*_hc1[3] - _hc0[14]*_t70 - _hc0[25]*_hc1[0] - _hc0[3]*_hc1[10] - _hc0[4]*_t324 - _hc1[14]*_t274 - _hc1[4]*_t350) + _t155*_t241 + _t155*_t79 + _t163*_t85 + _t18*_t276*_t30 + _t18*_t347*_t70 + _t206*_t229 + _t206*_t230 + _t206*_t234 + _t240*_t57 + _t242*_t332 + _t244*_t346 + _t248*_t332 + _t258*_t332 + _t266*_t63 + _t268*_t56 + _t27*_t329 + _t27*_t341 + _t30*_t348 + _t322*_t70 + _t324*_t71 + _t324*_t80 + _t324*_t89 + _t326*_t70 + _t328*_t77 + _t330*_t70 + _t331*_t77 + _t333*_t334 + _t336*_t86 + _t337*_t77 + _t339*_t70 + _t342*_t70 + _t343*_t70 + _t344*_t77 + _t345*_t86 + _t349*_t90 + _t50*_t85 + _t56*_t74;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dz_dt2 = _hc1[11]*_t49 + _hc1[11]*_t51 + _hc1[14]*_t42 + _hc1[15]*_t278 + _hc1[15]*_t98 + _hc1[26]*_t5 + _hc1[4]*_t174 + _hc1[5]*_t351 + _hc1[8]*_t71 + _hc1[8]*_t80 + _hc1[8]*_t89 + _hc2[7]*_t157 + _hc2[7]*_t158 + _t100*_t140 + _t100*_t142 + _t100*_t144 + _t100*_t149 + _t101*_t143 + _t104*_t143 + _t112*_t163 + _t112*_t50 + _t116*_t357 + _t122*_t147 + _t122*_t349 + _t139*_t38 + _t14*_t340 + _t143*_t99 + _t148*_t363 + _t15*(-_hc0[0]*_hc1[26] - _hc0[11]*_hc1[3] - _hc0[14]*_hc1[2] - _hc0[15]*_t19 - _hc0[2]*_hc1[14] - _hc0[26]*_hc1[0] - _hc0[3]*_hc1[11] - _hc0[4]*_hc1[8] - _hc0[8]*_hc1[4] - _hc1[15]*_t110 - _hc1[5]*_t154 - _hc1[7]*_t111) + _t155*_t162 + _t155*_t48 + _t159*_t228 + _t159*_t264 + _t159*_t347 + _t160*_t27 + _t161*_t228 + _t161*_t264 + _t161*_t347 + _t173*_t22 + _t173*_t93 + _t175*_t76 + _t19*_t352 + _t19*_t353 + _t19*_t354 + _t19*_t360 + _t19*_t364 + _t19*_t368 + _t190*_t289 + _t242*_t62 + _t244*_t366 + _t248*_t62 + _t257*_t63 + _t258*_t62 + _t269*_t63 + _t270*_t367 + _t276*_t369 + _t284*_t63 + _t288*_t362 + _t294*_t57 + _t295*_t362 + _t296*_t362 + 0.2e1*_t30*_t361 + _t328*_t41 + _t331*_t41 + _t333*_t47 + 0.2e1*_t335*_t40 + _t337*_t41 + _t344*_t41 + _t345*_t40 + _t348*_t47 + _t355*_t356 + _t358*_t359 + _t358*_t365 + _t62*_t73;
  out[26] = d4f_drs_dz_dt2;
  const double d4f_drs_dz2_dt = _hc1[1]*_t370 + _hc1[12]*_t49 + _hc1[12]*_t51 + _hc1[15]*_t277 + _hc1[16]*_t20 + _hc1[16]*_t23 + _hc1[27]*_t5 + _hc1[3]*_t281 + _hc1[3]*_t286 + _hc1[3]*_t291 + _hc1[6]*_t137 + _hc1[6]*_t140 + _hc1[6]*_t142 + _hc1[7]*_t125 + _hc1[7]*_t130 + _hc2[4]*_t371 + _t100*_t174 + _t100*_t176 + _t100*_t177 + _t101*_t175 + _t104*_t175 + _t114*_t183 + _t115*_t345 + _t116*_t363 + _t121*_t163 + _t121*_t50 + _t122*_t184 + _t132*_t146 + _t132*_t156 + _t133*_t173 + _t138*_t46 + _t145*_t290 + _t148*_t373 + _t15*(-_hc0[0]*_hc1[27] - _hc0[1]*_hc1[16] - _hc0[12]*_hc1[3] - _hc0[15]*_t41 - _hc0[16]*_hc1[1] - _hc0[27]*_hc1[0] - _hc0[3]*_hc1[12] - _hc0[6]*_hc1[7] - _hc0[7]*_hc1[6] - _hc1[15]*_t45 - _hc1[5]*_t182 - _hc1[8]*_t111) + _t161*_t365 + _t164*_t300 + _t175*_t99 + _t183*_t21 + _t183*_t92 + _t190*_t46 + _t199*_t38 + _t233*_t372 + _t251*_t381 + _t270*_t372 + _t270*_t374*_t47 + _t288*_t375 + _t295*_t375 + _t296*_t375 + _t298*_t56 + _t305*_t338 + _t308*_t56 + _t309*_t57 + _t310*_t56 + _t311*_t379 + _t352*_t41 + _t353*_t41 + _t354*_t41 + _t359*_t374 + _t360*_t41 + _t364*_t41 + _t365*_t374 + _t368*_t41 + _t369*_t377 + _t376*_t41 + _t378*_t47;
  out[27] = d4f_drs_dz2_dt;
  const double d4f_drs_dz3 = _hc1[13]*_t49 + _hc1[13]*_t51 + _hc1[16]*_t123 + _hc1[28]*_t5 + _hc1[6]*_t382 + 0.3e1*_t116*_t373 + _t124*_t370 + _t124*_t385 + _t124*_t386 + _t124*_t387 + _t124*_t390 + _t125*_t383 + _t129*_t163 + _t129*_t50 + _t130*_t383 + 0.2e1*_t132*_t184 + _t145*_t299 + _t15*(-_hc0[0]*_hc1[28] - _hc0[13]*_hc1[3] - _hc0[16]*_t124 - _hc0[28]*_hc1[0] - _hc0[3]*_hc1[13] - _hc0[6]*_t383 - _hc1[16]*_t128 - _hc1[6]*_t391) + _t161*_t300 + _t183*_t317 + _t199*_t301 + _t298*_t384 + _t302*_t63 + _t304*_t389 + _t307*_t372 + _t308*_t384 + _t310*_t384 + _t315*_t388 + _t316*_t57 + _t319*_t379 + _t321*_t381;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = _hc1[14]*_t186 + _hc1[14]*_t398 + _hc1[17]*_t278 + _hc1[17]*_t98 + _hc1[29]*_t5 + _hc1[4]*_t185 + _hc1[4]*_t400 + _hc1[9]*_t280 + _hc1[9]*_t71 + _hc1[9]*_t80 + _hc1[9]*_t89 + _hc2[12]*_t4 + 0.2e1*_hc2[7]*_t394 + 0.2e1*_hc2[8]*_t325 + _t102*_t411 + _t113*_t362*_t69 + _t137*_t393 + _t138*_t402 + _t140*_t393 + _t142*_t393 + _t144*_t393 + _t147*_t198 + _t149*_t393 + _t15*(-_hc0[0]*_hc1[29] - _hc0[14]*_t63 - _hc0[17]*_t19 - _hc0[29]*_hc1[0] - _hc0[4]*_hc1[9] - _hc0[9]*_hc1[4] - _hc1[14]*_t67 - _hc1[17]*_t110 - _hc1[7]*_t418) + _t155*_t197 + _t155*_t64 + _t156*_t417 + _t187*_t27 + _t189*_t357 + _t19*_t392 + _t19*_t397 + _t19*_t401 + _t19*_t409 + _t19*_t410 + _t19*_t412 + _t19*_t414 + _t190*_t402 + _t191*_t244*_t69 + _t191*_t30*_t345 + _t191*_t340 + _t196*_t22 + _t196*_t93 + _t217*_t276 + _t224*_t247 + _t231*_t395 + _t231*_t403 + _t231*_t407 + _t242*_t68 + _t248*_t68 + _t258*_t68 + _t30*_t335*_t405 + _t30*_t408 + _t322*_t63 + _t326*_t63 + _t328*_t399 + _t330*_t63 + _t331*_t399 + _t333*_t69 + _t337*_t399 + _t339*_t63 + _t342*_t63 + _t343*_t63 + _t344*_t399 + _t347*_t415 + _t358*_t406 + _t358*_t413 + _t404*_t86 + _t416*_t417 + _t57*(-_hc0[7]*_t231 - _hc1[7]*_t235 - 0.2e1*_t150 - 0.2e1*_t151 - 0.2e1*_t152 - 0.2e1*_t153) + _t68*_t73;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dz_dt = _hc1[1]*_t420 + _hc1[1]*_t421 + _hc1[15]*_t186 + _hc1[15]*_t398 + _hc1[17]*_t42 + _hc1[18]*_t20 + _hc1[18]*_t23 + _hc1[2]*_t401 + _hc1[2]*_t409 + _hc1[2]*_t412 + _hc1[30]*_t5 + _hc1[5]*_t185 + _hc1[5]*_t212 + _hc1[5]*_t219 + _hc1[8]*_t351 + _hc1[9]*_t101 + _hc1[9]*_t104 + _hc1[9]*_t99 + _hc2[8]*_t157 + _hc2[8]*_t158 + _t100*_t188 + _t113*_t427 + _t114*_t204 + _t122*_t424 + _t136*_t411 + _t139*_t62 + _t140*_t175 + _t142*_t175 + _t143*_t174 + _t143*_t176 + _t143*_t177 + _t144*_t175 + _t146*_t205 + _t149*_t175 + _t15*(-_hc0[0]*_hc1[30] - _hc0[1]*_hc1[18] - _hc0[15]*_t63 - _hc0[17]*_hc1[2] - _hc0[18]*_hc1[1] - _hc0[2]*_hc1[17] - _hc0[30]*_hc1[0] - _hc0[5]*_hc1[9] - _hc0[9]*_hc1[5] - _hc1[15]*_t67 - _hc1[7]*_t182 - _hc1[8]*_t154) + _t156*_t205 + _t159*_t406 + _t162*_t196 + _t173*_t197 + _t173*_t64 + _t184*_t198 + _t187*_t38 + _t19*_t419 + _t196*_t48 + _t198*_t423 + _t198*_t426 + _t199*_t362 + _t204*_t21 + _t204*_t92 + _t205*_t416 + _t205*_t422 + _t217*_t377 + _t224*_t311 + _t251*_t428 + _t270*_t369*_t63 + _t270*_t425 + _t288*_t68 + _t295*_t68 + _t296*_t68 + _t33*_t396 + _t335*_t366 + _t338*_t367 + _t341*_t62 + _t345*_t366 + _t352*_t63 + _t353*_t63 + _t354*_t63 + _t355*_t396 + _t356*_t374 + _t359*_t415 + _t360*_t63 + _t361*_t69 + _t364*_t63 + _t365*_t415 + _t368*_t63 + _t376*_t63 + _t378*_t69 + _t395*_t41 + _t40*_t404 + _t403*_t41 + _t57*(-0.2e1*_t165 - 0.2e1*_t166 - 0.2e1*_t167 - 0.2e1*_t168 - 0.2e1*_t169 - 0.2e1*_t170 - 0.2e1*_t171 - 0.2e1*_t172);
  out[30] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz2 = _hc1[16]*_t186 + _hc1[16]*_t398 + _hc1[18]*_t277 + _hc1[31]*_t5 + _hc1[6]*_t185 + _hc1[6]*_t400 + _hc1[9]*_t125 + _hc1[9]*_t130 + _hc2[5]*_t371 + _t132*_t424 + _t133*_t204 + _t136*_t375*_t69 + _t15*(-_hc0[0]*_hc1[31] - _hc0[16]*_t63 - _hc0[18]*_t41 - _hc0[31]*_hc1[0] - _hc0[6]*_hc1[9] - _hc0[9]*_hc1[6] - _hc1[16]*_t67 - _hc1[18]*_t45 - _hc1[8]*_t437) + _t174*_t430 + _t176*_t430 + _t177*_t430 + _t183*_t197 + _t183*_t64 + _t184*_t436 + _t187*_t46 + _t189*_t373 + 0.4e1*_t199*_t62 + _t224*_t319 + _t282*_t419 + _t282*_t431 + _t298*_t68 + _t308*_t68 + _t310*_t68 + _t321*_t428 + _t366*_t434 + _t370*_t63 + _t374*_t433 + _t385*_t63 + _t386*_t63 + _t387*_t63 + _t388*_t399 + _t390*_t63 + _t41*_t420 + _t41*_t421 + _t41*_t429 + _t41*_t432 + _t41*_t435 + _t426*_t436 + _t57*(-_hc0[8]*_t282 - _hc1[8]*_t131 - 0.2e1*_t178 - 0.2e1*_t179 - 0.2e1*_t180 - 0.2e1*_t181);
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dt = _hc1[1]*_t438 + _hc1[17]*_t207 + _hc1[17]*_t210 + _hc1[19]*_t20 + _hc1[19]*_t23 + _hc1[32]*_t5 + _hc1[7]*_t440 + _hc1[9]*_t323 + _hc2[13]*_t4 + 0.3e1*_hc2[8]*_t394 + _hc2[9]*_t325 + _t114*_t216 + _t140*_t441 + _t142*_t441 + _t144*_t441 + _t146*_t221 + _t149*_t441 + _t15*(-_hc0[0]*_hc1[32] - _hc0[1]*_hc1[19] - _hc0[17]*_t206 - _hc0[19]*_hc1[1] - _hc0[32]*_hc1[0] - _hc0[9]*_t324 - _hc1[17]*_t215 - _hc1[9]*_t350) + _t156*_t221 + _t164*_t450*_t69 + _t185*_t324 + _t19*_t446 + _t190*_t445 + _t196*_t211 + _t196*_t222 + _t206*_t392 + _t206*_t397 + _t206*_t401 + _t206*_t409 + _t206*_t410 + _t206*_t412 + _t206*_t414 + _t208*_t56 + _t209*_t395 + _t209*_t403 + _t209*_t407 + _t21*_t216 + _t212*_t324 + _t216*_t92 + _t217*_t336 + _t218*_t448 + _t219*_t324 + _t221*_t416 + _t221*_t422 + _t224*(-0.3e1*_t52 - 0.3e1*_t53 - 0.3e1*_t54 - 0.3e1*_t55) + _t251*_t455 + _t273*_t453 + _t303*_t449 + _t329*_t68 + _t332*_t447 + _t345*_t451 + _t346*_t404 + _t406*_t444 + _t408*_t69 + _t411*_t454 + _t413*_t444 + _t417*_t452 + _t439*_t70 + _t442*_t70 + _t443*_t70 + _t448*_t454 + _t57*(-_hc1[3]*_t418 - _hc1[7]*_t220 - 0.2e1*_t192 - 0.2e1*_t193 - 0.2e1*_t194 - 0.2e1*_t195);
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dz = _hc1[18]*_t207 + _hc1[18]*_t210 + _hc1[19]*_t42 + _hc1[33]*_t5 + _hc1[8]*_t440 + _hc1[9]*_t382 + _hc2[9]*_t157 + _hc2[9]*_t158 + _t124*_t439 + _t124*_t442 + _t124*_t443 + _t15*(-_hc0[0]*_hc1[33] - _hc0[18]*_t206 - _hc0[19]*_hc1[2] - _hc0[2]*_hc1[19] - _hc0[33]*_hc1[0] - _hc0[9]*_t383 - _hc1[18]*_t215 - _hc1[9]*_t391) + _t162*_t216 + _t176*_t441 + _t177*_t441 + _t184*_t221 + _t185*_t383 + _t199*_t445 + _t204*_t211 + _t204*_t222 + _t206*_t420 + _t206*_t421 + _t206*_t429 + _t206*_t432 + _t206*_t435 + _t208*_t62 + _t209*_t419 + _t209*_t431 + _t212*_t383 + _t216*_t48 + _t218*_t456 + _t219*_t383 + _t221*_t423 + _t221*_t426 + _t224*(-0.3e1*_t58 - 0.3e1*_t59 - 0.3e1*_t60 - 0.3e1*_t61) + _t320*_t453 + _t321*_t455 + 0.3e1*_t369*_t404 + _t384*_t447 + _t41*_t446 + _t425*_t450 + _t427*_t454 + _t433*_t444 + _t434*_t451 + _t436*_t452 + _t454*_t456 + _t57*(-_hc1[3]*_t437 - _hc1[8]*_t220 - 0.2e1*_t200 - 0.2e1*_t201 - 0.2e1*_t202 - 0.2e1*_t203);
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = 0.8e1*_hc1[3]*_t446 + _hc1[34]*_t5 + 0.12e2*_hc1[9]*_t188 + _hc2[14]*_t4 + 0.4e1*_hc2[9]*_t394 + _t103*_t18*_t221*_t399 + _t145*_t221*_t405 + _t15*(-_hc0[0]*_hc1[34] - _hc0[19]*_t399 - _hc0[34]*_hc1[0] - _hc0[9]*_t458 - _hc1[19]*_t220) + _t185*_t458 + 0.6e1*_t187*_t68 + _t191*_t221*_t454 + 0.3e1*_t197*_t216 + _t212*_t458 + _t216*_t32*_t399 + 0.4e1*_t216*_t50 + 0.6e1*_t217*_t404 + _t219*_t458 + 0.3e1*_t221*_t452 + _t224*(-_hc0[3]*_t209 - 0.3e1*_t65 - 0.3e1*_t66) + _t250*_t455*(-0.4e1*_t16 - 0.4e1*_t17) + _t306*_t399*_t449 + 0.4e1*_t389*_t449 + _t399*_t438 + _t439*_t459 + _t442*_t459 + _t443*_t459 + _t445*_t454*_t69 + 0.8e1*_t447*_t68 + _t457*_t49 + _t457*_t51 + _t57*(-_hc0[3]*_t458 - _hc0[9]*_t209 - 0.2e1*_t213 - 0.2e1*_t214);
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_grad_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(tp_k, _KMAX)(p, rs, z, xt, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(fH_k, _KMAX)(p, rs, z, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = ((_hc0[1]) * (_hc0[1]));
  const double _t2 = _hc0[2]*_hc1[4];
  const double _t3 = _hc1[5] + _t2;
  const double _t4 = _hc0[3]*_hc1[4];
  const double _t5 = _hc1[7] + _t4;
#endif
#if _KMAX >= 3
  const double _t6 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t7 = _hc0[5]*_hc1[4];
  const double _t8 = 0.2e1*_hc0[1];
  const double _t9 = _hc0[2]*_hc1[10];
  const double _t10 = _hc0[1]*_hc1[11];
  const double _t11 = _hc0[6]*_hc1[4];
  const double _t12 = _hc0[1]*_t9 + _t10 + _t7;
  const double _t13 = _hc0[2]*_hc1[11] + _hc1[12];
  const double _t14 = 0.2e1*_t3;
  const double _t15 = _hc1[11] + _t9;
  const double _t16 = _hc0[2]*_t15 + _t11 + _t13;
  const double _t17 = _hc0[7]*_hc1[4];
  const double _t18 = _hc0[3]*_hc1[10];
  const double _t19 = _hc0[2]*_hc1[14];
  const double _t20 = _hc0[8]*_hc1[4];
  const double _t21 = _hc1[15] + _t19;
  const double _t22 = _hc0[1]*_hc1[14];
  const double _t23 = _hc0[9]*_hc1[4];
  const double _t24 = _hc0[1]*_t18 + _t17 + _t22;
  const double _t25 = _hc0[3]*_t15 + _t20 + _t21;
  const double _t26 = _hc0[3]*_hc1[14] + _hc1[17];
  const double _t27 = 0.2e1*_t5;
  const double _t28 = _hc1[14] + _t18;
  const double _t29 = _hc0[3]*_t28 + _t23 + _t26;
#endif
#if _KMAX >= 4
  const double _t30 = _hc0[2]*_hc1[20];
  const double _t31 = _hc0[5]*_hc1[10];
  const double _t32 = 0.3e1*_t1;
  const double _t33 = _hc0[12]*_hc1[4];
  const double _t34 = 0.2e1*_hc0[5];
  const double _t35 = _hc1[21]*_t1;
  const double _t36 = _hc0[6]*_hc1[10];
  const double _t37 = 0.2e1*_t12;
  const double _t38 = _t1*_t30 + _t31*_t8 + _t35;
  const double _t39 = _hc0[13]*_hc1[4];
  const double _t40 = _hc0[1]*_hc1[22];
  const double _t41 = _hc0[1]*_hc1[21];
  const double _t42 = _hc0[2]*_t41 + _hc0[5]*_hc1[11] + _t40;
  const double _t43 = _hc0[1]*_t30 + _t31 + _t41;
  const double _t44 = _hc0[1]*_t36 + _hc0[2]*_t43 + _hc0[5]*_t15 + _t33 + _t42;
  const double _t45 = _hc0[2]*_hc1[22] + _hc1[23];
  const double _t46 = 0.3e1*_t3;
  const double _t47 = 0.2e1*_hc0[6];
  const double _t48 = _hc0[2]*_hc1[21] + _hc1[22];
  const double _t49 = _hc0[2]*_t48 + _hc0[6]*_hc1[11] + _t45;
  const double _t50 = 0.3e1*_t16;
  const double _t51 = _hc1[21] + _t30;
  const double _t52 = _hc0[2]*_t51 + _t36 + _t48;
  const double _t53 = _hc0[2]*_t52 + _t15*_t47 + _t39 + _t49;
  const double _t54 = _hc0[3]*_hc1[20];
  const double _t55 = _hc0[7]*_hc1[10];
  const double _t56 = _hc0[15]*_hc1[4];
  const double _t57 = _hc0[2]*_hc1[25];
  const double _t58 = _hc0[8]*_hc1[10];
  const double _t59 = _hc0[16]*_hc1[4];
  const double _t60 = _hc0[1]*_hc1[26];
  const double _t61 = _hc0[1]*_t57 + _hc0[5]*_hc1[14] + _t60;
  const double _t62 = _hc0[2]*_hc1[26] + _hc1[27];
  const double _t63 = _hc1[26] + _t57;
  const double _t64 = _hc0[2]*_t63 + _hc0[6]*_hc1[14] + _t62;
  const double _t65 = _hc0[17]*_hc1[4];
  const double _t66 = _hc1[25]*_t1;
  const double _t67 = _hc0[9]*_hc1[10];
  const double _t68 = 0.2e1*_t24;
  const double _t69 = _hc0[18]*_hc1[4];
  const double _t70 = _hc0[2]*_hc1[29];
  const double _t71 = _hc1[30] + _t70;
  const double _t72 = 0.2e1*_hc0[8];
  const double _t73 = _hc0[19]*_hc1[4];
  const double _t74 = _hc0[1]*_hc1[29];
  const double _t75 = _hc0[1]*_hc1[25];
  const double _t76 = _hc0[3]*_t75 + _hc0[7]*_hc1[14] + _t74;
  const double _t77 = _hc0[3]*_t63 + _hc0[8]*_hc1[14] + _t71;
  const double _t78 = 0.2e1*_hc0[9];
  const double _t79 = _hc0[3]*_hc1[29] + _hc1[32];
  const double _t80 = _hc0[3]*_hc1[25] + _hc1[29];
  const double _t81 = _hc0[3]*_t80 + _hc0[9]*_hc1[14] + _t79;
#endif

  const double f = _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0;
  out[1] = df_dxs1;
  const double df_dxs0 = 0;
  out[2] = df_dxs0;
  const double df_dxt = _hc0[1]*_hc1[1];
  out[3] = df_dxt;
  const double df_dz = _hc0[2]*_hc1[1] + _hc1[2];
  out[4] = df_dz;
  const double df_drs = _hc0[3]*_hc1[1] + _hc1[3];
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[6] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[7] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[8] = d2f_dxs02;
  const double d2f_dxt_dxs1 = 0;
  out[9] = d2f_dxt_dxs1;
  const double d2f_dxt_dxs0 = 0;
  out[10] = d2f_dxt_dxs0;
  const double d2f_dxt2 = _hc1[4]*_t1;
  out[11] = d2f_dxt2;
  const double d2f_dz_dxs1 = 0;
  out[12] = d2f_dz_dxs1;
  const double d2f_dz_dxs0 = 0;
  out[13] = d2f_dz_dxs0;
  const double d2f_dz_dxt = _hc0[1]*_hc1[5] + _hc0[1]*_t2 + _hc0[5]*_hc1[1];
  out[14] = d2f_dz_dxt;
  const double d2f_dz2 = _hc0[2]*_hc1[5] + _hc0[2]*_t3 + _hc0[6]*_hc1[1] + _hc1[6];
  out[15] = d2f_dz2;
  const double d2f_drs_dxs1 = 0;
  out[16] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[17] = d2f_drs_dxs0;
  const double d2f_drs_dxt = _hc0[1]*_hc1[7] + _hc0[1]*_t4 + _hc0[7]*_hc1[1];
  out[18] = d2f_drs_dxt;
  const double d2f_drs_dz = _hc0[2]*_hc1[7] + _hc0[3]*_t3 + _hc0[8]*_hc1[1] + _hc1[8];
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[3]*_hc1[7] + _hc0[3]*_t5 + _hc0[9]*_hc1[1] + _hc1[9];
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[21] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[22] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[23] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[24] = d3f_dxs03;
  const double d3f_dxt_dxs12 = 0;
  out[25] = d3f_dxt_dxs12;
  const double d3f_dxt_dxs0_dxs1 = 0;
  out[26] = d3f_dxt_dxs0_dxs1;
  const double d3f_dxt_dxs02 = 0;
  out[27] = d3f_dxt_dxs02;
  const double d3f_dxt2_dxs1 = 0;
  out[28] = d3f_dxt2_dxs1;
  const double d3f_dxt2_dxs0 = 0;
  out[29] = d3f_dxt2_dxs0;
  const double d3f_dxt3 = _hc1[10]*_t6;
  out[30] = d3f_dxt3;
  const double d3f_dz_dxs12 = 0;
  out[31] = d3f_dz_dxs12;
  const double d3f_dz_dxs0_dxs1 = 0;
  out[32] = d3f_dz_dxs0_dxs1;
  const double d3f_dz_dxs02 = 0;
  out[33] = d3f_dz_dxs02;
  const double d3f_dz_dxt_dxs1 = 0;
  out[34] = d3f_dz_dxt_dxs1;
  const double d3f_dz_dxt_dxs0 = 0;
  out[35] = d3f_dz_dxt_dxs0;
  const double d3f_dz_dxt2 = _hc1[11]*_t1 + _t1*_t9 + _t7*_t8;
  out[36] = d3f_dz_dxt2;
  const double d3f_dz2_dxs1 = 0;
  out[37] = d3f_dz2_dxs1;
  const double d3f_dz2_dxs0 = 0;
  out[38] = d3f_dz2_dxs0;
  const double d3f_dz2_dxt = _hc0[1]*_hc1[12] + _hc0[1]*_t11 + _hc0[12]*_hc1[1] + _hc0[2]*_t10 + _hc0[2]*_t12 + _hc0[5]*_hc1[5] + _hc0[5]*_t3;
  out[39] = d3f_dz2_dxt;
  const double d3f_dz3 = _hc0[13]*_hc1[1] + _hc0[2]*_hc1[12] + _hc0[2]*_t13 + _hc0[2]*_t16 + _hc0[6]*_hc1[5] + _hc0[6]*_t14 + _hc1[13];
  out[40] = d3f_dz3;
  const double d3f_drs_dxs12 = 0;
  out[41] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[42] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[43] = d3f_drs_dxs02;
  const double d3f_drs_dxt_dxs1 = 0;
  out[44] = d3f_drs_dxt_dxs1;
  const double d3f_drs_dxt_dxs0 = 0;
  out[45] = d3f_drs_dxt_dxs0;
  const double d3f_drs_dxt2 = _hc1[14]*_t1 + _t1*_t18 + _t17*_t8;
  out[46] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxs1 = 0;
  out[47] = d3f_drs_dz_dxs1;
  const double d3f_drs_dz_dxs0 = 0;
  out[48] = d3f_drs_dz_dxs0;
  const double d3f_drs_dz_dxt = _hc0[1]*_hc1[15] + _hc0[1]*_t19 + _hc0[1]*_t20 + _hc0[15]*_hc1[1] + _hc0[3]*_t12 + _hc0[5]*_hc1[7] + _hc0[7]*_t3;
  out[49] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = _hc0[16]*_hc1[1] + _hc0[2]*_hc1[15] + _hc0[2]*_t21 + _hc0[3]*_t16 + _hc0[6]*_hc1[7] + _hc0[8]*_t14 + _hc1[16];
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dxs1 = 0;
  out[51] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[52] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = _hc0[1]*_hc1[17] + _hc0[1]*_t23 + _hc0[17]*_hc1[1] + _hc0[3]*_t22 + _hc0[3]*_t24 + _hc0[7]*_hc1[7] + _hc0[7]*_t5;
  out[53] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _hc0[18]*_hc1[1] + _hc0[2]*_hc1[17] + _hc0[3]*_t21 + _hc0[3]*_t25 + _hc0[8]*_hc1[7] + _hc0[8]*_t5 + _hc0[9]*_t3 + _hc1[18];
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[19]*_hc1[1] + _hc0[3]*_hc1[17] + _hc0[3]*_t26 + _hc0[3]*_t29 + _hc0[9]*_hc1[7] + _hc0[9]*_t27 + _hc1[19];
  out[55] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[56] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[57] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[58] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[59] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[60] = d4f_dxs04;
  const double d4f_dxt_dxs13 = 0;
  out[61] = d4f_dxt_dxs13;
  const double d4f_dxt_dxs0_dxs12 = 0;
  out[62] = d4f_dxt_dxs0_dxs12;
  const double d4f_dxt_dxs02_dxs1 = 0;
  out[63] = d4f_dxt_dxs02_dxs1;
  const double d4f_dxt_dxs03 = 0;
  out[64] = d4f_dxt_dxs03;
  const double d4f_dxt2_dxs12 = 0;
  out[65] = d4f_dxt2_dxs12;
  const double d4f_dxt2_dxs0_dxs1 = 0;
  out[66] = d4f_dxt2_dxs0_dxs1;
  const double d4f_dxt2_dxs02 = 0;
  out[67] = d4f_dxt2_dxs02;
  const double d4f_dxt3_dxs1 = 0;
  out[68] = d4f_dxt3_dxs1;
  const double d4f_dxt3_dxs0 = 0;
  out[69] = d4f_dxt3_dxs0;
  const double d4f_dxt4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[20];
  out[70] = d4f_dxt4;
  const double d4f_dz_dxs13 = 0;
  out[71] = d4f_dz_dxs13;
  const double d4f_dz_dxs0_dxs12 = 0;
  out[72] = d4f_dz_dxs0_dxs12;
  const double d4f_dz_dxs02_dxs1 = 0;
  out[73] = d4f_dz_dxs02_dxs1;
  const double d4f_dz_dxs03 = 0;
  out[74] = d4f_dz_dxs03;
  const double d4f_dz_dxt_dxs12 = 0;
  out[75] = d4f_dz_dxt_dxs12;
  const double d4f_dz_dxt_dxs0_dxs1 = 0;
  out[76] = d4f_dz_dxt_dxs0_dxs1;
  const double d4f_dz_dxt_dxs02 = 0;
  out[77] = d4f_dz_dxt_dxs02;
  const double d4f_dz_dxt2_dxs1 = 0;
  out[78] = d4f_dz_dxt2_dxs1;
  const double d4f_dz_dxt2_dxs0 = 0;
  out[79] = d4f_dz_dxt2_dxs0;
  const double d4f_dz_dxt3 = _hc1[21]*_t6 + _t30*_t6 + _t31*_t32;
  out[80] = d4f_dz_dxt3;
  const double d4f_dz2_dxs12 = 0;
  out[81] = d4f_dz2_dxs12;
  const double d4f_dz2_dxs0_dxs1 = 0;
  out[82] = d4f_dz2_dxs0_dxs1;
  const double d4f_dz2_dxs02 = 0;
  out[83] = d4f_dz2_dxs02;
  const double d4f_dz2_dxt_dxs1 = 0;
  out[84] = d4f_dz2_dxt_dxs1;
  const double d4f_dz2_dxt_dxs0 = 0;
  out[85] = d4f_dz2_dxt_dxs0;
  const double d4f_dz2_dxt2 = _hc0[2]*_t35 + _hc0[2]*_t38 + _hc0[5]*_t37 + _hc1[22]*_t1 + _t1*_t36 + _t10*_t34 + _t33*_t8;
  out[86] = d4f_dz2_dxt2;
  const double d4f_dz3_dxs1 = 0;
  out[87] = d4f_dz3_dxs1;
  const double d4f_dz3_dxs0 = 0;
  out[88] = d4f_dz3_dxs0;
  const double d4f_dz3_dxt = _hc0[1]*_hc1[23] + _hc0[1]*_t39 + _hc0[12]*_hc1[5] + _hc0[12]*_t14 + _hc0[2]*_t40 + _hc0[2]*_t42 + _hc0[2]*_t44 + _hc0[23]*_hc1[1] + _hc0[5]*_hc1[12] + _hc0[5]*_t13 + _hc0[5]*_t16 + _hc0[6]*_t10 + _hc0[6]*_t37;
  out[89] = d4f_dz3_dxt;
  const double d4f_dz4 = _hc0[13]*_hc1[5] + _hc0[13]*_t46 + _hc0[2]*_hc1[23] + _hc0[2]*_t45 + _hc0[2]*_t49 + _hc0[2]*_t53 + _hc0[24]*_hc1[1] + _hc0[6]*_hc1[12] + _hc0[6]*_t50 + _hc1[24] + _t13*_t47;
  out[90] = d4f_dz4;
  const double d4f_drs_dxs13 = 0;
  out[91] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[92] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[93] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[94] = d4f_drs_dxs03;
  const double d4f_drs_dxt_dxs12 = 0;
  out[95] = d4f_drs_dxt_dxs12;
  const double d4f_drs_dxt_dxs0_dxs1 = 0;
  out[96] = d4f_drs_dxt_dxs0_dxs1;
  const double d4f_drs_dxt_dxs02 = 0;
  out[97] = d4f_drs_dxt_dxs02;
  const double d4f_drs_dxt2_dxs1 = 0;
  out[98] = d4f_drs_dxt2_dxs1;
  const double d4f_drs_dxt2_dxs0 = 0;
  out[99] = d4f_drs_dxt2_dxs0;
  const double d4f_drs_dxt3 = _hc1[25]*_t6 + _t32*_t55 + _t54*_t6;
  out[100] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxs12 = 0;
  out[101] = d4f_drs_dz_dxs12;
  const double d4f_drs_dz_dxs0_dxs1 = 0;
  out[102] = d4f_drs_dz_dxs0_dxs1;
  const double d4f_drs_dz_dxs02 = 0;
  out[103] = d4f_drs_dz_dxs02;
  const double d4f_drs_dz_dxt_dxs1 = 0;
  out[104] = d4f_drs_dz_dxt_dxs1;
  const double d4f_drs_dz_dxt_dxs0 = 0;
  out[105] = d4f_drs_dz_dxt_dxs0;
  const double d4f_drs_dz_dxt2 = _hc0[3]*_t38 + _hc0[7]*_t37 + _hc1[26]*_t1 + _t1*_t57 + _t1*_t58 + _t22*_t34 + _t56*_t8;
  out[106] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxs1 = 0;
  out[107] = d4f_drs_dz2_dxs1;
  const double d4f_drs_dz2_dxs0 = 0;
  out[108] = d4f_drs_dz2_dxs0;
  const double d4f_drs_dz2_dxt = _hc0[1]*_hc1[27] + _hc0[1]*_t59 + _hc0[12]*_hc1[7] + _hc0[15]*_t14 + _hc0[2]*_t60 + _hc0[2]*_t61 + _hc0[27]*_hc1[1] + _hc0[3]*_t44 + _hc0[5]*_hc1[15] + _hc0[5]*_t21 + _hc0[6]*_t22 + _hc0[7]*_t16 + _hc0[8]*_t37;
  out[109] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = _hc0[13]*_hc1[7] + _hc0[16]*_t46 + _hc0[2]*_hc1[27] + _hc0[2]*_t62 + _hc0[2]*_t64 + _hc0[28]*_hc1[1] + _hc0[3]*_t53 + _hc0[6]*_hc1[15] + _hc0[8]*_t50 + _hc1[28] + _t21*_t47;
  out[110] = d4f_drs_dz3;
  const double d4f_drs2_dxs12 = 0;
  out[111] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[112] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[113] = d4f_drs2_dxs02;
  const double d4f_drs2_dxt_dxs1 = 0;
  out[114] = d4f_drs2_dxt_dxs1;
  const double d4f_drs2_dxt_dxs0 = 0;
  out[115] = d4f_drs2_dxt_dxs0;
  const double d4f_drs2_dxt2 = _hc0[3]*_t66 + _hc0[3]*(_t1*_t54 + _t55*_t8 + _t66) + 0.2e1*_hc0[7]*_t22 + _hc0[7]*_t68 + _hc1[29]*_t1 + _t1*_t67 + _t65*_t8;
  out[116] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxs1 = 0;
  out[117] = d4f_drs2_dz_dxs1;
  const double d4f_drs2_dz_dxs0 = 0;
  out[118] = d4f_drs2_dz_dxs0;
  const double d4f_drs2_dz_dxt = _hc0[1]*_hc1[30] + _hc0[1]*_t69 + _hc0[1]*_t70 + _hc0[15]*_hc1[7] + _hc0[15]*_t5 + _hc0[17]*_t3 + _hc0[3]*_t61 + _hc0[3]*(_hc0[1]*_t58 + _hc0[3]*_t43 + _hc0[7]*_t15 + _t56 + _t61) + _hc0[30]*_hc1[1] + _hc0[5]*_hc1[17] + _hc0[7]*_t21 + _hc0[7]*_t25 + _hc0[8]*_t22 + _hc0[8]*_t24 + _hc0[9]*_t12;
  out[119] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = _hc0[16]*_hc1[7] + _hc0[16]*_t5 + _hc0[18]*_t14 + _hc0[2]*_hc1[30] + _hc0[2]*_t71 + _hc0[3]*_t64 + _hc0[3]*(_hc0[3]*_t52 + _t15*_t72 + _t59 + _t64) + _hc0[31]*_hc1[1] + _hc0[6]*_hc1[17] + _hc0[9]*_t16 + _hc1[31] + _t21*_t72 + _t25*_t72;
  out[120] = d4f_drs2_dz2;
  const double d4f_drs3_dxs1 = 0;
  out[121] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[122] = d4f_drs3_dxs0;
  const double d4f_drs3_dxt = _hc0[1]*_hc1[32] + _hc0[1]*_t73 + _hc0[17]*_hc1[7] + _hc0[17]*_t27 + _hc0[3]*_t74 + _hc0[3]*_t76 + _hc0[3]*(_hc0[1]*_t67 + _hc0[3]*(_hc0[1]*_t54 + _t55 + _t75) + _hc0[7]*_t28 + _t65 + _t76) + _hc0[32]*_hc1[1] + _hc0[7]*_hc1[17] + _hc0[7]*_t26 + _hc0[7]*_t29 + _hc0[9]*_t22 + _hc0[9]*_t68;
  out[123] = d4f_drs3_dxt;
  const double d4f_drs3_dz = _hc0[18]*_hc1[7] + _hc0[18]*_t27 + _hc0[19]*_t3 + _hc0[2]*_hc1[32] + _hc0[3]*_t71 + _hc0[3]*_t77 + _hc0[3]*(_hc0[3]*(_hc0[3]*_t51 + _t58 + _t63) + _hc0[8]*_t28 + _hc0[9]*_t15 + _t69 + _t77) + _hc0[33]*_hc1[1] + _hc0[8]*_hc1[17] + _hc0[8]*_t26 + _hc0[8]*_t29 + _hc0[9]*_t21 + _hc1[33] + _t25*_t78;
  out[124] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[19]*_hc1[7] + 0.3e1*_hc0[19]*_t5 + _hc0[3]*_hc1[32] + _hc0[3]*_t79 + _hc0[3]*_t81 + _hc0[3]*(_hc0[3]*(_hc0[3]*(_hc1[25] + _t54) + _t67 + _t80) + _t28*_t78 + _t73 + _t81) + _hc0[34]*_hc1[1] + _hc0[9]*_hc1[17] + 0.3e1*_hc0[9]*_t29 + _hc1[34] + _t26*_t78;
  out[125] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_pbe_grad_k, _KMAX)(p, rs, z, xt, 0, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc1);

  const double f = _hc0[0] + _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0;
  out[1] = df_dxs1;
  const double df_dxs0 = 0;
  out[2] = df_dxs0;
  const double df_dxt = _hc0[3];
  out[3] = df_dxt;
  const double df_dz = _hc0[4] + _hc1[1];
  out[4] = df_dz;
  const double df_drs = _hc0[5] + _hc1[2];
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[6] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[7] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[8] = d2f_dxs02;
  const double d2f_dxt_dxs1 = 0;
  out[9] = d2f_dxt_dxs1;
  const double d2f_dxt_dxs0 = 0;
  out[10] = d2f_dxt_dxs0;
  const double d2f_dxt2 = _hc0[11];
  out[11] = d2f_dxt2;
  const double d2f_dz_dxs1 = 0;
  out[12] = d2f_dz_dxs1;
  const double d2f_dz_dxs0 = 0;
  out[13] = d2f_dz_dxs0;
  const double d2f_dz_dxt = _hc0[14];
  out[14] = d2f_dz_dxt;
  const double d2f_dz2 = _hc0[15] + _hc1[3];
  out[15] = d2f_dz2;
  const double d2f_drs_dxs1 = 0;
  out[16] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[17] = d2f_drs_dxs0;
  const double d2f_drs_dxt = _hc0[18];
  out[18] = d2f_drs_dxt;
  const double d2f_drs_dz = _hc0[19] + _hc1[4];
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[20] + _hc1[5];
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[21] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[22] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[23] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[24] = d3f_dxs03;
  const double d3f_dxt_dxs12 = 0;
  out[25] = d3f_dxt_dxs12;
  const double d3f_dxt_dxs0_dxs1 = 0;
  out[26] = d3f_dxt_dxs0_dxs1;
  const double d3f_dxt_dxs02 = 0;
  out[27] = d3f_dxt_dxs02;
  const double d3f_dxt2_dxs1 = 0;
  out[28] = d3f_dxt2_dxs1;
  const double d3f_dxt2_dxs0 = 0;
  out[29] = d3f_dxt2_dxs0;
  const double d3f_dxt3 = _hc0[30];
  out[30] = d3f_dxt3;
  const double d3f_dz_dxs12 = 0;
  out[31] = d3f_dz_dxs12;
  const double d3f_dz_dxs0_dxs1 = 0;
  out[32] = d3f_dz_dxs0_dxs1;
  const double d3f_dz_dxs02 = 0;
  out[33] = d3f_dz_dxs02;
  const double d3f_dz_dxt_dxs1 = 0;
  out[34] = d3f_dz_dxt_dxs1;
  const double d3f_dz_dxt_dxs0 = 0;
  out[35] = d3f_dz_dxt_dxs0;
  const double d3f_dz_dxt2 = _hc0[36];
  out[36] = d3f_dz_dxt2;
  const double d3f_dz2_dxs1 = 0;
  out[37] = d3f_dz2_dxs1;
  const double d3f_dz2_dxs0 = 0;
  out[38] = d3f_dz2_dxs0;
  const double d3f_dz2_dxt = _hc0[39];
  out[39] = d3f_dz2_dxt;
  const double d3f_dz3 = _hc0[40] + _hc1[6];
  out[40] = d3f_dz3;
  const double d3f_drs_dxs12 = 0;
  out[41] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[42] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[43] = d3f_drs_dxs02;
  const double d3f_drs_dxt_dxs1 = 0;
  out[44] = d3f_drs_dxt_dxs1;
  const double d3f_drs_dxt_dxs0 = 0;
  out[45] = d3f_drs_dxt_dxs0;
  const double d3f_drs_dxt2 = _hc0[46];
  out[46] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxs1 = 0;
  out[47] = d3f_drs_dz_dxs1;
  const double d3f_drs_dz_dxs0 = 0;
  out[48] = d3f_drs_dz_dxs0;
  const double d3f_drs_dz_dxt = _hc0[49];
  out[49] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = _hc0[50] + _hc1[7];
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dxs1 = 0;
  out[51] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[52] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = _hc0[53];
  out[53] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _hc0[54] + _hc1[8];
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[55] + _hc1[9];
  out[55] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[56] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[57] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[58] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[59] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[60] = d4f_dxs04;
  const double d4f_dxt_dxs13 = 0;
  out[61] = d4f_dxt_dxs13;
  const double d4f_dxt_dxs0_dxs12 = 0;
  out[62] = d4f_dxt_dxs0_dxs12;
  const double d4f_dxt_dxs02_dxs1 = 0;
  out[63] = d4f_dxt_dxs02_dxs1;
  const double d4f_dxt_dxs03 = 0;
  out[64] = d4f_dxt_dxs03;
  const double d4f_dxt2_dxs12 = 0;
  out[65] = d4f_dxt2_dxs12;
  const double d4f_dxt2_dxs0_dxs1 = 0;
  out[66] = d4f_dxt2_dxs0_dxs1;
  const double d4f_dxt2_dxs02 = 0;
  out[67] = d4f_dxt2_dxs02;
  const double d4f_dxt3_dxs1 = 0;
  out[68] = d4f_dxt3_dxs1;
  const double d4f_dxt3_dxs0 = 0;
  out[69] = d4f_dxt3_dxs0;
  const double d4f_dxt4 = _hc0[70];
  out[70] = d4f_dxt4;
  const double d4f_dz_dxs13 = 0;
  out[71] = d4f_dz_dxs13;
  const double d4f_dz_dxs0_dxs12 = 0;
  out[72] = d4f_dz_dxs0_dxs12;
  const double d4f_dz_dxs02_dxs1 = 0;
  out[73] = d4f_dz_dxs02_dxs1;
  const double d4f_dz_dxs03 = 0;
  out[74] = d4f_dz_dxs03;
  const double d4f_dz_dxt_dxs12 = 0;
  out[75] = d4f_dz_dxt_dxs12;
  const double d4f_dz_dxt_dxs0_dxs1 = 0;
  out[76] = d4f_dz_dxt_dxs0_dxs1;
  const double d4f_dz_dxt_dxs02 = 0;
  out[77] = d4f_dz_dxt_dxs02;
  const double d4f_dz_dxt2_dxs1 = 0;
  out[78] = d4f_dz_dxt2_dxs1;
  const double d4f_dz_dxt2_dxs0 = 0;
  out[79] = d4f_dz_dxt2_dxs0;
  const double d4f_dz_dxt3 = _hc0[80];
  out[80] = d4f_dz_dxt3;
  const double d4f_dz2_dxs12 = 0;
  out[81] = d4f_dz2_dxs12;
  const double d4f_dz2_dxs0_dxs1 = 0;
  out[82] = d4f_dz2_dxs0_dxs1;
  const double d4f_dz2_dxs02 = 0;
  out[83] = d4f_dz2_dxs02;
  const double d4f_dz2_dxt_dxs1 = 0;
  out[84] = d4f_dz2_dxt_dxs1;
  const double d4f_dz2_dxt_dxs0 = 0;
  out[85] = d4f_dz2_dxt_dxs0;
  const double d4f_dz2_dxt2 = _hc0[86];
  out[86] = d4f_dz2_dxt2;
  const double d4f_dz3_dxs1 = 0;
  out[87] = d4f_dz3_dxs1;
  const double d4f_dz3_dxs0 = 0;
  out[88] = d4f_dz3_dxs0;
  const double d4f_dz3_dxt = _hc0[89];
  out[89] = d4f_dz3_dxt;
  const double d4f_dz4 = _hc0[90] + _hc1[10];
  out[90] = d4f_dz4;
  const double d4f_drs_dxs13 = 0;
  out[91] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[92] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[93] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[94] = d4f_drs_dxs03;
  const double d4f_drs_dxt_dxs12 = 0;
  out[95] = d4f_drs_dxt_dxs12;
  const double d4f_drs_dxt_dxs0_dxs1 = 0;
  out[96] = d4f_drs_dxt_dxs0_dxs1;
  const double d4f_drs_dxt_dxs02 = 0;
  out[97] = d4f_drs_dxt_dxs02;
  const double d4f_drs_dxt2_dxs1 = 0;
  out[98] = d4f_drs_dxt2_dxs1;
  const double d4f_drs_dxt2_dxs0 = 0;
  out[99] = d4f_drs_dxt2_dxs0;
  const double d4f_drs_dxt3 = _hc0[100];
  out[100] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxs12 = 0;
  out[101] = d4f_drs_dz_dxs12;
  const double d4f_drs_dz_dxs0_dxs1 = 0;
  out[102] = d4f_drs_dz_dxs0_dxs1;
  const double d4f_drs_dz_dxs02 = 0;
  out[103] = d4f_drs_dz_dxs02;
  const double d4f_drs_dz_dxt_dxs1 = 0;
  out[104] = d4f_drs_dz_dxt_dxs1;
  const double d4f_drs_dz_dxt_dxs0 = 0;
  out[105] = d4f_drs_dz_dxt_dxs0;
  const double d4f_drs_dz_dxt2 = _hc0[106];
  out[106] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxs1 = 0;
  out[107] = d4f_drs_dz2_dxs1;
  const double d4f_drs_dz2_dxs0 = 0;
  out[108] = d4f_drs_dz2_dxs0;
  const double d4f_drs_dz2_dxt = _hc0[109];
  out[109] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = _hc0[110] + _hc1[11];
  out[110] = d4f_drs_dz3;
  const double d4f_drs2_dxs12 = 0;
  out[111] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[112] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[113] = d4f_drs2_dxs02;
  const double d4f_drs2_dxt_dxs1 = 0;
  out[114] = d4f_drs2_dxt_dxs1;
  const double d4f_drs2_dxt_dxs0 = 0;
  out[115] = d4f_drs2_dxt_dxs0;
  const double d4f_drs2_dxt2 = _hc0[116];
  out[116] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxs1 = 0;
  out[117] = d4f_drs2_dz_dxs1;
  const double d4f_drs2_dz_dxs0 = 0;
  out[118] = d4f_drs2_dz_dxs0;
  const double d4f_drs2_dz_dxt = _hc0[119];
  out[119] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = _hc0[120] + _hc1[12];
  out[120] = d4f_drs2_dz2;
  const double d4f_drs3_dxs1 = 0;
  out[121] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[122] = d4f_drs3_dxs0;
  const double d4f_drs3_dxt = _hc0[123];
  out[123] = d4f_drs3_dxt;
  const double d4f_drs3_dz = _hc0[124] + _hc1[13];
  out[124] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[125] + _hc1[14];
  out[125] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(zvpbeloc_kv_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (0.1e1 / (rs * rs * rs));
  const double _t2 = xc_powr(0.2e1, 2, 3)*xc_powr(0.3e1, 1, 6)*pow(_t1, 0.1e1 / 0.9e1)/M_CBRTPI;

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.1e1 / 0.3e1*_t2/rs;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (0.4e1 / 0.9e1)*_t2/(rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.28e2 / 0.27e2*_t1*_t2;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = (0.280e3 / 0.81e2)*_t2/(rs * rs * rs * rs);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(zvpbeint_nu_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(zvpbeloc_kv_k, _KMAX)(p, rs, _hc0);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = (0.1e1 / (rs * rs * rs));
  const double _t5 = xc_powr(_t4, 1, 3);
  const double _t6 = _t2*_t3*_t5;
  const double _t7 = (0.1e1 / 0.4e1)*_t6;
  const double _t8 = _t1*_t7;
  const double _t9 = _t8*xt;
#if _KMAX >= 1
  const double _t10 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t11 = _t10*_t7;
  const double _t12 = _hc0[1]*_t11;
  const double _t13 = (0.1e1 / rs);
#endif
#if _KMAX >= 2
  const double _t14 = _hc0[2]*_t11;
  const double _t15 = (0.1e1 / 0.2e1)*_t6;
  const double _t16 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t17 = ((_hc0[1]) * (_hc0[1]));
  const double _t18 = _t16*_t17;
  const double _t19 = _t15*_t18;
  const double _t20 = (0.1e1 / (rs * rs));
  const double _t21 = _t1*_t15*_t20;
  const double _t22 = _hc0[1]*_t10;
  const double _t23 = _t13*_t15*_t22;
#endif
#if _KMAX >= 3
  const double _t24 = _hc0[3]*_t11;
  const double _t25 = (0.3e1 / 0.2e1)*_t6;
  const double _t26 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t27 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t26;
  const double _t28 = _t25*_t27;
  const double _t29 = _t1*_t25*_t4;
  const double _t30 = _t20*_t22*_t25;
  const double _t31 = _t13*_t18*_t25;
#endif
#if _KMAX >= 4
  const double _t32 = _t6*xt;
  const double _t33 = _hc0[3]*_t32;
  const double _t34 = 0.6e1*_t32;
  const double _t35 = _hc0[2]*_t6*xt;
  const double _t36 = _t13*_t34;
#endif

  const double f = _t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t8;
  out[1] = df_dxt;
  const double df_dz = 0;
  out[2] = df_dz;
  const double df_drs = -_t12*xt - _t13*_t9;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = 0;
  out[4] = d2f_dxt2;
  const double d2f_dz_dxt = 0;
  out[5] = d2f_dz_dxt;
  const double d2f_dz2 = 0;
  out[6] = d2f_dz2;
  const double d2f_drs_dxt = -_t12 - _t13*_t8;
  out[7] = d2f_drs_dxt;
  const double d2f_drs_dz = 0;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = -_t14*xt + _t19*xt + _t21*xt + _t23*xt;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0;
  out[10] = d3f_dxt3;
  const double d3f_dz_dxt2 = 0;
  out[11] = d3f_dz_dxt2;
  const double d3f_dz2_dxt = 0;
  out[12] = d3f_dz2_dxt;
  const double d3f_dz3 = 0;
  out[13] = d3f_dz3;
  const double d3f_drs_dxt2 = 0;
  out[14] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxt = 0;
  out[15] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = 0;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dxt = -_t14 + _t19 + _t21 + _t23;
  out[17] = d3f_drs2_dxt;
  const double d3f_drs2_dz = 0;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = (0.3e1 / 0.2e1)*_hc0[1]*_hc0[2]*_t16*_t2*_t3*_t5*xt + (0.3e1 / 0.4e1)*_hc0[2]*_t10*_t13*_t2*_t3*_t5*xt - _t24*xt - _t28*xt - _t29*xt - _t30*xt - _t31*xt;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = 0;
  out[20] = d4f_dxt4;
  const double d4f_dz_dxt3 = 0;
  out[21] = d4f_dz_dxt3;
  const double d4f_dz2_dxt2 = 0;
  out[22] = d4f_dz2_dxt2;
  const double d4f_dz3_dxt = 0;
  out[23] = d4f_dz3_dxt;
  const double d4f_dz4 = 0;
  out[24] = d4f_dz4;
  const double d4f_drs_dxt3 = 0;
  out[25] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxt2 = 0;
  out[26] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxt = 0;
  out[27] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = 0;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dxt2 = 0;
  out[29] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxt = 0;
  out[30] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = 0;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dxt = (0.3e1 / 0.2e1)*_hc0[1]*_hc0[2]*_t16*_t2*_t3*_t5 + (0.3e1 / 0.4e1)*_hc0[2]*_t10*_t13*_t2*_t3*_t5 - _t24 - _t28 - _t29 - _t30 - _t31;
  out[32] = d4f_drs3_dxt;
  const double d4f_drs3_dz = 0;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = -_hc0[1]*_hc0[2]*_t16*_t36 + 0.2e1*_hc0[1]*_t16*_t33 + ((_hc0[2]) * (_hc0[2]))*_t16*_t25*xt - _hc0[4]*_t11*xt + _t1*_t34/(rs * rs * rs * rs) + _t10*_t13*_t33 - 0.3e1*_t10*_t20*_t35 - 0.9e1*_t17*_t26*_t35 + _t18*_t20*_t34 + _t22*_t34*_t4 + _t27*_t36 + ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t34/xc_powi((_hc0[0]), 5);
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(zvpbeint_ff_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(zvpbeint_nu_k, _KMAX)(p, rs, 0, t, _hc0);
  const double _t1 = (z * z);
  const double _t2 = _t1 > 9.9999999999999995e-21;
  const double _t3 = my_piecewise3(_t2, _t1, 9.9999999999999995e-21);
  const double _t4 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t5 = 0.5*_t4;
  const double _t6 = exp(-_t3*_t5);
#if _KMAX >= 1
  const double _t7 = _hc0[1]*_t3;
  const double _t8 = ((_hc0[0]) * (_hc0[0]));
  const double _t9 = 1.5*_t6;
  const double _t10 = _t8*_t9;
  const double _t11 = my_piecewise3(_t2, 0.2e1*z, 0);
  const double _t12 = _t5*_t6;
  const double _t13 = _t10*_t3;
#endif
#if _KMAX >= 2
  const double _t14 = ((_hc0[1]) * (_hc0[1]));
  const double _t15 = 3.0*_t6;
  const double _t16 = _t15*_t3;
  const double _t17 = _hc0[0]*_t16;
  const double _t18 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t19 = _t14*_t18;
  const double _t20 = (_t3 * _t3);
  const double _t21 = _t20*_t6;
  const double _t22 = 2.25*_t21;
  const double _t23 = _t10*_t11;
  const double _t24 = _t6*_t7;
  const double _t25 = xc_powi((_hc0[0]), 5);
  const double _t26 = 0.75*_t11*_t25;
  const double _t27 = my_piecewise3(_t2, 0.2e1, 0);
  const double _t28 = (_t11 * _t11);
  const double _t29 = xc_powi((_hc0[0]), 6);
  const double _t30 = _t29*_t6;
  const double _t31 = _hc0[1]*_hc0[3];
  const double _t32 = _t3*_t6;
  const double _t33 = ((_hc0[3]) * (_hc0[3]));
#endif
#if _KMAX >= 3
  const double _t34 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t35 = (_t3 * _t3 * _t3);
  const double _t36 = _t34*_t35;
  const double _t37 = 3.375*_t30;
  const double _t38 = _t11*_t15;
  const double _t39 = _hc0[0]*_t38;
  const double _t40 = _t14*_t21;
  const double _t41 = xc_powi((_hc0[0]), 7);
  const double _t42 = _t11*_t41;
  const double _t43 = 1.125*_t42;
  const double _t44 = _t10*_t27;
  const double _t45 = _t28*_t6;
  const double _t46 = _t45*_t7;
  const double _t47 = xc_powi((_hc0[0]), 8);
  const double _t48 = 0.375*_t47;
  const double _t49 = xc_powi((_hc0[0]), 9);
  const double _t50 = (_t11 * _t11 * _t11)*_t6;
  const double _t51 = _hc0[7]*_t24;
  const double _t52 = 6.0*_hc0[0];
  const double _t53 = _hc0[3]*_t14;
  const double _t54 = _t35*_t37;
  const double _t55 = _t21*_t42;
  const double _t56 = 1.125*_hc0[1];
  const double _t57 = _hc0[3]*_t56;
  const double _t58 = _t3*_t45;
  const double _t59 = _t48*_t58;
  const double _t60 = _hc0[1]*_hc0[9];
  const double _t61 = 6.0*_t32;
  const double _t62 = _hc0[0]*_t61;
  const double _t63 = _hc0[3]*_hc0[7];
  const double _t64 = _hc0[1]*_t33;
  const double _t65 = _t21*_t33;
  const double _t66 = ((_hc0[3]) * (_hc0[3]) * (_hc0[3]));
  const double _t67 = 9.0*_t32;
  const double _t68 = _hc0[0]*_t67;
  const double _t69 = _hc0[3]*_hc0[9];
#endif
#if _KMAX >= 4
  const double _t70 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t71 = 45.0*_t21*_t8;
  const double _t72 = _t6*_t70;
  const double _t73 = 40.5*_t25;
  const double _t74 = _t35*_t73;
  const double _t75 = (_t3 * _t3 * _t3 * _t3);
  const double _t76 = 5.0625*_t47*_t75;
  const double _t77 = 16.875*_t11*_t20*_t30;
  const double _t78 = _t36*_t6;
  const double _t79 = _t14*_t27;
  const double _t80 = _hc0[0]*_t15;
  const double _t81 = 7.5*_t45;
  const double _t82 = _t27*_t61;
  const double _t83 = 1.125*_t41;
  const double _t84 = 5.25*_t41;
  const double _t85 = _t58*_t84;
  const double _t86 = 0.5625*xc_powi((_hc0[0]), 10)*_t28;
  const double _t87 = _t47*_t50;
  const double _t88 = _hc0[1]*_t25*_t6;
  const double _t89 = _t11*_t27;
  const double _t90 = 4.5*_t89;
  const double _t91 = 0.1875*xc_powi((_hc0[0]), 11)*_t50;
  const double _t92 = _t47*_t89;
  const double _t93 = 0.75*_t27;
  const double _t94 = _hc0[7]*_t14;
  const double _t95 = _hc0[3]*_t34;
  const double _t96 = _t30*_t35;
  const double _t97 = 10.125*_t96;
  const double _t98 = _hc0[1]*_hc0[7];
  const double _t99 = _t11*_t6;
  const double _t100 = _t52*_t99;
  const double _t101 = _t22*_t42;
  const double _t102 = _t27*_t80;
  const double _t103 = _t25*_t28*_t9;
  const double _t104 = _t25*_t93;
  const double _t105 = 1.125*_hc0[3];
  const double _t106 = 12.0*_hc0[3];
  const double _t107 = ((_hc0[7]) * (_hc0[7]));
  const double _t108 = _hc0[9]*_t14;
  const double _t109 = _t18*_t33;
  const double _t110 = _hc0[9]*_t32;
  const double _t111 = 9.0*_t69;
  const double _t112 = _hc0[7]*_t33;
  const double _t113 = ((_hc0[9]) * (_hc0[9]));
  const double _t114 = ((_hc0[3]) * (_hc0[3]) * (_hc0[3]) * (_hc0[3]));
#endif

  const double f = _t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_t10*_t7;
  out[1] = df_dt;
  const double df_dz = -_t11*_t12;
  out[2] = df_dz;
  const double df_drs = -_hc0[3]*_t13;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_t14*_t17 + _t19*_t22;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = -_hc0[1]*_t23 + _t24*_t26;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = -_t12*_t27 + 0.25*_t28*_t30;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = 2.25*_hc0[1]*_hc0[3]*_t18*_t20*_t6 - _hc0[7]*_t13 - _t17*_t31;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = -_hc0[3]*_t23 + _hc0[3]*_t26*_t32;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = -_hc0[9]*_t13 - _t17*_t33 + 2.25*_t18*_t20*_t33*_t6;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = -_t16*_t34 + 13.5*_t20*_t34*_t4*_t6 - _t36*_t37;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = 6.0*_t11*_t14*_t18*_t3*_t6 - _t14*_t39 - _t40*_t43;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = 0.75*_hc0[1]*_t25*_t27*_t3*_t6 + 1.5*_hc0[1]*_t25*_t28*_t6 - _hc0[1]*_t44 - _t46*_t48;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = 0.75*_t11*_t27*_t29*_t6 - 0.125*_t49*_t50;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = 4.5*_hc0[1]*_hc0[7]*_t18*_t20*_t6 + 13.5*_hc0[3]*_t14*_t20*_t4*_t6 - _t16*_t53 - _t51*_t52 - _t53*_t54;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = 6.0*_hc0[1]*_hc0[3]*_t11*_t18*_t3*_t6 + 0.75*_hc0[7]*_t11*_t25*_t3*_t6 - _hc0[7]*_t23 - _t31*_t39 - _t55*_t57;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = 0.75*_hc0[3]*_t25*_t27*_t3*_t6 + 1.5*_hc0[3]*_t25*_t28*_t6 - _hc0[3]*_t44 - _hc0[3]*_t59;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = 2.25*_hc0[1]*_hc0[9]*_t18*_t20*_t6 + 13.5*_hc0[1]*_t20*_t33*_t4*_t6 - _hc0[17]*_t13 + 4.5*_hc0[3]*_hc0[7]*_t18*_t20*_t6 - _t16*_t64 - _t17*_t60 - _t54*_t64 - _t62*_t63;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = 0.75*_hc0[9]*_t11*_t25*_t3*_t6 - _hc0[9]*_t23 + 6.0*_t11*_t18*_t3*_t33*_t6 - _t33*_t39 - _t43*_t65;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = -_hc0[19]*_t13 + 6.75*_hc0[3]*_hc0[9]*_t18*_t20*_t6 - _t16*_t66 + 13.5*_t20*_t4*_t6*_t66 - _t54*_t66 - _t68*_t69;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t70*_t71 - _t72*_t74 + _t72*_t76;
  out[20] = d4f_dt4;
  const double d4f_dz_dt3 = 28.5*_t11*_t32*_t34*_t4 + 1.6875*_t11*_t49*_t78 - _t34*_t38 - _t34*_t77;
  out[21] = d4f_dz_dt3;
  const double d4f_dz2_dt2 = -_t14*_t85 + _t19*_t81 + _t19*_t82 - _t21*_t79*_t83 + _t40*_t86 - _t79*_t80;
  out[22] = d4f_dz2_dt2;
  const double d4f_dz3_dt = -1.125*_t24*_t92 - _t56*_t87 + _t7*_t91 + _t88*_t90;
  out[23] = d4f_dz3_dt;
  const double d4f_dz4 = 0.0625*xc_powi((_hc0[0]), 12)*(_t11 * _t11 * _t11 * _t11)*_t6 + 0.75*(_t27 * _t27)*_t30 - _t45*_t49*_t93;
  out[24] = d4f_dz4;
  const double d4f_drs_dt3 = -_hc0[3]*_t73*_t78 + 40.5*_t21*_t4*_t94 + _t6*_t76*_t95 - _t67*_t94 + _t71*_t95 - _t94*_t97;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dz_dt2 = 12.0*_hc0[1]*_hc0[7]*_t11*_t18*_t3*_t6 + 28.5*_hc0[3]*_t11*_t14*_t3*_t4*_t6 + 1.6875*_hc0[3]*_t11*_t14*_t35*_t49*_t6 - _t100*_t98 - _t101*_t98 - _t38*_t53 - _t53*_t77;
  out[26] = d4f_drs_dz_dt2;
  const double d4f_drs_dz2_dt = 6.0*_hc0[3]*_t18*_t24*_t27 - _hc0[3]*_t46*_t84 + _hc0[7]*_t103 + _hc0[7]*_t104*_t32 - _hc0[7]*_t44 - _hc0[7]*_t59 - _t102*_t31 + _t18*_t31*_t81 - _t21*_t27*_t41*_t57 + _t21*_t31*_t86;
  out[27] = d4f_drs_dz2_dt;
  const double d4f_drs_dz3 = _hc0[3]*_t25*_t6*_t90 + _hc0[3]*_t3*_t91 - _t105*_t32*_t92 - _t105*_t87;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = 4.5*_hc0[1]*_hc0[17]*_t18*_t20*_t6 + 54.0*_hc0[1]*_hc0[3]*_hc0[7]*_t20*_t4*_t6 - _hc0[17]*_t24*_t52 - 13.5*_hc0[7]*_t31*_t96 + 13.5*_hc0[9]*_t14*_t20*_t4*_t6 - _t106*_t51 + 4.5*_t107*_t18*_t20*_t6 - _t107*_t62 - _t108*_t16 - _t108*_t54 + 45.0*_t14*_t20*_t33*_t6*_t8 + 5.0625*_t14*_t33*_t47*_t6*_t75 - _t14*_t33*_t6*_t74;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dz_dt = 6.0*_hc0[1]*_hc0[9]*_t11*_t18*_t3*_t6 + 28.5*_hc0[1]*_t11*_t3*_t33*_t4*_t6 + 1.6875*_hc0[1]*_t11*_t33*_t35*_t49*_t6 + 0.75*_hc0[17]*_t11*_t25*_t3*_t6 - _hc0[17]*_t23 + 12.0*_hc0[3]*_hc0[7]*_t11*_t18*_t3*_t6 - _hc0[9]*_t55*_t56 - _t100*_t63 - _t101*_t63 - _t38*_t64 - _t39*_t60 - _t64*_t77;
  out[30] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz2 = _hc0[9]*_t103 - _hc0[9]*_t44 - _hc0[9]*_t59 - _t102*_t33 + _t104*_t110 + _t109*_t81 + _t109*_t82 - _t27*_t65*_t83 - _t33*_t85 + _t65*_t86;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dt = -_hc0[1]*_hc0[19]*_t17 + 2.25*_hc0[1]*_hc0[19]*_t18*_t20*_t6 + 40.5*_hc0[1]*_hc0[3]*_hc0[9]*_t20*_t4*_t6 + 45.0*_hc0[1]*_t20*_t6*_t66*_t8 + 5.0625*_hc0[1]*_t47*_t6*_t66*_t75 + 6.75*_hc0[17]*_hc0[3]*_t18*_t20*_t6 - _hc0[17]*_hc0[3]*_t68 - _hc0[32]*_t13 + 6.75*_hc0[7]*_hc0[9]*_t18*_t20*_t6 - _hc0[7]*_hc0[9]*_t68 + 40.5*_hc0[7]*_t20*_t33*_t4*_t6 - _hc0[9]*_t31*_t97 - _t111*_t24 - _t112*_t67 - _t112*_t97 - 40.5*_t35*_t66*_t88;
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dz = -_hc0[0]*_t111*_t99 + 0.75*_hc0[19]*_t11*_t25*_t3*_t6 - _hc0[19]*_t23 + 18.0*_hc0[3]*_hc0[9]*_t11*_t18*_t3*_t6 + 28.5*_t11*_t3*_t4*_t6*_t66 + 1.6875*_t11*_t35*_t49*_t6*_t66 - _t38*_t66 - 3.375*_t55*_t69 - _t66*_t77;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = -_hc0[0]*_hc0[19]*_t106*_t32 + 9.0*_hc0[19]*_hc0[3]*_t18*_t20*_t6 - _hc0[34]*_t13 + 81.0*_hc0[9]*_t20*_t33*_t4*_t6 - 20.25*_hc0[9]*_t33*_t96 - 18.0*_t110*_t33 + 6.75*_t113*_t18*_t20*_t6 - _t113*_t68 + 45.0*_t114*_t20*_t6*_t8 + 5.0625*_t114*_t47*_t6*_t75 - _t114*_t6*_t74;
  out[34] = d4f_drs4;
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
  XC_CAT(mbeta_k, _KMAX)(p, rs, t, _hc1);
  const double _t1 = 0.1e1 - M_LN2;
  const double _t2 = (M_PI * M_PI)/_t1;
  const double _t3 = xc_expm1(-_hc0[0]*_t2);
  const double _t4 = _t2/_t3;
#if _KMAX >= 1
  const double _t5 = _hc0[1]*_hc1[0];
  const double _t6 = _t3 + 0.1e1;
  const double _t7 = _t6/(_t3 * _t3);
  const double _t8 = (M_PI * M_PI * M_PI * M_PI)*_t7/(_t1 * _t1);
#endif
#if _KMAX >= 2
  const double _t9 = _hc0[1]*_t8;
  const double _t10 = _hc0[2]*_t8;
  const double _t11 = 0.2e1*_t9;
  const double _t12 = _hc1[0]*_t7;
  const double _t13 = ((_hc0[1]) * (_hc0[1]));
  const double _t14 = xc_powi(M_PI, 6)/(_t1 * _t1 * _t1);
  const double _t15 = _t13*_t14;
  const double _t16 = (_t6 * _t6)/(_t3 * _t3 * _t3);
  const double _t17 = _hc1[0]*_t16;
  const double _t18 = 0.2e1*_t15;
#endif
#if _KMAX >= 3
  const double _t19 = _t15*_t7;
  const double _t20 = _t16*_t18;
  const double _t21 = _hc0[3]*_t8;
  const double _t22 = 0.3e1*_t9;
  const double _t23 = 0.3e1*_hc1[2];
  const double _t24 = xc_powi(M_PI, 8)/(_t1 * _t1 * _t1 * _t1);
  const double _t25 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t24;
  const double _t26 = _hc0[2]*_t14;
  const double _t27 = _t26*_t5;
  const double _t28 = 0.3e1*_t7;
  const double _t29 = 0.6e1*_t16;
  const double _t30 = _t15*_t29;
  const double _t31 = 0.6e1*_t25;
  const double _t32 = (_t6 * _t6 * _t6)/(_t3 * _t3 * _t3 * _t3);
  const double _t33 = _hc1[0]*_t32;
#endif
#if _KMAX >= 4
  const double _t34 = 0.3e1*_hc1[4];
  const double _t35 = _hc1[1]*_t25;
  const double _t36 = _hc0[1]*_t26;
  const double _t37 = _hc1[1]*_t36;
  const double _t38 = 0.6e1*_hc1[5];
  const double _t39 = _hc1[2]*_t36;
  const double _t40 = 0.4e1*_t7;
  const double _t41 = _hc0[3]*_t14*_t5;
  const double _t42 = ((_hc0[2]) * (_hc0[2]))*_t14;
  const double _t43 = _hc1[2]*_t25;
  const double _t44 = xc_powi(M_PI, 10)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))/xc_powi(_t1, 5);
  const double _t45 = _hc0[2]*_t13*_t24;
  const double _t46 = 0.24e2*_t43;
  const double _t47 = 0.36e2*_t33;
#endif

  const double f = _hc1[0]*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t4;
  out[1] = df_dt;
  const double df_drs = _hc1[2]*_t4 + _t5*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[3]*_t4;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = _hc1[1]*_t9 + _hc1[4]*_t4;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _hc1[0]*_t10 + _hc1[2]*_t11 + _hc1[5]*_t4 - _t12*_t15 + _t17*_t18;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _hc1[3]*_t9 + _hc1[7]*_t4;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = _hc1[1]*_t10 - _hc1[1]*_t19 + _hc1[1]*_t20 + _hc1[4]*_t11 + _hc1[8]*_t4;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = _hc1[0]*_t21 + _hc1[2]*_t30 + _hc1[5]*_t22 + _hc1[9]*_t4 + _t10*_t23 + _t12*_t25 - _t17*_t31 - _t19*_t23 - _t27*_t28 + _t27*_t29 + _t31*_t33;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = 0;
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = _hc1[12]*_t4 + _hc1[3]*_t10 - _hc1[3]*_t19 + _hc1[3]*_t20 + _hc1[7]*_t11;
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = _hc1[1]*_t21 + _hc1[13]*_t4 + _hc1[4]*_t30 + _hc1[8]*_t22 + _t10*_t34 - _t19*_t34 - _t28*_t37 - _t29*_t35 + _t29*_t37 + 0.6e1*_t32*_t35 + _t35*_t7;
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = _hc0[4]*_hc1[0]*_t8 + 0.24e2*_hc1[0]*_t44*(_t6 * _t6 * _t6 * _t6)/xc_powi(_t3, 5) + _hc1[14]*_t4 + 0.4e1*_hc1[2]*_t21 + 0.12e2*_hc1[5]*_t15*_t16 + 0.4e1*_hc1[9]*_t9 + _t10*_t38 - 0.3e1*_t12*_t42 - _t12*_t44 + 0.6e1*_t12*_t45 + 0.24e2*_t16*_t39 + 0.8e1*_t16*_t41 - _t16*_t46 + 0.6e1*_t17*_t42 + 0.14e2*_t17*_t44 - 0.36e2*_t17*_t45 - _t19*_t38 + _t32*_t46 - 0.12e2*_t39*_t7 - _t40*_t41 + _t40*_t43 - _t44*_t47 + _t45*_t47;
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
  XC_CAT(mbeta_k, _KMAX)(p, rs, t, _hc2);
  const double _t1 = _hc0[0]*_hc1[0] + 0.1e1;
  const double _t2 = (M_PI * M_PI)/(0.1e1 - M_LN2);
  const double _t3 = _t2/_t1;
  const double _t4 = _hc1[0]*_t3;
#if _KMAX >= 1
  const double _t5 = _hc2[0]*_t3;
  const double _t6 = _t2/(_t1 * _t1);
  const double _t7 = _hc1[0]*_t6;
  const double _t8 = _hc0[0]*_hc1[1];
  const double _t9 = _hc0[1]*_hc1[0];
  const double _t10 = -_t8 - _t9;
  const double _t11 = _hc2[0]*_t10;
  const double _t12 = _hc0[0]*_hc1[2];
  const double _t13 = _hc0[2]*_hc1[0];
  const double _t14 = -_t12 - _t13;
  const double _t15 = _hc2[0]*_t7;
#endif
#if _KMAX >= 2
  const double _t16 = 0.2e1*_hc1[1];
  const double _t17 = _hc2[1]*_t3;
  const double _t18 = _hc2[1]*_t7;
  const double _t19 = 0.2e1*_t18;
  const double _t20 = _t11*_t6;
  const double _t21 = _hc0[0]*_hc1[3];
  const double _t22 = _hc0[3]*_hc1[0];
  const double _t23 = _hc0[1]*_hc1[1];
  const double _t24 = -_t21 - _t22 - 0.2e1*_t23;
  const double _t25 = _t2/(_t1 * _t1 * _t1);
  const double _t26 = _hc1[0]*_t25;
  const double _t27 = -0.2e1*_t8 - 0.2e1*_t9;
  const double _t28 = _t11*_t27;
  const double _t29 = _hc2[2]*_t3;
  const double _t30 = _hc1[2]*_t3;
  const double _t31 = _t14*_t7;
  const double _t32 = _hc2[2]*_t7;
  const double _t33 = _hc2[0]*_t6;
  const double _t34 = _hc1[1]*_t14;
  const double _t35 = _hc0[0]*_hc1[4];
  const double _t36 = _hc0[1]*_hc1[2];
  const double _t37 = _hc0[2]*_hc1[1];
  const double _t38 = _hc0[4]*_hc1[0];
  const double _t39 = -_t35 - _t36 - _t37 - _t38;
  const double _t40 = _t26*_t27;
  const double _t41 = _hc2[0]*_t14;
  const double _t42 = 0.2e1*_hc1[2];
  const double _t43 = 0.2e1*_t31;
  const double _t44 = _t14*_t33;
  const double _t45 = _hc0[0]*_hc1[5];
  const double _t46 = _hc0[5]*_hc1[0];
  const double _t47 = 0.2e1*_hc0[2];
  const double _t48 = -_hc1[2]*_t47 - _t45 - _t46;
  const double _t49 = -0.2e1*_t12 - 0.2e1*_t13;
  const double _t50 = _t26*_t41;
#endif
#if _KMAX >= 3
  const double _t51 = 0.3e1*_hc1[1];
  const double _t52 = _hc2[3]*_t3;
  const double _t53 = 0.3e1*_hc1[3];
  const double _t54 = _t10*_t7;
  const double _t55 = 0.3e1*_hc2[3];
  const double _t56 = 0.6e1*_t10;
  const double _t57 = _hc2[1]*_t6;
  const double _t58 = _hc1[1]*_t57;
  const double _t59 = 0.3e1*_t18;
  const double _t60 = _t24*_t33;
  const double _t61 = _hc0[0]*_hc1[6];
  const double _t62 = _hc0[6]*_hc1[0];
  const double _t63 = _hc0[1]*_hc1[3];
  const double _t64 = _hc0[3]*_hc1[1];
  const double _t65 = -_t61 - _t62 - 0.3e1*_t63 - 0.3e1*_t64;
  const double _t66 = _hc2[1]*_t10;
  const double _t67 = 0.3e1*_t40;
  const double _t68 = _t25*_t28;
  const double _t69 = -0.2e1*_t21 - 0.2e1*_t22 - 0.4e1*_t23;
  const double _t70 = _t11*_t26;
  const double _t71 = _hc2[0]*_t40;
  const double _t72 = 0.2e1*_t24;
  const double _t73 = -0.3e1*_t8 - 0.3e1*_t9;
  const double _t74 = _t2/(_t1 * _t1 * _t1 * _t1);
  const double _t75 = _hc1[0]*_t74;
  const double _t76 = _t73*_t75;
  const double _t77 = _hc2[4]*_t3;
  const double _t78 = 0.2e1*_hc1[4];
  const double _t79 = 0.2e1*_t54;
  const double _t80 = _t14*_t16;
  const double _t81 = _hc2[2]*_t10;
  const double _t82 = _t6*_t81;
  const double _t83 = _t42*_t57;
  const double _t84 = _hc1[2]*_t33;
  const double _t85 = _t33*_t39;
  const double _t86 = _hc1[2]*_t25;
  const double _t87 = _hc2[1]*_t14;
  const double _t88 = 0.2e1*_t40;
  const double _t89 = _t27*_t41;
  const double _t90 = _t25*_t89;
  const double _t91 = _hc0[0]*_hc1[7];
  const double _t92 = _hc0[2]*_hc1[3];
  const double _t93 = _hc0[3]*_hc1[2];
  const double _t94 = _hc0[7]*_hc1[0];
  const double _t95 = 0.2e1*_hc0[1];
  const double _t96 = 0.2e1*_hc0[4];
  const double _t97 = -_hc1[1]*_t96 - _hc1[4]*_t95 - _t91 - _t92 - _t93 - _t94;
  const double _t98 = _hc2[0]*_t39;
  const double _t99 = _hc2[5]*_t3;
  const double _t100 = _hc1[5]*_t3;
  const double _t101 = _hc2[5]*_t7;
  const double _t102 = _hc2[2]*_t6;
  const double _t103 = _t48*_t7;
  const double _t104 = _t33*_t48;
  const double _t105 = 0.2e1*_t32;
  const double _t106 = _t26*_t49;
  const double _t107 = _t106*_t14;
  const double _t108 = _t25*_t49;
  const double _t109 = _hc2[0]*_t34;
  const double _t110 = _hc2[2]*_t14;
  const double _t111 = _hc2[0]*_t48;
  const double _t112 = _hc0[0]*_hc1[8];
  const double _t113 = _hc0[1]*_hc1[5];
  const double _t114 = _hc0[5]*_hc1[1];
  const double _t115 = _hc0[8]*_hc1[0];
  const double _t116 = -_hc1[2]*_t96 - _hc1[4]*_t47 - _t112 - _t113 - _t114 - _t115;
  const double _t117 = -0.2e1*_t35 - 0.2e1*_t36 - 0.2e1*_t37 - 0.2e1*_t38;
  const double _t118 = _t41*_t49;
  const double _t119 = 0.3e1*_hc1[2];
  const double _t120 = 0.3e1*_t29;
  const double _t121 = 0.3e1*_t31;
  const double _t122 = 0.6e1*_hc1[2];
  const double _t123 = _t102*_t14;
  const double _t124 = 0.3e1*_hc1[5];
  const double _t125 = 0.3e1*_t32;
  const double _t126 = _hc0[0]*_hc1[9];
  const double _t127 = _hc0[9]*_hc1[0];
  const double _t128 = 0.3e1*_hc0[2];
  const double _t129 = 0.3e1*_hc0[5];
  const double _t130 = -_hc1[2]*_t129 - _hc1[5]*_t128 - _t126 - _t127;
  const double _t131 = _t108*_t41;
  const double _t132 = 0.4e1*_hc0[2];
  const double _t133 = -_hc1[2]*_t132 - 0.2e1*_t45 - 0.2e1*_t46;
  const double _t134 = 0.2e1*_t106;
  const double _t135 = -0.3e1*_t12 - 0.3e1*_t13;
  const double _t136 = _t118*_t75;
#endif
#if _KMAX >= 4
  const double _t137 = 0.6e1*_hc1[3];
  const double _t138 = 0.4e1*_hc1[6];
  const double _t139 = _hc2[3]*_t6;
  const double _t140 = 0.12e2*_t10;
  const double _t141 = _hc1[1]*_t140;
  const double _t142 = _t24*_t7;
  const double _t143 = 0.4e1*_hc1[1];
  const double _t144 = _t25*_t27;
  const double _t145 = _hc2[1]*_t144;
  const double _t146 = 0.4e1*_hc0[1];
  const double _t147 = _hc2[1]*_t40;
  const double _t148 = _t26*_t69;
  const double _t149 = 0.4e1*_t66;
  const double _t150 = _hc2[0]*_t24;
  const double _t151 = _t144*_t150;
  const double _t152 = _t11*_t69;
  const double _t153 = _t143*_t25;
  const double _t154 = -0.2e1*_t61 - 0.2e1*_t62 - 0.6e1*_t63 - 0.6e1*_t64;
  const double _t155 = 0.3e1*_t148;
  const double _t156 = _t27*_t76;
  const double _t157 = _t28*_t73;
  const double _t158 = _t157*_t74;
  const double _t159 = -0.3e1*_t21 - 0.3e1*_t22 - 0.6e1*_t23;
  const double _t160 = _t159*_t75;
  const double _t161 = 0.3e1*_t156;
  const double _t162 = 0.2e1*_t76;
  const double _t163 = _hc1[0]*_t2/xc_powi(_t1, 5);
  const double _t164 = _t163*(-0.4e1*_t8 - 0.4e1*_t9);
  const double _t165 = _hc2[7]*_t3;
  const double _t166 = 0.3e1*_hc1[4];
  const double _t167 = 0.3e1*_hc1[7];
  const double _t168 = _t139*_t14;
  const double _t169 = _hc2[4]*_t6;
  const double _t170 = _t10*_t119;
  const double _t171 = _t14*_t57;
  const double _t172 = 0.3e1*_hc2[4];
  const double _t173 = _t102*_t24;
  const double _t174 = _t119*_t57;
  const double _t175 = _t39*_t7;
  const double _t176 = 0.6e1*_t39;
  const double _t177 = _t14*_t40;
  const double _t178 = _t144*_t81;
  const double _t179 = _hc2[2]*_t40;
  const double _t180 = _t25*_t41;
  const double _t181 = _t180*_t69;
  const double _t182 = _t33*_t97;
  const double _t183 = _t144*_t98;
  const double _t184 = _t73*_t89;
  const double _t185 = _t184*_t74;
  const double _t186 = _t41*_t76;
  const double _t187 = 0.2e1*_t186;
  const double _t188 = 0.3e1*_hc0[4];
  const double _t189 = _hc2[0]*_t97;
  const double _t190 = _hc2[8]*_t3;
  const double _t191 = 0.4e1*_hc1[4];
  const double _t192 = 0.2e1*_hc1[7];
  const double _t193 = 0.2e1*_hc1[8];
  const double _t194 = _t14*_t169;
  const double _t195 = _hc2[5]*_t10;
  const double _t196 = 0.4e1*_hc1[2];
  const double _t197 = 0.4e1*_hc2[4];
  const double _t198 = _t102*_t39;
  const double _t199 = _hc2[1]*_t48;
  const double _t200 = 0.2e1*_t110;
  const double _t201 = _t111*_t16;
  const double _t202 = _t116*_t33;
  const double _t203 = _t117*_t26;
  const double _t204 = 0.2e1*_t203;
  const double _t205 = _t108*_t98;
  const double _t206 = _t117*_t180;
  const double _t207 = _t162*_t49;
  const double _t208 = _t118*_t73;
  const double _t209 = _t208*_t74;
  const double _t210 = 0.2e1*_t98;
  const double _t211 = _t49*_t76;
  const double _t212 = 0.4e1*_hc0[4];
  const double _t213 = _hc2[9]*_t3;
  const double _t214 = _hc2[5]*_t6;
  const double _t215 = _t14*_t51;
  const double _t216 = _t102*_t48;
  const double _t217 = _t130*_t33;
  const double _t218 = 0.3e1*_t39;
  const double _t219 = _t133*_t26;
  const double _t220 = _t133*_t25;
  const double _t221 = _hc2[2]*_t48;
  const double _t222 = 0.3e1*_t110;
  const double _t223 = _t135*_t75;
  const double _t224 = _t223*_t49;
  const double _t225 = _t135*_t74;
  const double _t226 = _t223*_t41;
  const double _t227 = _t118*_t135;
  const double _t228 = 0.6e1*_hc1[5];
  const double _t229 = 0.4e1*_hc1[9];
  const double _t230 = 0.12e2*_hc1[2];
  const double _t231 = 0.6e1*_hc2[5];
  const double _t232 = _t49*_t86;
  const double _t233 = 0.4e1*_t110;
  const double _t234 = 0.3e1*_t111;
#endif

  const double f = _hc2[0]*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t5 + _hc2[1]*_t4 + _t11*_t7;
  out[1] = df_dt;
  const double df_drs = _hc1[2]*_t5 + _hc2[2]*_t4 + _t14*_t15;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[3]*_t5 + _hc2[3]*_t4 + _t10*_t19 + _t15*_t24 + _t16*_t17 + _t16*_t20 + _t26*_t28;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = _hc1[1]*_t29 + _hc1[2]*_t20 + _hc1[4]*_t5 + _hc2[1]*_t30 + _hc2[1]*_t31 + _hc2[4]*_t4 + _t10*_t32 + _t15*_t39 + _t33*_t34 + _t40*_t41;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _hc1[5]*_t5 + _hc2[2]*_t43 + _hc2[5]*_t4 + _t15*_t48 + _t29*_t42 + _t42*_t44 + _t49*_t50;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc1[6]*_t5 + _t15*_t65 + _t17*_t53 + _t20*_t53 + _t24*_t59 + _t28*_t76 + _t51*_t52 + _t51*_t60 + _t51*_t68 + _t54*_t55 + _t56*_t58 + _t66*_t67 + _t69*_t70 + _t71*_t72;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _hc1[3]*_t29 + _hc1[3]*_t44 + _hc1[7]*_t5 + _hc2[3]*_t30 + _hc2[3]*_t31 + _hc2[4]*_t79 + _hc2[7]*_t4 + _t10*_t83 + _t15*_t97 + _t16*_t77 + _t16*_t82 + _t16*_t85 + _t16*_t90 + _t17*_t78 + _t19*_t39 + _t20*_t78 + _t24*_t32 + _t24*_t84 + _t28*_t86 + _t40*_t81 + _t50*_t69 + _t57*_t80 + _t76*_t89 + _t87*_t88 + _t88*_t98;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = _hc1[1]*_t104 + _hc1[1]*_t99 + _hc1[5]*_t20 + _hc1[8]*_t5 + _hc2[1]*_t100 + _hc2[1]*_t103 + _hc2[1]*_t107 + _hc2[4]*_t43 + _hc2[8]*_t4 + _t10*_t101 + _t102*_t80 + _t105*_t39 + _t106*_t98 + _t108*_t109 + _t110*_t88 + _t111*_t40 + _t116*_t15 + _t117*_t50 + _t118*_t76 + _t14*_t83 + _t29*_t78 + _t42*_t77 + _t42*_t82 + _t42*_t85 + _t42*_t90 + _t44*_t78;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = _hc1[5]*_t120 + _hc1[9]*_t5 + 0.3e1*_hc2[2]*_t107 + _hc2[5]*_t121 + _hc2[9]*_t4 + _t104*_t119 + _t111*_t134 + _t119*_t131 + _t119*_t99 + _t122*_t123 + _t124*_t44 + _t125*_t48 + _t130*_t15 + _t133*_t50 + _t135*_t136;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.8e1*_hc1[1]*_t151 + _hc1[10]*_t5 + _hc1[3]*_t140*_t57 + 0.6e1*_hc2[3]*_t142 + _hc2[3]*_t40*_t56 + _t137*_t52 + _t137*_t60 + _t137*_t68 + _t138*_t17 + _t138*_t20 + _t139*_t141 + _t141*_t145 + _t143*_t158 + _t143*_t33*_t65 + 0.8e1*_t147*_t24 + _t148*_t149 + _t149*_t156 + _t15*(-_hc0[0]*_hc1[10] - _hc0[10]*_hc1[0] - _hc0[3]*_t137 - _hc0[6]*_t143 - _hc1[6]*_t146) + _t150*_t155 + _t150*_t161 + _t152*_t153 + _t152*_t162 + _t154*_t70 + _t157*_t164 + _t160*_t28 + 0.4e1*_t18*_t65 + 0.12e2*_t24*_t58 + 0.3e1*_t65*_t71;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = _hc1[1]*_t169*_t56 + 0.6e1*_hc1[1]*_t183 + _hc1[11]*_t5 + _hc1[2]*_t158 + _hc1[4]*_t56*_t57 + _hc1[6]*_t29 + _hc1[6]*_t44 + 0.3e1*_hc2[7]*_t54 + _t10*_t172*_t40 + _t139*_t170 + _t142*_t172 + _t145*_t170 + 0.6e1*_t145*_t34 + _t147*_t176 + _t148*_t81 + _t15*(-_hc0[0]*_hc1[11] - _hc0[1]*_t167 - _hc0[11]*_hc1[0] - _hc0[2]*_hc1[6] - _hc0[3]*_t166 - _hc0[6]*_hc1[2] - _hc0[7]*_t51 - _hc1[3]*_t188) + _t151*_t42 + _t152*_t86 + _t154*_t50 + _t155*_t87 + _t155*_t98 + _t156*_t81 + _t160*_t89 + _t161*_t87 + _t161*_t98 + _t164*_t184 + _t165*_t51 + _t166*_t52 + _t166*_t60 + _t166*_t68 + _t167*_t17 + _t167*_t20 + _t168*_t51 + _t171*_t53 + _t173*_t51 + _t174*_t24 + _t175*_t55 + _t176*_t58 + _t177*_t55 + _t178*_t51 + _t179*_t72 + _t181*_t51 + _t182*_t51 + _t185*_t51 + _t187*_t69 + _t189*_t67 + _t32*_t65 + _t53*_t77 + _t53*_t82 + _t53*_t85 + _t53*_t90 + _t59*_t97 + _t65*_t84;
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = _hc1[12]*_t5 + _hc1[3]*_t104 + 0.2e1*_hc1[3]*_t123 + _hc1[3]*_t131 + _hc1[3]*_t99 + 0.2e1*_hc1[5]*_t10*_t57 + _hc1[5]*_t60 + _hc1[5]*_t68 + _hc2[1]*_t108*_t80 + _hc2[1]*_t134*_t39 + _hc2[12]*_t4 + _hc2[3]*_t100 + _hc2[3]*_t103 + _hc2[3]*_t107 + _hc2[7]*_t43 + _hc2[8]*_t79 + _t10*_t169*_t196 + _t101*_t24 + _t105*_t97 + _t106*_t189 + _t110*_t153*_t27 + _t111*_t148 + _t111*_t156 + _t116*_t19 + 0.2e1*_t116*_t71 + _t117*_t187 + _t136*_t159 + _t143*_t194 + _t143*_t198 + _t144*_t196*_t87 + _t144*_t201 + _t148*_t200 + _t15*(-_hc0[0]*_hc1[12] - _hc0[12]*_hc1[0] - _hc0[3]*_hc1[5] - _hc0[5]*_hc1[3] - _hc0[7]*_t42 - _hc0[8]*_t16 - _hc1[4]*_t212 - _hc1[7]*_t47 - _hc1[8]*_t95) + _t156*_t200 + _t16*_t190 + _t16*_t195*_t6 + _t16*_t202 + _t16*_t205 + _t16*_t206 + _t16*_t209 + _t16*_t48*_t57 + _t164*_t208 + _t165*_t42 + _t168*_t42 + _t17*_t193 + _t171*_t191 + _t173*_t42 + _t175*_t197 + _t177*_t197 + _t178*_t42 + 0.4e1*_t179*_t39 + _t181*_t42 + _t182*_t42 + _t183*_t196 + _t185*_t42 + _t191*_t77 + _t191*_t82 + _t191*_t85 + _t191*_t90 + _t192*_t29 + _t192*_t44 + _t193*_t20 + _t195*_t40 + _t196*_t39*_t57 + _t199*_t88 + _t203*_t210 + _t204*_t87 + _t207*_t87 + _t210*_t211 + _t50*(-_hc0[4]*_t143 - _hc1[4]*_t146 - 0.2e1*_t91 - 0.2e1*_t92 - 0.2e1*_t93 - 0.2e1*_t94);
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = _hc1[1]*_t213 + _hc1[1]*_t217 + _hc1[13]*_t5 + 0.6e1*_hc1[4]*_t123 + _hc1[8]*_t120 + 0.3e1*_hc1[8]*_t44 + _hc1[9]*_t17 + _hc1[9]*_t20 + _hc2[0]*_t116*_t134 + _hc2[13]*_t4 + _hc2[2]*_t106*_t218 + _hc2[2]*_t108*_t215 + _hc2[5]*_t14*_t67 + _hc2[8]*_t121 + _hc2[9]*_t54 + _t100*_t172 + _t101*_t218 + _t103*_t172 + _t104*_t166 + _t107*_t172 + _t108*_t119*_t87 + _t108*_t201 + _t109*_t220 + _t109*_t225*_t49 + _t110*_t122*_t144 + _t111*_t119*_t144 + _t111*_t204 + _t111*_t207 + _t116*_t125 + _t117*_t226 + _t119*_t190 + _t119*_t202 + _t119*_t205 + _t119*_t206 + _t119*_t209 + _t122*_t194 + _t122*_t198 + _t124*_t171 + _t124*_t82 + _t124*_t85 + _t124*_t90 + _t130*_t18 + _t130*_t71 + _t131*_t166 + _t133*_t186 + _t134*_t199 + _t136*(-0.3e1*_t35 - 0.3e1*_t36 - 0.3e1*_t37 - 0.3e1*_t38) + _t15*(-_hc0[0]*_hc1[13] - _hc0[1]*_hc1[9] - _hc0[13]*_hc1[0] - _hc0[8]*_t119 - _hc0[9]*_hc1[1] - _hc1[4]*_t129 - _hc1[5]*_t188 - _hc1[8]*_t128) + _t164*_t227 + _t166*_t99 + _t170*_t214 + _t174*_t48 + _t203*_t222 + _t211*_t222 + _t214*_t215 + _t216*_t51 + _t219*_t87 + _t219*_t98 + _t221*_t67 + _t224*_t87 + _t224*_t98 + _t50*(-_hc1[2]*_t212 - _hc1[4]*_t132 - 0.2e1*_t112 - 0.2e1*_t113 - 0.2e1*_t114 - 0.2e1*_t115);
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = _hc1[14]*_t5 + 0.12e2*_hc1[5]*_t123 + 0.3e1*_hc2[0]*_t106*_t130 + _hc2[14]*_t4 + 0.4e1*_hc2[9]*_t31 + _t103*_t231 + _t104*_t228 + 0.8e1*_t106*_t221 + _t107*_t231 + 0.12e2*_t110*_t232 + 0.8e1*_t111*_t232 + _t118*_t196*_t225 + 0.4e1*_t130*_t32 + _t131*_t228 + 0.2e1*_t133*_t226 + _t136*(-_hc0[2]*_t122 - 0.3e1*_t45 - 0.3e1*_t46) + _t14*_t214*_t230 + _t15*(-_hc0[0]*_hc1[14] - _hc0[14]*_hc1[0] - _hc0[5]*_t228 - _hc0[9]*_t196 - _hc1[9]*_t132) + _t163*_t227*(-0.4e1*_t12 - 0.4e1*_t13) + _t196*_t213 + _t196*_t217 + _t196*_t220*_t41 + _t216*_t230 + _t219*_t233 + _t219*_t234 + _t224*_t233 + _t224*_t234 + _t228*_t99 + _t229*_t29 + _t229*_t44 + _t50*(-_hc0[2]*_t228 - _hc0[5]*_t122 - 0.2e1*_t126 - 0.2e1*_t127);
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_grad_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tp_z0_k, _KMAX)(p, rs, xt, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(fH_z0_k, _KMAX)(p, rs, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = ((_hc0[1]) * (_hc0[1]));
  const double _t2 = _hc0[2]*_hc1[3];
  const double _t3 = _hc1[4] + _t2;
#endif
#if _KMAX >= 3
  const double _t4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t5 = _hc0[4]*_hc1[3];
  const double _t6 = 0.2e1*_hc0[1];
  const double _t7 = _hc0[2]*_hc1[6];
  const double _t8 = _hc0[1]*_hc1[7];
  const double _t9 = _hc0[5]*_hc1[3];
  const double _t10 = _hc0[1]*_t7 + _t5 + _t8;
  const double _t11 = _hc0[2]*_hc1[7] + _hc1[8];
  const double _t12 = 0.2e1*_hc0[5];
  const double _t13 = _hc1[7] + _t7;
  const double _t14 = _hc0[2]*_t13 + _t11 + _t9;
#endif
#if _KMAX >= 4
  const double _t15 = _hc0[2]*_hc1[10];
  const double _t16 = _hc0[4]*_hc1[6];
  const double _t17 = 0.2e1*_hc0[4];
  const double _t18 = _hc0[8]*_hc1[3];
  const double _t19 = _hc1[11]*_t1;
  const double _t20 = _hc0[5]*_hc1[6];
  const double _t21 = _hc0[1]*_hc1[12];
  const double _t22 = _hc0[9]*_hc1[3];
  const double _t23 = _hc0[1]*_hc1[11];
  const double _t24 = _hc0[2]*_t23 + _hc0[4]*_hc1[7] + _t21;
  const double _t25 = _hc0[2]*_hc1[12] + _hc1[13];
  const double _t26 = _hc0[2]*_hc1[11] + _hc1[12];
  const double _t27 = _hc0[2]*_t26 + _hc0[5]*_hc1[7] + _t25;
#endif

  const double f = _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0;
  out[1] = df_dxs1;
  const double df_dxs0 = 0;
  out[2] = df_dxs0;
  const double df_dxt = _hc0[1]*_hc1[1];
  out[3] = df_dxt;
  const double df_drs = _hc0[2]*_hc1[1] + _hc1[2];
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[5] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[6] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[7] = d2f_dxs02;
  const double d2f_dxt_dxs1 = 0;
  out[8] = d2f_dxt_dxs1;
  const double d2f_dxt_dxs0 = 0;
  out[9] = d2f_dxt_dxs0;
  const double d2f_dxt2 = _hc1[3]*_t1;
  out[10] = d2f_dxt2;
  const double d2f_drs_dxs1 = 0;
  out[11] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[12] = d2f_drs_dxs0;
  const double d2f_drs_dxt = _hc0[1]*_hc1[4] + _hc0[1]*_t2 + _hc0[4]*_hc1[1];
  out[13] = d2f_drs_dxt;
  const double d2f_drs2 = _hc0[2]*_hc1[4] + _hc0[2]*_t3 + _hc0[5]*_hc1[1] + _hc1[5];
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[15] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[16] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[17] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[18] = d3f_dxs03;
  const double d3f_dxt_dxs12 = 0;
  out[19] = d3f_dxt_dxs12;
  const double d3f_dxt_dxs0_dxs1 = 0;
  out[20] = d3f_dxt_dxs0_dxs1;
  const double d3f_dxt_dxs02 = 0;
  out[21] = d3f_dxt_dxs02;
  const double d3f_dxt2_dxs1 = 0;
  out[22] = d3f_dxt2_dxs1;
  const double d3f_dxt2_dxs0 = 0;
  out[23] = d3f_dxt2_dxs0;
  const double d3f_dxt3 = _hc1[6]*_t4;
  out[24] = d3f_dxt3;
  const double d3f_drs_dxs12 = 0;
  out[25] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[26] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[27] = d3f_drs_dxs02;
  const double d3f_drs_dxt_dxs1 = 0;
  out[28] = d3f_drs_dxt_dxs1;
  const double d3f_drs_dxt_dxs0 = 0;
  out[29] = d3f_drs_dxt_dxs0;
  const double d3f_drs_dxt2 = _hc1[7]*_t1 + _t1*_t7 + _t5*_t6;
  out[30] = d3f_drs_dxt2;
  const double d3f_drs2_dxs1 = 0;
  out[31] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[32] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = _hc0[1]*_hc1[8] + _hc0[1]*_t9 + _hc0[2]*_t10 + _hc0[2]*_t8 + _hc0[4]*_hc1[4] + _hc0[4]*_t3 + _hc0[8]*_hc1[1];
  out[33] = d3f_drs2_dxt;
  const double d3f_drs3 = _hc0[2]*_hc1[8] + _hc0[2]*_t11 + _hc0[2]*_t14 + _hc0[5]*_hc1[4] + _hc0[9]*_hc1[1] + _hc1[9] + _t12*_t3;
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[35] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[36] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[37] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[38] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[39] = d4f_dxs04;
  const double d4f_dxt_dxs13 = 0;
  out[40] = d4f_dxt_dxs13;
  const double d4f_dxt_dxs0_dxs12 = 0;
  out[41] = d4f_dxt_dxs0_dxs12;
  const double d4f_dxt_dxs02_dxs1 = 0;
  out[42] = d4f_dxt_dxs02_dxs1;
  const double d4f_dxt_dxs03 = 0;
  out[43] = d4f_dxt_dxs03;
  const double d4f_dxt2_dxs12 = 0;
  out[44] = d4f_dxt2_dxs12;
  const double d4f_dxt2_dxs0_dxs1 = 0;
  out[45] = d4f_dxt2_dxs0_dxs1;
  const double d4f_dxt2_dxs02 = 0;
  out[46] = d4f_dxt2_dxs02;
  const double d4f_dxt3_dxs1 = 0;
  out[47] = d4f_dxt3_dxs1;
  const double d4f_dxt3_dxs0 = 0;
  out[48] = d4f_dxt3_dxs0;
  const double d4f_dxt4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[10];
  out[49] = d4f_dxt4;
  const double d4f_drs_dxs13 = 0;
  out[50] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[51] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[52] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[53] = d4f_drs_dxs03;
  const double d4f_drs_dxt_dxs12 = 0;
  out[54] = d4f_drs_dxt_dxs12;
  const double d4f_drs_dxt_dxs0_dxs1 = 0;
  out[55] = d4f_drs_dxt_dxs0_dxs1;
  const double d4f_drs_dxt_dxs02 = 0;
  out[56] = d4f_drs_dxt_dxs02;
  const double d4f_drs_dxt2_dxs1 = 0;
  out[57] = d4f_drs_dxt2_dxs1;
  const double d4f_drs_dxt2_dxs0 = 0;
  out[58] = d4f_drs_dxt2_dxs0;
  const double d4f_drs_dxt3 = _hc1[11]*_t4 + 0.3e1*_t1*_t16 + _t15*_t4;
  out[59] = d4f_drs_dxt3;
  const double d4f_drs2_dxs12 = 0;
  out[60] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[61] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[62] = d4f_drs2_dxs02;
  const double d4f_drs2_dxt_dxs1 = 0;
  out[63] = d4f_drs2_dxt_dxs1;
  const double d4f_drs2_dxt_dxs0 = 0;
  out[64] = d4f_drs2_dxt_dxs0;
  const double d4f_drs2_dxt2 = _hc0[2]*_t19 + _hc0[2]*(_t1*_t15 + _t16*_t6 + _t19) + _hc1[12]*_t1 + _t1*_t20 + _t10*_t17 + _t17*_t8 + _t18*_t6;
  out[65] = d4f_drs2_dxt2;
  const double d4f_drs3_dxs1 = 0;
  out[66] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[67] = d4f_drs3_dxs0;
  const double d4f_drs3_dxt = _hc0[1]*_hc1[13] + _hc0[1]*_t22 + _hc0[13]*_hc1[1] + _hc0[2]*_t21 + _hc0[2]*_t24 + _hc0[2]*(_hc0[1]*_t20 + _hc0[2]*(_hc0[1]*_t15 + _t16 + _t23) + _hc0[4]*_t13 + _t18 + _t24) + _hc0[4]*_hc1[8] + _hc0[4]*_t11 + _hc0[4]*_t14 + _hc0[5]*_t8 + _hc0[8]*_hc1[4] + 0.2e1*_hc0[8]*_t3 + _t10*_t12;
  out[68] = d4f_drs3_dxt;
  const double d4f_drs4 = _hc0[14]*_hc1[1] + _hc0[2]*_hc1[13] + _hc0[2]*_t25 + _hc0[2]*_t27 + _hc0[2]*(_hc0[2]*(_hc0[2]*(_hc1[11] + _t15) + _t20 + _t26) + _t12*_t13 + _t22 + _t27) + _hc0[5]*_hc1[8] + 0.3e1*_hc0[5]*_t14 + _hc0[9]*_hc1[4] + 0.3e1*_hc0[9]*_t3 + _hc1[14] + _t11*_t12;
  out[69] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(f_pbe_grad_z0_k, _KMAX)(p, rs, xt, 0, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc1);

  const double f = _hc0[0] + _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0;
  out[1] = df_dxs1;
  const double df_dxs0 = 0;
  out[2] = df_dxs0;
  const double df_dxt = _hc0[3];
  out[3] = df_dxt;
  const double df_drs = _hc0[4] + _hc1[1];
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[5] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[6] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[7] = d2f_dxs02;
  const double d2f_dxt_dxs1 = 0;
  out[8] = d2f_dxt_dxs1;
  const double d2f_dxt_dxs0 = 0;
  out[9] = d2f_dxt_dxs0;
  const double d2f_dxt2 = _hc0[10];
  out[10] = d2f_dxt2;
  const double d2f_drs_dxs1 = 0;
  out[11] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[12] = d2f_drs_dxs0;
  const double d2f_drs_dxt = _hc0[13];
  out[13] = d2f_drs_dxt;
  const double d2f_drs2 = _hc0[14] + _hc1[2];
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[15] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[16] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[17] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[18] = d3f_dxs03;
  const double d3f_dxt_dxs12 = 0;
  out[19] = d3f_dxt_dxs12;
  const double d3f_dxt_dxs0_dxs1 = 0;
  out[20] = d3f_dxt_dxs0_dxs1;
  const double d3f_dxt_dxs02 = 0;
  out[21] = d3f_dxt_dxs02;
  const double d3f_dxt2_dxs1 = 0;
  out[22] = d3f_dxt2_dxs1;
  const double d3f_dxt2_dxs0 = 0;
  out[23] = d3f_dxt2_dxs0;
  const double d3f_dxt3 = _hc0[24];
  out[24] = d3f_dxt3;
  const double d3f_drs_dxs12 = 0;
  out[25] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[26] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[27] = d3f_drs_dxs02;
  const double d3f_drs_dxt_dxs1 = 0;
  out[28] = d3f_drs_dxt_dxs1;
  const double d3f_drs_dxt_dxs0 = 0;
  out[29] = d3f_drs_dxt_dxs0;
  const double d3f_drs_dxt2 = _hc0[30];
  out[30] = d3f_drs_dxt2;
  const double d3f_drs2_dxs1 = 0;
  out[31] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[32] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = _hc0[33];
  out[33] = d3f_drs2_dxt;
  const double d3f_drs3 = _hc0[34] + _hc1[3];
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[35] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[36] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[37] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[38] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[39] = d4f_dxs04;
  const double d4f_dxt_dxs13 = 0;
  out[40] = d4f_dxt_dxs13;
  const double d4f_dxt_dxs0_dxs12 = 0;
  out[41] = d4f_dxt_dxs0_dxs12;
  const double d4f_dxt_dxs02_dxs1 = 0;
  out[42] = d4f_dxt_dxs02_dxs1;
  const double d4f_dxt_dxs03 = 0;
  out[43] = d4f_dxt_dxs03;
  const double d4f_dxt2_dxs12 = 0;
  out[44] = d4f_dxt2_dxs12;
  const double d4f_dxt2_dxs0_dxs1 = 0;
  out[45] = d4f_dxt2_dxs0_dxs1;
  const double d4f_dxt2_dxs02 = 0;
  out[46] = d4f_dxt2_dxs02;
  const double d4f_dxt3_dxs1 = 0;
  out[47] = d4f_dxt3_dxs1;
  const double d4f_dxt3_dxs0 = 0;
  out[48] = d4f_dxt3_dxs0;
  const double d4f_dxt4 = _hc0[49];
  out[49] = d4f_dxt4;
  const double d4f_drs_dxs13 = 0;
  out[50] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[51] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[52] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[53] = d4f_drs_dxs03;
  const double d4f_drs_dxt_dxs12 = 0;
  out[54] = d4f_drs_dxt_dxs12;
  const double d4f_drs_dxt_dxs0_dxs1 = 0;
  out[55] = d4f_drs_dxt_dxs0_dxs1;
  const double d4f_drs_dxt_dxs02 = 0;
  out[56] = d4f_drs_dxt_dxs02;
  const double d4f_drs_dxt2_dxs1 = 0;
  out[57] = d4f_drs_dxt2_dxs1;
  const double d4f_drs_dxt2_dxs0 = 0;
  out[58] = d4f_drs_dxt2_dxs0;
  const double d4f_drs_dxt3 = _hc0[59];
  out[59] = d4f_drs_dxt3;
  const double d4f_drs2_dxs12 = 0;
  out[60] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[61] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[62] = d4f_drs2_dxs02;
  const double d4f_drs2_dxt_dxs1 = 0;
  out[63] = d4f_drs2_dxt_dxs1;
  const double d4f_drs2_dxt_dxs0 = 0;
  out[64] = d4f_drs2_dxt_dxs0;
  const double d4f_drs2_dxt2 = _hc0[65];
  out[65] = d4f_drs2_dxt2;
  const double d4f_drs3_dxs1 = 0;
  out[66] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[67] = d4f_drs3_dxs0;
  const double d4f_drs3_dxt = _hc0[68];
  out[68] = d4f_drs3_dxt;
  const double d4f_drs4 = _hc0[69] + _hc1[4];
  out[69] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(zvpbeint_nu_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(zvpbeloc_kv_k, _KMAX)(p, rs, _hc0);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = (0.1e1 / (rs * rs * rs));
  const double _t5 = xc_powr(_t4, 1, 3);
  const double _t6 = _t2*_t3*_t5;
  const double _t7 = (0.1e1 / 0.4e1)*_t6;
  const double _t8 = _t1*_t7;
  const double _t9 = _t8*xt;
#if _KMAX >= 1
  const double _t10 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t11 = _t10*_t7;
  const double _t12 = _hc0[1]*_t11;
  const double _t13 = (0.1e1 / rs);
#endif
#if _KMAX >= 2
  const double _t14 = _hc0[2]*_t11;
  const double _t15 = (0.1e1 / 0.2e1)*_t6;
  const double _t16 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t17 = ((_hc0[1]) * (_hc0[1]));
  const double _t18 = _t16*_t17;
  const double _t19 = _t15*_t18;
  const double _t20 = (0.1e1 / (rs * rs));
  const double _t21 = _t1*_t15*_t20;
  const double _t22 = _hc0[1]*_t10;
  const double _t23 = _t13*_t15*_t22;
#endif
#if _KMAX >= 3
  const double _t24 = _hc0[3]*_t11;
  const double _t25 = (0.3e1 / 0.2e1)*_t6;
  const double _t26 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t27 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t26;
  const double _t28 = _t25*_t27;
  const double _t29 = _t1*_t25*_t4;
  const double _t30 = _t20*_t22*_t25;
  const double _t31 = _t13*_t18*_t25;
#endif
#if _KMAX >= 4
  const double _t32 = _t6*xt;
  const double _t33 = _hc0[3]*_t32;
  const double _t34 = 0.6e1*_t32;
  const double _t35 = _hc0[2]*_t6*xt;
  const double _t36 = _t13*_t34;
#endif

  const double f = _t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t8;
  out[1] = df_dxt;
  const double df_drs = -_t12*xt - _t13*_t9;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = 0;
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = -_t12 - _t13*_t8;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = -_t14*xt + _t19*xt + _t21*xt + _t23*xt;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0;
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = 0;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = -_t14 + _t19 + _t21 + _t23;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = (0.3e1 / 0.2e1)*_hc0[1]*_hc0[2]*_t16*_t2*_t3*_t5*xt + (0.3e1 / 0.4e1)*_hc0[2]*_t10*_t13*_t2*_t3*_t5*xt - _t24*xt - _t28*xt - _t29*xt - _t30*xt - _t31*xt;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = 0;
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = 0;
  out[11] = d4f_drs_dxt3;
  const double d4f_drs2_dxt2 = 0;
  out[12] = d4f_drs2_dxt2;
  const double d4f_drs3_dxt = (0.3e1 / 0.2e1)*_hc0[1]*_hc0[2]*_t16*_t2*_t3*_t5 + (0.3e1 / 0.4e1)*_hc0[2]*_t10*_t13*_t2*_t3*_t5 - _t24 - _t28 - _t29 - _t30 - _t31;
  out[13] = d4f_drs3_dxt;
  const double d4f_drs4 = -_hc0[1]*_hc0[2]*_t16*_t36 + 0.2e1*_hc0[1]*_t16*_t33 + ((_hc0[2]) * (_hc0[2]))*_t16*_t25*xt - _hc0[4]*_t11*xt + _t1*_t34/(rs * rs * rs * rs) + _t10*_t13*_t33 - 0.3e1*_t10*_t20*_t35 - 0.9e1*_t17*_t26*_t35 + _t18*_t20*_t34 + _t22*_t34*_t4 + _t27*_t36 + ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t34/xc_powi((_hc0[0]), 5);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(zvpbeint_ff_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(zvpbeint_nu_z0_k, _KMAX)(p, rs, t, _hc0);
  const double _t1 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t2 = exp(-4.9999999999999997e-21*_t1);
#if _KMAX >= 1
  const double _t3 = ((_hc0[0]) * (_hc0[0]));
  const double _t4 = _t2*_t3;
  const double _t5 = 1.4999999999999998e-20*_t4;
#endif
#if _KMAX >= 2
  const double _t6 = ((_hc0[1]) * (_hc0[1]));
  const double _t7 = 2.9999999999999997e-20*_t2;
  const double _t8 = _hc0[0]*_t7;
  const double _t9 = _t2*_t6;
  const double _t10 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t11 = _hc0[1]*_hc0[2];
  const double _t12 = ((_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 3
  const double _t13 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t14 = _t13*_t2;
  const double _t15 = xc_powi((_hc0[0]), 6);
  const double _t16 = 3.3749999999999993e-60*_t15;
  const double _t17 = 5.9999999999999994e-20*_hc0[0];
  const double _t18 = _hc0[4]*_t2;
  const double _t19 = _t6*_t7;
  const double _t20 = _t12*_t2;
  const double _t21 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t22 = 8.9999999999999991e-20*_hc0[0];
  const double _t23 = _hc0[2]*_t2;
  const double _t24 = _t22*_t23;
  const double _t25 = _t2*_t21;
#endif
#if _KMAX >= 4
  const double _t26 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t27 = 4.4999999999999988e-39*_t4;
  const double _t28 = _t2*_t26;
  const double _t29 = 4.049999999999999e-59*xc_powi((_hc0[0]), 5);
  const double _t30 = xc_powi((_hc0[0]), 8);
  const double _t31 = 5.0624999999999981e-80*_t30;
  const double _t32 = 8.9999999999999991e-20*_hc0[4];
  const double _t33 = _hc0[4]*_t9;
  const double _t34 = _hc0[2]*_t14;
  const double _t35 = 1.0124999999999997e-59*_t15;
  const double _t36 = _t11*_t18;
  const double _t37 = ((_hc0[4]) * (_hc0[4]));
  const double _t38 = _hc0[5]*_t2;
  const double _t39 = _t11*_t38;
  const double _t40 = ((_hc0[5]) * (_hc0[5]));
  const double _t41 = _hc0[5]*_t20;
  const double _t42 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
#endif

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_hc0[1]*_t5;
  out[1] = df_dt;
  const double df_drs = -_hc0[2]*_t5;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 2.2499999999999996e-40*_t10*_t9 - _t6*_t8;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = 2.2499999999999996e-40*_hc0[1]*_hc0[2]*_t10*_t2 - _hc0[4]*_t5 - _t11*_t8;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = -_hc0[5]*_t5 + 2.2499999999999996e-40*_t10*_t12*_t2 - _t12*_t8;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 1.3499999999999997e-39*_t1*_t13*_t2 - _t13*_t7 - _t14*_t16;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = 4.4999999999999993e-40*_hc0[1]*_hc0[4]*_t10*_t2 - _hc0[1]*_t17*_t18 + 1.3499999999999997e-39*_hc0[2]*_t1*_t2*_t6 - _hc0[2]*_t16*_t9 - _hc0[2]*_t19;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = 2.2499999999999996e-40*_hc0[1]*_hc0[5]*_t10*_t2 - _hc0[1]*_hc0[5]*_t8 + 1.3499999999999997e-39*_hc0[1]*_t1*_t12*_t2 - _hc0[1]*_t12*_t7 - _hc0[1]*_t16*_t20 + 4.4999999999999993e-40*_hc0[2]*_hc0[4]*_t10*_t2 - _hc0[2]*_t17*_t18 - _hc0[8]*_t5;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = 6.7499999999999985e-40*_hc0[2]*_hc0[5]*_t10*_t2 - _hc0[5]*_t24 - _hc0[9]*_t5 + 1.3499999999999997e-39*_t1*_t2*_t21 - _t16*_t25 - _t21*_t7;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t26*_t27 - _t28*_t29 + _t28*_t31;
  out[10] = d4f_dt4;
  const double d4f_drs_dt3 = _hc0[2]*_t13*_t27 + 4.0499999999999994e-39*_t1*_t33 - _t29*_t34 + _t31*_t34 - _t32*_t9 - _t33*_t35;
  out[11] = d4f_drs_dt3;
  const double d4f_drs2_dt2 = 5.3999999999999988e-39*_hc0[1]*_hc0[2]*_hc0[4]*_t1*_t2 + 4.4999999999999993e-40*_hc0[1]*_hc0[8]*_t10*_t2 - _hc0[1]*_hc0[8]*_t17*_t2 + 1.3499999999999997e-39*_hc0[5]*_t1*_t2*_t6 - _hc0[5]*_t16*_t9 - _hc0[5]*_t19 + 4.4999999999999993e-40*_t10*_t2*_t37 + 4.4999999999999988e-39*_t12*_t2*_t3*_t6 + 5.0624999999999981e-80*_t12*_t2*_t30*_t6 - _t12*_t29*_t9 - 1.3499999999999997e-59*_t15*_t36 - _t17*_t2*_t37 - 1.1999999999999999e-19*_t36;
  out[12] = d4f_drs2_dt2;
  const double d4f_drs3_dt = -_hc0[0]*_t32*_t38 + 4.0499999999999988e-39*_hc0[1]*_hc0[2]*_hc0[5]*_t1*_t2 + 2.2499999999999996e-40*_hc0[1]*_hc0[9]*_t10*_t2 - _hc0[1]*_hc0[9]*_t8 + 4.4999999999999988e-39*_hc0[1]*_t2*_t21*_t3 + 5.0624999999999981e-80*_hc0[1]*_t2*_t21*_t30 - _hc0[1]*_t25*_t29 - _hc0[13]*_t5 + 6.7499999999999985e-40*_hc0[2]*_hc0[8]*_t10*_t2 + 6.7499999999999985e-40*_hc0[4]*_hc0[5]*_t10*_t2 + 4.0499999999999988e-39*_hc0[4]*_t1*_t12*_t2 - _hc0[4]*_t20*_t35 - _hc0[8]*_t24 - _t20*_t32 - _t35*_t39 - 8.9999999999999991e-20*_t39;
  out[13] = d4f_drs3_dt;
  const double d4f_drs4 = -1.1999999999999999e-19*_hc0[0]*_hc0[9]*_t23 - _hc0[14]*_t5 + 8.9999999999999985e-40*_hc0[2]*_hc0[9]*_t10*_t2 + 8.0999999999999989e-39*_hc0[5]*_t1*_t12*_t2 + 6.7499999999999985e-40*_t10*_t2*_t40 - 2.0249999999999995e-59*_t15*_t41 - _t2*_t22*_t40 - _t2*_t29*_t42 + 4.4999999999999988e-39*_t2*_t3*_t42 + 5.0624999999999981e-80*_t2*_t30*_t42 - 1.7999999999999998e-19*_t41;
  out[14] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = xc_powr(na, -1, 3);
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = _t3*_t5;
  const double _t7 = xc_powr(gaa, 1, 2);
  const double _t8 = xc_powr(na, -4, 3);
  const double _t9 = _t7*_t8;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(f_pbe_z0_k, _KMAX)(p, _t6, _t9, 0, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(zvpbeint_ff_z0_k, _KMAX)(p, _t6, _t9, _hc1);
  const double _t10 = _hc0[0]*_hc1[0];
  const double zk = _t10;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = xc_powr(na, -7, 3);
  const double _t13 = (0.4e1 / 0.3e1)*_t12;
  const double _t15 = (0.1e1 / 0.6e1)*_t8;
  const double _t18 = _t13*_t7;
  const double _t19 = _t15*_t3;
  const double _t22 = (0.1e1 / _t7);
  const double _t11 = _hc1[1]*_t7;
  const double _t14 = _hc1[2]*_t3;
  const double _t16 = -_t11*_t13 - _t14*_t15;
  const double _t17 = _hc0[0]*_t16;
  const double _t20 = -_hc0[3]*_t18 - _hc0[4]*_t19;
  const double _t21 = _hc1[0]*_t20;
  const double _t23 = _hc1[1]*_t22;
  const double _t24 = _t23*_t5;
  const double _t25 = _hc0[3]*_t22;
  const double _t26 = _t25*_t5;
  const double dF_dna = _t10 + _t17*na + _t21*na;
  const double dF_dgaa = _hc0[0]*_t24 + _hc1[0]*_t26;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t29 = xc_powr(na, -10, 3);
  const double _t30 = (0.28e2 / 0.9e1)*_t29;
  const double _t31 = (0.2e1 / 0.9e1)*_t12;
  const double _t36 = _t30*_t7;
  const double _t37 = _t3*_t31;
  const double _t45 = xc_powr(na, -11, 3);
  const double _t46 = (0.2e1 / 0.3e1)*_t45;
  const double _t47 = (0.2e1 / 0.3e1)*_t12;
  const double _t48 = _t22*_t3;
  const double _t50 = xc_powr(na, -8, 3);
  const double _t51 = (0.1e1 / 0.12e2)*_t50;
  const double _t54 = _t22*_t47;
  const double _t55 = _t48*_t51;
  const double _t58 = xc_powr(gaa, -3, 2);
  const double _t59 = (0.1e1 / 0.4e1)*_t58;
  const double _t60 = _t4*_t59;
  const double _t61 = xc_powr(na, -5, 3);
  const double _t63 = (0.1e1 / gaa);
  const double _t69 = (0.1e1 / 0.4e1)*_t50;
  const double _t70 = _t63*_t69;
  const double _t27 = _t16*na;
  const double _t28 = 0.2e1*_t20;
  const double _t32 = -_hc1[3]*_t18 - _hc1[4]*_t19;
  const double _t33 = -_hc1[4]*_t18 - _hc1[5]*_t19;
  const double _t34 = _t11*_t30 + _t14*_t31 - _t18*_t32 - _t19*_t33;
  const double _t35 = _hc0[0]*na;
  const double _t38 = -_hc0[10]*_t18 - _hc0[13]*_t19;
  const double _t39 = -_hc0[13]*_t18 - _hc0[14]*_t19;
  const double _t40 = _hc0[3]*_t36 + _hc0[4]*_t37 - _t18*_t38 - _t19*_t39;
  const double _t41 = _hc1[0]*na;
  const double _t42 = _t23*_t8;
  const double _t43 = _hc0[3]*_t8;
  const double _t44 = _t22*_t43;
  const double _t49 = _hc1[4]*_t48;
  const double _t52 = -_hc1[3]*_t46 - _t23*_t47 - _t49*_t51;
  const double _t53 = _hc0[10]*_t46;
  const double _t56 = -_hc0[13]*_t55 - _hc0[3]*_t54 - _t53;
  const double _t57 = _hc0[0]*_hc1[1];
  const double _t62 = _hc0[0]*_t61;
  const double _t64 = _hc1[3]*_t63;
  const double _t65 = (0.1e1 / 0.4e1)*_t64;
  const double _t66 = _hc0[3]*_t61;
  const double _t67 = (0.1e1 / 0.2e1)*_hc1[1];
  const double _t68 = _t63*_t67;
  const double _t71 = _hc0[10]*_t70 - _t43*_t59;
  const double _t72 = _hc1[0]*_t71;
  const double d2F_dna2 = 0.2e1*_t17 + 0.2e1*_t21 + _t27*_t28 + _t34*_t35 + _t40*_t41;
  const double d2F_dna_dgaa = (0.1e1 / 0.2e1)*_hc0[0]*_t42 + (0.1e1 / 0.2e1)*_hc1[0]*_t44 + _t16*_t26 + _t20*_t24 + _t35*_t52 + _t41*_t56;
  const double d2F_dgaa2 = -_t57*_t60 + _t62*_t65 + _t66*_t68 + _t72*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t77 = 0.3e1*na;
  const double _t79 = xc_powr(na, -13, 3);
  const double _t80 = (0.280e3 / 0.27e2)*_t79;
  const double _t81 = (0.14e2 / 0.27e2)*_t29;
  const double _t88 = _t7*_t80;
  const double _t89 = _t3*_t81;
  const double _t100 = xc_powr(na, -14, 3);
  const double _t101 = (0.14e2 / 0.9e1)*_t100;
  const double _t102 = (0.14e2 / 0.9e1)*_t29;
  const double _t103 = (0.1e1 / 0.9e1)*_t45;
  const double _t108 = _t103*_t48;
  const double _t114 = _t59*_t8;
  const double _t121 = _t45*_t63;
  const double _t123 = xc_powi(na, -5);
  const double _t124 = _t123*_t22;
  const double _t125 = (0.1e1 / 0.24e2)*_t3;
  const double _t126 = (0.1e1 / (na * na * na * na));
  const double _t127 = _t126*_t63;
  const double _t132 = xc_powr(gaa, -5, 2);
  const double _t133 = (0.3e1 / 0.8e1)*_t132;
  const double _t134 = _t133*_t4;
  const double _t135 = (0.1e1 / (gaa * gaa));
  const double _t137 = (0.1e1 / (na * na * na));
  const double _t139 = (0.1e1 / 0.8e1)*_t58;
  const double _t141 = (0.3e1 / 0.8e1)*_t135;
  const double _t147 = (0.1e1 / 0.2e1)*_t8;
  const double _t73 = 0.6e1*_t20;
  const double _t74 = 0.3e1*_hc0[0];
  const double _t75 = 0.3e1*_hc1[0];
  const double _t76 = _t20*_t34;
  const double _t78 = _t16*_t40;
  const double _t82 = -_hc1[6]*_t18 - _hc1[7]*_t19;
  const double _t83 = -_hc1[7]*_t18 - _hc1[8]*_t19;
  const double _t84 = _hc1[3]*_t36 + _hc1[4]*_t37 - _t18*_t82 - _t19*_t83;
  const double _t85 = -_hc1[8]*_t18 - _hc1[9]*_t19;
  const double _t86 = _hc1[4]*_t36 + _hc1[5]*_t37 - _t18*_t83 - _t19*_t85;
  const double _t87 = (0.4e1 / 0.9e1)*_t1*_t12*_t2*_t33 - _t11*_t80 - _t14*_t81 - _t18*_t84 - _t19*_t86 + (0.56e2 / 0.9e1)*_t29*_t32*_t7;
  const double _t90 = -_hc0[24]*_t18 - _hc0[30]*_t19;
  const double _t91 = -_hc0[30]*_t18 - _hc0[33]*_t19;
  const double _t92 = _hc0[10]*_t36 + _hc0[13]*_t37 - _t18*_t90 - _t19*_t91;
  const double _t93 = -_hc0[33]*_t18 - _hc0[34]*_t19;
  const double _t94 = _hc0[13]*_t36 + _hc0[14]*_t37 - _t18*_t91 - _t19*_t93;
  const double _t95 = -_hc0[3]*_t88 - _hc0[4]*_t89 + (0.4e1 / 0.9e1)*_t1*_t12*_t2*_t39 - _t18*_t92 - _t19*_t94 + (0.56e2 / 0.9e1)*_t29*_t38*_t7;
  const double _t96 = 0.2e1*_hc0[0];
  const double _t97 = 0.2e1*_hc1[0];
  const double _t98 = _t28*na;
  const double _t99 = _t16*_t56;
  const double _t104 = -_hc1[3]*_t54 - _hc1[6]*_t46 - _hc1[7]*_t55;
  const double _t105 = -_hc1[4]*_t54 - _hc1[7]*_t46 - _hc1[8]*_t55;
  const double _t106 = _hc1[3]*_t101 + _t102*_t23 + _t103*_t49 - _t104*_t18 - _t105*_t19 - _t32*_t54;
  const double _t107 = _hc0[10]*_t101;
  const double _t109 = _hc0[24]*_t46;
  const double _t110 = -_hc0[10]*_t54 - _hc0[30]*_t55 - _t109;
  const double _t111 = _hc0[30]*_t46;
  const double _t112 = -_hc0[13]*_t54 - _hc0[33]*_t55 - _t111;
  const double _t113 = _hc0[13]*_t108 + _t102*_t25 + _t107 - _t110*_t18 - _t112*_t19 - _t38*_t54;
  const double _t115 = _hc0[3]*_t50;
  const double _t116 = _hc1[1]*_t60;
  const double _t117 = _t61*_t65;
  const double _t118 = _t25*_t4;
  const double _t119 = _t23*_t4;
  const double _t120 = _t16*_t71;
  const double _t122 = (0.1e1 / 0.3e1)*_hc1[6];
  const double _t128 = (0.1e1 / 0.3e1)*_hc1[1]*_t12*_t58 - 0.1e1 / 0.3e1*_hc1[3]*_t121 + (0.1e1 / 0.24e2)*_hc1[4]*_t1*_t2*_t50*_t58 - _hc1[7]*_t125*_t127 - _t122*_t124;
  const double _t129 = -_hc0[10]*_t114 + (0.1e1 / 0.4e1)*_hc0[24]*_t50*_t63;
  const double _t130 = -_hc0[13]*_t114 + (0.1e1 / 0.4e1)*_hc0[30]*_t50*_t63;
  const double _t131 = (0.1e1 / 0.3e1)*_hc0[3]*_t12*_t58 - _t129*_t18 - _t130*_t19 - _t53*_t63;
  const double _t136 = (0.3e1 / 0.8e1)*_hc1[3]*_t135;
  const double _t138 = _hc0[0]*_hc1[6]*_t137;
  const double _t140 = _hc1[1]*_t66;
  const double _t142 = _hc1[3]*_t137;
  const double _t143 = _hc0[3]*_t58;
  const double _t144 = (0.3e1 / 0.8e1)*_t143;
  const double _t145 = (0.3e1 / 0.2e1)*_t71;
  const double _t146 = _t129*_t22;
  const double _t148 = -_hc0[10]*_t135*_t69 + _t133*_t43 + _t146*_t147;
  const double _t149 = _hc1[0]*_t148;
  const double d3F_dna3 = _t16*_t73 + _t34*_t74 + _t35*_t87 + _t40*_t75 + _t41*_t95 + _t76*_t77 + _t77*_t78;
  const double d3F_dna2_dgaa = _t106*_t35 + _t113*_t41 + _t16*_t44 + _t20*_t42 + _t24*_t40 + _t26*_t34 + _t52*_t96 + _t52*_t98 + _t56*_t97 + 0.2e1*_t99*na;
  const double d3F_dna_dgaa2 = _hc0[0]*_hc1[3]*_t70 - _t114*_t57 + _t115*_t68 - _t116*_t20 + _t117*_t20 + _t118*_t52 + _t119*_t56 + _t120*na + _t128*_t35 + _t131*_t41 + _t72;
  const double d3F_dgaa3 = _t119*_t145 + _t134*_t57 - _t136*_t62 + _t138*_t139 - _t140*_t141 + _t142*_t144 + _t149*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t153 = xc_powr(na, -16, 3);
  const double _t154 = (0.3640e4 / 0.81e2)*_t153;
  const double _t155 = (0.140e3 / 0.81e2)*_t79;
  const double _t156 = (0.280e3 / 0.9e1)*_t79;
  const double _t157 = (0.28e2 / 0.3e1)*_t29*_t7;
  const double _t158 = _t3*_t47;
  const double _t166 = (0.140e3 / 0.27e2)/xc_powr(na, 17, 3);
  const double _t167 = (0.140e3 / 0.27e2)*_t79;
  const double _t168 = (0.7e1 / 0.27e2)*_t100;
  const double _t169 = _t102*_t22;
  const double _t173 = (0.7e1 / 0.9e1)*_t29;
  const double _t174 = _t13*_t22;
  const double _t175 = (0.1e1 / 0.3e1)*_t124;
  const double _t176 = _t125*_t127;
  const double _t179 = _t133*_t8;
  const double _t184 = _t12*_t132;
  const double _t185 = _t135*_t69;
  const double _t186 = _t147*_t22;
  const double _t188 = (0.15e2 / 0.16e2)/xc_powr(gaa, 7, 2);
  const double _t189 = _t135*_t79;
  const double _t190 = (0.1e1 / (gaa * gaa * gaa));
  const double _t150 = _t34*na;
  const double _t151 = 0.4e1*_t87;
  const double _t152 = 0.4e1*_t95;
  const double _t159 = -_hc1[11]*_t18 - _hc1[12]*_t19;
  const double _t160 = -_hc1[12]*_t18 - _hc1[13]*_t19;
  const double _t161 = _hc1[7]*_t36 + _hc1[8]*_t37 - _t159*_t18 - _t160*_t19;
  const double _t162 = -_hc0[59]*_t18 - _hc0[65]*_t19;
  const double _t163 = -_hc0[65]*_t18 - _hc0[68]*_t19;
  const double _t164 = _hc0[30]*_t36 + _hc0[33]*_t37 - _t162*_t18 - _t163*_t19;
  const double _t165 = _t52*_t77;
  const double _t170 = -_hc1[11]*_t46 - _hc1[12]*_t55 - _hc1[7]*_t54;
  const double _t171 = -_hc0[30]*_t54 - _hc0[59]*_t46 - _hc0[65]*_t55;
  const double _t172 = _hc1[1]*_t58;
  const double _t177 = -_hc0[24]*_t114 + (0.1e1 / 0.4e1)*_hc0[49]*_t50*_t63;
  const double _t178 = -_hc0[30]*_t114 + (0.1e1 / 0.4e1)*_hc0[59]*_t50*_t63;
  const double _t180 = _hc1[6]*_t139;
  const double _t181 = (0.3e1 / 0.4e1)*_t56;
  const double _t182 = _t172*_t4;
  const double _t183 = _t61*_t64;
  const double _t187 = _hc0[10]*_t179 - _hc0[24]*_t185 + _t177*_t186;
  const double d4F_dna4 = _hc0[0]*_t151 + _hc1[0]*_t152 + 0.6e1*_t150*_t40 + _t151*_t20*na + _t152*_t27 + _t35*(-_t102*_t3*_t33 + _t11*_t154 + _t14*_t155 - _t156*_t32*_t7 + _t157*_t84 + _t158*_t86 - _t18*(-_hc1[3]*_t88 - _hc1[4]*_t89 + (0.4e1 / 0.9e1)*_t1*_t12*_t2*_t83 - _t161*_t19 - _t18*(_hc1[6]*_t36 + _hc1[7]*_t37 - _t159*_t19 - _t18*(-_hc1[10]*_t18 - _hc1[11]*_t19)) + (0.56e2 / 0.9e1)*_t29*_t7*_t82) - _t19*(-_hc1[4]*_t88 - _hc1[5]*_t89 + (0.4e1 / 0.9e1)*_t1*_t12*_t2*_t85 - _t161*_t18 - _t19*(_hc1[8]*_t36 + _hc1[9]*_t37 - _t160*_t18 - _t19*(-_hc1[13]*_t18 - _hc1[14]*_t19)) + (0.56e2 / 0.9e1)*_t29*_t7*_t83)) + _t41*(_hc0[3]*_t154*_t7 + _hc0[4]*_t155*_t3 - _t102*_t3*_t39 - _t156*_t38*_t7 + _t157*_t92 + _t158*_t94 - _t18*(-_hc0[10]*_t88 - _hc0[13]*_t89 + (0.4e1 / 0.9e1)*_t1*_t12*_t2*_t91 - _t164*_t19 - _t18*(_hc0[24]*_t36 + _hc0[30]*_t37 - _t162*_t19 - _t18*(-_hc0[49]*_t18 - _hc0[59]*_t19)) + (0.56e2 / 0.9e1)*_t29*_t7*_t90) - _t19*(-_hc0[13]*_t88 - _hc0[14]*_t89 + (0.4e1 / 0.9e1)*_t1*_t12*_t2*_t93 - _t164*_t18 - _t19*(_hc0[33]*_t36 + _hc0[34]*_t37 - _t163*_t18 - _t19*(-_hc0[68]*_t18 - _hc0[69]*_t19)) + (0.56e2 / 0.9e1)*_t29*_t7*_t91)) + 0.12e2*_t76 + 0.12e2*_t78;
  const double d4F_dna3_dgaa = _t106*_t20*_t77 + _t106*_t74 + 0.3e1*_t113*_t27 + _t113*_t75 + 0.3e1*_t150*_t56 + _t165*_t40 + _t24*_t95 + _t26*_t87 + (0.3e1 / 0.2e1)*_t34*_t44 + _t35*(-_hc1[3]*_t166 + (0.4e1 / 0.9e1)*_t1*_t105*_t12*_t2 + (0.56e2 / 0.9e1)*_t104*_t29*_t7 - _t167*_t23 - _t168*_t49 - _t18*(_hc1[3]*_t169 + _hc1[6]*_t101 + _hc1[7]*_t108 - _t170*_t19 - _t18*(-_hc1[10]*_t46 - _hc1[11]*_t55 - _hc1[6]*_t54) - _t54*_t82) - _t19*(_hc1[4]*_t169 + _hc1[7]*_t101 + _hc1[8]*_t108 - _t170*_t18 - _t19*(-_hc1[12]*_t46 - _hc1[13]*_t55 - _hc1[8]*_t54) - _t54*_t83) + (0.28e2 / 0.9e1)*_t22*_t29*_t32 - _t54*_t84) + (0.3e1 / 0.2e1)*_t40*_t42 + _t41*(-_hc0[10]*_t166 - _hc0[13]*_t168*_t48 + (0.4e1 / 0.9e1)*_t1*_t112*_t12*_t2 + (0.56e2 / 0.9e1)*_t110*_t29*_t7 - _t167*_t25 - _t18*(_hc0[10]*_t169 + _hc0[24]*_t101 + _hc0[30]*_t108 - _t171*_t19 - _t18*(-_hc0[24]*_t54 - _hc0[49]*_t46 - _hc0[59]*_t55) - _t54*_t90) - _t19*(_hc0[13]*_t169 + _hc0[30]*_t101 + _hc0[33]*_t108 - _t171*_t18 - _t19*(-_hc0[33]*_t54 - _hc0[65]*_t46 - _hc0[68]*_t55) - _t54*_t91) + (0.28e2 / 0.9e1)*_t22*_t29*_t38 - _t54*_t92) + _t52*_t73 + 0.6e1*_t99;
  const double d4F_dna2_dgaa2 = _t106*_t118 + _t113*_t119 - _t116*_t40 + _t117*_t40 + 0.2e1*_t120 + _t128*_t96 + _t128*_t98 + 0.2e1*_t131*_t27 + _t131*_t97 - _t147*_t172*_t20 + _t150*_t71 + (0.1e1 / 0.2e1)*_t20*_t50*_t64 + _t35*((0.7e1 / 0.9e1)*_hc1[3]*_t100*_t63 - 0.1e1 / 0.18e2*_hc1[4]*_t3*_t45*_t58 + (0.7e1 / 0.9e1)*_hc1[6]*_t22/xc_powi(na, 6) + (0.1e1 / 0.18e2)*_hc1[7]*_t1*_t123*_t2*_t63 - _t104*_t174 + (0.1e1 / 0.3e1)*_t12*_t32*_t58 - _t172*_t173 - _t18*(-_hc1[10]*_t175 - _hc1[11]*_t176 + (0.1e1 / 0.3e1)*_hc1[3]*_t12*_t58 + (0.1e1 / 0.24e2)*_hc1[7]*_t1*_t2*_t50*_t58 - _t121*_t122) - _t19*(-_hc1[11]*_t175 - _hc1[12]*_t176 + (0.1e1 / 0.3e1)*_hc1[4]*_t12*_t58 - 0.1e1 / 0.3e1*_hc1[7]*_t121 + (0.1e1 / 0.24e2)*_hc1[8]*_t1*_t2*_t50*_t58)) + _t41*(_t107*_t63 - _t110*_t174 + (0.1e1 / 0.3e1)*_t12*_t38*_t58 + _t129*_t36 + _t130*_t37 - _t143*_t173 - _t18*((0.1e1 / 0.3e1)*_hc0[10]*_t12*_t58 - _t109*_t63 - _t177*_t18 - _t178*_t19) - _t19*((0.1e1 / 0.3e1)*_hc0[13]*_t12*_t58 - _t111*_t63 - _t178*_t18 - _t19*(-_hc0[33]*_t114 + (0.1e1 / 0.4e1)*_hc0[65]*_t50*_t63))) + 0.2e1*_t42*_t56 + 0.2e1*_t44*_t52 + 0.4e1*_t52*_t56*na;
  const double d4F_dna_dgaa3 = _hc0[0]*_t126*_t180 - _hc0[0]*_t136*_t50 - _hc1[1]*_t115*_t141 + _hc1[1]*_t134*_t20 + _hc1[3]*_t126*_t144 + (0.3e1 / 0.2e1)*_t118*_t128 + (0.3e1 / 0.2e1)*_t119*_t131 - _t136*_t20*_t61 + _t137*_t180*_t20 + _t145*_t42 + _t148*_t27 + _t149 + _t165*_t71 + _t179*_t57 - _t181*_t182 + _t181*_t183 + _t35*(-0.1e1 / 0.6e1*_hc1[10]*_t63/xc_powr(na, 19, 3) - 0.1e1 / 0.48e2*_hc1[11]*_t153*_t3*_t58 + (0.1e1 / 0.2e1)*_hc1[3]*_t135*_t45 - 0.1e1 / 0.16e2*_hc1[4]*_t132*_t3*_t50 + (0.1e1 / 0.16e2)*_hc1[7]*_t1*_t126*_t135*_t2 - _t184*_t67) + _t41*((0.1e1 / 0.2e1)*_hc0[10]*_t135*_t45 - 0.1e1 / 0.2e1*_hc0[3]*_t184 - 0.2e1*_t12*_t146 - _t18*_t187 - _t19*(_hc0[13]*_t179 - _hc0[30]*_t185 + _t178*_t186));
  const double d4F_dgaa4 = (0.1e1 / 0.16e2)*_hc0[0]*_hc1[10]*_t189 + (0.1e1 / 0.4e1)*_hc0[3]*_hc1[6]*_t189 - 0.3e1 / 0.4e1*_hc0[3]*_t132*_t142 + (0.15e2 / 0.16e2)*_hc1[3]*_t190*_t62 + 0.2e1*_t119*_t148 - _t133*_t138 + (0.3e1 / 0.4e1)*_t140*_t190 - _t145*_t182 + _t145*_t183 - _t188*_t4*_t57 + _t41*((0.9e1 / 0.16e2)*_hc0[10]*_t190*_t50 - 0.3e1 / 0.4e1*_t129*_t58*_t8 + _t186*_t187 - _t188*_t43);
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

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = na + nb;
  const double _t5 = xc_powr(_t4, -1, 3);
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = _t3*_t6;
  const double _t8 = na - nb;
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = _t8*_t9;
  const double _t11 = xc_powr(_t4, -4, 3);
  const double _t12 = gaa + 0.2e1*gab + gbb;
  const double _t13 = xc_powr(_t12, 1, 2);
  const double _t14 = _t11*_t13;
  double _hc0[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_pbe_k, _KMAX)(p, _t7, _t10, _t14, 0, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(zvpbeint_ff_k, _KMAX)(p, _t7, _t10, _t14, _hc1);
  const double _t15 = _hc0[0]*_hc1[0];
  const double zk = _t15;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t16 = (0.1e1 / (_t4 * _t4));
  const double _t17 = _t16*_t8;
  const double _t18 = -_t17 + _t9;
  const double _t20 = xc_powr(_t4, -7, 3);
  const double _t21 = (0.4e1 / 0.3e1)*_t20;
  const double _t23 = (0.1e1 / 0.6e1)*_t11;
  const double _t27 = _t13*_t21;
  const double _t28 = _t23*_t3;
  const double _t32 = -_t17 - _t9;
  const double _t38 = (0.1e1 / _t13);
  const double _t39 = _t38*_t6;
  const double _t42 = _t38*_t5;
  const double _t19 = _hc1[1]*_t13;
  const double _t22 = _hc1[3]*_t3;
  const double _t24 = _t19*_t21 + _t22*_t23;
  const double _t25 = _hc1[2]*_t18 - _t24;
  const double _t26 = _hc0[0]*_t25;
  const double _t29 = _hc0[3]*_t27 + _hc0[5]*_t28;
  const double _t30 = _hc0[4]*_t18 - _t29;
  const double _t31 = _hc1[0]*_t30;
  const double _t33 = _hc1[2]*_t32 - _t24;
  const double _t34 = _hc0[0]*_t33;
  const double _t35 = _hc0[4]*_t32 - _t29;
  const double _t36 = _hc1[0]*_t35;
  const double _t37 = _hc0[0]*_hc1[1];
  const double _t40 = _hc0[3]*_hc1[0];
  const double _t41 = _t37*_t39 + _t39*_t40;
  const double dF_dna = _t15 + _t26*_t4 + _t31*_t4;
  const double dF_dnb = _t15 + _t34*_t4 + _t36*_t4;
  const double dF_dgaa = _t41;
  const double dF_dgab = _t37*_t42 + _t40*_t42;
  const double dF_dgbb = _t41;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t45 = 0.2e1*_t16;
  const double _t46 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t47 = 0.2e1*_t46;
  const double _t48 = _t47*_t8;
  const double _t49 = -_t45 + _t48;
  const double _t56 = xc_powr(_t4, -10, 3);
  const double _t57 = (0.28e2 / 0.9e1)*_t56;
  const double _t58 = (0.2e1 / 0.9e1)*_t20;
  const double _t68 = _t13*_t57;
  const double _t69 = _t3*_t58;
  const double _t89 = _t45 + _t48;
  const double _t94 = xc_powr(_t4, -11, 3);
  const double _t95 = (0.2e1 / 0.3e1)*_t94;
  const double _t98 = (0.2e1 / 0.3e1)*_t20;
  const double _t99 = xc_powr(_t4, -8, 3);
  const double _t100 = _t3*_t38;
  const double _t101 = _t100*_t99;
  const double _t102 = (0.1e1 / 0.12e2)*_t101;
  const double _t113 = _t11*_t38;
  const double _t118 = (0.4e1 / 0.3e1)*_t94;
  const double _t120 = (0.1e1 / 0.6e1)*_t101;
  const double _t140 = xc_powr(_t12, -3, 2);
  const double _t141 = _t140*_t5;
  const double _t143 = (0.1e1 / _t12);
  const double _t144 = xc_powr(_t4, -5, 3);
  const double _t145 = _t143*_t144;
  const double _t151 = (0.1e1 / 0.4e1)*_t99;
  const double _t152 = _t11*_t140;
  const double _t157 = (0.1e1 / 0.2e1)*_t99;
  const double _t162 = _t140*_t6;
  const double _t43 = _t25*_t30;
  const double _t44 = 0.2e1*_t43;
  const double _t50 = _hc1[5]*_t27 + _hc1[8]*_t28;
  const double _t51 = _hc1[6]*_t18 - _t50;
  const double _t52 = _hc1[4]*_t27 + _hc1[7]*_t28;
  const double _t53 = _hc1[5]*_t18 - _t52;
  const double _t54 = _hc1[7]*_t27 + _hc1[9]*_t28;
  const double _t55 = _hc1[8]*_t18 - _t54;
  const double _t59 = _t19*_t57 + _t22*_t58;
  const double _t60 = _hc1[2]*_t49 + _t18*_t51 - _t27*_t53 - _t28*_t55 + _t59;
  const double _t61 = _hc0[0]*_t60;
  const double _t62 = _hc0[14]*_t27 + _hc0[19]*_t28;
  const double _t63 = _hc0[15]*_t18 - _t62;
  const double _t64 = _hc0[11]*_t27 + _hc0[18]*_t28;
  const double _t65 = _hc0[14]*_t18 - _t64;
  const double _t66 = _hc0[18]*_t27 + _hc0[20]*_t28;
  const double _t67 = _hc0[19]*_t18 - _t66;
  const double _t70 = _hc0[3]*_t68 + _hc0[5]*_t69;
  const double _t71 = _hc0[4]*_t49 + _t18*_t63 - _t27*_t65 - _t28*_t67 + _t70;
  const double _t72 = _hc1[0]*_t71;
  const double _t73 = _t25*_t35;
  const double _t74 = _t30*_t33;
  const double _t75 = _hc1[6]*_t32 - _t50;
  const double _t76 = _hc1[5]*_t32 - _t52;
  const double _t77 = _hc1[8]*_t32 - _t54;
  const double _t78 = -_t27*_t76 - _t28*_t77 + _t59;
  const double _t79 = _hc1[2]*_t48 + _t18*_t75 + _t78;
  const double _t80 = _hc0[0]*_t79;
  const double _t81 = _hc0[15]*_t32 - _t62;
  const double _t82 = _hc0[14]*_t32 - _t64;
  const double _t83 = _hc0[19]*_t32 - _t66;
  const double _t84 = -_t27*_t82 - _t28*_t83 + _t70;
  const double _t85 = _hc0[4]*_t48 + _t18*_t81 + _t84;
  const double _t86 = _hc1[0]*_t85;
  const double _t87 = _t35*_t4;
  const double _t88 = 0.2e1*_t33;
  const double _t90 = _hc1[2]*_t89 + _t32*_t75 + _t78;
  const double _t91 = _hc0[0]*_t90;
  const double _t92 = _hc0[4]*_t89 + _t32*_t81 + _t84;
  const double _t93 = _hc1[0]*_t92;
  const double _t96 = _hc1[4]*_t95;
  const double _t97 = _hc1[1]*_t38;
  const double _t103 = _hc1[7]*_t102 + _t96 + _t97*_t98;
  const double _t104 = (0.1e1 / 0.2e1)*_hc1[5]*_t11*_t18*_t38 - _t103;
  const double _t105 = _hc0[0]*_t104;
  const double _t106 = _hc0[11]*_t95;
  const double _t107 = _hc0[3]*_t38;
  const double _t108 = _hc0[18]*_t102 + _t106 + _t107*_t98;
  const double _t109 = (0.1e1 / 0.2e1)*_hc0[14]*_t11*_t18*_t38 - _t108;
  const double _t110 = _hc1[0]*_t109;
  const double _t111 = _t107*_t6;
  const double _t112 = _t6*_t97;
  const double _t114 = _t113*_t37;
  const double _t115 = _t113*_t40;
  const double _t116 = (0.1e1 / 0.2e1)*_t114 + (0.1e1 / 0.2e1)*_t115;
  const double _t117 = _t105*_t4 + _t110*_t4 + _t111*_t25 + _t112*_t30 + _t116;
  const double _t119 = _hc1[4]*_t118;
  const double _t121 = _hc1[7]*_t120 + _t119 + _t21*_t97;
  const double _t122 = _hc1[5]*_t11*_t18*_t38 - _t121;
  const double _t123 = _hc0[0]*_t122;
  const double _t124 = _hc0[11]*_t118;
  const double _t125 = _hc0[18]*_t120 + _t107*_t21 + _t124;
  const double _t126 = _hc0[14]*_t11*_t18*_t38 - _t125;
  const double _t127 = _hc1[0]*_t126;
  const double _t128 = _hc0[3]*_t42;
  const double _t129 = _hc1[1]*_t42;
  const double _t130 = _t114 + _t115;
  const double _t131 = (0.1e1 / 0.2e1)*_hc1[5]*_t11*_t32*_t38 - _t103;
  const double _t132 = _hc0[0]*_t131;
  const double _t133 = (0.1e1 / 0.2e1)*_hc0[14]*_t11*_t32*_t38 - _t108;
  const double _t134 = _hc1[0]*_t133;
  const double _t135 = _t111*_t33 + _t112*_t35 + _t116 + _t132*_t4 + _t134*_t4;
  const double _t136 = _hc1[5]*_t11*_t32*_t38 - _t121;
  const double _t137 = _hc0[0]*_t136;
  const double _t138 = _hc0[14]*_t11*_t32*_t38 - _t125;
  const double _t139 = _hc1[0]*_t138;
  const double _t142 = _t141*_t37;
  const double _t146 = _hc0[0]*_hc1[4];
  const double _t147 = _t145*_t146;
  const double _t148 = _hc0[3]*_hc1[1];
  const double _t149 = _t145*_t148;
  const double _t150 = _hc0[11]*_t143;
  const double _t153 = _hc0[3]*_t152;
  const double _t154 = _t150*_t151 - 0.1e1 / 0.4e1*_t153;
  const double _t155 = _hc1[0]*_t154;
  const double _t156 = -0.1e1 / 0.4e1*_t142 + (0.1e1 / 0.4e1)*_t147 + (0.1e1 / 0.2e1)*_t149 + _t155*_t4;
  const double _t158 = _t150*_t157;
  const double _t159 = (0.1e1 / 0.2e1)*_t153;
  const double _t160 = _t158 - _t159;
  const double _t161 = _hc1[0]*_t160;
  const double _t163 = (0.1e1 / 0.2e1)*_t147 + _t149 - _t162*_t37;
  const double _t164 = _hc1[0]*_t150;
  const double _t165 = _t144*_t164;
  const double d2F_dna2 = 0.2e1*_t26 + 0.2e1*_t31 + _t4*_t44 + _t4*_t61 + _t4*_t72;
  const double d2F_dna_dnb = _t26 + _t31 + _t34 + _t36 + _t4*_t73 + _t4*_t74 + _t4*_t80 + _t4*_t86;
  const double d2F_dnb2 = 0.2e1*_t34 + 0.2e1*_t36 + _t4*_t91 + _t4*_t93 + _t87*_t88;
  const double d2F_dna_dgaa = _t117;
  const double d2F_dna_dgab = _t123*_t4 + _t127*_t4 + _t128*_t25 + _t129*_t30 + _t130;
  const double d2F_dna_dgbb = _t117;
  const double d2F_dnb_dgaa = _t135;
  const double d2F_dnb_dgab = _t128*_t33 + _t129*_t35 + _t130 + _t137*_t4 + _t139*_t4;
  const double d2F_dnb_dgbb = _t135;
  const double d2F_dgaa2 = _t156;
  const double d2F_dgaa_dgab = _t161*_t4 + _t163;
  const double d2F_dgaa_dgbb = _t156;
  const double d2F_dgab2 = -_t141*_t40 - _t142 + _t147 + 0.2e1*_t149 + _t165;
  const double d2F_dgab_dgbb = -_t162*_t40 + _t163 + (0.1e1 / 0.2e1)*_t165;
  const double d2F_dgbb2 = _t156;
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
  const double _t170 = 0.6e1*_t46;
  const double _t171 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t172 = _t171*_t8;
  const double _t173 = 0.6e1*_t172;
  const double _t174 = _t170 - _t173;
  const double _t183 = 0.2e1*_t49;
  const double _t192 = (0.56e2 / 0.9e1)*_t56;
  const double _t198 = (0.4e1 / 0.9e1)*_t20;
  const double _t199 = xc_powr(_t4, -13, 3);
  const double _t200 = (0.280e3 / 0.27e2)*_t199;
  const double _t202 = (0.14e2 / 0.27e2)*_t56;
  const double _t222 = _t13*_t192;
  const double _t227 = _t198*_t3;
  const double _t228 = _t13*_t200;
  const double _t230 = _t202*_t3;
  const double _t235 = -_t173 + 0.2e1*_t46;
  const double _t285 = -_t170 - _t173;
  const double _t286 = 0.2e1*_t89;
  const double _t292 = _t38*_t98;
  const double _t302 = xc_powr(_t4, -14, 3);
  const double _t303 = (0.14e2 / 0.9e1)*_t302;
  const double _t304 = (0.14e2 / 0.9e1)*_t56;
  const double _t305 = _t100*_t94;
  const double _t306 = (0.1e1 / 0.9e1)*_t305;
  const double _t335 = _t21*_t38;
  const double _t344 = (0.28e2 / 0.9e1)*_t302;
  const double _t345 = (0.2e1 / 0.9e1)*_t305;
  const double _t365 = _t199*_t38;
  const double _t406 = (0.1e1 / 0.4e1)*_t152;
  const double _t407 = xc_powi(_t4, -5);
  const double _t408 = _t38*_t407;
  const double _t410 = _t143*_t94;
  const double _t411 = _t143*_t171;
  const double _t412 = (0.1e1 / 0.24e2)*_t3;
  const double _t429 = _t143*_t157;
  const double _t430 = _t143*_t151;
  const double _t433 = (0.1e1 / 0.2e1)*_t152;
  const double _t443 = _t143*_t99;
  const double _t448 = (0.1e1 / 0.12e2)*_t3;
  const double _t456 = (0.1e1 / 0.6e1)*_t3;
  const double _t503 = xc_powr(_t12, -5, 2);
  const double _t504 = _t5*_t503;
  const double _t510 = (0.1e1 / (_t12 * _t12));
  const double _t511 = _t144*_t510;
  const double _t518 = _t11*_t503;
  const double _t520 = (0.1e1 / 0.2e1)*_t113;
  const double _t535 = (0.1e1 / 0.2e1)*_t171;
  const double _t543 = (0.1e1 / 0.4e1)*_t171;
  const double _t166 = _t30*_t4;
  const double _t167 = 0.3e1*_t166;
  const double _t168 = _t25*_t4;
  const double _t169 = 0.3e1*_t168;
  const double _t175 = _hc1[12]*_t27 + _hc1[16]*_t28;
  const double _t176 = _hc1[13]*_t18 - _t175;
  const double _t177 = _hc1[11]*_t27 + _hc1[15]*_t28;
  const double _t178 = _hc1[12]*_t18 - _t177;
  const double _t179 = _hc1[15]*_t27 + _hc1[18]*_t28;
  const double _t180 = _hc1[16]*_t18 - _t179;
  const double _t181 = _hc1[5]*_t68 + _hc1[8]*_t69;
  const double _t182 = _hc1[6]*_t49 + _t176*_t18 - _t178*_t27 - _t180*_t28 + _t181;
  const double _t184 = _hc1[5]*_t49;
  const double _t185 = _hc1[10]*_t27 + _hc1[14]*_t28;
  const double _t186 = _hc1[11]*_t18 - _t185;
  const double _t187 = _hc1[14]*_t27 + _hc1[17]*_t28;
  const double _t188 = _hc1[15]*_t18 - _t187;
  const double _t189 = _hc1[4]*_t68 + _hc1[7]*_t69;
  const double _t190 = _t178*_t18 + _t184 - _t186*_t27 - _t188*_t28 + _t189;
  const double _t191 = _t13*_t53;
  const double _t193 = _hc1[17]*_t27 + _hc1[19]*_t28;
  const double _t194 = _hc1[18]*_t18 - _t193;
  const double _t195 = _hc1[7]*_t68 + _hc1[9]*_t69;
  const double _t196 = _hc1[8]*_t49 + _t18*_t180 - _t188*_t27 - _t194*_t28 + _t195;
  const double _t197 = _t3*_t55;
  const double _t201 = _t19*_t200;
  const double _t203 = _t202*_t22;
  const double _t204 = -_t201 - _t203;
  const double _t205 = _hc1[2]*_t174 + _t18*_t182 + _t183*_t51 - _t190*_t27 + _t191*_t192 - _t196*_t28 + _t197*_t198 + _t204;
  const double _t206 = _hc0[0]*_t205;
  const double _t207 = _hc0[39]*_t27 + _hc0[50]*_t28;
  const double _t208 = _hc0[40]*_t18 - _t207;
  const double _t209 = _hc0[36]*_t27 + _hc0[49]*_t28;
  const double _t210 = _hc0[39]*_t18 - _t209;
  const double _t211 = _hc0[49]*_t27 + _hc0[54]*_t28;
  const double _t212 = _hc0[50]*_t18 - _t211;
  const double _t213 = _hc0[14]*_t68 + _hc0[19]*_t69;
  const double _t214 = _hc0[15]*_t49 + _t18*_t208 - _t210*_t27 - _t212*_t28 + _t213;
  const double _t215 = _hc0[14]*_t49;
  const double _t216 = _hc0[30]*_t27 + _hc0[46]*_t28;
  const double _t217 = _hc0[36]*_t18 - _t216;
  const double _t218 = _hc0[46]*_t27 + _hc0[53]*_t28;
  const double _t219 = _hc0[49]*_t18 - _t218;
  const double _t220 = _hc0[11]*_t68 + _hc0[18]*_t69;
  const double _t221 = _t18*_t210 + _t215 - _t217*_t27 - _t219*_t28 + _t220;
  const double _t223 = _hc0[53]*_t27 + _hc0[55]*_t28;
  const double _t224 = _hc0[54]*_t18 - _t223;
  const double _t225 = _hc0[18]*_t68 + _hc0[20]*_t69;
  const double _t226 = _hc0[19]*_t49 + _t18*_t212 - _t219*_t27 - _t224*_t28 + _t225;
  const double _t229 = _hc0[3]*_t228;
  const double _t231 = _hc0[5]*_t230;
  const double _t232 = -_t229 - _t231;
  const double _t233 = _hc0[4]*_t174 + _t18*_t214 + _t183*_t63 - _t221*_t27 + _t222*_t65 - _t226*_t28 + _t227*_t67 + _t232;
  const double _t234 = _hc1[0]*_t233;
  const double _t236 = _hc1[13]*_t32 - _t175;
  const double _t237 = _hc1[12]*_t32 - _t177;
  const double _t238 = _hc1[16]*_t32 - _t179;
  const double _t239 = _t181 - _t237*_t27 - _t238*_t28;
  const double _t240 = _hc1[6]*_t48 + _t18*_t236 + _t239;
  const double _t241 = _hc1[11]*_t32 - _t185;
  const double _t242 = _hc1[15]*_t32 - _t187;
  const double _t243 = _t189 - _t241*_t27 - _t242*_t28;
  const double _t244 = _hc1[5]*_t48 + _t18*_t237 + _t243;
  const double _t245 = _hc1[18]*_t32 - _t193;
  const double _t246 = _t195 - _t242*_t27 - _t245*_t28;
  const double _t247 = _hc1[8]*_t48 + _t18*_t238 + _t246;
  const double _t248 = _hc1[2]*_t235 + _t18*_t240 + _t204 - _t244*_t27 - _t247*_t28 + _t48*_t51 + _t49*_t75 + _t53*_t68 + _t55*_t69 + _t68*_t76 + _t69*_t77;
  const double _t249 = _hc0[0]*_t4;
  const double _t250 = _hc0[40]*_t32 - _t207;
  const double _t251 = _hc0[39]*_t32 - _t209;
  const double _t252 = _hc0[50]*_t32 - _t211;
  const double _t253 = _t213 - _t251*_t27 - _t252*_t28;
  const double _t254 = _hc0[15]*_t48 + _t18*_t250 + _t253;
  const double _t255 = _hc0[36]*_t32 - _t216;
  const double _t256 = _hc0[49]*_t32 - _t218;
  const double _t257 = _t220 - _t255*_t27 - _t256*_t28;
  const double _t258 = _hc0[14]*_t48 + _t18*_t251 + _t257;
  const double _t259 = _hc0[54]*_t32 - _t223;
  const double _t260 = _t225 - _t256*_t27 - _t259*_t28;
  const double _t261 = _hc0[19]*_t48 + _t18*_t252 + _t260;
  const double _t262 = _hc0[4]*_t235 + _t18*_t254 + _t232 - _t258*_t27 - _t261*_t28 + _t48*_t63 + _t49*_t81 + _t65*_t68 + _t67*_t69 + _t68*_t82 + _t69*_t83;
  const double _t263 = _hc1[0]*_t4;
  const double _t264 = _t33*_t4;
  const double _t265 = 0.2e1*_t79;
  const double _t266 = 0.2e1*_t85;
  const double _t267 = 0.2e1*_t73 + 0.2e1*_t74 + 0.2e1*_t80 + 0.2e1*_t86;
  const double _t268 = _t33*_t35;
  const double _t269 = _hc1[8]*_t89 + _t238*_t32 + _t246;
  const double _t270 = _t269*_t28;
  const double _t271 = _hc1[5]*_t89;
  const double _t272 = _t237*_t32 + _t243 + _t271;
  const double _t273 = _t27*_t272;
  const double _t274 = _hc1[6]*_t89 + _t236*_t32 + _t239;
  const double _t275 = -_hc1[2]*_t173 - _hc1[2]*_t47 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t77 + (0.56e2 / 0.9e1)*_t13*_t56*_t76 + _t18*_t274 - _t201 - _t203 - _t270 - _t273 + 0.4e1*_t46*_t75*_t8;
  const double _t276 = _hc0[19]*_t89 + _t252*_t32 + _t260;
  const double _t277 = _t276*_t28;
  const double _t278 = _hc0[14]*_t89;
  const double _t279 = _t251*_t32 + _t257 + _t278;
  const double _t280 = _t27*_t279;
  const double _t281 = _hc0[15]*_t89 + _t250*_t32 + _t253;
  const double _t282 = -_hc0[4]*_t173 - _hc0[4]*_t47 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t83 + (0.56e2 / 0.9e1)*_t13*_t56*_t82 + _t18*_t281 - _t229 - _t231 - _t277 - _t280 + 0.4e1*_t46*_t8*_t81;
  const double _t283 = 0.3e1*_t87;
  const double _t284 = 0.3e1*_t264;
  const double _t287 = _hc1[2]*_t285 + _t204 + _t222*_t76 + _t227*_t77 - _t270 - _t273 + _t274*_t32 + _t286*_t75;
  const double _t288 = _hc0[0]*_t287;
  const double _t289 = _hc0[4]*_t285 + _t222*_t82 + _t227*_t83 + _t232 - _t277 - _t280 + _t281*_t32 + _t286*_t81;
  const double _t290 = _hc1[0]*_t289;
  const double _t291 = _hc1[11]*_t95;
  const double _t293 = _hc1[15]*_t102 + _hc1[5]*_t292 + _t291;
  const double _t294 = (0.1e1 / 0.2e1)*_hc1[12]*_t11*_t18*_t38 - _t293;
  const double _t295 = _hc1[10]*_t95;
  const double _t296 = _hc1[14]*_t102 + _hc1[4]*_t292 + _t295;
  const double _t297 = (0.1e1 / 0.2e1)*_hc1[11]*_t11*_t18*_t38 - _t296;
  const double _t298 = _t113*_t184;
  const double _t299 = _hc1[14]*_t95;
  const double _t300 = _hc1[17]*_t102 + _hc1[7]*_t292 + _t299;
  const double _t301 = (0.1e1 / 0.2e1)*_hc1[15]*_t11*_t18*_t38 - _t300;
  const double _t307 = _hc1[4]*_t303 + _hc1[7]*_t306 + _t304*_t97;
  const double _t308 = _t18*_t294 - _t27*_t297 - _t28*_t301 - _t292*_t53 + (0.1e1 / 0.2e1)*_t298 + _t307;
  const double _t309 = _hc0[0]*_t308;
  const double _t310 = _hc0[36]*_t95;
  const double _t311 = _hc0[14]*_t292 + _hc0[49]*_t102 + _t310;
  const double _t312 = (0.1e1 / 0.2e1)*_hc0[39]*_t11*_t18*_t38 - _t311;
  const double _t313 = _hc0[30]*_t95;
  const double _t314 = _hc0[11]*_t292 + _hc0[46]*_t102 + _t313;
  const double _t315 = (0.1e1 / 0.2e1)*_hc0[36]*_t11*_t18*_t38 - _t314;
  const double _t316 = _t113*_t215;
  const double _t317 = _hc0[46]*_t95;
  const double _t318 = _hc0[18]*_t292 + _hc0[53]*_t102 + _t317;
  const double _t319 = (0.1e1 / 0.2e1)*_hc0[49]*_t11*_t18*_t38 - _t318;
  const double _t320 = _hc0[11]*_t303;
  const double _t321 = _hc0[18]*_t306 + _t107*_t304 + _t320;
  const double _t322 = _t18*_t312 - _t27*_t315 - _t28*_t319 - _t292*_t65 + (0.1e1 / 0.2e1)*_t316 + _t321;
  const double _t323 = _hc1[0]*_t322;
  const double _t324 = 0.2e1*_t166;
  const double _t325 = 0.2e1*_t168;
  const double _t326 = _t107*_t11;
  const double _t327 = _t25*_t326;
  const double _t328 = _t11*_t97;
  const double _t329 = _t30*_t328;
  const double _t330 = _t327 + _t329;
  const double _t331 = _t104*_t324 + 0.2e1*_t105 + _t109*_t325 + 0.2e1*_t110 + _t111*_t60 + _t112*_t71 + _t309*_t4 + _t323*_t4 + _t330;
  const double _t332 = 0.2e1*_t25;
  const double _t333 = 0.2e1*_t30;
  const double _t334 = _hc1[11]*_t118;
  const double _t336 = _hc1[15]*_t120 + _hc1[5]*_t335 + _t334;
  const double _t337 = _hc1[12]*_t11*_t18*_t38 - _t336;
  const double _t338 = _hc1[10]*_t118;
  const double _t339 = _hc1[14]*_t120 + _hc1[4]*_t335 + _t338;
  const double _t340 = _hc1[11]*_t11*_t18*_t38 - _t339;
  const double _t341 = _hc1[14]*_t118;
  const double _t342 = _hc1[17]*_t120 + _hc1[7]*_t335 + _t341;
  const double _t343 = _hc1[15]*_t11*_t18*_t38 - _t342;
  const double _t346 = _hc1[4]*_t344 + _hc1[7]*_t345 + _t57*_t97;
  const double _t347 = _t18*_t337 - _t27*_t340 - _t28*_t343 + _t298 - _t335*_t53 + _t346;
  const double _t348 = _hc0[0]*_t347;
  const double _t349 = _hc0[36]*_t118;
  const double _t350 = _hc0[14]*_t335 + _hc0[49]*_t120 + _t349;
  const double _t351 = _hc0[39]*_t11*_t18*_t38 - _t350;
  const double _t352 = _hc0[30]*_t118;
  const double _t353 = _hc0[11]*_t335 + _hc0[46]*_t120 + _t352;
  const double _t354 = _hc0[36]*_t11*_t18*_t38 - _t353;
  const double _t355 = _hc0[46]*_t118;
  const double _t356 = _hc0[18]*_t335 + _hc0[53]*_t120 + _t355;
  const double _t357 = _hc0[49]*_t11*_t18*_t38 - _t356;
  const double _t358 = _hc0[11]*_t344;
  const double _t359 = _hc0[18]*_t345 + _t107*_t57 + _t358;
  const double _t360 = _t18*_t351 - _t27*_t354 - _t28*_t357 + _t316 - _t335*_t65 + _t359;
  const double _t361 = _hc1[0]*_t360;
  const double _t362 = _t326*_t33;
  const double _t363 = _t328*_t35;
  const double _t364 = (0.1e1 / 0.2e1)*_hc1[12]*_t11*_t32*_t38 - _t293;
  const double _t366 = _hc1[5]*_t365;
  const double _t367 = _t366*_t8;
  const double _t368 = (0.1e1 / 0.2e1)*_hc1[11]*_t11*_t32*_t38 - _t296;
  const double _t369 = (0.1e1 / 0.2e1)*_hc1[15]*_t11*_t32*_t38 - _t300;
  const double _t370 = -_t27*_t368 - _t28*_t369 - _t292*_t76 + _t307;
  const double _t371 = _t18*_t364 + _t367 + _t370;
  const double _t372 = (0.1e1 / 0.2e1)*_hc0[39]*_t11*_t32*_t38 - _t311;
  const double _t373 = _hc0[14]*_t365;
  const double _t374 = _t373*_t8;
  const double _t375 = (0.1e1 / 0.2e1)*_hc0[36]*_t11*_t32*_t38 - _t314;
  const double _t376 = (0.1e1 / 0.2e1)*_hc0[49]*_t11*_t32*_t38 - _t318;
  const double _t377 = -_t27*_t375 - _t28*_t376 - _t292*_t82 + _t321;
  const double _t378 = _t18*_t372 + _t374 + _t377;
  const double _t379 = _t104*_t87 + _t105 + _t109*_t264 + _t110 + _t111*_t79 + _t112*_t85 + _t131*_t166 + _t132 + _t133*_t168 + _t134 + _t249*_t371 + _t263*_t378 + (0.1e1 / 0.2e1)*_t327 + (0.1e1 / 0.2e1)*_t329 + (0.1e1 / 0.2e1)*_t362 + (0.1e1 / 0.2e1)*_t363;
  const double _t380 = _hc1[12]*_t11*_t32*_t38 - _t336;
  const double _t381 = _hc1[11]*_t11*_t32*_t38 - _t339;
  const double _t382 = _hc1[15]*_t11*_t32*_t38 - _t342;
  const double _t383 = -_t27*_t381 - _t28*_t382 - _t335*_t76 + _t346;
  const double _t384 = _t18*_t380 + 0.2e1*_t367 + _t383;
  const double _t385 = _hc0[39]*_t11*_t32*_t38 - _t350;
  const double _t386 = _hc0[36]*_t11*_t32*_t38 - _t353;
  const double _t387 = _hc0[49]*_t11*_t32*_t38 - _t356;
  const double _t388 = -_t27*_t386 - _t28*_t387 - _t335*_t82 + _t359;
  const double _t389 = _t18*_t385 + 0.2e1*_t374 + _t388;
  const double _t390 = _t362 + _t363;
  const double _t391 = _t113*_t271;
  const double _t392 = _t32*_t364 + _t370 + (0.1e1 / 0.2e1)*_t391;
  const double _t393 = _hc0[0]*_t392;
  const double _t394 = _t113*_t278;
  const double _t395 = _t32*_t372 + _t377 + (0.1e1 / 0.2e1)*_t394;
  const double _t396 = _hc1[0]*_t395;
  const double _t397 = 0.2e1*_t87;
  const double _t398 = 0.2e1*_t264;
  const double _t399 = _t111*_t90 + _t112*_t92 + _t131*_t397 + 0.2e1*_t132 + _t133*_t398 + 0.2e1*_t134 + _t390 + _t393*_t4 + _t396*_t4;
  const double _t400 = 0.2e1*_t35;
  const double _t401 = _t32*_t380 + _t383 + _t391;
  const double _t402 = _hc0[0]*_t401;
  const double _t403 = _t32*_t385 + _t388 + _t394;
  const double _t404 = _hc1[0]*_t403;
  const double _t405 = _hc1[5]*_t18;
  const double _t409 = (0.1e1 / 0.3e1)*_hc1[10];
  const double _t413 = -0.1e1 / 0.3e1*_hc1[1]*_t140*_t20 + _hc1[14]*_t411*_t412 + (0.1e1 / 0.3e1)*_hc1[4]*_t410 - 0.1e1 / 0.24e2*_hc1[7]*_t1*_t140*_t2*_t99 + _t408*_t409;
  const double _t414 = (0.1e1 / 0.4e1)*_hc1[11]*_t143*_t18*_t99 - _t405*_t406 - _t413;
  const double _t415 = _hc0[0]*_t414;
  const double _t416 = -_hc0[14]*_t406 + (0.1e1 / 0.4e1)*_hc0[36]*_t143*_t99;
  const double _t417 = _t106*_t143;
  const double _t418 = -_hc0[11]*_t406 + (0.1e1 / 0.4e1)*_hc0[30]*_t143*_t99;
  const double _t419 = -_hc0[18]*_t406 + (0.1e1 / 0.4e1)*_hc0[46]*_t143*_t99;
  const double _t420 = -0.1e1 / 0.3e1*_hc0[3]*_t140*_t20 + _t27*_t418 + _t28*_t419 + _t417;
  const double _t421 = _t18*_t416 - _t420;
  const double _t422 = _hc1[0]*_t421;
  const double _t423 = _t154*_t25;
  const double _t424 = _hc1[1]*_t141;
  const double _t425 = _t30*_t424;
  const double _t426 = _hc1[4]*_t145;
  const double _t427 = _t30*_t426;
  const double _t428 = _t104*_t128 + _t109*_t129;
  const double _t431 = _t146*_t430 + _t148*_t429 + _t155 - _t37*_t406;
  const double _t432 = _t4*_t415 + _t4*_t422 + _t4*_t423 - 0.1e1 / 0.4e1*_t425 + (0.1e1 / 0.4e1)*_t427 + _t428 + _t431;
  const double _t434 = -_hc0[14]*_t433 + (0.1e1 / 0.2e1)*_hc0[36]*_t143*_t99;
  const double _t435 = -0.2e1 / 0.3e1*_hc0[3]*_t140*_t20;
  const double _t436 = _t124*_t143;
  const double _t437 = -_hc0[11]*_t433 + (0.1e1 / 0.2e1)*_hc0[30]*_t143*_t99;
  const double _t438 = -_hc0[18]*_t433 + (0.1e1 / 0.2e1)*_hc0[46]*_t143*_t99;
  const double _t439 = _t27*_t437 + _t28*_t438 + _t435 + _t436;
  const double _t440 = _t18*_t434 - _t439;
  const double _t441 = _hc1[0]*_t440;
  const double _t442 = _t160*_t25;
  const double _t444 = _t148*_t443;
  const double _t445 = _t146*_t429 - _t37*_t433 + _t444;
  const double _t446 = _t161 + _t445;
  const double _t447 = _hc1[10]*_t408;
  const double _t449 = _hc1[14]*_t411;
  const double _t450 = -0.2e1 / 0.3e1*_hc1[1]*_t140*_t20 - 0.1e1 / 0.12e2*_hc1[7]*_t1*_t140*_t2*_t99 + _t143*_t96 + (0.2e1 / 0.3e1)*_t447 + _t448*_t449;
  const double _t451 = (0.1e1 / 0.2e1)*_hc1[11]*_t143*_t18*_t99 - _t405*_t433 - _t450;
  const double _t452 = _hc0[0]*_t451;
  const double _t453 = _hc1[1]*_t140;
  const double _t454 = _t453*_t6;
  const double _t455 = _t111*_t122 + _t112*_t126 - _t30*_t454 + _t4*_t452 + (0.1e1 / 0.2e1)*_t427 + _t428;
  const double _t457 = -0.4e1 / 0.3e1*_hc1[1]*_t140*_t20 - 0.1e1 / 0.6e1*_hc1[7]*_t1*_t140*_t2*_t99 + _t119*_t143 + (0.4e1 / 0.3e1)*_t447 + _t449*_t456;
  const double _t458 = _hc1[11]*_t143*_t18*_t99 - _t152*_t405 - _t457;
  const double _t459 = _hc0[0]*_t458;
  const double _t460 = _hc0[14]*_t18;
  const double _t461 = _hc0[30]*_t408;
  const double _t462 = _hc0[46]*_t411;
  const double _t463 = -0.1e1 / 0.6e1*_hc0[18]*_t1*_t140*_t2*_t99 - 0.4e1 / 0.3e1*_hc0[3]*_t140*_t20 + _t436 + _t456*_t462 + (0.4e1 / 0.3e1)*_t461;
  const double _t464 = _hc0[36]*_t143*_t18*_t99 - _t152*_t460 - _t463;
  const double _t465 = _hc1[0]*_t464;
  const double _t466 = _t144*_t150;
  const double _t467 = _t25*_t466;
  const double _t468 = _hc0[3]*_t141;
  const double _t469 = 0.2e1*_t128;
  const double _t470 = 0.2e1*_t129;
  const double _t471 = _t146*_t443 - _t152*_t37 - _t152*_t40 + _t164*_t99 + 0.2e1*_t444;
  const double _t472 = -0.1e1 / 0.12e2*_hc0[18]*_t1*_t140*_t2*_t99 + _t417 + _t435 + _t448*_t462 + (0.2e1 / 0.3e1)*_t461;
  const double _t473 = (0.1e1 / 0.2e1)*_hc0[36]*_t143*_t18*_t99 - _t433*_t460 - _t472;
  const double _t474 = _hc1[0]*_t473;
  const double _t475 = _hc0[3]*_t140;
  const double _t476 = _t475*_t6;
  const double _t477 = _hc1[0]*_t158 - _t40*_t433 + _t445;
  const double _t478 = _hc1[5]*_t32;
  const double _t479 = (0.1e1 / 0.4e1)*_hc1[11]*_t143*_t32*_t99 - _t406*_t478 - _t413;
  const double _t480 = _hc0[0]*_t479;
  const double _t481 = _t32*_t416 - _t420;
  const double _t482 = _hc1[0]*_t481;
  const double _t483 = _t154*_t33;
  const double _t484 = _t35*_t424;
  const double _t485 = _t35*_t426;
  const double _t486 = _t128*_t131 + _t129*_t133;
  const double _t487 = _t4*_t480 + _t4*_t482 + _t4*_t483 + _t431 - 0.1e1 / 0.4e1*_t484 + (0.1e1 / 0.4e1)*_t485 + _t486;
  const double _t488 = _t32*_t434 - _t439;
  const double _t489 = _hc1[0]*_t488;
  const double _t490 = _t160*_t33;
  const double _t491 = (0.1e1 / 0.2e1)*_hc1[11]*_t143*_t32*_t99 - _t433*_t478 - _t450;
  const double _t492 = _hc0[0]*_t491;
  const double _t493 = _t111*_t136 + _t112*_t138 - _t35*_t454 + _t4*_t492 + (0.1e1 / 0.2e1)*_t485 + _t486;
  const double _t494 = _hc1[11]*_t143*_t32*_t99 - _t152*_t478 - _t457;
  const double _t495 = _hc0[0]*_t494;
  const double _t496 = _hc0[14]*_t32;
  const double _t497 = _hc0[36]*_t143*_t32*_t99 - _t152*_t496 - _t463;
  const double _t498 = _hc1[0]*_t497;
  const double _t499 = _t33*_t466;
  const double _t500 = 0.2e1*_t138;
  const double _t501 = (0.1e1 / 0.2e1)*_hc0[36]*_t143*_t32*_t99 - _t433*_t496 - _t472;
  const double _t502 = _hc1[0]*_t501;
  const double _t505 = _t37*_t504;
  const double _t506 = _hc0[0]*_hc1[10];
  const double _t507 = _t140*_t506;
  const double _t508 = _t46*_t507;
  const double _t509 = (0.3e1 / 0.8e1)*_t146;
  const double _t512 = _t148*_t510;
  const double _t513 = _t144*_t512;
  const double _t514 = (0.3e1 / 0.8e1)*_hc1[4];
  const double _t515 = _t46*_t475;
  const double _t516 = _t129*_t154;
  const double _t517 = _hc0[11]*_t510;
  const double _t519 = _hc0[3]*_t518;
  const double _t521 = -_t151*_t517 + _t418*_t520 + (0.3e1 / 0.8e1)*_t519;
  const double _t522 = _hc1[0]*_t521;
  const double _t523 = _t4*_t522 + (0.3e1 / 0.8e1)*_t505 + (0.1e1 / 0.8e1)*_t508 - _t509*_t511 - 0.3e1 / 0.8e1*_t513 + _t514*_t515 + (0.3e1 / 0.2e1)*_t516;
  const double _t524 = _t157*_t517;
  const double _t525 = (0.3e1 / 0.4e1)*_t519;
  const double _t526 = _t437*_t520 - _t524 + _t525;
  const double _t527 = _hc1[0]*_t526;
  const double _t528 = _t129*_t160;
  const double _t529 = _t146*_t511;
  const double _t530 = _hc1[4]*_t515;
  const double _t531 = (0.3e1 / 0.4e1)*_t505 + (0.1e1 / 0.4e1)*_t508 + _t516 - 0.3e1 / 0.4e1*_t529 + (0.3e1 / 0.4e1)*_t530;
  const double _t532 = _t517*_t99;
  const double _t533 = (0.3e1 / 0.2e1)*_t532;
  const double _t534 = _hc0[30]*_t140;
  const double _t536 = _t534*_t535;
  const double _t537 = (0.3e1 / 0.2e1)*_t519 - _t533 + _t536;
  const double _t538 = _hc1[0]*_t537;
  const double _t539 = _hc0[11]*_t453;
  const double _t540 = _t46*_t539;
  const double _t541 = (0.1e1 / 0.2e1)*_t540;
  const double _t542 = (0.3e1 / 0.2e1)*_t505 + (0.1e1 / 0.2e1)*_t508 - 0.3e1 / 0.2e1*_t529 + (0.3e1 / 0.2e1)*_t530;
  const double _t544 = _t525 - 0.3e1 / 0.4e1*_t532 + _t534*_t543;
  const double _t545 = _hc1[0]*_t544;
  const double _t546 = _hc1[0]*_t534;
  const double _t547 = _t46*_t546;
  const double _t548 = 0.3e1*_hc1[0];
  const double _t549 = _t144*_t517;
  const double _t550 = _t40*_t504;
  const double _t551 = _hc1[0]*_t549;
  const double _t552 = _hc1[0]*_t418;
  const double d3F_dna3 = _t167*_t60 + _t169*_t71 + _t206*_t4 + _t234*_t4 + 0.6e1*_t43 + 0.3e1*_t61 + 0.3e1*_t72;
  const double d3F_dna2_dnb = _t166*_t265 + _t168*_t266 + _t248*_t249 + _t262*_t263 + _t264*_t71 + _t267 + _t44 + _t60*_t87 + _t61 + _t72;
  const double d3F_dna_dnb2 = _t166*_t90 + _t168*_t92 + _t249*_t275 + _t263*_t282 + _t264*_t266 + _t265*_t87 + _t267 + 0.2e1*_t268 + _t91 + _t93;
  const double d3F_dnb3 = 0.6e1*_t268 + _t283*_t90 + _t284*_t92 + _t288*_t4 + _t290*_t4 + 0.3e1*_t91 + 0.3e1*_t93;
  const double d3F_dna2_dgaa = _t331;
  const double d3F_dna2_dgab = _t122*_t324 + 0.2e1*_t123 + _t126*_t325 + 0.2e1*_t127 + _t128*_t60 + _t129*_t71 + _t326*_t332 + _t328*_t333 + _t348*_t4 + _t361*_t4;
  const double d3F_dna2_dgbb = _t331;
  const double d3F_dna_dnb_dgaa = _t379;
  const double d3F_dna_dnb_dgab = _t122*_t87 + _t123 + _t126*_t264 + _t127 + _t128*_t79 + _t129*_t85 + _t136*_t166 + _t137 + _t138*_t168 + _t139 + _t249*_t384 + _t263*_t389 + _t330 + _t390;
  const double d3F_dna_dnb_dgbb = _t379;
  const double d3F_dnb2_dgaa = _t399;
  const double d3F_dnb2_dgab = _t128*_t90 + _t129*_t92 + _t136*_t397 + 0.2e1*_t137 + _t138*_t398 + 0.2e1*_t139 + _t326*_t88 + _t328*_t400 + _t4*_t402 + _t4*_t404;
  const double d3F_dnb2_dgbb = _t399;
  const double d3F_dna_dgaa2 = _t432;
  const double d3F_dna_dgaa_dgab = _t4*_t441 + _t4*_t442 + _t446 + _t455;
  const double d3F_dna_dgaa_dgbb = _t432;
  const double d3F_dna_dgab2 = _t122*_t469 + _t126*_t470 - _t25*_t468 + _t4*_t459 + _t4*_t465 - _t425 + _t427 + _t467 + _t471;
  const double d3F_dna_dgab_dgbb = -_t25*_t476 + _t4*_t474 + _t455 + (0.1e1 / 0.2e1)*_t467 + _t477;
  const double d3F_dna_dgbb2 = _t432;
  const double d3F_dnb_dgaa2 = _t487;
  const double d3F_dnb_dgaa_dgab = _t4*_t489 + _t4*_t490 + _t446 + _t493;
  const double d3F_dnb_dgaa_dgbb = _t487;
  const double d3F_dnb_dgab2 = _t129*_t500 + _t136*_t469 - _t33*_t468 + _t4*_t495 + _t4*_t498 + _t471 - _t484 + _t485 + _t499;
  const double d3F_dnb_dgab_dgbb = -_t33*_t476 + _t4*_t502 + _t477 + _t493 + (0.1e1 / 0.2e1)*_t499;
  const double d3F_dnb_dgbb2 = _t487;
  const double d3F_dgaa3 = _t523;
  const double d3F_dgaa2_dgab = _t4*_t527 - 0.3e1 / 0.4e1*_t513 + _t528 + _t531;
  const double d3F_dgaa2_dgbb = _t523;
  const double d3F_dgaa_dgab2 = _t4*_t538 - 0.2e1*_t513 + 0.2e1*_t528 + _t541 + _t542;
  const double d3F_dgaa_dgab_dgbb = _t112*_t160 + _t4*_t545 - _t513 + _t531 + (0.1e1 / 0.4e1)*_t540;
  const double d3F_dgaa_dgbb2 = _t523;
  const double d3F_dgab3 = 0.3e1*_t505 + _t508 - 0.6e1*_t513 - 0.3e1*_t529 + 0.3e1*_t530 + 0.3e1*_t540 + _t547 - _t548*_t549 + 0.3e1*_t550;
  const double d3F_dgab2_dgbb = -0.3e1*_t513 + (0.3e1 / 0.2e1)*_t540 + _t542 + (0.1e1 / 0.2e1)*_t547 + (0.3e1 / 0.2e1)*_t550 - 0.3e1 / 0.2e1*_t551;
  const double d3F_dgab_dgbb2 = _t42*_t552 - 0.5e1 / 0.4e1*_t513 + _t531 + _t541 + (0.3e1 / 0.4e1)*_t550 - 0.1e1 / 0.2e1*_t551;
  const double d3F_dgbb3 = _t523;
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
  const double _t556 = 0.24e2*_t171;
  const double _t557 = 0.24e2*_t407*_t8;
  const double _t558 = -_t556 + _t557;
  const double _t579 = 0.3e1*_t49;
  const double _t580 = 0.3e1*_t174;
  const double _t581 = (0.280e3 / 0.9e1)*_t199;
  const double _t595 = (0.28e2 / 0.3e1)*_t13*_t56;
  const double _t601 = _t3*_t98;
  const double _t602 = xc_powr(_t4, -16, 3);
  const double _t603 = (0.3640e4 / 0.81e2)*_t602;
  const double _t604 = (0.140e3 / 0.81e2)*_t199;
  const double _t656 = 0.12e2*_t171;
  const double _t657 = _t557 - _t656;
  const double _t669 = 0.2e1*_t235;
  const double _t670 = (0.560e3 / 0.27e2)*_t199;
  const double _t677 = (0.28e2 / 0.27e2)*_t56;
  const double _t713 = 0.4e1*_t46*_t8;
  const double _t714 = _t13*_t670;
  const double _t720 = _t3*_t677;
  const double _t742 = 0.18e2*_t172;
  const double _t743 = _t170*_t8;
  const double _t744 = _t13*_t581;
  const double _t745 = _t3*_t304;
  const double _t749 = _t556 + _t557;
  const double _t750 = 0.3e1*_t285;
  const double _t751 = 0.3e1*_t89;
  const double _t763 = _t304*_t38;
  const double _t771 = xc_powr(_t4, -17, 3);
  const double _t772 = (0.140e3 / 0.27e2)*_t771;
  const double _t774 = (0.140e3 / 0.27e2)*_t365;
  const double _t776 = _t100*_t302;
  const double _t777 = (0.7e1 / 0.27e2)*_t776;
  const double _t802 = _t38*_t57;
  const double _t810 = (0.280e3 / 0.27e2)*_t771;
  const double _t812 = (0.280e3 / 0.27e2)*_t365;
  const double _t814 = (0.14e2 / 0.27e2)*_t776;
  const double _t834 = _t365*_t8;
  const double _t878 = _t38*_t602;
  const double _t879 = 0.3e1*_t878;
  const double _t889 = 0.6e1*_t878;
  const double _t900 = (0.1e1 / 0.3e1)*_t410;
  const double _t901 = (0.1e1 / 0.3e1)*_t408;
  const double _t902 = _t411*_t412;
  const double _t909 = xc_powi(_t4, -6);
  const double _t910 = (0.7e1 / 0.9e1)*_t56;
  const double _t911 = _t140*_t94;
  const double _t925 = (0.1e1 / 0.3e1)*_t140*_t20;
  const double _t950 = _t140*_t98;
  const double _t957 = (0.2e1 / 0.3e1)*_t408;
  const double _t958 = _t411*_t448;
  const double _t962 = (0.1e1 / 0.9e1)*_t3;
  const double _t973 = (0.4e1 / 0.3e1)*_t408;
  const double _t974 = _t411*_t456;
  const double _t977 = _t20*_t38;
  const double _t978 = (0.8e1 / 0.3e1)*_t977;
  const double _t980 = (0.2e1 / 0.9e1)*_t3;
  const double _t986 = _t140*_t21;
  const double _t998 = _t140*_t199;
  const double _t1045 = _t510*_t99;
  const double _t1047 = _t20*_t503;
  const double _t1049 = _t143/xc_powr(_t4, 19, 3);
  const double _t1053 = _t140*_t602;
  const double _t1056 = (0.3e1 / 0.8e1)*_t518;
  const double _t1057 = _t151*_t510;
  const double _t1078 = (0.3e1 / 0.4e1)*_t518;
  const double _t1080 = _t157*_t510;
  const double _t1090 = (0.3e1 / 0.4e1)*_t1045;
  const double _t1094 = (0.1e1 / 0.8e1)*_t3;
  const double _t1102 = (0.3e1 / 0.2e1)*_t518;
  const double _t1103 = (0.3e1 / 0.2e1)*_t1045;
  const double _t1104 = _t140*_t535;
  const double _t1120 = _t140*_t543;
  const double _t1127 = 0.3e1*_t1045;
  const double _t1141 = 0.3e1*_t518;
  const double _t1179 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t1182 = xc_powr(_t12, -7, 2);
  const double _t1183 = (0.15e2 / 0.16e2)*_t1182;
  const double _t1188 = _t46*_t503;
  const double _t1191 = _t199*_t510;
  const double _t1194 = _t1179*_t144;
  const double _t1223 = _t510*_t602;
  const double _t553 = _t30*_t60;
  const double _t554 = _t25*_t71;
  const double _t555 = _t4*_t71;
  const double _t559 = _hc1[23]*_t27 + _hc1[28]*_t28;
  const double _t560 = _hc1[22]*_t27 + _hc1[27]*_t28;
  const double _t561 = _hc1[23]*_t18 - _t560;
  const double _t562 = _hc1[27]*_t27 + _hc1[31]*_t28;
  const double _t563 = _hc1[28]*_t18 - _t562;
  const double _t564 = _hc1[12]*_t68 + _hc1[16]*_t69;
  const double _t565 = _hc1[12]*_t49;
  const double _t566 = _hc1[21]*_t27 + _hc1[26]*_t28;
  const double _t567 = _hc1[22]*_t18 - _t566;
  const double _t568 = _hc1[26]*_t27 + _hc1[30]*_t28;
  const double _t569 = _hc1[27]*_t18 - _t568;
  const double _t570 = _hc1[11]*_t68 + _hc1[15]*_t69;
  const double _t571 = _t18*_t561 - _t27*_t567 - _t28*_t569 + _t565 + _t570;
  const double _t572 = _hc1[30]*_t27 + _hc1[33]*_t28;
  const double _t573 = _hc1[31]*_t18 - _t572;
  const double _t574 = _hc1[15]*_t68 + _hc1[18]*_t69;
  const double _t575 = _hc1[16]*_t49 + _t18*_t563 - _t27*_t569 - _t28*_t573 + _t574;
  const double _t576 = _hc1[5]*_t228;
  const double _t577 = _hc1[8]*_t230;
  const double _t578 = -_t576 - _t577;
  const double _t582 = _hc1[11]*_t49;
  const double _t583 = _hc1[20]*_t27 + _hc1[25]*_t28;
  const double _t584 = _hc1[25]*_t27 + _hc1[29]*_t28;
  const double _t585 = _hc1[26]*_t18 - _t584;
  const double _t586 = _hc1[10]*_t68 + _hc1[14]*_t69;
  const double _t587 = _hc1[15]*_t49;
  const double _t588 = _hc1[29]*_t27 + _hc1[32]*_t28;
  const double _t589 = _hc1[30]*_t18 - _t588;
  const double _t590 = _hc1[14]*_t68 + _hc1[17]*_t69;
  const double _t591 = _t18*_t569 - _t27*_t585 - _t28*_t589 + _t587 + _t590;
  const double _t592 = _hc1[4]*_t228;
  const double _t593 = _hc1[7]*_t230;
  const double _t594 = -_t592 - _t593;
  const double _t596 = _hc1[32]*_t27 + _hc1[34]*_t28;
  const double _t597 = _hc1[17]*_t68 + _hc1[19]*_t69;
  const double _t598 = _hc1[7]*_t228;
  const double _t599 = _hc1[9]*_t230;
  const double _t600 = -_t598 - _t599;
  const double _t605 = _t19*_t603 + _t22*_t604;
  const double _t606 = _hc0[110]*_t28 + _hc0[89]*_t27;
  const double _t607 = _hc0[109]*_t28 + _hc0[86]*_t27;
  const double _t608 = _hc0[89]*_t18 - _t607;
  const double _t609 = _hc0[109]*_t27 + _hc0[120]*_t28;
  const double _t610 = _hc0[110]*_t18 - _t609;
  const double _t611 = _hc0[39]*_t68 + _hc0[50]*_t69;
  const double _t612 = _hc0[39]*_t49;
  const double _t613 = _hc0[106]*_t28 + _hc0[80]*_t27;
  const double _t614 = _hc0[86]*_t18 - _t613;
  const double _t615 = _hc0[106]*_t27 + _hc0[119]*_t28;
  const double _t616 = _hc0[109]*_t18 - _t615;
  const double _t617 = _hc0[36]*_t68 + _hc0[49]*_t69;
  const double _t618 = _t18*_t608 - _t27*_t614 - _t28*_t616 + _t612 + _t617;
  const double _t619 = _hc0[119]*_t27 + _hc0[124]*_t28;
  const double _t620 = _hc0[120]*_t18 - _t619;
  const double _t621 = _hc0[49]*_t68 + _hc0[54]*_t69;
  const double _t622 = _hc0[50]*_t49 + _t18*_t610 - _t27*_t616 - _t28*_t620 + _t621;
  const double _t623 = _hc0[14]*_t228;
  const double _t624 = _hc0[19]*_t230;
  const double _t625 = -_t623 - _t624;
  const double _t626 = _t13*_t65;
  const double _t627 = _hc0[36]*_t49;
  const double _t628 = _hc0[100]*_t28 + _hc0[70]*_t27;
  const double _t629 = _hc0[100]*_t27 + _hc0[116]*_t28;
  const double _t630 = _hc0[106]*_t18 - _t629;
  const double _t631 = _hc0[30]*_t68 + _hc0[46]*_t69;
  const double _t632 = _hc0[49]*_t49;
  const double _t633 = _hc0[116]*_t27 + _hc0[123]*_t28;
  const double _t634 = _hc0[119]*_t18 - _t633;
  const double _t635 = _hc0[46]*_t68 + _hc0[53]*_t69;
  const double _t636 = _t18*_t616 - _t27*_t630 - _t28*_t634 + _t632 + _t635;
  const double _t637 = _hc0[11]*_t228;
  const double _t638 = _hc0[18]*_t230;
  const double _t639 = -_t637 - _t638;
  const double _t640 = _t3*_t67;
  const double _t641 = _hc0[123]*_t27 + _hc0[125]*_t28;
  const double _t642 = _hc0[53]*_t68 + _hc0[55]*_t69;
  const double _t643 = _hc0[18]*_t228;
  const double _t644 = _hc0[20]*_t230;
  const double _t645 = -_t643 - _t644;
  const double _t646 = _hc0[3]*_t13*_t603 + _hc0[5]*_t3*_t604;
  const double _t647 = _t30*_t79;
  const double _t648 = _t25*_t85;
  const double _t649 = _t35*_t60;
  const double _t650 = _t33*_t71;
  const double _t651 = 0.3e1*_t79;
  const double _t652 = _t4*_t60;
  const double _t653 = 0.3e1*_t85;
  const double _t654 = _hc0[0]*_t248;
  const double _t655 = _hc1[0]*_t262;
  const double _t658 = _hc1[24]*_t32 - _t559;
  const double _t659 = _hc1[23]*_t32 - _t560;
  const double _t660 = _hc1[28]*_t32 - _t562;
  const double _t661 = -_t27*_t659 - _t28*_t660 + _t564;
  const double _t662 = _hc1[22]*_t32 - _t566;
  const double _t663 = _hc1[27]*_t32 - _t568;
  const double _t664 = -_t27*_t662 - _t28*_t663 + _t570;
  const double _t665 = _hc1[12]*_t48 + _t18*_t659 + _t664;
  const double _t666 = _hc1[31]*_t32 - _t572;
  const double _t667 = -_t27*_t663 - _t28*_t666 + _t574;
  const double _t668 = _hc1[16]*_t48 + _t18*_t660 + _t667;
  const double _t671 = _hc1[5]*_t235;
  const double _t672 = _hc1[26]*_t32 - _t584;
  const double _t673 = -_t27*(_hc1[21]*_t32 - _t583) - _t28*_t672 + _t586;
  const double _t674 = _hc1[30]*_t32 - _t588;
  const double _t675 = -_t27*_t672 - _t28*_t674 + _t590;
  const double _t676 = _hc1[15]*_t48 + _t18*_t663 + _t675;
  const double _t678 = -_t27*_t674 - _t28*(_hc1[33]*_t32 - _t596) + _t597;
  const double _t679 = _t222*_t244 + _t227*_t247 + _t605;
  const double _t680 = _hc0[90]*_t32 - _t606;
  const double _t681 = _hc0[89]*_t32 - _t607;
  const double _t682 = _hc0[110]*_t32 - _t609;
  const double _t683 = -_t27*_t681 - _t28*_t682 + _t611;
  const double _t684 = _hc0[86]*_t32 - _t613;
  const double _t685 = _hc0[109]*_t32 - _t615;
  const double _t686 = -_t27*_t684 - _t28*_t685 + _t617;
  const double _t687 = _hc0[39]*_t48 + _t18*_t681 + _t686;
  const double _t688 = _hc0[120]*_t32 - _t619;
  const double _t689 = -_t27*_t685 - _t28*_t688 + _t621;
  const double _t690 = _hc0[50]*_t48 + _t18*_t682 + _t689;
  const double _t691 = _hc0[14]*_t235;
  const double _t692 = _hc0[106]*_t32 - _t629;
  const double _t693 = -_t27*(_hc0[80]*_t32 - _t628) - _t28*_t692 + _t631;
  const double _t694 = _hc0[119]*_t32 - _t633;
  const double _t695 = -_t27*_t692 - _t28*_t694 + _t635;
  const double _t696 = _hc0[49]*_t48 + _t18*_t685 + _t695;
  const double _t697 = -_t27*_t694 - _t28*(_hc0[124]*_t32 - _t641) + _t642;
  const double _t698 = _t222*_t258 + _t227*_t261 + _t646;
  const double _t699 = _t35*_t79;
  const double _t700 = _t33*_t85;
  const double _t701 = _t30*_t90;
  const double _t702 = _t25*_t92;
  const double _t703 = _t4*_t79;
  const double _t704 = _hc0[0]*_t275;
  const double _t705 = _hc1[0]*_t282;
  const double _t706 = _hc1[2]*_t557;
  const double _t707 = _hc1[16]*_t89 + _t32*_t660 + _t667;
  const double _t708 = _t28*_t707;
  const double _t709 = _hc1[12]*_t89;
  const double _t710 = _t32*_t659 + _t664 + _t709;
  const double _t711 = _t27*_t710;
  const double _t712 = _hc1[13]*_t89 + _t32*_t658 + _t661;
  const double _t715 = _hc1[15]*_t89;
  const double _t716 = _t32*_t663 + _t675 + _t715;
  const double _t717 = _t28*_t716;
  const double _t718 = _hc1[11]*_t89;
  const double _t719 = _t27*(_t32*_t662 + _t673 + _t718);
  const double _t721 = _t28*(_hc1[18]*_t89 + _t32*_t666 + _t678);
  const double _t722 = _t27*_t716;
  const double _t723 = _hc0[4]*_t557;
  const double _t724 = _hc0[50]*_t89 + _t32*_t682 + _t689;
  const double _t725 = _t28*_t724;
  const double _t726 = _hc0[39]*_t89;
  const double _t727 = _t32*_t681 + _t686 + _t726;
  const double _t728 = _t27*_t727;
  const double _t729 = _hc0[40]*_t89 + _t32*_t680 + _t683;
  const double _t730 = _hc0[49]*_t89;
  const double _t731 = _t32*_t685 + _t695 + _t730;
  const double _t732 = _t28*_t731;
  const double _t733 = _hc0[36]*_t89;
  const double _t734 = _t27*(_t32*_t684 + _t693 + _t733);
  const double _t735 = _t28*(_hc0[54]*_t89 + _t32*_t688 + _t697);
  const double _t736 = _t27*_t731;
  const double _t737 = _t35*_t90;
  const double _t738 = _t33*_t92;
  const double _t739 = _t4*_t92;
  const double _t740 = _t4*_t90;
  const double _t741 = _hc1[6]*_t285 + _t222*_t237 + _t227*_t238 + _t236*_t286 + _t32*_t712 + _t578 - _t708 - _t711;
  const double _t746 = _t269*_t601 - _t27*(_hc1[5]*_t285 + _t222*_t241 + _t227*_t242 + _t237*_t286 + _t32*_t710 + _t594 - _t717 - _t719) + _t272*_t595 - _t28*(_hc1[8]*_t285 + _t222*_t242 + _t227*_t245 + _t238*_t286 + _t32*_t707 + _t600 - _t721 - _t722) + _t605 - _t744*_t76 - _t745*_t77;
  const double _t747 = _hc0[15]*_t285 + _t222*_t251 + _t227*_t252 + _t250*_t286 + _t32*_t729 + _t625 - _t725 - _t728;
  const double _t748 = -_t27*(_hc0[14]*_t285 + _t222*_t255 + _t227*_t256 + _t251*_t286 + _t32*_t727 + _t639 - _t732 - _t734) + _t276*_t601 + _t279*_t595 - _t28*(_hc0[19]*_t285 + _t222*_t256 + _t227*_t259 + _t252*_t286 + _t32*_t724 + _t645 - _t735 - _t736) + _t646 - _t744*_t82 - _t745*_t83;
  const double _t752 = 0.6e1*_t30;
  const double _t753 = 0.6e1*_t25;
  const double _t754 = _t326*_t60;
  const double _t755 = _t328*_t71;
  const double _t756 = 0.3e1*_t652;
  const double _t757 = 0.3e1*_t555;
  const double _t758 = _hc1[12]*_t292 + _hc1[22]*_t95 + _hc1[27]*_t102;
  const double _t759 = _hc1[11]*_t292 + _hc1[21]*_t95 + _hc1[26]*_t102;
  const double _t760 = (0.1e1 / 0.2e1)*_hc1[22]*_t11*_t18*_t38 - _t759;
  const double _t761 = _hc1[15]*_t292 + _hc1[26]*_t95 + _hc1[30]*_t102;
  const double _t762 = (0.1e1 / 0.2e1)*_hc1[27]*_t11*_t18*_t38 - _t761;
  const double _t764 = _hc1[11]*_t303 + _hc1[15]*_t306 + _hc1[5]*_t763;
  const double _t765 = _hc1[10]*_t292 + _hc1[20]*_t95 + _hc1[25]*_t102;
  const double _t766 = _hc1[14]*_t292 + _hc1[25]*_t95 + _hc1[29]*_t102;
  const double _t767 = (0.1e1 / 0.2e1)*_hc1[26]*_t11*_t18*_t38 - _t766;
  const double _t768 = _hc1[10]*_t303 + _hc1[14]*_t306 + _hc1[4]*_t763;
  const double _t769 = _hc1[17]*_t292 + _hc1[29]*_t95 + _hc1[32]*_t102;
  const double _t770 = _hc1[14]*_t303 + _hc1[17]*_t306 + _hc1[7]*_t763;
  const double _t773 = _hc1[4]*_t772;
  const double _t775 = _hc1[1]*_t774;
  const double _t778 = _hc1[7]*_t777;
  const double _t779 = _t773 + _t775 + _t778;
  const double _t780 = _hc0[109]*_t102 + _hc0[39]*_t292 + _hc0[86]*_t95;
  const double _t781 = _hc0[106]*_t102 + _hc0[36]*_t292 + _hc0[80]*_t95;
  const double _t782 = (0.1e1 / 0.2e1)*_hc0[86]*_t11*_t18*_t38 - _t781;
  const double _t783 = _hc0[106]*_t95 + _hc0[119]*_t102 + _hc0[49]*_t292;
  const double _t784 = (0.1e1 / 0.2e1)*_hc0[109]*_t11*_t18*_t38 - _t783;
  const double _t785 = _hc0[14]*_t763 + _hc0[36]*_t303 + _hc0[49]*_t306;
  const double _t786 = _hc0[100]*_t102 + _hc0[30]*_t292 + _hc0[70]*_t95;
  const double _t787 = _hc0[100]*_t95 + _hc0[116]*_t102 + _hc0[46]*_t292;
  const double _t788 = (0.1e1 / 0.2e1)*_hc0[106]*_t11*_t18*_t38 - _t787;
  const double _t789 = _hc0[11]*_t763 + _hc0[30]*_t303 + _hc0[46]*_t306;
  const double _t790 = _hc0[116]*_t95 + _hc0[123]*_t102 + _hc0[53]*_t292;
  const double _t791 = _hc0[18]*_t763 + _hc0[46]*_t303 + _hc0[53]*_t306;
  const double _t792 = _hc0[11]*_t772;
  const double _t793 = _hc0[3]*_t774;
  const double _t794 = _hc0[18]*_t777;
  const double _t795 = _t792 + _t793 + _t794;
  const double _t796 = _t104*_t752 + _t104*_t757 + _t109*_t753 + _t109*_t756 + _t111*_t205 + _t112*_t233 + _t167*_t308 + _t169*_t322 + _t249*((0.1e1 / 0.2e1)*_hc1[5]*_t11*_t174*_t38 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t301 + (0.56e2 / 0.9e1)*_t13*_t297*_t56 + _t18*(-_t178*_t292 + _t18*((0.1e1 / 0.2e1)*_hc1[23]*_t11*_t18*_t38 - _t758) - _t27*_t760 - _t28*_t762 + _t520*_t565 + _t764) - _t190*_t292 - _t27*(_t18*_t760 - _t186*_t292 - _t27*((0.1e1 / 0.2e1)*_hc1[21]*_t11*_t18*_t38 - _t765) - _t28*_t767 + _t520*_t582 + _t768) - _t28*(_t18*_t762 - _t188*_t292 - _t27*_t767 - _t28*((0.1e1 / 0.2e1)*_hc1[30]*_t11*_t18*_t38 - _t769) + _t520*_t587 + _t770) + 0.2e1*_t294*_t49 + (0.28e2 / 0.9e1)*_t38*_t53*_t56 - _t779) + _t263*((0.1e1 / 0.2e1)*_hc0[14]*_t11*_t174*_t38 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t319 + (0.56e2 / 0.9e1)*_t13*_t315*_t56 + _t18*(_t18*((0.1e1 / 0.2e1)*_hc0[89]*_t11*_t18*_t38 - _t780) - _t210*_t292 - _t27*_t782 - _t28*_t784 + _t520*_t612 + _t785) - _t221*_t292 - _t27*(_t18*_t782 - _t217*_t292 - _t27*((0.1e1 / 0.2e1)*_hc0[80]*_t11*_t18*_t38 - _t786) - _t28*_t788 + _t520*_t627 + _t789) - _t28*(_t18*_t784 - _t219*_t292 - _t27*_t788 - _t28*((0.1e1 / 0.2e1)*_hc0[119]*_t11*_t18*_t38 - _t790) + _t520*_t632 + _t791) + 0.2e1*_t312*_t49 + (0.28e2 / 0.9e1)*_t38*_t56*_t65 - _t795) + 0.3e1*_t309 + 0.3e1*_t323 + (0.3e1 / 0.2e1)*_t754 + (0.3e1 / 0.2e1)*_t755;
  const double _t797 = _hc1[12]*_t335 + _hc1[22]*_t118 + _hc1[27]*_t120;
  const double _t798 = _hc1[11]*_t335 + _hc1[21]*_t118 + _hc1[26]*_t120;
  const double _t799 = _hc1[22]*_t11*_t18*_t38 - _t798;
  const double _t800 = _hc1[15]*_t335 + _hc1[26]*_t118 + _hc1[30]*_t120;
  const double _t801 = _hc1[27]*_t11*_t18*_t38 - _t800;
  const double _t803 = _hc1[11]*_t344 + _hc1[15]*_t345 + _hc1[5]*_t802;
  const double _t804 = _hc1[10]*_t335 + _hc1[20]*_t118 + _hc1[25]*_t120;
  const double _t805 = _hc1[14]*_t335 + _hc1[25]*_t118 + _hc1[29]*_t120;
  const double _t806 = _hc1[26]*_t11*_t18*_t38 - _t805;
  const double _t807 = _hc1[10]*_t344 + _hc1[14]*_t345 + _hc1[4]*_t802;
  const double _t808 = _hc1[17]*_t335 + _hc1[29]*_t118 + _hc1[32]*_t120;
  const double _t809 = _hc1[14]*_t344 + _hc1[17]*_t345 + _hc1[7]*_t802;
  const double _t811 = _hc1[4]*_t810;
  const double _t813 = _hc1[1]*_t812;
  const double _t815 = _hc1[7]*_t814;
  const double _t816 = _t811 + _t813 + _t815;
  const double _t817 = _hc0[109]*_t120 + _hc0[39]*_t335 + _hc0[86]*_t118;
  const double _t818 = _hc0[106]*_t120 + _hc0[36]*_t335 + _hc0[80]*_t118;
  const double _t819 = _hc0[86]*_t11*_t18*_t38 - _t818;
  const double _t820 = _hc0[106]*_t118 + _hc0[119]*_t120 + _hc0[49]*_t335;
  const double _t821 = _hc0[109]*_t11*_t18*_t38 - _t820;
  const double _t822 = _hc0[14]*_t802 + _hc0[36]*_t344 + _hc0[49]*_t345;
  const double _t823 = _hc0[100]*_t120 + _hc0[30]*_t335 + _hc0[70]*_t118;
  const double _t824 = _hc0[100]*_t118 + _hc0[116]*_t120 + _hc0[46]*_t335;
  const double _t825 = _hc0[106]*_t11*_t18*_t38 - _t824;
  const double _t826 = _hc0[11]*_t802 + _hc0[30]*_t344 + _hc0[46]*_t345;
  const double _t827 = _hc0[116]*_t118 + _hc0[123]*_t120 + _hc0[53]*_t335;
  const double _t828 = _hc0[18]*_t802 + _hc0[46]*_t344 + _hc0[53]*_t345;
  const double _t829 = _hc0[11]*_t810;
  const double _t830 = _hc0[3]*_t812;
  const double _t831 = _hc0[18]*_t814;
  const double _t832 = _t829 + _t830 + _t831;
  const double _t833 = (0.1e1 / 0.2e1)*_hc1[27]*_t11*_t32*_t38 - _t761;
  const double _t835 = _hc1[15]*_t834;
  const double _t836 = (0.1e1 / 0.2e1)*_hc1[26]*_t11*_t32*_t38 - _t766;
  const double _t837 = -_t242*_t292 - _t27*_t836 - _t28*((0.1e1 / 0.2e1)*_hc1[30]*_t11*_t32*_t38 - _t769) + _t770;
  const double _t838 = (0.1e1 / 0.2e1)*_hc1[22]*_t11*_t32*_t38 - _t759;
  const double _t839 = _hc1[11]*_t834;
  const double _t840 = -_t241*_t292 - _t27*((0.1e1 / 0.2e1)*_hc1[21]*_t11*_t32*_t38 - _t765) - _t28*_t836 + _t768;
  const double _t841 = (0.1e1 / 0.2e1)*_hc1[23]*_t11*_t32*_t38 - _t758;
  const double _t842 = _hc1[12]*_t834;
  const double _t843 = -_t237*_t292 - _t27*_t838 - _t28*_t833 + _t764;
  const double _t844 = (0.1e1 / 0.2e1)*_hc0[109]*_t11*_t32*_t38 - _t783;
  const double _t845 = _hc0[49]*_t834;
  const double _t846 = (0.1e1 / 0.2e1)*_hc0[106]*_t11*_t32*_t38 - _t787;
  const double _t847 = -_t256*_t292 - _t27*_t846 - _t28*((0.1e1 / 0.2e1)*_hc0[119]*_t11*_t32*_t38 - _t790) + _t791;
  const double _t848 = (0.1e1 / 0.2e1)*_hc0[86]*_t11*_t32*_t38 - _t781;
  const double _t849 = _hc0[36]*_t834;
  const double _t850 = -_t255*_t292 - _t27*((0.1e1 / 0.2e1)*_hc0[80]*_t11*_t32*_t38 - _t786) - _t28*_t846 + _t789;
  const double _t851 = (0.1e1 / 0.2e1)*_hc0[89]*_t11*_t32*_t38 - _t780;
  const double _t852 = _hc0[39]*_t834;
  const double _t853 = -_t251*_t292 - _t27*_t848 - _t28*_t844 + _t785;
  const double _t854 = 0.2e1*_t703;
  const double _t855 = _t104*_t4;
  const double _t856 = 0.2e1*_hc0[0];
  const double _t857 = 0.2e1*_hc1[0];
  const double _t858 = _t104*_t400 + _t109*_t88 + _t131*_t333 + _t133*_t332 + _t326*_t79 + _t328*_t85 + _t371*_t856 + _t378*_t857;
  const double _t859 = _t104*_t333 + _t109*_t332 + _t109*_t854 + _t111*_t248 + _t112*_t262 + _t131*_t555 + _t133*_t652 + _t249*(_t18*(_t18*_t841 + _t842 + _t843) - _t244*_t292 - _t27*(_t18*_t838 + _t839 + _t840) - _t28*(_t18*_t833 + _t835 + _t837) + _t294*_t48 + _t297*_t68 + _t301*_t69 + _t364*_t49 + _t368*_t68 + _t369*_t69 + _t520*_t671 + _t53*_t763 + _t76*_t763 - _t773 - _t775 - _t778) + _t263*(_t18*(_t18*_t851 + _t852 + _t853) - _t258*_t292 - _t27*(_t18*_t848 + _t849 + _t850) - _t28*(_t18*_t844 + _t845 + _t847) + _t312*_t48 + _t315*_t68 + _t319*_t69 + _t372*_t49 + _t375*_t68 + _t376*_t69 + _t520*_t691 + _t65*_t763 + _t763*_t82 - _t792 - _t793 - _t794) + _t264*_t322 + _t266*_t855 + _t308*_t87 + _t309 + _t323 + _t324*_t371 + _t325*_t378 + (0.1e1 / 0.2e1)*_t754 + (0.1e1 / 0.2e1)*_t755 + _t858;
  const double _t860 = _hc1[27]*_t11*_t32*_t38 - _t800;
  const double _t861 = _hc1[26]*_t11*_t32*_t38 - _t805;
  const double _t862 = -_t242*_t335 - _t27*_t861 - _t28*(_hc1[30]*_t11*_t32*_t38 - _t808) + _t809;
  const double _t863 = _hc1[22]*_t11*_t32*_t38 - _t798;
  const double _t864 = -_t241*_t335 - _t27*(_hc1[21]*_t11*_t32*_t38 - _t804) - _t28*_t861 + _t807;
  const double _t865 = _hc1[23]*_t11*_t32*_t38 - _t797;
  const double _t866 = -_t237*_t335 - _t27*_t863 - _t28*_t860 + _t803;
  const double _t867 = _hc0[109]*_t11*_t32*_t38 - _t820;
  const double _t868 = _hc0[106]*_t11*_t32*_t38 - _t824;
  const double _t869 = -_t256*_t335 - _t27*_t868 - _t28*(_hc0[119]*_t11*_t32*_t38 - _t827) + _t828;
  const double _t870 = _hc0[86]*_t11*_t32*_t38 - _t818;
  const double _t871 = -_t255*_t335 - _t27*(_hc0[80]*_t11*_t32*_t38 - _t823) - _t28*_t868 + _t826;
  const double _t872 = _hc0[89]*_t11*_t32*_t38 - _t817;
  const double _t873 = -_t251*_t335 - _t27*_t870 - _t28*_t867 + _t822;
  const double _t874 = _t122*_t4;
  const double _t875 = _t122*_t400 + _t126*_t88 + _t136*_t333 + _t138*_t332 + _t265*_t326 + _t266*_t328 + _t384*_t856 + _t389*_t857;
  const double _t876 = _t32*_t841 + _t520*_t709 + _t843;
  const double _t877 = _hc1[5]*_t8;
  const double _t880 = -0.4e1 / 0.9e1*_t1*_t2*_t20*_t369 - 0.56e2 / 0.9e1*_t13*_t368*_t56 + _t27*(_t32*_t838 + _t520*_t718 + _t840) + _t272*_t292 + _t28*(_t32*_t833 + _t520*_t715 + _t837) - 0.28e2 / 0.9e1*_t38*_t56*_t76 + _t779;
  const double _t881 = _t32*_t851 + _t520*_t726 + _t853;
  const double _t882 = _hc0[14]*_t8;
  const double _t883 = -0.4e1 / 0.9e1*_t1*_t2*_t20*_t376 - 0.56e2 / 0.9e1*_t13*_t375*_t56 + _t27*(_t32*_t848 + _t520*_t733 + _t850) + _t279*_t292 + _t28*(_t32*_t844 + _t520*_t730 + _t847) - 0.28e2 / 0.9e1*_t38*_t56*_t82 + _t795;
  const double _t884 = _t131*_t4;
  const double _t885 = _t326*_t90;
  const double _t886 = _t328*_t92;
  const double _t887 = _t104*_t739 + _t109*_t740 + _t111*_t275 + _t112*_t282 + _t131*_t400 + _t133*_t854 + _t133*_t88 + _t166*_t392 + _t168*_t395 + _t249*(_t18*_t876 + 0.4e1*_t364*_t46*_t8 - _t366 - _t877*_t879 - _t880) + _t263*(_t18*_t881 + 0.4e1*_t372*_t46*_t8 - _t373 - _t879*_t882 - _t883) + _t266*_t884 + _t371*_t397 + _t378*_t398 + _t393 + _t396 + _t858 + (0.1e1 / 0.2e1)*_t885 + (0.1e1 / 0.2e1)*_t886;
  const double _t888 = _t113*_t709 + _t32*_t865 + _t866;
  const double _t890 = -0.4e1 / 0.9e1*_t1*_t2*_t20*_t382 - 0.56e2 / 0.9e1*_t13*_t381*_t56 + _t27*(_t113*_t718 + _t32*_t863 + _t864) + _t272*_t335 + _t28*(_t113*_t715 + _t32*_t860 + _t862) - 0.56e2 / 0.9e1*_t38*_t56*_t76 + _t816;
  const double _t891 = _t113*_t726 + _t32*_t872 + _t873;
  const double _t892 = -0.4e1 / 0.9e1*_t1*_t2*_t20*_t387 - 0.56e2 / 0.9e1*_t13*_t386*_t56 + _t27*(_t113*_t733 + _t32*_t870 + _t871) + _t279*_t335 + _t28*(_t113*_t730 + _t32*_t867 + _t869) - 0.56e2 / 0.9e1*_t38*_t56*_t82 + _t832;
  const double _t893 = _t136*_t4;
  const double _t894 = 0.6e1*_t35;
  const double _t895 = 0.6e1*_t33;
  const double _t896 = 0.3e1*_t740;
  const double _t897 = 0.3e1*_t739;
  const double _t898 = _t111*_t287 + _t112*_t289 + _t131*_t894 + _t131*_t897 + _t133*_t895 + _t133*_t896 + _t249*((0.1e1 / 0.2e1)*_hc1[5]*_t11*_t285*_t38 + _t32*_t876 + 0.2e1*_t364*_t89 - _t880) + _t263*((0.1e1 / 0.2e1)*_hc0[14]*_t11*_t285*_t38 + _t32*_t881 + 0.2e1*_t372*_t89 - _t883) + _t283*_t392 + _t284*_t395 + 0.3e1*_t393 + 0.3e1*_t396 + (0.3e1 / 0.2e1)*_t885 + (0.3e1 / 0.2e1)*_t886;
  const double _t899 = _hc1[12]*_t18;
  const double _t903 = _hc1[11]*_t900 - 0.1e1 / 0.24e2*_hc1[15]*_t1*_t140*_t2*_t99 + _hc1[21]*_t901 + _hc1[26]*_t902 - 0.1e1 / 0.3e1*_hc1[5]*_t140*_t20;
  const double _t904 = _hc1[11]*_t18;
  const double _t905 = -0.1e1 / 0.24e2*_hc1[14]*_t1*_t140*_t2*_t99 + _hc1[20]*_t901 + _hc1[25]*_t902 - 0.1e1 / 0.3e1*_hc1[4]*_t140*_t20 + _t409*_t410;
  const double _t906 = _t297*_t335;
  const double _t907 = _hc1[15]*_t18;
  const double _t908 = _hc1[14]*_t900 - 0.1e1 / 0.24e2*_hc1[17]*_t1*_t140*_t2*_t99 + _hc1[25]*_t901 + _hc1[29]*_t902 - 0.1e1 / 0.3e1*_hc1[7]*_t140*_t20;
  const double _t912 = _hc1[7]*_t911;
  const double _t913 = -0.7e1 / 0.9e1*_hc1[10]*_t38*_t909 - 0.1e1 / 0.18e2*_hc1[14]*_t1*_t143*_t2*_t407 - 0.7e1 / 0.9e1*_hc1[4]*_t143*_t302 + (0.1e1 / 0.18e2)*_t3*_t912 + _t453*_t910;
  const double _t914 = -_hc0[39]*_t406 + (0.1e1 / 0.4e1)*_hc0[86]*_t143*_t99;
  const double _t915 = _t143*_t310;
  const double _t916 = -_hc0[36]*_t406 + (0.1e1 / 0.4e1)*_hc0[80]*_t143*_t99;
  const double _t917 = _hc0[106]*_t430 - _hc0[49]*_t406;
  const double _t918 = -0.1e1 / 0.3e1*_hc0[14]*_t140*_t20 + _t27*_t916 + _t28*_t917 + _t915;
  const double _t919 = _t143*_t313;
  const double _t920 = -_hc0[30]*_t406 + (0.1e1 / 0.4e1)*_hc0[70]*_t143*_t99;
  const double _t921 = _hc0[100]*_t430 - _hc0[46]*_t406;
  const double _t922 = -0.1e1 / 0.3e1*_hc0[11]*_t140*_t20 + _t27*_t920 + _t28*_t921 + _t919;
  const double _t923 = _t315*_t335;
  const double _t924 = -_t923;
  const double _t926 = _t143*_t317;
  const double _t927 = -0.1e1 / 0.3e1*_hc0[18]*_t140*_t20 + _t27*_t921 + _t28*(_hc0[116]*_t430 - _hc0[53]*_t406) + _t926;
  const double _t928 = _t143*_t320 + _t418*_t68 + _t419*_t69 - _t475*_t910;
  const double _t929 = _t424*_t71;
  const double _t930 = _t426*_t71;
  const double _t931 = _hc1[4]*_t30;
  const double _t932 = _hc1[1]*_t30;
  const double _t933 = _t429*_t931 - _t433*_t932;
  const double _t934 = _t104*_t326;
  const double _t935 = 0.2e1*_t109;
  const double _t936 = _t128*_t308 + _t129*_t322 + _t328*_t935 + 0.2e1*_t934;
  const double _t937 = 0.4e1*_t109*_t855 + _t154*_t652 + _t249*((0.1e1 / 0.4e1)*_hc1[11]*_t143*_t49*_t99 + (0.1e1 / 0.3e1)*_t140*_t20*_t53 + _t18*((0.1e1 / 0.4e1)*_hc1[22]*_t143*_t18*_t99 - _t406*_t899 - _t903) - _t184*_t406 - _t27*((0.1e1 / 0.4e1)*_hc1[21]*_t143*_t18*_t99 - _t406*_t904 - _t905) - _t28*((0.1e1 / 0.4e1)*_hc1[26]*_t143*_t18*_t99 - _t406*_t907 - _t908) - _t906 - _t913) + _t263*(_t18*(_t18*_t914 - _t918) - _t27*(_t18*_t916 - _t922) - _t28*(_t18*_t917 - _t927) + _t416*_t49 + _t65*_t925 + _t924 + _t928) + _t324*_t414 + _t325*_t421 + 0.2e1*_t415 + 0.2e1*_t422 + 0.2e1*_t423 - 0.1e1 / 0.4e1*_t929 + (0.1e1 / 0.4e1)*_t930 + _t933 + _t936;
  const double _t938 = -_hc0[39]*_t433 + (0.1e1 / 0.2e1)*_hc0[86]*_t143*_t99;
  const double _t939 = -0.2e1 / 0.3e1*_hc0[14]*_t140*_t20;
  const double _t940 = _t143*_t349;
  const double _t941 = -_hc0[36]*_t433 + (0.1e1 / 0.2e1)*_hc0[80]*_t143*_t99;
  const double _t942 = _hc0[106]*_t429 - _hc0[49]*_t433;
  const double _t943 = _t27*_t941 + _t28*_t942 + _t939 + _t940;
  const double _t944 = -0.2e1 / 0.3e1*_hc0[11]*_t140*_t20;
  const double _t945 = _t143*_t352;
  const double _t946 = -_hc0[30]*_t433 + (0.1e1 / 0.2e1)*_hc0[70]*_t143*_t99;
  const double _t947 = _hc0[100]*_t429 - _hc0[46]*_t433;
  const double _t948 = _t27*_t946 + _t28*_t947 + _t944 + _t945;
  const double _t949 = _t292*_t354;
  const double _t951 = -0.2e1 / 0.3e1*_hc0[18]*_t140*_t20;
  const double _t952 = _t143*_t355;
  const double _t953 = _t27*_t947 + _t28*(_hc0[116]*_t429 - _hc0[53]*_t433) + _t951 + _t952;
  const double _t954 = _t304*_t475;
  const double _t955 = _t143*_t358;
  const double _t956 = _t437*_t68 + _t438*_t69 - _t954 + _t955;
  const double _t959 = -0.1e1 / 0.12e2*_hc1[15]*_t1*_t140*_t2*_t99 + _hc1[21]*_t957 + _hc1[26]*_t958 - 0.2e1 / 0.3e1*_hc1[5]*_t140*_t20 + _t143*_t291;
  const double _t960 = -0.1e1 / 0.12e2*_hc1[14]*_t1*_t140*_t2*_t99 + _hc1[20]*_t957 + _hc1[25]*_t958 - 0.2e1 / 0.3e1*_hc1[4]*_t140*_t20 + _t143*_t295;
  const double _t961 = -0.1e1 / 0.12e2*_hc1[17]*_t1*_t140*_t2*_t99 + _hc1[25]*_t957 + _hc1[29]*_t958 - 0.2e1 / 0.3e1*_hc1[7]*_t140*_t20 + _t143*_t299;
  const double _t963 = -0.14e2 / 0.9e1*_hc1[10]*_t38*_t909 - 0.1e1 / 0.9e1*_hc1[14]*_t1*_t143*_t2*_t407 - 0.14e2 / 0.9e1*_hc1[4]*_t143*_t302 + _t304*_t453 + _t912*_t962;
  const double _t964 = 0.2e1*_t855;
  const double _t965 = _t122*_t326;
  const double _t966 = _t126*_t328;
  const double _t967 = _hc1[4]*_t443;
  const double _t968 = _hc1[1]*_t152;
  const double _t969 = _t30*_t967 - _t30*_t968;
  const double _t970 = _t111*_t347 + _t112*_t360 + _t126*_t964 + _t249*((0.1e1 / 0.2e1)*_hc1[11]*_t143*_t49*_t99 + (0.2e1 / 0.3e1)*_t140*_t20*_t53 + _t18*((0.1e1 / 0.2e1)*_hc1[22]*_t143*_t18*_t99 - _t433*_t899 - _t959) - _t184*_t433 - _t27*((0.1e1 / 0.2e1)*_hc1[21]*_t143*_t18*_t99 - _t433*_t904 - _t960) - _t28*((0.1e1 / 0.2e1)*_hc1[26]*_t143*_t18*_t99 - _t433*_t907 - _t961) - _t292*_t340 - _t906 - _t963) + _t324*_t451 + 0.2e1*_t452 - _t454*_t71 + _t874*_t935 + (0.1e1 / 0.2e1)*_t930 + _t936 + _t965 + _t966 + _t969;
  const double _t971 = _t150*_t99;
  const double _t972 = _t466*_t60;
  const double _t975 = -0.1e1 / 0.6e1*_hc1[15]*_t1*_t140*_t2*_t99 + _hc1[21]*_t973 + _hc1[26]*_t974 - 0.4e1 / 0.3e1*_hc1[5]*_t140*_t20 + _t143*_t334;
  const double _t976 = -0.1e1 / 0.6e1*_hc1[14]*_t1*_t140*_t2*_t99 + _hc1[20]*_t973 + _hc1[25]*_t974 - 0.4e1 / 0.3e1*_hc1[4]*_t140*_t20 + _t143*_t338;
  const double _t979 = -0.1e1 / 0.6e1*_hc1[17]*_t1*_t140*_t2*_t99 + _hc1[25]*_t973 + _hc1[29]*_t974 - 0.4e1 / 0.3e1*_hc1[7]*_t140*_t20 + _t143*_t341;
  const double _t981 = -0.28e2 / 0.9e1*_hc1[10]*_t38*_t909 - 0.2e1 / 0.9e1*_hc1[14]*_t1*_t143*_t2*_t407 - 0.28e2 / 0.9e1*_hc1[4]*_t143*_t302 + _t453*_t57 + _t912*_t980;
  const double _t982 = _hc0[39]*_t18;
  const double _t983 = _hc0[106]*_t974 - 0.4e1 / 0.3e1*_hc0[14]*_t140*_t20 - 0.1e1 / 0.6e1*_hc0[49]*_t1*_t140*_t2*_t99 + _hc0[80]*_t973 + _t940;
  const double _t984 = _hc0[36]*_t18;
  const double _t985 = _hc0[100]*_t974 - 0.4e1 / 0.3e1*_hc0[11]*_t140*_t20 - 0.1e1 / 0.6e1*_hc0[46]*_t1*_t140*_t2*_t99 + _hc0[70]*_t973 + _t945;
  const double _t987 = _hc0[49]*_t18;
  const double _t988 = _hc0[100]*_t973 + _hc0[116]*_t974 - 0.4e1 / 0.3e1*_hc0[18]*_t140*_t20 - 0.1e1 / 0.6e1*_hc0[53]*_t1*_t140*_t2*_t99 + _t952;
  const double _t989 = _hc0[18]*_t911;
  const double _t990 = (0.28e2 / 0.9e1)*_hc0[30]*_t38*_t909 + _hc0[46]*_t143*_t407*_t980 - _t475*_t57 + _t955 - _t980*_t989;
  const double _t991 = _hc0[106]*_t958 - 0.1e1 / 0.12e2*_hc0[49]*_t1*_t140*_t2*_t99 + _hc0[80]*_t957 + _t915 + _t939;
  const double _t992 = _hc0[100]*_t958 - 0.1e1 / 0.12e2*_hc0[46]*_t1*_t140*_t2*_t99 + _hc0[70]*_t957 + _t919 + _t944;
  const double _t993 = _hc0[100]*_t957 + _hc0[116]*_t958 - 0.1e1 / 0.12e2*_hc0[53]*_t1*_t140*_t2*_t99 + _t926 + _t951;
  const double _t994 = -0.14e2 / 0.9e1*_hc0[11]*_t143*_t302 - 0.14e2 / 0.9e1*_hc0[30]*_t38*_t909 - 0.1e1 / 0.9e1*_hc0[46]*_t1*_t143*_t2*_t407 + _t954 + _t962*_t989;
  const double _t995 = -_t153*_t25 + _t25*_t971;
  const double _t996 = _hc1[12]*_t32;
  const double _t997 = (0.1e1 / 0.4e1)*_hc1[22]*_t143*_t32*_t99 - _t406*_t996 - _t903;
  const double _t999 = _t877*_t998;
  const double _t1000 = _hc1[11]*_t32;
  const double _t1001 = _t335*_t368;
  const double _t1002 = _hc1[15]*_t32;
  const double _t1003 = _t1001 - 0.1e1 / 0.3e1*_t140*_t20*_t76 + _t27*((0.1e1 / 0.4e1)*_hc1[21]*_t143*_t32*_t99 - _t1000*_t406 - _t905) + _t28*((0.1e1 / 0.4e1)*_hc1[26]*_t143*_t32*_t99 - _t1002*_t406 - _t908) + _t913;
  const double _t1004 = _t32*_t914 - _t918;
  const double _t1005 = _t335*_t375;
  const double _t1006 = -_t1005;
  const double _t1007 = _t1006 - _t27*(_t32*_t916 - _t922) - _t28*(_t32*_t917 - _t927) + _t82*_t925 + _t928;
  const double _t1008 = _hc1[1]*_t35;
  const double _t1009 = _t424*_t85;
  const double _t1010 = _hc1[4]*_t35;
  const double _t1011 = _t426*_t85;
  const double _t1012 = _t131*_t326;
  const double _t1013 = _t133*_t328;
  const double _t1014 = _t1012 + _t1013 + _t109*_t328 + _t128*_t371 + _t129*_t378 + _t934;
  const double _t1015 = -_t1008*_t406 - 0.1e1 / 0.4e1*_t1009 + _t1010*_t430 + (0.1e1 / 0.4e1)*_t1011 + _t1014 + _t133*_t964 + _t154*_t703 + _t166*_t479 + _t168*_t481 + _t249*((0.1e1 / 0.2e1)*_hc1[11]*_t143*_t771*_t8 - _t1003 + _t18*_t997 - 0.1e1 / 0.2e1*_t999) + _t263*(_t1004*_t18 + _t1007 + _t416*_t48) + _t264*_t421 - _t406*_t932 + _t414*_t87 + _t415 + _t422 + _t423 + _t430*_t931 + _t480 + _t482 + _t483 + _t884*_t935;
  const double _t1016 = _t32*_t938 - _t943;
  const double _t1017 = _t292*_t386;
  const double _t1018 = _t1006 - _t1017 - _t27*(_t32*_t941 - _t948) - _t28*(_t32*_t942 - _t953) + _t82*_t950 + _t956;
  const double _t1019 = (0.1e1 / 0.2e1)*_hc1[22]*_t143*_t32*_t99 - _t433*_t996 - _t959;
  const double _t1020 = _t1001 - 0.2e1 / 0.3e1*_t140*_t20*_t76 + _t27*((0.1e1 / 0.2e1)*_hc1[21]*_t143*_t32*_t99 - _t1000*_t433 - _t960) + _t28*((0.1e1 / 0.2e1)*_hc1[26]*_t143*_t32*_t99 - _t1002*_t433 - _t961) + _t292*_t381 + _t963;
  const double _t1021 = _t136*_t326;
  const double _t1022 = _t138*_t328;
  const double _t1023 = -_t1008*_t433 + _t1010*_t429;
  const double _t1024 = (0.1e1 / 0.2e1)*_t1011 + _t1014 + (0.1e1 / 0.2e1)*_t1021 + (0.1e1 / 0.2e1)*_t1022 + _t1023 + _t109*_t893 + _t111*_t384 + _t112*_t389 + _t126*_t884 + _t133*_t874 + _t138*_t855 + _t166*_t491 + _t249*(_hc1[11]*_t143*_t771*_t8 + _t1019*_t18 - _t1020 - _t999) + _t451*_t87 + _t452 - _t454*_t85 + _t492 + _t933 + (0.1e1 / 0.2e1)*_t965 + (0.1e1 / 0.2e1)*_t966;
  const double _t1025 = _hc1[22]*_t143*_t32*_t99 - _t152*_t996 - _t975;
  const double _t1026 = -0.4e1 / 0.3e1*_t140*_t20*_t76 + _t27*(_hc1[21]*_t143*_t32*_t99 - _t1000*_t152 - _t976) + _t28*(_hc1[26]*_t143*_t32*_t99 - _t1002*_t152 - _t979) + _t381*_t978 + _t981;
  const double _t1027 = _hc0[39]*_t32;
  const double _t1028 = _hc0[86]*_t143*_t32*_t99 - _t1027*_t152 - _t983;
  const double _t1029 = _t882*_t998;
  const double _t1030 = _hc0[36]*_t32;
  const double _t1031 = _hc0[49]*_t32;
  const double _t1032 = -_t27*(_hc0[80]*_t143*_t32*_t99 - _t1030*_t152 - _t985) - _t28*(_hc0[106]*_t143*_t32*_t99 - _t1031*_t152 - _t988) - _t386*_t978 + _t82*_t986 + _t990;
  const double _t1033 = 0.2e1*_t893;
  const double _t1034 = _t466*_t79;
  const double _t1035 = _t35*_t967 - _t35*_t968;
  const double _t1036 = -_t153*_t33 + _t33*_t971;
  const double _t1037 = (0.1e1 / 0.2e1)*_hc0[86]*_t143*_t32*_t99 - _t1027*_t433 - _t991;
  const double _t1038 = _t1005 + _t1017 - 0.2e1 / 0.3e1*_t140*_t20*_t82 + _t27*((0.1e1 / 0.2e1)*_hc0[80]*_t143*_t32*_t99 - _t1030*_t433 - _t992) + _t28*((0.1e1 / 0.2e1)*_hc0[106]*_t143*_t32*_t99 - _t1031*_t433 - _t993) + _t994;
  const double _t1039 = _t424*_t92;
  const double _t1040 = _t426*_t92;
  const double _t1041 = 0.2e1*_t1012 + 0.2e1*_t1013 + _t128*_t392 + _t129*_t395;
  const double _t1042 = _t1023 - 0.1e1 / 0.4e1*_t1039 + (0.1e1 / 0.4e1)*_t1040 + _t1041 + 0.4e1*_t133*_t884 + _t154*_t740 + _t249*((0.1e1 / 0.4e1)*_hc1[11]*_t143*_t89*_t99 - _t1003 - _t271*_t406 + _t32*_t997) + _t263*(_t1004*_t32 + _t1007 + _t416*_t89) + _t397*_t479 + _t398*_t481 + 0.2e1*_t480 + 0.2e1*_t482 + 0.2e1*_t483;
  const double _t1043 = _t1021 + _t1022 + _t1033*_t133 + _t1035 + (0.1e1 / 0.2e1)*_t1040 + _t1041 + _t111*_t401 + _t112*_t403 + _t249*((0.1e1 / 0.2e1)*_hc1[11]*_t143*_t89*_t99 + _t1019*_t32 - _t1020 - _t271*_t433) + _t397*_t491 - _t454*_t92 + 0.2e1*_t492 + _t500*_t884;
  const double _t1044 = _t466*_t90;
  const double _t1046 = _t1045*_t904;
  const double _t1048 = _hc1[1]*_t1047;
  const double _t1050 = _hc1[20]*_t1049;
  const double _t1051 = _hc1[7]*_t503;
  const double _t1052 = _t1051*_t99;
  const double _t1054 = _hc1[25]*_t1053;
  const double _t1055 = -0.1e1 / 0.16e2*_hc1[14]*_t1*_t171*_t2*_t510 - 0.1e1 / 0.2e1*_hc1[4]*_t510*_t94 + (0.1e1 / 0.2e1)*_t1048 + (0.1e1 / 0.6e1)*_t1050 + (0.1e1 / 0.16e2)*_t1052*_t3 + (0.1e1 / 0.48e2)*_t1054*_t3;
  const double _t1058 = _hc0[14]*_t1056 - _hc0[36]*_t1057 + _t520*_t916;
  const double _t1059 = _hc0[3]*_t1047;
  const double _t1060 = 0.2e1*_t418;
  const double _t1061 = _hc0[11]*_t1056 - _hc0[30]*_t1057 + _t520*_t920;
  const double _t1062 = -0.1e1 / 0.2e1*_hc0[11]*_t510*_t94 + (0.1e1 / 0.2e1)*_t1059 + _t1060*_t977 + _t1061*_t27 + _t28*(_hc0[18]*_t1056 - _hc0[46]*_t1057 + _t520*_t921);
  const double _t1063 = 0.3e1*_t154;
  const double _t1064 = _t109*_t424;
  const double _t1065 = _t511*_t514;
  const double _t1066 = _hc1[10]*_t140*_t46;
  const double _t1067 = _t1066*_t30;
  const double _t1068 = _t128*_t414;
  const double _t1069 = _t129*_t421;
  const double _t1070 = _t109*_t426;
  const double _t1071 = _t504*_t932;
  const double _t1072 = _t512*_t99;
  const double _t1073 = _t171*_t507;
  const double _t1074 = _t154*_t328;
  const double _t1075 = _t171*_t475;
  const double _t1076 = -_t1045*_t509 + _t1056*_t37 - 0.3e1 / 0.8e1*_t1072 + (0.1e1 / 0.8e1)*_t1073 + (0.3e1 / 0.2e1)*_t1074 + _t1075*_t514 + _t522;
  const double _t1077 = _t1063*_t855 - 0.3e1 / 0.4e1*_t1064 - _t1065*_t30 + (0.1e1 / 0.8e1)*_t1067 + (0.3e1 / 0.2e1)*_t1068 + (0.3e1 / 0.2e1)*_t1069 + (0.3e1 / 0.4e1)*_t1070 + (0.3e1 / 0.8e1)*_t1071 + _t1076 + _t168*_t521 + _t249*((0.1e1 / 0.8e1)*_hc1[21]*_t140*_t171*_t18 + (0.3e1 / 0.8e1)*_hc1[5]*_t11*_t18*_t503 - 0.3e1 / 0.8e1*_t1046 - _t1055) + _t263*(_t1058*_t18 - _t1062);
  const double _t1079 = _hc0[14]*_t1078;
  const double _t1081 = -_hc0[36]*_t1080 + _t1079 + _t520*_t941;
  const double _t1082 = _hc0[11]*_t1078;
  const double _t1083 = -_hc0[30]*_t1080 + _t1082 + _t520*_t946;
  const double _t1084 = _hc0[18]*_t1078;
  const double _t1085 = _t1059 + _t335*_t418;
  const double _t1086 = -_hc0[11]*_t510*_t94 + _t1083*_t27 + _t1085 + _t28*(-_hc0[46]*_t1080 + _t1084 + _t520*_t947) + _t335*_t437;
  const double _t1087 = _t160*_t855;
  const double _t1088 = _t129*_t440;
  const double _t1089 = _t160*_t328;
  const double _t1091 = _hc1[4]*_t1075;
  const double _t1092 = _t1074 + _t1078*_t37 - _t1090*_t146 + (0.3e1 / 0.4e1)*_t1091 + _t507*_t543;
  const double _t1093 = -0.3e1 / 0.4e1*_t1072 + _t1089 + _t1092 + _t527;
  const double _t1095 = -0.1e1 / 0.8e1*_hc1[14]*_t1*_t171*_t2*_t510 - _hc1[4]*_t510*_t94 + _t1048 + (0.1e1 / 0.3e1)*_t1050 + _t1052*_t1094 + _t1054*_t412;
  const double _t1096 = _t128*_t451;
  const double _t1097 = _t511*_t931;
  const double _t1098 = _t126*_t424;
  const double _t1099 = _t126*_t426;
  const double _t1100 = -_t1064 + _t1070;
  const double _t1101 = (0.1e1 / 0.4e1)*_t1067 + _t1068 + _t1069 + (0.3e1 / 0.4e1)*_t1071 + _t1096 - 0.3e1 / 0.4e1*_t1097 - 0.1e1 / 0.4e1*_t1098 + (0.1e1 / 0.4e1)*_t1099 + _t1100 + _t154*_t874 + _t249*((0.1e1 / 0.4e1)*_hc1[21]*_t140*_t171*_t18 + (0.3e1 / 0.4e1)*_hc1[5]*_t11*_t18*_t503 - _t1090*_t904 - _t1095);
  const double _t1105 = _hc0[14]*_t1102 - _hc0[36]*_t1103 + _hc0[80]*_t1104;
  const double _t1106 = 0.2e1*_t1059;
  const double _t1107 = _t407*_t534;
  const double _t1108 = _hc0[11]*_t1102 - _hc0[30]*_t1103 + _hc0[70]*_t1104;
  const double _t1109 = -0.8e1 / 0.3e1*_hc0[11]*_t510*_t94 + _t1106 + (0.2e1 / 0.3e1)*_t1107 + _t1108*_t27 + _t28*(_hc0[100]*_t1104 + _hc0[18]*_t1102 - _hc0[46]*_t1103) + _t437*_t978;
  const double _t1110 = 0.2e1*_t160;
  const double _t1111 = _t104*_t466;
  const double _t1112 = _t535*_t539;
  const double _t1113 = -_t104*_t468;
  const double _t1114 = _t1111 + _t1112 + _t1113;
  const double _t1115 = (0.3e1 / 0.2e1)*_t1091 + _t1102*_t37 - _t1103*_t146 + _t507*_t535;
  const double _t1116 = -0.2e1*_t1072 + 0.2e1*_t1089 + _t1115 + _t538;
  const double _t1117 = _t1051*_t3;
  const double _t1118 = -0.1e1 / 0.4e1*_hc1[14]*_t1*_t171*_t2*_t510 - 0.2e1*_hc1[4]*_t510*_t94 + 0.2e1*_t1048 + (0.2e1 / 0.3e1)*_t1050 + _t1054*_t448 + _t1117*_t151;
  const double _t1119 = (0.1e1 / 0.2e1)*_t1067 + (0.3e1 / 0.2e1)*_t1071 + 0.2e1*_t1096 - 0.3e1 / 0.2e1*_t1097 - _t1098 + _t1099 + _t1100 + _t111*_t458 + _t112*_t464 + _t249*((0.1e1 / 0.2e1)*_hc1[21]*_t140*_t171*_t18 + (0.3e1 / 0.2e1)*_hc1[5]*_t11*_t18*_t503 - _t1103*_t904 - _t1118);
  const double _t1121 = -_hc0[36]*_t1090 + _hc0[80]*_t1120 + _t1079;
  const double _t1122 = -_hc0[30]*_t1090 + _hc0[70]*_t1120 + _t1082;
  const double _t1123 = -0.4e1 / 0.3e1*_hc0[11]*_t510*_t94 + _t1085 + (0.1e1 / 0.3e1)*_t1107 + _t1122*_t27 + _t28*(_hc0[100]*_t1120 - _hc0[46]*_t1090 + _t1084) + _t292*_t437;
  const double _t1124 = _t1092 + _t1101;
  const double _t1125 = -_t1072 + (0.1e1 / 0.2e1)*_t1089 + _t539*_t543 + _t545;
  const double _t1126 = -0.1e1 / 0.2e1*_hc1[14]*_t1*_t171*_t2*_t510 - 0.4e1*_hc1[4]*_t510*_t94 + 0.4e1*_t1048 + (0.4e1 / 0.3e1)*_t1050 + _t1054*_t456 + _t1117*_t157;
  const double _t1128 = _hc0[70]*_t1049;
  const double _t1129 = _hc0[18]*_t503;
  const double _t1130 = _t1129*_t3;
  const double _t1131 = _hc0[100]*_t1053;
  const double _t1132 = -0.4e1*_hc0[11]*_t510*_t94 - 0.1e1 / 0.2e1*_hc0[46]*_t1*_t171*_t2*_t510 + 0.4e1*_t1059 + (0.4e1 / 0.3e1)*_t1128 + _t1130*_t157 + _t1131*_t456;
  const double _t1133 = _t46*_t534;
  const double _t1134 = _t1133*_t25;
  const double _t1135 = 0.3e1*_t25;
  const double _t1136 = _t122*_t468;
  const double _t1137 = _t122*_t466;
  const double _t1138 = _hc0[3]*_t504;
  const double _t1139 = 0.3e1*_t128;
  const double _t1140 = 0.3e1*_t129;
  const double _t1142 = _t171*_t539;
  const double _t1143 = -0.6e1*_t1072 + _t1073 + 0.3e1*_t1091 - _t1127*_t146 + _t1141*_t37 + _t1141*_t40 + 0.3e1*_t1142 + _t171*_t546 - _t532*_t548;
  const double _t1144 = -0.2e1*_hc0[11]*_t510*_t94 - 0.1e1 / 0.4e1*_hc0[46]*_t1*_t171*_t2*_t510 + _t1106 + (0.2e1 / 0.3e1)*_t1128 + _t1130*_t151 + _t1131*_t448;
  const double _t1145 = _t129*_t473;
  const double _t1146 = (0.3e1 / 0.2e1)*_t25;
  const double _t1147 = -_hc1[0]*_t533 + _hc1[0]*_t536 - 0.3e1*_t1072 + _t1102*_t40 + _t1115 + (0.3e1 / 0.2e1)*_t1142;
  const double _t1148 = -0.2e1 / 0.3e1*_hc0[11]*_t510*_t94 - 0.1e1 / 0.12e2*_hc0[46]*_t1*_t171*_t2*_t510 + _t1085 + _t1094*_t1129*_t99 + _t118*_t920 + _t120*_t921;
  const double _t1149 = _t418*_t42;
  const double _t1150 = (0.1e1 / 0.2e1)*_t549;
  const double _t1151 = (0.3e1 / 0.4e1)*_t1138;
  const double _t1152 = -_hc1[0]*_t524 - 0.5e1 / 0.4e1*_t1072 + _t1078*_t40 + _t113*_t552;
  const double _t1153 = _t133*_t424;
  const double _t1154 = _t1066*_t35;
  const double _t1155 = _t128*_t479;
  const double _t1156 = _t129*_t481;
  const double _t1157 = _t133*_t426;
  const double _t1158 = _t1008*_t504;
  const double _t1159 = _t1063*_t884 - _t1065*_t35 + _t1076 - 0.3e1 / 0.4e1*_t1153 + (0.1e1 / 0.8e1)*_t1154 + (0.3e1 / 0.2e1)*_t1155 + (0.3e1 / 0.2e1)*_t1156 + (0.3e1 / 0.4e1)*_t1157 + (0.3e1 / 0.8e1)*_t1158 + _t249*((0.1e1 / 0.8e1)*_hc1[21]*_t140*_t171*_t32 + (0.3e1 / 0.8e1)*_hc1[5]*_t11*_t32*_t503 - 0.3e1 / 0.8e1*_t1000*_t1045 - _t1055) + _t263*(_t1058*_t32 - _t1062) + _t264*_t521;
  const double _t1160 = _t160*_t884;
  const double _t1161 = _t129*_t488;
  const double _t1162 = _t128*_t491;
  const double _t1163 = _t1010*_t511;
  const double _t1164 = _t138*_t424;
  const double _t1165 = _t138*_t426;
  const double _t1166 = -_t1153 + _t1157;
  const double _t1167 = (0.1e1 / 0.4e1)*_t1154 + _t1155 + _t1156 + (0.3e1 / 0.4e1)*_t1158 + _t1162 - 0.3e1 / 0.4e1*_t1163 - 0.1e1 / 0.4e1*_t1164 + (0.1e1 / 0.4e1)*_t1165 + _t1166 + _t154*_t893 + _t249*((0.1e1 / 0.4e1)*_hc1[21]*_t140*_t171*_t32 + (0.3e1 / 0.4e1)*_hc1[5]*_t11*_t32*_t503 - _t1000*_t1090 - _t1095);
  const double _t1168 = _t131*_t466;
  const double _t1169 = -_t131*_t468;
  const double _t1170 = _t1112 + _t1168 + _t1169;
  const double _t1171 = _t111*_t494 + _t112*_t497 + (0.1e1 / 0.2e1)*_t1154 + (0.3e1 / 0.2e1)*_t1158 + 0.2e1*_t1162 - 0.3e1 / 0.2e1*_t1163 - _t1164 + _t1165 + _t1166 + _t249*((0.1e1 / 0.2e1)*_hc1[21]*_t140*_t171*_t32 + (0.3e1 / 0.2e1)*_hc1[5]*_t11*_t32*_t503 - _t1000*_t1103 - _t1118);
  const double _t1172 = _t1092 + _t1167;
  const double _t1173 = _t1133*_t33;
  const double _t1174 = 0.3e1*_t33;
  const double _t1175 = _t136*_t468;
  const double _t1176 = _t136*_t466;
  const double _t1177 = _t129*_t501;
  const double _t1178 = (0.3e1 / 0.2e1)*_t33;
  const double _t1180 = _hc0[11]*_t1179;
  const double _t1181 = _t1180*_t99;
  const double _t1184 = _hc0[3]*_t11;
  const double _t1185 = _t129*_t521;
  const double _t1186 = _t37*_t5;
  const double _t1187 = (0.3e1 / 0.4e1)*_hc1[4];
  const double _t1189 = _hc0[3]*_t1188;
  const double _t1190 = _t1188*_t506;
  const double _t1192 = _hc0[3]*_hc1[10]*_t1191;
  const double _t1193 = _hc0[0]*_hc1[20]*_t1191;
  const double _t1195 = _t1194*_t148;
  const double _t1196 = _t1194*_t146;
  const double _t1197 = _t154*_t424;
  const double _t1198 = _t154*_t426;
  const double _t1199 = -0.3e1 / 0.2e1*_t1197 + (0.3e1 / 0.2e1)*_t1198;
  const double _t1200 = -_t1183*_t1186 + 0.2e1*_t1185 - _t1187*_t1189 - 0.3e1 / 0.8e1*_t1190 + (0.1e1 / 0.4e1)*_t1192 + (0.1e1 / 0.16e2)*_t1193 + (0.3e1 / 0.4e1)*_t1195 + (0.15e2 / 0.16e2)*_t1196 + _t1199 + _t263*(_t1061*_t520 + (0.9e1 / 0.16e2)*_t1181 - _t1183*_t1184 - 0.3e1 / 0.4e1*_t152*_t418);
  const double _t1201 = _t152*_t437;
  const double _t1202 = _t1182*_t1184;
  const double _t1203 = (0.15e2 / 0.8e1)*_t1202 + _t418*_t433;
  const double _t1204 = _hc1[4]*_t1189;
  const double _t1205 = _t160*_t424;
  const double _t1206 = _t160*_t426;
  const double _t1207 = _t1182*_t1186;
  const double _t1208 = _t1185 - 0.3e1 / 0.4e1*_t1190 + (0.1e1 / 0.2e1)*_t1192 + (0.1e1 / 0.8e1)*_t1193 + (0.15e2 / 0.8e1)*_t1196 + _t1199 - 0.15e2 / 0.8e1*_t1207;
  const double _t1209 = (0.15e2 / 0.4e1)*_t1202;
  const double _t1210 = _hc0[30]*_t503;
  const double _t1211 = _t129*_t537;
  const double _t1212 = (0.1e1 / 0.4e1)*_hc1[1];
  const double _t1213 = _hc0[11]*_t1188;
  const double _t1214 = _t199*_t517;
  const double _t1215 = _hc1[4]*_t1214;
  const double _t1216 = (0.1e1 / 0.4e1)*_t1215;
  const double _t1217 = -0.3e1 / 0.2e1*_t1190 + _t1192 + (0.1e1 / 0.4e1)*_t1193 + (0.15e2 / 0.4e1)*_t1196 - _t1197 + _t1198 - 0.15e2 / 0.4e1*_t1207;
  const double _t1218 = _t1210*_t171;
  const double _t1219 = _hc1[1]*_t1213;
  const double _t1220 = _t129*_t544;
  const double _t1221 = _t1208 + _t1220;
  const double _t1222 = (0.1e1 / 0.2e1)*_hc0[70];
  const double _t1224 = _hc0[30]*_t1191;
  const double _t1225 = (0.1e1 / 0.2e1)*_hc1[1];
  const double _t1226 = _t1224*_t1225;
  const double _t1227 = -0.3e1*_t1190 + 0.2e1*_t1192 + (0.1e1 / 0.2e1)*_t1193 + (0.15e2 / 0.2e1)*_t1196 - 0.15e2 / 0.2e1*_t1207;
  const double _t1228 = _t145*_t418;
  const double _t1229 = _hc1[0]*_t1191;
  const double _t1230 = _hc1[0]*_t1180*_t144;
  const double _t1231 = _t1182*_t40*_t5;
  const double _t1232 = _hc1[0]*_t1210;
  const double _t1233 = _hc1[1]*_t1224;
  const double _t1234 = _t1232*_t46;
  const double _t1235 = _t141*_t552;
  const double d4F_dna4 = 0.4e1*_t166*_t205 + 0.4e1*_t168*_t233 + 0.4e1*_t206 + 0.4e1*_t234 + _t249*(_hc1[2]*_t558 + _t18*(_hc1[6]*_t174 + _t176*_t183 + _t178*_t222 + _t18*(_hc1[13]*_t49 + _t18*(_hc1[24]*_t18 - _t559) - _t27*_t561 - _t28*_t563 + _t564) + _t180*_t227 - _t27*_t571 - _t28*_t575 + _t578) + _t182*_t579 + _t190*_t595 - _t191*_t581 + _t196*_t601 - _t197*_t304 - _t27*(_hc1[5]*_t174 + _t178*_t183 + _t18*_t571 + _t186*_t222 + _t188*_t227 - _t27*(_t18*_t567 - _t27*(_hc1[21]*_t18 - _t583) - _t28*_t585 + _t582 + _t586) - _t28*_t591 + _t594) - _t28*(_hc1[8]*_t174 + _t18*_t575 + _t180*_t183 + _t188*_t222 + _t194*_t227 - _t27*_t591 - _t28*(_hc1[18]*_t49 + _t18*_t573 - _t27*_t589 - _t28*(_hc1[33]*_t18 - _t596) + _t597) + _t600) + _t51*_t580 + _t605) + _t263*(_hc0[4]*_t558 + _t18*(_hc0[15]*_t174 + _t18*(_hc0[40]*_t49 + _t18*(_hc0[90]*_t18 - _t606) - _t27*_t608 - _t28*_t610 + _t611) + _t183*_t208 + _t210*_t222 + _t212*_t227 - _t27*_t618 - _t28*_t622 + _t625) + _t214*_t579 + _t221*_t595 + _t226*_t601 - _t27*(_hc0[14]*_t174 + _t18*_t618 + _t183*_t210 + _t217*_t222 + _t219*_t227 - _t27*(_t18*_t614 - _t27*(_hc0[80]*_t18 - _t628) - _t28*_t630 + _t627 + _t631) - _t28*_t636 + _t639) - _t28*(_hc0[19]*_t174 + _t18*_t622 + _t183*_t212 + _t219*_t222 + _t224*_t227 - _t27*_t636 - _t28*(_hc0[54]*_t49 + _t18*_t620 - _t27*_t634 - _t28*(_hc0[124]*_t18 - _t641) + _t642) + _t645) - _t304*_t640 + _t580*_t63 - _t581*_t626 + _t646) + 0.12e2*_t553 + 0.12e2*_t554 + 0.6e1*_t555*_t60;
  const double d4F_dna3_dnb = _t167*_t248 + _t169*_t262 + _t205*_t87 + _t206 + _t233*_t264 + _t234 + _t249*(_hc1[2]*_t657 + _t174*_t75 + _t18*(_hc1[6]*_t235 + _t176*_t48 + _t178*_t68 + _t18*(_hc1[13]*_t48 + _t18*_t658 + _t661) + _t180*_t69 + _t236*_t49 + _t237*_t68 + _t238*_t69 - _t27*_t665 - _t28*_t668 + _t578) + _t182*_t48 + _t183*_t240 + _t190*_t68 - _t191*_t670 + _t196*_t69 - _t197*_t677 - _t228*_t76 - _t230*_t77 - _t27*(_t178*_t48 + _t18*_t665 + _t186*_t68 + _t188*_t69 + _t237*_t49 + _t241*_t68 + _t242*_t69 - _t27*(_hc1[11]*_t48 + _t18*_t662 + _t673) - _t28*_t676 + _t594 + _t671) - _t28*(_hc1[8]*_t235 + _t18*_t668 + _t180*_t48 + _t188*_t68 + _t194*_t69 + _t238*_t49 + _t242*_t68 + _t245*_t69 - _t27*_t676 - _t28*(_hc1[18]*_t48 + _t18*_t666 + _t678) + _t600) + _t51*_t669 + _t679) + _t263*(_hc0[4]*_t657 + _t174*_t81 + _t18*(_hc0[15]*_t235 + _t18*(_hc0[40]*_t48 + _t18*_t680 + _t683) + _t208*_t48 + _t210*_t68 + _t212*_t69 + _t250*_t49 + _t251*_t68 + _t252*_t69 - _t27*_t687 - _t28*_t690 + _t625) + _t183*_t254 + _t214*_t48 + _t221*_t68 + _t226*_t69 - _t228*_t82 - _t230*_t83 - _t27*(_t18*_t687 + _t210*_t48 + _t217*_t68 + _t219*_t69 + _t251*_t49 + _t255*_t68 + _t256*_t69 - _t27*(_hc0[36]*_t48 + _t18*_t684 + _t693) - _t28*_t696 + _t639 + _t691) - _t28*(_hc0[19]*_t235 + _t18*_t690 + _t212*_t48 + _t219*_t68 + _t224*_t69 + _t252*_t49 + _t256*_t68 + _t259*_t69 - _t27*_t696 - _t28*(_hc0[54]*_t48 + _t18*_t688 + _t697) + _t645) - _t626*_t670 + _t63*_t669 - _t640*_t677 + _t698) + 0.3e1*_t553 + 0.3e1*_t554 + _t555*_t651 + 0.6e1*_t647 + 0.6e1*_t648 + 0.3e1*_t649 + 0.3e1*_t650 + _t652*_t653 + 0.3e1*_t654 + 0.3e1*_t655;
  const double d4F_dna2_dnb2 = _t248*_t397 + _t249*(-_t173*_t51 + _t18*(-_hc1[6]*_t173 - _hc1[6]*_t47 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t238 + (0.56e2 / 0.9e1)*_t13*_t237*_t56 + _t18*_t712 + 0.4e1*_t236*_t46*_t8 - _t576 - _t577 - _t708 - _t711) - _t191*_t200 - _t197*_t202 + _t240*_t713 + _t269*_t69 - _t27*(-_hc1[5]*_t173 - _hc1[5]*_t47 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t242 + (0.56e2 / 0.9e1)*_t13*_t241*_t56 + _t18*_t710 + 0.4e1*_t237*_t46*_t8 - _t592 - _t593 - _t717 - _t719) + _t272*_t68 + _t274*_t49 - _t28*(-_hc1[8]*_t173 - _hc1[8]*_t47 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t245 + (0.56e2 / 0.9e1)*_t13*_t242*_t56 + _t18*_t707 + 0.4e1*_t238*_t46*_t8 - _t598 - _t599 - _t721 - _t722) - _t47*_t51 + _t669*_t75 + _t679 + _t706 - _t714*_t76 - _t720*_t77) + _t262*_t398 + _t263*(-_t173*_t63 + _t18*(-_hc0[15]*_t173 - _hc0[15]*_t47 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t252 + (0.56e2 / 0.9e1)*_t13*_t251*_t56 + _t18*_t729 + 0.4e1*_t250*_t46*_t8 - _t623 - _t624 - _t725 - _t728) - _t228*_t65 - _t230*_t67 + _t254*_t713 - _t27*(-_hc0[14]*_t173 - _hc0[14]*_t47 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t256 + (0.56e2 / 0.9e1)*_t13*_t255*_t56 + _t18*_t727 + 0.4e1*_t251*_t46*_t8 - _t637 - _t638 - _t732 - _t734) + _t276*_t69 + _t279*_t68 - _t28*(-_hc0[19]*_t173 - _hc0[19]*_t47 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t259 + (0.56e2 / 0.9e1)*_t13*_t256*_t56 + _t18*_t724 + 0.4e1*_t252*_t46*_t8 - _t643 - _t644 - _t735 - _t736) + _t281*_t49 - _t47*_t63 + _t669*_t81 + _t698 - _t714*_t82 - _t720*_t83 + _t723) + _t275*_t324 + _t282*_t325 + _t555*_t90 + 0.4e1*_t647 + 0.4e1*_t648 + 0.2e1*_t649 + 0.2e1*_t650 + _t652*_t92 + 0.2e1*_t654 + 0.2e1*_t655 + 0.4e1*_t699 + 0.4e1*_t700 + 0.2e1*_t701 + 0.2e1*_t702 + 0.4e1*_t703*_t85 + 0.2e1*_t704 + 0.2e1*_t705;
  const double d4F_dna_dnb3 = _t166*_t287 + _t168*_t289 + _t249*(_hc1[2]*_t656 - _t170*_t75 + _t18*_t741 + _t274*_t743 + _t706 - _t742*_t75 + _t746) + _t263*(_hc0[4]*_t656 - _t170*_t81 + _t18*_t747 + _t281*_t743 + _t723 - _t742*_t81 + _t748) + _t275*_t283 + _t282*_t284 + _t288 + _t290 + _t651*_t739 + _t653*_t740 + 0.6e1*_t699 + 0.6e1*_t700 + 0.3e1*_t701 + 0.3e1*_t702 + 0.3e1*_t704 + 0.3e1*_t705 + 0.3e1*_t737 + 0.3e1*_t738;
  const double d4F_dnb4 = _t249*(_hc1[2]*_t749 + _t274*_t751 + _t32*_t741 + _t746 + _t75*_t750) + _t263*(_hc0[4]*_t749 + _t281*_t751 + _t32*_t747 + _t748 + _t750*_t81) + 0.4e1*_t264*_t289 + 0.4e1*_t287*_t87 + 0.4e1*_t288 + 0.4e1*_t290 + 0.12e2*_t737 + 0.12e2*_t738 + 0.6e1*_t740*_t92;
  const double d4F_dna3_dgaa = _t796;
  const double d4F_dna3_dgab = _t122*_t752 + _t122*_t757 + _t126*_t753 + _t126*_t756 + _t128*_t205 + _t129*_t233 + _t167*_t347 + _t169*_t360 + _t249*(_hc1[5]*_t11*_t174*_t38 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t343 + (0.56e2 / 0.9e1)*_t13*_t340*_t56 + _t18*(_t113*_t565 - _t178*_t335 + _t18*(_hc1[23]*_t11*_t18*_t38 - _t797) - _t27*_t799 - _t28*_t801 + _t803) - _t190*_t335 - _t27*(_t113*_t582 + _t18*_t799 - _t186*_t335 - _t27*(_hc1[21]*_t11*_t18*_t38 - _t804) - _t28*_t806 + _t807) - _t28*(_t113*_t587 + _t18*_t801 - _t188*_t335 - _t27*_t806 - _t28*(_hc1[30]*_t11*_t18*_t38 - _t808) + _t809) + 0.2e1*_t337*_t49 + (0.56e2 / 0.9e1)*_t38*_t53*_t56 - _t816) + _t263*(_hc0[14]*_t11*_t174*_t38 + (0.4e1 / 0.9e1)*_t1*_t2*_t20*_t357 + (0.56e2 / 0.9e1)*_t13*_t354*_t56 + _t18*(_t113*_t612 + _t18*(_hc0[89]*_t11*_t18*_t38 - _t817) - _t210*_t335 - _t27*_t819 - _t28*_t821 + _t822) - _t221*_t335 - _t27*(_t113*_t627 + _t18*_t819 - _t217*_t335 - _t27*(_hc0[80]*_t11*_t18*_t38 - _t823) - _t28*_t825 + _t826) - _t28*(_t113*_t632 + _t18*_t821 - _t219*_t335 - _t27*_t825 - _t28*(_hc0[119]*_t11*_t18*_t38 - _t827) + _t828) + 0.2e1*_t351*_t49 + (0.56e2 / 0.9e1)*_t38*_t56*_t65 - _t832) + 0.3e1*_t348 + 0.3e1*_t361 + 0.3e1*_t754 + 0.3e1*_t755;
  const double d4F_dna3_dgbb = _t796;
  const double d4F_dna2_dnb_dgaa = _t859;
  const double d4F_dna2_dnb_dgab = _t122*_t333 + _t126*_t332 + _t126*_t854 + _t128*_t248 + _t129*_t262 + _t136*_t555 + _t138*_t652 + _t249*(_t113*_t671 + _t18*(_t18*_t865 + 0.2e1*_t842 + _t866) - _t244*_t335 - _t27*(_t18*_t863 + 0.2e1*_t839 + _t864) - _t28*(_t18*_t860 + 0.2e1*_t835 + _t862) + _t337*_t48 + _t340*_t68 + _t343*_t69 + _t380*_t49 + _t381*_t68 + _t382*_t69 + _t53*_t802 + _t76*_t802 - _t811 - _t813 - _t815) + _t263*(_t113*_t691 + _t18*(_t18*_t872 + 0.2e1*_t852 + _t873) - _t258*_t335 - _t27*(_t18*_t870 + 0.2e1*_t849 + _t871) - _t28*(_t18*_t867 + 0.2e1*_t845 + _t869) + _t351*_t48 + _t354*_t68 + _t357*_t69 + _t385*_t49 + _t386*_t68 + _t387*_t69 + _t65*_t802 + _t802*_t82 - _t829 - _t830 - _t831) + _t264*_t360 + _t266*_t874 + _t324*_t384 + _t325*_t389 + _t347*_t87 + _t348 + _t361 + _t754 + _t755 + _t875;
  const double d4F_dna2_dnb_dgbb = _t859;
  const double d4F_dna_dnb2_dgaa = _t887;
  const double d4F_dna_dnb2_dgab = _t122*_t739 + _t126*_t740 + _t128*_t275 + _t129*_t282 + _t136*_t400 + _t138*_t854 + _t138*_t88 + _t166*_t401 + _t168*_t403 + _t249*(_t18*_t888 - 0.2e1*_t366 + 0.4e1*_t380*_t46*_t8 - _t877*_t889 - _t890) + _t263*(_t18*_t891 - 0.2e1*_t373 + 0.4e1*_t385*_t46*_t8 - _t882*_t889 - _t892) + _t266*_t893 + _t384*_t397 + _t389*_t398 + _t402 + _t404 + _t875 + _t885 + _t886;
  const double d4F_dna_dnb2_dgbb = _t887;
  const double d4F_dnb3_dgaa = _t898;
  const double d4F_dnb3_dgab = _t128*_t287 + _t129*_t289 + _t136*_t894 + _t136*_t897 + _t138*_t895 + _t138*_t896 + _t249*(_hc1[5]*_t11*_t285*_t38 + _t32*_t888 + 0.2e1*_t380*_t89 - _t890) + _t263*(_hc0[14]*_t11*_t285*_t38 + _t32*_t891 + 0.2e1*_t385*_t89 - _t892) + _t283*_t401 + _t284*_t403 + 0.3e1*_t402 + 0.3e1*_t404 + 0.3e1*_t885 + 0.3e1*_t886;
  const double d4F_dnb3_dgbb = _t898;
  const double d4F_dna2_dgaa2 = _t937;
  const double d4F_dna2_dgaa_dgab = _t160*_t652 + _t263*(_t18*(_t18*_t938 - _t943) - _t27*(_t18*_t941 - _t948) - _t28*(_t18*_t942 - _t953) + _t434*_t49 + _t65*_t950 + _t924 - _t949 + _t956) + _t325*_t440 + 0.2e1*_t441 + 0.2e1*_t442 + _t970;
  const double d4F_dna2_dgaa_dgbb = _t937;
  const double d4F_dna2_dgab2 = 0.4e1*_t126*_t874 - _t153*_t332 + _t249*(_hc1[11]*_t143*_t49*_t99 + (0.4e1 / 0.3e1)*_t140*_t20*_t53 - _t152*_t184 + _t18*(_hc1[22]*_t143*_t18*_t99 - _t152*_t899 - _t975) - _t27*(_hc1[21]*_t143*_t18*_t99 - _t152*_t904 - _t976) - _t28*(_hc1[26]*_t143*_t18*_t99 - _t152*_t907 - _t979) - _t340*_t978 - _t981) + _t263*(-_t152*_t215 + _t18*(_hc0[86]*_t143*_t18*_t99 - _t152*_t982 - _t983) - _t27*(_hc0[80]*_t143*_t18*_t99 - _t152*_t984 - _t985) - _t28*(_hc0[106]*_t143*_t18*_t99 - _t152*_t987 - _t988) - _t354*_t978 + _t443*_t627 + _t65*_t986 + _t990) + _t324*_t458 + _t325*_t464 + _t332*_t971 + _t333*_t967 - _t333*_t968 + _t347*_t469 + _t360*_t470 + 0.2e1*_t459 + 0.2e1*_t465 - _t468*_t60 - _t929 + _t930 + 0.4e1*_t965 + 0.4e1*_t966 + _t972;
  const double d4F_dna2_dgab_dgbb = _t263*((0.1e1 / 0.2e1)*_hc0[36]*_t143*_t49*_t99 + (0.2e1 / 0.3e1)*_t140*_t20*_t65 + _t18*((0.1e1 / 0.2e1)*_hc0[86]*_t143*_t18*_t99 - _t433*_t982 - _t991) - _t215*_t433 - _t27*((0.1e1 / 0.2e1)*_hc0[80]*_t143*_t18*_t99 - _t433*_t984 - _t992) - _t28*((0.1e1 / 0.2e1)*_hc0[106]*_t143*_t18*_t99 - _t433*_t987 - _t993) - _t923 - _t949 - _t994) + _t325*_t473 + 0.2e1*_t474 - _t476*_t60 + _t970 + (0.1e1 / 0.2e1)*_t972 + _t995;
  const double d4F_dna2_dgbb2 = _t937;
  const double d4F_dna_dnb_dgaa2 = _t1015;
  const double d4F_dna_dnb_dgaa_dgab = _t1024 + _t160*_t703 + _t168*_t488 + _t263*(_t1016*_t18 + _t1018 + _t434*_t48) + _t264*_t440 + _t441 + _t442 + _t489 + _t490;
  const double d4F_dna_dnb_dgaa_dgbb = _t1015;
  const double d4F_dna_dnb_dgab2 = -_t1009 + _t1011 + 0.2e1*_t1021 + _t1033*_t126 + _t1034 + _t1035 + _t1036 + _t166*_t494 + _t168*_t497 + _t249*(0.2e1*_hc1[11]*_t143*_t771*_t8 + _t1025*_t18 - _t1026 - 0.2e1*_t999) + _t263*(0.2e1*_hc0[36]*_t143*_t771*_t8 + _t1028*_t18 - 0.2e1*_t1029 + _t1032) + _t264*_t464 + _t328*_t500 + _t384*_t469 + _t389*_t470 + _t458*_t87 + _t459 + _t465 - _t468*_t79 + _t495 + _t498 + _t500*_t874 + 0.2e1*_t965 + 0.2e1*_t966 + _t969 + _t995;
  const double d4F_dna_dnb_dgab_dgbb = _t1024 + (0.1e1 / 0.2e1)*_t1034 + _t158*_t25 + _t158*_t33 - _t159*_t25 - _t159*_t33 + _t168*_t501 + _t263*(_hc0[36]*_t143*_t771*_t8 - _t1029 + _t1037*_t18 - _t1038) + _t264*_t473 + _t474 - _t476*_t79 + _t502;
  const double d4F_dna_dnb_dgbb2 = _t1015;
  const double d4F_dnb2_dgaa2 = _t1042;
  const double d4F_dnb2_dgaa_dgab = _t1043 + _t160*_t740 + _t263*(_t1016*_t32 + _t1018 + _t434*_t89) + _t398*_t488 + 0.2e1*_t489 + 0.2e1*_t490;
  const double d4F_dnb2_dgaa_dgbb = _t1042;
  const double d4F_dnb2_dgab2 = 0.4e1*_t1021 + 0.4e1*_t1022 - _t1039 + _t1040 + _t1044 + 0.4e1*_t138*_t893 - _t153*_t88 + _t249*(_hc1[11]*_t143*_t89*_t99 + _t1025*_t32 - _t1026 - _t152*_t271) + _t263*(_t1028*_t32 + _t1032 - _t152*_t278 + _t443*_t733) + _t397*_t494 + _t398*_t497 + _t400*_t967 - _t400*_t968 + _t401*_t469 + _t403*_t470 - _t468*_t90 + 0.2e1*_t495 + 0.2e1*_t498 + _t88*_t971;
  const double d4F_dnb2_dgab_dgbb = _t1036 + _t1043 + (0.1e1 / 0.2e1)*_t1044 + _t263*((0.1e1 / 0.2e1)*_hc0[36]*_t143*_t89*_t99 + _t1037*_t32 - _t1038 - _t278*_t433) + _t398*_t501 - _t476*_t90 + 0.2e1*_t502;
  const double d4F_dnb2_dgbb2 = _t1042;
  const double d4F_dna_dgaa3 = _t1077;
  const double d4F_dna_dgaa2_dgab = 0.2e1*_t1087 + _t1088 + _t1093 + _t1101 + _t168*_t526 + _t263*(_t1081*_t18 - _t1086);
  const double d4F_dna_dgaa2_dgbb = _t1077;
  const double d4F_dna_dgaa_dgab2 = 0.2e1*_t1088 + _t1110*_t874 + _t1114 + _t1116 + _t1119 + _t168*_t537 + _t263*(_t1105*_t18 - _t1109);
  const double d4F_dna_dgaa_dgab_dgbb = -_t104*_t476 + _t1087 + (0.1e1 / 0.2e1)*_t1111 + _t112*_t440 + _t112*_t473 + _t1124 + _t1125 + _t168*_t544 + _t263*(_t1121*_t18 - _t1123);
  const double d4F_dna_dgaa_dgbb2 = _t1077;
  const double d4F_dna_dgab3 = _t1067 + 0.3e1*_t1071 - 0.3e1*_t1097 - 0.3e1*_t1098 + 0.3e1*_t1099 + _t1134 + _t1135*_t1138 - _t1135*_t549 - 0.3e1*_t1136 + 0.3e1*_t1137 + _t1139*_t458 + _t1140*_t464 + _t1143 + _t249*(_hc1[21]*_t140*_t171*_t18 + 0.3e1*_hc1[5]*_t11*_t18*_t503 - 0.3e1*_t1046 - _t1126) + _t263*(0.3e1*_hc0[14]*_t11*_t18*_t503 + _hc0[80]*_t140*_t171*_t18 - _t1127*_t984 - _t1132);
  const double d4F_dna_dgab2_dgbb = _t1111 + _t1113 + _t1119 + (0.1e1 / 0.2e1)*_t1134 - _t1136 + _t1137 + _t1138*_t1146 + 0.2e1*_t1145 - _t1146*_t549 + _t1147 + _t263*((0.3e1 / 0.2e1)*_hc0[14]*_t11*_t18*_t503 + (0.1e1 / 0.2e1)*_hc0[80]*_t140*_t171*_t18 - _t1103*_t984 - _t1144);
  const double d4F_dna_dgab_dgbb2 = _t1114 + _t1124 + _t1145 + _t1149*_t25 - _t1150*_t25 + _t1151*_t25 + _t1152 + _t263*((0.3e1 / 0.4e1)*_hc0[14]*_t11*_t18*_t503 - _t1080*_t984 + _t11*_t18*_t38*_t916 - _t1148);
  const double d4F_dna_dgbb3 = _t1077;
  const double d4F_dnb_dgaa3 = _t1159;
  const double d4F_dnb_dgaa2_dgab = _t1093 + 0.2e1*_t1160 + _t1161 + _t1167 + _t263*(_t1081*_t32 - _t1086) + _t264*_t526;
  const double d4F_dnb_dgaa2_dgbb = _t1159;
  const double d4F_dnb_dgaa_dgab2 = _t1033*_t160 + _t1116 + 0.2e1*_t1161 + _t1170 + _t1171 + _t263*(_t1105*_t32 - _t1109) + _t264*_t537;
  const double d4F_dnb_dgaa_dgab_dgbb = _t112*_t488 + _t112*_t501 + _t1125 + _t1160 + (0.1e1 / 0.2e1)*_t1168 + _t1172 - _t131*_t476 + _t263*(_t1121*_t32 - _t1123) + _t264*_t544;
  const double d4F_dnb_dgaa_dgbb2 = _t1159;
  const double d4F_dnb_dgab3 = _t1138*_t1174 + _t1139*_t494 + _t1140*_t497 + _t1143 + _t1154 + 0.3e1*_t1158 - 0.3e1*_t1163 - 0.3e1*_t1164 + 0.3e1*_t1165 + _t1173 - _t1174*_t549 - 0.3e1*_t1175 + 0.3e1*_t1176 + _t249*(_hc1[21]*_t140*_t171*_t32 + 0.3e1*_hc1[5]*_t11*_t32*_t503 - _t1000*_t1127 - _t1126) + _t263*(0.3e1*_hc0[14]*_t11*_t32*_t503 + _hc0[80]*_t140*_t171*_t32 - _t1030*_t1127 - _t1132);
  const double d4F_dnb_dgab2_dgbb = _t1138*_t1178 + _t1147 + _t1168 + _t1169 + _t1171 + (0.1e1 / 0.2e1)*_t1173 - _t1175 + _t1176 + 0.2e1*_t1177 - _t1178*_t549 + _t263*((0.3e1 / 0.2e1)*_hc0[14]*_t11*_t32*_t503 + (0.1e1 / 0.2e1)*_hc0[80]*_t140*_t171*_t32 - _t1030*_t1103 - _t1144);
  const double d4F_dnb_dgab_dgbb2 = _t1149*_t33 - _t1150*_t33 + _t1151*_t33 + _t1152 + _t1170 + _t1172 + _t1177 + _t263*((0.3e1 / 0.4e1)*_hc0[14]*_t11*_t32*_t503 - _t1030*_t1080 + _t11*_t32*_t38*_t916 - _t1148);
  const double d4F_dnb_dgbb3 = _t1159;
  const double d4F_dgaa4 = _t1200;
  const double d4F_dgaa3_dgab = (0.3e1 / 0.2e1)*_t1195 - 0.3e1 / 0.2e1*_t1204 - 0.3e1 / 0.4e1*_t1205 + (0.3e1 / 0.4e1)*_t1206 + _t1208 + (0.3e1 / 0.2e1)*_t129*_t526 + _t263*((0.9e1 / 0.8e1)*_hc0[11]*_t1179*_t99 + (0.1e1 / 0.2e1)*_t1083*_t11*_t38 - 0.1e1 / 0.2e1*_t1201 - _t1203);
  const double d4F_dgaa3_dgbb = _t1200;
  const double d4F_dgaa2_dgab2 = -_t1110*_t424 + _t1110*_t426 + (0.13e2 / 0.4e1)*_t1195 - 0.13e2 / 0.4e1*_t1204 + _t1211 - _t1212*_t1213 + _t1216 + _t1217 + _t263*((0.5e1 / 0.2e1)*_hc0[11]*_t1179*_t99 + (0.1e1 / 0.2e1)*_t11*_t1108*_t38 - _t1201 - _t1209 - _t1210*_t543) + _t470*_t526;
  const double d4F_dgaa2_dgab_dgbb = _t112*_t526 + (0.13e2 / 0.8e1)*_t1195 - 0.13e2 / 0.8e1*_t1204 + (0.1e1 / 0.2e1)*_t1206 + (0.1e1 / 0.8e1)*_t1215 - 0.1e1 / 0.8e1*_t1219 + _t1221 - _t160*_t454 + _t263*((0.5e1 / 0.4e1)*_hc0[11]*_t1179*_t99 + (0.1e1 / 0.2e1)*_t11*_t1122*_t38 - 0.1e1 / 0.4e1*_t1201 - _t1203 - 0.1e1 / 0.8e1*_t1218);
  const double d4F_dgaa2_dgbb2 = _t1200;
  const double d4F_dgaa_dgab3 = 0.9e1*_t1195 - 0.15e2 / 0.2e1*_t1204 - 0.3e1*_t1205 + 0.3e1*_t1206 + 0.3e1*_t1211 + (0.3e1 / 0.2e1)*_t1215 - 0.3e1*_t1219 + _t1226 + _t1227 + _t263*((0.15e2 / 0.2e1)*_t1181 - 0.15e2 / 0.2e1*_t1202 - 0.3e1*_t1218 + _t1222*_t1223);
  const double d4F_dgaa_dgab2_dgbb = _t112*_t537 + _t1187*_t1214 + (0.9e1 / 0.2e1)*_t1195 - 0.15e2 / 0.4e1*_t1204 - _t1205 + _t1206 + _t1212*_t1224 + _t1217 - 0.3e1 / 0.2e1*_t1219 + 0.2e1*_t1220 + _t263*((0.1e1 / 0.4e1)*_hc0[70]*_t1223 + (0.15e2 / 0.4e1)*_t1181 - _t1209 - 0.3e1 / 0.2e1*_t1218);
  const double d4F_dgaa_dgab_dgbb2 = (0.17e2 / 0.8e1)*_t1195 - 0.7e1 / 0.4e1*_t1204 - 0.1e1 / 0.4e1*_t1205 + (0.1e1 / 0.4e1)*_t1206 + _t1216 - 0.1e1 / 0.2e1*_t1219 + _t1221 + _t1225*_t1228 + _t263*((0.7e1 / 0.4e1)*_hc0[11]*_t1179*_t99 - _t1203 - _t1210*_t535 + (0.1e1 / 0.2e1)*_t143*_t920*_t99);
  const double d4F_dgaa_dgbb3 = _t1200;
  const double d4F_dgab4 = _hc0[70]*_t1229 + 0.4e1*_t1192 + _t1193 + 0.30e2*_t1195 + 0.15e2*_t1196 - 0.18e2*_t1204 - 0.15e2*_t1207 + 0.6e1*_t1215 - 0.18e2*_t1219 + 0.15e2*_t1230 - 0.15e2*_t1231 - _t1232*_t170 + 0.4e1*_t1233 - _t170*_t503*_t506;
  const double d4F_dgab3_dgbb = 0.15e2*_t1195 - 0.9e1*_t1204 + 0.3e1*_t1215 - 0.9e1*_t1219 + _t1222*_t1229 + _t1227 + (0.15e2 / 0.2e1)*_t1230 - 0.15e2 / 0.2e1*_t1231 + 0.2e1*_t1233 - 0.3e1*_t1234;
  const double d4F_dgab2_dgbb2 = _hc1[0]*_t145*_t920 + _hc1[1]*_t1060*_t145 + (0.29e2 / 0.4e1)*_t1195 - 0.17e2 / 0.4e1*_t1204 + (0.5e1 / 0.4e1)*_t1215 + _t1217 - 0.15e2 / 0.4e1*_t1219 + _t1226 + (0.7e1 / 0.2e1)*_t1230 - 0.15e2 / 0.4e1*_t1231 - _t1234 - _t1235;
  const double d4F_dgab_dgbb3 = _hc1[0]*_t1061*_t42 + (0.3e1 / 0.2e1)*_hc1[1]*_t1228 + 0.3e1*_t1195 - 0.15e2 / 0.8e1*_t1204 + _t1208 + _t1214*_t514 - 0.9e1 / 0.8e1*_t1219 + (0.9e1 / 0.8e1)*_t1230 - 0.15e2 / 0.8e1*_t1231 - 0.3e1 / 0.2e1*_t1235;
  const double d4F_dgbb4 = _t1200;
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