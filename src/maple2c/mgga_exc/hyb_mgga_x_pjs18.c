/*
  Generated from python/mgga_exc/hyb_mgga_x_pjs18.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py hyb_mgga_x_pjs18
*/

#ifndef _HYB_MGGA_X_PJS18_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _HYB_MGGA_X_PJS18_KERNEL_BODY
#define _KMAX 0
#define _HYB_MGGA_X_PJS18_HELPER_BODIES
#include "hyb_mgga_x_pjs18.c"
#undef _HYB_MGGA_X_PJS18_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _HYB_MGGA_X_PJS18_HELPER_BODIES
#include "hyb_mgga_x_pjs18.c"
#undef _HYB_MGGA_X_PJS18_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _HYB_MGGA_X_PJS18_HELPER_BODIES
#include "hyb_mgga_x_pjs18.c"
#undef _HYB_MGGA_X_PJS18_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _HYB_MGGA_X_PJS18_HELPER_BODIES
#include "hyb_mgga_x_pjs18.c"
#undef _HYB_MGGA_X_PJS18_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _HYB_MGGA_X_PJS18_HELPER_BODIES
#include "hyb_mgga_x_pjs18.c"
#undef _HYB_MGGA_X_PJS18_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "hyb_mgga_x_pjs18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_HYB_MGGA_X_PJS18_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_4_3_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z + 0.1e1;
  const double _t2 = _t1 <= p->zeta_threshold;

  const double f = my_piecewise3(_t2, xc_powr(p->zeta_threshold, 4, 3), xc_powr(_t1, 4, 3));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*xc_powr(_t1, 1, 3));
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)/xc_powr(_t1, 2, 3));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, 0, -(0.8e1 / 0.27e2)/xc_powr(_t1, 5, 3));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)/xc_powr(_t1, 8, 3));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(z_thr_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z + 0.1e1 <= p->zeta_threshold;
  const double _t2 = p->zeta_threshold - 0.1e1;
  const double _t3 = 0.1e1 - z <= p->zeta_threshold;
#if _KMAX >= 2
  const double _t4 = my_piecewise5(_t1, 0, _t3, 0, 0);
#endif

  const double f = my_piecewise5(_t1, _t2, _t3, -_t2, z);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise5(_t1, 0, _t3, 0, 0.1e1);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t4;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t4;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t4;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc0);
  const double _t1 = xc_powr(0.6e1, 1, 3)*M_CBRT3/(M_CBRTPI*M_CBRTPI);
  const double _t2 = (0.3e1 / 0.16e2)*_t1;
  const double _t3 = _t2/rs;
#if _KMAX >= 1
  const double _t4 = _t2/(rs * rs);
#endif
#if _KMAX >= 2
  const double _t5 = _hc0[0]*_t1;
  const double _t6 = (0.3e1 / 0.8e1)/(rs * rs * rs);
#endif
#if _KMAX >= 3
  const double _t7 = _t1*_t6;
  const double _t8 = (0.9e1 / 0.8e1)/(rs * rs * rs * rs);
#endif

  const double f = -_hc0[0]*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc0[1]*_t3;
  out[1] = df_dz;
  const double df_drs = _hc0[0]*_t4;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -_hc0[2]*_t3;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_t4;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -_t5*_t6;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_hc0[3]*_t3;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[2]*_t4;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = -_hc0[1]*_t7;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _t5*_t8;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_hc0[4]*_t3;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc0[3]*_t4;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = -_hc0[2]*_t7;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[1]*_t1*_t8;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = -0.9e1 / 0.2e1*_t5/xc_powi(rs, 5);
  out[14] = d4f_drs4;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux1_k, _KMAX)(const xc_func_type *p, double a, double *out) {

#if _KMAX >= 1
  const double _t1 = (0.1e1 / (a * a));
  const double _t2 = exp(-0.1e1 / 0.4e1*_t1);
#endif
#if _KMAX >= 2
  const double _t3 = _t2/xc_powi(a, 5);
#endif

  const double f = xc_powr(M_PI, 1, 2)*erf((0.1e1 / 0.2e1)/a);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t1*_t2;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.2e1*_t2/(a * a * a) - 0.1e1 / 0.2e1*_t3;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -0.6e1*_t2/(a * a * a * a) + (0.7e1 / 0.2e1)*_t2/xc_powi(a, 6) - 0.1e1 / 0.4e1*_t2/xc_powi(a, 8);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.24e2*_t2/xc_powi(a, 7) + (0.15e2 / 0.4e1)*_t2/xc_powi(a, 9) - 0.1e1 / 0.8e1*_t2/xc_powi(a, 11) + 0.24e2*_t3;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux2_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = xc_expm1(-(0.1e1 / 0.4e1)/(a * a));
#if _KMAX >= 1
  const double _t2 = _t1 + 0.1e1;
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi(a, -6);
#endif
#if _KMAX >= 3
  const double _t4 = (0.9e1 / 0.4e1)*_t2;
#endif

  const double f = _t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = (0.1e1 / 0.2e1)*_t2/(a * a * a);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = (0.1e1 / 0.4e1)*_t2*_t3 - 0.3e1 / 0.2e1*_t2/(a * a * a * a);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.6e1*_t2/xc_powi(a, 5) + (0.1e1 / 0.8e1)*_t2/xc_powi(a, 9) - _t4/xc_powi(a, 7);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.30e2*_t2*_t3 + (0.75e2 / 0.4e1)*_t2/xc_powi(a, 8) + (0.1e1 / 0.16e2)*_t2/xc_powi(a, 12) - _t4/xc_powi(a, 10);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux3_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux2_k, _KMAX)(p, a, _hc0);
  const double _t1 = 0.2e1*(a * a);
#if _KMAX >= 1
  const double _t2 = 0.4e1*_hc0[0];
#endif

  const double f = _hc0[0]*_t1 + 0.1e1 / 0.2e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _hc0[1]*_t1 + _t2*a;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.8e1*_hc0[1]*a + _hc0[2]*_t1 + _t2;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.12e2*_hc0[1] + 0.12e2*_hc0[2]*a + _hc0[3]*_t1;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.24e2*_hc0[2] + 0.16e2*_hc0[3]*a + _hc0[4]*_t1;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf0_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux3_k, _KMAX)(p, a, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux2_k, _KMAX)(p, a, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux1_k, _KMAX)(p, a, _hc2);
  const double _t1 = a*(-_hc0[0] + _hc1[0]);
  const double _t2 = (0.8e1 / 0.3e1)*a;
#if _KMAX >= 1
  const double _t3 = a*(-_hc0[1] + _hc1[1]);
#endif
#if _KMAX >= 2
  const double _t4 = a*(-_hc0[2] + _hc1[2]);
#endif
#if _KMAX >= 3
  const double _t5 = a*(-_hc0[3] + _hc1[3]);
#endif

  const double f = -_t2*(_hc2[0] + 0.2e1*_t1) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -0.8e1 / 0.3e1*_hc2[0] - 0.16e2 / 0.3e1*_t1 - _t2*(-0.2e1*_hc0[0] + 0.2e1*_hc1[0] + _hc2[1] + 0.2e1*_t3);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = (0.32e2 / 0.3e1)*_hc0[0] - 0.32e2 / 0.3e1*_hc1[0] - 0.16e2 / 0.3e1*_hc2[1] - _t2*(-0.4e1*_hc0[1] + 0.4e1*_hc1[1] + _hc2[2] + 0.2e1*_t4) - 0.32e2 / 0.3e1*_t3;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.32e2*_hc0[1] - 0.32e2*_hc1[1] - 0.8e1*_hc2[2] - _t2*(-0.6e1*_hc0[2] + 0.6e1*_hc1[2] + _hc2[3] + 0.2e1*_t5) - 0.16e2*_t4;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.64e2*_hc0[2] - 0.64e2*_hc1[2] - 0.32e2 / 0.3e1*_hc2[3] - _t2*(-0.8e1*_hc0[3] + 0.8e1*_hc1[3] + _hc2[4] + 0.2e1*a*(-_hc0[4] + _hc1[4])) - 0.64e2 / 0.3e1*_t5;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = a > 1.3500000000000001;
  const double _t2 = a >= 1.3500000000000001;
  const double _t3 = my_piecewise3(_t1, a, 1.3500000000000001);
  const double _t4 = xc_powi(_t3, -14);
  const double _t5 = xc_powi(_t3, -12);
  const double _t6 = xc_powi(_t3, -10);
  const double _t7 = xc_powi(_t3, -8);
  const double _t8 = xc_powi(_t3, -6);
  const double _t9 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
#if _KMAX >= 1
  const double _t10 = my_piecewise3(_t1, 0.1e1, 0);
  const double _t11 = xc_powi(_t3, -15);
  const double _t12 = xc_powi(_t3, -13);
  const double _t13 = xc_powi(_t3, -11);
  const double _t14 = xc_powi(_t3, -9);
  const double _t15 = xc_powi(_t3, -7);
  const double _t16 = xc_powi(_t3, -5);
  const double _t17 = my_piecewise3(_t1, 0, 0.1e1);
#endif
#if _KMAX >= 2
  const double _t18 = xc_powi(_t3, -16);
  const double _t19 = (_t10 * _t10);
#endif
#if _KMAX >= 3
  const double _t20 = (_t10 * _t10 * _t10);
#endif
#if _KMAX >= 4
  const double _t21 = (_t10 * _t10 * _t10 * _t10);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(attenuation_erf0_k, _KMAX)(p, my_piecewise3(_t1, 1.3500000000000001, a), _hc0);

  const double f = my_piecewise3(_t2, (0.1e1 / 0.44590694400e11)*_t4 - 0.1e1 / 0.1073479680e10*_t5 + (0.1e1 / 0.28385280e8)*_t6 - 0.1e1 / 0.829440e6*_t7 + (0.1e1 / 0.26880e5)*_t8 - 0.1e1 / 0.960e3*_t9 + (0.1e1 / 0.36e2)/(_t3 * _t3), _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, -0.1e1 / 0.3185049600e10*_t10*_t11 + (0.1e1 / 0.89456640e8)*_t10*_t12 - 0.1e1 / 0.2838528e7*_t10*_t13 + (0.1e1 / 0.103680e6)*_t10*_t14 - 0.1e1 / 0.4480e4*_t10*_t15 + (0.1e1 / 0.240e3)*_t10*_t16 - 0.1e1 / 0.18e2*_t10/(_t3 * _t3 * _t3), _hc0[1]*_t17);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, (0.1e1 / 0.212336640e9)*_t18*_t19 - 0.1e1 / 0.6881280e7*_t19*_t4 + (0.1e1 / 0.258048e6)*_t19*_t5 - 0.1e1 / 0.11520e5*_t19*_t6 + (0.1e1 / 0.640e3)*_t19*_t7 - 0.1e1 / 0.48e2*_t19*_t8 + (0.1e1 / 0.6e1)*_t19*_t9, _hc0[2]*(_t17 * _t17));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, (0.1e1 / 0.491520e6)*_t11*_t20 - 0.1e1 / 0.21504e5*_t12*_t20 + (0.1e1 / 0.1152e4)*_t13*_t20 - 0.1e1 / 0.80e2*_t14*_t20 + (0.1e1 / 0.8e1)*_t15*_t20 - 0.2e1 / 0.3e1*_t16*_t20 - 0.1e1 / 0.13271040e8*_t20/xc_powi(_t3, 17), _hc0[3]*(_t17 * _t17 * _t17));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, -0.1e1 / 0.32768e5*_t18*_t21 + (0.13e2 / 0.21504e5)*_t21*_t4 - 0.11e2 / 0.1152e4*_t21*_t5 + (0.9e1 / 0.80e2)*_t21*_t6 - 0.7e1 / 0.8e1*_t21*_t7 + (0.10e2 / 0.3e1)*_t21*_t8 + (0.17e2 / 0.13271040e8)*_t21/xc_powi(_t3, 18), _hc0[4]*(_t17 * _t17 * _t17 * _t17));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_p_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
#if _KMAX >= 1
  const double _t2 = (0.1e1 / 0.12e2)*_t1;
#endif

  const double f = (0.1e1 / 0.24e2)*_t1*(x * x);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t2*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _t2;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_y_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_p_k, _KMAX)(p, x, _hc0);

  const double f = 0.13927823999999997*_hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 0.13927823999999997*_hc0[1];
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.13927823999999997*_hc0[2];
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_f0_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_y_k, _KMAX)(p, x, _hc0);
  const double _t1 = 79.873000000000005*((_hc0[0]) * (_hc0[0])) + (0.700e3 / 0.27e2)*_hc0[0] + 0.1e1;
#if _KMAX >= 1
  const double _t2 = 15.974600000000002*_hc0[0];
  const double _t3 = _hc0[1]*_t2 + (0.70e2 / 0.27e2)*_hc0[1];
  const double _t4 = pow(_t1, -0.9e1 / 0.10e2);
#endif
#if _KMAX >= 2
  const double _t5 = ((_hc0[1]) * (_hc0[1]));
  const double _t6 = _hc0[2]*_t2 + (0.70e2 / 0.27e2)*_hc0[2] + 15.974600000000002*_t5;
  const double _t7 = 143.7714*_hc0[0];
  const double _t8 = -_hc0[1]*_t7 - 0.70e2 / 0.3e1*_hc0[1];
  const double _t9 = pow(_t1, -0.19e2 / 0.10e2);
  const double _t10 = _t3*_t9;
#endif
#if _KMAX >= 3
  const double _t11 = _hc0[1]*_hc0[2];
  const double _t12 = _hc0[3]*_t2 + (0.70e2 / 0.27e2)*_hc0[3] + 47.923800000000007*_t11;
  const double _t13 = -_hc0[2]*_t7 - 0.70e2 / 0.3e1*_hc0[2] - 143.7714*_t5;
  const double _t14 = _t8*_t9;
  const double _t15 = 303.51740000000001*_hc0[0];
  const double _t16 = -_hc0[1]*_t15 - 0.1330e4 / 0.27e2*_hc0[1];
  const double _t17 = pow(_t1, -0.29e2 / 0.10e2);
  const double _t18 = _t17*_t3*_t8;
#endif
#if _KMAX >= 4
  const double _t19 = 0.3e1*_t6;
  const double _t20 = _t16*_t17;
#endif

  const double f = pow(_t1, 0.1e1 / 0.10e2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t3*_t4;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _t10*_t8 + _t4*_t6;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _t10*_t13 + _t12*_t4 + 0.2e1*_t14*_t6 + _t16*_t18;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t10*(-_hc0[3]*_t7 - 0.70e2 / 0.3e1*_hc0[3] - 431.31420000000003*_t11) + 0.3e1*_t12*_t14 + _t13*_t19*_t9 + 0.2e1*_t13*_t20*_t3 + _t18*(-_hc0[2]*_t15 - 0.1330e4 / 0.27e2*_hc0[2] - 303.51740000000001*_t5) + _t19*_t20*_t8 + _t4*(63.898400000000009*_hc0[1]*_hc0[3] + 47.923800000000007*((_hc0[2]) * (_hc0[2])) + _hc0[4]*_t2 + (0.70e2 / 0.27e2)*_hc0[4]) + _t16*_t3*_t8*(-463.26339999999999*_hc0[0]*_hc0[1] - 0.2030e4 / 0.27e2*_hc0[1])/pow(_t1, 0.39e2 / 0.10e2);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf_f20_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = (a * a);
  const double _t2 = (a * a * a * a);
  const double _t3 = 0.64e2*_t2;
  const double _t4 = (0.1e1 / a);
  const double _t5 = xc_powr(M_PI, 1, 2)*erf((0.1e1 / 0.2e1)*_t4);
  const double _t6 = 0.10e2*_t5;
  const double _t7 = (0.1e1 / _t1);
  const double _t8 = exp(-0.1e1 / 0.4e1*_t7);
  const double _t9 = 0.20e2*_t1 - _t3;
  const double _t10 = _t8*_t9;
  const double _t11 = -0.36e2*_t1 + _t10 + _t3 + _t6*a - 0.3e1;
  const double _t12 = 0.24e2*_t1;
#if _KMAX >= 1
  const double _t13 = (a * a * a);
  const double _t14 = 0.256e3*_t13;
  const double _t15 = _t4*_t8;
  const double _t16 = -_t14 + 0.40e2*a;
  const double _t17 = _t16*_t8;
  const double _t18 = (0.1e1 / _t13);
  const double _t19 = _t10*_t18;
  const double _t20 = _t14 - 0.10e2*_t15 + _t17 + (0.1e1 / 0.2e1)*_t19 + _t6 - 0.72e2*a;
#endif
#if _KMAX >= 2
  const double _t21 = 0.768e3*_t1;
  const double _t22 = (0.1e1 / _t2);
  const double _t23 = _t22*_t8;
  const double _t24 = 0.40e2 - _t21;
  const double _t25 = _t24*_t8;
  const double _t26 = _t17*_t18;
  const double _t27 = xc_powi(a, -6);
  const double _t28 = _t10*_t27;
  const double _t29 = _t10*_t22;
  const double _t30 = _t21 - 0.5e1*_t23 + _t25 + _t26 + (0.1e1 / 0.4e1)*_t28 - 0.3e1 / 0.2e1*_t29 - 0.72e2;
#endif
#if _KMAX >= 3
  const double _t31 = 0.1536e4*a;
  const double _t32 = xc_powi(a, -7);
  const double _t33 = xc_powi(a, -5);
  const double _t34 = xc_powi(a, -9);
  const double _t35 = (0.9e1 / 0.4e1)*_t10;
  const double _t36 = 0.6e1*_t10*_t33 + (0.1e1 / 0.8e1)*_t10*_t34 - 0.9e1 / 0.2e1*_t17*_t22 + (0.3e1 / 0.4e1)*_t17*_t27 + (0.3e1 / 0.2e1)*_t18*_t25 - _t31*_t8 + _t31 - _t32*_t35 - 0.5e1 / 0.2e1*_t32*_t8 + 0.20e2*_t33*_t8;
#endif
#if _KMAX >= 4
  const double _t37 = xc_powi(a, -10);
  const double _t38 = xc_powi(a, -8);
#endif

  const double f = _t11*_t12 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = 0.48e2*_t11*a + _t12*_t20;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -0.1728e4*_t1 + 0.48e2*_t10 + _t12*_t30 + 0.3072e4*_t2 + 0.96e2*_t20*a + 0.480e3*_t5*a - 0.144e3;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _t12*_t36 + 0.36864e5*_t13 - 0.1440e4*_t15 + 0.144e3*_t17 + 0.72e2*_t19 + 0.144e3*_t30*a + 0.1440e4*_t5 - 0.10368e5*a;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.221184e6*_t1 + _t12*(0.24e2*_t16*_t33*_t8 + (0.1e1 / 0.2e1)*_t16*_t34*_t8 - 0.9e1*_t17*_t32 - 0.9e1*_t22*_t25 + (0.3e1 / 0.2e1)*_t24*_t27*_t8 - 0.100e3*_t27*_t8 - 0.30e2*_t28 - _t35*_t37 - 0.5e1 / 0.4e1*_t37*_t8 + (0.75e2 / 0.4e1)*_t38*_t8*_t9 + (0.55e2 / 0.2e1)*_t38*_t8 - 0.3072e4*_t7*_t8 + (0.1e1 / 0.16e2)*_t8*_t9/xc_powi(a, 12) - 0.1536e4*_t8 + 0.1536e4) - 0.1440e4*_t23 + 0.288e3*_t25 + 0.288e3*_t26 + 0.72e2*_t28 - 0.432e3*_t29 + 0.192e3*_t36*a - 0.20736e5;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf_f2_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = a > 0.27000000000000002;
  const double _t2 = a >= 0.27000000000000002;
  const double _t3 = my_piecewise3(_t1, a, 0.27000000000000002);
  const double _t4 = xc_powi(_t3, -44);
  const double _t5 = xc_powi(_t3, -42);
  const double _t6 = xc_powi(_t3, -40);
  const double _t7 = xc_powi(_t3, -38);
  const double _t8 = xc_powi(_t3, -36);
  const double _t9 = xc_powi(_t3, -34);
  const double _t10 = xc_powi(_t3, -32);
  const double _t11 = xc_powi(_t3, -30);
  const double _t12 = xc_powi(_t3, -28);
  const double _t13 = xc_powi(_t3, -26);
  const double _t14 = xc_powi(_t3, -24);
  const double _t15 = xc_powi(_t3, -22);
  const double _t16 = xc_powi(_t3, -20);
  const double _t17 = xc_powi(_t3, -18);
  const double _t18 = xc_powi(_t3, -16);
  const double _t19 = xc_powi(_t3, -14);
  const double _t20 = xc_powi(_t3, -12);
  const double _t21 = xc_powi(_t3, -10);
  const double _t22 = xc_powi(_t3, -8);
  const double _t23 = xc_powi(_t3, -6);
#if _KMAX >= 1
  const double _t24 = my_piecewise3(_t1, 0.1e1, 0);
  const double _t25 = xc_powi(_t3, -45);
  const double _t26 = xc_powi(_t3, -43);
  const double _t27 = xc_powi(_t3, -41);
  const double _t28 = xc_powi(_t3, -39);
  const double _t29 = xc_powi(_t3, -37);
  const double _t30 = xc_powi(_t3, -35);
  const double _t31 = xc_powi(_t3, -33);
  const double _t32 = xc_powi(_t3, -31);
  const double _t33 = xc_powi(_t3, -29);
  const double _t34 = xc_powi(_t3, -27);
  const double _t35 = xc_powi(_t3, -25);
  const double _t36 = xc_powi(_t3, -23);
  const double _t37 = xc_powi(_t3, -21);
  const double _t38 = xc_powi(_t3, -19);
  const double _t39 = xc_powi(_t3, -17);
  const double _t40 = xc_powi(_t3, -15);
  const double _t41 = xc_powi(_t3, -13);
  const double _t42 = xc_powi(_t3, -11);
  const double _t43 = xc_powi(_t3, -9);
  const double _t44 = xc_powi(_t3, -7);
  const double _t45 = my_piecewise3(_t1, 0, 0.1e1);
#endif
#if _KMAX >= 2
  const double _t46 = xc_powi(_t3, -46);
  const double _t47 = (_t24 * _t24);
#endif
#if _KMAX >= 3
  const double _t48 = (_t24 * _t24 * _t24);
#endif
#if _KMAX >= 4
  const double _t49 = (_t24 * _t24 * _t24 * _t24);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(attenuation_erf_f20_k, _KMAX)(p, my_piecewise3(_t1, 0.27000000000000002, a), _hc0);

  const double f = my_piecewise3(_t2, (0.1e1 / 0.67726520292999771979776000e26)*_t10 - 0.1e1 / 0.900231674141645733888000e24*_t11 + (0.1e1 / 0.12648942844388573184000e23)*_t12 - 0.1e1 / 0.188514051721003008000e21*_t13 + (0.1e1 / 0.2991700272218112000e19)*_t14 - 0.1e1 / 0.50785035485184000e17*_t15 + (0.1e1 / 0.927028425523200e15)*_t16 - 0.1e1 / 0.18311911833600e14*_t17 + (0.1e1 / 0.394474291200e12)*_t18 - 0.1e1 / 0.9358540800e10*_t19 + (0.1e1 / 0.247726080e9)*_t20 - 0.1e1 / 0.7454720e7*_t21 + (0.3e1 / 0.788480e6)*_t22 - 0.1e1 / 0.11520e5*_t23 + (0.1e1 / 0.33929038000650146833571361325056000000e38)*_t4 - 0.1e1 / 0.341095116070365837848137621831680000e36*_t5 + (0.1e1 / 0.3573852336994573837102806466560000e34)*_t6 - 0.1e1 / 0.39097165634742908368485089280000e32*_t7 + (0.1e1 / 0.447473103488807905221672960000e30)*_t8 - 0.1e1 / 0.5369745537516410492682240000e28*_t9 + (0.3e1 / 0.2240e4)/(_t3 * _t3 * _t3 * _t3), _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, -0.1e1 / 0.771114500014776064399349121024000000e36*_t24*_t25 + (0.1e1 / 0.8121312287389662805908038615040000e34)*_t24*_t26 - 0.1e1 / 0.89346308424864345927570161664000e32*_t24*_t27 + (0.1e1 / 0.1028872779861655483381186560000e31)*_t24*_t28 - 0.1e1 / 0.12429808430244664033935360000e29*_t24*_t29 + (0.1e1 / 0.157933692279894426255360000e27)*_t24*_t30 - 0.1e1 / 0.2116453759156242874368000e25*_t24*_t31 + (0.1e1 / 0.30007722471388191129600e23)*_t24*_t32 - 0.1e1 / 0.451747958728163328000e21*_t24*_t33 + (0.1e1 / 0.7250540450807808000e19)*_t24*_t34 - 0.1e1 / 0.124654178009088000e18*_t24*_t35 + (0.1e1 / 0.2308410703872000e16)*_t24*_t36 - 0.1e1 / 0.46351421276160e14*_t24*_t37 + (0.1e1 / 0.1017328435200e13)*_t24*_t38 - 0.1e1 / 0.24654643200e11*_t24*_t39 + (0.1e1 / 0.668467200e9)*_t24*_t40 - 0.1e1 / 0.20643840e8*_t24*_t41 + (0.1e1 / 0.745472e6)*_t24*_t42 - 0.3e1 / 0.98560e5*_t24*_t43 + (0.1e1 / 0.1920e4)*_t24*_t44 - 0.3e1 / 0.560e3*_t24/xc_powi(_t3, 5), _hc0[1]*_t45);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, -0.31e2 / 0.30007722471388191129600e23*_t10*_t47 + (0.29e2 / 0.451747958728163328000e21)*_t11*_t47 - 0.1e1 / 0.268538535215104000e18*_t12*_t47 + (0.1e1 / 0.4986167120363520e16)*_t13*_t47 - 0.23e2 / 0.2308410703872000e16*_t14*_t47 + (0.1e1 / 0.2207210536960e13)*_t15*_t47 - 0.19e2 / 0.1017328435200e13*_t16*_t47 + (0.17e2 / 0.24654643200e11)*_t17*_t47 - 0.1e1 / 0.44564480e8*_t18*_t47 + (0.13e2 / 0.20643840e8)*_t19*_t47 - 0.11e2 / 0.745472e6*_t20*_t47 + (0.27e2 / 0.98560e5)*_t21*_t47 - 0.7e1 / 0.1920e4*_t22*_t47 + (0.3e1 / 0.112e3)*_t23*_t47 - 0.43e2 / 0.8121312287389662805908038615040000e34*_t4*_t47 + (0.1e1 / 0.17135877778106134764429980467200000e35)*_t46*_t47 + (0.41e2 / 0.89346308424864345927570161664000e32)*_t47*_t5 - 0.1e1 / 0.26381353329786038035415040000e29*_t47*_t6 + (0.37e2 / 0.12429808430244664033935360000e29)*_t47*_t7 - 0.1e1 / 0.4512391207996983607296000e25*_t47*_t8 + (0.1e1 / 0.64134962398674026496000e23)*_t47*_t9, _hc0[2]*(_t45 * _t45));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, (0.43e2 / 0.184575279258855972861546332160000e33)*_t25*_t48 - 0.41e2 / 0.2127293057734865379227860992000e31*_t26*_t48 + (0.1e1 / 0.659533833244650950885376000e27)*_t27*_t48 - 0.37e2 / 0.327100221848543790366720000e27*_t28*_t48 + (0.1e1 / 0.125344200222138433536000e24)*_t29*_t48 - 0.1e1 / 0.1886322423490412544000e22*_t30*_t48 + (0.31e2 / 0.937741327230880972800e21)*_t31*_t48 - 0.29e2 / 0.15058265290938777600e20*_t32*_t48 + (0.1e1 / 0.9590661971968000e16)*_t33*_t48 - 0.1e1 / 0.191775658475520e15*_t34*_t48 + (0.23e2 / 0.96183779328000e14)*_t35*_t48 - 0.1e1 / 0.100327751680e12*_t36*_t48 + (0.19e2 / 0.50866421760e11)*_t37*_t48 - 0.17e2 / 0.1369702400e10*_t38*_t48 + (0.1e1 / 0.2785280e7)*_t39*_t48 - 0.13e2 / 0.1474560e7*_t40*_t48 + (0.33e2 / 0.186368e6)*_t41*_t48 - 0.27e2 / 0.9856e4*_t42*_t48 + (0.7e1 / 0.240e3)*_t43*_t48 - 0.9e1 / 0.56e2*_t44*_t48 - 0.1e1 / 0.372519082132742060096303923200000e33*_t48/xc_powi(_t3, 47), _hc0[3]*(_t45 * _t45 * _t45));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, (0.29e2 / 0.485750493256089600e18)*_t10*_t49 - 0.1e1 / 0.330712481792000e15*_t11*_t49 + (0.1e1 / 0.7102802165760e13)*_t12*_t49 - 0.23e2 / 0.3847351173120e13*_t13*_t49 + (0.1e1 / 0.4362076160e10)*_t14*_t49 - 0.19e2 / 0.2422210560e10*_t15*_t49 + (0.17e2 / 0.72089600e8)*_t16*_t49 - 0.1e1 / 0.163840e6*_t17*_t49 + (0.13e2 / 0.98304e5)*_t18*_t49 - 0.33e2 / 0.14336e5*_t19*_t49 + (0.27e2 / 0.896e3)*_t20*_t49 - 0.21e2 / 0.80e2*_t21*_t49 + (0.9e1 / 0.8e1)*_t22*_t49 + (0.41e2 / 0.49471931575229427423903744000e29)*_t4*_t49 - 0.43e2 / 0.4101672872419021619145474048000e31*_t46*_t49 - 0.1e1 / 0.16086191054747584167936000e26*_t49*_t5 + (0.37e2 / 0.8387185175603686932480000e25)*_t49*_t6 - 0.1e1 / 0.3387681087084822528000e22*_t49*_t7 + (0.1e1 / 0.53894926385440358400e20)*_t49*_t8 - 0.31e2 / 0.28416403855481241600e20*_t49*_t9 + (0.1e1 / 0.7925937917717916172261785600000e31)*_t49/xc_powi(_t3, 48), _hc0[4]*(_t45 * _t45 * _t45 * _t45));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf_f30_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = (0.1e1 / a);
  const double _t2 = xc_powr(M_PI, 1, 2)*erf((0.1e1 / 0.2e1)*_t1);
  const double _t3 = (a * a);
  const double _t4 = 0.60e2*_t3 - 0.2e1;
  const double _t5 = 0.2e1*_t4;
  const double _t6 = (a * a * a * a);
  const double _t7 = xc_powi(a, 6);
  const double _t8 = 0.224e3*_t3 - 0.1440e4*_t6 + 0.5120e4*_t7 - 0.35e2;
  const double _t9 = (a * a * a);
  const double _t10 = 0.24e2*_t9;
  const double _t11 = (0.1e1 / _t3);
  const double _t12 = exp(-0.1e1 / 0.4e1*_t11);
  const double _t13 = xc_powi(a, 5);
  const double _t14 = xc_powi(a, 7);
  const double _t15 = xc_powi(a, 9);
  const double _t16 = _t12*(-0.576e3*_t13 + 0.3840e4*_t14 - 0.122880e6*_t15 + 0.256e3*_t9 - 0.8e1*a);
  const double _t17 = (0.8e1 / 0.7e1)*a;
#if _KMAX >= 1
  const double _t18 = (0.16e2 / 0.7e1)*_t4;
  const double _t19 = (0.8e1 / 0.7e1)*_t16;
  const double _t20 = 0.240e3*_t2;
  const double _t21 = _t11*_t12;
  const double _t22 = 0.30720e5*_t13 - 0.5760e4*_t9 + 0.448e3*a;
  const double _t23 = _t3*_t8;
  const double _t24 = xc_powi(a, 8);
  const double _t25 = _t12*(-0.1105920e7*_t24 + 0.768e3*_t3 - 0.2880e4*_t6 + 0.26880e5*_t7 - 0.8e1);
  const double _t26 = (0.1e1 / _t9);
#endif
#if _KMAX >= 2
  const double _t27 = _t1*_t12;
  const double _t28 = -0.17280e5*_t3 + 0.153600e6*_t6 + 0.448e3;
  const double _t29 = (0.1e1 / _t13);
  const double _t30 = _t12*_t29;
  const double _t31 = _t30*_t4;
  const double _t32 = _t12*_t26;
  const double _t33 = _t32*_t4;
  const double _t34 = _t22*_t3;
  const double _t35 = _t8*a;
  const double _t36 = _t12*(0.161280e6*_t13 - 0.8847360e7*_t14 - 0.11520e5*_t9 + 0.1536e4*a);
  const double _t37 = _t25*_t26;
  const double _t38 = (0.1e1 / _t7);
  const double _t39 = _t16*_t38;
  const double _t40 = (0.1e1 / _t6);
  const double _t41 = _t16*_t40;
#endif
#if _KMAX >= 3
  const double _t42 = _t12*_t40;
  const double _t43 = 0.614400e6*_t9 - 0.34560e5*a;
  const double _t44 = _t22*a;
  const double _t45 = _t28*_t3;
  const double _t46 = (0.1e1 / _t24);
  const double _t47 = _t12*_t4;
  const double _t48 = _t38*_t47;
  const double _t49 = _t4*_t42;
  const double _t50 = _t12*(-0.34560e5*_t3 + 0.806400e6*_t6 - 0.61931520e8*_t7 + 0.1536e4);
  const double _t51 = (0.3e1 / 0.2e1)*_t36;
  const double _t52 = _t25*_t38;
  const double _t53 = _t25*_t40;
  const double _t54 = (0.1e1 / _t15);
  const double _t55 = _t16*_t54;
  const double _t56 = (0.1e1 / _t14);
  const double _t57 = (0.9e1 / 0.4e1)*_t16;
  const double _t58 = _t16*_t29;
#endif
#if _KMAX >= 4
  const double _t59 = _t12*_t56;
#endif

  const double f = _t17*(_t10*_t8 + _t16 + _t2*_t5) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t17*(_t10*_t22 + (0.1e1 / 0.2e1)*_t16*_t26 + _t20*a - _t21*_t5 + 0.72e2*_t23 + _t25) + _t18*_t2 + _t19 + (0.192e3 / 0.7e1)*_t8*_t9;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t17*(_t10*_t28 + _t20 - 0.480e3*_t27 - _t31 + 0.4e1*_t33 + 0.144e3*_t34 + 0.144e3*_t35 + _t36 + _t37 + (0.1e1 / 0.4e1)*_t39 - 0.3e1 / 0.2e1*_t41) + _t19*_t26 + (0.3840e4 / 0.7e1)*_t2*a - 0.32e2 / 0.7e1*_t21*_t4 + (0.384e3 / 0.7e1)*_t22*_t9 + (0.1152e4 / 0.7e1)*_t23 + (0.16e2 / 0.7e1)*_t25;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _t17*(_t10*_t43 + 0.720e3*_t21 + _t26*_t51 + 0.32256e5*_t3 - 0.360e3*_t42 + 0.432e3*_t44 + 0.216e3*_t45 - 0.1e1 / 0.2e1*_t46*_t47 + 0.7e1*_t48 - 0.12e2*_t49 + _t50 + (0.3e1 / 0.4e1)*_t52 - 0.9e1 / 0.2e1*_t53 + (0.1e1 / 0.8e1)*_t55 - _t56*_t57 + 0.6e1*_t58 - 0.207360e6*_t6 + 0.737280e6*_t7 - 0.5040e4) + (0.5760e4 / 0.7e1)*_t2 - 0.11520e5 / 0.7e1*_t27 + (0.576e3 / 0.7e1)*_t28*_t9 - 0.24e2 / 0.7e1*_t31 + (0.96e2 / 0.7e1)*_t33 + (0.3456e4 / 0.7e1)*_t34 + (0.3456e4 / 0.7e1)*_t35 + (0.24e2 / 0.7e1)*_t36 + (0.24e2 / 0.7e1)*_t37 + (0.6e1 / 0.7e1)*_t39 - 0.36e2 / 0.7e1*_t41;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -_t12*_t18*_t46 - 0.72e2 / 0.7e1*_t16*_t56 + _t17*(_t10*(0.1843200e7*_t3 - 0.34560e5) + _t12*(-0.371589120e9*_t13 + 0.3225600e7*_t9 - 0.69120e5*a) + 0.17694720e8*_t13 + (0.75e2 / 0.4e1)*_t16*_t46 + (0.1e1 / 0.16e2)*_t16/xc_powi(a, 12) + 0.24e2*_t25*_t29 + (0.1e1 / 0.2e1)*_t25*_t54 - 0.9e1*_t25*_t56 + 0.2e1*_t26*_t50 + 0.864e3*_t28*a + 0.288e3*_t3*_t43 + 0.2640e4*_t30 + 0.48e2*_t31 - 0.2880e4*_t32 - 0.9e1*_t36*_t40 + _t38*_t51 - 0.30e2*_t39 - 0.48e2*_t4*_t59 + (0.15e2 / 0.2e1)*_t47*_t54 - 0.1e1 / 0.4e1*_t47/xc_powi(a, 11) - _t57/xc_powi(a, 10) - 0.240e3*_t59 - 0.3317760e7*_t9 + 0.258048e6*a) + (0.23040e5 / 0.7e1)*_t21 + (0.48e2 / 0.7e1)*_t26*_t36 + 0.147456e6*_t3 - 0.11520e5 / 0.7e1*_t42 + (0.768e3 / 0.7e1)*_t43*_t9 + (0.13824e5 / 0.7e1)*_t44 + (0.6912e4 / 0.7e1)*_t45 + 0.32e2*_t48 - 0.384e3 / 0.7e1*_t49 + (0.32e2 / 0.7e1)*_t50 + (0.24e2 / 0.7e1)*_t52 - 0.144e3 / 0.7e1*_t53 + (0.4e1 / 0.7e1)*_t55 + (0.192e3 / 0.7e1)*_t58 - 0.6635520e7 / 0.7e1*_t6 + (0.23592960e8 / 0.7e1)*_t7 - 0.23040e5;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf_f3_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = a > 0.32000000000000001;
  const double _t2 = a >= 0.32000000000000001;
  const double _t3 = my_piecewise3(_t1, a, 0.32000000000000001);
  const double _t4 = xc_powi(_t3, -36);
  const double _t5 = xc_powi(_t3, -34);
  const double _t6 = xc_powi(_t3, -32);
  const double _t7 = xc_powi(_t3, -30);
  const double _t8 = xc_powi(_t3, -28);
  const double _t9 = xc_powi(_t3, -26);
  const double _t10 = xc_powi(_t3, -24);
  const double _t11 = xc_powi(_t3, -22);
  const double _t12 = xc_powi(_t3, -20);
  const double _t13 = xc_powi(_t3, -18);
  const double _t14 = xc_powi(_t3, -16);
  const double _t15 = xc_powi(_t3, -14);
  const double _t16 = xc_powi(_t3, -12);
  const double _t17 = xc_powi(_t3, -10);
  const double _t18 = xc_powi(_t3, -8);
  const double _t19 = xc_powi(_t3, -6);
#if _KMAX >= 1
  const double _t20 = my_piecewise3(_t1, 0.1e1, 0);
  const double _t21 = xc_powi(_t3, -37);
  const double _t22 = xc_powi(_t3, -35);
  const double _t23 = xc_powi(_t3, -33);
  const double _t24 = xc_powi(_t3, -31);
  const double _t25 = xc_powi(_t3, -29);
  const double _t26 = xc_powi(_t3, -27);
  const double _t27 = xc_powi(_t3, -25);
  const double _t28 = xc_powi(_t3, -23);
  const double _t29 = xc_powi(_t3, -21);
  const double _t30 = xc_powi(_t3, -19);
  const double _t31 = xc_powi(_t3, -17);
  const double _t32 = xc_powi(_t3, -15);
  const double _t33 = xc_powi(_t3, -13);
  const double _t34 = xc_powi(_t3, -11);
  const double _t35 = xc_powi(_t3, -9);
  const double _t36 = xc_powi(_t3, -7);
  const double _t37 = my_piecewise3(_t1, 0, 0.1e1);
#endif
#if _KMAX >= 2
  const double _t38 = xc_powi(_t3, -38);
  const double _t39 = (_t20 * _t20);
#endif
#if _KMAX >= 3
  const double _t40 = (_t20 * _t20 * _t20);
#endif
#if _KMAX >= 4
  const double _t41 = (_t20 * _t20 * _t20 * _t20);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(attenuation_erf_f30_k, _KMAX)(p, my_piecewise3(_t1, 0.32000000000000001, a), _hc0);

  const double f = my_piecewise3(_t2, (0.1e1 / 0.78244468658012160000e20)*_t10 - 0.1e1 / 0.1168055816159232000e19*_t11 + (0.1e1 / 0.18582706166169600e17)*_t12 - 0.1e1 / 0.316612955602944e15*_t13 + (0.1e1 / 0.5811921223680e13)*_t14 - 0.1e1 / 0.115811942400e12*_t15 + (0.1e1 / 0.2530344960e10)*_t16 - 0.1e1 / 0.61501440e8*_t17 + (0.5e1 / 0.8515584e7)*_t18 - 0.1e1 / 0.56448e5*_t19 + (0.1e1 / 0.22046293272414372635684634624000e32)*_t4 - 0.1e1 / 0.241191070393445437962977280000e30*_t5 + (0.1e1 / 0.2760851680179343645999104000e28)*_t6 - 0.1e1 / 0.33139778504339333578752000e26*_t7 + (0.1e1 / 0.418174050435486229463040e24)*_t8 - 0.1e1 / 0.5562511054710453043200e22*_t9 + (0.3e1 / 0.7840e4)/(_t3 * _t3 * _t3 * _t3), _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, -0.1e1 / 0.612397035344843684324573184000e30*_t20*_t21 + (0.1e1 / 0.7093855011571924645969920000e28)*_t20*_t22 - 0.1e1 / 0.86276615005604488937472000e26*_t20*_t23 + (0.1e1 / 0.1104659283477977785958400e25)*_t20*_t24 - 0.1e1 / 0.14934787515553079623680e23*_t20*_t25 + (0.1e1 / 0.213942732873478963200e21)*_t20*_t26 - 0.1e1 / 0.3260186194083840000e19*_t20*_t27 + (0.1e1 / 0.53093446189056000e17)*_t20*_t28 - 0.1e1 / 0.929135308308480e15*_t20*_t29 + (0.1e1 / 0.17589608644608e14)*_t20*_t30 - 0.1e1 / 0.363245076480e12*_t20*_t31 + (0.1e1 / 0.8272281600e10)*_t20*_t32 - 0.1e1 / 0.210862080e9*_t20*_t33 + (0.1e1 / 0.6150144e7)*_t20*_t34 - 0.5e1 / 0.1064448e7*_t20*_t35 + (0.1e1 / 0.9408e4)*_t20*_t36 - 0.3e1 / 0.1960e4*_t20/xc_powi(_t3, 5), _hc0[1]*_t37);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, -0.1e1 / 0.2308410703872000e16*_t10*_t39 + (0.1e1 / 0.44244538490880e14)*_t11*_t39 - 0.1e1 / 0.925768876032e12*_t12*_t39 + (0.1e1 / 0.21367357440e11)*_t13*_t39 - 0.1e1 / 0.551485440e9*_t14*_t39 + (0.1e1 / 0.16220160e8)*_t15*_t39 - 0.1e1 / 0.559104e6*_t16*_t39 + (0.5e1 / 0.118272e6)*_t17*_t39 - 0.1e1 / 0.1344e4*_t18*_t39 + (0.3e1 / 0.392e3)*_t19*_t39 + (0.1e1 / 0.16551271225536315792556032000e29)*_t38*_t39 - 0.1e1 / 0.202681571759197847027712000e27*_t39*_t4 + (0.1e1 / 0.2614442878957711785984000e25)*_t39*_t5 - 0.1e1 / 0.35634170434773476966400e23*_t39*_t6 + (0.1e1 / 0.514992672950106193920e21)*_t39*_t7 - 0.1e1 / 0.7923804921239961600e19*_t39*_t8 + (0.1e1 / 0.130407447763353600e18)*_t39*_t9, _hc0[2]*(_t37 * _t37));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, (0.1e1 / 0.5630043659977717972992000e25)*_t21*_t40 - 0.17e2 / 0.1307221439478855892992000e25*_t22*_t40 + (0.1e1 / 0.1113567826086671155200e22)*_t23*_t40 - 0.1e1 / 0.17166422431670206464e20*_t24*_t40 + (0.1e1 / 0.282993032901427200e18)*_t25*_t40 - 0.13e2 / 0.65203723881676800e17*_t26*_t40 + (0.1e1 / 0.96183779328000e14)*_t27*_t40 - 0.11e2 / 0.22122269245440e14*_t28*_t40 + (0.5e1 / 0.231442219008e12)*_t29*_t40 - 0.3e1 / 0.3561226240e10*_t30*_t40 + (0.1e1 / 0.34467840e8)*_t31*_t40 - 0.7e1 / 0.8110080e7*_t32*_t40 + (0.1e1 / 0.46592e5)*_t33*_t40 - 0.25e2 / 0.59136e5*_t34*_t40 + (0.1e1 / 0.168e3)*_t35*_t40 - 0.9e1 / 0.196e3*_t36*_t40 - 0.19e2 / 0.8275635612768157896278016000e28*_t40/xc_powi(_t3, 39), _hc0[3]*(_t37 * _t37 * _t37));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, (0.11e2 / 0.961837793280e12)*_t10*_t41 - 0.5e1 / 0.11021058048e11*_t11*_t41 + (0.3e1 / 0.187432960e9)*_t12*_t41 - 0.1e1 / 0.2027520e7*_t13*_t41 + (0.7e1 / 0.540672e6)*_t14*_t41 - 0.1e1 / 0.3584e4*_t15*_t41 + (0.25e2 / 0.5376e4)*_t16*_t41 - 0.3e1 / 0.56e2*_t17*_t41 + (0.9e1 / 0.28e2)*_t18*_t41 - 0.1e1 / 0.152163342161559945216000e24*_t38*_t41 + (0.17e2 / 0.37349183985110168371200e23)*_t4*_t41 - 0.1e1 / 0.33744479578383974400e20*_t41*_t5 + (0.1e1 / 0.553755562311942144e18)*_t41*_t6 - 0.1e1 / 0.9758380444876800e16*_t41*_t7 + (0.13e2 / 0.2414952736358400e16)*_t41*_t8 - 0.1e1 / 0.3847351173120e13*_t41*_t9 + (0.19e2 / 0.212195784942773279391744000e27)*_t41/xc_powi(_t3, 40), _hc0[4]*(_t37 * _t37 * _t37 * _t37));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(js18_H_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_p_k, _KMAX)(p, x, _hc0);

  const double f = 0.13927823999999997*_hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 0.13927823999999997*_hc0[1];
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.13927823999999997*_hc0[2];
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(js18_G_k, _KMAX)(const xc_func_type *p, double x, double t, double *out) {

  const double _t1 = (M_PI * M_CBRTPI);
  const double _t2 = xc_powr(0.6e1, 1, 3)/_t1;
#if _KMAX >= 1
  const double _t3 = 0.046995864814814811*_t2;
#endif

  const double f = (0.5e1 / 0.9e1)*_t2*(0.043662396000000048*xc_powr(0.6e1, 2, 3)*_t1 - 0.14554132000000009*t + 0.042296278333333326*(x * x));
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -0.080856288888888933*_t2;
  out[1] = df_dt;
  const double df_dx = _t3*x;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_dx_dt = 0;
  out[4] = d2f_dx_dt;
  const double d2f_dx2 = _t3;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_dx_dt2 = 0;
  out[7] = d3f_dx_dt2;
  const double d3f_dx2_dt = 0;
  out[8] = d3f_dx2_dt;
  const double d3f_dx3 = 0;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_dx_dt3 = 0;
  out[11] = d4f_dx_dt3;
  const double d4f_dx2_dt2 = 0;
  out[12] = d4f_dx2_dt2;
  const double d4f_dx3_dt = 0;
  out[13] = d4f_dx3_dt;
  const double d4f_dx4 = 0;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(js18_A_k, _KMAX)(const xc_func_type *p, double rs, double z, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.1e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_f0_k, _KMAX)(p, x, _hc1);
  const double _t1 = xc_powr(XC_EPSILON, 2, 3);
  const double _t2 = (0.1e1 / (_hc1[0]));
  const double _t3 = _hc0[0] + 0.1e1;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = xc_powr(0.2e1, 2, 3);
  const double _t6 = M_CBRT3;
  const double _t7 = (0.1e1 / (M_CBRTPI));
  const double _t8 = _t5*_t6*_t7*p->cam_omega;
  const double _t9 = _t4*_t8;
  const double _t10 = (0.1e1 / 0.6e1)*_t9;
  const double _t11 = _t10*_t2;
  const double _t12 = _t11*rs;
  const double _t13 = _t1 > _t12;
#if _KMAX >= 1
  const double _t14 = (0.1e1 / ((_hc1[0]) * (_hc1[0])));
  const double _t15 = _t10*_t14;
  const double _t16 = _hc1[1]*_t15;
  const double _t17 = _t2*_t8;
  const double _t18 = _hc0[2]*_t17;
  const double _t19 = (0.1e1 / (_t3 * _t3));
  const double _t20 = (0.1e1 / 0.6e1)*_t19;
  const double _t21 = _t18*_t20;
#endif
#if _KMAX >= 2
  const double _t22 = _hc1[2]*_t15;
  const double _t23 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t24 = ((_hc1[1]) * (_hc1[1]));
  const double _t25 = _hc1[1]*_t14;
  const double _t26 = _hc0[2]*_t8;
  const double _t27 = _t20*_t26;
  const double _t28 = _t25*_t27;
  const double _t29 = _t17*_t20;
  const double _t30 = _hc0[5]*_t29;
  const double _t31 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t32 = _t17*_t31;
  const double _t33 = ((_hc0[2]) * (_hc0[2]));
  const double _t34 = (0.1e1 / 0.3e1)*_t33;
  const double _t35 = _t32*_t34;
#endif
#if _KMAX >= 3
  const double _t36 = _hc1[3]*_t15;
  const double _t37 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t38 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t37;
  const double _t39 = _t38*_t9;
  const double _t40 = _t14*_t27;
  const double _t41 = _hc1[2]*_t40;
  const double _t42 = _t19*_t26;
  const double _t43 = _t42*rs;
  const double _t44 = (0.1e1 / 0.3e1)*_t23*_t24;
  const double _t45 = _t25*_t8;
  const double _t46 = _t45*rs;
  const double _t47 = _t31*_t34;
  const double _t48 = _hc0[9]*_t29;
  const double _t49 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t50 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t49;
  const double _t51 = _t17*_t50;
#endif
#if _KMAX >= 4
  const double _t52 = _t23*_t9*rs;
  const double _t53 = 0.4e1*rs;
  const double _t54 = _hc1[2]*rs;
#endif

  const double f = my_piecewise3(_t13, _t1, _t12);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = my_piecewise3(_t13, 0, -_t16*rs);
  out[1] = df_dx;
  const double df_dz = my_piecewise3(_t13, 0, -_t21*rs);
  out[2] = df_dz;
  const double df_drs = my_piecewise3(_t13, 0, _t11);
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = my_piecewise3(_t13, 0, -_t22*rs + (0.1e1 / 0.3e1)*_t23*_t24*_t4*_t5*_t6*_t7*p->cam_omega*rs);
  out[4] = d2f_dx2;
  const double d2f_dz_dx = my_piecewise3(_t13, 0, _t28*rs);
  out[5] = d2f_dz_dx;
  const double d2f_dz2 = my_piecewise3(_t13, 0, -_t30*rs + _t35*rs);
  out[6] = d2f_dz2;
  const double d2f_drs_dx = my_piecewise3(_t13, 0, -_t16);
  out[7] = d2f_drs_dx;
  const double d2f_drs_dz = my_piecewise3(_t13, 0, -_t21);
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = 0;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = my_piecewise3(_t13, 0, _hc1[1]*_hc1[2]*_t23*_t4*_t5*_t6*_t7*p->cam_omega*rs - _t36*rs - _t39*rs);
  out[10] = d3f_dx3;
  const double d3f_dz_dx2 = my_piecewise3(_t13, 0, _t41*rs - _t43*_t44);
  out[11] = d3f_dz_dx2;
  const double d3f_dz2_dx = my_piecewise3(_t13, 0, (0.1e1 / 0.6e1)*_hc0[5]*_hc1[1]*_t14*_t19*_t5*_t6*_t7*p->cam_omega*rs - _t46*_t47);
  out[12] = d3f_dz2_dx;
  const double d3f_dz3 = my_piecewise3(_t13, 0, _hc0[2]*_hc0[5]*_t2*_t31*_t5*_t6*_t7*p->cam_omega*rs - _t48*rs - _t51*rs);
  out[13] = d3f_dz3;
  const double d3f_drs_dx2 = my_piecewise3(_t13, 0, -_t22 + (0.1e1 / 0.3e1)*_t23*_t24*_t4*_t5*_t6*_t7*p->cam_omega);
  out[14] = d3f_drs_dx2;
  const double d3f_drs_dz_dx = my_piecewise3(_t13, 0, _t28);
  out[15] = d3f_drs_dz_dx;
  const double d3f_drs_dz2 = my_piecewise3(_t13, 0, -_t30 + _t35);
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dx = 0;
  out[17] = d3f_drs2_dx;
  const double d3f_drs2_dz = 0;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = 0;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = my_piecewise3(_t13, 0, (0.4e1 / 0.3e1)*_hc1[1]*_hc1[3]*_t52 + ((_hc1[2]) * (_hc1[2]))*_t52 - _hc1[4]*_t15*rs - 0.6e1*_t24*_t37*_t54*_t9 + ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t53*_t9/xc_powi((_hc1[0]), 5));
  out[20] = d4f_dx4;
  const double d4f_dz_dx3 = my_piecewise3(_t13, 0, -_hc1[1]*_hc1[2]*_t23*_t43 + _hc1[3]*_t40*rs + _t38*_t43);
  out[21] = d4f_dz_dx3;
  const double d4f_dz2_dx2 = my_piecewise3(_t13, 0, (0.1e1 / 0.6e1)*_hc0[5]*_hc1[2]*_t14*_t19*_t5*_t6*_t7*p->cam_omega*rs - _hc0[5]*_t19*_t44*_t8*rs - _t14*_t47*_t54*_t8 + (0.2e1 / 0.3e1)*_t23*_t24*_t31*_t33*_t5*_t6*_t7*p->cam_omega*rs);
  out[22] = d4f_dz2_dx2;
  const double d4f_dz3_dx = my_piecewise3(_t13, 0, -_hc0[5]*_t25*_t26*_t31*rs + _hc0[9]*_t20*_t46 + _t46*_t50);
  out[23] = d4f_dz3_dx;
  const double d4f_dz4 = my_piecewise3(_t13, 0, -_hc0[14]*_t29*rs + ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t17*_t53/xc_powi(_t3, 5) + ((_hc0[5]) * (_hc0[5]))*_t32*rs - 0.6e1*_hc0[5]*_t17*_t33*_t49*rs + (0.4e1 / 0.3e1)*_hc0[9]*_t18*_t31*rs);
  out[24] = d4f_dz4;
  const double d4f_drs_dx3 = my_piecewise3(_t13, 0, _hc1[1]*_hc1[2]*_t23*_t4*_t5*_t6*_t7*p->cam_omega - _t36 - _t39);
  out[25] = d4f_drs_dx3;
  const double d4f_drs_dz_dx2 = my_piecewise3(_t13, 0, _t41 - _t42*_t44);
  out[26] = d4f_drs_dz_dx2;
  const double d4f_drs_dz2_dx = my_piecewise3(_t13, 0, (0.1e1 / 0.6e1)*_hc0[5]*_hc1[1]*_t14*_t19*_t5*_t6*_t7*p->cam_omega - _t45*_t47);
  out[27] = d4f_drs_dz2_dx;
  const double d4f_drs_dz3 = my_piecewise3(_t13, 0, _hc0[2]*_hc0[5]*_t2*_t31*_t5*_t6*_t7*p->cam_omega - _t48 - _t51);
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dx2 = 0;
  out[29] = d4f_drs2_dx2;
  const double d4f_drs2_dz_dx = 0;
  out[30] = d4f_drs2_dz_dx;
  const double d4f_drs2_dz2 = 0;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dx = 0;
  out[32] = d4f_drs3_dx;
  const double d4f_drs3_dz = 0;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = 0;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(js18_DME_SR_k, _KMAX)(const xc_func_type *p, double rs, double z, double x, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_f0_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(js18_A_k, _KMAX)(p, rs, z, x, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_k, _KMAX)(p, _hc1[0], _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_f2_k, _KMAX)(p, _hc1[0], _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(js18_G_k, _KMAX)(p, x, t, _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_f3_k, _KMAX)(p, _hc1[0], _hc5);
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(js18_H_k, _KMAX)(p, x, _hc6);
  const double _t1 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t2 = _hc3[0]*_hc4[0];
  const double _t3 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t4 = (0.7e1 / 0.9e1)*_t3;
  const double _t5 = _hc5[0]*_hc6[0];
  const double _t6 = (0.245e3 / 0.54e2)*_t3;
#if _KMAX >= 1
  const double _t7 = _hc3[0]*_t4;
  const double _t8 = _hc2[1]*_t1;
  const double _t9 = _hc5[0]*_t6;
  const double _t10 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t11 = _hc0[1]*_t10;
  const double _t12 = 0.2e1*_hc2[0];
  const double _t13 = xc_powi((_hc0[0]), -5);
  const double _t14 = _hc0[1]*_t13;
  const double _t15 = (0.28e2 / 0.9e1)*_t14;
  const double _t16 = (0.490e3 / 0.27e2)*_t5;
  const double _t17 = _hc4[0]*_t4;
  const double _t18 = _hc1[1]*_hc3[1];
  const double _t19 = _hc1[1]*_hc5[1];
  const double _t20 = _hc6[0]*_t6;
  const double _t21 = _hc3[1]*_t17;
  const double _t22 = _hc5[1]*_t20;
#endif
#if _KMAX >= 2
  const double _t23 = _hc3[0]*_hc4[1];
  const double _t24 = _hc4[1]*_t4;
  const double _t25 = _t10*_t12;
  const double _t26 = ((_hc1[1]) * (_hc1[1]));
  const double _t27 = _hc2[2]*_t1;
  const double _t28 = _hc3[0]*_t14;
  const double _t29 = (0.56e2 / 0.9e1)*_hc4[2];
  const double _t30 = _hc5[0]*_t14;
  const double _t31 = (0.980e3 / 0.27e2)*_hc6[1];
  const double _t32 = _hc0[2]*_t13;
  const double _t33 = (0.28e2 / 0.9e1)*_t32;
  const double _t34 = _t18*_t3;
  const double _t35 = (0.14e2 / 0.9e1)*_hc4[2];
  const double _t36 = _t19*_t3;
  const double _t37 = (0.245e3 / 0.27e2)*_hc6[1];
  const double _t38 = _hc2[1]*_t11;
  const double _t39 = 0.4e1*_hc1[1];
  const double _t40 = _hc2[0]*_t3;
  const double _t41 = ((_hc0[1]) * (_hc0[1]));
  const double _t42 = 0.6e1*_t41;
  const double _t43 = _t14*_t18;
  const double _t44 = (0.56e2 / 0.9e1)*_t43;
  const double _t45 = _hc6[0]*_t14;
  const double _t46 = (0.980e3 / 0.27e2)*_t45;
  const double _t47 = xc_powi((_hc0[0]), -6);
  const double _t48 = _t41*_t47;
  const double _t49 = (0.140e3 / 0.9e1)*_t48;
  const double _t50 = (0.2450e4 / 0.27e2)*_t48;
  const double _t51 = _hc3[2]*_t17;
  const double _t52 = _hc5[2]*_t20;
  const double _t53 = _hc1[2]*_hc3[1];
  const double _t54 = _hc1[1]*_t27;
  const double _t55 = _hc4[2]*_t4;
  const double _t56 = _hc5[1]*_hc6[1];
  const double _t57 = _hc1[2]*_t6;
  const double _t58 = 0.2e1*_t38;
  const double _t59 = _hc4[0]*_t15;
  const double _t60 = _hc5[1]*_t45;
  const double _t61 = (0.490e3 / 0.27e2)*_hc1[2];
  const double _t62 = _hc1[1]*_hc1[2];
  const double _t63 = ((_hc1[2]) * (_hc1[2]));
  const double _t64 = _hc1[3]*_hc3[1];
  const double _t65 = _t56*_t6;
  const double _t66 = (0.490e3 / 0.27e2)*_t60;
  const double _t67 = _hc1[1]*_hc1[3];
  const double _t68 = _hc1[2]*_t27;
  const double _t69 = _hc1[2]*_hc1[3];
  const double _t70 = ((_hc1[3]) * (_hc1[3]));
#endif
#if _KMAX >= 3
  const double _t71 = _hc1[4]*_hc3[1];
  const double _t72 = _hc3[2]*_t26;
  const double _t73 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t74 = _hc2[3]*_t1;
  const double _t75 = (0.28e2 / 0.3e1)*_hc4[5];
  const double _t76 = (0.490e3 / 0.9e1)*_hc6[2];
  const double _t77 = _hc3[0]*_hc4[2];
  const double _t78 = (0.28e2 / 0.3e1)*_t32;
  const double _t79 = _hc5[0]*_hc6[1];
  const double _t80 = (0.490e3 / 0.9e1)*_t32;
  const double _t81 = _hc0[3]*_t13;
  const double _t82 = (0.28e2 / 0.9e1)*_t81;
  const double _t83 = 0.18e2*_t40;
  const double _t84 = _hc0[1]*_hc0[2];
  const double _t85 = (0.7e1 / 0.3e1)*_hc4[5];
  const double _t86 = (0.245e3 / 0.18e2)*_hc6[2];
  const double _t87 = (0.7e1 / 0.3e1)*_t3;
  const double _t88 = _hc4[2]*_t71;
  const double _t89 = (0.245e3 / 0.18e2)*_t3;
  const double _t90 = _hc1[4]*_t56;
  const double _t91 = 0.6e1*_hc1[4];
  const double _t92 = _hc1[1]*_hc2[1];
  const double _t93 = _hc0[2]*_t10;
  const double _t94 = 0.6e1*_t93;
  const double _t95 = 0.3e1*_t54;
  const double _t96 = _hc2[0]*_t13;
  const double _t97 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t98 = 0.24e2*_t97;
  const double _t99 = (0.140e3 / 0.3e1)*_t2;
  const double _t100 = _t47*_t84;
  const double _t101 = (0.2450e4 / 0.9e1)*_t5;
  const double _t102 = (0.56e2 / 0.3e1)*_hc4[2];
  const double _t103 = _t14*_t19;
  const double _t104 = _hc4[0]*_t14;
  const double _t105 = (0.28e2 / 0.3e1)*_t104;
  const double _t106 = (0.490e3 / 0.9e1)*_hc1[4];
  const double _t107 = _hc4[0]*_t18;
  const double _t108 = _hc6[0]*_t19;
  const double _t109 = _hc3[2]*_hc4[0];
  const double _t110 = _t109*_t87;
  const double _t111 = _hc1[1]*_hc1[4];
  const double _t112 = _hc5[2]*_hc6[0];
  const double _t113 = _t112*_t89;
  const double _t114 = xc_powi((_hc0[0]), -7);
  const double _t115 = _t114*_t97;
  const double _t116 = (0.280e3 / 0.3e1)*_t115;
  const double _t117 = (0.4900e4 / 0.9e1)*_t115;
  const double _t118 = (0.140e3 / 0.3e1)*_t48;
  const double _t119 = (0.2450e4 / 0.9e1)*_t48;
  const double _t120 = _t3*_t41;
  const double _t121 = 0.18e2*_t120;
  const double _t122 = _hc4[2]*_t87;
  const double _t123 = _hc5[2]*_hc6[1];
  const double _t124 = _t26*_t89;
  const double _t125 = _hc3[3]*_t17;
  const double _t126 = _hc5[3]*_t20;
  const double _t127 = _hc2[2]*_t11;
  const double _t128 = 0.6e1*_t26;
  const double _t129 = _t112*_t14;
  const double _t130 = (0.490e3 / 0.9e1)*_t26;
  const double _t131 = _hc1[5]*_hc3[1];
  const double _t132 = _hc4[1]*_t15;
  const double _t133 = _hc3[2]*_t62;
  const double _t134 = _hc4[5]*_t4;
  const double _t135 = _hc5[1]*_hc6[2];
  const double _t136 = _t3*_t35;
  const double _t137 = _hc5[1]*_t3;
  const double _t138 = _t137*_t37;
  const double _t139 = 0.4e1*_t38;
  const double _t140 = _hc1[2]*_hc2[1];
  const double _t141 = 0.2e1*_t93;
  const double _t142 = 0.2e1*_hc1[5];
  const double _t143 = _t26*_t74;
  const double _t144 = _t14*_t29;
  const double _t145 = _hc1[2]*_hc5[1];
  const double _t146 = _t14*_t31;
  const double _t147 = (0.56e2 / 0.9e1)*_t104;
  const double _t148 = _hc5[1]*_t46;
  const double _t149 = _hc4[0]*_t53;
  const double _t150 = _hc5[1]*_hc6[0];
  const double _t151 = _t150*_t32;
  const double _t152 = _hc5[2]*_t3;
  const double _t153 = _t152*_t37;
  const double _t154 = _t109*_t3;
  const double _t155 = (0.14e2 / 0.9e1)*_t154;
  const double _t156 = _hc1[1]*_hc1[5];
  const double _t157 = _hc6[0]*_t152;
  const double _t158 = (0.245e3 / 0.27e2)*_t157;
  const double _t159 = _hc1[2]*_hc1[4];
  const double _t160 = _t127*_t39;
  const double _t161 = _t3*_t42;
  const double _t162 = _t109*_t14;
  const double _t163 = (0.56e2 / 0.9e1)*_t162;
  const double _t164 = (0.980e3 / 0.27e2)*_t129;
  const double _t165 = _hc6[0]*_t145;
  const double _t166 = _hc1[2]*_t26;
  const double _t167 = _hc1[6]*_hc3[1];
  const double _t168 = _hc3[2]*_t63;
  const double _t169 = _t63*_t74;
  const double _t170 = _hc1[1]*_hc1[6];
  const double _t171 = _hc1[2]*_hc1[5];
  const double _t172 = _t123*_t6;
  const double _t173 = 0.2e1*_t127;
  const double _t174 = (0.490e3 / 0.27e2)*_t129;
  const double _t175 = _hc1[1]*_t63;
  const double _t176 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t177 = 0.3e1*_t68;
  const double _t178 = _hc1[2]*_hc1[6];
  const double _t179 = _hc1[7]*_hc3[1];
  const double _t180 = _hc3[2]*_t67;
  const double _t181 = _hc1[3]*_t27;
  const double _t182 = _t135*_t6;
  const double _t183 = _hc1[3]*_hc2[1];
  const double _t184 = 0.2e1*_hc1[7];
  const double _t185 = _hc5[1]*_t146;
  const double _t186 = _hc4[0]*_t64;
  const double _t187 = (0.490e3 / 0.27e2)*_t151;
  const double _t188 = _hc1[1]*_hc1[7];
  const double _t189 = _hc1[3]*_hc1[4];
  const double _t190 = _t150*_t50;
  const double _t191 = _hc1[3]*_t26;
  const double _t192 = _hc1[8]*_hc3[1];
  const double _t193 = _hc3[2]*_t69;
  const double _t194 = _t69*_t74;
  const double _t195 = _hc1[1]*_hc1[8];
  const double _t196 = _hc1[3]*_t57;
  const double _t197 = _hc1[2]*_hc1[7];
  const double _t198 = _hc1[3]*_hc1[5];
  const double _t199 = _t109*_t69;
  const double _t200 = _hc1[1]*_t69;
  const double _t201 = 0.2e1*_hc1[8];
  const double _t202 = _hc1[2]*_hc1[8];
  const double _t203 = _hc1[3]*_hc1[6];
  const double _t204 = _hc1[3]*_t63;
  const double _t205 = _hc3[2]*_t70;
  const double _t206 = _t70*_t74;
  const double _t207 = _hc1[3]*_hc1[7];
  const double _t208 = _hc1[1]*_t70;
  const double _t209 = _hc1[3]*_hc1[8];
  const double _t210 = _hc1[2]*_t70;
  const double _t211 = ((_hc1[3]) * (_hc1[3]) * (_hc1[3]));
#endif
#if _KMAX >= 4
  const double _t212 = _hc1[10]*_hc3[1];
  const double _t213 = (0.140e3 / 0.3e1)*_t100;
  const double _t214 = _hc4[1]*_t14;
  const double _t215 = (0.28e2 / 0.3e1)*_t214;
  const double _t216 = _hc4[1]*_t18;
  const double _t217 = _hc3[2]*_t111;
  const double _t218 = _hc4[1]*_t87;
  const double _t219 = _hc3[3]*_t73;
  const double _t220 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t221 = _hc2[4]*_t1;
  const double _t222 = _hc3[0]*_hc4[5];
  const double _t223 = (0.56e2 / 0.3e1)*_t32;
  const double _t224 = _hc5[0]*_hc6[2];
  const double _t225 = (0.980e3 / 0.9e1)*_t32;
  const double _t226 = (0.112e3 / 0.9e1)*_t81;
  const double _t227 = (0.1960e4 / 0.27e2)*_t81;
  const double _t228 = _hc0[4]*_t13;
  const double _t229 = _hc0[1]*_hc0[3];
  const double _t230 = _hc4[2]*_t3;
  const double _t231 = (0.28e2 / 0.9e1)*_t230;
  const double _t232 = (0.490e3 / 0.27e2)*_t3;
  const double _t233 = (0.14e2 / 0.3e1)*_t3;
  const double _t234 = _hc4[5]*_t233;
  const double _t235 = (0.245e3 / 0.9e1)*_hc6[2];
  const double _t236 = 0.12e2*_t93;
  const double _t237 = _hc1[4]*_hc2[1];
  const double _t238 = _hc0[3]*_t10;
  const double _t239 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t240 = ((_hc0[2]) * (_hc0[2]));
  const double _t241 = ((_hc1[4]) * (_hc1[4]));
  const double _t242 = 0.3e1*_t27;
  const double _t243 = (0.560e3 / 0.3e1)*_t100;
  const double _t244 = (0.9800e4 / 0.9e1)*_t100;
  const double _t245 = _t229*_t47;
  const double _t246 = (0.112e3 / 0.9e1)*_t104;
  const double _t247 = (0.112e3 / 0.3e1)*_t14;
  const double _t248 = (0.1960e4 / 0.9e1)*_t14;
  const double _t249 = _hc4[2]*_t18;
  const double _t250 = _hc6[1]*_t19;
  const double _t251 = _hc4[0]*_t223;
  const double _t252 = _hc1[4]*_t150;
  const double _t253 = _t3*_t84;
  const double _t254 = _hc1[1]*_hc1[10];
  const double _t255 = (0.28e2 / 0.9e1)*_t154;
  const double _t256 = _hc1[1]*_t3;
  const double _t257 = _t239/xc_powi((_hc0[0]), 8);
  const double _t258 = (0.1120e4 / 0.3e1)*_t115;
  const double _t259 = (0.19600e5 / 0.9e1)*_t115;
  const double _t260 = (0.280e3 / 0.3e1)*_t48;
  const double _t261 = (0.4900e4 / 0.9e1)*_t48;
  const double _t262 = _t240*_t47;
  const double _t263 = _hc0[2]*_t41;
  const double _t264 = 0.36e2*_t120;
  const double _t265 = _hc5[3]*_hc6[1];
  const double _t266 = _hc3[4]*_t17;
  const double _t267 = _hc5[4]*_t20;
  const double _t268 = _hc2[3]*_t11;
  const double _t269 = _hc2[2]*_t26;
  const double _t270 = _t114*_t263;
  const double _t271 = _hc4[0]*_t260;
  const double _t272 = _hc5[3]*_t45;
  const double _t273 = _t112*_t26;
  const double _t274 = _hc1[4]*_t26;
  const double _t275 = _hc3[3]*_hc4[0];
  const double _t276 = _t233*_t275;
  const double _t277 = (0.245e3 / 0.9e1)*_t3;
  const double _t278 = _hc5[3]*_hc6[0];
  const double _t279 = _t277*_t278;
  const double _t280 = _hc1[11]*_hc3[1];
  const double _t281 = (0.56e2 / 0.9e1)*_t214;
  const double _t282 = _hc4[1]*_t53;
  const double _t283 = _hc3[2]*_t156;
  const double _t284 = (0.14e2 / 0.9e1)*_t3;
  const double _t285 = _hc4[1]*_t284;
  const double _t286 = _hc3[2]*_t159;
  const double _t287 = _hc3[3]*_t166;
  const double _t288 = _t56*_t89;
  const double _t289 = _hc5[1]*_hc6[3];
  const double _t290 = _t3*_t85;
  const double _t291 = _t137*_t86;
  const double _t292 = 0.6e1*_t38;
  const double _t293 = _hc1[5]*_hc2[1];
  const double _t294 = 0.2e1*_t238;
  const double _t295 = _hc1[5]*_t242;
  const double _t296 = _t221*_t73;
  const double _t297 = (0.490e3 / 0.9e1)*_t60;
  const double _t298 = _t14*_t75;
  const double _t299 = _t14*_t76;
  const double _t300 = _t102*_t14;
  const double _t301 = (0.980e3 / 0.9e1)*_t14;
  const double _t302 = _t301*_t56;
  const double _t303 = _hc4[2]*_t53;
  const double _t304 = _hc1[2]*_t56;
  const double _t305 = _hc4[0]*_t131;
  const double _t306 = _hc1[5]*_t150;
  const double _t307 = _t150*_t81;
  const double _t308 = 0.18e2*_t253;
  const double _t309 = _hc1[1]*_hc1[11];
  const double _t310 = _t152*_t86;
  const double _t311 = _hc4[2]*_t233;
  const double _t312 = _t123*_t277;
  const double _t313 = _hc1[10]*_hc1[2];
  const double _t314 = _t123*_t89;
  const double _t315 = _hc1[4]*_hc1[5];
  const double _t316 = 0.12e2*_t127;
  const double _t317 = _hc1[2]*_t127;
  const double _t318 = _hc2[2]*_t62;
  const double _t319 = 0.3e1*_t62;
  const double _t320 = _hc1[4]*_t74;
  const double _t321 = _t13*_t98;
  const double _t322 = 0.3e1*_hc1[5];
  const double _t323 = (0.2450e4 / 0.9e1)*_t100;
  const double _t324 = _t123*_t301;
  const double _t325 = (0.56e2 / 0.3e1)*_t162;
  const double _t326 = (0.980e3 / 0.9e1)*_t129;
  const double _t327 = (0.28e2 / 0.3e1)*_t162;
  const double _t328 = _t106*_t129;
  const double _t329 = _t109*_t62;
  const double _t330 = _t112*_t62;
  const double _t331 = _t275*_t87;
  const double _t332 = _hc1[4]*_t62;
  const double _t333 = _t278*_t89;
  const double _t334 = _t124*_t265;
  const double _t335 = _hc1[5]*_t331;
  const double _t336 = _hc1[5]*_t278;
  const double _t337 = _hc1[2]*_t73;
  const double _t338 = _t128*_t268;
  const double _t339 = _t130*_t272;
  const double _t340 = _hc1[12]*_hc3[1];
  const double _t341 = _hc3[2]*_t170;
  const double _t342 = _hc3[2]*_t171;
  const double _t343 = _hc3[3]*_t175;
  const double _t344 = _hc1[4]*_t27;
  const double _t345 = _hc1[6]*_hc2[1];
  const double _t346 = 0.2e1*_t54;
  const double _t347 = 0.2e1*_t68;
  const double _t348 = ((_hc1[5]) * (_hc1[5]));
  const double _t349 = 0.2e1*_t27;
  const double _t350 = _hc4[0]*_t33;
  const double _t351 = _hc1[1]*_hc1[12];
  const double _t352 = _hc1[11]*_hc1[2];
  const double _t353 = _t123*_t232;
  const double _t354 = _hc1[4]*_hc1[6];
  const double _t355 = 0.8e1*_t127;
  const double _t356 = _t39*_t74;
  const double _t357 = _hc5[2]*_t63;
  const double _t358 = _hc6[2]*_t6;
  const double _t359 = _hc2[2]*_t63;
  const double _t360 = (0.112e3 / 0.9e1)*_t162;
  const double _t361 = (0.1960e4 / 0.27e2)*_t129;
  const double _t362 = _t275*_t62;
  const double _t363 = (0.28e2 / 0.9e1)*_t3;
  const double _t364 = _t221*_t26;
  const double _t365 = _hc4[0]*_t49;
  const double _t366 = _t112*_t63;
  const double _t367 = (0.490e3 / 0.27e2)*_t32;
  const double _t368 = _hc5[3]*_t175;
  const double _t369 = _t3*_t37;
  const double _t370 = _hc1[6]*_t26;
  const double _t371 = _hc1[4]*_t63;
  const double _t372 = _t268*_t39;
  const double _t373 = _t26*_t63;
  const double _t374 = _hc1[13]*_hc3[1];
  const double _t375 = _hc3[2]*_t178;
  const double _t376 = _hc3[3]*_t176;
  const double _t377 = _t176*_t221;
  const double _t378 = _hc1[1]*_hc1[13];
  const double _t379 = _hc1[12]*_hc1[2];
  const double _t380 = _hc1[5]*_hc1[6];
  const double _t381 = 0.6e1*_hc1[6];
  const double _t382 = _hc1[6]*_t74;
  const double _t383 = _t265*_t6;
  const double _t384 = 0.2e1*_t268;
  const double _t385 = _hc1[6]*_t62;
  const double _t386 = (0.490e3 / 0.27e2)*_t272;
  const double _t387 = _hc1[1]*_t176;
  const double _t388 = _t63*_t89;
  const double _t389 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t390 = ((_hc1[6]) * (_hc1[6]));
  const double _t391 = _hc1[6]*_t63;
  const double _t392 = _hc1[14]*_hc3[1];
  const double _t393 = _hc4[1]*_t64;
  const double _t394 = _hc3[2]*_t188;
  const double _t395 = _hc3[2]*_t189;
  const double _t396 = _hc3[3]*_t191;
  const double _t397 = _hc1[7]*_hc2[1];
  const double _t398 = _hc1[4]*_hc1[7];
  const double _t399 = _hc4[2]*_t64;
  const double _t400 = _hc1[3]*_t56;
  const double _t401 = _hc4[0]*_t179;
  const double _t402 = _hc1[7]*_t150;
  const double _t403 = _hc1[1]*_hc1[14];
  const double _t404 = _hc1[10]*_hc1[3];
  const double _t405 = _hc2[2]*_t67;
  const double _t406 = 0.3e1*_hc1[7];
  const double _t407 = _hc1[3]*_t150;
  const double _t408 = _t109*_t67;
  const double _t409 = _t112*_t67;
  const double _t410 = _hc1[4]*_t67;
  const double _t411 = _hc1[7]*_t331;
  const double _t412 = _hc1[7]*_t278;
  const double _t413 = _hc1[3]*_t73;
  const double _t414 = _hc1[15]*_hc3[1];
  const double _t415 = _hc3[2]*_t24;
  const double _t416 = _hc3[3]*_t200;
  const double _t417 = _hc1[8]*_hc2[1];
  const double _t418 = _hc1[5]*_t349;
  const double _t419 = _hc1[1]*_hc1[15];
  const double _t420 = _hc3[2]*_t136;
  const double _t421 = _hc1[11]*_hc1[3];
  const double _t422 = _hc1[14]*_hc1[2];
  const double _t423 = _hc1[4]*_hc1[8];
  const double _t424 = _hc1[5]*_hc1[7];
  const double _t425 = 0.4e1*_t127;
  const double _t426 = _hc2[2]*_t69;
  const double _t427 = _t62*_t74;
  const double _t428 = _t67*_t74;
  const double _t429 = _t112*_t69;
  const double _t430 = _t284*_t362;
  const double _t431 = (0.245e3 / 0.27e2)*_t3;
  const double _t432 = _t431*_t62;
  const double _t433 = _t275*_t67;
  const double _t434 = _hc1[5]*_t284;
  const double _t435 = _t336*_t431;
  const double _t436 = _hc1[4]*_t69;
  const double _t437 = _hc1[8]*_t26;
  const double _t438 = _t26*_t69;
  const double _t439 = _hc1[16]*_hc3[1];
  const double _t440 = _hc3[2]*_t285;
  const double _t441 = _hc3[3]*_t204;
  const double _t442 = _hc1[6]*_hc1[7];
  const double _t443 = _hc1[1]*_hc1[16];
  const double _t444 = _hc1[12]*_hc1[3];
  const double _t445 = _hc1[15]*_hc1[2];
  const double _t446 = _hc1[5]*_hc1[8];
  const double _t447 = _t221*_t63;
  const double _t448 = _hc1[8]*_t278;
  const double _t449 = _hc1[6]*_t67;
  const double _t450 = _t275*_t69;
  const double _t451 = _hc1[7]*_t63;
  const double _t452 = _t63*_t67;
  const double _t453 = _hc1[6]*_hc1[8];
  const double _t454 = _hc1[13]*_hc1[3];
  const double _t455 = _hc1[16]*_hc1[2];
  const double _t456 = 0.3e1*_hc1[8];
  const double _t457 = _hc1[6]*_t69;
  const double _t458 = _hc1[8]*_t331;
  const double _t459 = _hc1[3]*_t176;
  const double _t460 = _hc3[3]*_t208;
  const double _t461 = 0.2e1*_t181;
  const double _t462 = ((_hc1[7]) * (_hc1[7]));
  const double _t463 = _hc1[14]*_hc1[3];
  const double _t464 = _hc5[2]*_t70;
  const double _t465 = _hc2[2]*_t70;
  const double _t466 = _t112*_t70;
  const double _t467 = _hc5[3]*_t208;
  const double _t468 = _hc1[4]*_t70;
  const double _t469 = _t26*_t70;
  const double _t470 = _hc3[3]*_t210;
  const double _t471 = _hc1[7]*_hc1[8];
  const double _t472 = _hc1[15]*_hc1[3];
  const double _t473 = _t62*_t70;
  const double _t474 = _hc1[5]*_t70;
  const double _t475 = ((_hc1[8]) * (_hc1[8]));
  const double _t476 = _hc1[16]*_hc1[3];
  const double _t477 = _hc1[6]*_t70;
  const double _t478 = _t63*_t70;
  const double _t479 = _hc3[3]*_t211;
  const double _t480 = _t211*_t221;
  const double _t481 = _hc1[1]*_t211;
  const double _t482 = _t70*_t89;
  const double _t483 = _hc1[2]*_t211;
  const double _t484 = ((_hc1[3]) * (_hc1[3]) * (_hc1[3]) * (_hc1[3]));
#endif

  const double f = _hc2[0]*_t1 + _t2*_t4 + _t5*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc4[1]*_t7;
  out[1] = df_dt;
  const double df_dx = _hc1[1]*_t8 + _hc4[2]*_t7 + _hc6[1]*_t9 - _t11*_t12 - _t14*_t16 - _t15*_t2 + _t17*_t18 + _t19*_t20;
  out[2] = df_dx;
  const double df_dz = _hc1[2]*_t21 + _hc1[2]*_t22 + _hc1[2]*_t8;
  out[3] = df_dz;
  const double df_drs = _hc1[3]*_t21 + _hc1[3]*_t22 + _hc1[3]*_t8;
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[5] = d2f_dt2;
  const double d2f_dx_dt = -_t15*_t23 + _t18*_t24;
  out[6] = d2f_dx_dt;
  const double d2f_dx2 = -_hc0[2]*_t25 + _hc1[4]*_t21 + _hc1[4]*_t22 + _hc1[4]*_t8 - _hc4[0]*_t44 + _hc4[5]*_t7 + _hc6[2]*_t9 - _t16*_t32 - _t19*_t46 - _t2*_t33 + _t2*_t49 + _t26*_t27 + _t26*_t51 + _t26*_t52 - _t28*_t29 - _t30*_t31 + _t34*_t35 + _t36*_t37 - _t38*_t39 + _t40*_t42 + _t5*_t50;
  out[7] = d2f_dx2;
  const double d2f_dz_dt = _t24*_t53;
  out[8] = d2f_dz_dt;
  const double d2f_dz_dx = _hc1[2]*_t54 - _hc1[2]*_t58 + _hc1[5]*_t21 + _hc1[5]*_t22 + _hc1[5]*_t8 + _t51*_t62 + _t52*_t62 + _t53*_t55 - _t53*_t59 + _t56*_t57 - _t60*_t61;
  out[9] = d2f_dz_dx;
  const double d2f_dz2 = _hc1[6]*_t21 + _hc1[6]*_t22 + _hc1[6]*_t8 + _t27*_t63 + _t51*_t63 + _t52*_t63;
  out[10] = d2f_dz2;
  const double d2f_drs_dt = _t24*_t64;
  out[11] = d2f_drs_dt;
  const double d2f_drs_dx = _hc1[3]*_t54 - _hc1[3]*_t58 + _hc1[3]*_t65 - _hc1[3]*_t66 + _hc1[7]*_t21 + _hc1[7]*_t22 + _hc1[7]*_t8 + _t51*_t67 + _t52*_t67 + _t55*_t64 - _t59*_t64;
  out[12] = d2f_drs_dx;
  const double d2f_drs_dz = _hc1[3]*_t68 + _hc1[8]*_t21 + _hc1[8]*_t22 + _hc1[8]*_t8 + _t51*_t69 + _t52*_t69;
  out[13] = d2f_drs_dz;
  const double d2f_drs2 = _t27*_t70 + _t51*_t70 + _t52*_t70;
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[15] = d3f_dt3;
  const double d3f_dx_dt2 = 0;
  out[16] = d3f_dx_dt2;
  const double d3f_dx2_dt = -_hc4[1]*_t44 - _t23*_t33 + _t23*_t49 + _t24*_t71 + _t24*_t72;
  out[17] = d3f_dx2_dt;
  const double d3f_dx3 = -_hc0[3]*_t25 + _hc1[10]*_t21 + _hc1[10]*_t22 + _hc1[10]*_t8 + _hc1[4]*_t95 - 0.980e3 / 0.9e1*_hc6[1]*_t103 + _hc6[3]*_t9 + _t100*_t101 + _t100*_t99 - _t102*_t43 - _t105*_t71 - _t105*_t72 - _t106*_t60 + _t107*_t118 - _t107*_t78 + _t108*_t119 - _t108*_t80 + _t110*_t111 + _t111*_t113 - _t116*_t2 - _t117*_t5 + _t118*_t77 + _t119*_t79 + _t121*_t92 + _t122*_t72 + _t123*_t124 + _t125*_t73 + _t126*_t73 - _t127*_t128 - _t129*_t130 - _t16*_t81 - _t2*_t82 - _t28*_t75 - _t30*_t76 + _t34*_t85 + _t36*_t86 - _t38*_t91 + _t73*_t74 - _t77*_t78 - _t79*_t80 + _t83*_t84 + _t87*_t88 + _t89*_t90 - _t92*_t94 - _t96*_t98;
  out[18] = d3f_dx3;
  const double d3f_dz_dt2 = 0;
  out[19] = d3f_dz_dt2;
  const double d3f_dz_dx_dt = _t131*_t24 - _t132*_t53 + _t133*_t24;
  out[20] = d3f_dz_dx_dt;
  const double d3f_dz_dx2 = _hc1[11]*_t21 + _hc1[11]*_t22 + _hc1[11]*_t8 + _hc1[2]*_t143 - _hc1[2]*_t160 + _hc1[4]*_t68 + _hc1[5]*_t138 - _hc1[5]*_t139 - _hc1[5]*_t148 + _t125*_t166 + _t126*_t166 + _t131*_t136 - _t131*_t147 + _t133*_t136 + _t134*_t53 + _t135*_t57 - _t140*_t141 + _t140*_t161 + _t142*_t54 - _t144*_t53 - _t145*_t146 - _t149*_t33 + _t149*_t49 - _t151*_t61 + _t153*_t62 + _t155*_t156 + _t156*_t158 + _t159*_t51 + _t159*_t52 - _t163*_t62 - _t164*_t62 + _t165*_t50;
  out[21] = d3f_dz_dx2;
  const double d3f_dz2_dt = _t167*_t24 + _t168*_t24;
  out[22] = d3f_dz2_dt;
  const double d3f_dz2_dx = _hc1[1]*_t169 + _hc1[12]*_t21 + _hc1[12]*_t22 + _hc1[12]*_t8 + _hc1[6]*_t54 - _hc1[6]*_t58 + _hc1[6]*_t65 - _hc1[6]*_t66 + _t125*_t175 + _t126*_t175 + _t142*_t68 + _t155*_t171 + _t158*_t171 + _t167*_t55 - _t167*_t59 + _t168*_t55 - _t168*_t59 + _t170*_t51 + _t170*_t52 + _t172*_t63 - _t173*_t63 - _t174*_t63;
  out[23] = d3f_dz2_dx;
  const double d3f_dz3 = _hc1[13]*_t21 + _hc1[13]*_t22 + _hc1[13]*_t8 + _hc1[6]*_t177 + _t110*_t178 + _t113*_t178 + _t125*_t176 + _t126*_t176 + _t176*_t74;
  out[24] = d3f_dz3;
  const double d3f_drs_dt2 = 0;
  out[25] = d3f_drs_dt2;
  const double d3f_drs_dx_dt = -_t132*_t64 + _t179*_t24 + _t180*_t24;
  out[26] = d3f_drs_dx_dt;
  const double d3f_drs_dx2 = _hc1[14]*_t21 + _hc1[14]*_t22 + _hc1[14]*_t8 + _hc1[3]*_t143 - _hc1[3]*_t160 + _hc1[3]*_t182 - _hc1[3]*_t185 - _hc1[3]*_t187 + _hc1[3]*_t190 + _hc1[4]*_t181 + _hc1[7]*_t138 - _hc1[7]*_t139 - _hc1[7]*_t148 + _t125*_t191 + _t126*_t191 + _t134*_t64 + _t136*_t179 + _t136*_t180 - _t141*_t183 - _t144*_t64 - _t147*_t179 + _t153*_t67 + _t155*_t188 + _t158*_t188 + _t161*_t183 - _t163*_t67 - _t164*_t67 + _t184*_t54 - _t186*_t33 + _t186*_t49 + _t189*_t51 + _t189*_t52;
  out[27] = d3f_drs_dx2;
  const double d3f_drs_dz_dt = _t192*_t24 + _t193*_t24;
  out[28] = d3f_drs_dz_dt;
  const double d3f_drs_dz_dx = _hc1[1]*_t194 + _hc1[15]*_t21 + _hc1[15]*_t22 + _hc1[15]*_t8 + _hc1[5]*_t181 + _hc1[7]*_t68 + _hc1[8]*_t54 - _hc1[8]*_t58 + _hc1[8]*_t65 - _hc1[8]*_t66 + _t123*_t196 + _t125*_t200 + _t126*_t200 - _t15*_t199 - _t173*_t69 - _t174*_t69 + _t192*_t55 - _t192*_t59 + _t193*_t55 + _t195*_t51 + _t195*_t52 + _t197*_t51 + _t197*_t52 + _t198*_t51 + _t198*_t52;
  out[29] = d3f_drs_dz_dx;
  const double d3f_drs_dz2 = _hc1[16]*_t21 + _hc1[16]*_t22 + _hc1[16]*_t8 + _hc1[3]*_t169 + _hc1[6]*_t181 + _t125*_t204 + _t126*_t204 + _t155*_t202 + _t158*_t202 + _t201*_t68 + _t203*_t51 + _t203*_t52;
  out[30] = d3f_drs_dz2;
  const double d3f_drs2_dt = _t205*_t24;
  out[31] = d3f_drs2_dt;
  const double d3f_drs2_dx = _hc1[1]*_t206 + _t125*_t208 + _t126*_t208 + _t155*_t207 + _t158*_t207 + _t172*_t70 - _t173*_t70 - _t174*_t70 + _t181*_t184 + _t205*_t55 - _t205*_t59;
  out[32] = d3f_drs2_dx;
  const double d3f_drs2_dz = _hc1[2]*_t206 + _t125*_t210 + _t126*_t210 + _t155*_t209 + _t158*_t209 + _t181*_t201;
  out[33] = d3f_drs2_dz;
  const double d3f_drs3 = _t125*_t211 + _t126*_t211 + _t211*_t74;
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[35] = d4f_dt4;
  const double d4f_dx_dt3 = 0;
  out[36] = d4f_dx_dt3;
  const double d4f_dx2_dt2 = 0;
  out[37] = d4f_dx2_dt2;
  const double d4f_dx3_dt = -_t116*_t23 + _t118*_t216 + _t212*_t24 + _t213*_t23 - _t215*_t71 - _t215*_t72 - _t216*_t78 + _t217*_t218 + _t219*_t24 - _t23*_t82;
  out[38] = d4f_dx3_dt;
  const double d4f_dx4 = -_hc0[4]*_t25 + _hc1[10]*_t232*_t56 - 0.8e1*_hc1[10]*_t38 + 0.4e1*_hc1[10]*_t54 - 0.1960e4 / 0.27e2*_hc1[10]*_t60 + _hc1[20]*_t21 + _hc1[20]*_t22 + _hc1[20]*_t8 + _hc1[4]*_t137*_t235 + 0.120e3*_hc2[0]*_t239*_t47 - _hc4[2]*_t247*_t72 - 0.112e3 / 0.3e1*_hc4[5]*_t43 - 0.1960e4 / 0.9e1*_hc6[2]*_t103 - 0.1960e4 / 0.27e2*_hc6[3]*_t30 + (0.490e3 / 0.27e2)*_hc6[3]*_t36 + _hc6[4]*_t9 + _t101*_t262 + _t106*_t123*_t256 - _t107*_t226 + _t107*_t243 - _t107*_t258 - _t108*_t227 + _t108*_t244 - _t108*_t259 - _t109*_t111*_t247 + _t110*_t241 - 0.24e2*_t111*_t127 - 0.1960e4 / 0.9e1*_t111*_t129 + _t113*_t241 - _t123*_t248*_t26 - 0.96e2*_t13*_t92*_t97 + _t143*_t91 + _t152*_t235*_t26 + (0.490e3 / 0.27e2)*_t157*_t254 - _t16*_t228 - 0.28e2 / 0.9e1*_t2*_t228 + (0.560e3 / 0.9e1)*_t2*_t245 + (0.1960e4 / 0.3e1)*_t2*_t257 - 0.560e3*_t2*_t270 + _t212*_t231 - _t212*_t246 + (0.28e2 / 0.3e1)*_t217*_t230 + _t219*_t231 - _t219*_t246 + _t220*_t221 + _t220*_t266 + _t220*_t267 - _t222*_t223 + _t222*_t260 - _t224*_t225 + _t224*_t261 - _t225*_t252 - _t225*_t273 - _t226*_t77 - _t227*_t79 + 0.24e2*_t229*_t40 + _t232*_t265*_t73 + _t234*_t71 + _t234*_t72 - _t236*_t237 - _t236*_t269 + _t237*_t264 - 0.8e1*_t238*_t92 + _t240*_t83 + _t241*_t242 + _t243*_t77 + _t244*_t79 + (0.9800e4 / 0.27e2)*_t245*_t5 - _t247*_t88 - _t248*_t90 - 0.112e3 / 0.3e1*_t249*_t32 + (0.560e3 / 0.3e1)*_t249*_t48 - 0.1960e4 / 0.9e1*_t250*_t32 + (0.9800e4 / 0.9e1)*_t250*_t48 - _t251*_t71 - _t251*_t72 + _t252*_t261 + 0.72e2*_t253*_t92 + _t254*_t255 + (0.34300e5 / 0.9e1)*_t257*_t5 - _t258*_t77 - _t259*_t79 + _t261*_t273 + _t262*_t99 - 0.144e3*_t263*_t96 + _t264*_t269 - 0.8e1*_t268*_t73 - 0.9800e4 / 0.3e1*_t270*_t5 + _t271*_t71 + _t271*_t72 - 0.1960e4 / 0.27e2*_t272*_t73 + _t274*_t276 + _t274*_t279;
  out[39] = d4f_dx4;
  const double d4f_dz_dt3 = 0;
  out[40] = d4f_dz_dt3;
  const double d4f_dz_dx_dt2 = 0;
  out[41] = d4f_dz_dx_dt2;
  const double d4f_dz_dx2_dt = -_t131*_t281 - _t133*_t281 + _t24*_t280 + _t24*_t286 + _t24*_t287 - _t282*_t33 + _t282*_t49 + _t283*_t285;
  out[42] = d4f_dz_dx2_dt;
  const double d4f_dz_dx3 = _hc1[10]*_t68 + _hc1[11]*_t288 - _hc1[11]*_t292 - _hc1[11]*_t297 + _hc1[11]*_t95 + _hc1[2]*_t296 - _hc1[2]*_t328 + _hc1[2]*_t334 - _hc1[2]*_t338 - _hc1[2]*_t339 + _hc1[21]*_t21 + _hc1[21]*_t22 + _hc1[21]*_t8 + _hc1[4]*_t295 + _hc1[5]*_t291 - _hc1[5]*_t302 - _t105*_t280 - _t105*_t287 + _t110*_t309 + _t110*_t315 + _t113*_t309 + _t113*_t315 - _t116*_t149 - _t117*_t165 + _t118*_t303 + _t118*_t305 + _t118*_t329 + _t119*_t304 + _t119*_t306 + _t119*_t330 + _t121*_t293 + _t121*_t318 + _t122*_t280 + _t122*_t286 + _t122*_t287 + _t124*_t336 + _t131*_t290 - _t131*_t300 + _t133*_t290 - _t133*_t300 - _t140*_t294 + _t140*_t308 - _t140*_t321 + _t143*_t322 - _t145*_t299 + _t149*_t213 - _t149*_t82 + _t156*_t312 - _t156*_t316 - _t156*_t325 - _t156*_t326 + _t159*_t314 - _t159*_t327 + _t165*_t323 + _t26*_t335 + _t266*_t337 + _t267*_t337 + _t283*_t311 + _t289*_t57 - _t293*_t94 - _t298*_t53 - _t303*_t78 - _t304*_t80 - _t305*_t78 - _t306*_t80 - _t307*_t61 + _t310*_t62 + _t313*_t51 + _t313*_t52 - _t317*_t91 - _t318*_t94 + _t319*_t320 - _t324*_t62 - _t329*_t78 - _t330*_t80 + _t331*_t332 + _t332*_t333;
  out[43] = d4f_dz_dx3;
  const double d4f_dz2_dt2 = 0;
  out[44] = d4f_dz2_dt2;
  const double d4f_dz2_dx_dt = -_t132*_t167 - _t132*_t168 + _t24*_t340 + _t24*_t341 + _t24*_t343 + _t285*_t342;
  out[45] = d4f_dz2_dx_dt;
  const double d4f_dz2_dx2 = _hc1[11]*_t347 + _hc1[12]*_t138 - _hc1[12]*_t139 - _hc1[12]*_t148 + _hc1[12]*_t346 + _hc1[22]*_t21 + _hc1[22]*_t22 + _hc1[22]*_t8 + _hc1[4]*_t169 + _hc1[5]*_t362*_t363 + _hc1[6]*_t143 - _hc1[6]*_t160 + _hc1[6]*_t182 - _hc1[6]*_t185 - _hc1[6]*_t187 + _hc1[6]*_t190 + _hc1[6]*_t344 + _t125*_t370 + _t125*_t371 + _t126*_t370 + _t126*_t371 + _t134*_t167 + _t134*_t168 + _t136*_t340 + _t136*_t341 + _t136*_t343 - _t141*_t345 - _t141*_t359 - _t144*_t167 - _t144*_t168 - _t146*_t357 - _t147*_t340 - _t147*_t343 + _t153*_t170 + _t155*_t348 + _t155*_t351 + _t155*_t352 + _t158*_t348 + _t158*_t351 + _t158*_t352 + _t161*_t345 + _t161*_t359 - _t163*_t170 - _t164*_t170 - _t167*_t350 + _t167*_t365 - _t168*_t350 + _t168*_t365 + _t171*_t353 - _t171*_t355 + _t171*_t356 - _t171*_t360 - _t171*_t361 + _t231*_t342 + _t232*_t336*_t62 + _t266*_t373 + _t267*_t373 + _t348*_t349 + _t354*_t51 + _t354*_t52 + _t357*_t358 + _t364*_t63 - _t366*_t367 + _t366*_t50 + _t368*_t369 - _t368*_t46 - _t372*_t63;
  out[46] = d4f_dz2_dx2;
  const double d4f_dz3_dt = _t218*_t375 + _t24*_t374 + _t24*_t376;
  out[47] = d4f_dz3_dt;
  const double d4f_dz3_dx = _hc1[1]*_t377 + _hc1[12]*_t177 + _hc1[13]*_t54 - _hc1[13]*_t58 + _hc1[13]*_t65 - _hc1[13]*_t66 + _hc1[23]*_t21 + _hc1[23]*_t22 + _hc1[23]*_t8 + _hc1[6]*_t295 + _t110*_t379 + _t110*_t380 + _t113*_t379 + _t113*_t380 + _t122*_t375 - 0.490e3 / 0.9e1*_t129*_t178 + _t169*_t322 + _t176*_t383 - _t176*_t384 - _t176*_t386 + _t178*_t314 - _t178*_t327 + _t266*_t387 + _t267*_t387 - _t317*_t381 + _t319*_t382 + _t331*_t385 + _t333*_t385 + _t335*_t63 + _t336*_t388 + _t374*_t55 - _t374*_t59 + _t376*_t55 - _t376*_t59 + _t378*_t51 + _t378*_t52;
  out[48] = d4f_dz3_dx;
  const double d4f_dz4 = _hc1[13]*_hc1[2]*_t255 + _hc1[13]*_t157*_t61 + 0.4e1*_hc1[13]*_t68 + _hc1[24]*_t21 + _hc1[24]*_t22 + _hc1[24]*_t8 + _t110*_t390 + _t113*_t390 + _t169*_t381 + _t221*_t389 + _t242*_t390 + _t266*_t389 + _t267*_t389 + _t276*_t391 + _t279*_t391;
  out[49] = d4f_dz4;
  const double d4f_drs_dt3 = 0;
  out[50] = d4f_drs_dt3;
  const double d4f_drs_dx_dt2 = 0;
  out[51] = d4f_drs_dx_dt2;
  const double d4f_drs_dx2_dt = -_t179*_t281 - _t180*_t281 + _t24*_t392 + _t24*_t395 + _t24*_t396 + _t285*_t394 - _t33*_t393 + _t393*_t49;
  out[52] = d4f_drs_dx2_dt;
  const double d4f_drs_dx3 = _hc1[10]*_t181 + _hc1[14]*_t288 - _hc1[14]*_t292 - _hc1[14]*_t297 + _hc1[14]*_t95 + _hc1[25]*_t21 + _hc1[25]*_t22 + _hc1[25]*_t8 - _hc1[3]*_hc5[1]*_t299 - _hc1[3]*_t127*_t91 + _hc1[3]*_t289*_t6 + _hc1[3]*_t296 - 0.490e3 / 0.27e2*_hc1[3]*_t307 - _hc1[3]*_t328 + _hc1[3]*_t334 - _hc1[3]*_t338 - _hc1[3]*_t339 + _hc1[7]*_t291 - _hc1[7]*_t302 - _t105*_t392 - _t105*_t396 + _t110*_t398 + _t110*_t403 + _t113*_t398 + _t113*_t403 - _t116*_t186 - _t117*_t407 + _t118*_t399 + _t118*_t401 + _t118*_t408 + _t119*_t400 + _t119*_t402 + _t119*_t409 + _t121*_t397 + _t121*_t405 + _t122*_t392 + _t122*_t395 + _t122*_t396 + _t124*_t412 + _t143*_t406 + _t179*_t290 - _t179*_t300 + _t180*_t290 - _t180*_t300 - _t183*_t294 + _t183*_t308 - _t183*_t321 + _t186*_t213 - _t186*_t82 + _t188*_t312 - _t188*_t316 - _t188*_t325 - _t188*_t326 + _t189*_t314 - _t189*_t327 + _t242*_t398 + _t26*_t411 + _t266*_t413 + _t267*_t413 - _t298*_t64 + _t310*_t67 + _t311*_t394 + 0.3e1*_t320*_t67 + _t323*_t407 - _t324*_t67 + _t331*_t410 + _t333*_t410 - _t397*_t94 - _t399*_t78 - _t400*_t80 - _t401*_t78 - _t402*_t80 + _t404*_t51 + _t404*_t52 - _t405*_t94 - _t408*_t78 - _t409*_t80;
  out[53] = d4f_drs_dx3;
  const double d4f_drs_dz_dt2 = 0;
  out[54] = d4f_drs_dz_dt2;
  const double d4f_drs_dz_dx_dt = -_t132*_t192 - _t132*_t193 + _t195*_t415 + _t197*_t415 + _t198*_t415 + _t24*_t414 + _t24*_t416;
  out[55] = d4f_drs_dz_dx_dt;
  const double d4f_drs_dz_dx2 = _hc1[11]*_t181 + _hc1[14]*_t68 + _hc1[15]*_t138 - _hc1[15]*_t139 - _hc1[15]*_t148 + _hc1[15]*_t346 + _hc1[26]*_t21 + _hc1[26]*_t22 + _hc1[26]*_t8 + _hc1[4]*_t194 + _hc1[7]*_t418 + _hc1[7]*_t430 + _hc1[8]*_t143 - _hc1[8]*_t160 + _hc1[8]*_t182 - _hc1[8]*_t185 - _hc1[8]*_t187 + _hc1[8]*_t190 + _hc1[8]*_t344 + _hc5[2]*_hc6[2]*_t196 - _hc5[2]*_t146*_t69 - _hc5[3]*_t200*_t46 + _hc5[3]*_t256*_t37*_t69 + _t125*_t436 + _t125*_t437 + _t126*_t436 + _t126*_t437 + _t134*_t192 + _t134*_t193 + _t136*_t414 + _t136*_t416 - _t141*_t417 - _t141*_t426 + _t142*_t428 - _t144*_t192 - _t144*_t193 - _t147*_t414 - _t147*_t416 + _t153*_t195 + _t153*_t197 + _t153*_t198 + _t155*_t419 + _t155*_t424 + _t158*_t419 + _t158*_t424 + _t161*_t417 + _t161*_t426 - _t163*_t195 - _t163*_t197 - _t163*_t198 - _t164*_t195 - _t164*_t197 - _t164*_t198 + _t184*_t427 - _t192*_t350 + _t192*_t365 + _t195*_t420 + _t197*_t420 - _t197*_t425 + _t198*_t420 - _t198*_t425 - _t199*_t33 + _t199*_t49 + _t266*_t438 + _t267*_t438 + _t364*_t69 - _t367*_t429 - _t372*_t69 + _t412*_t432 + _t421*_t51 + _t421*_t52 + _t422*_t51 + _t422*_t52 + _t423*_t51 + _t423*_t52 + _t429*_t50 + _t433*_t434 + _t435*_t67;
  out[56] = d4f_drs_dz_dx2;
  const double d4f_drs_dz2_dt = _t202*_t440 + _t203*_t415 + _t24*_t439 + _t24*_t441;
  out[57] = d4f_drs_dz2_dt;
  const double d4f_drs_dz2_dx = _hc1[12]*_t181 + _hc1[15]*_t347 + _hc1[16]*_t54 - _hc1[16]*_t58 + _hc1[16]*_t65 - _hc1[16]*_t66 + _hc1[27]*_t21 + _hc1[27]*_t22 + _hc1[27]*_t8 + _hc1[7]*_t169 + _hc1[8]*_t418 + _hc1[8]*_t430 + _hc3[2]*_t203*_t55 - _t109*_t15*_t203 + _t125*_t449 + _t125*_t451 + _t126*_t449 + _t126*_t451 + _t142*_t194 + _t153*_t202 + _t155*_t445 + _t155*_t446 + _t158*_t445 + _t158*_t446 - _t163*_t202 - _t164*_t202 + _t172*_t203 - _t173*_t203 - _t174*_t203 + _t201*_t427 + _t202*_t420 - _t202*_t425 + _t204*_t383 - _t204*_t384 - _t204*_t386 + _t266*_t452 + _t267*_t452 + _t27*_t442 + _t382*_t67 + _t432*_t448 + _t434*_t450 + _t435*_t69 + _t439*_t55 - _t439*_t59 + _t441*_t55 - _t441*_t59 + _t442*_t51 + _t442*_t52 + _t443*_t51 + _t443*_t52 + _t444*_t51 + _t444*_t52 + _t447*_t67;
  out[58] = d4f_drs_dz2_dx;
  const double d4f_drs_dz3 = _hc1[13]*_t181 + _hc1[16]*_t177 + _hc1[28]*_t21 + _hc1[28]*_t22 + _hc1[28]*_t8 + _hc1[3]*_t377 + 0.3e1*_hc1[6]*_t194 + _t110*_t453 + _t110*_t455 + _t113*_t453 + _t113*_t455 + _t169*_t456 + _t242*_t453 + _t266*_t459 + _t267*_t459 + _t331*_t457 + _t333*_t457 + _t388*_t448 + _t454*_t51 + _t454*_t52 + _t458*_t63;
  out[59] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = 0;
  out[60] = d4f_drs2_dt2;
  const double d4f_drs2_dx_dt = -_t132*_t205 + _t207*_t440 + _t24*_t460;
  out[61] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx2 = _hc1[14]*_t461 + _hc1[4]*_t206 + _hc1[7]*_t363*_t433 + _hc3[2]*_t207*_t231 + _t125*_t468 + _t126*_t468 + _t134*_t205 + _t136*_t460 - _t141*_t465 - _t144*_t205 - _t146*_t464 - _t147*_t460 + _t155*_t462 + _t155*_t463 + _t158*_t462 + _t158*_t463 + _t161*_t465 - _t205*_t350 + _t205*_t365 + _t207*_t353 - _t207*_t355 + _t207*_t356 - _t207*_t360 - _t207*_t361 + _t232*_t412*_t67 + _t266*_t469 + _t267*_t469 + _t349*_t462 + _t358*_t464 + _t364*_t70 - _t367*_t466 + _t369*_t467 - _t372*_t70 - _t46*_t467 + _t466*_t50;
  out[62] = d4f_drs2_dx2;
  const double d4f_drs2_dz_dt = _t209*_t440 + _t24*_t470;
  out[63] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz_dx = _hc1[15]*_t461 + _hc1[5]*_t206 + _hc1[7]*_t284*_t450 + _hc1[8]*_t284*_t433 + _t125*_t474 + _t126*_t474 + _t153*_t209 + _t155*_t471 + _t155*_t472 + _t158*_t471 + _t158*_t472 - _t163*_t209 - _t164*_t209 + _t184*_t194 + _t201*_t428 + _t209*_t420 - _t209*_t425 - _t210*_t384 + _t221*_t473 + _t265*_t57*_t70 + _t266*_t473 + _t267*_t473 - _t272*_t61*_t70 + _t349*_t471 + _t412*_t431*_t69 + _t431*_t448*_t67 + _t470*_t55 - _t470*_t59;
  out[64] = d4f_drs2_dz_dx;
  const double d4f_drs2_dz2 = _hc1[16]*_t461 + _hc1[6]*_t206 + 0.4e1*_hc1[8]*_t194 + _hc1[8]*_t363*_t450 + _t125*_t477 + _t126*_t477 + _t155*_t475 + _t155*_t476 + _t158*_t475 + _t158*_t476 + _t232*_t448*_t69 + _t266*_t478 + _t267*_t478 + _t349*_t475 + _t447*_t70;
  out[65] = d4f_drs2_dz2;
  const double d4f_drs3_dt = _t24*_t479;
  out[66] = d4f_drs3_dt;
  const double d4f_drs3_dx = _hc1[1]*_t480 + _t206*_t406 + _t211*_t383 - _t211*_t384 - _t211*_t386 + _t266*_t481 + _t267*_t481 + _t411*_t70 + _t412*_t482 + _t479*_t55 - _t479*_t59;
  out[67] = d4f_drs3_dx;
  const double d4f_drs3_dz = _hc1[2]*_t480 + _t206*_t456 + _t266*_t483 + _t267*_t483 + _t448*_t482 + _t458*_t70;
  out[68] = d4f_drs3_dz;
  const double d4f_drs4 = _t221*_t484 + _t266*_t484 + _t267*_t484;
  out[69] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pjs18_f_k, _KMAX)(const xc_func_type *p, double rs, double z, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(js18_DME_SR_k, _KMAX)(p, rs, z, x, t, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1];
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc0[2];
  out[3] = df_dx;
  const double df_dz = _hc0[3];
  out[4] = df_dz;
  const double df_drs = _hc0[4];
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[5];
  out[6] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[7] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[8] = d2f_du2;
  const double d2f_dx_dt = _hc0[6];
  out[9] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[10] = d2f_dx_du;
  const double d2f_dx2 = _hc0[7];
  out[11] = d2f_dx2;
  const double d2f_dz_dt = _hc0[8];
  out[12] = d2f_dz_dt;
  const double d2f_dz_du = 0;
  out[13] = d2f_dz_du;
  const double d2f_dz_dx = _hc0[9];
  out[14] = d2f_dz_dx;
  const double d2f_dz2 = _hc0[10];
  out[15] = d2f_dz2;
  const double d2f_drs_dt = _hc0[11];
  out[16] = d2f_drs_dt;
  const double d2f_drs_du = 0;
  out[17] = d2f_drs_du;
  const double d2f_drs_dx = _hc0[12];
  out[18] = d2f_drs_dx;
  const double d2f_drs_dz = _hc0[13];
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[14];
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[15];
  out[21] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[22] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[23] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[24] = d3f_du3;
  const double d3f_dx_dt2 = _hc0[16];
  out[25] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[26] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[27] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc0[17];
  out[28] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[29] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[18];
  out[30] = d3f_dx3;
  const double d3f_dz_dt2 = _hc0[19];
  out[31] = d3f_dz_dt2;
  const double d3f_dz_du_dt = 0;
  out[32] = d3f_dz_du_dt;
  const double d3f_dz_du2 = 0;
  out[33] = d3f_dz_du2;
  const double d3f_dz_dx_dt = _hc0[20];
  out[34] = d3f_dz_dx_dt;
  const double d3f_dz_dx_du = 0;
  out[35] = d3f_dz_dx_du;
  const double d3f_dz_dx2 = _hc0[21];
  out[36] = d3f_dz_dx2;
  const double d3f_dz2_dt = _hc0[22];
  out[37] = d3f_dz2_dt;
  const double d3f_dz2_du = 0;
  out[38] = d3f_dz2_du;
  const double d3f_dz2_dx = _hc0[23];
  out[39] = d3f_dz2_dx;
  const double d3f_dz3 = _hc0[24];
  out[40] = d3f_dz3;
  const double d3f_drs_dt2 = _hc0[25];
  out[41] = d3f_drs_dt2;
  const double d3f_drs_du_dt = 0;
  out[42] = d3f_drs_du_dt;
  const double d3f_drs_du2 = 0;
  out[43] = d3f_drs_du2;
  const double d3f_drs_dx_dt = _hc0[26];
  out[44] = d3f_drs_dx_dt;
  const double d3f_drs_dx_du = 0;
  out[45] = d3f_drs_dx_du;
  const double d3f_drs_dx2 = _hc0[27];
  out[46] = d3f_drs_dx2;
  const double d3f_drs_dz_dt = _hc0[28];
  out[47] = d3f_drs_dz_dt;
  const double d3f_drs_dz_du = 0;
  out[48] = d3f_drs_dz_du;
  const double d3f_drs_dz_dx = _hc0[29];
  out[49] = d3f_drs_dz_dx;
  const double d3f_drs_dz2 = _hc0[30];
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dt = _hc0[31];
  out[51] = d3f_drs2_dt;
  const double d3f_drs2_du = 0;
  out[52] = d3f_drs2_du;
  const double d3f_drs2_dx = _hc0[32];
  out[53] = d3f_drs2_dx;
  const double d3f_drs2_dz = _hc0[33];
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[34];
  out[55] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc0[35];
  out[56] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[57] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[58] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[59] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[60] = d4f_du4;
  const double d4f_dx_dt3 = _hc0[36];
  out[61] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[62] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[63] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[64] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc0[37];
  out[65] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[66] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[67] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc0[38];
  out[68] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[69] = d4f_dx3_du;
  const double d4f_dx4 = _hc0[39];
  out[70] = d4f_dx4;
  const double d4f_dz_dt3 = _hc0[40];
  out[71] = d4f_dz_dt3;
  const double d4f_dz_du_dt2 = 0;
  out[72] = d4f_dz_du_dt2;
  const double d4f_dz_du2_dt = 0;
  out[73] = d4f_dz_du2_dt;
  const double d4f_dz_du3 = 0;
  out[74] = d4f_dz_du3;
  const double d4f_dz_dx_dt2 = _hc0[41];
  out[75] = d4f_dz_dx_dt2;
  const double d4f_dz_dx_du_dt = 0;
  out[76] = d4f_dz_dx_du_dt;
  const double d4f_dz_dx_du2 = 0;
  out[77] = d4f_dz_dx_du2;
  const double d4f_dz_dx2_dt = _hc0[42];
  out[78] = d4f_dz_dx2_dt;
  const double d4f_dz_dx2_du = 0;
  out[79] = d4f_dz_dx2_du;
  const double d4f_dz_dx3 = _hc0[43];
  out[80] = d4f_dz_dx3;
  const double d4f_dz2_dt2 = _hc0[44];
  out[81] = d4f_dz2_dt2;
  const double d4f_dz2_du_dt = 0;
  out[82] = d4f_dz2_du_dt;
  const double d4f_dz2_du2 = 0;
  out[83] = d4f_dz2_du2;
  const double d4f_dz2_dx_dt = _hc0[45];
  out[84] = d4f_dz2_dx_dt;
  const double d4f_dz2_dx_du = 0;
  out[85] = d4f_dz2_dx_du;
  const double d4f_dz2_dx2 = _hc0[46];
  out[86] = d4f_dz2_dx2;
  const double d4f_dz3_dt = _hc0[47];
  out[87] = d4f_dz3_dt;
  const double d4f_dz3_du = 0;
  out[88] = d4f_dz3_du;
  const double d4f_dz3_dx = _hc0[48];
  out[89] = d4f_dz3_dx;
  const double d4f_dz4 = _hc0[49];
  out[90] = d4f_dz4;
  const double d4f_drs_dt3 = _hc0[50];
  out[91] = d4f_drs_dt3;
  const double d4f_drs_du_dt2 = 0;
  out[92] = d4f_drs_du_dt2;
  const double d4f_drs_du2_dt = 0;
  out[93] = d4f_drs_du2_dt;
  const double d4f_drs_du3 = 0;
  out[94] = d4f_drs_du3;
  const double d4f_drs_dx_dt2 = _hc0[51];
  out[95] = d4f_drs_dx_dt2;
  const double d4f_drs_dx_du_dt = 0;
  out[96] = d4f_drs_dx_du_dt;
  const double d4f_drs_dx_du2 = 0;
  out[97] = d4f_drs_dx_du2;
  const double d4f_drs_dx2_dt = _hc0[52];
  out[98] = d4f_drs_dx2_dt;
  const double d4f_drs_dx2_du = 0;
  out[99] = d4f_drs_dx2_du;
  const double d4f_drs_dx3 = _hc0[53];
  out[100] = d4f_drs_dx3;
  const double d4f_drs_dz_dt2 = _hc0[54];
  out[101] = d4f_drs_dz_dt2;
  const double d4f_drs_dz_du_dt = 0;
  out[102] = d4f_drs_dz_du_dt;
  const double d4f_drs_dz_du2 = 0;
  out[103] = d4f_drs_dz_du2;
  const double d4f_drs_dz_dx_dt = _hc0[55];
  out[104] = d4f_drs_dz_dx_dt;
  const double d4f_drs_dz_dx_du = 0;
  out[105] = d4f_drs_dz_dx_du;
  const double d4f_drs_dz_dx2 = _hc0[56];
  out[106] = d4f_drs_dz_dx2;
  const double d4f_drs_dz2_dt = _hc0[57];
  out[107] = d4f_drs_dz2_dt;
  const double d4f_drs_dz2_du = 0;
  out[108] = d4f_drs_dz2_du;
  const double d4f_drs_dz2_dx = _hc0[58];
  out[109] = d4f_drs_dz2_dx;
  const double d4f_drs_dz3 = _hc0[59];
  out[110] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = _hc0[60];
  out[111] = d4f_drs2_dt2;
  const double d4f_drs2_du_dt = 0;
  out[112] = d4f_drs2_du_dt;
  const double d4f_drs2_du2 = 0;
  out[113] = d4f_drs2_du2;
  const double d4f_drs2_dx_dt = _hc0[61];
  out[114] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx_du = 0;
  out[115] = d4f_drs2_dx_du;
  const double d4f_drs2_dx2 = _hc0[62];
  out[116] = d4f_drs2_dx2;
  const double d4f_drs2_dz_dt = _hc0[63];
  out[117] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz_du = 0;
  out[118] = d4f_drs2_dz_du;
  const double d4f_drs2_dz_dx = _hc0[64];
  out[119] = d4f_drs2_dz_dx;
  const double d4f_drs2_dz2 = _hc0[65];
  out[120] = d4f_drs2_dz2;
  const double d4f_drs3_dt = _hc0[66];
  out[121] = d4f_drs3_dt;
  const double d4f_drs3_du = 0;
  out[122] = d4f_drs3_du;
  const double d4f_drs3_dx = _hc0[67];
  out[123] = d4f_drs3_dx;
  const double d4f_drs3_dz = _hc0[68];
  out[124] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[69];
  out[125] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)*M_CBRT3/(M_CBRTPI*M_CBRTPI);
  const double _t2 = (0.3e1 / 0.16e2)*_t1;

  const double f = -_t2/rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2/(rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.3e1 / 0.8e1*_t1/(rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.9e1 / 0.8e1)*_t1/(rs * rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.9e1 / 0.2e1*_t1/xc_powi(rs, 5);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(js18_A_z0_k, _KMAX)(const xc_func_type *p, double rs, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_f0_k, _KMAX)(p, x, _hc0);
  const double _t1 = M_CBRTPI;
  const double _t2 = xc_powr(XC_EPSILON, 2, 3);
  const double _t3 = xc_powr(0.2e1, 2, 3);
  const double _t4 = M_CBRT3;
  const double _t5 = _t3*_t4*p->cam_omega;
  const double _t6 = _t5*rs;
  const double _t7 = (0.1e1 / _t1);
  const double _t8 = (0.1e1 / 0.6e1)*_t7;
  const double _t9 = _t8/_hc0[0];
  const double _t10 = _t9*(0.6e1*_hc0[0]*_t1*_t2 - _t6) > 0;
#if _KMAX >= 1
  const double _t11 = _t8/((_hc0[0]) * (_hc0[0]));
  const double _t12 = _t11*_t6;
#endif
#if _KMAX >= 2
  const double _t13 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t14 = ((_hc0[1]) * (_hc0[1]));
  const double _t15 = _t11*_t5;
#endif
#if _KMAX >= 3
  const double _t16 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t17 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t16;
  const double _t18 = _t6*_t7;
#endif
#if _KMAX >= 4
  const double _t19 = _t13*_t18;
#endif

  const double f = my_piecewise3(_t10, _t2, _t6*_t9);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = my_piecewise3(_t10, 0, -_hc0[1]*_t12);
  out[1] = df_dx;
  const double df_drs = my_piecewise3(_t10, 0, _t5*_t9);
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = my_piecewise3(_t10, 0, -_hc0[2]*_t12 + (0.1e1 / 0.3e1)*_t13*_t14*_t3*_t4*_t7*p->cam_omega*rs);
  out[3] = d2f_dx2;
  const double d2f_drs_dx = my_piecewise3(_t10, 0, -_hc0[1]*_t15);
  out[4] = d2f_drs_dx;
  const double d2f_drs2 = 0;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = my_piecewise3(_t10, 0, _hc0[1]*_hc0[2]*_t13*_t3*_t4*_t7*p->cam_omega*rs - _hc0[3]*_t12 - _t17*_t18);
  out[6] = d3f_dx3;
  const double d3f_drs_dx2 = my_piecewise3(_t10, 0, -_hc0[2]*_t15 + (0.1e1 / 0.3e1)*_t13*_t14*_t3*_t4*_t7*p->cam_omega);
  out[7] = d3f_drs_dx2;
  const double d3f_drs2_dx = 0;
  out[8] = d3f_drs2_dx;
  const double d3f_drs3 = 0;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = my_piecewise3(_t10, 0, (0.4e1 / 0.3e1)*_hc0[1]*_hc0[3]*_t19 + ((_hc0[2]) * (_hc0[2]))*_t19 - 0.6e1*_hc0[2]*_t14*_t16*_t18 - _hc0[4]*_t12 + 0.4e1*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t18/xc_powi((_hc0[0]), 5));
  out[10] = d4f_dx4;
  const double d4f_drs_dx3 = my_piecewise3(_t10, 0, _hc0[1]*_hc0[2]*_t13*_t3*_t4*_t7*p->cam_omega - _hc0[3]*_t15 - _t17*_t5*_t7);
  out[11] = d4f_drs_dx3;
  const double d4f_drs2_dx2 = 0;
  out[12] = d4f_drs2_dx2;
  const double d4f_drs3_dx = 0;
  out[13] = d4f_drs3_dx;
  const double d4f_drs4 = 0;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(js18_DME_SR_z0_k, _KMAX)(const xc_func_type *p, double rs, double x, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_f0_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(js18_A_z0_k, _KMAX)(p, rs, x, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_k, _KMAX)(p, _hc1[0], _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_f2_k, _KMAX)(p, _hc1[0], _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(js18_G_k, _KMAX)(p, x, t, _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_f3_k, _KMAX)(p, _hc1[0], _hc5);
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(js18_H_k, _KMAX)(p, x, _hc6);
  const double _t1 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t2 = _hc3[0]*_hc4[0];
  const double _t3 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t4 = (0.7e1 / 0.9e1)*_t3;
  const double _t5 = _hc5[0]*_hc6[0];
  const double _t6 = (0.245e3 / 0.54e2)*_t3;
#if _KMAX >= 1
  const double _t7 = _hc3[0]*_t4;
  const double _t8 = _hc2[1]*_t1;
  const double _t9 = _hc5[0]*_t6;
  const double _t10 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t11 = _hc0[1]*_t10;
  const double _t12 = 0.2e1*_hc2[0];
  const double _t13 = xc_powi((_hc0[0]), -5);
  const double _t14 = _hc0[1]*_t13;
  const double _t15 = (0.28e2 / 0.9e1)*_t14;
  const double _t16 = (0.490e3 / 0.27e2)*_t5;
  const double _t17 = _hc4[0]*_t4;
  const double _t18 = _hc1[1]*_hc3[1];
  const double _t19 = _hc1[1]*_hc5[1];
  const double _t20 = _hc6[0]*_t6;
  const double _t21 = _hc3[1]*_t17;
  const double _t22 = _hc5[1]*_t20;
#endif
#if _KMAX >= 2
  const double _t23 = _hc3[0]*_hc4[1];
  const double _t24 = _hc4[1]*_t4;
  const double _t25 = _t10*_t12;
  const double _t26 = ((_hc1[1]) * (_hc1[1]));
  const double _t27 = _hc2[2]*_t1;
  const double _t28 = _hc3[0]*_t14;
  const double _t29 = (0.56e2 / 0.9e1)*_hc4[2];
  const double _t30 = _hc5[0]*_t14;
  const double _t31 = (0.980e3 / 0.27e2)*_hc6[1];
  const double _t32 = _hc0[2]*_t13;
  const double _t33 = (0.28e2 / 0.9e1)*_t32;
  const double _t34 = _t18*_t3;
  const double _t35 = (0.14e2 / 0.9e1)*_hc4[2];
  const double _t36 = _t19*_t3;
  const double _t37 = (0.245e3 / 0.27e2)*_hc6[1];
  const double _t38 = _hc2[1]*_t11;
  const double _t39 = 0.4e1*_hc1[1];
  const double _t40 = _hc2[0]*_t3;
  const double _t41 = ((_hc0[1]) * (_hc0[1]));
  const double _t42 = 0.6e1*_t41;
  const double _t43 = _t14*_t18;
  const double _t44 = (0.56e2 / 0.9e1)*_t43;
  const double _t45 = _hc6[0]*_t14;
  const double _t46 = (0.980e3 / 0.27e2)*_t45;
  const double _t47 = xc_powi((_hc0[0]), -6);
  const double _t48 = _t41*_t47;
  const double _t49 = (0.140e3 / 0.9e1)*_t48;
  const double _t50 = (0.2450e4 / 0.27e2)*_t48;
  const double _t51 = _hc3[2]*_t17;
  const double _t52 = _hc5[2]*_t20;
  const double _t53 = _hc1[2]*_hc3[1];
  const double _t54 = _hc1[2]*_t27;
  const double _t55 = _t4*_t53;
  const double _t56 = _hc5[1]*_hc6[1];
  const double _t57 = _hc1[2]*_t6;
  const double _t58 = 0.2e1*_hc1[2];
  const double _t59 = _t15*_t53;
  const double _t60 = _hc5[1]*_t45;
  const double _t61 = (0.490e3 / 0.27e2)*_hc1[2];
  const double _t62 = _hc1[1]*_hc1[2];
  const double _t63 = ((_hc1[2]) * (_hc1[2]));
#endif
#if _KMAX >= 3
  const double _t64 = _hc1[3]*_hc3[1];
  const double _t65 = _hc3[2]*_t26;
  const double _t66 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t67 = _hc2[3]*_t1;
  const double _t68 = (0.28e2 / 0.3e1)*_hc4[5];
  const double _t69 = (0.490e3 / 0.9e1)*_hc6[2];
  const double _t70 = _hc3[0]*_hc4[2];
  const double _t71 = (0.28e2 / 0.3e1)*_t32;
  const double _t72 = _hc5[0]*_hc6[1];
  const double _t73 = (0.490e3 / 0.9e1)*_t32;
  const double _t74 = _hc0[3]*_t13;
  const double _t75 = (0.28e2 / 0.9e1)*_t74;
  const double _t76 = 0.18e2*_t40;
  const double _t77 = _hc0[1]*_hc0[2];
  const double _t78 = (0.7e1 / 0.3e1)*_hc4[5];
  const double _t79 = (0.245e3 / 0.18e2)*_hc6[2];
  const double _t80 = (0.7e1 / 0.3e1)*_t3;
  const double _t81 = _hc4[2]*_t64;
  const double _t82 = (0.245e3 / 0.18e2)*_t3;
  const double _t83 = _hc1[3]*_t56;
  const double _t84 = 0.6e1*_hc1[3];
  const double _t85 = _hc1[1]*_hc2[1];
  const double _t86 = _hc0[2]*_t10;
  const double _t87 = 0.6e1*_t86;
  const double _t88 = 0.3e1*_t27;
  const double _t89 = _hc1[1]*_t88;
  const double _t90 = _hc2[0]*_t13;
  const double _t91 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t92 = 0.24e2*_t91;
  const double _t93 = (0.140e3 / 0.3e1)*_t2;
  const double _t94 = _t47*_t77;
  const double _t95 = (0.2450e4 / 0.9e1)*_t5;
  const double _t96 = (0.56e2 / 0.3e1)*_hc4[2];
  const double _t97 = _t14*_t19;
  const double _t98 = _hc4[0]*_t14;
  const double _t99 = (0.28e2 / 0.3e1)*_t98;
  const double _t100 = (0.490e3 / 0.9e1)*_hc1[3];
  const double _t101 = _hc4[0]*_t18;
  const double _t102 = _hc6[0]*_t19;
  const double _t103 = _hc3[2]*_hc4[0];
  const double _t104 = _t103*_t80;
  const double _t105 = _hc1[1]*_hc1[3];
  const double _t106 = _hc5[2]*_hc6[0];
  const double _t107 = _t106*_t82;
  const double _t108 = xc_powi((_hc0[0]), -7);
  const double _t109 = _t108*_t91;
  const double _t110 = (0.280e3 / 0.3e1)*_t109;
  const double _t111 = (0.4900e4 / 0.9e1)*_t109;
  const double _t112 = (0.140e3 / 0.3e1)*_t48;
  const double _t113 = (0.2450e4 / 0.9e1)*_t48;
  const double _t114 = _t3*_t41;
  const double _t115 = 0.18e2*_t114;
  const double _t116 = _hc4[2]*_t80;
  const double _t117 = _hc5[2]*_hc6[1];
  const double _t118 = _t26*_t82;
  const double _t119 = _hc3[3]*_t17;
  const double _t120 = _hc5[3]*_t20;
  const double _t121 = _hc2[2]*_t11;
  const double _t122 = 0.6e1*_t26;
  const double _t123 = _t106*_t14;
  const double _t124 = (0.490e3 / 0.9e1)*_t26;
  const double _t125 = _hc1[4]*_hc3[1];
  const double _t126 = _hc3[2]*_t62;
  const double _t127 = _hc5[1]*_t57;
  const double _t128 = _t125*_t3;
  const double _t129 = _hc5[1]*_t3;
  const double _t130 = _hc1[4]*_t129;
  const double _t131 = _hc2[1]*_t86;
  const double _t132 = 0.2e1*_t27;
  const double _t133 = _hc1[1]*_hc1[4];
  const double _t134 = _t26*_t67;
  const double _t135 = _t14*_t53;
  const double _t136 = _hc1[2]*_hc5[1];
  const double _t137 = _t14*_t31;
  const double _t138 = (0.56e2 / 0.9e1)*_t125;
  const double _t139 = _hc1[4]*_hc5[1];
  const double _t140 = _hc4[0]*_t53;
  const double _t141 = _hc5[1]*_hc6[0];
  const double _t142 = _t141*_t61;
  const double _t143 = _t126*_t3;
  const double _t144 = _hc5[2]*_t3;
  const double _t145 = _t144*_t62;
  const double _t146 = _t103*_t3;
  const double _t147 = (0.14e2 / 0.9e1)*_t146;
  const double _t148 = _hc6[0]*_t144;
  const double _t149 = (0.245e3 / 0.27e2)*_t148;
  const double _t150 = _hc1[2]*_hc1[3];
  const double _t151 = _hc1[2]*_t121;
  const double _t152 = _hc1[2]*_hc2[1];
  const double _t153 = _t3*_t42;
  const double _t154 = _t103*_t14;
  const double _t155 = _hc6[0]*_t136;
  const double _t156 = _hc1[2]*_t26;
  const double _t157 = _hc3[2]*_t63;
  const double _t158 = 0.2e1*_t54;
  const double _t159 = _t63*_t67;
  const double _t160 = _hc1[2]*_hc1[4];
  const double _t161 = _t157*_t4;
  const double _t162 = _t6*_t63;
  const double _t163 = 0.2e1*_t63;
  const double _t164 = _t15*_t157;
  const double _t165 = (0.490e3 / 0.27e2)*_t63;
  const double _t166 = _hc1[1]*_t63;
  const double _t167 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
#endif
#if _KMAX >= 4
  const double _t168 = _hc1[6]*_hc3[1];
  const double _t169 = (0.140e3 / 0.3e1)*_t94;
  const double _t170 = _hc4[1]*_t14;
  const double _t171 = (0.28e2 / 0.3e1)*_t170;
  const double _t172 = _hc4[1]*_t18;
  const double _t173 = _hc3[2]*_t105;
  const double _t174 = _hc3[3]*_t66;
  const double _t175 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t176 = _hc2[4]*_t1;
  const double _t177 = _hc3[0]*_hc4[5];
  const double _t178 = (0.56e2 / 0.3e1)*_t32;
  const double _t179 = _hc5[0]*_hc6[2];
  const double _t180 = (0.980e3 / 0.9e1)*_t32;
  const double _t181 = (0.112e3 / 0.9e1)*_t74;
  const double _t182 = (0.1960e4 / 0.27e2)*_t74;
  const double _t183 = _hc0[4]*_t13;
  const double _t184 = _hc0[1]*_hc0[3];
  const double _t185 = (0.14e2 / 0.3e1)*_t3;
  const double _t186 = _hc4[5]*_t185;
  const double _t187 = (0.245e3 / 0.9e1)*_hc6[2];
  const double _t188 = _hc4[2]*_t3;
  const double _t189 = (0.28e2 / 0.9e1)*_t188;
  const double _t190 = (0.490e3 / 0.27e2)*_t3;
  const double _t191 = _hc0[3]*_t10;
  const double _t192 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t193 = ((_hc0[2]) * (_hc0[2]));
  const double _t194 = ((_hc1[3]) * (_hc1[3]));
  const double _t195 = (0.560e3 / 0.3e1)*_t94;
  const double _t196 = (0.9800e4 / 0.9e1)*_t94;
  const double _t197 = _t184*_t47;
  const double _t198 = (0.112e3 / 0.3e1)*_t14;
  const double _t199 = (0.1960e4 / 0.9e1)*_t14;
  const double _t200 = (0.112e3 / 0.9e1)*_t98;
  const double _t201 = _hc4[2]*_t18;
  const double _t202 = _hc6[1]*_t19;
  const double _t203 = _hc4[0]*_t178;
  const double _t204 = _hc1[3]*_t141;
  const double _t205 = _t3*_t77;
  const double _t206 = _hc1[1]*_hc1[6];
  const double _t207 = _t192/xc_powi((_hc0[0]), 8);
  const double _t208 = (0.1120e4 / 0.3e1)*_t109;
  const double _t209 = (0.19600e5 / 0.9e1)*_t109;
  const double _t210 = (0.280e3 / 0.3e1)*_t48;
  const double _t211 = (0.4900e4 / 0.9e1)*_t48;
  const double _t212 = _t193*_t47;
  const double _t213 = _hc0[2]*_t41;
  const double _t214 = 0.36e2*_t114;
  const double _t215 = _hc5[3]*_hc6[1];
  const double _t216 = _hc3[4]*_t17;
  const double _t217 = _hc5[4]*_t20;
  const double _t218 = _hc2[3]*_t11;
  const double _t219 = _hc2[2]*_t26;
  const double _t220 = _t108*_t213;
  const double _t221 = _hc4[0]*_t210;
  const double _t222 = _hc5[3]*_t45;
  const double _t223 = _t106*_t26;
  const double _t224 = _hc1[3]*_t26;
  const double _t225 = _hc3[3]*_hc4[0];
  const double _t226 = (0.245e3 / 0.9e1)*_t3;
  const double _t227 = _hc5[3]*_hc6[0];
  const double _t228 = _hc1[7]*_hc3[1];
  const double _t229 = _hc4[1]*_t53;
  const double _t230 = _hc3[2]*_t133;
  const double _t231 = (0.14e2 / 0.9e1)*_hc4[1]*_t3;
  const double _t232 = _hc3[2]*_t150;
  const double _t233 = _hc3[3]*_t156;
  const double _t234 = _hc1[4]*_hc2[1];
  const double _t235 = _hc1[3]*_hc1[4];
  const double _t236 = _hc1[2]*_t66;
  const double _t237 = _t14*_t96;
  const double _t238 = (0.980e3 / 0.9e1)*_t14;
  const double _t239 = _hc4[2]*_t53;
  const double _t240 = _hc1[2]*_t56;
  const double _t241 = _hc4[0]*_t125;
  const double _t242 = _hc6[0]*_t139;
  const double _t243 = _hc1[1]*_hc1[7];
  const double _t244 = _hc1[2]*_hc1[6];
  const double _t245 = _hc2[2]*_t62;
  const double _t246 = _hc1[3]*_t62;
  const double _t247 = 0.3e1*_hc1[4];
  const double _t248 = _t103*_t62;
  const double _t249 = _t106*_t62;
  const double _t250 = _t225*_t80;
  const double _t251 = _hc1[4]*_t250;
  const double _t252 = _hc1[4]*_t227;
  const double _t253 = _hc3[2]*_t160;
  const double _t254 = _hc3[3]*_t166;
  const double _t255 = ((_hc1[4]) * (_hc1[4]));
  const double _t256 = _hc1[2]*_hc1[7];
  const double _t257 = _hc1[2]*_t133;
  const double _t258 = _t26*_t63;
  const double _t259 = _hc4[0]*_t157;
  const double _t260 = _hc5[3]*_t166;
  const double _t261 = _hc1[3]*_t63;
  const double _t262 = _hc3[3]*_t167;
  const double _t263 = _hc1[1]*_t167;
  const double _t264 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]));
#endif

  const double f = _hc2[0]*_t1 + _t2*_t4 + _t5*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc4[1]*_t7;
  out[1] = df_dt;
  const double df_dx = _hc1[1]*_t8 + _hc4[2]*_t7 + _hc6[1]*_t9 - _t11*_t12 - _t14*_t16 - _t15*_t2 + _t17*_t18 + _t19*_t20;
  out[2] = df_dx;
  const double df_drs = _hc1[2]*_t21 + _hc1[2]*_t22 + _hc1[2]*_t8;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_dx_dt = -_t15*_t23 + _t18*_t24;
  out[5] = d2f_dx_dt;
  const double d2f_dx2 = -_hc0[2]*_t25 + _hc1[3]*_t21 + _hc1[3]*_t22 + _hc1[3]*_t8 - _hc4[0]*_t44 + _hc4[5]*_t7 + _hc6[2]*_t9 - _t16*_t32 - _t19*_t46 - _t2*_t33 + _t2*_t49 + _t26*_t27 + _t26*_t51 + _t26*_t52 - _t28*_t29 - _t30*_t31 + _t34*_t35 + _t36*_t37 - _t38*_t39 + _t40*_t42 + _t5*_t50;
  out[6] = d2f_dx2;
  const double d2f_drs_dt = _t24*_t53;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dx = _hc1[1]*_t54 + _hc1[4]*_t21 + _hc1[4]*_t22 + _hc1[4]*_t8 - _hc4[0]*_t59 + _hc4[2]*_t55 - _t38*_t58 + _t51*_t62 + _t52*_t62 + _t56*_t57 - _t60*_t61;
  out[8] = d2f_drs_dx;
  const double d2f_drs2 = _t27*_t63 + _t51*_t63 + _t52*_t63;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_dx_dt2 = 0;
  out[11] = d3f_dx_dt2;
  const double d3f_dx2_dt = -_hc4[1]*_t44 - _t23*_t33 + _t23*_t49 + _t24*_t64 + _t24*_t65;
  out[12] = d3f_dx2_dt;
  const double d3f_dx3 = -_hc0[3]*_t25 + _hc1[3]*_t89 + _hc1[6]*_t21 + _hc1[6]*_t22 + _hc1[6]*_t8 - 0.980e3 / 0.9e1*_hc6[1]*_t97 + _hc6[3]*_t9 - _t100*_t60 + _t101*_t112 - _t101*_t71 + _t102*_t113 - _t102*_t73 + _t104*_t105 + _t105*_t107 - _t110*_t2 - _t111*_t5 + _t112*_t70 + _t113*_t72 + _t115*_t85 + _t116*_t65 + _t117*_t118 + _t119*_t66 + _t120*_t66 - _t121*_t122 - _t123*_t124 - _t16*_t74 - _t2*_t75 - _t28*_t68 - _t30*_t69 + _t34*_t78 + _t36*_t79 - _t38*_t84 - _t43*_t96 - _t64*_t99 - _t65*_t99 + _t66*_t67 - _t70*_t71 - _t72*_t73 + _t76*_t77 + _t80*_t81 + _t82*_t83 - _t85*_t87 - _t90*_t92 + _t93*_t94 + _t94*_t95;
  out[13] = d3f_dx3;
  const double d3f_drs_dt2 = 0;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dx_dt = -_hc4[1]*_t59 + _t125*_t24 + _t126*_t24;
  out[15] = d3f_drs_dx_dt;
  const double d3f_drs_dx2 = _hc1[2]*_t134 + _hc1[3]*_t54 - 0.4e1*_hc1[4]*_t38 + _hc1[7]*_t21 + _hc1[7]*_t22 + _hc1[7]*_t8 + _hc4[5]*_t55 + _hc6[2]*_t127 + _t119*_t156 + _t120*_t156 - 0.980e3 / 0.27e2*_t123*_t62 + _t128*_t35 + _t130*_t37 - _t131*_t58 + _t132*_t133 + _t133*_t147 + _t133*_t149 - _t135*_t29 - _t136*_t137 - _t138*_t98 - _t139*_t46 - _t140*_t33 + _t140*_t49 - _t142*_t32 + _t143*_t35 + _t145*_t37 + _t150*_t51 + _t150*_t52 - _t151*_t39 + _t152*_t153 - 0.56e2 / 0.9e1*_t154*_t62 + _t155*_t50;
  out[16] = d3f_drs_dx2;
  const double d3f_drs2_dt = _t157*_t24;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dx = _hc1[1]*_t159 + _hc1[4]*_t158 - _hc4[0]*_t164 + _hc4[2]*_t161 + _t117*_t162 + _t119*_t166 + _t120*_t166 - _t121*_t163 - _t123*_t165 + _t147*_t160 + _t149*_t160;
  out[18] = d3f_drs2_dx;
  const double d3f_drs3 = _t119*_t167 + _t120*_t167 + _t167*_t67;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[20] = d4f_dt4;
  const double d4f_dx_dt3 = 0;
  out[21] = d4f_dx_dt3;
  const double d4f_dx2_dt2 = 0;
  out[22] = d4f_dx2_dt2;
  const double d4f_dx3_dt = _hc4[1]*_t173*_t80 - _t110*_t23 + _t112*_t172 + _t168*_t24 + _t169*_t23 - _t171*_t64 - _t171*_t65 - _t172*_t71 + _t174*_t24 - _t23*_t75;
  out[23] = d4f_dx3_dt;
  const double d4f_dx4 = -_hc0[4]*_t25 + _hc1[1]*_t100*_t117*_t3 + _hc1[10]*_t21 + _hc1[10]*_t22 + _hc1[10]*_t8 + _hc1[3]*_hc2[1]*_t214 + _hc1[3]*_t129*_t187 - 0.12e2*_hc1[3]*_t131 + _hc1[6]*_t190*_t56 + _hc1[6]*_t27*_t39 - 0.8e1*_hc1[6]*_t38 - 0.1960e4 / 0.27e2*_hc1[6]*_t60 + 0.120e3*_hc2[0]*_t192*_t47 - _hc4[2]*_t198*_t65 - 0.112e3 / 0.3e1*_hc4[5]*_t43 - 0.1960e4 / 0.9e1*_hc6[2]*_t97 - 0.1960e4 / 0.27e2*_hc6[3]*_t30 + (0.490e3 / 0.27e2)*_hc6[3]*_t36 + _hc6[4]*_t9 - _t101*_t181 + _t101*_t195 - _t101*_t208 - _t102*_t182 + _t102*_t196 - _t102*_t209 - _t103*_t105*_t198 + _t104*_t194 - 0.24e2*_t105*_t121 - 0.1960e4 / 0.9e1*_t105*_t123 + _t107*_t194 - _t117*_t199*_t26 - 0.96e2*_t13*_t85*_t91 + _t134*_t84 + _t144*_t187*_t26 + (0.28e2 / 0.9e1)*_t146*_t206 + (0.490e3 / 0.27e2)*_t148*_t206 - _t16*_t183 + _t168*_t189 - _t168*_t200 + (0.28e2 / 0.3e1)*_t173*_t188 + _t174*_t189 - _t174*_t200 + _t175*_t176 + _t175*_t216 + _t175*_t217 - _t177*_t178 + _t177*_t210 - _t179*_t180 + _t179*_t211 - _t180*_t204 - _t180*_t223 - _t181*_t70 - _t182*_t72 - 0.28e2 / 0.9e1*_t183*_t2 + 0.24e2*_t184*_t40 + _t185*_t224*_t225 + _t186*_t64 + _t186*_t65 + _t190*_t215*_t66 - 0.8e1*_t191*_t85 + _t193*_t76 + _t194*_t88 + _t195*_t70 + _t196*_t72 + (0.560e3 / 0.9e1)*_t197*_t2 + (0.9800e4 / 0.27e2)*_t197*_t5 - _t198*_t81 - _t199*_t83 + (0.1960e4 / 0.3e1)*_t2*_t207 - 0.560e3*_t2*_t220 - 0.112e3 / 0.3e1*_t201*_t32 + (0.560e3 / 0.3e1)*_t201*_t48 - 0.1960e4 / 0.9e1*_t202*_t32 + (0.9800e4 / 0.9e1)*_t202*_t48 - _t203*_t64 - _t203*_t65 + _t204*_t211 + 0.72e2*_t205*_t85 + (0.34300e5 / 0.9e1)*_t207*_t5 - _t208*_t70 - _t209*_t72 + _t211*_t223 + _t212*_t93 + _t212*_t95 - 0.144e3*_t213*_t90 + _t214*_t219 - 0.8e1*_t218*_t66 - 0.12e2*_t219*_t86 - 0.9800e4 / 0.3e1*_t220*_t5 + _t221*_t64 + _t221*_t65 - 0.1960e4 / 0.27e2*_t222*_t66 + _t224*_t226*_t227;
  out[24] = d4f_dx4;
  const double d4f_drs_dt3 = 0;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dx_dt2 = 0;
  out[26] = d4f_drs_dx_dt2;
  const double d4f_drs_dx2_dt = -0.56e2 / 0.9e1*_t126*_t170 - _t138*_t170 + _t228*_t24 - _t229*_t33 + _t229*_t49 + _t230*_t231 + _t232*_t24 + _t233*_t24;
  out[27] = d4f_drs_dx2_dt;
  const double d4f_drs_dx3 = _hc1[11]*_t21 + _hc1[11]*_t22 + _hc1[11]*_t8 - _hc1[2]*_t100*_t123 + _hc1[2]*_t118*_t215 - _hc1[2]*_t122*_t218 - _hc1[2]*_t124*_t222 - _hc1[4]*_t238*_t56 + _hc1[6]*_t54 - 0.6e1*_hc1[7]*_t38 + _hc1[7]*_t56*_t82 - 0.490e3 / 0.9e1*_hc1[7]*_t60 + _hc1[7]*_t89 - _hc2[1]*_t191*_t58 + _hc4[2]*_t185*_t230 + _hc6[3]*_t127 + _t104*_t235 + _t104*_t243 + _t107*_t235 + _t107*_t243 - _t110*_t140 - _t111*_t155 + _t112*_t239 + _t112*_t241 + _t112*_t248 + _t113*_t240 + _t113*_t242 + _t113*_t249 + _t115*_t234 + _t115*_t245 + _t116*_t228 + _t116*_t232 + _t116*_t233 + _t117*_t133*_t226 + _t117*_t150*_t82 - _t117*_t238*_t62 + _t118*_t252 - 0.12e2*_t121*_t133 - 0.980e3 / 0.9e1*_t123*_t133 - _t125*_t237 - _t126*_t237 + _t128*_t78 - _t13*_t152*_t92 + _t130*_t79 - 0.56e2 / 0.3e1*_t133*_t154 + _t134*_t247 - _t135*_t68 - _t136*_t14*_t69 + _t140*_t169 - _t140*_t75 - _t142*_t74 + _t143*_t78 + _t145*_t79 - 0.28e2 / 0.3e1*_t150*_t154 - _t151*_t84 + 0.18e2*_t152*_t205 + (0.2450e4 / 0.9e1)*_t155*_t94 + _t176*_t236 + _t216*_t236 + _t217*_t236 + _t227*_t246*_t82 - _t228*_t99 - _t233*_t99 - _t234*_t87 + _t235*_t88 - _t239*_t71 - _t240*_t73 - _t241*_t71 - _t242*_t73 + _t244*_t51 + _t244*_t52 - _t245*_t87 + _t246*_t250 + 0.3e1*_t246*_t67 - _t248*_t71 - _t249*_t73 + _t251*_t26;
  out[28] = d4f_drs_dx3;
  const double d4f_drs2_dt2 = 0;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dx_dt = -_hc4[1]*_t164 + _t231*_t253 + _t24*_t254;
  out[30] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx2 = _hc1[3]*_t159 - 0.8e1*_hc1[4]*_t151 + _hc1[7]*_t158 + _hc2[2]*_t153*_t63 - _hc2[2]*_t163*_t86 + _hc4[5]*_t161 + _hc5[2]*_hc6[2]*_t162 - _hc5[2]*_t137*_t63 - _t106*_t165*_t32 + _t106*_t50*_t63 + _t117*_t160*_t190 + _t119*_t261 + _t120*_t261 - 0.1960e4 / 0.27e2*_t123*_t160 + _t132*_t255 - _t14*_t157*_t29 + _t147*_t255 + _t147*_t256 + _t149*_t255 + _t149*_t256 - 0.112e3 / 0.9e1*_t154*_t160 + _t160*_t39*_t67 + _t176*_t258 + _t189*_t253 + _t190*_t227*_t257 + _t216*_t258 + _t217*_t258 - _t218*_t39*_t63 + (0.28e2 / 0.9e1)*_t225*_t257*_t3 + _t254*_t3*_t35 - 0.56e2 / 0.9e1*_t254*_t98 - _t259*_t33 + _t259*_t49 + _t260*_t3*_t37 - _t260*_t46;
  out[31] = d4f_drs2_dx2;
  const double d4f_drs3_dt = _t24*_t262;
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dx = -_hc4[0]*_t15*_t262 + _hc4[2]*_t262*_t4 + _t159*_t247 + _t167*_t215*_t6 - 0.2e1*_t167*_t218 - 0.490e3 / 0.27e2*_t167*_t222 + _t176*_t263 + _t216*_t263 + _t217*_t263 + _t251*_t63 + _t252*_t63*_t82;
  out[33] = d4f_drs3_dx;
  const double d4f_drs4 = _t176*_t264 + _t216*_t264 + _t217*_t264;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pjs18_f_z0_k, _KMAX)(const xc_func_type *p, double rs, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(js18_DME_SR_z0_k, _KMAX)(p, rs, x, t, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1];
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc0[2];
  out[3] = df_dx;
  const double df_drs = _hc0[3];
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[4];
  out[5] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[6] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[7] = d2f_du2;
  const double d2f_dx_dt = _hc0[5];
  out[8] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[9] = d2f_dx_du;
  const double d2f_dx2 = _hc0[6];
  out[10] = d2f_dx2;
  const double d2f_drs_dt = _hc0[7];
  out[11] = d2f_drs_dt;
  const double d2f_drs_du = 0;
  out[12] = d2f_drs_du;
  const double d2f_drs_dx = _hc0[8];
  out[13] = d2f_drs_dx;
  const double d2f_drs2 = _hc0[9];
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[10];
  out[15] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[16] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[17] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[18] = d3f_du3;
  const double d3f_dx_dt2 = _hc0[11];
  out[19] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[20] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[21] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc0[12];
  out[22] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[23] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[13];
  out[24] = d3f_dx3;
  const double d3f_drs_dt2 = _hc0[14];
  out[25] = d3f_drs_dt2;
  const double d3f_drs_du_dt = 0;
  out[26] = d3f_drs_du_dt;
  const double d3f_drs_du2 = 0;
  out[27] = d3f_drs_du2;
  const double d3f_drs_dx_dt = _hc0[15];
  out[28] = d3f_drs_dx_dt;
  const double d3f_drs_dx_du = 0;
  out[29] = d3f_drs_dx_du;
  const double d3f_drs_dx2 = _hc0[16];
  out[30] = d3f_drs_dx2;
  const double d3f_drs2_dt = _hc0[17];
  out[31] = d3f_drs2_dt;
  const double d3f_drs2_du = 0;
  out[32] = d3f_drs2_du;
  const double d3f_drs2_dx = _hc0[18];
  out[33] = d3f_drs2_dx;
  const double d3f_drs3 = _hc0[19];
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc0[20];
  out[35] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[36] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[37] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[38] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[39] = d4f_du4;
  const double d4f_dx_dt3 = _hc0[21];
  out[40] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[41] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[42] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[43] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc0[22];
  out[44] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[45] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[46] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc0[23];
  out[47] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[48] = d4f_dx3_du;
  const double d4f_dx4 = _hc0[24];
  out[49] = d4f_dx4;
  const double d4f_drs_dt3 = _hc0[25];
  out[50] = d4f_drs_dt3;
  const double d4f_drs_du_dt2 = 0;
  out[51] = d4f_drs_du_dt2;
  const double d4f_drs_du2_dt = 0;
  out[52] = d4f_drs_du2_dt;
  const double d4f_drs_du3 = 0;
  out[53] = d4f_drs_du3;
  const double d4f_drs_dx_dt2 = _hc0[26];
  out[54] = d4f_drs_dx_dt2;
  const double d4f_drs_dx_du_dt = 0;
  out[55] = d4f_drs_dx_du_dt;
  const double d4f_drs_dx_du2 = 0;
  out[56] = d4f_drs_dx_du2;
  const double d4f_drs_dx2_dt = _hc0[27];
  out[57] = d4f_drs_dx2_dt;
  const double d4f_drs_dx2_du = 0;
  out[58] = d4f_drs_dx2_du;
  const double d4f_drs_dx3 = _hc0[28];
  out[59] = d4f_drs_dx3;
  const double d4f_drs2_dt2 = _hc0[29];
  out[60] = d4f_drs2_dt2;
  const double d4f_drs2_du_dt = 0;
  out[61] = d4f_drs2_du_dt;
  const double d4f_drs2_du2 = 0;
  out[62] = d4f_drs2_du2;
  const double d4f_drs2_dx_dt = _hc0[30];
  out[63] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx_du = 0;
  out[64] = d4f_drs2_dx_du;
  const double d4f_drs2_dx2 = _hc0[31];
  out[65] = d4f_drs2_dx2;
  const double d4f_drs3_dt = _hc0[32];
  out[66] = d4f_drs3_dt;
  const double d4f_drs3_du = 0;
  out[67] = d4f_drs3_du;
  const double d4f_drs3_dx = _hc0[33];
  out[68] = d4f_drs3_dx;
  const double d4f_drs4 = _hc0[34];
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
  const double ta = tau[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = _t4/xc_powr(na, 1, 3);
  const double _t6 = xc_powr(na, -4, 3);
  const double _t7 = M_CBRT2;
  const double _t8 = xc_powr(gaa, 1, 2);
  const double _t9 = _t7*_t8;
  const double _t10 = _t6*_t9;
  const double _t11 = xc_powr(0.2e1, 2, 3);
  const double _t12 = _t11/xc_powr(na, 5, 3);
  const double _t13 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_spin_z0_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1] = {0.};
  if(!(_t13)) XC_CAT(pjs18_f_z0_k, _KMAX)(p, _t5, _t10, 0, _t12*ta, _hc1);
  const double _t14 = 0.2e1*my_piecewise3(_t13, 0, _hc0[0]*_hc1[0]);
  const double zk = _t14;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = (0.1e1 / 0.6e1)*_t6;
  const double _t16 = _t15*_t3;
  const double _t19 = xc_powr(na, -8, 3);
  const double _t20 = (0.5e1 / 0.3e1)*_t19;
  const double _t23 = xc_powr(na, -7, 3);
  const double _t24 = (0.4e1 / 0.3e1)*_t23;
  const double _t28 = 0.2e1*na;
  const double _t29 = (0.1e1 / _t8);
  const double _t30 = _t29*_t7;
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1] = {0.};
  if(!(_t13)) XC_CAT(pjs18_f_z0_k, _KMAX)(p, _t5, _t10, 0, 0, _hc2);
  const double _t17 = _hc0[1]*_hc1[0];
  const double _t18 = _hc2[1]*_t11;
  const double _t21 = _t18*_t20;
  const double _t22 = _hc1[3]*_t9;
  const double _t25 = _hc1[4]*_t3;
  const double _t26 = -_t15*_t25 - _t21*ta - _t22*_t24;
  const double _t27 = my_piecewise3(_t13, 0, _hc0[0]*_t26 - _t16*_t17);
  const double _t31 = _hc1[3]*_t30;
  const double _t32 = _hc0[0]*_t6;
  const double _t33 = 0.2e1*my_piecewise3(_t13, 0, (0.1e1 / 0.2e1)*_t31*_t32);
  const double _t34 = 0.2e1*my_piecewise3(_t13, 0, _hc0[0]*_hc2[1]*_t12);
  const double dF_dna = _t14 + _t27*_t28;
  const double dF_dgaa = _t33*na;
  const double dF_dta = _t34*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double _t35 = (0.2e1 / 0.9e1)*_t23;
  const double _t36 = _t3*_t35;
  const double _t38 = xc_powr(0.6e1, 2, 3);
  const double _t39 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t46 = xc_powr(na, -11, 3);
  const double _t47 = (0.40e2 / 0.9e1)*_t46;
  const double _t49 = xc_powr(na, -10, 3);
  const double _t50 = (0.28e2 / 0.9e1)*_t49;
  const double _t51 = _t11*_t20;
  const double _t53 = _t24*_t9;
  const double _t62 = xc_powr(0.12e2, 1, 3);
  const double _t63 = _t2*_t62;
  const double _t64 = _t29*_t63;
  const double _t65 = (0.1e1 / 0.12e2)*_t19;
  const double _t66 = _t64*_t65;
  const double _t69 = (0.2e1 / 0.3e1)*_t46;
  const double _t72 = (0.1e1 / (na * na * na * na));
  const double _t73 = (0.5e1 / 0.3e1)*_t72;
  const double _t74 = (0.2e1 / 0.3e1)*_t23;
  const double _t78 = M_CBRT3;
  const double _t79 = _t2*_t78;
  const double _t80 = (0.1e1 / (na * na * na));
  const double _t81 = (0.1e1 / 0.3e1)*_t80;
  const double _t82 = _t79*_t81;
  const double _t85 = (0.8e1 / 0.3e1)*_t72;
  const double _t86 = xc_powr(na, -13, 3);
  const double _t87 = (0.10e2 / 0.3e1)*_t86;
  const double _t93 = xc_powr(gaa, -3, 2);
  const double _t96 = (0.1e1 / gaa);
  const double _t37 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t40 = _hc0[2]*_t39;
  const double _t41 = _t38*_t40;
  const double _t42 = _t19*_t41;
  const double _t43 = _t26*_t3;
  const double _t44 = _hc0[1]*_t6;
  const double _t45 = (0.1e1 / 0.3e1)*_t44;
  const double _t48 = _t18*_t47;
  const double _t52 = _hc2[5]*_t51;
  const double _t54 = -_hc2[11]*_t16 - _hc2[8]*_t53 - _t52*ta;
  const double _t55 = _t51*_t54;
  const double _t56 = _hc2[8]*_t51;
  const double _t57 = -_hc1[10]*_t53 - _hc1[13]*_t16 - _t56*ta;
  const double _t58 = _hc2[11]*_t51;
  const double _t59 = -_hc1[13]*_t53 - _hc1[14]*_t16 - _t58*ta;
  const double _t60 = -_t16*_t59 + _t22*_t50 + _t25*_t35 + _t48*ta - _t53*_t57 - _t55*ta;
  const double _t61 = my_piecewise3(_t13, 0, _hc0[0]*_t60 + _t17*_t36 + _t37*_t42 - _t43*_t45);
  const double _t67 = _hc0[1]*_hc1[3];
  const double _t68 = _hc1[10]*_t11;
  const double _t70 = _hc2[8]*_t29;
  const double _t71 = _t70*ta;
  const double _t75 = _hc1[13]*_t64;
  const double _t76 = -_t31*_t74 - _t65*_t75 - _t68*_t69 - _t71*_t73;
  const double _t77 = my_piecewise3(_t13, 0, _hc0[0]*_t76 - _t66*_t67);
  const double _t83 = _hc0[1]*_hc2[1];
  const double _t84 = _hc2[8]*_t8;
  const double _t88 = _hc2[5]*_t7;
  const double _t89 = _t88*ta;
  const double _t90 = _hc2[11]*_t79;
  const double _t91 = -_t21 - _t81*_t90 - _t84*_t85 - _t87*_t89;
  const double _t92 = my_piecewise3(_t13, 0, _hc0[0]*_t91 - _t82*_t83);
  const double _t94 = _hc1[3]*_t93;
  const double _t95 = _t7*_t94;
  const double _t97 = _t68*_t96;
  const double _t98 = _hc0[0]*_t19;
  const double _t99 = 0.2e1*my_piecewise3(_t13, 0, -0.1e1 / 0.4e1*_t32*_t95 + (0.1e1 / 0.4e1)*_t97*_t98);
  const double _t100 = _hc0[0]*_t80;
  const double _t101 = 0.2e1*my_piecewise3(_t13, 0, _t100*_t70);
  const double _t102 = 0.2e1*_hc0[0];
  const double _t103 = 0.2e1*my_piecewise3(_t13, 0, _t102*_t49*_t88);
  const double d2F_dna2 = 0.4e1*_t27 + _t28*_t61;
  const double d2F_dna_dgaa = _t28*_t77 + _t33;
  const double d2F_dna_dta = _t28*_t92 + _t34;
  const double d2F_dgaa2 = _t99*na;
  const double d2F_dgaa_dta = _t101*na;
  const double d2F_dta2 = _t103*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double _t106 = (0.14e2 / 0.27e2)*_t49;
  const double _t107 = _t106*_t3;
  const double _t108 = (0.1e1 / 0.9e1)*_t46;
  const double _t111 = xc_powr(na, -14, 3);
  const double _t112 = (0.440e3 / 0.27e2)*_t111;
  const double _t114 = (0.280e3 / 0.27e2)*_t86;
  const double _t115 = _t11*_t47;
  const double _t117 = _t50*_t9;
  const double _t141 = _t108*_t64;
  const double _t145 = (0.14e2 / 0.9e1)*_t111;
  const double _t146 = xc_powi(na, -5);
  const double _t147 = (0.40e2 / 0.9e1)*ta;
  const double _t148 = (0.14e2 / 0.9e1)*_t49;
  const double _t149 = _t30*_t74;
  const double _t150 = _t11*_t69;
  const double _t152 = _t29*_t73;
  const double _t156 = _t152*ta;
  const double _t162 = (0.4e1 / 0.9e1)*_t72;
  const double _t163 = _t162*_t79;
  const double _t164 = (0.56e2 / 0.9e1)*_t146;
  const double _t165 = xc_powr(na, -16, 3);
  const double _t167 = _t8*_t85;
  const double _t169 = _t7*_t87;
  const double _t171 = _t51*ta;
  const double _t177 = _t19*_t63;
  const double _t179 = _t79*_t96;
  const double _t180 = (0.1e1 / 0.12e2)*_t72;
  const double _t181 = _t179*_t180;
  const double _t184 = (0.2e1 / 0.3e1)*_t146;
  const double _t185 = (0.1e1 / 0.3e1)*_t46;
  const double _t186 = (0.5e1 / 0.6e1)*ta;
  const double _t192 = _t3*_t86;
  const double _t193 = (0.1e1 / 0.6e1)*_t192;
  const double _t194 = (0.4e1 / 0.3e1)*_t165;
  const double _t195 = 0.3e1*_t72;
  const double _t196 = xc_powr(na, -17, 3);
  const double _t197 = _t11*_t196;
  const double _t198 = (0.5e1 / 0.3e1)*_t29;
  const double _t201 = (0.1e1 / 0.3e1)*_t11*_t111;
  const double _t202 = _t201*_t79;
  const double _t204 = xc_powi(na, -6);
  const double _t206 = (0.20e2 / 0.3e1)*ta;
  const double _t207 = (0.20e2 / 0.3e1)*_t86;
  const double _t210 = (0.8e1 / 0.3e1)*_t196;
  const double _t214 = _t72*_t93;
  const double _t216 = xc_powr(gaa, -5, 2);
  const double _t219 = (0.1e1 / (gaa * gaa));
  const double _t104 = _hc0[3]/M_PI;
  const double _t105 = _t104*_t72;
  const double _t109 = _hc1[0]*_t41;
  const double _t110 = _t4*_t44;
  const double _t113 = _t112*_t18;
  const double _t116 = _hc2[5]*_t115;
  const double _t118 = _hc2[15]*_t51;
  const double _t119 = -_hc2[19]*_t53 - _hc2[25]*_t16 - _t118*ta;
  const double _t120 = _t119*_t51;
  const double _t121 = _hc2[19]*_t51;
  const double _t122 = -_hc2[22]*_t53 - _hc2[28]*_t16 - _t121*ta;
  const double _t123 = _hc2[25]*_t51;
  const double _t124 = -_hc2[28]*_t53 - _hc2[31]*_t16 - _t123*ta;
  const double _t125 = _hc2[11]*_t36 + _hc2[8]*_t117 + _t116*ta - _t120*ta - _t122*_t53 - _t124*_t16;
  const double _t126 = _t125*_t51;
  const double _t127 = _hc2[8]*_t115;
  const double _t128 = _t122*_t51;
  const double _t129 = _hc2[22]*_t51;
  const double _t130 = -_hc1[24]*_t53 - _hc1[30]*_t16 - _t129*ta;
  const double _t131 = _hc2[28]*_t51;
  const double _t132 = -_hc1[30]*_t53 - _hc1[33]*_t16 - _t131*ta;
  const double _t133 = _hc1[10]*_t117 + _hc1[13]*_t36 + _t127*ta - _t128*ta - _t130*_t53 - _t132*_t16;
  const double _t134 = _hc2[11]*_t115;
  const double _t135 = _t124*_t51;
  const double _t136 = _hc2[31]*_t51;
  const double _t137 = -_hc1[33]*_t53 - _hc1[34]*_t16 - _t136*ta;
  const double _t138 = _hc1[13]*_t117 + _hc1[14]*_t36 - _t132*_t53 + _t134*ta - _t135*ta - _t137*_t16;
  const double _t139 = (0.4e1 / 0.9e1)*_t1*_t2*_t23*_t59 - _t106*_t25 + (0.80e2 / 0.9e1)*_t11*_t46*_t54*ta - _t113*ta - _t114*_t22 - _t126*ta - _t133*_t53 - _t138*_t16 + (0.56e2 / 0.9e1)*_t49*_t57*_t7*_t8;
  const double _t140 = my_piecewise3(_t13, 0, _hc0[0]*_t139 + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t23*_t26 + (0.1e1 / 0.12e2)*_hc0[2]*_t19*_t26*_t38*_t39 - _t105*_t37 - _t107*_t17 - _t108*_t109 - _t110*_t60);
  const double _t142 = xc_powr(0.3e1, 2, 3)*_t40;
  const double _t143 = _hc1[3]*_t142;
  const double _t144 = _t3*_t45;
  const double _t151 = _hc2[19]*ta;
  const double _t153 = _t7*_t70;
  const double _t154 = -_hc2[22]*_t150 - _hc2[28]*_t66 - _t151*_t152 - _t153*_t74;
  const double _t155 = _t154*_t51;
  const double _t157 = -_hc1[10]*_t149 - _hc1[24]*_t150 - _hc1[30]*_t66 - _hc2[22]*_t156;
  const double _t158 = -_hc1[13]*_t149 - _hc1[30]*_t150 - _hc1[33]*_t66 - _hc2[28]*_t156;
  const double _t159 = _t108*_t75 + _t145*_t68 + _t146*_t147*_t70 + _t148*_t31 - _t149*_t57 - _t155*ta - _t157*_t53 - _t158*_t16;
  const double _t160 = my_piecewise3(_t13, 0, _hc0[0]*_t159 + _t141*_t67 + (0.1e1 / 0.36e2)*_t143*_t29*_t72 - _t144*_t76);
  const double _t161 = xc_powr(0.18e2, 1, 3)*_hc2[1]*_t40;
  const double _t166 = _t165*_t88;
  const double _t168 = _hc2[15]*ta;
  const double _t170 = -_hc2[19]*_t167 - _hc2[25]*_t82 - _t168*_t169 - _t52;
  const double _t172 = -_hc2[22]*_t167 - _hc2[28]*_t82 - _t151*_t169 - _t56;
  const double _t173 = _hc2[25]*ta;
  const double _t174 = -_hc2[28]*_t167 - _hc2[31]*_t82 - _t169*_t173 - _t58;
  const double _t175 = -_t16*_t174 + _t162*_t90 + _t164*_t84 + (0.80e2 / 0.9e1)*_t166*ta - _t170*_t171 - _t172*_t53 + _t48 - _t55;
  const double _t176 = my_piecewise3(_t13, 0, _hc0[0]*_t175 - _t144*_t91 + (0.1e1 / 0.18e2)*_t161*_t86 + _t163*_t83);
  const double _t178 = _hc0[1]*_t94;
  const double _t182 = _hc0[1]*_hc1[10];
  const double _t183 = _hc1[24]*_t29;
  const double _t187 = _hc2[22]*_t7;
  const double _t188 = _t187*_t96;
  const double _t189 = _t165*_t188;
  const double _t190 = (0.1e1 / 0.24e2)*_hc1[13]*_t19*_t2*_t62*_t93 + (0.1e1 / 0.3e1)*_hc1[3]*_t23*_t7*_t93 - _hc1[30]*_t179*_t180 + (0.5e1 / 0.6e1)*_hc2[8]*_t72*_t93*ta - _t183*_t184 - _t185*_t97 - _t186*_t189;
  const double _t191 = my_piecewise3(_t13, 0, _hc0[0]*_t190 + (0.1e1 / 0.24e2)*_t177*_t178 - _t181*_t182);
  const double _t199 = -_hc2[28]*_t193*_t29 - _t151*_t197*_t198 - _t187*_t194 - _t195*_t70;
  const double _t200 = my_piecewise3(_t13, 0, _hc0[0]*_t199 - _hc0[1]*_t193*_t70);
  const double _t203 = _hc0[1]*_hc2[5];
  const double _t205 = _hc2[15]*_t204;
  const double _t208 = _hc2[19]*_t11;
  const double _t209 = _t208*_t8;
  const double _t211 = _hc2[25]*_t79;
  const double _t212 = -_t201*_t211 - _t205*_t206 - _t207*_t88 - _t209*_t210;
  const double _t213 = my_piecewise3(_t13, 0, _hc0[0]*_t212 - _t202*_t203);
  const double _t215 = _hc0[0]*_hc1[24];
  const double _t217 = _hc1[3]*_t7;
  const double _t218 = _t216*_t217;
  const double _t220 = 0.2e1*my_piecewise3(_t13, 0, (0.1e1 / 0.4e1)*_t214*_t215 + (0.3e1 / 0.8e1)*_t218*_t32 - 0.3e1 / 0.8e1*_t219*_t68*_t98);
  const double _t221 = _hc2[8]*_t93;
  const double _t222 = _hc0[0]*_t86;
  const double _t223 = 0.2e1*my_piecewise3(_t13, 0, -0.1e1 / 0.2e1*_t100*_t221 + (0.1e1 / 0.2e1)*_t188*_t222);
  const double _t224 = _t208*_t29;
  const double _t225 = _hc0[0]*_t111;
  const double _t226 = 0.2e1*my_piecewise3(_t13, 0, _t224*_t225);
  const double _t227 = 0.4e1*_hc0[0];
  const double _t228 = 0.2e1*my_piecewise3(_t13, 0, _hc2[15]*_t146*_t227);
  const double d3F_dna3 = _t140*_t28 + 0.6e1*_t61;
  const double d3F_dna2_dgaa = _t160*_t28 + 0.4e1*_t77;
  const double d3F_dna2_dta = _t176*_t28 + 0.4e1*_t92;
  const double d3F_dna_dgaa2 = _t191*_t28 + _t99;
  const double d3F_dna_dgaa_dta = _t101 + _t200*_t28;
  const double d3F_dna_dta2 = _t103 + _t213*_t28;
  const double d3F_dgaa3 = _t220*na;
  const double d3F_dgaa2_dta = _t223*na;
  const double d3F_dgaa_dta2 = _t226*na;
  const double d3F_dta3 = _t228*na;
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
#if _KMAX >= 4
  const double _t229 = (0.140e3 / 0.81e2)*_t86;
  const double _t231 = (0.2e1 / 0.3e1)*_t3;
  const double _t233 = _t11*ta;
  const double _t234 = _t112*_t233;
  const double _t235 = _t114*_t9;
  const double _t243 = _t115*ta;
  const double _t247 = (0.7e1 / 0.27e2)*_t111;
  const double _t248 = _t146*_t29;
  const double _t250 = _t11*_t145;
  const double _t253 = _t147*_t248;
  const double _t254 = _t148*_t30;
  const double _t256 = (0.2e1 / 0.9e1)*_t165;
  const double _t257 = (0.28e2 / 0.27e2)*_t146;
  const double _t258 = xc_powr(na, -19, 3);
  const double _t259 = _t164*_t8;
  const double _t260 = _t165*_t7;
  const double _t261 = (0.80e2 / 0.9e1)*_t260;
  const double _t262 = _t169*ta;
  const double _t268 = (0.1e1 / 0.18e2)*_t46*_t63;
  const double _t269 = _t184*_t29;
  const double _t270 = _t11*_t96;
  const double _t271 = _t185*_t270;
  const double _t273 = _t186*_t260;
  const double _t274 = _t273*_t96;
  const double _t275 = xc_powr(na, -20, 3);
  const double _t276 = _t194*_t7;
  const double _t277 = _t195*_t29;
  const double _t278 = _t196*_t198*_t233;
  const double _t279 = _t193*_t29;
  const double _t280 = (0.4e1 / 0.9e1)*_t197;
  const double _t281 = xc_powi(na, -7);
  const double _t282 = _t204*_t206;
  const double _t283 = _t207*_t7;
  const double _t284 = _t11*_t210*_t8;
  const double _t285 = (0.1e1 / 0.16e2)*_t216;
  const double _t286 = (0.1e1 / 0.8e1)*_t219;
  const double _t287 = (0.1e1 / 0.24e2)*_t165*_t93;
  const double _t288 = _t216*_t72;
  const double _t290 = (0.1e1 / 0.12e2)*_t196*_t270*_t79;
  const double _t291 = _t11*_t275;
  const double _t292 = (0.1e1 / 0.3e1)*_t204*_t29*_t79;
  const double _t294 = _t231*_t258;
  const double _t230 = _hc0[1]*_t3;
  const double _t232 = _t18*_t196;
  const double _t236 = -_hc2[40]*_t171 - _hc2[44]*_t53 - _hc2[54]*_t16;
  const double _t237 = -_hc2[50]*_t171 - _hc2[54]*_t53 - _hc2[60]*_t16;
  const double _t238 = -_hc2[44]*_t171 - _hc2[47]*_t53 - _hc2[57]*_t16;
  const double _t239 = -_hc2[54]*_t171 - _hc2[57]*_t53 - _hc2[63]*_t16;
  const double _t240 = _hc2[22]*_t117 + _hc2[28]*_t36 + _t115*_t151 - _t16*_t239 - _t171*_t236 - _t238*_t53;
  const double _t241 = -_hc2[60]*_t171 - _hc2[63]*_t53 - _hc2[66]*_t16;
  const double _t242 = _hc2[28]*_t117 + _hc2[31]*_t36 + _t115*_t173 - _t16*_t241 - _t171*_t237 - _t239*_t53;
  const double _t244 = -_hc1[59]*_t53 - _hc1[65]*_t16 - _hc2[57]*_t171;
  const double _t245 = -_hc1[65]*_t53 - _hc1[68]*_t16 - _hc2[63]*_t171;
  const double _t246 = _hc1[30]*_t117 + _hc1[33]*_t36 + _hc2[28]*_t243 - _t16*_t245 - _t171*_t239 - _t244*_t53;
  const double _t249 = (0.1e1 / 0.9e1)*_t142;
  const double _t251 = -_hc2[44]*_t156 - _hc2[47]*_t150 - _hc2[57]*_t66 - _t187*_t29*_t74;
  const double _t252 = -_hc2[28]*_t149 - _hc2[54]*_t156 - _hc2[57]*_t150 - _hc2[63]*_t66;
  const double _t255 = -_hc1[30]*_t149 - _hc1[59]*_t150 - _hc1[65]*_t66 - _hc2[57]*_t156;
  const double _t263 = (0.8e1 / 0.3e1)*_hc2[44];
  const double _t264 = _t263*_t8;
  const double _t265 = -_hc2[40]*_t262 - _hc2[54]*_t82 - _t121 - _t264*_t72;
  const double _t266 = -_hc2[50]*_t262 - _hc2[54]*_t167 - _hc2[60]*_t82 - _t123;
  const double _t267 = -_hc2[54]*_t262 - _hc2[57]*_t167 - _hc2[63]*_t82 - _t131;
  const double _t272 = _hc2[44]*_t96;
  const double _t289 = _hc2[47]*_t93;
  const double _t293 = _hc2[40]/xc_powr(na, 22, 3);
  const double d4F_dna4 = 0.8e1*_t140 + _t28*my_piecewise3(_t13, 0, _hc0[0]*(-0.440e3 / 0.9e1*_t11*_t111*_t54*ta + (0.40e2 / 0.3e1)*_t125*_t233*_t46 + (0.28e2 / 0.3e1)*_t133*_t49*_t9 + _t138*_t3*_t74 - _t148*_t3*_t59 - _t16*(-_hc1[13]*_t235 - _hc1[14]*_t107 - _hc2[11]*_t234 + (0.4e1 / 0.9e1)*_t1*_t137*_t2*_t23 + (0.80e2 / 0.9e1)*_t11*_t124*_t46*ta + (0.56e2 / 0.9e1)*_t132*_t49*_t7*_t8 - _t16*(_hc1[33]*_t117 + _hc1[34]*_t36 + _hc2[31]*_t243 - _t16*(-_hc1[68]*_t53 - _hc1[69]*_t16 - _hc2[66]*_t171) - _t171*_t241 - _t245*_t53) - _t171*_t242 - _t246*_t53) + (0.3640e4 / 0.81e2)*_t165*_t22 - _t171*(-_hc2[11]*_t107 - _hc2[5]*_t234 - _hc2[8]*_t235 + (0.4e1 / 0.9e1)*_t1*_t124*_t2*_t23 + (0.80e2 / 0.9e1)*_t11*_t119*_t46*ta + (0.56e2 / 0.9e1)*_t122*_t49*_t7*_t8 - _t16*_t242 - _t171*(_hc2[19]*_t117 + _hc2[25]*_t36 + _t115*_t168 - _t16*_t237 - _t171*(-_hc2[35]*_t171 - _hc2[40]*_t53 - _hc2[50]*_t16) - _t236*_t53) - _t240*_t53) + _t229*_t25 + (0.6160e4 / 0.81e2)*_t232*ta - _t53*(-_hc1[10]*_t235 - _hc1[13]*_t107 - _hc2[8]*_t234 + (0.4e1 / 0.9e1)*_t1*_t132*_t2*_t23 + (0.80e2 / 0.9e1)*_t11*_t122*_t46*ta + (0.56e2 / 0.9e1)*_t130*_t49*_t7*_t8 - _t16*_t246 - _t171*_t240 - _t53*(_hc1[24]*_t117 + _hc1[30]*_t36 + _hc2[22]*_t243 - _t16*_t244 - _t171*_t238 - _t53*(-_hc1[49]*_t53 - _hc1[59]*_t16 - _hc2[47]*_t171))) - 0.280e3 / 0.9e1*_t57*_t86*_t9) - 0.56e2 / 0.27e2*_hc0[1]*_t43*_t49 + (0.1e1 / 0.216e3)*_hc0[4]*_hc1[0]*_t1*_t165/(M_PI * M_CBRTPI) + (0.2e1 / 0.9e1)*_hc1[0]*_t104*_t146 - 0.1e1 / 0.9e1*_t105*_t26 + (0.40e2 / 0.81e2)*_t109*_t111 - _t139*_t231*_t44 + _t17*_t229*_t3 + _t230*_t24*_t60 - 0.4e1 / 0.9e1*_t26*_t41*_t46 + (0.1e1 / 0.6e1)*_t42*_t60);
  const double d4F_dna3_dgaa = 0.6e1*_t160 + _t28*my_piecewise3(_t13, 0, _hc0[0]*((0.4e1 / 0.9e1)*_t1*_t158*_t2*_t23 + (0.80e2 / 0.9e1)*_t11*_t154*_t46*ta - _t133*_t149 + (0.56e2 / 0.9e1)*_t157*_t49*_t7*_t8 - _t16*(_hc1[13]*_t254 + _hc1[30]*_t250 + _hc1[33]*_t141 + _hc2[28]*_t253 - _t132*_t149 - _t16*(-_hc1[33]*_t149 - _hc1[65]*_t150 - _hc1[68]*_t66 - _hc2[63]*_t156) - _t171*_t252 - _t255*_t53) - _t171*(_hc2[22]*_t250 + _hc2[28]*_t141 - _t122*_t149 + _t148*_t153 + (0.40e2 / 0.9e1)*_t151*_t248 - _t16*_t252 - _t171*(-_hc2[19]*_t149 - _hc2[40]*_t156 - _hc2[44]*_t150 - _hc2[54]*_t66) - _t251*_t53) - 0.140e3 / 0.27e2*_t196*_t68 - 0.440e3 / 0.27e2*_t204*_t71 - _t247*_t75 + (0.28e2 / 0.9e1)*_t29*_t49*_t57*_t7 - 0.140e3 / 0.27e2*_t31*_t86 - _t53*(_hc1[10]*_t254 + _hc1[24]*_t250 + _hc1[30]*_t141 + _hc2[22]*_t253 - _t130*_t149 - _t16*_t255 - _t171*_t251 - _t53*(-_hc1[49]*_t150 - _hc1[59]*_t66 - _hc2[47]*_t156 - _t183*_t7*_t74))) + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t23*_t76 + (0.1e1 / 0.12e2)*_hc0[2]*_t19*_t38*_t39*_t76 - _hc1[3]*_t248*_t249 - 0.1e1 / 0.72e2*_t104*_t165*_t31 - _t110*_t159 - _t247*_t64*_t67);
  const double d4F_dna3_dta = 0.6e1*_t176 + _t28*my_piecewise3(_t13, 0, _hc0[0]*((0.4e1 / 0.9e1)*_t1*_t174*_t2*_t23 + (0.80e2 / 0.9e1)*_t11*_t170*_t46*ta + (0.80e2 / 0.9e1)*_t11*_t46*_t54 - _t113 - _t126 - _t16*(_hc2[28]*_t259 + _hc2[31]*_t163 + _t134 - _t135 - _t16*(-_hc2[60]*_t262 - _hc2[63]*_t167 - _hc2[66]*_t82 - _t136) - _t171*_t266 + _t173*_t261 - _t267*_t53) - _t171*(_hc2[19]*_t259 + _hc2[25]*_t163 + _t116 - _t120 - _t16*_t266 + _t168*_t261 - _t171*(-_hc2[35]*_t262 - _hc2[40]*_t167 - _hc2[50]*_t82 - _t118) - _t265*_t53) + (0.56e2 / 0.9e1)*_t172*_t49*_t7*_t8 - 0.560e3 / 0.27e2*_t204*_t84 - _t257*_t90 - 0.880e3 / 0.27e2*_t258*_t89 - _t53*(_hc2[22]*_t259 + _hc2[28]*_t163 + _t127 - _t128 + _t151*_t261 - _t16*_t267 - _t171*_t265 - _t53*(-_hc2[44]*_t262 - _hc2[47]*_t167 - _hc2[57]*_t82 - _t129))) + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t23*_t91 + (0.1e1 / 0.12e2)*_hc0[2]*_t19*_t38*_t39*_t91 - 0.1e1 / 0.36e2*_t104*_t232 - _t110*_t175 - _t161*_t256 - _t257*_t79*_t83);
  const double d4F_dna2_dgaa2 = 0.4e1*_t191 + _t28*my_piecewise3(_t13, 0, _hc0[0]*((0.7e1 / 0.9e1)*_hc1[10]*_t11*_t111*_t96 - _hc1[13]*_t268*_t93 + (0.14e2 / 0.9e1)*_hc1[24]*_t204*_t29 + (0.1e1 / 0.9e1)*_hc1[30]*_t146*_t2*_t78*_t96 + (0.20e2 / 0.9e1)*_hc2[22]*_t258*_t7*_t96*ta - 0.20e2 / 0.9e1*_t146*_t221*ta - _t157*_t24*_t30 - _t16*((0.1e1 / 0.3e1)*_hc1[13]*_t23*_t7*_t93 - _hc1[30]*_t271 + (0.1e1 / 0.24e2)*_hc1[33]*_t19*_t2*_t62*_t93 - _hc1[59]*_t269 - _hc1[65]*_t181 + (0.5e1 / 0.6e1)*_hc2[28]*_t72*_t93*ta - _hc2[57]*_t274) - _t171*((0.5e1 / 0.6e1)*_hc2[19]*_t72*_t93*ta - _hc2[22]*_t271 + (0.1e1 / 0.24e2)*_hc2[28]*_t19*_t2*_t62*_t93 - _hc2[47]*_t269 - _hc2[57]*_t181 + (0.1e1 / 0.3e1)*_hc2[8]*_t23*_t7*_t93 - _t272*_t273) + (0.1e1 / 0.3e1)*_t23*_t57*_t7*_t93 - 0.7e1 / 0.9e1*_t49*_t95 - _t53*((0.1e1 / 0.3e1)*_hc1[10]*_t23*_t7*_t93 - _hc1[24]*_t271 + (0.1e1 / 0.24e2)*_hc1[30]*_t19*_t2*_t62*_t93 - _hc1[49]*_t269 - _hc1[59]*_t181 + (0.5e1 / 0.6e1)*_hc2[22]*_t72*_t93*ta - _hc2[47]*_t274)) + (0.1e1 / 0.72e2)*_hc1[10]*_t142*_t260*_t96 - 0.1e1 / 0.72e2*_t143*_t214 - _t144*_t190 + (0.1e1 / 0.9e1)*_t146*_t179*_t182 - _t178*_t268);
  const double d4F_dna2_dgaa_dta = 0.4e1*_t200 + _t28*my_piecewise3(_t13, 0, _hc0[0]*((0.40e2 / 0.9e1)*_hc2[19]*_t11*_t275*_t29*ta + (0.28e2 / 0.9e1)*_hc2[22]*_t258*_t7 + (0.2e1 / 0.9e1)*_hc2[28]*_t1*_t165*_t2*_t29 + (0.68e2 / 0.9e1)*_hc2[8]*_t146*_t29 - _t149*_t172 - _t155 - _t16*(-_hc2[28]*_t277 - _hc2[54]*_t278 - _hc2[57]*_t276 - _hc2[63]*_t279) - _t171*(-_hc2[19]*_t277 - _hc2[40]*_t278 - _hc2[44]*_t276 - _hc2[54]*_t279) - _t53*(-_hc2[22]*_t277 - _hc2[44]*_t278 - _hc2[47]*_t276 - _hc2[57]*_t279)) - _t144*_t199 + (0.1e1 / 0.36e2)*_t196*_t41*_t70 + _t230*_t256*_t70);
  const double d4F_dna2_dta2 = 0.4e1*_t213 + _t28*my_piecewise3(_t13, 0, _hc0[0]*(-0.10e2 / 0.3e1*_t11*_t170*_t19 - _t16*(-_hc2[25]*_t283 - _hc2[50]*_t282 - _hc2[54]*_t284 - _hc2[60]*_t202) + (0.160e3 / 0.9e1)*_t166 + (0.160e3 / 0.9e1)*_t168*_t281 - _t171*(-_hc2[15]*_t283 - _hc2[35]*_t282 - _hc2[40]*_t284 - _hc2[50]*_t202) + (0.56e2 / 0.9e1)*_t209*_t275 + _t211*_t280 - _t53*(-_hc2[19]*_t283 - _hc2[40]*_t282 - _hc2[54]*_t202 - _t197*_t264)) + _hc2[5]*_t204*_t249 - _t144*_t212 + _t203*_t280*_t79);
  const double d4F_dna_dgaa3 = _t220 + _t28*my_piecewise3(_t13, 0, _hc0[0]*((0.1e1 / 0.2e1)*_hc1[10]*_t11*_t219*_t46 - _hc1[13]*_t177*_t285 + (0.1e1 / 0.8e1)*_hc1[30]*_t2*_t219*_t72*_t78 - 0.1e1 / 0.3e1*_hc1[49]*_t258*_t7*_t96 - _hc1[59]*_t287*_t3 + (0.5e1 / 0.4e1)*_hc2[22]*_t165*_t219*_t7*ta - 0.5e1 / 0.4e1*_hc2[8]*_t288*ta - 0.1e1 / 0.2e1*_t218*_t23 - 0.5e1 / 0.12e2*_t233*_t275*_t289) - _hc1[24]*_t230*_t287 - _t177*_t285*_t67 + _t182*_t286*_t72*_t79);
  const double d4F_dna_dgaa2_dta = _t223 + _t28*my_piecewise3(_t13, 0, _hc0[0]*((0.5e1 / 0.6e1)*_hc2[19]*_t11*_t196*_t93*ta + (0.1e1 / 0.12e2)*_hc2[28]*_t1*_t2*_t86*_t93 - 0.2e1 / 0.3e1*_hc2[47]*_t29*_t291 - _hc2[57]*_t290 + (0.3e1 / 0.2e1)*_hc2[8]*_t72*_t93 - 0.3e1 / 0.2e1*_t189 - 0.5e1 / 0.3e1*_t272*_t281*ta) - _hc0[1]*_hc2[22]*_t290 + (0.1e1 / 0.12e2)*_hc0[1]*_t192*_t221);
  const double d4F_dna_dgaa_dta2 = _t226 + _t28*my_piecewise3(_t13, 0, _hc0[0]*(-_hc2[54]*_t292 - 0.14e2 / 0.3e1*_t196*_t224 - _t263*_t281 - 0.10e2 / 0.3e1*_t293*_t30*ta) - _hc0[1]*_hc2[19]*_t292);
  const double d4F_dna_dta3 = _t228 + _t28*my_piecewise3(_t13, 0, _hc0[0]*(-_hc2[35]*_t11*_t206/xc_powr(na, 23, 3) - _hc2[50]*_t294 - 0.20e2*_t205 - 0.16e2 / 0.3e1*_t293*_t9) - _hc0[1]*_hc2[15]*_t294);
  const double d4F_dgaa4 = _t28*my_piecewise3(_t13, 0, _hc0[0]*_hc1[49]*_t260*_t286 - 0.3e1 / 0.4e1*_t215*_t288 - 0.15e2 / 0.16e2*_t217*_t32/xc_powr(gaa, 7, 2) + (0.15e2 / 0.16e2)*_t68*_t98/(gaa * gaa * gaa));
  const double d4F_dgaa3_dta = _t28*my_piecewise3(_t13, 0, (0.1e1 / 0.4e1)*_hc0[0]*_t197*_t289 + (0.3e1 / 0.4e1)*_hc2[8]*_t100*_t216 - 0.3e1 / 0.4e1*_t187*_t219*_t222);
  const double d4F_dgaa2_dta2 = _t28*my_piecewise3(_t13, 0, _hc0[0]*_hc2[44]*_t204*_t96 - 0.1e1 / 0.2e1*_t208*_t225*_t93);
  const double d4F_dgaa_dta3 = _t28*my_piecewise3(_t13, 0, _hc2[40]*_t102*_t258*_t30);
  const double d4F_dta4 = _t28*my_piecewise3(_t13, 0, _hc2[35]*_t227*_t291);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double ta = tau[0];
  const double tb = tau[1];

  const double _t1 = -nb;
  const double _t2 = _t1 + na;
  const double _t3 = na + nb;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = xc_powr(0.6e1, 1, 3);
  const double _t7 = (0.1e1 / (M_CBRTPI));
  const double _t8 = _t6*_t7;
  const double _t9 = (0.1e1 / 0.2e1)*_t8/xc_powr(_t3, 1, 3);
  const double _t10 = xc_powr(gaa, 1, 2);
  const double _t11 = xc_powr(na, -4, 3);
  const double _t12 = _t10*_t11;
  const double _t13 = xc_powr(na, -5, 3);
  const double _t14 = xc_powr(gbb, 1, 2);
  const double _t15 = xc_powr(nb, -4, 3);
  const double _t16 = _t14*_t15;
  const double _t17 = xc_powr(nb, -5, 3);
  const double _t18 = -p->dens_threshold + na <= 0;
  const double _t19 = -_t1 - p->dens_threshold <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t18)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t9, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1] = {0.};
  if(!(_t18)) XC_CAT(pjs18_f_k, _KMAX)(p, _t9, _hc0[0], _t12, 0, _t13*ta, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t5, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t19)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t9, _hc3[0], _hc4);
  double _hc5[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1] = {0.};
  if(!(_t19)) XC_CAT(pjs18_f_k, _KMAX)(p, _t9, _hc3[0], _t16, 0, _t17*tb, _hc5);
  const double _t20 = my_piecewise3(_t18, 0, _hc1[0]*_hc2[0]) + my_piecewise3(_t19, 0, _hc4[0]*_hc5[0]);
  const double zk = _t20;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t21 = xc_powr(_t3, -4, 3);
  const double _t22 = _t21*_t8;
  const double _t23 = (0.1e1 / 0.6e1)*_t22;
  const double _t25 = -_t4;
  const double _t26 = (0.1e1 / (_t3 * _t3));
  const double _t27 = _t2*_t26;
  const double _t28 = _t25 + _t27;
  const double _t35 = -_t28;
  const double _t38 = xc_powr(na, -8, 3);
  const double _t39 = (0.5e1 / 0.3e1)*_t38;
  const double _t41 = xc_powr(na, -7, 3);
  const double _t42 = _t10*_t41;
  const double _t43 = (0.4e1 / 0.3e1)*_t42;
  const double _t48 = _t27 + _t4;
  const double _t49 = -_t48;
  const double _t56 = xc_powr(nb, -8, 3);
  const double _t57 = (0.5e1 / 0.3e1)*_t56;
  const double _t60 = xc_powr(nb, -7, 3);
  const double _t61 = (0.4e1 / 0.3e1)*_t60;
  const double _t66 = (0.1e1 / _t10);
  const double _t71 = (0.1e1 / _t14);
  double _hc6[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1] = {0.};
  if(!(_t18)) XC_CAT(pjs18_f_k, _KMAX)(p, _t9, _hc0[0], _t12, 0, 0, _hc6);
  double _hc7[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1] = {0.};
  if(!(_t19)) XC_CAT(pjs18_f_k, _KMAX)(p, _t9, _hc3[0], _t16, 0, 0, _hc7);
  const double _t24 = _hc5[5]*_t23;
  const double _t29 = _hc3[1]*_t28;
  const double _t30 = _hc5[4]*_t29 - _t24;
  const double _t31 = -_hc4[2]*_t23;
  const double _t32 = _hc4[1]*_t29 + _t31;
  const double _t33 = my_piecewise3(_t19, 0, _hc4[0]*_t30 + _hc5[0]*_t32);
  const double _t34 = -_hc1[2]*_t23;
  const double _t36 = _hc0[1]*_t35;
  const double _t37 = _hc1[1]*_t36 + _t34;
  const double _t40 = _hc6[1]*_t39;
  const double _t44 = _hc2[5]*_t23;
  const double _t45 = _hc0[1]*_hc2[4]*_t35 - _hc2[3]*_t43 - _t40*ta - _t44;
  const double _t46 = my_piecewise3(_t18, 0, _hc1[0]*_t45 + _hc2[0]*_t37);
  const double _t47 = _t33 + _t46;
  const double _t50 = _hc0[1]*_t49;
  const double _t51 = _hc2[4]*_t50 - _t44;
  const double _t52 = _hc1[1]*_t50 + _t34;
  const double _t53 = my_piecewise3(_t18, 0, _hc1[0]*_t51 + _hc2[0]*_t52);
  const double _t54 = _hc3[1]*_t48;
  const double _t55 = _hc4[1]*_t54 + _t31;
  const double _t58 = _hc7[1]*_t57;
  const double _t59 = _hc5[3]*_t14;
  const double _t62 = _hc3[1]*_hc5[4]*_t48 - _t24 - _t58*tb - _t59*_t61;
  const double _t63 = my_piecewise3(_t19, 0, _hc4[0]*_t62 + _hc5[0]*_t55);
  const double _t64 = _t53 + _t63;
  const double _t65 = _hc1[0]*_t11;
  const double _t67 = _hc2[3]*_t66;
  const double _t68 = (0.1e1 / 0.2e1)*_t67;
  const double _t69 = my_piecewise3(_t18, 0, _t65*_t68);
  const double _t70 = _hc4[0]*_t15;
  const double _t72 = _hc5[3]*_t71;
  const double _t73 = (0.1e1 / 0.2e1)*_t72;
  const double _t74 = my_piecewise3(_t19, 0, _t70*_t73);
  const double _t75 = _hc6[1]*_t13;
  const double _t76 = my_piecewise3(_t18, 0, _hc1[0]*_t75);
  const double _t77 = _hc7[1]*_t17;
  const double _t78 = my_piecewise3(_t19, 0, _hc4[0]*_t77);
  const double dF_dna = _t20 + _t3*_t47;
  const double dF_dnb = _t20 + _t3*_t64;
  const double dF_dgaa = _t3*_t69;
  const double dF_dgbb = _t3*_t74;
  const double dF_dta = _t3*_t76;
  const double dF_dtb = _t3*_t78;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double _t80 = xc_powr(_t3, -7, 3);
  const double _t81 = (0.2e1 / 0.9e1)*_t80;
  const double _t82 = _t8*_t81;
  const double _t84 = 0.2e1*_t26;
  const double _t85 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t86 = 0.2e1*_t85;
  const double _t87 = _t2*_t86;
  const double _t88 = -_t84 + _t87;
  const double _t89 = -_t88;
  const double _t91 = (_t28 * _t28);
  const double _t108 = (_t35 * _t35);
  const double _t115 = xc_powr(na, -11, 3);
  const double _t116 = (0.40e2 / 0.9e1)*_t115;
  const double _t119 = xc_powr(na, -10, 3);
  const double _t120 = (0.28e2 / 0.9e1)*_t119;
  const double _t148 = _t14*_t61;
  const double _t175 = _t84 + _t87;
  const double _t177 = (_t49 * _t49);
  const double _t183 = -_t175;
  const double _t185 = (_t48 * _t48);
  const double _t194 = xc_powr(nb, -10, 3);
  const double _t195 = (0.28e2 / 0.9e1)*_t194;
  const double _t196 = xc_powr(nb, -11, 3);
  const double _t197 = (0.40e2 / 0.9e1)*_t196;
  const double _t203 = (0.2e1 / 0.3e1)*_t115;
  const double _t204 = (0.2e1 / 0.3e1)*_t41;
  const double _t207 = (0.1e1 / (na * na * na * na));
  const double _t208 = (0.5e1 / 0.6e1)*_t207;
  const double _t209 = (0.1e1 / 0.12e2)*_t22;
  const double _t210 = _t11*_t66;
  const double _t216 = _t15*_t71;
  const double _t217 = _t209*_t216;
  const double _t223 = (0.1e1 / 0.2e1)*_t210;
  const double _t226 = (0.2e1 / 0.3e1)*_t196;
  const double _t227 = (0.2e1 / 0.3e1)*_t60;
  const double _t230 = (0.1e1 / (nb * nb * nb * nb));
  const double _t231 = (0.5e1 / 0.6e1)*_t230;
  const double _t234 = xc_powr(na, -13, 3);
  const double _t235 = (0.5e1 / 0.3e1)*ta;
  const double _t236 = _t234*_t235;
  const double _t238 = (0.4e1 / 0.3e1)*_t207;
  const double _t248 = xc_powr(nb, -13, 3);
  const double _t249 = (0.5e1 / 0.3e1)*tb;
  const double _t250 = _t248*_t249;
  const double _t252 = (0.4e1 / 0.3e1)*_t230;
  const double _t256 = (0.1e1 / gaa);
  const double _t258 = xc_powr(gaa, -3, 2);
  const double _t263 = (0.1e1 / gbb);
  const double _t265 = xc_powr(gbb, -3, 2);
  const double _t269 = (0.1e1 / (na * na * na));
  const double _t273 = (0.1e1 / (nb * nb * nb));
  const double _t79 = 0.2e1*_t32;
  const double _t83 = _hc5[5]*_t82;
  const double _t90 = _hc3[1]*_t89;
  const double _t92 = _hc3[2]*_t91;
  const double _t93 = _hc5[20]*_t23;
  const double _t94 = _hc5[19]*_t29 - _t93;
  const double _t95 = _hc5[19]*_t23;
  const double _t96 = _hc5[15]*_t29 - _t95;
  const double _t97 = _hc5[4]*_t90 + _hc5[4]*_t92 - _t23*_t94 + _t29*_t96 + _t83;
  const double _t98 = _hc4[2]*_t82;
  const double _t99 = -_hc4[5]*_t23;
  const double _t100 = _hc4[4]*_t29 + _t99;
  const double _t101 = -_hc4[4]*_t23;
  const double _t102 = _hc4[3]*_t29 + _t101;
  const double _t103 = _hc4[1]*_t90 + _hc4[1]*_t92 - _t100*_t23 + _t102*_t29 + _t98;
  const double _t104 = my_piecewise3(_t19, 0, _hc4[0]*_t97 + _hc5[0]*_t103 + _t30*_t79);
  const double _t105 = 0.2e1*_t37;
  const double _t106 = _hc1[2]*_t82;
  const double _t107 = _hc0[1]*_t88;
  const double _t109 = _hc0[2]*_t108;
  const double _t110 = -_hc1[5]*_t23;
  const double _t111 = _hc1[4]*_t36 + _t110;
  const double _t112 = -_hc1[4]*_t23;
  const double _t113 = _hc1[3]*_t36 + _t112;
  const double _t114 = _hc1[1]*_t107 + _hc1[1]*_t109 + _t106 - _t111*_t23 + _t113*_t36;
  const double _t117 = _hc6[1]*_t116;
  const double _t118 = _hc2[3]*_t10;
  const double _t121 = _hc2[5]*_t8;
  const double _t122 = _t121*_t81;
  const double _t123 = _hc6[6]*_t39;
  const double _t124 = _hc6[16]*_t23;
  const double _t125 = _hc0[1]*_hc6[12]*_t35 - _hc6[9]*_t43 - _t123*ta - _t124;
  const double _t126 = _t125*_t39;
  const double _t127 = _hc6[9]*_t39;
  const double _t128 = _hc2[18]*_t23;
  const double _t129 = _hc0[1]*_hc2[14]*_t35 - _hc2[11]*_t43 - _t127*ta - _t128;
  const double _t130 = _hc6[16]*_t39;
  const double _t131 = _hc2[20]*_t23;
  const double _t132 = _hc0[1]*_hc2[19]*_t35 - _hc2[18]*_t43 - _t130*ta - _t131;
  const double _t133 = _hc6[12]*_t39;
  const double _t134 = _hc2[19]*_t23;
  const double _t135 = _hc2[14]*_t43 + _t133*ta + _t134;
  const double _t136 = _hc0[1]*_hc2[15]*_t35 - _t135;
  const double _t137 = _hc2[4]*_t107 + _hc2[4]*_t109 + _t117*ta + _t118*_t120 + _t122 - _t126*ta - _t129*_t43 - _t132*_t23 + _t136*_t36;
  const double _t138 = my_piecewise3(_t18, 0, _hc1[0]*_t137 + _hc2[0]*_t114 + _t105*_t45);
  const double _t139 = _t104 + _t138;
  const double _t140 = _hc4[3]*_t54 + _t101;
  const double _t141 = _hc3[2]*_t28;
  const double _t142 = _hc4[1]*_t141;
  const double _t143 = _hc3[1]*_t87;
  const double _t144 = _hc4[4]*_t54 + _t99;
  const double _t145 = -_t144*_t23 + _t98;
  const double _t146 = -_hc4[1]*_t143 + _t140*_t29 + _t142*_t48 + _t145;
  const double _t147 = _hc7[12]*_t57;
  const double _t149 = _hc3[1]*_hc5[15]*_t48 - _hc5[14]*_t148 - _t147*tb - _t95;
  const double _t150 = _hc5[4]*_t48;
  const double _t151 = _hc7[16]*_t57;
  const double _t152 = _hc3[1]*_hc5[19]*_t48 - _hc5[18]*_t148 - _t151*tb - _t93;
  const double _t153 = -_t152*_t23 + _t83;
  const double _t154 = -_hc5[4]*_t143 + _t141*_t150 + _t149*_t29 + _t153;
  const double _t155 = my_piecewise3(_t19, 0, _hc4[0]*_t154 + _hc5[0]*_t146 + _t30*_t55 + _t32*_t62);
  const double _t156 = _hc1[3]*_t50 + _t112;
  const double _t157 = _hc0[2]*_t35;
  const double _t158 = _t157*_t49;
  const double _t159 = _hc0[1]*_t87;
  const double _t160 = _hc1[4]*_t50 + _t110;
  const double _t161 = _t106 - _t160*_t23;
  const double _t162 = _hc1[1]*_t158 + _hc1[1]*_t159 + _t156*_t36 + _t161;
  const double _t163 = -_t134;
  const double _t164 = _hc2[15]*_t50 + _t163;
  const double _t165 = _hc6[12]*_t50;
  const double _t166 = -_t124 + _t165;
  const double _t167 = _t166*_t39;
  const double _t168 = _hc2[14]*_t50;
  const double _t169 = -_t128 + _t168;
  const double _t170 = _hc2[19]*_t50 - _t131;
  const double _t171 = _t122 - _t170*_t23;
  const double _t172 = _hc2[4]*_t158 + _hc2[4]*_t159 + _t164*_t36 - _t167*ta - _t169*_t43 + _t171;
  const double _t173 = my_piecewise3(_t18, 0, _hc1[0]*_t172 + _hc2[0]*_t162 + _t37*_t51 + _t45*_t52);
  const double _t174 = 0.2e1*_t52;
  const double _t176 = _hc0[1]*_t175;
  const double _t178 = _hc0[2]*_t177;
  const double _t179 = _hc2[4]*_t176 + _hc2[4]*_t178 + _t164*_t50 + _t171;
  const double _t180 = _hc1[1]*_t176 + _hc1[1]*_t178 + _t156*_t50 + _t161;
  const double _t181 = my_piecewise3(_t18, 0, _hc1[0]*_t179 + _hc2[0]*_t180 + _t174*_t51);
  const double _t182 = 0.2e1*_t55;
  const double _t184 = _hc3[1]*_t183;
  const double _t186 = _hc3[2]*_t185;
  const double _t187 = _hc4[1]*_t184 + _hc4[1]*_t186 + _t140*_t54 + _t145;
  const double _t188 = _hc7[6]*_t57;
  const double _t189 = _hc7[16]*_t23;
  const double _t190 = _hc3[1]*_hc7[12]*_t48 - _hc7[9]*_t148 - _t188*tb - _t189;
  const double _t191 = _t190*_t57;
  const double _t192 = _hc7[9]*_t57;
  const double _t193 = _hc3[1]*_hc5[14]*_t48 - _hc5[11]*_t148 - _hc5[18]*_t23 - _t192*tb;
  const double _t198 = _hc7[1]*_t197;
  const double _t199 = _hc5[4]*_t184 + _hc5[4]*_t186 - _t148*_t193 + _t149*_t54 + _t153 - _t191*tb + _t195*_t59 + _t198*tb;
  const double _t200 = my_piecewise3(_t19, 0, _hc4[0]*_t199 + _hc5[0]*_t187 + _t182*_t62);
  const double _t201 = _t181 + _t200;
  const double _t202 = _t11*_t68;
  const double _t205 = _hc6[9]*_t66;
  const double _t206 = _t205*ta;
  const double _t211 = _hc2[18]*_t210;
  const double _t212 = _t209*_t211;
  const double _t213 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[14]*_t11*_t35*_t66 - _hc2[11]*_t203 - _t204*_t67 - _t206*_t208 - _t212;
  const double _t214 = my_piecewise3(_t18, 0, _hc1[0]*_t213 + _t202*_t37);
  const double _t215 = _t15*_t73;
  const double _t218 = _hc5[18]*_t217;
  const double _t219 = _hc5[14]*_t216;
  const double _t220 = (0.1e1 / 0.2e1)*_t29;
  const double _t221 = -_t218 + _t219*_t220;
  const double _t222 = my_piecewise3(_t19, 0, _hc4[0]*_t221 + _t215*_t32);
  const double _t224 = _t168*_t223 - _t212;
  const double _t225 = my_piecewise3(_t18, 0, _hc1[0]*_t224 + _t202*_t52);
  const double _t228 = _hc7[9]*_t71;
  const double _t229 = _t228*tb;
  const double _t232 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[14]*_t15*_t48*_t71 - _hc5[11]*_t226 - _t218 - _t227*_t72 - _t229*_t231;
  const double _t233 = my_piecewise3(_t19, 0, _hc4[0]*_t232 + _t215*_t55);
  const double _t237 = _hc6[9]*_t10;
  const double _t239 = _t124*_t13;
  const double _t240 = _hc0[1]*_hc6[12]*_t13*_t35 - _hc6[6]*_t236 - _t237*_t238 - _t239 - _t40;
  const double _t241 = my_piecewise3(_t18, 0, _hc1[0]*_t240 + _t37*_t75);
  const double _t242 = _t17*_t189;
  const double _t243 = _t17*_t29;
  const double _t244 = _hc7[12]*_t243 - _t242;
  const double _t245 = my_piecewise3(_t19, 0, _hc4[0]*_t244 + _t32*_t77);
  const double _t246 = _t13*_t165 - _t239;
  const double _t247 = my_piecewise3(_t18, 0, _hc1[0]*_t246 + _t52*_t75);
  const double _t251 = _hc7[9]*_t14;
  const double _t253 = _hc3[1]*_hc7[12]*_t17*_t48 - _hc7[6]*_t250 - _t242 - _t251*_t252 - _t58;
  const double _t254 = my_piecewise3(_t19, 0, _hc4[0]*_t253 + _t55*_t77);
  const double _t255 = _hc1[0]*_t38;
  const double _t257 = (0.1e1 / 0.4e1)*_hc2[11]*_t256;
  const double _t259 = _hc2[3]*_t258;
  const double _t260 = (0.1e1 / 0.4e1)*_t259;
  const double _t261 = my_piecewise3(_t18, 0, _t255*_t257 - _t260*_t65);
  const double _t262 = _hc4[0]*_t56;
  const double _t264 = (0.1e1 / 0.4e1)*_hc5[11]*_t263;
  const double _t266 = _hc5[3]*_t265;
  const double _t267 = (0.1e1 / 0.4e1)*_t266;
  const double _t268 = my_piecewise3(_t19, 0, _t262*_t264 - _t267*_t70);
  const double _t270 = _hc1[0]*_t269;
  const double _t271 = (0.1e1 / 0.2e1)*_t205;
  const double _t272 = my_piecewise3(_t18, 0, _t270*_t271);
  const double _t274 = _hc4[0]*_t273;
  const double _t275 = (0.1e1 / 0.2e1)*_t228;
  const double _t276 = my_piecewise3(_t19, 0, _t274*_t275);
  const double _t277 = _hc6[6]*_t119;
  const double _t278 = my_piecewise3(_t18, 0, _hc1[0]*_t277);
  const double _t279 = _hc7[6]*_t194;
  const double _t280 = my_piecewise3(_t19, 0, _hc4[0]*_t279);
  const double d2F_dna2 = _t139*_t3 + 0.2e1*_t33 + 0.2e1*_t46;
  const double d2F_dna_dnb = _t3*(_t155 + _t173) + _t47 + _t64;
  const double d2F_dnb2 = _t201*_t3 + 0.2e1*_t53 + 0.2e1*_t63;
  const double d2F_dna_dgaa = _t214*_t3 + _t69;
  const double d2F_dna_dgbb = _t222*_t3 + _t74;
  const double d2F_dnb_dgaa = _t225*_t3 + _t69;
  const double d2F_dnb_dgbb = _t233*_t3 + _t74;
  const double d2F_dna_dta = _t241*_t3 + _t76;
  const double d2F_dna_dtb = _t245*_t3 + _t78;
  const double d2F_dnb_dta = _t247*_t3 + _t76;
  const double d2F_dnb_dtb = _t254*_t3 + _t78;
  const double d2F_dgaa2 = _t261*_t3;
  const double d2F_dgbb2 = _t268*_t3;
  const double d2F_dgaa_dta = _t272*_t3;
  const double d2F_dgbb_dtb = _t276*_t3;
  const double d2F_dta2 = _t278*_t3;
  const double d2F_dtb2 = _t280*_t3;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 1] += d2F_dna_dtb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 2] += d2F_dnb_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 5] += d2F_dgbb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double _t283 = xc_powr(_t3, -10, 3);
  const double _t284 = (0.14e2 / 0.27e2)*_t283;
  const double _t285 = _t284*_t8;
  const double _t287 = 0.6e1*_t85;
  const double _t288 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t289 = _t2*_t288;
  const double _t290 = 0.6e1*_t289;
  const double _t291 = -_t287 + _t290;
  const double _t293 = (_t28 * _t28 * _t28);
  const double _t295 = 0.4e1*_t26;
  const double _t296 = 0.4e1*_t85;
  const double _t297 = _t2*_t296;
  const double _t298 = -_t295 + _t297;
  const double _t299 = -_t298;
  const double _t301 = _t8*_t80;
  const double _t302 = (0.4e1 / 0.9e1)*_t301;
  const double _t332 = -_t291;
  const double _t334 = (_t35 * _t35 * _t35);
  const double _t337 = -_t2*_t26;
  const double _t338 = _t337 + _t4;
  const double _t355 = xc_powr(na, -14, 3);
  const double _t356 = (0.440e3 / 0.27e2)*_t355;
  const double _t358 = (0.280e3 / 0.27e2)*_t234;
  const double _t361 = (0.80e2 / 0.9e1)*_t115;
  const double _t364 = (0.56e2 / 0.9e1)*_t119;
  const double _t387 = _t10*_t120;
  const double _t427 = _t290 - 0.2e1*_t85;
  const double _t454 = -_t427;
  const double _t456 = _t25 + _t337;
  const double _t457 = _t108*_t456;
  const double _t519 = _t177*_t338;
  const double _t557 = _t14*_t195;
  const double _t576 = _t287 + _t290;
  const double _t577 = -_t576;
  const double _t579 = (_t49 * _t49 * _t49);
  const double _t583 = _t295 + _t297;
  const double _t590 = (_t48 * _t48 * _t48);
  const double _t592 = -_t583;
  const double _t594 = xc_powr(nb, -14, 3);
  const double _t595 = (0.440e3 / 0.27e2)*_t594;
  const double _t597 = (0.280e3 / 0.27e2)*_t248;
  const double _t619 = (0.56e2 / 0.9e1)*_t194;
  const double _t620 = (0.80e2 / 0.9e1)*_t196;
  const double _t625 = (0.14e2 / 0.9e1)*_t355;
  const double _t626 = (0.14e2 / 0.9e1)*_t119;
  const double _t627 = xc_powi(na, -5);
  const double _t628 = _t627*_t66;
  const double _t630 = (0.20e2 / 0.9e1)*ta;
  const double _t631 = (0.1e1 / 0.9e1)*_t301;
  const double _t633 = _t204*_t66;
  const double _t635 = _t208*ta;
  const double _t636 = _t209*_t210;
  const double _t640 = _t635*_t66;
  const double _t651 = _t216*_t631;
  const double _t673 = _t227*_t71;
  const double _t674 = _t231*tb;
  const double _t679 = _t674*_t71;
  const double _t686 = (0.14e2 / 0.9e1)*_t594;
  const double _t691 = (0.14e2 / 0.9e1)*_t194;
  const double _t692 = xc_powi(nb, -5);
  const double _t693 = _t692*_t71;
  const double _t695 = (0.20e2 / 0.9e1)*tb;
  const double _t696 = (0.1e1 / 0.2e1)*_t216;
  const double _t699 = xc_powr(na, -16, 3);
  const double _t701 = (0.40e2 / 0.9e1)*ta;
  const double _t702 = (0.28e2 / 0.9e1)*_t627;
  const double _t704 = _t10*_t238;
  const double _t707 = _t39*ta;
  const double _t734 = _t14*_t252;
  const double _t743 = _t57*tb;
  const double _t745 = (0.28e2 / 0.9e1)*_t692;
  const double _t746 = xc_powr(nb, -16, 3);
  const double _t748 = (0.40e2 / 0.9e1)*tb;
  const double _t753 = _t115*_t256;
  const double _t757 = (0.5e1 / 0.12e2)*ta;
  const double _t758 = (0.1e1 / 0.4e1)*_t258;
  const double _t759 = _t256*_t38;
  const double _t760 = (0.1e1 / 0.24e2)*_t22;
  const double _t766 = (0.1e1 / 0.4e1)*_t265;
  const double _t767 = _t15*_t766;
  const double _t769 = _t263*_t56;
  const double _t773 = _t11*_t758;
  const double _t776 = _t196*_t263;
  const double _t780 = (0.5e1 / 0.12e2)*tb;
  const double _t784 = (0.2e1 / 0.3e1)*_t699;
  const double _t785 = (0.3e1 / 0.2e1)*_t207;
  const double _t786 = xc_powr(na, -17, 3);
  const double _t787 = _t786*ta;
  const double _t788 = (0.5e1 / 0.6e1)*_t787;
  const double _t790 = _t209*_t66;
  const double _t796 = _t209*_t71;
  const double _t801 = (0.1e1 / 0.2e1)*_t66;
  const double _t802 = _t269*_t801;
  const double _t805 = (0.2e1 / 0.3e1)*_t746;
  const double _t806 = (0.3e1 / 0.2e1)*_t230;
  const double _t807 = xc_powr(nb, -17, 3);
  const double _t808 = _t807*tb;
  const double _t809 = (0.5e1 / 0.6e1)*_t808;
  const double _t812 = (0.10e2 / 0.3e1)*_t234;
  const double _t813 = xc_powi(na, -6);
  const double _t816 = (0.4e1 / 0.3e1)*_t786;
  const double _t826 = (0.10e2 / 0.3e1)*_t248;
  const double _t827 = xc_powi(nb, -6);
  const double _t830 = (0.4e1 / 0.3e1)*_t807;
  const double _t833 = (0.1e1 / (gaa * gaa));
  const double _t835 = xc_powr(gaa, -5, 2);
  const double _t839 = _t207*_t258;
  const double _t840 = (0.1e1 / 0.8e1)*_t839;
  const double _t842 = (0.1e1 / (gbb * gbb));
  const double _t844 = xc_powr(gbb, -5, 2);
  const double _t848 = _t230*_t265;
  const double _t849 = (0.1e1 / 0.8e1)*_t848;
  const double _t281 = 0.3e1*_t32;
  const double _t282 = 0.3e1*_t30;
  const double _t286 = -_hc5[5]*_t285;
  const double _t292 = _hc3[1]*_t291;
  const double _t294 = _hc3[3]*_t293;
  const double _t300 = _hc5[4]*_t141;
  const double _t303 = 0.2e1*_t96;
  const double _t304 = _hc5[20]*_t82;
  const double _t305 = _hc5[55]*_t23;
  const double _t306 = _hc5[54]*_t29 - _t305;
  const double _t307 = _hc5[54]*_t23;
  const double _t308 = _hc5[50]*_t29 - _t307;
  const double _t309 = _hc5[19]*_t90 + _hc5[19]*_t92 - _t23*_t306 + _t29*_t308 + _t304;
  const double _t310 = _hc5[19]*_t82;
  const double _t311 = _hc5[50]*_t23;
  const double _t312 = _hc5[40]*_t29 - _t311;
  const double _t313 = _hc5[15]*_t90 + _hc5[15]*_t92 - _t23*_t308 + _t29*_t312 + _t310;
  const double _t314 = _hc5[4]*_t292 + _hc5[4]*_t294 - _t23*_t309 + _t286 + _t29*_t313 + _t299*_t300 + _t300*_t89 + _t302*_t94 + _t303*_t90 + _t303*_t92;
  const double _t315 = -_hc4[2]*_t285;
  const double _t316 = 0.2e1*_t102;
  const double _t317 = _hc4[5]*_t82;
  const double _t318 = -_hc4[9]*_t23;
  const double _t319 = _hc4[8]*_t29 + _t318;
  const double _t320 = -_hc4[8]*_t23;
  const double _t321 = _hc4[7]*_t29 + _t320;
  const double _t322 = _hc4[4]*_t90 + _hc4[4]*_t92 - _t23*_t319 + _t29*_t321 + _t317;
  const double _t323 = _hc4[4]*_t82;
  const double _t324 = -_hc4[7]*_t23;
  const double _t325 = _hc4[6]*_t29 + _t324;
  const double _t326 = _hc4[3]*_t90 + _hc4[3]*_t92 - _t23*_t321 + _t29*_t325 + _t323;
  const double _t327 = _hc4[1]*_t292 + _hc4[1]*_t294 + _t100*_t302 + _t142*_t299 + _t142*_t89 - _t23*_t322 + _t29*_t326 + _t315 + _t316*_t90 + _t316*_t92;
  const double _t328 = my_piecewise3(_t19, 0, _hc4[0]*_t314 + _hc5[0]*_t327 + _t103*_t282 + _t281*_t97);
  const double _t329 = 0.3e1*_t45;
  const double _t330 = 0.3e1*_t37;
  const double _t331 = -_hc1[2]*_t285;
  const double _t333 = _hc0[1]*_t332;
  const double _t335 = _hc0[3]*_t334;
  const double _t336 = _hc1[1]*_t157;
  const double _t339 = _hc0[1]*_t338;
  const double _t340 = _hc1[3]*_t339 + _t112;
  const double _t341 = 0.2e1*_t109;
  const double _t342 = 0.2e1*_t107;
  const double _t343 = _hc1[5]*_t82;
  const double _t344 = -_hc1[9]*_t23;
  const double _t345 = _hc1[8]*_t36 + _t344;
  const double _t346 = -_hc1[8]*_t23;
  const double _t347 = _hc1[7]*_t36 + _t346;
  const double _t348 = _hc1[4]*_t107 + _hc1[4]*_t109 - _t23*_t345 + _t343 + _t347*_t36;
  const double _t349 = -_hc1[7]*_t23;
  const double _t350 = _hc1[6]*_t36 + _t349;
  const double _t351 = _hc1[4]*_t82;
  const double _t352 = _hc1[3]*_t109 + _t351;
  const double _t353 = _hc1[3]*_t107 - _t23*_t347 + _t350*_t36 + _t352;
  const double _t354 = _hc1[1]*_t333 + _hc1[1]*_t335 + _t111*_t302 + _t113*_t342 - _t23*_t348 + _t298*_t336 + _t331 + _t336*_t88 + _t340*_t341 + _t353*_t36;
  const double _t357 = _hc6[1]*_t356;
  const double _t359 = -_t121*_t284;
  const double _t360 = _hc2[4]*_t157;
  const double _t362 = _t125*_t361;
  const double _t363 = _t10*_t129;
  const double _t365 = _hc0[1]*_hc2[15]*_t338 - _t135;
  const double _t366 = _hc6[6]*_t116;
  const double _t367 = _hc6[16]*_t82;
  const double _t368 = _hc6[12]*_t107;
  const double _t369 = _hc6[12]*_t109;
  const double _t370 = _hc6[21]*_t39;
  const double _t371 = _hc6[41]*_t23;
  const double _t372 = _hc0[1]*_hc6[31]*_t35 - _hc6[25]*_t43 - _t370*ta - _t371;
  const double _t373 = _t372*_t39;
  const double _t374 = _hc6[25]*_t39;
  const double _t375 = _hc6[44]*_t23;
  const double _t376 = _hc0[1]*_hc6[34]*_t35 - _hc6[28]*_t43 - _t374*ta - _t375;
  const double _t377 = _hc6[41]*_t39;
  const double _t378 = _hc6[51]*_t23;
  const double _t379 = _hc0[1]*_hc6[47]*_t35 - _hc6[44]*_t43 - _t377*ta - _t378;
  const double _t380 = _hc6[31]*_t39;
  const double _t381 = _hc6[47]*_t23;
  const double _t382 = _hc6[34]*_t43 + _t380*ta + _t381;
  const double _t383 = _hc0[1]*_hc6[37]*_t35 - _t382;
  const double _t384 = _t120*_t237 - _t23*_t379 + _t36*_t383 + _t366*ta + _t367 + _t368 + _t369 - _t373*ta - _t376*_t43;
  const double _t385 = _t384*_t39;
  const double _t386 = _hc6[9]*_t116;
  const double _t388 = _hc2[18]*_t82;
  const double _t389 = _hc2[14]*_t107;
  const double _t390 = _hc2[14]*_t109;
  const double _t391 = _t376*_t39;
  const double _t392 = _hc6[28]*_t39;
  const double _t393 = _hc2[46]*_t23;
  const double _t394 = _hc0[1]*_hc2[36]*_t35 - _hc2[30]*_t43 - _t392*ta - _t393;
  const double _t395 = _hc6[44]*_t39;
  const double _t396 = _hc2[53]*_t23;
  const double _t397 = _hc0[1]*_hc2[49]*_t35 - _hc2[46]*_t43 - _t395*ta - _t396;
  const double _t398 = _hc6[34]*_t39;
  const double _t399 = _hc2[49]*_t23;
  const double _t400 = _hc2[36]*_t43 + _t398*ta + _t399;
  const double _t401 = _hc0[1]*_hc2[39]*_t35 - _t400;
  const double _t402 = _hc2[11]*_t387 - _t23*_t397 + _t36*_t401 + _t386*ta + _t388 + _t389 + _t390 - _t391*ta - _t394*_t43;
  const double _t403 = _hc6[16]*_t116;
  const double _t404 = _hc2[20]*_t82;
  const double _t405 = _t379*_t39;
  const double _t406 = _hc6[51]*_t39;
  const double _t407 = _hc2[55]*_t23;
  const double _t408 = _hc0[1]*_hc2[54]*_t35 - _hc2[53]*_t43 - _t406*ta - _t407;
  const double _t409 = _hc6[47]*_t39;
  const double _t410 = _hc2[54]*_t23;
  const double _t411 = _hc2[49]*_t43 + _t409*ta + _t410;
  const double _t412 = _hc0[1]*_hc2[50]*_t35 - _t411;
  const double _t413 = _hc2[18]*_t387 + _hc2[19]*_t107 + _hc2[19]*_t109 - _t23*_t408 + _t36*_t412 - _t397*_t43 + _t403*ta + _t404 - _t405*ta;
  const double _t414 = _hc6[37]*_t39;
  const double _t415 = _hc2[50]*_t23;
  const double _t416 = _hc2[39]*_t43 + _t414*ta + _t415;
  const double _t417 = _hc0[1]*_hc2[40]*_t35 - _t416;
  const double _t418 = _t383*_t39;
  const double _t419 = _hc2[19]*_t82;
  const double _t420 = _hc6[12]*_t116;
  const double _t421 = _hc2[14]*_t387 + _hc2[15]*_t109 + _t419 + _t420*ta;
  const double _t422 = _hc2[15]*_t107 - _t23*_t412 + _t36*_t417 - _t401*_t43 - _t418*ta + _t421;
  const double _t423 = _hc2[4]*_t333 + _hc2[4]*_t335 - _t118*_t358 + _t132*_t302 + _t136*_t342 - _t23*_t413 + _t298*_t360 + _t341*_t365 - _t357*ta + _t359 + _t36*_t422 + _t360*_t88 + _t362*ta + _t363*_t364 - _t385*ta - _t402*_t43;
  const double _t424 = my_piecewise3(_t18, 0, _hc1[0]*_t423 + _hc2[0]*_t354 + _t114*_t329 + _t137*_t330);
  const double _t425 = _t328 + _t424;
  const double _t426 = 0.2e1*_t146;
  const double _t428 = _hc3[1]*_t427;
  const double _t429 = _hc3[2]*_t89;
  const double _t430 = _hc4[1]*_t48;
  const double _t431 = _hc3[3]*_t91;
  const double _t432 = _t141*_t48;
  const double _t433 = _hc4[7]*_t54 + _t320;
  const double _t434 = _hc4[8]*_t54 + _t318;
  const double _t435 = -_t23*_t434 + _t317;
  const double _t436 = -_hc4[4]*_t143 + _hc4[4]*_t432 + _t29*_t433 + _t435;
  const double _t437 = _hc4[6]*_t54 + _t324;
  const double _t438 = -_t23*_t433 + _t323;
  const double _t439 = -_hc4[3]*_t143 + _hc4[3]*_t432 + _t29*_t437 + _t438;
  const double _t440 = _hc4[1]*_t428 + _t100*_t82 - _t102*_t143 + _t102*_t432 + _t140*_t90 + _t140*_t92 - _t142*_t297 + _t144*_t82 - _t23*_t436 + _t29*_t439 + _t315 + _t429*_t430 + _t430*_t431;
  const double _t441 = _hc7[47]*_t57;
  const double _t442 = _hc3[1]*_hc5[50]*_t48 - _hc5[49]*_t148 - _t307 - _t441*tb;
  const double _t443 = _hc7[51]*_t57;
  const double _t444 = _hc3[1]*_hc5[54]*_t48 - _hc5[53]*_t148 - _t305 - _t443*tb;
  const double _t445 = -_t23*_t444 + _t304;
  const double _t446 = -_hc5[19]*_t143 + _hc5[19]*_t432 + _t29*_t442 + _t445;
  const double _t447 = _hc7[37]*_t57;
  const double _t448 = _hc3[1]*_hc5[40]*_t48 - _hc5[39]*_t148 - _t311 - _t447*tb;
  const double _t449 = -_t23*_t442 + _t310;
  const double _t450 = -_hc5[15]*_t143 + _hc5[15]*_t432 + _t29*_t448 + _t449;
  const double _t451 = _hc5[4]*_t428 - _t143*_t96 + _t149*_t90 + _t149*_t92 + _t150*_t429 + _t150*_t431 + _t152*_t82 - _t23*_t446 + _t286 + _t29*_t450 - _t297*_t300 + _t432*_t96 + _t82*_t94;
  const double _t452 = my_piecewise3(_t19, 0, _hc4[0]*_t451 + _hc5[0]*_t440 + _t103*_t62 + _t154*_t79 + _t30*_t426 + _t55*_t97);
  const double _t453 = 0.2e1*_t162;
  const double _t455 = _hc0[1]*_t454;
  const double _t458 = _hc0[3]*_hc1[1];
  const double _t459 = _hc0[2]*_t49;
  const double _t460 = _t459*_t88;
  const double _t461 = _hc0[1]*_t456;
  const double _t462 = _hc1[3]*_t461 + _t112;
  const double _t463 = _hc1[7]*_t50 + _t346;
  const double _t464 = _hc1[8]*_t50 + _t344;
  const double _t465 = -_t23*_t464 + _t343;
  const double _t466 = _hc1[4]*_t158 + _hc1[4]*_t159 + _t36*_t463 + _t465;
  const double _t467 = _hc1[6]*_t50 + _t349;
  const double _t468 = _hc1[3]*_t159;
  const double _t469 = -_t23*_t463 + _t351;
  const double _t470 = _hc1[3]*_t158 + _t36*_t467 + _t468 + _t469;
  const double _t471 = _hc1[1]*_t455 + _hc1[1]*_t460 + _t107*_t156 + _t109*_t462 + _t111*_t82 + _t113*_t158 + _t113*_t159 + _t160*_t82 - _t23*_t466 + _t297*_t336 + _t331 + _t36*_t470 + _t457*_t458;
  const double _t472 = _hc0[3]*_hc2[4];
  const double _t473 = _t116*_t166;
  const double _t474 = _hc2[15]*_t461 + _t163;
  const double _t475 = -_t381;
  const double _t476 = _hc6[37]*_t50;
  const double _t477 = _t475 + _t476;
  const double _t478 = _hc6[31]*_t50;
  const double _t479 = -_t371 + _t478;
  const double _t480 = _t39*_t479;
  const double _t481 = _hc6[34]*_t50;
  const double _t482 = -_t375 + _t481;
  const double _t483 = _hc6[12]*_t158;
  const double _t484 = _hc6[12]*_t159;
  const double _t485 = _hc6[47]*_t50;
  const double _t486 = -_t378 + _t485;
  const double _t487 = -_t23*_t486 + _t367;
  const double _t488 = _t36*_t477 - _t43*_t482 - _t480*ta + _t483 + _t484 + _t487;
  const double _t489 = _t39*_t488;
  const double _t490 = -_t399;
  const double _t491 = _hc2[39]*_t50;
  const double _t492 = _t490 + _t491;
  const double _t493 = _t39*_t482;
  const double _t494 = _hc2[36]*_t50;
  const double _t495 = -_t393 + _t494;
  const double _t496 = _hc2[14]*_t158;
  const double _t497 = _hc2[49]*_t50;
  const double _t498 = -_t396 + _t497;
  const double _t499 = -_t23*_t498 + _t388;
  const double _t500 = _hc2[14]*_t159 + _t36*_t492 - _t43*_t495 - _t493*ta + _t496 + _t499;
  const double _t501 = -_t410;
  const double _t502 = _hc2[50]*_t50 + _t501;
  const double _t503 = _t39*_t486;
  const double _t504 = _hc2[54]*_t50 - _t407;
  const double _t505 = -_t23*_t504 + _t404;
  const double _t506 = _hc2[19]*_t158 + _hc2[19]*_t159 + _t36*_t502 - _t43*_t498 - _t503*ta + _t505;
  const double _t507 = -_t23*_t502;
  const double _t508 = -_t415;
  const double _t509 = _hc2[40]*_t50 + _t508;
  const double _t510 = _t39*_t477;
  const double _t511 = _hc2[15]*_t159 + _t419;
  const double _t512 = _hc2[15]*_t158 + _t36*_t509 - _t43*_t492 + _t507 - _t510*ta + _t511;
  const double _t513 = _hc2[4]*_t455 + _hc2[4]*_t460 + _t107*_t164 + _t109*_t474 + _t132*_t82 + _t136*_t158 + _t136*_t159 + _t169*_t387 + _t170*_t82 - _t23*_t506 + _t297*_t360 + _t359 + _t36*_t512 - _t43*_t500 + _t457*_t472 + _t473*ta - _t489*ta;
  const double _t514 = my_piecewise3(_t18, 0, _hc1[0]*_t513 + _hc2[0]*_t471 + _t105*_t172 + _t114*_t51 + _t137*_t52 + _t45*_t453);
  const double _t515 = 0.2e1*_t155 + 0.2e1*_t173;
  const double _t516 = _hc1[3]*_t178;
  const double _t517 = _hc1[3]*_t176 + _t467*_t50 + _t469 + _t516;
  const double _t518 = _hc0[1]*_t86;
  const double _t520 = _hc0[1]*_t290;
  const double _t521 = 0.2e1*_t158;
  const double _t522 = _hc0[1]*_t297;
  const double _t523 = _hc1[1]*_t459;
  const double _t524 = _hc1[4]*_t176 + _hc1[4]*_t178 + _t463*_t50 + _t465;
  const double _t525 = _t160*_t302 - _t23*_t524 + _t331;
  const double _t526 = -_hc1[1]*_t518 - _hc1[1]*_t520 + _t156*_t521 + _t156*_t522 + _t175*_t336 + _t297*_t523 + _t36*_t517 + _t458*_t519 + _t525;
  const double _t527 = _hc2[15]*_t178 + _t419;
  const double _t528 = _hc2[15]*_t176 + _t50*_t509 + _t507 + _t527;
  const double _t529 = _hc6[12]*_t176;
  const double _t530 = _hc6[12]*_t178;
  const double _t531 = _t477*_t50 + _t487 + _t529 + _t530;
  const double _t532 = _t39*_t531;
  const double _t533 = _hc2[14]*_t176;
  const double _t534 = _hc2[14]*_t178;
  const double _t535 = _t492*_t50 + _t499 + _t533 + _t534;
  const double _t536 = _hc2[4]*_t459;
  const double _t537 = _hc2[19]*_t176 + _hc2[19]*_t178 + _t50*_t502 + _t505;
  const double _t538 = _t170*_t302 - _t23*_t537 + _t359;
  const double _t539 = -_hc2[4]*_t518 - _hc2[4]*_t520 + _t164*_t521 + _t164*_t522 + _t175*_t360 + _t297*_t536 + _t36*_t528 - _t43*_t535 + _t472*_t519 - _t532*ta + _t538;
  const double _t540 = my_piecewise3(_t18, 0, _hc1[0]*_t539 + _hc2[0]*_t526 + _t172*_t174 + _t179*_t37 + _t180*_t45 + _t453*_t51);
  const double _t541 = _hc4[3]*_t184 + _hc4[3]*_t186 + _t437*_t54 + _t438;
  const double _t542 = _hc3[1]*_t86;
  const double _t543 = _hc3[3]*_t28;
  const double _t544 = _t185*_t543;
  const double _t545 = _hc3[1]*_t297;
  const double _t546 = 0.2e1*_t140;
  const double _t547 = _hc3[1]*_t290;
  const double _t548 = _hc3[2]*_t430;
  const double _t549 = _hc4[4]*_t184 + _hc4[4]*_t186 + _t433*_t54 + _t435;
  const double _t550 = _t144*_t302 - _t23*_t549 + _t315;
  const double _t551 = _hc4[1]*_t542 + _hc4[1]*_t544 + _hc4[1]*_t547 - _t140*_t545 + _t142*_t183 + _t29*_t541 - _t297*_t548 + _t432*_t546 + _t550;
  const double _t552 = _hc7[31]*_t57;
  const double _t553 = _hc3[1]*_hc7[37]*_t48 - _hc7[34]*_t148 - _hc7[47]*_t23 - _t552*tb;
  const double _t554 = _t553*_t57;
  const double _t555 = _hc7[34]*_t57;
  const double _t556 = _hc3[1]*_hc5[39]*_t48 - _hc5[36]*_t148 - _hc5[49]*_t23 - _t555*tb;
  const double _t558 = _hc7[12]*_t197;
  const double _t559 = _hc5[14]*_t557 + _hc5[15]*_t184 + _hc5[15]*_t186 - _t148*_t556 + _t448*_t54 + _t449 - _t554*tb + _t558*tb;
  const double _t560 = _hc5[4]*_t185;
  const double _t561 = 0.2e1*_t149;
  const double _t562 = _hc3[2]*_t150;
  const double _t563 = _hc7[41]*_t57;
  const double _t564 = _hc7[51]*_t23;
  const double _t565 = _hc3[1]*_hc7[47]*_t48 - _hc7[44]*_t148 - _t563*tb - _t564;
  const double _t566 = _t565*_t57;
  const double _t567 = _hc7[44]*_t57;
  const double _t568 = _hc3[1]*_hc5[49]*_t48 - _hc5[46]*_t148 - _hc5[53]*_t23 - _t567*tb;
  const double _t569 = _hc7[16]*_t197;
  const double _t570 = _hc5[18]*_t557 + _hc5[19]*_t184 + _hc5[19]*_t186 - _t148*_t568 + _t442*_t54 + _t445 - _t566*tb + _t569*tb;
  const double _t571 = _t152*_t302 - _t23*_t570 + _t286;
  const double _t572 = _hc5[4]*_t542 + _hc5[4]*_t547 - _t149*_t545 + _t183*_t300 + _t29*_t559 - _t297*_t562 + _t432*_t561 + _t543*_t560 + _t571;
  const double _t573 = my_piecewise3(_t19, 0, _hc4[0]*_t572 + _hc5[0]*_t551 + _t154*_t182 + _t187*_t30 + _t199*_t32 + _t426*_t62);
  const double _t574 = 0.3e1*_t52;
  const double _t575 = 0.3e1*_t51;
  const double _t578 = _hc0[1]*_t577;
  const double _t580 = _hc0[3]*_t579;
  const double _t581 = 0.2e1*_t176;
  const double _t582 = 0.2e1*_t178;
  const double _t584 = _hc2[4]*_t578 + _hc2[4]*_t580 + _t164*_t581 + _t175*_t536 + _t474*_t582 + _t50*_t528 + _t536*_t583 + _t538;
  const double _t585 = _hc1[1]*_t578 + _hc1[1]*_t580 + _t156*_t581 + _t175*_t523 + _t462*_t582 + _t50*_t517 + _t523*_t583 + _t525;
  const double _t586 = my_piecewise3(_t18, 0, _hc1[0]*_t584 + _hc2[0]*_t585 + _t179*_t574 + _t180*_t575);
  const double _t587 = 0.3e1*_t62;
  const double _t588 = 0.3e1*_t55;
  const double _t589 = _hc3[1]*_t576;
  const double _t591 = _hc3[3]*_t590;
  const double _t593 = _hc4[1]*_t589 + _hc4[1]*_t591 + _t183*_t548 + _t184*_t546 + _t186*_t546 + _t54*_t541 + _t548*_t592 + _t550;
  const double _t596 = _hc7[1]*_t595;
  const double _t598 = _hc7[6]*_t197;
  const double _t599 = _hc7[16]*_t82;
  const double _t600 = _hc7[12]*_t186;
  const double _t601 = _hc7[12]*_t184;
  const double _t602 = _hc7[21]*_t57;
  const double _t603 = _hc7[41]*_t23;
  const double _t604 = _hc3[1]*_hc7[31]*_t48 - _hc7[25]*_t148 - _t602*tb - _t603;
  const double _t605 = _t57*_t604;
  const double _t606 = _hc7[25]*_t57;
  const double _t607 = _hc7[44]*_t23;
  const double _t608 = _hc3[1]*_hc7[34]*_t48 - _hc7[28]*_t148 - _t606*tb - _t607;
  const double _t609 = -_t148*_t608 + _t195*_t251 - _t23*_t565 + _t54*_t553 + _t598*tb + _t599 + _t600 + _t601 - _t605*tb;
  const double _t610 = _t57*_t609;
  const double _t611 = _hc7[9]*_t197;
  const double _t612 = _hc5[14]*_t186;
  const double _t613 = _hc5[14]*_t184;
  const double _t614 = _t57*_t608;
  const double _t615 = _hc7[28]*_t57;
  const double _t616 = _hc3[1]*_hc5[36]*_t48 - _hc5[30]*_t148 - _hc5[46]*_t23 - _t615*tb;
  const double _t617 = _hc5[11]*_t557 + _hc5[18]*_t82 - _t148*_t616 - _t23*_t568 + _t54*_t556 + _t611*tb + _t612 + _t613 - _t614*tb;
  const double _t618 = _t14*_t193;
  const double _t621 = _t190*_t620;
  const double _t622 = _hc5[4]*_t589 + _hc5[4]*_t591 - _t148*_t617 + _t183*_t562 + _t184*_t561 + _t186*_t561 + _t54*_t559 + _t562*_t592 + _t571 - _t59*_t597 - _t596*tb - _t610*tb + _t618*_t619 + _t621*tb;
  const double _t623 = my_piecewise3(_t19, 0, _hc4[0]*_t622 + _hc5[0]*_t593 + _t187*_t587 + _t199*_t588);
  const double _t624 = _t586 + _t623;
  const double _t629 = _hc6[9]*_t628;
  const double _t632 = _t211*_t631;
  const double _t634 = _hc6[25]*_t66;
  const double _t637 = _hc6[44]*_t636;
  const double _t638 = (0.1e1 / 0.2e1)*_hc0[1]*_hc6[34]*_t11*_t35*_t66 - _hc6[28]*_t203 - _hc6[9]*_t633 - _t634*_t635 - _t637;
  const double _t639 = _t39*_t638;
  const double _t641 = _hc2[46]*_t636;
  const double _t642 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[36]*_t11*_t35*_t66 - _hc2[11]*_t633 - _hc2[30]*_t203 - _hc6[28]*_t640 - _t641;
  const double _t643 = _hc2[53]*_t636;
  const double _t644 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[49]*_t11*_t35*_t66 - _hc2[18]*_t633 - _hc2[46]*_t203 - _hc6[44]*_t640 - _t643;
  const double _t645 = _hc6[34]*_t66;
  const double _t646 = _hc2[49]*_t636;
  const double _t647 = _hc2[14]*_t633 + _hc2[36]*_t203 + _t635*_t645 + _t646;
  const double _t648 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[39]*_t11*_t35*_t66 - _t647;
  const double _t649 = _hc2[11]*_t625 - _t129*_t633 + _t223*_t389 + _t223*_t390 - _t23*_t644 + _t36*_t648 - _t43*_t642 + _t626*_t67 + _t629*_t630 + _t632 - _t639*ta;
  const double _t650 = my_piecewise3(_t18, 0, _hc1[0]*_t649 + _t105*_t213 + _t114*_t202);
  const double _t652 = _hc5[18]*_t651;
  const double _t653 = (0.1e1 / 0.2e1)*_t219;
  const double _t654 = _hc5[53]*_t217;
  const double _t655 = _t216*_t220;
  const double _t656 = _hc5[49]*_t655 - _t654;
  const double _t657 = _hc5[49]*_t217;
  const double _t658 = _hc5[39]*_t655 - _t657;
  const double _t659 = -_t23*_t656 + _t29*_t658 + _t652 + _t653*_t90 + _t653*_t92;
  const double _t660 = my_piecewise3(_t19, 0, _hc4[0]*_t659 + _t103*_t215 + _t221*_t79);
  const double _t661 = -_t646;
  const double _t662 = _t223*_t491 + _t661;
  const double _t663 = _t223*_t481 - _t637;
  const double _t664 = _t39*_t663;
  const double _t665 = _t223*_t494 - _t641;
  const double _t666 = _hc0[1]*_t85;
  const double _t667 = _t210*_t666;
  const double _t668 = _hc2[14]*_t667;
  const double _t669 = _t223*_t497 - _t643;
  const double _t670 = -_t23*_t669 + _t632;
  const double _t671 = -_t169*_t633 + _t2*_t668 + _t223*_t496 + _t36*_t662 - _t43*_t665 - _t664*ta + _t670;
  const double _t672 = my_piecewise3(_t18, 0, _hc1[0]*_t671 + _t162*_t202 + _t213*_t52 + _t224*_t37);
  const double _t675 = _hc7[34]*_t71;
  const double _t676 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[39]*_t15*_t48*_t71 - _hc5[14]*_t673 - _hc5[36]*_t226 - _t657 - _t674*_t675;
  const double _t677 = _hc3[1]*_t85;
  const double _t678 = _t219*_t677;
  const double _t680 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[49]*_t15*_t48*_t71 - _hc5[18]*_t673 - _hc5[46]*_t226 - _hc7[44]*_t679 - _t654;
  const double _t681 = -_t23*_t680 + _t652;
  const double _t682 = -_t2*_t678 + _t29*_t676 + _t432*_t653 + _t681;
  const double _t683 = my_piecewise3(_t19, 0, _hc4[0]*_t682 + _t146*_t215 + _t221*_t55 + _t232*_t32);
  const double _t684 = _t223*_t533 + _t223*_t534 + _t50*_t662 + _t670;
  const double _t685 = my_piecewise3(_t18, 0, _hc1[0]*_t684 + _t174*_t224 + _t180*_t202);
  const double _t687 = _hc7[25]*_t71;
  const double _t688 = (0.1e1 / 0.2e1)*_hc3[1]*_hc7[34]*_t15*_t48*_t71 - _hc7[28]*_t226 - _hc7[44]*_t217 - _hc7[9]*_t673 - _t674*_t687;
  const double _t689 = _t57*_t688;
  const double _t690 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[36]*_t15*_t48*_t71 - _hc5[11]*_t673 - _hc5[30]*_t226 - _hc5[46]*_t217 - _hc7[28]*_t679;
  const double _t694 = _hc7[9]*_t693;
  const double _t697 = _hc5[11]*_t686 - _t148*_t690 - _t193*_t673 + _t54*_t676 + _t612*_t696 + _t613*_t696 + _t681 - _t689*tb + _t691*_t72 + _t694*_t695;
  const double _t698 = my_piecewise3(_t19, 0, _hc4[0]*_t697 + _t182*_t232 + _t187*_t215);
  const double _t700 = _hc6[6]*_t699;
  const double _t703 = _t13*_t367;
  const double _t705 = _t13*_t371;
  const double _t706 = _hc0[1]*_hc6[31]*_t13*_t35 - _hc6[21]*_t236 - _hc6[25]*_t704 - _t123 - _t705;
  const double _t708 = _t13*_t375;
  const double _t709 = _hc0[1]*_hc6[34]*_t13*_t35 - _hc6[25]*_t236 - _hc6[28]*_t704 - _t127 - _t708;
  const double _t710 = _t13*_t378;
  const double _t711 = _hc0[1]*_hc6[47]*_t13*_t35 - _hc6[41]*_t236 - _hc6[44]*_t704 - _t130 - _t710;
  const double _t712 = _t13*_t381;
  const double _t713 = _hc6[31]*_t236 + _hc6[34]*_t704 + _t133 + _t712;
  const double _t714 = _hc0[1]*_hc6[37]*_t13*_t35 - _t713;
  const double _t715 = _t117 - _t126 + _t13*_t368 + _t13*_t369 - _t23*_t711 + _t237*_t702 + _t36*_t714 - _t43*_t709 + _t700*_t701 + _t703 - _t706*_t707;
  const double _t716 = my_piecewise3(_t18, 0, _hc1[0]*_t715 + _t105*_t240 + _t114*_t75);
  const double _t717 = _t17*_t599;
  const double _t718 = _hc7[12]*_t17;
  const double _t719 = _t17*_t564;
  const double _t720 = _hc7[47]*_t243 - _t719;
  const double _t721 = _hc7[47]*_t17;
  const double _t722 = _t23*_t721;
  const double _t723 = _hc7[37]*_t243 - _t722;
  const double _t724 = -_t23*_t720 + _t29*_t723 + _t717 + _t718*_t90 + _t718*_t92;
  const double _t725 = my_piecewise3(_t19, 0, _hc4[0]*_t724 + _t103*_t77 + _t244*_t79);
  const double _t726 = -_t712;
  const double _t727 = _t13*_t476 + _t726;
  const double _t728 = _t13*_t478 - _t705;
  const double _t729 = _t13*_t481 - _t708;
  const double _t730 = _t13*_t485 - _t710;
  const double _t731 = -_t23*_t730 + _t703;
  const double _t732 = _t13*_t483 + _t13*_t484 - _t167 + _t36*_t727 - _t43*_t729 - _t707*_t728 + _t731;
  const double _t733 = my_piecewise3(_t18, 0, _hc1[0]*_t732 + _t162*_t75 + _t240*_t52 + _t246*_t37);
  const double _t735 = _hc3[1]*_hc7[37]*_t17*_t48 - _hc7[31]*_t250 - _hc7[34]*_t734 - _t147 - _t722;
  const double _t736 = _hc3[1]*_hc7[47]*_t17*_t48 - _hc7[41]*_t250 - _hc7[44]*_t734 - _t151 - _t719;
  const double _t737 = -_t23*_t736 + _t717;
  const double _t738 = -_t143*_t718 + _t29*_t735 + _t432*_t718 + _t737;
  const double _t739 = my_piecewise3(_t19, 0, _hc4[0]*_t738 + _t146*_t77 + _t244*_t55 + _t253*_t32);
  const double _t740 = _t13*_t529 + _t13*_t530 + _t50*_t727 + _t731;
  const double _t741 = my_piecewise3(_t18, 0, _hc1[0]*_t740 + _t174*_t246 + _t180*_t75);
  const double _t742 = _hc3[1]*_hc7[31]*_t17*_t48 - _hc7[21]*_t250 - _hc7[25]*_t734 - _t17*_t603 - _t188;
  const double _t744 = _hc3[1]*_hc7[34]*_t17*_t48 - _hc7[25]*_t250 - _hc7[28]*_t734 - _t17*_t607 - _t192;
  const double _t747 = _hc7[6]*_t746;
  const double _t749 = -_t148*_t744 + _t17*_t600 + _t17*_t601 - _t191 + _t198 + _t251*_t745 + _t54*_t735 + _t737 - _t742*_t743 + _t747*_t748;
  const double _t750 = my_piecewise3(_t19, 0, _hc4[0]*_t749 + _t182*_t253 + _t187*_t77);
  const double _t751 = _t257*_t38;
  const double _t752 = _t11*_t260;
  const double _t754 = (0.1e1 / 0.3e1)*_hc2[30];
  const double _t755 = _hc6[28]*_t256;
  const double _t756 = _t699*_t755;
  const double _t761 = -0.1e1 / 0.24e2*_hc2[18]*_t11*_t21*_t258*_t6*_t7 + _hc2[46]*_t759*_t760;
  const double _t762 = (0.1e1 / 0.4e1)*_hc0[1]*_hc2[36]*_t256*_t35*_t38 - 0.1e1 / 0.3e1*_hc2[11]*_t753 - _hc2[14]*_t11*_t36*_t758 + (0.1e1 / 0.3e1)*_hc2[3]*_t258*_t41 + (0.5e1 / 0.12e2)*_hc6[9]*_t207*_t258*ta - _t628*_t754 - _t756*_t757 - _t761;
  const double _t763 = my_piecewise3(_t18, 0, _hc1[0]*_t762 + _t37*_t751 - _t37*_t752);
  const double _t764 = _t264*_t56;
  const double _t765 = _t15*_t267;
  const double _t768 = _hc5[14]*_t29;
  const double _t770 = -0.1e1 / 0.24e2*_hc5[18]*_t15*_t21*_t265*_t6*_t7 + _hc5[46]*_t760*_t769;
  const double _t771 = (0.1e1 / 0.4e1)*_hc3[1]*_hc5[36]*_t263*_t28*_t56 - _t767*_t768 - _t770;
  const double _t772 = my_piecewise3(_t19, 0, _hc4[0]*_t771 + _t32*_t764 - _t32*_t765);
  const double _t774 = (0.1e1 / 0.4e1)*_hc0[1]*_hc2[36]*_t256*_t38*_t49 - _t168*_t773 - _t761;
  const double _t775 = my_piecewise3(_t18, 0, _hc1[0]*_t774 + _t52*_t751 - _t52*_t752);
  const double _t777 = (0.1e1 / 0.3e1)*_hc5[30];
  const double _t778 = _hc7[28]*_t263;
  const double _t779 = _t746*_t778;
  const double _t781 = (0.1e1 / 0.4e1)*_hc3[1]*_hc5[36]*_t263*_t48*_t56 - 0.1e1 / 0.3e1*_hc5[11]*_t776 - _hc5[14]*_t54*_t767 + (0.1e1 / 0.3e1)*_hc5[3]*_t265*_t60 + (0.5e1 / 0.12e2)*_hc7[9]*_t230*_t265*tb - _t693*_t777 - _t770 - _t779*_t780;
  const double _t782 = my_piecewise3(_t19, 0, _hc4[0]*_t781 + _t55*_t764 - _t55*_t765);
  const double _t783 = _t269*_t271;
  const double _t789 = _hc6[44]*_t269;
  const double _t791 = _t789*_t790;
  const double _t792 = (0.1e1 / 0.2e1)*_hc0[1]*_hc6[34]*_t269*_t35*_t66 - _hc6[28]*_t784 - _t205*_t785 - _t634*_t788 - _t791;
  const double _t793 = my_piecewise3(_t18, 0, _hc1[0]*_t792 + _t37*_t783);
  const double _t794 = _t273*_t275;
  const double _t795 = _hc7[44]*_t273;
  const double _t797 = _t795*_t796;
  const double _t798 = _t273*_t675;
  const double _t799 = _t220*_t798 - _t797;
  const double _t800 = my_piecewise3(_t19, 0, _hc4[0]*_t799 + _t32*_t794);
  const double _t803 = _t481*_t802 - _t791;
  const double _t804 = my_piecewise3(_t18, 0, _hc1[0]*_t803 + _t52*_t783);
  const double _t810 = (0.1e1 / 0.2e1)*_hc3[1]*_hc7[34]*_t273*_t48*_t71 - _hc7[28]*_t805 - _t228*_t806 - _t687*_t809 - _t797;
  const double _t811 = my_piecewise3(_t19, 0, _hc4[0]*_t810 + _t55*_t794);
  const double _t814 = _hc6[21]*_t813;
  const double _t815 = _hc6[25]*_t10;
  const double _t817 = _t119*_t371;
  const double _t818 = _hc0[1]*_hc6[31]*_t119*_t35 - _hc6[6]*_t812 - _t235*_t814 - _t815*_t816 - _t817;
  const double _t819 = my_piecewise3(_t18, 0, _hc1[0]*_t818 + _t277*_t37);
  const double _t820 = _t194*_t603;
  const double _t821 = _t194*_t29;
  const double _t822 = _hc7[31]*_t821 - _t820;
  const double _t823 = my_piecewise3(_t19, 0, _hc4[0]*_t822 + _t279*_t32);
  const double _t824 = _t119*_t478 - _t817;
  const double _t825 = my_piecewise3(_t18, 0, _hc1[0]*_t824 + _t277*_t52);
  const double _t828 = _hc7[21]*_t827;
  const double _t829 = _hc7[25]*_t14;
  const double _t831 = _hc3[1]*_hc7[31]*_t194*_t48 - _hc7[6]*_t826 - _t249*_t828 - _t820 - _t829*_t830;
  const double _t832 = my_piecewise3(_t19, 0, _hc4[0]*_t831 + _t279*_t55);
  const double _t834 = (0.3e1 / 0.8e1)*_hc2[11]*_t833;
  const double _t836 = _hc2[3]*_t835;
  const double _t837 = (0.3e1 / 0.8e1)*_t836;
  const double _t838 = _hc1[0]*_hc2[30];
  const double _t841 = my_piecewise3(_t18, 0, -_t255*_t834 + _t65*_t837 + _t838*_t840);
  const double _t843 = (0.3e1 / 0.8e1)*_hc5[11]*_t842;
  const double _t845 = _hc5[3]*_t844;
  const double _t846 = (0.3e1 / 0.8e1)*_t845;
  const double _t847 = _hc4[0]*_hc5[30];
  const double _t850 = my_piecewise3(_t19, 0, -_t262*_t843 + _t70*_t846 + _t847*_t849);
  const double _t851 = _hc1[0]*_t234;
  const double _t852 = (0.1e1 / 0.4e1)*_t755;
  const double _t853 = _hc6[9]*_t258;
  const double _t854 = (0.1e1 / 0.4e1)*_t853;
  const double _t855 = my_piecewise3(_t18, 0, -_t270*_t854 + _t851*_t852);
  const double _t856 = _hc4[0]*_t248;
  const double _t857 = (0.1e1 / 0.4e1)*_t778;
  const double _t858 = _hc7[9]*_t265;
  const double _t859 = (0.1e1 / 0.4e1)*_t858;
  const double _t860 = my_piecewise3(_t19, 0, -_t274*_t859 + _t856*_t857);
  const double _t861 = _hc1[0]*_t355;
  const double _t862 = (0.1e1 / 0.2e1)*_t634;
  const double _t863 = my_piecewise3(_t18, 0, _t861*_t862);
  const double _t864 = _hc4[0]*_t594;
  const double _t865 = (0.1e1 / 0.2e1)*_t687;
  const double _t866 = my_piecewise3(_t19, 0, _t864*_t865);
  const double _t867 = _hc6[21]*_t627;
  const double _t868 = my_piecewise3(_t18, 0, _hc1[0]*_t867);
  const double _t869 = _hc7[21]*_t692;
  const double _t870 = my_piecewise3(_t19, 0, _hc4[0]*_t869);
  const double d3F_dna3 = 0.3e1*_t104 + 0.3e1*_t138 + _t3*_t425;
  const double d3F_dna2_dnb = _t139 + _t3*(_t452 + _t514) + _t515;
  const double d3F_dna_dnb2 = _t201 + _t3*(_t540 + _t573) + _t515;
  const double d3F_dnb3 = 0.3e1*_t181 + 0.3e1*_t200 + _t3*_t624;
  const double d3F_dna2_dgaa = 0.2e1*_t214 + _t3*_t650;
  const double d3F_dna2_dgbb = 0.2e1*_t222 + _t3*_t660;
  const double d3F_dna_dnb_dgaa = _t214 + _t225 + _t3*_t672;
  const double d3F_dna_dnb_dgbb = _t222 + _t233 + _t3*_t683;
  const double d3F_dnb2_dgaa = 0.2e1*_t225 + _t3*_t685;
  const double d3F_dnb2_dgbb = 0.2e1*_t233 + _t3*_t698;
  const double d3F_dna2_dta = 0.2e1*_t241 + _t3*_t716;
  const double d3F_dna2_dtb = 0.2e1*_t245 + _t3*_t725;
  const double d3F_dna_dnb_dta = _t241 + _t247 + _t3*_t733;
  const double d3F_dna_dnb_dtb = _t245 + _t254 + _t3*_t739;
  const double d3F_dnb2_dta = 0.2e1*_t247 + _t3*_t741;
  const double d3F_dnb2_dtb = 0.2e1*_t254 + _t3*_t750;
  const double d3F_dna_dgaa2 = _t261 + _t3*_t763;
  const double d3F_dna_dgbb2 = _t268 + _t3*_t772;
  const double d3F_dnb_dgaa2 = _t261 + _t3*_t775;
  const double d3F_dnb_dgbb2 = _t268 + _t3*_t782;
  const double d3F_dna_dgaa_dta = _t272 + _t3*_t793;
  const double d3F_dna_dgbb_dtb = _t276 + _t3*_t800;
  const double d3F_dnb_dgaa_dta = _t272 + _t3*_t804;
  const double d3F_dnb_dgbb_dtb = _t276 + _t3*_t811;
  const double d3F_dna_dta2 = _t278 + _t3*_t819;
  const double d3F_dna_dtb2 = _t280 + _t3*_t823;
  const double d3F_dnb_dta2 = _t278 + _t3*_t825;
  const double d3F_dnb_dtb2 = _t280 + _t3*_t832;
  const double d3F_dgaa3 = _t3*_t841;
  const double d3F_dgbb3 = _t3*_t850;
  const double d3F_dgaa2_dta = _t3*_t855;
  const double d3F_dgbb2_dtb = _t3*_t860;
  const double d3F_dgaa_dta2 = _t3*_t863;
  const double d3F_dgbb_dtb2 = _t3*_t866;
  const double d3F_dta3 = _t3*_t868;
  const double d3F_dtb3 = _t3*_t870;
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
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 1] += d3F_dna2_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 2] += d3F_dna_dnb_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 3] += d3F_dna_dnb_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 4] += d3F_dnb2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 5] += d3F_dna_dgbb_dtb;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 6] += d3F_dnb_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += d3F_dnb_dgbb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 2] += d3F_dna_dtb2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 3] += d3F_dnb_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 11] += d3F_dgbb2_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 8] += d3F_dgbb_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 3] += d3F_dtb3;
#endif
#if _KMAX >= 4
  const double _t871 = (0.140e3 / 0.81e2)/xc_powr(_t3, 13, 3);
  const double _t872 = _t8*_t871;
  const double _t874 = 0.24e2*_t288;
  const double _t875 = 0.24e2*_t2/xc_powi(_t3, 5);
  const double _t876 = -_t874 + _t875;
  const double _t880 = 0.12e2*_t85;
  const double _t881 = 0.12e2*_t288;
  const double _t882 = _t2*_t881;
  const double _t883 = -_t880 + _t882;
  const double _t884 = 0.2e1*_t291;
  const double _t886 = 0.6e1*_t26;
  const double _t887 = _t2*_t287;
  const double _t888 = _t886 - _t887;
  const double _t890 = _t283*_t8;
  const double _t891 = (0.14e2 / 0.9e1)*_t890;
  const double _t894 = (0.2e1 / 0.3e1)*_t301;
  const double _t938 = -_t883;
  const double _t939 = 0.2e1*_t332;
  const double _t942 = 0.6e1*na - 0.6e1*nb;
  const double _t943 = _t85*_t942 - _t886;
  const double _t945 = 0.4e1*na - 0.4e1*nb;
  const double _t946 = -_t295 + _t85*_t945;
  const double _t947 = 0.2e1*na - 0.2e1*nb;
  const double _t948 = -_t84 + _t85*_t947;
  const double _t977 = _t38*ta;
  const double _t981 = _t356*ta;
  const double _t989 = _t361*ta;
  const double _t990 = _t10*_t364;
  const double _t991 = _t116*ta;
  const double _t1026 = _t10*_t358;
  const double _t1071 = _t875 - _t881;
  const double _t1081 = -0.4e1*_t85 + _t882;
  const double _t1085 = (0.28e2 / 0.27e2)*_t890;
  const double _t1089 = 0.8e1*_t2*_t85;
  const double _t1123 = -_t1081;
  const double _t1125 = _t334*_t456;
  const double _t1131 = _t35*_t49;
  const double _t1134 = _t298*_t87;
  const double _t1230 = 0.2e1*_t427;
  const double _t1233 = 0.8e1*(_t2 * _t2)/xc_powi(_t3, 6);
  const double _t1242 = _t197*tb;
  const double _t1267 = _t84 + _t85*_t947;
  const double _t1272 = _t177*_t948;
  const double _t1273 = _t108*_t177;
  const double _t1274 = 0.2e1*_t454;
  const double _t1314 = _t338*_t579;
  const double _t1315 = 0.18e2*_t289;
  const double _t1318 = 0.3e1*_t175;
  const double _t1321 = _t175*_t887;
  const double _t1324 = _t2*_t880;
  const double _t1344 = 0.3e1*_t183;
  const double _t1348 = _t183*_t887;
  const double _t1351 = _t595*tb;
  const double _t1352 = _t14*_t597;
  const double _t1364 = _t14*_t619;
  const double _t1365 = _t620*tb;
  const double _t1383 = _t874 + _t875;
  const double _t1391 = _t880 + _t882;
  const double _t1392 = -_t1391;
  const double _t1393 = _t175*_t583;
  const double _t1394 = _t295 + _t85*_t945;
  const double _t1395 = _t85*_t942 + _t886;
  const double _t1396 = 0.2e1*_t577;
  const double _t1397 = 0.3e1*_t583;
  const double _t1401 = _t183*_t592;
  const double _t1402 = -_t886 - _t887;
  const double _t1403 = 0.2e1*_t576;
  const double _t1432 = (0.7e1 / 0.27e2)*_t890;
  const double _t1435 = _t628*_t630;
  const double _t1436 = _t210*_t631;
  const double _t1445 = _t626*_t66;
  const double _t1494 = 0.3e1*_t289;
  const double _t1499 = _t691*_t71;
  const double _t1500 = _t693*_t695;
  const double _t1510 = xc_powr(na, -19, 3);
  const double _t1513 = _t699*_t701;
  const double _t1522 = _t10*_t702;
  const double _t1568 = _t14*_t745;
  const double _t1569 = _t746*_t748;
  const double _t1576 = xc_powr(nb, -19, 3);
  const double _t1578 = (0.1e1 / 0.3e1)*_t753;
  const double _t1579 = (0.1e1 / 0.3e1)*_t628;
  const double _t1580 = _t256*_t757;
  const double _t1581 = _t1580*_t699;
  const double _t1582 = _t759*_t760;
  const double _t1586 = (0.4e1 / 0.3e1)*_t41*_t66;
  const double _t1590 = _t11*_t258;
  const double _t1591 = (0.1e1 / 0.18e2)*_t301;
  const double _t1594 = _t760*_t769;
  const double _t1597 = _t15*_t265;
  const double _t1598 = (0.1e1 / 0.4e1)*_t263*_t56;
  const double _t1605 = (0.1e1 / 0.3e1)*_t693;
  const double _t1606 = (0.1e1 / 0.3e1)*_t776;
  const double _t1607 = _t263*_t780;
  const double _t1608 = _t1607*_t746;
  const double _t1613 = xc_powr(na, -20, 3);
  const double _t1615 = _t66*_t785;
  const double _t1616 = _t66*_t788;
  const double _t1617 = _t269*_t790;
  const double _t1624 = _t273*_t796;
  const double _t1626 = (0.1e1 / 0.2e1)*_t71;
  const double _t1627 = _t1626*_t273;
  const double _t1632 = _t71*_t806;
  const double _t1633 = _t71*_t809;
  const double _t1636 = xc_powr(nb, -20, 3);
  const double _t1637 = xc_powi(na, -7);
  const double _t1639 = (0.10e2 / 0.3e1)*_t38;
  const double _t1640 = _t235*_t813;
  const double _t1641 = _t10*_t816;
  const double _t1652 = _t249*_t827;
  const double _t1653 = _t14*_t830;
  const double _t1656 = xc_powi(nb, -7);
  const double _t1661 = _t207*_t835;
  const double _t1662 = (0.1e1 / 0.48e2)*_t22;
  const double _t1664 = (0.1e1 / 0.16e2)*_t22;
  const double _t1666 = (0.3e1 / 0.8e1)*_t833;
  const double _t1667 = _t1666*_t38;
  const double _t1673 = (0.3e1 / 0.8e1)*_t844;
  const double _t1674 = (0.3e1 / 0.8e1)*_t842;
  const double _t1675 = _t1674*_t56;
  const double _t1676 = (0.3e1 / 0.8e1)*_t835;
  const double _t1678 = _t230*_t844;
  const double _t1682 = _t269*_t758;
  const double _t1686 = _t273*_t766;
  const double _t873 = _hc5[5]*_t872;
  const double _t877 = -_hc3[1]*_t876;
  const double _t878 = _hc3[4]*(_t28 * _t28 * _t28 * _t28);
  const double _t879 = _hc3[2]*(_t89 * _t89);
  const double _t885 = _hc5[4]*_t299;
  const double _t889 = _hc5[4]*_t431;
  const double _t892 = 0.3e1*_t96;
  const double _t893 = _t141*_t892;
  const double _t895 = 0.3e1*_t313;
  const double _t896 = -_hc5[20]*_t285;
  const double _t897 = _hc5[19]*_t141;
  const double _t898 = 0.2e1*_t308;
  const double _t899 = _hc5[55]*_t82;
  const double _t900 = _hc5[125]*_t23;
  const double _t901 = _hc5[124]*_t23;
  const double _t902 = _hc5[120]*_t29 - _t901;
  const double _t903 = _hc5[54]*_t82;
  const double _t904 = _hc5[120]*_t23;
  const double _t905 = _hc5[110]*_t29 - _t904;
  const double _t906 = _hc5[50]*_t90 + _hc5[50]*_t92 - _t23*_t902 + _t29*_t905 + _t903;
  const double _t907 = -_hc5[19]*_t285;
  const double _t908 = _hc5[15]*_t141;
  const double _t909 = 0.2e1*_t312;
  const double _t910 = _hc5[50]*_t82;
  const double _t911 = _hc5[110]*_t23;
  const double _t912 = _hc4[2]*_t872;
  const double _t913 = _hc4[1]*_t299;
  const double _t914 = _hc4[1]*_t431;
  const double _t915 = 0.3e1*_t102;
  const double _t916 = _t141*_t915;
  const double _t917 = 0.3e1*_t326;
  const double _t918 = -_hc4[5]*_t285;
  const double _t919 = _hc4[4]*_t141;
  const double _t920 = 0.2e1*_t321;
  const double _t921 = _hc4[9]*_t82;
  const double _t922 = -_hc4[14]*_t23;
  const double _t923 = -_hc4[13]*_t23;
  const double _t924 = _hc4[12]*_t29 + _t923;
  const double _t925 = _hc4[8]*_t82;
  const double _t926 = -_hc4[12]*_t23;
  const double _t927 = _hc4[11]*_t29 + _t926;
  const double _t928 = _hc4[7]*_t90 + _hc4[7]*_t92 - _t23*_t924 + _t29*_t927 + _t925;
  const double _t929 = -_hc4[4]*_t285;
  const double _t930 = _hc4[3]*_t141;
  const double _t931 = 0.2e1*_t325;
  const double _t932 = _hc4[7]*_t82;
  const double _t933 = -_hc4[11]*_t23;
  const double _t934 = _hc1[2]*_t872;
  const double _t935 = _hc0[1]*_t876;
  const double _t936 = _hc0[4]*(_t35 * _t35 * _t35 * _t35);
  const double _t937 = _hc0[2]*(_t88 * _t88);
  const double _t940 = _hc0[2]*_t88;
  const double _t941 = _t298*_t940;
  const double _t944 = _t108*_t458;
  const double _t949 = 0.3e1*_t335;
  const double _t950 = 0.3e1*_t333;
  const double _t951 = 0.3e1*_t157;
  const double _t952 = _t113*_t951;
  const double _t953 = _hc0[1]*_t948;
  const double _t954 = _hc1[6]*_t339 + _t349;
  const double _t955 = -0.1e1 / 0.36e2*_hc1[8]*_t21*_t6*_t7;
  const double _t956 = _hc1[7]*_t339;
  const double _t957 = 0.3e1*_t109;
  const double _t958 = 0.3e1*_t107;
  const double _t959 = -_hc1[5]*_t285;
  const double _t960 = _hc1[4]*_t157;
  const double _t961 = _hc1[9]*_t82;
  const double _t962 = -_hc1[14]*_t23;
  const double _t963 = -_hc1[13]*_t23;
  const double _t964 = _hc1[12]*_t36 + _t963;
  const double _t965 = _hc1[8]*_t82;
  const double _t966 = -_hc1[12]*_t23;
  const double _t967 = _hc1[11]*_t36 + _t966;
  const double _t968 = _hc1[7]*_t107 + _hc1[7]*_t109 - _t23*_t964 + _t36*_t967 + _t965;
  const double _t969 = -_hc1[4]*_t285;
  const double _t970 = _hc1[3]*_t157;
  const double _t971 = _hc1[7]*_t82;
  const double _t972 = -_hc1[11]*_t23;
  const double _t973 = _t121*_t871;
  const double _t974 = _t108*_t472;
  const double _t975 = _t136*_t951;
  const double _t976 = _hc0[1]*_hc2[40]*_t338 - _t416;
  const double _t978 = (0.20e2 / 0.9e1)*_hc6[34];
  const double _t979 = (0.2e1 / 0.9e1)*_hc2[49];
  const double _t980 = _hc0[1]*_hc6[37]*_t338 - _t382;
  const double _t982 = _hc6[16]*_t285;
  const double _t983 = -_t982;
  const double _t984 = _hc6[12]*_t333;
  const double _t985 = _hc6[12]*_t335;
  const double _t986 = _hc6[12]*_t157;
  const double _t987 = _t88*_t986;
  const double _t988 = _t298*_t986;
  const double _t992 = _hc6[41]*_t82;
  const double _t993 = _hc6[31]*_t107;
  const double _t994 = _hc6[31]*_t109;
  const double _t995 = _hc6[91]*_t23;
  const double _t996 = _hc6[95]*_t23;
  const double _t997 = _hc0[1]*_hc6[75]*_t35 - _hc6[61]*_t707 - _hc6[65]*_t43 - _t996;
  const double _t998 = _hc6[111]*_t23;
  const double _t999 = _hc0[1]*_hc6[101]*_t35 - _hc6[91]*_t707 - _hc6[95]*_t43 - _t998;
  const double _t1000 = _hc6[101]*_t23;
  const double _t1001 = _hc0[1]*_hc6[81]*_t35 - _hc6[71]*_t707 - _hc6[75]*_t43 - _t1000;
  const double _t1002 = _hc6[44]*_t82;
  const double _t1003 = _hc6[34]*_t107;
  const double _t1004 = _hc6[34]*_t109;
  const double _t1005 = _hc6[98]*_t23;
  const double _t1006 = _hc0[1]*_hc6[78]*_t35 - _hc6[65]*_t707 - _hc6[68]*_t43 - _t1005;
  const double _t1007 = _hc6[114]*_t23;
  const double _t1008 = _hc0[1]*_hc6[104]*_t35 - _hc6[95]*_t707 - _hc6[98]*_t43 - _t1007;
  const double _t1009 = _hc6[104]*_t23;
  const double _t1010 = _hc0[1]*_hc6[84]*_t35 - _hc6[75]*_t707 - _hc6[78]*_t43 - _t1009;
  const double _t1011 = _hc6[25]*_t991 + _hc6[28]*_t387 + _t1002 + _t1003 + _t1004 - _t1006*_t43 - _t1008*_t23 + _t1010*_t36 - _t707*_t997;
  const double _t1012 = _hc6[51]*_t82;
  const double _t1013 = _hc6[47]*_t107;
  const double _t1014 = _hc6[47]*_t109;
  const double _t1015 = _hc6[121]*_t23;
  const double _t1016 = _hc0[1]*_hc6[117]*_t35 - _hc6[111]*_t707 - _hc6[114]*_t43 - _t1015;
  const double _t1017 = _hc6[117]*_t23;
  const double _t1018 = _hc0[1]*_hc6[107]*_t35 - _hc6[101]*_t707 - _hc6[104]*_t43 - _t1017;
  const double _t1019 = _hc6[41]*_t991 + _hc6[44]*_t387 - _t1008*_t43 + _t1012 + _t1013 + _t1014 - _t1016*_t23 + _t1018*_t36 - _t707*_t999;
  const double _t1020 = _hc6[47]*_t82;
  const double _t1021 = _hc6[37]*_t107;
  const double _t1022 = _hc6[37]*_t109;
  const double _t1023 = _hc6[107]*_t23;
  const double _t1024 = _hc0[1]*_hc6[87]*_t35 - _hc6[81]*_t707 - _hc6[84]*_t43 - _t1023;
  const double _t1025 = _hc6[31]*_t991 + _hc6[34]*_t387 - _t1001*_t707 - _t1010*_t43 - _t1018*_t23 + _t1020 + _t1021 + _t1022 + _t1024*_t36;
  const double _t1027 = -_hc2[18]*_t285;
  const double _t1028 = _hc2[14]*_t333;
  const double _t1029 = _hc2[14]*_t335;
  const double _t1030 = _hc2[14]*_t157;
  const double _t1031 = _t1030*_t88;
  const double _t1032 = _t1030*_t298;
  const double _t1033 = _hc2[46]*_t82;
  const double _t1034 = _hc2[36]*_t107;
  const double _t1035 = _hc2[36]*_t109;
  const double _t1036 = _hc2[100]*_t23;
  const double _t1037 = _hc2[116]*_t23;
  const double _t1038 = _hc0[1]*_hc2[106]*_t35 - _hc2[100]*_t43 - _hc6[98]*_t707 - _t1037;
  const double _t1039 = _hc2[106]*_t23;
  const double _t1040 = _hc0[1]*_hc2[86]*_t35 - _hc2[80]*_t43 - _hc6[78]*_t707 - _t1039;
  const double _t1041 = _hc2[53]*_t82;
  const double _t1042 = _hc2[49]*_t107;
  const double _t1043 = _hc2[49]*_t109;
  const double _t1044 = _hc2[123]*_t23;
  const double _t1045 = _hc0[1]*_hc2[119]*_t35 - _hc2[116]*_t43 - _hc6[114]*_t707 - _t1044;
  const double _t1046 = _hc2[119]*_t23;
  const double _t1047 = _hc0[1]*_hc2[109]*_t35 - _hc2[106]*_t43 - _hc6[104]*_t707 - _t1046;
  const double _t1048 = _hc2[46]*_t387 + _hc6[44]*_t991 - _t1008*_t707 - _t1038*_t43 + _t1041 + _t1042 + _t1043 - _t1045*_t23 + _t1047*_t36;
  const double _t1049 = _t301*_t979;
  const double _t1050 = _hc2[39]*_t107;
  const double _t1051 = _hc2[39]*_t109;
  const double _t1052 = _hc2[109]*_t23;
  const double _t1053 = _hc0[1]*_hc2[89]*_t35 - _hc2[86]*_t43 - _hc6[84]*_t707 - _t1052;
  const double _t1054 = _hc2[36]*_t387 + _hc6[34]*_t991 - _t1010*_t707 - _t1040*_t43 - _t1047*_t23 + _t1049 + _t1050 + _t1051 + _t1053*_t36;
  const double _t1055 = -_hc2[20]*_t285;
  const double _t1056 = _hc2[19]*_t157;
  const double _t1057 = _hc2[55]*_t82;
  const double _t1058 = _hc2[125]*_t23;
  const double _t1059 = _hc2[124]*_t23;
  const double _t1060 = _hc0[1]*_hc2[120]*_t35 - _hc2[119]*_t43 - _hc6[117]*_t707 - _t1059;
  const double _t1061 = _hc2[54]*_t82;
  const double _t1062 = _hc2[120]*_t23;
  const double _t1063 = _hc0[1]*_hc2[110]*_t35 - _hc2[109]*_t43 - _hc6[107]*_t707 - _t1062;
  const double _t1064 = _hc2[49]*_t387 + _hc2[50]*_t107 + _hc2[50]*_t109 + _hc6[47]*_t991 - _t1018*_t707 - _t1047*_t43 - _t1060*_t23 + _t1061 + _t1063*_t36;
  const double _t1065 = -_hc2[19]*_t285;
  const double _t1066 = _hc2[15]*_t157;
  const double _t1067 = _hc2[50]*_t82;
  const double _t1068 = _hc2[110]*_t23;
  const double _t1069 = 0.3e1*_t146;
  const double _t1070 = 0.3e1*_t154;
  const double _t1072 = -_hc3[1]*_t1071;
  const double _t1073 = _hc4[3]*_t48;
  const double _t1074 = _hc4[11]*_t54 + _t926;
  const double _t1075 = _hc4[12]*_t54 + _t923;
  const double _t1076 = -_t1075*_t23 + _t925;
  const double _t1077 = -_hc4[7]*_t143 + _hc4[7]*_t432 + _t1074*_t29 + _t1076;
  const double _t1078 = _hc4[10]*_t54 + _t933;
  const double _t1079 = -_t1074*_t23 + _t932;
  const double _t1080 = 0.2e1*_t439;
  const double _t1082 = _t140*_t141;
  const double _t1083 = _hc3[4]*_t293;
  const double _t1084 = _t316*_t48;
  const double _t1086 = _hc4[4]*_t48;
  const double _t1087 = -_t23*(_hc4[13]*_t54 + _t922) + _t921;
  const double _t1088 = _t430*_t543;
  const double _t1090 = _t1089*_t141;
  const double _t1091 = _t429*_t87;
  const double _t1092 = _hc3[2]*_t87;
  const double _t1093 = _t302*_t436 + _t912;
  const double _t1094 = _t150*_t543;
  const double _t1095 = _t303*_t48;
  const double _t1096 = _t141*_t149;
  const double _t1097 = _t302*_t446;
  const double _t1098 = 0.2e1*_t450;
  const double _t1099 = _hc5[19]*_t48;
  const double _t1100 = _hc3[1]*_hc5[120]*_t48 - _hc5[119]*_t148 - _hc7[117]*_t743 - _t901;
  const double _t1101 = -_t23*(_hc3[1]*_hc5[124]*_t48 - _hc5[123]*_t148 - _hc7[121]*_t743 - _t900) + _t899;
  const double _t1102 = _hc3[1]*_hc5[110]*_t48 - _hc5[109]*_t148 - _hc7[107]*_t743 - _t904;
  const double _t1103 = -_t1100*_t23 + _t903;
  const double _t1104 = -_hc5[50]*_t143 + _hc5[50]*_t432 + _t1102*_t29 + _t1103;
  const double _t1105 = _hc5[15]*_t48;
  const double _t1106 = _hc3[1]*_hc5[90]*_t48 - _hc5[89]*_t148 - _hc7[87]*_t743 - _t911;
  const double _t1107 = -_t1102*_t23 + _t910;
  const double _t1108 = 0.3e1*_t172;
  const double _t1109 = 0.3e1*_t162;
  const double _t1110 = _hc0[1]*_t1071;
  const double _t1111 = _hc0[3]*_t457;
  const double _t1112 = _hc1[6]*_t461 + _t349;
  const double _t1113 = _hc1[11]*_t50 + _t966;
  const double _t1114 = _hc1[12]*_t50 + _t963;
  const double _t1115 = -_t1114*_t23 + _t965;
  const double _t1116 = _hc1[7]*_t158 + _hc1[7]*_t159 + _t1113*_t36 + _t1115;
  const double _t1117 = _hc1[10]*_t50 + _t972;
  const double _t1118 = -_t1113*_t23 + _t971;
  const double _t1119 = 0.2e1*_t455;
  const double _t1120 = _hc0[2]*_t338*_t456;
  const double _t1121 = _hc1[7]*_t461;
  const double _t1122 = _t22*(-0.1e1 / 0.6e1*_t1121 - _t955) + _t351;
  const double _t1124 = _t156*_t157;
  const double _t1126 = _hc0[4]*_hc1[1];
  const double _t1127 = 0.2e1*_t460;
  const double _t1128 = 0.2e1*_t1111;
  const double _t1129 = _t1121 + _t346;
  const double _t1130 = -_t23*(_hc1[13]*_t50 + _t962) + _t961;
  const double _t1132 = _t1131*_t458;
  const double _t1133 = _hc0[2]*_hc1[1];
  const double _t1135 = _t87*_t940;
  const double _t1136 = _t1089*_t157;
  const double _t1137 = _t302*_t466 + _t934;
  const double _t1138 = _hc2[40]*_t461 + _t508;
  const double _t1139 = _hc6[87]*_t50;
  const double _t1140 = -_t1023 + _t1139;
  const double _t1141 = _hc6[81]*_t50;
  const double _t1142 = -_t1000 + _t1141;
  const double _t1143 = _hc6[84]*_t50;
  const double _t1144 = -_t1009 + _t1143;
  const double _t1145 = _hc6[37]*_t158;
  const double _t1146 = _hc6[37]*_t159;
  const double _t1147 = _hc6[107]*_t50;
  const double _t1148 = -_t1017 + _t1147;
  const double _t1149 = _t1020 - _t1148*_t23;
  const double _t1150 = _t1140*_t36 - _t1142*_t707 - _t1144*_t43 + _t1145 + _t1146 + _t1149;
  const double _t1151 = _hc2[89]*_t50;
  const double _t1152 = -_t1052 + _t1151;
  const double _t1153 = _hc2[86]*_t50;
  const double _t1154 = -_t1039 + _t1153;
  const double _t1155 = _hc2[39]*_t158;
  const double _t1156 = _hc2[109]*_t50;
  const double _t1157 = -_t1046 + _t1156;
  const double _t1158 = _t1049 - _t1157*_t23;
  const double _t1159 = _hc2[39]*_t159 - _t1144*_t707 + _t1152*_t36 - _t1154*_t43 + _t1155 + _t1158;
  const double _t1160 = _hc2[110]*_t50 - _t1062;
  const double _t1161 = _hc2[120]*_t50 - _t1059;
  const double _t1162 = _t1061 - _t1161*_t23;
  const double _t1163 = _hc2[50]*_t158 + _hc2[50]*_t159 - _t1148*_t707 - _t1157*_t43 + _t1160*_t36 + _t1162;
  const double _t1164 = _hc2[90]*_t50 - _t1068;
  const double _t1165 = _t1067 - _t1160*_t23;
  const double _t1166 = _hc2[50]*_t461;
  const double _t1167 = _t22*((0.1e1 / 0.36e2)*_hc2[54]*_t21*_t6*_t7 - 0.1e1 / 0.6e1*_t1166);
  const double _t1168 = _hc2[39]*_t461;
  const double _t1169 = _hc6[37]*_t461;
  const double _t1170 = _t1169 + _t475;
  const double _t1171 = _hc6[12]*_t455;
  const double _t1172 = _t297*_t986;
  const double _t1173 = _hc6[12]*_t1111;
  const double _t1174 = _hc6[12]*_t460;
  const double _t1175 = _hc6[71]*_t50;
  const double _t1176 = _hc6[75]*_t50;
  const double _t1177 = _t1176 - _t996;
  const double _t1178 = _hc6[31]*_t158;
  const double _t1179 = _hc6[31]*_t159;
  const double _t1180 = _hc6[101]*_t50;
  const double _t1181 = _t1180 - _t998;
  const double _t1182 = -_t1181*_t23 + _t992;
  const double _t1183 = _hc6[78]*_t50;
  const double _t1184 = -_t1005 + _t1183;
  const double _t1185 = _hc6[34]*_t158;
  const double _t1186 = _hc6[34]*_t159;
  const double _t1187 = _hc6[104]*_t50;
  const double _t1188 = -_t1007 + _t1187;
  const double _t1189 = _t1002 - _t1188*_t23;
  const double _t1190 = _t1144*_t36 - _t1177*_t707 - _t1184*_t43 + _t1185 + _t1186 + _t1189;
  const double _t1191 = _hc6[47]*_t158;
  const double _t1192 = _hc6[47]*_t159;
  const double _t1193 = _hc6[117]*_t50;
  const double _t1194 = -_t1015 + _t1193;
  const double _t1195 = _t1012 - _t1194*_t23;
  const double _t1196 = _t1148*_t36 - _t1181*_t707 - _t1188*_t43 + _t1191 + _t1192 + _t1195;
  const double _t1197 = _hc2[14]*_t455;
  const double _t1198 = _hc2[14]*_t1111;
  const double _t1199 = _hc2[14]*_t460;
  const double _t1200 = _t1168 + _t490;
  const double _t1201 = _hc2[80]*_t50;
  const double _t1202 = _hc2[36]*_t158;
  const double _t1203 = _hc2[106]*_t50;
  const double _t1204 = -_t1037 + _t1203;
  const double _t1205 = _t1033 - _t1204*_t23;
  const double _t1206 = _hc2[49]*_t158;
  const double _t1207 = _hc2[119]*_t50;
  const double _t1208 = -_t1044 + _t1207;
  const double _t1209 = _t1041 - _t1208*_t23;
  const double _t1210 = _hc2[49]*_t159 + _t1157*_t36 - _t1188*_t707 - _t1204*_t43 + _t1206 + _t1209;
  const double _t1211 = _t157*_t164;
  const double _t1212 = _hc0[4]*_hc2[4];
  const double _t1213 = _t1166 + _t501;
  const double _t1214 = _t1057 - _t23*(_hc2[124]*_t50 - _t1058);
  const double _t1215 = _t1131*_t472;
  const double _t1216 = _hc0[2]*_hc2[4];
  const double _t1217 = _t302*_t506 + _t973;
  const double _t1218 = _hc3[1]*_t875;
  const double _t1219 = -_hc4[1]*_t1218;
  const double _t1220 = _hc4[6]*_t184 + _hc4[6]*_t186 + _t1078*_t54 + _t1079;
  const double _t1221 = 0.2e1*_t437;
  const double _t1222 = _hc3[2]*_t1073;
  const double _t1223 = _hc4[7]*_t184 + _hc4[7]*_t186 + _t1074*_t54 + _t1076;
  const double _t1224 = -_t1223*_t23 + _t302*_t433 + _t929;
  const double _t1225 = _t183*_t429;
  const double _t1226 = _t141*_t183;
  const double _t1227 = _hc3[3]*_t89;
  const double _t1228 = _hc4[1]*_t185;
  const double _t1229 = _hc3[4]*_t91;
  const double _t1231 = _t48*_t546;
  const double _t1232 = _hc3[2]*_hc4[1];
  const double _t1234 = 0.2e1*_t433;
  const double _t1235 = _hc3[2]*_t1086;
  const double _t1236 = -_t23*(_hc4[8]*_t184 + _hc4[8]*_t186 + _t1075*_t54 + _t1087) + _t302*_t434 + _t918;
  const double _t1237 = _hc3[2]*_t48;
  const double _t1238 = _t1237*_t297;
  const double _t1239 = _hc7[107]*_t23;
  const double _t1240 = _hc3[1]*_hc7[87]*_t48 - _hc7[81]*_t743 - _hc7[84]*_t148 - _t1239;
  const double _t1241 = _hc3[1]*_hc5[89]*_t48 - _hc5[109]*_t23 - _hc5[86]*_t148 - _hc7[84]*_t743;
  const double _t1243 = _hc5[39]*_t557 + _hc5[40]*_t184 + _hc5[40]*_t186 + _hc7[37]*_t1242 + _t1106*_t54 + _t1107 - _t1240*_t743 - _t1241*_t148;
  const double _t1244 = 0.2e1*_t448;
  const double _t1245 = _hc3[2]*_t1105;
  const double _t1246 = _hc7[117]*_t23;
  const double _t1247 = _hc3[1]*_hc7[107]*_t48 - _hc7[101]*_t743 - _hc7[104]*_t148 - _t1246;
  const double _t1248 = _hc3[1]*_hc5[109]*_t48 - _hc5[106]*_t148 - _hc5[119]*_t23 - _hc7[104]*_t743;
  const double _t1249 = _hc5[49]*_t557 + _hc5[50]*_t184 + _hc5[50]*_t186 + _hc7[47]*_t1242 + _t1102*_t54 + _t1103 - _t1247*_t743 - _t1248*_t148;
  const double _t1250 = -_t1249*_t23 + _t302*_t442 + _t907;
  const double _t1251 = _t48*_t561;
  const double _t1252 = _hc3[2]*_hc5[4];
  const double _t1253 = 0.2e1*_t442;
  const double _t1254 = _hc3[2]*_t1099;
  const double _t1255 = _hc7[121]*_t23;
  const double _t1256 = _hc3[1]*_hc7[117]*_t48 - _hc7[111]*_t743 - _hc7[114]*_t148 - _t1255;
  const double _t1257 = _hc3[1]*_hc5[119]*_t48 - _hc5[116]*_t148 - _hc5[123]*_t23 - _hc7[114]*_t743;
  const double _t1258 = -_t23*(_hc5[53]*_t557 + _hc5[54]*_t184 + _hc5[54]*_t186 + _hc7[51]*_t1242 + _t1100*_t54 + _t1101 - _t1256*_t743 - _t1257*_t148) + _t302*_t444 + _t896;
  const double _t1259 = -_hc5[4]*_t1218 + _t873;
  const double _t1260 = _hc0[1]*_t875;
  const double _t1261 = _hc1[1]*_t1260;
  const double _t1262 = _hc1[6]*_t176 + _hc1[6]*_t178 + _t1117*_t50 + _t1118;
  const double _t1263 = _hc0[3]*_t519;
  const double _t1264 = _hc1[3]*_t459;
  const double _t1265 = _hc1[7]*_t176 + _hc1[7]*_t178 + _t1113*_t50 + _t1115;
  const double _t1266 = -_t1265*_t23 + _t302*_t463 + _t969;
  const double _t1268 = _hc0[1]*_t1267;
  const double _t1269 = _hc1[3]*_t1268 + _t1112*_t461 + _t1122 + _t516;
  const double _t1270 = _t175*_t940;
  const double _t1271 = _t157*_t175;
  const double _t1275 = _hc1[4]*_t459;
  const double _t1276 = -_t23*(_hc1[8]*_t176 + _hc1[8]*_t178 + _t1114*_t50 + _t1130) + _t302*_t464 + _t959;
  const double _t1277 = _t297*_t459;
  const double _t1278 = _hc2[4]*_t1260;
  const double _t1279 = _hc2[40]*_t176 + _hc2[40]*_t178 + _t1164*_t50 + _t1165;
  const double _t1280 = _hc6[37]*_t176;
  const double _t1281 = _hc6[37]*_t178;
  const double _t1282 = _t1140*_t50 + _t1149 + _t1280 + _t1281;
  const double _t1283 = _hc2[39]*_t176;
  const double _t1284 = _hc2[39]*_t178;
  const double _t1285 = _t1152*_t50 + _t1158 + _t1283 + _t1284;
  const double _t1286 = _hc2[15]*_t459;
  const double _t1287 = _hc2[50]*_t176 + _hc2[50]*_t178 + _t1160*_t50 + _t1162;
  const double _t1288 = _t1065 - _t1287*_t23 + _t302*_t502;
  const double _t1289 = _hc2[15]*_t1268 + _t1138*_t461 + _t1167 + _t527;
  const double _t1290 = _hc6[12]*_t518;
  const double _t1291 = _hc6[31]*_t176;
  const double _t1292 = _hc6[31]*_t178;
  const double _t1293 = _hc6[34]*_t176;
  const double _t1294 = _hc6[34]*_t178;
  const double _t1295 = _t1144*_t50 + _t1189 + _t1293 + _t1294;
  const double _t1296 = _hc6[12]*_t520;
  const double _t1297 = _hc6[12]*_t459;
  const double _t1298 = _hc6[47]*_t176;
  const double _t1299 = _hc6[47]*_t178;
  const double _t1300 = _t1148*_t50 + _t1195 + _t1298 + _t1299;
  const double _t1301 = -_t1300*_t23 + _t302*_t486 + _t983;
  const double _t1302 = _hc2[36]*_t176;
  const double _t1303 = _hc2[36]*_t178;
  const double _t1304 = _hc2[14]*_t459;
  const double _t1305 = _hc2[49]*_t176;
  const double _t1306 = _hc2[49]*_t178;
  const double _t1307 = _t1157*_t50 + _t1209 + _t1305 + _t1306;
  const double _t1308 = _t1027 - _t1307*_t23 + _t302*_t498;
  const double _t1309 = _hc2[19]*_t459;
  const double _t1310 = _t1055 - _t23*(_hc2[54]*_t176 + _hc2[54]*_t178 + _t1161*_t50 + _t1214) + _t302*_t504;
  const double _t1311 = _hc1[3]*_t578 + _hc1[3]*_t580 + _t1112*_t582 + _t1262*_t50 + _t1264*_t175 + _t1264*_t583 + _t1266 + _t467*_t581;
  const double _t1312 = _hc0[1]*_t287;
  const double _t1313 = _hc0[1]*_t881;
  const double _t1316 = _hc0[1]*_t1315;
  const double _t1317 = 0.3e1*_t158;
  const double _t1319 = 0.3e1*_t1263;
  const double _t1320 = _hc0[1]*_t887;
  const double _t1322 = _t177*_t458;
  const double _t1323 = _t156*_t459;
  const double _t1325 = -_t160*_t891 - _t23*(_hc1[4]*_t578 + _hc1[4]*_t580 + _t1129*_t582 + _t1265*_t50 + _t1275*_t175 + _t1275*_t583 + _t1276 + _t463*_t581) + _t524*_t894 + _t934;
  const double _t1326 = _hc2[15]*_t578 + _hc2[15]*_t580 + _t1138*_t582 + _t1279*_t50 + _t1286*_t175 + _t1286*_t583 + _t1288 + _t509*_t581;
  const double _t1327 = _hc6[12]*_t578;
  const double _t1328 = _hc6[12]*_t580;
  const double _t1329 = _t1297*_t175;
  const double _t1330 = _t1297*_t583;
  const double _t1331 = _hc2[14]*_t578;
  const double _t1332 = _hc2[14]*_t580;
  const double _t1333 = _t1304*_t175;
  const double _t1334 = _t1304*_t583;
  const double _t1335 = _t177*_t472;
  const double _t1336 = _t164*_t459;
  const double _t1337 = -_t170*_t891 - _t23*(_hc2[19]*_t578 + _hc2[19]*_t580 + _t1213*_t582 + _t1287*_t50 + _t1309*_t175 + _t1309*_t583 + _t1310 + _t502*_t581) + _t537*_t894 + _t973;
  const double _t1338 = _hc4[3]*_t589 + _hc4[3]*_t591 + _t1220*_t54 + _t1221*_t184 + _t1221*_t186 + _t1222*_t183 + _t1222*_t592 + _t1224;
  const double _t1339 = _hc3[1]*_t881;
  const double _t1340 = _hc3[1]*_t287;
  const double _t1341 = _hc3[4]*_t28*_t590;
  const double _t1342 = _hc3[1]*_t887;
  const double _t1343 = 0.3e1*_t541;
  const double _t1345 = 0.3e1*_t140;
  const double _t1346 = _hc3[1]*_t1315;
  const double _t1347 = _t1237*_t1324;
  const double _t1349 = _hc3[3]*_t1228;
  const double _t1350 = -_t144*_t891 - _t23*(_hc4[4]*_t589 + _hc4[4]*_t591 + _t1223*_t54 + _t1234*_t184 + _t1234*_t186 + _t1235*_t183 + _t1235*_t592 + _t1236) + _t549*_t894 + _t912;
  const double _t1353 = _hc7[37]*_t186;
  const double _t1354 = _hc7[37]*_t184;
  const double _t1355 = _hc7[101]*_t23;
  const double _t1356 = _hc3[1]*_hc7[81]*_t48 - _hc7[71]*_t743 - _hc7[75]*_t148 - _t1355;
  const double _t1357 = _hc7[104]*_t23;
  const double _t1358 = _hc3[1]*_hc7[84]*_t48 - _hc7[75]*_t743 - _hc7[78]*_t148 - _t1357;
  const double _t1359 = _hc7[31]*_t1242 + _hc7[34]*_t557 + _hc7[47]*_t82 + _t1240*_t54 - _t1247*_t23 + _t1353 + _t1354 - _t1356*_t743 - _t1358*_t148;
  const double _t1360 = _hc5[39]*_t186;
  const double _t1361 = _hc5[39]*_t184;
  const double _t1362 = _hc3[1]*_hc5[86]*_t48 - _hc5[106]*_t23 - _hc5[80]*_t148 - _hc7[78]*_t743;
  const double _t1363 = _hc5[36]*_t557 + _hc5[49]*_t82 + _hc7[34]*_t1242 + _t1241*_t54 - _t1248*_t23 - _t1358*_t743 + _t1360 + _t1361 - _t1362*_t148;
  const double _t1366 = -_hc5[14]*_t1352 + _hc5[15]*_t589 + _hc5[15]*_t591 - _hc7[12]*_t1351 + _t1243*_t54 + _t1244*_t184 + _t1244*_t186 + _t1245*_t183 + _t1245*_t592 + _t1250 - _t1359*_t743 - _t1363*_t148 + _t1364*_t556 + _t1365*_t553;
  const double _t1367 = 0.3e1*_t559;
  const double _t1368 = 0.3e1*_t149;
  const double _t1369 = _hc3[3]*_t560;
  const double _t1370 = _hc7[51]*_t82;
  const double _t1371 = _hc7[47]*_t186;
  const double _t1372 = _hc7[47]*_t184;
  const double _t1373 = _hc7[111]*_t23;
  const double _t1374 = _hc3[1]*_hc7[101]*_t48 - _hc7[91]*_t743 - _hc7[95]*_t148 - _t1373;
  const double _t1375 = _hc7[114]*_t23;
  const double _t1376 = _hc3[1]*_hc7[104]*_t48 - _hc7[95]*_t743 - _hc7[98]*_t148 - _t1375;
  const double _t1377 = _hc7[41]*_t1242 + _hc7[44]*_t557 + _t1247*_t54 - _t1256*_t23 + _t1370 + _t1371 + _t1372 - _t1374*_t743 - _t1376*_t148;
  const double _t1378 = _hc5[49]*_t186;
  const double _t1379 = _hc5[49]*_t184;
  const double _t1380 = _hc3[1]*_hc5[106]*_t48 - _hc5[100]*_t148 - _hc5[116]*_t23 - _hc7[98]*_t743;
  const double _t1381 = _hc5[46]*_t557 + _hc5[53]*_t82 + _hc7[44]*_t1242 + _t1248*_t54 - _t1257*_t23 - _t1376*_t743 + _t1378 + _t1379 - _t1380*_t148;
  const double _t1382 = -_t152*_t891 - _t23*(-_hc5[18]*_t1352 + _hc5[19]*_t589 + _hc5[19]*_t591 - _hc7[16]*_t1351 + _t1249*_t54 + _t1253*_t184 + _t1253*_t186 + _t1254*_t183 + _t1254*_t592 + _t1258 + _t1364*_t568 + _t1365*_t565 - _t1377*_t743 - _t1381*_t148) + _t570*_t894;
  const double _t1384 = _hc0[1]*_t1383;
  const double _t1385 = _hc0[2]*(_t175 * _t175);
  const double _t1386 = _hc0[4]*(_t49 * _t49 * _t49 * _t49);
  const double _t1387 = 0.3e1*_t578;
  const double _t1388 = 0.3e1*_t176;
  const double _t1389 = 0.3e1*_t178;
  const double _t1390 = 0.3e1*_t580;
  const double _t1398 = -_hc3[1]*_t1383;
  const double _t1399 = _hc3[2]*(_t183 * _t183);
  const double _t1400 = _hc3[4]*(_t48 * _t48 * _t48 * _t48);
  const double _t1404 = _t1237*_t1345;
  const double _t1405 = _hc7[16]*_t285;
  const double _t1406 = _hc7[12]*_t591;
  const double _t1407 = _hc7[12]*_t589;
  const double _t1408 = _hc7[12]*_t1237;
  const double _t1409 = 0.2e1*_t553;
  const double _t1410 = _hc7[41]*_t82;
  const double _t1411 = _hc7[31]*_t186;
  const double _t1412 = _hc7[31]*_t184;
  const double _t1413 = _hc7[91]*_t23;
  const double _t1414 = _hc7[95]*_t23;
  const double _t1415 = _hc3[1]*_hc7[75]*_t48 - _hc7[61]*_t743 - _hc7[65]*_t148 - _t1414;
  const double _t1416 = _hc7[44]*_t82;
  const double _t1417 = _hc7[34]*_t186;
  const double _t1418 = _hc7[34]*_t184;
  const double _t1419 = _hc7[98]*_t23;
  const double _t1420 = _hc3[1]*_hc7[78]*_t48 - _hc7[65]*_t743 - _hc7[68]*_t148 - _t1419;
  const double _t1421 = _hc7[25]*_t1242 + _hc7[28]*_t557 + _t1358*_t54 - _t1376*_t23 - _t1415*_t743 + _t1416 + _t1417 + _t1418 - _t1420*_t148;
  const double _t1422 = _hc5[14]*_t591;
  const double _t1423 = _hc5[14]*_t589;
  const double _t1424 = _hc5[14]*_t1237;
  const double _t1425 = _t1424*_t592;
  const double _t1426 = _t1424*_t183;
  const double _t1427 = 0.2e1*_t556;
  const double _t1428 = _hc5[36]*_t186;
  const double _t1429 = _hc5[36]*_t184;
  const double _t1430 = _t1237*_t1368;
  const double _t1431 = 0.3e1*_t114;
  const double _t1433 = _t1432*_t211;
  const double _t1434 = -_t1433;
  const double _t1437 = _hc6[44]*_t1436;
  const double _t1438 = _hc6[95]*_t636;
  const double _t1439 = _hc6[98]*_t636;
  const double _t1440 = (0.1e1 / 0.2e1)*_hc0[1]*_hc6[78]*_t11*_t35*_t66 - _hc6[28]*_t633 - _hc6[65]*_t640 - _hc6[68]*_t203 - _t1439;
  const double _t1441 = _hc6[114]*_t636;
  const double _t1442 = (0.1e1 / 0.2e1)*_hc0[1]*_hc6[104]*_t11*_t35*_t66 - _hc6[44]*_t633 - _hc6[95]*_t640 - _hc6[98]*_t203 - _t1441;
  const double _t1443 = _hc6[104]*_t636;
  const double _t1444 = (0.1e1 / 0.2e1)*_hc0[1]*_hc6[84]*_t11*_t35*_t66 - _hc6[34]*_t633 - _hc6[75]*_t640 - _hc6[78]*_t203 - _t1443;
  const double _t1446 = _hc2[46]*_t1436;
  const double _t1447 = _hc6[68]*_t66;
  const double _t1448 = _hc2[100]*_t636;
  const double _t1449 = _hc2[116]*_t636;
  const double _t1450 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[106]*_t11*_t35*_t66 - _hc2[100]*_t203 - _hc2[46]*_t633 - _hc6[98]*_t640 - _t1449;
  const double _t1451 = _hc2[106]*_t636;
  const double _t1452 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[86]*_t11*_t35*_t66 - _hc2[36]*_t633 - _hc2[80]*_t203 - _hc6[78]*_t640 - _t1451;
  const double _t1453 = _hc2[53]*_t1436;
  const double _t1454 = _hc2[123]*_t636;
  const double _t1455 = _hc2[119]*_t636;
  const double _t1456 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[109]*_t11*_t35*_t66 - _hc2[106]*_t203 - _hc2[49]*_t633 - _hc6[104]*_t640 - _t1455;
  const double _t1457 = _hc2[49]*_t1436;
  const double _t1458 = _hc2[109]*_t636;
  const double _t1459 = 0.3e1*_t103;
  const double _t1460 = -_hc5[18]*_t1432*_t216;
  const double _t1461 = _t141*_t653;
  const double _t1462 = 0.2e1*_t658;
  const double _t1463 = _hc5[53]*_t651;
  const double _t1464 = _hc5[49]*_t696;
  const double _t1465 = _hc5[123]*_t217;
  const double _t1466 = _hc5[119]*_t217;
  const double _t1467 = _hc5[109]*_t655 - _t1466;
  const double _t1468 = _hc5[49]*_t651;
  const double _t1469 = _hc5[39]*_t696;
  const double _t1470 = _hc5[109]*_t217;
  const double _t1471 = 0.2e1*_t672;
  const double _t1472 = _t1168*_t223 + _t661;
  const double _t1473 = _t1143*_t223 - _t1443;
  const double _t1474 = _t1183*_t223 - _t1439;
  const double _t1475 = _t2*_t666;
  const double _t1476 = _t1187*_t223 - _t1441;
  const double _t1477 = _t1437 - _t1476*_t23;
  const double _t1478 = _t1153*_t223 - _t1451;
  const double _t1479 = _t2*_t667;
  const double _t1480 = _t1203*_t223 - _t1449;
  const double _t1481 = _t1446 - _t1480*_t23;
  const double _t1482 = _t1156*_t223 - _t1455;
  const double _t1483 = _t1453 - _t23*(_t1207*_t223 - _t1454);
  const double _t1484 = _t1151*_t223 - _t1458;
  const double _t1485 = _t1457 - _t1482*_t23;
  const double _t1486 = 0.2e1*_t683;
  const double _t1487 = _t48*_t653;
  const double _t1488 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[109]*_t15*_t48*_t71 - _hc5[106]*_t226 - _hc5[49]*_t673 - _hc7[104]*_t679 - _t1466;
  const double _t1489 = _t2*_t677;
  const double _t1490 = _t1489*_t216;
  const double _t1491 = _t1463 - _t23*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[119]*_t15*_t48*_t71 - _hc5[116]*_t226 - _hc5[53]*_t673 - _hc7[114]*_t679 - _t1465);
  const double _t1492 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[89]*_t15*_t48*_t71 - _hc5[39]*_t673 - _hc5[86]*_t226 - _hc7[84]*_t679 - _t1470;
  const double _t1493 = _t1468 - _t1488*_t23;
  const double _t1495 = _t23*(_t1305*_t223 + _t1306*_t223 + _t1482*_t50 + _t1483);
  const double _t1496 = _t1283*_t223 + _t1284*_t223 + _t1484*_t50 + _t1485;
  const double _t1497 = (0.1e1 / 0.2e1)*_hc3[1]*_hc7[84]*_t15*_t48*_t71 - _hc7[104]*_t217 - _hc7[34]*_t673 - _hc7[75]*_t679 - _hc7[78]*_t226;
  const double _t1498 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[86]*_t15*_t48*_t71 - _hc5[106]*_t217 - _hc5[36]*_t673 - _hc5[80]*_t226 - _hc7[78]*_t679;
  const double _t1501 = _hc5[14]*_t1499 + _hc5[36]*_t686 + _hc7[34]*_t1500 + _t1360*_t696 + _t1361*_t696 - _t148*_t1498 + _t1492*_t54 + _t1493 - _t1497*_t743 - _t556*_t673;
  const double _t1502 = 0.2e1*_t676;
  const double _t1503 = (0.1e1 / 0.2e1)*_hc3[1]*_hc7[104]*_t15*_t48*_t71 - _hc7[114]*_t217 - _hc7[44]*_t673 - _hc7[95]*_t679 - _hc7[98]*_t226;
  const double _t1504 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[106]*_t15*_t48*_t71 - _hc5[100]*_t226 - _hc5[116]*_t217 - _hc5[46]*_t673 - _hc7[98]*_t679;
  const double _t1505 = _t1460 - _t23*(_hc5[18]*_t1499 + _hc5[46]*_t686 + _hc7[44]*_t1500 + _t1378*_t696 + _t1379*_t696 - _t148*_t1504 + _t1488*_t54 + _t1491 - _t1503*_t743 - _t568*_t673) + _t302*_t680;
  const double _t1506 = 0.3e1*_t180;
  const double _t1507 = 0.3e1*_t187;
  const double _t1508 = (0.1e1 / 0.2e1)*_hc3[1]*_hc7[78]*_t15*_t48*_t71 - _hc7[28]*_t673 - _hc7[65]*_t679 - _hc7[68]*_t226 - _hc7[98]*_t217;
  const double _t1509 = _hc7[68]*_t71;
  const double _t1511 = _t13*_t982;
  const double _t1512 = -_t1511;
  const double _t1514 = _t13*_t992;
  const double _t1515 = _t13*_t995;
  const double _t1516 = _t13*_t996;
  const double _t1517 = _hc0[1]*_hc6[75]*_t13*_t35 - _hc6[61]*_t236 - _hc6[65]*_t704 - _t1516 - _t374;
  const double _t1518 = _t13*_t998;
  const double _t1519 = _hc0[1]*_hc6[101]*_t13*_t35 - _hc6[91]*_t236 - _hc6[95]*_t704 - _t1518 - _t377;
  const double _t1520 = _t1000*_t13;
  const double _t1521 = _hc0[1]*_hc6[81]*_t13*_t35 - _hc6[71]*_t236 - _hc6[75]*_t704 - _t1520 - _t380;
  const double _t1523 = _t1002*_t13;
  const double _t1524 = _t1005*_t13;
  const double _t1525 = _t1007*_t13;
  const double _t1526 = _hc0[1]*_hc6[104]*_t13*_t35 - _hc6[95]*_t236 - _hc6[98]*_t704 - _t1525 - _t395;
  const double _t1527 = _t1009*_t13;
  const double _t1528 = _hc0[1]*_hc6[84]*_t13*_t35 - _hc6[75]*_t236 - _hc6[78]*_t704 - _t1527 - _t398;
  const double _t1529 = _t1012*_t13;
  const double _t1530 = _t1015*_t13;
  const double _t1531 = _t1017*_t13;
  const double _t1532 = _hc0[1]*_hc6[107]*_t13*_t35 - _hc6[101]*_t236 - _hc6[104]*_t704 - _t1531 - _t409;
  const double _t1533 = _t1020*_t13;
  const double _t1534 = _t1023*_t13;
  const double _t1535 = -_t1405*_t17;
  const double _t1536 = _t141*_t718;
  const double _t1537 = 0.2e1*_t723;
  const double _t1538 = _t1370*_t17;
  const double _t1539 = _t1255*_t17;
  const double _t1540 = _t1246*_t17;
  const double _t1541 = _hc7[107]*_t243 - _t1540;
  const double _t1542 = _t721*_t82;
  const double _t1543 = _hc7[37]*_t17;
  const double _t1544 = _t1239*_t17;
  const double _t1545 = 0.2e1*_t733;
  const double _t1546 = _t1169*_t13 + _t726;
  const double _t1547 = _t1141*_t13 - _t1520;
  const double _t1548 = _t1176*_t13 - _t1516;
  const double _t1549 = _t1180*_t13 - _t1518;
  const double _t1550 = _t1514 - _t1549*_t23;
  const double _t1551 = _t1143*_t13 - _t1527;
  const double _t1552 = _t1187*_t13 - _t1525;
  const double _t1553 = _t1523 - _t1552*_t23;
  const double _t1554 = _t1147*_t13 - _t1531;
  const double _t1555 = _t1529 - _t23*(_t1193*_t13 - _t1530);
  const double _t1556 = _t1139*_t13 - _t1534;
  const double _t1557 = _t1533 - _t1554*_t23;
  const double _t1558 = 0.2e1*_t739;
  const double _t1559 = _t48*_t718;
  const double _t1560 = _hc3[1]*_hc7[107]*_t17*_t48 - _hc7[101]*_t250 - _hc7[104]*_t734 - _t1540 - _t441;
  const double _t1561 = _t1538 - _t23*(_hc3[1]*_hc7[117]*_t17*_t48 - _hc7[111]*_t250 - _hc7[114]*_t734 - _t1539 - _t443);
  const double _t1562 = _hc3[1]*_hc7[87]*_t17*_t48 - _hc7[81]*_t250 - _hc7[84]*_t734 - _t1544 - _t447;
  const double _t1563 = _t1542 - _t1560*_t23;
  const double _t1564 = _t23*(_t1298*_t13 + _t1299*_t13 + _t1554*_t50 + _t1555);
  const double _t1565 = _t1280*_t13 + _t1281*_t13 + _t1556*_t50 + _t1557;
  const double _t1566 = _hc3[1]*_hc7[81]*_t17*_t48 - _hc7[71]*_t250 - _hc7[75]*_t734 - _t1355*_t17 - _t552;
  const double _t1567 = _hc3[1]*_hc7[84]*_t17*_t48 - _hc7[75]*_t250 - _hc7[78]*_t734 - _t1357*_t17 - _t555;
  const double _t1570 = _hc7[31]*_t1569 + _hc7[34]*_t1568 + _t1353*_t17 + _t1354*_t17 - _t148*_t1567 + _t1562*_t54 + _t1563 - _t1566*_t743 - _t554 + _t558;
  const double _t1571 = 0.2e1*_t735;
  const double _t1572 = _t1237*_t718;
  const double _t1573 = _hc3[1]*_hc7[101]*_t17*_t48 - _hc7[91]*_t250 - _hc7[95]*_t734 - _t1373*_t17 - _t563;
  const double _t1574 = _hc3[1]*_hc7[104]*_t17*_t48 - _hc7[95]*_t250 - _hc7[98]*_t734 - _t1375*_t17 - _t567;
  const double _t1575 = _t1535 - _t23*(_hc7[41]*_t1569 + _hc7[44]*_t1568 + _t1371*_t17 + _t1372*_t17 - _t148*_t1574 + _t1560*_t54 + _t1561 - _t1573*_t743 - _t566 + _t569) + _t302*_t736;
  const double _t1577 = _hc3[1]*_hc7[75]*_t17*_t48 - _hc7[61]*_t250 - _hc7[65]*_t734 - _t1414*_t17 - _t606;
  const double _t1583 = _hc2[106]*_t1582 - 0.1e1 / 0.24e2*_hc2[49]*_t11*_t21*_t258*_t6*_t7;
  const double _t1584 = _hc2[36]*_t36;
  const double _t1585 = _hc2[100]*_t1582 - 0.1e1 / 0.24e2*_hc2[46]*_t11*_t21*_t258*_t6*_t7;
  const double _t1587 = _hc6[34]*_t36;
  const double _t1588 = -0.1e1 / 0.24e2*_hc6[44]*_t11*_t21*_t258*_t6*_t7 + _hc6[98]*_t1582;
  const double _t1589 = _hc2[116]*_t1582;
  const double _t1592 = _hc2[18]*_t1590*_t1591 - 0.1e1 / 0.18e2*_hc2[46]*_t256*_t38*_t6*_t7*_t80;
  const double _t1593 = _t29*_t767;
  const double _t1595 = _hc5[106]*_t1594 - 0.1e1 / 0.24e2*_hc5[49]*_t15*_t21*_t265*_t6*_t7;
  const double _t1596 = _hc5[116]*_t1594;
  const double _t1599 = _hc5[14]*_t767;
  const double _t1600 = _hc5[18]*_t1591*_t1597;
  const double _t1601 = -0.1e1 / 0.18e2*_hc5[46]*_t263*_t56*_t6*_t7*_t80 + _t1600;
  const double _t1602 = (0.1e1 / 0.4e1)*_hc0[1]*_hc2[86]*_t256*_t38*_t49 - _t1583 - _t491*_t773;
  const double _t1603 = _t1592 + _t23*(_hc2[53]*_t1590*_t760 + (0.1e1 / 0.4e1)*_t1203*_t256*_t38 - _t1589 - _t497*_t773);
  const double _t1604 = (0.1e1 / 0.2e1)*_t1489;
  const double _t1609 = _t23*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[106]*_t263*_t48*_t56 - _hc5[100]*_t1605 + (0.1e1 / 0.3e1)*_hc5[18]*_t265*_t60 - _hc5[46]*_t1606 - _hc5[49]*_t54*_t767 + (0.1e1 / 0.24e2)*_hc5[53]*_t15*_t21*_t265*_t6*_t7 + (0.5e1 / 0.12e2)*_hc7[44]*_t230*_t265*tb - _hc7[98]*_t1608 - _t1596);
  const double _t1610 = (0.1e1 / 0.4e1)*_hc3[1]*_hc5[86]*_t263*_t48*_t56 + (0.1e1 / 0.3e1)*_hc5[14]*_t265*_t60 - _hc5[36]*_t1606 - _hc5[39]*_t54*_t767 - _hc5[80]*_t1605 + (0.5e1 / 0.12e2)*_hc7[34]*_t230*_t265*tb - _hc7[78]*_t1608 - _t1595;
  const double _t1611 = _hc5[36]*_t54;
  const double _t1612 = _hc7[34]*_t54;
  const double _t1614 = _t631*_t66*_t789;
  const double _t1618 = _hc6[95]*_t1617;
  const double _t1619 = _hc6[98]*_t1617;
  const double _t1620 = _hc6[114]*_t1617;
  const double _t1621 = _hc6[104]*_t1617;
  const double _t1622 = _t631*_t71*_t795;
  const double _t1623 = (0.1e1 / 0.2e1)*_t798;
  const double _t1625 = _hc7[114]*_t1624;
  const double _t1628 = _t1627*_t29;
  const double _t1629 = _hc7[104]*_t1624;
  const double _t1630 = _t23*(_t1187*_t802 - _t1620);
  const double _t1631 = _t1143*_t802 - _t1621;
  const double _t1634 = (0.1e1 / 0.2e1)*_hc3[1]*_hc7[84]*_t273*_t48*_t71 - _hc7[34]*_t1632 - _hc7[75]*_t1633 - _hc7[78]*_t805 - _t1629;
  const double _t1635 = _t1622 - _t23*((0.1e1 / 0.2e1)*_hc3[1]*_hc7[104]*_t273*_t48*_t71 - _hc7[44]*_t1632 - _hc7[95]*_t1633 - _hc7[98]*_t805 - _t1625);
  const double _t1638 = _t119*_t992;
  const double _t1642 = _t119*_t995;
  const double _t1643 = _t119*_t996;
  const double _t1644 = _t119*_t998;
  const double _t1645 = _t1000*_t119;
  const double _t1646 = _t1410*_t194;
  const double _t1647 = _hc7[31]*_t194;
  const double _t1648 = _t1373*_t194;
  const double _t1649 = _t1355*_t194;
  const double _t1650 = _t1141*_t119 - _t1645;
  const double _t1651 = _t1638 - _t23*(_t1180*_t119 - _t1644);
  const double _t1654 = _hc3[1]*_hc7[81]*_t194*_t48 - _hc7[31]*_t826 - _hc7[71]*_t1652 - _hc7[75]*_t1653 - _t1649;
  const double _t1655 = _t1646 - _t23*(_hc3[1]*_hc7[101]*_t194*_t48 - _hc7[41]*_t826 - _hc7[91]*_t1652 - _hc7[95]*_t1653 - _t1648);
  const double _t1657 = _t38*_t834;
  const double _t1658 = _t11*_t837;
  const double _t1659 = _hc2[30]*_t840;
  const double _t1660 = _hc6[68]*_t258;
  const double _t1663 = _hc2[100]*_t1662*_t839;
  const double _t1665 = _hc2[18]*_t11*_t1664*_t835;
  const double _t1668 = _t56*_t843;
  const double _t1669 = _t15*_t846;
  const double _t1670 = _hc5[30]*_t849;
  const double _t1671 = _hc5[100]*_t1662*_t848;
  const double _t1672 = _hc5[18]*_t15*_t1664*_t844;
  const double _t1677 = _hc7[68]*_t265;
  const double _t1679 = _t234*_t852;
  const double _t1680 = _t269*_t854;
  const double _t1681 = _hc6[65]*_t1637;
  const double _t1683 = -0.1e1 / 0.24e2*_hc6[44]*_t21*_t258*_t269*_t6*_t7 + _hc6[98]*_t234*_t256*_t760;
  const double _t1684 = _t248*_t857;
  const double _t1685 = _t273*_t859;
  const double _t1687 = -0.1e1 / 0.24e2*_hc7[44]*_t21*_t265*_t273*_t6*_t7 + _hc7[98]*_t248*_t263*_t760;
  const double _t1688 = _hc7[65]*_t1656;
  const double _t1689 = _t355*_t862;
  const double _t1690 = _hc6[61]/xc_powr(na, 22, 3);
  const double _t1691 = _hc6[95]*_t355*_t790;
  const double _t1692 = _t594*_t865;
  const double _t1693 = _hc7[95]*_t594*_t796;
  const double _t1694 = _hc7[61]/xc_powr(nb, 22, 3);
  const double _t1695 = _t627*_t995;
  const double _t1696 = _t1413*_t692;
  const double d4F_dna4 = _t3*(my_piecewise3(_t18, 0, _hc1[0]*(_hc2[4]*_t935 + _hc2[4]*_t936 + _hc2[4]*_t937 + _hc2[4]*_t941 + (0.6160e4 / 0.81e2)*_hc6[1]*_t787 + (0.28e2 / 0.3e1)*_t10*_t119*_t402 + (0.40e2 / 0.3e1)*_t115*_t384*ta + (0.3640e4 / 0.81e2)*_t118*_t699 - 0.440e3 / 0.9e1*_t125*_t355*ta - _t132*_t891 + _t136*_t950 - _t23*(-_hc2[18]*_t1026 + _hc2[19]*_t333 + _hc2[19]*_t335 - _hc6[16]*_t981 - _t1019*_t707 - _t1048*_t43 + _t1055 + _t1056*_t298 + _t1056*_t88 + _t1064*_t36 - _t23*(_hc2[53]*_t387 + _hc2[54]*_t107 + _hc2[54]*_t109 + _hc6[51]*_t991 - _t1016*_t707 - _t1045*_t43 + _t1057 + _t1060*_t36 - _t23*(_hc0[1]*_hc2[124]*_t35 - _hc2[123]*_t43 - _hc6[121]*_t707 - _t1058)) + _t302*_t408 + _t341*(_hc0[1]*_hc2[50]*_t338 - _t411) + _t342*_t412 + _t379*_t989 + _t397*_t990) - 0.280e3 / 0.9e1*_t234*_t363 + _t298*_t975 + _t36*(-_hc2[14]*_t1026 + _hc2[15]*_t333 + _hc2[15]*_t335 - _hc6[12]*_t981 - _t1025*_t707 - _t1054*_t43 - _t1064*_t23 + _t1065 + _t1066*_t298 + _t1066*_t88 + _t302*_t412 + _t341*_t976 + _t342*_t417 + _t36*(_hc2[39]*_t387 + _hc2[40]*_t107 + _hc2[40]*_t109 + _hc6[37]*_t991 - _t1024*_t707 - _t1053*_t43 - _t1063*_t23 + _t1067 + _t36*(_hc0[1]*_hc2[90]*_t35 - _hc2[89]*_t43 - _hc6[87]*_t707 - _t1068)) + _t383*_t989 + _t401*_t990) + _t360*_t938 + _t360*_t939 + _t365*_t949 + _t413*_t894 + _t422*_t958 - _t43*(-_hc2[11]*_t1026 - _hc6[9]*_t981 - _t1011*_t707 + _t1027 + _t1028 + _t1029 + _t1031 + _t1032 - _t1048*_t23 + _t1054*_t36 + _t302*_t397 + _t341*(_hc0[1]*_hc2[39]*_t338 - _t400) + _t342*_t401 + _t376*_t989 + _t394*_t990 - _t43*(_hc2[30]*_t387 + _hc6[28]*_t991 - _t1006*_t707 + _t1033 + _t1034 + _t1035 - _t1038*_t23 + _t1040*_t36 - _t43*(_hc0[1]*_hc2[80]*_t35 - _hc2[70]*_t43 - _hc6[68]*_t707 - _t1036))) - _t707*(-_hc6[6]*_t981 - _t1011*_t43 - _t1019*_t23 + _t1025*_t36 - _t237*_t358 + _t302*_t379 + _t341*_t980 + _t342*_t383 + _t372*_t989 + _t376*_t990 - _t707*(_hc6[21]*_t991 + _hc6[25]*_t387 + _t1001*_t36 - _t23*_t999 - _t43*_t997 - _t707*(_hc0[1]*_hc6[71]*_t35 - _hc6[56]*_t707 - _hc6[61]*_t43 - _t995) + _t992 + _t993 + _t994) + _t983 + _t984 + _t985 + _t987 + _t988) + _t88*_t975 + _t943*_t974 + _t946*_t974 + _t948*_t974 + _t957*(_hc2[15]*_t953 + _t22*(-0.1e1 / 0.6e1*_hc2[50]*_t339 + (0.1e1 / 0.36e2)*_hc2[54]*_t22 + (0.5e1 / 0.18e2)*_hc6[47]*_t977 + _t42*_t979) + _t339*_t976 + _t42*((0.16e2 / 0.9e1)*_hc2[36]*_t42 - 0.4e1 / 0.3e1*_hc2[39]*_t339 + _t22*_t979 + _t977*_t978) + _t421 - _t707*_t980) + _t973) + _hc2[0]*(_hc1[1]*_t935 + _hc1[1]*_t936 + _hc1[1]*_t937 + _hc1[1]*_t941 - _t111*_t891 + _t113*_t950 - _t23*(_hc1[4]*_t333 + _hc1[4]*_t335 - _t23*(_hc1[8]*_t107 + _hc1[8]*_t109 - _t23*(_hc1[13]*_t36 + _t962) + _t36*_t964 + _t961) + _t298*_t960 + _t302*_t345 + _t341*(_t346 + _t956) + _t342*_t347 + _t36*_t968 + _t88*_t960 + _t959) + _t298*_t952 + _t336*_t938 + _t336*_t939 + _t340*_t949 + _t348*_t894 + _t353*_t958 + _t36*(_hc1[3]*_t333 + _hc1[3]*_t335 - _t23*_t968 + _t298*_t970 + _t302*_t347 + _t341*_t954 + _t342*_t350 + _t36*(_hc1[6]*_t107 + _hc1[6]*_t109 - _t23*_t967 + _t36*(_hc1[10]*_t36 + _t972) + _t971) + _t88*_t970 + _t969) + _t88*_t952 + _t934 + _t943*_t944 + _t944*_t946 + _t944*_t948 + _t957*(_hc1[3]*_t953 + _t22*(-_t955 - 0.1e1 / 0.6e1*_t956) + _t339*_t954 + _t352)) + 0.6e1*_t114*_t137 + 0.4e1*_t354*_t45 + 0.4e1*_t37*_t423) + my_piecewise3(_t19, 0, _hc4[0]*(_hc5[4]*_t877 + _hc5[4]*_t878 + _hc5[4]*_t879 - _t23*(_hc5[19]*_t292 + _hc5[19]*_t294 - _t23*(_hc5[54]*_t90 + _hc5[54]*_t92 - _t23*(_hc5[124]*_t29 - _t900) + _t29*_t902 + _t899) + _t29*_t906 + _t299*_t897 + _t302*_t306 + _t89*_t897 + _t896 + _t898*_t90 + _t898*_t92) + _t29*(_hc5[15]*_t292 + _hc5[15]*_t294 - _t23*_t906 + _t29*(_hc5[40]*_t90 + _hc5[40]*_t92 - _t23*_t905 + _t29*(_hc5[90]*_t29 - _t911) + _t910) + _t299*_t908 + _t302*_t308 + _t89*_t908 + _t90*_t909 + _t907 + _t909*_t92) + _t292*_t892 + _t294*_t892 + _t299*_t893 + _t300*_t883 + _t300*_t884 + _t309*_t894 + _t429*_t885 + _t431*_t885 + _t873 + _t888*_t889 + _t889*_t89 + _t89*_t893 - _t891*_t94 + _t895*_t90 + _t895*_t92) + _hc5[0]*(_hc4[1]*_t877 + _hc4[1]*_t878 + _hc4[1]*_t879 - _t100*_t891 + _t142*_t883 + _t142*_t884 - _t23*(_hc4[4]*_t292 + _hc4[4]*_t294 - _t23*(_hc4[8]*_t90 + _hc4[8]*_t92 - _t23*(_hc4[13]*_t29 + _t922) + _t29*_t924 + _t921) + _t29*_t928 + _t299*_t919 + _t302*_t319 + _t89*_t919 + _t90*_t920 + _t918 + _t92*_t920) + _t29*(_hc4[3]*_t292 + _hc4[3]*_t294 - _t23*_t928 + _t29*(_hc4[6]*_t90 + _hc4[6]*_t92 - _t23*_t927 + _t29*(_hc4[10]*_t29 + _t933) + _t932) + _t299*_t930 + _t302*_t321 + _t89*_t930 + _t90*_t931 + _t92*_t931 + _t929) + _t292*_t915 + _t294*_t915 + _t299*_t916 + _t322*_t894 + _t429*_t913 + _t431*_t913 + _t888*_t914 + _t89*_t914 + _t89*_t916 + _t90*_t917 + _t912 + _t917*_t92) + 0.6e1*_t103*_t97 + 0.4e1*_t30*_t327 + 0.4e1*_t314*_t32)) + 0.4e1*_t328 + 0.4e1*_t424;
  const double d4F_dna3_dnb = _t3*(my_piecewise3(_t18, 0, _hc1[0]*(_hc2[4]*_t1110 + _hc2[4]*_t1135 - _t1026*_t169 - _t1085*_t132 + _t1119*_t136 + _t1123*_t360 + _t1125*_t1212 + _t1127*_t136 + _t1128*_t365 + _t1134*_t1216 + _t1136*_t136 + _t1211*_t298 + _t1211*_t88 + _t1215*_t298 + _t1215*_t88 + _t1217 + _t158*_t422 + _t159*_t422 + _t164*_t333 - _t166*_t981 - _t170*_t285 - _t23*(_hc2[19]*_t1111 + _hc2[19]*_t455 + _hc2[19]*_t460 + _t1055 + _t1056*_t297 + _t107*_t502 + _t109*_t1213 + _t1163*_t36 - _t1196*_t707 - _t1210*_t43 + _t158*_t412 + _t159*_t412 - _t23*(_hc2[54]*_t158 + _hc2[54]*_t159 + _t1161*_t36 - _t1194*_t707 - _t1208*_t43 + _t1214) + _t387*_t498 + _t408*_t82 + _t486*_t991 + _t504*_t82) + _t332*_t536 + _t335*_t474 + _t341*(_hc2[15]*_t1120 + _t1138*_t339 + _t1167 - _t1170*_t707 + _t42*((0.2e1 / 0.9e1)*_hc2[49]*_t21*_t6*_t7 - 0.4e1 / 0.3e1*_t1168) + _t511) + _t342*_t512 + _t36*(_hc2[15]*_t1111 + _hc2[15]*_t455 + _hc2[15]*_t460 + _t1065 + _t1066*_t297 + _t107*_t509 + _t109*_t1138 - _t1150*_t707 - _t1159*_t43 - _t1163*_t23 + _t158*_t417 + _t159*_t417 + _t36*(_hc2[40]*_t158 + _hc2[40]*_t159 - _t1140*_t707 - _t1152*_t43 + _t1164*_t36 + _t1165) + _t387*_t492 + _t412*_t82 + _t477*_t991 + _t502*_t82) + _t360*_t454 + _t413*_t82 - _t43*(_t1027 + _t1030*_t297 + _t107*_t492 + _t109*_t1200 + _t1159*_t36 - _t1190*_t707 + _t1197 + _t1198 + _t1199 - _t1210*_t23 + _t158*_t401 + _t159*_t401 + _t387*_t495 + _t397*_t82 - _t43*(_hc2[36]*_t159 + _t1154*_t36 - _t1184*_t707 + _t1202 + _t1205 - _t43*(-_t1036 + _t1201)) + _t482*_t991 + _t498*_t82) + _t488*_t989 + _t500*_t990 - _t707*(_t107*_t477 + _t109*_t1170 + _t1150*_t36 + _t1171 + _t1172 + _t1173 + _t1174 - _t1190*_t43 - _t1196*_t23 + _t158*_t383 + _t159*_t383 + _t379*_t82 + _t387*_t482 + _t479*_t991 + _t486*_t82 - _t707*(_t1142*_t36 - _t1177*_t43 + _t1178 + _t1179 + _t1182 - _t707*(_t1175 - _t995)) + _t983) + _t887*_t974) + _hc2[0]*(_hc1[1]*_t1110 + _hc1[1]*_t1135 - _t1085*_t111 + _t1119*_t113 + _t1123*_t336 + _t1124*_t298 + _t1124*_t88 + _t1125*_t1126 + _t1127*_t113 + _t1128*_t340 + _t113*_t1136 + _t1132*_t298 + _t1132*_t88 + _t1133*_t1134 + _t1137 + _t156*_t333 + _t158*_t353 + _t159*_t353 - _t160*_t285 - _t23*(_hc1[4]*_t1111 + _hc1[4]*_t455 + _hc1[4]*_t460 + _t107*_t463 + _t109*_t1129 + _t1116*_t36 + _t158*_t347 + _t159*_t347 - _t23*(_hc1[8]*_t158 + _hc1[8]*_t159 + _t1114*_t36 + _t1130) + _t297*_t960 + _t345*_t82 + _t464*_t82 + _t959) + _t332*_t523 + _t335*_t462 + _t336*_t454 + _t341*(_hc1[3]*_t1120 + _t1112*_t339 + _t1122 + _t468) + _t342*_t470 + _t348*_t82 + _t36*(_hc1[3]*_t1111 + _hc1[3]*_t455 + _hc1[3]*_t460 + _t107*_t467 + _t109*_t1112 - _t1116*_t23 + _t158*_t350 + _t159*_t350 + _t297*_t970 + _t347*_t82 + _t36*(_hc1[6]*_t158 + _hc1[6]*_t159 + _t1117*_t36 + _t1118) + _t463*_t82 + _t969) + _t887*_t944) + _t1108*_t114 + _t1109*_t137 + _t329*_t471 + _t330*_t513 + _t354*_t51 + _t423*_t52) + my_piecewise3(_t19, 0, _hc4[0]*(_hc5[4]*_t1072 - _hc5[4]*_t1091 + _t1081*_t300 + _t1083*_t150 - _t1085*_t94 - _t1090*_t96 - _t1092*_t885 + _t1094*_t299 + _t1094*_t89 + _t1095*_t429 + _t1095*_t431 + _t1096*_t299 + _t1096*_t89 + _t1097 + _t1098*_t90 + _t1098*_t92 - _t143*_t313 + _t149*_t292 + _t149*_t294 - _t152*_t285 - _t23*(_hc5[19]*_t428 + _t1099*_t429 + _t1099*_t431 + _t1104*_t29 - _t143*_t308 - _t23*(-_hc5[54]*_t143 + _hc5[54]*_t432 + _t1100*_t29 + _t1101) - _t297*_t897 + _t306*_t82 + _t308*_t432 + _t442*_t90 + _t442*_t92 + _t444*_t82 + _t896) + _t29*(_hc5[15]*_t428 - _t1104*_t23 + _t1105*_t429 + _t1105*_t431 - _t143*_t312 + _t29*(-_hc5[40]*_t143 + _hc5[40]*_t432 + _t1106*_t29 + _t1107) - _t297*_t908 + _t308*_t82 + _t312*_t432 + _t442*_t82 + _t448*_t90 + _t448*_t92 + _t907) + _t291*_t562 + _t300*_t427 + _t303*_t428 + _t309*_t82 + _t313*_t432 + _t873 - _t887*_t889) + _hc5[0]*(_hc4[1]*_t1072 - _hc4[1]*_t1091 - _t100*_t1085 - _t102*_t1090 + _t1080*_t90 + _t1080*_t92 + _t1081*_t142 + _t1082*_t299 + _t1082*_t89 + _t1083*_t430 + _t1084*_t429 + _t1084*_t431 + _t1088*_t299 + _t1088*_t89 - _t1092*_t913 + _t1093 + _t140*_t292 + _t140*_t294 + _t142*_t427 - _t143*_t326 - _t144*_t285 - _t23*(_hc4[4]*_t428 + _t1077*_t29 + _t1086*_t429 + _t1086*_t431 - _t143*_t321 - _t23*(-_hc4[8]*_t143 + _hc4[8]*_t432 + _t1075*_t29 + _t1087) - _t297*_t919 + _t319*_t82 + _t321*_t432 + _t433*_t90 + _t433*_t92 + _t434*_t82 + _t918) + _t29*(_hc4[3]*_t428 + _t1073*_t429 + _t1073*_t431 - _t1077*_t23 - _t143*_t325 + _t29*(-_hc4[6]*_t143 + _hc4[6]*_t432 + _t1078*_t29 + _t1079) - _t297*_t930 + _t321*_t82 + _t325*_t432 + _t433*_t82 + _t437*_t90 + _t437*_t92 + _t929) + _t291*_t548 + _t316*_t428 + _t322*_t82 + _t326*_t432 - _t887*_t914) + _t103*_t1070 + _t1069*_t97 + _t281*_t451 + _t282*_t440 + _t314*_t55 + _t327*_t62)) + _t425 + 0.3e1*_t452 + 0.3e1*_t514;
  const double d4F_dna2_dnb2 = _t3*(my_piecewise3(_t18, 0, _hc1[0]*(_hc2[4]*_t1270 + _t107*_t528 - _t1085*_t170 + _t1089*_t1211 + _t1089*_t1215 + _t109*_t1289 + _t1119*_t164 + _t1127*_t164 + _t1128*_t474 + _t1212*_t1273 + _t1216*_t1233 + _t1217 + _t1263*_t365 + _t1267*_t974 + _t1271*_t136 + _t1272*_t472 + _t1274*_t536 + _t1277*_t136 + _t1278 - _t132*_t285 - _t136*_t518 - _t136*_t520 - _t23*(_hc2[19]*_t1263 - _hc2[19]*_t518 - _hc2[19]*_t520 + _t1056*_t175 + _t1287*_t36 - _t1300*_t707 - _t1307*_t43 + _t1309*_t297 + _t1310 + _t502*_t521 + _t502*_t522) - _t296*_t360 + _t36*(_hc2[15]*_t1263 - _hc2[15]*_t518 - _hc2[15]*_t520 + _t1066*_t175 + _t1279*_t36 - _t1282*_t707 - _t1285*_t43 + _t1286*_t297 + _t1288 + _t509*_t521 + _t509*_t522) - _t360*_t882 + _t387*_t535 - _t43*(_hc2[14]*_t1263 - _hc2[14]*_t518 - _hc2[14]*_t520 + _t1030*_t175 + _t1285*_t36 - _t1295*_t707 + _t1304*_t297 + _t1308 - _t43*(_t1154*_t50 + _t1205 + _t1302 + _t1303) + _t492*_t521 + _t492*_t522) + _t512*_t521 + _t512*_t522 + _t531*_t991 + _t537*_t82 - _t707*(_hc6[12]*_t1263 + _t1282*_t36 - _t1290 - _t1295*_t43 - _t1296 + _t1297*_t297 + _t1301 + _t175*_t986 + _t477*_t521 + _t477*_t522 - _t707*(_t1142*_t50 + _t1182 + _t1291 + _t1292))) + _hc2[0]*(_hc1[1]*_t1270 + _t107*_t517 - _t1085*_t160 + _t1089*_t1124 + _t1089*_t1132 + _t109*_t1269 - _t111*_t285 + _t1119*_t156 + _t1126*_t1273 + _t1127*_t156 + _t1128*_t462 + _t113*_t1271 + _t113*_t1277 - _t113*_t518 - _t113*_t520 + _t1133*_t1233 + _t1137 + _t1261 + _t1263*_t340 + _t1267*_t944 + _t1272*_t458 + _t1274*_t523 - _t23*(_hc1[4]*_t1263 - _hc1[4]*_t518 - _hc1[4]*_t520 + _t1265*_t36 + _t1275*_t297 + _t1276 + _t175*_t960 + _t463*_t521 + _t463*_t522) - _t296*_t336 - _t336*_t882 + _t36*(_hc1[3]*_t1263 - _hc1[3]*_t518 - _hc1[3]*_t520 + _t1262*_t36 + _t1264*_t297 + _t1266 + _t175*_t970 + _t467*_t521 + _t467*_t522) + _t470*_t521 + _t470*_t522 + _t524*_t82) + _t105*_t539 + _t114*_t179 + _t137*_t180 + 0.4e1*_t162*_t172 + _t174*_t513 + 0.2e1*_t45*_t526 + 0.2e1*_t471*_t51) + my_piecewise3(_t19, 0, _hc4[0]*(_hc5[4]*_t1225 - _t1085*_t152 - _t1089*_t1094 - _t1089*_t1096 + _t1097 + _t1098*_t432 + _t1226*_t96 + _t1227*_t560 + _t1229*_t560 + _t1230*_t562 + _t1233*_t1252 - _t1238*_t96 + _t1251*_t429 + _t1251*_t431 + _t1259 + _t183*_t889 - _t23*(_hc5[19]*_t542 + _hc5[19]*_t544 + _hc5[19]*_t547 + _t1249*_t29 + _t1253*_t432 - _t1254*_t297 + _t1258 + _t183*_t897 - _t442*_t545) - _t285*_t94 + _t29*(_hc5[15]*_t542 + _hc5[15]*_t544 + _hc5[15]*_t547 + _t1243*_t29 + _t1244*_t432 - _t1245*_t297 + _t1250 + _t183*_t908 - _t448*_t545) + _t296*_t300 + _t300*_t882 + _t428*_t561 - _t450*_t545 + _t542*_t96 + _t544*_t96 + _t547*_t96 + _t559*_t90 + _t559*_t92 + _t570*_t82) + _hc5[0]*(_hc4[1]*_t1225 - _t100*_t285 + _t102*_t1226 - _t102*_t1238 + _t102*_t542 + _t102*_t544 + _t102*_t547 + _t1080*_t432 - _t1082*_t1089 - _t1085*_t144 - _t1088*_t1089 + _t1093 + _t1219 + _t1227*_t1228 + _t1228*_t1229 + _t1230*_t548 + _t1231*_t429 + _t1231*_t431 + _t1232*_t1233 + _t142*_t296 + _t142*_t882 + _t183*_t914 - _t23*(_hc4[4]*_t542 + _hc4[4]*_t544 + _hc4[4]*_t547 + _t1223*_t29 + _t1234*_t432 - _t1235*_t297 + _t1236 + _t183*_t919 - _t433*_t545) + _t29*(_hc4[3]*_t542 + _hc4[3]*_t544 + _hc4[3]*_t547 + _t1220*_t29 + _t1221*_t432 - _t1222*_t297 + _t1224 + _t183*_t930 - _t437*_t545) + _t428*_t546 - _t439*_t545 + _t541*_t90 + _t541*_t92 + _t549*_t82) + _t103*_t199 + 0.4e1*_t146*_t154 + _t182*_t451 + _t187*_t97 + 0.2e1*_t30*_t551 + 0.2e1*_t440*_t62 + _t572*_t79)) + 0.2e1*_t452 + 0.2e1*_t514 + 0.2e1*_t540 + 0.2e1*_t573;
  const double d4F_dna_dnb3 = _t3*(my_piecewise3(_t18, 0, _hc1[0]*(_hc2[4]*_t1313 + _t1211*_t1318 + _t1212*_t1314 + _t1215*_t175 + _t1215*_t583 + _t1216*_t1321 + _t1278 - _t1312*_t164 - _t1315*_t536 - _t1316*_t164 + _t1317*_t528 + _t1319*_t474 + _t1320*_t528 + _t1324*_t1336 + _t1326*_t36 + _t1335*_t887 + _t1337 - _t287*_t536 + _t360*_t577 - _t43*(_t1200*_t582 + _t1285*_t50 + _t1308 + _t1331 + _t1332 + _t1333 + _t1334 + _t492*_t581) - _t707*(_t1170*_t582 + _t1282*_t50 + _t1301 + _t1327 + _t1328 + _t1329 + _t1330 + _t477*_t581)) + _hc2[0]*(_hc1[1]*_t1313 + _t1124*_t1318 + _t1126*_t1314 + _t1132*_t175 + _t1132*_t583 + _t1133*_t1321 + _t1261 + _t1311*_t36 - _t1312*_t156 - _t1315*_t523 - _t1316*_t156 + _t1317*_t517 + _t1319*_t462 + _t1320*_t517 + _t1322*_t887 + _t1323*_t1324 + _t1325 - _t287*_t523 + _t336*_t577) + _t1108*_t180 + _t1109*_t179 + _t37*_t584 + _t45*_t585 + _t526*_t575 + _t539*_t574) + my_piecewise3(_t19, 0, _hc4[0]*(-_hc5[4]*_t1339 + _hc5[4]*_t1341 + _t1094*_t183 + _t1094*_t592 + _t1096*_t1344 - _t1252*_t1348 + _t1259 + _t1315*_t562 + _t1340*_t149 - _t1342*_t559 + _t1346*_t149 - _t1347*_t149 + _t1366*_t29 + _t1367*_t432 + _t1368*_t544 - _t1369*_t887 + _t1382 + _t287*_t562 + _t300*_t576) + _hc5[0]*(-_hc4[1]*_t1339 + _hc4[1]*_t1341 + _t1082*_t1344 + _t1088*_t183 + _t1088*_t592 + _t1219 - _t1232*_t1348 + _t1315*_t548 + _t1338*_t29 + _t1340*_t140 - _t1342*_t541 + _t1343*_t432 + _t1345*_t544 + _t1346*_t140 - _t1347*_t140 - _t1349*_t887 + _t1350 + _t142*_t576 + _t287*_t548) + _t1069*_t199 + _t1070*_t187 + _t30*_t593 + _t32*_t622 + _t551*_t587 + _t572*_t588)) + 0.3e1*_t540 + 0.3e1*_t573 + _t624;
  const double d4F_dnb4 = _t3*(my_piecewise3(_t18, 0, _hc1[0]*(_hc2[4]*_t1384 + _hc2[4]*_t1385 + _hc2[4]*_t1386 + _t1216*_t1393 + _t1267*_t1335 + _t1289*_t1389 + _t1318*_t1336 + _t1326*_t50 + _t1335*_t1394 + _t1335*_t1395 + _t1336*_t1397 + _t1337 + _t1387*_t164 + _t1388*_t528 + _t1390*_t474 + _t1392*_t536 + _t1396*_t536) + _hc2[0]*(_hc1[1]*_t1384 + _hc1[1]*_t1385 + _hc1[1]*_t1386 + _t1133*_t1393 + _t1267*_t1322 + _t1269*_t1389 + _t1311*_t50 + _t1318*_t1323 + _t1322*_t1394 + _t1322*_t1395 + _t1323*_t1397 + _t1325 + _t1387*_t156 + _t1388*_t517 + _t1390*_t462 + _t1392*_t523 + _t1396*_t523) + 0.6e1*_t179*_t180 + 0.4e1*_t51*_t585 + 0.4e1*_t52*_t584) + my_piecewise3(_t19, 0, _hc4[0]*(_hc5[4]*_t1398 + _hc5[4]*_t1399 + _hc5[4]*_t1400 + (0.6160e4 / 0.81e2)*_hc7[1]*_t808 + _t1252*_t1401 + _t1366*_t54 + _t1367*_t184 + _t1367*_t186 + _t1368*_t589 + _t1368*_t591 + _t1369*_t1402 + _t1369*_t183 + _t1369*_t592 + _t1382 + _t1391*_t562 + (0.28e2 / 0.3e1)*_t14*_t194*_t617 + _t1403*_t562 + _t1430*_t183 + _t1430*_t592 - _t148*(-_hc5[11]*_t1352 - _hc5[18]*_t285 - _hc7[9]*_t1351 + _t1363*_t54 + _t1364*_t616 + _t1365*_t608 - _t1381*_t23 - _t1421*_t743 + _t1422 + _t1423 + _t1425 + _t1426 + _t1427*_t184 + _t1427*_t186 - _t148*(_hc5[30]*_t557 + _hc5[46]*_t82 + _hc7[28]*_t1242 + _t1362*_t54 - _t1380*_t23 - _t1420*_t743 + _t1428 + _t1429 - _t148*(_hc3[1]*_hc5[80]*_t48 - _hc5[100]*_t23 - _hc5[70]*_t148 - _hc7[68]*_t743)) + _t302*_t568) - 0.440e3 / 0.9e1*_t190*_t594*tb + (0.40e2 / 0.3e1)*_t196*_t609*tb - 0.280e3 / 0.9e1*_t248*_t618 + (0.3640e4 / 0.81e2)*_t59*_t746 - _t743*(-_hc7[6]*_t1351 + _t1359*_t54 + _t1364*_t608 + _t1365*_t604 - _t1377*_t23 - _t1405 + _t1406 + _t1407 + _t1408*_t183 + _t1408*_t592 + _t1409*_t184 + _t1409*_t186 - _t1421*_t148 - _t251*_t597 + _t302*_t565 - _t743*(_hc7[21]*_t1242 + _hc7[25]*_t557 + _t1356*_t54 - _t1374*_t23 + _t1410 + _t1411 + _t1412 - _t1415*_t148 - _t743*(_hc3[1]*_hc7[71]*_t48 - _hc7[56]*_t743 - _hc7[61]*_t148 - _t1413))) + _t873) + _hc5[0]*(_hc4[1]*_t1398 + _hc4[1]*_t1399 + _hc4[1]*_t1400 + _t1232*_t1401 + _t1338*_t54 + _t1343*_t184 + _t1343*_t186 + _t1345*_t589 + _t1345*_t591 + _t1349*_t1402 + _t1349*_t183 + _t1349*_t592 + _t1350 + _t1391*_t548 + _t1403*_t548 + _t1404*_t183 + _t1404*_t592) + 0.6e1*_t187*_t199 + 0.4e1*_t55*_t622 + 0.4e1*_t593*_t62)) + 0.4e1*_t586 + 0.4e1*_t623;
  const double d4F_dna3_dgaa = _t3*my_piecewise3(_t18, 0, _hc1[0]*(-0.140e3 / 0.27e2*_hc2[11]*_t786 + _t1028*_t223 + _t1029*_t223 + _t1031*_t223 + _t1032*_t223 + _t120*_t129*_t66 + _t1434 - 0.220e3 / 0.27e2*_t206*_t813 - _t23*(_hc2[18]*_t1445 + _hc2[46]*_t625 + _hc6[44]*_t1435 + _t1042*_t223 + _t1043*_t223 - _t1442*_t707 - _t1450*_t43 + _t1453 + _t1456*_t36 - _t23*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[119]*_t11*_t35*_t66 - _hc2[116]*_t203 - _hc2[53]*_t633 - _hc6[114]*_t640 - _t1454) - _t397*_t633) - 0.140e3 / 0.27e2*_t234*_t67 + _t302*_t644 + _t341*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[39]*_t11*_t338*_t66 - _t647) + _t342*_t648 + _t36*(_hc2[14]*_t1445 + _hc2[36]*_t625 + _t1050*_t223 + _t1051*_t223 - _t1444*_t707 - _t1452*_t43 - _t1456*_t23 + _t1457 + _t36*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[89]*_t11*_t35*_t66 - _hc2[39]*_t633 - _hc2[86]*_t203 - _hc6[84]*_t640 - _t1458) - _t401*_t633 + _t628*_t978*ta) - _t402*_t633 - _t43*(_hc2[11]*_t1445 + _hc2[30]*_t625 + _hc6[28]*_t1435 + _t1034*_t223 + _t1035*_t223 - _t1440*_t707 + _t1446 - _t1450*_t23 + _t1452*_t36 - _t394*_t633 - _t43*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[80]*_t11*_t35*_t66 - _hc2[30]*_t633 - _hc2[70]*_t203 - _t1447*_t635 - _t1448)) + _t638*_t989 + _t642*_t990 - _t707*(_hc6[25]*_t1435 + _hc6[28]*_t625 + _t1003*_t223 + _t1004*_t223 + _t1437 - _t1440*_t43 - _t1442*_t23 + _t1444*_t36 + _t205*_t626 - _t376*_t633 - _t707*((0.1e1 / 0.2e1)*_hc0[1]*_hc6[75]*_t11*_t35*_t66 - _hc6[25]*_t633 - _hc6[61]*_t640 - _hc6[65]*_t203 - _t1438))) + _t1431*_t213 + _t202*_t354 + _t330*_t649) + 0.3e1*_t650;
  const double d4F_dna3_dgbb = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_t1460 + _t1461*_t299 + _t1461*_t89 + _t1462*_t90 + _t1462*_t92 - _t23*(_t1463 + _t1464*_t90 + _t1464*_t92 + _t1467*_t29 - _t23*(_hc5[119]*_t655 - _t1465)) + _t29*(-_t1467*_t23 + _t1468 + _t1469*_t90 + _t1469*_t92 + _t29*(_hc5[89]*_t655 - _t1470)) + _t292*_t653 + _t294*_t653 + _t302*_t656) + _t1459*_t221 + _t215*_t327 + _t281*_t659) + 0.3e1*_t660;
  const double d4F_dna2_dnb_dgaa = _t1471 + _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t1030*_t210*_t87 + _t107*_t662 + _t109*_t1472 + _t1197*_t223 + _t1198*_t223 + _t1199*_t223 + _t1434 + _t1445*_t169 + _t158*_t648 + _t159*_t648 - _t23*(_hc2[49]*_t1479 + _t1206*_t223 - _t1476*_t707 - _t1480*_t43 + _t1482*_t36 + _t1483 - _t498*_t633) + _t36*(_hc2[39]*_t1479 + _t1155*_t223 - _t1473*_t707 - _t1478*_t43 + _t1484*_t36 + _t1485 - _t492*_t633) + _t387*_t665 - _t43*(_hc2[36]*_t1479 + _t1202*_t223 - _t1474*_t707 + _t1478*_t36 + _t1481 - _t43*(_t1201*_t223 - _t1448) - _t495*_t633) - _t500*_t633 + _t644*_t82 + _t663*_t991 + _t669*_t82 - _t707*(_t11*_t1475*_t645 + _t1185*_t223 + _t1473*_t36 - _t1474*_t43 + _t1477 - _t482*_t633 - _t707*(_t1176*_t223 - _t1438))) + _t105*_t671 + _t114*_t224 + _t202*_t471 + _t213*_t453 + _t52*_t649) + _t650;
  const double d4F_dna2_dnb_dgbb = _t1486 + _t3*my_piecewise3(_t19, 0, _hc4[0]*(-_t141*_t219*_t87 - _t143*_t658 + _t1460 + _t1487*_t429 + _t1487*_t431 - _t23*(-_hc5[49]*_t1490 + _t1464*_t432 + _t1488*_t29 + _t1491) + _t29*(-_hc5[39]*_t1490 + _t1469*_t432 + _t1492*_t29 + _t1493) + _t428*_t653 + _t432*_t658 + _t656*_t82 + _t676*_t90 + _t676*_t92 + _t680*_t82) + _t103*_t232 + _t215*_t440 + _t221*_t426 + _t55*_t659 + _t682*_t79) + _t660;
  const double d4F_dna_dnb2_dgaa = _t1471 + _t3*my_piecewise3(_t18, 0, _hc1[0]*(-_hc0[1]*_hc2[14]*_t1494*_t210 + _hc0[1]*_t1496*_t35 + 0.4e1*_hc0[1]*_t2*_t662*_t85 + (0.1e1 / 0.2e1)*_hc0[2]*_hc2[14]*_t11*_t175*_t35*_t66 + 0.2e1*_hc0[2]*_hc2[14]*_t11*_t2*_t49*_t66*_t85 + 0.2e1*_hc0[2]*_t35*_t49*_t662 + (0.1e1 / 0.2e1)*_hc0[3]*_hc2[14]*_t11*_t177*_t338*_t66 - _t1433 - _t1495 - _t43*(_t1302*_t223 + _t1303*_t223 + _t1478*_t50 + _t1481) - _t535*_t633 + (0.4e1 / 0.9e1)*_t6*_t669*_t7*_t80 - _t668 - _t707*(_t1293*_t223 + _t1294*_t223 + _t1473*_t50 + _t1477)) + _t174*_t671 + _t180*_t213 + _t202*_t526 + _t224*_t453 + _t37*_t684) + _t685;
  const double d4F_dna_dnb2_dgbb = _t1486 + _t3*my_piecewise3(_t19, 0, _hc4[0]*(_hc3[1]*_t1494*_t219 + _t1226*_t653 - _t1424*_t216*_t87 + _t1501*_t29 + _t1502*_t432 + _t1505 + _t544*_t653 - _t545*_t676 + _t678) + _t182*_t682 + _t187*_t221 + _t215*_t551 + _t232*_t426 + _t32*_t697) + _t698;
  const double d4F_dnb3_dgaa = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t1331*_t223 + _t1332*_t223 + _t1333*_t223 + _t1334*_t223 + _t1434 + _t1472*_t582 - _t1495 + _t1496*_t50 + _t302*_t669 + _t581*_t662) + _t1506*_t224 + _t202*_t585 + _t574*_t684) + 0.3e1*_t685;
  const double d4F_dnb3_dgbb = _t3*my_piecewise3(_t19, 0, _hc4[0]*(-0.140e3 / 0.27e2*_hc5[11]*_t807 + _t1364*_t690 + _t1365*_t688 + _t1422*_t696 + _t1423*_t696 + _t1425*_t696 + _t1426*_t696 - _t148*(_hc5[11]*_t1499 + _hc5[30]*_t686 + _hc5[46]*_t651 + _hc7[28]*_t1500 + _t1428*_t696 + _t1429*_t696 - _t148*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[80]*_t15*_t48*_t71 - _hc5[100]*_t217 - _hc5[30]*_t673 - _hc5[70]*_t226 - _t1509*_t674) + _t1498*_t54 - _t1504*_t23 - _t1508*_t743 - _t616*_t673) + _t1501*_t54 + _t1502*_t184 + _t1502*_t186 + _t1505 + _t193*_t195*_t71 - 0.220e3 / 0.27e2*_t229*_t827 - 0.140e3 / 0.27e2*_t248*_t72 - _t617*_t673 - _t743*(_hc7[25]*_t1500 + _hc7[28]*_t686 + _hc7[44]*_t651 + _t1417*_t696 + _t1418*_t696 - _t148*_t1508 + _t1497*_t54 - _t1503*_t23 + _t228*_t691 - _t608*_t673 - _t743*((0.1e1 / 0.2e1)*_hc3[1]*_hc7[75]*_t15*_t48*_t71 - _hc7[25]*_t673 - _hc7[61]*_t679 - _hc7[65]*_t226 - _hc7[95]*_t217))) + _t1507*_t232 + _t215*_t593 + _t588*_t697) + 0.3e1*_t698;
  const double d4F_dna3_dta = _t3*my_piecewise3(_t18, 0, _hc1[0]*(-0.440e3 / 0.27e2*_hc6[6]*_t1510*ta + _t13*_t984 + _t13*_t985 + _t13*_t987 + _t13*_t988 + _t1512 - _t23*(_hc6[41]*_t1513 + _hc6[44]*_t1522 + _t1013*_t13 + _t1014*_t13 - _t1519*_t707 - _t1526*_t43 + _t1529 + _t1532*_t36 - _t23*(_hc0[1]*_hc6[117]*_t13*_t35 - _hc6[111]*_t236 - _hc6[114]*_t704 - _t1530 - _t406) + _t403 - _t405) - 0.280e3 / 0.27e2*_t237*_t813 + _t302*_t711 + _t341*(_hc0[1]*_hc6[37]*_t13*_t338 - _t713) + _t342*_t714 - _t357 + _t36*(_hc6[31]*_t1513 + _hc6[34]*_t1522 + _t1021*_t13 + _t1022*_t13 - _t1521*_t707 - _t1528*_t43 - _t1532*_t23 + _t1533 + _t36*(_hc0[1]*_hc6[87]*_t13*_t35 - _hc6[81]*_t236 - _hc6[84]*_t704 - _t1534 - _t414) - _t418 + _t420) + _t362 - _t385 - _t43*(_hc6[25]*_t1513 + _hc6[28]*_t1522 + _t1003*_t13 + _t1004*_t13 - _t1517*_t707 + _t1523 - _t1526*_t23 + _t1528*_t36 + _t386 - _t391 - _t43*(_hc0[1]*_hc6[78]*_t13*_t35 - _hc6[65]*_t236 - _hc6[68]*_t704 - _t1524 - _t392)) + _t706*_t989 - _t707*(_hc6[21]*_t1513 + _t13*_t993 + _t13*_t994 + _t1514 - _t1517*_t43 - _t1519*_t23 + _t1521*_t36 + _t366 - _t373 + _t702*_t815 - _t707*(_hc0[1]*_hc6[71]*_t13*_t35 - _hc6[56]*_t236 - _hc6[61]*_t704 - _t1515 - _t370)) + _t709*_t990) + _t1431*_t240 + _t330*_t715 + _t354*_t75) + 0.3e1*_t716;
  const double d4F_dna3_dtb = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_t1535 + _t1536*_t299 + _t1536*_t89 + _t1537*_t90 + _t1537*_t92 - _t23*(_t1538 + _t1541*_t29 - _t23*(_hc7[117]*_t243 - _t1539) + _t721*_t90 + _t721*_t92) + _t29*(-_t1541*_t23 + _t1542 + _t1543*_t90 + _t1543*_t92 + _t29*(_hc7[87]*_t243 - _t1544)) + _t292*_t718 + _t294*_t718 + _t302*_t720) + _t1459*_t244 + _t281*_t724 + _t327*_t77) + 0.3e1*_t725;
  const double d4F_dna2_dnb_dta = _t1545 + _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t107*_t727 + _t109*_t1546 + _t1171*_t13 + _t1172*_t13 + _t1173*_t13 + _t1174*_t13 + _t1512 + _t158*_t714 + _t159*_t714 - _t23*(_t1191*_t13 + _t1192*_t13 - _t1549*_t707 - _t1552*_t43 + _t1554*_t36 + _t1555 - _t503) + _t36*(_t1145*_t13 + _t1146*_t13 - _t1547*_t707 - _t1551*_t43 + _t1556*_t36 + _t1557 - _t510) + _t387*_t729 - _t43*(_t1185*_t13 + _t1186*_t13 - _t1548*_t707 + _t1551*_t36 + _t1553 - _t43*(_t1183*_t13 - _t1524) - _t493) + _t473 - _t489 - _t707*(_t1178*_t13 + _t1179*_t13 + _t1547*_t36 - _t1548*_t43 + _t1550 - _t480 - _t707*(_t1175*_t13 - _t1515)) + _t711*_t82 + _t728*_t991 + _t730*_t82) + _t105*_t732 + _t114*_t246 + _t240*_t453 + _t471*_t75 + _t52*_t715) + _t716;
  const double d4F_dna2_dnb_dtb = _t1558 + _t3*my_piecewise3(_t19, 0, _hc4[0]*(-_t143*_t723 + _t1535 - _t1536*_t297 + _t1559*_t429 + _t1559*_t431 - _t23*(-_t143*_t721 + _t1560*_t29 + _t1561 + _t432*_t721) + _t29*(-_t143*_t1543 + _t1543*_t432 + _t1562*_t29 + _t1563) + _t428*_t718 + _t432*_t723 + _t720*_t82 + _t735*_t90 + _t735*_t92 + _t736*_t82) + _t103*_t253 + _t244*_t426 + _t440*_t77 + _t55*_t724 + _t738*_t79) + _t725;
  const double d4F_dna_dnb2_dta = _t1545 + _t3*my_piecewise3(_t18, 0, _hc1[0]*(_hc0[1]*_t1565*_t35 + 0.4e1*_hc0[1]*_t2*_t727*_t85 + _hc0[2]*_hc6[12]*_t13*_t175*_t35 + 0.4e1*_hc0[2]*_hc6[12]*_t13*_t2*_t49*_t85 + 0.2e1*_hc0[2]*_t35*_t49*_t727 + _hc0[3]*_hc6[12]*_t13*_t177*_t338 - _t1290*_t13 - _t1296*_t13 - _t1511 - _t1564 - _t43*(_t1293*_t13 + _t1294*_t13 + _t1551*_t50 + _t1553) - _t532 + (0.4e1 / 0.9e1)*_t6*_t7*_t730*_t80 - _t707*(_t1291*_t13 + _t1292*_t13 + _t1547*_t50 + _t1550)) + _t174*_t732 + _t180*_t240 + _t246*_t453 + _t37*_t740 + _t526*_t75) + _t741;
  const double d4F_dna_dnb2_dtb = _t1558 + _t3*my_piecewise3(_t19, 0, _hc4[0]*(_t1226*_t718 + _t1570*_t29 + _t1571*_t432 - _t1572*_t297 + _t1575 + _t542*_t718 + _t544*_t718 - _t545*_t735 + _t547*_t718) + _t182*_t738 + _t187*_t244 + _t253*_t426 + _t32*_t749 + _t551*_t77) + _t750;
  const double d4F_dnb3_dta = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t13*_t1327 + _t13*_t1328 + _t13*_t1329 + _t13*_t1330 + _t1512 + _t1546*_t582 - _t1564 + _t1565*_t50 + _t302*_t730 + _t581*_t727) + _t1506*_t246 + _t574*_t740 + _t585*_t75) + 0.3e1*_t741;
  const double d4F_dnb3_dtb = _t3*my_piecewise3(_t19, 0, _hc4[0]*(-0.440e3 / 0.27e2*_hc7[6]*_t1576*tb + _t1364*_t744 + _t1365*_t742 + _t1406*_t17 + _t1407*_t17 - _t148*(_hc7[25]*_t1569 + _hc7[28]*_t1568 + _t1416*_t17 + _t1417*_t17 + _t1418*_t17 - _t148*(_hc3[1]*_hc7[78]*_t17*_t48 - _hc7[65]*_t250 - _hc7[68]*_t734 - _t1419*_t17 - _t615) + _t1567*_t54 - _t1574*_t23 - _t1577*_t743 + _t611 - _t614) + _t1570*_t54 + _t1571*_t184 + _t1571*_t186 + _t1572*_t183 + _t1572*_t592 + _t1575 - 0.280e3 / 0.27e2*_t251*_t827 - _t596 - _t610 + _t621 - _t743*(_hc7[21]*_t1569 + _t1410*_t17 + _t1411*_t17 + _t1412*_t17 - _t148*_t1577 + _t1566*_t54 - _t1573*_t23 + _t598 - _t605 - _t743*(_hc3[1]*_hc7[71]*_t17*_t48 - _hc7[56]*_t250 - _hc7[61]*_t734 - _t1413*_t17 - _t602) + _t745*_t829)) + _t1507*_t253 + _t588*_t749 + _t593*_t77) + 0.3e1*_t750;
  const double d4F_dna2_dgaa2 = _t3*my_piecewise3(_t18, 0, _hc1[0]*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[36]*_t256*_t38*_t88 + _hc0[1]*_t35*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[86]*_t256*_t35*_t38 + (0.1e1 / 0.3e1)*_hc2[14]*_t258*_t41 - _hc2[36]*_t1578 - _hc2[39]*_t36*_t773 - _hc2[80]*_t1579 + (0.5e1 / 0.12e2)*_hc6[34]*_t207*_t258*ta - _hc6[78]*_t1581 - _t1583) + (0.1e1 / 0.4e1)*_hc0[2]*_hc2[36]*_t108*_t256*_t38 + (0.7e1 / 0.9e1)*_hc2[11]*_t256*_t355 + (0.7e1 / 0.9e1)*_hc2[30]*_t66*_t813 + (0.10e2 / 0.9e1)*_hc6[28]*_t1510*_t256*ta - 0.7e1 / 0.9e1*_t119*_t259 + (0.1e1 / 0.3e1)*_t129*_t258*_t41 - _t1586*_t642 - _t1592 - _t23*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[106]*_t256*_t35*_t38 - _hc2[100]*_t1579 + (0.1e1 / 0.3e1)*_hc2[18]*_t258*_t41 - _hc2[46]*_t1578 - _hc2[49]*_t36*_t773 + (0.1e1 / 0.24e2)*_hc2[53]*_t11*_t21*_t258*_t6*_t7 + (0.5e1 / 0.12e2)*_hc6[44]*_t207*_t258*ta - _hc6[98]*_t1581 - _t1589) - _t389*_t773 - _t390*_t773 - _t43*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[80]*_t256*_t35*_t38 + (0.1e1 / 0.3e1)*_hc2[11]*_t258*_t41 - _hc2[70]*_t1579 + (0.5e1 / 0.12e2)*_hc6[28]*_t207*_t258*ta - _hc6[68]*_t1581 - _t1584*_t773 - _t1585 - _t753*_t754) - 0.10e2 / 0.9e1*_t627*_t853*ta - _t707*((0.1e1 / 0.4e1)*_hc0[1]*_hc6[78]*_t256*_t35*_t38 + (0.5e1 / 0.12e2)*_hc6[25]*_t207*_t258*ta - _hc6[28]*_t1578 - _hc6[65]*_t1581 - _hc6[68]*_t1579 + (0.1e1 / 0.3e1)*_hc6[9]*_t258*_t41 - _t1587*_t773 - _t1588)) + _t105*_t762 + _t114*_t751 - _t114*_t752) + 0.2e1*_t763;
  const double d4F_dna2_dgbb2 = _t3*my_piecewise3(_t19, 0, _hc4[0]*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[36]*_t263*_t56*_t89 + _hc3[1]*_t28*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[86]*_t263*_t28*_t56 - _hc5[39]*_t1593 - _t1595) + (0.1e1 / 0.4e1)*_hc3[2]*_hc5[36]*_t263*_t56*_t91 - _t1599*_t90 - _t1599*_t92 - _t1601 - _t23*(_hc5[106]*_t1598*_t29 - _hc5[49]*_t1593 + _hc5[53]*_t1597*_t760 - _t1596)) + _t103*_t764 - _t103*_t765 + _t771*_t79) + 0.2e1*_t772;
  const double d4F_dna_dnb_dgaa2 = _t3*my_piecewise3(_t18, 0, _hc1[0]*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[36]*_t2*_t256*_t38*_t85 + _hc0[1]*_t1602*_t35 + (0.1e1 / 0.4e1)*_hc0[2]*_hc2[36]*_t256*_t35*_t38*_t49 - 0.1e1 / 0.2e1*_hc2[14]*_t1475*_t1590 - _t1586*_t665 - _t1603 + (0.1e1 / 0.3e1)*_t169*_t258*_t41 - _t43*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[80]*_t256*_t38*_t49 - _t1585 - _t494*_t773) - _t496*_t773 - _t707*((0.1e1 / 0.4e1)*_hc0[1]*_hc6[78]*_t256*_t38*_t49 - _t1588 - _t481*_t773)) + _t162*_t751 - _t162*_t752 + _t37*_t774 + _t52*_t762) + _t763 + _t775;
  const double d4F_dna_dnb_dgbb2 = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_hc5[14]*_t1597*_t1604 + _hc5[36]*_t1598*_t432 - _hc5[36]*_t1604*_t769 + _hc5[46]*_t1591*_t769 - _t1599*_t432 - _t1600 - _t1609 + _t1610*_t29) + _t146*_t764 - _t146*_t765 + _t32*_t781 + _t55*_t771) + _t772 + _t782;
  const double d4F_dnb2_dgaa2 = _t3*my_piecewise3(_t18, 0, _hc1[0]*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[36]*_t175*_t256*_t38 + _hc0[1]*_t1602*_t49 + (0.1e1 / 0.4e1)*_hc0[2]*_hc2[36]*_t177*_t256*_t38 - _t1603 - _t533*_t773 - _t534*_t773) + _t174*_t774 + _t180*_t751 - _t180*_t752) + 0.2e1*_t775;
  const double d4F_dnb2_dgbb2 = _t3*my_piecewise3(_t19, 0, _hc4[0]*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[36]*_t183*_t263*_t56 + _hc3[1]*_t1610*_t48 + (0.1e1 / 0.4e1)*_hc3[2]*_hc5[36]*_t185*_t263*_t56 + (0.7e1 / 0.9e1)*_hc5[11]*_t263*_t594 + (0.7e1 / 0.9e1)*_hc5[30]*_t71*_t827 + (0.10e2 / 0.9e1)*_hc7[28]*_t1576*_t263*tb - _t148*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[80]*_t263*_t48*_t56 - _hc5[100]*_t1594 + (0.1e1 / 0.3e1)*_hc5[11]*_t265*_t60 + (0.1e1 / 0.24e2)*_hc5[46]*_t15*_t21*_t265*_t6*_t7 - _hc5[70]*_t1605 + (0.5e1 / 0.12e2)*_hc7[28]*_t230*_t265*tb - _hc7[68]*_t1608 - _t1611*_t767 - _t776*_t777) - _t1601 - _t1609 + (0.1e1 / 0.3e1)*_t193*_t265*_t60 - 0.7e1 / 0.9e1*_t194*_t266 - _t61*_t690*_t71 - _t612*_t767 - _t613*_t767 - 0.10e2 / 0.9e1*_t692*_t858*tb - _t743*((0.1e1 / 0.4e1)*_hc3[1]*_hc7[78]*_t263*_t48*_t56 + (0.5e1 / 0.12e2)*_hc7[25]*_t230*_t265*tb - _hc7[28]*_t1606 + (0.1e1 / 0.24e2)*_hc7[44]*_t15*_t21*_t265*_t6*_t7 - _hc7[65]*_t1608 - _hc7[68]*_t1605 + (0.1e1 / 0.3e1)*_hc7[9]*_t265*_t60 - _hc7[98]*_t1594 - _t1612*_t767)) + _t182*_t781 + _t187*_t764 - _t187*_t765) + 0.2e1*_t782;
  const double d4F_dna2_dgaa_dta = _t3*my_piecewise3(_t18, 0, _hc1[0]*((0.14e2 / 0.9e1)*_hc6[28]*_t1510 + _t1003*_t802 + _t1004*_t802 + _t1613*_t630*_t634 + _t1614 - _t23*((0.1e1 / 0.2e1)*_hc0[1]*_hc6[104]*_t269*_t35*_t66 - _hc6[44]*_t1615 - _hc6[95]*_t1616 - _hc6[98]*_t784 - _t1620) + _t36*((0.1e1 / 0.2e1)*_hc0[1]*_hc6[84]*_t269*_t35*_t66 - _hc6[34]*_t1615 - _hc6[75]*_t1616 - _hc6[78]*_t784 - _t1621) - _t43*((0.1e1 / 0.2e1)*_hc0[1]*_hc6[78]*_t269*_t35*_t66 - _hc6[28]*_t1615 - _hc6[65]*_t1616 - _hc6[68]*_t784 - _t1619) + (0.34e2 / 0.9e1)*_t629 - _t633*_t709 - _t639 - _t707*((0.1e1 / 0.2e1)*_hc0[1]*_hc6[75]*_t269*_t35*_t66 - _hc6[25]*_t1615 - _hc6[61]*_t1616 - _hc6[65]*_t784 - _t1618)) + _t105*_t792 + _t114*_t783) + 0.2e1*_t793;
  const double d4F_dna2_dgbb_dtb = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_t1622 + _t1623*_t90 + _t1623*_t92 - _t23*(_hc7[104]*_t1628 - _t1625) + _t29*(_hc7[84]*_t1628 - _t1629)) + _t103*_t794 + _t79*_t799) + 0.2e1*_t800;
  const double d4F_dna_dnb_dgaa_dta = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_hc0[1]*_hc6[34]*_t2*_t269*_t66*_t85 + _hc0[1]*_t1631*_t35 + (0.1e1 / 0.2e1)*_hc0[2]*_hc6[34]*_t269*_t35*_t49*_t66 + (0.1e1 / 0.9e1)*_hc6[44]*_t269*_t6*_t66*_t7*_t80 - _t1630 - _t43*(_t1183*_t802 - _t1619) - _t633*_t729 - _t664 - _t707*(_t1176*_t802 - _t1618)) + _t162*_t783 + _t37*_t803 + _t52*_t792) + _t793 + _t804;
  const double d4F_dna_dnb_dgbb_dtb = _t3*my_piecewise3(_t19, 0, _hc4[0]*(-_t1489*_t798 + _t1623*_t432 + _t1634*_t29 + _t1635) + _t146*_t794 + _t32*_t810 + _t55*_t799) + _t800 + _t811;
  const double d4F_dnb2_dgaa_dta = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t1293*_t802 + _t1294*_t802 + _t1614 - _t1630 + _t1631*_t50) + _t174*_t803 + _t180*_t783) + 0.2e1*_t804;
  const double d4F_dnb2_dgbb_dtb = _t3*my_piecewise3(_t19, 0, _hc4[0]*((0.14e2 / 0.9e1)*_hc7[28]*_t1576 + _t1417*_t1627 + _t1418*_t1627 - _t148*((0.1e1 / 0.2e1)*_hc3[1]*_hc7[78]*_t273*_t48*_t71 - _hc7[28]*_t1632 - _hc7[65]*_t1633 - _hc7[68]*_t805 - _hc7[98]*_t1624) + _t1634*_t54 + _t1635 + _t1636*_t687*_t695 - _t673*_t744 - _t689 + (0.34e2 / 0.9e1)*_t694 - _t743*((0.1e1 / 0.2e1)*_hc3[1]*_hc7[75]*_t273*_t48*_t71 - _hc7[25]*_t1632 - _hc7[61]*_t1633 - _hc7[65]*_t805 - _hc7[95]*_t1624)) + _t182*_t810 + _t187*_t794) + 0.2e1*_t811;
  const double d4F_dna2_dta2 = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_hc6[21]*_t1637*_t701 + _t119*_t993 + _t119*_t994 + (0.28e2 / 0.9e1)*_t1613*_t815 + _t1638 - _t1639*_t706 - _t23*(_hc0[1]*_hc6[101]*_t119*_t35 - _hc6[41]*_t812 - _hc6[91]*_t1640 - _hc6[95]*_t1641 - _t1644) + _t36*(_hc0[1]*_hc6[81]*_t119*_t35 - _hc6[31]*_t812 - _hc6[71]*_t1640 - _hc6[75]*_t1641 - _t1645) - _t43*(_hc0[1]*_hc6[75]*_t119*_t35 - _hc6[25]*_t812 - _hc6[61]*_t1640 - _hc6[65]*_t1641 - _t1643) + (0.80e2 / 0.9e1)*_t700 - _t707*(_hc0[1]*_hc6[71]*_t119*_t35 - _hc6[21]*_t812 - _hc6[56]*_t1640 - _hc6[61]*_t1641 - _t1642)) + _t105*_t818 + _t114*_t277) + 0.2e1*_t819;
  const double d4F_dna2_dtb2 = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_t1646 + _t1647*_t90 + _t1647*_t92 - _t23*(_hc7[101]*_t821 - _t1648) + _t29*(_hc7[81]*_t821 - _t1649)) + _t103*_t279 + _t79*_t822) + 0.2e1*_t823;
  const double d4F_dna_dnb_dta2 = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t1178*_t119 + _t1179*_t119 - _t1639*_t728 + _t1650*_t36 + _t1651 - _t43*(_t1176*_t119 - _t1643) - _t707*(_t1175*_t119 - _t1642)) + _t162*_t277 + _t37*_t824 + _t52*_t818) + _t819 + _t825;
  const double d4F_dna_dnb_dtb2 = _t3*my_piecewise3(_t19, 0, _hc4[0]*(-_t143*_t1647 + _t1647*_t432 + _t1654*_t29 + _t1655) + _t146*_t279 + _t32*_t831 + _t55*_t822) + _t823 + _t832;
  const double d4F_dnb2_dta2 = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t119*_t1291 + _t119*_t1292 + _t1650*_t50 + _t1651) + _t174*_t824 + _t180*_t277) + 0.2e1*_t825;
  const double d4F_dnb2_dtb2 = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_hc7[21]*_t1656*_t748 + _t1411*_t194 + _t1412*_t194 - _t148*(_hc3[1]*_hc7[75]*_t194*_t48 - _hc7[25]*_t826 - _hc7[61]*_t1652 - _hc7[65]*_t1653 - _t1414*_t194) + (0.28e2 / 0.9e1)*_t1636*_t829 + _t1654*_t54 + _t1655 - 0.10e2 / 0.3e1*_t56*_t742 - _t743*(_hc3[1]*_hc7[71]*_t194*_t48 - _hc7[21]*_t826 - _hc7[56]*_t1652 - _hc7[61]*_t1653 - _t1413*_t194) + (0.80e2 / 0.9e1)*_t747) + _t182*_t831 + _t187*_t279) + 0.2e1*_t832;
  const double d4F_dna_dgaa3 = _t3*my_piecewise3(_t18, 0, _hc1[0]*((0.3e1 / 0.8e1)*_hc0[1]*_hc2[14]*_t11*_t35*_t835 + (0.1e1 / 0.8e1)*_hc0[1]*_hc2[80]*_t207*_t258*_t35 + (0.1e1 / 0.2e1)*_hc2[11]*_t115*_t833 + (0.1e1 / 0.16e2)*_hc2[46]*_t21*_t38*_t6*_t7*_t833 - 0.1e1 / 0.6e1*_hc2[70]*_t1510*_t256 + (0.5e1 / 0.8e1)*_hc6[28]*_t699*_t833*ta - 0.5e1 / 0.8e1*_hc6[9]*_t1661*ta - _t1584*_t1667 - 0.5e1 / 0.24e2*_t1613*_t1660*ta - _t1663 - _t1665 - 0.1e1 / 0.2e1*_t41*_t836) - _t1657*_t37 + _t1658*_t37 + _t1659*_t37) + _t841;
  const double d4F_dna_dgbb3 = _t3*my_piecewise3(_t19, 0, _hc4[0]*(-_hc5[36]*_t1675*_t29 + _hc5[46]*_t1664*_t56*_t842 + _hc5[80]*_t29*_t849 + _t15*_t1673*_t768 - _t1671 - _t1672) - _t1668*_t32 + _t1669*_t32 + _t1670*_t32) + _t850;
  const double d4F_dnb_dgaa3 = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_hc2[46]*_t1664*_t38*_t833 + _t11*_t1676*_t168 + _t1201*_t840 - _t1663 - _t1665 - _t1667*_t494) - _t1657*_t52 + _t1658*_t52 + _t1659*_t52) + _t841;
  const double d4F_dnb_dgbb3 = _t3*my_piecewise3(_t19, 0, _hc4[0]*((0.3e1 / 0.8e1)*_hc3[1]*_hc5[14]*_t15*_t48*_t844 + (0.1e1 / 0.8e1)*_hc3[1]*_hc5[80]*_t230*_t265*_t48 + (0.1e1 / 0.2e1)*_hc5[11]*_t196*_t842 + (0.1e1 / 0.16e2)*_hc5[46]*_t21*_t56*_t6*_t7*_t842 - 0.1e1 / 0.6e1*_hc5[70]*_t1576*_t263 + (0.5e1 / 0.8e1)*_hc7[28]*_t746*_t842*tb - 0.5e1 / 0.8e1*_hc7[9]*_t1678*tb - _t1611*_t1675 - 0.5e1 / 0.24e2*_t1636*_t1677*tb - _t1671 - _t1672 - 0.1e1 / 0.2e1*_t60*_t845) - _t1668*_t55 + _t1669*_t55 + _t1670*_t55) + _t850;
  const double d4F_dna_dgaa2_dta = _t3*my_piecewise3(_t18, 0, _hc1[0]*((0.1e1 / 0.4e1)*_hc0[1]*_hc6[78]*_t234*_t256*_t35 + (0.5e1 / 0.12e2)*_hc6[25]*_t258*_t786*ta + (0.3e1 / 0.4e1)*_hc6[9]*_t207*_t258 - 0.1e1 / 0.3e1*_t1447*_t1613 - _t1580*_t1681 - _t1587*_t1682 - _t1683 - 0.3e1 / 0.4e1*_t756) + _t1679*_t37 - _t1680*_t37) + _t855;
  const double d4F_dna_dgbb2_dtb = _t3*my_piecewise3(_t19, 0, _hc4[0]*((0.1e1 / 0.4e1)*_hc3[1]*_hc7[78]*_t248*_t263*_t28 - _hc7[34]*_t1686*_t29 - _t1687) + _t1684*_t32 - _t1685*_t32) + _t860;
  const double d4F_dnb_dgaa2_dta = _t3*my_piecewise3(_t18, 0, _hc1[0]*((0.1e1 / 0.4e1)*_hc0[1]*_hc6[78]*_t234*_t256*_t49 - _t1682*_t481 - _t1683) + _t1679*_t52 - _t1680*_t52) + _t855;
  const double d4F_dnb_dgbb2_dtb = _t3*my_piecewise3(_t19, 0, _hc4[0]*((0.1e1 / 0.4e1)*_hc3[1]*_hc7[78]*_t248*_t263*_t48 + (0.5e1 / 0.12e2)*_hc7[25]*_t265*_t807*tb + (0.3e1 / 0.4e1)*_hc7[9]*_t230*_t265 - 0.1e1 / 0.3e1*_t1509*_t1636 - _t1607*_t1688 - _t1612*_t1686 - _t1687 - 0.3e1 / 0.4e1*_t779) + _t1684*_t55 - _t1685*_t55) + _t860;
  const double d4F_dna_dgaa_dta2 = _t3*my_piecewise3(_t18, 0, _hc1[0]*((0.1e1 / 0.2e1)*_hc0[1]*_hc6[75]*_t35*_t355*_t66 - 0.2e1 / 0.3e1*_t1681 - 0.5e1 / 0.6e1*_t1690*_t66*ta - _t1691 - 0.7e1 / 0.3e1*_t634*_t786) + _t1689*_t37) + _t863;
  const double d4F_dna_dgbb_dtb2 = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_hc7[75]*_t1626*_t29*_t594 - _t1693) + _t1692*_t32) + _t866;
  const double d4F_dnb_dgaa_dta2 = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t1176*_t355*_t801 - _t1691) + _t1689*_t52) + _t863;
  const double d4F_dnb_dgbb_dtb2 = _t3*my_piecewise3(_t19, 0, _hc4[0]*((0.1e1 / 0.2e1)*_hc3[1]*_hc7[75]*_t48*_t594*_t71 - 0.2e1 / 0.3e1*_t1688 - _t1693 - 0.5e1 / 0.6e1*_t1694*_t71*tb - 0.7e1 / 0.3e1*_t687*_t807) + _t1692*_t55) + _t866;
  const double d4F_dna_dta3 = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_hc0[1]*_hc6[71]*_t35*_t627 - _hc6[56]*_t235/xc_powr(na, 23, 3) - 0.4e1 / 0.3e1*_t10*_t1690 - _t1695 - 0.5e1*_t814) + _t37*_t867) + _t868;
  const double d4F_dna_dtb3 = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_hc7[71]*_t29*_t692 - _t1696) + _t32*_t869) + _t870;
  const double d4F_dnb_dta3 = _t3*my_piecewise3(_t18, 0, _hc1[0]*(_t1175*_t627 - _t1695) + _t52*_t867) + _t868;
  const double d4F_dnb_dtb3 = _t3*my_piecewise3(_t19, 0, _hc4[0]*(_hc3[1]*_hc7[71]*_t48*_t692 - _hc7[56]*_t249/xc_powr(nb, 23, 3) - 0.4e1 / 0.3e1*_t14*_t1694 - _t1696 - 0.5e1*_t828) + _t55*_t869) + _t870;
  const double d4F_dgaa4 = _t3*my_piecewise3(_t18, 0, (0.1e1 / 0.16e2)*_hc1[0]*_hc2[70]*_t699*_t833 + (0.15e2 / 0.16e2)*_hc2[11]*_t255/(gaa * gaa * gaa) - 0.15e2 / 0.16e2*_hc2[3]*_t65/xc_powr(gaa, 7, 2) - 0.3e1 / 0.8e1*_t1661*_t838);
  const double d4F_dgbb4 = _t3*my_piecewise3(_t19, 0, (0.1e1 / 0.16e2)*_hc4[0]*_hc5[70]*_t746*_t842 + (0.15e2 / 0.16e2)*_hc5[11]*_t262/(gbb * gbb * gbb) - 0.15e2 / 0.16e2*_hc5[3]*_t70/xc_powr(gbb, 7, 2) - 0.3e1 / 0.8e1*_t1678*_t847);
  const double d4F_dgaa3_dta = _t3*my_piecewise3(_t18, 0, (0.1e1 / 0.8e1)*_hc1[0]*_t1660*_t786 - _hc6[28]*_t1666*_t851 + _hc6[9]*_t1676*_t270);
  const double d4F_dgbb3_dtb = _t3*my_piecewise3(_t19, 0, (0.1e1 / 0.8e1)*_hc4[0]*_t1677*_t807 - _hc7[28]*_t1674*_t856 + _hc7[9]*_t1673*_t274);
  const double d4F_dgaa2_dta2 = _t3*my_piecewise3(_t18, 0, (0.1e1 / 0.4e1)*_hc1[0]*_hc6[65]*_t256*_t813 - 0.1e1 / 0.4e1*_hc6[25]*_t258*_t861);
  const double d4F_dgbb2_dtb2 = _t3*my_piecewise3(_t19, 0, (0.1e1 / 0.4e1)*_hc4[0]*_hc7[65]*_t263*_t827 - 0.1e1 / 0.4e1*_hc7[25]*_t265*_t864);
  const double d4F_dgaa_dta3 = _t3*my_piecewise3(_t18, 0, _hc1[0]*_hc6[61]*_t1510*_t801);
  const double d4F_dgbb_dtb3 = _t3*my_piecewise3(_t19, 0, _hc4[0]*_hc7[61]*_t1576*_t1626);
  const double d4F_dta4 = _t3*my_piecewise3(_t18, 0, _hc1[0]*_hc6[56]*_t1613);
  const double d4F_dtb4 = _t3*my_piecewise3(_t19, 0, _hc4[0]*_hc7[56]*_t1636);
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
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 1] += d4F_dna3_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 2] += d4F_dna2_dnb_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 3] += d4F_dna2_dnb_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 4] += d4F_dna_dnb2_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 5] += d4F_dna_dnb2_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 6] += d4F_dnb3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 5] += d4F_dna2_dgbb_dtb;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 6] += d4F_dna_dnb_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 11] += d4F_dna_dnb_dgbb_dtb;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 12] += d4F_dnb2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += d4F_dnb2_dgbb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 2] += d4F_dna2_dtb2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 3] += d4F_dna_dnb_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 5] += d4F_dna_dnb_dtb2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 6] += d4F_dnb2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 11] += d4F_dna_dgbb2_dtb;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 12] += d4F_dnb_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += d4F_dnb_dgbb2_dtb;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 8] += d4F_dna_dgbb_dtb2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 9] += d4F_dnb_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += d4F_dnb_dgbb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 3] += d4F_dna_dtb3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 4] += d4F_dnb_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += d4F_dnb_dtb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 19] += d4F_dgbb3_dtb;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 17] += d4F_dgbb2_dtb2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 11] += d4F_dgbb_dtb3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 4] += d4F_dtb4;
#endif
#endif
}
#endif