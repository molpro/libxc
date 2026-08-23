/*
  Generated from python/gga_exc/gga_x_pw91.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_pw91
*/

#ifndef _GGA_X_PW91_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_PW91_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_PW91_HELPER_BODIES
#include "gga_x_pw91.c"
#undef _GGA_X_PW91_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_PW91_HELPER_BODIES
#include "gga_x_pw91.c"
#undef _GGA_X_PW91_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_PW91_HELPER_BODIES
#include "gga_x_pw91.c"
#undef _GGA_X_PW91_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_PW91_HELPER_BODIES
#include "gga_x_pw91.c"
#undef _GGA_X_PW91_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_PW91_HELPER_BODIES
#include "gga_x_pw91.c"
#undef _GGA_X_PW91_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_pw91.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_PW91_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pw91_den_k, _KMAX)(const xc_func_type *p, double s, double *out) {
  const gga_x_pw91_params *params = (const gga_x_pw91_params *)(p->params);

  const double _t1 = pow(s, params->expo);
  const double _t2 = _t1*params->f;
  const double _t3 = params->b*s;
  const double _t4 = params->a*xc_asinh(_t3);
#if _KMAX >= 1
  const double _t5 = _t2*params->expo;
  const double _t6 = (s * s);
  const double _t7 = _t6*((params->b) * (params->b)) + 0.1e1;
  const double _t8 = xc_powr(_t7, -1, 2);
#endif
#if _KMAX >= 2
  const double _t9 = (0.1e1 / _t6);
  const double _t10 = ((params->expo) * (params->expo));
  const double _t11 = ((params->b) * (params->b) * (params->b))/xc_powr(_t7, 3, 2);
#endif
#if _KMAX >= 3
  const double _t12 = (s * s * s);
  const double _t13 = (0.1e1 / _t12);
  const double _t14 = _t2*((params->expo) * (params->expo) * (params->expo));
  const double _t15 = 0.4e1*_t11*params->a;
  const double _t16 = xc_powr(_t7, -5, 2);
  const double _t17 = xc_powi((params->b), 5);
#endif
#if _KMAX >= 4
  const double _t18 = (s * s * s * s);
  const double _t19 = (0.1e1 / _t18);
  const double _t20 = 0.6e1*_t19;
#endif

  const double f = _t2 + _t4*s + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = _t3*_t8*params->a + _t4 + _t5/s;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = _t1*_t10*_t9*params->f - _t11*_t6*params->a - _t5*_t9 + 0.2e1*_t8*params->a*params->b;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = -0.3e1*_t10*_t13*_t2 + 0.3e1*_t12*_t16*_t17*params->a + _t13*_t14 + 0.2e1*_t13*_t5 - _t15*s;
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = 0.11e2*_t1*_t10*_t19*params->f + _t1*_t19*((params->expo) * (params->expo) * (params->expo) * (params->expo))*params->f - _t14*_t20 - _t15 + 0.21e2*_t16*_t17*_t6*params->a - 0.15e2*_t18*params->a*xc_powi((params->b), 7)/xc_powr(_t7, 7, 2) - _t20*_t5;
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pw91_fnum_k, _KMAX)(const xc_func_type *p, double s, double *out) {
  const gga_x_pw91_params *params = (const gga_x_pw91_params *)(p->params);

  const double _t1 = params->b*s;
  const double _t2 = params->a*xc_asinh(_t1);
  const double _t3 = (s * s);
  const double _t4 = _t3*params->alpha;
  const double _t5 = exp(-_t4);
  const double _t6 = _t5*params->d;
  const double _t7 = _t6 + params->c;
#if _KMAX >= 1
  const double _t8 = (s * s * s);
  const double _t9 = 0.2e1*_t6;
  const double _t10 = _t3*((params->b) * (params->b)) + 0.1e1;
  const double _t11 = params->a/xc_powr(_t10, 1, 2);
#endif
#if _KMAX >= 2
  const double _t12 = (s * s * s * s);
  const double _t13 = ((params->alpha) * (params->alpha));
  const double _t14 = ((params->b) * (params->b) * (params->b))/xc_powr(_t10, 3, 2);
#endif
#if _KMAX >= 3
  const double _t15 = 0.24e2*_t6*params->alpha;
  const double _t16 = _t6*((params->alpha) * (params->alpha) * (params->alpha));
  const double _t17 = 0.4e1*_t14*params->a;
  const double _t18 = xc_powi((params->b), 5);
  const double _t19 = xc_powr(_t10, -5, 2);
#endif

  const double f = _t2*s + _t3*_t7 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_ds = _t1*_t11 + _t2 + 0.2e1*_t7*s - _t8*_t9*params->alpha;
  out[1] = df_ds;
#endif
#if _KMAX >= 2
  const double d2f_ds2 = 0.2e1*_t11*params->b + 0.4e1*_t12*_t13*_t6 - _t14*_t3*params->a - 0.10e2*_t4*_t6 + _t9 + 0.2e1*params->c;
  out[2] = d2f_ds2;
#endif
#if _KMAX >= 3
  const double d3f_ds3 = 0.36e2*_t13*_t5*_t8*params->d - _t15*s - 0.8e1*_t16*xc_powi(s, 5) - _t17*s + 0.3e1*_t18*_t19*_t8*params->a;
  out[3] = d3f_ds3;
#endif
#if _KMAX >= 4
  const double d4f_ds4 = -0.112e3*_t12*_t16 + 0.156e3*_t13*_t3*_t5*params->d - _t15 - _t17 + 0.21e2*_t18*_t19*_t3*params->a + 0.16e2*_t5*((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha))*params->d*xc_powi(s, 6) - 0.15e2*_t12*params->a*xc_powi((params->b), 7)/xc_powr(_t10, 7, 2);
  out[4] = d4f_ds4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pw91_f_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_powr(0.6e1, 2, 3);
  const double _t2 = (0.1e1 / 0.12e2)*_t1/(M_CBRTPI * M_CBRTPI);
  const double _t3 = _t2*x;
#if _KMAX >= 2
  const double _t7 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t8 = (0.1e1 / 0.24e2)*_t7;
  const double _t9 = (0.1e1 / 0.12e2)*_t7;
#endif
#if _KMAX >= 3
  const double _t14 = (0.1e1 / (M_PI * M_PI));
  const double _t15 = (0.1e1 / 0.16e2)*_t14;
#endif
#if _KMAX >= 4
  const double _t19 = _t1/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t20 = (0.1e1 / 0.576e3)*_t19;
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pw91_den_k, _KMAX)(p, _t3, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pw91_fnum_k, _KMAX)(p, _t3, _hc1);
  const double _t4 = (0.1e1 / (_hc0[0]));
#if _KMAX >= 1
  const double _t5 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t6 = _hc0[1]*_t5;
#endif
#if _KMAX >= 2
  const double _t10 = _hc0[2]*_t5;
  const double _t11 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t12 = ((_hc0[1]) * (_hc0[1]));
  const double _t13 = _t11*_t12;
#endif
#if _KMAX >= 3
  const double _t16 = _hc0[3]*_t5;
  const double _t17 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t18 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t17;
#endif
#if _KMAX >= 4
  const double _t21 = _hc1[2]*_t19;
  const double _t22 = _hc1[1]*_t19;
  const double _t23 = _hc0[1]*_t11;
  const double _t24 = (0.1e1 / 0.24e2)*_t22;
  const double _t25 = _hc1[0]*_t19;
#endif

  const double f = _hc1[0]*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -_hc1[0]*_t2*_t6 + _hc1[1]*_t2*_t4;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -_hc1[0]*_t10*_t8 + _hc1[0]*_t13*_t9 - _hc1[1]*_t6*_t9 + _hc1[2]*_t4*_t8;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = (0.1e1 / 0.8e1)*_hc0[1]*_hc0[2]*_hc1[0]*_t11*_t14 - 0.1e1 / 0.48e2*_hc1[0]*_t14*_t16 - 0.1e1 / 0.8e1*_hc1[0]*_t14*_t18 - _hc1[1]*_t10*_t15 + (0.1e1 / 0.8e1)*_hc1[1]*_t11*_t12*_t14 - _hc1[2]*_t15*_t6 + (0.1e1 / 0.48e2)*_hc1[3]*_t14*_t4;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = (0.1e1 / 0.96e2)*((_hc0[2]) * (_hc0[2]))*_t11*_t25 - 0.1e1 / 0.16e2*_hc0[2]*_t12*_t17*_t25 + _hc0[2]*_t23*_t24 + (0.1e1 / 0.72e2)*_hc0[3]*_t23*_t25 - _hc0[4]*_hc1[0]*_t20*_t5 - 0.1e1 / 0.144e3*_hc1[3]*_t19*_t6 + _hc1[4]*_t20*_t4 - 0.1e1 / 0.96e2*_t10*_t21 + (0.1e1 / 0.48e2)*_t13*_t21 - 0.1e1 / 0.144e3*_t16*_t22 - _t18*_t24 + (0.1e1 / 0.24e2)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t25/xc_powi((_hc0[0]), 5);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {
  const gga_x_pw91_params *params = (const gga_x_pw91_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = xc_powr(n_s, -4, 3);
  const double _t5 = xc_powr(sigma_ss, 1, 2);
  const double _t6 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t8 = (0.1e1 / _t5);
  const double _t12 = xc_powr(n_s, -7, 3);
#endif
#if _KMAX >= 2
  const double _t17 = xc_powr(sigma_ss, 3, 2);
  const double _t18 = (0.1e1 / _t17);
  const double _t19 = xc_powr(n_s, -8, 3);
  const double _t20 = (0.1e1 / sigma_ss);
  const double _t22 = xc_powr(n_s, -11, 3);
  const double _t28 = xc_powr(n_s, -14, 3);
  const double _t30 = xc_powr(n_s, -10, 3);
#endif
#if _KMAX >= 3
  const double _t37 = xc_powr(sigma_ss, -5, 2);
  const double _t38 = (0.3e1 / 0.8e1)*_t37;
  const double _t39 = (sigma_ss * sigma_ss);
  const double _t40 = (0.1e1 / _t39);
  const double _t42 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t43 = _t18*_t42;
  const double _t45 = xc_powi(n_s, -5);
  const double _t50 = xc_powi(n_s, -6);
  const double _t51 = (0.8e1 / 0.9e1)*_t50;
  const double _t53 = (0.1e1 / 0.72e2)*_t8;
  const double _t56 = xc_powr(n_s, -17, 3);
  const double _t59 = xc_powr(n_s, -13, 3);
  const double _t61 = xc_powi(n_s, -7);
  const double _t67 = (0.1e1 / 0.9e1)*_t45;
#endif
#if _KMAX >= 4
  const double _t69 = xc_powr(n_s, -16, 3);
  const double _t70 = xc_powr(n_s, -19, 3);
  const double _t72 = (0.1e1 / 0.6e1)*_t20;
  const double _t74 = xc_powr(n_s, -22, 3);
  const double _t75 = (0.4e1 / 0.9e1)*_t74;
  const double _t76 = (0.19e2 / 0.9e1)*_t50;
  const double _t78 = xc_powr(n_s, -25, 3);
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t6)) XC_CAT(lda_x_spin_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t3/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t6)) XC_CAT(pw91_f_k, _KMAX)(p, _t4*_t5, _hc1);
  const double _t7 = my_piecewise3(_t6, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t9 = _hc0[0]*_hc1[1];
  const double _t10 = _t4*_t9;
  const double _t11 = my_piecewise3(_t6, 0, (0.1e1 / 0.2e1)*_t10*_t8);
  const double _t13 = _t12*_t9;
  const double _t14 = _hc0[2]*_t3;
  const double _t15 = _hc1[0]*_t14;
  const double _t16 = my_piecewise3(_t6, 0, -0.4e1 / 0.3e1*_t13*_t5 - 0.1e1 / 0.6e1*_t15*_t4);
#endif
#if _KMAX >= 2
  const double _t21 = my_piecewise3(_t6, 0, (0.1e1 / 0.4e1)*_hc0[0]*_hc1[2]*_t19*_t20 - 0.1e1 / 0.4e1*_t10*_t18);
  const double _t23 = _hc0[0]*_hc1[2];
  const double _t24 = _t22*_t23;
  const double _t25 = _hc1[1]*_t14;
  const double _t26 = _t19*_t25;
  const double _t27 = my_piecewise3(_t6, 0, -0.2e1 / 0.3e1*_t13*_t8 - 0.2e1 / 0.3e1*_t24 - 0.1e1 / 0.12e2*_t26*_t8);
  const double _t29 = _t23*_t28;
  const double _t31 = _t30*_t9;
  const double _t32 = (0.2e1 / 0.9e1)*_hc1[0];
  const double _t33 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t34 = xc_powr(0.6e1, 2, 3)*_hc0[5]/(M_CBRTPI * M_CBRTPI);
  const double _t35 = _t22*_t25;
  const double _t36 = my_piecewise3(_t6, 0, _t12*_t14*_t32 + _t19*_t33*_t34 + (0.16e2 / 0.9e1)*_t29*sigma_ss + (0.28e2 / 0.9e1)*_t31*_t5 + (0.4e1 / 0.9e1)*_t35*_t5);
#endif
#if _KMAX >= 3
  const double _t41 = _hc0[0]*_hc1[3];
  const double _t44 = my_piecewise3(_t6, 0, _t10*_t38 - 0.3e1 / 0.8e1*_t19*_t23*_t40 + (0.1e1 / 0.8e1)*_t41*_t43);
  const double _t46 = _t41*_t8;
  const double _t47 = _hc1[2]*_t14;
  const double _t48 = my_piecewise3(_t6, 0, (0.1e1 / 0.3e1)*_hc0[0]*_hc1[1]*_t12*_t18 + (0.1e1 / 0.24e2)*_hc0[2]*_hc1[1]*_t1*_t18*_t19*_t2 - 0.1e1 / 0.3e1*_t20*_t24 - 0.1e1 / 0.24e2*_t20*_t42*_t47 - 0.1e1 / 0.3e1*_t45*_t46);
  const double _t49 = _t41*_t5;
  const double _t52 = _t45*_t47;
  const double _t54 = _hc1[1]*_t34;
  const double _t55 = my_piecewise3(_t6, 0, (0.10e2 / 0.3e1)*_t29 + (0.14e2 / 0.9e1)*_t31*_t8 + (0.1e1 / 0.3e1)*_t35*_t8 + _t42*_t53*_t54 + _t49*_t51 + (0.2e1 / 0.9e1)*_t52);
  const double _t57 = _t23*_t56;
  const double _t58 = _hc0[9]/M_PI;
  const double _t60 = _t59*_t9;
  const double _t62 = _t17*_t41;
  const double _t63 = _hc1[0]*_t34;
  const double _t64 = _t47*sigma_ss;
  const double _t65 = _t25*_t28;
  const double _t66 = _t5*_t54;
  const double _t68 = my_piecewise3(_t6, 0, -0.14e2 / 0.27e2*_t15*_t30 - 0.1e1 / 0.9e1*_t22*_t63 - _t33*_t42*_t58 - 0.280e3 / 0.27e2*_t5*_t60 - 0.22e2 / 0.9e1*_t5*_t65 - _t51*_t64 - 0.112e3 / 0.9e1*_t57*sigma_ss - 0.64e2 / 0.27e2*_t61*_t62 - _t66*_t67);
#endif
#if _KMAX >= 4
  const double _t71 = _hc0[0]*_hc1[4];
  const double _t73 = _hc1[3]*_t14;
  const double _t77 = _hc1[2]*_t34;
  const double _t79 = _hc1[1]*_t58;
#endif

  const double f = my_piecewise3(_t6, 0, _t7*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t6, 0, _t11*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t6, 0, _t16*n_s + _t7);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t6, 0, _t21*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t6, 0, _t11 + _t27*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t6, 0, 0.2e1*_t16 + _t36*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t6, 0, _t44*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t6, 0, _t21 + _t48*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t6, 0, 0.2e1*_t27 + _t55*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t6, 0, 0.3e1*_t36 + _t68*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t6, 0, n_s*my_piecewise3(_t6, 0, (0.15e2 / 0.16e2)*_hc0[0]*_hc1[2]*_t19/(sigma_ss * sigma_ss * sigma_ss) + (0.1e1 / 0.16e2)*_hc0[0]*_hc1[4]*_t40*_t69 - 0.15e2 / 0.16e2*_t10/xc_powr(sigma_ss, 7, 2) - _t38*_t41*_t42));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t6, 0, _t44 + n_s*my_piecewise3(_t6, 0, (0.1e1 / 0.2e1)*_hc0[0]*_hc1[2]*_t22*_t40 + (0.1e1 / 0.16e2)*_hc0[2]*_hc1[2]*_t1*_t2*_t40*_t42 - 0.1e1 / 0.2e1*_t13*_t37 - 0.1e1 / 0.48e2*_t18*_t69*_t73 - 0.1e1 / 0.16e2*_t26*_t37 - _t70*_t71*_t72));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t6, 0, 0.2e1*_t48 + n_s*my_piecewise3(_t6, 0, -0.7e1 / 0.9e1*_t18*_t31 - 0.1e1 / 0.6e1*_t18*_t35 + (0.7e1 / 0.9e1)*_t20*_t29 + (0.1e1 / 0.144e3)*_t20*_t69*_t77 - 0.1e1 / 0.144e3*_t43*_t54 + _t46*_t76 + _t52*_t72 + (0.1e1 / 0.9e1)*_t70*_t73*_t8 + _t71*_t75));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t6, 0, 0.3e1*_t55 + n_s*my_piecewise3(_t6, 0, -_t47*_t76 - 0.88e2 / 0.9e1*_t49*_t61 - _t5*_t73*_t75 - _t53*_t69*_t79 - _t54*_t67*_t8 - 0.476e3 / 0.27e2*_t57 - 0.140e3 / 0.27e2*_t60*_t8 - 0.40e2 / 0.27e2*_t65*_t8 - 0.1e1 / 0.18e2*_t70*_t77 - 0.32e2 / 0.27e2*_t71*_t78*sigma_ss));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t6, 0, 0.4e1*_t68 + n_s*my_piecewise3(_t6, 0, (0.1e1 / 0.216e3)*_hc0[14]*_hc1[0]*_t1*_t69/(M_PI * M_CBRTPI) + (0.140e3 / 0.81e2)*_t15*_t59 + (0.128e3 / 0.81e2)*_t17*_t73*_t78 + (0.6832e4 / 0.81e2)*_t23*sigma_ss/xc_powr(n_s, 20, 3) + (0.1120e4 / 0.81e2)*_t25*_t5*_t56 + (0.40e2 / 0.81e2)*_t28*_t63 + _t32*_t45*_t58 + (0.256e3 / 0.81e2)*_t39*_t71/xc_powr(n_s, 28, 3) + (0.3640e4 / 0.81e2)*_t5*_t69*_t9 + (0.4e1 / 0.27e2)*_t5*_t70*_t79 + (0.10e2 / 0.9e1)*_t50*_t66 + (0.32e2 / 0.3e1)*_t61*_t64 + (0.896e3 / 0.27e2)*_t62/xc_powi(n_s, 8) + (0.8e1 / 0.27e2)*_t74*_t77*sigma_ss));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_pw91_params *params = (const gga_x_pw91_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, (0.1e1 / 0.2e1)*na, (0.1e1 / 0.4e1)*gaa, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[2];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[5];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[4];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[9];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[8];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[7];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[6];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[14];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[13];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[12];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[11];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[10];
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

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[2];
  const double dF_dnb = _hc1[2];
  const double dF_dgaa = _hc0[1];
  const double dF_dgbb = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = _hc0[5];
  const double d2F_dnb2 = _hc1[5];
  const double d2F_dna_dgaa = _hc0[4];
  const double d2F_dnb_dgbb = _hc1[4];
  const double d2F_dgaa2 = _hc0[3];
  const double d2F_dgbb2 = _hc1[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc0[9];
  const double d3F_dnb3 = _hc1[9];
  const double d3F_dna2_dgaa = _hc0[8];
  const double d3F_dnb2_dgbb = _hc1[8];
  const double d3F_dna_dgaa2 = _hc0[7];
  const double d3F_dnb_dgbb2 = _hc1[7];
  const double d3F_dgaa3 = _hc0[6];
  const double d3F_dgbb3 = _hc1[6];
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
  const double d4F_dna4 = _hc0[14];
  const double d4F_dnb4 = _hc1[14];
  const double d4F_dna3_dgaa = _hc0[13];
  const double d4F_dnb3_dgbb = _hc1[13];
  const double d4F_dna2_dgaa2 = _hc0[12];
  const double d4F_dnb2_dgbb2 = _hc1[12];
  const double d4F_dna_dgaa3 = _hc0[11];
  const double d4F_dnb_dgbb3 = _hc1[11];
  const double d4F_dgaa4 = _hc0[10];
  const double d4F_dgbb4 = _hc1[10];
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