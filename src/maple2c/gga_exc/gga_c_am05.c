/*
  Generated from python/gga_exc/gga_c_am05.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_am05
*/

#ifndef _GGA_C_AM05_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_AM05_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_AM05_HELPER_BODIES
#include "gga_c_am05.c"
#undef _GGA_C_AM05_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_AM05_HELPER_BODIES
#include "gga_c_am05.c"
#undef _GGA_C_AM05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_AM05_HELPER_BODIES
#include "gga_c_am05.c"
#undef _GGA_C_AM05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_AM05_HELPER_BODIES
#include "gga_c_am05.c"
#undef _GGA_C_AM05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_AM05_HELPER_BODIES
#include "gga_c_am05.c"
#undef _GGA_C_AM05_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_am05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_AM05_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(ff_k, _KMAX)(const xc_func_type *p, double s, double *out) {
  const gga_c_am05_params *params = (const gga_c_am05_params *)(p->params);

  const double _t1 = (s * s);
  const double _t2 = _t1*params->alpha;
  const double _t3 = _t2*params->gamma + 0.1e1;
  const double _t4 = _t2 + 0.1e1;
  const double _t5 = (0.1e1 / _t4);
#if _KMAX >= 1
  const double _t6 = 0.2e1*params->alpha;
  const double _t7 = (0.1e1 / (_t4 * _t4));
  const double _t8 = _t3*_t6*_t7;
#endif
#if _KMAX >= 2
  const double _t9 = _t7*params->gamma;
  const double _t10 = ((params->alpha) * (params->alpha));
  const double _t11 = (0.1e1 / (_t4 * _t4 * _t4));
#endif
#if _KMAX >= 3
  const double _t12 = 0.24e2*_t10;
  const double _t13 = _t12*_t9;
  const double _t14 = ((params->alpha) * (params->alpha) * (params->alpha));
  const double _t15 = 0.48e2*_t14*(s * s * s);
  const double _t16 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t17 = _t16*_t3;
#endif
#if _KMAX >= 4
  const double _t18 = (s * s * s * s);
  const double _t19 = ((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha));
#endif

  const double f = _t3*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = _t5*_t6*params->gamma*s - _t8*s;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = 0.8e1*_t1*_t10*_t11*_t3 - 0.8e1*_t1*_t10*_t9 + 0.2e1*_t5*params->alpha*params->gamma - _t8;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = _t11*_t12*_t3*s + _t11*_t15*params->gamma - _t13*s - _t15*_t17;
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = 0.288e3*_t1*_t11*_t14*params->gamma - 0.288e3*_t1*_t14*_t17 + 0.24e2*_t10*_t11*_t3 - _t13 - 0.384e3*_t16*_t18*_t19*params->gamma + 0.384e3*_t18*_t19*_t3/xc_powi(_t4, 5);
  out[4] = d4f_ds4;
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

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_c_am05_params *params = (const gga_c_am05_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
  const double _t6 = xc_powr(na, -4, 3);
  const double _t7 = xc_powr(gaa, 1, 2);
  const double _t8 = xc_powr(0.3e1, 2, 3);
  const double _t9 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t10 = _t8*_t9;
  const double _t11 = _t10*_t7;
  const double _t12 = _t11*_t6;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ff_k, _KMAX)(p, (0.1e1 / 0.6e1)*_t12, _hc1);
  const double zk = _hc0[0]*_hc1[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = (0.1e1 / _t7);
  const double _t16 = (0.1e1 / 0.12e2)*_t15;
  const double _t13 = _hc0[1]*_hc1[0];
  const double _t14 = _hc0[0]*_hc1[1];
  const double _t17 = _t10*_t14;
  const double _t18 = _t1*_t17;
  const double dF_dna = _hc0[0]*_hc1[0] - 0.2e1 / 0.9e1*_t12*_t14 - 0.1e1 / 0.6e1*_t13*_t5;
  const double dF_dgaa = _t16*_t18;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t20 = xc_powr(na, -5, 3);
  const double _t24 = xc_powr(na, -11, 3);
  const double _t25 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t26 = M_CBRT3;
  const double _t30 = xc_powr(na, -8, 3);
  const double _t32 = (0.1e1 / M_PI);
  const double _t33 = M_CBRT2;
  const double _t36 = xc_powr(na, -7, 3);
  const double _t38 = (0.1e1 / 0.18e2)*_t25;
  const double _t43 = (0.1e1 / gaa);
  const double _t44 = xc_powr(gaa, 3, 2);
  const double _t45 = (0.1e1 / _t44);
  const double _t46 = (0.1e1 / 0.24e2)*_t45;
  const double _t19 = (0.1e1 / 0.9e1)*_hc1[0];
  const double _t21 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t22 = xc_powr(0.6e1, 2, 3)*_hc0[2]*_t9;
  const double _t23 = _t21*_t22;
  const double _t27 = _hc0[0]*_hc1[2]*_t26;
  const double _t28 = _t25*_t27;
  const double _t29 = _t24*_t28;
  const double _t31 = _hc1[1]*_t7;
  const double _t34 = _hc0[1]*_t32*_t33;
  const double _t35 = _t31*_t34;
  const double _t37 = _t11*_t14;
  const double _t39 = _t27*_t30;
  const double _t40 = _hc1[1]*_t34;
  const double _t41 = _t20*_t40;
  const double _t42 = _t15*_t17;
  const double d2F_dna2 = -_hc0[1]*_t19*_t4*_t6 + _t20*_t23 + (0.4e1 / 0.27e2)*_t29*gaa + (0.2e1 / 0.9e1)*_t30*_t35 + (0.2e1 / 0.27e2)*_t36*_t37;
  const double d2F_dna_dgaa = -0.1e1 / 0.24e2*_t15*_t41 - _t38*_t39 - 0.1e1 / 0.36e2*_t42*_t6;
  const double d2F_dgaa2 = (0.1e1 / 0.48e2)*_hc0[0]*_hc1[2]*_t20*_t25*_t26*_t43 - _t18*_t46;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t47 = (0.1e1 / (na * na * na));
  const double _t49 = xc_powi(na, -6);
  const double _t51 = (0.1e1 / (M_PI * M_PI));
  const double _t54 = xc_powi(na, -5);
  const double _t55 = (0.1e1 / (M_PI * M_CBRTPI * M_CBRTPI));
  const double _t56 = (0.2e1 / 0.81e2)*_t55;
  const double _t60 = xc_powr(na, -14, 3);
  const double _t62 = (0.1e1 / (na * na * na * na));
  const double _t65 = xc_powr(na, -10, 3);
  const double _t66 = _t55*_t8;
  const double _t70 = _t54*_t7;
  const double _t71 = (0.1e1 / 0.144e3)*_t25;
  const double _t78 = (gaa * gaa);
  const double _t79 = (0.1e1 / _t78);
  const double _t80 = xc_powr(gaa, -5, 2);
  const double _t48 = _hc0[3]*_t32;
  const double _t50 = _hc1[3]*_t44;
  const double _t52 = _hc0[0]*_t51;
  const double _t53 = _t50*_t52;
  const double _t57 = _hc0[1]*_hc1[2];
  const double _t58 = xc_powr(0.18e2, 1, 3)*_t57;
  const double _t59 = _t54*_t56*_t58;
  const double _t61 = _t28*_t60;
  const double _t63 = xc_powr(0.12e2, 1, 3)*_hc0[2];
  const double _t64 = _t62*_t63;
  const double _t67 = _t33*_t57*_t66;
  const double _t68 = _t54*_t67;
  const double _t69 = _hc1[3]*_t52;
  const double _t72 = _hc1[1]*_t15;
  const double _t73 = _t47*_t63;
  const double _t74 = _t62*_t67;
  const double _t75 = _t30*_t40;
  const double _t76 = _t15*_t69;
  const double _t77 = _t47*_t69;
  const double d3F_dna3 = (0.4e1 / 0.27e2)*_hc0[1]*_hc1[0]*_t2*_t3*_t36 - _t21*_t47*_t48 - _t23*_t30 - 0.5e1 / 0.9e1*_t24*_t35 - _t31*_t38*_t64 - 0.14e2 / 0.81e2*_t37*_t65 - 0.8e1 / 0.81e2*_t49*_t53 - _t59*gaa - 0.16e2 / 0.27e2*_t61*gaa - 0.4e1 / 0.81e2*_t68*gaa;
  const double d3F_dna2_dgaa = _t16*_t75 + (0.1e1 / 0.6e1)*_t29 + (0.1e1 / 0.27e2)*_t36*_t42 + (0.1e1 / 0.27e2)*_t69*_t70 + _t71*_t72*_t73 + (0.1e1 / 0.54e2)*_t74;
  const double d3F_dna_dgaa2 = (0.1e1 / 0.72e2)*_hc0[0]*_hc1[1]*_t45*_t6*_t8*_t9 + (0.1e1 / 0.48e2)*_hc0[1]*_hc1[1]*_t20*_t32*_t33*_t45 - _t39*_t43*_t71 - 0.1e1 / 0.288e3*_t43*_t47*_t67 - 0.1e1 / 0.72e2*_t62*_t76;
  const double d3F_dgaa3 = (0.1e1 / 0.16e2)*_t18*_t80 - 0.1e1 / 0.32e2*_t20*_t28*_t79 + (0.1e1 / 0.192e3)*_t45*_t77;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t81 = xc_powr(na, -13, 3);
  const double _t82 = (0.1e1 / 0.216e3)*_t2;
  const double _t83 = _t49*gaa;
  const double _t84 = xc_powr(na, -19, 3);
  const double _t87 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t89 = xc_powr(na, -16, 3);
  const double _t90 = xc_powr(na, -22, 3);
  const double _t85 = xc_powr(0.2e1, 2, 3)*_hc0[2]*_hc1[2]*_t51;
  const double _t86 = _hc1[1]*_t25;
  const double _t88 = _hc0[0]*_hc1[4]*_t8*_t87;
  const double _t91 = _hc0[1]/(M_PI * M_PI * M_CBRTPI);
  const double _t92 = _t2*_t91;
  const double _t93 = _hc1[3]*_t92;
  const double d4F_dna4 = _hc0[3]*_t31*_t56*_t8*_t89 + _hc0[4]*_hc1[0]*_t25*_t81*_t82 + (0.4e1 / 0.81e2)*_hc1[0]*_t22*_t24 - 0.28e2 / 0.81e2*_t13*_t4*_t65 + _t19*_t48*_t62 + (0.700e3 / 0.243e3)*_t28*gaa/xc_powr(na, 17, 3) + (0.164e3 / 0.81e2)*_t35*_t60 + (0.140e3 / 0.243e3)*_t37*_t81 + (0.16e2 / 0.243e3)*_t50*_t90*_t92 + (0.80e2 / 0.81e2)*_t53/xc_powi(na, 7) + (0.2e1 / 0.9e1)*_t55*_t58*_t83 + (0.1e1 / 0.3e1)*_t63*_t70*_t86 + (0.10e2 / 0.27e2)*_t67*_t83 + (0.16e2 / 0.729e3)*_t78*_t88/xc_powr(na, 25, 3) + (0.2e1 / 0.27e2)*_t84*_t85*gaa;
  const double d4F_dna3_dgaa = -0.1e1 / 0.432e3*_hc0[3]*_t66*_t72*_t81 - 0.13e2 / 0.54e2*_t15*_t24*_t40 - 0.5e1 / 0.144e3*_t25*_t64*_t72 - 0.7e1 / 0.81e2*_t42*_t65 - 0.8e1 / 0.27e2*_t49*_t69*_t7 - _t59 - 0.103e3 / 0.162e3*_t61 - 0.31e2 / 0.324e3*_t68 - 0.1e1 / 0.54e2*_t7*_t84*_t93 - 0.1e1 / 0.72e2*_t85*_t89 - 0.2e1 / 0.243e3*_t88*_t90*gaa;
  const double d4F_dna2_dgaa2 = _hc1[3]*_t15*_t82*_t89*_t91 - 0.1e1 / 0.54e2*_t17*_t36*_t45 + (0.1e1 / 0.108e3)*_t29*_t43 + (0.1e1 / 0.144e3)*_t43*_t74 + (0.1e1 / 0.576e3)*_t43*_t81*_t85 - 0.1e1 / 0.288e3*_t45*_t73*_t86 - _t46*_t75 + (0.13e2 / 0.216e3)*_t54*_t76 + (0.1e1 / 0.324e3)*_t84*_t88;
  const double d4F_dna_dgaa3 = (0.1e1 / 0.96e2)*_hc0[0]*_hc1[2]*_t25*_t26*_t30*_t79 + (0.1e1 / 0.192e3)*_hc0[0]*_hc1[3]*_t45*_t51*_t62 + (0.1e1 / 0.192e3)*_hc0[1]*_hc1[2]*_t33*_t47*_t55*_t79*_t8 - 0.1e1 / 0.48e2*_t17*_t6*_t80 - 0.1e1 / 0.32e2*_t41*_t80 - 0.1e1 / 0.864e3*_t43*_t88*_t89 - 0.1e1 / 0.1152e4*_t45*_t81*_t93;
  const double d4F_dgaa4 = (0.5e1 / 0.64e2)*_hc0[0]*_hc1[2]*_t20*_t25*_t26/(gaa * gaa * gaa) + (0.1e1 / 0.2304e4)*_hc0[0]*_hc1[4]*_t79*_t8*_t81*_t87 - 0.5e1 / 0.32e2*_t18/xc_powr(gaa, 7, 2) - 0.1e1 / 0.64e2*_t77*_t80;
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
  const double gbb = sigma[2];

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = xc_powr(gaa, 1, 2);
  const double _t6 = xc_powr(na, -4, 3);
  const double _t7 = xc_powr(0.6e1, 2, 3);
  const double _t8 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t9 = _t7*_t8;
  const double _t10 = (0.1e1 / 0.12e2)*_t9;
  const double _t11 = _t10*_t6;
  const double _t12 = xc_powr(gbb, 1, 2);
  const double _t13 = xc_powr(nb, -4, 3);
  const double _t14 = _t10*_t13;
  const double _t15 = xc_powr(0.6e1, 1, 3);
  const double _t16 = (0.1e1 / (M_CBRTPI));
  const double _t17 = _t15*_t16;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t4, 0.1e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ff_k, _KMAX)(p, _t11*_t5, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -_t4, 0.1e1, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ff_k, _KMAX)(p, _t12*_t14, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t17/xc_powr(_t2, 1, 3), _t4, _hc4);
  const double _t18 = (0.1e1 / 0.2e1)*_hc0[0] + 0.1e1 / 0.2e1;
  const double _t19 = (0.1e1 / 0.2e1)*_hc2[0] + 0.1e1 / 0.2e1;
  const double _t20 = _hc1[0]*_t18 + _hc3[0]*_t19;
  const double _t21 = _hc4[0]*_t20;
  const double zk = _t21;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t23 = (0.1e1 / 0.6e1)/xc_powr(_t2, 4, 3);
  const double _t25 = -_t3;
  const double _t26 = (0.1e1 / (_t2 * _t2));
  const double _t27 = _t1*_t26;
  const double _t28 = _t25 + _t27;
  const double _t29 = -_t28;
  const double _t34 = xc_powr(na, -7, 3);
  const double _t35 = (0.1e1 / 0.9e1)*_t9;
  const double _t36 = _t34*_t35;
  const double _t43 = _t27 + _t3;
  const double _t44 = -_t43;
  const double _t49 = xc_powr(nb, -7, 3);
  const double _t50 = _t35*_t49;
  const double _t54 = (0.1e1 / 0.24e2)*_t9;
  const double _t55 = (0.1e1 / _t5);
  const double _t59 = (0.1e1 / _t12);
  const double _t22 = _hc4[2]*_t17;
  const double _t24 = -_t22*_t23;
  const double _t30 = _hc4[1]*_t29 + _t24;
  const double _t31 = _t20*_t30;
  const double _t32 = _hc1[1]*_t18;
  const double _t33 = _t32*_t5;
  const double _t37 = _hc0[2]*_hc1[0];
  const double _t38 = (0.1e1 / 0.2e1)*_t37;
  const double _t39 = _hc2[2]*_hc3[0];
  const double _t40 = (0.1e1 / 0.2e1)*_t39;
  const double _t41 = _t28*_t40 + _t29*_t38 - _t33*_t36;
  const double _t42 = _hc4[0]*_t41;
  const double _t45 = _hc4[1]*_t44 + _t24;
  const double _t46 = _t20*_t45;
  const double _t47 = _hc3[1]*_t19;
  const double _t48 = _t12*_t47;
  const double _t51 = _t38*_t44 + _t40*_t43 - _t48*_t50;
  const double _t52 = _hc4[0]*_t51;
  const double _t53 = _hc4[0]*_t2;
  const double _t56 = _t32*_t55;
  const double _t57 = _t56*_t6;
  const double _t58 = _t54*_t57;
  const double _t60 = _t47*_t59;
  const double _t61 = _t13*_t60;
  const double _t62 = _t54*_t61;
  const double dF_dna = _t2*_t31 + _t2*_t42 + _t21;
  const double dF_dnb = _t2*_t46 + _t2*_t52 + _t21;
  const double dF_dgaa = _t53*_t58;
  const double dF_dgbb = _t53*_t62;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t65 = xc_powr(_t2, -7, 3);
  const double _t66 = (0.2e1 / 0.9e1)*_t65;
  const double _t68 = 0.2e1*_t26;
  const double _t69 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t70 = 0.2e1*_t69;
  const double _t71 = _t1*_t70;
  const double _t72 = -_t68 + _t71;
  const double _t73 = _t17*_t23;
  const double _t80 = xc_powr(na, -14, 3);
  const double _t81 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t82 = _t15*_t81;
  const double _t86 = xc_powr(na, -10, 3);
  const double _t87 = (0.7e1 / 0.27e2)*_t9;
  const double _t89 = (_t29 * _t29);
  const double _t91 = -_t72;
  const double _t93 = (_t28 * _t28);
  const double _t110 = (0.1e1 / 0.18e2)*_t9;
  const double _t111 = _t110*_t49;
  const double _t114 = _t110*_t34;
  const double _t125 = _t68 + _t71;
  const double _t128 = xc_powr(nb, -14, 3);
  const double _t132 = xc_powr(nb, -10, 3);
  const double _t133 = (_t43 * _t43);
  const double _t134 = -_t125;
  const double _t135 = (_t44 * _t44);
  const double _t148 = (0.1e1 / 0.48e2)*_t9;
  const double _t157 = (0.1e1 / gaa);
  const double _t158 = xc_powr(na, -8, 3);
  const double _t159 = xc_powr(gaa, 3, 2);
  const double _t160 = (0.1e1 / _t159);
  const double _t161 = _t160*_t9;
  const double _t165 = (0.1e1 / gbb);
  const double _t166 = xc_powr(nb, -8, 3);
  const double _t167 = xc_powr(gbb, 3, 2);
  const double _t168 = (0.1e1 / _t167);
  const double _t169 = _t168*_t9;
  const double _t63 = _t30*_t41;
  const double _t64 = 0.2e1*_t63;
  const double _t67 = _t22*_t66;
  const double _t74 = -_hc4[5]*_t73;
  const double _t75 = _hc4[4]*_t29 + _t74;
  const double _t76 = -_hc4[4]*_t73;
  const double _t77 = _hc4[3]*_t29 + _t76;
  const double _t78 = _hc4[1]*_t72 + _t29*_t77 + _t67 - _t73*_t75;
  const double _t79 = _t20*_t78;
  const double _t83 = _hc1[2]*_t82;
  const double _t84 = _t18*_t83;
  const double _t85 = _t80*_t84;
  const double _t88 = (0.1e1 / 0.2e1)*_hc1[0];
  const double _t90 = _hc0[5]*_t89;
  const double _t92 = (0.1e1 / 0.2e1)*_hc3[0];
  const double _t94 = _hc2[5]*_t93;
  const double _t95 = _hc0[2]*_t29;
  const double _t96 = _hc1[1]*_t5;
  const double _t97 = _t95*_t96;
  const double _t98 = _t33*_t86*_t87 - _t36*_t97 + _t38*_t72 + _t40*_t91 + (0.2e1 / 0.27e2)*_t85*gaa + _t88*_t90 + _t92*_t94;
  const double _t99 = _hc4[0]*_t98;
  const double _t100 = _t30*_t51;
  const double _t101 = _t41*_t45;
  const double _t102 = _hc4[3]*_t44 + _t76;
  const double _t103 = _hc4[4]*_t44 + _t74;
  const double _t104 = -_t103*_t73 + _t67;
  const double _t105 = _hc4[1]*_t71 + _t102*_t29 + _t104;
  const double _t106 = _t105*_t20;
  const double _t107 = _t37*_t69;
  const double _t108 = _t39*_t69;
  const double _t109 = _hc2[2]*_t28;
  const double _t112 = _hc3[1]*_t12;
  const double _t113 = _t111*_t112;
  const double _t115 = _hc0[2]*_t44;
  const double _t116 = _t115*_t96;
  const double _t117 = _hc2[5]*_t92;
  const double _t118 = _t117*_t28;
  const double _t119 = _hc0[5]*_t88;
  const double _t120 = _t119*_t29;
  const double _t121 = _t1*_t107 - _t1*_t108 - _t109*_t113 - _t114*_t116 + _t118*_t43 + _t120*_t44;
  const double _t122 = _hc4[0]*_t121;
  const double _t123 = _t2*_t45;
  const double _t124 = 0.2e1*_t123;
  const double _t126 = _hc4[1]*_t125 + _t102*_t44 + _t104;
  const double _t127 = _t126*_t20;
  const double _t129 = _hc3[2]*_t82;
  const double _t130 = _t129*_t19;
  const double _t131 = _t128*_t130;
  const double _t136 = _hc2[2]*_t43;
  const double _t137 = _t112*_t136;
  const double _t138 = _t117*_t133 + _t119*_t135 + _t125*_t38 + (0.2e1 / 0.27e2)*_t131*gbb + _t132*_t48*_t87 + _t134*_t40 - _t137*_t50;
  const double _t139 = _hc4[0]*_t138;
  const double _t140 = _hc4[0]*_t54;
  const double _t141 = _t140*_t57;
  const double _t142 = _t2*_t30;
  const double _t143 = _t83/xc_powr(na, 11, 3);
  const double _t144 = (0.1e1 / 0.48e2)*_hc0[2]*_hc1[1]*_t29*_t55*_t6*_t7*_t8 - _t114*_t56 - 0.1e1 / 0.36e2*_t143*_t18;
  const double _t145 = _hc4[0]*_t144;
  const double _t146 = _t140*_t61;
  const double _t147 = _hc3[1]*_t59;
  const double _t149 = _t13*_t147*_t148;
  const double _t150 = _t109*_t149;
  const double _t151 = _hc1[1]*_t6;
  const double _t152 = _t148*_t151*_t55;
  const double _t153 = _t115*_t152;
  const double _t154 = _t129/xc_powr(nb, 11, 3);
  const double _t155 = (0.1e1 / 0.48e2)*_hc2[2]*_hc3[1]*_t13*_t43*_t59*_t7*_t8 - _t111*_t60 - 0.1e1 / 0.36e2*_t154*_t19;
  const double _t156 = _hc4[0]*_t155;
  const double _t162 = _t161*_t32;
  const double _t163 = _t162*_t6;
  const double _t164 = (0.1e1 / 0.48e2)*_t53;
  const double _t170 = _t169*_t47;
  const double _t171 = _t13*_t170;
  const double d2F_dna2 = _t2*_t64 + _t2*_t79 + _t2*_t99 + 0.2e1*_t31 + 0.2e1*_t42;
  const double d2F_dna_dnb = _t100*_t2 + _t101*_t2 + _t106*_t2 + _t122*_t2 + _t31 + _t42 + _t46 + _t52;
  const double d2F_dnb2 = _t124*_t51 + _t127*_t2 + _t139*_t2 + 0.2e1*_t46 + 0.2e1*_t52;
  const double d2F_dna_dgaa = _t141 + _t142*_t58 + _t145*_t2;
  const double d2F_dna_dgbb = _t142*_t62 + _t146 + _t150*_t53;
  const double d2F_dnb_dgaa = _t123*_t58 + _t141 + _t153*_t53;
  const double d2F_dnb_dgbb = _t123*_t62 + _t146 + _t156*_t2;
  const double d2F_dgaa2 = (0.1e1 / 0.96e2)*_hc1[2]*_hc4[0]*_t15*_t157*_t158*_t18*_t2*_t81 - _t163*_t164;
  const double d2F_dgbb2 = (0.1e1 / 0.96e2)*_hc3[2]*_hc4[0]*_t15*_t165*_t166*_t19*_t2*_t81 - _t164*_t171;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t175 = xc_powi(na, -7);
  const double _t176 = (0.1e1 / (M_PI * M_PI));
  const double _t177 = (0.4e1 / 0.81e2)*_t176;
  const double _t180 = xc_powr(na, -17, 3);
  const double _t182 = xc_powr(na, -13, 3);
  const double _t183 = (0.70e2 / 0.81e2)*_t9;
  const double _t184 = 0.6e1*_t69;
  const double _t185 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t186 = 0.6e1*_t185;
  const double _t187 = _t1*_t186;
  const double _t188 = -_t184 + _t187;
  const double _t189 = -_t188;
  const double _t190 = (_t29 * _t29 * _t29);
  const double _t192 = (_t28 * _t28 * _t28);
  const double _t195 = (0.1e1 / 0.9e1)*gaa;
  const double _t196 = (0.7e1 / 0.18e2)*_t9;
  const double _t197 = _t196*_t86;
  const double _t201 = (0.1e1 / 0.6e1)*_t9;
  const double _t205 = 0.4e1*_t26;
  const double _t206 = 0.4e1*_t1*_t69;
  const double _t207 = -_t205 + _t206;
  const double _t208 = -_t207;
  const double _t211 = xc_powr(_t2, -10, 3);
  const double _t212 = (0.14e2 / 0.27e2)*_t211;
  const double _t216 = (0.4e1 / 0.9e1)*_t65;
  const double _t217 = 0.2e1*_t72;
  const double _t218 = _t17*_t66;
  const double _t231 = _t187 - 0.2e1*_t69;
  const double _t232 = -_t231;
  const double _t233 = _t1*_t69;
  const double _t234 = (0.2e1 / 0.9e1)*_t9;
  const double _t242 = (0.1e1 / 0.27e2)*gaa;
  const double _t243 = (0.7e1 / 0.54e2)*_t9;
  const double _t244 = _t243*_t86;
  const double _t248 = -_t1*_t26;
  const double _t249 = _t248 + _t25;
  const double _t252 = _t29*_t44;
  const double _t268 = 0.2e1*_t2;
  const double _t271 = _t1*_t185;
  const double _t272 = 0.3e1*_t271;
  const double _t280 = (0.1e1 / 0.27e2)*gbb;
  const double _t282 = _t132*_t243;
  const double _t289 = _t248 + _t3;
  const double _t292 = _t28*_t43;
  const double _t304 = xc_powi(nb, -7);
  const double _t307 = xc_powr(nb, -17, 3);
  const double _t309 = xc_powr(nb, -13, 3);
  const double _t310 = (_t43 * _t43 * _t43);
  const double _t311 = _t184 + _t187;
  const double _t312 = -_t311;
  const double _t313 = (_t44 * _t44 * _t44);
  const double _t317 = _t205 + _t206;
  const double _t318 = -_t317;
  const double _t321 = _t17*_t216;
  const double _t327 = xc_powi(na, -6);
  const double _t328 = (0.1e1 / 0.54e2)*_t176;
  const double _t331 = (0.1e1 / 0.36e2)*_t29;
  const double _t344 = _t233*_t54;
  const double _t346 = (0.1e1 / 0.36e2)*_t9;
  const double _t365 = xc_powi(nb, -6);
  const double _t367 = (0.1e1 / 0.36e2)*_t43;
  const double _t371 = _t157*_t158;
  const double _t378 = xc_powi(na, -5);
  const double _t379 = (0.1e1 / 0.144e3)*_t176;
  const double _t380 = _t378*_t379;
  const double _t383 = (0.1e1 / 0.96e2)*_t161;
  const double _t388 = (0.1e1 / 0.96e2)*_t169;
  const double _t394 = _t165*_t166;
  const double _t398 = xc_powi(nb, -5);
  const double _t399 = _t379*_t398;
  const double _t404 = (0.1e1 / (na * na * na * na));
  const double _t405 = _t160*_t404;
  const double _t407 = (0.1e1 / 0.384e3)*_t176;
  const double _t409 = (gaa * gaa);
  const double _t410 = (0.1e1 / _t409);
  const double _t411 = _t158*_t410;
  const double _t414 = xc_powr(gaa, -5, 2);
  const double _t417 = (0.1e1 / 0.32e2)*_t9;
  const double _t419 = (0.1e1 / (nb * nb * nb * nb));
  const double _t420 = _t168*_t419;
  const double _t422 = (gbb * gbb);
  const double _t423 = (0.1e1 / _t422);
  const double _t424 = _t166*_t423;
  const double _t426 = xc_powr(gbb, -5, 2);
  const double _t172 = 0.3e1*_t142;
  const double _t173 = _t41*_t78;
  const double _t174 = 0.3e1*_t173;
  const double _t178 = _hc1[3]*_t18;
  const double _t179 = _t159*_t178;
  const double _t181 = _t180*_t84;
  const double _t191 = _hc0[9]*_t88;
  const double _t193 = _hc2[9]*_t92;
  const double _t194 = _t80*_t83;
  const double _t198 = _hc1[1]*_t34;
  const double _t199 = _t198*_t72;
  const double _t200 = _hc0[2]*_t5;
  const double _t202 = _t200*_t201;
  const double _t203 = _t198*_t5;
  const double _t204 = _t201*_t203;
  const double _t209 = _t118*_t208 + _t118*_t91 + _t120*_t207 + _t120*_t72 - _t175*_t177*_t179 - 0.14e2 / 0.27e2*_t181*gaa - _t182*_t183*_t33 + _t188*_t40 + _t189*_t38 + _t190*_t191 + _t192*_t193 + _t194*_t195*_t95 + _t197*_t97 - _t199*_t202 - _t204*_t90;
  const double _t210 = _hc4[0]*_t209;
  const double _t213 = _t212*_t22;
  const double _t214 = -_t213;
  const double _t215 = _t17*_t75;
  const double _t219 = _hc4[5]*_t218;
  const double _t220 = -_hc4[9]*_t73;
  const double _t221 = _hc4[8]*_t29 + _t220;
  const double _t222 = -_hc4[8]*_t73;
  const double _t223 = _hc4[7]*_t29 + _t222;
  const double _t224 = _hc4[4]*_t72 + _t219 - _t221*_t73 + _t223*_t29;
  const double _t225 = _hc4[4]*_t218;
  const double _t226 = -_hc4[7]*_t73;
  const double _t227 = _hc4[6]*_t29 + _t226;
  const double _t228 = _hc4[3]*_t72 - _t223*_t73 + _t225 + _t227*_t29;
  const double _t229 = _hc4[1]*_t189 + _t214 + _t215*_t216 + _t217*_t77 - _t224*_t73 + _t228*_t29;
  const double _t230 = _t20*_t229;
  const double _t235 = _t198*_t200;
  const double _t236 = _t234*_t235;
  const double _t237 = _hc0[5]*_hc1[0];
  const double _t238 = _t237*_t29;
  const double _t239 = _hc2[5]*_hc3[0];
  const double _t240 = _t239*_t28;
  const double _t241 = _t115*_t194;
  const double _t245 = _hc2[2]*_t91;
  const double _t246 = _t117*_t43;
  const double _t247 = _t193*_t93;
  const double _t250 = _t191*_t89;
  const double _t251 = _t119*_t44;
  const double _t253 = _hc0[5]*_t252;
  const double _t254 = _t253*_t96;
  const double _t255 = -_t113*_t245 - _t113*_t94 + _t116*_t244 + _t231*_t40 + _t232*_t38 - _t233*_t236 + _t238*_t71 - _t240*_t71 + _t241*_t242 + _t246*_t91 + _t247*_t43 + _t249*_t250 + _t251*_t72 - _t254*_t36;
  const double _t256 = _hc4[7]*_t44 + _t222;
  const double _t257 = _hc4[8]*_t44 + _t220;
  const double _t258 = _t219 - _t257*_t73;
  const double _t259 = _hc4[4]*_t71 + _t256*_t29 + _t258;
  const double _t260 = _hc4[6]*_t44 + _t226;
  const double _t261 = _t225 - _t256*_t73;
  const double _t262 = _hc4[3]*_t71 + _t260*_t29 + _t261;
  const double _t263 = _hc4[1]*_t232 + _t102*_t72 + _t103*_t218 + _t214 + _t218*_t75 - _t259*_t73 + _t262*_t29 + _t71*_t77;
  const double _t264 = _t2*_t20;
  const double _t265 = _t51*_t78;
  const double _t266 = 0.2e1*_t142;
  const double _t267 = _t105*_t41;
  const double _t269 = 0.2e1*_t100 + 0.2e1*_t101 + 0.2e1*_t106 + 0.2e1*_t122;
  const double _t270 = _t45*_t51;
  const double _t273 = _hc3[1]*_t49;
  const double _t274 = _t12*_t273;
  const double _t275 = _hc2[2]*_t274;
  const double _t276 = _t234*_t275;
  const double _t277 = _t239*_t43;
  const double _t278 = _t128*_t129;
  const double _t279 = _t109*_t278;
  const double _t281 = _t237*_t44;
  const double _t283 = _t112*_t282;
  const double _t284 = _hc1[1]*_t114;
  const double _t285 = _t125*_t200;
  const double _t286 = _hc0[5]*_t135;
  const double _t287 = _t286*_t96;
  const double _t288 = _t133*_t193;
  const double _t290 = _t135*_t191;
  const double _t291 = _t112*_t50;
  const double _t293 = _hc2[5]*_t292;
  const double _t294 = -_t107 + _t108 + _t109*_t283 - _t114*_t287 + _t118*_t134 + _t120*_t125 + _t233*_t276 - _t272*_t37 + _t272*_t39 - _t277*_t71 + _t279*_t280 + _t28*_t288 + _t281*_t71 - _t284*_t285 + _t289*_t290 - _t291*_t293;
  const double _t295 = _hc4[4]*_t125 + _t256*_t44 + _t258;
  const double _t296 = _t295*_t73;
  const double _t297 = _hc4[3]*_t125 + _t260*_t44 + _t261;
  const double _t298 = -_hc4[1]*_t187 - _hc4[1]*_t70 + 0.4e1*_t1*_t102*_t69 + (0.4e1 / 0.9e1)*_t103*_t15*_t16*_t65 - _t213 + _t29*_t297 - _t296;
  const double _t299 = _t126*_t41;
  const double _t300 = _t2*_t51;
  const double _t301 = 0.2e1*_t300;
  const double _t302 = 0.3e1*_t123;
  const double _t303 = 0.3e1*_t300;
  const double _t305 = _hc3[3]*_t19;
  const double _t306 = _t167*_t305;
  const double _t308 = _t130*_t307;
  const double _t314 = _hc2[5]*_t133;
  const double _t315 = _t201*_t274;
  const double _t316 = _hc2[2]*_t134;
  const double _t319 = _t125*_t251 + _t132*_t137*_t196 + _t134*_t246 + (0.1e1 / 0.9e1)*_t136*_t278*gbb - _t177*_t304*_t306 - _t183*_t309*_t48 + _t191*_t313 + _t193*_t310 + _t246*_t318 + _t251*_t317 - 0.14e2 / 0.27e2*_t308*gbb + _t311*_t40 + _t312*_t38 - _t314*_t315 - _t315*_t316;
  const double _t320 = _hc4[0]*_t319;
  const double _t322 = 0.2e1*_t102;
  const double _t323 = _hc4[1]*_t312 + _t103*_t321 + _t125*_t322 + _t214 - _t296 + _t297*_t44;
  const double _t324 = _t20*_t323;
  const double _t325 = _t11*_t56;
  const double _t326 = _t2*_t78;
  const double _t329 = _t178*_t5;
  const double _t330 = _hc0[2]*_t143;
  const double _t332 = _hc0[2]*_t72;
  const double _t333 = _t152*_t332 + _t152*_t90 + _t244*_t56 - _t284*_t55*_t95 + _t327*_t328*_t329 - _t330*_t331 + (0.5e1 / 0.36e2)*_t85;
  const double _t334 = _hc4[0]*_t333;
  const double _t335 = _t13*_t147;
  const double _t336 = _t109*_t335;
  const double _t337 = _t14*_t60;
  const double _t338 = _t336*_t54;
  const double _t339 = _t149*_t245 + _t149*_t94;
  const double _t340 = _hc4[0]*_t339;
  const double _t341 = _hc4[0]*_t115;
  const double _t342 = _hc0[2]*_t55;
  const double _t343 = _t151*_t342;
  const double _t345 = (0.1e1 / 0.72e2)*_t330;
  const double _t347 = _t198*_t55;
  const double _t348 = _t346*_t347;
  const double _t349 = -_t115*_t348 + _t152*_t253 + _t343*_t344 - _t345*_t44;
  const double _t350 = _t105*_t2;
  const double _t351 = _hc2[2]*_t335;
  const double _t352 = _hc2[2]*_t154;
  const double _t353 = (0.1e1 / 0.72e2)*_t352;
  const double _t354 = _t273*_t59;
  const double _t355 = _t346*_t354;
  const double _t356 = (0.1e1 / 0.48e2)*_hc2[5]*_hc3[1]*_t13*_t28*_t43*_t59*_t7*_t8 - _t109*_t355 - _t28*_t353 - _t344*_t351;
  const double _t357 = _t115*_t55;
  const double _t358 = _t151*_t357;
  const double _t359 = _t358*_t54;
  const double _t360 = _hc0[2]*_t125;
  const double _t361 = _t152*_t286 + _t152*_t360;
  const double _t362 = _hc4[0]*_t361;
  const double _t363 = _t126*_t2;
  const double _t364 = 0.2e1*_t155;
  const double _t366 = _t12*_t305;
  const double _t368 = -_t111*_t136*_t147 + (0.5e1 / 0.36e2)*_t131 + _t149*_t314 + _t149*_t316 + _t282*_t60 + _t328*_t365*_t366 - _t352*_t367;
  const double _t369 = _hc4[0]*_t368;
  const double _t370 = (0.1e1 / 0.96e2)*_hc4[0];
  const double _t372 = _t371*_t84;
  const double _t373 = (0.1e1 / 0.48e2)*_hc4[0];
  const double _t374 = _t163*_t373;
  const double _t375 = (0.1e1 / 0.96e2)*_t372;
  const double _t376 = (0.1e1 / 0.48e2)*_t142;
  const double _t377 = _t178*_t55;
  const double _t381 = (0.1e1 / 0.72e2)*_t143;
  const double _t382 = _t151*_t95;
  const double _t384 = (0.1e1 / 0.192e3)*_hc0[2]*_hc1[2]*_t15*_t157*_t158*_t29*_t81 + (0.1e1 / 0.36e2)*_hc1[1]*_t160*_t18*_t34*_t7*_t8 - _t157*_t18*_t381 - _t377*_t380 - _t382*_t383;
  const double _t385 = _hc4[0]*_t384;
  const double _t386 = _t171*_t373;
  const double _t387 = _hc3[1]*_t13;
  const double _t389 = _t387*_t388;
  const double _t390 = _t109*_t389;
  const double _t391 = _t151*_t383;
  const double _t392 = _t115*_t391;
  const double _t393 = (0.1e1 / 0.48e2)*_t123;
  const double _t395 = _t130*_t394;
  const double _t396 = (0.1e1 / 0.96e2)*_t395;
  const double _t397 = _t305*_t59;
  const double _t400 = (0.1e1 / 0.72e2)*_t154;
  const double _t401 = _t136*_t387;
  const double _t402 = (0.1e1 / 0.192e3)*_hc2[2]*_hc3[2]*_t15*_t165*_t166*_t43*_t81 + (0.1e1 / 0.36e2)*_hc3[1]*_t168*_t19*_t49*_t7*_t8 - _t165*_t19*_t400 - _t388*_t401 - _t397*_t399;
  const double _t403 = _hc4[0]*_t402;
  const double _t406 = _t178*_t405;
  const double _t408 = _t407*_t53;
  const double _t412 = _t411*_t84;
  const double _t413 = (0.1e1 / 0.64e2)*_t53;
  const double _t415 = _t32*_t414;
  const double _t416 = _t415*_t6;
  const double _t418 = _t417*_t53;
  const double _t421 = _t305*_t420;
  const double _t425 = _t130*_t424;
  const double _t427 = _t426*_t47;
  const double _t428 = _t13*_t427;
  const double d3F_dna3 = _t172*_t98 + _t174*_t2 + _t2*_t210 + _t2*_t230 + 0.6e1*_t63 + 0.3e1*_t79 + 0.3e1*_t99;
  const double d3F_dna2_dnb = _t121*_t266 + _t123*_t98 + _t2*_t265 + _t255*_t53 + _t263*_t264 + _t267*_t268 + _t269 + _t64 + _t79 + _t99;
  const double d3F_dna_dnb2 = _t105*_t301 + _t121*_t124 + _t127 + _t138*_t142 + _t139 + _t2*_t299 + _t264*_t298 + _t269 + 0.2e1*_t270 + _t294*_t53;
  const double d3F_dnb3 = _t126*_t303 + 0.3e1*_t127 + _t138*_t302 + 0.3e1*_t139 + _t2*_t320 + _t2*_t324 + 0.6e1*_t270;
  const double d3F_dna2_dgaa = _t144*_t266 + 0.2e1*_t145 + _t2*_t334 + _t30*_t325 + _t326*_t58;
  const double d3F_dna2_dgbb = _t140*_t336 + _t142*_t338 + _t2*_t340 + _t30*_t337 + _t326*_t62;
  const double d3F_dna_dnb_dgaa = _t123*_t144 + _t142*_t153 + _t145 + _t152*_t341 + _t30*_t58 + _t349*_t53 + _t350*_t58 + _t45*_t58;
  const double d3F_dna_dnb_dgbb = _hc4[0]*_t150 + _t123*_t150 + _t142*_t155 + _t156 + _t30*_t62 + _t350*_t62 + _t356*_t53 + _t45*_t62;
  const double d3F_dnb2_dgaa = _t123*_t359 + _t140*_t358 + _t2*_t362 + _t325*_t45 + _t363*_t58;
  const double d3F_dnb2_dgbb = _t123*_t364 + 0.2e1*_t156 + _t2*_t369 + _t337*_t45 + _t363*_t62;
  const double d3F_dna_dgaa2 = _t142*_t375 - _t163*_t376 + _t2*_t385 + _t370*_t372 - _t374;
  const double d3F_dna_dgbb2 = (0.1e1 / 0.192e3)*_hc2[2]*_hc3[2]*_hc4[0]*_t15*_t165*_t166*_t2*_t28*_t81 + (0.1e1 / 0.96e2)*_hc3[2]*_hc4[0]*_t15*_t165*_t166*_t19*_t81 + (0.1e1 / 0.96e2)*_hc3[2]*_t15*_t165*_t166*_t19*_t2*_t30*_t81 - _t171*_t376 - _t386 - _t390*_t53;
  const double d3F_dnb_dgaa2 = (0.1e1 / 0.192e3)*_hc0[2]*_hc1[2]*_hc4[0]*_t15*_t157*_t158*_t2*_t44*_t81 + (0.1e1 / 0.96e2)*_hc1[2]*_hc4[0]*_t15*_t157*_t158*_t18*_t81 + (0.1e1 / 0.96e2)*_hc1[2]*_t15*_t157*_t158*_t18*_t2*_t45*_t81 - _t163*_t393 - _t374 - _t392*_t53;
  const double d3F_dnb_dgbb2 = _t123*_t396 - _t171*_t393 + _t2*_t403 + _t370*_t395 - _t386;
  const double d3F_dgaa3 = _t406*_t408 - _t412*_t413 + _t416*_t418;
  const double d3F_dgbb3 = _t408*_t421 - _t413*_t425 + _t418*_t428;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 2] += d3F_dna2_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 3] += d3F_dna_dnb_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 5] += d3F_dna_dnb_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 6] += d3F_dnb2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t431 = (0.56e2 / 0.81e2)*_t176;
  const double _t433 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t434 = _t433*_t7;
  const double _t435 = (0.4e1 / 0.729e3)*_t434;
  const double _t436 = xc_powr(na, -16, 3);
  const double _t437 = (0.910e3 / 0.243e3)*_t9;
  const double _t439 = 0.24e2*_t185;
  const double _t440 = xc_powi(_t2, -5);
  const double _t441 = _t1*_t440;
  const double _t442 = 0.24e2*_t441;
  const double _t443 = -_t439 + _t442;
  const double _t445 = (0.8e1 / 0.81e2)*_t176;
  const double _t447 = _t159*_t175;
  const double _t449 = _t180*gaa;
  const double _t451 = (0.140e3 / 0.81e2)*_t9;
  const double _t452 = (0.7e1 / 0.9e1)*_t9;
  const double _t453 = _t452*_t86;
  const double _t456 = 0.12e2*_t69;
  const double _t457 = 0.12e2*_t185;
  const double _t458 = _t1*_t457;
  const double _t459 = -_t456 + _t458;
  const double _t462 = 0.6e1*_t26;
  const double _t463 = 0.6e1*na - 0.6e1*nb;
  const double _t464 = 0.4e1*na - 0.4e1*nb;
  const double _t465 = 0.2e1*na - 0.2e1*nb;
  const double _t466 = _t465*_t69 - _t68;
  const double _t467 = _t1*_t184;
  const double _t472 = (0.2e1 / 0.3e1)*_t17*_t65;
  const double _t473 = _t17*_t212;
  const double _t494 = _t442 - _t457;
  const double _t497 = (0.2e1 / 0.81e2)*_t176;
  const double _t499 = 0.3e1*_t233;
  const double _t505 = (0.35e2 / 0.81e2)*_t9;
  const double _t506 = _t182*_t505;
  const double _t509 = _t458 - 0.4e1*_t69;
  const double _t510 = (0.2e1 / 0.3e1)*_t9;
  const double _t532 = 0.12e2*_t441;
  const double _t534 = 0.4e1*(_t1 * _t1)/xc_powi(_t2, 6);
  const double _t537 = _t465*_t69 + _t68;
  const double _t538 = (0.4e1 / 0.9e1)*_t9;
  const double _t555 = _t167*_t304;
  const double _t556 = _t307*gbb;
  const double _t558 = _t309*_t505;
  const double _t565 = 0.2e1*_t125;
  const double _t569 = xc_powr(nb, -16, 3);
  const double _t570 = _t439 + _t442;
  const double _t574 = _t456 + _t458;
  const double _t577 = (0.1e1 / 0.8e1)*_t9;
  const double _t580 = (0.11e2 / 0.54e2)*_t176;
  const double _t581 = (0.1e1 / 0.486e3)*_t434;
  const double _t585 = (0.1e1 / 0.18e2)*_t233;
  const double _t587 = (0.7e1 / 0.108e3)*_t86;
  const double _t595 = _t54*_t69;
  const double _t596 = _t271*_t577;
  const double _t599 = (0.7e1 / 0.108e3)*_t132;
  const double _t607 = (0.1e1 / 0.1296e4)*_t434;
  const double _t608 = (0.19e2 / 0.432e3)*_t176;
  const double _t609 = (0.1e1 / 0.192e3)*_t371;
  const double _t618 = (0.1e1 / 0.192e3)*_t394;
  const double _t624 = (0.1e1 / 0.3456e4)*_t434;
  const double _t625 = (0.1e1 / 0.768e3)*_t176;
  const double _t626 = (0.1e1 / 0.128e3)*_t411;
  const double _t627 = (0.1e1 / 0.64e2)*_t9;
  const double _t628 = _t414*_t627;
  const double _t637 = (0.1e1 / 0.128e3)*_t424;
  const double _t429 = _t30*_t98;
  const double _t430 = _t2*_t41;
  const double _t432 = _hc1[4]*_t18;
  const double _t438 = _hc0[14]*_t88;
  const double _t444 = _hc2[14]*_t92;
  const double _t446 = _hc1[3]*_t95;
  const double _t448 = _t83*_t95;
  const double _t450 = (0.2e1 / 0.9e1)*_t194*gaa;
  const double _t454 = _hc1[1]*_t200*_t453;
  const double _t455 = _t203*_t234;
  const double _t460 = _t119*_t72;
  const double _t461 = _t117*_t91;
  const double _t468 = _hc0[5]*_t29;
  const double _t469 = _t199*_t5;
  const double _t470 = (0.140e3 / 0.81e2)*_t22/xc_powr(_t2, 13, 3);
  const double _t471 = _t211*_t215;
  const double _t474 = _hc4[5]*_t473;
  const double _t475 = -_t474;
  const double _t476 = _hc4[9]*_t218;
  const double _t477 = -_hc4[14]*_t73;
  const double _t478 = -_hc4[13]*_t73;
  const double _t479 = _hc4[12]*_t29 + _t478;
  const double _t480 = _hc4[8]*_t218;
  const double _t481 = -_hc4[12]*_t73;
  const double _t482 = _hc4[11]*_t29 + _t481;
  const double _t483 = _hc4[7]*_t72 + _t29*_t482 - _t479*_t73 + _t480;
  const double _t484 = _hc4[4]*_t473;
  const double _t485 = -_t484;
  const double _t486 = _hc4[7]*_t218;
  const double _t487 = -_hc4[11]*_t73;
  const double _t488 = _t45*_t98;
  const double _t489 = _t121*_t30;
  const double _t490 = 0.3e1*_t350;
  const double _t491 = 0.3e1*_t121;
  const double _t492 = _hc4[0]*_t255;
  const double _t493 = _t20*_t263;
  const double _t495 = _hc0[2]*_t233;
  const double _t496 = _t233*_t237;
  const double _t498 = _hc1[3]*_t115;
  const double _t500 = _hc0[9]*_hc1[0];
  const double _t501 = _t233*_t239;
  const double _t502 = _t115*_t83;
  const double _t503 = _hc2[9]*_hc3[0];
  const double _t504 = _t499*_t503;
  const double _t507 = _hc2[2]*_t188;
  const double _t508 = _hc2[9]*_t192;
  const double _t511 = _t203*_t233;
  const double _t512 = _hc0[9]*_t249*_t89;
  const double _t513 = _t113*_t28;
  const double _t514 = _hc2[5]*_t208;
  const double _t515 = _hc2[5]*_t91;
  const double _t516 = _hc0[5]*_t44;
  const double _t517 = _t193*_t292;
  const double _t518 = _t191*_t252;
  const double _t519 = _hc4[11]*_t44 + _t481;
  const double _t520 = _hc4[12]*_t44 + _t478;
  const double _t521 = _t480 - _t520*_t73;
  const double _t522 = _hc4[7]*_t71 + _t29*_t519 + _t521;
  const double _t523 = _hc4[10]*_t44 + _t487;
  const double _t524 = _t486 - _t519*_t73;
  const double _t525 = _t476 - _t73*(_hc4[13]*_t44 + _t477);
  const double _t526 = _t259*_t321 + _t470;
  const double _t527 = _t105*_t51;
  const double _t528 = _t138*_t30;
  const double _t529 = _t121*_t45;
  const double _t530 = _t20*_t298;
  const double _t531 = _hc4[0]*_t294;
  const double _t533 = _t39*_t532;
  const double _t535 = _t194*_t242;
  const double _t536 = _t278*_t280;
  const double _t539 = _hc2[5]*_t233;
  const double _t540 = _t291*_t43;
  const double _t541 = _t36*_t96;
  const double _t542 = _hc4[1]*_t442;
  const double _t543 = _hc4[7]*_t125 + _t44*_t519 + _t521;
  const double _t544 = _t543*_t73;
  const double _t545 = _hc4[6]*_t125 + _t44*_t523 + _t524;
  const double _t546 = _t103*_t17*_t211;
  const double _t547 = _t73*(_hc4[8]*_t125 + _t44*_t520 + _t525);
  const double _t548 = _t138*_t45;
  const double _t549 = _t126*_t51;
  const double _t550 = _t275*_t9;
  const double _t551 = (0.2e1 / 0.9e1)*_t278*gbb;
  const double _t552 = _hc2[2]*_t233;
  const double _t553 = _t112*_t132*_t452;
  const double _t554 = _hc3[3]*_t109;
  const double _t557 = _t109*_t129;
  const double _t559 = _hc0[9]*_t313;
  const double _t560 = _t114*_t96;
  const double _t561 = _t28*_t315;
  const double _t562 = _hc2[9]*_t133;
  const double _t563 = _hc2[5]*_t134;
  const double _t564 = _t516*_t560;
  const double _t566 = _hc4[3]*_t312 + _t256*_t321 + _t260*_t565 + _t44*_t545 + _t485 - _t544;
  const double _t567 = _t295*_t472 + _t470 - 0.14e2 / 0.9e1*_t546 - _t73*(_hc4[4]*_t312 + _t256*_t565 + _t257*_t321 + _t44*_t543 + _t475 - _t547);
  const double _t568 = _hc3[4]*_t19;
  const double _t571 = _hc2[2]*_hc3[3]*_t43;
  const double _t572 = _t129*_t136;
  const double _t573 = _t234*_t274;
  const double _t575 = _t43*_t573;
  const double _t576 = _t144*_t30;
  const double _t578 = _t577*_t78;
  const double _t579 = _t2*_t229;
  const double _t582 = _t30*_t336;
  const double _t583 = _t109*_t9;
  const double _t584 = _t149*_t28;
  const double _t586 = _hc1[1]*_t233;
  const double _t588 = _hc0[2]*_t152;
  const double _t589 = _t2*_t263;
  const double _t590 = 0.2e1*_hc4[0];
  const double _t591 = 0.2e1*_t45;
  const double _t592 = _t105*_t325 + _t144*_t591 + _t30*_t359 + _t349*_t590;
  const double _t593 = _t14*_t147*_t539;
  const double _t594 = _t105*_t337 + _t30*_t364 + _t338*_t45 + _t356*_t590;
  const double _t597 = _t2*_t298;
  const double _t598 = _t176*_t554;
  const double _t600 = _t126*_t577;
  const double _t601 = _t152*_t516;
  const double _t602 = _t2*_t323;
  const double _t603 = _t10*_t354;
  const double _t604 = (0.1e1 / 0.48e2)*_t30;
  const double _t605 = (0.1e1 / 0.24e2)*_t30;
  const double _t606 = (0.1e1 / 0.48e2)*_t326;
  const double _t610 = _t609*_t83;
  const double _t611 = _t394*_t557;
  const double _t612 = _t109*_t169*_t387;
  const double _t613 = _t502*_t609;
  const double _t614 = (0.1e1 / 0.48e2)*_t45;
  const double _t615 = (0.1e1 / 0.48e2)*_t350;
  const double _t616 = _t151*_t161;
  const double _t617 = _t176*_t498;
  const double _t619 = _t557*_t618;
  const double _t620 = _t115*_t616;
  const double _t621 = (0.1e1 / 0.24e2)*_t45;
  const double _t622 = (0.1e1 / 0.48e2)*_t363;
  const double _t623 = _t129*_t618;
  const double _t629 = _t142*_t407;
  const double _t630 = (0.1e1 / 0.64e2)*_t142;
  const double _t631 = _t142*_t417;
  const double _t632 = _hc4[0]*_t407;
  const double _t633 = (0.1e1 / 0.64e2)*_hc4[0];
  const double _t634 = _hc4[0]*_t417;
  const double _t635 = _t406*_t632 - _t412*_t633 + _t416*_t634;
  const double _t636 = (0.1e1 / 0.768e3)*_t53;
  const double _t638 = _t421*_t632 - _t425*_t633 + _t428*_t634;
  const double _t639 = _t123*_t407;
  const double _t640 = (0.1e1 / 0.64e2)*_t123;
  const double _t641 = _t123*_t417;
  const double _t642 = (0.1e1 / 0.128e3)*_t176*_t53;
  const double _t643 = (0.5e1 / 0.64e2)*_t53*_t9;
  const double d4F_dna4 = 0.4e1*_t142*_t209 + 0.12e2*_t173 + 0.4e1*_t210 + 0.4e1*_t229*_t430 + 0.4e1*_t230 + _t264*(_hc4[1]*_t443 + 0.3e1*_t189*_t77 + _t224*_t472 + 0.3e1*_t228*_t72 + _t29*(_hc4[3]*_t189 + _t217*_t227 + _t223*_t321 + _t29*(_hc4[6]*_t72 + _t29*(_hc4[10]*_t29 + _t487) - _t482*_t73 + _t486) - _t483*_t73 + _t485) + _t470 - 0.14e2 / 0.9e1*_t471 - _t73*(_hc4[4]*_t189 + _t217*_t223 + _t221*_t321 + _t29*_t483 + _t475 - _t73*(_hc4[8]*_t72 + _t29*_t479 + _t476 - _t73*(_hc4[13]*_t29 + _t477)))) + 0.6e1*_t326*_t98 + 0.12e2*_t429 + _t53*(-_hc0[9]*_t190*_t455 + _t117*(_t91 * _t91) + _t118*_t459 + _t119*(_t72 * _t72) - _t120*_t459 + _t179*_t431/xc_powi(na, 8) - _t182*_t451*_t97 + _t188*_t240 - _t189*_t236 + _t189*_t238 - _t207*_t455*_t468 + _t207*_t460 + _t208*_t247 + _t208*_t461 - _t234*_t468*_t469 + _t247*_t91 + _t247*(_t462 - _t467) + _t250*_t466 + _t250*(-_t205 + _t464*_t69) + _t250*(-_t462 + _t463*_t69) + (_t28 * _t28 * _t28 * _t28)*_t444 + (_t29 * _t29 * _t29 * _t29)*_t438 + _t33*_t436*_t437 + _t332*_t450 + _t38*_t443 - _t40*_t443 + _t409*_t432*_t435/xc_powr(na, 28, 3) - _t445*_t446*_t447 - 0.28e2 / 0.27e2*_t448*_t449 + _t450*_t90 + _t453*_t90*_t96 + _t454*_t72 + (0.854e3 / 0.243e3)*_t84*gaa/xc_powr(na, 20, 3));
  const double d4F_dna3_dnb = _t123*_t209 + _t172*_t255 + _t174 + _t210 + _t229*_t300 + _t230 + 0.3e1*_t263*_t430 + _t264*(_hc4[1]*_t494 + _t102*_t189 - _t103*_t473 + _t217*_t262 + _t218*_t224 + _t228*_t71 + 0.2e1*_t232*_t77 + _t29*(_hc4[3]*_t232 + _t218*_t223 + _t218*_t256 + _t227*_t71 + _t260*_t72 + _t29*(_hc4[6]*_t71 + _t29*_t523 + _t524) + _t485 - _t522*_t73) - 0.28e2 / 0.27e2*_t471 + _t526 - _t73*(_hc4[4]*_t232 + _t218*_t221 + _t218*_t257 + _t223*_t71 + _t256*_t72 + _t29*_t522 + _t475 - _t73*(_hc4[8]*_t71 + _t29*_t520 + _t525))) + 0.3e1*_t265 + 0.6e1*_t267 + _t326*_t491 + 0.3e1*_t429 + 0.3e1*_t488 + 0.6e1*_t489 + _t490*_t98 + 0.3e1*_t492 + 0.3e1*_t493 + _t53*(-_t113*_t507 - _t113*_t508 - _t116*_t506 + _t118*_t231 + _t118*_t509 + _t120*_t232 - _t120*_t509 + _t188*_t246 + _t189*_t251 + _t190*_t249*_t438 + _t192*_t43*_t444 + _t194*_t195*_t253 + _t197*_t254 - _t198*_t202*_t232 - _t201*_t469*_t516 - _t204*_t512 + _t207*_t496 + _t207*_t518 - _t208*_t501 + _t208*_t517 + _t233*_t454 + _t38*_t494 - _t40*_t494 - _t447*_t497*_t498 - 0.7e1 / 0.27e2*_t449*_t502 + _t450*_t495 - _t468*_t510*_t511 + _t496*_t72 + _t499*_t500*_t89 - _t501*_t91 - _t504*_t93 - _t513*_t514 - _t513*_t515 + _t517*_t91 + _t518*_t72);
  const double d4F_dna2_dnb2 = 0.4e1*_t121*_t350 + _t124*_t255 + _t138*_t326 + _t263*_t301 + _t264*(-_t187*_t77 + _t206*_t262 - _t212*_t215 + _t218*_t295 + _t232*_t322 + _t29*(-_hc4[3]*_t187 - _hc4[3]*_t70 + 0.4e1*_t1*_t260*_t69 + (0.4e1 / 0.9e1)*_t15*_t16*_t256*_t65 + _t29*_t545 - _t484 - _t544) + _t297*_t72 + _t526 + _t542 - 0.28e2 / 0.27e2*_t546 - _t70*_t77 - _t73*(-_hc4[4]*_t187 - _hc4[4]*_t70 + 0.4e1*_t1*_t256*_t69 + (0.4e1 / 0.9e1)*_t15*_t16*_t257*_t65 + _t29*_t543 - _t474 - _t547)) + 0.2e1*_t265 + _t266*_t294 + 0.4e1*_t267 + 0.2e1*_t298*_t430 + 0.2e1*_t299 + _t363*_t98 + 0.2e1*_t488 + 0.4e1*_t489 + 0.2e1*_t492 + 0.2e1*_t493 + 0.4e1*_t527 + 0.2e1*_t528 + 0.4e1*_t529 + _t53*(-_hc0[9]*_t135*_t289*_t541 + _hc1[1]*_t244*_t285 - _hc2[2]*_t231*_t291 - _hc2[9]*_t540*_t93 + _t125*_t460 - _t125*_t468*_t541 + _t133*_t444*_t93 + _t134*_t247 + _t134*_t461 + _t135*_t438*_t89 - _t187*_t238 + _t187*_t240 + _t206*_t252*_t500 - _t206*_t292*_t503 + _t231*_t277 + _t232*_t281 + _t235*_t271*_t510 + _t236*_t69 + _t237*_t534 - _t238*_t70 + _t239*_t534 + _t240*_t70 + _t244*_t287 + _t245*_t283 + _t245*_t536 + _t250*_t537 + _t274*_t28*_t538*_t539 + _t283*_t94 + _t286*_t535 + _t288*_t91 + _t290*_t466 + _t360*_t535 + _t37*_t532 - _t511*_t516*_t538 - _t515*_t540 - _t533 + _t536*_t94) + 0.2e1*_t530 + 0.2e1*_t531;
  const double d4F_dna_dnb3 = _t138*_t490 + _t142*_t319 + _t264*(_hc4[1]*_t457 - _t102*_t184 - 0.18e2*_t102*_t271 + _t29*_t566 + _t297*_t467 + _t542 + _t567) + _t294*_t302 + _t298*_t303 + 0.3e1*_t299 + _t320 + _t323*_t430 + _t324 + _t363*_t491 + 0.6e1*_t527 + 0.3e1*_t528 + 0.6e1*_t529 + _t53*((0.1e1 / 0.2e1)*_hc0[14]*_hc1[0]*_t289*_t313 + 0.12e2*_hc0[2]*_hc1[0]*_t1*_t440 + 0.6e1*_hc0[2]*_hc1[0]*_t185 + 0.3e1*_hc0[5]*_hc1[0]*_t1*_t125*_t69 + (0.1e1 / 0.2e1)*_hc0[5]*_hc1[0]*_t29*_t312 + 0.3e1*_hc0[9]*_hc1[0]*_t1*_t135*_t69 + (0.1e1 / 0.2e1)*_hc0[9]*_hc1[0]*_t125*_t29*_t44 + (0.1e1 / 0.2e1)*_hc0[9]*_hc1[0]*_t29*_t317*_t44 + (0.1e1 / 0.2e1)*_hc2[14]*_hc3[0]*_t28*_t310 + 0.9e1*_hc2[5]*_hc3[0]*_t1*_t185*_t43 + (0.1e1 / 0.2e1)*_hc2[5]*_hc3[0]*_t28*_t311 + 0.3e1*_hc2[5]*_hc3[0]*_t43*_t69 + (0.2e1 / 0.3e1)*_hc2[5]*_hc3[1]*_t1*_t12*_t43*_t49*_t69*_t7*_t8 + (0.7e1 / 0.18e2)*_hc2[5]*_hc3[1]*_t12*_t132*_t28*_t43*_t7*_t8 + (0.1e1 / 0.9e1)*_hc2[5]*_hc3[2]*_t128*_t15*_t28*_t43*_t81*gbb + (0.1e1 / 0.2e1)*_hc2[9]*_hc3[0]*_t134*_t28*_t43 + (0.1e1 / 0.2e1)*_hc2[9]*_hc3[0]*_t28*_t318*_t43 - _t109*_t112*_t558 - _t125*_t564 - _t133*_t504 - 0.3e1*_t134*_t501 - _t186*_t39 - _t200*_t284*_t312 - 0.9e1*_t271*_t281 - _t271*_t550 - 0.3e1*_t281*_t69 - _t317*_t564 - _t497*_t554*_t555 - _t533 - 0.1e1 / 0.3e1*_t550*_t69 - _t551*_t552 - _t552*_t553 - 0.7e1 / 0.27e2*_t556*_t557 - _t559*_t560 - _t561*_t562 - _t561*_t563) + 0.3e1*_t530 + 0.3e1*_t531 + 0.3e1*_t548 + 0.3e1*_t549;
  const double d4F_dnb4 = 0.4e1*_t123*_t319 + 0.6e1*_t138*_t363 + _t264*(_hc4[1]*_t570 + 0.3e1*_t102*_t312 + 0.3e1*_t125*_t297 + _t44*_t566 + _t567) + 0.4e1*_t300*_t323 + 0.4e1*_t320 + 0.4e1*_t324 + _t53*(-_hc2[5]*_t318*_t575 - _hc2[9]*_t310*_t573 + _t117*(_t134 * _t134) + _t117*_t134*_t318 + _t119*(_t125 * _t125) + _t119*_t125*_t317 + (0.854e3 / 0.243e3)*_t130*gbb/xc_powr(nb, 20, 3) + _t134*_t288 - _t137*_t309*_t451 + _t246*_t574 - _t251*_t574 - _t276*_t311 + _t277*_t311 + _t281*_t312 + _t288*_t318 + _t288*(-_t462 - _t467) + _t290*_t537 + _t290*(_t205 + _t464*_t69) + _t290*(_t462 + _t463*_t69) + _t306*_t431/xc_powi(nb, 8) + _t314*_t551 + _t314*_t553 + _t316*_t551 + _t316*_t553 + _t38*_t570 - _t40*_t570 + _t422*_t435*_t568/xc_powr(nb, 28, 3) + (_t43 * _t43 * _t43 * _t43)*_t444 + _t437*_t48*_t569 + _t438*(_t44 * _t44 * _t44 * _t44) - _t445*_t555*_t571 - 0.28e2 / 0.27e2*_t556*_t572 - _t563*_t575) + 0.12e2*_t548 + 0.12e2*_t549;
  const double d4F_dna3_dgaa = 0.3e1*_t144*_t326 + _t172*_t333 + 0.3e1*_t334 + _t53*((0.1e1 / 0.48e2)*_hc0[2]*_hc1[1]*_t189*_t55*_t6*_t7*_t8 + (0.7e1 / 0.36e2)*_hc0[2]*_hc1[1]*_t29*_t55*_t7*_t8*_t86 + (0.5e1 / 0.24e2)*_hc0[2]*_hc1[2]*_t15*_t29*_t80*_t81 + (0.1e1 / 0.36e2)*_hc0[2]*_hc1[3]*_t176*_t29*_t327*_t5 + (0.1e1 / 0.48e2)*_hc0[5]*_hc1[1]*_t207*_t29*_t55*_t6*_t7*_t8 + (0.1e1 / 0.48e2)*_hc0[5]*_hc1[1]*_t29*_t55*_t6*_t7*_t72*_t8 + (0.1e1 / 0.48e2)*_hc0[9]*_hc1[1]*_t190*_t55*_t6*_t7*_t8 - _t10*_t199*_t342 - _t10*_t347*_t90 - 0.1e1 / 0.24e2*_t143*_t90 - _t175*_t329*_t580 - 0.119e3 / 0.162e3*_t181 - 0.1e1 / 0.24e2*_t330*_t72 - _t432*_t581*gaa/xc_powr(na, 25, 3) - _t506*_t56) + _t57*_t578 + 0.6e1*_t576 + _t579*_t58;
  const double d4F_dna3_dgbb = _t172*_t339 + (0.1e1 / 0.16e2)*_t326*_t335*_t583 + 0.3e1*_t340 + _t53*(_t149*_t507 + _t149*_t508 + _t514*_t584 + _t515*_t584) + _t577*_t582 + _t578*_t61 + _t579*_t62;
  const double d4F_dna2_dnb_dgaa = _t105*_t144*_t268 + _t123*_t333 + _t153*_t326 + _t266*_t349 + _t334 + _t53*(_hc1[1]*_t357*_t587*_t9 + _t11*_t468*_t55*_t586 - 0.1e1 / 0.36e2*_t143*_t253 + _t152*_t512 + _t152*_t516*_t72 + (0.1e1 / 0.108e3)*_t176*_t327*_t498*_t5 + _t232*_t588 + (0.5e1 / 0.72e2)*_t241 - _t253*_t284*_t55 - _t330*_t585 - _t342*_t36*_t586) + 0.2e1*_t576 + _t58*_t589 + _t58*_t78 + _t592;
  const double d4F_dna2_dnb_dgbb = _t123*_t339 + _t155*_t326 + _t266*_t356 + _t338*_t350 + _t340 + _t53*((0.1e1 / 0.48e2)*_hc2[2]*_hc3[1]*_t13*_t231*_t59*_t7*_t8 + (0.1e1 / 0.48e2)*_hc2[5]*_hc3[1]*_t13*_t43*_t59*_t7*_t8*_t91 + (0.1e1 / 0.48e2)*_hc2[9]*_hc3[1]*_t13*_t43*_t59*_t7*_t8*_t93 - _t245*_t355 - _t28*_t593 - _t353*_t91 - _t355*_t94 - _t400*_t94) + _t54*_t582 + _t589*_t62 + _t594 + _t62*_t78;
  const double d4F_dna_dnb2_dgaa = _t124*_t349 + _t126*_t58 + _t142*_t361 + _t144*_t363 + _t350*_t359 + _t359*_t45 + _t362 + _t53*((0.1e1 / 0.12e2)*_hc0[5]*_hc1[1]*_t1*_t44*_t55*_t6*_t69*_t7*_t8 + (0.1e1 / 0.48e2)*_hc0[5]*_hc1[1]*_t125*_t29*_t55*_t6*_t7*_t8 + (0.1e1 / 0.48e2)*_hc0[9]*_hc1[1]*_t135*_t289*_t55*_t6*_t7*_t8 - _t125*_t345 - _t286*_t348 - _t286*_t381 - _t343*_t595 - _t343*_t596 - _t348*_t360) + _t58*_t597 + _t592;
  const double d4F_dna_dnb2_dgbb = _t124*_t356 + _t126*_t62 + _t142*_t368 + _t150*_t363 + _t155*_t591 + _t350*_t364 + _t369 + _t53*(-_t111*_t147*_t293 + (0.1e1 / 0.108e3)*_t12*_t365*_t598 + _t147*_t50*_t552 + _t147*_t583*_t599 - 0.1e1 / 0.36e2*_t154*_t293 + (0.5e1 / 0.72e2)*_t279 + _t351*_t595 + _t351*_t596 + _t352*_t585 - _t43*_t593 + _t562*_t584 + _t563*_t584) + _t594 + _t597*_t62;
  const double d4F_dnb3_dgaa = _t302*_t361 + (0.1e1 / 0.16e2)*_t358*_t363*_t9 + _t358*_t45*_t577 + 0.3e1*_t362 + _t53*(_t125*_t601 + _t152*_t559 + _t312*_t588 + _t317*_t601) + _t57*_t600 + _t58*_t602;
  const double d4F_dnb3_dgbb = 0.3e1*_t155*_t363 + 0.6e1*_t155*_t45 + _t302*_t368 + 0.3e1*_t369 + _t53*((0.1e1 / 0.48e2)*_hc2[2]*_hc3[1]*_t13*_t311*_t59*_t7*_t8 + (0.7e1 / 0.36e2)*_hc2[2]*_hc3[1]*_t132*_t43*_t59*_t7*_t8 + (0.5e1 / 0.24e2)*_hc2[2]*_hc3[2]*_t128*_t15*_t43*_t81 + (0.1e1 / 0.36e2)*_hc2[2]*_hc3[3]*_t12*_t176*_t365*_t43 + (0.1e1 / 0.48e2)*_hc2[5]*_hc3[1]*_t13*_t134*_t43*_t59*_t7*_t8 + (0.1e1 / 0.48e2)*_hc2[5]*_hc3[1]*_t13*_t318*_t43*_t59*_t7*_t8 + (0.1e1 / 0.48e2)*_hc2[9]*_hc3[1]*_t13*_t310*_t59*_t7*_t8 - 0.1e1 / 0.24e2*_t134*_t352 - 0.1e1 / 0.24e2*_t154*_t314 - _t304*_t366*_t580 - 0.119e3 / 0.162e3*_t308 - _t314*_t603 - _t316*_t603 - _t558*_t60 - _t568*_t581*gbb/xc_powr(nb, 25, 3)) + _t600*_t61 + _t602*_t62;
  const double d4F_dna2_dgaa2 = -_t163*_t605 - _t163*_t606 + _t266*_t384 + _t326*_t375 + _t372*_t604 + 0.2e1*_t385 + _t53*(_hc0[2]*_t161*_t198*_t331 - _t157*_t29*_t345 + (0.7e1 / 0.216e3)*_t157*_t85 - _t162*_t587 + _t327*_t377*_t608 - _t332*_t391 + _t332*_t610 - _t380*_t446*_t55 - _t391*_t90 + _t432*_t607/xc_powr(na, 22, 3) + _t610*_t90);
  const double d4F_dna2_dgbb2 = (0.1e1 / 0.96e2)*_t142*_t611 - _t171*_t605 - _t171*_t606 + _t326*_t396 + _t370*_t611 - _t373*_t612 - _t376*_t612 + _t395*_t604 + _t53*((0.1e1 / 0.192e3)*_hc2[2]*_hc3[2]*_t15*_t165*_t166*_t81*_t91 + (0.1e1 / 0.192e3)*_hc2[5]*_hc3[2]*_t15*_t165*_t166*_t81*_t93 - _t245*_t389 - _t389*_t94);
  const double d4F_dna_dnb_dgaa2 = _hc4[0]*_t613 + _t123*_t384 - _t142*_t392 + _t142*_t613 - _t163*_t604 - _t163*_t614 - _t163*_t615 + _t30*_t375 - _t341*_t391 + _t350*_t375 + _t375*_t45 + _t385 + _t53*((0.1e1 / 0.72e2)*_hc0[2]*_hc1[1]*_t160*_t34*_t44*_t7*_t8 + (0.1e1 / 0.96e2)*_hc0[2]*_hc1[2]*_t1*_t15*_t157*_t158*_t69*_t81 + (0.1e1 / 0.192e3)*_hc0[5]*_hc1[2]*_t15*_t157*_t158*_t29*_t44*_t81 - 0.1e1 / 0.144e3*_t157*_t330*_t44 - _t253*_t391 - 0.1e1 / 0.288e3*_t378*_t55*_t617 - 0.1e1 / 0.48e2*_t495*_t616);
  const double d4F_dna_dnb_dgbb2 = _hc4[0]*_t619 - _t123*_t390 + _t123*_t619 + _t142*_t402 - _t171*_t604 - _t171*_t614 - _t171*_t615 + _t30*_t396 + _t350*_t396 - _t370*_t612 + _t396*_t45 + _t403 + _t53*((0.1e1 / 0.48e2)*_hc2[2]*_hc3[1]*_t1*_t13*_t168*_t69*_t7*_t8 + (0.1e1 / 0.72e2)*_hc2[2]*_hc3[1]*_t168*_t28*_t49*_t7*_t8 + (0.1e1 / 0.192e3)*_hc2[5]*_hc3[2]*_t15*_t165*_t166*_t28*_t43*_t81 - 0.1e1 / 0.96e2*_t129*_t394*_t552 - 0.1e1 / 0.144e3*_t165*_t28*_t352 - _t293*_t389 - 0.1e1 / 0.288e3*_t398*_t59*_t598);
  const double d4F_dnb2_dgaa2 = (0.1e1 / 0.96e2)*_t123*_t371*_t502 - _t163*_t621 - _t163*_t622 + _t363*_t375 + _t370*_t371*_t502 + _t372*_t614 - _t373*_t620 - _t393*_t620 + _t53*((0.1e1 / 0.192e3)*_hc0[2]*_hc1[2]*_t125*_t15*_t157*_t158*_t81 + (0.1e1 / 0.192e3)*_hc0[5]*_hc1[2]*_t135*_t15*_t157*_t158*_t81 - _t286*_t391 - _t360*_t391);
  const double d4F_dnb2_dgbb2 = _t124*_t402 - _t171*_t621 - _t171*_t622 + _t363*_t396 + _t395*_t614 + 0.2e1*_t403 + _t53*(_hc2[2]*_t169*_t273*_t367 + (0.7e1 / 0.216e3)*_t131*_t165 - _t165*_t353*_t43 - _t170*_t599 - _t314*_t389 + _t314*_t623 - _t316*_t389 + _t316*_t623 + _t365*_t397*_t608 - _t399*_t571*_t59 + _t568*_t607/xc_powr(nb, 22, 3));
  const double d4F_dna_dgaa3 = _t406*_t629 - _t412*_t630 + _t416*_t631 + _t53*((0.1e1 / 0.48e2)*_t143*_t18*_t410 - _t157*_t432*_t624/xc_powr(na, 19, 3) - _t34*_t415*_t54 + _t382*_t628 + _t405*_t446*_t625 - _t448*_t626) + _t635;
  const double d4F_dna_dgbb3 = _t387*_t413*_t426*_t583 + _t420*_t598*_t636 + _t421*_t629 - _t425*_t630 + _t428*_t631 - _t53*_t557*_t637 + _t638;
  const double d4F_dnb_dgaa3 = _t115*_t151*_t53*_t628 + _t405*_t617*_t636 + _t406*_t639 - _t412*_t640 + _t416*_t641 - _t502*_t53*_t626 + _t635;
  const double d4F_dnb_dgbb3 = _t421*_t639 - _t425*_t640 + _t428*_t641 + _t53*((0.1e1 / 0.48e2)*_t154*_t19*_t423 - _t165*_t568*_t624/xc_powr(nb, 19, 3) + _t401*_t426*_t627 + _t420*_t571*_t625 - _t427*_t49*_t54 - _t572*_t637) + _t638;
  const double d4F_dgaa4 = (0.5e1 / 0.128e3)*_hc1[2]*_hc4[0]*_t15*_t158*_t18*_t2*_t81/(gaa * gaa * gaa) + (0.1e1 / 0.9216e4)*_hc1[4]*_hc4[0]*_t18*_t2*_t410*_t433*_t436*_t7 - _t178*_t404*_t414*_t642 - _t32*_t6*_t643/xc_powr(gaa, 7, 2);
  const double d4F_dgbb4 = (0.5e1 / 0.128e3)*_hc3[2]*_hc4[0]*_t15*_t166*_t19*_t2*_t81/(gbb * gbb * gbb) + (0.1e1 / 0.9216e4)*_hc3[4]*_hc4[0]*_t19*_t2*_t423*_t433*_t569*_t7 - _t13*_t47*_t643/xc_powr(gbb, 7, 2) - _t305*_t419*_t426*_t642;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 2] += d4F_dna3_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 3] += d4F_dna2_dnb_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 5] += d4F_dna2_dnb_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 6] += d4F_dna_dnb2_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 8] += d4F_dna_dnb2_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 9] += d4F_dnb3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif