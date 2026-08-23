/*
  Generated from python/mgga_exc/mgga_xc_zlp.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_xc_zlp
*/

#ifndef _MGGA_XC_ZLP_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_XC_ZLP_KERNEL_BODY
#define _KMAX 0
#define _MGGA_XC_ZLP_HELPER_BODIES
#include "mgga_xc_zlp.c"
#undef _MGGA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_XC_ZLP_HELPER_BODIES
#include "mgga_xc_zlp.c"
#undef _MGGA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_XC_ZLP_HELPER_BODIES
#include "mgga_xc_zlp.c"
#undef _MGGA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_XC_ZLP_HELPER_BODIES
#include "mgga_xc_zlp.c"
#undef _MGGA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_XC_ZLP_HELPER_BODIES
#include "mgga_xc_zlp.c"
#undef _MGGA_XC_ZLP_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_xc_zlp.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_XC_ZLP_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(zlp_f_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt2, double us0, double us1, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.5e1 / 0.3e1, _hc1);
  const double _t1 = (0.1e1 / (rs * rs));
  const double _t2 = xc_powr(0.6e1, 2, 3);
  const double _t3 = M_CBRTPI;
  const double _t4 = _t2*_t3;
  const double _t5 = 162.83141688897226*_t4;
  const double _t6 = _t5*rs;
  const double _t7 = xc_x_minus_log1p(_t6);
  const double _t8 = _t1*_t7;
  const double _t9 = xc_powr(0.6e1, 1, 3);
  const double _t10 = (0.1e1 / _t3);
  const double _t11 = _t10*_t9;
  const double _t12 = M_CBRT2;
  const double _t13 = _hc0[0] + 0.1e1;
  const double _t14 = _hc1[0] + 0.1e1;
  const double _t15 = -0.010775450000000001*_t11*(-0.1e1 / 0.32e2*_t12*(_t13*us0 + _t14*us1) + (0.1e1 / 0.8e1)*xt2) - 0.41421599999999997*_t11;
  const double _t16 = _t11*_t15;
#if _KMAX >= 1
  const double _t17 = (M_CBRTPI * M_CBRTPI);
  const double _t18 = (0.1e1 / _t17);
  const double _t19 = xc_powr(0.3e1, 2, 3);
  const double _t20 = _t18*_t19;
  const double _t21 = _t14*_t20;
  const double _t22 = 6.8932809759843754e-7*_t8;
  const double _t23 = _t20*_t22;
  const double _t24 = _t18*_t2;
  const double _t25 = _hc0[2]*us0 - _hc1[2]*us1;
  const double _t26 = (0.1e1 / (rs * rs * rs));
  const double _t27 = _t26*_t7;
  const double _t28 = (0.1e1 / rs);
  const double _t29 = _t6 + 0.1e1;
  const double _t30 = (0.1e1 / _t29);
  const double _t31 = _t28*_t30;
#endif
#if _KMAX >= 2
  const double _t32 = _hc0[5]*us0 + _hc1[5]*us1;
  const double _t33 = _t12*_t14;
  const double _t34 = 0.32898408583430178*_t31;
  const double _t35 = 1.3786561951968751e-6*_t27;
  const double _t36 = _t12*_t34;
  const double _t37 = _t20*_t35;
  const double _t38 = (0.1e1 / (rs * rs * rs * rs));
  const double _t39 = (0.1e1 / (_t29 * _t29));
  const double _t40 = _t28*_t39;
  const double _t41 = _t17*_t9;
  const double _t42 = _t15*_t41;
  const double _t43 = _t1*_t30;
  const double _t44 = _t15*_t4;
#endif
#if _KMAX >= 3
  const double _t45 = _hc0[9]*us0 - _hc1[9]*us1;
  const double _t46 = 0.98695225750290527*_t43;
  const double _t47 = _t19*_t3;
  const double _t48 = _t14*_t47;
  const double _t49 = 107.13788966064526*_t40;
  const double _t50 = _t12*_t46;
  const double _t51 = _t47*_t49;
  const double _t52 = _t39*_t4;
  const double _t53 = (0.1e1 / (_t29 * _t29 * _t29));
  const double _t54 = _t28*_t53;
  const double _t55 = M_PI*_t15;
  const double _t56 = xc_powi(rs, -5);
  const double _t57 = _t56*_t7;
  const double _t58 = _t1*_t39;
  const double _t59 = _t26*_t30;
#endif
#if _KMAX >= 4
  const double _t60 = 3.9478090300116211*_t59;
  const double _t61 = 1.6543874342362499e-5*_t57;
  const double _t62 = 104672.48625562344*xc_powr(0.12e2, 1, 3)*_t17*_t54;
  const double _t63 = 428.55155864258097*_t58;
  const double _t64 = _t12*_t60;
  const double _t65 = _t20*_t61;
  const double _t66 = _t47*_t63;
#endif

  const double f = 0.0010235534999999999*_t16*_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_dus1 = _t21*_t22;
  out[1] = df_dus1;
  const double df_dus0 = _t13*_t23;
  out[2] = df_dus0;
  const double df_dxt2 = -1.3786561951968751e-6*_t24*_t8;
  out[3] = df_dxt2;
  const double df_dz = _t23*_t25;
  out[4] = df_dz;
  const double df_drs = _t15*_t31*_t5 - 0.0020471069999999998*_t16*_t27;
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dus12 = 0;
  out[6] = d2f_dus12;
  const double d2f_dus0_dus1 = 0;
  out[7] = d2f_dus0_dus1;
  const double d2f_dus02 = 0;
  out[8] = d2f_dus02;
  const double d2f_dxt2_dus1 = 0;
  out[9] = d2f_dxt2_dus1;
  const double d2f_dxt2_dus0 = 0;
  out[10] = d2f_dxt2_dus0;
  const double d2f_dxt22 = 0;
  out[11] = d2f_dxt22;
  const double d2f_dz_dus1 = -_hc1[2]*_t23;
  out[12] = d2f_dz_dus1;
  const double d2f_dz_dus0 = _hc0[2]*_t23;
  out[13] = d2f_dz_dus0;
  const double d2f_dz_dxt2 = 0;
  out[14] = d2f_dz_dxt2;
  const double d2f_dz2 = _t23*_t32;
  out[15] = d2f_dz2;
  const double d2f_drs_dus1 = -_t21*_t35 + _t33*_t34;
  out[16] = d2f_drs_dus1;
  const double d2f_drs_dus0 = _t13*_t36 - _t13*_t37;
  out[17] = d2f_drs_dus0;
  const double d2f_drs_dxt2 = 2.7573123903937501e-6*_t18*_t2*_t26*_t7 - 1.3159363433372071*_t31;
  out[18] = d2f_drs_dxt2;
  const double d2f_drs_dz = _t25*_t36 - _t25*_t37;
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = 0.0061413209999999999*_t10*_t15*_t38*_t7*_t9 - 159084.42195642169*_t40*_t42 - 488.49425066691674*_t43*_t44;
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dus13 = 0;
  out[21] = d3f_dus13;
  const double d3f_dus0_dus12 = 0;
  out[22] = d3f_dus0_dus12;
  const double d3f_dus02_dus1 = 0;
  out[23] = d3f_dus02_dus1;
  const double d3f_dus03 = 0;
  out[24] = d3f_dus03;
  const double d3f_dxt2_dus12 = 0;
  out[25] = d3f_dxt2_dus12;
  const double d3f_dxt2_dus0_dus1 = 0;
  out[26] = d3f_dxt2_dus0_dus1;
  const double d3f_dxt2_dus02 = 0;
  out[27] = d3f_dxt2_dus02;
  const double d3f_dxt22_dus1 = 0;
  out[28] = d3f_dxt22_dus1;
  const double d3f_dxt22_dus0 = 0;
  out[29] = d3f_dxt22_dus0;
  const double d3f_dxt23 = 0;
  out[30] = d3f_dxt23;
  const double d3f_dz_dus12 = 0;
  out[31] = d3f_dz_dus12;
  const double d3f_dz_dus0_dus1 = 0;
  out[32] = d3f_dz_dus0_dus1;
  const double d3f_dz_dus02 = 0;
  out[33] = d3f_dz_dus02;
  const double d3f_dz_dxt2_dus1 = 0;
  out[34] = d3f_dz_dxt2_dus1;
  const double d3f_dz_dxt2_dus0 = 0;
  out[35] = d3f_dz_dxt2_dus0;
  const double d3f_dz_dxt22 = 0;
  out[36] = d3f_dz_dxt22;
  const double d3f_dz2_dus1 = _hc1[5]*_t23;
  out[37] = d3f_dz2_dus1;
  const double d3f_dz2_dus0 = _hc0[5]*_t23;
  out[38] = d3f_dz2_dus0;
  const double d3f_dz2_dxt2 = 0;
  out[39] = d3f_dz2_dxt2;
  const double d3f_dz3 = _t23*_t45;
  out[40] = d3f_dz3;
  const double d3f_drs_dus12 = 0;
  out[41] = d3f_drs_dus12;
  const double d3f_drs_dus0_dus1 = 0;
  out[42] = d3f_drs_dus0_dus1;
  const double d3f_drs_dus02 = 0;
  out[43] = d3f_drs_dus02;
  const double d3f_drs_dxt2_dus1 = 0;
  out[44] = d3f_drs_dxt2_dus1;
  const double d3f_drs_dxt2_dus0 = 0;
  out[45] = d3f_drs_dxt2_dus0;
  const double d3f_drs_dxt22 = 0;
  out[46] = d3f_drs_dxt22;
  const double d3f_drs_dz_dus1 = 1.3786561951968751e-6*_hc1[2]*_t18*_t19*_t26*_t7 - _hc1[2]*_t36;
  out[47] = d3f_drs_dz_dus1;
  const double d3f_drs_dz_dus0 = _hc0[2]*_t36 - _hc0[2]*_t37;
  out[48] = d3f_drs_dz_dus0;
  const double d3f_drs_dz_dxt2 = 0;
  out[49] = d3f_drs_dz_dxt2;
  const double d3f_drs_dz2 = _t32*_t36 - _t32*_t37;
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dus1 = 4.1359685855906248e-6*_t14*_t18*_t19*_t38*_t7 - _t33*_t46 - _t48*_t49;
  out[51] = d3f_drs2_dus1;
  const double d3f_drs2_dus0 = 4.1359685855906248e-6*_t13*_t18*_t19*_t38*_t7 - _t13*_t50 - _t13*_t51;
  out[52] = d3f_drs2_dus0;
  const double d3f_drs2_dxt2 = -8.2719371711812496e-6*_t24*_t38*_t7 + 214.27577932129051*_t28*_t52 + 3.9478090300116211*_t43;
  out[53] = d3f_drs2_dxt2;
  const double d3f_drs2_dz = 4.1359685855906248e-6*_t18*_t19*_t25*_t38*_t7 - _t25*_t50 - _t25*_t51;
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = -0.024565284*_t16*_t57 + 636337.68782568665*_t42*_t58 + 1953.977002667667*_t44*_t59 + 310847301.98552728*_t54*_t55;
  out[55] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dus14 = 0;
  out[56] = d4f_dus14;
  const double d4f_dus0_dus13 = 0;
  out[57] = d4f_dus0_dus13;
  const double d4f_dus02_dus12 = 0;
  out[58] = d4f_dus02_dus12;
  const double d4f_dus03_dus1 = 0;
  out[59] = d4f_dus03_dus1;
  const double d4f_dus04 = 0;
  out[60] = d4f_dus04;
  const double d4f_dxt2_dus13 = 0;
  out[61] = d4f_dxt2_dus13;
  const double d4f_dxt2_dus0_dus12 = 0;
  out[62] = d4f_dxt2_dus0_dus12;
  const double d4f_dxt2_dus02_dus1 = 0;
  out[63] = d4f_dxt2_dus02_dus1;
  const double d4f_dxt2_dus03 = 0;
  out[64] = d4f_dxt2_dus03;
  const double d4f_dxt22_dus12 = 0;
  out[65] = d4f_dxt22_dus12;
  const double d4f_dxt22_dus0_dus1 = 0;
  out[66] = d4f_dxt22_dus0_dus1;
  const double d4f_dxt22_dus02 = 0;
  out[67] = d4f_dxt22_dus02;
  const double d4f_dxt23_dus1 = 0;
  out[68] = d4f_dxt23_dus1;
  const double d4f_dxt23_dus0 = 0;
  out[69] = d4f_dxt23_dus0;
  const double d4f_dxt24 = 0;
  out[70] = d4f_dxt24;
  const double d4f_dz_dus13 = 0;
  out[71] = d4f_dz_dus13;
  const double d4f_dz_dus0_dus12 = 0;
  out[72] = d4f_dz_dus0_dus12;
  const double d4f_dz_dus02_dus1 = 0;
  out[73] = d4f_dz_dus02_dus1;
  const double d4f_dz_dus03 = 0;
  out[74] = d4f_dz_dus03;
  const double d4f_dz_dxt2_dus12 = 0;
  out[75] = d4f_dz_dxt2_dus12;
  const double d4f_dz_dxt2_dus0_dus1 = 0;
  out[76] = d4f_dz_dxt2_dus0_dus1;
  const double d4f_dz_dxt2_dus02 = 0;
  out[77] = d4f_dz_dxt2_dus02;
  const double d4f_dz_dxt22_dus1 = 0;
  out[78] = d4f_dz_dxt22_dus1;
  const double d4f_dz_dxt22_dus0 = 0;
  out[79] = d4f_dz_dxt22_dus0;
  const double d4f_dz_dxt23 = 0;
  out[80] = d4f_dz_dxt23;
  const double d4f_dz2_dus12 = 0;
  out[81] = d4f_dz2_dus12;
  const double d4f_dz2_dus0_dus1 = 0;
  out[82] = d4f_dz2_dus0_dus1;
  const double d4f_dz2_dus02 = 0;
  out[83] = d4f_dz2_dus02;
  const double d4f_dz2_dxt2_dus1 = 0;
  out[84] = d4f_dz2_dxt2_dus1;
  const double d4f_dz2_dxt2_dus0 = 0;
  out[85] = d4f_dz2_dxt2_dus0;
  const double d4f_dz2_dxt22 = 0;
  out[86] = d4f_dz2_dxt22;
  const double d4f_dz3_dus1 = -_hc1[9]*_t23;
  out[87] = d4f_dz3_dus1;
  const double d4f_dz3_dus0 = _hc0[9]*_t23;
  out[88] = d4f_dz3_dus0;
  const double d4f_dz3_dxt2 = 0;
  out[89] = d4f_dz3_dxt2;
  const double d4f_dz4 = _t23*(_hc0[14]*us0 + _hc1[14]*us1);
  out[90] = d4f_dz4;
  const double d4f_drs_dus13 = 0;
  out[91] = d4f_drs_dus13;
  const double d4f_drs_dus0_dus12 = 0;
  out[92] = d4f_drs_dus0_dus12;
  const double d4f_drs_dus02_dus1 = 0;
  out[93] = d4f_drs_dus02_dus1;
  const double d4f_drs_dus03 = 0;
  out[94] = d4f_drs_dus03;
  const double d4f_drs_dxt2_dus12 = 0;
  out[95] = d4f_drs_dxt2_dus12;
  const double d4f_drs_dxt2_dus0_dus1 = 0;
  out[96] = d4f_drs_dxt2_dus0_dus1;
  const double d4f_drs_dxt2_dus02 = 0;
  out[97] = d4f_drs_dxt2_dus02;
  const double d4f_drs_dxt22_dus1 = 0;
  out[98] = d4f_drs_dxt22_dus1;
  const double d4f_drs_dxt22_dus0 = 0;
  out[99] = d4f_drs_dxt22_dus0;
  const double d4f_drs_dxt23 = 0;
  out[100] = d4f_drs_dxt23;
  const double d4f_drs_dz_dus12 = 0;
  out[101] = d4f_drs_dz_dus12;
  const double d4f_drs_dz_dus0_dus1 = 0;
  out[102] = d4f_drs_dz_dus0_dus1;
  const double d4f_drs_dz_dus02 = 0;
  out[103] = d4f_drs_dz_dus02;
  const double d4f_drs_dz_dxt2_dus1 = 0;
  out[104] = d4f_drs_dz_dxt2_dus1;
  const double d4f_drs_dz_dxt2_dus0 = 0;
  out[105] = d4f_drs_dz_dxt2_dus0;
  const double d4f_drs_dz_dxt22 = 0;
  out[106] = d4f_drs_dz_dxt22;
  const double d4f_drs_dz2_dus1 = _hc1[5]*_t36 - _hc1[5]*_t37;
  out[107] = d4f_drs_dz2_dus1;
  const double d4f_drs_dz2_dus0 = _hc0[5]*_t36 - _hc0[5]*_t37;
  out[108] = d4f_drs_dz2_dus0;
  const double d4f_drs_dz2_dxt2 = 0;
  out[109] = d4f_drs_dz2_dxt2;
  const double d4f_drs_dz3 = _t36*_t45 - _t37*_t45;
  out[110] = d4f_drs_dz3;
  const double d4f_drs2_dus12 = 0;
  out[111] = d4f_drs2_dus12;
  const double d4f_drs2_dus0_dus1 = 0;
  out[112] = d4f_drs2_dus0_dus1;
  const double d4f_drs2_dus02 = 0;
  out[113] = d4f_drs2_dus02;
  const double d4f_drs2_dxt2_dus1 = 0;
  out[114] = d4f_drs2_dxt2_dus1;
  const double d4f_drs2_dxt2_dus0 = 0;
  out[115] = d4f_drs2_dxt2_dus0;
  const double d4f_drs2_dxt22 = 0;
  out[116] = d4f_drs2_dxt22;
  const double d4f_drs2_dz_dus1 = -4.1359685855906248e-6*_hc1[2]*_t20*_t38*_t7 + _hc1[2]*_t50 + _hc1[2]*_t51;
  out[117] = d4f_drs2_dz_dus1;
  const double d4f_drs2_dz_dus0 = 4.1359685855906248e-6*_hc0[2]*_t18*_t19*_t38*_t7 - _hc0[2]*_t50 - _hc0[2]*_t51;
  out[118] = d4f_drs2_dz_dus0;
  const double d4f_drs2_dz_dxt2 = 0;
  out[119] = d4f_drs2_dz_dxt2;
  const double d4f_drs2_dz2 = 4.1359685855906248e-6*_t18*_t19*_t32*_t38*_t7 - _t32*_t50 - _t32*_t51;
  out[120] = d4f_drs2_dz2;
  const double d4f_drs3_dus1 = _t14*_t62 - _t21*_t61 + _t33*_t60 + _t48*_t63;
  out[121] = d4f_drs3_dus1;
  const double d4f_drs3_dus0 = _t13*_t62 + _t13*_t64 - _t13*_t65 + _t13*_t66;
  out[122] = d4f_drs3_dus0;
  const double d4f_drs3_dxt2 = -857.10311728516194*_t1*_t52 + 3.3087748684724998e-5*_t18*_t2*_t56*_t7 - 418689.94502249378*_t41*_t54 - 15.791236120046484*_t59;
  out[123] = d4f_drs3_dxt2;
  const double d4f_drs3_dz = _t25*_t62 + _t25*_t64 - _t25*_t65 + _t25*_t66;
  out[124] = d4f_drs3_dz;
  const double d4f_drs4 = -1554236509.9276359*_t1*_t53*_t55 + 0.12282641999999999*_t10*_t15*_t7*_t9/xc_powi(rs, 6) - 151847119855.25293*(M_PI * M_CBRTPI)*_t15*_t2*_t28/(_t29 * _t29 * _t29 * _t29) - 3181688.4391284334*_t26*_t39*_t42 - 9769.8850133383348*_t30*_t38*_t44;
  out[125] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(zlp_f_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt2, double us0, double us1, double *out) {

  const double _t1 = (0.1e1 / (rs * rs));
  const double _t2 = xc_powr(0.6e1, 2, 3);
  const double _t3 = M_CBRTPI;
  const double _t4 = _t2*_t3;
  const double _t5 = 162.83141688897226*_t4;
  const double _t6 = _t5*rs;
  const double _t7 = xc_x_minus_log1p(_t6);
  const double _t8 = xc_powr(0.6e1, 1, 3);
  const double _t9 = (0.1e1 / _t3);
  const double _t10 = _t8*_t9;
  const double _t11 = M_CBRT2;
  const double _t12 = -0.010775450000000001*_t10*(-0.1e1 / 0.32e2*_t11*(us0 + us1) + (0.1e1 / 0.8e1)*xt2) - 0.41421599999999997*_t10;
  const double _t13 = _t10*_t12*_t7;
#if _KMAX >= 1
  const double _t14 = (M_CBRTPI * M_CBRTPI);
  const double _t15 = (0.1e1 / _t14);
  const double _t16 = _t15*_t7;
  const double _t17 = xc_powr(0.3e1, 2, 3);
  const double _t18 = _t1*_t17;
  const double _t19 = 6.8932809759843754e-7*_t16*_t18;
  const double _t20 = 1.3786561951968751e-6*_t16;
  const double _t21 = (0.1e1 / (rs * rs * rs));
  const double _t22 = (0.1e1 / rs);
  const double _t23 = _t6 + 0.1e1;
  const double _t24 = (0.1e1 / _t23);
  const double _t25 = _t22*_t24;
#endif
#if _KMAX >= 2
  const double _t26 = 0.32898408583430178*_t11*_t25 - _t17*_t20*_t21;
  const double _t27 = (0.1e1 / (rs * rs * rs * rs));
  const double _t28 = (0.1e1 / (_t23 * _t23));
  const double _t29 = _t22*_t28;
  const double _t30 = _t12*_t14*_t8;
  const double _t31 = _t1*_t24;
  const double _t32 = _t12*_t4;
#endif
#if _KMAX >= 3
  const double _t33 = -0.98695225750290527*_t11*_t31 + 4.1359685855906248e-6*_t15*_t17*_t27*_t7 - 107.13788966064526*_t17*_t29*_t3;
  const double _t34 = (0.1e1 / (_t23 * _t23 * _t23));
  const double _t35 = _t22*_t34;
  const double _t36 = M_PI*_t12;
  const double _t37 = xc_powi(rs, -5);
  const double _t38 = _t1*_t28;
  const double _t39 = _t21*_t24;
#endif
#if _KMAX >= 4
  const double _t40 = _t14*_t35;
  const double _t41 = 3.9478090300116211*_t11*_t39 - 1.6543874342362499e-5*_t16*_t17*_t37 + 428.55155864258097*_t18*_t28*_t3 + 104672.48625562344*xc_powr(0.12e2, 1, 3)*_t40;
#endif

  const double f = 0.0010235534999999999*_t1*_t13;
  out[0] = f;
#if _KMAX >= 1
  const double df_dus1 = _t19;
  out[1] = df_dus1;
  const double df_dus0 = _t19;
  out[2] = df_dus0;
  const double df_dxt2 = -_t1*_t2*_t20;
  out[3] = df_dxt2;
  const double df_drs = _t12*_t25*_t5 - 0.0020471069999999998*_t13*_t21;
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dus12 = 0;
  out[5] = d2f_dus12;
  const double d2f_dus0_dus1 = 0;
  out[6] = d2f_dus0_dus1;
  const double d2f_dus02 = 0;
  out[7] = d2f_dus02;
  const double d2f_dxt2_dus1 = 0;
  out[8] = d2f_dxt2_dus1;
  const double d2f_dxt2_dus0 = 0;
  out[9] = d2f_dxt2_dus0;
  const double d2f_dxt22 = 0;
  out[10] = d2f_dxt22;
  const double d2f_drs_dus1 = _t26;
  out[11] = d2f_drs_dus1;
  const double d2f_drs_dus0 = _t26;
  out[12] = d2f_drs_dus0;
  const double d2f_drs_dxt2 = 2.7573123903937501e-6*_t15*_t2*_t21*_t7 - 1.3159363433372071*_t25;
  out[13] = d2f_drs_dxt2;
  const double d2f_drs2 = 0.0061413209999999999*_t12*_t27*_t7*_t8*_t9 - 159084.42195642169*_t29*_t30 - 488.49425066691674*_t31*_t32;
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dus13 = 0;
  out[15] = d3f_dus13;
  const double d3f_dus0_dus12 = 0;
  out[16] = d3f_dus0_dus12;
  const double d3f_dus02_dus1 = 0;
  out[17] = d3f_dus02_dus1;
  const double d3f_dus03 = 0;
  out[18] = d3f_dus03;
  const double d3f_dxt2_dus12 = 0;
  out[19] = d3f_dxt2_dus12;
  const double d3f_dxt2_dus0_dus1 = 0;
  out[20] = d3f_dxt2_dus0_dus1;
  const double d3f_dxt2_dus02 = 0;
  out[21] = d3f_dxt2_dus02;
  const double d3f_dxt22_dus1 = 0;
  out[22] = d3f_dxt22_dus1;
  const double d3f_dxt22_dus0 = 0;
  out[23] = d3f_dxt22_dus0;
  const double d3f_dxt23 = 0;
  out[24] = d3f_dxt23;
  const double d3f_drs_dus12 = 0;
  out[25] = d3f_drs_dus12;
  const double d3f_drs_dus0_dus1 = 0;
  out[26] = d3f_drs_dus0_dus1;
  const double d3f_drs_dus02 = 0;
  out[27] = d3f_drs_dus02;
  const double d3f_drs_dxt2_dus1 = 0;
  out[28] = d3f_drs_dxt2_dus1;
  const double d3f_drs_dxt2_dus0 = 0;
  out[29] = d3f_drs_dxt2_dus0;
  const double d3f_drs_dxt22 = 0;
  out[30] = d3f_drs_dxt22;
  const double d3f_drs2_dus1 = _t33;
  out[31] = d3f_drs2_dus1;
  const double d3f_drs2_dus0 = _t33;
  out[32] = d3f_drs2_dus0;
  const double d3f_drs2_dxt2 = -8.2719371711812496e-6*_t16*_t2*_t27 + 214.27577932129051*_t29*_t4 + 3.9478090300116211*_t31;
  out[33] = d3f_drs2_dxt2;
  const double d3f_drs3 = -0.024565284*_t13*_t37 + 636337.68782568665*_t30*_t38 + 1953.977002667667*_t32*_t39 + 310847301.98552728*_t35*_t36;
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dus14 = 0;
  out[35] = d4f_dus14;
  const double d4f_dus0_dus13 = 0;
  out[36] = d4f_dus0_dus13;
  const double d4f_dus02_dus12 = 0;
  out[37] = d4f_dus02_dus12;
  const double d4f_dus03_dus1 = 0;
  out[38] = d4f_dus03_dus1;
  const double d4f_dus04 = 0;
  out[39] = d4f_dus04;
  const double d4f_dxt2_dus13 = 0;
  out[40] = d4f_dxt2_dus13;
  const double d4f_dxt2_dus0_dus12 = 0;
  out[41] = d4f_dxt2_dus0_dus12;
  const double d4f_dxt2_dus02_dus1 = 0;
  out[42] = d4f_dxt2_dus02_dus1;
  const double d4f_dxt2_dus03 = 0;
  out[43] = d4f_dxt2_dus03;
  const double d4f_dxt22_dus12 = 0;
  out[44] = d4f_dxt22_dus12;
  const double d4f_dxt22_dus0_dus1 = 0;
  out[45] = d4f_dxt22_dus0_dus1;
  const double d4f_dxt22_dus02 = 0;
  out[46] = d4f_dxt22_dus02;
  const double d4f_dxt23_dus1 = 0;
  out[47] = d4f_dxt23_dus1;
  const double d4f_dxt23_dus0 = 0;
  out[48] = d4f_dxt23_dus0;
  const double d4f_dxt24 = 0;
  out[49] = d4f_dxt24;
  const double d4f_drs_dus13 = 0;
  out[50] = d4f_drs_dus13;
  const double d4f_drs_dus0_dus12 = 0;
  out[51] = d4f_drs_dus0_dus12;
  const double d4f_drs_dus02_dus1 = 0;
  out[52] = d4f_drs_dus02_dus1;
  const double d4f_drs_dus03 = 0;
  out[53] = d4f_drs_dus03;
  const double d4f_drs_dxt2_dus12 = 0;
  out[54] = d4f_drs_dxt2_dus12;
  const double d4f_drs_dxt2_dus0_dus1 = 0;
  out[55] = d4f_drs_dxt2_dus0_dus1;
  const double d4f_drs_dxt2_dus02 = 0;
  out[56] = d4f_drs_dxt2_dus02;
  const double d4f_drs_dxt22_dus1 = 0;
  out[57] = d4f_drs_dxt22_dus1;
  const double d4f_drs_dxt22_dus0 = 0;
  out[58] = d4f_drs_dxt22_dus0;
  const double d4f_drs_dxt23 = 0;
  out[59] = d4f_drs_dxt23;
  const double d4f_drs2_dus12 = 0;
  out[60] = d4f_drs2_dus12;
  const double d4f_drs2_dus0_dus1 = 0;
  out[61] = d4f_drs2_dus0_dus1;
  const double d4f_drs2_dus02 = 0;
  out[62] = d4f_drs2_dus02;
  const double d4f_drs2_dxt2_dus1 = 0;
  out[63] = d4f_drs2_dxt2_dus1;
  const double d4f_drs2_dxt2_dus0 = 0;
  out[64] = d4f_drs2_dxt2_dus0;
  const double d4f_drs2_dxt22 = 0;
  out[65] = d4f_drs2_dxt22;
  const double d4f_drs3_dus1 = _t41;
  out[66] = d4f_drs3_dus1;
  const double d4f_drs3_dus0 = _t41;
  out[67] = d4f_drs3_dus0;
  const double d4f_drs3_dxt2 = 3.3087748684724998e-5*_t15*_t2*_t37*_t7 - 857.10311728516194*_t38*_t4 - 15.791236120046484*_t39 - 418689.94502249378*_t40*_t8;
  out[68] = d4f_drs3_dxt2;
  const double d4f_drs4 = -1554236509.9276359*_t1*_t34*_t36 - 151847119855.25293*(M_PI * M_CBRTPI)*_t12*_t2*_t22/(_t23 * _t23 * _t23 * _t23) + 0.12282641999999999*_t12*_t7*_t8*_t9/xc_powi(rs, 6) - 3181688.4391284334*_t21*_t28*_t30 - 9769.8850133383348*_t24*_t27*_t32;
  out[69] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = _t4/xc_powr(na, 1, 3);
  const double _t6 = xc_powr(na, -8, 3);
  const double _t7 = xc_powr(na, -5, 3);
  const double _t8 = xc_powr(0.2e1, 2, 3);
  const double _t9 = _t7*_t8;
  const double _t10 = _t9*la;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(zlp_f_z0_k, _KMAX)(p, _t5, _t6*gaa, _t10, _t10, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t11 = xc_powr(na, -11, 3);
  const double _t12 = (0.8e1 / 0.3e1)*_t11;
  const double _t15 = (0.5e1 / 0.3e1)*_t6;
  const double _t20 = xc_powr(na, -4, 3);
  const double _t21 = (0.1e1 / 0.6e1)*_t20;
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(zlp_f_z0_k, _KMAX)(p, _t5, 0, 0, 0, _hc1);
  const double _t13 = _hc1[3]*_t12;
  const double _t14 = _hc1[1]*_t8;
  const double _t16 = _t14*_t15;
  const double _t17 = _hc1[2]*_t8;
  const double _t18 = _t15*_t17;
  const double _t19 = _hc0[4]*_t3;
  const double _t22 = _hc1[1]*_t9 + _hc1[2]*_t9;
  const double dF_dna = _hc0[0] + na*(-_t13*gaa - _t16*la - _t18*la - _t19*_t21);
  const double dF_dgaa = _hc1[3]*_t7;
  const double dF_dla = _t22*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
#endif
#if _KMAX >= 2
  const double _t24 = (0.10e2 / 0.3e1)*_t6;
  const double _t27 = (0.1e1 / 0.3e1)*_t20;
  const double _t28 = xc_powr(na, -14, 3);
  const double _t29 = (0.88e2 / 0.9e1)*_t28;
  const double _t31 = (0.40e2 / 0.9e1)*_t11;
  const double _t34 = xc_powr(na, -7, 3);
  const double _t35 = (0.2e1 / 0.9e1)*_t34;
  const double _t36 = M_CBRT3*_t2;
  const double _t38 = (0.1e1 / (na * na * na * na));
  const double _t39 = (0.5e1 / 0.9e1)*_t38;
  const double _t45 = xc_powi(na, -5);
  const double _t46 = (0.4e1 / 0.9e1)*_t45;
  const double _t48 = _t15*_t8;
  const double _t51 = _t21*_t3;
  const double _t54 = (0.1e1 / 0.6e1)*_t38;
  const double _t23 = (0.16e2 / 0.3e1)*_hc1[3]*_t11;
  const double _t25 = _t14*_t24;
  const double _t26 = _t17*_t24;
  const double _t30 = _hc1[3]*_t29;
  const double _t32 = _t14*_t31;
  const double _t33 = _t17*_t31;
  const double _t37 = _hc1[11]*_t36;
  const double _t40 = _t37*_t39;
  const double _t41 = _hc1[12]*_t36;
  const double _t42 = _t39*_t41;
  const double _t43 = _hc1[13]*gaa;
  const double _t44 = _t3*_t43;
  const double _t47 = _hc1[13]*_t12;
  const double _t49 = _hc1[11]*_t48;
  const double _t50 = _hc1[12]*_t48;
  const double _t52 = -_hc0[14]*_t51 - _t47*gaa - _t49*la - _t50*la;
  const double _t53 = _hc1[13]*_t3;
  const double _t55 = _hc1[11]*_t9 + _hc1[12]*_t9;
  const double d2F_dna2 = -_t19*_t27 - _t23*gaa - _t25*la - _t26*la + na*(_t19*_t35 + _t30*gaa + _t32*la + _t33*la + _t40*la + _t42*la + _t44*_t46 - _t51*_t52);
  const double d2F_dna_dgaa = _hc1[3]*_t6 + na*(-_t13 - _t53*_t54);
  const double d2F_dna_dla = _t22 + na*(-_t16 - _t18 - _t51*_t55);
  const double d2F_dgaa2 = 0;
  const double d2F_dgaa_dla = 0;
  const double d2F_dla2 = 0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
#endif
#if _KMAX >= 3
  const double _t56 = (0.88e2 / 0.3e1)*_t28;
  const double _t58 = (0.40e2 / 0.3e1)*_t11;
  const double _t61 = (0.2e1 / 0.3e1)*_t34;
  const double _t62 = (0.5e1 / 0.3e1)*_t38;
  const double _t65 = _t20*_t4;
  const double _t66 = xc_powr(na, -17, 3);
  const double _t67 = (0.1232e4 / 0.27e2)*_t66;
  const double _t69 = (0.440e3 / 0.27e2)*_t28;
  const double _t72 = xc_powr(na, -10, 3);
  const double _t73 = (0.14e2 / 0.27e2)*_t72;
  const double _t74 = (0.80e2 / 0.27e2)*_t45;
  const double _t77 = xc_powi(na, -6);
  const double _t78 = (0.88e2 / 0.27e2)*_t77;
  const double _t79 = xc_powr(0.6e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  const double _t81 = (0.1e1 / 0.36e2)*_t6;
  const double _t84 = _t3*_t35;
  const double _t85 = _t79*_t81;
  const double _t91 = _t31*_t8;
  const double _t94 = _t36*_t39;
  const double _t98 = _t3*_t46;
  const double _t104 = (0.2e1 / 0.3e1)*_t45;
  const double _t105 = _t3*_t54;
  const double _t57 = _hc1[3]*_t56;
  const double _t59 = _t14*_t58;
  const double _t60 = _t17*_t58;
  const double _t63 = _t37*_t62;
  const double _t64 = _t41*_t62;
  const double _t68 = _hc1[3]*_t67;
  const double _t70 = _t14*_t69;
  const double _t71 = _t17*_t69;
  const double _t75 = _t37*_t74;
  const double _t76 = _t41*_t74;
  const double _t80 = _hc1[33]*_t79;
  const double _t82 = _t35*_t53 + _t80*_t81;
  const double _t83 = _t12*_t82;
  const double _t86 = _hc1[11]*_t84 + _hc1[31]*_t85;
  const double _t87 = _t48*_t86;
  const double _t88 = _hc1[12]*_t84 + _hc1[32]*_t85;
  const double _t89 = _t48*_t88;
  const double _t90 = _hc1[13]*_t29;
  const double _t92 = _hc1[11]*_t91;
  const double _t93 = _hc1[12]*_t91;
  const double _t95 = _hc1[31]*_t94;
  const double _t96 = _hc1[32]*_t94;
  const double _t97 = _hc1[33]*gaa;
  const double _t99 = _hc1[33]*_t12;
  const double _t100 = _hc1[31]*_t48;
  const double _t101 = _hc1[32]*_t48;
  const double _t102 = -_hc0[34]*_t51 - _t100*la - _t101*la - _t99*gaa;
  const double _t103 = _hc0[14]*_t84 - _t102*_t51 + _t90*gaa + _t92*la + _t93*la + _t95*la + _t96*la + _t97*_t98;
  const double _t106 = -_hc1[33]*_t105 - _t47;
  const double _t107 = _t3*_t55;
  const double _t108 = _hc1[31]*_t9 + _hc1[32]*_t9;
  const double _t109 = -_t108*_t51 - _t49 - _t50;
  const double d3F_dna3 = _t19*_t61 + (0.4e1 / 0.3e1)*_t44*_t45 - _t52*_t65 + _t57*gaa + _t59*la + _t60*la + _t63*la + _t64*la + na*((0.4e1 / 0.9e1)*_t1*_t2*_t34*_t52 - _t103*_t51 - _t19*_t73 - _t44*_t78 - _t68*gaa - _t70*la - _t71*la - _t75*la - _t76*la - _t83*gaa - _t87*la - _t89*la);
  const double d3F_dna2_dgaa = -_t23 - 0.1e1 / 0.3e1*_t38*_t53 + na*(_t104*_t53 - _t106*_t51 + _t30);
  const double d3F_dna2_dla = -_t107*_t27 - _t25 - _t26 + na*(-_t109*_t51 + _t32 + _t33 + _t40 + _t42 + _t55*_t84);
  const double d3F_dna_dgaa2 = 0;
  const double d3F_dna_dgaa_dla = 0;
  const double d3F_dna_dla2 = 0;
  const double d3F_dgaa3 = 0;
  const double d3F_dgaa2_dla = 0;
  const double d3F_dgaa_dla2 = 0;
  const double d3F_dla3 = 0;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
#endif
#if _KMAX >= 4
  const double _t112 = (0.1760e4 / 0.27e2)*_t28;
  const double _t115 = (0.320e3 / 0.27e2)*_t45;
  const double _t118 = _t8*la;
  const double _t119 = (0.20e2 / 0.3e1)*_t118*_t6;
  const double _t121 = (0.6160e4 / 0.81e2)*_t66;
  const double _t122 = (0.440e3 / 0.27e2)*_t77;
  const double _t123 = _t118*_t58;
  const double _t124 = (0.2e1 / 0.27e2)*_t11;
  const double _t126 = _t12*gaa;
  const double _t127 = _t3*_t73;
  const double _t128 = _t124*_t79;
  const double _t130 = _t48*la;
  const double _t132 = _t118*_t69;
  const double _t133 = _t36*_t74*la;
  const double _t134 = _t91*la;
  const double _t135 = _t94*la;
  const double _t110 = _hc1[3]*gaa;
  const double _t111 = _t14*la;
  const double _t113 = _t17*la;
  const double _t114 = _t37*la;
  const double _t116 = _t41*la;
  const double _t117 = _t82*gaa;
  const double _t120 = _t103*_t3;
  const double _t125 = _hc1[33]*_t84 + _hc1[68]*_t85;
  const double _t129 = _hc1[31]*_t84 + _hc1[66]*_t85;
  const double _t131 = _hc1[32]*_t84 + _hc1[67]*_t85;
  const double d4F_dna4 = (0.16e2 / 0.9e1)*_t1*_t2*_t34*_t52 - 0.32e2 / 0.3e1*_t11*_t117 - 0.4928e4 / 0.27e2*_t110*_t66 - _t111*_t112 - _t112*_t113 - _t114*_t115 - _t115*_t116 - _t119*_t86 - _t119*_t88 - 0.2e1 / 0.3e1*_t120*_t20 - 0.56e2 / 0.27e2*_t19*_t72 - 0.352e3 / 0.27e2*_t44*_t77 + na*((0.20944e5 / 0.81e2)*_t110/xc_powr(na, 20, 3) + _t111*_t121 + _t113*_t121 + _t114*_t122 + _t116*_t122 + _t117*_t56 + _t120*_t61 + _t123*_t86 + _t123*_t88 - _t126*(-_t124*_t80 - _t125*_t51 - _t53*_t73) - _t130*(-_hc1[11]*_t127 - _hc1[31]*_t128 - _t129*_t51) - _t130*(-_hc1[12]*_t127 - _hc1[32]*_t128 - _t131*_t51) + (0.140e3 / 0.81e2)*_t19/xc_powr(na, 13, 3) - 0.14e2 / 0.9e1*_t3*_t52*_t72 + (0.616e3 / 0.27e2)*_t44/xc_powi(na, 7) - _t51*(-_hc0[14]*_t127 - _hc1[11]*_t132 - _hc1[12]*_t132 - _hc1[31]*_t133 - _hc1[32]*_t133 + (0.4e1 / 0.9e1)*_t1*_t102*_t2*_t34 - _t125*_t126 - _t129*_t130 - _t130*_t131 - _t3*_t78*_t97 - _t43*_t67 - _t51*(_hc0[34]*_t84 + _hc1[31]*_t134 + _hc1[32]*_t134 + _hc1[66]*_t135 + _hc1[67]*_t135 + _hc1[68]*_t98*gaa + _t29*_t97 - _t51*(-_hc0[69]*_t51 - _hc1[66]*_t130 - _hc1[67]*_t130 - _hc1[68]*_t126))));
  const double d4F_dna3_dgaa = -_t106*_t65 + 0.2e1*_t45*_t53 + _t57 + na*((0.4e1 / 0.9e1)*_t1*_t106*_t2*_t34 - _t51*(_hc1[33]*_t104*_t3 - _t51*(-_hc1[68]*_t105 - _t99) + _t90) - 0.34e2 / 0.9e1*_t53*_t77 - _t68 - _t83);
  const double d4F_dna3_dla = _t107*_t61 - _t109*_t65 + _t59 + _t60 + _t63 + _t64 + na*((0.4e1 / 0.9e1)*_t1*_t109*_t2*_t34 - _t107*_t73 - _t51*(_t108*_t84 - _t51*(-_t100 - _t101 - _t51*(_hc1[66]*_t9 + _hc1[67]*_t9)) + _t92 + _t93 + _t95 + _t96) - _t70 - _t71 - _t75 - _t76 - _t87 - _t89);
  const double d4F_dna2_dgaa2 = 0;
  const double d4F_dna2_dgaa_dla = 0;
  const double d4F_dna2_dla2 = 0;
  const double d4F_dna_dgaa3 = 0;
  const double d4F_dna_dgaa2_dla = 0;
  const double d4F_dna_dgaa_dla2 = 0;
  const double d4F_dna_dla3 = 0;
  const double d4F_dgaa4 = 0;
  const double d4F_dgaa3_dla = 0;
  const double d4F_dgaa2_dla2 = 0;
  const double d4F_dgaa_dla3 = 0;
  const double d4F_dla4 = 0;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gab = sigma[1];
  const double gbb = sigma[2];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = _t5/xc_powr(_t1, 1, 3);
  const double _t7 = na - nb;
  const double _t8 = (0.1e1 / _t1);
  const double _t9 = _t7*_t8;
  const double _t10 = xc_powr(_t1, -8, 3);
  const double _t11 = gaa + 0.2e1*gab + gbb;
  const double _t12 = xc_powr(na, -5, 3);
  const double _t13 = _t12*la;
  const double _t14 = xc_powr(nb, -5, 3);
  const double _t15 = _t14*lb;
  double _hc0[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(zlp_f_k, _KMAX)(p, _t6, _t9, _t10*_t11, _t13, _t15, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t16 = xc_powr(_t1, -11, 3);
  const double _t20 = xc_powr(_t1, -4, 3);
  const double _t21 = (0.1e1 / 0.6e1)*_t20;
  const double _t23 = (0.1e1 / (_t1 * _t1));
  const double _t24 = _t23*_t7;
  const double _t25 = -_t24 + _t8;
  const double _t26 = xc_powr(na, -8, 3);
  const double _t27 = (0.5e1 / 0.3e1)*_t26;
  const double _t30 = -_t24 - _t8;
  const double _t31 = xc_powr(nb, -8, 3);
  const double _t32 = (0.5e1 / 0.3e1)*_t31;
  double _hc1[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(zlp_f_k, _KMAX)(p, _t6, _t9, 0, _t13, _t15, _hc1);
  double _hc2[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(zlp_f_k, _KMAX)(p, _t6, 0, 0, 0, 0, _hc2);
  double _hc3[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(zlp_f_k, _KMAX)(p, _t6, _t9, 0, 0, 0, _hc3);
  const double _t17 = _hc2[3]*_t16;
  const double _t18 = (0.8e1 / 0.3e1)*_t17;
  const double _t19 = _hc0[5]*_t4;
  const double _t22 = _t11*_t18 + _t19*_t21;
  const double _t28 = _hc3[2]*_t27;
  const double _t29 = -_hc1[4]*_t25 + _t28*la;
  const double _t33 = _hc3[1]*_t32;
  const double _t34 = -_hc1[4]*_t30 + _t33*lb;
  const double _t35 = _hc2[3]/xc_powr(_t1, 5, 3);
  const double _t36 = _hc3[2]*_t12;
  const double _t37 = _hc3[1]*_t14;
  const double dF_dna = _hc0[0] + _t1*(-_t22 - _t29);
  const double dF_dnb = _hc0[0] + _t1*(-_t22 - _t34);
  const double dF_dgaa = _t35;
  const double dF_dgab = 0.2e1*_t35;
  const double dF_dgbb = _t35;
  const double dF_dla = _t1*_t36;
  const double dF_dlb = _t1*_t37;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 1] += dF_dlb;
#endif
#if _KMAX >= 2
  const double _t38 = xc_powr(_t1, -14, 3);
  const double _t41 = xc_powr(_t1, -7, 3);
  const double _t42 = (0.2e1 / 0.9e1)*_t41;
  const double _t45 = xc_powi(_t1, -5);
  const double _t46 = (0.4e1 / 0.9e1)*_t45;
  const double _t48 = 0.2e1*_t23;
  const double _t49 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t50 = 0.2e1*_t49;
  const double _t51 = _t50*_t7;
  const double _t52 = -_t48 + _t51;
  const double _t55 = _t21*_t4;
  const double _t64 = xc_powr(na, -11, 3);
  const double _t65 = (0.40e2 / 0.9e1)*_t64;
  const double _t73 = (0.10e2 / 0.3e1)*_t26;
  const double _t76 = (0.1e1 / 0.3e1)*_t20;
  const double _t87 = _t48 + _t51;
  const double _t94 = xc_powr(nb, -11, 3);
  const double _t95 = (0.40e2 / 0.9e1)*_t94;
  const double _t100 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t108 = _t14*_t25;
  const double _t39 = _hc2[3]*_t38;
  const double _t40 = (0.88e2 / 0.9e1)*_t39;
  const double _t43 = _hc2[18]*_t11;
  const double _t44 = _t4*_t43;
  const double _t47 = _t11*_t40 + _t19*_t42 + _t44*_t46;
  const double _t53 = _hc1[4]*_t52;
  const double _t54 = _hc3[13]*_t27;
  const double _t56 = _hc1[19]*_t55;
  const double _t57 = _hc1[15]*_t25 - _t54*la - _t56;
  const double _t58 = _t25*_t57;
  const double _t59 = _hc3[17]*_t55;
  const double _t60 = -_t59;
  const double _t61 = _hc3[13]*_t25;
  const double _t62 = _t60 + _t61;
  const double _t63 = _t27*_t62;
  const double _t66 = _hc3[2]*_t65;
  const double _t67 = _hc3[17]*_t27;
  const double _t68 = _hc2[18]*_t16;
  const double _t69 = (0.8e1 / 0.3e1)*_t68;
  const double _t70 = _hc0[20]*_t55 + _t11*_t69;
  const double _t71 = _hc1[19]*_t25 - _t67*la - _t70;
  const double _t72 = _t53 - _t55*_t71 + _t58 - _t63*la + _t66*la;
  const double _t74 = _hc3[2]*_t73;
  const double _t75 = (0.16e2 / 0.3e1)*_t17;
  const double _t77 = _t11*_t75 + _t19*_t76;
  const double _t78 = _hc3[12]*_t32;
  const double _t79 = _hc1[15]*_t30 - _t56 - _t78*lb;
  const double _t80 = _t25*_t79;
  const double _t81 = _hc3[13]*_t30;
  const double _t82 = _t60 + _t81;
  const double _t83 = _t27*_t82;
  const double _t84 = _hc3[16]*_t32;
  const double _t85 = _hc1[19]*_t30 - _t70 - _t84*lb;
  const double _t86 = _t47 - _t55*_t85;
  const double _t88 = _hc1[4]*_t87;
  const double _t89 = _t30*_t79;
  const double _t90 = _hc3[16]*_t55;
  const double _t91 = _hc3[12]*_t30;
  const double _t92 = -_t90 + _t91;
  const double _t93 = _t32*_t92;
  const double _t96 = _hc3[1]*_t95;
  const double _t97 = _t88 + _t89 - _t93*lb + _t96*lb;
  const double _t98 = (0.10e2 / 0.3e1)*_hc3[1]*_t31;
  const double _t99 = _hc2[3]*_t10;
  const double _t101 = _hc2[18]*_t4;
  const double _t102 = _t100*_t101;
  const double _t103 = _t1*(-0.1e1 / 0.6e1*_t102 - _t18) + _t99;
  const double _t104 = (0.1e1 / 0.3e1)*_t102 + _t75;
  const double _t105 = -_t1*_t104 + 0.2e1*_t99;
  const double _t106 = _t12*_t59;
  const double _t107 = _t14*_t90;
  const double _t109 = _hc3[12]*_t108;
  const double _t110 = _t12*_t81;
  const double d2F_dna2 = 0.2e1*_hc1[4]*_t25 + _t1*(_t47 + _t72) - _t74*la - _t77;
  const double d2F_dna_dnb = _t1*(_hc1[4]*_t51 + _t80 - _t83*la + _t86) - _t29 - _t34 - _t77;
  const double d2F_dnb2 = 0.2e1*_hc1[4]*_t30 + _t1*(_t86 + _t97) - _t77 - _t98*lb;
  const double d2F_dna_dgaa = _t103;
  const double d2F_dna_dgab = _t105;
  const double d2F_dna_dgbb = _t103;
  const double d2F_dnb_dgaa = _t103;
  const double d2F_dnb_dgab = _t105;
  const double d2F_dnb_dgbb = _t103;
  const double d2F_dna_dla = _t1*(_hc3[13]*_t12*_t25 - _t106 - _t28) + _t36;
  const double d2F_dna_dlb = _t1*(-_t107 + _t109) + _t37;
  const double d2F_dnb_dla = _t1*(-_t106 + _t110) + _t36;
  const double d2F_dnb_dlb = _t1*(_hc3[12]*_t14*_t30 - _t107 - _t33) + _t37;
  const double d2F_dgaa2 = 0;
  const double d2F_dgaa_dgab = 0;
  const double d2F_dgaa_dgbb = 0;
  const double d2F_dgab2 = 0;
  const double d2F_dgab_dgbb = 0;
  const double d2F_dgbb2 = 0;
  const double d2F_dgaa_dla = 0;
  const double d2F_dgaa_dlb = 0;
  const double d2F_dgab_dla = 0;
  const double d2F_dgab_dlb = 0;
  const double d2F_dgbb_dla = 0;
  const double d2F_dgbb_dlb = 0;
  const double d2F_dla2 = 0;
  const double d2F_dla_dlb = 0;
  const double d2F_dlb2 = 0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 1] += d2F_dna_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 4] += d2F_dnb_dgab;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 1] += d2F_dna_dlb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 2] += d2F_dnb_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += d2F_dnb_dlb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 1] += d2F_dgaa_dgab;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 2] += d2F_dgaa_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 3] += d2F_dgab2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 4] += d2F_dgab_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 1] += d2F_dgaa_dlb;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 2] += d2F_dgab_dla;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 3] += d2F_dgab_dlb;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 4] += d2F_dgbb_dla;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 5] += d2F_dgbb_dlb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 1] += d2F_dla_dlb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 2] += d2F_dlb2;
