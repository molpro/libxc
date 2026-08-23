/*
  Generated from python/mgga_exc/mgga_c_r2scan.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_c_r2scan
*/

#ifndef _MGGA_C_R2SCAN_KERNEL_BODY
#define maple2c_order 2
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC)

/* ---- top-level dispatch ---- */

#define _MGGA_C_R2SCAN_KERNEL_BODY
#define _KMAX 0
#define _MGGA_C_R2SCAN_HELPER_BODIES
#include "mgga_c_r2scan.c"
#undef _MGGA_C_R2SCAN_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_C_R2SCAN_HELPER_BODIES
#include "mgga_c_r2scan.c"
#undef _MGGA_C_R2SCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_C_R2SCAN_HELPER_BODIES
#include "mgga_c_r2scan.c"
#undef _MGGA_C_R2SCAN_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_c_r2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_c_r2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_c_r2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_c_r2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_c_r2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_c_r2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_C_R2SCAN_HELPER_BODIES)

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
  const double _t13 = my_piecewise3(_t5, 0.1e1, 0);
  const double _t14 = _t6 + 0.1e1;
  const double _t15 = _t7 + 0.1e1;
  const double _t16 = my_piecewise3(_t10, -0.1e1, 0);
  const double _t17 = _t11 + 0.1e1;
  const double _t18 = _t12 + 0.1e1;

  const double f = _t1*(my_piecewise3(_t2, _t3, _t7) + my_piecewise3(_t8, _t3, _t12));
  out[0] = f;
  const double df_dz = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*_t13*_t15/_t14) + my_piecewise3(_t8, 0, (0.4e1 / 0.3e1)*_t16*_t18/_t17));
  out[1] = df_dz;
#if _KMAX >= 1
  const double d2f_dz2 = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)*(_t13 * _t13)*_t15/(_t14 * _t14)) + my_piecewise3(_t8, 0, (0.4e1 / 0.9e1)*(_t16 * _t16)*_t18/(_t17 * _t17)));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 2
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
  const double _t11 = my_piecewise3(_t4, 0.1e1, 0);
  const double _t12 = _t5 + 0.1e1;
  const double _t13 = _t10*_t11/_t12;
#endif
#if _KMAX >= 2
  const double _t14 = _t10*(_t11 * _t11)/(_t12 * _t12);
#endif

  const double f = my_piecewise3(_t1, _t2 - 0.1e1, _t8);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = my_piecewise3(_t1, _t2*_t9, _t10*_t6);
  out[1] = df_dn;
  const double df_dz = my_piecewise3(_t1, 0, _t13*n);
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = my_piecewise3(_t1, _t2*(_t9 * _t9), _t10*(_t6 * _t6));
  out[3] = d2f_dn2;
  const double d2f_dz_dn = my_piecewise3(_t1, 0, _t13*_t7 + _t13);
  out[4] = d2f_dz_dn;
  const double d2f_dz2 = my_piecewise3(_t1, 0, _t14*(n * n) - _t14*n);
  out[5] = d2f_dz2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mgga_alpha_total_reg_k, _KMAX)(const xc_func_type *p, double z, double xt, double ts0, double ts1, double eta, double *out) {

  double _hc0[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.5e1 / 0.3e1, _hc1);
  const double _t1 = (xt * xt);
  const double _t2 = (0.1e1 / 0.8e1)*_t1;
  const double _t3 = _t2*eta;
  const double _t4 = xc_powr(0.3e1, 2, 3)*(M_PI * M_CBRTPI);
  const double _t5 = (0.3e1 / 0.20e2)*_t4;
  const double _t6 = _t3 + _t5*(_hc0[0] + _hc1[0] + 0.2e1);
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = M_CBRT2;
  const double _t9 = _hc0[0] + 0.1e1;
  const double _t10 = _t9*ts0;
  const double _t11 = _hc1[0] + 0.1e1;
  const double _t12 = _t11*ts1;
  const double _t13 = -_t2 + (0.1e1 / 0.4e1)*_t8*(_t10 + _t12);
#if _KMAX >= 1
  const double _t14 = (0.1e1 / (_t6 * _t6));
  const double _t15 = _t13*_t14;
  const double _t16 = (0.1e1 / 0.4e1)*_t7;
  const double _t17 = _t16*_t8;
  const double _t18 = (0.1e1 / 0.4e1)*_t15;
  const double _t19 = _t18*xt;
  const double _t20 = _hc0[2]*ts0 - _hc1[2]*ts1;
  const double _t21 = _hc0[2] - _hc1[2];
  const double _t22 = _t15*_t5;
#endif
#if _KMAX >= 2
  const double _t23 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t24 = _t13*_t23;
  const double _t25 = _t11*_t8;
  const double _t26 = (0.1e1 / 0.32e2)*_t14;
  const double _t27 = _t1*_t26;
  const double _t28 = _t27*_t8;
  const double _t29 = (xt * xt * xt);
  const double _t30 = (0.1e1 / 0.16e2)*eta;
  const double _t31 = _t14*xt;
  const double _t32 = _t30*_t31;
  const double _t33 = _t32*_t8;
  const double _t34 = _t21*_t4;
  const double _t35 = (0.3e1 / 0.80e2)*_t34;
  const double _t36 = _t14*_t35;
  const double _t37 = (0.3e1 / 0.40e2)*_t34;
#endif

  const double f = _t13*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_deta = -_t15*_t2;
  out[1] = df_deta;
  const double df_dts1 = _t11*_t17;
  out[2] = df_dts1;
  const double df_dts0 = _t17*_t9;
  out[3] = df_dts0;
  const double df_dxt = -_t16*xt - _t19*eta;
  out[4] = df_dxt;
  const double df_dz = (0.1e1 / 0.4e1)*_t20*_t7*_t8 - _t21*_t22;
  out[5] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_deta2 = (0.1e1 / 0.32e2)*_t24*(xt * xt * xt * xt);
  out[6] = d2f_deta2;
  const double d2f_dts1_deta = -_t25*_t27;
  out[7] = d2f_dts1_deta;
  const double d2f_dts12 = 0;
  out[8] = d2f_dts12;
  const double d2f_dts0_deta = -_t28*_t9;
  out[9] = d2f_dts0_deta;
  const double d2f_dts0_dts1 = 0;
  out[10] = d2f_dts0_dts1;
  const double d2f_dts02 = 0;
  out[11] = d2f_dts02;
  const double d2f_dxt_deta = -_t19 + _t24*_t29*_t30 + _t26*_t29;
  out[12] = d2f_dxt_deta;
  const double d2f_dxt_dts1 = -_t25*_t32;
  out[13] = d2f_dxt_dts1;
  const double d2f_dxt_dts0 = -_t33*_t9;
  out[14] = d2f_dxt_dts0;
  const double d2f_dxt2 = _t14*_t3 - _t16 - _t18*eta + _t2*_t24*(eta * eta);
  out[15] = d2f_dxt2;
  const double d2f_dz_deta = _t1*_t24*_t35 - _t20*_t28;
  out[16] = d2f_dz_deta;
  const double d2f_dz_dts1 = -_hc1[2]*_t17 - _t25*_t36;
  out[17] = d2f_dz_dts1;
  const double d2f_dz_dts0 = _hc0[2]*_t17 - _t36*_t8*_t9;
  out[18] = d2f_dz_dts0;
  const double d2f_dz_dxt = -_t20*_t33 + _t24*_t37*eta*xt + _t31*_t35;
  out[19] = d2f_dz_dxt;
  const double d2f_dz2 = -_t14*_t20*_t37*_t8 + _t17*(_hc0[5]*ts0 + _hc1[5]*ts1) + M_CBRT3*(M_PI * M_PI * M_CBRTPI * M_CBRTPI)*(_t21 * _t21)*_t23*(-0.27e2 / 0.1600e4*_t1 + (0.27e2 / 0.200e3)*_t8*((0.1e1 / 0.4e1)*_t10 + (0.1e1 / 0.4e1)*_t12)) - _t22*(_hc0[5] + _hc1[5]);
  out[20] = d2f_dz2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 2 ? 4 : (_KMAX) >= 1 ? 3 : 2];
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
#if _KMAX >= 1
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
#if _KMAX >= 2
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
  const double df_dzeta = -_hc0[1]*_t15 + _hc0[1]*_t23 + _t25*_t26;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t27 + _hc0[0]*_t45 - _hc0[0]*_t48 + _t43;
  out[2] = df_drs;
#if _KMAX >= 1
  const double d2f_dzeta2 = -_hc0[2]*_t15 + _hc0[2]*_t23 + _t25*_t52 + _t49*_t51;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t27 + _hc0[1]*_t45 - _hc0[1]*_t48 + _t26*_t53;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[0]*_t55 - _hc0[0]*_t63 + _hc0[0]*_t73 - _hc0[0]*_t82 + _hc0[0]*_t95 + _t1*_t68 - _t54 + _t60 + _t77;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 2
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeta_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 0.0066724550603149224*rs + 0.06672455060314922;
  const double _t2 = 0.17780000000000001*rs + 0.1e1;
  const double _t3 = (0.1e1 / _t2);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (_t2 * _t2));
#endif

  const double f = _t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.17780000000000001*_t1*_t4 + 0.0066724550603149224*_t3;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.063225680000000006*_t1/(_t2 * _t2 * _t2) - 0.0023727250194479866*_t4;
  out[2] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w1_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 6 : 3];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc2);
  const double _t1 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t2 = 0.1e1 - M_LN2;
  const double _t3 = (M_PI * M_PI)/_t2;
  const double _t4 = _t3/(_t1 * _t1 * _t1);
  const double _t5 = xc_expm1(-_hc2[0]*_t4);
#if _KMAX >= 1
  const double _t6 = _t5 + 0.1e1;
  const double _t7 = -0.3e1 / 0.2e1*_hc0[2] + (0.3e1 / 0.2e1)*_hc1[2];
  const double _t8 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t9 = _hc2[0]*_t3*_t8;
  const double _t10 = -_hc2[1]*_t4 - _t7*_t9;
  const double _t11 = _t10*_t6;
  const double _t12 = _t4*_t6;
#endif
#if _KMAX >= 2
  const double _t13 = _t3*_t7;
  const double _t14 = _t13*_t8;
#endif

  const double f = _t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t11;
  out[1] = df_dz;
  const double df_drs = -_hc2[2]*_t12;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (_t10 * _t10)*_t6 + _t6*(-_hc2[0]*_t13*(-0.2e1*_hc0[2] + 0.2e1*_hc1[2])/xc_powi(_t1, 5) - 0.2e1*_hc2[1]*_t14 - _hc2[3]*_t4 - _t9*(-0.3e1 / 0.2e1*_hc0[5] - 0.3e1 / 0.2e1*_hc1[5]));
  out[3] = d2f_dz2;
  const double d2f_drs_dz = -_hc2[2]*_t11*_t4 - _hc2[2]*_t14*_t6 - _hc2[4]*_t12;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = (M_PI * M_PI * M_PI * M_PI)*((_hc2[2]) * (_hc2[2]))*_t6/(xc_powi(_t1, 6)*(_t2 * _t2)) - _hc2[5]*_t12;
  out[5] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_d_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
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
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_eclda0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(rs, 1, 2);
  const double _t2 = 0.088900000000000007*_t1 + 0.12554100000000001*rs + 0.1e1;
  const double _t3 = (0.1e1 / (_t2 * _t2));
  const double _t4 = (0.1e1 / _t1);
  const double _t5 = -0.044450000000000003*_t4 - 0.12554100000000001;
  const double _t6 = 0.028576399999999998*_t5;
#if _KMAX >= 1
  const double _t7 = xc_powr(rs, -3, 2);
  const double _t8 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t9 = -0.088900000000000007*_t4 - 0.25108200000000003;
  const double _t10 = _t8*_t9;
#endif
#if _KMAX >= 2
  const double _t11 = 0.0012702209800000001*_t7;
#endif

  const double f = -0.028576399999999998/_t2;
  out[0] = f;
  const double df_drs = -_t3*_t6;
  out[1] = df_drs;
#if _KMAX >= 1
  const double d2f_drs2 = -_t10*_t6 - 0.00063511049000000003*_t3*_t7;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 2
  const double d3f_drs3 = -_t10*_t11 - _t11*_t5*_t8 + 0.00095266573499999999*_t3/xc_powr(rs, 5, 2) - _t6*_t9*(-0.13335000000000002*_t4 - 0.37662300000000004)/(_t2 * _t2 * _t2 * _t2);
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_elsda1_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 6 : 3];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc0);

  const double f = _hc0[0];
  out[0] = f;
  const double df_dz = _hc0[1];
  out[1] = df_dz;
  const double df_drs = _hc0[2];
  out[2] = df_drs;
#if _KMAX >= 1
  const double d2f_dz2 = _hc0[3];
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[4];
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[5];
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 2
  const double d3f_dz3 = _hc0[6];
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[7];
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc0[8];
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[9];
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_delsda1_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 6 : 3];
  XC_CAT(r2scan_elsda1_k, _KMAX)(p, rs, z, _hc0);

  const double f = _hc0[2];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[4];
  out[1] = df_dz;
  const double df_drs = _hc0[5];
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[7];
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[8];
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[9];
  out[5] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_y_k, _KMAX)(const xc_func_type *p, double rs, double z, double t, double *out) {

  double _hc0[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(w1_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, rs, _hc1);
  const double _t1 = (t * t);
  const double _t2 = (M_PI * M_PI);
  const double _t3 = (0.1e1 / (0.1e1 - M_LN2));
  const double _t4 = _t2*_t3/_hc0[0];
  const double _t5 = _t1*_t4;
#if _KMAX >= 1
  const double _t6 = 0.2e1*_t4;
  const double _t7 = _hc1[0]*_t6;
  const double _t8 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t9 = _hc1[0]*_t1*_t2*_t3;
  const double _t10 = _t8*_t9;
#endif
#if _KMAX >= 2
  const double _t11 = _t2*_t3*_t8;
  const double _t12 = _hc0[1]*_t11;
  const double _t13 = 0.2e1*_hc1[0]*t;
  const double _t14 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t15 = _hc0[2]*_t11;
  const double _t16 = _hc1[1]*_t1;
#endif

  const double f = _hc1[0]*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t7*t;
  out[1] = df_dt;
  const double df_dz = -_hc0[1]*_t10;
  out[2] = df_dz;
  const double df_drs = -_hc0[2]*_t10 + _hc1[1]*_t5;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t7;
  out[4] = d2f_dt2;
  const double d2f_dz_dt = -_t12*_t13;
  out[5] = d2f_dz_dt;
  const double d2f_dz2 = 0.2e1*((_hc0[1]) * (_hc0[1]))*_hc1[0]*_t1*_t14*_t2*_t3 - _hc0[3]*_t10;
  out[6] = d2f_dz2;
  const double d2f_drs_dt = _hc1[1]*_t6*t - _t13*_t15;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dz = 0.2e1*_hc0[1]*_hc0[2]*_hc1[0]*_t1*_t14*_t2*_t3 - _hc0[4]*_t10 - _t12*_t16;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = 0.2e1*((_hc0[2]) * (_hc0[2]))*_t14*_t9 - _hc0[5]*_t10 + _hc1[2]*_t5 - 0.2e1*_t15*_t16;
  out[9] = d2f_drs2;
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

  const double f = -_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = 0.2560517052525163*_t5*_t6*s;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = -0.32781237881360742*_t1*_t6/(_t4 * _t4) + 0.2560517052525163*_t5*_t6;
  out[2] = d2f_ds2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_H0_k, _KMAX)(const xc_func_type *p, double rs, double s, double *out) {

  double _hc0[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_one_minus_g_infty_k, _KMAX)(p, s, _hc0);
  double _hc1[(_KMAX) >= 2 ? 4 : (_KMAX) >= 1 ? 3 : 2];
  XC_CAT(scan_eclda0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = xc_expm1(-34.99391105947565*_hc1[0]);
  const double _t2 = _hc0[0]*_t1;
#if _KMAX >= 1
  const double _t3 = _t2 + 0.1e1;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _hc0[1]*_t4;
  const double _t6 = _t1 + 0.1e1;
  const double _t7 = 0.99999999999999989*_hc1[1]*_t6;
  const double _t8 = _hc0[0]*_t4;
#endif
#if _KMAX >= 2
  const double _t9 = (0.1e1 / (_t3 * _t3));
  const double _t10 = ((_hc1[1]) * (_hc1[1]));
#endif

  const double f = 0.028576399999999998*xc_log1p(_t2);
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = 0.028576399999999998*_t1*_t5;
  out[1] = df_ds;
  const double df_drs = -_t7*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = -0.028576399999999998*((_hc0[1]) * (_hc0[1]))*(_t1 * _t1)*_t9 + 0.028576399999999998*_hc0[2]*_t1*_t4;
  out[3] = d2f_ds2;
  const double d2f_drs_ds = _hc0[1]*_t2*_t7*_t9 - _t5*_t7;
  out[4] = d2f_drs_ds;
  const double d2f_drs2 = -34.993911059475643*((_hc0[0]) * (_hc0[0]))*_t10*(_t6 * _t6)*_t9 + 34.993911059475643*_hc0[0]*_t10*_t4*_t6 - 0.99999999999999989*_hc1[2]*_t6*_t8;
  out[5] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_f_alpha_large_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = 0.1e1 - a;
  const double _t2 = exp(1.5/_t1);

  const double f = -0.69999999999999996*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -1.0499999999999998*_t2/(_t1 * _t1);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -2.0999999999999996*_t2/(_t1 * _t1 * _t1) - 1.5749999999999997*_t2/(_t1 * _t1 * _t1 * _t1);
  out[2] = d2f_da2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_f_alpha_neg_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = 0.1e1 - a;
  const double _t2 = 0.64000000000000001/_t1;
  const double _t3 = exp(-_t2*a);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (_t1 * _t1));
  const double _t5 = -_t2 - 0.64000000000000001*_t4*a;
#endif

  const double f = _t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t3*_t5;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t3*(_t5 * _t5) + _t3*(-1.28*_t4 - 1.28*a/(_t1 * _t1 * _t1));
  out[2] = d2f_da2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 0.01328816518*rs + 0.062181399999999998;
  const double _t2 = -_t1;
  const double _t3 = xc_powr(rs, 1, 2);
  const double _t4 = 0.47231125997999995*_t3 + 0.030651699315999998*(rs * rs) + 0.22308199064000001*rs + 0.10186556948*pow(rs, 1.5);
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = xc_log1p(_t5);
#if _KMAX >= 1
  const double _t7 = sqrt(rs);
  const double _t8 = (0.1e1 / _t3);
  const double _t9 = -0.15279835421999999*_t7 - 0.23615562998999998*_t8 - 0.061303398631999996*rs - 0.22308199064000001;
  const double _t10 = (0.1e1 / (_t4 * _t4));
  const double _t11 = _t5 + 0.1e1;
  const double _t12 = (0.1e1 / _t11);
#endif
#if _KMAX >= 2
  const double _t13 = _t12*_t2;
#endif

  const double f = _t2*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t12*_t2*_t9 - 0.01328816518*_t6;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1*(_t9 * _t9)/((_t11 * _t11)*(_t4 * _t4 * _t4 * _t4)) - 0.026576330360000001*_t10*_t12*_t9 + _t10*_t13*(-0.061303398631999996 + 0.11807781499499999/xc_powr(rs, 3, 2) - 0.076399177109999994/_t7) + _t13*_t9*(-0.30559670843999998*_t7 - 0.47231125997999995*_t8 - 0.12260679726399999*rs - 0.44616398128000001)/(_t4 * _t4 * _t4);
  out[2] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w1_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc0);
  const double _t1 = 0.1e1 - M_LN2;
  const double _t2 = (M_PI * M_PI)/_t1;
  const double _t3 = xc_expm1(-_hc0[0]*_t2);
#if _KMAX >= 1
  const double _t4 = _t3 + 0.1e1;
  const double _t5 = _t2*_t4;
#endif

  const double f = _t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_hc0[1]*_t5;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (M_PI * M_PI * M_PI * M_PI)*((_hc0[1]) * (_hc0[1]))*_t4/(_t1 * _t1) - _hc0[2]*_t5;
  out[2] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_y_z0_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {

  double _hc0[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w1_z0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, rs, _hc1);
  const double _t1 = (t * t);
  const double _t2 = (M_PI * M_PI);
  const double _t3 = (0.1e1 / (0.1e1 - M_LN2));
  const double _t4 = _t2*_t3/_hc0[0];
  const double _t5 = _t1*_t4;
#if _KMAX >= 1
  const double _t6 = 0.2e1*_t4;
  const double _t7 = _hc1[0]*_t6;
  const double _t8 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t9 = _hc1[0]*_t1*_t2*_t3;
  const double _t10 = _t8*_t9;
#endif
#if _KMAX >= 2
  const double _t11 = 0.2e1*_hc0[1]*_t2*_t3*_t8;
#endif

  const double f = _hc1[0]*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t7*t;
  out[1] = df_dt;
  const double df_drs = -_hc0[1]*_t10 + _hc1[1]*_t5;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t7;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = -_hc1[0]*_t11*t + _hc1[1]*_t6*t;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = -_hc0[2]*_t10 - _hc1[1]*_t1*_t11 + _hc1[2]*_t5 + 0.2e1*((_hc0[1]) * (_hc0[1]))*_t9/((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  out[5] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_elsda1_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[1];
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[2];
  out[2] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_delsda1_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 6 : 3];
  XC_CAT(r2scan_elsda1_k, _KMAX)(p, rs, 0, _hc0);

  const double f = _hc0[2];
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[5];
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[9];
  out[2] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mgga_alpha_total_reg_z0_k, _KMAX)(const xc_func_type *p, double xt, double ts0, double ts1, double eta, double *out) {

  const double _t1 = (xt * xt);
  const double _t2 = (0.1e1 / 0.8e1)*_t1;
  const double _t3 = M_CBRT2;
  const double _t4 = -_t2 + (0.1e1 / 0.4e1)*_t3*(ts0 + ts1);
  const double _t5 = _t2*eta;
  const double _t6 = _t5 + (0.3e1 / 0.10e2)*xc_powr(0.3e1, 2, 3)*(M_PI * M_CBRTPI);
  const double _t7 = (0.1e1 / _t6);
#if _KMAX >= 1
  const double _t8 = (0.1e1 / (_t6 * _t6));
  const double _t9 = _t4*_t8;
  const double _t10 = (0.1e1 / 0.4e1)*_t7;
  const double _t11 = _t10*_t3;
  const double _t12 = (0.1e1 / 0.4e1)*_t9;
  const double _t13 = _t12*xt;
#endif
#if _KMAX >= 2
  const double _t14 = _t4/(_t6 * _t6 * _t6);
  const double _t15 = (0.1e1 / 0.32e2)*_t8;
  const double _t16 = -_t1*_t15*_t3;
  const double _t17 = (xt * xt * xt);
  const double _t18 = (0.1e1 / 0.16e2)*eta;
  const double _t19 = -_t18*_t3*_t8*xt;
#endif

  const double f = _t4*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_deta = -_t2*_t9;
  out[1] = df_deta;
  const double df_dts1 = _t11;
  out[2] = df_dts1;
  const double df_dts0 = _t11;
  out[3] = df_dts0;
  const double df_dxt = -_t10*xt - _t13*eta;
  out[4] = df_dxt;
#endif
#if _KMAX >= 2
  const double d2f_deta2 = (0.1e1 / 0.32e2)*_t14*(xt * xt * xt * xt);
  out[5] = d2f_deta2;
  const double d2f_dts1_deta = _t16;
  out[6] = d2f_dts1_deta;
  const double d2f_dts12 = 0;
  out[7] = d2f_dts12;
  const double d2f_dts0_deta = _t16;
  out[8] = d2f_dts0_deta;
  const double d2f_dts0_dts1 = 0;
  out[9] = d2f_dts0_dts1;
  const double d2f_dts02 = 0;
  out[10] = d2f_dts02;
  const double d2f_dxt_deta = -_t13 + _t14*_t17*_t18 + _t15*_t17;
  out[11] = d2f_dxt_deta;
  const double d2f_dxt_dts1 = _t19;
  out[12] = d2f_dxt_dts1;
  const double d2f_dxt_dts0 = _t19;
  out[13] = d2f_dxt_dts0;
  const double d2f_dxt2 = -_t10 - _t12*eta + _t14*_t2*(eta * eta) + _t5*_t8;
  out[14] = d2f_dxt2;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_c_r2scan_params *params = (const mgga_c_r2scan_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double ta = tau[0];

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = M_CBRTPI;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = _t1*_t5;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = xc_powr(gaa, 1, 2);
  const double _t9 = xc_powr(M_PI, 1, 6);
  const double _t10 = xc_powr(0.3e1, 5, 6)*_t9;
  const double _t11 = _t10*_t8;
  const double _t12 = xc_powr(na, -7, 6);
  const double _t13 = (0.1e1 / 0.12e2)*_t12;
  const double _t14 = xc_powr(na, -4, 3);
  const double _t15 = _t14*_t8;
  const double _t16 = xc_powr(0.3e1, 2, 3);
  const double _t17 = (M_CBRTPI * M_CBRTPI);
  const double _t18 = (0.1e1 / _t17);
  const double _t19 = _t16*_t18;
  const double _t20 = xc_powr(0.2e1, 2, 3);
  const double _t21 = _t20/xc_powr(na, 5, 3);
  const double _t22 = _t21*ta;
  const double _t31 = xc_powr(na, -8, 3);
  const double _t32 = M_CBRT3;
  const double _t34 = M_LN2;
  const double _t35 = 0.1e1 - _t34;
  const double _t36 = (0.1e1 / _t35);
  const double _t37 = (gaa * gaa);
  const double _t38 = xc_powr(na, -16, 3);
  const double _t39 = exp(-0.40889208157792739*_t16*_t37*_t38/(M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t40 = _t36*_t39;
  const double _t50 = (0.1e1 / (M_PI * M_PI));
  const double _t51 = _t35*_t50;
  double _hc0[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, _t7, _hc0);
  double _hc1[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w1_z0_k, _KMAX)(p, _t7, _hc1);
  double _hc2[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(r2scan_y_z0_k, _KMAX)(p, _t7, _t11*_t13, _hc2);
  double _hc3[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(r2scan_elsda1_z0_k, _KMAX)(p, _t7, _hc3);
  double _hc4[(_KMAX) >= 2 ? 4 : (_KMAX) >= 1 ? 3 : 2];
  XC_CAT(scan_eclda0_k, _KMAX)(p, _t7, _hc4);
  double _hc5[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(r2scan_delsda1_z0_k, _KMAX)(p, _t7, _hc5);
  double _hc6[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_H0_k, _KMAX)(p, _t7, (0.1e1 / 0.6e1)*_t15*_t19, _hc6);
  double _hc7[(_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(mgga_alpha_total_reg_z0_k, _KMAX)(p, _t15, _t22, _t22, params->eta, _hc7);
  const double _t23 = _hc7[0] > 0;
  const double _t24 = 1.0*_hc7[0] - 2.5;
  const double _t25 = _t24 > 0;
  const double _t26 = -_hc4[0];
  const double _t27 = params->eta*(-_hc3[0] - _t26);
  const double _t28 = 0.45e2*_t27;
  const double _t29 = _hc4[1] - _hc5[0];
  const double _t30 = 0.10e2*_t1*_t2*_t29*_t4 - _t28;
  const double _t33 = (0.1e1 / (_hc1[0]));
  const double _t41 = _t33*_t40;
  const double _t42 = _t17*_t41;
  const double _t43 = _t32*_t42;
  const double _t44 = _t31*_t43;
  const double _t45 = 0.0087827448677654102*_t44;
  const double _t46 = _t30*_t45;
  const double _t47 = 0.4e1*_hc2[0] + _t46*gaa;
  const double _t48 = xc_expm1(-0.1e1 / 0.4e1*xc_log1p(_t47));
  const double _t49 = _hc1[0]*_t48;
  const double _t52 = _hc0[0] + _t51*xc_log1p(-_t49);
  const double _t53 = _hc6[0] - _t26 - _t52;
  const double _t54 = _hc7[0] <= 0;
  const double _t55 = _t24 <= 0;
  const double _t56 = my_piecewise3(_t25, 2.5, _hc7[0]);
  const double _t57 = (_t56 * _t56);
  const double _t58 = (_t56 * _t56 * _t56);
  const double _t59 = (_t56 * _t56 * _t56 * _t56);
  const double _t60 = xc_powi(_t56, 5);
  const double _t61 = xc_powi(_t56, 6);
  double _hc8[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(r2scan_f_alpha_neg_k, _KMAX)(p, my_piecewise3(_t23, 0, _hc7[0]), _hc8);
  double _hc9[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(rscan_f_alpha_large_k, _KMAX)(p, my_piecewise3(_t25, _hc7[0], 2.5), _hc9);
  const double _t62 = my_piecewise5(_t54, _hc8[0], _t55, -0.051848879792000001*xc_powi(_t56, 7) - 0.64000000000000001*_t56 - 0.43519999999999998*_t57 - 1.5356856045489999*_t58 + 3.0615602521750001*_t59 - 1.9157102362059999*_t60 + 0.51688446837199997*_t61 + 0.1e1, _hc9[0]);
  const double _t63 = _t52 + _t53*_t62;
  const double zk = _t63;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t65 = xc_powr(na, -7, 3);
  const double _t66 = (0.4e1 / 0.3e1)*_t65;
  const double _t68 = (0.5e1 / 0.3e1)*_t31;
  const double _t70 = _t20*_t68;
  const double _t82 = _t14*_t5;
  const double _t83 = (0.1e1 / 0.6e1)*_t82;
  const double _t86 = (0.2e1 / 0.9e1)*_t65;
  const double _t88 = (gaa * gaa * gaa);
  const double _t89 = xc_powi(na, -9);
  const double _t94 = xc_powr(na, -11, 3);
  const double _t95 = _t32*_t94;
  const double _t102 = 0.0014637908112942349*_t40;
  const double _t106 = (0.1e1 / (na * na * na * na));
  const double _t107 = xc_powr(0.18e2, 1, 3);
  const double _t108 = _t107*_t3;
  const double _t109 = _t106*_t108;
  const double _t111 = xc_powr(na, -13, 6);
  const double _t112 = _t11*_t111;
  const double _t129 = (0.1e1 / _t8);
  const double _t131 = (0.1e1 / 0.2e1)*_t14;
  const double _t144 = xc_powi(na, -8);
  const double _t64 = _hc7[4]*_t8;
  const double _t75 = 0.87039999999999995*_t56;
  const double _t76 = 4.6070568136469996*_t57;
  const double _t77 = 9.578551181029999*_t59;
  const double _t78 = 0.36294215854400003*_t61;
  const double _t84 = _hc4[1]*_t83;
  const double _t85 = _hc6[1]*_t19;
  const double _t87 = _hc1[1]*_t48;
  const double _t90 = 2.585660278282889*_t27;
  const double _t91 = 0.5745911729517531*_hc4[1] - 0.5745911729517531*_hc5[0];
  const double _t92 = _t1*_t2*_t4*(0.10e2*_hc4[1] - 0.10e2*_hc5[0]) - _t28;
  const double _t93 = _t92*gaa;
  const double _t96 = _t42*_t95;
  const double _t97 = 0.023420652980707758*_t96;
  const double _t98 = params->eta*(_hc3[1]*_t83 - _t84);
  const double _t99 = 0.45e2*_t98;
  const double _t100 = _t6*(-0.5e1 / 0.3e1*_hc4[2]*_t82 + (0.5e1 / 0.3e1)*_hc5[1]*_t14*_t2*_t4) + _t82*(-0.10e2 / 0.3e1*_hc4[1] + (0.10e2 / 0.3e1)*_hc5[0]) - _t99;
  const double _t101 = _t45*gaa;
  const double _t103 = _t102*_t93;
  const double _t104 = ((_hc1[0]) * (_hc1[0]));
  const double _t105 = (0.1e1 / _t104);
  const double _t110 = _t105*_t109;
  const double _t113 = (0.7e1 / 0.18e2)*_hc2[1]*_t112 + (0.2e1 / 0.3e1)*_hc2[2]*_t82;
  const double _t114 = -_hc1[1]*_t103*_t110 - _t100*_t101 + _t113 + _t93*_t97;
  const double _t115 = -_t114 + _t33*_t36*_t39*_t50*_t88*_t89*(_t1*_t2*_t4*_t91 - _t90);
  const double _t116 = _t48 + 0.1e1;
  const double _t117 = _hc1[0]*_t116;
  const double _t118 = _t115*_t117;
  const double _t119 = _t47 + 0.1e1;
  const double _t120 = (0.1e1 / _t119);
  const double _t121 = (0.1e1 / 0.4e1)*_t120;
  const double _t122 = _t118*_t121 + _t83*_t87;
  const double _t123 = 0.1e1 - _t49;
  const double _t124 = _t51/_t123;
  const double _t125 = _t122*_t124;
  const double _t126 = -_hc0[1]*_t83 + _t125;
  const double _t127 = -_hc6[2]*_t83 - _t126 - _t8*_t85*_t86 - _t84;
  const double _t130 = _hc7[4]*_t129;
  const double _t132 = _t130*_t131;
  const double _t133 = my_piecewise3(_t23, 0, _t132);
  const double _t134 = my_piecewise3(_t25, 0, _t132);
  const double _t135 = my_piecewise3(_t25, _t132, 0);
  const double _t137 = _hc2[1]*_t10;
  const double _t138 = _t129*_t137;
  const double _t139 = (0.1e1 / 0.6e1)*_t12*_t138;
  const double _t140 = 0.39522351904944347*_t27;
  const double _t141 = 0.087827448677654102*_hc4[1] - 0.087827448677654102*_hc5[0];
  const double _t142 = 0.96962260435608338*_t27;
  const double _t143 = 0.21547168985690743*_hc4[1] - 0.21547168985690743*_hc5[0];
  const double _t145 = _t41*_t50;
  const double _t146 = _t145*_t37;
  const double _t147 = _t144*_t146;
  const double _t148 = _t139 + _t147*(_t142 - _t143*_t6) + _t44*(_t1*_t141*_t2*_t4 - _t140);
  const double _t149 = _t117*_t121;
  const double _t150 = _t124*_t149;
  const double _t151 = _t148*_t150;
  const double _t152 = (0.1e1 / 0.12e2)*_hc6[1]*_t129*_t14*_t16*_t18 - _t151;
  double _hc10[(_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(mgga_alpha_total_reg_z0_k, _KMAX)(p, _t15, 0, 0, params->eta, _hc10);
  const double _t67 = _hc10[2]*_t20;
  const double _t69 = _t67*_t68;
  const double _t71 = _hc10[3]*_t70;
  const double _t72 = -_t64*_t66 - _t69*ta - _t71*ta;
  const double _t73 = my_piecewise3(_t23, 0, _t72);
  const double _t74 = my_piecewise3(_t25, 0, _t72);
  const double _t79 = my_piecewise3(_t25, _t72, 0);
  const double _t80 = my_piecewise5(_t54, _hc8[1]*_t73, _t55, 12.2462410087*_t58*_t74 + 3.1013068102319998*_t60*_t74 - _t74*_t75 - _t74*_t76 - _t74*_t77 - _t74*_t78 - 0.64000000000000001*_t74, _hc9[1]*_t79);
  const double _t81 = _t53*_t80;
  const double _t128 = _t127*_t62;
  const double _t136 = my_piecewise5(_t54, _hc8[1]*_t133, _t55, 12.2462410087*_t134*_t58 + 3.1013068102319998*_t134*_t60 - _t134*_t75 - _t134*_t76 - _t134*_t77 - _t134*_t78 - 0.64000000000000001*_t134, _hc9[1]*_t135);
  const double _t153 = _t136*_t53 + _t151 + _t152*_t62;
  const double _t154 = _hc10[2]*_t21 + _hc10[3]*_t21;
  const double _t155 = my_piecewise3(_t23, 0, _t154);
  const double _t156 = my_piecewise3(_t25, 0, _t154);
  const double _t157 = my_piecewise3(_t25, _t154, 0);
  const double _t158 = my_piecewise5(_t54, _hc8[1]*_t155, _t55, 12.2462410087*_t156*_t58 + 3.1013068102319998*_t156*_t60 - _t156*_t75 - _t156*_t76 - _t156*_t77 - _t156*_t78 - 0.64000000000000001*_t156, _hc9[1]*_t157);
  const double _t159 = _t158*_t53;
  const double dF_dna = _t63 + na*(_t126 + _t128 + _t81);
  const double dF_dgaa = _t153*na;
  const double dF_dta = _t159*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double _t160 = xc_powr(na, -10, 3);
  const double _t161 = (0.40e2 / 0.9e1)*_t94*ta;
  const double _t162 = _t20*ta;
  const double _t164 = xc_powi(na, -5);
  const double _t165 = (0.20e2 / 0.9e1)*_t164*_t8;
  const double _t167 = _t66*_t8;
  const double _t168 = _t70*ta;
  const double _t177 = _t19*_t8*_t86;
  const double _t178 = xc_powr(0.6e1, 2, 3);
  const double _t180 = _t5*_t65;
  const double _t181 = (0.2e1 / 0.9e1)*_t180;
  const double _t182 = _t178*_t18*_t31;
  const double _t183 = (0.1e1 / 0.36e2)*_t182;
  const double _t191 = _t20*_t38;
  const double _t198 = (0.10e2 / 0.9e1)*_t82;
  const double _t199 = (0.20e2 / 0.9e1)*_t180;
  const double _t200 = (0.5e1 / 0.18e2)*_t182;
  const double _t202 = (0.5e1 / 0.6e1)*_t106*_t129;
  const double _t210 = M_CBRT2*_t129;
  const double _t214 = 0.035911948309484576*_t82;
  const double _t222 = 0.1e1 / 0.16e2 - 0.1e1 / 0.16e2*_t34;
  const double _t224 = (0.1e1 / gaa);
  const double _t225 = xc_powr(gaa, -3, 2);
  const double _t228 = _t224*_t31;
  const double _t229 = _t14*_t225;
  const double _t171 = 9.2141136272939992*_t56;
  const double _t172 = 38.314204724119996*_t58;
  const double _t173 = 2.1776529512640002*_t60;
  const double _t175 = (0.1e1 / (_t123 * _t123));
  const double _t176 = (_t122 * _t122);
  const double _t179 = -0.2e1 / 0.9e1*_hc4[1]*_t2*_t4*_t65 - 0.1e1 / 0.36e2*_hc4[2]*_t178*_t18*_t31;
  const double _t184 = (0.1e1 / (_t119 * _t119));
  const double _t185 = (0.1e1 / 0.16e2)*_t184;
  const double _t186 = _t117*_t185;
  const double _t187 = _hc1[1]*_t116*_t120*_t82;
  const double _t188 = _t145*_t88;
  const double _t189 = _t188*_t89;
  const double _t190 = (0.7e1 / 0.108e3)*_hc2[4];
  const double _t192 = _t105*_t40;
  const double _t193 = _t192*_t93;
  const double _t194 = _t16*_t41/(M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t195 = _hc1[1]*_t92;
  const double _t196 = _t192*_t195*_t2/(M_PI * M_PI * M_CBRTPI);
  const double _t197 = _t100*gaa;
  const double _t209 = _hc6[3]/(M_PI * M_CBRTPI);
  const double _t211 = -_t139 + _t147*(_t1*_t143*_t2*_t4 - _t142) + _t44*(_t140 - _t141*_t6);
  const double _t212 = (0.1e1 / 0.4e1)*_t184;
  const double _t220 = ((_t139 - 0.021547168985690743*_t147*_t30 + _t46) * (_t139 - 0.021547168985690743*_t147*_t30 + _t46));
  const double _t221 = _t124*_t186*_t220;
  const double _t223 = _t104*(_t116 * _t116)*_t175*_t184*_t220*_t50;
  const double _t227 = _t117*_t124*_t148*_t211*_t212;
  const double _t230 = (0.1e1 / 0.4e1)*_hc7[14]*_t228 - 0.1e1 / 0.4e1*_hc7[4]*_t229;
  const double _t231 = (_t134 * _t134);
  const double _t232 = my_piecewise3(_t25, 0, _t230);
  double _hc11[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(r2scan_y_z0_k, _KMAX)(p, _t7, 0, _hc11);
  const double _t163 = _hc10[12]*_t162;
  const double _t166 = _hc10[13]*_t162;
  const double _t169 = _hc10[3]*_t161*_t20 + (0.28e2 / 0.9e1)*_t160*_t64 + _t161*_t67 + _t163*_t165 + _t165*_t166 - _t167*(-_hc10[12]*_t168 - _hc10[13]*_t168 - _hc7[14]*_t167);
  const double _t170 = (_t74 * _t74);
  const double _t174 = my_piecewise3(_t25, 0, _t169);
  const double _t201 = _hc0[1]*_t181 + _hc0[2]*_t183 + _t124*((0.1e1 / 0.4e1)*_hc1[0]*_t115*_t116*_t184*(_t114 + _t189*(-_t6*_t91 + _t90)) + (0.1e1 / 0.4e1)*_hc1[0]*_t116*_t120*(-0.009758605408628232*_hc1[1]*_t108*_t164*_t193 + 0.0029275816225884698*_hc1[1]*_t109*_t192*_t197 - 0.00073189540564711744*_hc1[2]*_t191*_t193 + (0.91e2 / 0.108e3)*_hc2[1]*_t11/xc_powr(na, 19, 6) + (0.8e1 / 0.9e1)*_hc2[2]*_t180 + _t101*(_t180*((0.40e2 / 0.9e1)*_hc4[1] - 0.40e2 / 0.9e1*_hc5[0]) + _t6*(_hc4[2]*_t199 + _hc4[3]*_t200 - _hc5[1]*_t199 - _hc5[2]*_t200) + _t82*(_hc4[2]*_t198 - _hc5[1]*_t198) - 0.45e2*params->eta*(-_hc3[1]*_t181 - _hc3[2]*_t183 - _t179)) + _t112*((0.49e2 / 0.1296e4)*_hc11[3]*_t112 + _t190*_t82) + _t188*(30.166036579967038*_t27 + _t6*(-6.7035636844371194*_hc4[1] + 6.7035636844371194*_hc5[0]))/xc_powi(na, 10) + _t189*(_t6*(-0.19153039098391772*_hc4[2]*_t82 + 0.19153039098391772*_hc5[1]*_t14*_t2*_t4) + _t82*(-0.38306078196783544*_hc4[1] + 0.38306078196783544*_hc5[0]) - 5.171320556565778*_t98) + _t194*xc_powi(gaa, 5)*(_t1*_t2*_t4*(1.2530441640775745*_hc4[1] - 1.2530441640775745*_hc5[0]) - 5.6386987383490847*_t27)/xc_powr(na, 46, 3) + 0.019153039098391771*_t196*_t88/xc_powr(na, 31, 3) - 0.046841305961415516*_t197*_t96 + 0.085875727595928444*_t43*_t93/xc_powr(na, 14, 3) + _t82*((0.1e1 / 0.9e1)*_hc2[5]*_t82 + _t112*_t190) + ((_hc1[1]) * (_hc1[1]))*_t103*_t191/((_hc1[0]) * (_hc1[0]) * (_hc1[0]))) - _hc1[2]*_t183*_t48 - 0.1e1 / 0.12e2*_t115*_t187 - _t181*_t87 - _t186*((0.0014637908112942349*_hc1[1]*_t105*_t106*_t107*_t3*_t30*_t36*_t39*gaa - _t113 + 0.0087827448677654102*_t17*_t31*_t32*_t33*_t36*_t39*gaa*(0.10e2*_t1*_t2*_t4*(-_hc4[2]*_t83 + (0.1e1 / 0.6e1)*_hc5[1]*_t14*_t2*_t4) - 0.10e2 / 0.3e1*_t29*_t82 - _t99) + 0.057459117295175312*_t30*_t33*_t36*_t39*_t50*_t88*_t89 - _t30*_t97*gaa) * (0.0014637908112942349*_hc1[1]*_t105*_t106*_t107*_t3*_t30*_t36*_t39*gaa - _t113 + 0.0087827448677654102*_t17*_t31*_t32*_t33*_t36*_t39*gaa*(0.10e2*_t1*_t2*_t4*(-_hc4[2]*_t83 + (0.1e1 / 0.6e1)*_hc5[1]*_t14*_t2*_t4) - 0.10e2 / 0.3e1*_t29*_t82 - _t99) + 0.057459117295175312*_t30*_t33*_t36*_t39*_t50*_t88*_t89 - _t30*_t97*gaa)));
  const double _t203 = -0.2e1 / 0.3e1*_hc7[14]*_t94 - 0.2e1 / 0.3e1*_t130*_t65 - _t163*_t202 - _t166*_t202;
  const double _t204 = _hc8[2]*_t73;
  const double _t205 = my_piecewise3(_t25, 0, _t203);
  const double _t206 = 0.87039999999999995*_t74;
  const double _t207 = _t134*_t74;
  const double _t208 = _hc9[2]*_t79;
  const double _t213 = _hc11[3]*_t16*_t3;
  const double _t215 = -_t122*_t148*_t149*_t175*_t51 + _t124*(-_t118*_t148*_t185 + _t118*_t211*_t212 - 0.1e1 / 0.24e2*_t148*_t187 + _t149*(-0.1e1 / 0.12e2*xc_powr(0.3e1, 1, 6)*_hc2[4]*_t210/(_t9*xc_powr(na, 5, 2)) + _t102*_t110*_t195 - 0.7e1 / 0.36e2*_t111*_t138 + _t146*_t89*(_t1*_t2*_t4*(2.2983646918070124*_hc4[1] - 2.2983646918070124*_hc5[0]) - 10.342641113131556*_t27) + _t147*(_t6*(_hc4[2]*_t214 - _hc5[1]*_t214) + _t82*(0.071823896618969152*_hc4[1] - 0.071823896618969152*_hc5[0]) + 0.96962260435608338*_t98) - 0.7e1 / 0.144e3*_t160*_t213 + _t194*(gaa * gaa * gaa * gaa)*(2.1145120268809068*_t27 + _t6*(-0.46989156152909045*_hc4[1] + 0.46989156152909045*_hc5[0]))/xc_powr(na, 43, 3) - 0.003591194830948457*_t196*_t37/xc_powr(na, 28, 3) + _t44*(_t6*(-0.014637908112942351*_hc4[2]*_t82 + 0.014637908112942351*_hc5[1]*_t14*_t2*_t4) + _t82*(-0.029275816225884703*_hc4[1] + 0.029275816225884703*_hc5[0]) - 0.39522351904944347*_t98) + _t96*(1.0539293841318491*_t27 + _t6*(-0.23420652980707757*_hc4[1] + 0.23420652980707757*_hc5[0]))));
  const double _t216 = _hc10[12]*_t21 + _hc10[13]*_t21;
  const double _t217 = -_t167*_t216 - _t69 - _t71;
  const double _t218 = my_piecewise3(_t25, 0, _t217);
  const double _t219 = _t156*_t74;
  const double _t226 = _t150*(-_t13*_t137*_t225 - 0.064641506957072228*_t144*_t145*_t93 + _t194*_t88*(_t1*_t2*_t4*(0.17620933557340895*_hc4[1] - 0.17620933557340895*_hc5[0]) - 0.79294201008034026*_t27)/xc_powr(na, 40, 3) + (0.1e1 / 0.48e2)*_t213*_t224*_t65);
  const double _t233 = _t129*_t131*_t216;
  const double _t234 = my_piecewise3(_t25, 0, _t233);
  const double _t235 = _t134*_t156;
  const double _t236 = (_t156 * _t156);
  const double d2F_dna2 = -0.1e1 / 0.3e1*_hc0[1]*_t82 + 0.2e1*_t125 + 0.2e1*_t128 + 0.2e1*_t81 + na*(0.2e1*_t127*_t80 - _t175*_t176*_t35*_t50 + _t201 + _t53*my_piecewise5(_t54, _hc8[1]*my_piecewise3(_t23, 0, _t169) + _hc8[2]*(_t73 * _t73), _t55, -_t170*_t171 - _t170*_t172 - _t170*_t173 + 36.738723026100004*_t170*_t57 + 15.506534051159999*_t170*_t59 - 0.87039999999999995*_t170 + 12.2462410087*_t174*_t58 + 3.1013068102319998*_t174*_t60 - _t174*_t75 - _t174*_t76 - _t174*_t77 - _t174*_t78 - 0.64000000000000001*_t174, _hc9[1]*my_piecewise3(_t25, _t169, 0) + _hc9[2]*(_t79 * _t79)) + _t62*((0.14e2 / 0.27e2)*_hc6[1]*_t16*_t160*_t18*_t8 + (0.2e1 / 0.9e1)*_hc6[2]*_t2*_t4*_t65 + _t175*_t176*_t35*_t50 - _t177*(-_hc6[3]*_t177 - _hc6[4]*_t83) - _t179 - _t201 - _t83*(-_hc6[4]*_t177 - _hc6[5]*_t83)));
  const double d2F_dna_dgaa = _t153 + na*(_t127*_t136 + _t152*_t80 + _t215 + _t53*my_piecewise5(_t54, _hc8[1]*my_piecewise3(_t23, 0, _t203) + _t133*_t204, _t55, -_t134*_t206 + 36.738723026100004*_t134*_t57*_t74 + 15.506534051159999*_t134*_t59*_t74 - _t171*_t207 - _t172*_t207 - _t173*_t207 + 12.2462410087*_t205*_t58 + 3.1013068102319998*_t205*_t60 - _t205*_t75 - _t205*_t76 - _t205*_t77 - _t205*_t78 - 0.64000000000000001*_t205, _hc9[1]*my_piecewise3(_t25, _t203, 0) + _t135*_t208) + _t62*(-0.1e1 / 0.24e2*_hc6[4]*_t210*_t31/M_PI - 0.1e1 / 0.9e1*_t129*_t65*_t85 - 0.1e1 / 0.18e2*_t209*_t95 - _t215));
  const double d2F_dna_dta = _t159 + na*(_t127*_t158 + _t53*my_piecewise5(_t54, _hc8[1]*my_piecewise3(_t23, 0, _t217) + _t155*_t204, _t55, -_t156*_t206 + 36.738723026100004*_t156*_t57*_t74 + 15.506534051159999*_t156*_t59*_t74 - _t171*_t219 - _t172*_t219 - _t173*_t219 + 12.2462410087*_t218*_t58 + 3.1013068102319998*_t218*_t60 - _t218*_t75 - _t218*_t76 - _t218*_t77 - _t218*_t78 - 0.64000000000000001*_t218, _hc9[1]*my_piecewise3(_t25, _t217, 0) + _t157*_t208));
  const double d2F_dgaa2 = na*(0.2e1*_t136*_t152 - _t221 - _t222*_t223 + _t226 + _t227 + _t53*my_piecewise5(_t54, _hc8[1]*my_piecewise3(_t23, 0, _t230) + _hc8[2]*(_t133 * _t133), _t55, -_t171*_t231 - _t172*_t231 - _t173*_t231 + 36.738723026100004*_t231*_t57 + 15.506534051159999*_t231*_t59 - 0.87039999999999995*_t231 + 12.2462410087*_t232*_t58 + 3.1013068102319998*_t232*_t60 - _t232*_t75 - _t232*_t76 - _t232*_t77 - _t232*_t78 - 0.64000000000000001*_t232, _hc9[1]*my_piecewise3(_t25, _t230, 0) + _hc9[2]*(_t135 * _t135)) + _t62*((0.1e1 / 0.48e2)*_t209*_t228*_t32 + _t221 + _t222*_t223 - _t226 - _t227 - 0.1e1 / 0.24e2*_t229*_t85));
  const double d2F_dgaa_dta = na*(_t152*_t158 + _t53*my_piecewise5(_t54, _hc8[1]*my_piecewise3(_t23, 0, _t233) + _hc8[2]*_t133*_t155, _t55, 36.738723026100004*_t134*_t156*_t57 + 15.506534051159999*_t134*_t156*_t59 - _t171*_t235 - _t172*_t235 - _t173*_t235 + 12.2462410087*_t234*_t58 + 3.1013068102319998*_t234*_t60 - _t234*_t75 - _t234*_t76 - _t234*_t77 - _t234*_t78 - 0.64000000000000001*_t234 - 0.87039999999999995*_t235, _hc9[1]*my_piecewise3(_t25, _t233, 0) + _hc9[2]*_t135*_t157));
  const double d2F_dta2 = _t53*na*my_piecewise5(_t54, _hc8[2]*(_t155 * _t155), _t55, -_t171*_t236 - _t172*_t236 - _t173*_t236 + 36.738723026100004*_t236*_t57 + 15.506534051159999*_t236*_t59 - 0.87039999999999995*_t236, _hc9[2]*(_t157 * _t157));
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
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
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = xc_powr(0.6e1, 1, 3);
  const double _t5 = M_CBRTPI;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = _t4*_t6;
  const double _t8 = _t3*_t7;
  const double _t9 = (0.1e1 / 0.2e1)*_t8;
  const double _t10 = na - nb;
  const double _t11 = (0.1e1 / _t1);
  const double _t12 = _t10*_t11;
  const double _t16 = xc_powr(_t1, -7, 6);
  const double _t17 = gaa + 0.2e1*gab + gbb;
  const double _t18 = xc_powr(_t17, 1, 2);
  const double _t19 = xc_powr(0.3e1, 5, 6);
  const double _t20 = xc_powr(M_PI, 1, 6);
  const double _t21 = _t18*_t19*_t20;
  const double _t22 = _t16*_t21;
  const double _t23 = xc_powr(_t1, -4, 3);
  const double _t24 = _t18*_t23;
  const double _t25 = xc_powr(0.3e1, 2, 3);
  const double _t26 = (M_CBRTPI * M_CBRTPI);
  const double _t27 = (0.1e1 / _t26);
  const double _t28 = _t25*_t27;
  const double _t29 = (0.1e1 / 0.6e1)*_t28;
  const double _t30 = xc_powr(na, -5, 3);
  const double _t31 = _t30*ta;
  const double _t32 = xc_powr(nb, -5, 3);
  const double _t33 = _t32*tb;
  const double _t47 = (0.1e1 / (_t1 * _t1));
  const double _t48 = M_CBRT2;
  const double _t49 = 2.363*_t48 - 2.363;
  const double _t51 = (_t10 * _t10);
  const double _t52 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t53 = (_t10 * _t10 * _t10 * _t10);
  const double _t54 = xc_powi(_t1, -6);
  const double _t55 = xc_powi(_t10, 6);
  const double _t56 = xc_powi(_t1, -8);
  const double _t57 = xc_powi(_t10, 8);
  const double _t58 = xc_powi(_t1, -10);
  const double _t59 = xc_powi(_t10, 10);
  const double _t60 = _t47*_t51 + _t52*_t53 + _t54*_t55 + _t56*_t57 + _t58*_t59 + 0.1e1;
  const double _t63 = 0.4e1*na;
  const double _t70 = xc_powr(_t1, -8, 3);
  const double _t71 = M_CBRT3;
  const double _t76 = M_LN2;
  const double _t77 = 0.1e1 - _t76;
  const double _t78 = (0.1e1 / _t77);
  const double _t79 = (_t17 * _t17);
  const double _t80 = exp(-0.40889208157792739*_t25*_t79/((M_PI * M_PI * M_CBRTPI * M_CBRTPI)*xc_powr(_t1, 16, 3)));
  const double _t93 = (0.1e1 / (M_PI * M_PI));
  const double _t609 = _t63 - 0.4e1*nb;
  double _hc0[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 6 : 3];
  XC_CAT(f_pw_k, _KMAX)(p, _t9, _t12, _hc0);
  double _hc1[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t12, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -_t12, 0.2e1 / 0.3e1, _hc2);
  double _hc3[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(w1_k, _KMAX)(p, _t9, _t12, _hc3);
  const double _t13 = (0.1e1 / 0.2e1)*_hc1[0] + (0.1e1 / 0.2e1)*_hc2[0] + 0.1e1;
  const double _t14 = (0.1e1 / _t13);
  const double _t15 = (0.1e1 / 0.12e2)*_t14;
  const double _t72 = (_t13 * _t13 * _t13);
  const double _t73 = (0.1e1 / _t72);
  const double _t74 = (0.1e1 / (_hc3[0]));
  const double _t94 = _t72*_t93;
  const double _t95 = _t77*_t94;
  double _hc4[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(r2scan_y_k, _KMAX)(p, _t9, _t12, _t15*_t22, _hc4);
  double _hc5[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(r2scan_d_k, _KMAX)(p, _t12, _hc5);
  double _hc6[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 6 : 3];
  XC_CAT(r2scan_elsda1_k, _KMAX)(p, _t9, _t12, _hc6);
  double _hc7[(_KMAX) >= 2 ? 4 : (_KMAX) >= 1 ? 3 : 2];
  XC_CAT(f_zeta_k, _KMAX)(p, _t12, _hc7);
  double _hc8[(_KMAX) >= 2 ? 4 : (_KMAX) >= 1 ? 3 : 2];
  XC_CAT(scan_eclda0_k, _KMAX)(p, _t9, _hc8);
  double _hc9[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(r2scan_delsda1_k, _KMAX)(p, _t9, _t12, _hc9);
  double _hc10[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_H0_k, _KMAX)(p, _t9, _t24*_t29, _hc10);
  double _hc11[(_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(mgga_alpha_total_reg_k, _KMAX)(p, _t11*na - _t11*nb, _t18/(_t2*na + _t2*nb), _t31, _t33, params->eta, _hc11);
  double _hc12[(_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(mgga_alpha_total_reg_k, _KMAX)(p, _t12, _t24, _t31, _t33, params->eta, _hc12);
  const double _t34 = _hc11[0] > 0;
  const double _t35 = 1.0*_hc11[0] - 2.5;
  const double _t36 = _t35 > 0;
  const double _t37 = _hc11[0] <= 0;
  const double _t38 = _t35 <= 0;
  const double _t39 = my_piecewise3(_t36, 2.5, _hc12[0]);
  const double _t40 = (_t39 * _t39);
  const double _t41 = (_t39 * _t39 * _t39);
  const double _t42 = (_t39 * _t39 * _t39 * _t39);
  const double _t43 = xc_powi(_t39, 5);
  const double _t44 = xc_powi(_t39, 6);
  const double _t46 = _hc10[0] + _hc8[0];
  const double _t50 = -_hc7[0]*_t49 + 0.1e1;
  const double _t61 = params->eta*(-_hc6[0] + 0.4e1*_hc8[0]*_t47*_t50*_t60*na*nb);
  const double _t62 = 0.45e2*_t61;
  const double _t64 = _t50*_t60;
  const double _t65 = _hc8[1]*_t64;
  const double _t66 = _t47*_t65;
  const double _t67 = _t66*nb;
  const double _t68 = -_hc9[0] + _t63*_t67;
  const double _t69 = 0.10e2*_t3*_t4*_t6*_t68 - _t62;
  const double _t75 = (0.1e1 / (_hc5[0]));
  const double _t81 = _t75*_t78*_t80;
  const double _t82 = _t74*_t81;
  const double _t83 = _t73*_t82;
  const double _t84 = _t26*_t83;
  const double _t85 = _t71*_t84;
  const double _t86 = _t70*_t85;
  const double _t87 = _t69*_t86;
  const double _t88 = 0.0087827448677654102*_t87;
  const double _t89 = 0.4e1*_hc4[0] + _t17*_t88;
  const double _t90 = xc_expm1(-0.1e1 / 0.4e1*xc_log1p(_t89));
  const double _t91 = _hc3[0]*_t90;
  const double _t92 = xc_log1p(-_t91);
  const double _t96 = _hc0[0] + _t92*_t95;
  const double _t97 = 0.4e1*_t46*_t47*_t50*_t60*na*nb - _t96;
  double _hc13[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(r2scan_f_alpha_neg_k, _KMAX)(p, my_piecewise3(_t34, 0, _hc12[0]), _hc13);
  double _hc14[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(rscan_f_alpha_large_k, _KMAX)(p, my_piecewise3(_t36, _hc12[0], 2.5), _hc14);
  const double _t45 = my_piecewise5(_t37, _hc13[0], _t38, -0.051848879792000001*xc_powi(_t39, 7) - 0.64000000000000001*_t39 - 0.43519999999999998*_t40 - 1.5356856045489999*_t41 + 3.0615602521750001*_t42 - 1.9157102362059999*_t43 + 0.51688446837199997*_t44 + 0.1e1, _hc14[0]);
  const double _t98 = _t45*_t97 + _t96;
  const double zk = _t98;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t99 = -_t11;
  const double _t100 = _t10*_t47;
  const double _t101 = _t100 + _t99;
  const double _t102 = -_t101;
  const double _t104 = _t23*_t7;
  const double _t105 = (0.1e1 / 0.6e1)*_t104;
  const double _t108 = -_t10*_t47;
  const double _t109 = _t108 + _t11;
  const double _t116 = xc_powi(_t1, -9);
  const double _t117 = (_t17 * _t17 * _t17);
  const double _t124 = xc_powr(_t1, -11, 3);
  const double _t125 = _t124*_t71;
  const double _t131 = xc_powr(_t1, -13, 6);
  const double _t132 = (0.7e1 / 0.72e2)*_t131;
  const double _t147 = _t49*_t60;
  const double _t151 = 0.2e1*na - 0.2e1*nb;
  const double _t152 = xc_powi(_t10, 9);
  const double _t153 = 0.10e2*_t152*_t58;
  const double _t154 = xc_powi(_t10, 7);
  const double _t155 = 0.8e1*_t154*_t56;
  const double _t156 = xc_powi(_t10, 5);
  const double _t157 = 0.6e1*_t156*_t54;
  const double _t158 = (_t10 * _t10 * _t10);
  const double _t159 = 0.4e1*_t158*_t52;
  const double _t160 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t161 = 0.2e1*_t160;
  const double _t162 = xc_powi(_t1, -5);
  const double _t163 = xc_powi(_t1, -7);
  const double _t164 = xc_powi(_t1, -11);
  const double _t165 = 0.8e1*_t116*_t57 + _t161*_t51 + 0.4e1*_t162*_t53 + 0.6e1*_t163*_t55 + 0.10e2*_t164*_t59;
  const double _t166 = _t151*_t47 + _t153 + _t155 + _t157 + _t159 - _t165;
  const double _t168 = 0.8e1*na;
  const double _t169 = _t160*nb;
  const double _t170 = _t168*_t169;
  const double _t171 = na*nb;
  const double _t172 = xc_powr(_t1, -10, 3);
  const double _t173 = _t172*_t7;
  const double _t174 = (0.2e1 / 0.3e1)*_t173;
  const double _t175 = _t171*_t174;
  const double _t179 = 0.45e2*params->eta;
  const double _t192 = _t26*_t71;
  const double _t193 = _t192*_t70;
  const double _t194 = 0.0087827448677654102*_t193;
  const double _t230 = xc_powr(na, -8, 3);
  const double _t231 = (0.5e1 / 0.3e1)*_t230;
  const double _t234 = xc_powr(_t1, -7, 3);
  const double _t235 = (0.4e1 / 0.3e1)*_t234;
  const double _t253 = (0.2e1 / 0.9e1)*_t234;
  const double _t260 = _t100 + _t11;
  const double _t261 = -_t260;
  const double _t263 = _t108 + _t99;
  const double _t272 = -_t151;
  const double _t273 = -_t153 - _t155 - _t157 - _t159 - _t165 + _t272*_t47;
  const double _t294 = xc_powr(nb, -8, 3);
  const double _t295 = (0.5e1 / 0.3e1)*_t294;
  const double _t308 = (0.1e1 / _t18);
  const double _t317 = _t19*_t20;
  const double _t324 = 0.2e1*gaa + 0.4e1*gab + 0.2e1*gbb;
  const double _t346 = 0.4e1*gaa + 0.8e1*gab + 0.4e1*gbb;
  const double _t103 = _hc0[1]*_t102;
  const double _t106 = -_hc0[2]*_t105;
  const double _t107 = -_hc3[2]*_t105;
  const double _t110 = _hc3[1]*_t109;
  const double _t111 = _t107 + _t110;
  const double _t130 = _t14*_t21;
  const double _t133 = -_t130*_t132;
  const double _t134 = _hc1[2]*_t109;
  const double _t135 = _hc2[2]*_t101;
  const double _t136 = -0.1e1 / 0.24e2*_t134 - 0.1e1 / 0.24e2*_t135;
  const double _t137 = (_t13 * _t13);
  const double _t138 = (0.1e1 / _t137);
  const double _t139 = _t138*_t22;
  const double _t140 = _t133 + _t136*_t139;
  const double _t196 = (0.3e1 / 0.2e1)*_t135;
  const double _t197 = (0.3e1 / 0.2e1)*_t134 + _t196;
  const double _t198 = -_t197;
  const double _t199 = (0.1e1 / (_t13 * _t13 * _t13 * _t13));
  const double _t202 = -_t111;
  const double _t203 = ((_hc3[0]) * (_hc3[0]));
  const double _t204 = (0.1e1 / _t203);
  const double _t209 = _t74*_t78*_t80;
  const double _t224 = _hc1[2]*_t102;
  const double _t225 = _t196 + (0.3e1 / 0.2e1)*_t224;
  const double _t226 = _t137*_t77*_t93;
  const double _t262 = _hc0[1]*_t261;
  const double _t264 = _hc3[1]*_t263;
  const double _t265 = _t107 + _t264;
  const double _t266 = _hc2[2]*_t260;
  const double _t267 = _hc1[2]*_t263;
  const double _t268 = -0.1e1 / 0.24e2*_t266 - 0.1e1 / 0.24e2*_t267;
  const double _t269 = _t133 + _t139*_t268;
  const double _t278 = (0.3e1 / 0.2e1)*_t266;
  const double _t279 = (0.3e1 / 0.2e1)*_t267 + _t278;
  const double _t280 = -_t279;
  const double _t282 = -_t265;
  const double _t290 = _hc1[2]*_t261;
  const double _t291 = _t278 + (0.3e1 / 0.2e1)*_t290;
  const double _t318 = _t14*_t308;
  const double _t319 = _t317*_t318;
  const double _t320 = _t16*_t319;
  const double _t112 = _t89 + 0.1e1;
  const double _t113 = (0.1e1 / _t112);
  const double _t114 = 2.585660278282889*_t61;
  const double _t115 = -0.5745911729517531*_hc9[0] + 2.2983646918070124*_t67*na;
  const double _t118 = _t83*_t93;
  const double _t119 = _t117*_t118;
  const double _t120 = _t116*_t119;
  const double _t121 = -0.2e1 / 0.3e1*_hc4[3]*_t104;
  const double _t122 = _t3*_t4*_t6*(-0.10e2*_hc9[0] + 0.40e2*_t66*na*nb) - _t62;
  const double _t123 = _t122*_t17;
  const double _t126 = _t125*_t84;
  const double _t127 = 0.023420652980707758*_t126;
  const double _t128 = _t121 - _t123*_t127;
  const double _t129 = _t120*(-_t114 + _t115*_t3*_t4*_t6) + _t128;
  const double _t141 = 0.4e1*_hc4[1];
  const double _t142 = 0.4e1*_hc4[2];
  const double _t143 = (0.40e2 / 0.3e1)*_t67;
  const double _t144 = _t104*((0.10e2 / 0.3e1)*_hc9[0] - _t143*na);
  const double _t145 = _hc8[0]*_t47;
  const double _t146 = _t145*_t63;
  const double _t148 = _hc7[1]*_t147;
  const double _t149 = _t109*_t148;
  const double _t150 = _t149*nb;
  const double _t167 = _hc8[0]*_t64;
  const double _t176 = -0.1e1 / 0.6e1*_hc6[2]*_t23*_t4*_t6 + _t167*_t170 + _t175*_t65;
  const double _t177 = -0.4e1*_hc8[0]*_t166*_t47*_t50*na*nb - 0.4e1*_hc8[0]*_t47*_t50*_t60*nb + _t176;
  const double _t178 = -_hc6[1]*_t109 - _t146*_t150 - _t177;
  const double _t180 = 0.10e2*_hc9[1];
  const double _t181 = _hc8[1]*_t47;
  const double _t182 = 0.40e2*_t181;
  const double _t183 = _t171*_t182;
  const double _t184 = _t169*_t65;
  const double _t185 = 0.80e2*_t184;
  const double _t186 = _t171*_t64;
  const double _t187 = (0.20e2 / 0.3e1)*_hc8[2];
  const double _t188 = _t173*_t187;
  const double _t189 = -0.5e1 / 0.3e1*_hc9[2]*_t23*_t4*_t6 + _t185*na + _t186*_t188;
  const double _t190 = _t17*(_t144 - _t178*_t179 + _t8*(0.40e2*_hc8[1]*_t166*_t47*_t50*na*nb + 0.40e2*_hc8[1]*_t47*_t50*_t60*nb - _t109*_t180 - _t149*_t183 - _t189));
  const double _t191 = 0.0087827448677654102*_t86;
  const double _t195 = _t123*_t194;
  const double _t200 = _t199*_t82;
  const double _t201 = _t198*_t200;
  const double _t205 = _t204*_t81;
  const double _t206 = _t202*_t205;
  const double _t207 = _t195*_t73;
  const double _t208 = (0.1e1 / ((_hc5[0]) * (_hc5[0])));
  const double _t210 = _t208*_t209;
  const double _t211 = _hc5[1]*_t210;
  const double _t212 = _t109*_t211;
  const double _t213 = _t109*_t142 + _t140*_t141 + _t190*_t191 + _t195*_t201 + _t206*_t207 - _t207*_t212;
  const double _t214 = _t129 + _t213;
  const double _t215 = _t113*_t214;
  const double _t216 = _t90 + 0.1e1;
  const double _t217 = _hc3[0]*_t216;
  const double _t218 = (0.1e1 / 0.4e1)*_t217;
  const double _t219 = -_t111*_t90 + _t215*_t218;
  const double _t220 = 0.1e1 - _t91;
  const double _t221 = (0.1e1 / _t220);
  const double _t222 = _t221*_t95;
  const double _t223 = _t219*_t222;
  const double _t227 = _t226*_t92;
  const double _t228 = _t225*_t227;
  const double _t229 = _t103 + _t106 + _t223 + _t228;
  const double _t233 = _hc12[4]*_t18;
  const double _t236 = _t233*_t235;
  const double _t240 = 0.87039999999999995*_t39;
  const double _t241 = 4.6070568136469996*_t40;
  const double _t242 = 9.578551181029999*_t42;
  const double _t243 = 0.36294215854400003*_t44;
  const double _t247 = _t46*_t47;
  const double _t248 = _t247*_t63;
  const double _t249 = _t102*_t148;
  const double _t250 = _t248*_t249;
  const double _t251 = _hc10[1]*_t28;
  const double _t252 = _t18*_t251;
  const double _t254 = -_hc10[2]*_t105 - _hc8[1]*_t105 - _t252*_t253;
  const double _t255 = _t46*_t64;
  const double _t256 = _t170*_t255 - 0.4e1*_t254*_t47*_t50*_t60*na*nb;
  const double _t257 = 0.4e1*_t166*_t46*_t47*_t50*na*nb - _t229 - _t250*nb - _t256 + 0.4e1*_t46*_t47*_t50*_t60*nb;
  const double _t270 = _t148*_t263;
  const double _t271 = _t270*nb;
  const double _t274 = -0.4e1*_hc8[0]*_t273*_t47*_t50*na*nb - 0.4e1*_hc8[0]*_t47*_t50*_t60*na + _t176;
  const double _t275 = -_hc6[1]*_t263 - _t146*_t271 - _t274;
  const double _t276 = _t144 - _t179*_t275 + _t8*(0.40e2*_hc8[1]*_t273*_t47*_t50*na*nb + 0.40e2*_hc8[1]*_t47*_t50*_t60*na - _t180*_t263 - _t183*_t270 - _t189);
  const double _t277 = _t17*_t191;
  const double _t281 = _t195*_t200;
  const double _t283 = _t205*_t282;
  const double _t284 = _t211*_t263;
  const double _t285 = _t141*_t269 + _t142*_t263 + _t207*_t283 - _t207*_t284 + _t276*_t277 + _t280*_t281;
  const double _t286 = _t129 + _t285;
  const double _t287 = _t113*_t218;
  const double _t288 = -_t265*_t90 + _t286*_t287;
  const double _t289 = _t222*_t288;
  const double _t292 = _t227*_t291;
  const double _t293 = _t106 + _t262 + _t289 + _t292;
  const double _t303 = _t148*_t261;
  const double _t304 = _t248*nb;
  const double _t305 = -_t256 + 0.4e1*_t273*_t46*_t47*_t50*na*nb - _t293 - _t303*_t304 + 0.4e1*_t46*_t47*_t50*_t60*na;
  const double _t309 = _hc12[4]*_t23;
  const double _t310 = _t308*_t309;
  const double _t311 = (0.1e1 / 0.2e1)*_t310;
  const double _t312 = my_piecewise3(_t34, 0, _t311);
  const double _t313 = my_piecewise3(_t36, 0, _t311);
  const double _t314 = my_piecewise3(_t36, _t311, 0);
  const double _t316 = (0.1e1 / 0.6e1)*_hc4[1];
  const double _t321 = _t316*_t320;
  const double _t322 = 0.39522351904944347*_t61;
  const double _t323 = -0.087827448677654102*_hc9[0] + 0.35130979471061641*_t67*na;
  const double _t325 = _t118*_t56;
  const double _t326 = 0.010773584492845371*_t325;
  const double _t327 = _t123*_t326;
  const double _t328 = _t324*_t327;
  const double _t329 = _t321 - _t328 + _t86*(_t3*_t323*_t4*_t6 - _t322);
  const double _t330 = _t222*_t287;
  const double _t331 = _t329*_t330;
  const double _t332 = _t251*_t308;
  const double _t333 = _t172*_t332;
  const double _t334 = (0.1e1 / 0.3e1)*_t333;
  const double _t335 = _t186*_t334 - _t331;
  const double _t338 = my_piecewise3(_t34, 0, _t310);
  const double _t339 = my_piecewise3(_t36, 0, _t310);
  const double _t340 = my_piecewise3(_t36, _t310, 0);
  const double _t342 = (0.1e1 / 0.3e1)*_hc4[1];
  const double _t343 = _t320*_t342;
  const double _t344 = 0.79044703809888694*_t61;
  const double _t345 = -0.1756548973553082*_hc9[0] + 0.70261958942123282*_t67*na;
  const double _t347 = _t327*_t346;
  const double _t348 = _t343 - _t347 + _t86*(_t3*_t345*_t4*_t6 - _t344);
  const double _t349 = _t330*_t348;
  const double _t350 = (0.2e1 / 0.3e1)*_t333;
  const double _t351 = _t186*_t350 - _t349;
  double _hc15[(_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(mgga_alpha_total_reg_k, _KMAX)(p, _t12, _t24, 0, 0, params->eta, _hc15);
  const double _t232 = _hc15[3]*_t231;
  const double _t237 = _hc12[5]*_t102 - _t232*ta - _t236;
  const double _t238 = my_piecewise3(_t34, 0, _t237);
  const double _t239 = my_piecewise3(_t36, 0, _t237);
  const double _t244 = my_piecewise3(_t36, _t237, 0);
  const double _t245 = my_piecewise5(_t37, _hc13[1]*_t238, _t38, -_t239*_t240 - _t239*_t241 - _t239*_t242 - _t239*_t243 + 12.2462410087*_t239*_t41 + 3.1013068102319998*_t239*_t43 - 0.64000000000000001*_t239, _hc14[1]*_t244);
  const double _t246 = _t245*_t97;
  const double _t258 = _t257*_t45;
  const double _t259 = _t246 + _t258;
  const double _t296 = _hc15[2]*_t295;
  const double _t297 = _hc12[5]*_t261 - _t236 - _t296*tb;
  const double _t298 = my_piecewise3(_t34, 0, _t297);
  const double _t299 = my_piecewise3(_t36, 0, _t297);
  const double _t300 = my_piecewise3(_t36, _t297, 0);
  const double _t301 = my_piecewise5(_t37, _hc13[1]*_t298, _t38, -_t240*_t299 - _t241*_t299 - _t242*_t299 - _t243*_t299 + 12.2462410087*_t299*_t41 + 3.1013068102319998*_t299*_t43 - 0.64000000000000001*_t299, _hc14[1]*_t300);
  const double _t302 = _t301*_t97;
  const double _t306 = _t305*_t45;
  const double _t307 = _t302 + _t306;
  const double _t315 = my_piecewise5(_t37, _hc13[1]*_t312, _t38, -_t240*_t313 - _t241*_t313 - _t242*_t313 - _t243*_t313 + 12.2462410087*_t313*_t41 + 3.1013068102319998*_t313*_t43 - 0.64000000000000001*_t313, _hc14[1]*_t314);
  const double _t336 = _t315*_t97 + _t331 + _t335*_t45;
  const double _t337 = _t1*_t336;
  const double _t341 = my_piecewise5(_t37, _hc13[1]*_t338, _t38, -_t240*_t339 - _t241*_t339 - _t242*_t339 - _t243*_t339 + 12.2462410087*_t339*_t41 + 3.1013068102319998*_t339*_t43 - 0.64000000000000001*_t339, _hc14[1]*_t340);
  const double _t352 = _t341*_t97 + _t349 + _t351*_t45;
  const double _t353 = _hc15[3]*_t30;
  const double _t354 = my_piecewise3(_t34, 0, _t353);
  const double _t355 = my_piecewise3(_t36, 0, _t353);
  const double _t356 = my_piecewise3(_t36, _t353, 0);
  const double _t357 = my_piecewise5(_t37, _hc13[1]*_t354, _t38, -_t240*_t355 - _t241*_t355 - _t242*_t355 - _t243*_t355 + 12.2462410087*_t355*_t41 + 3.1013068102319998*_t355*_t43 - 0.64000000000000001*_t355, _hc14[1]*_t356);
  const double _t358 = _t357*_t97;
  const double _t359 = _hc15[2]*_t32;
  const double _t360 = my_piecewise3(_t34, 0, _t359);
  const double _t361 = my_piecewise3(_t36, 0, _t359);
  const double _t362 = my_piecewise3(_t36, _t359, 0);
  const double _t363 = my_piecewise5(_t37, _hc13[1]*_t360, _t38, -_t240*_t361 - _t241*_t361 - _t242*_t361 - _t243*_t361 + 12.2462410087*_t361*_t41 + 3.1013068102319998*_t361*_t43 - 0.64000000000000001*_t361, _hc14[1]*_t362);
  const double _t364 = _t363*_t97;
  const double dF_dna = _t1*(_t229 + _t259) + _t98;
  const double dF_dnb = _t1*(_t293 + _t307) + _t98;
  const double dF_dgaa = _t337;
  const double dF_dgab = _t1*_t352;
  const double dF_dgbb = _t337;
  const double dF_dta = _t1*_t358;
  const double dF_dtb = _t1*_t364;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double _t367 = 0.2e1*_t47;
  const double _t368 = -_t367;
  const double _t369 = _t10*_t161;
  const double _t370 = _t368 + _t369;
  const double _t371 = _t18*_t235;
  const double _t373 = _t231*ta;
  const double _t385 = 0.16e2*_t169;
  const double _t386 = _t151*_t160;
  const double _t387 = 0.200e3*_t152*_t164;
  const double _t388 = 0.128e3*_t116*_t154;
  const double _t389 = 0.72e2*_t156*_t163;
  const double _t390 = 0.32e2*_t158*_t162;
  const double _t391 = _t51*_t52;
  const double _t392 = _t53*_t54;
  const double _t393 = _t55*_t56;
  const double _t394 = xc_powi(_t1, -12);
  const double _t395 = _t57*_t58;
  const double _t396 = _t367 + 0.18e2*_t391 + 0.50e2*_t392 + 0.98e2*_t393 + 0.110e3*_t394*_t59 + 0.162e3*_t395;
  const double _t397 = -_t387 - _t388 - _t389 - _t390 + _t396;
  const double _t401 = 0.8e1*nb;
  const double _t403 = (_t102 * _t102);
  const double _t408 = _t168*nb;
  const double _t415 = _t234*_t7;
  const double _t416 = (0.2e1 / 0.9e1)*_t415;
  const double _t419 = (0.1e1 / 0.6e1)*_t109;
  const double _t421 = _t151*_t160 - _t367;
  const double _t451 = _t160*_t272;
  const double _t455 = 0.4e1*_t109;
  const double _t479 = _t168 - 0.8e1*nb;
  const double _t480 = -_t160*_t479 + _t397;
  const double _t481 = _t173*nb;
  const double _t489 = (0.4e1 / 0.3e1)*_t173;
  const double _t491 = xc_powr(_t1, -13, 3);
  const double _t492 = xc_powr(0.6e1, 2, 3);
  const double _t493 = xc_powr(_t1, -14, 3);
  const double _t496 = 0.10e2*_t109;
  const double _t510 = _t116*_t117*_t93;
  const double _t511 = 0.11491823459035062*_t510;
  const double _t517 = 0.01756548973553082*_t193;
  const double _t540 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t550 = _t18*_t253*_t28;
  const double _t555 = _t295*tb;
  const double _t565 = _t367 + 0.6e1*_t391 + 0.10e2*_t392 + 0.14e2*_t393 - 0.110e3*_t394*_t59 + 0.18e2*_t395;
  const double _t569 = 0.4e1*nb;
  const double _t576 = _t102*_t261;
  const double _t578 = (0.1e1 / 0.6e1)*_t263;
  const double _t590 = _t10*_t160;
  const double _t591 = _t109*_t263;
  const double _t610 = -_t565;
  const double _t619 = _t160*na;
  const double _t625 = 0.057459117295175312*_t510;
  const double _t628 = 0.3e1*_t590;
  const double _t652 = _t367 + _t369;
  const double _t658 = _t387 + _t388 + _t389 + _t390 + _t396;
  const double _t660 = (_t261 * _t261);
  const double _t662 = _t367 + _t386;
  const double _t667 = _t368 + _t451;
  const double _t669 = _t160*_t479 + _t658;
  const double _t676 = _t23*_t308;
  const double _t688 = _t16*_t317;
  const double _t697 = 0.010773584492845371*_t56*_t93;
  const double _t699 = _t308*_t48;
  const double _t710 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t768 = (0.1e1 / _t17);
  const double _t770 = xc_powr(_t17, -3, 2);
  const double _t775 = 0.1e1 / 0.16e2 - 0.1e1 / 0.16e2*_t76;
  const double _t779 = _t172*_t770;
  const double _t782 = _t688*_t770;
  const double _t785 = xc_powr(_t1, -40, 3);
  const double _t789 = -_t775;
  const double _t365 = -0.1e1 / 0.3e1*_hc0[2]*_t104;
  const double _t413 = -_hc0[4]*_t105;
  const double _t414 = -_hc0[5]*_t105;
  const double _t417 = _hc0[2]*_t416;
  const double _t418 = -0.1e1 / 0.36e2*_hc3[5]*_t23*_t4*_t6;
  const double _t420 = _hc3[4]*_t419 + _t418;
  const double _t422 = -_hc3[4]*_t105;
  const double _t423 = _hc3[2]*_t416;
  const double _t424 = _hc3[1]*_t421 + _t109*(_hc3[3]*_t109 + _t422) + _t423;
  const double _t425 = (0.1e1 / 0.2e1)*_t135;
  const double _t426 = (0.1e1 / 0.12e2)*_t139;
  const double _t445 = (0.91e2 / 0.432e3)*_t130/xc_powr(_t1, 19, 6);
  const double _t446 = _t131*_t138*_t21;
  const double _t447 = (0.1e1 / 0.12e2)*_t22*_t73;
  const double _t448 = _t447*(-0.1e1 / 0.2e1*_t134 - _t425);
  const double _t449 = _hc1[5]*_t403;
  const double _t450 = _hc1[2]*_t421;
  const double _t452 = _hc2[2]*(_t367 + _t451);
  const double _t453 = _hc2[5]*(_t101 * _t101);
  const double _t459 = 0.4e1*_t140;
  const double _t515 = (0.3e1 / 0.2e1)*_t449 + (0.3e1 / 0.2e1)*_t453;
  const double _t525 = -0.1e1 / 0.3e1*_hc3[2]*_t23*_t4*_t6;
  const double _t543 = (0.3e1 / 0.2e1)*_hc1[2];
  const double _t544 = (0.3e1 / 0.2e1)*_hc2[2];
  const double _t553 = -_t77*_t94;
  const double _t577 = _hc0[3]*_t261 + _t413;
  const double _t579 = _hc3[4]*_t578 + _t418;
  const double _t580 = -_t104*_t579 + _t423;
  const double _t581 = _hc3[3]*_t263 + _t422;
  const double _t582 = _hc3[1]*_t369 + _t109*_t581;
  const double _t589 = -_t266 - _t267;
  const double _t592 = _hc1[5]*_t591;
  const double _t593 = _hc2[5]*_t101*_t260;
  const double _t629 = _hc1[2]*_t628 - _hc2[2]*_t628 + (0.3e1 / 0.2e1)*_t593;
  const double _t635 = -_t23*_t4*_t579*_t6 + _t423;
  const double _t637 = -0.2e1*_t266 - 0.2e1*_t267;
  const double _t638 = -0.2e1*_t264 - _t525;
  const double _t649 = _t266 + _t290;
  const double _t650 = -_t105*(_hc0[4]*_t261 + _t414) + _t417;
  const double _t663 = _hc3[1]*_t662 + _t263*_t581;
  const double _t664 = (0.1e1 / 0.2e1)*_t266;
  const double _t666 = _hc2[5]*(_t260 * _t260);
  const double _t668 = _hc1[5]*_t660;
  const double _t672 = (0.3e1 / 0.2e1)*_t666 + (0.3e1 / 0.2e1)*_t668;
  const double _t687 = -0.7e1 / 0.144e3*_t131*_t319;
  const double _t689 = _t138*_t308*_t688;
  const double _t690 = (0.1e1 / 0.6e1)*_t320;
  const double _t722 = -_t132*_t319;
  const double _t723 = (0.1e1 / 0.3e1)*_t320;
  const double _t793 = _t14*_t782;
  const double _t366 = (0.28e2 / 0.9e1)*_t172*_t233;
  const double _t375 = _hc12[15]*_t371;
  const double _t376 = _hc12[19]*_t371;
  const double _t379 = 9.2141136272939992*_t39;
  const double _t380 = 38.314204724119996*_t41;
  const double _t381 = 2.1776529512640002*_t43;
  const double _t383 = (0.1e1 / (_t220 * _t220));
  const double _t384 = (_t219 * _t219);
  const double _t398 = _t166*_t50;
  const double _t399 = _t398*na;
  const double _t400 = _t385*_t399;
  const double _t402 = _t148*_t304;
  const double _t404 = _hc7[2]*_t147;
  const double _t405 = _t403*_t404;
  const double _t406 = _hc7[1]*_t49;
  const double _t407 = _t166*_t406;
  const double _t409 = _t247*_t408;
  const double _t410 = _t254*_t47;
  const double _t411 = _t168*_t410;
  const double _t412 = _t249*nb;
  const double _t427 = (0.10e2 / 0.3e1)*_t104*_t68;
  const double _t428 = _t181*_t63;
  const double _t429 = _hc8[2]*_t175*_t64 - 0.1e1 / 0.6e1*_hc9[2]*_t23*_t4*_t6 + _t168*_t184;
  const double _t430 = _t17*_t69;
  const double _t431 = _t194*_t430;
  const double _t432 = _t200*_t431;
  const double _t433 = _t431*_t73;
  const double _t434 = _t205*_t433;
  const double _t435 = _t211*_t433;
  const double _t436 = _t127*_t17;
  const double _t437 = 0.057459117295175312*_t120*_t69 + _t121 - _t436*_t69;
  const double _t438 = (0.1e1 / (_t112 * _t112));
  const double _t439 = (0.1e1 / 0.16e2)*_t438;
  const double _t440 = _t217*_t439;
  const double _t441 = _t111*_t216;
  const double _t442 = -_t116*_t117*_t73*_t74*_t75*_t78*_t80*_t93*(_t114 - _t115*_t8) + _t128;
  const double _t443 = _t218*_t438;
  const double _t444 = _t214*_t443;
  const double _t454 = -_hc4[8]*_t105;
  const double _t456 = -_hc4[7]*_t105;
  const double _t457 = _hc4[5]*_t109;
  const double _t460 = -0.1e1 / 0.9e1*_hc4[9]*_t23*_t4*_t6;
  const double _t461 = (0.2e1 / 0.3e1)*_hc4[8];
  const double _t462 = (0.2e1 / 0.3e1)*_hc4[7];
  const double _t463 = _t67*na;
  const double _t464 = _t104*(0.38306078196783544*_hc9[0] - 1.5322431278713418*_t463);
  const double _t465 = _t178*params->eta;
  const double _t466 = _hc9[1]*_t109;
  const double _t467 = _t171*_t181;
  const double _t468 = _t149*_t467;
  const double _t469 = _t184*na;
  const double _t470 = _hc8[2]*_t173*_t186;
  const double _t471 = -0.19153039098391772*_hc9[2]*_t23*_t4*_t6 + 9.1934587672280497*_t469 + 0.76612156393567088*_t470;
  const double _t472 = _t415*(-0.40e2 / 0.9e1*_hc9[0] + (0.160e3 / 0.9e1)*_t463);
  const double _t473 = _t398*na*nb;
  const double _t474 = _t181*_t473;
  const double _t475 = _hc9[2]*_t104;
  const double _t476 = (0.160e3 / 0.3e1)*_t469 + (0.40e2 / 0.9e1)*_t470 - 0.10e2 / 0.9e1*_t475;
  const double _t477 = -_hc6[4]*_t105;
  const double _t478 = -0.1e1 / 0.36e2*_hc6[5]*_t104;
  const double _t482 = _t481*_t65;
  const double _t483 = _t146*nb;
  const double _t484 = _t148*_t421;
  const double _t485 = _t109*_t406;
  const double _t486 = _t166*_t485;
  const double _t487 = _t145*_t168;
  const double _t488 = _t487*nb;
  const double _t490 = _hc8[1]*_t473;
  const double _t494 = _hc6[2]*_t416 - 0.24e2*_hc8[0]*_t50*_t52*_t60*na*nb - 0.32e2 / 0.9e1*_hc8[1]*_t4*_t491*_t50*_t6*_t60*na*nb - 0.1e1 / 0.9e1*_hc8[2]*_t27*_t492*_t493*_t50*_t60*na*nb;
  const double _t495 = -_hc9[4]*_t105;
  const double _t497 = -0.5e1 / 0.18e2*_hc9[5]*_t104;
  const double _t498 = (0.5e1 / 0.3e1)*_hc9[4];
  const double _t499 = _t169*_t399;
  const double _t500 = 0.160e3*_hc8[1];
  const double _t501 = 0.80e2*_hc8[1];
  const double _t502 = _t47*_t501;
  const double _t503 = (0.40e2 / 0.3e1)*_hc8[2];
  const double _t504 = _t481*_t64;
  const double _t505 = _t171*_t502;
  const double _t506 = _t173*_t503;
  const double _t507 = -0.240e3*_hc8[1]*_t50*_t52*_t60*na*nb - 0.320e3 / 0.9e1*_hc8[2]*_t4*_t491*_t50*_t6*_t60*na*nb - 0.10e2 / 0.9e1*_hc8[3]*_t27*_t492*_t493*_t50*_t60*na*nb + (0.20e2 / 0.9e1)*_hc9[2]*_t415;
  const double _t508 = _t122*_t200;
  const double _t509 = _t198*_t508;
  const double _t512 = _t122*_t73;
  const double _t513 = _t511*_t512;
  const double _t514 = 0.046841305961415516*_t126;
  const double _t516 = _t205*_t207;
  const double _t518 = _t190*_t517;
  const double _t519 = _t206*_t73;
  const double _t520 = _t123*_t125*_t26;
  const double _t521 = 0.046841305961415516*_t520;
  const double _t522 = _t195*_t198;
  const double _t523 = _t82/xc_powi(_t13, 5);
  const double _t524 = _t522*_t523;
  const double _t526 = _t202*_t207;
  const double _t527 = _t81/((_hc3[0]) * (_hc3[0]) * (_hc3[0]));
  const double _t528 = _t526*_t527;
  const double _t529 = _t123*_t517;
  const double _t530 = _t529*_t73;
  const double _t531 = ((_hc5[1]) * (_hc5[1]))*_t209*_t530/((_hc5[0]) * (_hc5[0]) * (_hc5[0]));
  const double _t532 = _t199*_t206;
  const double _t533 = _t198*_t529;
  const double _t534 = _t212*_t73;
  const double _t535 = _t207*_t211;
  const double _t536 = _hc5[2]*_t207*_t210;
  const double _t537 = _t199*_t212;
  const double _t538 = _hc5[1]*_t204*_t208*_t78*_t80;
  const double _t539 = _t109*_t538;
  const double _t541 = _t25*_t540*_t83;
  const double _t542 = (0.8e1 / 0.9e1)*_hc4[3]*_t415 + _t119*_t58*(30.166036579967038*_t61 + _t8*(6.7035636844371194*_hc9[0] - 26.814254737748477*_t463)) + 0.085875727595928444*_t123*_t493*_t85 + xc_powi(_t17, 5)*_t541*(_t3*_t4*_t6*(-1.2530441640775745*_hc9[0] + 5.0121766563102979*_t463) - 5.6386987383490847*_t61)/xc_powr(_t1, 46, 3);
  const double _t545 = _t13*_t77*_t92*_t93;
  const double _t546 = _t225*_t545;
  const double _t547 = _t221*_t226;
  const double _t548 = _t219*_t547;
  const double _t551 = _t64*na;
  const double _t552 = _t254*_t385*_t551 - 0.24e2*_t46*_t50*_t52*_t60*na*nb - 0.4e1*_t47*_t50*_t60*na*nb*(_hc10[2]*_t416 + _hc8[1]*_t416 + (0.1e1 / 0.36e2)*_hc8[2]*_t27*_t492*_t70 - _t105*(-_hc10[4]*_t550 - _hc10[5]*_t105) + (0.14e2 / 0.27e2)*_t172*_t252 - _t550*(-_hc10[3]*_t550 - _hc10[4]*_t105));
  const double _t564 = _t160*_t255;
  const double _t566 = _t273*_t50;
  const double _t567 = _t168*_t169*_t566;
  const double _t568 = _t170*_t398;
  const double _t570 = _t247*_t303;
  const double _t571 = _t273*_t406;
  const double _t572 = _t410*_t63;
  const double _t573 = _t303*nb;
  const double _t574 = _t10*_t148*_t162;
  const double _t575 = _t408*_t574;
  const double _t583 = _t216*_t265;
  const double _t584 = (0.1e1 / 0.4e1)*_t583;
  const double _t585 = _t113*_t286;
  const double _t586 = (0.1e1 / 0.4e1)*_t441;
  const double _t587 = -_t285 - _t442;
  const double _t588 = _t214*_t440;
  const double _t594 = _hc4[5]*_t269 + _hc4[6]*_t263 + _t454;
  const double _t595 = _hc4[5]*_t263;
  const double _t598 = _t104*(0.19153039098391772*_hc9[0] - 0.76612156393567088*_t463);
  const double _t599 = -0.09576519549195886*_hc9[2]*_t23*_t4*_t6 + 4.5967293836140248*_t469 + 0.38306078196783544*_t470;
  const double _t600 = _t275*params->eta;
  const double _t601 = _hc9[1]*_t263;
  const double _t602 = _t270*_t467;
  const double _t603 = (0.80e2 / 0.3e1)*_t469 + (0.20e2 / 0.9e1)*_t470 - 0.5e1 / 0.9e1*_t475;
  const double _t604 = _t66*na;
  const double _t605 = _t566*nb;
  const double _t606 = _t181*_t605*na;
  const double _t607 = _hc6[3]*_t263 + _t477;
  const double _t608 = _t160*_t167;
  const double _t611 = _t65*na;
  const double _t612 = _t273*_t485;
  const double _t613 = _t263*_t407;
  const double _t614 = _t605*na;
  const double _t615 = _hc8[1]*_t614;
  const double _t616 = _t404*_t591;
  const double _t617 = -_t23*_t4*_t6*(_hc6[4]*_t578 + _t478) + _t494;
  const double _t618 = _hc9[3]*_t263 + _t495;
  const double _t620 = _t619*_t65;
  const double _t621 = _t566*na;
  const double _t622 = _t169*_t621;
  const double _t623 = _t173*_t551;
  const double _t624 = -_t23*_t4*_t6*(_t263*_t498 + _t497) + _t507;
  const double _t626 = _t280*_t508;
  const double _t627 = _t512*_t625;
  const double _t630 = _t17*_t276;
  const double _t631 = _t194*_t630;
  const double _t632 = _t190*_t194;
  const double _t633 = _t200*_t280;
  const double _t634 = _t283*_t73;
  const double _t636 = 0.023420652980707758*_t520;
  const double _t639 = _t195*_t280;
  const double _t640 = _t199*_t283;
  const double _t641 = _t284*_t73;
  const double _t642 = _t199*_t284;
  const double _t643 = _t207*_t282;
  const double _t644 = _t263*_t538;
  const double _t645 = _t104*(-_t263*_t461 - _t269*_t462 - _t460) + _t542;
  const double _t646 = _t288*_t547;
  const double _t647 = _t383*_t95;
  const double _t648 = _t219*_t647;
  const double _t657 = (_t288 * _t288);
  const double _t659 = _t385*_t621;
  const double _t661 = _t404*_t660;
  const double _t665 = _t286*_t443;
  const double _t670 = _t148*_t662;
  const double _t671 = _t263*_t571;
  const double _t673 = _t517*_t630;
  const double _t674 = _t280*_t529;
  const double _t678 = _hc12[15]*_t124;
  const double _t679 = _hc12[4]*_t308;
  const double _t680 = (0.2e1 / 0.3e1)*_t234*_t679 + (0.2e1 / 0.3e1)*_t678;
  const double _t684 = _t171*_t249;
  const double _t685 = _t113*_t586;
  const double _t686 = -_t321 + _t328 + _t86*(_t322 - _t323*_t8);
  const double _t691 = _t104*(0.029275816225884703*_hc9[0] - 0.11710326490353881*_t463);
  const double _t692 = -0.014637908112942351*_hc9[2]*_t23*_t4*_t6 + 0.70261958942123282*_t469 + 0.058551632451769406*_t470;
  const double _t693 = _t206*_t512;
  const double _t694 = _t190*_t326;
  const double _t695 = _t212*_t512;
  const double _t696 = _t123*_t324;
  const double _t698 = _t696*_t697;
  const double _t700 = xc_powr(0.3e1, 1, 6)*_hc4[7]/(xc_powr(_t1, 5, 2)*_t20);
  const double _t701 = _t116*_t118;
  const double _t702 = _t701*_t79;
  const double _t703 = 0.028729558647587656*_t701;
  const double _t704 = _t122*_t324;
  const double _t705 = 0.023494578076454522*_t117*_t541/xc_powr(_t1, 43, 3);
  const double _t706 = _t126*(1.0539293841318491*_t61 + _t8*(0.23420652980707757*_hc9[0] - 0.93682611922831027*_t463)) - _t15*_t699*_t700 + _t696*_t703 + _t702*(_t3*_t4*_t6*(-1.7237735188552594*_hc9[0] + 6.8950940754210377*_t463) - 7.7569808348486671*_t61) - _t704*_t705;
  const double _t707 = _t287*_t329;
  const double _t708 = _t197*_t547;
  const double _t711 = _hc10[3]*_t125*_t710;
  const double _t712 = _hc10[4]*_t699*_t70/M_PI;
  const double _t713 = (0.2e1 / 0.3e1)*_t186;
  const double _t714 = _t332*_t491;
  const double _t715 = -0.4e1*_t47*_t50*_t60*na*nb*(-0.1e1 / 0.9e1*_t234*_t332 - 0.1e1 / 0.18e2*_t711 - 0.1e1 / 0.24e2*_t712) + _t713*_t714;
  const double _t717 = _t235*_t679 + (0.4e1 / 0.3e1)*_t678;
  const double _t721 = -_t343 + _t347 + _t86*(_t344 - _t345*_t8);
  const double _t724 = _t104*(0.058551632451769406*_hc9[0] - 0.23420652980707762*_t463);
  const double _t725 = -0.029275816225884703*_hc9[2]*_t23*_t4*_t6 + 1.4052391788424656*_t469 + 0.11710326490353881*_t470;
  const double _t726 = _t123*_t346;
  const double _t727 = _t697*_t726;
  const double _t728 = _t122*_t346;
  const double _t729 = _t126*(2.1078587682636982*_t61 + _t8*(0.46841305961415514*_hc9[0] - 1.8736522384566205*_t463)) - 0.1e1 / 0.6e1*_t318*_t48*_t700 + _t702*(_t3*_t4*_t6*(-3.4475470377105188*_hc9[0] + 13.790188150842075*_t463) - 15.513961669697334*_t61) + _t703*_t726 - _t705*_t728;
  const double _t730 = _t287*_t348;
  const double _t732 = (0.4e1 / 0.3e1)*_t186*_t714 - 0.4e1*_t47*_t50*_t60*na*nb*(-_t253*_t332 - 0.1e1 / 0.9e1*_t711 - 0.1e1 / 0.12e2*_t712);
  const double _t740 = _t171*_t303;
  const double _t741 = _t113*_t584;
  const double _t742 = _t286*_t440;
  const double _t743 = _t283*_t512;
  const double _t744 = _t326*_t630;
  const double _t745 = _t284*_t512;
  const double _t746 = _t288*_t647;
  const double _t747 = _t279*_t547;
  const double _t769 = _hc12[15]*_t70*_t768;
  const double _t771 = _t309*_t770;
  const double _t772 = (0.1e1 / 0.4e1)*_t769 - 0.1e1 / 0.4e1*_t771;
  const double _t773 = (_t313 * _t313);
  const double _t774 = my_piecewise3(_t36, 0, _t772);
  const double _t776 = (_t216 * _t216);
  const double _t777 = _t326*_t430;
  const double _t778 = ((_t321 - _t324*_t777 + _t88) * (_t321 - _t324*_t777 + _t88));
  const double _t780 = _t186*_t779;
  const double _t781 = _t222*_t440;
  const double _t783 = 0.021547168985690743*_t325;
  const double _t784 = _t704*_t783;
  const double _t786 = _t222*_t443;
  const double _t787 = _t329*_t786;
  const double _t790 = _t203*_t776;
  const double _t791 = _t383*_t438*_t790*_t94;
  const double _t794 = 0.043094337971381486*_t325;
  const double _t795 = _t329*_t348;
  const double _t798 = -0.1e1 / 0.6e1*_hc10[3]*_t493*_t50*_t60*_t71*_t710*_t768*na*nb + (0.1e1 / 0.3e1)*_t251*_t780;
  const double _t799 = (0.1e1 / 0.2e1)*_t769 - 0.1e1 / 0.2e1*_t771;
  const double _t801 = my_piecewise3(_t36, 0, _t799);
  const double _t802 = 0.87039999999999995*_t313;
  const double _t803 = _t313*_t339;
  const double _t806 = _t769 - _t771;
  const double _t807 = (_t339 * _t339);
  const double _t808 = my_piecewise3(_t36, 0, _t806);
  const double _t809 = ((_t343 - _t346*_t777 + 0.01756548973553082*_t87) * (_t343 - _t346*_t777 + 0.01756548973553082*_t87));
  const double _t810 = _t348*_t786;
  const double _t825 = 0.87039999999999995*_t339;
  const double _t831 = _t1*_t97;
  double _hc16[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(r2scan_y_k, _KMAX)(p, _t9, _t12, 0, _hc16);
  const double _t372 = _hc15[14]*_t371;
  const double _t374 = _hc15[14]*_t373;
  const double _t377 = _hc12[5]*_t370 + (0.40e2 / 0.9e1)*_hc15[3]*ta/xc_powr(na, 11, 3) + _t102*(_hc12[20]*_t102 - _hc15[18]*_t373 - _t376) + _t366 - _t371*(_hc12[19]*_t102 - _t374 - _t375) - _t373*(_hc15[18]*_t102 - _t372);
  const double _t378 = (_t239 * _t239);
  const double _t382 = my_piecewise3(_t36, 0, _t377);
  const double _t458 = _hc16[4]*_t140;
  const double _t549 = _hc0[1]*_t370 + _t102*(_hc0[3]*_t102 + _t413) - _t105*(_hc0[4]*_t102 + _t414) + 0.2e1*_t197*_t548 + _t222*((0.1e1 / 0.2e1)*_t215*_t441 + _t287*(_t104*(-_t109*_t461 - _t140*_t462 - _t460) + _t120*(_t464 - 5.171320556565778*_t465 + _t8*(4.5967293836140248*_hc8[1]*_t166*_t47*_t50*na*nb + 4.5967293836140248*_hc8[1]*_t47*_t50*_t60*nb - 1.1491823459035062*_t466 - 4.5967293836140248*_t468 - _t471)) + _t141*(_t139*(-0.1e1 / 0.24e2*_t449 - 0.1e1 / 0.24e2*_t450 - 0.1e1 / 0.24e2*_t452 - 0.1e1 / 0.24e2*_t453) + _t445 + _t446*((0.7e1 / 0.72e2)*_t134 + (0.7e1 / 0.72e2)*_t135) + _t448*(-_t134 - _t135)) + _t142*_t421 - _t190*_t514 + _t201*_t518 - _t201*_t521 - _t202*_t530*_t539 + _t206*_t513 - _t212*_t513 + _t277*(_t104*((0.20e2 / 0.3e1)*_t466 + (0.80e2 / 0.3e1)*_t468 - 0.80e2 / 0.3e1*_t474 + _t476 - 0.80e2 / 0.3e1*_t67) - _t179*(-_hc6[1]*_t421 + 0.16e2*_hc7[1]*_hc8[0]*_t109*_t160*_t49*_t60*na*nb + (0.4e1 / 0.3e1)*_hc7[1]*_hc8[1]*_t109*_t172*_t4*_t49*_t6*_t60*na*nb + 0.8e1*_hc8[0]*_t166*_t47*_t50*nb - _hc8[0]*_t400 + 0.4e1*_hc8[0]*_t47*_t480*_t50*na*nb - _t109*(_hc6[3]*_t109 + _t477) - _t145*_t149*_t401 - _t167*_t385 + _t23*_t4*_t6*(_hc6[4]*_t419 + _t478) - _t405*_t483 - 0.4e1 / 0.3e1*_t482 - _t483*_t484 - _t486*_t488 - _t489*_t490 - _t494) + _t472 + _t8*(0.160e3*_hc7[1]*_hc8[1]*_t109*_t160*_t49*_t60*na*nb + (0.40e2 / 0.3e1)*_hc7[1]*_hc8[2]*_t109*_t172*_t4*_t49*_t6*_t60*na*nb + 0.80e2*_hc8[1]*_t166*_t47*_t50*nb + 0.40e2*_hc8[1]*_t47*_t480*_t50*na*nb - _t150*_t502 - _t180*_t421 - _t183*_t405 - _t183*_t484 - 0.160e3*_t184 + _t23*_t4*_t6*(_t109*_t498 + _t497) - _t473*_t506 - _t486*_t505 - _t496*(_hc9[3]*_t109 + _t495) - _t499*_t500 - _t503*_t504 - _t507)) + _t281*(-0.3e1 / 0.2e1*_t450 - 0.3e1 / 0.2e1*_t452 - _t515) + _t403*_t531 - _t403*_t536 - _t421*_t535 + _t455*(_hc4[5]*_t140 + _hc4[6]*_t109 + _t454) + _t459*(_t456 + _t457 + _t458) + _t509*_t511 + _t516*(_t23*_t4*_t420*_t6 - _t424) + _t518*_t519 - _t518*_t534 - _t519*_t521 + _t521*_t534 + _t524*(-0.2e1*_t134 - 0.2e1*_t135) + _t528*(-0.2e1*_t110 - _t525) + _t532*_t533 - _t533*_t537 + _t542) - _t440*((_t102*_t142 - _t102*_t435 + _t141*(_t133 + _t426*(-0.1e1 / 0.2e1*_t224 - _t425)) - _t225*_t432 + _t277*(-_t179*(-_hc6[1]*_t102 - _t146*_t412 - _t177) + 0.10e2*_t3*_t4*_t6*(0.4e1*_hc8[1]*_t166*_t47*_t50*na*nb + 0.4e1*_hc8[1]*_t47*_t50*_t60*nb - _hc9[1]*_t102 - _t412*_t428 - _t429) - _t427) + _t434*(-_hc3[1]*_t102 - _t107) + _t437) * (_t102*_t142 - _t102*_t435 + _t141*(_t133 + _t426*(-0.1e1 / 0.2e1*_t224 - _t425)) - _t225*_t432 + _t277*(-_t179*(-_hc6[1]*_t102 - _t146*_t412 - _t177) + 0.10e2*_t3*_t4*_t6*(0.4e1*_hc8[1]*_t166*_t47*_t50*na*nb + 0.4e1*_hc8[1]*_t47*_t50*_t60*nb - _hc9[1]*_t102 - _t412*_t428 - _t429) - _t427) + _t434*(-_hc3[1]*_t102 - _t107) + _t437)) + _t444*(-_t213 - _t442) - _t90*(-_t104*_t420 + _t424)) + _t227*(_t370*_t543 - _t370*_t544 + _t515) + _t417 + _t546*(_t135 + _t224);
  const double _t554 = _hc13[2]*_t238;
  const double _t556 = _hc12[20]*_t261 - _hc15[17]*_t555 - _t376;
  const double _t557 = _hc15[13]*_t555;
  const double _t558 = _t366 - _t371*(_hc12[19]*_t261 - _t375 - _t557);
  const double _t559 = _hc12[5]*_t369 + _t102*_t556 - _t373*(_hc15[18]*_t261 - _t372) + _t558;
  const double _t560 = 0.87039999999999995*_t239;
  const double _t561 = _t239*_t299;
  const double _t562 = my_piecewise3(_t36, 0, _t559);
  const double _t563 = _hc14[2]*_t244;
  const double _t596 = _hc16[4]*_t269;
  const double _t597 = _t456 + _t595 + _t596;
  const double _t651 = _hc0[1]*_t369 + _t102*_t577 + _t197*_t646 + _t222*(_t215*_t584 - _t286*_t588 + _t287*(0.8e1*_hc4[2]*_t590 + _t120*(-2.585660278282889*_t465 + _t598 + _t8*(2.2983646918070124*_hc8[1]*_t166*_t47*_t50*na*nb + 2.2983646918070124*_hc8[1]*_t47*_t50*_t60*nb - 0.5745911729517531*_t466 - 2.2983646918070124*_t468 - _t599)) + _t120*(_t598 - 2.585660278282889*_t600 + _t8*(2.2983646918070124*_hc8[1]*_t273*_t47*_t50*na*nb + 2.2983646918070124*_hc8[1]*_t47*_t50*_t60*na - _t599 - 0.5745911729517531*_t601 - 2.2983646918070124*_t602)) - _t127*_t190 + _t141*(_t139*(-0.1e1 / 0.12e2*_hc1[2]*_t590 + (0.1e1 / 0.12e2)*_hc2[2]*_t10*_t160 - 0.1e1 / 0.24e2*_t592 - 0.1e1 / 0.24e2*_t593) + _t445 + _t446*((0.7e1 / 0.144e3)*_t134 + (0.7e1 / 0.144e3)*_t135) + _t446*((0.7e1 / 0.144e3)*_t266 + (0.7e1 / 0.144e3)*_t267) + _t448*_t589) + _t201*_t631 - _t201*_t636 + _t206*_t627 - _t212*_t627 - _t276*_t436 + _t277*(_t104*(-_t143 + (0.10e2 / 0.3e1)*_t466 + (0.40e2 / 0.3e1)*_t468 - 0.40e2 / 0.3e1*_t474 + _t603) + _t104*((0.10e2 / 0.3e1)*_t601 + (0.40e2 / 0.3e1)*_t602 + _t603 - 0.40e2 / 0.3e1*_t604 - 0.40e2 / 0.3e1*_t606) - _t179*(-_hc6[1]*_t369 + 0.8e1*_hc7[1]*_hc8[0]*_t109*_t160*_t49*_t60*na*nb + 0.8e1*_hc7[1]*_hc8[0]*_t160*_t263*_t49*_t60*na*nb + (0.2e1 / 0.3e1)*_hc7[1]*_hc8[1]*_t109*_t172*_t4*_t49*_t6*_t60*na*nb + (0.2e1 / 0.3e1)*_hc7[1]*_hc8[1]*_t172*_t263*_t4*_t49*_t6*_t60*na*nb + 0.4e1*_hc8[0]*_t166*_t47*_t50*na + 0.4e1*_hc8[0]*_t273*_t47*_t50*nb + 0.4e1*_hc8[0]*_t47*_t50*_t60 + 0.4e1*_hc8[0]*_t47*_t50*_t610*na*nb - _hc8[0]*_t567 - _hc8[0]*_t568 - _hc8[0]*_t575 - _t109*_t607 - _t145*_t270*_t569 - _t146*_t149 - _t168*_t608 - _t174*_t490 - _t174*_t611 - _t174*_t615 - _t401*_t608 - 0.2e1 / 0.3e1*_t482 - _t483*_t612 - _t483*_t613 - _t483*_t616 - _t617) + _t472 + _t8*(0.80e2*_hc7[1]*_hc8[1]*_t109*_t160*_t49*_t60*na*nb + 0.80e2*_hc7[1]*_hc8[1]*_t160*_t263*_t49*_t60*na*nb + (0.20e2 / 0.3e1)*_hc7[1]*_hc8[2]*_t109*_t172*_t4*_t49*_t6*_t60*na*nb + (0.20e2 / 0.3e1)*_hc7[1]*_hc8[2]*_t172*_t263*_t4*_t49*_t6*_t60*na*nb + 0.40e2*_hc8[1]*_t166*_t47*_t50*na + 0.40e2*_hc8[1]*_t273*_t47*_t50*nb + 0.40e2*_hc8[1]*_t47*_t50*_t60 + 0.40e2*_hc8[1]*_t47*_t50*_t610*na*nb - 0.20e2*_hc9[1]*_t590 - _t149*_t182*na - _t171*_t501*_t574 - _t182*_t271 - _t183*_t612 - _t183*_t613 - _t183*_t616 - _t185 - _t187*_t504 - _t187*_t623 - _t188*_t473 - _t188*_t614 - _t496*_t618 - _t499*_t501 - _t501*_t622 - 0.80e2*_t620 - _t624)) + _t281*(-0.3e1 / 0.2e1*_t592 - _t629) + _t283*_t627 - _t284*_t627 + _t455*_t594 + _t459*_t597 + _t509*_t625 + _t516*(-_t582 - _t635) + _t519*_t631 - _t519*_t636 + _t522*_t640 - _t522*_t642 + _t524*_t637 - _t526*_t644 + _t528*_t638 + _t531*_t591 + _t532*_t639 - _t534*_t631 + _t534*_t636 - _t536*_t591 - _t537*_t639 - _t539*_t643 + _t625*_t626 + _t632*_t633 + _t632*_t634 - _t632*_t641 - _t633*_t636 - _t634*_t636 + _t636*_t641 + _t645 - 0.01756548973553082*_t10*_t123*_t192*_t211*_t73/xc_powr(_t1, 17, 3)) + _t444*_t587 + _t585*_t586 - _t90*(_t580 + _t582)) + _t227*((0.3e1 / 0.2e1)*_hc1[5]*_t576 + _t629) + _t279*_t548 - _t288*_t648 + _t546*_t649 + _t650;
  const double _t653 = _hc15[13]*_t371;
  const double _t654 = _hc12[5]*_t652 + (0.40e2 / 0.9e1)*_hc15[2]*tb/xc_powr(nb, 11, 3) + _t261*_t556 - _t555*(_hc15[17]*_t261 - _t653) + _t558;
  const double _t655 = (_t299 * _t299);
  const double _t656 = my_piecewise3(_t36, 0, _t654);
  const double _t675 = _hc0[1]*_t652 + _t222*(_t287*(_t120*(_t464 - 5.171320556565778*_t600 + _t8*(4.5967293836140248*_hc8[1]*_t273*_t47*_t50*na*nb + 4.5967293836140248*_hc8[1]*_t47*_t50*_t60*na - _t471 - 1.1491823459035062*_t601 - 4.5967293836140248*_t602)) + _t141*(_t139*(-0.1e1 / 0.24e2*_hc1[2]*_t662 - 0.1e1 / 0.24e2*_hc2[2]*_t667 - 0.1e1 / 0.24e2*_t666 - 0.1e1 / 0.24e2*_t668) + _t445 + _t446*((0.7e1 / 0.72e2)*_t266 + (0.7e1 / 0.72e2)*_t267) + _t447*_t589*(-0.1e1 / 0.2e1*_t267 - _t664)) + _t142*_t662 + 0.4e1*_t263*_t594 + 0.4e1*_t269*_t597 + _t277*(_t104*(_t476 + (0.20e2 / 0.3e1)*_t601 + (0.80e2 / 0.3e1)*_t602 - 0.80e2 / 0.3e1*_t604 - 0.80e2 / 0.3e1*_t606) - _t179*(-_hc6[1]*_t662 + 0.16e2*_hc7[1]*_hc8[0]*_t160*_t263*_t49*_t60*na*nb + (0.4e1 / 0.3e1)*_hc7[1]*_hc8[1]*_t172*_t263*_t4*_t49*_t6*_t60*na*nb + 0.8e1*_hc8[0]*_t273*_t47*_t50*na + 0.4e1*_hc8[0]*_t47*_t50*_t669*na*nb - _hc8[0]*_t659 - _t263*_t607 - _t270*_t487 - _t483*_t661 - _t483*_t670 - _t488*_t671 - _t489*_t611 - _t489*_t615 - 0.16e2*_t608*na - _t617) + _t472 + _t8*(0.160e3*_hc7[1]*_hc8[1]*_t160*_t263*_t49*_t60*na*nb + (0.40e2 / 0.3e1)*_hc7[1]*_hc8[2]*_t172*_t263*_t4*_t49*_t6*_t60*na*nb + 0.80e2*_hc8[1]*_t273*_t47*_t50*na + 0.40e2*_hc8[1]*_t47*_t50*_t669*na*nb - _t180*_t662 - _t183*_t661 - _t183*_t670 - 0.10e2*_t263*_t618 - _t270*_t502*na - _t500*_t622 - _t503*_t623 - _t505*_t671 - _t506*_t614 - 0.160e3*_t620 - _t624)) + _t281*(-_t543*_t662 - _t544*_t667 - _t672) - _t282*_t530*_t644 + _t283*_t513 - _t284*_t513 + _t511*_t626 - _t514*_t630 + _t516*(-_t635 - _t663) - _t521*_t633 - _t521*_t634 + _t521*_t641 + _t523*_t637*_t639 + _t527*_t638*_t643 + _t531*_t660 - _t535*_t662 - _t536*_t660 + _t633*_t673 + _t634*_t673 + _t640*_t674 - _t641*_t673 - _t642*_t674 + _t645) - _t440*((_t141*(_t133 + _t426*(-0.1e1 / 0.2e1*_t290 - _t664)) + _t142*_t261 - _t261*_t435 + _t277*(-_t179*(-_hc6[1]*_t261 - _t274 - _t303*_t483) + 0.10e2*_t3*_t4*_t6*(0.4e1*_hc8[1]*_t273*_t47*_t50*na*nb + 0.4e1*_hc8[1]*_t47*_t50*_t60*na - _hc9[1]*_t261 - _t428*_t573 - _t429) - _t427) - _t291*_t432 + _t434*(-_hc3[1]*_t261 - _t107) + _t437) * (_t141*(_t133 + _t426*(-0.1e1 / 0.2e1*_t290 - _t664)) + _t142*_t261 - _t261*_t435 + _t277*(-_t179*(-_hc6[1]*_t261 - _t274 - _t303*_t483) + 0.10e2*_t3*_t4*_t6*(0.4e1*_hc8[1]*_t273*_t47*_t50*na*nb + 0.4e1*_hc8[1]*_t47*_t50*_t60*na - _hc9[1]*_t261 - _t428*_t573 - _t429) - _t427) - _t291*_t432 + _t434*(-_hc3[1]*_t261 - _t107) + _t437)) + (0.1e1 / 0.2e1)*_t583*_t585 + _t587*_t665 - _t90*(_t580 + _t663)) + _t227*(_t543*_t652 - _t544*_t652 + _t672) + _t261*_t577 + 0.2e1*_t279*_t646 + _t291*_t545*_t649 + _t650;
  const double _t677 = _hc15[14]*_t676;
  const double _t681 = (0.1e1 / 0.2e1)*_hc12[19]*_t102*_t23*_t308 - 0.5e1 / 0.6e1*_t230*_t677*ta - _t680;
  const double _t682 = _t239*_t313;
  const double _t683 = my_piecewise3(_t36, 0, _t681);
  const double _t709 = _t222*(_t287*(_t141*(_t687 + _t689*(-0.1e1 / 0.48e2*_t134 - 0.1e1 / 0.48e2*_t135)) + _t194*_t509 + _t194*_t693 - _t194*_t695 - _t201*_t698 - _t324*_t694 + _t457*_t690 + _t458*_t690 - _t519*_t698 + _t534*_t698 + _t706 + _t86*(-0.39522351904944347*_t465 + _t691 + _t8*(0.35130979471061641*_hc8[1]*_t166*_t47*_t50*na*nb + 0.35130979471061641*_hc8[1]*_t47*_t50*_t60*nb - 0.087827448677654102*_t466 - 0.35130979471061641*_t468 - _t692))) - _t329*_t588 + _t329*_t685 + _t444*_t686) - _t648*_t707 + _t707*_t708;
  const double _t716 = _t1*(_t245*_t335 + _t257*_t315 + _t45*((0.1e1 / 0.3e1)*_hc10[1]*_t166*_t172*_t25*_t27*_t308*_t50*na*nb + (0.1e1 / 0.3e1)*_hc10[1]*_t172*_t25*_t27*_t308*_t50*_t60*nb - _t334*_t684 - _t709 - _t715) + _t709 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t681) + _t312*_t554, _t38, 36.738723026100004*_t239*_t313*_t40 + 15.506534051159999*_t239*_t313*_t42 - _t240*_t683 - _t241*_t683 - _t242*_t683 - _t243*_t683 - _t313*_t560 - _t379*_t682 - _t380*_t682 - _t381*_t682 + 12.2462410087*_t41*_t683 + 3.1013068102319998*_t43*_t683 - 0.64000000000000001*_t683, _hc14[1]*my_piecewise3(_t36, _t681, 0) + _t314*_t563)) + _t336;
  const double _t718 = _hc12[19]*_t102*_t23*_t308 - _t374*_t676 - _t717;
  const double _t719 = _t239*_t339;
  const double _t720 = my_piecewise3(_t36, 0, _t718);
  const double _t731 = _t222*(_t287*(_t141*(_t136*_t689 + _t722) - _t201*_t727 - _t346*_t694 + _t457*_t723 + _t458*_t723 + _t509*_t517 + _t517*_t693 - _t517*_t695 - _t519*_t727 + _t534*_t727 + _t729 + _t86*(-0.79044703809888694*_t465 + _t724 + _t8*(0.70261958942123282*_hc8[1]*_t166*_t47*_t50*na*nb + 0.70261958942123282*_hc8[1]*_t47*_t50*_t60*nb - 0.1756548973553082*_t466 - 0.70261958942123282*_t468 - _t725))) - _t348*_t588 + _t348*_t685 + _t444*_t721) - _t648*_t730 + _t708*_t730;
  const double _t733 = _hc13[2]*_t298;
  const double _t734 = _hc15[13]*_t676;
  const double _t735 = (0.1e1 / 0.2e1)*_hc12[19]*_t23*_t261*_t308 - 0.5e1 / 0.6e1*_t294*_t734*tb - _t680;
  const double _t736 = 0.87039999999999995*_t299;
  const double _t737 = _t299*_t313;
  const double _t738 = my_piecewise3(_t36, 0, _t735);
  const double _t739 = _hc14[2]*_t300;
  const double _t748 = _t222*(_t287*(_t141*(_t687 + _t689*(-0.1e1 / 0.48e2*_t266 - 0.1e1 / 0.48e2*_t267)) + _t194*_t626 + _t194*_t743 - _t194*_t745 - _t324*_t744 + _t595*_t690 + _t596*_t690 - _t633*_t698 - _t634*_t698 + _t641*_t698 + _t706 + _t86*(-0.39522351904944347*_t600 + _t691 + _t8*(0.35130979471061641*_hc8[1]*_t273*_t47*_t50*na*nb + 0.35130979471061641*_hc8[1]*_t47*_t50*_t60*na - 0.087827448677654102*_t601 - 0.35130979471061641*_t602 - _t692))) + _t329*_t741 - _t329*_t742 + _t665*_t686) - _t707*_t746 + _t707*_t747;
  const double _t749 = _t1*(_t301*_t335 + _t305*_t315 + _t45*((0.1e1 / 0.3e1)*_hc10[1]*_t172*_t25*_t27*_t273*_t308*_t50*na*nb + (0.1e1 / 0.3e1)*_hc10[1]*_t172*_t25*_t27*_t308*_t50*_t60*na - _t334*_t740 - _t715 - _t748) + _t748 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t735) + _t312*_t733, _t38, -_t240*_t738 - _t241*_t738 - _t242*_t738 - _t243*_t738 + 36.738723026100004*_t299*_t313*_t40 + 15.506534051159999*_t299*_t313*_t42 - _t313*_t736 - _t379*_t737 - _t380*_t737 - _t381*_t737 + 12.2462410087*_t41*_t738 + 3.1013068102319998*_t43*_t738 - 0.64000000000000001*_t738, _hc14[1]*my_piecewise3(_t36, _t735, 0) + _t314*_t739)) + _t336;
  const double _t750 = _hc12[19]*_t23*_t261*_t308 - _t557*_t676 - _t717;
  const double _t751 = _t299*_t339;
  const double _t752 = my_piecewise3(_t36, 0, _t750);
  const double _t753 = _t222*(_t287*(_t141*(_t268*_t689 + _t722) - _t346*_t744 + _t517*_t626 + _t517*_t743 - _t517*_t745 + _t595*_t723 + _t596*_t723 - _t633*_t727 - _t634*_t727 + _t641*_t727 + _t729 + _t86*(-0.79044703809888694*_t600 + _t724 + _t8*(0.70261958942123282*_hc8[1]*_t273*_t47*_t50*na*nb + 0.70261958942123282*_hc8[1]*_t47*_t50*_t60*na - 0.1756548973553082*_t601 - 0.70261958942123282*_t602 - _t725))) + _t348*_t741 - _t348*_t742 + _t665*_t721) - _t730*_t746 + _t730*_t747;
  const double _t754 = _t30*_t372;
  const double _t755 = _hc15[18]*_t102*_t30 - _t232 - _t754;
  const double _t756 = my_piecewise3(_t36, 0, _t755);
  const double _t757 = _t239*_t355;
  const double _t758 = _t32*_t653;
  const double _t759 = _hc15[17]*_t102*_t32 - _t758;
  const double _t760 = my_piecewise3(_t36, 0, _t759);
  const double _t761 = _t239*_t361;
  const double _t762 = _hc15[18]*_t261*_t30 - _t754;
  const double _t763 = my_piecewise3(_t36, 0, _t762);
  const double _t764 = _t299*_t355;
  const double _t765 = _hc15[17]*_t261*_t32 - _t296 - _t758;
  const double _t766 = my_piecewise3(_t36, 0, _t765);
  const double _t767 = _t299*_t361;
  const double _t788 = _t330*((0.1e1 / 0.48e2)*_hc16[4]*_t138*_t234*_t25*_t5*_t768 - _hc4[1]*_t15*_t782 + 0.0044052333893352235*_t122*_t17*_t25*(_t324 * _t324)*_t540*_t73*_t74*_t75*_t78*_t785*_t80 - _t123*_t783 - _t784) + _t686*_t787 - _t778*_t781;
  const double _t792 = _t1*(0.2e1*_t315*_t335 + _t45*(-_hc10[1]*_t29*_t780 + (0.1e1 / 0.12e2)*_hc10[3]*_t493*_t50*_t60*_t71*_t710*_t768*na*nb + _t203*_t383*_t438*_t72*_t775*_t776*_t778*_t93 - _t788) + _t778*_t789*_t791 + _t788 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t772) + _hc13[2]*(_t312 * _t312), _t38, -_t240*_t774 - _t241*_t774 - _t242*_t774 - _t243*_t774 - _t379*_t773 - _t380*_t773 - _t381*_t773 + 36.738723026100004*_t40*_t773 + 12.2462410087*_t41*_t774 + 15.506534051159999*_t42*_t773 + 3.1013068102319998*_t43*_t774 - 0.87039999999999995*_t773 - 0.64000000000000001*_t774, _hc14[1]*my_piecewise3(_t36, _t772, 0) + _hc14[2]*(_t314 * _t314)));
  const double _t796 = _t330*((0.1e1 / 0.24e2)*_hc16[4]*_t138*_t234*_t25*_t5*_t768 + 0.0044052333893352235*_t122*_t17*_t25*_t324*_t346*_t540*_t73*_t74*_t75*_t78*_t785*_t80 - _t123*_t794 - _t316*_t793 - _t326*_t728 - _t784) - _t439*_t647*_t790*_t795 - _t781*_t795;
  const double _t797 = _t721*_t787 + _t796;
  const double _t800 = _hc13[2]*_t312;
  const double _t804 = _hc14[2]*_t314;
  const double _t805 = _t315*_t351 + _t335*_t341 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t799) + _t338*_t800, _t38, -_t240*_t801 - _t241*_t801 - _t242*_t801 - _t243*_t801 + 36.738723026100004*_t313*_t339*_t40 + 15.506534051159999*_t313*_t339*_t42 - _t339*_t802 - _t379*_t803 - _t380*_t803 - _t381*_t803 + 12.2462410087*_t41*_t801 + 3.1013068102319998*_t43*_t801 - 0.64000000000000001*_t801, _hc14[1]*my_piecewise3(_t36, _t799, 0) + _t340*_t804);
  const double _t811 = _t330*((0.1e1 / 0.12e2)*_hc16[4]*_t138*_t234*_t25*_t5*_t768 + 0.0044052333893352235*_t122*_t17*_t25*(_t346 * _t346)*_t540*_t73*_t74*_t75*_t78*_t785*_t80 - 0.086188675942762971*_t123*_t325 - _t342*_t793 - _t728*_t794) + _t721*_t810 - _t781*_t809;
  const double _t812 = _t686*_t810 + _t796;
  const double _t813 = _t30*_t677;
  const double _t814 = (0.1e1 / 0.2e1)*_t813;
  const double _t815 = my_piecewise3(_t36, 0, _t814);
  const double _t816 = _t313*_t355;
  const double _t817 = _t1*(_t335*_t357 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t814) + _t354*_t800, _t38, -_t240*_t815 - _t241*_t815 - _t242*_t815 - _t243*_t815 + 36.738723026100004*_t313*_t355*_t40 + 15.506534051159999*_t313*_t355*_t42 - _t355*_t802 - _t379*_t816 - _t380*_t816 - _t381*_t816 + 12.2462410087*_t41*_t815 + 3.1013068102319998*_t43*_t815 - 0.64000000000000001*_t815, _hc14[1]*my_piecewise3(_t36, _t814, 0) + _t356*_t804));
  const double _t818 = _t32*_t734;
  const double _t819 = (0.1e1 / 0.2e1)*_t818;
  const double _t820 = my_piecewise3(_t36, 0, _t819);
  const double _t821 = _t313*_t361;
  const double _t822 = _t1*(_t335*_t363 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t819) + _t360*_t800, _t38, -_t240*_t820 - _t241*_t820 - _t242*_t820 - _t243*_t820 + 36.738723026100004*_t313*_t361*_t40 + 15.506534051159999*_t313*_t361*_t42 - _t361*_t802 - _t379*_t821 - _t380*_t821 - _t381*_t821 + 12.2462410087*_t41*_t820 + 3.1013068102319998*_t43*_t820 - 0.64000000000000001*_t820, _hc14[1]*my_piecewise3(_t36, _t819, 0) + _t362*_t804));
  const double _t823 = _hc13[2]*_t338;
  const double _t824 = my_piecewise3(_t36, 0, _t813);
  const double _t826 = _t339*_t355;
  const double _t827 = _hc14[2]*_t340;
  const double _t828 = my_piecewise3(_t36, 0, _t818);
  const double _t829 = _t339*_t361;
  const double _t830 = (_t355 * _t355);
  const double _t832 = _t355*_t361;
  const double _t833 = (_t361 * _t361);
  const double d2F_dna2 = _t1*(0.2e1*_t245*_t257 + _t383*_t384*_t553 + _t45*(0.16e2*_hc7[1]*_t102*_t160*_t46*_t49*_t60*na*nb - _t102*_t407*_t409 + 0.8e1*_t166*_t254*_t47*_t50*na*nb + 0.8e1*_t166*_t46*_t47*_t50*nb - _t247*_t249*_t401 + 0.8e1*_t254*_t47*_t50*_t60*nb - _t255*_t385 - _t304*_t405 - _t370*_t402 + _t383*_t384*_t72*_t77*_t93 - _t400*_t46 - _t411*_t412 + 0.4e1*_t46*_t47*_t50*na*nb*(-0.4e1*_t386 + _t397) - _t549 - _t552) + _t549 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t377) + _hc13[2]*(_t238 * _t238), _t38, -_t240*_t382 - _t241*_t382 - _t242*_t382 - _t243*_t382 - _t378*_t379 - _t378*_t380 - _t378*_t381 + 36.738723026100004*_t378*_t40 + 15.506534051159999*_t378*_t42 - 0.87039999999999995*_t378 + 12.2462410087*_t382*_t41 + 3.1013068102319998*_t382*_t43 - 0.64000000000000001*_t382, _hc14[1]*my_piecewise3(_t36, _t377, 0) + _hc14[2]*(_t244 * _t244))) + 0.2e1*_t103 + 0.2e1*_t223 + 0.2e1*_t228 + 0.2e1*_t246 + 0.2e1*_t258 + _t365;
  const double d2F_dna_dnb = _t1*(_t245*_t305 + _t257*_t301 + _t45*(0.8e1*_hc7[1]*_t102*_t160*_t46*_t49*_t60*na*nb + 0.8e1*_hc7[1]*_t160*_t261*_t46*_t49*_t60*na*nb - _t102*_t304*_t571 + 0.4e1*_t166*_t254*_t47*_t50*na*nb + 0.4e1*_t166*_t46*_t47*_t50*na - _t168*_t564 - _t250 + 0.4e1*_t254*_t273*_t47*_t50*na*nb + 0.4e1*_t254*_t47*_t50*_t60*na + 0.4e1*_t254*_t47*_t50*_t60*nb - _t261*_t304*_t407 + 0.4e1*_t273*_t46*_t47*_t50*nb - _t304*_t404*_t576 - _t401*_t564 - _t412*_t572 + 0.4e1*_t46*_t47*_t50*_t60 + 0.4e1*_t46*_t47*_t50*na*nb*(-0.2e1*_t386 - 0.2e1*_t451 - _t565) - _t46*_t567 - _t46*_t568 - _t46*_t575 - _t552 - _t569*_t570 - _t572*_t573 - _t651) + _t651 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t559) + _t298*_t554, _t38, 36.738723026100004*_t239*_t299*_t40 + 15.506534051159999*_t239*_t299*_t42 - _t240*_t562 - _t241*_t562 - _t242*_t562 - _t243*_t562 - _t299*_t560 - _t379*_t561 - _t380*_t561 - _t381*_t561 + 12.2462410087*_t41*_t562 + 3.1013068102319998*_t43*_t562 - 0.64000000000000001*_t562, _hc14[1]*my_piecewise3(_t36, _t559, 0) + _t300*_t563)) + _t103 + _t223 + _t228 + _t259 + _t262 + _t289 + _t292 + _t307 + _t365;
  const double d2F_dnb2 = _t1*(0.2e1*_t301*_t305 + _t383*_t553*_t657 + _t45*(0.16e2*_hc7[1]*_t160*_t261*_t46*_t49*_t60*na*nb - _t168*_t570 + 0.8e1*_t254*_t273*_t47*_t50*na*nb + 0.8e1*_t254*_t47*_t50*_t60*na - 0.16e2*_t255*_t619 - _t261*_t409*_t571 + 0.8e1*_t273*_t46*_t47*_t50*na - _t304*_t661 + _t383*_t657*_t72*_t77*_t93 - _t402*_t652 - _t411*_t573 + 0.4e1*_t46*_t47*_t50*na*nb*(-0.4e1*_t451 + _t658) - _t46*_t659 - _t552 - _t675) + _t675 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t654) + _hc13[2]*(_t298 * _t298), _t38, -_t240*_t656 - _t241*_t656 - _t242*_t656 - _t243*_t656 - _t379*_t655 - _t380*_t655 - _t381*_t655 + 36.738723026100004*_t40*_t655 + 12.2462410087*_t41*_t656 + 15.506534051159999*_t42*_t655 + 3.1013068102319998*_t43*_t656 - 0.87039999999999995*_t655 - 0.64000000000000001*_t656, _hc14[1]*my_piecewise3(_t36, _t654, 0) + _hc14[2]*(_t300 * _t300))) + 0.2e1*_t262 + 0.2e1*_t289 + 0.2e1*_t292 + 0.2e1*_t302 + 0.2e1*_t306 + _t365;
  const double d2F_dna_dgaa = _t716;
  const double d2F_dna_dgab = _t1*(_t245*_t351 + _t257*_t341 + _t45*((0.2e1 / 0.3e1)*_hc10[1]*_t166*_t172*_t25*_t27*_t308*_t50*na*nb + (0.2e1 / 0.3e1)*_hc10[1]*_t172*_t25*_t27*_t308*_t50*_t60*nb - _t350*_t684 - _t731 - _t732) + _t731 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t718) + _t338*_t554, _t38, 36.738723026100004*_t239*_t339*_t40 + 15.506534051159999*_t239*_t339*_t42 - _t240*_t720 - _t241*_t720 - _t242*_t720 - _t243*_t720 - _t339*_t560 - _t379*_t719 - _t380*_t719 - _t381*_t719 + 12.2462410087*_t41*_t720 + 3.1013068102319998*_t43*_t720 - 0.64000000000000001*_t720, _hc14[1]*my_piecewise3(_t36, _t718, 0) + _t340*_t563)) + _t352;
  const double d2F_dna_dgbb = _t716;
  const double d2F_dnb_dgaa = _t749;
  const double d2F_dnb_dgab = _t1*(_t301*_t351 + _t305*_t341 + _t45*((0.2e1 / 0.3e1)*_hc10[1]*_t172*_t25*_t27*_t273*_t308*_t50*na*nb + (0.2e1 / 0.3e1)*_hc10[1]*_t172*_t25*_t27*_t308*_t50*_t60*na - _t350*_t740 - _t732 - _t753) + _t753 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t750) + _t338*_t733, _t38, -_t240*_t752 - _t241*_t752 - _t242*_t752 - _t243*_t752 + 36.738723026100004*_t299*_t339*_t40 + 15.506534051159999*_t299*_t339*_t42 - _t339*_t736 - _t379*_t751 - _t380*_t751 - _t381*_t751 + 12.2462410087*_t41*_t752 + 3.1013068102319998*_t43*_t752 - 0.64000000000000001*_t752, _hc14[1]*my_piecewise3(_t36, _t750, 0) + _t340*_t739)) + _t352;
  const double d2F_dnb_dgbb = _t749;
  const double d2F_dna_dta = _t1*(_t257*_t357 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t755) + _t354*_t554, _t38, 36.738723026100004*_t239*_t355*_t40 + 15.506534051159999*_t239*_t355*_t42 - _t240*_t756 - _t241*_t756 - _t242*_t756 - _t243*_t756 - _t355*_t560 - _t379*_t757 - _t380*_t757 - _t381*_t757 + 12.2462410087*_t41*_t756 + 3.1013068102319998*_t43*_t756 - 0.64000000000000001*_t756, _hc14[1]*my_piecewise3(_t36, _t755, 0) + _t356*_t563)) + _t358;
  const double d2F_dna_dtb = _t1*(_t257*_t363 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t759) + _t360*_t554, _t38, 36.738723026100004*_t239*_t361*_t40 + 15.506534051159999*_t239*_t361*_t42 - _t240*_t760 - _t241*_t760 - _t242*_t760 - _t243*_t760 - _t361*_t560 - _t379*_t761 - _t380*_t761 - _t381*_t761 + 12.2462410087*_t41*_t760 + 3.1013068102319998*_t43*_t760 - 0.64000000000000001*_t760, _hc14[1]*my_piecewise3(_t36, _t759, 0) + _t362*_t563)) + _t364;
  const double d2F_dnb_dta = _t1*(_t305*_t357 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t762) + _t354*_t733, _t38, -_t240*_t763 - _t241*_t763 - _t242*_t763 - _t243*_t763 + 36.738723026100004*_t299*_t355*_t40 + 15.506534051159999*_t299*_t355*_t42 - _t355*_t736 - _t379*_t764 - _t380*_t764 - _t381*_t764 + 12.2462410087*_t41*_t763 + 3.1013068102319998*_t43*_t763 - 0.64000000000000001*_t763, _hc14[1]*my_piecewise3(_t36, _t762, 0) + _t356*_t739)) + _t358;
  const double d2F_dnb_dtb = _t1*(_t305*_t363 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t765) + _t360*_t733, _t38, -_t240*_t766 - _t241*_t766 - _t242*_t766 - _t243*_t766 + 36.738723026100004*_t299*_t361*_t40 + 15.506534051159999*_t299*_t361*_t42 - _t361*_t736 - _t379*_t767 - _t380*_t767 - _t381*_t767 + 12.2462410087*_t41*_t766 + 3.1013068102319998*_t43*_t766 - 0.64000000000000001*_t766, _hc14[1]*my_piecewise3(_t36, _t765, 0) + _t362*_t739)) + _t364;
  const double d2F_dgaa2 = _t792;
  const double d2F_dgaa_dgab = _t1*(_t45*(-_t797 - _t798) + _t797 + _t805);
  const double d2F_dgaa_dgbb = _t792;
  const double d2F_dgab2 = _t1*(0.2e1*_t341*_t351 + _t45*((0.1e1 / 0.3e1)*_hc10[3]*_t493*_t50*_t60*_t71*_t710*_t768*na*nb + _t203*_t383*_t438*_t72*_t775*_t776*_t809*_t93 - _t251*_t713*_t779 - _t811) + _t789*_t791*_t809 + _t811 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t806) + _hc13[2]*(_t338 * _t338), _t38, -_t240*_t808 - _t241*_t808 - _t242*_t808 - _t243*_t808 - _t379*_t807 - _t380*_t807 - _t381*_t807 + 36.738723026100004*_t40*_t807 + 12.2462410087*_t41*_t808 + 15.506534051159999*_t42*_t807 + 3.1013068102319998*_t43*_t808 - 0.87039999999999995*_t807 - 0.64000000000000001*_t808, _hc14[1]*my_piecewise3(_t36, _t806, 0) + _hc14[2]*(_t340 * _t340)));
  const double d2F_dgab_dgbb = _t1*(_t45*(-_t798 - _t812) + _t805 + _t812);
  const double d2F_dgbb2 = _t792;
  const double d2F_dgaa_dta = _t817;
  const double d2F_dgaa_dtb = _t822;
  const double d2F_dgab_dta = _t1*(_t351*_t357 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t813) + _t354*_t823, _t38, -_t240*_t824 - _t241*_t824 - _t242*_t824 - _t243*_t824 + 36.738723026100004*_t339*_t355*_t40 + 15.506534051159999*_t339*_t355*_t42 - _t355*_t825 - _t379*_t826 - _t380*_t826 - _t381*_t826 + 12.2462410087*_t41*_t824 + 3.1013068102319998*_t43*_t824 - 0.64000000000000001*_t824, _hc14[1]*my_piecewise3(_t36, _t813, 0) + _t356*_t827));
  const double d2F_dgab_dtb = _t1*(_t351*_t363 + _t97*my_piecewise5(_t37, _hc13[1]*my_piecewise3(_t34, 0, _t818) + _t360*_t823, _t38, -_t240*_t828 - _t241*_t828 - _t242*_t828 - _t243*_t828 + 36.738723026100004*_t339*_t361*_t40 + 15.506534051159999*_t339*_t361*_t42 - _t361*_t825 - _t379*_t829 - _t380*_t829 - _t381*_t829 + 12.2462410087*_t41*_t828 + 3.1013068102319998*_t43*_t828 - 0.64000000000000001*_t828, _hc14[1]*my_piecewise3(_t36, _t818, 0) + _t362*_t827));
  const double d2F_dgbb_dta = _t817;
  const double d2F_dgbb_dtb = _t822;
  const double d2F_dta2 = _t831*my_piecewise5(_t37, _hc13[2]*(_t354 * _t354), _t38, -_t379*_t830 - _t380*_t830 - _t381*_t830 + 36.738723026100004*_t40*_t830 + 15.506534051159999*_t42*_t830 - 0.87039999999999995*_t830, _hc14[2]*(_t356 * _t356));
  const double d2F_dta_dtb = _t831*my_piecewise5(_t37, _hc13[2]*_t354*_t360, _t38, 36.738723026100004*_t355*_t361*_t40 + 15.506534051159999*_t355*_t361*_t42 - _t379*_t832 - _t380*_t832 - _t381*_t832 - 0.87039999999999995*_t832, _hc14[2]*_t356*_t362);
  const double d2F_dtb2 = _t831*my_piecewise5(_t37, _hc13[2]*(_t360 * _t360), _t38, -_t379*_t833 - _t380*_t833 - _t381*_t833 + 36.738723026100004*_t40*_t833 + 15.506534051159999*_t42*_t833 - 0.87039999999999995*_t833, _hc14[2]*(_t362 * _t362));
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
#endif
}
#endif