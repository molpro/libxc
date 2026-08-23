/*
  Generated from python/mgga_exc/mgga_x_scanl.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_scanl
*/

#ifndef _MGGA_X_SCANL_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_SCANL_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_SCANL_HELPER_BODIES
#include "mgga_x_scanl.c"
#undef _MGGA_X_SCANL_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_SCANL_HELPER_BODIES
#include "mgga_x_scanl.c"
#undef _MGGA_X_SCANL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_SCANL_HELPER_BODIES
#include "mgga_x_scanl.c"
#undef _MGGA_X_SCANL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_SCANL_HELPER_BODIES
#include "mgga_x_scanl.c"
#undef _MGGA_X_SCANL_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_SCANL_HELPER_BODIES
#include "mgga_x_scanl.c"
#undef _MGGA_X_SCANL_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_scanl.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_SCANL_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_f_alpha_left0_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

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
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

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
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

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
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

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
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

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
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_fab0_k, _KMAX)(const xc_func_type *p, double z, double *out) {
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

  const double _t1 = (0.1e1 / z);
  const double _t2 = _t1*params->pc07_a;
  const double _t3 = exp(-_t2);
  const double _t4 = params->pc07_a - z;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t5*params->pc07_a;
  const double _t7 = exp(-_t6);
  const double _t8 = _t3 + _t7;
  const double _t9 = pow(_t8, -params->pc07_b);
  const double _t10 = _t7 + 0.1e1;
  const double _t11 = pow(_t10, params->pc07_b);
  const double _t12 = exp(-_t2*params->pc07_b);
  const double _t13 = _t11*_t12;
  const double _t14 = _t13*_t9;
#if _KMAX >= 1
  const double _t15 = (0.1e1 / (z * z));
  const double _t16 = (0.1e1 / (_t4 * _t4));
  const double _t17 = _t7*params->pc07_a;
  const double _t18 = _t16*_t17;
  const double _t19 = (0.1e1 / _t10);
  const double _t20 = _t14*params->pc07_b;
  const double _t21 = _t19*_t20;
  const double _t22 = -_t15*_t3*params->pc07_a + _t18;
  const double _t23 = -_t22;
  const double _t24 = (0.1e1 / _t8);
  const double _t25 = _t20*_t24;
#endif
#if _KMAX >= 2
  const double _t26 = (0.1e1 / (z * z * z));
  const double _t27 = _t20*params->pc07_a;
  const double _t28 = ((params->pc07_a) * (params->pc07_a));
  const double _t29 = ((params->pc07_b) * (params->pc07_b));
  const double _t30 = (0.1e1 / (z * z * z * z));
  const double _t31 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t32 = _t17*_t31;
  const double _t33 = 0.2e1*_t32;
  const double _t34 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t35 = (0.1e1 / (_t10 * _t10));
  const double _t36 = exp(-0.2e1*_t6);
  const double _t37 = _t35*_t36;
  const double _t38 = _t34*_t37;
  const double _t39 = _t20*_t28;
  const double _t40 = pow(_t8, -params->pc07_b - 0.2e1);
  const double _t41 = (_t23 * _t23);
  const double _t42 = _t15*_t16;
  const double _t43 = _t28*_t7;
  const double _t44 = _t14*_t29;
  const double _t45 = _t19*_t44;
  const double _t46 = _t43*_t45;
  const double _t47 = _t23*_t44;
  const double _t48 = _t15*params->pc07_a;
  const double _t49 = _t24*_t48;
  const double _t50 = (0.1e1 / (_t8 * _t8));
  const double _t51 = _t20*_t50;
  const double _t52 = _t22*_t23;
  const double _t53 = _t3*params->pc07_a;
  const double _t54 = _t26*_t53;
  const double _t55 = _t28*_t3;
  const double _t56 = _t30*_t55;
  const double _t57 = _t34*_t43;
  const double _t58 = -_t33 - 0.2e1*_t54 + _t56 + _t57;
#endif
#if _KMAX >= 3
  const double _t59 = xc_powi(z, -5);
  const double _t60 = _t28*_t44;
  const double _t61 = 0.6e1*_t60;
  const double _t62 = ((params->pc07_a) * (params->pc07_a) * (params->pc07_a));
  const double _t63 = ((params->pc07_b) * (params->pc07_b) * (params->pc07_b));
  const double _t64 = xc_powi(z, -6);
  const double _t65 = _t17*_t34;
  const double _t66 = 0.6e1*_t65;
  const double _t67 = xc_powi(_t4, -6);
  const double _t68 = _t62*_t7;
  const double _t69 = _t67*_t68;
  const double _t70 = xc_powi(_t4, -5);
  const double _t71 = _t62*_t67;
  const double _t72 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t73 = exp(-0.3e1*_t6);
  const double _t74 = _t72*_t73;
  const double _t75 = _t20*_t74;
  const double _t76 = _t14*_t63;
  const double _t77 = _t62*_t76;
  const double _t78 = _t67*_t77;
  const double _t79 = _t74*_t78;
  const double _t80 = _t37*_t44;
  const double _t81 = _t13*_t63;
  const double _t82 = pow(_t8, -params->pc07_b - 0.3e1);
  const double _t83 = (_t23 * _t23 * _t23);
  const double _t84 = _t82*_t83;
  const double _t85 = (_t22 * _t22 * _t22);
  const double _t86 = _t15*_t31;
  const double _t87 = _t38*_t62;
  const double _t88 = 0.3e1*_t76;
  const double _t89 = _t19*_t68;
  const double _t90 = _t30*_t89;
  const double _t91 = _t16*_t90;
  const double _t92 = _t40*_t41;
  const double _t93 = pow(_t10, params->pc07_b - 0.1e1);
  const double _t94 = _t1*params->pc07_b;
  const double _t95 = exp(-params->pc07_a*(_t5 + _t94));
  const double _t96 = _t16*_t93*_t95*params->pc07_a;
  const double _t97 = _t63*_t96;
  const double _t98 = _t28*_t30;
  const double _t99 = _t23*_t24;
  const double _t100 = _t88*_t99;
  const double _t101 = -0.2e1*_t15*_t53 + 0.2e1*_t18;
  const double _t102 = 0.3e1*_t57;
  const double _t103 = _t24*_t47;
  const double _t104 = _t103*_t19;
  const double _t105 = _t28*_t38;
  const double _t106 = _t44*_t50;
  const double _t107 = _t106*_t52;
  const double _t108 = 0.3e1*_t58;
  const double _t109 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t110 = _t109*_t52;
  const double _t111 = _t110*_t20;
  const double _t112 = _t22*_t51;
  const double _t113 = 0.2e1*_t58;
  const double _t114 = -_t58;
  const double _t115 = _t23*_t51;
  const double _t116 = _t55*_t59;
  const double _t117 = 0.6e1*_t116 - 0.6e1*_t28*_t7*_t70 - 0.6e1*_t3*_t30*params->pc07_a - _t3*_t62*_t64 + _t66 + _t69;
  const double _t118 = -_t117;
  const double _t119 = -0.4e1*_t32 - 0.4e1*_t54 + 0.2e1*_t56 + 0.2e1*_t57;
#endif
#if _KMAX >= 4
  const double _t120 = 0.24e2*_t59;
  const double _t121 = ((params->pc07_a) * (params->pc07_a) * (params->pc07_a) * (params->pc07_a));
  const double _t122 = _t121/xc_powi(z, 8);
  const double _t123 = ((params->pc07_b) * (params->pc07_b) * (params->pc07_b) * (params->pc07_b));
  const double _t124 = _t123*_t14;
  const double _t125 = 0.36e2*_t64;
  const double _t126 = 0.12e2/xc_powi(z, 7);
  const double _t127 = 0.24e2*_t70;
  const double _t128 = _t127*_t17;
  const double _t129 = _t121/xc_powi(_t4, 8);
  const double _t130 = _t129*_t7;
  const double _t131 = 0.36e2*_t67;
  const double _t132 = _t131*_t37;
  const double _t133 = _t131*_t43;
  const double _t134 = xc_powi(_t4, -7);
  const double _t135 = _t134*_t62;
  const double _t136 = _t20*_t37;
  const double _t137 = 0.36e2*_t135;
  const double _t138 = 0.12e2*_t134;
  const double _t139 = _t138*_t68;
  const double _t140 = _t129*exp(-0.4e1*_t6)/(_t10 * _t10 * _t10 * _t10);
  const double _t141 = 0.7e1*_t129;
  const double _t142 = _t44*_t74;
  const double _t143 = 0.6e1*_t76;
  const double _t144 = pow(_t8, -params->pc07_b - 0.4e1);
  const double _t145 = _t144*_t81;
  const double _t146 = _t123*_t13;
  const double _t147 = 0.24e2*_t30;
  const double _t148 = _t15*_t45;
  const double _t149 = 0.12e2*_t44;
  const double _t150 = _t149*_t26;
  const double _t151 = _t34*_t89;
  const double _t152 = _t15*_t80;
  const double _t153 = _t120*_t76;
  const double _t154 = 0.12e2*_t76;
  const double _t155 = 0.12e2*_t38*_t77;
  const double _t156 = _t15*_t37;
  const double _t157 = _t121*_t67;
  const double _t158 = _t15*_t157;
  const double _t159 = 0.6e1*_t30;
  const double _t160 = _t121*_t159*_t76;
  const double _t161 = _t19*_t7;
  const double _t162 = _t154*_t157;
  const double _t163 = 0.4e1*_t124;
  const double _t164 = _t163*_t64;
  const double _t165 = _t124*_t38;
  const double _t166 = _t163*_t74;
  const double _t167 = _t26*params->pc07_a;
  const double _t168 = 0.12e2*_t92;
  const double _t169 = _t81*_t82;
  const double _t170 = 0.4e1*_t48;
  const double _t171 = 0.6e1*_t92;
  const double _t172 = _t63*_t93*_t95;
  const double _t173 = 0.4e1*_t82*_t97;
  const double _t174 = _t171*_t28*_t34;
  const double _t175 = pow(_t10, params->pc07_b - 0.2e1)*_t174*exp(-params->pc07_a*(0.2e1*_t5 + _t94));
  const double _t176 = _t28*_t99;
  const double _t177 = _t62*_t99;
  const double _t178 = _t13*_t29;
  const double _t179 = _t144*_t178*_t85;
  const double _t180 = -0.3e1*_t15*_t3*params->pc07_a + 0.3e1*_t18;
  const double _t181 = _t145*_t83;
  const double _t182 = _t169*_t41;
  const double _t183 = _t101*_t170;
  const double _t184 = 0.24e2*_t104;
  const double _t185 = _t127*_t37;
  const double _t186 = _t103*_t71;
  const double _t187 = 0.12e2*_t99;
  const double _t188 = _t101*_t41;
  const double _t189 = 0.12e2*_t107;
  const double _t190 = 0.24e2*_t19*_t43*_t76*_t99;
  const double _t191 = _t15*_t99;
  const double _t192 = _t143*_t98;
  const double _t193 = _t50*_t52;
  const double _t194 = _t24*_t58;
  const double _t195 = _t149*_t194;
  const double _t196 = -_t119;
  const double _t197 = _t19*_t32;
  const double _t198 = 0.6e1*_t57;
  const double _t199 = _t105*_t143;
  const double _t200 = _t110*_t44;
  const double _t201 = _t154*_t19*_t42*_t43;
  const double _t202 = _t106*_t58;
  const double _t203 = 0.8e1*_t202*_t22;
  const double _t204 = _t23*_t50*_t76;
  const double _t205 = _t170*_t204;
  const double _t206 = _t106*_t23;
  const double _t207 = _t114*_t206;
  const double _t208 = _t118*_t24*_t44;
  const double _t209 = _t18*_t19;
  const double _t210 = 0.4e1*_t209;
  const double _t211 = _t101*_t109;
  const double _t212 = _t20*_t211;
  const double _t213 = _t211*_t47;
  const double _t214 = _t204*_t210;
#endif

  const double f = _t14;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t11*_t12*_t15*_t9*params->pc07_a*params->pc07_b - _t18*_t21 - _t23*_t25;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0.2e1*_t11*_t12*_t16*_t19*_t23*_t24*_t29*_t7*_t9*params->pc07_a + _t11*_t12*_t19*_t28*_t34*_t7*_t9*params->pc07_b + _t11*_t12*_t28*_t29*_t30*_t9 + _t11*_t12*_t28*_t29*_t34*_t35*_t36*_t9 + _t11*_t12*_t29*_t40*_t41 - _t21*_t33 - _t25*_t58 - 0.2e1*_t26*_t27 - _t38*_t39 - 0.2e1*_t42*_t46 - 0.2e1*_t47*_t49 - _t51*_t52;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_t100*_t105 - _t100*_t98 + _t101*_t11*_t12*_t29*_t41*_t82 - _t101*_t111 - _t102*_t104 - 0.3e1*_t107*_t48 - _t108*_t44*_t49 + _t11*_t119*_t12*_t23*_t29*_t50*_t9 + 0.6e1*_t11*_t12*_t15*_t16*_t19*_t23*_t24*_t28*_t63*_t7*_t9 + 0.3e1*_t11*_t12*_t15*_t19*_t29*_t34*_t62*_t7*_t9 + 0.3e1*_t11*_t12*_t15*_t34*_t35*_t36*_t62*_t63*_t9 + 0.3e1*_t11*_t12*_t15*_t40*_t41*_t63*params->pc07_a + 0.3e1*_t11*_t12*_t16*_t19*_t22*_t23*_t29*_t50*_t7*_t9*params->pc07_a + 0.3e1*_t11*_t12*_t16*_t19*_t24*_t29*_t58*_t7*_t9*params->pc07_a + 0.6e1*_t11*_t12*_t16*_t19*_t26*_t28*_t29*_t7*_t9 + 0.6e1*_t11*_t12*_t19*_t23*_t24*_t29*_t31*_t7*_t9*params->pc07_a + 0.6e1*_t11*_t12*_t19*_t28*_t7*_t70*_t9*params->pc07_b + 0.6e1*_t11*_t12*_t23*_t24*_t26*_t29*_t9*params->pc07_a + 0.3e1*_t11*_t12*_t23*_t24*_t28*_t29*_t34*_t35*_t36*_t9 + _t11*_t12*_t23*_t29*_t50*_t58*_t9 + 0.6e1*_t11*_t12*_t28*_t29*_t35*_t36*_t70*_t9 + 0.3e1*_t11*_t12*_t29*_t62*_t67*_t72*_t73*_t9 + _t11*_t12*_t29*_t82*_t85 + 0.6e1*_t11*_t12*_t30*_t9*params->pc07_a*params->pc07_b + 0.3e1*_t11*_t12*_t35*_t36*_t62*_t67*_t9*params->pc07_b + _t11*_t12*_t62*_t63*_t64*_t9 - _t112*_t113 - _t114*_t115 - _t118*_t25 - 0.3e1*_t15*_t44*_t87 - _t21*_t66 - _t21*_t69 - 0.6e1*_t37*_t39*_t70 - 0.6e1*_t46*_t86 - _t59*_t61 - 0.2e1*_t71*_t75 - 0.3e1*_t71*_t80 - _t79 - _t81*_t84 - _t88*_t91 - 0.3e1*_t92*_t97;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t101*_t179 - _t101*_t180*_t20*_t52/(_t8 * _t8 * _t8 * _t8) - _t101*_t181 + _t101*_t200*_t210 - _t103*_t147*params->pc07_a + 0.4e1*_t104*_t69 + 0.6e1*_t105*_t107 + _t106*(_t58 * _t58) - _t107*_t19*_t198 - _t108*_t114*_t51 - _t108*_t212*_t22 - _t111*_t196 - 0.3e1*_t112*_t118 + _t113*_t200 + _t114*_t182 - 0.2e1*_t114*_t212*_t23 - _t115*_t117 + 0.2e1*_t118*_t206 + _t119*_t200 + _t119*_t202 + _t119*_t205 + 0.2e1*_t119*_t213 - _t119*_t214 - _t120*_t27 + _t121*_t159*_t165 - _t121*_t16*_t161*_t164 + _t122*_t124 - _t123*_t168*_t28*_t42*_t93*_t95 + _t123*_t175 + 0.4e1*_t123*_t84*_t96 + _t124*_t140 + _t124*_t187*_t91 + _t125*_t60 - _t126*_t77 + _t127*_t15*_t45*_t68 - _t127*_t152*_t62 + _t127*_t156*_t77 - _t128*_t21 - 0.18e2*_t129*_t142 + _t129*_t143*_t74 + 0.12e2*_t129*_t75 + _t130*_t21 - _t132*_t39 + _t132*_t60 + _t133*_t21 - 0.24e2*_t135*_t75 + _t136*_t137 - _t136*_t141 + _t137*_t142 - _t137*_t80 - _t138*_t74*_t77 - _t139*_t21 - _t140*_t143 - 0.6e1*_t140*_t20 + 0.11e2*_t140*_t44 + _t141*_t80 - 0.8e1*_t142*_t158 + _t144*_t146*(_t23 * _t23 * _t23 * _t23) + _t144*_t178*_t180*_t188 + _t145*(_t22 * _t22 * _t22 * _t22) - _t146*_t170*_t84 + _t146*_t171*_t98 - _t147*_t16*_t46 - 0.4e1*_t148*_t157*_t7 - 0.24e2*_t148*_t57 + _t15*_t162*_t74 - 0.12e2*_t15*_t165*_t177 - _t150*_t151 + _t150*_t87 - _t151*_t154*_t191 + 0.12e2*_t152*_t157 + _t153*_t16*_t89 + _t153*_t176 - _t154*_t31*_t90 + _t155*_t191 - _t155*_t26 - _t156*_t162 - _t158*_t166 - _t16*_t190*_t26 + _t160*_t161*_t34 - _t160*_t38 - _t164*_t177 + _t166*_t71*_t99 - _t167*_t168*_t81 + _t167*_t189 + _t167*_t195 - _t168*_t172*_t31*params->pc07_a + _t169*_t170*_t85 - _t170*_t207 - _t170*_t208 + _t172*_t174 - _t173*_t188 - _t173*_t85 - _t175*_t63 - _t176*_t185*_t76 + 0.2e1*_t178*_t196*_t41*_t82 + _t179*_t180 - _t180*_t181 + _t182*_t183 + _t182*_t196 + _t182*(-_t102 + 0.6e1*_t26*_t3*params->pc07_a + 0.6e1*_t31*_t7*params->pc07_a - 0.3e1*_t56) - _t183*_t200 - _t184*_t43*_t70 + _t184*_t65 + _t185*_t60*_t99 - 0.12e2*_t186*_t37 + 0.8e1*_t186*_t74 + _t187*_t37*_t78 - _t187*_t79 + _t189*_t197 + _t190*_t86 - _t192*_t193 - _t192*_t194 - _t193*_t199 + _t193*_t201 - _t194*_t198*_t45 - _t194*_t199 + _t194*_t201 + _t194*_t38*_t61 + _t195*_t197 + _t203*_t209 - _t203*_t48 + _t205*_t58 + _t206*(-0.12e2*_t116 + 0.12e2*_t28*_t7*_t70 + 0.12e2*_t3*_t30*params->pc07_a + 0.2e1*_t3*_t62*_t64 - 0.12e2*_t65 - 0.2e1*_t69) + _t207*_t210 + _t208*_t210 + _t213*_t58 - _t214*_t58 - _t25*(-_t120*_t53 + _t122*_t3 + _t125*_t55 - _t126*_t3*_t62 - _t128 + _t130 + _t133 - _t139) + 0.24e2*_t26*_t31*_t46;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_fab_k, _KMAX)(const xc_func_type *p, double z, double *out) {
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

  const double _t1 = (0.39e2 / 0.40e2)*params->pc07_a;
  const double _t2 = (0.1e1 / 0.40e2)*params->pc07_a;
  const double _t3 = _t2 > z;
  const double _t4 = my_piecewise3(_t3, _t2, z);
  const double _t5 = _t1 > _t4;
  const double _t6 = z <= _t2;
  const double _t7 = z >= _t1;
#if _KMAX >= 1
  const double _t8 = my_piecewise3(_t5, my_piecewise3(_t3, 0, 0.1e1), 0);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t6) && !(_t7)) XC_CAT(pc07_fab0_k, _KMAX)(p, my_piecewise3(_t5, _t4, _t1), _hc0);

  const double f = my_piecewise5(_t6, 0, _t7, 0.1e1, _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise5(_t6, 0, _t7, 0, _hc0[1]*_t8);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise5(_t6, 0, _t7, 0, _hc0[2]*(_t8 * _t8));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise5(_t6, 0, _t7, 0, _hc0[3]*(_t8 * _t8 * _t8));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise5(_t6, 0, _t7, 0, _hc0[4]*(_t8 * _t8 * _t8 * _t8));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_Delta_k, _KMAX)(const xc_func_type *p, double x, double u, double *out) {

  const double _t1 = xc_powr(0.6e1, 2, 3);
  const double _t2 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (x * x);
  const double _t5 = (0.1e1 / 0.5184e4)*_t3*_t4;
#if _KMAX >= 1
  const double _t6 = (0.1e1 / 0.2916e4)*_t3;
  const double _t7 = (0.1e1 / 0.2592e4)*_t3;
  const double _t8 = _t7*x;
#endif
#if _KMAX >= 3
  const double _t9 = (0.1e1 / 0.729e3)*_t3;
#endif

  const double f = (0.1e1 / 0.5832e4)*_t3*(u * u) + (0.1e1 / 0.17496e5)*_t3*(x * x * x * x) - _t5*u;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = -_t5 + _t6*u;
  out[1] = df_du;
  const double df_dx = (0.1e1 / 0.4374e4)*_t1*_t2*(x * x * x) - _t8*u;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _t6;
  out[3] = d2f_du2;
  const double d2f_dx_du = -_t8;
  out[4] = d2f_dx_du;
  const double d2f_dx2 = (0.1e1 / 0.1458e4)*_t1*_t2*_t4 - _t7*u;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_du3 = 0;
  out[6] = d3f_du3;
  const double d3f_dx_du2 = 0;
  out[7] = d3f_dx_du2;
  const double d3f_dx2_du = -_t7;
  out[8] = d3f_dx2_du;
  const double d3f_dx3 = _t9*x;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_du4 = 0;
  out[10] = d4f_du4;
  const double d4f_dx_du3 = 0;
  out[11] = d4f_dx_du3;
  const double d4f_dx2_du2 = 0;
  out[12] = d4f_dx2_du2;
  const double d4f_dx3_du = 0;
  out[13] = d4f_dx3_du;
  const double d4f_dx4 = _t9;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_f_W_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
#if _KMAX >= 1
  const double _t2 = (0.5e1 / 0.36e2)*_t1;
#endif

  const double f = (0.5e1 / 0.72e2)*_t1*(x * x);
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_GE4_k, _KMAX)(const xc_func_type *p, double x, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_Delta_k, _KMAX)(p, x, u, _hc0);
  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = (0.5e1 / 0.54e2)*_t1;
#if _KMAX >= 1
  const double _t3 = (0.5e1 / 0.324e3)*_t1;
#endif

  const double f = _hc0[0] + (0.5e1 / 0.648e3)*_t1*(x * x) + _t2*u + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _hc0[1] + _t2;
  out[1] = df_du;
  const double df_dx = _hc0[2] + _t3*x;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _hc0[3];
  out[3] = d2f_du2;
  const double d2f_dx_du = _hc0[4];
  out[4] = d2f_dx_du;
  const double d2f_dx2 = _hc0[5] + _t3;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_du3 = 0;
  out[6] = d3f_du3;
  const double d3f_dx_du2 = 0;
  out[7] = d3f_dx_du2;
  const double d3f_dx2_du = _hc0[8];
  out[8] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[9];
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_du4 = 0;
  out[10] = d4f_du4;
  const double d4f_dx_du3 = 0;
  out[11] = d4f_dx_du3;
  const double d4f_dx2_du2 = 0;
  out[12] = d4f_dx2_du2;
  const double d4f_dx3_du = 0;
  out[13] = d4f_dx3_du;
  const double d4f_dx4 = _hc0[14];
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_S_k, _KMAX)(const xc_func_type *p, double x, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pc07_f_W_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_Delta_k, _KMAX)(p, x, u, _hc1);
  const double _t1 = ((_hc1[0]) * (_hc1[0]));
  const double _t2 = _hc0[0] + 0.1e1;
  const double _t3 = (0.1e1 / (_t2 * _t2));
  const double _t4 = _t1*_t3 + 0.1e1;
  const double _t5 = xc_powr(_t4, 1, 2);
#if _KMAX >= 1
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = _hc1[0]*_t3;
  const double _t8 = _t6*_t7;
  const double _t9 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t10 = _t1*_t9;
  const double _t11 = _hc0[1]*_t10;
  const double _t12 = -_hc1[0]*_hc1[2]*_t3 + _t11;
  const double _t13 = -_t12;
#endif
#if _KMAX >= 2
  const double _t14 = ((_hc1[1]) * (_hc1[1]));
  const double _t15 = _t14*_t3;
  const double _t16 = xc_powr(_t4, -3, 2);
  const double _t17 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t18 = _t1*_t17;
  const double _t19 = _t16*_t18;
  const double _t20 = _t13*_t16;
  const double _t21 = _t20*_t7;
  const double _t22 = _hc1[4]*_t7;
  const double _t23 = _hc1[2]*_t3;
  const double _t24 = _hc1[1]*_t23;
  const double _t25 = _hc0[1]*_t9;
  const double _t26 = _hc1[0]*_t25;
  const double _t27 = 0.2e1*_hc1[1];
  const double _t28 = _t22 + _t24 - _t26*_t27;
  const double _t29 = _t12*_t16;
  const double _t30 = _hc1[5]*_t7;
  const double _t31 = ((_hc1[2]) * (_hc1[2]));
  const double _t32 = _t3*_t31;
  const double _t33 = 0.4e1*_t26;
  const double _t34 = ((_hc0[1]) * (_hc0[1]));
  const double _t35 = _t18*_t34;
  const double _t36 = -_hc0[2]*_t10 - _hc1[2]*_t33 + _t30 + _t32 + 0.3e1*_t35;
#endif
#if _KMAX >= 3
  const double _t37 = 0.3e1*_hc1[3];
  const double _t38 = _hc1[1]*_t3*_t37;
  const double _t39 = 0.3e1*_t16;
  const double _t40 = _t17*_t39;
  const double _t41 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t42 = xc_powr(_t4, -5, 2);
  const double _t43 = 0.3e1*_t42;
  const double _t44 = xc_powi(_t2, -6);
  const double _t45 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t46 = _t41*_t44*_t45;
  const double _t47 = _t16*_t28;
  const double _t48 = _t47*_t7;
  const double _t49 = 0.2e1*_hc1[3];
  const double _t50 = 0.2e1*_t14;
  const double _t51 = -0.2e1*_hc1[1]*_hc1[4]*_t3 - _hc1[2]*_hc1[3]*_t3 + _t25*_t50 + _t26*_t49;
  const double _t52 = -_t51;
  const double _t53 = _t13*_t42;
  const double _t54 = _t12*_t53;
  const double _t55 = _hc1[1]*_t7;
  const double _t56 = -_t28;
  const double _t57 = _t16*_t36;
  const double _t58 = _t57*_t7;
  const double _t59 = _hc1[5]*_t3;
  const double _t60 = _hc1[1]*_t25;
  const double _t61 = 0.4e1*_hc1[2];
  const double _t62 = _hc0[2]*_t9;
  const double _t63 = _hc1[0]*_t62;
  const double _t64 = _t17*_t34;
  const double _t65 = 0.6e1*_t64;
  const double _t66 = _hc1[0]*_t65;
  const double _t67 = _hc1[1]*_t59 + _hc1[1]*_t66 + 0.2e1*_hc1[4]*_t23 - _hc1[4]*_t33 + _hc1[8]*_t7 - _t27*_t63 - _t60*_t61;
  const double _t68 = _hc1[2]*_t7;
  const double _t69 = 0.3e1*_t11 - 0.3e1*_t68;
  const double _t70 = -_t36;
  const double _t71 = 0.2e1*_t29;
  const double _t72 = 0.6e1*_t25;
  const double _t73 = _hc1[0]*_t72;
  const double _t74 = 0.6e1*_t63;
  const double _t75 = xc_powi(_t2, -5);
  const double _t76 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t75;
  const double _t77 = -0.9e1*_hc0[1]*_hc0[2]*_t1*_t17 - 0.18e2*_hc1[0]*_hc1[2]*_t17*_t34 - _hc1[0]*_hc1[9]*_t3 - 0.3e1*_hc1[2]*_hc1[5]*_t3 + _hc1[2]*_t74 + _hc1[5]*_t73 + 0.12e2*_t1*_t76 + _t31*_t72;
  const double _t78 = -_t77;
#endif
#if _KMAX >= 4
  const double _t79 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t80 = ((_hc1[3]) * (_hc1[3]));
  const double _t81 = xc_powr(_t4, -7, 2);
  const double _t82 = 0.15e2*_t81;
  const double _t83 = _hc1[1]*_t72;
  const double _t84 = 0.3e1*_t15;
  const double _t85 = _t28*_t42;
  const double _t86 = 0.6e1*_t55;
  const double _t87 = _t12*_t86;
  const double _t88 = 0.2e1*_t3;
  const double _t89 = _t12*_t69;
  const double _t90 = _t13*_t81*_t89;
  const double _t91 = _t53*_t69;
  const double _t92 = _hc1[2]*_t25;
  const double _t93 = 0.12e2*_t62;
  const double _t94 = _hc1[0]*_hc1[5];
  const double _t95 = _hc1[0]*_hc1[2];
  const double _t96 = 0.36e2*_t64;
