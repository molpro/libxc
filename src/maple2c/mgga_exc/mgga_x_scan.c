/*
  Generated from python/mgga_exc/mgga_x_scan.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_scan
*/

#ifndef _MGGA_X_SCAN_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_SCAN_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_SCAN_HELPER_BODIES
#include "mgga_x_scan.c"
#undef _MGGA_X_SCAN_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_SCAN_HELPER_BODIES
#include "mgga_x_scan.c"
#undef _MGGA_X_SCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_SCAN_HELPER_BODIES
#include "mgga_x_scan.c"
#undef _MGGA_X_SCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_SCAN_HELPER_BODIES
#include "mgga_x_scan.c"
#undef _MGGA_X_SCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_SCAN_HELPER_BODIES
#include "mgga_x_scan.c"
#undef _MGGA_X_SCAN_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_SCAN_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(mgga_alpha_k, _KMAX)(const xc_func_type *p, double x, double t, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = (0.5e1 / 0.9e1)*_t1;
#if _KMAX >= 1
  const double _t3 = (0.5e1 / 0.36e2)*_t1;
#endif

  const double f = _t2*(t - 0.1e1 / 0.8e1*(x * x));
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t2;
  out[1] = df_dt;
  const double df_dx = -_t3*x;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_dx_dt = 0;
  out[4] = d2f_dx_dt;
  const double d2f_dx2 = -_t3;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_f_alpha_left0_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_scan_params *params = (const mgga_x_scan_params *)(p->params);

  const double _t1 = 0.1e1 - a;
  const double _t2 = params->c1/_t1;
  const double _t3 = exp(-_t2*a);
#if _KMAX >= 1
  const double _t4 = params->c1/(_t1 * _t1);
  const double _t5 = -_t2 - _t4*a;
  const double _t6 = _t3*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = params->c1/(_t1 * _t1 * _t1);
  const double _t8 = _t7*a;
  const double _t9 = -0.2e1*_t4 - 0.2e1*_t8;
  const double _t10 = _t3*_t9;
  const double _t11 = _t3*(_t5 * _t5);
#endif
#if _KMAX >= 3
  const double _t12 = 0.6e1*_t7;
  const double _t13 = params->c1/(_t1 * _t1 * _t1 * _t1);
  const double _t14 = _t13*a;
  const double _t15 = -_t12 - 0.6e1*_t14;
  const double _t16 = -0.4e1*_t4 - 0.4e1*_t8;
#endif

  const double f = _t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t6;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t10 + _t11;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _t15*_t3 + _t16*_t6 + _t3*(_t5 * _t5 * _t5) + _t6*_t9;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = _t10*_t16 + _t11*_t16 + _t11*_t9 + _t11*(-_t12*a - 0.6e1*_t4) + 0.2e1*_t15*_t6 + _t3*(_t5 * _t5 * _t5 * _t5) + _t3*(_t9 * _t9) + _t3*(-0.24e2*_t13 - 0.24e2*a*params->c1/xc_powi(_t1, 5)) + _t6*(-0.12e2*_t14 - 0.12e2*_t7);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_f_alpha_left_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_scan_params *params = (const mgga_x_scan_params *)(p->params);

  const double _t1 = log(XC_EPSILON);
  const double _t2 = -_t1/(-_t1 + params->c1);
  const double _t3 = _t2 > a;
  const double _t4 = a > _t2;
#if _KMAX >= 1
  const double _t5 = my_piecewise3(_t3, 0.1e1, 0);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t4)) XC_CAT(scan_f_alpha_left0_k, _KMAX)(p, my_piecewise3(_t3, a, _t2), _hc0);

  const double f = my_piecewise3(_t4, 0, _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t4, 0, _hc0[1]*_t5);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t4, 0, _hc0[2]*(_t5 * _t5));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t4, 0, _hc0[3]*(_t5 * _t5 * _t5));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t4, 0, _hc0[4]*(_t5 * _t5 * _t5 * _t5));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_f_alpha_right0_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_scan_params *params = (const mgga_x_scan_params *)(p->params);

  const double _t1 = 0.1e1 - a;
  const double _t2 = params->d*exp(params->c2/_t1);
#if _KMAX >= 1
  const double _t3 = _t2*params->c2;
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t5 = _t2*((params->c2) * (params->c2));
#endif
#if _KMAX >= 3
  const double _t6 = xc_powi(_t1, -6);
  const double _t7 = _t2*((params->c2) * (params->c2) * (params->c2));
  const double _t8 = xc_powi(_t1, -5);
#endif

  const double f = -_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t3/(_t1 * _t1);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -_t4*_t5 - 0.2e1*_t3/(_t1 * _t1 * _t1);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -0.6e1*_t3*_t4 - 0.6e1*_t5*_t8 - _t6*_t7;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.24e2*_t3*_t8 - 0.36e2*_t5*_t6 - 0.12e2*_t7/xc_powi(_t1, 7) - _t2*((params->c2) * (params->c2) * (params->c2) * (params->c2))/xc_powi(_t1, 8);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_f_alpha_right_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_scan_params *params = (const mgga_x_scan_params *)(p->params);

  const double _t1 = log(XC_EPSILON/my_piecewise3(params->d >= 0, params->d, -params->d));
  const double _t2 = -(-_t1 + params->c2)/_t1;
  const double _t3 = _t2 > a;
  const double _t4 = a < _t2;
#if _KMAX >= 1
  const double _t5 = my_piecewise3(_t3, 0, 0.1e1);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_f_alpha_right0_k, _KMAX)(p, my_piecewise3(_t3, _t2, a), _hc0);

  const double f = my_piecewise3(_t4, 0, _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t4, 0, _hc0[1]*_t5);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t4, 0, _hc0[2]*(_t5 * _t5));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t4, 0, _hc0[3]*(_t5 * _t5 * _t5));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t4, 0, _hc0[4]*(_t5 * _t5 * _t5 * _t5));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_f_alpha_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_f_alpha_left_k, _KMAX)(p, a, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_f_alpha_right_k, _KMAX)(p, a, _hc1);
  const double _t1 = a <= 0.1e1;

  const double f = my_piecewise3(_t1, _hc0[0], _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t1, _hc0[1], _hc1[1]);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t1, _hc0[2], _hc1[2]);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t1, _hc0[3], _hc1[3]);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t1, _hc0[4], _hc1[4]);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_h1x_k, _KMAX)(const xc_func_type *p, double x, double *out) {
  const mgga_x_scan_params *params = (const mgga_x_scan_params *)(p->params);

  const double _t1 = params->k1 + x;
  const double _t2 = (0.1e1 / _t1);
#if _KMAX >= 1
  const double _t3 = params->k1/(_t1 * _t1);
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (_t1 * _t1 * _t1));
#endif
#if _KMAX >= 3
  const double _t5 = params->k1/(_t1 * _t1 * _t1 * _t1);
#endif

  const double f = _t2*params->k1*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t2*params->k1 - _t3*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.2e1*_t3 + 0.2e1*_t4*params->k1*x;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.6e1*_t4*params->k1 - 0.6e1*_t5*x;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = -0.24e2*_t5 + 0.24e2*params->k1*x/xc_powi(_t1, 5);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_y_k, _KMAX)(const xc_func_type *p, double x, double a, double *out) {
  const mgga_x_scan_params *params = (const mgga_x_scan_params *)(p->params);

  const double _t1 = (x * x);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
  const double _t6 = (x * x * x * x);
  const double _t7 = xc_powr(0.6e1, 2, 3);
  const double _t8 = _t7/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t9 = 0.73e2 / 0.648e3 - (0.100e3 / 0.6561e4)/params->k1;
  const double _t10 = (0.27e2 / 0.80e2)*_t9;
  const double _t11 = -_t9*exp(_t10*_t5);
  const double _t12 = _t11*_t8;
  const double _t13 = xc_powr(0.2e1, 5, 6)*M_CBRT3*xc_powr(0.73e2, 1, 2)*_t3;
  const double _t14 = 0.1e1 - a;
  const double _t15 = (_t14 * _t14);
  const double _t16 = xc_powr(0.146e3, 1, 2)*exp(-0.1e1 / 0.2e1*_t15);
  const double _t17 = (0.1e1 / 0.100e3)*_t16;
  const double _t18 = _t14*_t17;
  const double _t19 = (0.7e1 / 0.12960e5)*_t1*_t13 + _t18;
#if _KMAX >= 1
  const double _t20 = (0.1e1 / 0.50e2)*_t16;
  const double _t21 = _t15*_t20 - _t20;
  const double _t22 = (0.5e1 / 0.486e3)*_t4;
  const double _t23 = (x * x * x);
  const double _t24 = xc_powi(x, 5);
  const double _t25 = _t11/(M_PI * M_PI * M_PI * M_PI);
  const double _t26 = _t25*_t9;
  const double _t27 = (0.7e1 / 0.3240e4)*_t13;
  const double _t28 = _t19*_t27;
#endif
#if _KMAX >= 2
  const double _t29 = _t15*_t17 - _t17;
  const double _t30 = _t14*_t20;
  const double _t31 = 0.2e1*a - 0.2e1;
  const double _t32 = (_t14 * _t14 * _t14);
  const double _t33 = _t20*_t31 + _t20*_t32 - _t30;
  const double _t34 = _t27*_t29;
  const double _t35 = _t1*_t8;
  const double _t36 = _t11*xc_powi(x, 6);
  const double _t37 = _t2*(_t9 * _t9)/(M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
#endif
#if _KMAX >= 3
  const double _t38 = _t17*_t31 + _t17*_t32 - _t18;
  const double _t39 = _t15*_t16;
  const double _t40 = (_t14 * _t14 * _t14 * _t14);
  const double _t41 = (0.3e1 / 0.50e2)*_t16 + _t20*_t40 + _t30*_t31 - 0.2e1 / 0.25e2*_t39;
  const double _t42 = _t27*_t38;
  const double _t43 = (0.3577e4 / 0.3499200e7)*_t8;
  const double _t44 = (0.1e1 / 0.24e2)*_t12;
  const double _t45 = _t11*_t37;
  const double _t46 = _t7*(_t9 * _t9 * _t9)/(M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI);
#endif
#if _KMAX >= 4
  const double _t47 = (0.3e1 / 0.100e3)*_t16 + _t17*_t40 + _t18*_t31 - 0.1e1 / 0.25e2*_t39;
  const double _t48 = (0.1e1 / 0.10e2)*_t16;
#endif

  const double f = (0.1e1 / 0.576e3)*_t12*_t6 + (_t19 * _t19) + (0.5e1 / 0.972e3)*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t19*_t21;
  out[1] = df_da;
  const double df_dx = (0.1e1 / 0.144e3)*_t12*_t23 + _t22*x + (0.9e1 / 0.1280e4)*_t24*_t26 + _t28*x;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t19*_t33 + _t21*_t29;
  out[3] = d2f_da2;
  const double d2f_dx_da = _t34*x;
  out[4] = d2f_dx_da;
  const double d2f_dx2 = (0.1e1 / 0.48e2)*_t11*_t35 + _t22 + (0.81e2 / 0.1280e4)*_t26*_t6 + _t28 + (0.3577e4 / 0.10497600e8)*_t35 + (0.243e3 / 0.51200e5)*_t36*_t37;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _t19*_t41 + _t21*_t38 + 0.2e1*_t29*_t33;
  out[6] = d3f_da3;
  const double d3f_dx_da2 = _t42*x;
  out[7] = d3f_dx_da2;
  const double d3f_dx2_da = _t34;
  out[8] = d3f_dx2_da;
  const double d3f_dx3 = _t10*_t23*_t25 + (0.6561e4 / 0.2048000e7)*_t11*_t46*xc_powi(x, 7) + (0.729e3 / 0.10240e5)*_t24*_t45 + _t43*x + _t44*x;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = _t19*(xc_powi(_t14, 5)*_t20 + _t14*_t48 - 0.4e1 / 0.25e2*_t16*_t32 - _t31*_t48 + _t39*((0.1e1 / 0.25e2)*a - 0.1e1 / 0.25e2)) + _t21*_t47 + 0.3e1*_t29*_t41 + 0.3e1*_t33*_t38;
  out[10] = d4f_da4;
  const double d4f_dx_da3 = _t27*_t47*x;
  out[11] = d4f_dx_da3;
  const double d4f_dx2_da2 = _t42;
  out[12] = d4f_dx2_da2;
  const double d4f_dx3_da = 0;
  out[13] = d4f_dx3_da;
  const double d4f_dx4 = (0.189e3 / 0.160e3)*_t1*_t26 + (0.531441e6 / 0.40960000e8)*_t11*(_t9 * _t9 * _t9 * _t9)*xc_powi(x, 8)/xc_powi(M_PI, 8) + (0.72171e5 / 0.1024000e7)*_t36*_t46 + _t43 + _t44 + (0.29889e5 / 0.51200e5)*_t45*_t6;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_gx_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = xc_powr(0.3e1, 1, 6);
  const double _t3 = M_CBRTPI;
  const double _t4 = _t1*_t2*_t3;
  const double _t5 = xc_expm1(-4.9478999999999997*_t4/xc_powr(x, 1, 2));
#if _KMAX >= 1
  const double _t6 = _t5 + 0.1e1;
  const double _t7 = _t4*_t6;
#endif
#if _KMAX >= 2
  const double _t8 = xc_powr(0.6e1, 1, 3);
  const double _t9 = (M_CBRTPI * M_CBRTPI);
  const double _t10 = _t6*_t8*_t9;
#endif
#if _KMAX >= 3
  const double _t11 = xc_powr(x, -9, 2);
  const double _t12 = xc_powr(0.3e1, 1, 2);
#endif

  const double f = -_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -2.4739499999999999*_t7/xc_powr(x, 3, 2);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 3.7109249999999996*_t1*_t2*_t3*_t6/xc_powr(x, 5, 2) - 12.240857204999999*_t10/(x * x * x);
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -60.566537364619492*M_PI*_t11*_t12*_t6 + 55.083857422499996*_t6*_t8*_t9/(x * x * x * x) - 9.277312499999999*_t7/xc_powr(x, 7, 2);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 32.470593749999999*_t1*_t11*_t2*_t3*_t6 - 266.23864420874997*_t10/xc_powi(x, 5) + 545.09883628157547*M_PI*_t12*_t6/xc_powr(x, 11, 2) - 149.83858511320039*xc_powr(0.6e1, 2, 3)*(M_PI * M_CBRTPI)*_t6/xc_powi(x, 6);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_f_a_k, _KMAX)(const xc_func_type *p, double x, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_f_alpha_k, _KMAX)(p, a, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_y_k, _KMAX)(p, x, a, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_h1x_k, _KMAX)(p, _hc1[0], _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_gx_k, _KMAX)(p, x, _hc3);
  const double _t1 = 0.1e1 - _hc0[0];
  const double _t2 = 1.1739999999999999*_hc0[0] + _hc2[0]*_t1;
#if _KMAX >= 1
  const double _t3 = _hc2[1]*_t1;
  const double _t4 = -_hc0[1]*_hc2[0] + 1.1739999999999999*_hc0[1] + _hc1[1]*_t3;
  const double _t5 = _hc3[0]*_t3;
#endif
#if _KMAX >= 2
  const double _t6 = _hc0[1]*_hc2[1];
  const double _t7 = 0.2e1*_hc1[1];
  const double _t8 = ((_hc1[1]) * (_hc1[1]));
  const double _t9 = _hc2[2]*_t1;
  const double _t10 = -_hc0[2]*_hc2[0] + 1.1739999999999999*_hc0[2] + _hc1[3]*_t3 - _t6*_t7 + _t8*_t9;
  const double _t11 = _hc1[2]*_hc3[0];
  const double _t12 = _hc1[1]*_t9;
  const double _t13 = _hc1[2]*_t3;
  const double _t14 = 0.2e1*_hc3[1];
  const double _t15 = ((_hc1[2]) * (_hc1[2]));
  const double _t16 = _hc3[0]*_t15;
#endif
#if _KMAX >= 3
  const double _t17 = 0.3e1*_hc1[3];
  const double _t18 = _hc0[2]*_hc2[1];
  const double _t19 = 0.3e1*_hc1[1];
  const double _t20 = _hc0[1]*_hc2[2];
  const double _t21 = 0.3e1*_t8;
  const double _t22 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t23 = -_hc0[3]*_hc2[0] + 1.1739999999999999*_hc0[3] + 0.3e1*_hc1[1]*_hc1[3]*_hc2[2]*_t1 + _hc1[6]*_hc2[1]*_t1 + _hc2[3]*_t1*_t22 - _t17*_t6 - _t18*_t19 - _t20*_t21;
  const double _t24 = _hc3[0]*_t6;
  const double _t25 = 0.2e1*_t24;
  const double _t26 = _t11*_t20;
  const double _t27 = _t11*_t9;
  const double _t28 = _hc1[4]*_hc3[0];
  const double _t29 = _t7*_t9;
  const double _t30 = _hc2[3]*_t1;
  const double _t31 = _t30*_t8;
  const double _t32 = _hc1[2]*_t14;
  const double _t33 = _hc1[5]*_hc3[0];
  const double _t34 = _t14*_t3;
  const double _t35 = _hc1[2]*_hc3[1];
  const double _t36 = 0.2e1*_t27;
  const double _t37 = _t16*_t30;
  const double _t38 = 0.3e1*_hc3[2];
  const double _t39 = 0.3e1*_hc3[1];
  const double _t40 = _hc1[5]*_t3;
  const double _t41 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t42 = _hc3[0]*_t41;
  const double _t43 = 0.3e1*_t9;
  const double _t44 = _t11*_t43;
  const double _t45 = _hc3[1]*_t15;
#endif
#if _KMAX >= 4
  const double _t46 = _hc0[3]*_hc2[1];
  const double _t47 = 0.4e1*_hc1[1];
  const double _t48 = _hc1[1]*_t20;
  const double _t49 = _hc0[1]*_hc2[3];
  const double _t50 = _hc0[2]*_hc2[2];
  const double _t51 = _t11*_t19;
  const double _t52 = _hc3[0]*_t9;
  const double _t53 = _hc2[4]*_t1;
  const double _t54 = _t11*_t30;
  const double _t55 = 0.4e1*_hc3[1];
  const double _t56 = _hc1[3]*_t9;
  const double _t57 = _hc3[1]*_t9;
  const double _t58 = _hc1[4]*_t47;
  const double _t59 = _t35*_t9;
  const double _t60 = 0.6e1*_hc3[2];
#endif

  const double f = _hc3[0]*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _hc3[0]*_t4;
  out[1] = df_da;
  const double df_dx = _hc1[2]*_t5 + _hc3[1]*_t2;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _hc3[0]*_t10;
  out[3] = d2f_da2;
  const double d2f_dx_da = _hc1[4]*_t5 + _hc3[1]*_t4 + _t11*_t12 - _t11*_t6;
  out[4] = d2f_dx_da;
  const double d2f_dx2 = _hc1[5]*_t5 + _hc3[2]*_t2 + _t13*_t14 + _t16*_t9;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _hc3[0]*_t23;
  out[6] = d3f_da3;
  const double d3f_dx_da2 = _hc1[3]*_t27 - _hc1[4]*_t25 + _hc1[7]*_t5 + _hc3[1]*_t10 - _t11*_t18 + _t11*_t31 - _t26*_t7 + _t28*_t29;
  out[7] = d3f_dx_da2;
  const double d3f_dx2_da = _hc1[1]*_t37 + _hc1[4]*_t34 + _hc1[4]*_t36 + _hc1[8]*_t5 + _hc3[2]*_t4 + _t12*_t33 - _t16*_t20 + _t29*_t35 - _t32*_t6 - _t33*_t6;
  out[8] = d3f_dx2_da;
  const double d3f_dx3 = _hc1[5]*_t44 + _hc1[9]*_t5 + _hc3[3]*_t2 + _t13*_t38 + _t30*_t42 + _t39*_t40 + _t43*_t45;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = _hc3[0]*(-_hc0[4]*_hc2[0] + 1.1739999999999999*_hc0[4] + ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_hc2[4]*_t1 + 0.4e1*_hc1[1]*_hc1[6]*_hc2[2]*_t1 + _hc1[10]*_hc2[1]*_t1 + 0.3e1*((_hc1[3]) * (_hc1[3]))*_hc2[2]*_t1 + 0.6e1*_hc1[3]*_hc2[3]*_t1*_t8 - 0.6e1*_hc1[3]*_t18 - 0.12e2*_hc1[3]*_t48 - 0.4e1*_hc1[6]*_t6 - 0.4e1*_t22*_t49 - _t46*_t47 - 0.6e1*_t50*_t8);
  out[10] = d4f_da4;
  const double d4f_dx_da3 = _hc1[1]*_t17*_t54 + _hc1[11]*_t5 + _hc1[6]*_t27 + _hc1[7]*_t19*_t52 - 0.3e1*_hc1[7]*_t24 + _hc3[1]*_t23 - _t11*_t21*_t49 + _t11*_t22*_t53 - _t11*_t46 - _t17*_t26 + _t17*_t28*_t9 - 0.3e1*_t18*_t28 + _t21*_t28*_t30 - 0.6e1*_t28*_t48 - _t50*_t51;
  out[11] = d4f_dx_da3;
  const double d4f_dx2_da2 = _hc1[12]*_t5 + _hc1[3]*_t37 + 0.2e1*((_hc1[4]) * (_hc1[4]))*_t52 - 0.4e1*_hc1[4]*_t26 - _hc1[4]*_t55*_t6 + _hc1[7]*_t34 + _hc1[7]*_t36 - _hc1[8]*_t25 + _hc1[8]*_t52*_t7 + _hc3[2]*_t10 - _t16*_t49*_t7 - _t16*_t50 + _t16*_t53*_t8 - _t18*_t32 - _t18*_t33 - _t20*_t33*_t7 - _t20*_t35*_t47 + _t31*_t32 + _t31*_t33 + _t32*_t56 + _t33*_t56 + _t54*_t58 + _t57*_t58;
  out[12] = d4f_dx2_da2;
  const double d4f_dx3_da = _hc1[1]*_t42*_t53 + _hc1[2]*_hc3[2]*_t19*_t9 - _hc1[2]*_t38*_t6 + _hc1[4]*_t3*_t38 + _hc1[4]*_t33*_t43 + 0.3e1*_hc1[4]*_t37 + 0.6e1*_hc1[4]*_t59 + _hc1[5]*_t19*_t57 - 0.3e1*_hc1[5]*_t26 + _hc1[5]*_t30*_t51 - _hc1[5]*_t39*_t6 + _hc1[8]*_t3*_t39 + _hc1[8]*_t44 + _hc1[9]*_hc3[0]*_t12 - _hc1[9]*_t24 + _hc3[3]*_t4 - _t15*_t20*_t39 + _t19*_t30*_t45 - _t42*_t49;
  out[13] = d4f_dx3_da;
  const double d4f_dx4 = _hc1[14]*_t5 + ((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]))*_hc3[0]*_t53 + ((_hc1[5]) * (_hc1[5]))*_hc3[0]*_t43 + 0.6e1*_hc1[5]*_t37 + 0.12e2*_hc1[5]*_t59 + 0.4e1*_hc1[9]*_t27 + _hc1[9]*_t3*_t55 + 0.4e1*_hc3[3]*_t13 + _hc3[4]*_t2 + _t15*_t60*_t9 + _t30*_t41*_t55 + _t40*_t60;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_f_k, _KMAX)(const xc_func_type *p, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mgga_alpha_k, _KMAX)(p, x, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_f_a_k, _KMAX)(p, x, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = ((_hc0[1]) * (_hc0[1]));
  const double _t2 = _hc0[2]*_hc1[3];
  const double _t3 = _hc1[4] + _t2;
#endif
#if _KMAX >= 3
  const double _t4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t5 = _hc0[2]*_hc1[6];
  const double _t6 = _hc0[1]*_hc1[7];
  const double _t7 = _hc0[5]*_hc1[3];
  const double _t8 = _hc0[1]*_t5 + _t6;
  const double _t9 = _hc0[2]*_hc1[7] + _hc1[8];
  const double _t10 = 0.2e1*_hc0[5];
  const double _t11 = _hc1[7] + _t5;
  const double _t12 = _hc0[2]*_t11 + _t7 + _t9;
#endif
#if _KMAX >= 4
  const double _t13 = _hc0[2]*_hc1[10];
  const double _t14 = _hc1[11]*_t1;
  const double _t15 = _hc0[5]*_hc1[6];
  const double _t16 = _hc0[1]*_hc1[12];
  const double _t17 = _hc0[1]*_hc1[11];
  const double _t18 = _hc0[2]*_t17 + _t16;
  const double _t19 = _hc0[2]*_hc1[12] + _hc1[13];
  const double _t20 = _hc0[2]*_hc1[11] + _hc1[12];
  const double _t21 = _hc0[2]*_t20 + _hc0[5]*_hc1[7] + _t19;
#endif

  const double f = _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1]*_hc1[1];
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc0[2]*_hc1[1] + _hc1[2];
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[3]*_t1;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx_dt = _hc0[1]*_hc1[4] + _hc0[1]*_t2;
  out[7] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[8] = d2f_dx_du;
  const double d2f_dx2 = _hc0[2]*_hc1[4] + _hc0[2]*_t3 + _hc0[5]*_hc1[1] + _hc1[5];
  out[9] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc1[6]*_t4;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx_dt2 = _hc1[7]*_t1 + _t1*_t5;
  out[14] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[15] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[16] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc0[1]*_hc1[8] + _hc0[1]*_t7 + _hc0[2]*_t6 + _hc0[2]*_t8;
  out[17] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[18] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[2]*_hc1[8] + _hc0[2]*_t12 + _hc0[2]*_t9 + _hc0[5]*_hc1[4] + _hc1[9] + _t10*_t3;
  out[19] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[10];
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx_dt3 = _hc1[11]*_t4 + _t13*_t4;
  out[25] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[26] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[27] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[28] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc0[2]*_t14 + _hc0[2]*(_t1*_t13 + _t14) + _hc1[12]*_t1 + _t1*_t15;
  out[29] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[30] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[31] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc0[1]*_hc1[13] + _hc0[2]*_t16 + _hc0[2]*_t18 + _hc0[2]*(_hc0[1]*_t15 + _hc0[2]*(_hc0[1]*_t13 + _t17) + _t18) + _hc0[5]*_t6 + _t10*_t8;
  out[32] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[33] = d4f_dx3_du;
  const double d4f_dx4 = _hc0[2]*_hc1[13] + _hc0[2]*_t19 + _hc0[2]*_t21 + _hc0[2]*(_hc0[2]*(_hc0[2]*(_hc1[11] + _t13) + _t15 + _t20) + _t10*_t11 + _t21) + _hc0[5]*_hc1[8] + 0.3e1*_hc0[5]*_t12 + _hc1[14] + _t10*_t9;
  out[34] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_scan_params *params = (const mgga_x_scan_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = xc_powr(n_s, -4, 3);
  const double _t6 = xc_powr(sigma_ss, 1, 2);
  const double _t7 = xc_powr(n_s, -5, 3);
  const double _t8 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t12 = (0.1e1 / _t6);
  const double _t17 = xc_powr(n_s, -8, 3);
  const double _t18 = (0.5e1 / 0.3e1)*_t17;
  const double _t20 = (0.4e1 / 0.3e1)*_t6;
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
  const double _t58 = (0.1e1 / 0.3e1)*_t5;
  const double _t59 = (0.40e2 / 0.9e1)*_t43;
  const double _t61 = (0.28e2 / 0.9e1)*_t6;
  const double _t67 = _t20*_t21;
#endif
#if _KMAX >= 3
  const double _t71 = xc_powi(n_s, -5);
  const double _t73 = xc_powr(n_s, -14, 3);
  const double _t82 = xc_powr(sigma_ss, -5, 2);
  const double _t86 = (0.1e1 / (sigma_ss * sigma_ss));
  const double _t89 = (0.10e2 / 0.3e1)*_t35;
  const double _t90 = xc_powi(n_s, -6);
  const double _t92 = xc_powr(n_s, -17, 3);
  const double _t97 = xc_powr(n_s, -16, 3);
  const double _t98 = (0.2e1 / 0.3e1)*_t97;
  const double _t99 = (0.3e1 / 0.2e1)*_t12;
  const double _t105 = (0.1e1 / 0.3e1)*_t12;
  const double _t106 = _t105*_t71;
  const double _t107 = (0.1e1 / 0.3e1)*_t33;
  const double _t109 = (0.5e1 / 0.12e2)*tau_s;
  const double _t116 = (0.40e2 / 0.9e1)*tau_s;
  const double _t119 = _t18*tau_s;
  const double _t126 = (0.14e2 / 0.9e1)*_t73;
  const double _t127 = (0.14e2 / 0.9e1)*_t12;
  const double _t128 = (0.20e2 / 0.9e1)*tau_s;
  const double _t129 = _t21*_t45;
  const double _t140 = (0.440e3 / 0.27e2)*_t73;
  const double _t142 = (0.280e3 / 0.27e2)*_t6;
#endif
#if _KMAX >= 4
  const double _t160 = xc_powr(n_s, -20, 3);
  const double _t161 = xc_powr(n_s, -19, 3);
  const double _t163 = (0.1e1 / 0.6e1)*_t161;
  const double _t165 = xc_powr(n_s, -22, 3);
  const double _t167 = xc_powi(n_s, -7);
  const double _t171 = _t109*_t33;
  const double _t175 = _t92*tau_s;
  const double _t176 = (0.5e1 / 0.6e1)*_t175;
  const double _t180 = (0.4e1 / 0.3e1)*_t21;
  const double _t181 = _t107*_t43;
  const double _t189 = _t59*tau_s;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t8)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t8)) XC_CAT(scan_f_k, _KMAX)(p, _t5*_t6, 0, _t7*tau_s, _hc1);
  const double _t9 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t10 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[1]*_t7);
  const double _t11 = (0.1e1 / 0.2e1)*_hc0[0];
  const double _t13 = _hc1[3]*_t12;
  const double _t14 = my_piecewise3(_t8, 0, _t11*_t13*_t5);
  const double _t15 = _hc0[2]*_t3;
  const double _t16 = (0.1e1 / 0.6e1)*_t15;
  const double _t19 = _hc1[1]*_t18;
  const double _t22 = _hc1[3]*_t21;
  const double _t23 = -_t19*tau_s - _t20*_t22;
  const double _t24 = my_piecewise3(_t8, 0, _hc0[0]*_t23 - _hc1[0]*_t16*_t5);
#endif
#if _KMAX >= 2
  const double _t26 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[4]*_t25);
  const double _t28 = _hc1[7]*_t12;
  const double _t29 = my_piecewise3(_t8, 0, _t11*_t27*_t28);
  const double _t30 = (0.1e1 / 0.4e1)*_hc0[0];
  const double _t32 = _hc1[3]*_t31;
  const double _t34 = my_piecewise3(_t8, 0, (0.1e1 / 0.4e1)*_hc0[0]*_hc1[9]*_t17*_t33 - _t30*_t32*_t5);
  const double _t39 = _hc1[7]*_t20;
  const double _t40 = -_hc1[4]*_t37 - _t19 - _t38*_t39;
  const double _t41 = my_piecewise3(_t8, 0, _hc0[0]*_t40 - _hc1[1]*_t16*_t27);
  const double _t42 = _t15*_t17;
  const double _t46 = _hc1[7]*_t38;
  const double _t49 = -_hc1[9]*_t44 - _t22*_t45 - _t46*_t48;
  const double _t50 = my_piecewise3(_t8, 0, _hc0[0]*_t49 - 0.1e1 / 0.12e2*_t13*_t42);
  const double _t51 = (0.2e1 / 0.9e1)*_hc1[0];
  const double _t52 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t55 = _hc0[5]*_t53*_t54;
  const double _t56 = _t17*_t55;
  const double _t57 = _t15*_t23;
  const double _t60 = _hc1[1]*_t59;
  const double _t62 = _hc1[3]*_t25;
  const double _t63 = _hc1[4]*_t18;
  const double _t64 = -_t21*_t39 - _t63*tau_s;
  const double _t65 = _t18*_t64;
  const double _t66 = _hc1[7]*_t18;
  const double _t68 = -_hc1[9]*_t67 - _t66*tau_s;
  const double _t69 = _t60*tau_s + _t61*_t62 - _t65*tau_s - _t67*_t68;
  const double _t70 = my_piecewise3(_t8, 0, _hc0[0]*_t69 + _t15*_t21*_t51 + _t52*_t56 - _t57*_t58);
#endif
#if _KMAX >= 3
  const double _t72 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[10]*_t71);
  const double _t74 = _hc1[14]*_t12;
  const double _t75 = my_piecewise3(_t8, 0, _t11*_t73*_t74);
  const double _t76 = _hc1[17]*_t33;
  const double _t77 = _t30*_t31;
  const double _t78 = _hc1[7]*_t27;
  const double _t79 = my_piecewise3(_t8, 0, _t30*_t35*_t76 - _t77*_t78);
  const double _t80 = _hc1[19]*_t38;
  const double _t81 = (0.1e1 / 0.8e1)*_hc0[0]*_t31;
  const double _t83 = (0.3e1 / 0.8e1)*_hc0[0];
  const double _t84 = _t82*_t83;
  const double _t85 = _hc1[3]*_t5;
  const double _t87 = _hc1[9]*_t86;
  const double _t88 = my_piecewise3(_t8, 0, -_t17*_t83*_t87 + _t80*_t81 + _t84*_t85);
  const double _t91 = _hc1[10]*_t90;
  const double _t93 = _hc1[14]*_t20;
  const double _t94 = -_hc1[4]*_t89 - _t36*_t91 - _t92*_t93;
  const double _t95 = my_piecewise3(_t8, 0, _hc0[0]*_t94 - _hc1[4]*_t16*_t73);
  const double _t96 = _t15*_t35;
  const double _t100 = _t74*_t92;
  const double _t101 = -_hc1[17]*_t98 - _t100*_t47 - _t46*_t99;
  const double _t102 = my_piecewise3(_t8, 0, _hc0[0]*_t101 - 0.1e1 / 0.12e2*_t28*_t96);
  const double _t103 = _hc1[9]*_t33;
  const double _t104 = (0.1e1 / 0.24e2)*_t15;
  const double _t108 = _t76*_t97;
  const double _t110 = -_hc1[19]*_t106 + (0.1e1 / 0.3e1)*_hc1[3]*_t21*_t31 + (0.5e1 / 0.12e2)*_hc1[7]*_t31*_t38*tau_s - _hc1[9]*_t107*_t43 - _t108*_t109;
  const double _t111 = my_piecewise3(_t8, 0, _hc0[0]*_t110 - _t103*_t104*_t38 + (0.1e1 / 0.24e2)*_t32*_t42);
  const double _t112 = (0.2e1 / 0.9e1)*_t15;
  const double _t113 = (0.1e1 / 0.36e2)*_hc1[1];
  const double _t114 = _t15*_t58;
  const double _t115 = _hc1[4]*_t97;
  const double _t117 = _hc1[7]*_t61;
  const double _t118 = -_hc1[10]*_t37 - _t38*_t93 - _t63;
  const double _t120 = _hc1[17]*_t38;
  const double _t121 = -_hc1[14]*_t37 - _t120*_t20 - _t66;
  const double _t122 = _t115*_t116 + _t117*_t71 - _t118*_t119 - _t121*_t67 + _t60 - _t65;
  const double _t123 = my_piecewise3(_t8, 0, _hc0[0]*_t122 + _hc1[1]*_t112*_t38 + _t113*_t35*_t55 - _t114*_t40);
  const double _t124 = (0.1e1 / 0.9e1)*_t15;
  const double _t125 = (0.1e1 / 0.72e2)*_t55;
  const double _t130 = -_hc1[17]*_t44 - _hc1[7]*_t129 - _t38*_t47*_t74;
  const double _t131 = _t130*_t18;
  const double _t132 = -_hc1[19]*_t44 - _hc1[9]*_t129 - _t120*_t48;
  const double _t133 = _hc1[9]*_t126 + _t127*_t62 + _t128*_t28*_t71 - _t129*_t68 - _t131*tau_s - _t132*_t67;
  const double _t134 = my_piecewise3(_t8, 0, _hc0[0]*_t133 - _t114*_t49 + _t124*_t13*_t43 + _t125*_t13*_t38);
  const double _t135 = _hc0[9]/M_PI;
  const double _t136 = _t135*_t38;
  const double _t137 = (0.14e2 / 0.27e2)*_t15;
  const double _t138 = (0.1e1 / 0.9e1)*_t55;
  const double _t139 = _hc0[2]*_t4*_t5;
  const double _t141 = _hc1[1]*_t140;
  const double _t143 = _hc1[3]*_t35;
  const double _t144 = _hc1[4]*_t59;
  const double _t145 = _hc1[10]*_t18;
  const double _t146 = -_hc1[14]*_t67 - _t145*tau_s;
  const double _t147 = _t146*_t18;
  const double _t148 = _hc1[14]*_t18;
  const double _t149 = -_hc1[17]*_t67 - _t148*tau_s;
  const double _t150 = _t117*_t25 + _t144*tau_s - _t147*tau_s - _t149*_t67;
  const double _t151 = _t150*_t18;
  const double _t152 = _hc1[7]*_t59;
  const double _t153 = _hc1[9]*_t25;
  const double _t154 = _t149*_t18;
  const double _t155 = _hc1[17]*_t18;
  const double _t156 = -_hc1[19]*_t67 - _t155*tau_s;
  const double _t157 = _t152*tau_s + _t153*_t61 - _t154*tau_s - _t156*_t67;
  const double _t158 = -_t141*tau_s - _t142*_t143 - _t151*tau_s - _t157*_t67 + (0.56e2 / 0.9e1)*_t25*_t6*_t68 + (0.80e2 / 0.9e1)*_t43*_t64*tau_s;
  const double _t159 = my_piecewise3(_t8, 0, _hc0[0]*_t158 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t21*_t23 + (0.1e1 / 0.12e2)*_hc0[5]*_t17*_t23*_t53*_t54 - _hc1[0]*_t137*_t25 - _hc1[0]*_t138*_t43 - _t136*_t52 - _t139*_t69);
#endif
#if _KMAX >= 4
  const double _t162 = _hc1[25]*_t12;
  const double _t164 = _hc1[20]*_t36;
  const double _t166 = _hc1[25]*_t20;
  const double _t168 = _hc1[29]*_t167;
  const double _t169 = _hc1[25]*_t48;
  const double _t170 = _hc1[32]*_t160;
  const double _t172 = _hc1[10]*_t116;
  const double _t173 = _hc1[14]*_t61;
  const double _t174 = _hc1[29]*_t20;
  const double _t177 = (0.1e1 / 0.18e2)*_t15;
  const double _t178 = (0.1e1 / 0.144e3)*_t55;
  const double _t179 = _hc1[7]*tau_s;
  const double _t182 = _hc1[4]*tau_s;
  const double _t183 = _hc1[7]*_t142;
  const double _t184 = -_hc1[25]*_t37 - _t148 - _t174*_t38;
  const double _t185 = _hc1[17]*_t61;
  const double _t186 = _hc1[32]*_t38;
  const double _t187 = _hc1[3]*_t97;
  const double _t188 = -_hc1[17]*_t129 - _hc1[29]*_t38*_t48 - _hc1[32]*_t44;
  const double _t190 = -_hc1[25]*_t119 - _hc1[29]*_t67;
  const double _t191 = -_hc1[29]*_t119 - _hc1[32]*_t67;
  const double _t192 = _hc1[14]*_t189 - _t119*_t190 + _t185*_t25 - _t191*_t67;
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
  const double d3f_dsigma_ss3 = my_piecewise3(_t8, 0, _t88*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t8, 0, _t26 + _t95*n_s);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t8, 0, _t102*n_s + _t29);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t8, 0, _t111*n_s + _t34);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t8, 0, _t123*n_s + 0.2e1*_t41);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t8, 0, _t134*n_s + 0.2e1*_t50);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t8, 0, _t159*n_s + 0.3e1*_t70);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, _hc0[0]*_hc1[20]*_t160));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, _t11*_t161*_t162));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.4e1)*_hc0[0]*_hc1[29]*_t33*_t90 - _hc1[14]*_t73*_t77));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, -_hc1[17]*_t35*_t83*_t86 + _hc1[32]*_t81*_t92 + _t78*_t84));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.16e2)*_hc0[0]*_hc1[34]*_t86*_t97 + (0.15e2 / 0.16e2)*_hc0[0]*_hc1[9]*_t17/(sigma_ss * sigma_ss * sigma_ss) - 0.15e2 / 0.16e2*_hc0[0]*_t85/xc_powr(sigma_ss, 7, 2) - _t80*_t84));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t8, 0, _t72 + n_s*my_piecewise3(_t8, 0, _hc0[0]*(-_t164/xc_powr(n_s, 23, 3) - _t165*_t166 - 0.5e1*_t91) - _hc1[10]*_t15*_t163));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t8, 0, _t75 + n_s*my_piecewise3(_t8, 0, _hc0[0]*(-0.7e1 / 0.3e1*_t100 - _t165*_t169 - 0.2e1 / 0.3e1*_t168) - 0.1e1 / 0.12e2*_t15*_t74*_t90));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t8, 0, _t79 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.5e1 / 0.12e2)*_hc1[14]*_t31*_t92*tau_s + (0.3e1 / 0.4e1)*_hc1[7]*_t31*_t38 - _t105*_t170 - 0.3e1 / 0.4e1*_t108 - _t168*_t171) + (0.1e1 / 0.24e2)*_hc1[7]*_t31*_t96 - _t104*_t76*_t92));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t8, 0, _t88 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.5e1 / 0.8e1)*_hc1[17]*_t86*_t97*tau_s - _hc1[34]*_t163*_t33 + (0.1e1 / 0.2e1)*_hc1[9]*_t43*_t86 - 0.5e1 / 0.24e2*_t170*_t31*tau_s - 0.1e1 / 0.2e1*_t22*_t82 - 0.5e1 / 0.8e1*_t46*_t82*tau_s) - 0.1e1 / 0.48e2*_hc1[19]*_t15*_t31*_t97 - 0.1e1 / 0.16e2*_hc1[3]*_t42*_t82 + (0.1e1 / 0.16e2)*_t15*_t38*_t87));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t8, 0, 0.2e1*_t95 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.80e2 / 0.9e1)*_t115 - 0.10e2 / 0.3e1*_t118*_t17 - _t119*(-_hc1[10]*_t89 - _t164*_t90 - _t166*_t92) + _t160*_t173 + _t167*_t172 - _t67*(-_hc1[14]*_t89 - _hc1[25]*_t36*_t90 - _t174*_t92)) + _hc1[4]*_t112*_t92 + (0.1e1 / 0.36e2)*_hc1[4]*_t55*_t90 - _t114*_t94));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t8, 0, 0.2e1*_t102 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.20e2 / 0.9e1)*_hc1[14]*_t12*_t160*tau_s + (0.14e2 / 0.9e1)*_hc1[17]*_t161 + (0.34e2 / 0.9e1)*_hc1[7]*_t12*_t71 - _t119*(-_hc1[14]*_t38*_t99 - _hc1[29]*_t98 - _t162*_t176) - _t121*_t129 - _t131 - _t67*(-_hc1[29]*_t12*_t176 - _hc1[32]*_t98 - _t120*_t99)) - _t101*_t114 + _t124*_t28*_t97 + _t125*_t28*_t92));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t8, 0, 0.2e1*_t111 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.10e2 / 0.9e1)*_hc1[17]*_t161*_t33*tau_s + (0.7e1 / 0.9e1)*_hc1[19]*_t12*_t90 + (0.7e1 / 0.9e1)*_hc1[9]*_t33*_t73 - _t119*((0.5e1 / 0.12e2)*_hc1[14]*_t31*_t38*tau_s - _hc1[17]*_t181 - _hc1[29]*_t109*_t33*_t97 - _hc1[32]*_t106 + (0.1e1 / 0.3e1)*_hc1[7]*_t21*_t31) - _t12*_t132*_t180 - 0.10e2 / 0.9e1*_t179*_t31*_t71 + (0.1e1 / 0.3e1)*_t21*_t31*_t68 - 0.7e1 / 0.9e1*_t31*_t62 - _t67*((0.5e1 / 0.12e2)*_hc1[17]*_t31*_t38*tau_s - _hc1[19]*_t181 - _hc1[32]*_t171*_t97 - _hc1[34]*_t106 + (0.1e1 / 0.3e1)*_hc1[9]*_t21*_t31)) + _t103*_t177*_t71 + _t103*_t178*_t97 - _t110*_t114 - _t177*_t32*_t43 - _t178*_t32*_t38));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t8, 0, 0.3e1*_t123 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.80e2 / 0.9e1)*_t118*_t43*tau_s - _t119*(-_t119*(-_hc1[20]*_t37 - _t145 - _t166*_t38) + _t144 - _t147 + _t172*_t97 + _t173*_t71 - _t184*_t67) + (0.56e2 / 0.9e1)*_t121*_t25*_t6 - _t141 - _t151 - 0.440e3 / 0.27e2*_t161*_t182 - _t183*_t90 + (0.80e2 / 0.9e1)*_t43*_t64 - _t67*(_hc1[14]*_t116*_t97 - _t119*_t184 + _t152 - _t154 + _t185*_t71 - _t67*(-_hc1[29]*_t37 - _t155 - _t186*_t20))) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t21*_t40 + (0.1e1 / 0.12e2)*_hc0[5]*_t17*_t40*_t53*_t54 - _hc1[1]*_t137*_t71 - _hc1[1]*_t138*_t97 - _t113*_t135*_t92 - _t122*_t139));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t8, 0, 0.3e1*_t134 + n_s*my_piecewise3(_t8, 0, _hc0[0]*(-0.140e3 / 0.27e2*_hc1[9]*_t92 - _t119*(_hc1[17]*_t126 + _hc1[7]*_t127*_t25 - _t119*(-_hc1[14]*_t129 - _hc1[29]*_t44 - _t169*_t38) + _t128*_t71*_t74 - _t129*_t149 - _t188*_t67) - 0.140e3 / 0.27e2*_t12*_t143 + (0.28e2 / 0.9e1)*_t12*_t25*_t68 - _t129*_t157 + (0.80e2 / 0.9e1)*_t130*_t43*tau_s + (0.56e2 / 0.9e1)*_t132*_t25*_t6 - 0.220e3 / 0.27e2*_t28*_t90*tau_s - _t67*(_hc1[17]*_t12*_t128*_t71 + _hc1[19]*_t126 - _t119*_t188 + _t127*_t153 - _t129*_t156 - _t67*(-_hc1[19]*_t129 - _hc1[34]*_t44 - _t186*_t48))) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t21*_t49 + (0.1e1 / 0.12e2)*_hc0[5]*_t17*_t49*_t53*_t54 - 0.1e1 / 0.72e2*_t12*_t135*_t187 - 0.7e1 / 0.27e2*_t13*_t15*_t73 - 0.1e1 / 0.18e2*_t13*_t55*_t71 - _t133*_t139));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t8, 0, 0.4e1*_t159 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.6160e4 / 0.81e2)*_hc1[1]*_t175 - _t119*(-_t119*(_hc1[10]*_t189 - _t119*(-_hc1[20]*_t119 - _hc1[25]*_t67) + _t173*_t25 - _t190*_t67) - _t140*_t182 + (0.80e2 / 0.9e1)*_t146*_t43*tau_s + (0.56e2 / 0.9e1)*_t149*_t25*_t6 - _t183*_t35 - _t192*_t67) + (0.40e2 / 0.3e1)*_t150*_t43*tau_s + (0.28e2 / 0.3e1)*_t157*_t25*_t6 + (0.3640e4 / 0.81e2)*_t187*_t6 - 0.280e3 / 0.9e1*_t35*_t6*_t68 - 0.440e3 / 0.9e1*_t64*_t73*tau_s - _t67*(-_hc1[9]*_t142*_t35 - _t119*_t192 - _t140*_t179 + (0.80e2 / 0.9e1)*_t149*_t43*tau_s + (0.56e2 / 0.9e1)*_t156*_t25*_t6 - _t67*(_hc1[17]*_t189 + _hc1[19]*_t25*_t61 - _t119*_t191 - _t67*(-_hc1[32]*_t119 - _hc1[34]*_t67)))) + (0.1e1 / 0.216e3)*_hc0[14]*_hc1[0]*_t1*_t97/(M_PI * M_CBRTPI) + (0.40e2 / 0.81e2)*_hc1[0]*_t55*_t73 + (0.140e3 / 0.81e2)*_hc1[0]*_t96 + _t135*_t51*_t71 - 0.1e1 / 0.9e1*_t136*_t23 - 0.2e1 / 0.3e1*_t15*_t158*_t5 + _t15*_t180*_t69 - 0.4e1 / 0.9e1*_t23*_t43*_t55 - 0.56e2 / 0.27e2*_t25*_t57 + (0.1e1 / 0.6e1)*_t56*_t69));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_scan_params *params = (const mgga_x_scan_params *)(p->params);
  (void)params;
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