#endif
#if _KMAX >= 3
  const double _t111 = 0.6e1*_t49;
  const double _t112 = _t100*_t7;
  const double _t113 = 0.6e1*_t112;
  const double _t114 = _t111 - _t113;
  const double _t116 = _t4*_t42;
  const double _t137 = xc_powr(na, -14, 3);
  const double _t138 = (0.440e3 / 0.27e2)*_t137;
  const double _t145 = (0.8e1 / 0.3e1)*_t16;
  const double _t156 = xc_powr(0.6e1, 2, 3);
  const double _t157 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t159 = (0.1e1 / 0.36e2)*_t10;
  const double _t163 = xc_powr(_t1, -17, 3);
  const double _t167 = xc_powr(_t1, -10, 3);
  const double _t168 = (0.14e2 / 0.27e2)*_t167;
  const double _t170 = xc_powi(_t1, -6);
  const double _t171 = (0.88e2 / 0.27e2)*_t170;
  const double _t174 = 0.5e1*_t26;
  const double _t176 = (0.40e2 / 0.3e1)*_t64;
  const double _t178 = _t20*_t5;
  const double _t180 = (0.2e1 / 0.3e1)*_t41;
  const double _t182 = -_t113 + 0.2e1*_t49;
  const double _t208 = 0.4e1*_t49;
  const double _t227 = -_t111 - _t113;
  const double _t232 = xc_powr(nb, -14, 3);
  const double _t233 = (0.440e3 / 0.27e2)*_t232;
  const double _t237 = (0.40e2 / 0.3e1)*_t94;
  const double _t245 = _t4*_t76;
  const double _t264 = _t14*_t52;
  const double _t115 = _hc3[13]*_t65;
  const double _t117 = _hc1[19]*_t116;
  const double _t118 = _hc3[48]*_t55;
  const double _t119 = -_t118;
  const double _t120 = _hc3[38]*_t25 + _t119;
  const double _t121 = _t120*_t27;
  const double _t122 = _hc3[48]*_t27;
  const double _t123 = _hc1[54]*_t55;
  const double _t124 = _hc1[50]*_t25 - _t122*la - _t123;
  const double _t125 = _hc3[38]*_t27;
  const double _t126 = _hc1[50]*_t55;
  const double _t127 = _hc1[40]*_t25 - _t125*la - _t126;
  const double _t128 = _hc1[15]*_t52 + _t115*la + _t117 - _t121*la - _t124*_t55 + _t127*_t25;
  const double _t129 = _hc3[17]*_t116;
  const double _t130 = _hc3[13]*_t52;
  const double _t131 = _hc3[52]*_t55;
  const double _t132 = -_t131;
  const double _t133 = _hc3[48]*_t25 + _t132;
  const double _t134 = _t120*_t25 + _t129 + _t130 - _t133*_t55;
  const double _t135 = _t134*_t27;
  const double _t136 = _t135*la;
  const double _t139 = _hc3[2]*_t138;
  const double _t140 = _t139*la;
  const double _t141 = -0.4e1 / 0.9e1*_t2*_t3*_t41*_t71;
  const double _t142 = _t133*_t27;
  const double _t143 = _hc3[17]*_t65;
  const double _t144 = _hc3[52]*_t27;
  const double _t146 = _hc2[53]*_t145;
  const double _t147 = _hc0[55]*_t55 + _t11*_t146;
  const double _t148 = _hc1[54]*_t25 - _t144*la - _t147;
  const double _t149 = _hc2[18]*_t38;
  const double _t150 = (0.88e2 / 0.9e1)*_t149;
  const double _t151 = _hc2[53]*_t4;
  const double _t152 = _t151*_t45;
  const double _t153 = _hc0[20]*_t116 + _t11*_t150 + (0.4e1 / 0.9e1)*_t11*_t152;
  const double _t154 = _hc1[19]*_t52 + _t124*_t25 - _t142*la + _t143*la - _t148*_t55 + _t153;
  const double _t155 = _t154*_t55;
  const double _t158 = _hc2[53]*_t156*_t157;
  const double _t160 = _t101*_t42 + _t158*_t159;
  const double _t161 = _t145*_t160;
  const double _t162 = _t11*_t161;
  const double _t164 = _hc2[3]*_t163;
  const double _t165 = (0.1232e4 / 0.27e2)*_t164;
  const double _t166 = _t11*_t165;
  const double _t169 = _t168*_t19;
  const double _t172 = _t171*_t44;
  const double _t173 = _t162 + _t166 + _t169 + _t172;
  const double _t175 = _t174*_t62;
  const double _t177 = _hc3[2]*_t176;
  const double _t179 = (0.88e2 / 0.3e1)*_t39;
  const double _t181 = _t11*_t179 + _t180*_t19 + (0.4e1 / 0.3e1)*_t44*_t45;
  const double _t183 = _hc1[4]*_t182;
  const double _t184 = _t65*_t82;
  const double _t185 = _t52*_t79;
  const double _t186 = _hc3[38]*_t30;
  const double _t187 = _t119 + _t186;
  const double _t188 = _hc3[13]*_t51;
  const double _t189 = _hc3[48]*_t30;
  const double _t190 = _t132 + _t189;
  const double _t191 = _t129 - _t190*_t55;
  const double _t192 = _t187*_t25 + _t188 + _t191;
  const double _t193 = _t192*_t27;
  const double _t194 = _hc3[37]*_t32;
  const double _t195 = _hc1[40]*_t30 - _t126 - _t194*lb;
  const double _t196 = _t187*_t27;
  const double _t197 = _hc3[47]*_t32;
  const double _t198 = _hc1[50]*_t30 - _t123 - _t197*lb;
  const double _t199 = _t117 - _t198*_t55;
  const double _t200 = _hc1[15]*_t51 + _t195*_t25 - _t196*la + _t199;
  const double _t201 = _t200*_t25;
  const double _t202 = _t190*_t27;
  const double _t203 = _hc3[51]*_t32;
  const double _t204 = _hc1[54]*_t30 - _t147 - _t203*lb;
  const double _t205 = _t153 - _t204*_t55;
  const double _t206 = _hc1[19]*_t51 + _t198*_t25 - _t202*la + _t205;
  const double _t207 = _t4*_t85;
  const double _t209 = _hc1[4]*_t208;
  const double _t210 = _t73*_t82;
  const double _t211 = _t209*_t7 - _t210*la + 0.2e1*_t80;
  const double _t212 = _hc3[47]*_t55;
  const double _t213 = _hc3[37]*_t30 - _t212;
  const double _t214 = _t213*_t32;
  const double _t215 = _hc3[12]*_t95;
  const double _t216 = _hc1[15]*_t87 + _t195*_t30 + _t199 - _t214*lb + _t215*lb;
  const double _t217 = _hc3[13]*_t87;
  const double _t218 = _t187*_t30 + _t191 + _t217;
  const double _t219 = _t218*_t27;
  const double _t220 = _hc3[51]*_t55;
  const double _t221 = _hc3[47]*_t30 - _t220;
  const double _t222 = _t221*_t32;
  const double _t223 = _hc3[16]*_t95;
  const double _t224 = _hc1[19]*_t87 + _t198*_t30 + _t205 - _t222*lb + _t223*lb;
  const double _t225 = _t173 - 0.4e1 / 0.9e1*_t2*_t3*_t41*_t85 + _t224*_t55;
  const double _t226 = -_t178*_t85 + _t181;
  const double _t228 = _hc3[16]*_t116;
  const double _t229 = _hc3[12]*_t87;
  const double _t230 = _t213*_t30 - _t221*_t55 + _t228 + _t229;
  const double _t231 = _t230*_t32;
  const double _t234 = _hc3[1]*_t233;
  const double _t235 = -_hc1[4]*_t227 - _t216*_t30 + _t231*lb + _t234*lb - 0.2e1*_t79*_t87 - 0.80e2 / 0.9e1*_t92*_t94*lb;
  const double _t236 = 0.5e1*_t31*_t92;
  const double _t238 = _hc3[1]*_t237;
  const double _t239 = _t101*_t45;
  const double _t240 = _t100*_t151;
  const double _t241 = -0.1e1 / 0.6e1*_t240 - _t69;
  const double _t242 = _t1*((0.2e1 / 0.3e1)*_t239 - _t241*_t55 + _t40) - _t104;
  const double _t243 = -0.1e1 / 0.3e1*_t240 - 0.16e2 / 0.3e1*_t68;
  const double _t244 = _t1*((0.4e1 / 0.3e1)*_t239 - _t243*_t55 + (0.176e3 / 0.9e1)*_t39) - 0.2e1 / 0.3e1*_t102 - 0.32e2 / 0.3e1*_t17;
  const double _t246 = _hc3[17]*_t12;
  const double _t247 = -_t245*_t246;
  const double _t248 = _t12*_t61;
  const double _t249 = _t12*_t129;
  const double _t250 = _t118*_t12;
  const double _t251 = _hc3[38]*_t12*_t25 - _t250 - _t54;
  const double _t252 = _t25*_t251;
  const double _t253 = _t12*_t130;
  const double _t254 = _t12*_t131;
  const double _t255 = _hc3[48]*_t12*_t25 - _t254 - _t67;
  const double _t256 = _t252 + _t253 - _t255*_t55 - _t63 + _t66;
  const double _t257 = _hc3[16]*_t14;
  const double _t258 = _t245*_t257;
  const double _t259 = -_t258;
  const double _t260 = _t14*_t228;
  const double _t261 = _t14*_t212;
  const double _t262 = _hc3[37]*_t108 - _t261;
  const double _t263 = _t25*_t262;
  const double _t265 = _hc3[12]*_t264;
  const double _t266 = _t14*_t220;
  const double _t267 = _hc3[47]*_t108 - _t266;
  const double _t268 = _t263 + _t265 - _t267*_t55;
  const double _t269 = _t12*_t186 - _t250;
  const double _t270 = _t25*_t269;
  const double _t271 = _t12*_t189 - _t254;
  const double _t272 = _t249 - _t271*_t55;
  const double _t273 = _hc3[37]*_t14*_t30 - _t261 - _t78;
  const double _t274 = _t25*_t273;
  const double _t275 = _hc3[12]*_t14;
  const double _t276 = _hc3[47]*_t14*_t30 - _t266 - _t84;
  const double _t277 = _t260 - _t276*_t55;
  const double _t278 = _t269*_t30;
  const double _t279 = _t12*_t217;
  const double _t280 = _t278 + _t279;
  const double _t281 = _t273*_t30;
  const double _t282 = _t14*_t229;
  const double _t283 = _t281 + _t282 - _t93 + _t96;
  const double d3F_dna3 = _t1*(_hc1[4]*_t114 + _t128*_t25 - _t136 - _t140 - _t141 - _t155 - _t173 + 0.2e1*_t52*_t57 + (0.80e2 / 0.9e1)*_t62*_t64*la) - _t175*la + _t177*la - _t178*_t71 + _t181 + 0.3e1*_t53 + 0.3e1*_t58;
  const double d3F_dna2_dnb = _t1*(_t116*_t71 + _t116*_t85 - _t162 - _t166 - _t169 - _t172 + _t183 + _t184*la + _t185 - _t193*la + _t201 - _t206*_t55 + _t51*_t57) + _t181 - _t207*_t76 + _t211 + _t72;
  const double d3F_dna_dnb2 = _t1*(-_hc1[4]*_t113 - _hc1[4]*_t50 + _t216*_t25 - _t219*la - _t225 + 0.4e1*_t49*_t7*_t79) + _t211 + _t226 + _t97;
  const double d3F_dnb3 = _t1*(-_t225 - _t235) + _t226 - _t236*lb + _t238*lb + 0.3e1*_t88 + 0.3e1*_t89;
  const double d3F_dna2_dgaa = _t242;
  const double d3F_dna2_dgab = _t244;
  const double d3F_dna2_dgbb = _t242;
  const double d3F_dna_dnb_dgaa = _t242;
  const double d3F_dna_dnb_dgab = _t244;
  const double d3F_dna_dnb_dgbb = _t242;
  const double d3F_dnb2_dgaa = _t242;
  const double d3F_dnb2_dgab = _t244;
  const double d3F_dnb2_dgbb = _t242;
  const double d3F_dna2_dla = _t1*(_t249 + _t256) + _t247 + 0.2e1*_t248 - _t74;
  const double d3F_dna2_dlb = _t1*(_t260 + _t268) + 0.2e1*_t109 + _t259;
  const double d3F_dna_dnb_dla = _t1*(_t12*_t188 + _t270 + _t272 - _t83) + _t110 + _t247 + _t248 - _t28;
  const double d3F_dna_dnb_dlb = _t1*(_t274 + _t275*_t51 + _t277) + _t109 + _t14*_t91 + _t259 - _t33;
  const double d3F_dnb2_dla = _t1*(_t272 + _t280) + 0.2e1*_t110 + _t247;
  const double d3F_dnb2_dlb = 0.2e1*_hc3[12]*_t14*_t30 + _t1*(_t277 + _t283) - _t258 - _t98;
  const double d3F_dna_dgaa2 = 0;
  const double d3F_dna_dgaa_dgab = 0;
  const double d3F_dna_dgaa_dgbb = 0;
  const double d3F_dna_dgab2 = 0;
  const double d3F_dna_dgab_dgbb = 0;
  const double d3F_dna_dgbb2 = 0;
  const double d3F_dnb_dgaa2 = 0;
  const double d3F_dnb_dgaa_dgab = 0;
  const double d3F_dnb_dgaa_dgbb = 0;
  const double d3F_dnb_dgab2 = 0;
  const double d3F_dnb_dgab_dgbb = 0;
  const double d3F_dnb_dgbb2 = 0;
  const double d3F_dna_dgaa_dla = 0;
  const double d3F_dna_dgaa_dlb = 0;
  const double d3F_dna_dgab_dla = 0;
  const double d3F_dna_dgab_dlb = 0;
  const double d3F_dna_dgbb_dla = 0;
  const double d3F_dna_dgbb_dlb = 0;
  const double d3F_dnb_dgaa_dla = 0;
  const double d3F_dnb_dgaa_dlb = 0;
  const double d3F_dnb_dgab_dla = 0;
  const double d3F_dnb_dgab_dlb = 0;
  const double d3F_dnb_dgbb_dla = 0;
  const double d3F_dnb_dgbb_dlb = 0;
  const double d3F_dna_dla2 = 0;
  const double d3F_dna_dla_dlb = 0;
  const double d3F_dna_dlb2 = 0;
  const double d3F_dnb_dla2 = 0;
  const double d3F_dnb_dla_dlb = 0;
  const double d3F_dnb_dlb2 = 0;
  const double d3F_dgaa3 = 0;
  const double d3F_dgaa2_dgab = 0;
  const double d3F_dgaa2_dgbb = 0;
  const double d3F_dgaa_dgab2 = 0;
  const double d3F_dgaa_dgab_dgbb = 0;
  const double d3F_dgaa_dgbb2 = 0;
  const double d3F_dgab3 = 0;
  const double d3F_dgab2_dgbb = 0;
  const double d3F_dgab_dgbb2 = 0;
  const double d3F_dgbb3 = 0;
  const double d3F_dgaa2_dla = 0;
  const double d3F_dgaa2_dlb = 0;
  const double d3F_dgaa_dgab_dla = 0;
  const double d3F_dgaa_dgab_dlb = 0;
  const double d3F_dgaa_dgbb_dla = 0;
  const double d3F_dgaa_dgbb_dlb = 0;
  const double d3F_dgab2_dla = 0;
  const double d3F_dgab2_dlb = 0;
  const double d3F_dgab_dgbb_dla = 0;
  const double d3F_dgab_dgbb_dlb = 0;
  const double d3F_dgbb2_dla = 0;
  const double d3F_dgbb2_dlb = 0;
  const double d3F_dgaa_dla2 = 0;
  const double d3F_dgaa_dla_dlb = 0;
  const double d3F_dgaa_dlb2 = 0;
  const double d3F_dgab_dla2 = 0;
  const double d3F_dgab_dla_dlb = 0;
  const double d3F_dgab_dlb2 = 0;
  const double d3F_dgbb_dla2 = 0;
  const double d3F_dgbb_dla_dlb = 0;
  const double d3F_dgbb_dlb2 = 0;
  const double d3F_dla3 = 0;
  const double d3F_dla2_dlb = 0;
  const double d3F_dla_dlb2 = 0;
  const double d3F_dlb3 = 0;
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
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 1] += d3F_dna2_dlb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 2] += d3F_dna_dnb_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 3] += d3F_dna_dnb_dlb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 4] += d3F_dnb2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += d3F_dnb2_dlb;
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
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 1] += d3F_dna_dgaa_dlb;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 2] += d3F_dna_dgab_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 3] += d3F_dna_dgab_dlb;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 4] += d3F_dna_dgbb_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 5] += d3F_dna_dgbb_dlb;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 6] += d3F_dnb_dgaa_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 7] += d3F_dnb_dgaa_dlb;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 8] += d3F_dnb_dgab_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 9] += d3F_dnb_dgab_dlb;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 10] += d3F_dnb_dgbb_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 11] += d3F_dnb_dgbb_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 1] += d3F_dna_dla_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 2] += d3F_dna_dlb2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 3] += d3F_dnb_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 4] += d3F_dnb_dla_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += d3F_dnb_dlb2;
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
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 1] += d3F_dgaa2_dlb;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 2] += d3F_dgaa_dgab_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 3] += d3F_dgaa_dgab_dlb;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 4] += d3F_dgaa_dgbb_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 5] += d3F_dgaa_dgbb_dlb;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 6] += d3F_dgab2_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 7] += d3F_dgab2_dlb;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 8] += d3F_dgab_dgbb_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 9] += d3F_dgab_dgbb_dlb;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 10] += d3F_dgbb2_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 11] += d3F_dgbb2_dlb;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 1] += d3F_dgaa_dla_dlb;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 2] += d3F_dgaa_dlb2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 3] += d3F_dgab_dla2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 4] += d3F_dgab_dla_dlb;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 5] += d3F_dgab_dlb2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 6] += d3F_dgbb_dla2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 7] += d3F_dgbb_dla_dlb;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 8] += d3F_dgbb_dlb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 1] += d3F_dla2_dlb;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 2] += d3F_dla_dlb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 3] += d3F_dlb3;
#endif
#if _KMAX >= 4
  const double _t284 = 0.24e2*_t100;
  const double _t285 = 0.24e2*_t45*_t7;
  const double _t286 = _t138*la;
  const double _t287 = _t168*_t4;
  const double _t290 = (0.80e2 / 0.9e1)*_t64;
  const double _t291 = _t290*la;
  const double _t292 = (0.4e1 / 0.9e1)*_t4*_t41;
  const double _t293 = 0.2e1*_t52;
  const double _t302 = _t27*la;
  const double _t303 = _t65*la;
  const double _t312 = _t137*la;
  const double _t325 = _t11*_t145;
  const double _t327 = _t11*_t38;
  const double _t338 = (0.2e1 / 0.3e1)*_t20;
  const double _t345 = _t111*_t7;
  const double _t347 = 0.12e2*_t100;
  const double _t354 = _t32*lb;
  const double _t373 = _t95*lb;
  const double _t379 = _t208*_t7;
  const double _t392 = _t233*lb;
  const double _t393 = (0.80e2 / 0.9e1)*_t94;
  const double _t394 = 0.2e1*_t87;
  const double _t399 = 0.18e2*_t112;
  const double _t407 = _t232*lb;
  const double _t414 = (0.16e2 / 0.3e1)*_t16;
  const double _t416 = _t180*_t4;
  const double _t441 = _t14*_t51;
  const double _t288 = _hc1[19]*_t287;
  const double _t289 = -_t288;
  const double _t294 = _hc3[48]*_t116;
  const double _t295 = _hc3[38]*_t52;
  const double _t296 = _hc3[118]*_t55;
  const double _t297 = -_t296;
  const double _t298 = _hc3[108]*_t25 + _t297;
  const double _t299 = _hc3[108]*_t55;
  const double _t300 = _hc3[88]*_t25 - _t299;
  const double _t301 = _t25*_t300 + _t294 + _t295 - _t298*_t55;
  const double _t304 = _hc1[54]*_t116;
  const double _t305 = _hc1[124]*_t55;
  const double _t306 = _hc1[120]*_t25 - _hc3[118]*_t302 - _t305;
  const double _t307 = _hc1[120]*_t55;
  const double _t308 = _hc1[110]*_t25 - _hc3[108]*_t302 - _t307;
  const double _t309 = _hc1[50]*_t52 + _hc3[48]*_t303 + _t25*_t308 - _t298*_t302 + _t304 - _t306*_t55;
  const double _t310 = _hc1[50]*_t116;
  const double _t311 = _hc1[110]*_t55;
  const double _t313 = _hc3[17]*_t287;
  const double _t314 = -_t313;
  const double _t315 = _hc3[13]*_t114;
  const double _t316 = _hc3[52]*_t116;
  const double _t317 = _hc3[48]*_t52;
  const double _t318 = _hc3[122]*_t55;
  const double _t319 = -_t318;
  const double _t320 = _hc3[118]*_t25 + _t319;
  const double _t321 = _t25*_t298 + _t316 + _t317 - _t320*_t55;
  const double _t322 = _t134*la;
  const double _t323 = _t4*_t71;
  const double _t324 = _t167*_t323;
  const double _t326 = _hc0[125]*_t55 + _hc2[123]*_t325;
  const double _t328 = _hc2[123]*_t4;
  const double _t329 = _hc0[55]*_t116 + (0.88e2 / 0.9e1)*_hc2[53]*_t327 + _t11*_t328*_t46;
  const double _t330 = _hc2[123]*_t156*_t157*_t159 + _hc2[53]*_t116;
  const double _t331 = _t325*_t330;
  const double _t332 = (0.1232e4 / 0.27e2)*_t163*_t43;
  const double _t333 = _hc0[20]*_t287;
  const double _t334 = _t11*_t151*_t171;
  const double _t335 = _t331 + _t332 + _t333 + _t334;
  const double _t336 = _t154*_t4;
  const double _t337 = (0.20944e5 / 0.81e2)*_hc2[3]*_t11/xc_powr(_t1, 20, 3) + (0.88e2 / 0.3e1)*_t160*_t327 - _t325*(-_t101*_t168 - 0.2e1 / 0.27e2*_t158*_t16 - _t330*_t55) + (0.616e3 / 0.27e2)*_t44/xc_powi(_t1, 7) + (0.140e3 / 0.81e2)*_t19/xc_powr(_t1, 13, 3);
  const double _t339 = (0.32e2 / 0.3e1)*_t11*_t16*_t160;
  const double _t340 = (0.4928e4 / 0.27e2)*_t11*_t164;
  const double _t341 = (0.56e2 / 0.27e2)*_t167*_t19;
  const double _t342 = (0.352e3 / 0.27e2)*_t170*_t44;
  const double _t343 = _t339 + _t340 + _t341 + _t342;
  const double _t344 = _t290*_t62;
  const double _t346 = _t192*la;
  const double _t348 = _hc3[88]*_t30 - _t299;
  const double _t349 = _hc3[38]*_t51;
  const double _t350 = _hc3[108]*_t30;
  const double _t351 = _t297 + _t350;
  const double _t352 = _t294 - _t351*_t55;
  const double _t353 = _t25*_t348 + _t349 + _t352;
  const double _t355 = _hc1[110]*_t30 - _hc3[107]*_t354 - _t307;
  const double _t356 = _hc1[120]*_t30 - _hc3[117]*_t354 - _t305;
  const double _t357 = _t304 - _t356*_t55;
  const double _t358 = _hc1[50]*_t51 + _t25*_t355 - _t302*_t351 + _t357;
  const double _t359 = _hc1[90]*_t30 - _hc3[87]*_t354 - _t311;
  const double _t360 = _t310 - _t355*_t55;
  const double _t361 = _hc3[13]*_t182;
  const double _t362 = _hc3[48]*_t51;
  const double _t363 = _hc3[118]*_t30;
  const double _t364 = _t319 + _t363;
  const double _t365 = _t316 - _t364*_t55;
  const double _t366 = _t25*_t351 + _t362 + _t365;
  const double _t367 = _t329 - _t55*(_hc1[124]*_t30 - _hc3[121]*_t354 - _t326);
  const double _t368 = _t206*_t292;
  const double _t369 = _hc3[38]*_t87;
  const double _t370 = _t30*_t348 + _t352 + _t369;
  const double _t371 = _hc3[117]*_t55;
  const double _t372 = _hc3[107]*_t30 - _t371;
  const double _t374 = _hc1[50]*_t87 + _hc3[47]*_t373 + _t30*_t355 - _t354*_t372 + _t357;
  const double _t375 = _t374*_t55;
  const double _t376 = _hc3[107]*_t55;
  const double _t377 = _hc3[87]*_t30 - _t376;
  const double _t378 = _hc1[40]*_t87 + _hc3[37]*_t373 + _t30*_t359 - _t354*_t377 + _t360;
  const double _t380 = _hc3[13]*_t50;
  const double _t381 = _hc3[13]*_t113;
  const double _t382 = _hc3[48]*_t87;
  const double _t383 = _t30*_t351 + _t365 + _t382;
  const double _t384 = _t383*_t55;
  const double _t385 = _t167*_t207;
  const double _t386 = _hc3[121]*_t55;
  const double _t387 = _hc3[117]*_t30 - _t386;
  const double _t388 = -0.4e1 / 0.9e1*_t2*_t204*_t3*_t41 + _t335 + _t55*(_hc1[54]*_t87 + _hc3[51]*_t373 + _t30*_t356 - _t354*_t387 + _t367);
  const double _t389 = _hc1[4]*_t285 + _t337;
  const double _t390 = _hc1[4]*_t347;
  const double _t391 = _t218*la;
  const double _t395 = _hc3[47]*_t116;
  const double _t396 = _hc3[37]*_t87;
  const double _t397 = _t30*_t377 - _t372*_t55 + _t395 + _t396;
  const double _t398 = _hc1[15]*_t227 - _hc3[12]*_t392 + _t195*_t394 + _t198*_t292 + _t213*_t393*lb + _t289 + _t30*_t378 - _t354*_t397 - _t375;
  const double _t400 = _hc3[13]*_t227;
  const double _t401 = _hc3[51]*_t116;
  const double _t402 = _hc3[47]*_t87;
  const double _t403 = _t30*_t372 - _t387*_t55 + _t401 + _t402;
  const double _t404 = _t224*_t4;
  const double _t405 = _t180*_t404 - 0.14e2 / 0.9e1*_t385 - _t55*(_hc1[19]*_t227 - _hc3[16]*_t392 + 0.2e1*_t198*_t87 + (0.80e2 / 0.9e1)*_t221*_t94*lb + _t30*_t374 - _t354*_t403 - _t388);
  const double _t406 = -0.16e2 / 0.9e1*_t2*_t3*_t41*_t85 + _t338*_t404 + _t343;
  const double _t408 = _hc3[16]*_t287;
  const double _t409 = _hc3[12]*_t227;
  const double _t410 = _t230*lb;
  const double _t411 = _t101*_t170;
  const double _t412 = _t100*_t328;
  const double _t413 = _t1*(-_t161 - _t165 + (0.4e1 / 0.9e1)*_t2*_t241*_t3*_t41 - 0.34e2 / 0.9e1*_t411 - _t55*(_t150 + (0.2e1 / 0.3e1)*_t152 - _t55*(-_t146 - 0.1e1 / 0.6e1*_t412))) - _t178*_t241 + _t179 + 0.2e1*_t239;
  const double _t415 = _t1*(-_t160*_t414 - 0.2464e4 / 0.27e2*_t164 + (0.4e1 / 0.9e1)*_t2*_t243*_t3*_t41 - 0.68e2 / 0.9e1*_t411 - _t55*((0.176e3 / 0.9e1)*_t149 + (0.4e1 / 0.3e1)*_t152 - _t55*(-_hc2[53]*_t414 - 0.1e1 / 0.3e1*_t412))) - _t178*_t243 + 0.4e1*_t239 + (0.176e3 / 0.3e1)*_t39;
  const double _t417 = _t246*_t416;
  const double _t418 = _t12*_t313;
  const double _t419 = -_t418;
  const double _t420 = _t12*_t316;
  const double _t421 = _t12*_t318;
  const double _t422 = _t12*_t296;
  const double _t423 = _hc3[108]*_t12*_t25 - _t122 - _t422;
  const double _t424 = _t12*_t294;
  const double _t425 = _t12*_t299;
  const double _t426 = _t257*_t416;
  const double _t427 = _t14*_t408;
  const double _t428 = -_t427;
  const double _t429 = _t14*_t401;
  const double _t430 = _t14*_t386;
  const double _t431 = _t14*_t371;
  const double _t432 = _hc3[107]*_t108 - _t431;
  const double _t433 = _t14*_t395;
  const double _t434 = _t14*_t376;
  const double _t435 = _t12*_t350 - _t422;
  const double _t436 = _t420 - _t55*(_t12*_t363 - _t421);
  const double _t437 = _hc3[88]*_t12*_t30 - _t425;
  const double _t438 = _t424 - _t435*_t55;
  const double _t439 = _hc3[13]*_t12*_t379 - _t210 + 0.2e1*_t270;
  const double _t440 = _hc3[107]*_t14*_t30 - _t197 - _t431;
  const double _t442 = _t429 - _t55*(_hc3[117]*_t14*_t30 - _t203 - _t430);
  const double _t443 = _hc3[87]*_t14*_t30 - _t194 - _t434;
  const double _t444 = _t433 - _t440*_t55;
  const double _t445 = 0.2e1*_t274 + _t275*_t379;
  const double _t446 = _t55*(_t12*_t382 + _t30*_t435 + _t436);
  const double _t447 = _t12*_t369 + _t30*_t437 + _t438;
  const double _t448 = -_t178*_t271 + _t417;
  const double _t449 = _t55*(_t14*_t402 - _t222 + _t223 + _t30*_t440 + _t442);
  const double _t450 = _t14*_t396 - _t214 + _t215 + _t30*_t443 + _t444;
  const double _t451 = -_t178*_t276 + _t426;
  const double d4F_dna4 = 0.4e1*_hc1[4]*_t114 - 0.1760e4 / 0.27e2*_hc3[2]*_t312 + _t1*(_hc1[4]*(-_t284 + _t285) + (0.6160e4 / 0.81e2)*_hc3[2]*la/xc_powr(na, 17, 3) + 0.3e1*_t114*_t57 + 0.3e1*_t128*_t52 + _t176*_t322 + _t180*_t336 + _t25*(_hc1[15]*_t114 - _hc3[13]*_t286 + _t120*_t291 + _t124*_t292 + _t127*_t293 + _t25*(_hc1[40]*_t52 + _hc3[38]*_t303 + _t25*(_hc1[90]*_t25 - _hc3[88]*_t302 - _t311) - _t300*_t302 - _t308*_t55 + _t310) + _t289 - _t301*_t302 - _t309*_t55) - _t302*(_t120*_t293 + _t133*_t292 + _t25*_t301 + _t314 + _t315 - _t321*_t55) - 0.440e3 / 0.9e1*_t312*_t62 - 0.14e2 / 0.9e1*_t324 + _t337 - _t55*(_hc1[19]*_t114 - _hc3[17]*_t286 + 0.2e1*_t124*_t52 + (0.80e2 / 0.9e1)*_t133*_t64*la + (0.4e1 / 0.9e1)*_t148*_t2*_t3*_t41 + _t25*_t309 - _t302*_t321 - _t335 - _t55*(_hc1[54]*_t52 + _hc3[52]*_t303 + _t25*_t306 - _t302*_t320 + _t329 - _t55*(_hc1[124]*_t25 - _hc3[122]*_t302 - _t326)))) + 0.4e1*_t128*_t25 + (0.16e2 / 0.9e1)*_t2*_t3*_t41*_t71 - 0.20e2 / 0.3e1*_t26*_t322 - _t336*_t338 - _t343 + 0.8e1*_t52*_t57 + (0.320e3 / 0.9e1)*_t62*_t64*la;
  const double d4F_dna3_dnb = _hc1[4]*_t114 + _t1*(_hc1[4]*(_t285 - _t347) + _t114*_t79 + _t116*_t154 + _t128*_t51 - _t168*_t207 + 0.2e1*_t182*_t57 + _t192*_t291 + _t200*_t293 + _t25*(_hc1[15]*_t182 + _t116*_t124 + _t116*_t198 + _t127*_t51 + _t187*_t303 + _t195*_t52 + _t25*(_hc1[40]*_t51 + _t25*_t359 - _t302*_t348 + _t360) + _t289 - _t302*_t353 - _t358*_t55) - _t286*_t82 - _t302*(_t116*_t133 + _t116*_t190 + _t120*_t51 + _t187*_t52 + _t25*_t353 + _t314 + _t361 - _t366*_t55) - 0.28e2 / 0.27e2*_t324 + _t337 + _t368 - _t55*(_hc1[19]*_t182 + _t116*_t148 + _t116*_t204 + _t124*_t51 + _t190*_t303 + _t198*_t52 + _t25*_t358 - _t302*_t366 - _t331 - _t332 - _t333 - _t334 - _t55*(_hc1[54]*_t51 + _t25*_t356 - _t302*_t364 + _t367))) + _t128*_t25 - _t136 - _t140 - _t155 - _t174*_t346 + _t176*_t82*la - _t178*_t206 + _t180*_t207 + 0.3e1*_t183 + 0.3e1*_t185 + 0.3e1*_t201 + _t293*_t57 + (0.10e2 / 0.9e1)*_t323*_t41 - _t339 - _t340 - _t341 - _t342 + _t344*la + _t345*_t57;
  const double d4F_dna2_dnb2 = 0.2e1*_hc1[4]*_t182 + _t1*(-_t113*_t57 + _t116*_t224 - _t168*_t323 + 0.2e1*_t182*_t79 + _t200*_t379 + _t216*_t52 + _t218*_t303 + _t25*(-_hc1[15]*_t113 - _hc1[15]*_t50 + 0.4e1*_t195*_t49*_t7 + (0.4e1 / 0.9e1)*_t198*_t2*_t3*_t41 + _t25*_t378 - _t288 - _t302*_t370 - _t375) - _t302*(0.4e1*_t187*_t49*_t7 + (0.4e1 / 0.9e1)*_t190*_t2*_t3*_t41 + _t25*_t370 - _t313 - _t380 - _t381 - _t384) + _t368 - 0.28e2 / 0.27e2*_t385 + _t389 - _t50*_t57 - _t55*(-_hc1[19]*_t113 - _hc1[19]*_t50 + 0.4e1*_t198*_t49*_t7 + _t25*_t374 - _t302*_t383 - _t388)) - _t141 + (0.4e1 / 0.3e1)*_t2*_t3*_t41*_t85 + 0.2e1*_t200*_t25 - _t206*_t245 - _t209 + 0.2e1*_t216*_t25 - _t224*_t245 - _t343 - _t346*_t73 - _t390*_t7 - _t391*_t73 + 0.4e1*_t49*_t57*_t7 + 0.8e1*_t49*_t7*_t79 + 0.2e1*_t52*_t79 + (0.80e2 / 0.9e1)*_t64*_t82*la;
  const double d4F_dna_dnb3 = -_hc1[4]*_t111 - _hc1[4]*_t399 + _t1*(-_t111*_t79 + _t216*_t345 + _t25*_t398 - _t302*(_t187*_t394 + _t190*_t292 + _t30*_t370 + _t314 - _t384 + _t400) + _t389 + _t390 - _t399*_t79 + _t405) - _t174*_t391 + 0.3e1*_t216*_t25 - _t235 - _t406 + 0.12e2*_t49*_t7*_t79;
  const double d4F_dnb4 = 0.4e1*_hc1[4]*_t227 - 0.1760e4 / 0.27e2*_hc3[1]*_t407 + _t1*(_hc1[4]*(_t284 + _t285) + (0.6160e4 / 0.81e2)*_hc3[1]*lb/xc_powr(nb, 17, 3) + 0.3e1*_t216*_t87 + 0.3e1*_t227*_t79 + _t237*_t410 + _t30*_t398 + _t337 - _t354*(_t213*_t394 + _t221*_t292 + _t30*_t397 - _t403*_t55 - _t408 + _t409) + _t405 - 0.440e3 / 0.9e1*_t407*_t92) + 0.4e1*_t216*_t30 - 0.20e2 / 0.3e1*_t31*_t410 - _t406 + 0.8e1*_t79*_t87 + (0.320e3 / 0.9e1)*_t92*_t94*lb;
  const double d4F_dna3_dgaa = _t413;
  const double d4F_dna3_dgab = _t415;
  const double d4F_dna3_dgbb = _t413;
  const double d4F_dna2_dnb_dgaa = _t413;
  const double d4F_dna2_dnb_dgab = _t415;
  const double d4F_dna2_dnb_dgbb = _t413;
  const double d4F_dna_dnb2_dgaa = _t413;
  const double d4F_dna_dnb2_dgab = _t415;
  const double d4F_dna_dnb2_dgbb = _t413;
  const double d4F_dnb3_dgaa = _t413;
  const double d4F_dnb3_dgab = _t415;
  const double d4F_dnb3_dgbb = _t413;
  const double d4F_dna3_dla = _t1*(_t12*_t315 - _t135 - _t139 + _t25*(_t115 + _t12*_t295 - _t121 + _t25*(_hc3[88]*_t12*_t25 - _t125 - _t425) - _t423*_t55 + _t424) + _t251*_t293 + _t255*_t292 + _t344 + _t419 - _t55*(_t12*_t317 - _t142 + _t143 + _t25*_t423 + _t420 - _t55*(_hc3[118]*_t12*_t25 - _t144 - _t421))) - _t175 + _t177 - _t178*_t255 + 0.3e1*_t252 + 0.3e1*_t253 + _t417;
  const double d4F_dna3_dlb = _t1*(_t114*_t275 + _t25*(_hc3[37]*_t264 + _t25*(_hc3[87]*_t14*_t25 - _t434) - _t432*_t55 + _t433) + _t262*_t293 + _t267*_t292 + _t428 - _t55*(_hc3[47]*_t264 + _t25*_t432 + _t429 - _t55*(_hc3[117]*_t108 - _t430))) - _t178*_t267 + 0.3e1*_t263 + 0.3e1*_t265 + _t426;
  const double d4F_dna2_dnb_dla = _t1*(_t116*_t255 + _t116*_t271 + _t12*_t361 + _t184 - _t193 + _t25*(_t12*_t349 - _t196 + _t25*_t437 + _t438) + _t251*_t51 + _t269*_t52 + _t419 - _t55*(_t12*_t362 - _t202 + _t25*_t435 + _t436)) - _t245*_t271 + _t256 + _t417 + _t439;
  const double d4F_dna2_dnb_dlb = _t1*(_t116*_t267 + _t116*_t276 + _t182*_t275 + _t25*(_hc3[37]*_t441 + _t25*_t443 + _t444) + _t262*_t51 + _t273*_t52 + _t428 - _t55*(_hc3[47]*_t441 + _t25*_t440 + _t442)) - _t245*_t276 + _t268 + _t426 + _t445;
  const double d4F_dna_dnb2_dla = _t1*(-_t12*_t380 - _t12*_t381 + (0.4e1 / 0.9e1)*_t2*_t271*_t3*_t41 - _t219 + _t25*_t447 + 0.4e1*_t269*_t49*_t7 - _t418 - _t446) + _t280 + _t439 + _t448;
  const double d4F_dna_dnb2_dlb = _t1*(-_t113*_t275 + (0.4e1 / 0.9e1)*_t2*_t276*_t3*_t41 + _t25*_t450 + 0.4e1*_t273*_t49*_t7 - _t275*_t50 - _t427 - _t449) + _t283 + _t445 + _t451;
  const double d4F_dnb3_dla = _t1*(_t12*_t400 + _t269*_t394 + _t271*_t292 + _t30*_t447 + _t419 - _t446) + 0.3e1*_t278 + 0.3e1*_t279 + _t448;
  const double d4F_dnb3_dlb = _t1*(_t14*_t409 - _t231 - _t234 + _t273*_t394 + _t276*_t292 + _t30*_t450 + _t393*_t92 + _t428 - _t449) - _t236 + _t238 + 0.3e1*_t281 + 0.3e1*_t282 + _t451;
  const double d4F_dna2_dgaa2 = 0;
  const double d4F_dna2_dgaa_dgab = 0;
  const double d4F_dna2_dgaa_dgbb = 0;
  const double d4F_dna2_dgab2 = 0;
  const double d4F_dna2_dgab_dgbb = 0;
  const double d4F_dna2_dgbb2 = 0;
  const double d4F_dna_dnb_dgaa2 = 0;
  const double d4F_dna_dnb_dgaa_dgab = 0;
  const double d4F_dna_dnb_dgaa_dgbb = 0;
  const double d4F_dna_dnb_dgab2 = 0;
  const double d4F_dna_dnb_dgab_dgbb = 0;
  const double d4F_dna_dnb_dgbb2 = 0;
  const double d4F_dnb2_dgaa2 = 0;
  const double d4F_dnb2_dgaa_dgab = 0;
  const double d4F_dnb2_dgaa_dgbb = 0;
  const double d4F_dnb2_dgab2 = 0;
  const double d4F_dnb2_dgab_dgbb = 0;
  const double d4F_dnb2_dgbb2 = 0;
  const double d4F_dna2_dgaa_dla = 0;
  const double d4F_dna2_dgaa_dlb = 0;
  const double d4F_dna2_dgab_dla = 0;
  const double d4F_dna2_dgab_dlb = 0;
  const double d4F_dna2_dgbb_dla = 0;
  const double d4F_dna2_dgbb_dlb = 0;
  const double d4F_dna_dnb_dgaa_dla = 0;
  const double d4F_dna_dnb_dgaa_dlb = 0;
  const double d4F_dna_dnb_dgab_dla = 0;
  const double d4F_dna_dnb_dgab_dlb = 0;
  const double d4F_dna_dnb_dgbb_dla = 0;
  const double d4F_dna_dnb_dgbb_dlb = 0;
  const double d4F_dnb2_dgaa_dla = 0;
  const double d4F_dnb2_dgaa_dlb = 0;
  const double d4F_dnb2_dgab_dla = 0;
  const double d4F_dnb2_dgab_dlb = 0;
  const double d4F_dnb2_dgbb_dla = 0;
  const double d4F_dnb2_dgbb_dlb = 0;
  const double d4F_dna2_dla2 = 0;
  const double d4F_dna2_dla_dlb = 0;
  const double d4F_dna2_dlb2 = 0;
  const double d4F_dna_dnb_dla2 = 0;
  const double d4F_dna_dnb_dla_dlb = 0;
  const double d4F_dna_dnb_dlb2 = 0;
  const double d4F_dnb2_dla2 = 0;
  const double d4F_dnb2_dla_dlb = 0;
  const double d4F_dnb2_dlb2 = 0;
  const double d4F_dna_dgaa3 = 0;
  const double d4F_dna_dgaa2_dgab = 0;
  const double d4F_dna_dgaa2_dgbb = 0;
  const double d4F_dna_dgaa_dgab2 = 0;
  const double d4F_dna_dgaa_dgab_dgbb = 0;
  const double d4F_dna_dgaa_dgbb2 = 0;
  const double d4F_dna_dgab3 = 0;
  const double d4F_dna_dgab2_dgbb = 0;
  const double d4F_dna_dgab_dgbb2 = 0;
  const double d4F_dna_dgbb3 = 0;
  const double d4F_dnb_dgaa3 = 0;
  const double d4F_dnb_dgaa2_dgab = 0;
  const double d4F_dnb_dgaa2_dgbb = 0;
  const double d4F_dnb_dgaa_dgab2 = 0;
  const double d4F_dnb_dgaa_dgab_dgbb = 0;
  const double d4F_dnb_dgaa_dgbb2 = 0;
  const double d4F_dnb_dgab3 = 0;
  const double d4F_dnb_dgab2_dgbb = 0;
  const double d4F_dnb_dgab_dgbb2 = 0;
  const double d4F_dnb_dgbb3 = 0;
  const double d4F_dna_dgaa2_dla = 0;
  const double d4F_dna_dgaa2_dlb = 0;
  const double d4F_dna_dgaa_dgab_dla = 0;
  const double d4F_dna_dgaa_dgab_dlb = 0;
  const double d4F_dna_dgaa_dgbb_dla = 0;
  const double d4F_dna_dgaa_dgbb_dlb = 0;
  const double d4F_dna_dgab2_dla = 0;
  const double d4F_dna_dgab2_dlb = 0;
  const double d4F_dna_dgab_dgbb_dla = 0;
  const double d4F_dna_dgab_dgbb_dlb = 0;
  const double d4F_dna_dgbb2_dla = 0;
  const double d4F_dna_dgbb2_dlb = 0;
  const double d4F_dnb_dgaa2_dla = 0;
  const double d4F_dnb_dgaa2_dlb = 0;
  const double d4F_dnb_dgaa_dgab_dla = 0;
  const double d4F_dnb_dgaa_dgab_dlb = 0;
  const double d4F_dnb_dgaa_dgbb_dla = 0;
  const double d4F_dnb_dgaa_dgbb_dlb = 0;
  const double d4F_dnb_dgab2_dla = 0;
  const double d4F_dnb_dgab2_dlb = 0;
  const double d4F_dnb_dgab_dgbb_dla = 0;
  const double d4F_dnb_dgab_dgbb_dlb = 0;
  const double d4F_dnb_dgbb2_dla = 0;
  const double d4F_dnb_dgbb2_dlb = 0;
  const double d4F_dna_dgaa_dla2 = 0;
  const double d4F_dna_dgaa_dla_dlb = 0;
  const double d4F_dna_dgaa_dlb2 = 0;
  const double d4F_dna_dgab_dla2 = 0;
  const double d4F_dna_dgab_dla_dlb = 0;
  const double d4F_dna_dgab_dlb2 = 0;
  const double d4F_dna_dgbb_dla2 = 0;
  const double d4F_dna_dgbb_dla_dlb = 0;
  const double d4F_dna_dgbb_dlb2 = 0;
  const double d4F_dnb_dgaa_dla2 = 0;
  const double d4F_dnb_dgaa_dla_dlb = 0;
  const double d4F_dnb_dgaa_dlb2 = 0;
  const double d4F_dnb_dgab_dla2 = 0;
  const double d4F_dnb_dgab_dla_dlb = 0;
  const double d4F_dnb_dgab_dlb2 = 0;
  const double d4F_dnb_dgbb_dla2 = 0;
  const double d4F_dnb_dgbb_dla_dlb = 0;
  const double d4F_dnb_dgbb_dlb2 = 0;
  const double d4F_dna_dla3 = 0;
  const double d4F_dna_dla2_dlb = 0;
  const double d4F_dna_dla_dlb2 = 0;
  const double d4F_dna_dlb3 = 0;
  const double d4F_dnb_dla3 = 0;
  const double d4F_dnb_dla2_dlb = 0;
  const double d4F_dnb_dla_dlb2 = 0;
  const double d4F_dnb_dlb3 = 0;
  const double d4F_dgaa4 = 0;
  const double d4F_dgaa3_dgab = 0;
  const double d4F_dgaa3_dgbb = 0;
  const double d4F_dgaa2_dgab2 = 0;
  const double d4F_dgaa2_dgab_dgbb = 0;
  const double d4F_dgaa2_dgbb2 = 0;
  const double d4F_dgaa_dgab3 = 0;
  const double d4F_dgaa_dgab2_dgbb = 0;
  const double d4F_dgaa_dgab_dgbb2 = 0;
  const double d4F_dgaa_dgbb3 = 0;
  const double d4F_dgab4 = 0;
  const double d4F_dgab3_dgbb = 0;
  const double d4F_dgab2_dgbb2 = 0;
  const double d4F_dgab_dgbb3 = 0;
  const double d4F_dgbb4 = 0;
  const double d4F_dgaa3_dla = 0;
  const double d4F_dgaa3_dlb = 0;
  const double d4F_dgaa2_dgab_dla = 0;
  const double d4F_dgaa2_dgab_dlb = 0;
  const double d4F_dgaa2_dgbb_dla = 0;
  const double d4F_dgaa2_dgbb_dlb = 0;
  const double d4F_dgaa_dgab2_dla = 0;
  const double d4F_dgaa_dgab2_dlb = 0;
  const double d4F_dgaa_dgab_dgbb_dla = 0;
  const double d4F_dgaa_dgab_dgbb_dlb = 0;
  const double d4F_dgaa_dgbb2_dla = 0;
  const double d4F_dgaa_dgbb2_dlb = 0;
  const double d4F_dgab3_dla = 0;
  const double d4F_dgab3_dlb = 0;
  const double d4F_dgab2_dgbb_dla = 0;
  const double d4F_dgab2_dgbb_dlb = 0;
  const double d4F_dgab_dgbb2_dla = 0;
  const double d4F_dgab_dgbb2_dlb = 0;
  const double d4F_dgbb3_dla = 0;
  const double d4F_dgbb3_dlb = 0;
  const double d4F_dgaa2_dla2 = 0;
  const double d4F_dgaa2_dla_dlb = 0;
  const double d4F_dgaa2_dlb2 = 0;
  const double d4F_dgaa_dgab_dla2 = 0;
  const double d4F_dgaa_dgab_dla_dlb = 0;
  const double d4F_dgaa_dgab_dlb2 = 0;
  const double d4F_dgaa_dgbb_dla2 = 0;
  const double d4F_dgaa_dgbb_dla_dlb = 0;
  const double d4F_dgaa_dgbb_dlb2 = 0;
  const double d4F_dgab2_dla2 = 0;
  const double d4F_dgab2_dla_dlb = 0;
  const double d4F_dgab2_dlb2 = 0;
  const double d4F_dgab_dgbb_dla2 = 0;
  const double d4F_dgab_dgbb_dla_dlb = 0;
  const double d4F_dgab_dgbb_dlb2 = 0;
  const double d4F_dgbb2_dla2 = 0;
  const double d4F_dgbb2_dla_dlb = 0;
  const double d4F_dgbb2_dlb2 = 0;
  const double d4F_dgaa_dla3 = 0;
  const double d4F_dgaa_dla2_dlb = 0;
  const double d4F_dgaa_dla_dlb2 = 0;
  const double d4F_dgaa_dlb3 = 0;
  const double d4F_dgab_dla3 = 0;
  const double d4F_dgab_dla2_dlb = 0;
  const double d4F_dgab_dla_dlb2 = 0;
  const double d4F_dgab_dlb3 = 0;
  const double d4F_dgbb_dla3 = 0;
  const double d4F_dgbb_dla2_dlb = 0;
  const double d4F_dgbb_dla_dlb2 = 0;
  const double d4F_dgbb_dlb3 = 0;
  const double d4F_dla4 = 0;
  const double d4F_dla3_dlb = 0;
  const double d4F_dla2_dlb2 = 0;
  const double d4F_dla_dlb3 = 0;
  const double d4F_dlb4 = 0;
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
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 1] += d4F_dna3_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 2] += d4F_dna2_dnb_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 3] += d4F_dna2_dnb_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 4] += d4F_dna_dnb2_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 5] += d4F_dna_dnb2_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 6] += d4F_dnb3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += d4F_dnb3_dlb;
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
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 1] += d4F_dna2_dgaa_dlb;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 2] += d4F_dna2_dgab_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 3] += d4F_dna2_dgab_dlb;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 4] += d4F_dna2_dgbb_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 5] += d4F_dna2_dgbb_dlb;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 6] += d4F_dna_dnb_dgaa_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 7] += d4F_dna_dnb_dgaa_dlb;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 8] += d4F_dna_dnb_dgab_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 9] += d4F_dna_dnb_dgab_dlb;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 10] += d4F_dna_dnb_dgbb_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 11] += d4F_dna_dnb_dgbb_dlb;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 12] += d4F_dnb2_dgaa_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 13] += d4F_dnb2_dgaa_dlb;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 14] += d4F_dnb2_dgab_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 15] += d4F_dnb2_dgab_dlb;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 16] += d4F_dnb2_dgbb_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 17] += d4F_dnb2_dgbb_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 1] += d4F_dna2_dla_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 2] += d4F_dna2_dlb2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 3] += d4F_dna_dnb_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 4] += d4F_dna_dnb_dla_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 5] += d4F_dna_dnb_dlb2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 6] += d4F_dnb2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 7] += d4F_dnb2_dla_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += d4F_dnb2_dlb2;
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
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 1] += d4F_dna_dgaa2_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 2] += d4F_dna_dgaa_dgab_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 3] += d4F_dna_dgaa_dgab_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 4] += d4F_dna_dgaa_dgbb_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 5] += d4F_dna_dgaa_dgbb_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 6] += d4F_dna_dgab2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 7] += d4F_dna_dgab2_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 8] += d4F_dna_dgab_dgbb_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 9] += d4F_dna_dgab_dgbb_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 10] += d4F_dna_dgbb2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 11] += d4F_dna_dgbb2_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 12] += d4F_dnb_dgaa2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 13] += d4F_dnb_dgaa2_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 14] += d4F_dnb_dgaa_dgab_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 15] += d4F_dnb_dgaa_dgab_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 16] += d4F_dnb_dgaa_dgbb_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 17] += d4F_dnb_dgaa_dgbb_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 18] += d4F_dnb_dgab2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 19] += d4F_dnb_dgab2_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 20] += d4F_dnb_dgab_dgbb_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 21] += d4F_dnb_dgab_dgbb_dlb;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 22] += d4F_dnb_dgbb2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 23] += d4F_dnb_dgbb2_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 1] += d4F_dna_dgaa_dla_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 2] += d4F_dna_dgaa_dlb2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 3] += d4F_dna_dgab_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 4] += d4F_dna_dgab_dla_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 5] += d4F_dna_dgab_dlb2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 6] += d4F_dna_dgbb_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 7] += d4F_dna_dgbb_dla_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 8] += d4F_dna_dgbb_dlb2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 9] += d4F_dnb_dgaa_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 10] += d4F_dnb_dgaa_dla_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 11] += d4F_dnb_dgaa_dlb2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 12] += d4F_dnb_dgab_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 13] += d4F_dnb_dgab_dla_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 14] += d4F_dnb_dgab_dlb2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 15] += d4F_dnb_dgbb_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 16] += d4F_dnb_dgbb_dla_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 17] += d4F_dnb_dgbb_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 1] += d4F_dna_dla2_dlb;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 2] += d4F_dna_dla_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 3] += d4F_dna_dlb3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 4] += d4F_dnb_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 5] += d4F_dnb_dla2_dlb;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 6] += d4F_dnb_dla_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += d4F_dnb_dlb3;
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
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 1] += d4F_dgaa3_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 2] += d4F_dgaa2_dgab_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 3] += d4F_dgaa2_dgab_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 4] += d4F_dgaa2_dgbb_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 5] += d4F_dgaa2_dgbb_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 6] += d4F_dgaa_dgab2_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 7] += d4F_dgaa_dgab2_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 8] += d4F_dgaa_dgab_dgbb_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 9] += d4F_dgaa_dgab_dgbb_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 10] += d4F_dgaa_dgbb2_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 11] += d4F_dgaa_dgbb2_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 12] += d4F_dgab3_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 13] += d4F_dgab3_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 14] += d4F_dgab2_dgbb_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 15] += d4F_dgab2_dgbb_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 16] += d4F_dgab_dgbb2_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 17] += d4F_dgab_dgbb2_dlb;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 18] += d4F_dgbb3_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 19] += d4F_dgbb3_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 1] += d4F_dgaa2_dla_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 2] += d4F_dgaa2_dlb2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 3] += d4F_dgaa_dgab_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 4] += d4F_dgaa_dgab_dla_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 5] += d4F_dgaa_dgab_dlb2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 6] += d4F_dgaa_dgbb_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 7] += d4F_dgaa_dgbb_dla_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 8] += d4F_dgaa_dgbb_dlb2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 9] += d4F_dgab2_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 10] += d4F_dgab2_dla_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 11] += d4F_dgab2_dlb2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 12] += d4F_dgab_dgbb_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 13] += d4F_dgab_dgbb_dla_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 14] += d4F_dgab_dgbb_dlb2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 15] += d4F_dgbb2_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 16] += d4F_dgbb2_dla_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 17] += d4F_dgbb2_dlb2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 1] += d4F_dgaa_dla2_dlb;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 2] += d4F_dgaa_dla_dlb2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 3] += d4F_dgaa_dlb3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 4] += d4F_dgab_dla3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 5] += d4F_dgab_dla2_dlb;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 6] += d4F_dgab_dla_dlb2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 7] += d4F_dgab_dlb3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 8] += d4F_dgbb_dla3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 9] += d4F_dgbb_dla2_dlb;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 10] += d4F_dgbb_dla_dlb2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 11] += d4F_dgbb_dlb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 1] += d4F_dla3_dlb;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 2] += d4F_dla2_dlb2;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 3] += d4F_dla_dlb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 4] += d4F_dlb4;
#endif
#endif
}
#endif