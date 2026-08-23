/*
  Generated from python/mgga_exc/mgga_x_lak.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_lak
*/

#ifndef _MGGA_X_LAK_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_LAK_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_LAK_HELPER_BODIES
#include "mgga_x_lak.c"
#undef _MGGA_X_LAK_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_LAK_HELPER_BODIES
#include "mgga_x_lak.c"
#undef _MGGA_X_LAK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_LAK_HELPER_BODIES
#include "mgga_x_lak.c"
#undef _MGGA_X_LAK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_LAK_HELPER_BODIES
#include "mgga_x_lak.c"
#undef _MGGA_X_LAK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_LAK_HELPER_BODIES
#include "mgga_x_lak.c"
#undef _MGGA_X_LAK_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_lak.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_LAK_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(m_one_minus_recexp_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = -0.1e1/log(XC_EPSILON);
  const double _t2 = x <= _t1;
  const double _t3 = _t1 > x;
  const double _t4 = my_piecewise3(_t3, _t1, x);
  const double _t5 = xc_expm1(-0.1e1/_t4);
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0, 0.1e1);
  const double _t7 = _t5 + 0.1e1;
#endif
#if _KMAX >= 2
  const double _t8 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t9 = (_t6 * _t6)*_t7;
#endif
#if _KMAX >= 3
  const double _t10 = xc_powi(_t4, -6);
  const double _t11 = (_t6 * _t6 * _t6);
  const double _t12 = _t11*_t7;
  const double _t13 = xc_powi(_t4, -5);
#endif
#if _KMAX >= 4
  const double _t14 = (_t6 * _t6 * _t6 * _t6)*_t7;
#endif

  const double f = my_piecewise3(_t2, 0.1e1, -_t5);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = my_piecewise3(_t2, 0, -_t6*_t7/(_t4 * _t4));
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = my_piecewise3(_t2, 0, -_t8*_t9 + 0.2e1*_t9/(_t4 * _t4 * _t4));
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = my_piecewise3(_t2, 0, -_t10*_t12 + 0.6e1*_t11*_t13*_t7 - 0.6e1*_t12*_t8);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = my_piecewise3(_t2, 0, -0.36e2*_t10*_t14 + 0.24e2*_t13*_t14 + 0.12e2*_t14/xc_powi(_t4, 7) - _t14/xc_powi(_t4, 8));
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mgga_alpha_safe_k, _KMAX)(const xc_func_type *p, double x, double t, double *out) {

  const double _t1 = (0.1e1 / t);
  const double _t2 = 0.8e1*t - (x * x);
  const double _t3 = (0.1e1 / 0.8e1)*_t2;
  const double _t4 = _t1*_t3;
  const double _t5 = xc_powr(XC_EPSILON, 2, 3);
  const double _t6 = _t4 > _t5;
  const double _t7 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t8 = (0.5e1 / 0.9e1)*_t7;
  const double _t9 = _t8*my_piecewise3(_t6, _t4, _t5);
#if _KMAX >= 1
  const double _t10 = (0.1e1 / (t * t));
  const double _t11 = my_piecewise3(_t6, _t1 - _t10*_t3, 0);
  const double _t12 = _t8*t;
  const double _t13 = (0.1e1 / 0.4e1)*_t1;
  const double _t14 = _t8*my_piecewise3(_t6, -_t13*x, 0);
#endif
#if _KMAX >= 2
  const double _t15 = (0.10e2 / 0.9e1)*_t7;
  const double _t16 = (0.1e1 / (t * t * t));
  const double _t17 = my_piecewise3(_t6, -0.2e1*_t10 + (0.1e1 / 0.4e1)*_t16*_t2, 0);
  const double _t18 = (0.1e1 / 0.4e1)*_t10;
  const double _t19 = my_piecewise3(_t6, _t18*x, 0);
  const double _t20 = _t8*my_piecewise3(_t6, -_t13, 0);
#endif
#if _KMAX >= 3
  const double _t21 = (0.5e1 / 0.3e1)*_t7;
  const double _t22 = (0.1e1 / (t * t * t * t));
  const double _t23 = my_piecewise3(_t6, 0.6e1*_t16 - 0.3e1 / 0.4e1*_t2*_t22, 0);
  const double _t24 = (0.1e1 / 0.2e1)*_t16;
  const double _t25 = my_piecewise3(_t6, -_t24*x, 0);
  const double _t26 = my_piecewise3(_t6, _t18, 0);
#endif

  const double f = _t9*t;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t11*_t12 + _t9;
  out[1] = df_dt;
  const double df_dx = _t14*t;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t11*_t15 + _t12*_t17;
  out[3] = d2f_dt2;
  const double d2f_dx_dt = _t12*_t19 + _t14;
  out[4] = d2f_dx_dt;
  const double d2f_dx2 = _t20*t;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t12*_t23 + _t17*_t21;
  out[6] = d3f_dt3;
  const double d3f_dx_dt2 = _t12*_t25 + _t15*_t19;
  out[7] = d3f_dx_dt2;
  const double d3f_dx2_dt = _t12*_t26 + _t20;
  out[8] = d3f_dx2_dt;
  const double d3f_dx3 = 0;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t12*my_piecewise3(_t6, 0.3e1*_t2/xc_powi(t, 5) - 0.24e2*_t22, 0) + (0.20e2 / 0.9e1)*_t23*_t7;
  out[10] = d4f_dt4;
  const double d4f_dx_dt3 = _t12*my_piecewise3(_t6, (0.3e1 / 0.2e1)*_t22*x, 0) + _t21*_t25;
  out[11] = d4f_dx_dt3;
  const double d4f_dx2_dt2 = _t12*my_piecewise3(_t6, -_t24, 0) + _t15*_t26;
  out[12] = d4f_dx2_dt2;
  const double d4f_dx3_dt = 0;
  out[13] = d4f_dx3_dt;
  const double d4f_dx4 = 0;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_one_minus_gx_k, _KMAX)(const xc_func_type *p, double s, double *out) {

  const double _t1 = xc_powr(s, 1, 2);
  const double _t2 = 0.20210594393581116*_t1;
  const double _t3 = -0.1e1/log(XC_EPSILON);
  const double _t4 = _t2 <= _t3;
  const double _t5 = _t3 > _t2;
  const double _t6 = my_piecewise3(_t5, _t3, _t2);
  const double _t7 = exp(-0.1e1/_t6);
#if _KMAX >= 1
  const double _t8 = my_piecewise3(_t5, 0, 0.10105297196790558/_t1);
  const double _t9 = _t7/(_t6 * _t6);
#endif
#if _KMAX >= 2
  const double _t10 = my_piecewise3(_t5, 0, -0.05052648598395279/xc_powr(s, 3, 2));
  const double _t11 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t12 = _t7*(_t8 * _t8);
  const double _t13 = _t11*_t12;
  const double _t14 = (0.1e1 / (_t6 * _t6 * _t6));
#endif
#if _KMAX >= 3
  const double _t15 = my_piecewise3(_t5, 0, 0.075789728975929185/xc_powr(s, 5, 2));
  const double _t16 = xc_powi(_t6, -6);
  const double _t17 = _t7*(_t8 * _t8 * _t8);
  const double _t18 = xc_powi(_t6, -5);
  const double _t19 = 0.6e1*_t17;
  const double _t20 = 0.3e1*_t11;
  const double _t21 = _t7*_t8;
  const double _t22 = _t10*_t21;
  const double _t23 = 0.6e1*_t14;
#endif
#if _KMAX >= 4
  const double _t24 = _t7*(_t8 * _t8 * _t8 * _t8);
  const double _t25 = (_t10 * _t10)*_t7;
  const double _t26 = _t15*_t21;
  const double _t27 = _t10*_t12;
#endif

  const double f = my_piecewise3(_t4, 0, _t7);
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = my_piecewise3(_t4, 0, _t8*_t9);
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = my_piecewise3(_t4, 0, _t10*_t9 - 0.2e1*_t12*_t14 + _t13);
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = my_piecewise3(_t4, 0, _t11*_t19 + _t15*_t9 + _t16*_t17 - _t18*_t19 + _t20*_t22 - _t22*_t23);
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = my_piecewise3(_t4, 0, 0.36e2*_t10*_t13 + 0.4e1*_t11*_t26 - 0.8e1*_t14*_t26 + 0.36e2*_t16*_t24 + 0.6e1*_t16*_t27 - 0.24e2*_t18*_t24 - 0.36e2*_t18*_t27 + _t20*_t25 - _t23*_t25 - 0.12e2*_t24/xc_powi(_t6, 7) + _t24/xc_powi(_t6, 8) + _t9*my_piecewise3(_t5, 0, -0.18947432243982296/xc_powr(s, 7, 2)));
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_gx_k, _KMAX)(const xc_func_type *p, double s, double *out) {

  const double _t1 = xc_powr(s, 1, 2);
#if _KMAX >= 2
  const double _t2 = xc_powr(s, -3, 2);
#endif
#if _KMAX >= 3
  const double _t3 = xc_powr(s, -5, 2);
  const double _t4 = (0.1e1 / (s * s));
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(m_one_minus_recexp_k, _KMAX)(p, 0.20210594393581116*_t1, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = 0.10105297196790558*_hc0[1]/_t1;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = -0.05052648598395279*_hc0[1]*_t2 + 0.010211703143546311*_hc0[2]/s;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = 0.075789728975929185*_hc0[1]*_t3 - 0.015317554715319467*_hc0[2]*_t4 + 0.0010319229515093587*_hc0[3]*_t2;
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = -0.18947432243982296*_hc0[1]/xc_powr(s, 7, 2) + 0.038293886788298669*_hc0[2]/(s * s * s) - 0.0030957688545280764*_hc0[3]*_t3 + 0.00010427888109191362*_hc0[4]*_t4;
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_fx0_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = ((a - 0.1e1) * (a - 0.1e1));
  const double _t2 = (0.1e1 / a);
  const double _t3 = 1.206306719102564*a - 1.206306719102564;
  const double _t4 = -_t3;
  const double _t5 = -1.1103356059345268*_t1 + _t2*_t4;
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
#if _KMAX >= 1
  const double _t7 = (0.1e1 / (a * a));
  const double _t8 = _t4*_t7;
  const double _t9 = 1.206306719102564*_t2 + 2.2206712118690537*a - 2.2206712118690537;
  const double _t10 = -_t8 - _t9;
  const double _t11 = (_t5 * _t5);
  const double _t12 = (M_PI * M_PI);
  const double _t13 = (0.1e1 / 0.4e1)*_t12;
  const double _t14 = _t11*_t13 + 0.1e1;
  const double _t15 = (0.1e1 / _t14);
#endif
#if _KMAX >= 2
  const double _t16 = (0.1e1 / (a * a * a));
  const double _t17 = _t16*_t4;
  const double _t18 = 2.4126134382051281*_t7 - 2.2206712118690537;
  const double _t19 = 0.2e1*_t17 + _t18;
  const double _t20 = 2.4126134382051281*_t2 + 4.4413424237381074*a - 4.4413424237381074;
  const double _t21 = -_t20 - 0.2e1*_t8;
  const double _t22 = _t21*_t5;
  const double _t23 = (0.1e1 / (_t14 * _t14));
  const double _t24 = _t10*_t13*_t23;
#endif
#if _KMAX >= 3
  const double _t25 = (0.1e1 / (a * a * a * a));
  const double _t26 = _t25*_t4;
  const double _t27 = -7.2378403146153847*_t16 - 0.6e1*_t26;
  const double _t28 = 2.4126134382051281*a - 2.4126134382051281;
  const double _t29 = (_t10 * _t10);
  const double _t30 = _t12*_t23;
  const double _t31 = _t29*_t30;
  const double _t32 = 4.8252268764102562*_t7 - 4.4413424237381074;
  const double _t33 = 0.4e1*_t17 + _t32;
  const double _t34 = _t33*_t5;
  const double _t35 = _t19*_t30;
  const double _t36 = _t21*_t35;
  const double _t37 = (M_PI * M_PI * M_PI * M_PI)/(_t14 * _t14 * _t14);
  const double _t38 = (_t21 * _t21)*_t37;
  const double _t39 = _t11*_t38;
#endif
#if _KMAX >= 4
  const double _t40 = _t16*(4.8252268764102562 - 4.8252268764102562*a);
  const double _t41 = (_t21 * _t21 * _t21);
  const double _t42 = (0.1e1 / 0.8e1)*_t37*(_t3*_t7 - _t9);
  const double _t43 = _t11*_t42*(-_t20 + _t28*_t7);
#endif

  const double f = 0.2e1*atan(M_PI*_t6)/M_PI;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t10*_t15;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t15*_t19 - _t22*_t24;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _t15*_t27 - _t24*_t34 + _t31*(0.60315335955128202*_t2 - 0.1e1 / 0.4e1*_t28*_t7 + 1.1103356059345268*a - 1.1103356059345268) - _t36*_t6 + _t39*(-0.15078833988782051*_t2 + (0.1e1 / 0.8e1)*_t3*_t7 - 0.27758390148363171*a + 0.27758390148363171);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.1e1 / 0.2e1*_t10*_t36 + _t15*(28.951361258461539*_t25 + 0.24e2*_t4/xc_powi(a, 5)) - _t21*_t24*_t33 - 0.3e1 / 0.4e1*_t22*_t27*_t30 - _t24*_t5*(-14.475680629230769*_t16 - 0.12e2*_t26) + _t29*_t38*(-0.13879195074181586*_t1 + (0.1e1 / 0.8e1)*_t2*_t4) + _t31*(-_t18 - 0.1e1 / 0.2e1*_t40) - 0.3e1 / 0.4e1*_t34*_t35 + _t39*(-0.3e1 / 0.8e1*_t16*_t28 + 0.90473003932692309*_t7 - 0.83275170445089519) + _t41*_t42*_t5 + _t43*(_t32 + _t40) + _t43*(_t16*(9.6504537528205123 - 9.6504537528205123*a) + 9.6504537528205123*_t7 - 8.8826848474762148) + xc_powi(M_PI, 6)*_t41*(_t5 * _t5 * _t5)*(0.11309125491586539*_t2 - 0.3e1 / 0.32e2*_t3*_t7 + 0.2081879261127238*a - 0.2081879261127238)/(_t14 * _t14 * _t14 * _t14);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_fx_taylor_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = (0.1e1 / (M_PI * M_PI));
  const double _t2 = 3.3159062588790134*_t1;
  const double _t3 = (a * a);
  const double _t4 = (a * a * a);
  const double _t5 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t6 = -6.1251879226606034*_t1 + 3.0382638576511054*_t5;
  const double _t7 = (a * a * a * a);
  const double _t8 = -3.09240597971597*_t1 + 17.504430347121136*_t5;
  const double _t9 = -0.52440578643538516*_t1 + 50.453215773052712*_t5 - 5.010963455068655/xc_powi(M_PI, 6);
#if _KMAX >= 1
  const double _t10 = 12.736012597010811*_t1;
#endif

  const double f = -6.3680062985054056*_t1*_t3 - _t2*a + _t4*_t6 + _t7*_t8 + _t9*xc_powi(a, 5) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t10*a - _t2 + 0.3e1*_t3*_t6 + 0.4e1*_t4*_t8 + 0.5e1*_t7*_t9;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -_t10 + 0.12e2*_t3*_t8 + 0.20e2*_t4*_t9 + 0.6e1*_t6*a;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -36.751127535963619*_t1 + 0.60e2*_t3*_t9 + 18.229583145906631*_t5 + 0.24e2*_t8*a;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -74.217743513183279*_t1 + 420.10632833090727*_t5 + 0.120e3*_t9*a;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_fx_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lak_fx_taylor_k, _KMAX)(p, a, _hc0);
  const double _t1 = a > XC_EPSILON;
  const double _t2 = a <= XC_EPSILON;
#if _KMAX >= 1
  const double _t3 = my_piecewise3(_t1, 0.1e1, 0);
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(lak_fx0_k, _KMAX)(p, my_piecewise3(_t1, a, XC_EPSILON), _hc1);

  const double f = my_piecewise3(_t2, _hc0[0], _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, _hc0[1], _hc1[1]*_t3);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, _hc0[2], _hc1[2]*(_t3 * _t3));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, _hc0[3], _hc1[3]*(_t3 * _t3 * _t3));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, _hc0[4], _hc1[4]*(_t3 * _t3 * _t3 * _t3));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_hx_ge4_k, _KMAX)(const xc_func_type *p, double s, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lak_one_minus_gx_k, _KMAX)(p, s, _hc0);
  const double _t1 = (s * s);

  const double f = 1.1739999999999999*_hc0[0] - 0.032022742560873618*_t1 - 0.088696563426951563*(s * s * s * s) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = 1.1739999999999999*_hc0[1] - 0.35478625370780625*(s * s * s) - 0.064045485121747237*s;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = 1.1739999999999999*_hc0[2] - 1.0643587611234189*_t1 - 0.064045485121747237;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = 1.1739999999999999*_hc0[3] - 2.1287175222468377*s;
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = 1.1739999999999999*_hc0[4] - 2.1287175222468377;
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_kx_k, _KMAX)(const xc_func_type *p, double s, double *out) {

  const double _t1 = (s * s);
  const double _t2 = _t1 + 0.1e1;
  const double _t3 = 0.82644628099173545*_t1*_t2;
  const double _t4 = -0.1e1/log(XC_EPSILON);
  const double _t5 = _t3 <= _t4;
  const double _t6 = _t4 > _t3;
  const double _t7 = my_piecewise3(_t6, _t4, _t3);
  const double _t8 = exp(-0.1e1/_t7);
#if _KMAX >= 1
  const double _t9 = my_piecewise3(_t6, 0, 1.6528925619834709*_t2*s + 1.6528925619834709*(s * s * s));
  const double _t10 = _t8/(_t7 * _t7);
#endif
#if _KMAX >= 2
  const double _t11 = my_piecewise3(_t6, 0, 9.9173553719008254*_t1 + 1.6528925619834709);
  const double _t12 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t13 = _t8*(_t9 * _t9);
  const double _t14 = _t12*_t13;
  const double _t15 = (0.1e1 / (_t7 * _t7 * _t7));
#endif
#if _KMAX >= 3
  const double _t16 = my_piecewise3(_t6, 0, 19.834710743801651*s);
  const double _t17 = xc_powi(_t7, -6);
  const double _t18 = _t8*(_t9 * _t9 * _t9);
  const double _t19 = xc_powi(_t7, -5);
  const double _t20 = 0.6e1*_t18;
  const double _t21 = 0.3e1*_t12;
  const double _t22 = _t8*_t9;
  const double _t23 = _t11*_t22;
  const double _t24 = 0.6e1*_t15;
#endif
#if _KMAX >= 4
  const double _t25 = (_t11 * _t11)*_t8;
  const double _t26 = _t8*(_t9 * _t9 * _t9 * _t9);
  const double _t27 = _t16*_t22;
  const double _t28 = _t11*_t13;
#endif

  const double f = my_piecewise3(_t5, 0, _t8);
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = my_piecewise3(_t5, 0, _t10*_t9);
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = my_piecewise3(_t5, 0, _t10*_t11 - 0.2e1*_t13*_t15 + _t14);
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = my_piecewise3(_t5, 0, _t10*_t16 + _t12*_t20 + _t17*_t18 - _t19*_t20 + _t21*_t23 - _t23*_t24);
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = my_piecewise3(_t5, 0, _t10*my_piecewise3(_t6, 0, 19.834710743801651) + 0.36e2*_t11*_t14 + 0.4e1*_t12*_t27 - 0.8e1*_t15*_t27 + 0.36e2*_t17*_t26 + 0.6e1*_t17*_t28 - 0.24e2*_t19*_t26 - 0.36e2*_t19*_t28 + _t21*_t25 - _t24*_t25 - 0.12e2*_t26/xc_powi(_t7, 7) + _t26/xc_powi(_t7, 8));
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_h1x_k, _KMAX)(const xc_func_type *p, double s, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lak_hx_ge4_k, _KMAX)(p, s, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lak_kx_k, _KMAX)(p, s, _hc1);
  const double _t1 = 1.1000000000000001 - _hc0[0];

  const double f = _hc0[0] + _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = -_hc0[1]*_hc1[0] + _hc0[1] + _hc1[1]*_t1;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = -0.2e1*_hc0[1]*_hc1[1] - _hc0[2]*_hc1[0] + _hc0[2] + _hc1[2]*_t1;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = -0.3e1*_hc0[1]*_hc1[2] - 0.3e1*_hc0[2]*_hc1[1] - _hc0[3]*_hc1[0] + _hc0[3] + _hc1[3]*_t1;
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = -0.4e1*_hc0[1]*_hc1[3] - 0.6e1*_hc0[2]*_hc1[2] - 0.4e1*_hc0[3]*_hc1[1] - _hc0[4]*_hc1[0] + _hc0[4] + _hc1[4]*_t1;
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_gnum_k, _KMAX)(const xc_func_type *p, double s, double *out) {

  const double _t1 = (s * s);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(m_one_minus_recexp_k, _KMAX)(p, (0.1e1 / 0.25e2)*_t1, _hc0);
#if _KMAX >= 1
  const double _t2 = (0.2e1 / 0.25e2)*_hc0[1];
#endif
#if _KMAX >= 3
  const double _t3 = (0.12e2 / 0.625e3)*_hc0[2];
#endif

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = _t2*s;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = (0.4e1 / 0.625e3)*_hc0[2]*_t1 + _t2;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = (0.8e1 / 0.15625e5)*_hc0[3]*(s * s * s) + _t3*s;
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = (0.48e2 / 0.15625e5)*_hc0[3]*_t1 + (0.16e2 / 0.390625e6)*_hc0[4]*(s * s * s * s) + _t3;
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_fsa_k, _KMAX)(const xc_func_type *p, double s, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lak_gx_k, _KMAX)(p, s, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lak_fx_k, _KMAX)(p, a, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lak_h1x_k, _KMAX)(p, s, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lak_gnum_k, _KMAX)(p, s, _hc3);
  const double _t1 = 0.1e1 - _hc1[0];
  const double _t2 = _hc2[0] - 1.1739999999999999;
  const double _t3 = _hc3[0]*_t2;
