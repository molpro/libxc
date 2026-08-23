/*
  Generated from python/gga_exc/gga_c_lm.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_lm
*/

#ifndef _GGA_C_LM_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_LM_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_LM_HELPER_BODIES
#include "gga_c_lm.c"
#undef _GGA_C_LM_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_LM_HELPER_BODIES
#include "gga_c_lm.c"
#undef _GGA_C_LM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_LM_HELPER_BODIES
#include "gga_c_lm.c"
#undef _GGA_C_LM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_LM_HELPER_BODIES
#include "gga_c_lm.c"
#undef _GGA_C_LM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_LM_HELPER_BODIES
#include "gga_c_lm.c"
#undef _GGA_C_LM_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_lm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_LM_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_zeta_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (0.1e1 / (-0.2e1 + 0.2e1*M_CBRT2));
  const double _t2 = z + 0.1e1 <= p->zeta_threshold;
  const double _t3 = xc_powr(p->zeta_threshold, 4, 3) - 0.1e1;
  const double _t4 = p->zeta_threshold - 0.1e1;
  const double _t5 = z > _t4;
  const double _t6 = my_piecewise3(_t5, z, _t4);
  const double _t7 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t6));
  const double _t8 = 0.1e1 - z <= p->zeta_threshold;
  const double _t9 = -z;
  const double _t10 = _t9 > _t4;
  const double _t11 = my_piecewise3(_t10, _t9, _t4);
  const double _t12 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t11));
#if _KMAX >= 1
  const double _t13 = my_piecewise3(_t5, 0.1e1, 0);
  const double _t14 = _t6 + 0.1e1;
  const double _t15 = _t7 + 0.1e1;
  const double _t16 = my_piecewise3(_t10, -0.1e1, 0);
  const double _t17 = _t11 + 0.1e1;
  const double _t18 = _t12 + 0.1e1;
#endif

  const double f = _t1*(my_piecewise3(_t2, _t3, _t7) + my_piecewise3(_t8, _t3, _t12));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*_t13*_t15/_t14) + my_piecewise3(_t8, 0, (0.4e1 / 0.3e1)*_t16*_t18/_t17));
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)*(_t13 * _t13)*_t15/(_t14 * _t14)) + my_piecewise3(_t8, 0, (0.4e1 / 0.9e1)*(_t16 * _t16)*_t18/(_t17 * _t17)));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t1*(my_piecewise3(_t2, 0, -0.8e1 / 0.27e2*(_t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, -0.8e1 / 0.27e2*(_t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17)));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t1*(my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)*(_t13 * _t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, (0.40e2 / 0.81e2)*(_t16 * _t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17 * _t17)));
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(hl_f_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = (rs * rs);
  const double _t2 = (0.1e1 / rs);
  const double _t3 = 0.30e2*_t2;
  const double _t4 = xc_log1p(_t3);
  const double _t5 = (rs * rs * rs);
  const double _t6 = (0.1e1 / 0.27000e5)*_t5 + 0.1e1;
  const double _t7 = -0.0252*_t4*_t6;
  const double _t8 = 75.0*_t2;
  const double _t9 = xc_log1p(_t8);
  const double _t10 = 2.3703703703703707e-6*_t5 + 0.1e1;
  const double _t11 = -2.574222222222222e-5*_t1 - 0.012699999999999999*_t10*_t9 - _t7 + 0.00033533333333333332*rs - 0.0041666666666666666;
#if _KMAX >= 1
  const double _t12 = 2.8000000000000003e-6*_t1*_t4;
  const double _t13 = _t3 + 0.1e1;
  const double _t14 = (0.1e1 / _t13);
  const double _t15 = (0.1e1 / _t1);
  const double _t16 = _t14*_t15;
  const double _t17 = 0.75600000000000001*_t16*_t6;
  const double _t18 = _t8 + 0.1e1;
  const double _t19 = (0.1e1 / _t18);
  const double _t20 = _t15*_t19;
  const double _t21 = -9.0311111111111121e-8*_t1*_t9 + 0.95250000000000001*_t10*_t20 + _t12 - _t17 - 5.148444444444444e-5*rs + 0.00033533333333333332;
#endif
#if _KMAX >= 2
  const double _t22 = 1.8062222222222224e-7*_t9;
  const double _t23 = (0.1e1 / _t5);
  const double _t24 = _t10*_t19;
  const double _t25 = (0.1e1 / (rs * rs * rs * rs));
  const double _t26 = (0.1e1 / (_t18 * _t18));
  const double _t27 = 5.6000000000000006e-6*_t4;
  const double _t28 = (0.1e1 / (_t13 * _t13));
  const double _t29 = _t28*_t6;
  const double _t30 = _t14*_t6;
  const double _t31 = 0.00016800000000000002*_t14 - 1.512*_t23*_t30 + 22.68*_t25*_t29 - _t27*rs;
  const double _t32 = 71.4375*_t10*_t25*_t26 + 1.354666666666667e-5*_t19 - _t22*rs - 1.905*_t23*_t24 - _t31 - 5.148444444444444e-5;
#endif
#if _KMAX >= 3
  const double _t33 = xc_powi(rs, -5);
  const double _t34 = xc_powi(rs, -6);
  const double _t35 = (0.1e1 / (_t18 * _t18 * _t18));
  const double _t36 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t37 = _t36*_t6;
  const double _t38 = 0.0075600000000000007*_t15*_t28 + 4.5359999999999996*_t25*_t30 - _t27 - 136.07999999999998*_t29*_t33 + 1360.8*_t34*_t37;
  const double _t39 = 5.7149999999999999*_t10*_t19*_t25 - 428.625*_t10*_t26*_t33 + 10715.625*_t10*_t34*_t35 + 0.0015240000000000002*_t15*_t26 - 1.6940658945086007e-21*_t19*_t2 - _t22 - _t38;
#endif
#if _KMAX >= 4
  const double _t40 = 0.6048*_t25*_t36;
  const double _t41 = 0.030240000000000003*_t23*_t28;
  const double _t42 = 0.00067200000000000007*_t16;
  const double _t43 = xc_powi(rs, -8);
  const double _t44 = 122472.0*_t43*_t6/(_t13 * _t13 * _t13 * _t13);
  const double _t45 = xc_powi(rs, -7);
  const double _t46 = 16329.599999999999*_t37*_t45;
  const double _t47 = 816.47999999999979*_t29*_t34;
  const double _t48 = 18.143999999999998*_t30*_t33;
#endif

  const double f = _hc0[0]*_t11 + 2.8e-5*_t1 + _t7 - 0.00042000000000000002*rs + 0.0083999999999999995;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = _hc0[1]*_t11;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t21 - _t12 + _t17 + 5.5999999999999999e-5*rs - 0.00042000000000000002;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = _hc0[2]*_t11;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t21;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[0]*_t32 + _t31 + 5.5999999999999999e-5;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = _hc0[3]*_t11;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc0[2]*_t21;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc0[1]*_t32;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = _hc0[0]*_t39 + _t38;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = _hc0[4]*_t11;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = _hc0[3]*_t21;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = _hc0[2]*_t32;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = _hc0[1]*_t39;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = _hc0[0]*(2571.75*_t10*_t26*_t34 - 128587.5*_t10*_t35*_t45 + 2411015.625*_t10*_t43/(_t18 * _t18 * _t18 * _t18) + 5.4186666666666681e-5*_t20 - 0.0060960000000000007*_t23*_t26 - 22.859999999999999*_t24*_t33 + 0.30480000000000007*_t25*_t35 - _t40 + _t41 - _t42 - _t44 + _t46 - _t47 + _t48) + _t40 - _t41 + _t42 + _t44 - _t46 + _t47 - _t48;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lm_d_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.5e1 / 0.3e1, _hc1);
  const double _t1 = _hc0[0] + _hc1[0] + 0.2e1;
  const double _t2 = xc_powr(_t1, 1, 2);
  const double _t3 = xc_powr(0.2e1, 1, 2);
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
#if _KMAX >= 1
  const double _t5 = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  const double _t6 = _t4/_t2;
#endif
#if _KMAX >= 2
  const double _t7 = (0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5];
  const double _t8 = xc_powr(_t1, -3, 2);
  const double _t9 = -_t5;
  const double _t10 = _t8*_t9;
  const double _t11 = _t4*_t5;
#endif
#if _KMAX >= 3
  const double _t12 = (0.1e1 / 0.2e1)*_hc0[9] - 0.1e1 / 0.2e1*_hc1[9];
  const double _t13 = _t3*_t7;
  const double _t14 = -_t7;
  const double _t15 = _t11*_t8;
  const double _t16 = xc_powr(_t1, -5, 2);
  const double _t17 = -0.3e1 / 0.2e1*_hc0[2] + (0.3e1 / 0.2e1)*_hc1[2];
  const double _t18 = _t16*_t17;
  const double _t19 = _t11*_t9;
#endif
#if _KMAX >= 4
  const double _t20 = (0.3e1 / 0.2e1)*_t13;
#endif

  const double f = _t2*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t5*_t6;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t10*_t11 + _t6*_t7;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t10*_t13 + _t12*_t6 + _t14*_t15 + _t18*_t19;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.3e1 / 0.2e1)*_t10*_t12*_t3 - _t12*_t15 + _t14*_t18*_t3*_t5 + _t14*_t20*_t8 + _t16*_t19*(-0.3e1 / 0.2e1*_hc0[5] - 0.3e1 / 0.2e1*_hc1[5]) + _t18*_t20*_t9 + _t6*((0.1e1 / 0.2e1)*_hc0[14] + (0.1e1 / 0.2e1)*_hc1[14]) + _t17*_t19*(-0.5e1 / 0.2e1*_hc0[2] + (0.5e1 / 0.2e1)*_hc1[2])/xc_powr(_t1, 7, 2);
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lm_t1_k, _KMAX)(const xc_func_type *p, double z, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, -z, _hc1);
  const double _t1 = (xs0 * xs0);
  const double _t2 = (xs1 * xs1);
  const double _t3 = M_CBRT2;
  const double _t4 = (0.7e1 / 0.36e2)*_t3;
#if _KMAX >= 1
  const double _t5 = (0.7e1 / 0.18e2)*_t3;
  const double _t6 = _hc1[0]*_t5;
  const double _t7 = _hc0[0]*_t5;
#endif
#if _KMAX >= 2
  const double _t8 = _hc1[1]*_t5;
  const double _t9 = _hc0[1]*_t5;
#endif
#if _KMAX >= 3
  const double _t10 = _hc1[2]*_t5;
  const double _t11 = _hc0[2]*_t5;
