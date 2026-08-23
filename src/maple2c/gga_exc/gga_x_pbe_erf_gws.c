/*
  Generated from python/gga_exc/gga_x_pbe_erf_gws.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_pbe_erf_gws
*/

#ifndef _GGA_X_PBE_ERF_GWS_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_PBE_ERF_GWS_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#include "gga_x_pbe_erf_gws.c"
#undef _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#include "gga_x_pbe_erf_gws.c"
#undef _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#include "gga_x_pbe_erf_gws.c"
#undef _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#include "gga_x_pbe_erf_gws.c"
#undef _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#include "gga_x_pbe_erf_gws.c"
#undef _GGA_X_PBE_ERF_GWS_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_pbe_erf_gws.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_PBE_ERF_GWS_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_erf_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.1e1 / 0.3e1, _hc0);
  const double _t1 = (0.1e1 / (M_CBRTPI));
  const double _t2 = _hc0[0] + 0.1e1;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t3*p->cam_omega;
  const double _t5 = xc_powr(0.2e1, 2, 3);
  const double _t6 = _t5*rs;
  const double _t7 = (0.1e1 / rs);
  const double _t8 = (0.1e1 / M_CBRTPI);
  const double _t9 = M_CBRT3*_t8;
  const double _t12 = xc_powr(0.6e1, 1, 3);
#if _KMAX >= 1
  const double _t18 = xc_powr(0.3e1, 2, 3);
  const double _t19 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t22 = (0.1e1 / (_t2 * _t2));
  const double _t23 = _t22*p->cam_omega;
  const double _t25 = (rs * rs);
  const double _t26 = (0.1e1 / _t25);
#endif
#if _KMAX >= 2
  const double _t30 = ((_hc0[2]) * (_hc0[2]));
  const double _t32 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t33 = _t32*p->cam_omega;
  const double _t34 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t35 = (0.1e1 / M_PI);
  const double _t36 = ((p->cam_omega) * (p->cam_omega));
  const double _t47 = (rs * rs * rs);
  const double _t48 = (0.3e1 / 0.8e1)/_t47;
#endif
#if _KMAX >= 3
  const double _t58 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t62 = xc_powi(_t2, -5);
  const double _t65 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t66 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t69 = xc_powi(_t2, -6);
  const double _t74 = (0.1e1 / (rs * rs * rs * rs));
  const double _t75 = (0.9e1 / 0.8e1)*_t74;
#endif
#if _KMAX >= 4
  const double _t83 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t87 = _t25/xc_powi(_t2, 7);
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_k, _KMAX)(p, (0.1e1 / 0.6e1)*M_CBRT3*_t1*_t4*_t6, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc2);
  const double _t10 = _hc2[0]*_t9;
  const double _t11 = _t10*_t7;
  const double _t13 = _hc1[0]*_t1*_t12;
  const double _t14 = (0.3e1 / 0.16e2)*_t13;
#if _KMAX >= 1
  const double _t15 = _t14*_t9;
  const double _t16 = _t15*_t7;
  const double _t17 = _hc0[2]*_t10;
  const double _t20 = _hc1[1]*_t18*_t19;
  const double _t21 = (0.1e1 / 0.16e2)*_t20;
  const double _t24 = _t21*_t23;
  const double _t27 = _t10*_t26;
  const double _t28 = _t21*_t4;
#endif
#if _KMAX >= 2
  const double _t29 = (0.1e1 / 0.8e1)*_t20;
  const double _t31 = _t10*_t30;
  const double _t37 = _hc1[2]*_t35*_t36;
  const double _t38 = _t37*_t6;
  const double _t39 = _t34*_t38;
  const double _t40 = _t15*_t26;
  const double _t41 = (0.1e1 / 0.32e2)*_t17;
  const double _t42 = _t37*_t5;
  const double _t43 = _t32*_t42;
  const double _t44 = _hc2[1]*_t9;
  const double _t45 = _t28*_t7;
  const double _t46 = _t10*_t13;
  const double _t49 = _t22*_t42;
  const double _t50 = (0.1e1 / 0.32e2)*_t49;
#endif
#if _KMAX >= 3
  const double _t51 = _hc2[2]*_t9;
  const double _t52 = (0.3e1 / 0.16e2)*_t20;
  const double _t53 = (0.3e1 / 0.8e1)*_t20;
  const double _t54 = _t33*_t53;
  const double _t55 = _hc0[5]*_t17;
  const double _t56 = _t30*_t44;
  const double _t57 = _t10*p->cam_omega;
  const double _t59 = _t17*_t34;
  const double _t60 = _hc0[5]*_t38;
  const double _t61 = (0.3e1 / 0.32e2)*_t39;
  const double _t63 = _t10*_t58;
  const double _t64 = _t62*_t63;
  const double _t67 = _hc1[3]*_t12*_t65*_t66;
  const double _t68 = (0.1e1 / 0.96e2)*_t67;
  const double _t70 = _t34*_t42;
  const double _t71 = _t31*_t62;
  const double _t72 = _t13*_t48;
  const double _t73 = _t50*_t7;
  const double _t76 = _t10*_t48;
  const double _t77 = _t20*_t4;
  const double _t78 = (0.3e1 / 0.32e2)*_t49;
  const double _t79 = _t32*_t68;
#endif
#if _KMAX >= 4
  const double _t80 = (0.3e1 / 0.2e1)*_t20;
  const double _t81 = _t20*_t33;
  const double _t82 = _t30*_t51;
  const double _t84 = ((_hc0[5]) * (_hc0[5]))*_t10;
  const double _t85 = _t10*_t83;
  const double _t86 = (0.1e1 / 0.288e3)*_hc1[4]*_t18*((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega))/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t88 = (0.9e1 / 0.32e2)*_t70;
  const double _t89 = _t67*rs;
  const double _t90 = _t62*_t89;
#endif

  const double f = -_t11*_t14;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc2[1]*_t16 + _t17*_t24;
  out[1] = df_dz;
  const double df_drs = -_t11*_t28 + _t14*_t27;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.8e1)*M_CBRT3*_hc0[2]*_hc1[1]*_hc2[1]*_t18*_t19*_t22*_t8*p->cam_omega + (0.1e1 / 0.16e2)*M_CBRT3*_hc0[5]*_hc1[1]*_hc2[0]*_t18*_t19*_t22*_t8*p->cam_omega - _hc2[2]*_t16 - _t29*_t31*_t33 - 0.1e1 / 0.32e2*_t31*_t39;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc2[1]*_t40 + _t41*_t43 - _t44*_t45;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = (0.1e1 / 0.8e1)*M_CBRT3*_hc1[1]*_hc2[0]*_t18*_t19*_t26*_t3*_t8*p->cam_omega - _t11*_t50 - _t46*_t48;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[2]*_t23*_t51*_t52 + _hc0[5]*_t23*_t44*_t52 + _hc0[9]*_t10*_t24 - _hc2[3]*_t16 + _t25*_t63*_t68*_t69 + _t34*_t53*_t57*_t58 + (0.3e1 / 0.16e2)*_t38*_t64 - _t54*_t55 - _t54*_t56 - _t56*_t61 - 0.3e1 / 0.32e2*_t59*_t60;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = (0.1e1 / 0.16e2)*M_CBRT3*_hc0[2]*_hc1[2]*_hc2[1]*_t32*_t35*_t36*_t5*_t8 + (0.1e1 / 0.32e2)*M_CBRT3*_hc0[5]*_hc1[2]*_hc2[0]*_t32*_t35*_t36*_t5*_t8 + (0.3e1 / 0.16e2)*M_CBRT3*_hc1[0]*_hc2[2]*_t1*_t12*_t26*_t8 - 0.3e1 / 0.32e2*_t31*_t70 - _t45*_t51 - _t68*_t71*rs;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _t26*_t29*_t4*_t44 - _t44*_t72 - _t44*_t73 + _t59*_t68;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = -_t11*_t79 + _t27*_t78 + _t46*_t75 - _t76*_t77;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.1e1 / 0.16e2)*M_CBRT3*_hc0[14]*_hc1[1]*_hc2[0]*_t18*_t19*_t22*_t8*p->cam_omega + (0.1e1 / 0.4e1)*M_CBRT3*_hc0[2]*_hc1[1]*_hc2[3]*_t18*_t19*_t22*_t8*p->cam_omega + (0.9e1 / 0.4e1)*M_CBRT3*_hc0[5]*_hc1[1]*_hc2[0]*_t18*_t19*_t30*_t34*_t8*p->cam_omega + (0.3e1 / 0.8e1)*M_CBRT3*_hc0[5]*_hc1[1]*_hc2[2]*_t18*_t19*_t22*_t8*p->cam_omega + (0.9e1 / 0.8e1)*M_CBRT3*_hc0[5]*_hc1[2]*_hc2[0]*_t30*_t35*_t36*_t5*_t62*_t8*rs + (0.1e1 / 0.16e2)*M_CBRT3*_hc0[5]*_hc1[3]*_hc2[0]*_t12*_t25*_t30*_t65*_t66*_t69*_t8 + (0.1e1 / 0.4e1)*M_CBRT3*_hc0[9]*_hc1[1]*_hc2[1]*_t18*_t19*_t22*_t8*p->cam_omega + (0.3e1 / 0.2e1)*M_CBRT3*_hc1[1]*_hc2[1]*_t18*_t19*_t34*_t58*_t8*p->cam_omega + (0.3e1 / 0.4e1)*M_CBRT3*_hc1[2]*_hc2[1]*_t35*_t36*_t5*_t58*_t62*_t8*rs + (0.1e1 / 0.24e2)*M_CBRT3*_hc1[3]*_hc2[1]*_t12*_t25*_t58*_t65*_t66*_t69*_t8 - _hc0[2]*_hc0[5]*_t33*_t44*_t80 - 0.3e1 / 0.8e1*_hc0[2]*_t34*_t44*_t60 - 0.1e1 / 0.2e1*_hc0[9]*_t17*_t81 - 0.1e1 / 0.8e1*_hc0[9]*_t38*_t59 - _hc2[4]*_t16 - 0.9e1 / 0.8e1*_t38*_t69*_t85 - 0.3e1 / 0.16e2*_t39*_t82 - _t54*_t84 - _t57*_t62*_t80*_t83 - _t61*_t84 - 0.1e1 / 0.8e1*_t67*_t85*_t87 - 0.3e1 / 0.4e1*_t81*_t82 - _t47*_t85*_t86/xc_powi(_t2, 8);
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = (0.3e1 / 0.32e2)*_hc0[2]*_t43*_t51 - _hc0[5]*_t41*_t90 + (0.3e1 / 0.32e2)*_hc0[5]*_t43*_t44 + (0.1e1 / 0.32e2)*_hc0[9]*_t10*_t43 + _hc2[3]*_t40 - _hc2[3]*_t45*_t9 + (0.3e1 / 0.8e1)*_t42*_t64 - _t55*_t88 - _t56*_t88 - 0.1e1 / 0.32e2*_t56*_t90 + (0.1e1 / 0.12e2)*_t63*_t69*_t89 + _t63*_t86*_t87;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = (0.1e1 / 0.48e2)*M_CBRT3*_hc0[2]*_hc1[3]*_hc2[1]*_t12*_t34*_t65*_t66*_t8 + (0.1e1 / 0.96e2)*M_CBRT3*_hc0[5]*_hc1[3]*_hc2[0]*_t12*_t34*_t65*_t66*_t8 + (0.1e1 / 0.8e1)*M_CBRT3*_hc1[1]*_hc2[2]*_t18*_t19*_t26*_t3*_t8*p->cam_omega - _t31*_t69*_t86*rs - _t51*_t72 - _t51*_t73 - 0.1e1 / 0.24e2*_t67*_t71;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _t13*_t44*_t75 + _t17*_t62*_t86 + _t26*_t44*_t78 - _t44*_t48*_t77 - _t44*_t7*_t79;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = (0.3e1 / 0.2e1)*M_CBRT3*_hc1[1]*_hc2[0]*_t18*_t19*_t3*_t74*_t8*p->cam_omega + (0.1e1 / 0.24e2)*M_CBRT3*_hc1[3]*_hc2[0]*_t12*_t26*_t32*_t65*_t66*_t8 - _t11*_t34*_t86 - 0.9e1 / 0.2e1*_t46/xc_powi(rs, 5) - _t49*_t76;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_c1_b_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);

  const double f = 0.22e2*_t1 + 0.144e3*(x * x * x * x) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 0.576e3*(x * x * x) + 0.44e2*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.1728e4*_t1 + 0.44e2;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.3456e4*x;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0.3456e4;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_c2_b_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);
  const double _t2 = 0.72e2*_t1 - 0.7e1;

  const double f = 0.2e1*_t1*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 0.4e1*_t2*x + 0.288e3*(x * x * x);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.1728e4*_t1 - 0.28e2;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.3456e4*x;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0.3456e4;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_c3_b_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x * x * x);
  const double _t2 = (x * x);
  const double _t3 = 0.2e1*_t2 - 0.1e1;
#if _KMAX >= 1
  const double _t4 = (x * x * x);
#endif

  const double f = -0.864e3*_t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -0.3456e4*_t3*_t4 - 0.3456e4*xc_powi(x, 5);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.31104e5*_t1 - 0.10368e5*_t2*_t3;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -0.20736e5*_t3*x - 0.165888e6*_t4;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0.20736e5 - 0.622080e6*_t2;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_c4_b_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);
  const double _t2 = (x * x * x * x);
  const double _t3 = (0.1e1 / x);
  const double _t4 = xc_powr(M_PI, 1, 2)*erf((0.1e1 / 0.2e1)*_t3);
  const double _t5 = 0.8e1*_t4;
  const double _t6 = -0.24e2*_t1 + 0.32e2*_t2 + _t5*x - 0.3e1;
#if _KMAX >= 1
  const double _t7 = (x * x * x);
  const double _t8 = exp(-(0.1e1 / 0.4e1)/_t1);
  const double _t9 = _t3*_t8;
  const double _t10 = _t5 + 0.128e3*_t7 - 0.8e1*_t9 - 0.48e2*x;
#endif
#if _KMAX >= 2
  const double _t11 = _t8/_t2;
  const double _t12 = 0.384e3*_t1 - 0.4e1*_t11 - 0.48e2;
#endif
#if _KMAX >= 3
  const double _t13 = 0.16e2*_t8/xc_powi(x, 5) - 0.2e1*_t8/xc_powi(x, 7) + 0.768e3*x;
#endif

  const double f = _t1*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t1*_t10 + 0.2e1*_t6*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _t1*_t12 - 0.48e2*_t1 + 0.4e1*_t10*x + 0.64e2*_t2 + 0.16e2*_t4*x - 0.6e1;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _t1*_t13 + 0.6e1*_t12*x + 0.48e2*_t4 + 0.768e3*_t7 - 0.48e2*_t9 - 0.288e3*x;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t1*(-0.80e2*_t8/xc_powi(x, 6) + 0.22e2*_t8/xc_powi(x, 8) - _t8/xc_powi(x, 10) + 0.768e3) + 0.4608e4*_t1 - 0.48e2*_t11 + 0.8e1*_t13*x - 0.576e3;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(invexp_b_k, _KMAX)(const xc_func_type *p, double mu_t, double *out) {

  const double _t1 = 0.4e1*(mu_t * mu_t);
  const double _t2 = -0.1e1/log(XC_EPSILON);
  const double _t3 = _t1 <= _t2;
  const double _t4 = _t2 > _t1;
  const double _t5 = my_piecewise3(_t4, _t2, _t1);
  const double _t6 = exp(-0.1e1/_t5);
#if _KMAX >= 1
  const double _t7 = my_piecewise3(_t4, 0, 0.8e1*mu_t);
  const double _t8 = _t6/(_t5 * _t5);
#endif
#if _KMAX >= 2
  const double _t9 = my_piecewise3(_t4, 0, 0.8e1);
  const double _t10 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t11 = _t6*(_t7 * _t7);
  const double _t12 = _t10*_t11;
  const double _t13 = (0.1e1 / (_t5 * _t5 * _t5));
#endif
#if _KMAX >= 3
  const double _t14 = xc_powi(_t5, -6);
  const double _t15 = _t6*(_t7 * _t7 * _t7);
  const double _t16 = xc_powi(_t5, -5);
  const double _t17 = 0.6e1*_t15;
  const double _t18 = 0.3e1*_t10;
  const double _t19 = _t6*_t7*_t9;
  const double _t20 = 0.6e1*_t13;
#endif
#if _KMAX >= 4
  const double _t21 = _t6*(_t9 * _t9);
  const double _t22 = _t6*(_t7 * _t7 * _t7 * _t7);
  const double _t23 = _t11*_t9;
#endif

  const double f = my_piecewise3(_t3, 0, _t6);
  out[0] = f;
#if _KMAX >= 1
  const double df_dmu_t = my_piecewise3(_t3, 0, _t7*_t8);
  out[1] = df_dmu_t;
#endif
#if _KMAX >= 2
  const double d2f_dmu_t2 = my_piecewise3(_t3, 0, -0.2e1*_t11*_t13 + _t12 + _t8*_t9);
  out[2] = d2f_dmu_t2;
#endif
#if _KMAX >= 3
  const double d3f_dmu_t3 = my_piecewise3(_t3, 0, _t10*_t17 + _t14*_t15 - _t16*_t17 + _t18*_t19 - _t19*_t20);
  out[3] = d3f_dmu_t3;
#endif
#if _KMAX >= 4
  const double d4f_dmu_t4 = my_piecewise3(_t3, 0, 0.36e2*_t12*_t9 + 0.36e2*_t14*_t22 + 0.6e1*_t14*_t23 - 0.24e2*_t16*_t22 - 0.36e2*_t16*_t23 + _t18*_t21 - _t20*_t21 - 0.12e2*_t22/xc_powi(_t5, 7) + _t22/xc_powi(_t5, 8));
  out[4] = d4f_dmu_t4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_bb_k, _KMAX)(const xc_func_type *p, double mu_t, double ie, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_c4_b_k, _KMAX)(p, mu_t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_c3_b_k, _KMAX)(p, mu_t, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_c1_b_k, _KMAX)(p, mu_t, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_c2_b_k, _KMAX)(p, mu_t, _hc3);
  const double _t1 = -_hc2[0]*ie + _hc3[0];
  const double _t2 = 0.54e2*_hc0[0] + _hc1[0]*ie;
  const double _t3 = (0.1e1 / _t2);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (_t2 * _t2));
  const double _t5 = _t1*_t4;
  const double _t6 = -_hc2[1]*ie + _hc3[1];
  const double _t7 = _hc1[1]*ie;
  const double _t8 = -0.54e2*_hc0[1] - _t7;
#endif
#if _KMAX >= 2
  const double _t9 = _hc1[0]*_t4;
  const double _t10 = 0.2e1*_t9;
  const double _t11 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t12 = _t1*_t11;
  const double _t13 = ((_hc1[0]) * (_hc1[0]));
  const double _t14 = 0.2e1*_t13;
  const double _t15 = _hc2[0]*_t4;
  const double _t16 = 0.2e1*_t8;
  const double _t17 = _hc1[0]*_t12;
  const double _t18 = -_hc2[2]*ie + _hc3[2];
  const double _t19 = _hc1[2]*ie;
  const double _t20 = -0.54e2*_hc0[2] - _t19;
  const double _t21 = _t4*_t6;
  const double _t22 = -0.108e3*_hc0[1] - 0.2e1*_t7;
  const double _t23 = _t12*_t22;
#endif
#if _KMAX >= 3
  const double _t24 = _hc2[0]*_t11;
  const double _t25 = 0.6e1*_t13;
  const double _t26 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t27 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t28 = _t26*_t27;
  const double _t29 = 0.6e1*_t28;
  const double _t30 = 0.2e1*_hc1[1];
  const double _t31 = 0.4e1*_hc1[1];
  const double _t32 = _t11*_t14;
  const double _t33 = _t24*_t8;
  const double _t34 = 0.4e1*_hc1[0];
  const double _t35 = _t1*_t27;
  const double _t36 = _t35*_t8;
  const double _t37 = _hc2[1]*_t4;
  const double _t38 = _t11*_t6;
  const double _t39 = _t34*_t8;
  const double _t40 = 0.2e1*_t20;
  const double _t41 = _t12*_t16;
  const double _t42 = 0.3e1*_t22;
  const double _t43 = _hc1[0]*_t36;
  const double _t44 = -_hc2[3]*ie + _hc3[3];
  const double _t45 = _hc1[3]*ie;
  const double _t46 = -0.54e2*_hc0[3] - _t45;
  const double _t47 = _t4*_t8;
  const double _t48 = 0.3e1*_t18;
  const double _t49 = 0.3e1*_t21;
  const double _t50 = -0.108e3*_hc0[2] - 0.2e1*_t19;
  const double _t51 = _t12*_t50;
  const double _t52 = _t38*_t8;
  const double _t53 = -0.162e3*_hc0[1] - 0.3e1*_t7;
  const double _t54 = _t22*_t53;
#endif
#if _KMAX >= 4
  const double _t55 = _t1/xc_powi(_t2, 5);
  const double _t56 = 0.24e2*_t55;
  const double _t57 = _hc1[0]*_hc1[1];
  const double _t58 = 0.12e2*_t57;
  const double _t59 = _hc2[1]*_t11;
  const double _t60 = 0.18e2*_t13;
  const double _t61 = _hc1[1]*_t35;
  const double _t62 = _t27*_t8;
  const double _t63 = _hc2[0]*_t62;
  const double _t64 = 0.2e1*_hc1[2];
  const double _t65 = 0.8e1*_t38;
  const double _t66 = 0.4e1*_t12;
  const double _t67 = _hc1[0]*_t8;
  const double _t68 = _t22*_t24;
  const double _t69 = _hc1[0]*_t22;
  const double _t70 = 0.6e1*_t69;
  const double _t71 = 0.12e2*_t13;
  const double _t72 = _t6*_t62;
  const double _t73 = _t22*_t8;
  const double _t74 = 0.3e1*_t20;
  const double _t75 = 0.6e1*_t11*_t18;
  const double _t76 = 0.6e1*_t20;
  const double _t77 = _hc1[0]*_t76;
  const double _t78 = _hc1[1]*_t42;
  const double _t79 = _t16*_t53;
  const double _t80 = _t54*_t55;
#endif

  const double f = _t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_die = -_hc1[0]*_t5 - _hc2[0]*_t3;
  out[1] = df_die;
  const double df_dmu_t = _t3*_t6 + _t5*_t8;
  out[2] = df_dmu_t;
#endif
#if _KMAX >= 2
  const double d2f_die2 = _hc2[0]*_t10 + _t12*_t14;
  out[3] = d2f_die2;
  const double d2f_dmu_t_die = -_hc1[1]*_t5 - _hc2[1]*_t3 - _t15*_t8 - _t16*_t17 - _t6*_t9;
  out[4] = d2f_dmu_t_die;
  const double d2f_dmu_t2 = _t16*_t21 + _t18*_t3 + _t20*_t5 + _t23*_t8;
  out[5] = d2f_dmu_t2;
#endif
#if _KMAX >= 3
  const double d3f_die3 = -_t1*_t29 - _t24*_t25;
  out[6] = d3f_die3;
  const double d3f_dmu_t_die2 = _hc2[1]*_t10 + _t15*_t30 + _t17*_t31 + _t25*_t36 + _t32*_t6 + _t33*_t34;
  out[7] = d3f_dmu_t_die2;
  const double d3f_dmu_t2_die = -_hc1[1]*_t23 - _hc1[1]*_t41 - _hc1[2]*_t5 - _hc2[2]*_t3 - _t15*_t20 - _t16*_t37 - _t17*_t40 - _t18*_t9 - _t21*_t30 - _t22*_t33 - _t38*_t39 - _t42*_t43;
  out[8] = d3f_dmu_t2_die;
  const double d3f_dmu_t3 = _t20*_t49 + _t23*_t40 + _t3*_t44 + _t36*_t54 + _t42*_t52 + _t46*_t5 + _t47*_t48 + _t51*_t8;
  out[9] = d3f_dmu_t3;
#endif
#if _KMAX >= 4
  const double d4f_die4 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]))*_t56 + 0.24e2*_hc2[0]*_t28;
  out[10] = d4f_die4;
  const double d4f_dmu_t_die3 = -_t24*_t58 - _t25*_t59 - _t26*_t56*_t8 - _t29*_t6 - _t60*_t61 - _t60*_t63;
  out[11] = d4f_dmu_t_die3;
  const double d4f_dmu_t2_die2 = _hc1[0]*_hc1[2]*_t66 + ((_hc1[1]) * (_hc1[1]))*_t66 + _hc2[2]*_t10 + _t15*_t64 + _t18*_t32 + _t20*_t24*_t34 + _t20*_t25*_t35 + _t30*_t68 + _t31*_t33 + _t31*_t37 + _t36*_t58 + _t55*_t71*_t73 + _t57*_t65 + 0.8e1*_t59*_t67 + _t61*_t70 + _t63*_t70 + _t71*_t72;
  out[12] = d4f_dmu_t2_die2;
  const double d4f_dmu_t3_die = -_hc1[1]*_t4*_t48 - _hc1[1]*_t51 - 0.6e1*_hc1[1]*_t52 - _hc1[2]*_t41 - _hc1[2]*_t49 - _hc1[3]*_t5 - 0.3e1*_hc2[2]*_t47 - _hc2[3]*_t3 - _t12*_t20*_t31 - _t15*_t46 - 0.2e1*_t17*_t46 - _t22*_t35*_t77 - _t23*_t64 - _t33*_t50 - _t36*_t78 - _t37*_t74 - _t38*_t77 - _t38*_t78 - _t39*_t80 - _t40*_t68 - _t42*_t59*_t8 - 0.3e1*_t43*_t50 - _t44*_t9 - _t54*_t61 - _t54*_t63 - _t61*_t79 - _t67*_t75 - 0.9e1*_t69*_t72;
  out[13] = d4f_dmu_t3_die;
  const double d4f_dmu_t4 = _t12*_t8*(-0.108e3*_hc0[3] - 0.2e1*_t45) + _t18*_t4*_t76 + _t20*_t22*_t65 + 0.4e1*_t21*_t46 + _t22*_t36*(-0.162e3*_hc0[2] - 0.3e1*_t19) + 0.3e1*_t23*_t46 + _t3*(-_hc2[4]*ie + _hc3[4]) + _t35*_t50*_t79 + _t35*_t54*_t74 + 0.4e1*_t44*_t47 + _t5*(-0.54e2*_hc0[4] - _hc1[4]*ie) + 0.4e1*_t50*_t52 + _t51*_t74 + 0.4e1*_t54*_t72 + _t73*_t75 + _t8*_t80*(-0.216e3*_hc0[1] - 0.4e1*_t7);
  out[14] = d4f_dmu_t4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_b_k, _KMAX)(const xc_func_type *p, double mu_t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(invexp_b_k, _KMAX)(p, mu_t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pbe_x_erf_gws_bb_k, _KMAX)(p, mu_t, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = _hc0[1]*_hc1[3] + _hc1[4];
#endif
#if _KMAX >= 3
  const double _t2 = _hc0[1]*_hc1[7] + _hc1[8];
  const double _t3 = 0.2e1*_hc0[2];
  const double _t4 = _hc0[1]*_hc1[6] + _hc1[7];
  const double _t5 = _hc0[1]*_t4 + _hc0[2]*_hc1[3] + _t2;
#endif
#if _KMAX >= 4
  const double _t6 = _hc0[1]*_hc1[12] + _hc1[13];
  const double _t7 = _hc0[1]*_hc1[11] + _hc1[12];
  const double _t8 = _hc0[1]*_t7 + _hc0[2]*_hc1[7] + _t6;
#endif

  const double f = _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dmu_t = _hc0[1]*_hc1[1] + _hc1[2];
  out[1] = df_dmu_t;
#endif
#if _KMAX >= 2
  const double d2f_dmu_t2 = _hc0[1]*_hc1[4] + _hc0[1]*_t1 + _hc0[2]*_hc1[1] + _hc1[5];
  out[2] = d2f_dmu_t2;
#endif
#if _KMAX >= 3
  const double d3f_dmu_t3 = _hc0[1]*_hc1[8] + _hc0[1]*_t2 + _hc0[1]*_t5 + _hc0[2]*_hc1[4] + _hc0[3]*_hc1[1] + _hc1[9] + _t1*_t3;
  out[3] = d3f_dmu_t3;
#endif
#if _KMAX >= 4
  const double d4f_dmu_t4 = _hc0[1]*_hc1[13] + _hc0[1]*_t6 + _hc0[1]*_t8 + _hc0[1]*(_hc0[1]*(_hc0[1]*(_hc0[1]*_hc1[10] + _hc1[11]) + _hc0[2]*_hc1[6] + _t7) + _hc0[3]*_hc1[3] + _t3*_t4 + _t8) + _hc0[2]*_hc1[8] + 0.3e1*_hc0[2]*_t5 + _hc0[3]*_hc1[4] + 0.3e1*_hc0[3]*_t1 + _hc0[4]*_hc1[1] + _hc1[14] + _t2*_t3;
  out[4] = d4f_dmu_t4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_kappa_fx_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {
  const gga_x_pbe_erf_gws_params *params = (const gga_x_pbe_erf_gws_params *)(p->params);


  const double f = params->kappa;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
  const double df_drs = 0;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = 0;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = 0;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = 0;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = 0;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = 0;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = 0;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = 0;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = 0;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_b_asymp_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = xc_powi(a, -16);
  const double _t2 = xc_powi(a, -14);
  const double _t3 = xc_powi(a, -12);
  const double _t4 = xc_powi(a, -10);
  const double _t5 = xc_powi(a, -8);
  const double _t6 = xc_powi(a, -6);
  const double _t7 = (0.1e1 / (a * a * a * a));
#if _KMAX >= 1
  const double _t8 = xc_powi(a, -17);
  const double _t9 = xc_powi(a, -15);
  const double _t10 = xc_powi(a, -13);
  const double _t11 = xc_powi(a, -11);
  const double _t12 = xc_powi(a, -9);
  const double _t13 = xc_powi(a, -7);
  const double _t14 = xc_powi(a, -5);
#endif
#if _KMAX >= 2
  const double _t15 = xc_powi(a, -18);
#endif

  const double f = (0.623087515283e12 / 0.305948098151055360000000e24)*_t1 - 0.14180177569e11 / 0.74987278958592000000e20*_t2 + (0.128912159e9 / 0.14878428364800000e17)*_t3 - 0.11410897e8 / 0.42918543360000e14*_t4 + (0.12791e5 / 0.2322432000e10)*_t5 - 0.23e2 / 0.358400e6*_t6 - 0.1e1 / 0.17280e5*_t7 + (0.1e1 / 0.72e2)/(a * a);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -0.128912159e9 / 0.1239869030400000e16*_t10 + (0.11410897e8 / 0.4291854336000e13)*_t11 - 0.12791e5 / 0.290304000e9*_t12 + (0.69e2 / 0.179200e6)*_t13 + (0.1e1 / 0.4320e4)*_t14 - 0.623087515283e12 / 0.19121756134440960000000e23*_t8 + (0.14180177569e11 / 0.5356234211328000000e19)*_t9 - (0.1e1 / 0.36e2)/(a * a * a);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -0.14180177569e11 / 0.357082280755200000e18*_t1 + (0.623087515283e12 / 0.1124809184378880000000e22)*_t15 + (0.128912159e9 / 0.95374540800000e14)*_t2 - 0.11410897e8 / 0.390168576000e12*_t3 + (0.12791e5 / 0.32256000e8)*_t4 - 0.69e2 / 0.25600e5*_t5 - 0.1e1 / 0.864e3*_t6 + (0.1e1 / 0.12e2)*_t7;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = (0.11410897e8 / 0.32514048000e11)*_t10 - 0.12791e5 / 0.3225600e7*_t11 + (0.69e2 / 0.3200e4)*_t12 + (0.1e1 / 0.144e3)*_t13 - 0.1e1 / 0.3e1*_t14 + (0.14180177569e11 / 0.22317642547200000e17)*_t8 - 0.128912159e9 / 0.6812467200000e13*_t9 - (0.623087515283e12 / 0.62489399132160000000e20)/xc_powi(a, 19);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = (0.128912159e9 / 0.454164480000e12)*_t1 - 0.241063018673e12 / 0.22317642547200000e17*_t15 - 0.148341661e9 / 0.32514048000e11*_t2 + (0.140701e6 / 0.3225600e7)*_t3 - 0.621e3 / 0.3200e4*_t4 - 0.7e1 / 0.144e3*_t5 + (0.5e1 / 0.3e1)*_t6 + (0.11838662790377e14 / 0.62489399132160000000e20)/xc_powi(a, 20);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_b_smooth_k, _KMAX)(const xc_func_type *p, double mu_t, double *out) {

  const double _t1 = mu_t > 0.2e1;
  const double _t2 = mu_t >= 0.2e1;
#if _KMAX >= 1
  const double _t3 = my_piecewise3(_t1, 0.1e1, 0);
  const double _t4 = my_piecewise3(_t1, 0, 0.1e1);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_b_asymp_k, _KMAX)(p, my_piecewise3(_t1, mu_t, 0.2e1), _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(pbe_x_erf_gws_b_k, _KMAX)(p, my_piecewise3(_t1, 0.2e1, mu_t), _hc1);

  const double f = my_piecewise3(_t2, _hc0[0], _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dmu_t = my_piecewise3(_t2, _hc0[1]*_t3, _hc1[1]*_t4);
  out[1] = df_dmu_t;
#endif
#if _KMAX >= 2
  const double d2f_dmu_t2 = my_piecewise3(_t2, _hc0[2]*(_t3 * _t3), _hc1[2]*(_t4 * _t4));
  out[2] = d2f_dmu_t2;
#endif
#if _KMAX >= 3
  const double d3f_dmu_t3 = my_piecewise3(_t2, _hc0[3]*(_t3 * _t3 * _t3), _hc1[3]*(_t4 * _t4 * _t4));
  out[3] = d3f_dmu_t3;
#endif
#if _KMAX >= 4
  const double d4f_dmu_t4 = my_piecewise3(_t2, _hc0[4]*(_t3 * _t3 * _t3 * _t3), _hc1[4]*(_t4 * _t4 * _t4 * _t4));
  out[4] = d4f_dmu_t4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_b_mod_k, _KMAX)(const xc_func_type *p, double mu_t, double *out) {
  const gga_x_pbe_erf_gws_params *params = (const gga_x_pbe_erf_gws_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_b_smooth_k, _KMAX)(p, mu_t, _hc0);
  const double _t1 = (mu_t * mu_t);
  const double _t2 = exp(-_t1*params->ax);
  const double _t3 = _t2*params->b_PBE;
  const double _t4 = (0.81e2 / 0.7e1)*_t3;
#if _KMAX >= 1
  const double _t5 = _t3*params->ax;
  const double _t6 = (0.162e3 / 0.7e1)*_hc0[0]*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = _hc0[1]*_t5;
  const double _t8 = ((params->ax) * (params->ax));
  const double _t9 = _hc0[0]*_t3;
  const double _t10 = _t8*_t9;
#endif
#if _KMAX >= 3
  const double _t11 = _hc0[2]*_t5;
  const double _t12 = (mu_t * mu_t * mu_t);
  const double _t13 = ((params->ax) * (params->ax) * (params->ax));
  const double _t14 = _t13*_t9;
#endif
#if _KMAX >= 4
  const double _t15 = _hc0[1]*_t3;
#endif

  const double f = _hc0[0]*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dmu_t = (0.81e2 / 0.7e1)*_hc0[1]*_t2*params->b_PBE - _t6*mu_t;
  out[1] = df_dmu_t;
#endif
#if _KMAX >= 2
  const double d2f_dmu_t2 = _hc0[2]*_t4 + (0.324e3 / 0.7e1)*_t1*_t10 - _t6 - 0.324e3 / 0.7e1*_t7*mu_t;
  out[2] = d2f_dmu_t2;
#endif
#if _KMAX >= 3
  const double d3f_dmu_t3 = (0.972e3 / 0.7e1)*_hc0[0]*_t2*_t8*mu_t*params->b_PBE + (0.972e3 / 0.7e1)*_hc0[1]*_t1*_t2*_t8*params->b_PBE + (0.81e2 / 0.7e1)*_hc0[3]*_t2*params->b_PBE - 0.486e3 / 0.7e1*_t11*mu_t - 0.648e3 / 0.7e1*_t12*_t14 - 0.486e3 / 0.7e1*_t7;
  out[3] = d3f_dmu_t3;
#endif
#if _KMAX >= 4
  const double d4f_dmu_t4 = (0.1944e4 / 0.7e1)*_hc0[2]*_t1*_t3*_t8 - 0.648e3 / 0.7e1*_hc0[3]*_t5*mu_t + _hc0[4]*_t4 - 0.3888e4 / 0.7e1*_t1*_t14 + (0.972e3 / 0.7e1)*_t10 - 0.972e3 / 0.7e1*_t11 - 0.2592e4 / 0.7e1*_t12*_t13*_t15 + (0.3888e4 / 0.7e1)*_t15*_t8*mu_t + (0.1296e4 / 0.7e1)*_t9*(mu_t * mu_t * mu_t * mu_t)*((params->ax) * (params->ax) * (params->ax) * (params->ax));
  out[4] = d4f_dmu_t4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(nu_2_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.1e1 / 0.3e1, _hc0);
  const double _t1 = _hc0[0] + 0.1e1;
  const double _t2 = xc_powr(0.12e2, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3*p->cam_omega;
  const double _t5 = (0.1e1 / 0.6e1)*_t4;
  const double _t6 = _t5/_t1;
#if _KMAX >= 1
  const double _t7 = _t5/(_t1 * _t1);
  const double _t8 = _hc0[2]*_t7;
#endif
#if _KMAX >= 2
  const double _t9 = _hc0[5]*_t7;
  const double _t10 = ((_hc0[2]) * (_hc0[2]));
  const double _t11 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t12 = _t11*_t4;
  const double _t13 = (0.1e1 / 0.3e1)*_t10*_t12;
#endif
#if _KMAX >= 3
  const double _t14 = _hc0[9]*_t7;
  const double _t15 = _t4/(_t1 * _t1 * _t1 * _t1);
  const double _t16 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t15;
#endif
#if _KMAX >= 4
  const double _t17 = _t12*rs;
#endif

  const double f = _t6*rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_t8*rs;
  out[1] = df_dz;
  const double df_drs = _t6;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t13*rs - _t9*rs;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = -_t8;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = 0;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[2]*_hc0[5]*_t11*_t2*_t3*p->cam_omega*rs - _t14*rs - _t16*rs;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _t13 - _t9;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = 0;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = 0;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_hc0[14]*_t7*rs + 0.4e1*((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t4*rs/xc_powi(_t1, 5) + (0.4e1 / 0.3e1)*_hc0[2]*_hc0[9]*_t17 + ((_hc0[5]) * (_hc0[5]))*_t17 - 0.6e1*_hc0[5]*_t10*_t15*rs;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc0[2]*_hc0[5]*_t11*_t2*_t3*p->cam_omega - _t14 - _t16;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = 0;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = 0;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_Fx_k, _KMAX)(const xc_func_type *p, double rs, double z, double s, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(nu_2_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_b_mod_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pbe_x_erf_gws_kappa_fx_k, _KMAX)(p, 0, 0, _hc2);
  const double _t1 = (s * s);
  const double _t2 = _hc1[0]*_t1;
  const double _t3 = _hc2[0] + _t2;
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (_t3 * _t3));
  const double _t5 = ((_hc2[0]) * (_hc2[0]));
  const double _t6 = _t4*_t5;
  const double _t7 = _hc1[1]*_t1;
  const double _t8 = _t6*_t7;
#endif
#if _KMAX >= 2
  const double _t9 = ((_hc1[0]) * (_hc1[0]));
  const double _t10 = _t5*_t9;
  const double _t11 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t12 = 0.8e1*_t11;
  const double _t13 = (s * s * s);
  const double _t14 = 0.4e1*_hc1[0]*_t13;
  const double _t15 = _hc2[0]*_t11;
  const double _t16 = _hc0[1]*_hc1[1];
  const double _t17 = _t15*_t16;
  const double _t18 = ((_hc0[1]) * (_hc0[1]));
  const double _t19 = ((_hc1[1]) * (_hc1[1]));
  const double _t20 = _t18*_t19;
  const double _t21 = (s * s * s * s);
  const double _t22 = _t15*_t21;
  const double _t23 = 0.2e1*_t22;
  const double _t24 = _hc0[3]*_t7;
  const double _t25 = _hc1[2]*_t18;
  const double _t26 = _t1*_t25;
  const double _t27 = -_t24 - _t26;
  const double _t28 = _hc2[0]*_t4;
  const double _t29 = _hc0[2]*_hc1[1];
  const double _t30 = _t14*_t15;
  const double _t31 = _hc0[1]*_hc0[2];
  const double _t32 = _t19*_t31;
  const double _t33 = _hc0[4]*_t7;
  const double _t34 = _hc1[2]*_t1;
  const double _t35 = _t31*_t34;
  const double _t36 = -_t33 - _t35;
  const double _t37 = ((_hc0[2]) * (_hc0[2]));
  const double _t38 = _t19*_t37;
#endif
#if _KMAX >= 3
  const double _t39 = 0.24e2*_t11;
  const double _t40 = _t10*_t39;
  const double _t41 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t42 = _t13*_t41;
  const double _t43 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t44 = 0.2e1*_hc1[1];
  const double _t45 = _t28*_t44;
  const double _t46 = 0.20e2*_t2;
  const double _t47 = _hc2[0]*_t41;
  const double _t48 = _t21*_t47;
  const double _t49 = 0.24e2*_t48;
  const double _t50 = _hc2[0]*_t20;
  const double _t51 = _t12*_t13;
  const double _t52 = _t41*_t50;
  const double _t53 = xc_powi(s, 5);
  const double _t54 = 0.12e2*_hc1[0];
  const double _t55 = _t53*_t54;
  const double _t56 = _hc0[3]*_t44;
  const double _t57 = 0.2e1*_t25;
  const double _t58 = -_t56*s - _t57*s;
  const double _t59 = _t15*_t27;
  const double _t60 = 0.4e1*s;
  const double _t61 = _hc1[0]*_t60;
  const double _t62 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t63 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t64 = _t47*_t63;
  const double _t65 = _t62*_t64;
  const double _t66 = xc_powi(s, 6);
  const double _t67 = 0.6e1*_t66;
  const double _t68 = _t15*_t7;
  const double _t69 = -0.2e1*_t24 - 0.2e1*_t26;
  const double _t70 = _hc0[1]*_t69;
  const double _t71 = 0.4e1*_hc0[1]*_t7;
  const double _t72 = _hc0[6]*_t7;
  const double _t73 = _hc1[3]*_t1;
  const double _t74 = _t62*_t73;
  const double _t75 = 0.3e1*_t34;
  const double _t76 = _hc0[1]*_hc0[3];
  const double _t77 = -_t72 - _t74 - _t75*_t76;
  const double _t78 = _t15*_t29;
  const double _t79 = _hc2[0]*_t32;
  const double _t80 = _t47*_t55;
  const double _t81 = _hc0[4]*_t44;
  const double _t82 = 0.2e1*s;
  const double _t83 = _hc1[2]*_t31;
  const double _t84 = -_t81*s - _t82*_t83;
  const double _t85 = _t15*_t36;
  const double _t86 = _hc0[2]*_t18;
  const double _t87 = _t64*_t67;
  const double _t88 = _hc0[2]*_t68;
  const double _t89 = _hc0[7]*_t7;
  const double _t90 = _hc0[2]*_t34;
  const double _t91 = _hc0[3]*_t90;
  const double _t92 = 0.2e1*_t34;
  const double _t93 = _hc0[1]*_hc0[4];
  const double _t94 = _t18*_t73;
  const double _t95 = _hc0[2]*_t94;
  const double _t96 = -_t89 - _t91 - _t92*_t93 - _t95;
  const double _t97 = _hc1[2]*_t82;
  const double _t98 = _hc1[2]*_t15*_t37;
  const double _t99 = _hc2[0]*_t38;
  const double _t100 = _hc0[1]*_t37;
  const double _t101 = _t22*_t44;
  const double _t102 = 0.2e1*_t90;
  const double _t103 = _t37*_t73;
  const double _t104 = _hc0[1]*_t103;
  const double _t105 = -_hc0[4]*_t102 - _t104;
  const double _t106 = -0.2e1*_t33 - 0.2e1*_t35;
  const double _t107 = 0.2e1*_t85;
  const double _t108 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t109 = 0.6e1*_t22;
  const double _t110 = _hc1[1]*_hc1[2];
  const double _t111 = _t108*_t110;
#endif
#if _KMAX >= 4
  const double _t112 = xc_powi(_t3, -5);
  const double _t113 = 0.48e2*_hc1[0]*s;
  const double _t114 = _hc2[0]*_t112;
  const double _t115 = 0.192e3*_t114*_t43*_t53;
  const double _t116 = _t1*_t39;
  const double _t117 = 0.96e2*_t112*_t66*_t9;
  const double _t118 = 0.24e2*_hc2[0];
  const double _t119 = _t118*_t27;
  const double _t120 = _t1*_t41*_t9;
  const double _t121 = 0.36e2*_t53;
  const double _t122 = 0.48e2*_hc1[0]*_t114*_t63*xc_powi(s, 7);
  const double _t123 = _hc1[1]*_t60;
  const double _t124 = -_hc0[3]*_t123 - _t25*_t60;
  const double _t125 = _hc0[1]*_t68;
  const double _t126 = 0.4e1*_t125;
  const double _t127 = _t44*s;
  const double _t128 = 0.6e1*_t76;
  const double _t129 = _hc1[3]*_t82;
  const double _t130 = _t127*_t15;
  const double _t131 = _hc2[0]*_t12;
  const double _t132 = _t131*_t16*s;
  const double _t133 = _hc2[0]*_t42;
  const double _t134 = _hc1[0]*_t133;
  const double _t135 = 0.6e1*_t134;
  const double _t136 = _hc1[0]*_t16*_t42;
  const double _t137 = _t15*_t61;
  const double _t138 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t139 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t112*_t118*xc_powi(s, 8);
  const double _t140 = _t21*_t52;
  const double _t141 = -0.6e1*_t24 - 0.6e1*_t26;
  const double _t142 = 0.6e1*_t69;
  const double _t143 = 0.18e2*_t140;
  const double _t144 = -_t128*_t34 - 0.2e1*_t72 - 0.2e1*_t74;
  const double _t145 = 0.3e1*_t69;
  const double _t146 = _hc1[4]*_t1;
  const double _t147 = 0.4e1*_t34;
  const double _t148 = _t118*_t36;
  const double _t149 = _t121*_t64;
  const double _t150 = _hc0[2]*_t130;
  const double _t151 = _hc1[2]*_t60;
  const double _t152 = _hc0[2]*_t62;
  const double _t153 = _t32*_t48;
  const double _t154 = _t31*_t73;
  const double _t155 = 0.3e1*_hc0[4];
  const double _t156 = _t100*_t110;
  const double _t157 = _t18*_t37;
  const double _t158 = _t38*_t48;
  const double _t159 = 0.4e1*_hc0[4];
  const double _t160 = _hc0[1]*_t108;
  const double _t161 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
#endif

  const double f = _hc2[0]*(-_hc2[0]/_t3 + 0.1e1) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = 0.2e1*_hc1[0]*_t6*s;
  out[1] = df_ds;
  const double df_dz = _hc0[1]*_t8;
  out[2] = df_dz;
  const double df_drs = _hc0[2]*_t8;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = 0.2e1*_hc1[0]*_t4*_t5 - _t1*_t10*_t12;
  out[4] = d2f_ds2;
  const double d2f_dz_ds = _hc2[0]*(0.2e1*_hc0[1]*_hc1[1]*_hc2[0]*_t4*s - _t14*_t17);
  out[5] = d2f_dz_ds;
  const double d2f_dz2 = _hc2[0]*(-_t20*_t23 - _t27*_t28);
  out[6] = d2f_dz2;
  const double d2f_drs_ds = _hc2[0]*(0.2e1*_hc0[2]*_hc1[1]*_hc2[0]*_t4*s - _t29*_t30);
  out[7] = d2f_drs_ds;
  const double d2f_drs_dz = _hc2[0]*(-_t23*_t32 - _t28*_t36);
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc2[0]*(_hc1[2]*_hc2[0]*_t1*_t37*_t4 - _t23*_t38);
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = -_t40*s + 0.48e2*_t42*_t43*_t5;
  out[10] = d3f_ds3;
  const double d3f_dz_ds2 = _hc2[0]*(_hc0[1]*_t45 + _t16*_t49*_t9 - _t17*_t46);
  out[11] = d3f_dz_ds2;
  const double d3f_dz2_ds = _hc2[0]*(-_t28*_t58 - _t50*_t51 + _t52*_t55 + _t59*_t61);
  out[12] = d3f_dz2_ds;
  const double d3f_dz3 = _hc2[0]*(-_t28*_t77 + _t59*_t71 + _t65*_t67 + _t68*_t70);
  out[13] = d3f_dz3;
  const double d3f_drs_ds2 = _hc2[0]*(_hc0[2]*_t45 + _t29*_t49*_t9 - _t46*_t78);
  out[14] = d3f_drs_ds2;
  const double d3f_drs_dz_ds = _hc2[0]*(-_t28*_t84 + _t32*_t80 - _t51*_t79 + _t61*_t85);
  out[15] = d3f_drs_dz_ds;
  const double d3f_drs_dz2 = _hc2[0]*(-_t28*_t96 + _t69*_t88 + _t71*_t85 + _t86*_t87);
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_ds = _hc2[0]*(-_t14*_t98 + _t28*_t37*_t97 + _t38*_t80 - _t51*_t99);
  out[17] = d3f_drs2_ds;
  const double d3f_drs2_dz = _hc2[0]*(_hc0[2]*_t107*_t7 - _hc1[2]*_t100*_t101 + _t100*_t87 - _t105*_t28 + _t106*_t88);
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc2[0]*(_t108*_t28*_t73 + _t108*_t64*_t67 - _t109*_t111);
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = -0.384e3*((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]))*_t112*_t21*_t5 + 0.288e3*_t1*_t41*_t43*_t5 - _t40;
  out[20] = d4f_ds4;
  const double d4f_dz_ds3 = _hc2[0]*(0.216e3*_hc0[1]*_hc1[1]*_hc2[0]*_t13*_t41*_t9 - _t113*_t17 - _t115*_t16);
  out[21] = d4f_dz_ds3;
  const double d4f_dz2_ds2 = _hc2[0]*(0.4e1*_hc1[0]*_hc2[0]*_t11*_t27 + 0.8e1*_hc1[0]*_hc2[0]*_t11*_t58*s + 0.108e3*_hc1[0]*_hc2[0]*_t18*_t19*_t21*_t41 - _t116*_t50 - _t117*_t50 - _t119*_t120 - _t28*(-_t56 - _t57));
  out[22] = d4f_dz2_ds2;
  const double d4f_dz3_ds = _hc2[0]*(-_hc1[1]*_t135*_t70 - _t119*_t136 + _t121*_t65 - _t122*_t62 + _t124*_t125 + _t126*_t58 + _t130*_t70 + _t132*_t27 + _t137*_t77 - _t28*(-_hc0[6]*_t127 - _hc1[2]*_t128*s - _t129*_t62));
  out[23] = d4f_dz3_ds;
  const double d4f_dz4 = _hc2[0]*(_hc0[1]*_hc1[1]*_hc2[0]*_t1*_t11*_t144 + 0.6e1*_hc0[1]*_hc1[1]*_hc2[0]*_t1*_t11*_t77 - _t138*_t139 - _t140*_t141 - _t140*_t142 - _t143*_t27 - _t145*_t59 - _t28*(-_hc0[1]*_hc0[6]*_t147 - _hc0[10]*_t7 - ((_hc0[3]) * (_hc0[3]))*_t75 - 0.6e1*_hc0[3]*_t94 - _t138*_t146));
  out[24] = d4f_dz4;
  const double d4f_drs_ds3 = _hc2[0]*(0.216e3*_hc0[2]*_hc1[1]*_hc2[0]*_t13*_t41*_t9 - _t113*_t78 - _t115*_t29);
  out[25] = d4f_drs_ds3;
  const double d4f_drs_dz_ds2 = _hc2[0]*(0.108e3*_hc0[1]*_hc0[2]*_hc1[0]*_hc2[0]*_t19*_t21*_t41 + 0.4e1*_hc1[0]*_hc2[0]*_t11*_t36 + 0.8e1*_hc1[0]*_hc2[0]*_t11*_t84*s - _t116*_t79 - _t117*_t79 - _t120*_t148 - _t28*(-_t81 - 0.2e1*_t83));
  out[26] = d4f_drs_dz_ds2;
  const double d4f_drs_dz2_ds = _hc2[0]*(-_t122*_t86 + _t124*_t88 + _t126*_t84 + _t132*_t36 - _t134*_t142*_t29 - _t136*_t148 + _t137*_t96 + _t149*_t86 + _t150*_t69 - _t28*(-_hc0[2]*_hc0[3]*_t97 - _hc0[7]*_t127 - _t129*_t86 - _t151*_t93));
  out[27] = d4f_drs_dz2_ds;
  const double d4f_drs_dz3 = _hc2[0]*(0.6e1*_hc0[1]*_hc1[1]*_hc2[0]*_t1*_t11*_t96 + _hc0[2]*_hc1[1]*_hc2[0]*_t1*_t11*_t144 - _t139*_t152 - _t141*_t153 - _t142*_t153 - _t143*_t36 - _t145*_t85 - _t28*(-_hc0[1]*_hc0[7]*_t75 - _hc0[11]*_t7 - _hc0[3]*_hc0[4]*_t75 - 0.3e1*_hc0[3]*_t154 - _hc0[6]*_t90 - _t146*_t152 - _t155*_t94));
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_ds2 = _hc2[0]*(0.108e3*_hc1[0]*_hc2[0]*_t19*_t21*_t37*_t41 + 0.24e2*_hc1[2]*_hc2[0]*_t21*_t37*_t41*_t9 + 0.2e1*_hc1[2]*_hc2[0]*_t37*_t4 - _t116*_t99 - _t117*_t99 - _t46*_t98);
  out[29] = d4f_drs2_ds2;
  const double d4f_drs2_dz_ds = _hc2[0]*(_hc0[2]*_t123*_t85 - _hc2[0]*_t156*_t51 - _t100*_t122 + _t100*_t149 + _t105*_t137 - _t106*_t135*_t29 + _t106*_t150 - _t133*_t29*_t36*_t54 + _t156*_t80 - _t28*(-_hc0[2]*_hc0[4]*_t151 - _t100*_t129) + 0.2e1*_t84*_t88 + _t88*(-_hc0[4]*_t123 - _t60*_t83));
  out[30] = d4f_drs2_dz_ds;
  const double d4f_drs2_dz2 = _hc2[0]*(0.4e1*_hc0[1]*_hc1[1]*_hc2[0]*_t1*_t105*_t11 + 0.2e1*_hc0[2]*_hc1[1]*_hc2[0]*_t1*_t11*_t96 + _hc0[2]*_hc1[1]*_hc2[0]*_t1*_t11*(-_t147*_t93 - 0.2e1*_t89 - 0.2e1*_t91 - 0.2e1*_t95) + _hc1[2]*_hc2[0]*_t1*_t11*_t37*_t69 + 0.6e1*_hc1[2]*_hc2[0]*_t18*_t19*_t37*_t41*_t66 - _t106*_t107 - 0.6e1*_t106*_t153 - _t139*_t157 - _t141*_t158 - 0.12e2*_t153*_t36 - _t28*(-_hc0[3]*_t103 - ((_hc0[4]) * (_hc0[4]))*_t92 - _hc0[7]*_t102 - _t146*_t157 - _t154*_t159));
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_ds = _hc2[0]*(0.36e2*_hc1[0]*_hc1[1]*_hc1[2]*_hc2[0]*_t108*_t41*_t53 + 0.2e1*_hc1[3]*_hc2[0]*_t108*_t4*s - _hc1[3]*_t108*_t30 + 0.36e2*_hc2[0]*_t108*_t41*_t53*_t63 - _hc2[0]*_t111*_t13*_t39 - _t108*_t122);
  out[32] = d4f_drs3_ds;
  const double d4f_drs3_dz = _hc2[0]*(0.18e2*_hc0[1]*_hc1[2]*_hc2[0]*_t108*_t19*_t41*_t66 + 0.4e1*_hc0[2]*_hc1[1]*_hc2[0]*_t1*_t105*_t11 + _hc0[2]*_hc1[1]*_hc2[0]*_t1*_t11*(-0.2e1*_t104 - _t159*_t90) + 0.2e1*_hc1[2]*_hc2[0]*_t1*_t106*_t11*_t37 + 0.2e1*_hc1[2]*_hc2[0]*_t1*_t11*_t36*_t37 - _hc1[3]*_t101*_t160 - 0.3e1*_t106*_t158 - _t139*_t160 - 0.6e1*_t158*_t36 - 0.2e1*_t158*(-0.3e1*_t33 - 0.3e1*_t35) - _t28*(-_t103*_t155 - _t146*_t160));
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = _hc2[0]*(-_hc1[1]*_hc1[3]*_t131*_t161*_t21 - ((_hc1[2]) * (_hc1[2]))*_t109*_t161 + 0.36e2*_hc1[2]*_hc2[0]*_t161*_t19*_t41*_t66 + _hc1[4]*_hc2[0]*_t1*_t161*_t4 - _t139*_t161);
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_x_erf_gws_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double xs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_x_erf_spin_k, _KMAX)(p, rs, z, _hc0);
  const double _t1 = xc_powr(0.6e1, 2, 3);
  const double _t2 = _t1/(M_CBRTPI * M_CBRTPI);
  const double _t3 = (0.1e1 / 0.12e2)*_t2;
#if _KMAX >= 1
  const double _t4 = _hc0[0]*_t3;
#endif
#if _KMAX >= 2
  const double _t5 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t6 = (0.1e1 / 0.24e2)*_t5;
  const double _t7 = _hc0[0]*_t6;
  const double _t9 = 0.2e1*_hc0[1];
  const double _t10 = 0.2e1*_hc0[2];
#endif
#if _KMAX >= 3
  const double _t11 = (0.1e1 / (M_PI * M_PI));
  const double _t12 = (0.1e1 / 0.48e2)*_hc0[0]*_t11;
  const double _t14 = (0.1e1 / 0.6e1)*_t2;
  const double _t15 = _hc0[1]*_t14;
  const double _t16 = 0.3e1*_hc0[1];
  const double _t17 = 0.3e1*_hc0[3];
  const double _t19 = _hc0[2]*_t3;
  const double _t20 = 0.2e1*_hc0[4];
  const double _t21 = _hc0[2]*_t14;
  const double _t22 = 0.3e1*_hc0[2];
  const double _t23 = 0.3e1*_hc0[5];
#endif
#if _KMAX >= 4
  const double _t25 = (0.1e1 / 0.12e2)*_t5;
  const double _t26 = (0.1e1 / 0.4e1)*_t2;
  const double _t27 = _hc0[4]*_t14;
  const double _t28 = 0.3e1*_hc0[4];
#endif
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(pbe_x_erf_gws_Fx_k, _KMAX)(p, rs, z, _t3*xs, _hc1);
#if _KMAX >= 2
  const double _t8 = _hc1[1]*_t3;
#endif
#if _KMAX >= 3
  const double _t13 = _hc1[4]*_t6;
  const double _t18 = _hc1[7]*_t3;
#endif
#if _KMAX >= 4
  const double _t24 = (0.1e1 / 0.48e2)*_hc1[10]*_t11;
#endif

  const double f = _hc0[0]*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs = _hc1[1]*_t4;
  out[1] = df_dxs;
  const double df_dz = _hc0[0]*_hc1[2] + _hc0[1]*_hc1[0];
  out[2] = df_dz;
  const double df_drs = _hc0[0]*_hc1[3] + _hc0[2]*_hc1[0];
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs2 = _hc1[4]*_t7;
  out[4] = d2f_dxs2;
  const double d2f_dz_dxs = _hc0[1]*_t8 + _hc1[5]*_t4;
  out[5] = d2f_dz_dxs;
  const double d2f_dz2 = _hc0[0]*_hc1[6] + _hc0[3]*_hc1[0] + _hc1[2]*_t9;
  out[6] = d2f_dz2;
  const double d2f_drs_dxs = _hc0[2]*_t8 + _hc1[7]*_t4;
  out[7] = d2f_drs_dxs;
  const double d2f_drs_dz = _hc0[0]*_hc1[8] + _hc0[1]*_hc1[3] + _hc0[2]*_hc1[2] + _hc0[4]*_hc1[0];
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[0]*_hc1[9] + _hc0[5]*_hc1[0] + _hc1[3]*_t10;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs3 = _hc1[10]*_t12;
  out[10] = d3f_dxs3;
  const double d3f_dz_dxs2 = _hc0[1]*_t13 + _hc1[11]*_t7;
  out[11] = d3f_dz_dxs2;
  const double d3f_dz2_dxs = _hc0[3]*_t8 + _hc1[12]*_t4 + _hc1[5]*_t15;
  out[12] = d3f_dz2_dxs;
  const double d3f_dz3 = _hc0[0]*_hc1[13] + _hc0[6]*_hc1[0] + _hc1[2]*_t17 + _hc1[6]*_t16;
  out[13] = d3f_dz3;
  const double d3f_drs_dxs2 = _hc0[2]*_t13 + _hc1[14]*_t7;
  out[14] = d3f_drs_dxs2;
  const double d3f_drs_dz_dxs = _hc0[1]*_t18 + _hc0[4]*_t8 + _hc1[15]*_t4 + _hc1[5]*_t19;
  out[15] = d3f_drs_dz_dxs;
  const double d3f_drs_dz2 = _hc0[0]*_hc1[16] + _hc0[2]*_hc1[6] + _hc0[3]*_hc1[3] + _hc0[7]*_hc1[0] + _hc1[2]*_t20 + _hc1[8]*_t9;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dxs = _hc0[5]*_t8 + _hc1[17]*_t4 + _hc1[7]*_t21;
  out[17] = d3f_drs2_dxs;
  const double d3f_drs2_dz = _hc0[0]*_hc1[18] + _hc0[1]*_hc1[9] + _hc0[5]*_hc1[2] + _hc0[8]*_hc1[0] + _hc1[3]*_t20 + _hc1[8]*_t10;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[0]*_hc1[19] + _hc0[9]*_hc1[0] + _hc1[3]*_t23 + _hc1[9]*_t22;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs4 = (0.1e1 / 0.576e3)*_hc0[0]*_hc1[20]*_t1/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  out[20] = d4f_dxs4;
  const double d4f_dz_dxs3 = _hc0[1]*_t24 + _hc1[21]*_t12;
  out[21] = d4f_dz_dxs3;
  const double d4f_dz2_dxs2 = _hc0[1]*_hc1[11]*_t25 + _hc0[3]*_t13 + _hc1[22]*_t7;
  out[22] = d4f_dz2_dxs2;
  const double d4f_dz3_dxs = _hc0[1]*_hc1[12]*_t26 + _hc0[3]*_hc1[5]*_t26 + _hc0[6]*_t8 + _hc1[23]*_t4;
  out[23] = d4f_dz3_dxs;
  const double d4f_dz4 = _hc0[0]*_hc1[24] + 0.4e1*_hc0[1]*_hc1[13] + _hc0[10]*_hc1[0] + 0.6e1*_hc0[3]*_hc1[6] + 0.4e1*_hc0[6]*_hc1[2];
  out[24] = d4f_dz4;
  const double d4f_drs_dxs3 = _hc0[2]*_t24 + _hc1[25]*_t12;
  out[25] = d4f_drs_dxs3;
  const double d4f_drs_dz_dxs2 = _hc0[1]*_hc1[14]*_t6 + _hc0[2]*_hc1[11]*_t6 + _hc0[4]*_t13 + _hc1[26]*_t7;
  out[26] = d4f_drs_dz_dxs2;
  const double d4f_drs_dz2_dxs = _hc0[3]*_t18 + _hc0[7]*_t8 + _hc1[12]*_t19 + _hc1[15]*_t15 + _hc1[27]*_t4 + _hc1[5]*_t27;
  out[27] = d4f_drs_dz2_dxs;
  const double d4f_drs_dz3 = _hc0[0]*_hc1[28] + _hc0[11]*_hc1[0] + _hc0[2]*_hc1[13] + _hc0[6]*_hc1[3] + 0.3e1*_hc0[7]*_hc1[2] + _hc1[16]*_t16 + _hc1[6]*_t28 + _hc1[8]*_t17;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dxs2 = _hc0[2]*_hc1[14]*_t25 + _hc0[5]*_t13 + _hc1[29]*_t7;
  out[29] = d4f_drs2_dxs2;
  const double d4f_drs2_dz_dxs = _hc0[1]*_hc1[17]*_t3 + _hc0[5]*_hc1[5]*_t3 + _hc0[8]*_t8 + _hc1[15]*_t21 + _hc1[30]*_t4 + _hc1[7]*_t27;
  out[30] = d4f_drs2_dz_dxs;
  const double d4f_drs2_dz2 = _hc0[0]*_hc1[31] + _hc0[12]*_hc1[0] + _hc0[3]*_hc1[9] + 0.4e1*_hc0[4]*_hc1[8] + _hc0[5]*_hc1[6] + 0.2e1*_hc0[7]*_hc1[3] + 0.2e1*_hc0[8]*_hc1[2] + _hc1[16]*_t10 + _hc1[18]*_t9;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dxs = _hc0[2]*_hc1[17]*_t26 + _hc0[5]*_hc1[7]*_t26 + _hc0[9]*_t8 + _hc1[32]*_t4;
  out[32] = d4f_drs3_dxs;
  const double d4f_drs3_dz = _hc0[0]*_hc1[33] + _hc0[1]*_hc1[19] + _hc0[13]*_hc1[0] + 0.3e1*_hc0[8]*_hc1[3] + _hc0[9]*_hc1[2] + _hc1[18]*_t22 + _hc1[8]*_t23 + _hc1[9]*_t28;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[0]*_hc1[34] + _hc0[14]*_hc1[0] + 0.4e1*_hc0[2]*_hc1[19] + 0.6e1*_hc0[5]*_hc1[9] + 0.4e1*_hc0[9]*_hc1[3];
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_erf_spin_z1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (0.1e1 / (M_CBRTPI));
  const double _t2 = xc_expm1((0.1e1 / 0.3e1)*xc_log1p(0.1e1)) + 0.1e1;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t3*p->cam_omega;
  const double _t5 = xc_powr(0.2e1, 2, 3);
  const double _t6 = M_CBRT3;
  const double _t7 = _t5*_t6;
  const double _t8 = (0.1e1 / M_CBRTPI);
  const double _t9 = M_CBRT3*_t8;
  const double _t10 = _t9/rs;
#if _KMAX >= 1
  const double _t13 = (0.1e1 / (rs * rs));
  const double _t14 = _t13*_t9;
  const double _t15 = (0.1e1 / 0.8e1)*_t10;
  const double _t16 = xc_powr(0.18e2, 1, 3);
  const double _t17 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
#endif
#if _KMAX >= 2
  const double _t20 = (0.1e1 / (rs * rs * rs));
  const double _t21 = (0.3e1 / 0.4e1)*_t20;
#endif
#if _KMAX >= 3
  const double _t23 = (0.1e1 / (rs * rs * rs * rs));
  const double _t24 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t25 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t26 = (0.1e1 / (_t2 * _t2 * _t2));
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_k, _KMAX)(p, (0.1e1 / 0.6e1)*_t1*_t4*_t7*rs, _hc0);
  const double _t11 = xc_powr(0.12e2, 1, 3)*_hc0[0]*_t1;
  const double _t12 = (0.3e1 / 0.8e1)*_t11;
#if _KMAX >= 1
  const double _t18 = _hc0[1]*_t16*_t17*_t4;
#endif
#if _KMAX >= 2
  const double _t19 = _t11*_t9;
  const double _t22 = _hc0[2]*((p->cam_omega) * (p->cam_omega))/(M_PI*(_t2 * _t2));
#endif

  const double f = -_t10*_t12;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t12*_t14 - _t15*_t18;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (0.1e1 / 0.4e1)*M_CBRT3*_hc0[1]*_t13*_t16*_t17*_t3*_t8*p->cam_omega - _t15*_t22 - _t19*_t21;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.1e1 / 0.48e2*_hc0[3]*_t10*_t24*_t25*_t26*_t7 + (0.3e1 / 0.8e1)*_t14*_t22 - _t18*_t21*_t9 + (0.9e1 / 0.4e1)*_t19*_t23;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.3e1*M_CBRT3*_hc0[1]*_t16*_t17*_t23*_t3*_t8*p->cam_omega + (0.1e1 / 0.12e2)*M_CBRT3*_hc0[3]*_t13*_t24*_t25*_t26*_t5*_t6*_t8 - 0.1e1 / 0.144e3*M_CBRT2*xc_powr(0.3e1, 2, 3)*_hc0[4]*_t10*((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega))/((M_PI * M_CBRTPI * M_CBRTPI)*(_t2 * _t2 * _t2 * _t2)) - 0.9e1*_t19/xc_powi(rs, 5) - 0.3e1 / 0.2e1*_t20*_t22*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(nu_2_z1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (0.1e1 / 0.6e1)*xc_powr(0.12e2, 1, 3)*p->cam_omega/(M_CBRTPI*(xc_expm1((0.1e1 / 0.3e1)*xc_log1p(0.1e1)) + 0.1e1));

  const double f = _t1*rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t1;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_kappa_fx_z1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const gga_x_pbe_erf_gws_params *params = (const gga_x_pbe_erf_gws_params *)(p->params);


  const double f = params->kappa;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pbe_x_erf_gws_Fx_z1_k, _KMAX)(const xc_func_type *p, double rs, double s, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(nu_2_z1_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_b_mod_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pbe_x_erf_gws_kappa_fx_z1_k, _KMAX)(p, 0, _hc2);
  const double _t1 = (s * s);
  const double _t2 = _hc1[0]*_t1;
  const double _t3 = _hc2[0] + _t2;
#if _KMAX >= 1
  const double _t4 = ((_hc2[0]) * (_hc2[0]));
  const double _t5 = (0.1e1 / (_t3 * _t3));
  const double _t6 = _t4*_t5;
  const double _t7 = _hc0[1]*_hc1[1];
#endif
#if _KMAX >= 2
  const double _t8 = ((_hc1[0]) * (_hc1[0]));
  const double _t9 = _t4*_t8;
  const double _t10 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t11 = 0.8e1*_t10;
  const double _t12 = _hc2[0]*_t10;
  const double _t13 = _t12*_t7;
  const double _t14 = _hc1[0]*_t13;
  const double _t15 = (s * s * s);
  const double _t16 = 0.4e1*_t15;
  const double _t17 = ((_hc0[1]) * (_hc0[1]));
  const double _t18 = ((_hc1[1]) * (_hc1[1]));
  const double _t19 = _t17*_t18;
  const double _t20 = (s * s * s * s);
  const double _t21 = _t12*_t20;
#endif
#if _KMAX >= 3
  const double _t22 = 0.24e2*_t10;
  const double _t23 = _t22*_t9;
  const double _t24 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t25 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t26 = _hc2[0]*_t5;
  const double _t27 = 0.2e1*_t26;
  const double _t28 = 0.20e2*_t2;
  const double _t29 = _hc2[0]*_t24;
  const double _t30 = _hc1[2]*_t17;
  const double _t31 = _t12*_t30;
  const double _t32 = _hc1[0]*_t16;
  const double _t33 = _hc2[0]*_t19;
  const double _t34 = xc_powi(s, 5);
  const double _t35 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t36 = _hc1[3]*_t35;
  const double _t37 = 0.6e1*_t35;
  const double _t38 = _hc1[1]*_hc1[2];
  const double _t39 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t40 = xc_powi(s, 6);
#endif
#if _KMAX >= 4
  const double _t41 = xc_powi(_t3, -5);
  const double _t42 = _hc2[0]*_t41;
  const double _t43 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc2[0]*(-_hc2[0]/_t3 + 0.1e1) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = 0.2e1*_hc1[0]*_t6*s;
  out[1] = df_ds;
  const double df_drs = _t1*_t6*_t7;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = 0.2e1*_hc1[0]*_t4*_t5 - _t1*_t11*_t9;
  out[3] = d2f_ds2;
  const double d2f_drs_ds = _hc2[0]*(0.2e1*_hc0[1]*_hc1[1]*_hc2[0]*_t5*s - _t14*_t16);
  out[4] = d2f_drs_ds;
  const double d2f_drs2 = _hc2[0]*(_hc1[2]*_hc2[0]*_t1*_t17*_t5 - 0.2e1*_t19*_t21);
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = 0.48e2*_t15*_t24*_t25*_t4 - _t23*s;
  out[6] = d3f_ds3;
  const double d3f_drs_ds2 = _hc2[0]*(-_t13*_t28 + 0.24e2*_t20*_t29*_t7*_t8 + _t27*_t7);
  out[7] = d3f_drs_ds2;
  const double d3f_drs2_ds = _hc2[0]*(0.12e2*_hc1[0]*_t24*_t33*_t34 - _t11*_t15*_t33 + _t27*_t30*s - _t31*_t32);
  out[8] = d3f_drs2_ds;
  const double d3f_drs3 = _hc2[0]*(_t1*_t26*_t36 - _t21*_t37*_t38 + _t29*_t37*_t39*_t40);
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = -0.384e3*((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]))*_t20*_t4*_t41 + 0.288e3*_t1*_t24*_t25*_t4 - _t23;
  out[10] = d4f_ds4;
  const double d4f_drs_ds3 = _hc2[0]*(0.216e3*_hc0[1]*_hc1[1]*_hc2[0]*_t15*_t24*_t8 - 0.48e2*_t14*s - 0.192e3*_t25*_t34*_t42*_t7);
  out[11] = d4f_drs_ds3;
  const double d4f_drs2_ds2 = _hc2[0]*(0.108e3*_hc1[0]*_hc2[0]*_t17*_t18*_t20*_t24 + 0.24e2*_hc1[2]*_hc2[0]*_t17*_t20*_t24*_t8 + 0.2e1*_hc1[2]*_hc2[0]*_t17*_t5 - _t1*_t22*_t33 - _t28*_t31 - 0.96e2*_t33*_t40*_t41*_t8);
  out[12] = d4f_drs2_ds2;
  const double d4f_drs3_ds = _hc2[0]*(0.36e2*_hc1[0]*_hc1[1]*_hc1[2]*_hc2[0]*_t24*_t34*_t35 - 0.48e2*_hc1[0]*_t35*_t39*_t42*xc_powi(s, 7) + 0.2e1*_hc1[3]*_hc2[0]*_t35*_t5*s - _hc2[0]*_t15*_t22*_t35*_t38 + 0.36e2*_hc2[0]*_t24*_t34*_t35*_t39 - _t12*_t32*_t36);
  out[13] = d4f_drs3_ds;
  const double d4f_drs4 = _hc2[0]*(-0.24e2*((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t42*_t43*xc_powi(s, 8) - _hc1[1]*_hc1[3]*_hc2[0]*_t11*_t20*_t43 - 0.6e1*((_hc1[2]) * (_hc1[2]))*_t21*_t43 + 0.36e2*_hc1[2]*_hc2[0]*_t18*_t24*_t40*_t43 + _hc1[4]*_hc2[0]*_t1*_t43*_t5);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pbe_x_erf_gws_spin_z1_k, _KMAX)(const xc_func_type *p, double rs, double xs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_erf_spin_z1_k, _KMAX)(p, rs, _hc0);
  const double _t1 = xc_powr(0.6e1, 2, 3);
  const double _t2 = _t1/(M_CBRTPI * M_CBRTPI);
  const double _t3 = (0.1e1 / 0.12e2)*_t2;
#if _KMAX >= 1
  const double _t4 = _hc0[0]*_t3;
#endif
#if _KMAX >= 2
  const double _t5 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t6 = (0.1e1 / 0.24e2)*_hc0[0]*_t5;
#endif
#if _KMAX >= 3
  const double _t8 = (0.1e1 / (M_PI * M_PI));
  const double _t9 = (0.1e1 / 0.48e2)*_hc0[0]*_t8;
  const double _t10 = _hc0[1]*_t5;
  const double _t12 = _hc0[1]*_t2;
#endif
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pbe_x_erf_gws_Fx_z1_k, _KMAX)(p, rs, _t3*xs, _hc1);
#if _KMAX >= 2
  const double _t7 = _hc1[1]*_t3;
#endif
#if _KMAX >= 3
  const double _t11 = (0.1e1 / 0.24e2)*_hc1[3];
#endif

  const double f = _hc0[0]*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs = _hc1[1]*_t4;
  out[1] = df_dxs;
  const double df_drs = _hc0[0]*_hc1[2] + _hc0[1]*_hc1[0];
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs2 = _hc1[3]*_t6;
  out[3] = d2f_dxs2;
  const double d2f_drs_dxs = _hc0[1]*_t7 + _hc1[4]*_t4;
  out[4] = d2f_drs_dxs;
  const double d2f_drs2 = _hc0[0]*_hc1[5] + 0.2e1*_hc0[1]*_hc1[2] + _hc0[2]*_hc1[0];
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs3 = _hc1[6]*_t9;
  out[6] = d3f_dxs3;
  const double d3f_drs_dxs2 = _hc1[7]*_t6 + _t10*_t11;
  out[7] = d3f_drs_dxs2;
  const double d3f_drs2_dxs = _hc0[2]*_t7 + (0.1e1 / 0.6e1)*_hc1[4]*_t12 + _hc1[8]*_t4;
  out[8] = d3f_drs2_dxs;
  const double d3f_drs3 = _hc0[0]*_hc1[9] + 0.3e1*_hc0[1]*_hc1[5] + 0.3e1*_hc0[2]*_hc1[2] + _hc0[3]*_hc1[0];
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs4 = (0.1e1 / 0.576e3)*_hc0[0]*_hc1[10]*_t1/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  out[10] = d4f_dxs4;
  const double d4f_drs_dxs3 = (0.1e1 / 0.48e2)*_hc0[1]*_hc1[6]*_t8 + _hc1[11]*_t9;
  out[11] = d4f_drs_dxs3;
  const double d4f_drs2_dxs2 = _hc0[2]*_t11*_t5 + _hc1[12]*_t6 + (0.1e1 / 0.12e2)*_hc1[7]*_t10;
  out[12] = d4f_drs2_dxs2;
  const double d4f_drs3_dxs = (0.1e1 / 0.4e1)*_hc0[2]*_hc1[4]*_t2 + _hc0[3]*_t7 + _hc1[13]*_t4 + (0.1e1 / 0.4e1)*_hc1[8]*_t12;
  out[13] = d4f_drs3_dxs;
  const double d4f_drs4 = _hc0[0]*_hc1[14] + 0.4e1*_hc0[1]*_hc1[9] + 0.6e1*_hc0[2]*_hc1[5] + 0.4e1*_hc0[3]*_hc1[2] + _hc0[4]*_hc1[0];
  out[14] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_pbe_erf_gws_params *params = (const gga_x_pbe_erf_gws_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = xc_powr(0.12e2, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = xc_powr(na, -4, 3);
  const double _t6 = M_CBRT2;
  const double _t7 = xc_powr(gaa, 1, 2);
  const double _t8 = _t6*_t7;
  const double _t9 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  const double _t10 = (0.1e1 / 0.2e1)*na;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t9)) XC_CAT(f_pbe_x_erf_gws_spin_z1_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t1*_t4, _t5*_t8, _hc0);
  const double zk = 0.2e1*my_piecewise3(_t9, 0, _hc0[0]*_t10)/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = (0.1e1 / 0.6e1)*_t5;
  const double _t13 = (0.4e1 / 0.3e1)*_t8;
  const double _t14 = xc_powr(na, -7, 3);
  const double _t18 = (0.1e1 / _t7);
  const double _t19 = _t18*_t6;
  const double _t20 = (0.1e1 / 0.4e1)*_t19;
  const double _t11 = _hc0[2]*_t4;
  const double _t15 = _hc0[1]*_t14;
  const double _t16 = _t11*_t12 + _t13*_t15;
  const double _t17 = _hc0[1]*_t1;
  const double dF_dna = 0.2e1*my_piecewise3(_t9, 0, (0.1e1 / 0.2e1)*_hc0[0] - _t10*_t16);
  const double dF_dgaa = 0.2e1*my_piecewise3(_t9, 0, _t17*_t20);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t21 = (0.2e1 / 0.9e1)*_t14;
  const double _t23 = xc_powr(na, -10, 3);
  const double _t24 = (0.28e2 / 0.9e1)*_t23;
  const double _t25 = _t12*_t4;
  const double _t26 = _t13*_t14;
  const double _t31 = xc_powr(0.2e1, 2, 3);
  const double _t33 = xc_powr(na, -11, 3);
  const double _t34 = (0.2e1 / 0.3e1)*_t33;
  const double _t35 = (0.2e1 / 0.3e1)*_t19;
  const double _t36 = M_CBRT3;
  const double _t37 = _t18*_t3*_t36;
  const double _t39 = xc_powr(na, -8, 3);
  const double _t40 = (0.1e1 / 0.6e1)*_t39;
  const double _t42 = xc_powr(gaa, -3, 2);
  const double _t43 = (0.1e1 / 0.8e1)*_t42;
  const double _t44 = _t43*_t6;
  const double _t45 = (0.1e1 / gaa);
  const double _t46 = xc_powr(na, -5, 3);
  const double _t22 = _hc0[1]*_t8;
  const double _t27 = -_hc0[4]*_t26 - _hc0[5]*_t25;
  const double _t28 = -_hc0[3]*_t26 - _hc0[4]*_t25;
  const double _t29 = _t14*_t28;
  const double _t30 = _hc0[1]*_t5;
  const double _t32 = _hc0[3]*_t31;
  const double _t38 = _hc0[4]*_t37;
  const double _t41 = _t15*_t35 + _t32*_t34 + _t38*_t40;
  const double d2F_dna2 = 0.2e1*my_piecewise3(_t9, 0, -_t16 + (0.1e1 / 0.2e1)*na*(_t11*_t21 - _t13*_t29 + _t22*_t24 - _t25*_t27));
  const double d2F_dna_dgaa = 0.2e1*my_piecewise3(_t9, 0, -_t10*_t41 + _t20*_t30);
  const double d2F_dgaa2 = 0.2e1*my_piecewise3(_t9, 0, (0.1e1 / 0.8e1)*_hc0[3]*_t31*_t45*_t46 - _t17*_t44);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t48 = (0.1e1 / 0.4e1)*_t5;
  const double _t49 = 0.2e1*_t8;
  const double _t50 = (0.14e2 / 0.27e2)*_t23;
  const double _t51 = xc_powr(na, -13, 3);
  const double _t52 = (0.280e3 / 0.27e2)*_t51;
  const double _t53 = _t21*_t4;
  const double _t54 = _t24*_t8;
  const double _t60 = xc_powr(na, -14, 3);
  const double _t61 = (0.14e2 / 0.9e1)*_t60;
  const double _t62 = (0.14e2 / 0.9e1)*_t23;
  const double _t64 = (0.2e1 / 0.9e1)*_t33;
  const double _t66 = _t31*_t34;
  const double _t67 = _t14*_t35;
  const double _t68 = _t37*_t40;
  const double _t73 = xc_powi(na, -5);
  const double _t74 = (0.2e1 / 0.3e1)*_t73;
  const double _t76 = (0.1e1 / 0.3e1)*_t33;
  const double _t78 = (0.1e1 / 0.12e2)*_t3;
  const double _t79 = (0.1e1 / (na * na * na * na));
  const double _t80 = xc_powr(0.6e1, 1, 3);
  const double _t81 = _t45*_t79*_t80;
  const double _t84 = xc_powr(gaa, -5, 2);
  const double _t85 = _t6*_t84;
  const double _t86 = (0.3e1 / 0.16e2)*_t85;
  const double _t87 = (0.1e1 / (gaa * gaa));
  const double _t47 = _t27*_t4;
  const double _t55 = -_hc0[8]*_t26 - _hc0[9]*_t25;
  const double _t56 = -_hc0[7]*_t26 - _hc0[8]*_t25;
  const double _t57 = _hc0[4]*_t54 + _hc0[5]*_t53 - _t25*_t55 - _t26*_t56;
  const double _t58 = -_hc0[6]*_t26 - _hc0[7]*_t25;
  const double _t59 = _hc0[3]*_t54 + _hc0[4]*_t53 - _t25*_t56 - _t26*_t58;
  const double _t63 = _hc0[1]*_t19;
  const double _t65 = _t19*_t29;
  const double _t69 = -_hc0[4]*_t67 - _hc0[7]*_t66 - _hc0[8]*_t68;
  const double _t70 = -_hc0[3]*_t67 - _hc0[6]*_t66 - _hc0[7]*_t68;
  const double _t71 = _t32*_t45;
  const double _t72 = _hc0[6]*_t18;
  const double _t75 = _t72*_t74;
  const double _t77 = _t71*_t76;
  const double _t82 = _hc0[7]*_t78*_t81;
  const double _t83 = _hc0[6]/(na * na * na);
  const double _t88 = (0.3e1 / 0.16e2)*_t32*_t87;
  const double d3F_dna3 = 0.2e1*my_piecewise3(_t9, 0, _t10*(-_t11*_t50 + (0.4e1 / 0.9e1)*_t14*_t2*_t27*_t3 - _t22*_t52 + (0.56e2 / 0.9e1)*_t23*_t28*_t6*_t7 - _t25*_t57 - _t26*_t59) + (0.1e1 / 0.3e1)*_t11*_t14 + (0.14e2 / 0.3e1)*_t22*_t23 - _t29*_t49 - _t47*_t48);
  const double d3F_dna2_dgaa = 0.2e1*my_piecewise3(_t9, 0, -_t41 + (0.1e1 / 0.2e1)*na*(-_t25*_t69 - _t26*_t70 + _t32*_t61 + _t38*_t64 + _t62*_t63 - 0.2e1 / 0.3e1*_t65));
  const double d3F_dna_dgaa2 = 0.2e1*my_piecewise3(_t9, 0, _t10*((0.1e1 / 0.3e1)*_hc0[1]*_t14*_t42*_t6 + (0.1e1 / 0.12e2)*_hc0[4]*_t3*_t36*_t39*_t42 - _t75 - _t77 - _t82) - _t30*_t44 + (0.1e1 / 0.8e1)*_t39*_t71);
  const double d3F_dgaa3 = 0.2e1*my_piecewise3(_t9, 0, _t17*_t86 + _t43*_t83 - _t46*_t88);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t91 = xc_powr(na, -16, 3);
  const double _t92 = (0.2e1 / 0.3e1)*_t14;
  const double _t93 = _t4*_t50;
  const double _t94 = _t52*_t8;
  const double _t99 = _t31*_t61;
  const double _t100 = _t19*_t62;
  const double _t101 = _t37*_t64;
  const double _t103 = _t42*_t6;
  const double _t105 = _t18*_t74;
  const double _t106 = _t31*_t45*_t76;
  const double _t107 = _t78*_t81;
  const double _t89 = _t4*_t57;
  const double _t90 = _t59*_t8;
  const double _t95 = -_hc0[12]*_t26 - _hc0[13]*_t25;
  const double _t96 = -_hc0[11]*_t26 - _hc0[12]*_t25;
  const double _t97 = _hc0[7]*_t54 + _hc0[8]*_t53 - _t25*_t95 - _t26*_t96;
  const double _t98 = _t14*_t70;
  const double _t102 = -_hc0[11]*_t66 - _hc0[12]*_t68 - _hc0[7]*_t67;
  const double _t104 = _hc0[4]*_t36;
  const double d4F_dna4 = 0.2e1*my_piecewise3(_t9, 0, -0.28e2 / 0.27e2*_t11*_t23 + (0.8e1 / 0.9e1)*_t14*_t2*_t27*_t3 - 0.8e1 / 0.3e1*_t14*_t90 - 0.560e3 / 0.27e2*_t22*_t51 + (0.112e3 / 0.9e1)*_t23*_t28*_t6*_t7 - 0.1e1 / 0.3e1*_t5*_t89 + (0.1e1 / 0.2e1)*na*((0.140e3 / 0.81e2)*_t11*_t51 + (0.3640e4 / 0.81e2)*_t22*_t91 + (0.28e2 / 0.3e1)*_t23*_t90 - _t25*(-_hc0[4]*_t94 - _hc0[5]*_t93 + (0.4e1 / 0.9e1)*_t14*_t2*_t3*_t55 + (0.56e2 / 0.9e1)*_t23*_t56*_t6*_t7 - _t25*(_hc0[8]*_t54 + _hc0[9]*_t53 - _t25*(-_hc0[13]*_t26 - _hc0[14]*_t25) - _t26*_t95) - _t26*_t97) - _t26*(-_hc0[3]*_t94 - _hc0[4]*_t93 + (0.4e1 / 0.9e1)*_t14*_t2*_t3*_t56 + (0.56e2 / 0.9e1)*_t23*_t58*_t6*_t7 - _t25*_t97 - _t26*(_hc0[6]*_t54 + _hc0[7]*_t53 - _t25*_t96 - _t26*(-_hc0[10]*_t26 - _hc0[11]*_t25))) - 0.280e3 / 0.9e1*_t28*_t51*_t8 - _t47*_t62 + _t89*_t92));
  const double d4F_dna3_dgaa = 0.2e1*my_piecewise3(_t9, 0, _t10*((0.4e1 / 0.9e1)*_t14*_t2*_t3*_t69 + (0.28e2 / 0.9e1)*_t18*_t23*_t28*_t6 + (0.56e2 / 0.9e1)*_t23*_t6*_t7*_t70 - _t25*(_hc0[4]*_t100 + _hc0[7]*_t99 + _hc0[8]*_t101 - _t102*_t26 - _t25*(-_hc0[12]*_t66 - _hc0[13]*_t68 - _hc0[8]*_t67) - _t56*_t67) - _t26*(_hc0[3]*_t100 + _hc0[6]*_t99 + _hc0[7]*_t101 - _t102*_t25 - _t26*(-_hc0[10]*_t66 - _hc0[11]*_t68 - _t6*_t72*_t92) - _t58*_t67) - 0.140e3 / 0.27e2*_t32/xc_powr(na, 17, 3) - 0.14e2 / 0.27e2*_t38*_t60 - 0.140e3 / 0.27e2*_t51*_t63 - _t59*_t67) + (0.7e1 / 0.3e1)*_t23*_t63 + (0.7e1 / 0.3e1)*_t32*_t60 + _t38*_t76 - _t4*_t48*_t69 - _t49*_t98 - _t65);
  const double d4F_dna2_dgaa2 = 0.2e1*my_piecewise3(_t9, 0, _hc0[4]*_t36*_t39*_t42*_t78 + _t10*(-0.7e1 / 0.9e1*_hc0[1]*_t103*_t23 + (0.7e1 / 0.9e1)*_hc0[3]*_t31*_t45*_t60 + (0.14e2 / 0.9e1)*_hc0[6]*_t18/xc_powi(na, 6) + (0.1e1 / 0.9e1)*_hc0[7]*_t3*_t45*_t73*_t80 - 0.1e1 / 0.9e1*_t104*_t3*_t33*_t42 + (0.1e1 / 0.3e1)*_t14*_t28*_t42*_t6 - 0.4e1 / 0.3e1*_t19*_t98 - _t25*(-_hc0[11]*_t105 - _hc0[12]*_t107 + (0.1e1 / 0.3e1)*_hc0[4]*_t14*_t42*_t6 - _hc0[7]*_t106 + (0.1e1 / 0.12e2)*_hc0[8]*_t3*_t36*_t39*_t42) - _t26*(-_hc0[10]*_t105 - _hc0[11]*_t107 + (0.1e1 / 0.3e1)*_hc0[3]*_t14*_t42*_t6 - _hc0[6]*_t106 + (0.1e1 / 0.12e2)*_hc0[7]*_t3*_t36*_t39*_t42)) + (0.1e1 / 0.3e1)*_t103*_t15 - _t75 - _t77 - _t82);
  const double d4F_dna_dgaa3 = 0.2e1*my_piecewise3(_t9, 0, _hc0[6]*_t43*_t79 + _t10*(-0.1e1 / 0.3e1*_hc0[10]*_t45*_t6/xc_powr(na, 19, 3) - 0.1e1 / 0.24e2*_hc0[11]*_t4*_t42*_t91 + (0.1e1 / 0.2e1)*_hc0[3]*_t31*_t33*_t87 + (0.1e1 / 0.8e1)*_hc0[7]*_t3*_t79*_t80*_t87 - 0.1e1 / 0.8e1*_t104*_t3*_t39*_t84 - 0.1e1 / 0.2e1*_t15*_t85) + _t30*_t86 - _t39*_t88);
  const double d4F_dgaa4 = 0.2e1*my_piecewise3(_t9, 0, (0.1e1 / 0.16e2)*_hc0[10]*_t51*_t6*_t87 + (0.15e2 / 0.32e2)*_hc0[3]*_t31*_t46/(gaa * gaa * gaa) - 0.15e2 / 0.32e2*_t17*_t6/xc_powr(gaa, 7, 2) - 0.3e1 / 0.8e1*_t83*_t84);
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

  const double _t1 = xc_powr(na, -1, 3);
  const double _t2 = (0.1e1 / 0.2e1)*_t1;
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = xc_powr(gaa, 1, 2);
  const double _t7 = xc_powr(na, -4, 3);
  const double _t8 = xc_powr(nb, -1, 3);
  const double _t9 = (0.1e1 / 0.2e1)*_t8;
  const double _t10 = xc_powr(gbb, 1, 2);
  const double _t11 = xc_powr(nb, -4, 3);
  const double _t12 = -p->dens_threshold + na <= 0;
  const double _t13 = -p->dens_threshold + nb <= 0;
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t12)) XC_CAT(f_pbe_x_erf_gws_spin_k, _KMAX)(p, _t2*_t5, 0.1e1, _t6*_t7, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t13)) XC_CAT(f_pbe_x_erf_gws_spin_k, _KMAX)(p, _t5*_t9, 0.1e1, _t10*_t11, _hc1);
  const double zk = (my_piecewise3(_t12, 0, _hc0[0]*na) + my_piecewise3(_t13, 0, _hc1[0]*nb))/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t14 = xc_powr(na, -7, 3);
  const double _t15 = _t14*_t6;
  const double _t16 = (0.4e1 / 0.3e1)*_t15;
  const double _t17 = (0.1e1 / 0.6e1)*_t5;
  const double _t18 = _t17*_t7;
  const double _t19 = xc_powr(nb, -7, 3);
  const double _t20 = _t10*_t19;
  const double _t21 = (0.4e1 / 0.3e1)*_t20;
  const double _t22 = _t11*_t17;
  const double _t23 = (0.1e1 / _t6);
  const double _t25 = (0.1e1 / _t10);
  const double _t24 = _hc0[1]*_t23;
  const double _t26 = _hc1[1]*_t25;
  const double dF_dna = my_piecewise3(_t12, 0, _hc0[0] + na*(-_hc0[1]*_t16 - _hc0[3]*_t18));
  const double dF_dnb = my_piecewise3(_t13, 0, _hc1[0] + nb*(-_hc1[1]*_t21 - _hc1[3]*_t22));
  const double dF_dgaa = my_piecewise3(_t12, 0, _t2*_t24);
  const double dF_dgbb = my_piecewise3(_t13, 0, _t26*_t9);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t29 = xc_powr(na, -10, 3);
  const double _t30 = (0.28e2 / 0.9e1)*_t29;
  const double _t31 = (0.2e1 / 0.9e1)*_t14;
  const double _t37 = xc_powr(nb, -10, 3);
  const double _t38 = (0.28e2 / 0.9e1)*_t37;
  const double _t39 = (0.2e1 / 0.9e1)*_t19;
  const double _t43 = (0.1e1 / 0.2e1)*_t7;
  const double _t44 = xc_powr(na, -11, 3);
  const double _t45 = (0.2e1 / 0.3e1)*_t44;
  const double _t47 = (0.2e1 / 0.3e1)*_t14;
  const double _t48 = (0.1e1 / 0.12e2)*_t5;
  const double _t49 = xc_powr(na, -8, 3);
  const double _t52 = (0.1e1 / 0.2e1)*_t11;
  const double _t53 = xc_powr(nb, -11, 3);
  const double _t54 = (0.2e1 / 0.3e1)*_t53;
  const double _t56 = (0.2e1 / 0.3e1)*_t19;
  const double _t58 = xc_powr(nb, -8, 3);
  const double _t59 = _t48*_t58;
  const double _t60 = xc_powr(gaa, -3, 2);
  const double _t63 = (0.1e1 / gaa);
  const double _t64 = xc_powr(na, -5, 3);
  const double _t65 = xc_powr(gbb, -3, 2);
  const double _t68 = (0.1e1 / gbb);
  const double _t69 = xc_powr(nb, -5, 3);
  const double _t27 = _hc0[3]*_t5;
  const double _t28 = _hc0[1]*_t6;
  const double _t32 = (0.4e1 / 0.3e1)*_hc0[4];
  const double _t33 = -_hc0[7]*_t18 - _t15*_t32;
  const double _t34 = -_hc0[7]*_t16 - _hc0[9]*_t18;
  const double _t35 = _hc1[3]*_t5;
  const double _t36 = _hc1[1]*_t10;
  const double _t40 = (0.4e1 / 0.3e1)*_hc1[4];
  const double _t41 = -_hc1[7]*_t22 - _t20*_t40;
  const double _t42 = -_hc1[7]*_t21 - _hc1[9]*_t22;
  const double _t46 = _hc0[4]*_t45;
  const double _t50 = _hc0[7]*_t23;
  const double _t51 = _t49*_t50;
  const double _t55 = _hc1[4]*_t54;
  const double _t57 = _hc1[7]*_t25;
  const double _t61 = _hc0[1]*_t60;
  const double _t62 = (0.1e1 / 0.4e1)*_t61;
  const double _t66 = _hc1[1]*_t65;
  const double _t67 = (0.1e1 / 0.4e1)*_t66;
  const double d2F_dna2 = my_piecewise3(_t12, 0, -0.8e1 / 0.3e1*_hc0[1]*_t15 - 0.1e1 / 0.3e1*_t27*_t7 + na*(-_t16*_t33 - _t18*_t34 + _t27*_t31 + _t28*_t30));
  const double d2F_dnb2 = my_piecewise3(_t13, 0, -0.8e1 / 0.3e1*_hc1[1]*_t20 - 0.1e1 / 0.3e1*_t11*_t35 + nb*(-_t21*_t41 - _t22*_t42 + _t35*_t39 + _t36*_t38));
  const double d2F_dna_dgaa = my_piecewise3(_t12, 0, _t24*_t43 + na*(-_t24*_t47 - _t46 - _t48*_t51));
  const double d2F_dnb_dgbb = my_piecewise3(_t13, 0, _t26*_t52 + nb*(-_t26*_t56 - _t55 - _t57*_t59));
  const double d2F_dgaa2 = my_piecewise3(_t12, 0, (0.1e1 / 0.4e1)*_hc0[4]*_t63*_t64 - _t1*_t62);
  const double d2F_dgbb2 = my_piecewise3(_t13, 0, (0.1e1 / 0.4e1)*_hc1[4]*_t68*_t69 - _t67*_t8);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t70 = (0.28e2 / 0.3e1)*_t29;
  const double _t71 = 0.4e1*_t15;
  const double _t73 = xc_powr(na, -13, 3);
  const double _t74 = (0.280e3 / 0.27e2)*_t73;
  const double _t75 = (0.14e2 / 0.27e2)*_t29;
  const double _t76 = _t30*_t6;
  const double _t77 = _t31*_t5;
  const double _t83 = (0.28e2 / 0.3e1)*_t37;
  const double _t84 = 0.4e1*_t20;
  const double _t86 = xc_powr(nb, -13, 3);
  const double _t87 = (0.280e3 / 0.27e2)*_t86;
  const double _t88 = (0.14e2 / 0.27e2)*_t37;
  const double _t89 = _t10*_t38;
  const double _t90 = _t39*_t5;
  const double _t96 = (0.4e1 / 0.3e1)*_t14;
  const double _t97 = xc_powr(na, -14, 3);
  const double _t98 = (0.14e2 / 0.9e1)*_t97;
  const double _t99 = (0.14e2 / 0.9e1)*_t29;
  const double _t100 = (0.1e1 / 0.9e1)*_t5;
  const double _t101 = _t100*_t44;
  const double _t102 = _t23*_t47;
  const double _t104 = _t48*_t49;
  const double _t106 = _t104*_t23;
  const double _t108 = (0.4e1 / 0.3e1)*_t19;
  const double _t109 = xc_powr(nb, -14, 3);
  const double _t110 = (0.14e2 / 0.9e1)*_t109;
  const double _t111 = (0.14e2 / 0.9e1)*_t37;
  const double _t112 = _t100*_t53;
  const double _t113 = _t25*_t56;
  const double _t114 = _t25*_t59;
  const double _t119 = xc_powi(na, -5);
  const double _t120 = _t119*_t23;
  const double _t121 = (0.1e1 / 0.3e1)*_t44;
  const double _t122 = (0.1e1 / 0.24e2)*_t5;
  const double _t123 = (0.1e1 / (na * na * na * na));
  const double _t128 = xc_powi(nb, -5);
  const double _t129 = _t128*_t25;
  const double _t130 = (0.1e1 / 0.3e1)*_t53;
  const double _t132 = (0.1e1 / (nb * nb * nb * nb));
  const double _t133 = _t122*_t132;
  const double _t134 = xc_powr(gaa, -5, 2);
  const double _t138 = (0.1e1 / 0.8e1)*_t60;
  const double _t139 = (0.1e1 / (gaa * gaa));
  const double _t141 = xc_powr(gbb, -5, 2);
  const double _t145 = (0.1e1 / 0.8e1)*_t65;
  const double _t146 = (0.1e1 / (gbb * gbb));
  const double _t72 = _t34*_t5;
  const double _t78 = -_hc0[10]*_t16 - _hc0[14]*_t18;
  const double _t79 = -_hc0[14]*_t16 - _hc0[17]*_t18;
  const double _t80 = _hc0[4]*_t76 + _hc0[7]*_t77 - _t16*_t78 - _t18*_t79;
  const double _t81 = -_hc0[17]*_t16 - _hc0[19]*_t18;
  const double _t82 = _hc0[7]*_t76 + _hc0[9]*_t77 - _t16*_t79 - _t18*_t81;
  const double _t85 = _t42*_t5;
  const double _t91 = -_hc1[10]*_t21 - _hc1[14]*_t22;
  const double _t92 = -_hc1[14]*_t21 - _hc1[17]*_t22;
  const double _t93 = _hc1[4]*_t89 + _hc1[7]*_t90 - _t21*_t91 - _t22*_t92;
  const double _t94 = -_hc1[17]*_t21 - _hc1[19]*_t22;
  const double _t95 = _hc1[7]*_t89 + _hc1[9]*_t90 - _t21*_t92 - _t22*_t94;
  const double _t103 = _hc0[14]*_t23;
  const double _t105 = -_hc0[10]*_t45 - _hc0[4]*_t102 - _t103*_t104;
  const double _t107 = -_hc0[14]*_t45 - _hc0[17]*_t106 - _hc0[7]*_t102;
  const double _t115 = -_hc1[10]*_t54 - _hc1[14]*_t114 - _hc1[4]*_t113;
  const double _t116 = -_hc1[14]*_t54 - _hc1[17]*_t114 - _hc1[7]*_t113;
  const double _t117 = _hc0[4]*_t63;
  const double _t118 = (0.1e1 / 0.3e1)*_hc0[10];
  const double _t124 = _hc0[14]*_t63;
  const double _t125 = _t123*_t124;
  const double _t126 = _hc1[4]*_t68;
  const double _t127 = (0.1e1 / 0.3e1)*_hc1[10];
  const double _t131 = _hc1[14]*_t68;
  const double _t135 = _hc0[1]*_t134;
  const double _t136 = (0.3e1 / 0.8e1)*_t135;
  const double _t137 = _hc0[10]/(na * na * na);
  const double _t140 = (0.3e1 / 0.8e1)*_hc0[4]*_t139;
  const double _t142 = _hc1[1]*_t141;
  const double _t143 = (0.3e1 / 0.8e1)*_t142;
  const double _t144 = _hc1[10]/(nb * nb * nb);
  const double _t147 = (0.3e1 / 0.8e1)*_hc1[4]*_t146;
  const double d3F_dna3 = my_piecewise3(_t12, 0, _t27*_t47 + _t28*_t70 - _t33*_t71 - _t43*_t72 + na*((0.4e1 / 0.9e1)*_t14*_t3*_t34*_t4 - _t16*_t80 - _t18*_t82 - _t27*_t75 - _t28*_t74 + (0.56e2 / 0.9e1)*_t29*_t33*_t6));
  const double d3F_dnb3 = my_piecewise3(_t13, 0, _t35*_t56 + _t36*_t83 - _t41*_t84 - _t52*_t85 + nb*((0.56e2 / 0.9e1)*_t10*_t37*_t41 + (0.4e1 / 0.9e1)*_t19*_t3*_t4*_t42 - _t21*_t93 - _t22*_t95 - _t35*_t88 - _t36*_t87));
  const double d3F_dna2_dgaa = my_piecewise3(_t12, 0, -_t17*_t51 - _t24*_t96 - _t32*_t44 + na*(_hc0[4]*_t98 + _t101*_t50 - _t102*_t33 - _t105*_t16 - _t107*_t18 + _t24*_t99));
  const double d3F_dnb2_dgbb = my_piecewise3(_t13, 0, -_t108*_t26 - _t17*_t57*_t58 - _t40*_t53 + nb*(_hc1[4]*_t110 + _t111*_t26 + _t112*_t57 - _t113*_t41 - _t115*_t21 - _t116*_t22));
  const double d3F_dna_dgaa2 = my_piecewise3(_t12, 0, (0.1e1 / 0.4e1)*_t117*_t49 - _t62*_t7 + na*((0.1e1 / 0.3e1)*_hc0[1]*_t14*_t60 + (0.1e1 / 0.24e2)*_hc0[7]*_t3*_t4*_t49*_t60 - _t117*_t121 - _t118*_t120 - _t122*_t125));
  const double d3F_dnb_dgbb2 = my_piecewise3(_t13, 0, -_t11*_t67 + (0.1e1 / 0.4e1)*_t126*_t58 + nb*((0.1e1 / 0.3e1)*_hc1[1]*_t19*_t65 + (0.1e1 / 0.24e2)*_hc1[7]*_t3*_t4*_t58*_t65 - _t126*_t130 - _t127*_t129 - _t131*_t133));
  const double d3F_dgaa3 = my_piecewise3(_t12, 0, _t1*_t136 + _t137*_t138 - _t140*_t64);
  const double d3F_dgbb3 = my_piecewise3(_t13, 0, _t143*_t8 + _t144*_t145 - _t147*_t69);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t149 = xc_powr(na, -16, 3);
  const double _t150 = _t6*_t74;
  const double _t151 = _t5*_t75;
  const double _t156 = xc_powr(nb, -16, 3);
  const double _t157 = _t10*_t87;
  const double _t158 = _t5*_t88;
  const double _t163 = _t23*_t99;
  const double _t166 = _t111*_t25;
  const double _t167 = _t112*_t25;
  const double _t170 = (0.1e1 / 0.18e2)*_t5;
  const double _t171 = (0.1e1 / 0.3e1)*_t120;
  const double _t172 = _t122*_t123*_t63;
  const double _t174 = (0.1e1 / 0.3e1)*_t129;
  const double _t175 = _t133*_t68;
  const double _t176 = (0.1e1 / 0.48e2)*_t5;
  const double _t177 = (0.1e1 / 0.16e2)*_t5;
  const double _t148 = _t5*_t82;
  const double _t152 = -_hc0[25]*_t16 - _hc0[29]*_t18;
  const double _t153 = -_hc0[29]*_t16 - _hc0[32]*_t18;
  const double _t154 = _hc0[14]*_t76 + _hc0[17]*_t77 - _t152*_t16 - _t153*_t18;
  const double _t155 = _t5*_t95;
  const double _t159 = -_hc1[25]*_t21 - _hc1[29]*_t22;
  const double _t160 = -_hc1[29]*_t21 - _hc1[32]*_t22;
  const double _t161 = _hc1[14]*_t89 + _hc1[17]*_t90 - _t159*_t21 - _t160*_t22;
  const double _t162 = _t5*_t50;
  const double _t164 = -_hc0[14]*_t102 - _hc0[25]*_t45 - _hc0[29]*_t106;
  const double _t165 = _t5*_t57;
  const double _t168 = -_hc1[14]*_t113 - _hc1[25]*_t54 - _hc1[29]*_t114;
  const double _t169 = _hc0[7]*_t60;
  const double _t173 = _hc1[7]*_t65;
  const double d4F_dna4 = my_piecewise3(_t12, 0, (0.16e2 / 0.9e1)*_t14*_t3*_t34*_t4 - 0.2e1 / 0.3e1*_t148*_t7 - 0.16e2 / 0.3e1*_t15*_t80 - 0.56e2 / 0.27e2*_t27*_t29 - 0.1120e4 / 0.27e2*_t28*_t73 + (0.224e3 / 0.9e1)*_t29*_t33*_t6 + na*(_t148*_t47 + (0.3640e4 / 0.81e2)*_t149*_t28 - _t16*(-_hc0[4]*_t150 - _hc0[7]*_t151 + (0.4e1 / 0.9e1)*_t14*_t3*_t4*_t79 - _t154*_t18 - _t16*(_hc0[10]*_t76 + _hc0[14]*_t77 - _t152*_t18 - _t16*(-_hc0[20]*_t16 - _hc0[25]*_t18)) + (0.56e2 / 0.9e1)*_t29*_t6*_t78) - _t18*(-_hc0[7]*_t150 - _hc0[9]*_t151 + (0.4e1 / 0.9e1)*_t14*_t3*_t4*_t81 - _t154*_t16 - _t18*(_hc0[17]*_t76 + _hc0[19]*_t77 - _t153*_t16 - _t18*(-_hc0[32]*_t16 - _hc0[34]*_t18)) + (0.56e2 / 0.9e1)*_t29*_t6*_t79) + (0.140e3 / 0.81e2)*_t27*_t73 - 0.280e3 / 0.9e1*_t33*_t6*_t73 + _t6*_t70*_t80 - _t72*_t99));
  const double d4F_dnb4 = my_piecewise3(_t13, 0, (0.224e3 / 0.9e1)*_t10*_t37*_t41 - 0.2e1 / 0.3e1*_t11*_t155 + (0.16e2 / 0.9e1)*_t19*_t3*_t4*_t42 - 0.16e2 / 0.3e1*_t20*_t93 - 0.56e2 / 0.27e2*_t35*_t37 - 0.1120e4 / 0.27e2*_t36*_t86 + nb*(-0.280e3 / 0.9e1*_t10*_t41*_t86 + _t10*_t83*_t93 - _t111*_t85 + _t155*_t56 + (0.3640e4 / 0.81e2)*_t156*_t36 - _t21*(-_hc1[4]*_t157 - _hc1[7]*_t158 + (0.56e2 / 0.9e1)*_t10*_t37*_t91 - _t161*_t22 + (0.4e1 / 0.9e1)*_t19*_t3*_t4*_t92 - _t21*(_hc1[10]*_t89 + _hc1[14]*_t90 - _t159*_t22 - _t21*(-_hc1[20]*_t21 - _hc1[25]*_t22))) - _t22*(-_hc1[7]*_t157 - _hc1[9]*_t158 + (0.56e2 / 0.9e1)*_t10*_t37*_t92 - _t161*_t21 + (0.4e1 / 0.9e1)*_t19*_t3*_t4*_t94 - _t22*(_hc1[17]*_t89 + _hc1[19]*_t90 - _t160*_t21 - _t22*(-_hc1[32]*_t21 - _hc1[34]*_t22))) + (0.140e3 / 0.81e2)*_t35*_t86));
  const double d4F_dna3_dgaa = my_piecewise3(_t12, 0, (0.14e2 / 0.3e1)*_hc0[4]*_t97 - _t105*_t71 - _t107*_t43*_t5 + _t121*_t162 - 0.2e1*_t14*_t23*_t33 + (0.14e2 / 0.3e1)*_t24*_t29 + na*(-0.140e3 / 0.27e2*_hc0[4]/xc_powr(na, 17, 3) - _t102*_t80 + (0.56e2 / 0.9e1)*_t105*_t29*_t6 + (0.4e1 / 0.9e1)*_t107*_t14*_t3*_t4 - _t16*(_hc0[10]*_t98 + _hc0[4]*_t163 + _t101*_t103 - _t102*_t78 - _t16*(-_hc0[10]*_t102 - _hc0[20]*_t45 - _hc0[25]*_t106) - _t164*_t18) - 0.7e1 / 0.27e2*_t162*_t97 - _t18*(_hc0[14]*_t98 + _hc0[17]*_t101*_t23 + _hc0[7]*_t163 - _t102*_t79 - _t16*_t164 - _t18*(-_hc0[17]*_t102 - _hc0[29]*_t45 - _hc0[32]*_t106)) + (0.28e2 / 0.9e1)*_t23*_t29*_t33 - 0.140e3 / 0.27e2*_t24*_t73));
  const double d4F_dnb3_dgbb = my_piecewise3(_t13, 0, (0.14e2 / 0.3e1)*_hc1[4]*_t109 - _t115*_t84 - _t116*_t5*_t52 + _t130*_t165 - 0.2e1*_t19*_t25*_t41 + (0.14e2 / 0.3e1)*_t26*_t37 + nb*(-0.140e3 / 0.27e2*_hc1[4]/xc_powr(nb, 17, 3) + (0.56e2 / 0.9e1)*_t10*_t115*_t37 - 0.7e1 / 0.27e2*_t109*_t165 - _t113*_t93 + (0.4e1 / 0.9e1)*_t116*_t19*_t3*_t4 - _t21*(_hc1[10]*_t110 + _hc1[14]*_t167 + _hc1[4]*_t166 - _t113*_t91 - _t168*_t22 - _t21*(-_hc1[10]*_t113 - _hc1[20]*_t54 - _hc1[25]*_t114)) - _t22*(_hc1[14]*_t110 + _hc1[17]*_t167 + _hc1[7]*_t166 - _t113*_t92 - _t168*_t21 - _t22*(-_hc1[17]*_t113 - _hc1[29]*_t54 - _hc1[32]*_t114)) + (0.28e2 / 0.9e1)*_t25*_t37*_t41 - 0.140e3 / 0.27e2*_t26*_t86));
  const double d4F_dna2_dgaa2 = my_piecewise3(_t12, 0, -0.2e1 / 0.3e1*_hc0[10]*_t120 + _t104*_t169 - _t125*_t48 - _t46*_t63 + _t47*_t61 + na*((0.7e1 / 0.9e1)*_hc0[10]*_t23/xc_powi(na, 6) + (0.1e1 / 0.18e2)*_hc0[14]*_t119*_t3*_t4*_t63 + (0.7e1 / 0.9e1)*_hc0[4]*_t63*_t97 - _t105*_t23*_t96 + (0.1e1 / 0.3e1)*_t14*_t33*_t60 - _t16*((0.1e1 / 0.24e2)*_hc0[14]*_t3*_t4*_t49*_t60 - _hc0[20]*_t171 - _hc0[25]*_t172 + (0.1e1 / 0.3e1)*_hc0[4]*_t14*_t60 - _t118*_t44*_t63) - _t169*_t170*_t44 - _t18*((0.1e1 / 0.24e2)*_hc0[17]*_t3*_t4*_t49*_t60 - _hc0[25]*_t171 - _hc0[29]*_t172 + (0.1e1 / 0.3e1)*_hc0[7]*_t14*_t60 - _t121*_t124) - 0.7e1 / 0.9e1*_t29*_t61));
  const double d4F_dnb2_dgbb2 = my_piecewise3(_t13, 0, -0.2e1 / 0.3e1*_hc1[10]*_t129 - _t131*_t132*_t48 + _t173*_t59 - _t55*_t68 + _t56*_t66 + nb*((0.7e1 / 0.9e1)*_hc1[10]*_t25/xc_powi(nb, 6) + (0.1e1 / 0.18e2)*_hc1[14]*_t128*_t3*_t4*_t68 + (0.7e1 / 0.9e1)*_hc1[4]*_t109*_t68 - _t108*_t115*_t25 - _t170*_t173*_t53 + (0.1e1 / 0.3e1)*_t19*_t41*_t65 - _t21*((0.1e1 / 0.24e2)*_hc1[14]*_t3*_t4*_t58*_t65 - _hc1[20]*_t174 - _hc1[25]*_t175 + (0.1e1 / 0.3e1)*_hc1[4]*_t19*_t65 - _t127*_t53*_t68) - _t22*((0.1e1 / 0.24e2)*_hc1[17]*_t3*_t4*_t58*_t65 - _hc1[25]*_t174 - _hc1[29]*_t175 + (0.1e1 / 0.3e1)*_hc1[7]*_t19*_t65 - _t130*_t131) - 0.7e1 / 0.9e1*_t37*_t66));
  const double d4F_dna_dgaa3 = my_piecewise3(_t12, 0, _hc0[10]*_t123*_t138 + _t136*_t7 - _t140*_t49 + na*((0.1e1 / 0.16e2)*_hc0[14]*_t123*_t139*_t3*_t4 - 0.1e1 / 0.6e1*_hc0[20]*_t63/xc_powr(na, 19, 3) - _hc0[25]*_t149*_t176*_t60 + (0.1e1 / 0.2e1)*_hc0[4]*_t139*_t44 - _hc0[7]*_t134*_t177*_t49 - 0.1e1 / 0.2e1*_t135*_t14));
  const double d4F_dnb_dgbb3 = my_piecewise3(_t13, 0, _hc1[10]*_t132*_t145 + _t11*_t143 - _t147*_t58 + nb*((0.1e1 / 0.16e2)*_hc1[14]*_t132*_t146*_t3*_t4 - 0.1e1 / 0.6e1*_hc1[20]*_t68/xc_powr(nb, 19, 3) - _hc1[25]*_t156*_t176*_t65 + (0.1e1 / 0.2e1)*_hc1[4]*_t146*_t53 - _hc1[7]*_t141*_t177*_t58 - 0.1e1 / 0.2e1*_t142*_t19));
  const double d4F_dgaa4 = my_piecewise3(_t12, 0, -0.15e2 / 0.16e2*_hc0[1]*_t1/xc_powr(gaa, 7, 2) + (0.1e1 / 0.16e2)*_hc0[20]*_t139*_t73 + (0.15e2 / 0.16e2)*_hc0[4]*_t64/(gaa * gaa * gaa) - 0.3e1 / 0.8e1*_t134*_t137);
  const double d4F_dgbb4 = my_piecewise3(_t13, 0, -0.15e2 / 0.16e2*_hc1[1]*_t8/xc_powr(gbb, 7, 2) + (0.1e1 / 0.16e2)*_hc1[20]*_t146*_t86 + (0.15e2 / 0.16e2)*_hc1[4]*_t69/(gbb * gbb * gbb) - 0.3e1 / 0.8e1*_t141*_t144);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif