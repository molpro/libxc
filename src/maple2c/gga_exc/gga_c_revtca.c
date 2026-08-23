/*
  Generated from python/gga_exc/gga_c_revtca.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_revtca
*/

#ifndef _GGA_C_REVTCA_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_REVTCA_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_REVTCA_HELPER_BODIES
#include "gga_c_revtca.c"
#undef _GGA_C_REVTCA_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_REVTCA_HELPER_BODIES
#include "gga_c_revtca.c"
#undef _GGA_C_REVTCA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_REVTCA_HELPER_BODIES
#include "gga_c_revtca.c"
#undef _GGA_C_REVTCA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_REVTCA_HELPER_BODIES
#include "gga_c_revtca.c"
#undef _GGA_C_REVTCA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_REVTCA_HELPER_BODIES
#include "gga_c_revtca.c"
#undef _GGA_C_REVTCA_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_revtca.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_REVTCA_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(sinc_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = sin(x);
  const double _t2 = (0.1e1 / x);
  const double _t3 = _t1*_t2;
#if _KMAX >= 1
  const double _t4 = cos(x);
  const double _t5 = _t2*_t4;
  const double _t6 = (0.1e1 / (x * x));
#endif
#if _KMAX >= 2
  const double _t7 = (0.1e1 / (x * x * x));
  const double _t8 = _t4*_t6;
#endif
#if _KMAX >= 3
  const double _t9 = (0.1e1 / (x * x * x * x));
#endif

  const double f = _t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -_t1*_t6 + _t5;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.2e1*_t1*_t7 - _t3 - 0.2e1*_t8;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.3e1*_t1*_t6 - 0.6e1*_t1*_t9 + 0.6e1*_t4*_t7 - _t5;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = -0.12e2*_t1*_t7 + 0.24e2*_t1/xc_powi(x, 5) + _t3 - 0.24e2*_t4*_t9 + 0.4e1*_t8;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(sinc_taylor_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);
  const double _t2 = (x * x * x * x);
#if _KMAX >= 1
  const double _t3 = (x * x * x);
#endif

  const double f = -0.1e1 / 0.6e1*_t1 + (0.1e1 / 0.120e3)*_t2 - 0.1e1 / 0.5040e4*xc_powi(x, 6) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = (0.1e1 / 0.30e2)*_t3 - 0.1e1 / 0.840e3*xc_powi(x, 5) - 0.1e1 / 0.3e1*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = (0.1e1 / 0.10e2)*_t1 - 0.1e1 / 0.168e3*_t2 - 0.1e1 / 0.3e1;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -0.1e1 / 0.42e2*_t3 + (0.1e1 / 0.5e1)*x;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0.1e1 / 0.5e1 - 0.1e1 / 0.14e2*_t1;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(msinc_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(sinc_taylor_k, _KMAX)(p, x, _hc0);
  const double _t1 = xc_powr(XC_EPSILON, 1, 4);
  const double _t2 = x > _t1;
  const double _t3 = x <= _t1;
#if _KMAX >= 1
  const double _t4 = my_piecewise3(_t2, 0.1e1, 0);
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(sinc_k, _KMAX)(p, my_piecewise3(_t2, x, _t1), _hc1);

  const double f = my_piecewise3(_t3, _hc0[0], _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = my_piecewise3(_t3, _hc0[1], _hc1[1]*_t4);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = my_piecewise3(_t3, _hc0[2], _hc1[2]*(_t4 * _t4));
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = my_piecewise3(_t3, _hc0[3], _hc1[3]*(_t4 * _t4 * _t4));
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = my_piecewise3(_t3, _hc0[4], _hc1[4]*(_t4 * _t4 * _t4 * _t4));
  out[4] = d4f_dx4;
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
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = gaa + 0.2e1*gab + gbb;
  const double _t4 = xc_powr(_t3, 1, 2);
  const double _t5 = M_PI*_t4;
  const double _t6 = xc_powr(0.6e1, 1, 3);
  const double _t7 = (0.1e1 / (M_CBRTPI));
  const double _t8 = _t6*_t7;
  const double _t9 = xc_powr(_t1, -1, 3);
  const double _t10 = (0.1e1 / 0.2e1)*_t9;
  const double _t11 = na - nb;
  const double _t12 = xc_powr(_t1, -4, 3);
  const double _t13 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t15 = (_t11 * _t11 * _t11 * _t11);
  const double _t17 = (0.1e1 / (_t1 * _t1));
  const double _t18 = (_t11 * _t11);
  const double _t19 = _t17*_t18 + 0.1e1;
  const double _t20 = 0.4e1*_t17;
  const double _t21 = _t19*_t20;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(msinc_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t2*_t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f_tcs_k, _KMAX)(p, _t10*_t8, _t11*_t2, _t12*_t4, _hc1);
  const double _t14 = ((_hc0[0]) * (_hc0[0]));
  const double _t16 = _t14*_t15;
  const double _t22 = _t13*_t16 + _t21*na*nb;
  const double _t23 = _hc1[0]*_t22;
  const double zk = _t23;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t24 = _t11*_t17;
  const double _t25 = _t2 - _t24;
  const double _t26 = xc_powr(_t1, -7, 3);
  const double _t28 = (0.4e1 / 0.3e1)*_t4;
  const double _t30 = (0.1e1 / 0.6e1)*_t12;
  const double _t34 = (_t11 * _t11 * _t11);
  const double _t37 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t38 = 0.2e1*_t37;
  const double _t39 = _t18*_t38;
  const double _t40 = 0.2e1*na - 0.2e1*nb;
  const double _t41 = _t17*_t40 - _t39;
  const double _t42 = xc_powi(_t1, -5);
  const double _t43 = 0.4e1*_t42;
  const double _t44 = _t19*_t37;
  const double _t45 = 0.8e1*_t44;
  const double _t46 = _t45*na;
  const double _t48 = xc_powi(_t1, -6);
  const double _t54 = -_t2 - _t24;
  const double _t57 = -_t40;
  const double _t58 = _t17*_t57 - _t39;
  const double _t61 = (0.1e1 / _t4);
  const double _t62 = _t13*_t61;
  const double _t63 = (0.1e1 / 0.2e1)*_t15;
  const double _t27 = _hc1[1]*_t26;
  const double _t29 = _hc1[3]*_t8;
  const double _t31 = _t27*_t28 + _t29*_t30;
  const double _t32 = _hc1[2]*_t25 - _t31;
  const double _t33 = _t22*_t32;
  const double _t35 = _t14*_t34;
  const double _t36 = 0.4e1*_t13*_t35;
  const double _t47 = _hc0[0]*_t15;
  const double _t49 = _hc0[1]*_t48;
  const double _t50 = _t49*_t5;
  const double _t51 = _t16*_t43 + _t46*nb + _t47*_t50;
  const double _t52 = 0.4e1*_t17*_t19*nb + 0.4e1*_t17*_t41*na*nb + _t36 - _t51;
  const double _t53 = _hc1[0]*_t52;
  const double _t55 = _hc1[2]*_t54 - _t31;
  const double _t56 = _t22*_t55;
  const double _t59 = 0.4e1*_t17*_t19*na + 0.4e1*_t17*_t58*na*nb - _t36 - _t51;
  const double _t60 = _hc1[0]*_t59;
  const double _t64 = _hc1[0]*_t63;
  const double _t65 = M_PI*_hc0[1];
  const double _t66 = _hc0[0]*_t65;
  const double _t67 = _t64*_t66;
  const double _t68 = _hc1[1]*_t61;
  const double _t69 = _t22*_t68;
  const double _t70 = _t10*_t69 + _t62*_t67;
  const double _t71 = _t47*_t65;
  const double _t72 = _hc1[0]*_t71;
  const double dF_dna = _t1*_t33 + _t1*_t53 + _t23;
  const double dF_dnb = _t1*_t56 + _t1*_t60 + _t23;
  const double dF_dgaa = _t70;
  const double dF_dgab = _t62*_t72 + _t69*_t9;
  const double dF_dgbb = _t70;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t75 = 0.2e1*_t17;
  const double _t76 = _t11*_t38;
  const double _t77 = -_t75 + _t76;
  const double _t78 = _t26*_t28;
  const double _t79 = _t30*_t8;
  const double _t87 = xc_powr(_t1, -10, 3);
  const double _t88 = (0.28e2 / 0.9e1)*_t87;
  const double _t89 = (0.2e1 / 0.9e1)*_t26;
  const double _t94 = 0.16e2*_t44;
  const double _t95 = 0.8e1*_t17;
  const double _t96 = _t41*_t95;
  const double _t97 = _t37*_t41;
  const double _t98 = 0.16e2*_t97;
  const double _t99 = _t98*na;
  const double _t100 = 0.4e1*_t37;
  const double _t101 = 0.6e1*_t13;
  const double _t102 = _t101*_t18 + _t75;
  const double _t103 = -_t100*_t40 + _t102;
  const double _t104 = _t20*na;
  const double _t105 = _t103*_t104;
  const double _t108 = 0.12e2*_t13;
  const double _t111 = 0.20e2*_t48;
  const double _t112 = 0.24e2*_t13;
  const double _t113 = _t112*_t19*na;
  const double _t114 = xc_powi(_t1, -8);
  const double _t115 = (M_PI * M_PI);
  const double _t125 = xc_powi(_t1, -7);
  const double _t139 = _t20*nb;
  const double _t140 = _t37*_t58;
  const double _t141 = 0.8e1*na;
  const double _t142 = _t141*nb;
  const double _t143 = 0.6e1*_t13*_t18 - _t38*_t40 - _t38*_t57 - _t75;
  const double _t144 = _t104*nb;
  const double _t149 = _t75 + _t76;
  const double _t152 = 0.16e2*_t140;
  const double _t153 = _t152*nb;
  const double _t154 = -_t100*_t57 + _t102;
  const double _t158 = _t42*_t61;
  const double _t159 = 0.2e1*_t158;
  const double _t161 = (0.1e1 / 0.4e1)*_t15;
  const double _t165 = _t48*_t61;
  const double _t170 = xc_powr(_t1, -11, 3);
  const double _t175 = xc_powr(_t1, -8, 3);
  const double _t176 = (0.1e1 / 0.12e2)*_t8;
  const double _t177 = _t175*_t176;
  const double _t195 = (0.1e1 / 0.6e1)*_t175;
  const double _t211 = xc_powr(_t3, 3, 2);
  const double _t212 = (0.1e1 / _t211);
  const double _t213 = _t13*_t212;
  const double _t215 = xc_powr(_t1, -16, 3);
  const double _t216 = (0.1e1 / _t3);
  const double _t220 = _t216*_t42;
  const double _t228 = xc_powr(_t1, -5, 3);
  const double _t73 = _t32*_t52;
  const double _t74 = 0.2e1*_t73;
  const double _t80 = _hc1[5]*_t78 + _hc1[8]*_t79;
  const double _t81 = _hc1[6]*_t25 - _t80;
  const double _t82 = _hc1[4]*_t78 + _hc1[7]*_t79;
  const double _t83 = _hc1[5]*_t25 - _t82;
  const double _t84 = _hc1[7]*_t78 + _hc1[9]*_t79;
  const double _t85 = _hc1[8]*_t25 - _t84;
  const double _t86 = _hc1[1]*_t4;
  const double _t90 = _t29*_t89 + _t86*_t88;
  const double _t91 = _hc1[2]*_t77 + _t25*_t81 - _t78*_t83 - _t79*_t85 + _t90;
  const double _t92 = _t22*_t91;
  const double _t93 = 0.32e2*_t35*_t42;
  const double _t106 = _hc0[0]*_t34;
  const double _t107 = 0.8e1*_t106*_t50;
  const double _t109 = _t14*_t18;
  const double _t110 = _t108*_t109;
  const double _t116 = ((_hc0[1]) * (_hc0[1]));
  const double _t117 = _t115*_t116;
  const double _t118 = _t114*_t117;
  const double _t119 = _t118*_t3;
  const double _t120 = _hc0[2]*_t115;
  const double _t121 = _t114*_t120;
  const double _t122 = _hc0[0]*_t121;
  const double _t123 = _t122*_t3;
  const double _t124 = _hc0[1]*_t5;
  const double _t126 = _t125*_t47;
  const double _t127 = _t111*_t16 + _t113*nb + _t119*_t63 + _t123*_t63 + 0.10e2*_t124*_t126;
  const double _t128 = _t110 + _t127;
  const double _t129 = _t105*nb - _t107 + _t128 - _t93 - _t94*nb + _t96*nb - _t99*nb;
  const double _t130 = _hc1[0]*_t129;
  const double _t131 = _t32*_t59;
  const double _t132 = _t52*_t55;
  const double _t133 = _hc1[6]*_t54 - _t80;
  const double _t134 = _hc1[5]*_t54 - _t82;
  const double _t135 = _hc1[8]*_t54 - _t84;
  const double _t136 = -_t134*_t78 - _t135*_t79 + _t90;
  const double _t137 = _hc1[2]*_t76 + _t133*_t25 + _t136;
  const double _t138 = _t137*_t22;
  const double _t145 = _t104*_t41 - _t110 + _t127 + _t139*_t58 - _t140*_t142 - _t142*_t97 + _t143*_t144 + _t21 - _t45*nb - _t46;
  const double _t146 = _hc1[0]*_t145;
  const double _t147 = _t1*_t55;
  const double _t148 = 0.2e1*_t59;
  const double _t150 = _hc1[2]*_t149 + _t133*_t54 + _t136;
  const double _t151 = _t150*_t22;
  const double _t155 = _t107 + _t128 + _t144*_t154 - _t153*na + _t58*_t95*na + _t93 - _t94*na;
  const double _t156 = _hc1[0]*_t155;
  const double _t157 = _t106*_t65;
  const double _t160 = _t157*_t159;
  const double _t162 = _t117*_t125;
  const double _t163 = _hc0[0]*_t125;
  const double _t164 = _t161*_t163;
  const double _t166 = _t165*_t71;
  const double _t167 = _t120*_t164 + _t161*_t162 + (0.5e1 / 0.2e1)*_t166;
  const double _t168 = _t160 - _t167;
  const double _t169 = _hc1[0]*_t168;
  const double _t171 = _hc1[4]*_t170;
  const double _t172 = (0.2e1 / 0.3e1)*_t171;
  const double _t173 = _t27*_t61;
  const double _t174 = _hc1[7]*_t61;
  const double _t178 = _t172 + (0.2e1 / 0.3e1)*_t173 + _t174*_t177;
  const double _t179 = (0.1e1 / 0.2e1)*_hc1[5]*_t12*_t25*_t61 - _t178;
  const double _t180 = _t179*_t22;
  const double _t181 = _t10*_t68;
  const double _t182 = _t63*_t66;
  const double _t183 = _t182*_t62;
  const double _t184 = _t12*_t69;
  const double _t185 = _t158*_t67 + (0.1e1 / 0.2e1)*_t184;
  const double _t186 = _t1*_t169 + _t1*_t180 + _t181*_t52 + _t183*_t32 + _t185;
  const double _t187 = _t157*_t61;
  const double _t188 = _t187*_t43;
  const double _t189 = _t120*_t163;
  const double _t190 = _t162*_t63 + 0.5e1*_t166 + _t189*_t63;
  const double _t191 = _t188 - _t190;
  const double _t192 = _hc1[0]*_t191;
  const double _t193 = (0.4e1 / 0.3e1)*_t171;
  const double _t194 = _t174*_t8;
  const double _t196 = (0.4e1 / 0.3e1)*_t173 + _t193 + _t194*_t195;
  const double _t197 = _hc1[5]*_t12*_t25*_t61 - _t196;
  const double _t198 = _t197*_t22;
  const double _t199 = _t68*_t9;
  const double _t200 = _t62*_t71;
  const double _t201 = _t158*_t72 + _t184;
  const double _t202 = -_t160 - _t167;
  const double _t203 = _hc1[0]*_t202;
  const double _t204 = (0.1e1 / 0.2e1)*_hc1[5]*_t12*_t54*_t61 - _t178;
  const double _t205 = _t204*_t22;
  const double _t206 = _t1*_t203 + _t1*_t205 + _t181*_t59 + _t183*_t55 + _t185;
  const double _t207 = -_t188 - _t190;
  const double _t208 = _hc1[0]*_t207;
  const double _t209 = _hc1[5]*_t12*_t54*_t61 - _t196;
  const double _t210 = _t209*_t22;
  const double _t214 = _hc1[0]*_t161;
  const double _t217 = _hc1[1]*_t216;
  const double _t218 = _t182*_t217;
  const double _t219 = (0.1e1 / 0.8e1)*_hc1[0];
  const double _t221 = _t120*_t47;
  const double _t222 = _t220*_t221;
  const double _t223 = _t117*_t15;
  const double _t224 = _t220*_t223;
  const double _t225 = _t212*_t22;
  const double _t226 = _hc1[1]*_t9;
  const double _t227 = _t225*_t226;
  const double _t229 = _hc1[4]*_t216;
  const double _t230 = _t22*_t229;
  const double _t231 = _t228*_t230;
  const double _t232 = -_t213*_t214*_t66 + _t215*_t218 + _t219*_t222 + _t219*_t224 - 0.1e1 / 0.4e1*_t227 + (0.1e1 / 0.4e1)*_t231;
  const double _t233 = _t217*_t71;
  const double _t234 = _t215*_t233;
  const double _t235 = _hc0[0]*_t214;
  const double _t236 = _t120*_t220;
  const double _t237 = _t117*_t216;
  const double _t238 = _t237*_t42;
  const double _t239 = _hc1[1]*_t225;
  const double _t240 = -_t10*_t239 - _t213*_t67 + _t214*_t238 + (0.1e1 / 0.2e1)*_t231 + _t234 + _t235*_t236;
  const double _t241 = _hc0[0]*_t64;
  const double d2F_dna2 = _t1*_t130 + _t1*_t74 + _t1*_t92 + 0.2e1*_t33 + 0.2e1*_t53;
  const double d2F_dna_dnb = _t1*_t131 + _t1*_t132 + _t1*_t138 + _t1*_t146 + _t33 + _t53 + _t56 + _t60;
  const double d2F_dnb2 = _t1*_t151 + _t1*_t156 + _t147*_t148 + 0.2e1*_t56 + 0.2e1*_t60;
  const double d2F_dna_dgaa = _t186;
  const double d2F_dna_dgab = _t1*_t192 + _t1*_t198 + _t199*_t52 + _t200*_t32 + _t201;
  const double d2F_dna_dgbb = _t186;
  const double d2F_dnb_dgaa = _t206;
  const double d2F_dnb_dgab = _t1*_t208 + _t1*_t210 + _t199*_t59 + _t200*_t55 + _t201;
  const double d2F_dnb_dgbb = _t206;
  const double d2F_dgaa2 = _t232;
  const double d2F_dgaa_dgab = _t240;
  const double d2F_dgaa_dgbb = _t232;
  const double d2F_dgab2 = -_t213*_t72 - _t227 + _t231 + 0.2e1*_t234 + _t236*_t241 + _t238*_t64;
  const double d2F_dgab_dgbb = _t240;
  const double d2F_dgbb2 = _t232;
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
  const double _t248 = 0.48e2*_t97;
  const double _t249 = 0.24e2*_t42;
  const double _t250 = _t18*_t249;
  const double _t251 = _t250 + 0.12e2*_t37;
  const double _t252 = 0.18e2*_t13*_t40 - _t251;
  const double _t253 = _t37*nb;
  const double _t254 = _t103*_t253;
  const double _t255 = 0.24e2*_t254;
  const double _t257 = _t3*_t34;
  const double _t259 = 0.120e3*_t125;
  const double _t267 = _t18*_t48;
  const double _t270 = _t19*_t42;
  const double _t271 = _t270*nb;
  const double _t272 = 0.96e2*na;
  const double _t273 = _t271*_t272;
  const double _t274 = xc_powi(_t1, -9);
  const double _t276 = 0.9e1*_t3;
  const double _t283 = xc_powi(_t1, -10);
  const double _t284 = _t211*_t283;
  const double _t285 = (M_PI * M_PI * M_PI);
  const double _t299 = 0.6e1*_t37;
  const double _t300 = _t101*_t11;
  const double _t301 = _t299 - _t300;
  const double _t308 = _t4*_t88;
  const double _t309 = _t8*_t89;
  const double _t312 = 0.2e1*_t77;
  const double _t321 = (0.56e2 / 0.9e1)*_t87;
  const double _t327 = (0.4e1 / 0.9e1)*_t26;
  const double _t328 = xc_powr(_t1, -13, 3);
  const double _t329 = (0.280e3 / 0.27e2)*_t328;
  const double _t331 = (0.14e2 / 0.27e2)*_t87;
  const double _t336 = _t13*_t19;
  const double _t337 = _t143*_t253;
  const double _t338 = 0.16e2*_t337*na;
  const double _t339 = _t100 - _t250;
  const double _t340 = _t101*_t57 + _t108*_t40 + _t339;
  const double _t341 = _t58*nb;
  const double _t342 = _t341*na;
  const double _t343 = _t13*_t41;
  const double _t344 = _t343*nb;
  const double _t345 = 0.48e2*na;
  const double _t347 = _t108*_t57;
  const double _t354 = -_t300 + 0.2e1*_t37;
  const double _t374 = _t101*_t40 + _t339 + _t347;
  const double _t375 = _t154*_t253;
  const double _t386 = 0.48e2*_t140;
  const double _t387 = 0.18e2*_t13*_t57 - _t251;
  const double _t388 = 0.24e2*_t375;
  const double _t391 = -_t299 - _t300;
  const double _t393 = _t321*_t4;
  const double _t394 = _t327*_t8;
  const double _t402 = _t158*_t18;
  const double _t405 = 0.3e1*_t15;
  const double _t410 = _t274*_t4;
  const double _t411 = (0.3e1 / 0.8e1)*_t15;
  const double _t418 = (0.2e1 / 0.3e1)*_t170;
  const double _t421 = (0.2e1 / 0.3e1)*_t26;
  const double _t422 = _t177*_t61;
  const double _t426 = _t421*_t61;
  const double _t429 = _t12*_t61;
  const double _t434 = xc_powr(_t1, -14, 3);
  const double _t436 = (0.14e2 / 0.9e1)*_t87;
  const double _t460 = (0.4e1 / 0.3e1)*_t170;
  const double _t462 = (0.4e1 / 0.3e1)*_t26;
  const double _t463 = _t195*_t61*_t8;
  const double _t467 = _t462*_t61;
  const double _t508 = _t216*_t48;
  const double _t517 = _t15*_t216;
  const double _t519 = _t114*_t61;
  const double _t527 = _t12*_t212;
  const double _t530 = (0.1e1 / 0.3e1)*_t216;
  const double _t531 = (0.1e1 / 0.24e2)*_t8;
  const double _t532 = _t13*_t216;
  const double _t549 = xc_powr(_t1, -19, 3);
  const double _t577 = (0.1e1 / 0.6e1)*_t216;
  const double _t578 = _t13*_t577;
  const double _t610 = xc_powr(_t3, -5, 2);
  const double _t611 = (0.3e1 / 0.8e1)*_t610;
  const double _t614 = (_t3 * _t3);
  const double _t615 = (0.1e1 / _t614);
  const double _t616 = (0.3e1 / 0.4e1)*_t615;
  const double _t631 = (0.3e1 / 0.32e2)*_t15;
  const double _t641 = (0.3e1 / 0.4e1)*_t610;
  const double _t642 = (0.3e1 / 0.2e1)*_t615;
  const double _t645 = (0.3e1 / 0.8e1)*_t615;
  const double _t646 = _t42*_t645;
  const double _t656 = (0.3e1 / 0.2e1)*_t610;
  const double _t242 = _t1*_t32;
  const double _t243 = 0.3e1*_t242;
  const double _t244 = _t1*_t52;
  const double _t245 = 0.3e1*_t244;
  const double _t246 = _t35*_t48;
  const double _t247 = 0.240e3*_t246;
  const double _t256 = 0.6e1*_t118;
  const double _t258 = _t256*_t257;
  const double _t260 = _t106*_t124;
  const double _t261 = _t259*_t260;
  const double _t262 = 0.6e1*_t121;
  const double _t263 = _hc0[0]*_t257;
  const double _t264 = _t262*_t263;
  const double _t265 = _t109*_t42;
  const double _t266 = 0.36e2*_hc0[0];
  const double _t268 = _t124*_t267;
  const double _t269 = _t16*_t259;
  const double _t275 = _t223*_t274;
  const double _t277 = _t275*_t276;
  const double _t278 = _t274*_t47;
  const double _t279 = _t120*_t278;
  const double _t280 = _t276*_t279;
  const double _t281 = _t114*_t47;
  const double _t282 = 0.90e2*_t124*_t281;
  const double _t286 = _hc0[3]*_t285;
  const double _t287 = _hc0[0]*_t161;
  const double _t288 = _t286*_t287;
  const double _t289 = _t284*_t288;
  const double _t290 = _hc0[1]*_t15;
  const double _t291 = _hc0[2]*_t285;
  const double _t292 = _t290*_t291;
  const double _t293 = (0.3e1 / 0.4e1)*_t292;
  const double _t294 = _t284*_t293;
  const double _t295 = _t269 + _t273 + _t277 + _t280 + _t282 + _t289 + _t294;
  const double _t296 = 0.144e3*_t265 + _t266*_t268 + _t295;
  const double _t297 = 0.12e2*_t103*_t17*nb + 0.12e2*_t13*_t14*_t40 + 0.72e2*_t13*_t19*nb + 0.72e2*_t13*_t41*na*nb + 0.4e1*_t17*_t252*na*nb + _t247 - _t248*nb - _t255*na + _t258 + _t261 + _t264 - _t296;
  const double _t298 = _hc1[0]*_t297;
  const double _t302 = _hc1[12]*_t78 + _hc1[16]*_t79;
  const double _t303 = _hc1[13]*_t25 - _t302;
  const double _t304 = _hc1[11]*_t78 + _hc1[15]*_t79;
  const double _t305 = _hc1[12]*_t25 - _t304;
  const double _t306 = _hc1[15]*_t78 + _hc1[18]*_t79;
  const double _t307 = _hc1[16]*_t25 - _t306;
  const double _t310 = _hc1[5]*_t308 + _hc1[8]*_t309;
  const double _t311 = _hc1[6]*_t77 + _t25*_t303 - _t305*_t78 - _t307*_t79 + _t310;
  const double _t313 = _hc1[5]*_t77;
  const double _t314 = _hc1[10]*_t78 + _hc1[14]*_t79;
  const double _t315 = _hc1[11]*_t25 - _t314;
  const double _t316 = _hc1[14]*_t78 + _hc1[17]*_t79;
  const double _t317 = _hc1[15]*_t25 - _t316;
  const double _t318 = _hc1[4]*_t308 + _hc1[7]*_t309;
  const double _t319 = _t25*_t305 + _t313 - _t315*_t78 - _t317*_t79 + _t318;
  const double _t320 = _t4*_t83;
  const double _t322 = _hc1[17]*_t78 + _hc1[19]*_t79;
  const double _t323 = _hc1[18]*_t25 - _t322;
  const double _t324 = _hc1[7]*_t308 + _hc1[9]*_t309;
  const double _t325 = _hc1[8]*_t77 + _t25*_t307 - _t317*_t78 - _t323*_t79 + _t324;
  const double _t326 = _t8*_t85;
  const double _t330 = _t329*_t86;
  const double _t332 = _t29*_t331;
  const double _t333 = -_t330 - _t332;
  const double _t334 = _hc1[2]*_t301 + _t25*_t311 + _t312*_t81 - _t319*_t78 + _t320*_t321 - _t325*_t79 + _t326*_t327 + _t333;
  const double _t335 = _t22*_t334;
  const double _t346 = 0.12e2*_hc0[0];
  const double _t348 = _t14*_t347;
  const double _t349 = _t118*_t34;
  const double _t350 = _t163*_t34;
  const double _t351 = 0.2e1*_t122*_t257 + 0.40e2*_t124*_t350 + 0.80e2*_t246 + 0.2e1*_t3*_t349 + _t348;
  const double _t352 = _t104*_t340*nb + _t105 + _t112*_t342 + _t113 - _t141*_t254 + _t143*_t95*nb - _t153 + 0.48e2*_t265 + _t268*_t346 - _t269 - _t273 - _t277 - _t280 - _t282 - _t289 - _t294 + 0.48e2*_t336*nb - _t338 + _t344*_t345 + _t351 - _t94 + _t96 - _t98*nb - _t99;
  const double _t353 = _hc1[0]*_t1;
  const double _t355 = _hc1[13]*_t54 - _t302;
  const double _t356 = _hc1[12]*_t54 - _t304;
  const double _t357 = _hc1[16]*_t54 - _t306;
  const double _t358 = _t310 - _t356*_t78 - _t357*_t79;
  const double _t359 = _hc1[6]*_t76 + _t25*_t355 + _t358;
  const double _t360 = _hc1[11]*_t54 - _t314;
  const double _t361 = _hc1[15]*_t54 - _t316;
  const double _t362 = _t318 - _t360*_t78 - _t361*_t79;
  const double _t363 = _hc1[5]*_t76 + _t25*_t356 + _t362;
  const double _t364 = _hc1[18]*_t54 - _t322;
  const double _t365 = _t324 - _t361*_t78 - _t364*_t79;
  const double _t366 = _hc1[8]*_t76 + _t25*_t357 + _t365;
  const double _t367 = _hc1[2]*_t354 + _t133*_t77 + _t134*_t308 + _t135*_t309 + _t25*_t359 + _t308*_t83 + _t309*_t85 + _t333 - _t363*_t78 - _t366*_t79 + _t76*_t81;
  const double _t368 = _t1*_t22;
  const double _t369 = _t1*_t59;
  const double _t370 = 0.2e1*_t145;
  const double _t371 = 0.2e1*_t137;
  const double _t372 = 0.2e1*_t131 + 0.2e1*_t132 + 0.2e1*_t138 + 0.2e1*_t146;
  const double _t373 = _t55*_t59;
  const double _t376 = 0.12e2*M_PI*_hc0[0]*_hc0[1]*_t18*_t4*_t48 + 0.48e2*_t13*_t19*na + 0.24e2*_t13*_t19*nb + 0.24e2*_t13*_t41*na*nb + 0.48e2*_t13*_t58*na*nb + 0.48e2*_t14*_t18*_t42 - _t141*_t375 + 0.8e1*_t143*_t17*na - _t152*na - _t153 + 0.4e1*_t154*_t17*nb + 0.4e1*_t17*_t374*na*nb + 0.8e1*_t17*_t58 - _t295 - _t338 - _t351 - _t94 - _t99;
  const double _t377 = _hc1[8]*_t149 + _t357*_t54 + _t365;
  const double _t378 = _t377*_t79;
  const double _t379 = _hc1[5]*_t149;
  const double _t380 = _t356*_t54 + _t362 + _t379;
  const double _t381 = _t380*_t78;
  const double _t382 = _hc1[6]*_t149 + _t355*_t54 + _t358;
  const double _t383 = -_hc1[2]*_t300 - _hc1[2]*_t38 + 0.4e1*_t11*_t133*_t37 + (0.56e2 / 0.9e1)*_t134*_t4*_t87 + (0.4e1 / 0.9e1)*_t135*_t26*_t6*_t7 + _t25*_t382 - _t330 - _t332 - _t378 - _t381;
  const double _t384 = 0.3e1*_t147;
  const double _t385 = 0.3e1*_t369;
  const double _t389 = 0.72e2*_t13*_t19*na + 0.72e2*_t13*_t58*na*nb + 0.12e2*_t154*_t17*na + 0.4e1*_t17*_t387*na*nb - _t247 - _t258 - _t261 - _t264 - _t296 + _t348 - _t386*na - _t388*na;
  const double _t390 = _hc1[0]*_t389;
  const double _t392 = 0.2e1*_t133;
  const double _t395 = _hc1[2]*_t391 + _t134*_t393 + _t135*_t394 + _t149*_t392 + _t333 - _t378 - _t381 + _t382*_t54;
  const double _t396 = _t22*_t395;
  const double _t397 = _t162*_t34;
  const double _t398 = 0.2e1*_t397;
  const double _t399 = _t189*_t34;
  const double _t400 = 0.2e1*_t399;
  const double _t401 = _t111*_t187;
  const double _t403 = 0.6e1*_t66;
  const double _t404 = _t402*_t403;
  const double _t406 = _hc0[0]*_t405;
  const double _t407 = _t61*_t71;
  const double _t408 = _t125*_t407;
  const double _t409 = (0.1e1 / 0.8e1)*_t286;
  const double _t412 = _hc0[1]*_t291;
  const double _t413 = _t411*_t412;
  const double _t414 = _t118*_t405 + _t121*_t406 + _t278*_t4*_t409 + 0.15e2*_t408 + _t410*_t413;
  const double _t415 = _t404 + _t414;
  const double _t416 = -_t398 - _t400 - _t401 + _t415;
  const double _t417 = _hc1[0]*_t416;
  const double _t419 = _hc1[11]*_t418;
  const double _t420 = _hc1[5]*_t61;
  const double _t423 = _hc1[15]*_t422 + _t419 + _t420*_t421;
  const double _t424 = (0.1e1 / 0.2e1)*_hc1[12]*_t12*_t25*_t61 - _t423;
  const double _t425 = _hc1[10]*_t418;
  const double _t427 = _hc1[14]*_t422 + _hc1[4]*_t426 + _t425;
  const double _t428 = (0.1e1 / 0.2e1)*_hc1[11]*_t12*_t25*_t61 - _t427;
  const double _t430 = _t313*_t429;
  const double _t431 = _hc1[14]*_t418;
  const double _t432 = _hc1[17]*_t422 + _hc1[7]*_t426 + _t431;
  const double _t433 = (0.1e1 / 0.2e1)*_hc1[15]*_t12*_t25*_t61 - _t432;
  const double _t435 = _hc1[4]*_t434;
  const double _t437 = _t170*_t194;
  const double _t438 = (0.14e2 / 0.9e1)*_t435 + _t436*_t68 + (0.1e1 / 0.9e1)*_t437;
  const double _t439 = _t25*_t424 - _t426*_t83 - _t428*_t78 + (0.1e1 / 0.2e1)*_t430 - _t433*_t79 + _t438;
  const double _t440 = _t22*_t439;
  const double _t441 = 0.2e1*_t242;
  const double _t442 = 0.2e1*_t179;
  const double _t443 = _t12*_t68;
  const double _t444 = _t443*_t52;
  const double _t445 = _t158*_t71;
  const double _t446 = _t32*_t445 + _t444;
  const double _t447 = _t1*_t417 + _t1*_t440 + _t129*_t181 + _t168*_t441 + 0.2e1*_t169 + 0.2e1*_t180 + _t183*_t91 + _t244*_t442 + _t446;
  const double _t448 = 0.2e1*_t32;
  const double _t449 = 0.2e1*_t52;
  const double _t450 = 0.4e1*_t397;
  const double _t451 = 0.4e1*_t399;
  const double _t452 = 0.40e2*_t157*_t165;
  const double _t453 = _t346*_t65;
  const double _t454 = _t402*_t453;
  const double _t455 = _t15*_t256 + _t262*_t47 + _t288*_t410 + _t293*_t410 + 0.30e2*_t408;
  const double _t456 = _t454 + _t455;
  const double _t457 = -_t450 - _t451 - _t452 + _t456;
  const double _t458 = _hc1[0]*_t457;
  const double _t459 = 0.2e1*_t244;
  const double _t461 = _hc1[11]*_t460;
  const double _t464 = _hc1[15]*_t463 + _t420*_t462 + _t461;
  const double _t465 = _hc1[12]*_t12*_t25*_t61 - _t464;
  const double _t466 = _hc1[10]*_t460;
  const double _t468 = _hc1[14]*_t463 + _hc1[4]*_t467 + _t466;
  const double _t469 = _hc1[11]*_t12*_t25*_t61 - _t468;
  const double _t470 = _hc1[14]*_t460;
  const double _t471 = _hc1[17]*_t463 + _hc1[7]*_t467 + _t470;
  const double _t472 = _hc1[15]*_t12*_t25*_t61 - _t471;
  const double _t473 = (0.28e2 / 0.9e1)*_t435 + (0.2e1 / 0.9e1)*_t437 + _t68*_t88;
  const double _t474 = _t25*_t465 + _t430 - _t467*_t83 - _t469*_t78 - _t472*_t79 + _t473;
  const double _t475 = _t22*_t474;
  const double _t476 = _t158*_t182;
  const double _t477 = -_t404 + _t414;
  const double _t478 = _t443*_t59;
  const double _t479 = (0.1e1 / 0.2e1)*_hc1[12]*_t12*_t54*_t61 - _t423;
  const double _t480 = _t328*_t420;
  const double _t481 = _t11*_t480;
  const double _t482 = (0.1e1 / 0.2e1)*_hc1[11]*_t12*_t54*_t61 - _t427;
  const double _t483 = (0.1e1 / 0.2e1)*_hc1[15]*_t12*_t54*_t61 - _t432;
  const double _t484 = -_t134*_t426 + _t438 - _t482*_t78 - _t483*_t79;
  const double _t485 = _t25*_t479 + _t481 + _t484;
  const double _t486 = _t137*_t183 + _t145*_t181 + _t147*_t168 + _t169 + _t179*_t369 + _t180 + _t202*_t242 + _t203 + _t204*_t244 + _t205 + _t32*_t476 + _t353*_t477 + _t368*_t485 + (0.1e1 / 0.2e1)*_t444 + _t476*_t55 + (0.1e1 / 0.2e1)*_t478;
  const double _t487 = -_t454 + _t455;
  const double _t488 = _hc1[12]*_t12*_t54*_t61 - _t464;
  const double _t489 = _hc1[11]*_t12*_t54*_t61 - _t468;
  const double _t490 = _hc1[15]*_t12*_t54*_t61 - _t471;
  const double _t491 = -_t134*_t467 + _t473 - _t489*_t78 - _t490*_t79;
  const double _t492 = _t25*_t488 + 0.2e1*_t481 + _t491;
  const double _t493 = _t445*_t55 + _t478;
  const double _t494 = _t398 + _t400 + _t401 + _t415;
  const double _t495 = _hc1[0]*_t494;
  const double _t496 = _t379*_t429;
  const double _t497 = _t479*_t54 + _t484 + (0.1e1 / 0.2e1)*_t496;
  const double _t498 = _t22*_t497;
  const double _t499 = 0.2e1*_t147;
  const double _t500 = 0.2e1*_t369;
  const double _t501 = _t1*_t495 + _t1*_t498 + _t150*_t183 + _t155*_t181 + _t202*_t499 + 0.2e1*_t203 + _t204*_t500 + 0.2e1*_t205 + _t493;
  const double _t502 = 0.2e1*_t55;
  const double _t503 = _t450 + _t451 + _t452 + _t456;
  const double _t504 = _hc1[0]*_t503;
  const double _t505 = _t488*_t54 + _t491 + _t496;
  const double _t506 = _t22*_t505;
  const double _t507 = _t117*_t34;
  const double _t509 = _t507*_t508;
  const double _t510 = (0.1e1 / 0.2e1)*_t509;
  const double _t511 = _t212*_t65;
  const double _t512 = _t42*_t511;
  const double _t513 = _t106*_t512;
  const double _t514 = _t120*_t508;
  const double _t515 = _t106*_t514;
  const double _t516 = (0.1e1 / 0.2e1)*_t515;
  const double _t518 = _t162*_t517;
  const double _t520 = _t47*_t519;
  const double _t521 = (0.3e1 / 0.16e2)*_t292;
  const double _t522 = _t120*_t216;
  const double _t523 = _t126*_t522;
  const double _t524 = -0.5e1 / 0.4e1*M_PI*_hc0[0]*_hc0[1]*_t15*_t212*_t48 + (0.1e1 / 0.16e2)*_t286*_t520 + (0.5e1 / 0.8e1)*_t518 + _t519*_t521 + (0.5e1 / 0.8e1)*_t523;
  const double _t525 = _t510 - _t513 + _t516 - _t524;
  const double _t526 = _hc1[0]*_t525;
  const double _t528 = _hc1[5]*_t25*_t527;
  const double _t529 = (0.1e1 / 0.3e1)*_hc1[10];
  const double _t533 = _hc1[14]*_t532;
  const double _t534 = -0.1e1 / 0.3e1*_hc1[1]*_t212*_t26 - 0.1e1 / 0.24e2*_hc1[7]*_t175*_t212*_t6*_t7 + _t158*_t529 + _t171*_t530 + _t531*_t533;
  const double _t535 = (0.1e1 / 0.4e1)*_hc1[11]*_t175*_t216*_t25 - 0.1e1 / 0.4e1*_t528 - _t534;
  const double _t536 = _t22*_t535;
  const double _t537 = _t212*_t226;
  const double _t538 = _t52*_t537;
  const double _t539 = _t228*_t229;
  const double _t540 = _t52*_t539;
  const double _t541 = (0.1e1 / 0.8e1)*_t224;
  const double _t542 = _t213*_t32;
  const double _t543 = _t287*_t65;
  const double _t544 = (0.1e1 / 0.8e1)*_t222;
  const double _t545 = _t168*_t199 + _t179*_t200;
  const double _t546 = _t12*_t239;
  const double _t547 = _t175*_t230;
  const double _t548 = _t223*_t508;
  const double _t550 = _t47*_t514;
  const double _t551 = _t218*_t549 + _t219*_t548 + _t219*_t550 - _t235*_t512 - 0.1e1 / 0.4e1*_t546 + (0.1e1 / 0.4e1)*_t547;
  const double _t552 = _t1*_t526 + _t1*_t536 + _t32*_t541 + _t32*_t544 - 0.1e1 / 0.4e1*_t538 + (0.1e1 / 0.4e1)*_t540 - _t542*_t543 + _t545 + _t551;
  const double _t553 = 0.2e1*_t513;
  const double _t554 = -0.5e1 / 0.2e1*M_PI*_hc0[0]*_hc0[1]*_t15*_t212*_t48 + _t409*_t520 + _t413*_t519 + (0.5e1 / 0.4e1)*_t518 + (0.5e1 / 0.4e1)*_t523;
  const double _t555 = _t509 + _t515 - _t553 - _t554;
  const double _t556 = _hc1[0]*_t555;
  const double _t557 = _hc1[10]*_t158;
  const double _t558 = -0.2e1 / 0.3e1*_hc1[1]*_t212*_t26 - 0.1e1 / 0.12e2*_hc1[7]*_t175*_t212*_t6*_t7 + _t172*_t216 + _t176*_t533 + (0.2e1 / 0.3e1)*_t557;
  const double _t559 = (0.1e1 / 0.2e1)*_hc1[11]*_t175*_t216*_t25 - 0.1e1 / 0.2e1*_t528 - _t558;
  const double _t560 = _t22*_t559;
  const double _t561 = _hc1[1]*_t212;
  const double _t562 = _t10*_t561;
  const double _t563 = _t238*_t32;
  const double _t564 = _t236*_t32;
  const double _t565 = _t117*_t508;
  const double _t566 = _t233*_t549;
  const double _t567 = _t214*_t565 + _t235*_t514 - _t241*_t512 - 0.1e1 / 0.2e1*_t546 + (0.1e1 / 0.2e1)*_t547 + _t566;
  const double _t568 = _t1*_t556 + _t1*_t560 + _t161*_t563 + _t181*_t191 - _t182*_t542 + _t183*_t197 + _t287*_t564 - _t52*_t562 + (0.1e1 / 0.2e1)*_t540 + _t545 + _t567;
  const double _t569 = 0.2e1*_t509;
  const double _t570 = 0.2e1*_t515;
  const double _t571 = _t106*_t511;
  const double _t572 = _t43*_t571;
  const double _t573 = -0.5e1*M_PI*_hc0[0]*_hc0[1]*_t15*_t212*_t48 + _t288*_t519 + _t293*_t519 + (0.5e1 / 0.2e1)*_t518 + (0.5e1 / 0.2e1)*_t523;
  const double _t574 = _t569 + _t570 - _t572 - _t573;
  const double _t575 = _hc1[0]*_t574;
  const double _t576 = _hc1[14]*_t8;
  const double _t579 = -0.4e1 / 0.3e1*_hc1[1]*_t212*_t26 - 0.1e1 / 0.6e1*_hc1[7]*_t175*_t212*_t6*_t7 + _t193*_t216 + (0.4e1 / 0.3e1)*_t557 + _t576*_t578;
  const double _t580 = _hc1[11]*_t175*_t216*_t25 - _t528 - _t579;
  const double _t581 = _t22*_t580;
  const double _t582 = 0.2e1*_t199;
  const double _t583 = _hc0[0]*_t63;
  const double _t584 = _t213*_t71;
  const double _t585 = 0.2e1*_t200;
  const double _t586 = _t47*_t512;
  const double _t587 = -_hc1[0]*_t586 + _t241*_t514 - _t546 + _t547 + _t565*_t64 + 0.2e1*_t566;
  const double _t588 = -_t510 + _t513 - _t516 - _t524;
  const double _t589 = _hc1[0]*_t588;
  const double _t590 = _hc1[5]*_t527*_t54;
  const double _t591 = (0.1e1 / 0.4e1)*_hc1[11]*_t175*_t216*_t54 - _t534 - 0.1e1 / 0.4e1*_t590;
  const double _t592 = _t22*_t591;
  const double _t593 = _t537*_t59;
  const double _t594 = _t539*_t59;
  const double _t595 = _t213*_t55;
  const double _t596 = _t199*_t202 + _t200*_t204;
  const double _t597 = _t1*_t589 + _t1*_t592 + _t541*_t55 - _t543*_t595 + _t544*_t55 + _t551 - 0.1e1 / 0.4e1*_t593 + (0.1e1 / 0.4e1)*_t594 + _t596;
  const double _t598 = -_t509 - _t515 + _t553 - _t554;
  const double _t599 = _hc1[0]*_t598;
  const double _t600 = (0.1e1 / 0.2e1)*_hc1[11]*_t175*_t216*_t54 - _t558 - 0.1e1 / 0.2e1*_t590;
  const double _t601 = _t22*_t600;
  const double _t602 = _t238*_t55;
  const double _t603 = _t236*_t55;
  const double _t604 = _t1*_t599 + _t1*_t601 + _t161*_t602 + _t181*_t207 - _t182*_t595 + _t183*_t209 + _t287*_t603 - _t562*_t59 + _t567 + (0.1e1 / 0.2e1)*_t594 + _t596;
  const double _t605 = -_t569 - _t570 + _t572 - _t573;
  const double _t606 = _hc1[0]*_t605;
  const double _t607 = _hc1[11]*_t175*_t216*_t54 - _t579 - _t590;
  const double _t608 = _t22*_t607;
  const double _t609 = 0.2e1*_t209;
  const double _t612 = _t13*_t72;
  const double _t613 = _hc1[1]*_t215;
  const double _t617 = _t616*_t71;
  const double _t618 = _hc1[4]/xc_powr(_t1, 20, 3);
  const double _t619 = _t47*_t511;
  const double _t620 = (0.3e1 / 0.8e1)*_t619;
  const double _t621 = _hc1[0]*_t615;
  const double _t622 = _t42*_t621;
  const double _t623 = (0.3e1 / 0.16e2)*_t221;
  const double _t624 = _t549*_t561;
  const double _t625 = _t212*_t286;
  const double _t626 = _t48*_t625;
  const double _t627 = _t47*_t626;
  const double _t628 = (0.1e1 / 0.32e2)*_hc1[0];
  const double _t629 = _t212*_t49;
  const double _t630 = _t291*_t629;
  const double _t632 = _hc1[0]*_t631;
  const double _t633 = (0.3e1 / 0.16e2)*_t223;
  const double _t634 = _t22*_t226;
  const double _t635 = _hc1[10]*_t225;
  const double _t636 = _t37*_t635;
  const double _t637 = _t22*_t615;
  const double _t638 = _hc1[4]*_t637;
  const double _t639 = _t228*_t638;
  const double _t640 = _t611*_t612 + _t611*_t634 - _t613*_t617 + _t618*_t620 - _t622*_t623 - _t622*_t633 + _t623*_t624 + _t624*_t633 + _t627*_t628 + _t630*_t632 + (0.1e1 / 0.8e1)*_t636 - 0.3e1 / 0.8e1*_t639;
  const double _t643 = _t642*_t71;
  const double _t644 = _t618*_t619;
  const double _t647 = _hc1[0]*_t221;
  const double _t648 = _t221*_t624;
  const double _t649 = (0.1e1 / 0.16e2)*_hc1[0];
  const double _t650 = _hc1[0]*_t15;
  const double _t651 = _t630*_t650;
  const double _t652 = _hc1[0]*_t223;
  const double _t653 = _t223*_t624;
  const double _t654 = _t610*_t634;
  const double _t655 = _t612*_t641 - _t613*_t643 + _t627*_t649 + (0.1e1 / 0.4e1)*_t636 - 0.3e1 / 0.4e1*_t639 + (0.3e1 / 0.4e1)*_t644 - _t646*_t647 - _t646*_t652 + (0.3e1 / 0.8e1)*_t648 + (0.3e1 / 0.16e2)*_t651 + (0.3e1 / 0.8e1)*_t653 + (0.3e1 / 0.4e1)*_t654;
  const double _t657 = _t615*_t65;
  const double _t658 = _t406*_t657;
  const double _t659 = _t42*_t647;
  const double _t660 = _t411*_t630;
  const double _t661 = _t616*_t652;
  const double _t662 = _hc1[0]*_t660 + _t219*_t627 - _t42*_t661 + _t612*_t656 - _t613*_t658 - _t616*_t659 + (0.1e1 / 0.2e1)*_t636 - 0.3e1 / 0.2e1*_t639 + (0.3e1 / 0.2e1)*_t644 + (0.3e1 / 0.4e1)*_t648 + (0.3e1 / 0.4e1)*_t653 + (0.3e1 / 0.2e1)*_t654;
  const double _t663 = _t406*_t65;
  const double _t664 = _hc1[0]*_t610;
  const double _t665 = _t663*_t664;
  const double _t666 = _hc1[1]*_t615;
  const double _t667 = 0.6e1*_t71;
  const double _t668 = _t406*_t511;
  const double _t669 = (0.3e1 / 0.2e1)*_t221;
  const double _t670 = (0.3e1 / 0.2e1)*_t223;
  const double d3F_dna3 = _t1*_t298 + _t1*_t335 + _t129*_t243 + 0.3e1*_t130 + _t245*_t91 + 0.6e1*_t73 + 0.3e1*_t92;
  const double d3F_dna2_dnb = _t129*_t147 + _t130 + _t242*_t370 + _t244*_t371 + _t352*_t353 + _t367*_t368 + _t369*_t91 + _t372 + _t74 + _t92;
  const double d3F_dna_dnb2 = _t147*_t370 + _t150*_t244 + _t151 + _t155*_t242 + _t156 + _t353*_t376 + _t368*_t383 + _t369*_t371 + _t372 + 0.2e1*_t373;
  const double d3F_dnb3 = _t1*_t390 + _t1*_t396 + _t150*_t385 + 0.3e1*_t151 + _t155*_t384 + 0.3e1*_t156 + 0.6e1*_t373;
  const double d3F_dna2_dgaa = _t447;
  const double d3F_dna2_dgab = _t1*_t458 + _t1*_t475 + _t129*_t199 + _t191*_t441 + 0.2e1*_t192 + _t197*_t459 + 0.2e1*_t198 + _t200*_t91 + _t443*_t449 + _t445*_t448;
  const double d3F_dna2_dgbb = _t447;
  const double d3F_dna_dnb_dgaa = _t486;
  const double d3F_dna_dnb_dgab = _t137*_t200 + _t145*_t199 + _t147*_t191 + _t192 + _t197*_t369 + _t198 + _t207*_t242 + _t208 + _t209*_t244 + _t210 + _t353*_t487 + _t368*_t492 + _t446 + _t493;
  const double d3F_dna_dnb_dgbb = _t486;
  const double d3F_dnb2_dgaa = _t501;
  const double d3F_dnb2_dgab = _t1*_t504 + _t1*_t506 + _t148*_t443 + _t150*_t200 + _t155*_t199 + _t207*_t499 + 0.2e1*_t208 + _t209*_t500 + 0.2e1*_t210 + _t445*_t502;
  const double d3F_dnb2_dgbb = _t501;
  const double d3F_dna_dgaa2 = _t552;
  const double d3F_dna_dgaa_dgab = _t568;
  const double d3F_dna_dgaa_dgbb = _t552;
  const double d3F_dna_dgab2 = _t1*_t575 + _t1*_t581 + _t191*_t582 + _t197*_t585 - _t32*_t584 - _t538 + _t540 + _t563*_t63 + _t564*_t583 + _t587;
  const double d3F_dna_dgab_dgbb = _t568;
  const double d3F_dna_dgbb2 = _t552;
  const double d3F_dnb_dgaa2 = _t597;
  const double d3F_dnb_dgaa_dgab = _t604;
  const double d3F_dnb_dgaa_dgbb = _t597;
  const double d3F_dnb_dgab2 = _t1*_t606 + _t1*_t608 + _t200*_t609 + _t207*_t582 - _t55*_t584 + _t583*_t603 + _t587 - _t593 + _t594 + _t602*_t63;
  const double d3F_dnb_dgab_dgbb = _t604;
  const double d3F_dnb_dgbb2 = _t597;
  const double d3F_dgaa3 = _t640;
  const double d3F_dgaa2_dgab = _t655;
  const double d3F_dgaa2_dgbb = _t640;
  const double d3F_dgaa_dgab2 = _t662;
  const double d3F_dgaa_dgab_dgbb = _t655;
  const double d3F_dgaa_dgbb2 = _t640;
  const double d3F_dgab3 = _t13*_t665 - _t215*_t666*_t667 + _t235*_t626 + _t618*_t668 - _t622*_t669 - _t622*_t670 + _t636 - 0.3e1*_t639 + (0.3e1 / 0.2e1)*_t648 + (0.3e1 / 0.4e1)*_t651 + (0.3e1 / 0.2e1)*_t653 + 0.3e1*_t654;
  const double d3F_dgab2_dgbb = _t662;
  const double d3F_dgab_dgbb2 = _t655;
  const double d3F_dgbb3 = _t640;
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
  const double _t676 = _t40*_t42;
  const double _t678 = 0.16e2*_t17;
  const double _t679 = 0.288e3*nb;
  const double _t680 = _t41*na;
  const double _t681 = _t42*_t680*nb;
  const double _t682 = _t252*_t253;
  const double _t683 = 0.72e2*_t13;
  const double _t684 = 0.120e3*_t267 + _t683;
  const double _t685 = na*nb;
  const double _t686 = _t103*_t685;
  const double _t687 = 0.144e3*_t13;
  const double _t688 = 0.144e3*_t274;
  const double _t708 = 0.126e3*_t283*_t3;
  const double _t709 = xc_powi(_t1, -12);
  const double _t710 = _t614*_t709;
  const double _t711 = (M_PI * M_PI * M_PI * M_PI);
  const double _t715 = _t710*_t711;
  const double _t718 = xc_powi(_t1, -11);
  const double _t719 = _t211*_t718;
  const double _t726 = _t11*_t249;
  const double _t744 = _t329*_t4;
  const double _t746 = _t331*_t8;
  const double _t763 = (0.28e2 / 0.3e1)*_t4*_t87;
  const double _t769 = _t421*_t8;
  const double _t780 = _t37*na;
  const double _t781 = _t103*_t780;
  const double _t782 = 0.48e2*_t676;
  const double _t783 = _t270*na;
  const double _t784 = _t42*_t57;
  const double _t785 = -0.120e3*_t18*_t48;
  const double _t786 = _t340*na;
  const double _t787 = _t253*_t786;
  const double _t788 = _t42*_t679;
  const double _t790 = 0.72e2*_t274;
  const double _t809 = (0.28e2 / 0.27e2)*_t87;
  const double _t819 = _t143*_t780;
  const double _t820 = _t13*_t58;
  const double _t821 = _t342*_t42;
  const double _t822 = _t374*na;
  const double _t823 = _t253*_t822;
  const double _t824 = _t154*_t685;
  const double _t845 = 0.12e2*_t17;
  const double _t846 = _t154*_t780;
  const double _t847 = 0.96e2*_t784;
  const double _t848 = _t820*na;
  const double _t849 = _t387*na;
  const double _t850 = _t253*_t849;
  const double _t851 = _t683*_t685;
  const double _t852 = 0.2e1*_t149;
  const double _t874 = _t3*_t718;
  const double _t881 = _t711*_t874;
  const double _t885 = _t283*_t4;
  const double _t898 = (0.14e2 / 0.9e1)*_t434;
  const double _t899 = _t170*_t61;
  const double _t900 = (0.1e1 / 0.9e1)*_t899;
  const double _t901 = _t8*_t900;
  const double _t907 = _t436*_t61;
  const double _t912 = xc_powr(_t1, -17, 3);
  const double _t941 = (0.28e2 / 0.9e1)*_t434;
  const double _t942 = (0.2e1 / 0.9e1)*_t899;
  const double _t943 = _t8*_t942;
  const double _t948 = _t61*_t88;
  const double _t956 = _t61*_t784;
  const double _t961 = _t11*_t328;
  const double _t962 = _t61*_t961;
  const double _t1026 = _t283*_t711;
  const double _t1028 = (0.1e1 / 0.8e1)*_t1026;
  const double _t1040 = _t170*_t530;
  const double _t1041 = (0.1e1 / 0.3e1)*_t158;
  const double _t1042 = _t531*_t532;
  const double _t1079 = (0.2e1 / 0.3e1)*_t158;
  const double _t1080 = _t176*_t532;
  const double _t1104 = (0.4e1 / 0.3e1)*_t158;
  const double _t1105 = _t578*_t8;
  const double _t1108 = (0.8e1 / 0.3e1)*_t26*_t61;
  const double _t1156 = _t125*_t212;
  const double _t1161 = _t48*_t616;
  const double _t1167 = (0.1e1 / 0.16e2)*_t711;
  const double _t1168 = _t274*_t517;
  const double _t1170 = _t216*_t711;
  const double _t1173 = _t114*_t212;
  const double _t1178 = (0.3e1 / 0.8e1)*_t175;
  const double _t1209 = xc_powr(_t1, -22, 3);
  const double _t1219 = 0.3e1*_t610;
  const double _t1227 = (0.3e1 / 0.4e1)*_t175;
  const double _t1241 = _t48*_t645;
  const double _t1255 = _t1170*_t274;
  const double _t1257 = (0.3e1 / 0.2e1)*_t175;
  const double _t1270 = 0.3e1*_t175;
  const double _t1305 = xc_powr(_t3, -7, 2);
  const double _t1307 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t1308 = (0.15e2 / 0.8e1)*_t1307;
  const double _t1316 = (0.1e1 / 0.16e2)*_t615;
  const double _t1332 = (0.15e2 / 0.16e2)*_t1307;
  const double _t1339 = _t125*_t711;
  const double _t671 = _t129*_t32;
  const double _t672 = _t52*_t91;
  const double _t673 = _t1*_t91;
  const double _t674 = _t125*_t35;
  const double _t675 = 0.1920e4*_t674;
  const double _t677 = 0.192e3*_t14;
  const double _t689 = _t3*_t507;
  const double _t690 = _t688*_t689;
  const double _t691 = _t114*_t260;
  const double _t692 = 0.1440e4*_t691;
  const double _t693 = _t120*_t263;
  const double _t694 = _t688*_t693;
  const double _t695 = _t40*_t50;
  const double _t696 = 0.48e2*_hc0[0];
  const double _t697 = _t34*_t412;
  const double _t698 = _t284*_t697;
  const double _t699 = 0.12e2*_t698;
  const double _t700 = _t106*_t286;
  const double _t701 = _t284*_t700;
  const double _t702 = 0.4e1*_t701;
  const double _t703 = _t14*_t267;
  const double _t704 = _t119*_t18;
  const double _t705 = _t123*_t18;
  const double _t706 = _t124*_t163*_t18;
  const double _t707 = _t112*_t14;
  const double _t712 = ((_hc0[2]) * (_hc0[2]));
  const double _t713 = _t711*_t712;
  const double _t714 = _t411*_t713;
  const double _t716 = _hc0[1]*_hc0[3];
  const double _t717 = _t63*_t716;
  const double _t720 = _t286*_t47;
  const double _t721 = _hc0[4]*_t47;
  const double _t722 = (0.1e1 / 0.8e1)*_t721;
  const double _t723 = 0.840e3*_t114*_t16 + 0.840e3*_t124*_t278 + 0.480e3*_t19*_t48*_t685 + _t221*_t708 + _t223*_t708 + 0.21e2*_t292*_t719 + _t710*_t714 + _t715*_t717 + _t715*_t722 + 0.7e1*_t719*_t720;
  const double _t724 = _t707 + _t723;
  const double _t725 = 0.1440e4*_t703 + 0.36e2*_t704 + 0.36e2*_t705 + 0.720e3*_t706 + _t724;
  const double _t727 = _hc1[23]*_t78 + _hc1[28]*_t79;
  const double _t728 = _hc1[22]*_t78 + _hc1[27]*_t79;
  const double _t729 = _hc1[23]*_t25 - _t728;
  const double _t730 = _hc1[27]*_t78 + _hc1[31]*_t79;
  const double _t731 = _hc1[28]*_t25 - _t730;
  const double _t732 = _hc1[12]*_t308 + _hc1[16]*_t309;
  const double _t733 = _hc1[12]*_t77;
  const double _t734 = _hc1[21]*_t78 + _hc1[26]*_t79;
  const double _t735 = _hc1[22]*_t25 - _t734;
  const double _t736 = _hc1[26]*_t78 + _hc1[30]*_t79;
  const double _t737 = _hc1[27]*_t25 - _t736;
  const double _t738 = _hc1[11]*_t308 + _hc1[15]*_t309;
  const double _t739 = _t25*_t729 + _t733 - _t735*_t78 - _t737*_t79 + _t738;
  const double _t740 = _hc1[30]*_t78 + _hc1[33]*_t79;
  const double _t741 = _hc1[31]*_t25 - _t740;
  const double _t742 = _hc1[15]*_t308 + _hc1[18]*_t309;
  const double _t743 = _hc1[16]*_t77 + _t25*_t731 - _t737*_t78 - _t741*_t79 + _t742;
  const double _t745 = _hc1[5]*_t744;
  const double _t747 = _hc1[8]*_t746;
  const double _t748 = -_t745 - _t747;
  const double _t749 = _t320*_t328;
  const double _t750 = _hc1[11]*_t77;
  const double _t751 = _hc1[20]*_t78 + _hc1[25]*_t79;
  const double _t752 = _hc1[25]*_t78 + _hc1[29]*_t79;
  const double _t753 = _hc1[26]*_t25 - _t752;
  const double _t754 = _hc1[10]*_t308 + _hc1[14]*_t309;
  const double _t755 = _hc1[15]*_t77;
  const double _t756 = _hc1[29]*_t78 + _hc1[32]*_t79;
  const double _t757 = _hc1[30]*_t25 - _t756;
  const double _t758 = _hc1[14]*_t308 + _hc1[17]*_t309;
  const double _t759 = _t25*_t737 - _t753*_t78 + _t755 - _t757*_t79 + _t758;
  const double _t760 = _hc1[4]*_t744;
  const double _t761 = _hc1[7]*_t746;
  const double _t762 = -_t760 - _t761;
  const double _t764 = _hc1[32]*_t78 + _hc1[34]*_t79;
  const double _t765 = _hc1[17]*_t308 + _hc1[19]*_t309;
  const double _t766 = _hc1[7]*_t744;
  const double _t767 = _hc1[9]*_t746;
  const double _t768 = -_t766 - _t767;
  const double _t770 = (0.3640e4 / 0.81e2)*_t215*_t86 + (0.140e3 / 0.81e2)*_t29*_t328;
  const double _t771 = _t129*_t55;
  const double _t772 = _t137*_t52;
  const double _t773 = _t59*_t91;
  const double _t774 = _t145*_t32;
  const double _t775 = _t1*_t129;
  const double _t776 = 0.3e1*_t137;
  const double _t777 = 0.3e1*_t145;
  const double _t778 = _hc1[0]*_t352;
  const double _t779 = _t22*_t367;
  const double _t789 = _t50*_t57;
  const double _t791 = 0.960e3*_t674 + _t689*_t790 + 0.720e3*_t691 + _t693*_t790 + 0.6e1*_t698 + 0.2e1*_t701;
  const double _t792 = _hc1[24]*_t54 - _t727;
  const double _t793 = _hc1[23]*_t54 - _t728;
  const double _t794 = _hc1[28]*_t54 - _t730;
  const double _t795 = _t732 - _t78*_t793 - _t79*_t794;
  const double _t796 = _hc1[22]*_t54 - _t734;
  const double _t797 = _hc1[27]*_t54 - _t736;
  const double _t798 = _t738 - _t78*_t796 - _t79*_t797;
  const double _t799 = _hc1[12]*_t76 + _t25*_t793 + _t798;
  const double _t800 = _hc1[31]*_t54 - _t740;
  const double _t801 = _t742 - _t78*_t797 - _t79*_t800;
  const double _t802 = _hc1[16]*_t76 + _t25*_t794 + _t801;
  const double _t803 = _hc1[5]*_t354;
  const double _t804 = _hc1[26]*_t54 - _t752;
  const double _t805 = _t754 - _t78*(_hc1[21]*_t54 - _t751) - _t79*_t804;
  const double _t806 = _hc1[30]*_t54 - _t756;
  const double _t807 = _t758 - _t78*_t804 - _t79*_t806;
  const double _t808 = _hc1[15]*_t76 + _t25*_t797 + _t807;
  const double _t810 = _t765 - _t78*_t806 - _t79*(_hc1[33]*_t54 - _t764);
  const double _t811 = _t363*_t393 + _t366*_t394 + _t770;
  const double _t812 = _t155*_t32;
  const double _t813 = _t137*_t59;
  const double _t814 = _t150*_t52;
  const double _t815 = _t145*_t55;
  const double _t816 = _t1*_t145;
  const double _t817 = _hc1[0]*_t376;
  const double _t818 = _t22*_t383;
  const double _t825 = _hc1[2]*_t726;
  const double _t826 = _hc1[16]*_t149 + _t54*_t794 + _t801;
  const double _t827 = _t79*_t826;
  const double _t828 = _hc1[12]*_t149;
  const double _t829 = _t54*_t793 + _t798 + _t828;
  const double _t830 = _t78*_t829;
  const double _t831 = _hc1[13]*_t149 + _t54*_t792 + _t795;
  const double _t832 = _t134*_t328*_t4;
  const double _t833 = _hc1[15]*_t149;
  const double _t834 = _t54*_t797 + _t807 + _t833;
  const double _t835 = _t79*_t834;
  const double _t836 = _hc1[11]*_t149;
  const double _t837 = _t78*(_t54*_t796 + _t805 + _t836);
  const double _t838 = _t135*_t8;
  const double _t839 = _t79*(_hc1[18]*_t149 + _t54*_t800 + _t810);
  const double _t840 = _t78*_t834;
  const double _t841 = _t155*_t55;
  const double _t842 = _t150*_t59;
  const double _t843 = _t1*_t155;
  const double _t844 = _t1*_t150;
  const double _t853 = _hc1[6]*_t391 + _t355*_t852 + _t356*_t393 + _t357*_t394 + _t54*_t831 + _t748 - _t827 - _t830;
  const double _t854 = _t377*_t769 + _t380*_t763 - _t436*_t838 + _t770 - _t78*(_hc1[5]*_t391 + _t356*_t852 + _t360*_t393 + _t361*_t394 + _t54*_t829 + _t762 - _t835 - _t837) - _t79*(_hc1[8]*_t391 + _t357*_t852 + _t361*_t393 + _t364*_t394 + _t54*_t826 + _t768 - _t839 - _t840) - 0.280e3 / 0.9e1*_t832;
  const double _t855 = 0.6e1*_t32;
  const double _t856 = 0.6e1*_t52;
  const double _t857 = _t445*_t91;
  const double _t858 = _t129*_t443;
  const double _t859 = 0.3e1*_t673;
  const double _t860 = 0.3e1*_t775;
  const double _t861 = 0.36e2*_t349;
  const double _t862 = _t106*_t121;
  const double _t863 = 0.36e2*_t862;
  const double _t864 = _t350*_t61*_t65;
  const double _t865 = 0.180e3*_t864;
  const double _t866 = _t410*_t697;
  const double _t867 = (0.9e1 / 0.2e1)*_t866;
  const double _t868 = _t410*_t700;
  const double _t869 = (0.3e1 / 0.2e1)*_t868;
  const double _t870 = _t162*_t18;
  const double _t871 = _t18*_t189;
  const double _t872 = _t267*_t61*_t66;
  const double _t873 = (0.63e2 / 0.2e1)*_t275;
  const double _t875 = (0.3e1 / 0.16e2)*_t713;
  const double _t876 = _t15*_t875;
  const double _t877 = _t874*_t876;
  const double _t878 = (0.63e2 / 0.2e1)*_t279;
  const double _t879 = _t519*_t71;
  const double _t880 = 0.105e3*_t879;
  const double _t882 = _t161*_t716;
  const double _t883 = _t881*_t882;
  const double _t884 = (0.1e1 / 0.16e2)*_t721*_t881;
  const double _t886 = _t720*_t885;
  const double _t887 = (0.21e2 / 0.8e1)*_t886;
  const double _t888 = _t292*_t885;
  const double _t889 = (0.63e2 / 0.8e1)*_t888;
  const double _t890 = _t873 + _t877 + _t878 + _t880 + _t883 + _t884 + _t887 + _t889;
  const double _t891 = 0.9e1*_t870 + 0.9e1*_t871 + 0.90e2*_t872 + _t890;
  const double _t892 = _hc1[12]*_t426 + _hc1[22]*_t418 + _hc1[27]*_t422;
  const double _t893 = _hc1[11]*_t426 + _hc1[21]*_t418 + _hc1[26]*_t422;
  const double _t894 = (0.1e1 / 0.2e1)*_hc1[22]*_t12*_t25*_t61 - _t893;
  const double _t895 = _t429*_t733;
  const double _t896 = _hc1[15]*_t426 + _hc1[26]*_t418 + _hc1[30]*_t422;
  const double _t897 = (0.1e1 / 0.2e1)*_hc1[27]*_t12*_t25*_t61 - _t896;
  const double _t902 = _hc1[11]*_t898 + _hc1[15]*_t901 + _t420*_t436;
  const double _t903 = _hc1[10]*_t426 + _hc1[20]*_t418 + _hc1[25]*_t422;
  const double _t904 = _t429*_t750;
  const double _t905 = _hc1[14]*_t426 + _hc1[25]*_t418 + _hc1[29]*_t422;
  const double _t906 = (0.1e1 / 0.2e1)*_hc1[26]*_t12*_t25*_t61 - _t905;
  const double _t908 = _hc1[10]*_t898 + _hc1[4]*_t907 + _t576*_t900;
  const double _t909 = _t429*_t755;
  const double _t910 = _hc1[17]*_t426 + _hc1[29]*_t418 + _hc1[32]*_t422;
  const double _t911 = _hc1[14]*_t898 + _hc1[17]*_t901 + _hc1[7]*_t907;
  const double _t913 = _hc1[4]*_t912;
  const double _t914 = (0.140e3 / 0.27e2)*_t913;
  const double _t915 = (0.140e3 / 0.27e2)*_t328*_t68;
  const double _t916 = _t194*_t434;
  const double _t917 = (0.7e1 / 0.27e2)*_t916;
  const double _t918 = _t914 + _t915 + _t917;
  const double _t919 = _t168*_t855 + _t168*_t859 + _t179*_t856 + _t179*_t860 + _t181*_t297 + _t183*_t334 + _t243*_t416 + _t245*_t439 + _t353*(0.6e1*M_PI*_hc0[0]*_hc0[1]*_t40*_t42*_t61 + _t861 + _t863 + _t865 + _t867 + _t869 - _t891) + _t368*((0.1e1 / 0.2e1)*_hc1[5]*_t12*_t301*_t61 + _t25*(_t25*((0.1e1 / 0.2e1)*_hc1[23]*_t12*_t25*_t61 - _t892) - _t305*_t426 - _t78*_t894 - _t79*_t897 + (0.1e1 / 0.2e1)*_t895 + _t902) + (0.4e1 / 0.9e1)*_t26*_t433*_t6*_t7 - _t319*_t426 + (0.56e2 / 0.9e1)*_t4*_t428*_t87 + 0.2e1*_t424*_t77 + (0.28e2 / 0.9e1)*_t61*_t83*_t87 - _t78*(_t25*_t894 - _t315*_t426 - _t78*((0.1e1 / 0.2e1)*_hc1[21]*_t12*_t25*_t61 - _t903) - _t79*_t906 + (0.1e1 / 0.2e1)*_t904 + _t908) - _t79*(_t25*_t897 - _t317*_t426 - _t78*_t906 - _t79*((0.1e1 / 0.2e1)*_hc1[30]*_t12*_t25*_t61 - _t910) + (0.1e1 / 0.2e1)*_t909 + _t911) - _t918) + 0.3e1*_t417 + 0.3e1*_t440 + (0.3e1 / 0.2e1)*_t857 + (0.3e1 / 0.2e1)*_t858;
  const double _t920 = _t158*_t663;
  const double _t921 = 0.72e2*_t349;
  const double _t922 = 0.72e2*_t862;
  const double _t923 = 0.360e3*_t864;
  const double _t924 = 0.9e1*_t866;
  const double _t925 = 0.3e1*_t868;
  const double _t926 = 0.63e2*_t275;
  const double _t927 = 0.63e2*_t279;
  const double _t928 = _t714*_t874;
  const double _t929 = _t717*_t881;
  const double _t930 = 0.210e3*_t879;
  const double _t931 = _t722*_t881;
  const double _t932 = (0.21e2 / 0.4e1)*_t886;
  const double _t933 = (0.63e2 / 0.4e1)*_t888;
  const double _t934 = _t926 + _t927 + _t928 + _t929 + _t930 + _t931 + _t932 + _t933;
  const double _t935 = 0.18e2*_t870 + 0.18e2*_t871 + 0.180e3*_t872 + _t934;
  const double _t936 = _hc1[12]*_t467 + _hc1[22]*_t460 + _hc1[27]*_t463;
  const double _t937 = _hc1[11]*_t467 + _hc1[21]*_t460 + _hc1[26]*_t463;
  const double _t938 = _hc1[22]*_t12*_t25*_t61 - _t937;
  const double _t939 = _hc1[15]*_t467 + _hc1[26]*_t460 + _hc1[30]*_t463;
  const double _t940 = _hc1[27]*_t12*_t25*_t61 - _t939;
  const double _t944 = _hc1[11]*_t941 + _hc1[15]*_t943 + _t420*_t88;
  const double _t945 = _hc1[10]*_t467 + _hc1[20]*_t460 + _hc1[25]*_t463;
  const double _t946 = _hc1[14]*_t467 + _hc1[25]*_t460 + _hc1[29]*_t463;
  const double _t947 = _hc1[26]*_t12*_t25*_t61 - _t946;
  const double _t949 = _hc1[10]*_t941 + _hc1[4]*_t948 + _t576*_t942;
  const double _t950 = _hc1[17]*_t467 + _hc1[29]*_t460 + _hc1[32]*_t463;
  const double _t951 = _hc1[14]*_t941 + _hc1[17]*_t943 + _hc1[7]*_t948;
  const double _t952 = (0.280e3 / 0.27e2)*_t913;
  const double _t953 = _t329*_t68;
  const double _t954 = (0.14e2 / 0.27e2)*_t916;
  const double _t955 = _t952 + _t953 + _t954;
  const double _t957 = _t403*_t956;
  const double _t958 = 0.12e2*_t349 + 0.12e2*_t862 + 0.60e2*_t864 + (0.3e1 / 0.2e1)*_t866 + (0.1e1 / 0.2e1)*_t868 + _t957;
  const double _t959 = _t429*_t803;
  const double _t960 = (0.1e1 / 0.2e1)*_hc1[27]*_t12*_t54*_t61 - _t896;
  const double _t963 = _hc1[15]*_t962;
  const double _t964 = (0.1e1 / 0.2e1)*_hc1[26]*_t12*_t54*_t61 - _t905;
  const double _t965 = -_t361*_t426 - _t78*_t964 - _t79*((0.1e1 / 0.2e1)*_hc1[30]*_t12*_t54*_t61 - _t910) + _t911;
  const double _t966 = (0.1e1 / 0.2e1)*_hc1[22]*_t12*_t54*_t61 - _t893;
  const double _t967 = _hc1[11]*_t962;
  const double _t968 = -_t360*_t426 - _t78*((0.1e1 / 0.2e1)*_hc1[21]*_t12*_t54*_t61 - _t903) - _t79*_t964 + _t908;
  const double _t969 = (0.1e1 / 0.2e1)*_hc1[23]*_t12*_t54*_t61 - _t892;
  const double _t970 = _hc1[12]*_t962;
  const double _t971 = -_t356*_t426 - _t78*_t966 - _t79*_t960 + _t902;
  const double _t972 = _t1*_t168;
  const double _t973 = 0.2e1*_hc1[0];
  const double _t974 = 0.2e1*_t22;
  const double _t975 = _t137*_t445 + _t145*_t443 + _t168*_t502 + _t202*_t448 + _t204*_t449 + _t442*_t59 + _t477*_t973 + _t485*_t974;
  const double _t976 = _t147*_t416 + _t168*_t448 + _t181*_t352 + _t183*_t367 + _t202*_t673 + _t204*_t775 + _t353*(0.3e1*_t870 + 0.3e1*_t871 + 0.30e2*_t872 - _t873 - _t877 - _t878 - _t880 - _t883 - _t884 - _t887 - _t889 + _t958) + _t368*(_t134*_t907 + _t25*(_t25*_t969 + _t970 + _t971) + _t308*_t428 + _t308*_t482 + _t309*_t433 + _t309*_t483 - _t363*_t426 + _t424*_t76 + _t479*_t77 - _t78*(_t25*_t966 + _t967 + _t968) - _t79*(_t25*_t960 + _t963 + _t965) + _t83*_t907 - _t914 - _t915 - _t917 + (0.1e1 / 0.2e1)*_t959) + _t369*_t439 + _t371*_t972 + _t417 + _t440 + _t441*_t477 + _t442*_t52 + _t442*_t816 + _t459*_t485 + _t476*_t91 + (0.1e1 / 0.2e1)*_t858 + _t975;
  const double _t977 = _t453*_t956;
  const double _t978 = _t187*_t259 + 0.24e2*_t349 + 0.24e2*_t862 + 0.3e1*_t866 + _t868 + _t977;
  const double _t979 = _hc1[27]*_t12*_t54*_t61 - _t939;
  const double _t980 = _hc1[26]*_t12*_t54*_t61 - _t946;
  const double _t981 = -_t361*_t467 - _t78*_t980 - _t79*(_hc1[30]*_t12*_t54*_t61 - _t950) + _t951;
  const double _t982 = _hc1[22]*_t12*_t54*_t61 - _t937;
  const double _t983 = -_t360*_t467 - _t78*(_hc1[21]*_t12*_t54*_t61 - _t945) - _t79*_t980 + _t949;
  const double _t984 = _hc1[23]*_t12*_t54*_t61 - _t936;
  const double _t985 = -_t356*_t467 - _t78*_t982 - _t79*_t979 + _t944;
  const double _t986 = _t1*_t197;
  const double _t987 = _t1*_t191;
  const double _t988 = _t148*_t197 + _t191*_t502 + _t207*_t448 + _t209*_t449 + _t370*_t443 + _t371*_t445 + _t487*_t973 + _t492*_t974;
  const double _t989 = _t429*_t828;
  const double _t990 = _t54*_t969 + _t971 + (0.1e1 / 0.2e1)*_t989;
  const double _t991 = _t11*_t215*_t420;
  const double _t992 = _t429*_t836;
  const double _t993 = _t429*_t833;
  const double _t994 = -0.28e2 / 0.9e1*_t134*_t61*_t87 - 0.4e1 / 0.9e1*_t26*_t483*_t6*_t7 + _t380*_t426 - 0.56e2 / 0.9e1*_t4*_t482*_t87 + _t78*(_t54*_t966 + _t968 + (0.1e1 / 0.2e1)*_t992) + _t79*(_t54*_t960 + _t965 + (0.1e1 / 0.2e1)*_t993) + _t918;
  const double _t995 = _t1*_t370;
  const double _t996 = _t1*_t202;
  const double _t997 = _t155*_t443;
  const double _t998 = _t148*_t204 + _t150*_t476 + _t168*_t844 + _t179*_t843 + _t181*_t376 + _t183*_t383 + _t202*_t502 + _t204*_t995 + _t242*_t494 + _t244*_t497 + _t353*(0.30e2*M_PI*_hc0[0]*_hc0[1]*_t18*_t48*_t61 + 0.3e1*_hc0[0]*_hc0[2]*_t115*_t125*_t18 + 0.3e1*_t115*_t116*_t125*_t18 - _t890 - _t958) + _t368*(0.4e1*_t11*_t37*_t479 + _t25*_t990 - _t480 - 0.3e1*_t991 - _t994) + _t371*_t996 + _t477*_t499 + _t485*_t500 + _t495 + _t498 + _t975 + (0.1e1 / 0.2e1)*_t997;
  const double _t999 = _t54*_t984 + _t985 + _t989;
  const double _t1000 = -0.56e2 / 0.9e1*_t134*_t61*_t87 - 0.4e1 / 0.9e1*_t26*_t490*_t6*_t7 + _t380*_t467 - 0.56e2 / 0.9e1*_t4*_t489*_t87 + _t78*(_t54*_t982 + _t983 + _t992) + _t79*(_t54*_t979 + _t981 + _t993) + _t955;
  const double _t1001 = _t1*_t207;
  const double _t1002 = _t150*_t445;
  const double _t1003 = 0.6e1*_t55;
  const double _t1004 = 0.6e1*_t59;
  const double _t1005 = 0.3e1*_t844;
  const double _t1006 = 0.3e1*_t843;
  const double _t1007 = (0.3e1 / 0.2e1)*_t1002 + _t1003*_t202 + _t1004*_t204 + _t1005*_t202 + _t1006*_t204 + _t181*_t389 + _t183*_t395 + _t353*(-_t861 - _t863 - _t865 - _t867 - _t869 - _t891 + _t957) + _t368*((0.1e1 / 0.2e1)*_hc1[5]*_t12*_t391*_t61 + 0.2e1*_t149*_t479 + _t54*_t990 - _t994) + _t384*_t494 + _t385*_t497 + 0.3e1*_t495 + 0.3e1*_t498 + (0.3e1 / 0.2e1)*_t997;
  const double _t1008 = _t216*_t397;
  const double _t1009 = 0.5e1*_t1008;
  const double _t1010 = _t216*_t399;
  const double _t1011 = 0.5e1*_t1010;
  const double _t1012 = M_PI*_t106*_t629;
  const double _t1013 = 0.10e2*_t1012;
  const double _t1014 = _t519*_t697;
  const double _t1015 = (0.3e1 / 0.2e1)*_t1014;
  const double _t1016 = _t519*_t700;
  const double _t1017 = (0.1e1 / 0.2e1)*_t1016;
  const double _t1018 = _t237*_t267;
  const double _t1019 = (0.3e1 / 0.2e1)*_t1018;
  const double _t1020 = 0.3e1*_hc0[0];
  const double _t1021 = _t18*_t512;
  const double _t1022 = _t1020*_t1021;
  const double _t1023 = _t267*_t522;
  const double _t1024 = _hc0[0]*_t1023;
  const double _t1025 = (0.3e1 / 0.2e1)*_t1024;
  const double _t1027 = _t1026*_t712;
  const double _t1029 = _hc0[3]*_t290;
  const double _t1030 = _t1026*_t721;
  const double _t1031 = _t118*_t517;
  const double _t1032 = _t126*_t511;
  const double _t1033 = _t278*_t286*_t61;
  const double _t1034 = (0.15e2 / 0.4e1)*_t47;
  const double _t1035 = _t121*_t216;
  const double _t1036 = _t274*_t292*_t61;
  const double _t1037 = _t1027*_t631 + _t1028*_t1029 + (0.1e1 / 0.32e2)*_t1030 + (0.15e2 / 0.4e1)*_t1031 - 0.15e2 / 0.2e1*_t1032 + (0.13e2 / 0.16e2)*_t1033 + _t1034*_t1035 + (0.39e2 / 0.16e2)*_t1036;
  const double _t1038 = _t1019 - _t1022 + _t1025 + _t1037;
  const double _t1039 = _hc1[12]*_t25*_t527;
  const double _t1043 = _hc1[11]*_t1040 - 0.1e1 / 0.24e2*_hc1[15]*_t175*_t212*_t6*_t7 + _hc1[21]*_t1041 + _hc1[26]*_t1042 - 0.1e1 / 0.3e1*_hc1[5]*_t212*_t26;
  const double _t1044 = _hc1[11]*_t25;
  const double _t1045 = _t1044*_t527;
  const double _t1046 = -0.1e1 / 0.24e2*_hc1[14]*_t175*_t212*_t6*_t7 + _hc1[20]*_t1041 + _hc1[25]*_t1042 - 0.1e1 / 0.3e1*_hc1[4]*_t212*_t26 + _t170*_t216*_t529;
  const double _t1047 = _t428*_t467;
  const double _t1048 = _t313*_t527;
  const double _t1049 = _hc1[15]*_t25*_t527;
  const double _t1050 = _hc1[14]*_t1040 - 0.1e1 / 0.24e2*_hc1[17]*_t175*_t212*_t6*_t7 + _hc1[25]*_t1041 + _hc1[29]*_t1042 - 0.1e1 / 0.3e1*_hc1[7]*_t212*_t26;
  const double _t1051 = _hc1[7]*_t170*_t212*_t8;
  const double _t1052 = -0.7e1 / 0.9e1*_hc1[10]*_t48*_t61 - 0.1e1 / 0.18e2*_hc1[14]*_t216*_t42*_t6*_t7 - 0.7e1 / 0.9e1*_hc1[4]*_t216*_t434 + (0.1e1 / 0.18e2)*_t1051 + (0.7e1 / 0.9e1)*_t561*_t87;
  const double _t1053 = _t129*_t537;
  const double _t1054 = _t129*_t539;
  const double _t1055 = _t213*_t91;
  const double _t1056 = _t168*_t443;
  const double _t1057 = 0.2e1*_t1056 + _t199*_t416 + _t200*_t439 + _t442*_t445;
  const double _t1058 = _t175*_t229;
  const double _t1059 = _t1058*_t52;
  const double _t1060 = _hc1[1]*_t527;
  const double _t1061 = _t1060*_t52;
  const double _t1062 = _t32*_t565;
  const double _t1063 = _t32*_t583;
  const double _t1064 = _t287*_t32;
  const double _t1065 = (0.1e1 / 0.2e1)*_t1059 - 0.1e1 / 0.2e1*_t1061 + _t1062*_t161 - _t1063*_t512 + _t1064*_t514;
  const double _t1066 = -0.1e1 / 0.4e1*_t1053 + (0.1e1 / 0.4e1)*_t1054 - _t1055*_t543 + _t1057 + _t1065 + 0.4e1*_t179*_t972 + _t353*(-_t1009 - _t1011 + _t1013 - _t1015 - _t1017 + _t1038) + _t368*((0.1e1 / 0.4e1)*_hc1[11]*_t175*_t216*_t77 - _t1047 - 0.1e1 / 0.4e1*_t1048 - _t1052 + (0.1e1 / 0.3e1)*_t212*_t26*_t83 + _t25*((0.1e1 / 0.4e1)*_hc1[22]*_t175*_t216*_t25 - 0.1e1 / 0.4e1*_t1039 - _t1043) - _t78*((0.1e1 / 0.4e1)*_hc1[21]*_t175*_t216*_t25 - 0.1e1 / 0.4e1*_t1045 - _t1046) - _t79*((0.1e1 / 0.4e1)*_hc1[26]*_t175*_t216*_t25 - 0.1e1 / 0.4e1*_t1049 - _t1050)) + _t441*_t525 + _t459*_t535 + 0.2e1*_t526 + 0.2e1*_t536 + _t541*_t91 + _t544*_t91;
  const double _t1067 = 0.10e2*_t1008;
  const double _t1068 = 0.10e2*_t1010;
  const double _t1069 = 0.3e1*_t1014;
  const double _t1070 = _t111*_t571;
  const double _t1071 = 0.3e1*_t1018;
  const double _t1072 = 0.6e1*_hc0[0]*_t1021;
  const double _t1073 = _t1020*_t1023;
  const double _t1074 = _t1027*_t15;
  const double _t1075 = _t1026*_t716;
  const double _t1076 = _t1035*_t47;
  const double _t1077 = (0.1e1 / 0.16e2)*_t1030 + (0.15e2 / 0.2e1)*_t1031 - 0.15e2*_t1032 + (0.13e2 / 0.8e1)*_t1033 + (0.39e2 / 0.8e1)*_t1036 + (0.3e1 / 0.16e2)*_t1074 + _t1075*_t161 + (0.15e2 / 0.2e1)*_t1076;
  const double _t1078 = _t1071 - _t1072 + _t1073 + _t1077;
  const double _t1081 = -0.1e1 / 0.12e2*_hc1[15]*_t175*_t212*_t6*_t7 + _hc1[21]*_t1079 + _hc1[26]*_t1080 - 0.2e1 / 0.3e1*_hc1[5]*_t212*_t26 + _t216*_t419;
  const double _t1082 = -0.1e1 / 0.12e2*_hc1[14]*_t175*_t212*_t6*_t7 + _hc1[20]*_t1079 + _hc1[25]*_t1080 - 0.2e1 / 0.3e1*_hc1[4]*_t212*_t26 + _t216*_t425;
  const double _t1083 = -0.1e1 / 0.12e2*_hc1[17]*_t175*_t212*_t6*_t7 + _hc1[25]*_t1079 + _hc1[29]*_t1080 - 0.2e1 / 0.3e1*_hc1[7]*_t212*_t26 + _t216*_t431;
  const double _t1084 = -0.14e2 / 0.9e1*_hc1[10]*_t48*_t61 - 0.1e1 / 0.9e1*_hc1[14]*_t216*_t42*_t6*_t7 - 0.14e2 / 0.9e1*_hc1[4]*_t216*_t434 + (0.1e1 / 0.9e1)*_t1051 + _t436*_t561;
  const double _t1085 = 0.2e1*_t986;
  const double _t1086 = _t191*_t443;
  const double _t1087 = _t238*_t91;
  const double _t1088 = _t236*_t91;
  const double _t1089 = _t1059 - _t1061 + _t1062*_t63 + _t1063*_t514 - _t32*_t586;
  const double _t1090 = (0.1e1 / 0.2e1)*_t1054 - _t1055*_t182 + _t1057 + _t1085*_t168 + _t1086 + _t1087*_t161 + _t1088*_t287 + _t1089 - _t129*_t562 + _t181*_t457 + _t183*_t474 + _t197*_t445 + _t353*(-_t1016 - _t1067 - _t1068 - _t1069 + _t1070 + _t1078) + _t368*((0.1e1 / 0.2e1)*_hc1[11]*_t175*_t216*_t77 - _t1047 - 0.1e1 / 0.2e1*_t1048 - _t1084 + (0.2e1 / 0.3e1)*_t212*_t26*_t83 + _t25*((0.1e1 / 0.2e1)*_hc1[22]*_t175*_t216*_t25 - 0.1e1 / 0.2e1*_t1039 - _t1081) - _t426*_t469 - _t78*((0.1e1 / 0.2e1)*_hc1[21]*_t175*_t216*_t25 - 0.1e1 / 0.2e1*_t1045 - _t1082) - _t79*((0.1e1 / 0.2e1)*_hc1[26]*_t175*_t216*_t25 - 0.1e1 / 0.2e1*_t1049 - _t1083)) + _t441*_t555 + _t442*_t987 + _t459*_t559 + 0.2e1*_t556 + 0.2e1*_t560;
  const double _t1091 = _t32*_t550;
  const double _t1092 = _t32*_t548;
  const double _t1093 = _t407*_t43;
  const double _t1094 = 0.20e2*_t1008;
  const double _t1095 = 0.20e2*_t1010;
  const double _t1096 = 0.6e1*_t1014;
  const double _t1097 = 0.2e1*_t1016;
  const double _t1098 = 0.40e2*_t1012;
  const double _t1099 = 0.6e1*_t1018;
  const double _t1100 = _t1021*_t346;
  const double _t1101 = 0.6e1*_t1024;
  const double _t1102 = _t1028*_t721 + 0.15e2*_t1031 - 0.30e2*_t1032 + (0.13e2 / 0.4e1)*_t1033 + (0.39e2 / 0.4e1)*_t1036 + (0.3e1 / 0.8e1)*_t1074 + _t1075*_t63 + 0.15e2*_t1076;
  const double _t1103 = _t1099 - _t1100 + _t1101 + _t1102;
  const double _t1106 = -0.1e1 / 0.6e1*_hc1[15]*_t175*_t212*_t6*_t7 + _hc1[21]*_t1104 + _hc1[26]*_t1105 - 0.4e1 / 0.3e1*_hc1[5]*_t212*_t26 + _t216*_t461;
  const double _t1107 = -0.1e1 / 0.6e1*_hc1[14]*_t175*_t212*_t6*_t7 + _hc1[20]*_t1104 + _hc1[25]*_t1105 - 0.4e1 / 0.3e1*_hc1[4]*_t212*_t26 + _t216*_t466;
  const double _t1109 = -0.1e1 / 0.6e1*_hc1[17]*_t175*_t212*_t6*_t7 + _hc1[25]*_t1104 + _hc1[29]*_t1105 - 0.4e1 / 0.3e1*_hc1[7]*_t212*_t26 + _t216*_t470;
  const double _t1110 = -0.28e2 / 0.9e1*_hc1[10]*_t48*_t61 - 0.2e1 / 0.9e1*_hc1[14]*_t216*_t42*_t6*_t7 - 0.28e2 / 0.9e1*_hc1[4]*_t216*_t434 + (0.2e1 / 0.9e1)*_t1051 + _t561*_t88;
  const double _t1111 = _hc1[12]*_t527*_t54;
  const double _t1112 = (0.1e1 / 0.4e1)*_hc1[22]*_t175*_t216*_t54 - _t1043 - 0.1e1 / 0.4e1*_t1111;
  const double _t1113 = _hc1[5]*_t212*_t961;
  const double _t1114 = _hc1[11]*_t54;
  const double _t1115 = _t1114*_t527;
  const double _t1116 = _t467*_t482;
  const double _t1117 = _hc1[15]*_t527*_t54;
  const double _t1118 = _t1052 + _t1116 - 0.1e1 / 0.3e1*_t134*_t212*_t26 + _t78*((0.1e1 / 0.4e1)*_hc1[21]*_t175*_t216*_t54 - _t1046 - 0.1e1 / 0.4e1*_t1115) + _t79*((0.1e1 / 0.4e1)*_hc1[26]*_t175*_t216*_t54 - _t1050 - 0.1e1 / 0.4e1*_t1117);
  const double _t1119 = 0.2e1*_t204;
  const double _t1120 = _t1060*_t59;
  const double _t1121 = _t145*_t537;
  const double _t1122 = _t1058*_t59;
  const double _t1123 = _t145*_t539;
  const double _t1124 = _t548*_t55;
  const double _t1125 = _t512*_t55;
  const double _t1126 = _t137*_t213;
  const double _t1127 = _t55*_t550;
  const double _t1128 = _t202*_t443;
  const double _t1129 = _t1056 + _t1128 + _t179*_t445 + _t199*_t477 + _t200*_t485 + _t204*_t445;
  const double _t1130 = (0.1e1 / 0.4e1)*_t1059 - 0.1e1 / 0.4e1*_t1061 - _t1064*_t512 + (0.1e1 / 0.8e1)*_t1091 + (0.1e1 / 0.8e1)*_t1092 + _t1119*_t972 - 0.1e1 / 0.4e1*_t1120 - 0.1e1 / 0.4e1*_t1121 + (0.1e1 / 0.4e1)*_t1122 + (0.1e1 / 0.4e1)*_t1123 + (0.1e1 / 0.8e1)*_t1124 - _t1125*_t287 - _t1126*_t543 + (0.1e1 / 0.8e1)*_t1127 + _t1129 + _t137*_t541 + _t137*_t544 + _t147*_t525 + _t242*_t588 + _t244*_t591 + _t353*(-_t1019 + _t1022 - _t1025 + _t1037) + _t368*((0.1e1 / 0.2e1)*_hc1[11]*_t11*_t216*_t912 + _t1112*_t25 - 0.1e1 / 0.2e1*_t1113 - _t1118) + _t369*_t535 + _t442*_t996 + _t526 + _t536 + _t589 + _t592;
  const double _t1131 = (0.1e1 / 0.2e1)*_hc1[22]*_t175*_t216*_t54 - _t1081 - 0.1e1 / 0.2e1*_t1111;
  const double _t1132 = _t1084 + _t1116 - 0.2e1 / 0.3e1*_t134*_t212*_t26 + _t426*_t489 + _t78*((0.1e1 / 0.2e1)*_hc1[21]*_t175*_t216*_t54 - _t1082 - 0.1e1 / 0.2e1*_t1115) + _t79*((0.1e1 / 0.2e1)*_hc1[26]*_t175*_t216*_t54 - _t1083 - 0.1e1 / 0.2e1*_t1117);
  const double _t1133 = _t207*_t443;
  const double _t1134 = _t137*_t238;
  const double _t1135 = _t137*_t236;
  const double _t1136 = _t55*_t565;
  const double _t1137 = _t514*_t55;
  const double _t1138 = -0.1e1 / 0.2e1*_t1120 + (0.1e1 / 0.2e1)*_t1122 - _t1125*_t583 + _t1136*_t161 + _t1137*_t287;
  const double _t1139 = _t1001*_t179 + _t1065 + (0.1e1 / 0.2e1)*_t1086 + (0.1e1 / 0.2e1)*_t1123 - _t1126*_t182 + _t1129 + (0.1e1 / 0.2e1)*_t1133 + _t1134*_t161 + _t1135*_t287 + _t1138 - _t145*_t562 + _t147*_t555 + _t181*_t487 + _t183*_t492 + _t197*_t476 + _t202*_t986 + _t204*_t987 + _t209*_t476 + _t209*_t972 + _t242*_t598 + _t244*_t600 + _t353*(-_t1071 + _t1072 - _t1073 + _t1077) + _t368*(_hc1[11]*_t11*_t216*_t912 - _t1113 + _t1131*_t25 - _t1132) + _t369*_t559 + _t556 + _t560 + _t599 + _t601;
  const double _t1140 = _hc1[22]*_t175*_t216*_t54 - _t1106 - _t1111;
  const double _t1141 = _t1108*_t489 + _t1110 - 0.4e1 / 0.3e1*_t134*_t212*_t26 + _t78*(_hc1[21]*_t175*_t216*_t54 - _t1107 - _t1115) + _t79*(_hc1[26]*_t175*_t216*_t54 - _t1109 - _t1117);
  const double _t1142 = -_t1120 + _t1122 + _t1136*_t63 + _t1137*_t583 - _t55*_t586;
  const double _t1143 = _t379*_t527;
  const double _t1144 = _t155*_t537;
  const double _t1145 = _t155*_t539;
  const double _t1146 = _t150*_t213;
  const double _t1147 = _t1119*_t445 + 0.2e1*_t1128 + _t199*_t494 + _t200*_t497;
  const double _t1148 = _t1138 - 0.1e1 / 0.4e1*_t1144 + (0.1e1 / 0.4e1)*_t1145 - _t1146*_t543 + _t1147 + _t150*_t541 + _t150*_t544 + 0.4e1*_t204*_t996 + _t353*(_t1009 + _t1011 - _t1013 + _t1015 + _t1017 + _t1038) + _t368*((0.1e1 / 0.4e1)*_hc1[11]*_t149*_t175*_t216 + _t1112*_t54 - _t1118 - 0.1e1 / 0.4e1*_t1143) + _t499*_t588 + _t500*_t591 + 0.2e1*_t589 + 0.2e1*_t592;
  const double _t1149 = _t150*_t238;
  const double _t1150 = _t150*_t236;
  const double _t1151 = _t1001*_t1119 + _t1133 + _t1142 + (0.1e1 / 0.2e1)*_t1145 - _t1146*_t182 + _t1147 + _t1149*_t161 + _t1150*_t287 - _t155*_t562 + _t181*_t503 + _t183*_t505 + _t209*_t445 + _t353*(_t1016 + _t1067 + _t1068 + _t1069 - _t1070 + _t1078) + _t368*((0.1e1 / 0.2e1)*_hc1[11]*_t149*_t175*_t216 + _t1131*_t54 - _t1132 - 0.1e1 / 0.2e1*_t1143) + _t499*_t598 + _t500*_t600 + 0.2e1*_t599 + 0.2e1*_t601 + _t609*_t996;
  const double _t1152 = _t48*_t507;
  const double _t1153 = _t1152*_t616;
  const double _t1154 = _t157*_t42;
  const double _t1155 = _t1154*_t656;
  const double _t1157 = _t1156*_t697;
  const double _t1158 = (0.3e1 / 0.8e1)*_t1157;
  const double _t1159 = _t350*_t625;
  const double _t1160 = (0.1e1 / 0.8e1)*_t1159;
  const double _t1162 = _t106*_t120;
  const double _t1163 = _t1161*_t1162;
  const double _t1164 = _t274*_t713;
  const double _t1165 = _t1164*_t517;
  const double _t1166 = _t281*_t625;
  const double _t1169 = _t1168*_t716;
  const double _t1171 = _hc0[4]*_t278;
  const double _t1172 = _t1170*_t1171;
  const double _t1174 = _t49*_t610;
  const double _t1175 = M_PI*_t1174;
  const double _t1176 = _t1175*_t47;
  const double _t1177 = -0.15e2 / 0.16e2*_hc0[0]*_hc0[2]*_t115*_t125*_t15*_t615 - 0.15e2 / 0.16e2*_t115*_t116*_t125*_t15*_t615 + (0.3e1 / 0.64e2)*_t1165 + (0.1e1 / 0.8e1)*_t1166 + _t1167*_t1169 + (0.1e1 / 0.64e2)*_t1172 + _t1173*_t413 + (0.15e2 / 0.8e1)*_t1176;
  const double _t1179 = _t1044*_t615;
  const double _t1180 = _t27*_t610;
  const double _t1181 = _hc1[20]*_t549;
  const double _t1182 = _hc1[7]*_t175*_t610*_t8;
  const double _t1183 = _hc1[25]*_t212*_t215;
  const double _t1184 = _t1183*_t8;
  const double _t1185 = -0.1e1 / 0.16e2*_hc1[14]*_t13*_t6*_t615*_t7 - 0.1e1 / 0.2e1*_hc1[4]*_t170*_t615 + (0.1e1 / 0.2e1)*_t1180 + _t1181*_t577 + (0.1e1 / 0.16e2)*_t1182 + (0.1e1 / 0.48e2)*_t1184;
  const double _t1186 = _t168*_t537;
  const double _t1187 = _hc1[4]*_t228;
  const double _t1188 = _t1187*_t52;
  const double _t1189 = _hc1[10]*_t37;
  const double _t1190 = _t1189*_t212;
  const double _t1191 = _t1190*_t52;
  const double _t1192 = _t199*_t525;
  const double _t1193 = _t168*_t539;
  const double _t1194 = _t226*_t52;
  const double _t1195 = _t32*_t42;
  const double _t1196 = _t615*_t633;
  const double _t1197 = (0.3e1 / 0.8e1)*_t224;
  const double _t1198 = _t179*_t584;
  const double _t1199 = _t615*_t623;
  const double _t1200 = _t32*_t627;
  const double _t1201 = _t200*_t535;
  const double _t1202 = _t13*_t32;
  const double _t1203 = _t1202*_t71;
  const double _t1204 = (0.3e1 / 0.8e1)*_t222;
  const double _t1205 = _t32*_t630;
  const double _t1206 = _t13*_t635;
  const double _t1207 = _hc1[1]*_t22;
  const double _t1208 = _t48*_t621;
  const double _t1210 = _t1209*_t561;
  const double _t1211 = _hc1[1]*_t549;
  const double _t1212 = _t126*_t625;
  const double _t1213 = _t42*_t72;
  const double _t1214 = _hc1[4]/xc_powr(_t1, 23, 3);
  const double _t1215 = _t1156*_t412*_t632 - _t1178*_t638 + _t12*_t1207*_t611 + (0.1e1 / 0.8e1)*_t1206 - _t1208*_t623 - _t1208*_t633 + _t1210*_t623 + _t1210*_t633 - _t1211*_t617 + _t1212*_t628 + _t1213*_t611 + _t1214*_t620;
  const double _t1216 = -0.3e1 / 0.4e1*_t1186 - _t1188*_t645 + (0.1e1 / 0.8e1)*_t1191 + (0.3e1 / 0.2e1)*_t1192 + (0.3e1 / 0.4e1)*_t1193 + _t1194*_t611 - _t1195*_t1196 - _t1195*_t1199 + _t1197*_t179 - 0.3e1 / 0.4e1*_t1198 + (0.1e1 / 0.32e2)*_t1200 + (0.3e1 / 0.2e1)*_t1201 + _t1203*_t611 + _t1204*_t179 + _t1205*_t631 + _t1215 + _t353*(-_t1153 + _t1155 + _t1158 + _t1160 - _t1163 - _t1177) + _t368*((0.1e1 / 0.8e1)*_hc1[21]*_t13*_t212*_t25 + (0.3e1 / 0.8e1)*_hc1[5]*_t12*_t25*_t610 - _t1178*_t1179 - _t1185);
  const double _t1217 = _t1152*_t615;
  const double _t1218 = (0.3e1 / 0.2e1)*_t1217;
  const double _t1220 = _t1154*_t1219;
  const double _t1221 = (0.3e1 / 0.4e1)*_t1157;
  const double _t1222 = (0.1e1 / 0.4e1)*_t1159;
  const double _t1223 = _t1162*_t48;
  const double _t1224 = _t1223*_t642;
  const double _t1225 = _t114*_t625;
  const double _t1226 = -0.15e2 / 0.8e1*_hc0[0]*_hc0[2]*_t115*_t125*_t15*_t615 + _t1034*_t1175 - 0.15e2 / 0.8e1*_t115*_t116*_t125*_t15*_t615 + _t1164*_t216*_t631 + (0.1e1 / 0.8e1)*_t1169*_t711 + (0.1e1 / 0.32e2)*_t1172 + _t1173*_t293 + _t1225*_t287;
  const double _t1228 = -0.1e1 / 0.8e1*_hc1[14]*_t13*_t6*_t615*_t7 - _hc1[4]*_t170*_t615 + _t1180 + _t1181*_t530 + (0.1e1 / 0.8e1)*_t1182 + _t1183*_t531;
  const double _t1229 = _t199*_t555;
  const double _t1230 = _t1188*_t615;
  const double _t1231 = _t191*_t537;
  const double _t1232 = _t191*_t539;
  const double _t1233 = _t223*_t646;
  const double _t1234 = _t200*_t559;
  const double _t1235 = _t221*_t646;
  const double _t1236 = _t197*_t213;
  const double _t1237 = _t1205*_t15;
  const double _t1238 = _t238*_t63;
  const double _t1239 = _t236*_t583;
  const double _t1240 = -_t1186 + _t1193 - _t1198 + _t1238*_t179 + _t1239*_t179;
  const double _t1242 = _t1210*_t223;
  const double _t1243 = _t1214*_t619;
  const double _t1244 = _t1210*_t221;
  const double _t1245 = _hc1[0]*_t1156;
  const double _t1246 = _t12*_t1207*_t641 + (0.1e1 / 0.4e1)*_t1206 - _t1211*_t643 + _t1212*_t649 + _t1213*_t641 - _t1227*_t638 - _t1241*_t647 - _t1241*_t652 + (0.3e1 / 0.8e1)*_t1242 + (0.3e1 / 0.4e1)*_t1243 + (0.3e1 / 0.8e1)*_t1244 + _t1245*_t521;
  const double _t1247 = (0.1e1 / 0.4e1)*_t1191 + _t1192 + _t1194*_t641 + (0.1e1 / 0.16e2)*_t1200 + _t1201 + _t1203*_t641 + _t1229 - 0.3e1 / 0.4e1*_t1230 - 0.1e1 / 0.4e1*_t1231 + (0.1e1 / 0.4e1)*_t1232 - _t1233*_t32 + _t1234 - _t1235*_t32 - _t1236*_t543 + (0.3e1 / 0.16e2)*_t1237 + _t1240 + _t1246 + _t197*_t541 + _t197*_t544 + _t353*(-_t1218 + _t1220 + _t1221 + _t1222 - _t1224 - _t1226) + _t368*((0.1e1 / 0.4e1)*_hc1[21]*_t13*_t212*_t25 + (0.3e1 / 0.4e1)*_hc1[5]*_t12*_t25*_t610 - _t1179*_t1227 - _t1228);
  const double _t1248 = 0.3e1*_t1217;
  const double _t1249 = _t1154*_t610;
  const double _t1250 = 0.6e1*_t1249;
  const double _t1251 = _t1223*_t615;
  const double _t1252 = 0.3e1*_t1251;
  const double _t1253 = (0.3e1 / 0.2e1)*_t1157;
  const double _t1254 = (0.1e1 / 0.2e1)*_t1159;
  const double _t1256 = -0.15e2 / 0.4e1*_hc0[0]*_hc0[2]*_t115*_t125*_t15*_t615 - 0.15e2 / 0.4e1*_t115*_t116*_t125*_t15*_t615 + _t1167*_t1171*_t216 + _t1168*_t875 + (0.3e1 / 0.2e1)*_t1173*_t292 + (0.15e2 / 0.2e1)*_t1176 + _t1225*_t583 + _t1255*_t882;
  const double _t1258 = _t1181*_t216;
  const double _t1259 = -0.1e1 / 0.4e1*_hc1[14]*_t13*_t6*_t615*_t7 - 0.2e1*_hc1[4]*_t170*_t615 + 0.2e1*_t1180 + (0.1e1 / 0.4e1)*_t1182 + _t1183*_t176 + (0.2e1 / 0.3e1)*_t1258;
  const double _t1260 = _t223*_t616;
  const double _t1261 = _t1195*_t221;
  const double _t1262 = -_t1161*_t647 + _t12*_t1207*_t656 + (0.1e1 / 0.2e1)*_t1206 - _t1211*_t658 + _t1212*_t219 + _t1213*_t656 + (0.3e1 / 0.4e1)*_t1242 + (0.3e1 / 0.2e1)*_t1243 + (0.3e1 / 0.4e1)*_t1244 + _t1245*_t413 - _t1257*_t638 - _t48*_t661;
  const double _t1263 = (0.1e1 / 0.2e1)*_t1191 + _t1194*_t656 - _t1195*_t1260 + (0.1e1 / 0.8e1)*_t1200 + _t1203*_t656 + 0.2e1*_t1229 - 0.3e1 / 0.2e1*_t1230 - _t1231 + _t1232 + 0.2e1*_t1234 + _t1238*_t197 + _t1239*_t197 + _t1240 - _t1261*_t616 + _t1262 + _t181*_t574 + _t183*_t580 - _t197*_t584 + _t32*_t660 + _t353*(-_t1248 + _t1250 - _t1252 + _t1253 + _t1254 - _t1256) + _t368*((0.1e1 / 0.2e1)*_hc1[21]*_t13*_t212*_t25 + (0.3e1 / 0.2e1)*_hc1[5]*_t12*_t25*_t610 - _t1179*_t1257 - _t1259);
  const double _t1264 = 0.6e1*_t1217;
  const double _t1265 = 0.12e2*_t1249;
  const double _t1266 = 0.3e1*_t1157;
  const double _t1267 = 0.6e1*_t1251;
  const double _t1268 = _t405*_t412;
  const double _t1269 = -0.15e2 / 0.2e1*_hc0[0]*_hc0[2]*_t115*_t125*_t15*_t615 - 0.15e2 / 0.2e1*_t115*_t116*_t125*_t15*_t615 + (0.3e1 / 0.8e1)*_t1165 + _t1166 + (0.1e1 / 0.8e1)*_t1172 + _t1173*_t1268 + 0.15e2*_t1176 + _t1255*_t717;
  const double _t1271 = -0.1e1 / 0.2e1*_hc1[14]*_t13*_t6*_t615*_t7 - 0.4e1*_hc1[4]*_t170*_t615 + 0.4e1*_t1180 + (0.1e1 / 0.2e1)*_t1182 + (0.1e1 / 0.6e1)*_t1184 + (0.4e1 / 0.3e1)*_t1258;
  const double _t1272 = 0.3e1*_t199;
  const double _t1273 = _t615*_t670;
  const double _t1274 = (0.3e1 / 0.2e1)*_t224;
  const double _t1275 = _t610*_t663;
  const double _t1276 = _t62*_t663;
  const double _t1277 = (0.3e1 / 0.2e1)*_t222;
  const double _t1278 = _hc1[0]*_t164*_t625 + _t12*_t1207*_t1219 + _t1206 - _t1208*_t669 - _t1208*_t670 + _t1210*_t669 + _t1210*_t670 - _t1211*_t615*_t667 + _t1214*_t668 + _t1245*_t293 - _t1270*_t638 + _t42*_t665;
  const double _t1279 = _t1114*_t615;
  const double _t1280 = _t202*_t537;
  const double _t1281 = _t1187*_t59;
  const double _t1282 = _t1190*_t59;
  const double _t1283 = _t199*_t588;
  const double _t1284 = _t202*_t539;
  const double _t1285 = _t226*_t59;
  const double _t1286 = _t42*_t55;
  const double _t1287 = _t204*_t584;
  const double _t1288 = _t55*_t627;
  const double _t1289 = _t200*_t591;
  const double _t1290 = _t13*_t55;
  const double _t1291 = _t1290*_t71;
  const double _t1292 = _t55*_t630;
  const double _t1293 = -_t1196*_t1286 + _t1197*_t204 - _t1199*_t1286 + _t1204*_t204 + _t1215 - 0.3e1 / 0.4e1*_t1280 - _t1281*_t645 + (0.1e1 / 0.8e1)*_t1282 + (0.3e1 / 0.2e1)*_t1283 + (0.3e1 / 0.4e1)*_t1284 + _t1285*_t611 - 0.3e1 / 0.4e1*_t1287 + (0.1e1 / 0.32e2)*_t1288 + (0.3e1 / 0.2e1)*_t1289 + _t1291*_t611 + _t1292*_t631 + _t353*(_t1153 - _t1155 - _t1158 - _t1160 + _t1163 - _t1177) + _t368*((0.1e1 / 0.8e1)*_hc1[21]*_t13*_t212*_t54 + (0.3e1 / 0.8e1)*_hc1[5]*_t12*_t54*_t610 - _t1178*_t1279 - _t1185);
  const double _t1294 = _t199*_t598;
  const double _t1295 = _t1281*_t615;
  const double _t1296 = _t207*_t537;
  const double _t1297 = _t207*_t539;
  const double _t1298 = _t200*_t600;
  const double _t1299 = _t209*_t213;
  const double _t1300 = _t1292*_t15;
  const double _t1301 = _t1238*_t204 + _t1239*_t204 - _t1280 + _t1284 - _t1287;
  const double _t1302 = -_t1233*_t55 - _t1235*_t55 + _t1246 + (0.1e1 / 0.4e1)*_t1282 + _t1283 + _t1285*_t641 + (0.1e1 / 0.16e2)*_t1288 + _t1289 + _t1291*_t641 + _t1294 - 0.3e1 / 0.4e1*_t1295 - 0.1e1 / 0.4e1*_t1296 + (0.1e1 / 0.4e1)*_t1297 + _t1298 - _t1299*_t543 + (0.3e1 / 0.16e2)*_t1300 + _t1301 + _t209*_t541 + _t209*_t544 + _t353*(_t1218 - _t1220 - _t1221 - _t1222 + _t1224 - _t1226) + _t368*((0.1e1 / 0.4e1)*_hc1[21]*_t13*_t212*_t54 + (0.3e1 / 0.4e1)*_hc1[5]*_t12*_t54*_t610 - _t1227*_t1279 - _t1228);
  const double _t1303 = _t1286*_t221;
  const double _t1304 = _t1238*_t209 + _t1239*_t209 - _t1260*_t1286 + _t1262 + (0.1e1 / 0.2e1)*_t1282 + _t1285*_t656 + (0.1e1 / 0.8e1)*_t1288 + _t1291*_t656 + 0.2e1*_t1294 - 0.3e1 / 0.2e1*_t1295 - _t1296 + _t1297 + 0.2e1*_t1298 + _t1301 - _t1303*_t616 + _t181*_t605 + _t183*_t607 - _t209*_t584 + _t353*(_t1248 - _t1250 + _t1252 - _t1253 - _t1254 - _t1256) + _t368*((0.1e1 / 0.2e1)*_hc1[21]*_t13*_t212*_t54 + (0.3e1 / 0.2e1)*_hc1[5]*_t12*_t54*_t610 - _t1257*_t1279 - _t1259) + _t55*_t660;
  const double _t1306 = _t1305*_t612;
  const double _t1309 = _t613*_t71;
  const double _t1310 = _hc1[10]*_t657;
  const double _t1311 = _t610*_t618*_t71;
  const double _t1312 = _t1307*_t659;
  const double _t1313 = _t1211*_t610;
  const double _t1314 = _t1313*_t221;
  const double _t1315 = _t1214*_t615;
  const double _t1317 = _t1209*_t720;
  const double _t1318 = _t1174*_t291*_t650;
  const double _t1319 = _t1209*_t666;
  const double _t1320 = _t125*_t621;
  const double _t1321 = _t1320*_t711;
  const double _t1322 = _t1321*_t721;
  const double _t1323 = (0.1e1 / 0.32e2)*_t1321;
  const double _t1324 = _t42*_t652;
  const double _t1325 = _t1307*_t1324;
  const double _t1326 = _t1313*_t223;
  const double _t1327 = _t1320*_t713;
  const double _t1328 = _t1327*_t15;
  const double _t1329 = _t1305*_t634;
  const double _t1330 = _t1189*_t22;
  const double _t1331 = _hc1[20]*_t328*_t637;
  const double _t1333 = _t1187*_t22;
  const double _t1334 = -_hc0[0]*_t286*_t48*_t610*_t632 + _hc1[1]*_t1316*_t1317 + _t1029*_t1323 + _t114*_t1310*_t287 + _t1196*_t1214 - 0.15e2 / 0.16e2*_t1306 + _t1308*_t1309 - 0.9e1 / 0.8e1*_t1311 + (0.15e2 / 0.32e2)*_t1312 - 0.9e1 / 0.16e2*_t1314 + _t1315*_t623 - 0.9e1 / 0.32e2*_t1318 + _t1319*_t521 + (0.1e1 / 0.128e3)*_t1322 + (0.15e2 / 0.32e2)*_t1325 - 0.9e1 / 0.16e2*_t1326 + (0.3e1 / 0.128e3)*_t1328 - 0.15e2 / 0.16e2*_t1329 - _t1330*_t611 + (0.1e1 / 0.16e2)*_t1331 + _t1332*_t1333;
  const double _t1335 = _t1307*_t1309;
  const double _t1336 = _t1214*_t645;
  const double _t1337 = _t48*_t720;
  const double _t1338 = _hc1[1]*_t1209*_t292;
  const double _t1340 = _t1029*_t1339;
  const double _t1341 = _hc1[0]*_t1316;
  const double _t1342 = _t1307*_t1333;
  const double _t1343 = _hc1[10]*_t114*_t182*_t615 - 0.15e2 / 0.8e1*_t1306 - 0.9e1 / 0.4e1*_t1311 - 0.9e1 / 0.8e1*_t1314 - 0.9e1 / 0.16e2*_t1318 + _t1319*_t409*_t47 + (0.1e1 / 0.64e2)*_t1322 + _t1324*_t1332 - 0.9e1 / 0.8e1*_t1326 + (0.3e1 / 0.64e2)*_t1328 - 0.15e2 / 0.8e1*_t1329 - _t1330*_t641 + (0.1e1 / 0.8e1)*_t1331 + _t1332*_t659 + (0.15e2 / 0.4e1)*_t1335 + _t1336*_t221 + _t1336*_t223 - 0.3e1 / 0.16e2*_t1337*_t664 + _t1338*_t645 + _t1340*_t1341 + (0.15e2 / 0.8e1)*_t1342;
  const double _t1344 = _t1310*_t281;
  const double _t1345 = _t1214*_t221;
  const double _t1346 = _hc1[0]*_t1337;
  const double _t1347 = _t219*_t615;
  const double _t1348 = _t1214*_t1260 - 0.15e2 / 0.4e1*_t1306 + _t1308*_t659 - 0.9e1 / 0.2e1*_t1311 - 0.9e1 / 0.4e1*_t1314 - 0.9e1 / 0.8e1*_t1318 + _t1319*_t288 + _t1323*_t721 + (0.15e2 / 0.8e1)*_t1325 - 0.9e1 / 0.4e1*_t1326 + _t1327*_t631 - 0.15e2 / 0.4e1*_t1329 - _t1330*_t656 + (0.1e1 / 0.4e1)*_t1331 + (0.15e2 / 0.2e1)*_t1335 + _t1338*_t616 + _t1340*_t1347 + (0.15e2 / 0.4e1)*_t1342 + _t1344 + _t1345*_t616 - _t1346*_t611;
  const double _t1349 = _t1339*_t721;
  const double _t1350 = _t1339*_t615*_t716;
  const double _t1351 = _t1214*_t1273 - _t1219*_t1330 - 0.15e2 / 0.2e1*_t1306 - 0.9e1*_t1311 + (0.15e2 / 0.4e1)*_t1312 - 0.9e1 / 0.2e1*_t1314 - 0.9e1 / 0.4e1*_t1318 + _t1319*_t286*_t583 + _t1320*_t876 + (0.15e2 / 0.4e1)*_t1325 - 0.9e1 / 0.2e1*_t1326 - 0.15e2 / 0.2e1*_t1329 + (0.1e1 / 0.2e1)*_t1331 + 0.15e2*_t1335 + _t1338*_t642 + _t1341*_t1349 + (0.15e2 / 0.2e1)*_t1342 + 0.2e1*_t1344 + _t1345*_t642 - _t1346*_t641 + _t1350*_t214;
  const double d4F_dna4 = 0.6e1*_t129*_t673 + 0.4e1*_t242*_t297 + 0.4e1*_t244*_t334 + 0.4e1*_t298 + 0.4e1*_t335 + _t353*(_t144*(-0.96e2*_t676 + _t684) + _t252*_t678*nb - 0.96e2*_t254 - 0.384e3*_t271 + _t343*_t679 - _t675 - _t676*_t677 - 0.384e3*_t681 - 0.32e2*_t682*na + _t686*_t687 - _t690 - _t692 - _t694 - _t695*_t696 - _t699 - _t702 + _t725) + _t368*(_hc1[2]*(-_t112 + _t726) + _t25*(_hc1[6]*_t301 + _t25*(_hc1[13]*_t77 + _t25*(_hc1[24]*_t25 - _t727) - _t729*_t78 - _t731*_t79 + _t732) + _t303*_t312 + _t305*_t393 + _t307*_t394 - _t739*_t78 - _t743*_t79 + _t748) + 0.3e1*_t301*_t81 + 0.3e1*_t311*_t77 + _t319*_t763 + _t325*_t769 - _t326*_t436 - 0.280e3 / 0.9e1*_t749 + _t770 - _t78*(_hc1[5]*_t301 + _t25*_t739 + _t305*_t312 + _t315*_t393 + _t317*_t394 - _t759*_t79 + _t762 - _t78*(_t25*_t735 + _t750 - _t753*_t79 + _t754 - _t78*(_hc1[21]*_t25 - _t751))) - _t79*(_hc1[8]*_t301 + _t25*_t743 + _t307*_t312 + _t317*_t393 + _t323*_t394 - _t759*_t78 + _t768 - _t79*(_hc1[18]*_t77 + _t25*_t741 - _t757*_t78 + _t765 - _t79*(_hc1[33]*_t25 - _t764)))) + 0.12e2*_t671 + 0.12e2*_t672;
  const double d4F_dna3_dnb = _t147*_t297 + _t243*_t352 + _t245*_t367 + _t298 + _t334*_t369 + _t335 + _t353*(0.840e3*M_PI*_hc0[0]*_hc0[1]*_t15*_t274*_t4 + 0.126e3*_hc0[0]*_hc0[2]*_t115*_t15*_t283*_t3 + 0.7e1*_hc0[0]*_hc0[3]*_t15*_t211*_t285*_t718 + (0.1e1 / 0.8e1)*_hc0[0]*_hc0[4]*_t15*_t614*_t709*_t711 + 0.21e2*_hc0[1]*_hc0[2]*_t15*_t211*_t285*_t718 + (0.1e1 / 0.2e1)*_hc0[1]*_hc0[3]*_t15*_t614*_t709*_t711 + 0.72e2*_t103*_t13*na*nb + 0.12e2*_t103*_t17 + 0.840e3*_t114*_t14*_t15 + 0.126e3*_t115*_t116*_t15*_t283*_t3 + 0.72e2*_t13*_t143*na*nb + 0.72e2*_t13*_t19 + 0.72e2*_t13*_t41*na + 0.144e3*_t13*_t41*nb + 0.72e2*_t13*_t58*nb - _t14*_t782 - 0.144e3*_t14*_t784 - _t141*_t682 + (0.3e1 / 0.8e1)*_t15*_t614*_t709*_t711*_t712 + 0.4e1*_t17*_t252*na + 0.12e2*_t17*_t340*nb + 0.4e1*_t17*na*nb*(-_t249*_t57 - 0.72e2*_t676 - _t785) + 0.480e3*_t19*_t48*na*nb - _t248 - _t255 - _t266*_t789 - 0.288e3*_t271 - _t272*_t341*_t42 - 0.48e2*_t337 - _t346*_t695 - _t680*_t788 - _t707 - 0.24e2*_t781 - 0.96e2*_t783 - 0.24e2*_t787 - _t791) + _t368*(_hc1[2]*(-_t108 + _t726) + _t133*_t301 - _t134*_t744 - _t135*_t746 + _t25*(_hc1[6]*_t354 + _t25*(_hc1[13]*_t76 + _t25*_t792 + _t795) + _t303*_t76 + _t305*_t308 + _t307*_t309 + _t308*_t356 + _t309*_t357 + _t355*_t77 + _t748 - _t78*_t799 - _t79*_t802) + _t308*_t319 + _t309*_t325 + _t311*_t76 + _t312*_t359 - _t326*_t809 + 0.2e1*_t354*_t81 - 0.560e3 / 0.27e2*_t749 - _t78*(_t25*_t799 + _t305*_t76 + _t308*_t315 + _t308*_t360 + _t309*_t317 + _t309*_t361 + _t356*_t77 + _t762 - _t78*(_hc1[11]*_t76 + _t25*_t796 + _t805) - _t79*_t808 + _t803) - _t79*(_hc1[8]*_t354 + _t25*_t802 + _t307*_t76 + _t308*_t317 + _t308*_t361 + _t309*_t323 + _t309*_t364 + _t357*_t77 + _t768 - _t78*_t808 - _t79*(_hc1[18]*_t76 + _t25*_t800 + _t810)) + _t811) + 0.3e1*_t671 + 0.3e1*_t672 + _t673*_t777 + 0.3e1*_t771 + 0.6e1*_t772 + 0.3e1*_t773 + 0.6e1*_t774 + _t775*_t776 + 0.3e1*_t778 + 0.3e1*_t779;
  const double d4F_dna2_dnb2 = 0.4e1*_t137*_t816 + _t150*_t775 + _t155*_t673 + _t352*_t499 + _t353*(_t112*_t686 + _t112*_t824 + _t13*_t143*_t272*nb + 0.96e2*_t13*_t341 - 0.32e2*_t140 + _t143*_t678 + _t144*(-_t112 - _t782 - 0.48e2*_t784 - _t785) - 0.192e3*_t271 + _t272*_t343 + 0.96e2*_t336 - 0.32e2*_t337 + 0.48e2*_t344 + _t345*_t820 + _t374*_t95*nb - 0.16e2*_t375 - 0.192e3*_t681 - 0.480e3*_t703 - 0.12e2*_t704 - 0.12e2*_t705 - 0.240e3*_t706 + _t724 - 0.16e2*_t781 - 0.192e3*_t783 + _t786*_t95 - 0.16e2*_t787 - 0.32e2*_t819 - 0.192e3*_t821 - 0.16e2*_t823 - 0.32e2*_t97) + _t367*_t500 + _t368*(_t100*_t11*_t359 + _t25*(-_hc1[6]*_t300 - _hc1[6]*_t38 + 0.4e1*_t11*_t355*_t37 + _t25*_t831 + (0.4e1 / 0.9e1)*_t26*_t357*_t6*_t7 + (0.56e2 / 0.9e1)*_t356*_t4*_t87 - _t745 - _t747 - _t827 - _t830) - _t300*_t81 + _t308*_t380 + _t309*_t377 - _t320*_t329 - _t326*_t331 + _t354*_t392 - _t38*_t81 + _t382*_t77 - _t78*(-_hc1[5]*_t300 - _hc1[5]*_t38 + 0.4e1*_t11*_t356*_t37 + _t25*_t829 + (0.4e1 / 0.9e1)*_t26*_t361*_t6*_t7 + (0.56e2 / 0.9e1)*_t360*_t4*_t87 - _t760 - _t761 - _t835 - _t837) - _t79*(-_hc1[8]*_t300 - _hc1[8]*_t38 + 0.4e1*_t11*_t357*_t37 + _t25*_t826 + (0.4e1 / 0.9e1)*_t26*_t364*_t6*_t7 + (0.56e2 / 0.9e1)*_t361*_t4*_t87 - _t766 - _t767 - _t839 - _t840) - _t809*_t838 + _t811 + _t825 - 0.560e3 / 0.27e2*_t832) + _t376*_t441 + _t383*_t459 + 0.2e1*_t771 + 0.4e1*_t772 + 0.2e1*_t773 + 0.4e1*_t774 + 0.2e1*_t778 + 0.2e1*_t779 + 0.2e1*_t812 + 0.4e1*_t813 + 0.2e1*_t814 + 0.4e1*_t815 + 0.2e1*_t817 + 0.2e1*_t818;
  const double d4F_dna_dnb3 = _t242*_t389 + _t244*_t395 + _t353*(0.24e2*_hc0[0]*_t789 + _t139*_t387 + _t14*_t847 + _t143*_t851 + _t144*(-_t249*_t40 - 0.72e2*_t784 - _t785) + _t154*_t845 + _t154*_t851 + _t19*_t683 - 0.96e2*_t271 + _t341*_t683 - _t386 - _t388 - _t58*_t788*na + _t680*_t683 - 0.96e2*_t681 - _t707 + _t723 - 0.288e3*_t783 + _t791 - 0.48e2*_t819 + _t822*_t845 - 0.24e2*_t823 - 0.24e2*_t846 + 0.144e3*_t848 - 0.8e1*_t850) + _t368*(_hc1[2]*_t108 - 0.18e2*_t11*_t13*_t133 + _t11*_t299*_t382 - _t133*_t299 + _t25*_t853 + _t825 + _t854) + _t376*_t384 + _t383*_t385 + _t390 + _t396 + _t776*_t843 + _t777*_t844 + 0.3e1*_t812 + 0.6e1*_t813 + 0.3e1*_t814 + 0.6e1*_t815 + 0.3e1*_t817 + 0.3e1*_t818 + 0.3e1*_t841 + 0.3e1*_t842;
  const double d4F_dnb4 = 0.4e1*_t147*_t389 + 0.6e1*_t150*_t843 + _t353*(_t144*(_t684 - _t847) + _t675 - _t677*_t784 + _t678*_t849 + _t687*_t824 + _t690 + _t692 + _t694 - _t696*_t789 + _t699 + _t702 + _t725 - 0.384e3*_t783 - 0.384e3*_t821 - 0.96e2*_t846 + 0.288e3*_t848 - 0.32e2*_t850) + _t368*(_hc1[2]*(_t112 + _t726) + 0.3e1*_t133*_t391 + 0.3e1*_t149*_t382 + _t54*_t853 + _t854) + 0.4e1*_t369*_t395 + 0.4e1*_t390 + 0.4e1*_t396 + 0.12e2*_t841 + 0.12e2*_t842;
  const double d4F_dna3_dgaa = _t919;
  const double d4F_dna3_dgab = _t191*_t855 + _t191*_t859 + _t197*_t856 + _t197*_t860 + _t199*_t297 + _t200*_t334 + _t243*_t457 + _t245*_t474 + _t353*(0.12e2*M_PI*_hc0[0]*_hc0[1]*_t40*_t42*_t61 + _t921 + _t922 + _t923 + _t924 + _t925 - _t935) + _t368*(_hc1[5]*_t12*_t301*_t61 + _t25*(_t25*(_hc1[23]*_t12*_t25*_t61 - _t936) - _t305*_t467 - _t78*_t938 - _t79*_t940 + _t895 + _t944) + (0.4e1 / 0.9e1)*_t26*_t472*_t6*_t7 - _t319*_t467 + (0.56e2 / 0.9e1)*_t4*_t469*_t87 + 0.2e1*_t465*_t77 + (0.56e2 / 0.9e1)*_t61*_t83*_t87 - _t78*(_t25*_t938 - _t315*_t467 - _t78*(_hc1[21]*_t12*_t25*_t61 - _t945) - _t79*_t947 + _t904 + _t949) - _t79*(_t25*_t940 - _t317*_t467 - _t78*_t947 - _t79*(_hc1[30]*_t12*_t25*_t61 - _t950) + _t909 + _t951) - _t955) + 0.3e1*_t458 + 0.3e1*_t475 + 0.3e1*_t858 + _t91*_t920;
  const double d4F_dna3_dgbb = _t919;
  const double d4F_dna2_dnb_dgaa = _t976;
  const double d4F_dna2_dnb_dgab = _t147*_t457 + _t191*_t448 + _t197*_t449 + _t199*_t352 + _t200*_t367 + _t207*_t673 + _t209*_t775 + _t353*(0.6e1*_t870 + 0.6e1*_t871 + 0.60e2*_t872 - _t926 - _t927 - _t928 - _t929 - _t930 - _t931 - _t932 - _t933 + _t978) + _t368*(_t134*_t948 + _t25*(_t25*_t984 + 0.2e1*_t970 + _t985) + _t308*_t469 + _t308*_t489 + _t309*_t472 + _t309*_t490 - _t363*_t467 + _t465*_t76 + _t488*_t77 - _t78*(_t25*_t982 + 0.2e1*_t967 + _t983) - _t79*(_t25*_t979 + 0.2e1*_t963 + _t981) + _t83*_t948 - _t952 - _t953 - _t954 + _t959) + _t369*_t474 + _t370*_t986 + _t371*_t987 + _t441*_t487 + _t458 + _t459*_t492 + _t475 + _t857 + _t858 + _t988;
  const double d4F_dna2_dnb_dgbb = _t976;
  const double d4F_dna_dnb2_dgaa = _t998;
  const double d4F_dna_dnb2_dgab = _t1001*_t371 + _t1002 + _t148*_t209 + _t191*_t844 + _t197*_t843 + _t199*_t376 + _t200*_t383 + _t207*_t502 + _t209*_t995 + _t242*_t503 + _t244*_t505 + _t353*(0.60e2*M_PI*_hc0[0]*_hc0[1]*_t18*_t48*_t61 + 0.6e1*_hc0[0]*_hc0[2]*_t115*_t125*_t18 + 0.6e1*_t115*_t116*_t125*_t18 - _t934 - _t978) + _t368*(-_t1000 + 0.4e1*_t11*_t37*_t488 + _t25*_t999 - 0.2e1*_t480 - 0.6e1*_t991) + _t487*_t499 + _t492*_t500 + _t504 + _t506 + _t988 + _t997;
  const double d4F_dna_dnb2_dgbb = _t998;
  const double d4F_dnb3_dgaa = _t1007;
  const double d4F_dnb3_dgab = _t1003*_t207 + _t1004*_t209 + _t1005*_t207 + _t1006*_t209 + _t150*_t920 + _t199*_t389 + _t200*_t395 + _t353*(-_t921 - _t922 - _t923 - _t924 - _t925 - _t935 + _t977) + _t368*(_hc1[5]*_t12*_t391*_t61 - _t1000 + 0.2e1*_t149*_t488 + _t54*_t999) + _t384*_t503 + _t385*_t505 + 0.3e1*_t504 + 0.3e1*_t506 + 0.3e1*_t997;
  const double d4F_dnb3_dgbb = _t1007;
  const double d4F_dna2_dgaa2 = _t1066;
  const double d4F_dna2_dgaa_dgab = _t1090;
  const double d4F_dna2_dgaa_dgbb = _t1066;
  const double d4F_dna2_dgab2 = -_t1053 + _t1054 + _t1058*_t449 - _t1060*_t449 + 0.4e1*_t1086 + _t1087*_t63 + _t1088*_t583 + _t1091 + _t1092 + _t1093*_t197 + 0.4e1*_t191*_t986 + _t353*(-_t1094 - _t1095 - _t1096 - _t1097 + _t1098 + _t1103) + _t368*(_hc1[11]*_t175*_t216*_t77 - _t1048 - _t1108*_t469 - _t1110 + (0.4e1 / 0.3e1)*_t212*_t26*_t83 + _t25*(_hc1[22]*_t175*_t216*_t25 - _t1039 - _t1106) - _t78*(_hc1[21]*_t175*_t216*_t25 - _t1045 - _t1107) - _t79*(_hc1[26]*_t175*_t216*_t25 - _t1049 - _t1109)) + _t441*_t574 - _t448*_t586 + _t457*_t582 + _t459*_t580 + _t474*_t585 + 0.2e1*_t575 + 0.2e1*_t581 - _t584*_t91;
  const double d4F_dna2_dgab_dgbb = _t1090;
  const double d4F_dna2_dgbb2 = _t1066;
  const double d4F_dna_dnb_dgaa2 = _t1130;
  const double d4F_dna_dnb_dgaa_dgab = _t1139;
  const double d4F_dna_dnb_dgaa_dgbb = _t1130;
  const double d4F_dna_dnb_dgab2 = _t1085*_t207 + 0.2e1*_t1086 + _t1089 - _t1121 + _t1123 + 0.2e1*_t1133 + _t1134*_t63 + _t1135*_t583 + _t1142 - _t137*_t584 + _t147*_t574 + _t159*_t197*_t71 + _t242*_t605 + _t244*_t607 + _t353*(-_t1099 + _t1100 - _t1101 + _t1102) + _t368*(0.2e1*_hc1[11]*_t11*_t216*_t912 - 0.2e1*_t1113 + _t1140*_t25 - _t1141) + _t369*_t580 + _t445*_t609 + _t487*_t582 + _t492*_t585 + _t575 + _t581 + _t606 + _t608 + _t609*_t987;
  const double d4F_dna_dnb_dgab_dgbb = _t1139;
  const double d4F_dna_dnb_dgbb2 = _t1130;
  const double d4F_dnb2_dgaa2 = _t1148;
  const double d4F_dnb2_dgaa_dgab = _t1151;
  const double d4F_dnb2_dgaa_dgbb = _t1148;
  const double d4F_dnb2_dgab2 = 0.4e1*_t1001*_t209 + _t1058*_t148 - _t1060*_t148 + _t1093*_t209 + _t1124 + _t1127 + 0.4e1*_t1133 - _t1144 + _t1145 + _t1149*_t63 + _t1150*_t583 - _t150*_t584 + _t353*(_t1094 + _t1095 + _t1096 + _t1097 - _t1098 + _t1103) + _t368*(_hc1[11]*_t149*_t175*_t216 + _t1140*_t54 - _t1141 - _t1143) + _t499*_t605 + _t500*_t607 - _t502*_t586 + _t503*_t582 + _t505*_t585 + 0.2e1*_t606 + 0.2e1*_t608;
  const double d4F_dnb2_dgab_dgbb = _t1151;
  const double d4F_dnb2_dgbb2 = _t1148;
  const double d4F_dna_dgaa3 = _t1216;
  const double d4F_dna_dgaa2_dgab = _t1247;
  const double d4F_dna_dgaa2_dgbb = _t1216;
  const double d4F_dna_dgaa_dgab2 = _t1263;
  const double d4F_dna_dgaa_dgab_dgbb = _t1247;
  const double d4F_dna_dgaa_dgbb2 = _t1216;
  const double d4F_dna_dgab3 = _t1064*_t626 + _t1191 + _t1194*_t1219 - _t1195*_t1273 + _t1202*_t1275 - 0.3e1*_t1230 - 0.3e1*_t1231 + 0.3e1*_t1232 - _t1236*_t663 + (0.3e1 / 0.4e1)*_t1237 - _t1261*_t642 + _t1272*_t574 + _t1274*_t197 + _t1276*_t580 + _t1277*_t197 + _t1278 + _t353*(_t1159 - _t1264 + _t1265 + _t1266 - _t1267 - _t1269) + _t368*(_hc1[21]*_t13*_t212*_t25 + 0.3e1*_hc1[5]*_t12*_t25*_t610 - _t1179*_t1270 - _t1271);
  const double d4F_dna_dgab2_dgbb = _t1263;
  const double d4F_dna_dgab_dgbb2 = _t1247;
  const double d4F_dna_dgbb3 = _t1216;
  const double d4F_dnb_dgaa3 = _t1293;
  const double d4F_dnb_dgaa2_dgab = _t1302;
  const double d4F_dnb_dgaa2_dgbb = _t1293;
  const double d4F_dnb_dgaa_dgab2 = _t1304;
  const double d4F_dnb_dgaa_dgab_dgbb = _t1302;
  const double d4F_dnb_dgaa_dgbb2 = _t1293;
  const double d4F_dnb_dgab3 = _t1219*_t1285 + _t1272*_t605 - _t1273*_t1286 + _t1274*_t209 + _t1275*_t1290 + _t1276*_t607 + _t1277*_t209 + _t1278 + _t1282 - 0.3e1*_t1295 - 0.3e1*_t1296 + 0.3e1*_t1297 - _t1299*_t663 + (0.3e1 / 0.4e1)*_t1300 - _t1303*_t642 + _t287*_t55*_t626 + _t353*(-_t1159 + _t1264 - _t1265 - _t1266 + _t1267 - _t1269) + _t368*(_hc1[21]*_t13*_t212*_t54 + 0.3e1*_hc1[5]*_t12*_t54*_t610 - _t1270*_t1279 - _t1271);
  const double d4F_dnb_dgab2_dgbb = _t1304;
  const double d4F_dnb_dgab_dgbb2 = _t1302;
  const double d4F_dnb_dgbb3 = _t1293;
  const double d4F_dgaa4 = _t1334;
  const double d4F_dgaa3_dgab = _t1343;
  const double d4F_dgaa3_dgbb = _t1334;
  const double d4F_dgaa2_dgab2 = _t1348;
  const double d4F_dgaa2_dgab_dgbb = _t1343;
  const double d4F_dgaa2_dgbb2 = _t1334;
  const double d4F_dgaa_dgab3 = _t1351;
  const double d4F_dgaa_dgab2_dgbb = _t1348;
  const double d4F_dgaa_dgab_dgbb2 = _t1343;
  const double d4F_dgaa_dgbb3 = _t1334;
  const double d4F_dgab4 = -_hc1[10]*_t22*_t299*_t610 + _t117*_t1315*_t405 + _t120*_t1315*_t406 + _t125*_t645*_t650*_t713 + _t1268*_t1319 - 0.15e2*_t1306 - 0.18e2*_t1311 + (0.15e2 / 0.2e1)*_t1312 - 0.9e1*_t1314 + _t1317*_t666 - 0.9e1 / 0.2e1*_t1318 + (0.15e2 / 0.2e1)*_t1325 - 0.9e1*_t1326 - 0.15e2*_t1329 + _t1331 + 0.30e2*_t1335 + 0.15e2*_t1342 + 0.4e1*_t1344 - _t1346*_t656 + _t1347*_t1349 + _t1350*_t64;
  const double d4F_dgab3_dgbb = _t1351;
  const double d4F_dgab2_dgbb2 = _t1348;
  const double d4F_dgab_dgbb3 = _t1343;
  const double d4F_dgbb4 = _t1334;
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