#endif

  const double f = -_t4*(_hc0[0]*_t1 + _hc1[0]*_t2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = -_t6*xs1;
  out[1] = df_dxs1;
  const double df_dxs0 = -_t7*xs0;
  out[2] = df_dxs0;
  const double df_dz = -_t4*(_hc0[1]*_t1 - _hc1[1]*_t2);
  out[3] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = -_t6;
  out[4] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[5] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = -_t7;
  out[6] = d2f_dxs02;
  const double d2f_dz_dxs1 = _t8*xs1;
  out[7] = d2f_dz_dxs1;
  const double d2f_dz_dxs0 = -_t9*xs0;
  out[8] = d2f_dz_dxs0;
  const double d2f_dz2 = -_t4*(_hc0[2]*_t1 + _hc1[2]*_t2);
  out[9] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[10] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[11] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[12] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[13] = d3f_dxs03;
  const double d3f_dz_dxs12 = _t8;
  out[14] = d3f_dz_dxs12;
  const double d3f_dz_dxs0_dxs1 = 0;
  out[15] = d3f_dz_dxs0_dxs1;
  const double d3f_dz_dxs02 = -_t9;
  out[16] = d3f_dz_dxs02;
  const double d3f_dz2_dxs1 = -_t10*xs1;
  out[17] = d3f_dz2_dxs1;
  const double d3f_dz2_dxs0 = -_t11*xs0;
  out[18] = d3f_dz2_dxs0;
  const double d3f_dz3 = -_t4*(_hc0[3]*_t1 - _hc1[3]*_t2);
  out[19] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[20] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[21] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[22] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[23] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[24] = d4f_dxs04;
  const double d4f_dz_dxs13 = 0;
  out[25] = d4f_dz_dxs13;
  const double d4f_dz_dxs0_dxs12 = 0;
  out[26] = d4f_dz_dxs0_dxs12;
  const double d4f_dz_dxs02_dxs1 = 0;
  out[27] = d4f_dz_dxs02_dxs1;
  const double d4f_dz_dxs03 = 0;
  out[28] = d4f_dz_dxs03;
  const double d4f_dz2_dxs12 = -_t10;
  out[29] = d4f_dz2_dxs12;
  const double d4f_dz2_dxs0_dxs1 = 0;
  out[30] = d4f_dz2_dxs0_dxs1;
  const double d4f_dz2_dxs02 = -_t11;
  out[31] = d4f_dz2_dxs02;
  const double d4f_dz3_dxs1 = _hc1[3]*_t5*xs1;
  out[32] = d4f_dz3_dxs1;
  const double d4f_dz3_dxs0 = -_hc0[3]*_t5*xs0;
  out[33] = d4f_dz3_dxs0;
  const double d4f_dz4 = -_t4*(_hc0[4]*_t1 + _hc1[4]*_t2);
  out[34] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lm_t2_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double *out) {
  const gga_c_lm_params *params = (const gga_c_lm_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lm_d_k, _KMAX)(p, z, _hc0);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = xc_powr(0.2e1, 2, 3);
  const double _t3 = xc_powr(0.3e1, 1, 2);
  const double _t4 = (0.1e1 / (rs * rs * rs));
  const double _t5 = xc_powr(_t4, 1, 6);
  const double _t6 = _t2*_t3*_t5*params->lm_f;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = exp(-_t7*xt);
  const double _t9 = _t1*_t8;
  const double _t10 = (xt * xt);
  const double _t11 = 0.2e1*_t10;
#if _KMAX >= 1
  const double _t12 = _t6*_t9;
  const double _t13 = _t10*_t12;
  const double _t14 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t15 = _t14*_t8;
  const double _t16 = _t11*_t15;
  const double _t17 = (0.1e1 / rs);
  const double _t18 = (xt * xt * xt);
  const double _t19 = _t17*_t18;
  const double _t20 = _t19*_t7;
#endif
#if _KMAX >= 2
  const double _t21 = 0.4e1*_t9;
  const double _t22 = M_CBRT2;
  const double _t23 = xc_powr(_t4, 1, 3);
  const double _t24 = ((params->lm_f) * (params->lm_f));
  const double _t25 = _t22*_t23*_t24;
  const double _t26 = _t25*_t9;
  const double _t27 = 0.3e1*_t10;
  const double _t28 = 0.4e1*_t15;
  const double _t29 = _hc0[1]*_t28;
  const double _t30 = _hc0[1]*_t10;
  const double _t31 = _t15*_t30;
  const double _t32 = _t31*_t6;
  const double _t33 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t34 = ((_hc0[1]) * (_hc0[1]));
  const double _t35 = _t17*_t26;
  const double _t36 = (0.3e1 / 0.2e1)*_t18;
  const double _t37 = _hc0[1]*_t15;
  const double _t38 = (0.1e1 / (rs * rs));
  const double _t39 = _t26*_t38;
  const double _t40 = (xt * xt * xt * xt);
  const double _t41 = (0.3e1 / 0.4e1)*_t40;
  const double _t42 = _t12*_t18;
#endif
#if _KMAX >= 3
  const double _t43 = xc_powr(_t4, 1, 2);
  const double _t44 = ((params->lm_f) * (params->lm_f) * (params->lm_f));
  const double _t45 = _t3*_t43*_t44;
  const double _t46 = _t45*_t9;
  const double _t47 = 0.3e1*_t31;
  const double _t48 = _hc0[2]*_t28;
  const double _t49 = _t33*_t8;
  const double _t50 = _t34*_t49;
  const double _t51 = 0.8e1*_t50*xt;
  const double _t52 = _t15*_t6;
  const double _t53 = _t10*_t52;
  const double _t54 = _hc0[2]*_t53;
  const double _t55 = _t50*_t6;
  const double _t56 = 0.12e2*_t10;
  const double _t57 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t58 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t57*_t8;
  const double _t59 = 0.3e1*_t17;
  const double _t60 = _t15*_t25;
  const double _t61 = _hc0[1]*_t60;
  const double _t62 = _t17*_t36;
  const double _t63 = (0.3e1 / 0.2e1)*_t17;
  const double _t64 = _t15*_t20;
  const double _t65 = _t38*_t46;
  const double _t66 = (0.9e1 / 0.4e1)*_t38;
  const double _t67 = _t38*_t61;
  const double _t68 = _t26*_t4;
  const double _t69 = xc_powi(xt, 5);
  const double _t70 = _t4*_t69;
  const double _t71 = (0.3e1 / 0.8e1)*_t70;
  const double _t72 = (0.15e2 / 0.8e1)*_t4;
#endif
#if _KMAX >= 4
  const double _t73 = 0.24e2*xt;
  const double _t74 = _t2*xc_powr(_t4, 2, 3)*_t9*((params->lm_f) * (params->lm_f) * (params->lm_f) * (params->lm_f));
  const double _t75 = _hc0[1]*_t52;
  const double _t76 = _hc0[2]*_t60;
  const double _t77 = _hc0[1]*_hc0[2]*_t49;
  const double _t78 = 0.6e1*_t10;
  const double _t79 = _t58*_t6;
  const double _t80 = _t10*_t8;
  const double _t81 = _t37*_t45;
  const double _t82 = _t18*_t59;
  const double _t83 = _t38*_t41;
  const double _t84 = (0.1e1 / (rs * rs * rs * rs));
#endif

  const double f = _t11*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = 0.4e1*_t1*_t8*xt - _t13;
  out[1] = df_dxt;
  const double df_dz = -_hc0[1]*_t16;
  out[2] = df_dz;
  const double df_drs = _t20*_t9;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = -_t21*_t6*xt + _t21 + _t26*_t27;
  out[4] = d2f_dxt2;
  const double d2f_dz_dxt = -_t29*xt + _t32;
  out[5] = d2f_dz_dxt;
  const double d2f_dz2 = -_hc0[2]*_t16 + 0.4e1*_t10*_t33*_t34*_t8;
  out[6] = d2f_dz2;
  const double d2f_drs_dxt = (0.3e1 / 0.2e1)*_t1*_t10*_t17*_t2*_t3*_t5*_t8*params->lm_f - _t35*_t36;
  out[7] = d2f_drs_dxt;
  const double d2f_drs_dz = -_t20*_t37;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = -0.3e1 / 0.4e1*_t38*_t42 + _t39*_t41;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0.18e2*_t1*_t22*_t23*_t24*_t8*xt - 0.6e1*_t12 - _t27*_t46;
  out[10] = d3f_dxt3;
  const double d3f_dz_dxt2 = 0.4e1*_hc0[1]*_t14*_t2*_t3*_t5*_t8*params->lm_f*xt - _t25*_t47 - _t29;
  out[11] = d3f_dz_dxt2;
  const double d3f_dz2_dxt = -_t11*_t55 - _t48*xt + _t51 + _t54;
  out[12] = d3f_dz2_dxt;
  const double d3f_dz3 = 0.12e2*_hc0[1]*_hc0[2]*_t10*_t33*_t8 - _hc0[3]*_t16 - _t56*_t58;
  out[13] = d3f_dz3;
  const double d3f_drs_dxt2 = -0.9e1*_t10*_t35 + _t12*_t59*xt + _t17*_t36*_t46;
  out[14] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxt = -_t32*_t63 + _t61*_t62;
  out[15] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = -_hc0[2]*_t64 + _t17*_t18*_t2*_t3*_t33*_t34*_t5*_t8*params->lm_f;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dxt = (0.21e2 / 0.4e1)*_t1*_t18*_t22*_t23*_t24*_t38*_t8 - _t13*_t66 - _t41*_t65;
  out[17] = d3f_drs2_dxt;
  const double d3f_drs2_dz = (0.3e1 / 0.4e1)*_hc0[1]*_t14*_t18*_t2*_t3*_t38*_t5*_t8*params->lm_f - _t41*_t67;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = -0.27e2 / 0.8e1*_t40*_t68 + _t42*_t72 + _t46*_t71;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = (0.9e1 / 0.2e1)*_t10*_t74 + 0.36e2*_t26 - _t46*_t73;
  out[20] = d4f_dxt4;
  const double d4f_dz_dxt3 = _t45*_t47 - 0.18e2*_t61*xt + 0.6e1*_t75;
  out[21] = d4f_dz_dxt3;
  const double d4f_dz2_dxt2 = 0.4e1*_hc0[2]*_t14*_t2*_t3*_t5*_t8*params->lm_f*xt + 0.6e1*_t10*_t22*_t23*_t24*_t33*_t34*_t8 - _t27*_t76 + 0.8e1*_t33*_t34*_t8 - _t48 - _t51*_t6;
  out[22] = d4f_dz2_dxt2;
  const double d4f_dz3_dxt = -_hc0[3]*_t28*xt + _hc0[3]*_t53 - _t58*_t73 - _t6*_t77*_t78 + _t73*_t77 + _t78*_t79;
  out[23] = d4f_dz3_dxt;
  const double d4f_dz4 = ((_hc0[2]) * (_hc0[2]))*_t49*_t56 - 0.72e2*_hc0[2]*_t34*_t57*_t80 + 0.16e2*_hc0[3]*_t30*_t49 - _hc0[4]*_t16 + 0.48e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t80/xc_powi((_hc0[0]), 5);
  out[24] = d4f_dz4;
  const double d4f_drs_dxt3 = (0.27e2 / 0.2e1)*_t1*_t10*_t17*_t3*_t43*_t44*_t8 + 0.3e1*_t1*_t17*_t2*_t3*_t5*_t8*params->lm_f - 0.9e1 / 0.4e1*_t19*_t74 - 0.27e2*_t35*xt;
  out[25] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxt2 = 0.9e1*_hc0[1]*_t10*_t14*_t17*_t22*_t23*_t24*_t8 - _t59*_t75*xt - _t62*_t81;
  out[26] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxt = _t10*_t50*_t59*_t6 - _t25*_t50*_t82 - _t54*_t63 + _t62*_t76;
  out[27] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = 0.3e1*_hc0[1]*_hc0[2]*_t17*_t18*_t2*_t3*_t33*_t5*_t8*params->lm_f - _hc0[3]*_t64 - _t79*_t82;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dxt2 = (0.45e2 / 0.2e1)*_t10*_t39 - 0.9e1 / 0.2e1*_t12*_t38*xt - 0.33e2 / 0.4e1*_t18*_t65 + (0.9e1 / 0.8e1)*_t38*_t40*_t74;
  out[29] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxt = -0.21e2 / 0.4e1*_t18*_t67 + _t32*_t66 + _t81*_t83;
  out[30] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = (0.3e1 / 0.4e1)*_hc0[2]*_t14*_t18*_t2*_t3*_t38*_t5*_t8*params->lm_f + (0.3e1 / 0.2e1)*_t22*_t23*_t24*_t33*_t34*_t38*_t40*_t8 - _t36*_t38*_t55 - _t76*_t83;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dxt = (0.45e2 / 0.8e1)*_t1*_t10*_t2*_t3*_t4*_t5*_t8*params->lm_f + (0.21e2 / 0.4e1)*_t1*_t3*_t4*_t40*_t43*_t44*_t8 - 0.153e3 / 0.8e1*_t18*_t68 - 0.9e1 / 0.16e2*_t70*_t74;
  out[32] = d4f_drs3_dxt;
  const double d4f_drs3_dz = (0.27e2 / 0.8e1)*_hc0[1]*_t14*_t22*_t23*_t24*_t4*_t40*_t8 - _t18*_t72*_t75 - _t71*_t81;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = (0.261e3 / 0.16e2)*_t26*_t40*_t84 - 0.105e3 / 0.16e2*_t42*_t84 - 0.27e2 / 0.8e1*_t46*_t69*_t84 + (0.9e1 / 0.32e2)*_t74*_t84*xc_powi(xt, 6);
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lm_t1_z0_k, _KMAX)(const xc_func_type *p, double xs0, double xs1, double *out) {

  const double _t1 = M_CBRT2;
#if _KMAX >= 1
  const double _t2 = (0.7e1 / 0.18e2)*_t1;
#endif
#if _KMAX >= 2
  const double _t3 = -_t2;
#endif

  const double f = -0.7e1 / 0.36e2*_t1*((xs0 * xs0) + (xs1 * xs1));
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = -_t2*xs1;
  out[1] = df_dxs1;
  const double df_dxs0 = -_t2*xs0;
  out[2] = df_dxs0;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = _t3;
  out[3] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[4] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = _t3;
  out[5] = d2f_dxs02;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[6] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[7] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[8] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[9] = d3f_dxs03;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[10] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[11] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[12] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[13] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[14] = d4f_dxs04;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lm_t2_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {
  const gga_c_lm_params *params = (const gga_c_lm_params *)(p->params);

  const double _t1 = xc_powr(0.3e1, 1, 2);
  const double _t2 = _t1*xt;
  const double _t3 = xc_powr(0.2e1, 2, 3);
  const double _t4 = (0.1e1 / (rs * rs * rs));
  const double _t5 = xc_powr(_t4, 1, 6);
  const double _t6 = _t3*_t5*params->lm_f;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = exp(-_t2*_t7);
  const double _t9 = (xt * xt);
  const double _t10 = _t8*_t9;
#if _KMAX >= 1
  const double _t11 = _t1*_t6;
  const double _t12 = _t10*_t11;
  const double _t13 = (0.1e1 / rs);
  const double _t14 = (xt * xt * xt);
  const double _t15 = _t13*_t14;
#endif
#if _KMAX >= 2
  const double _t16 = 0.4e1*_t8;
  const double _t17 = M_CBRT2;
  const double _t18 = xc_powr(_t4, 1, 3);
  const double _t19 = ((params->lm_f) * (params->lm_f));
  const double _t20 = _t17*_t18*_t19;
  const double _t21 = 0.3e1*_t10;
  const double _t22 = _t20*_t8;
  const double _t23 = _t14*_t22;
  const double _t24 = (0.3e1 / 0.2e1)*_t13;
  const double _t25 = (xt * xt * xt * xt);
  const double _t26 = _t22*_t25;
  const double _t27 = (0.1e1 / (rs * rs));
  const double _t28 = (0.3e1 / 0.4e1)*_t27;
  const double _t29 = _t11*_t8;
  const double _t30 = _t14*_t29;
#endif
#if _KMAX >= 3
  const double _t31 = xc_powr(_t4, 1, 2);
  const double _t32 = ((params->lm_f) * (params->lm_f) * (params->lm_f));
  const double _t33 = _t31*_t32;
  const double _t34 = _t1*_t33;
  const double _t35 = _t2*_t8;
  const double _t36 = _t35*_t6;
  const double _t37 = _t34*_t8;
  const double _t38 = _t14*_t37;
  const double _t39 = xc_powi(xt, 5);
  const double _t40 = _t39*_t4;
#endif
#if _KMAX >= 4
  const double _t41 = _t3*xc_powr(_t4, 2, 3)*((params->lm_f) * (params->lm_f) * (params->lm_f) * (params->lm_f));
  const double _t42 = _t41*_t8;
  const double _t43 = (0.1e1 / (rs * rs * rs * rs));
#endif

  const double f = 0.2e1*_t10;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = -_t12 + 0.4e1*_t8*xt;
  out[1] = df_dxt;
  const double df_drs = _t1*_t15*_t7*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = -_t11*_t16*xt + _t16 + _t20*_t21;
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = (0.3e1 / 0.2e1)*_t1*_t13*_t3*_t5*_t8*_t9*params->lm_f - _t23*_t24;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = _t26*_t28 - _t28*_t30;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0.18e2*_t17*_t18*_t19*_t8*xt - _t21*_t34 - 0.6e1*_t29;
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = -0.9e1*_t10*_t13*_t20 + 0.3e1*_t13*_t36 + _t24*_t38;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = -0.9e1 / 0.4e1*_t12*_t27 + (0.21e2 / 0.4e1)*_t14*_t17*_t18*_t19*_t27*_t8 - _t25*_t28*_t37;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = -0.27e2 / 0.8e1*_t26*_t4 + (0.15e2 / 0.8e1)*_t30*_t4 + (0.3e1 / 0.8e1)*_t37*_t40;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = (0.9e1 / 0.2e1)*_t10*_t41 + 0.36e2*_t22 - 0.24e2*_t33*_t35;
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = 0.3e1*_t1*_t13*_t3*_t5*_t8*params->lm_f + (0.27e2 / 0.2e1)*_t1*_t13*_t31*_t32*_t8*_t9 - 0.27e2*_t13*_t22*xt - 0.9e1 / 0.4e1*_t15*_t42;
  out[11] = d4f_drs_dxt3;
  const double d4f_drs2_dxt2 = (0.45e2 / 0.2e1)*_t10*_t20*_t27 + (0.9e1 / 0.8e1)*_t25*_t27*_t42 - 0.9e1 / 0.2e1*_t27*_t36 - 0.33e2 / 0.4e1*_t27*_t38;
  out[12] = d4f_drs2_dxt2;
  const double d4f_drs3_dxt = (0.21e2 / 0.4e1)*_t1*_t25*_t31*_t32*_t4*_t8 + (0.45e2 / 0.8e1)*_t1*_t3*_t4*_t5*_t8*_t9*params->lm_f - 0.153e3 / 0.8e1*_t23*_t4 - 0.9e1 / 0.16e2*_t40*_t42;
  out[13] = d4f_drs3_dxt;
  const double d4f_drs4 = (0.261e3 / 0.16e2)*_t26*_t43 - 0.105e3 / 0.16e2*_t30*_t43 - 0.27e2 / 0.8e1*_t37*_t39*_t43 + (0.9e1 / 0.32e2)*_t42*_t43*xc_powi(xt, 6);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(hl_f_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = 0.30e2/rs;
  const double _t3 = xc_log1p(_t2);
  const double _t4 = (rs * rs * rs);
  const double _t5 = (0.1e1 / 0.27000e5)*_t4 + 0.1e1;
#if _KMAX >= 1
  const double _t6 = (0.1e1 / _t1);
  const double _t7 = _t2 + 0.1e1;
  const double _t8 = (0.1e1 / _t7);
#endif
#if _KMAX >= 2
  const double _t9 = 5.6000000000000006e-6*_t3;
  const double _t10 = (0.1e1 / (_t7 * _t7));
  const double _t11 = (0.1e1 / (rs * rs * rs * rs));
  const double _t12 = _t11*_t5;
  const double _t13 = (0.1e1 / _t4);
  const double _t14 = _t5*_t8;
#endif
#if _KMAX >= 3
  const double _t15 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t16 = _t5/xc_powi(rs, 6);
  const double _t17 = xc_powi(rs, -5);
#endif

  const double f = 2.8e-5*_t1 - 0.0252*_t3*_t5 - 0.00042000000000000002*rs + 0.0083999999999999995;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -2.8000000000000003e-6*_t1*_t3 + 0.75600000000000001*_t5*_t6*_t8 + 5.5999999999999999e-5*rs - 0.00042000000000000002;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 22.68*_t10*_t12 - 1.512*_t13*_t14 + 0.00016800000000000002*_t8 - _t9*rs + 5.5999999999999999e-5;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -136.07999999999998*_t10*_t17*_t5 + 0.0075600000000000007*_t10*_t6 + 4.5359999999999996*_t12*_t8 + 1360.8*_t15*_t16 - _t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.030240000000000003*_t10*_t13 + 816.47999999999979*_t10*_t16 + 0.6048*_t11*_t15 - 18.143999999999998*_t14*_t17 - 16329.599999999999*_t15*_t5/xc_powi(rs, 7) + 122472.0*_t5/((_t7 * _t7 * _t7 * _t7)*xc_powi(rs, 8)) + 0.00067200000000000007*_t6*_t8;
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_c_lm_params *params = (const gga_c_lm_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = M_CBRT2;
  const double _t2 = xc_powr(gaa, 1, 2);
  const double _t3 = xc_powr(na, 4, 3);
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = _t1*_t5;
  const double _t7 = xc_powr(na, 1, 3);
  const double _t8 = xc_powr(0.6e1, 1, 3);
  const double _t9 = (0.1e1 / (M_CBRTPI));
  const double _t10 = _t8*_t9;
  const double _t11 = (0.1e1 / 0.2e1)*_t10/_t7;
  const double _t13 = xc_powr(0.3e1, 2, 3);
  const double _t14 = (0.1e1 / (M_PI * M_CBRTPI * M_CBRTPI));
  const double _t15 = _t13*_t14;
  const double _t17 = (0.1e1 / 0.144e3)*_t7;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lm_t1_z0_k, _KMAX)(p, _t6, _t6, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lm_t2_z0_k, _KMAX)(p, _t11, _t5, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(hl_f_zeta0_k, _KMAX)(p, _t11, _hc2);
  const double _t12 = _hc0[0] + _hc1[0];
  const double _t16 = _t12*_t15;
  const double _t18 = _hc2[0] + _t16*_t17;
  const double zk = _t18;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t20 = (0.1e1 / 0.6e1)*_t4;
  const double _t21 = xc_powr(na, -2, 3);
  const double _t24 = xc_powr(na, -7, 3);
  const double _t25 = (0.4e1 / 0.3e1)*_t24;
  const double _t26 = _t2*_t25;
  const double _t27 = _t1*_t26;
  const double _t28 = _t10*_t20;
  const double _t30 = _t15*_t17;
  const double _t31 = (0.1e1 / _t2);
  const double _t33 = (0.1e1 / 0.2e1)*_t4;
  const double _t35 = _t31*_t33;
  const double _t39 = (0.1e1 / 0.144e3)*_t3;
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lm_t1_z0_k, _KMAX)(p, 0, _t6, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lm_t1_z0_k, _KMAX)(p, _t6, 0, _hc4);
  const double _t19 = _hc2[1]*_t10;
  const double _t22 = _t16*_t21;
  const double _t23 = _hc1[1]*_t2;
  const double _t29 = -_hc1[2]*_t28 - _hc3[1]*_t27 - _hc4[2]*_t27 - _t23*_t25;
  const double _t32 = _hc1[1]*_t31;
  const double _t34 = _hc3[1]*_t1;
  const double _t36 = _hc4[2]*_t1;
  const double _t37 = _t32*_t33 + _t34*_t35 + _t35*_t36;
  const double _t38 = _t15*_t37;
  const double dF_dna = _t18 + na*(-_t19*_t20 + (0.1e1 / 0.432e3)*_t22 + _t29*_t30);
  const double dF_dgaa = _t38*_t39;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t42 = (0.2e1 / 0.9e1)*_t24;
  const double _t43 = xc_powr(na, -8, 3);
  const double _t46 = xc_powr(na, -5, 3);
  const double _t48 = (0.1e1 / 0.216e3)*_t21;
  const double _t49 = xc_powr(na, -10, 3);
  const double _t50 = (0.28e2 / 0.9e1)*_t49;
  const double _t51 = xc_powr(0.2e1, 2, 3);
  const double _t54 = xc_powr(na, -14, 3);
  const double _t55 = (0.16e2 / 0.9e1)*_t54;
  const double _t58 = _t2*_t50;
  const double _t63 = (0.1e1 / 0.432e3)*_t21;
  const double _t64 = xc_powr(na, -11, 3);
  const double _t65 = (0.2e1 / 0.3e1)*_t64;
  const double _t66 = _t51*_t65;
  const double _t67 = (0.2e1 / 0.3e1)*_t24;
  const double _t68 = _t31*_t67;
  const double _t69 = _t10*_t31;
  const double _t71 = (0.1e1 / 0.12e2)*_t43;
  const double _t73 = xc_powr(gaa, -3, 2);
  const double _t75 = (0.1e1 / 0.4e1)*_t4;
  const double _t76 = (0.1e1 / gaa);
  const double _t77 = _t73*_t75;
  double _hc5[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lm_t1_z0_k, _KMAX)(p, 0, 0, _hc5);
  const double _t40 = _t15*_t29;
  const double _t41 = (0.1e1 / 0.72e2)*_t40;
  const double _t44 = xc_powr(0.6e1, 2, 3)*_hc2[2]/(M_CBRTPI * M_CBRTPI);
  const double _t45 = _t43*_t44;
  const double _t47 = _t16*_t46;
  const double _t52 = _hc5[3]*_t51;
  const double _t53 = _t52*gaa;
  const double _t56 = _hc5[5]*_t51;
  const double _t57 = _t56*gaa;
  const double _t59 = _hc1[2]*_t10;
  const double _t60 = -_hc1[3]*_t26 - _hc1[4]*_t28;
  const double _t61 = -_hc1[4]*_t26 - _hc1[5]*_t28;
  const double _t62 = _t23*_t50 - _t26*_t60 - _t28*_t61 + _t34*_t58 + _t36*_t58 + _t42*_t59 + _t53*_t55 + _t55*_t57;
  const double _t70 = _hc1[4]*_t69;
  const double _t72 = -_hc1[3]*_t65 - _hc5[3]*_t66 - _hc5[5]*_t66 - _t32*_t67 - _t34*_t68 - _t36*_t68 - _t70*_t71;
  const double _t74 = _hc1[1]*_t73;
  const double _t78 = (0.1e1 / 0.4e1)*_hc1[3]*_t43*_t76 + (0.1e1 / 0.4e1)*_hc5[3]*_t43*_t51*_t76 + (0.1e1 / 0.4e1)*_hc5[5]*_t43*_t51*_t76 - _t34*_t77 - _t36*_t77 - _t74*_t75;
  const double _t79 = _t15*_t78;
  const double d2F_dna2 = -0.1e1 / 0.3e1*_t19*_t4 + (0.1e1 / 0.216e3)*_t22 + _t41*_t7 + na*(_t19*_t42 + _t30*_t62 + _t40*_t48 + (0.1e1 / 0.36e2)*_t45 - 0.1e1 / 0.648e3*_t47);
  const double d2F_dna_dgaa = _t30*_t37 + na*(_t30*_t72 + _t38*_t63);
  const double d2F_dgaa2 = _t39*_t79;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t81 = (0.1e1 / 0.48e2)*_t7;
  const double _t82 = (0.1e1 / (na * na * na * na));
  const double _t85 = (0.14e2 / 0.27e2)*_t49;
  const double _t88 = xc_powr(na, -13, 3);
  const double _t89 = (0.280e3 / 0.27e2)*_t88;
  const double _t90 = xc_powr(na, -17, 3);
  const double _t91 = (0.112e3 / 0.9e1)*_t90;
  const double _t92 = _t2*_t89;
  const double _t93 = _t10*_t42;
  const double _t103 = (0.14e2 / 0.9e1)*_t54;
  const double _t104 = (0.10e2 / 0.3e1)*_t54;
  const double _t105 = (0.14e2 / 0.9e1)*_t49;
  const double _t106 = _t105*_t31;
  const double _t107 = (0.1e1 / 0.9e1)*_t64;
  const double _t108 = _t69*_t71;
  const double _t112 = (0.1e1 / 0.3e1)*_t64;
  const double _t113 = xc_powi(na, -5);
  const double _t114 = (0.1e1 / 0.3e1)*_t113;
  const double _t115 = _t112*_t76;
  const double _t116 = (0.1e1 / 0.24e2)*_t10;
  const double _t117 = _t76*_t82;
  const double _t119 = xc_powr(gaa, -5, 2);
  const double _t121 = (0.3e1 / 0.8e1)*_t4;
  const double _t122 = (0.1e1 / (gaa * gaa));
  const double _t123 = (0.3e1 / 0.8e1)*_t43;
  const double _t125 = _t119*_t121;
  const double _t126 = _t122*_t123;
  const double _t80 = _t15*_t62;
  const double _t83 = _hc2[3]/M_PI;
  const double _t84 = _t82*_t83;
  const double _t86 = _t44*_t64;
  const double _t87 = _t40*_t46;
  const double _t94 = -_hc1[6]*_t26 - _hc1[7]*_t28;
  const double _t95 = -_hc1[7]*_t26 - _hc1[8]*_t28;
  const double _t96 = _hc1[3]*_t58 + _hc1[4]*_t93 - _t26*_t94 - _t28*_t95;
  const double _t97 = -_hc1[8]*_t26 - _hc1[9]*_t28;
  const double _t98 = _hc1[4]*_t58 + _hc1[5]*_t93 - _t26*_t95 - _t28*_t97;
  const double _t99 = (0.56e2 / 0.9e1)*_t2*_t49*_t60 - _t23*_t89 + (0.4e1 / 0.9e1)*_t24*_t61*_t8*_t9 - _t26*_t96 - _t28*_t98 - _t34*_t92 - _t36*_t92 - _t53*_t91 - _t57*_t91 - _t59*_t85;
  const double _t100 = _t15*_t72;
  const double _t101 = (0.1e1 / 0.72e2)*_t100;
  const double _t102 = _t38*_t46;
  const double _t109 = -_hc1[3]*_t68 - _hc1[6]*_t65 - _hc1[7]*_t108;
  const double _t110 = -_hc1[4]*_t68 - _hc1[7]*_t65 - _hc1[8]*_t108;
  const double _t111 = _hc1[3]*_t103 + _t104*_t52 + _t104*_t56 + _t105*_t32 + _t106*_t34 + _t106*_t36 + _t107*_t70 - _t109*_t26 - _t110*_t28 - _t60*_t68;
  const double _t118 = (0.1e1 / 0.3e1)*_hc1[1]*_t24*_t73 - _hc1[3]*_t112*_t76 + (0.1e1 / 0.24e2)*_hc1[4]*_t43*_t73*_t8*_t9 - _hc1[6]*_t114*_t31 - _hc1[7]*_t116*_t117 + (0.1e1 / 0.3e1)*_hc3[1]*_t1*_t24*_t73 + (0.1e1 / 0.3e1)*_hc4[2]*_t1*_t24*_t73 - _t115*_t52 - _t115*_t56;
  const double _t120 = _hc1[1]*_t119;
  const double _t124 = _hc1[6]*_t82;
  const double _t127 = -_hc1[3]*_t122*_t123 + _t120*_t121 + (0.1e1 / 0.8e1)*_t124*_t73 + _t125*_t34 + _t125*_t36 - _t126*_t52 - _t126*_t56;
  const double _t128 = _t127*_t15;
  const double d3F_dna3 = _t19*_t67 + _t21*_t41 + (0.1e1 / 0.12e2)*_t45 - 0.1e1 / 0.216e3*_t47 + _t80*_t81 + na*((0.5e1 / 0.1944e4)*_t12*_t13*_t14*_t43 + (0.1e1 / 0.144e3)*_t13*_t14*_t21*_t62 + (0.1e1 / 0.144e3)*_t13*_t14*_t7*_t99 - _t19*_t85 - 0.1e1 / 0.36e2*_t84 - 0.1e1 / 0.9e1*_t86 - 0.1e1 / 0.216e3*_t87);
  const double d3F_dna2_dgaa = _t101*_t7 + _t38*_t48 + na*(_t100*_t48 - 0.1e1 / 0.648e3*_t102 + _t111*_t30);
  const double d3F_dna_dgaa2 = _t30*_t78 + na*(_t118*_t30 + _t63*_t79);
  const double d3F_dgaa3 = _t128*_t39;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t129 = xc_powr(na, -16, 3);
  const double _t130 = (0.140e3 / 0.81e2)*_t88;
  const double _t131 = (0.3640e4 / 0.81e2)*_t129;
  const double _t132 = (0.6832e4 / 0.81e2)/xc_powr(na, 20, 3);
  const double _t133 = _t131*_t2;
  const double _t134 = _t10*_t85;
  const double _t139 = (0.476e3 / 0.27e2)*_t90;
  const double _t140 = (0.140e3 / 0.27e2)*_t88;
  const double _t141 = _t140*_t31;
  const double _t142 = _t107*_t69;
  const double _t145 = (0.7e1 / 0.9e1)*_t49;
  const double _t146 = _t145*_t73;
  const double _t147 = _t114*_t31;
  const double _t148 = _t116*_t117;
  const double _t149 = (0.1e1 / 0.2e1)*_t24;
  const double _t150 = _t119*_t149;
  const double _t151 = (0.15e2 / 0.16e2)*_t4/xc_powr(gaa, 7, 2);
  const double _t152 = (0.1e1 / (gaa * gaa * gaa));
  const double _t135 = -_hc1[11]*_t26 - _hc1[12]*_t28;
  const double _t136 = -_hc1[12]*_t26 - _hc1[13]*_t28;
  const double _t137 = _hc1[7]*_t58 + _hc1[8]*_t93 - _t135*_t26 - _t136*_t28;
  const double _t138 = _t111*_t15;
  const double _t143 = -_hc1[11]*_t65 - _hc1[12]*_t108 - _hc1[7]*_t68;
  const double _t144 = _t118*_t15;
  const double d4F_dna4 = (0.5e1 / 0.486e3)*_t12*_t13*_t14*_t43 + (0.1e1 / 0.36e2)*_t13*_t14*_t21*_t62 + (0.1e1 / 0.36e2)*_t13*_t14*_t7*_t99 - 0.56e2 / 0.27e2*_t19*_t49 - 0.1e1 / 0.9e1*_t84 - 0.4e1 / 0.9e1*_t86 - 0.1e1 / 0.54e2*_t87 + na*((0.1e1 / 0.216e3)*_hc2[4]*_t129*_t8/(M_PI * M_CBRTPI) + (0.2e1 / 0.9e1)*_t113*_t83 + _t130*_t19 + (0.1e1 / 0.108e3)*_t15*_t21*_t99 - 0.5e1 / 0.729e3*_t16*_t64 + _t30*(-_t10*_t105*_t61 + _t10*_t67*_t98 + _t130*_t59 + _t131*_t23 + _t132*_t53 + _t132*_t57 + _t133*_t34 + _t133*_t36 + (0.28e2 / 0.3e1)*_t2*_t49*_t96 - 0.280e3 / 0.9e1*_t2*_t60*_t88 - _t26*(-_hc1[3]*_t92 - _hc1[4]*_t134 - _t137*_t28 + (0.56e2 / 0.9e1)*_t2*_t49*_t94 + (0.4e1 / 0.9e1)*_t24*_t8*_t9*_t95 - _t26*(_hc1[6]*_t58 + _hc1[7]*_t93 - _t135*_t28 - _t26*(-_hc1[10]*_t26 - _hc1[11]*_t28))) - _t28*(-_hc1[4]*_t92 - _hc1[5]*_t134 - _t137*_t26 + (0.56e2 / 0.9e1)*_t2*_t49*_t95 + (0.4e1 / 0.9e1)*_t24*_t8*_t9*_t97 - _t28*(_hc1[8]*_t58 + _hc1[9]*_t93 - _t136*_t26 - _t28*(-_hc1[13]*_t26 - _hc1[14]*_t28)))) + (0.5e1 / 0.486e3)*_t40*_t43 + (0.40e2 / 0.81e2)*_t44*_t54 - 0.1e1 / 0.108e3*_t46*_t80);
  const double d4F_dna3_dgaa = _t101*_t21 - 0.1e1 / 0.216e3*_t102 + _t138*_t81 + na*(-0.1e1 / 0.216e3*_t100*_t46 + (0.1e1 / 0.144e3)*_t138*_t21 + _t30*(-0.140e3 / 0.27e2*_hc1[3]*_t90 + (0.56e2 / 0.9e1)*_t109*_t2*_t49 + (0.4e1 / 0.9e1)*_t110*_t24*_t8*_t9 - _t139*_t52 - _t139*_t56 - _t140*_t32 - _t141*_t34 - _t141*_t36 - _t26*(_hc1[3]*_t106 + _hc1[6]*_t103 + _hc1[7]*_t142 - _t143*_t28 - _t26*(-_hc1[10]*_t65 - _hc1[11]*_t108 - _hc1[6]*_t68) - _t68*_t94) - _t28*(_hc1[4]*_t106 + _hc1[7]*_t103 + _hc1[8]*_t142 - _t143*_t26 - _t28*(-_hc1[12]*_t65 - _hc1[13]*_t108 - _hc1[8]*_t68) - _t68*_t95) + (0.28e2 / 0.9e1)*_t31*_t49*_t60 - 0.7e1 / 0.27e2*_t54*_t70 - _t68*_t96) + (0.5e1 / 0.1944e4)*_t38*_t43);
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.72e2)*_t144*_t7 + _t48*_t79 + na*(_t144*_t48 + _t30*((0.7e1 / 0.9e1)*_hc1[3]*_t54*_t76 - 0.1e1 / 0.18e2*_hc1[4]*_t10*_t64*_t73 + (0.7e1 / 0.9e1)*_hc1[6]*_t31/xc_powi(na, 6) + (0.1e1 / 0.18e2)*_hc1[7]*_t113*_t76*_t8*_t9 + (0.7e1 / 0.9e1)*_hc5[3]*_t51*_t54*_t76 + (0.7e1 / 0.9e1)*_hc5[5]*_t51*_t54*_t76 - _t109*_t25*_t31 - _t145*_t74 - _t146*_t34 - _t146*_t36 + (0.1e1 / 0.3e1)*_t24*_t60*_t73 - _t26*(-_hc1[10]*_t147 - _hc1[11]*_t148 + (0.1e1 / 0.3e1)*_hc1[3]*_t24*_t73 - _hc1[6]*_t115 + (0.1e1 / 0.24e2)*_hc1[7]*_t43*_t73*_t8*_t9) - _t28*(-_hc1[11]*_t147 - _hc1[12]*_t148 + (0.1e1 / 0.3e1)*_hc1[4]*_t24*_t73 - _hc1[7]*_t115 + (0.1e1 / 0.24e2)*_hc1[8]*_t43*_t73*_t8*_t9)) - 0.1e1 / 0.648e3*_t46*_t79);
  const double d4F_dna_dgaa3 = _t127*_t30 + na*(_t128*_t63 + _t30*(-0.1e1 / 0.6e1*_hc1[10]*_t76/xc_powr(na, 19, 3) - 0.1e1 / 0.48e2*_hc1[11]*_t10*_t129*_t73 + (0.1e1 / 0.2e1)*_hc1[3]*_t122*_t64 - 0.1e1 / 0.16e2*_hc1[4]*_t10*_t119*_t43 + (0.1e1 / 0.16e2)*_hc1[7]*_t122*_t8*_t82*_t9 + (0.1e1 / 0.2e1)*_hc5[3]*_t122*_t51*_t64 + (0.1e1 / 0.2e1)*_hc5[5]*_t122*_t51*_t64 - _t120*_t149 - _t150*_t34 - _t150*_t36));
  const double d4F_dgaa4 = _t15*_t39*(-_hc1[1]*_t151 + (0.1e1 / 0.16e2)*_hc1[10]*_t122*_t129 + (0.15e2 / 0.16e2)*_hc1[3]*_t152*_t43 + (0.15e2 / 0.16e2)*_hc5[3]*_t152*_t43*_t51 + (0.15e2 / 0.16e2)*_hc5[5]*_t152*_t43*_t51 - 0.3e1 / 0.8e1*_t119*_t124 - _t151*_t34 - _t151*_t36);
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

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = xc_powr(gaa, 1, 2);
  const double _t6 = xc_powr(na, -4, 3);
  const double _t7 = _t5*_t6;
  const double _t8 = xc_powr(gbb, 1, 2);
  const double _t9 = xc_powr(nb, -4, 3);
  const double _t10 = _t8*_t9;
  const double _t11 = xc_powr(_t2, 1, 3);
  const double _t12 = xc_powr(0.6e1, 1, 3);
  const double _t13 = (0.1e1 / (M_CBRTPI));
  const double _t14 = _t12*_t13;
  const double _t15 = (0.1e1 / 0.2e1)*_t14;
  const double _t16 = _t15/_t11;
  const double _t17 = xc_powr(_t2, 4, 3);
  const double _t18 = (0.1e1 / _t17);
  const double _t19 = gaa + 0.2e1*gab + gbb;
  const double _t20 = xc_powr(_t19, 1, 2);
  const double _t21 = xc_powr(0.3e1, 2, 3);
  const double _t22 = (0.1e1 / (M_PI * M_CBRTPI * M_CBRTPI));
  const double _t23 = _t21*_t22;
  const double _t25 = (0.1e1 / 0.144e3)*_t11;
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lm_t1_k, _KMAX)(p, _t4, _t7, _t10, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lm_t2_k, _KMAX)(p, _t16, _t4, _t18*_t20, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(hl_f_k, _KMAX)(p, _t16, _t4, _hc2);
  const double _t24 = _t23*(_hc0[0] + _hc1[0]);
  const double _t26 = _hc2[0] + _t24*_t25;
  const double zk = _t26;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t28 = (0.1e1 / 0.6e1)*_t18;
  const double _t29 = xc_powr(_t2, -2, 3);
  const double _t32 = (0.1e1 / (_t2 * _t2));
  const double _t33 = _t1*_t32;
  const double _t34 = _t3 - _t33;
  const double _t37 = xc_powr(na, -7, 3);
  const double _t38 = (0.4e1 / 0.3e1)*_t37;
  const double _t39 = xc_powr(_t2, -7, 3);
  const double _t41 = (0.4e1 / 0.3e1)*_t20;
  const double _t42 = _t14*_t28;
  const double _t45 = _t23*_t25;
  const double _t47 = -_t3 - _t33;
  const double _t50 = xc_powr(nb, -7, 3);
  const double _t51 = (0.4e1 / 0.3e1)*_t50;
  const double _t54 = (0.1e1 / _t5);
  const double _t56 = (0.1e1 / 0.2e1)*_t6;
  const double _t57 = (0.1e1 / _t20);
  const double _t58 = _t18*_t57;
  const double _t62 = (0.1e1 / 0.144e3)*_t23;
  const double _t63 = _t17*_t62;
  const double _t66 = (0.1e1 / _t8);
  const double _t68 = (0.1e1 / 0.2e1)*_t9;
  double _hc3[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lm_t1_k, _KMAX)(p, _t4, _t7, 0, _hc3);
  double _hc4[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lm_t1_k, _KMAX)(p, _t4, 0, _t10, _hc4);
  const double _t27 = _hc2[2]*_t14;
  const double _t30 = _t24*_t29;
  const double _t31 = -_t27*_t28 + (0.1e1 / 0.432e3)*_t30;
  const double _t35 = _hc2[1]*_t34;
  const double _t36 = _hc3[2]*_t5;
  const double _t40 = _hc1[1]*_t39;
  const double _t43 = _hc1[3]*_t42 + _t40*_t41;
  const double _t44 = _hc0[3]*_t34 + _hc1[2]*_t34 - _t36*_t38 - _t43;
  const double _t46 = _t35 + _t44*_t45;
  const double _t48 = _hc2[1]*_t47;
  const double _t49 = _hc4[1]*_t8;
  const double _t52 = _hc0[3]*_t47 + _hc1[2]*_t47 - _t43 - _t49*_t51;
  const double _t53 = _t45*_t52 + _t48;
  const double _t55 = _hc3[2]*_t54;
  const double _t59 = (0.1e1 / 0.2e1)*_hc1[1];
  const double _t60 = _t58*_t59;
  const double _t61 = _t55*_t56 + _t60;
  const double _t64 = _hc1[1]*_t57;
  const double _t65 = _t62*_t64;
  const double _t67 = _hc4[1]*_t66;
  const double _t69 = _t60 + _t67*_t68;
  const double dF_dna = _t2*(_t31 + _t46) + _t26;
  const double dF_dnb = _t2*(_t31 + _t53) + _t26;
  const double dF_dgaa = _t61*_t63;
  const double dF_dgab = _t65;
  const double dF_dgbb = _t63*_t69;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t73 = xc_powr(_t2, -5, 3);
  const double _t75 = (0.2e1 / 0.9e1)*_t39;
  const double _t77 = 0.2e1*_t32;
  const double _t78 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t79 = 0.2e1*_t78;
  const double _t80 = _t1*_t79;
  const double _t81 = -_t77 + _t80;
  const double _t88 = _t38*_t5;
  const double _t91 = _t39*_t41;
  const double _t98 = xc_powr(na, -10, 3);
  const double _t99 = (0.28e2 / 0.9e1)*_t98;
  const double _t103 = xc_powr(_t2, -10, 3);
  const double _t104 = (0.28e2 / 0.9e1)*_t103;
  const double _t109 = (0.1e1 / 0.72e2)*_t11;
  const double _t110 = (0.1e1 / 0.3e1)*_t18;
  const double _t114 = _t51*_t8;
  const double _t126 = _t77 + _t80;
  const double _t131 = xc_powr(nb, -10, 3);
  const double _t132 = (0.28e2 / 0.9e1)*_t131;
  const double _t136 = _t23*_t29;
  const double _t137 = (0.1e1 / 0.432e3)*_t136;
  const double _t139 = xc_powr(na, -11, 3);
  const double _t140 = (0.2e1 / 0.3e1)*_t139;
  const double _t141 = (0.2e1 / 0.3e1)*_t37;
  const double _t142 = xc_powr(_t2, -11, 3);
  const double _t146 = (0.1e1 / 0.12e2)*_t14;
  const double _t147 = xc_powr(_t2, -8, 3);
  const double _t159 = (0.1e1 / 0.6e1)*_t14;
  const double _t172 = xc_powr(nb, -11, 3);
  const double _t173 = (0.2e1 / 0.3e1)*_t172;
  const double _t174 = (0.2e1 / 0.3e1)*_t50;
  const double _t177 = (0.1e1 / gaa);
  const double _t178 = xc_powr(na, -8, 3);
  const double _t179 = xc_powr(gaa, -3, 2);
  const double _t181 = (0.1e1 / 0.4e1)*_t6;
  const double _t182 = xc_powr(_t19, -3, 2);
  const double _t183 = _t18*_t182;
  const double _t184 = (0.1e1 / 0.4e1)*_t183;
  const double _t185 = (0.1e1 / _t19);
  const double _t192 = (0.1e1 / 0.288e3)*_t23;
  const double _t194 = (0.1e1 / gbb);
  const double _t195 = xc_powr(nb, -8, 3);
  const double _t196 = xc_powr(gbb, -3, 2);
  const double _t198 = (0.1e1 / 0.4e1)*_t9;
  double _hc5[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(lm_t1_k, _KMAX)(p, _t4, 0, 0, _hc5);
  const double _t70 = _t23*_t44;
  const double _t71 = _t29*_t70;
  const double _t72 = (0.1e1 / 0.216e3)*_t71;
  const double _t74 = _t24*_t73;
  const double _t76 = _t27*_t75 - 0.1e1 / 0.648e3*_t74;
  const double _t82 = _hc2[1]*_t81;
  const double _t83 = -_hc2[4]*_t42;
  const double _t84 = _hc2[3]*_t34 + _t83;
  const double _t85 = _t34*_t84;
  const double _t86 = -_hc2[5]*_t42;
  const double _t87 = _hc2[4]*_t34 + _t86;
  const double _t89 = _hc3[8]*_t88;
  const double _t90 = _hc0[9]*_t34 - _t89;
  const double _t92 = _hc1[5]*_t91 + _hc1[8]*_t42;
  const double _t93 = _hc1[6]*_t34 - _t92;
  const double _t94 = _hc3[8]*_t34;
  const double _t95 = -_hc5[6]*_t88 + _t94;
  const double _t96 = _hc1[4]*_t91 + _hc1[7]*_t42;
  const double _t97 = _hc1[5]*_t34 - _t96;
  const double _t100 = _hc1[7]*_t91 + _hc1[9]*_t42;
  const double _t101 = _hc1[8]*_t34 - _t100;
  const double _t102 = _hc1[1]*_t20;
  const double _t105 = _hc1[3]*_t14;
  const double _t106 = _t102*_t104 + _t105*_t75;
  const double _t107 = _hc0[3]*_t81 + _hc1[2]*_t81 - _t101*_t42 + _t106 + _t34*_t90 + _t34*_t93 + _t36*_t99 - _t88*_t95 - _t91*_t97;
  const double _t108 = _t107*_t45 - _t42*_t87 + _t82 + _t85;
  const double _t111 = -_t110*_t27 + (0.1e1 / 0.216e3)*_t30;
  const double _t112 = _hc2[3]*_t47 + _t83;
  const double _t113 = _t112*_t34;
  const double _t115 = _hc0[9]*_t47 - _hc4[7]*_t114;
  const double _t116 = _hc1[6]*_t47 - _t92;
  const double _t117 = _hc1[5]*_t47 - _t96;
  const double _t118 = _hc1[8]*_t47 - _t100;
  const double _t119 = _t106 - _t117*_t91 - _t118*_t42;
  const double _t120 = _hc0[3]*_t80 + _hc1[2]*_t80 + _t115*_t34 + _t116*_t34 + _t119 - _t47*_t89;
  const double _t121 = _t23*_t52;
  const double _t122 = _t121*_t29;
  const double _t123 = _hc2[4]*_t47 + _t86;
  const double _t124 = -_t123*_t42 + _t76;
  const double _t125 = (0.1e1 / 0.216e3)*_t122;
  const double _t127 = _hc2[1]*_t126;
  const double _t128 = _t112*_t47;
  const double _t129 = _hc4[7]*_t47;
  const double _t130 = -_hc5[4]*_t114 + _t129;
  const double _t133 = _hc0[3]*_t126 + _hc1[2]*_t126 - _t114*_t130 + _t115*_t47 + _t116*_t47 + _t119 + _t132*_t49;
  const double _t134 = _t127 + _t128 + _t133*_t45;
  const double _t135 = _t45*_t61;
  const double _t138 = _t137*_t61;
  const double _t143 = _hc1[4]*_t142;
  const double _t144 = (0.2e1 / 0.3e1)*_t143;
  const double _t145 = _t40*_t57;
  const double _t148 = _hc1[7]*_t147;
  const double _t149 = _t148*_t57;
  const double _t150 = _t144 + (0.2e1 / 0.3e1)*_t145 + _t146*_t149;
  const double _t151 = -0.1e1 / 0.2e1*_hc1[5]*_t18*_t34*_t57 + _t150;
  const double _t152 = (0.1e1 / 0.2e1)*_hc3[8]*_t34*_t54*_t6 - _hc5[6]*_t140 - _t141*_t55 - _t151;
  const double _t153 = _t152*_t45;
  const double _t154 = _t3*_t65;
  const double _t155 = _t23*_t64;
  const double _t156 = _t155*_t32;
  const double _t157 = (0.1e1 / 0.432e3)*_t156;
  const double _t158 = (0.4e1 / 0.3e1)*_t143;
  const double _t160 = (0.4e1 / 0.3e1)*_t145 + _t149*_t159 + _t158;
  const double _t161 = _hc1[5]*_t18*_t34*_t57 - _t160;
  const double _t162 = _t161*_t45;
  const double _t163 = _t45*_t69;
  const double _t164 = _t137*_t69;
  const double _t165 = (0.1e1 / 0.2e1)*_hc4[7]*_t34*_t66*_t9 - _t151;
  const double _t166 = _t165*_t45;
  const double _t167 = -0.1e1 / 0.2e1*_hc1[5]*_t18*_t47*_t57 + _t150;
  const double _t168 = (0.1e1 / 0.2e1)*_hc3[8]*_t47*_t54*_t6 - _t167;
  const double _t169 = _t168*_t45;
  const double _t170 = _hc1[5]*_t18*_t47*_t57 - _t160;
  const double _t171 = _t170*_t45;
  const double _t175 = (0.1e1 / 0.2e1)*_hc4[7]*_t47*_t66*_t9 - _hc5[4]*_t173 - _t167 - _t174*_t67;
  const double _t176 = _t175*_t45;
  const double _t180 = _hc3[2]*_t179;
  const double _t186 = _hc1[1]*_t184 - 0.1e1 / 0.4e1*_hc1[4]*_t147*_t185;
  const double _t187 = (0.1e1 / 0.4e1)*_hc5[6]*_t177*_t178 - _t180*_t181 - _t186;
  const double _t188 = (0.1e1 / 0.2e1)*_hc1[4]*_t147*_t185 - _t183*_t59;
  const double _t189 = -_t186;
  const double _t190 = _hc1[1]*_t182;
  const double _t191 = _t190*_t62;
  const double _t193 = _t190*_t192;
  const double _t197 = _hc4[1]*_t196;
  const double _t199 = (0.1e1 / 0.4e1)*_hc5[4]*_t194*_t195 - _t186 - _t197*_t198;
  const double d2F_dna2 = _t109*_t70 + _t111 + _t2*(_t108 + _t72 + _t76) + 0.2e1*_t35;
  const double d2F_dna_dnb = _t111 + _t2*(_hc2[1]*_t80 + _t113 + _t120*_t45 + (0.1e1 / 0.432e3)*_t122 + _t124 + (0.1e1 / 0.432e3)*_t71) + _t46 + _t53;
  const double d2F_dnb2 = _t109*_t121 + _t111 + _t2*(_t124 + _t125 + _t134) + 0.2e1*_t48;
  const double d2F_dna_dgaa = _t135 + _t2*(_t138 + _t153);
  const double d2F_dna_dgab = _t154 + _t2*(_t157 + _t162);
  const double d2F_dna_dgbb = _t163 + _t2*(_t164 + _t166);
  const double d2F_dnb_dgaa = _t135 + _t2*(_t138 + _t169);
  const double d2F_dnb_dgab = _t154 + _t2*(_t157 + _t171);
  const double d2F_dnb_dgbb = _t163 + _t2*(_t164 + _t176);
  const double d2F_dgaa2 = _t187*_t63;
  const double d2F_dgaa_dgab = _t188*_t63;
  const double d2F_dgaa_dgbb = _t189*_t63;
  const double d2F_dgab2 = (0.1e1 / 0.144e3)*_hc1[4]*_t18*_t185*_t21*_t22 - _t191;
  const double d2F_dgab_dgbb = (0.1e1 / 0.288e3)*_hc1[4]*_t18*_t185*_t21*_t22 - _t193;
  const double d2F_dgbb2 = _t199*_t63;
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
  const double _t202 = _t29*_t62;
  const double _t203 = (0.4e1 / 0.9e1)*_t39;
  const double _t204 = _t14*_t203;
  const double _t206 = (0.14e2 / 0.27e2)*_t103;
  const double _t209 = 0.6e1*_t78;
  const double _t210 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t211 = _t1*_t210;
  const double _t212 = 0.6e1*_t211;
  const double _t213 = _t209 - _t212;
  const double _t215 = _t14*_t75;
  const double _t223 = 0.2e1*_t81;
  const double _t228 = _t5*_t99;
  const double _t242 = _t104*_t20;
  const double _t245 = xc_powr(na, -13, 3);
  const double _t246 = (0.280e3 / 0.27e2)*_t245;
  const double _t257 = (0.56e2 / 0.9e1)*_t98;
  const double _t259 = (0.56e2 / 0.9e1)*_t103;
  const double _t265 = xc_powr(_t2, -13, 3);
  const double _t266 = (0.280e3 / 0.27e2)*_t265;
  const double _t272 = _t15*_t18;
  const double _t273 = (0.1e1 / 0.48e2)*_t23;
  const double _t274 = _t11*_t273;
  const double _t275 = (0.2e1 / 0.3e1)*_t39;
  const double _t277 = (0.1e1 / 0.216e3)*_t136;
  const double _t279 = -_t212 + 0.2e1*_t78;
  const double _t309 = 0.4e1*_t78;
  const double _t311 = _t109*_t23;
  const double _t315 = _t1*_t309;
  const double _t317 = (_t47 * _t47);
  const double _t320 = _t132*_t8;
  const double _t336 = -_t209 - _t212;
  const double _t339 = 0.2e1*_t126;
  const double _t340 = xc_powr(nb, -13, 3);
  const double _t341 = (0.280e3 / 0.27e2)*_t340;
  const double _t345 = (0.56e2 / 0.9e1)*_t131;
  const double _t346 = _t20*_t259;
  const double _t350 = _t23*_t73;
  const double _t351 = (0.1e1 / 0.648e3)*_t350;
  const double _t355 = _t141*_t54;
  const double _t358 = xc_powr(na, -14, 3);
  const double _t359 = (0.14e2 / 0.9e1)*_t358;
  const double _t360 = _t54*_t56;
  const double _t363 = (0.14e2 / 0.9e1)*_t98;
  const double _t364 = (0.2e1 / 0.3e1)*_t142;
  const double _t367 = _t147*_t57;
  const double _t368 = _t146*_t367;
  const double _t372 = _t275*_t57;
  const double _t379 = xc_powr(_t2, -14, 3);
  const double _t381 = (0.14e2 / 0.9e1)*_t103;
  const double _t382 = (0.1e1 / 0.9e1)*_t14;
  const double _t393 = (0.4e1 / 0.3e1)*_t142;
  const double _t395 = (0.4e1 / 0.3e1)*_t39;
  const double _t396 = _t159*_t367;
  const double _t400 = _t395*_t57;
  const double _t406 = (0.2e1 / 0.9e1)*_t14;
  const double _t413 = (_t34 * _t34);
  const double _t414 = _t66*_t68;
  const double _t420 = _t1*_t78;
  const double _t435 = _t174*_t66;
  const double _t448 = xc_powr(nb, -14, 3);
  const double _t449 = (0.14e2 / 0.9e1)*_t448;
  const double _t452 = (0.14e2 / 0.9e1)*_t131;
  const double _t457 = (0.1e1 / 0.3e1)*_t139;
  const double _t458 = _t179*_t181;
  const double _t461 = xc_powi(_t2, -5);
  const double _t462 = _t461*_t57;
  const double _t463 = (0.1e1 / 0.3e1)*_t185;
  const double _t464 = (0.1e1 / 0.24e2)*_t14;
  const double _t465 = _t185*_t210;
  const double _t483 = (0.1e1 / 0.6e1)*_t185;
  const double _t484 = _t210*_t483;
  const double _t488 = (0.1e1 / 0.432e3)*_t23;
  const double _t495 = (0.1e1 / 0.864e3)*_t23;
  const double _t500 = _t196*_t198;
  const double _t503 = _t458*_t47;
  const double _t515 = (0.1e1 / 0.3e1)*_t172;
  const double _t518 = (0.1e1 / (gaa * gaa));
  const double _t519 = (0.3e1 / 0.8e1)*_t178;
  const double _t520 = xc_powr(gaa, -5, 2);
  const double _t523 = xc_powr(_t19, -5, 2);
  const double _t524 = (0.3e1 / 0.8e1)*_t523;
  const double _t526 = (0.1e1 / (_t19 * _t19));
  const double _t545 = _t147*_t23;
  const double _t547 = (0.1e1 / (gbb * gbb));
  const double _t548 = (0.3e1 / 0.8e1)*_t195;
  const double _t549 = xc_powr(gbb, -5, 2);
  const double _t200 = _t70*_t73;
  const double _t201 = -0.1e1 / 0.216e3*_t200;
  const double _t205 = _t204*_t87;
  const double _t207 = _t147*_t24;
  const double _t208 = -_t206*_t27 + (0.5e1 / 0.1944e4)*_t207;
  const double _t214 = _hc2[1]*_t213;
  const double _t216 = _hc2[4]*_t215;
  const double _t217 = -_hc2[8]*_t42;
  const double _t218 = _hc2[7]*_t34 + _t217;
  const double _t219 = -_hc2[7]*_t42;
  const double _t220 = _hc2[6]*_t34 + _t219;
  const double _t221 = _hc2[3]*_t81 + _t216 - _t218*_t42 + _t220*_t34;
  const double _t222 = _t221*_t34;
  const double _t224 = _hc2[5]*_t215;
  const double _t225 = -_hc2[9]*_t42;
  const double _t226 = _hc2[8]*_t34 + _t225;
  const double _t227 = _hc2[4]*_t81 + _t218*_t34 + _t224 - _t226*_t42;
  const double _t229 = _hc3[8]*_t228;
  const double _t230 = _hc5[16]*_t88;
  const double _t231 = _hc3[18]*_t34;
  const double _t232 = -_t230 + _t231;
  const double _t233 = _hc3[18]*_t88;
  const double _t234 = _hc0[19]*_t34 - _t233;
  const double _t235 = _hc0[9]*_t81 + _t229 - _t232*_t88 + _t234*_t34;
  const double _t236 = _hc1[12]*_t91 + _hc1[16]*_t42;
  const double _t237 = _hc1[13]*_t34 - _t236;
  const double _t238 = _hc1[11]*_t91 + _hc1[15]*_t42;
  const double _t239 = _hc1[12]*_t34 - _t238;
  const double _t240 = _hc1[15]*_t91 + _hc1[18]*_t42;
  const double _t241 = _hc1[16]*_t34 - _t240;
  const double _t243 = _hc1[5]*_t242 + _hc1[8]*_t215;
  const double _t244 = _hc1[6]*_t81 + _t237*_t34 - _t239*_t91 - _t241*_t42 + _t243;
  const double _t247 = _hc3[8]*_t81;
  const double _t248 = _hc5[6]*_t228 - _t230*_t34 + _t232*_t34 + _t247;
  const double _t249 = _hc1[5]*_t81;
  const double _t250 = _hc1[10]*_t91 + _hc1[14]*_t42;
  const double _t251 = _hc1[11]*_t34 - _t250;
  const double _t252 = _hc1[14]*_t91 + _hc1[17]*_t42;
  const double _t253 = _hc1[15]*_t34 - _t252;
  const double _t254 = _hc1[4]*_t242 + _hc1[7]*_t215;
  const double _t255 = _t239*_t34 + _t249 - _t251*_t91 - _t253*_t42 + _t254;
  const double _t256 = _t5*_t95;
  const double _t258 = _t20*_t97;
  const double _t260 = _hc1[17]*_t91 + _hc1[19]*_t42;
  const double _t261 = _hc1[18]*_t34 - _t260;
  const double _t262 = _hc1[7]*_t242 + _hc1[9]*_t215;
  const double _t263 = _hc1[8]*_t81 + _t241*_t34 - _t253*_t91 - _t261*_t42 + _t262;
  const double _t264 = _t101*_t14;
  const double _t267 = _t102*_t266;
  const double _t268 = _t105*_t206;
  const double _t269 = -_t267 - _t268;
  const double _t270 = _hc0[3]*_t213 + _hc1[2]*_t213 + _t203*_t264 + _t223*_t90 + _t223*_t93 + _t235*_t34 + _t244*_t34 - _t246*_t36 - _t248*_t88 - _t255*_t91 + _t256*_t257 + _t258*_t259 - _t263*_t42 + _t269;
  const double _t271 = _t214 + _t222 + _t223*_t84 - _t227*_t42 + _t270*_t45;
  const double _t276 = _t27*_t275 - 0.1e1 / 0.216e3*_t74;
  const double _t278 = _t120*_t277;
  const double _t280 = _hc2[1]*_t279;
  const double _t281 = _hc2[6]*_t47 + _t219;
  const double _t282 = _hc2[7]*_t47 + _t217;
  const double _t283 = _t216 - _t282*_t42;
  const double _t284 = _hc2[3]*_t80 + _t281*_t34 + _t283;
  const double _t285 = _t284*_t34;
  const double _t286 = _t112*_t81;
  const double _t287 = _hc2[8]*_t47 + _t225;
  const double _t288 = _t224 - _t287*_t42;
  const double _t289 = _hc2[4]*_t80 + _t282*_t34 + _t288;
  const double _t290 = _t121*_t73;
  const double _t291 = _hc0[19]*_t47 - _hc4[17]*_t114;
  const double _t292 = _hc0[9]*_t80 - _t233*_t47 + _t291*_t34;
  const double _t293 = _hc1[13]*_t47 - _t236;
  const double _t294 = _hc1[12]*_t47 - _t238;
  const double _t295 = _hc1[16]*_t47 - _t240;
  const double _t296 = _t243 - _t294*_t91 - _t295*_t42;
  const double _t297 = _hc1[6]*_t80 + _t293*_t34 + _t296;
  const double _t298 = _t231*_t47;
  const double _t299 = _hc3[8]*_t80 - _t230*_t47 + _t298;
  const double _t300 = _hc1[11]*_t47 - _t250;
  const double _t301 = _hc1[15]*_t47 - _t252;
  const double _t302 = _t254 - _t300*_t91 - _t301*_t42;
  const double _t303 = _hc1[5]*_t80 + _t294*_t34 + _t302;
  const double _t304 = _hc1[18]*_t47 - _t260;
  const double _t305 = _t262 - _t301*_t91 - _t304*_t42;
  const double _t306 = _hc1[8]*_t80 + _t295*_t34 + _t305;
  const double _t307 = _hc0[3]*_t279 + _hc1[2]*_t279 + _t101*_t215 + _t115*_t81 + _t116*_t81 + _t117*_t242 + _t118*_t215 + _t229*_t47 + _t242*_t97 + _t269 + _t292*_t34 + _t297*_t34 - _t299*_t88 - _t303*_t91 - _t306*_t42 + _t80*_t90 + _t80*_t93;
  const double _t308 = _t123*_t14;
  const double _t310 = _hc2[1]*_t309;
  const double _t312 = _t1*_t310 + 0.2e1*_t113 + _t120*_t311;
  const double _t313 = _hc2[3]*_t126 + _t281*_t47 + _t283;
  const double _t314 = _t313*_t34;
  const double _t316 = _hc3[8]*_t126;
  const double _t318 = _hc3[18]*_t317;
  const double _t319 = _t316 + _t318;
  const double _t321 = _hc5[14]*_t114;
  const double _t322 = _hc4[17]*_t47;
  const double _t323 = -_t321 + _t322;
  const double _t324 = _hc0[9]*_t126 + _hc4[7]*_t320 - _t114*_t323 + _t291*_t47;
  const double _t325 = _hc1[8]*_t126 + _t295*_t47 + _t305;
  const double _t326 = _t325*_t42;
  const double _t327 = _hc1[5]*_t126;
  const double _t328 = _t294*_t47 + _t302 + _t327;
  const double _t329 = _t328*_t91;
  const double _t330 = _hc1[6]*_t126 + _t293*_t47 + _t296;
  const double _t331 = -_hc0[3]*_t212 - _hc0[3]*_t79 - _hc1[2]*_t212 - _hc1[2]*_t79 + 0.4e1*_t1*_t115*_t78 + 0.4e1*_t1*_t116*_t78 + (0.56e2 / 0.9e1)*_t103*_t117*_t20 + (0.4e1 / 0.9e1)*_t118*_t12*_t13*_t39 - _t267 - _t268 - _t319*_t88 + _t324*_t34 - _t326 - _t329 + _t330*_t34;
  const double _t332 = _hc2[4]*_t126 + _t282*_t47 + _t288;
  const double _t333 = _t123*_t204 + _t208 - _t332*_t42;
  const double _t334 = -_t123*_t272 + _t276;
  const double _t335 = -0.1e1 / 0.216e3*_t290;
  const double _t337 = _hc2[1]*_t336;
  const double _t338 = _t313*_t47;
  const double _t342 = _hc4[7]*_t126;
  const double _t343 = _hc5[4]*_t320 - _t321*_t47 + _t323*_t47 + _t342;
  const double _t344 = _t130*_t8;
  const double _t347 = _hc0[3]*_t336 + _hc1[2]*_t336 - _t114*_t343 + _t115*_t339 + _t116*_t339 + _t117*_t346 + _t118*_t204 + _t269 + _t324*_t47 - _t326 - _t329 + _t330*_t47 - _t341*_t49 + _t344*_t345;
  const double _t348 = _t112*_t339 + _t337 + _t338 + _t347*_t45;
  const double _t349 = _t277*_t61;
  const double _t352 = -_t351*_t61;
  const double _t353 = _t152*_t277;
  const double _t354 = _hc5[16]*_t140;
  const double _t356 = _hc3[8]*_t355;
  const double _t357 = (0.1e1 / 0.2e1)*_hc3[18]*_t34*_t54*_t6 - _t354 - _t356;
  const double _t361 = _hc5[16]*_t34;
  const double _t362 = -_hc5[6]*_t355 + _t360*_t361;
  const double _t365 = _hc1[11]*_t364;
  const double _t366 = _hc1[5]*_t57;
  const double _t369 = _hc1[15]*_t368 + _t275*_t366 + _t365;
  const double _t370 = (0.1e1 / 0.2e1)*_hc1[12]*_t18*_t34*_t57 - _t369;
  const double _t371 = _hc1[10]*_t364;
  const double _t373 = _hc1[14]*_t368 + _hc1[4]*_t372 + _t371;
  const double _t374 = (0.1e1 / 0.2e1)*_hc1[11]*_t18*_t34*_t57 - _t373;
  const double _t375 = _t249*_t58;
  const double _t376 = _hc1[14]*_t364;
  const double _t377 = _hc1[17]*_t368 + _hc1[7]*_t372 + _t376;
  const double _t378 = (0.1e1 / 0.2e1)*_hc1[15]*_t18*_t34*_t57 - _t377;
  const double _t380 = _hc1[4]*_t379;
  const double _t383 = _hc1[7]*_t57;
  const double _t384 = _t142*_t383;
  const double _t385 = (0.14e2 / 0.9e1)*_t380 + _t381*_t64 + _t382*_t384;
  const double _t386 = _t34*_t370 - _t372*_t97 - _t374*_t91 + (0.1e1 / 0.2e1)*_t375 - _t378*_t42 + _t385;
  const double _t387 = _hc5[6]*_t359 + _t247*_t360 + _t34*_t357 - _t355*_t95 - _t362*_t88 + _t363*_t55 + _t386;
  const double _t388 = _t387*_t45;
  const double _t389 = (0.1e1 / 0.216e3)*_t156;
  const double _t390 = _t155*_t78;
  const double _t391 = -0.1e1 / 0.648e3*_t390;
  const double _t392 = _t161*_t277;
  const double _t394 = _hc1[11]*_t393;
  const double _t397 = _hc1[15]*_t396 + _t366*_t395 + _t394;
  const double _t398 = _hc1[12]*_t18*_t34*_t57 - _t397;
  const double _t399 = _hc1[10]*_t393;
  const double _t401 = _hc1[14]*_t396 + _hc1[4]*_t400 + _t399;
  const double _t402 = _hc1[11]*_t18*_t34*_t57 - _t401;
  const double _t403 = _hc1[14]*_t393;
  const double _t404 = _hc1[17]*_t396 + _hc1[7]*_t400 + _t403;
  const double _t405 = _hc1[15]*_t18*_t34*_t57 - _t404;
  const double _t407 = _t104*_t64 + (0.28e2 / 0.9e1)*_t380 + _t384*_t406;
  const double _t408 = _t34*_t398 + _t375 - _t400*_t97 - _t402*_t91 - _t405*_t42 + _t407;
  const double _t409 = _t408*_t45;
  const double _t410 = _t277*_t69;
  const double _t411 = -_t351*_t69;
  const double _t412 = _t165*_t277;
  const double _t415 = _hc4[17]*_t414;
  const double _t416 = _hc4[7]*_t66;
  const double _t417 = _t416*_t68;
  const double _t418 = _t386 + _t413*_t415 + _t417*_t81;
  const double _t419 = _t418*_t45;
  const double _t421 = _hc3[8]*_t54*_t6;
  const double _t422 = (0.1e1 / 0.2e1)*_hc1[12]*_t18*_t47*_t57 - _t369;
  const double _t423 = _t265*_t366;
  const double _t424 = _t1*_t423;
  const double _t425 = (0.1e1 / 0.2e1)*_hc1[11]*_t18*_t47*_t57 - _t373;
  const double _t426 = (0.1e1 / 0.2e1)*_hc1[15]*_t18*_t47*_t57 - _t377;
  const double _t427 = -_t117*_t372 + _t385 - _t42*_t426 - _t425*_t91;
  const double _t428 = _t34*_t422 + _t424 + _t427;
  const double _t429 = _t298*_t360 - _t354*_t47 - _t356*_t47 + _t420*_t421 + _t428;
  const double _t430 = _hc1[12]*_t18*_t47*_t57 - _t397;
  const double _t431 = _hc1[11]*_t18*_t47*_t57 - _t401;
  const double _t432 = _hc1[15]*_t18*_t47*_t57 - _t404;
  const double _t433 = -_t117*_t400 + _t407 - _t42*_t432 - _t431*_t91;
  const double _t434 = _t34*_t430 + 0.2e1*_t424 + _t433;
  const double _t436 = (0.1e1 / 0.2e1)*_hc4[17]*_t47*_t66*_t9 - _hc4[7]*_t435 - _hc5[14]*_t173;
  const double _t437 = _t416*_t9;
  const double _t438 = _t34*_t436 + _t420*_t437 + _t428;
  const double _t439 = _t168*_t277;
  const double _t440 = _t327*_t58;
  const double _t441 = _t422*_t47 + _t427 + (0.1e1 / 0.2e1)*_t440;
  const double _t442 = _t316*_t360 + _t318*_t360 + _t441;
  const double _t443 = _t442*_t45;
  const double _t444 = _t170*_t277;
  const double _t445 = _t430*_t47 + _t433 + _t440;
  const double _t446 = _t445*_t45;
  const double _t447 = _t175*_t277;
  const double _t450 = _hc5[14]*_t47;
  const double _t451 = -_hc5[4]*_t435 + _t414*_t450;
  const double _t453 = _hc5[4]*_t449 - _t114*_t451 - _t130*_t435 + _t342*_t414 + _t436*_t47 + _t441 + _t452*_t67;
  const double _t454 = _t45*_t453;
  const double _t455 = _t187*_t45;
  const double _t456 = _t137*_t187;
  const double _t459 = _hc1[5]*_t34;
  const double _t460 = (0.1e1 / 0.3e1)*_hc1[10];
  const double _t466 = _hc1[14]*_t465;
  const double _t467 = -0.1e1 / 0.3e1*_hc1[1]*_t182*_t39 - 0.1e1 / 0.24e2*_hc1[7]*_t12*_t13*_t147*_t182 + _t143*_t463 + _t460*_t462 + _t464*_t466;
  const double _t468 = -0.1e1 / 0.4e1*_hc1[11]*_t147*_t185*_t34 + _t184*_t459 + _t467;
  const double _t469 = (0.1e1 / 0.3e1)*_hc3[2]*_t179*_t37 + (0.1e1 / 0.4e1)*_hc5[16]*_t177*_t178*_t34 - _hc5[6]*_t177*_t457 - _t458*_t94 - _t468;
  const double _t470 = _t45*_t469;
  const double _t471 = _t188*_t45;
  const double _t472 = _t137*_t188;
  const double _t473 = _t183*_t459;
  const double _t474 = _hc1[10]*_t462;
  const double _t475 = -0.2e1 / 0.3e1*_hc1[1]*_t182*_t39 - 0.1e1 / 0.12e2*_hc1[7]*_t12*_t13*_t147*_t182 + _t144*_t185 + _t146*_t466 + (0.2e1 / 0.3e1)*_t474;
  const double _t476 = (0.1e1 / 0.2e1)*_hc1[11]*_t147*_t185*_t34 - 0.1e1 / 0.2e1*_t473 - _t475;
  const double _t477 = _t45*_t476;
  const double _t478 = _t189*_t45;
  const double _t479 = _t137*_t189;
  const double _t480 = -_t468;
  const double _t481 = _t45*_t480;
  const double _t482 = _hc1[14]*_t14;
  const double _t485 = -0.4e1 / 0.3e1*_hc1[1]*_t182*_t39 - 0.1e1 / 0.6e1*_hc1[7]*_t12*_t13*_t147*_t182 + _t158*_t185 + (0.4e1 / 0.3e1)*_t474 + _t482*_t484;
  const double _t486 = _hc1[11]*_t147*_t185*_t34 - _t473 - _t485;
  const double _t487 = _t45*_t486;
  const double _t489 = _t190*_t32;
  const double _t490 = _hc1[4]*_t185;
  const double _t491 = _t103*_t490;
  const double _t492 = -_t488*_t489 + _t488*_t491;
  const double _t493 = _t39*_t490;
  const double _t494 = -_t191*_t3 + _t493*_t62;
  const double _t496 = -_t489*_t495 + _t491*_t495;
  const double _t497 = _t192*_t493 - _t193*_t3;
  const double _t498 = _t199*_t45;
  const double _t499 = _t137*_t199;
  const double _t501 = -_hc4[7]*_t34*_t500 + (0.1e1 / 0.4e1)*_hc5[14]*_t194*_t195*_t34 - _t468;
  const double _t502 = _t45*_t501;
  const double _t504 = _hc1[5]*_t47;
  const double _t505 = -0.1e1 / 0.4e1*_hc1[11]*_t147*_t185*_t47 + _t184*_t504 + _t467;
  const double _t506 = -_hc3[8]*_t503 + (0.1e1 / 0.4e1)*_hc5[16]*_t177*_t178*_t47 - _t505;
  const double _t507 = _t45*_t506;
  const double _t508 = _t183*_t504;
  const double _t509 = (0.1e1 / 0.2e1)*_hc1[11]*_t147*_t185*_t47 - _t475 - 0.1e1 / 0.2e1*_t508;
  const double _t510 = _t45*_t509;
  const double _t511 = -_t505;
  const double _t512 = _t45*_t511;
  const double _t513 = _hc1[11]*_t147*_t185*_t47 - _t485 - _t508;
  const double _t514 = _t45*_t513;
  const double _t516 = (0.1e1 / 0.3e1)*_hc4[1]*_t196*_t50 + (0.1e1 / 0.4e1)*_hc5[14]*_t194*_t195*_t47 - _hc5[4]*_t194*_t515 - _t129*_t500 - _t505;
  const double _t517 = _t45*_t516;
  const double _t521 = _hc3[2]*_t520;
  const double _t522 = _hc1[1]*_t18;
  const double _t525 = _hc1[10]*_t182*_t210;
  const double _t527 = _hc1[4]*_t147*_t526;
  const double _t528 = _t522*_t524 + (0.1e1 / 0.8e1)*_t525 - 0.3e1 / 0.8e1*_t527;
  const double _t529 = -_hc5[6]*_t518*_t519 + (0.3e1 / 0.8e1)*_t521*_t6 + _t528;
  const double _t530 = _t522*_t523;
  const double _t531 = (0.1e1 / 0.4e1)*_t525 - 0.3e1 / 0.4e1*_t527 + (0.3e1 / 0.4e1)*_t530;
  const double _t532 = _t531*_t63;
  const double _t533 = _t528*_t63;
  const double _t534 = (0.1e1 / 0.2e1)*_t525 - 0.3e1 / 0.2e1*_t527 + (0.3e1 / 0.2e1)*_t530;
  const double _t535 = _hc1[1]*_t523;
  const double _t536 = _t273*_t535;
  const double _t537 = _hc1[10]*_t182;
  const double _t538 = _t147*_t537;
  const double _t539 = _hc1[4]*_t526;
  const double _t540 = _t18*_t539;
  const double _t541 = _t23*_t535;
  const double _t542 = (0.1e1 / 0.96e2)*_t541;
  const double _t543 = _t23*_t540;
  const double _t544 = (0.1e1 / 0.192e3)*_t541;
  const double _t546 = (0.1e1 / 0.576e3)*_t537;
  const double _t550 = _hc4[1]*_t549;
  const double _t551 = -_hc5[4]*_t547*_t548 + _t528 + (0.3e1 / 0.8e1)*_t550*_t9;
  const double d3F_dna3 = _t107*_t274 + _t2*(_t107*_t202 + _t201 + _t205 + _t208 + _t271) - _t272*_t87 + _t276 + (0.1e1 / 0.72e2)*_t71 + 0.3e1*_t82 + 0.3e1*_t85;
  const double d3F_dna2_dnb = _t108 - _t110*_t308 + _t125 + _t2*(_t107*_t137 + _t123*_t215 - 0.1e1 / 0.324e3*_t200 + _t208 + _t215*_t87 + _t278 + _t280 + _t285 + _t286 - _t289*_t42 - 0.1e1 / 0.648e3*_t290 + _t307*_t45 + _t80*_t84) + _t276 + _t312 + (0.1e1 / 0.108e3)*_t71;
  const double d3F_dna_dnb2 = (0.1e1 / 0.108e3)*_t122 + _t134 + _t2*(-_hc2[1]*_t212 - _hc2[1]*_t79 + _t112*_t315 + _t133*_t137 - 0.1e1 / 0.648e3*_t200 + _t278 - 0.1e1 / 0.324e3*_t290 + _t314 + _t331*_t45 + _t333) + _t312 + _t334 + _t72;
  const double d3F_dnb3 = (0.1e1 / 0.72e2)*_t122 + 0.3e1*_t127 + 0.3e1*_t128 + _t133*_t274 + _t2*(_t133*_t202 + _t333 + _t335 + _t348) + _t334;
  const double d3F_dna2_dgaa = _t152*_t311 + _t2*(_t352 + _t353 + _t388) + _t349;
  const double d3F_dna2_dgab = _t161*_t311 + _t2*(_t391 + _t392 + _t409) + _t389;
  const double d3F_dna2_dgbb = _t165*_t311 + _t2*(_t411 + _t412 + _t419) + _t410;
  const double d3F_dna_dnb_dgaa = _t153 + _t169 + _t2*(_t137*_t152 + _t137*_t168 + _t352 + _t429*_t45) + _t349;
  const double d3F_dna_dnb_dgab = _t162 + _t171 + _t2*(_t137*_t161 + _t137*_t170 + _t391 + _t434*_t45) + _t389;
  const double d3F_dna_dnb_dgbb = _t166 + _t176 + _t2*(_t137*_t165 + _t137*_t175 + _t411 + _t438*_t45) + _t410;
  const double d3F_dnb2_dgaa = _t168*_t311 + _t2*(_t352 + _t439 + _t443) + _t349;
  const double d3F_dnb2_dgab = _t170*_t311 + _t2*(_t391 + _t444 + _t446) + _t389;
  const double d3F_dnb2_dgbb = _t175*_t311 + _t2*(_t411 + _t447 + _t454) + _t410;
  const double d3F_dna_dgaa2 = _t2*(_t456 + _t470) + _t455;
  const double d3F_dna_dgaa_dgab = _t2*(_t472 + _t477) + _t471;
  const double d3F_dna_dgaa_dgbb = _t2*(_t479 + _t481) + _t478;
  const double d3F_dna_dgab2 = _t2*(_t487 + _t492) + _t494;
  const double d3F_dna_dgab_dgbb = _t2*(_t477 + _t496) + _t497;
  const double d3F_dna_dgbb2 = _t2*(_t499 + _t502) + _t498;
  const double d3F_dnb_dgaa2 = _t2*(_t456 + _t507) + _t455;
  const double d3F_dnb_dgaa_dgab = _t2*(_t472 + _t510) + _t471;
  const double d3F_dnb_dgaa_dgbb = _t2*(_t479 + _t512) + _t478;
  const double d3F_dnb_dgab2 = _t2*(_t492 + _t514) + _t494;
  const double d3F_dnb_dgab_dgbb = _t2*(_t496 + _t510) + _t497;
  const double d3F_dnb_dgbb2 = _t2*(_t499 + _t517) + _t498;
  const double d3F_dgaa3 = _t529*_t63;
  const double d3F_dgaa2_dgab = _t532;
  const double d3F_dgaa2_dgbb = _t533;
  const double d3F_dgaa_dgab2 = _t534*_t63;
  const double d3F_dgaa_dgab_dgbb = _t532;
  const double d3F_dgaa_dgbb2 = _t533;
  const double d3F_dgab3 = -_t273*_t540 + _t536 + _t538*_t62;
  const double d3F_dgab2_dgbb = _t192*_t538 + _t542 - 0.1e1 / 0.96e2*_t543;
  const double d3F_dgab_dgbb2 = -0.1e1 / 0.192e3*_t543 + _t544 + _t545*_t546;
  const double d3F_dgbb3 = _t551*_t63;
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
  const double _t552 = 0.24e2*_t210;
  const double _t553 = 0.24e2*_t1*_t461;
  const double _t554 = -_t552 + _t553;
  const double _t555 = _t14*_t206;
  const double _t566 = 0.3e1*_t81;
  const double _t567 = 0.3e1*_t213;
  const double _t574 = (0.1e1 / 0.108e3)*_t136;
  const double _t575 = _t246*_t5;
  const double _t577 = _t257*_t5;
  const double _t603 = _t20*_t266;
  const double _t624 = (0.28e2 / 0.3e1)*_t103*_t20;
  const double _t630 = _t14*_t275;
  const double _t631 = xc_powr(_t2, -16, 3);
  const double _t632 = (0.140e3 / 0.81e2)*_t265;
  const double _t636 = (0.2e1 / 0.3e1)*_t14*_t18;
  const double _t638 = (0.1e1 / 0.36e2)*_t11*_t23;
  const double _t645 = 0.12e2*_t210;
  const double _t646 = _t553 - _t645;
  const double _t653 = 0.2e1*_t279;
  const double _t654 = (0.28e2 / 0.27e2)*_t103;
  const double _t684 = _t1*_t209;
  const double _t716 = _t110*_t14;
  const double _t718 = 0.18e2*_t211;
  const double _t720 = _t341*_t8;
  const double _t721 = _t345*_t8;
  const double _t733 = _t552 + _t553;
  const double _t734 = 0.3e1*_t336;
  const double _t735 = 0.3e1*_t126;
  const double _t738 = (0.1e1 / 0.216e3)*_t350;
  const double _t740 = (0.1e1 / 0.72e2)*_t136;
  const double _t741 = (0.5e1 / 0.1944e4)*_t545;
  const double _t744 = _t363*_t54;
  const double _t755 = (0.14e2 / 0.9e1)*_t379;
  const double _t756 = _t142*_t57;
  const double _t757 = _t382*_t756;
  const double _t763 = _t381*_t57;
  const double _t765 = _t104*_t57;
  const double _t770 = xc_powr(_t2, -17, 3);
  const double _t785 = (0.28e2 / 0.9e1)*_t379;
  const double _t786 = _t406*_t756;
  const double _t801 = _t66*_t9;
  const double _t803 = (0.1e1 / 0.324e3)*_t350;
  const double _t804 = _t54*_t6;
  const double _t805 = _t420*_t804;
  const double _t807 = _t1*_t265;
  const double _t808 = _t57*_t807;
  const double _t836 = 0.3e1*_t211;
  const double _t857 = _t142*_t463;
  const double _t858 = (0.1e1 / 0.3e1)*_t462;
  const double _t859 = _t464*_t465;
  const double _t870 = xc_powi(_t2, -6);
  const double _t872 = _t14*_t182;
  const double _t881 = (0.2e1 / 0.3e1)*_t462;
  const double _t882 = _t146*_t465;
  const double _t894 = (0.4e1 / 0.3e1)*_t462;
  const double _t895 = _t14*_t484;
  const double _t898 = (0.8e1 / 0.3e1)*_t39*_t57;
  const double _t901 = (0.1e1 / 0.648e3)*_t23;
  const double _t905 = (0.1e1 / 0.216e3)*_t23;
  const double _t907 = (0.1e1 / 0.1296e4)*_t23;
  const double _t911 = (0.1e1 / 0.3e1)*_t182*_t39;
  const double _t912 = _t147*_t185;
  const double _t916 = (0.1e1 / 0.2e1)*_t420;
  const double _t946 = _t518*_t519;
  const double _t947 = _t147*_t526;
  const double _t985 = _t547*_t548;
  const double _t992 = xc_powr(_t19, -7, 2);
  const double _t995 = (0.1e1 / (_t19 * _t19 * _t19));
  const double _t556 = _hc2[4]*_t555;
  const double _t557 = -_t556;
  const double _t558 = _hc2[8]*_t215;
  const double _t559 = -_hc2[13]*_t42;
  const double _t560 = _hc2[12]*_t34 + _t559;
  const double _t561 = -_hc2[12]*_t42;
  const double _t562 = _hc2[11]*_t34 + _t561;
  const double _t563 = _hc2[7]*_t81 + _t34*_t562 - _t42*_t560 + _t558;
  const double _t564 = _hc2[7]*_t215;
  const double _t565 = -_hc2[11]*_t42;
  const double _t568 = _t14*_t87;
  const double _t569 = _hc2[5]*_t555;
  const double _t570 = -_t569;
  const double _t571 = _hc2[9]*_t215;
  const double _t572 = -_hc2[14]*_t42;
  const double _t573 = _t107*_t350;
  const double _t576 = _hc3[8]*_t575;
  const double _t578 = _hc5[16]*_t228;
  const double _t579 = _hc3[18]*_t81;
  const double _t580 = _hc5[31]*_t88;
  const double _t581 = _hc3[33]*_t34;
  const double _t582 = -_t580 + _t581;
  const double _t583 = -_t34*_t580 + _t34*_t582 + _t578 + _t579;
  const double _t584 = _hc3[18]*_t228;
  const double _t585 = _hc3[33]*_t88;
  const double _t586 = _hc1[23]*_t91 + _hc1[28]*_t42;
  const double _t587 = _hc1[22]*_t91 + _hc1[27]*_t42;
  const double _t588 = _hc1[23]*_t34 - _t587;
  const double _t589 = _hc1[27]*_t91 + _hc1[31]*_t42;
  const double _t590 = _hc1[28]*_t34 - _t589;
  const double _t591 = _hc1[12]*_t242 + _hc1[16]*_t215;
  const double _t592 = _hc1[12]*_t81;
  const double _t593 = _hc1[21]*_t91 + _hc1[26]*_t42;
  const double _t594 = _hc1[22]*_t34 - _t593;
  const double _t595 = _hc1[26]*_t91 + _hc1[30]*_t42;
  const double _t596 = _hc1[27]*_t34 - _t595;
  const double _t597 = _hc1[11]*_t242 + _hc1[15]*_t215;
  const double _t598 = _t34*_t588 - _t42*_t596 + _t592 - _t594*_t91 + _t597;
  const double _t599 = _hc1[30]*_t91 + _hc1[33]*_t42;
  const double _t600 = _hc1[31]*_t34 - _t599;
  const double _t601 = _hc1[15]*_t242 + _hc1[18]*_t215;
  const double _t602 = _hc1[16]*_t81 + _t34*_t590 - _t42*_t600 - _t596*_t91 + _t601;
  const double _t604 = _hc1[5]*_t603;
  const double _t605 = _hc1[8]*_t555;
  const double _t606 = -_t604 - _t605;
  const double _t607 = _t258*_t265;
  const double _t608 = _hc3[8]*_t213;
  const double _t609 = _hc5[16]*_t81;
  const double _t610 = _hc1[5]*_t213;
  const double _t611 = _hc1[11]*_t81;
  const double _t612 = _hc1[20]*_t91 + _hc1[25]*_t42;
  const double _t613 = _hc1[25]*_t91 + _hc1[29]*_t42;
  const double _t614 = _hc1[26]*_t34 - _t613;
  const double _t615 = _hc1[10]*_t242 + _hc1[14]*_t215;
  const double _t616 = _hc1[15]*_t81;
  const double _t617 = _hc1[29]*_t91 + _hc1[32]*_t42;
  const double _t618 = _hc1[30]*_t34 - _t617;
  const double _t619 = _hc1[14]*_t242 + _hc1[17]*_t215;
  const double _t620 = _t34*_t596 - _t42*_t618 - _t614*_t91 + _t616 + _t619;
  const double _t621 = _hc1[4]*_t603;
  const double _t622 = _hc1[7]*_t555;
  const double _t623 = -_t621 - _t622;
  const double _t625 = _hc1[32]*_t91 + _hc1[34]*_t42;
  const double _t626 = _hc1[17]*_t242 + _hc1[19]*_t215;
  const double _t627 = _hc1[7]*_t603;
  const double _t628 = _hc1[9]*_t555;
  const double _t629 = -_t627 - _t628;
  const double _t633 = (0.3640e4 / 0.81e2)*_t102*_t631 + _t105*_t632;
  const double _t634 = _t147*_t70;
  const double _t635 = -0.5e1 / 0.729e3*_t142*_t24 + _t27*_t632;
  const double _t637 = _t107*_t136;
  const double _t639 = _t39*_t568;
  const double _t640 = -0.56e2 / 0.27e2*_t103*_t27 + (0.5e1 / 0.486e3)*_t207;
  const double _t641 = _t120*_t136;
  const double _t642 = (0.1e1 / 0.72e2)*_t641;
  const double _t643 = _t120*_t350;
  const double _t644 = -0.1e1 / 0.216e3*_t643;
  const double _t647 = _hc2[11]*_t47 + _t561;
  const double _t648 = _hc2[12]*_t47 + _t559;
  const double _t649 = -_t42*_t648 + _t558;
  const double _t650 = _hc2[7]*_t80 + _t34*_t647 + _t649;
  const double _t651 = _hc2[10]*_t47 + _t565;
  const double _t652 = -_t42*_t647 + _t564;
  const double _t655 = -_t42*(_hc2[13]*_t47 + _t572) + _t571;
  const double _t656 = _hc5[31]*_t47;
  const double _t657 = _t47*_t581;
  const double _t658 = _hc3[18]*_t80 - _t656*_t88 + _t657;
  const double _t659 = _hc0[34]*_t47 - _hc4[32]*_t114;
  const double _t660 = _hc1[24]*_t47 - _t586;
  const double _t661 = _hc1[23]*_t47 - _t587;
  const double _t662 = _hc1[28]*_t47 - _t589;
  const double _t663 = -_t42*_t662 + _t591 - _t661*_t91;
  const double _t664 = _hc1[22]*_t47 - _t593;
  const double _t665 = _hc1[27]*_t47 - _t595;
  const double _t666 = -_t42*_t665 + _t597 - _t664*_t91;
  const double _t667 = _hc1[12]*_t80 + _t34*_t661 + _t666;
  const double _t668 = _hc1[31]*_t47 - _t599;
  const double _t669 = -_t42*_t668 + _t601 - _t665*_t91;
  const double _t670 = _hc1[16]*_t80 + _t34*_t662 + _t669;
  const double _t671 = _hc3[8]*_t279;
  const double _t672 = _t47*_t579;
  const double _t673 = _t34*_t656;
  const double _t674 = _hc1[5]*_t279;
  const double _t675 = _hc1[26]*_t47 - _t613;
  const double _t676 = -_t42*_t675 + _t615 - _t91*(_hc1[21]*_t47 - _t612);
  const double _t677 = _hc1[30]*_t47 - _t617;
  const double _t678 = -_t42*_t677 + _t619 - _t675*_t91;
  const double _t679 = _hc1[15]*_t80 + _t34*_t665 + _t678;
  const double _t680 = -_t42*(_hc1[33]*_t47 - _t625) + _t626 - _t677*_t91;
  const double _t681 = _t204*_t306 + _t303*_t346 + _t633;
  const double _t682 = _t121*_t147;
  const double _t683 = _t204*_t289 + _t635;
  const double _t685 = _hc2[1]*_t553;
  const double _t686 = _hc2[7]*_t126 + _t47*_t647 + _t649;
  const double _t687 = _t42*_t686;
  const double _t688 = _hc2[6]*_t126 + _t47*_t651 + _t652;
  const double _t689 = _t42*(_hc2[8]*_t126 + _t47*_t648 + _t655);
  const double _t690 = _hc3[18]*_t126;
  const double _t691 = _hc3[33]*_t317;
  const double _t692 = _t690 + _t691;
  const double _t693 = _hc5[29]*_t114;
  const double _t694 = _hc4[32]*_t47 - _t693;
  const double _t695 = _hc0[19]*_t126 + _hc4[17]*_t320 - _t114*_t694 + _t47*_t659;
  const double _t696 = _hc1[16]*_t126 + _t47*_t662 + _t669;
  const double _t697 = _t42*_t696;
  const double _t698 = _hc1[12]*_t126;
  const double _t699 = _t47*_t661 + _t666 + _t698;
  const double _t700 = _t699*_t91;
  const double _t701 = _hc1[13]*_t126 + _t47*_t660 + _t663;
  const double _t702 = _t117*_t20*_t265;
  const double _t703 = _hc5[16]*_t126;
  const double _t704 = _hc5[31]*_t317;
  const double _t705 = _hc1[15]*_t126;
  const double _t706 = _t47*_t665 + _t678 + _t705;
  const double _t707 = _t42*_t706;
  const double _t708 = _hc1[11]*_t126;
  const double _t709 = _t91*(_t47*_t664 + _t676 + _t708);
  const double _t710 = _t118*_t14;
  const double _t711 = _t42*(_hc1[18]*_t126 + _t47*_t668 + _t680);
  const double _t712 = _t706*_t91;
  const double _t713 = _hc0[3]*_t553 + _hc1[2]*_t553;
  const double _t714 = _hc2[1]*_t645;
  const double _t715 = 0.8e1*_t112;
  const double _t717 = _hc2[3]*_t336 + _t204*_t282 + _t281*_t339 + _t47*_t688 + _t557 - _t687;
  const double _t719 = _t133*_t350;
  const double _t722 = _hc4[17]*_t126;
  const double _t723 = _hc5[14]*_t320 - _t47*_t693 + _t47*_t694 + _t722;
  const double _t724 = _hc0[9]*_t336 - _hc4[7]*_t720 - _t114*_t723 + _t291*_t339 + _t323*_t721 + _t47*_t695;
  const double _t725 = _hc1[6]*_t336 + _t204*_t295 + _t293*_t339 + _t294*_t346 + _t47*_t701 + _t606 - _t697 - _t700;
  const double _t726 = _hc3[8]*_t336;
  const double _t727 = _t47*_t690;
  const double _t728 = _hc1[5]*_t336;
  const double _t729 = _t325*_t630 + _t328*_t624 - _t381*_t710 - _t42*(_hc1[8]*_t336 + _t204*_t304 + _t295*_t339 + _t301*_t346 + _t47*_t696 + _t629 - _t711 - _t712) + _t633 - 0.280e3 / 0.9e1*_t702 - _t91*(_t204*_t301 + _t294*_t339 + _t300*_t346 + _t47*_t699 + _t623 - _t707 - _t709 + _t728);
  const double _t730 = -_t308*_t381 + _t332*_t630 - _t42*(_hc2[4]*_t336 + _t204*_t287 + _t282*_t339 + _t47*_t686 + _t570 - _t689) + _t635;
  const double _t731 = _t133*_t136;
  const double _t732 = (0.16e2 / 0.9e1)*_t308*_t39 - _t332*_t636 + _t640;
  const double _t736 = _hc4[7]*_t336;
  const double _t737 = _hc5[14]*_t126;
  const double _t739 = -_t61*_t738;
  const double _t742 = _t61*_t741;
  const double _t743 = _hc5[16]*_t359;
  const double _t745 = _hc3[8]*_t744;
  const double _t746 = _hc5[16]*_t355;
  const double _t747 = (0.1e1 / 0.2e1)*_hc5[31]*_t34*_t54*_t6 - _t746;
  const double _t748 = _hc3[18]*_t355;
  const double _t749 = _hc1[12]*_t372 + _hc1[22]*_t364 + _hc1[27]*_t368;
  const double _t750 = _hc1[11]*_t372 + _hc1[21]*_t364 + _hc1[26]*_t368;
  const double _t751 = (0.1e1 / 0.2e1)*_hc1[22]*_t18*_t34*_t57 - _t750;
  const double _t752 = _t58*_t592;
  const double _t753 = _hc1[15]*_t372 + _hc1[26]*_t364 + _hc1[30]*_t368;
  const double _t754 = (0.1e1 / 0.2e1)*_hc1[27]*_t18*_t34*_t57 - _t753;
  const double _t758 = _hc1[11]*_t755 + _hc1[15]*_t757 + _t366*_t381;
  const double _t759 = _hc1[10]*_t372 + _hc1[20]*_t364 + _hc1[25]*_t368;
  const double _t760 = _t58*_t611;
  const double _t761 = _hc1[14]*_t372 + _hc1[25]*_t364 + _hc1[29]*_t368;
  const double _t762 = (0.1e1 / 0.2e1)*_hc1[26]*_t18*_t34*_t57 - _t761;
  const double _t764 = _hc1[10]*_t755 + _hc1[14]*_t757 + _hc1[4]*_t763;
  const double _t766 = _t765*_t97;
  const double _t767 = _t58*_t616;
  const double _t768 = _hc1[17]*_t372 + _hc1[29]*_t364 + _hc1[32]*_t368;
  const double _t769 = _hc1[14]*_t755 + _hc1[17]*_t757 + _hc1[7]*_t763;
  const double _t771 = _hc1[4]*_t770;
  const double _t772 = (0.140e3 / 0.27e2)*_t771;
  const double _t773 = (0.140e3 / 0.27e2)*_t265*_t64;
  const double _t774 = _t14*_t379*_t383;
  const double _t775 = (0.7e1 / 0.27e2)*_t774;
  const double _t776 = -_t772 - _t773 - _t775;
  const double _t777 = _t204*_t378 + _t223*_t370 - _t255*_t372 + _t34*(-_t239*_t372 + _t34*((0.1e1 / 0.2e1)*_hc1[23]*_t18*_t34*_t57 - _t749) - _t42*_t754 - _t751*_t91 + (0.1e1 / 0.2e1)*_t752 + _t758) + _t346*_t374 - _t42*(-_t253*_t372 + _t34*_t754 - _t42*((0.1e1 / 0.2e1)*_hc1[30]*_t18*_t34*_t57 - _t768) - _t762*_t91 + (0.1e1 / 0.2e1)*_t767 + _t769) + (0.1e1 / 0.2e1)*_t58*_t610 + _t766 + _t776 - _t91*(-_t251*_t372 + _t34*_t751 - _t42*_t762 + (0.1e1 / 0.2e1)*_t760 + _t764 - _t91*((0.1e1 / 0.2e1)*_hc1[21]*_t18*_t34*_t57 - _t759));
  const double _t778 = -0.1e1 / 0.216e3*_t390;
  const double _t779 = (0.5e1 / 0.1944e4)*_t155*_t210;
  const double _t780 = _hc1[12]*_t400 + _hc1[22]*_t393 + _hc1[27]*_t396;
  const double _t781 = _hc1[11]*_t400 + _hc1[21]*_t393 + _hc1[26]*_t396;
  const double _t782 = _hc1[22]*_t18*_t34*_t57 - _t781;
  const double _t783 = _hc1[15]*_t400 + _hc1[26]*_t393 + _hc1[30]*_t396;
  const double _t784 = _hc1[27]*_t18*_t34*_t57 - _t783;
  const double _t787 = _hc1[11]*_t785 + _hc1[15]*_t786 + _t104*_t366;
  const double _t788 = _hc1[10]*_t400 + _hc1[20]*_t393 + _hc1[25]*_t396;
  const double _t789 = _hc1[14]*_t400 + _hc1[25]*_t393 + _hc1[29]*_t396;
  const double _t790 = _hc1[26]*_t18*_t34*_t57 - _t789;
  const double _t791 = _hc1[10]*_t785 + _hc1[14]*_t786 + _hc1[4]*_t765;
  const double _t792 = _hc1[17]*_t400 + _hc1[29]*_t393 + _hc1[32]*_t396;
  const double _t793 = _hc1[14]*_t785 + _hc1[17]*_t786 + _hc1[7]*_t765;
  const double _t794 = (0.280e3 / 0.27e2)*_t771;
  const double _t795 = _t266*_t64;
  const double _t796 = (0.14e2 / 0.27e2)*_t774;
  const double _t797 = _t794 + _t795 + _t796;
  const double _t798 = -_t69*_t738;
  const double _t799 = _t69*_t741;
  const double _t800 = _hc4[17]*_t34;
  const double _t802 = _t800*_t801;
  const double _t806 = (0.1e1 / 0.2e1)*_hc1[23]*_t18*_t47*_t57 - _t749;
  const double _t809 = _hc1[12]*_t808;
  const double _t810 = (0.1e1 / 0.2e1)*_hc1[22]*_t18*_t47*_t57 - _t750;
  const double _t811 = (0.1e1 / 0.2e1)*_hc1[27]*_t18*_t47*_t57 - _t753;
  const double _t812 = -_t294*_t372 - _t42*_t811 + _t758 - _t810*_t91;
  const double _t813 = _hc1[11]*_t808;
  const double _t814 = (0.1e1 / 0.2e1)*_hc1[26]*_t18*_t47*_t57 - _t761;
  const double _t815 = -_t300*_t372 - _t42*_t814 + _t764 - _t91*((0.1e1 / 0.2e1)*_hc1[21]*_t18*_t47*_t57 - _t759);
  const double _t816 = _t58*_t674;
  const double _t817 = _hc1[15]*_t808;
  const double _t818 = -_t301*_t372 - _t42*((0.1e1 / 0.2e1)*_hc1[30]*_t18*_t47*_t57 - _t768) + _t769 - _t814*_t91;
  const double _t819 = _t117*_t763 + _t215*_t378 + _t215*_t426 + _t242*_t374 + _t242*_t425 - _t303*_t372 + _t34*(_t34*_t806 + _t809 + _t812) + _t370*_t80 - _t42*(_t34*_t811 + _t817 + _t818) + _t422*_t81 + _t763*_t97 + _t776 + (0.1e1 / 0.2e1)*_t816 - _t91*(_t34*_t810 + _t813 + _t815);
  const double _t820 = _t277*_t429 + _t742;
  const double _t821 = _t311*_t429 + _t739;
  const double _t822 = _t117*_t765;
  const double _t823 = _hc1[27]*_t18*_t47*_t57 - _t783;
  const double _t824 = _hc1[26]*_t18*_t47*_t57 - _t789;
  const double _t825 = -_t301*_t400 - _t42*(_hc1[30]*_t18*_t47*_t57 - _t792) + _t793 - _t824*_t91;
  const double _t826 = _hc1[22]*_t18*_t47*_t57 - _t781;
  const double _t827 = -_t300*_t400 - _t42*_t824 + _t791 - _t91*(_hc1[21]*_t18*_t47*_t57 - _t788);
  const double _t828 = _hc1[23]*_t18*_t47*_t57 - _t780;
  const double _t829 = -_t294*_t400 - _t42*_t823 + _t787 - _t826*_t91;
  const double _t830 = _t277*_t434 + _t779;
  const double _t831 = _t311*_t434 + _t778;
  const double _t832 = -_hc4[17]*_t435 + (0.1e1 / 0.2e1)*_hc4[32]*_t47*_t66*_t9 - _hc5[29]*_t173;
  const double _t833 = _t277*_t438 + _t799;
  const double _t834 = _t311*_t438 + _t798;
  const double _t835 = _t360*_t690 + _t360*_t691;
  const double _t837 = _t58*_t698;
  const double _t838 = _t47*_t806 + _t812 + (0.1e1 / 0.2e1)*_t837;
  const double _t839 = _t328*_t372;
  const double _t840 = _t58*_t708;
  const double _t841 = _t91*(_t47*_t810 + _t815 + (0.1e1 / 0.2e1)*_t840);
  const double _t842 = _t1*_t366*_t631;
  const double _t843 = _t58*_t705;
  const double _t844 = _t42*(_t47*_t811 + _t818 + (0.1e1 / 0.2e1)*_t843);
  const double _t845 = -0.4e1*_t1*_t422*_t78 - 0.28e2 / 0.9e1*_t103*_t117*_t57 - 0.56e2 / 0.9e1*_t103*_t20*_t425 - 0.4e1 / 0.9e1*_t12*_t13*_t39*_t426 - _t34*_t838 + _t423 + _t772 + _t773 + _t775 + _t839 + _t841 + 0.3e1*_t842 + _t844;
  const double _t846 = _t47*_t828 + _t829 + _t837;
  const double _t847 = -0.56e2 / 0.9e1*_t103*_t117*_t57 - 0.56e2 / 0.9e1*_t103*_t20*_t431 - 0.4e1 / 0.9e1*_t12*_t13*_t39*_t432 + _t328*_t400 + _t42*(_t47*_t823 + _t825 + _t843) + _t797 + _t91*(_t47*_t826 + _t827 + _t840);
  const double _t848 = _hc5[14]*_t435;
  const double _t849 = (0.1e1 / 0.2e1)*_hc5[29]*_t47*_t66*_t9 - _t848;
  const double _t850 = _hc5[14]*_t449 - _t114*_t849 - _t323*_t435 + _t414*_t722 + _t416*_t452 + _t47*_t832;
  const double _t851 = _t204*_t426 + _t339*_t422 + _t346*_t425 + _t47*_t838 + (0.1e1 / 0.2e1)*_t58*_t728 + _t776 + _t822 - _t839 - _t841 - _t844;
  const double _t852 = _t187*_t277;
  const double _t853 = -_t187*_t351;
  const double _t854 = _hc5[16]*_t177;
  const double _t855 = _t457*_t854;
  const double _t856 = _hc1[12]*_t34;
  const double _t860 = _hc1[11]*_t857 - 0.1e1 / 0.24e2*_hc1[15]*_t12*_t13*_t147*_t182 + _hc1[21]*_t858 + _hc1[26]*_t859 - 0.1e1 / 0.3e1*_hc1[5]*_t182*_t39;
  const double _t861 = (0.1e1 / 0.4e1)*_hc1[22]*_t147*_t185*_t34 - _t184*_t856 - _t860;
  const double _t862 = _hc1[11]*_t34;
  const double _t863 = -0.1e1 / 0.24e2*_hc1[14]*_t12*_t13*_t147*_t182 + _hc1[20]*_t858 + _hc1[25]*_t859 - 0.1e1 / 0.3e1*_hc1[4]*_t182*_t39 + _t142*_t185*_t460;
  const double _t864 = _t91*((0.1e1 / 0.4e1)*_hc1[21]*_t147*_t185*_t34 - _t184*_t862 - _t863);
  const double _t865 = _t374*_t400;
  const double _t866 = _t184*_t249;
  const double _t867 = _hc1[15]*_t34;
  const double _t868 = _hc1[14]*_t857 - 0.1e1 / 0.24e2*_hc1[17]*_t12*_t13*_t147*_t182 + _hc1[25]*_t858 + _hc1[29]*_t859 - 0.1e1 / 0.3e1*_hc1[7]*_t182*_t39;
  const double _t869 = _t42*((0.1e1 / 0.4e1)*_hc1[26]*_t147*_t185*_t34 - _t184*_t867 - _t868);
  const double _t871 = (0.7e1 / 0.9e1)*_t103*_t190;
  const double _t873 = _hc1[7]*_t142;
  const double _t874 = (0.1e1 / 0.18e2)*_t872*_t873;
  const double _t875 = -0.7e1 / 0.9e1*_hc1[10]*_t57*_t870 - 0.1e1 / 0.18e2*_hc1[14]*_t12*_t13*_t185*_t461 - 0.7e1 / 0.9e1*_hc1[4]*_t185*_t379 + _t871 + _t874;
  const double _t876 = -0.1e1 / 0.4e1*_hc1[11]*_t147*_t185*_t81 - 0.1e1 / 0.3e1*_t182*_t39*_t97 - _t34*_t861 + _t864 + _t865 + _t866 + _t869 + _t875;
  const double _t877 = _t188*_t277;
  const double _t878 = _t311*_t476;
  const double _t879 = -_t188*_t351;
  const double _t880 = _t183*_t856;
  const double _t883 = -0.1e1 / 0.12e2*_hc1[15]*_t12*_t13*_t147*_t182 + _hc1[21]*_t881 + _hc1[26]*_t882 - 0.2e1 / 0.3e1*_hc1[5]*_t182*_t39 + _t185*_t365;
  const double _t884 = _t183*_t862;
  const double _t885 = -0.1e1 / 0.12e2*_hc1[14]*_t12*_t13*_t147*_t182 + _hc1[20]*_t881 + _hc1[25]*_t882 - 0.2e1 / 0.3e1*_hc1[4]*_t182*_t39 + _t185*_t371;
  const double _t886 = _t183*_t249;
  const double _t887 = _t183*_t867;
  const double _t888 = -0.1e1 / 0.12e2*_hc1[17]*_t12*_t13*_t147*_t182 + _hc1[25]*_t881 + _hc1[29]*_t882 - 0.2e1 / 0.3e1*_hc1[7]*_t182*_t39 + _t185*_t376;
  const double _t889 = _t182*_t873;
  const double _t890 = -0.14e2 / 0.9e1*_hc1[10]*_t57*_t870 - 0.1e1 / 0.9e1*_hc1[14]*_t12*_t13*_t185*_t461 - 0.14e2 / 0.9e1*_hc1[4]*_t185*_t379 + _t190*_t381 + _t382*_t889;
  const double _t891 = _t277*_t476 + _t45*((0.1e1 / 0.2e1)*_hc1[11]*_t147*_t185*_t81 + (0.2e1 / 0.3e1)*_t182*_t39*_t97 + _t34*((0.1e1 / 0.2e1)*_hc1[22]*_t147*_t185*_t34 - 0.1e1 / 0.2e1*_t880 - _t883) - _t372*_t402 - _t42*((0.1e1 / 0.2e1)*_hc1[26]*_t147*_t185*_t34 - 0.1e1 / 0.2e1*_t887 - _t888) - _t865 - 0.1e1 / 0.2e1*_t886 - _t890 - _t91*((0.1e1 / 0.2e1)*_hc1[21]*_t147*_t185*_t34 - 0.1e1 / 0.2e1*_t884 - _t885));
  const double _t892 = _t189*_t277;
  const double _t893 = -_t189*_t351;
  const double _t896 = -0.1e1 / 0.6e1*_hc1[15]*_t12*_t13*_t147*_t182 + _hc1[21]*_t894 + _hc1[26]*_t895 - 0.4e1 / 0.3e1*_hc1[5]*_t182*_t39 + _t185*_t394;
  const double _t897 = -0.1e1 / 0.6e1*_hc1[14]*_t12*_t13*_t147*_t182 + _hc1[20]*_t894 + _hc1[25]*_t895 - 0.4e1 / 0.3e1*_hc1[4]*_t182*_t39 + _t185*_t399;
  const double _t899 = -0.1e1 / 0.6e1*_hc1[17]*_t12*_t13*_t147*_t182 + _hc1[25]*_t894 + _hc1[29]*_t895 - 0.4e1 / 0.3e1*_hc1[7]*_t182*_t39 + _t185*_t403;
  const double _t900 = -0.28e2 / 0.9e1*_hc1[10]*_t57*_t870 - 0.2e1 / 0.9e1*_hc1[14]*_t12*_t13*_t185*_t461 - 0.28e2 / 0.9e1*_hc1[4]*_t185*_t379 + _t104*_t190 + _t406*_t889;
  const double _t902 = _t265*_t490;
  const double _t903 = _t190*_t78;
  const double _t904 = -_t901*_t902 + _t901*_t903;
  const double _t906 = -_t489*_t905 + _t491*_t905;
  const double _t908 = -_t902*_t907 + _t903*_t907;
  const double _t909 = _t199*_t277;
  const double _t910 = -_t199*_t351;
  const double _t913 = _hc5[14]*_t194;
  const double _t914 = (0.7e1 / 0.9e1)*_hc1[10]*_t57*_t870 + (0.7e1 / 0.9e1)*_t185*_t380 + (0.1e1 / 0.18e2)*_t185*_t461*_t482 - _t871 - _t874;
  const double _t915 = -_hc3[18]*_t503 + (0.1e1 / 0.4e1)*_hc5[31]*_t177*_t178*_t47;
  const double _t917 = _hc1[12]*_t47;
  const double _t918 = (0.1e1 / 0.4e1)*_hc1[22]*_t147*_t185*_t47 - _t184*_t917 - _t860;
  const double _t919 = _hc1[5]*_t182*_t807;
  const double _t920 = (0.1e1 / 0.2e1)*_t919;
  const double _t921 = _hc1[11]*_t47;
  const double _t922 = _t91*((0.1e1 / 0.4e1)*_hc1[21]*_t147*_t185*_t47 - _t184*_t921 - _t863);
  const double _t923 = _t400*_t425;
  const double _t924 = _hc1[15]*_t47;
  const double _t925 = _t42*((0.1e1 / 0.4e1)*_hc1[26]*_t147*_t185*_t47 - _t184*_t924 - _t868);
  const double _t926 = _t117*_t911 + _t914 - _t922 - _t923 - _t925;
  const double _t927 = (0.1e1 / 0.2e1)*_hc1[11]*_t1*_t185*_t770 + _t34*_t918 - _t920 + _t926;
  const double _t928 = _t183*_t917;
  const double _t929 = (0.1e1 / 0.2e1)*_hc1[22]*_t147*_t185*_t47 - _t883 - 0.1e1 / 0.2e1*_t928;
  const double _t930 = _t183*_t921;
  const double _t931 = _t183*_t924;
  const double _t932 = -0.2e1 / 0.3e1*_t117*_t182*_t39 + _t372*_t431 + _t42*((0.1e1 / 0.2e1)*_hc1[26]*_t147*_t185*_t47 - _t888 - 0.1e1 / 0.2e1*_t931) + _t890 + _t91*((0.1e1 / 0.2e1)*_hc1[21]*_t147*_t185*_t47 - _t885 - 0.1e1 / 0.2e1*_t930) + _t923;
  const double _t933 = _t137*_t476 + _t137*_t509 + _t45*(_hc1[11]*_t1*_t185*_t770 + _t34*_t929 - _t919 - _t932);
  const double _t934 = _t477 + _t510;
  const double _t935 = -0.1e1 / 0.3e1*_t117*_t182*_t39 + _t875 + _t922 + _t923 + _t925;
  const double _t936 = _hc1[22]*_t147*_t185*_t47 - _t896 - _t928;
  const double _t937 = -0.4e1 / 0.3e1*_t117*_t182*_t39 + _t42*(_hc1[26]*_t147*_t185*_t47 - _t899 - _t931) + _t431*_t898 + _t900 + _t91*(_hc1[21]*_t147*_t185*_t47 - _t897 - _t930);
  const double _t938 = (0.1e1 / 0.3e1)*_hc4[7]*_t196*_t50 + (0.1e1 / 0.4e1)*_hc5[29]*_t194*_t195*_t47 - _t322*_t500 - _t515*_t913;
  const double _t939 = _t184*_t327;
  const double _t940 = _t311*_t509;
  const double _t941 = _t183*_t327;
  const double _t942 = _t277*_t509 + _t45*((0.1e1 / 0.2e1)*_hc1[11]*_t126*_t147*_t185 + _t47*_t929 - _t932 - 0.1e1 / 0.2e1*_t941);
  const double _t943 = -0.1e1 / 0.4e1*_hc1[11]*_t126*_t147*_t185 - _t47*_t918 + _t935 + _t939;
  const double _t944 = _t45*_t529;
  const double _t945 = _t137*_t529;
  const double _t948 = _t862*_t947;
  const double _t949 = _t40*_t523;
  const double _t950 = _hc1[20]/xc_powr(_t2, 19, 3);
  const double _t951 = _t148*_t523;
  const double _t952 = _t14*_t951;
  const double _t953 = _hc1[25]*_t631;
  const double _t954 = -0.1e1 / 0.16e2*_hc1[14]*_t12*_t13*_t210*_t526 - 0.1e1 / 0.2e1*_hc1[4]*_t142*_t526 + _t483*_t950 + (0.1e1 / 0.48e2)*_t872*_t953 + (0.1e1 / 0.2e1)*_t949 + (0.1e1 / 0.16e2)*_t952;
  const double _t955 = -0.1e1 / 0.8e1*_hc1[21]*_t182*_t210*_t34 - 0.3e1 / 0.8e1*_hc1[5]*_t18*_t34*_t523 + (0.3e1 / 0.8e1)*_t948 + _t954;
  const double _t956 = _t45*_t531;
  const double _t957 = _t137*_t531;
  const double _t958 = _t182*_t953;
  const double _t959 = -0.1e1 / 0.8e1*_hc1[14]*_t12*_t13*_t210*_t526 - _hc1[4]*_t142*_t526 + _t463*_t950 + _t464*_t958 + _t949 + (0.1e1 / 0.8e1)*_t952;
  const double _t960 = _t45*((0.1e1 / 0.4e1)*_hc1[21]*_t182*_t210*_t34 + (0.3e1 / 0.4e1)*_hc1[5]*_t18*_t34*_t523 - 0.3e1 / 0.4e1*_t948 - _t959);
  const double _t961 = _t2*(_t957 + _t960) + _t956;
  const double _t962 = _t45*_t528;
  const double _t963 = _t137*_t528;
  const double _t964 = _t2*(-_t45*_t955 + _t963) + _t962;
  const double _t965 = _t45*_t534;
  const double _t966 = _t137*_t534;
  const double _t967 = _t185*_t950;
  const double _t968 = -0.1e1 / 0.4e1*_hc1[14]*_t12*_t13*_t210*_t526 - 0.2e1*_hc1[4]*_t142*_t526 + _t146*_t958 + 0.2e1*_t949 + (0.1e1 / 0.4e1)*_t952 + (0.2e1 / 0.3e1)*_t967;
  const double _t969 = _t45*((0.1e1 / 0.2e1)*_hc1[21]*_t182*_t210*_t34 + (0.3e1 / 0.2e1)*_hc1[5]*_t18*_t34*_t523 - 0.3e1 / 0.2e1*_t948 - _t968);
  const double _t970 = -0.1e1 / 0.2e1*_hc1[14]*_t12*_t13*_t210*_t526 - 0.4e1*_hc1[4]*_t142*_t526 + _t15*_t951 + _t159*_t958 + 0.4e1*_t949 + (0.4e1 / 0.3e1)*_t967;
  const double _t971 = _t103*_t539;
  const double _t972 = _t32*_t535;
  const double _t973 = _t379*_t537;
  const double _t974 = _t488*_t973 - _t62*_t971 + _t62*_t972;
  const double _t975 = _t39*_t539;
  const double _t976 = _t142*_t537;
  const double _t977 = -_t273*_t975 + _t3*_t536 + _t62*_t976;
  const double _t978 = -_t192*_t971 + _t192*_t972 + _t495*_t973;
  const double _t979 = _t23*_t975;
  const double _t980 = _t192*_t976 + _t3*_t542 - 0.1e1 / 0.96e2*_t979;
  const double _t981 = -0.1e1 / 0.576e3*_t23*_t971 + (0.1e1 / 0.1728e4)*_t23*_t973 + (0.1e1 / 0.576e3)*_t32*_t541;
  const double _t982 = _t142*_t23*_t546 + _t3*_t544 - 0.1e1 / 0.192e3*_t979;
  const double _t983 = _t45*_t551;
  const double _t984 = _t137*_t551;
  const double _t986 = _t921*_t947;
  const double _t987 = -0.1e1 / 0.8e1*_hc1[21]*_t182*_t210*_t47 - 0.3e1 / 0.8e1*_hc1[5]*_t18*_t47*_t523 + _t954 + (0.3e1 / 0.8e1)*_t986;
  const double _t988 = _t45*((0.1e1 / 0.4e1)*_hc1[21]*_t182*_t210*_t47 + (0.3e1 / 0.4e1)*_hc1[5]*_t18*_t47*_t523 - _t959 - 0.3e1 / 0.4e1*_t986);
  const double _t989 = _t2*(_t957 + _t988) + _t956;
  const double _t990 = _t2*(-_t45*_t987 + _t963) + _t962;
  const double _t991 = _t45*((0.1e1 / 0.2e1)*_hc1[21]*_t182*_t210*_t47 + (0.3e1 / 0.2e1)*_hc1[5]*_t18*_t47*_t523 - _t968 - 0.3e1 / 0.2e1*_t986);
  const double _t993 = _t522*_t992;
  const double _t994 = _hc1[10]*_t210;
  const double _t996 = -0.1e1 / 0.16e2*_hc1[20]*_t526*_t631 - 0.15e2 / 0.16e2*_hc1[4]*_t147*_t995 + _t524*_t994 + (0.15e2 / 0.16e2)*_t993;
  const double _t997 = _t523*_t994;
  const double _t998 = _t63*((0.1e1 / 0.8e1)*_hc1[20]*_t526*_t631 + (0.15e2 / 0.8e1)*_hc1[4]*_t147*_t995 - 0.15e2 / 0.8e1*_t993 - 0.3e1 / 0.4e1*_t997);
  const double _t999 = -_t63*_t996;
  const double _t1000 = _t63*((0.1e1 / 0.4e1)*_hc1[20]*_t526*_t631 + (0.15e2 / 0.4e1)*_hc1[4]*_t147*_t995 - 0.15e2 / 0.4e1*_t993 - 0.3e1 / 0.2e1*_t997);
  const double _t1001 = _hc1[1]*_t992;
  const double _t1002 = _hc1[10]*_t523;
  const double _t1003 = _t1002*_t545;
  const double _t1004 = _t1001*_t23;
  const double d4F_dna4 = _t2*(_hc2[1]*_t554 + _t221*_t566 + _t227*_t630 + _t270*_t574 + _t34*(_hc2[3]*_t213 + _t204*_t218 + _t220*_t223 + _t34*(_hc2[6]*_t81 + _t34*(_hc2[10]*_t34 + _t565) - _t42*_t562 + _t564) - _t42*_t563 + _t557) - _t381*_t568 - _t42*(_hc2[4]*_t213 + _t204*_t226 + _t218*_t223 + _t34*_t563 - _t42*(_hc2[8]*_t81 + _t34*_t560 - _t42*(_hc2[13]*_t34 + _t572) + _t571) + _t570) + _t45*(_hc0[3]*_t554 + _hc1[2]*_t554 + _t235*_t566 + _t244*_t566 - 0.280e3 / 0.9e1*_t245*_t256 + (0.28e2 / 0.3e1)*_t248*_t5*_t98 + _t255*_t624 + _t263*_t630 - _t264*_t381 + _t34*(_hc0[9]*_t213 + _t223*_t234 + _t232*_t577 + _t34*(_hc0[19]*_t81 + _t34*(_hc0[34]*_t34 - _t585) - _t582*_t88 + _t584) - _t576 - _t583*_t88) + _t34*(_hc1[6]*_t213 + _t204*_t241 + _t223*_t237 + _t239*_t346 + _t34*(_hc1[13]*_t81 + _t34*(_hc1[24]*_t34 - _t586) - _t42*_t590 - _t588*_t91 + _t591) - _t42*_t602 - _t598*_t91 + _t606) + (0.3640e4 / 0.81e2)*_t36/xc_powr(na, 16, 3) - _t42*(_hc1[8]*_t213 + _t204*_t261 + _t223*_t241 + _t253*_t346 + _t34*_t602 - _t42*(_hc1[18]*_t81 + _t34*_t600 - _t42*(_hc1[33]*_t34 - _t625) - _t618*_t91 + _t626) - _t620*_t91 + _t629) + _t567*_t90 + _t567*_t93 - 0.280e3 / 0.9e1*_t607 + _t633 - _t88*(-_hc5[6]*_t575 + _t223*_t232 + _t34*_t583 + _t361*_t577 + _t608 - _t88*(_hc5[31]*_t413 + _t609)) - _t91*(_t204*_t253 + _t223*_t239 + _t251*_t346 + _t34*_t598 - _t42*_t620 + _t610 + _t623 - _t91*(_t34*_t594 - _t42*_t614 + _t611 + _t615 - _t91*(_hc1[21]*_t34 - _t612)))) + _t567*_t84 - 0.1e1 / 0.108e3*_t573 + (0.5e1 / 0.486e3)*_t634 + _t635) - 0.1e1 / 0.54e2*_t200 + 0.4e1*_t214 + 0.4e1*_t222 - _t227*_t636 + _t270*_t638 + (0.1e1 / 0.36e2)*_t637 + (0.16e2 / 0.9e1)*_t639 + _t640 + 0.8e1*_t81*_t84;
  const double d4F_dna3_dnb = _t2*(_hc2[1]*_t646 + _t112*_t213 + _t137*_t270 + _t202*_t307 - _t206*_t308 + _t215*_t227 + _t221*_t80 + _t223*_t284 + _t34*(_hc2[3]*_t279 + _t215*_t218 + _t215*_t282 + _t220*_t80 + _t281*_t81 + _t34*(_hc2[6]*_t80 + _t34*_t651 + _t652) - _t42*_t650 + _t557) - _t42*(_hc2[4]*_t279 + _t215*_t226 + _t215*_t287 + _t218*_t80 + _t282*_t81 + _t34*_t650 - _t42*(_hc2[8]*_t80 + _t34*_t648 + _t655) + _t570) + _t45*(_hc0[3]*_t646 + _hc1[2]*_t646 + _t115*_t213 + _t116*_t213 - _t117*_t603 - _t118*_t555 + _t215*_t263 + _t223*_t292 + _t223*_t297 + _t235*_t80 + _t242*_t255 + _t244*_t80 - _t264*_t654 + _t299*_t577 + _t34*(_hc0[9]*_t279 + _t234*_t80 + _t291*_t81 + _t34*(_hc0[19]*_t80 + _t34*_t659 - _t47*_t585) + _t47*_t584 - _t658*_t88) + _t34*(_hc1[6]*_t279 + _t215*_t241 + _t215*_t295 + _t237*_t80 + _t239*_t242 + _t242*_t294 + _t293*_t81 + _t34*(_hc1[13]*_t80 + _t34*_t660 + _t663) - _t42*_t670 + _t606 - _t667*_t91) - _t42*(_hc1[8]*_t279 + _t215*_t261 + _t215*_t304 + _t241*_t80 + _t242*_t253 + _t242*_t301 + _t295*_t81 + _t34*_t670 - _t42*(_hc1[18]*_t80 + _t34*_t668 + _t680) + _t629 - _t679*_t91) - _t47*_t576 - 0.560e3 / 0.27e2*_t607 + _t653*_t90 + _t653*_t93 + _t681 - _t88*(_t232*_t80 + _t34*_t658 + _t47*_t578 + _t671 + _t672 - _t88*(_hc5[16]*_t80 + _t673)) - _t91*(_t215*_t253 + _t215*_t301 + _t239*_t80 + _t242*_t251 + _t242*_t300 + _t294*_t81 + _t34*_t667 - _t42*_t679 + _t623 + _t674 - _t91*(_hc1[11]*_t80 + _t34*_t664 + _t676))) - _t568*_t654 - 0.1e1 / 0.216e3*_t573 + (0.5e1 / 0.648e3)*_t634 + _t644 + _t653*_t84 + (0.5e1 / 0.1944e4)*_t682 + _t683) - 0.1e1 / 0.72e2*_t200 + _t271 - _t272*_t289 + _t274*_t307 + _t275*_t308 + 0.3e1*_t280 + 0.3e1*_t285 + 0.3e1*_t286 + _t335 + (0.1e1 / 0.72e2)*_t637 + (0.10e2 / 0.9e1)*_t639 + _t640 + _t642 + _t684*_t84;
  const double d4F_dna2_dnb2 = -_t1*_t714 + _t107*_t277 + _t133*_t277 + _t2*(-_t107*_t351 + _t112*_t653 - _t133*_t351 - _t212*_t84 + _t215*_t332 + _t277*_t307 + _t277*_t331 + _t284*_t315 - _t308*_t654 + _t313*_t81 + _t34*(-_hc2[3]*_t212 - _hc2[3]*_t79 + 0.4e1*_t1*_t281*_t78 + (0.4e1 / 0.9e1)*_t12*_t13*_t282*_t39 + _t34*_t688 - _t556 - _t687) - _t42*(-_hc2[4]*_t212 - _hc2[4]*_t79 + 0.4e1*_t1*_t282*_t78 + (0.4e1 / 0.9e1)*_t12*_t13*_t287*_t39 + _t34*_t686 - _t569 - _t689) + _t45*(_t115*_t653 + _t116*_t653 - _t206*_t264 - _t212*_t90 - _t212*_t93 + _t215*_t325 + _t228*_t319 + _t242*_t328 - _t258*_t266 + _t292*_t315 + _t297*_t315 + _t324*_t81 + _t330*_t81 + _t34*(-_hc0[9]*_t212 - _hc0[9]*_t79 + 0.4e1*_t1*_t291*_t78 + _t34*_t695 - _t692*_t88) + _t34*(-_hc1[6]*_t212 - _hc1[6]*_t79 + 0.4e1*_t1*_t293*_t78 + (0.56e2 / 0.9e1)*_t103*_t20*_t294 + (0.4e1 / 0.9e1)*_t12*_t13*_t295*_t39 + _t34*_t701 - _t604 - _t605 - _t697 - _t700) - _t42*(-_hc1[8]*_t212 - _hc1[8]*_t79 + 0.4e1*_t1*_t295*_t78 + (0.56e2 / 0.9e1)*_t103*_t20*_t301 + (0.4e1 / 0.9e1)*_t12*_t13*_t304*_t39 + _t34*_t696 - _t627 - _t628 - _t711 - _t712) - _t654*_t710 + _t681 - 0.560e3 / 0.27e2*_t702 + _t713 - _t79*_t90 - _t79*_t93 - _t88*(0.4e1*_hc3[18]*_t1*_t47*_t78 - _hc3[8]*_t212 - _hc3[8]*_t79 + _t34*_t692 - _t88*(_t703 + _t704)) - _t91*(-_hc1[5]*_t212 - _hc1[5]*_t79 + 0.4e1*_t1*_t294*_t78 + (0.56e2 / 0.9e1)*_t103*_t20*_t300 + (0.4e1 / 0.9e1)*_t12*_t13*_t301*_t39 + _t34*_t699 - _t621 - _t622 - _t707 - _t709)) - _t555*_t87 + (0.5e1 / 0.972e3)*_t634 - 0.1e1 / 0.162e3*_t643 + (0.5e1 / 0.972e3)*_t682 + _t683 + _t685 - _t79*_t84) - 0.1e1 / 0.108e3*_t200 + _t205 + 0.2e1*_t280 + 0.2e1*_t285 + 0.2e1*_t286 - _t289*_t716 - 0.1e1 / 0.108e3*_t290 + _t307*_t311 + _t308*_t395 - _t310 + _t311*_t331 + 0.2e1*_t314 + _t315*_t84 - _t332*_t716 + _t420*_t715 + _t640 + (0.1e1 / 0.54e2)*_t641;
  const double d4F_dna_dnb3 = -_hc2[1]*_t209 - _hc2[1]*_t718 + 0.12e2*_t112*_t420 + _t2*(-_t112*_t209 - _t112*_t718 + _t137*_t347 + _t202*_t331 + _t313*_t684 + _t34*_t717 + _t45*(_hc0[3]*_t645 + _hc1[2]*_t645 - _t115*_t209 - _t115*_t718 - _t116*_t209 - _t116*_t718 + _t324*_t684 + _t330*_t684 + _t34*_t724 + _t34*_t725 + _t713 + _t729 - _t88*(_t47*_t692 + _t726 + 0.2e1*_t727)) + (0.5e1 / 0.1944e4)*_t634 + _t644 + (0.5e1 / 0.648e3)*_t682 + _t685 + _t714 - 0.1e1 / 0.216e3*_t719 + _t730) + _t201 + _t274*_t331 - 0.1e1 / 0.72e2*_t290 + 0.3e1*_t314 + _t348 + _t642 + (0.1e1 / 0.72e2)*_t731 + _t732;
  const double d4F_dnb4 = _t126*_t715 + _t2*(_hc2[1]*_t733 + _t112*_t734 + _t313*_t735 + _t347*_t574 + _t45*(_hc0[3]*_t733 + _hc1[2]*_t733 - _t114*(-_hc5[4]*_t720 - _t114*(_hc5[29]*_t317 + _t737) + _t323*_t339 + _t450*_t721 + _t47*_t723 + _t736) + _t115*_t734 + _t116*_t734 + (0.28e2 / 0.3e1)*_t131*_t343*_t8 + _t324*_t735 + _t330*_t735 - 0.280e3 / 0.9e1*_t340*_t344 + _t47*_t724 + _t47*_t725 + (0.3640e4 / 0.81e2)*_t49/xc_powr(nb, 16, 3) + _t729) + _t47*_t717 + (0.5e1 / 0.486e3)*_t682 - 0.1e1 / 0.108e3*_t719 + _t730) - 0.1e1 / 0.54e2*_t290 + 0.4e1*_t337 + 0.4e1*_t338 + _t347*_t638 + (0.1e1 / 0.36e2)*_t731 + _t732;
  const double d4F_dna3_dgaa = _t152*_t740 + _t2*(-_t152*_t738 + _t202*_t387 + _t45*(-0.140e3 / 0.27e2*_hc5[6]/xc_powr(na, 17, 3) + _t223*_t357 - 0.140e3 / 0.27e2*_t245*_t55 - _t248*_t355 + _t34*(-_t232*_t355 + _t34*((0.1e1 / 0.2e1)*_hc3[33]*_t34*_t54*_t6 - _hc5[31]*_t140 - _t748) + _t360*_t579 + _t743 + _t745 - _t747*_t88) + _t360*_t608 + _t362*_t577 + _t54*_t95*_t99 + _t777 - _t88*(_hc5[6]*_t744 - _t34*_t746 + _t34*_t747 + _t360*_t609)) + _t742) + _t274*_t387 + _t739;
  const double d4F_dna3_dgab = _t161*_t740 + _t2*(-_t161*_t738 + _t202*_t408 + _t45*(_hc1[5]*_t18*_t213*_t57 + (0.56e2 / 0.9e1)*_t103*_t20*_t402 + (0.56e2 / 0.9e1)*_t103*_t57*_t97 + (0.4e1 / 0.9e1)*_t12*_t13*_t39*_t405 - _t255*_t400 + _t34*(-_t239*_t400 + _t34*(_hc1[23]*_t18*_t34*_t57 - _t780) - _t42*_t784 + _t752 - _t782*_t91 + _t787) + 0.2e1*_t398*_t81 - _t42*(-_t253*_t400 + _t34*_t784 - _t42*(_hc1[30]*_t18*_t34*_t57 - _t792) + _t767 - _t790*_t91 + _t793) - _t797 - _t91*(-_t251*_t400 + _t34*_t782 - _t42*_t790 + _t760 + _t791 - _t91*(_hc1[21]*_t18*_t34*_t57 - _t788))) + _t779) + _t274*_t408 + _t778;
  const double d4F_dna3_dgbb = _t165*_t740 + _t2*(-_t165*_t738 + _t202*_t418 + _t45*(_t213*_t417 + _t34*(_hc4[32]*_t413*_t414 + _t415*_t81) + _t777 + _t802*_t81) + _t799) + _t274*_t418 + _t798;
  const double d4F_dna2_dnb_dgaa = _t152*_t574 + _t2*(_t137*_t387 - _t152*_t803 - _t168*_t351 + _t45*(-_t299*_t355 + _t34*(_hc3[18]*_t805 - _t140*_t656 + _t360*_t657 - _t47*_t748) + _t357*_t80 + _t360*_t671 + _t360*_t672 + _t47*_t743 + _t47*_t745 + _t819 - _t88*(_hc5[16]*_t805 + _t360*_t673 - _t47*_t746)) + _t820) + _t388 + _t439 + _t821;
  const double d4F_dna2_dnb_dgab = _t161*_t574 + _t2*(_t137*_t408 - _t161*_t803 - _t170*_t351 + _t45*(_t215*_t405 + _t215*_t432 + _t242*_t402 + _t242*_t431 - _t303*_t400 + _t34*(_t34*_t828 + 0.2e1*_t809 + _t829) + _t398*_t80 - _t42*(_t34*_t823 + 0.2e1*_t817 + _t825) + _t430*_t81 + _t766 - _t794 - _t795 - _t796 + _t816 + _t822 - _t91*(_t34*_t826 + 0.2e1*_t813 + _t827)) + _t830) + _t409 + _t444 + _t831;
  const double d4F_dna2_dnb_dgbb = _t165*_t574 + _t2*(_t137*_t418 - _t165*_t803 - _t175*_t351 + _t45*(_t279*_t417 + _t34*(_hc4[17]*_t420*_t801 + _t34*_t832) + _t420*_t802 + _t436*_t81 + _t819) + _t833) + _t419 + _t447 + _t834;
  const double d4F_dna_dnb2_dgaa = _t168*_t574 + _t2*(_t137*_t442 - _t152*_t351 - _t168*_t803 + _t45*(0.2e1*_hc3[18]*_t1*_t47*_t54*_t6*_t78 - _t319*_t355 + _t34*_t835 - _t421*_t78 - _t421*_t836 - _t845 - _t88*(_t360*_t703 + _t360*_t704)) + _t820) + _t353 + _t443 + _t821;
  const double d4F_dna_dnb2_dgab = _t170*_t574 + _t2*(_t137*_t445 - _t161*_t351 - _t170*_t803 + _t45*(0.4e1*_t1*_t430*_t78 + _t34*_t846 - 0.2e1*_t423 - 0.6e1*_t842 - _t847) + _t830) + _t392 + _t446 + _t831;
  const double d4F_dna_dnb2_dgbb = _t175*_t574 + _t2*(_t137*_t453 - _t165*_t351 - _t175*_t803 + _t45*(0.4e1*_t1*_t436*_t78 + _t34*_t850 - _t437*_t78 - _t437*_t836 - _t845) + _t833) + _t412 + _t454 + _t834;
  const double d4F_dnb3_dgaa = _t168*_t740 + _t2*(-_t168*_t738 + _t202*_t442 + _t45*(_t360*_t726 + _t47*_t835 + _t727*_t804 + _t851) + _t742) + _t274*_t442 + _t739;
  const double d4F_dnb3_dgab = _t170*_t740 + _t2*(-_t170*_t738 + _t202*_t445 + _t45*(_hc1[5]*_t18*_t336*_t57 + 0.2e1*_t126*_t430 + _t47*_t846 - _t847) + _t779) + _t274*_t445 + _t778;
  const double d4F_dnb3_dgbb = _t175*_t740 + _t2*(-_t175*_t738 + _t202*_t453 + _t45*(-0.140e3 / 0.27e2*_hc5[4]/xc_powr(nb, 17, 3) - _t114*(_hc5[4]*_t452*_t66 + _t414*_t737 - _t47*_t848 + _t47*_t849) + _t130*_t132*_t66 + _t339*_t436 - 0.140e3 / 0.27e2*_t340*_t67 - _t343*_t435 + _t414*_t736 + _t451*_t721 + _t47*_t850 + _t851) + _t799) + _t274*_t453 + _t798;
  const double d4F_dna2_dgaa2 = _t2*(_t277*_t469 + _t45*((0.1e1 / 0.4e1)*_hc5[16]*_t177*_t178*_t81 + (0.7e1 / 0.9e1)*_hc5[6]*_t177*_t358 + (0.1e1 / 0.3e1)*_t179*_t37*_t95 - 0.7e1 / 0.9e1*_t180*_t98 - _t247*_t458 + _t34*((0.1e1 / 0.3e1)*_hc3[8]*_t179*_t37 + (0.1e1 / 0.4e1)*_hc5[31]*_t177*_t178*_t34 - _t231*_t458 - _t855) - _t362*_t38*_t54 - _t876 - _t88*((0.1e1 / 0.3e1)*_hc5[6]*_t179*_t37 - _t361*_t458)) + _t853) + _t311*_t469 + _t852;
  const double d4F_dna2_dgaa_dgab = _t2*(_t879 + _t891) + _t877 + _t878;
  const double d4F_dna2_dgaa_dgbb = _t2*(_t277*_t480 - _t45*_t876 + _t893) + _t311*_t480 + _t892;
  const double d4F_dna2_dgab2 = _t2*(_t277*_t486 + _t45*(_hc1[11]*_t147*_t185*_t81 + (0.4e1 / 0.3e1)*_t182*_t39*_t97 + _t34*(_hc1[22]*_t147*_t185*_t34 - _t880 - _t896) - _t402*_t898 - _t42*(_hc1[26]*_t147*_t185*_t34 - _t887 - _t899) - _t886 - _t900 - _t91*(_hc1[21]*_t147*_t185*_t34 - _t884 - _t897)) + _t904) + _t311*_t486 + _t906;
  const double d4F_dna2_dgab_dgbb = _t2*(_t891 + _t908) + _t492 + _t878;
  const double d4F_dna2_dgbb2 = _t2*(_t277*_t501 + _t45*(-_hc4[7]*_t500*_t81 + (0.1e1 / 0.4e1)*_t195*_t81*_t913 + _t34*_t861 + _t34*((0.1e1 / 0.4e1)*_hc5[29]*_t194*_t195*_t34 - _t500*_t800) + (0.1e1 / 0.4e1)*_t611*_t912 - _t864 - _t865 - _t866 - _t869 + _t911*_t97 + _t914) + _t910) + _t311*_t501 + _t909;
  const double d4F_dna_dnb_dgaa2 = _t2*(_t137*_t469 + _t137*_t506 + _t45*((0.1e1 / 0.3e1)*_hc3[8]*_t179*_t37*_t47 - _hc3[8]*_t179*_t420*_t56 + _t178*_t854*_t916 + _t34*_t915 - _t47*_t855 + _t927) + _t853) + _t470 + _t507 + _t852;
  const double d4F_dna_dnb_dgaa_dgab = _t2*(_t879 + _t933) + _t877 + _t934;
  const double d4F_dna_dnb_dgaa_dgbb = _t2*(_t137*_t480 + _t137*_t511 + _t45*((0.1e1 / 0.2e1)*_hc1[11]*_t1*_t185*_t770 + _t34*_t918 - _t920 - _t935) + _t893) + _t481 + _t512 + _t892;
  const double d4F_dna_dnb_dgab2 = _t2*(_t137*_t486 + _t137*_t513 + _t45*(0.2e1*_hc1[11]*_t1*_t185*_t770 + _t34*_t936 - 0.2e1*_t919 - _t937) + _t904) + _t487 + _t514 + _t906;
  const double d4F_dna_dnb_dgab_dgbb = _t2*(_t908 + _t933) + _t492 + _t934;
  const double d4F_dna_dnb_dgbb2 = _t2*(_t137*_t501 + _t137*_t516 + _t45*(-_hc4[7]*_t196*_t420*_t68 + _t195*_t913*_t916 + _t34*_t938 + _t927) + _t910) + _t502 + _t517 + _t909;
  const double d4F_dnb2_dgaa2 = _t2*(_t277*_t506 + _t45*((0.1e1 / 0.4e1)*_t177*_t178*_t703 - _t316*_t458 + _t47*_t915 + _t47*_t918 + (0.1e1 / 0.4e1)*_t708*_t912 + _t926 - _t939) + _t853) + _t311*_t506 + _t852;
  const double d4F_dnb2_dgaa_dgab = _t2*(_t879 + _t942) + _t877 + _t940;
  const double d4F_dnb2_dgaa_dgbb = _t2*(_t277*_t511 - _t45*_t943 + _t893) + _t311*_t511 + _t892;
  const double d4F_dnb2_dgab2 = _t2*(_t277*_t513 + _t45*(_hc1[11]*_t126*_t147*_t185 + _t47*_t936 - _t937 - _t941) + _t904) + _t311*_t513 + _t906;
  const double d4F_dnb2_dgab_dgbb = _t2*(_t908 + _t942) + _t492 + _t940;
  const double d4F_dnb2_dgbb2 = _t2*(_t277*_t516 + _t45*((0.1e1 / 0.4e1)*_hc5[14]*_t126*_t194*_t195 + (0.7e1 / 0.9e1)*_hc5[4]*_t194*_t448 - _t114*((0.1e1 / 0.3e1)*_hc5[4]*_t196*_t50 - _t450*_t500) + (0.1e1 / 0.3e1)*_t130*_t196*_t50 - 0.7e1 / 0.9e1*_t131*_t197 - _t342*_t500 - _t451*_t51*_t66 + _t47*_t938 - _t943) + _t910) + _t311*_t516 + _t909;
  const double d4F_dna_dgaa3 = _t2*(_t45*((0.3e1 / 0.8e1)*_hc3[8]*_t34*_t520*_t6 + (0.1e1 / 0.2e1)*_hc5[6]*_t139*_t518 - _t361*_t946 - 0.1e1 / 0.2e1*_t37*_t521 - _t955) + _t945) + _t944;
  const double d4F_dna_dgaa2_dgab = _t961;
  const double d4F_dna_dgaa2_dgbb = _t964;
  const double d4F_dna_dgaa_dgab2 = _t2*(_t966 + _t969) + _t965;
  const double d4F_dna_dgaa_dgab_dgbb = _t961;
  const double d4F_dna_dgaa_dgbb2 = _t964;
  const double d4F_dna_dgab3 = _t2*(_t45*(_hc1[21]*_t182*_t210*_t34 + 0.3e1*_hc1[5]*_t18*_t34*_t523 - 0.3e1*_t948 - _t970) + _t974) + _t977;
  const double d4F_dna_dgab2_dgbb = _t2*(_t969 + _t978) + _t980;
  const double d4F_dna_dgab_dgbb2 = _t2*(_t960 + _t981) + _t982;
  const double d4F_dna_dgbb3 = _t2*(_t45*((0.3e1 / 0.8e1)*_hc4[7]*_t34*_t549*_t9 - _hc5[14]*_t34*_t985 - _t955) + _t984) + _t983;
  const double d4F_dnb_dgaa3 = _t2*(_t45*((0.3e1 / 0.8e1)*_hc3[8]*_t47*_t520*_t6 - _hc5[16]*_t47*_t946 - _t987) + _t945) + _t944;
  const double d4F_dnb_dgaa2_dgab = _t989;
  const double d4F_dnb_dgaa2_dgbb = _t990;
  const double d4F_dnb_dgaa_dgab2 = _t2*(_t966 + _t991) + _t965;
  const double d4F_dnb_dgaa_dgab_dgbb = _t989;
  const double d4F_dnb_dgaa_dgbb2 = _t990;
  const double d4F_dnb_dgab3 = _t2*(_t45*(_hc1[21]*_t182*_t210*_t47 + 0.3e1*_hc1[5]*_t18*_t47*_t523 - _t970 - 0.3e1*_t986) + _t974) + _t977;
  const double d4F_dnb_dgab2_dgbb = _t2*(_t978 + _t991) + _t980;
  const double d4F_dnb_dgab_dgbb2 = _t2*(_t981 + _t988) + _t982;
  const double d4F_dnb_dgbb3 = _t2*(_t45*((0.3e1 / 0.8e1)*_hc4[7]*_t47*_t549*_t9 + (0.1e1 / 0.2e1)*_hc5[4]*_t172*_t547 - _t450*_t985 - 0.1e1 / 0.2e1*_t50*_t550 - _t987) + _t984) + _t983;
  const double d4F_dgaa4 = _t63*(-0.15e2 / 0.16e2*_hc3[2]*_t6/xc_powr(gaa, 7, 2) + (0.15e2 / 0.16e2)*_hc5[6]*_t178/(gaa * gaa * gaa) - _t996);
  const double d4F_dgaa3_dgab = _t998;
  const double d4F_dgaa3_dgbb = _t999;
  const double d4F_dgaa2_dgab2 = _t1000;
  const double d4F_dgaa2_dgab_dgbb = _t998;
  const double d4F_dgaa2_dgbb2 = _t999;
  const double d4F_dgaa_dgab3 = _t63*((0.1e1 / 0.2e1)*_hc1[20]*_t526*_t631 + (0.15e2 / 0.2e1)*_hc1[4]*_t147*_t995 - 0.15e2 / 0.2e1*_t993 - 0.3e1*_t997);
  const double d4F_dgaa_dgab2_dgbb = _t1000;
  const double d4F_dgaa_dgab_dgbb2 = _t998;
  const double d4F_dgaa_dgbb3 = _t999;
  const double d4F_dgab4 = (0.1e1 / 0.144e3)*_hc1[20]*_t21*_t210*_t22*_t526 + (0.5e1 / 0.48e2)*_hc1[4]*_t18*_t21*_t22*_t995 - 0.5e1 / 0.48e2*_t1001*_t23 - 0.1e1 / 0.24e2*_t1003;
  const double d4F_dgab3_dgbb = (0.1e1 / 0.288e3)*_hc1[20]*_t21*_t210*_t22*_t526 + (0.5e1 / 0.96e2)*_hc1[4]*_t18*_t21*_t22*_t995 - _t1002*_t147*_t273 - 0.5e1 / 0.96e2*_t1004;
  const double d4F_dgab2_dgbb2 = (0.1e1 / 0.576e3)*_hc1[20]*_t21*_t210*_t22*_t526 + (0.5e1 / 0.192e3)*_hc1[4]*_t18*_t21*_t22*_t995 - 0.1e1 / 0.96e2*_t1003 - 0.5e1 / 0.192e3*_t1004;
  const double d4F_dgab_dgbb3 = (0.1e1 / 0.1152e4)*_hc1[20]*_t21*_t210*_t22*_t526 + (0.5e1 / 0.384e3)*_hc1[4]*_t18*_t21*_t22*_t995 - 0.1e1 / 0.192e3*_t1003 - 0.5e1 / 0.384e3*_t1004;
  const double d4F_dgbb4 = _t63*(-0.15e2 / 0.16e2*_hc4[1]*_t9/xc_powr(gbb, 7, 2) + (0.15e2 / 0.16e2)*_hc5[4]*_t195/(gbb * gbb * gbb) - _t996);
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