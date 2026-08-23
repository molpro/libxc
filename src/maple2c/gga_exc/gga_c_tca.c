/*
  Generated from python/gga_exc/gga_c_tca.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_tca
*/

#ifndef _GGA_C_TCA_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_TCA_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_TCA_HELPER_BODIES
#include "gga_c_tca.c"
#undef _GGA_C_TCA_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_TCA_HELPER_BODIES
#include "gga_c_tca.c"
#undef _GGA_C_TCA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_TCA_HELPER_BODIES
#include "gga_c_tca.c"
#undef _GGA_C_TCA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_TCA_HELPER_BODIES
#include "gga_c_tca.c"
#undef _GGA_C_TCA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_TCA_HELPER_BODIES
#include "gga_c_tca.c"
#undef _GGA_C_TCA_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_tca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_TCA_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(phi_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_rc04_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(phi_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = (0.1e1 / rs);
  const double _t2 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t3 = 3.1770369999999999*rs + 4.8882700000000003;
  const double _t4 = 0.89788900000000005 - 0.65586800000000001*atan(_t3);
  const double _t5 = _t2*_t4;
#if _KMAX >= 1
  const double _t6 = _hc0[1]*_t4;
  const double _t7 = ((_hc0[0]) * (_hc0[0]));
  const double _t8 = _t1*_t7;
  const double _t9 = 0.3e1*_t8;
  const double _t10 = (0.1e1 / (rs * rs));
  const double _t11 = (_t3 * _t3) + 0.1e1;
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = _t12*_t2;
  const double _t14 = 2.0837169031160001*_t1;
#endif
#if _KMAX >= 2
  const double _t15 = 0.6e1*_t4;
  const double _t16 = ((_hc0[1]) * (_hc0[1]));
  const double _t17 = _hc0[0]*_t16;
  const double _t18 = _t1*_t17;
  const double _t19 = _t4*_t9;
  const double _t20 = _t10*_t7;
  const double _t21 = 0.3e1*_t20;
  const double _t22 = _hc0[1]*_t8;
  const double _t23 = 6.2511507093479999*_t12;
  const double _t24 = (0.1e1 / (rs * rs * rs));
  const double _t25 = -20.187128198737998*rs - 31.060429311980002;
  const double _t26 = (0.1e1 / (_t11 * _t11));
  const double _t27 = _t2*_t26;
  const double _t28 = _t25*_t27;
#endif
#if _KMAX >= 3
  const double _t29 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t30 = _t1*_t29;
  const double _t31 = _hc0[0]*_t1;
  const double _t32 = 0.18e2*_t31;
  const double _t33 = _t10*_t15;
  const double _t34 = _hc0[2]*_t4;
  const double _t35 = 12.502301418696*_t12;
  const double _t36 = _t23*_t8;
  const double _t37 = _t15*_t24*_t7;
  const double _t38 = _t20*_t35;
  const double _t39 = 6.2511507093479999*_t25;
  const double _t40 = (0.1e1 / (rs * rs * rs * rs));
  const double _t41 = -40.374256397475996*rs - 62.120858623960004;
  const double _t42 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t43 = _t2*_t25;
  const double _t44 = _t42*_t43;
  const double _t45 = _t41*_t44;
#endif
#if _KMAX >= 4
  const double _t46 = 0.18e2*_t6;
  const double _t47 = 37.506904256087999*_hc0[1]*_t12;
  const double _t48 = _t41*_t42;
  const double _t49 = 84.128520506160044*_t1;
#endif

  const double f = _t1*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = _t6*_t9;
  out[1] = df_dzeta;
  const double df_drs = -_t10*_t5 - _t13*_t14;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = _hc0[2]*_t19 + _t15*_t18;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = -_t21*_t6 - _t22*_t23;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = 4.1674338062320002*_t10*_t13 - _t14*_t28 + 0.2e1*_t24*_t5;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = _hc0[2]*_t32*_t6 + _hc0[3]*_t19 + _t15*_t30;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = -_hc0[2]*_t36 - _t17*_t33 - _t18*_t35 - _t21*_t34;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc0[1]*_t37 + _hc0[1]*_t38 - _t22*_t26*_t39;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = 42.064260253080022*_t1*_t2*_t26 + 6.2511507093479999*_t10*_t2*_t25*_t26 - 12.502301418696*_t13*_t24 - _t14*_t45 - 0.6e1*_t40*_t5;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = ((_hc0[2]) * (_hc0[2]))*_t32*_t4 + 0.24e2*_hc0[3]*_t31*_t6 + _hc0[4]*_t19 + 0.36e2*_t1*_t16*_t34;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = -_hc0[0]*_hc0[2]*_t10*_t46 - _hc0[2]*_t31*_t47 - _hc0[3]*_t21*_t4 - _hc0[3]*_t36 - _t29*_t33 - _t30*_t35;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = -_hc0[2]*_t26*_t39*_t8 + _hc0[2]*_t37 + _hc0[2]*_t38 + 25.004602837392*_t10*_t12*_t17 + 0.12e2*_t17*_t24*_t4 - 12.502301418696*_t18*_t25*_t26;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = 126.19278075924007*_hc0[1]*_t1*_t26*_t7 + 18.753452128044*_hc0[1]*_t10*_t25*_t26*_t7 - _t22*_t39*_t48 - _t24*_t47*_t7 - _t40*_t46*_t7;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = -168.25704101232009*_t10*_t27 + 8.3348676124640004*_t10*_t45 + 50.009205674783999*_t13*_t40 + _t2*_t48*_t49 - 25.004602837392*_t24*_t28 + _t44*_t49 + 0.24e2*_t5/xc_powi(rs, 5) - _t14*_t41*_t43*(-60.561384596213998*rs - 93.181287935940006)/(_t11 * _t11 * _t11 * _t11);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(Bs_k, _KMAX)(const xc_func_type *p, double s, double *out) {

  const double _t1 = 1.4299999999999999*pow(s, 2.2999999999999998) + 0.1e1;
#if _KMAX >= 1
  const double _t2 = (0.1e1 / (_t1 * _t1));
#endif
#if _KMAX >= 2
  const double _t3 = (0.1e1 / (_t1 * _t1 * _t1));
#endif
#if _KMAX >= 3
  const double _t4 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
#endif

  const double f = (0.1e1 / _t1);
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = -3.2889999999999997*_t2*pow(s, 1.2999999999999998);
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = -4.2756999999999987*_t2*pow(s, 0.29999999999999982) + 21.635041999999995*_t3*pow(s, 2.5999999999999996);
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = -1.2827099999999989*_t2*pow(s, -0.70000000000000018) + 84.376663799999974*_t3*pow(s, 1.5999999999999996) - 213.47295941399994*_t4*pow(s, 3.8999999999999995);
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = 0.8978969999999995*_t2*pow(s, -1.7000000000000002) + 143.44032845999993*_t3*pow(s, 0.59999999999999964) - 1665.0890834291993*_t4*pow(s, 2.8999999999999995) + 2808.4502540505832*pow(s, 5.1999999999999993)/xc_powi(_t1, 5);
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_tcs_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double *out) {

  const double _t1 = xc_powr(0.3e1, 2, 3);
  const double _t2 = (0.1e1 / 0.6e1)*_t1/(M_CBRTPI * M_CBRTPI);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Bs_k, _KMAX)(p, _t2*xt, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_rc04_k, _KMAX)(p, rs, z, _hc1);
#if _KMAX >= 1
  const double _t3 = _hc0[1]*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / 0.12e2)*M_CBRT3*_hc0[2]/(M_PI * M_CBRTPI);
#endif
#if _KMAX >= 3
  const double _t5 = (0.1e1 / 0.24e2)*_hc0[3]/(M_PI * M_PI);
#endif

  const double f = _hc0[0]*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _hc1[0]*_t3;
  out[1] = df_dxt;
  const double df_dz = _hc0[0]*_hc1[1];
  out[2] = df_dz;
  const double df_drs = _hc0[0]*_hc1[2];
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = _hc1[0]*_t4;
  out[4] = d2f_dxt2;
  const double d2f_dz_dxt = _hc1[1]*_t3;
  out[5] = d2f_dz_dxt;
  const double d2f_dz2 = _hc0[0]*_hc1[3];
  out[6] = d2f_dz2;
  const double d2f_drs_dxt = _hc1[2]*_t3;
  out[7] = d2f_drs_dxt;
  const double d2f_drs_dz = _hc0[0]*_hc1[4];
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[0]*_hc1[5];
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = _hc1[0]*_t5;
  out[10] = d3f_dxt3;
  const double d3f_dz_dxt2 = _hc1[1]*_t4;
  out[11] = d3f_dz_dxt2;
  const double d3f_dz2_dxt = _hc1[3]*_t3;
  out[12] = d3f_dz2_dxt;
  const double d3f_dz3 = _hc0[0]*_hc1[6];
  out[13] = d3f_dz3;
  const double d3f_drs_dxt2 = _hc1[2]*_t4;
  out[14] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxt = _hc1[4]*_t3;
  out[15] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = _hc0[0]*_hc1[7];
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dxt = _hc1[5]*_t3;
  out[17] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _hc0[0]*_hc1[8];
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[0]*_hc1[9];
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = (0.1e1 / 0.144e3)*_hc0[4]*_hc1[0]*_t1/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  out[20] = d4f_dxt4;
  const double d4f_dz_dxt3 = _hc1[1]*_t5;
  out[21] = d4f_dz_dxt3;
  const double d4f_dz2_dxt2 = _hc1[3]*_t4;
  out[22] = d4f_dz2_dxt2;
  const double d4f_dz3_dxt = _hc1[6]*_t3;
  out[23] = d4f_dz3_dxt;
  const double d4f_dz4 = _hc0[0]*_hc1[10];
  out[24] = d4f_dz4;
  const double d4f_drs_dxt3 = _hc1[2]*_t5;
  out[25] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxt2 = _hc1[4]*_t4;
  out[26] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxt = _hc1[7]*_t3;
  out[27] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = _hc0[0]*_hc1[11];
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dxt2 = _hc1[5]*_t4;
  out[29] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxt = _hc1[8]*_t3;
  out[30] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = _hc0[0]*_hc1[12];
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dxt = _hc1[9]*_t3;
  out[32] = d4f_drs3_dxt;
  const double d4f_drs3_dz = _hc0[0]*_hc1[13];
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[0]*_hc1[14];
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_rc04_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (0.1e1 / rs);
  const double _t2 = 3.1770369999999999*rs + 4.8882700000000003;
  const double _t3 = 0.89788900000000005 - 0.65586800000000001*atan(_t2);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (rs * rs));
  const double _t5 = (_t2 * _t2) + 0.1e1;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = 2.0837169031160001*_t1;
#endif
#if _KMAX >= 2
  const double _t8 = (0.1e1 / (rs * rs * rs));
  const double _t9 = (0.1e1 / (_t5 * _t5));
  const double _t10 = -20.187128198737998*rs - 31.060429311980002;
  const double _t11 = _t10*_t9;
#endif
#if _KMAX >= 3
  const double _t12 = (0.1e1 / (rs * rs * rs * rs));
  const double _t13 = -40.374256397475996*rs - 62.120858623960004;
  const double _t14 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t15 = _t10*_t14;
  const double _t16 = _t13*_t15;
#endif
#if _KMAX >= 4
  const double _t17 = 84.128520506160044*_t1;
#endif

  const double f = _t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t3*_t4 - _t6*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -_t11*_t7 + 0.2e1*_t3*_t8 + 4.1674338062320002*_t4*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 42.064260253080022*_t1*_t9 + 6.2511507093479999*_t10*_t4*_t9 - 0.6e1*_t12*_t3 - _t16*_t7 - 12.502301418696*_t6*_t8;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -_t10*_t13*_t7*(-60.561384596213998*rs - 93.181287935940006)/(_t5 * _t5 * _t5 * _t5) - 25.004602837392*_t11*_t8 + 50.009205674783999*_t12*_t6 + _t13*_t14*_t17 + _t15*_t17 + 8.3348676124640004*_t16*_t4 + 0.24e2*_t3/xc_powi(rs, 5) - 168.25704101232009*_t4*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_tcs_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {

  const double _t1 = xc_powr(0.3e1, 2, 3);
  const double _t2 = (0.1e1 / 0.6e1)*_t1/(M_CBRTPI * M_CBRTPI);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Bs_k, _KMAX)(p, _t2*xt, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_rc04_zeta0_k, _KMAX)(p, rs, _hc1);
#if _KMAX >= 1
  const double _t3 = _hc0[1]*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / 0.12e2)*M_CBRT3*_hc0[2]/(M_PI * M_CBRTPI);
#endif
#if _KMAX >= 3
  const double _t5 = (0.1e1 / 0.24e2)*_hc0[3]/(M_PI * M_PI);
#endif

  const double f = _hc0[0]*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _hc1[0]*_t3;
  out[1] = df_dxt;
  const double df_drs = _hc0[0]*_hc1[1];
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = _hc1[0]*_t4;
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = _hc1[1]*_t3;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = _hc0[0]*_hc1[2];
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = _hc1[0]*_t5;
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = _hc1[1]*_t4;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = _hc1[2]*_t3;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = _hc0[0]*_hc1[3];
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = (0.1e1 / 0.144e3)*_hc0[4]*_hc1[0]*_t1/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = _hc1[1]*_t5;
  out[11] = d4f_drs_dxt3;
  const double d4f_drs2_dxt2 = _hc1[2]*_t4;
  out[12] = d4f_drs2_dxt2;
  const double d4f_drs3_dxt = _hc1[3]*_t3;
  out[13] = d4f_drs3_dxt;
  const double d4f_drs4 = _hc0[0]*_hc1[4];
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

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = (0.1e1 / 0.2e1)*_t1;
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = xc_powr(gaa, 1, 2);
  const double _t7 = xc_powr(na, -4, 3);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_tcs_z0_k, _KMAX)(p, _t2*_t5, _t6*_t7, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t8 = xc_powr(na, -7, 3);
  const double _t9 = _t6*_t8;
  const double _t10 = (0.4e1 / 0.3e1)*_t9;
  const double _t12 = (0.1e1 / 0.6e1)*_t7;
  const double _t13 = (0.1e1 / _t6);
  const double _t11 = _hc0[2]*_t5;
  const double _t14 = _hc0[1]*_t13;
  const double dF_dna = _hc0[0] + na*(-_hc0[1]*_t10 - _t11*_t12);
  const double dF_dgaa = _t14*_t2;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t16 = xc_powr(na, -10, 3);
  const double _t17 = (0.28e2 / 0.9e1)*_t16;
  const double _t18 = (0.2e1 / 0.9e1)*_t8;
  const double _t20 = _t12*_t5;
  const double _t23 = (0.1e1 / 0.2e1)*_t7;
  const double _t24 = xc_powr(na, -11, 3);
  const double _t25 = (0.2e1 / 0.3e1)*_t24;
  const double _t27 = (0.2e1 / 0.3e1)*_t8;
  const double _t28 = _t13*_t5;
  const double _t30 = xc_powr(na, -8, 3);
  const double _t31 = (0.1e1 / 0.12e2)*_t30;
  const double _t32 = xc_powr(gaa, -3, 2);
  const double _t35 = (0.1e1 / gaa);
  const double _t36 = xc_powr(na, -5, 3);
  const double _t15 = _hc0[1]*_t6;
  const double _t19 = (0.4e1 / 0.3e1)*_hc0[3];
  const double _t21 = -_hc0[4]*_t20 - _t19*_t9;
  const double _t22 = -_hc0[4]*_t10 - _hc0[5]*_t20;
  const double _t26 = _hc0[3]*_t25;
  const double _t29 = _hc0[4]*_t28;
  const double _t33 = _hc0[1]*_t32;
  const double _t34 = (0.1e1 / 0.4e1)*_t33;
  const double d2F_dna2 = -0.8e1 / 0.3e1*_hc0[1]*_t9 - 0.1e1 / 0.3e1*_t11*_t7 + na*(-_t10*_t21 + _t11*_t18 + _t15*_t17 - _t20*_t22);
  const double d2F_dna_dgaa = _t14*_t23 + na*(-_t14*_t27 - _t26 - _t29*_t31);
  const double d2F_dgaa2 = (0.1e1 / 0.4e1)*_hc0[3]*_t35*_t36 - _t1*_t34;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t37 = (0.28e2 / 0.3e1)*_t16;
  const double _t38 = 0.4e1*_t9;
  const double _t40 = xc_powr(na, -13, 3);
  const double _t41 = (0.280e3 / 0.27e2)*_t40;
  const double _t42 = (0.14e2 / 0.27e2)*_t16;
  const double _t43 = _t17*_t6;
  const double _t44 = _t18*_t5;
  const double _t50 = (0.4e1 / 0.3e1)*_t8;
  const double _t51 = xc_powr(na, -14, 3);
  const double _t52 = (0.14e2 / 0.9e1)*_t51;
  const double _t53 = (0.14e2 / 0.9e1)*_t16;
  const double _t54 = (0.1e1 / 0.9e1)*_t24;
  const double _t55 = _t13*_t27;
  const double _t56 = _t28*_t31;
  const double _t60 = (0.1e1 / 0.3e1)*_t24;
  const double _t62 = xc_powi(na, -5);
  const double _t63 = (0.1e1 / 0.3e1)*_t62;
  const double _t64 = (0.1e1 / 0.24e2)*_t5;
  const double _t65 = (0.1e1 / (na * na * na * na));
  const double _t66 = _t35*_t65;
  const double _t67 = xc_powr(gaa, -5, 2);
  const double _t70 = (0.1e1 / (gaa * gaa));
  const double _t73 = (0.1e1 / 0.8e1)*_t32;
  const double _t39 = _t22*_t5;
  const double _t45 = -_hc0[6]*_t10 - _hc0[7]*_t20;
  const double _t46 = -_hc0[7]*_t10 - _hc0[8]*_t20;
  const double _t47 = _hc0[3]*_t43 + _hc0[4]*_t44 - _t10*_t45 - _t20*_t46;
  const double _t48 = -_hc0[8]*_t10 - _hc0[9]*_t20;
  const double _t49 = _hc0[4]*_t43 + _hc0[5]*_t44 - _t10*_t46 - _t20*_t48;
  const double _t57 = -_hc0[3]*_t55 - _hc0[6]*_t25 - _hc0[7]*_t56;
  const double _t58 = -_hc0[4]*_t55 - _hc0[7]*_t25 - _hc0[8]*_t56;
  const double _t59 = _hc0[3]*_t35;
  const double _t61 = _hc0[6]*_t13;
  const double _t68 = _hc0[1]*_t67;
  const double _t69 = (0.3e1 / 0.8e1)*_t68;
  const double _t71 = (0.3e1 / 0.8e1)*_hc0[3]*_t70;
  const double _t72 = _hc0[6]/(na * na * na);
  const double d3F_dna3 = _t11*_t27 + _t15*_t37 - _t21*_t38 - _t23*_t39 + na*(-_t10*_t47 - _t11*_t42 - _t15*_t41 + (0.56e2 / 0.9e1)*_t16*_t21*_t6 - _t20*_t49 + (0.4e1 / 0.9e1)*_t22*_t3*_t4*_t8);
  const double d3F_dna2_dgaa = -_t14*_t50 - _t19*_t24 - 0.1e1 / 0.6e1*_t29*_t30 + na*(_hc0[3]*_t52 - _t10*_t57 + _t14*_t53 - _t20*_t58 - _t21*_t55 + _t29*_t54);
  const double d3F_dna_dgaa2 = (0.1e1 / 0.4e1)*_t30*_t59 - _t34*_t7 + na*((0.1e1 / 0.3e1)*_hc0[1]*_t32*_t8 + (0.1e1 / 0.24e2)*_hc0[4]*_t3*_t30*_t32*_t4 - _hc0[7]*_t64*_t66 - _t59*_t60 - _t61*_t63);
  const double d3F_dgaa3 = _t1*_t69 - _t36*_t71 + _t72*_t73;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t75 = xc_powr(na, -16, 3);
  const double _t76 = _t41*_t6;
  const double _t77 = _t42*_t5;
  const double _t81 = _t13*_t53;
  const double _t82 = _t28*_t54;
  const double _t85 = _t13*_t63;
  const double _t86 = _t35*_t60;
  const double _t87 = _t64*_t66;
  const double _t74 = _t49*_t5;
  const double _t78 = -_hc0[11]*_t10 - _hc0[12]*_t20;
  const double _t79 = -_hc0[12]*_t10 - _hc0[13]*_t20;
  const double _t80 = _hc0[7]*_t43 + _hc0[8]*_t44 - _t10*_t78 - _t20*_t79;
  const double _t83 = -_hc0[11]*_t25 - _hc0[12]*_t56 - _hc0[7]*_t55;
  const double _t84 = _hc0[4]*_t32;
  const double d4F_dna4 = -0.56e2 / 0.27e2*_t11*_t16 - 0.1120e4 / 0.27e2*_t15*_t40 + (0.224e3 / 0.9e1)*_t16*_t21*_t6 + (0.16e2 / 0.9e1)*_t22*_t3*_t4*_t8 - 0.16e2 / 0.3e1*_t47*_t9 - 0.2e1 / 0.3e1*_t7*_t74 + na*(-_t10*(-_hc0[3]*_t76 - _hc0[4]*_t77 - _t10*(_hc0[6]*_t43 + _hc0[7]*_t44 - _t10*(-_hc0[10]*_t10 - _hc0[11]*_t20) - _t20*_t78) + (0.56e2 / 0.9e1)*_t16*_t45*_t6 - _t20*_t80 + (0.4e1 / 0.9e1)*_t3*_t4*_t46*_t8) + (0.140e3 / 0.81e2)*_t11*_t40 + (0.3640e4 / 0.81e2)*_t15*_t75 - _t20*(-_hc0[4]*_t76 - _hc0[5]*_t77 - _t10*_t80 + (0.56e2 / 0.9e1)*_t16*_t46*_t6 - _t20*(_hc0[8]*_t43 + _hc0[9]*_t44 - _t10*_t79 - _t20*(-_hc0[13]*_t10 - _hc0[14]*_t20)) + (0.4e1 / 0.9e1)*_t3*_t4*_t48*_t8) - 0.280e3 / 0.9e1*_t21*_t40*_t6 + _t27*_t74 + _t37*_t47*_t6 - _t39*_t53);
  const double d4F_dna3_dgaa = (0.14e2 / 0.3e1)*_hc0[3]*_t51 - 0.2e1*_t13*_t21*_t8 + (0.14e2 / 0.3e1)*_t14*_t16 - _t23*_t5*_t58 + _t29*_t60 - _t38*_t57 + na*(-0.140e3 / 0.27e2*_hc0[3]/xc_powr(na, 17, 3) - _t10*(_hc0[3]*_t81 + _hc0[6]*_t52 + _hc0[7]*_t82 - _t10*(-_hc0[10]*_t25 - _hc0[11]*_t56 - _hc0[6]*_t55) - _t20*_t83 - _t45*_t55) + (0.28e2 / 0.9e1)*_t13*_t16*_t21 - 0.140e3 / 0.27e2*_t14*_t40 + (0.56e2 / 0.9e1)*_t16*_t57*_t6 - _t20*(_hc0[4]*_t81 + _hc0[7]*_t52 + _hc0[8]*_t82 - _t10*_t83 - _t20*(-_hc0[12]*_t25 - _hc0[13]*_t56 - _hc0[8]*_t55) - _t46*_t55) - 0.7e1 / 0.27e2*_t29*_t51 + (0.4e1 / 0.9e1)*_t3*_t4*_t58*_t8 - _t47*_t55);
  const double d4F_dna2_dgaa2 = -0.1e1 / 0.12e2*_hc0[7]*_t5*_t66 - _t26*_t35 + _t27*_t33 + _t31*_t5*_t84 - 0.2e1 / 0.3e1*_t61*_t62 + na*((0.7e1 / 0.9e1)*_hc0[3]*_t35*_t51 + (0.7e1 / 0.9e1)*_hc0[6]*_t13/xc_powi(na, 6) + (0.1e1 / 0.18e2)*_hc0[7]*_t3*_t35*_t4*_t62 - _t10*(-_hc0[10]*_t85 - _hc0[11]*_t87 + (0.1e1 / 0.3e1)*_hc0[3]*_t32*_t8 - _hc0[6]*_t86 + (0.1e1 / 0.24e2)*_hc0[7]*_t3*_t30*_t32*_t4) - _t13*_t50*_t57 - 0.7e1 / 0.9e1*_t16*_t33 - _t20*(-_hc0[11]*_t85 - _hc0[12]*_t87 + (0.1e1 / 0.3e1)*_hc0[4]*_t32*_t8 - _hc0[7]*_t86 + (0.1e1 / 0.24e2)*_hc0[8]*_t3*_t30*_t32*_t4) + (0.1e1 / 0.3e1)*_t21*_t32*_t8 - 0.1e1 / 0.18e2*_t24*_t5*_t84);
  const double d4F_dna_dgaa3 = _hc0[6]*_t65*_t73 - _t30*_t71 + _t69*_t7 + na*(-0.1e1 / 0.6e1*_hc0[10]*_t35/xc_powr(na, 19, 3) - 0.1e1 / 0.48e2*_hc0[11]*_t32*_t5*_t75 + (0.1e1 / 0.2e1)*_hc0[3]*_t24*_t70 - 0.1e1 / 0.16e2*_hc0[4]*_t30*_t5*_t67 + (0.1e1 / 0.16e2)*_hc0[7]*_t3*_t4*_t65*_t70 - 0.1e1 / 0.2e1*_t68*_t8);
  const double d4F_dgaa4 = -0.15e2 / 0.16e2*_hc0[1]*_t1/xc_powr(gaa, 7, 2) + (0.1e1 / 0.16e2)*_hc0[10]*_t40*_t70 + (0.15e2 / 0.16e2)*_hc0[3]*_t36/(gaa * gaa * gaa) - 0.3e1 / 0.8e1*_t67*_t72;
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
  const double _t2 = xc_powr(_t1, -1, 3);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = na - nb;
  const double _t8 = (0.1e1 / _t1);
  const double _t9 = xc_powr(_t1, -4, 3);
  const double _t10 = gaa + 0.2e1*gab + gbb;
  const double _t11 = xc_powr(_t10, 1, 2);
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f_tcs_k, _KMAX)(p, _t2*_t6, _t7*_t8, _t11*_t9, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = (0.1e1 / (_t1 * _t1));
  const double _t13 = _t12*_t7;
  const double _t14 = -_t13 + _t8;
  const double _t15 = xc_powr(_t1, -7, 3);
  const double _t17 = (0.4e1 / 0.3e1)*_t11;
  const double _t19 = (0.1e1 / 0.6e1)*_t9;
  const double _t21 = -_t13 - _t8;
  const double _t22 = (0.1e1 / _t11);
  const double _t16 = _hc0[1]*_t15;
  const double _t18 = _hc0[3]*_t5;
  const double _t20 = _t16*_t17 + _t18*_t19;
  const double _t23 = _hc0[1]*_t22;
  const double _t24 = _t2*_t23;
  const double _t25 = (0.1e1 / 0.2e1)*_t24;
  const double dF_dna = _hc0[0] + _t1*(_hc0[2]*_t14 - _t20);
  const double dF_dnb = _hc0[0] + _t1*(_hc0[2]*_t21 - _t20);
  const double dF_dgaa = _t25;
  const double dF_dgab = _t24;
  const double dF_dgbb = _t25;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t27 = xc_powr(_t1, -10, 3);
  const double _t28 = (0.28e2 / 0.9e1)*_t27;
  const double _t29 = (0.2e1 / 0.9e1)*_t15;
  const double _t31 = 0.2e1*_t12;
  const double _t32 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t33 = 0.2e1*_t32;
  const double _t34 = _t33*_t7;
  const double _t35 = -_t31 + _t34;
  const double _t37 = _t15*_t17;
  const double _t38 = _t19*_t5;
  const double _t47 = (0.8e1 / 0.3e1)*_t11;
  const double _t49 = (0.1e1 / 0.3e1)*_t9;
  const double _t57 = _t31 + _t34;
  const double _t64 = xc_powr(_t1, -11, 3);
  const double _t68 = (0.1e1 / 0.12e2)*_t5;
  const double _t69 = xc_powr(_t1, -8, 3);
  const double _t76 = (0.1e1 / 0.6e1)*_t5;
  const double _t83 = xc_powr(_t10, -3, 2);
  const double _t86 = xc_powr(_t1, -5, 3);
  const double _t87 = (0.1e1 / _t10);
  const double _t26 = _hc0[1]*_t11;
  const double _t30 = _t18*_t29 + _t26*_t28;
  const double _t36 = _hc0[2]*_t35;
  const double _t39 = _hc0[5]*_t37 + _hc0[8]*_t38;
  const double _t40 = _hc0[6]*_t14 - _t39;
  const double _t41 = _t14*_t40;
  const double _t42 = _hc0[4]*_t37 + _hc0[7]*_t38;
  const double _t43 = _hc0[5]*_t14 - _t42;
  const double _t44 = _hc0[7]*_t37 + _hc0[9]*_t38;
  const double _t45 = _hc0[8]*_t14 - _t44;
  const double _t46 = _t36 - _t37*_t43 - _t38*_t45 + _t41;
  const double _t48 = _t16*_t47;
  const double _t50 = _t18*_t49;
  const double _t51 = _t48 + _t50;
  const double _t52 = _hc0[6]*_t21 - _t39;
  const double _t53 = _t14*_t52;
  const double _t54 = _hc0[5]*_t21 - _t42;
  const double _t55 = _hc0[8]*_t21 - _t44;
  const double _t56 = _t30 - _t37*_t54 - _t38*_t55;
  const double _t58 = _hc0[2]*_t57;
  const double _t59 = _t21*_t52;
  const double _t60 = _t58 + _t59;
  const double _t61 = _t23*_t9;
  const double _t62 = (0.1e1 / 0.2e1)*_t61;
  const double _t63 = -0.1e1 / 0.2e1*_hc0[5]*_t14*_t22*_t9;
  const double _t65 = _hc0[4]*_t64;
  const double _t66 = (0.2e1 / 0.3e1)*_t65;
  const double _t67 = _t15*_t23;
  const double _t70 = _hc0[7]*_t69;
  const double _t71 = _t22*_t70;
  const double _t72 = _t66 + (0.2e1 / 0.3e1)*_t67 + _t68*_t71;
  const double _t73 = _t1*(-_t63 - _t72) + _t62;
  const double _t74 = -_hc0[5]*_t14*_t22*_t9;
  const double _t75 = (0.4e1 / 0.3e1)*_t65;
  const double _t77 = (0.4e1 / 0.3e1)*_t67 + _t71*_t76 + _t75;
  const double _t78 = _t74 + _t77;
  const double _t79 = -0.1e1 / 0.2e1*_hc0[5]*_t21*_t22*_t9;
  const double _t80 = _t1*(-_t72 - _t79) + _t62;
  const double _t81 = -_hc0[5]*_t21*_t22*_t9;
  const double _t82 = _t77 + _t81;
  const double _t84 = _hc0[1]*_t83;
  const double _t85 = _t2*_t84;
  const double _t88 = (0.1e1 / 0.4e1)*_hc0[4]*_t86*_t87 - 0.1e1 / 0.4e1*_t85;
  const double _t89 = (0.1e1 / 0.2e1)*_hc0[4]*_t86*_t87 - 0.1e1 / 0.2e1*_t85;
  const double d2F_dna2 = 0.2e1*_hc0[2]*_t14 + _t1*(_t30 + _t46) - _t51;
  const double d2F_dna_dnb = _hc0[2]*_t14 + _hc0[2]*_t21 + _t1*(_hc0[2]*_t34 + _t53 + _t56) - _t48 - _t50;
  const double d2F_dnb2 = 0.2e1*_hc0[2]*_t21 + _t1*(_t56 + _t60) - _t51;
  const double d2F_dna_dgaa = _t73;
  const double d2F_dna_dgab = -_t1*_t78 + _t61;
  const double d2F_dna_dgbb = _t73;
  const double d2F_dnb_dgaa = _t80;
  const double d2F_dnb_dgab = -_t1*_t82 + _t61;
  const double d2F_dnb_dgbb = _t80;
  const double d2F_dgaa2 = _t88;
  const double d2F_dgaa_dgab = _t89;
  const double d2F_dgaa_dgbb = _t88;
  const double d2F_dgab2 = _hc0[4]*_t86*_t87 - _t85;
  const double d2F_dgab_dgbb = _t89;
  const double d2F_dgbb2 = _t88;
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
  const double _t90 = xc_powr(_t1, -13, 3);
  const double _t91 = (0.280e3 / 0.27e2)*_t90;
  const double _t93 = (0.14e2 / 0.27e2)*_t27;
  const double _t97 = (0.56e2 / 0.9e1)*_t27;
  const double _t99 = (0.4e1 / 0.9e1)*_t15;
  const double _t101 = 0.6e1*_t32;
  const double _t102 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t103 = _t102*_t7;
  const double _t104 = 0.6e1*_t103;
  const double _t105 = _t101 - _t104;
  const double _t113 = _t11*_t28;
  const double _t114 = _t29*_t5;
  const double _t118 = 0.2e1*_t35;
  const double _t131 = 0.4e1*_t15;
  const double _t132 = _t6*_t9;
  const double _t133 = (0.28e2 / 0.3e1)*_t27;
  const double _t134 = (0.2e1 / 0.3e1)*_t15;
  const double _t136 = -_t104 + 0.2e1*_t32;
  const double _t154 = 0.4e1*_t32;
  const double _t165 = -_t101 - _t104;
  const double _t170 = xc_powr(_t1, -14, 3);
  const double _t172 = (0.14e2 / 0.9e1)*_t27;
  const double _t173 = (0.1e1 / 0.9e1)*_t5;
  const double _t177 = (0.2e1 / 0.3e1)*_t64;
  const double _t180 = _t22*_t69;
  const double _t181 = _t180*_t68;
  const double _t186 = _t134*_t22;
  const double _t189 = _t22*_t9;
  const double _t198 = (0.4e1 / 0.3e1)*_t64;
  const double _t200 = (0.4e1 / 0.3e1)*_t15;
  const double _t201 = _t180*_t76;
  const double _t206 = _t200*_t22;
  const double _t214 = (0.1e1 / 0.3e1)*_t5;
  const double _t239 = _t83*_t9;
  const double _t243 = xc_powi(_t1, -5);
  const double _t244 = _t22*_t243;
  const double _t245 = (0.1e1 / 0.3e1)*_t87;
  const double _t246 = (0.1e1 / 0.24e2)*_t5;
  const double _t247 = _t102*_t87;
  const double _t265 = (0.1e1 / 0.6e1)*_t87;
  const double _t266 = _t102*_t265;
  const double _t275 = xc_powr(_t10, -5, 2);
  const double _t280 = (0.1e1 / (_t10 * _t10));
  const double _t92 = _t26*_t91;
  const double _t94 = _t18*_t93;
  const double _t95 = -_t92 - _t94;
  const double _t96 = _t11*_t43;
  const double _t98 = _t45*_t5;
  const double _t100 = _t96*_t97 + _t98*_t99;
  const double _t106 = _hc0[2]*_t105;
  const double _t107 = _hc0[12]*_t37 + _hc0[16]*_t38;
  const double _t108 = _hc0[13]*_t14 - _t107;
  const double _t109 = _hc0[11]*_t37 + _hc0[15]*_t38;
  const double _t110 = _hc0[12]*_t14 - _t109;
  const double _t111 = _hc0[15]*_t37 + _hc0[18]*_t38;
  const double _t112 = _hc0[16]*_t14 - _t111;
  const double _t115 = _hc0[5]*_t113 + _hc0[8]*_t114;
  const double _t116 = _hc0[6]*_t35 + _t108*_t14 - _t110*_t37 - _t112*_t38 + _t115;
  const double _t117 = _t116*_t14;
  const double _t119 = _hc0[5]*_t35;
  const double _t120 = _hc0[10]*_t37 + _hc0[14]*_t38;
  const double _t121 = _hc0[11]*_t14 - _t120;
  const double _t122 = _hc0[14]*_t37 + _hc0[17]*_t38;
  const double _t123 = _hc0[15]*_t14 - _t122;
  const double _t124 = _hc0[4]*_t113 + _hc0[7]*_t114;
  const double _t125 = _t110*_t14 + _t119 - _t121*_t37 - _t123*_t38 + _t124;
  const double _t126 = _hc0[17]*_t37 + _hc0[19]*_t38;
  const double _t127 = _hc0[18]*_t14 - _t126;
  const double _t128 = _hc0[7]*_t113 + _hc0[9]*_t114;
  const double _t129 = _hc0[8]*_t35 + _t112*_t14 - _t123*_t37 - _t127*_t38 + _t128;
  const double _t130 = _t106 + _t117 + _t118*_t40 - _t125*_t37 - _t129*_t38;
  const double _t135 = _t133*_t26 + _t134*_t18;
  const double _t137 = _hc0[2]*_t136;
  const double _t138 = _hc0[13]*_t21 - _t107;
  const double _t139 = _hc0[12]*_t21 - _t109;
  const double _t140 = _hc0[16]*_t21 - _t111;
  const double _t141 = _t115 - _t139*_t37 - _t140*_t38;
  const double _t142 = _hc0[6]*_t34 + _t138*_t14 + _t141;
  const double _t143 = _t14*_t142;
  const double _t144 = _t35*_t52;
  const double _t145 = _hc0[11]*_t21 - _t120;
  const double _t146 = _hc0[15]*_t21 - _t122;
  const double _t147 = _t124 - _t145*_t37 - _t146*_t38;
  const double _t148 = _hc0[5]*_t34 + _t139*_t14 + _t147;
  const double _t149 = _hc0[18]*_t21 - _t126;
  const double _t150 = _t128 - _t146*_t37 - _t149*_t38;
  const double _t151 = _hc0[8]*_t34 + _t14*_t140 + _t150;
  const double _t152 = _t15*_t54;
  const double _t153 = _t5*_t55;
  const double _t155 = _hc0[2]*_t154;
  const double _t156 = _t155*_t7 + 0.2e1*_t53;
  const double _t157 = _hc0[8]*_t57 + _t140*_t21 + _t150;
  const double _t158 = _t157*_t38;
  const double _t159 = _hc0[5]*_t57;
  const double _t160 = _t139*_t21 + _t147 + _t159;
  const double _t161 = _t160*_t37;
  const double _t162 = _hc0[6]*_t57 + _t138*_t21 + _t141;
  const double _t163 = _t11*_t54;
  const double _t164 = -_t131*_t163 - _t132*_t55 + _t135;
  const double _t166 = _hc0[2]*_t165;
  const double _t167 = _t162*_t21;
  const double _t168 = 0.2e1*_t52;
  const double _t169 = _t166 + _t167 + _t168*_t57;
  const double _t171 = _hc0[4]*_t170;
  const double _t174 = _hc0[7]*_t22;
  const double _t175 = _t174*_t64;
  const double _t176 = (0.14e2 / 0.9e1)*_t171 + _t172*_t23 + _t173*_t175;
  const double _t178 = _hc0[11]*_t177;
  const double _t179 = _hc0[5]*_t22;
  const double _t182 = _hc0[15]*_t181 + _t134*_t179 + _t178;
  const double _t183 = (0.1e1 / 0.2e1)*_hc0[12]*_t14*_t22*_t9 - _t182;
  const double _t184 = _t14*_t183;
  const double _t185 = _hc0[10]*_t177;
  const double _t187 = _hc0[14]*_t181 + _hc0[4]*_t186 + _t185;
  const double _t188 = (0.1e1 / 0.2e1)*_hc0[11]*_t14*_t22*_t9 - _t187;
  const double _t190 = _t119*_t189;
  const double _t191 = _hc0[14]*_t177;
  const double _t192 = _hc0[17]*_t181 + _hc0[7]*_t186 + _t191;
  const double _t193 = (0.1e1 / 0.2e1)*_hc0[15]*_t14*_t22*_t9 - _t192;
  const double _t194 = _t184 - _t186*_t43 - _t188*_t37 + (0.1e1 / 0.2e1)*_t190 - _t193*_t38;
  const double _t195 = _t1*(_t176 + _t194) - _t78;
  const double _t196 = _t175*_t5;
  const double _t197 = (0.28e2 / 0.9e1)*_t171 + (0.2e1 / 0.9e1)*_t196 + _t23*_t28;
  const double _t199 = _hc0[11]*_t198;
  const double _t202 = _hc0[15]*_t201 + _t179*_t200 + _t199;
  const double _t203 = _hc0[12]*_t14*_t22*_t9 - _t202;
  const double _t204 = _t14*_t203;
  const double _t205 = _hc0[10]*_t198;
  const double _t207 = _hc0[14]*_t201 + _hc0[4]*_t206 + _t205;
  const double _t208 = _hc0[11]*_t14*_t22*_t9 - _t207;
  const double _t209 = _hc0[14]*_t198;
  const double _t210 = _hc0[17]*_t201 + _hc0[7]*_t206 + _t209;
  const double _t211 = _hc0[15]*_t14*_t22*_t9 - _t210;
  const double _t212 = _t190 + _t204 - _t206*_t43 - _t208*_t37 - _t211*_t38;
  const double _t213 = (0.8e1 / 0.3e1)*_t65;
  const double _t215 = _t213 + _t214*_t71 + (0.8e1 / 0.3e1)*_t67;
  const double _t216 = (0.1e1 / 0.2e1)*_hc0[12]*_t21*_t22*_t9 - _t182;
  const double _t217 = _t14*_t216;
  const double _t218 = _t179*_t90;
  const double _t219 = _t218*_t7;
  const double _t220 = (0.1e1 / 0.2e1)*_hc0[11]*_t21*_t22*_t9 - _t187;
  const double _t221 = _t152*_t22;
  const double _t222 = (0.1e1 / 0.2e1)*_hc0[15]*_t21*_t22*_t9 - _t192;
  const double _t223 = _t176 - _t220*_t37 - 0.2e1 / 0.3e1*_t221 - _t222*_t38;
  const double _t224 = _t1*(_t217 + _t219 + _t223) - _t63 - _t77 - _t79;
  const double _t225 = _hc0[12]*_t21*_t22*_t9 - _t202;
  const double _t226 = _t14*_t225;
  const double _t227 = -0.4e1 / 0.3e1*_t221;
  const double _t228 = 0.2e1*_t219;
  const double _t229 = _t227 + _t228;
  const double _t230 = _hc0[11]*_t21*_t22*_t9 - _t207;
  const double _t231 = _hc0[15]*_t21*_t22*_t9 - _t210;
  const double _t232 = _t197 - _t230*_t37 - _t231*_t38;
  const double _t233 = _t21*_t216;
  const double _t234 = _t159*_t189;
  const double _t235 = _t233 + (0.1e1 / 0.2e1)*_t234;
  const double _t236 = _t1*(_t223 + _t235) - _t82;
  const double _t237 = _t21*_t225;
  const double _t238 = _t234 + _t237;
  const double _t240 = _hc0[5]*_t14*_t239;
  const double _t241 = (0.1e1 / 0.4e1)*_t240;
  const double _t242 = (0.1e1 / 0.3e1)*_hc0[10];
  const double _t248 = _hc0[14]*_t247;
  const double _t249 = -0.1e1 / 0.3e1*_hc0[1]*_t15*_t83 - 0.1e1 / 0.24e2*_hc0[7]*_t3*_t4*_t69*_t83 + _t242*_t244 + _t245*_t65 + _t246*_t248;
  const double _t250 = _t84*_t9;
  const double _t251 = _hc0[4]*_t69*_t87;
  const double _t252 = -0.1e1 / 0.4e1*_t250 + (0.1e1 / 0.4e1)*_t251;
  const double _t253 = _t1*((0.1e1 / 0.4e1)*_hc0[11]*_t14*_t69*_t87 - _t241 - _t249) + _t252;
  const double _t254 = (0.1e1 / 0.2e1)*_t240;
  const double _t255 = _hc0[10]*_t244;
  const double _t256 = (0.2e1 / 0.3e1)*_t255;
  const double _t257 = _t66*_t87;
  const double _t258 = _t248*_t68;
  const double _t259 = -0.2e1 / 0.3e1*_hc0[1]*_t15*_t83 - 0.1e1 / 0.12e2*_hc0[7]*_t3*_t4*_t69*_t83 + _t256 + _t257 + _t258;
  const double _t260 = -0.1e1 / 0.2e1*_t250 + (0.1e1 / 0.2e1)*_t251;
  const double _t261 = _t1*((0.1e1 / 0.2e1)*_hc0[11]*_t14*_t69*_t87 - _t254 - _t259) + _t260;
  const double _t262 = (0.4e1 / 0.3e1)*_t255;
  const double _t263 = _t75*_t87;
  const double _t264 = _hc0[14]*_t5;
  const double _t267 = _t264*_t266;
  const double _t268 = -0.4e1 / 0.3e1*_hc0[1]*_t15*_t83 - 0.1e1 / 0.6e1*_hc0[7]*_t3*_t4*_t69*_t83 + _t262 + _t263 + _t267;
  const double _t269 = -_t250 + _t251;
  const double _t270 = _hc0[5]*_t21*_t239;
  const double _t271 = (0.1e1 / 0.4e1)*_t270;
  const double _t272 = _t1*((0.1e1 / 0.4e1)*_hc0[11]*_t21*_t69*_t87 - _t249 - _t271) + _t252;
  const double _t273 = (0.1e1 / 0.2e1)*_t270;
  const double _t274 = _t1*((0.1e1 / 0.2e1)*_hc0[11]*_t21*_t69*_t87 - _t259 - _t273) + _t260;
  const double _t276 = _hc0[1]*_t275;
  const double _t277 = _t2*_t276;
  const double _t278 = _hc0[10]*_t83;
  const double _t279 = _t278*_t32;
  const double _t281 = _hc0[4]*_t280;
  const double _t282 = _t281*_t86;
  const double _t283 = (0.3e1 / 0.8e1)*_t277 + (0.1e1 / 0.8e1)*_t279 - 0.3e1 / 0.8e1*_t282;
  const double _t284 = (0.3e1 / 0.4e1)*_t277 + (0.1e1 / 0.4e1)*_t279 - 0.3e1 / 0.4e1*_t282;
  const double _t285 = (0.3e1 / 0.2e1)*_t277 + (0.1e1 / 0.2e1)*_t279 - 0.3e1 / 0.2e1*_t282;
  const double d3F_dna3 = _t1*(_t100 + _t130 + _t95) - _t131*_t96 - _t132*_t45 + _t135 + 0.3e1*_t36 + 0.3e1*_t41;
  const double d3F_dna2_dnb = _t1*(_t113*_t43 + _t113*_t54 + _t114*_t45 + _t114*_t55 + _t137 + _t143 + _t144 - _t148*_t37 - _t151*_t38 + _t34*_t40 + _t95) + _t135 - _t152*_t47 - _t153*_t49 + _t156 + _t46;
  const double d3F_dna_dnb2 = _t1*(-_hc0[2]*_t104 - _hc0[2]*_t33 + (0.56e2 / 0.9e1)*_t11*_t27*_t54 + _t14*_t162 + (0.4e1 / 0.9e1)*_t15*_t3*_t4*_t55 - _t158 - _t161 + 0.4e1*_t32*_t52*_t7 - _t92 - _t94) + _t156 + _t164 + _t60;
  const double d3F_dnb3 = _t1*(_t153*_t99 - _t158 - _t161 + _t163*_t97 + _t169 + _t95) + _t164 + 0.3e1*_t58 + 0.3e1*_t59;
  const double d3F_dna2_dgaa = _t195;
  const double d3F_dna2_dgab = 0.2e1*_hc0[5]*_t14*_t22*_t9 + _t1*(_t197 + _t212) - _t215;
  const double d3F_dna2_dgbb = _t195;
  const double d3F_dna_dnb_dgaa = _t224;
  const double d3F_dna_dnb_dgab = _t1*(_t226 + _t229 + _t232) - _t215 - _t74 - _t81;
  const double d3F_dna_dnb_dgbb = _t224;
  const double d3F_dnb2_dgaa = _t236;
  const double d3F_dnb2_dgab = 0.2e1*_hc0[5]*_t21*_t22*_t9 + _t1*(_t227 + _t232 + _t238) - _t215;
  const double d3F_dnb2_dgbb = _t236;
  const double d3F_dna_dgaa2 = _t253;
  const double d3F_dna_dgaa_dgab = _t261;
  const double d3F_dna_dgaa_dgbb = _t253;
  const double d3F_dna_dgab2 = _t1*(_hc0[11]*_t14*_t69*_t87 - _t240 - _t268) + _t269;
  const double d3F_dna_dgab_dgbb = _t261;
  const double d3F_dna_dgbb2 = _t253;
  const double d3F_dnb_dgaa2 = _t272;
  const double d3F_dnb_dgaa_dgab = _t274;
  const double d3F_dnb_dgaa_dgbb = _t272;
  const double d3F_dnb_dgab2 = _t1*(_hc0[11]*_t21*_t69*_t87 - _t268 - _t270) + _t269;
  const double d3F_dnb_dgab_dgbb = _t274;
  const double d3F_dnb_dgbb2 = _t272;
  const double d3F_dgaa3 = _t283;
  const double d3F_dgaa2_dgab = _t284;
  const double d3F_dgaa2_dgbb = _t283;
  const double d3F_dgaa_dgab2 = _t285;
  const double d3F_dgaa_dgab_dgbb = _t284;
  const double d3F_dgaa_dgbb2 = _t283;
  const double d3F_dgab3 = 0.3e1*_t277 + _t279 - 0.3e1*_t282;
  const double d3F_dgab2_dgbb = _t285;
  const double d3F_dgab_dgbb2 = _t284;
  const double d3F_dgbb3 = _t283;
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
  const double _t286 = 0.24e2*_t102;
  const double _t287 = 0.24e2*_t243*_t7;
  const double _t301 = _t11*_t97;
  const double _t306 = _t5*_t99;
  const double _t307 = _t11*_t91;
  const double _t309 = _t5*_t93;
  const double _t333 = xc_powr(_t1, -16, 3);
  const double _t335 = (0.16e2 / 0.3e1)*_t15;
  const double _t337 = (0.2e1 / 0.3e1)*_t9;
  const double _t340 = 0.12e2*_t102;
  const double _t358 = (0.28e2 / 0.27e2)*_t27;
  const double _t361 = _t11*_t131;
  const double _t362 = _t101*_t7;
  const double _t370 = _t154*_t7;
  const double _t382 = _t32*_t7;
  const double _t383 = _t15*_t47;
  const double _t385 = _t49*_t5;
  const double _t386 = 0.2e1*_t57;
  const double _t388 = 0.18e2*_t103;
  const double _t399 = (0.14e2 / 0.9e1)*_t170;
  const double _t400 = _t22*_t64;
  const double _t401 = _t173*_t400;
  const double _t407 = _t172*_t22;
  const double _t412 = xc_powr(_t1, -17, 3);
  const double _t428 = (0.28e2 / 0.9e1)*_t170;
  const double _t429 = (0.2e1 / 0.9e1)*_t400;
  const double _t430 = _t429*_t5;
  const double _t435 = _t22*_t28;
  const double _t447 = _t7*_t90;
  const double _t448 = _t22*_t447;
  const double _t480 = _t245*_t64;
  const double _t481 = (0.1e1 / 0.3e1)*_t244;
  const double _t482 = _t246*_t247;
  const double _t491 = xc_powi(_t1, -6);
  const double _t492 = _t5*_t83;
  const double _t496 = _t69*_t87;
  const double _t502 = (0.2e1 / 0.3e1)*_t244;
  const double _t503 = _t247*_t68;
  const double _t511 = (0.4e1 / 0.3e1)*_t244;
  const double _t512 = _t266*_t5;
  const double _t515 = (0.8e1 / 0.3e1)*_t15;
  const double _t516 = _t22*_t515;
  const double _t540 = _t280*_t69;
  const double _t570 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t288 = _hc0[23]*_t37 + _hc0[28]*_t38;
  const double _t289 = _hc0[22]*_t37 + _hc0[27]*_t38;
  const double _t290 = _hc0[23]*_t14 - _t289;
  const double _t291 = _hc0[27]*_t37 + _hc0[31]*_t38;
  const double _t292 = _hc0[28]*_t14 - _t291;
  const double _t293 = _hc0[12]*_t113 + _hc0[16]*_t114;
  const double _t294 = _hc0[12]*_t35;
  const double _t295 = _hc0[21]*_t37 + _hc0[26]*_t38;
  const double _t296 = _hc0[22]*_t14 - _t295;
  const double _t297 = _hc0[26]*_t37 + _hc0[30]*_t38;
  const double _t298 = _hc0[27]*_t14 - _t297;
  const double _t299 = _hc0[11]*_t113 + _hc0[15]*_t114;
  const double _t300 = _t14*_t290 + _t294 - _t296*_t37 - _t298*_t38 + _t299;
  const double _t302 = _hc0[30]*_t37 + _hc0[33]*_t38;
  const double _t303 = _hc0[31]*_t14 - _t302;
  const double _t304 = _hc0[15]*_t113 + _hc0[18]*_t114;
  const double _t305 = _hc0[16]*_t35 + _t14*_t292 - _t298*_t37 - _t303*_t38 + _t304;
  const double _t308 = _hc0[5]*_t307;
  const double _t310 = _hc0[8]*_t309;
  const double _t311 = -_t308 - _t310;
  const double _t312 = _t90*_t96;
  const double _t313 = _hc0[11]*_t35;
  const double _t314 = _hc0[20]*_t37 + _hc0[25]*_t38;
  const double _t315 = _hc0[25]*_t37 + _hc0[29]*_t38;
  const double _t316 = _hc0[26]*_t14 - _t315;
  const double _t317 = _hc0[10]*_t113 + _hc0[14]*_t114;
  const double _t318 = _hc0[15]*_t35;
  const double _t319 = _hc0[29]*_t37 + _hc0[32]*_t38;
  const double _t320 = _hc0[30]*_t14 - _t319;
  const double _t321 = _hc0[14]*_t113 + _hc0[17]*_t114;
  const double _t322 = _t14*_t298 - _t316*_t37 + _t318 - _t320*_t38 + _t321;
  const double _t323 = _hc0[4]*_t307;
  const double _t324 = _hc0[7]*_t309;
  const double _t325 = -_t323 - _t324;
  const double _t326 = _t11*_t125;
  const double _t327 = _hc0[32]*_t37 + _hc0[34]*_t38;
  const double _t328 = _hc0[17]*_t113 + _hc0[19]*_t114;
  const double _t329 = _hc0[7]*_t307;
  const double _t330 = _hc0[9]*_t309;
  const double _t331 = -_t329 - _t330;
  const double _t332 = _t129*_t5;
  const double _t334 = (0.140e3 / 0.81e2)*_t18*_t90 + (0.3640e4 / 0.81e2)*_t26*_t333;
  const double _t336 = _t27*_t96;
  const double _t338 = _t15*_t98;
  const double _t339 = -0.56e2 / 0.27e2*_t18*_t27 - 0.1120e4 / 0.27e2*_t26*_t90;
  const double _t341 = _hc0[24]*_t21 - _t288;
  const double _t342 = _hc0[23]*_t21 - _t289;
  const double _t343 = _hc0[28]*_t21 - _t291;
  const double _t344 = _t293 - _t342*_t37 - _t343*_t38;
  const double _t345 = _hc0[22]*_t21 - _t295;
  const double _t346 = _hc0[27]*_t21 - _t297;
  const double _t347 = _t299 - _t345*_t37 - _t346*_t38;
  const double _t348 = _hc0[12]*_t34 + _t14*_t342 + _t347;
  const double _t349 = _hc0[31]*_t21 - _t302;
  const double _t350 = _t304 - _t346*_t37 - _t349*_t38;
  const double _t351 = _hc0[16]*_t34 + _t14*_t343 + _t350;
  const double _t352 = _hc0[5]*_t136;
  const double _t353 = _hc0[26]*_t21 - _t315;
  const double _t354 = _t317 - _t353*_t38 - _t37*(_hc0[21]*_t21 - _t314);
  const double _t355 = _hc0[30]*_t21 - _t319;
  const double _t356 = _t321 - _t353*_t37 - _t355*_t38;
  const double _t357 = _hc0[15]*_t34 + _t14*_t346 + _t356;
  const double _t359 = _t328 - _t355*_t37 - _t38*(_hc0[33]*_t21 - _t327);
  const double _t360 = _t148*_t301 + _t151*_t306 + _t334;
  const double _t363 = _hc0[2]*_t287;
  const double _t364 = _hc0[16]*_t57 + _t21*_t343 + _t350;
  const double _t365 = _t364*_t38;
  const double _t366 = _hc0[12]*_t57;
  const double _t367 = _t21*_t342 + _t347 + _t366;
  const double _t368 = _t367*_t37;
  const double _t369 = _hc0[13]*_t57 + _t21*_t341 + _t344;
  const double _t371 = _t163*_t90;
  const double _t372 = _hc0[15]*_t57;
  const double _t373 = _t21*_t346 + _t356 + _t372;
  const double _t374 = _t373*_t38;
  const double _t375 = _hc0[11]*_t57;
  const double _t376 = _t37*(_t21*_t345 + _t354 + _t375);
  const double _t377 = _t38*(_hc0[18]*_t57 + _t21*_t349 + _t359);
  const double _t378 = _t37*_t373;
  const double _t379 = _t14*_t162;
  const double _t380 = _hc0[2]*_t340;
  const double _t381 = 0.8e1*_t52;
  const double _t384 = _t163*_t27;
  const double _t387 = _hc0[6]*_t165 + _t138*_t386 + _t139*_t301 + _t140*_t306 + _t21*_t369 + _t311 - _t365 - _t368;
  const double _t389 = _t11*_t160;
  const double _t390 = _t157*_t5;
  const double _t391 = _t133*_t389 + _t134*_t390 - _t153*_t172 + _t334 - _t37*(_hc0[5]*_t165 + _t139*_t386 + _t145*_t301 + _t146*_t306 + _t21*_t367 + _t325 - _t374 - _t376) - 0.280e3 / 0.9e1*_t371 - _t38*(_hc0[8]*_t165 + _t140*_t386 + _t146*_t301 + _t149*_t306 + _t21*_t364 + _t331 - _t377 - _t378);
  const double _t392 = (0.16e2 / 0.9e1)*_t15*_t153 - _t335*_t389 - _t337*_t390 + _t339 + (0.224e3 / 0.9e1)*_t384;
  const double _t393 = _hc0[12]*_t186 + _hc0[22]*_t177 + _hc0[27]*_t181;
  const double _t394 = _hc0[11]*_t186 + _hc0[21]*_t177 + _hc0[26]*_t181;
  const double _t395 = (0.1e1 / 0.2e1)*_hc0[22]*_t14*_t22*_t9 - _t394;
  const double _t396 = _t189*_t294;
  const double _t397 = _hc0[15]*_t186 + _hc0[26]*_t177 + _hc0[30]*_t181;
  const double _t398 = (0.1e1 / 0.2e1)*_hc0[27]*_t14*_t22*_t9 - _t397;
  const double _t402 = _hc0[11]*_t399 + _hc0[15]*_t401 + _t172*_t179;
  const double _t403 = _hc0[10]*_t186 + _hc0[20]*_t177 + _hc0[25]*_t181;
  const double _t404 = _t189*_t313;
  const double _t405 = _hc0[14]*_t186 + _hc0[25]*_t177 + _hc0[29]*_t181;
  const double _t406 = (0.1e1 / 0.2e1)*_hc0[26]*_t14*_t22*_t9 - _t405;
  const double _t408 = _hc0[10]*_t399 + _hc0[14]*_t401 + _hc0[4]*_t407;
  const double _t409 = _t189*_t318;
  const double _t410 = _hc0[17]*_t186 + _hc0[29]*_t177 + _hc0[32]*_t181;
  const double _t411 = _hc0[14]*_t399 + _hc0[17]*_t401 + _hc0[7]*_t407;
  const double _t413 = _hc0[4]*_t412;
  const double _t414 = (0.140e3 / 0.27e2)*_t413;
  const double _t415 = (0.140e3 / 0.27e2)*_t23*_t90;
  const double _t416 = _t174*_t5;
  const double _t417 = _t170*_t416;
  const double _t418 = (0.7e1 / 0.27e2)*_t417;
  const double _t419 = _t414 + _t415 + _t418;
  const double _t420 = _t22*_t43;
  const double _t421 = (0.14e2 / 0.3e1)*_t171 + (0.1e1 / 0.3e1)*_t196 + (0.14e2 / 0.3e1)*_t23*_t27;
  const double _t422 = _t1*((0.1e1 / 0.2e1)*_hc0[5]*_t105*_t22*_t9 + (0.56e2 / 0.9e1)*_t11*_t188*_t27 - _t125*_t186 + _t14*(-_t110*_t186 + _t14*((0.1e1 / 0.2e1)*_hc0[23]*_t14*_t22*_t9 - _t393) - _t37*_t395 - _t38*_t398 + (0.1e1 / 0.2e1)*_t396 + _t402) + (0.4e1 / 0.9e1)*_t15*_t193*_t3*_t4 + 0.2e1*_t183*_t35 + (0.28e2 / 0.9e1)*_t22*_t27*_t43 - _t37*(-_t121*_t186 + _t14*_t395 - _t37*((0.1e1 / 0.2e1)*_hc0[21]*_t14*_t22*_t9 - _t403) - _t38*_t406 + (0.1e1 / 0.2e1)*_t404 + _t408) - _t38*(-_t123*_t186 + _t14*_t398 - _t37*_t406 - _t38*((0.1e1 / 0.2e1)*_hc0[30]*_t14*_t22*_t9 - _t410) + (0.1e1 / 0.2e1)*_t409 + _t411) - _t419) - _t132*_t193 - 0.2e1*_t15*_t420 + 0.3e1*_t184 - _t188*_t361 + (0.3e1 / 0.2e1)*_t190 + _t421;
  const double _t423 = _hc0[12]*_t206 + _hc0[22]*_t198 + _hc0[27]*_t201;
  const double _t424 = _hc0[11]*_t206 + _hc0[21]*_t198 + _hc0[26]*_t201;
  const double _t425 = _hc0[22]*_t14*_t22*_t9 - _t424;
  const double _t426 = _hc0[15]*_t206 + _hc0[26]*_t198 + _hc0[30]*_t201;
  const double _t427 = _hc0[27]*_t14*_t22*_t9 - _t426;
  const double _t431 = _hc0[11]*_t428 + _hc0[15]*_t430 + _t179*_t28;
  const double _t432 = _hc0[10]*_t206 + _hc0[20]*_t198 + _hc0[25]*_t201;
  const double _t433 = _hc0[14]*_t206 + _hc0[25]*_t198 + _hc0[29]*_t201;
  const double _t434 = _hc0[26]*_t14*_t22*_t9 - _t433;
  const double _t436 = _hc0[10]*_t428 + _hc0[4]*_t435 + _t264*_t429;
  const double _t437 = _hc0[17]*_t206 + _hc0[29]*_t198 + _hc0[32]*_t201;
  const double _t438 = _hc0[14]*_t428 + _hc0[17]*_t430 + _hc0[7]*_t435;
  const double _t439 = (0.280e3 / 0.27e2)*_t413;
  const double _t440 = _t23*_t91;
  const double _t441 = (0.14e2 / 0.27e2)*_t417;
  const double _t442 = _t439 + _t440 + _t441;
  const double _t443 = _t133*_t23 + (0.28e2 / 0.3e1)*_t171 + _t177*_t416;
  const double _t444 = 0.2e1*_t217;
  const double _t445 = _t189*_t352;
  const double _t446 = (0.1e1 / 0.2e1)*_hc0[27]*_t21*_t22*_t9 - _t397;
  const double _t449 = _hc0[15]*_t448;
  const double _t450 = (0.1e1 / 0.2e1)*_hc0[26]*_t21*_t22*_t9 - _t405;
  const double _t451 = -_t146*_t186 - _t37*_t450 - _t38*((0.1e1 / 0.2e1)*_hc0[30]*_t21*_t22*_t9 - _t410) + _t411;
  const double _t452 = (0.1e1 / 0.2e1)*_hc0[22]*_t21*_t22*_t9 - _t394;
  const double _t453 = _hc0[11]*_t448;
  const double _t454 = -_t145*_t186 - _t37*((0.1e1 / 0.2e1)*_hc0[21]*_t21*_t22*_t9 - _t403) - _t38*_t450 + _t408;
  const double _t455 = (0.1e1 / 0.2e1)*_hc0[23]*_t21*_t22*_t9 - _t393;
  const double _t456 = _hc0[12]*_t448;
  const double _t457 = -_t139*_t186 - _t37*_t452 - _t38*_t446 + _t402;
  const double _t458 = _t1*(_t113*_t188 + _t113*_t220 + _t114*_t193 + _t114*_t222 + _t14*(_t14*_t455 + _t456 + _t457) - _t148*_t186 + _t183*_t34 + _t216*_t35 - _t37*(_t14*_t452 + _t453 + _t454) - _t38*(_t14*_t446 + _t449 + _t451) + _t407*_t43 + _t407*_t54 - _t414 - _t415 - _t418 + (0.1e1 / 0.2e1)*_t445) + _t194 - _t220*_t383 - _t222*_t385 + _t229 + _t421 + _t444;
  const double _t459 = _hc0[27]*_t21*_t22*_t9 - _t426;
  const double _t460 = _hc0[26]*_t21*_t22*_t9 - _t433;
  const double _t461 = -_t146*_t206 - _t37*_t460 - _t38*(_hc0[30]*_t21*_t22*_t9 - _t437) + _t438;
  const double _t462 = _hc0[22]*_t21*_t22*_t9 - _t424;
  const double _t463 = -_t145*_t206 - _t37*(_hc0[21]*_t21*_t22*_t9 - _t432) - _t38*_t460 + _t436;
  const double _t464 = _hc0[23]*_t21*_t22*_t9 - _t423;
  const double _t465 = -_t139*_t206 - _t37*_t462 - _t38*_t459 + _t431;
  const double _t466 = 0.4e1*_t219 + 0.2e1*_t226;
  const double _t467 = _t189*_t366;
  const double _t468 = _t21*_t455 + _t457 + (0.1e1 / 0.2e1)*_t467;
  const double _t469 = _t179*_t333*_t7;
  const double _t470 = _t189*_t375;
  const double _t471 = _t189*_t372;
  const double _t472 = -0.56e2 / 0.9e1*_t11*_t220*_t27 - 0.4e1 / 0.9e1*_t15*_t222*_t3*_t4 + _t160*_t186 - 0.28e2 / 0.9e1*_t22*_t27*_t54 + _t37*(_t21*_t452 + _t454 + (0.1e1 / 0.2e1)*_t470) + _t38*(_t21*_t446 + _t451 + (0.1e1 / 0.2e1)*_t471) + _t419;
  const double _t473 = -_t132*_t222 - _t220*_t361 - 0.2e1*_t221 + _t421;
  const double _t474 = _t1*(_t14*_t468 + 0.4e1*_t216*_t32*_t7 - _t218 - 0.3e1*_t469 - _t472) + _t228 + _t235 + _t444 + _t473;
  const double _t475 = _t21*_t464 + _t465 + _t467;
  const double _t476 = -0.56e2 / 0.9e1*_t11*_t230*_t27 - 0.4e1 / 0.9e1*_t15*_t231*_t3*_t4 + _t160*_t206 - 0.56e2 / 0.9e1*_t22*_t27*_t54 + _t37*(_t21*_t462 + _t463 + _t470) + _t38*(_t21*_t459 + _t461 + _t471) + _t442;
  const double _t477 = -_t131*_t22*_t54 - _t132*_t231 - _t230*_t361 + _t443;
  const double _t478 = _t1*((0.1e1 / 0.2e1)*_hc0[5]*_t165*_t22*_t9 + _t21*_t468 + 0.2e1*_t216*_t57 - _t472) + 0.3e1*_t233 + (0.3e1 / 0.2e1)*_t234 + _t473;
  const double _t479 = _hc0[12]*_t14*_t239;
  const double _t483 = _hc0[11]*_t480 - 0.1e1 / 0.24e2*_hc0[15]*_t3*_t4*_t69*_t83 + _hc0[21]*_t481 + _hc0[26]*_t482 - 0.1e1 / 0.3e1*_hc0[5]*_t15*_t83;
  const double _t484 = _hc0[11]*_t14;
  const double _t485 = _t239*_t484;
  const double _t486 = -0.1e1 / 0.24e2*_hc0[14]*_t3*_t4*_t69*_t83 + _hc0[20]*_t481 + _hc0[25]*_t482 - 0.1e1 / 0.3e1*_hc0[4]*_t15*_t83 + _t242*_t64*_t87;
  const double _t487 = _t188*_t206;
  const double _t488 = _t119*_t239;
  const double _t489 = _hc0[15]*_t14*_t239;
  const double _t490 = _hc0[14]*_t480 - 0.1e1 / 0.24e2*_hc0[17]*_t3*_t4*_t69*_t83 + _hc0[25]*_t481 + _hc0[29]*_t482 - 0.1e1 / 0.3e1*_hc0[7]*_t15*_t83;
  const double _t493 = _hc0[7]*_t64;
  const double _t494 = _t492*_t493;
  const double _t495 = -0.7e1 / 0.9e1*_hc0[10]*_t22*_t491 - 0.1e1 / 0.18e2*_hc0[14]*_t243*_t3*_t4*_t87 - 0.7e1 / 0.9e1*_hc0[4]*_t170*_t87 + (0.7e1 / 0.9e1)*_t27*_t84 + (0.1e1 / 0.18e2)*_t494;
  const double _t497 = _t484*_t496;
  const double _t498 = -_t254 + (0.1e1 / 0.2e1)*_t497;
  const double _t499 = _t70*_t83;
  const double _t500 = _t134*_t84 - _t256 - _t257 - _t258 + _t499*_t68;
  const double _t501 = _t1*((0.1e1 / 0.4e1)*_hc0[11]*_t35*_t69*_t87 + _t14*((0.1e1 / 0.4e1)*_hc0[22]*_t14*_t69*_t87 - 0.1e1 / 0.4e1*_t479 - _t483) + (0.1e1 / 0.3e1)*_t15*_t43*_t83 - _t37*((0.1e1 / 0.4e1)*_hc0[21]*_t14*_t69*_t87 - 0.1e1 / 0.4e1*_t485 - _t486) - _t38*((0.1e1 / 0.4e1)*_hc0[26]*_t14*_t69*_t87 - 0.1e1 / 0.4e1*_t489 - _t490) - _t487 - 0.1e1 / 0.4e1*_t488 - _t495) + _t498 + _t500;
  const double _t504 = -0.1e1 / 0.12e2*_hc0[15]*_t3*_t4*_t69*_t83 + _hc0[21]*_t502 + _hc0[26]*_t503 - 0.2e1 / 0.3e1*_hc0[5]*_t15*_t83 + _t178*_t87;
  const double _t505 = -0.1e1 / 0.12e2*_hc0[14]*_t3*_t4*_t69*_t83 + _hc0[20]*_t502 + _hc0[25]*_t503 - 0.2e1 / 0.3e1*_hc0[4]*_t15*_t83 + _t185*_t87;
  const double _t506 = -0.1e1 / 0.12e2*_hc0[17]*_t3*_t4*_t69*_t83 + _hc0[25]*_t502 + _hc0[29]*_t503 - 0.2e1 / 0.3e1*_hc0[7]*_t15*_t83 + _t191*_t87;
  const double _t507 = -0.14e2 / 0.9e1*_hc0[10]*_t22*_t491 - 0.1e1 / 0.9e1*_hc0[14]*_t243*_t3*_t4*_t87 - 0.14e2 / 0.9e1*_hc0[4]*_t170*_t87 + _t172*_t84 + _t173*_t493*_t83;
  const double _t508 = -_t240 + _t497;
  const double _t509 = _t200*_t84 - _t262 - _t263 - _t267 + _t499*_t76;
  const double _t510 = _t1*((0.1e1 / 0.2e1)*_hc0[11]*_t35*_t69*_t87 + _t14*((0.1e1 / 0.2e1)*_hc0[22]*_t14*_t69*_t87 - 0.1e1 / 0.2e1*_t479 - _t504) + (0.2e1 / 0.3e1)*_t15*_t43*_t83 - _t186*_t208 - _t37*((0.1e1 / 0.2e1)*_hc0[21]*_t14*_t69*_t87 - 0.1e1 / 0.2e1*_t485 - _t505) - _t38*((0.1e1 / 0.2e1)*_hc0[26]*_t14*_t69*_t87 - 0.1e1 / 0.2e1*_t489 - _t506) - _t487 - 0.1e1 / 0.2e1*_t488 - _t507) + _t508 + _t509;
  const double _t513 = -0.1e1 / 0.6e1*_hc0[15]*_t3*_t4*_t69*_t83 + _hc0[21]*_t511 + _hc0[26]*_t512 - 0.4e1 / 0.3e1*_hc0[5]*_t15*_t83 + _t199*_t87;
  const double _t514 = -0.1e1 / 0.6e1*_hc0[14]*_t3*_t4*_t69*_t83 + _hc0[20]*_t511 + _hc0[25]*_t512 - 0.4e1 / 0.3e1*_hc0[4]*_t15*_t83 + _t205*_t87;
  const double _t517 = -0.1e1 / 0.6e1*_hc0[17]*_t3*_t4*_t69*_t83 + _hc0[25]*_t511 + _hc0[29]*_t512 - 0.4e1 / 0.3e1*_hc0[7]*_t15*_t83 + _t209*_t87;
  const double _t518 = -0.28e2 / 0.9e1*_hc0[10]*_t22*_t491 - 0.2e1 / 0.9e1*_hc0[14]*_t243*_t3*_t4*_t87 - 0.28e2 / 0.9e1*_hc0[4]*_t170*_t87 + _t28*_t84 + (0.2e1 / 0.9e1)*_t494;
  const double _t519 = -_t102*_t245*_t264 - _t213*_t87 + _t214*_t499 - 0.8e1 / 0.3e1*_t255 + _t515*_t84;
  const double _t520 = _hc0[12]*_t21*_t239;
  const double _t521 = (0.1e1 / 0.4e1)*_hc0[22]*_t21*_t69*_t87 - _t483 - 0.1e1 / 0.4e1*_t520;
  const double _t522 = _hc0[5]*_t447*_t83;
  const double _t523 = _hc0[11]*_t21;
  const double _t524 = _t239*_t523;
  const double _t525 = _t206*_t220;
  const double _t526 = _hc0[15]*_t21*_t239;
  const double _t527 = -0.1e1 / 0.3e1*_t15*_t54*_t83 + _t37*((0.1e1 / 0.4e1)*_hc0[21]*_t21*_t69*_t87 - _t486 - 0.1e1 / 0.4e1*_t524) + _t38*((0.1e1 / 0.4e1)*_hc0[26]*_t21*_t69*_t87 - _t490 - 0.1e1 / 0.4e1*_t526) + _t495 + _t525;
  const double _t528 = _t496*_t523;
  const double _t529 = _t1*((0.1e1 / 0.2e1)*_hc0[11]*_t412*_t7*_t87 + _t14*_t521 - 0.1e1 / 0.2e1*_t522 - _t527) - _t241 - _t271 + (0.1e1 / 0.4e1)*_t497 + _t500 + (0.1e1 / 0.4e1)*_t528;
  const double _t530 = (0.1e1 / 0.2e1)*_hc0[22]*_t21*_t69*_t87 - _t504 - 0.1e1 / 0.2e1*_t520;
  const double _t531 = -0.2e1 / 0.3e1*_t15*_t54*_t83 + _t186*_t230 + _t37*((0.1e1 / 0.2e1)*_hc0[21]*_t21*_t69*_t87 - _t505 - 0.1e1 / 0.2e1*_t524) + _t38*((0.1e1 / 0.2e1)*_hc0[26]*_t21*_t69*_t87 - _t506 - 0.1e1 / 0.2e1*_t526) + _t507 + _t525;
  const double _t532 = -_t273 + (0.1e1 / 0.2e1)*_t528;
  const double _t533 = _t1*(_hc0[11]*_t412*_t7*_t87 + _t14*_t530 - _t522 - _t531) + _t498 + _t509 + _t532;
  const double _t534 = _hc0[22]*_t21*_t69*_t87 - _t513 - _t520;
  const double _t535 = -0.4e1 / 0.3e1*_t15*_t54*_t83 + _t230*_t516 + _t37*(_hc0[21]*_t21*_t69*_t87 - _t514 - _t524) + _t38*(_hc0[26]*_t21*_t69*_t87 - _t517 - _t526) + _t518;
  const double _t536 = -_t270 + _t528;
  const double _t537 = _t159*_t239;
  const double _t538 = _t1*((0.1e1 / 0.4e1)*_hc0[11]*_t57*_t69*_t87 + _t21*_t521 - _t527 - 0.1e1 / 0.4e1*_t537) + _t500 + _t532;
  const double _t539 = _t1*((0.1e1 / 0.2e1)*_hc0[11]*_t57*_t69*_t87 + _t21*_t530 - _t531 - 0.1e1 / 0.2e1*_t537) + _t509 + _t536;
  const double _t541 = _t484*_t540;
  const double _t542 = _t16*_t275;
  const double _t543 = _hc0[20]/xc_powr(_t1, 19, 3);
  const double _t544 = _t275*_t70;
  const double _t545 = _t5*_t544;
  const double _t546 = _hc0[25]*_t333;
  const double _t547 = -0.1e1 / 0.16e2*_hc0[14]*_t102*_t280*_t3*_t4 - 0.1e1 / 0.2e1*_hc0[4]*_t280*_t64 + _t265*_t543 + (0.1e1 / 0.48e2)*_t492*_t546 + (0.1e1 / 0.2e1)*_t542 + (0.1e1 / 0.16e2)*_t545;
  const double _t548 = _t281*_t69;
  const double _t549 = _t102*_t278;
  const double _t550 = _t276*_t9;
  const double _t551 = -0.3e1 / 0.8e1*_t548 + (0.1e1 / 0.8e1)*_t549 + (0.3e1 / 0.8e1)*_t550;
  const double _t552 = _t1*((0.1e1 / 0.8e1)*_hc0[21]*_t102*_t14*_t83 + (0.3e1 / 0.8e1)*_hc0[5]*_t14*_t275*_t9 - 0.3e1 / 0.8e1*_t541 - _t547) + _t551;
  const double _t553 = _t546*_t83;
  const double _t554 = -0.1e1 / 0.8e1*_hc0[14]*_t102*_t280*_t3*_t4 - _hc0[4]*_t280*_t64 + _t245*_t543 + _t246*_t553 + _t542 + (0.1e1 / 0.8e1)*_t545;
  const double _t555 = -0.3e1 / 0.4e1*_t548 + (0.1e1 / 0.4e1)*_t549 + (0.3e1 / 0.4e1)*_t550;
  const double _t556 = _t1*((0.1e1 / 0.4e1)*_hc0[21]*_t102*_t14*_t83 + (0.3e1 / 0.4e1)*_hc0[5]*_t14*_t275*_t9 - 0.3e1 / 0.4e1*_t541 - _t554) + _t555;
  const double _t557 = _t543*_t87;
  const double _t558 = -0.1e1 / 0.4e1*_hc0[14]*_t102*_t280*_t3*_t4 - 0.2e1*_hc0[4]*_t280*_t64 + 0.2e1*_t542 + (0.1e1 / 0.4e1)*_t545 + _t553*_t68 + (0.2e1 / 0.3e1)*_t557;
  const double _t559 = -0.3e1 / 0.2e1*_t548 + (0.1e1 / 0.2e1)*_t549 + (0.3e1 / 0.2e1)*_t550;
  const double _t560 = _t1*((0.1e1 / 0.2e1)*_hc0[21]*_t102*_t14*_t83 + (0.3e1 / 0.2e1)*_hc0[5]*_t14*_t275*_t9 - 0.3e1 / 0.2e1*_t541 - _t558) + _t559;
  const double _t561 = -0.1e1 / 0.2e1*_hc0[14]*_t102*_t280*_t3*_t4 - 0.4e1*_hc0[4]*_t280*_t64 + 0.4e1*_t542 + _t544*_t6 + _t553*_t76 + (0.4e1 / 0.3e1)*_t557;
  const double _t562 = -0.3e1*_t548 + _t549 + 0.3e1*_t550;
  const double _t563 = _t523*_t540;
  const double _t564 = _t1*((0.1e1 / 0.8e1)*_hc0[21]*_t102*_t21*_t83 + (0.3e1 / 0.8e1)*_hc0[5]*_t21*_t275*_t9 - _t547 - 0.3e1 / 0.8e1*_t563) + _t551;
  const double _t565 = _t1*((0.1e1 / 0.4e1)*_hc0[21]*_t102*_t21*_t83 + (0.3e1 / 0.4e1)*_hc0[5]*_t21*_t275*_t9 - _t554 - 0.3e1 / 0.4e1*_t563) + _t555;
  const double _t566 = _t1*((0.1e1 / 0.2e1)*_hc0[21]*_t102*_t21*_t83 + (0.3e1 / 0.2e1)*_hc0[5]*_t21*_t275*_t9 - _t558 - 0.3e1 / 0.2e1*_t563) + _t559;
  const double _t567 = _hc0[1]*_t2/xc_powr(_t10, 7, 2);
  const double _t568 = _hc0[10]*_t275;
  const double _t569 = _t32*_t568;
  const double _t571 = (0.1e1 / 0.16e2)*_hc0[20]*_t280*_t90 + (0.15e2 / 0.16e2)*_hc0[4]*_t570*_t86 - 0.15e2 / 0.16e2*_t567 - 0.3e1 / 0.8e1*_t569;
  const double _t572 = (0.1e1 / 0.8e1)*_hc0[20]*_t280*_t90 + (0.15e2 / 0.8e1)*_hc0[4]*_t570*_t86 - 0.15e2 / 0.8e1*_t567 - 0.3e1 / 0.4e1*_t569;
  const double _t573 = (0.1e1 / 0.4e1)*_hc0[20]*_t280*_t90 + (0.15e2 / 0.4e1)*_hc0[4]*_t570*_t86 - 0.15e2 / 0.4e1*_t567 - 0.3e1 / 0.2e1*_t569;
  const double _t574 = (0.1e1 / 0.2e1)*_hc0[20]*_t280*_t90 + (0.15e2 / 0.2e1)*_hc0[4]*_t570*_t86 - 0.15e2 / 0.2e1*_t567 - 0.3e1*_t569;
  const double d4F_dna4 = _t1*(_hc0[2]*(-_t286 + _t287) + 0.3e1*_t105*_t40 + 0.3e1*_t116*_t35 + _t133*_t326 + _t134*_t332 + _t14*(_hc0[6]*_t105 + _t108*_t118 + _t110*_t301 + _t112*_t306 + _t14*(_hc0[13]*_t35 + _t14*(_hc0[24]*_t14 - _t288) - _t290*_t37 - _t292*_t38 + _t293) - _t300*_t37 - _t305*_t38 + _t311) - _t172*_t98 - 0.280e3 / 0.9e1*_t312 + _t334 - _t37*(_hc0[5]*_t105 + _t110*_t118 + _t121*_t301 + _t123*_t306 + _t14*_t300 - _t322*_t38 + _t325 - _t37*(_t14*_t296 + _t313 - _t316*_t38 + _t317 - _t37*(_hc0[21]*_t14 - _t314))) - _t38*(_hc0[8]*_t105 + _t112*_t118 + _t123*_t301 + _t127*_t306 + _t14*_t305 - _t322*_t37 + _t331 - _t38*(_hc0[18]*_t35 + _t14*_t303 - _t320*_t37 + _t328 - _t38*(_hc0[33]*_t14 - _t327)))) + 0.4e1*_t106 + 0.4e1*_t117 - _t326*_t335 - _t332*_t337 + (0.224e3 / 0.9e1)*_t336 + (0.16e2 / 0.9e1)*_t338 + _t339 + 0.8e1*_t35*_t40;
  const double d4F_dna3_dnb = _t1*(_hc0[2]*(_t287 - _t340) + _t105*_t52 + _t113*_t125 + _t114*_t129 + _t116*_t34 + _t118*_t142 + 0.2e1*_t136*_t40 + _t14*(_hc0[6]*_t136 + _t108*_t34 + _t110*_t113 + _t112*_t114 + _t113*_t139 + _t114*_t140 + _t138*_t35 + _t14*(_hc0[13]*_t34 + _t14*_t341 + _t344) + _t311 - _t348*_t37 - _t351*_t38) - _t153*_t93 - _t163*_t91 - 0.560e3 / 0.27e2*_t312 - _t358*_t98 + _t360 - _t37*(_t110*_t34 + _t113*_t121 + _t113*_t145 + _t114*_t123 + _t114*_t146 + _t139*_t35 + _t14*_t348 + _t325 + _t352 - _t357*_t38 - _t37*(_hc0[11]*_t34 + _t14*_t345 + _t354)) - _t38*(_hc0[8]*_t136 + _t112*_t34 + _t113*_t123 + _t113*_t146 + _t114*_t127 + _t114*_t149 + _t14*_t351 + _t140*_t35 + _t331 - _t357*_t37 - _t38*(_hc0[18]*_t34 + _t14*_t349 + _t359))) + _t130 - _t132*_t151 + _t133*_t163 + _t134*_t153 + 0.3e1*_t137 + 0.3e1*_t143 + 0.3e1*_t144 - _t148*_t361 + (0.140e3 / 0.9e1)*_t336 + (0.10e2 / 0.9e1)*_t338 + _t339 + _t362*_t40;
  const double d4F_dna2_dnb2 = _t1*(-_t104*_t40 + _t113*_t160 + _t114*_t157 + _t136*_t168 + _t14*(-_hc0[6]*_t104 - _hc0[6]*_t33 + (0.56e2 / 0.9e1)*_t11*_t139*_t27 + 0.4e1*_t138*_t32*_t7 + _t14*_t369 + (0.4e1 / 0.9e1)*_t140*_t15*_t3*_t4 - _t308 - _t310 - _t365 - _t368) + _t142*_t370 - _t153*_t358 + _t162*_t35 - _t33*_t40 + _t360 + _t363 - _t37*(-_hc0[5]*_t104 - _hc0[5]*_t33 + (0.56e2 / 0.9e1)*_t11*_t145*_t27 + 0.4e1*_t139*_t32*_t7 + _t14*_t367 + (0.4e1 / 0.9e1)*_t146*_t15*_t3*_t4 - _t323 - _t324 - _t374 - _t376) - 0.560e3 / 0.27e2*_t371 - _t38*(-_hc0[8]*_t104 - _hc0[8]*_t33 + (0.56e2 / 0.9e1)*_t11*_t146*_t27 + _t14*_t364 + 0.4e1*_t140*_t32*_t7 + (0.4e1 / 0.9e1)*_t149*_t15*_t3*_t4 - _t329 - _t330 - _t377 - _t378) - _t91*_t96 - _t93*_t98) + _t100 + 0.2e1*_t137 + 0.2e1*_t143 + 0.2e1*_t144 - _t148*_t383 - _t151*_t385 + _t153*_t200 - _t155 - _t157*_t385 - _t160*_t383 + _t339 + _t370*_t40 + 0.2e1*_t379 - _t380*_t7 + _t381*_t382 + (0.56e2 / 0.3e1)*_t384;
  const double d4F_dna_dnb3 = -_hc0[2]*_t101 - _hc0[2]*_t388 + _t1*(-_t101*_t52 + _t14*_t387 + _t162*_t362 + _t363 + _t380 - _t388*_t52 + _t391) + _t169 + 0.3e1*_t379 + 0.12e2*_t382*_t52 + _t392;
  const double d4F_dnb4 = _t1*(_hc0[2]*(_t286 + _t287) + 0.3e1*_t162*_t57 + 0.3e1*_t165*_t52 + _t21*_t387 + _t391) + 0.4e1*_t166 + 0.4e1*_t167 + _t381*_t57 + _t392;
  const double d4F_dna3_dgaa = _t422;
  const double d4F_dna3_dgab = _t1*(_hc0[5]*_t105*_t22*_t9 + (0.56e2 / 0.9e1)*_t11*_t208*_t27 - _t125*_t206 + _t14*(-_t110*_t206 + _t14*(_hc0[23]*_t14*_t22*_t9 - _t423) - _t37*_t425 - _t38*_t427 + _t396 + _t431) + (0.4e1 / 0.9e1)*_t15*_t211*_t3*_t4 + 0.2e1*_t203*_t35 + (0.56e2 / 0.9e1)*_t22*_t27*_t43 - _t37*(-_t121*_t206 + _t14*_t425 - _t37*(_hc0[21]*_t14*_t22*_t9 - _t432) - _t38*_t434 + _t404 + _t436) - _t38*(-_t123*_t206 + _t14*_t427 - _t37*_t434 - _t38*(_hc0[30]*_t14*_t22*_t9 - _t437) + _t409 + _t438) - _t442) - _t131*_t420 - _t132*_t211 + 0.3e1*_t190 + 0.3e1*_t204 - _t208*_t361 + _t443;
  const double d4F_dna3_dgbb = _t422;
  const double d4F_dna2_dnb_dgaa = _t458;
  const double d4F_dna2_dnb_dgab = _t1*(_t113*_t208 + _t113*_t230 + _t114*_t211 + _t114*_t231 + _t14*(_t14*_t464 + 0.2e1*_t456 + _t465) - _t148*_t206 + _t203*_t34 + _t225*_t35 + _t28*_t420 - _t37*(_t14*_t462 + 0.2e1*_t453 + _t463) - _t38*(_t14*_t459 + 0.2e1*_t449 + _t461) + _t435*_t54 - _t439 - _t440 - _t441 + _t445) + _t212 - 0.8e1 / 0.3e1*_t221 - _t230*_t383 - _t231*_t385 + _t443 + _t466;
  const double d4F_dna2_dnb_dgbb = _t458;
  const double d4F_dna_dnb2_dgaa = _t474;
  const double d4F_dna_dnb2_dgab = _t1*(_t14*_t475 - 0.2e1*_t218 + 0.4e1*_t225*_t32*_t7 - 0.6e1*_t469 - _t476) + _t238 + _t466 + _t477;
  const double d4F_dna_dnb2_dgbb = _t474;
  const double d4F_dnb3_dgaa = _t478;
  const double d4F_dnb3_dgab = _t1*(_hc0[5]*_t165*_t22*_t9 + _t21*_t475 + 0.2e1*_t225*_t57 - _t476) + 0.3e1*_t234 + 0.3e1*_t237 + _t477;
  const double d4F_dnb3_dgbb = _t478;
  const double d4F_dna2_dgaa2 = _t501;
  const double d4F_dna2_dgaa_dgab = _t510;
  const double d4F_dna2_dgaa_dgbb = _t501;
  const double d4F_dna2_dgab2 = _t1*(_hc0[11]*_t35*_t69*_t87 + _t14*(_hc0[22]*_t14*_t69*_t87 - _t479 - _t513) + (0.4e1 / 0.3e1)*_t15*_t43*_t83 - _t208*_t516 - _t37*(_hc0[21]*_t14*_t69*_t87 - _t485 - _t514) - _t38*(_hc0[26]*_t14*_t69*_t87 - _t489 - _t517) - _t488 - _t518) - 0.2e1*_t240 + 0.2e1*_t497 + _t519;
  const double d4F_dna2_dgab_dgbb = _t510;
  const double d4F_dna2_dgbb2 = _t501;
  const double d4F_dna_dnb_dgaa2 = _t529;
  const double d4F_dna_dnb_dgaa_dgab = _t533;
  const double d4F_dna_dnb_dgaa_dgbb = _t529;
  const double d4F_dna_dnb_dgab2 = _t1*(0.2e1*_hc0[11]*_t412*_t7*_t87 + _t14*_t534 - 0.2e1*_t522 - _t535) + _t508 + _t519 + _t536;
  const double d4F_dna_dnb_dgab_dgbb = _t533;
  const double d4F_dna_dnb_dgbb2 = _t529;
  const double d4F_dnb2_dgaa2 = _t538;
  const double d4F_dnb2_dgaa_dgab = _t539;
  const double d4F_dnb2_dgaa_dgbb = _t538;
  const double d4F_dnb2_dgab2 = _t1*(_hc0[11]*_t57*_t69*_t87 + _t21*_t534 - _t535 - _t537) - 0.2e1*_t270 + _t519 + 0.2e1*_t528;
  const double d4F_dnb2_dgab_dgbb = _t539;
  const double d4F_dnb2_dgbb2 = _t538;
  const double d4F_dna_dgaa3 = _t552;
  const double d4F_dna_dgaa2_dgab = _t556;
  const double d4F_dna_dgaa2_dgbb = _t552;
  const double d4F_dna_dgaa_dgab2 = _t560;
  const double d4F_dna_dgaa_dgab_dgbb = _t556;
  const double d4F_dna_dgaa_dgbb2 = _t552;
  const double d4F_dna_dgab3 = _t1*(_hc0[21]*_t102*_t14*_t83 + 0.3e1*_hc0[5]*_t14*_t275*_t9 - 0.3e1*_t541 - _t561) + _t562;
  const double d4F_dna_dgab2_dgbb = _t560;
  const double d4F_dna_dgab_dgbb2 = _t556;
  const double d4F_dna_dgbb3 = _t552;
  const double d4F_dnb_dgaa3 = _t564;
  const double d4F_dnb_dgaa2_dgab = _t565;
  const double d4F_dnb_dgaa2_dgbb = _t564;
  const double d4F_dnb_dgaa_dgab2 = _t566;
  const double d4F_dnb_dgaa_dgab_dgbb = _t565;
  const double d4F_dnb_dgaa_dgbb2 = _t564;
  const double d4F_dnb_dgab3 = _t1*(_hc0[21]*_t102*_t21*_t83 + 0.3e1*_hc0[5]*_t21*_t275*_t9 - _t561 - 0.3e1*_t563) + _t562;
  const double d4F_dnb_dgab2_dgbb = _t566;
  const double d4F_dnb_dgab_dgbb2 = _t565;
  const double d4F_dnb_dgbb3 = _t564;
  const double d4F_dgaa4 = _t571;
  const double d4F_dgaa3_dgab = _t572;
  const double d4F_dgaa3_dgbb = _t571;
  const double d4F_dgaa2_dgab2 = _t573;
  const double d4F_dgaa2_dgab_dgbb = _t572;
  const double d4F_dgaa2_dgbb2 = _t571;
  const double d4F_dgaa_dgab3 = _t574;
  const double d4F_dgaa_dgab2_dgbb = _t573;
  const double d4F_dgaa_dgab_dgbb2 = _t572;
  const double d4F_dgaa_dgbb3 = _t571;
  const double d4F_dgab4 = _hc0[20]*_t280*_t90 + 0.15e2*_hc0[4]*_t570*_t86 - _t101*_t568 - 0.15e2*_t567;
  const double d4F_dgab3_dgbb = _t574;
  const double d4F_dgab2_dgbb2 = _t573;
  const double d4F_dgab_dgbb3 = _t572;
  const double d4F_dgbb4 = _t571;
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