#if _KMAX >= 1
  const double _t4 = _hc2[1]*_hc3[0];
  const double _t5 = _hc3[1]*_t2;
#endif
#if _KMAX >= 2
  const double _t6 = _hc2[2]*_hc3[0];
  const double _t7 = _hc2[1]*_t1;
  const double _t8 = 0.2e1*_hc3[1];
  const double _t9 = _hc3[2]*_t2;
#endif
#if _KMAX >= 3
  const double _t10 = _hc2[1]*_t8;
  const double _t11 = _hc2[3]*_hc3[0];
  const double _t12 = 0.3e1*_hc3[2];
  const double _t13 = _hc3[1]*_t1;
  const double _t14 = 0.3e1*_hc2[2];
  const double _t15 = _hc3[3]*_t2;
#endif

  const double f = 1.1739999999999999*_hc0[0] + _t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_hc1[1]*_t3;
  out[1] = df_da;
  const double df_ds = 1.1739999999999999*_hc0[1] + _t1*_t4 + _t1*_t5;
  out[2] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -_hc1[2]*_t3;
  out[3] = d2f_da2;
  const double d2f_ds_da = -_hc1[1]*_t4 - _hc1[1]*_t5;
  out[4] = d2f_ds_da;
  const double d2f_ds2 = 1.1739999999999999*_hc0[2] + _t1*_t6 + _t1*_t9 + _t7*_t8;
  out[5] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -_hc1[3]*_t3;
  out[6] = d3f_da3;
  const double d3f_ds_da2 = -_hc1[2]*_t4 - _hc1[2]*_t5;
  out[7] = d3f_ds_da2;
  const double d3f_ds2_da = -_hc1[1]*_t10 - _hc1[1]*_t6 - _hc1[1]*_t9;
  out[8] = d3f_ds2_da;
  const double d3f_ds3 = 1.1739999999999999*_hc0[3] + _t1*_t11 + _t1*_t15 + _t12*_t7 + _t13*_t14;
  out[9] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -_hc1[4]*_t3;
  out[10] = d4f_da4;
  const double d4f_ds_da3 = -_hc1[3]*_t4 - _hc1[3]*_t5;
  out[11] = d4f_ds_da3;
  const double d4f_ds2_da2 = -_hc1[2]*_t10 - _hc1[2]*_t6 - _hc1[2]*_t9;
  out[12] = d4f_ds2_da2;
  const double d4f_ds3_da = -_hc1[1]*_hc2[1]*_t12 - _hc1[1]*_hc3[1]*_t14 - _hc1[1]*_t11 - _hc1[1]*_t15;
  out[13] = d4f_ds3_da;
  const double d4f_ds4 = 1.1739999999999999*_hc0[4] + 0.6e1*_hc2[2]*_hc3[2]*_t1 + 0.4e1*_hc2[3]*_t13 + _hc2[4]*_hc3[0]*_t1 + 0.4e1*_hc3[3]*_t7 + _hc3[4]*_t1*_t2;
  out[14] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lak_f_k, _KMAX)(const xc_func_type *p, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mgga_alpha_safe_k, _KMAX)(p, x, t, _hc0);
  const double _t1 = xc_powr(0.6e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  const double _t2 = (0.1e1 / 0.12e2)*_t1;
#if _KMAX >= 2
  const double _t3 = ((_hc0[1]) * (_hc0[1]));
#endif
#if _KMAX >= 3
  const double _t7 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t9 = _hc0[1]*_hc0[3];
  const double _t11 = 0.2e1*_hc0[1];
  const double _t19 = 0.2e1*_hc0[5];
#endif
#if _KMAX >= 4
  const double _t24 = 0.3e1*_hc0[3];
#endif
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lak_fsa_k, _KMAX)(p, _t2*x, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t4 = _hc0[2]*_hc1[3];
  const double _t5 = _hc1[4]*_t2;
  const double _t6 = _t4 + _t5;
#endif
#if _KMAX >= 3
  const double _t8 = 0.3e1*_hc1[3];
  const double _t10 = _hc0[4]*_hc1[3];
  const double _t12 = _hc0[2]*_hc1[6];
  const double _t13 = _hc1[7]*_t2;
  const double _t14 = _hc0[5]*_hc1[3];
  const double _t15 = _hc0[1]*_t12;
  const double _t16 = _hc0[1]*_t13 + _t10 + _t15;
  const double _t17 = _hc0[2]*_hc1[7];
  const double _t18 = _hc1[8]*_t2;
  const double _t20 = _t12 + _t13;
  const double _t21 = _t17 + _t18;
  const double _t22 = _hc0[2]*_t20 + _t14 + _t2*_t21;
#endif
#if _KMAX >= 4
  const double _t23 = _hc0[7]*_hc1[3];
  const double _t25 = _hc0[2]*_hc1[10];
  const double _t26 = _hc0[4]*_hc1[6];
  const double _t27 = _hc1[11]*_t2;
  const double _t28 = _hc0[8]*_hc1[3];
  const double _t29 = _hc0[5]*_hc1[6];
  const double _t30 = _hc0[4]*_hc1[7];
  const double _t31 = _hc0[2]*_hc1[11];
  const double _t32 = _hc1[12]*_t2;
  const double _t33 = _hc0[1]*_t31 + _hc0[1]*_t32 + _t30;
  const double _t34 = _hc0[5]*_hc1[7];
  const double _t35 = _hc0[2]*_hc1[12];
  const double _t36 = _hc1[13]*_t2;
  const double _t37 = _t31 + _t32;
  const double _t38 = _t35 + _t36;
  const double _t39 = _hc0[2]*_t37 + _t2*_t38 + _t34;
#endif

  const double f = _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1]*_hc1[1];
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc0[2]*_hc1[1] + _hc1[2]*_t2;
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[3]*_hc1[1] + _hc1[3]*_t3;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx_dt = _hc0[1]*_t4 + _hc0[1]*_t5 + _hc0[4]*_hc1[1];
  out[7] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[8] = d2f_dx_du;
  const double d2f_dx2 = _hc0[2]*_t6 + _hc0[5]*_hc1[1] + _t2*(_hc0[2]*_hc1[4] + _hc1[5]*_t2);
  out[9] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[6]*_hc1[1] + _hc1[6]*_t7 + _t8*_t9;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx_dt2 = _hc0[3]*_t4 + _hc0[3]*_t5 + _hc0[7]*_hc1[1] + _t10*_t11 + _t12*_t3 + _t13*_t3;
  out[14] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[15] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[16] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc0[1]*_t14 + _hc0[2]*_t16 + _hc0[4]*_t6 + _hc0[8]*_hc1[1] + _t2*(_hc0[1]*_t17 + _hc0[1]*_t18 + _hc0[4]*_hc1[4]);
  out[17] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[18] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[2]*_t22 + _t19*_t6 + _t2*(_hc0[2]*_t21 + _hc0[5]*_hc1[4] + _t2*(_hc0[2]*_hc1[8] + _hc1[9]*_t2));
  out[19] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[10] + 0.4e1*_hc0[1]*_hc0[6]*_hc1[3] + _hc0[10]*_hc1[1] + ((_hc0[3]) * (_hc0[3]))*_t8 + 0.6e1*_hc0[3]*_hc1[6]*_t3;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx_dt3 = 0.3e1*_hc0[1]*_t23 + _hc0[11]*_hc1[1] + _hc0[6]*_t4 + _hc0[6]*_t5 + (0.1e1 / 0.4e1)*_hc1[7]*_t1*_t9 + _t10*_t24 + _t15*_t24 + _t25*_t7 + 0.3e1*_t26*_t3 + _t27*_t7;
  out[25] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[26] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[27] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[28] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc0[12]*_hc1[1] + _hc0[2]*(_hc0[3]*_t12 + _hc0[3]*_t13 + _t11*_t26 + _t23 + _t25*_t3 + _t27*_t3) + _hc0[3]*_t14 + 0.2e1*_hc0[4]*_t16 + _hc0[7]*_t6 + _t11*_t28 + _t2*(_hc0[3]*_t17 + _hc0[3]*_t18 + _hc0[7]*_hc1[4] + _t11*_t30 + _t3*_t31 + _t3*_t32) + _t29*_t3;
  out[29] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[30] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[31] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc0[2]*(_hc0[1]*_t29 + _hc0[2]*(_hc0[1]*_t25 + _hc0[1]*_t27 + _t26) + _hc0[4]*_t20 + _t2*_t33 + _t28) + _hc0[4]*_t22 + 0.2e1*_hc0[8]*_t6 + _t16*_t19 + _t2*(_hc0[1]*_t34 + _hc0[2]*_t33 + _hc0[4]*_t21 + _hc0[8]*_hc1[4] + _t2*(_hc0[1]*_t35 + _hc0[1]*_t36 + _hc0[4]*_hc1[8]));
  out[32] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[33] = d4f_dx3_du;
  const double d4f_dx4 = _hc0[2]*(_hc0[2]*(_hc0[2]*(_t25 + _t27) + _t2*_t37 + _t29) + _t19*_t20 + _t2*_t39) + 0.3e1*_hc0[5]*_t22 + _t2*(_hc0[2]*_t39 + _t19*_t21 + _t2*(_hc0[2]*_t38 + _hc0[5]*_hc1[8] + _t2*(_hc0[2]*_hc1[13] + _hc1[14]*_t2)));
  out[34] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {

  const double _t1 = xc_powr(n_s, -4, 3);
  const double _t2 = xc_powr(sigma_ss, 1, 2);
  const double _t3 = xc_powr(n_s, -5, 3);
  const double _t4 = xc_powr(0.6e1, 1, 3);
  const double _t5 = (0.1e1 / (M_CBRTPI));
  const double _t6 = _t4*_t5;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t12 = (0.1e1 / _t2);
  const double _t17 = xc_powr(n_s, -8, 3);
  const double _t18 = (0.5e1 / 0.3e1)*_t17;
  const double _t20 = (0.4e1 / 0.3e1)*_t2;
  const double _t21 = xc_powr(n_s, -7, 3);
#endif
#if _KMAX >= 2
  const double _t25 = xc_powr(n_s, -10, 3);
  const double _t27 = (0.1e1 / (n_s * n_s * n_s));
  const double _t31 = xc_powr(sigma_ss, -3, 2);
  const double _t33 = (0.1e1 / sigma_ss);
  const double _t35 = xc_powr(n_s, -13, 3);
  const double _t36 = (0.5e1 / 0.3e1)*tau_s;
  const double _t37 = _t35*_t36;
  const double _t38 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t43 = xc_powr(n_s, -11, 3);
  const double _t44 = (0.2e1 / 0.3e1)*_t43;
  const double _t45 = (0.2e1 / 0.3e1)*_t12;
  const double _t47 = (0.5e1 / 0.6e1)*tau_s;
  const double _t48 = _t12*_t47;
  const double _t53 = xc_powr(0.6e1, 2, 3);
  const double _t54 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t58 = (0.1e1 / 0.3e1)*_t1;
  const double _t59 = (0.40e2 / 0.9e1)*_t43;
  const double _t61 = (0.28e2 / 0.9e1)*_t2;
  const double _t67 = _t20*_t21;
#endif
#if _KMAX >= 3
  const double _t71 = xc_powi(n_s, -5);
  const double _t73 = xc_powr(n_s, -14, 3);
  const double _t82 = xc_powr(sigma_ss, -5, 2);
  const double _t86 = (0.1e1 / (sigma_ss * sigma_ss));
  const double _t88 = (0.10e2 / 0.3e1)*_t35;
  const double _t89 = xc_powi(n_s, -6);
  const double _t91 = xc_powr(n_s, -17, 3);
  const double _t96 = xc_powr(n_s, -16, 3);
  const double _t97 = (0.2e1 / 0.3e1)*_t96;
  const double _t98 = (0.3e1 / 0.2e1)*_t12;
  const double _t103 = (0.1e1 / 0.3e1)*_t12;
  const double _t104 = _t103*_t71;
  const double _t105 = (0.1e1 / 0.3e1)*_t33;
  const double _t107 = (0.5e1 / 0.12e2)*tau_s;
  const double _t114 = (0.40e2 / 0.9e1)*tau_s;
  const double _t117 = _t18*tau_s;
  const double _t124 = (0.14e2 / 0.9e1)*_t73;
  const double _t125 = (0.14e2 / 0.9e1)*_t12;
  const double _t126 = (0.20e2 / 0.9e1)*tau_s;
  const double _t127 = _t21*_t45;
  const double _t138 = (0.440e3 / 0.27e2)*_t73;
  const double _t140 = (0.280e3 / 0.27e2)*_t2;
#endif
#if _KMAX >= 4
  const double _t158 = xc_powr(n_s, -20, 3);
  const double _t159 = xc_powr(n_s, -19, 3);
  const double _t161 = (0.1e1 / 0.6e1)*_t159;
  const double _t163 = xc_powr(n_s, -22, 3);
  const double _t165 = xc_powi(n_s, -7);
  const double _t169 = _t107*_t33;
  const double _t173 = _t91*tau_s;
  const double _t174 = (0.5e1 / 0.6e1)*_t173;
  const double _t176 = (0.4e1 / 0.3e1)*_t21;
  const double _t177 = _t105*_t43;
  const double _t185 = _t59*tau_s;
#endif
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t8)) XC_CAT(lak_f_k, _KMAX)(p, _t1*_t2, 0, _t3*tau_s, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t8)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t7/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc1);
  const double _t9 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t10 = my_piecewise3(_t8, 0, _hc0[1]*_hc1[0]*_t3);
  const double _t11 = (0.1e1 / 0.2e1)*_hc1[0];
  const double _t13 = _hc0[3]*_t12;
  const double _t14 = my_piecewise3(_t8, 0, _t1*_t11*_t13);
  const double _t15 = _hc1[2]*_t6;
  const double _t16 = (0.1e1 / 0.6e1)*_t15;
  const double _t19 = _hc0[1]*_t18;
  const double _t22 = _hc0[3]*_t21;
  const double _t23 = -_t19*tau_s - _t20*_t22;
  const double _t24 = my_piecewise3(_t8, 0, -_hc0[0]*_t1*_t16 + _hc1[0]*_t23);
#endif
#if _KMAX >= 2
  const double _t26 = my_piecewise3(_t8, 0, _hc0[4]*_hc1[0]*_t25);
  const double _t28 = _hc0[7]*_t12;
  const double _t29 = my_piecewise3(_t8, 0, _t11*_t27*_t28);
  const double _t30 = (0.1e1 / 0.4e1)*_hc1[0];
  const double _t32 = _hc0[3]*_t31;
  const double _t34 = my_piecewise3(_t8, 0, (0.1e1 / 0.4e1)*_hc0[9]*_hc1[0]*_t17*_t33 - _t1*_t30*_t32);
  const double _t39 = _hc0[7]*_t20;
  const double _t40 = -_hc0[4]*_t37 - _t19 - _t38*_t39;
  const double _t41 = my_piecewise3(_t8, 0, -_hc0[1]*_t16*_t27 + _hc1[0]*_t40);
  const double _t42 = _t15*_t17;
  const double _t46 = _hc0[7]*_t38;
  const double _t49 = -_hc0[9]*_t44 - _t22*_t45 - _t46*_t48;
  const double _t50 = my_piecewise3(_t8, 0, _hc1[0]*_t49 - 0.1e1 / 0.12e2*_t13*_t42);
  const double _t51 = (0.2e1 / 0.9e1)*_hc0[0];
  const double _t52 = (0.1e1 / 0.36e2)*_hc0[0];
  const double _t55 = _hc1[5]*_t53*_t54;
  const double _t56 = _t17*_t55;
  const double _t57 = _t15*_t23;
  const double _t60 = _hc0[1]*_t59;
  const double _t62 = _hc0[3]*_t25;
  const double _t63 = _hc0[4]*_t18;
  const double _t64 = -_t21*_t39 - _t63*tau_s;
  const double _t65 = _t18*_t64;
  const double _t66 = _hc0[7]*_t18;
  const double _t68 = -_hc0[9]*_t67 - _t66*tau_s;
  const double _t69 = _t60*tau_s + _t61*_t62 - _t65*tau_s - _t67*_t68;
  const double _t70 = my_piecewise3(_t8, 0, _hc1[0]*_t69 + _t15*_t21*_t51 + _t52*_t56 - _t57*_t58);
#endif
#if _KMAX >= 3
  const double _t72 = my_piecewise3(_t8, 0, _hc0[10]*_hc1[0]*_t71);
  const double _t74 = _hc0[14]*_t12;
  const double _t75 = my_piecewise3(_t8, 0, _t11*_t73*_t74);
  const double _t76 = _hc0[17]*_t33;
  const double _t77 = _t30*_t31;
  const double _t78 = _hc0[7]*_t27;
  const double _t79 = my_piecewise3(_t8, 0, _t30*_t35*_t76 - _t77*_t78);
  const double _t80 = _hc0[19]*_t38;
  const double _t81 = (0.1e1 / 0.8e1)*_hc1[0]*_t31;
  const double _t83 = (0.3e1 / 0.8e1)*_hc1[0];
  const double _t84 = _t82*_t83;
  const double _t85 = _hc0[3]*_t1;
  const double _t87 = my_piecewise3(_t8, 0, -_hc0[9]*_t17*_t83*_t86 + _t80*_t81 + _t84*_t85);
  const double _t90 = _hc0[10]*_t89;
  const double _t92 = _hc0[14]*_t20;
  const double _t93 = -_hc0[4]*_t88 - _t36*_t90 - _t91*_t92;
  const double _t94 = my_piecewise3(_t8, 0, -_hc0[4]*_t16*_t73 + _hc1[0]*_t93);
  const double _t95 = _t15*_t35;
  const double _t99 = _t74*_t91;
  const double _t100 = -_hc0[17]*_t97 - _t46*_t98 - _t47*_t99;
  const double _t101 = my_piecewise3(_t8, 0, _hc1[0]*_t100 - 0.1e1 / 0.12e2*_t28*_t95);
  const double _t102 = (0.1e1 / 0.24e2)*_t15;
  const double _t106 = _t76*_t96;
  const double _t108 = -_hc0[19]*_t104 + (0.1e1 / 0.3e1)*_hc0[3]*_t21*_t31 + (0.5e1 / 0.12e2)*_hc0[7]*_t31*_t38*tau_s - _hc0[9]*_t105*_t43 - _t106*_t107;
  const double _t109 = my_piecewise3(_t8, 0, -_hc0[9]*_t102*_t33*_t38 + _hc1[0]*_t108 + (0.1e1 / 0.24e2)*_t32*_t42);
  const double _t110 = (0.2e1 / 0.9e1)*_t15;
  const double _t111 = (0.1e1 / 0.36e2)*_hc0[1];
  const double _t112 = _t15*_t58;
  const double _t113 = _hc0[4]*_t96;
  const double _t115 = _hc0[7]*_t61;
  const double _t116 = -_hc0[10]*_t37 - _t38*_t92 - _t63;
  const double _t118 = _hc0[17]*_t38;
  const double _t119 = -_hc0[14]*_t37 - _t118*_t20 - _t66;
  const double _t120 = _t113*_t114 + _t115*_t71 - _t116*_t117 - _t119*_t67 + _t60 - _t65;
  const double _t121 = my_piecewise3(_t8, 0, _hc0[1]*_t110*_t38 + _hc1[0]*_t120 + _t111*_t35*_t55 - _t112*_t40);
  const double _t122 = (0.1e1 / 0.9e1)*_t15;
  const double _t123 = (0.1e1 / 0.72e2)*_t55;
  const double _t128 = -_hc0[17]*_t44 - _hc0[7]*_t127 - _t38*_t47*_t74;
  const double _t129 = _t128*_t18;
  const double _t130 = -_hc0[19]*_t44 - _hc0[9]*_t127 - _t118*_t48;
  const double _t131 = _hc0[9]*_t124 + _t125*_t62 + _t126*_t28*_t71 - _t127*_t68 - _t129*tau_s - _t130*_t67;
  const double _t132 = my_piecewise3(_t8, 0, _hc1[0]*_t131 - _t112*_t49 + _t122*_t13*_t43 + _t123*_t13*_t38);
  const double _t133 = _hc1[9]/M_PI;
  const double _t134 = _t133*_t38;
  const double _t135 = (0.14e2 / 0.27e2)*_t15;
  const double _t136 = (0.1e1 / 0.9e1)*_t55;
  const double _t137 = _hc1[2]*_t1*_t7;
  const double _t139 = _hc0[1]*_t138;
  const double _t141 = _hc0[3]*_t35;
  const double _t142 = _hc0[4]*_t59;
  const double _t143 = _hc0[10]*_t18;
  const double _t144 = -_hc0[14]*_t67 - _t143*tau_s;
  const double _t145 = _t144*_t18;
  const double _t146 = _hc0[14]*_t18;
  const double _t147 = -_hc0[17]*_t67 - _t146*tau_s;
  const double _t148 = _t115*_t25 + _t142*tau_s - _t145*tau_s - _t147*_t67;
  const double _t149 = _t148*_t18;
  const double _t150 = _hc0[7]*_t59;
  const double _t151 = _hc0[9]*_t25;
  const double _t152 = _t147*_t18;
  const double _t153 = _hc0[17]*_t18;
  const double _t154 = -_hc0[19]*_t67 - _t153*tau_s;
  const double _t155 = _t150*tau_s + _t151*_t61 - _t152*tau_s - _t154*_t67;
  const double _t156 = -_t139*tau_s - _t140*_t141 - _t149*tau_s - _t155*_t67 + (0.56e2 / 0.9e1)*_t2*_t25*_t68 + (0.80e2 / 0.9e1)*_t43*_t64*tau_s;
  const double _t157 = my_piecewise3(_t8, 0, -_hc0[0]*_t135*_t25 - _hc0[0]*_t136*_t43 + _hc1[0]*_t156 + (0.2e1 / 0.3e1)*_hc1[2]*_t21*_t23*_t4*_t5 + (0.1e1 / 0.12e2)*_hc1[5]*_t17*_t23*_t53*_t54 - _t134*_t52 - _t137*_t69);
