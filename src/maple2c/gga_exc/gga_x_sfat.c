/*
  Generated from python/gga_exc/gga_x_sfat.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_sfat
*/

#ifndef _GGA_X_SFAT_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_SFAT_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_SFAT_HELPER_BODIES
#include "gga_x_sfat.c"
#undef _GGA_X_SFAT_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_SFAT_HELPER_BODIES
#include "gga_x_sfat.c"
#undef _GGA_X_SFAT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_SFAT_HELPER_BODIES
#include "gga_x_sfat.c"
#undef _GGA_X_SFAT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_SFAT_HELPER_BODIES
#include "gga_x_sfat.c"
#undef _GGA_X_SFAT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_SFAT_HELPER_BODIES
#include "gga_x_sfat.c"
#undef _GGA_X_SFAT_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_sfat.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_SFAT_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(b88_f_m1_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_asinh(x);
  const double _t2 = 0.0252*_t1;
  const double _t3 = _t2*x + 0.1e1;
  const double _t4 = xc_powr(0.2e1, 2, 3)*M_CBRTPI/M_CBRT3;
  const double _t5 = _t4/_t3;
  const double _t6 = (x * x);
  const double _t7 = 0.0027999999999999995*_t6;
#if _KMAX >= 1
  const double _t8 = 0.0055999999999999991*_t5;
  const double _t9 = _t6 + 0.1e1;
  const double _t10 = xc_powr(_t9, -1, 2);
  const double _t11 = _t10*x;
  const double _t12 = -0.0252*_t11 - _t2;
  const double _t13 = _t4/(_t3 * _t3);
  const double _t14 = _t12*_t13;
#endif
#if _KMAX >= 2
  const double _t15 = 0.0504*_t10;
  const double _t16 = xc_powr(_t9, -3, 2);
  const double _t17 = _t16*_t6;
  const double _t18 = -_t15 + 0.0252*_t17;
  const double _t19 = _t13*_t18;
  const double _t20 = -0.0504*_t1 - _t15*x;
  const double _t21 = _t4/(_t3 * _t3 * _t3);
  const double _t22 = _t12*_t21;
  const double _t23 = _t20*_t22;
#endif
#if _KMAX >= 3
  const double _t24 = 0.016799999999999995*x;
  const double _t25 = xc_powr(_t9, -5, 2);
  const double _t26 = _t25*(x * x * x);
  const double _t27 = 0.1008*_t16*x - 0.075600000000000001*_t26;
  const double _t28 = _t13*_t7;
  const double _t29 = 0.0055999999999999991*_t6;
  const double _t30 = _t18*_t21;
  const double _t31 = _t20*_t30;
  const double _t32 = 0.1008*_t10;
  const double _t33 = 0.0504*_t17 - _t32;
  const double _t34 = _t22*_t7;
  const double _t35 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t36 = -0.075600000000000001*_t1 - 0.075600000000000001*_t11;
  const double _t37 = _t35*_t36*_t4;
  const double _t38 = _t12*_t37;
  const double _t39 = _t20*_t7;
#endif
#if _KMAX >= 4
  const double _t40 = 0.022399999999999996*x;
  const double _t41 = 0.0083999999999999977*_t6;
  const double _t42 = _t20*_t41;
  const double _t43 = _t12*_t39*_t4;
#endif

  const double f = _t5*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t14*_t7 + _t8*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.011199999999999998*_t14*x + _t19*_t7 + _t23*_t7 + _t8;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.016799999999999995*_t14 + _t19*_t24 + _t23*_t24 + _t27*_t28 + _t29*_t31 + _t33*_t34 + _t38*_t39;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t13*_t27*_t40 + _t18*_t37*_t42 + 0.033599999999999991*_t19 + _t20*_t38*_t40 + _t21*_t27*_t42 + _t22*_t33*_t40 + 0.033599999999999991*_t23 + _t28*(0.1008*_t16 - 0.5292*_t25*_t6 + 0.378*(x * x * x * x)/xc_powr(_t9, 7, 2)) + _t29*_t33*_t38 + _t30*_t33*_t41 + 0.044799999999999993*_t31*x + _t34*(0.2016*_t16*x - 0.1512*_t26) + _t35*_t43*(-0.1512*_t10 + 0.075600000000000001*_t17) + _t36*_t43*(-0.1008*_t1 - _t32*x)/xc_powi(_t3, 5);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(b88_f_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(b88_f_m1_k, _KMAX)(p, x, _hc0);

  const double f = _hc0[0] + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _hc0[1];
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _hc0[2];
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _hc0[3];
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _hc0[4];
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_yuk_aux1_k, _KMAX)(const xc_func_type *p, double a, double *out) {

#if _KMAX >= 1
  const double _t1 = (a * a);
  const double _t2 = _t1 + 0.1e1;
#endif
#if _KMAX >= 2
  const double _t3 = (0.1e1 / (_t2 * _t2));
#endif
#if _KMAX >= 3
  const double _t4 = (0.1e1 / (_t2 * _t2 * _t2));
#endif

  const double f = atan2(0.1e1, a);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -0.1e1/_t2;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.2e1*_t3*a;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -0.8e1*_t1*_t4 + 0.2e1*_t3;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.24e2*_t4*a + 0.48e2*(a * a * a)/(_t2 * _t2 * _t2 * _t2);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_yuk_aux2_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = (0.1e1 / (a * a));
#if _KMAX >= 1
  const double _t2 = _t1 + 0.1e1;
  const double _t3 = (0.1e1 / _t2);
#endif
#if _KMAX >= 2
  const double _t4 = xc_powi(a, -6);
  const double _t5 = (0.1e1 / (_t2 * _t2));
#endif
#if _KMAX >= 3
  const double _t6 = (0.1e1 / (_t2 * _t2 * _t2));
#endif

  const double f = xc_log1p(_t1);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -0.2e1*_t3/(a * a * a);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.6e1*_t3/(a * a * a * a) - 0.4e1*_t4*_t5;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -0.24e2*_t3/xc_powi(a, 5) + 0.36e2*_t5/xc_powi(a, 7) - 0.16e2*_t6/xc_powi(a, 9);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.120e3*_t3*_t4 - 0.300e3*_t5/xc_powi(a, 8) + 0.288e3*_t6/xc_powi(a, 10) - 0.96e2/((_t2 * _t2 * _t2 * _t2)*xc_powi(a, 12));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_yuk_aux3_k, _KMAX)(const xc_func_type *p, double a, double *out) {


  const double f = (a * a) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = 0.2e1*a;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.2e1;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_yukawa0_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_yuk_aux3_k, _KMAX)(p, a, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_yuk_aux2_k, _KMAX)(p, a, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_yuk_aux1_k, _KMAX)(p, a, _hc2);
  const double _t1 = _hc0[0] + 0.2e1;
  const double _t2 = _hc1[0]*_t1;
  const double _t3 = 0.1e1 - _t2;
  const double _t4 = (0.1e1 / 0.4e1)*a;
  const double _t5 = (0.8e1 / 0.3e1)*a;
#if _KMAX >= 1
  const double _t6 = _hc0[1]*_hc1[0];
  const double _t7 = _hc1[1]*_t1;
  const double _t8 = -_t6 - _t7;
#endif
#if _KMAX >= 2
  const double _t9 = _hc0[2]*_hc1[0];
  const double _t10 = _hc0[1]*_hc1[1];
  const double _t11 = _hc1[2]*_t1;
  const double _t12 = -0.2e1*_t10 - _t11 - _t9;
#endif
#if _KMAX >= 3
  const double _t13 = 0.3e1*_hc0[1]*_hc1[2] + 0.3e1*_hc0[2]*_hc1[1] + _hc1[3]*_t1;
  const double _t14 = -_t13;
#endif

  const double f = -_t5*(_hc2[0] + _t3*_t4) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -0.8e1 / 0.3e1*_hc2[0] - 0.2e1 / 0.3e1*_t3*a - _t5*(_hc2[1] - 0.1e1 / 0.4e1*_t2 + _t4*_t8 + 0.1e1 / 0.4e1);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = (0.4e1 / 0.3e1)*_hc1[0]*_t1 - 0.16e2 / 0.3e1*_hc2[1] - _t5*(_hc2[2] + (0.1e1 / 0.4e1)*_t12*a - 0.1e1 / 0.2e1*_t6 - 0.1e1 / 0.2e1*_t7) - 0.4e1 / 0.3e1*_t8*a - 0.4e1 / 0.3e1;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.4e1*_hc0[1]*_hc1[0] + 0.4e1*_hc1[1]*_t1 - 0.8e1*_hc2[2] - 0.2e1*_t12*a - _t5*(_hc2[3] - 0.3e1 / 0.2e1*_t10 - 0.3e1 / 0.4e1*_t11 + (0.1e1 / 0.4e1)*_t14*a - 0.3e1 / 0.4e1*_t9);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.32e2 / 0.3e1*_hc2[3] + 0.16e2*_t10 + 0.8e1*_t11 - _t14*_t5 - _t5*(_hc2[4] - _t13 + (0.1e1 / 0.4e1)*a*(-0.4e1*_hc0[1]*_hc1[3] - 0.6e1*_hc0[2]*_hc1[2] - _hc1[4]*_t1)) + 0.8e1*_t9;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_yukawa_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = a > 1.9199999999999999;
  const double _t2 = a >= 1.9199999999999999;
  const double _t3 = my_piecewise3(_t1, a, 1.9199999999999999);
  const double _t4 = xc_powi(_t3, -34);
  const double _t5 = xc_powi(_t3, -32);
  const double _t6 = xc_powi(_t3, -30);
  const double _t7 = xc_powi(_t3, -28);
  const double _t8 = xc_powi(_t3, -26);
  const double _t9 = xc_powi(_t3, -24);
  const double _t10 = xc_powi(_t3, -22);
  const double _t11 = xc_powi(_t3, -20);
  const double _t12 = xc_powi(_t3, -18);
  const double _t13 = xc_powi(_t3, -16);
  const double _t14 = xc_powi(_t3, -14);
  const double _t15 = xc_powi(_t3, -12);
  const double _t16 = xc_powi(_t3, -10);
  const double _t17 = xc_powi(_t3, -8);
  const double _t18 = xc_powi(_t3, -6);
  const double _t19 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
#if _KMAX >= 1
  const double _t20 = my_piecewise3(_t1, 0.1e1, 0);
  const double _t21 = xc_powi(_t3, -35);
  const double _t22 = xc_powi(_t3, -33);
  const double _t23 = xc_powi(_t3, -31);
  const double _t24 = xc_powi(_t3, -29);
  const double _t25 = xc_powi(_t3, -27);
  const double _t26 = xc_powi(_t3, -25);
  const double _t27 = xc_powi(_t3, -23);
  const double _t28 = xc_powi(_t3, -21);
  const double _t29 = xc_powi(_t3, -19);
  const double _t30 = xc_powi(_t3, -17);
  const double _t31 = xc_powi(_t3, -15);
  const double _t32 = xc_powi(_t3, -13);
  const double _t33 = xc_powi(_t3, -11);
  const double _t34 = xc_powi(_t3, -9);
  const double _t35 = xc_powi(_t3, -7);
  const double _t36 = xc_powi(_t3, -5);
  const double _t37 = my_piecewise3(_t1, 0, 0.1e1);
#endif
#if _KMAX >= 2
  const double _t38 = xc_powi(_t3, -36);
  const double _t39 = (_t20 * _t20);
  const double _t40 = (0.2e1 / 0.3e1)*_t39;
#endif
#if _KMAX >= 3
  const double _t41 = (_t20 * _t20 * _t20);
#endif
#if _KMAX >= 4
  const double _t42 = (_t20 * _t20 * _t20 * _t20);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(attenuation_yukawa0_k, _KMAX)(p, my_piecewise3(_t1, 1.9199999999999999, a), _hc0);

  const double f = my_piecewise3(_t2, (0.1e1 / 0.1794e4)*_t10 - 0.1e1 / 0.1386e4*_t11 + (0.1e1 / 0.1045e4)*_t12 - 0.1e1 / 0.765e3*_t13 + (0.1e1 / 0.540e3)*_t14 - 0.1e1 / 0.364e3*_t15 + (0.1e1 / 0.231e3)*_t16 - 0.1e1 / 0.135e3*_t17 + (0.1e1 / 0.70e2)*_t18 - 0.1e1 / 0.30e2*_t19 + (0.1e1 / 0.5985e4)*_t4 - 0.1e1 / 0.5049e4*_t5 + (0.1e1 / 0.4216e4)*_t6 - 0.1e1 / 0.3480e4*_t7 + (0.1e1 / 0.2835e4)*_t8 - 0.1e1 / 0.2275e4*_t9 + (0.1e1 / 0.9e1)/(_t3 * _t3), _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, -0.34e2 / 0.5985e4*_t20*_t21 + (0.32e2 / 0.5049e4)*_t20*_t22 - 0.15e2 / 0.2108e4*_t20*_t23 + (0.7e1 / 0.870e3)*_t20*_t24 - 0.26e2 / 0.2835e4*_t20*_t25 + (0.24e2 / 0.2275e4)*_t20*_t26 - 0.11e2 / 0.897e3*_t20*_t27 + (0.10e2 / 0.693e3)*_t20*_t28 - 0.18e2 / 0.1045e4*_t20*_t29 + (0.16e2 / 0.765e3)*_t20*_t30 - 0.7e1 / 0.270e3*_t20*_t31 + (0.3e1 / 0.91e2)*_t20*_t32 - 0.10e2 / 0.231e3*_t20*_t33 + (0.8e1 / 0.135e3)*_t20*_t34 - 0.3e1 / 0.35e2*_t20*_t35 + (0.2e1 / 0.15e2)*_t20*_t36 - 0.2e1 / 0.9e1*_t20/(_t3 * _t3 * _t3), _hc0[1]*_t37);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, -0.10e2 / 0.33e2*_t10*_t39 + (0.18e2 / 0.55e2)*_t11*_t39 - 0.16e2 / 0.45e2*_t12*_t39 + (0.7e1 / 0.18e2)*_t13*_t39 - 0.3e1 / 0.7e1*_t14*_t39 + (0.10e2 / 0.21e2)*_t15*_t39 - 0.8e1 / 0.15e2*_t16*_t39 + (0.3e1 / 0.5e1)*_t17*_t39 - _t18*_t40 + _t19*_t40 + (0.34e2 / 0.171e3)*_t38*_t39 - 0.32e2 / 0.153e3*_t39*_t4 + (0.15e2 / 0.68e2)*_t39*_t5 - 0.7e1 / 0.30e2*_t39*_t6 + (0.26e2 / 0.105e3)*_t39*_t7 - 0.24e2 / 0.91e2*_t39*_t8 + (0.11e2 / 0.39e2)*_t39*_t9, _hc0[2]*(_t37 * _t37));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, (0.64e2 / 0.9e1)*_t21*_t41 - 0.120e3 / 0.17e2*_t22*_t41 + 0.7e1*_t23*_t41 - 0.104e3 / 0.15e2*_t24*_t41 + (0.48e2 / 0.7e1)*_t25*_t41 - 0.88e2 / 0.13e2*_t26*_t41 + (0.20e2 / 0.3e1)*_t27*_t41 - 0.72e2 / 0.11e2*_t28*_t41 + (0.32e2 / 0.5e1)*_t29*_t41 - 0.56e2 / 0.9e1*_t30*_t41 + 0.6e1*_t31*_t41 - 0.40e2 / 0.7e1*_t32*_t41 + (0.16e2 / 0.3e1)*_t33*_t41 - 0.24e2 / 0.5e1*_t34*_t41 + 0.4e1*_t35*_t41 - 0.8e1 / 0.3e1*_t36*_t41 - 0.136e3 / 0.19e2*_t41/xc_powi(_t3, 37), _hc0[3]*(_t37 * _t37 * _t37));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, (0.1512e4 / 0.11e2)*_t10*_t42 - 0.608e3 / 0.5e1*_t11*_t42 + (0.952e3 / 0.9e1)*_t12*_t42 - 0.90e2*_t13*_t42 + (0.520e3 / 0.7e1)*_t14*_t42 - 0.176e3 / 0.3e1*_t15*_t42 + (0.216e3 / 0.5e1)*_t16*_t42 - 0.28e2*_t17*_t42 + (0.40e2 / 0.3e1)*_t18*_t42 - 0.2240e4 / 0.9e1*_t38*_t42 + (0.3960e4 / 0.17e2)*_t4*_t42 - 0.217e3*_t42*_t5 + (0.3016e4 / 0.15e2)*_t42*_t6 - 0.1296e4 / 0.7e1*_t42*_t7 + (0.2200e4 / 0.13e2)*_t42*_t8 - 0.460e3 / 0.3e1*_t42*_t9 + (0.5032e4 / 0.19e2)*_t42/xc_powi(_t3, 38), _hc0[4]*(_t37 * _t37 * _t37 * _t37));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ityh_enhancement_k, _KMAX)(const xc_func_type *p, double xs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(b88_f_k, _KMAX)(p, xs, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs = _hc0[1];
  out[1] = df_dxs;
#endif
#if _KMAX >= 2
  const double d2f_dxs2 = _hc0[2];
  out[2] = d2f_dxs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs3 = _hc0[3];
  out[3] = d3f_dxs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs4 = _hc0[4];
  out[4] = d4f_dxs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ityh_attenuation_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_yukawa_k, _KMAX)(p, a, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _hc0[1];
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _hc0[2];
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _hc0[3];
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = _hc0[4];
  out[4] = d4f_da4;
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

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(na, -4, 3);
  const double _t2 = M_CBRT2;
  const double _t3 = xc_powr(gaa, 1, 2);
  const double _t4 = _t2*_t3;
  const double _t5 = xc_powr(na, -1, 3);
  const double _t6 = xc_powr(M_PI, -1, 2);
  const double _t7 = xc_powr(0.3e1, 1, 2);
  const double _t11 = xc_powr(M_CBRT3, 1, 2);
  const double _t12 = xc_powr(M_CBRTPI, -1, 2);
  const double _t13 = _t11*_t12*p->cam_omega;
  const double _t17 = xc_powr(0.6e1, 1, 3);
  const double _t18 = (0.1e1 / (M_CBRTPI));
  const double _t19 = _t17*_t18;
  const double _t20 = (0.1e1 / 0.2e1)*_t19;
  const double _t21 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ityh_enhancement_k, _KMAX)(p, _t1*_t4, _hc0);
  const double _t8 = (0.1e1 / (_hc0[0]));
  const double _t9 = xc_powr(_t8, -1, 2);
  const double _t10 = _t7*_t9;
  const double _t14 = _t10*_t13;
  const double _t15 = _t14*_t6;
  const double _t16 = (0.1e1 / 0.6e1)*_t15;
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t21)) XC_CAT(ityh_attenuation_k, _KMAX)(p, _t16*_t5, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_spin_z0_k, _KMAX)(p, _t20*_t5, _hc2);
  const double _t22 = _hc0[0]*_hc2[0];
  const double _t23 = 0.2e1*my_piecewise3(_t21, 0, _hc1[0]*_t22);
  const double zk = _t23;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t26 = xc_powr(na, -7, 3);
  const double _t33 = xc_powr(na, -8, 3);
  const double _t39 = 0.2e1*na;
  const double _t40 = (0.1e1 / _t3);
  const double _t45 = xc_powr(na, -5, 3);
  const double _t49 = _t2*_t40;
  const double _t27 = _hc0[1]*_t26;
  const double _t28 = (0.4e1 / 0.3e1)*_t27;
  const double _t32 = (0.1e1 / 0.18e2)*_t15;
  const double _t34 = _t15*_t8;
  const double _t35 = _hc0[1]*_t34;
  const double _t36 = _t35*_t4;
  const double _t37 = -_t1*_t32 - 0.1e1 / 0.9e1*_t33*_t36;
  const double _t43 = _hc0[1]*_t1;
  const double _t44 = (0.1e1 / 0.2e1)*_t43;
  const double _t50 = _hc0[1]*_t49;
  const double _t51 = (0.1e1 / 0.24e2)*_t50;
  const double _t24 = _hc1[0]*_hc2[0];
  const double _t25 = _t24*_t4;
  const double _t29 = _hc2[1]*_t1;
  const double _t30 = _hc0[0]*_hc1[0];
  const double _t31 = _t19*_t30;
  const double _t38 = my_piecewise3(_t21, 0, _hc0[0]*_hc1[1]*_hc2[0]*_t37 - _t25*_t28 - 0.1e1 / 0.6e1*_t29*_t31);
  const double _t41 = _t2*_t24;
  const double _t42 = _t40*_t41;
  const double _t46 = _hc1[1]*_hc2[0];
  const double _t47 = _t15*_t46;
  const double _t48 = _t45*_t47;
  const double _t52 = 0.2e1*my_piecewise3(_t21, 0, _t42*_t44 + _t48*_t51);
  const double dF_dna = _t23 + _t38*_t39;
  const double dF_dgaa = _t52*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t53 = xc_powr(na, -14, 3);
  const double _t54 = xc_powr(0.2e1, 2, 3);
  const double _t58 = xc_powr(na, -10, 3);
  const double _t61 = (0.2e1 / 0.9e1)*_t26;
  const double _t62 = xc_powr(0.6e1, 2, 3);
  const double _t63 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t67 = xc_powr(na, -11, 3);
  const double _t68 = (0.4e1 / 0.9e1)*_t67;
  const double _t71 = xc_powr(0.12e2, 1, 3);
  const double _t85 = xc_powi(na, -5);
  const double _t90 = (0.1e1 / 0.3e1)*_t67;
  const double _t101 = (0.2e1 / 0.3e1)*_t67;
  const double _t103 = (0.1e1 / 0.12e2)*_t33;
  const double _t108 = xc_powr(0.3e1, 5, 6);
  const double _t109 = xc_powr(M_PI, -5, 6);
  const double _t110 = _t108*_t109;
  const double _t114 = (0.1e1 / (na * na * na));
  const double _t118 = (0.1e1 / (na * na * na * na));
  const double _t125 = xc_powr(gaa, 3, 2);
  const double _t126 = (0.1e1 / _t125);
  const double _t127 = (0.1e1 / 0.4e1)*_t126;
  const double _t129 = (0.1e1 / gaa);
  const double _t131 = (0.1e1 / 0.4e1)*_t33;
  const double _t135 = (0.1e1 / M_PI);
  const double _t136 = M_CBRT3*((p->cam_omega) * (p->cam_omega))/M_CBRTPI;
  const double _t137 = _t135*_t136;
  const double _t138 = _t137*_t58;
  const double _t139 = (0.1e1 / 0.192e3)*_t138;
  const double _t142 = _t126*_t2;
  const double _t147 = (0.1e1 / 0.32e2)*_t114;
  const double _t55 = _hc0[2]*_t54;
  const double _t75 = (_t37 * _t37);
  const double _t78 = _t27*_t4;
  const double _t79 = (0.8e1 / 0.3e1)*_t78;
  const double _t84 = _t15*_t26;
  const double _t86 = _t55*_t8;
  const double _t87 = _t15*_t86;
  const double _t88 = _t85*_t87;
  const double _t89 = _t88*gaa;
  const double _t91 = ((_hc0[1]) * (_hc0[1]));
  const double _t92 = _t54*_t91;
  const double _t93 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t94 = _t15*_t93;
  const double _t95 = _t92*_t94;
  const double _t96 = _t85*_t95;
  const double _t97 = _t96*gaa;
  const double _t98 = _t36*_t90 + (0.2e1 / 0.27e2)*_t84 + (0.4e1 / 0.27e2)*_t89 - 0.2e1 / 0.27e2*_t97;
  const double _t102 = (0.2e1 / 0.3e1)*_t27;
  const double _t106 = _t13*_t9;
  const double _t115 = _hc0[1]*_t40;
  const double _t116 = _t115*_t54;
  const double _t117 = _t114*_t116;
  const double _t119 = _t118*_t32;
  const double _t121 = _t35*_t49;
  const double _t122 = _t121*_t33;
  const double _t123 = (0.1e1 / 0.36e2)*_t11*_t118*_t12*_t54*_t6*_t7*_t9*_t91*_t93*p->cam_omega - _t119*_t86 - 0.5e1 / 0.72e2*_t122;
  const double _t132 = _t129*_t92;
  const double _t143 = _hc0[1]*_t45;
  const double _t144 = _t142*_t143;
  const double _t145 = _t129*_t55;
  const double _t146 = _t114*_t145;
  const double _t56 = _t24*_t55;
  const double _t57 = _t53*_t56;
  const double _t59 = _hc0[1]*_t25;
  const double _t60 = _hc2[1]*_t31;
  const double _t64 = _hc2[2]*_t63;
  const double _t65 = _t62*_t64;
  const double _t66 = _t30*_t65;
  const double _t69 = _hc0[1]*_hc1[0];
  const double _t70 = _t3*_t69;
  const double _t72 = _hc2[1]*_t18;
  const double _t73 = _t71*_t72;
  const double _t74 = _t70*_t73;
  const double _t76 = _hc1[2]*_t22;
  const double _t77 = _t37*_t46;
  const double _t80 = _hc0[0]*_hc1[1];
  const double _t81 = _t37*_t80;
  const double _t82 = _t19*_t81;
  const double _t83 = (0.1e1 / 0.3e1)*_t29;
  const double _t99 = _hc1[1]*_t22;
  const double _t100 = my_piecewise3(_t21, 0, (0.1e1 / 0.36e2)*_t33*_t66 + (0.16e2 / 0.9e1)*_t57*gaa + (0.28e2 / 0.9e1)*_t58*_t59 + _t60*_t61 + _t68*_t74 + _t75*_t76 - _t77*_t79 - _t82*_t83 + _t98*_t99);
  const double _t104 = _t40*_t69;
  const double _t105 = _t104*_t73;
  const double _t107 = _hc1[1]*_t106;
  const double _t111 = _t107*_t110;
  const double _t112 = _hc2[1]*_t111;
  const double _t113 = (0.1e1 / 0.144e3)*_t112;
  const double _t120 = _t46*_t8;
  const double _t124 = my_piecewise3(_t21, 0, _hc0[0]*_hc1[1]*_hc2[0]*_t123 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc2[0]*_t1*_t2*_t37*_t40 + (0.1e1 / 0.24e2)*_hc0[1]*_hc1[2]*_hc2[0]*_t11*_t12*_t2*_t37*_t40*_t45*_t6*_t7*_t9*p->cam_omega - _t101*_t56 - _t102*_t42 - _t103*_t105 - _t113*_t117 - _t119*_t120*_t92);
  const double _t128 = _t41*_t43;
  const double _t130 = _t129*_t56;
  const double _t133 = _hc1[2]*_hc2[0];
  const double _t134 = _t132*_t133;
  const double _t140 = (0.1e1 / 0.48e2)*_t46;
  const double _t141 = _t140*_t15;
  const double _t148 = _t34*_t46;
  const double _t149 = _t132*_t148;
  const double _t150 = 0.2e1*my_piecewise3(_t21, 0, -_t127*_t128 + _t130*_t131 + _t134*_t139 - _t141*_t144 + _t141*_t146 + _t147*_t149);
  const double d2F_dna2 = _t100*_t39 + 0.4e1*_t38;
  const double d2F_dna_dgaa = _t124*_t39 + _t52;
  const double d2F_dgaa2 = _t150*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t151 = (0.1e1 / 0.36e2)*_t118;
  const double _t154 = xc_powi(na, -7);
  const double _t157 = xc_powr(na, -17, 3);
  const double _t159 = xc_powr(na, -13, 3);
  const double _t160 = xc_powi(na, -6);
  const double _t161 = (0.16e2 / 0.9e1)*_t160;
  const double _t163 = M_CBRT3;
  const double _t167 = (0.2e1 / 0.9e1)*_t85;
  const double _t168 = xc_powr(0.3e1, 2, 3);
  const double _t182 = xc_powr(na, -22, 3);
  const double _t185 = _t160*gaa;
  const double _t186 = (0.8e1 / 0.27e2)*_t182;
  const double _t197 = (0.4e1 / 0.9e1)*_t85;
  const double _t199 = xc_powr(0.3e1, 1, 6);
  const double _t200 = xc_powr(M_PI, -7, 6);
  const double _t203 = xc_powr(na, -16, 3);
  const double _t208 = xc_powr(na, -19, 3);
  const double _t209 = (0.4e1 / 0.27e2)*_t208;
  const double _t228 = (0.1e1 / 0.9e1)*_t118;
  const double _t238 = (0.2e1 / 0.9e1)*_t208;
  const double _t241 = (0.1e1 / 0.9e1)*_t208;
  const double _t250 = (0.1e1 / 0.12e2)*_t129;
  const double _t251 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t261 = (0.1e1 / 0.288e3)*_t126;
  const double _t286 = (0.1e1 / 0.12e2)*_t203;
  const double _t288 = (0.1e1 / 0.24e2)*_t203;
  const double _t293 = _t118*_t129;
  const double _t298 = xc_powr(gaa, -5, 2);
  const double _t299 = (0.3e1 / 0.8e1)*_t298;
  const double _t300 = (gaa * gaa);
  const double _t301 = (0.1e1 / _t300);
  const double _t303 = (0.3e1 / 0.8e1)*_t33;
  const double _t304 = (0.1e1 / 0.64e2)*_t126;
  const double _t308 = (0.1e1 / 0.128e3)*_t301;
  const double _t312 = (0.1e1 / 0.128e3)*_t126;
  const double _t317 = _t2*_t298;
  const double _t318 = (0.1e1 / 0.32e2)*_t317;
  const double _t320 = _t147*_t301;
  const double _t325 = xc_powr(M_PI, -3, 2);
  const double _t326 = xc_powr(M_CBRT3, 3, 2)*((p->cam_omega) * (p->cam_omega) * (p->cam_omega))/xc_powr(M_CBRTPI, 3, 2);
  const double _t331 = (0.3e1 / 0.64e2)*_t301;
  const double _t332 = _t114*_t331;
  const double _t171 = (_t37 * _t37 * _t37);
  const double _t174 = 0.4e1*_t78;
  const double _t179 = _t101*_t36 + (0.4e1 / 0.27e2)*_t84 + (0.8e1 / 0.27e2)*_t89 - 0.4e1 / 0.27e2*_t97;
  const double _t180 = _t15*_t58;
  const double _t181 = _hc0[3]*_t125;
  const double _t183 = _t182*_t34;
  const double _t184 = _t181*_t183;
  const double _t187 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t188 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t189 = _t15*_t188;
  const double _t190 = _t187*_t189;
  const double _t191 = _t125*_t190;
  const double _t192 = _t36*_t53;
  const double _t193 = (0.16e2 / 0.27e2)*_hc0[1]*_hc0[2]*_t11*_t12*_t125*_t182*_t6*_t7*_t9*_t93*p->cam_omega + (0.16e2 / 0.27e2)*_t11*_t12*_t160*_t54*_t6*_t7*_t9*_t91*_t93*p->cam_omega*gaa - 0.14e2 / 0.81e2*_t180 - 0.32e2 / 0.81e2*_t184 - 0.32e2 / 0.27e2*_t185*_t87 - _t186*_t191 - 0.103e3 / 0.81e2*_t192;
  const double _t198 = _hc0[1]*_t159;
  const double _t204 = _t203*_t8;
  const double _t210 = _t209*_t34;
  const double _t211 = _hc0[1]*_t3;
  const double _t215 = _t55*_t67;
  const double _t217 = _t44*_t49;
  const double _t224 = _t15*_t45;
  const double _t225 = _t224*_t51;
  const double _t235 = (0.1e1 / 0.18e2)*_t11*_t118*_t12*_t54*_t6*_t7*_t9*_t91*_t93*p->cam_omega - 0.5e1 / 0.36e2*_t122 - _t228*_t87;
  const double _t237 = _hc0[3]*_t3;
  const double _t239 = _hc0[2]*_t94;
  const double _t240 = _t211*_t239;
  const double _t242 = _t190*_t3;
  const double _t243 = _t121*_t67;
  const double _t244 = _t210*_t237 - _t238*_t240 + _t241*_t242 + (0.5e1 / 0.27e2)*_t243 + (0.17e2 / 0.54e2)*_t88 - 0.17e2 / 0.108e3*_t96;
  const double _t256 = _t187*_t8;
  const double _t257 = _t256*_t40;
  const double _t259 = _hc0[2]*_t129;
  const double _t260 = _t159*_t259;
  const double _t264 = _hc0[2]*_t16;
  const double _t265 = _t187*_t203*_t40;
  const double _t268 = _t159*_t8;
  const double _t270 = _t127*_t43;
  const double _t278 = _t147*_t34;
  const double _t279 = _t43*_t49;
  const double _t281 = _t224*_t50;
  const double _t282 = (0.1e1 / 0.12e2)*_t281;
  const double _t283 = _hc0[3]*_t40;
  const double _t284 = _t203*_t283;
  const double _t285 = _t32*_t8;
  const double _t287 = _t115*_t239;
  const double _t289 = _t190*_t40;
  const double _t290 = _t142*_t35;
  const double _t291 = _t290*_t33;
  const double _t292 = _t118*_t145*_t34;
  const double _t294 = _t293*_t95;
  const double _t295 = -_t284*_t285 + _t286*_t287 - _t288*_t289 + (0.5e1 / 0.144e3)*_t291 - 0.5e1 / 0.144e3*_t292 + (0.5e1 / 0.288e3)*_t294;
  const double _t306 = _hc0[1]*_hc0[2];
  const double _t313 = _t15*_t159;
  const double _t314 = _t126*_t313;
  const double _t315 = _hc0[3]*_t314;
  const double _t321 = (0.3e1 / 0.32e2)*_t306*_t314;
  const double _t323 = _t187*_t93;
  const double _t329 = _t126*_t256;
  const double _t330 = (0.1e1 / 0.2304e4)*_t329;
  const double _t152 = _hc2[3]*_t135;
  const double _t153 = _t152*_t30;
  const double _t155 = _hc0[3]*_t24;
  const double _t156 = _t125*_t155;
  const double _t158 = _t157*_t56;
  const double _t162 = _hc0[2]*_hc1[0];
  const double _t164 = _t163*_t72;
  const double _t165 = _t162*_t164;
  const double _t166 = _t165*gaa;
  const double _t169 = _t168*_t64;
  const double _t170 = _t167*_t169;
  const double _t172 = _hc1[2]*_t75;
  const double _t173 = _hc2[0]*_t172;
  const double _t175 = _t20*_t29;
  const double _t176 = _hc0[0]*_t172;
  const double _t177 = _t46*_t98;
  const double _t178 = _t80*_t98;
  const double _t194 = my_piecewise3(_t21, 0, _hc0[0]*_hc1[1]*_hc2[0]*_t193 + (0.2e1 / 0.3e1)*_hc0[0]*_hc1[1]*_hc2[1]*_t17*_t18*_t26*_t37 + (0.1e1 / 0.12e2)*_hc0[0]*_hc1[1]*_hc2[2]*_t33*_t37*_t62*_t63 + _hc0[0]*_hc1[2]*_hc2[0]*_t179*_t37 + _hc0[0]*_hc1[2]*_hc2[0]*_t37*_t98 + _hc0[0]*_hc1[3]*_hc2[0]*_t171 + (0.28e2 / 0.3e1)*_hc0[1]*_hc1[1]*_hc2[0]*_t2*_t3*_t37*_t58 + (0.4e1 / 0.3e1)*_hc0[1]*_hc1[1]*_hc2[1]*_t18*_t3*_t37*_t67*_t71 + (0.16e2 / 0.3e1)*_hc0[2]*_hc1[1]*_hc2[0]*_t37*_t53*_t54*gaa - _t151*_t153 - 0.128e3 / 0.27e2*_t154*_t156 - 0.112e3 / 0.9e1*_t158*gaa - 0.280e3 / 0.27e2*_t159*_t59 - _t161*_t166 - _t170*_t70 - _t173*_t174 - _t174*_t177 - _t175*_t176 - _t175*_t178 - 0.22e2 / 0.9e1*_t53*_t74 - 0.14e2 / 0.27e2*_t58*_t60 - 0.1e1 / 0.9e1*_t66*_t67);
  const double _t195 = _t155*_t3;
  const double _t196 = _hc0[1]*_t42;
  const double _t201 = _hc2[2]*_t107*_t199*_t200;
  const double _t202 = _t198*_t201;
  const double _t205 = _hc2[1]*_t91;
  const double _t206 = _t111*_t205;
  const double _t207 = (0.1e1 / 0.108e3)*_t112;
  const double _t212 = _hc0[2]*_t46;
  const double _t213 = _t211*_t212;
  const double _t214 = _t148*_t92;
  const double _t216 = (0.4e1 / 0.3e1)*_t77;
  const double _t218 = _t33*_t73;
  const double _t219 = _hc1[1]*_t37;
  const double _t220 = _hc0[1]*_t219;
  const double _t221 = _hc1[2]*_t37;
  const double _t222 = _t106*_t110*_t221;
  const double _t223 = (0.1e1 / 0.72e2)*_hc2[1]*_t222;
  const double _t226 = _hc1[3]*_hc2[0];
  const double _t227 = _t226*_t75;
  const double _t229 = _hc2[0]*_t221;
  const double _t230 = _t229*_t34;
  const double _t231 = _t230*_t92;
  const double _t232 = _t123*_t46;
  const double _t233 = (0.8e1 / 0.3e1)*_t232;
  const double _t234 = _t19*_t80;
  const double _t236 = _t37*_t76;
  const double _t245 = my_piecewise3(_t21, 0, _t104*_t151*_t169 + _t105*_t90 + _t116*_t118*_t207 - _t117*_t223 - _t123*_t234*_t83 + _t133*_t225*_t98 + _t161*_t195 + _t165*_t197 + _t173*_t217 + _t177*_t217 + (0.14e2 / 0.9e1)*_t196*_t58 + (0.1e1 / 0.144e3)*_t202*_t40 + (0.1e1 / 0.27e2)*_t204*_t206 + _t210*_t213 + (0.7e1 / 0.54e2)*_t214*_t85 - _t215*_t216 - 0.1e1 / 0.6e1*_t218*_t220*_t40 + _t225*_t227 - _t228*_t231 - _t233*_t78 + _t235*_t236 + _t244*_t99 - _t28*_t49*_t77 + (0.10e2 / 0.3e1)*_t57);
  const double _t246 = _t155*_t40;
  const double _t247 = _t126*_t41;
  const double _t248 = _t126*_t69;
  const double _t249 = _t118*_t165;
  const double _t252 = _hc1[2]*_t136;
  const double _t253 = _t129*_t205;
  const double _t254 = _t163*_t251*_t252*_t253;
  const double _t255 = _t133*_t137;
  const double _t258 = _t255*_t257;
  const double _t262 = _hc0[1]*_t112*_t54;
  const double _t263 = _t114*_t262;
  const double _t266 = _t46*_t94;
  const double _t267 = _t111*_t253;
  const double _t269 = _t2*_t77;
  const double _t271 = _t55*_t77;
  const double _t272 = _t129*_t271;
  const double _t273 = _hc1[3]*_t37;
  const double _t274 = _hc2[0]*_t132;
  const double _t275 = _t139*_t274;
  const double _t276 = (0.1e1 / 0.48e2)*_t229;
  const double _t277 = _t15*_t276;
  const double _t280 = _t123*_t133;
  const double _t296 = my_piecewise3(_t21, 0, -_t113*_t260 - _t115*_t204*_t264*_t46 - _t130*_t90 + _t131*_t272 - _t144*_t277 + _t146*_t277 - _t149*_t151 - 0.1e1 / 0.72e2*_t157*_t258 + (0.1e1 / 0.24e2)*_t218*_t248 + _t221*_t274*_t278 + _t232*_t279 - 0.2e1 / 0.3e1*_t246*_t85 + (0.1e1 / 0.3e1)*_t247*_t27 - _t249*_t250 - 0.1e1 / 0.576e3*_t254*_t53 + _t261*_t263 + (0.1e1 / 0.36e2)*_t265*_t266 - 0.1e1 / 0.96e2*_t267*_t268 - _t269*_t270 + _t273*_t275 + _t280*_t282 + _t295*_t99);
  const double _t297 = _t118*_t155;
  const double _t302 = _t301*_t56;
  const double _t305 = _t255*_t53;
  const double _t307 = _t305*_t306;
  const double _t309 = _t133*_t92;
  const double _t310 = _t138*_t309;
  const double _t311 = _t256*_t305;
  const double _t316 = _hc0[1]*_t48;
  const double _t319 = _t47*_t55;
  const double _t322 = _t313*_t46;
  const double _t324 = _t322*_t323;
  const double _t327 = _t10*_t226*_t325*_t326;
  const double _t328 = _t327*_t85;
  const double _t333 = 0.2e1*my_piecewise3(_t21, 0, _t120*_t321 + _t127*_t297 + _t128*_t299 + _t140*_t315 - _t214*_t332 - _t302*_t303 + _t304*_t307 - _t304*_t324 - _t308*_t310 + _t311*_t312 + _t316*_t318 - _t319*_t320 + _t328*_t330);
  const double d3F_dna3 = 0.6e1*_t100 + _t194*_t39;
  const double d3F_dna2_dgaa = 0.4e1*_t124 + _t245*_t39;
  const double d3F_dna_dgaa2 = _t150 + _t296*_t39;
  const double d3F_dgaa3 = _t333*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t334 = xc_powi(na, -8);
  const double _t335 = xc_powr(na, -20, 3);
  const double _t337 = _t17*_t251;
  const double _t338 = (0.1e1 / 0.216e3)*_t337;
  const double _t343 = xc_powr(na, -25, 3);
  const double _t365 = (0.64e2 / 0.27e2)*gaa;
  const double _t367 = _t154*gaa;
  const double _t369 = _t300/xc_powr(na, 29, 3);
  const double _t370 = _t2*_t369;
  const double _t380 = (0.38e2 / 0.9e1)*_t160;
  const double _t382 = (0.1e1 / 0.72e2)*_t203;
  const double _t383 = (0.8e1 / 0.9e1)*_t182;
  const double _t390 = xc_powr(na, -26, 3);
  const double _t391 = _t390*gaa;
  const double _t392 = (0.16e2 / 0.81e2)*_t391;
  const double _t394 = xc_powr(na, -23, 3);
  const double _t410 = (0.1e1 / 0.3e1)*_t129;
  const double _t415 = (0.1e1 / 0.288e3)*_t157;
  const double _t416 = _t2*_t394;
  const double _t417 = (0.4e1 / 0.27e2)*_t416;
  const double _t423 = _t163*_t251*_t53;
  const double _t435 = (0.1e1 / 0.16e2)*_t298;
  const double _t436 = (0.1e1 / 0.8e1)*_t301;
  const double _t438 = _t160*_t337;
  const double _t442 = (0.1e1 / 0.96e2)*_t301;
  const double _t444 = _t129*_t335;
  const double _t453 = _t126*_t203;
  const double _t454 = xc_powr(gaa, -7, 2);
  const double _t455 = (0.1e1 / (gaa * gaa * gaa));
  const double _t456 = (0.3e1 / 0.64e2)*_t298;
  const double _t460 = _t157*_t2;
  const double _t461 = _t114*_t455;
  const double _t344 = _t181*_t343;
  const double _t347 = (0.32e2 / 0.3e1)*_t53*_t55*gaa;
  const double _t349 = _hc0[1]*_t58;
  const double _t350 = (0.56e2 / 0.3e1)*_t349*_t4;
  const double _t352 = (0.16e2 / 0.3e1)*_t78;
  const double _t366 = _t160*_t87;
  const double _t368 = _hc0[4]*_t34;
  const double _t371 = _hc0[1]*_hc0[3];
  const double _t372 = _t371*_t94;
  const double _t373 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t374 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t375 = _t15*_t373*_t374;
  const double _t376 = ((_hc0[2]) * (_hc0[2]));
  const double _t377 = _t376*_t94;
  const double _t378 = _hc0[2]*_t91;
  const double _t379 = _t189*_t378;
  const double _t385 = _t115*_t203;
  const double _t387 = _t208*_t8;
  const double _t388 = _t2*_t91;
  const double _t389 = _t335*_t8;
  const double _t395 = _t306*_t8;
  const double _t396 = 0.2e1*_t215;
  const double _t397 = _t27*_t49;
  const double _t398 = 0.2e1*_t397;
  const double _t401 = _t118*_t16;
  const double _t402 = _t401*_t8;
  const double _t403 = (0.1e1 / 0.48e2)*_t98;
  const double _t408 = _t208*_t34;
  const double _t409 = _t2*_t368;
  const double _t413 = _t129*_t388;
  const double _t420 = _t157*_t8;
  const double _t421 = _t2*_t270;
  const double _t422 = _t131*_t145;
  const double _t427 = (0.1e1 / 0.3e1)*_t115;
  const double _t428 = _t144*_t15;
  const double _t430 = _t146*_t15;
  const double _t432 = _t123*_t34;
  const double _t440 = _t374*_t93;
  const double _t441 = _t129*_t440;
  const double _t445 = _t2*_t374;
  const double _t446 = _t335*_t388;
  const double _t459 = _t301*_t445;
  const double _t336 = _hc0[4]*_t41;
  const double _t339 = _t162*_t186*gaa;
  const double _t340 = _t152*_t69;
  const double _t341 = _hc2[1]*_t19;
  const double _t342 = _hc1[0]*_t341;
  const double _t345 = _t169*_t2;
  const double _t346 = _hc0[3]*_t77;
  const double _t348 = _hc0[2]*_t164*_t219;
  const double _t351 = _hc1[3]*_t171;
  const double _t353 = _hc2[0]*_t352;
  const double _t354 = (0.4e1 / 0.3e1)*_t26*_t341;
  const double _t355 = (0.2e1 / 0.3e1)*_t29;
  const double _t356 = _hc0[0]*_t19*_t355;
  const double _t357 = (0.1e1 / 0.6e1)*_t33*_t65;
  const double _t358 = _t220*_t3;
  const double _t359 = _t67*_t73;
  const double _t360 = (0.8e1 / 0.3e1)*_t211*_t359;
  const double _t361 = _hc1[1]*_t98;
  const double _t362 = _hc1[3]*_t22*_t75;
  const double _t363 = _t221*_t353;
  const double _t364 = _t221*_t356;
  const double _t381 = _t162*_t345;
  const double _t384 = _hc0[3]*_t342;
  const double _t386 = (0.1e1 / 0.36e2)*_t201;
  const double _t393 = _hc0[3]*_t35*_t46;
  const double _t399 = _t115*_t131*_t73;
  const double _t400 = _hc2[1]*_t106*_t110*_t117;
  const double _t404 = _hc1[2]*_t400;
  const double _t405 = _t221*_t235;
  const double _t406 = _hc2[0]*_t405;
  const double _t407 = _t244*_t46;
  const double _t411 = _t2*_t255;
  const double _t412 = _t411*_t8;
  const double _t414 = _hc2[1]*_t252;
  const double _t418 = _t148*_t376;
  const double _t419 = _t239*_t46;
  const double _t424 = _hc2[0]*_t273;
  const double _t425 = _t137*_t424;
  const double _t426 = _hc2[1]*_t126;
  const double _t429 = (0.1e1 / 0.48e2)*_t227;
  const double _t431 = _hc1[3]*_t274;
  const double _t433 = _t133*_t403;
  const double _t434 = _t295*_t46;
  const double _t437 = (0.1e1 / 0.384e3)*_t252;
  const double _t439 = _t205*_t301;
  const double _t443 = _t112*_t142;
  const double _t447 = _t2*_t327;
  const double _t448 = _t425*_t53;
  const double _t449 = _t15*_t229;
  const double _t450 = _hc1[4]*_hc2[0];
  const double _t451 = (0.3e1 / 0.4e1)*_t232;
  const double _t452 = (0.1e1 / 0.16e2)*_t280;
  const double _t457 = _t160*_t411;
  const double _t458 = _t301*_t457;
  const double _t462 = _t301*_t447;
  const double d4F_dna4 = 0.8e1*_t194 + _t39*my_piecewise3(_t21, 0, _hc1[4]*_t22*(_t37 * _t37 * _t37 * _t37) - 0.56e2 / 0.27e2*_hc2[1]*_t58*_t82 + _hc2[4]*_t203*_t30*_t338 - 0.512e3 / 0.27e2*_t125*_t154*_t346 - _t152*_t228*_t81 + _t153*_t167 + (0.64e2 / 0.3e1)*_t154*_t166 + (0.1792e4 / 0.27e2)*_t156*_t334 - 0.448e3 / 0.9e1*_t157*_t271*gaa + (0.1120e4 / 0.81e2)*_t157*_t74 + (0.140e3 / 0.81e2)*_t159*_t60 + (0.20e2 / 0.9e1)*_t160*_t169*_t3*_t69 - 0.8e1 / 0.9e1*_t169*_t358*_t85 + _t172*_t360 + _t173*_t347 + _t173*_t350 + _t176*_t354 + _t176*_t357 + _t177*_t347 + _t177*_t350 + _t178*_t354 + _t178*_t357 + _t179*_t362 - _t179*_t363 - _t179*_t364 + _t179*_t76*_t98 - 0.64e2 / 0.9e1*_t185*_t348 - _t193*_t234*_t355 + 0.2e1*_t193*_t236 - _t193*_t352*_t46 - 0.1120e4 / 0.27e2*_t198*_t4*_t77 + (0.3640e4 / 0.81e2)*_t203*_t59 + _t209*_t340*_t4 + _t236*((0.32e2 / 0.27e2)*_hc0[1]*_hc0[2]*_t11*_t12*_t125*_t182*_t6*_t7*_t9*_t93*p->cam_omega + (0.32e2 / 0.27e2)*_t11*_t12*_t160*_t54*_t6*_t7*_t9*_t91*_t93*p->cam_omega*gaa - 0.28e2 / 0.81e2*_t180 - 0.16e2 / 0.27e2*_t182*_t191 - 0.64e2 / 0.81e2*_t184 - 0.206e3 / 0.81e2*_t192 - _t365*_t366) + (0.512e3 / 0.81e2)*_t300*_t336/xc_powr(na, 28, 3) + (0.6832e4 / 0.81e2)*_t335*_t56*gaa + _t339*_t345 + xc_powr(0.18e2, 1, 3)*_t339*_t64 + (0.256e3 / 0.81e2)*_t342*_t344 - _t351*_t353 - _t351*_t356 - 0.88e2 / 0.9e1*_t358*_t53*_t73 + _t360*_t361 + _t362*_t98 + _t362*(_t15*_t61 - _t167*_t95*gaa + _t197*_t87*gaa + _t36*_t67) - _t363*_t98 - _t364*_t98 + (0.40e2 / 0.81e2)*_t53*_t66 - _t65*_t68*_t81 + _t76*(_t98 * _t98) + _t99*(-0.736e3 / 0.81e2*_t125*_t306*_t343*_t94 + (0.490e3 / 0.81e2)*_t157*_t36 + (0.368e3 / 0.81e2)*_t191*_t343 - 0.80e2 / 0.81e2*_t2*_t369*_t375 + (0.140e3 / 0.243e3)*_t313 + (0.1472e4 / 0.243e3)*_t34*_t344 + (0.2140e4 / 0.243e3)*_t367*_t87 - 0.1070e4 / 0.243e3*_t367*_t95 + (0.128e3 / 0.243e3)*_t368*_t370 - 0.256e3 / 0.243e3*_t370*_t372 - 0.64e2 / 0.81e2*_t370*_t377 + (0.64e2 / 0.27e2)*_t370*_t379));
  const double d4F_dna3_dgaa = 0.6e1*_t245 + _t39*my_piecewise3(_t21, 0, _hc0[0]*_hc1[1]*_hc2[0]*((0.8e1 / 0.3e1)*_hc0[1]*_hc0[2]*_t11*_t12*_t182*_t3*_t6*_t7*_t9*_t93*p->cam_omega + (0.32e2 / 0.81e2)*_hc0[1]*_hc0[3]*_t11*_t12*_t2*_t390*_t6*_t7*_t9*_t93*p->cam_omega*gaa + (0.295e3 / 0.324e3)*_t11*_t12*_t160*_t54*_t6*_t7*_t9*_t91*_t93*p->cam_omega + (0.10e2 / 0.27e2)*_t11*_t12*_t2*_t373*_t374*_t390*_t6*_t7*_t9*p->cam_omega*gaa + (0.8e1 / 0.27e2)*_t11*_t12*_t2*_t376*_t390*_t6*_t7*_t9*_t93*p->cam_omega*gaa - 0.55e2 / 0.81e2*_t121*_t53 - 0.4e1 / 0.3e1*_t182*_t242 - 0.16e2 / 0.9e1*_t183*_t237 - 0.8e1 / 0.9e1*_t2*_t379*_t391 - 0.295e3 / 0.162e3*_t366 - _t392*_t409) + (0.2e1 / 0.3e1)*_hc0[0]*_hc1[1]*_hc2[1]*_t123*_t17*_t18*_t26 + (0.1e1 / 0.12e2)*_hc0[0]*_hc1[1]*_hc2[2]*_t123*_t33*_t62*_t63 + _hc0[0]*_hc1[2]*_hc2[0]*_t123*_t179 + _hc0[0]*_hc1[2]*_hc2[0]*_t123*_t98 + _hc0[0]*_hc1[2]*_hc2[0]*_t244*_t37 + _hc0[0]*_hc1[2]*_hc2[0]*_t37*(-0.4e1 / 0.9e1*_t208*_t240 + (0.8e1 / 0.27e2)*_t237*_t408 + _t238*_t242 + (0.10e2 / 0.27e2)*_t243 + (0.17e2 / 0.27e2)*_t88 - 0.17e2 / 0.54e2*_t96) + _hc0[0]*_hc1[3]*_hc2[0]*_t75*((0.1e1 / 0.12e2)*_t11*_t118*_t12*_t54*_t6*_t7*_t9*_t91*_t93*p->cam_omega - 0.5e1 / 0.24e2*_t122 - _t401*_t86) - _hc0[0]*_t175*_t405 + (0.4e1 / 0.9e1)*_hc0[1]*_hc0[2]*_hc1[2]*_hc2[0]*_t11*_t12*_t208*_t3*_t37*_t6*_t7*_t8*_t9*p->cam_omega + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[1]*_hc2[0]*_t1*_t193*_t2*_t40 + (0.28e2 / 0.3e1)*_hc0[1]*_hc1[1]*_hc2[0]*_t123*_t2*_t3*_t58 + (0.14e2 / 0.3e1)*_hc0[1]*_hc1[1]*_hc2[0]*_t2*_t37*_t40*_t58 + (0.4e1 / 0.3e1)*_hc0[1]*_hc1[1]*_hc2[1]*_t123*_t18*_t3*_t67*_t71 + _hc0[1]*_hc1[1]*_hc2[1]*_t18*_t37*_t40*_t67*_t71 + (0.1e1 / 0.12e2)*_hc0[1]*_hc1[1]*_hc2[2]*_t118*_t168*_t37*_t40*_t63 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[2]*_hc2[0]*_t1*_t179*_t2*_t37*_t40 + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[2]*_hc2[0]*_t1*_t2*_t37*_t40*_t98 + (0.1e1 / 0.24e2)*_hc0[1]*_hc1[2]*_hc2[0]*_t11*_t12*_t193*_t2*_t40*_t45*_t6*_t7*_t9*p->cam_omega + (0.1e1 / 0.36e2)*_hc0[1]*_hc1[2]*_hc2[1]*_t108*_t109*_t11*_t118*_t12*_t37*_t40*_t54*_t9*p->cam_omega + (0.1e1 / 0.48e2)*_hc0[1]*_hc1[2]*_hc2[2]*_t11*_t12*_t159*_t199*_t200*_t37*_t40*_t9*p->cam_omega + (0.1e1 / 0.2e1)*_hc0[1]*_hc1[3]*_hc2[0]*_t1*_t171*_t2*_t40 + (0.1e1 / 0.24e2)*_hc0[1]*_hc1[3]*_hc2[0]*_t11*_t12*_t179*_t2*_t37*_t40*_t45*_t6*_t7*_t9*p->cam_omega + (0.1e1 / 0.24e2)*_hc0[1]*_hc1[3]*_hc2[0]*_t11*_t12*_t2*_t37*_t40*_t45*_t6*_t7*_t9*_t98*p->cam_omega + (0.1e1 / 0.24e2)*_hc0[1]*_hc1[4]*_hc2[0]*_t11*_t12*_t171*_t2*_t40*_t45*_t6*_t7*_t9*p->cam_omega + (0.16e2 / 0.3e1)*_hc0[2]*_hc1[1]*_hc2[0]*_t123*_t53*_t54*gaa + 0.10e2*_hc0[2]*_hc1[1]*_hc2[0]*_t37*_t53*_t54 + (0.4e1 / 0.3e1)*_hc0[2]*_hc1[1]*_hc2[1]*_t163*_t18*_t37*_t85 + (0.16e2 / 0.3e1)*_hc0[3]*_hc1[1]*_hc2[0]*_t160*_t3*_t37 - 0.1e1 / 0.864e3*_hc1[1]*_hc2[3]*_t14*_t157*_t325*_t50 + (0.7e1 / 0.18e2)*_hc1[2]*_hc2[0]*_t11*_t12*_t37*_t54*_t6*_t7*_t8*_t85*_t9*_t91*p->cam_omega + (0.1e1 / 0.9e1)*_hc1[2]*_hc2[1]*_t108*_t109*_t11*_t12*_t203*_t37*_t8*_t9*_t91*p->cam_omega - 0.1e1 / 0.48e2*_hc1[3]*_t400*_t75 - _t104*_t170 - 0.40e2 / 0.27e2*_t105*_t53 - 0.7e1 / 0.324e3*_t112*_t116*_t85 - 0.2e1 / 0.27e2*_t112*_t394*_t395*_t4 - 0.176e3 / 0.9e1*_t154*_t195 - 0.476e3 / 0.27e2*_t158 - 0.140e3 / 0.27e2*_t159*_t196 - 0.35e2 / 0.81e2*_t160*_t214 - _t165*_t380 - _t172*_t399 - _t173*_t396 - _t173*_t398 - _t174*_t406 - _t174*_t407 - _t175*_t244*_t80 - _t177*_t396 - _t177*_t398 - 0.28e2 / 0.27e2*_t183*_t213 - _t2*_t392*_t393 - 0.11e2 / 0.54e2*_t206*_t387 - _t227*_t402*_t92 - _t241*_t381 - _t3*_t383*_t384 - _t309*_t402*_t98 - _t336*_t343*_t365 - _t340*_t382*_t49 - _t361*_t399 - _t385*_t386 - _t386*_t388*_t389 - _t403*_t404);
  const double d4F_dna2_dgaa2 = 0.4e1*_t296 + _t39*my_piecewise3(_t21, 0, (0.1e1 / 0.144e3)*_hc0[1]*_t114*_t222*_t426*_t54 - _hc0[2]*_t203*_t230*_t427 - _hc1[1]*_t123*_t218*_t427 + _hc1[3]*_t275*_t98 + _hc1[4]*_t275*_t75 + (0.1e1 / 0.3456e4)*_hc2[2]*_t160*_t168*_t252*_t413/(M_PI * M_CBRTPI * M_CBRTPI) - _t101*_t272 + _t102*_t126*_t269 + _t103*_t126*_t220*_t73 + (0.1e1 / 0.18e2)*_t112*_t306*_t389*_t49 + (0.11e2 / 0.18e2)*_t115*_t212*_t408 - 0.1e1 / 0.216e3*_t118*_t126*_t262 - 0.1e1 / 0.72e2*_t118*_t169*_t248 - 0.2e1 / 0.9e1*_t118*_t309*_t432 + _t123*_t235*_t76 - 0.1e1 / 0.36e2*_t123*_t404 + _t129*_t381*_t382 + (0.7e1 / 0.9e1)*_t129*_t57 + _t133*_t244*_t282 + _t134*_t278*_t98 - 0.1e1 / 0.288e3*_t136*_t253*_t273*_t423 + (0.7e1 / 0.108e3)*_t149*_t85 + _t154*_t257*_t338*_t414 + (0.1e1 / 0.432e3)*_t157*_t254 - 0.1e1 / 0.36e2*_t157*_t257*_t425 + _t165*_t410*_t85 - _t173*_t421 + _t173*_t422 - _t177*_t421 + _t177*_t422 - 0.7e1 / 0.108e3*_t187*_t208*_t266*_t40 + _t2*_t201*_t259*_t415 + (0.1e1 / 0.192e3)*_t201*_t413*_t420 - _t202*_t261 + _t203*_t207*_t259 + (0.7e1 / 0.216e3)*_t204*_t267 - _t207*_t323*_t335*_t49 - _t215*_t233 - _t216*_t283*_t85 - 0.1e1 / 0.48e2*_t222*_t253*_t268 - _t223*_t260 + _t229*_t265*_t32*_t93 - _t229*_t285*_t293*_t92 - _t233*_t397 - _t234*_t295*_t83 + _t235*_t282*_t424 + _t236*(_t264*_t385*_t93 - 0.1e1 / 0.9e1*_t284*_t34 - _t286*_t289 + (0.5e1 / 0.72e2)*_t291 - 0.5e1 / 0.72e2*_t292 + (0.5e1 / 0.144e3)*_t294) + _t238*_t283*_t342 + _t246*_t380 - 0.7e1 / 0.9e1*_t247*_t349 - 0.1e1 / 0.6e1*_t248*_t359 + (0.7e1 / 0.216e3)*_t258*_t335 + _t278*_t431*_t75 + _t279*_t406 + _t279*_t407 - 0.1e1 / 0.6e1*_t293*_t348 + (0.1e1 / 0.54e2)*_t334*_t378*_t412 + _t336*_t383 + _t393*_t417 + (0.2e1 / 0.27e2)*_t416*_t418 - 0.1e1 / 0.27e2*_t416*_t419*_t91 - _t428*_t429 - _t428*_t433 + _t429*_t430 + _t430*_t433 - _t434*_t79 + _t99*((0.5e1 / 0.54e2)*_hc0[2]*_t11*_t12*_t129*_t54*_t6*_t7*_t8*_t85*_t9*p->cam_omega + (0.1e1 / 0.3e1)*_hc0[2]*_t11*_t12*_t188*_t2*_t394*_t6*_t7*_t9*_t91*p->cam_omega + (0.7e1 / 0.18e2)*_hc0[3]*_t11*_t12*_t208*_t40*_t6*_t7*_t8*_t9*p->cam_omega + (0.2e1 / 0.27e2)*_hc0[4]*_t11*_t12*_t2*_t394*_t6*_t7*_t8*_t9*p->cam_omega + (0.7e1 / 0.24e2)*_t11*_t12*_t187*_t188*_t208*_t40*_t6*_t7*_t9*p->cam_omega - 0.5e1 / 0.108e3*_t129*_t96 - 0.7e1 / 0.12e2*_t208*_t287 - 0.5e1 / 0.54e2*_t290*_t67 - _t372*_t417 - 0.5e1 / 0.36e2*_t375*_t416 - 0.1e1 / 0.9e1*_t377*_t416));
  const double d4F_dna_dgaa3 = _t333 + _t39*my_piecewise3(_t21, 0, _hc0[2]*_t112*_t159*_t442 - _hc0[3]*_t415*_t443 - 0.1e1 / 0.13824e5*_hc1[3]*_hc2[1]*_t108*_t142*_t208*_t256*_t326*_t9/xc_powr(M_PI, 11, 6) + _t10*_t325*_t326*_t330*_t37*_t450*_t85 + (0.1e1 / 0.64e2)*_t111*_t268*_t439 + (0.3e1 / 0.32e2)*_t114*_t134*_t432 + _t118*_t127*_t346 + (0.1e1 / 0.24e2)*_t118*_t214*_t301 + (0.1e1 / 0.64e2)*_t123*_t138*_t431 - _t126*_t288*_t384 + (0.1e1 / 0.8e1)*_t133*_t281*_t295 - _t138*_t308*_t424*_t92 - _t140*_t189*_t444*_t445 - _t142*_t43*_t451 + _t143*_t318*_t449 + _t145*_t33*_t451 - 0.1e1 / 0.24e2*_t154*_t259*_t412*_t91 + (0.1e1 / 0.96e2)*_t154*_t411*_t441 + (0.1e1 / 0.384e3)*_t157*_t323*_t443 - 0.1e1 / 0.1728e4*_t182*_t441*_t447 - _t2*_t250*_t335*_t418 - 0.1e1 / 0.9e1*_t2*_t393*_t444 - _t208*_t336*_t410 - _t218*_t435*_t69 - _t229*_t304*_t313*_t323 + _t229*_t321*_t8 - _t231*_t332 + _t249*_t436 + _t250*_t419*_t446 + _t256*_t312*_t448 - 0.1e1 / 0.192e3*_t263*_t298 + _t269*_t299*_t43 - 0.1e1 / 0.2e1*_t27*_t298*_t41 - _t271*_t301*_t303 + _t276*_t315 + (0.3e1 / 0.2e1)*_t279*_t434 + (0.1e1 / 0.2e1)*_t302*_t67 + _t304*_t306*_t448 - 0.1e1 / 0.64e2*_t306*_t420*_t443 - _t306*_t426*_t437*_t438 - _t320*_t449*_t55 - 0.1e1 / 0.768e3*_t329*_t414*_t438 + _t423*_t437*_t439 - _t428*_t452 + _t430*_t452 + _t99*((0.1e1 / 0.96e2)*_hc0[1]*_hc0[2]*_t11*_t12*_t126*_t203*_t6*_t7*_t9*_t93*p->cam_omega + (0.1e1 / 0.18e2)*_hc0[1]*_hc0[3]*_t11*_t12*_t129*_t2*_t335*_t6*_t7*_t9*_t93*p->cam_omega + (0.5e1 / 0.96e2)*_hc0[2]*_t11*_t118*_t12*_t301*_t54*_t6*_t7*_t8*_t9*p->cam_omega - 0.1e1 / 0.144e3*_hc0[3]*_t34*_t453 + (0.5e1 / 0.96e2)*_t11*_t12*_t129*_t2*_t335*_t373*_t374*_t6*_t7*_t9*p->cam_omega + (0.1e1 / 0.24e2)*_t11*_t12*_t129*_t2*_t335*_t376*_t6*_t7*_t9*_t93*p->cam_omega - 0.5e1 / 0.192e3*_t118*_t301*_t95 - 0.1e1 / 0.8e1*_t189*_t259*_t446 - 0.1e1 / 0.192e3*_t190*_t453 - 0.5e1 / 0.96e2*_t317*_t33*_t35 - 0.1e1 / 0.36e2*_t409*_t444));
  const double d4F_dgaa4 = _t39*my_piecewise3(_t21, 0, (0.1e1 / 0.18432e5)*(M_CBRT3 * M_CBRT3)*_t389*_t450*_t459*((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega))/((M_PI * M_PI)*(M_CBRTPI * M_CBRTPI)) - _hc0[3]*_t322*_t435 + _hc0[4]*_t442*_t460*_t47 - 0.15e2 / 0.16e2*_t128*_t454 + (0.3e1 / 0.256e3)*_t157*_t189*_t459*_t46 - _t157*_t331*_t388*_t419 - 0.5e1 / 0.64e2*_t2*_t316*_t454 + _t203*_t336*_t436 + (0.1e1 / 0.4608e4)*_t208*_t440*_t462 + (0.15e2 / 0.128e3)*_t214*_t461 - 0.1e1 / 0.768e3*_t256*_t298*_t328 - 0.3e1 / 0.4e1*_t297*_t298 - 0.3e1 / 0.128e3*_t298*_t311 - 0.9e1 / 0.32e2*_t298*_t322*_t395 + (0.1e1 / 0.16e2)*_t301*_t393*_t460 - _t307*_t456 + _t308*_t376*_t457 + (0.5e1 / 0.256e3)*_t310*_t455 + (0.5e1 / 0.64e2)*_t319*_t461 + _t324*_t456 + (0.15e2 / 0.16e2)*_t33*_t455*_t56 + _t331*_t418*_t460 + _t371*_t442*_t457 + (0.1e1 / 0.768e3)*_t378*_t387*_t462 + (0.3e1 / 0.128e3)*_t378*_t458*_t8 - 0.3e1 / 0.512e3*_t440*_t458);
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

  const double _t1 = xc_powr(gaa, 1, 2);
  const double _t2 = xc_powr(na, -4, 3);
  const double _t3 = -nb;
  const double _t4 = _t3 + na;
  const double _t5 = na + nb;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = _t4*_t6;
  const double _t8 = xc_powr(_t5, -1, 3);
  const double _t9 = (0.1e1 / 0.6e1)*_t8;
  const double _t12 = xc_powr(0.3e1, 1, 2);
  const double _t16 = xc_powr(M_PI, -1, 2);
  const double _t17 = xc_powr(M_CBRT3, 1, 2);
  const double _t18 = xc_powr(M_CBRTPI, -1, 2);
  const double _t19 = _t16*_t17*_t18*p->cam_omega;
  const double _t23 = xc_powr(0.6e1, 1, 3);
  const double _t24 = (0.1e1 / (M_CBRTPI));
  const double _t25 = _t23*_t24;
  const double _t26 = (0.1e1 / 0.2e1)*_t25*_t8;
  const double _t27 = xc_powr(gbb, 1, 2);
  const double _t28 = xc_powr(nb, -4, 3);
  const double _t37 = -p->dens_threshold + na <= 0;
  const double _t39 = -_t3 - p->dens_threshold <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ityh_enhancement_k, _KMAX)(p, _t1*_t2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, _t7, _hc1);
  const double _t10 = _hc1[0] + 0.1e1;
  const double _t11 = xc_powr(_t10, -1, 3);
  const double _t13 = (0.1e1 / (_hc0[0]));
  const double _t14 = xc_powr(_t13, -1, 2);
  const double _t15 = _t12*_t14;
  const double _t20 = _t15*_t19;
  const double _t21 = _t11*_t20;
  const double _t22 = _t21*_t9;
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t37)) XC_CAT(ityh_attenuation_k, _KMAX)(p, _t22, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t37)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t26, _hc1[0], _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ityh_enhancement_k, _KMAX)(p, _t27*_t28, _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t7, _hc5);
  const double _t29 = _hc5[0] + 0.1e1;
  const double _t30 = xc_powr(_t29, -1, 3);
  const double _t31 = (0.1e1 / (_hc4[0]));
  const double _t32 = xc_powr(_t31, -1, 2);
  const double _t33 = _t12*_t32;
  const double _t34 = _t19*_t33;
  const double _t35 = _t30*_t34;
  const double _t36 = _t35*_t9;
  const double _t38 = _hc0[0]*_hc2[0];
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t39)) XC_CAT(ityh_attenuation_k, _KMAX)(p, _t36, _hc6);
  double _hc7[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t39)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t26, _hc5[0], _hc7);
  const double _t40 = _hc4[0]*_hc6[0];
  const double _t41 = my_piecewise3(_t37, 0, _hc3[0]*_t38) + my_piecewise3(_t39, 0, _hc7[0]*_t40);
  const double zk = _t41;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t42 = xc_powr(_t5, -4, 3);
  const double _t43 = _t25*_t42;
  const double _t44 = (0.1e1 / 0.6e1)*_t43;
  const double _t46 = -_t6;
  const double _t47 = (0.1e1 / (_t5 * _t5));
  const double _t48 = _t4*_t47;
  const double _t49 = _t46 + _t48;
  const double _t53 = (0.1e1 / 0.18e2)*_t42;
  const double _t58 = (0.1e1 / 0.18e2)*_t8;
  const double _t65 = xc_powr(na, -7, 3);
  const double _t66 = _t1*_t65;
  const double _t67 = (0.4e1 / 0.3e1)*_t66;
  const double _t69 = -_t49;
  const double _t79 = (0.1e1 / 0.9e1)*_t8;
  const double _t88 = _t48 + _t6;
  const double _t89 = -_t88;
  const double _t98 = xc_powr(nb, -7, 3);
  const double _t99 = _t27*_t98;
  const double _t100 = (0.4e1 / 0.3e1)*_t99;
  const double _t112 = (0.1e1 / _t1);
  const double _t113 = (0.1e1 / 0.2e1)*_t112;
  const double _t118 = (0.1e1 / 0.24e2)*_t8;
  const double _t122 = (0.1e1 / _t27);
  const double _t123 = (0.1e1 / 0.2e1)*_t122;
  const double _t73 = _hc1[1]*_t69;
  const double _t74 = xc_powr(_t10, -4, 3);
  const double _t75 = _t20*_t74;
  const double _t76 = _t73*_t75;
  const double _t77 = _t58*_t76;
  const double _t78 = _t21*_t53;
  const double _t80 = _hc0[1]*_t66;
  const double _t81 = _t13*_t21;
  const double _t82 = _t80*_t81;
  const double _t83 = _t78 + _t79*_t82;
  const double _t84 = -_t77 - _t83;
  const double _t91 = _hc1[1]*_t89;
  const double _t92 = _t58*_t75;
  const double _t93 = -_t78 - _t91*_t92;
  const double _t114 = _hc0[1]*_t2;
  const double _t115 = _t112*_t114;
  const double _t119 = _t118*_t21;
  const double _t54 = _t35*_t53;
  const double _t55 = _hc5[1]*_t49;
  const double _t56 = xc_powr(_t29, -4, 3);
  const double _t57 = _t34*_t56;
  const double _t59 = _t57*_t58;
  const double _t60 = -_t54 - _t55*_t59;
  const double _t63 = _hc2[0]*_hc3[0];
  const double _t64 = _hc0[1]*_t63;
  const double _t68 = -_hc3[2]*_t44;
  const double _t70 = _hc1[1]*_hc3[1];
  const double _t71 = _t68 + _t69*_t70;
  const double _t72 = _hc0[0]*_hc3[0];
  const double _t85 = _hc2[1]*_t84;
  const double _t86 = my_piecewise3(_t37, 0, _t38*_t71 - _t64*_t67 + _t72*_t85);
  const double _t90 = _t68 + _t70*_t89;
  const double _t94 = _hc2[1]*_t72;
  const double _t95 = my_piecewise3(_t37, 0, _t38*_t90 + _t93*_t94);
  const double _t102 = _hc4[1]*_t99;
  const double _t103 = _t31*_t35;
  const double _t104 = _t102*_t103;
  const double _t105 = _hc5[1]*_t88;
  const double _t106 = _t105*_t59;
  const double _t107 = -_t104*_t79 - _t106 - _t54;
  const double _t111 = _t2*_t64;
  const double _t116 = _hc2[1]*_hc3[0];
  const double _t117 = _t115*_t116;
  const double _t120 = my_piecewise3(_t37, 0, _t111*_t113 + _t117*_t119);
  const double _t124 = _hc4[1]*_t28;
  const double _t125 = _t122*_t124;
  const double _t128 = _t118*_t35;
  const double _t45 = -_hc7[2]*_t44;
  const double _t50 = _hc5[1]*_hc7[1];
  const double _t51 = _t45 + _t49*_t50;
  const double _t52 = _hc4[0]*_hc7[0];
  const double _t61 = _hc6[1]*_t60;
  const double _t62 = my_piecewise3(_t39, 0, _t40*_t51 + _t52*_t61);
  const double _t87 = _t62 + _t86;
  const double _t96 = _hc6[0]*_hc7[0];
  const double _t97 = _hc4[1]*_t96;
  const double _t101 = _t45 + _t50*_t88;
  const double _t108 = _hc6[1]*_t52;
  const double _t109 = my_piecewise3(_t39, 0, -_t100*_t97 + _t101*_t40 + _t107*_t108);
  const double _t110 = _t109 + _t95;
  const double _t121 = _t28*_t97;
  const double _t126 = _hc6[1]*_t125;
  const double _t127 = _hc7[0]*_t126;
  const double _t129 = my_piecewise3(_t39, 0, _t121*_t123 + _t127*_t128);
  const double dF_dna = _t41 + _t5*_t87;
  const double dF_dnb = _t110*_t5 + _t41;
  const double dF_dgaa = _t120*_t5;
  const double dF_dgbb = _t129*_t5;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t134 = 0.2e1*_t47;
  const double _t135 = -_t134;
  const double _t136 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t137 = 0.2e1*_t136;
  const double _t138 = _t137*_t4;
  const double _t139 = _t135 + _t138;
  const double _t140 = -_t139;
  const double _t146 = (_t49 * _t49);
  const double _t148 = xc_powr(_t5, -7, 3);
  const double _t149 = (0.2e1 / 0.9e1)*_t148;
  const double _t150 = _t149*_t25;
  const double _t155 = (0.2e1 / 0.27e2)*_t148;
  const double _t158 = (0.1e1 / 0.27e2)*_t42;
  const double _t161 = (0.2e1 / 0.27e2)*_t8;
  const double _t170 = xc_powr(na, -14, 3);
  const double _t176 = xc_powr(na, -10, 3);
  const double _t177 = (0.28e2 / 0.9e1)*_t176;
  const double _t180 = (0.8e1 / 0.3e1)*_t66;
  const double _t191 = (_t69 * _t69);
  const double _t201 = (0.2e1 / 0.27e2)*_t42;
  const double _t218 = (0.4e1 / 0.27e2)*_t8;
  const double _t222 = (0.7e1 / 0.27e2)*_t8;
  const double _t223 = _t1*_t176;
  const double _t244 = xc_powr(_t5, -10, 3);
  const double _t245 = (0.1e1 / 0.9e1)*_t244;
  const double _t248 = (0.1e1 / 0.54e2)*_t42;
  const double _t252 = (0.1e1 / 0.27e2)*_t8;
  const double _t257 = _t49*_t88;
  const double _t288 = _t134 + _t138;
  const double _t289 = (_t89 * _t89);
  const double _t299 = xc_powr(nb, -14, 3);
  const double _t305 = xc_powr(nb, -10, 3);
  const double _t306 = (0.28e2 / 0.9e1)*_t305;
  const double _t308 = (0.8e1 / 0.3e1)*_t99;
  const double _t313 = -_t288;
  const double _t314 = (_t88 * _t88);
  const double _t329 = _t27*_t305;
  const double _t340 = xc_powr(na, -11, 3);
  const double _t342 = _t112*_t65;
  const double _t347 = _t113*_t2;
  const double _t353 = (0.1e1 / 0.72e2)*_t8;
  const double _t356 = (0.1e1 / 0.72e2)*_t42;
  const double _t367 = _t123*_t28;
  const double _t384 = xc_powr(nb, -11, 3);
  const double _t386 = _t122*_t98;
  const double _t402 = xc_powr(gaa, 3, 2);
  const double _t403 = (0.1e1 / _t402);
  const double _t404 = (0.1e1 / 0.4e1)*_t403;
  const double _t405 = xc_powr(na, -8, 3);
  const double _t408 = (0.1e1 / gaa);
  const double _t409 = (0.1e1 / 0.4e1)*_t408;
  const double _t414 = M_CBRT3*((p->cam_omega) * (p->cam_omega))/(M_PI*M_CBRTPI*xc_powr(_t5, 2, 3));
  const double _t418 = (0.1e1 / 0.48e2)*_t8;
  const double _t429 = xc_powr(gbb, 3, 2);
  const double _t430 = (0.1e1 / _t429);
  const double _t431 = (0.1e1 / 0.4e1)*_t430;
  const double _t432 = xc_powr(nb, -8, 3);
  const double _t435 = (0.1e1 / gbb);
  const double _t436 = (0.1e1 / 0.4e1)*_t435;
  const double _t181 = (_t84 * _t84);
  const double _t197 = _hc1[1]*_t139;
  const double _t198 = _t13*_t80;
  const double _t199 = _t198*_t76;
  const double _t200 = _t158*_t76;
  const double _t202 = _t201*_t82;
  const double _t203 = _t200 + _t202;
  const double _t204 = _t155*_t21;
  const double _t205 = _hc1[2]*_t191;
  const double _t206 = ((_hc1[1]) * (_hc1[1]));
  const double _t207 = xc_powr(_t10, -7, 3);
  const double _t208 = _t20*_t207;
  const double _t209 = _t206*_t208;
  const double _t210 = _t191*_t209;
  const double _t211 = _t161*_t210;
  const double _t212 = ((_hc0[1]) * (_hc0[1]));
  const double _t213 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t214 = _t21*_t213;
  const double _t215 = _t212*_t214;
  const double _t216 = _t170*_t215;
  const double _t217 = _t216*gaa;
  const double _t219 = _hc0[2]*_t170;
  const double _t220 = _t219*gaa;
  const double _t221 = _t220*_t81;
  const double _t224 = _hc0[1]*_t223;
  const double _t225 = _t224*_t81;
  const double _t226 = -_t161*_t217 + _t204 - _t205*_t92 + _t211 + _t218*_t221 + _t222*_t225;
  const double _t227 = _t161*_t199 - _t197*_t92 + _t203 + _t226;
  const double _t273 = _t248*_t76;
  const double _t274 = _t75*_t91;
  const double _t275 = _t248*_t274;
  const double _t276 = _hc1[2]*_t69;
  const double _t277 = _t276*_t89;
  const double _t278 = _t161*_t209;
  const double _t279 = _t278*_t69;
  const double _t280 = _t198*_t274;
  const double _t281 = _hc1[1]*_t75;
  const double _t282 = _t158*_t82 + _t204 - _t245*_t281*_t4;
  const double _t283 = _t252*_t280 + _t273 + _t275 - _t277*_t92 + _t279*_t89 + _t282;
  const double _t285 = (_t93 * _t93);
  const double _t292 = _hc1[1]*_t288;
  const double _t293 = _t158*_t274;
  const double _t294 = _hc1[2]*_t289;
  const double _t295 = _t209*_t289;
  const double _t296 = _t161*_t295 + _t204 - _t294*_t92;
  const double _t297 = -_t292*_t92 + _t293 + _t296;
  const double _t344 = _t212*_t340;
  const double _t345 = _t58*_t81;
  const double _t346 = _t344*_t345;
  const double _t351 = _t115*_t84;
  const double _t354 = _t115*_t13;
  const double _t355 = _t353*_t354;
  const double _t357 = _t115*_t81;
  const double _t358 = _t356*_t357;
  const double _t359 = _hc0[2]*_t340;
  const double _t360 = _t359*_t81;
  const double _t361 = _t360*_t58;
  const double _t362 = _hc0[1]*_t342;
  const double _t363 = _t362*_t81;
  const double _t364 = -0.1e1 / 0.36e2*_t11*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t340*_t8*p->cam_omega + _t358 + _t361 + _t363*_t58;
  const double _t365 = -_t355*_t76 - _t364;
  const double _t379 = -_t274*_t355 - _t358;
  const double _t412 = _t212*_t405;
  const double _t413 = (0.1e1 / 0.192e3)*_t412;
  const double _t415 = _t414/xc_powr(_t10, 2, 3);
  const double _t416 = _t413*_t415;
  const double _t417 = _t114*_t403;
  const double _t419 = _t21*_t418;
  const double _t420 = _t417*_t419;
  const double _t421 = _hc0[2]*_t405;
  const double _t425 = _t8*_t81;
  const double _t426 = (0.1e1 / 0.32e2)*_t425;
  const double _t427 = _t412*_t426;
  const double _t130 = (_t60 * _t60);
  const double _t154 = _hc5[1]*_t140;
  const double _t156 = _t155*_t35;
  const double _t157 = _hc5[2]*_t146;
  const double _t159 = _t55*_t57;
  const double _t160 = _t158*_t159;
  const double _t162 = ((_hc5[1]) * (_hc5[1]));
  const double _t163 = xc_powr(_t29, -7, 3);
  const double _t164 = _t163*_t34;
  const double _t165 = _t162*_t164;
  const double _t166 = _t161*_t165;
  const double _t167 = _t146*_t166 + _t156 - _t157*_t59 + _t160;
  const double _t168 = -_t154*_t59 + _t167;
  const double _t171 = _hc0[2]*_hc2[0];
  const double _t172 = _t170*_t171;
  const double _t173 = _t172*gaa;
  const double _t174 = (0.16e2 / 0.9e1)*_t173;
  const double _t175 = _t1*_t64;
  const double _t178 = _hc0[1]*_hc2[0];
  const double _t179 = _t178*_t71;
  const double _t182 = _hc2[2]*_t72;
  const double _t183 = _hc3[0]*_t85;
  const double _t184 = _hc0[1]*_t183;
  const double _t185 = _hc0[0]*_t85;
  const double _t186 = 0.2e1*_t185;
  const double _t187 = -_hc3[4]*_t44;
  const double _t188 = _hc3[3]*_t73 + _t187;
  const double _t189 = -_hc3[5]*_t44;
  const double _t190 = _hc3[4]*_t73 + _t189;
  const double _t192 = _hc1[2]*_hc3[1];
  const double _t193 = _hc3[2]*_t25;
  const double _t194 = _t149*_t193;
  const double _t195 = _t191*_t192 + _t194;
  const double _t196 = _t139*_t70 + _t188*_t73 - _t190*_t44 + _t195;
  const double _t228 = my_piecewise3(_t37, 0, _hc3[0]*_t174 + _t175*_t177 - _t179*_t180 - _t180*_t184 + _t181*_t182 + _t186*_t71 + _t196*_t38 + _t227*_t94);
  const double _t246 = _hc5[1]*_t57;
  const double _t247 = _t245*_t246;
  const double _t249 = _t105*_t57;
  const double _t250 = _t248*_t249;
  const double _t251 = _t159*_t248;
  const double _t253 = _t102*_t31;
  const double _t254 = _t159*_t253;
  const double _t255 = _hc5[2]*_t49;
  const double _t256 = _t255*_t88;
  const double _t258 = _t104*_t158 + _t156 + _t166*_t257 + _t247*_t4 + _t250 + _t251 + _t252*_t254 - _t256*_t59;
  const double _t260 = _t178*_t90;
  const double _t261 = _hc2[1]*_t93;
  const double _t262 = _hc3[0]*_t261;
  const double _t263 = _hc0[1]*_t262;
  const double _t264 = _hc0[0]*_hc2[1];
  const double _t265 = _t71*_t93;
  const double _t266 = _hc3[3]*_t91 + _t187;
  const double _t267 = _t192*_t69;
  const double _t268 = _t138*_t70;
  const double _t269 = _hc3[4]*_t91 + _t189;
  const double _t270 = _t194 - _t269*_t44;
  const double _t271 = _t266*_t73 + _t267*_t89 + _t268 + _t270;
  const double _t272 = _t182*_t84;
  const double _t284 = my_piecewise3(_t37, 0, _t185*_t90 - _t260*_t67 - _t263*_t67 + _t264*_t265 + _t271*_t38 + _t272*_t93 + _t283*_t94);
  const double _t286 = _t264*_t90;
  const double _t287 = 0.2e1*_t286;
  const double _t290 = _t192*_t289;
  const double _t291 = _t266*_t91 + _t270 + _t288*_t70 + _t290;
  const double _t298 = my_piecewise3(_t37, 0, _t182*_t285 + _t287*_t93 + _t291*_t38 + _t297*_t94);
  const double _t309 = (_t107 * _t107);
  const double _t317 = _hc5[1]*_t313;
  const double _t318 = _hc5[2]*_t314;
  const double _t319 = _t166*_t314;
  const double _t320 = ((_hc4[1]) * (_hc4[1]));
  const double _t321 = (0.1e1 / ((_hc4[0]) * (_hc4[0])));
  const double _t322 = _t321*_t35;
  const double _t323 = _t320*_t322;
  const double _t324 = _t299*_t323;
  const double _t325 = _t324*gbb;
  const double _t326 = _hc4[2]*_t299;
  const double _t327 = _t326*gbb;
  const double _t328 = _t103*_t327;
  const double _t330 = _hc4[1]*_t329;
  const double _t331 = _t103*_t330;
  const double _t332 = _t249*_t253;
  const double _t333 = _t158*_t249;
  const double _t334 = _t104*_t201 + _t333;
  const double _t335 = _t156 - _t161*_t325 + _t161*_t332 + _t218*_t328 + _t222*_t331 - _t318*_t59 + _t319 + _t334;
  const double _t336 = -_t317*_t59 + _t335;
  const double _t339 = (0.2e1 / 0.3e1)*_hc3[0];
  const double _t341 = _t171*_t340;
  const double _t343 = _t178*_t342;
  const double _t348 = _hc2[1]*_t115;
  const double _t349 = _t348*_t71;
  const double _t350 = _hc2[2]*_hc3[0];
  const double _t352 = _t350*_t351;
  const double _t366 = my_piecewise3(_t37, 0, -_t116*_t346 + _t119*_t349 + _t119*_t352 + _t179*_t347 + _t184*_t347 - _t339*_t341 - _t339*_t343 + _t365*_t94);
  const double _t369 = _t103*_t125;
  const double _t370 = _t356*_t369;
  const double _t371 = _t125*_t31;
  const double _t372 = _t353*_t371;
  const double _t373 = -_t159*_t372 - _t370;
  const double _t378 = _t348*_t90;
  const double _t380 = _t350*_t93;
  const double _t381 = _t115*_t380;
  const double _t382 = my_piecewise3(_t37, 0, _t119*_t378 + _t119*_t381 + _t260*_t347 + _t263*_t347 + _t379*_t94);
  const double _t388 = _t103*_t58;
  const double _t389 = _t320*_t384;
  const double _t395 = _hc4[2]*_t384;
  const double _t396 = _t103*_t395;
  const double _t397 = _t396*_t58;
  const double _t398 = _hc4[1]*_t386;
  const double _t399 = _t103*_t398;
  const double _t400 = (0.1e1 / 0.36e2)*_t12*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t384*_t8*p->cam_omega - _t249*_t372 - _t370 - _t397 - _t399*_t58;
  const double _t406 = _hc3[0]*_t171;
  const double _t407 = _t405*_t406;
  const double _t410 = _hc3[0]*_t408;
  const double _t411 = _hc2[2]*_t410;
  const double _t422 = _hc2[1]*_t421;
  const double _t423 = _t419*_t422;
  const double _t424 = _hc2[1]*_t410;
  const double _t428 = my_piecewise3(_t37, 0, -_t111*_t404 - _t116*_t420 + _t407*_t409 + _t410*_t423 + _t411*_t416 + _t424*_t427);
  const double _t437 = _t320*_t432;
  const double _t438 = (0.1e1 / 0.192e3)*_t437;
  const double _t440 = _t414/xc_powr(_t29, 2, 3);
  const double _t443 = _t124*_t430;
  const double _t447 = _hc4[2]*_t432;
  const double _t450 = _t103*_t8;
  const double _t131 = _hc6[2]*_t52;
  const double _t132 = _hc4[0]*_t51;
  const double _t133 = 0.2e1*_t132;
  const double _t141 = -_hc7[5]*_t44;
  const double _t142 = _hc7[4]*_t55;
  const double _t143 = _t141 + _t142;
  const double _t144 = -_hc7[4]*_t44;
  const double _t145 = _hc7[3]*_t55 + _t144;
  const double _t147 = _hc5[2]*_hc7[1];
  const double _t151 = _hc7[2]*_t150;
  const double _t152 = _t145*_t55 + _t146*_t147 + _t151;
  const double _t153 = _t140*_t50 - _t143*_t44 + _t152;
  const double _t169 = my_piecewise3(_t39, 0, _t108*_t168 + _t130*_t131 + _t133*_t61 + _t153*_t40);
  const double _t229 = _t169 + _t228;
  const double _t230 = _hc4[1]*_hc6[0];
  const double _t231 = _t230*_t51;
  const double _t232 = _hc7[0]*_t61;
  const double _t233 = _hc4[1]*_t232;
  const double _t234 = _hc4[0]*_t101;
  const double _t235 = _hc6[1]*_t107;
  const double _t236 = _hc7[4]*_t105;
  const double _t237 = _t141 + _t236;
  const double _t238 = _t151 - _t237*_t44;
  const double _t239 = _hc7[3]*_t105 + _t144;
  const double _t240 = _t147*_t49;
  const double _t241 = -_t138*_t50 + _t239*_t55 + _t240*_t88;
  const double _t242 = _t238 + _t241;
  const double _t243 = _t131*_t60;
  const double _t259 = my_piecewise3(_t39, 0, -_t100*_t231 - _t100*_t233 + _t107*_t243 + _t108*_t258 + _t132*_t235 + _t234*_t61 + _t242*_t40);
  const double _t300 = _hc4[2]*_hc6[0];
  const double _t301 = _t299*_t300;
  const double _t302 = _t301*gbb;
  const double _t303 = (0.16e2 / 0.9e1)*_t302;
  const double _t304 = _t27*_t97;
  const double _t307 = _t101*_t230;
  const double _t310 = _hc7[0]*_t235;
  const double _t311 = _hc4[1]*_t310;
  const double _t312 = 0.2e1*_t234;
  const double _t315 = _t105*_t239 + _t147*_t314;
  const double _t316 = _t238 + _t313*_t50 + _t315;
  const double _t337 = my_piecewise3(_t39, 0, _hc7[0]*_t303 + _t108*_t336 + _t131*_t309 + _t235*_t312 + _t304*_t306 - _t307*_t308 - _t308*_t311 + _t316*_t40);
  const double _t338 = _t298 + _t337;
  const double _t368 = _t126*_t51;
  const double _t374 = _hc6[2]*_t60;
  const double _t375 = _hc7[0]*_t125;
  const double _t376 = _t128*_t375;
  const double _t377 = my_piecewise3(_t39, 0, _t108*_t373 + _t128*_t368 + _t231*_t367 + _t233*_t367 + _t374*_t376);
  const double _t383 = (0.2e1 / 0.3e1)*_hc7[0];
  const double _t385 = _t300*_t384;
  const double _t387 = _t230*_t386;
  const double _t390 = _hc6[1]*_t389;
  const double _t391 = _t388*_t390;
  const double _t392 = _t101*_t125;
  const double _t393 = _hc6[1]*_t392;
  const double _t394 = _hc6[2]*_t107;
  const double _t401 = my_piecewise3(_t39, 0, -_hc7[0]*_t391 + _t108*_t400 + _t128*_t393 + _t307*_t367 + _t311*_t367 + _t376*_t394 - _t383*_t385 - _t383*_t387);
  const double _t433 = _hc7[0]*_t300;
  const double _t434 = _t432*_t433;
  const double _t439 = _hc7[0]*_t435;
  const double _t441 = _hc6[2]*_t440;
  const double _t442 = _t439*_t441;
  const double _t444 = _hc7[0]*_t443;
  const double _t445 = _hc6[1]*_t35;
  const double _t446 = _t418*_t445;
  const double _t448 = _t439*_t447;
  const double _t449 = _t437*_t439;
  const double _t451 = _hc6[1]*_t450;
  const double _t452 = (0.1e1 / 0.32e2)*_t451;
  const double _t453 = my_piecewise3(_t39, 0, -_t121*_t431 + _t434*_t436 + _t438*_t442 - _t444*_t446 + _t446*_t448 + _t449*_t452);
  const double d2F_dna2 = _t229*_t5 + 0.2e1*_t62 + 0.2e1*_t86;
  const double d2F_dna_dnb = _t110 + _t5*(_t259 + _t284) + _t87;
  const double d2F_dnb2 = 0.2e1*_t109 + _t338*_t5 + 0.2e1*_t95;
  const double d2F_dna_dgaa = _t120 + _t366*_t5;
  const double d2F_dna_dgbb = _t129 + _t377*_t5;
  const double d2F_dnb_dgaa = _t120 + _t382*_t5;
  const double d2F_dnb_dgbb = _t129 + _t401*_t5;
  const double d2F_dgaa2 = _t428*_t5;
  const double d2F_dgbb2 = _t453*_t5;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double _t463 = (0.4e1 / 0.27e2)*_t148;
  const double _t468 = (0.14e2 / 0.27e2)*_t244;
  const double _t469 = _t25*_t468;
  const double _t471 = 0.6e1*_t136;
  const double _t472 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t473 = _t4*_t472;
  const double _t474 = 0.6e1*_t473;
  const double _t475 = -_t471 + _t474;
  const double _t476 = (_t49 * _t49 * _t49);
  const double _t478 = 0.4e1*_t47;
  const double _t479 = 0.4e1*_t136;
  const double _t480 = _t4*_t479;
  const double _t481 = -_t478 + _t480;
  const double _t482 = -_t481;
  const double _t483 = (0.4e1 / 0.9e1)*_t148;
  const double _t484 = _t25*_t483;
  const double _t497 = (0.14e2 / 0.81e2)*_t244;
  const double _t501 = (0.14e2 / 0.81e2)*_t8;
  const double _t508 = xc_powr(na, -17, 3);
  const double _t510 = (0.112e3 / 0.9e1)*gaa;
  const double _t511 = xc_powr(na, -13, 3);
  const double _t512 = (0.280e3 / 0.27e2)*_t511;
  const double _t514 = xc_powi(na, -7);
  const double _t515 = _t402*_t514;
  const double _t516 = (0.64e2 / 0.27e2)*_t515;
  const double _t518 = (0.16e2 / 0.3e1)*gaa;
  const double _t520 = (0.28e2 / 0.3e1)*_t176;
  const double _t524 = _t1*_t520;
  const double _t526 = 0.4e1*_t66;
  const double _t528 = -_t4*_t47;
  const double _t529 = _t528 + _t6;
  const double _t546 = (0.4e1 / 0.27e2)*_t42;
  const double _t547 = (0.8e1 / 0.27e2)*_t8;
  const double _t548 = (0.14e2 / 0.27e2)*_t8;
  const double _t552 = -_t475;
  const double _t553 = (_t69 * _t69 * _t69);
  const double _t574 = _t508*gaa;
  const double _t575 = _t574*_t8;
  const double _t578 = _t1*_t511;
  const double _t581 = (0.16e2 / 0.81e2)*_t515;
  const double _t614 = (0.2e1 / 0.9e1)*_t244;
  const double _t618 = -0.2e1*_t136 + _t474;
  const double _t632 = xc_powr(_t5, -13, 3);
  const double _t633 = (0.2e1 / 0.27e2)*_t632;
  const double _t635 = (0.2e1 / 0.81e2)*_t148;
  const double _t636 = (0.2e1 / 0.81e2)*_t42;
  const double _t637 = (0.4e1 / 0.81e2)*_t148;
  const double _t642 = (0.8e1 / 0.27e2)*_t244;
  const double _t648 = (0.4e1 / 0.81e2)*_t42;
  const double _t654 = (0.16e2 / 0.9e1)*gaa;
  const double _t655 = _t1*_t177;
  const double _t658 = _t46 + _t528;
  const double _t677 = -_t618;
  const double _t692 = _t139*_t89;
  const double _t694 = _t191*_t658;
  const double _t706 = (0.8e1 / 0.81e2)*_t148;
  const double _t726 = _t289*_t529;
  const double _t741 = _t27*_t306;
  const double _t743 = (0.16e2 / 0.9e1)*gbb;
  const double _t753 = _t314*_t49;
  const double _t780 = _t471 + _t474;
  const double _t781 = -_t780;
  const double _t782 = (_t89 * _t89 * _t89);
  const double _t785 = _t478 + _t480;
  const double _t792 = xc_powr(nb, -17, 3);
  const double _t794 = (0.112e3 / 0.9e1)*gbb;
  const double _t795 = xc_powr(nb, -13, 3);
  const double _t796 = (0.280e3 / 0.27e2)*_t795;
  const double _t798 = xc_powi(nb, -7);
  const double _t799 = _t429*_t798;
  const double _t800 = (0.64e2 / 0.27e2)*_t799;
  const double _t802 = (0.16e2 / 0.3e1)*gbb;
  const double _t804 = (0.28e2 / 0.3e1)*_t305;
  const double _t807 = _t27*_t804;
  const double _t808 = 0.4e1*_t99;
  const double _t821 = (_t88 * _t88 * _t88);
  const double _t822 = -_t785;
  const double _t824 = _t792*gbb;
  const double _t829 = _t27*_t795;
  const double _t850 = (0.14e2 / 0.9e1)*_t176;
  const double _t852 = xc_powi(na, -6);
  const double _t853 = (0.8e1 / 0.9e1)*_t852;
  const double _t858 = _t1*_t852;
  const double _t859 = _t161*_t858;
  const double _t862 = (0.4e1 / 0.3e1)*_t342;
  const double _t873 = (0.1e1 / 0.12e2)*_t8;
  const double _t878 = (0.1e1 / 0.36e2)*_t42;
  const double _t880 = (0.1e1 / 0.36e2)*_t8;
  const double _t884 = (0.1e1 / 0.54e2)*_t148;
  const double _t886 = (0.5e1 / 0.36e2)*_t8;
  const double _t887 = (0.5e1 / 0.18e2)*_t8;
  const double _t891 = _t112*_t176;
  const double _t892 = (0.7e1 / 0.54e2)*_t891;
  const double _t896 = (0.1e1 / 0.54e2)*_t8;
  const double _t905 = (0.1e1 / 0.108e3)*_t42;
  const double _t943 = (0.1e1 / 0.216e3)*_t42;
  const double _t944 = (0.1e1 / 0.108e3)*_t8;
  const double _t986 = (0.14e2 / 0.9e1)*_t305;
  const double _t988 = xc_powi(nb, -6);
  const double _t989 = (0.8e1 / 0.9e1)*_t988;
  const double _t997 = _t27*_t988;
  const double _t998 = _t161*_t997;
  const double _t999 = (0.4e1 / 0.3e1)*_t386;
  const double _t1012 = _t122*_t305;
  const double _t1013 = (0.7e1 / 0.54e2)*_t1012;
  const double _t1026 = (0.1e1 / 0.3e1)*_t65;
  const double _t1028 = xc_powi(na, -5);
  const double _t1029 = _t1028*_t112;
  const double _t1030 = (0.1e1 / 0.3e1)*_t1029;
  const double _t1031 = (0.1e1 / 0.144e3)*_t1029;
  const double _t1035 = _t1029*_t873;
  const double _t1036 = _t1029*_t353;
  const double _t1041 = _t2*_t404;
  const double _t1043 = _t405*_t409;
  const double _t1058 = _t403*_t65;
  const double _t1066 = (0.1e1 / 0.288e3)*_t8;
  const double _t1070 = (0.1e1 / 0.144e3)*_t42;
  const double _t1073 = (0.1e1 / 0.288e3)*_t42;
  const double _t1078 = _t28*_t431;
  const double _t1080 = _t432*_t436;
  const double _t1117 = (0.1e1 / 0.3e1)*_t98;
  const double _t1119 = xc_powi(nb, -5);
  const double _t1120 = _t1119*_t122;
  const double _t1121 = (0.1e1 / 0.3e1)*_t1120;
  const double _t1126 = _t1120*_t873;
  const double _t1139 = _t430*_t98;
  const double _t1147 = xc_powr(gaa, -5, 2);
  const double _t1148 = (0.3e1 / 0.8e1)*_t1147;
  const double _t1149 = (gaa * gaa);
  const double _t1150 = (0.1e1 / _t1149);
  const double _t1151 = (0.3e1 / 0.8e1)*_t1150;
  const double _t1152 = (0.1e1 / (na * na * na * na));
  const double _t1154 = (0.1e1 / 0.8e1)*_t403;
  const double _t1156 = _t1152*_t403;
  const double _t1162 = (0.1e1 / 0.32e2)*_t8;
  const double _t1166 = (0.1e1 / 0.96e2)*_t8;
  const double _t1169 = (0.3e1 / 0.64e2)*_t8;
  const double _t1170 = _t1156*_t1169;
  const double _t1172 = (0.1e1 / 0.128e3)*_t1156;
  const double _t1176 = xc_powr(M_CBRT3, 3, 2)*_t6*((p->cam_omega) * (p->cam_omega) * (p->cam_omega))/(xc_powr(M_PI, 3, 2)*xc_powr(M_CBRTPI, 3, 2));
  const double _t1177 = (0.1e1 / 0.4608e4)*_t1176;
  const double _t1180 = xc_powr(gbb, -5, 2);
  const double _t1181 = (0.3e1 / 0.8e1)*_t1180;
  const double _t1182 = (gbb * gbb);
  const double _t1183 = (0.1e1 / _t1182);
  const double _t1184 = (0.3e1 / 0.8e1)*_t1183;
  const double _t1185 = (0.1e1 / (nb * nb * nb * nb));
  const double _t1187 = (0.1e1 / 0.8e1)*_t430;
  const double _t1188 = _t1185*_t430;
  const double _t1189 = (0.1e1 / 0.128e3)*_t1188;
  const double _t1196 = (0.1e1 / 0.256e3)*_t1188;
  const double _t1204 = _t1169*_t1188;
  const double _t1212 = _t1177*_t1188;
  const double _t521 = (_t84 * _t84 * _t84);
  const double _t527 = _hc0[1]*_t526;
  const double _t535 = 0.8e1*_t80;
  const double _t541 = _t197*_t75;
  const double _t542 = _t201*_t76;
  const double _t543 = _t21*_t463;
  const double _t544 = _t205*_t75;
  const double _t545 = _t210*_t218;
  const double _t549 = -_t217*_t218 + _t221*_t547 + _t225*_t548 + _t543 - _t544*_t79 + _t545 + _t546*_t82;
  const double _t550 = _t199*_t218 - _t541*_t79 + _t542 + _t549;
  const double _t558 = 0.2e1*_t205;
  const double _t559 = 0.2e1*_t197;
  const double _t572 = _t21*_t497;
  const double _t573 = _hc0[2]*_t81;
  const double _t576 = _t573*_t575;
  const double _t577 = _hc0[1]*_t425;
  const double _t579 = _t577*_t578;
  const double _t580 = _t225*_t42;
  const double _t582 = _hc0[3]*_t425;
  const double _t583 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t584 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t585 = _t583*_t584;
  const double _t586 = _t21*_t585;
  const double _t587 = _t515*_t586;
  const double _t588 = _t281*_t58;
  const double _t589 = _hc1[3]*_t553;
  const double _t590 = xc_powr(_t10, -10, 3);
  const double _t591 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t20*_t590;
  const double _t592 = _t553*_t591;
  const double _t593 = _t13*_t76;
  const double _t594 = _t220*_t593;
  const double _t595 = _t224*_t593;
  const double _t596 = _t276*_t92;
  const double _t597 = (0.8e1 / 0.27e2)*_hc0[1]*_hc0[2]*_t11*_t12*_t14*_t16*_t17*_t18*_t213*_t402*_t514*_t8*p->cam_omega + (0.1e1 / 0.9e1)*_hc0[1]*_hc1[1]*_t1*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t65*_t74*_t8*p->cam_omega + (0.1e1 / 0.9e1)*_hc0[1]*_hc1[2]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t65*_t74*_t8*p->cam_omega + (0.2e1 / 0.9e1)*_hc1[1]*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t207*_t553*_t8*p->cam_omega + (0.1e1 / 0.18e2)*_hc1[1]*_t12*_t139*_t14*_t16*_t17*_t18*_t42*_t74*p->cam_omega + (0.2e1 / 0.27e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t69*_t74*_t8*p->cam_omega*gaa + (0.1e1 / 0.18e2)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t191*_t42*_t74*p->cam_omega + (0.2e1 / 0.27e2)*_t11*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t42*p->cam_omega*gaa + (0.14e2 / 0.27e2)*_t11*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t508*_t8*p->cam_omega*gaa + (0.2e1 / 0.27e2)*_t12*_t139*_t14*_t16*_t17*_t18*_t206*_t207*_t69*_t8*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t481*_t69*_t8*p->cam_omega - _t139*_t596 - _t155*_t76 - _t198*_t542 - _t198*_t543 - _t198*_t545 - _t201*_t210 - _t218*_t587 - _t218*_t594 - _t221*_t546 - _t222*_t595 - _t481*_t596 - _t501*_t592 - _t552*_t588 - _t572 - 0.28e2 / 0.27e2*_t576 - 0.70e2 / 0.81e2*_t579 - 0.7e1 / 0.27e2*_t580 - _t581*_t582 - _t589*_t92;
  const double _t657 = _hc0[1]*_t180;
  const double _t663 = _hc1[1]*_t658;
  const double _t664 = -_t663*_t92 - _t78;
  const double _t672 = _t75*_t79;
  const double _t673 = _t209*_t69;
  const double _t674 = _t673*_t89;
  const double _t675 = _t161*_t280 + _t203 + _t218*_t674 - _t277*_t672 - _t281*_t4*_t614 + _t293 + _t543;
  const double _t693 = _hc1[2]*_t92;
  const double _t695 = _hc1[3]*_t92;
  const double _t696 = _t276*_t75;
  const double _t697 = _t614*_t696;
  const double _t698 = _t501*_t591;
  const double _t699 = _t274*_t8;
  const double _t700 = _t13*_t699;
  const double _t701 = _t220*_t700;
  const double _t702 = (0.7e1 / 0.81e2)*_t224;
  const double _t703 = _t198*_t8;
  const double _t704 = (0.8e1 / 0.81e2)*_t703;
  const double _t705 = -0.1e1 / 0.27e2*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t42*_t69*_t74*_t89*p->cam_omega + _t280*_t636 + _t572 + _t648*_t674;
  const double _t707 = _t637*_t76 + _t706*_t82;
  const double _t708 = (0.4e1 / 0.27e2)*_hc0[1]*_hc1[1]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t244*_t4*_t65*_t74*p->cam_omega + (0.2e1 / 0.27e2)*_hc0[1]*_hc1[2]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t65*_t69*_t74*_t8*_t89*p->cam_omega + (0.2e1 / 0.9e1)*_hc1[1]*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t191*_t207*_t658*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc1[1]*_t12*_t139*_t14*_t16*_t17*_t18*_t42*_t74*p->cam_omega + (0.2e1 / 0.81e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t74*_t8*_t89*p->cam_omega*gaa + (0.2e1 / 0.27e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t4*_t632*_t74*p->cam_omega + (0.1e1 / 0.54e2)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t191*_t42*_t74*p->cam_omega + (0.2e1 / 0.81e2)*_t11*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t42*p->cam_omega*gaa + (0.2e1 / 0.27e2)*_t12*_t139*_t14*_t16*_t17*_t18*_t206*_t207*_t8*_t89*p->cam_omega + (0.8e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t244*_t4*_t69*p->cam_omega - _t199*_t636 - _t210*_t636 - _t221*_t648 - _t274*_t635 - _t4*_t697 - 0.7e1 / 0.81e2*_t580 - _t588*_t677 - _t674*_t704 - _t692*_t693 - _t694*_t695 - _t694*_t698 - _t700*_t702 - 0.4e1 / 0.81e2*_t701 - _t705 - _t707;
  const double _t711 = _hc0[1]*_t67;
  const double _t716 = _hc1[1]*_t529;
  const double _t717 = -_t716*_t92 - _t83;
  const double _t720 = 0.2e1*_t93;
  const double _t727 = 0.2e1*_t277;
  const double _t732 = _t274*_t637;
  const double _t733 = _hc1[3]*_t726;
  const double _t734 = _hc1[2]*_t75;
  const double _t735 = _t734*_t89;
  const double _t736 = _t4*_t735;
  const double _t737 = _t295*_t8;
  const double _t738 = _t198*_t737;
  const double _t739 = (0.1e1 / 0.27e2)*_hc0[1]*_hc1[1]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t288*_t65*_t74*_t8*p->cam_omega + (0.1e1 / 0.27e2)*_hc0[1]*_hc1[2]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t289*_t65*_t74*_t8*p->cam_omega + (0.2e1 / 0.9e1)*_hc1[1]*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t207*_t289*_t529*_t8*p->cam_omega + (0.1e1 / 0.9e1)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t244*_t74*p->cam_omega + (0.1e1 / 0.54e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t288*_t42*_t74*p->cam_omega + (0.11e2 / 0.27e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t4*_t632*_t74*p->cam_omega + (0.1e1 / 0.54e2)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t289*_t42*_t74*p->cam_omega + (0.8e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t244*_t4*_t89*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t288*_t69*_t8*p->cam_omega - _t288*_t596 - _t295*_t636 - _t614*_t736 - _t635*_t76 - _t637*_t82 - _t698*_t726 - _t705 - _t732 - _t733*_t92 - 0.4e1 / 0.81e2*_t738;
  const double _t774 = (_t93 * _t93 * _t93);
  const double _t778 = _t218*_t295 - _t294*_t672 + _t543;
  const double _t779 = _t201*_t274 - _t292*_t672 + _t778;
  const double _t784 = 0.2e1*_t294;
  const double _t787 = _hc1[3]*_t782;
  const double _t788 = _t591*_t782;
  const double _t789 = _t693*_t89;
  const double _t790 = (0.2e1 / 0.9e1)*_hc1[1]*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t207*_t782*_t8*p->cam_omega + (0.1e1 / 0.18e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t288*_t42*_t74*p->cam_omega + (0.1e1 / 0.18e2)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t289*_t42*_t74*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t288*_t8*_t89*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t785*_t8*_t89*p->cam_omega - _t155*_t274 - _t201*_t295 - _t288*_t789 - _t501*_t788 - _t572 - _t588*_t781 - _t785*_t789 - _t787*_t92;
  const double _t855 = _t170*_t212;
  const double _t856 = (0.7e1 / 0.54e2)*_t855;
  const double _t864 = _t344*_t81;
  const double _t865 = _t79*_t864;
  const double _t866 = (0.4e1 / 0.3e1)*_t359;
  const double _t867 = _hc0[1]*_t347;
  const double _t870 = _t115*_t119;
  const double _t874 = _t21*_t873;
  const double _t879 = _t357*_t878;
  const double _t881 = _t354*_t76;
  const double _t882 = (0.1e1 / 0.18e2)*_t11*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t340*_t8*p->cam_omega - _t360*_t79 - _t363*_t79 - _t879 - _t880*_t881;
  const double _t885 = _t357*_t884;
  const double _t888 = _t219*_t81;
  const double _t889 = _t586*_t858;
  const double _t890 = _hc0[3]*_t81;
  const double _t893 = _hc0[1]*_hc0[2];
  const double _t894 = _t214*_t893;
  const double _t895 = _t858*_t894;
  const double _t897 = _t213*_t344;
  const double _t898 = _t76*_t897;
  const double _t899 = _t13*_t359;
  const double _t900 = _t76*_t899;
  const double _t901 = _t13*_t362;
  const double _t902 = _t76*_t901;
  const double _t903 = _t354*_t896;
  const double _t904 = _t214*_t344;
  const double _t906 = _t158*_t360 + _t158*_t363 - _t248*_t904 + _t881*_t905;
  const double _t907 = _t210*_t903 - _t216*_t886 + _t252*_t900 + _t252*_t902 - _t355*_t541 - _t355*_t544 + _t577*_t892 + _t58*_t889 - _t79*_t895 + _t859*_t890 + _t885 + _t887*_t888 - _t896*_t898 + _t906;
  const double _t935 = _t119*_t351;
  const double _t936 = _t351*_t93;
  const double _t938 = _t904*_t905;
  const double _t939 = _t281*_t4;
  const double _t940 = _t244*_t939;
  const double _t941 = _t354*_t940;
  const double _t942 = _t274*_t899;
  const double _t945 = _t274*_t897;
  const double _t946 = _t274*_t896;
  const double _t947 = _t274*_t354;
  const double _t948 = _t277*_t75;
  const double _t949 = _t248*_t360 + _t248*_t363 - _t355*_t948 + _t674*_t903 + _t881*_t943 + _t885 + _t896*_t942 + _t901*_t946 - _t938 - 0.1e1 / 0.36e2*_t941 + _t943*_t947 - _t944*_t945;
  const double _t976 = _t115*_t874;
  const double _t978 = -_t879 - _t880*_t947;
  const double _t979 = _t905*_t947;
  const double _t980 = _t292*_t75;
  const double _t981 = _t294*_t75;
  const double _t982 = _t295*_t903 - _t355*_t980 - _t355*_t981 + _t885 + _t979;
  const double _t1033 = _t13*_t584;
  const double _t1037 = _t214*_t584;
  const double _t1039 = _t81*_t880;
  const double _t1040 = _t1039*_t344;
  const double _t1047 = _t114*_t404;
  const double _t1048 = _hc0[2]*_t1043;
  const double _t1051 = _t421*_t84;
  const double _t1054 = _t115*_t365;
  const double _t1055 = _t1054*_t874;
  const double _t1056 = _hc0[3]*_t1029;
  const double _t1057 = _t1029*_t586;
  const double _t1059 = _hc0[1]*_t1058;
  const double _t1060 = _t408*_t904;
  const double _t1061 = _t1029*_t894;
  const double _t1062 = _t408*_t421;
  const double _t1063 = (0.1e1 / 0.144e3)*_t1062;
  const double _t1064 = _t593*_t8;
  const double _t1065 = (0.1e1 / 0.144e3)*_t417;
  const double _t1067 = _t408*_t412;
  const double _t1068 = _t213*_t76;
  const double _t1069 = _t1067*_t1068;
  const double _t1071 = _t1062*_t81;
  const double _t1072 = _t417*_t81;
  const double _t1074 = _t1067*_t214;
  const double _t1075 = -_t1070*_t1071 + _t1070*_t1072 + _t1073*_t1074;
  const double _t1076 = -_t1039*_t1056 + _t1039*_t1059 - _t1057*_t418 + _t1060*_t353 + _t1061*_t118 - _t1063*_t1064 + _t1064*_t1065 + _t1066*_t1069 + _t1075 - _t360*_t408*_t880;
  const double _t1112 = _t1067*_t213;
  const double _t1113 = _t1112*_t699;
  const double _t1114 = -_t1063*_t700 + _t1065*_t700 + _t1075 + (0.1e1 / 0.288e3)*_t1113;
  const double _t1157 = _t1156*_t893;
  const double _t1158 = _t1150*_t412;
  const double _t1160 = _t1033*_t1156;
  const double _t1161 = _t114*_t1147;
  const double _t1165 = _t1150*_t421;
  const double _t1167 = _hc0[3]*_t1156;
  const double _t1168 = _t1166*_t1167;
  const double _t1173 = (0.3e1 / 0.64e2)*_t1158;
  const double _t1174 = _t15/_t10;
  const double _t1178 = _t1160*_t1177;
  const double _t454 = (_t60 * _t60 * _t60);
  const double _t462 = _t57*_t79;
  const double _t464 = _t35*_t463;
  const double _t465 = _t146*_t165;
  const double _t466 = -_t157*_t462 + _t159*_t201 + _t218*_t465 + _t464;
  const double _t467 = -_t154*_t462 + _t466;
  const double _t498 = _t35*_t497;
  const double _t499 = _hc5[1]*_t475;
  const double _t500 = _hc5[3]*_t476;
  const double _t502 = _t34/xc_powr(_t29, 10, 3);
  const double _t503 = ((_hc5[1]) * (_hc5[1]) * (_hc5[1]))*_t502;
  const double _t504 = _t501*_t503;
  const double _t505 = _t255*_t59;
  const double _t506 = (0.2e1 / 0.9e1)*_hc5[1]*_hc5[2]*_t12*_t16*_t163*_t17*_t18*_t32*_t476*_t8*p->cam_omega + (0.1e1 / 0.18e2)*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.18e2)*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t32*_t42*_t56*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t140*_t16*_t162*_t163*_t17*_t18*_t32*_t49*_t8*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t32*_t482*_t49*_t8*p->cam_omega - _t140*_t505 - _t155*_t159 - _t201*_t465 - _t476*_t504 - _t482*_t505 - _t498 - _t499*_t59 - _t500*_t59;
  const double _t509 = _t406*_t508;
  const double _t513 = _hc0[3]*_t63;
  const double _t517 = _t172*_t71;
  const double _t519 = _t1*_t179;
  const double _t522 = _hc2[3]*_t72;
  const double _t523 = _t183*_t219;
  const double _t525 = _t181*_t350;
  const double _t530 = _t529*_t70 + _t68;
  const double _t531 = _hc0[0]*_hc2[2];
  const double _t532 = _t181*_t531;
  const double _t533 = 0.3e1*_t532;
  const double _t534 = _t71*_t85;
  const double _t536 = _t178*_t196;
  const double _t537 = 0.3e1*_t185;
  const double _t538 = _t116*_t227;
  const double _t539 = _t264*_t71;
  const double _t540 = 0.3e1*_t539;
  const double _t551 = -_t193*_t468;
  const double _t554 = _hc1[3]*_hc3[1];
  const double _t555 = _t190*_t25;
  const double _t556 = _hc1[1]*_hc3[3];
  const double _t557 = _t187 + _t529*_t556;
  const double _t560 = _hc3[5]*_t150;
  const double _t561 = -_hc3[9]*_t44;
  const double _t562 = _hc3[8]*_t73 + _t561;
  const double _t563 = -_hc3[8]*_t44;
  const double _t564 = _hc3[7]*_t73 + _t563;
  const double _t565 = _hc3[4]*_t197 + _hc3[4]*_t205 - _t44*_t562 + _t560 + _t564*_t73;
  const double _t566 = -_hc3[7]*_t44;
  const double _t567 = _hc3[6]*_t73 + _t566;
  const double _t568 = _hc3[4]*_t150;
  const double _t569 = _hc3[3]*_t205 + _t568;
  const double _t570 = _t139*_t556 - _t44*_t564 + _t567*_t73 + _t569;
  const double _t571 = _t139*_t267 + _t188*_t559 + _t267*_t481 - _t44*_t565 + _t483*_t555 + _t551 + _t552*_t70 + _t553*_t554 + _t557*_t558 + _t570*_t73;
  const double _t598 = my_piecewise3(_t37, 0, -_t175*_t512 + _t184*_t524 + _t196*_t537 + _t227*_t272 + _t227*_t540 + _t272*_t550 + _t38*_t571 - _t509*_t510 - _t513*_t516 + _t517*_t518 + _t518*_t523 + _t519*_t520 + _t521*_t522 - _t525*_t527 - _t526*_t536 - _t527*_t538 + _t530*_t533 - _t534*_t535 + _t597*_t94);
  const double _t603 = _hc4[1]*_t308;
  const double _t613 = 0.2e1*_t258;
  const double _t615 = _t246*_t614;
  const double _t616 = _t165*_t257;
  const double _t617 = _t160 + _t161*_t254 + _t218*_t616 - _t256*_t462 + _t334 + _t4*_t615 + _t464;
  const double _t621 = _hc5[1]*_t138;
  const double _t631 = _hc5[1]*_t618;
  const double _t634 = _t246*_t633;
  const double _t638 = _t159*_t637;
  const double _t639 = _hc5[2]*_t140;
  const double _t640 = _t59*_t88;
  const double _t641 = _hc5[3]*_t146;
  const double _t643 = _t165*_t642;
  const double _t644 = _t49*_t643;
  const double _t645 = _t146*_t504;
  const double _t646 = _t465*_t8;
  const double _t647 = _t253*_t646;
  const double _t649 = -0.1e1 / 0.27e2*_hc5[2]*_t12*_t16*_t17*_t18*_t32*_t42*_t49*_t56*_t88*p->cam_omega + _t254*_t636 + _t498 + _t616*_t648;
  const double _t650 = (0.1e1 / 0.27e2)*_hc4[1]*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t27*_t31*_t32*_t56*_t8*_t98*p->cam_omega + (0.1e1 / 0.27e2)*_hc4[1]*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t27*_t31*_t32*_t56*_t8*_t98*p->cam_omega + (0.2e1 / 0.9e1)*_hc5[1]*_hc5[2]*_t12*_t146*_t16*_t163*_t17*_t18*_t32*_t8*_t88*p->cam_omega + (0.1e1 / 0.54e2)*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.54e2)*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t32*_t42*_t56*p->cam_omega + (0.2e1 / 0.9e1)*_hc5[2]*_t12*_t16*_t17*_t18*_t244*_t32*_t4*_t49*_t56*p->cam_omega - _t104*_t637 + (0.2e1 / 0.27e2)*_t12*_t140*_t16*_t162*_t163*_t17*_t18*_t32*_t8*_t88*p->cam_omega - _t249*_t635 - _t4*_t634 - _t4*_t644 - _t465*_t636 - _t59*_t631 - _t638 - _t639*_t640 - _t640*_t641 - _t645*_t88 - 0.4e1 / 0.81e2*_t647 - _t649;
  const double _t652 = _t1*_t260;
  const double _t653 = _t219*_t262;
  const double _t656 = _hc2[1]*_t265;
  const double _t659 = _t658*_t70 + _t68;
  const double _t660 = _t181*_t659;
  const double _t661 = _t85*_t90;
  const double _t662 = _t178*_t271;
  const double _t665 = _t181*_t522;
  const double _t666 = _t380*_t84;
  const double _t667 = _t531*_t84;
  const double _t668 = 0.2e1*_t667;
  const double _t669 = _t264*_t93;
  const double _t670 = _t116*_t283;
  const double _t671 = 0.2e1*_t539;
  const double _t676 = _t182*_t93;
  const double _t678 = _t191*_t554;
  const double _t679 = _t192*_t89;
  const double _t680 = _hc1[1]*_t188;
  const double _t681 = _t187 + _t556*_t658;
  const double _t682 = _hc3[7]*_t91 + _t563;
  const double _t683 = _hc1[1]*_hc3[4];
  const double _t684 = _hc3[8]*_t91 + _t561;
  const double _t685 = -_t44*_t684 + _t560;
  const double _t686 = _hc3[4]*_t277 + _t138*_t683 + _t682*_t73 + _t685;
  const double _t687 = _hc3[6]*_t91 + _t566;
  const double _t688 = _t138*_t556;
  const double _t689 = -_t44*_t682 + _t568;
  const double _t690 = _hc3[3]*_t277 + _t687*_t73 + _t688 + _t689;
  const double _t691 = _t138*_t680 + _t139*_t679 + _t150*_t190 + _t150*_t269 + _t188*_t277 + _t197*_t266 + _t205*_t681 + _t267*_t480 - _t44*_t686 + _t551 + _t658*_t678 + _t677*_t70 + _t690*_t73;
  const double _t709 = my_piecewise3(_t37, 0, _t174*_t90 + _t177*_t652 - _t180*_t662 + _t186*_t271 + _t196*_t669 + _t227*_t286 + _t227*_t676 + _t263*_t655 + _t265*_t668 + _t272*_t675 + _t283*_t671 + _t38*_t691 + _t531*_t660 + _t653*_t654 - _t656*_t657 - _t657*_t661 - _t657*_t666 - _t657*_t670 + _t664*_t665 + _t708*_t94);
  const double _t712 = _t285*_t350;
  const double _t713 = _t285*_t531;
  const double _t714 = _t261*_t90;
  const double _t715 = _t178*_t291;
  const double _t718 = _t285*_t522;
  const double _t719 = _t667*_t90;
  const double _t721 = _t116*_t297;
  const double _t722 = 0.2e1*_t669;
  const double _t723 = 0.2e1*_t676;
  const double _t724 = _hc3[3]*_t294;
  const double _t725 = _t288*_t556 + _t687*_t91 + _t689 + _t724;
  const double _t728 = _hc1[1]*_t266;
  const double _t729 = _hc3[4]*_t294 + _t288*_t683 + _t682*_t91 + _t685;
  const double _t730 = _t269*_t484 - _t44*_t729 + _t551;
  const double _t731 = -_t137*_t70 + _t266*_t727 + _t267*_t288 - _t474*_t70 + _t480*_t679 + _t480*_t728 + _t554*_t726 + _t725*_t73 + _t730;
  const double _t740 = my_piecewise3(_t37, 0, _t185*_t291 + _t271*_t722 + _t272*_t297 + _t283*_t287 + _t283*_t723 + _t297*_t539 + _t38*_t731 + _t530*_t713 - _t657*_t714 - _t67*_t715 - _t711*_t712 - _t711*_t721 + _t717*_t718 + _t719*_t720 + _t739*_t94);
  const double _t759 = _t165*_t314;
  const double _t760 = _t246*_t4;
  const double _t761 = _hc5[3]*_t753;
  const double _t762 = _t331*_t42;
  const double _t763 = (0.4e1 / 0.27e2)*_t760;
  const double _t764 = _t244*_t763;
  const double _t765 = _t159*_t8;
  const double _t766 = _t31*_t765;
  const double _t767 = (0.4e1 / 0.81e2)*_t327;
  const double _t768 = (0.7e1 / 0.81e2)*_t330;
  const double _t769 = _t253*_t8;
  const double _t770 = (0.8e1 / 0.81e2)*_t769;
  const double _t771 = _t104*_t706 + _t249*_t637;
  const double _t772 = (0.2e1 / 0.27e2)*_hc4[1]*_hc5[2]*_t12*_t16*_t17*_t18*_t27*_t31*_t32*_t49*_t56*_t8*_t88*_t98*p->cam_omega + (0.2e1 / 0.9e1)*_hc5[1]*_hc5[2]*_t12*_t16*_t163*_t17*_t18*_t314*_t32*_t49*_t8*p->cam_omega + (0.2e1 / 0.81e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t299*_t32*_t320*_t321*_t49*_t56*_t8*p->cam_omega*gbb + (0.1e1 / 0.54e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t313*_t32*_t42*_t56*p->cam_omega + (0.2e1 / 0.9e1)*_hc5[2]*_t12*_t16*_t17*_t18*_t244*_t32*_t4*_t56*_t88*p->cam_omega + (0.1e1 / 0.54e2)*_hc5[2]*_t12*_t16*_t17*_t18*_t314*_t32*_t42*_t56*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t313*_t32*_t49*_t8*p->cam_omega + (0.2e1 / 0.81e2)*_t12*_t16*_t17*_t18*_t299*_t30*_t32*_t320*_t321*_t42*p->cam_omega*gbb - _t159*_t635 - _t247 - _t253*_t764 - _t313*_t505 - _t328*_t648 - _t332*_t636 - _t4*_t643*_t88 - _t504*_t753 - _t59*_t761 - _t616*_t770 - 0.11e2 / 0.27e2*_t632*_t760 - _t636*_t759 - _t649 - 0.7e1 / 0.81e2*_t762 - _t766*_t767 - _t766*_t768 - _t771;
  const double _t775 = 0.3e1*_t713;
  const double _t776 = 0.3e1*_t669;
  const double _t777 = 0.3e1*_t286;
  const double _t783 = 0.2e1*_t728;
  const double _t786 = _t288*_t679 + _t288*_t783 + _t554*_t782 + _t679*_t785 + _t681*_t784 + _t70*_t781 + _t725*_t91 + _t730;
  const double _t791 = my_piecewise3(_t37, 0, _t291*_t776 + _t297*_t676 + _t297*_t777 + _t38*_t786 + _t522*_t774 + _t659*_t775 + _t676*_t779 + _t790*_t94);
  const double _t805 = (_t107 * _t107 * _t107);
  const double _t812 = 0.8e1*_t102;
  const double _t817 = _t201*_t249;
  const double _t818 = _t218*_t759;
  const double _t819 = _t104*_t546 - _t218*_t325 + _t218*_t332 - _t318*_t462 + _t328*_t547 + _t331*_t548 + _t464 + _t817 + _t818;
  const double _t820 = -_t317*_t462 + _t819;
  const double _t825 = _hc4[2]*_t103;
  const double _t826 = _t824*_t825;
  const double _t827 = _t8*_t826;
  const double _t828 = _hc4[1]*_t450;
  const double _t830 = _t828*_t829;
  const double _t831 = _hc4[3]*_t799;
  const double _t832 = _t450*_t831;
  const double _t833 = (0.1e1 / ((_hc4[0]) * (_hc4[0]) * (_hc4[0])));
  const double _t834 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]));
  const double _t835 = _t833*_t834;
  const double _t836 = _t35*_t835;
  const double _t837 = _t799*_t836;
  const double _t838 = _hc5[3]*_t821;
  const double _t839 = _hc5[1]*_t780;
  const double _t840 = _t249*_t31;
  const double _t841 = _t327*_t840;
  const double _t842 = _t330*_t840;
  const double _t843 = _hc5[2]*_t88;
  const double _t844 = _t59*_t843;
  const double _t845 = (0.8e1 / 0.27e2)*_hc4[1]*_hc4[2]*_t12*_t16*_t17*_t18*_t30*_t32*_t321*_t429*_t798*_t8*p->cam_omega + (0.1e1 / 0.9e1)*_hc4[1]*_hc5[1]*_t12*_t16*_t17*_t18*_t27*_t31*_t313*_t32*_t56*_t8*_t98*p->cam_omega + (0.1e1 / 0.9e1)*_hc4[1]*_hc5[2]*_t12*_t16*_t17*_t18*_t27*_t31*_t314*_t32*_t56*_t8*_t98*p->cam_omega + (0.2e1 / 0.9e1)*_hc5[1]*_hc5[2]*_t12*_t16*_t163*_t17*_t18*_t32*_t8*_t821*p->cam_omega + (0.2e1 / 0.27e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t299*_t32*_t320*_t321*_t56*_t8*_t88*p->cam_omega*gbb + (0.1e1 / 0.18e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t313*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.18e2)*_hc5[2]*_t12*_t16*_t17*_t18*_t314*_t32*_t42*_t56*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t313*_t32*_t8*_t88*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t32*_t8*_t822*_t88*p->cam_omega + (0.2e1 / 0.27e2)*_t12*_t16*_t17*_t18*_t299*_t30*_t32*_t320*_t321*_t42*p->cam_omega*gbb + (0.14e2 / 0.27e2)*_t12*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t792*_t8*p->cam_omega*gbb - _t155*_t249 - _t201*_t759 - _t218*_t837 - _t218*_t841 - _t222*_t842 - _t253*_t464 - _t253*_t817 - _t253*_t818 - _t313*_t844 - _t328*_t546 - _t498 - _t504*_t821 - _t59*_t838 - _t59*_t839 - 0.7e1 / 0.27e2*_t762 - _t822*_t844 - 0.28e2 / 0.27e2*_t827 - 0.70e2 / 0.81e2*_t830 - 0.16e2 / 0.81e2*_t832;
  const double _t848 = (0.10e2 / 0.3e1)*_t172;
  const double _t849 = _t112*_t64;
  const double _t851 = _t1*_t513;
  const double _t854 = _t116*_t425;
  const double _t857 = (0.4e1 / 0.3e1)*_t341;
  const double _t860 = _hc0[1]*_t116;
  const double _t861 = _t573*_t860;
  const double _t863 = _hc2[1]*_t71;
  const double _t868 = _t350*_t84;
  const double _t869 = _hc2[3]*_hc3[0];
  const double _t871 = _t869*_t870;
  const double _t872 = _hc2[2]*_t71;
  const double _t875 = _t872*_t874;
  const double _t876 = _t119*_t348;
  const double _t877 = _t116*_t365;
  const double _t883 = _t227*_t350;
  const double _t908 = my_piecewise3(_t37, 0, _hc3[0]*_t848 + _t115*_t534 - _t179*_t862 + _t181*_t871 - _t183*_t866 - _t184*_t862 + _t196*_t876 + _t272*_t882 + _t347*_t536 + _t351*_t875 + _t365*_t671 + _t525*_t867 + _t538*_t867 - _t657*_t877 - _t71*_t857 + _t849*_t850 + _t851*_t853 + _t854*_t856 + _t859*_t861 - _t863*_t865 - _t865*_t868 + _t870*_t883 + _t907*_t94);
  const double _t913 = _t35*_t873;
  const double _t915 = _t369*_t878;
  const double _t916 = _t159*_t371;
  const double _t917 = -_t880*_t916 - _t915;
  const double _t920 = _t369*_t884;
  const double _t921 = _t905*_t916;
  const double _t922 = _t154*_t57;
  const double _t923 = _t157*_t57;
  const double _t924 = _t371*_t896;
  const double _t925 = -_t372*_t922 - _t372*_t923 + _t465*_t924 + _t920 + _t921;
  const double _t927 = (0.2e1 / 0.3e1)*_t341;
  const double _t928 = _hc2[1]*_t90;
  const double _t929 = _t339*_t359;
  const double _t930 = _hc0[1]*_t261;
  const double _t931 = _t339*_t342;
  const double _t932 = _t116*_t711;
  const double _t933 = _hc2[2]*_t265;
  const double _t934 = _hc2[2]*_t90;
  const double _t937 = _t350*_t870;
  const double _t950 = my_piecewise3(_t37, 0, _t119*_t869*_t936 - 0.2e1 / 0.3e1*_t260*_t342 - _t261*_t929 + _t271*_t876 + _t272*_t379 + _t283*_t937 + _t286*_t365 - _t346*_t380 - _t346*_t928 + _t347*_t662 + _t365*_t676 + _t379*_t539 - _t379*_t932 + _t656*_t867 + _t661*_t867 + _t666*_t867 + _t670*_t867 + _t870*_t933 - _t90*_t927 - _t930*_t931 + _t934*_t935 + _t94*_t949);
  const double _t958 = _hc4[1]*_t367;
  const double _t963 = _t322*_t389;
  const double _t964 = _t905*_t963;
  const double _t965 = (0.1e1 / 0.36e2)*_t244*_t371;
  const double _t966 = _t31*_t395;
  const double _t967 = _t159*_t966;
  const double _t968 = _t249*_t371;
  const double _t969 = _t321*_t389;
  const double _t970 = _t159*_t944;
  const double _t971 = _t31*_t398;
  const double _t972 = _t159*_t971;
  const double _t973 = _t256*_t57;
  const double _t974 = _t248*_t396 + _t248*_t399 - _t372*_t973 + _t616*_t924 + _t760*_t965 + _t896*_t967 + _t896*_t972 + _t916*_t943 + _t920 + _t943*_t968 - _t964 - _t969*_t970;
  const double _t977 = _t93*_t934;
  const double _t983 = my_piecewise3(_t37, 0, _t115*_t714 + _t285*_t871 + _t287*_t379 + _t291*_t876 + _t297*_t937 + _t347*_t715 + _t676*_t978 + _t712*_t867 + _t721*_t867 + _t94*_t982 + _t976*_t977);
  const double _t992 = _t299*_t320;
  const double _t993 = (0.7e1 / 0.54e2)*_t992;
  const double _t1000 = _t103*_t79;
  const double _t1002 = (0.4e1 / 0.3e1)*_t395;
  const double _t1007 = (0.1e1 / 0.18e2)*_t12*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t384*_t8*p->cam_omega - _t396*_t79 - _t399*_t79 - _t880*_t968 - _t915;
  const double _t1008 = _t103*_t326;
  const double _t1009 = _t836*_t997;
  const double _t1010 = _hc4[3]*_t161;
  const double _t1011 = _t103*_t997;
  const double _t1014 = _hc4[1]*_t322;
  const double _t1015 = _hc4[2]*_t1014;
  const double _t1016 = _t1015*_t997;
  const double _t1017 = _t896*_t969;
  const double _t1018 = _t249*_t966;
  const double _t1019 = _t317*_t57;
  const double _t1020 = _t318*_t57;
  const double _t1021 = _t249*_t971;
  const double _t1022 = _t158*_t396 + _t158*_t399 - _t248*_t963 + _t905*_t968;
  const double _t1023 = _t1008*_t887 + _t1009*_t58 + _t1010*_t1011 + _t1013*_t828 - _t1016*_t79 - _t1017*_t249 + _t1018*_t252 - _t1019*_t372 - _t1020*_t372 + _t1021*_t252 + _t1022 - _t324*_t886 + _t759*_t924 + _t920;
  const double _t1025 = _t403*_t64;
  const double _t1027 = (0.1e1 / 0.3e1)*_t341;
  const double _t1032 = _t350*_t415;
  const double _t1034 = _t1032*_t1033;
  const double _t1038 = _t1037*_t116;
  const double _t1042 = _t171*_t71;
  const double _t1044 = _t408*_t71;
  const double _t1045 = _hc2[2]*_t416;
  const double _t1046 = _hc2[1]*_t427;
  const double _t1049 = _hc2[3]*_t84;
  const double _t1050 = _t410*_t416;
  const double _t1052 = _t411*_t419;
  const double _t1053 = _t411*_t427;
  const double _t1077 = my_piecewise3(_t37, 0, _t1025*_t1026 - _t1027*_t410 - _t1030*_t513 - _t1031*_t1034 - _t1035*_t861 + _t1036*_t1038 - _t1040*_t424 - _t1041*_t179 + _t1042*_t1043 + _t1044*_t1045 + _t1044*_t1046 + _t1044*_t423 - _t1047*_t183 + _t1048*_t183 + _t1049*_t1050 + _t1051*_t1052 + _t1053*_t84 + _t1054*_t116 + _t1055*_t350 + _t1076*_t94 - _t420*_t863 - _t420*_t868);
  const double _t1086 = _t124*_t431;
  const double _t1087 = _hc4[2]*_t1080;
  const double _t1091 = _t35*_t418;
  const double _t1097 = _t435*_t447;
  const double _t1098 = (0.1e1 / 0.144e3)*_t766;
  const double _t1099 = _t435*_t437;
  const double _t1100 = _t1099*_t321;
  const double _t1101 = _t1100*_t765;
  const double _t1102 = _t103*_t1070;
  const double _t1103 = _t1099*_t322;
  const double _t1104 = _t1073*_t1103 - _t1097*_t1102 + _t1102*_t443;
  const double _t1105 = -_t1097*_t1098 + _t1098*_t443 + (0.1e1 / 0.288e3)*_t1101 + _t1104;
  const double _t1107 = _t171*_t90;
  const double _t1108 = _t408*_t90;
  const double _t1109 = _hc2[3]*_t1050;
  const double _t1110 = _t1052*_t421;
  const double _t1111 = _t350*_t976;
  const double _t1115 = my_piecewise3(_t37, 0, -_t1041*_t260 + _t1043*_t1107 + _t1045*_t1108 + _t1046*_t1108 - _t1047*_t262 + _t1048*_t262 + _t1053*_t93 + _t1108*_t423 + _t1109*_t93 + _t1110*_t93 + _t1111*_t379 + _t1114*_t94 + _t117*_t379 - _t380*_t420 - _t420*_t928);
  const double _t1124 = _t1120*_t834;
  const double _t1125 = (0.1e1 / 0.144e3)*_t1124;
  const double _t1128 = _t1124*_t353;
  const double _t1129 = _t103*_t880;
  const double _t1137 = _hc4[3]*_t1120;
  const double _t1138 = _t1120*_t836;
  const double _t1140 = _hc4[1]*_t1139;
  const double _t1141 = _t435*_t963;
  const double _t1142 = _t1015*_t1120;
  const double _t1143 = _t8*_t840;
  const double _t1144 = (0.1e1 / 0.144e3)*_t1143;
  const double _t1145 = _t1066*_t1100*_t249 - _t1097*_t1144 + _t1104 - _t1129*_t1137 + _t1129*_t1140 - _t1138*_t418 + _t1141*_t353 + _t1142*_t118 + _t1144*_t443 - _t396*_t435*_t880;
  const double _t1153 = _t1152*_t513;
  const double _t1155 = (0.1e1 / 0.128e3)*_t1032;
  const double _t1159 = (0.1e1 / 0.256e3)*_t1032;
  const double _t1163 = _t116*_t21;
  const double _t1164 = _t1162*_t1163;
  const double _t1171 = _t1038*_t8;
  const double _t1175 = _t1174*_t869;
  const double _t1179 = my_piecewise3(_t37, 0, _t111*_t1148 - _t1151*_t407 + _t1153*_t1154 + _t1155*_t1157 - _t1155*_t1158 + _t1159*_t1160 + _t1161*_t1164 + _t1163*_t1168 - _t1164*_t1165 + _t1170*_t861 - _t1171*_t1172 - _t1173*_t854 + _t1175*_t1178);
  const double _t1194 = (0.1e1 / 0.128e3)*_t437;
  const double _t1197 = _t1180*_t124;
  const double _t1202 = _hc4[3]*_t1188;
  const double _t1203 = _t1166*_t1202;
  const double _t1206 = (0.3e1 / 0.64e2)*_t437;
  const double _t1209 = (0.1e1 / _t29);
  const double _t455 = _hc6[3]*_t52;
  const double _t456 = _hc6[2]*_t130;
  const double _t457 = 0.3e1*_t132;
  const double _t458 = _hc4[0]*_t153;
  const double _t459 = 0.3e1*_t458;
  const double _t460 = _hc6[1]*_t132;
  const double _t461 = 0.3e1*_t460;
  const double _t470 = -_hc7[2]*_t469;
  const double _t477 = _hc5[3]*_hc7[1];
  const double _t485 = 0.2e1*_t145;
  const double _t486 = _hc7[5]*_t150;
  const double _t487 = -_hc7[9]*_t44;
  const double _t488 = _hc7[8]*_t55 + _t487;
  const double _t489 = -_hc7[8]*_t44;
  const double _t490 = _hc7[7]*_t55 + _t489;
  const double _t491 = _hc7[4]*_t154 + _hc7[4]*_t157 - _t44*_t488 + _t486 + _t490*_t55;
  const double _t492 = _hc7[4]*_t150;
  const double _t493 = -_hc7[7]*_t44;
  const double _t494 = _hc7[6]*_t55 + _t493;
  const double _t495 = _hc7[3]*_t154 + _hc7[3]*_t157 - _t44*_t490 + _t492 + _t494*_t55;
  const double _t496 = _t140*_t240 + _t143*_t484 + _t154*_t485 + _t157*_t485 + _t240*_t482 - _t44*_t491 + _t470 + _t475*_t50 + _t476*_t477 + _t495*_t55;
  const double _t507 = my_piecewise3(_t39, 0, _t108*_t506 + _t168*_t243 + _t168*_t461 + _t243*_t467 + _t40*_t496 + _t454*_t455 + _t456*_t457 + _t459*_t61);
  const double _t599 = _t507 + _t598;
  const double _t600 = _hc4[1]*_hc7[0];
  const double _t601 = _t100*_t600;
  const double _t602 = _t51*_t61;
  const double _t604 = _t153*_t230;
  const double _t605 = _t130*_t455;
  const double _t606 = _t107*_t374;
  const double _t607 = _hc6[1]*_t168;
  const double _t608 = _hc4[0]*_t61;
  const double _t609 = 0.2e1*_t242;
  const double _t610 = _hc6[1]*_t234;
  const double _t611 = _hc4[0]*_t235;
  const double _t612 = _t107*_t131;
  const double _t619 = _t147*_t88;
  const double _t620 = _t146*_t477;
  const double _t622 = _hc7[7]*_t105 + _t489;
  const double _t623 = _hc7[8]*_t105 + _t487;
  const double _t624 = -_t44*_t623 + _t486;
  const double _t625 = _hc7[4]*_t256 - _hc7[4]*_t621 + _t55*_t622 + _t624;
  const double _t626 = _hc7[6]*_t105 + _t493;
  const double _t627 = _hc7[3]*_t88;
  const double _t628 = -_t44*_t622 + _t492;
  const double _t629 = -_hc7[3]*_t621 + _t255*_t627 + _t55*_t626 + _t628;
  const double _t630 = _t140*_t619 + _t143*_t150 + _t145*_t256 - _t145*_t621 + _t150*_t237 + _t154*_t239 + _t157*_t239 - _t240*_t480 - _t44*_t625 + _t470 + _t50*_t618 + _t55*_t629 + _t620*_t88;
  const double _t651 = my_piecewise3(_t39, 0, -_t100*_t604 + _t107*_t605 + _t108*_t650 + _t133*_t606 + _t153*_t611 + _t168*_t610 + _t168*_t612 + _t234*_t456 + _t243*_t617 + _t40*_t630 - _t456*_t601 + _t460*_t613 - _t601*_t607 - _t602*_t603 + _t608*_t609);
  const double _t710 = 0.2e1*_t259 + 0.2e1*_t284;
  const double _t742 = _t232*_t326;
  const double _t744 = _t101*_t61;
  const double _t745 = _hc6[2]*_t309;
  const double _t746 = _t235*_t51;
  const double _t747 = _t230*_t242;
  const double _t748 = _t309*_t455;
  const double _t749 = _hc7[0]*_t603;
  const double _t750 = _hc4[0]*_t316;
  const double _t751 = _hc6[1]*_t258;
  const double _t752 = _hc7[3]*_t317 + _hc7[3]*_t318 + _t105*_t626 + _t628;
  const double _t754 = _hc5[1]*_t239;
  const double _t755 = 0.2e1*_t239;
  const double _t756 = _hc7[4]*_t317 + _hc7[4]*_t318 + _t105*_t622 + _t624;
  const double _t757 = _t237*_t484 - _t44*_t756 + _t470;
  const double _t758 = _t137*_t50 + _t240*_t313 + _t256*_t755 + _t474*_t50 + _t477*_t753 - _t480*_t619 - _t480*_t754 + _t55*_t752 + _t757;
  const double _t773 = my_piecewise3(_t39, 0, _t108*_t772 + _t132*_t745 + _t231*_t741 + _t233*_t741 + _t243*_t336 + _t303*_t51 - _t308*_t747 + _t312*_t606 + _t336*_t460 + _t40*_t758 + _t60*_t748 - _t603*_t744 - _t603*_t746 - _t606*_t749 + _t609*_t611 + _t61*_t750 + _t610*_t613 + _t612*_t613 + _t742*_t743 - _t749*_t751);
  const double _t793 = _t433*_t792;
  const double _t797 = _hc4[3]*_t96;
  const double _t801 = _t101*_t301;
  const double _t803 = _t27*_t307;
  const double _t806 = _t310*_t326;
  const double _t809 = _t600*_t808;
  const double _t810 = 0.3e1*_t234;
  const double _t811 = _t101*_t235;
  const double _t813 = _t230*_t316;
  const double _t814 = 0.3e1*_t611;
  const double _t815 = _hc6[1]*_t336;
  const double _t816 = 0.3e1*_t610;
  const double _t823 = _t105*_t752 + _t313*_t619 + _t317*_t755 + _t318*_t755 + _t477*_t821 + _t50*_t780 + _t619*_t822 + _t757;
  const double _t846 = my_piecewise3(_t39, 0, _t108*_t845 - _t304*_t796 + _t311*_t807 + _t316*_t814 + _t336*_t612 + _t336*_t816 + _t40*_t823 + _t455*_t805 + _t612*_t820 - _t745*_t809 + _t745*_t810 - _t793*_t794 - _t797*_t800 + _t801*_t802 + _t802*_t806 + _t803*_t804 - _t808*_t813 - _t809*_t815 - _t811*_t812);
  const double _t847 = _t791 + _t846;
  const double _t909 = _t367*_t600;
  const double _t910 = _hc6[3]*_t376;
  const double _t911 = 0.2e1*_t460;
  const double _t912 = _t125*_t51;
  const double _t914 = _t912*_t913;
  const double _t918 = _t126*_t128;
  const double _t919 = _hc6[2]*_t376;
  const double _t926 = my_piecewise3(_t39, 0, _t108*_t925 + _t125*_t602 + _t130*_t910 + _t153*_t918 + _t168*_t919 + _t243*_t917 + _t367*_t604 + _t373*_t911 + _t374*_t914 + _t456*_t909 + _t607*_t909);
  const double _t951 = (0.2e1 / 0.3e1)*_t385;
  const double _t952 = _t383*_t61;
  const double _t953 = _hc7[0]*_t373;
  const double _t954 = _hc6[1]*_t953;
  const double _t955 = _hc4[1]*_t954;
  const double _t956 = _hc7[0]*_t389;
  const double _t957 = _t388*_t956;
  const double _t959 = _t128*_t392;
  const double _t960 = _t128*_t394;
  const double _t961 = _hc6[3]*_t107;
  const double _t962 = _t60*_t961;
  const double _t975 = my_piecewise3(_t39, 0, -_t100*_t955 + _t108*_t974 - 0.2e1 / 0.3e1*_t231*_t386 + _t242*_t918 + _t243*_t400 + _t258*_t919 + _t367*_t747 + _t373*_t610 + _t373*_t612 - _t374*_t957 + _t374*_t959 + _t376*_t962 - _t391*_t51 - _t395*_t952 - _t398*_t952 + _t400*_t460 - _t51*_t951 + _t606*_t909 + _t744*_t958 + _t746*_t958 + _t751*_t909 + _t912*_t960);
  const double _t984 = (0.10e2 / 0.3e1)*_t301;
  const double _t985 = _t122*_t97;
  const double _t987 = _t27*_t797;
  const double _t990 = _hc6[1]*_hc7[0];
  const double _t991 = _t450*_t990;
  const double _t994 = (0.4e1 / 0.3e1)*_t385;
  const double _t995 = _hc6[1]*_t600;
  const double _t996 = _t825*_t995;
  const double _t1001 = _t1000*_t390;
  const double _t1003 = _t1000*_t956;
  const double _t1004 = _t392*_t913;
  const double _t1005 = _hc6[1]*_t400;
  const double _t1006 = 0.2e1*_t610;
  const double _t1024 = my_piecewise3(_t39, 0, _hc7[0]*_t984 - _t1001*_t101 - _t1002*_t310 - _t1003*_t394 + _t1004*_t394 - _t1005*_t749 + _t1006*_t400 + _t1007*_t612 - _t101*_t994 + _t1023*_t108 + _t235*_t392 - _t307*_t999 + _t309*_t910 - _t311*_t999 + _t316*_t918 + _t336*_t919 + _t367*_t813 + _t745*_t909 + _t815*_t909 + _t985*_t986 + _t987*_t989 + _t991*_t993 + _t996*_t998);
  const double _t1079 = _t300*_t51;
  const double _t1081 = _t435*_t51;
  const double _t1082 = _t438*_t441;
  const double _t1083 = _t443*_t446;
  const double _t1084 = _t446*_t447;
  const double _t1085 = _t437*_t452;
  const double _t1088 = _hc6[3]*_t60;
  const double _t1089 = _t1088*_t440;
  const double _t1090 = _t438*_t439;
  const double _t1092 = _t1091*_t374;
  const double _t1093 = (0.1e1 / 0.32e2)*_t449;
  const double _t1094 = _t374*_t450;
  const double _t1095 = _hc6[2]*_t913;
  const double _t1096 = _t125*_t953;
  const double _t1106 = my_piecewise3(_t39, 0, -_t1078*_t231 + _t1079*_t1080 + _t108*_t1105 + _t1081*_t1082 + _t1081*_t1084 + _t1081*_t1085 - _t1083*_t51 - _t1086*_t232 + _t1087*_t232 + _t1089*_t1090 - _t1092*_t444 + _t1092*_t448 + _t1093*_t1094 + _t1095*_t1096 + _t126*_t953);
  const double _t1116 = _t430*_t97;
  const double _t1118 = (0.1e1 / 0.3e1)*_t385;
  const double _t1122 = _hc7[0]*_t441;
  const double _t1123 = _t1122*_t31;
  const double _t1127 = _t322*_t990;
  const double _t1130 = _t1129*_t390;
  const double _t1131 = _t101*_t300;
  const double _t1132 = _t101*_t435;
  const double _t1133 = _t1090*_t440;
  const double _t1134 = _t1091*_t394;
  const double _t1135 = _t394*_t450;
  const double _t1136 = _t1095*_t375;
  const double _t1146 = my_piecewise3(_t39, 0, -_t101*_t1083 - _t1078*_t307 + _t108*_t1145 + _t1080*_t1131 + _t1082*_t1132 + _t1084*_t1132 + _t1085*_t1132 - _t1086*_t310 + _t1087*_t310 + _t1093*_t1135 + _t1116*_t1117 - _t1118*_t439 - _t1121*_t797 - _t1123*_t1125 - _t1126*_t996 + _t1127*_t1128 - _t1130*_t439 + _t1133*_t961 - _t1134*_t444 + _t1134*_t448 + _t1136*_t400 + _t127*_t400);
  const double _t1186 = _t1185*_t797;
  const double _t1190 = _hc4[2]*_t600;
  const double _t1191 = _t1190*_t441;
  const double _t1192 = _hc7[0]*_t1183;
  const double _t1193 = _t1192*_t441;
  const double _t1195 = _t1123*_t834;
  const double _t1198 = _t1162*_t445;
  const double _t1199 = _t1197*_t1198;
  const double _t1200 = _t1192*_t447;
  const double _t1201 = _hc7[0]*_t445;
  const double _t1205 = _t1127*_t8*_t834;
  const double _t1207 = _t1192*_t1206;
  const double _t1208 = _hc7[0]*_t31;
  const double _t1210 = _hc6[3]*_t1209*_t33;
  const double _t1211 = _t1208*_t1210*_t834;
  const double _t1213 = my_piecewise3(_t39, 0, _hc7[0]*_t1199 + _t1181*_t121 - _t1184*_t434 + _t1186*_t1187 + _t1189*_t1191 - _t1189*_t1205 - _t1193*_t1194 + _t1195*_t1196 - _t1198*_t1200 + _t1201*_t1203 + _t1204*_t996 - _t1207*_t451 + _t1211*_t1212);
  const double d3F_dna3 = 0.3e1*_t169 + 0.3e1*_t228 + _t5*_t599;
  const double d3F_dna2_dnb = _t229 + _t5*(_t651 + _t709) + _t710;
  const double d3F_dna_dnb2 = _t338 + _t5*(_t740 + _t773) + _t710;
  const double d3F_dnb3 = 0.3e1*_t298 + 0.3e1*_t337 + _t5*_t847;
  const double d3F_dna2_dgaa = 0.2e1*_t366 + _t5*_t908;
  const double d3F_dna2_dgbb = 0.2e1*_t377 + _t5*_t926;
  const double d3F_dna_dnb_dgaa = _t366 + _t382 + _t5*_t950;
  const double d3F_dna_dnb_dgbb = _t377 + _t401 + _t5*_t975;
  const double d3F_dnb2_dgaa = 0.2e1*_t382 + _t5*_t983;
  const double d3F_dnb2_dgbb = _t1024*_t5 + 0.2e1*_t401;
  const double d3F_dna_dgaa2 = _t1077*_t5 + _t428;
  const double d3F_dna_dgbb2 = _t1106*_t5 + _t453;
  const double d3F_dnb_dgaa2 = _t1115*_t5 + _t428;
  const double d3F_dnb_dgbb2 = _t1146*_t5 + _t453;
  const double d3F_dgaa3 = _t1179*_t5;
  const double d3F_dgbb3 = _t1213*_t5;
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
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double _t1217 = 0.2e1*na - 0.2e1*nb;
  const double _t1218 = -_t1217*_t136;
  const double _t1219 = _t1218 + _t134;
  const double _t1227 = (0.1e1 / 0.9e1)*_t42;
  const double _t1228 = (0.2e1 / 0.9e1)*_t8;
  const double _t1232 = (0.28e2 / 0.81e2)*_t244;
  const double _t1234 = (0.28e2 / 0.81e2)*_t8;
  const double _t1237 = (0.140e3 / 0.243e3)*_t632;
  const double _t1239 = (0.56e2 / 0.243e3)*_t244;
  const double _t1242 = 0.24e2*_t472;
  const double _t1243 = 0.24e2*_t4/xc_powi(_t5, 5);
  const double _t1244 = -_t1242 + _t1243;
  const double _t1245 = -_t1244;
  const double _t1246 = (_t49 * _t49 * _t49 * _t49);
  const double _t1248 = (_t140 * _t140);
  const double _t1254 = _t1246*_t8;
  const double _t1257 = (0.16e2 / 0.81e2)*_t148;
  const double _t1258 = (0.56e2 / 0.243e3)*_t42;
  const double _t1265 = 0.12e2*_t136;
  const double _t1266 = 0.12e2*_t472;
  const double _t1267 = _t1266*_t4;
  const double _t1268 = -_t1265 + _t1267;
  const double _t1270 = (0.8e1 / 0.81e2)*_t42;
  const double _t1275 = 0.6e1*_t47;
  const double _t1276 = _t4*_t471;
  const double _t1277 = _t1275 - _t1276;
  const double _t1282 = (0.140e3 / 0.81e2)*_t632;
  const double _t1286 = (0.14e2 / 0.9e1)*_t244;
  const double _t1290 = (0.2e1 / 0.3e1)*_t148*_t25;
  const double _t1308 = gaa/xc_powr(na, 20, 3);
  const double _t1309 = xc_powr(na, -16, 3);
  const double _t1310 = _t402/xc_powi(na, 8);
  const double _t1312 = _t1149/xc_powr(na, 28, 3);
  const double _t1313 = (0.448e3 / 0.9e1)*_t574;
  const double _t1314 = (0.1120e4 / 0.27e2)*_t511;
  const double _t1317 = (0.256e3 / 0.27e2)*_t515;
  const double _t1322 = (0.56e2 / 0.3e1)*_t223;
  const double _t1324 = (0.16e2 / 0.3e1)*_t66;
  const double _t1332 = _t1217*_t136 - _t134;
  const double _t1344 = (0.4e1 / 0.9e1)*_t8;
  const double _t1345 = (0.7e1 / 0.9e1)*_t8;
  const double _t1346 = (0.2e1 / 0.9e1)*_t42;
  const double _t1355 = (0.8e1 / 0.27e2)*_t42;
  const double _t1356 = (0.8e1 / 0.27e2)*_t148;
  const double _t1357 = (0.32e2 / 0.81e2)*_t515;
  const double _t1362 = (_t69 * _t69 * _t69 * _t69);
  const double _t1364 = (_t139 * _t139);
  const double _t1365 = -_t1268;
  const double _t1367 = 0.6e1*na - 0.6e1*nb;
  const double _t1368 = -_t1275 + _t136*_t1367;
  const double _t1369 = 0.4e1*na - 0.4e1*nb;
  const double _t1370 = _t136*_t1369 - _t478;
  const double _t1391 = _t1308*_t8;
  const double _t1392 = _t42*_t574;
  const double _t1395 = (0.280e3 / 0.243e3)*_t42;
  const double _t1399 = (0.112e3 / 0.243e3)*_t244;
  const double _t1400 = (0.64e2 / 0.243e3)*_t42;
  const double _t1403 = (0.112e3 / 0.27e2)*_t8;
  const double _t1406 = _t1312*_t8;
  const double _t1413 = (0.56e2 / 0.27e2)*_t8;
  const double _t1424 = _t1362*_t8;
  const double _t1432 = (0.16e2 / 0.81e2)*_t42;
  const double _t1450 = (0.32e2 / 0.81e2)*_t8;
  const double _t1452 = (0.16e2 / 0.27e2)*_t8;
  const double _t1453 = (0.16e2 / 0.81e2)*_t8;
  const double _t1455 = (0.56e2 / 0.81e2)*_t8;
  const double _t1459 = _t139*_t481;
  const double _t1479 = (0.1e1 / 0.3e1)*_t244;
  const double _t1488 = (0.16e2 / 0.27e2)*_t244*_t4;
  const double _t1493 = _t1243 - _t1266;
  const double _t1494 = -_t1493;
  const double _t1502 = _t1267 - 0.4e1*_t136;
  const double _t1504 = _t476*_t88;
  const double _t1506 = (0.28e2 / 0.27e2)*_t244;
  const double _t1511 = 0.8e1*_t136*_t4;
  const double _t1515 = xc_powr(_t5, -16, 3);
  const double _t1516 = (0.14e2 / 0.243e3)*_t244;
  const double _t1517 = (0.14e2 / 0.243e3)*_t42;
  const double _t1518 = (0.4e1 / 0.27e2)*_t244;
  const double _t1520 = _t4*_t632;
  const double _t1521 = (0.2e1 / 0.9e1)*_t1520;
  const double _t1529 = _t245*_t4;
  const double _t1535 = (0.8e1 / 0.27e2)*_t1520;
  const double _t1536 = (0.14e2 / 0.81e2)*_t42;
  const double _t1537 = _t1506*_t4;
  const double _t1541 = _t244*_t4;
  const double _t1542 = (0.4e1 / 0.3e1)*_t1541;
  const double _t1550 = (0.28e2 / 0.243e3)*_t244;
  const double _t1560 = _t508*_t510;
  const double _t1571 = _t529*_t658;
  const double _t1601 = (0.4e1 / 0.9e1)*_t244;
  const double _t1602 = _t1601*_t4;
  const double _t1619 = 0.2e1*_t677;
  const double _t1622 = -_t1502;
  const double _t1624 = _t553*_t658;
  const double _t1626 = 0.2e1*_t692;
  const double _t1628 = 0.2e1*_t694;
  const double _t1634 = _t481*_t89;
  const double _t1638 = _t191*_t4;
  const double _t1643 = _t4*_t481;
  const double _t1645 = _t139*_t4;
  const double _t1647 = _t1624*_t8;
  const double _t1658 = (0.16e2 / 0.243e3)*_t42;
  const double _t1659 = (0.70e2 / 0.243e3)*_t42;
  const double _t1675 = (0.16e2 / 0.3e1)*_t99;
  const double _t1678 = _t1218 + _t135;
  const double _t1693 = (0.22e2 / 0.27e2)*_t632;
  const double _t1714 = _t146*_t314;
  const double _t1717 = (_t4 * _t4);
  const double _t1718 = 0.8e1*_t1717/xc_powi(_t5, 6);
  const double _t1719 = _t1506*_t25;
  const double _t1723 = (0.142e3 / 0.81e2)*_t1515;
  const double _t1724 = _t1717/xc_powr(_t5, 19, 3);
  const double _t1725 = (0.4e1 / 0.9e1)*_t1724;
  const double _t1727 = (0.16e2 / 0.27e2)*_t1724;
  const double _t1728 = (0.8e1 / 0.243e3)*_t148;
  const double _t1732 = (0.4e1 / 0.27e2)*_t632;
  const double _t1736 = _t1693*_t4;
  const double _t1737 = (0.88e2 / 0.81e2)*_t1520;
  const double _t1742 = (0.4e1 / 0.243e3)*_t42;
  const double _t1746 = (0.16e2 / 0.243e3)*_t148;
  const double _t1753 = (0.8e1 / 0.243e3)*_t42;
  const double _t1757 = (0.32e2 / 0.243e3)*_t148;
  const double _t1760 = _t140*_t314;
  const double _t1762 = (0.28e2 / 0.243e3)*_t42;
  const double _t1766 = _t314*_t8;
  const double _t1767 = (0.112e3 / 0.81e2)*_t1541;
  const double _t1778 = _t1217*_t136 + _t134;
  const double _t1802 = _t191*_t289;
  const double _t1822 = _t139*_t288;
  const double _t1825 = _t1332*_t289;
  const double _t1826 = _t1802*_t8;
  const double _t1827 = _t69*_t89;
  const double _t1841 = _t529*_t782;
  const double _t1842 = 0.18e2*_t473;
  const double _t1844 = 0.3e1*_t288;
  const double _t1848 = _t1265*_t4;
  const double _t1849 = _t1286*_t25;
  const double _t1851 = (0.7e1 / 0.9e1)*_t632;
  const double _t1852 = (0.49e2 / 0.27e2)*_t1515;
  const double _t1854 = _t289*_t4;
  const double _t1858 = _t1479*_t4;
  const double _t1860 = _t1841*_t8;
  const double _t1861 = (0.11e2 / 0.9e1)*_t632;
  const double _t1867 = _t792*_t794;
  const double _t1868 = _t27*_t796;
  const double _t1885 = _t49*_t821;
  const double _t1916 = _t1242 + _t1243;
  const double _t1917 = (_t288 * _t288);
  const double _t1918 = (_t89 * _t89 * _t89 * _t89);
  const double _t1919 = _t1918*_t8;
  const double _t1921 = _t1265 + _t1267;
  const double _t1922 = -_t1921;
  const double _t1923 = _t288*_t785;
  const double _t1926 = _t136*_t1369 + _t478;
  const double _t1927 = _t1275 + _t136*_t1367;
  const double _t1929 = gbb/xc_powr(nb, 20, 3);
  const double _t1930 = xc_powr(nb, -16, 3);
  const double _t1931 = _t429/xc_powi(nb, 8);
  const double _t1933 = _t1182/xc_powr(nb, 28, 3);
  const double _t1934 = (0.448e3 / 0.9e1)*_t824;
  const double _t1935 = (0.1120e4 / 0.27e2)*_t795;
  const double _t1937 = (0.256e3 / 0.27e2)*_t799;
  const double _t1941 = (0.56e2 / 0.3e1)*_t329;
  const double _t1954 = -_t1916;
  const double _t1955 = (_t313 * _t313);
  const double _t1956 = (_t88 * _t88 * _t88 * _t88);
  const double _t1957 = -_t1275 - _t1276;
  const double _t1959 = _t1929*_t8;
  const double _t1963 = _t1933*_t8;
  const double _t1972 = _t1956*_t8;
  const double _t1983 = _t313*_t822;
  const double _t1990 = xc_powr(na, -25, 3);
  const double _t1991 = _t1990*gaa;
  const double _t1992 = _t508*_t8;
  const double _t1993 = (0.8e1 / 0.81e2)*_t1991;
  const double _t1995 = _t1*_t514;
  const double _t1996 = (0.14e2 / 0.3e1)*_t891;
  const double _t1997 = (0.8e1 / 0.3e1)*_t858;
  const double _t2002 = _t1228*_t858;
  const double _t2014 = (0.1e1 / 0.8e1)*_t8;
  const double _t2021 = (0.1e1 / 0.24e2)*_t42;
  const double _t2027 = (0.5e1 / 0.9e1)*_t8;
  const double _t2028 = (0.1e1 / 0.27e2)*_t148;
  const double _t2034 = (0.7e1 / 0.162e3)*_t244;
  const double _t2036 = (0.11e2 / 0.18e2)*_t8;
  const double _t2041 = (0.7e1 / 0.162e3)*_t8;
  const double _t2064 = _t112*_t850;
  const double _t2065 = _t1*_t853;
  const double _t2090 = (0.7e1 / 0.162e3)*_t891;
  const double _t2091 = (0.1e1 / 0.81e2)*_t42;
  const double _t2092 = (0.1e1 / 0.81e2)*_t148;
  const double _t2093 = (0.1e1 / 0.162e3)*_t148;
  const double _t2134 = _t122*_t986;
  const double _t2135 = _t27*_t989;
  const double _t2156 = (0.7e1 / 0.162e3)*_t1012;
  const double _t2164 = xc_powr(nb, -25, 3);
  const double _t2165 = _t2164*gbb;
  const double _t2166 = _t792*_t8;
  const double _t2167 = (0.8e1 / 0.81e2)*_t2165;
  const double _t2168 = _t27*_t798;
  const double _t2169 = (0.14e2 / 0.3e1)*_t1012;
  const double _t2170 = (0.8e1 / 0.3e1)*_t997;
  const double _t2175 = _t1228*_t997;
  const double _t2191 = xc_powr(na, -22, 3);
  const double _t2192 = _t112*_t852;
  const double _t2194 = _t161*_t2191;
  const double _t2197 = (0.11e2 / 0.36e2)*_t8;
  const double _t2202 = _t1029*_t880;
  const double _t2226 = (0.1e1 / 0.144e3)*_t8;
  const double _t2228 = (0.5e1 / 0.72e2)*_t8;
  const double _t2229 = _t408*_t8;
  const double _t2230 = (0.19e2 / 0.72e2)*_t8;
  const double _t2234 = (0.1e1 / 0.432e3)*_t42;
  const double _t2235 = (0.1e1 / 0.108e3)*_t148;
  const double _t2236 = (0.1e1 / 0.216e3)*_t148;
  const double _t2263 = _t1026*_t403;
  const double _t2269 = (0.1e1 / 0.864e3)*_t42;
  const double _t2271 = _t1117*_t430;
  const double _t2289 = _t435*_t8;
  const double _t2300 = xc_powr(nb, -22, 3);
  const double _t2301 = _t122*_t988;
  const double _t2317 = _t1147*_t65;
  const double _t2319 = xc_powr(na, -19, 3);
  const double _t2320 = _t2319*_t408;
  const double _t2326 = _t1148*_t2;
  const double _t2327 = _t1151*_t405;
  const double _t2328 = _t1152*_t1154;
  const double _t2329 = (0.1e1 / 0.3456e4)*_t1176;
  const double _t2337 = _t1172*_t8;
  const double _t2350 = (0.1e1 / 0.16e2)*_t8;
  const double _t2359 = (0.1e1 / 0.384e3)*_t1156;
  const double _t2360 = (0.1e1 / 0.96e2)*_t42;
  const double _t2362 = _t1181*_t28;
  const double _t2363 = _t1184*_t432;
  const double _t2364 = _t1185*_t1187;
  const double _t2400 = _t1180*_t98;
  const double _t2401 = xc_powr(nb, -19, 3);
  const double _t2402 = _t2401*_t435;
  const double _t2416 = xc_powr(gaa, -7, 2);
  const double _t2417 = (0.1e1 / (gaa * gaa * gaa));
  const double _t2418 = _t1150*_t1309;
  const double _t2419 = _t1147*_t1152;
  const double _t2420 = (0.3e1 / 0.128e3)*_t2419;
  const double _t2425 = (0.1e1 / 0.36864e5)*(M_CBRT3 * M_CBRT3)*((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega))/((M_PI * M_PI)*(M_CBRTPI * M_CBRTPI));
  const double _t2428 = (0.9e1 / 0.64e2)*_t8;
  const double _t2431 = (0.1e1 / 0.9216e4)*_t1176;
  const double _t2433 = (0.1e1 / 0.1536e4)*_t1176;
  const double _t2434 = xc_powr(gbb, -7, 2);
  const double _t2435 = (0.1e1 / (gbb * gbb * gbb));
  const double _t2436 = _t1180*_t1185;
  const double _t2437 = (0.3e1 / 0.128e3)*_t2436;
  const double _t1320 = (0.32e2 / 0.3e1)*_t220;
  const double _t1323 = _hc0[1]*_t1322;
  const double _t1325 = _hc0[1]*_t1324;
  const double _t1329 = 0.16e2*_t80;
  const double _t1337 = _t716*_t75;
  const double _t1338 = _t161*_t198;
  const double _t1339 = -_t1332*_t588 + _t1337*_t1338 + _t1337*_t158 + _t202 + _t226;
  const double _t1340 = _t1332*_t281;
  const double _t1341 = _t201*_t75;
  const double _t1342 = _t198*_t218;
  const double _t1343 = _t149*_t21;
  const double _t1354 = _t1232*_t21;
  const double _t1358 = _t281*_t552;
  const double _t1359 = _t198*_t210;
  const double _t1360 = _t276*_t672;
  const double _t1390 = _t1237*_t21;
  const double _t1393 = _t1392*_t573;
  const double _t1394 = _t148*_t221;
  const double _t1396 = _hc0[1]*_t81;
  const double _t1397 = _t1396*_t578;
  const double _t1398 = _t148*_t225;
  const double _t1401 = _t515*_t890;
  const double _t1402 = _hc0[4]*_t425;
  const double _t1404 = _t214*_t42;
  const double _t1405 = _t1357*_t893;
  const double _t1407 = _hc0[1]*_hc0[3];
  const double _t1408 = _t1407*_t214;
  const double _t1409 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t1410 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t1411 = _t1410*_t21;
  const double _t1412 = _t1409*_t1411;
  const double _t1414 = _t42*_t586;
  const double _t1415 = ((_hc0[2]) * (_hc0[2]));
  const double _t1416 = _t1415*_t214;
  const double _t1417 = _hc0[2]*_t212;
  const double _t1418 = _t1417*_t21*_t583;
  const double _t1419 = _hc1[4]*_t92;
  const double _t1420 = _hc1[1]*_hc1[2];
  const double _t1421 = _t1420*_t553;
  const double _t1422 = (0.8e1 / 0.27e2)*_t208;
  const double _t1423 = _t1422*_t42;
  const double _t1425 = _hc1[1]*_hc1[3]*_t1422;
  const double _t1426 = _t1424*_t20;
  const double _t1427 = (0.140e3 / 0.243e3)*((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))/xc_powr(_t10, 13, 3);
  const double _t1428 = (0.2e1 / 0.9e1)*_t208;
  const double _t1429 = ((_hc1[2]) * (_hc1[2]))*_t1428;
  const double _t1430 = (0.28e2 / 0.27e2)*_t206*_t590;
  const double _t1431 = _hc1[2]*_t1430;
  const double _t1433 = _t213*_t855;
  const double _t1434 = _t1433*_t76*gaa;
  const double _t1435 = _hc0[1]*_t578;
  const double _t1436 = _t13*_t42;
  const double _t1437 = _t1436*_t76;
  const double _t1438 = _t13*_t541;
  const double _t1439 = _t220*_t547;
  const double _t1440 = _t13*_t544;
  const double _t1441 = _hc0[3]*_t515;
  const double _t1442 = _t1068*_t8;
  const double _t1443 = _t585*_t76*_t8;
  const double _t1444 = _t1433*gaa;
  const double _t1445 = _t1444*_t218;
  const double _t1446 = _t224*_t548;
  const double _t1447 = _t198*_t546;
  const double _t1448 = _t589*_t75;
  const double _t1449 = _t13*_t220;
  const double _t1451 = _t1421*_t208;
  const double _t1454 = _t13*_t224;
  const double _t1456 = _t1341*_t276;
  const double _t1457 = _t139*_t673;
  const double _t1458 = _t481*_t673;
  const double _t1460 = _t191*_t695;
  const double _t1461 = _t1428*_t8;
  const double _t1462 = _hc1[1]*_t1461*_t205;
  const double _t1463 = _t191*_t698;
  const double _t1464 = _t1342*_t696;
  const double _t1465 = _t1453*_t198;
  const double _t1564 = _t219*_t518;
  const double _t1565 = _hc0[1]*_t524;
  const double _t1567 = _t181*_t664;
  const double _t1579 = _t53*_t75;
  const double _t1581 = _t227*_t93;
  const double _t1584 = 0.3e1*_t227;
  const double _t1586 = 0.3e1*_t283;
  const double _t1593 = _t281*_t677;
  const double _t1594 = _t1593*_t79;
  const double _t1595 = _t210*_t648;
  const double _t1596 = _t706*_t76;
  const double _t1597 = _hc1[2]*_t692;
  const double _t1598 = _t1597*_t672;
  const double _t1599 = _hc1[3]*_t694;
  const double _t1600 = _t1599*_t672;
  const double _t1603 = _t1602*_t696;
  const double _t1604 = _t591*_t694;
  const double _t1605 = _t1234*_t1604;
  const double _t1606 = _t1454*_t274;
  const double _t1607 = _t1270*_t674;
  const double _t1608 = -0.2e1 / 0.27e2*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t42*_t69*_t74*_t89*p->cam_omega + _t1354 + _t1607 + _t280*_t648;
  const double _t1611 = _hc1[1]*_t138;
  const double _t1636 = (0.4e1 / 0.27e2)*_t939;
  const double _t1637 = _t248*_t75;
  const double _t1639 = _t1506*_t591;
  const double _t1640 = _t209*_t692;
  const double _t1641 = _hc1[3]*_t75;
  const double _t1642 = _t1479*_t1641;
  const double _t1644 = _t245*_t734;
  const double _t1646 = _t1637*_t276;
  const double _t1648 = _t278*_t89;
  const double _t1649 = _t1518*_t209;
  const double _t1650 = _t1427*_t20;
  const double _t1651 = _t1431*_t20;
  const double _t1652 = _t69*_t698;
  const double _t1653 = _t205*_t663;
  const double _t1654 = _t1428*_t42;
  const double _t1655 = _t69*_t695;
  const double _t1656 = _hc1[1]*_t1542*_t208;
  const double _t1657 = _t1422*_t8;
  const double _t1660 = _t1461*_t73;
  const double _t1661 = _t274*_t574;
  const double _t1662 = _t1444*_t274;
  const double _t1663 = _t585*_t699;
  const double _t1664 = _t1436*_t274;
  const double _t1665 = _t213*_t699;
  const double _t1666 = _t674*_t8;
  const double _t1667 = _t1653*_t208;
  const double _t1668 = _t155*_t75;
  const double _t1669 = _t1390 - _t1668*_t277 + _t198*_t732 + _t674*_t706;
  const double _t1769 = _t219*_t654;
  const double _t1770 = _hc0[1]*_t655;
  const double _t1773 = _t285*_t717;
  const double _t1775 = _t84*_t93;
  const double _t1781 = _t158*_t75;
  const double _t1782 = -_t1778*_t588 + _t1781*_t663 + _t296;
  const double _t1786 = 0.4e1*_t283;
  const double _t1792 = _t295*_t648;
  const double _t1793 = _t591*_t726;
  const double _t1796 = _hc1[1]*_t480;
  const double _t1807 = _t635*_t75;
  const double _t1808 = _t209*_t89;
  const double _t1809 = _t1808*_t4;
  const double _t1810 = _t1809*_t632;
  const double _t1811 = _t8*_t980;
  const double _t1812 = (0.4e1 / 0.81e2)*_t1449;
  const double _t1813 = (0.2e1 / 0.81e2)*_t1444;
  const double _t1814 = _t13*_t702;
  const double _t1815 = _t198*_t636;
  const double _t1816 = _t8*_t981;
  const double _t1817 = _t288*_t696;
  const double _t1818 = _t288*_t673;
  const double _t1819 = _t692*_t734;
  const double _t1820 = _hc1[2]*_t89;
  const double _t1821 = _t1820*_t672;
  const double _t1823 = _t294*_t716;
  const double _t1824 = _t1808*_t218;
  const double _t1828 = _hc1[1]*_t1461*_t294;
  const double _t1833 = 0.3e1*_t297;
  const double _t1834 = _t198*_t252;
  const double _t1835 = _t1834*_t75;
  const double _t1839 = 0.2e1*_t292;
  const double _t1853 = _t281*_t781;
  const double _t1855 = _t1420*_t782;
  const double _t1856 = _t1855*_t208;
  const double _t1857 = _t1808*_t636;
  const double _t1859 = _t1637*_t1820;
  const double _t1862 = _t1652*_t89;
  const double _t1863 = _t1655*_t89;
  const double _t1864 = _t1660*_t1820;
  const double _t1865 = (0.4e1 / 0.81e2)*_t703;
  const double _t1866 = _t1834*_t735;
  const double _t1912 = _t1778*_t281;
  const double _t1915 = _t463*_t75;
  const double _t1920 = _t1341*_t1820;
  const double _t1924 = _t1270*_t1808;
  const double _t1925 = _t289*_t695;
  const double _t1928 = _t289*_t698;
  const double _t1994 = _hc0[3]*_t577;
  const double _t1998 = _t425*_t855;
  const double _t1999 = (0.7e1 / 0.18e2)*_t1998;
  const double _t2000 = _hc0[1]*_t573;
  const double _t2003 = 0.2e1*_t359;
  const double _t2004 = 0.2e1*_t362;
  const double _t2008 = _t13*_t22;
  const double _t2009 = _t2008*_t344;
  const double _t2012 = (0.3e1 / 0.2e1)*_t115;
  const double _t2015 = _t2014*_t21;
  const double _t2016 = _t115*_t2015;
  const double _t2022 = _t2021*_t357;
  const double _t2023 = _t118*_t354;
  const double _t2029 = _t2028*_t357;
  const double _t2030 = _t858*_t890;
  const double _t2031 = _t354*_t880;
  const double _t2032 = _t42*_t888;
  const double _t2033 = _t1396*_t42;
  const double _t2035 = _t2034*_t357;
  const double _t2037 = _t585*_t858;
  const double _t2038 = _t13*_t219;
  const double _t2039 = _t880*_t897;
  const double _t2040 = _t248*_t354;
  const double _t2042 = _t2041*_t354;
  const double _t2043 = _t355*_t696;
  const double _t2066 = _t425*_t856;
  const double _t2070 = _hc0[1]*_t862;
  const double _t2071 = _t379*_t657;
  const double _t2075 = _t355*_t75;
  const double _t2079 = _t351*_t874;
  const double _t2087 = _t274*_t901;
  const double _t2088 = _t252*_t354;
  const double _t2094 = _t115*_t1436;
  const double _t2095 = (0.1e1 / 0.162e3)*_t2094;
  const double _t2096 = (0.4e1 / 0.81e2)*_t1666;
  const double _t2097 = -0.1e1 / 0.108e3*_hc0[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t42*_t69*_t74*_t89*p->cam_omega - 0.1e1 / 0.162e3*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t340*_t42*_t74*_t89*p->cam_omega + _t2035 + _t2087*_t2091 + _t2091*_t942 + (0.1e1 / 0.81e2)*_t2094*_t674;
  const double _t2128 = _t297*_t870;
  const double _t2129 = 0.2e1*_t379;
  const double _t2132 = _t897*_t944;
  const double _t2133 = (0.2e1 / 0.81e2)*_t737;
  const double _t2163 = _t355*_t735;
  const double _t2196 = _hc0[2]*_t215;
  const double _t2198 = _t1033*_t415;
  const double _t2199 = (0.1e1 / 0.72e2)*_t1029*_t2198;
  const double _t2200 = _t1029*_t2008*_t893;
  const double _t2214 = (0.1e1 / 0.96e2)*_t415;
  const double _t2215 = _t119*_t417;
  const double _t2218 = _t412*_t425;
  const double _t2219 = (0.1e1 / 0.16e2)*_t2218;
  const double _t2220 = _t1062*_t419;
  const double _t2221 = _t1067*_t426;
  const double _t2225 = _t353*_t593;
  const double _t2227 = _t1070*_t1074 - _t1071*_t356 + _t1072*_t356;
  const double _t2231 = _t13*_t944;
  const double _t2232 = _t1063*_t8;
  const double _t2233 = (0.1e1 / 0.216e3)*_t1112;
  const double _t2237 = -0.1e1 / 0.108e3*_hc0[2]*_t11*_t12*_t13*_t14*_t148*_t16*_t17*_t18*_t405*_t408*p->cam_omega + _t1072*_t2235 + _t1074*_t2236;
  const double _t2264 = _t1031*_t2198;
  const double _t2267 = _t1062*_t13;
  const double _t2268 = (0.1e1 / 0.432e3)*_t417;
  const double _t2270 = _t1112*_t274;
  const double _t2297 = _t274*_t353;
  const double _t2298 = _t13*_t417;
  const double _t2299 = _t1063*_t13;
  const double _t2321 = _t1410*_t213;
  const double _t2323 = _t13*_t1417;
  const double _t2325 = _t1411*_t583;
  const double _t2330 = _t1174*_t2321;
  const double _t2331 = (0.1e1 / 0.128e3)*_t415;
  const double _t2332 = _t1157*_t2331;
  const double _t2333 = _t1158*_t2331;
  const double _t2334 = (0.1e1 / 0.256e3)*_t1160*_t415;
  const double _t2338 = _t1173*_t425;
  const double _t2339 = _t1174*_t1178;
  const double _t2341 = _t114*_t1148;
  const double _t2346 = (0.3e1 / 0.4e1)*_t417;
  const double _t2351 = _t21*_t2350;
  const double _t2352 = _t2351*_t417;
  const double _t2357 = _t1150*_t413;
  const double _t2358 = (0.1e1 / 0.288e3)*_t1167;
  const double _t2361 = -0.1e1 / 0.192e3*_hc0[1]*_hc0[2]*_t11*_t1152*_t12*_t14*_t16*_t17*_t18*_t213*_t403*_t42*p->cam_omega - 0.1e1 / 0.96e2*_hc0[2]*_t11*_t1150*_t12*_t13*_t14*_t16*_t17*_t18*_t405*_t42*p->cam_omega + _t1073*_t1156*_t890 + _t1161*_t2360*_t81 + _t1404*_t2357 + _t1414*_t2359;
  const double _t2422 = _t2417*_t412;
  const double _t2423 = _t1415*_t2418;
  const double _t1223 = _t246*_t58;
  const double _t1224 = -_t1219*_t1223 + _t167;
  const double _t1225 = _t1219*_t246;
  const double _t1226 = _t149*_t35;
  const double _t1233 = _t1232*_t35;
  const double _t1235 = _t476*_t503;
  const double _t1236 = _t255*_t462;
  const double _t1238 = _t1237*_t35;
  const double _t1240 = _t463*_t57;
  const double _t1241 = _t201*_t57;
  const double _t1247 = _hc5[4]*_t59;
  const double _t1249 = _hc5[2]*_t59;
  const double _t1250 = _hc5[1]*_hc5[2];
  const double _t1251 = _t1250*_t476;
  const double _t1252 = (0.8e1 / 0.27e2)*_t164;
  const double _t1253 = _t1252*_t42;
  const double _t1255 = _hc5[1]*_t1252;
  const double _t1256 = _hc5[3]*_t1255;
  const double _t1259 = (0.140e3 / 0.243e3)*((_hc5[1]) * (_hc5[1]) * (_hc5[1]) * (_hc5[1]))*_t34/xc_powr(_t29, 13, 3);
  const double _t1260 = _t1228*_t164;
  const double _t1261 = ((_hc5[2]) * (_hc5[2]))*_t1260;
  const double _t1262 = (0.28e2 / 0.27e2)*_t162*_t502;
  const double _t1263 = _hc5[2]*_t1262;
  const double _t1264 = _t1241*_t255;
  const double _t1269 = _t482*_t59;
  const double _t1271 = _t165*_t49;
  const double _t1272 = _t1270*_t1271;
  const double _t1273 = _t1271*_t218;
  const double _t1274 = _t166*_t49;
  const double _t1278 = _t59*_t641;
  const double _t1279 = _t140*_t166;
  const double _t1280 = _t1260*_t157;
  const double _t1281 = _hc5[1]*_t1280;
  const double _t1311 = _hc0[4]*_t63;
  const double _t1315 = _hc0[3]*_hc2[0];
  const double _t1316 = _t1315*_t71;
  const double _t1318 = _hc2[4]*_t72;
  const double _t1319 = _hc0[2]*_t183;
  const double _t1321 = _hc0[3]*_t183;
  const double _t1326 = _t521*_t869;
  const double _t1327 = _hc0[0]*_hc2[3];
  const double _t1328 = _t1327*_t521;
  const double _t1330 = _t181*_t530;
  const double _t1331 = _hc2[2]*_t1330;
  const double _t1333 = -0.1e1 / 0.36e2*_hc3[5]*_t23*_t24*_t42;
  const double _t1334 = (0.1e1 / 0.6e1)*_t683;
  const double _t1335 = _t1332*_t70 + _t195 + _t43*(-_t1333 - _t1334*_t529) + _t557*_t716;
  const double _t1336 = _t196*_t85;
  const double _t1347 = _t1325*_t868;
  const double _t1348 = _t667*_t71;
  const double _t1349 = 0.4e1*_t1348;
  const double _t1350 = _t196*_t264;
  const double _t1351 = _t178*_t571;
  const double _t1352 = _t182*_t227;
  const double _t1353 = _t116*_t597;
  const double _t1361 = _t1282*_t193;
  const double _t1363 = _hc1[4]*_hc3[1];
  const double _t1366 = _t139*_t192;
  const double _t1371 = _t188*_t276;
  const double _t1372 = 0.3e1*_t1371;
  const double _t1373 = _hc3[6]*_t716 + _t566;
  const double _t1374 = -0.1e1 / 0.36e2*_hc3[8]*_t23*_t24*_t42;
  const double _t1375 = _hc3[7]*_t716;
  const double _t1376 = -_hc3[5]*_t469;
  const double _t1377 = _hc3[4]*_t276;
  const double _t1378 = _hc3[9]*_t150;
  const double _t1379 = -_hc3[14]*_t44;
  const double _t1380 = -_hc3[13]*_t44;
  const double _t1381 = _hc3[12]*_t73 + _t1380;
  const double _t1382 = _hc3[8]*_t150;
  const double _t1383 = -_hc3[12]*_t44;
  const double _t1384 = _hc3[11]*_t73 + _t1383;
  const double _t1385 = _hc3[7]*_t197 + _hc3[7]*_t205 - _t1381*_t44 + _t1382 + _t1384*_t73;
  const double _t1386 = -_hc3[4]*_t469;
  const double _t1387 = _hc3[3]*_t276;
  const double _t1388 = _hc3[7]*_t150;
  const double _t1389 = -_hc3[11]*_t44;
  const double _t1466 = _hc4[1]*_t808;
  const double _t1477 = _t107*_t60;
  const double _t1480 = _t57*_t9;
  const double _t1482 = 0.3e1*_t258;
  const double _t1486 = _t465*_t648;
  const double _t1487 = _t462*_t88;
  const double _t1489 = _t146*_t503;
  const double _t1490 = _t1489*_t88;
  const double _t1491 = _t1270*_t616;
  const double _t1492 = -0.2e1 / 0.27e2*_hc5[2]*_t12*_t16*_t17*_t18*_t32*_t42*_t49*_t56*_t88*p->cam_omega + _t1233 + _t1491 + _t254*_t648;
  const double _t1513 = _t53*_t57;
  const double _t1514 = _t248*_t57;
  const double _t1519 = _t1518*_t165*_t4;
  const double _t1522 = _t255*_t57;
  const double _t1523 = _t1251*_t164;
  const double _t1524 = _t165*_t88;
  const double _t1525 = _t140*_t1524;
  const double _t1526 = _t1271*_t636;
  const double _t1527 = _t1479*_t57;
  const double _t1528 = _t1527*_t4;
  const double _t1530 = _t57*_t639;
  const double _t1531 = _hc5[2]*_t57;
  const double _t1532 = _t1513*_t88;
  const double _t1533 = _t1514*_t255;
  const double _t1534 = _t166*_t88;
  const double _t1538 = _t1259*_t8;
  const double _t1539 = _t257*_t504;
  const double _t1540 = _t157*_t164;
  const double _t1543 = _hc5[1]*_t1542;
  const double _t1544 = _t105*_t1540;
  const double _t1545 = _hc5[3]*_t59;
  const double _t1546 = _t1545*_t257;
  const double _t1547 = _hc5[3]*_t257;
  const double _t1548 = _t1252*_t8;
  const double _t1549 = _t105*_t1548;
  const double _t1551 = _t1260*_t55;
  const double _t1552 = _t1551*_t843;
  const double _t1553 = _t252*_t253;
  const double _t1554 = _t1553*_t57;
  const double _t1555 = _t218*_t253;
  const double _t1556 = (0.4e1 / 0.81e2)*_t769;
  const double _t1557 = _t1522*_t1553;
  const double _t1558 = _t155*_t57;
  const double _t1559 = _t1238 - _t1558*_t256 + _t253*_t638 + _t616*_t706;
  const double _t1561 = _t1315*_t90;
  const double _t1562 = _hc0[2]*_t262;
  const double _t1563 = _hc0[3]*_t262;
  const double _t1566 = _hc2[2]*_t660;
  const double _t1568 = _t1567*_t869;
  const double _t1569 = _t1327*_t530;
  const double _t1570 = _t261*_t527;
  const double _t1572 = _t194 + _t43*(-_t1333 - _t1334*_t658);
  const double _t1573 = _t1571*_t192 + _t1572 + _t268 + _t681*_t716;
  const double _t1574 = _t667*_t93;
  const double _t1575 = 0.3e1*_t1574;
  const double _t1576 = _t535*_t863;
  const double _t1577 = _t227*_t90;
  const double _t1578 = _hc2[1]*_t1577;
  const double _t1580 = _t527*_t868;
  const double _t1582 = _t1581*_t350;
  const double _t1583 = 0.3e1*_t1348;
  const double _t1585 = _t265*_t531;
  const double _t1587 = _t264*_t271;
  const double _t1588 = _t522*_t84;
  const double _t1589 = _t1588*_t93;
  const double _t1590 = _t182*_t283;
  const double _t1591 = _t178*_t691;
  const double _t1592 = _t116*_t527;
  const double _t1609 = _hc1[3]*_hc3[3];
  const double _t1610 = _hc1[2]*_hc3[3];
  const double _t1612 = _hc3[6]*_t663 + _t566;
  const double _t1613 = _hc3[11]*_t91 + _t1383;
  const double _t1614 = _hc3[12]*_t91 + _t1380;
  const double _t1615 = _t1382 - _t1614*_t44;
  const double _t1616 = _hc3[7]*_t1611 + _hc3[7]*_t277 + _t1613*_t73 + _t1615;
  const double _t1617 = _hc3[10]*_t91 + _t1389;
  const double _t1618 = _t1388 - _t1613*_t44;
  const double _t1620 = _hc3[7]*_t663;
  const double _t1621 = _t43*(-_t1374 - 0.1e1 / 0.6e1*_t1620) + _t568;
  const double _t1623 = _t266*_t276;
  const double _t1625 = _hc1[2]*_t188;
  const double _t1627 = _hc1[3]*_t557;
  const double _t1629 = _hc1[3]*_hc3[4];
  const double _t1630 = _hc1[2]*_hc3[4];
  const double _t1631 = _t1620 + _t563;
  const double _t1632 = _t1378 - _t44*(_hc3[13]*_t91 + _t1379);
  const double _t1633 = _t554*_t69;
  const double _t1635 = _t1361 + _t484*_t686;
  const double _t1685 = -_t1223*_t1678 + _t335;
  const double _t1691 = _t648*_t759;
  const double _t1692 = _t249*_t706;
  const double _t1694 = _t1693*_t760;
  const double _t1695 = _t1236*_t313;
  const double _t1696 = _t462*_t761;
  const double _t1697 = _t1488*_t1524;
  const double _t1698 = _t503*_t753;
  const double _t1699 = _t1234*_t1698;
  const double _t1700 = _t253*_t760;
  const double _t1701 = _t31*_t330;
  const double _t1702 = _t159*_t1701;
  const double _t1703 = _t253*_t616;
  const double _t1706 = _hc5[1]*_t137;
  const double _t1707 = _hc5[1]*_t480;
  const double _t1709 = _hc5[1]*_t474;
  const double _t1726 = _t148*_t328;
  const double _t1729 = _t148*_t331;
  const double _t1730 = _t57*_t635;
  const double _t1731 = _t158*_t57;
  const double _t1733 = _t4*_t843;
  const double _t1734 = _t1733*_t57;
  const double _t1735 = _t1520*_t1524;
  const double _t1738 = _t31*_t42;
  const double _t1739 = _t159*_t327;
  const double _t1740 = _t31*_t8;
  const double _t1741 = _t1740*_t767;
  const double _t1743 = _t321*_t992;
  const double _t1744 = _t1743*gbb;
  const double _t1745 = _t159*_t1744;
  const double _t1747 = (0.2e1 / 0.81e2)*_t1743*_t8*gbb;
  const double _t1748 = _t1740*_t768;
  const double _t1749 = _t253*_t636;
  const double _t1750 = _t161*_t253;
  const double _t1751 = _t57*_t631;
  const double _t1752 = _t31*_t327;
  const double _t1754 = _t1271*_t1541;
  const double _t1755 = _t1731*_t88;
  const double _t1756 = _t462*_t843;
  const double _t1758 = _t1524*_t218;
  const double _t1759 = _t255*_t313;
  const double _t1761 = _t164*_t318*_t55;
  const double _t1763 = _t313*_t59;
  const double _t1764 = _t1260*_t318;
  const double _t1765 = _t1271*_t313;
  const double _t1768 = _t1750*_t88;
  const double _t1771 = _hc2[2]*_t285;
  const double _t1772 = _t1771*_t530;
  const double _t1774 = _t1773*_t869;
  const double _t1776 = _hc2[1]*_t297;
  const double _t1777 = _t1776*_t71;
  const double _t1779 = _t1572 + _t1778*_t70 + _t290 + _t663*_t681;
  const double _t1780 = _t291*_t85;
  const double _t1783 = _t297*_t868;
  const double _t1784 = _t668*_t71;
  const double _t1785 = _t283*_t90;
  const double _t1787 = 0.2e1*_t719;
  const double _t1788 = _t531*_t720;
  const double _t1789 = _t264*_t291;
  const double _t1790 = _t178*_t731;
  const double _t1791 = _t116*_t657;
  const double _t1794 = _t1243*_t70;
  const double _t1795 = _hc3[6]*_t292 + _hc3[6]*_t294 + _t1617*_t91 + _t1618;
  const double _t1797 = _t1610*_t89;
  const double _t1798 = _hc3[7]*_t292 + _hc3[7]*_t294 + _t1613*_t91 + _t1615;
  const double _t1799 = _t1386 - _t1798*_t44 + _t484*_t682;
  const double _t1800 = _t1612*_t663 + _t1621 + _t1778*_t556 + _t724;
  const double _t1801 = _t289*_t554;
  const double _t1803 = _hc1[2]*_t266;
  const double _t1804 = _t1630*_t89;
  const double _t1805 = _t1376 - _t44*(_hc3[8]*_t292 + _hc3[8]*_t294 + _t1614*_t91 + _t1632) + _t484*_t684;
  const double _t1806 = _t1633*_t89;
  const double _t1829 = _t774*_t869;
  const double _t1830 = _t1327*_t774;
  const double _t1831 = 0.4e1*_t659;
  const double _t1832 = _t380*_t711;
  const double _t1836 = _t531*_t93;
  const double _t1837 = _t182*_t297;
  const double _t1838 = _t178*_t786;
  const double _t1840 = _hc3[3]*_t787 + _t1612*_t784 + _t1795*_t91 + _t1797*_t288 + _t1797*_t785 + _t1799 + _t1839*_t687 + _t556*_t781;
  const double _t1843 = 0.3e1*_t725;
  const double _t1845 = 0.3e1*_t681;
  const double _t1846 = _t192*_t288;
  const double _t1847 = _t1803*_t89;
  const double _t1850 = _t1290*_t729 + _t1361 - _t1849*_t269 - _t44*(_hc3[4]*_t787 + _t1631*_t784 + _t1798*_t91 + _t1804*_t288 + _t1804*_t785 + _t1805 + _t1839*_t682 + _t683*_t781);
  const double _t1873 = _t326*_t802;
  const double _t1874 = _hc4[1]*_t807;
  const double _t1890 = _t503*_t821;
  const double _t1891 = _t1250*_t821;
  const double _t1892 = _t164*_t1891;
  const double _t1893 = _t1524*_t636;
  const double _t1894 = _hc5[3]*_t314;
  const double _t1895 = _t1514*_t843;
  const double _t1896 = _t323*_t824;
  const double _t1897 = _t103*_t831;
  const double _t1898 = _t42*_t826;
  const double _t1899 = _hc4[1]*_t103;
  const double _t1900 = _t1899*_t829;
  const double _t1901 = _t1015*_t799;
  const double _t1902 = _t159*_t824;
  const double _t1903 = _t320*_t321;
  const double _t1904 = _t1743*_t249*gbb;
  const double _t1905 = _t799*_t835;
  const double _t1906 = _t1738*_t768;
  const double _t1907 = _hc4[1]*_t829;
  const double _t1908 = _hc4[1]*_hc4[2];
  const double _t1909 = _t1908*_t321;
  const double _t1910 = _t1909*_t799;
  const double _t1911 = _t616*_t8;
  const double _t1913 = _t1836*_t90;
  const double _t1914 = 0.4e1*_t1913;
  const double _t1945 = 0.16e2*_t102;
  const double _t1948 = _t1678*_t246;
  const double _t1953 = _t253*_t759;
  const double _t1960 = _t1930*_t828;
  const double _t1961 = _hc4[3]*_t450;
  const double _t1962 = _hc4[4]*_t450;
  const double _t1964 = (0.1e1 / ((_hc4[0]) * (_hc4[0]) * (_hc4[0]) * (_hc4[0])));
  const double _t1965 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]) * (_hc4[1]));
  const double _t1966 = _t1965*_t35;
  const double _t1967 = _t1964*_t1966;
  const double _t1968 = ((_hc4[2]) * (_hc4[2]));
  const double _t1969 = _t1968*_t322;
  const double _t1970 = _hc4[2]*_t320;
  const double _t1971 = _t1970*_t35*_t833;
  const double _t1973 = _t1738*_t249;
  const double _t1974 = _t1752*_t547;
  const double _t1975 = _t1744*_t218;
  const double _t1976 = _t1701*_t548;
  const double _t1977 = _t253*_t546;
  const double _t1978 = _t57*_t838;
  const double _t1979 = _t57*_t839;
  const double _t1980 = _t1241*_t843;
  const double _t1981 = _t1270*_t1524;
  const double _t1982 = _t1545*_t314;
  const double _t1984 = _hc5[1]*_t1764;
  const double _t1985 = _t314*_t504;
  const double _t1986 = _t822*_t843;
  const double _t1987 = _t1555*_t57;
  const double _t1988 = _t313*_t843;
  const double _t1989 = _t1453*_t253;
  const double _t2001 = _t2000*_t863;
  const double _t2005 = _hc2[4]*_hc3[0];
  const double _t2006 = _t2005*_t870;
  const double _t2007 = 0.4e1*_t534;
  const double _t2010 = _t181*_t869;
  const double _t2011 = _t2000*_t868;
  const double _t2013 = 0.2e1*_t196;
  const double _t2017 = _hc2[3]*_t2016;
  const double _t2018 = _t84*_t872;
  const double _t2019 = _hc2[1]*_t196;
  const double _t2020 = _hc2[2]*_t196;
  const double _t2024 = _t867*_t868;
  const double _t2025 = _t869*_t935;
  const double _t2026 = _t182*_t365;
  const double _t2045 = (0.3e1 / 0.2e1)*_t125;
  const double _t2046 = _t2014*_t35;
  const double _t2049 = _t2021*_t369;
  const double _t2056 = _t2028*_t369;
  const double _t2057 = _t371*_t880;
  const double _t2058 = _t371*_t465;
  const double _t2059 = _t2034*_t369;
  const double _t2060 = _t372*_t57;
  const double _t2061 = _t2041*_t371;
  const double _t2062 = _t1522*_t372;
  const double _t2063 = 0.2e1*_t950;
  const double _t2067 = _t2000*_t928;
  const double _t2068 = _t116*_t379;
  const double _t2069 = _t2000*_t380;
  const double _t2072 = _hc2[3]*_t870;
  const double _t2073 = _t84*_t934;
  const double _t2074 = _hc2[1]*_t271;
  const double _t2076 = _t1775*_t869;
  const double _t2077 = _t365*_t90;
  const double _t2078 = _hc2[3]*_t265;
  const double _t2080 = _t115*_t271;
  const double _t2081 = _hc2[2]*_t84;
  const double _t2082 = _t2080*_t874;
  const double _t2083 = 0.2e1*_t1587;
  const double _t2084 = _t116*_t866;
  const double _t2085 = _t350*_t865;
  const double _t2086 = _t115*_t875;
  const double _t2089 = _t116*_t867;
  const double _t2101 = _hc4[1]*_t999;
  const double _t2106 = _t1000*_t389;
  const double _t2115 = _t244*_t760;
  const double _t2116 = _t944*_t969;
  const double _t2117 = (0.2e1 / 0.81e2)*_t646;
  const double _t2118 = _t371*_t632*_t760;
  const double _t2119 = _t125*_t1738;
  const double _t2120 = (0.1e1 / 0.162e3)*_t2119;
  const double _t2121 = (0.2e1 / 0.27e2)*_t371;
  const double _t2122 = -0.1e1 / 0.108e3*_hc4[1]*_hc5[2]*_t12*_t122*_t16*_t17*_t18*_t28*_t31*_t32*_t42*_t49*_t56*_t88*p->cam_omega - 0.1e1 / 0.162e3*_hc5[1]*_t12*_t16*_t17*_t18*_t32*_t320*_t321*_t384*_t42*_t49*_t56*p->cam_omega + _t2059 + _t2091*_t967 + _t2091*_t972 + (0.1e1 / 0.81e2)*_t2119*_t616;
  const double _t2123 = _hc0[1]*_t931;
  const double _t2124 = _t285*_t869;
  const double _t2125 = _hc2[1]*_t291;
  const double _t2126 = _t297*_t350;
  const double _t2127 = _hc2[2]*_t93;
  const double _t2130 = _t869*_t93;
  const double _t2131 = _t2130*_t976;
  const double _t2137 = _t825*_t998;
  const double _t2153 = _t1008*_t42;
  const double _t2154 = _hc4[3]*_t1011;
  const double _t2155 = _t1899*_t42;
  const double _t2157 = (0.2e1 / 0.27e2)*_t2115;
  const double _t2158 = _t31*_t326;
  const double _t2159 = _t835*_t997;
  const double _t2160 = (0.4e1 / 0.81e2)*_t1911;
  const double _t2161 = _t380*_t867;
  const double _t2162 = _t182*_t379;
  const double _t2171 = (0.7e1 / 0.18e2)*_t992;
  const double _t2181 = _t31*_t36;
  const double _t2189 = _t371*_t759;
  const double _t2190 = _t880*_t969;
  const double _t2193 = _t1032*_t13;
  const double _t2195 = _t116*_t2191;
  const double _t2201 = _t1037*_t863;
  const double _t2203 = _t339*_t85;
  const double _t2204 = _hc2[4]*_t1050;
  const double _t2205 = _t84*_t869;
  const double _t2206 = _hc2[3]*_t410;
  const double _t2207 = _t2206*_t419*_t421;
  const double _t2208 = _t1037*_t868;
  const double _t2209 = (0.1e1 / 0.2e1)*_t534;
  const double _t2210 = _hc2[3]*_t412;
  const double _t2211 = _t2210*_t410*_t426;
  const double _t2212 = _t1043*_t171;
  const double _t2213 = _t1049*_t412;
  const double _t2216 = _hc2[2]*_t1051;
  const double _t2217 = _t1045*_t408;
  const double _t2222 = (0.8e1 / 0.3e1)*_t877;
  const double _t2223 = _t350*_t365;
  const double _t2224 = _t2079*_t869;
  const double _t2245 = (0.1e1 / 0.96e2)*_t437;
  const double _t2255 = _t159*_t353;
  const double _t2256 = _t31*_t443;
  const double _t2257 = _t103*_t356;
  const double _t2258 = _t1070*_t1103 - _t1097*_t2257 + _t2257*_t443;
  const double _t2259 = (0.1e1 / 0.144e3)*_t1097*_t1740;
  const double _t2260 = (0.1e1 / 0.216e3)*_t1100;
  const double _t2261 = _t1100*_t159;
  const double _t2262 = -0.1e1 / 0.108e3*_hc4[2]*_t12*_t148*_t16*_t17*_t18*_t30*_t31*_t32*_t432*_t435*p->cam_omega + _t103*_t2235*_t443 + _t1103*_t2236;
  const double _t2265 = _t1037*_t928;
  const double _t2266 = _t1037*_t380;
  const double _t2288 = 0.2e1*_t400;
  const double _t2290 = _t2289*_t969;
  const double _t2291 = (0.1e1 / 0.432e3)*_t443;
  const double _t2292 = _t1100*_t249;
  const double _t2293 = _t1120*_t1909;
  const double _t2294 = (0.1e1 / 0.2e1)*_t714;
  const double _t2295 = _t1108*_t93;
  const double _t2296 = _hc2[2]*_t421;
  const double _t2302 = _t1010*_t2300;
  const double _t2304 = _hc4[2]*_t323;
  const double _t2308 = (0.1e1 / 0.72e2)*_t1124;
  const double _t2309 = _t1120*_t2181;
  const double _t2310 = _t322*_t880;
  const double _t2311 = _t1124*_t2310;
  const double _t2316 = _t353*_t840;
  const double _t2318 = _hc3[0]*_t1150;
  const double _t2322 = _t2319*_t411*_t415;
  const double _t2324 = _t2319*_t424;
  const double _t2335 = _t21*_t863;
  const double _t2336 = _t1162*_t2335;
  const double _t2340 = _hc2[3]*_t2339;
  const double _t2342 = _t2318*_t2331;
  const double _t2343 = _t21*_t868;
  const double _t2344 = _t1162*_t2343;
  const double _t2345 = _t2005*_t2339;
  const double _t2347 = _t365*_t410;
  const double _t2348 = (0.3e1 / 0.4e1)*_t422;
  const double _t2349 = (0.1e1 / 0.64e2)*_t2210*_t415;
  const double _t2353 = _t2296*_t2351;
  const double _t2354 = (0.3e1 / 0.32e2)*_hc2[2]*_t2218;
  const double _t2355 = (0.3e1 / 0.2e1)*_t117;
  const double _t2356 = _t2016*_t350;
  const double _t2365 = _hc4[2]*_t1189;
  const double _t2366 = _t1183*_t1194;
  const double _t2367 = _t1196*_t834;
  const double _t2370 = _t1189*_t8*_t834;
  const double _t2371 = _t1183*_t1206;
  const double _t2372 = _t1212*_t834;
  const double _t2374 = _t1181*_t124;
  const double _t2385 = _t2350*_t35;
  const double _t2390 = _t1166*_t1197;
  const double _t2391 = _t1183*_t438;
  const double _t2392 = _t2391*_t321;
  const double _t2393 = (0.1e1 / 0.384e3)*_t835;
  const double _t2394 = -0.1e1 / 0.192e3*_hc4[1]*_hc4[2]*_t1185*_t12*_t16*_t17*_t18*_t30*_t32*_t321*_t42*_t430*p->cam_omega - 0.1e1 / 0.96e2*_hc4[2]*_t1183*_t12*_t16*_t17*_t18*_t30*_t31*_t32*_t42*_t432*p->cam_omega + _t103*_t1073*_t1202 + _t103*_t1197*_t2360 + (0.1e1 / 0.384e3)*_t1188*_t42*_t836 + _t2391*_t322*_t42;
  const double _t2395 = _t21*_t928;
  const double _t2396 = _t1162*_t2395;
  const double _t2397 = _t379*_t410;
  const double _t2398 = _t21*_t380;
  const double _t2399 = _t1162*_t2398;
  const double _t2403 = _t1965*_t321;
  const double _t2405 = _t1970*_t31;
  const double _t2415 = _t249*_t8;
  const double _t2421 = _t1032*_t2418;
  const double _t2424 = _t1309*_t2318;
  const double _t2426 = _t1163*_t8;
  const double _t2427 = (0.5e1 / 0.64e2)*_t2426;
  const double _t2429 = _t116*_t2418;
  const double _t2430 = _t2429*_t8;
  const double _t2432 = _hc2[3]*_t2424;
  const double _t2439 = _t2435*_t437;
  const double _t1214 = _hc6[4]*_t52;
  const double _t1215 = _hc6[3]*_t454;
  const double _t1216 = 0.4e1*_t132;
  const double _t1220 = -0.1e1 / 0.36e2*_hc7[5]*_t23*_t24*_t42;
  const double _t1221 = _t1219*_t50 + _t152 + _t43*(-_t1220 - 0.1e1 / 0.6e1*_t142);
  const double _t1222 = _hc4[0]*_t456;
  const double _t1229 = _t1216*_t374;
  const double _t1230 = _hc6[1]*_t458;
  const double _t1231 = _t131*_t168;
  const double _t1283 = _hc7[2]*_t1282*_t25;
  const double _t1284 = _hc5[4]*_hc7[1];
  const double _t1285 = _t140*_t147;
  const double _t1287 = _t143*_t25;
  const double _t1288 = 0.3e1*_t145;
  const double _t1289 = _t1288*_t255;
  const double _t1291 = 0.3e1*_t495;
  const double _t1292 = -_hc7[5]*_t469;
  const double _t1293 = _hc7[4]*_t255;
  const double _t1294 = 0.2e1*_t490;
  const double _t1295 = _hc7[9]*_t150;
  const double _t1296 = -_hc7[14]*_t44;
  const double _t1297 = -_hc7[13]*_t44;
  const double _t1298 = _hc7[12]*_t55 + _t1297;
  const double _t1299 = _hc7[8]*_t150;
  const double _t1300 = -_hc7[12]*_t44;
  const double _t1301 = _hc7[11]*_t55 + _t1300;
  const double _t1302 = _hc7[7]*_t154 + _hc7[7]*_t157 - _t1298*_t44 + _t1299 + _t1301*_t55;
  const double _t1303 = -_hc7[4]*_t469;
  const double _t1304 = _hc7[3]*_t255;
  const double _t1305 = 0.2e1*_t494;
  const double _t1306 = _hc7[7]*_t150;
  const double _t1307 = -_hc7[11]*_t44;
  const double _t1467 = _t1466*_t51;
  const double _t1468 = _t130*_t961;
  const double _t1469 = _t151 + _t43*(-_t1220 - 0.1e1 / 0.6e1*_t236);
  const double _t1470 = 0.3e1*_t1469 + 0.3e1*_t241;
  const double _t1471 = _t1466*_t61;
  const double _t1472 = _t374*_t601;
  const double _t1473 = _t234*_t374;
  const double _t1474 = _t168*_t394;
  const double _t1475 = _hc4[0]*_hc6[1];
  const double _t1476 = _t1475*_t242;
  const double _t1478 = _t1477*_t455;
  const double _t1481 = _t374*_t617;
  const double _t1483 = _t131*_t258;
  const double _t1484 = _t230*_t496;
  const double _t1485 = _hc6[1]*_t506;
  const double _t1495 = _hc7[11]*_t105 + _t1300;
  const double _t1496 = _hc7[12]*_t105 + _t1297;
  const double _t1497 = _t1299 - _t1496*_t44;
  const double _t1498 = _hc7[7]*_t256 - _hc7[7]*_t621 + _t1495*_t55 + _t1497;
  const double _t1499 = _hc7[10]*_t105 + _t1307;
  const double _t1500 = _t1306 - _t1495*_t44;
  const double _t1501 = 0.2e1*_t629;
  const double _t1503 = _t239*_t255;
  const double _t1505 = _t485*_t88;
  const double _t1507 = _hc7[4]*_t88;
  const double _t1508 = _t1295 - _t44*(_hc7[13]*_t105 + _t1296);
  const double _t1509 = _t257*_t477;
  const double _t1510 = _t145*_t255;
  const double _t1512 = _t1283 + _t484*_t625;
  const double _t1670 = _hc7[0]*_t326;
  const double _t1671 = _t1670*_t743;
  const double _t1672 = _t600*_t741;
  const double _t1673 = _t101*_t603;
  const double _t1674 = _t1088*_t309;
  const double _t1676 = _hc4[1]*_t51;
  const double _t1677 = _t1675*_t1676;
  const double _t1679 = _t1469 + _t1678*_t50 + _t315;
  const double _t1680 = (0.16e2 / 0.3e1)*_t242;
  const double _t1681 = _hc4[0]*_t745;
  const double _t1682 = _t153*_t235;
  const double _t1683 = _hc4[0]*_t242;
  const double _t1684 = _hc6[1]*_t750;
  const double _t1686 = _t258*_t394;
  const double _t1687 = _t336*_t374;
  const double _t1688 = _t230*_t630;
  const double _t1689 = _hc6[1]*_t650;
  const double _t1690 = 0.2e1*_t612;
  const double _t1704 = -_t1243*_t50;
  const double _t1705 = _hc7[6]*_t317 + _hc7[6]*_t318 + _t105*_t1499 + _t1500;
  const double _t1708 = 0.2e1*_t626;
  const double _t1710 = _hc5[2]*_t627;
  const double _t1711 = _hc7[7]*_t317 + _hc7[7]*_t318 + _t105*_t1495 + _t1497;
  const double _t1712 = _t1303 - _t1711*_t44 + _t484*_t622;
  const double _t1713 = _t314*_t477;
  const double _t1715 = 0.2e1*_t619;
  const double _t1716 = _t755*_t88;
  const double _t1720 = 0.2e1*_t622;
  const double _t1721 = _hc5[2]*_t1507;
  const double _t1722 = _t1292 - _t44*(_hc7[8]*_t317 + _hc7[8]*_t318 + _t105*_t1496 + _t1508) + _t484*_t623;
  const double _t1869 = _hc4[3]*_hc6[0];
  const double _t1870 = _t1869*_t51;
  const double _t1871 = _hc4[2]*_t232;
  const double _t1872 = _hc4[3]*_t232;
  const double _t1875 = _hc6[3]*_t805;
  const double _t1876 = _t1670*_t802;
  const double _t1877 = _t600*_t807;
  const double _t1878 = _t101*_t812;
  const double _t1879 = _t600*_t751;
  const double _t1880 = _t132*_t394;
  const double _t1881 = _t230*_t758;
  const double _t1882 = _t131*_t336;
  const double _t1883 = _hc6[1]*_t772;
  const double _t1884 = _hc7[3]*_t838 + _hc7[3]*_t839 + _t105*_t1705 + _t1708*_t317 + _t1708*_t318 + _t1710*_t313 + _t1710*_t822 + _t1712;
  const double _t1886 = 0.3e1*_t752;
  const double _t1887 = 0.3e1*_t239;
  const double _t1888 = _t147*_t313;
  const double _t1889 = _t1283 + _t1290*_t756 - _t1849*_t237 - _t44*(_hc7[4]*_t838 + _hc7[4]*_t839 + _t105*_t1711 + _t1720*_t317 + _t1720*_t318 + _t1721*_t313 + _t1721*_t822 + _t1722);
  const double _t1932 = _hc4[4]*_t96;
  const double _t1936 = _t101*_t1869;
  const double _t1938 = _hc4[2]*_t310;
  const double _t1939 = (0.32e2 / 0.3e1)*_t1670*gbb;
  const double _t1940 = _hc4[3]*_t310;
  const double _t1942 = _t1941*_t600;
  const double _t1943 = _t1675*_t600;
  const double _t1944 = 0.4e1*_t234;
  const double _t1946 = _t101*_t1945;
  const double _t1947 = _t235*_t316;
  const double _t1949 = _t1943*_t394;
  const double _t1950 = _t1944*_t394;
  const double _t1951 = _t230*_t823;
  const double _t1952 = _hc6[1]*_t845;
  const double _t1958 = _t1887*_t843;
  const double _t2044 = _hc6[4]*_t376;
  const double _t2047 = _t2046*_t912;
  const double _t2048 = _hc6[3]*_t130;
  const double _t2050 = _t374*_t917;
  const double _t2051 = _t125*_t153;
  const double _t2052 = _hc6[2]*_t168;
  const double _t2053 = _t374*_t909;
  const double _t2054 = _t131*_t373;
  const double _t2055 = _t1088*_t376;
  const double _t2098 = 0.2e1*_t975;
  const double _t2099 = _t383*_t395;
  const double _t2100 = _t383*_t398;
  const double _t2102 = _t101*_t958;
  const double _t2103 = _hc6[1]*_t373;
  const double _t2104 = _t51*_t603;
  const double _t2105 = _t374*_t51;
  const double _t2107 = _t373*_t394;
  const double _t2108 = _t125*_t242;
  const double _t2109 = _t1475*_t609;
  const double _t2110 = _t2108*_t913;
  const double _t2111 = _hc6[1]*_t601;
  const double _t2112 = _t374*_t400;
  const double _t2113 = _t376*_t961;
  const double _t2114 = _hc6[2]*_t258;
  const double _t2136 = _t451*_t51;
  const double _t2138 = _hc6[1]*_t1676;
  const double _t2139 = _hc7[0]*_t450;
  const double _t2140 = _t374*_t600;
  const double _t2141 = _t51*_t958;
  const double _t2142 = _t128*_t912;
  const double _t2143 = _hc6[3]*_t309;
  const double _t2144 = _hc7[0]*_t1002;
  const double _t2145 = _t394*_t953;
  const double _t2146 = _t125*_t316;
  const double _t2147 = _t128*_t374;
  const double _t2148 = _hc6[2]*_t336;
  const double _t2149 = _t375*_t913;
  const double _t2150 = _t2149*_t961;
  const double _t2151 = _t131*_t400;
  const double _t2152 = _hc6[1]*_t749;
  const double _t2172 = _t101*_t451;
  const double _t2173 = _hc6[1]*_t101;
  const double _t2174 = _hc4[1]*_t2173*_t825;
  const double _t2176 = _hc7[0]*_t395;
  const double _t2177 = 0.2e1*_t2176;
  const double _t2178 = _t386*_t600;
  const double _t2179 = 0.2e1*_t2178;
  const double _t2180 = 0.4e1*_t811;
  const double _t2182 = _t2181*_t956;
  const double _t2183 = _t394*_t600*_t825;
  const double _t2184 = (0.3e1 / 0.2e1)*_t392;
  const double _t2185 = 0.2e1*_t316;
  const double _t2186 = _t2046*_t392;
  const double _t2187 = _t1007*_t394;
  const double _t2188 = _t394*_t909;
  const double _t2238 = _hc7[0]*_t1086;
  const double _t2239 = _hc7[0]*_t1087;
  const double _t2240 = _hc6[4]*_t1133;
  const double _t2241 = _t1091*_t444;
  const double _t2242 = _t1091*_t448;
  const double _t2243 = _t1093*_t450;
  const double _t2244 = (0.1e1 / 0.2e1)*_t602;
  const double _t2246 = _t1081*_t447;
  const double _t2247 = _t1094*_t437;
  const double _t2248 = _hc6[2]*_t373;
  const double _t2249 = _t1080*_t300;
  const double _t2250 = _t1082*_t435;
  const double _t2251 = _t1097*_t446;
  const double _t2252 = _t1099*_t452;
  const double _t2253 = _t1088*_t2149;
  const double _t2254 = _hc6[3]*_t1133;
  const double _t2272 = _t441*_t51;
  const double _t2273 = _t2272*_t31;
  const double _t2274 = _t2138*_t825;
  const double _t2275 = _hc6[1]*_t322;
  const double _t2276 = _t2275*_t51;
  const double _t2277 = _t1089*_t1208;
  const double _t2278 = _t2140*_t825;
  const double _t2279 = _hc7[0]*_t322;
  const double _t2280 = _t2279*_t374;
  const double _t2281 = _t389*_t439;
  const double _t2282 = _hc6[2]*_t953;
  const double _t2283 = _t101*_t443;
  const double _t2284 = _t1132*_t447;
  const double _t2285 = _t440*_t961;
  const double _t2286 = _t1135*_t437;
  const double _t2287 = _hc6[2]*_t400;
  const double _t2303 = _t2300*_t990;
  const double _t2305 = _t439*_t451;
  const double _t2306 = _t101*_t441;
  const double _t2307 = _t2306*_t31;
  const double _t2312 = _t235*_t383;
  const double _t2313 = _t1208*_t2285;
  const double _t2314 = (0.1e1 / 0.2e1)*_t811;
  const double _t2315 = (0.8e1 / 0.3e1)*_t1005;
  const double _t2368 = _t1183*_t1198*_t447;
  const double _t2369 = _t1203*_t445;
  const double _t2373 = _t1210*_t2372*_t31;
  const double _t2375 = (0.3e1 / 0.4e1)*_t954;
  const double _t2376 = _t1189*_t1190;
  const double _t2377 = _t1192*_t1194;
  const double _t2378 = _t35*_t374;
  const double _t2379 = _t1162*_t2378;
  const double _t2380 = _hc7[0]*_t1197;
  const double _t2381 = _hc7[0]*_t1203;
  const double _t2382 = _hc6[4]*_t1208*_t1209*_t2372*_t33;
  const double _t2383 = _t1099*_t953;
  const double _t2384 = (0.1e1 / 0.64e2)*_hc6[3]*_t440;
  const double _t2386 = _t2282*_t2385;
  const double _t2387 = (0.3e1 / 0.32e2)*_hc6[2]*_t450;
  const double _t2388 = (0.3e1 / 0.2e1)*_t127;
  const double _t2389 = _hc6[2]*_t2046*_t375;
  const double _t2404 = _t2401*_t442;
  const double _t2406 = _t2401*_t439;
  const double _t2407 = _hc6[1]*_t2406;
  const double _t2408 = _hc6[1]*_t1966*_t833;
  const double _t2409 = _t1210*_t2403;
  const double _t2410 = _t35*_t394;
  const double _t2411 = _t1162*_t2410;
  const double _t2412 = (0.3e1 / 0.4e1)*_t1005;
  const double _t2413 = _t400*_t449;
  const double _t2414 = _t2287*_t2385;
  const double _t2438 = _t1193*_t1930;
  const double _t2440 = _t1192*_t1930;
  const double _t2441 = (0.5e1 / 0.64e2)*_t1201*_t8;
  const double _t2442 = _t2440*_t8;
  const double d4F_dna4 = _t5*(my_piecewise3(_t37, 0, -_t1*_t1314*_t184 - _t1042*_t1313 + (0.6832e4 / 0.81e2)*_t1308*_t406 + (0.3640e4 / 0.81e2)*_t1309*_t175 + (0.896e3 / 0.27e2)*_t1310*_t513 + (0.256e3 / 0.81e2)*_t1311*_t1312 - _t1313*_t1319 - _t1314*_t519 - _t1316*_t1317 - _t1317*_t1321 + _t1318*(_t84 * _t84 * _t84 * _t84) + _t1320*_t525 + _t1320*_t538 + _t1322*_t536 + _t1323*_t525 + _t1323*_t538 - _t1324*_t1351 - _t1325*_t1326 - _t1325*_t1353 + 0.4e1*_t1328*_t530 - _t1329*_t1331 - _t1329*_t1336 - _t1329*_t227*_t863 + 0.6e1*_t1335*_t532 + _t1339*_t665 - _t1347*_t227 - _t1347*_t550 + _t1349*_t227 + _t1349*_t550 + 0.6e1*_t1350*_t227 + _t1352*_t550 + (0.32e2 / 0.3e1)*_t173*_t196 + _t182*(_t227 * _t227) + 0.4e1*_t185*_t571 + (0.64e2 / 0.3e1)*_t220*_t534 + (0.112e3 / 0.3e1)*_t224*_t534 + 0.2e1*_t272*_t597 + _t272*((0.16e2 / 0.27e2)*_hc0[1]*_hc0[2]*_t11*_t12*_t14*_t16*_t17*_t18*_t213*_t402*_t514*_t8*p->cam_omega + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[1]*_t1*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t65*_t74*_t8*p->cam_omega + (0.2e1 / 0.9e1)*_hc0[1]*_hc1[2]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t65*_t74*_t8*p->cam_omega + (0.4e1 / 0.9e1)*_hc1[1]*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t207*_t553*_t8*p->cam_omega + (0.1e1 / 0.9e1)*_hc1[1]*_t12*_t139*_t14*_t16*_t17*_t18*_t42*_t74*p->cam_omega + (0.4e1 / 0.27e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t69*_t74*_t8*p->cam_omega*gaa + (0.1e1 / 0.9e1)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t191*_t42*_t74*p->cam_omega + (0.4e1 / 0.27e2)*_t11*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t42*p->cam_omega*gaa + (0.28e2 / 0.27e2)*_t11*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t508*_t8*p->cam_omega*gaa + (0.4e1 / 0.27e2)*_t12*_t139*_t14*_t16*_t17*_t18*_t206*_t207*_t69*_t8*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t481*_t69*_t8*p->cam_omega - _t1234*_t592 - _t1354 - _t1355*_t221 - _t1356*_t82 - _t1357*_t582 - _t1358*_t79 - _t1359*_t547 - _t1360*_t139 - _t1360*_t481 - _t199*_t546 - _t210*_t546 - _t463*_t76 - _t547*_t587 - _t547*_t594 - _t548*_t595 - 0.56e2 / 0.27e2*_t576 - 0.140e3 / 0.81e2*_t579 - 0.14e2 / 0.27e2*_t580 - _t589*_t672) + _t38*(_t1244*_t70 - _t1286*_t555 + _t1290*_t565 + _t1332*_t678 + _t1361 + _t1362*_t1363 + _t1364*_t192 + _t1365*_t267 + _t1366*_t481 + _t1368*_t678 + _t1370*_t678 + _t1372*_t139 + _t1372*_t481 + 0.3e1*_t197*_t570 + 0.3e1*_t205*(_t1332*_t556 + _t1373*_t716 + _t43*(-_t1374 - 0.1e1 / 0.6e1*_t1375) + _t569) + 0.2e1*_t267*_t552 - _t44*(_hc3[4]*_t589 + _t1376 + _t1377*_t139 + _t1377*_t481 + _t1385*_t73 - _t44*(_hc3[8]*_t197 + _hc3[8]*_t205 + _t1378 + _t1381*_t73 - _t44*(_hc3[13]*_t73 + _t1379)) + _t484*_t562 + _t552*_t683 + _t558*(_t1375 + _t563) + _t559*_t564) + 0.3e1*_t552*_t680 + 0.3e1*_t557*_t589 + _t73*(_hc3[3]*_t589 + _t1373*_t558 - _t1385*_t44 + _t1386 + _t1387*_t139 + _t1387*_t481 + _t484*_t564 + _t552*_t556 + _t559*_t567 + _t73*(_hc3[6]*_t197 + _hc3[6]*_t205 - _t1384*_t44 + _t1388 + _t73*(_hc3[10]*_t73 + _t1389)))) + 0.4e1*_t539*_t597 + _t665*(_t1337*_t1342 - _t1340*_t79 + _t1341*_t716 + _t549) + _t665*(_t1227*_t1337 + _t1228*_t1337*_t198 + _t1228*_t210 - _t1228*_t217 - _t1340*_t9 + _t1343 + _t1344*_t221 + _t1345*_t225 + _t1346*_t82 - _t544*_t9) + _t94*((0.112e3 / 0.81e2)*_hc0[2]*_t575*_t593 + (0.910e3 / 0.243e3)*_t1*_t1309*_t577 + (0.280e3 / 0.243e3)*_t1064*_t1435 + (0.64e2 / 0.243e3)*_t1064*_t1441 - 0.56e2 / 0.81e2*_t1068*_t212*_t575 + _t1239*_t76 - _t1244*_t588 + _t1257*_t199 + _t1257*_t210 - _t1257*_t217 + _t1258*_t592 - _t1270*_t1434 - _t1270*_t1457 - _t1270*_t1458 - _t1310*_t1403*_t894 + _t1310*_t1413*_t586 + (0.224e3 / 0.81e2)*_t1310*_t582 + (0.64e2 / 0.243e3)*_t1312*_t1402 - _t1332*_t1460 + _t1332*_t1462 - _t1332*_t1463 + _t1341*_t589 + _t1342*_t1358 + _t1342*_t1448 + _t1358*_t201 + _t1359*_t1432 - _t1360*_t552 - _t1362*_t1419 + _t1364*_t278 - _t1364*_t693 + _t1365*_t279 - _t1365*_t596 - _t1368*_t1460 + _t1368*_t1462 - _t1368*_t1463 - _t1370*_t1460 + _t1370*_t1462 - _t1370*_t1463 + _t139*_t1456 + _t139*_t1464 + _t1390 - 0.854e3 / 0.243e3*_t1391*_t215 + (0.1708e4 / 0.243e3)*_t1391*_t573 - 0.56e2 / 0.81e2*_t1392*_t215 + (0.112e3 / 0.81e2)*_t1393 + (0.32e2 / 0.81e2)*_t1394 + _t1395*_t1397 + (0.56e2 / 0.81e2)*_t1398 + _t1399*_t82 + _t1400*_t1401 - _t1404*_t1405 - _t1405*_t1442 - 0.128e3 / 0.243e3*_t1406*_t1408 - 0.40e2 / 0.81e2*_t1406*_t1412 - 0.32e2 / 0.81e2*_t1406*_t1416 + (0.32e2 / 0.27e2)*_t1406*_t1418 + _t1414*_t581 - _t1421*_t1423 + _t1424*_t1425 + _t1424*_t1429 + _t1426*_t1427 - _t1426*_t1431 + _t1432*_t594 + (0.28e2 / 0.81e2)*_t1437*_t224 - _t1438*_t1439 - _t1438*_t1446 - _t1439*_t1440 - _t1440*_t1446 + _t1443*_t581 - _t1444*_t1453*_t210 + _t1445*_t541 + _t1445*_t544 - _t1447*_t541 - _t1447*_t544 + _t1449*_t1450*_t210 - _t1451*_t1452*_t198 + _t1454*_t1455*_t210 + _t1456*_t481 - _t1457*_t1465 - _t1458*_t1465 + _t1459*_t278 - _t1459*_t693 + _t1464*_t481 + _t218*_t552*_t673 - _t463*_t541 - _t463*_t544 + (0.112e3 / 0.243e3)*_t592*_t703)) + my_piecewise3(_t39, 0, _t108*(-_t1223*_t1245 + _t1235*_t1258 - _t1236*_t475 + _t1238 + _t1239*_t159 - _t1240*_t154 - _t1240*_t157 + _t1241*_t499 + _t1241*_t500 - _t1246*_t1247 + _t1246*_t1261 - _t1248*_t1249 + _t1248*_t166 - _t1251*_t1253 + _t1254*_t1256 + _t1254*_t1259 - _t1254*_t1263 + _t1257*_t465 + _t1264*_t140 + _t1264*_t482 + _t1268*_t1274 - _t1268*_t505 - _t1269*_t639 - _t1269*_t641 - _t1272*_t140 - _t1272*_t482 + _t1273*_t475 - _t1277*_t1278 + _t1277*_t1281 - _t1277*_t645 - _t1278*_t140 + _t1279*_t482 + _t1280*_t154 + _t1281*_t482 - _t140*_t645 - _t482*_t645) + _t1214*(_t60 * _t60 * _t60 * _t60) + _t1215*_t1216 + 0.6e1*_t1221*_t1222 + _t1224*_t605 + _t1229*_t168 + _t1229*_t467 + 0.6e1*_t1230*_t168 + _t1231*_t467 + _t131*(_t168 * _t168) + 0.2e1*_t243*_t506 + _t243*((0.4e1 / 0.9e1)*_hc5[1]*_hc5[2]*_t12*_t16*_t163*_t17*_t18*_t32*_t476*_t8*p->cam_omega + (0.1e1 / 0.9e1)*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.9e1)*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t32*_t42*_t56*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t140*_t16*_t162*_t163*_t17*_t18*_t32*_t49*_t8*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t32*_t482*_t49*_t8*p->cam_omega - _t1233 - _t1234*_t1235 - _t1236*_t140 - _t1236*_t482 - _t159*_t463 - _t462*_t499 - _t462*_t500 - _t465*_t546) + _t40*(_t1245*_t50 + _t1246*_t1284 + _t1248*_t147 + _t1268*_t240 + _t1277*_t620 + _t1283 + _t1285*_t482 - _t1286*_t1287 + _t1288*_t499 + _t1288*_t500 + _t1289*_t140 + _t1289*_t482 + _t1290*_t491 + _t1291*_t154 + _t1291*_t157 + _t140*_t620 + 0.2e1*_t240*_t475 - _t44*(_hc7[4]*_t499 + _hc7[4]*_t500 + _t1292 + _t1293*_t140 + _t1293*_t482 + _t1294*_t154 + _t1294*_t157 + _t1302*_t55 - _t44*(_hc7[8]*_t154 + _hc7[8]*_t157 + _t1295 + _t1298*_t55 - _t44*(_hc7[13]*_t55 + _t1296)) + _t484*_t488) + _t482*_t620 + _t55*(_hc7[3]*_t499 + _hc7[3]*_t500 - _t1302*_t44 + _t1303 + _t1304*_t140 + _t1304*_t482 + _t1305*_t154 + _t1305*_t157 + _t484*_t490 + _t55*(_hc7[6]*_t154 + _hc7[6]*_t157 - _t1301*_t44 + _t1306 + _t55*(_hc7[10]*_t55 + _t1307)))) + 0.4e1*_t460*_t506 + 0.4e1*_t496*_t608 + _t605*(-_t1225*_t79 + _t466) + _t605*(-_t1225*_t9 + _t1226 + _t1227*_t159 + _t1228*_t465 - _t9*_t923))) + 0.4e1*_t507 + 0.4e1*_t598;
  const double d4F_dna3_dnb = _t5*(my_piecewise3(_t37, 0, -_t1*_t263*_t512 - _t1107*_t1560 + _t1318*_t521*_t664 + _t1328*_t659 + _t1350*_t1586 + _t1352*_t283 - _t1560*_t1562 - _t1561*_t516 - _t1563*_t516 + _t1564*_t656 + _t1564*_t661 + _t1564*_t666 + _t1564*_t670 + _t1565*_t656 + _t1565*_t661 + _t1565*_t666 + _t1565*_t670 - _t1566*_t527 + 0.3e1*_t1567*_t1569 - _t1568*_t527 - _t1570*_t196 + _t1573*_t533 + _t1575*_t196 - _t1576*_t283 + _t1577*_t667 - _t1578*_t527 - _t1580*_t675 + _t1581*_t1588 - _t1582*_t527 + _t1583*_t675 + _t1584*_t1585 + _t1584*_t1587 + _t1589*_t550 + _t1590*_t550 - _t1591*_t526 - _t1592*_t708 + (0.16e2 / 0.3e1)*_t173*_t271 - _t271*_t535*_t85 + _t272*_t708 + _t272*((0.8e1 / 0.27e2)*_hc0[1]*_hc1[1]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t244*_t4*_t65*_t74*p->cam_omega + (0.4e1 / 0.27e2)*_hc0[1]*_hc1[2]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t65*_t69*_t74*_t8*_t89*p->cam_omega + (0.4e1 / 0.9e1)*_hc1[1]*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t191*_t207*_t658*_t8*p->cam_omega + (0.1e1 / 0.27e2)*_hc1[1]*_t12*_t139*_t14*_t16*_t17*_t18*_t42*_t74*p->cam_omega + (0.4e1 / 0.81e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t74*_t8*_t89*p->cam_omega*gaa + (0.4e1 / 0.27e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t4*_t632*_t74*p->cam_omega + (0.1e1 / 0.27e2)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t191*_t42*_t74*p->cam_omega + (0.4e1 / 0.81e2)*_t11*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t42*p->cam_omega*gaa + (0.4e1 / 0.27e2)*_t12*_t139*_t14*_t16*_t17*_t18*_t206*_t207*_t8*_t89*p->cam_omega + (0.16e2 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t244*_t4*_t69*p->cam_omega - _t1257*_t82 - _t1270*_t221 - _t1465*_t674 - _t1536*_t225 - _t1594 - _t1595 - _t1596 - _t1598 - _t1600 - _t1603 - _t1605 - _t1606*_t501 - _t1608 - _t199*_t648 - 0.8e1 / 0.81e2*_t701 - _t732) + _t286*_t597 + _t38*(_t1276*_t678 + _t1363*_t1624 + _t1366*_t138 + _t1371*_t1511 + _t138*_t192*_t481 + _t139*_t1623 + _t1493*_t70 + _t150*_t565 - _t1506*_t555 + _t1611*_t570 + _t1619*_t680 + _t1622*_t267 + _t1623*_t481 + _t1625*_t1626 + _t1627*_t1628 + _t1633*_t1634 + _t1633*_t692 + _t1635 + _t267*_t677 - _t269*_t469 + _t277*_t570 - _t44*(_t1376 + _t1377*_t480 + _t150*_t562 + _t150*_t684 + _t1611*_t564 + _t1616*_t73 + _t1629*_t694 + _t1630*_t692 + _t1631*_t205 + _t197*_t682 + _t277*_t564 - _t44*(_hc3[8]*_t1611 + _hc3[8]*_t277 + _t1614*_t73 + _t1632) + _t677*_t683) + _t552*_t679 + _t552*_t728 + _t558*(_t1571*_t1610 + _t1612*_t716 + _t1621 + _t688) + _t559*_t690 + _t589*_t681 + _t73*(_t1386 + _t1387*_t480 + _t150*_t564 + _t150*_t682 + _t1609*_t694 + _t1610*_t692 + _t1611*_t567 + _t1612*_t205 - _t1616*_t44 + _t197*_t687 + _t277*_t567 + _t556*_t677 + _t73*(_hc3[6]*_t1611 + _hc3[6]*_t277 + _t1617*_t73 + _t1618))) - _t512*_t652 + _t524*_t662 - _t535*_t84*_t933 + _t537*_t691 + _t540*_t708 + _t550*_t719 + _t571*_t669 + _t597*_t676 + _t665*(_t1227*_t82 + _t1228*_t1571*_t209 + _t1343 - _t1479*_t939 - _t1571*_t734*_t9 + _t1579*_t663 + _t1579*_t716 + _t198*_t663*_t672) + _t94*(_hc0[2]*_t1234*_t13*_t1661 + _hc1[2]*_t1634*_t1660 + _t1234*_t1454*_t674 + _t1257*_t221 - _t1270*_t515*_t894 - _t1341*_t198*_t277 - _t1344*_t1667*_t198 + _t1354*_t198 + _t1358*_t248 + _t139*_t1646 + (0.28e2 / 0.81e2)*_t1393 + _t1397*_t1659 + (0.28e2 / 0.81e2)*_t1398 + _t1401*_t1658 - _t1419*_t1624 + _t1429*_t1647 - _t1434*_t636 + (0.70e2 / 0.243e3)*_t1435*_t700 + _t1437*_t702 + (0.16e2 / 0.243e3)*_t1441*_t700 + _t1444*_t161*_t948 + _t1444*_t1636*_t244 - 0.8e1 / 0.81e2*_t1444*_t1666 + _t1449*_t1453*_t674 - _t1449*_t218*_t948 + _t1449*_t274*_t648 - _t1449*_t642*_t939 - _t1451*_t201 - _t1454*_t222*_t948 - _t1454*_t468*_t939 - _t1457*_t636 - _t1458*_t636 - _t1488*_t198*_t673 - _t1493*_t588 - _t1515*_t1636 + _t1516*_t274 + _t1517*_t592 + _t1521*_t696 - _t1535*_t673 + _t1536*_t1604 - _t1536*_t215*_t574 - _t155*_t541 - _t155*_t544 + _t1579*_t1597 + _t1579*_t1599 - _t158*_t198*_t541 - _t158*_t198*_t544 + _t1593*_t53 + _t1594*_t198 + _t1595*_t198 + _t1596*_t198 + _t1597*_t1660 + _t1598*_t198 + _t1600*_t198 + _t1603*_t198 + _t1605*_t198 + _t1607*_t198 + _t1622*_t279 - _t1622*_t596 - _t1634*_t1652 - _t1634*_t1655 - _t1636*_t198*_t632 + _t1637*_t589 - _t1638*_t1639 - _t1638*_t1642 - _t1640*_t198*_t218 - _t1640*_t201 - _t1643*_t1644 + _t1643*_t1649 - _t1644*_t1645 + _t1645*_t1649 + _t1646*_t481 + _t1647*_t1650 - _t1647*_t1651 + _t1648*_t552 - _t1652*_t692 - _t1653*_t1654 - _t1655*_t692 + _t1656*_t205 + _t1657*_t589*_t663 - _t1661*_t212*_t213*_t501 - _t1662*_t636 + (0.4e1 / 0.81e2)*_t1663*_t515 + _t1664*_t702 - 0.8e1 / 0.81e2*_t1665*_t515*_t893 + _t1669 + _t210*_t706 - _t217*_t706 + _t279*_t677 + _t497*_t76 - _t552*_t789 + _t587*_t648 + _t594*_t648 - _t596*_t677)) + my_piecewise3(_t39, 0, -_t100*_t1484 + _t107*_t1214*_t454 + _t108*(_t104*_t1550 - _t1223*_t1494 + _t1235*_t1517 + (0.28e2 / 0.243e3)*_t1235*_t769 - _t1247*_t1504 + _t1261*_t1504 - _t1263*_t1504*_t8 - _t1269*_t1547 - _t1271*_t140*_t1556 + _t1271*_t1535 - _t1271*_t1556*_t482 + _t1274*_t1502 + _t1274*_t618 - _t1346*_t1544 - _t140*_t1519 - _t140*_t1526 + _t140*_t1533 - _t140*_t1539 - _t140*_t1546 + _t140*_t1557 + _t1486*_t253 + _t1489*_t1537 + _t1490*_t1536 - _t1502*_t505 + _t1504*_t1538 + _t1513*_t631 + _t1514*_t499 + _t1514*_t500 + _t1515*_t763 + _t1516*_t249 - _t1519*_t482 - _t1521*_t1522 - _t1523*_t1555 - _t1523*_t201 - _t1525*_t201 - _t1526*_t482 + _t1528*_t641 + _t1529*_t1530 + _t1529*_t1531*_t482 + _t1532*_t639 + _t1532*_t641 + _t1533*_t482 + _t1534*_t475 - _t1539*_t482 - _t1540*_t1543 + _t1549*_t500 - _t155*_t922 - _t155*_t923 + _t1551*_t639*_t88 + _t1552*_t482 + _t1554*_t499 + _t1554*_t500 + _t1557*_t482 + _t1559 - _t158*_t253*_t922 - _t158*_t253*_t923 + _t159*_t497 + _t465*_t706 - _t475*_t844 - _t505*_t618) + _t1215*_t234 - _t1215*_t601 + _t1222*_t1470 + _t1230*_t1482 + _t1231*_t258 - _t1467*_t456 - _t1467*_t607 + _t1468*_t457 - _t1471*_t153 - _t1472*_t168 - _t1472*_t467 + _t1473*_t168 + _t1473*_t467 + _t1474*_t457 + 0.3e1*_t1476*_t168 + _t1478*_t168 + _t1478*_t467 + _t1481*_t457 + _t1483*_t467 - _t1485*_t601 + _t243*_t650 + _t243*((0.2e1 / 0.27e2)*_hc4[1]*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t27*_t31*_t32*_t56*_t8*_t98*p->cam_omega + (0.2e1 / 0.27e2)*_hc4[1]*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t27*_t31*_t32*_t56*_t8*_t98*p->cam_omega + (0.4e1 / 0.9e1)*_hc5[1]*_hc5[2]*_t12*_t146*_t16*_t163*_t17*_t18*_t32*_t8*_t88*p->cam_omega + (0.1e1 / 0.27e2)*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.27e2)*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t32*_t42*_t56*p->cam_omega + (0.4e1 / 0.9e1)*_hc5[2]*_t12*_t16*_t17*_t18*_t244*_t32*_t4*_t49*_t56*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t140*_t16*_t162*_t163*_t17*_t18*_t32*_t8*_t88*p->cam_omega - _t1234*_t1490 - _t1271*_t1488 - _t1486 - _t1487*_t639 - _t1487*_t641 - _t1492 - _t159*_t706 - _t462*_t631 - _t632*_t763 - 0.8e1 / 0.81e2*_t647 - _t771) + _t40*(-_t1276*_t620 + _t1284*_t1504 - _t1285*_t138 - _t1287*_t1506 - _t138*_t147*_t482 + _t140*_t1503 + _t140*_t1509 + _t1494*_t50 + _t150*_t491 + _t1501*_t154 + _t1501*_t157 + _t1502*_t240 + _t1503*_t482 + _t1505*_t639 + _t1505*_t641 + _t1509*_t482 - _t1510*_t1511 + _t1512 - _t237*_t469 + _t239*_t499 + _t239*_t500 + _t240*_t618 + _t256*_t495 - _t44*(_hc7[4]*_t631 + _t1292 - _t1293*_t480 + _t1498*_t55 + _t150*_t488 + _t150*_t623 + _t1507*_t639 + _t1507*_t641 + _t154*_t622 + _t157*_t622 + _t256*_t490 - _t44*(_hc7[8]*_t256 - _hc7[8]*_t621 + _t1496*_t55 + _t1508) - _t490*_t621) + _t475*_t619 + _t485*_t631 - _t495*_t621 + _t55*(_hc7[3]*_t631 + _t1303 - _t1304*_t480 - _t1498*_t44 + _t150*_t490 + _t150*_t622 + _t154*_t626 + _t157*_t626 + _t256*_t494 - _t494*_t621 + _t55*(_hc7[6]*_t256 - _hc7[6]*_t621 + _t1499*_t55 + _t1500) + _t627*_t639 + _t627*_t641)) + _t459*_t606 + _t461*_t650 + _t496*_t611 + _t506*_t610 + _t506*_t612 + _t605*(_t104*_t1227 + _t1226 + _t1228*_t616 + _t1479*_t760 - _t1480*_t256 + _t159*_t53 + _t249*_t53 + _t254*_t79) + 0.3e1*_t608*_t630)) + _t599 + 0.3e1*_t651 + 0.3e1*_t709;
  const double d4F_dna2_dnb2 = _t5*(my_piecewise3(_t37, 0, -_hc2[1]*_t1325*_t1785 + _t1318*_t181*_t285 - _t1324*_t271*_t930 - _t1325*_t1775*_t934 - _t1325*_t283*_t380 + 0.2e1*_t1327*_t660*_t664 + _t1335*_t713 + _t1339*_t718 + _t1350*_t297 + _t1352*_t297 + 0.2e1*_t1569*_t1773 + 0.4e1*_t1574*_t271 + _t1577*_t1788 + _t1585*_t1786 + _t1587*_t1786 + _t1588*_t675*_t720 + _t1590*_t675 + _t174*_t291 + _t1769*_t712 + _t1769*_t721 + _t1770*_t712 + _t1770*_t721 - _t1772*_t657 - _t1774*_t657 - _t1777*_t657 + _t1779*_t532 - _t1780*_t657 + _t1782*_t665 - _t1783*_t657 + _t1784*_t297 + _t1787*_t675 + _t1789*_t227 - _t1790*_t180 - _t1791*_t739 + _t186*_t731 + (0.32e2 / 0.9e1)*_t220*_t714 + (0.56e2 / 0.9e1)*_t224*_t714 + _t272*((0.2e1 / 0.27e2)*_hc0[1]*_hc1[1]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t288*_t65*_t74*_t8*p->cam_omega + (0.2e1 / 0.27e2)*_hc0[1]*_hc1[2]*_t1*_t12*_t13*_t14*_t16*_t17*_t18*_t289*_t65*_t74*_t8*p->cam_omega + (0.4e1 / 0.9e1)*_hc1[1]*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t207*_t289*_t529*_t8*p->cam_omega + (0.2e1 / 0.9e1)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t244*_t74*p->cam_omega + (0.1e1 / 0.27e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t288*_t42*_t74*p->cam_omega + (0.22e2 / 0.27e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t4*_t632*_t74*p->cam_omega + (0.1e1 / 0.27e2)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t289*_t42*_t74*p->cam_omega + (0.16e2 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t244*_t4*_t89*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t288*_t69*_t8*p->cam_omega - _t1234*_t1793 - _t1360*_t288 - _t1601*_t736 - _t1608 - _t1792 - _t274*_t706 - _t672*_t733 - _t707 - 0.8e1 / 0.81e2*_t738) + _t287*_t708 + _t38*(_hc1[3]*_t1628*_t681 - _t1267*_t267 + _t1332*_t1801 + _t1363*_t1802 + _t1366*_t288 - _t137*_t680 + _t1371*_t288 + _t150*_t729 + _t1511*_t1623 + _t1511*_t1806 + _t1619*_t679 + _t1625*_t480*_t89 + _t1626*_t1803 + _t1627*_t726 + _t1635 + _t1718*_t192 - _t1719*_t269 + _t1778*_t678 + _t1794 + _t1796*_t690 + _t1800*_t205 + _t197*_t725 - _t267*_t479 - _t44*(-_t137*_t683 + _t1377*_t288 + _t1629*_t726 + _t1796*_t682 + _t1798*_t73 + _t1804*_t480 + _t1805 - _t474*_t683 + _t682*_t727) - _t468*_t555 - _t474*_t680 + _t677*_t783 + _t690*_t727 + _t73*(-_t137*_t556 + _t1387*_t288 + _t1609*_t726 + _t1795*_t73 + _t1796*_t687 + _t1797*_t480 + _t1799 - _t474*_t556 + _t687*_t727)) + _t655*_t715 + _t671*_t739 + _t691*_t722 + _t708*_t723 + _t94*(_t1239*_t82 + _t1332*_t1828 + _t1338*_t1817 + _t1338*_t733*_t75 + _t1390 + (0.16e2 / 0.243e3)*_t1394 + (0.28e2 / 0.243e3)*_t1398 - _t1419*_t1802 + _t1425*_t1826 + _t1429*_t1826 - _t1430*_t20*_t205*_t289*_t8 - 0.8e1 / 0.243e3*_t1444*_t737 + (0.16e2 / 0.243e3)*_t1449*_t737 + (0.28e2 / 0.243e3)*_t1454*_t737 - _t1460*_t1778 + _t1462*_t1778 - _t1463*_t1778 + _t1517*_t1606 - _t1518*_t198*_t281 + (0.16e2 / 0.9e1)*_t1541*_t1820*_t208*_t73 + _t1550*_t274 + _t1550*_t76 + _t158*_t1593 + _t158*_t1817 + _t158*_t1819 + _t1599*_t1781 - _t1602*_t1641*_t1827 + _t1604*_t1762 - _t1640*_t648 + _t1650*_t1826 - _t1657*_t1823*_t198 + _t1658*_t198*_t674 - _t1662*_t1742 + (0.8e1 / 0.243e3)*_t1664*_t220 - _t1667*_t546 - _t1723*_t939 - _t1725*_t734 + _t1727*_t209 + _t1728*_t199 + _t1728*_t210 - _t1728*_t217 + _t1728*_t295 + _t1732*_t736 + _t1736*_t696 - _t1737*_t673 + _t1746*_t280 + _t1753*_t198*_t295 + _t1757*_t674 + _t1762*_t1793 - _t1767*_t1827*_t591 + _t1781*_t733 + (0.56e2 / 0.243e3)*_t1793*_t703 - _t1807*_t292 - _t1807*_t294 - 0.32e2 / 0.81e2*_t1809*_t198*_t244 - 0.16e2 / 0.81e2*_t1810 - _t1811*_t1812 + _t1811*_t1813 - _t1811*_t1814 - _t1812*_t1816 + _t1813*_t1816 - _t1814*_t1816 - _t1815*_t980 - _t1815*_t981 - _t1818*_t648 - _t1818*_t704 - _t1821*_t677 + _t1822*_t278 - _t1822*_t693 - _t1823*_t208*_t546 + _t1824*_t677 - _t1825*_t695 - _t1825*_t698 - 0.44e2 / 0.81e2*_t198*_t632*_t939 + _t198*_t642*_t736 - _t198*_t648*_t948 - _t281*_t633 - _t541*_t635 - _t544*_t635 - _t642*_t673 + _t697 - _t706*_t948)) + my_piecewise3(_t39, 0, _t1006*_t650 - _t102*_t1680*_t61 + _t108*(_t104*_t1239 + _t1238 - _t1247*_t1714 + _t1255*_t1766*_t641 + _t1261*_t1714 - _t1262*_t157*_t1766 + _t1271*_t1737 - _t1278*_t313 + _t1279*_t313 + _t1280*_t317 + _t1490*_t1762 + (0.56e2 / 0.243e3)*_t1490*_t769 + _t1517*_t1702 - _t1522*_t1736 - _t1522*_t253*_t4*_t642 - _t1525*_t648 - _t1525*_t770 + _t1530*_t1768 - _t1531*_t1725 + _t1538*_t1714 + _t154*_t1764 - _t1544*_t546 - _t1545*_t1760 + _t1547*_t1602*_t57 - _t1549*_t157*_t253 + _t1550*_t159 + _t1550*_t249 - 0.16e2 / 0.9e1*_t164*_t1733*_t244*_t55 + _t165*_t1727 + _t1658*_t1703 + _t1698*_t1762 + (0.8e1 / 0.81e2)*_t1700*_t632 + (0.28e2 / 0.243e3)*_t1701*_t646 + _t1723*_t760 + (0.16e2 / 0.243e3)*_t1726 - _t1728*_t325 + _t1728*_t332 + _t1728*_t465 + _t1728*_t759 + (0.28e2 / 0.243e3)*_t1729 - _t1730*_t317 - _t1730*_t318 + _t1731*_t1759 + _t1731*_t631 + _t1731*_t761 - _t1732*_t1734 + (0.16e2 / 0.81e2)*_t1735 + (0.8e1 / 0.243e3)*_t1738*_t1739 - _t1741*_t922 - _t1741*_t923 - _t1742*_t1745 - 0.8e1 / 0.243e3*_t1744*_t646 + _t1746*_t254 + _t1747*_t922 + _t1747*_t923 - _t1748*_t922 - _t1748*_t923 - _t1749*_t922 - _t1749*_t923 + _t1750*_t1751 + (0.16e2 / 0.243e3)*_t1752*_t646 + _t1753*_t253*_t465 + (0.32e2 / 0.81e2)*_t1754*_t253 + _t1755*_t639 + _t1755*_t641 - _t1756*_t618 + _t1757*_t616 + _t1758*_t618 - _t1760*_t504 - _t1761*_t546 - _t1763*_t639 - _t1765*_t648 + _t1767*_t257*_t503 + _t1768*_t57*_t641 - _t253*_t648*_t973 - _t255*_t57*_t614 - _t313*_t645 + _t634 - _t635*_t922 - _t635*_t923 + _t644 - _t706*_t973) + _t1214*_t130*_t309 + _t1216*_t1686 + _t1221*_t1681 + _t1222*_t1679 + _t1224*_t748 + _t1231*_t336 + _t133*_t1674 + _t133*_t1687 + _t1468*_t312 - _t1468*_t749 + _t1474*_t312 - _t1474*_t749 + 0.4e1*_t1476*_t258 + 0.2e1*_t1478*_t617 + _t1481*_t312 - _t1481*_t749 + _t1483*_t617 + _t153*_t303 + _t1671*_t456 + _t1671*_t607 + _t1672*_t456 + _t1672*_t607 - _t1673*_t456 - _t1673*_t607 - _t1677*_t606 - _t1677*_t751 + _t168*_t1684 - _t1682*_t603 + 0.4e1*_t1683*_t606 + _t1685*_t605 - _t1688*_t308 - _t1689*_t749 + _t1690*_t650 + _t243*((0.4e1 / 0.27e2)*_hc4[1]*_hc5[2]*_t12*_t16*_t17*_t18*_t27*_t31*_t32*_t49*_t56*_t8*_t88*_t98*p->cam_omega + (0.4e1 / 0.9e1)*_hc5[1]*_hc5[2]*_t12*_t16*_t163*_t17*_t18*_t314*_t32*_t49*_t8*p->cam_omega + (0.4e1 / 0.81e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t299*_t32*_t320*_t321*_t49*_t56*_t8*p->cam_omega*gbb + (0.1e1 / 0.27e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t313*_t32*_t42*_t56*p->cam_omega + (0.4e1 / 0.9e1)*_hc5[2]*_t12*_t16*_t17*_t18*_t244*_t32*_t4*_t56*_t88*p->cam_omega + (0.1e1 / 0.27e2)*_hc5[2]*_t12*_t16*_t17*_t18*_t314*_t32*_t42*_t56*p->cam_omega - _t104*_t1257 + (0.4e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t313*_t32*_t49*_t8*p->cam_omega + (0.4e1 / 0.81e2)*_t12*_t16*_t17*_t18*_t299*_t30*_t32*_t320*_t321*_t42*p->cam_omega*gbb - _t1270*_t328 - _t1453*_t1703 - _t1492 - _t1536*_t331 - _t1691 - _t1692 - _t1694 - _t1695 - _t1696 - _t1697 - _t1699 - _t1700*_t642 - _t1702*_t501 - 0.8e1 / 0.81e2*_t327*_t766 - _t332*_t648 - _t615 - _t638) + (0.32e2 / 0.9e1)*_t327*_t602 + (0.56e2 / 0.9e1)*_t330*_t602 + _t40*(_t1267*_t240 + _t1284*_t1714 + _t1285*_t313 + _t140*_t1713 - _t143*_t469 + _t145*_t1706 + _t145*_t1709 - _t145*_t480*_t843 + _t145*_t761 + _t147*_t1718 + _t150*_t756 + _t1501*_t256 - _t1503*_t1511 - _t1509*_t1511 + _t1510*_t313 + _t1512 + _t154*_t752 + _t157*_t752 + _t1704 - _t1707*_t629 + _t1715*_t618 + _t1716*_t639 + _t1716*_t641 - _t1719*_t237 + _t240*_t479 + _t313*_t620 - _t44*(_hc7[4]*_t1706 + _hc7[4]*_t1709 + _hc7[4]*_t761 + _t1293*_t313 - _t1707*_t622 + _t1711*_t55 + _t1720*_t256 - _t1721*_t480 + _t1722) + _t55*(_hc7[3]*_t1706 + _hc7[3]*_t1709 + _hc7[3]*_t761 + _t1304*_t313 + _t1705*_t55 - _t1707*_t626 + _t1708*_t256 - _t1710*_t480 + _t1712) + _t631*_t755) + _t458*_t815 + _t604*_t741 + 0.2e1*_t608*_t758 + 0.2e1*_t611*_t630 + _t772*_t911)) + 0.2e1*_t651 + 0.2e1*_t709 + 0.2e1*_t740 + 0.2e1*_t773;
  const double d4F_dna_dnb3 = _t5*(my_piecewise3(_t37, 0, _t1318*_t717*_t774 + 0.3e1*_t1327*_t1773*_t659 - _t1570*_t291 + _t1573*_t775 + _t1575*_t291 + _t1585*_t297 + _t1585*_t779 + _t1586*_t1789 + _t1586*_t1837 + _t1587*_t1833 + _t1589*_t297 + _t1589*_t779 - _t1771*_t1831*_t80 - _t1776*_t527*_t90 + 0.6e1*_t1785*_t1836 - _t1829*_t711 + _t1830*_t530 - _t1832*_t297 - _t1832*_t779 + _t1833*_t719 - _t1838*_t67 + _t185*_t786 + _t272*_t790 + _t38*(_hc1[1]*_t1276*_t725 + _t1266*_t70 + _t1276*_t1801 + _t1276*_t1846 + _t1363*_t1841 + _t1623*_t1844 + _t1794 + _t1806*_t288 + _t1806*_t785 + _t1840*_t73 - _t1842*_t679 - _t1842*_t728 + _t1843*_t277 + _t1845*_t733 + _t1847*_t1848 + _t1850 + _t267*_t781 - _t471*_t679 - _t471*_t728) + _t539*_t790 + 0.3e1*_t676*_t739 + 0.3e1*_t718*(_t1571*_t278 - _t1571*_t693 + _t1637*_t663 + _t1637*_t716 + _t1835*_t663 + _t282) + _t731*_t776 + _t739*_t777 - _t790*_t932 + _t94*(-_t1342*_t1856 - _t1419*_t1841 + _t1429*_t1860 + _t1479*_t735 + _t1516*_t76 + _t1517*_t788 + _t1536*_t1793 + _t1550*_t82 + _t1579*_t276*_t288 + _t1579*_t733 - _t1601*_t1808 + _t1602*_t209*_t288 + _t1637*_t787 - _t1639*_t1854 - _t1642*_t1854 + _t1650*_t1860 - _t1651*_t1860 - _t1654*_t1823 + _t1656*_t294 + _t1657*_t716*_t787 - _t1668*_t292 - _t1668*_t294 + _t1669 - _t1781*_t198*_t292 - _t1781*_t198*_t294 + _t1792*_t198 - _t1808*_t1865*_t288 - _t1808*_t1865*_t785 - 0.44e2 / 0.27e2*_t1810 - _t1818*_t201 + _t1834*_t1853 + _t1835*_t787 - _t1851*_t281 - _t1852*_t939 + _t1853*_t248 - _t1856*_t201 - _t1857*_t288 - _t1857*_t785 - _t1858*_t288*_t734 + _t1859*_t288 + _t1859*_t785 + _t1861*_t736 - _t1862*_t288 - _t1862*_t785 - _t1863*_t288 - _t1863*_t785 + _t1864*_t288 + _t1864*_t785 + _t1866*_t288 + _t1866*_t785 + _t274*_t497 + _t279*_t781 + _t295*_t706 - _t596*_t781 + (0.28e2 / 0.243e3)*_t703*_t788)) + my_piecewise3(_t39, 0, -_t1079*_t1867 + _t108*(_hc4[2]*_t1234*_t1902*_t31 + _t1233*_t253 + _t1234*_t1701*_t616 - _t1241*_t253*_t256 - _t1247*_t1885 + _t1257*_t328 + _t1261*_t1885 - _t1262*_t255*_t8*_t821 - _t1270*_t1901 - _t1273*_t253*_t313 + _t1274*_t780 - _t1344*_t1761*_t253 - _t1346*_t1761 + _t1453*_t1752*_t616 + _t1491*_t253 + _t1513*_t1759 + _t1513*_t761 + _t1514*_t838 + _t1514*_t839 + _t1516*_t159 + _t1517*_t1890 + _t1524*_t1601 - _t1527*_t843 + _t1528*_t1894 + _t1531*_t1858*_t313 + _t1536*_t1698 - _t1536*_t1896 + _t1537*_t314*_t503 + _t1538*_t1885 - _t1539*_t313 - _t1539*_t822 - _t1543*_t164*_t318 - _t1546*_t822 - _t1547*_t1763 + _t1548*_t55*_t838 + _t1552*_t313 + _t1552*_t822 - _t1558*_t317 - _t1558*_t318 + _t1559 + _t159*_t1906 - _t1601*_t1734*_t253 - _t1602*_t165*_t313 + _t161*_t1744*_t973 + _t1658*_t1897 + _t1659*_t1900 + _t1691*_t253 + _t1692*_t253 + _t1694*_t253 + _t1695*_t253 + _t1696*_t253 + _t1697*_t253 + _t1699*_t253 - _t1701*_t222*_t973 + _t1701*_t468*_t760 + (0.28e2 / 0.81e2)*_t1729 - _t1731*_t253*_t317 - _t1731*_t253*_t318 - _t1734*_t1861 + (0.44e2 / 0.27e2)*_t1735 + _t1739*_t31*_t648 - 0.8e1 / 0.81e2*_t1744*_t1911 - _t1744*_t764 - _t1745*_t636 - _t1752*_t218*_t973 + _t1752*_t642*_t760 - _t1765*_t201 + _t1851*_t246 + _t1852*_t760 - _t1892*_t201 - _t1893*_t313 - _t1893*_t822 + _t1895*_t313 + _t1895*_t822 + (0.28e2 / 0.81e2)*_t1898 - _t1902*_t1903*_t501 - _t1904*_t636 + (0.4e1 / 0.81e2)*_t1905*_t765 + _t1906*_t249 + (0.70e2 / 0.243e3)*_t1907*_t766 - 0.8e1 / 0.81e2*_t1910*_t765 + _t249*_t497 + _t253*_t615 - _t325*_t706 - _t505*_t780 + _t648*_t837 + _t648*_t841 + _t706*_t759 + (0.16e2 / 0.243e3)*_t766*_t831) + _t1214*_t60*_t805 + _t132*_t1875 - _t1467*_t745 - _t1467*_t815 + _t1470*_t1681 - _t1471*_t316 + _t1478*_t336 + _t1478*_t820 + _t1482*_t1684 + _t1482*_t1882 + _t1482*_t748 - _t1674*_t809 + _t1674*_t810 + _t1680*_t302 + 0.3e1*_t1683*_t815 + 0.6e1*_t1686*_t234 - 0.8e1*_t1686*_t600*_t99 - _t1687*_t809 + _t1687*_t810 - _t1867*_t1871 - _t1868*_t231 - _t1868*_t233 - _t1870*_t800 - _t1872*_t800 + _t1873*_t744 + _t1873*_t746 + _t1874*_t744 + _t1874*_t746 + _t1876*_t606 + _t1876*_t751 + _t1877*_t606 - _t1878*_t606 - _t1878*_t751 + _t1879*_t807 + _t1880*_t336 + _t1880*_t820 - _t1881*_t808 - _t1883*_t809 - _t235*_t242*_t812 + _t243*_t845 + _t40*(-_hc5[1]*_t1276*_t752 - _t1266*_t50 - _t1276*_t1713 - _t1276*_t1888 + _t1284*_t1885 + 0.3e1*_t1503*_t313 + _t1509*_t313 + _t1509*_t822 + _t1704 + _t1842*_t619 + _t1842*_t754 - _t1848*_t239*_t843 + _t1884*_t55 + _t1886*_t256 + _t1887*_t761 + _t1889 + _t240*_t780 + _t471*_t619 + _t471*_t754) + _t460*_t845 + 0.3e1*_t606*_t750 + _t608*_t823 + 0.3e1*_t612*_t772 + _t747*_t807 + _t758*_t814 + _t772*_t816)) + 0.3e1*_t740 + 0.3e1*_t773 + _t847;
  const double d4F_dnb4 = _t5*(my_piecewise3(_t37, 0, _t1318*(_t93 * _t93 * _t93 * _t93) + 0.6e1*_t1779*_t713 + _t1782*_t718 + 0.6e1*_t1789*_t297 + _t182*(_t297 * _t297) + _t1830*_t1831 + _t1837*_t779 + _t1914*_t297 + _t1914*_t779 + 0.4e1*_t286*_t790 + _t38*(_t1363*_t1918 + _t1778*_t1801 + 0.3e1*_t1800*_t294 + _t1801*_t1926 + _t1801*_t1927 + _t1840*_t91 + _t1843*_t292 + _t1844*_t1847 + _t1845*_t787 + _t1846*_t785 + 0.3e1*_t1847*_t785 + _t1850 + _t1916*_t70 + _t1917*_t192 + _t1922*_t679 + 0.2e1*_t679*_t781 + 0.3e1*_t728*_t781) + 0.4e1*_t669*_t786 + _t676*((0.4e1 / 0.9e1)*_hc1[1]*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t207*_t782*_t8*p->cam_omega + (0.1e1 / 0.9e1)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t288*_t42*_t74*p->cam_omega + (0.1e1 / 0.9e1)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t289*_t42*_t74*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t288*_t8*_t89*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t785*_t8*_t89*p->cam_omega - _t1234*_t788 - _t1354 - _t1821*_t288 - _t1821*_t785 - _t1853*_t79 - _t274*_t463 - _t295*_t546 - _t672*_t787) + _t718*(_t1341*_t663 - _t1912*_t79 + _t778) + _t718*(_t1227*_t663*_t75 + _t1228*_t295 + _t1343 - _t1912*_t9 - _t9*_t981) + _t723*_t790 + _t94*(_t1239*_t274 + _t1257*_t295 + _t1258*_t788 + _t1341*_t787 + _t1390 - _t1419*_t1918 - _t1423*_t1855 + _t1425*_t1919 + _t1429*_t1919 + _t1648*_t1922 + _t1650*_t1919 - _t1651*_t1919 + _t1778*_t1828 - _t1778*_t1925 - _t1778*_t1928 - _t1821*_t781 + _t1824*_t781 + _t1828*_t1926 + _t1828*_t1927 + _t1853*_t201 - _t1915*_t292 - _t1915*_t294 - _t1916*_t588 + _t1917*_t278 - _t1917*_t693 + _t1920*_t288 + _t1920*_t785 - _t1922*_t789 + _t1923*_t278 - _t1923*_t693 - _t1924*_t288 - _t1924*_t785 - _t1925*_t1926 - _t1925*_t1927 - _t1926*_t1928 - _t1927*_t1928)) + my_piecewise3(_t39, 0, (_t107 * _t107 * _t107 * _t107)*_t1214 + _t108*((0.112e3 / 0.81e2)*_hc4[2]*_t1143*_t824 - 0.128e3 / 0.243e3*_hc4[3]*_t1014*_t1963 - _t1015*_t1403*_t1931 - _t1019*_t1974 + _t1019*_t1975 - _t1019*_t1976 - _t1019*_t1977 - _t1020*_t1974 + _t1020*_t1975 - _t1020*_t1976 - _t1020*_t1977 + _t104*_t1399 + (0.280e3 / 0.243e3)*_t1143*_t1907 + (0.64e2 / 0.243e3)*_t1143*_t831 - _t1223*_t1954 + _t1238 + _t1239*_t249 - _t1240*_t317 - _t1240*_t318 + _t1241*_t838 + _t1241*_t839 - _t1247*_t1956 - _t1249*_t1955 - _t1249*_t1983 - _t1253*_t1891 + _t1256*_t1972 - _t1257*_t325 + _t1257*_t332 + _t1257*_t759 + _t1258*_t1890 + _t1261*_t1956 - _t1263*_t1972 - _t1270*_t1904 + _t1395*_t1900 + _t1400*_t1897 + _t1413*_t1931*_t836 + _t1432*_t1953 + _t1432*_t837 + _t1432*_t841 + _t1450*_t1752*_t759 - _t1450*_t1910*_t249 - _t1452*_t1892*_t253 - _t1453*_t1744*_t759 + _t1453*_t1905*_t249 + _t1455*_t1701*_t759 - _t1455*_t1903*_t249*_t824 - _t1524*_t1989*_t313 - _t1524*_t1989*_t822 + _t1534*_t1921 + _t1538*_t1956 + _t1555*_t1978 + _t1555*_t1979 + _t166*_t1955 + _t166*_t1983 + (0.32e2 / 0.81e2)*_t1726 + (0.56e2 / 0.81e2)*_t1729 - _t1756*_t780 + _t1758*_t780 - _t1763*_t1894 + _t1764*_t317 + (0.112e3 / 0.243e3)*_t1890*_t769 - 0.56e2 / 0.81e2*_t1896*_t42 + (0.112e3 / 0.81e2)*_t1898 - 0.32e2 / 0.81e2*_t1901*_t42 - _t1921*_t844 + (0.224e3 / 0.81e2)*_t1931*_t1961 + (0.64e2 / 0.243e3)*_t1933*_t1962 - _t1957*_t1982 + _t1957*_t1984 - _t1957*_t1985 - 0.854e3 / 0.243e3*_t1959*_t323 + (0.1708e4 / 0.243e3)*_t1959*_t825 + (0.910e3 / 0.243e3)*_t1960*_t27 - 0.40e2 / 0.81e2*_t1963*_t1967 - 0.32e2 / 0.81e2*_t1963*_t1969 + (0.32e2 / 0.27e2)*_t1963*_t1971 + (0.28e2 / 0.81e2)*_t1973*_t330 + _t1980*_t313 + _t1980*_t822 - _t1981*_t313 - _t1981*_t822 - _t1982*_t822 + _t1984*_t822 - _t1985*_t313 - _t1985*_t822 + _t1986*_t1987 + _t1987*_t1988) - _t1131*_t1934 + _t131*(_t336 * _t336) - _t1675*_t1951 + 0.6e1*_t1679*_t1681 + 0.6e1*_t1684*_t336 + _t1685*_t748 + _t1690*_t845 - _t1875*_t1943 + _t1875*_t1944 + _t1882*_t820 + (0.6832e4 / 0.81e2)*_t1929*_t433 + (0.3640e4 / 0.81e2)*_t1930*_t304 + (0.896e3 / 0.27e2)*_t1931*_t797 + (0.256e3 / 0.81e2)*_t1932*_t1933 - _t1934*_t1938 - _t1935*_t27*_t311 - _t1935*_t803 - _t1936*_t1937 - _t1937*_t1940 + _t1939*_t745 + _t1939*_t815 + _t1941*_t813 + _t1942*_t745 + _t1942*_t815 - _t1943*_t1952 - _t1945*_t1947 - _t1946*_t745 - _t1946*_t815 - _t1949*_t336 - _t1949*_t820 + _t1950*_t336 + _t1950*_t820 + (0.32e2 / 0.3e1)*_t302*_t316 + (0.64e2 / 0.3e1)*_t327*_t811 + (0.112e3 / 0.3e1)*_t330*_t811 + _t40*(_t105*_t1884 + _t1284*_t1956 + _t147*_t1955 + _t1713*_t1957 + _t1713*_t313 + _t1713*_t822 + _t1715*_t780 + _t1886*_t317 + _t1886*_t318 + _t1887*_t838 + _t1887*_t839 + _t1888*_t822 + _t1889 + _t1921*_t619 + _t1954*_t50 + _t1958*_t313 + _t1958*_t822) + 0.4e1*_t610*_t845 + 0.4e1*_t611*_t823 + _t612*((0.16e2 / 0.27e2)*_hc4[1]*_hc4[2]*_t12*_t16*_t17*_t18*_t30*_t32*_t321*_t429*_t798*_t8*p->cam_omega + (0.2e1 / 0.9e1)*_hc4[1]*_hc5[1]*_t12*_t16*_t17*_t18*_t27*_t31*_t313*_t32*_t56*_t8*_t98*p->cam_omega + (0.2e1 / 0.9e1)*_hc4[1]*_hc5[2]*_t12*_t16*_t17*_t18*_t27*_t31*_t314*_t32*_t56*_t8*_t98*p->cam_omega + (0.4e1 / 0.9e1)*_hc5[1]*_hc5[2]*_t12*_t16*_t163*_t17*_t18*_t32*_t8*_t821*p->cam_omega + (0.4e1 / 0.27e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t299*_t32*_t320*_t321*_t56*_t8*_t88*p->cam_omega*gbb + (0.1e1 / 0.9e1)*_hc5[1]*_t12*_t16*_t17*_t18*_t313*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.9e1)*_hc5[2]*_t12*_t16*_t17*_t18*_t314*_t32*_t42*_t56*p->cam_omega - _t104*_t1356 + (0.4e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t313*_t32*_t8*_t88*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t32*_t8*_t822*_t88*p->cam_omega + (0.4e1 / 0.27e2)*_t12*_t16*_t17*_t18*_t299*_t30*_t32*_t320*_t321*_t42*p->cam_omega*gbb + (0.28e2 / 0.27e2)*_t12*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t792*_t8*p->cam_omega*gbb - _t1233 - _t1234*_t1890 - _t1355*_t328 - _t1756*_t313 - _t1756*_t822 - _t1953*_t547 - _t249*_t463 - _t332*_t546 - _t462*_t838 - _t462*_t839 - _t546*_t759 - _t547*_t837 - _t547*_t841 - _t548*_t842 - 0.14e2 / 0.27e2*_t762 - 0.56e2 / 0.27e2*_t827 - 0.140e3 / 0.81e2*_t830 - 0.32e2 / 0.81e2*_t832) + _t748*(-_t1948*_t79 + _t819) + _t748*(_t104*_t1346 + _t1226 + _t1227*_t249 - _t1228*_t325 + _t1228*_t332 + _t1228*_t759 + _t1344*_t328 + _t1345*_t331 - _t1480*_t318 - _t1948*_t9))) + 0.4e1*_t791 + 0.4e1*_t846;
  const double d4F_dna3_dgaa = _t5*my_piecewise3(_t37, 0, -0.35e2 / 0.81e2*_t116*_t1992*_t212*_t81 - _t116*_t1993*_t1994 - 0.32e2 / 0.27e2*_t1311*_t1991 + _t1316*_t1997 + _t1321*_t1997 + _t1326*_t867 + _t1330*_t2017 + _t1331*_t2012 + _t1336*_t2012 + 0.3e1*_t1350*_t365 + _t1351*_t347 + _t1352*_t365 + _t1353*_t867 + _t1564*_t877 + _t1565*_t877 - _t1576*_t365 - _t1580*_t882 + _t1583*_t882 - _t1592*_t907 + _t179*_t1996 + _t184*_t1996 - _t1995*_t548*_t861 + _t1999*_t863 + _t1999*_t868 + _t2001*_t2002 + _t2002*_t2011 - _t2003*_t525 - _t2003*_t538 - _t2004*_t525 - _t2004*_t538 + _t2006*_t521 - _t2007*_t359 - _t2007*_t362 - _t2009*_t2010 - _t2009*_t2019 - _t2009*_t883 - _t2013*_t341 - _t2013*_t343 + _t2015*_t2020*_t351 + _t2016*_t227*_t872 - 0.1e1 / 0.3e1*_t2018*_t344*_t425 + _t2024*_t227 + _t2024*_t550 + _t2025*_t227 + _t2025*_t550 + _t2026*_t550 + (0.3e1 / 0.2e1)*_t227*_t349 + _t272*_t907 + _t272*(-_t1228*_t895 + _t1396*_t222*_t891 - _t158*_t904 + _t161*_t900 + _t161*_t902 + _t201*_t360 + _t201*_t363 + _t2027*_t888 + _t2029 + _t2030*_t218 - _t2031*_t541 - _t2031*_t544 + _t210*_t252*_t354 - _t216*_t887 - _t252*_t898 + _t273*_t354 + _t79*_t889) - 0.476e3 / 0.27e2*_t509 - 0.140e3 / 0.27e2*_t511*_t849 - 0.88e2 / 0.9e1*_t514*_t851 + 0.10e2*_t517 + 0.10e2*_t523 + _t540*_t907 + _t571*_t876 + _t597*_t937 + _t665*((0.1e1 / 0.12e2)*_t11*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t340*_t8*p->cam_omega - _t1337*_t2023 - _t2022 - _t22*_t899 - _t22*_t901) + _t94*((0.1e1 / 0.9e1)*_hc0[1]*_hc0[2]*_hc1[1]*_t1*_t12*_t14*_t16*_t17*_t18*_t213*_t69*_t74*_t8*_t852*p->cam_omega + (0.1e1 / 0.9e1)*_hc0[1]*_hc0[2]*_t1*_t11*_t12*_t14*_t16*_t17*_t18*_t213*_t42*_t852*p->cam_omega + (0.11e2 / 0.9e1)*_hc0[1]*_hc0[2]*_t1*_t11*_t12*_t14*_t16*_t17*_t18*_t213*_t514*_t8*p->cam_omega + (0.16e2 / 0.81e2)*_hc0[1]*_hc0[3]*_t11*_t12*_t14*_t16*_t17*_t18*_t1990*_t213*_t8*p->cam_omega*gaa + (0.1e1 / 0.18e2)*_hc0[1]*_hc1[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t207*_t553*_t8*p->cam_omega + (0.1e1 / 0.72e2)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t2*_t42*_t74*p->cam_omega + (0.1e1 / 0.18e2)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t65*_t74*_t8*p->cam_omega + (0.1e1 / 0.72e2)*_hc0[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t2*_t42*_t74*p->cam_omega + (0.1e1 / 0.18e2)*_hc0[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t65*_t74*_t8*p->cam_omega - _hc0[1]*_t1064*_t892 + (0.1e1 / 0.54e2)*_hc0[1]*_t112*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t2*_t206*_t207*_t69*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t206*_t207*_t481*_t69*_t8*p->cam_omega + (0.1e1 / 0.18e2)*_hc0[2]*_hc1[1]*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t340*_t74*_t8*p->cam_omega + (0.1e1 / 0.18e2)*_hc0[2]*_hc1[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t340*_t74*_t8*p->cam_omega - _hc0[3]*_t593*_t859 + (0.5e1 / 0.36e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t69*_t74*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t340*_t42*_t69*_t74*p->cam_omega + (0.5e1 / 0.27e2)*_t11*_t12*_t14*_t1409*_t1410*_t16*_t17*_t18*_t1990*_t8*p->cam_omega*gaa + (0.4e1 / 0.27e2)*_t11*_t12*_t14*_t1415*_t16*_t17*_t18*_t1990*_t213*_t8*p->cam_omega*gaa + (0.1e1 / 0.27e2)*_t11*_t12*_t14*_t148*_t16*_t17*_t18*_t212*_t213*_t340*p->cam_omega + (0.5e1 / 0.36e2)*_t11*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t42*p->cam_omega + (0.119e3 / 0.162e3)*_t11*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t508*_t8*p->cam_omega - 0.35e2 / 0.81e2*_t112*_t511*_t577 + (0.1e1 / 0.27e2)*_t12*_t14*_t16*_t17*_t18*_t191*_t206*_t207*_t212*_t213*_t340*_t8*p->cam_omega - _t1344*_t1418*_t1991 - _t1358*_t355 - _t139*_t2043 - _t1402*_t1993 - _t1448*_t355 - 0.119e3 / 0.81e2*_t1992*_t573 - _t1995*_t2036*_t586 - 0.22e2 / 0.27e2*_t1995*_t582 - _t200*_t899 - _t200*_t901 - _t201*_t2030 - 0.5e1 / 0.18e2*_t2032 - _t2033*_t892 - _t2035 - _t2037*_t77 - _t2037*_t78 - _t2038*_t76*_t887 - _t2039*_t541 - _t2039*_t544 - _t204*_t899 - _t204*_t901 - _t2040*_t210 - _t2042*_t592 - _t2043*_t481 - _t211*_t899 - _t211*_t901 - _t881*_t884)) + 0.3e1*_t908;
  const double d4F_dna3_dgbb = _t5*my_piecewise3(_t39, 0, _t108*((0.1e1 / 0.18e2)*_hc4[1]*_hc5[1]*_hc5[2]*_t12*_t122*_t16*_t163*_t17*_t18*_t28*_t31*_t32*_t476*_t8*p->cam_omega + (0.1e1 / 0.72e2)*_hc4[1]*_hc5[1]*_t12*_t122*_t140*_t16*_t17*_t18*_t28*_t31*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.72e2)*_hc4[1]*_hc5[2]*_t12*_t122*_t146*_t16*_t17*_t18*_t28*_t31*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[1]*_t12*_t122*_t140*_t16*_t162*_t163*_t17*_t18*_t28*_t31*_t32*_t49*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[1]*_t12*_t122*_t16*_t162*_t163*_t17*_t18*_t28*_t31*_t32*_t482*_t49*_t8*p->cam_omega - _t1235*_t2061 - _t140*_t2062 - _t2058*_t248 - _t2059 - _t2060*_t499 - _t2060*_t500 - _t2062*_t482 - _t884*_t916) + _t1215*_t909 + 0.3e1*_t1230*_t373 + _t1231*_t373 + _t1484*_t367 + _t1485*_t909 + _t153*_t2045*_t61 + _t168*_t2053 + _t168*_t2055 + (0.3e1 / 0.2e1)*_t168*_t368 + _t2044*_t454 + _t2045*_t456*_t51 + _t2046*_t2051*_t374 + _t2047*_t2048 + _t2047*_t2052 + _t2050*_t457 + _t2053*_t467 + _t2054*_t467 + _t2055*_t467 + _t243*_t925 + _t243*(_t2056 - _t2057*_t922 - _t2057*_t923 + _t2058*_t252 + _t251*_t371) + _t461*_t925 + _t496*_t918 + _t506*_t919 + _t605*(-_t118*_t916 - _t2049)) + 0.3e1*_t926;
  const double d4F_dna2_dnb_dgaa = _t2063 + _t5*my_piecewise3(_t37, 0, -_hc2[1]*_t2077*_t657 + _hc2[2]*_t1577*_t870 + _t1350*_t379 + _t1352*_t379 + _t1561*_t2065 + _t1563*_t2065 + _t1566*_t867 + _t1567*_t2006 + _t1568*_t867 + _t1578*_t867 + _t1581*_t871 + _t1582*_t867 + 0.2e1*_t1585*_t365 + _t1589*_t882 + _t1591*_t347 + _t1769*_t2068 + _t1770*_t2068 + _t1784*_t379 - _t1791*_t949 + _t196*_t261*_t867 + _t2020*_t870*_t93 + _t2024*_t675 + _t2025*_t675 + _t2026*_t675 + _t2064*_t260 + _t2064*_t263 + _t2066*_t380 + _t2066*_t928 + _t2067*_t859 + _t2069*_t859 - _t2070*_t656 - _t2070*_t661 - _t2070*_t666 - _t2070*_t670 - _t2071*_t863 - _t2071*_t868 + _t2072*_t660 - _t2073*_t865 - _t2074*_t865 - _t2076*_t865 + _t2078*_t2079 + _t2080*_t85 + _t2081*_t2082 + _t2083*_t365 - _t2084*_t283 - _t2085*_t283 + _t2086*_t283 + _t2089*_t708 - 0.4e1 / 0.3e1*_t271*_t343 - _t271*_t857 + _t272*(_t2029 - _t2031*_t948 + _t2087*_t252 + _t2088*_t674 + _t252*_t942 - _t896*_t945 + _t906 - 0.1e1 / 0.18e2*_t941 + _t979) + _t283*_t349 + _t286*_t907 + _t351*_t933 - _t365*_t380*_t657 + (0.10e2 / 0.3e1)*_t653 - _t656*_t866 - _t661*_t866 + _t665*(-_t2075*_t663 - _t358) - _t666*_t866 + _t671*_t949 + _t676*_t907 + _t691*_t876 + _t708*_t937 + _t719*_t882 + _t848*_t90 - _t865*_t933 + _t94*((0.1e1 / 0.27e2)*_hc0[1]*_hc0[2]*_hc1[1]*_t1*_t12*_t14*_t16*_t17*_t18*_t213*_t74*_t8*_t852*_t89*p->cam_omega + (0.1e1 / 0.27e2)*_hc0[1]*_hc0[2]*_t1*_t11*_t12*_t14*_t16*_t17*_t18*_t213*_t42*_t852*p->cam_omega + (0.1e1 / 0.18e2)*_hc0[1]*_hc1[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t2*_t207*_t658*_t8*p->cam_omega + (0.1e1 / 0.216e3)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t2*_t42*_t74*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t4*_t632*_t74*p->cam_omega + (0.2e1 / 0.27e2)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t244*_t4*_t65*_t74*p->cam_omega + (0.1e1 / 0.216e3)*_hc0[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t2*_t42*_t74*p->cam_omega + (0.1e1 / 0.27e2)*_hc0[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t65*_t69*_t74*_t8*_t89*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[1]*_t112*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t2*_t206*_t207*_t8*_t89*p->cam_omega + (0.2e1 / 0.27e2)*_hc0[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t206*_t207*_t244*_t4*_t69*p->cam_omega - _hc0[1]*_t2090*_t700 + (0.2e1 / 0.27e2)*_hc0[2]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t244*_t340*_t4*_t74*p->cam_omega + (0.1e1 / 0.27e2)*_hc0[2]*_hc1[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t340*_t69*_t74*_t8*_t89*p->cam_omega - 0.2e1 / 0.81e2*_hc0[3]*_t700*_t858 + (0.5e1 / 0.108e3)*_hc1[1]*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t74*_t8*_t89*p->cam_omega + (0.1e1 / 0.162e3)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t340*_t42*_t69*_t74*p->cam_omega + (0.2e1 / 0.81e2)*_t11*_t12*_t14*_t148*_t16*_t17*_t18*_t212*_t213*_t340*p->cam_omega + (0.5e1 / 0.108e3)*_t11*_t12*_t14*_t16*_t17*_t170*_t18*_t212*_t213*_t42*p->cam_omega + (0.2e1 / 0.81e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t212*_t213*_t340*_t69*_t8*_t89*p->cam_omega - 0.1e1 / 0.18e2*_t1541*_t354*_t696 - _t1593*_t355 - _t1604*_t2042 - _t1641*_t355*_t694 - _t1819*_t355 - _t2030*_t636 - 0.5e1 / 0.54e2*_t2032 - _t2033*_t2090 - _t2037*_t946 - 0.5e1 / 0.54e2*_t2038*_t699 - _t2091*_t900 - _t2091*_t902 - _t2092*_t881 - _t2093*_t947 - _t2095*_t210 - _t2096*_t899 - _t2096*_t901 - _t2097 - _t248*_t889 - _t360*_t637 - _t363*_t637 - _t896*_t897*_t948 - 0.1e1 / 0.27e2*_t897*_t940)) + _t908;
  const double d4F_dna2_dnb_dgbb = _t2098 + _t5*my_piecewise3(_t39, 0, -_t1002*_t602 + _t107*_t130*_t2044 + _t108*((0.1e1 / 0.18e2)*_hc4[1]*_hc5[1]*_hc5[2]*_t12*_t122*_t146*_t16*_t163*_t17*_t18*_t28*_t31*_t32*_t8*_t88*p->cam_omega + (0.1e1 / 0.216e3)*_hc4[1]*_hc5[1]*_t12*_t122*_t140*_t16*_t17*_t18*_t28*_t31*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[1]*_hc5[1]*_t12*_t122*_t140*_t16*_t17*_t18*_t31*_t32*_t56*_t8*_t98*p->cam_omega + (0.1e1 / 0.216e3)*_hc4[1]*_hc5[2]*_t12*_t122*_t146*_t16*_t17*_t18*_t28*_t31*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[1]*_hc5[2]*_t12*_t122*_t146*_t16*_t17*_t18*_t31*_t32*_t56*_t8*_t98*p->cam_omega + (0.1e1 / 0.18e2)*_hc4[1]*_hc5[2]*_t12*_t122*_t16*_t17*_t18*_t244*_t28*_t31*_t32*_t4*_t49*_t56*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[1]*_t12*_t122*_t140*_t16*_t162*_t163*_t17*_t18*_t28*_t31*_t32*_t8*_t88*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[2]*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t31*_t32*_t384*_t56*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[2]*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t31*_t32*_t384*_t56*_t8*p->cam_omega + (0.1e1 / 0.81e2)*_t12*_t146*_t16*_t162*_t163*_t17*_t18*_t32*_t320*_t321*_t384*_t8*p->cam_omega + (0.1e1 / 0.81e2)*_t12*_t148*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t384*p->cam_omega - _t1490*_t2061 - _t1530*_t372*_t88 - _t1751*_t372 - _t1754*_t2121 - _t2060*_t641*_t88 - _t2092*_t916 - _t2093*_t968 - _t2116*_t922 - _t2116*_t923 - _t2117*_t966 - _t2117*_t971 - 0.1e1 / 0.54e2*_t2118 - _t2120*_t465 - _t2122 - _t396*_t635 - _t399*_t635) + _t1230*_t400 + _t1231*_t400 + _t133*_t2107 + _t133*_t2112 + _t1468*_t909 + _t1473*_t917 + _t1474*_t909 + _t1478*_t917 + _t1481*_t909 - 0.2e1 / 0.3e1*_t153*_t387 - _t153*_t391 - _t153*_t951 + _t168*_t2113 + _t1682*_t958 + _t1688*_t367 + _t1689*_t909 - _t2048*_t957 + _t2048*_t959 - _t2050*_t601 + _t2051*_t960 - _t2052*_t957 + _t2052*_t959 + _t2054*_t617 + _t2055*_t617 - _t2099*_t456 - _t2099*_t607 - _t2100*_t456 - _t2100*_t607 - _t2101*_t602 + _t2102*_t456 + _t2102*_t607 - _t2103*_t2104 - _t2105*_t2106 + _t2108*_t61 + _t2109*_t373 + _t2110*_t374 - _t2111*_t925 + _t2114*_t914 + _t243*(-_t1017*_t159 + _t1022 + _t2056 - _t2057*_t973 + (0.1e1 / 0.18e2)*_t2115*_t371 + _t252*_t371*_t616 + _t252*_t967 + _t252*_t972 + _t921) + _t258*_t368 + _t400*_t605 + _t606*_t912 + _t610*_t925 + _t612*_t925 + _t630*_t918 + _t650*_t919 + _t911*_t974 + _t914*_t962) + _t926;
  const double d4F_dna_dnb2_dgaa = _t2063 + _t5*my_piecewise3(_t37, 0, _hc2[2]*_t1785*_t976 + _hc2[2]*_t291*_t935 + _hc2[3]*_t874*_t90*_t936 + _t1585*_t978 + _t1589*_t978 + _t1590*_t2129 - _t1771*_t2123 - _t1771*_t929 + _t1772*_t867 + _t1773*_t2006 + _t1774*_t867 - _t1776*_t2123 - _t1776*_t929 + _t1777*_t867 + _t1780*_t867 + _t1783*_t867 + _t1785*_t348 + _t1787*_t379 + _t1788*_t2077 + _t1789*_t365 + _t1790*_t347 - _t1832*_t978 + _t1837*_t365 + _t2025*_t297 - _t2070*_t714 - _t2071*_t928 + _t2072*_t285*_t530 + _t2080*_t261 + _t2082*_t2127 + _t2083*_t379 + _t2089*_t739 - _t2124*_t346 - _t2125*_t346 - _t2126*_t346 + _t2128*_t872 + _t2131*_t283 + _t272*_t982 + _t283*_t381 + _t287*_t949 - 0.2e1 / 0.3e1*_t291*_t343 - _t291*_t927 + _t539*_t982 - _t714*_t866 + _t718*(-_t1337*_t355 - _t364) + _t723*_t949 + _t731*_t876 + _t739*_t937 - _t865*_t977 - _t932*_t982 + _t934*_t936 + _t94*((0.1e1 / 0.18e2)*_hc0[1]*_hc1[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t207*_t289*_t529*_t8*p->cam_omega + (0.1e1 / 0.36e2)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t244*_t74*p->cam_omega + (0.1e1 / 0.216e3)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t288*_t42*_t74*p->cam_omega + (0.11e2 / 0.108e3)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t4*_t632*_t74*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t288*_t65*_t74*_t8*p->cam_omega + (0.1e1 / 0.216e3)*_hc0[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t289*_t42*_t74*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t289*_t65*_t74*_t8*p->cam_omega + (0.2e1 / 0.27e2)*_hc0[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t206*_t207*_t244*_t4*_t89*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t206*_t207*_t288*_t69*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[2]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t288*_t340*_t74*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[2]*_hc1[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t289*_t340*_t74*_t8*p->cam_omega + (0.1e1 / 0.81e2)*_t11*_t12*_t14*_t148*_t16*_t17*_t18*_t212*_t213*_t340*p->cam_omega + (0.1e1 / 0.81e2)*_t12*_t14*_t16*_t17*_t18*_t206*_t207*_t212*_t213*_t289*_t340*_t8*p->cam_omega - _t1793*_t2042 - _t1817*_t355 - _t2075*_t733 - _t2092*_t947 - _t2093*_t881 - _t2095*_t295 - _t2097 - _t2132*_t980 - _t2132*_t981 - _t2133*_t899 - _t2133*_t901 - 0.1e1 / 0.18e2*_t244*_t354*_t736 - _t360*_t635 - _t363*_t635)) + _t983;
  const double d4F_dna_dnb2_dgbb = _t1024 + _t2098 + _t5*my_piecewise3(_t39, 0, -_t1001*_t242 - _t1002*_t744 - _t1002*_t746 - _t1003*_t2114 - _t1003*_t962 + _t1004*_t2114 + _t1004*_t962 - _t1005*_t2104 + _t1006*_t974 + _t1007*_t1478 + _t1007*_t1880 - _t101*_t2106*_t374 + _t1023*_t243 + _t1023*_t460 + _t108*((0.1e1 / 0.27e2)*_hc4[1]*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t27*_t32*_t321*_t49*_t56*_t8*_t988*p->cam_omega + (0.1e1 / 0.27e2)*_hc4[1]*_hc4[2]*_t12*_t16*_t17*_t18*_t27*_t30*_t32*_t321*_t42*_t988*p->cam_omega + (0.1e1 / 0.18e2)*_hc4[1]*_hc5[1]*_hc5[2]*_t12*_t122*_t16*_t163*_t17*_t18*_t28*_t31*_t314*_t32*_t49*_t8*p->cam_omega + (0.1e1 / 0.216e3)*_hc4[1]*_hc5[1]*_t12*_t122*_t16*_t17*_t18*_t28*_t31*_t313*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.18e2)*_hc4[1]*_hc5[2]*_t12*_t122*_t16*_t17*_t18*_t244*_t28*_t31*_t32*_t4*_t56*_t88*p->cam_omega + (0.1e1 / 0.216e3)*_hc4[1]*_hc5[2]*_t12*_t122*_t16*_t17*_t18*_t28*_t31*_t314*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.27e2)*_hc4[1]*_hc5[2]*_t12*_t122*_t16*_t17*_t18*_t31*_t32*_t49*_t56*_t8*_t88*_t98*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[1]*_t12*_t122*_t16*_t162*_t163*_t17*_t18*_t28*_t31*_t313*_t32*_t49*_t8*p->cam_omega - _hc4[1]*_t2156*_t766 + (0.1e1 / 0.27e2)*_hc4[2]*_hc5[2]*_t12*_t16*_t17*_t18*_t31*_t32*_t384*_t49*_t56*_t8*_t88*p->cam_omega - 0.2e1 / 0.81e2*_hc4[3]*_t766*_t997 + (0.1e1 / 0.27e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t244*_t32*_t320*_t321*_t384*_t4*_t56*p->cam_omega + (0.5e1 / 0.108e3)*_hc5[1]*_t12*_t16*_t17*_t18*_t299*_t32*_t320*_t321*_t49*_t56*_t8*p->cam_omega + (0.1e1 / 0.162e3)*_hc5[1]*_t12*_t16*_t17*_t18*_t32*_t320*_t321*_t384*_t42*_t56*_t88*p->cam_omega - _t1009*_t248 - _t1017*_t973 - _t1018*_t2091 - _t1021*_t2091 + (0.2e1 / 0.81e2)*_t12*_t148*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t384*p->cam_omega + (0.2e1 / 0.81e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t32*_t320*_t321*_t384*_t49*_t8*_t88*p->cam_omega + (0.5e1 / 0.108e3)*_t12*_t16*_t17*_t18*_t299*_t30*_t32*_t320*_t321*_t42*p->cam_omega - _t1524*_t1541*_t2121 - _t159*_t2159*_t896 - _t1698*_t2061 - _t2060*_t761 - _t2062*_t313 - _t2092*_t968 - _t2093*_t916 - 0.11e2 / 0.108e3*_t2118 - _t2120*_t759 - _t2122 - 0.5e1 / 0.54e2*_t2153 - _t2154*_t636 - _t2155*_t2156 - _t2157*_t966 - _t2157*_t971 - 0.5e1 / 0.54e2*_t2158*_t765 - _t2160*_t966 - _t2160*_t971 - _t246*_t965 - _t396*_t637 - _t399*_t637) - _t1673*_t2103 + _t1674*_t909 + _t1684*_t373 + _t1686*_t375 + _t1687*_t909 + _t1690*_t974 + _t1870*_t2135 + _t1872*_t2135 - _t1879*_t999 + _t1881*_t367 + _t1882*_t373 + _t1883*_t909 + _t2044*_t309*_t60 + _t2055*_t336 - _t2101*_t744 - _t2101*_t746 - _t2106*_t394*_t51 + _t2107*_t312 + _t2108*_t235 + _t2109*_t400 + _t2110*_t394 + _t2112*_t312 - _t2112*_t749 + _t2134*_t231 + _t2134*_t233 + _t2136*_t993 + _t2137*_t2138 + _t2137*_t2140 + _t2139*_t374*_t993 + _t2141*_t745 + _t2141*_t815 + _t2142*_t2143 + _t2142*_t2148 - _t2144*_t606 - _t2144*_t751 - _t2145*_t603 + _t2146*_t2147 + _t2150*_t258 + _t2151*_t613 - _t2152*_t974 - 0.4e1 / 0.3e1*_t242*_t387 - _t242*_t994 + _t316*_t61*_t958 + _t326*_t743*_t954 + _t373*_t748 + _t392*_t606 + _t392*_t751 + _t51*_t984 - _t600*_t606*_t999 + _t741*_t955 + (0.10e2 / 0.3e1)*_t742 + _t758*_t918 + _t772*_t919);
  const double d4F_dnb3_dgaa = _t5*my_piecewise3(_t37, 0, _t1771*_t2012*_t659 + 0.3e1*_t1789*_t379 + _t1829*_t867 + _t1837*_t379 + _t1838*_t347 + 0.3e1*_t1913*_t978 + _t2006*_t774 + _t2012*_t261*_t291 + _t2016*_t2127*_t291 + _t2016*_t297*_t934 + _t2017*_t285*_t659 + _t2089*_t790 + _t2128*_t2130 + _t2130*_t779*_t870 + _t2161*_t297 + _t2161*_t779 + _t2162*_t779 + (0.3e1 / 0.2e1)*_t297*_t378 + _t676*_t982 + _t676*(_t2029 - _t2031*_t980 - _t2031*_t981 + _t2088*_t295 + _t275*_t354) + _t718*(-_t2022 - _t2023*_t663*_t75) + _t777*_t982 + _t786*_t876 + _t790*_t937 + _t94*((0.1e1 / 0.18e2)*_hc0[1]*_hc1[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t207*_t782*_t8*p->cam_omega + (0.1e1 / 0.72e2)*_hc0[1]*_hc1[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t288*_t42*_t74*p->cam_omega + (0.1e1 / 0.72e2)*_hc0[1]*_hc1[2]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t289*_t42*_t74*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t206*_t207*_t288*_t8*_t89*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[1]*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t206*_t207*_t785*_t8*_t89*p->cam_omega - _t1853*_t355 - _t2035 - _t2040*_t295 - _t2042*_t788 - _t2075*_t787 - _t2163*_t288 - _t2163*_t785 - _t884*_t947)) + 0.3e1*_t983;
  const double d4F_dnb3_dgbb = 0.3e1*_t1024 + _t5*my_piecewise3(_t39, 0, -_hc6[1]*_t1023*_t809 + _t1005*_t1876 + _t1005*_t1877 - _t1005*_t1878 - 0.1e1 / 0.3e1*_t101*_t1135*_t389 + _t1023*_t612 + _t1023*_t816 - 0.35e2 / 0.81e2*_t103*_t2166*_t320*_t990 + _t108*((0.1e1 / 0.9e1)*_hc4[1]*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t27*_t32*_t321*_t56*_t8*_t88*_t988*p->cam_omega + (0.1e1 / 0.9e1)*_hc4[1]*_hc4[2]*_t12*_t16*_t17*_t18*_t27*_t30*_t32*_t321*_t42*_t988*p->cam_omega + (0.11e2 / 0.9e1)*_hc4[1]*_hc4[2]*_t12*_t16*_t17*_t18*_t27*_t30*_t32*_t321*_t798*_t8*p->cam_omega + (0.16e2 / 0.81e2)*_hc4[1]*_hc4[3]*_t12*_t16*_t17*_t18*_t2164*_t30*_t32*_t321*_t8*p->cam_omega*gbb + (0.1e1 / 0.18e2)*_hc4[1]*_hc5[1]*_hc5[2]*_t12*_t122*_t16*_t163*_t17*_t18*_t28*_t31*_t32*_t8*_t821*p->cam_omega + (0.1e1 / 0.72e2)*_hc4[1]*_hc5[1]*_t12*_t122*_t16*_t17*_t18*_t28*_t31*_t313*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.18e2)*_hc4[1]*_hc5[1]*_t12*_t122*_t16*_t17*_t18*_t31*_t313*_t32*_t56*_t8*_t98*p->cam_omega + (0.1e1 / 0.72e2)*_hc4[1]*_hc5[2]*_t12*_t122*_t16*_t17*_t18*_t28*_t31*_t314*_t32*_t42*_t56*p->cam_omega + (0.1e1 / 0.18e2)*_hc4[1]*_hc5[2]*_t12*_t122*_t16*_t17*_t18*_t31*_t314*_t32*_t56*_t8*_t98*p->cam_omega - _hc4[1]*_t1013*_t1143 + (0.1e1 / 0.54e2)*_hc4[1]*_t12*_t122*_t16*_t162*_t163*_t17*_t18*_t28*_t31*_t313*_t32*_t8*_t88*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[1]*_t12*_t122*_t16*_t162*_t163*_t17*_t18*_t28*_t31*_t32*_t8*_t822*_t88*p->cam_omega + (0.1e1 / 0.18e2)*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t31*_t313*_t32*_t384*_t56*_t8*p->cam_omega + (0.1e1 / 0.18e2)*_hc4[2]*_hc5[2]*_t12*_t16*_t17*_t18*_t31*_t314*_t32*_t384*_t56*_t8*p->cam_omega + (0.5e1 / 0.36e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t299*_t32*_t320*_t321*_t56*_t8*_t88*p->cam_omega + (0.1e1 / 0.54e2)*_hc5[1]*_t12*_t16*_t17*_t18*_t32*_t320*_t321*_t384*_t42*_t56*_t88*p->cam_omega - _t1010*_t840*_t997 - _t1013*_t2155 - _t1019*_t2190 - _t1020*_t2190 - _t106*_t2159 + (0.1e1 / 0.27e2)*_t12*_t148*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t384*p->cam_omega + (0.1e1 / 0.27e2)*_t12*_t16*_t162*_t163*_t17*_t18*_t314*_t32*_t320*_t321*_t384*_t8*p->cam_omega + (0.5e1 / 0.27e2)*_t12*_t16*_t17*_t18*_t1964*_t1965*_t2164*_t30*_t32*_t8*p->cam_omega*gbb + (0.4e1 / 0.27e2)*_t12*_t16*_t17*_t18*_t1968*_t2164*_t30*_t32*_t321*_t8*p->cam_omega*gbb + (0.5e1 / 0.36e2)*_t12*_t16*_t17*_t18*_t299*_t30*_t32*_t320*_t321*_t42*p->cam_omega + (0.119e3 / 0.162e3)*_t12*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t792*_t8*p->cam_omega - 0.35e2 / 0.81e2*_t122*_t795*_t828 - _t1344*_t1971*_t2165 - _t156*_t966 - _t156*_t971 - _t1890*_t2061 - 0.22e2 / 0.27e2*_t1961*_t2168 - _t1962*_t2167 - _t1978*_t372 - _t1979*_t372 - _t1986*_t2060 - _t1988*_t2060 - _t201*_t2154 - _t2036*_t2168*_t836 - _t2059 - 0.5e1 / 0.18e2*_t2153 - _t2158*_t249*_t887 - _t2159*_t54 - 0.119e3 / 0.81e2*_t2166*_t825 - _t2189*_t248 - _t319*_t966 - _t319*_t971 - _t333*_t966 - _t333*_t971 - _t884*_t968) + 0.3e1*_t1684*_t400 + _t1875*_t909 + _t1882*_t400 - 0.32e2 / 0.27e2*_t1932*_t2165 + _t1936*_t2170 + _t1940*_t2170 + _t1947*_t2045 + _t1951*_t367 + _t1952*_t909 - _t1961*_t2167*_t995 + _t2044*_t805 + _t2046*_t2146*_t394 + _t2113*_t336 + _t2113*_t820 + _t2139*_t2171*_t394 - _t2143*_t2182 + _t2143*_t2186 - _t2148*_t2182 + _t2148*_t2186 + _t2151*_t820 - _t2168*_t548*_t996 + _t2169*_t307 + _t2169*_t311 + _t2171*_t2172 + _t2174*_t2175 + _t2175*_t2183 - _t2177*_t745 - _t2177*_t815 - _t2179*_t745 - _t2179*_t815 - _t2180*_t395 - _t2180*_t398 - _t2181*_t316*_t390 + _t2184*_t745 + _t2184*_t815 - _t2185*_t385 - _t2185*_t387 - _t2187*_t809 + _t2187*_t810 + _t2188*_t336 + _t2188*_t820 + _t612*(_t1008*_t2027 + _t1009*_t79 + _t1012*_t1899*_t222 - _t1016*_t1228 + _t1018*_t161 - _t1019*_t2057 - _t1020*_t2057 + _t1021*_t161 - _t158*_t963 + _t201*_t396 + _t201*_t399 + _t2056 + _t2154*_t218 + _t2189*_t252 - _t249*_t252*_t969 + _t250*_t371 - _t324*_t887) + _t748*(-_t118*_t968 + (0.1e1 / 0.12e2)*_t12*_t16*_t17*_t18*_t30*_t32*_t320*_t321*_t384*_t8*p->cam_omega - _t2049 - _t36*_t966 - _t36*_t971) - 0.476e3 / 0.27e2*_t793 - 0.140e3 / 0.27e2*_t795*_t985 - 0.88e2 / 0.9e1*_t798*_t987 + 0.10e2*_t801 + 0.10e2*_t806 + _t823*_t918 + _t845*_t919);
  const double d4F_dna2_dgaa2 = 0.2e1*_t1077 + _t5*my_piecewise3(_t37, 0, (0.4e1 / 0.9e1)*_hc0[4]*_t2191*_t63 - _hc2[1]*_t1044*_t346 - 0.7e1 / 0.9e1*_t1025*_t176 - 0.2e1 / 0.3e1*_t1029*_t1316 + (0.7e1 / 0.432e3)*_t1034*_t2192 - _t1041*_t536 + _t1044*_t119*_t2216 + _t1044*_t2081*_t2219 + _t1044*_t2213*_t2214 - _t1044*_t927 - _t1047*_t525 - _t1047*_t538 + _t1048*_t525 + _t1048*_t538 + _t1053*_t227 + _t1054*_t22*_t872 + 0.2e1*_t1054*_t863 - _t1056*_t2203 + (0.2e1 / 0.3e1)*_t1058*_t179 + _t1059*_t2203 + _t1062*_t2209 - _t1076*_t1791 + _t1076*_t671 + _t1109*_t227 + _t1110*_t227 + _t1111*_t907 + _t117*_t907 - 0.7e1 / 0.216e3*_t1171*_t2192 - _t1228*_t2223*_t864 + _t1415*_t2195*_t252*_t81 + (0.1e1 / 0.108e3)*_t1417*_t2191*_t2193 + (0.7e1 / 0.9e1)*_t172*_t410 + _t181*_t2204 + _t181*_t2207 + _t181*_t2211 + _t196*_t2212 + _t196*_t2217 + (0.7e1 / 0.108e3)*_t1998*_t424 - _t2010*_t420 - _t2018*_t2215 + _t2019*_t2220 + _t2019*_t2221 - _t2019*_t420 + _t2026*_t882 + _t2192*_t2197*_t861 + (0.19e2 / 0.9e1)*_t2192*_t513 + _t2194*_t860*_t890 - _t2195*_t2196*_t896 - _t2199*_t2205 - _t2199*_t872 - _t2200*_t863 - _t2200*_t868 + _t2201*_t2202 + _t2202*_t2208 - _t2209*_t417 - _t2222*_t359 - _t2222*_t362 + _t2224*_t882 + _t272*(-_t1056*_t345 - _t1057*_t118 + _t1059*_t345 + _t1061*_t873 - _t1062*_t2225 + _t1069*_t2226 + _t2225*_t417 + _t2227 - _t361*_t408 + _t408*_t880*_t904) - _t346*_t411*_t84 + _t352*_t882 - _t408*_t85*_t929 - _t420*_t883 + _t94*((0.1e1 / 0.144e3)*_hc0[1]*_hc1[1]*_t12*_t13*_t139*_t14*_t16*_t17*_t18*_t2*_t403*_t74*_t8*p->cam_omega + (0.1e1 / 0.144e3)*_hc0[1]*_hc1[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t2*_t403*_t74*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[2]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t340*_t408*_t69*_t74*_t8*p->cam_omega + (0.1e1 / 0.216e3)*_hc0[2]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t405*_t408*_t42*_t69*_t74*p->cam_omega + (0.7e1 / 0.108e3)*_hc0[2]*_t11*_t12*_t13*_t14*_t16*_t17*_t170*_t18*_t408*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[2]*_t11*_t12*_t13*_t14*_t16*_t17*_t18*_t340*_t408*_t42*p->cam_omega + (0.1e1 / 0.6e1)*_hc0[2]*_t11*_t12*_t14*_t16*_t17*_t18*_t212*_t2191*_t583*_t8*p->cam_omega + (0.1e1 / 0.108e3)*_hc0[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t191*_t206*_t207*_t405*_t408*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[3]*_hc1[1]*_t1028*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t69*_t74*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc0[3]*_t1028*_t11*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t42*p->cam_omega + (0.19e2 / 0.108e3)*_hc0[3]*_t11*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t8*_t852*p->cam_omega + (0.1e1 / 0.27e2)*_hc0[4]*_t11*_t12*_t13*_t14*_t16*_t17*_t18*_t2191*_t8*p->cam_omega + (0.1e1 / 0.72e2)*_hc1[1]*_t1028*_t112*_t12*_t14*_t16*_t17*_t18*_t583*_t584*_t69*_t74*_t8*p->cam_omega + (0.1e1 / 0.288e3)*_hc1[1]*_t12*_t139*_t14*_t16*_t17*_t18*_t212*_t213*_t405*_t408*_t74*_t8*p->cam_omega + (0.1e1 / 0.288e3)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t191*_t212*_t213*_t405*_t408*_t74*_t8*p->cam_omega + (0.1e1 / 0.72e2)*_t1028*_t11*_t112*_t12*_t14*_t16*_t17*_t18*_t42*_t583*_t584*p->cam_omega - _t1059*_t248*_t81 - _t1059*_t593*_t896 - _t1061*_t878 - _t1068*_t2202*_t893 - _t1069*_t2234 + (0.19e2 / 0.144e3)*_t11*_t112*_t12*_t14*_t16*_t17*_t18*_t583*_t584*_t8*_t852*p->cam_omega - _t1408*_t2194 - _t1412*_t2191*_t2228 - _t1416*_t2191*_t58 - _t1438*_t2232 - _t1440*_t2232 - 0.7e1 / 0.108e3*_t176*_t403*_t577 - _t210*_t2231*_t417 - _t210*_t2233*_t8 - 0.7e1 / 0.216e3*_t216*_t2229 - _t2192*_t2230*_t894 - 0.1e1 / 0.108e3*_t2229*_t898 - _t2237 - _t408*_t938 - _t417*_t593*_t943));
  const double d4F_dna2_dgbb2 = 0.2e1*_t1106 + _t5*my_piecewise3(_t39, 0, -_t1078*_t604 + _t108*((0.1e1 / 0.144e3)*_hc4[1]*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t28*_t31*_t32*_t430*_t56*_t8*p->cam_omega + (0.1e1 / 0.144e3)*_hc4[1]*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t28*_t31*_t32*_t430*_t56*_t8*p->cam_omega + (0.1e1 / 0.216e3)*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t31*_t32*_t42*_t432*_t435*_t49*_t56*p->cam_omega + (0.1e1 / 0.108e3)*_hc4[2]*_t12*_t146*_t16*_t162*_t163*_t17*_t18*_t31*_t32*_t432*_t435*_t8*p->cam_omega + (0.1e1 / 0.288e3)*_hc5[1]*_t12*_t140*_t16*_t17*_t18*_t32*_t320*_t321*_t432*_t435*_t56*_t8*p->cam_omega + (0.1e1 / 0.288e3)*_hc5[2]*_t12*_t146*_t16*_t17*_t18*_t32*_t320*_t321*_t432*_t435*_t56*_t8*p->cam_omega - _t159*_t2256*_t943 - _t2234*_t2261 - _t2256*_t465*_t944 - _t2259*_t922 - _t2259*_t923 - _t2260*_t646 - _t2262) + _t1081*_t1089*_t2245 + (0.1e1 / 0.16e2)*_t1081*_t2247 - _t1083*_t153 + _t1097*_t2244 + _t1105*_t911 + _t1136*_t925 + _t127*_t925 - _t128*_t2105*_t443 + _t130*_t2240 + _t153*_t2249 + _t153*_t2250 + _t153*_t2251 + _t153*_t2252 + _t168*_t2254 - _t2048*_t2241 + _t2048*_t2242 + _t2048*_t2243 + _t2050*_t375 - _t2052*_t2241 + _t2052*_t2242 + _t2052*_t2243 + _t2054*_t917 + _t2147*_t2246 - _t2238*_t456 - _t2238*_t607 + _t2239*_t456 + _t2239*_t607 - _t2244*_t443 + _t2248*_t36*_t912 + _t2253*_t917 + _t243*(-_t1097*_t2255*_t31 + (0.1e1 / 0.144e3)*_t1101 + _t2255*_t2256 + _t2258) + 0.2e1*_t368*_t373);
  const double d4F_dna_dnb_dgaa2 = _t1077 + _t1115 + _t5*my_piecewise3(_t37, 0, -_hc2[1]*_t1040*_t1108 - _t1027*_t1108 - _t1030*_t1561 - _t1030*_t1563 - _t1035*_t2067 - _t1035*_t2069 + _t1036*_t2265 + _t1036*_t2266 - _t1040*_t411*_t93 - _t1041*_t662 - _t1047*_t656 - _t1047*_t661 - _t1047*_t666 - _t1047*_t670 + _t1048*_t656 + _t1048*_t661 + _t1048*_t666 + _t1048*_t670 + _t1049*_t1108*_t416 + _t1053*_t283 + _t1054*_t380 + _t1054*_t928 + _t1055*_t2130 + _t1055*_t934 + _t1076*_t286 + _t1076*_t676 + _t1108*_t2081*_t427 + _t1108*_t2216*_t419 + _t1109*_t283 + _t1110*_t283 + _t1111*_t949 + _t1114*_t272 + _t1114*_t539 - _t1114*_t932 + _t117*_t949 + _t1775*_t2204 + _t1775*_t2207 + _t1775*_t2211 + _t2026*_t2129 - _t2068*_t2070 - _t2073*_t420 + _t2074*_t2220 + _t2074*_t2221 - _t2074*_t420 - _t2076*_t420 + _t2078*_t408*_t416 - _t2084*_t379 - _t2085*_t379 + _t2086*_t379 - _t2130*_t2264 + _t2212*_t271 + _t2217*_t271 + _t2220*_t933 + _t2221*_t933 + _t2224*_t379 + _t2263*_t260 + _t2263*_t263 - _t2264*_t934 - 0.1e1 / 0.3e1*_t261*_t359*_t410 - _t283*_t350*_t420 + _t349*_t379 + _t352*_t379 - _t420*_t933 + _t94*((0.1e1 / 0.72e2)*_hc0[1]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t244*_t4*_t403*_t74*p->cam_omega + (0.1e1 / 0.144e3)*_hc0[1]*_hc1[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t403*_t69*_t74*_t8*_t89*p->cam_omega + (0.1e1 / 0.108e3)*_hc0[2]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t340*_t408*_t74*_t8*_t89*p->cam_omega + (0.1e1 / 0.432e3)*_hc0[2]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t405*_t408*_t42*_t69*_t74*p->cam_omega + (0.1e1 / 0.432e3)*_hc0[2]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t405*_t408*_t42*_t74*_t89*p->cam_omega + (0.1e1 / 0.108e3)*_hc0[2]*_t11*_t12*_t13*_t14*_t16*_t17*_t18*_t340*_t408*_t42*p->cam_omega + (0.1e1 / 0.108e3)*_hc0[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t206*_t207*_t405*_t408*_t69*_t8*_t89*p->cam_omega + (0.1e1 / 0.108e3)*_hc0[3]*_hc1[1]*_t1028*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t74*_t8*_t89*p->cam_omega + (0.1e1 / 0.108e3)*_hc0[3]*_t1028*_t11*_t112*_t12*_t13*_t14*_t16*_t17*_t18*_t42*p->cam_omega + (0.1e1 / 0.144e3)*_hc1[1]*_t1028*_t112*_t12*_t14*_t16*_t17*_t18*_t583*_t584*_t74*_t8*_t89*p->cam_omega + (0.1e1 / 0.144e3)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t244*_t4*_t405*_t408*_t74*p->cam_omega + (0.1e1 / 0.288e3)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t405*_t408*_t69*_t74*_t8*_t89*p->cam_omega + (0.1e1 / 0.144e3)*_t1028*_t11*_t112*_t12*_t14*_t16*_t17*_t18*_t42*_t583*_t584*p->cam_omega - _t1036*_t213*_t274*_t893 - _t1059*_t2231*_t274 - _t1059*_t81*_t905 - _t1060*_t943 - _t1061*_t356 - _t1069*_t2269 - _t13*_t2232*_t948 - _t1437*_t2268 - _t1664*_t2268 - _t1666*_t2233 - 0.1e1 / 0.216e3*_t2229*_t945 - _t2231*_t417*_t674 - _t2237 - 0.1e1 / 0.72e2*_t2267*_t940 - _t2269*_t2270));
  const double d4F_dna_dnb_dgbb2 = _t1106 + _t1146 + _t5*my_piecewise3(_t39, 0, -_t1002*_t954 + _t1004*_t2248 - _t1078*_t747 + _t108*((0.1e1 / 0.144e3)*_hc4[1]*_hc5[2]*_t12*_t16*_t17*_t18*_t28*_t31*_t32*_t430*_t49*_t56*_t8*_t88*p->cam_omega + (0.1e1 / 0.72e2)*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t244*_t31*_t32*_t4*_t432*_t435*_t56*p->cam_omega + (0.1e1 / 0.108e3)*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t31*_t32*_t384*_t435*_t49*_t56*_t8*p->cam_omega + (0.1e1 / 0.432e3)*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t31*_t32*_t42*_t432*_t435*_t49*_t56*p->cam_omega + (0.1e1 / 0.432e3)*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t31*_t32*_t42*_t432*_t435*_t56*_t88*p->cam_omega + (0.1e1 / 0.108e3)*_hc4[2]*_t12*_t16*_t162*_t163*_t17*_t18*_t31*_t32*_t432*_t435*_t49*_t8*_t88*p->cam_omega + (0.1e1 / 0.108e3)*_hc4[2]*_t12*_t16*_t17*_t18*_t30*_t31*_t32*_t384*_t42*_t435*p->cam_omega + (0.1e1 / 0.108e3)*_hc4[3]*_hc5[1]*_t1119*_t12*_t122*_t16*_t17*_t18*_t31*_t32*_t49*_t56*_t8*p->cam_omega + (0.1e1 / 0.108e3)*_hc4[3]*_t1119*_t12*_t122*_t16*_t17*_t18*_t30*_t31*_t32*_t42*p->cam_omega + (0.1e1 / 0.144e3)*_hc5[1]*_t1119*_t12*_t122*_t16*_t17*_t18*_t32*_t49*_t56*_t8*_t833*_t834*p->cam_omega + (0.1e1 / 0.288e3)*_hc5[2]*_t12*_t16*_t17*_t18*_t32*_t320*_t321*_t432*_t435*_t49*_t56*_t8*_t88*p->cam_omega - _t103*_t1140*_t905 - 0.1e1 / 0.144e3*_t1100*_t2115 + (0.1e1 / 0.144e3)*_t1119*_t12*_t122*_t16*_t17*_t18*_t30*_t32*_t42*_t833*_t834*p->cam_omega - _t1140*_t31*_t970 - _t1141*_t943 - _t1142*_t356 - _t159*_t1738*_t2291 - 0.1e1 / 0.216e3*_t159*_t2290 - _t1911*_t2260 - _t1973*_t2291 - 0.1e1 / 0.72e2*_t2115*_t2256 - _t2255*_t2293 - _t2256*_t616*_t944 - _t2259*_t973 - _t2261*_t2269 - _t2262 - _t2269*_t2292) - _t1081*_t1118 - _t1081*_t1130 + _t1081*_t2285*_t438 + (0.1e1 / 0.32e2)*_t1081*_t2286 - _t1083*_t242 - _t1086*_t744 - _t1086*_t746 + _t1087*_t744 + _t1087*_t746 + _t1089*_t1132*_t438 - _t1092*_t2283 + _t1092*_t2284 + _t1096*_t913*_t961 - _t1105*_t2111 + _t1105*_t610 + _t1105*_t612 - _t1121*_t1870 - _t1121*_t1872 - _t1125*_t2273 - _t1125*_t2277 - _t1126*_t2274 - _t1126*_t2278 + _t1128*_t2276 + _t1128*_t2280 - _t1129*_t2281*_t374 + (0.1e1 / 0.32e2)*_t1132*_t2247 + _t1134*_t2246 - _t1134*_t443*_t51 + _t1136*_t974 + _t1145*_t243 + _t1145*_t460 + _t125*_t2145 + _t127*_t974 + _t1477*_t2240 + _t2054*_t2288 + _t2103*_t392 - _t2106*_t2282 + _t2112*_t375 - _t2114*_t2241 + _t2114*_t2242 + _t2114*_t2243 - _t2238*_t606 - _t2238*_t751 + _t2239*_t606 + _t2239*_t751 - _t2241*_t962 + _t2242*_t962 + _t2243*_t962 + _t2249*_t242 + _t2250*_t242 + _t2251*_t242 + _t2252*_t242 + _t2253*_t400 + _t2254*_t258 + _t2271*_t231 + _t2271*_t233 + _t2287*_t914 + _t368*_t400 - 0.1e1 / 0.3e1*_t395*_t439*_t61 - _t955*_t999);
  const double d4F_dnb2_dgaa2 = 0.2e1*_t1115 + _t5*my_piecewise3(_t37, 0, _hc2[2]*_t2219*_t2295 - _t1041*_t715 - _t1047*_t712 - _t1047*_t721 + _t1048*_t712 + _t1048*_t721 + _t1053*_t297 + _t1062*_t2294 + _t1109*_t297 + _t1110*_t297 + _t1111*_t982 + _t1114*_t287 + _t115*_t22*_t379*_t934 + _t117*_t982 + _t119*_t2295*_t2296 - _t2124*_t420 + _t2125*_t2220 + _t2125*_t2221 - _t2125*_t420 - _t2126*_t420 + _t2129*_t378 + _t2131*_t978 + _t2162*_t978 + _t2204*_t285 + _t2207*_t285 + _t2210*_t2214*_t2295 + _t2211*_t285 + _t2212*_t291 - _t2215*_t977 + _t2217*_t291 - _t2294*_t417 + _t381*_t978 + _t676*((0.1e1 / 0.144e3)*_t1113 + _t2227 - _t2267*_t2297 + _t2297*_t2298) + _t94*((0.1e1 / 0.144e3)*_hc0[1]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t288*_t403*_t74*_t8*p->cam_omega + (0.1e1 / 0.144e3)*_hc0[1]*_hc1[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t2*_t289*_t403*_t74*_t8*p->cam_omega + (0.1e1 / 0.216e3)*_hc0[2]*_hc1[1]*_t12*_t13*_t14*_t16*_t17*_t18*_t405*_t408*_t42*_t74*_t89*p->cam_omega + (0.1e1 / 0.108e3)*_hc0[2]*_t12*_t13*_t14*_t16*_t17*_t18*_t206*_t207*_t289*_t405*_t408*_t8*p->cam_omega + (0.1e1 / 0.288e3)*_hc1[1]*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t288*_t405*_t408*_t74*_t8*p->cam_omega + (0.1e1 / 0.288e3)*_hc1[2]*_t12*_t14*_t16*_t17*_t18*_t212*_t213*_t289*_t405*_t408*_t74*_t8*p->cam_omega - _t1811*_t2299 - _t1816*_t2299 - _t2231*_t295*_t417 - _t2233*_t737 - _t2234*_t2270 - _t2237 - _t2298*_t274*_t943));
  const double d4F_dnb2_dgbb2 = 0.2e1*_t1146 + _t5*my_piecewise3(_t39, 0, (0.4e1 / 0.9e1)*_hc4[4]*_t2300*_t96 + _hc7[0]*_t2311*_t394 + _t1006*_t1145 + _t1007*_t2150 + _t1007*_t2151 + _t1023*_t1136 + _t1023*_t127 - _t103*_t1228*_t2287*_t956 + _t103*_t1968*_t2303*_t252 + _t103*_t2302*_t995 - _t1078*_t813 + _t108*((0.1e1 / 0.144e3)*_hc4[1]*_hc5[1]*_t12*_t16*_t17*_t18*_t28*_t31*_t313*_t32*_t430*_t56*_t8*p->cam_omega + (0.1e1 / 0.144e3)*_hc4[1]*_hc5[2]*_t12*_t16*_t17*_t18*_t28*_t31*_t314*_t32*_t430*_t56*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t31*_t32*_t384*_t435*_t56*_t8*_t88*p->cam_omega + (0.1e1 / 0.216e3)*_hc4[2]*_hc5[1]*_t12*_t16*_t17*_t18*_t31*_t32*_t42*_t432*_t435*_t56*_t88*p->cam_omega + (0.1e1 / 0.108e3)*_hc4[2]*_t12*_t16*_t162*_t163*_t17*_t18*_t31*_t314*_t32*_t432*_t435*_t8*p->cam_omega + (0.1e1 / 0.6e1)*_hc4[2]*_t12*_t16*_t17*_t18*_t2300*_t30*_t32*_t320*_t8*_t833*p->cam_omega + (0.7e1 / 0.108e3)*_hc4[2]*_t12*_t16*_t17*_t18*_t299*_t30*_t31*_t32*_t435*_t8*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[2]*_t12*_t16*_t17*_t18*_t30*_t31*_t32*_t384*_t42*_t435*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[3]*_hc5[1]*_t1119*_t12*_t122*_t16*_t17*_t18*_t31*_t32*_t56*_t8*_t88*p->cam_omega + (0.1e1 / 0.54e2)*_hc4[3]*_t1119*_t12*_t122*_t16*_t17*_t18*_t30*_t31*_t32*_t42*p->cam_omega + (0.19e2 / 0.108e3)*_hc4[3]*_t12*_t122*_t16*_t17*_t18*_t30*_t31*_t32*_t8*_t988*p->cam_omega + (0.1e1 / 0.27e2)*_hc4[4]*_t12*_t16*_t17*_t18*_t2300*_t30*_t31*_t32*_t8*p->cam_omega + (0.1e1 / 0.72e2)*_hc5[1]*_t1119*_t12*_t122*_t16*_t17*_t18*_t32*_t56*_t8*_t833*_t834*_t88*p->cam_omega + (0.1e1 / 0.288e3)*_hc5[1]*_t12*_t16*_t17*_t18*_t313*_t32*_t320*_t321*_t432*_t435*_t56*_t8*p->cam_omega + (0.1e1 / 0.288e3)*_hc5[2]*_t12*_t16*_t17*_t18*_t314*_t32*_t320*_t321*_t432*_t435*_t56*_t8*p->cam_omega - _t1014*_t2302 - _t1015*_t2230*_t2301 - _t1019*_t2259 - _t1020*_t2259 - _t103*_t1140*_t248 + (0.1e1 / 0.72e2)*_t1119*_t12*_t122*_t16*_t17*_t18*_t30*_t32*_t42*_t833*_t834*p->cam_omega - _t1140*_t840*_t896 - _t1142*_t878 + (0.19e2 / 0.144e3)*_t12*_t122*_t16*_t17*_t18*_t30*_t32*_t8*_t833*_t834*_t988*p->cam_omega - _t1967*_t2228*_t2300 - _t1969*_t2300*_t58 - _t2234*_t2292 - _t2256*_t759*_t944 - _t2260*_t759*_t8 - _t2262 - 0.7e1 / 0.216e3*_t2289*_t324 - 0.1e1 / 0.108e3*_t2290*_t249 - _t2293*_t249*_t880 - 0.7e1 / 0.108e3*_t305*_t430*_t828 - _t435*_t964 - _t443*_t840*_t943) - _t1083*_t316 + _t1097*_t2314 - 0.7e1 / 0.9e1*_t1116*_t305 - 0.2e1 / 0.3e1*_t1120*_t1936 + (0.1e1 / 0.108e3)*_t1123*_t1970*_t2300 + _t1132*_t2245*_t2285 + (0.1e1 / 0.16e2)*_t1132*_t2286 - _t1132*_t391 - _t1132*_t951 - _t1137*_t2312 + (0.2e1 / 0.3e1)*_t1139*_t307 + _t1140*_t2312 - _t1145*_t2152 - _t1190*_t2309*_t394 + (0.7e1 / 0.432e3)*_t1195*_t2301 - 0.7e1 / 0.216e3*_t1205*_t2301 - _t1908*_t2173*_t2309 - _t2099*_t235*_t435 - _t2143*_t2241 + _t2143*_t2242 + _t2143*_t2243 - _t2148*_t2241 + _t2148*_t2242 + _t2148*_t2243 + _t2173*_t2311 - _t2176*_t2315 - _t2178*_t2315 + _t2187*_t375 + _t2197*_t2301*_t996 - _t2238*_t745 - _t2238*_t815 + _t2239*_t745 + _t2239*_t815 + _t2240*_t309 + _t2249*_t316 + _t2250*_t316 + _t2251*_t316 + _t2252*_t316 + _t2254*_t336 - _t2281*_t388*_t394 - _t2283*_t960 + _t2284*_t960 + _t2287*_t36*_t392 + _t2288*_t393 + (0.19e2 / 0.9e1)*_t2301*_t797 - _t2303*_t2304*_t896 + (0.7e1 / 0.108e3)*_t2305*_t992 - _t2307*_t2308 - _t2308*_t2313 - _t2314*_t443 + (0.7e1 / 0.9e1)*_t301*_t439 + _t612*(-_t1097*_t2316 - _t1137*_t388 - _t1138*_t118 + _t1140*_t388 + _t1142*_t873 + _t2226*_t2292 + _t2258 + _t2310*_t389*_t435 + _t2316*_t443 - _t397*_t435));
  const double d4F_dna_dgaa3 = _t1179 + _t5*my_piecewise3(_t37, 0, -_hc0[1]*_t2324*_t58*_t890 - _t1042*_t2327 + _t1076*_t2355 + _t1076*_t2356 + (0.1e1 / 0.24e2)*_t1150*_t344*_t854 + _t1161*_t2336 + _t1161*_t2344 - _t1165*_t2336 - _t1165*_t2344 - _t1166*_t2324*_t2325 + _t1168*_t2335 + _t1168*_t2343 + _t1170*_t2001 + _t1170*_t2011 + _t118*_t2196*_t2324 - 0.1e1 / 0.6e1*_t1311*_t2320 + _t1316*_t2328 - _t1319*_t2327 + _t1321*_t2328 - 0.1e1 / 0.24e2*_t1415*_t2324*_t425 + _t179*_t2326 + _t183*_t2341 - _t2201*_t2337 + _t2205*_t2332 + _t2205*_t2334 - _t2206*_t2319*_t2329*_t2330 - _t2208*_t2337 - _t2213*_t2342 - _t2223*_t2352 - 0.1e1 / 0.2e1*_t2317*_t64 + (0.1e1 / 0.2e1)*_t2318*_t341 + (0.1e1 / 0.192e3)*_t2321*_t2322 - 0.1e1 / 0.48e2*_t2322*_t2323 + _t2332*_t872 - _t2333*_t872 + _t2334*_t872 - _t2338*_t863 - _t2338*_t868 + _t2340*_t71 + _t2345*_t84 - _t2346*_t877 + _t2347*_t2348 + _t2347*_t2349 + _t2347*_t2353 + _t2347*_t2354 + _t94*((0.1e1 / 0.192e3)*_hc0[1]*_hc0[2]*_hc1[1]*_t1152*_t12*_t14*_t16*_t17*_t18*_t213*_t403*_t69*_t74*_t8*p->cam_omega + (0.1e1 / 0.36e2)*_hc0[1]*_hc0[3]*_t11*_t12*_t14*_t16*_t17*_t18*_t213*_t2319*_t408*_t8*p->cam_omega + (0.1e1 / 0.96e2)*_hc0[2]*_hc1[1]*_t1150*_t12*_t13*_t14*_t16*_t17*_t18*_t405*_t69*_t74*_t8*p->cam_omega + (0.1e1 / 0.24e2)*_hc0[2]*_t11*_t1150*_t12*_t13*_t14*_t16*_t17*_t18*_t340*_t8*p->cam_omega - _t1064*_t2358 + (0.5e1 / 0.192e3)*_t11*_t12*_t14*_t1409*_t1410*_t16*_t17*_t18*_t2319*_t408*_t8*p->cam_omega + (0.1e1 / 0.48e2)*_t11*_t12*_t14*_t1415*_t16*_t17*_t18*_t213*_t2319*_t408*_t8*p->cam_omega - _t1150*_t418*_t904 - _t1161*_t1166*_t593 - 0.1e1 / 0.72e2*_t1402*_t2320 - _t1418*_t2320*_t2350 - _t1442*_t2357 - _t1443*_t2359 - 0.1e1 / 0.24e2*_t2317*_t577 - _t2361));
  const double d4F_dna_dgbb3 = _t1213 + _t5*my_piecewise3(_t39, 0, -_t1079*_t2363 + _t108*((0.1e1 / 0.192e3)*_hc4[1]*_hc4[2]*_hc5[1]*_t1185*_t12*_t16*_t17*_t18*_t32*_t321*_t430*_t49*_t56*_t8*p->cam_omega + (0.1e1 / 0.96e2)*_hc4[2]*_hc5[1]*_t1183*_t12*_t16*_t17*_t18*_t31*_t32*_t432*_t49*_t56*_t8*p->cam_omega - _t1188*_t2393*_t765 - 0.1e1 / 0.288e3*_t1202*_t766 - _t159*_t2390*_t31 - _t2392*_t765 - _t2394) + _t1089*_t2376 - _t1089*_t2377 - _t1094*_t1207 + _t1097*_t2375 + _t1097*_t2386 + _t1105*_t2388 + _t1105*_t2389 + _t1199*_t51 - _t1200*_t2379 + _t1204*_t2274 + _t1204*_t2278 + _t1676*_t2365*_t441 + _t1870*_t2364 - _t1871*_t2363 + _t1872*_t2364 - _t2136*_t2371 - _t2272*_t2366 + _t2273*_t2367 - _t2276*_t2370 + _t2277*_t2367 - _t2280*_t2370 + _t231*_t2362 + _t232*_t2374 - _t2368*_t51 + _t2369*_t51 + _t2373*_t51 - _t2375*_t443 + _t2378*_t2381 + _t2379*_t2380 + _t2382*_t60 + _t2383*_t2384 + _t2383*_t2387 - _t2386*_t443);
  const double d4F_dnb_dgaa3 = _t1179 + _t5*my_piecewise3(_t37, 0, -_t1107*_t2327 + _t1114*_t2355 + _t1114*_t2356 + _t1161*_t2396 + _t1161*_t2399 - _t1165*_t2396 - _t1165*_t2399 + _t1168*_t2395 + _t1168*_t2398 + _t1170*_t2067 + _t1170*_t2069 + _t1561*_t2328 - _t1562*_t2327 + _t1563*_t2328 - _t2068*_t2346 + _t2130*_t2332 + _t2130*_t2334 - _t2210*_t2342*_t93 - _t2265*_t2337 - _t2266*_t2337 + _t2326*_t260 + _t2332*_t934 - _t2333*_t934 + _t2334*_t934 - _t2338*_t380 - _t2338*_t928 + _t2340*_t90 + _t2341*_t262 + _t2345*_t93 + _t2348*_t2397 + _t2349*_t2397 - _t2352*_t350*_t379 + _t2353*_t2397 + _t2354*_t2397 + _t94*((0.1e1 / 0.192e3)*_hc0[1]*_hc0[2]*_hc1[1]*_t1152*_t12*_t14*_t16*_t17*_t18*_t213*_t403*_t74*_t8*_t89*p->cam_omega + (0.1e1 / 0.96e2)*_hc0[2]*_hc1[1]*_t1150*_t12*_t13*_t14*_t16*_t17*_t18*_t405*_t74*_t8*_t89*p->cam_omega - _t1161*_t1166*_t13*_t274 - _t1663*_t2359 - _t1665*_t2357 - _t2358*_t700 - _t2361));
  const double d4F_dnb_dgbb3 = _t1213 + _t5*my_piecewise3(_t39, 0, _hc4[1]*_t2306*_t2365 - _hc4[3]*_t1899*_t2407*_t58 + _t101*_t1199 - _t101*_t2275*_t2370 - _t101*_t2368 + _t101*_t2369 + _t101*_t2373 + _t107*_t2382 + _t108*((0.1e1 / 0.192e3)*_hc4[1]*_hc4[2]*_hc5[1]*_t1185*_t12*_t16*_t17*_t18*_t32*_t321*_t430*_t56*_t8*_t88*p->cam_omega + (0.1e1 / 0.36e2)*_hc4[1]*_hc4[3]*_t12*_t16*_t17*_t18*_t2401*_t30*_t32*_t321*_t435*_t8*p->cam_omega + (0.1e1 / 0.96e2)*_hc4[2]*_hc5[1]*_t1183*_t12*_t16*_t17*_t18*_t31*_t32*_t432*_t56*_t8*_t88*p->cam_omega + (0.1e1 / 0.24e2)*_hc4[2]*_t1183*_t12*_t16*_t17*_t18*_t30*_t31*_t32*_t384*_t8*p->cam_omega - _t1066*_t1202*_t840 - _t1183*_t418*_t963 - _t1188*_t2393*_t2415 + (0.5e1 / 0.192e3)*_t12*_t16*_t17*_t18*_t1964*_t1965*_t2401*_t30*_t32*_t435*_t8*p->cam_omega + (0.1e1 / 0.48e2)*_t12*_t16*_t17*_t18*_t1968*_t2401*_t30*_t32*_t321*_t435*_t8*p->cam_omega - 0.1e1 / 0.72e2*_t1962*_t2402 - _t1971*_t2350*_t2402 - _t2390*_t840 - _t2392*_t2415 - _t2394 - 0.1e1 / 0.24e2*_t2400*_t828) - _t1131*_t2363 - _t1135*_t1207 + _t1145*_t2388 + _t1145*_t2389 - _t1166*_t2406*_t2408 + _t118*_t2304*_t2407 + (0.1e1 / 0.2e1)*_t1192*_t385 + (0.1e1 / 0.24e2)*_t1192*_t390*_t450 - _t1200*_t2411 + _t1204*_t2174 + _t1204*_t2183 - 0.1e1 / 0.6e1*_t1932*_t2402 + _t1936*_t2364 - _t1938*_t2363 + _t1940*_t2364 - 0.1e1 / 0.24e2*_t1968*_t2305*_t2401 - _t2172*_t2371 - _t2279*_t2370*_t394 + _t2285*_t2376 - _t2285*_t2377 - _t2306*_t2366 + _t2307*_t2367 + _t2313*_t2367 - _t2329*_t2406*_t2409 + _t2362*_t307 + _t2374*_t310 + _t2380*_t2411 + _t2381*_t2410 + _t2384*_t2413 + _t2387*_t2413 - 0.1e1 / 0.2e1*_t2400*_t97 + (0.1e1 / 0.192e3)*_t2403*_t2404 - 0.1e1 / 0.48e2*_t2404*_t2405 - _t2412*_t444 + _t2412*_t448 - _t2414*_t444 + _t2414*_t448);
  const double d4F_dgaa4 = _t5*my_piecewise3(_t37, 0, -_hc0[3]*_t1164*_t2419 + (0.1e1 / 0.192e3)*_hc0[4]*_t2418*_t2426 + _hc2[4]*_t1410*_t1436*_t2424*_t2425*_t74 - _t1032*_t2420*_t893 + (0.5e1 / 0.256e3)*_t1032*_t2422 - _t1033*_t1175*_t2419*_t2433 - 0.3e1 / 0.256e3*_t1034*_t2419 - 0.15e2 / 0.16e2*_t111*_t2416 - _t114*_t2416*_t2427 - _t1148*_t1153 + _t1159*_t2423 + _t1171*_t2420 + _t1174*_t2323*_t2432*_t2433 + (0.1e1 / 0.16e2)*_t1311*_t2418 + (0.1e1 / 0.192e3)*_t1407*_t2421 + (0.3e1 / 0.256e3)*_t1417*_t2193*_t2418 + (0.1e1 / 0.32e2)*_t1994*_t2429 - 0.3e1 / 0.128e3*_t2196*_t2430 - 0.3e1 / 0.1024e4*_t2321*_t2421 + (0.3e1 / 0.512e3)*_t2325*_t2430 + _t2330*_t2431*_t2432 + _t2417*_t2427*_t421 + (0.15e2 / 0.16e2)*_t2417*_t407 - _t2419*_t2428*_t861 + (0.15e2 / 0.128e3)*_t2422*_t854 + (0.3e1 / 0.128e3)*_t2423*_t854);
  const double d4F_dgbb4 = _t5*my_piecewise3(_t39, 0, (0.1e1 / 0.192e3)*_hc4[1]*_hc4[3]*_t2438 + (0.1e1 / 0.32e2)*_hc4[3]*_hc6[1]*_t1192*_t1960 - _hc4[3]*_hc7[0]*_t1198*_t2436 + (0.1e1 / 0.192e3)*_hc4[4]*_t2442*_t445 - 0.3e1 / 0.128e3*_hc6[1]*_t2304*_t2442 + _hc6[4]*_t1738*_t1965*_t2425*_t2440*_t56 + (0.5e1 / 0.256e3)*_t1122*_t2439 - _t1181*_t1186 + (0.1e1 / 0.16e2)*_t1183*_t1930*_t1932 - _t1191*_t2437 - 0.3e1 / 0.256e3*_t1195*_t2436 + _t1205*_t2437 - 0.15e2 / 0.16e2*_t121*_t2434 + _t1210*_t2405*_t2433*_t2440 - _t1211*_t2433*_t2436 - _t124*_t2434*_t2441 + (0.1e1 / 0.256e3)*_t1968*_t2438 + (0.3e1 / 0.128e3)*_t1968*_t2440*_t451 - 0.3e1 / 0.1024e4*_t2403*_t2438 + (0.3e1 / 0.256e3)*_t2405*_t2438 + (0.3e1 / 0.512e3)*_t2408*_t2442 + _t2409*_t2431*_t2440 - _t2428*_t2436*_t996 + _t2435*_t2441*_t447 + (0.15e2 / 0.16e2)*_t2435*_t434 + (0.15e2 / 0.128e3)*_t2439*_t991);
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
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif