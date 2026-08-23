/*
  Generated from python/gga_exc/gga_x_n12.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_n12
*/

#ifndef _GGA_X_N12_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_N12_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_N12_HELPER_BODIES
#include "gga_x_n12.c"
#undef _GGA_X_N12_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_N12_HELPER_BODIES
#include "gga_x_n12.c"
#undef _GGA_X_N12_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_N12_HELPER_BODIES
#include "gga_x_n12.c"
#undef _GGA_X_N12_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_N12_HELPER_BODIES
#include "gga_x_n12.c"
#undef _GGA_X_N12_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_N12_HELPER_BODIES
#include "gga_x_n12.c"
#undef _GGA_X_N12_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_n12.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_N12_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(b97_u_k, _KMAX)(const xc_func_type *p, double mgamma, double x2, double *out) {

  const double _t1 = mgamma*x2;
  const double _t2 = _t1 + 0.1e1;
  const double _t3 = (0.1e1 / _t2);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / (_t2 * _t2));
  const double _t5 = (mgamma * mgamma);
  const double _t6 = _t4*_t5;
  const double _t7 = (x2 * x2);
  const double _t8 = _t4*_t7;
#endif
#if _KMAX >= 2
  const double _t9 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t10 = 0.2e1*_t9;
  const double _t11 = (mgamma * mgamma * mgamma);
  const double _t12 = _t11*x2;
  const double _t13 = _t5*_t7;
  const double _t14 = (x2 * x2 * x2);
  const double _t15 = _t14*mgamma;
#endif
#if _KMAX >= 3
  const double _t16 = (mgamma * mgamma * mgamma * mgamma);
  const double _t17 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t18 = 0.6e1*_t17;
  const double _t19 = 0.4e1*_t4;
  const double _t20 = (x2 * x2 * x2 * x2);
#endif
#if _KMAX >= 4
  const double _t21 = 0.24e2*_t17;
  const double _t22 = 0.24e2/xc_powi(_t2, 5);
  const double _t23 = 0.18e2*_t9;
  const double _t24 = 0.42e2*_t17;
#endif

  const double f = _t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = _t3*mgamma - _t6*x2;
  out[1] = df_dx2;
  const double df_dmgamma = _t3*x2 - _t8*mgamma;
  out[2] = df_dmgamma;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = _t10*_t12 - 0.2e1*_t6;
  out[3] = d2f_dx22;
  const double d2f_dmgamma_dx2 = -0.3e1*_t1*_t4 + _t10*_t13 + _t3;
  out[4] = d2f_dmgamma_dx2;
  const double d2f_dmgamma2 = _t10*_t15 - 0.2e1*_t8;
  out[5] = d2f_dmgamma2;
#endif
#if _KMAX >= 3
  const double d3f_dx23 = 0.6e1*_t11*_t9 - _t16*_t18*x2;
  out[6] = d3f_dx23;
  const double d3f_dmgamma_dx22 = -_t11*_t18*_t7 - _t19*mgamma + 0.10e2*_t5*_t9*x2;
  out[7] = d3f_dmgamma_dx22;
  const double d3f_dmgamma2_dx2 = -_t14*_t18*_t5 - _t19*x2 + 0.10e2*_t7*_t9*mgamma;
  out[8] = d3f_dmgamma2_dx2;
  const double d3f_dmgamma3 = 0.6e1*_t14*_t9 - _t18*_t20*mgamma;
  out[9] = d3f_dmgamma3;
#endif
#if _KMAX >= 4
  const double d4f_dx24 = -_t16*_t21 + _t22*xc_powi(mgamma, 5)*x2;
  out[10] = d4f_dx24;
  const double d4f_dmgamma_dx23 = -_t12*_t24 + _t16*_t22*_t7 + _t23*_t5;
  out[11] = d4f_dmgamma_dx23;
  const double d4f_dmgamma2_dx22 = 0.28e2*_t1*_t9 + _t11*_t14*_t22 - 0.48e2*_t13*_t17 - _t19;
  out[12] = d4f_dmgamma2_dx22;
  const double d4f_dmgamma3_dx2 = -_t15*_t24 + _t20*_t22*_t5 + _t23*_t7;
  out[13] = d4f_dmgamma3_dx2;
  const double d4f_dmgamma4 = -_t20*_t21 + _t22*mgamma*xc_powi(x2, 5);
  out[14] = d4f_dmgamma4;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(n12_rss_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, -0.1e1 / 0.3e1, _hc0);
  const double _t1 = M_CBRT2;
  const double _t2 = _t1*(_hc0[0] + 0.1e1);
#if _KMAX >= 1
  const double _t3 = _hc0[2]*_t1;
#endif
#if _KMAX >= 2
  const double _t4 = _hc0[5]*_t1;
#endif
#if _KMAX >= 3
  const double _t5 = _hc0[9]*_t1;