#endif
#if _KMAX >= 4
  const double _t160 = _hc0[25]*_t12;
  const double _t162 = _hc0[20]*_t36;
  const double _t164 = _hc0[25]*_t20;
  const double _t166 = _hc0[29]*_t165;
  const double _t167 = _hc0[25]*_t48;
  const double _t168 = _hc0[32]*_t158;
  const double _t170 = _hc0[10]*_t114;
  const double _t171 = _hc0[14]*_t61;
  const double _t172 = _hc0[29]*_t20;
  const double _t175 = _hc0[7]*tau_s;
  const double _t178 = _hc0[4]*tau_s;
  const double _t179 = _hc0[7]*_t140;
  const double _t180 = -_hc0[25]*_t37 - _t146 - _t172*_t38;
  const double _t181 = _hc0[17]*_t61;
  const double _t182 = _hc0[32]*_t38;
  const double _t183 = _hc0[3]*_t96;
  const double _t184 = -_hc0[17]*_t127 - _hc0[29]*_t38*_t48 - _hc0[32]*_t44;
  const double _t186 = -_hc0[25]*_t117 - _hc0[29]*_t67;
  const double _t187 = -_hc0[29]*_t117 - _hc0[32]*_t67;
  const double _t188 = _hc0[14]*_t185 - _t117*_t186 + _t181*_t25 - _t187*_t67;
#endif

  const double f = my_piecewise3(_t8, 0, _t9*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t8, 0, _t10*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t8, 0, _t14*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t8, 0, _t24*n_s + _t9);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t8, 0, _t26*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t8, 0, _t29*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t8, 0, _t34*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t8, 0, _t10 + _t41*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t8, 0, _t14 + _t50*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t8, 0, 0.2e1*_t24 + _t70*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t8, 0, _t72*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t8, 0, _t75*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t8, 0, _t79*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t8, 0, _t87*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t8, 0, _t26 + _t94*n_s);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t8, 0, _t101*n_s + _t29);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t8, 0, _t109*n_s + _t34);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t8, 0, _t121*n_s + 0.2e1*_t41);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t8, 0, _t132*n_s + 0.2e1*_t50);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t8, 0, _t157*n_s + 0.3e1*_t70);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, _hc0[20]*_hc1[0]*_t158));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, _t11*_t159*_t160));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, -_hc0[14]*_t73*_t77 + (0.1e1 / 0.4e1)*_hc0[29]*_hc1[0]*_t33*_t89));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, -_hc0[17]*_t35*_t83*_t86 + _hc0[32]*_t81*_t91 + _t78*_t84));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.16e2)*_hc0[34]*_hc1[0]*_t86*_t96 + (0.15e2 / 0.16e2)*_hc0[9]*_hc1[0]*_t17/(sigma_ss * sigma_ss * sigma_ss) - 0.15e2 / 0.16e2*_hc1[0]*_t85/xc_powr(sigma_ss, 7, 2) - _t80*_t84));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t8, 0, _t72 + n_s*my_piecewise3(_t8, 0, -_hc0[10]*_t15*_t161 + _hc1[0]*(-_t162/xc_powr(n_s, 23, 3) - _t163*_t164 - 0.5e1*_t90)));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t8, 0, _t75 + n_s*my_piecewise3(_t8, 0, _hc1[0]*(-_t163*_t167 - 0.2e1 / 0.3e1*_t166 - 0.7e1 / 0.3e1*_t99) - 0.1e1 / 0.12e2*_t15*_t74*_t89));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t8, 0, _t79 + n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.24e2)*_hc0[7]*_t31*_t95 + _hc1[0]*((0.5e1 / 0.12e2)*_hc0[14]*_t31*_t91*tau_s + (0.3e1 / 0.4e1)*_hc0[7]*_t31*_t38 - _t103*_t168 - 0.3e1 / 0.4e1*_t106 - _t166*_t169) - _t102*_t76*_t91));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t8, 0, _t87 + n_s*my_piecewise3(_t8, 0, -0.1e1 / 0.48e2*_hc0[19]*_t15*_t31*_t96 - 0.1e1 / 0.16e2*_hc0[3]*_t42*_t82 + (0.1e1 / 0.16e2)*_hc0[9]*_hc1[2]*_t38*_t4*_t5*_t86 + _hc1[0]*((0.5e1 / 0.8e1)*_hc0[17]*_t86*_t96*tau_s - _hc0[34]*_t161*_t33 + (0.1e1 / 0.2e1)*_hc0[9]*_t43*_t86 - 0.5e1 / 0.24e2*_t168*_t31*tau_s - 0.1e1 / 0.2e1*_t22*_t82 - 0.5e1 / 0.8e1*_t46*_t82*tau_s)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t8, 0, 0.2e1*_t94 + n_s*my_piecewise3(_t8, 0, _hc0[4]*_t110*_t91 + (0.1e1 / 0.36e2)*_hc0[4]*_t55*_t89 + _hc1[0]*((0.80e2 / 0.9e1)*_t113 - 0.10e2 / 0.3e1*_t116*_t17 - _t117*(-_hc0[10]*_t88 - _t162*_t89 - _t164*_t91) + _t158*_t171 + _t165*_t170 - _t67*(-_hc0[14]*_t88 - _hc0[25]*_t36*_t89 - _t172*_t91)) - _t112*_t93));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t8, 0, 0.2e1*_t101 + n_s*my_piecewise3(_t8, 0, _hc1[0]*((0.20e2 / 0.9e1)*_hc0[14]*_t12*_t158*tau_s + (0.14e2 / 0.9e1)*_hc0[17]*_t159 + (0.34e2 / 0.9e1)*_hc0[7]*_t12*_t71 - _t117*(-_hc0[14]*_t38*_t98 - _hc0[29]*_t97 - _t160*_t174) - _t119*_t127 - _t129 - _t67*(-_hc0[29]*_t12*_t174 - _hc0[32]*_t97 - _t118*_t98)) - _t100*_t112 + _t122*_t28*_t96 + _t123*_t28*_t91));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t8, 0, 0.2e1*_t109 + n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.18e2)*_hc0[9]*_hc1[2]*_t33*_t4*_t5*_t71 + (0.1e1 / 0.144e3)*_hc0[9]*_hc1[5]*_t33*_t53*_t54*_t96 + _hc1[0]*((0.10e2 / 0.9e1)*_hc0[17]*_t159*_t33*tau_s + (0.7e1 / 0.9e1)*_hc0[19]*_t12*_t89 + (0.7e1 / 0.9e1)*_hc0[9]*_t33*_t73 - _t117*((0.5e1 / 0.12e2)*_hc0[14]*_t31*_t38*tau_s - _hc0[17]*_t177 - _hc0[29]*_t107*_t33*_t96 - _hc0[32]*_t104 + (0.1e1 / 0.3e1)*_hc0[7]*_t21*_t31) - _t12*_t130*_t176 - 0.10e2 / 0.9e1*_t175*_t31*_t71 + (0.1e1 / 0.3e1)*_t21*_t31*_t68 - 0.7e1 / 0.9e1*_t31*_t62 - _t67*((0.5e1 / 0.12e2)*_hc0[17]*_t31*_t38*tau_s - _hc0[19]*_t177 - _hc0[32]*_t169*_t96 - _hc0[34]*_t104 + (0.1e1 / 0.3e1)*_hc0[9]*_t21*_t31)) - _t108*_t112 - 0.1e1 / 0.18e2*_t15*_t32*_t43 - 0.1e1 / 0.144e3*_t32*_t38*_t55));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t8, 0, 0.3e1*_t121 + n_s*my_piecewise3(_t8, 0, -_hc0[1]*_t135*_t71 - _hc0[1]*_t136*_t96 + _hc1[0]*((0.80e2 / 0.9e1)*_t116*_t43*tau_s - _t117*(-_t117*(-_hc0[20]*_t37 - _t143 - _t164*_t38) + _t142 - _t145 + _t170*_t96 + _t171*_t71 - _t180*_t67) + (0.56e2 / 0.9e1)*_t119*_t2*_t25 - _t139 - _t149 - 0.440e3 / 0.27e2*_t159*_t178 - _t179*_t89 + (0.80e2 / 0.9e1)*_t43*_t64 - _t67*(_hc0[14]*_t114*_t96 - _t117*_t180 + _t150 - _t152 + _t181*_t71 - _t67*(-_hc0[29]*_t37 - _t153 - _t182*_t20))) + (0.2e1 / 0.3e1)*_hc1[2]*_t21*_t4*_t40*_t5 + (0.1e1 / 0.12e2)*_hc1[5]*_t17*_t40*_t53*_t54 - _t111*_t133*_t91 - _t120*_t137));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t8, 0, 0.3e1*_t132 + n_s*my_piecewise3(_t8, 0, _hc1[0]*(-0.140e3 / 0.27e2*_hc0[9]*_t91 - _t117*(_hc0[17]*_t124 + _hc0[7]*_t125*_t25 - _t117*(-_hc0[14]*_t127 - _hc0[29]*_t44 - _t167*_t38) + _t126*_t71*_t74 - _t127*_t147 - _t184*_t67) - 0.140e3 / 0.27e2*_t12*_t141 + (0.28e2 / 0.9e1)*_t12*_t25*_t68 - _t127*_t155 + (0.80e2 / 0.9e1)*_t128*_t43*tau_s + (0.56e2 / 0.9e1)*_t130*_t2*_t25 - 0.220e3 / 0.27e2*_t28*_t89*tau_s - _t67*(_hc0[17]*_t12*_t126*_t71 + _hc0[19]*_t124 - _t117*_t184 + _t125*_t151 - _t127*_t154 - _t67*(-_hc0[19]*_t127 - _hc0[34]*_t44 - _t182*_t48))) + (0.2e1 / 0.3e1)*_hc1[2]*_t21*_t4*_t49*_t5 + (0.1e1 / 0.12e2)*_hc1[5]*_t17*_t49*_t53*_t54 - 0.1e1 / 0.72e2*_t12*_t133*_t183 - 0.7e1 / 0.27e2*_t13*_t15*_t73 - 0.1e1 / 0.18e2*_t13*_t55*_t71 - _t131*_t137));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t8, 0, 0.4e1*_t157 + n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.216e3)*_hc0[0]*_hc1[14]*_t4*_t96/(M_PI * M_CBRTPI) + (0.40e2 / 0.81e2)*_hc0[0]*_t55*_t73 + (0.140e3 / 0.81e2)*_hc0[0]*_t95 + _hc1[0]*((0.6160e4 / 0.81e2)*_hc0[1]*_t173 - _t117*(-_t117*(_hc0[10]*_t185 - _t117*(-_hc0[20]*_t117 - _hc0[25]*_t67) + _t171*_t25 - _t186*_t67) - _t138*_t178 + (0.80e2 / 0.9e1)*_t144*_t43*tau_s + (0.56e2 / 0.9e1)*_t147*_t2*_t25 - _t179*_t35 - _t188*_t67) + (0.40e2 / 0.3e1)*_t148*_t43*tau_s + (0.28e2 / 0.3e1)*_t155*_t2*_t25 + (0.3640e4 / 0.81e2)*_t183*_t2 - 0.280e3 / 0.9e1*_t2*_t35*_t68 - 0.440e3 / 0.9e1*_t64*_t73*tau_s - _t67*(-_hc0[9]*_t140*_t35 - _t117*_t188 - _t138*_t175 + (0.80e2 / 0.9e1)*_t147*_t43*tau_s + (0.56e2 / 0.9e1)*_t154*_t2*_t25 - _t67*(_hc0[17]*_t185 + _hc0[19]*_t25*_t61 - _t117*_t187 - _t67*(-_hc0[32]*_t117 - _hc0[34]*_t67)))) - 0.2e1 / 0.3e1*_t1*_t15*_t156 + _t133*_t51*_t71 - 0.1e1 / 0.9e1*_t134*_t23 + _t15*_t176*_t69 - 0.4e1 / 0.9e1*_t23*_t43*_t55 - 0.56e2 / 0.27e2*_t25*_t57 + (0.1e1 / 0.6e1)*_t56*_t69));
  out[69] = d4f_dn_s4;
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
  const double ta = tau[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / 0.4e1)*gaa;
  const double _t3 = (0.1e1 / 0.2e1)*ta;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, 0, _t3, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[3];
  const double dF_dta = _hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, (0.1e1 / 0.2e1)*la, _t3, _hc1);
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc1[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dta = (0.1e1 / 0.2e1)*_hc0[11];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[10];
  const double d2F_dgaa_dta = (0.1e1 / 0.4e1)*_hc0[8];
  const double d2F_dta2 = (0.1e1 / 0.2e1)*_hc0[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc1[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc1[33];
  const double d3F_dna2_dta = (0.1e1 / 0.4e1)*_hc1[31];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dta = (0.1e1 / 0.8e1)*_hc0[28];
  const double d3F_dna_dta2 = (0.1e1 / 0.4e1)*_hc0[25];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[24];
  const double d3F_dgaa2_dta = (0.1e1 / 0.16e2)*_hc0[22];
  const double d3F_dgaa_dta2 = (0.1e1 / 0.8e1)*_hc0[19];
  const double d3F_dta3 = (0.1e1 / 0.4e1)*_hc0[15];
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
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc1[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc1[68];
  const double d4F_dna3_dta = (0.1e1 / 0.8e1)*_hc1[66];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc1[65];
  const double d4F_dna2_dgaa_dta = (0.1e1 / 0.16e2)*_hc1[63];
  const double d4F_dna2_dta2 = (0.1e1 / 0.8e1)*_hc1[60];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dta = (0.1e1 / 0.32e2)*_hc0[57];
  const double d4F_dna_dgaa_dta2 = (0.1e1 / 0.16e2)*_hc0[54];
  const double d4F_dna_dta3 = (0.1e1 / 0.8e1)*_hc0[50];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[49];
  const double d4F_dgaa3_dta = (0.1e1 / 0.64e2)*_hc0[47];
  const double d4F_dgaa2_dta2 = (0.1e1 / 0.32e2)*_hc0[44];
  const double d4F_dgaa_dta3 = (0.1e1 / 0.16e2)*_hc0[40];
  const double d4F_dta4 = (0.1e1 / 0.8e1)*_hc0[35];
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
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;
  const double ta = tau[0];
  const double tb = tau[1];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, 0, ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, 0, tb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc0[3];
  const double dF_dgbb = _hc1[3];
  const double dF_dta = _hc0[1];
  const double dF_dtb = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, ta, _hc2);
  double _hc3[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, lb, tb, _hc3);
  const double d2F_dna2 = _hc2[14];
  const double d2F_dnb2 = _hc3[14];
  const double d2F_dna_dgaa = _hc0[13];
  const double d2F_dnb_dgbb = _hc1[13];
  const double d2F_dna_dta = _hc0[11];
  const double d2F_dnb_dtb = _hc1[11];
  const double d2F_dgaa2 = _hc0[10];
  const double d2F_dgbb2 = _hc1[10];
  const double d2F_dgaa_dta = _hc0[8];
  const double d2F_dgbb_dtb = _hc1[8];
  const double d2F_dta2 = _hc0[5];
  const double d2F_dtb2 = _hc1[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 5] += d2F_dgbb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc2[34];
  const double d3F_dnb3 = _hc3[34];
  const double d3F_dna2_dgaa = _hc2[33];
  const double d3F_dnb2_dgbb = _hc3[33];
  const double d3F_dna2_dta = _hc2[31];
  const double d3F_dnb2_dtb = _hc3[31];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dta = _hc0[28];
  const double d3F_dnb_dgbb_dtb = _hc1[28];
  const double d3F_dna_dta2 = _hc0[25];
  const double d3F_dnb_dtb2 = _hc1[25];
  const double d3F_dgaa3 = _hc0[24];
  const double d3F_dgbb3 = _hc1[24];
  const double d3F_dgaa2_dta = _hc0[22];
  const double d3F_dgbb2_dtb = _hc1[22];
  const double d3F_dgaa_dta2 = _hc0[19];
  const double d3F_dgbb_dtb2 = _hc1[19];
  const double d3F_dta3 = _hc0[15];
  const double d3F_dtb3 = _hc1[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += d3F_dnb_dgbb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
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
  const double d4F_dna4 = _hc2[69];
  const double d4F_dnb4 = _hc3[69];
  const double d4F_dna3_dgaa = _hc2[68];
  const double d4F_dnb3_dgbb = _hc3[68];
  const double d4F_dna3_dta = _hc2[66];
  const double d4F_dnb3_dtb = _hc3[66];
  const double d4F_dna2_dgaa2 = _hc2[65];
  const double d4F_dnb2_dgbb2 = _hc3[65];
  const double d4F_dna2_dgaa_dta = _hc2[63];
  const double d4F_dnb2_dgbb_dtb = _hc3[63];
  const double d4F_dna2_dta2 = _hc2[60];
  const double d4F_dnb2_dtb2 = _hc3[60];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dta = _hc0[57];
  const double d4F_dnb_dgbb2_dtb = _hc1[57];
  const double d4F_dna_dgaa_dta2 = _hc0[54];
  const double d4F_dnb_dgbb_dtb2 = _hc1[54];
  const double d4F_dna_dta3 = _hc0[50];
  const double d4F_dnb_dtb3 = _hc1[50];
  const double d4F_dgaa4 = _hc0[49];
  const double d4F_dgbb4 = _hc1[49];
  const double d4F_dgaa3_dta = _hc0[47];
  const double d4F_dgbb3_dtb = _hc1[47];
  const double d4F_dgaa2_dta2 = _hc0[44];
  const double d4F_dgbb2_dtb2 = _hc1[44];
  const double d4F_dgaa_dta3 = _hc0[40];
  const double d4F_dgbb_dtb3 = _hc1[40];
  const double d4F_dta4 = _hc0[35];
  const double d4F_dtb4 = _hc1[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += d4F_dnb2_dgbb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += d4F_dnb_dgbb2_dtb;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += d4F_dnb_dgbb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
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