/*
  Generated from python/mgga_exc/mgga_c_rscan.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_c_rscan
*/

#ifndef _MGGA_C_RSCAN_KERNEL_BODY
#define maple2c_order 3
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC)

/* ---- top-level dispatch ---- */

#define _MGGA_C_RSCAN_KERNEL_BODY
#define _KMAX 0
#define _MGGA_C_RSCAN_HELPER_BODIES
#include "mgga_c_rscan.c"
#undef _MGGA_C_RSCAN_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_C_RSCAN_HELPER_BODIES
#include "mgga_c_rscan.c"
#undef _MGGA_C_RSCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_C_RSCAN_HELPER_BODIES
#include "mgga_c_rscan.c"
#undef _MGGA_C_RSCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_C_RSCAN_HELPER_BODIES
#include "mgga_c_rscan.c"
#undef _MGGA_C_RSCAN_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_c_rscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_c_rscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_c_rscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_c_rscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_c_rscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_c_rscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_c_rscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_c_rscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_C_RSCAN_HELPER_BODIES)

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
  const double _t21 = _t10*(_t13 * _t13 * _t13)/(_t12 * _t12 * _t12);
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
  const double d3f_dn3 = my_piecewise3(_t1, _t2*(_t9 * _t9 * _t9), _t10*(_t6 * _t6 * _t6));
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t1, 0, 0.2e1*_t11*_t14 + _t14*_t16*n);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t1, 0, _t11*_t17*_t20 - _t18*_t7 - _t18 + 0.2e1*_t19);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t1, 0, -0.3e1*_t20*_t21 + _t21*(n * n * n) + 0.2e1*_t21*n);
  out[9] = d3f_dz3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
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
  const double _t24 = (zeta * zeta * zeta);
  const double _t25 = _t22*_t24;
  const double _t26 = 0.4e1*_hc0[0];
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
  const double _t49 = _hc0[0]*_t22;
  const double _t50 = (zeta * zeta);
  const double _t51 = 0.12e2*_t50;
  const double _t52 = 0.8e1*_hc0[1];
  const double _t53 = _t24*_t44;
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
  const double _t64 = (_t41 * _t41);
  const double _t65 = (0.1e1 / (_t38 * _t38));
  const double _t66 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t67 = _t65*_t66;
  const double _t68 = _t64*_t67;
  const double _t69 = (0.1e1 / (_t10 * _t10 * _t10 * _t10));
  const double _t70 = (0.1e1 / (_t36 * _t36));
  const double _t71 = (_t34 * _t34)*_t70;
  const double _t72 = _t69*_t71;
  const double _t73 = _t14*_t72;
  const double _t74 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t75 = -0.30559670843999998*_t28 - 0.47231125997999995*_t29 - 0.12260679726399999*rs - 0.44616398128000001;
  const double _t76 = _t39*_t74*_t75;
  const double _t77 = _t42*_t76;
  const double _t78 = -0.089189175563999995*_t28 - 0.3497952466*_t29 - 0.067103136792000001*rs - 0.24473170956000001;
  const double _t79 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t80 = _t34*_t37*_t79;
  const double _t81 = _t78*_t80;
  const double _t82 = _t14*_t81;
  const double _t83 = _t31*_t33;
  const double _t84 = -0.078493135754999999*_t56 + 0.1097416210575*_t57 - 0.038873945837999996;
  const double _t85 = _t83*_t84;
  const double _t86 = (0.1e1 / (_t19 * _t19 * _t19 * _t19));
  const double _t87 = (0.1e1 / (_t32 * _t32));
  const double _t88 = (_t30 * _t30)*_t87;
  const double _t89 = _t86*_t88;
  const double _t90 = _t18*_t30;
  const double _t91 = (0.1e1 / (_t19 * _t19 * _t19));
  const double _t92 = -0.31397254301999999*_t28 - 0.43896648423000001*_t29 - 0.077747891675999992*rs - 0.38538166278000002;
  const double _t93 = _t33*_t91*_t92;
  const double _t94 = _t17*_t89 + _t18*_t85 + _t2*_t68 - 0.012777034071999999*_t30*_t83 + _t54 - _t55 - _t60 + _t63 + _t72*(0.0021973736767207854*rs + 0.019751673498613801) - _t77 + _t82 + _t90*_t93;
  const double _t95 = _t16*_t94;
#endif
#if _KMAX >= 3
  const double _t96 = 0.039864495540000003*_t59;
  const double _t97 = 0.0065921210301623562*_t62;
  const double _t98 = (0.1e1 / _t3);
  const double _t99 = xc_powr(rs, -5, 2);
  const double _t100 = _t2*_t40*(0.038199588554999997*_t98 - 0.17711672249249999*_t99);
  const double _t101 = 0.039864495540000003*_t68;
  const double _t102 = _t14*_t46*(0.011148646945499999*_t98 - 0.13117321747499999*_t99);
  const double _t103 = 0.0065921210301623562*_t72;
  const double _t104 = 0.026576330360000001*rs + 0.1243628;
  const double _t105 = (_t41 * _t41 * _t41)/((_t38 * _t38 * _t38)*xc_powi(_t6, 6));
  const double _t106 = (_t34 * _t34 * _t34)/(xc_powi(_t10, 6)*(_t36 * _t36 * _t36));
  const double _t107 = 1.1696447245269292*_t13;
  const double _t108 = 0.039864495540000003*_t41*_t76;
  const double _t109 = 0.0065921210301623562*_t81;
  const double _t110 = -0.15279835421999999*_t56 + 0.23615562998999998*_t57 - 0.12260679726399999;
  const double _t111 = _t39*_t42;
  const double _t112 = _t110*_t111*_t74;
  const double _t113 = _t42*_t67;
  const double _t114 = _t110*_t113;
  const double _t115 = _t113*_t58;
  const double _t116 = 0.2e1*_t2*_t58*_t76;
  const double _t117 = _t14*(-0.044594587781999998*_t56 + 0.1748976233*_t57 - 0.067103136792000001);
  const double _t118 = _t34*_t69*_t70;
  const double _t119 = _t117*_t118;
  const double _t120 = _t118*_t14*_t61;
  const double _t121 = _t117*_t80;
  const double _t122 = _t37*_t78;
  const double _t123 = _t107*_t122*_t61*_t79;
  const double _t124 = _t2*_t64*_t65/xc_powi(_t6, 5);
  const double _t125 = _t124*(-0.61119341687999995*_t28 - 0.94462251995999991*_t29 - 0.24521359452799998*rs - 0.89232796256000002);
  const double _t126 = _t124*_t75;
  const double _t127 = _t14*_t71/xc_powi(_t10, 5);
  const double _t128 = _t127*(-0.17837835112799999*_t28 - 0.6995904932*_t29 - 0.134206273584*rs - 0.48946341912000002);
  const double _t129 = _t127*_t78;
  const double _t130 = _t111*_t66*_t75*(-0.45839506265999996*_t28 - 0.70846688996999996*_t29 - 0.18391019589599999*rs - 0.66924597192000002);
  const double _t131 = _t122*_t14*_t34*_t69*(-0.13378376334600001*_t28 - 0.52469286989999997*_t29 - 0.100654705188*rs - 0.36709756434000002);
  const double _t132 = _t90*(-0.15698627151*_t56 + 0.219483242115*_t57 - 0.077747891675999992);
  const double _t133 = _t86*_t87;
  const double _t134 = _t18*_t88/xc_powi(_t19, 5);
#endif

  const double f = -_hc0[0]*_t15 + _hc0[0]*_t23 + _t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = -_hc0[1]*_t15 + _hc0[1]*_t23 + _t25*_t26;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t27 + _hc0[0]*_t45 - _hc0[0]*_t48 + _t43;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = -_hc0[2]*_t15 + _hc0[2]*_t23 + _t25*_t52 + _t49*_t51;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t27 + _hc0[1]*_t45 - _hc0[1]*_t48 + _t26*_t53;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[0]*_t55 - _hc0[0]*_t63 + _hc0[0]*_t73 - _hc0[0]*_t82 + _hc0[0]*_t95 + _t1*_t68 - _t54 + _t60 + _t77;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = 0.36e2*_hc0[1]*_t22*_t50 + 0.12e2*_hc0[2]*_t25 - _hc0[3]*_t15 + _hc0[3]*_t23 + 0.24e2*_t49*zeta;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc0[0]*_t44*_t51 + _hc0[2]*_t27 + _hc0[2]*_t45 - _hc0[2]*_t48 + _t52*_t53;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc0[1]*_t55 - _hc0[1]*_t63 + _hc0[1]*_t73 - _hc0[1]*_t82 + _hc0[1]*_t95 + _t24*_t26*_t94;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = -_hc0[0]*_t102 - _hc0[0]*_t103 - _hc0[0]*_t106*_t107 + _hc0[0]*_t109 + _hc0[0]*_t119 + _hc0[0]*_t120 - _hc0[0]*_t121 - _hc0[0]*_t123 + _hc0[0]*_t128 + _hc0[0]*_t129 - _hc0[0]*_t131 + _hc0[0]*_t16*(-_t100 - _t101 + _t102 + _t103 + _t104*_t105 + _t106*(-0.0043947473534415708*rs - 0.039503346997227602) + _t108 - _t109 - _t112 + _t114 + _t115 - _t116 - _t119 - _t120 + _t121 + _t123 + _t125 + _t126 - _t128 - _t129 - _t130 + _t131 - _t132*_t133 + _t132*_t33*_t91 - _t133*_t84*_t90 - _t134*_t92 - _t134*(-0.62794508603999999*_t28 - 0.87793296846000002*_t29 - 0.15549578335199998*rs - 0.77076332556000005) + _t18*_t83*(0.039246567877499999*_t98 - 0.16461243158625*_t99) + 0.2e1*_t18*_t84*_t93 - 0.019165551108000001*_t30*_t93 + _t33*_t86*_t90*_t92*(-0.47095881452999999*_t28 - 0.65844972634499999*_t29 - 0.11662183751399999*rs - 0.57807249417000006) - 0.019165551108000001*_t85 + 0.019165551108000001*_t89 + _t96 - _t97 + (_t30 * _t30 * _t30)*(-0.012777034071999999*rs - 0.062181399999999998)/(xc_powi(_t19, 6)*(_t32 * _t32 * _t32))) + _hc0[0]*_t97 + _t100 + _t101 - _t104*_t105 - _t108 + _t112 - _t114 - _t115 + _t116 - _t125 - _t126 + _t130 - _t96;
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeta_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  const double _t1 = 0.0066724550603149224*rs + 0.06672455060314922;
  const double _t2 = 0.17780000000000001*rs + 0.1e1;
  const double _t3 = (0.1e1 / _t2);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (_t2 * _t2));
#endif
#if _KMAX >= 2
  const double _t5 = (0.1e1 / (_t2 * _t2 * _t2));
#endif

  const double f = _t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_drs = -0.17780000000000001*_t1*_t4 + 0.0066724550603149224*_t3;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = 0;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = 0.063225680000000006*_t1*_t5 - 0.0023727250194479866*_t4;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = 0;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = 0;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = -0.033724577712000006*_t1/(_t2 * _t2 * _t2 * _t2) + 0.0012656115253735561*_t5;
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tp_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
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
  const double _t11 = (0.1e1 / 0.16e2)/xc_powr(rs, 3, 2);
  const double _t12 = _t11*_t3;
#endif
#if _KMAX >= 2
  const double _t13 = -0.1e1 / 0.2e1*_hc0[5] - 0.1e1 / 0.2e1*_hc1[5];
  const double _t14 = _t13*_t9;
  const double _t15 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t16 = -_hc0[2] + _hc1[2];
  const double _t17 = _t1*_t15*_t16;
  const double _t18 = _t5*_t7;
  const double _t19 = _t17*_t18;
  const double _t20 = _t11*_t8;
  const double _t21 = _t20*_t7;
  const double _t22 = (0.3e1 / 0.32e2)/xc_powr(rs, 5, 2);
  const double _t23 = _t22*_t3;
#endif
#if _KMAX >= 3
  const double _t24 = _t13*xt;
  const double _t25 = _t1*_t18*xt;
  const double _t26 = _t7*xt;
#endif

  const double f = _t6*xt;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t6;
  out[1] = df_dxt;
  const double df_dz = _t10*xt;
  out[2] = df_dz;
  const double df_drs = -_t12*xt;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = 0;
  out[4] = d2f_dxt2;
  const double d2f_dz_dxt = _t10;
  out[5] = d2f_dz_dxt;
  const double d2f_dz2 = _t14*xt + _t19*xt;
  out[6] = d2f_dz2;
  const double d2f_drs_dxt = -_t12;
  out[7] = d2f_drs_dxt;
  const double d2f_drs_dz = -_t21*xt;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _t23*xt;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0;
  out[10] = d3f_dxt3;
  const double d3f_dz_dxt2 = 0;
  out[11] = d3f_dz_dxt2;
  const double d3f_dz2_dxt = _t14 + _t19;
  out[12] = d3f_dz2_dxt;
  const double d3f_dz3 = _t15*_t25*(-_hc0[5] - _hc1[5]) + _t16*_t25*(-0.3e1 / 0.2e1*_hc0[2] + (0.3e1 / 0.2e1)*_hc1[2])/(_t2 * _t2 * _t2 * _t2) + (0.1e1 / 0.4e1)*_t17*_t24*_t4 + _t9*xt*(-0.1e1 / 0.2e1*_hc0[9] + (0.1e1 / 0.2e1)*_hc1[9]);
  out[13] = d3f_dz3;
  const double d3f_drs_dxt2 = 0;
  out[14] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxt = -_t21;
  out[15] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = -_t11*_t17*_t26 - _t20*_t24;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dxt = _t23;
  out[17] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _t22*_t26*_t8;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = -0.15e2 / 0.64e2*_t3*xt/xc_powr(rs, 7, 2);
  out[19] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(A_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc2);
  double _hc3[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, rs, 0, _hc3);
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
  const double _t23 = (M_PI * M_PI * M_PI * M_PI);
  const double _t24 = (0.1e1 / (_t4 * _t4));
  const double _t25 = _t2*_t23*_t24;
  const double _t26 = _t22*_t25;
#endif
#if _KMAX >= 2
  const double _t27 = (_t18 * _t18);
  const double _t28 = _t11*_t19;
  const double _t29 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t30 = (_t10 * _t10);
  const double _t31 = _hc2[3]*_t7;
  const double _t32 = -0.3e1 / 0.2e1*_hc0[5] - 0.3e1 / 0.2e1*_hc1[5];
  const double _t33 = _t16*_t32;
  const double _t34 = _hc2[1]*_t15;
  const double _t35 = 0.2e1*_t13;
  const double _t36 = xc_powi(_t1, -5);
  const double _t37 = -0.2e1*_hc0[2] + 0.2e1*_hc1[2];
  const double _t38 = _t13*_t36*_t37;
  const double _t39 = _hc2[0]*_t6;
  const double _t40 = -_t31 - _t33 - _t34*_t35 - _t38*_t39;
  const double _t41 = _t21*_t25;
  const double _t42 = _t14*_t23*_t24;
  const double _t43 = _t22*_t42;
  const double _t44 = _hc3[2]*_t6;
  const double _t45 = _t11*_t18;
  const double _t46 = _hc2[2]*_t25;
  const double _t47 = _hc3[0]*_t45;
  const double _t48 = _t29*_t30;
  const double _t49 = 0.2e1*_t48;
  const double _t50 = _hc3[0]*_t49;
  const double _t51 = _t46*_t50;
  const double _t52 = _t18*_t51;
  const double _t53 = _hc3[2]*_t11;
  const double _t54 = 0.2e1*_t53;
  const double _t55 = ((_hc2[2]) * (_hc2[2]));
  const double _t56 = xc_powi(M_PI, 6);
  const double _t57 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t58 = xc_powi(_t1, -6);
  const double _t59 = _t56*_t57*_t58;
  const double _t60 = _t55*_t59;
  const double _t61 = _t50*_t60;
#endif
#if _KMAX >= 3
  const double _t62 = (_t18 * _t18 * _t18);
  const double _t63 = 0.6e1*(_t10 * _t10 * _t10)/(_t8 * _t8 * _t8 * _t8);
  const double _t64 = -0.2e1*_t12 - 0.2e1*_t17;
  const double _t65 = 0.4e1*_t13;
  const double _t66 = _t36*_t39;
  const double _t67 = _t37*_t66;
  const double _t68 = -0.2e1*_t31 - 0.2e1*_t33 - _t34*_t65 - _t35*_t67;
  const double _t69 = _t21*_t42;
  const double _t70 = _t11*_t44;
  const double _t71 = _t27*_t49;
  const double _t72 = _hc2[4]*_t25;
  const double _t73 = _hc3[0]*_t18;
  const double _t74 = 0.4e1*_t48;
  const double _t75 = _hc3[0]*_t46;
  const double _t76 = _hc2[2]*_t42;
  const double _t77 = _t35*_t76;
  const double _t78 = _hc2[4]*_t59;
  const double _t79 = _hc2[2]*_hc3[0];
  const double _t80 = _t55*_t56*_t57*(-0.3e1*_hc0[2] + 0.3e1*_hc1[2])/xc_powi(_t1, 7);
  const double _t81 = _hc2[5]*_t25;
  const double _t82 = _hc3[2]*_t46;
  const double _t83 = 0.3e1*_t53;
  const double _t84 = xc_powi(M_PI, 8)*((_hc2[2]) * (_hc2[2]) * (_hc2[2]))/(xc_powi(_t1, 9)*(_t4 * _t4 * _t4 * _t4));
  const double _t85 = _hc2[5]*_t59;
  const double _t86 = 0.6e1*_t48;
  const double _t87 = _hc3[0]*_t84;
#endif

  const double f = _hc3[0]*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_dz = -_t20;
  out[2] = df_dz;
  const double df_drs = _hc3[2]*_t9 + _t26;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = 0;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = 0.2e1*_hc3[0]*_t27*_t29*_t3*_t30*_t5 - _t27*_t28 - _t28*_t40;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = 0;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _hc2[4]*_t41 + _t13*_t43 - _t44*_t45 + _t46*_t47 - _t52;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc2[5]*_t41 + _hc3[5]*_t9 - _t21*_t60 + _t46*_t54 + _t61;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = 0;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = 0;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = 0.2e1*_hc3[0]*_t18*_t29*_t3*_t30*_t40*_t5 + 0.2e1*_hc3[0]*_t18*_t29*_t3*_t30*_t5*_t68 + 0.2e1*_hc3[0]*_t27*_t29*_t3*_t30*_t5*_t64 + 0.2e1*_hc3[0]*_t29*_t3*_t30*_t5*_t62 - _t19*_t62*_t63 - _t20*_t40 - _t20*_t68 - _t28*_t62 - _t28*(-0.3e1*_hc2[1]*_t38*_t6 - 0.3e1*_hc2[3]*_t13*_t15 - _hc2[6]*_t7 - _t13*_t37*_t39*_t58*(-0.5e1 / 0.2e1*_hc0[2] + (0.5e1 / 0.2e1)*_hc1[2]) - _t13*_t66*(-0.2e1*_hc0[5] - 0.2e1*_hc1[5]) - _t16*(-0.3e1 / 0.2e1*_hc0[9] + (0.3e1 / 0.2e1)*_hc1[9]) - 0.3e1*_t32*_t34 - 0.2e1*_t32*_t67);
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = 0;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = 0;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _hc2[4]*_t35*_t69 + _hc2[7]*_t41 + _t22*_t23*_t24*_t38 + _t26*_t27 + _t26*_t40 + _t27*_t63*_t75 - _t27*_t70 + _t32*_t43 - _t40*_t51 - _t40*_t70 + _t44*_t71 + 0.2e1*_t47*_t72 + _t47*_t77 - _t48*_t65*_t73*_t76 - _t52*_t64 - _t71*_t75 - _t72*_t73*_t74;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = 0;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _hc2[5]*_t13*_t69 + _hc2[8]*_t41 - _hc3[5]*_t45*_t6 - _t18*_t50*_t81 + _t18*_t61 - _t18*_t74*_t82 - _t21*_t80 - 0.2e1*_t22*_t78 + 0.2e1*_t45*_t82 - _t47*_t60 + _t47*_t81 + _t50*_t80 + _t53*_t77 + _t54*_t72 - _t60*_t63*_t73 + _t61*_t64 + _t74*_t78*_t79;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc2[9]*_t41 + _hc3[2]*_t60*_t86 + 0.3e1*_hc3[5]*_t11*_t46 + _hc3[9]*_t9 + _t21*_t84 - 0.3e1*_t22*_t85 - _t60*_t83 + _t63*_t87 + _t79*_t85*_t86 + _t81*_t83 - _t86*_t87;
  out[19] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_e0_one_minus_g_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(A_k, _KMAX)(p, rs, z, t, _hc0);
  const double _t1 = (t * t);
  const double _t2 = 0.4e1*_t1;
  const double _t3 = _hc0[0]*_t2;
  const double _t4 = xc_expm1(-0.1e1 / 0.4e1*xc_log1p(_t3));
#if _KMAX >= 1
  const double _t5 = 0.8e1*_hc0[0];
  const double _t6 = _hc0[1]*_t2 + _t5*t;
  const double _t7 = _t3 + 0.1e1;
  const double _t8 = (0.1e1 / _t7);
  const double _t9 = _t4 + 0.1e1;
  const double _t10 = _t8*_t9;
  const double _t11 = (0.1e1 / 0.4e1)*_t10;
  const double _t12 = _t1*_t10;
#endif
#if _KMAX >= 2
  const double _t13 = (0.1e1 / (_t7 * _t7));
  const double _t14 = _t13*_t9;
  const double _t15 = (0.1e1 / 0.16e2)*(_t6 * _t6);
  const double _t16 = _hc0[1]*t;
  const double _t17 = _hc0[4]*_t2 + 0.16e2*_t16 + _t5;
  const double _t18 = -_t6;
  const double _t19 = _t14*_t18;
  const double _t20 = (0.1e1 / 0.4e1)*_t6;
  const double _t21 = 0.2e1*_t10;
  const double _t22 = _hc0[2]*_t21;
  const double _t23 = _t1*_t19;
  const double _t24 = _hc0[2]*_t14;
  const double _t25 = _t1*_t20;
  const double _t26 = ((_hc0[2]) * (_hc0[2]));
  const double _t27 = _t14*_t26;
  const double _t28 = (t * t * t * t);
  const double _t29 = 0.5e1*_t28;
  const double _t30 = _hc0[3]*_t21;
  const double _t31 = _t14*_t25;
  const double _t32 = _hc0[3]*_t24;
  const double _t33 = ((_hc0[3]) * (_hc0[3]));
  const double _t34 = _t14*_t33;
#endif
#if _KMAX >= 3
  const double _t35 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t36 = _t35*_t9;
  const double _t37 = 0.16e2*_hc0[0];
  const double _t38 = 0.8e1*_t1;
  const double _t39 = -_hc0[1]*_t38 - _t37*t;
  const double _t40 = _t15*_t36;
  const double _t41 = -_t14*_t17;
  const double _t42 = _t14*_t6;
  const double _t43 = (0.1e1 / 0.16e2)*_t42;
  const double _t44 = _t36*_t39;
  const double _t45 = _t18*_t44;
  const double _t46 = 0.4e1*t;
  const double _t47 = _t10*_t46;
  const double _t48 = _t19*_t46;
  const double _t49 = _t42*t;
  const double _t50 = 0.2e1*_t23;
  const double _t51 = (0.1e1 / 0.2e1)*_t1*_t42;
  const double _t52 = _hc0[2]*_t1;
  const double _t53 = _t1*_t41;
  const double _t54 = (0.1e1 / 0.4e1)*_t1*_t17;
  const double _t55 = _hc0[2]*_t25;
  const double _t56 = _t18*_t36;
  const double _t57 = _t21*t;
  const double _t58 = _t24*_t28;
  const double _t59 = 0.10e2*_t58;
  const double _t60 = 0.20e2*(t * t * t);
  const double _t61 = _t29*_t44;
  const double _t62 = (0.5e1 / 0.4e1)*_t28*_t36*_t6;
  const double _t63 = 0.45e2*_t36*xc_powi(t, 6);
  const double _t64 = _hc0[3]*_t1;
  const double _t65 = _hc0[3]*_t14;
  const double _t66 = _hc0[3]*_t25;
  const double _t67 = _t24*_t29;
  const double _t68 = _t29*_t65;
  const double _t69 = _t28*_t65;
  const double _t70 = 0.10e2*_t69;
#endif

  const double f = -_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t11*_t6;
  out[1] = df_dt;
  const double df_dz = _hc0[2]*_t12;
  out[2] = df_dz;
  const double df_drs = _hc0[3]*_t12;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t11*_t17 - _t14*_t15 + _t19*_t20;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = _hc0[2]*_t23 + _hc0[5]*_t12 + _t22*t - _t24*_t25;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = _hc0[6]*_t1*_t8*_t9 - _t27*_t29;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = _hc0[3]*_t23 - _hc0[3]*_t31 + _hc0[7]*_t12 + _t30*t;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _hc0[8]*_t1*_t8*_t9 - _t29*_t32;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[9]*_t1*_t8*_t9 - _t29*_t34;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t11*(0.24e2*_hc0[1] + _hc0[10]*_t2 + 0.24e2*_hc0[4]*t) + (0.1e1 / 0.2e1)*_t17*_t19 - _t17*_t43 - _t18*_t40 + _t20*_t41 + _t20*_t45 + (0.1e1 / 0.64e2)*_t36*(_t6 * _t6 * _t6) - _t39*_t40 - _t43*(_hc0[4]*_t38 + 0.32e2*_t16 + _t37);
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = _hc0[11]*_t12 + _hc0[2]*_t48 - _hc0[2]*_t49 + _hc0[2]*_t53 + _hc0[5]*_t47 + _hc0[5]*_t50 - _hc0[5]*_t51 + _t22 - _t24*_t54 + _t40*_t52 - _t44*_t55 + _t45*_t52 - _t55*_t56;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = _hc0[12]*_t12 - _hc0[5]*_t59 + _hc0[6]*_t23 - _hc0[6]*_t31 + _hc0[6]*_t57 - _t26*_t61 + _t26*_t62 - _t27*_t60;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = _hc0[13]*_t12 + ((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t63 - 0.15e2*_hc0[6]*_t58;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = _hc0[14]*_t12 + _hc0[3]*_t48 - _hc0[3]*_t49 + _hc0[3]*_t53 + _hc0[7]*_t47 + _hc0[7]*_t50 - _hc0[7]*_t51 + _t30 + _t40*_t64 - _t44*_t66 + _t45*_t64 - _t54*_t65 - _t56*_t66;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = _hc0[15]*_t1*_t8*_t9 + (0.5e1 / 0.4e1)*_hc0[2]*_hc0[3]*_t28*_t35*_t6*_t9 - _hc0[2]*_hc0[3]*_t61 - _hc0[5]*_t68 - _hc0[7]*_t67 + _hc0[8]*_t1*_t13*_t18*_t9 - _hc0[8]*_t31 + 0.2e1*_hc0[8]*_t8*_t9*t - _t32*_t60;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _hc0[16]*_t12 + _hc0[3]*_t26*_t63 - _hc0[6]*_t68 - _hc0[8]*_t59;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = _hc0[17]*_t12 - _hc0[7]*_t70 + _hc0[9]*_t23 - _hc0[9]*_t31 + _hc0[9]*_t57 - _t33*_t61 + _t33*_t62 - _t34*_t60;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _hc0[18]*_t12 + _hc0[2]*_t33*_t63 - _hc0[8]*_t70 - _hc0[9]*_t67;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[19]*_t12 + ((_hc0[3]) * (_hc0[3]) * (_hc0[3]))*_t63 - 0.15e2*_hc0[9]*_t69;
  out[19] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f2_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(A_k, _KMAX)(p, rs, z, t, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, rs, 0, _hc1);
  double _hc2[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(scan_e0_one_minus_g_k, _KMAX)(p, rs, z, t, _hc2);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = (M_PI * M_PI);
  const double _t3 = (0.1e1 / (0.1e1 - M_LN2));
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
  const double _t6 = _hc1[0]*_t5;
#if _KMAX >= 1
  const double _t7 = _t4/((_hc0[0]) * (_hc0[0]));
  const double _t8 = _hc1[0]*_t7;
  const double _t9 = _hc0[1]*_hc2[0];
  const double _t10 = _hc2[0]*_t8;
  const double _t11 = _hc1[2]*_t5;
#endif
#if _KMAX >= 2
  const double _t12 = _hc0[1]*_t8;
  const double _t13 = 0.2e1*_t12;
  const double _t14 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t15 = 0.2e1*_t14;
  const double _t16 = ((_hc0[1]) * (_hc0[1]));
  const double _t17 = _hc1[0]*_t4;
  const double _t18 = _hc2[0]*_t17;
  const double _t19 = _t16*_t18;
  const double _t20 = _hc2[1]*_t8;
  const double _t21 = _hc0[2]*_t8;
  const double _t22 = 0.2e1*_t21;
  const double _t23 = ((_hc0[2]) * (_hc0[2]));
  const double _t24 = _t15*_t18;
  const double _t25 = _hc1[2]*_t7;
  const double _t26 = _hc2[0]*_t25;
  const double _t27 = _hc2[2]*_t8;
  const double _t28 = _hc1[5]*_t5;
  const double _t29 = _hc0[3]*_t8;
  const double _t30 = 0.2e1*_hc2[3];
  const double _t31 = 0.2e1*_hc0[3];
  const double _t32 = ((_hc0[3]) * (_hc0[3]));
#endif
#if _KMAX >= 3
  const double _t33 = 0.6e1/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t34 = _t18*_t33;
  const double _t35 = 0.2e1*_hc0[5];
  const double _t36 = _t19*_t33;
  const double _t37 = _t33*_t9;
  const double _t38 = _hc2[3]*_t8;
  const double _t39 = _hc0[1]*_t25;
  const double _t40 = 0.2e1*_hc0[7];
  const double _t41 = _hc0[2]*_t25;
  const double _t42 = 0.2e1*_hc0[8];
  const double _t43 = _hc1[5]*_t7;
  const double _t44 = 0.2e1*_t29;
  const double _t45 = _t25*_t31;
  const double _t46 = _t17*_t32;
  const double _t47 = _hc2[0]*_t43;
  const double _t48 = 0.3e1*_hc2[9];
  const double _t49 = 0.3e1*_hc0[9];
  const double _t50 = 0.6e1*_t14;
#endif

  const double f = _hc2[0]*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc2[1]*_t6 - _t8*_t9;
  out[1] = df_dt;
  const double df_dz = -_hc0[2]*_t10 + _hc2[2]*_t6;
  out[2] = df_dz;
  const double df_drs = -_hc0[3]*_t10 + _hc2[0]*_t11 + _hc2[3]*_t6;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_hc0[4]*_t10 - _hc2[1]*_t13 + _hc2[4]*_t6 + _t15*_t19;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = 0.2e1*_hc0[1]*_hc0[2]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[2]*_t20 - _hc0[5]*_t10 + _hc1[0]*_hc2[5]*_t1*_t2*_t3 - _hc2[2]*_t12;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = -_hc0[6]*_t10 - _hc2[2]*_t22 + _hc2[6]*_t6 + _t23*_t24;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = 0.2e1*_hc0[1]*_hc0[3]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[3]*_t20 - _hc0[7]*_t10 + _hc1[0]*_hc2[7]*_t1*_t2*_t3 + _hc1[2]*_hc2[1]*_t1*_t2*_t3 - _hc2[3]*_t12 - _t25*_t9;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = 0.2e1*_hc0[2]*_hc0[3]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[2]*_t26 - _hc0[3]*_t27 - _hc0[8]*_t10 + _hc1[0]*_hc2[8]*_t1*_t2*_t3 + _hc1[2]*_hc2[2]*_t1*_t2*_t3 - _hc2[3]*_t21;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = -_hc0[9]*_t10 + _hc2[0]*_t28 + 0.2e1*_hc2[3]*_t11 + _hc2[9]*_t6 + _t24*_t32 - _t26*_t31 - _t29*_t30;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = -((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t34 + 0.6e1*_hc0[1]*_hc0[4]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[10]*_t10 - 0.3e1*_hc0[4]*_t20 + 0.6e1*_hc1[0]*_hc2[1]*_t14*_t16*_t2*_t3 + _hc1[0]*_hc2[10]*_t1*_t2*_t3 - 0.3e1*_hc2[4]*_t12;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = 0.4e1*_hc0[1]*_hc0[2]*_hc1[0]*_hc2[1]*_t14*_t2*_t3 + 0.4e1*_hc0[1]*_hc0[5]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[11]*_t10 + 0.2e1*_hc0[2]*_hc0[4]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[2]*_t36 - _hc0[4]*_t27 + _hc1[0]*_hc2[11]*_t1*_t2*_t3 + 0.2e1*_hc1[0]*_hc2[2]*_t14*_t16*_t2*_t3 - _hc2[4]*_t21 - _hc2[5]*_t13 - _t20*_t35;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = 0.4e1*_hc0[1]*_hc0[2]*_hc1[0]*_hc2[2]*_t14*_t2*_t3 + 0.2e1*_hc0[1]*_hc0[6]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[12]*_t10 + 0.4e1*_hc0[2]*_hc0[5]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[6]*_t20 + 0.2e1*_hc1[0]*_hc2[1]*_t14*_t2*_t23*_t3 + _hc1[0]*_hc2[12]*_t1*_t2*_t3 - _hc2[5]*_t22 - _hc2[6]*_t12 - _t17*_t23*_t37 - _t27*_t35;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = -_hc0[13]*_t10 - ((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t34 + 0.6e1*_hc0[2]*_hc0[6]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - 0.3e1*_hc0[6]*_t27 + _hc1[0]*_hc2[13]*_t1*_t2*_t3 + 0.6e1*_hc1[0]*_hc2[2]*_t14*_t2*_t23*_t3 - 0.3e1*_hc2[6]*_t21;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = 0.4e1*_hc0[1]*_hc0[3]*_hc1[0]*_hc2[1]*_t14*_t2*_t3 + 0.4e1*_hc0[1]*_hc0[7]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[14]*_t10 + 0.2e1*_hc0[3]*_hc0[4]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[3]*_t36 - _hc0[4]*_t26 - _hc0[4]*_t38 + _hc1[0]*_hc2[14]*_t1*_t2*_t3 + 0.2e1*_hc1[0]*_hc2[3]*_t14*_t16*_t2*_t3 + 0.2e1*_hc1[2]*_hc2[0]*_t14*_t16*_t2*_t3 + _hc1[2]*_hc2[4]*_t1*_t2*_t3 - 0.2e1*_hc2[1]*_t39 - _hc2[4]*_t29 - _hc2[7]*_t13 - _t20*_t40;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = 0.2e1*_hc0[1]*_hc0[2]*_hc1[0]*_hc2[3]*_t14*_t2*_t3 + 0.2e1*_hc0[1]*_hc0[2]*_hc1[2]*_hc2[0]*_t14*_t2*_t3 + 0.2e1*_hc0[1]*_hc0[3]*_hc1[0]*_hc2[2]*_t14*_t2*_t3 + 0.2e1*_hc0[1]*_hc0[8]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[15]*_t10 + 0.2e1*_hc0[2]*_hc0[3]*_hc1[0]*_hc2[1]*_t14*_t2*_t3 - _hc0[2]*_hc0[3]*_t17*_t33*_t9 + 0.2e1*_hc0[2]*_hc0[7]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 + 0.2e1*_hc0[3]*_hc0[5]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[5]*_t26 - _hc0[5]*_t38 - _hc0[7]*_t27 - _hc0[8]*_t20 + _hc1[0]*_hc2[15]*_t1*_t2*_t3 + _hc1[2]*_hc2[5]*_t1*_t2*_t3 - _hc2[1]*_t41 - _hc2[2]*_t39 - _hc2[5]*_t29 - _hc2[7]*_t21 - _hc2[8]*_t12;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = -_hc0[16]*_t10 + 0.4e1*_hc0[2]*_hc0[3]*_hc1[0]*_hc2[2]*_t14*_t2*_t3 + 0.4e1*_hc0[2]*_hc0[8]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 + 0.2e1*_hc0[3]*_hc0[6]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[3]*_t23*_t34 - _hc0[6]*_t26 - _hc0[6]*_t38 + _hc1[0]*_hc2[16]*_t1*_t2*_t3 + 0.2e1*_hc1[0]*_hc2[3]*_t14*_t2*_t23*_t3 + 0.2e1*_hc1[2]*_hc2[0]*_t14*_t2*_t23*_t3 + _hc1[2]*_hc2[6]*_t1*_t2*_t3 - 0.2e1*_hc2[2]*_t41 - _hc2[6]*_t29 - _hc2[8]*_t22 - _t27*_t42;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = 0.4e1*_hc0[1]*_hc0[3]*_hc1[0]*_hc2[3]*_t14*_t2*_t3 + 0.4e1*_hc0[1]*_hc0[3]*_hc1[2]*_hc2[0]*_t14*_t2*_t3 + 0.2e1*_hc0[1]*_hc0[9]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[17]*_t10 + 0.4e1*_hc0[3]*_hc0[7]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[9]*_t20 + 0.2e1*_hc1[0]*_hc2[1]*_t14*_t2*_t3*_t32 + _hc1[0]*_hc2[17]*_t1*_t2*_t3 + 0.2e1*_hc1[2]*_hc2[7]*_t1*_t2*_t3 + _hc1[5]*_hc2[1]*_t1*_t2*_t3 - _hc2[1]*_t45 - _hc2[7]*_t44 - _hc2[9]*_t12 - _t26*_t40 - _t30*_t39 - _t37*_t46 - _t38*_t40 - _t43*_t9;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = -_hc0[18]*_t10 + 0.4e1*_hc0[2]*_hc0[3]*_hc1[0]*_hc2[3]*_t14*_t2*_t3 + 0.4e1*_hc0[2]*_hc0[3]*_hc1[2]*_hc2[0]*_t14*_t2*_t3 + 0.2e1*_hc0[2]*_hc0[9]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[2]*_t32*_t34 - _hc0[2]*_t47 + 0.4e1*_hc0[3]*_hc0[8]*_hc1[0]*_hc2[0]*_t14*_t2*_t3 - _hc0[9]*_t27 + _hc1[0]*_hc2[18]*_t1*_t2*_t3 + 0.2e1*_hc1[0]*_hc2[2]*_t14*_t2*_t3*_t32 + 0.2e1*_hc1[2]*_hc2[8]*_t1*_t2*_t3 + _hc1[5]*_hc2[2]*_t1*_t2*_t3 - _hc2[2]*_t45 - _hc2[8]*_t44 - _hc2[9]*_t21 - _t26*_t42 - _t30*_t41 - _t38*_t42;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = -_hc0[19]*_t10 - ((_hc0[3]) * (_hc0[3]) * (_hc0[3]))*_t34 + _hc0[3]*_hc0[9]*_t18*_t50 - 0.6e1*_hc0[3]*_hc2[3]*_t25 - 0.3e1*_hc0[3]*_t47 + _hc1[2]*_hc2[0]*_t32*_t4*_t50 + _hc1[9]*_hc2[0]*_t5 + _hc2[19]*_t6 + 0.3e1*_hc2[3]*_t28 + _hc2[3]*_t46*_t50 + _t11*_t48 - _t26*_t49 - _t29*_t48 - _t38*_t49;
  out[19] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fH_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
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
  const double _t20 = _t19*_t9;
  const double _t21 = ((_hc2[2]) * (_hc2[2]));
  const double _t22 = (0.3e1 / 0.2e1)*_hc0[5] + (0.3e1 / 0.2e1)*_hc1[5];
  const double _t23 = _hc0[2] - _hc1[2];
  const double _t24 = _t1*_t11*_t23*_t6;
  const double _t25 = 0.2e1*_t20;
  const double _t26 = _hc2[2]*_t17;
  const double _t27 = ((_hc2[3]) * (_hc2[3]));
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t29 = 0.2e1*_t28*_t7;
  const double _t30 = 0.2e1*_hc2[5];
  const double _t31 = _t15*_t29;
  const double _t32 = _t16*_t19;
  const double _t33 = _t21*_t29;
  const double _t34 = _hc2[1]*_t9;
  const double _t35 = _t13*_t22;
  const double _t36 = _hc2[1]*_t32;
  const double _t37 = 0.2e1*_hc2[2];
  const double _t38 = _t11*_t2*_t6;
  const double _t39 = _t23*_t38;
  const double _t40 = 0.3e1*_hc2[6];
  const double _t41 = _t35*_t9;
  const double _t42 = 0.3e1*_hc2[2];
  const double _t43 = _t39*_t9;
  const double _t44 = 0.2e1*_hc2[7];
  const double _t45 = _hc2[3]*_t17;
  const double _t46 = 0.2e1*_hc2[8];
  const double _t47 = _t27*_t29;
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
  const double d2f_dz_dt = _hc2[1]*_t20 - _hc2[2]*_t18 + _hc2[5]*_t10;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = _hc2[2]*_t25 + _hc2[6]*_t10 + _t14*_t22 - _t17*_t21 + _t2*_t24;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = -_hc2[3]*_t18 + _hc2[7]*_t3*_t4*_t5*_t9;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = _hc2[3]*_t20 - _hc2[3]*_t26 + _hc2[8]*_t10;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc2[9]*_t3*_t4*_t5*_t9 - _t17*_t27;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t29 + _hc2[10]*_t10 - 0.3e1*_hc2[4]*_t18;
  out[10] = d3f_dt3;
  const double d3f_dz_dt2 = _hc2[11]*_t10 + _hc2[2]*_t31 + _hc2[4]*_t20 - _hc2[4]*_t26 - _t15*_t32 - _t18*_t30;
  out[11] = d3f_dz_dt2;
  const double d3f_dz2_dt = _hc2[1]*_t33 + _hc2[12]*_t10 + _hc2[5]*_t25 - _hc2[6]*_t18 - _t26*_t30 + _t34*_t35 + _t34*_t39 - _t36*_t37;
  out[12] = d3f_dz2_dt;
  const double d3f_dz3 = _hc2[13]*_t10 + ((_hc2[2]) * (_hc2[2]) * (_hc2[2]))*_t29 + 0.2e1*_t1*_t2*_t22*_t23*_t6 + _t1*_t38*(_hc0[5] + _hc1[5]) + _t14*((0.3e1 / 0.2e1)*_hc0[9] - 0.3e1 / 0.2e1*_hc1[9]) + _t20*_t40 - 0.3e1*_t21*_t32 + _t24*((0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2]) - _t26*_t40 + _t41*_t42 + _t42*_t43;
  out[13] = d3f_dz3;
  const double d3f_drs_dt2 = _hc2[14]*_t10 + _hc2[3]*_t31 - _hc2[4]*_t45 - _t18*_t44;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dz_dt = 0.2e1*_hc2[1]*_hc2[2]*_hc2[3]*_t28*_t3*_t4*_t5 + _hc2[15]*_t3*_t4*_t5*_t9 - _hc2[3]*_t36 - _hc2[5]*_t45 + _hc2[7]*_t11*_t12*_t4*_t5*_t9 - _hc2[7]*_t26 - _hc2[8]*_t18;
  out[15] = d3f_drs_dz_dt;
  const double d3f_drs_dz2 = _hc2[16]*_t10 - _hc2[3]*_t32*_t37 + _hc2[3]*_t33 + _hc2[3]*_t41 + _hc2[3]*_t43 - _hc2[6]*_t45 + _hc2[8]*_t25 - _t26*_t46;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dt = _hc2[1]*_t47 + _hc2[17]*_t10 - _hc2[9]*_t18 - _t44*_t45;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dz = _hc2[18]*_t10 + _hc2[2]*_t47 + _hc2[9]*_t20 - _hc2[9]*_t26 - _t27*_t32 - _t45*_t46;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc2[19]*_t10 + ((_hc2[3]) * (_hc2[3]) * (_hc2[3]))*_t29 - 0.3e1*_hc2[9]*_t45;
  out[19] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_grad_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(tp_k, _KMAX)(p, rs, z, xt, _hc0);
  double _hc1[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(fH_k, _KMAX)(p, rs, z, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = ((_hc0[1]) * (_hc0[1]));
  const double _t2 = _hc0[2]*_hc1[4];
  const double _t3 = _hc1[5] + _t2;
  const double _t4 = _hc0[3]*_hc1[4];
  const double _t5 = _hc1[7] + _t4;
#endif
#if _KMAX >= 3
  const double _t6 = _hc0[5]*_hc1[4];
  const double _t7 = 0.2e1*_hc0[1];
  const double _t8 = _hc0[2]*_hc1[10];
  const double _t9 = _hc0[1]*_hc1[11];
  const double _t10 = _hc0[6]*_hc1[4];
  const double _t11 = _hc0[1]*_t8 + _t6 + _t9;
  const double _t12 = _hc0[2]*_hc1[11] + _hc1[12];
  const double _t13 = 0.2e1*_t3;
  const double _t14 = _hc1[11] + _t8;
  const double _t15 = _hc0[2]*_t14 + _t10 + _t12;
  const double _t16 = _hc0[7]*_hc1[4];
  const double _t17 = _hc0[3]*_hc1[10];
  const double _t18 = _hc0[2]*_hc1[14];
  const double _t19 = _hc0[8]*_hc1[4];
  const double _t20 = _hc1[15] + _t18;
  const double _t21 = _hc0[1]*_hc1[14];
  const double _t22 = _hc0[9]*_hc1[4];
  const double _t23 = _hc0[3]*_hc1[14] + _hc1[17];
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
  const double d3f_dxt3 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[10];
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
  const double d3f_dz_dxt2 = _hc1[11]*_t1 + _t1*_t8 + _t6*_t7;
  out[36] = d3f_dz_dxt2;
  const double d3f_dz2_dxs1 = 0;
  out[37] = d3f_dz2_dxs1;
  const double d3f_dz2_dxs0 = 0;
  out[38] = d3f_dz2_dxs0;
  const double d3f_dz2_dxt = _hc0[1]*_hc1[12] + _hc0[1]*_t10 + _hc0[12]*_hc1[1] + _hc0[2]*_t11 + _hc0[2]*_t9 + _hc0[5]*_hc1[5] + _hc0[5]*_t3;
  out[39] = d3f_dz2_dxt;
  const double d3f_dz3 = _hc0[13]*_hc1[1] + _hc0[2]*_hc1[12] + _hc0[2]*_t12 + _hc0[2]*_t15 + _hc0[6]*_hc1[5] + _hc0[6]*_t13 + _hc1[13];
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
  const double d3f_drs_dxt2 = _hc1[14]*_t1 + _t1*_t17 + _t16*_t7;
  out[46] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxs1 = 0;
  out[47] = d3f_drs_dz_dxs1;
  const double d3f_drs_dz_dxs0 = 0;
  out[48] = d3f_drs_dz_dxs0;
  const double d3f_drs_dz_dxt = _hc0[1]*_hc1[15] + _hc0[1]*_t18 + _hc0[1]*_t19 + _hc0[15]*_hc1[1] + _hc0[3]*_t11 + _hc0[5]*_hc1[7] + _hc0[7]*_t3;
  out[49] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = _hc0[16]*_hc1[1] + _hc0[2]*_hc1[15] + _hc0[2]*_t20 + _hc0[3]*_t15 + _hc0[6]*_hc1[7] + _hc0[8]*_t13 + _hc1[16];
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dxs1 = 0;
  out[51] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[52] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = _hc0[1]*_hc1[17] + _hc0[1]*_t22 + _hc0[17]*_hc1[1] + _hc0[3]*_t21 + _hc0[3]*(_hc0[1]*_t17 + _t16 + _t21) + _hc0[7]*_hc1[7] + _hc0[7]*_t5;
  out[53] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _hc0[18]*_hc1[1] + _hc0[2]*_hc1[17] + _hc0[3]*_t20 + _hc0[3]*(_hc0[3]*_t14 + _t19 + _t20) + _hc0[8]*_hc1[7] + _hc0[8]*_t5 + _hc0[9]*_t3 + _hc1[18];
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[19]*_hc1[1] + _hc0[3]*_hc1[17] + _hc0[3]*_t23 + _hc0[3]*(_hc0[3]*(_hc1[14] + _t17) + _t22 + _t23) + _hc0[9]*_hc1[7] + 0.2e1*_hc0[9]*_t5 + _hc1[19];
  out[55] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_pbe_grad_k, _KMAX)(p, rs, z, xt, 0, 0, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
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
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_eclda0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(rs, 1, 2);
  const double _t2 = 0.088900000000000007*_t1 + 0.12554100000000001*rs + 0.1e1;
#if _KMAX >= 1
  const double _t3 = (0.1e1 / (_t2 * _t2));
  const double _t4 = (0.1e1 / _t1);
  const double _t5 = -0.044450000000000003*_t4 - 0.12554100000000001;
  const double _t6 = 0.028576399999999998*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = xc_powr(rs, -3, 2);
  const double _t8 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t9 = -0.088900000000000007*_t4 - 0.25108200000000003;
  const double _t10 = _t8*_t9;
#endif
#if _KMAX >= 3
  const double _t11 = 0.0012702209800000001*_t7;
#endif

  const double f = -0.028576399999999998/_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t3*_t6;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -_t10*_t6 - 0.00063511049000000003*_t3*_t7;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -_t10*_t11 - _t11*_t5*_t8 + 0.00095266573499999999*_t3/xc_powr(rs, 5, 2) - _t6*_t9*(-0.13335000000000002*_t4 - 0.37662300000000004)/(_t2 * _t2 * _t2 * _t2);
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_one_minus_g_infty_k, _KMAX)(const xc_func_type *p, double s, double *out) {

  const double _t1 = (s * s);
  const double _t2 = 0.5121034105050326*_t1;
  const double _t3 = xc_expm1(-0.1e1 / 0.4e1*xc_log1p(_t2));
#if _KMAX >= 1
  const double _t4 = _t2 + 0.1e1;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t3 + 0.1e1;
#endif
#if _KMAX >= 2
  const double _t7 = _t6/(_t4 * _t4);
#endif

  const double f = -_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = 0.2560517052525163*_t5*_t6*s;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = -0.32781237881360742*_t1*_t7 + 0.2560517052525163*_t5*_t6;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = -0.98343713644082225*_t7*s + 0.75543226738297223*_t6*(s * s * s)/(_t4 * _t4 * _t4);
  out[3] = d3f_ds3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_H0_k, _KMAX)(const xc_func_type *p, double rs, double s, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_one_minus_g_infty_k, _KMAX)(p, s, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_eclda0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = xc_expm1(-34.99391105947565*_hc1[0]);
  const double _t2 = _hc0[0]*_t1;
#if _KMAX >= 1
  const double _t3 = _t2 + 0.1e1;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _hc0[1]*_t4;
  const double _t6 = 0.028576399999999998*_t1;
  const double _t7 = _t1 + 0.1e1;
  const double _t8 = 0.99999999999999989*_t7;
  const double _t9 = _hc1[1]*_t8;
  const double _t10 = _hc0[0]*_t4;
#endif
#if _KMAX >= 2
  const double _t11 = ((_hc0[1]) * (_hc0[1]));
  const double _t12 = (0.1e1 / (_t3 * _t3));
  const double _t13 = (_t1 * _t1);
  const double _t14 = _t12*_t13;
  const double _t15 = _hc0[1]*_t12*_t2;
  const double _t16 = _hc1[2]*_t8;
  const double _t17 = ((_hc1[1]) * (_hc1[1]));
  const double _t18 = 34.993911059475643*_t17;
  const double _t19 = ((_hc0[0]) * (_hc0[0]));
  const double _t20 = (_t7 * _t7);
  const double _t21 = _t12*_t20;
  const double _t22 = _t19*_t21;
#endif
#if _KMAX >= 3
  const double _t23 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t24 = _t18*_t7;
  const double _t25 = 69.987822118951286*_hc0[1]*_t17;
  const double _t26 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
#endif

  const double f = 0.028576399999999998*xc_log1p(_t2);
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = _t5*_t6;
  out[1] = df_ds;
  const double df_drs = -_t10*_t9;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = 0.028576399999999998*_hc0[2]*_t1*_t4 - 0.028576399999999998*_t11*_t14;
  out[3] = d2f_ds2;
  const double d2f_drs_ds = _t15*_t9 - _t5*_t9;
  out[4] = d2f_drs_ds;
  const double d2f_drs2 = 34.993911059475643*_hc0[0]*_t17*_t4*_t7 - _t10*_t16 - _t18*_t22;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = 0.057152799999999997*((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*(_t1 * _t1 * _t1)*_t23 - 0.085729199999999992*_hc0[1]*_hc0[2]*_t14 + _hc0[3]*_t4*_t6;
  out[6] = d3f_ds3;
  const double d3f_drs_ds2 = 0.99999999999999989*_hc0[0]*_hc0[2]*_hc1[1]*_t1*_t12*_t7 - 1.9999999999999998*_hc0[0]*_hc1[1]*_t11*_t13*_t23*_t7 - _hc0[2]*_t4*_t9 + 1.9999999999999998*_hc1[1]*_t1*_t11*_t12*_t7;
  out[7] = d3f_drs_ds2;
  const double d3f_drs2_ds = -_hc0[0]*_t21*_t25 + _t1*_t19*_t20*_t23*_t25 + _t15*_t16 - _t15*_t24 - _t16*_t5 + _t24*_t5;
  out[8] = d3f_drs2_ds;
  const double d3f_drs3 = -2449.147622476984*((_hc0[0]) * (_hc0[0]) * (_hc0[0]))*_t23*_t26*(_t7 * _t7 * _t7) + 104.98173317842694*_hc0[0]*_hc1[1]*_hc1[2]*_t4*_t7 - 104.98173317842694*_hc1[1]*_hc1[2]*_t22 - _hc1[3]*_t10*_t8 - 1224.573811238492*_t10*_t26*_t7 + 3673.721433715476*_t12*_t19*_t20*_t26;
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(np53_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (0.1e1 / (rs * rs * rs));
  const double _t2 = xc_powr(0.6e1, 2, 3)*xc_powr(_t1, 5, 3)/(M_PI * M_CBRTPI * M_CBRTPI);

  const double f = (0.3e1 / 0.16e2)*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.15e2 / 0.16e2*_t2/rs;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (0.45e2 / 0.8e1)*_t2/(rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.315e3 / 0.8e1*_t1*_t2;
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_f_alpha_large_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = 0.1e1 - a;
  const double _t2 = exp(1.5/_t1);
#if _KMAX >= 2
  const double _t3 = _t2/(_t1 * _t1 * _t1 * _t1);
#endif

  const double f = -0.69999999999999996*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -1.0499999999999998*_t2/(_t1 * _t1);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -1.5749999999999997*_t3 - 2.0999999999999996*_t2/(_t1 * _t1 * _t1);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -6.2999999999999989*_t3 - 9.4499999999999993*_t2/xc_powi(_t1, 5) - 2.3624999999999998*_t2/xc_powi(_t1, 6);
  out[3] = d3f_da3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_alpha0_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double ts0, double ts1, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(np53_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.5e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.5e1 / 0.3e1, _hc2);
  const double _t1 = _hc1[0] + _hc2[0] + 0.2e1;
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = M_CBRT2;
  const double _t4 = _hc1[0] + 0.1e1;
  const double _t5 = _hc2[0] + 0.1e1;
  const double _t6 = (0.1e1 / 0.4e1)*_t3*(_t4*ts0 + _t5*ts1) - 0.1e1 / 0.8e1*(xt * xt);
  const double _t7 = _t6 > 0;
  const double _t8 = my_piecewise3(_t7, _t6, 0);
  const double _t9 = _t2*_t8;
  const double _t10 = xc_powr(0.2e1, 2, 3);
  const double _t11 = (M_PI * M_CBRTPI);
  const double _t12 = _hc0[0]*_t11;
  const double _t13 = 0.0001*_t10 + (0.3e1 / 0.10e2)*xc_powr(0.6e1, 2, 3)*_t12;
  const double _t14 = (0.1e1 / _t13);
  const double _t15 = _t10*_t14;
  const double _t16 = _hc0[0]*_t15;
  const double _t17 = 0.2e1*_t16;
#if _KMAX >= 1
  const double _t18 = (0.1e1 / 0.4e1)*_t3;
  const double _t19 = my_piecewise3(_t7, _t18*_t5, 0);
  const double _t20 = _t17*_t2;
  const double _t21 = my_piecewise3(_t7, _t18*_t4, 0);
  const double _t22 = my_piecewise3(_t7, -0.1e1 / 0.4e1*xt, 0);
  const double _t23 = my_piecewise3(_t7, _t18*(_hc1[2]*ts0 - _hc2[2]*ts1), 0);
  const double _t24 = (0.1e1 / (_t1 * _t1));
  const double _t25 = -_hc1[2] + _hc2[2];
  const double _t26 = _t24*_t25;
  const double _t27 = _t17*_t26;
  const double _t28 = _hc0[1]*_t9;
  const double _t29 = xc_powr(0.18e2, 1, 3)/(_t13 * _t13);
  const double _t30 = _t12*_t29;
  const double _t31 = (0.6e1 / 0.5e1)*_t30;
#endif
#if _KMAX >= 2
  const double _t32 = my_piecewise3(_t7, -0.1e1 / 0.4e1, 0);
  const double _t33 = my_piecewise3(_t7, -_hc2[2]*_t18, 0);
  const double _t34 = my_piecewise3(_t7, _hc1[2]*_t18, 0);
  const double _t35 = my_piecewise3(_t7, _t18*(_hc1[5]*ts0 + _hc2[5]*ts1), 0);
  const double _t36 = _t16*_t26;
  const double _t37 = 0.4e1*_t36;
  const double _t38 = -_hc1[5] - _hc2[5];
  const double _t39 = _t24*_t38;
  const double _t40 = _t17*_t8;
  const double _t41 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t42 = -0.2e1*_hc1[2] + 0.2e1*_hc2[2];
  const double _t43 = _t41*_t42;
  const double _t44 = _t25*_t43;
  const double _t45 = _hc0[1]*_t19;
  const double _t46 = _t2*_t31;
  const double _t47 = _hc0[1]*_t46;
  const double _t48 = _hc0[1]*_t23;
  const double _t49 = _hc0[1]*_t8;
  const double _t50 = _t26*_t31;
  const double _t51 = 0.2e1*_t15;
  const double _t52 = _hc0[2]*_t31;
  const double _t53 = ((_hc0[1]) * (_hc0[1]));
  const double _t54 = _t53*_t9;
  const double _t55 = _t11*_t29;
  const double _t56 = (0.12e2 / 0.5e1)*_t55;
  const double _t57 = M_CBRT3;
  const double _t58 = (M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t59 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t60 = (0.108e3 / 0.25e2)*_hc0[0]*_t57*_t58*_t59;
#endif
#if _KMAX >= 3
  const double _t61 = _t17*_t39;
  const double _t62 = _t17*_t44;
  const double _t63 = 0.6e1*_t16*_t23;
  const double _t64 = _t25*_t40;
  const double _t65 = _hc0[1]*_t50;
  const double _t66 = _t31*_t49;
  const double _t67 = _hc0[2]*_t2*_t51;
  const double _t68 = _t19*_t2;
  const double _t69 = _t53*_t56;
  const double _t70 = _t53*_t60;
  const double _t71 = _hc0[2]*_t46;
  const double _t72 = _t2*_t69;
  const double _t73 = _t2*_t70;
  const double _t74 = _hc0[2]*_t8;
  const double _t75 = _t26*_t8;
  const double _t76 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _t17*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dts1 = _t19*_t20;
  out[1] = df_dts1;
  const double df_dts0 = _t20*_t21;
  out[2] = df_dts0;
  const double df_dxt = _t20*_t22;
  out[3] = df_dxt;
  const double df_dz = _t20*_t23 + _t27*_t8;
  out[4] = df_dz;
  const double df_drs = 0.2e1*_hc0[1]*_t10*_t14*_t2*_t8 - _t28*_t31;
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dts12 = 0;
  out[6] = d2f_dts12;
  const double d2f_dts0_dts1 = 0;
  out[7] = d2f_dts0_dts1;
  const double d2f_dts02 = 0;
  out[8] = d2f_dts02;
  const double d2f_dxt_dts1 = 0;
  out[9] = d2f_dxt_dts1;
  const double d2f_dxt_dts0 = 0;
  out[10] = d2f_dxt_dts0;
  const double d2f_dxt2 = _t20*_t32;
  out[11] = d2f_dxt2;
  const double d2f_dz_dts1 = _t19*_t27 + _t20*_t33;
  out[12] = d2f_dz_dts1;
  const double d2f_dz_dts0 = _t20*_t34 + _t21*_t27;
  out[13] = d2f_dz_dts0;
  const double d2f_dz_dxt = _t22*_t27;
  out[14] = d2f_dz_dxt;
  const double d2f_dz2 = _t20*_t35 + _t23*_t37 + _t39*_t40 + _t40*_t44;
  out[15] = d2f_dz2;
  const double d2f_drs_dts1 = 0.2e1*_hc0[1]*_t10*_t14*_t19*_t2 - _t45*_t46;
  out[16] = d2f_drs_dts1;
  const double d2f_drs_dts0 = 0.2e1*_hc0[1]*_t10*_t14*_t2*_t21 - _t21*_t47;
  out[17] = d2f_drs_dts0;
  const double d2f_drs_dxt = 0.2e1*_hc0[1]*_t10*_t14*_t2*_t22 - _t22*_t47;
  out[18] = d2f_drs_dxt;
  const double d2f_drs_dz = 0.2e1*_hc0[1]*_t10*_t14*_t2*_t23 + 0.2e1*_hc0[1]*_t10*_t14*_t24*_t25*_t8 - _t46*_t48 - _t49*_t50;
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[2]*_t51*_t9 - _t52*_t9 - _t54*_t56 + _t54*_t60;
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dts13 = 0;
  out[21] = d3f_dts13;
  const double d3f_dts0_dts12 = 0;
  out[22] = d3f_dts0_dts12;
  const double d3f_dts02_dts1 = 0;
  out[23] = d3f_dts02_dts1;
  const double d3f_dts03 = 0;
  out[24] = d3f_dts03;
  const double d3f_dxt_dts12 = 0;
  out[25] = d3f_dxt_dts12;
  const double d3f_dxt_dts0_dts1 = 0;
  out[26] = d3f_dxt_dts0_dts1;
  const double d3f_dxt_dts02 = 0;
  out[27] = d3f_dxt_dts02;
  const double d3f_dxt2_dts1 = 0;
  out[28] = d3f_dxt2_dts1;
  const double d3f_dxt2_dts0 = 0;
  out[29] = d3f_dxt2_dts0;
  const double d3f_dxt3 = 0;
  out[30] = d3f_dxt3;
  const double d3f_dz_dts12 = 0;
  out[31] = d3f_dz_dts12;
  const double d3f_dz_dts0_dts1 = 0;
  out[32] = d3f_dz_dts0_dts1;
  const double d3f_dz_dts02 = 0;
  out[33] = d3f_dz_dts02;
  const double d3f_dz_dxt_dts1 = 0;
  out[34] = d3f_dz_dxt_dts1;
  const double d3f_dz_dxt_dts0 = 0;
  out[35] = d3f_dz_dxt_dts0;
  const double d3f_dz_dxt2 = _t27*_t32;
  out[36] = d3f_dz_dxt2;
  const double d3f_dz2_dts1 = _t19*_t61 + _t19*_t62 + _t20*my_piecewise3(_t7, _hc2[5]*_t18, 0) + _t33*_t37;
  out[37] = d3f_dz2_dts1;
  const double d3f_dz2_dts0 = _t20*my_piecewise3(_t7, _hc1[5]*_t18, 0) + _t21*_t61 + _t21*_t62 + _t34*_t37;
  out[38] = d3f_dz2_dts0;
  const double d3f_dz2_dxt = _t22*_t61 + _t22*_t62;
  out[39] = d3f_dz2_dxt;
  const double d3f_dz3 = 0.4e1*_t16*_t38*_t43*_t8 + _t20*my_piecewise3(_t7, _t18*(_hc1[9]*ts0 - _hc2[9]*ts1), 0) + _t24*_t40*(-_hc1[9] + _hc2[9]) + 0.6e1*_t35*_t36 + _t39*_t63 + _t41*_t64*(-0.2e1*_hc1[5] - 0.2e1*_hc2[5]) + _t44*_t63 + _t42*_t64*(-0.3e1*_hc1[2] + 0.3e1*_hc2[2])/(_t1 * _t1 * _t1 * _t1);
  out[40] = d3f_dz3;
  const double d3f_drs_dts12 = 0;
  out[41] = d3f_drs_dts12;
  const double d3f_drs_dts0_dts1 = 0;
  out[42] = d3f_drs_dts0_dts1;
  const double d3f_drs_dts02 = 0;
  out[43] = d3f_drs_dts02;
  const double d3f_drs_dxt_dts1 = 0;
  out[44] = d3f_drs_dxt_dts1;
  const double d3f_drs_dxt_dts0 = 0;
  out[45] = d3f_drs_dxt_dts0;
  const double d3f_drs_dxt2 = 0.2e1*_hc0[1]*_t10*_t14*_t2*_t32 - _t32*_t47;
  out[46] = d3f_drs_dxt2;
  const double d3f_drs_dz_dts1 = 0.2e1*_hc0[1]*_t10*_t14*_t19*_t24*_t25 + 0.2e1*_hc0[1]*_t10*_t14*_t2*_t33 - _t33*_t47 - _t45*_t50;
  out[47] = d3f_drs_dz_dts1;
  const double d3f_drs_dz_dts0 = 0.2e1*_hc0[1]*_t10*_t14*_t2*_t34 + 0.2e1*_hc0[1]*_t10*_t14*_t21*_t24*_t25 - _t21*_t65 - _t34*_t47;
  out[48] = d3f_drs_dz_dts0;
  const double d3f_drs_dz_dxt = 0.2e1*_hc0[1]*_t10*_t14*_t22*_t24*_t25 - _t22*_t65;
  out[49] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = 0.2e1*_hc0[1]*_t10*_t14*_t2*_t35 + 0.4e1*_hc0[1]*_t10*_t14*_t23*_t24*_t25 + 0.2e1*_hc0[1]*_t10*_t14*_t24*_t38*_t8 + 0.2e1*_hc0[1]*_t10*_t14*_t25*_t41*_t42*_t8 - 0.12e2 / 0.5e1*_t26*_t30*_t48 - _t35*_t47 - _t39*_t66 - _t44*_t66;
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dts1 = _t19*_t67 - _t52*_t68 - _t68*_t69 + _t68*_t70;
  out[51] = d3f_drs2_dts1;
  const double d3f_drs2_dts0 = _t21*_t67 - _t21*_t71 - _t21*_t72 + _t21*_t73;
  out[52] = d3f_drs2_dts0;
  const double d3f_drs2_dxt = _t22*_t67 - _t22*_t71 - _t22*_t72 + _t22*_t73;
  out[53] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _t23*_t67 - _t23*_t71 - _t23*_t72 + _t23*_t73 + _t26*_t51*_t74 - _t50*_t74 - _t69*_t75 + _t70*_t75;
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = (0.324e3 / 0.25e2)*_hc0[0]*_hc0[1]*_hc0[2]*_t2*_t57*_t58*_t59*_t8 - 0.1458e4 / 0.125e3*(M_PI * M_PI * M_PI * M_PI)*_hc0[0]*_t10*_t76*_t9/(_t13 * _t13 * _t13 * _t13) - 0.36e2 / 0.5e1*_hc0[2]*_t28*_t55 + 0.2e1*_hc0[3]*_t10*_t14*_t2*_t8 - _hc0[3]*_t31*_t9 + (0.324e3 / 0.25e2)*_t2*_t57*_t58*_t59*_t76*_t8;
  out[55] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_alpha_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double ts0, double ts1, double *out) {

  double _hc0[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(rscan_alpha0_k, _KMAX)(p, rs, z, xt, ts0, ts1, _hc0);
  const double _t1 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t2 = ((_hc0[0]) * (_hc0[0]));
  const double _t3 = _t2 + 0.001;
  const double _t4 = (0.1e1 / _t3);
#if _KMAX >= 1
  const double _t5 = (0.1e1 / (_t3 * _t3));
  const double _t6 = _hc0[1]*_t5;
  const double _t7 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t8 = 0.2e1*_t7;
  const double _t9 = _t5*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = ((_hc0[1]) * (_hc0[1]));
  const double _t11 = 0.6e1*_t4;
  const double _t12 = _hc0[0]*_t11;
  const double _t13 = 0.14e2*_t1;
  const double _t14 = _t10*_t5;
  const double _t15 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t16 = _t10*_t15;
  const double _t17 = xc_powi((_hc0[0]), 5);
  const double _t18 = 0.8e1*_t17;
  const double _t19 = _hc0[1]*_hc0[2];
  const double _t20 = _t13*_t6;
  const double _t21 = _t15*_t18;
  const double _t22 = ((_hc0[2]) * (_hc0[2]));
  const double _t23 = _t13*_t5;
  const double _t24 = _hc0[1]*_hc0[3];
  const double _t25 = _hc0[2]*_hc0[3];
  const double _t26 = ((_hc0[3]) * (_hc0[3]));
  const double _t27 = 0.3e1*_t2*_t4;
  const double _t28 = _hc0[1]*_hc0[4];
  const double _t29 = _hc0[2]*_hc0[4];
  const double _t30 = _hc0[3]*_hc0[4];
  const double _t31 = ((_hc0[4]) * (_hc0[4]));
  const double _t32 = _hc0[1]*_hc0[5];
  const double _t33 = _hc0[2]*_hc0[5];
  const double _t34 = _hc0[3]*_hc0[5];
  const double _t35 = _hc0[4]*_hc0[5];
  const double _t36 = ((_hc0[5]) * (_hc0[5]));
#endif
#if _KMAX >= 3
  const double _t37 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t38 = 0.54e2*_t2;
  const double _t39 = _t38*_t5;
  const double _t40 = 0.48e2*xc_powi((_hc0[0]), 6)/(_t3 * _t3 * _t3 * _t3);
  const double _t41 = _t14*_t38;
  const double _t42 = _t10*_t40;
  const double _t43 = _t38*_t6;
  const double _t44 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t45 = _hc0[3]*_t22;
  const double _t46 = _hc0[1]*_hc0[11];
  const double _t47 = _t11*_t26;
  const double _t48 = 0.96e2*_t7;
  const double _t49 = _t15*_t48;
  const double _t50 = _hc0[1]*_t26;
  const double _t51 = _hc0[11]*_hc0[2];
  const double _t52 = _hc0[2]*_t26;
  const double _t53 = ((_hc0[3]) * (_hc0[3]) * (_hc0[3]));
  const double _t54 = _hc0[11]*_hc0[3];
  const double _t55 = _hc0[0]*_t4;
  const double _t56 = 0.18e2*_t55;
  const double _t57 = _t1*_t5;
  const double _t58 = 0.42e2*_t57;
  const double _t59 = _t15*_t17;
  const double _t60 = 0.24e2*_t59;
  const double _t61 = 0.12e2*_hc0[12];
  const double _t62 = _hc0[0]*_hc0[1]*_t4;
  const double _t63 = _t10*_t11;
  const double _t64 = 0.28e2*_hc0[12];
  const double _t65 = _t1*_t6;
  const double _t66 = 0.16e2*_t59;
  const double _t67 = _hc0[12]*_t66;
  const double _t68 = _t16*_t48;
  const double _t69 = _hc0[1]*_hc0[13];
  const double _t70 = _hc0[12]*_hc0[2];
  const double _t71 = _t11*_t19;
  const double _t72 = _hc0[4]*_t19;
  const double _t73 = _hc0[13]*_hc0[2];
  const double _t74 = 0.12e2*_t55;
  const double _t75 = _t11*_t22;
  const double _t76 = 0.28e2*_t57;
  const double _t77 = _hc0[4]*_t22;
  const double _t78 = _hc0[1]*_hc0[14];
  const double _t79 = _hc0[12]*_hc0[3];
  const double _t80 = _hc0[4]*_t11;
  const double _t81 = _hc0[4]*_t24;
  const double _t82 = _hc0[13]*_hc0[3];
  const double _t83 = _hc0[14]*_hc0[2];
  const double _t84 = _hc0[4]*_t25;
  const double _t85 = _hc0[11]*_hc0[4];
  const double _t86 = _hc0[14]*_hc0[3];
  const double _t87 = _hc0[4]*_t26;
  const double _t88 = _hc0[1]*_hc0[15];
  const double _t89 = _t11*_t31;
  const double _t90 = _hc0[1]*_t31;
  const double _t91 = _hc0[13]*_hc0[4];
  const double _t92 = _hc0[15]*_hc0[2];
  const double _t93 = _hc0[2]*_t31;
  const double _t94 = _hc0[14]*_hc0[4];
  const double _t95 = _hc0[15]*_hc0[3];
  const double _t96 = _hc0[3]*_t31;
  const double _t97 = ((_hc0[4]) * (_hc0[4]) * (_hc0[4]));
  const double _t98 = _hc0[15]*_hc0[4];
  const double _t99 = _hc0[16]*_t66;
  const double _t100 = _hc0[1]*_hc0[17];
  const double _t101 = _hc0[16]*_hc0[2];
  const double _t102 = _hc0[5]*_t19;
  const double _t103 = _hc0[17]*_hc0[2];
  const double _t104 = _hc0[5]*_t22;
  const double _t105 = _hc0[1]*_hc0[18];
  const double _t106 = _hc0[16]*_hc0[3];
  const double _t107 = _hc0[5]*_t11;
  const double _t108 = _hc0[5]*_t24;
  const double _t109 = _hc0[17]*_hc0[3];
  const double _t110 = _hc0[18]*_hc0[2];
  const double _t111 = _hc0[5]*_t25;
  const double _t112 = _hc0[11]*_hc0[5];
  const double _t113 = _hc0[18]*_hc0[3];
  const double _t114 = _hc0[5]*_t26;
  const double _t115 = _hc0[1]*_hc0[19];
  const double _t116 = _hc0[12]*_hc0[5];
  const double _t117 = _hc0[16]*_hc0[4];
  const double _t118 = _hc0[5]*_t28;
  const double _t119 = _hc0[13]*_hc0[5];
  const double _t120 = _hc0[17]*_hc0[4];
  const double _t121 = _hc0[19]*_hc0[2];
  const double _t122 = _hc0[5]*_t29;
  const double _t123 = _hc0[14]*_hc0[5];
  const double _t124 = _hc0[18]*_hc0[4];
  const double _t125 = _hc0[19]*_hc0[3];
  const double _t126 = _hc0[5]*_t30;
  const double _t127 = _hc0[15]*_hc0[5];
  const double _t128 = _hc0[19]*_hc0[4];
  const double _t129 = _hc0[5]*_t31;
  const double _t130 = _hc0[1]*_hc0[20];
  const double _t131 = _hc0[16]*_hc0[5];
  const double _t132 = _t11*_t36;
  const double _t133 = _hc0[1]*_t36;
  const double _t134 = _hc0[17]*_hc0[5];
  const double _t135 = _hc0[2]*_hc0[20];
  const double _t136 = _hc0[2]*_t36;
  const double _t137 = _hc0[18]*_hc0[5];
  const double _t138 = _hc0[20]*_hc0[3];
  const double _t139 = _hc0[3]*_t36;
  const double _t140 = _hc0[19]*_hc0[5];
  const double _t141 = _hc0[20]*_hc0[4];
  const double _t142 = _hc0[4]*_t36;
  const double _t143 = ((_hc0[5]) * (_hc0[5]) * (_hc0[5]));
  const double _t144 = _hc0[20]*_hc0[5];
#endif

  const double f = _t1*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dts1 = 0.3e1*_hc0[1]*_t2*_t4 - _t6*_t8;
  out[1] = df_dts1;
  const double df_dts0 = 0.3e1*_hc0[2]*_t2*_t4 - _hc0[2]*_t9;
  out[2] = df_dts0;
  const double df_dxt = 0.3e1*_hc0[3]*_t2*_t4 - _hc0[3]*_t9;
  out[3] = df_dxt;
  const double df_dz = 0.3e1*_hc0[4]*_t2*_t4 - _hc0[4]*_t9;
  out[4] = df_dz;
  const double df_drs = 0.3e1*_hc0[5]*_t2*_t4 - _hc0[5]*_t9;
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dts12 = _t10*_t12 - _t13*_t14 + _t16*_t18;
  out[6] = d2f_dts12;
  const double d2f_dts0_dts1 = -_hc0[2]*_t20 + _t12*_t19 + _t19*_t21;
  out[7] = d2f_dts0_dts1;
  const double d2f_dts02 = _t12*_t22 + _t21*_t22 - _t22*_t23;
  out[8] = d2f_dts02;
  const double d2f_dxt_dts1 = -_hc0[3]*_t20 + _t12*_t24 + _t21*_t24;
  out[9] = d2f_dxt_dts1;
  const double d2f_dxt_dts0 = _t12*_t25 + _t21*_t25 - _t23*_t25;
  out[10] = d2f_dxt_dts0;
  const double d2f_dxt2 = _hc0[11]*_t27 - _hc0[11]*_t9 + _t12*_t26 + _t21*_t26 - _t23*_t26;
  out[11] = d2f_dxt2;
  const double d2f_dz_dts1 = _hc0[12]*_t27 - _hc0[12]*_t9 - _hc0[4]*_t20 + _t12*_t28 + _t21*_t28;
  out[12] = d2f_dz_dts1;
  const double d2f_dz_dts0 = _hc0[13]*_t27 - _hc0[13]*_t9 + _t12*_t29 + _t21*_t29 - _t23*_t29;
  out[13] = d2f_dz_dts0;
  const double d2f_dz_dxt = _hc0[14]*_t27 - _hc0[14]*_t9 + _t12*_t30 + _t21*_t30 - _t23*_t30;
  out[14] = d2f_dz_dxt;
  const double d2f_dz2 = _hc0[15]*_t27 - _hc0[15]*_t9 + _t12*_t31 + _t21*_t31 - _t23*_t31;
  out[15] = d2f_dz2;
  const double d2f_drs_dts1 = _hc0[16]*_t27 - _hc0[16]*_t9 - _hc0[5]*_t20 + _t12*_t32 + _t21*_t32;
  out[16] = d2f_drs_dts1;
  const double d2f_drs_dts0 = _hc0[17]*_t27 - _hc0[17]*_t9 + _t12*_t33 + _t21*_t33 - _t23*_t33;
  out[17] = d2f_drs_dts0;
  const double d2f_drs_dxt = _hc0[18]*_t27 - _hc0[18]*_t9 + _t12*_t34 + _t21*_t34 - _t23*_t34;
  out[18] = d2f_drs_dxt;
  const double d2f_drs_dz = _hc0[19]*_t27 - _hc0[19]*_t9 + _t12*_t35 + _t21*_t35 - _t23*_t35;
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[20]*_t27 - _hc0[20]*_t9 + _t12*_t36 + _t21*_t36 - _t23*_t36;
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dts13 = 0.96e2*_t15*_t37*_t7 - _t37*_t39 + 0.6e1*_t37*_t4 - _t37*_t40;
  out[21] = d3f_dts13;
  const double d3f_dts0_dts12 = 0.96e2*_hc0[2]*_t10*_t15*_t7 + 0.6e1*_hc0[2]*_t10*_t4 - _hc0[2]*_t41 - _hc0[2]*_t42;
  out[22] = d3f_dts0_dts12;
  const double d3f_dts02_dts1 = 0.96e2*_hc0[1]*_t15*_t22*_t7 + 0.6e1*_hc0[1]*_t22*_t4 - _hc0[1]*_t22*_t40 - _t22*_t43;
  out[23] = d3f_dts02_dts1;
  const double d3f_dts03 = 0.96e2*_t15*_t44*_t7 - _t39*_t44 + 0.6e1*_t4*_t44 - _t40*_t44;
  out[24] = d3f_dts03;
  const double d3f_dxt_dts12 = 0.96e2*_hc0[3]*_t10*_t15*_t7 + 0.6e1*_hc0[3]*_t10*_t4 - _hc0[3]*_t41 - _hc0[3]*_t42;
  out[25] = d3f_dxt_dts12;
  const double d3f_dxt_dts0_dts1 = 0.96e2*_hc0[1]*_hc0[2]*_hc0[3]*_t15*_t7 + 0.6e1*_hc0[1]*_hc0[2]*_hc0[3]*_t4 - _hc0[3]*_t19*_t40 - _t25*_t43;
  out[26] = d3f_dxt_dts0_dts1;
  const double d3f_dxt_dts02 = 0.96e2*_hc0[3]*_t15*_t22*_t7 + 0.6e1*_hc0[3]*_t22*_t4 - _t39*_t45 - _t40*_t45;
  out[27] = d3f_dxt_dts02;
  const double d3f_dxt2_dts1 = _hc0[1]*_t47 - _hc0[11]*_t20 + _t12*_t46 + _t21*_t46 - _t26*_t43 - _t40*_t50 + _t49*_t50;
  out[28] = d3f_dxt2_dts1;
  const double d3f_dxt2_dts0 = _hc0[2]*_t47 + _t12*_t51 + _t21*_t51 - _t23*_t51 - _t39*_t52 - _t40*_t52 + _t49*_t52;
  out[29] = d3f_dxt2_dts0;
  const double d3f_dxt3 = _t11*_t53 - _t39*_t53 - _t40*_t53 + _t49*_t53 + _t54*_t56 - _t54*_t58 + _t54*_t60;
  out[30] = d3f_dxt3;
  const double d3f_dz_dts12 = _hc0[1]*_t67 - _hc0[4]*_t41 - _hc0[4]*_t42 + _hc0[4]*_t63 + _hc0[4]*_t68 + _t61*_t62 - _t64*_t65;
  out[31] = d3f_dz_dts12;
  const double d3f_dz_dts0_dts1 = -_hc0[13]*_t20 + _hc0[4]*_t71 + _t12*_t69 + _t12*_t70 + _t21*_t69 + _t21*_t70 - _t23*_t70 - _t29*_t43 - _t40*_t72 + _t49*_t72;
  out[32] = d3f_dz_dts0_dts1;
  const double d3f_dz_dts02 = _hc0[4]*_t75 - _t39*_t77 - _t40*_t77 + _t49*_t77 + _t66*_t73 + _t73*_t74 - _t73*_t76;
  out[33] = d3f_dz_dts02;
  const double d3f_dz_dxt_dts1 = -_hc0[14]*_t20 + _t12*_t78 + _t12*_t79 + _t21*_t78 + _t21*_t79 - _t23*_t79 + _t24*_t80 - _t30*_t43 - _t40*_t81 + _t49*_t81;
  out[34] = d3f_dz_dxt_dts1;
  const double d3f_dz_dxt_dts0 = _t12*_t82 + _t12*_t83 + _t21*_t82 + _t21*_t83 - _t23*_t82 - _t23*_t83 + _t25*_t80 - _t39*_t84 - _t40*_t84 + _t49*_t84;
  out[35] = d3f_dz_dxt_dts0;
  const double d3f_dz_dxt2 = _hc0[36]*_t27 - _hc0[36]*_t9 + _hc0[4]*_t47 + _t12*_t85 + _t21*_t85 - _t23*_t85 - _t39*_t87 - _t40*_t87 + _t49*_t87 + _t66*_t86 + _t74*_t86 - _t76*_t86;
  out[36] = d3f_dz_dxt2;
  const double d3f_dz2_dts1 = _hc0[1]*_t89 - _hc0[15]*_t20 + _hc0[37]*_t27 - _hc0[37]*_t9 + _hc0[4]*_t55*_t61 - _hc0[4]*_t57*_t64 + _hc0[4]*_t67 + _t12*_t88 + _t21*_t88 - _t31*_t43 - _t40*_t90 + _t49*_t90;
  out[37] = d3f_dz2_dts1;
  const double d3f_dz2_dts0 = _hc0[2]*_t89 + _hc0[38]*_t27 - _hc0[38]*_t9 + _t12*_t92 + _t21*_t92 - _t23*_t92 - _t39*_t93 - _t40*_t93 + _t49*_t93 + _t66*_t91 + _t74*_t91 - _t76*_t91;
  out[38] = d3f_dz2_dts0;
  const double d3f_dz2_dxt = _hc0[3]*_t89 + _hc0[39]*_t27 - _hc0[39]*_t9 + _t12*_t95 + _t21*_t95 - _t23*_t95 - _t39*_t96 - _t40*_t96 + _t49*_t96 + _t66*_t94 + _t74*_t94 - _t76*_t94;
  out[39] = d3f_dz2_dxt;
  const double d3f_dz3 = _hc0[40]*_t27 - _hc0[40]*_t9 + _t11*_t97 - _t39*_t97 - _t40*_t97 + _t49*_t97 + _t56*_t98 - _t58*_t98 + _t60*_t98;
  out[40] = d3f_dz3;
  const double d3f_drs_dts12 = _hc0[1]*_t99 + 0.12e2*_hc0[16]*_t62 - 0.28e2*_hc0[16]*_t65 - _hc0[5]*_t41 - _hc0[5]*_t42 + _hc0[5]*_t63 + _hc0[5]*_t68;
  out[41] = d3f_drs_dts12;
  const double d3f_drs_dts0_dts1 = -_hc0[17]*_t20 + _hc0[5]*_t71 + _t100*_t12 + _t100*_t21 + _t101*_t12 + _t101*_t21 - _t101*_t23 - _t102*_t40 + _t102*_t49 - _t33*_t43;
  out[42] = d3f_drs_dts0_dts1;
  const double d3f_drs_dts02 = _hc0[5]*_t75 + _t103*_t66 + _t103*_t74 - _t103*_t76 - _t104*_t39 - _t104*_t40 + _t104*_t49;
  out[43] = d3f_drs_dts02;
  const double d3f_drs_dxt_dts1 = -_hc0[18]*_t20 + _t105*_t12 + _t105*_t21 + _t106*_t12 + _t106*_t21 - _t106*_t23 + _t107*_t24 - _t108*_t40 + _t108*_t49 - _t34*_t43;
  out[44] = d3f_drs_dxt_dts1;
  const double d3f_drs_dxt_dts0 = _t107*_t25 + _t109*_t12 + _t109*_t21 - _t109*_t23 + _t110*_t12 + _t110*_t21 - _t110*_t23 - _t111*_t39 - _t111*_t40 + _t111*_t49;
  out[45] = d3f_drs_dxt_dts0;
  const double d3f_drs_dxt2 = _hc0[46]*_t27 - _hc0[46]*_t9 + _hc0[5]*_t47 + _t112*_t12 + _t112*_t21 - _t112*_t23 + _t113*_t66 + _t113*_t74 - _t113*_t76 - _t114*_t39 - _t114*_t40 + _t114*_t49;
  out[46] = d3f_drs_dxt2;
  const double d3f_drs_dz_dts1 = -_hc0[19]*_t20 + _hc0[47]*_t27 - _hc0[47]*_t9 + _t107*_t28 + _t115*_t12 + _t115*_t21 + _t116*_t12 + _t116*_t21 - _t116*_t23 + _t117*_t12 + _t117*_t21 - _t117*_t23 - _t118*_t40 + _t118*_t49 - _t35*_t43;
  out[47] = d3f_drs_dz_dts1;
  const double d3f_drs_dz_dts0 = _hc0[48]*_t27 - _hc0[48]*_t9 + _t107*_t29 + _t119*_t12 + _t119*_t21 - _t119*_t23 + _t12*_t120 + _t12*_t121 + _t120*_t21 - _t120*_t23 + _t121*_t21 - _t121*_t23 - _t122*_t39 - _t122*_t40 + _t122*_t49;
  out[48] = d3f_drs_dz_dts0;
  const double d3f_drs_dz_dxt = _hc0[49]*_t27 - _hc0[49]*_t9 + _t107*_t30 + _t12*_t123 + _t12*_t124 + _t12*_t125 + _t123*_t21 - _t123*_t23 + _t124*_t21 - _t124*_t23 + _t125*_t21 - _t125*_t23 - _t126*_t39 - _t126*_t40 + _t126*_t49;
  out[49] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = _hc0[5]*_t89 + _hc0[50]*_t27 - _hc0[50]*_t9 + _t12*_t127 + _t127*_t21 - _t127*_t23 + _t128*_t66 + _t128*_t74 - _t128*_t76 - _t129*_t39 - _t129*_t40 + _t129*_t49;
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dts1 = _hc0[1]*_t132 - _hc0[20]*_t20 + _hc0[5]*_t99 + _hc0[51]*_t27 - _hc0[51]*_t9 + _t12*_t130 + _t130*_t21 + _t131*_t74 - _t131*_t76 - _t133*_t40 + _t133*_t49 - _t36*_t43;
  out[51] = d3f_drs2_dts1;
  const double d3f_drs2_dts0 = _hc0[2]*_t132 + _hc0[52]*_t27 - _hc0[52]*_t9 + _t12*_t135 + _t134*_t66 + _t134*_t74 - _t134*_t76 + _t135*_t21 - _t135*_t23 - _t136*_t39 - _t136*_t40 + _t136*_t49;
  out[52] = d3f_drs2_dts0;
  const double d3f_drs2_dxt = _hc0[3]*_t132 + _hc0[53]*_t27 - _hc0[53]*_t9 + _t12*_t138 + _t137*_t66 + _t137*_t74 - _t137*_t76 + _t138*_t21 - _t138*_t23 - _t139*_t39 - _t139*_t40 + _t139*_t49;
  out[53] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _hc0[4]*_t132 + _hc0[54]*_t27 - _hc0[54]*_t9 + _t12*_t141 + _t140*_t66 + _t140*_t74 - _t140*_t76 + _t141*_t21 - _t141*_t23 - _t142*_t39 - _t142*_t40 + _t142*_t49;
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[55]*_t27 - _hc0[55]*_t9 + _t11*_t143 - _t143*_t39 - _t143*_t40 + _t143*_t49 + _t144*_t56 - _t144*_t58 + _t144*_t60;
  out[55] = d3f_drs3;
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
  const double d3f_drs3 = -0.15e2 / 0.64e2*_t1*xt/xc_powr(rs, 7, 2);
  out[9] = d3f_drs3;
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
  const double _t21 = (_t10 * _t10)*_t20;
  const double _t22 = _t19*_t21;
  const double _t23 = _t10*_t2;
  const double _t24 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t25 = -0.30559670843999998*_t8 - 0.47231125997999995*_t9 - 0.12260679726399999*rs - 0.44616398128000001;
  const double _t26 = _t13*_t24*_t25;
#endif
#if _KMAX >= 3
  const double _t27 = _t23*(-0.15279835421999999*_t15 + 0.23615562998999998*_t16 - 0.12260679726399999);
  const double _t28 = _t19*_t20;
  const double _t29 = _t2*_t21/xc_powi(_t5, 5);
#endif

  const double f = _t2*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t11*_t13*_t2 - 0.01328816518*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1*_t22 - 0.026576330360000001*_t10*_t14 + _t18*_t2 + _t23*_t26;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (_t10 * _t10 * _t10)*(-0.026576330360000001*rs - 0.1243628)/((_t12 * _t12 * _t12)*xc_powi(_t5, 6)) - 0.039864495540000003*_t10*_t26 + _t13*_t19*_t23*_t25*(-0.45839506265999996*_t8 - 0.70846688996999996*_t9 - 0.18391019589599999*rs - 0.66924597192000002) + _t13*_t24*_t27 + _t14*_t2*(-0.17711672249249999/xc_powr(rs, 5, 2) + 0.038199588554999997/_t3) + 0.2e1*_t17*_t2*_t26 - _t17*_t23*_t28 - 0.039864495540000003*_t18 + 0.039864495540000003*_t22 - _t25*_t29 - _t27*_t28 - _t29*(-0.61119341687999995*_t8 - 0.94462251995999991*_t9 - 0.24521359452799998*rs - 0.89232796256000002);
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(A_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, rs, 0, _hc1);
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
  const double _t9 = _hc1[0]*_t8;
  const double _t10 = _hc0[1]*_t8;
  const double _t11 = _hc1[0]*_t7;
  const double _t12 = xc_powi(M_PI, 6)/(_t1 * _t1 * _t1);
  const double _t13 = ((_hc0[1]) * (_hc0[1]))*_t12;
  const double _t14 = (_t6 * _t6)/(_t3 * _t3 * _t3);
  const double _t15 = _hc1[0]*_t14;
#endif
#if _KMAX >= 3
  const double _t16 = 0.3e1*_hc1[2];
  const double _t17 = xc_powi(M_PI, 8)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]))/(_t1 * _t1 * _t1 * _t1);
  const double _t18 = _hc0[2]*_t12*_t5;
  const double _t19 = 0.6e1*_t14;
  const double _t20 = 0.6e1*_t17;
#endif

  const double f = _hc1[0]*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_drs = _hc1[2]*_t4 + _t5*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = 0;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _hc0[2]*_t9 + 0.2e1*_hc1[2]*_t10 + _hc1[5]*_t4 - _t11*_t13 + 0.2e1*_t13*_t15;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = 0;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = 0;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = _hc0[2]*_t16*_t8 + _hc0[3]*_t9 + _hc1[0]*_t20*(_t6 * _t6 * _t6)/(_t3 * _t3 * _t3 * _t3) + _hc1[2]*_t13*_t19 + 0.3e1*_hc1[5]*_t10 + _hc1[9]*_t4 + _t11*_t17 - _t13*_t16*_t7 - _t15*_t20 + _t18*_t19 - 0.3e1*_t18*_t7;
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_e0_one_minus_g_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(A_z0_k, _KMAX)(p, rs, t, _hc0);
  const double _t1 = (t * t);
  const double _t2 = 0.4e1*_t1;
  const double _t3 = _hc0[0]*_t2;
  const double _t4 = xc_expm1(-0.1e1 / 0.4e1*xc_log1p(_t3));
#if _KMAX >= 1
  const double _t5 = 0.8e1*_hc0[0];
  const double _t6 = _hc0[1]*_t2 + _t5*t;
  const double _t7 = _t3 + 0.1e1;
  const double _t8 = (0.1e1 / _t7);
  const double _t9 = _t4 + 0.1e1;
  const double _t10 = _t8*_t9;
  const double _t11 = (0.1e1 / 0.4e1)*_t10;
  const double _t12 = _t1*_t10;
#endif
#if _KMAX >= 2
  const double _t13 = (0.1e1 / (_t7 * _t7));
  const double _t14 = _t13*_t9;
  const double _t15 = (0.1e1 / 0.16e2)*(_t6 * _t6);
  const double _t16 = _hc0[1]*t;
  const double _t17 = _hc0[3]*_t2 + 0.16e2*_t16 + _t5;
  const double _t18 = -_t6;
  const double _t19 = _t14*_t18;
  const double _t20 = (0.1e1 / 0.4e1)*_t6;
  const double _t21 = 0.2e1*_hc0[2]*_t10;
  const double _t22 = _hc0[2]*_t1;
  const double _t23 = _t14*_t22;
  const double _t24 = ((_hc0[2]) * (_hc0[2]));
  const double _t25 = _t14*_t24;
  const double _t26 = (t * t * t * t);
  const double _t27 = 0.5e1*_t26;
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t29 = _t28*_t9;
  const double _t30 = 0.16e2*_hc0[0];
  const double _t31 = 0.8e1*_t1;
  const double _t32 = -_hc0[1]*_t31 - _t30*t;
  const double _t33 = _t15*_t29;
  const double _t34 = -_t14*_t17;
  const double _t35 = _t14*_t6;
  const double _t36 = (0.1e1 / 0.16e2)*_t35;
  const double _t37 = _t29*_t32;
  const double _t38 = _t18*_t37;
  const double _t39 = 0.4e1*t;
  const double _t40 = _t20*_t22;
  const double _t41 = _hc0[2]*_t14*_t26;
#endif

  const double f = -_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t11*_t6;
  out[1] = df_dt;
  const double df_drs = _hc0[2]*_t12;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t11*_t17 - _t14*_t15 + _t19*_t20;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = _hc0[4]*_t12 + _t19*_t22 - _t20*_t23 + _t21*t;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = _hc0[5]*_t1*_t8*_t9 - _t25*_t27;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t11*(0.24e2*_hc0[1] + 0.24e2*_hc0[3]*t + _hc0[6]*_t2) + (0.1e1 / 0.2e1)*_t17*_t19 - _t17*_t36 - _t18*_t33 + _t20*_t34 + _t20*_t38 + (0.1e1 / 0.64e2)*_t29*(_t6 * _t6 * _t6) - _t32*_t33 - _t36*(_hc0[3]*_t31 + 0.32e2*_t16 + _t30);
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _hc0[2]*_t19*_t39 - _hc0[2]*_t35*t + 0.2e1*_hc0[4]*_t1*_t19 - 0.1e1 / 0.2e1*_hc0[4]*_t1*_t35 + _hc0[4]*_t10*_t39 + _hc0[7]*_t12 - 0.1e1 / 0.4e1*_t17*_t23 - _t18*_t29*_t40 + _t21 + _t22*_t33 + _t22*_t34 + _t22*_t38 - _t37*_t40;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = -0.10e2*_hc0[4]*_t41 + _hc0[5]*_t1*_t13*_t18*_t9 - _hc0[5]*_t1*_t14*_t20 + 0.2e1*_hc0[5]*_t8*_t9*t + _hc0[8]*_t1*_t8*_t9 + (0.5e1 / 0.4e1)*_t24*_t26*_t28*_t6*_t9 - _t24*_t27*_t37 - 0.20e2*_t25*(t * t * t);
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = 0.45e2*((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t29*xc_powi(t, 6) - 0.15e2*_hc0[5]*_t41 + _hc0[9]*_t12;
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f2_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(A_z0_k, _KMAX)(p, rs, t, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, rs, 0, _hc1);
  double _hc2[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_e0_one_minus_g_z0_k, _KMAX)(p, rs, t, _hc2);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = (M_PI * M_PI);
  const double _t3 = (0.1e1 / (0.1e1 - M_LN2));
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
  const double _t6 = _hc1[0]*_t5;
#if _KMAX >= 1
  const double _t7 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t8 = _hc1[0]*_t4;
  const double _t9 = _t7*_t8;
  const double _t10 = _hc0[1]*_hc2[0];
  const double _t11 = _hc1[2]*_t5;
  const double _t12 = _hc2[0]*_t9;
#endif
#if _KMAX >= 2
  const double _t13 = _hc0[1]*_t9;
  const double _t14 = 0.2e1*_t13;
  const double _t15 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t16 = ((_hc0[1]) * (_hc0[1]));
  const double _t17 = _hc2[0]*_t8;
  const double _t18 = 0.2e1*_t17;
  const double _t19 = _hc2[2]*_t9;
  const double _t20 = _hc1[2]*_t4;
  const double _t21 = _t20*_t7;
  const double _t22 = _hc0[2]*_t9;
  const double _t23 = _hc1[5]*_t5;
  const double _t24 = 0.2e1*_hc0[2];
  const double _t25 = _hc2[0]*_t21;
  const double _t26 = ((_hc0[2]) * (_hc0[2]));
  const double _t27 = _t15*_t26;
#endif
#if _KMAX >= 3
  const double _t28 = _hc2[1]*_t9;
  const double _t29 = 0.6e1/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t30 = _t17*_t29;
  const double _t31 = _hc2[1]*_t21;
  const double _t32 = 0.2e1*_hc0[1];
  const double _t33 = 0.2e1*_hc0[4];
  const double _t34 = _hc1[5]*_t4*_t7;
  const double _t35 = _hc2[2]*_t21;
  const double _t36 = 0.3e1*_hc2[5];
  const double _t37 = 0.6e1*_hc0[2];
  const double _t38 = 0.3e1*_hc0[5];
#endif

  const double f = _hc2[0]*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc2[1]*_t6 - _t10*_t9;
  out[1] = df_dt;
  const double df_drs = -_hc0[2]*_t12 + _hc2[0]*_t11 + _hc2[2]*_t6;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_hc0[3]*_t12 - _hc2[1]*_t14 + _hc2[3]*_t6 + _t15*_t16*_t18;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = 0.2e1*_hc0[1]*_hc0[2]*_hc1[0]*_hc2[0]*_t15*_t2*_t3 - _hc0[1]*_t19 - _hc0[4]*_t12 + _hc1[0]*_hc2[4]*_t1*_t2*_t3 + _hc1[2]*_hc2[1]*_t1*_t2*_t3 - _hc2[1]*_t22 - _t10*_t21;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = -_hc0[5]*_t12 + _hc2[0]*_t23 + 0.2e1*_hc2[2]*_t11 + _hc2[5]*_t6 + _t18*_t27 - _t19*_t24 - _t24*_t25;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = -((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t30 + 0.6e1*_hc0[1]*_hc0[3]*_hc1[0]*_hc2[0]*_t15*_t2*_t3 - 0.3e1*_hc0[3]*_t28 - _hc0[6]*_t12 + 0.6e1*_hc1[0]*_hc2[1]*_t15*_t16*_t2*_t3 + _hc1[0]*_hc2[6]*_t1*_t2*_t3 - 0.3e1*_hc2[3]*_t13;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = 0.4e1*_hc0[1]*_hc0[2]*_hc1[0]*_hc2[1]*_t15*_t2*_t3 + 0.4e1*_hc0[1]*_hc0[4]*_hc1[0]*_hc2[0]*_t15*_t2*_t3 + 0.2e1*_hc0[2]*_hc0[3]*_hc1[0]*_hc2[0]*_t15*_t2*_t3 - _hc0[2]*_t16*_t30 - _hc0[3]*_t19 - _hc0[3]*_t25 - _hc0[7]*_t12 + 0.2e1*_hc1[0]*_hc2[2]*_t15*_t16*_t2*_t3 + _hc1[0]*_hc2[7]*_t1*_t2*_t3 + 0.2e1*_hc1[2]*_hc2[0]*_t15*_t16*_t2*_t3 + _hc1[2]*_hc2[3]*_t1*_t2*_t3 - _hc2[3]*_t22 - _hc2[4]*_t14 - _t28*_t33 - _t31*_t32;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = 0.4e1*_hc0[1]*_hc0[2]*_hc1[0]*_hc2[2]*_t15*_t2*_t3 + 0.4e1*_hc0[1]*_hc0[2]*_hc1[2]*_hc2[0]*_t15*_t2*_t3 + 0.2e1*_hc0[1]*_hc0[5]*_hc1[0]*_hc2[0]*_t15*_t2*_t3 + 0.4e1*_hc0[2]*_hc0[4]*_hc1[0]*_hc2[0]*_t15*_t2*_t3 - _hc0[5]*_t28 - _hc0[8]*_t12 + 0.2e1*_hc1[0]*_hc2[1]*_t15*_t2*_t26*_t3 + _hc1[0]*_hc2[8]*_t1*_t2*_t3 + 0.2e1*_hc1[2]*_hc2[4]*_t1*_t2*_t3 + _hc1[5]*_hc2[1]*_t1*_t2*_t3 - 0.2e1*_hc2[4]*_t22 - _hc2[5]*_t13 - _t10*_t26*_t29*_t8 - _t10*_t34 - _t19*_t33 - _t24*_t31 - _t25*_t33 - _t32*_t35;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = -((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t30 - 0.3e1*_hc0[2]*_hc2[0]*_t34 + _hc0[5]*_t15*_t17*_t37 - _hc0[9]*_t12 + _hc1[9]*_hc2[0]*_t5 + 0.6e1*_hc2[0]*_t20*_t27 + 0.3e1*_hc2[2]*_t23 + 0.6e1*_hc2[2]*_t27*_t8 + _hc2[9]*_t6 + _t11*_t36 - _t19*_t38 - _t22*_t36 - _t25*_t38 - _t35*_t37;
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fH_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
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
  const double _t11 = _hc0[1]*_t8;
  const double _t12 = 0.2e1*_t3/(_t4 * _t4 * _t4);
  const double _t13 = 0.2e1*_hc0[4];
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
  const double d3f_dt3 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t12 - 0.3e1*_hc0[3]*_t11 + _hc0[6]*_t6;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = _hc0[2]*_t12*_t7 - _hc0[3]*_t9 + _hc0[7]*_t6 - _t11*_t13;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = _hc0[1]*_t10*_t12 - _hc0[5]*_t11 + _hc0[8]*_t6 - _t13*_t9;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t12 - 0.3e1*_hc0[5]*_t9 + _hc0[9]*_t6;
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_grad_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tp_z0_k, _KMAX)(p, rs, xt, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(fH_z0_k, _KMAX)(p, rs, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = ((_hc0[1]) * (_hc0[1]));
  const double _t2 = _hc0[2]*_hc1[3];
  const double _t3 = _hc1[4] + _t2;
#endif
#if _KMAX >= 3
  const double _t4 = _hc0[4]*_hc1[3];
  const double _t5 = _hc0[2]*_hc1[6];
  const double _t6 = _hc0[1]*_hc1[7];
  const double _t7 = _hc0[5]*_hc1[3];
  const double _t8 = _hc0[2]*_hc1[7] + _hc1[8];
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
  const double d3f_dxt3 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[6];
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
  const double d3f_drs_dxt2 = 0.2e1*_hc0[1]*_t4 + _hc1[7]*_t1 + _t1*_t5;
  out[30] = d3f_drs_dxt2;
  const double d3f_drs2_dxs1 = 0;
  out[31] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[32] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = _hc0[1]*_hc1[8] + _hc0[1]*_t7 + _hc0[2]*_t6 + _hc0[2]*(_hc0[1]*_t5 + _t4 + _t6) + _hc0[4]*_hc1[4] + _hc0[4]*_t3 + _hc0[8]*_hc1[1];
  out[33] = d3f_drs2_dxt;
  const double d3f_drs3 = _hc0[2]*_hc1[8] + _hc0[2]*_t8 + _hc0[2]*(_hc0[2]*(_hc1[7] + _t5) + _t7 + _t8) + _hc0[5]*_hc1[4] + 0.2e1*_hc0[5]*_t3 + _hc0[9]*_hc1[1] + _hc1[9];
  out[34] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(f_pbe_grad_z0_k, _KMAX)(p, rs, xt, 0, 0, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
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
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_alpha0_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double ts0, double ts1, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(np53_k, _KMAX)(p, rs, _hc0);
  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = (M_PI * M_CBRTPI);
  const double _t3 = _hc0[0]*_t2;
  const double _t4 = 0.0001*_t1 + (0.3e1 / 0.10e2)*xc_powr(0.6e1, 2, 3)*_t3;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t1*_t5;
  const double _t7 = (0.1e1 / 0.8e1)*(xt * xt);
  const double _t8 = M_CBRT2;
  const double _t9 = (0.1e1 / 0.4e1)*_t8;
  const double _t10 = -_t7 + _t9*ts0 + _t9*ts1 > 0;
  const double _t11 = my_piecewise3(_t10, -_t7 + (0.1e1 / 0.4e1)*_t8*(ts0 + ts1), 0);
  const double _t12 = _hc0[0]*_t11;
#if _KMAX >= 1
  const double _t13 = my_piecewise3(_t10, _t9, 0);
  const double _t14 = _hc0[0]*_t6;
  const double _t15 = _t13*_t14;
  const double _t16 = my_piecewise3(_t10, -0.1e1 / 0.4e1*xt, 0);
  const double _t17 = xc_powr(0.18e2, 1, 3)/(_t4 * _t4);
  const double _t18 = _t11*_t17;
  const double _t19 = (0.3e1 / 0.5e1)*_t3;
  const double _t20 = _hc0[1]*_t19;
#endif
#if _KMAX >= 2
  const double _t21 = my_piecewise3(_t10, -0.1e1 / 0.4e1, 0);
  const double _t22 = _t13*_t17;
  const double _t23 = _hc0[1]*_t1*_t13*_t5 - _t20*_t22;
  const double _t24 = _t16*_t17;
  const double _t25 = _hc0[2]*_t6;
  const double _t26 = _hc0[2]*_t19;
  const double _t27 = _t18*_t2;
  const double _t28 = ((_hc0[1]) * (_hc0[1]));
  const double _t29 = (0.6e1 / 0.5e1)*_t28;
  const double _t30 = M_CBRT3;
  const double _t31 = (M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t32 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t33 = (0.54e2 / 0.25e2)*_t28*_t30*_t31*_t32;
#endif
#if _KMAX >= 3
  const double _t34 = _t2*_t29;
  const double _t35 = _hc0[0]*_t33;
  const double _t36 = _t13*_t25 + _t13*_t35 - _t22*_t26 - _t22*_t34;
  const double _t37 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _t12*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dts1 = _t15;
  out[1] = df_dts1;
  const double df_dts0 = _t15;
  out[2] = df_dts0;
  const double df_dxt = _t14*_t16;
  out[3] = df_dxt;
  const double df_drs = _hc0[1]*_t1*_t11*_t5 - _t18*_t20;
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dts12 = 0;
  out[5] = d2f_dts12;
  const double d2f_dts0_dts1 = 0;
  out[6] = d2f_dts0_dts1;
  const double d2f_dts02 = 0;
  out[7] = d2f_dts02;
  const double d2f_dxt_dts1 = 0;
  out[8] = d2f_dxt_dts1;
  const double d2f_dxt_dts0 = 0;
  out[9] = d2f_dxt_dts0;
  const double d2f_dxt2 = _t14*_t21;
  out[10] = d2f_dxt2;
  const double d2f_drs_dts1 = _t23;
  out[11] = d2f_drs_dts1;
  const double d2f_drs_dts0 = _t23;
  out[12] = d2f_drs_dts0;
  const double d2f_drs_dxt = _hc0[1]*_t1*_t16*_t5 - _t20*_t24;
  out[13] = d2f_drs_dxt;
  const double d2f_drs2 = _t11*_t25 + _t12*_t33 - _t18*_t26 - _t27*_t29;
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dts13 = 0;
  out[15] = d3f_dts13;
  const double d3f_dts0_dts12 = 0;
  out[16] = d3f_dts0_dts12;
  const double d3f_dts02_dts1 = 0;
  out[17] = d3f_dts02_dts1;
  const double d3f_dts03 = 0;
  out[18] = d3f_dts03;
  const double d3f_dxt_dts12 = 0;
  out[19] = d3f_dxt_dts12;
  const double d3f_dxt_dts0_dts1 = 0;
  out[20] = d3f_dxt_dts0_dts1;
  const double d3f_dxt_dts02 = 0;
  out[21] = d3f_dxt_dts02;
  const double d3f_dxt2_dts1 = 0;
  out[22] = d3f_dxt2_dts1;
  const double d3f_dxt2_dts0 = 0;
  out[23] = d3f_dxt2_dts0;
  const double d3f_dxt3 = 0;
  out[24] = d3f_dxt3;
  const double d3f_drs_dts12 = 0;
  out[25] = d3f_drs_dts12;
  const double d3f_drs_dts0_dts1 = 0;
  out[26] = d3f_drs_dts0_dts1;
  const double d3f_drs_dts02 = 0;
  out[27] = d3f_drs_dts02;
  const double d3f_drs_dxt_dts1 = 0;
  out[28] = d3f_drs_dxt_dts1;
  const double d3f_drs_dxt_dts0 = 0;
  out[29] = d3f_drs_dxt_dts0;
  const double d3f_drs_dxt2 = _hc0[1]*_t1*_t21*_t5 - _t17*_t20*_t21;
  out[30] = d3f_drs_dxt2;
  const double d3f_drs2_dts1 = _t36;
  out[31] = d3f_drs2_dts1;
  const double d3f_drs2_dts0 = _t36;
  out[32] = d3f_drs2_dts0;
  const double d3f_drs2_dxt = _t16*_t25 + _t16*_t35 - _t24*_t26 - _t24*_t34;
  out[33] = d3f_drs2_dxt;
  const double d3f_drs3 = (0.162e3 / 0.25e2)*_hc0[0]*_hc0[1]*_hc0[2]*_t11*_t30*_t31*_t32 - 0.18e2 / 0.5e1*_hc0[1]*_hc0[2]*_t27 + _hc0[3]*_t1*_t11*_t5 - _hc0[3]*_t11*_t17*_t19 - 0.729e3 / 0.125e3*(M_PI * M_PI * M_PI * M_PI)*_t1*_t12*_t37/(_t4 * _t4 * _t4 * _t4) + (0.162e3 / 0.25e2)*_t11*_t30*_t31*_t32*_t37;
  out[34] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_alpha_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double ts0, double ts1, double *out) {

  double _hc0[(_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(rscan_alpha0_z0_k, _KMAX)(p, rs, xt, ts0, ts1, _hc0);
  const double _t1 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t2 = ((_hc0[0]) * (_hc0[0]));
  const double _t3 = _t2 + 0.001;
  const double _t4 = (0.1e1 / _t3);
#if _KMAX >= 1
  const double _t5 = (0.1e1 / (_t3 * _t3));
  const double _t6 = _hc0[1]*_t5;
  const double _t7 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t8 = 0.2e1*_t7;
  const double _t9 = _t5*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = ((_hc0[1]) * (_hc0[1]));
  const double _t11 = 0.6e1*_t4;
  const double _t12 = _hc0[0]*_t11;
  const double _t13 = 0.14e2*_t1;
  const double _t14 = _t10*_t5;
  const double _t15 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t16 = _t10*_t15;
  const double _t17 = xc_powi((_hc0[0]), 5);
  const double _t18 = 0.8e1*_t17;
  const double _t19 = _hc0[1]*_hc0[2];
  const double _t20 = _t13*_t6;
  const double _t21 = _t15*_t18;
  const double _t22 = ((_hc0[2]) * (_hc0[2]));
  const double _t23 = _t13*_t5;
  const double _t24 = _hc0[1]*_hc0[3];
  const double _t25 = _hc0[2]*_hc0[3];
  const double _t26 = ((_hc0[3]) * (_hc0[3]));
  const double _t27 = 0.3e1*_t2*_t4;
  const double _t28 = _hc0[1]*_hc0[4];
  const double _t29 = _hc0[2]*_hc0[4];
  const double _t30 = _hc0[3]*_hc0[4];
  const double _t31 = ((_hc0[4]) * (_hc0[4]));
#endif
#if _KMAX >= 3
  const double _t32 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t33 = 0.54e2*_t2;
  const double _t34 = _t33*_t5;
  const double _t35 = 0.48e2*xc_powi((_hc0[0]), 6)/(_t3 * _t3 * _t3 * _t3);
  const double _t36 = _t14*_t33;
  const double _t37 = _t10*_t35;
  const double _t38 = _t33*_t6;
  const double _t39 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t40 = _hc0[3]*_t22;
  const double _t41 = _hc0[1]*_hc0[10];
  const double _t42 = _t11*_t26;
  const double _t43 = 0.96e2*_t7;
  const double _t44 = _t15*_t43;
  const double _t45 = _hc0[1]*_t26;
  const double _t46 = _hc0[10]*_hc0[2];
  const double _t47 = _hc0[2]*_t26;
  const double _t48 = ((_hc0[3]) * (_hc0[3]) * (_hc0[3]));
  const double _t49 = _hc0[10]*_hc0[3];
  const double _t50 = _hc0[0]*_t4;
  const double _t51 = 0.18e2*_t50;
  const double _t52 = _t1*_t5;
  const double _t53 = 0.42e2*_t52;
  const double _t54 = _t15*_t17;
  const double _t55 = 0.24e2*_t54;
  const double _t56 = 0.12e2*_hc0[11];
  const double _t57 = 0.28e2*_hc0[11];
  const double _t58 = 0.16e2*_t54;
  const double _t59 = _hc0[11]*_t58;
  const double _t60 = _hc0[1]*_hc0[12];
  const double _t61 = _hc0[11]*_hc0[2];
  const double _t62 = _hc0[4]*_t19;
  const double _t63 = _hc0[12]*_hc0[2];
  const double _t64 = 0.12e2*_t50;
  const double _t65 = 0.28e2*_t52;
  const double _t66 = _hc0[4]*_t22;
  const double _t67 = _hc0[1]*_hc0[13];
  const double _t68 = _hc0[11]*_hc0[3];
  const double _t69 = _hc0[4]*_t11;
  const double _t70 = _hc0[4]*_t24;
  const double _t71 = _hc0[12]*_hc0[3];
  const double _t72 = _hc0[13]*_hc0[2];
  const double _t73 = _hc0[4]*_t25;
  const double _t74 = _hc0[10]*_hc0[4];
  const double _t75 = _hc0[13]*_hc0[3];
  const double _t76 = _hc0[4]*_t26;
  const double _t77 = _hc0[1]*_hc0[14];
  const double _t78 = _t11*_t31;
  const double _t79 = _hc0[1]*_t31;
  const double _t80 = _hc0[12]*_hc0[4];
  const double _t81 = _hc0[14]*_hc0[2];
  const double _t82 = _hc0[2]*_t31;
  const double _t83 = _hc0[13]*_hc0[4];
  const double _t84 = _hc0[14]*_hc0[3];
  const double _t85 = _hc0[3]*_t31;
  const double _t86 = ((_hc0[4]) * (_hc0[4]) * (_hc0[4]));
  const double _t87 = _hc0[14]*_hc0[4];
#endif

  const double f = _t1*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dts1 = 0.3e1*_hc0[1]*_t2*_t4 - _t6*_t8;
  out[1] = df_dts1;
  const double df_dts0 = 0.3e1*_hc0[2]*_t2*_t4 - _hc0[2]*_t9;
  out[2] = df_dts0;
  const double df_dxt = 0.3e1*_hc0[3]*_t2*_t4 - _hc0[3]*_t9;
  out[3] = df_dxt;
  const double df_drs = 0.3e1*_hc0[4]*_t2*_t4 - _hc0[4]*_t9;
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dts12 = _t10*_t12 - _t13*_t14 + _t16*_t18;
  out[5] = d2f_dts12;
  const double d2f_dts0_dts1 = -_hc0[2]*_t20 + _t12*_t19 + _t19*_t21;
  out[6] = d2f_dts0_dts1;
  const double d2f_dts02 = _t12*_t22 + _t21*_t22 - _t22*_t23;
  out[7] = d2f_dts02;
  const double d2f_dxt_dts1 = -_hc0[3]*_t20 + _t12*_t24 + _t21*_t24;
  out[8] = d2f_dxt_dts1;
  const double d2f_dxt_dts0 = _t12*_t25 + _t21*_t25 - _t23*_t25;
  out[9] = d2f_dxt_dts0;
  const double d2f_dxt2 = _hc0[10]*_t27 - _hc0[10]*_t9 + _t12*_t26 + _t21*_t26 - _t23*_t26;
  out[10] = d2f_dxt2;
  const double d2f_drs_dts1 = _hc0[11]*_t27 - _hc0[11]*_t9 - _hc0[4]*_t20 + _t12*_t28 + _t21*_t28;
  out[11] = d2f_drs_dts1;
  const double d2f_drs_dts0 = _hc0[12]*_t27 - _hc0[12]*_t9 + _t12*_t29 + _t21*_t29 - _t23*_t29;
  out[12] = d2f_drs_dts0;
  const double d2f_drs_dxt = _hc0[13]*_t27 - _hc0[13]*_t9 + _t12*_t30 + _t21*_t30 - _t23*_t30;
  out[13] = d2f_drs_dxt;
  const double d2f_drs2 = _hc0[14]*_t27 - _hc0[14]*_t9 + _t12*_t31 + _t21*_t31 - _t23*_t31;
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dts13 = 0.96e2*_t15*_t32*_t7 - _t32*_t34 - _t32*_t35 + 0.6e1*_t32*_t4;
  out[15] = d3f_dts13;
  const double d3f_dts0_dts12 = 0.96e2*_hc0[2]*_t10*_t15*_t7 + 0.6e1*_hc0[2]*_t10*_t4 - _hc0[2]*_t36 - _hc0[2]*_t37;
  out[16] = d3f_dts0_dts12;
  const double d3f_dts02_dts1 = 0.96e2*_hc0[1]*_t15*_t22*_t7 - _hc0[1]*_t22*_t35 + 0.6e1*_hc0[1]*_t22*_t4 - _t22*_t38;
  out[17] = d3f_dts02_dts1;
  const double d3f_dts03 = 0.96e2*_t15*_t39*_t7 - _t34*_t39 - _t35*_t39 + 0.6e1*_t39*_t4;
  out[18] = d3f_dts03;
  const double d3f_dxt_dts12 = 0.96e2*_hc0[3]*_t10*_t15*_t7 + 0.6e1*_hc0[3]*_t10*_t4 - _hc0[3]*_t36 - _hc0[3]*_t37;
  out[19] = d3f_dxt_dts12;
  const double d3f_dxt_dts0_dts1 = 0.96e2*_hc0[1]*_hc0[2]*_hc0[3]*_t15*_t7 + 0.6e1*_hc0[1]*_hc0[2]*_hc0[3]*_t4 - _hc0[3]*_t19*_t35 - _t25*_t38;
  out[20] = d3f_dxt_dts0_dts1;
  const double d3f_dxt_dts02 = 0.96e2*_hc0[3]*_t15*_t22*_t7 + 0.6e1*_hc0[3]*_t22*_t4 - _t34*_t40 - _t35*_t40;
  out[21] = d3f_dxt_dts02;
  const double d3f_dxt2_dts1 = _hc0[1]*_t42 - _hc0[10]*_t20 + _t12*_t41 + _t21*_t41 - _t26*_t38 - _t35*_t45 + _t44*_t45;
  out[22] = d3f_dxt2_dts1;
  const double d3f_dxt2_dts0 = _hc0[2]*_t42 + _t12*_t46 + _t21*_t46 - _t23*_t46 - _t34*_t47 - _t35*_t47 + _t44*_t47;
  out[23] = d3f_dxt2_dts0;
  const double d3f_dxt3 = _t11*_t48 - _t34*_t48 - _t35*_t48 + _t44*_t48 + _t49*_t51 - _t49*_t53 + _t49*_t55;
  out[24] = d3f_dxt3;
  const double d3f_drs_dts12 = _hc0[0]*_hc0[1]*_t4*_t56 + _hc0[1]*_t59 + _hc0[4]*_t10*_t11 + _hc0[4]*_t16*_t43 - _hc0[4]*_t36 - _hc0[4]*_t37 - _t1*_t57*_t6;
  out[25] = d3f_drs_dts12;
  const double d3f_drs_dts0_dts1 = -_hc0[12]*_t20 + _hc0[4]*_t11*_t19 + _t12*_t60 + _t12*_t61 + _t21*_t60 + _t21*_t61 - _t23*_t61 - _t29*_t38 - _t35*_t62 + _t44*_t62;
  out[26] = d3f_drs_dts0_dts1;
  const double d3f_drs_dts02 = _hc0[4]*_t11*_t22 - _t34*_t66 - _t35*_t66 + _t44*_t66 + _t58*_t63 + _t63*_t64 - _t63*_t65;
  out[27] = d3f_drs_dts02;
  const double d3f_drs_dxt_dts1 = -_hc0[13]*_t20 + _t12*_t67 + _t12*_t68 + _t21*_t67 + _t21*_t68 - _t23*_t68 + _t24*_t69 - _t30*_t38 - _t35*_t70 + _t44*_t70;
  out[28] = d3f_drs_dxt_dts1;
  const double d3f_drs_dxt_dts0 = _t12*_t71 + _t12*_t72 + _t21*_t71 + _t21*_t72 - _t23*_t71 - _t23*_t72 + _t25*_t69 - _t34*_t73 - _t35*_t73 + _t44*_t73;
  out[29] = d3f_drs_dxt_dts0;
  const double d3f_drs_dxt2 = _hc0[30]*_t27 - _hc0[30]*_t9 + _hc0[4]*_t42 + _t12*_t74 + _t21*_t74 - _t23*_t74 - _t34*_t76 - _t35*_t76 + _t44*_t76 + _t58*_t75 + _t64*_t75 - _t65*_t75;
  out[30] = d3f_drs_dxt2;
  const double d3f_drs2_dts1 = _hc0[1]*_t78 - _hc0[14]*_t20 + _hc0[31]*_t27 - _hc0[31]*_t9 + _hc0[4]*_t50*_t56 - _hc0[4]*_t52*_t57 + _hc0[4]*_t59 + _t12*_t77 + _t21*_t77 - _t31*_t38 - _t35*_t79 + _t44*_t79;
  out[31] = d3f_drs2_dts1;
  const double d3f_drs2_dts0 = _hc0[2]*_t78 + _hc0[32]*_t27 - _hc0[32]*_t9 + _t12*_t81 + _t21*_t81 - _t23*_t81 - _t34*_t82 - _t35*_t82 + _t44*_t82 + _t58*_t80 + _t64*_t80 - _t65*_t80;
  out[32] = d3f_drs2_dts0;
  const double d3f_drs2_dxt = _hc0[3]*_t78 + _hc0[33]*_t27 - _hc0[33]*_t9 + _t12*_t84 + _t21*_t84 - _t23*_t84 - _t34*_t85 - _t35*_t85 + _t44*_t85 + _t58*_t83 + _t64*_t83 - _t65*_t83;
  out[33] = d3f_drs2_dxt;
  const double d3f_drs3 = _hc0[34]*_t27 - _hc0[34]*_t9 + _t11*_t86 - _t34*_t86 - _t35*_t86 + _t44*_t86 + _t51*_t87 - _t53*_t87 + _t55*_t87;
  out[34] = d3f_drs3;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double ta = tau[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = _t4/xc_powr(na, 1, 3);
  const double _t6 = xc_powr(gaa, 1, 2);
  const double _t7 = xc_powr(na, -4, 3);
  const double _t8 = _t6*_t7;
  const double _t9 = xc_powr(0.3e1, 2, 3);
  const double _t10 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t11 = _t10*_t9;
  const double _t12 = xc_powr(0.2e1, 2, 3);
  const double _t13 = _t12/xc_powr(na, 5, 3);
  const double _t14 = _t13*ta;
  double _hc0[(_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(f_pbe_z0_k, _KMAX)(p, _t5, _t8, 0, 0, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_H0_k, _KMAX)(p, _t5, (0.1e1 / 0.6e1)*_t11*_t8, _hc1);
  double _hc2[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_eclda0_k, _KMAX)(p, _t5, _hc2);
  double _hc3[(_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(rscan_alpha_z0_k, _KMAX)(p, _t5, _t8, _t14, _t14, _hc3);
  const double _t15 = 1.0*_hc3[0] - 2.5;
  const double _t16 = _t15 > 0;
  const double _t17 = -_hc0[0] + _hc1[0] + _hc2[0];
  const double _t18 = _t15 <= 0;
  const double _t19 = my_piecewise3(_t16, 2.5, _hc3[0]);
  const double _t20 = (_t19 * _t19);
  const double _t21 = (_t19 * _t19 * _t19);
  const double _t22 = (_t19 * _t19 * _t19 * _t19);
  const double _t23 = xc_powi(_t19, 5);
  const double _t24 = xc_powi(_t19, 6);
  double _hc4[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(rscan_f_alpha_large_k, _KMAX)(p, my_piecewise3(_t16, _hc3[0], 2.5), _hc4);
  const double _t25 = my_piecewise3(_t18, -0.051848879792000001*xc_powi(_t19, 7) - 0.64000000000000001*_t19 - 0.43519999999999998*_t20 - 1.5356856045489999*_t21 + 3.0615602521750001*_t22 - 1.9157102362059999*_t23 + 0.51688446837199997*_t24 + 0.1e1, _hc4[0]);
  const double _t26 = _hc0[0] + _t17*_t25;
  const double zk = _t26;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t27 = xc_powr(na, -7, 3);
  const double _t28 = (0.4e1 / 0.3e1)*_t27;
  const double _t29 = _t28*_t6;
  const double _t31 = (0.1e1 / 0.6e1)*_t7;
  const double _t32 = _t3*_t31;
  const double _t35 = _t27*_t6;
  const double _t36 = (0.2e1 / 0.9e1)*_t35;
  const double _t40 = xc_powr(na, -8, 3);
  const double _t41 = (0.5e1 / 0.3e1)*_t40;
  const double _t43 = _t12*_t41;
  const double _t54 = (0.1e1 / _t6);
  const double _t56 = (0.1e1 / 0.2e1)*_t7;
  const double _t30 = _hc0[3]*_t29;
  const double _t33 = _hc0[4]*_t32;
  const double _t34 = _hc1[1]*_t11;
  const double _t37 = -_hc1[2]*_t32 - _hc2[1]*_t32 + _t30 + _t33 - _t34*_t36;
  const double _t38 = _hc3[3]*_t6;
  const double _t39 = _hc3[1]*_t12;
  const double _t42 = _t39*_t41;
  const double _t44 = _hc3[2]*_t43;
  const double _t45 = _hc3[4]*_t3;
  const double _t46 = -_t28*_t38 - _t31*_t45 - _t42*ta - _t44*ta;
  const double _t47 = my_piecewise3(_t16, 0, _t46);
  const double _t48 = 0.87039999999999995*_t19;
  const double _t49 = 4.6070568136469996*_t20;
  const double _t50 = 9.578551181029999*_t22;
  const double _t51 = 0.36294215854400003*_t24;
  const double _t52 = my_piecewise3(_t16, _t46, 0);
  const double _t55 = _hc0[3]*_t54;
  const double _t57 = _t55*_t56;
  const double _t58 = (0.1e1 / 0.12e2)*_hc1[1]*_t10*_t54*_t7*_t9 - _t57;
  const double _t59 = _hc3[3]*_t54;
  const double _t60 = _t56*_t59;
  const double _t61 = my_piecewise3(_t16, 0, _t60);
  const double _t62 = my_piecewise3(_t16, _t60, 0);
  const double _t65 = _hc3[1]*_t13 + _hc3[2]*_t13;
  const double _t66 = my_piecewise3(_t16, 0, _t65);
  const double _t67 = my_piecewise3(_t16, _t65, 0);
  const double _t53 = my_piecewise3(_t18, 12.2462410087*_t21*_t47 + 3.1013068102319998*_t23*_t47 - _t47*_t48 - _t47*_t49 - _t47*_t50 - _t47*_t51 - 0.64000000000000001*_t47, _hc4[1]*_t52);
  const double _t63 = my_piecewise3(_t18, 12.2462410087*_t21*_t61 + 3.1013068102319998*_t23*_t61 - _t48*_t61 - _t49*_t61 - _t50*_t61 - _t51*_t61 - 0.64000000000000001*_t61, _hc4[1]*_t62);
  const double _t64 = _t17*_t63 + _t25*_t58 + _t57;
  const double _t68 = my_piecewise3(_t18, 12.2462410087*_t21*_t66 + 3.1013068102319998*_t23*_t66 - _t48*_t66 - _t49*_t66 - _t50*_t66 - _t51*_t66 - 0.64000000000000001*_t66, _hc4[1]*_t67);
  const double _t69 = _t17*_t68;
  const double dF_dna = _t26 + na*(_t17*_t53 + _t25*_t37 - _t30 - _t33);
  const double dF_dgaa = _t64*na;
  const double dF_dta = _t69*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double _t72 = xc_powr(na, -10, 3);
  const double _t73 = (0.28e2 / 0.9e1)*_t72;
  const double _t75 = (0.2e1 / 0.9e1)*_t27;
  const double _t76 = _t3*_t75;
  const double _t84 = _t6*_t72;
  const double _t85 = (0.14e2 / 0.27e2)*_t84;
  const double _t86 = _t11*_t36;
  const double _t96 = xc_powr(na, -11, 3);
  const double _t97 = (0.40e2 / 0.9e1)*_t96;
  const double _t99 = _t12*_t97;
  const double _t121 = (0.2e1 / 0.3e1)*_t96;
  const double _t123 = (0.2e1 / 0.3e1)*_t27;
  const double _t125 = (0.1e1 / 0.12e2)*_t40*_t54;
  const double _t126 = _t125*_t3;
  const double _t128 = (0.1e1 / 0.18e2)*_t96;
  const double _t129 = M_CBRT3;
  const double _t130 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t132 = (0.1e1 / 0.24e2)*_t40;
  const double _t133 = (0.1e1 / M_PI);
  const double _t134 = M_CBRT2;
  const double _t136 = (0.1e1 / 0.9e1)*_t27;
  const double _t141 = _t12*ta;
  const double _t142 = (0.1e1 / (na * na * na * na));
  const double _t143 = (0.5e1 / 0.6e1)*_t142*_t54;
  const double _t144 = _t141*_t143;
  const double _t159 = _t43*ta;
  const double _t168 = (0.1e1 / gaa);
  const double _t170 = (0.1e1 / 0.4e1)*_t40;
  const double _t171 = xc_powr(gaa, -3, 2);
  const double _t172 = (0.1e1 / 0.4e1)*_t7;
  const double _t179 = _t168*_t170;
  const double _t70 = _hc0[3]*_t6;
  const double _t71 = _hc0[4]*_t3;
  const double _t74 = _t70*_t73;
  const double _t77 = _hc0[4]*_t76;
  const double _t78 = (0.4e1 / 0.3e1)*_hc0[10];
  const double _t79 = -_hc0[13]*_t32 - _t35*_t78;
  const double _t80 = _t29*_t79;
  const double _t81 = -_hc0[13]*_t29 - _hc0[14]*_t32;
  const double _t82 = _t32*_t81;
  const double _t83 = xc_powr(0.6e1, 2, 3)*_hc2[2]*_t10;
  const double _t87 = -_hc1[4]*_t86 - _hc1[5]*_t32;
  const double _t88 = -_hc1[3]*_t86 - _hc1[4]*_t32;
  const double _t89 = _hc1[2]*_t76 + _hc2[1]*_t76 - _t32*_t87 + _t34*_t85 + (0.1e1 / 0.36e2)*_t40*_t83 - _t74 - _t77 + _t80 + _t82 - _t86*_t88;
  const double _t92 = (_t47 * _t47);
  const double _t93 = 9.2141136272939992*_t19;
  const double _t94 = 38.314204724119996*_t21;
  const double _t95 = 2.1776529512640002*_t23;
  const double _t98 = _t39*_t97;
  const double _t100 = _hc3[2]*_t99;
  const double _t101 = _hc3[8]*_t43;
  const double _t102 = _hc3[9]*_t43;
  const double _t103 = -_hc3[10]*_t29 - _hc3[13]*_t32 - _t101*ta - _t102*ta;
  const double _t104 = _hc3[5]*_t43;
  const double _t105 = _hc3[6]*_t43;
  const double _t106 = _t105*ta;
  const double _t107 = -_hc3[11]*_t32 - _hc3[8]*_t29 - _t104*ta - _t106;
  const double _t108 = _t107*_t43;
  const double _t109 = _hc3[7]*_t43;
  const double _t110 = -_hc3[12]*_t32 - _hc3[9]*_t29 - _t106 - _t109*ta;
  const double _t111 = _t110*_t43;
  const double _t112 = _hc3[11]*_t43;
  const double _t113 = _hc3[12]*_t43;
  const double _t114 = -_hc3[13]*_t29 - _hc3[14]*_t32 - _t112*ta - _t113*ta;
  const double _t115 = _t100*ta - _t103*_t29 - _t108*ta - _t111*ta - _t114*_t32 + _t38*_t73 + _t45*_t75 + _t98*ta;
  const double _t116 = my_piecewise3(_t16, 0, _t115);
  const double _t117 = (_t52 * _t52);
  const double _t118 = my_piecewise3(_t16, _t115, 0);
  const double _t122 = _hc0[10]*_t121;
  const double _t124 = _t123*_t55;
  const double _t127 = _hc0[13]*_t126;
  const double _t131 = _hc1[3]*_t129*_t130;
  const double _t135 = _hc1[4]*_t54;
  const double _t137 = _t122 + _t124 + _t127 - _t128*_t131 - _t132*_t133*_t134*_t135 - _t136*_t34*_t54;
  const double _t145 = _hc3[13]*_t3;
  const double _t146 = -_hc3[10]*_t121 - _hc3[8]*_t144 - _hc3[9]*_t144 - _t123*_t59 - _t125*_t145;
  const double _t147 = my_piecewise3(_t16, 0, _t146);
  const double _t148 = 0.87039999999999995*_t47;
  const double _t149 = _t47*_t61;
  const double _t150 = my_piecewise3(_t16, _t146, 0);
  const double _t155 = _t47*_t66;
  const double _t156 = _hc3[8]*_t13 + _hc3[9]*_t13;
  const double _t157 = _hc3[6]*_t13;
  const double _t158 = _hc3[5]*_t13 + _t157;
  const double _t160 = _hc3[7]*_t13 + _t157;
  const double _t161 = _hc3[11]*_t13 + _hc3[12]*_t13;
  const double _t162 = -_t156*_t29 - _t158*_t159 - _t159*_t160 - _t161*_t32 - _t42 - _t44;
  const double _t163 = my_piecewise3(_t16, 0, _t162);
  const double _t164 = my_piecewise3(_t16, _t162, 0);
  const double _t167 = (_t61 * _t61);
  const double _t169 = _hc3[10]*_t168;
  const double _t173 = -_hc3[3]*_t171*_t172 + _t169*_t170;
  const double _t174 = my_piecewise3(_t16, 0, _t173);
  const double _t175 = (_t62 * _t62);
  const double _t176 = my_piecewise3(_t16, _t173, 0);
  const double _t178 = _hc0[3]*_t171;
  const double _t180 = _hc0[10]*_t179 - _t172*_t178;
  const double _t181 = (0.1e1 / 0.48e2)*_hc1[3]*_t129*_t130*_t168*_t40 - 0.1e1 / 0.24e2*_t171*_t34*_t7 - _t180;
  const double _t182 = 0.2e1*_t58;
  const double _t184 = _t156*_t54;
  const double _t185 = _t184*_t56;
  const double _t186 = my_piecewise3(_t16, 0, _t185);
  const double _t187 = 0.87039999999999995*_t61;
  const double _t188 = _t61*_t66;
  const double _t189 = my_piecewise3(_t16, _t185, 0);
  const double _t193 = (_t66 * _t66);
  const double _t194 = _t13*_t158 + _t13*_t160;
  const double _t195 = my_piecewise3(_t16, 0, _t194);
  const double _t196 = (_t67 * _t67);
  const double _t197 = my_piecewise3(_t16, _t194, 0);
  const double _t90 = _t25*_t89;
  const double _t91 = _t37*_t53;
  const double _t119 = my_piecewise3(_t18, 12.2462410087*_t116*_t21 + 3.1013068102319998*_t116*_t23 - _t116*_t48 - _t116*_t49 - _t116*_t50 - _t116*_t51 - 0.64000000000000001*_t116 + 36.738723026100004*_t20*_t92 + 15.506534051159999*_t22*_t92 - _t92*_t93 - _t92*_t94 - _t92*_t95 - 0.87039999999999995*_t92, _hc4[1]*_t118 + _hc4[2]*_t117);
  const double _t120 = _t119*_t17;
  const double _t138 = _t137*_t25;
  const double _t139 = _t37*_t63;
  const double _t140 = _t53*_t58;
  const double _t151 = _hc4[2]*_t52;
  const double _t152 = my_piecewise3(_t18, 12.2462410087*_t147*_t21 + 3.1013068102319998*_t147*_t23 - _t147*_t48 - _t147*_t49 - _t147*_t50 - _t147*_t51 - 0.64000000000000001*_t147 - _t148*_t61 - _t149*_t93 - _t149*_t94 - _t149*_t95 + 36.738723026100004*_t20*_t47*_t61 + 15.506534051159999*_t22*_t47*_t61, _hc4[1]*_t150 + _t151*_t62);
  const double _t153 = _t152*_t17;
  const double _t154 = _t37*_t68;
  const double _t165 = my_piecewise3(_t18, -_t148*_t66 - _t155*_t93 - _t155*_t94 - _t155*_t95 + 12.2462410087*_t163*_t21 + 3.1013068102319998*_t163*_t23 - _t163*_t48 - _t163*_t49 - _t163*_t50 - _t163*_t51 - 0.64000000000000001*_t163 + 36.738723026100004*_t20*_t47*_t66 + 15.506534051159999*_t22*_t47*_t66, _hc4[1]*_t164 + _t151*_t67);
  const double _t166 = _t165*_t17;
  const double _t177 = my_piecewise3(_t18, 36.738723026100004*_t167*_t20 + 15.506534051159999*_t167*_t22 - _t167*_t93 - _t167*_t94 - _t167*_t95 - 0.87039999999999995*_t167 + 12.2462410087*_t174*_t21 + 3.1013068102319998*_t174*_t23 - _t174*_t48 - _t174*_t49 - _t174*_t50 - _t174*_t51 - 0.64000000000000001*_t174, _hc4[1]*_t176 + _hc4[2]*_t175);
  const double _t183 = _t17*_t177 + _t180 + _t181*_t25 + _t182*_t63;
  const double _t190 = _hc4[2]*_t62;
  const double _t191 = my_piecewise3(_t18, 12.2462410087*_t186*_t21 + 3.1013068102319998*_t186*_t23 - _t186*_t48 - _t186*_t49 - _t186*_t50 - _t186*_t51 - 0.64000000000000001*_t186 - _t187*_t66 - _t188*_t93 - _t188*_t94 - _t188*_t95 + 36.738723026100004*_t20*_t61*_t66 + 15.506534051159999*_t22*_t61*_t66, _hc4[1]*_t189 + _t190*_t67);
  const double _t192 = _t17*_t191 + _t58*_t68;
  const double _t198 = my_piecewise3(_t18, 36.738723026100004*_t193*_t20 + 15.506534051159999*_t193*_t22 - _t193*_t93 - _t193*_t94 - _t193*_t95 - 0.87039999999999995*_t193 + 12.2462410087*_t195*_t21 + 3.1013068102319998*_t195*_t23 - _t195*_t48 - _t195*_t49 - _t195*_t50 - _t195*_t51 - 0.64000000000000001*_t195, _hc4[1]*_t197 + _hc4[2]*_t196);
  const double _t199 = _t17*_t198;
  const double d2F_dna2 = 0.2e1*_t17*_t53 + 0.2e1*_t25*_t37 - 0.8e1 / 0.3e1*_t27*_t70 - 0.1e1 / 0.3e1*_t7*_t71 + na*(_t120 + _t74 + _t77 - _t80 - _t82 + _t90 + 0.2e1*_t91);
  const double d2F_dna_dgaa = _t64 + na*(-_t122 - _t124 - _t127 + _t138 + _t139 + _t140 + _t153);
  const double d2F_dna_dta = _t69 + na*(_t154 + _t166);
  const double d2F_dgaa2 = _t183*na;
  const double d2F_dgaa_dta = _t192*na;
  const double d2F_dta2 = _t199*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double _t207 = xc_powr(na, -13, 3);
  const double _t208 = (0.280e3 / 0.27e2)*_t207;
  const double _t209 = xc_powr(na, -14, 3);
  const double _t210 = (0.440e3 / 0.27e2)*_t209*ta;
  const double _t211 = (0.14e2 / 0.27e2)*_t72;
  const double _t212 = _t6*_t73;
  const double _t213 = _t99*ta;
  const double _t226 = _t11*_t85;
  const double _t228 = (0.1e1 / 0.9e1)*_t96;
  const double _t229 = _t211*_t3;
  const double _t241 = (0.14e2 / 0.9e1)*_t209;
  const double _t242 = (0.14e2 / 0.9e1)*_t72;
  const double _t243 = _t54/xc_powi(na, 5);
  const double _t244 = (0.20e2 / 0.9e1)*_t243;
  const double _t245 = _t228*_t54;
  const double _t246 = _t123*_t54;
  const double _t252 = _t128*_t129*_t130;
  const double _t253 = _t133*_t134;
  const double _t254 = _t132*_t253*_t54;
  const double _t255 = _t11*_t136;
  const double _t282 = _t171*_t172;
  const double _t287 = _t142*_t168;
  const double _t293 = (0.5e1 / 0.12e2)*_t141*_t168/xc_powr(na, 16, 3);
  const double _t302 = _t12*_t143;
  const double _t309 = (0.10e2 / 0.3e1)*_t12*_t40;
  const double _t317 = (0.1e1 / (gaa * gaa));
  const double _t319 = _t7/xc_powr(gaa, 5, 2);
  const double _t320 = (0.3e1 / 0.8e1)*_t319;
  const double _t322 = _t54*_t56;
  const double _t324 = _t142*_t171;
  const double _t325 = _t317*_t40;
  const double _t200 = (_t47 * _t47 * _t47);
  const double _t201 = 114.94261417235998*_t20;
  const double _t202 = 10.888264756320002*_t22;
  const double _t203 = _t116*_t47;
  const double _t204 = 27.642340881881999*_t19;
  const double _t205 = 114.94261417235998*_t21;
  const double _t206 = 6.5329588537920005*_t23;
  const double _t214 = _hc3[20]*_t159;
  const double _t215 = -_hc3[19]*_t159 - _hc3[22]*_t29 - _hc3[28]*_t32 - _t214;
  const double _t216 = -_hc3[21]*_t159 - _hc3[23]*_t29 - _hc3[29]*_t32 - _t214;
  const double _t217 = -_hc3[28]*_t159 - _hc3[29]*_t159 - _hc3[30]*_t29 - _hc3[33]*_t32;
  const double _t218 = _hc3[16]*_t159;
  const double _t219 = _hc3[26]*_t159;
  const double _t220 = -_hc3[25]*_t159 - _hc3[28]*_t29 - _hc3[31]*_t32 - _t219;
  const double _t221 = _hc3[17]*_t159;
  const double _t222 = _hc3[6]*_t213 - _t159*(-_hc3[20]*_t29 - _hc3[26]*_t32 - _t218 - _t221);
  const double _t223 = -_hc3[27]*_t159 - _hc3[29]*_t29 - _hc3[32]*_t32 - _t219;
  const double _t224 = -_hc3[2]*_t12*_t210 + (0.4e1 / 0.9e1)*_t1*_t114*_t2*_t27 + (0.56e2 / 0.9e1)*_t103*_t6*_t72 + (0.80e2 / 0.9e1)*_t107*_t12*_t96*ta + (0.80e2 / 0.9e1)*_t110*_t12*_t96*ta - _t159*(_hc3[11]*_t76 + _hc3[5]*_t213 + _hc3[8]*_t212 - _t159*(-_hc3[15]*_t159 - _hc3[19]*_t29 - _hc3[25]*_t32 - _t218) - _t215*_t29 - _t220*_t32 + _t222) - _t159*(_hc3[12]*_t76 + _hc3[7]*_t213 + _hc3[9]*_t212 - _t159*(-_hc3[18]*_t159 - _hc3[21]*_t29 - _hc3[27]*_t32 - _t221) - _t216*_t29 + _t222 - _t223*_t32) - _t208*_t38 - _t210*_t39 - _t211*_t45 - _t29*(_hc3[10]*_t212 + _hc3[13]*_t76 + _hc3[8]*_t213 + _hc3[9]*_t213 - _t159*_t215 - _t159*_t216 - _t217*_t32 - _t29*(-_hc3[22]*_t159 - _hc3[23]*_t159 - _hc3[24]*_t29 - _hc3[30]*_t32)) - _t32*(_hc3[11]*_t213 + _hc3[12]*_t213 + _hc3[13]*_t212 + _hc3[14]*_t76 - _t159*_t220 - _t159*_t223 - _t217*_t29 - _t32*(-_hc3[31]*_t159 - _hc3[32]*_t159 - _hc3[33]*_t29 - _hc3[34]*_t32));
  const double _t225 = my_piecewise3(_t16, 0, _t224);
  const double _t227 = -_hc1[7]*_t86 - _hc1[8]*_t32;
  const double _t230 = -_hc0[30]*_t29 - _hc0[33]*_t32;
  const double _t231 = -_t208*_t70 - _t211*_t71 + (0.4e1 / 0.9e1)*_t27*_t3*_t81 - _t29*(_hc0[10]*_t212 + _hc0[13]*_t76 - _t230*_t32 - _t29*(-_hc0[24]*_t29 - _hc0[30]*_t32)) - _t32*(_hc0[13]*_t212 + _hc0[14]*_t76 - _t230*_t29 - _t32*(-_hc0[33]*_t29 - _hc0[34]*_t32)) + (0.56e2 / 0.9e1)*_t79*_t84;
  const double _t232 = _hc0[13]*_t3;
  const double _t233 = 9.2141136272939992*_t92;
  const double _t234 = _t61*_t92;
  const double _t235 = 1.7407999999999999*_t47;
  const double _t236 = _t147*_t47;
  const double _t237 = 18.428227254587998*_t19;
  const double _t238 = 76.628409448239992*_t21;
  const double _t239 = 4.3553059025280003*_t23;
  const double _t240 = _t116*_t61;
  const double _t247 = _hc3[20]*_t144;
  const double _t248 = _hc3[10]*_t241 + _hc3[8]*_t141*_t244 + _hc3[9]*_t141*_t244 - _t103*_t246 + _t145*_t245 - _t159*(-_hc3[19]*_t144 - _hc3[22]*_t121 - _hc3[28]*_t126 - _hc3[8]*_t246 - _t247) - _t159*(-_hc3[21]*_t144 - _hc3[23]*_t121 - _hc3[29]*_t126 - _hc3[9]*_t246 - _t247) + _t242*_t59 - _t29*(-_hc3[10]*_t246 - _hc3[22]*_t144 - _hc3[23]*_t144 - _hc3[24]*_t121 - _hc3[30]*_t126) - _t32*(-_hc3[13]*_t246 - _hc3[28]*_t144 - _hc3[29]*_t144 - _hc3[30]*_t121 - _hc3[33]*_t126);
  const double _t249 = my_piecewise3(_t16, 0, _t248);
  const double _t256 = _hc0[10]*_t241 + _t232*_t245 + _t242*_t55 - _t246*_t79 - _t29*(-_hc0[10]*_t246 - _hc0[24]*_t121 - _hc0[30]*_t126) - _t32*(-_hc0[13]*_t246 - _hc0[30]*_t121 - _hc0[33]*_t126);
  const double _t257 = 0.2e1*_t37;
  const double _t258 = 0.2e1*_t137;
  const double _t259 = _t66*_t92;
  const double _t260 = _t163*_t47;
  const double _t261 = 0.87039999999999995*_t66;
  const double _t262 = _t116*_t66;
  const double _t263 = _hc3[22]*_t13 + _hc3[23]*_t13;
  const double _t264 = _hc3[20]*_t13;
  const double _t265 = _hc3[19]*_t13 + _t264;
  const double _t266 = _hc3[21]*_t13 + _t264;
  const double _t267 = _hc3[28]*_t13 + _hc3[29]*_t13;
  const double _t268 = _hc3[26]*_t13;
  const double _t269 = _hc3[25]*_t13 + _t268;
  const double _t270 = _hc3[16]*_t13;
  const double _t271 = _hc3[15]*_t13 + _t270;
  const double _t272 = _hc3[17]*_t13;
  const double _t273 = _t270 + _t272;
  const double _t274 = _t105 + _t159*_t273;
  const double _t275 = _hc3[27]*_t13 + _t268;
  const double _t276 = _hc3[18]*_t13 + _t272;
  const double _t277 = _t100 - _t108 - _t111 + _t156*_t212 + _t158*_t213 - _t159*(-_t104 - _t159*_t271 - _t265*_t29 - _t269*_t32 - _t274) - _t159*(-_t109 - _t159*_t276 - _t266*_t29 - _t274 - _t275*_t32) + _t160*_t213 + _t161*_t76 - _t29*(-_t101 - _t102 - _t159*_t265 - _t159*_t266 - _t263*_t29 - _t267*_t32) - _t32*(-_t112 - _t113 - _t159*_t269 - _t159*_t275 - _t267*_t29 - _t32*(_hc3[31]*_t13 + _hc3[32]*_t13)) + _t98;
  const double _t278 = my_piecewise3(_t16, 0, _t277);
  const double _t280 = _t122*_t168;
  const double _t281 = (0.1e1 / 0.3e1)*_t178*_t27;
  const double _t283 = -_hc0[10]*_t282 + (0.1e1 / 0.4e1)*_hc0[24]*_t168*_t40;
  const double _t284 = _t283*_t29;
  const double _t285 = _t32*(-_hc0[13]*_t282 + (0.1e1 / 0.4e1)*_hc0[30]*_t168*_t40);
  const double _t286 = _hc1[6]/(M_PI * M_PI);
  const double _t288 = 9.2141136272939992*_t47;
  const double _t289 = _t167*_t47;
  const double _t290 = 1.7407999999999999*_t61;
  const double _t291 = _t174*_t47;
  const double _t292 = _t147*_t61;
  const double _t294 = (0.1e1 / 0.24e2)*_hc3[13]*_t1*_t171*_t2*_t40 - _hc3[22]*_t293 - _hc3[23]*_t293 - 0.1e1 / 0.3e1*_hc3[24]*_t243 + (0.1e1 / 0.3e1)*_hc3[3]*_t171*_t27 - 0.1e1 / 0.24e2*_hc3[30]*_t287*_t3 + (0.5e1 / 0.12e2)*_hc3[8]*_t12*_t142*_t171*ta + (0.5e1 / 0.12e2)*_hc3[9]*_t12*_t142*_t171*ta - 0.1e1 / 0.3e1*_t169*_t96;
  const double _t295 = my_piecewise3(_t16, 0, _t294);
  const double _t298 = _t186*_t47;
  const double _t299 = _t147*_t66;
  const double _t300 = _t149*_t66;
  const double _t301 = _t163*_t61;
  const double _t303 = -_hc3[8]*_t302 - _hc3[9]*_t302 - _t121*_t263 - _t123*_t184 - _t126*_t267 - _t144*_t265 - _t144*_t266;
  const double _t304 = my_piecewise3(_t16, 0, _t303);
  const double _t305 = _t193*_t47;
  const double _t306 = _t195*_t47;
  const double _t307 = 1.7407999999999999*_t66;
  const double _t308 = _t163*_t66;
  const double _t310 = _t13*_t265 + _t13*_t266;
  const double _t311 = _t13*_t273;
  const double _t312 = _t13*_t271 + _t311;
  const double _t313 = _t13*_t276 + _t311;
  const double _t314 = -_t158*_t309 - _t159*_t312 - _t159*_t313 - _t160*_t309 - _t29*_t310 - _t32*(_t13*_t269 + _t13*_t275);
  const double _t315 = my_piecewise3(_t16, 0, _t314);
  const double _t318 = _hc0[10]*_t170*_t317;
  const double _t321 = _hc0[3]*_t320;
  const double _t323 = _t283*_t322;
  const double _t326 = (_t61 * _t61 * _t61);
  const double _t327 = -0.3e1 / 0.8e1*_hc3[10]*_t325 + (0.1e1 / 0.8e1)*_hc3[24]*_t324 + _hc3[3]*_t320;
  const double _t328 = my_piecewise3(_t16, 0, _t327);
  const double _t329 = _t174*_t61;
  const double _t330 = _t167*_t66;
  const double _t331 = _t186*_t61;
  const double _t332 = -_t156*_t282 + _t179*_t263;
  const double _t333 = my_piecewise3(_t16, 0, _t332);
  const double _t334 = _t174*_t66;
  const double _t335 = _t193*_t61;
  const double _t336 = _t310*_t322;
  const double _t337 = my_piecewise3(_t16, 0, _t336);
  const double _t338 = _t186*_t66;
  const double _t339 = _t195*_t61;
  const double _t340 = (_t66 * _t66 * _t66);
  const double _t341 = _t195*_t66;
  const double _t342 = _t13*_t312 + _t13*_t313;
  const double _t343 = my_piecewise3(_t16, 0, _t342);
  const double _t250 = _hc4[3]*_t117;
  const double _t251 = 0.2e1*_t151;
  const double _t279 = _hc4[2]*_t67;
  const double _t296 = _hc4[3]*_t52;
  const double _t297 = 0.2e1*_t190;
  const double _t316 = 0.2e1*_t279;
  const double d3F_dna3 = 0.3e1*_t120 + _t123*_t71 - 0.4e1*_t35*_t79 - _t4*_t7*_t81 + (0.28e2 / 0.3e1)*_t70*_t72 + 0.3e1*_t90 + 0.6e1*_t91 + na*(0.3e1*_t119*_t37 + _t17*my_piecewise3(_t18, 110.21616907830001*_t116*_t20*_t47 + 46.519602153479994*_t116*_t22*_t47 + 73.477446052200008*_t19*_t200 - _t200*_t201 - _t200*_t202 + 62.026136204639997*_t200*_t21 - 9.2141136272939992*_t200 - _t203*_t204 - _t203*_t205 - _t203*_t206 - 2.6111999999999997*_t203 + 12.2462410087*_t21*_t225 + 3.1013068102319998*_t225*_t23 - _t225*_t48 - _t225*_t49 - _t225*_t50 - _t225*_t51 - 0.64000000000000001*_t225, _hc4[1]*my_piecewise3(_t16, _t224, 0) + _hc4[3]*(_t52 * _t52 * _t52) + 0.3e1*_t118*_t151) + _t231 + _t25*(-_hc1[2]*_t229 - _hc2[1]*_t229 - 0.1e1 / 0.36e2*_hc2[3]*_t133*_t142 + (0.4e1 / 0.9e1)*_t1*_t2*_t27*_t87 + (0.28e2 / 0.27e2)*_t10*_t6*_t72*_t88*_t9 - 0.140e3 / 0.81e2*_t207*_t34*_t6 - _t228*_t83 - _t231 - _t32*(_hc1[4]*_t226 + _hc1[5]*_t76 - _t227*_t86 - _t32*(-_hc1[8]*_t86 - _hc1[9]*_t32)) - _t86*(_hc1[3]*_t226 + _hc1[4]*_t76 - _t227*_t32 - _t86*(-_hc1[6]*_t86 - _hc1[7]*_t32))) + 0.3e1*_t53*_t89);
  const double d3F_dna2_dgaa = 0.2e1*_t138 + 0.2e1*_t139 + 0.2e1*_t140 + 0.2e1*_t153 - 0.1e1 / 0.6e1*_t232*_t40*_t54 - _t28*_t55 - _t78*_t96 + na*(_t119*_t58 + _t152*_t257 + _t17*my_piecewise3(_t18, -_t116*_t187 + 36.738723026100004*_t116*_t20*_t61 + 15.506534051159999*_t116*_t22*_t61 + 73.477446052200008*_t147*_t20*_t47 + 31.013068102319998*_t147*_t22*_t47 - _t147*_t235 + 73.477446052200008*_t19*_t61*_t92 - _t201*_t234 - _t202*_t234 + 12.2462410087*_t21*_t249 + 62.026136204639997*_t21*_t61*_t92 + 3.1013068102319998*_t23*_t249 - _t233*_t61 - _t236*_t237 - _t236*_t238 - _t236*_t239 - _t240*_t93 - _t240*_t94 - _t240*_t95 - _t249*_t48 - _t249*_t49 - _t249*_t50 - _t249*_t51 - 0.64000000000000001*_t249, _hc4[1]*my_piecewise3(_t16, _t248, 0) + _t118*_t190 + _t150*_t251 + _t250*_t62) + _t25*((0.7e1 / 0.27e2)*_hc1[1]*_t10*_t54*_t72*_t9 + (0.7e1 / 0.54e2)*_hc1[3]*_t129*_t130*_t209 + (0.1e1 / 0.18e2)*_hc1[4]*_t133*_t134*_t54*_t96 - _t11*_t136*_t54*_t88 - _t256 - _t32*(-_hc1[7]*_t252 - _hc1[8]*_t254 - _t135*_t255) - _t86*(-_hc1[3]*_t255*_t54 - _hc1[6]*_t252 - _hc1[7]*_t254)) + _t256 + _t258*_t53 + _t63*_t89);
  const double d3F_dna2_dta = 0.2e1*_t154 + 0.2e1*_t166 + na*(_t165*_t257 + _t17*my_piecewise3(_t18, 36.738723026100004*_t116*_t20*_t66 + 15.506534051159999*_t116*_t22*_t66 - _t116*_t261 + 73.477446052200008*_t163*_t20*_t47 + 31.013068102319998*_t163*_t22*_t47 - _t163*_t235 + 73.477446052200008*_t19*_t66*_t92 - _t201*_t259 - _t202*_t259 + 12.2462410087*_t21*_t278 + 62.026136204639997*_t21*_t66*_t92 + 3.1013068102319998*_t23*_t278 - _t233*_t66 - _t237*_t260 - _t238*_t260 - _t239*_t260 - _t262*_t93 - _t262*_t94 - _t262*_t95 - _t278*_t48 - _t278*_t49 - _t278*_t50 - _t278*_t51 - 0.64000000000000001*_t278, _hc4[1]*my_piecewise3(_t16, _t277, 0) + _t118*_t279 + _t164*_t251 + _t250*_t67) + _t68*_t89);
  const double d3F_dna_dgaa2 = _t183 + na*(_t152*_t182 + _t17*my_piecewise3(_t18, 73.477446052200008*_t147*_t20*_t61 + 31.013068102319998*_t147*_t22*_t61 - _t147*_t290 - _t148*_t174 + 73.477446052200008*_t167*_t19*_t47 + 62.026136204639997*_t167*_t21*_t47 - _t167*_t288 + 36.738723026100004*_t174*_t20*_t47 + 15.506534051159999*_t174*_t22*_t47 - _t201*_t289 - _t202*_t289 + 12.2462410087*_t21*_t295 + 3.1013068102319998*_t23*_t295 - _t237*_t292 - _t238*_t292 - _t239*_t292 - _t291*_t93 - _t291*_t94 - _t291*_t95 - _t295*_t48 - _t295*_t49 - _t295*_t50 - _t295*_t51 - 0.64000000000000001*_t295, _hc4[1]*my_piecewise3(_t16, _t294, 0) + _t150*_t297 + _t151*_t176 + _t175*_t296) + _t177*_t37 + _t181*_t53 + _t25*((0.1e1 / 0.48e2)*_hc1[4]*_t171*_t253*_t40 - 0.1e1 / 0.288e3*_hc1[7]*_t134*_t287*_t9/(M_PI * M_CBRTPI * M_CBRTPI) - 0.1e1 / 0.36e2*_t131*_t168*_t96 + (0.1e1 / 0.18e2)*_t171*_t27*_t34 - 0.1e1 / 0.72e2*_t243*_t286 + _t280 - _t281 + _t284 + _t285) + _t258*_t63 - _t280 + _t281 - _t284 - _t285);
  const double d3F_dna_dgaa_dta = _t192 + na*(_t137*_t68 + _t165*_t58 + _t17*my_piecewise3(_t18, 36.738723026100004*_t147*_t20*_t66 + 15.506534051159999*_t147*_t22*_t66 - _t147*_t261 - _t148*_t186 - _t163*_t187 + 36.738723026100004*_t163*_t20*_t61 + 15.506534051159999*_t163*_t22*_t61 + 36.738723026100004*_t186*_t20*_t47 + 15.506534051159999*_t186*_t22*_t47 - _t188*_t288 + 73.477446052200008*_t19*_t47*_t61*_t66 - _t201*_t300 - _t202*_t300 + 12.2462410087*_t21*_t304 + 62.026136204639997*_t21*_t47*_t61*_t66 + 3.1013068102319998*_t23*_t304 - _t298*_t93 - _t298*_t94 - _t298*_t95 - _t299*_t93 - _t299*_t94 - _t299*_t95 - _t301*_t93 - _t301*_t94 - _t301*_t95 - _t304*_t48 - _t304*_t49 - _t304*_t50 - _t304*_t51 - 0.64000000000000001*_t304, _hc4[1]*my_piecewise3(_t16, _t303, 0) + _t150*_t279 + _t151*_t189 + _t164*_t190 + _t296*_t62*_t67) + _t191*_t37);
  const double d3F_dna_dta2 = _t199 + na*(_t17*my_piecewise3(_t18, -_t148*_t195 + 73.477446052200008*_t163*_t20*_t66 + 31.013068102319998*_t163*_t22*_t66 - _t163*_t307 + 73.477446052200008*_t19*_t193*_t47 + 62.026136204639997*_t193*_t21*_t47 - _t193*_t288 + 36.738723026100004*_t195*_t20*_t47 + 15.506534051159999*_t195*_t22*_t47 - _t201*_t305 - _t202*_t305 + 12.2462410087*_t21*_t315 + 3.1013068102319998*_t23*_t315 - _t237*_t308 - _t238*_t308 - _t239*_t308 - _t306*_t93 - _t306*_t94 - _t306*_t95 - _t315*_t48 - _t315*_t49 - _t315*_t50 - _t315*_t51 - 0.64000000000000001*_t315, _hc4[1]*my_piecewise3(_t16, _t314, 0) + _t151*_t197 + _t164*_t316 + _t196*_t296) + _t198*_t37);
  const double d3F_dgaa3 = na*(_t17*my_piecewise3(_t18, 110.21616907830001*_t174*_t20*_t61 + 46.519602153479994*_t174*_t22*_t61 + 73.477446052200008*_t19*_t326 - _t201*_t326 - _t202*_t326 - _t204*_t329 - _t205*_t329 - _t206*_t329 + 62.026136204639997*_t21*_t326 + 12.2462410087*_t21*_t328 + 3.1013068102319998*_t23*_t328 - 9.2141136272939992*_t326 - _t328*_t48 - _t328*_t49 - _t328*_t50 - _t328*_t51 - 0.64000000000000001*_t328 - 2.6111999999999997*_t329, _hc4[1]*my_piecewise3(_t16, _t327, 0) + _hc4[3]*(_t62 * _t62 * _t62) + 0.3e1*_t176*_t190) + 0.3e1*_t177*_t58 + 0.3e1*_t181*_t63 + _t25*(-0.1e1 / 0.32e2*_t131*_t325 + (0.1e1 / 0.192e3)*_t286*_t324 + _t318 + (0.1e1 / 0.16e2)*_t319*_t34 - _t321 - _t323) - _t318 + _t321 + _t323);
  const double d3F_dgaa2_dta = na*(_t17*my_piecewise3(_t18, 73.477446052200008*_t167*_t19*_t66 + 62.026136204639997*_t167*_t21*_t66 + 36.738723026100004*_t174*_t20*_t66 + 15.506534051159999*_t174*_t22*_t66 - _t174*_t261 + 73.477446052200008*_t186*_t20*_t61 + 31.013068102319998*_t186*_t22*_t61 - _t186*_t290 - _t201*_t330 - _t202*_t330 + 12.2462410087*_t21*_t333 + 3.1013068102319998*_t23*_t333 - _t237*_t331 - _t238*_t331 - _t239*_t331 - 9.2141136272939992*_t330 - _t333*_t48 - _t333*_t49 - _t333*_t50 - _t333*_t51 - 0.64000000000000001*_t333 - _t334*_t93 - _t334*_t94 - _t334*_t95, _hc4[1]*my_piecewise3(_t16, _t332, 0) + _hc4[3]*_t175*_t67 + _t176*_t279 + _t189*_t297) + _t181*_t68 + _t182*_t191);
  const double d3F_dgaa_dta2 = na*(_t17*my_piecewise3(_t18, 73.477446052200008*_t186*_t20*_t66 + 31.013068102319998*_t186*_t22*_t66 - _t186*_t307 - _t187*_t195 + 73.477446052200008*_t19*_t193*_t61 + 62.026136204639997*_t193*_t21*_t61 + 36.738723026100004*_t195*_t20*_t61 + 15.506534051159999*_t195*_t22*_t61 - _t201*_t335 - _t202*_t335 + 12.2462410087*_t21*_t337 + 3.1013068102319998*_t23*_t337 - _t237*_t338 - _t238*_t338 - _t239*_t338 - 9.2141136272939992*_t335 - _t337*_t48 - _t337*_t49 - _t337*_t50 - _t337*_t51 - 0.64000000000000001*_t337 - _t339*_t93 - _t339*_t94 - _t339*_t95, _hc4[1]*my_piecewise3(_t16, _t336, 0) + _hc4[3]*_t196*_t62 + _t189*_t316 + _t190*_t197) + _t198*_t58);
  const double d3F_dta3 = _t17*na*my_piecewise3(_t18, 73.477446052200008*_t19*_t340 + 110.21616907830001*_t195*_t20*_t66 + 46.519602153479994*_t195*_t22*_t66 - _t201*_t340 - _t202*_t340 - _t204*_t341 - _t205*_t341 - _t206*_t341 + 62.026136204639997*_t21*_t340 + 12.2462410087*_t21*_t343 + 3.1013068102319998*_t23*_t343 - 9.2141136272939992*_t340 - 2.6111999999999997*_t341 - _t343*_t48 - _t343*_t49 - _t343*_t50 - _t343*_t51 - 0.64000000000000001*_t343, _hc4[1]*my_piecewise3(_t16, _t342, 0) + _hc4[3]*(_t67 * _t67 * _t67) + 0.3e1*_t197*_t279);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gab = sigma[1];
  const double gbb = sigma[2];
  const double ta = tau[0];
  const double tb = tau[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(_t1, 1, 3);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = _t6/_t2;
  const double _t8 = na - nb;
  const double _t9 = (0.1e1 / _t1);
  const double _t10 = _t8*_t9;
  const double _t11 = xc_powr(_t1, -4, 3);
  const double _t12 = gaa + 0.2e1*gab + gbb;
  const double _t13 = xc_powr(_t12, 1, 2);
  const double _t14 = _t11*_t13;
  const double _t15 = xc_powr(0.3e1, 2, 3);
  const double _t16 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t17 = _t15*_t16;
  const double _t18 = (0.1e1 / 0.6e1)*_t17;
  const double _t19 = xc_powr(na, -5, 3);
  const double _t20 = _t19*ta;
  const double _t21 = xc_powr(nb, -5, 3);
  const double _t22 = _t21*tb;
  const double _t34 = (0.1e1 / (_t1 * _t1));
  const double _t35 = M_CBRT2;
  const double _t36 = 2.363*_t35 - 2.363;
  const double _t38 = (_t8 * _t8);
  const double _t39 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t40 = (_t8 * _t8 * _t8 * _t8);
  const double _t41 = xc_powi(_t1, -6);
  const double _t42 = xc_powi(_t8, 6);
  const double _t43 = xc_powi(_t1, -8);
  const double _t44 = xc_powi(_t8, 8);
  const double _t45 = xc_powi(_t1, -10);
  const double _t46 = xc_powi(_t8, 10);
  const double _t47 = _t34*_t38 + _t39*_t40 + _t41*_t42 + _t43*_t44 + _t45*_t46 + 0.1e1;
  double _hc0[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_pbe_k, _KMAX)(p, _t7, _t10, _t14, 0, 0, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, _t10, _hc1);
  double _hc2[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_H0_k, _KMAX)(p, _t7, _t14*_t18, _hc2);
  double _hc3[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_eclda0_k, _KMAX)(p, _t7, _hc3);
  double _hc4[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(rscan_alpha_k, _KMAX)(p, _t7, _t9*na - _t9*nb, _t13/(_t2*na + _t2*nb), _t20, _t22, _hc4);
  double _hc5[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(rscan_alpha_k, _KMAX)(p, _t7, _t10, _t14, _t20, _t22, _hc5);
  const double _t23 = 1.0*_hc4[0] - 2.5;
  const double _t24 = _t23 > 0;
  const double _t25 = _t23 <= 0;
  const double _t26 = my_piecewise3(_t24, 2.5, _hc5[0]);
  const double _t27 = (_t26 * _t26);
  const double _t28 = (_t26 * _t26 * _t26);
  const double _t29 = (_t26 * _t26 * _t26 * _t26);
  const double _t30 = xc_powi(_t26, 5);
  const double _t31 = xc_powi(_t26, 6);
  const double _t33 = _hc2[0] + _hc3[0];
  const double _t37 = -_hc1[0]*_t36 + 0.1e1;
  const double _t48 = -_hc0[0] + 0.4e1*_t33*_t34*_t37*_t47*na*nb;
  double _hc6[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(rscan_f_alpha_large_k, _KMAX)(p, my_piecewise3(_t24, _hc5[0], 2.5), _hc6);
  const double _t32 = my_piecewise3(_t25, -0.051848879792000001*xc_powi(_t26, 7) - 0.64000000000000001*_t26 - 0.43519999999999998*_t27 - 1.5356856045489999*_t28 + 3.0615602521750001*_t29 - 1.9157102362059999*_t30 + 0.51688446837199997*_t31 + 0.1e1, _hc6[0]);
  const double _t49 = _hc0[0] + _t32*_t48;
  const double zk = _t49;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t50 = xc_powr(_t1, -7, 3);
  const double _t51 = (0.4e1 / 0.3e1)*_t50;
  const double _t52 = _t13*_t51;
  const double _t54 = (0.1e1 / 0.6e1)*_t11;
  const double _t55 = _t5*_t54;
  const double _t58 = -_t9;
  const double _t59 = _t34*_t8;
  const double _t60 = -_t58 - _t59;
  const double _t62 = xc_powr(na, -8, 3);
  const double _t63 = (0.5e1 / 0.3e1)*_t62;
  const double _t78 = 0.4e1*_t34;
  const double _t79 = _t47*_t78;
  const double _t81 = 0.2e1*nb;
  const double _t82 = -_t81 + 0.2e1*na;
  const double _t83 = xc_powi(_t8, 9);
  const double _t84 = 0.10e2*_t45*_t83;
  const double _t85 = xc_powi(_t8, 7);
  const double _t86 = 0.8e1*_t43*_t85;
  const double _t87 = xc_powi(_t8, 5);
  const double _t88 = 0.6e1*_t41*_t87;
  const double _t89 = (_t8 * _t8 * _t8);
  const double _t90 = 0.4e1*_t39*_t89;
  const double _t91 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t92 = 0.2e1*_t91;
  const double _t93 = xc_powi(_t1, -5);
  const double _t94 = xc_powi(_t1, -7);
  const double _t95 = xc_powi(_t1, -9);
  const double _t96 = xc_powi(_t1, -11);
  const double _t97 = _t38*_t92 + 0.4e1*_t40*_t93 + 0.6e1*_t42*_t94 + 0.8e1*_t44*_t95 + 0.10e2*_t46*_t96;
  const double _t98 = _t34*_t82 + _t84 + _t86 + _t88 + _t90 - _t97;
  const double _t99 = _t78*na;
  const double _t100 = na*nb;
  const double _t101 = _t100*_t79;
  const double _t107 = 0.8e1*_t47;
  const double _t110 = _t13*_t50;
  const double _t111 = (0.2e1 / 0.9e1)*_t110;
  const double _t118 = -_t59 - _t9;
  const double _t120 = xc_powr(nb, -8, 3);
  const double _t121 = (0.5e1 / 0.3e1)*_t120;
  const double _t128 = -_t82;
  const double _t129 = _t128*_t34 - _t84 - _t86 - _t88 - _t90 - _t97;
  const double _t130 = _t99*nb;
  const double _t135 = (0.1e1 / _t13);
  const double _t136 = _t11*_t135;
  const double _t139 = xc_powr(_t1, -10, 3);
  const double _t53 = _hc0[3]*_t52;
  const double _t56 = _hc0[5]*_t55;
  const double _t57 = -_t53 - _t56;
  const double _t61 = _hc0[4]*_t60;
  const double _t64 = _hc5[2]*_t63;
  const double _t65 = _hc5[3]*_t13;
  const double _t66 = _hc5[5]*_t5;
  const double _t67 = _t51*_t65 + _t54*_t66;
  const double _t68 = _hc5[4]*_t60 - _t64*ta - _t67;
  const double _t69 = my_piecewise3(_t24, 0, _t68);
  const double _t70 = 0.87039999999999995*_t26;
  const double _t71 = 4.6070568136469996*_t27;
  const double _t72 = 9.578551181029999*_t29;
  const double _t73 = 0.36294215854400003*_t31;
  const double _t74 = my_piecewise3(_t24, _t68, 0);
  const double _t77 = _t33*_t37;
  const double _t80 = _t77*_t79;
  const double _t102 = _t33*_t36;
  const double _t103 = _hc1[1]*_t102;
  const double _t104 = _t103*_t60;
  const double _t105 = _t77*_t91;
  const double _t106 = _t105*na;
  const double _t108 = _t106*_t107;
  const double _t109 = _hc2[1]*_t17;
  const double _t112 = -_hc2[2]*_t55 - _hc3[1]*_t55 - _t109*_t111;
  const double _t113 = _t112*_t37;
  const double _t114 = -_t108*nb + _t113*_t79*na*nb + _t53 + _t56;
  const double _t115 = -_t101*_t104 + _t114 - _t61 + _t77*_t98*_t99*nb + _t80*nb;
  const double _t119 = _hc0[4]*_t118;
  const double _t122 = _hc5[1]*_t121;
  const double _t123 = _hc5[4]*_t118 - _t122*tb - _t67;
  const double _t124 = my_piecewise3(_t24, 0, _t123);
  const double _t125 = my_piecewise3(_t24, _t123, 0);
  const double _t131 = _t103*_t118;
  const double _t132 = -_t101*_t131 + _t114 - _t119 + _t129*_t130*_t77 + _t80*na;
  const double _t137 = _hc0[3]*_t136;
  const double _t138 = (0.1e1 / 0.2e1)*_t137;
  const double _t140 = (0.1e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t37*_t47*na*nb - _t138;
  const double _t141 = _hc5[3]*_t136;
  const double _t142 = (0.1e1 / 0.2e1)*_t141;
  const double _t143 = my_piecewise3(_t24, 0, _t142);
  const double _t144 = my_piecewise3(_t24, _t142, 0);
  const double _t148 = (0.2e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t37*_t47*na*nb - _t137;
  const double _t149 = my_piecewise3(_t24, 0, _t141);
  const double _t150 = my_piecewise3(_t24, _t141, 0);
  const double _t153 = _hc5[2]*_t19;
  const double _t154 = my_piecewise3(_t24, 0, _t153);
  const double _t155 = my_piecewise3(_t24, _t153, 0);
  const double _t158 = _hc5[1]*_t21;
  const double _t159 = my_piecewise3(_t24, 0, _t158);
  const double _t160 = my_piecewise3(_t24, _t158, 0);
  const double _t75 = my_piecewise3(_t25, 12.2462410087*_t28*_t69 + 3.1013068102319998*_t30*_t69 - _t69*_t70 - _t69*_t71 - _t69*_t72 - _t69*_t73 - 0.64000000000000001*_t69, _hc6[1]*_t74);
  const double _t76 = _t48*_t75;
  const double _t116 = _t115*_t32;
  const double _t117 = _t116 + _t61 + _t76;
  const double _t126 = my_piecewise3(_t25, 12.2462410087*_t124*_t28 + 3.1013068102319998*_t124*_t30 - _t124*_t70 - _t124*_t71 - _t124*_t72 - _t124*_t73 - 0.64000000000000001*_t124, _hc6[1]*_t125);
  const double _t127 = _t126*_t48;
  const double _t133 = _t132*_t32;
  const double _t134 = _t119 + _t127 + _t133;
  const double _t145 = my_piecewise3(_t25, 12.2462410087*_t143*_t28 + 3.1013068102319998*_t143*_t30 - _t143*_t70 - _t143*_t71 - _t143*_t72 - _t143*_t73 - 0.64000000000000001*_t143, _hc6[1]*_t144);
  const double _t146 = _t138 + _t140*_t32 + _t145*_t48;
  const double _t147 = _t1*_t146;
  const double _t151 = my_piecewise3(_t25, 12.2462410087*_t149*_t28 + 3.1013068102319998*_t149*_t30 - _t149*_t70 - _t149*_t71 - _t149*_t72 - _t149*_t73 - 0.64000000000000001*_t149, _hc6[1]*_t150);
  const double _t152 = _t137 + _t148*_t32 + _t151*_t48;
  const double _t156 = my_piecewise3(_t25, 12.2462410087*_t154*_t28 + 3.1013068102319998*_t154*_t30 - _t154*_t70 - _t154*_t71 - _t154*_t72 - _t154*_t73 - 0.64000000000000001*_t154, _hc6[1]*_t155);
  const double _t157 = _t156*_t48;
  const double _t161 = my_piecewise3(_t25, 12.2462410087*_t159*_t28 + 3.1013068102319998*_t159*_t30 - _t159*_t70 - _t159*_t71 - _t159*_t72 - _t159*_t73 - 0.64000000000000001*_t159, _hc6[1]*_t160);
  const double _t162 = _t161*_t48;
  const double dF_dna = _t1*(_t117 + _t57) + _t49;
  const double dF_dnb = _t1*(_t134 + _t57) + _t49;
  const double dF_dgaa = _t147;
  const double dF_dgab = _t1*_t152;
  const double dF_dgbb = _t147;
  const double dF_dta = _t1*_t157;
  const double dF_dtb = _t1*_t162;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double _t163 = 0.2e1*_t34;
  const double _t164 = _t8*_t92;
  const double _t165 = -_t163 + _t164;
  const double _t176 = (0.28e2 / 0.9e1)*_t139;
  const double _t178 = (0.2e1 / 0.9e1)*_t50;
  const double _t179 = _t178*_t5;
  const double _t199 = xc_powr(na, -11, 3);
  const double _t200 = (0.40e2 / 0.9e1)*_t199;
  const double _t212 = 0.16e2*_t47;
  const double _t214 = 0.200e3*_t83*_t96;
  const double _t215 = 0.128e3*_t85*_t95;
  const double _t216 = 0.72e2*_t87*_t94;
  const double _t217 = 0.32e2*_t89*_t93;
  const double _t218 = 0.4e1*_t91;
  const double _t219 = _t38*_t39;
  const double _t220 = _t40*_t41;
  const double _t221 = _t42*_t43;
  const double _t222 = xc_powi(_t1, -12);
  const double _t223 = _t44*_t45;
  const double _t224 = _t163 + 0.18e2*_t219 + 0.50e2*_t220 + 0.98e2*_t221 + 0.110e3*_t222*_t46 + 0.162e3*_t223;
  const double _t225 = -_t214 - _t215 - _t216 - _t217 - _t218*_t82 + _t224;
  const double _t228 = 0.8e1*_t34;
  const double _t229 = _t228*_t47;
  const double _t230 = _t229*nb;
  const double _t232 = (_t60 * _t60);
  const double _t235 = _t228*nb;
  const double _t236 = _t235*na;
  const double _t237 = _t236*_t98;
  const double _t242 = xc_powr(_t1, -8, 3);
  const double _t244 = _t13*_t139;
  const double _t245 = (0.14e2 / 0.27e2)*_t244;
  const double _t246 = _t111*_t17;
  const double _t258 = (0.8e1 / 0.3e1)*_t50;
  const double _t260 = (0.1e1 / 0.3e1)*_t11;
  const double _t285 = -_t128*_t92 - _t163 - 0.6e1*_t219 - 0.10e2*_t220 - 0.14e2*_t221 + 0.110e3*_t222*_t46 - 0.18e2*_t223 - _t82*_t92;
  const double _t287 = 0.8e1*nb;
  const double _t289 = _t79*na;
  const double _t290 = _t79*nb;
  const double _t305 = _t163 + _t164;
  const double _t313 = xc_powr(nb, -11, 3);
  const double _t314 = (0.40e2 / 0.9e1)*_t313;
  const double _t323 = -_t128*_t218 + _t214 + _t215 + _t216 + _t217 + _t224;
  const double _t325 = _t229*na;
  const double _t327 = (_t118 * _t118);
  const double _t329 = _t129*_t236;
  const double _t335 = xc_powr(_t1, -11, 3);
  const double _t336 = (0.2e1 / 0.3e1)*_t335;
  const double _t338 = (0.2e1 / 0.3e1)*_t50;
  const double _t341 = _t135*_t242;
  const double _t342 = (0.1e1 / 0.12e2)*_t5;
  const double _t343 = _t341*_t342;
  const double _t347 = (0.5e1 / 0.6e1)*_t136;
  const double _t362 = _t47*nb;
  const double _t367 = _t100*_t98;
  const double _t369 = _t362*na;
  const double _t374 = (0.1e1 / 0.18e2)*_t335;
  const double _t375 = M_CBRT3;
  const double _t376 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t378 = (0.1e1 / M_PI);
  const double _t381 = (0.1e1 / 0.9e1)*_t50;
  const double _t384 = xc_powr(_t1, -13, 3);
  const double _t385 = _t135*_t384;
  const double _t394 = (0.4e1 / 0.3e1)*_t335;
  const double _t397 = (0.1e1 / 0.6e1)*_t341;
  const double _t413 = (0.1e1 / 0.9e1)*_t335;
  const double _t423 = _t120*_t347;
  const double _t436 = _t47*na;
  const double _t438 = _t100*_t129;
  const double _t459 = xc_powr(na, -13, 3);
  const double _t461 = (0.5e1 / 0.3e1)*ta;
  const double _t472 = _t63*ta;
  const double _t490 = xc_powr(nb, -13, 3);
  const double _t492 = (0.5e1 / 0.3e1)*tb;
  const double _t501 = (0.1e1 / _t12);
  const double _t502 = _t242*_t501;
  const double _t504 = xc_powr(_t12, -3, 2);
  const double _t505 = _t11*_t504;
  const double _t512 = xc_powr(_t1, -14, 3);
  const double _t575 = xc_powr(na, -10, 3);
  const double _t591 = xc_powr(nb, -10, 3);
  const double _t166 = _hc0[4]*_t165;
  const double _t167 = _hc0[14]*_t52 + _hc0[19]*_t55;
  const double _t168 = _hc0[15]*_t60 - _t167;
  const double _t169 = _t168*_t60;
  const double _t170 = _hc0[11]*_t52 + _hc0[18]*_t55;
  const double _t171 = _hc0[14]*_t60 - _t170;
  const double _t172 = -_t171*_t52;
  const double _t173 = _hc0[18]*_t52 + _hc0[20]*_t55;
  const double _t174 = _hc0[19]*_t60 - _t173;
  const double _t175 = -_t174*_t55;
  const double _t177 = _hc0[3]*_t13;
  const double _t180 = _hc0[5]*_t179 + _t176*_t177;
  const double _t181 = _t166 + _t169 + _t172 + _t175 + _t180;
  const double _t182 = (_t69 * _t69);
  const double _t183 = 9.2141136272939992*_t26;
  const double _t184 = 38.314204724119996*_t28;
  const double _t185 = 2.1776529512640002*_t30;
  const double _t186 = _hc5[13]*_t63;
  const double _t187 = _hc5[14]*_t52 + _hc5[19]*_t55;
  const double _t188 = _hc5[15]*_t60 - _t186*ta - _t187;
  const double _t189 = _hc5[8]*_t63;
  const double _t190 = _hc5[10]*_t52;
  const double _t191 = _hc5[17]*_t55;
  const double _t192 = _t190 + _t191;
  const double _t193 = _hc5[13]*_t60 - _t189*ta - _t192;
  const double _t194 = _t193*_t63;
  const double _t195 = _hc5[10]*_t63;
  const double _t196 = _t195*ta;
  const double _t197 = _hc5[11]*_t52 + _hc5[18]*_t55;
  const double _t198 = _hc5[14]*_t60 - _t196 - _t197;
  const double _t201 = _hc5[2]*_t200;
  const double _t202 = _hc5[17]*_t63;
  const double _t203 = _hc5[18]*_t52 + _hc5[20]*_t55;
  const double _t204 = _hc5[19]*_t60 - _t202*ta - _t203;
  const double _t205 = _t176*_t65 + _t178*_t66;
  const double _t206 = _hc5[4]*_t165 + _t188*_t60 - _t194*ta - _t198*_t52 + _t201*ta - _t204*_t55 + _t205;
  const double _t207 = my_piecewise3(_t24, 0, _t206);
  const double _t208 = (_t74 * _t74);
  const double _t209 = my_piecewise3(_t24, _t206, 0);
  const double _t213 = _t105*_t212;
  const double _t226 = 0.16e2*_t106;
  const double _t227 = _t226*_t98;
  const double _t231 = _t103*_t165;
  const double _t233 = _hc1[2]*_t102;
  const double _t234 = _t232*_t233;
  const double _t238 = _t112*_t36;
  const double _t239 = _hc1[1]*_t238;
  const double _t240 = _t239*_t60;
  const double _t241 = _t230*_t240;
  const double _t243 = xc_powr(0.6e1, 2, 3)*_hc3[2]*_t16;
  const double _t247 = -_hc2[4]*_t246 - _hc2[5]*_t55;
  const double _t248 = -_hc2[3]*_t246 - _hc2[4]*_t55;
  const double _t249 = _hc2[2]*_t179 + _hc3[1]*_t179 + _t109*_t245 + (0.1e1 / 0.36e2)*_t242*_t243 - _t246*_t248 - _t247*_t55;
  const double _t250 = _t113*_t91;
  const double _t251 = _t212*_t250;
  const double _t252 = _t251*na;
  const double _t253 = -0.4e1*_t249*_t34*_t37*_t47*na*nb + _t252*nb - 0.24e2*_t33*_t37*_t39*_t47*na*nb;
  const double _t254 = 0.16e2*_hc1[1]*_t33*_t36*_t47*_t60*_t91*na*nb - _t101*_t231 - _t101*_t234 - _t104*_t230 - _t104*_t237 + 0.8e1*_t112*_t34*_t37*_t47*nb + 0.8e1*_t112*_t34*_t37*_t98*na*nb - _t181 - _t213*nb + 0.4e1*_t225*_t33*_t34*_t37*na*nb - _t227*nb - _t241*na - _t253 + 0.8e1*_t33*_t34*_t37*_t98*nb;
  const double _t259 = _hc0[5]*_t5;
  const double _t261 = -_t177*_t258 - _t259*_t260;
  const double _t262 = 0.87039999999999995*_t69;
  const double _t263 = _t124*_t69;
  const double _t264 = _hc5[12]*_t121;
  const double _t265 = _hc5[15]*_t118 - _t187 - _t264*tb;
  const double _t266 = _hc5[7]*_t121;
  const double _t267 = _t266*tb;
  const double _t268 = _hc5[13]*_t118 - _t192 - _t267;
  const double _t269 = _t268*_t63;
  const double _t270 = _hc5[9]*_t121;
  const double _t271 = _t270*tb;
  const double _t272 = _hc5[14]*_t118 - _t197 - _t271;
  const double _t273 = _hc5[16]*_t121;
  const double _t274 = _hc5[19]*_t118 - _t203 - _t273*tb;
  const double _t275 = _t205 - _t272*_t52 - _t274*_t55;
  const double _t276 = _hc5[4]*_t164 + _t265*_t60 - _t269*ta + _t275;
  const double _t277 = my_piecewise3(_t24, 0, _t276);
  const double _t279 = my_piecewise3(_t24, _t276, 0);
  const double _t284 = _t105*nb;
  const double _t286 = _t106*_t129;
  const double _t288 = _t106*_t287;
  const double _t291 = _t104*_t129;
  const double _t292 = _t131*_t98;
  const double _t293 = _t118*_t239;
  const double _t294 = _t103*_t8*_t93;
  const double _t295 = _t233*_t60;
  const double _t296 = _t118*_t295;
  const double _t297 = _hc0[15]*_t118 - _t167;
  const double _t298 = _t297*_t60;
  const double _t299 = _hc0[14]*_t118 - _t170;
  const double _t300 = _hc0[19]*_t118 - _t173;
  const double _t301 = _t180 - _t299*_t52 - _t300*_t55;
  const double _t302 = _hc0[4]*_t164 + _t298 + _t301;
  const double _t303 = 0.8e1*_hc1[1]*_t118*_t33*_t36*_t47*_t91*na*nb + 0.8e1*_hc1[1]*_t33*_t36*_t47*_t60*_t91*na*nb - _t100*_t107*_t294 - _t101*_t240 - _t101*_t293 - _t101*_t296 - _t104*_t289 - _t107*_t284 - _t108 + 0.4e1*_t112*_t129*_t34*_t37*na*nb + 0.4e1*_t112*_t34*_t37*_t47*na + 0.4e1*_t112*_t34*_t37*_t47*nb + 0.4e1*_t112*_t34*_t37*_t98*na*nb + 0.4e1*_t129*_t33*_t34*_t37*nb - _t130*_t291 - _t130*_t292 - _t131*_t290 - _t253 + 0.4e1*_t285*_t33*_t34*_t37*na*nb - _t286*_t287 - _t288*_t98 - _t302 + 0.4e1*_t33*_t34*_t37*_t47 + 0.4e1*_t33*_t34*_t37*_t98*na;
  const double _t306 = _hc0[4]*_t305;
  const double _t307 = (_t124 * _t124);
  const double _t308 = _hc5[6]*_t121;
  const double _t309 = _hc5[16]*_t55;
  const double _t310 = _hc5[9]*_t52;
  const double _t311 = _hc5[12]*_t118 - _t308*tb - _t309 - _t310;
  const double _t312 = _t121*_t311;
  const double _t315 = _hc5[1]*_t314;
  const double _t316 = _hc5[4]*_t305 + _t118*_t265 + _t275 - _t312*tb + _t315*tb;
  const double _t317 = my_piecewise3(_t24, 0, _t316);
  const double _t318 = (_t125 * _t125);
  const double _t319 = my_piecewise3(_t24, _t316, 0);
  const double _t322 = _t118*_t297;
  const double _t324 = _t129*_t226;
  const double _t326 = _t103*_t305;
  const double _t328 = _t233*_t327;
  const double _t330 = _t230*_t293;
  const double _t331 = 0.16e2*_hc1[1]*_t118*_t33*_t36*_t47*_t91*na*nb - _t101*_t326 - _t101*_t328 + 0.8e1*_t112*_t129*_t34*_t37*na*nb + 0.8e1*_t112*_t34*_t37*_t47*na + 0.8e1*_t129*_t33*_t34*_t37*na - _t131*_t325 - _t131*_t329 - _t213*na - _t253 - _t301 - _t306 - _t322 + 0.4e1*_t323*_t33*_t34*_t37*na*nb - _t324*nb - _t330*na;
  const double _t333 = 0.2e1*_t132;
  const double _t337 = _hc0[11]*_t336;
  const double _t339 = _hc0[3]*_t135;
  const double _t340 = _t338*_t339;
  const double _t344 = _hc0[18]*_t343;
  const double _t345 = -_t337 - _t340 - _t344;
  const double _t346 = _t143*_t69;
  const double _t348 = _hc5[10]*_t347*_t62;
  const double _t349 = _hc5[11]*_t336;
  const double _t350 = _hc5[3]*_t135;
  const double _t351 = _hc5[18]*_t343 + _t338*_t350 + _t349;
  const double _t352 = (0.1e1 / 0.2e1)*_hc5[14]*_t11*_t135*_t60 - _t348*ta - _t351;
  const double _t353 = my_piecewise3(_t24, 0, _t352);
  const double _t354 = my_piecewise3(_t24, _t352, 0);
  const double _t359 = _hc0[14]*_t60;
  const double _t360 = _t136*_t359;
  const double _t361 = (0.1e1 / 0.2e1)*_t360;
  const double _t363 = _t109*_t135;
  const double _t364 = _t139*_t363;
  const double _t365 = _t364*_t37;
  const double _t366 = _t362*_t365;
  const double _t368 = _t365*_t367;
  const double _t370 = _hc1[1]*_t36;
  const double _t371 = _t364*_t370;
  const double _t372 = _t371*_t60;
  const double _t373 = _t369*_t372;
  const double _t377 = _hc2[3]*_t375*_t376;
  const double _t379 = _hc2[4]*_t35*_t378;
  const double _t380 = _t341*_t379;
  const double _t382 = -_t363*_t381 - _t374*_t377 - 0.1e1 / 0.24e2*_t380;
  const double _t383 = _t37*_t382;
  const double _t386 = _t109*_t385;
  const double _t387 = (0.2e1 / 0.3e1)*_t386;
  const double _t388 = _t369*_t37;
  const double _t389 = _t337 + _t340 + _t344 + _t383*_t79*na*nb - _t387*_t388;
  const double _t390 = -_t361 + (0.1e1 / 0.3e1)*_t366 + (0.1e1 / 0.3e1)*_t368 - 0.1e1 / 0.3e1*_t373 + _t389;
  const double _t395 = _hc0[11]*_t394;
  const double _t396 = _t339*_t51;
  const double _t398 = _hc0[18]*_t5;
  const double _t399 = _t397*_t398;
  const double _t400 = -_t395 - _t396 - _t399;
  const double _t401 = _t360 + _t400;
  const double _t402 = _t149*_t69;
  const double _t403 = _hc5[11]*_t394;
  const double _t404 = _hc5[18]*_t5;
  const double _t405 = _t350*_t51 + _t397*_t404 + _t403;
  const double _t406 = _hc5[14]*_t11*_t135*_t60 - _t136*_t196 - _t405;
  const double _t407 = my_piecewise3(_t24, 0, _t406);
  const double _t408 = my_piecewise3(_t24, _t406, 0);
  const double _t414 = -_t178*_t363 - _t377*_t413 - 0.1e1 / 0.12e2*_t380;
  const double _t415 = _t37*_t414;
  const double _t416 = (0.4e1 / 0.3e1)*_t386;
  const double _t417 = -_t388*_t416 + _t395 + _t396 + _t399 + _t415*_t79*na*nb;
  const double _t418 = -_t360 + (0.2e1 / 0.3e1)*_t366 + (0.2e1 / 0.3e1)*_t368 - 0.2e1 / 0.3e1*_t373 + _t417;
  const double _t421 = 0.87039999999999995*_t124;
  const double _t422 = _t124*_t143;
  const double _t424 = _hc5[9]*_t423;
  const double _t425 = (0.1e1 / 0.2e1)*_hc5[14]*_t11*_t118*_t135 - _t351 - _t424*tb;
  const double _t426 = my_piecewise3(_t24, 0, _t425);
  const double _t428 = my_piecewise3(_t24, _t425, 0);
  const double _t433 = _hc0[14]*_t118;
  const double _t434 = _t136*_t433;
  const double _t435 = (0.1e1 / 0.2e1)*_t434;
  const double _t437 = _t365*_t436;
  const double _t439 = _t365*_t438;
  const double _t440 = _t118*_t371;
  const double _t441 = _t369*_t440;
  const double _t442 = _t389 - _t435 + (0.1e1 / 0.3e1)*_t437 + (0.1e1 / 0.3e1)*_t439 - 0.1e1 / 0.3e1*_t441;
  const double _t446 = _t400 + _t434;
  const double _t447 = _t124*_t149;
  const double _t448 = _hc5[14]*_t11*_t118*_t135 - _t136*_t271 - _t405;
  const double _t449 = my_piecewise3(_t24, 0, _t448);
  const double _t450 = my_piecewise3(_t24, _t448, 0);
  const double _t455 = _t417 - _t434 + (0.2e1 / 0.3e1)*_t437 + (0.2e1 / 0.3e1)*_t439 - 0.2e1 / 0.3e1*_t441;
  const double _t460 = _hc5[8]*_t459;
  const double _t462 = _t19*_t190 + _t19*_t191;
  const double _t463 = _hc5[13]*_t19*_t60 - _t460*_t461 - _t462 - _t64;
  const double _t464 = my_piecewise3(_t24, 0, _t463);
  const double _t465 = _t154*_t69;
  const double _t466 = my_piecewise3(_t24, _t463, 0);
  const double _t471 = _hc5[7]*_t21;
  const double _t473 = _t21*_t309 + _t21*_t310;
  const double _t474 = _hc5[12]*_t21*_t60 - _t471*_t472 - _t473;
  const double _t475 = my_piecewise3(_t24, 0, _t474);
  const double _t476 = _t159*_t69;
  const double _t477 = my_piecewise3(_t24, _t474, 0);
  const double _t482 = _hc5[13]*_t118*_t19 - _t19*_t267 - _t462;
  const double _t483 = my_piecewise3(_t24, 0, _t482);
  const double _t484 = _t124*_t154;
  const double _t485 = my_piecewise3(_t24, _t482, 0);
  const double _t491 = _hc5[6]*_t490;
  const double _t493 = _hc5[12]*_t118*_t21 - _t122 - _t473 - _t491*_t492;
  const double _t494 = my_piecewise3(_t24, 0, _t493);
  const double _t495 = _t124*_t159;
  const double _t496 = my_piecewise3(_t24, _t493, 0);
  const double _t500 = (_t143 * _t143);
  const double _t503 = _hc5[11]*_t502;
  const double _t506 = _hc5[3]*_t505;
  const double _t507 = (0.1e1 / 0.4e1)*_t503 - 0.1e1 / 0.4e1*_t506;
  const double _t508 = my_piecewise3(_t24, 0, _t507);
  const double _t509 = (_t144 * _t144);
  const double _t510 = my_piecewise3(_t24, _t507, 0);
  const double _t513 = _hc2[1]*_t18*_t504;
  const double _t514 = _t139*_t388;
  const double _t515 = _hc0[3]*_t505;
  const double _t516 = _hc0[11]*_t502;
  const double _t517 = -0.1e1 / 0.4e1*_t515 + (0.1e1 / 0.4e1)*_t516;
  const double _t518 = (0.1e1 / 0.12e2)*_hc2[3]*_t37*_t375*_t376*_t47*_t501*_t512*na*nb - _t513*_t514 - _t517;
  const double _t519 = 0.2e1*_t140;
  const double _t522 = (0.1e1 / 0.2e1)*_t503 - 0.1e1 / 0.2e1*_t506;
  const double _t523 = my_piecewise3(_t24, 0, _t522);
  const double _t524 = 0.87039999999999995*_t143;
  const double _t525 = _t143*_t149;
  const double _t526 = my_piecewise3(_t24, _t522, 0);
  const double _t529 = _t109*_t504;
  const double _t530 = _t514*_t529;
  const double _t531 = -0.1e1 / 0.2e1*_t515 + (0.1e1 / 0.2e1)*_t516;
  const double _t532 = (0.1e1 / 0.6e1)*_hc2[3]*_t37*_t375*_t376*_t47*_t501*_t512*na*nb - 0.1e1 / 0.3e1*_t530 - _t531;
  const double _t535 = (_t149 * _t149);
  const double _t536 = _t503 - _t506;
  const double _t537 = my_piecewise3(_t24, 0, _t536);
  const double _t538 = (_t150 * _t150);
  const double _t539 = my_piecewise3(_t24, _t536, 0);
  const double _t541 = -_t515 + _t516;
  const double _t542 = (0.1e1 / 0.3e1)*_hc2[3]*_t37*_t375*_t376*_t47*_t501*_t512*na*nb - 0.2e1 / 0.3e1*_t530 - _t541;
  const double _t543 = 0.2e1*_t148;
  const double _t545 = _hc5[10]*_t19;
  const double _t546 = _t136*_t545;
  const double _t547 = (0.1e1 / 0.2e1)*_t546;
  const double _t548 = my_piecewise3(_t24, 0, _t547);
  const double _t549 = _t143*_t154;
  const double _t550 = my_piecewise3(_t24, _t547, 0);
  const double _t554 = _hc5[9]*_t21;
  const double _t555 = _t136*_t554;
  const double _t556 = (0.1e1 / 0.2e1)*_t555;
  const double _t557 = my_piecewise3(_t24, 0, _t556);
  const double _t558 = _t143*_t159;
  const double _t559 = my_piecewise3(_t24, _t556, 0);
  const double _t563 = my_piecewise3(_t24, 0, _t546);
  const double _t564 = 0.87039999999999995*_t149;
  const double _t565 = _t149*_t154;
  const double _t566 = my_piecewise3(_t24, _t546, 0);
  const double _t570 = my_piecewise3(_t24, 0, _t555);
  const double _t571 = _t149*_t159;
  const double _t572 = my_piecewise3(_t24, _t555, 0);
  const double _t576 = _hc5[8]*_t575;
  const double _t577 = my_piecewise3(_t24, 0, _t576);
  const double _t578 = (_t154 * _t154);
  const double _t579 = my_piecewise3(_t24, _t576, 0);
  const double _t580 = (_t155 * _t155);
  const double _t583 = _t19*_t471;
  const double _t584 = my_piecewise3(_t24, 0, _t583);
  const double _t585 = 0.87039999999999995*_t154;
  const double _t586 = _t154*_t159;
  const double _t587 = my_piecewise3(_t24, _t583, 0);
  const double _t592 = _hc5[6]*_t591;
  const double _t593 = my_piecewise3(_t24, 0, _t592);
  const double _t594 = (_t159 * _t159);
  const double _t595 = my_piecewise3(_t24, _t592, 0);
  const double _t596 = (_t160 * _t160);
  const double _t210 = my_piecewise3(_t25, -_t182*_t183 - _t182*_t184 - _t182*_t185 + 36.738723026100004*_t182*_t27 + 15.506534051159999*_t182*_t29 - 0.87039999999999995*_t182 + 12.2462410087*_t207*_t28 + 3.1013068102319998*_t207*_t30 - _t207*_t70 - _t207*_t71 - _t207*_t72 - _t207*_t73 - 0.64000000000000001*_t207, _hc6[1]*_t209 + _hc6[2]*_t208);
  const double _t211 = _t210*_t48;
  const double _t255 = _t254*_t32;
  const double _t256 = _t115*_t75;
  const double _t257 = _t211 + _t255 + 0.2e1*_t256;
  const double _t278 = _hc6[2]*_t74;
  const double _t280 = my_piecewise3(_t25, -_t124*_t262 + 36.738723026100004*_t124*_t27*_t69 + 15.506534051159999*_t124*_t29*_t69 - _t183*_t263 - _t184*_t263 - _t185*_t263 + 12.2462410087*_t277*_t28 + 3.1013068102319998*_t277*_t30 - _t277*_t70 - _t277*_t71 - _t277*_t72 - _t277*_t73 - 0.64000000000000001*_t277, _hc6[1]*_t279 + _t125*_t278);
  const double _t281 = _t280*_t48;
  const double _t282 = _t115*_t126;
  const double _t283 = _t132*_t75;
  const double _t304 = _t303*_t32;
  const double _t320 = my_piecewise3(_t25, -_t183*_t307 - _t184*_t307 - _t185*_t307 + 36.738723026100004*_t27*_t307 + 12.2462410087*_t28*_t317 + 15.506534051159999*_t29*_t307 + 3.1013068102319998*_t30*_t317 - 0.87039999999999995*_t307 - _t317*_t70 - _t317*_t71 - _t317*_t72 - _t317*_t73 - 0.64000000000000001*_t317, _hc6[1]*_t319 + _hc6[2]*_t318);
  const double _t321 = _t320*_t48;
  const double _t332 = _t32*_t331;
  const double _t334 = _t126*_t333 + _t306 + _t321 + _t322 + _t332;
  const double _t355 = my_piecewise3(_t25, -_t143*_t262 + 36.738723026100004*_t143*_t27*_t69 + 15.506534051159999*_t143*_t29*_t69 - _t183*_t346 - _t184*_t346 - _t185*_t346 + 12.2462410087*_t28*_t353 + 3.1013068102319998*_t30*_t353 - _t353*_t70 - _t353*_t71 - _t353*_t72 - _t353*_t73 - 0.64000000000000001*_t353, _hc6[1]*_t354 + _t144*_t278);
  const double _t356 = _t355*_t48;
  const double _t357 = _t140*_t75;
  const double _t358 = _t115*_t145;
  const double _t391 = _t32*_t390;
  const double _t392 = _t356 + _t357 + _t358 + _t361 + _t391;
  const double _t393 = _t1*(_t345 + _t392) + _t146;
  const double _t409 = my_piecewise3(_t25, -_t149*_t262 + 36.738723026100004*_t149*_t27*_t69 + 15.506534051159999*_t149*_t29*_t69 - _t183*_t402 - _t184*_t402 - _t185*_t402 + 12.2462410087*_t28*_t407 + 3.1013068102319998*_t30*_t407 - _t407*_t70 - _t407*_t71 - _t407*_t72 - _t407*_t73 - 0.64000000000000001*_t407, _hc6[1]*_t408 + _t150*_t278);
  const double _t410 = _t409*_t48;
  const double _t411 = _t148*_t75;
  const double _t412 = _t115*_t151;
  const double _t419 = _t32*_t418;
  const double _t420 = _t410 + _t411 + _t412 + _t419;
  const double _t427 = _hc6[2]*_t125;
  const double _t429 = my_piecewise3(_t25, 36.738723026100004*_t124*_t143*_t27 + 15.506534051159999*_t124*_t143*_t29 - _t143*_t421 - _t183*_t422 - _t184*_t422 - _t185*_t422 + 12.2462410087*_t28*_t426 + 3.1013068102319998*_t30*_t426 - _t426*_t70 - _t426*_t71 - _t426*_t72 - _t426*_t73 - 0.64000000000000001*_t426, _hc6[1]*_t428 + _t144*_t427);
  const double _t430 = _t429*_t48;
  const double _t431 = _t126*_t140;
  const double _t432 = _t132*_t145;
  const double _t443 = _t32*_t442;
  const double _t444 = _t430 + _t431 + _t432 + _t435 + _t443;
  const double _t445 = _t1*(_t345 + _t444) + _t146;
  const double _t451 = my_piecewise3(_t25, 36.738723026100004*_t124*_t149*_t27 + 15.506534051159999*_t124*_t149*_t29 - _t149*_t421 - _t183*_t447 - _t184*_t447 - _t185*_t447 + 12.2462410087*_t28*_t449 + 3.1013068102319998*_t30*_t449 - _t449*_t70 - _t449*_t71 - _t449*_t72 - _t449*_t73 - 0.64000000000000001*_t449, _hc6[1]*_t450 + _t150*_t427);
  const double _t452 = _t451*_t48;
  const double _t453 = _t126*_t148;
  const double _t454 = _t132*_t151;
  const double _t456 = _t32*_t455;
  const double _t457 = _t452 + _t453 + _t454 + _t456;
  const double _t458 = _t115*_t156;
  const double _t467 = my_piecewise3(_t25, -_t154*_t262 + 36.738723026100004*_t154*_t27*_t69 + 15.506534051159999*_t154*_t29*_t69 - _t183*_t465 - _t184*_t465 - _t185*_t465 + 12.2462410087*_t28*_t464 + 3.1013068102319998*_t30*_t464 - _t464*_t70 - _t464*_t71 - _t464*_t72 - _t464*_t73 - 0.64000000000000001*_t464, _hc6[1]*_t466 + _t155*_t278);
  const double _t468 = _t467*_t48;
  const double _t469 = _t458 + _t468;
  const double _t470 = _t115*_t161;
  const double _t478 = my_piecewise3(_t25, -_t159*_t262 + 36.738723026100004*_t159*_t27*_t69 + 15.506534051159999*_t159*_t29*_t69 - _t183*_t476 - _t184*_t476 - _t185*_t476 + 12.2462410087*_t28*_t475 + 3.1013068102319998*_t30*_t475 - _t475*_t70 - _t475*_t71 - _t475*_t72 - _t475*_t73 - 0.64000000000000001*_t475, _hc6[1]*_t477 + _t160*_t278);
  const double _t479 = _t478*_t48;
  const double _t480 = _t470 + _t479;
  const double _t481 = _t132*_t156;
  const double _t486 = my_piecewise3(_t25, 36.738723026100004*_t124*_t154*_t27 + 15.506534051159999*_t124*_t154*_t29 - _t154*_t421 - _t183*_t484 - _t184*_t484 - _t185*_t484 + 12.2462410087*_t28*_t483 + 3.1013068102319998*_t30*_t483 - _t483*_t70 - _t483*_t71 - _t483*_t72 - _t483*_t73 - 0.64000000000000001*_t483, _hc6[1]*_t485 + _t155*_t427);
  const double _t487 = _t48*_t486;
  const double _t488 = _t481 + _t487;
  const double _t489 = _t132*_t161;
  const double _t497 = my_piecewise3(_t25, 36.738723026100004*_t124*_t159*_t27 + 15.506534051159999*_t124*_t159*_t29 - _t159*_t421 - _t183*_t495 - _t184*_t495 - _t185*_t495 + 12.2462410087*_t28*_t494 + 3.1013068102319998*_t30*_t494 - _t494*_t70 - _t494*_t71 - _t494*_t72 - _t494*_t73 - 0.64000000000000001*_t494, _hc6[1]*_t496 + _t160*_t427);
  const double _t498 = _t48*_t497;
  const double _t499 = _t489 + _t498;
  const double _t511 = my_piecewise3(_t25, -_t183*_t500 - _t184*_t500 - _t185*_t500 + 36.738723026100004*_t27*_t500 + 12.2462410087*_t28*_t508 + 15.506534051159999*_t29*_t500 + 3.1013068102319998*_t30*_t508 - 0.87039999999999995*_t500 - _t508*_t70 - _t508*_t71 - _t508*_t72 - _t508*_t73 - 0.64000000000000001*_t508, _hc6[1]*_t510 + _hc6[2]*_t509);
  const double _t520 = _t145*_t519 + _t32*_t518 + _t48*_t511 + _t517;
  const double _t521 = _t1*_t520;
  const double _t527 = _hc6[2]*_t144;
  const double _t528 = my_piecewise3(_t25, 36.738723026100004*_t143*_t149*_t27 + 15.506534051159999*_t143*_t149*_t29 - _t149*_t524 - _t183*_t525 - _t184*_t525 - _t185*_t525 + 12.2462410087*_t28*_t523 + 3.1013068102319998*_t30*_t523 - _t523*_t70 - _t523*_t71 - _t523*_t72 - _t523*_t73 - 0.64000000000000001*_t523, _hc6[1]*_t526 + _t150*_t527);
  const double _t533 = _t140*_t151 + _t145*_t148 + _t32*_t532 + _t48*_t528 + _t531;
  const double _t534 = _t1*_t533;
  const double _t540 = my_piecewise3(_t25, -_t183*_t535 - _t184*_t535 - _t185*_t535 + 36.738723026100004*_t27*_t535 + 12.2462410087*_t28*_t537 + 15.506534051159999*_t29*_t535 + 3.1013068102319998*_t30*_t537 - 0.87039999999999995*_t535 - _t537*_t70 - _t537*_t71 - _t537*_t72 - _t537*_t73 - 0.64000000000000001*_t537, _hc6[1]*_t539 + _hc6[2]*_t538);
  const double _t544 = _t151*_t543 + _t32*_t542 + _t48*_t540 + _t541;
  const double _t551 = my_piecewise3(_t25, 36.738723026100004*_t143*_t154*_t27 + 15.506534051159999*_t143*_t154*_t29 - _t154*_t524 - _t183*_t549 - _t184*_t549 - _t185*_t549 + 12.2462410087*_t28*_t548 + 3.1013068102319998*_t30*_t548 - _t548*_t70 - _t548*_t71 - _t548*_t72 - _t548*_t73 - 0.64000000000000001*_t548, _hc6[1]*_t550 + _t155*_t527);
  const double _t552 = _t140*_t156 + _t48*_t551;
  const double _t553 = _t1*_t552;
  const double _t560 = my_piecewise3(_t25, 36.738723026100004*_t143*_t159*_t27 + 15.506534051159999*_t143*_t159*_t29 - _t159*_t524 - _t183*_t558 - _t184*_t558 - _t185*_t558 + 12.2462410087*_t28*_t557 + 3.1013068102319998*_t30*_t557 - _t557*_t70 - _t557*_t71 - _t557*_t72 - _t557*_t73 - 0.64000000000000001*_t557, _hc6[1]*_t559 + _t160*_t527);
  const double _t561 = _t140*_t161 + _t48*_t560;
  const double _t562 = _t1*_t561;
  const double _t567 = _hc6[2]*_t150;
  const double _t568 = my_piecewise3(_t25, 36.738723026100004*_t149*_t154*_t27 + 15.506534051159999*_t149*_t154*_t29 - _t154*_t564 - _t183*_t565 - _t184*_t565 - _t185*_t565 + 12.2462410087*_t28*_t563 + 3.1013068102319998*_t30*_t563 - _t563*_t70 - _t563*_t71 - _t563*_t72 - _t563*_t73 - 0.64000000000000001*_t563, _hc6[1]*_t566 + _t155*_t567);
  const double _t569 = _t148*_t156 + _t48*_t568;
  const double _t573 = my_piecewise3(_t25, 36.738723026100004*_t149*_t159*_t27 + 15.506534051159999*_t149*_t159*_t29 - _t159*_t564 - _t183*_t571 - _t184*_t571 - _t185*_t571 + 12.2462410087*_t28*_t570 + 3.1013068102319998*_t30*_t570 - _t570*_t70 - _t570*_t71 - _t570*_t72 - _t570*_t73 - 0.64000000000000001*_t570, _hc6[1]*_t572 + _t160*_t567);
  const double _t574 = _t148*_t161 + _t48*_t573;
  const double _t581 = my_piecewise3(_t25, -_t183*_t578 - _t184*_t578 - _t185*_t578 + 36.738723026100004*_t27*_t578 + 12.2462410087*_t28*_t577 + 15.506534051159999*_t29*_t578 + 3.1013068102319998*_t30*_t577 - _t577*_t70 - _t577*_t71 - _t577*_t72 - _t577*_t73 - 0.64000000000000001*_t577 - 0.87039999999999995*_t578, _hc6[1]*_t579 + _hc6[2]*_t580);
  const double _t582 = _t48*_t581;
  const double _t588 = _hc6[2]*_t155;
  const double _t589 = my_piecewise3(_t25, 36.738723026100004*_t154*_t159*_t27 + 15.506534051159999*_t154*_t159*_t29 - _t159*_t585 - _t183*_t586 - _t184*_t586 - _t185*_t586 + 12.2462410087*_t28*_t584 + 3.1013068102319998*_t30*_t584 - _t584*_t70 - _t584*_t71 - _t584*_t72 - _t584*_t73 - 0.64000000000000001*_t584, _hc6[1]*_t587 + _t160*_t588);
  const double _t590 = _t48*_t589;
  const double _t597 = my_piecewise3(_t25, -_t183*_t594 - _t184*_t594 - _t185*_t594 + 36.738723026100004*_t27*_t594 + 12.2462410087*_t28*_t593 + 15.506534051159999*_t29*_t594 + 3.1013068102319998*_t30*_t593 - _t593*_t70 - _t593*_t71 - _t593*_t72 - _t593*_t73 - 0.64000000000000001*_t593 - 0.87039999999999995*_t594, _hc6[1]*_t595 + _hc6[2]*_t596);
  const double _t598 = _t48*_t597;
  const double d2F_dna2 = _t1*(_t181 + _t257) + 0.2e1*_t116 + _t261 + 0.2e1*_t61 + 0.2e1*_t76;
  const double d2F_dna_dnb = _t1*(_t281 + _t282 + _t283 + _t302 + _t304) + _t117 + _t134 + _t261;
  const double d2F_dnb2 = _t1*(_t301 + _t334) + 0.2e1*_t119 + 0.2e1*_t127 + 0.2e1*_t133 + _t261;
  const double d2F_dna_dgaa = _t393;
  const double d2F_dna_dgab = _t1*(_t401 + _t420) + _t152;
  const double d2F_dna_dgbb = _t393;
  const double d2F_dnb_dgaa = _t445;
  const double d2F_dnb_dgab = _t1*(_t446 + _t457) + _t152;
  const double d2F_dnb_dgbb = _t445;
  const double d2F_dna_dta = _t1*_t469 + _t157;
  const double d2F_dna_dtb = _t1*_t480 + _t162;
  const double d2F_dnb_dta = _t1*_t488 + _t157;
  const double d2F_dnb_dtb = _t1*_t499 + _t162;
  const double d2F_dgaa2 = _t521;
  const double d2F_dgaa_dgab = _t534;
  const double d2F_dgaa_dgbb = _t521;
  const double d2F_dgab2 = _t1*_t544;
  const double d2F_dgab_dgbb = _t534;
  const double d2F_dgbb2 = _t521;
  const double d2F_dgaa_dta = _t553;
  const double d2F_dgaa_dtb = _t562;
  const double d2F_dgab_dta = _t1*_t569;
  const double d2F_dgab_dtb = _t1*_t574;
  const double d2F_dgbb_dta = _t553;
  const double d2F_dgbb_dtb = _t562;
  const double d2F_dta2 = _t1*_t582;
  const double d2F_dta_dtb = _t1*_t590;
  const double d2F_dtb2 = _t1*_t598;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 1] += d2F_dna_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 4] += d2F_dnb_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 1] += d2F_dna_dtb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 2] += d2F_dnb_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 1] += d2F_dgaa_dgab;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 2] += d2F_dgaa_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 3] += d2F_dgab2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 4] += d2F_dgab_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 1] += d2F_dgaa_dtb;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 2] += d2F_dgab_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 3] += d2F_dgab_dtb;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 4] += d2F_dgbb_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 5] += d2F_dgbb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 1] += d2F_dta_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double _t606 = 0.6e1*_t91;
  const double _t607 = 0.6e1*_t39;
  const double _t608 = _t607*_t8;
  const double _t609 = _t606 - _t608;
  const double _t618 = _t200*ta;
  const double _t621 = _t13*_t176;
  const double _t648 = (0.280e3 / 0.27e2)*_t384;
  const double _t650 = (0.14e2 / 0.27e2)*_t139;
  const double _t656 = 0.48e2*_t362;
  const double _t657 = _t222*_t83;
  const double _t658 = 0.3300e4*_t657;
  const double _t659 = _t45*_t85;
  const double _t660 = 0.2448e4*_t659;
  const double _t661 = _t43*_t87;
  const double _t662 = 0.1092e4*_t661;
  const double _t663 = _t41*_t89;
  const double _t664 = 0.360e3*_t663;
  const double _t665 = _t38*_t93;
  const double _t666 = _t40*_t94;
  const double _t667 = 0.1320e4*_t46/xc_powi(_t1, 13);
  const double _t668 = _t42*_t95;
  const double _t669 = _t44*_t96;
  const double _t670 = 0.168e3*_t665 + 0.660e3*_t666 + _t667 + 0.1680e4*_t668 + 0.3420e4*_t669 + 0.12e2*_t91;
  const double _t671 = 0.24e2*nb;
  const double _t674 = 0.12e2*_t34;
  const double _t675 = _t362*_t674;
  const double _t676 = _t34*_t671;
  const double _t678 = 0.24e2*_t34;
  const double _t681 = _t674*na*nb;
  const double _t682 = _t681*_t98;
  const double _t683 = _t675*na;
  const double _t689 = 0.72e2*_t369*_t39;
  const double _t690 = _t218*_t8;
  const double _t703 = (0.56e2 / 0.9e1)*_t244;
  const double _t706 = (0.4e1 / 0.9e1)*_t5*_t50;
  const double _t709 = _t5*_t650;
  const double _t711 = _t17*_t245;
  const double _t713 = 0.24e2*na;
  const double _t714 = _t362*_t713;
  const double _t716 = 0.4e1*_t110;
  const double _t717 = _t11*_t6;
  const double _t727 = -_t608 + 0.2e1*_t91;
  const double _t728 = _t121*tb;
  const double _t753 = 0.144e3*_t659;
  const double _t754 = 0.84e2*_t661;
  const double _t755 = 0.40e2*_t663;
  const double _t756 = 0.1100e4*_t657;
  const double _t757 = _t218 + 0.24e2*_t665 + 0.60e2*_t666 - _t667 + 0.112e3*_t668 + 0.180e3*_t669;
  const double _t759 = 0.16e2*_t129;
  const double _t760 = _t100*_t759;
  const double _t761 = _t228*na;
  const double _t763 = _t129*_t130;
  const double _t765 = _t236*_t285;
  const double _t766 = _t230*na;
  const double _t767 = 0.16e2*_t367;
  const double _t770 = _t656*na;
  const double _t773 = -_t34*_t8;
  const double _t774 = _t100*_t212*_t8*_t93;
  const double _t783 = _t60*_t766;
  const double _t795 = _t314*tb;
  const double _t815 = _t130*_t98;
  const double _t825 = -_t606 - _t608;
  const double _t832 = _t436*_t674;
  const double _t833 = _t129*_t681;
  const double _t839 = _t62*ta;
  const double _t840 = _t347*_t839;
  const double _t841 = _t135*_t338;
  const double _t849 = (0.20e2 / 0.9e1)*_t136;
  const double _t850 = (0.14e2 / 0.9e1)*_t512;
  const double _t851 = (0.14e2 / 0.9e1)*_t139;
  const double _t852 = _t135*_t413;
  const double _t859 = (0.1e1 / 0.3e1)*_t369;
  const double _t872 = _t135*_t381;
  const double _t873 = _t375*_t376;
  const double _t874 = _t374*_t873;
  const double _t875 = _t341*_t35*_t378;
  const double _t876 = (0.1e1 / 0.24e2)*_t875;
  const double _t877 = _t17*_t872;
  const double _t878 = _t100*_t212*_t91;
  const double _t879 = xc_powr(_t1, -16, 3);
  const double _t889 = _t135*_t51;
  const double _t890 = _t397*_t5;
  const double _t897 = (0.28e2 / 0.9e1)*_t512;
  const double _t898 = (0.2e1 / 0.9e1)*_t135*_t335;
  const double _t905 = (0.2e1 / 0.3e1)*_t369;
  const double _t911 = _t135*_t178;
  const double _t912 = _t413*_t873;
  const double _t913 = (0.1e1 / 0.12e2)*_t875;
  const double _t914 = _t17*_t911;
  const double _t922 = _t423*tb;
  const double _t925 = _t385*_t8;
  const double _t971 = _t118*_t766;
  const double _t991 = _t459*_t461;
  const double _t1004 = _t21*_t472;
  const double _t1031 = _t490*_t492;
  const double _t1048 = (0.1e1 / 0.4e1)*_t505;
  const double _t1056 = (0.5e1 / 0.12e2)*_t502;
  const double _t1058 = _t335*_t501;
  const double _t1059 = _t135*_t93;
  const double _t1061 = _t39*_t501;
  const double _t1095 = (0.1e1 / 0.2e1)*_t505;
  const double _t1117 = (0.5e1 / 0.6e1)*_t502;
  const double _t1137 = _t242*_t504;
  const double _t1145 = (0.1e1 / 0.2e1)*_t502;
  const double _t1292 = (0.1e1 / (_t12 * _t12));
  const double _t1293 = _t1292*_t242;
  const double _t1296 = xc_powr(_t12, -5, 2);
  const double _t1297 = _t11*_t1296;
  const double _t1298 = (0.3e1 / 0.8e1)*_t1297;
  const double _t1308 = _t39*_t504;
  const double _t1314 = (0.1e1 / 0.2e1)*_t136;
  const double _t1317 = (0.3e1 / 0.4e1)*_t1297;
  const double _t1331 = (0.3e1 / 0.2e1)*_t1297;
  const double _t1346 = 0.3e1*_t1297;
  const double _t599 = (_t69 * _t69 * _t69);
  const double _t600 = 114.94261417235998*_t27;
  const double _t601 = 10.888264756320002*_t29;
  const double _t602 = _t207*_t69;
  const double _t603 = 27.642340881881999*_t26;
  const double _t604 = 114.94261417235998*_t28;
  const double _t605 = 6.5329588537920005*_t30;
  const double _t610 = _hc5[39]*_t52 + _hc5[50]*_t55;
  const double _t611 = _hc5[35]*_t52;
  const double _t612 = _hc5[48]*_t55;
  const double _t613 = _t611 + _t612;
  const double _t614 = -_hc5[33]*_t472 + _hc5[38]*_t60 - _t613;
  const double _t615 = _hc5[35]*_t472;
  const double _t616 = _hc5[36]*_t52 + _hc5[49]*_t55;
  const double _t617 = _hc5[39]*_t60 - _t615 - _t616;
  const double _t619 = _hc5[49]*_t52 + _hc5[54]*_t55;
  const double _t620 = -_hc5[48]*_t472 + _hc5[50]*_t60 - _t619;
  const double _t622 = _hc5[14]*_t621 + _hc5[19]*_t179;
  const double _t623 = _hc5[14]*_t165;
  const double _t624 = _hc5[27]*_t472;
  const double _t625 = _hc5[29]*_t52;
  const double _t626 = _hc5[45]*_t55;
  const double _t627 = _t625 + _t626;
  const double _t628 = _hc5[35]*_t60 - _t624 - _t627;
  const double _t629 = _hc5[29]*_t472;
  const double _t630 = _hc5[30]*_t52 + _hc5[46]*_t55;
  const double _t631 = _hc5[10]*_t618;
  const double _t632 = _hc5[45]*_t472;
  const double _t633 = _hc5[46]*_t52 + _hc5[53]*_t55;
  const double _t634 = _hc5[49]*_t60 - _t632 - _t633;
  const double _t635 = _hc5[11]*_t621 + _hc5[18]*_t179;
  const double _t636 = _hc5[13]*_t165;
  const double _t637 = _hc5[27]*_t52;
  const double _t638 = _hc5[43]*_t55;
  const double _t639 = _t637 + _t638;
  const double _t640 = _hc5[45]*_t52;
  const double _t641 = _hc5[52]*_t55;
  const double _t642 = _t640 + _t641;
  const double _t643 = -_hc5[43]*_t472 + _hc5[48]*_t60 - _t642;
  const double _t644 = _hc5[17]*_t179;
  const double _t645 = _hc5[10]*_t621 + _t644;
  const double _t646 = _hc5[53]*_t52 + _hc5[55]*_t55;
  const double _t647 = _hc5[18]*_t621 + _hc5[20]*_t179;
  const double _t649 = _t648*_t65;
  const double _t651 = _t650*_t66;
  const double _t652 = _t649 + _t651;
  const double _t653 = -0.440e3 / 0.27e2*_hc5[2]*ta/xc_powr(na, 14, 3) + _hc5[4]*_t609 + (0.56e2 / 0.9e1)*_t13*_t139*_t198 + 0.2e1*_t165*_t188 + (0.80e2 / 0.9e1)*_t193*_t199*ta + (0.4e1 / 0.9e1)*_t204*_t3*_t4*_t50 - _t472*(_hc5[8]*_t618 - _t472*(-_hc5[24]*_t472 + _hc5[33]*_t60 - _t639) - _t52*_t628 - _t55*_t643 + _t60*_t614 + _t636 + _t645) - _t52*(-_t472*_t628 - _t52*(_hc5[36]*_t60 - _t629 - _t630) - _t55*_t634 + _t60*_t617 + _t623 + _t631 + _t635) - _t55*(_hc5[17]*_t618 + _hc5[19]*_t165 - _t472*_t643 - _t52*_t634 - _t55*(-_hc5[52]*_t472 + _hc5[54]*_t60 - _t646) + _t60*_t620 + _t647) + _t60*(_hc5[13]*_t618 + _hc5[15]*_t165 - _t472*_t614 - _t52*_t617 - _t55*_t620 + _t60*(-_hc5[38]*_t472 + _hc5[40]*_t60 - _t610) + _t622) - _t652;
  const double _t654 = my_piecewise3(_t24, 0, _t653);
  const double _t655 = _t284*_t98;
  const double _t672 = _t106*_t671;
  const double _t673 = 0.48e2*_t250;
  const double _t677 = _t104*_t98;
  const double _t679 = _t101*_t103;
  const double _t680 = _hc1[3]*_t101*_t102;
  const double _t684 = _t249*_t370;
  const double _t685 = _t60*_t684;
  const double _t686 = _t165*_t239;
  const double _t687 = _hc1[2]*_t238;
  const double _t688 = _t232*_t687;
  const double _t691 = _t101*_t295;
  const double _t692 = _hc0[39]*_t52 + _hc0[50]*_t55;
  const double _t693 = _hc0[36]*_t52 + _hc0[49]*_t55;
  const double _t694 = _hc0[39]*_t60 - _t693;
  const double _t695 = _hc0[49]*_t52 + _hc0[54]*_t55;
  const double _t696 = _hc0[50]*_t60 - _t695;
  const double _t697 = _hc0[14]*_t621 + _hc0[19]*_t179;
  const double _t698 = _hc0[14]*_t165;
  const double _t699 = _hc0[30]*_t52 + _hc0[46]*_t55;
  const double _t700 = _hc0[46]*_t52 + _hc0[53]*_t55;
  const double _t701 = _hc0[49]*_t60 - _t700;
  const double _t702 = _hc0[11]*_t621 + _hc0[18]*_t179;
  const double _t704 = _hc0[53]*_t52 + _hc0[55]*_t55;
  const double _t705 = _hc0[18]*_t621 + _hc0[20]*_t179;
  const double _t707 = -_t177*_t648 - _t259*_t650;
  const double _t708 = _hc0[4]*_t609 + 0.2e1*_t165*_t168 + _t171*_t703 + _t174*_t706 - _t52*(-_t52*(_hc0[36]*_t60 - _t699) - _t55*_t701 + _t60*_t694 + _t698 + _t702) - _t55*(_hc0[19]*_t165 - _t52*_t701 - _t55*(_hc0[54]*_t60 - _t704) + _t60*_t696 + _t705) + _t60*(_hc0[15]*_t165 - _t52*_t694 - _t55*_t696 + _t60*(_hc0[40]*_t60 - _t692) + _t697) + _t707;
  const double _t710 = _t109*_t384;
  const double _t712 = -_hc2[7]*_t246 - _hc2[8]*_t55;
  const double _t715 = -0.72e2*_t112*_t37*_t39*_t47*na*nb + _t249*_t37*_t714*_t91 - 0.4e1*_t34*_t37*_t47*na*nb*(-_hc2[2]*_t709 - _hc3[1]*_t709 - 0.1e1 / 0.36e2*_hc3[3]*_t378*_t39 + (0.28e2 / 0.27e2)*_t13*_t139*_t15*_t16*_t248 - 0.140e3 / 0.81e2*_t13*_t710 - _t243*_t413 - _t246*(_hc2[3]*_t711 + _hc2[4]*_t179 - _t246*(-_hc2[6]*_t246 - _hc2[7]*_t55) - _t55*_t712) + (0.4e1 / 0.9e1)*_t247*_t3*_t4*_t50 - _t55*(_hc2[4]*_t711 + _hc2[5]*_t179 - _t246*_t712 - _t55*(-_hc2[8]*_t246 - _hc2[9]*_t55))) + 0.96e2*_t369*_t77*_t93;
  const double _t718 = (0.28e2 / 0.3e1)*_t139*_t177 + _t259*_t338;
  const double _t719 = 9.2141136272939992*_t182;
  const double _t720 = _t124*_t182;
  const double _t721 = 1.7407999999999999*_t277;
  const double _t722 = _t277*_t69;
  const double _t723 = 18.428227254587998*_t26;
  const double _t724 = 76.628409448239992*_t28;
  const double _t725 = 4.3553059025280003*_t30;
  const double _t726 = _t124*_t207;
  const double _t729 = _hc5[32]*_t728;
  const double _t730 = _hc5[38]*_t118 - _t613 - _t729;
  const double _t731 = _hc5[13]*_t164;
  const double _t732 = _hc5[23]*_t728;
  const double _t733 = _hc5[26]*_t728;
  const double _t734 = _hc5[35]*_t118 - _t627 - _t733;
  const double _t735 = _hc5[42]*_t728;
  const double _t736 = _hc5[48]*_t118 - _t642 - _t735;
  const double _t737 = -_t52*_t734 - _t55*_t736 + _t645;
  const double _t738 = -_hc5[47]*_t728 + _hc5[50]*_t118 - _t619;
  const double _t739 = _hc5[44]*_t728;
  const double _t740 = _hc5[49]*_t118 - _t633 - _t739;
  const double _t741 = -_t52*_t740 - _t55*(-_hc5[51]*_t728 + _hc5[54]*_t118 - _t646) + _t647;
  const double _t742 = _hc5[34]*_t728;
  const double _t743 = _hc5[39]*_t118 - _t616 - _t742;
  const double _t744 = _hc5[28]*_t728;
  const double _t745 = -_t52*(_hc5[36]*_t118 - _t630 - _t744) - _t55*_t740 + _t635;
  const double _t746 = -_hc5[37]*_t728 + _hc5[40]*_t118 - _t610;
  const double _t747 = -_t52*_t743 - _t55*_t738 + _t622;
  const double _t748 = _hc5[4]*_t727 + _t164*_t188 + _t165*_t265 + _t179*_t204 + _t179*_t274 + _t198*_t621 + _t268*_t618 + _t272*_t621 - _t472*(-_t472*(_hc5[33]*_t118 - _t639 - _t732) + _t60*_t730 + _t731 + _t737) - _t52*(_hc5[14]*_t164 - _t472*_t734 + _t60*_t743 + _t745) - _t55*(_hc5[19]*_t164 - _t472*_t736 + _t60*_t738 + _t741) + _t60*(_hc5[15]*_t164 - _t472*_t730 + _t60*_t746 + _t747) - _t649 - _t651;
  const double _t749 = my_piecewise3(_t24, 0, _t748);
  const double _t751 = 0.2e1*_t279;
  const double _t752 = 0.32e2*_t250;
  const double _t758 = _t103*_t229;
  const double _t762 = _t212*_t294;
  const double _t764 = _t118*_t684;
  const double _t768 = _t131*_t39;
  const double _t769 = _t104*_t39;
  const double _t771 = _t118*_t233;
  const double _t772 = _t101*_t771;
  const double _t775 = _hc0[40]*_t118 - _t692;
  const double _t776 = _hc0[39]*_t118 - _t693;
  const double _t777 = _hc0[50]*_t118 - _t695;
  const double _t778 = -_t52*_t776 - _t55*_t777 + _t697;
  const double _t779 = _hc0[49]*_t118 - _t700;
  const double _t780 = -_t52*(_hc0[36]*_t118 - _t699) - _t55*_t779 + _t702;
  const double _t781 = -_t52*_t779 - _t55*(_hc0[54]*_t118 - _t704) + _t705;
  const double _t782 = _hc0[4]*_t727 + _t164*_t168 + _t165*_t297 + _t171*_t621 + _t174*_t179 + _t179*_t300 + _t299*_t621 - _t52*(_hc0[14]*_t164 + _t60*_t776 + _t780) - _t55*(_hc0[19]*_t164 + _t60*_t777 + _t781) + _t60*(_hc0[15]*_t164 + _t60*_t775 + _t778) + _t707;
  const double _t784 = -0.16e2*_hc1[1]*_t118*_t33*_t36*_t47*_t91*nb - 0.16e2*_hc1[1]*_t118*_t33*_t36*_t91*_t98*na*nb - 0.16e2*_hc1[1]*_t129*_t33*_t36*_t60*_t91*na*nb - 0.16e2*_hc1[1]*_t33*_t36*_t47*_t60*_t91*na - 0.16e2*_hc1[2]*_t118*_t33*_t36*_t47*_t60*_t91*na*nb - 0.8e1*_t112*_t129*_t34*_t37*nb - 0.8e1*_t112*_t285*_t34*_t37*na*nb - 0.8e1*_t112*_t34*_t37*_t47 - 0.8e1*_t112*_t34*_t37*_t98*na + _t118*_t687*_t783 + _t213 + _t226*_t285*nb + _t227 + _t237*_t293 + _t239*_t774 + _t240*_t325 + _t240*_t329 + _t284*_t759 + _t330 + _t715;
  const double _t785 = 0.2e1*_t115;
  const double _t786 = 0.2e1*_t303;
  const double _t788 = 9.2141136272939992*_t307;
  const double _t789 = _t307*_t69;
  const double _t790 = _t124*_t277;
  const double _t791 = _t317*_t69;
  const double _t792 = _hc5[47]*_t55;
  const double _t793 = _hc5[34]*_t52;
  const double _t794 = -_hc5[31]*_t728 + _hc5[37]*_t118 - _t792 - _t793;
  const double _t796 = _hc5[12]*_t795 + _hc5[15]*_t305 + _t118*_t746 - _t728*_t794 + _t747;
  const double _t797 = _hc5[13]*_t305;
  const double _t798 = _hc5[42]*_t55;
  const double _t799 = _hc5[26]*_t52;
  const double _t800 = _hc5[7]*_t795;
  const double _t801 = _hc5[14]*_t305;
  const double _t802 = _hc5[25]*_t728;
  const double _t803 = _hc5[44]*_t55;
  const double _t804 = _hc5[28]*_t52;
  const double _t805 = _hc5[34]*_t118 - _t802 - _t803 - _t804;
  const double _t806 = _hc5[9]*_t795;
  const double _t807 = _hc5[51]*_t55;
  const double _t808 = _hc5[44]*_t52;
  const double _t809 = -_hc5[41]*_t728 + _hc5[47]*_t118 - _t807 - _t808;
  const double _t810 = -0.56e2 / 0.9e1*_t13*_t139*_t272 - 0.4e1 / 0.9e1*_t274*_t3*_t4*_t50 + _t52*(_t118*_t743 - _t728*_t805 + _t745 + _t801 + _t806) + _t55*(_hc5[16]*_t795 + _hc5[19]*_t305 + _t118*_t738 - _t728*_t809 + _t741) + _t652;
  const double _t811 = -_hc5[4]*_t608 - _hc5[4]*_t92 + 0.4e1*_t265*_t8*_t91 - _t472*(_t118*_t730 - _t728*(-_hc5[22]*_t728 + _hc5[32]*_t118 - _t798 - _t799) + _t737 + _t797 + _t800) + _t60*_t796 - _t810;
  const double _t812 = my_piecewise3(_t24, 0, _t811);
  const double _t814 = _t129*_t131;
  const double _t816 = _t239*_t305;
  const double _t817 = _t327*_t687;
  const double _t818 = _hc0[15]*_t305 + _t118*_t775 + _t778;
  const double _t819 = _hc0[14]*_t305;
  const double _t820 = _t299*_t703 + _t300*_t706 - _t52*(_t118*_t776 + _t780 + _t819) - _t55*(_hc0[19]*_t305 + _t118*_t777 + _t781) + _t707;
  const double _t821 = -_hc0[4]*_t608 - _hc0[4]*_t92 + _t297*_t690 + _t60*_t818 + _t820;
  const double _t822 = -_t299*_t716 - _t300*_t717 + _t718;
  const double _t823 = (_t124 * _t124 * _t124);
  const double _t824 = _t124*_t317;
  const double _t826 = _hc5[16]*_t179;
  const double _t827 = _hc5[12]*_t305;
  const double _t828 = _hc5[41]*_t55;
  const double _t829 = _hc5[25]*_t52;
  const double _t830 = -0.440e3 / 0.27e2*_hc5[1]*tb/xc_powr(nb, 14, 3) + _hc5[4]*_t825 + _t118*_t796 + 0.2e1*_t265*_t305 + (0.80e2 / 0.9e1)*_t311*_t313*tb - _t728*(_hc5[6]*_t795 + _hc5[9]*_t621 + _t118*_t794 - _t52*_t805 - _t55*_t809 - _t728*(-_hc5[21]*_t728 + _hc5[31]*_t118 - _t828 - _t829) + _t826 + _t827) - _t810;
  const double _t831 = my_piecewise3(_t24, 0, _t830);
  const double _t834 = _hc0[4]*_t825 + _t118*_t818 + 0.2e1*_t297*_t305 + _t820;
  const double _t835 = _t143*_t182;
  const double _t836 = 1.7407999999999999*_t69;
  const double _t837 = _t353*_t69;
  const double _t838 = _t143*_t207;
  const double _t842 = _hc5[14]*_t841 + _hc5[36]*_t336 + _hc5[49]*_t343;
  const double _t843 = _hc5[29]*_t336;
  const double _t844 = _hc5[45]*_t343;
  const double _t845 = _hc5[10]*_t841 + _t843 + _t844;
  const double _t846 = _hc5[11]*_t841 + _hc5[30]*_t336 + _hc5[46]*_t343;
  const double _t847 = _t136*_t623;
  const double _t848 = _hc5[18]*_t841 + _hc5[46]*_t336 + _hc5[53]*_t343;
  const double _t853 = _hc5[11]*_t850 + _t350*_t851 + _t404*_t852;
  const double _t854 = _hc5[10]*_t199*_t849*ta - _t198*_t841 - _t472*(-_hc5[27]*_t840 + (0.1e1 / 0.2e1)*_hc5[35]*_t11*_t135*_t60 - _t845) - _t52*(-_hc5[29]*_t840 + (0.1e1 / 0.2e1)*_hc5[36]*_t11*_t135*_t60 - _t846) - _t55*(-_hc5[45]*_t840 + (0.1e1 / 0.2e1)*_hc5[49]*_t11*_t135*_t60 - _t848) + _t60*(-_hc5[35]*_t840 + (0.1e1 / 0.2e1)*_hc5[39]*_t11*_t135*_t60 - _t842) + (0.1e1 / 0.2e1)*_t847 + _t853;
  const double _t855 = my_piecewise3(_t24, 0, _t854);
  const double _t857 = _t370*_t382;
  const double _t858 = _t362*_t372;
  const double _t860 = _t165*_t371;
  const double _t861 = _hc1[2]*_t36*_t364;
  const double _t862 = _t232*_t861;
  const double _t863 = _t367*_t372;
  const double _t864 = _hc0[14]*_t841 + _hc0[36]*_t336 + _hc0[49]*_t343;
  const double _t865 = _hc0[11]*_t841 + _hc0[30]*_t336 + _hc0[46]*_t343;
  const double _t866 = _t136*_t698;
  const double _t867 = _hc0[18]*_t841 + _hc0[46]*_t336 + _hc0[53]*_t343;
  const double _t868 = _hc0[11]*_t850 + _t339*_t851 + _t398*_t852;
  const double _t869 = -_t171*_t841 - _t52*((0.1e1 / 0.2e1)*_hc0[36]*_t11*_t135*_t60 - _t865) - _t55*((0.1e1 / 0.2e1)*_hc0[49]*_t11*_t135*_t60 - _t867) + _t60*((0.1e1 / 0.2e1)*_hc0[39]*_t11*_t135*_t60 - _t864) + (0.1e1 / 0.2e1)*_t866 + _t868;
  const double _t870 = _t377*_t512;
  const double _t871 = _t17*_t248;
  const double _t880 = -0.2e1*_hc2[1]*_t135*_t15*_t16*_t37*_t47*_t879*na*nb - 0.4e1*_t34*_t37*_t47*na*nb*(_t135*_t374*_t379 - _t246*(-_hc2[3]*_t877 - _hc2[6]*_t874 - _hc2[7]*_t876) + (0.7e1 / 0.27e2)*_t364 - _t55*(-_hc2[4]*_t877 - _hc2[7]*_t874 - _hc2[8]*_t876) + (0.7e1 / 0.54e2)*_t870 - _t871*_t872) + _t383*_t878;
  const double _t881 = _t362*_t37;
  const double _t882 = _t367*_t37;
  const double _t883 = -0.4e1 / 0.3e1*_hc1[1]*_hc2[1]*_t135*_t15*_t16*_t36*_t384*_t47*_t60*na*nb + _t416*_t881 + _t416*_t882;
  const double _t886 = _t149*_t182;
  const double _t887 = _t407*_t69;
  const double _t888 = _t149*_t207;
  const double _t891 = _hc5[14]*_t889 + _hc5[36]*_t394 + _hc5[49]*_t890;
  const double _t892 = _hc5[29]*_t394;
  const double _t893 = _hc5[45]*_t890;
  const double _t894 = _hc5[10]*_t889 + _t892 + _t893;
  const double _t895 = _hc5[11]*_t889 + _hc5[30]*_t394 + _hc5[46]*_t890;
  const double _t896 = _hc5[18]*_t889 + _hc5[46]*_t394 + _hc5[53]*_t890;
  const double _t899 = _hc5[11]*_t897 + _t176*_t350 + _t404*_t898;
  const double _t900 = _t136*_t631 - _t198*_t889 - _t472*(_hc5[35]*_t11*_t135*_t60 - _t136*_t624 - _t894) - _t52*(_hc5[36]*_t11*_t135*_t60 - _t136*_t629 - _t895) - _t55*(_hc5[49]*_t11*_t135*_t60 - _t136*_t632 - _t896) + _t60*(_hc5[39]*_t11*_t135*_t60 - _t136*_t615 - _t891) + _t847 + _t899;
  const double _t901 = my_piecewise3(_t24, 0, _t900);
  const double _t902 = _t370*_t414;
  const double _t903 = _t386*_t881;
  const double _t904 = (0.8e1 / 0.3e1)*_t386;
  const double _t906 = _hc0[14]*_t889 + _hc0[36]*_t394 + _hc0[49]*_t890;
  const double _t907 = _hc0[11]*_t889 + _hc0[30]*_t394 + _hc0[46]*_t890;
  const double _t908 = _hc0[18]*_t889 + _hc0[46]*_t394 + _hc0[53]*_t890;
  const double _t909 = _hc0[11]*_t897 + _t176*_t339 + _t398*_t898;
  const double _t910 = -_t171*_t889 - _t52*(_hc0[36]*_t11*_t135*_t60 - _t907) - _t55*(_hc0[49]*_t11*_t135*_t60 - _t908) + _t60*(_hc0[39]*_t11*_t135*_t60 - _t906) + _t866 + _t909;
  const double _t915 = -0.4e1*_hc2[1]*_t135*_t15*_t16*_t37*_t47*_t879*na*nb - 0.4e1*_t34*_t37*_t47*na*nb*(-_t246*(-_hc2[3]*_t914 - _hc2[6]*_t912 - _hc2[7]*_t913) + _t363*_t650 + _t379*_t852 - _t55*(-_hc2[4]*_t914 - _hc2[7]*_t912 - _hc2[8]*_t913) + (0.7e1 / 0.27e2)*_t870 - _t871*_t911) + _t415*_t878;
  const double _t916 = -0.8e1 / 0.3e1*_hc0[11]*_t335 - _t258*_t339 - 0.1e1 / 0.3e1*_t341*_t398;
  const double _t917 = 9.2141136272939992*_t69;
  const double _t918 = _t143*_t263;
  const double _t919 = _t124*_t353;
  const double _t920 = _t426*_t69;
  const double _t921 = _t143*_t277;
  const double _t923 = -_hc5[34]*_t922 + (0.1e1 / 0.2e1)*_hc5[39]*_t11*_t118*_t135 - _t842;
  const double _t924 = _hc5[26]*_t922;
  const double _t926 = _hc5[14]*_t925;
  const double _t927 = -_t272*_t841 - _t52*(-_hc5[28]*_t922 + (0.1e1 / 0.2e1)*_hc5[36]*_t11*_t118*_t135 - _t846) - _t55*(-_hc5[44]*_t922 + (0.1e1 / 0.2e1)*_hc5[49]*_t11*_t118*_t135 - _t848) + _t853;
  const double _t928 = -_t472*((0.1e1 / 0.2e1)*_hc5[35]*_t11*_t118*_t135 - _t845 - _t924) + _t60*_t923 + _t926 + _t927;
  const double _t929 = my_piecewise3(_t24, 0, _t928);
  const double _t932 = _t101*_t857;
  const double _t933 = _t37*_t436;
  const double _t934 = _t37*_t438;
  const double _t935 = _t372*_t436;
  const double _t936 = _t362*_t440;
  const double _t937 = _t372*_t438;
  const double _t938 = _t367*_t440;
  const double _t939 = _t369*_t370;
  const double _t940 = (0.2e1 / 0.3e1)*_t939;
  const double _t941 = _t363*_t8/xc_powr(_t1, 19, 3);
  const double _t942 = _t118*_t60*_t861;
  const double _t943 = (0.1e1 / 0.2e1)*_hc0[39]*_t11*_t118*_t135 - _t864;
  const double _t944 = _hc0[14]*_t925;
  const double _t945 = -_t299*_t841 - _t52*((0.1e1 / 0.2e1)*_hc0[36]*_t11*_t118*_t135 - _t865) - _t55*((0.1e1 / 0.2e1)*_hc0[49]*_t11*_t118*_t135 - _t867) + _t868;
  const double _t946 = _t60*_t943 + _t944 + _t945;
  const double _t948 = _t149*_t263;
  const double _t949 = _t124*_t407;
  const double _t950 = _t449*_t69;
  const double _t951 = _t149*_t277;
  const double _t952 = _hc5[39]*_t11*_t118*_t135 - _t136*_t742 - _t891;
  const double _t953 = -_t272*_t889 - _t52*(_hc5[36]*_t11*_t118*_t135 - _t136*_t744 - _t895) - _t55*(_hc5[49]*_t11*_t118*_t135 - _t136*_t739 - _t896) + _t899;
  const double _t954 = -_t472*(_hc5[35]*_t11*_t118*_t135 - _t136*_t733 - _t894) + _t60*_t952 + 0.2e1*_t926 + _t953;
  const double _t955 = my_piecewise3(_t24, 0, _t954);
  const double _t956 = _t101*_t902;
  const double _t957 = _hc0[39]*_t11*_t118*_t135 - _t906;
  const double _t958 = -_t299*_t889 - _t52*(_hc0[36]*_t11*_t118*_t135 - _t907) - _t55*(_hc0[49]*_t11*_t118*_t135 - _t908) + _t909;
  const double _t959 = _t60*_t957 + 0.2e1*_t944 + _t958;
  const double _t960 = -0.4e1 / 0.3e1*_hc1[1]*_hc2[1]*_t118*_t135*_t15*_t16*_t36*_t384*_t47*na*nb + _t416*_t933 + _t416*_t934;
  const double _t961 = _t143*_t307;
  const double _t962 = 1.7407999999999999*_t124;
  const double _t963 = _t124*_t426;
  const double _t964 = _t143*_t317;
  const double _t965 = _hc5[28]*_t336;
  const double _t966 = _hc5[44]*_t343;
  const double _t967 = _t136*_t801;
  const double _t968 = _hc5[9]*_t313*_t849*tb + _t118*_t923 - _t728*(-_hc5[25]*_t922 + (0.1e1 / 0.2e1)*_hc5[34]*_t11*_t118*_t135 - _hc5[9]*_t841 - _t965 - _t966) + _t927 + (0.1e1 / 0.2e1)*_t967;
  const double _t969 = my_piecewise3(_t24, 0, _t968);
  const double _t972 = _t436*_t440;
  const double _t973 = _t305*_t371;
  const double _t974 = _t327*_t861;
  const double _t975 = _t438*_t440;
  const double _t976 = _t136*_t819;
  const double _t977 = _t118*_t943 + _t945 + (0.1e1 / 0.2e1)*_t976;
  const double _t980 = _t149*_t307;
  const double _t981 = _t124*_t449;
  const double _t982 = _t149*_t317;
  const double _t983 = _hc5[28]*_t394;
  const double _t984 = _hc5[44]*_t890;
  const double _t985 = _t118*_t952 + _t136*_t806 - _t728*(_hc5[34]*_t11*_t118*_t135 - _hc5[9]*_t889 - _t136*_t802 - _t983 - _t984) + _t953 + _t967;
  const double _t986 = my_piecewise3(_t24, 0, _t985);
  const double _t987 = _t118*_t957 + _t958 + _t976;
  const double _t988 = _t154*_t182;
  const double _t989 = _t464*_t69;
  const double _t990 = _t154*_t207;
  const double _t992 = _t19*_t611 + _t19*_t612;
  const double _t993 = _t19*_t637 + _t19*_t638;
  const double _t994 = _hc5[27]*_t991;
  const double _t995 = _t19*_t625 + _t19*_t626;
  const double _t996 = _t19*_t640 + _t19*_t641;
  const double _t997 = _t19*_t644 + _t545*_t621;
  const double _t998 = (0.40e2 / 0.9e1)*_hc5[8]*ta/xc_powr(na, 16, 3) + _t19*_t636 - _t194 + _t201 - _t472*(-_hc5[24]*_t991 + _hc5[33]*_t19*_t60 - _t189 - _t993) - _t52*(_hc5[35]*_t19*_t60 - _t195 - _t994 - _t995) - _t55*(-_hc5[43]*_t991 + _hc5[48]*_t19*_t60 - _t202 - _t996) + _t60*(-_hc5[33]*_t991 + _hc5[38]*_t19*_t60 - _t186 - _t992) + _t997;
  const double _t999 = my_piecewise3(_t24, 0, _t998);
  const double _t1000 = _t159*_t182;
  const double _t1001 = _t475*_t69;
  const double _t1002 = 0.87039999999999995*_t159;
  const double _t1003 = _t159*_t207;
  const double _t1005 = _t21*_t792 + _t21*_t793;
  const double _t1006 = _hc5[12]*_t21;
  const double _t1007 = _hc5[23]*_t21;
  const double _t1008 = _t21*_t799;
  const double _t1009 = _t21*_t798;
  const double _t1010 = _t1008 + _t1009;
  const double _t1011 = _hc5[26]*_t1004;
  const double _t1012 = _t21*_t803 + _t21*_t804;
  const double _t1013 = _t21*_t807 + _t21*_t808;
  const double _t1014 = _t21*_t826 + _t554*_t621;
  const double _t1015 = _t1006*_t165 + _t1014 + _t471*_t618 - _t472*(_hc5[32]*_t21*_t60 - _t1007*_t472 - _t1010) - _t52*(_hc5[34]*_t21*_t60 - _t1011 - _t1012) - _t55*(-_hc5[42]*_t1004 + _hc5[47]*_t21*_t60 - _t1013) + _t60*(-_hc5[32]*_t1004 + _hc5[37]*_t21*_t60 - _t1005);
  const double _t1016 = my_piecewise3(_t24, 0, _t1015);
  const double _t1018 = _t483*_t69;
  const double _t1019 = _t124*_t464;
  const double _t1020 = _t154*_t263;
  const double _t1021 = _t154*_t277;
  const double _t1022 = _hc5[38]*_t118*_t19 - _t19*_t729 - _t992;
  const double _t1023 = _t19*_t733;
  const double _t1024 = -_t52*(_hc5[35]*_t118*_t19 - _t1023 - _t995) - _t55*(_hc5[48]*_t118*_t19 - _t19*_t735 - _t996) + _t997;
  const double _t1025 = _t1022*_t60 + _t1024 + _t19*_t731 - _t269 - _t472*(_hc5[33]*_t118*_t19 - _t19*_t732 - _t993);
  const double _t1026 = my_piecewise3(_t24, 0, _t1025);
  const double _t1027 = _t124*_t475;
  const double _t1028 = _t494*_t69;
  const double _t1029 = _t159*_t263;
  const double _t1030 = _t159*_t277;
  const double _t1032 = -_hc5[31]*_t1031 + _hc5[37]*_t118*_t21 - _t1005 - _t264;
  const double _t1033 = _hc5[25]*_t1031;
  const double _t1034 = _t1014 - _t52*(_hc5[34]*_t118*_t21 - _t1012 - _t1033 - _t270) - _t55*(-_hc5[41]*_t1031 + _hc5[47]*_t118*_t21 - _t1013 - _t273);
  const double _t1035 = _t1006*_t164 + _t1032*_t60 + _t1034 - _t472*(-_hc5[22]*_t1031 + _hc5[32]*_t118*_t21 - _t1010 - _t266);
  const double _t1036 = my_piecewise3(_t24, 0, _t1035);
  const double _t1037 = _t154*_t307;
  const double _t1038 = _t124*_t483;
  const double _t1039 = _t154*_t317;
  const double _t1040 = _hc5[22]*_t19;
  const double _t1041 = _t1022*_t118 + _t1024 + _t19*_t797 + _t19*_t800 - _t728*(_hc5[32]*_t118*_t19 - _t1040*_t728 - _t19*_t798 - _t19*_t799);
  const double _t1042 = my_piecewise3(_t24, 0, _t1041);
  const double _t1043 = _t159*_t307;
  const double _t1044 = _t124*_t494;
  const double _t1045 = _t159*_t317;
  const double _t1046 = (0.40e2 / 0.9e1)*_hc5[6]*tb/xc_powr(nb, 16, 3) + _t1032*_t118 + _t1034 + _t21*_t827 - _t312 + _t315 - _t728*(-_hc5[21]*_t1031 + _hc5[31]*_t118*_t21 - _t21*_t828 - _t21*_t829 - _t308);
  const double _t1047 = my_piecewise3(_t24, 0, _t1046);
  const double _t1049 = -_hc0[14]*_t1048 + (0.1e1 / 0.4e1)*_hc0[36]*_t242*_t501;
  const double _t1050 = _t1049*_t60;
  const double _t1051 = _t500*_t69;
  const double _t1052 = _t508*_t69;
  const double _t1053 = 1.7407999999999999*_t143;
  const double _t1054 = _t143*_t353;
  const double _t1055 = _hc5[14]*_t60;
  const double _t1057 = _hc5[29]*_t839;
  const double _t1060 = _hc5[30]*_t1059;
  const double _t1062 = _hc5[46]*_t1061;
  const double _t1063 = _t1062*_t5;
  const double _t1064 = (0.1e1 / 0.3e1)*_hc5[11]*_t1058 - 0.1e1 / 0.24e2*_hc5[18]*_t242*_t3*_t4*_t504 - 0.1e1 / 0.3e1*_hc5[3]*_t50*_t504 + (0.1e1 / 0.3e1)*_t1060 + (0.1e1 / 0.24e2)*_t1063;
  const double _t1065 = (0.5e1 / 0.12e2)*_hc5[10]*_t11*_t504*_t62*ta + (0.1e1 / 0.4e1)*_hc5[36]*_t242*_t501*_t60 - _t1048*_t1055 - _t1056*_t1057 - _t1064;
  const double _t1066 = my_piecewise3(_t24, 0, _t1065);
  const double _t1068 = _t139*_t881;
  const double _t1069 = _t501*_t870;
  const double _t1070 = _t1069*_t881;
  const double _t1071 = _t139*_t882;
  const double _t1072 = _t1069*_t882;
  const double _t1073 = _t60*_t939;
  const double _t1074 = _t1069*_t1073;
  const double _t1075 = _t1073*_t139;
  const double _t1076 = _hc0[3]*_t504;
  const double _t1077 = (0.1e1 / 0.3e1)*_t1076*_t50;
  const double _t1078 = _t337*_t501;
  const double _t1079 = -_hc0[11]*_t1048 + (0.1e1 / 0.4e1)*_hc0[30]*_t242*_t501;
  const double _t1080 = _t1079*_t52;
  const double _t1081 = _t55*(-_hc0[18]*_t1048 + (0.1e1 / 0.4e1)*_hc0[46]*_t242*_t501);
  const double _t1082 = _hc2[6]/(M_PI * M_PI);
  const double _t1083 = _t1059*_t1082;
  const double _t1084 = _t1058*_t377;
  const double _t1085 = _hc2[7]*_t1061*_t15*_t35/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t1086 = _t101*_t37;
  const double _t1087 = _t377*_t388*_t501/xc_powr(_t1, 17, 3);
  const double _t1088 = _t388*_t504;
  const double _t1089 = _t1088*_t710;
  const double _t1090 = -_t1077 + _t1078 + _t1080 + _t1081 + _t1086*((0.1e1 / 0.18e2)*_hc2[1]*_t15*_t16*_t50*_t504 + (0.1e1 / 0.48e2)*_hc2[4]*_t242*_t35*_t378*_t504 - 0.1e1 / 0.72e2*_t1083 - 0.1e1 / 0.36e2*_t1084 - 0.1e1 / 0.288e3*_t1085) - 0.1e1 / 0.6e1*_t1087 + (0.1e1 / 0.3e1)*_t1089;
  const double _t1092 = -_t1078;
  const double _t1093 = _t1077 - _t1080 - _t1081 + _t1092;
  const double _t1096 = -_hc0[14]*_t1095 + (0.1e1 / 0.2e1)*_hc0[36]*_t242*_t501;
  const double _t1097 = _t1096*_t60;
  const double _t1098 = _t395*_t501;
  const double _t1099 = -_hc0[11]*_t1095 + (0.1e1 / 0.2e1)*_hc0[30]*_t242*_t501;
  const double _t1100 = _t1099*_t52;
  const double _t1101 = _t55*(-_hc0[18]*_t1095 + (0.1e1 / 0.2e1)*_hc0[46]*_t242*_t501);
  const double _t1102 = _t1076*_t338;
  const double _t1103 = _t1086*((0.1e1 / 0.9e1)*_hc2[1]*_t15*_t16*_t50*_t504 + (0.1e1 / 0.24e2)*_hc2[4]*_t242*_t35*_t378*_t504 - 0.1e1 / 0.36e2*_t1083 - 0.1e1 / 0.18e2*_t1084 - 0.1e1 / 0.144e3*_t1085) - 0.1e1 / 0.3e1*_t1087 + (0.2e1 / 0.3e1)*_t1089 - _t1102;
  const double _t1104 = _t1098 + _t1100 + _t1101 + _t1103;
  const double _t1105 = _t1068*_t529;
  const double _t1106 = _t1071*_t529;
  const double _t1107 = _t139*_t529;
  const double _t1108 = _t370*_t859;
  const double _t1109 = _t1108*_t60;
  const double _t1110 = (0.1e1 / 0.6e1)*_t1070 + (0.1e1 / 0.6e1)*_t1072 - 0.1e1 / 0.6e1*_t1074 - 0.1e1 / 0.3e1*_t1105 - 0.1e1 / 0.3e1*_t1106 + _t1107*_t1109;
  const double _t1111 = -_t1098;
  const double _t1112 = -_t1100 - _t1101 + _t1102 + _t1111;
  const double _t1113 = _t523*_t69;
  const double _t1114 = _t149*_t346;
  const double _t1115 = _t143*_t407;
  const double _t1116 = _t149*_t353;
  const double _t1118 = -0.1e1 / 0.12e2*_hc5[18]*_t242*_t3*_t4*_t504 - 0.2e1 / 0.3e1*_hc5[3]*_t50*_t504 + (0.2e1 / 0.3e1)*_t1060 + _t1062*_t342 + _t349*_t501;
  const double _t1119 = (0.5e1 / 0.6e1)*_hc5[10]*_t11*_t504*_t62*ta + (0.1e1 / 0.2e1)*_hc5[36]*_t242*_t501*_t60 - _t1055*_t1095 - _t1057*_t1117 - _t1118;
  const double _t1120 = my_piecewise3(_t24, 0, _t1119);
  const double _t1121 = _t144*_t150;
  const double _t1123 = _t535*_t69;
  const double _t1124 = _t537*_t69;
  const double _t1125 = 1.7407999999999999*_t149;
  const double _t1126 = _t149*_t407;
  const double _t1127 = -0.1e1 / 0.6e1*_hc5[18]*_t242*_t3*_t4*_t504 - 0.4e1 / 0.3e1*_hc5[3]*_t50*_t504 + (0.4e1 / 0.3e1)*_t1060 + (0.1e1 / 0.6e1)*_t1063 + _t403*_t501;
  const double _t1128 = (0.5e1 / 0.3e1)*_hc5[10]*_t11*_t504*_t62*ta + _hc5[36]*_t242*_t501*_t60 - _t1055*_t505 - _t1127 - _t502*_t629;
  const double _t1129 = my_piecewise3(_t24, 0, _t1128);
  const double _t1131 = _t359*_t505;
  const double _t1132 = _hc0[36]*_t60;
  const double _t1133 = _t1132*_t502;
  const double _t1134 = _t1076*_t51;
  const double _t1135 = _hc0[30]*_t1059;
  const double _t1136 = (0.4e1 / 0.3e1)*_t1135;
  const double _t1138 = (0.1e1 / 0.6e1)*_t1137*_t398;
  const double _t1139 = _hc0[46]*_t1061;
  const double _t1140 = (0.1e1 / 0.6e1)*_t1139*_t5;
  const double _t1141 = _t1086*((0.2e1 / 0.9e1)*_hc2[1]*_t15*_t16*_t50*_t504 + (0.1e1 / 0.12e2)*_hc2[4]*_t242*_t35*_t378*_t504 - 0.1e1 / 0.18e2*_t1083 - 0.1e1 / 0.9e1*_t1084 - 0.1e1 / 0.72e2*_t1085) - 0.2e1 / 0.3e1*_t1087 + (0.4e1 / 0.3e1)*_t1089 + _t1098 - _t1134 + _t1136 - _t1138 + _t1140;
  const double _t1143 = _t1111 + _t1134 - _t1136 + _t1138 - _t1140;
  const double _t1144 = _t1095*_t359;
  const double _t1146 = _t1132*_t1145;
  const double _t1147 = (0.2e1 / 0.3e1)*_t1135;
  const double _t1148 = _hc0[18]*_t1137*_t342;
  const double _t1149 = _t1139*_t342;
  const double _t1150 = _t1078 + _t1103 + _t1147 - _t1148 + _t1149;
  const double _t1151 = _t1092 + _t1102 - _t1147 + _t1148 - _t1149;
  const double _t1152 = 9.2141136272939992*_t124;
  const double _t1153 = _t124*_t500;
  const double _t1154 = _t124*_t508;
  const double _t1155 = _t143*_t426;
  const double _t1156 = _hc5[14]*_t118;
  const double _t1157 = _hc5[28]*_t120*tb;
  const double _t1158 = (0.1e1 / 0.4e1)*_hc5[36]*_t118*_t242*_t501 + (0.5e1 / 0.12e2)*_hc5[9]*_t11*_t120*_t504*tb - _t1048*_t1156 - _t1056*_t1157 - _t1064;
  const double _t1159 = my_piecewise3(_t24, 0, _t1158);
  const double _t1161 = _t1049*_t118;
  const double _t1162 = _t139*_t933;
  const double _t1163 = _t1069*_t933;
  const double _t1164 = _t139*_t934;
  const double _t1165 = _t1069*_t934;
  const double _t1166 = _t118*_t939;
  const double _t1167 = _t1069*_t1166;
  const double _t1169 = _t1096*_t118;
  const double _t1170 = _t1162*_t529;
  const double _t1171 = _t1164*_t529;
  const double _t1172 = _t1108*_t118;
  const double _t1173 = _t1107*_t1172 + (0.1e1 / 0.6e1)*_t1163 + (0.1e1 / 0.6e1)*_t1165 - 0.1e1 / 0.6e1*_t1167 - 0.1e1 / 0.3e1*_t1170 - 0.1e1 / 0.3e1*_t1171;
  const double _t1174 = _t124*_t523;
  const double _t1175 = _t149*_t422;
  const double _t1176 = _t143*_t449;
  const double _t1177 = _t149*_t426;
  const double _t1178 = (0.1e1 / 0.2e1)*_hc5[36]*_t118*_t242*_t501 + (0.5e1 / 0.6e1)*_hc5[9]*_t11*_t120*_t504*tb - _t1095*_t1156 - _t1117*_t1157 - _t1118;
  const double _t1179 = my_piecewise3(_t24, 0, _t1178);
  const double _t1181 = _t124*_t535;
  const double _t1182 = _t124*_t537;
  const double _t1183 = _t149*_t449;
  const double _t1184 = _hc5[36]*_t118*_t242*_t501 + (0.5e1 / 0.3e1)*_hc5[9]*_t11*_t120*_t504*tb - _t1127 - _t1156*_t505 - _t502*_t744;
  const double _t1185 = my_piecewise3(_t24, 0, _t1184);
  const double _t1186 = _t433*_t505;
  const double _t1187 = _hc0[36]*_t118;
  const double _t1188 = _t1187*_t502;
  const double _t1189 = _t1095*_t433;
  const double _t1190 = _t1145*_t1187;
  const double _t1191 = _t548*_t69;
  const double _t1192 = _t143*_t464;
  const double _t1193 = _t154*_t346;
  const double _t1194 = _t154*_t353;
  const double _t1195 = _t19*_t843 + _t19*_t844 + _t545*_t841;
  const double _t1196 = -_hc5[27]*_t347*_t459*ta + (0.1e1 / 0.2e1)*_hc5[35]*_t11*_t135*_t19*_t60 - _t1195 - _t348;
  const double _t1197 = my_piecewise3(_t24, 0, _t1196);
  const double _t1200 = _t557*_t69;
  const double _t1201 = _t143*_t475;
  const double _t1202 = _t159*_t346;
  const double _t1203 = _hc5[26]*_t21;
  const double _t1204 = _t21*_t965 + _t21*_t966 + _t554*_t841;
  const double _t1205 = (0.1e1 / 0.2e1)*_hc5[34]*_t11*_t135*_t21*_t60 - _t1203*_t840 - _t1204;
  const double _t1206 = my_piecewise3(_t24, 0, _t1205);
  const double _t1207 = _t159*_t353;
  const double _t1209 = _t563*_t69;
  const double _t1210 = _t149*_t464;
  const double _t1211 = _t154*_t402;
  const double _t1212 = _t154*_t407;
  const double _t1213 = _t19*_t892 + _t19*_t893 + _t545*_t889;
  const double _t1214 = _hc5[35]*_t11*_t135*_t19*_t60 - _t1213 - _t136*_t195 - _t136*_t994;
  const double _t1215 = my_piecewise3(_t24, 0, _t1214);
  const double _t1217 = _t570*_t69;
  const double _t1218 = _t149*_t475;
  const double _t1219 = _t159*_t402;
  const double _t1220 = _t21*_t983 + _t21*_t984 + _t554*_t889;
  const double _t1221 = _hc5[34]*_t11*_t135*_t21*_t60 - _t1011*_t136 - _t1220;
  const double _t1222 = my_piecewise3(_t24, 0, _t1221);
  const double _t1223 = _t159*_t407;
  const double _t1224 = _t124*_t548;
  const double _t1225 = _t143*_t483;
  const double _t1226 = _t154*_t422;
  const double _t1227 = (0.1e1 / 0.2e1)*_hc5[35]*_t11*_t118*_t135*_t19 - _t1195 - _t19*_t924;
  const double _t1228 = my_piecewise3(_t24, 0, _t1227);
  const double _t1229 = _t154*_t426;
  const double _t1232 = _t124*_t557;
  const double _t1233 = _t143*_t494;
  const double _t1234 = _t159*_t422;
  const double _t1235 = _t159*_t426;
  const double _t1236 = -_hc5[25]*_t347*_t490*tb + (0.1e1 / 0.2e1)*_hc5[34]*_t11*_t118*_t135*_t21 - _t1204 - _t424;
  const double _t1237 = my_piecewise3(_t24, 0, _t1236);
  const double _t1239 = _t124*_t563;
  const double _t1240 = _t149*_t483;
  const double _t1241 = _t154*_t447;
  const double _t1242 = _hc5[35]*_t11*_t118*_t135*_t19 - _t1023*_t136 - _t1213;
  const double _t1243 = my_piecewise3(_t24, 0, _t1242);
  const double _t1244 = _t154*_t449;
  const double _t1246 = _t124*_t570;
  const double _t1247 = _t149*_t494;
  const double _t1248 = _t159*_t447;
  const double _t1249 = _t159*_t449;
  const double _t1250 = _hc5[34]*_t11*_t118*_t135*_t21 - _t1033*_t136 - _t1220 - _t136*_t270;
  const double _t1251 = my_piecewise3(_t24, 0, _t1250);
  const double _t1252 = _t575*_t637 + _t575*_t638;
  const double _t1253 = -_hc5[24]*_t461/xc_powi(na, 6) + _hc5[33]*_t575*_t60 - _t1252 - 0.10e2 / 0.3e1*_t460;
  const double _t1254 = my_piecewise3(_t24, 0, _t1253);
  const double _t1255 = _t577*_t69;
  const double _t1256 = _t578*_t69;
  const double _t1257 = 1.7407999999999999*_t154;
  const double _t1258 = _t154*_t464;
  const double _t1260 = _t584*_t69;
  const double _t1261 = _t1008*_t19 + _t1009*_t19;
  const double _t1262 = _hc5[32]*_t19*_t21*_t60 - _t1007*_t991 - _t1261 - _t471*_t63;
  const double _t1263 = my_piecewise3(_t24, 0, _t1262);
  const double _t1264 = _t154*_t475;
  const double _t1265 = _t159*_t464;
  const double _t1266 = _t159*_t465;
  const double _t1267 = _t155*_t160;
  const double _t1268 = _t591*_t828 + _t591*_t829;
  const double _t1269 = -_hc5[22]*_t472*_t591 + _hc5[31]*_t591*_t60 - _t1268;
  const double _t1270 = my_piecewise3(_t24, 0, _t1269);
  const double _t1271 = _t593*_t69;
  const double _t1272 = 1.7407999999999999*_t159;
  const double _t1273 = _t594*_t69;
  const double _t1274 = _t159*_t475;
  const double _t1276 = _hc5[33]*_t118*_t575 - _t1252 - _t575*_t732;
  const double _t1277 = my_piecewise3(_t24, 0, _t1276);
  const double _t1278 = _t124*_t577;
  const double _t1279 = _t124*_t578;
  const double _t1280 = _t154*_t483;
  const double _t1281 = _t124*_t584;
  const double _t1282 = _hc5[32]*_t118*_t19*_t21 - _t1031*_t1040 - _t1261 - _t19*_t266;
  const double _t1283 = my_piecewise3(_t24, 0, _t1282);
  const double _t1284 = _t159*_t483;
  const double _t1285 = _t154*_t494;
  const double _t1286 = _t159*_t484;
  const double _t1287 = -_hc5[21]*_t492/xc_powi(nb, 6) + _hc5[31]*_t118*_t591 - _t1268 - 0.10e2 / 0.3e1*_t491;
  const double _t1288 = my_piecewise3(_t24, 0, _t1287);
  const double _t1289 = _t124*_t593;
  const double _t1290 = _t124*_t594;
  const double _t1291 = _t159*_t494;
  const double _t1294 = _hc0[11]*_t1293;
  const double _t1295 = (0.1e1 / 0.4e1)*_t1294;
  const double _t1299 = _hc0[3]*_t1298;
  const double _t1300 = _t1079*_t136;
  const double _t1301 = (0.1e1 / 0.2e1)*_t1300;
  const double _t1302 = _t1082*_t1088*_t41;
  const double _t1303 = _t1292*_t388*_t870;
  const double _t1304 = _t109*_t1296;
  const double _t1305 = _t1304*_t514;
  const double _t1306 = (_t143 * _t143 * _t143);
  const double _t1307 = _hc5[11]*_t1293;
  const double _t1309 = _hc5[30]*_t1308;
  const double _t1310 = _hc5[3]*_t1298 - 0.3e1 / 0.8e1*_t1307 + (0.1e1 / 0.8e1)*_t1309;
  const double _t1311 = my_piecewise3(_t24, 0, _t1310);
  const double _t1312 = _t143*_t508;
  const double _t1315 = _t1099*_t1314;
  const double _t1316 = (0.1e1 / 0.2e1)*_t1294;
  const double _t1318 = _hc0[3]*_t1317;
  const double _t1319 = (0.1e1 / 0.24e2)*_t1302 - 0.1e1 / 0.4e1*_t1303 + (0.1e1 / 0.2e1)*_t1305 - _t1318;
  const double _t1320 = _t1316 + _t1319;
  const double _t1321 = 9.2141136272939992*_t500;
  const double _t1322 = _hc5[3]*_t1317 - 0.3e1 / 0.4e1*_t1307 + (0.1e1 / 0.4e1)*_t1309;
  const double _t1323 = my_piecewise3(_t24, 0, _t1322);
  const double _t1324 = _t149*_t500;
  const double _t1325 = _t149*_t508;
  const double _t1326 = _t143*_t523;
  const double _t1330 = (0.3e1 / 0.2e1)*_t1294;
  const double _t1332 = _hc0[3]*_t1331;
  const double _t1333 = _hc0[30]*_t1308;
  const double _t1334 = (0.1e1 / 0.2e1)*_t1333;
  const double _t1335 = 9.2141136272939992*_t535;
  const double _t1336 = _hc5[3]*_t1331 - 0.3e1 / 0.2e1*_t1307 + (0.1e1 / 0.2e1)*_t1309;
  const double _t1337 = my_piecewise3(_t24, 0, _t1336);
  const double _t1338 = _t143*_t535;
  const double _t1339 = _t143*_t537;
  const double _t1340 = _t149*_t523;
  const double _t1343 = (0.1e1 / 0.4e1)*_t1333;
  const double _t1344 = (0.3e1 / 0.4e1)*_t1294;
  const double _t1345 = 0.3e1*_t1294;
  const double _t1347 = _hc0[3]*_t1346;
  const double _t1348 = (_t149 * _t149 * _t149);
  const double _t1349 = _hc5[3]*_t1346 - 0.3e1*_t1307 + _t1309;
  const double _t1350 = my_piecewise3(_t24, 0, _t1349);
  const double _t1351 = _t149*_t537;
  const double _t1352 = (0.1e1 / 0.4e1)*_hc5[29]*_t19*_t242*_t501 - _t1048*_t545;
  const double _t1353 = my_piecewise3(_t24, 0, _t1352);
  const double _t1354 = _t154*_t500;
  const double _t1355 = _t143*_t548;
  const double _t1356 = _t154*_t508;
  const double _t1358 = _hc5[28]*_t21;
  const double _t1359 = -_t1048*_t554 + (0.1e1 / 0.4e1)*_t1358*_t502;
  const double _t1360 = my_piecewise3(_t24, 0, _t1359);
  const double _t1361 = _t159*_t500;
  const double _t1362 = _t143*_t557;
  const double _t1363 = _t159*_t508;
  const double _t1365 = (0.1e1 / 0.2e1)*_hc5[29]*_t19*_t242*_t501 - _t1095*_t545;
  const double _t1366 = my_piecewise3(_t24, 0, _t1365);
  const double _t1367 = _t143*_t563;
  const double _t1368 = _t149*_t548;
  const double _t1369 = 9.2141136272939992*_t143;
  const double _t1370 = _t154*_t523;
  const double _t1371 = _t154*_t525;
  const double _t1375 = -_t1095*_t554 + _t1145*_t1358;
  const double _t1376 = my_piecewise3(_t24, 0, _t1375);
  const double _t1377 = _t143*_t570;
  const double _t1378 = _t149*_t557;
  const double _t1379 = _t159*_t523;
  const double _t1380 = _t159*_t525;
  const double _t1382 = _hc5[29]*_t19*_t242*_t501 - _t505*_t545;
  const double _t1383 = my_piecewise3(_t24, 0, _t1382);
  const double _t1384 = _t154*_t535;
  const double _t1385 = _t149*_t563;
  const double _t1386 = _t154*_t537;
  const double _t1387 = _t1358*_t502 - _t505*_t554;
  const double _t1388 = my_piecewise3(_t24, 0, _t1387);
  const double _t1389 = _t159*_t535;
  const double _t1390 = _t149*_t570;
  const double _t1391 = _t159*_t537;
  const double _t1392 = _hc5[27]*_t575;
  const double _t1393 = _t1314*_t1392;
  const double _t1394 = my_piecewise3(_t24, 0, _t1393);
  const double _t1395 = _t143*_t577;
  const double _t1396 = _t154*_t548;
  const double _t1397 = _t143*_t578;
  const double _t1399 = _t1203*_t19;
  const double _t1400 = _t1314*_t1399;
  const double _t1401 = my_piecewise3(_t24, 0, _t1400);
  const double _t1402 = _t159*_t548;
  const double _t1403 = _t154*_t557;
  const double _t1404 = _t143*_t584;
  const double _t1405 = _t159*_t549;
  const double _t1407 = _hc5[25]*_t591;
  const double _t1408 = _t1314*_t1407;
  const double _t1409 = my_piecewise3(_t24, 0, _t1408);
  const double _t1410 = _t143*_t593;
  const double _t1411 = _t159*_t557;
  const double _t1412 = _t143*_t594;
  const double _t1414 = _t136*_t1392;
  const double _t1415 = my_piecewise3(_t24, 0, _t1414);
  const double _t1416 = 9.2141136272939992*_t149;
  const double _t1417 = _t149*_t577;
  const double _t1418 = _t154*_t563;
  const double _t1419 = _t149*_t578;
  const double _t1421 = _t136*_t1399;
  const double _t1422 = my_piecewise3(_t24, 0, _t1421);
  const double _t1423 = _t159*_t563;
  const double _t1424 = _t154*_t570;
  const double _t1425 = _t149*_t584;
  const double _t1426 = _t159*_t565;
  const double _t1427 = _t136*_t1407;
  const double _t1428 = my_piecewise3(_t24, 0, _t1427);
  const double _t1429 = _t149*_t593;
  const double _t1430 = _t159*_t570;
  const double _t1431 = _t149*_t594;
  const double _t1432 = _hc5[24]/xc_powi(na, 5);
  const double _t1433 = my_piecewise3(_t24, 0, _t1432);
  const double _t1434 = (_t154 * _t154 * _t154);
  const double _t1435 = _t154*_t577;
  const double _t1436 = _t1*_t48;
  const double _t1437 = _t1007*_t575;
  const double _t1438 = my_piecewise3(_t24, 0, _t1437);
  const double _t1439 = _t159*_t578;
  const double _t1440 = _t159*_t577;
  const double _t1441 = _t154*_t584;
  const double _t1442 = _t1040*_t591;
  const double _t1443 = my_piecewise3(_t24, 0, _t1442);
  const double _t1444 = _t154*_t594;
  const double _t1445 = _t154*_t593;
  const double _t1446 = _t159*_t584;
  const double _t1447 = _hc5[21]/xc_powi(nb, 5);
  const double _t1448 = my_piecewise3(_t24, 0, _t1447);
  const double _t1449 = (_t159 * _t159 * _t159);
  const double _t1450 = _t159*_t593;
  const double _t750 = _hc6[3]*_t208;
  const double _t787 = _hc0[4]*_t690 + 0.2e1*_t281 + 0.2e1*_t282 + 0.2e1*_t283 + 0.2e1*_t298 + 0.2e1*_t304;
  const double _t813 = _hc6[3]*_t318;
  const double _t856 = 0.2e1*_t278;
  const double _t884 = 0.2e1*_t75;
  const double _t885 = _t1*(_t140*_t210 + _t145*_t254 + _t32*((0.1e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t225*_t37*na*nb + (0.2e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t37*_t98*nb + 0.8e1*_t34*_t37*_t382*_t47*nb + 0.8e1*_t34*_t37*_t382*_t98*na*nb - _t783*_t857 - 0.2e1 / 0.3e1*_t858 - _t859*_t860 - _t859*_t862 - 0.2e1 / 0.3e1*_t863 - _t869 - _t880 - _t883) + _t355*_t785 + _t390*_t884 + _t48*my_piecewise3(_t25, 73.477446052200008*_t143*_t182*_t26 + 62.026136204639997*_t143*_t182*_t28 + 36.738723026100004*_t143*_t207*_t27 + 15.506534051159999*_t143*_t207*_t29 - _t143*_t719 - _t183*_t838 - _t184*_t838 - _t185*_t838 - _t207*_t524 + 73.477446052200008*_t27*_t353*_t69 + 12.2462410087*_t28*_t855 + 31.013068102319998*_t29*_t353*_t69 + 3.1013068102319998*_t30*_t855 - _t353*_t836 - _t600*_t835 - _t601*_t835 - _t70*_t855 - _t71*_t855 - _t72*_t855 - _t723*_t837 - _t724*_t837 - _t725*_t837 - _t73*_t855 - 0.64000000000000001*_t855, _hc6[1]*my_piecewise3(_t24, _t854, 0) + _t144*_t750 + _t209*_t527 + _t354*_t856) + _t869) + 0.2e1*_t356 + 0.2e1*_t357 + 0.2e1*_t358 + 0.2e1*_t391 + _t401;
  const double _t930 = _hc6[3]*_t74;
  const double _t931 = _t125*_t930;
  const double _t947 = _t1*(_t115*_t429 + _t126*_t390 + _t132*_t355 + _t140*_t280 + _t145*_t303 + _t32*((0.2e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t118*_t135*_t15*_t16*_t36*_t384*_t47*na*nb + (0.2e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t135*_t15*_t16*_t36*_t384*_t47*_t60*na*nb + (0.1e1 / 0.3e1)*_hc2[1]*_t129*_t135*_t139*_t15*_t16*_t37*nb + (0.1e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t285*_t37*na*nb + (0.1e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t37*_t47 + (0.1e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t37*_t98*na - _t118*_t932 + 0.4e1*_t129*_t34*_t37*_t382*na*nb + 0.4e1*_t34*_t37*_t382*_t47*na + 0.4e1*_t34*_t37*_t382*_t47*nb + 0.4e1*_t34*_t37*_t382*_t98*na*nb - _t387*_t882 - _t387*_t933 - _t387*_t934 - _t60*_t932 - _t859*_t942 - _t880 - 0.2e1 / 0.3e1*_t903 - 0.1e1 / 0.3e1*_t935 - 0.1e1 / 0.3e1*_t936 - 0.1e1 / 0.3e1*_t937 - 0.1e1 / 0.3e1*_t938 - _t940*_t941 - _t946) + _t442*_t75 + _t48*my_piecewise3(_t25, 73.477446052200008*_t124*_t143*_t26*_t69 + 62.026136204639997*_t124*_t143*_t28*_t69 + 36.738723026100004*_t124*_t27*_t353 + 15.506534051159999*_t124*_t29*_t353 + 36.738723026100004*_t143*_t27*_t277 + 15.506534051159999*_t143*_t277*_t29 - _t183*_t919 - _t183*_t920 - _t183*_t921 - _t184*_t919 - _t184*_t920 - _t184*_t921 - _t185*_t919 - _t185*_t920 - _t185*_t921 - _t262*_t426 + 36.738723026100004*_t27*_t426*_t69 - _t277*_t524 + 12.2462410087*_t28*_t929 + 15.506534051159999*_t29*_t426*_t69 + 3.1013068102319998*_t30*_t929 - _t353*_t421 - _t422*_t917 - _t600*_t918 - _t601*_t918 - _t70*_t929 - _t71*_t929 - _t72*_t929 - _t73*_t929 - 0.64000000000000001*_t929, _hc6[1]*my_piecewise3(_t24, _t928, 0) + _t144*_t931 + _t278*_t428 + _t279*_t527 + _t354*_t427) + _t946) + _t392 + _t400 + _t444;
  const double _t970 = 0.2e1*_t427;
  const double _t978 = 0.2e1*_t126;
  const double _t979 = _t1*(_t140*_t320 + _t145*_t331 + _t32*((0.2e1 / 0.3e1)*_hc2[1]*_t129*_t135*_t139*_t15*_t16*_t37*na + (0.1e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t323*_t37*na*nb + 0.8e1*_t129*_t34*_t37*_t382*na*nb + 0.8e1*_t34*_t37*_t382*_t47*na - _t857*_t971 - _t859*_t973 - _t859*_t974 - _t880 - _t960 - 0.2e1 / 0.3e1*_t972 - 0.2e1 / 0.3e1*_t975 - _t977) + _t333*_t429 + _t442*_t978 + _t48*my_piecewise3(_t25, 73.477446052200008*_t124*_t27*_t426 + 31.013068102319998*_t124*_t29*_t426 + 73.477446052200008*_t143*_t26*_t307 + 36.738723026100004*_t143*_t27*_t317 + 62.026136204639997*_t143*_t28*_t307 + 15.506534051159999*_t143*_t29*_t317 - _t143*_t788 - _t183*_t964 - _t184*_t964 - _t185*_t964 + 12.2462410087*_t28*_t969 + 3.1013068102319998*_t30*_t969 - _t317*_t524 - _t426*_t962 - _t600*_t961 - _t601*_t961 - _t70*_t969 - _t71*_t969 - _t72*_t969 - _t723*_t963 - _t724*_t963 - _t725*_t963 - _t73*_t969 - 0.64000000000000001*_t969, _hc6[1]*my_piecewise3(_t24, _t968, 0) + _t144*_t813 + _t319*_t527 + _t428*_t970) + _t977) + 0.2e1*_t430 + 0.2e1*_t431 + 0.2e1*_t432 + 0.2e1*_t443 + _t446;
  const double _t1017 = _hc6[2]*_t160;
  const double _t1067 = 0.2e1*_t527;
  const double _t1091 = 0.2e1*_t145;
  const double _t1094 = _t1*(_t1050 + _t1091*_t390 + _t1093 + _t115*_t511 + _t32*(-_t1050 - _t1068*_t513 + (0.1e1 / 0.12e2)*_t1070 - _t1071*_t513 + (0.1e1 / 0.12e2)*_t1072 - 0.1e1 / 0.12e2*_t1074 + _t1075*_t513 + _t1090) + _t355*_t519 + _t48*my_piecewise3(_t25, -_t1051*_t600 - _t1051*_t601 - _t1052*_t183 - _t1052*_t184 - _t1052*_t185 - _t1053*_t353 - _t1054*_t723 - _t1054*_t724 - _t1054*_t725 + 12.2462410087*_t1066*_t28 + 3.1013068102319998*_t1066*_t30 - _t1066*_t70 - _t1066*_t71 - _t1066*_t72 - _t1066*_t73 - 0.64000000000000001*_t1066 + 73.477446052200008*_t143*_t27*_t353 + 31.013068102319998*_t143*_t29*_t353 + 73.477446052200008*_t26*_t500*_t69 - _t262*_t508 + 36.738723026100004*_t27*_t508*_t69 + 62.026136204639997*_t28*_t500*_t69 + 15.506534051159999*_t29*_t508*_t69 - _t500*_t917, _hc6[1]*my_piecewise3(_t24, _t1065, 0) + _t1067*_t354 + _t278*_t510 + _t509*_t930) + _t518*_t75) + _t520;
  const double _t1122 = _t115*_t528 + _t140*_t409 + _t145*_t418 + _t148*_t355 + _t151*_t390 + _t48*my_piecewise3(_t25, -_t1113*_t183 - _t1113*_t184 - _t1113*_t185 - _t1114*_t600 - _t1114*_t601 - _t1115*_t183 - _t1115*_t184 - _t1115*_t185 - _t1116*_t183 - _t1116*_t184 - _t1116*_t185 + 12.2462410087*_t1120*_t28 + 3.1013068102319998*_t1120*_t30 - _t1120*_t70 - _t1120*_t71 - _t1120*_t72 - _t1120*_t73 - 0.64000000000000001*_t1120 + 73.477446052200008*_t143*_t149*_t26*_t69 + 62.026136204639997*_t143*_t149*_t28*_t69 + 36.738723026100004*_t143*_t27*_t407 + 15.506534051159999*_t143*_t29*_t407 + 36.738723026100004*_t149*_t27*_t353 + 15.506534051159999*_t149*_t29*_t353 - _t262*_t523 + 36.738723026100004*_t27*_t523*_t69 + 15.506534051159999*_t29*_t523*_t69 - _t353*_t564 - _t407*_t524 - _t525*_t917, _hc6[1]*my_piecewise3(_t24, _t1119, 0) + _t1121*_t930 + _t278*_t526 + _t354*_t567 + _t408*_t527) + _t532*_t75;
  const double _t1130 = 0.2e1*_t567;
  const double _t1142 = 0.2e1*_t151;
  const double _t1160 = _hc6[3]*_t125;
  const double _t1168 = _t1*(_t1091*_t442 + _t1093 + _t1161 + _t126*_t518 + _t132*_t511 + _t32*(_t1090 - _t1161 - _t1162*_t513 + (0.1e1 / 0.12e2)*_t1163 - _t1164*_t513 + (0.1e1 / 0.12e2)*_t1165 + _t1166*_t139*_t513 - 0.1e1 / 0.12e2*_t1167) + _t429*_t519 + _t48*my_piecewise3(_t25, -_t1053*_t426 - _t1152*_t500 - _t1153*_t600 - _t1153*_t601 - _t1154*_t183 - _t1154*_t184 - _t1154*_t185 - _t1155*_t723 - _t1155*_t724 - _t1155*_t725 + 12.2462410087*_t1159*_t28 + 3.1013068102319998*_t1159*_t30 - _t1159*_t70 - _t1159*_t71 - _t1159*_t72 - _t1159*_t73 - 0.64000000000000001*_t1159 + 73.477446052200008*_t124*_t26*_t500 + 36.738723026100004*_t124*_t27*_t508 + 62.026136204639997*_t124*_t28*_t500 + 15.506534051159999*_t124*_t29*_t508 + 73.477446052200008*_t143*_t27*_t426 + 31.013068102319998*_t143*_t29*_t426 - _t421*_t508, _hc6[1]*my_piecewise3(_t24, _t1158, 0) + _t1067*_t428 + _t1160*_t509 + _t427*_t510)) + _t520;
  const double _t1180 = _t126*_t532 + _t132*_t528 + _t140*_t451 + _t145*_t455 + _t148*_t429 + _t151*_t442 + _t48*my_piecewise3(_t25, -_t1152*_t525 - _t1174*_t183 - _t1174*_t184 - _t1174*_t185 - _t1175*_t600 - _t1175*_t601 - _t1176*_t183 - _t1176*_t184 - _t1176*_t185 - _t1177*_t183 - _t1177*_t184 - _t1177*_t185 + 12.2462410087*_t1179*_t28 + 3.1013068102319998*_t1179*_t30 - _t1179*_t70 - _t1179*_t71 - _t1179*_t72 - _t1179*_t73 - 0.64000000000000001*_t1179 + 73.477446052200008*_t124*_t143*_t149*_t26 + 62.026136204639997*_t124*_t143*_t149*_t28 + 36.738723026100004*_t124*_t27*_t523 + 15.506534051159999*_t124*_t29*_t523 + 36.738723026100004*_t143*_t27*_t449 + 15.506534051159999*_t143*_t29*_t449 + 36.738723026100004*_t149*_t27*_t426 + 15.506534051159999*_t149*_t29*_t426 - _t421*_t523 - _t426*_t564 - _t449*_t524, _hc6[1]*my_piecewise3(_t24, _t1178, 0) + _t1121*_t1160 + _t427*_t526 + _t428*_t567 + _t450*_t527);
  const double _t1198 = _t144*_t930;
  const double _t1199 = _t1*(_t115*_t551 + _t140*_t467 + _t156*_t390 + _t48*my_piecewise3(_t25, -_t1191*_t183 - _t1191*_t184 - _t1191*_t185 - _t1192*_t183 - _t1192*_t184 - _t1192*_t185 - _t1193*_t600 - _t1193*_t601 - _t1194*_t183 - _t1194*_t184 - _t1194*_t185 + 12.2462410087*_t1197*_t28 + 3.1013068102319998*_t1197*_t30 - _t1197*_t70 - _t1197*_t71 - _t1197*_t72 - _t1197*_t73 - 0.64000000000000001*_t1197 + 73.477446052200008*_t143*_t154*_t26*_t69 + 62.026136204639997*_t143*_t154*_t28*_t69 + 36.738723026100004*_t143*_t27*_t464 + 15.506534051159999*_t143*_t29*_t464 + 36.738723026100004*_t154*_t27*_t353 + 15.506534051159999*_t154*_t29*_t353 - _t262*_t548 + 36.738723026100004*_t27*_t548*_t69 + 15.506534051159999*_t29*_t548*_t69 - _t353*_t585 - _t464*_t524 - _t549*_t917, _hc6[1]*my_piecewise3(_t24, _t1196, 0) + _t1198*_t155 + _t278*_t550 + _t354*_t588 + _t466*_t527)) + _t552;
  const double _t1208 = _t1*(_t115*_t560 + _t140*_t478 + _t161*_t390 + _t48*my_piecewise3(_t25, -_t1002*_t353 - _t1200*_t183 - _t1200*_t184 - _t1200*_t185 - _t1201*_t183 - _t1201*_t184 - _t1201*_t185 - _t1202*_t600 - _t1202*_t601 + 12.2462410087*_t1206*_t28 + 3.1013068102319998*_t1206*_t30 - _t1206*_t70 - _t1206*_t71 - _t1206*_t72 - _t1206*_t73 - 0.64000000000000001*_t1206 - _t1207*_t183 - _t1207*_t184 - _t1207*_t185 + 73.477446052200008*_t143*_t159*_t26*_t69 + 62.026136204639997*_t143*_t159*_t28*_t69 + 36.738723026100004*_t143*_t27*_t475 + 15.506534051159999*_t143*_t29*_t475 + 36.738723026100004*_t159*_t27*_t353 + 15.506534051159999*_t159*_t29*_t353 - _t262*_t557 + 36.738723026100004*_t27*_t557*_t69 + 15.506534051159999*_t29*_t557*_t69 - _t475*_t524 - _t558*_t917, _hc6[1]*my_piecewise3(_t24, _t1205, 0) + _t1017*_t354 + _t1198*_t160 + _t278*_t559 + _t477*_t527)) + _t561;
  const double _t1216 = _t150*_t930;
  const double _t1230 = _t1160*_t144;
  const double _t1231 = _t1*(_t132*_t551 + _t140*_t486 + _t156*_t442 + _t48*my_piecewise3(_t25, -_t1152*_t549 - _t1224*_t183 - _t1224*_t184 - _t1224*_t185 - _t1225*_t183 - _t1225*_t184 - _t1225*_t185 - _t1226*_t600 - _t1226*_t601 + 12.2462410087*_t1228*_t28 + 3.1013068102319998*_t1228*_t30 - _t1228*_t70 - _t1228*_t71 - _t1228*_t72 - _t1228*_t73 - 0.64000000000000001*_t1228 - _t1229*_t183 - _t1229*_t184 - _t1229*_t185 + 73.477446052200008*_t124*_t143*_t154*_t26 + 62.026136204639997*_t124*_t143*_t154*_t28 + 36.738723026100004*_t124*_t27*_t548 + 15.506534051159999*_t124*_t29*_t548 + 36.738723026100004*_t143*_t27*_t483 + 15.506534051159999*_t143*_t29*_t483 + 36.738723026100004*_t154*_t27*_t426 + 15.506534051159999*_t154*_t29*_t426 - _t421*_t548 - _t426*_t585 - _t483*_t524, _hc6[1]*my_piecewise3(_t24, _t1227, 0) + _t1230*_t155 + _t427*_t550 + _t428*_t588 + _t485*_t527)) + _t552;
  const double _t1238 = _t1*(_t132*_t560 + _t140*_t497 + _t161*_t442 + _t48*my_piecewise3(_t25, -_t1002*_t426 - _t1152*_t558 - _t1232*_t183 - _t1232*_t184 - _t1232*_t185 - _t1233*_t183 - _t1233*_t184 - _t1233*_t185 - _t1234*_t600 - _t1234*_t601 - _t1235*_t183 - _t1235*_t184 - _t1235*_t185 + 12.2462410087*_t1237*_t28 + 3.1013068102319998*_t1237*_t30 - _t1237*_t70 - _t1237*_t71 - _t1237*_t72 - _t1237*_t73 - 0.64000000000000001*_t1237 + 73.477446052200008*_t124*_t143*_t159*_t26 + 62.026136204639997*_t124*_t143*_t159*_t28 + 36.738723026100004*_t124*_t27*_t557 + 15.506534051159999*_t124*_t29*_t557 + 36.738723026100004*_t143*_t27*_t494 + 15.506534051159999*_t143*_t29*_t494 + 36.738723026100004*_t159*_t27*_t426 + 15.506534051159999*_t159*_t29*_t426 - _t421*_t557 - _t494*_t524, _hc6[1]*my_piecewise3(_t24, _t1236, 0) + _t1017*_t428 + _t1230*_t160 + _t427*_t559 + _t496*_t527)) + _t561;
  const double _t1245 = _t1160*_t150;
  const double _t1259 = 0.2e1*_t588;
  const double _t1275 = 0.2e1*_t1017;
  const double _t1313 = _t1*(-_t1295 + _t1299 + _t1301 + 0.3e1*_t140*_t511 + 0.3e1*_t145*_t518 + _t32*(_t1295 - _t1299 - _t1301 + (0.1e1 / 0.48e2)*_t1302 - 0.1e1 / 0.8e1*_t1303 + (0.1e1 / 0.4e1)*_t1305) + _t48*my_piecewise3(_t25, 73.477446052200008*_t1306*_t26 + 62.026136204639997*_t1306*_t28 - _t1306*_t600 - _t1306*_t601 - 9.2141136272939992*_t1306 + 12.2462410087*_t1311*_t28 + 3.1013068102319998*_t1311*_t30 - _t1311*_t70 - _t1311*_t71 - _t1311*_t72 - _t1311*_t73 - 0.64000000000000001*_t1311 - _t1312*_t603 - _t1312*_t604 - _t1312*_t605 - 2.6111999999999997*_t1312 + 110.21616907830001*_t143*_t27*_t508 + 46.519602153479994*_t143*_t29*_t508, _hc6[1]*my_piecewise3(_t24, _t1310, 0) + _hc6[3]*(_t144 * _t144 * _t144) + 0.3e1*_t510*_t527));
  const double _t1327 = _hc6[3]*_t509;
  const double _t1328 = _t1091*_t532 + _t1318 + _t148*_t511 + _t151*_t518 + _t48*my_piecewise3(_t25, -_t1053*_t523 - _t1321*_t149 + 12.2462410087*_t1323*_t28 + 3.1013068102319998*_t1323*_t30 - _t1323*_t70 - _t1323*_t71 - _t1323*_t72 - _t1323*_t73 - 0.64000000000000001*_t1323 - _t1324*_t600 - _t1324*_t601 - _t1325*_t183 - _t1325*_t184 - _t1325*_t185 - _t1326*_t723 - _t1326*_t724 - _t1326*_t725 + 73.477446052200008*_t143*_t27*_t523 + 31.013068102319998*_t143*_t29*_t523 + 73.477446052200008*_t149*_t26*_t500 + 36.738723026100004*_t149*_t27*_t508 + 62.026136204639997*_t149*_t28*_t500 + 15.506534051159999*_t149*_t29*_t508 - _t508*_t564, _hc6[1]*my_piecewise3(_t24, _t1322, 0) + _t1067*_t526 + _t1327*_t150 + _t510*_t567) + _t519*_t528;
  const double _t1329 = -_t1316 + _t1328;
  const double _t1341 = _hc6[3]*_t538;
  const double _t1342 = _t1*(_t1142*_t532 - _t1330 + _t1332 + _t1334 + _t140*_t540 + _t145*_t542 + _t32*((0.1e1 / 0.12e2)*_t1302 - 0.1e1 / 0.2e1*_t1303 + _t1305 + _t1330 - _t1332 - _t1334) + _t48*my_piecewise3(_t25, -_t1125*_t523 - _t1335*_t143 + 12.2462410087*_t1337*_t28 + 3.1013068102319998*_t1337*_t30 - _t1337*_t70 - _t1337*_t71 - _t1337*_t72 - _t1337*_t73 - 0.64000000000000001*_t1337 - _t1338*_t600 - _t1338*_t601 - _t1339*_t183 - _t1339*_t184 - _t1339*_t185 - _t1340*_t723 - _t1340*_t724 - _t1340*_t725 + 73.477446052200008*_t143*_t26*_t535 + 36.738723026100004*_t143*_t27*_t537 + 62.026136204639997*_t143*_t28*_t535 + 15.506534051159999*_t143*_t29*_t537 + 73.477446052200008*_t149*_t27*_t523 + 31.013068102319998*_t149*_t29*_t523 - _t524*_t537, _hc6[1]*my_piecewise3(_t24, _t1336, 0) + _t1130*_t526 + _t1341*_t144 + _t527*_t539) + _t528*_t543);
  const double _t1357 = _t1*(_t156*_t518 + _t48*my_piecewise3(_t25, -_t1053*_t548 - _t1321*_t154 + 12.2462410087*_t1353*_t28 + 3.1013068102319998*_t1353*_t30 - _t1353*_t70 - _t1353*_t71 - _t1353*_t72 - _t1353*_t73 - 0.64000000000000001*_t1353 - _t1354*_t600 - _t1354*_t601 - _t1355*_t723 - _t1355*_t724 - _t1355*_t725 - _t1356*_t183 - _t1356*_t184 - _t1356*_t185 + 73.477446052200008*_t143*_t27*_t548 + 31.013068102319998*_t143*_t29*_t548 + 73.477446052200008*_t154*_t26*_t500 + 36.738723026100004*_t154*_t27*_t508 + 62.026136204639997*_t154*_t28*_t500 + 15.506534051159999*_t154*_t29*_t508 - _t508*_t585, _hc6[1]*my_piecewise3(_t24, _t1352, 0) + _t1067*_t550 + _t1327*_t155 + _t510*_t588) + _t519*_t551);
  const double _t1364 = _t1*(_t161*_t518 + _t48*my_piecewise3(_t25, -_t1002*_t508 - _t1053*_t557 - _t1321*_t159 + 12.2462410087*_t1360*_t28 + 3.1013068102319998*_t1360*_t30 - _t1360*_t70 - _t1360*_t71 - _t1360*_t72 - _t1360*_t73 - 0.64000000000000001*_t1360 - _t1361*_t600 - _t1361*_t601 - _t1362*_t723 - _t1362*_t724 - _t1362*_t725 - _t1363*_t183 - _t1363*_t184 - _t1363*_t185 + 73.477446052200008*_t143*_t27*_t557 + 31.013068102319998*_t143*_t29*_t557 + 73.477446052200008*_t159*_t26*_t500 + 36.738723026100004*_t159*_t27*_t508 + 62.026136204639997*_t159*_t28*_t500 + 15.506534051159999*_t159*_t29*_t508, _hc6[1]*my_piecewise3(_t24, _t1359, 0) + _t1017*_t510 + _t1067*_t559 + _t1327*_t160) + _t519*_t560);
  const double _t1372 = _hc6[3]*_t144;
  const double _t1373 = _t1372*_t150;
  const double _t1374 = _t1*(_t140*_t568 + _t148*_t551 + _t156*_t532 + _t48*my_piecewise3(_t25, 12.2462410087*_t1366*_t28 + 3.1013068102319998*_t1366*_t30 - _t1366*_t70 - _t1366*_t71 - _t1366*_t72 - _t1366*_t73 - 0.64000000000000001*_t1366 - _t1367*_t183 - _t1367*_t184 - _t1367*_t185 - _t1368*_t183 - _t1368*_t184 - _t1368*_t185 - _t1369*_t565 - _t1370*_t183 - _t1370*_t184 - _t1370*_t185 - _t1371*_t600 - _t1371*_t601 + 73.477446052200008*_t143*_t149*_t154*_t26 + 62.026136204639997*_t143*_t149*_t154*_t28 + 36.738723026100004*_t143*_t27*_t563 + 15.506534051159999*_t143*_t29*_t563 + 36.738723026100004*_t149*_t27*_t548 + 15.506534051159999*_t149*_t29*_t548 + 36.738723026100004*_t154*_t27*_t523 + 15.506534051159999*_t154*_t29*_t523 - _t523*_t585 - _t524*_t563 - _t548*_t564, _hc6[1]*my_piecewise3(_t24, _t1365, 0) + _t1373*_t155 + _t526*_t588 + _t527*_t566 + _t550*_t567));
  const double _t1381 = _t1*(_t140*_t573 + _t148*_t560 + _t161*_t532 + _t48*my_piecewise3(_t25, -_t1002*_t523 - _t1369*_t571 + 12.2462410087*_t1376*_t28 + 3.1013068102319998*_t1376*_t30 - _t1376*_t70 - _t1376*_t71 - _t1376*_t72 - _t1376*_t73 - 0.64000000000000001*_t1376 - _t1377*_t183 - _t1377*_t184 - _t1377*_t185 - _t1378*_t183 - _t1378*_t184 - _t1378*_t185 - _t1379*_t183 - _t1379*_t184 - _t1379*_t185 - _t1380*_t600 - _t1380*_t601 + 73.477446052200008*_t143*_t149*_t159*_t26 + 62.026136204639997*_t143*_t149*_t159*_t28 + 36.738723026100004*_t143*_t27*_t570 + 15.506534051159999*_t143*_t29*_t570 + 36.738723026100004*_t149*_t27*_t557 + 15.506534051159999*_t149*_t29*_t557 + 36.738723026100004*_t159*_t27*_t523 + 15.506534051159999*_t159*_t29*_t523 - _t524*_t570 - _t557*_t564, _hc6[1]*my_piecewise3(_t24, _t1375, 0) + _t1017*_t526 + _t1373*_t160 + _t527*_t572 + _t559*_t567));
  const double _t1398 = _t1*(_t140*_t581 + _t48*my_piecewise3(_t25, -_t1257*_t548 - _t1369*_t578 + 12.2462410087*_t1394*_t28 + 3.1013068102319998*_t1394*_t30 - _t1394*_t70 - _t1394*_t71 - _t1394*_t72 - _t1394*_t73 - 0.64000000000000001*_t1394 - _t1395*_t183 - _t1395*_t184 - _t1395*_t185 - _t1396*_t723 - _t1396*_t724 - _t1396*_t725 - _t1397*_t600 - _t1397*_t601 + 73.477446052200008*_t143*_t26*_t578 + 36.738723026100004*_t143*_t27*_t577 + 62.026136204639997*_t143*_t28*_t578 + 15.506534051159999*_t143*_t29*_t577 + 73.477446052200008*_t154*_t27*_t548 + 31.013068102319998*_t154*_t29*_t548 - _t524*_t577, _hc6[1]*my_piecewise3(_t24, _t1393, 0) + _t1259*_t550 + _t1372*_t580 + _t527*_t579));
  const double _t1406 = _t1*(_t140*_t589 + _t48*my_piecewise3(_t25, -_t1002*_t548 - _t1369*_t586 + 12.2462410087*_t1401*_t28 + 3.1013068102319998*_t1401*_t30 - _t1401*_t70 - _t1401*_t71 - _t1401*_t72 - _t1401*_t73 - 0.64000000000000001*_t1401 - _t1402*_t183 - _t1402*_t184 - _t1402*_t185 - _t1403*_t183 - _t1403*_t184 - _t1403*_t185 - _t1404*_t183 - _t1404*_t184 - _t1404*_t185 - _t1405*_t600 - _t1405*_t601 + 73.477446052200008*_t143*_t154*_t159*_t26 + 62.026136204639997*_t143*_t154*_t159*_t28 + 36.738723026100004*_t143*_t27*_t584 + 15.506534051159999*_t143*_t29*_t584 + 36.738723026100004*_t154*_t27*_t557 + 15.506534051159999*_t154*_t29*_t557 + 36.738723026100004*_t159*_t27*_t548 + 15.506534051159999*_t159*_t29*_t548 - _t524*_t584 - _t557*_t585, _hc6[1]*my_piecewise3(_t24, _t1400, 0) + _t1017*_t550 + _t1267*_t1372 + _t527*_t587 + _t559*_t588));
  const double _t1413 = _t1*(_t140*_t597 + _t48*my_piecewise3(_t25, -_t1272*_t557 - _t1369*_t594 + 12.2462410087*_t1409*_t28 + 3.1013068102319998*_t1409*_t30 - _t1409*_t70 - _t1409*_t71 - _t1409*_t72 - _t1409*_t73 - 0.64000000000000001*_t1409 - _t1410*_t183 - _t1410*_t184 - _t1410*_t185 - _t1411*_t723 - _t1411*_t724 - _t1411*_t725 - _t1412*_t600 - _t1412*_t601 + 73.477446052200008*_t143*_t26*_t594 + 36.738723026100004*_t143*_t27*_t593 + 62.026136204639997*_t143*_t28*_t594 + 15.506534051159999*_t143*_t29*_t593 + 73.477446052200008*_t159*_t27*_t557 + 31.013068102319998*_t159*_t29*_t557 - _t524*_t593, _hc6[1]*my_piecewise3(_t24, _t1408, 0) + _t1275*_t559 + _t1372*_t596 + _t527*_t595));
  const double _t1420 = _hc6[3]*_t150;
  const double d3F_dna3 = _t1*(0.3e1*_t115*_t210 + 0.3e1*_t254*_t75 + _t32*(0.48e2*_hc1[1]*_t112*_t36*_t47*_t60*_t91*na*nb + 0.24e2*_hc1[1]*_t165*_t33*_t36*_t47*_t91*na*nb + 0.48e2*_hc1[1]*_t33*_t36*_t47*_t60*_t91*nb + 0.48e2*_hc1[1]*_t33*_t36*_t60*_t91*_t98*na*nb + 0.24e2*_hc1[2]*_t232*_t33*_t36*_t47*_t91*na*nb - _t104*_t225*_t681 - _t104*_t689 + 0.12e2*_t112*_t225*_t34*_t37*na*nb + 0.24e2*_t112*_t34*_t37*_t98*nb - _t165*_t691 + 0.12e2*_t225*_t33*_t34*_t37*nb - _t225*_t672 - _t231*_t675 - _t231*_t682 - _t234*_t675 - _t234*_t682 - _t240*_t362*_t678 - _t240*_t676*_t98*na + 0.12e2*_t249*_t34*_t37*_t47*nb + 0.12e2*_t249*_t34*_t37*_t98*na*nb - _t250*_t656 + 0.4e1*_t33*_t34*_t37*na*nb*(0.30e2*_t39*_t82 + _t658 + _t660 + _t662 + _t664 - _t670) + 0.72e2*_t33*_t37*_t39*_t47*nb + 0.72e2*_t33*_t37*_t39*_t98*na*nb - _t367*_t673 - (_t60 * _t60 * _t60)*_t680 - _t609*_t679 - 0.48e2*_t655 - _t676*_t677 - _t683*_t685 - _t683*_t686 - _t683*_t688 - _t691*(_t690 - _t78) - _t708 - _t715) + _t48*my_piecewise3(_t25, 110.21616907830001*_t207*_t27*_t69 + 46.519602153479994*_t207*_t29*_t69 + 73.477446052200008*_t26*_t599 + 62.026136204639997*_t28*_t599 + 12.2462410087*_t28*_t654 + 3.1013068102319998*_t30*_t654 - _t599*_t600 - _t599*_t601 - 9.2141136272939992*_t599 - _t602*_t603 - _t602*_t604 - _t602*_t605 - 2.6111999999999997*_t602 - _t654*_t70 - _t654*_t71 - _t654*_t72 - _t654*_t73 - 0.64000000000000001*_t654, _hc6[1]*my_piecewise3(_t24, _t653, 0) + _hc6[3]*(_t74 * _t74 * _t74) + 0.3e1*_t209*_t278) + _t708) + 0.3e1*_t166 + 0.3e1*_t169 - _t171*_t716 - _t174*_t717 + 0.3e1*_t211 + 0.3e1*_t255 + 0.6e1*_t256 + _t718;
  const double d3F_dna2_dnb = _t1*(_t126*_t254 + _t132*_t210 + _t280*_t785 + _t32*(0.16e2*_hc1[1]*_t112*_t118*_t36*_t47*_t91*na*nb + 0.32e2*_hc1[1]*_t112*_t36*_t47*_t60*_t91*na*nb + 0.8e1*_hc1[1]*_t165*_t33*_t36*_t47*_t91*na*nb + 0.32e2*_hc1[1]*_t33*_t36*_t41*_t47*_t8*na*nb + 0.16e2*_hc1[1]*_t33*_t36*_t47*_t60*_t91*nb + 0.16e2*_hc1[1]*_t33*_t36*_t60*_t91*_t98*na*nb + 0.8e1*_hc1[2]*_t232*_t33*_t36*_t47*_t91*na*nb - _t101*_t686 - _t101*_t688 - _t101*_t764 - _t104*_t765 + 0.4e1*_t112*_t225*_t34*_t37*na*nb + 0.8e1*_t112*_t34*_t37*_t98*nb + 0.4e1*_t129*_t249*_t34*_t37*na*nb + 0.24e2*_t129*_t33*_t37*_t39*na*nb - _t130*_t131*_t225 - _t165*_t772 - _t225*_t288 + 0.4e1*_t225*_t33*_t34*_t37*na - _t230*_t296 - _t231*_t289 - _t231*_t763 - _t232*_t680*(_t58 + _t773) - _t234*_t289 - _t234*_t763 - _t235*_t291 - _t235*_t292 - _t237*_t240 - _t237*_t296 - _t241 + 0.4e1*_t249*_t34*_t37*_t47*na + 0.8e1*_t249*_t34*_t37*_t47*nb + 0.8e1*_t249*_t34*_t37*_t98*na*nb - _t250*_t760 - _t252 + 0.8e1*_t285*_t33*_t34*_t37*nb - _t294*_t767 - _t295*_t774 + 0.8e1*_t33*_t34*_t37*_t98 + 0.4e1*_t33*_t34*_t37*na*nb*(0.18e2*_t128*_t39 + 0.12e2*_t39*_t82 - _t753 - _t754 - _t755 + _t756 + _t757) + 0.24e2*_t33*_t37*_t39*_t47*na + 0.48e2*_t33*_t37*_t39*_t47*nb + 0.48e2*_t33*_t37*_t39*_t98*na*nb - _t362*_t752 - _t367*_t752 - _t60*_t758 - 0.16e2*_t655 - _t677*_t761 - _t679*_t727 - _t685*_t766 - _t714*_t768 - _t762*nb - _t769*_t770 - _t782 - _t784) + _t48*my_piecewise3(_t25, 73.477446052200008*_t124*_t182*_t26 + 62.026136204639997*_t124*_t182*_t28 + 36.738723026100004*_t124*_t207*_t27 + 15.506534051159999*_t124*_t207*_t29 - _t124*_t719 - _t183*_t726 - _t184*_t726 - _t185*_t726 - _t207*_t421 + 73.477446052200008*_t27*_t277*_t69 + 31.013068102319998*_t277*_t29*_t69 + 12.2462410087*_t28*_t749 + 3.1013068102319998*_t30*_t749 - _t600*_t720 - _t601*_t720 - _t69*_t721 - _t70*_t749 - _t71*_t749 - _t72*_t749 - _t722*_t723 - _t722*_t724 - _t722*_t725 - _t73*_t749 - 0.64000000000000001*_t749, _hc6[1]*my_piecewise3(_t24, _t748, 0) + _t125*_t750 + _t209*_t427 + _t278*_t751) + _t75*_t786 + _t782) - _t13*_t258*_t299 + _t166 + _t169 + _t172 + _t175 + _t257 - _t260*_t300*_t5 + _t718 + _t787;
  const double d3F_dna_dnb2 = _t1*(_t115*_t320 + _t126*_t786 + _t280*_t333 + _t32*(0.32e2*_hc1[1]*_t112*_t118*_t36*_t47*_t91*na*nb + 0.16e2*_hc1[1]*_t112*_t36*_t47*_t60*_t91*na*nb + 0.16e2*_hc1[1]*_t118*_t129*_t33*_t36*_t91*na*nb + 0.16e2*_hc1[1]*_t118*_t33*_t36*_t47*_t91*na + 0.8e1*_hc1[1]*_t305*_t33*_t36*_t47*_t91*na*nb + 0.56e2*_hc1[1]*_t33*_t36*_t41*_t47*_t8*na*nb + 0.8e1*_hc1[1]*_t33*_t36*_t47*_t93*na*nb + 0.8e1*_hc1[2]*_t327*_t33*_t36*_t47*_t91*na*nb - _t101*_t685 - _t101*_t816 - _t101*_t817 - _t104*_t130*_t323 + 0.8e1*_t112*_t129*_t34*_t37*na + 0.4e1*_t112*_t323*_t34*_t37*na*nb - _t118*_t758 + 0.8e1*_t129*_t249*_t34*_t37*na*nb + 0.8e1*_t129*_t33*_t34*_t37 + 0.48e2*_t129*_t33*_t37*_t39*na*nb - _t131*_t765 - _t235*_t814 + 0.8e1*_t249*_t34*_t37*_t47*na + 0.4e1*_t249*_t34*_t37*_t47*nb + 0.4e1*_t249*_t34*_t37*_t98*na*nb - _t250*_t767 - _t251*nb + 0.8e1*_t285*_t33*_t34*_t37*na - _t288*_t323 - _t290*_t326 - _t290*_t328 - _t291*_t761 - _t292*_t761 - _t293*_t325 - _t293*_t329 - _t294*_t760 - _t296*_t325 - _t296*_t329 - _t305*_t691 + 0.4e1*_t323*_t33*_t34*_t37*nb - _t324 - _t326*_t815 - _t327*_t680*(_t773 + _t9) - _t328*_t815 + 0.4e1*_t33*_t34*_t37*na*nb*(_t607*_t82 + _t753 + _t754 + _t755 - _t756 + _t757) + 0.48e2*_t33*_t37*_t39*_t47*na + 0.24e2*_t33*_t37*_t39*_t47*nb + 0.24e2*_t33*_t37*_t39*_t98*na*nb - _t436*_t752 - _t438*_t752 - _t714*_t769 - _t762*na - _t764*_t766 - _t768*_t770 - _t771*_t774 - _t784 - _t821) + _t331*_t75 + _t48*my_piecewise3(_t25, 73.477446052200008*_t124*_t27*_t277 + 31.013068102319998*_t124*_t277*_t29 - _t124*_t721 - _t183*_t791 - _t184*_t791 - _t185*_t791 + 73.477446052200008*_t26*_t307*_t69 - _t262*_t317 + 36.738723026100004*_t27*_t317*_t69 + 62.026136204639997*_t28*_t307*_t69 + 12.2462410087*_t28*_t812 + 15.506534051159999*_t29*_t317*_t69 + 3.1013068102319998*_t30*_t812 - _t600*_t789 - _t601*_t789 - _t69*_t788 - _t70*_t812 - _t71*_t812 - _t72*_t812 - _t723*_t790 - _t724*_t790 - _t725*_t790 - _t73*_t812 - 0.64000000000000001*_t812, _hc6[1]*my_piecewise3(_t24, _t811, 0) + _t278*_t319 + _t427*_t751 + _t74*_t813) + _t821) + _t334 + _t787 + _t822;
  const double d3F_dnb3 = _t1*(0.3e1*_t126*_t331 + 0.3e1*_t132*_t320 + _t32*(0.48e2*_hc1[1]*_t112*_t118*_t36*_t47*_t91*na*nb + 0.48e2*_hc1[1]*_t118*_t129*_t33*_t36*_t91*na*nb + 0.48e2*_hc1[1]*_t118*_t33*_t36*_t47*_t91*na + 0.24e2*_hc1[1]*_t305*_t33*_t36*_t47*_t91*na*nb + 0.24e2*_hc1[2]*_t327*_t33*_t36*_t47*_t91*na*nb + 0.24e2*_t112*_t129*_t34*_t37*na + 0.12e2*_t112*_t323*_t34*_t37*na*nb - (_t118 * _t118 * _t118)*_t680 + 0.12e2*_t129*_t249*_t34*_t37*na*nb - _t129*_t293*_t676*na + 0.72e2*_t129*_t33*_t37*_t39*na*nb - _t131*_t323*_t681 - _t131*_t689 + 0.12e2*_t249*_t34*_t37*_t47*na - 0.48e2*_t286 - _t293*_t436*_t678 - _t305*_t772 + 0.12e2*_t323*_t33*_t34*_t37*na - _t323*_t672 - _t326*_t832 - _t326*_t833 - _t328*_t832 - _t328*_t833 + 0.4e1*_t33*_t34*_t37*na*nb*(0.30e2*_t128*_t39 - _t658 - _t660 - _t662 - _t664 - _t670) + 0.72e2*_t33*_t37*_t39*_t47*na - _t34*_t713*_t814 - _t436*_t673 - _t438*_t673 - _t679*_t825 - _t683*_t764 - _t683*_t816 - _t683*_t817 - _t715 - _t772*(_t690 + _t78) - _t834) + _t48*my_piecewise3(_t25, 110.21616907830001*_t124*_t27*_t317 + 46.519602153479994*_t124*_t29*_t317 + 73.477446052200008*_t26*_t823 + 62.026136204639997*_t28*_t823 + 12.2462410087*_t28*_t831 + 3.1013068102319998*_t30*_t831 - _t600*_t823 - _t601*_t823 - _t603*_t824 - _t604*_t824 - _t605*_t824 - _t70*_t831 - _t71*_t831 - _t72*_t831 - _t73*_t831 - 9.2141136272939992*_t823 - 2.6111999999999997*_t824 - 0.64000000000000001*_t831, _hc6[1]*my_piecewise3(_t24, _t830, 0) + _hc6[3]*(_t125 * _t125 * _t125) + 0.3e1*_t319*_t427) + _t834) + 0.6e1*_t126*_t132 + 0.3e1*_t306 + 0.3e1*_t321 + 0.3e1*_t322 + 0.3e1*_t332 + _t822;
  const double d3F_dna2_dgaa = _t885;
  const double d3F_dna2_dgab = _t1*(_t148*_t210 + _t151*_t254 + _t32*((0.8e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t135*_t15*_t16*_t36*_t384*_t47*_t60*na*nb + (0.2e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t225*_t37*na*nb + (0.4e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t37*_t98*nb + 0.8e1*_t34*_t37*_t414*_t47*nb + 0.8e1*_t34*_t37*_t414*_t98*na*nb - _t783*_t902 - 0.4e1 / 0.3e1*_t858 - _t860*_t905 - _t862*_t905 - 0.4e1 / 0.3e1*_t863 - _t882*_t904 - 0.8e1 / 0.3e1*_t903 - _t910 - _t915) + _t409*_t785 + _t418*_t884 + _t48*my_piecewise3(_t25, 73.477446052200008*_t149*_t182*_t26 + 62.026136204639997*_t149*_t182*_t28 + 36.738723026100004*_t149*_t207*_t27 + 15.506534051159999*_t149*_t207*_t29 - _t149*_t719 - _t183*_t888 - _t184*_t888 - _t185*_t888 - _t207*_t564 + 73.477446052200008*_t27*_t407*_t69 + 12.2462410087*_t28*_t901 + 31.013068102319998*_t29*_t407*_t69 + 3.1013068102319998*_t30*_t901 - _t407*_t836 - _t600*_t886 - _t601*_t886 - _t70*_t901 - _t71*_t901 - _t72*_t901 - _t723*_t887 - _t724*_t887 - _t725*_t887 - _t73*_t901 - 0.64000000000000001*_t901, _hc6[1]*my_piecewise3(_t24, _t900, 0) + _t150*_t750 + _t209*_t567 + _t408*_t856) + _t910) + 0.2e1*_t360 + 0.2e1*_t410 + 0.2e1*_t411 + 0.2e1*_t412 + 0.2e1*_t419 + _t916;
  const double d3F_dna2_dgbb = _t885;
  const double d3F_dna_dnb_dgaa = _t947;
  const double d3F_dna_dnb_dgab = _t1*(_t115*_t451 + _t126*_t418 + _t132*_t409 + _t148*_t280 + _t151*_t303 + _t32*((0.2e1 / 0.3e1)*_hc2[1]*_t129*_t135*_t139*_t15*_t16*_t37*nb + (0.2e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t285*_t37*na*nb + (0.2e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t37*_t47 + (0.2e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t37*_t98*na - _t118*_t956 + 0.4e1*_t129*_t34*_t37*_t414*na*nb + 0.4e1*_t34*_t37*_t414*_t47*na + 0.4e1*_t34*_t37*_t414*_t47*nb + 0.4e1*_t34*_t37*_t414*_t98*na*nb - _t60*_t956 - _t883 - _t905*_t942 - _t915 - 0.2e1 / 0.3e1*_t935 - 0.2e1 / 0.3e1*_t936 - 0.2e1 / 0.3e1*_t937 - 0.2e1 / 0.3e1*_t938 - 0.4e1 / 0.3e1*_t939*_t941 - _t959 - _t960) + _t455*_t75 + _t48*my_piecewise3(_t25, 73.477446052200008*_t124*_t149*_t26*_t69 + 62.026136204639997*_t124*_t149*_t28*_t69 + 36.738723026100004*_t124*_t27*_t407 + 15.506534051159999*_t124*_t29*_t407 + 36.738723026100004*_t149*_t27*_t277 + 15.506534051159999*_t149*_t277*_t29 - _t183*_t949 - _t183*_t950 - _t183*_t951 - _t184*_t949 - _t184*_t950 - _t184*_t951 - _t185*_t949 - _t185*_t950 - _t185*_t951 - _t262*_t449 + 36.738723026100004*_t27*_t449*_t69 - _t277*_t564 + 12.2462410087*_t28*_t955 + 15.506534051159999*_t29*_t449*_t69 + 3.1013068102319998*_t30*_t955 - _t407*_t421 - _t447*_t917 - _t600*_t948 - _t601*_t948 - _t70*_t955 - _t71*_t955 - _t72*_t955 - _t73*_t955 - 0.64000000000000001*_t955, _hc6[1]*my_piecewise3(_t24, _t954, 0) + _t150*_t931 + _t278*_t450 + _t279*_t567 + _t408*_t427) + _t959) + _t360 + _t420 + _t434 + _t457 + _t916;
  const double d3F_dna_dnb_dgbb = _t947;
  const double d3F_dnb2_dgaa = _t979;
  const double d3F_dnb2_dgab = _t1*(_t148*_t320 + _t151*_t331 + _t32*((0.8e1 / 0.3e1)*_hc1[1]*_hc2[1]*_t118*_t135*_t15*_t16*_t36*_t384*_t47*na*nb + (0.4e1 / 0.3e1)*_hc2[1]*_t129*_t135*_t139*_t15*_t16*_t37*na + (0.2e1 / 0.3e1)*_hc2[1]*_t135*_t139*_t15*_t16*_t323*_t37*na*nb + 0.8e1*_t129*_t34*_t37*_t414*na*nb + 0.8e1*_t34*_t37*_t414*_t47*na - _t902*_t971 - _t904*_t933 - _t904*_t934 - _t905*_t973 - _t905*_t974 - _t915 - 0.4e1 / 0.3e1*_t972 - 0.4e1 / 0.3e1*_t975 - _t987) + _t333*_t451 + _t455*_t978 + _t48*my_piecewise3(_t25, 73.477446052200008*_t124*_t27*_t449 + 31.013068102319998*_t124*_t29*_t449 + 73.477446052200008*_t149*_t26*_t307 + 36.738723026100004*_t149*_t27*_t317 + 62.026136204639997*_t149*_t28*_t307 + 15.506534051159999*_t149*_t29*_t317 - _t149*_t788 - _t183*_t982 - _t184*_t982 - _t185*_t982 + 12.2462410087*_t28*_t986 + 3.1013068102319998*_t30*_t986 - _t317*_t564 - _t449*_t962 - _t600*_t980 - _t601*_t980 - _t70*_t986 - _t71*_t986 - _t72*_t986 - _t723*_t981 - _t724*_t981 - _t725*_t981 - _t73*_t986 - 0.64000000000000001*_t986, _hc6[1]*my_piecewise3(_t24, _t985, 0) + _t150*_t813 + _t319*_t567 + _t450*_t970) + _t987) + 0.2e1*_t434 + 0.2e1*_t452 + 0.2e1*_t453 + 0.2e1*_t454 + 0.2e1*_t456 + _t916;
  const double d3F_dnb2_dgbb = _t979;
  const double d3F_dna2_dta = _t1*(_t156*_t254 + _t467*_t785 + _t48*my_piecewise3(_t25, 73.477446052200008*_t154*_t182*_t26 + 62.026136204639997*_t154*_t182*_t28 + 36.738723026100004*_t154*_t207*_t27 + 15.506534051159999*_t154*_t207*_t29 - _t154*_t719 - _t183*_t990 - _t184*_t990 - _t185*_t990 - _t207*_t585 + 73.477446052200008*_t27*_t464*_t69 + 12.2462410087*_t28*_t999 + 31.013068102319998*_t29*_t464*_t69 + 3.1013068102319998*_t30*_t999 - _t464*_t836 - _t600*_t988 - _t601*_t988 - _t70*_t999 - _t71*_t999 - _t72*_t999 - _t723*_t989 - _t724*_t989 - _t725*_t989 - _t73*_t999 - 0.64000000000000001*_t999, _hc6[1]*my_piecewise3(_t24, _t998, 0) + _t155*_t750 + _t209*_t588 + _t466*_t856)) + 0.2e1*_t458 + 0.2e1*_t468;
  const double d3F_dna2_dtb = _t1*(_t161*_t254 + _t478*_t785 + _t48*my_piecewise3(_t25, -_t1000*_t600 - _t1000*_t601 - _t1001*_t723 - _t1001*_t724 - _t1001*_t725 - _t1002*_t207 - _t1003*_t183 - _t1003*_t184 - _t1003*_t185 + 12.2462410087*_t1016*_t28 + 3.1013068102319998*_t1016*_t30 - _t1016*_t70 - _t1016*_t71 - _t1016*_t72 - _t1016*_t73 - 0.64000000000000001*_t1016 + 73.477446052200008*_t159*_t182*_t26 + 62.026136204639997*_t159*_t182*_t28 + 36.738723026100004*_t159*_t207*_t27 + 15.506534051159999*_t159*_t207*_t29 - _t159*_t719 + 73.477446052200008*_t27*_t475*_t69 + 31.013068102319998*_t29*_t475*_t69 - _t475*_t836, _hc6[1]*my_piecewise3(_t24, _t1015, 0) + _t1017*_t209 + _t160*_t750 + _t477*_t856)) + 0.2e1*_t470 + 0.2e1*_t479;
  const double d3F_dna_dnb_dta = _t1*(_t115*_t486 + _t132*_t467 + _t156*_t303 + _t48*my_piecewise3(_t25, -_t1018*_t183 - _t1018*_t184 - _t1018*_t185 - _t1019*_t183 - _t1019*_t184 - _t1019*_t185 - _t1020*_t600 - _t1020*_t601 - _t1021*_t183 - _t1021*_t184 - _t1021*_t185 + 12.2462410087*_t1026*_t28 + 3.1013068102319998*_t1026*_t30 - _t1026*_t70 - _t1026*_t71 - _t1026*_t72 - _t1026*_t73 - 0.64000000000000001*_t1026 + 73.477446052200008*_t124*_t154*_t26*_t69 + 62.026136204639997*_t124*_t154*_t28*_t69 + 36.738723026100004*_t124*_t27*_t464 + 15.506534051159999*_t124*_t29*_t464 + 36.738723026100004*_t154*_t27*_t277 + 15.506534051159999*_t154*_t277*_t29 - _t262*_t483 + 36.738723026100004*_t27*_t483*_t69 - _t277*_t585 + 15.506534051159999*_t29*_t483*_t69 - _t421*_t464 - _t484*_t917, _hc6[1]*my_piecewise3(_t24, _t1025, 0) + _t155*_t931 + _t278*_t485 + _t279*_t588 + _t427*_t466)) + _t469 + _t488;
  const double d3F_dna_dnb_dtb = _t1*(_t115*_t497 + _t132*_t478 + _t161*_t303 + _t48*my_piecewise3(_t25, -_t1002*_t277 - _t1027*_t183 - _t1027*_t184 - _t1027*_t185 - _t1028*_t183 - _t1028*_t184 - _t1028*_t185 - _t1029*_t600 - _t1029*_t601 - _t1030*_t183 - _t1030*_t184 - _t1030*_t185 + 12.2462410087*_t1036*_t28 + 3.1013068102319998*_t1036*_t30 - _t1036*_t70 - _t1036*_t71 - _t1036*_t72 - _t1036*_t73 - 0.64000000000000001*_t1036 + 73.477446052200008*_t124*_t159*_t26*_t69 + 62.026136204639997*_t124*_t159*_t28*_t69 + 36.738723026100004*_t124*_t27*_t475 + 15.506534051159999*_t124*_t29*_t475 + 36.738723026100004*_t159*_t27*_t277 + 15.506534051159999*_t159*_t277*_t29 - _t262*_t494 + 36.738723026100004*_t27*_t494*_t69 + 15.506534051159999*_t29*_t494*_t69 - _t421*_t475 - _t495*_t917, _hc6[1]*my_piecewise3(_t24, _t1035, 0) + _t1017*_t279 + _t160*_t931 + _t278*_t496 + _t427*_t477)) + _t480 + _t499;
  const double d3F_dnb2_dta = _t1*(_t156*_t331 + _t333*_t486 + _t48*my_piecewise3(_t25, -_t1037*_t600 - _t1037*_t601 - _t1038*_t723 - _t1038*_t724 - _t1038*_t725 - _t1039*_t183 - _t1039*_t184 - _t1039*_t185 + 12.2462410087*_t1042*_t28 + 3.1013068102319998*_t1042*_t30 - _t1042*_t70 - _t1042*_t71 - _t1042*_t72 - _t1042*_t73 - 0.64000000000000001*_t1042 + 73.477446052200008*_t124*_t27*_t483 + 31.013068102319998*_t124*_t29*_t483 + 73.477446052200008*_t154*_t26*_t307 + 36.738723026100004*_t154*_t27*_t317 + 62.026136204639997*_t154*_t28*_t307 + 15.506534051159999*_t154*_t29*_t317 - _t154*_t788 - _t317*_t585 - _t483*_t962, _hc6[1]*my_piecewise3(_t24, _t1041, 0) + _t155*_t813 + _t319*_t588 + _t485*_t970)) + 0.2e1*_t481 + 0.2e1*_t487;
  const double d3F_dnb2_dtb = _t1*(_t161*_t331 + _t333*_t497 + _t48*my_piecewise3(_t25, -_t1002*_t317 - _t1043*_t600 - _t1043*_t601 - _t1044*_t723 - _t1044*_t724 - _t1044*_t725 - _t1045*_t183 - _t1045*_t184 - _t1045*_t185 + 12.2462410087*_t1047*_t28 + 3.1013068102319998*_t1047*_t30 - _t1047*_t70 - _t1047*_t71 - _t1047*_t72 - _t1047*_t73 - 0.64000000000000001*_t1047 + 73.477446052200008*_t124*_t27*_t494 + 31.013068102319998*_t124*_t29*_t494 + 73.477446052200008*_t159*_t26*_t307 + 36.738723026100004*_t159*_t27*_t317 + 62.026136204639997*_t159*_t28*_t307 + 15.506534051159999*_t159*_t29*_t317 - _t159*_t788 - _t494*_t962, _hc6[1]*my_piecewise3(_t24, _t1046, 0) + _t1017*_t319 + _t160*_t813 + _t496*_t970)) + 0.2e1*_t489 + 0.2e1*_t498;
  const double d3F_dna_dgaa2 = _t1094;
  const double d3F_dna_dgaa_dgab = _t1*(_t1097 + _t1112 + _t1122 + _t32*(-_t1097 + _t1104 + _t1110)) + _t533;
  const double d3F_dna_dgaa_dgbb = _t1094;
  const double d3F_dna_dgab2 = _t1*(-_t1131 + _t1133 + _t1142*_t418 + _t1143 + _t115*_t540 + _t32*(-_t1069*_t1109 + (0.1e1 / 0.3e1)*_t1070 + (0.1e1 / 0.3e1)*_t1072 + (0.2e1 / 0.3e1)*_t1075*_t529 - 0.2e1 / 0.3e1*_t1105 - 0.2e1 / 0.3e1*_t1106 + _t1131 - _t1133 + _t1141) + _t409*_t543 + _t48*my_piecewise3(_t25, -_t1123*_t600 - _t1123*_t601 - _t1124*_t183 - _t1124*_t184 - _t1124*_t185 - _t1125*_t407 - _t1126*_t723 - _t1126*_t724 - _t1126*_t725 + 12.2462410087*_t1129*_t28 + 3.1013068102319998*_t1129*_t30 - _t1129*_t70 - _t1129*_t71 - _t1129*_t72 - _t1129*_t73 - 0.64000000000000001*_t1129 + 73.477446052200008*_t149*_t27*_t407 + 31.013068102319998*_t149*_t29*_t407 + 73.477446052200008*_t26*_t535*_t69 - _t262*_t537 + 36.738723026100004*_t27*_t537*_t69 + 62.026136204639997*_t28*_t535*_t69 + 15.506534051159999*_t29*_t537*_t69 - _t535*_t917, _hc6[1]*my_piecewise3(_t24, _t1128, 0) + _t1130*_t408 + _t278*_t539 + _t538*_t930) + _t542*_t75) + _t544;
  const double d3F_dna_dgab_dgbb = _t1*(_t1122 - _t1144 + _t1146 + _t1151 + _t32*(_t1110 + _t1144 - _t1146 + _t1150)) + _t533;
  const double d3F_dna_dgbb2 = _t1094;
  const double d3F_dnb_dgaa2 = _t1168;
  const double d3F_dnb_dgaa_dgab = _t1*(_t1112 + _t1169 + _t1180 + _t32*(_t1104 - _t1169 + _t1173)) + _t533;
  const double d3F_dnb_dgaa_dgbb = _t1168;
  const double d3F_dnb_dgab2 = _t1*(_t1142*_t455 + _t1143 - _t1186 + _t1188 + _t126*_t542 + _t132*_t540 + _t32*(-_t1069*_t1172 + _t1107*_t118*_t940 + _t1141 + (0.1e1 / 0.3e1)*_t1163 + (0.1e1 / 0.3e1)*_t1165 - 0.2e1 / 0.3e1*_t1170 - 0.2e1 / 0.3e1*_t1171 + _t1186 - _t1188) + _t451*_t543 + _t48*my_piecewise3(_t25, -_t1125*_t449 - _t1152*_t535 - _t1181*_t600 - _t1181*_t601 - _t1182*_t183 - _t1182*_t184 - _t1182*_t185 - _t1183*_t723 - _t1183*_t724 - _t1183*_t725 + 12.2462410087*_t1185*_t28 + 3.1013068102319998*_t1185*_t30 - _t1185*_t70 - _t1185*_t71 - _t1185*_t72 - _t1185*_t73 - 0.64000000000000001*_t1185 + 73.477446052200008*_t124*_t26*_t535 + 36.738723026100004*_t124*_t27*_t537 + 62.026136204639997*_t124*_t28*_t535 + 15.506534051159999*_t124*_t29*_t537 + 73.477446052200008*_t149*_t27*_t449 + 31.013068102319998*_t149*_t29*_t449 - _t421*_t537, _hc6[1]*my_piecewise3(_t24, _t1184, 0) + _t1130*_t450 + _t1160*_t538 + _t427*_t539)) + _t544;
  const double d3F_dnb_dgab_dgbb = _t1*(_t1151 + _t1180 - _t1189 + _t1190 + _t32*(_t1150 + _t1173 + _t1189 - _t1190)) + _t533;
  const double d3F_dnb_dgbb2 = _t1168;
  const double d3F_dna_dgaa_dta = _t1199;
  const double d3F_dna_dgaa_dtb = _t1208;
  const double d3F_dna_dgab_dta = _t1*(_t115*_t568 + _t148*_t467 + _t156*_t418 + _t48*my_piecewise3(_t25, -_t1209*_t183 - _t1209*_t184 - _t1209*_t185 - _t1210*_t183 - _t1210*_t184 - _t1210*_t185 - _t1211*_t600 - _t1211*_t601 - _t1212*_t183 - _t1212*_t184 - _t1212*_t185 + 12.2462410087*_t1215*_t28 + 3.1013068102319998*_t1215*_t30 - _t1215*_t70 - _t1215*_t71 - _t1215*_t72 - _t1215*_t73 - 0.64000000000000001*_t1215 + 73.477446052200008*_t149*_t154*_t26*_t69 + 62.026136204639997*_t149*_t154*_t28*_t69 + 36.738723026100004*_t149*_t27*_t464 + 15.506534051159999*_t149*_t29*_t464 + 36.738723026100004*_t154*_t27*_t407 + 15.506534051159999*_t154*_t29*_t407 - _t262*_t563 + 36.738723026100004*_t27*_t563*_t69 + 15.506534051159999*_t29*_t563*_t69 - _t407*_t585 - _t464*_t564 - _t565*_t917, _hc6[1]*my_piecewise3(_t24, _t1214, 0) + _t1216*_t155 + _t278*_t566 + _t408*_t588 + _t466*_t567)) + _t569;
  const double d3F_dna_dgab_dtb = _t1*(_t115*_t573 + _t148*_t478 + _t161*_t418 + _t48*my_piecewise3(_t25, -_t1002*_t407 - _t1217*_t183 - _t1217*_t184 - _t1217*_t185 - _t1218*_t183 - _t1218*_t184 - _t1218*_t185 - _t1219*_t600 - _t1219*_t601 + 12.2462410087*_t1222*_t28 + 3.1013068102319998*_t1222*_t30 - _t1222*_t70 - _t1222*_t71 - _t1222*_t72 - _t1222*_t73 - 0.64000000000000001*_t1222 - _t1223*_t183 - _t1223*_t184 - _t1223*_t185 + 73.477446052200008*_t149*_t159*_t26*_t69 + 62.026136204639997*_t149*_t159*_t28*_t69 + 36.738723026100004*_t149*_t27*_t475 + 15.506534051159999*_t149*_t29*_t475 + 36.738723026100004*_t159*_t27*_t407 + 15.506534051159999*_t159*_t29*_t407 - _t262*_t570 + 36.738723026100004*_t27*_t570*_t69 + 15.506534051159999*_t29*_t570*_t69 - _t475*_t564 - _t571*_t917, _hc6[1]*my_piecewise3(_t24, _t1221, 0) + _t1017*_t408 + _t1216*_t160 + _t278*_t572 + _t477*_t567)) + _t574;
  const double d3F_dna_dgbb_dta = _t1199;
  const double d3F_dna_dgbb_dtb = _t1208;
  const double d3F_dnb_dgaa_dta = _t1231;
  const double d3F_dnb_dgaa_dtb = _t1238;
  const double d3F_dnb_dgab_dta = _t1*(_t132*_t568 + _t148*_t486 + _t156*_t455 + _t48*my_piecewise3(_t25, -_t1152*_t565 - _t1239*_t183 - _t1239*_t184 - _t1239*_t185 + 73.477446052200008*_t124*_t149*_t154*_t26 + 62.026136204639997*_t124*_t149*_t154*_t28 + 36.738723026100004*_t124*_t27*_t563 + 15.506534051159999*_t124*_t29*_t563 - _t1240*_t183 - _t1240*_t184 - _t1240*_t185 - _t1241*_t600 - _t1241*_t601 + 12.2462410087*_t1243*_t28 + 3.1013068102319998*_t1243*_t30 - _t1243*_t70 - _t1243*_t71 - _t1243*_t72 - _t1243*_t73 - 0.64000000000000001*_t1243 - _t1244*_t183 - _t1244*_t184 - _t1244*_t185 + 36.738723026100004*_t149*_t27*_t483 + 15.506534051159999*_t149*_t29*_t483 + 36.738723026100004*_t154*_t27*_t449 + 15.506534051159999*_t154*_t29*_t449 - _t421*_t563 - _t449*_t585 - _t483*_t564, _hc6[1]*my_piecewise3(_t24, _t1242, 0) + _t1245*_t155 + _t427*_t566 + _t450*_t588 + _t485*_t567)) + _t569;
  const double d3F_dnb_dgab_dtb = _t1*(_t132*_t573 + _t148*_t497 + _t161*_t455 + _t48*my_piecewise3(_t25, -_t1002*_t449 - _t1152*_t571 + 73.477446052200008*_t124*_t149*_t159*_t26 + 62.026136204639997*_t124*_t149*_t159*_t28 + 36.738723026100004*_t124*_t27*_t570 + 15.506534051159999*_t124*_t29*_t570 - _t1246*_t183 - _t1246*_t184 - _t1246*_t185 - _t1247*_t183 - _t1247*_t184 - _t1247*_t185 - _t1248*_t600 - _t1248*_t601 - _t1249*_t183 - _t1249*_t184 - _t1249*_t185 + 12.2462410087*_t1251*_t28 + 3.1013068102319998*_t1251*_t30 - _t1251*_t70 - _t1251*_t71 - _t1251*_t72 - _t1251*_t73 - 0.64000000000000001*_t1251 + 36.738723026100004*_t149*_t27*_t494 + 15.506534051159999*_t149*_t29*_t494 + 36.738723026100004*_t159*_t27*_t449 + 15.506534051159999*_t159*_t29*_t449 - _t421*_t570 - _t494*_t564, _hc6[1]*my_piecewise3(_t24, _t1250, 0) + _t1017*_t450 + _t1245*_t160 + _t427*_t572 + _t496*_t567)) + _t574;
  const double d3F_dnb_dgbb_dta = _t1231;
  const double d3F_dnb_dgbb_dtb = _t1238;
  const double d3F_dna_dta2 = _t1*(_t115*_t581 + _t48*my_piecewise3(_t25, 12.2462410087*_t1254*_t28 + 3.1013068102319998*_t1254*_t30 - _t1254*_t70 - _t1254*_t71 - _t1254*_t72 - _t1254*_t73 - 0.64000000000000001*_t1254 - _t1255*_t183 - _t1255*_t184 - _t1255*_t185 - _t1256*_t600 - _t1256*_t601 - _t1257*_t464 - _t1258*_t723 - _t1258*_t724 - _t1258*_t725 + 73.477446052200008*_t154*_t27*_t464 + 31.013068102319998*_t154*_t29*_t464 + 73.477446052200008*_t26*_t578*_t69 - _t262*_t577 + 36.738723026100004*_t27*_t577*_t69 + 62.026136204639997*_t28*_t578*_t69 + 15.506534051159999*_t29*_t577*_t69 - _t578*_t917, _hc6[1]*my_piecewise3(_t24, _t1253, 0) + _t1259*_t466 + _t278*_t579 + _t580*_t930)) + _t582;
  const double d3F_dna_dta_dtb = _t1*(_t115*_t589 + _t48*my_piecewise3(_t25, -_t1002*_t464 - _t1260*_t183 - _t1260*_t184 - _t1260*_t185 + 12.2462410087*_t1263*_t28 + 3.1013068102319998*_t1263*_t30 - _t1263*_t70 - _t1263*_t71 - _t1263*_t72 - _t1263*_t73 - 0.64000000000000001*_t1263 - _t1264*_t183 - _t1264*_t184 - _t1264*_t185 - _t1265*_t183 - _t1265*_t184 - _t1265*_t185 - _t1266*_t600 - _t1266*_t601 + 73.477446052200008*_t154*_t159*_t26*_t69 + 62.026136204639997*_t154*_t159*_t28*_t69 + 36.738723026100004*_t154*_t27*_t475 + 15.506534051159999*_t154*_t29*_t475 + 36.738723026100004*_t159*_t27*_t464 + 15.506534051159999*_t159*_t29*_t464 - _t262*_t584 + 36.738723026100004*_t27*_t584*_t69 + 15.506534051159999*_t29*_t584*_t69 - _t475*_t585 - _t586*_t917, _hc6[1]*my_piecewise3(_t24, _t1262, 0) + _t1017*_t466 + _t1267*_t930 + _t278*_t587 + _t477*_t588)) + _t590;
  const double d3F_dna_dtb2 = _t1*(_t115*_t597 + _t48*my_piecewise3(_t25, 12.2462410087*_t1270*_t28 + 3.1013068102319998*_t1270*_t30 - _t1270*_t70 - _t1270*_t71 - _t1270*_t72 - _t1270*_t73 - 0.64000000000000001*_t1270 - _t1271*_t183 - _t1271*_t184 - _t1271*_t185 - _t1272*_t475 - _t1273*_t600 - _t1273*_t601 - _t1274*_t723 - _t1274*_t724 - _t1274*_t725 + 73.477446052200008*_t159*_t27*_t475 + 31.013068102319998*_t159*_t29*_t475 + 73.477446052200008*_t26*_t594*_t69 - _t262*_t593 + 36.738723026100004*_t27*_t593*_t69 + 62.026136204639997*_t28*_t594*_t69 + 15.506534051159999*_t29*_t593*_t69 - _t594*_t917, _hc6[1]*my_piecewise3(_t24, _t1269, 0) + _t1275*_t477 + _t278*_t595 + _t596*_t930)) + _t598;
  const double d3F_dnb_dta2 = _t1*(_t132*_t581 + _t48*my_piecewise3(_t25, -_t1152*_t578 + 73.477446052200008*_t124*_t26*_t578 + 36.738723026100004*_t124*_t27*_t577 + 62.026136204639997*_t124*_t28*_t578 + 15.506534051159999*_t124*_t29*_t577 - _t1257*_t483 + 12.2462410087*_t1277*_t28 + 3.1013068102319998*_t1277*_t30 - _t1277*_t70 - _t1277*_t71 - _t1277*_t72 - _t1277*_t73 - 0.64000000000000001*_t1277 - _t1278*_t183 - _t1278*_t184 - _t1278*_t185 - _t1279*_t600 - _t1279*_t601 - _t1280*_t723 - _t1280*_t724 - _t1280*_t725 + 73.477446052200008*_t154*_t27*_t483 + 31.013068102319998*_t154*_t29*_t483 - _t421*_t577, _hc6[1]*my_piecewise3(_t24, _t1276, 0) + _t1160*_t580 + _t1259*_t485 + _t427*_t579)) + _t582;
  const double d3F_dnb_dta_dtb = _t1*(_t132*_t589 + _t48*my_piecewise3(_t25, -_t1002*_t483 - _t1152*_t586 + 73.477446052200008*_t124*_t154*_t159*_t26 + 62.026136204639997*_t124*_t154*_t159*_t28 + 36.738723026100004*_t124*_t27*_t584 + 15.506534051159999*_t124*_t29*_t584 - _t1281*_t183 - _t1281*_t184 - _t1281*_t185 + 12.2462410087*_t1283*_t28 + 3.1013068102319998*_t1283*_t30 - _t1283*_t70 - _t1283*_t71 - _t1283*_t72 - _t1283*_t73 - 0.64000000000000001*_t1283 - _t1284*_t183 - _t1284*_t184 - _t1284*_t185 - _t1285*_t183 - _t1285*_t184 - _t1285*_t185 - _t1286*_t600 - _t1286*_t601 + 36.738723026100004*_t154*_t27*_t494 + 15.506534051159999*_t154*_t29*_t494 + 36.738723026100004*_t159*_t27*_t483 + 15.506534051159999*_t159*_t29*_t483 - _t421*_t584 - _t494*_t585, _hc6[1]*my_piecewise3(_t24, _t1282, 0) + _t1017*_t485 + _t1160*_t1267 + _t427*_t587 + _t496*_t588)) + _t590;
  const double d3F_dnb_dtb2 = _t1*(_t132*_t597 + _t48*my_piecewise3(_t25, -_t1152*_t594 + 73.477446052200008*_t124*_t26*_t594 + 36.738723026100004*_t124*_t27*_t593 + 62.026136204639997*_t124*_t28*_t594 + 15.506534051159999*_t124*_t29*_t593 - _t1272*_t494 + 12.2462410087*_t1288*_t28 + 3.1013068102319998*_t1288*_t30 - _t1288*_t70 - _t1288*_t71 - _t1288*_t72 - _t1288*_t73 - 0.64000000000000001*_t1288 - _t1289*_t183 - _t1289*_t184 - _t1289*_t185 - _t1290*_t600 - _t1290*_t601 - _t1291*_t723 - _t1291*_t724 - _t1291*_t725 + 73.477446052200008*_t159*_t27*_t494 + 31.013068102319998*_t159*_t29*_t494 - _t421*_t593, _hc6[1]*my_piecewise3(_t24, _t1287, 0) + _t1160*_t596 + _t1275*_t496 + _t427*_t595)) + _t598;
  const double d3F_dgaa3 = _t1313;
  const double d3F_dgaa2_dgab = _t1*(_t1315 + _t1329 + _t32*(-_t1315 + _t1320));
  const double d3F_dgaa2_dgbb = _t1313;
  const double d3F_dgaa_dgab2 = _t1342;
  const double d3F_dgaa_dgab_dgbb = _t1*(_t1328 + _t1343 - _t1344 + _t32*(_t1319 - _t1343 + _t1344));
  const double d3F_dgaa_dgbb2 = _t1313;
  const double d3F_dgab3 = _t1*(_t1333 - _t1345 + _t1347 + 0.3e1*_t148*_t540 + 0.3e1*_t151*_t542 + _t32*(_t1162*_t1304*_t81 + (0.1e1 / 0.6e1)*_t1302 - _t1303 - _t1333 + _t1345 - _t1347) + _t48*my_piecewise3(_t25, 73.477446052200008*_t1348*_t26 + 62.026136204639997*_t1348*_t28 - _t1348*_t600 - _t1348*_t601 - 9.2141136272939992*_t1348 + 12.2462410087*_t1350*_t28 + 3.1013068102319998*_t1350*_t30 - _t1350*_t70 - _t1350*_t71 - _t1350*_t72 - _t1350*_t73 - 0.64000000000000001*_t1350 - _t1351*_t603 - _t1351*_t604 - _t1351*_t605 - 2.6111999999999997*_t1351 + 110.21616907830001*_t149*_t27*_t537 + 46.519602153479994*_t149*_t29*_t537, _hc6[1]*my_piecewise3(_t24, _t1349, 0) + _hc6[3]*(_t150 * _t150 * _t150) + 0.3e1*_t539*_t567));
  const double d3F_dgab2_dgbb = _t1342;
  const double d3F_dgab_dgbb2 = _t1*(_t1300 + _t1329 + _t32*(-_t1300 + _t1320));
  const double d3F_dgbb3 = _t1313;
  const double d3F_dgaa2_dta = _t1357;
  const double d3F_dgaa2_dtb = _t1364;
  const double d3F_dgaa_dgab_dta = _t1374;
  const double d3F_dgaa_dgab_dtb = _t1381;
  const double d3F_dgaa_dgbb_dta = _t1357;
  const double d3F_dgaa_dgbb_dtb = _t1364;
  const double d3F_dgab2_dta = _t1*(_t156*_t542 + _t48*my_piecewise3(_t25, -_t1125*_t563 - _t1335*_t154 + 12.2462410087*_t1383*_t28 + 3.1013068102319998*_t1383*_t30 - _t1383*_t70 - _t1383*_t71 - _t1383*_t72 - _t1383*_t73 - 0.64000000000000001*_t1383 - _t1384*_t600 - _t1384*_t601 - _t1385*_t723 - _t1385*_t724 - _t1385*_t725 - _t1386*_t183 - _t1386*_t184 - _t1386*_t185 + 73.477446052200008*_t149*_t27*_t563 + 31.013068102319998*_t149*_t29*_t563 + 73.477446052200008*_t154*_t26*_t535 + 36.738723026100004*_t154*_t27*_t537 + 62.026136204639997*_t154*_t28*_t535 + 15.506534051159999*_t154*_t29*_t537 - _t537*_t585, _hc6[1]*my_piecewise3(_t24, _t1382, 0) + _t1130*_t566 + _t1341*_t155 + _t539*_t588) + _t543*_t568);
  const double d3F_dgab2_dtb = _t1*(_t161*_t542 + _t48*my_piecewise3(_t25, -_t1002*_t537 - _t1125*_t570 - _t1335*_t159 + 12.2462410087*_t1388*_t28 + 3.1013068102319998*_t1388*_t30 - _t1388*_t70 - _t1388*_t71 - _t1388*_t72 - _t1388*_t73 - 0.64000000000000001*_t1388 - _t1389*_t600 - _t1389*_t601 - _t1390*_t723 - _t1390*_t724 - _t1390*_t725 - _t1391*_t183 - _t1391*_t184 - _t1391*_t185 + 73.477446052200008*_t149*_t27*_t570 + 31.013068102319998*_t149*_t29*_t570 + 73.477446052200008*_t159*_t26*_t535 + 36.738723026100004*_t159*_t27*_t537 + 62.026136204639997*_t159*_t28*_t535 + 15.506534051159999*_t159*_t29*_t537, _hc6[1]*my_piecewise3(_t24, _t1387, 0) + _t1017*_t539 + _t1130*_t572 + _t1341*_t160) + _t543*_t573);
  const double d3F_dgab_dgbb_dta = _t1374;
  const double d3F_dgab_dgbb_dtb = _t1381;
  const double d3F_dgbb2_dta = _t1357;
  const double d3F_dgbb2_dtb = _t1364;
  const double d3F_dgaa_dta2 = _t1398;
  const double d3F_dgaa_dta_dtb = _t1406;
  const double d3F_dgaa_dtb2 = _t1413;
  const double d3F_dgab_dta2 = _t1*(_t148*_t581 + _t48*my_piecewise3(_t25, -_t1257*_t563 + 12.2462410087*_t1415*_t28 + 3.1013068102319998*_t1415*_t30 - _t1415*_t70 - _t1415*_t71 - _t1415*_t72 - _t1415*_t73 - 0.64000000000000001*_t1415 - _t1416*_t578 - _t1417*_t183 - _t1417*_t184 - _t1417*_t185 - _t1418*_t723 - _t1418*_t724 - _t1418*_t725 - _t1419*_t600 - _t1419*_t601 + 73.477446052200008*_t149*_t26*_t578 + 36.738723026100004*_t149*_t27*_t577 + 62.026136204639997*_t149*_t28*_t578 + 15.506534051159999*_t149*_t29*_t577 + 73.477446052200008*_t154*_t27*_t563 + 31.013068102319998*_t154*_t29*_t563 - _t564*_t577, _hc6[1]*my_piecewise3(_t24, _t1414, 0) + _t1259*_t566 + _t1420*_t580 + _t567*_t579));
  const double d3F_dgab_dta_dtb = _t1*(_t148*_t589 + _t48*my_piecewise3(_t25, -_t1002*_t563 - _t1416*_t586 + 12.2462410087*_t1422*_t28 + 3.1013068102319998*_t1422*_t30 - _t1422*_t70 - _t1422*_t71 - _t1422*_t72 - _t1422*_t73 - 0.64000000000000001*_t1422 - _t1423*_t183 - _t1423*_t184 - _t1423*_t185 - _t1424*_t183 - _t1424*_t184 - _t1424*_t185 - _t1425*_t183 - _t1425*_t184 - _t1425*_t185 - _t1426*_t600 - _t1426*_t601 + 73.477446052200008*_t149*_t154*_t159*_t26 + 62.026136204639997*_t149*_t154*_t159*_t28 + 36.738723026100004*_t149*_t27*_t584 + 15.506534051159999*_t149*_t29*_t584 + 36.738723026100004*_t154*_t27*_t570 + 15.506534051159999*_t154*_t29*_t570 + 36.738723026100004*_t159*_t27*_t563 + 15.506534051159999*_t159*_t29*_t563 - _t564*_t584 - _t570*_t585, _hc6[1]*my_piecewise3(_t24, _t1421, 0) + _t1017*_t566 + _t1267*_t1420 + _t567*_t587 + _t572*_t588));
  const double d3F_dgab_dtb2 = _t1*(_t148*_t597 + _t48*my_piecewise3(_t25, -_t1272*_t570 - _t1416*_t594 + 12.2462410087*_t1428*_t28 + 3.1013068102319998*_t1428*_t30 - _t1428*_t70 - _t1428*_t71 - _t1428*_t72 - _t1428*_t73 - 0.64000000000000001*_t1428 - _t1429*_t183 - _t1429*_t184 - _t1429*_t185 - _t1430*_t723 - _t1430*_t724 - _t1430*_t725 - _t1431*_t600 - _t1431*_t601 + 73.477446052200008*_t149*_t26*_t594 + 36.738723026100004*_t149*_t27*_t593 + 62.026136204639997*_t149*_t28*_t594 + 15.506534051159999*_t149*_t29*_t593 + 73.477446052200008*_t159*_t27*_t570 + 31.013068102319998*_t159*_t29*_t570 - _t564*_t593, _hc6[1]*my_piecewise3(_t24, _t1427, 0) + _t1275*_t572 + _t1420*_t596 + _t567*_t595));
  const double d3F_dgbb_dta2 = _t1398;
  const double d3F_dgbb_dta_dtb = _t1406;
  const double d3F_dgbb_dtb2 = _t1413;
  const double d3F_dta3 = _t1436*my_piecewise3(_t25, 12.2462410087*_t1433*_t28 + 3.1013068102319998*_t1433*_t30 - _t1433*_t70 - _t1433*_t71 - _t1433*_t72 - _t1433*_t73 - 0.64000000000000001*_t1433 + 73.477446052200008*_t1434*_t26 + 62.026136204639997*_t1434*_t28 - _t1434*_t600 - _t1434*_t601 - 9.2141136272939992*_t1434 - _t1435*_t603 - _t1435*_t604 - _t1435*_t605 - 2.6111999999999997*_t1435 + 110.21616907830001*_t154*_t27*_t577 + 46.519602153479994*_t154*_t29*_t577, _hc6[1]*my_piecewise3(_t24, _t1432, 0) + _hc6[3]*(_t155 * _t155 * _t155) + 0.3e1*_t579*_t588);
  const double d3F_dta2_dtb = _t1436*my_piecewise3(_t25, -_t1002*_t577 - _t1257*_t584 + 12.2462410087*_t1438*_t28 + 3.1013068102319998*_t1438*_t30 - _t1438*_t70 - _t1438*_t71 - _t1438*_t72 - _t1438*_t73 - 0.64000000000000001*_t1438 - _t1439*_t600 - _t1439*_t601 - 9.2141136272939992*_t1439 - _t1440*_t183 - _t1440*_t184 - _t1440*_t185 - _t1441*_t723 - _t1441*_t724 - _t1441*_t725 + 73.477446052200008*_t154*_t27*_t584 + 31.013068102319998*_t154*_t29*_t584 + 73.477446052200008*_t159*_t26*_t578 + 36.738723026100004*_t159*_t27*_t577 + 62.026136204639997*_t159*_t28*_t578 + 15.506534051159999*_t159*_t29*_t577, _hc6[1]*my_piecewise3(_t24, _t1437, 0) + _hc6[3]*_t160*_t580 + _t1017*_t579 + _t1259*_t587);
  const double d3F_dta_dtb2 = _t1436*my_piecewise3(_t25, -_t1272*_t584 + 12.2462410087*_t1443*_t28 + 3.1013068102319998*_t1443*_t30 - _t1443*_t70 - _t1443*_t71 - _t1443*_t72 - _t1443*_t73 - 0.64000000000000001*_t1443 - _t1444*_t600 - _t1444*_t601 - 9.2141136272939992*_t1444 - _t1445*_t183 - _t1445*_t184 - _t1445*_t185 - _t1446*_t723 - _t1446*_t724 - _t1446*_t725 + 73.477446052200008*_t154*_t26*_t594 + 36.738723026100004*_t154*_t27*_t593 + 62.026136204639997*_t154*_t28*_t594 + 15.506534051159999*_t154*_t29*_t593 + 73.477446052200008*_t159*_t27*_t584 + 31.013068102319998*_t159*_t29*_t584 - _t585*_t593, _hc6[1]*my_piecewise3(_t24, _t1442, 0) + _hc6[3]*_t155*_t596 + _t1275*_t587 + _t588*_t595);
  const double d3F_dtb3 = _t1436*my_piecewise3(_t25, 12.2462410087*_t1448*_t28 + 3.1013068102319998*_t1448*_t30 - _t1448*_t70 - _t1448*_t71 - _t1448*_t72 - _t1448*_t73 - 0.64000000000000001*_t1448 + 73.477446052200008*_t1449*_t26 + 62.026136204639997*_t1449*_t28 - _t1449*_t600 - _t1449*_t601 - 9.2141136272939992*_t1449 - _t1450*_t603 - _t1450*_t604 - _t1450*_t605 - 2.6111999999999997*_t1450 + 110.21616907830001*_t159*_t27*_t593 + 46.519602153479994*_t159*_t29*_t593, _hc6[1]*my_piecewise3(_t24, _t1447, 0) + _hc6[3]*(_t160 * _t160 * _t160) + 0.3e1*_t1017*_t595);
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
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 1] += d3F_dna2_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 2] += d3F_dna_dnb_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 3] += d3F_dna_dnb_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 4] += d3F_dnb2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
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
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 1] += d3F_dna_dgaa_dtb;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 2] += d3F_dna_dgab_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 3] += d3F_dna_dgab_dtb;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 4] += d3F_dna_dgbb_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 5] += d3F_dna_dgbb_dtb;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 6] += d3F_dnb_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 7] += d3F_dnb_dgaa_dtb;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 8] += d3F_dnb_dgab_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 9] += d3F_dnb_dgab_dtb;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 10] += d3F_dnb_dgbb_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += d3F_dnb_dgbb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 1] += d3F_dna_dta_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 2] += d3F_dna_dtb2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 3] += d3F_dnb_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 4] += d3F_dnb_dta_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
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
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 1] += d3F_dgaa2_dtb;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 2] += d3F_dgaa_dgab_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 3] += d3F_dgaa_dgab_dtb;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 4] += d3F_dgaa_dgbb_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 5] += d3F_dgaa_dgbb_dtb;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 6] += d3F_dgab2_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 7] += d3F_dgab2_dtb;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 8] += d3F_dgab_dgbb_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 9] += d3F_dgab_dgbb_dtb;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 10] += d3F_dgbb2_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 11] += d3F_dgbb2_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 1] += d3F_dgaa_dta_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 2] += d3F_dgaa_dtb2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 3] += d3F_dgab_dta2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 4] += d3F_dgab_dta_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 5] += d3F_dgab_dtb2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 6] += d3F_dgbb_dta2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 7] += d3F_dgbb_dta_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 8] += d3F_dgbb_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 1] += d3F_dta2_dtb;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 2] += d3F_dta_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 3] += d3F_dtb3;
#endif
#endif
}
#endif