#endif

  const double f = _t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _hc1[1]*_t8;
  out[1] = df_du;
  const double df_dx = _t13*_t6;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _hc1[3]*_t8 - _t14*_t19 + _t15*_t6;
  out[3] = d2f_du2;
  const double d2f_dx_du = -_hc1[1]*_t21 + _t28*_t6;
  out[4] = d2f_dx_du;
  const double d2f_dx2 = _t13*_t29 + _t36*_t6;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_du3 = -_hc1[0]*_t40*_t41 - _hc1[1]*_t19*_t37 + _t38*_t6 + _t43*_t46;
  out[6] = d3f_du3;
  const double d3f_dx_du2 = -_hc1[3]*_t21 + 0.3e1*_t1*_t13*_t14*_t17*_t42 - _t15*_t20 - _t27*_t48 + _t52*_t6;
  out[7] = d3f_dx_du2;
  const double d3f_dx2_du = -_hc1[1]*_t58 + _t20*_t56 + _t28*_t29 - 0.3e1*_t54*_t55 + _t6*_t67;
  out[8] = d3f_dx2_du;
  const double d3f_dx3 = _t20*_t70 + _t36*_t71 + _t54*_t69 + _t6*_t78;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_du4 = -((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]))*_t79*_t82/xc_powi(_t2, 8) - 0.18e2*_hc1[0]*_hc1[3]*_t14*_t16*_t17 + 0.18e2*_hc1[3]*_t14*_t42*_t44*_t45 + 0.18e2*_t1*_t42*_t44*_t79 - 0.3e1*_t19*_t80 + 0.3e1*_t3*_t6*_t80 - _t40*_t79;
  out[10] = d4f_du4;
  const double d4f_dx_du3 = 0.9e1*_hc1[0]*_t13*_t17*_t41*_t42 + 0.9e1*_hc1[1]*_hc1[3]*_t1*_t13*_t17*_t42 + 0.9e1*_t1*_t14*_t17*_t28*_t42 - _t13*_t46*_t82 - _t20*_t38 - _t37*_t48 - _t39*_t52*_t55 - _t47*_t84 + _t6*(0.3e1*_hc1[3]*_hc1[4]*_t3 - _hc1[3]*_t83);
  out[11] = d4f_dx_du3;
  const double d4f_dx2_du2 = -_hc1[3]*_t58 + 0.15e2*_t1*_t12*_t13*_t14*_t17*_t81 + 0.3e1*_t1*_t14*_t17*_t36*_t42 + _t12*_t16*_t52 + _t13*_t16*_t51 - _t15*_t57 - _t16*_t27*_t67*_t7 + 0.2e1*_t16*_t28*_t56 - _t37*_t54*_t7 - _t53*_t56*_t86 - _t54*_t84 + _t6*(_hc1[1]*_hc1[8]*_t88 - _hc1[3]*_t25*_t61 + _hc1[3]*_t59 + _hc1[3]*_t66 + ((_hc1[4]) * (_hc1[4]))*_t88 - 0.8e1*_hc1[4]*_t60 + _t14*_t65 - _t49*_t63 - _t50*_t62) - _t85*_t87;
  out[12] = d4f_dx2_du2;
  const double d4f_dx3_du = -_t16*_t55*_t78 - _t20*_t67 - _t36*_t42*_t87 + _t47*_t70 - 0.3e1*_t53*_t55*_t70 + _t54*(0.6e1*_hc0[1]*_hc1[0]*_hc1[1]*_t9 - 0.3e1*_t22 - 0.3e1*_t24) - 0.5e1*_t55*_t90 + 0.2e1*_t56*_t57 + _t56*_t91 + _t6*(0.18e2*_hc0[1]*_hc0[2]*_hc1[0]*_hc1[1]*_t17 - 0.24e2*_hc1[0]*_hc1[1]*_t76 + 0.18e2*_hc1[0]*_hc1[4]*_t17*_t34 + 0.18e2*_hc1[1]*_hc1[2]*_t17*_t34 - 0.6e1*_hc1[1]*_hc1[2]*_t62 + _hc1[1]*_hc1[9]*_t3 + 0.3e1*_hc1[2]*_hc1[8]*_t3 + 0.3e1*_hc1[4]*_hc1[5]*_t3 - _hc1[4]*_t74 - 0.12e2*_hc1[4]*_t92 - _hc1[5]*_t83 - _hc1[8]*_t73) + _t67*_t71 + _t85*_t89;
  out[13] = d4f_dx3_du;
  const double d4f_dx4 = _t20*_t77 + 0.3e1*_t29*_t78 + _t36*_t39*_t70 + _t36*_t43*_t89 + _t54*(0.12e2*_hc0[1]*_hc1[0]*_hc1[2]*_t9 + 0.3e1*_hc0[2]*_t1*_t9 - 0.3e1*_t30 - 0.3e1*_t32 - 0.9e1*_t35) + _t6*(0.60e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t1*_t44 + 0.72e2*_hc0[1]*_hc0[2]*_t17*_t95 + 0.9e1*((_hc0[2]) * (_hc0[2]))*_t18 - 0.72e2*_hc0[2]*_t1*_t34*_t75 + _hc1[14]*_t7 + 0.3e1*((_hc1[5]) * (_hc1[5]))*_t3 - 0.24e2*_hc1[5]*_t92 + 0.4e1*_hc1[9]*_t23 - 0.8e1*_hc1[9]*_t26 - _t31*_t93 + _t31*_t96 - 0.96e2*_t76*_t95 - _t93*_t94 + _t94*_t96) + 0.2e1*_t70*_t91 + _t90*(0.5e1*_t11 - 0.5e1*_t68);
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_B_k, _KMAX)(const xc_func_type *p, double x, double u, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = (0.5e1 / 0.54e2)*_t1;
#if _KMAX >= 1
  const double _t3 = (0.10e2 / 0.81e2)*_t1;
#endif

  const double f = -0.5e1 / 0.81e2*_t1*(x * x) + _t2*u + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _t2;
  out[1] = df_du;
  const double df_dx = -_t3*x;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_du2 = 0;
  out[3] = d2f_du2;
  const double d2f_dx_du = 0;
  out[4] = d2f_dx_du;
  const double d2f_dx2 = -_t3;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_du3 = 0;
  out[6] = d3f_du3;
  const double d3f_dx_du2 = 0;
  out[7] = d3f_dx_du2;
  const double d3f_dx2_du = 0;
  out[8] = d3f_dx2_du;
  const double d3f_dx3 = 0;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_du4 = 0;
  out[10] = d4f_du4;
  const double d4f_dx_du3 = 0;
  out[11] = d4f_dx_du3;
  const double d4f_dx2_du2 = 0;
  out[12] = d4f_dx2_du2;
  const double d4f_dx3_du = 0;
  out[13] = d4f_dx3_du;
  const double d4f_dx4 = 0;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_z_k, _KMAX)(const xc_func_type *p, double x, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_S_k, _KMAX)(p, x, u, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pc07_f_W_k, _KMAX)(p, x, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_GE4_k, _KMAX)(p, x, u, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_B_k, _KMAX)(p, x, u, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_Delta_k, _KMAX)(p, x, u, _hc4);
  const double _t1 = 0.2e1*_hc3[0];
  const double _t2 = _hc3[0] + _hc4[0];
  const double _t3 = 0.2e1*_hc1[0];
  const double _t4 = _t3 + 0.1e1;
  const double _t5 = ((_hc4[0]) * (_hc4[0]));
  const double _t6 = _hc1[0] + 0.1e1;
  const double _t7 = (0.1e1 / (_t6 * _t6));
  const double _t8 = _t5*_t7;
  const double _t9 = ((_hc3[0]) * (_hc3[0])) + _hc4[0]*_t1 + _t2*_t3 + _t4*_t8;
  const double _t10 = (0.1e1 / (_hc0[0]));
  const double _t11 = _hc0[0]*_hc1[0] + _hc2[0];
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = _t10*_t12;
#if _KMAX >= 1
  const double _t14 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t15 = _t12*_t14;
  const double _t16 = _hc0[1]*_t9;
  const double _t17 = 0.2e1*_hc4[0];
  const double _t18 = _hc3[1] + _hc4[1];
  const double _t19 = _t4*_t7;
  const double _t20 = _t17*_t19;
  const double _t21 = _hc3[1]*_t1 + _hc3[1]*_t17 + _hc4[1]*_t1 + _hc4[1]*_t20 + _t18*_t3;
  const double _t22 = (0.1e1 / (_t11 * _t11));
  const double _t23 = _t10*_t22;
  const double _t24 = _hc0[1]*_hc1[0];
  const double _t25 = -_hc2[1] - _t24;
  const double _t26 = _t25*_t9;
  const double _t27 = _t15*_t9;
  const double _t28 = _hc0[0]*_hc1[1];
  const double _t29 = _hc0[2]*_hc1[0];
  const double _t30 = -_hc2[2] - _t28 - _t29;
  const double _t31 = _t23*_t9;
  const double _t32 = _hc3[2] + _hc4[2];
  const double _t33 = 0.2e1*_hc1[1];
  const double _t34 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t35 = _t34*_t5;
  const double _t36 = _t35*_t4;
  const double _t37 = _hc3[2]*_t1 + _hc3[2]*_t17 + _hc4[2]*_t1 + _hc4[2]*_t20 + _t2*_t33 + _t3*_t32 - _t33*_t36 + _t33*_t8;
#endif
#if _KMAX >= 2
  const double _t38 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t39 = ((_hc0[1]) * (_hc0[1]));
  const double _t40 = _t38*_t39;
  const double _t41 = _t12*_t9;
  const double _t42 = 0.2e1*_t41;
  const double _t43 = _hc0[1]*_t15;
  const double _t44 = 0.2e1*_t21;
  const double _t45 = _hc0[3]*_hc1[0];
  const double _t46 = -_hc2[3] - _t45;
  const double _t47 = _t14*_t22;
  const double _t48 = _t26*_t47;
  const double _t49 = 0.2e1*_hc0[1];
  const double _t50 = _t23*_t25;
  const double _t51 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t52 = _t10*_t51;
  const double _t53 = -_hc0[1]*_t3 - 0.2e1*_hc2[1];
  const double _t54 = _t26*_t53;
  const double _t55 = 0.4e1*_hc3[1];
  const double _t56 = ((_hc4[1]) * (_hc4[1]));
  const double _t57 = _t56*_t7;
  const double _t58 = 0.2e1*_t4;
  const double _t59 = 0.2e1*((_hc3[1]) * (_hc3[1])) + _hc4[1]*_t55 + _hc4[3]*_t1 + _hc4[3]*_t20 + _hc4[3]*_t3 + _t57*_t58;
  const double _t60 = _hc0[2]*_t38;
  const double _t61 = _t12*_t16;
  const double _t62 = 0.2e1*_t61;
  const double _t63 = _hc0[2]*_t15;
  const double _t64 = _hc0[2]*_t47;
  const double _t65 = _hc0[1]*_hc1[1];
  const double _t66 = _hc0[4]*_hc1[0];
  const double _t67 = -_hc2[4] - _t65 - _t66;
  const double _t68 = _t16*_t30;
  const double _t69 = _t23*_t30;
  const double _t70 = _t52*_t53;
  const double _t71 = _t30*_t9;
  const double _t72 = _t15*_t37;
  const double _t73 = _t23*_t37;
  const double _t74 = 0.2e1*_hc3[1];
  const double _t75 = 0.2e1*_hc3[2];
  const double _t76 = _hc4[1]*_t7;
  const double _t77 = 0.4e1*_hc1[1];
  const double _t78 = _hc4[0]*_t77;
  const double _t79 = _hc4[2]*_t58;
  const double _t80 = _t34*_t4;
  const double _t81 = _t78*_t80;
  const double _t82 = _hc3[2]*_t74 + _hc4[1]*_t75 - _hc4[1]*_t81 + _hc4[2]*_t74 + _hc4[4]*_t1 + _hc4[4]*_t20 + _hc4[4]*_t3 + _t18*_t33 + _t76*_t78 + _t76*_t79;
  const double _t83 = ((_hc0[2]) * (_hc0[2]));
  const double _t84 = _t38*_t83;
  const double _t85 = 0.2e1*_t71;
  const double _t86 = _hc0[0]*_hc1[2];
  const double _t87 = _hc0[5]*_hc1[0];
  const double _t88 = -_hc0[2]*_t33 - _hc2[5] - _t86 - _t87;
  const double _t89 = -_hc0[2]*_t3 - 0.2e1*_hc2[2] - 0.2e1*_t28;
  const double _t90 = _t52*_t71;
  const double _t91 = 0.2e1*_t72;
  const double _t92 = 0.2e1*_t73;
  const double _t93 = 0.4e1*_hc3[2];
  const double _t94 = _hc3[5] + _hc4[5];
  const double _t95 = 0.2e1*_hc1[2];
  const double _t96 = 0.8e1*_hc1[1];
  const double _t97 = _hc4[0]*_hc4[2];
  const double _t98 = _t7*_t97;
  const double _t99 = ((_hc1[1]) * (_hc1[1]));
  const double _t100 = _t34*_t99;
  const double _t101 = ((_hc4[2]) * (_hc4[2]));
  const double _t102 = _t101*_t7;
  const double _t103 = _t80*_t96;
  const double _t104 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t105 = _t104*_t5;
  const double _t106 = _t4*_t99;
  const double _t107 = 0.2e1*((_hc3[2]) * (_hc3[2])) + _hc3[5]*_t1 + _hc3[5]*_t17 + _hc4[2]*_t93 + _hc4[5]*_t1 + _hc4[5]*_t20 - 0.8e1*_t100*_t5 + _t102*_t58 - _t103*_t97 + 0.6e1*_t105*_t106 + _t2*_t95 + _t3*_t94 + _t32*_t77 - _t36*_t95 + _t8*_t95 + _t96*_t98;
#endif
#if _KMAX >= 3
  const double _t108 = 0.6e1*_hc4[3];
  const double _t109 = _t108*_t19;
  const double _t110 = _hc3[1]*_t108 + _hc4[1]*_t109;
  const double _t111 = _t38*_t61;
  const double _t112 = 0.6e1*_hc0[3];
  const double _t113 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t114 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t115 = _t113*_t114;
  const double _t116 = 0.6e1*_t41;
  const double _t117 = _t15*_t21;
  const double _t118 = 0.3e1*_hc0[3];
  const double _t119 = -_hc0[6]*_hc1[0] - _hc2[6];
  const double _t120 = _t12*_t40;
  const double _t121 = 0.6e1*_t21;
  const double _t122 = 0.3e1*_t46;
  const double _t123 = _t16*_t47;
  const double _t124 = _t22*_t40;
  const double _t125 = 0.6e1*_t124;
  const double _t126 = _t21*_t23;
  const double _t127 = _hc0[1]*_t47;
  const double _t128 = _t127*_t25;
  const double _t129 = -_hc0[3]*_t3 - 0.2e1*_hc2[3];
  const double _t130 = _t26*_t52;
  const double _t131 = _t46*_t9;
  const double _t132 = 0.2e1*_t70;
  const double _t133 = _t14*_t51;
  const double _t134 = _t133*_t54;
  const double _t135 = 0.3e1*_t59;
  const double _t136 = _t25*_t70;
  const double _t137 = 0.3e1*_t21;
  const double _t138 = -0.3e1*_hc2[1] - 0.3e1*_t24;
  const double _t139 = (0.1e1 / (_t11 * _t11 * _t11 * _t11));
  const double _t140 = _t10*_t139;
  const double _t141 = _t138*_t140;
  const double _t142 = 0.4e1*_hc0[4];
  const double _t143 = _t42*_t60;
  const double _t144 = _t113*_t39;
  const double _t145 = _hc0[2]*_t144;
  const double _t146 = 0.2e1*_t117;
  const double _t147 = 0.4e1*_t38;
  const double _t148 = _hc0[2]*_t147;
  const double _t149 = _hc0[1]*_t12;
  const double _t150 = _t149*_t21;
  const double _t151 = _t64*_t9;
  const double _t152 = 0.2e1*_hc0[4];
  const double _t153 = _t148*_t22;
  const double _t154 = _hc0[1]*_t26;
  const double _t155 = _hc0[3]*_hc1[1];
  const double _t156 = -_hc0[7]*_hc1[0] - _hc2[7] - _t155;
  const double _t157 = 0.2e1*_t67;
  const double _t158 = _t47*_t71;
  const double _t159 = _t25*_t64;
  const double _t160 = 0.2e1*_t126;
  const double _t161 = _hc0[2]*_t133;
  const double _t162 = _t30*_t44;
  const double _t163 = _t70*_t9;
  const double _t164 = _t133*_t68;
  const double _t165 = 0.2e1*_t53;
  const double _t166 = _t141*_t71;
  const double _t167 = 0.2e1*_t120;
  const double _t168 = _t25*_t37;
  const double _t169 = _t47*_t49;
  const double _t170 = 0.2e1*_t82;
  const double _t171 = _hc4[3]*_t7;
  const double _t172 = 0.4e1*_t19;
  const double _t173 = _hc4[4]*_t172;
  const double _t174 = _t56*_t80;
  const double _t175 = _hc4[1]*_t173 + _hc4[3]*_t33 + _hc4[3]*_t75 - _hc4[3]*_t81 + _hc4[4]*_t55 + _t171*_t78 + _t171*_t79 - _t174*_t77 + _t57*_t77;
  const double _t176 = _hc0[5]*_t38;
  const double _t177 = _t41*_t60;
  const double _t178 = _t113*_t83;
  const double _t179 = _hc0[5]*_t15;
  const double _t180 = _t12*_t84;
  const double _t181 = _hc0[5]*_t47;
  const double _t182 = _t22*_t84;
  const double _t183 = 0.2e1*_t26;
  const double _t184 = _hc0[1]*_hc1[2];
  const double _t185 = -_hc0[4]*_t33 - _hc0[8]*_hc1[0] - _hc2[8] - _t184;
  const double _t186 = _t23*_t88;
  const double _t187 = _t161*_t53;
  const double _t188 = _t88*_t9;
  const double _t189 = _t52*_t89;
  const double _t190 = _t189*_t9;
  const double _t191 = -_hc0[4]*_t3 - 0.2e1*_hc2[4] - 0.2e1*_t65;
  const double _t192 = _t133*_t89;
  const double _t193 = _t21*_t30;
  const double _t194 = _t148*_t37;
  const double _t195 = 0.2e1*_t64;
  const double _t196 = _t30*_t37;
  const double _t197 = _t107*_t15;
  const double _t198 = _t107*_t23;
  const double _t199 = 0.2e1*_hc3[5];
  const double _t200 = _hc4[0]*_t7;
  const double _t201 = _hc4[4]*_t200;
  const double _t202 = _hc4[2]*_t96;
  const double _t203 = 0.4e1*_hc1[2];
  const double _t204 = _hc4[0]*_t203;
  const double _t205 = 0.16e2*_t100;
  const double _t206 = _hc4[0]*_t205;
  const double _t207 = _hc4[5]*_t58;
  const double _t208 = _hc4[0]*_hc4[4];
  const double _t209 = _hc4[1]*_t80;
  const double _t210 = _t104*_t106;
  const double _t211 = 0.12e2*_t210;
  const double _t212 = _hc4[0]*_hc4[1];
  const double _t213 = _hc3[5]*_t74 + _hc4[1]*_t199 - _hc4[1]*_t206 + _hc4[2]*_t173 + _hc4[4]*_t77 + _hc4[4]*_t93 + _hc4[5]*_t74 + _hc4[8]*_t1 + _hc4[8]*_t20 + _hc4[8]*_t3 - _t103*_t208 + _t18*_t95 + _t201*_t96 - _t202*_t209 + _t202*_t76 - _t204*_t209 + _t204*_t76 + _t207*_t76 + _t211*_t212;
  const double _t214 = _t116*_t38;
  const double _t215 = _hc0[2]*_t214;
  const double _t216 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t217 = _t113*_t216;
  const double _t218 = 0.3e1*_t158;
  const double _t219 = 0.3e1*_hc1[2];
  const double _t220 = 0.3e1*_hc1[1];
  const double _t221 = -_hc0[2]*_t219 - _hc0[5]*_t220 - _hc0[9]*_hc1[0] - _hc2[9];
  const double _t222 = 0.6e1*_t71;
  const double _t223 = 0.3e1*_t88;
  const double _t224 = _t71*_t89;
  const double _t225 = 0.3e1*_t161;
  const double _t226 = -_hc0[2]*_t77 - _hc0[5]*_t3 - 0.2e1*_hc2[5] - 0.2e1*_t86;
  const double _t227 = 0.2e1*_t188;
  const double _t228 = _t140*_t71;
  const double _t229 = -0.3e1*_hc2[2] - 0.3e1*_t28 - 0.3e1*_t29;
  const double _t230 = _t229*_t89;
  const double _t231 = 0.3e1*_t72;
  const double _t232 = 0.6e1*_t37;
  const double _t233 = _t30*_t64;
  const double _t234 = 0.3e1*_t73;
  const double _t235 = _t189*_t30;
  const double _t236 = 0.3e1*_t107;
  const double _t237 = 0.6e1*_hc3[2];
  const double _t238 = 0.6e1*_hc3[5];
  const double _t239 = 0.6e1*_hc1[1];
  const double _t240 = 0.6e1*_hc1[2];
  const double _t241 = 0.12e2*_hc4[5];
  const double _t242 = _hc1[1]*_t241;
  const double _t243 = 0.12e2*_hc1[2];
  const double _t244 = 0.12e2*_hc1[1];
  const double _t245 = 0.24e2*_t35;
  const double _t246 = _hc1[1]*_hc1[2];
  const double _t247 = 0.48e2*_t100;
  const double _t248 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t249 = 0.6e1*_t19;
  const double _t250 = _hc4[2]*_t249;
  const double _t251 = _hc4[0]*_t80;
  const double _t252 = _t243*_t80;
  const double _t253 = _t101*_t80;
  const double _t254 = 0.18e2*_t105*_t4;
  const double _t255 = 0.36e2*_t210;
  const double _t256 = xc_powi(_t6, -5);
  const double _t257 = _t256*_t5;
  const double _t258 = _t248*_t4;
  const double _t259 = _hc3[5]*_t237 + _hc4[2]*_t238 + _hc4[5]*_t237 + _hc4[5]*_t250 + _hc4[9]*_t1 + _hc4[9]*_t20 + _hc4[9]*_t3 + _t102*_t244 + 0.36e2*_t105*_t248 + _t200*_t242 + _t239*_t94 + _t240*_t32 - _t242*_t251 + _t243*_t98 - _t244*_t253 - _t245*_t246 + _t246*_t254 - _t247*_t97 - _t252*_t97 + _t255*_t97 - 0.24e2*_t257*_t258;
#endif
#if _KMAX >= 4
  const double _t260 = 0.4e1*_t110;
  const double _t261 = 0.24e2/xc_powi((_hc0[0]), 5);
  const double _t262 = _t261*_t41;
  const double _t263 = _t144*_t41;
  const double _t264 = 0.4e1*_hc0[6];
  const double _t265 = 0.24e2*_t21;
  const double _t266 = _t149*_t38;
  const double _t267 = _hc0[3]*_t266;
  const double _t268 = _t115*_t12;
  const double _t269 = 0.4e1*_t119;
  const double _t270 = _hc0[3]*_t47;
  const double _t271 = 0.24e2*_t26;
  const double _t272 = _t22*_t38;
  const double _t273 = _t115*_t22;
  const double _t274 = 0.12e2*_t21;
  const double _t275 = _t25*_t274;
  const double _t276 = -_hc0[6]*_t3 - 0.2e1*_hc2[6];
  const double _t277 = _t129*_t52;
  const double _t278 = _t122*_t9;
  const double _t279 = _t133*_t53;
  const double _t280 = _t16*_t279;
  const double _t281 = _t129*_t26;
  const double _t282 = 0.4e1*_hc0[1];
  const double _t283 = _t40*_t51;
  const double _t284 = 0.6e1*_t59;
  const double _t285 = 0.8e1*_t21;
  const double _t286 = 0.4e1*_t21*_t25;
  const double _t287 = 0.12e2*_t59;
  const double _t288 = _hc0[1]*_t275;
  const double _t289 = -0.3e1*_hc2[3] - 0.3e1*_t45;
  const double _t290 = _t141*_t53;
  const double _t291 = _t129*_t141;
  const double _t292 = _t138*_t54;
  const double _t293 = _t139*_t14;
  const double _t294 = _t292*_t293;
  const double _t295 = _t10/xc_powi(_t11, 5);
  const double _t296 = _t295*(-0.4e1*_hc2[1] - 0.4e1*_t24);
  const double _t297 = _hc0[4]*_t214;
  const double _t298 = _hc0[2]*_t113*_t61;
  const double _t299 = 0.18e2*_t298;
  const double _t300 = 0.18e2*_hc0[4];
  const double _t301 = 0.3e1*_hc0[7];
  const double _t302 = 0.12e2*_t150;
  const double _t303 = _hc0[4]*_t38;
  const double _t304 = _hc0[3]*_t12;
  const double _t305 = _t121*_t60;
  const double _t306 = _t12*_t145;
  const double _t307 = _hc0[4]*_t47;
  const double _t308 = _t22*_t60;
  const double _t309 = _t16*_t308;
  const double _t310 = 0.12e2*_t22;
  const double _t311 = _t154*_t310;
  const double _t312 = _t22*_t26;
  const double _t313 = _t312*_t60;
  const double _t314 = _hc4[3]*_t244;
  const double _t315 = 0.3e1*_t156;
  const double _t316 = _t67*_t9;
  const double _t317 = _t118*_t47;
  const double _t318 = _t21*_t64;
  const double _t319 = _t272*_t68;
  const double _t320 = 0.2e1*_t131;
  const double _t321 = 0.3e1*_hc0[4];
  const double _t322 = _t121*_t67;
  const double _t323 = _t51*_t60;
  const double _t324 = 0.6e1*_t323;
  const double _t325 = _t121*_t30;
  const double _t326 = 0.3e1*_t67;
  const double _t327 = _t326*_t9;
  const double _t328 = _t149*_t60;
  const double _t329 = _t279*_t71;
  const double _t330 = _t222*_t53;
  const double _t331 = 0.3e1*_t193;
  const double _t332 = _hc0[1]*_t279;
  const double _t333 = _t228*_t289;
  const double _t334 = _t293*_t68;
  const double _t335 = _t138*_t334;
  const double _t336 = _t135*_t30;
  const double _t337 = _t138*_t296;
  const double _t338 = _t127*_t37;
  const double _t339 = _t15*_t82;
  const double _t340 = _t37*_t46;
  const double _t341 = 0.6e1*_t82;
  const double _t342 = 0.3e1*_t168;
  const double _t343 = _t23*_t82;
  const double _t344 = 0.3e1*_t175;
  const double _t345 = 0.3e1*_t82;
  const double _t346 = _t147*_t41;
  const double _t347 = _hc0[5]*_t147;
  const double _t348 = _t12*_t60;
  const double _t349 = _hc0[4]*_t348;
  const double _t350 = _t142*_t47;
  const double _t351 = _t22*_t68;
  const double _t352 = _hc0[3]*_t71;
  const double _t353 = 0.2e1*_t185;
  const double _t354 = 0.4e1*_t67;
  const double _t355 = _hc0[1]*_t308;
  const double _t356 = 0.8e1*_t355;
  const double _t357 = _t51*_t84;
  const double _t358 = 0.2e1*_t59;
  const double _t359 = _t44*_t88;
  const double _t360 = _t191*_t52;
  const double _t361 = 0.2e1*_t316;
  const double _t362 = _t16*_t88;
  const double _t363 = _hc0[2]*_t293;
  const double _t364 = _t138*_t363;
  const double _t365 = _hc0[1]*_t192;
  const double _t366 = _t141*_t89;
  const double _t367 = 0.8e1*_t37;
  const double _t368 = 0.12e2*_t37;
  const double _t369 = 0.2e1*_t196;
  const double _t370 = 0.4e1*_t196;
  const double _t371 = _t37*_t70;
  const double _t372 = 0.4e1*_t82;
  const double _t373 = _t127*_t30;
  const double _t374 = 0.2e1*_t175;
  const double _t375 = _t30*_t70;
  const double _t376 = 0.2e1*_t213;
  const double _t377 = _hc1[1]*_hc4[4];
  const double _t378 = 0.16e2*_t377;
  const double _t379 = _hc4[3]*_t80;
  const double _t380 = _t178*_t41;
  const double _t381 = _t12*_t217;
  const double _t382 = 0.6e1*_hc0[5];
  const double _t383 = _t217*_t22;
  const double _t384 = 0.6e1*_t182;
  const double _t385 = 0.18e2*_t178;
  const double _t386 = 0.6e1*_t88;
  const double _t387 = _t64*_t88;
  const double _t388 = 0.3e1*_t188;
  const double _t389 = _t161*_t89;
  const double _t390 = _t192*_t71;
  const double _t391 = _t226*_t52;
  const double _t392 = _t140*_t230;
  const double _t393 = _t228*_t89;
  const double _t394 = _t230*_t71;
  const double _t395 = _t232*_t30;
  const double _t396 = 0.12e2*_t196;
  const double _t397 = 0.3e1*_t196;
  const double _t398 = 0.6e1*_t107;
  const double _t399 = 0.3e1*_t213;
  const double _t400 = _hc4[8]*_t244;
  const double _t401 = _hc4[2]*_t7;
  const double _t402 = 0.24e2*_t377;
  const double _t403 = 0.48e2*_t212;
  const double _t404 = _t246*_t34;
  const double _t405 = _hc4[1]*_hc4[2];
  const double _t406 = _t104*_t248;
  const double _t407 = _hc4[2]*_t80;
  const double _t408 = _t104*_t246*_t4;
  const double _t409 = _t256*_t258;
  const double _t410 = 0.4e1*_hc0[9];
  const double _t411 = 0.24e2*_t71;
  const double _t412 = 0.4e1*_t221;
  const double _t413 = 0.24e2*_t37;
  const double _t414 = 0.12e2*_t107;
  const double _t415 = 0.4e1*_t259;
  const double _t416 = 0.8e1*_hc4[9];
  const double _t417 = 0.16e2*_hc1[1]*_hc4[9];
  const double _t418 = 0.48e2*_hc1[1]*_hc4[5];
  const double _t419 = 0.24e2*_hc1[2];
  const double _t420 = 0.192e3*_t97;
  const double _t421 = 0.96e2*_t100;
  const double _t422 = _hc4[0]*_hc4[5];
  const double _t423 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t424 = ((_hc1[2]) * (_hc1[2]));
  const double _t425 = 0.72e2*_t210;
#endif

  const double f = _t13*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _t13*_t21 - _t15*_t16 + _t23*_t26;
  out[1] = df_du;
  const double df_dx = -_hc0[2]*_t27 + _t13*_t37 + _t30*_t31;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_du2 = -_hc0[3]*_t27 + _t13*_t59 + _t31*_t46 + _t40*_t42 - _t43*_t44 + _t44*_t50 - _t48*_t49 + _t52*_t54;
  out[3] = d2f_du2;
  const double d2f_dx_du = -_hc0[1]*_t72 - _hc0[4]*_t27 + _t13*_t82 - _t21*_t63 + _t21*_t69 + _t25*_t73 - _t26*_t64 + _t31*_t67 - _t47*_t68 + _t60*_t62 + _t70*_t71;
  out[4] = d2f_dx_du;
  const double d2f_dx2 = -_hc0[2]*_t91 - _hc0[5]*_t27 + _t107*_t13 + _t30*_t92 + _t31*_t88 + _t42*_t84 - _t64*_t85 + _t89*_t90;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_du3 = -0.3e1*_hc0[1]*_t134 - _hc0[6]*_t27 + _t110*_t13 + _t111*_t112 - _t115*_t116 - _t117*_t118 - _t118*_t48 + _t119*_t31 + _t120*_t121 - _t121*_t128 - _t122*_t123 + _t122*_t126 + _t125*_t26 + _t129*_t130 + _t131*_t132 - _t135*_t43 + _t135*_t50 + _t136*_t137 + _t141*_t54;
  out[6] = d3f_du3;
  const double d3f_dx_du2 = _hc0[3]*_t143 - _hc0[3]*_t158 - _hc0[3]*_t72 - _hc0[4]*_t146 - _hc0[7]*_t27 + _t111*_t142 - _t116*_t145 - _t123*_t157 + _t124*_t85 - _t127*_t162 + _t129*_t90 + _t13*_t175 + _t148*_t150 - _t151*_t46 - _t152*_t48 + _t153*_t154 + _t156*_t31 + _t157*_t163 - _t159*_t44 + _t160*_t67 - _t161*_t54 + _t162*_t70 - _t164*_t165 + _t166*_t53 + _t167*_t37 - _t168*_t169 + _t168*_t70 - _t170*_t43 + _t170*_t50 + _t46*_t73 - _t59*_t63 + _t59*_t69;
  out[7] = d3f_dx_du2;
  const double d3f_dx2_du = -_hc0[1]*_t197 - _hc0[4]*_t91 - _hc0[8]*_t27 - _t123*_t88 + _t13*_t213 + _t132*_t196 + _t142*_t177 + _t149*_t194 - _t151*_t157 - _t152*_t158 + _t153*_t68 - _t162*_t64 + _t166*_t89 - _t168*_t195 - _t169*_t196 - _t170*_t63 + _t170*_t69 + _t176*_t62 - 0.6e1*_t178*_t61 - _t179*_t21 + _t180*_t44 - _t181*_t26 + _t182*_t183 + _t185*_t31 + _t186*_t21 - _t187*_t85 + _t188*_t70 + _t189*_t193 + _t190*_t67 + _t191*_t90 - _t192*_t68 + _t198*_t25 + _t67*_t92;
  out[8] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[5]*_t215 - _hc0[5]*_t218 - _hc0[5]*_t231 - _hc0[9]*_t27 - _t116*_t217 + _t13*_t259 - _t151*_t223 + _t180*_t232 + _t182*_t222 + _t189*_t227 + _t221*_t31 - _t224*_t225 + _t226*_t90 + _t228*_t230 - _t232*_t233 + _t234*_t88 + 0.3e1*_t235*_t37 - _t236*_t63 + _t236*_t69;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_du4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t262 + _hc0[1]*_hc0[3]*_t271*_t272 - _hc0[10]*_t27 + ((_hc0[3]) * (_hc0[3]))*_t214 - _hc0[3]*_t15*_t284 - 0.36e2*_hc0[3]*_t263 + 0.8e1*_hc0[6]*_t111 + ((_hc4[3]) * (_hc4[3]))*_t13*_t249 - _t112*_t134 - _t117*_t264 + 0.3e1*_t119*_t163 + _t120*_t287 - _t123*_t269 + 0.12e2*_t124*_t131 + _t124*_t25*_t265 + _t126*_t269 - _t127*_t274*_t46 - _t128*_t287 + _t130*_t276 - 0.6e1*_t131*_t270 - _t133*_t281*_t282 + _t136*_t284 + _t140*_t289*_t54 + _t183*_t291 + _t23*_t284*_t46 - _t260*_t43 + _t260*_t50 - _t264*_t48 + _t265*_t267 - _t265*_t268 - _t270*_t275 - _t271*_t273 + _t277*_t278 + _t277*_t286 + _t278*_t290 - _t279*_t288 - 0.8e1*_t280*_t46 - _t282*_t294 + 0.12e2*_t283*_t54 + _t285*_t46*_t70 + _t286*_t290 + _t292*_t296 + _t31*(-_hc0[10]*_hc1[0] - _hc2[10]);
  out[10] = d4f_du4;
  const double d4f_dx_du3 = _hc0[1]*_t324*_t54 - _hc0[11]*_t27 + _hc0[2]*_t114*_t262 - _hc0[2]*_t294 + _hc0[3]*_t297 - _hc0[3]*_t299 - _hc0[4]*_t135*_t15 + _hc0[6]*_t143 - _hc0[6]*_t158 - _hc0[6]*_t72 + 0.6e1*_hc0[7]*_t111 - _t110*_t63 + _t110*_t69 + _t112*_t313 + _t112*_t319 - _t117*_t301 - _t118*_t329 - _t118*_t339 - _t119*_t151 + _t119*_t73 + _t120*_t341 - _t121*_t25*_t307 - _t122*_t318 - _t122*_t338 + _t122*_t343 - _t123*_t315 + _t124*_t325 + _t125*_t168 + _t125*_t316 + _t126*_t315 - _t127*_t322 - _t127*_t336 - _t128*_t341 - 0.3e1*_t129*_t164 + _t13*(_hc4[4]*_t109 - _t209*_t314 + _t314*_t76) + _t132*_t340 - _t134*_t321 - _t135*_t159 + _t135*_t23*_t67 + _t136*_t345 - _t137*_t187*_t25 - 0.18e2*_t145*_t312 - _t161*_t281 + _t163*_t315 + _t168*_t277 + _t168*_t290 - _t168*_t317 - _t187*_t320 - _t193*_t317 - 0.18e2*_t21*_t306 - _t222*_t273 + _t232*_t267 - _t232*_t268 - _t263*_t300 + _t276*_t90 + _t277*_t327 + _t277*_t331 - _t278*_t307 - 0.6e1*_t280*_t67 + _t283*_t330 + _t284*_t328 + _t288*_t308 + _t290*_t327 + _t290*_t331 + _t291*_t85 - _t301*_t48 + _t302*_t303 + _t303*_t311 + _t304*_t305 + 0.6e1*_t309*_t46 + _t31*(-_hc0[11]*_hc1[0] - _hc0[6]*_hc1[1] - _hc2[11]) - _t316*_t317 + _t322*_t70 - _t325*_t332 - _t332*_t342 + _t333*_t53 - 0.3e1*_t335*_t53 + _t336*_t70 + _t337*_t53*_t71 - _t344*_t43 + _t344*_t50;
  out[11] = d4f_dx_du3;
  const double d4f_dx2_du2 = -_hc0[12]*_t27 + _hc0[2]*_hc0[7]*_t346 - _hc0[3]*_t116*_t178 + _hc0[3]*_t176*_t42 - _hc0[3]*_t197 + ((_hc0[4]) * (_hc0[4]))*_t346 + _hc0[4]*_t266*_t367 - 0.24e2*_hc0[4]*_t298 + 0.8e1*_hc0[4]*_t313 - _hc0[5]*_t116*_t144 - _hc0[5]*_t134 - 0.2e1*_hc0[7]*_t158 - _hc0[7]*_t91 - _hc0[8]*_t146 + _hc0[8]*_t147*_t61 - 0.2e1*_hc0[8]*_t48 + _t107*_t136 + _t107*_t167 - _t107*_t169*_t25 - _t123*_t353 + _t124*_t227 + _t124*_t370 - _t127*_t359 - _t129*_t161*_t85 + _t13*(_hc4[0]*_hc4[3]*_t211 + _hc4[1]*_hc4[8]*_t172 + _hc4[3]*_t199 - _hc4[3]*_t206 + _hc4[3]*_t95 + ((_hc4[4]) * (_hc4[4]))*_t172 + _hc4[8]*_t55 + _t171*_t202 + _t171*_t204 + _t171*_t207 - _t174*_t203 - _t202*_t379 + _t203*_t57 - _t204*_t379 - _t205*_t56 - _t209*_t378 + _t211*_t56 + _t378*_t76) - _t131*_t181 - _t133*_t165*_t362 + _t141*_t191*_t85 - _t142*_t329 - _t142*_t339 - _t145*_t310*_t71 + _t150*_t347 - 0.2e1*_t151*_t156 + _t153*_t352 + _t154*_t22*_t347 + _t156*_t190 + _t156*_t92 - _t157*_t16*_t192 - _t159*_t372 + _t160*_t185 - _t161*_t165*_t168 + _t162*_t360 - _t162*_t365 + _t162*_t366 + _t163*_t353 - 0.2e1*_t164*_t191 - _t168*_t350 + _t168*_t356 - _t178*_t302 - _t178*_t311 - _t179*_t59 + _t180*_t358 - _t181*_t25*_t44 + _t182*_t286 + _t182*_t320 + _t186*_t59 - 0.4e1*_t187*_t193 - _t187*_t354*_t9 - _t188*_t270 + _t188*_t277 + _t188*_t290 + _t189*_t44*_t67 - _t192*_t352 - _t193*_t350 + _t193*_t356 + _t194*_t304 - _t195*_t340 + _t198*_t46 + _t224*_t337 - _t233*_t358 + _t235*_t59 + _t262*_t39*_t83 - _t270*_t369 + _t277*_t369 + _t283*_t85*_t89 + _t285*_t349 + _t290*_t369 + 0.8e1*_t303*_t351 - _t306*_t368 + 0.8e1*_t309*_t67 + _t31*(-_hc0[12]*_hc1[0] - _hc0[3]*_hc1[2] - _hc0[7]*_t33 - _hc2[12]) - _t316*_t350 - _t318*_t354 + 0.8e1*_t323*_t53*_t68 + 0.8e1*_t328*_t82 - _t332*_t370 + _t333*_t89 - 0.2e1*_t335*_t89 - _t338*_t354 + _t343*_t354 + _t354*_t371 + 0.2e1*_t357*_t54 + _t359*_t70 + _t360*_t361 + _t361*_t366 - _t364*_t53*_t85 - _t372*_t373 + _t372*_t375 - _t374*_t63 + _t374*_t69 - _t376*_t43 + _t376*_t50 + _t90*(-_hc0[7]*_t3 - 0.2e1*_hc2[7] - 0.2e1*_t155);
  out[12] = d4f_dx2_du2;
  const double d4f_dx3_du = -_hc0[13]*_t27 + 0.12e2*_hc0[4]*_t308*_t71 + _hc0[5]*_t12*_t305 + _hc0[5]*_t297 - _hc0[5]*_t299 - 0.3e1*_hc0[5]*_t329 + _hc0[8]*_t215 - _hc0[8]*_t218 - _hc0[8]*_t231 - _hc0[9]*_t117 + _hc0[9]*_t38*_t62 - _hc0[9]*_t48 - _t121*_t381 - _t123*_t221 + _t126*_t221 + _t13*(_hc4[2]*_t243*_t76 + _hc4[4]*_hc4[5]*_t249 + _hc4[4]*_t238 + _hc4[4]*_t240 + _hc4[8]*_t237 + _hc4[8]*_t239 + _hc4[8]*_t250 + _hc4[9]*_t58*_t76 + _hc4[9]*_t74 + _t200*_t400 + _t201*_t243 - _t208*_t247 - _t208*_t252 + _t208*_t255 - _t209*_t242 + 0.72e2*_t212*_t406 + 0.36e2*_t212*_t408 + _t242*_t76 - _t247*_t405 - _t251*_t400 - _t252*_t405 + _t255*_t405 + _t401*_t402 - _t402*_t407 - _t403*_t404 - _t403*_t409) - _t137*_t387 + _t149*_t176*_t232 - _t149*_t37*_t385 - 0.3e1*_t151*_t185 - _t159*_t236 + _t163*_t221 - _t164*_t226 + _t166*_t226 + _t168*_t384 - _t179*_t345 + _t180*_t341 - _t181*_t327 - _t181*_t331 - _t181*_t342 + _t182*_t325 + _t185*_t234 + _t186*_t345 - _t187*_t388 - _t187*_t395 - _t188*_t321*_t47 + _t189*_t326*_t37 + _t189*_t359 + _t190*_t353 - _t191*_t225*_t71 + _t191*_t228*_t229 - 0.2e1*_t192*_t362 + _t193*_t391 + _t193*_t392 - _t197*_t321 + _t198*_t326 + _t216*_t261*_t61 - _t223*_t338 + _t223*_t371 - 0.3e1*_t224*_t364 + _t227*_t360 + _t227*_t366 - _t230*_t334 - _t232*_t64*_t67 - _t233*_t341 + _t235*_t345 - _t236*_t373 + _t236*_t375 - _t259*_t43 + _t259*_t50 - 0.6e1*_t26*_t383 + _t296*_t394 - _t300*_t380 - _t307*_t395 + _t309*_t386 + _t31*(-_hc0[13]*_hc1[0] - _hc0[4]*_t219 - _hc0[8]*_t220 - _hc2[13]) + _t313*_t382 + _t316*_t384 + _t316*_t391 + _t316*_t392 + _t319*_t382 - _t321*_t390 + _t324*_t68*_t89 - _t327*_t389 + _t328*_t398 + _t330*_t357 - _t331*_t389 + _t349*_t368 - _t351*_t385 + _t355*_t396 + _t360*_t397 - _t365*_t397 + _t366*_t397 + _t393*(-0.3e1*_hc2[4] - 0.3e1*_t65 - 0.3e1*_t66) - _t399*_t63 + _t399*_t69 + _t90*(-_hc0[4]*_t77 - _hc0[8]*_t3 - 0.2e1*_hc2[8] - 0.2e1*_t184);
  out[13] = d4f_dx3_du;
  const double d4f_dx4 = -_hc0[14]*_t27 + ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t262 + ((_hc0[5]) * (_hc0[5]))*_t214 + _hc0[5]*_t308*_t411 + _hc0[5]*_t348*_t413 - 0.36e2*_hc0[5]*_t380 + 0.8e1*_hc0[9]*_t177 + _t13*(_hc1[1]*_t416 + 0.216e3*_hc1[2]*_t105*_t99 - 0.144e3*_hc1[2]*_t106*_t257 + _hc3[2]*_t416 + 0.6e1*((_hc3[5]) * (_hc3[5])) + _hc3[5]*_t241 + _hc4[14]*_t1 + _hc4[14]*_t20 + _hc4[14]*_t3 + _hc4[2]*_t19*_t416 + ((_hc4[5]) * (_hc4[5]))*_t249 + _hc4[5]*_t200*_t419 - _t101*_t421 + _t101*_t425 + _t102*_t419 + _t200*_t417 + _t243*_t94 - _t245*_t424 - _t251*_t417 - _t253*_t419 + _t254*_t424 - 0.192e3*_t257*_t423 + 0.120e3*_t4*_t423*_t5/xc_powi(_t6, 6) + _t401*_t418 - _t404*_t420 + 0.288e3*_t406*_t97 - _t407*_t418 + 0.144e3*_t408*_t97 - _t409*_t420 - _t419*_t422*_t80 - _t421*_t422 + _t422*_t425) + _t140*_t226*_t229*_t85 - _t151*_t412 - _t158*_t410 - 0.4e1*_t161*_t226*_t71 + _t180*_t414 - 0.6e1*_t181*_t188 - _t181*_t396 + 0.12e2*_t182*_t188 + _t182*_t30*_t413 - 0.8e1*_t188*_t389 + _t189*_t367*_t88 + 0.3e1*_t190*_t221 - _t197*_t382 + _t198*_t386 + 0.12e2*_t224*_t357 - _t233*_t414 + _t235*_t398 + _t295*_t394*(-0.4e1*_hc2[2] - 0.4e1*_t28 - 0.4e1*_t29) + _t31*(-_hc0[14]*_hc1[0] - _hc0[5]*_t240 - _hc0[9]*_t77 - _hc2[14]) - 0.4e1*_t363*_t394 - _t368*_t387 + _t370*_t391 + _t370*_t392 - _t381*_t413 - _t382*_t390 - _t383*_t411 + _t388*_t391 + _t388*_t392 - _t389*_t396 + _t393*(-_hc0[2]*_t239 - 0.3e1*_hc2[5] - 0.3e1*_t86 - 0.3e1*_t87) - _t410*_t72 + _t412*_t73 - _t415*_t63 + _t415*_t69 + _t90*(-_hc0[2]*_t240 - _hc0[5]*_t239 - _hc0[9]*_t3 - 0.2e1*_hc2[9]);
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_alpha_k, _KMAX)(const xc_func_type *p, double x, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_z_k, _KMAX)(p, x, u, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pc07_fab_k, _KMAX)(p, _hc0[0], _hc1);
#if _KMAX >= 1
  const double _t1 = _hc0[0]*_hc1[1];
#endif
#if _KMAX >= 2
  const double _t2 = ((_hc0[1]) * (_hc0[1]));
  const double _t3 = 0.2e1*_hc1[1];
  const double _t4 = _hc0[0]*_hc1[2];
  const double _t5 = _hc0[1]*_hc0[2];
  const double _t6 = ((_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 3
  const double _t7 = 0.6e1*_hc1[1];
  const double _t8 = _hc0[1]*_t7;
  const double _t9 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t10 = 0.3e1*_hc1[2];
  const double _t11 = _hc0[0]*_hc1[3];
  const double _t12 = 0.3e1*_t4;
  const double _t13 = _hc0[1]*_t12;
  const double _t14 = 0.4e1*_hc1[1];
  const double _t15 = _hc0[4]*_t14;
  const double _t16 = _hc0[2]*_hc0[3];
  const double _t17 = 0.2e1*_t4;
  const double _t18 = _hc0[4]*_t17;
  const double _t19 = _hc0[2]*_t2;
  const double _t20 = _hc0[1]*_hc0[5];
  const double _t21 = _hc0[1]*_t6;
  const double _t22 = _hc0[2]*_t7;
  const double _t23 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t24 = _hc0[2]*_t12;
#endif
#if _KMAX >= 4
  const double _t25 = 0.8e1*_hc1[1];
  const double _t26 = _hc0[1]*_hc0[6];
  const double _t27 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t28 = 0.4e1*_hc1[3];
  const double _t29 = ((_hc0[3]) * (_hc0[3]));
  const double _t30 = _hc0[0]*_hc1[4];
  const double _t31 = 0.4e1*_t4;
  const double _t32 = _hc1[2]*_t2;
  const double _t33 = _t11*_t2;
  const double _t34 = _hc0[2]*_hc0[6];
  const double _t35 = _hc0[4]*_t7;
  const double _t36 = _hc0[4]*_t12;
  const double _t37 = _hc1[2]*_t5;
  const double _t38 = 0.9e1*_t37;
  const double _t39 = 0.9e1*_hc0[4];
  const double _t40 = _hc0[2]*_t9;
  const double _t41 = _t11*_t5;
  const double _t42 = 0.3e1*_t41;
  const double _t43 = 0.3e1*_hc0[4];
  const double _t44 = _hc0[1]*_hc0[8];
  const double _t45 = _hc0[2]*_hc0[7];
  const double _t46 = _hc0[3]*_hc0[5];
  const double _t47 = ((_hc0[4]) * (_hc0[4]));
  const double _t48 = _hc0[5]*_t2;
  const double _t49 = _hc0[3]*_t6;
  const double _t50 = _t2*_t6;
  const double _t51 = _hc0[1]*_hc0[9];
  const double _t52 = _hc0[1]*_t23;
  const double _t53 = _hc1[2]*_t6;
  const double _t54 = _t11*_t6;
  const double _t55 = _hc0[2]*_hc0[9];
  const double _t56 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t57 = ((_hc0[5]) * (_hc0[5]));
#endif

  const double f = _hc0[0]*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _hc0[1]*_hc1[0] + _hc0[1]*_t1;
  out[1] = df_du;
  const double df_dx = _hc0[2]*_hc1[0] + _hc0[2]*_t1;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _hc0[3]*_hc1[0] + _hc0[3]*_t1 + _t2*_t3 + _t2*_t4;
  out[3] = d2f_du2;
  const double d2f_dx_du = _hc0[4]*_hc1[0] + _hc0[4]*_t1 + _t3*_t5 + _t4*_t5;
  out[4] = d2f_dx_du;
  const double d2f_dx2 = _hc0[5]*_hc1[0] + _hc0[5]*_t1 + _t3*_t6 + _t4*_t6;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_du3 = _hc0[3]*_t13 + _hc0[3]*_t8 + _hc0[6]*_hc1[0] + _hc0[6]*_t1 + _t10*_t9 + _t11*_t9;
  out[6] = d3f_du3;
  const double d3f_dx_du2 = _hc0[1]*_t15 + _hc0[1]*_t18 + _hc0[7]*_hc1[0] + _hc0[7]*_t1 + _t10*_t19 + _t11*_t19 + _t16*_t3 + _t16*_t4;
  out[7] = d3f_dx_du2;
  const double d3f_dx2_du = _hc0[2]*_t15 + _hc0[2]*_t18 + _hc0[8]*_hc1[0] + _hc0[8]*_t1 + _t10*_t21 + _t11*_t21 + _t20*_t3 + _t20*_t4;
  out[8] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[5]*_t22 + _hc0[5]*_t24 + _hc0[9]*_hc1[0] + _hc0[9]*_t1 + _t10*_t23 + _t11*_t23;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_du4 = _hc0[10]*_hc1[0] + _hc0[10]*_t1 + 0.18e2*_hc0[3]*_t32 + 0.6e1*_hc0[3]*_t33 + _t12*_t29 + _t25*_t26 + _t26*_t31 + _t27*_t28 + _t27*_t30 + _t29*_t7;
  out[10] = d4f_du4;
  const double d4f_dx_du3 = _hc0[11]*_hc1[0] + _hc0[11]*_t1 + _hc0[3]*_t35 + _hc0[3]*_t36 + _hc0[3]*_t38 + _hc0[3]*_t42 + _hc0[7]*_t13 + _hc0[7]*_t8 + _t28*_t40 + _t3*_t34 + _t30*_t40 + _t32*_t39 + _t33*_t43 + _t34*_t4;
  out[11] = d4f_dx_du3;
  const double d4f_dx2_du2 = _hc0[12]*_hc1[0] + _hc0[12]*_t1 + 0.12e2*_hc0[4]*_t37 + 0.4e1*_hc0[4]*_t41 + _t10*_t48 + _t10*_t49 + _t11*_t48 + _t11*_t49 + _t14*_t44 + _t14*_t45 + _t14*_t47 + _t17*_t44 + _t17*_t45 + _t17*_t47 + _t28*_t50 + _t3*_t46 + _t30*_t50 + _t4*_t46;
  out[12] = d4f_dx2_du2;
  const double d4f_dx3_du = _hc0[13]*_hc1[0] + _hc0[13]*_t1 + _hc0[5]*_t35 + _hc0[5]*_t36 + _hc0[5]*_t38 + _hc0[5]*_t42 + _hc0[8]*_t22 + _hc0[8]*_t24 + _t28*_t52 + _t3*_t51 + _t30*_t52 + _t39*_t53 + _t4*_t51 + _t43*_t54;
  out[13] = d4f_dx3_du;
  const double d4f_dx4 = _hc0[14]*_hc1[0] + _hc0[14]*_t1 + 0.18e2*_hc0[5]*_t53 + 0.6e1*_hc0[5]*_t54 + _t12*_t57 + _t25*_t55 + _t28*_t56 + _t30*_t56 + _t31*_t55 + _t57*_t7;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scanl_f_k, _KMAX)(const xc_func_type *p, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_alpha_k, _KMAX)(p, x, u, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_f_a_k, _KMAX)(p, x, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = ((_hc0[1]) * (_hc0[1]));
  const double _t2 = _hc0[2]*_hc1[3];
  const double _t3 = _hc1[4] + _t2;
#endif
#if _KMAX >= 3
  const double _t4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t5 = 0.3e1*_hc1[3];
  const double _t6 = _hc0[4]*_hc1[3];
  const double _t7 = 0.2e1*_hc0[1];
  const double _t8 = _hc0[2]*_hc1[6];
  const double _t9 = _hc0[1]*_hc1[7];
  const double _t10 = _hc0[5]*_hc1[3];
  const double _t11 = _hc0[1]*_t8;
  const double _t12 = _t11 + _t6 + _t9;
  const double _t13 = _hc0[2]*_hc1[7];
  const double _t14 = _hc1[8] + _t13;
  const double _t15 = 0.2e1*_hc0[5];
  const double _t16 = _hc1[7] + _t8;
  const double _t17 = _hc0[2]*_t16 + _t10 + _t14;
#endif
#if _KMAX >= 4
  const double _t18 = 0.3e1*_hc0[3];
  const double _t19 = _hc0[7]*_hc1[3];
  const double _t20 = _hc0[2]*_hc1[10];
  const double _t21 = _hc0[4]*_hc1[6];
  const double _t22 = 0.2e1*_hc0[4];
  const double _t23 = _hc0[8]*_hc1[3];
  const double _t24 = _hc1[11]*_t1;
  const double _t25 = _hc0[5]*_hc1[6];
  const double _t26 = _hc0[1]*_hc1[12];
  const double _t27 = _hc0[9]*_hc1[3];
  const double _t28 = _hc0[1]*_hc1[11];
  const double _t29 = _hc0[2]*_t28 + _hc0[4]*_hc1[7] + _t26;
  const double _t30 = _hc0[2]*_hc1[12] + _hc1[13];
  const double _t31 = _hc0[2]*_hc1[11] + _hc1[12];
  const double _t32 = _hc0[2]*_t31 + _hc0[5]*_hc1[7] + _t30;
#endif

  const double f = _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_du = _hc0[1]*_hc1[1];
  out[2] = df_du;
  const double df_dx = _hc0[2]*_hc1[1] + _hc1[2];
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = _hc0[3]*_hc1[1] + _hc1[3]*_t1;
  out[6] = d2f_du2;
  const double d2f_dx_dt = 0;
  out[7] = d2f_dx_dt;
  const double d2f_dx_du = _hc0[1]*_hc1[4] + _hc0[1]*_t2 + _hc0[4]*_hc1[1];
  out[8] = d2f_dx_du;
  const double d2f_dx2 = _hc0[2]*_hc1[4] + _hc0[2]*_t3 + _hc0[5]*_hc1[1] + _hc1[5];
  out[9] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = _hc0[1]*_hc0[3]*_t5 + _hc0[6]*_hc1[1] + _hc1[6]*_t4;
  out[13] = d3f_du3;
  const double d3f_dx_dt2 = 0;
  out[14] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[15] = d3f_dx_du_dt;
  const double d3f_dx_du2 = _hc0[3]*_hc1[4] + _hc0[3]*_t2 + _hc0[7]*_hc1[1] + _hc1[7]*_t1 + _t1*_t8 + _t6*_t7;
  out[16] = d3f_dx_du2;
  const double d3f_dx2_dt = 0;
  out[17] = d3f_dx2_dt;
  const double d3f_dx2_du = _hc0[1]*_hc1[8] + _hc0[1]*_t10 + _hc0[2]*_t12 + _hc0[2]*_t9 + _hc0[4]*_hc1[4] + _hc0[4]*_t3 + _hc0[8]*_hc1[1];
  out[18] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[2]*_hc1[8] + _hc0[2]*_t14 + _hc0[2]*_t17 + _hc0[5]*_hc1[4] + _hc0[9]*_hc1[1] + _hc1[9] + _t15*_t3;
  out[19] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[10] + 0.4e1*_hc0[1]*_hc0[6]*_hc1[3] + _hc0[10]*_hc1[1] + ((_hc0[3]) * (_hc0[3]))*_t5 + 0.6e1*_hc0[3]*_hc1[6]*_t1;
  out[24] = d4f_du4;
  const double d4f_dx_dt3 = 0;
  out[25] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[26] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[27] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0.3e1*_hc0[1]*_t19 + _hc0[11]*_hc1[1] + _hc0[6]*_hc1[4] + _hc0[6]*_t2 + _hc1[11]*_t4 + 0.3e1*_t1*_t21 + _t11*_t18 + _t18*_t6 + _t18*_t9 + _t20*_t4;
  out[28] = d4f_dx_du3;
  const double d4f_dx2_dt2 = 0;
  out[29] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[30] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = _hc0[12]*_hc1[1] + _hc0[2]*_t24 + _hc0[2]*(_hc0[3]*_hc1[7] + _hc0[3]*_t8 + _t1*_t20 + _t19 + _t21*_t7 + _t24) + _hc0[3]*_hc1[8] + _hc0[3]*_t10 + _hc0[3]*_t13 + _hc0[7]*_hc1[4] + _hc0[7]*_t3 + _hc1[12]*_t1 + _t1*_t25 + _t12*_t22 + _t22*_t9 + _t23*_t7;
  out[31] = d4f_dx2_du2;
  const double d4f_dx3_dt = 0;
  out[32] = d4f_dx3_dt;
  const double d4f_dx3_du = _hc0[1]*_hc1[13] + _hc0[1]*_t27 + _hc0[13]*_hc1[1] + _hc0[2]*_t26 + _hc0[2]*_t29 + _hc0[2]*(_hc0[1]*_t25 + _hc0[2]*(_hc0[1]*_t20 + _t21 + _t28) + _hc0[4]*_t16 + _t23 + _t29) + _hc0[4]*_hc1[8] + _hc0[4]*_t14 + _hc0[4]*_t17 + _hc0[5]*_t9 + _hc0[8]*_hc1[4] + 0.2e1*_hc0[8]*_t3 + _t12*_t15;
  out[33] = d4f_dx3_du;
  const double d4f_dx4 = _hc0[14]*_hc1[1] + _hc0[2]*_hc1[13] + _hc0[2]*_t30 + _hc0[2]*_t32 + _hc0[2]*(_hc0[2]*(_hc0[2]*(_hc1[11] + _t20) + _t25 + _t31) + _t15*_t16 + _t27 + _t32) + _hc0[5]*_hc1[8] + 0.3e1*_hc0[5]*_t17 + _hc0[9]*_hc1[4] + 0.3e1*_hc0[9]*_t3 + _hc1[14] + _t14*_t15;
  out[34] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);

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
  const double _t36 = (0.5e1 / 0.3e1)*lapl_s;
  const double _t37 = _t35*_t36;
  const double _t38 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t43 = xc_powr(n_s, -11, 3);
  const double _t44 = (0.2e1 / 0.3e1)*_t43;
  const double _t45 = (0.2e1 / 0.3e1)*_t12;
  const double _t47 = (0.5e1 / 0.6e1)*lapl_s;
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
  const double _t109 = (0.5e1 / 0.12e2)*lapl_s;
  const double _t116 = (0.40e2 / 0.9e1)*lapl_s;
  const double _t119 = _t18*lapl_s;
  const double _t126 = (0.14e2 / 0.9e1)*_t73;
  const double _t127 = (0.14e2 / 0.9e1)*_t12;
  const double _t128 = (0.20e2 / 0.9e1)*lapl_s;
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
  const double _t175 = _t92*lapl_s;
  const double _t176 = (0.5e1 / 0.6e1)*_t175;
  const double _t180 = (0.4e1 / 0.3e1)*_t21;
  const double _t181 = _t107*_t43;
  const double _t189 = _t59*lapl_s;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t8)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t8)) XC_CAT(scanl_f_k, _KMAX)(p, _t5*_t6, _t7*lapl_s, 0, _hc1);
  const double _t9 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t10 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[2]*_t7);
  const double _t11 = (0.1e1 / 0.2e1)*_hc0[0];
  const double _t13 = _hc1[3]*_t12;
  const double _t14 = my_piecewise3(_t8, 0, _t11*_t13*_t5);
  const double _t15 = _hc0[2]*_t3;
  const double _t16 = (0.1e1 / 0.6e1)*_t15;
  const double _t19 = _hc1[2]*_t18;
  const double _t22 = _hc1[3]*_t21;
  const double _t23 = -_t19*lapl_s - _t20*_t22;
  const double _t24 = my_piecewise3(_t8, 0, _hc0[0]*_t23 - _hc1[0]*_t16*_t5);
#endif
#if _KMAX >= 2
  const double _t26 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[6]*_t25);
  const double _t28 = _hc1[8]*_t12;
  const double _t29 = my_piecewise3(_t8, 0, _t11*_t27*_t28);
  const double _t30 = (0.1e1 / 0.4e1)*_hc0[0];
  const double _t32 = _hc1[3]*_t31;
  const double _t34 = my_piecewise3(_t8, 0, (0.1e1 / 0.4e1)*_hc0[0]*_hc1[9]*_t17*_t33 - _t30*_t32*_t5);
  const double _t39 = _hc1[8]*_t20;
  const double _t40 = -_hc1[6]*_t37 - _t19 - _t38*_t39;
  const double _t41 = my_piecewise3(_t8, 0, _hc0[0]*_t40 - _hc1[2]*_t16*_t27);
  const double _t42 = _t15*_t17;
  const double _t46 = _hc1[8]*_t38;
  const double _t49 = -_hc1[9]*_t44 - _t22*_t45 - _t46*_t48;
  const double _t50 = my_piecewise3(_t8, 0, _hc0[0]*_t49 - 0.1e1 / 0.12e2*_t13*_t42);
  const double _t51 = (0.2e1 / 0.9e1)*_hc1[0];
  const double _t52 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t55 = _hc0[5]*_t53*_t54;
  const double _t56 = _t17*_t55;
  const double _t57 = _t15*_t23;
  const double _t60 = _hc1[2]*_t59;
  const double _t62 = _hc1[3]*_t25;
  const double _t63 = _hc1[6]*_t18;
  const double _t64 = -_t21*_t39 - _t63*lapl_s;
  const double _t65 = _t18*_t64;
  const double _t66 = _hc1[8]*_t18;
  const double _t68 = -_hc1[9]*_t67 - _t66*lapl_s;
  const double _t69 = _t60*lapl_s + _t61*_t62 - _t65*lapl_s - _t67*_t68;
  const double _t70 = my_piecewise3(_t8, 0, _hc0[0]*_t69 + _t15*_t21*_t51 + _t52*_t56 - _t57*_t58);
#endif
#if _KMAX >= 3
  const double _t72 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[13]*_t71);
  const double _t74 = _hc1[16]*_t12;
  const double _t75 = my_piecewise3(_t8, 0, _t11*_t73*_t74);
  const double _t76 = _hc1[18]*_t33;
  const double _t77 = _t30*_t31;
  const double _t78 = _hc1[8]*_t27;
  const double _t79 = my_piecewise3(_t8, 0, _t30*_t35*_t76 - _t77*_t78);
  const double _t80 = _hc1[19]*_t38;
  const double _t81 = (0.1e1 / 0.8e1)*_hc0[0]*_t31;
  const double _t83 = (0.3e1 / 0.8e1)*_hc0[0];
  const double _t84 = _t82*_t83;
  const double _t85 = _hc1[3]*_t5;
  const double _t87 = _hc1[9]*_t86;
  const double _t88 = my_piecewise3(_t8, 0, -_t17*_t83*_t87 + _t80*_t81 + _t84*_t85);
  const double _t91 = _hc1[13]*_t90;
  const double _t93 = _hc1[16]*_t20;
  const double _t94 = -_hc1[6]*_t89 - _t36*_t91 - _t92*_t93;
  const double _t95 = my_piecewise3(_t8, 0, _hc0[0]*_t94 - _hc1[6]*_t16*_t73);
  const double _t96 = _t15*_t35;
  const double _t100 = _t74*_t92;
  const double _t101 = -_hc1[18]*_t98 - _t100*_t47 - _t46*_t99;
  const double _t102 = my_piecewise3(_t8, 0, _hc0[0]*_t101 - 0.1e1 / 0.12e2*_t28*_t96);
  const double _t103 = _hc1[9]*_t33;
  const double _t104 = (0.1e1 / 0.24e2)*_t15;
  const double _t108 = _t76*_t97;
  const double _t110 = -_hc1[19]*_t106 + (0.1e1 / 0.3e1)*_hc1[3]*_t21*_t31 + (0.5e1 / 0.12e2)*_hc1[8]*_t31*_t38*lapl_s - _hc1[9]*_t107*_t43 - _t108*_t109;
  const double _t111 = my_piecewise3(_t8, 0, _hc0[0]*_t110 - _t103*_t104*_t38 + (0.1e1 / 0.24e2)*_t32*_t42);
  const double _t112 = (0.2e1 / 0.9e1)*_t15;
  const double _t113 = (0.1e1 / 0.36e2)*_hc1[2];
  const double _t114 = _t15*_t58;
  const double _t115 = _hc1[6]*_t97;
  const double _t117 = _hc1[8]*_t61;
  const double _t118 = -_hc1[13]*_t37 - _t38*_t93 - _t63;
  const double _t120 = _hc1[18]*_t38;
  const double _t121 = -_hc1[16]*_t37 - _t120*_t20 - _t66;
  const double _t122 = _t115*_t116 + _t117*_t71 - _t118*_t119 - _t121*_t67 + _t60 - _t65;
  const double _t123 = my_piecewise3(_t8, 0, _hc0[0]*_t122 + _hc1[2]*_t112*_t38 + _t113*_t35*_t55 - _t114*_t40);
  const double _t124 = (0.1e1 / 0.9e1)*_t15;
  const double _t125 = (0.1e1 / 0.72e2)*_t55;
  const double _t130 = -_hc1[18]*_t44 - _hc1[8]*_t129 - _t38*_t47*_t74;
  const double _t131 = _t130*_t18;
  const double _t132 = -_hc1[19]*_t44 - _hc1[9]*_t129 - _t120*_t48;
  const double _t133 = _hc1[9]*_t126 + _t127*_t62 + _t128*_t28*_t71 - _t129*_t68 - _t131*lapl_s - _t132*_t67;
  const double _t134 = my_piecewise3(_t8, 0, _hc0[0]*_t133 - _t114*_t49 + _t124*_t13*_t43 + _t125*_t13*_t38);
  const double _t135 = _hc0[9]/M_PI;
  const double _t136 = _t135*_t38;
  const double _t137 = (0.14e2 / 0.27e2)*_t15;
  const double _t138 = (0.1e1 / 0.9e1)*_t55;
  const double _t139 = _hc0[2]*_t4*_t5;
  const double _t141 = _hc1[2]*_t140;
  const double _t143 = _hc1[3]*_t35;
  const double _t144 = _hc1[6]*_t59;
  const double _t145 = _hc1[13]*_t18;
  const double _t146 = -_hc1[16]*_t67 - _t145*lapl_s;
  const double _t147 = _t146*_t18;
  const double _t148 = _hc1[16]*_t18;
  const double _t149 = -_hc1[18]*_t67 - _t148*lapl_s;
  const double _t150 = _t117*_t25 + _t144*lapl_s - _t147*lapl_s - _t149*_t67;
  const double _t151 = _t150*_t18;
  const double _t152 = _hc1[8]*_t59;
  const double _t153 = _hc1[9]*_t25;
  const double _t154 = _t149*_t18;
  const double _t155 = _hc1[18]*_t18;
  const double _t156 = -_hc1[19]*_t67 - _t155*lapl_s;
  const double _t157 = _t152*lapl_s + _t153*_t61 - _t154*lapl_s - _t156*_t67;
  const double _t158 = -_t141*lapl_s - _t142*_t143 - _t151*lapl_s - _t157*_t67 + (0.56e2 / 0.9e1)*_t25*_t6*_t68 + (0.80e2 / 0.9e1)*_t43*_t64*lapl_s;
  const double _t159 = my_piecewise3(_t8, 0, _hc0[0]*_t158 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t21*_t23 + (0.1e1 / 0.12e2)*_hc0[5]*_t17*_t23*_t53*_t54 - _hc1[0]*_t137*_t25 - _hc1[0]*_t138*_t43 - _t136*_t52 - _t139*_t69);
#endif
#if _KMAX >= 4
  const double _t162 = _hc1[28]*_t12;
  const double _t164 = _hc1[24]*_t36;
  const double _t166 = _hc1[28]*_t20;
  const double _t168 = _hc1[31]*_t167;
  const double _t169 = _hc1[28]*_t48;
  const double _t170 = _hc1[33]*_t160;
  const double _t172 = _hc1[13]*_t116;
  const double _t173 = _hc1[16]*_t61;
  const double _t174 = _hc1[31]*_t20;
  const double _t177 = (0.1e1 / 0.18e2)*_t15;
  const double _t178 = (0.1e1 / 0.144e3)*_t55;
  const double _t179 = _hc1[8]*lapl_s;
  const double _t182 = _hc1[6]*lapl_s;
  const double _t183 = _hc1[8]*_t142;
  const double _t184 = -_hc1[28]*_t37 - _t148 - _t174*_t38;
  const double _t185 = _hc1[18]*_t61;
  const double _t186 = _hc1[33]*_t38;
  const double _t187 = _hc1[3]*_t97;
  const double _t188 = -_hc1[18]*_t129 - _hc1[31]*_t38*_t48 - _hc1[33]*_t44;
  const double _t190 = -_hc1[28]*_t119 - _hc1[31]*_t67;
  const double _t191 = -_hc1[31]*_t119 - _hc1[33]*_t67;
  const double _t192 = _hc1[16]*_t189 - _t119*_t190 + _t185*_t25 - _t191*_t67;
#endif

  const double f = my_piecewise3(_t8, 0, _t9*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = 0;
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t8, 0, _t10*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t8, 0, _t14*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t8, 0, _t24*n_s + _t9);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = 0;
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t8, 0, _t26*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = 0;
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t8, 0, _t29*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t8, 0, _t34*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = 0;
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t8, 0, _t10 + _t41*n_s);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t8, 0, _t14 + _t50*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t8, 0, 0.2e1*_t24 + _t70*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = 0;
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t8, 0, _t72*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = 0;
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t8, 0, _t75*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = 0;
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t8, 0, _t79*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t8, 0, _t88*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = 0;
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t8, 0, _t26 + _t95*n_s);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = 0;
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t8, 0, _t102*n_s + _t29);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t8, 0, _t111*n_s + _t34);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = 0;
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t8, 0, _t123*n_s + 0.2e1*_t41);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t8, 0, _t134*n_s + 0.2e1*_t50);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t8, 0, _t159*n_s + 0.3e1*_t70);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = 0;
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, _hc0[0]*_hc1[24]*_t160));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = 0;
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, _t11*_t161*_t162));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = 0;
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.4e1)*_hc0[0]*_hc1[31]*_t33*_t90 - _hc1[16]*_t73*_t77));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = 0;
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, -_hc1[18]*_t35*_t83*_t86 + _hc1[33]*_t81*_t92 + _t78*_t84));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.16e2)*_hc0[0]*_hc1[34]*_t86*_t97 + (0.15e2 / 0.16e2)*_hc0[0]*_hc1[9]*_t17/(sigma_ss * sigma_ss * sigma_ss) - 0.15e2 / 0.16e2*_hc0[0]*_t85/xc_powr(sigma_ss, 7, 2) - _t80*_t84));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = 0;
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t8, 0, _t72 + n_s*my_piecewise3(_t8, 0, _hc0[0]*(-_t164/xc_powr(n_s, 23, 3) - _t165*_t166 - 0.5e1*_t91) - _hc1[13]*_t15*_t163));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = 0;
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t8, 0, _t75 + n_s*my_piecewise3(_t8, 0, _hc0[0]*(-0.7e1 / 0.3e1*_t100 - _t165*_t169 - 0.2e1 / 0.3e1*_t168) - 0.1e1 / 0.12e2*_t15*_t74*_t90));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = 0;
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t8, 0, _t79 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.5e1 / 0.12e2)*_hc1[16]*_t31*_t92*lapl_s + (0.3e1 / 0.4e1)*_hc1[8]*_t31*_t38 - _t105*_t170 - 0.3e1 / 0.4e1*_t108 - _t168*_t171) + (0.1e1 / 0.24e2)*_hc1[8]*_t31*_t96 - _t104*_t76*_t92));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t8, 0, _t88 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.5e1 / 0.8e1)*_hc1[18]*_t86*_t97*lapl_s - _hc1[34]*_t163*_t33 + (0.1e1 / 0.2e1)*_hc1[9]*_t43*_t86 - 0.5e1 / 0.24e2*_t170*_t31*lapl_s - 0.1e1 / 0.2e1*_t22*_t82 - 0.5e1 / 0.8e1*_t46*_t82*lapl_s) - 0.1e1 / 0.48e2*_hc1[19]*_t15*_t31*_t97 - 0.1e1 / 0.16e2*_hc1[3]*_t42*_t82 + (0.1e1 / 0.16e2)*_t15*_t38*_t87));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = 0;
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t8, 0, 0.2e1*_t95 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.80e2 / 0.9e1)*_t115 - 0.10e2 / 0.3e1*_t118*_t17 - _t119*(-_hc1[13]*_t89 - _t164*_t90 - _t166*_t92) + _t160*_t173 + _t167*_t172 - _t67*(-_hc1[16]*_t89 - _hc1[28]*_t36*_t90 - _t174*_t92)) + _hc1[6]*_t112*_t92 + (0.1e1 / 0.36e2)*_hc1[6]*_t55*_t90 - _t114*_t94));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = 0;
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t8, 0, 0.2e1*_t102 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.20e2 / 0.9e1)*_hc1[16]*_t12*_t160*lapl_s + (0.14e2 / 0.9e1)*_hc1[18]*_t161 + (0.34e2 / 0.9e1)*_hc1[8]*_t12*_t71 - _t119*(-_hc1[16]*_t38*_t99 - _hc1[31]*_t98 - _t162*_t176) - _t121*_t129 - _t131 - _t67*(-_hc1[31]*_t12*_t176 - _hc1[33]*_t98 - _t120*_t99)) - _t101*_t114 + _t124*_t28*_t97 + _t125*_t28*_t92));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t8, 0, 0.2e1*_t111 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.10e2 / 0.9e1)*_hc1[18]*_t161*_t33*lapl_s + (0.7e1 / 0.9e1)*_hc1[19]*_t12*_t90 + (0.7e1 / 0.9e1)*_hc1[9]*_t33*_t73 - _t119*((0.5e1 / 0.12e2)*_hc1[16]*_t31*_t38*lapl_s - _hc1[18]*_t181 - _hc1[31]*_t109*_t33*_t97 - _hc1[33]*_t106 + (0.1e1 / 0.3e1)*_hc1[8]*_t21*_t31) - _t12*_t132*_t180 - 0.10e2 / 0.9e1*_t179*_t31*_t71 + (0.1e1 / 0.3e1)*_t21*_t31*_t68 - 0.7e1 / 0.9e1*_t31*_t62 - _t67*((0.5e1 / 0.12e2)*_hc1[18]*_t31*_t38*lapl_s - _hc1[19]*_t181 - _hc1[33]*_t171*_t97 - _hc1[34]*_t106 + (0.1e1 / 0.3e1)*_hc1[9]*_t21*_t31)) + _t103*_t177*_t71 + _t103*_t178*_t97 - _t110*_t114 - _t177*_t32*_t43 - _t178*_t32*_t38));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = 0;
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t8, 0, 0.3e1*_t123 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.80e2 / 0.9e1)*_t118*_t43*lapl_s - _t119*(-_t119*(-_hc1[24]*_t37 - _t145 - _t166*_t38) + _t144 - _t147 + _t172*_t97 + _t173*_t71 - _t184*_t67) + (0.56e2 / 0.9e1)*_t121*_t25*_t6 - _t141 - _t151 - 0.440e3 / 0.27e2*_t161*_t182 - _t183*_t90 + (0.80e2 / 0.9e1)*_t43*_t64 - _t67*(_hc1[16]*_t116*_t97 - _t119*_t184 + _t152 - _t154 + _t185*_t71 - _t67*(-_hc1[31]*_t37 - _t155 - _t186*_t20))) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t21*_t40 + (0.1e1 / 0.12e2)*_hc0[5]*_t17*_t40*_t53*_t54 - _hc1[2]*_t137*_t71 - _hc1[2]*_t138*_t97 - _t113*_t135*_t92 - _t122*_t139));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t8, 0, 0.3e1*_t134 + n_s*my_piecewise3(_t8, 0, _hc0[0]*(-0.140e3 / 0.27e2*_hc1[9]*_t92 - _t119*(_hc1[18]*_t126 + _hc1[8]*_t127*_t25 - _t119*(-_hc1[16]*_t129 - _hc1[31]*_t44 - _t169*_t38) + _t128*_t71*_t74 - _t129*_t149 - _t188*_t67) - 0.140e3 / 0.27e2*_t12*_t143 + (0.28e2 / 0.9e1)*_t12*_t25*_t68 - _t129*_t157 + (0.80e2 / 0.9e1)*_t130*_t43*lapl_s + (0.56e2 / 0.9e1)*_t132*_t25*_t6 - 0.220e3 / 0.27e2*_t28*_t90*lapl_s - _t67*(_hc1[18]*_t12*_t128*_t71 + _hc1[19]*_t126 - _t119*_t188 + _t127*_t153 - _t129*_t156 - _t67*(-_hc1[19]*_t129 - _hc1[34]*_t44 - _t186*_t48))) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t21*_t49 + (0.1e1 / 0.12e2)*_hc0[5]*_t17*_t49*_t53*_t54 - 0.1e1 / 0.72e2*_t12*_t135*_t187 - 0.7e1 / 0.27e2*_t13*_t15*_t73 - 0.1e1 / 0.18e2*_t13*_t55*_t71 - _t133*_t139));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t8, 0, 0.4e1*_t159 + n_s*my_piecewise3(_t8, 0, _hc0[0]*((0.6160e4 / 0.81e2)*_hc1[2]*_t175 - _t119*(-_t119*(_hc1[13]*_t189 - _t119*(-_hc1[24]*_t119 - _hc1[28]*_t67) + _t173*_t25 - _t190*_t67) - _t140*_t182 + (0.80e2 / 0.9e1)*_t146*_t43*lapl_s + (0.56e2 / 0.9e1)*_t149*_t25*_t6 - _t183*_t35 - _t192*_t67) + (0.40e2 / 0.3e1)*_t150*_t43*lapl_s + (0.28e2 / 0.3e1)*_t157*_t25*_t6 + (0.3640e4 / 0.81e2)*_t187*_t6 - 0.280e3 / 0.9e1*_t35*_t6*_t68 - 0.440e3 / 0.9e1*_t64*_t73*lapl_s - _t67*(-_hc1[9]*_t142*_t35 - _t119*_t192 - _t140*_t179 + (0.80e2 / 0.9e1)*_t149*_t43*lapl_s + (0.56e2 / 0.9e1)*_t156*_t25*_t6 - _t67*(_hc1[18]*_t189 + _hc1[19]*_t25*_t61 - _t119*_t191 - _t67*(-_hc1[33]*_t119 - _hc1[34]*_t67)))) + (0.1e1 / 0.216e3)*_hc0[14]*_hc1[0]*_t1*_t97/(M_PI * M_CBRTPI) + (0.40e2 / 0.81e2)*_hc1[0]*_t55*_t73 + (0.140e3 / 0.81e2)*_hc1[0]*_t96 + _t135*_t51*_t71 - 0.1e1 / 0.9e1*_t136*_t23 - 0.2e1 / 0.3e1*_t15*_t158*_t5 + _t15*_t180*_t69 - 0.4e1 / 0.9e1*_t23*_t43*_t55 - 0.56e2 / 0.27e2*_t25*_t57 + (0.1e1 / 0.6e1)*_t56*_t69));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_scanl_params *params = (const mgga_x_scanl_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double ta = tau[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / 0.4e1)*gaa;
  const double _t3 = (0.1e1 / 0.2e1)*la;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, _t3, 0, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[3];
  const double dF_dla = _hc0[2];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
#endif
#if _KMAX >= 2
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, _t3, (0.1e1 / 0.2e1)*ta, _hc1);
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc1[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dla = (0.1e1 / 0.2e1)*_hc0[12];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[10];
  const double d2F_dgaa_dla = (0.1e1 / 0.4e1)*_hc0[9];
  const double d2F_dla2 = (0.1e1 / 0.2e1)*_hc0[7];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc1[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc1[33];
  const double d3F_dna2_dla = (0.1e1 / 0.4e1)*_hc1[32];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dla = (0.1e1 / 0.8e1)*_hc0[29];
  const double d3F_dna_dla2 = (0.1e1 / 0.4e1)*_hc0[27];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[24];
  const double d3F_dgaa2_dla = (0.1e1 / 0.16e2)*_hc0[23];
  const double d3F_dgaa_dla2 = (0.1e1 / 0.8e1)*_hc0[21];
  const double d3F_dla3 = (0.1e1 / 0.4e1)*_hc0[18];
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
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc1[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc1[68];
  const double d4F_dna3_dla = (0.1e1 / 0.8e1)*_hc1[67];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc1[65];
  const double d4F_dna2_dgaa_dla = (0.1e1 / 0.16e2)*_hc1[64];
  const double d4F_dna2_dla2 = (0.1e1 / 0.8e1)*_hc1[62];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dla = (0.1e1 / 0.32e2)*_hc0[58];
  const double d4F_dna_dgaa_dla2 = (0.1e1 / 0.16e2)*_hc0[56];
  const double d4F_dna_dla3 = (0.1e1 / 0.8e1)*_hc0[53];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[49];
  const double d4F_dgaa3_dla = (0.1e1 / 0.64e2)*_hc0[48];
  const double d4F_dgaa2_dla2 = (0.1e1 / 0.32e2)*_hc0[46];
  const double d4F_dgaa_dla3 = (0.1e1 / 0.16e2)*_hc0[43];
  const double d4F_dla4 = (0.1e1 / 0.8e1)*_hc0[39];
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
  const double gbb = sigma[2];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;
  const double ta = tau[0];
  const double tb = tau[1];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, lb, 0, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc0[3];
  const double dF_dgbb = _hc1[3];
  const double dF_dla = _hc0[2];
  const double dF_dlb = _hc1[2];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 1] += dF_dlb;
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
  const double d2F_dna_dla = _hc0[12];
  const double d2F_dnb_dlb = _hc1[12];
  const double d2F_dgaa2 = _hc0[10];
  const double d2F_dgbb2 = _hc1[10];
  const double d2F_dgaa_dla = _hc0[9];
  const double d2F_dgbb_dlb = _hc1[9];
  const double d2F_dla2 = _hc0[7];
  const double d2F_dlb2 = _hc1[7];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += d2F_dnb_dlb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 5] += d2F_dgbb_dlb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 2] += d2F_dlb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc2[34];
  const double d3F_dnb3 = _hc3[34];
  const double d3F_dna2_dgaa = _hc2[33];
  const double d3F_dnb2_dgbb = _hc3[33];
  const double d3F_dna2_dla = _hc2[32];
  const double d3F_dnb2_dlb = _hc3[32];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dla = _hc0[29];
  const double d3F_dnb_dgbb_dlb = _hc1[29];
  const double d3F_dna_dla2 = _hc0[27];
  const double d3F_dnb_dlb2 = _hc1[27];
  const double d3F_dgaa3 = _hc0[24];
  const double d3F_dgbb3 = _hc1[24];
  const double d3F_dgaa2_dla = _hc0[23];
  const double d3F_dgbb2_dlb = _hc1[23];
  const double d3F_dgaa_dla2 = _hc0[21];
  const double d3F_dgbb_dlb2 = _hc1[21];
  const double d3F_dla3 = _hc0[18];
  const double d3F_dlb3 = _hc1[18];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += d3F_dnb2_dlb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 11] += d3F_dnb_dgbb_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += d3F_dnb_dlb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 11] += d3F_dgbb2_dlb;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 8] += d3F_dgbb_dlb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 3] += d3F_dlb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc2[69];
  const double d4F_dnb4 = _hc3[69];
  const double d4F_dna3_dgaa = _hc2[68];
  const double d4F_dnb3_dgbb = _hc3[68];
  const double d4F_dna3_dla = _hc2[67];
  const double d4F_dnb3_dlb = _hc3[67];
  const double d4F_dna2_dgaa2 = _hc2[65];
  const double d4F_dnb2_dgbb2 = _hc3[65];
  const double d4F_dna2_dgaa_dla = _hc2[64];
  const double d4F_dnb2_dgbb_dlb = _hc3[64];
  const double d4F_dna2_dla2 = _hc2[62];
  const double d4F_dnb2_dlb2 = _hc3[62];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dla = _hc0[58];
  const double d4F_dnb_dgbb2_dlb = _hc1[58];
  const double d4F_dna_dgaa_dla2 = _hc0[56];
  const double d4F_dnb_dgbb_dlb2 = _hc1[56];
  const double d4F_dna_dla3 = _hc0[53];
  const double d4F_dnb_dlb3 = _hc1[53];
  const double d4F_dgaa4 = _hc0[49];
  const double d4F_dgbb4 = _hc1[49];
  const double d4F_dgaa3_dla = _hc0[48];
  const double d4F_dgbb3_dlb = _hc1[48];
  const double d4F_dgaa2_dla2 = _hc0[46];
  const double d4F_dgbb2_dlb2 = _hc1[46];
  const double d4F_dgaa_dla3 = _hc0[43];
  const double d4F_dgbb_dlb3 = _hc1[43];
  const double d4F_dla4 = _hc0[39];
  const double d4F_dlb4 = _hc1[39];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += d4F_dnb3_dlb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 17] += d4F_dnb2_dgbb_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += d4F_dnb2_dlb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 23] += d4F_dnb_dgbb2_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 17] += d4F_dnb_dgbb_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += d4F_dnb_dlb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 19] += d4F_dgbb3_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 17] += d4F_dgbb2_dlb2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 11] += d4F_dgbb_dlb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 4] += d4F_dlb4;
#endif
#endif
}
#endif