#endif

  const double f = _t2*rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t3*rs;
  out[1] = df_dz;
  const double df_drs = _t2;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t4*rs;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _t3;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = 0;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t5*rs;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _t4;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = 0;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = 0;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc0[14]*_t1*rs;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _t5;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = 0;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = 0;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(n12_vx_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(0.6e1, 2, 3);
  const double _t2 = 0.13333333333333333*M_CBRTPI*_t1;
  const double _t3 = _t2*rs + 0.1e1;

  const double f = (0.1e1 / _t3);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t2/(_t3 * _t3);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.21333333333333332*xc_powr(0.6e1, 1, 3)*(M_CBRTPI * M_CBRTPI)/(_t3 * _t3 * _t3);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.51200000000000001*M_PI/(_t3 * _t3 * _t3 * _t3);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.27306666666666668*(M_PI * M_CBRTPI)*_t1/xc_powi(_t3, 5);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(n12_ux_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(b97_u_k, _KMAX)(p, 0.0040000000000000001, _t1, _hc0);
#if _KMAX >= 1
  const double _t2 = 0.2e1*_hc0[1];
#endif
#if _KMAX >= 3
  const double _t3 = 0.12e2*_hc0[3];
#endif

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t2*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 0.4e1*_hc0[3]*_t1 + _t2;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.8e1*_hc0[6]*(x * x * x) + _t3*x;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0.16e2*_hc0[10]*(x * x * x * x) + 0.48e2*_hc0[6]*_t1 + _t3;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(n12_FN12_k, _KMAX)(const xc_func_type *p, double rs, double z, double x, double *out) {
  const gga_x_n12_params *params = (const gga_x_n12_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(n12_ux_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(n12_rss_k, _KMAX)(p, rs, z, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(n12_vx_k, _KMAX)(p, _hc1[0], _hc2);
  const double _t1 = ((_hc0[0]) * (_hc0[0]));
  const double _t2 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t3 = _hc0[0]*params->CC[1][1] + _t1*params->CC[1][2] + _t2*params->CC[1][3] + params->CC[1][0];
  const double _t4 = ((_hc2[0]) * (_hc2[0]));
  const double _t5 = _hc0[0]*params->CC[2][1] + _t1*params->CC[2][2] + _t2*params->CC[2][3] + params->CC[2][0];
  const double _t6 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t7 = _hc0[0]*params->CC[3][1] + _t1*params->CC[3][2] + _t2*params->CC[3][3] + params->CC[3][0];
#if _KMAX >= 1
  const double _t8 = 0.2e1*_hc0[0];
  const double _t9 = _hc0[1]*_t8;
  const double _t10 = 0.3e1*_t1;
  const double _t11 = _hc0[1]*_t10;
  const double _t12 = _hc0[1]*params->CC[1][2];
  const double _t13 = _hc0[1]*params->CC[1][3];
  const double _t14 = _hc0[1]*params->CC[1][1] + _t10*_t13 + _t12*_t8;
  const double _t15 = _hc0[1]*params->CC[2][1] + _t11*params->CC[2][3] + _t9*params->CC[2][2];
  const double _t16 = _hc0[1]*params->CC[3][1] + _t11*params->CC[3][3] + _t9*params->CC[3][2];
  const double _t17 = _hc2[1]*_t3;
  const double _t18 = _hc1[1]*_hc2[1];
  const double _t19 = 0.2e1*_hc2[0];
  const double _t20 = _t19*_t5;
  const double _t21 = 0.3e1*_t4;
  const double _t22 = _t21*_t7;
  const double _t23 = _hc1[2]*_hc2[1];
#endif
#if _KMAX >= 2
  const double _t24 = _hc0[2]*_t8;
  const double _t25 = ((_hc0[1]) * (_hc0[1]));
  const double _t26 = 0.2e1*_t25;
  const double _t27 = 0.6e1*_t25;
  const double _t28 = _hc0[0]*_t27;
  const double _t29 = _hc0[2]*_t10;
  const double _t30 = _hc0[0]*params->CC[1][3];
  const double _t31 = _hc0[2]*params->CC[1][1] + _t24*params->CC[1][2] + _t26*params->CC[1][2] + _t27*_t30 + _t29*params->CC[1][3];
  const double _t32 = _hc0[2]*params->CC[2][1] + _t24*params->CC[2][2] + _t26*params->CC[2][2] + _t28*params->CC[2][3] + _t29*params->CC[2][3];
  const double _t33 = _hc0[2]*params->CC[3][1] + _t24*params->CC[3][2] + _t26*params->CC[3][2] + _t28*params->CC[3][3] + _t29*params->CC[3][3];
  const double _t34 = _hc2[1]*_t14;
  const double _t35 = _t15*_t19;
  const double _t36 = _t16*_t21;
  const double _t37 = ((_hc1[1]) * (_hc1[1]));
  const double _t38 = _hc2[2]*_t3;
  const double _t39 = _hc1[3]*_hc2[1];
  const double _t40 = _t37*_t5;
  const double _t41 = _hc2[2]*_t19;
  const double _t42 = ((_hc2[1]) * (_hc2[1]));
  const double _t43 = 0.2e1*_t42;
  const double _t44 = 0.6e1*_t42;
  const double _t45 = _hc2[0]*_t7;
  const double _t46 = _t37*_t45;
  const double _t47 = _hc2[2]*_t22;
  const double _t48 = _hc1[1]*_hc1[2];
  const double _t49 = _hc1[4]*_hc2[1];
  const double _t50 = _hc2[2]*_t48;
  const double _t51 = _t43*_t48;
  const double _t52 = _t44*_t48;
  const double _t53 = ((_hc1[2]) * (_hc1[2]));
  const double _t54 = _hc2[2]*_t53;
  const double _t55 = _t43*_t53;
  const double _t56 = _t44*_t53;
#endif
#if _KMAX >= 3
  const double _t57 = _hc0[3]*_t8;
  const double _t58 = 0.6e1*_hc0[2];
  const double _t59 = _hc0[1]*_t58;
  const double _t60 = 0.6e1*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t61 = 0.18e2*_hc0[2];
  const double _t62 = _hc0[0]*_hc0[1];
  const double _t63 = _t61*_t62;
  const double _t64 = _hc0[3]*_t10;
  const double _t65 = _hc0[0]*_t13;
  const double _t66 = _hc0[3]*params->CC[1][1] + _t12*_t58 + _t57*params->CC[1][2] + _t60*params->CC[1][3] + _t61*_t65 + _t64*params->CC[1][3];
  const double _t67 = _hc0[3]*params->CC[2][1] + _t57*params->CC[2][2] + _t59*params->CC[2][2] + _t60*params->CC[2][3] + _t63*params->CC[2][3] + _t64*params->CC[2][3];
  const double _t68 = _hc0[3]*params->CC[3][1] + _t57*params->CC[3][2] + _t59*params->CC[3][2] + _t60*params->CC[3][3] + _t63*params->CC[3][3] + _t64*params->CC[3][3];
  const double _t69 = _hc2[1]*_t31;
  const double _t70 = _t19*_t32;
  const double _t71 = _t21*_t33;
  const double _t72 = _hc2[2]*_t14;
  const double _t73 = _hc2[2]*_t37;
  const double _t74 = _t37*_t43;
  const double _t75 = _hc2[0]*_t16;
  const double _t76 = _t37*_t44;
  const double _t77 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t78 = _hc2[3]*_t3;
  const double _t79 = 0.3e1*_t38;
  const double _t80 = _hc1[1]*_hc1[3];
  const double _t81 = _hc1[6]*_hc2[1];
  const double _t82 = 0.6e1*_t5;
  const double _t83 = _hc2[2]*_t82;
  const double _t84 = _hc2[0]*_t83;
  const double _t85 = _t42*_t82;
  const double _t86 = _hc2[3]*_t20;
  const double _t87 = _hc2[1]*_t83;
  const double _t88 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t89 = 0.6e1*_t88;
  const double _t90 = _t7*_t77;
  const double _t91 = 0.18e2*_t45;
  const double _t92 = _t42*_t91;
  const double _t93 = _hc2[2]*_t7;
  const double _t94 = 0.9e1*_t4;
  const double _t95 = _t93*_t94;
  const double _t96 = 0.18e2*_t90;
  const double _t97 = _hc2[0]*_hc2[2];
  const double _t98 = _hc2[1]*_t97;
  const double _t99 = _hc2[3]*_t21;
  const double _t100 = _hc1[2]*_hc1[3];
  const double _t101 = 0.2e1*_t38;
  const double _t102 = _hc1[1]*_hc1[4];
  const double _t103 = _hc1[7]*_hc2[1];
  const double _t104 = _hc1[2]*_t37;
  const double _t105 = 0.4e1*_t102;
  const double _t106 = _t5*_t97;
  const double _t107 = _hc2[2]*_t100;
  const double _t108 = _t42*_t5;
  const double _t109 = 0.4e1*_t108;
  const double _t110 = _t100*_t43;
  const double _t111 = _t42*_t45;
  const double _t112 = 0.12e2*_t111;
  const double _t113 = 0.6e1*_hc2[2];
  const double _t114 = _t4*_t7;
  const double _t115 = _t113*_t114;
  const double _t116 = _hc2[3]*_t40;
  const double _t117 = _t100*_t44;
  const double _t118 = _t7*_t89;
  const double _t119 = _hc2[1]*_hc2[2];
  const double _t120 = _t119*_t91;
  const double _t121 = _hc2[3]*_t22;
  const double _t122 = _hc1[2]*_t38;
  const double _t123 = 0.2e1*_hc1[4];
  const double _t124 = _hc1[1]*_t53;
  const double _t125 = _hc1[2]*_hc1[4];
  const double _t126 = 0.4e1*_t125;
  const double _t127 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t128 = _t127*_t89;
  const double _t129 = _t119*_t127;
  const double _t130 = _hc2[3]*_t127;
#endif
#if _KMAX >= 4
  const double _t131 = _hc0[4]*_t8;
  const double _t132 = 0.8e1*_hc0[3];
  const double _t133 = _hc0[1]*_t132;
  const double _t134 = ((_hc0[2]) * (_hc0[2]));
  const double _t135 = 0.6e1*_t134;
  const double _t136 = 0.24e2*_hc0[3];
  const double _t137 = _t136*_t62;
  const double _t138 = 0.18e2*_t134;
  const double _t139 = _hc0[0]*_t138;
  const double _t140 = _hc0[4]*_t10;
  const double _t141 = 0.36e2*_hc0[2]*_t25;
  const double _t142 = _hc2[1]*_t66;
  const double _t143 = _t19*_t67;
  const double _t144 = _t21*_t68;
  const double _t145 = _hc2[2]*_t31;
  const double _t146 = _t32*_t41;
  const double _t147 = _hc2[0]*_t33;
  const double _t148 = _hc2[3]*_t14;
  const double _t149 = _t15*_t80;
  const double _t150 = _hc2[3]*_t35;
  const double _t151 = _hc2[1]*_t113*_t15;
  const double _t152 = _t16*_t77;
  const double _t153 = _t42*_t75;
  const double _t154 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t155 = _hc2[4]*_t3;
  const double _t156 = _hc1[1]*_hc1[6];
  const double _t157 = _hc1[10]*_hc2[1];
  const double _t158 = ((_hc1[3]) * (_hc1[3]));
  const double _t159 = 0.8e1*_t156;
  const double _t160 = _hc1[3]*_t78;
  const double _t161 = _hc2[4]*_t154;
  const double _t162 = _hc2[1]*_hc2[3];
  const double _t163 = _t154*_t162;
  const double _t164 = 0.8e1*_t5;
  const double _t165 = ((_hc2[2]) * (_hc2[2]));
  const double _t166 = _t154*_t165;
  const double _t167 = _hc1[3]*_hc2[0];
  const double _t168 = _hc2[2]*_t40;
  const double _t169 = 0.24e2*_t45;
  const double _t170 = _t7*_t88;
  const double _t171 = _t170*_t37;
  const double _t172 = 0.36e2*_t42;
  const double _t173 = _t172*_t93;
  const double _t174 = _hc2[2]*_t46;
  const double _t175 = 0.18e2*_hc1[3];
  const double _t176 = _hc2[3]*_t114;
  const double _t177 = _t15*_t97;
  const double _t178 = _t15*_t42;
  const double _t179 = 0.12e2*_t153;
  const double _t180 = _t113*_t16*_t4;
  const double _t181 = _t16*_t89;
  const double _t182 = 0.18e2*_t75;
  const double _t183 = _t119*_t182;
  const double _t184 = _hc2[3]*_t36;
  const double _t185 = _hc1[1]*_hc1[7];
  const double _t186 = _hc1[11]*_hc2[1];
  const double _t187 = _hc1[3]*_hc1[4];
  const double _t188 = _hc1[2]*_t77;
  const double _t189 = _hc1[2]*_hc1[6];
  const double _t190 = _hc1[4]*_t37;
  const double _t191 = 0.3e1*_t78;
  const double _t192 = _t5*_t50;
  const double _t193 = _t170*_t48;
  const double _t194 = 0.6e1*_t40;
  const double _t195 = _hc2[0]*_hc2[3];
  const double _t196 = _hc1[4]*_t195;
  const double _t197 = 0.18e2*_t49;
  const double _t198 = _hc2[4]*_t20;
  const double _t199 = _t162*_t164;
  const double _t200 = _t45*_t50;
  const double _t201 = 0.18e2*_hc1[4];
  const double _t202 = _t165*_t82;
  const double _t203 = _hc2[3]*_t7*_t94;
  const double _t204 = 0.54e2*_t49;
  const double _t205 = _hc1[2]*_t90;
  const double _t206 = ((_hc1[4]) * (_hc1[4]));
  const double _t207 = _hc1[4]*_t48;
  const double _t208 = _hc1[2]*_hc1[7];
  const double _t209 = 0.4e1*_t106;
  const double _t210 = _t37*_t53;
  const double _t211 = _hc1[3]*_t53;
  const double _t212 = _t39*_t54;
  const double _t213 = _t40*_t53;
  const double _t214 = _t162*_t169;
  const double _t215 = _t165*_t91;
  const double _t216 = _hc2[4]*_t22;
  const double _t217 = _hc1[1]*_t127;
  const double _t218 = _hc1[4]*_t53;
  const double _t219 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t220 = _hc2[4]*_t219;
#endif

  const double f = _hc0[0]*params->CC[0][1] + _hc2[0]*_t3 + _t1*params->CC[0][2] + _t2*params->CC[0][3] + _t4*_t5 + _t6*_t7 + params->CC[0][0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _hc0[1]*params->CC[0][1] + _hc2[0]*_t14 + _t11*params->CC[0][3] + _t15*_t4 + _t16*_t6 + _t9*params->CC[0][2];
  out[1] = df_dx;
  const double df_dz = _hc1[1]*_t17 + _t18*_t20 + _t18*_t22;
  out[2] = df_dz;
  const double df_drs = _hc1[2]*_t17 + _t20*_t23 + _t22*_t23;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _hc0[2]*params->CC[0][1] + _hc2[0]*_t31 + _t24*params->CC[0][2] + _t26*params->CC[0][2] + _t28*params->CC[0][3] + _t29*params->CC[0][3] + _t32*_t4 + _t33*_t6;
  out[4] = d2f_dx2;
  const double d2f_dz_dx = _hc1[1]*_t34 + _t18*_t35 + _t18*_t36;
  out[5] = d2f_dz_dx;
  const double d2f_dz2 = _hc1[3]*_t17 + _t20*_t39 + _t22*_t39 + _t37*_t38 + _t37*_t47 + _t40*_t41 + _t40*_t43 + _t44*_t46;
  out[6] = d2f_dz2;
  const double d2f_drs_dx = _hc1[2]*_t34 + _t23*_t35 + _t23*_t36;
  out[7] = d2f_drs_dx;
  const double d2f_drs_dz = _hc1[4]*_t17 + _t20*_t49 + _t20*_t50 + _t22*_t49 + _t38*_t48 + _t45*_t52 + _t47*_t48 + _t5*_t51;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _t20*_t54 + _t38*_t53 + _t45*_t56 + _t47*_t53 + _t5*_t55;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _hc0[3]*params->CC[0][1] + _hc2[0]*_t66 + _t4*_t67 + _t57*params->CC[0][2] + _t59*params->CC[0][2] + _t6*_t68 + _t60*params->CC[0][3] + _t63*params->CC[0][3] + _t64*params->CC[0][3];
  out[10] = d3f_dx3;
  const double d3f_dz_dx2 = _hc1[1]*_t69 + _t18*_t70 + _t18*_t71;
  out[11] = d3f_dz_dx2;
  const double d3f_dz2_dx = _hc1[3]*_t34 + _t15*_t74 + _t35*_t39 + _t35*_t73 + _t36*_t39 + _t36*_t73 + _t37*_t72 + _t75*_t76;
  out[12] = d3f_dz2_dx;
  const double d3f_dz3 = _hc1[6]*_t17 + _t20*_t81 + _t22*_t81 + _t77*_t78 + _t77*_t86 + _t77*_t87 + _t79*_t80 + _t80*_t84 + _t80*_t85 + _t80*_t92 + _t80*_t95 + _t89*_t90 + _t90*_t99 + _t96*_t98;
  out[13] = d3f_dz3;
  const double d3f_drs_dx2 = _hc1[2]*_t69 + _t23*_t70 + _t23*_t71;
  out[14] = d3f_drs_dx2;
  const double d3f_drs_dz_dx = _hc1[4]*_t34 + _t15*_t51 + _t35*_t49 + _t35*_t50 + _t36*_t49 + _t36*_t50 + _t48*_t72 + _t52*_t75;
  out[15] = d3f_drs_dz_dx;
  const double d3f_drs_dz2 = _hc1[2]*_t116*_t19 + _hc1[7]*_t17 + _t100*_t38 + _t100*_t47 + _t101*_t102 + _t102*_t109 + _t102*_t112 + _t102*_t115 + _t103*_t20 + _t103*_t22 + _t104*_t118 + _t104*_t120 + _t104*_t121 + _t104*_t78 + _t105*_t106 + _t107*_t20 + _t110*_t5 + _t113*_t23*_t40 + _t117*_t45;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dx = _t15*_t55 + _t35*_t54 + _t36*_t54 + _t53*_t72 + _t56*_t75;
  out[17] = d3f_drs2_dx;
  const double d3f_drs2_dz = _t106*_t126 + _t109*_t125 + _t112*_t125 + _t115*_t125 + _t118*_t124 + _t120*_t124 + _t121*_t124 + _t122*_t123 + _t124*_t78 + _t124*_t86 + _t124*_t87;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = _t127*_t78 + _t127*_t86 + _t127*_t87 + _t128*_t7 + _t129*_t91 + _t130*_t22;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _hc0[4]*params->CC[0][1] + _hc2[0]*(_hc0[4]*params->CC[1][1] + _t12*_t132 + _t131*params->CC[1][2] + _t135*params->CC[1][2] + _t136*_t65 + _t138*_t30 + _t140*params->CC[1][3] + _t141*params->CC[1][3]) + _t131*params->CC[0][2] + _t133*params->CC[0][2] + _t135*params->CC[0][2] + _t137*params->CC[0][3] + _t139*params->CC[0][3] + _t140*params->CC[0][3] + _t141*params->CC[0][3] + _t4*(_hc0[4]*params->CC[2][1] + _t131*params->CC[2][2] + _t133*params->CC[2][2] + _t135*params->CC[2][2] + _t137*params->CC[2][3] + _t139*params->CC[2][3] + _t140*params->CC[2][3] + _t141*params->CC[2][3]) + _t6*(_hc0[4]*params->CC[3][1] + _t131*params->CC[3][2] + _t133*params->CC[3][2] + _t135*params->CC[3][2] + _t137*params->CC[3][3] + _t139*params->CC[3][3] + _t140*params->CC[3][3] + _t141*params->CC[3][3]);
  out[20] = d4f_dx4;
  const double d4f_dz_dx3 = _hc1[1]*_t142 + _t143*_t18 + _t144*_t18;
  out[21] = d4f_dz_dx3;
  const double d4f_dz2_dx2 = _hc1[3]*_t69 + _t145*_t37 + _t146*_t37 + _t147*_t76 + _t32*_t74 + _t39*_t70 + _t39*_t71 + _t71*_t73;
  out[22] = d4f_dz2_dx2;
  const double d4f_dz3_dx = _hc1[6]*_t34 + _hc2[0]*_t113*_t149 + _hc2[2]*_t16*_t80*_t94 + _t148*_t77 + _t149*_t44 + _t150*_t77 + _t151*_t77 + _t152*_t89 + 0.18e2*_t152*_t98 + _t152*_t99 + 0.18e2*_t153*_t80 + _t35*_t81 + _t36*_t81 + 0.3e1*_t72*_t80;
  out[23] = d4f_dz3_dx;
  const double d4f_dz4 = _hc1[10]*_t17 + 0.36e2*_hc1[3]*_t171 + _t106*_t159 + _t108*_t159 + 0.24e2*_t111*_t156 + 0.12e2*_t116*_t167 + _t154*_t155 + _t154*_t173 + 0.4e1*_t156*_t38 + 0.12e2*_t156*_t4*_t93 + _t157*_t20 + _t157*_t22 + _t158*_t79 + _t158*_t84 + _t158*_t85 + _t158*_t92 + _t158*_t95 + 0.6e1*_t160*_t37 + _t161*_t20 + _t161*_t22 + _t163*_t164 + _t163*_t169 + _t166*_t82 + _t166*_t91 + 0.36e2*_t168*_t39 + 0.108e3*_t174*_t39 + _t175*_t176*_t37;
  out[24] = d4f_dz4;
  const double d4f_drs_dx3 = _hc1[2]*_t142 + _t143*_t23 + _t144*_t23;
  out[25] = d4f_drs_dx3;
  const double d4f_drs_dz_dx2 = _hc1[4]*_t69 + _t145*_t48 + _t146*_t48 + _t147*_t52 + _t32*_t51 + _t49*_t70 + _t49*_t71 + _t50*_t71;
  out[26] = d4f_drs_dz_dx2;
  const double d4f_drs_dz2_dx = _hc1[7]*_t34 + _t100*_t72 + _t102*_t179 + _t102*_t180 + 0.2e1*_t102*_t72 + _t103*_t35 + _t103*_t36 + _t104*_t148 + _t104*_t150 + _t104*_t151 + _t104*_t181 + _t104*_t183 + _t104*_t184 + _t105*_t177 + _t105*_t178 + _t107*_t35 + _t107*_t36 + _t110*_t15 + _t117*_t75;
  out[27] = d4f_drs_dz2_dx;
  const double d4f_drs_dz3 = _hc1[11]*_t17 + _hc1[2]*_hc2[0]*_t165*_t96 + _hc1[3]*_t203*_t48 + _hc1[6]*_t122 + _hc2[2]*_t172*_t205 + _hc2[2]*_t189*_t20 + _hc2[3]*_t167*_t48*_t82 + _hc2[4]*_t205*_t21 + _t155*_t188 + 0.3e1*_t160*_t48 + _t168*_t197 + _t171*_t201 + _t174*_t204 + _t175*_t193 + _t185*_t79 + _t185*_t84 + _t185*_t85 + _t185*_t92 + _t185*_t95 + _t186*_t20 + _t186*_t22 + _t187*_t79 + _t187*_t84 + _t187*_t85 + _t187*_t92 + _t187*_t95 + _t188*_t198 + _t188*_t199 + _t188*_t202 + _t189*_t43*_t5 + _t189*_t44*_t45 + _t189*_t47 + _t190*_t191 + _t190*_t203 + 0.18e2*_t192*_t39 + _t194*_t196 + 0.24e2*_t195*_t23*_t90 + 0.54e2*_t200*_t39;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dx2 = _t145*_t53 + _t146*_t53 + _t147*_t56 + _t32*_t55 + _t54*_t71;
  out[29] = d4f_drs2_dx2;
  const double d4f_drs2_dz_dx = _hc1[2]*_t123*_t72 + _t124*_t148 + _t124*_t150 + _t124*_t151 + _t124*_t181 + _t124*_t183 + _t124*_t184 + _t125*_t179 + _t125*_t180 + _t126*_t177 + _t126*_t178;
  out[30] = d4f_drs2_dz_dx;
  const double d4f_drs2_dz2 = 0.24e2*_hc1[4]*_t193 + 0.2e1*_hc1[7]*_t122 + _hc2[4]*_t19*_t213 + _t101*_t206 + _t109*_t206 + _t109*_t208 + _t112*_t206 + _t112*_t208 + _t115*_t206 + _t115*_t208 + _t118*_t211 + _t121*_t211 + _t155*_t210 + _t160*_t53 + 0.8e1*_t162*_t213 + _t164*_t196*_t48 + _t165*_t194*_t53 + _t173*_t210 + 0.12e2*_t176*_t207 + 0.24e2*_t192*_t49 + 0.72e2*_t200*_t49 + _t206*_t209 + 0.4e1*_t207*_t78 + _t208*_t209 + _t210*_t214 + _t210*_t215 + _t210*_t216 + _t211*_t86 + _t212*_t82 + _t212*_t91;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dx = _t127*_t148 + _t127*_t151 + _t128*_t16 + _t129*_t182 + _t130*_t35 + _t130*_t36;
  out[32] = d4f_drs3_dx;
  const double d4f_drs3_dz = _t155*_t217 + _t170*_t201*_t53 + _t173*_t217 + _t191*_t218 + _t195*_t218*_t82 + _t197*_t5*_t54 + _t198*_t217 + _t199*_t217 + _t202*_t217 + _t203*_t218 + _t204*_t45*_t54 + _t214*_t217 + _t215*_t217 + _t216*_t217;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = _t155*_t219 + _t173*_t219 + _t199*_t219 + _t20*_t220 + _t202*_t219 + _t214*_t219 + _t215*_t219 + _t22*_t220;
  out[34] = d4f_drs4;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(n12_rss_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = M_CBRT2;

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(n12_FN12_z0_k, _KMAX)(const xc_func_type *p, double rs, double x, double *out) {
  const gga_x_n12_params *params = (const gga_x_n12_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(n12_ux_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(n12_rss_z0_k, _KMAX)(p, rs, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(n12_vx_k, _KMAX)(p, _hc1[0], _hc2);
  const double _t1 = ((_hc0[0]) * (_hc0[0]));
  const double _t2 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t3 = _hc0[0]*params->CC[1][1] + _t1*params->CC[1][2] + _t2*params->CC[1][3] + params->CC[1][0];
  const double _t4 = ((_hc2[0]) * (_hc2[0]));
  const double _t5 = _hc0[0]*params->CC[2][1] + _t1*params->CC[2][2] + _t2*params->CC[2][3] + params->CC[2][0];
  const double _t6 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t7 = _hc0[0]*params->CC[3][1] + _t1*params->CC[3][2] + _t2*params->CC[3][3] + params->CC[3][0];
#if _KMAX >= 1
  const double _t8 = 0.2e1*_hc0[0];
  const double _t9 = _hc0[1]*_t8;
  const double _t10 = 0.3e1*_t1;
  const double _t11 = _hc0[1]*_t10;
  const double _t12 = _hc0[1]*params->CC[1][2];
  const double _t13 = _hc0[1]*params->CC[1][3];
  const double _t14 = _hc0[1]*params->CC[1][1] + _t10*_t13 + _t12*_t8;
  const double _t15 = _hc0[1]*params->CC[2][1] + _t11*params->CC[2][3] + _t9*params->CC[2][2];
  const double _t16 = _hc0[1]*params->CC[3][1] + _t11*params->CC[3][3] + _t9*params->CC[3][2];
  const double _t17 = _hc1[1]*_hc2[1];
  const double _t18 = 0.2e1*_t5;
  const double _t19 = _hc2[0]*_t17;
  const double _t20 = 0.3e1*_t4;
  const double _t21 = _t17*_t20;
#endif
#if _KMAX >= 2
  const double _t22 = _hc0[2]*_t8;
  const double _t23 = ((_hc0[1]) * (_hc0[1]));
  const double _t24 = 0.2e1*_t23;
  const double _t25 = 0.6e1*_t23;
  const double _t26 = _hc0[0]*_t25;
  const double _t27 = _hc0[2]*_t10;
  const double _t28 = _hc0[0]*params->CC[1][3];
  const double _t29 = _hc0[2]*params->CC[1][1] + _t22*params->CC[1][2] + _t24*params->CC[1][2] + _t25*_t28 + _t27*params->CC[1][3];
  const double _t30 = _hc0[2]*params->CC[2][1] + _t22*params->CC[2][2] + _t24*params->CC[2][2] + _t26*params->CC[2][3] + _t27*params->CC[2][3];
  const double _t31 = _hc0[2]*params->CC[3][1] + _t22*params->CC[3][2] + _t24*params->CC[3][2] + _t26*params->CC[3][3] + _t27*params->CC[3][3];
  const double _t32 = 0.2e1*_t19;
  const double _t33 = ((_hc1[1]) * (_hc1[1]));
  const double _t34 = _hc2[2]*_t33;
  const double _t35 = _hc2[0]*_t34;
  const double _t36 = ((_hc2[1]) * (_hc2[1]));
  const double _t37 = _t33*_t36;
  const double _t38 = 0.6e1*_t7;
  const double _t39 = _hc2[0]*_t37;
  const double _t40 = _t20*_t34;
#endif
#if _KMAX >= 3
  const double _t41 = _hc0[3]*_t8;
  const double _t42 = 0.6e1*_hc0[2];
  const double _t43 = _hc0[1]*_t42;
  const double _t44 = 0.6e1*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t45 = 0.18e2*_hc0[2];
  const double _t46 = _hc0[0]*_hc0[1];
  const double _t47 = _t45*_t46;
  const double _t48 = _hc0[3]*_t10;
  const double _t49 = _hc0[0]*_t13;
  const double _t50 = _hc0[3]*params->CC[1][1] + _t12*_t42 + _t41*params->CC[1][2] + _t44*params->CC[1][3] + _t45*_t49 + _t48*params->CC[1][3];
  const double _t51 = _hc0[3]*params->CC[2][1] + _t41*params->CC[2][2] + _t43*params->CC[2][2] + _t44*params->CC[2][3] + _t47*params->CC[2][3] + _t48*params->CC[2][3];
  const double _t52 = _hc0[3]*params->CC[3][1] + _t41*params->CC[3][2] + _t43*params->CC[3][2] + _t44*params->CC[3][3] + _t47*params->CC[3][3] + _t48*params->CC[3][3];
  const double _t53 = 0.2e1*_t35;
  const double _t54 = 0.2e1*_t37;
  const double _t55 = 0.6e1*_t16;
  const double _t56 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t57 = _hc2[3]*_t56;
  const double _t58 = _hc2[0]*_t57;
  const double _t59 = 0.6e1*_t5;
  const double _t60 = _hc2[1]*_hc2[2]*_t56;
  const double _t61 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t56;
  const double _t62 = 0.18e2*_hc2[0];
  const double _t63 = _t62*_t7;
  const double _t64 = _t20*_t57;
#endif
#if _KMAX >= 4
  const double _t65 = _hc0[4]*_t8;
  const double _t66 = 0.8e1*_hc0[3];
  const double _t67 = _hc0[1]*_t66;
  const double _t68 = ((_hc0[2]) * (_hc0[2]));
  const double _t69 = 0.6e1*_t68;
  const double _t70 = 0.24e2*_hc0[3];
  const double _t71 = _t46*_t70;
  const double _t72 = 0.18e2*_t68;
  const double _t73 = _hc0[0]*_t72;
  const double _t74 = _hc0[4]*_t10;
  const double _t75 = 0.36e2*_hc0[2]*_t23;
  const double _t76 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t77 = _hc2[4]*_t76;
  const double _t78 = _hc2[1]*_hc2[3]*_t76;
  const double _t79 = ((_hc2[2]) * (_hc2[2]))*_t76;
#endif

  const double f = _hc0[0]*params->CC[0][1] + _hc2[0]*_t3 + _t1*params->CC[0][2] + _t2*params->CC[0][3] + _t4*_t5 + _t6*_t7 + params->CC[0][0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _hc0[1]*params->CC[0][1] + _hc2[0]*_t14 + _t11*params->CC[0][3] + _t15*_t4 + _t16*_t6 + _t9*params->CC[0][2];
  out[1] = df_dx;
  const double df_drs = _t17*_t3 + _t18*_t19 + _t21*_t7;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _hc0[2]*params->CC[0][1] + _hc2[0]*_t29 + _t22*params->CC[0][2] + _t24*params->CC[0][2] + _t26*params->CC[0][3] + _t27*params->CC[0][3] + _t30*_t4 + _t31*_t6;
  out[3] = d2f_dx2;
  const double d2f_drs_dx = _t14*_t17 + _t15*_t32 + _t16*_t21;
  out[4] = d2f_drs_dx;
  const double d2f_drs2 = _t18*_t35 + _t18*_t37 + _t3*_t34 + _t38*_t39 + _t40*_t7;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _hc0[3]*params->CC[0][1] + _hc2[0]*_t50 + _t4*_t51 + _t41*params->CC[0][2] + _t43*params->CC[0][2] + _t44*params->CC[0][3] + _t47*params->CC[0][3] + _t48*params->CC[0][3] + _t52*_t6;
  out[6] = d3f_dx3;
  const double d3f_drs_dx2 = _t17*_t29 + _t21*_t31 + _t30*_t32;
  out[7] = d3f_drs_dx2;
  const double d3f_drs2_dx = _t14*_t34 + _t15*_t53 + _t15*_t54 + _t16*_t40 + _t39*_t55;
  out[8] = d3f_drs2_dx;
  const double d3f_drs3 = _t18*_t58 + _t3*_t57 + _t38*_t61 + _t59*_t60 + _t60*_t63 + _t64*_t7;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _hc0[4]*params->CC[0][1] + _hc2[0]*(_hc0[4]*params->CC[1][1] + _t12*_t66 + _t28*_t72 + _t49*_t70 + _t65*params->CC[1][2] + _t69*params->CC[1][2] + _t74*params->CC[1][3] + _t75*params->CC[1][3]) + _t4*(_hc0[4]*params->CC[2][1] + _t65*params->CC[2][2] + _t67*params->CC[2][2] + _t69*params->CC[2][2] + _t71*params->CC[2][3] + _t73*params->CC[2][3] + _t74*params->CC[2][3] + _t75*params->CC[2][3]) + _t6*(_hc0[4]*params->CC[3][1] + _t65*params->CC[3][2] + _t67*params->CC[3][2] + _t69*params->CC[3][2] + _t71*params->CC[3][3] + _t73*params->CC[3][3] + _t74*params->CC[3][3] + _t75*params->CC[3][3]) + _t65*params->CC[0][2] + _t67*params->CC[0][2] + _t69*params->CC[0][2] + _t71*params->CC[0][3] + _t73*params->CC[0][3] + _t74*params->CC[0][3] + _t75*params->CC[0][3];
  out[10] = d4f_dx4;
  const double d4f_drs_dx3 = _t17*_t50 + _t21*_t52 + _t32*_t51;
  out[11] = d4f_drs_dx3;
  const double d4f_drs2_dx2 = _t29*_t34 + _t30*_t53 + _t30*_t54 + 0.6e1*_t31*_t39 + _t31*_t40;
  out[12] = d4f_drs2_dx2;
  const double d4f_drs3_dx = _t14*_t57 + 0.2e1*_t15*_t58 + 0.6e1*_t15*_t60 + _t16*_t60*_t62 + _t16*_t64 + _t55*_t61;
  out[13] = d4f_drs3_dx;
  const double d4f_drs4 = _hc2[0]*_t18*_t77 + 0.24e2*_hc2[0]*_t7*_t78 + 0.36e2*_hc2[2]*_t36*_t7*_t76 + _t20*_t7*_t77 + _t3*_t77 + 0.8e1*_t5*_t78 + _t59*_t79 + _t63*_t79;
  out[14] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_n12_params *params = (const gga_x_n12_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = _t4/xc_powr(na, 1, 3);
  const double _t6 = xc_powr(na, -4, 3);
  const double _t7 = M_CBRT2;
  const double _t8 = xc_powr(gaa, 1, 2);
  const double _t9 = _t7*_t8;
  const double _t10 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_spin_z0_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t10)) XC_CAT(n12_FN12_z0_k, _KMAX)(p, _t5, _t6*_t9, _hc1);
  const double _t11 = 0.2e1*my_piecewise3(_t10, 0, _hc0[0]*_hc1[0]);
  const double zk = _t11;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t12 = (0.1e1 / 0.6e1)*_t6;
  const double _t13 = _t12*_t3;
  const double _t16 = xc_powr(na, -7, 3);
  const double _t17 = (0.4e1 / 0.3e1)*_t16;
  const double _t21 = 0.2e1*na;
  const double _t22 = (0.1e1 / _t8);
  const double _t23 = _t22*_t7;
  const double _t14 = _hc0[1]*_hc1[0];
  const double _t15 = _hc1[1]*_t9;
  const double _t18 = _hc1[2]*_t3;
  const double _t19 = -_t12*_t18 - _t15*_t17;
  const double _t20 = my_piecewise3(_t10, 0, _hc0[0]*_t19 - _t13*_t14);
  const double _t24 = _hc1[1]*_t23;
  const double _t25 = _hc0[0]*_t6;
  const double _t26 = 0.2e1*my_piecewise3(_t10, 0, (0.1e1 / 0.2e1)*_t24*_t25);
  const double dF_dna = _t11 + _t20*_t21;
  const double dF_dgaa = _t26*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t27 = (0.2e1 / 0.9e1)*_t16;
  const double _t28 = _t27*_t3;
  const double _t30 = xc_powr(na, -8, 3);
  const double _t31 = xc_powr(0.6e1, 2, 3);
  const double _t32 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t39 = xc_powr(na, -10, 3);
  const double _t40 = (0.28e2 / 0.9e1)*_t39;
  const double _t41 = _t17*_t9;
  const double _t46 = xc_powr(0.12e2, 1, 3);
  const double _t47 = _t22*_t46;
  const double _t48 = (0.1e1 / 0.12e2)*_t2;
  const double _t49 = _t30*_t48;
  const double _t50 = _t47*_t49;
  const double _t52 = xc_powr(0.2e1, 2, 3);
  const double _t54 = xc_powr(na, -11, 3);
  const double _t55 = (0.2e1 / 0.3e1)*_t54;
  const double _t56 = (0.2e1 / 0.3e1)*_t16;
  const double _t61 = xc_powr(gaa, -3, 2);
  const double _t64 = (0.1e1 / gaa);
  const double _t29 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t33 = _hc0[2]*_t32;
  const double _t34 = _t31*_t33;
  const double _t35 = _t30*_t34;
  const double _t36 = _t19*_t3;
  const double _t37 = _hc0[1]*_t6;
  const double _t38 = (0.1e1 / 0.3e1)*_t37;
  const double _t42 = -_hc1[3]*_t41 - _hc1[4]*_t13;
  const double _t43 = -_hc1[4]*_t41 - _hc1[5]*_t13;
  const double _t44 = -_t13*_t43 + _t15*_t40 + _t18*_t27 - _t41*_t42;
  const double _t45 = my_piecewise3(_t10, 0, _hc0[0]*_t44 + _t14*_t28 + _t29*_t35 - _t36*_t38);
  const double _t51 = _hc0[1]*_hc1[1];
  const double _t53 = _hc1[3]*_t52;
  const double _t57 = _hc1[4]*_t47;
  const double _t58 = -_t24*_t56 - _t49*_t57 - _t53*_t55;
  const double _t59 = my_piecewise3(_t10, 0, _hc0[0]*_t58 - _t50*_t51);
  const double _t60 = (0.1e1 / 0.4e1)*_hc0[0];
  const double _t62 = _hc1[1]*_t61;
  const double _t63 = _t62*_t7;
  const double _t65 = 0.2e1*my_piecewise3(_t10, 0, (0.1e1 / 0.4e1)*_hc0[0]*_hc1[3]*_t30*_t52*_t64 - _t6*_t60*_t63);
  const double d2F_dna2 = 0.4e1*_t20 + _t21*_t45;
  const double d2F_dna_dgaa = _t21*_t59 + _t26;
  const double d2F_dgaa2 = _t65*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t66 = (0.1e1 / (na * na * na * na));
  const double _t69 = (0.14e2 / 0.27e2)*_t39;
  const double _t70 = _t3*_t69;
  const double _t71 = (0.1e1 / 0.9e1)*_t54;
  const double _t74 = xc_powr(na, -13, 3);
  const double _t75 = (0.280e3 / 0.27e2)*_t74;
  const double _t76 = _t40*_t9;
  const double _t84 = _t2*_t71;
  const double _t85 = _t47*_t84;
  const double _t90 = xc_powr(na, -14, 3);
  const double _t91 = (0.14e2 / 0.9e1)*_t90;
  const double _t92 = (0.14e2 / 0.9e1)*_t39;
  const double _t93 = _t23*_t56;
  const double _t94 = _t52*_t55;
  const double _t99 = _t2*_t46;
  const double _t100 = _t30*_t99;
  const double _t102 = M_CBRT3;
  const double _t103 = _t102*_t64;
  const double _t104 = _t48*_t66;
  const double _t105 = _t103*_t104;
  const double _t108 = xc_powi(na, -5);
  const double _t109 = (0.2e1 / 0.3e1)*_t108;
  const double _t110 = (0.1e1 / 0.3e1)*_t54;
  const double _t114 = xc_powr(gaa, -5, 2);
  const double _t117 = (0.1e1 / (gaa * gaa));
  const double _t67 = _hc0[3]/M_PI;
  const double _t68 = _t66*_t67;
  const double _t72 = _hc1[0]*_t34;
  const double _t73 = _t37*_t4;
  const double _t77 = -_hc1[6]*_t41 - _hc1[7]*_t13;
  const double _t78 = -_hc1[7]*_t41 - _hc1[8]*_t13;
  const double _t79 = _hc1[3]*_t76 + _hc1[4]*_t28 - _t13*_t78 - _t41*_t77;
  const double _t80 = -_hc1[8]*_t41 - _hc1[9]*_t13;
  const double _t81 = _hc1[4]*_t76 + _hc1[5]*_t28 - _t13*_t80 - _t41*_t78;
  const double _t82 = (0.4e1 / 0.9e1)*_t1*_t16*_t2*_t43 - _t13*_t81 - _t15*_t75 - _t18*_t69 + (0.56e2 / 0.9e1)*_t39*_t42*_t7*_t8 - _t41*_t79;
  const double _t83 = my_piecewise3(_t10, 0, _hc0[0]*_t82 + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t16*_t19*_t2 + (0.1e1 / 0.12e2)*_hc0[2]*_t19*_t30*_t31*_t32 - _t14*_t70 - _t29*_t68 - _t44*_t73 - _t71*_t72);
  const double _t86 = xc_powr(0.3e1, 2, 3)*_t33;
  const double _t87 = _t66*_t86;
  const double _t88 = _hc1[1]*_t22;
  const double _t89 = _t3*_t38;
  const double _t95 = -_hc1[3]*_t93 - _hc1[6]*_t94 - _hc1[7]*_t50;
  const double _t96 = -_hc1[4]*_t93 - _hc1[7]*_t94 - _hc1[8]*_t50;
  const double _t97 = -_t13*_t96 + _t24*_t92 - _t41*_t95 - _t42*_t93 + _t53*_t91 + _t57*_t84;
  const double _t98 = my_piecewise3(_t10, 0, _hc0[0]*_t97 + _t51*_t85 - _t58*_t89 + (0.1e1 / 0.36e2)*_t87*_t88);
  const double _t101 = _hc0[1]*_t62;
  const double _t106 = _hc0[1]*_hc1[3];
  const double _t107 = _hc1[6]*_t22;
  const double _t111 = (0.1e1 / 0.3e1)*_hc1[1]*_t16*_t61*_t7 + (0.1e1 / 0.24e2)*_hc1[4]*_t2*_t30*_t46*_t61 - _hc1[7]*_t103*_t104 - _t107*_t109 - _t110*_t53*_t64;
  const double _t112 = my_piecewise3(_t10, 0, _hc0[0]*_t111 + (0.1e1 / 0.24e2)*_t100*_t101 - _t105*_t106);
  const double _t113 = _hc1[6]*_t61;
  const double _t115 = _hc1[1]*_t7;
  const double _t116 = _t114*_t115;
  const double _t118 = 0.2e1*my_piecewise3(_t10, 0, -0.3e1 / 0.8e1*_hc0[0]*_t117*_t30*_t53 + _t113*_t60*_t66 + (0.3e1 / 0.8e1)*_t116*_t25);
  const double d3F_dna3 = _t21*_t83 + 0.6e1*_t45;
  const double d3F_dna2_dgaa = _t21*_t98 + 0.4e1*_t59;
  const double d3F_dna_dgaa2 = _t112*_t21 + _t65;
  const double d3F_dgaa3 = _t118*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t119 = xc_powr(na, -16, 3);
  const double _t120 = (0.140e3 / 0.81e2)*_t74;
  const double _t122 = _t75*_t9;
  const double _t126 = (0.7e1 / 0.27e2)*_t2*_t90;
  const double _t127 = (0.1e1 / 0.9e1)*_t108;
  const double _t128 = _t52*_t91;
  const double _t129 = _t23*_t92;
  const double _t131 = (0.1e1 / 0.18e2)*_t54*_t99;
  const double _t132 = _t109*_t22;
  const double _t133 = _t110*_t52*_t64;
  const double _t134 = (0.1e1 / 0.16e2)*_t114;
  const double _t121 = _hc0[1]*_t3;
  const double _t123 = -_hc1[11]*_t41 - _hc1[12]*_t13;
  const double _t124 = -_hc1[12]*_t41 - _hc1[13]*_t13;
  const double _t125 = _hc1[7]*_t76 + _hc1[8]*_t28 - _t123*_t41 - _t124*_t13;
  const double _t130 = -_hc1[11]*_t94 - _hc1[12]*_t50 - _hc1[7]*_t93;
  const double d4F_dna4 = _t21*my_piecewise3(_t10, 0, _hc0[0]*((0.3640e4 / 0.81e2)*_t119*_t15 + _t120*_t18 - _t13*(-_hc1[4]*_t122 - _hc1[5]*_t70 + (0.4e1 / 0.9e1)*_t1*_t16*_t2*_t80 - _t125*_t41 - _t13*(_hc1[8]*_t76 + _hc1[9]*_t28 - _t124*_t41 - _t13*(-_hc1[13]*_t41 - _hc1[14]*_t13)) + (0.56e2 / 0.9e1)*_t39*_t7*_t78*_t8) - _t3*_t43*_t92 + _t3*_t56*_t81 + (0.28e2 / 0.3e1)*_t39*_t79*_t9 - _t41*(-_hc1[3]*_t122 - _hc1[4]*_t70 + (0.4e1 / 0.9e1)*_t1*_t16*_t2*_t78 - _t125*_t13 + (0.56e2 / 0.9e1)*_t39*_t7*_t77*_t8 - _t41*(_hc1[6]*_t76 + _hc1[7]*_t28 - _t123*_t13 - _t41*(-_hc1[10]*_t41 - _hc1[11]*_t13))) - 0.280e3 / 0.9e1*_t42*_t74*_t9) - 0.56e2 / 0.27e2*_hc0[1]*_t36*_t39 + (0.1e1 / 0.216e3)*_hc0[4]*_hc1[0]*_t1*_t119/(M_PI * M_CBRTPI) + (0.2e1 / 0.9e1)*_hc1[0]*_t108*_t67 + _t120*_t14*_t3 + _t121*_t17*_t44 - 0.4e1 / 0.9e1*_t19*_t34*_t54 - 0.1e1 / 0.9e1*_t19*_t68 - 0.2e1 / 0.3e1*_t3*_t37*_t82 + (0.1e1 / 0.6e1)*_t35*_t44 + (0.40e2 / 0.81e2)*_t72*_t90) + 0.8e1*_t83;
  const double d4F_dna3_dgaa = _t21*my_piecewise3(_t10, 0, _hc0[0]*((0.4e1 / 0.9e1)*_t1*_t16*_t2*_t96 - _t126*_t57 - _t13*(_hc1[4]*_t129 + _hc1[7]*_t128 + _hc1[8]*_t85 - _t13*(-_hc1[12]*_t94 - _hc1[13]*_t50 - _hc1[8]*_t93) - _t130*_t41 - _t78*_t93) + (0.28e2 / 0.9e1)*_t22*_t39*_t42*_t7 - 0.140e3 / 0.27e2*_t24*_t74 + (0.56e2 / 0.9e1)*_t39*_t7*_t8*_t95 - _t41*(_hc1[3]*_t129 + _hc1[6]*_t128 + _hc1[7]*_t85 - _t13*_t130 - _t41*(-_hc1[10]*_t94 - _hc1[11]*_t50 - _t107*_t56*_t7) - _t77*_t93) - 0.140e3 / 0.27e2*_t53/xc_powr(na, 17, 3) - _t79*_t93) + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t16*_t2*_t58 + (0.1e1 / 0.12e2)*_hc0[2]*_t30*_t31*_t32*_t58 - 0.1e1 / 0.72e2*_t119*_t24*_t67 - _t126*_t47*_t51 - _t127*_t86*_t88 - _t73*_t97) + 0.6e1*_t98;
  const double d4F_dna2_dgaa2 = 0.4e1*_t112 + _t21*my_piecewise3(_t10, 0, _hc0[0]*((0.7e1 / 0.9e1)*_hc1[3]*_t52*_t64*_t90 - _hc1[4]*_t131*_t61 + (0.14e2 / 0.9e1)*_hc1[6]*_t22/xc_powi(na, 6) + (0.1e1 / 0.9e1)*_hc1[7]*_t102*_t108*_t2*_t64 - _t13*(-_hc1[11]*_t132 - _hc1[12]*_t105 + (0.1e1 / 0.3e1)*_hc1[4]*_t16*_t61*_t7 - _hc1[7]*_t133 + (0.1e1 / 0.24e2)*_hc1[8]*_t2*_t30*_t46*_t61) + (0.1e1 / 0.3e1)*_t16*_t42*_t61*_t7 - _t17*_t23*_t95 - 0.7e1 / 0.9e1*_t39*_t63 - _t41*(-_hc1[10]*_t132 - _hc1[11]*_t105 + (0.1e1 / 0.3e1)*_hc1[3]*_t16*_t61*_t7 - _hc1[6]*_t133 + (0.1e1 / 0.24e2)*_hc1[7]*_t2*_t30*_t46*_t61)) + (0.1e1 / 0.72e2)*_hc1[3]*_t119*_t64*_t7*_t86 - _t101*_t131 + _t103*_t106*_t127*_t2 - _t111*_t89 - 0.1e1 / 0.72e2*_t62*_t87);
  const double d4F_dna_dgaa3 = _t118 + _t21*my_piecewise3(_t10, 0, _hc0[0]*(-0.1e1 / 0.3e1*_hc1[10]*_t64*_t7/xc_powr(na, 19, 3) - 0.1e1 / 0.24e2*_hc1[11]*_t119*_t3*_t61 + (0.1e1 / 0.2e1)*_hc1[3]*_t117*_t52*_t54 - _hc1[4]*_t100*_t134 + (0.1e1 / 0.8e1)*_hc1[7]*_t102*_t117*_t2*_t66 - 0.1e1 / 0.2e1*_t116*_t16) - _t100*_t134*_t51 + (0.1e1 / 0.8e1)*_t102*_t106*_t117*_t2*_t66 - 0.1e1 / 0.24e2*_t113*_t119*_t121);
  const double d4F_dgaa4 = _t21*my_piecewise3(_t10, 0, (0.1e1 / 0.8e1)*_hc0[0]*_hc1[10]*_t117*_t119*_t7 + (0.15e2 / 0.16e2)*_hc0[0]*_hc1[3]*_t30*_t52/(gaa * gaa * gaa) - 0.3e1 / 0.4e1*_hc0[0]*_hc1[6]*_t114*_t66 - 0.15e2 / 0.16e2*_t115*_t25/xc_powr(gaa, 7, 2));
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
  const double _t12 = xc_powr(gbb, 1, 2);
  const double _t13 = xc_powr(nb, -4, 3);
  const double _t14 = -p->dens_threshold + na <= 0;
  const double _t15 = -_t1 - p->dens_threshold <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t14)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t9, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t14)) XC_CAT(n12_FN12_k, _KMAX)(p, _t9, _hc0[0], _t10*_t11, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t5, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t15)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t9, _hc3[0], _hc4);
  double _hc5[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t15)) XC_CAT(n12_FN12_k, _KMAX)(p, _t9, _hc3[0], _t12*_t13, _hc5);
  const double _t16 = my_piecewise3(_t14, 0, _hc1[0]*_hc2[0]) + my_piecewise3(_t15, 0, _hc4[0]*_hc5[0]);
  const double zk = _t16;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t17 = xc_powr(_t3, -4, 3);
  const double _t18 = _t17*_t8;
  const double _t19 = (0.1e1 / 0.6e1)*_t18;
  const double _t21 = -_t4;
  const double _t22 = (0.1e1 / (_t3 * _t3));
  const double _t23 = _t2*_t22;
  const double _t24 = _t21 + _t23;
  const double _t31 = -_t24;
  const double _t34 = xc_powr(na, -7, 3);
  const double _t35 = _t10*_t34;
  const double _t36 = (0.4e1 / 0.3e1)*_t35;
  const double _t41 = _t23 + _t4;
  const double _t42 = -_t41;
  const double _t50 = xc_powr(nb, -7, 3);
  const double _t51 = (0.4e1 / 0.3e1)*_t50;
  const double _t56 = (0.1e1 / _t10);
  const double _t61 = (0.1e1 / _t12);
  const double _t20 = _hc5[3]*_t19;
  const double _t25 = _hc3[1]*_t24;
  const double _t26 = _hc5[2]*_t25 - _t20;
  const double _t27 = -_hc4[2]*_t19;
  const double _t28 = _hc4[1]*_t25 + _t27;
  const double _t29 = my_piecewise3(_t15, 0, _hc4[0]*_t26 + _hc5[0]*_t28);
  const double _t30 = -_hc1[2]*_t19;
  const double _t32 = _hc0[1]*_t31;
  const double _t33 = _hc1[1]*_t32 + _t30;
  const double _t37 = _hc2[3]*_t19;
  const double _t38 = _hc0[1]*_hc2[2]*_t31 - _hc2[1]*_t36 - _t37;
  const double _t39 = my_piecewise3(_t14, 0, _hc1[0]*_t38 + _hc2[0]*_t33);
  const double _t40 = _t29 + _t39;
  const double _t43 = _hc0[1]*_t42;
  const double _t44 = _hc2[2]*_t43 - _t37;
  const double _t45 = _hc1[1]*_t43 + _t30;
  const double _t46 = my_piecewise3(_t14, 0, _hc1[0]*_t44 + _hc2[0]*_t45);
  const double _t47 = _hc3[1]*_t41;
  const double _t48 = _hc4[1]*_t47 + _t27;
  const double _t49 = _hc5[1]*_t12;
  const double _t52 = _hc3[1]*_hc5[2]*_t41 - _t20 - _t49*_t51;
  const double _t53 = my_piecewise3(_t15, 0, _hc4[0]*_t52 + _hc5[0]*_t48);
  const double _t54 = _t46 + _t53;
  const double _t55 = _hc1[0]*_t11;
  const double _t57 = _hc2[1]*_t56;
  const double _t58 = (0.1e1 / 0.2e1)*_t57;
  const double _t59 = my_piecewise3(_t14, 0, _t55*_t58);
  const double _t60 = _hc4[0]*_t13;
  const double _t62 = _hc5[1]*_t61;
  const double _t63 = (0.1e1 / 0.2e1)*_t62;
  const double _t64 = my_piecewise3(_t15, 0, _t60*_t63);
  const double dF_dna = _t16 + _t3*_t40;
  const double dF_dnb = _t16 + _t3*_t54;
  const double dF_dgaa = _t3*_t59;
  const double dF_dgbb = _t3*_t64;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t66 = xc_powr(_t3, -7, 3);
  const double _t67 = (0.2e1 / 0.9e1)*_t66;
  const double _t68 = _t67*_t8;
  const double _t70 = 0.2e1*_t22;
  const double _t71 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t72 = 0.2e1*_t71;
  const double _t73 = _t2*_t72;
  const double _t74 = -_t70 + _t73;
  const double _t75 = -_t74;
  const double _t77 = (_t24 * _t24);
  const double _t94 = (_t31 * _t31);
  const double _t102 = xc_powr(na, -10, 3);
  const double _t103 = (0.28e2 / 0.9e1)*_t102;
  const double _t123 = _t12*_t51;
  const double _t146 = _t70 + _t73;
  const double _t148 = (_t42 * _t42);
  const double _t154 = -_t146;
  const double _t156 = (_t41 * _t41);
  const double _t160 = xc_powr(nb, -10, 3);
  const double _t161 = (0.28e2 / 0.9e1)*_t160;
  const double _t166 = xc_powr(na, -11, 3);
  const double _t167 = (0.2e1 / 0.3e1)*_t166;
  const double _t168 = (0.2e1 / 0.3e1)*_t34;
  const double _t169 = (0.1e1 / 0.12e2)*_t18;
  const double _t170 = _t11*_t56;
  const double _t176 = _t13*_t61;
  const double _t177 = _t169*_t176;
  const double _t183 = (0.1e1 / 0.2e1)*_t170;
  const double _t186 = xc_powr(nb, -11, 3);
  const double _t187 = (0.2e1 / 0.3e1)*_t186;
  const double _t188 = (0.2e1 / 0.3e1)*_t50;
  const double _t191 = xc_powr(gaa, -3, 2);
  const double _t194 = (0.1e1 / gaa);
  const double _t195 = xc_powr(na, -8, 3);
  const double _t197 = xc_powr(gbb, -3, 2);
  const double _t200 = (0.1e1 / gbb);
  const double _t201 = xc_powr(nb, -8, 3);
  const double _t65 = 0.2e1*_t28;
  const double _t69 = _hc5[3]*_t68;
  const double _t76 = _hc3[1]*_t75;
  const double _t78 = _hc3[2]*_t77;
  const double _t79 = _hc5[9]*_t19;
  const double _t80 = _hc5[8]*_t25 - _t79;
  const double _t81 = _hc5[8]*_t19;
  const double _t82 = _hc5[6]*_t25 - _t81;
  const double _t83 = _hc5[2]*_t76 + _hc5[2]*_t78 - _t19*_t80 + _t25*_t82 + _t69;
  const double _t84 = _hc4[2]*_t68;
  const double _t85 = -_hc4[5]*_t19;
  const double _t86 = _hc4[4]*_t25 + _t85;
  const double _t87 = -_hc4[4]*_t19;
  const double _t88 = _hc4[3]*_t25 + _t87;
  const double _t89 = _hc4[1]*_t76 + _hc4[1]*_t78 - _t19*_t86 + _t25*_t88 + _t84;
  const double _t90 = my_piecewise3(_t15, 0, _hc4[0]*_t83 + _hc5[0]*_t89 + _t26*_t65);
  const double _t91 = 0.2e1*_t33;
  const double _t92 = _hc1[2]*_t68;
  const double _t93 = _hc0[1]*_t74;
  const double _t95 = _hc0[2]*_t94;
  const double _t96 = -_hc1[5]*_t19;
  const double _t97 = _hc1[4]*_t32 + _t96;
  const double _t98 = -_hc1[4]*_t19;
  const double _t99 = _hc1[3]*_t32 + _t98;
  const double _t100 = _hc1[1]*_t93 + _hc1[1]*_t95 - _t19*_t97 + _t32*_t99 + _t92;
  const double _t101 = _hc2[1]*_t10;
  const double _t104 = _hc2[3]*_t8;
  const double _t105 = _t104*_t67;
  const double _t106 = _hc2[7]*_t19;
  const double _t107 = _hc0[1]*_hc2[5]*_t31 - _hc2[4]*_t36 - _t106;
  const double _t108 = _hc2[9]*_t19;
  const double _t109 = _hc0[1]*_hc2[8]*_t31 - _hc2[7]*_t36 - _t108;
  const double _t110 = _hc2[8]*_t19;
  const double _t111 = _hc2[5]*_t36 + _t110;
  const double _t112 = _hc0[1]*_hc2[6]*_t31 - _t111;
  const double _t113 = _hc2[2]*_t93 + _hc2[2]*_t95 + _t101*_t103 + _t105 - _t107*_t36 - _t109*_t19 + _t112*_t32;
  const double _t114 = my_piecewise3(_t14, 0, _hc1[0]*_t113 + _hc2[0]*_t100 + _t38*_t91);
  const double _t115 = _t114 + _t90;
  const double _t116 = _hc4[3]*_t47 + _t87;
  const double _t117 = _hc3[2]*_t24;
  const double _t118 = _hc4[1]*_t117;
  const double _t119 = _hc3[1]*_t73;
  const double _t120 = _hc4[4]*_t47 + _t85;
  const double _t121 = -_t120*_t19 + _t84;
  const double _t122 = -_hc4[1]*_t119 + _t116*_t25 + _t118*_t41 + _t121;
  const double _t124 = _hc3[1]*_hc5[6]*_t41 - _hc5[5]*_t123 - _t81;
  const double _t125 = _hc5[2]*_t41;
  const double _t126 = _hc3[1]*_hc5[8]*_t41 - _hc5[7]*_t123 - _t79;
  const double _t127 = -_t126*_t19 + _t69;
  const double _t128 = -_hc5[2]*_t119 + _t117*_t125 + _t124*_t25 + _t127;
  const double _t129 = my_piecewise3(_t15, 0, _hc4[0]*_t128 + _hc5[0]*_t122 + _t26*_t48 + _t28*_t52);
  const double _t130 = _hc1[3]*_t43 + _t98;
  const double _t131 = _hc0[2]*_t31;
  const double _t132 = _t131*_t42;
  const double _t133 = _hc0[1]*_t73;
  const double _t134 = _hc1[4]*_t43 + _t96;
  const double _t135 = -_t134*_t19 + _t92;
  const double _t136 = _hc1[1]*_t132 + _hc1[1]*_t133 + _t130*_t32 + _t135;
  const double _t137 = -_t110;
  const double _t138 = _hc2[6]*_t43 + _t137;
  const double _t139 = _hc2[5]*_t43;
  const double _t140 = -_t106 + _t139;
  const double _t141 = _hc2[8]*_t43 - _t108;
  const double _t142 = _t105 - _t141*_t19;
  const double _t143 = _hc2[2]*_t132 + _hc2[2]*_t133 + _t138*_t32 - _t140*_t36 + _t142;
  const double _t144 = my_piecewise3(_t14, 0, _hc1[0]*_t143 + _hc2[0]*_t136 + _t33*_t44 + _t38*_t45);
  const double _t145 = 0.2e1*_t45;
  const double _t147 = _hc0[1]*_t146;
  const double _t149 = _hc0[2]*_t148;
  const double _t150 = _hc2[2]*_t147 + _hc2[2]*_t149 + _t138*_t43 + _t142;
  const double _t151 = _hc1[1]*_t147 + _hc1[1]*_t149 + _t130*_t43 + _t135;
  const double _t152 = my_piecewise3(_t14, 0, _hc1[0]*_t150 + _hc2[0]*_t151 + _t145*_t44);
  const double _t153 = 0.2e1*_t48;
  const double _t155 = _hc3[1]*_t154;
  const double _t157 = _hc3[2]*_t156;
  const double _t158 = _hc4[1]*_t155 + _hc4[1]*_t157 + _t116*_t47 + _t121;
  const double _t159 = _hc3[1]*_hc5[5]*_t41 - _hc5[4]*_t123 - _hc5[7]*_t19;
  const double _t162 = _hc5[2]*_t155 + _hc5[2]*_t157 - _t123*_t159 + _t124*_t47 + _t127 + _t161*_t49;
  const double _t163 = my_piecewise3(_t15, 0, _hc4[0]*_t162 + _hc5[0]*_t158 + _t153*_t52);
  const double _t164 = _t152 + _t163;
  const double _t165 = _t11*_t58;
  const double _t171 = _hc2[7]*_t170;
  const double _t172 = _t169*_t171;
  const double _t173 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[5]*_t11*_t31*_t56 - _hc2[4]*_t167 - _t168*_t57 - _t172;
  const double _t174 = my_piecewise3(_t14, 0, _hc1[0]*_t173 + _t165*_t33);
  const double _t175 = _t13*_t63;
  const double _t178 = _hc5[7]*_t177;
  const double _t179 = _hc5[5]*_t176;
  const double _t180 = (0.1e1 / 0.2e1)*_t25;
  const double _t181 = -_t178 + _t179*_t180;
  const double _t182 = my_piecewise3(_t15, 0, _hc4[0]*_t181 + _t175*_t28);
  const double _t184 = _t139*_t183 - _t172;
  const double _t185 = my_piecewise3(_t14, 0, _hc1[0]*_t184 + _t165*_t45);
  const double _t189 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[5]*_t13*_t41*_t61 - _hc5[4]*_t187 - _t178 - _t188*_t62;
  const double _t190 = my_piecewise3(_t15, 0, _hc4[0]*_t189 + _t175*_t48);
  const double _t192 = _hc2[1]*_t191;
  const double _t193 = (0.1e1 / 0.4e1)*_t192;
  const double _t196 = my_piecewise3(_t14, 0, (0.1e1 / 0.4e1)*_hc1[0]*_hc2[4]*_t194*_t195 - _t193*_t55);
  const double _t198 = _hc5[1]*_t197;
  const double _t199 = (0.1e1 / 0.4e1)*_t198;
  const double _t202 = my_piecewise3(_t15, 0, (0.1e1 / 0.4e1)*_hc4[0]*_hc5[4]*_t200*_t201 - _t199*_t60);
  const double d2F_dna2 = _t115*_t3 + 0.2e1*_t29 + 0.2e1*_t39;
  const double d2F_dna_dnb = _t3*(_t129 + _t144) + _t40 + _t54;
  const double d2F_dnb2 = _t164*_t3 + 0.2e1*_t46 + 0.2e1*_t53;
  const double d2F_dna_dgaa = _t174*_t3 + _t59;
  const double d2F_dna_dgbb = _t182*_t3 + _t64;
  const double d2F_dnb_dgaa = _t185*_t3 + _t59;
  const double d2F_dnb_dgbb = _t190*_t3 + _t64;
  const double d2F_dgaa2 = _t196*_t3;
  const double d2F_dgbb2 = _t202*_t3;
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
  const double _t205 = xc_powr(_t3, -10, 3);
  const double _t206 = (0.14e2 / 0.27e2)*_t205;
  const double _t207 = _t206*_t8;
  const double _t209 = 0.6e1*_t71;
  const double _t210 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t211 = _t2*_t210;
  const double _t212 = 0.6e1*_t211;
  const double _t213 = -_t209 + _t212;
  const double _t215 = (_t24 * _t24 * _t24);
  const double _t217 = 0.4e1*_t22;
  const double _t218 = 0.4e1*_t71;
  const double _t219 = _t2*_t218;
  const double _t220 = -_t217 + _t219;
  const double _t221 = -_t220;
  const double _t223 = _t66*_t8;
  const double _t224 = (0.4e1 / 0.9e1)*_t223;
  const double _t254 = -_t213;
  const double _t256 = (_t31 * _t31 * _t31);
  const double _t259 = -_t2*_t22;
  const double _t260 = _t259 + _t4;
  const double _t277 = xc_powr(na, -13, 3);
  const double _t278 = (0.280e3 / 0.27e2)*_t277;
  const double _t282 = (0.56e2 / 0.9e1)*_t102;
  const double _t284 = _t10*_t103;
  const double _t313 = _t212 - 0.2e1*_t71;
  const double _t337 = -_t313;
  const double _t339 = _t21 + _t259;
  const double _t340 = _t339*_t94;
  const double _t392 = _t12*_t161;
  const double _t405 = _t148*_t260;
  const double _t425 = _t209 + _t212;
  const double _t426 = -_t425;
  const double _t428 = (_t42 * _t42 * _t42);
  const double _t432 = _t217 + _t219;
  const double _t439 = (_t41 * _t41 * _t41);
  const double _t441 = -_t432;
  const double _t443 = xc_powr(nb, -13, 3);
  const double _t444 = (0.280e3 / 0.27e2)*_t443;
  const double _t450 = (0.56e2 / 0.9e1)*_t160;
  const double _t454 = xc_powr(na, -14, 3);
  const double _t455 = (0.14e2 / 0.9e1)*_t454;
  const double _t456 = (0.14e2 / 0.9e1)*_t102;
  const double _t457 = (0.1e1 / 0.9e1)*_t223;
  const double _t459 = _t168*_t56;
  const double _t460 = _t169*_t170;
  const double _t470 = _t176*_t457;
  const double _t490 = _t188*_t61;
  const double _t500 = xc_powr(nb, -14, 3);
  const double _t501 = (0.14e2 / 0.9e1)*_t500;
  const double _t503 = (0.14e2 / 0.9e1)*_t160;
  const double _t504 = (0.1e1 / 0.2e1)*_t176;
  const double _t511 = _t56/xc_powi(na, 5);
  const double _t512 = _t166*_t194;
  const double _t513 = _t194*_t195;
  const double _t514 = (0.1e1 / 0.24e2)*_t18;
  const double _t516 = (0.1e1 / 0.4e1)*_t191;
  const double _t522 = _t200*_t201;
  const double _t523 = _t514*_t522;
  const double _t525 = _t13*_t197;
  const double _t530 = _t11*_t191;
  const double _t531 = (0.1e1 / 0.4e1)*_t194*_t195;
  const double _t532 = _t11*_t516;
  const double _t536 = _t61/xc_powi(nb, 5);
  const double _t537 = _t186*_t200;
  const double _t538 = (0.1e1 / 0.4e1)*_t525;
  const double _t541 = xc_powr(gaa, -5, 2);
  const double _t545 = (0.1e1 / (na * na * na * na));
  const double _t546 = _t191*_t545;
  const double _t547 = (0.1e1 / 0.8e1)*_t546;
  const double _t548 = (0.1e1 / (gaa * gaa));
  const double _t551 = xc_powr(gbb, -5, 2);
  const double _t555 = (0.1e1 / (nb * nb * nb * nb));
  const double _t556 = _t197*_t555;
  const double _t557 = (0.1e1 / 0.8e1)*_t556;
  const double _t558 = (0.1e1 / (gbb * gbb));
  const double _t203 = 0.3e1*_t28;
  const double _t204 = 0.3e1*_t26;
  const double _t208 = -_hc5[3]*_t207;
  const double _t214 = _hc3[1]*_t213;
  const double _t216 = _hc3[3]*_t215;
  const double _t222 = _hc5[2]*_t117;
  const double _t225 = 0.2e1*_t82;
  const double _t226 = _hc5[9]*_t68;
  const double _t227 = _hc5[19]*_t19;
  const double _t228 = _hc5[18]*_t25 - _t227;
  const double _t229 = _hc5[18]*_t19;
  const double _t230 = _hc5[16]*_t25 - _t229;
  const double _t231 = _hc5[8]*_t76 + _hc5[8]*_t78 - _t19*_t228 + _t226 + _t230*_t25;
  const double _t232 = _hc5[8]*_t68;
  const double _t233 = _hc5[16]*_t19;
  const double _t234 = _hc5[13]*_t25 - _t233;
  const double _t235 = _hc5[6]*_t76 + _hc5[6]*_t78 - _t19*_t230 + _t232 + _t234*_t25;
  const double _t236 = _hc5[2]*_t214 + _hc5[2]*_t216 - _t19*_t231 + _t208 + _t221*_t222 + _t222*_t75 + _t224*_t80 + _t225*_t76 + _t225*_t78 + _t235*_t25;
  const double _t237 = -_hc4[2]*_t207;
  const double _t238 = 0.2e1*_t88;
  const double _t239 = _hc4[5]*_t68;
  const double _t240 = -_hc4[9]*_t19;
  const double _t241 = _hc4[8]*_t25 + _t240;
  const double _t242 = -_hc4[8]*_t19;
  const double _t243 = _hc4[7]*_t25 + _t242;
  const double _t244 = _hc4[4]*_t76 + _hc4[4]*_t78 - _t19*_t241 + _t239 + _t243*_t25;
  const double _t245 = _hc4[4]*_t68;
  const double _t246 = -_hc4[7]*_t19;
  const double _t247 = _hc4[6]*_t25 + _t246;
  const double _t248 = _hc4[3]*_t76 + _hc4[3]*_t78 - _t19*_t243 + _t245 + _t247*_t25;
  const double _t249 = _hc4[1]*_t214 + _hc4[1]*_t216 + _t118*_t221 + _t118*_t75 - _t19*_t244 + _t224*_t86 + _t237 + _t238*_t76 + _t238*_t78 + _t248*_t25;
  const double _t250 = my_piecewise3(_t15, 0, _hc4[0]*_t236 + _hc5[0]*_t249 + _t203*_t83 + _t204*_t89);
  const double _t251 = 0.3e1*_t38;
  const double _t252 = 0.3e1*_t33;
  const double _t253 = -_hc1[2]*_t207;
  const double _t255 = _hc0[1]*_t254;
  const double _t257 = _hc0[3]*_t256;
  const double _t258 = _hc1[1]*_t131;
  const double _t261 = _hc0[1]*_t260;
  const double _t262 = _hc1[3]*_t261 + _t98;
  const double _t263 = 0.2e1*_t95;
  const double _t264 = 0.2e1*_t93;
  const double _t265 = _hc1[5]*_t68;
  const double _t266 = -_hc1[9]*_t19;
  const double _t267 = _hc1[8]*_t32 + _t266;
  const double _t268 = -_hc1[8]*_t19;
  const double _t269 = _hc1[7]*_t32 + _t268;
  const double _t270 = _hc1[4]*_t93 + _hc1[4]*_t95 - _t19*_t267 + _t265 + _t269*_t32;
  const double _t271 = -_hc1[7]*_t19;
  const double _t272 = _hc1[6]*_t32 + _t271;
  const double _t273 = _hc1[4]*_t68;
  const double _t274 = _hc1[3]*_t95 + _t273;
  const double _t275 = _hc1[3]*_t93 - _t19*_t269 + _t272*_t32 + _t274;
  const double _t276 = _hc1[1]*_t255 + _hc1[1]*_t257 - _t19*_t270 + _t220*_t258 + _t224*_t97 + _t253 + _t258*_t74 + _t262*_t263 + _t264*_t99 + _t275*_t32;
  const double _t279 = -_t104*_t206;
  const double _t280 = _hc2[2]*_t131;
  const double _t281 = _t10*_t107;
  const double _t283 = _hc0[1]*_hc2[6]*_t260 - _t111;
  const double _t285 = _hc2[7]*_t68;
  const double _t286 = _hc2[5]*_t93;
  const double _t287 = _hc2[5]*_t95;
  const double _t288 = _hc2[14]*_t19;
  const double _t289 = _hc0[1]*_hc2[11]*_t31 - _hc2[10]*_t36 - _t288;
  const double _t290 = _hc2[17]*_t19;
  const double _t291 = _hc0[1]*_hc2[15]*_t31 - _hc2[14]*_t36 - _t290;
  const double _t292 = _hc2[15]*_t19;
  const double _t293 = _hc2[11]*_t36 + _t292;
  const double _t294 = _hc0[1]*_hc2[12]*_t31 - _t293;
  const double _t295 = _hc2[4]*_t284 - _t19*_t291 + _t285 + _t286 + _t287 - _t289*_t36 + _t294*_t32;
  const double _t296 = _hc2[9]*_t68;
  const double _t297 = _hc2[19]*_t19;
  const double _t298 = _hc0[1]*_hc2[18]*_t31 - _hc2[17]*_t36 - _t297;
  const double _t299 = _hc2[18]*_t19;
  const double _t300 = _hc2[15]*_t36 + _t299;
  const double _t301 = _hc0[1]*_hc2[16]*_t31 - _t300;
  const double _t302 = _hc2[7]*_t284 + _hc2[8]*_t93 + _hc2[8]*_t95 - _t19*_t298 - _t291*_t36 + _t296 + _t301*_t32;
  const double _t303 = _hc2[16]*_t19;
  const double _t304 = _hc2[12]*_t36 + _t303;
  const double _t305 = _hc0[1]*_hc2[13]*_t31 - _t304;
  const double _t306 = _hc2[8]*_t68;
  const double _t307 = _hc2[5]*_t284 + _hc2[6]*_t95 + _t306;
  const double _t308 = _hc2[6]*_t93 - _t19*_t301 - _t294*_t36 + _t305*_t32 + _t307;
  const double _t309 = _hc2[2]*_t255 + _hc2[2]*_t257 - _t101*_t278 + _t109*_t224 + _t112*_t264 - _t19*_t302 + _t220*_t280 + _t263*_t283 + _t279 + _t280*_t74 + _t281*_t282 - _t295*_t36 + _t308*_t32;
  const double _t310 = my_piecewise3(_t14, 0, _hc1[0]*_t309 + _hc2[0]*_t276 + _t100*_t251 + _t113*_t252);
  const double _t311 = _t250 + _t310;
  const double _t312 = 0.2e1*_t122;
  const double _t314 = _hc3[1]*_t313;
  const double _t315 = _hc3[2]*_t75;
  const double _t316 = _hc4[1]*_t41;
  const double _t317 = _hc3[3]*_t77;
  const double _t318 = _t117*_t41;
  const double _t319 = _hc4[7]*_t47 + _t242;
  const double _t320 = _hc4[8]*_t47 + _t240;
  const double _t321 = -_t19*_t320 + _t239;
  const double _t322 = -_hc4[4]*_t119 + _hc4[4]*_t318 + _t25*_t319 + _t321;
  const double _t323 = _hc4[6]*_t47 + _t246;
  const double _t324 = -_t19*_t319 + _t245;
  const double _t325 = -_hc4[3]*_t119 + _hc4[3]*_t318 + _t25*_t323 + _t324;
  const double _t326 = _hc4[1]*_t314 + _t116*_t76 + _t116*_t78 - _t118*_t219 - _t119*_t88 + _t120*_t68 - _t19*_t322 + _t237 + _t25*_t325 + _t315*_t316 + _t316*_t317 + _t318*_t88 + _t68*_t86;
  const double _t327 = _hc3[1]*_hc5[16]*_t41 - _hc5[15]*_t123 - _t229;
  const double _t328 = _hc3[1]*_hc5[18]*_t41 - _hc5[17]*_t123 - _t227;
  const double _t329 = -_t19*_t328 + _t226;
  const double _t330 = -_hc5[8]*_t119 + _hc5[8]*_t318 + _t25*_t327 + _t329;
  const double _t331 = _hc3[1]*_hc5[13]*_t41 - _hc5[12]*_t123 - _t233;
  const double _t332 = -_t19*_t327 + _t232;
  const double _t333 = -_hc5[6]*_t119 + _hc5[6]*_t318 + _t25*_t331 + _t332;
  const double _t334 = _hc5[2]*_t314 - _t119*_t82 + _t124*_t76 + _t124*_t78 + _t125*_t315 + _t125*_t317 + _t126*_t68 - _t19*_t330 + _t208 - _t219*_t222 + _t25*_t333 + _t318*_t82 + _t68*_t80;
  const double _t335 = my_piecewise3(_t15, 0, _hc4[0]*_t334 + _hc5[0]*_t326 + _t128*_t65 + _t26*_t312 + _t48*_t83 + _t52*_t89);
  const double _t336 = 0.2e1*_t136;
  const double _t338 = _hc0[1]*_t337;
  const double _t341 = _hc0[3]*_hc1[1];
  const double _t342 = _hc0[2]*_t42;
  const double _t343 = _t342*_t74;
  const double _t344 = _hc0[1]*_t339;
  const double _t345 = _hc1[3]*_t344 + _t98;
  const double _t346 = _hc1[7]*_t43 + _t268;
  const double _t347 = _hc1[8]*_t43 + _t266;
  const double _t348 = -_t19*_t347 + _t265;
  const double _t349 = _hc1[4]*_t132 + _hc1[4]*_t133 + _t32*_t346 + _t348;
  const double _t350 = _hc1[6]*_t43 + _t271;
  const double _t351 = _hc1[3]*_t133;
  const double _t352 = -_t19*_t346 + _t273;
  const double _t353 = _hc1[3]*_t132 + _t32*_t350 + _t351 + _t352;
  const double _t354 = _hc1[1]*_t338 + _hc1[1]*_t343 + _t130*_t93 + _t132*_t99 + _t133*_t99 + _t134*_t68 - _t19*_t349 + _t219*_t258 + _t253 + _t32*_t353 + _t340*_t341 + _t345*_t95 + _t68*_t97;
  const double _t355 = _hc0[3]*_hc2[2];
  const double _t356 = _hc2[6]*_t344 + _t137;
  const double _t357 = -_t292;
  const double _t358 = _hc2[12]*_t43;
  const double _t359 = _t357 + _t358;
  const double _t360 = _hc2[11]*_t43;
  const double _t361 = -_t288 + _t360;
  const double _t362 = _hc2[5]*_t132;
  const double _t363 = _hc2[15]*_t43;
  const double _t364 = -_t290 + _t363;
  const double _t365 = -_t19*_t364 + _t285;
  const double _t366 = _hc2[5]*_t133 + _t32*_t359 - _t36*_t361 + _t362 + _t365;
  const double _t367 = -_t299;
  const double _t368 = _hc2[16]*_t43 + _t367;
  const double _t369 = _hc2[18]*_t43 - _t297;
  const double _t370 = -_t19*_t369 + _t296;
  const double _t371 = _hc2[8]*_t132 + _hc2[8]*_t133 + _t32*_t368 - _t36*_t364 + _t370;
  const double _t372 = -_t19*_t368;
  const double _t373 = -_t303;
  const double _t374 = _hc2[13]*_t43 + _t373;
  const double _t375 = _hc2[6]*_t133 + _t306;
  const double _t376 = _hc2[6]*_t132 + _t32*_t374 - _t359*_t36 + _t372 + _t375;
  const double _t377 = _hc2[2]*_t338 + _hc2[2]*_t343 + _t109*_t68 + _t112*_t132 + _t112*_t133 + _t138*_t93 + _t140*_t284 + _t141*_t68 - _t19*_t371 + _t219*_t280 + _t279 + _t32*_t376 + _t340*_t355 + _t356*_t95 - _t36*_t366;
  const double _t378 = my_piecewise3(_t14, 0, _hc1[0]*_t377 + _hc2[0]*_t354 + _t100*_t44 + _t113*_t45 + _t143*_t91 + _t336*_t38);
  const double _t379 = 0.2e1*_t129 + 0.2e1*_t144;
  const double _t380 = _hc4[3]*_t155 + _hc4[3]*_t157 + _t323*_t47 + _t324;
  const double _t381 = _hc3[1]*_t72;
  const double _t382 = _hc3[3]*_t24;
  const double _t383 = _t156*_t382;
  const double _t384 = _hc3[1]*_t219;
  const double _t385 = 0.2e1*_t116;
  const double _t386 = _hc3[1]*_t212;
  const double _t387 = _hc3[2]*_t316;
  const double _t388 = _hc4[4]*_t155 + _hc4[4]*_t157 + _t319*_t47 + _t321;
  const double _t389 = _t120*_t224 - _t19*_t388 + _t237;
  const double _t390 = _hc4[1]*_t381 + _hc4[1]*_t383 + _hc4[1]*_t386 - _t116*_t384 + _t118*_t154 - _t219*_t387 + _t25*_t380 + _t318*_t385 + _t389;
  const double _t391 = _hc3[1]*_hc5[12]*_t41 - _hc5[11]*_t123 - _hc5[15]*_t19;
  const double _t393 = _hc5[5]*_t392 + _hc5[6]*_t155 + _hc5[6]*_t157 - _t123*_t391 + _t331*_t47 + _t332;
  const double _t394 = _hc5[2]*_t156;
  const double _t395 = 0.2e1*_t124;
  const double _t396 = _hc3[2]*_t125;
  const double _t397 = _hc3[1]*_hc5[15]*_t41 - _hc5[14]*_t123 - _hc5[17]*_t19;
  const double _t398 = _hc5[7]*_t392 + _hc5[8]*_t155 + _hc5[8]*_t157 - _t123*_t397 + _t327*_t47 + _t329;
  const double _t399 = _t126*_t224 - _t19*_t398 + _t208;
  const double _t400 = _hc5[2]*_t381 + _hc5[2]*_t386 - _t124*_t384 + _t154*_t222 - _t219*_t396 + _t25*_t393 + _t318*_t395 + _t382*_t394 + _t399;
  const double _t401 = my_piecewise3(_t15, 0, _hc4[0]*_t400 + _hc5[0]*_t390 + _t128*_t153 + _t158*_t26 + _t162*_t28 + _t312*_t52);
  const double _t402 = _hc1[3]*_t149;
  const double _t403 = _hc1[3]*_t147 + _t350*_t43 + _t352 + _t402;
  const double _t404 = _hc0[1]*_t72;
  const double _t406 = _hc0[1]*_t212;
  const double _t407 = 0.2e1*_t132;
  const double _t408 = _hc0[1]*_t219;
  const double _t409 = _hc1[1]*_t342;
  const double _t410 = _hc1[4]*_t147 + _hc1[4]*_t149 + _t346*_t43 + _t348;
  const double _t411 = _t134*_t224 - _t19*_t410 + _t253;
  const double _t412 = -_hc1[1]*_t404 - _hc1[1]*_t406 + _t130*_t407 + _t130*_t408 + _t146*_t258 + _t219*_t409 + _t32*_t403 + _t341*_t405 + _t411;
  const double _t413 = _hc2[6]*_t149 + _t306;
  const double _t414 = _hc2[6]*_t147 + _t372 + _t374*_t43 + _t413;
  const double _t415 = _hc2[5]*_t147;
  const double _t416 = _hc2[5]*_t149;
  const double _t417 = _t359*_t43 + _t365 + _t415 + _t416;
  const double _t418 = _hc2[2]*_t342;
  const double _t419 = _hc2[8]*_t147 + _hc2[8]*_t149 + _t368*_t43 + _t370;
  const double _t420 = _t141*_t224 - _t19*_t419 + _t279;
  const double _t421 = -_hc2[2]*_t404 - _hc2[2]*_t406 + _t138*_t407 + _t138*_t408 + _t146*_t280 + _t219*_t418 + _t32*_t414 + _t355*_t405 - _t36*_t417 + _t420;
  const double _t422 = my_piecewise3(_t14, 0, _hc1[0]*_t421 + _hc2[0]*_t412 + _t143*_t145 + _t150*_t33 + _t151*_t38 + _t336*_t44);
  const double _t423 = 0.3e1*_t45;
  const double _t424 = 0.3e1*_t44;
  const double _t427 = _hc0[1]*_t426;
  const double _t429 = _hc0[3]*_t428;
  const double _t430 = 0.2e1*_t147;
  const double _t431 = 0.2e1*_t149;
  const double _t433 = _hc2[2]*_t427 + _hc2[2]*_t429 + _t138*_t430 + _t146*_t418 + _t356*_t431 + _t414*_t43 + _t418*_t432 + _t420;
  const double _t434 = _hc1[1]*_t427 + _hc1[1]*_t429 + _t130*_t430 + _t146*_t409 + _t345*_t431 + _t403*_t43 + _t409*_t432 + _t411;
  const double _t435 = my_piecewise3(_t14, 0, _hc1[0]*_t433 + _hc2[0]*_t434 + _t150*_t423 + _t151*_t424);
  const double _t436 = 0.3e1*_t52;
  const double _t437 = 0.3e1*_t48;
  const double _t438 = _hc3[1]*_t425;
  const double _t440 = _hc3[3]*_t439;
  const double _t442 = _hc4[1]*_t438 + _hc4[1]*_t440 + _t154*_t387 + _t155*_t385 + _t157*_t385 + _t380*_t47 + _t387*_t441 + _t389;
  const double _t445 = _hc5[5]*_t157;
  const double _t446 = _hc5[5]*_t155;
  const double _t447 = _hc3[1]*_hc5[11]*_t41 - _hc5[10]*_t123 - _hc5[14]*_t19;
  const double _t448 = _hc5[4]*_t392 + _hc5[7]*_t68 - _t123*_t447 - _t19*_t397 + _t391*_t47 + _t445 + _t446;
  const double _t449 = _t12*_t159;
  const double _t451 = _hc5[2]*_t438 + _hc5[2]*_t440 - _t123*_t448 + _t154*_t396 + _t155*_t395 + _t157*_t395 + _t393*_t47 + _t396*_t441 + _t399 - _t444*_t49 + _t449*_t450;
  const double _t452 = my_piecewise3(_t15, 0, _hc4[0]*_t451 + _hc5[0]*_t442 + _t158*_t436 + _t162*_t437);
  const double _t453 = _t435 + _t452;
  const double _t458 = _t171*_t457;
  const double _t461 = _hc2[14]*_t460;
  const double _t462 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[11]*_t11*_t31*_t56 - _hc2[10]*_t167 - _hc2[4]*_t459 - _t461;
  const double _t463 = _hc2[17]*_t460;
  const double _t464 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[15]*_t11*_t31*_t56 - _hc2[14]*_t167 - _hc2[7]*_t459 - _t463;
  const double _t465 = _hc2[15]*_t460;
  const double _t466 = _hc2[11]*_t167 + _hc2[5]*_t459 + _t465;
  const double _t467 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[12]*_t11*_t31*_t56 - _t466;
  const double _t468 = _hc2[4]*_t455 - _t107*_t459 + _t183*_t286 + _t183*_t287 - _t19*_t464 + _t32*_t467 - _t36*_t462 + _t456*_t57 + _t458;
  const double _t469 = my_piecewise3(_t14, 0, _hc1[0]*_t468 + _t100*_t165 + _t173*_t91);
  const double _t471 = _hc5[7]*_t470;
  const double _t472 = (0.1e1 / 0.2e1)*_t179;
  const double _t473 = _hc5[17]*_t177;
  const double _t474 = _t176*_t180;
  const double _t475 = _hc5[15]*_t474 - _t473;
  const double _t476 = _hc5[15]*_t177;
  const double _t477 = _hc5[12]*_t474 - _t476;
  const double _t478 = -_t19*_t475 + _t25*_t477 + _t471 + _t472*_t76 + _t472*_t78;
  const double _t479 = my_piecewise3(_t15, 0, _hc4[0]*_t478 + _t175*_t89 + _t181*_t65);
  const double _t480 = -_t465;
  const double _t481 = _t183*_t358 + _t480;
  const double _t482 = _t183*_t360 - _t461;
  const double _t483 = _hc0[1]*_t71;
  const double _t484 = _t170*_t483;
  const double _t485 = _hc2[5]*_t484;
  const double _t486 = _t183*_t363 - _t463;
  const double _t487 = -_t19*_t486 + _t458;
  const double _t488 = -_t140*_t459 + _t183*_t362 + _t2*_t485 + _t32*_t481 - _t36*_t482 + _t487;
  const double _t489 = my_piecewise3(_t14, 0, _hc1[0]*_t488 + _t136*_t165 + _t173*_t45 + _t184*_t33);
  const double _t491 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[12]*_t13*_t41*_t61 - _hc5[11]*_t187 - _hc5[5]*_t490 - _t476;
  const double _t492 = _hc3[1]*_t71;
  const double _t493 = _t179*_t492;
  const double _t494 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[15]*_t13*_t41*_t61 - _hc5[14]*_t187 - _hc5[7]*_t490 - _t473;
  const double _t495 = -_t19*_t494 + _t471;
  const double _t496 = -_t2*_t493 + _t25*_t491 + _t318*_t472 + _t495;
  const double _t497 = my_piecewise3(_t15, 0, _hc4[0]*_t496 + _t122*_t175 + _t181*_t48 + _t189*_t28);
  const double _t498 = _t183*_t415 + _t183*_t416 + _t43*_t481 + _t487;
  const double _t499 = my_piecewise3(_t14, 0, _hc1[0]*_t498 + _t145*_t184 + _t151*_t165);
  const double _t502 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[11]*_t13*_t41*_t61 - _hc5[10]*_t187 - _hc5[14]*_t177 - _hc5[4]*_t490;
  const double _t505 = _hc5[4]*_t501 - _t123*_t502 - _t159*_t490 + _t445*_t504 + _t446*_t504 + _t47*_t491 + _t495 + _t503*_t62;
  const double _t506 = my_piecewise3(_t15, 0, _hc4[0]*_t505 + _t153*_t189 + _t158*_t175);
  const double _t507 = _t11*_t193;
  const double _t508 = _hc2[4]*_t194;
  const double _t509 = (0.1e1 / 0.4e1)*_t195*_t508;
  const double _t510 = (0.1e1 / 0.3e1)*_hc2[10];
  const double _t515 = _hc2[14]*_t513*_t514;
  const double _t517 = (0.1e1 / 0.4e1)*_hc0[1]*_hc2[11]*_t194*_t195*_t31 + (0.1e1 / 0.3e1)*_hc2[1]*_t191*_t34 - 0.1e1 / 0.3e1*_hc2[4]*_t512 - _hc2[5]*_t11*_t32*_t516 + (0.1e1 / 0.24e2)*_hc2[7]*_t11*_t17*_t191*_t6*_t7 - _t510*_t511 - _t515;
  const double _t518 = my_piecewise3(_t14, 0, _hc1[0]*_t517 - _t33*_t507 + _t33*_t509);
  const double _t519 = _t13*_t199;
  const double _t520 = _hc5[4]*_t200;
  const double _t521 = (0.1e1 / 0.4e1)*_t201*_t520;
  const double _t524 = _hc5[14]*_t523;
  const double _t526 = (0.1e1 / 0.4e1)*_t25;
  const double _t527 = _hc5[5]*_t525;
  const double _t528 = _hc5[11]*_t522*_t526 + _hc5[7]*_t514*_t525 - _t524 - _t526*_t527;
  const double _t529 = my_piecewise3(_t15, 0, _hc4[0]*_t528 - _t28*_t519 + _t28*_t521);
  const double _t533 = _hc2[7]*_t514*_t530 - _t139*_t532 + _t360*_t531 - _t515;
  const double _t534 = my_piecewise3(_t14, 0, _hc1[0]*_t533 - _t45*_t507 + _t45*_t509);
  const double _t535 = (0.1e1 / 0.3e1)*_hc5[10];
  const double _t539 = (0.1e1 / 0.4e1)*_hc3[1]*_hc5[11]*_t200*_t201*_t41 + (0.1e1 / 0.3e1)*_hc5[1]*_t197*_t50 - 0.1e1 / 0.3e1*_hc5[4]*_t537 - _hc5[5]*_t47*_t538 + (0.1e1 / 0.24e2)*_hc5[7]*_t13*_t17*_t197*_t6*_t7 - _t524 - _t535*_t536;
  const double _t540 = my_piecewise3(_t15, 0, _hc4[0]*_t539 - _t48*_t519 + _t48*_t521);
  const double _t542 = _hc2[1]*_t541;
  const double _t543 = (0.3e1 / 0.8e1)*_t542;
  const double _t544 = _hc1[0]*_hc2[10];
  const double _t549 = (0.3e1 / 0.8e1)*_hc2[4]*_t548;
  const double _t550 = my_piecewise3(_t14, 0, -_hc1[0]*_t195*_t549 + _t543*_t55 + _t544*_t547);
  const double _t552 = _hc5[1]*_t551;
  const double _t553 = (0.3e1 / 0.8e1)*_t552;
  const double _t554 = _hc4[0]*_hc5[10];
  const double _t559 = (0.3e1 / 0.8e1)*_hc5[4]*_t558;
  const double _t560 = my_piecewise3(_t15, 0, -_hc4[0]*_t201*_t559 + _t553*_t60 + _t554*_t557);
  const double d3F_dna3 = 0.3e1*_t114 + _t3*_t311 + 0.3e1*_t90;
  const double d3F_dna2_dnb = _t115 + _t3*(_t335 + _t378) + _t379;
  const double d3F_dna_dnb2 = _t164 + _t3*(_t401 + _t422) + _t379;
  const double d3F_dnb3 = 0.3e1*_t152 + 0.3e1*_t163 + _t3*_t453;
  const double d3F_dna2_dgaa = 0.2e1*_t174 + _t3*_t469;
  const double d3F_dna2_dgbb = 0.2e1*_t182 + _t3*_t479;
  const double d3F_dna_dnb_dgaa = _t174 + _t185 + _t3*_t489;
  const double d3F_dna_dnb_dgbb = _t182 + _t190 + _t3*_t497;
  const double d3F_dnb2_dgaa = 0.2e1*_t185 + _t3*_t499;
  const double d3F_dnb2_dgbb = 0.2e1*_t190 + _t3*_t506;
  const double d3F_dna_dgaa2 = _t196 + _t3*_t518;
  const double d3F_dna_dgbb2 = _t202 + _t3*_t529;
  const double d3F_dnb_dgaa2 = _t196 + _t3*_t534;
  const double d3F_dnb_dgbb2 = _t202 + _t3*_t540;
  const double d3F_dgaa3 = _t3*_t550;
  const double d3F_dgbb3 = _t3*_t560;
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
  const double _t561 = (0.140e3 / 0.81e2)/xc_powr(_t3, 13, 3);
  const double _t562 = _t561*_t8;
  const double _t564 = 0.24e2*_t210;
  const double _t565 = 0.24e2*_t2/xc_powi(_t3, 5);
  const double _t566 = -_t564 + _t565;
  const double _t570 = 0.12e2*_t71;
  const double _t571 = 0.12e2*_t210;
  const double _t572 = _t2*_t571;
  const double _t573 = -_t570 + _t572;
  const double _t574 = 0.2e1*_t213;
  const double _t576 = 0.6e1*_t22;
  const double _t577 = _t2*_t209;
  const double _t578 = _t576 - _t577;
  const double _t580 = _t205*_t8;
  const double _t581 = (0.14e2 / 0.9e1)*_t580;
  const double _t584 = (0.2e1 / 0.3e1)*_t223;
  const double _t628 = -_t573;
  const double _t629 = 0.2e1*_t254;
  const double _t632 = 0.6e1*na - 0.6e1*nb;
  const double _t633 = -_t576 + _t632*_t71;
  const double _t635 = 0.4e1*na - 0.4e1*nb;
  const double _t636 = -_t217 + _t635*_t71;
  const double _t637 = 0.2e1*na - 0.2e1*nb;
  const double _t638 = _t637*_t71 - _t70;
  const double _t663 = xc_powr(na, -16, 3);
  const double _t669 = _t10*_t278;
  const double _t676 = _t10*_t282;
  const double _t715 = _t565 - _t571;
  const double _t725 = _t572 - 0.4e1*_t71;
  const double _t729 = (0.28e2 / 0.27e2)*_t580;
  const double _t733 = 0.8e1*_t2*_t71;
  const double _t767 = -_t725;
  const double _t769 = _t256*_t339;
  const double _t775 = _t31*_t42;
  const double _t778 = _t220*_t73;
  const double _t834 = 0.2e1*_t313;
  const double _t836 = 0.8e1*(_t2 * _t2)/xc_powi(_t3, 6);
  const double _t863 = _t637*_t71 + _t70;
  const double _t868 = _t148*_t638;
  const double _t869 = _t148*_t94;
  const double _t870 = 0.2e1*_t337;
  const double _t897 = _t260*_t428;
  const double _t898 = 0.18e2*_t211;
  const double _t901 = 0.3e1*_t146;
  const double _t904 = _t146*_t577;
  const double _t907 = _t2*_t570;
  const double _t923 = 0.3e1*_t154;
  const double _t931 = _t12*_t444;
  const double _t936 = _t12*_t450;
  const double _t946 = _t564 + _t565;
  const double _t954 = _t570 + _t572;
  const double _t955 = -_t954;
  const double _t956 = _t146*_t432;
  const double _t957 = _t217 + _t635*_t71;
  const double _t958 = _t576 + _t632*_t71;
  const double _t959 = 0.2e1*_t426;
  const double _t960 = 0.3e1*_t432;
  const double _t966 = -_t576 - _t577;
  const double _t967 = 0.2e1*_t425;
  const double _t977 = xc_powr(nb, -16, 3);
  const double _t979 = (0.7e1 / 0.27e2)*_t580;
  const double _t981 = _t456*_t56;
  const double _t982 = _t170*_t457;
  const double _t1007 = _t170*_t73;
  const double _t1026 = 0.3e1*_t211;
  const double _t1029 = _t503*_t61;
  const double _t1034 = (0.1e1 / 0.3e1)*_t512;
  const double _t1035 = (0.1e1 / 0.3e1)*_t511;
  const double _t1036 = _t513*_t514;
  const double _t1040 = (0.4e1 / 0.3e1)*_t34*_t56;
  const double _t1042 = (0.1e1 / 0.18e2)*_t223;
  const double _t1049 = (0.1e1 / 0.4e1)*_t522;
  const double _t1055 = (0.1e1 / 0.3e1)*_t537;
  const double _t1056 = (0.1e1 / 0.3e1)*_t536;
  const double _t1063 = (0.3e1 / 0.8e1)*_t548;
  const double _t1064 = (0.1e1 / 0.16e2)*_t18;
  const double _t1065 = (0.1e1 / 0.48e2)*_t18;
  const double _t1070 = (0.3e1 / 0.8e1)*_t201*_t558;
  const double _t563 = _hc5[3]*_t562;
  const double _t567 = -_hc3[1]*_t566;
  const double _t568 = _hc3[4]*(_t24 * _t24 * _t24 * _t24);
  const double _t569 = _hc3[2]*(_t75 * _t75);
  const double _t575 = _hc5[2]*_t221;
  const double _t579 = _hc5[2]*_t317;
  const double _t582 = 0.3e1*_t82;
  const double _t583 = _t117*_t582;
  const double _t585 = 0.3e1*_t235;
  const double _t586 = -_hc5[9]*_t207;
  const double _t587 = _hc5[8]*_t117;
  const double _t588 = 0.2e1*_t230;
  const double _t589 = _hc5[19]*_t68;
  const double _t590 = _hc5[34]*_t19;
  const double _t591 = _hc5[33]*_t19;
  const double _t592 = _hc5[31]*_t25 - _t591;
  const double _t593 = _hc5[18]*_t68;
  const double _t594 = _hc5[31]*_t19;
  const double _t595 = _hc5[28]*_t25 - _t594;
  const double _t596 = _hc5[16]*_t76 + _hc5[16]*_t78 - _t19*_t592 + _t25*_t595 + _t593;
  const double _t597 = -_hc5[8]*_t207;
  const double _t598 = _hc5[6]*_t117;
  const double _t599 = 0.2e1*_t234;
  const double _t600 = _hc5[16]*_t68;
  const double _t601 = _hc5[28]*_t19;
  const double _t602 = _hc4[2]*_t562;
  const double _t603 = _hc4[1]*_t221;
  const double _t604 = _hc4[1]*_t317;
  const double _t605 = 0.3e1*_t88;
  const double _t606 = _t117*_t605;
  const double _t607 = 0.3e1*_t248;
  const double _t608 = -_hc4[5]*_t207;
  const double _t609 = _hc4[4]*_t117;
  const double _t610 = 0.2e1*_t243;
  const double _t611 = _hc4[9]*_t68;
  const double _t612 = -_hc4[14]*_t19;
  const double _t613 = -_hc4[13]*_t19;
  const double _t614 = _hc4[12]*_t25 + _t613;
  const double _t615 = _hc4[8]*_t68;
  const double _t616 = -_hc4[12]*_t19;
  const double _t617 = _hc4[11]*_t25 + _t616;
  const double _t618 = _hc4[7]*_t76 + _hc4[7]*_t78 - _t19*_t614 + _t25*_t617 + _t615;
  const double _t619 = -_hc4[4]*_t207;
  const double _t620 = _hc4[3]*_t117;
  const double _t621 = 0.2e1*_t247;
  const double _t622 = _hc4[7]*_t68;
  const double _t623 = -_hc4[11]*_t19;
  const double _t624 = _hc1[2]*_t562;
  const double _t625 = _hc0[1]*_t566;
  const double _t626 = _hc0[4]*(_t31 * _t31 * _t31 * _t31);
  const double _t627 = _hc0[2]*(_t74 * _t74);
  const double _t630 = _hc0[2]*_t74;
  const double _t631 = _t220*_t630;
  const double _t634 = _t341*_t94;
  const double _t639 = 0.3e1*_t257;
  const double _t640 = 0.3e1*_t255;
  const double _t641 = 0.3e1*_t131;
  const double _t642 = _t641*_t99;
  const double _t643 = _hc0[1]*_t638;
  const double _t644 = _hc1[6]*_t261 + _t271;
  const double _t645 = -0.1e1 / 0.36e2*_hc1[8]*_t17*_t6*_t7;
  const double _t646 = _hc1[7]*_t261;
  const double _t647 = 0.3e1*_t95;
  const double _t648 = 0.3e1*_t93;
  const double _t649 = -_hc1[5]*_t207;
  const double _t650 = _hc1[4]*_t131;
  const double _t651 = _hc1[9]*_t68;
  const double _t652 = -_hc1[14]*_t19;
  const double _t653 = -_hc1[13]*_t19;
  const double _t654 = _hc1[12]*_t32 + _t653;
  const double _t655 = _hc1[8]*_t68;
  const double _t656 = -_hc1[12]*_t19;
  const double _t657 = _hc1[11]*_t32 + _t656;
  const double _t658 = _hc1[7]*_t93 + _hc1[7]*_t95 - _t19*_t654 + _t32*_t657 + _t655;
  const double _t659 = -_hc1[4]*_t207;
  const double _t660 = _hc1[3]*_t131;
  const double _t661 = _hc1[7]*_t68;
  const double _t662 = -_hc1[11]*_t19;
  const double _t664 = _t104*_t561;
  const double _t665 = _t355*_t94;
  const double _t666 = _t112*_t641;
  const double _t667 = _hc0[1]*_hc2[13]*_t260 - _t304;
  const double _t668 = (0.2e1 / 0.9e1)*_hc2[15];
  const double _t670 = -_hc2[7]*_t207;
  const double _t671 = _hc2[5]*_t255;
  const double _t672 = _hc2[5]*_t257;
  const double _t673 = _hc2[5]*_t131;
  const double _t674 = _t673*_t74;
  const double _t675 = _t220*_t673;
  const double _t677 = _hc2[14]*_t68;
  const double _t678 = _hc2[11]*_t93;
  const double _t679 = _hc2[11]*_t95;
  const double _t680 = _hc2[25]*_t19;
  const double _t681 = _hc2[29]*_t19;
  const double _t682 = _hc0[1]*_hc2[26]*_t31 - _hc2[25]*_t36 - _t681;
  const double _t683 = _hc2[26]*_t19;
  const double _t684 = _hc0[1]*_hc2[22]*_t31 - _hc2[21]*_t36 - _t683;
  const double _t685 = _hc2[17]*_t68;
  const double _t686 = _hc2[15]*_t93;
  const double _t687 = _hc2[15]*_t95;
  const double _t688 = _hc2[32]*_t19;
  const double _t689 = _hc0[1]*_hc2[30]*_t31 - _hc2[29]*_t36 - _t688;
  const double _t690 = _hc2[30]*_t19;
  const double _t691 = _hc0[1]*_hc2[27]*_t31 - _hc2[26]*_t36 - _t690;
  const double _t692 = _hc2[14]*_t284 - _t19*_t689 + _t32*_t691 - _t36*_t682 + _t685 + _t686 + _t687;
  const double _t693 = _t223*_t668;
  const double _t694 = _hc2[12]*_t93;
  const double _t695 = _hc2[12]*_t95;
  const double _t696 = _hc2[27]*_t19;
  const double _t697 = _hc0[1]*_hc2[23]*_t31 - _hc2[22]*_t36 - _t696;
  const double _t698 = _hc2[11]*_t284 - _t19*_t691 + _t32*_t697 - _t36*_t684 + _t693 + _t694 + _t695;
  const double _t699 = -_hc2[9]*_t207;
  const double _t700 = _hc2[8]*_t131;
  const double _t701 = _hc2[19]*_t68;
  const double _t702 = _hc2[34]*_t19;
  const double _t703 = _hc2[33]*_t19;
  const double _t704 = _hc0[1]*_hc2[31]*_t31 - _hc2[30]*_t36 - _t703;
  const double _t705 = _hc2[18]*_t68;
  const double _t706 = _hc2[31]*_t19;
  const double _t707 = _hc0[1]*_hc2[28]*_t31 - _hc2[27]*_t36 - _t706;
  const double _t708 = _hc2[15]*_t284 + _hc2[16]*_t93 + _hc2[16]*_t95 - _t19*_t704 + _t32*_t707 - _t36*_t691 + _t705;
  const double _t709 = -_hc2[8]*_t207;
  const double _t710 = _hc2[6]*_t131;
  const double _t711 = _hc2[16]*_t68;
  const double _t712 = _hc2[28]*_t19;
  const double _t713 = 0.3e1*_t122;
  const double _t714 = 0.3e1*_t128;
  const double _t716 = -_hc3[1]*_t715;
  const double _t717 = _hc4[3]*_t41;
  const double _t718 = _hc4[11]*_t47 + _t616;
  const double _t719 = _hc4[12]*_t47 + _t613;
  const double _t720 = -_t19*_t719 + _t615;
  const double _t721 = -_hc4[7]*_t119 + _hc4[7]*_t318 + _t25*_t718 + _t720;
  const double _t722 = _hc4[10]*_t47 + _t623;
  const double _t723 = -_t19*_t718 + _t622;
  const double _t724 = 0.2e1*_t325;
  const double _t726 = _t116*_t117;
  const double _t727 = _hc3[4]*_t215;
  const double _t728 = _t238*_t41;
  const double _t730 = _hc4[4]*_t41;
  const double _t731 = -_t19*(_hc4[13]*_t47 + _t612) + _t611;
  const double _t732 = _t316*_t382;
  const double _t734 = _t117*_t733;
  const double _t735 = _t315*_t73;
  const double _t736 = _hc3[2]*_t73;
  const double _t737 = _t224*_t322 + _t602;
  const double _t738 = _t125*_t382;
  const double _t739 = _t225*_t41;
  const double _t740 = _t117*_t124;
  const double _t741 = _t224*_t330;
  const double _t742 = 0.2e1*_t333;
  const double _t743 = _hc5[8]*_t41;
  const double _t744 = _hc3[1]*_hc5[31]*_t41 - _hc5[30]*_t123 - _t591;
  const double _t745 = -_t19*(_hc3[1]*_hc5[33]*_t41 - _hc5[32]*_t123 - _t590) + _t589;
  const double _t746 = _hc3[1]*_hc5[28]*_t41 - _hc5[27]*_t123 - _t594;
  const double _t747 = -_t19*_t744 + _t593;
  const double _t748 = -_hc5[16]*_t119 + _hc5[16]*_t318 + _t25*_t746 + _t747;
  const double _t749 = _hc5[6]*_t41;
  const double _t750 = _hc3[1]*_hc5[24]*_t41 - _hc5[23]*_t123 - _t601;
  const double _t751 = -_t19*_t746 + _t600;
  const double _t752 = 0.3e1*_t143;
  const double _t753 = 0.3e1*_t136;
  const double _t754 = _hc0[1]*_t715;
  const double _t755 = _hc0[3]*_t340;
  const double _t756 = _hc1[6]*_t344 + _t271;
  const double _t757 = _hc1[11]*_t43 + _t656;
  const double _t758 = _hc1[12]*_t43 + _t653;
  const double _t759 = -_t19*_t758 + _t655;
  const double _t760 = _hc1[7]*_t132 + _hc1[7]*_t133 + _t32*_t757 + _t759;
  const double _t761 = _hc1[10]*_t43 + _t662;
  const double _t762 = -_t19*_t757 + _t661;
  const double _t763 = 0.2e1*_t338;
  const double _t764 = _hc0[2]*_t260*_t339;
  const double _t765 = _hc1[7]*_t344;
  const double _t766 = _t18*(-_t645 - 0.1e1 / 0.6e1*_t765) + _t273;
  const double _t768 = _t130*_t131;
  const double _t770 = _hc0[4]*_hc1[1];
  const double _t771 = 0.2e1*_t343;
  const double _t772 = 0.2e1*_t755;
  const double _t773 = _t268 + _t765;
  const double _t774 = -_t19*(_hc1[13]*_t43 + _t652) + _t651;
  const double _t776 = _t341*_t775;
  const double _t777 = _hc0[2]*_hc1[1];
  const double _t779 = _t630*_t73;
  const double _t780 = _t131*_t733;
  const double _t781 = _t224*_t349 + _t624;
  const double _t782 = _hc2[13]*_t344 + _t373;
  const double _t783 = _hc2[23]*_t43;
  const double _t784 = -_t696 + _t783;
  const double _t785 = _hc2[22]*_t43;
  const double _t786 = -_t683 + _t785;
  const double _t787 = _hc2[12]*_t132;
  const double _t788 = _hc2[27]*_t43;
  const double _t789 = -_t690 + _t788;
  const double _t790 = -_t19*_t789 + _t693;
  const double _t791 = _hc2[12]*_t133 + _t32*_t784 - _t36*_t786 + _t787 + _t790;
  const double _t792 = _hc2[28]*_t43 - _t706;
  const double _t793 = _hc2[31]*_t43 - _t703;
  const double _t794 = -_t19*_t793 + _t705;
  const double _t795 = _hc2[16]*_t132 + _hc2[16]*_t133 + _t32*_t792 - _t36*_t789 + _t794;
  const double _t796 = _hc2[24]*_t43 - _t712;
  const double _t797 = -_t19*_t792 + _t711;
  const double _t798 = _hc2[16]*_t344;
  const double _t799 = _t18*((0.1e1 / 0.36e2)*_hc2[18]*_t17*_t6*_t7 - 0.1e1 / 0.6e1*_t798);
  const double _t800 = _hc2[12]*_t344;
  const double _t801 = _hc2[5]*_t338;
  const double _t802 = _hc2[5]*_t755;
  const double _t803 = _hc2[5]*_t343;
  const double _t804 = _t357 + _t800;
  const double _t805 = _hc2[21]*_t43;
  const double _t806 = _hc2[11]*_t132;
  const double _t807 = _hc2[26]*_t43;
  const double _t808 = -_t681 + _t807;
  const double _t809 = -_t19*_t808 + _t677;
  const double _t810 = _hc2[15]*_t132;
  const double _t811 = _hc2[30]*_t43;
  const double _t812 = -_t688 + _t811;
  const double _t813 = -_t19*_t812 + _t685;
  const double _t814 = _hc2[15]*_t133 + _t32*_t789 - _t36*_t808 + _t810 + _t813;
  const double _t815 = _t131*_t138;
  const double _t816 = _hc0[4]*_hc2[2];
  const double _t817 = _t367 + _t798;
  const double _t818 = -_t19*(_hc2[33]*_t43 - _t702) + _t701;
  const double _t819 = _t355*_t775;
  const double _t820 = _hc0[2]*_hc2[2];
  const double _t821 = _t224*_t371 + _t664;
  const double _t822 = _hc3[1]*_t565;
  const double _t823 = -_hc4[1]*_t822;
  const double _t824 = _hc4[6]*_t155 + _hc4[6]*_t157 + _t47*_t722 + _t723;
  const double _t825 = 0.2e1*_t323;
  const double _t826 = _hc3[2]*_t717;
  const double _t827 = _hc4[7]*_t155 + _hc4[7]*_t157 + _t47*_t718 + _t720;
  const double _t828 = -_t19*_t827 + _t224*_t319 + _t619;
  const double _t829 = _t154*_t315;
  const double _t830 = _t117*_t154;
  const double _t831 = _hc3[3]*_t75;
  const double _t832 = _hc4[1]*_t156;
  const double _t833 = _hc3[4]*_t77;
  const double _t835 = _t385*_t41;
  const double _t837 = _hc3[2]*_t836;
  const double _t838 = 0.2e1*_t319;
  const double _t839 = _hc3[2]*_t730;
  const double _t840 = -_t19*(_hc4[8]*_t155 + _hc4[8]*_t157 + _t47*_t719 + _t731) + _t224*_t320 + _t608;
  const double _t841 = _hc3[2]*_t41;
  const double _t842 = _t219*_t841;
  const double _t843 = _hc3[1]*_hc5[23]*_t41 - _hc5[22]*_t123 - _hc5[27]*_t19;
  const double _t844 = _hc5[12]*_t392 + _hc5[13]*_t155 + _hc5[13]*_t157 - _t123*_t843 + _t47*_t750 + _t751;
  const double _t845 = 0.2e1*_t331;
  const double _t846 = _hc3[2]*_t749;
  const double _t847 = _hc3[1]*_hc5[27]*_t41 - _hc5[26]*_t123 - _hc5[30]*_t19;
  const double _t848 = _hc5[15]*_t392 + _hc5[16]*_t155 + _hc5[16]*_t157 - _t123*_t847 + _t47*_t746 + _t747;
  const double _t849 = -_t19*_t848 + _t224*_t327 + _t597;
  const double _t850 = _t395*_t41;
  const double _t851 = 0.2e1*_t327;
  const double _t852 = _hc3[2]*_t743;
  const double _t853 = _hc3[1]*_hc5[30]*_t41 - _hc5[29]*_t123 - _hc5[32]*_t19;
  const double _t854 = -_t19*(_hc5[17]*_t392 + _hc5[18]*_t155 + _hc5[18]*_t157 - _t123*_t853 + _t47*_t744 + _t745) + _t224*_t328 + _t586;
  const double _t855 = -_hc5[2]*_t822 + _t563;
  const double _t856 = _hc0[1]*_t565;
  const double _t857 = _hc1[1]*_t856;
  const double _t858 = _hc1[6]*_t147 + _hc1[6]*_t149 + _t43*_t761 + _t762;
  const double _t859 = _hc0[3]*_t405;
  const double _t860 = _hc1[3]*_t342;
  const double _t861 = _hc1[7]*_t147 + _hc1[7]*_t149 + _t43*_t757 + _t759;
  const double _t862 = -_t19*_t861 + _t224*_t346 + _t659;
  const double _t864 = _hc0[1]*_t863;
  const double _t865 = _hc1[3]*_t864 + _t344*_t756 + _t402 + _t766;
  const double _t866 = _t146*_t630;
  const double _t867 = _t131*_t146;
  const double _t871 = _hc1[4]*_t342;
  const double _t872 = -_t19*(_hc1[8]*_t147 + _hc1[8]*_t149 + _t43*_t758 + _t774) + _t224*_t347 + _t649;
  const double _t873 = _t219*_t342;
  const double _t874 = _hc2[2]*_t856;
  const double _t875 = _hc2[13]*_t147 + _hc2[13]*_t149 + _t43*_t796 + _t797;
  const double _t876 = _hc2[12]*_t147;
  const double _t877 = _hc2[12]*_t149;
  const double _t878 = _t43*_t784 + _t790 + _t876 + _t877;
  const double _t879 = _hc2[6]*_t342;
  const double _t880 = _hc2[16]*_t147 + _hc2[16]*_t149 + _t43*_t792 + _t794;
  const double _t881 = -_t19*_t880 + _t224*_t368 + _t709;
  const double _t882 = _hc2[6]*_t864 + _t344*_t782 + _t413 + _t799;
  const double _t883 = _hc2[11]*_t147;
  const double _t884 = _hc2[11]*_t149;
  const double _t885 = _t146*_t673;
  const double _t886 = _hc2[5]*_t859;
  const double _t887 = _hc2[5]*_t342;
  const double _t888 = _hc2[15]*_t147;
  const double _t889 = _hc2[15]*_t149;
  const double _t890 = _t43*_t789 + _t813 + _t888 + _t889;
  const double _t891 = -_t19*_t890 + _t224*_t364 + _t670;
  const double _t892 = _hc2[8]*_t342;
  const double _t893 = -_t19*(_hc2[18]*_t147 + _hc2[18]*_t149 + _t43*_t793 + _t818) + _t224*_t369 + _t699;
  const double _t894 = _hc1[3]*_t427 + _hc1[3]*_t429 + _t146*_t860 + _t350*_t430 + _t43*_t858 + _t431*_t756 + _t432*_t860 + _t862;
  const double _t895 = _hc0[1]*_t209;
  const double _t896 = _hc0[1]*_t571;
  const double _t899 = _hc0[1]*_t898;
  const double _t900 = 0.3e1*_t132;
  const double _t902 = 0.3e1*_t859;
  const double _t903 = _hc0[1]*_t577;
  const double _t905 = _t148*_t341;
  const double _t906 = _t130*_t342;
  const double _t908 = -_t134*_t581 - _t19*(_hc1[4]*_t427 + _hc1[4]*_t429 + _t146*_t871 + _t346*_t430 + _t43*_t861 + _t431*_t773 + _t432*_t871 + _t872) + _t410*_t584 + _t624;
  const double _t909 = _hc2[6]*_t427 + _hc2[6]*_t429 + _t146*_t879 + _t374*_t430 + _t43*_t875 + _t431*_t782 + _t432*_t879 + _t881;
  const double _t910 = _hc2[5]*_t427;
  const double _t911 = _hc2[5]*_t429;
  const double _t912 = _t146*_t887;
  const double _t913 = _t432*_t887;
  const double _t914 = _t148*_t355;
  const double _t915 = _t138*_t342;
  const double _t916 = -_t141*_t581 - _t19*(_hc2[8]*_t427 + _hc2[8]*_t429 + _t146*_t892 + _t368*_t430 + _t43*_t880 + _t431*_t817 + _t432*_t892 + _t893) + _t419*_t584 + _t664;
  const double _t917 = _hc4[3]*_t438 + _hc4[3]*_t440 + _t154*_t826 + _t155*_t825 + _t157*_t825 + _t441*_t826 + _t47*_t824 + _t828;
  const double _t918 = _hc3[1]*_t571;
  const double _t919 = _hc3[1]*_t209;
  const double _t920 = _hc3[4]*_t24*_t439;
  const double _t921 = _hc3[1]*_t577;
  const double _t922 = 0.3e1*_t380;
  const double _t924 = 0.3e1*_t116;
  const double _t925 = _hc3[1]*_t898;
  const double _t926 = _t841*_t907;
  const double _t927 = _hc3[2]*_t154;
  const double _t928 = _t577*_t927;
  const double _t929 = _hc3[3]*_t832;
  const double _t930 = -_t120*_t581 - _t19*(_hc4[4]*_t438 + _hc4[4]*_t440 + _t154*_t839 + _t155*_t838 + _t157*_t838 + _t441*_t839 + _t47*_t827 + _t840) + _t388*_t584 + _t602;
  const double _t932 = _hc5[12]*_t157;
  const double _t933 = _hc5[12]*_t155;
  const double _t934 = _hc3[1]*_hc5[22]*_t41 - _hc5[21]*_t123 - _hc5[26]*_t19;
  const double _t935 = _hc5[11]*_t392 + _hc5[15]*_t68 - _t123*_t934 - _t19*_t847 + _t47*_t843 + _t932 + _t933;
  const double _t937 = -_hc5[5]*_t931 + _hc5[6]*_t438 + _hc5[6]*_t440 - _t123*_t935 + _t154*_t846 + _t155*_t845 + _t157*_t845 + _t391*_t936 + _t441*_t846 + _t47*_t844 + _t849;
  const double _t938 = 0.3e1*_t393;
  const double _t939 = 0.3e1*_t124;
  const double _t940 = _hc3[3]*_t394;
  const double _t941 = _hc5[15]*_t157;
  const double _t942 = _hc5[15]*_t155;
  const double _t943 = _hc3[1]*_hc5[26]*_t41 - _hc5[25]*_t123 - _hc5[29]*_t19;
  const double _t944 = _hc5[14]*_t392 + _hc5[17]*_t68 - _t123*_t943 - _t19*_t853 + _t47*_t847 + _t941 + _t942;
  const double _t945 = -_t126*_t581 - _t19*(-_hc5[7]*_t931 + _hc5[8]*_t438 + _hc5[8]*_t440 - _t123*_t944 + _t154*_t852 + _t155*_t851 + _t157*_t851 + _t397*_t936 + _t441*_t852 + _t47*_t848 + _t854) + _t398*_t584;
  const double _t947 = _hc0[1]*_t946;
  const double _t948 = _hc0[2]*(_t146 * _t146);
  const double _t949 = _hc0[4]*(_t42 * _t42 * _t42 * _t42);
  const double _t950 = 0.3e1*_t427;
  const double _t951 = 0.3e1*_t147;
  const double _t952 = 0.3e1*_t149;
  const double _t953 = 0.3e1*_t429;
  const double _t961 = -_hc3[1]*_t946;
  const double _t962 = _hc3[2]*(_t154 * _t154);
  const double _t963 = _hc3[4]*(_t41 * _t41 * _t41 * _t41);
  const double _t964 = _hc3[2]*_t441;
  const double _t965 = _t154*_t964;
  const double _t968 = _t41*_t924;
  const double _t969 = _hc5[5]*_t440;
  const double _t970 = _hc5[5]*_t438;
  const double _t971 = _hc5[5]*_t41;
  const double _t972 = _t964*_t971;
  const double _t973 = _t927*_t971;
  const double _t974 = 0.2e1*_t391;
  const double _t975 = _hc5[11]*_t157;
  const double _t976 = _hc5[11]*_t155;
  const double _t978 = _t41*_t939;
  const double _t980 = -_t171*_t979;
  const double _t983 = _hc2[14]*_t982;
  const double _t984 = _hc2[25]*_t460;
  const double _t985 = _hc2[29]*_t460;
  const double _t986 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[26]*_t11*_t31*_t56 - _hc2[14]*_t459 - _hc2[25]*_t167 - _t985;
  const double _t987 = _hc2[26]*_t460;
  const double _t988 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[22]*_t11*_t31*_t56 - _hc2[11]*_t459 - _hc2[21]*_t167 - _t987;
  const double _t989 = _hc2[17]*_t982;
  const double _t990 = _hc2[32]*_t460;
  const double _t991 = _hc2[30]*_t460;
  const double _t992 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[27]*_t11*_t31*_t56 - _hc2[15]*_t459 - _hc2[26]*_t167 - _t991;
  const double _t993 = _hc2[15]*_t982;
  const double _t994 = _hc2[27]*_t460;
  const double _t995 = -_hc5[7]*_t176*_t979;
  const double _t996 = _t117*_t472;
  const double _t997 = 0.2e1*_t477;
  const double _t998 = _hc5[17]*_t470;
  const double _t999 = _hc5[15]*_t504;
  const double _t1000 = _hc5[32]*_t177;
  const double _t1001 = _hc5[30]*_t177;
  const double _t1002 = _hc5[27]*_t474 - _t1001;
  const double _t1003 = _hc5[15]*_t470;
  const double _t1004 = _hc5[12]*_t504;
  const double _t1005 = _hc5[27]*_t177;
  const double _t1006 = 0.2e1*_t489;
  const double _t1008 = _t183*_t800 + _t480;
  const double _t1009 = _t183*_t785 - _t987;
  const double _t1010 = _t2*_t484;
  const double _t1011 = _t183*_t807 - _t985;
  const double _t1012 = -_t1011*_t19 + _t983;
  const double _t1013 = _t183*_t788 - _t991;
  const double _t1014 = -_t19*(_t183*_t811 - _t990) + _t989;
  const double _t1015 = _t183*_t783 - _t994;
  const double _t1016 = -_t1013*_t19 + _t993;
  const double _t1017 = 0.2e1*_t497;
  const double _t1018 = _t504*_t971;
  const double _t1019 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[27]*_t13*_t41*_t61 - _hc5[15]*_t490 - _hc5[26]*_t187 - _t1001;
  const double _t1020 = _t2*_t492;
  const double _t1021 = _t1020*_t176;
  const double _t1022 = -_t19*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[30]*_t13*_t41*_t61 - _hc5[17]*_t490 - _hc5[29]*_t187 - _t1000) + _t998;
  const double _t1023 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[23]*_t13*_t41*_t61 - _hc5[12]*_t490 - _hc5[22]*_t187 - _t1005;
  const double _t1024 = _t1003 - _t1019*_t19;
  const double _t1025 = _t1015*_t43 + _t1016 + _t183*_t876 + _t183*_t877;
  const double _t1027 = -_t19*(_t1013*_t43 + _t1014 + _t183*_t888 + _t183*_t889) + _t224*_t486 + _t980;
  const double _t1028 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[22]*_t13*_t41*_t61 - _hc5[11]*_t490 - _hc5[21]*_t187 - _hc5[26]*_t177;
  const double _t1030 = _hc5[11]*_t501 + _hc5[5]*_t1029 + _t1023*_t47 + _t1024 - _t1028*_t123 - _t391*_t490 + _t504*_t932 + _t504*_t933;
  const double _t1031 = 0.2e1*_t491;
  const double _t1032 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[26]*_t13*_t41*_t61 - _hc5[14]*_t490 - _hc5[25]*_t187 - _hc5[29]*_t177;
  const double _t1033 = -_t19*(_hc5[14]*_t501 + _hc5[7]*_t1029 + _t1019*_t47 + _t1022 - _t1032*_t123 - _t397*_t490 + _t504*_t941 + _t504*_t942) + _t224*_t494 + _t995;
  const double _t1037 = -0.1e1 / 0.24e2*_hc2[15]*_t11*_t17*_t191*_t6*_t7 + _hc2[26]*_t1036;
  const double _t1038 = _hc2[11]*_t32;
  const double _t1039 = -0.1e1 / 0.24e2*_hc2[14]*_t11*_t17*_t191*_t6*_t7 + _hc2[25]*_t1036;
  const double _t1041 = -0.1e1 / 0.24e2*_hc2[17]*_t11*_t17*_t191*_t6*_t7 + _hc2[29]*_t1036;
  const double _t1043 = _hc2[7]*_t1042*_t530;
  const double _t1044 = _hc2[14]*_t1042*_t513 - _t1043;
  const double _t1045 = _t525*_t526;
  const double _t1046 = -0.1e1 / 0.24e2*_hc5[15]*_t13*_t17*_t197*_t6*_t7 + _hc5[26]*_t523;
  const double _t1047 = -0.1e1 / 0.24e2*_hc5[17]*_t13*_t17*_t197*_t6*_t7 + _hc5[29]*_t523;
  const double _t1048 = (0.1e1 / 0.4e1)*_t527;
  const double _t1050 = _hc5[11]*_t1049;
  const double _t1051 = _hc5[7]*_t1042*_t525;
  const double _t1052 = _hc5[14]*_t1042*_t522 - _t1051;
  const double _t1053 = _t19*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[26]*_t194*_t195*_t42 - _t1041 - _t363*_t532);
  const double _t1054 = (0.1e1 / 0.4e1)*_hc0[1]*_hc2[22]*_t194*_t195*_t42 - _t1037 - _t358*_t532;
  const double _t1057 = _t19*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[26]*_t200*_t201*_t41 - _hc5[14]*_t1055 - _hc5[15]*_t47*_t538 - _hc5[25]*_t1056 + (0.1e1 / 0.3e1)*_hc5[7]*_t197*_t50 - _t1047);
  const double _t1058 = (0.1e1 / 0.4e1)*_hc3[1]*_hc5[22]*_t200*_t201*_t41 - _hc5[11]*_t1055 - _hc5[12]*_t47*_t538 - _hc5[21]*_t1056 + (0.1e1 / 0.3e1)*_hc5[5]*_t197*_t50 - _t1046;
  const double _t1059 = _hc5[11]*_t47;
  const double _t1060 = _t11*_t543;
  const double _t1061 = _hc2[10]*_t547;
  const double _t1062 = _t195*_t549;
  const double _t1066 = -0.1e1 / 0.16e2*_hc2[14]*_t17*_t195*_t548*_t6*_t7 + _hc2[25]*_t1065*_t546 + _hc2[7]*_t1064*_t11*_t541;
  const double _t1067 = _t13*_t553;
  const double _t1068 = _hc5[10]*_t557;
  const double _t1069 = _t201*_t559;
  const double _t1071 = -0.1e1 / 0.16e2*_hc5[14]*_t17*_t201*_t558*_t6*_t7 + _hc5[25]*_t1065*_t556 + _hc5[7]*_t1064*_t13*_t551;
  const double d4F_dna4 = 0.4e1*_t250 + _t3*(my_piecewise3(_t14, 0, _hc1[0]*(_hc2[2]*_t625 + _hc2[2]*_t626 + _hc2[2]*_t627 + _hc2[2]*_t631 + (0.28e2 / 0.3e1)*_t10*_t102*_t295 + (0.3640e4 / 0.81e2)*_t101*_t663 - _t109*_t581 + _t112*_t640 - _t19*(-_hc2[7]*_t669 + _hc2[8]*_t255 + _hc2[8]*_t257 - _t19*(_hc2[17]*_t284 + _hc2[18]*_t93 + _hc2[18]*_t95 - _t19*(_hc0[1]*_hc2[33]*_t31 - _hc2[32]*_t36 - _t702) + _t32*_t704 - _t36*_t689 + _t701) + _t220*_t700 + _t224*_t298 + _t263*(_hc0[1]*_hc2[16]*_t260 - _t300) + _t264*_t301 + _t291*_t676 + _t32*_t708 - _t36*_t692 + _t699 + _t700*_t74) + _t220*_t666 - 0.280e3 / 0.9e1*_t277*_t281 + _t280*_t628 + _t280*_t629 + _t283*_t639 + _t302*_t584 + _t308*_t648 + _t32*(-_hc2[5]*_t669 + _hc2[6]*_t255 + _hc2[6]*_t257 - _t19*_t708 + _t220*_t710 + _t224*_t301 + _t263*_t667 + _t264*_t305 + _t294*_t676 + _t32*(_hc2[12]*_t284 + _hc2[13]*_t93 + _hc2[13]*_t95 - _t19*_t707 + _t32*(_hc0[1]*_hc2[24]*_t31 - _hc2[23]*_t36 - _t712) - _t36*_t697 + _t711) - _t36*_t698 + _t709 + _t710*_t74) - _t36*(-_hc2[4]*_t669 - _t19*_t692 + _t224*_t291 + _t263*(_hc0[1]*_hc2[12]*_t260 - _t293) + _t264*_t294 + _t289*_t676 + _t32*_t698 - _t36*(_hc2[10]*_t284 - _t19*_t682 + _t32*_t684 - _t36*(_hc0[1]*_hc2[21]*_t31 - _hc2[20]*_t36 - _t680) + _t677 + _t678 + _t679) + _t670 + _t671 + _t672 + _t674 + _t675) + _t633*_t665 + _t636*_t665 + _t638*_t665 + _t647*(_hc2[6]*_t643 + _t18*(-0.1e1 / 0.6e1*_hc2[16]*_t261 + (0.1e1 / 0.36e2)*_hc2[18]*_t18 + _t35*_t668) + _t261*_t667 + _t307 + _t35*((0.16e2 / 0.9e1)*_hc2[11]*_t35 - 0.4e1 / 0.3e1*_hc2[12]*_t261 + _t18*_t668)) + _t664 + _t666*_t74) + _hc2[0]*(_hc1[1]*_t625 + _hc1[1]*_t626 + _hc1[1]*_t627 + _hc1[1]*_t631 - _t19*(_hc1[4]*_t255 + _hc1[4]*_t257 - _t19*(_hc1[8]*_t93 + _hc1[8]*_t95 - _t19*(_hc1[13]*_t32 + _t652) + _t32*_t654 + _t651) + _t220*_t650 + _t224*_t267 + _t263*(_t268 + _t646) + _t264*_t269 + _t32*_t658 + _t649 + _t650*_t74) + _t220*_t642 + _t258*_t628 + _t258*_t629 + _t262*_t639 + _t270*_t584 + _t275*_t648 + _t32*(_hc1[3]*_t255 + _hc1[3]*_t257 - _t19*_t658 + _t220*_t660 + _t224*_t269 + _t263*_t644 + _t264*_t272 + _t32*(_hc1[6]*_t93 + _hc1[6]*_t95 - _t19*_t657 + _t32*(_hc1[10]*_t32 + _t662) + _t661) + _t659 + _t660*_t74) - _t581*_t97 + _t624 + _t633*_t634 + _t634*_t636 + _t634*_t638 + _t640*_t99 + _t642*_t74 + _t647*(_hc1[3]*_t643 + _t18*(-_t645 - 0.1e1 / 0.6e1*_t646) + _t261*_t644 + _t274)) + 0.6e1*_t100*_t113 + 0.4e1*_t276*_t38 + 0.4e1*_t309*_t33) + my_piecewise3(_t15, 0, _hc4[0]*(_hc5[2]*_t567 + _hc5[2]*_t568 + _hc5[2]*_t569 - _t19*(_hc5[8]*_t214 + _hc5[8]*_t216 - _t19*(_hc5[18]*_t76 + _hc5[18]*_t78 - _t19*(_hc5[33]*_t25 - _t590) + _t25*_t592 + _t589) + _t221*_t587 + _t224*_t228 + _t25*_t596 + _t586 + _t587*_t75 + _t588*_t76 + _t588*_t78) + _t214*_t582 + _t216*_t582 + _t221*_t583 + _t222*_t573 + _t222*_t574 + _t231*_t584 + _t25*(_hc5[6]*_t214 + _hc5[6]*_t216 - _t19*_t596 + _t221*_t598 + _t224*_t230 + _t25*(_hc5[13]*_t76 + _hc5[13]*_t78 - _t19*_t595 + _t25*(_hc5[24]*_t25 - _t601) + _t600) + _t597 + _t598*_t75 + _t599*_t76 + _t599*_t78) + _t315*_t575 + _t317*_t575 + _t563 + _t578*_t579 + _t579*_t75 - _t581*_t80 + _t583*_t75 + _t585*_t76 + _t585*_t78) + _hc5[0]*(_hc4[1]*_t567 + _hc4[1]*_t568 + _hc4[1]*_t569 + _t118*_t573 + _t118*_t574 - _t19*(_hc4[4]*_t214 + _hc4[4]*_t216 - _t19*(_hc4[8]*_t76 + _hc4[8]*_t78 - _t19*(_hc4[13]*_t25 + _t612) + _t25*_t614 + _t611) + _t221*_t609 + _t224*_t241 + _t25*_t618 + _t608 + _t609*_t75 + _t610*_t76 + _t610*_t78) + _t214*_t605 + _t216*_t605 + _t221*_t606 + _t244*_t584 + _t25*(_hc4[3]*_t214 + _hc4[3]*_t216 - _t19*_t618 + _t221*_t620 + _t224*_t243 + _t25*(_hc4[6]*_t76 + _hc4[6]*_t78 - _t19*_t617 + _t25*(_hc4[10]*_t25 + _t623) + _t622) + _t619 + _t620*_t75 + _t621*_t76 + _t621*_t78) + _t315*_t603 + _t317*_t603 + _t578*_t604 - _t581*_t86 + _t602 + _t604*_t75 + _t606*_t75 + _t607*_t76 + _t607*_t78) + 0.4e1*_t236*_t28 + 0.4e1*_t249*_t26 + 0.6e1*_t83*_t89)) + 0.4e1*_t310;
  const double d4F_dna3_dnb = _t3*(my_piecewise3(_t14, 0, _hc1[0]*(_hc2[2]*_t754 + _hc2[2]*_t779 - _t109*_t729 + _t112*_t763 + _t112*_t771 + _t112*_t780 + _t132*_t308 + _t133*_t308 + _t138*_t255 - _t140*_t669 - _t141*_t207 - _t19*(_hc2[8]*_t338 + _hc2[8]*_t343 + _hc2[8]*_t755 + _t132*_t301 + _t133*_t301 - _t19*(_hc2[18]*_t132 + _hc2[18]*_t133 + _t32*_t793 - _t36*_t812 + _t818) + _t219*_t700 + _t284*_t364 + _t298*_t68 + _t32*_t795 - _t36*_t814 + _t368*_t93 + _t369*_t68 + _t699 + _t817*_t95) + _t220*_t815 + _t220*_t819 + _t254*_t418 + _t257*_t356 + _t263*(_hc2[6]*_t764 + _t261*_t782 + _t35*((0.2e1 / 0.9e1)*_hc2[15]*_t17*_t6*_t7 - 0.4e1 / 0.3e1*_t800) + _t375 + _t799) + _t264*_t376 + _t280*_t337 + _t280*_t767 + _t283*_t772 + _t302*_t68 + _t32*(_hc2[6]*_t338 + _hc2[6]*_t343 + _hc2[6]*_t755 + _t132*_t305 + _t133*_t305 - _t19*_t795 + _t219*_t710 + _t284*_t359 + _t301*_t68 + _t32*(_hc2[13]*_t132 + _hc2[13]*_t133 + _t32*_t796 - _t36*_t784 + _t797) - _t36*_t791 + _t368*_t68 + _t374*_t93 + _t709 + _t782*_t95) - _t36*(_t132*_t294 + _t133*_t294 - _t19*_t814 + _t219*_t673 + _t284*_t361 + _t291*_t68 + _t32*_t791 + _t359*_t93 - _t36*(_hc2[11]*_t133 + _t32*_t786 - _t36*(-_t680 + _t805) + _t806 + _t809) + _t364*_t68 + _t670 + _t801 + _t802 + _t803 + _t804*_t95) + _t366*_t676 + _t577*_t665 + _t74*_t815 + _t74*_t819 + _t769*_t816 + _t778*_t820 + _t821) + _hc2[0]*(_hc1[1]*_t754 + _hc1[1]*_t779 + _t130*_t255 + _t132*_t275 + _t133*_t275 - _t134*_t207 - _t19*(_hc1[4]*_t338 + _hc1[4]*_t343 + _hc1[4]*_t755 + _t132*_t269 + _t133*_t269 - _t19*(_hc1[8]*_t132 + _hc1[8]*_t133 + _t32*_t758 + _t774) + _t219*_t650 + _t267*_t68 + _t32*_t760 + _t346*_t93 + _t347*_t68 + _t649 + _t773*_t95) + _t220*_t768 + _t220*_t776 + _t254*_t409 + _t257*_t345 + _t258*_t337 + _t258*_t767 + _t262*_t772 + _t263*(_hc1[3]*_t764 + _t261*_t756 + _t351 + _t766) + _t264*_t353 + _t270*_t68 + _t32*(_hc1[3]*_t338 + _hc1[3]*_t343 + _hc1[3]*_t755 + _t132*_t272 + _t133*_t272 - _t19*_t760 + _t219*_t660 + _t269*_t68 + _t32*(_hc1[6]*_t132 + _hc1[6]*_t133 + _t32*_t761 + _t762) + _t346*_t68 + _t350*_t93 + _t659 + _t756*_t95) + _t577*_t634 - _t729*_t97 + _t74*_t768 + _t74*_t776 + _t763*_t99 + _t769*_t770 + _t771*_t99 + _t777*_t778 + _t780*_t99 + _t781) + _t100*_t752 + _t113*_t753 + _t251*_t354 + _t252*_t377 + _t276*_t44 + _t309*_t45) + my_piecewise3(_t15, 0, _hc4[0]*(_hc5[2]*_t716 - _hc5[2]*_t735 - _t119*_t235 + _t124*_t214 + _t124*_t216 + _t125*_t727 - _t126*_t207 - _t19*(_hc5[8]*_t314 - _t119*_t230 - _t19*(-_hc5[18]*_t119 + _hc5[18]*_t318 + _t25*_t744 + _t745) - _t219*_t587 + _t228*_t68 + _t230*_t318 + _t25*_t748 + _t315*_t743 + _t317*_t743 + _t327*_t76 + _t327*_t78 + _t328*_t68 + _t586) + _t213*_t396 + _t221*_t738 + _t221*_t740 + _t222*_t313 + _t222*_t725 + _t225*_t314 + _t231*_t68 + _t235*_t318 + _t25*(_hc5[6]*_t314 - _t119*_t234 - _t19*_t748 - _t219*_t598 + _t230*_t68 + _t234*_t318 + _t25*(-_hc5[13]*_t119 + _hc5[13]*_t318 + _t25*_t750 + _t751) + _t315*_t749 + _t317*_t749 + _t327*_t68 + _t331*_t76 + _t331*_t78 + _t597) + _t315*_t739 + _t317*_t739 + _t563 - _t575*_t736 - _t577*_t579 - _t729*_t80 - _t734*_t82 + _t738*_t75 + _t740*_t75 + _t741 + _t742*_t76 + _t742*_t78) + _hc5[0]*(_hc4[1]*_t716 - _hc4[1]*_t735 + _t116*_t214 + _t116*_t216 + _t118*_t313 + _t118*_t725 - _t119*_t248 - _t120*_t207 - _t19*(_hc4[4]*_t314 - _t119*_t243 - _t19*(-_hc4[8]*_t119 + _hc4[8]*_t318 + _t25*_t719 + _t731) - _t219*_t609 + _t241*_t68 + _t243*_t318 + _t25*_t721 + _t315*_t730 + _t317*_t730 + _t319*_t76 + _t319*_t78 + _t320*_t68 + _t608) + _t213*_t387 + _t221*_t726 + _t221*_t732 + _t238*_t314 + _t244*_t68 + _t248*_t318 + _t25*(_hc4[3]*_t314 - _t119*_t247 - _t19*_t721 - _t219*_t620 + _t243*_t68 + _t247*_t318 + _t25*(-_hc4[6]*_t119 + _hc4[6]*_t318 + _t25*_t722 + _t723) + _t315*_t717 + _t317*_t717 + _t319*_t68 + _t323*_t76 + _t323*_t78 + _t619) + _t315*_t728 + _t316*_t727 + _t317*_t728 - _t577*_t604 - _t603*_t736 + _t724*_t76 + _t724*_t78 + _t726*_t75 - _t729*_t86 + _t732*_t75 - _t734*_t88 + _t737) + _t203*_t334 + _t204*_t326 + _t236*_t48 + _t249*_t52 + _t713*_t83 + _t714*_t89)) + _t311 + 0.3e1*_t335 + 0.3e1*_t378;
  const double d4F_dna2_dnb2 = _t3*(my_piecewise3(_t14, 0, _hc1[0]*(_hc2[2]*_t866 - _t109*_t207 - _t112*_t404 - _t112*_t406 + _t112*_t867 + _t112*_t873 + _t138*_t763 + _t138*_t771 - _t141*_t729 - _t19*(-_hc2[8]*_t404 - _hc2[8]*_t406 + _hc2[8]*_t859 + _t146*_t700 + _t219*_t892 + _t32*_t880 - _t36*_t890 + _t368*_t407 + _t368*_t408 + _t893) - _t218*_t280 - _t280*_t572 + _t283*_t859 + _t284*_t417 + _t32*(-_hc2[6]*_t404 - _hc2[6]*_t406 + _hc2[6]*_t859 + _t146*_t710 + _t219*_t879 + _t32*_t875 - _t36*_t878 + _t374*_t407 + _t374*_t408 + _t881) + _t355*_t868 + _t356*_t772 - _t36*(-_hc2[5]*_t404 - _hc2[5]*_t406 + _t219*_t887 + _t32*_t878 + _t359*_t407 + _t359*_t408 - _t36*(_t43*_t786 + _t809 + _t883 + _t884) + _t885 + _t886 + _t891) + _t376*_t407 + _t376*_t408 + _t414*_t93 + _t418*_t870 + _t419*_t68 + _t665*_t863 + _t733*_t815 + _t733*_t819 + _t816*_t869 + _t820*_t836 + _t821 + _t874 + _t882*_t95) + _hc2[0]*(_hc1[1]*_t866 + _t130*_t763 + _t130*_t771 - _t134*_t729 - _t19*(-_hc1[4]*_t404 - _hc1[4]*_t406 + _hc1[4]*_t859 + _t146*_t650 + _t219*_t871 + _t32*_t861 + _t346*_t407 + _t346*_t408 + _t872) - _t207*_t97 - _t218*_t258 - _t258*_t572 + _t262*_t859 + _t32*(-_hc1[3]*_t404 - _hc1[3]*_t406 + _hc1[3]*_t859 + _t146*_t660 + _t219*_t860 + _t32*_t858 + _t350*_t407 + _t350*_t408 + _t862) + _t341*_t868 + _t345*_t772 + _t353*_t407 + _t353*_t408 + _t403*_t93 - _t404*_t99 - _t406*_t99 + _t409*_t870 + _t410*_t68 + _t634*_t863 + _t733*_t768 + _t733*_t776 + _t770*_t869 + _t777*_t836 + _t781 + _t857 + _t865*_t95 + _t867*_t99 + _t873*_t99) + _t100*_t150 + _t113*_t151 + 0.4e1*_t136*_t143 + _t145*_t377 + 0.2e1*_t354*_t44 + 0.2e1*_t38*_t412 + _t421*_t91) + my_piecewise3(_t15, 0, _hc4[0]*(_hc5[2]*_t829 + _hc5[2]*_t837 - _t126*_t729 + _t154*_t579 - _t19*(_hc5[8]*_t381 + _hc5[8]*_t383 + _hc5[8]*_t386 + _t154*_t587 - _t219*_t852 + _t25*_t848 + _t318*_t851 - _t327*_t384 + _t854) - _t207*_t80 + _t218*_t222 + _t222*_t572 + _t25*(_hc5[6]*_t381 + _hc5[6]*_t383 + _hc5[6]*_t386 + _t154*_t598 - _t219*_t846 + _t25*_t844 + _t318*_t845 - _t331*_t384 + _t849) + _t314*_t395 + _t315*_t850 + _t317*_t850 + _t318*_t742 - _t333*_t384 + _t381*_t82 + _t383*_t82 + _t386*_t82 + _t393*_t76 + _t393*_t78 + _t394*_t831 + _t394*_t833 + _t396*_t834 + _t398*_t68 - _t733*_t738 - _t733*_t740 + _t741 + _t82*_t830 - _t82*_t842 + _t855) + _hc5[0]*(_hc4[1]*_t829 + _hc4[1]*_t837 + _t118*_t218 + _t118*_t572 - _t120*_t729 + _t154*_t604 - _t19*(_hc4[4]*_t381 + _hc4[4]*_t383 + _hc4[4]*_t386 + _t154*_t609 - _t219*_t839 + _t25*_t827 + _t318*_t838 - _t319*_t384 + _t840) - _t207*_t86 + _t25*(_hc4[3]*_t381 + _hc4[3]*_t383 + _hc4[3]*_t386 + _t154*_t620 - _t219*_t826 + _t25*_t824 + _t318*_t825 - _t323*_t384 + _t828) + _t314*_t385 + _t315*_t835 + _t317*_t835 + _t318*_t724 - _t325*_t384 + _t380*_t76 + _t380*_t78 + _t381*_t88 + _t383*_t88 + _t386*_t88 + _t387*_t834 + _t388*_t68 - _t726*_t733 - _t732*_t733 + _t737 + _t823 + _t830*_t88 + _t831*_t832 + _t832*_t833 - _t842*_t88) + 0.4e1*_t122*_t128 + _t153*_t334 + _t158*_t83 + _t162*_t89 + 0.2e1*_t26*_t390 + 0.2e1*_t326*_t52 + _t400*_t65)) + 0.2e1*_t335 + 0.2e1*_t378 + 0.2e1*_t401 + 0.2e1*_t422;
  const double d4F_dna_dnb3 = _t3*(my_piecewise3(_t14, 0, _hc1[0]*(_hc2[2]*_t896 - _t138*_t895 - _t138*_t899 + _t146*_t819 - _t209*_t418 + _t280*_t426 + _t32*_t909 + _t356*_t902 - _t36*(_t359*_t430 + _t43*_t878 + _t431*_t804 + _t891 + _t910 + _t911 + _t912 + _t913) + _t414*_t900 + _t414*_t903 - _t418*_t898 + _t432*_t819 + _t577*_t914 + _t815*_t901 + _t816*_t897 + _t820*_t904 + _t874 + _t907*_t915 + _t916) + _hc2[0]*(_hc1[1]*_t896 - _t130*_t895 - _t130*_t899 + _t146*_t776 - _t209*_t409 + _t258*_t426 + _t32*_t894 + _t345*_t902 + _t403*_t900 + _t403*_t903 - _t409*_t898 + _t432*_t776 + _t577*_t905 + _t768*_t901 + _t770*_t897 + _t777*_t904 + _t857 + _t906*_t907 + _t908) + _t150*_t753 + _t151*_t752 + _t33*_t433 + _t38*_t434 + _t412*_t424 + _t421*_t423) + my_piecewise3(_t15, 0, _hc4[0]*(-_hc5[2]*_t918 + _hc5[2]*_t920 - _hc5[2]*_t928 + _t124*_t919 + _t124*_t925 - _t124*_t926 + _t154*_t738 + _t209*_t396 + _t222*_t425 + _t25*_t937 + _t318*_t938 + _t383*_t939 - _t393*_t921 + _t396*_t898 + _t441*_t738 - _t577*_t940 + _t740*_t923 + _t855 + _t945) + _hc5[0]*(-_hc4[1]*_t918 + _hc4[1]*_t920 - _hc4[1]*_t928 + _t116*_t919 + _t116*_t925 - _t116*_t926 + _t118*_t425 + _t154*_t732 + _t209*_t387 + _t25*_t917 + _t318*_t922 - _t380*_t921 + _t383*_t924 + _t387*_t898 + _t441*_t732 - _t577*_t929 + _t726*_t923 + _t823 + _t930) + _t158*_t714 + _t162*_t713 + _t26*_t442 + _t28*_t451 + _t390*_t436 + _t400*_t437)) + 0.3e1*_t401 + 0.3e1*_t422 + _t453;
  const double d4F_dnb4 = _t3*(my_piecewise3(_t14, 0, _hc1[0]*(_hc2[2]*_t947 + _hc2[2]*_t948 + _hc2[2]*_t949 + _t138*_t950 + _t356*_t953 + _t414*_t951 + _t418*_t955 + _t418*_t959 + _t43*_t909 + _t820*_t956 + _t863*_t914 + _t882*_t952 + _t901*_t915 + _t914*_t957 + _t914*_t958 + _t915*_t960 + _t916) + _hc2[0]*(_hc1[1]*_t947 + _hc1[1]*_t948 + _hc1[1]*_t949 + _t130*_t950 + _t345*_t953 + _t403*_t951 + _t409*_t955 + _t409*_t959 + _t43*_t894 + _t777*_t956 + _t863*_t905 + _t865*_t952 + _t901*_t906 + _t905*_t957 + _t905*_t958 + _t906*_t960 + _t908) + 0.6e1*_t150*_t151 + 0.4e1*_t433*_t45 + 0.4e1*_t434*_t44) + my_piecewise3(_t15, 0, _hc4[0]*(_hc5[2]*_t961 + _hc5[2]*_t962 + _hc5[2]*_t963 + _hc5[2]*_t965 + (0.28e2 / 0.3e1)*_t12*_t160*_t448 - _t123*(-_hc5[4]*_t931 - _hc5[7]*_t207 - _t123*(_hc5[10]*_t392 + _hc5[14]*_t68 - _t123*(_hc3[1]*_hc5[21]*_t41 - _hc5[20]*_t123 - _hc5[25]*_t19) - _t19*_t943 + _t47*_t934 + _t975 + _t976) + _t155*_t974 + _t157*_t974 - _t19*_t944 + _t224*_t397 + _t447*_t936 + _t47*_t935 + _t969 + _t970 + _t972 + _t973) + _t154*_t940 + _t155*_t938 + _t157*_t938 + _t396*_t954 + _t396*_t967 + _t438*_t939 + _t440*_t939 + _t441*_t940 - 0.280e3 / 0.9e1*_t443*_t449 + _t47*_t937 + (0.3640e4 / 0.81e2)*_t49*_t977 + _t563 + _t927*_t978 + _t940*_t966 + _t945 + _t964*_t978) + _hc5[0]*(_hc4[1]*_t961 + _hc4[1]*_t962 + _hc4[1]*_t963 + _hc4[1]*_t965 + _t154*_t929 + _t155*_t922 + _t157*_t922 + _t387*_t954 + _t387*_t967 + _t438*_t924 + _t440*_t924 + _t441*_t929 + _t47*_t917 + _t927*_t968 + _t929*_t966 + _t930 + _t964*_t968) + 0.6e1*_t158*_t162 + 0.4e1*_t442*_t52 + 0.4e1*_t451*_t48)) + 0.4e1*_t435 + 0.4e1*_t452;
  const double d4F_dna3_dgaa = _t3*my_piecewise3(_t14, 0, _hc1[0]*(-0.140e3 / 0.27e2*_hc2[4]/xc_powr(na, 17, 3) + _t103*_t107*_t56 + _t183*_t671 + _t183*_t672 + _t183*_t674 + _t183*_t675 - _t19*(_hc2[14]*_t455 + _hc2[7]*_t981 + _t183*_t686 + _t183*_t687 - _t19*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[30]*_t11*_t31*_t56 - _hc2[17]*_t459 - _hc2[29]*_t167 - _t990) - _t291*_t459 + _t32*_t992 - _t36*_t986 + _t989) + _t224*_t464 + _t263*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[12]*_t11*_t260*_t56 - _t466) + _t264*_t467 - 0.140e3 / 0.27e2*_t277*_t57 - _t295*_t459 + _t32*(_hc2[11]*_t455 + _hc2[5]*_t981 + _t183*_t694 + _t183*_t695 - _t19*_t992 - _t294*_t459 + _t32*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[23]*_t11*_t31*_t56 - _hc2[12]*_t459 - _hc2[22]*_t167 - _t994) - _t36*_t988 + _t993) - _t36*(_hc2[10]*_t455 + _hc2[4]*_t981 + _t183*_t678 + _t183*_t679 - _t19*_t986 - _t289*_t459 + _t32*_t988 - _t36*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[21]*_t11*_t31*_t56 - _hc2[10]*_t459 - _hc2[20]*_t167 - _t984) + _t983) + _t462*_t676 + _t980) + 0.3e1*_t100*_t173 + _t165*_t276 + _t252*_t468) + 0.3e1*_t469;
  const double d4F_dna3_dgbb = _t3*my_piecewise3(_t15, 0, _hc4[0]*(-_t19*(_t1002*_t25 - _t19*(_hc5[30]*_t474 - _t1000) + _t76*_t999 + _t78*_t999 + _t998) + _t214*_t472 + _t216*_t472 + _t221*_t996 + _t224*_t475 + _t25*(-_t1002*_t19 + _t1003 + _t1004*_t76 + _t1004*_t78 + _t25*(_hc5[23]*_t474 - _t1005)) + _t75*_t996 + _t76*_t997 + _t78*_t997 + _t995) + _t175*_t249 + 0.3e1*_t181*_t89 + _t203*_t478) + 0.3e1*_t479;
  const double d4F_dna2_dnb_dgaa = _t1006 + _t3*my_piecewise3(_t14, 0, _hc1[0]*(_t1007*_t673 + _t1008*_t95 + _t132*_t467 + _t133*_t467 + _t140*_t981 + _t183*_t801 + _t183*_t802 + _t183*_t803 - _t19*(_hc2[15]*_t1010 - _t1011*_t36 + _t1013*_t32 + _t1014 + _t183*_t810 - _t364*_t459) + _t284*_t482 + _t32*(_hc2[12]*_t1010 - _t1009*_t36 + _t1015*_t32 + _t1016 + _t183*_t787 - _t359*_t459) - _t36*(_hc2[11]*_t1010 + _t1009*_t32 + _t1012 + _t183*_t806 - _t36*(_t183*_t805 - _t984) - _t361*_t459) - _t366*_t459 + _t464*_t68 + _t481*_t93 + _t486*_t68 + _t980) + _t100*_t184 + _t165*_t354 + _t173*_t336 + _t45*_t468 + _t488*_t91) + _t469;
  const double d4F_dna2_dnb_dgbb = _t1017 + _t3*my_piecewise3(_t15, 0, _hc4[0]*(_t1018*_t315 + _t1018*_t317 - _t117*_t179*_t73 - _t119*_t477 - _t19*(-_hc5[15]*_t1021 + _t1019*_t25 + _t1022 + _t318*_t999) + _t25*(-_hc5[12]*_t1021 + _t1004*_t318 + _t1023*_t25 + _t1024) + _t314*_t472 + _t318*_t477 + _t475*_t68 + _t491*_t76 + _t491*_t78 + _t494*_t68 + _t995) + _t175*_t326 + _t181*_t312 + _t189*_t89 + _t478*_t48 + _t496*_t65) + _t479;
  const double d4F_dna_dnb2_dgaa = _t1006 + _t3*my_piecewise3(_t14, 0, _hc1[0]*(-_hc0[1]*_hc2[5]*_t1026*_t170 + _t1007*_t887 + _t1025*_t32 + _t1027 + _t183*_t885 + _t183*_t886 - _t36*(_t1009*_t43 + _t1012 + _t183*_t883 + _t183*_t884) + _t407*_t481 + _t408*_t481 - _t417*_t459 - _t485) + _t145*_t488 + _t151*_t173 + _t165*_t412 + _t184*_t336 + _t33*_t498) + _t499;
  const double d4F_dna_dnb2_dgbb = _t1017 + _t3*my_piecewise3(_t15, 0, _hc4[0]*(_hc3[1]*_t1026*_t179 + _t1030*_t25 + _t1031*_t318 + _t1033 - _t176*_t736*_t971 + _t383*_t472 - _t384*_t491 + _t472*_t830 + _t493) + _t153*_t496 + _t158*_t181 + _t175*_t390 + _t189*_t312 + _t28*_t505) + _t506;
  const double d4F_dnb3_dgaa = _t3*my_piecewise3(_t14, 0, _hc1[0]*(_t1008*_t431 + _t1025*_t43 + _t1027 + _t183*_t910 + _t183*_t911 + _t183*_t912 + _t183*_t913 + _t430*_t481) + 0.3e1*_t151*_t184 + _t165*_t434 + _t423*_t498) + 0.3e1*_t499;
  const double d4F_dnb3_dgbb = _t3*my_piecewise3(_t15, 0, _hc4[0]*(-0.140e3 / 0.27e2*_hc5[4]/xc_powr(nb, 17, 3) + _t1030*_t47 + _t1031*_t155 + _t1031*_t157 + _t1033 - _t123*(_hc5[10]*_t501 + _hc5[14]*_t470 + _hc5[4]*_t1029 + _t1028*_t47 - _t1032*_t19 - _t123*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[21]*_t13*_t41*_t61 - _hc5[10]*_t490 - _hc5[20]*_t187 - _hc5[25]*_t177) - _t447*_t490 + _t504*_t975 + _t504*_t976) + _t159*_t161*_t61 - 0.140e3 / 0.27e2*_t443*_t62 - _t448*_t490 + _t502*_t936 + _t504*_t969 + _t504*_t970 + _t504*_t972 + _t504*_t973) + 0.3e1*_t158*_t189 + _t175*_t442 + _t437*_t505) + 0.3e1*_t506;
  const double d4F_dna2_dgaa2 = _t3*my_piecewise3(_t14, 0, _hc1[0]*((0.7e1 / 0.9e1)*_hc2[10]*_t56/xc_powi(na, 6) - 0.7e1 / 0.9e1*_t102*_t192 - _t1040*_t462 + _t1044 + (0.1e1 / 0.3e1)*_t107*_t191*_t34 - _t19*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[26]*_t194*_t195*_t31 - _hc2[14]*_t1034 - _hc2[15]*_t32*_t532 - _hc2[25]*_t1035 + (0.1e1 / 0.3e1)*_hc2[7]*_t191*_t34 - _t1041) - _t286*_t532 - _t287*_t532 + _t32*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[22]*_t194*_t195*_t31 - _hc2[11]*_t1034 - _hc2[12]*_t32*_t532 - _hc2[21]*_t1035 + (0.1e1 / 0.3e1)*_hc2[5]*_t191*_t34 - _t1037) - _t36*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[21]*_t194*_t195*_t31 - _hc2[20]*_t1035 + (0.1e1 / 0.3e1)*_hc2[4]*_t191*_t34 - _t1038*_t532 - _t1039 - _t510*_t512) + (0.7e1 / 0.9e1)*_t454*_t508 + _t531*_t678 + _t531*_t679) - _t100*_t507 + _t100*_t509 + _t517*_t91) + 0.2e1*_t518;
  const double d4F_dna2_dgbb2 = _t3*my_piecewise3(_t15, 0, _hc4[0]*(-_t1048*_t76 - _t1048*_t78 + _t1050*_t76 + _t1050*_t78 + _t1052 - _t19*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[26]*_t200*_t201*_t24 - _hc5[15]*_t1045 - _t1047) + _t25*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[22]*_t200*_t201*_t24 - _hc5[12]*_t1045 - _t1046)) - _t519*_t89 + _t521*_t89 + _t528*_t65) + 0.2e1*_t529;
  const double d4F_dna_dnb_dgaa2 = _t3*my_piecewise3(_t14, 0, _hc1[0]*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[11]*_t194*_t195*_t2*_t71 + _hc0[1]*_t1054*_t31 + (0.1e1 / 0.4e1)*_hc0[2]*_hc2[11]*_t194*_t195*_t31*_t42 + (0.1e1 / 0.18e2)*_hc2[14]*_t194*_t195*_t6*_t66*_t7 - 0.1e1 / 0.2e1*_hc2[5]*_t2*_t483*_t530 - _t1040*_t482 - _t1043 - _t1053 + (0.1e1 / 0.3e1)*_t140*_t191*_t34 - _t36*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[21]*_t194*_t195*_t42 - _t1039 - _t360*_t532) - _t362*_t532) - _t136*_t507 + _t136*_t509 + _t33*_t533 + _t45*_t517) + _t518 + _t534;
  const double d4F_dna_dnb_dgbb2 = _t3*my_piecewise3(_t15, 0, _hc4[0]*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[5]*_t13*_t197*_t2*_t71 + _hc3[1]*_t1058*_t24 + (0.1e1 / 0.4e1)*_hc3[2]*_hc5[11]*_t200*_t201*_t24*_t41 - 0.1e1 / 0.2e1*_hc5[11]*_t1020*_t522 + (0.1e1 / 0.18e2)*_hc5[14]*_t200*_t201*_t6*_t66*_t7 - _t1048*_t318 - _t1051 - _t1057) - _t122*_t519 + _t122*_t521 + _t28*_t539 + _t48*_t528) + _t529 + _t540;
  const double d4F_dnb2_dgaa2 = _t3*my_piecewise3(_t14, 0, _hc1[0]*(_t1044 - _t1053 + _t1054*_t43 - _t415*_t532 - _t416*_t532 + _t531*_t883 + _t531*_t884) + _t145*_t533 - _t151*_t507 + _t151*_t509) + 0.2e1*_t534;
  const double d4F_dnb2_dgbb2 = _t3*my_piecewise3(_t15, 0, _hc4[0]*((0.7e1 / 0.9e1)*_hc5[10]*_t61/xc_powi(nb, 6) + _t1049*_t975 + _t1049*_t976 + _t1052 - _t1057 + _t1058*_t47 - _t123*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[21]*_t200*_t201*_t41 + (0.1e1 / 0.24e2)*_hc5[14]*_t13*_t17*_t197*_t6*_t7 - _hc5[20]*_t1056 - _hc5[25]*_t523 + (0.1e1 / 0.3e1)*_hc5[4]*_t197*_t50 - _t1059*_t538 - _t535*_t537) + (0.1e1 / 0.3e1)*_t159*_t197*_t50 - 0.7e1 / 0.9e1*_t160*_t198 - _t445*_t538 - _t446*_t538 + (0.7e1 / 0.9e1)*_t500*_t520 - _t502*_t51*_t61) + _t153*_t539 - _t158*_t519 + _t158*_t521) + 0.2e1*_t540;
  const double d4F_dna_dgaa3 = _t3*my_piecewise3(_t14, 0, _hc1[0]*((0.1e1 / 0.8e1)*_hc0[1]*_hc2[21]*_t191*_t31*_t545 + (0.3e1 / 0.8e1)*_hc0[1]*_hc2[5]*_t11*_t31*_t541 - 0.1e1 / 0.6e1*_hc2[20]*_t194/xc_powr(na, 19, 3) + (0.1e1 / 0.2e1)*_hc2[4]*_t166*_t548 - _t1038*_t1063*_t195 - _t1066 - 0.1e1 / 0.2e1*_t34*_t542) + _t1060*_t33 + _t1061*_t33 - _t1062*_t33) + _t550;
  const double d4F_dna_dgbb3 = _t3*my_piecewise3(_t15, 0, _hc4[0]*((0.1e1 / 0.8e1)*_hc3[1]*_hc5[21]*_t197*_t24*_t555 + (0.3e1 / 0.8e1)*_hc3[1]*_hc5[5]*_t13*_t24*_t551 - _hc5[11]*_t1070*_t25 - _t1071) + _t1067*_t28 + _t1068*_t28 - _t1069*_t28) + _t560;
  const double d4F_dnb_dgaa3 = _t3*my_piecewise3(_t14, 0, _hc1[0]*((0.1e1 / 0.8e1)*_hc0[1]*_hc2[21]*_t191*_t42*_t545 + (0.3e1 / 0.8e1)*_hc0[1]*_hc2[5]*_t11*_t42*_t541 - _t1063*_t195*_t360 - _t1066) + _t1060*_t45 + _t1061*_t45 - _t1062*_t45) + _t550;
  const double d4F_dnb_dgbb3 = _t3*my_piecewise3(_t15, 0, _hc4[0]*((0.1e1 / 0.8e1)*_hc3[1]*_hc5[21]*_t197*_t41*_t555 + (0.3e1 / 0.8e1)*_hc3[1]*_hc5[5]*_t13*_t41*_t551 - 0.1e1 / 0.6e1*_hc5[20]*_t200/xc_powr(nb, 19, 3) + (0.1e1 / 0.2e1)*_hc5[4]*_t186*_t558 - _t1059*_t1070 - _t1071 - 0.1e1 / 0.2e1*_t50*_t552) + _t1067*_t48 + _t1068*_t48 - _t1069*_t48) + _t560;
  const double d4F_dgaa4 = _t3*my_piecewise3(_t14, 0, (0.1e1 / 0.16e2)*_hc1[0]*_hc2[20]*_t548*_t663 + (0.15e2 / 0.16e2)*_hc1[0]*_hc2[4]*_t195/(gaa * gaa * gaa) - 0.15e2 / 0.16e2*_hc2[1]*_t55/xc_powr(gaa, 7, 2) - 0.3e1 / 0.8e1*_t541*_t544*_t545);
  const double d4F_dgbb4 = _t3*my_piecewise3(_t15, 0, (0.1e1 / 0.16e2)*_hc4[0]*_hc5[20]*_t558*_t977 + (0.15e2 / 0.16e2)*_hc4[0]*_hc5[4]*_t201/(gbb * gbb * gbb) - 0.15e2 / 0.16e2*_hc5[1]*_t60/xc_powr(gbb, 7, 2) - 0.3e1 / 0.8e1*_t551*_t554*_t555);
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