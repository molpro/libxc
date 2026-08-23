/*
  Generated from python/gga_exc/gga_c_p86.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_p86
*/

#ifndef _GGA_C_P86_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_P86_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_P86_HELPER_BODIES
#include "gga_c_p86.c"
#undef _GGA_C_P86_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_P86_HELPER_BODIES
#include "gga_c_p86.c"
#undef _GGA_C_P86_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_P86_HELPER_BODIES
#include "gga_c_p86.c"
#undef _GGA_C_P86_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_P86_HELPER_BODIES
#include "gga_c_p86.c"
#undef _GGA_C_P86_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_C_P86_HELPER_BODIES
#include "gga_c_p86.c"
#undef _GGA_C_P86_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_c_p86.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_P86_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pz_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = rs >= 0.1e1;
  const double _t2 = xc_powr(rs, 1, 2);
  const double _t3 = 1.0528999999999999*_t2 + 0.33339999999999997*rs + 0.1e1;
  const double _t4 = log(rs);
  const double _t5 = 0.002*_t4;
  const double _t6 = my_piecewise3(_t1, -0.14230000000000001/_t3, 0.031099999999999999*_t4 + _t5*rs - 0.011599999999999999*rs - 0.048000000000000001);
  const double _t7 = 1.3980999999999999*_t2 + 0.2611*rs + 0.1e1;
  const double _t8 = 0.00069999999999999999*_t4;
  const double _t9 = -_t6 + my_piecewise3(_t1, -0.0843/_t7, 0.01555*_t4 + _t8*rs - 0.0047999999999999996*rs - 0.0269);
#if _KMAX >= 1
  const double _t10 = (0.1e1 / (_t3 * _t3));
  const double _t11 = (0.1e1 / _t2);
  const double _t12 = -0.52644999999999997*_t11 - 0.33339999999999997;
  const double _t13 = 0.14230000000000001*_t12;
  const double _t14 = (0.1e1 / rs);
  const double _t15 = my_piecewise3(_t1, -_t10*_t13, 0.031099999999999999*_t14 + _t5 - 0.0095999999999999992);
  const double _t16 = (0.1e1 / (_t7 * _t7));
  const double _t17 = -0.69904999999999995*_t11 - 0.2611;
  const double _t18 = 0.0843*_t17;
  const double _t19 = -_t15 + my_piecewise3(_t1, -_t16*_t18, 0.01555*_t14 + _t8 - 0.0040999999999999995);
#endif
#if _KMAX >= 2
  const double _t20 = xc_powr(rs, -3, 2);
  const double _t21 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t22 = -1.0528999999999999*_t11 - 0.66679999999999995;
  const double _t23 = _t21*_t22;
  const double _t24 = (0.1e1 / (rs * rs));
  const double _t25 = my_piecewise3(_t1, -0.037456917499999999*_t10*_t20 - _t13*_t23, 0.002*_t14 - 0.031099999999999999*_t24);
  const double _t26 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t27 = -1.3980999999999999*_t11 - 0.5222;
  const double _t28 = _t26*_t27;
  const double _t29 = -_t25 + my_piecewise3(_t1, -0.029464957499999996*_t16*_t20 - _t18*_t28, 0.00069999999999999999*_t14 - 0.01555*_t24);
#endif
#if _KMAX >= 3
  const double _t30 = xc_powr(rs, -5, 2);
  const double _t31 = 0.074913834999999998*_t20;
  const double _t32 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t33 = -1.5793499999999998*_t11 - 1.0002;
  const double _t34 = _t32*_t33;
  const double _t35 = _t22*_t34;
  const double _t36 = (0.1e1 / (rs * rs * rs));
  const double _t37 = my_piecewise3(_t1, 0.056185376250000002*_t10*_t30 - _t12*_t21*_t31 - _t13*_t35 - _t23*_t31, -0.002*_t24 + 0.062199999999999998*_t36);
  const double _t38 = 0.058929914999999992*_t20;
  const double _t39 = -2.0971500000000001*_t11 - 0.7833;
  const double _t40 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t41 = _t27*_t40;
  const double _t42 = _t39*_t41;
  const double _t43 = -_t37 + my_piecewise3(_t1, 0.044197436249999993*_t16*_t30 - _t17*_t26*_t38 - _t18*_t42 - _t28*_t38, -0.00069999999999999999*_t24 + 0.031099999999999999*_t36);
#endif
#if _KMAX >= 4
  const double _t44 = xc_powr(rs, -7, 2);
  const double _t45 = _t12*_t20;
  const double _t46 = (0.1e1 / (rs * rs * rs * rs));
  const double _t47 = my_piecewise3(_t1, -0.14046344062499999*_t10*_t44 + 0.1123707525*_t12*_t21*_t30 - _t13*_t22*_t33*(-2.1057999999999999*_t11 - 1.3335999999999999)/xc_powi(_t3, 5) - 0.1123707525*_t20*_t35 + 0.16855612875000001*_t21*_t22*_t30 - 0.059157582653624995*_t21*_t36 - 0.11237075249999999*_t22*_t32*_t45 - 0.14982767*_t34*_t45, 0.0040000000000000001*_t36 - 0.18659999999999999*_t46);
  const double _t48 = _t17*_t20;
#endif

  const double f = _hc0[0]*_t9 + _t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = _hc0[1]*_t9;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t19 + _t15;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = _hc0[2]*_t9;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t19;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[0]*_t29 + _t25;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = _hc0[3]*_t9;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc0[2]*_t19;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc0[1]*_t29;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = _hc0[0]*_t43 + _t37;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = _hc0[4]*_t9;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = _hc0[3]*_t19;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = _hc0[2]*_t29;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = _hc0[1]*_t43;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = _hc0[0]*(-_t47 + my_piecewise3(_t1, -0.11049359062499998*_t16*_t44 + 0.088394872499999985*_t17*_t26*_t30 - _t18*_t27*_t39*(-2.7961999999999998*_t11 - 1.0444)/xc_powi(_t7, 5) - 0.088394872499999985*_t20*_t42 + 0.13259230874999997*_t26*_t27*_t30 - 0.061792435621124991*_t26*_t36 - 0.11785982999999998*_t39*_t40*_t48 - 0.088394872499999999*_t41*_t48, 0.0014*_t36 - 0.093299999999999994*_t46)) + _t47;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(p86_DD_k, _KMAX)(const xc_func_type *p, double z, double *out) {

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(p86_CC_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const gga_c_p86_params *params = (const gga_c_p86_params *)(p->params);

  const double _t1 = (rs * rs);
  const double _t2 = _t1*params->mbeta;
  const double _t3 = _t2 + params->bb + params->malpha*rs;
  const double _t4 = _t1*params->mdelta + 10000.0*params->mbeta*(rs * rs * rs) + params->mgamma*rs + 0.1e1;
  const double _t5 = (0.1e1 / _t4);
#if _KMAX >= 1
  const double _t6 = 0.2e1*params->mbeta;
  const double _t7 = _t6*rs + params->malpha;
  const double _t8 = 0.2e1*params->mdelta;
  const double _t9 = -30000.0*_t2 - _t8*rs - params->mgamma;
  const double _t10 = (0.1e1 / (_t4 * _t4));
  const double _t11 = _t10*_t3;
#endif
#if _KMAX >= 2
  const double _t12 = params->mbeta*rs;
  const double _t13 = -60000.0*_t12 - _t8;
  const double _t14 = _t10*_t7;
  const double _t15 = 0.2e1*_t9;
  const double _t16 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t17 = _t16*_t3;
  const double _t18 = 0.4e1*params->mdelta;
  const double _t19 = -_t18*rs - 60000.0*_t2 - 0.2e1*params->mgamma;
  const double _t20 = _t19*_t9;
#endif
#if _KMAX >= 3
  const double _t21 = 0.3e1*_t13;
  const double _t22 = _t10*params->mbeta;
  const double _t23 = -120000.0*_t12 - _t18;
  const double _t24 = _t17*_t23;
  const double _t25 = _t13*_t19;
  const double _t26 = _t16*_t7;
  const double _t27 = 0.6e1*params->mdelta;
  const double _t28 = -90000.0*_t2 - _t27*rs - 0.3e1*params->mgamma;
  const double _t29 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t30 = _t20*_t29*_t3;
#endif
#if _KMAX >= 4
  const double _t31 = _t17*params->mbeta;
  const double _t32 = _t28*_t29;
  const double _t33 = _t3*_t32;
#endif

  const double f = _t3*_t5 + params->aa;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t11*_t9 + _t5*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t11*_t13 + _t14*_t15 + _t17*_t20 + _t5*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -60000.0*_t11*params->mbeta + _t14*_t21 + 0.2e1*_t17*_t25 + 0.3e1*_t20*_t26 + 0.6e1*_t22*_t9 + _t24*_t9 + _t28*_t30;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.12e2*_t13*_t22 - 240000.0*_t14*params->mbeta + _t15*_t23*_t33 + 0.12e2*_t16*_t20*params->mbeta + _t19*_t21*_t33 - 180000.0*_t19*_t31 + _t20*_t28*_t3*(-120000.0*_t2 - 0.8e1*params->mdelta*rs - 0.4e1*params->mgamma)/xc_powi(_t4, 5) + 0.4e1*_t20*_t32*_t7 + _t21*_t24 + 0.4e1*_t23*_t26*_t9 + 0.8e1*_t25*_t26 + _t30*(-180000.0*_t12 - _t27) - 120000.0*_t31*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(p86_x1_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {

  const double _t1 = xc_powr(0.2e1, 2, 3)*xc_powr(0.3e1, 1, 6)/xc_powr(M_PI, 1, 6);
  const double _t2 = (0.1e1 / 0.2e1)*_t1/xc_powr(rs, 1, 2);
#if _KMAX >= 1
  const double _t3 = (0.1e1 / 0.4e1)*_t1/xc_powr(rs, 3, 2);
#endif
#if _KMAX >= 2
  const double _t4 = (0.3e1 / 0.8e1)*_t1/xc_powr(rs, 5, 2);
#endif
#if _KMAX >= 3
  const double _t5 = (0.15e2 / 0.16e2)*_t1/xc_powr(rs, 7, 2);
#endif

  const double f = _t2*xt;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t2;
  out[1] = df_dxt;
  const double df_drs = -_t3*xt;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = 0;
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = -_t3;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = _t4*xt;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0;
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = 0;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = _t4;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = -_t5*xt;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = 0;
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = 0;
  out[11] = d4f_drs_dxt3;
  const double d4f_drs2_dxt2 = 0;
  out[12] = d4f_drs2_dxt2;
  const double d4f_drs3_dxt = -_t5;
  out[13] = d4f_drs3_dxt;
  const double d4f_drs4 = (0.105e3 / 0.32e2)*_t1*xt/xc_powr(rs, 9, 2);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(p86_mPhi_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {
  const gga_c_p86_params *params = (const gga_c_p86_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(p86_CC_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(p86_x1_k, _KMAX)(p, rs, xt, _hc1);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = params->aa + params->bb;
  const double _t3 = _t2*params->ftilde;
  const double _t4 = _t1*_t3;
#if _KMAX >= 1
  const double _t5 = _t3/((_hc0[0]) * (_hc0[0]));
  const double _t6 = _hc0[1]*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = 0.2e1*_t6;
  const double _t8 = _hc0[2]*_t5;
  const double _t9 = _hc1[0]*_t3;
  const double _t10 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t11 = ((_hc0[1]) * (_hc0[1]));
  const double _t12 = _t10*_t11;
  const double _t13 = 0.2e1*_t12;
#endif
#if _KMAX >= 3
  const double _t14 = _hc1[1]*_t3;
  const double _t15 = _hc0[3]*_t5;
  const double _t16 = 0.3e1*_t6;
  const double _t17 = 0.3e1*_t8;
  const double _t18 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t19 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t18;
  const double _t20 = 0.6e1*_t9;
#endif
#if _KMAX >= 4
  const double _t21 = 0.24e2*_hc1[2]*_t3;
#endif

  const double f = _hc1[0]*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _hc1[1]*_t4;
  out[1] = df_dxt;
  const double df_drs = -_hc1[0]*_t6 + _hc1[2]*_t4;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = 0;
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = -_hc1[1]*_t6 + _hc1[4]*_t4;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = -_hc1[0]*_t8 - _hc1[2]*_t7 + _hc1[5]*_t4 + _t13*_t9;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0;
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = 0;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = -_hc1[1]*_t8 - _hc1[4]*_t7 + _hc1[8]*_t4 + _t13*_t14;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = 0.6e1*_hc0[1]*_hc0[2]*_hc1[0]*_t10*_t2*params->ftilde - _hc1[0]*_t15 + 0.6e1*_hc1[2]*_t10*_t11*_t2*params->ftilde - _hc1[2]*_t17 - _hc1[5]*_t16 + _hc1[9]*_t1*_t2*params->ftilde - _t19*_t20;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = 0;
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = 0;
  out[11] = d4f_drs_dxt3;
  const double d4f_drs2_dxt2 = 0;
  out[12] = d4f_drs2_dxt2;
  const double d4f_drs3_dxt = 0.6e1*_hc0[1]*_hc0[2]*_hc1[1]*_t10*_t2*params->ftilde - _hc1[1]*_t15 + _hc1[13]*_t1*_t2*params->ftilde + 0.6e1*_hc1[4]*_t10*_t11*_t2*params->ftilde - _hc1[4]*_t17 - _hc1[8]*_t16 - 0.6e1*_t14*_t19;
  out[13] = d4f_drs3_dxt;
  const double d4f_drs4 = _hc0[1]*_hc0[2]*_t10*_t21 + 0.8e1*_hc0[1]*_hc0[3]*_t10*_t9 + ((_hc0[2]) * (_hc0[2]))*_t10*_t20 - 0.36e2*_hc0[2]*_t11*_t18*_t9 - _hc0[4]*_hc1[0]*_t5 + _hc1[14]*_t4 - 0.4e1*_hc1[2]*_t15 + 0.12e2*_hc1[5]*_t12*_t3 - 0.6e1*_hc1[5]*_t8 - 0.4e1*_hc1[9]*_t6 - _t19*_t21 + 0.24e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t9/xc_powi((_hc0[0]), 5);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(p86_H_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(p86_DD_k, _KMAX)(p, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(p86_x1_k, _KMAX)(p, rs, xt, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(p86_mPhi_k, _KMAX)(p, rs, xt, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(p86_CC_k, _KMAX)(p, rs, _hc3);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = ((_hc1[0]) * (_hc1[0]));
  const double _t3 = exp(-_hc2[0]);
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
  const double _t6 = _hc3[0]*_t5;
#if _KMAX >= 1
  const double _t7 = _hc2[1]*_t6;
  const double _t8 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t9 = _t4*_t8;
  const double _t10 = _hc0[1]*_hc3[0];
  const double _t11 = _t10*_t9;
  const double _t12 = _hc3[1]*_t5;
  const double _t13 = 0.2e1*_hc3[0];
  const double _t14 = _t1*_t3;
  const double _t15 = _hc1[0]*_t14;
  const double _t16 = _t13*_t15;
  const double _t17 = _hc1[2]*_t16;
  const double _t18 = _hc2[2]*_t6;
#endif
#if _KMAX >= 2
  const double _t19 = ((_hc1[1]) * (_hc1[1]));
  const double _t20 = _t14*_t19;
  const double _t21 = _t13*_t20;
  const double _t22 = _hc3[0]*_t14;
  const double _t23 = 0.4e1*_t22;
  const double _t24 = _hc1[1]*_t23;
  const double _t25 = _hc1[0]*_t24;
  const double _t26 = _hc2[1]*_t25;
  const double _t27 = _hc2[3]*_t6;
  const double _t28 = ((_hc2[1]) * (_hc2[1]));
  const double _t29 = _t28*_t6;
  const double _t30 = 0.2e1*_hc1[1];
  const double _t31 = _hc1[0]*_t3;
  const double _t32 = _t31*_t8;
  const double _t33 = _t30*_t32;
  const double _t34 = _t10*_t33;
  const double _t35 = _hc2[1]*_t11;
  const double _t36 = _hc3[0]*_t9;
  const double _t37 = _hc0[2]*_t36;
  const double _t38 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t39 = ((_hc0[1]) * (_hc0[1]));
  const double _t40 = _hc3[1]*_t15;
  const double _t41 = _hc1[1]*_t13;
  const double _t42 = _t15*_t41;
  const double _t43 = _hc2[1]*_t12;
  const double _t44 = _hc2[4]*_t6;
  const double _t45 = _hc2[2]*_t7;
  const double _t46 = _hc3[1]*_t9;
  const double _t47 = _hc0[1]*_t46;
  const double _t48 = 0.2e1*_t10;
  const double _t49 = _t32*_t48;
  const double _t50 = _hc1[2]*_t49;
  const double _t51 = _hc3[2]*_t5;
  const double _t52 = 0.4e1*_t40;
  const double _t53 = _hc1[2]*_t52;
  const double _t54 = _hc1[5]*_t16;
  const double _t55 = ((_hc1[2]) * (_hc1[2]));
  const double _t56 = _t14*_t55;
  const double _t57 = _t13*_t56;
  const double _t58 = _hc1[0]*_hc2[2];
  const double _t59 = _hc1[2]*_t23;
  const double _t60 = _t58*_t59;
  const double _t61 = 0.2e1*_t12;
  const double _t62 = ((_hc2[2]) * (_hc2[2]));
  const double _t63 = _t6*_t62;
#endif
#if _KMAX >= 3
  const double _t64 = _hc1[0]*_hc1[1];
  const double _t65 = 0.6e1*_t22;
  const double _t66 = _hc2[3]*_t65;
  const double _t67 = 0.6e1*_hc3[0];
  const double _t68 = _hc2[1]*_t20;
  const double _t69 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t70 = _t19*_t3*_t8;
  const double _t71 = _t48*_t70;
  const double _t72 = _t32*_t41;
  const double _t73 = _hc2[1]*_t37;
  const double _t74 = _t38*_t39;
  const double _t75 = _hc3[0]*_t74;
  const double _t76 = 0.4e1*_t31*_t75;
  const double _t77 = _hc1[1]*_t76;
  const double _t78 = _t4*_t74;
  const double _t79 = _t13*_t78;
  const double _t80 = _hc0[3]*_t36;
  const double _t81 = _t4*_t67;
  const double _t82 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t83 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t84 = _t82*_t83;
  const double _t85 = _t81*_t84;
  const double _t86 = _hc1[1]*_t52;
  const double _t87 = _hc1[4]*_t23;
  const double _t88 = _hc1[0]*_hc2[1];
  const double _t89 = _hc1[1]*_hc1[2];
  const double _t90 = _t23*_t89;
  const double _t91 = _hc3[1]*_t33;
  const double _t92 = _t3*_t8;
  const double _t93 = _hc1[2]*_t10;
  const double _t94 = _t92*_t93;
  const double _t95 = _hc0[2]*_t13;
  const double _t96 = _hc1[2]*_t32;
  const double _t97 = _hc1[2]*_t76;
  const double _t98 = 0.2e1*_hc3[1];
  const double _t99 = _t78*_t98;
  const double _t100 = _hc1[0]*_hc2[4];
  const double _t101 = _hc3[2]*_t9;
  const double _t102 = _hc0[1]*_t101;
  const double _t103 = 0.4e1*_hc3[1];
  const double _t104 = _hc0[1]*_t103;
  const double _t105 = _t104*_t96;
  const double _t106 = _hc1[5]*_t49;
  const double _t107 = _t3*_t55*_t8;
  const double _t108 = _t107*_t48;
  const double _t109 = _hc3[3]*_t5;
  const double _t110 = _hc3[2]*_t15;
  const double _t111 = 0.6e1*_t110;
  const double _t112 = _hc1[2]*_t111;
  const double _t113 = 0.6e1*_t40;
  const double _t114 = _hc1[5]*_t113;
  const double _t115 = _hc1[9]*_t16;
  const double _t116 = _hc1[2]*_t65;
  const double _t117 = _hc1[5]*_t116;
  const double _t118 = 0.6e1*_t56;
  const double _t119 = _hc3[1]*_t118;
  const double _t120 = 0.12e2*_hc1[2];
  const double _t121 = _t120*_t40;
  const double _t122 = _hc1[0]*_t116;
  const double _t123 = _hc1[5]*_t65;
  const double _t124 = 0.3e1*_t51;
  const double _t125 = 0.3e1*_t12;
  const double _t126 = _hc3[0]*_t118;
  const double _t127 = 0.3e1*_hc2[5];
  const double _t128 = ((_hc2[2]) * (_hc2[2]) * (_hc2[2]));
#endif
#if _KMAX >= 4
  const double _t129 = 0.8e1*_t22;
  const double _t130 = _t129*_t64;
  const double _t131 = 0.12e2*_hc3[0];
  const double _t132 = _t131*_t20;
  const double _t133 = _hc2[1]*_t22;
  const double _t134 = 0.3e1*_t6;
  const double _t135 = 0.6e1*_t10;
  const double _t136 = _hc1[1]*_t135*_t32;
  const double _t137 = 0.3e1*_hc2[3];
  const double _t138 = _hc1[1]*_t31;
  const double _t139 = 0.8e1*_hc2[1];
  const double _t140 = _hc0[2]*_t38;
  const double _t141 = _t131*_t84;
  const double _t142 = _t135*_t140*_t4;
  const double _t143 = _hc3[0]*_t4;
  const double _t144 = _hc1[1]*_t113;
  const double _t145 = _hc1[0]*_hc1[4];
  const double _t146 = _hc1[1]*_hc1[4];
  const double _t147 = 0.6e1*_hc3[1];
  const double _t148 = _t10*_t92;
  const double _t149 = 0.4e1*_t148;
  const double _t150 = _hc1[1]*_hc2[1];
  const double _t151 = _t150*_t32;
  const double _t152 = _hc1[1]*_hc2[4];
  const double _t153 = 0.4e1*_t10;
  const double _t154 = _hc1[4]*_t32;
  const double _t155 = 0.4e1*_hc2[2];
  const double _t156 = _t10*_t155;
  const double _t157 = 0.2e1*_hc2[4];
  const double _t158 = _hc2[2]*_t11;
  const double _t159 = 0.8e1*_t40;
  const double _t160 = 0.8e1*_hc1[4];
  const double _t161 = _t160*_t22;
  const double _t162 = _t14*_t89;
  const double _t163 = _hc1[1]*_hc2[2];
  const double _t164 = _hc2[2]*_t103;
  const double _t165 = 0.4e1*_hc2[4];
  const double _t166 = 0.2e1*_hc2[2];
  const double _t167 = _hc0[1]*_t32;
  const double _t168 = _t32*_t93;
  const double _t169 = 0.8e1*_hc1[2];
  const double _t170 = _hc2[2]*_t40;
  const double _t171 = _hc2[5]*_t65;
  const double _t172 = _hc2[2]*_hc3[1];
  const double _t173 = _hc2[2]*_t22;
  const double _t174 = 0.3e1*_t62;
  const double _t175 = _hc1[2]*_hc1[5];
  const double _t176 = 0.12e2*_hc1[5];
  const double _t177 = 0.24e2*_t175;
  const double _t178 = _t169*_t22;
  const double _t179 = 0.12e2*_t56;
  const double _t180 = 0.24e2*_hc1[2];
  const double _t181 = _t180*_t40;
  const double _t182 = _hc1[0]*_t178;
  const double _t183 = _hc2[5]*_t22;
  const double _t184 = _hc1[0]*_t176;
  const double _t185 = 0.6e1*_t51;
  const double _t186 = 0.4e1*_t12;
  const double _t187 = _hc3[0]*_t179;
#endif

  const double f = _t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = 0.2e1*_hc1[0]*_hc1[1]*_hc3[0]*_t1*_t3 - _t7;
  out[1] = df_dxt;
  const double df_dz = -_t11;
  out[2] = df_dz;
  const double df_drs = _t12 + _t17 - _t18;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = _t21 - _t26 - _t27 + _t29;
  out[4] = d2f_dxt2;
  const double d2f_dz_dxt = -_t34 + _t35;
  out[5] = d2f_dz_dxt;
  const double d2f_dz2 = 0.2e1*_hc3[0]*_t2*_t3*_t38*_t39 - _t37;
  out[6] = d2f_dz2;
  const double d2f_drs_dxt = _hc1[2]*_t14*_t41 + _hc1[4]*_t16 - _hc2[1]*_t17 - _hc2[2]*_t42 + _t30*_t40 - _t43 - _t44 + _t45;
  out[7] = d2f_drs_dxt;
  const double d2f_drs_dz = _hc0[1]*_hc2[2]*_hc3[0]*_t2*_t3*_t8 - _t47 - _t50;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = -_hc2[2]*_t61 - _hc2[5]*_t6 + _t51 + _t53 + _t54 + _t57 - _t60 + _t63;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0.6e1*_hc1[0]*_hc1[1]*_hc3[0]*_t1*_t28*_t3 + 0.3e1*_hc2[1]*_hc2[3]*_hc3[0]*_t1*_t2*_t3 - _hc2[6]*_t6 - _t6*_t69 - _t64*_t66 - _t67*_t68;
  out[10] = d3f_dxt3;
  const double d3f_dz_dxt2 = 0.4e1*_hc0[1]*_hc1[0]*_hc1[1]*_hc2[1]*_hc3[0]*_t3*_t8 + _hc0[1]*_hc2[3]*_hc3[0]*_t2*_t3*_t8 - _t11*_t28 - _t71;
  out[11] = d3f_dz_dxt2;
  const double d3f_dz2_dxt = -_hc0[2]*_t72 - _hc2[1]*_t79 + _t73 + _t77;
  out[12] = d3f_dz2_dxt;
  const double d3f_dz3 = 0.6e1*_hc0[1]*_hc0[2]*_hc3[0]*_t2*_t3*_t38 - _t80 - _t85;
  out[13] = d3f_dz3;
  const double d3f_drs_dxt2 = 0.4e1*_hc1[0]*_hc1[1]*_hc2[1]*_hc2[2]*_hc3[0]*_t1*_t3 + 0.2e1*_hc1[0]*_hc1[2]*_hc3[0]*_t1*_t28*_t3 + 0.4e1*_hc1[1]*_hc1[4]*_hc3[0]*_t1*_t3 + 0.2e1*_hc2[1]*_hc2[4]*_hc3[0]*_t1*_t2*_t3 - _hc2[1]*_t86 - _hc2[1]*_t90 + _hc2[2]*_hc2[3]*_hc3[0]*_t1*_t2*_t3 - _hc2[2]*_t21 - _hc2[3]*_t12 - _hc2[3]*_t17 - _hc2[4]*_t25 - _hc2[7]*_t6 + 0.2e1*_hc3[1]*_t1*_t19*_t3 + _hc3[1]*_t1*_t2*_t28*_t3 - _t18*_t28 - _t87*_t88;
  out[14] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxt = 0.2e1*_hc0[1]*_hc1[0]*_hc1[1]*_hc2[2]*_hc3[0]*_t3*_t8 + 0.2e1*_hc0[1]*_hc1[0]*_hc1[2]*_hc2[1]*_hc3[0]*_t3*_t8 + _hc0[1]*_hc2[1]*_hc3[1]*_t2*_t3*_t8 + _hc0[1]*_hc2[4]*_hc3[0]*_t2*_t3*_t8 - _hc0[1]*_t91 - _hc1[4]*_t49 - _hc2[2]*_t35 - _t30*_t94;
  out[15] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = -_hc0[2]*_t46 + _hc2[2]*_t37 - _hc2[2]*_t79 - _t95*_t96 + _t97 + _t99;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dxt = 0.2e1*_hc1[0]*_hc1[1]*_hc3[0]*_t1*_t3*_t62 + 0.2e1*_hc1[0]*_hc1[1]*_hc3[2]*_t1*_t3 + 0.4e1*_hc1[0]*_hc1[2]*_hc2[1]*_hc2[2]*_hc3[0]*_t1*_t3 + 0.4e1*_hc1[0]*_hc1[4]*_hc3[1]*_t1*_t3 + 0.2e1*_hc1[0]*_hc1[8]*_hc3[0]*_t1*_t3 + 0.4e1*_hc1[1]*_hc1[2]*_hc3[1]*_t1*_t3 + 0.2e1*_hc1[1]*_hc1[5]*_hc3[0]*_t1*_t3 + 0.4e1*_hc1[2]*_hc1[4]*_hc3[0]*_t1*_t3 + 0.2e1*_hc2[1]*_hc2[2]*_hc3[1]*_t1*_t2*_t3 + _hc2[1]*_hc2[5]*_hc3[0]*_t1*_t2*_t3 - _hc2[1]*_t51 - _hc2[1]*_t53 - _hc2[1]*_t54 - _hc2[1]*_t57 + 0.2e1*_hc2[2]*_hc2[4]*_hc3[0]*_t1*_t2*_t3 - _hc2[2]*_t86 - _hc2[2]*_t90 - _hc2[4]*_t61 - _hc2[5]*_t42 - _hc2[8]*_t6 - _t100*_t59 - _t58*_t87 - _t62*_t7;
  out[17] = d3f_drs2_dxt;
  const double d3f_drs2_dz = 0.4e1*_hc0[1]*_hc1[0]*_hc1[2]*_hc2[2]*_hc3[0]*_t3*_t8 + 0.2e1*_hc0[1]*_hc2[2]*_hc3[1]*_t2*_t3*_t8 + _hc0[1]*_hc2[5]*_hc3[0]*_t2*_t3*_t8 - _t102 - _t105 - _t106 - _t108 - _t11*_t62;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = -_hc2[2]*_t121 - _hc2[2]*_t124 - _hc2[2]*_t126 - _hc2[5]*_t122 - _hc2[5]*_t125 - _hc2[9]*_t6 + _t109 + _t112 + _t114 + _t115 + _t117 + _t119 + _t122*_t62 - _t123*_t58 + _t125*_t62 + _t127*_t18 - _t128*_t6;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t6 - _hc2[10]*_t6 + ((_hc2[3]) * (_hc2[3]))*_t134 - _hc2[3]*_t132 + 0.24e2*_hc2[3]*_t133*_t64 - 0.6e1*_hc2[3]*_t29 - _hc2[6]*_t130 + 0.4e1*_hc2[6]*_t7 - _t130*_t69 + _t132*_t28;
  out[20] = d4f_dxt4;
  const double d4f_dz_dxt3 = _hc2[1]*_t135*_t70 + _hc2[3]*_t136 + _hc2[6]*_t11 + _t11*_t69 - _t136*_t28 - _t137*_t35;
  out[21] = d4f_dz_dxt3;
  const double d4f_dz2_dxt2 = 0.4e1*_hc0[2]*_hc1[0]*_hc1[1]*_hc2[1]*_hc3[0]*_t3*_t8 + _hc0[2]*_hc2[3]*_hc3[0]*_t2*_t3*_t8 - _hc2[3]*_t79 + 0.4e1*_hc3[0]*_t19*_t3*_t38*_t39 + 0.2e1*_hc3[0]*_t2*_t28*_t3*_t38*_t39 - _t138*_t139*_t75 - _t28*_t37 - _t70*_t95;
  out[22] = d4f_dz2_dxt2;
  const double d4f_dz3_dxt = -_hc0[3]*_t72 - _hc2[1]*_t142 + _hc2[1]*_t80 + _hc2[1]*_t85 + 0.12e2*_t10*_t138*_t140 - _t138*_t141;
  out[23] = d4f_dz3_dxt;
  const double d4f_dz4 = ((_hc0[2]) * (_hc0[2]))*_t38*_t81 - 0.36e2*_hc0[2]*_t143*_t39*_t82 + 0.8e1*_hc0[3]*_t10*_t38*_t4 - _hc0[4]*_t36 + 0.24e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t143/xc_powi((_hc0[0]), 5);
  out[24] = d4f_dz4;
  const double d4f_drs_dxt3 = 0.12e2*_hc1[0]*_hc1[1]*_hc2[1]*_hc2[4]*_hc3[0]*_t1*_t3 + 0.6e1*_hc1[0]*_hc1[1]*_hc2[2]*_hc2[3]*_hc3[0]*_t1*_t3 + 0.6e1*_hc1[0]*_hc1[1]*_hc3[1]*_t1*_t28*_t3 + 0.6e1*_hc1[0]*_hc1[2]*_hc2[1]*_hc2[3]*_hc3[0]*_t1*_t3 + 0.6e1*_hc1[0]*_hc1[4]*_hc3[0]*_t1*_t28*_t3 + 0.6e1*_hc1[1]*_hc1[2]*_hc3[0]*_t1*_t28*_t3 - _hc1[1]*_t28*_t58*_t65 + 0.6e1*_hc2[1]*_hc2[2]*_hc3[0]*_t1*_t19*_t3 + 0.3e1*_hc2[1]*_hc2[3]*_hc3[1]*_t1*_t2*_t3 + 0.3e1*_hc2[1]*_hc2[7]*_hc3[0]*_t1*_t2*_t3 - _hc2[11]*_t6 + _hc2[2]*_hc2[6]*_hc3[0]*_t1*_t2*_t3 + _hc2[2]*_hc3[0]*_t1*_t2*_t3*_t69 + 0.3e1*_hc2[3]*_hc2[4]*_hc3[0]*_t1*_t2*_t3 - _hc2[3]*_t144 - _hc2[4]*_t20*_t67 - 0.3e1*_hc2[4]*_t29 - _hc2[6]*_t12 - _hc2[6]*_t17 - _hc2[7]*_t64*_t65 - _t12*_t69 - 0.12e2*_t133*_t146 - _t137*_t45 - _t145*_t66 - _t147*_t68 - _t17*_t69 - _t66*_t89;
  out[25] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxt2 = -_hc0[1]*_t70*_t98 + _hc2[1]*_t149*_t89 + _hc2[1]*_t153*_t154 + _hc2[2]*_t71 - _hc2[3]*_t158 + _hc2[3]*_t47 + _hc2[3]*_t50 + _hc2[7]*_t11 + _t104*_t151 - _t146*_t149 - _t151*_t156 + _t152*_t153*_t32 - _t157*_t35 + _t158*_t28 - _t28*_t47 - _t28*_t50;
  out[26] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxt = 0.2e1*_hc0[2]*_hc1[0]*_hc1[1]*_hc2[2]*_hc3[0]*_t3*_t8 + 0.2e1*_hc0[2]*_hc1[0]*_hc1[2]*_hc2[1]*_hc3[0]*_t3*_t8 - _hc0[2]*_hc1[2]*_t41*_t92 + _hc0[2]*_hc2[1]*_hc3[1]*_t2*_t3*_t8 + _hc0[2]*_hc2[4]*_hc3[0]*_t2*_t3*_t8 - _hc0[2]*_t91 + 0.4e1*_hc1[0]*_hc1[1]*_hc3[1]*_t3*_t38*_t39 + 0.4e1*_hc1[0]*_hc1[4]*_hc3[0]*_t3*_t38*_t39 + 0.4e1*_hc1[1]*_hc1[2]*_hc3[0]*_t3*_t38*_t39 + 0.2e1*_hc2[1]*_hc2[2]*_hc3[0]*_t2*_t3*_t38*_t39 - _hc2[1]*_t97 - _hc2[1]*_t99 - _hc2[2]*_t73 - _hc2[2]*_t77 - _hc2[4]*_t79 - _t154*_t95;
  out[27] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = 0.12e2*_hc0[1]*_hc0[2]*_hc1[0]*_hc1[2]*_hc3[0]*_t3*_t38 + 0.6e1*_hc0[1]*_hc0[2]*_hc3[1]*_t2*_t3*_t38 + _hc0[3]*_hc2[2]*_hc3[0]*_t2*_t3*_t8 - _hc0[3]*_t13*_t96 - _hc0[3]*_t46 - _hc1[2]*_t141*_t31 + 0.6e1*_hc2[2]*_hc3[0]*_t2*_t3*_t82*_t83 - _hc2[2]*_t142 - _t147*_t4*_t84;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dxt2 = 0.8e1*_hc1[0]*_hc1[1]*_hc2[1]*_hc2[2]*_hc3[1]*_t1*_t3 + 0.4e1*_hc1[0]*_hc1[1]*_hc2[1]*_hc2[5]*_hc3[0]*_t1*_t3 + 0.8e1*_hc1[0]*_hc1[1]*_hc2[2]*_hc2[4]*_hc3[0]*_t1*_t3 + 0.8e1*_hc1[0]*_hc1[2]*_hc2[1]*_hc2[4]*_hc3[0]*_t1*_t3 + 0.4e1*_hc1[0]*_hc1[2]*_hc2[2]*_hc2[3]*_hc3[0]*_t1*_t3 + 0.4e1*_hc1[0]*_hc1[2]*_hc3[1]*_t1*_t28*_t3 + 0.8e1*_hc1[0]*_hc1[4]*_hc2[1]*_hc2[2]*_hc3[0]*_t1*_t3 + 0.2e1*_hc1[0]*_hc1[5]*_hc3[0]*_t1*_t28*_t3 - _hc1[0]*_hc2[7]*_t59 + 0.8e1*_hc1[1]*_hc1[2]*_hc2[1]*_hc2[2]*_hc3[0]*_t1*_t3 + 0.8e1*_hc1[1]*_hc1[4]*_hc3[1]*_t1*_t3 + 0.4e1*_hc1[1]*_hc1[8]*_hc3[0]*_t1*_t3 - _hc1[2]*_t133*_t160 + 0.4e1*((_hc1[4]) * (_hc1[4]))*_hc3[0]*_t1*_t3 - _hc1[5]*_hc2[1]*_t24 - _hc1[8]*_t23*_t88 + 0.4e1*_hc2[1]*_hc2[4]*_hc3[1]*_t1*_t2*_t3 + 0.2e1*_hc2[1]*_hc2[8]*_hc3[0]*_t1*_t2*_t3 - _hc2[1]*_t160*_t40 - _hc2[12]*_t6 + 0.2e1*_hc2[2]*_hc2[3]*_hc3[1]*_t1*_t2*_t3 + 0.2e1*_hc2[2]*_hc2[7]*_hc3[0]*_t1*_t2*_t3 + _hc2[3]*_hc2[5]*_hc3[0]*_t1*_t2*_t3 - _hc2[3]*_t51 - _hc2[3]*_t53 - _hc2[3]*_t54 - _hc2[3]*_t57 + 0.2e1*((_hc2[4]) * (_hc2[4]))*_hc3[0]*_t1*_t2*_t3 - _hc2[4]*_t129*_t89 - _hc2[5]*_t21 - _hc2[5]*_t29 - _hc2[7]*_t61 - _hc2[8]*_t25 + 0.2e1*_hc3[0]*_t1*_t19*_t3*_t62 + _hc3[0]*_t1*_t2*_t28*_t3*_t62 + 0.2e1*_hc3[0]*_t1*_t28*_t3*_t55 - _hc3[1]*_t139*_t162 + 0.2e1*_hc3[2]*_t1*_t19*_t3 + _hc3[2]*_t1*_t2*_t28*_t3 - _t100*_t161 - 0.4e1*_t110*_t150 - _t12*_t166*_t28 - _t152*_t159 - _t161*_t163 - _t164*_t20 - _t165*_t45 - _t26*_t62 - _t27*_t62 - _t28*_t60;
  out[29] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxt = -_hc0[1]*_hc3[2]*_t33 + _hc1[1]*_t164*_t167 - 0.4e1*_hc1[4]*_t94 - _hc1[5]*_t148*_t30 - _hc1[8]*_t49 + _hc2[1]*_t102 + _hc2[1]*_t105 + _hc2[1]*_t106 + _hc2[1]*_t108 - _hc2[1]*_t155*_t168 - _hc2[1]*_t166*_t47 + _hc2[5]*_t34 - _hc2[5]*_t35 + _hc2[8]*_t11 - _t104*_t154 - _t104*_t89*_t92 + _t148*_t155*_t89 + _t154*_t156 - _t157*_t158 + _t157*_t47 + _t165*_t168 - _t34*_t62 + _t35*_t62;
  out[30] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = 0.4e1*_hc0[2]*_hc1[0]*_hc1[2]*_hc2[2]*_hc3[0]*_t3*_t8 + 0.2e1*_hc0[2]*_hc2[2]*_hc3[1]*_t2*_t3*_t8 + _hc0[2]*_hc2[5]*_hc3[0]*_t2*_t3*_t8 - _hc0[2]*_t101 - _hc0[2]*_t103*_t96 + 0.8e1*_hc1[0]*_hc1[2]*_hc3[1]*_t3*_t38*_t39 + 0.4e1*_hc1[0]*_hc1[5]*_hc3[0]*_t3*_t38*_t39 - _hc1[5]*_t32*_t95 - _hc2[2]*_t169*_t31*_t75 - _hc2[5]*_t79 + 0.2e1*_hc3[0]*_t2*_t3*_t38*_t39*_t62 + 0.4e1*_hc3[0]*_t3*_t38*_t39*_t55 + 0.2e1*_hc3[2]*_t2*_t3*_t38*_t39 - _t107*_t95 - _t164*_t78 - _t37*_t62;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dxt = 0.6e1*_hc1[0]*_hc1[1]*_hc2[2]*_hc2[5]*_hc3[0]*_t1*_t3 + 0.6e1*_hc1[0]*_hc1[1]*_hc3[1]*_t1*_t3*_t62 + 0.2e1*_hc1[0]*_hc1[1]*_hc3[3]*_t1*_t3 + 0.2e1*_hc1[0]*_hc1[13]*_hc3[0]*_t1*_t3 + 0.12e2*_hc1[0]*_hc1[2]*_hc2[1]*_hc2[2]*_hc3[1]*_t1*_t3 + 0.6e1*_hc1[0]*_hc1[2]*_hc2[1]*_hc2[5]*_hc3[0]*_t1*_t3 + 0.12e2*_hc1[0]*_hc1[2]*_hc2[2]*_hc2[4]*_hc3[0]*_t1*_t3 + 0.6e1*_hc1[0]*_hc1[4]*_hc3[0]*_t1*_t3*_t62 + 0.6e1*_hc1[0]*_hc1[4]*_hc3[2]*_t1*_t3 + 0.6e1*_hc1[0]*_hc1[5]*_hc2[1]*_hc2[2]*_hc3[0]*_t1*_t3 + 0.6e1*_hc1[0]*_hc1[8]*_hc3[1]*_t1*_t3 + 0.6e1*_hc1[1]*_hc1[2]*_hc3[0]*_t1*_t3*_t62 + 0.6e1*_hc1[1]*_hc1[2]*_hc3[2]*_t1*_t3 + 0.6e1*_hc1[1]*_hc1[5]*_hc3[1]*_t1*_t3 + 0.2e1*_hc1[1]*_hc1[9]*_hc3[0]*_t1*_t3 + 0.12e2*_hc1[2]*_hc1[4]*_hc3[1]*_t1*_t3 + 0.6e1*_hc1[2]*_hc1[8]*_hc3[0]*_t1*_t3 + 0.6e1*_hc1[4]*_hc1[5]*_hc3[0]*_t1*_t3 - _hc1[4]*_t120*_t173 - 0.12e2*_hc1[4]*_t170 - _hc1[8]*_t58*_t65 + 0.6e1*_hc2[1]*_hc2[2]*_hc3[0]*_t1*_t3*_t55 + 0.3e1*_hc2[1]*_hc2[2]*_hc3[2]*_t1*_t2*_t3 + 0.3e1*_hc2[1]*_hc2[5]*_hc3[1]*_t1*_t2*_t3 + _hc2[1]*_hc2[9]*_hc3[0]*_t1*_t2*_t3 + _hc2[1]*_hc3[0]*_t1*_t128*_t2*_t3 - _hc2[1]*_t109 - _hc2[1]*_t112 - _hc2[1]*_t114 - _hc2[1]*_t115 - _hc2[1]*_t117 - _hc2[1]*_t119 - _hc2[13]*_t6 + 0.6e1*_hc2[2]*_hc2[4]*_hc3[1]*_t1*_t2*_t3 + 0.3e1*_hc2[2]*_hc2[8]*_hc3[0]*_t1*_t2*_t3 + 0.3e1*_hc2[4]*_hc2[5]*_hc3[0]*_t1*_t2*_t3 - _hc2[4]*_t121 - _hc2[4]*_t124 - _hc2[4]*_t126 - _hc2[5]*_t144 - _hc2[8]*_t122 - _hc2[8]*_t125 - _hc2[9]*_t42 - _t100*_t123 - _t111*_t163 - _t116*_t62*_t88 - _t123*_t163 - _t127*_t45 - _t128*_t42 - _t145*_t171 - 0.12e2*_t162*_t172 - _t171*_t89 - _t174*_t43 - _t174*_t44;
  out[32] = d4f_drs3_dxt;
  const double d4f_drs3_dz = 0.12e2*_hc0[1]*_hc1[0]*_hc1[2]*_hc2[2]*_hc3[1]*_t3*_t8 + 0.6e1*_hc0[1]*_hc1[0]*_hc1[2]*_hc2[5]*_hc3[0]*_t3*_t8 + 0.6e1*_hc0[1]*_hc1[0]*_hc1[5]*_hc2[2]*_hc3[0]*_t3*_t8 + 0.6e1*_hc0[1]*_hc2[2]*_hc3[0]*_t3*_t55*_t8 + 0.3e1*_hc0[1]*_hc2[2]*_hc3[2]*_t2*_t3*_t8 + 0.3e1*_hc0[1]*_hc2[5]*_hc3[1]*_t2*_t3*_t8 + _hc0[1]*_hc2[9]*_hc3[0]*_t2*_t3*_t8 + _hc0[1]*_hc3[0]*_t128*_t2*_t3*_t8 - 0.6e1*_hc0[1]*_hc3[2]*_t96 - _hc0[1]*_hc3[3]*_t9 - _hc0[1]*_t107*_t147 - _hc1[5]*_t147*_t167 - _hc1[9]*_t49 - _t127*_t158 - _t135*_t175*_t92 - _t135*_t62*_t96 - _t174*_t47;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = _hc1[14]*_t16 + ((_hc1[5]) * (_hc1[5]))*_t65 - 0.24e2*_hc1[5]*_t170 - _hc1[9]*_t129*_t58 + _hc1[9]*_t159 + _hc1[9]*_t178 - _hc2[14]*_t6 + ((_hc2[2]) * (_hc2[2]) * (_hc2[2]) * (_hc2[2]))*_t6 + 0.12e2*_hc2[2]*_hc2[5]*_t12 - _hc2[2]*_t110*_t180 + ((_hc2[5]) * (_hc2[5]))*_t134 - _hc2[5]*_t181 - _hc2[5]*_t185 - _hc2[5]*_t187 - 0.6e1*_hc2[5]*_t63 + 0.4e1*_hc2[9]*_t18 - _hc2[9]*_t182 - _hc2[9]*_t186 + _hc3[1]*_t14*_t177 + _hc3[2]*_t179 + _hc3[3]*_t15*_t169 + _hc3[4]*_t5 - _t109*_t155 + _t110*_t176 - _t128*_t182 - _t128*_t186 - 0.24e2*_t172*_t56 - _t173*_t177 + _t180*_t183*_t58 + _t181*_t62 - _t183*_t184 + _t184*_t22*_t62 + _t185*_t62 + _t187*_t62;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_p86_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pz_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(p86_H_k, _KMAX)(p, rs, z, xt, _hc1);

  const double f = _hc0[0] + _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0;
  out[1] = df_dxs1;
  const double df_dxs0 = 0;
  out[2] = df_dxs0;
  const double df_dxt = _hc1[1];
  out[3] = df_dxt;
  const double df_dz = _hc0[1] + _hc1[2];
  out[4] = df_dz;
  const double df_drs = _hc0[2] + _hc1[3];
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[6] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[7] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[8] = d2f_dxs02;
  const double d2f_dxt_dxs1 = 0;
  out[9] = d2f_dxt_dxs1;
  const double d2f_dxt_dxs0 = 0;
  out[10] = d2f_dxt_dxs0;
  const double d2f_dxt2 = _hc1[4];
  out[11] = d2f_dxt2;
  const double d2f_dz_dxs1 = 0;
  out[12] = d2f_dz_dxs1;
  const double d2f_dz_dxs0 = 0;
  out[13] = d2f_dz_dxs0;
  const double d2f_dz_dxt = _hc1[5];
  out[14] = d2f_dz_dxt;
  const double d2f_dz2 = _hc0[3] + _hc1[6];
  out[15] = d2f_dz2;
  const double d2f_drs_dxs1 = 0;
  out[16] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[17] = d2f_drs_dxs0;
  const double d2f_drs_dxt = _hc1[7];
  out[18] = d2f_drs_dxt;
  const double d2f_drs_dz = _hc0[4] + _hc1[8];
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[5] + _hc1[9];
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[21] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[22] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[23] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[24] = d3f_dxs03;
  const double d3f_dxt_dxs12 = 0;
  out[25] = d3f_dxt_dxs12;
  const double d3f_dxt_dxs0_dxs1 = 0;
  out[26] = d3f_dxt_dxs0_dxs1;
  const double d3f_dxt_dxs02 = 0;
  out[27] = d3f_dxt_dxs02;
  const double d3f_dxt2_dxs1 = 0;
  out[28] = d3f_dxt2_dxs1;
  const double d3f_dxt2_dxs0 = 0;
  out[29] = d3f_dxt2_dxs0;
  const double d3f_dxt3 = _hc1[10];
  out[30] = d3f_dxt3;
  const double d3f_dz_dxs12 = 0;
  out[31] = d3f_dz_dxs12;
  const double d3f_dz_dxs0_dxs1 = 0;
  out[32] = d3f_dz_dxs0_dxs1;
  const double d3f_dz_dxs02 = 0;
  out[33] = d3f_dz_dxs02;
  const double d3f_dz_dxt_dxs1 = 0;
  out[34] = d3f_dz_dxt_dxs1;
  const double d3f_dz_dxt_dxs0 = 0;
  out[35] = d3f_dz_dxt_dxs0;
  const double d3f_dz_dxt2 = _hc1[11];
  out[36] = d3f_dz_dxt2;
  const double d3f_dz2_dxs1 = 0;
  out[37] = d3f_dz2_dxs1;
  const double d3f_dz2_dxs0 = 0;
  out[38] = d3f_dz2_dxs0;
  const double d3f_dz2_dxt = _hc1[12];
  out[39] = d3f_dz2_dxt;
  const double d3f_dz3 = _hc0[6] + _hc1[13];
  out[40] = d3f_dz3;
  const double d3f_drs_dxs12 = 0;
  out[41] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[42] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[43] = d3f_drs_dxs02;
  const double d3f_drs_dxt_dxs1 = 0;
  out[44] = d3f_drs_dxt_dxs1;
  const double d3f_drs_dxt_dxs0 = 0;
  out[45] = d3f_drs_dxt_dxs0;
  const double d3f_drs_dxt2 = _hc1[14];
  out[46] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxs1 = 0;
  out[47] = d3f_drs_dz_dxs1;
  const double d3f_drs_dz_dxs0 = 0;
  out[48] = d3f_drs_dz_dxs0;
  const double d3f_drs_dz_dxt = _hc1[15];
  out[49] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = _hc0[7] + _hc1[16];
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dxs1 = 0;
  out[51] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[52] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = _hc1[17];
  out[53] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _hc0[8] + _hc1[18];
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[9] + _hc1[19];
  out[55] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[56] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[57] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[58] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[59] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[60] = d4f_dxs04;
  const double d4f_dxt_dxs13 = 0;
  out[61] = d4f_dxt_dxs13;
  const double d4f_dxt_dxs0_dxs12 = 0;
  out[62] = d4f_dxt_dxs0_dxs12;
  const double d4f_dxt_dxs02_dxs1 = 0;
  out[63] = d4f_dxt_dxs02_dxs1;
  const double d4f_dxt_dxs03 = 0;
  out[64] = d4f_dxt_dxs03;
  const double d4f_dxt2_dxs12 = 0;
  out[65] = d4f_dxt2_dxs12;
  const double d4f_dxt2_dxs0_dxs1 = 0;
  out[66] = d4f_dxt2_dxs0_dxs1;
  const double d4f_dxt2_dxs02 = 0;
  out[67] = d4f_dxt2_dxs02;
  const double d4f_dxt3_dxs1 = 0;
  out[68] = d4f_dxt3_dxs1;
  const double d4f_dxt3_dxs0 = 0;
  out[69] = d4f_dxt3_dxs0;
  const double d4f_dxt4 = _hc1[20];
  out[70] = d4f_dxt4;
  const double d4f_dz_dxs13 = 0;
  out[71] = d4f_dz_dxs13;
  const double d4f_dz_dxs0_dxs12 = 0;
  out[72] = d4f_dz_dxs0_dxs12;
  const double d4f_dz_dxs02_dxs1 = 0;
  out[73] = d4f_dz_dxs02_dxs1;
  const double d4f_dz_dxs03 = 0;
  out[74] = d4f_dz_dxs03;
  const double d4f_dz_dxt_dxs12 = 0;
  out[75] = d4f_dz_dxt_dxs12;
  const double d4f_dz_dxt_dxs0_dxs1 = 0;
  out[76] = d4f_dz_dxt_dxs0_dxs1;
  const double d4f_dz_dxt_dxs02 = 0;
  out[77] = d4f_dz_dxt_dxs02;
  const double d4f_dz_dxt2_dxs1 = 0;
  out[78] = d4f_dz_dxt2_dxs1;
  const double d4f_dz_dxt2_dxs0 = 0;
  out[79] = d4f_dz_dxt2_dxs0;
  const double d4f_dz_dxt3 = _hc1[21];
  out[80] = d4f_dz_dxt3;
  const double d4f_dz2_dxs12 = 0;
  out[81] = d4f_dz2_dxs12;
  const double d4f_dz2_dxs0_dxs1 = 0;
  out[82] = d4f_dz2_dxs0_dxs1;
  const double d4f_dz2_dxs02 = 0;
  out[83] = d4f_dz2_dxs02;
  const double d4f_dz2_dxt_dxs1 = 0;
  out[84] = d4f_dz2_dxt_dxs1;
  const double d4f_dz2_dxt_dxs0 = 0;
  out[85] = d4f_dz2_dxt_dxs0;
  const double d4f_dz2_dxt2 = _hc1[22];
  out[86] = d4f_dz2_dxt2;
  const double d4f_dz3_dxs1 = 0;
  out[87] = d4f_dz3_dxs1;
  const double d4f_dz3_dxs0 = 0;
  out[88] = d4f_dz3_dxs0;
  const double d4f_dz3_dxt = _hc1[23];
  out[89] = d4f_dz3_dxt;
  const double d4f_dz4 = _hc0[10] + _hc1[24];
  out[90] = d4f_dz4;
  const double d4f_drs_dxs13 = 0;
  out[91] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[92] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[93] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[94] = d4f_drs_dxs03;
  const double d4f_drs_dxt_dxs12 = 0;
  out[95] = d4f_drs_dxt_dxs12;
  const double d4f_drs_dxt_dxs0_dxs1 = 0;
  out[96] = d4f_drs_dxt_dxs0_dxs1;
  const double d4f_drs_dxt_dxs02 = 0;
  out[97] = d4f_drs_dxt_dxs02;
  const double d4f_drs_dxt2_dxs1 = 0;
  out[98] = d4f_drs_dxt2_dxs1;
  const double d4f_drs_dxt2_dxs0 = 0;
  out[99] = d4f_drs_dxt2_dxs0;
  const double d4f_drs_dxt3 = _hc1[25];
  out[100] = d4f_drs_dxt3;
  const double d4f_drs_dz_dxs12 = 0;
  out[101] = d4f_drs_dz_dxs12;
  const double d4f_drs_dz_dxs0_dxs1 = 0;
  out[102] = d4f_drs_dz_dxs0_dxs1;
  const double d4f_drs_dz_dxs02 = 0;
  out[103] = d4f_drs_dz_dxs02;
  const double d4f_drs_dz_dxt_dxs1 = 0;
  out[104] = d4f_drs_dz_dxt_dxs1;
  const double d4f_drs_dz_dxt_dxs0 = 0;
  out[105] = d4f_drs_dz_dxt_dxs0;
  const double d4f_drs_dz_dxt2 = _hc1[26];
  out[106] = d4f_drs_dz_dxt2;
  const double d4f_drs_dz2_dxs1 = 0;
  out[107] = d4f_drs_dz2_dxs1;
  const double d4f_drs_dz2_dxs0 = 0;
  out[108] = d4f_drs_dz2_dxs0;
  const double d4f_drs_dz2_dxt = _hc1[27];
  out[109] = d4f_drs_dz2_dxt;
  const double d4f_drs_dz3 = _hc0[11] + _hc1[28];
  out[110] = d4f_drs_dz3;
  const double d4f_drs2_dxs12 = 0;
  out[111] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[112] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[113] = d4f_drs2_dxs02;
  const double d4f_drs2_dxt_dxs1 = 0;
  out[114] = d4f_drs2_dxt_dxs1;
  const double d4f_drs2_dxt_dxs0 = 0;
  out[115] = d4f_drs2_dxt_dxs0;
  const double d4f_drs2_dxt2 = _hc1[29];
  out[116] = d4f_drs2_dxt2;
  const double d4f_drs2_dz_dxs1 = 0;
  out[117] = d4f_drs2_dz_dxs1;
  const double d4f_drs2_dz_dxs0 = 0;
  out[118] = d4f_drs2_dz_dxs0;
  const double d4f_drs2_dz_dxt = _hc1[30];
  out[119] = d4f_drs2_dz_dxt;
  const double d4f_drs2_dz2 = _hc0[12] + _hc1[31];
  out[120] = d4f_drs2_dz2;
  const double d4f_drs3_dxs1 = 0;
  out[121] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[122] = d4f_drs3_dxs0;
  const double d4f_drs3_dxt = _hc1[32];
  out[123] = d4f_drs3_dxt;
  const double d4f_drs3_dz = _hc0[13] + _hc1[33];
  out[124] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[14] + _hc1[34];
  out[125] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pz_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = rs - 0.1e1 >= 0;
  const double _t2 = xc_powr(rs, 1, 2);
  const double _t3 = 1.0528999999999999*_t2 + 0.33339999999999997*rs + 0.1e1;
  const double _t4 = log(rs);
  const double _t5 = 0.002*_t4;
#if _KMAX >= 1
  const double _t6 = (0.1e1 / (_t3 * _t3));
  const double _t7 = (0.1e1 / _t2);
  const double _t8 = -0.52644999999999997*_t7 - 0.33339999999999997;
  const double _t9 = 0.14230000000000001*_t8;
  const double _t10 = (0.1e1 / rs);
#endif
#if _KMAX >= 2
  const double _t11 = xc_powr(rs, -3, 2);
  const double _t12 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t13 = -1.0528999999999999*_t7 - 0.66679999999999995;
  const double _t14 = _t12*_t13;
  const double _t15 = (0.1e1 / (rs * rs));
#endif
#if _KMAX >= 3
  const double _t16 = xc_powr(rs, -5, 2);
  const double _t17 = 0.074913834999999998*_t11;
  const double _t18 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t19 = -1.5793499999999998*_t7 - 1.0002;
  const double _t20 = _t18*_t19;
  const double _t21 = _t13*_t20;
  const double _t22 = (0.1e1 / (rs * rs * rs));
#endif
#if _KMAX >= 4
  const double _t23 = _t11*_t8;
#endif

  const double f = my_piecewise3(_t1, -0.14230000000000001/_t3, 0.031099999999999999*_t4 + _t5*rs - 0.011599999999999999*rs - 0.048000000000000001);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = my_piecewise3(_t1, -_t6*_t9, 0.031099999999999999*_t10 + _t5 - 0.0095999999999999992);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = my_piecewise3(_t1, -0.037456917499999999*_t11*_t6 - _t14*_t9, 0.002*_t10 - 0.031099999999999999*_t15);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = my_piecewise3(_t1, -_t12*_t17*_t8 - _t14*_t17 + 0.056185376250000002*_t16*_t6 - _t21*_t9, -0.002*_t15 + 0.062199999999999998*_t22);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = my_piecewise3(_t1, -0.1123707525*_t11*_t21 + 0.16855612875000001*_t12*_t13*_t16 + 0.1123707525*_t12*_t16*_t8 - 0.059157582653624995*_t12*_t22 - 0.11237075249999999*_t13*_t18*_t23 - _t13*_t19*_t9*(-2.1057999999999999*_t7 - 1.3335999999999999)/xc_powi(_t3, 5) - 0.14982767*_t20*_t23 - 0.14046344062499999*_t6/xc_powr(rs, 7, 2), 0.0040000000000000001*_t22 - 0.18659999999999999/(rs * rs * rs * rs));
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(p86_H_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(p86_x1_k, _KMAX)(p, rs, xt, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(p86_mPhi_k, _KMAX)(p, rs, xt, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(p86_CC_k, _KMAX)(p, rs, _hc2);
  const double _t1 = ((_hc0[0]) * (_hc0[0]));
  const double _t2 = exp(-_hc1[0]);
  const double _t3 = _t1*_t2;
  const double _t4 = _hc2[0]*_t3;
#if _KMAX >= 1
  const double _t5 = _hc1[1]*_t4;
  const double _t6 = _hc2[1]*_t3;
  const double _t7 = _hc2[0]*_t2;
  const double _t8 = 0.2e1*_t7;
  const double _t9 = _hc0[0]*_t8;
  const double _t10 = _hc0[2]*_t9;
  const double _t11 = _hc1[2]*_t4;
#endif
#if _KMAX >= 2
  const double _t12 = ((_hc0[1]) * (_hc0[1]));
  const double _t13 = _t12*_t8;
  const double _t14 = 0.4e1*_t7;
  const double _t15 = _hc0[1]*_t14;
  const double _t16 = _hc0[0]*_t15;
  const double _t17 = _hc1[1]*_t16;
  const double _t18 = _hc1[3]*_t4;
  const double _t19 = ((_hc1[1]) * (_hc1[1]));
  const double _t20 = _t19*_t4;
  const double _t21 = _hc2[1]*_t2;
  const double _t22 = _hc0[0]*_t21;
  const double _t23 = _hc0[1]*_t9;
  const double _t24 = _hc1[1]*_t6;
  const double _t25 = _hc1[4]*_t4;
  const double _t26 = _hc1[2]*_t5;
  const double _t27 = _hc2[2]*_t3;
  const double _t28 = 0.4e1*_t22;
  const double _t29 = _hc0[2]*_t28;
  const double _t30 = _hc0[5]*_t9;
  const double _t31 = ((_hc0[2]) * (_hc0[2]));
  const double _t32 = _t31*_t8;
  const double _t33 = _hc0[0]*_hc1[2];
  const double _t34 = _hc0[2]*_t14;
  const double _t35 = _t33*_t34;
  const double _t36 = 0.2e1*_t6;
  const double _t37 = ((_hc1[2]) * (_hc1[2]));
  const double _t38 = _t37*_t4;
#endif
#if _KMAX >= 3
  const double _t39 = _hc0[1]*_hc1[3];
  const double _t40 = 0.6e1*_t7;
  const double _t41 = _hc0[0]*_t40;
  const double _t42 = _hc1[1]*_t12;
  const double _t43 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t44 = _hc0[1]*_t28;
  const double _t45 = _hc0[4]*_t14;
  const double _t46 = _hc0[0]*_hc1[1];
  const double _t47 = _hc0[1]*_hc0[2];
  const double _t48 = _t14*_t47;
  const double _t49 = _hc0[0]*_hc1[4];
  const double _t50 = _hc2[3]*_t3;
  const double _t51 = _hc2[2]*_t2;
  const double _t52 = _hc0[0]*_t51;
  const double _t53 = 0.6e1*_t52;
  const double _t54 = _hc0[2]*_t53;
  const double _t55 = 0.6e1*_t22;
  const double _t56 = _hc0[5]*_t55;
  const double _t57 = _hc0[9]*_t9;
  const double _t58 = _hc0[2]*_t40;
  const double _t59 = _hc0[5]*_t58;
  const double _t60 = 0.6e1*_t31;
  const double _t61 = _t21*_t60;
  const double _t62 = 0.12e2*_hc0[2]*_t22;
  const double _t63 = _hc0[0]*_t58;
  const double _t64 = 0.3e1*_t27;
  const double _t65 = 0.3e1*_t6;
  const double _t66 = _t60*_t7;
  const double _t67 = 0.3e1*_hc1[5];
  const double _t68 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
#endif
#if _KMAX >= 4
  const double _t69 = 0.8e1*_hc0[1];
  const double _t70 = _t69*_t7;
  const double _t71 = _hc0[0]*_t70;
  const double _t72 = 0.12e2*_t7;
  const double _t73 = _t12*_t72;
  const double _t74 = 0.3e1*_t4;
  const double _t75 = _hc0[4]*_t41;
  const double _t76 = _t40*_t47;
  const double _t77 = _hc0[4]*_hc1[1];
  const double _t78 = _hc1[4]*_t40;
  const double _t79 = _t33*_t40;
  const double _t80 = 0.8e1*_t22;
  const double _t81 = 0.8e1*_t7;
  const double _t82 = _t21*_t47;
  const double _t83 = _hc0[4]*_hc1[2];
  const double _t84 = 0.8e1*_hc0[2];
  const double _t85 = _t7*_t84;
  const double _t86 = _hc0[0]*_hc0[5];
  const double _t87 = 0.12e2*_hc1[2];
  const double _t88 = 0.3e1*_t37;
  const double _t89 = 0.24e2*_t21;
  const double _t90 = _hc0[2]*_hc0[5];
  const double _t91 = 0.12e2*_t31;
  const double _t92 = 0.24e2*_hc0[2];
  const double _t93 = _t22*_t92;
  const double _t94 = _hc0[0]*_t85;
  const double _t95 = 0.24e2*_hc1[2];
  const double _t96 = _t72*_t86;
  const double _t97 = 0.6e1*_t27;
  const double _t98 = 0.4e1*_t6;
  const double _t99 = _t7*_t91;
#endif

  const double f = _t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = 0.2e1*_hc0[0]*_hc0[1]*_hc2[0]*_t2 - _t5;
  out[1] = df_dxt;
  const double df_drs = _t10 - _t11 + _t6;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = _t13 - _t17 - _t18 + _t20;
  out[3] = d2f_dxt2;
  const double d2f_drs_dxt = _hc0[1]*_hc0[2]*_t8 + 0.2e1*_hc0[1]*_t22 + _hc0[4]*_t9 - _hc1[1]*_t10 - _hc1[2]*_t23 - _t24 - _t25 + _t26;
  out[4] = d2f_drs_dxt;
  const double d2f_drs2 = -_hc1[2]*_t36 - _hc1[5]*_t4 + _t27 + _t29 + _t30 + _t32 - _t35 + _t38;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0.6e1*_hc0[0]*_hc0[1]*_hc2[0]*_t19*_t2 + 0.3e1*_hc1[1]*_hc1[3]*_hc2[0]*_t1*_t2 - _hc1[6]*_t4 - _t39*_t41 - _t4*_t43 - _t40*_t42;
  out[6] = d3f_dxt3;
  const double d3f_drs_dxt2 = 0.4e1*_hc0[0]*_hc0[1]*_hc1[1]*_hc1[2]*_hc2[0]*_t2 + 0.2e1*_hc0[0]*_hc0[2]*_hc2[0]*_t19*_t2 + 0.4e1*_hc0[1]*_hc0[4]*_hc2[0]*_t2 + 0.2e1*_hc1[1]*_hc1[4]*_hc2[0]*_t1*_t2 - _hc1[1]*_t44 - _hc1[1]*_t48 + _hc1[2]*_hc1[3]*_hc2[0]*_t1*_t2 - _hc1[2]*_t13 - _hc1[3]*_t10 - _hc1[3]*_t6 - _hc1[4]*_t16 - _hc1[7]*_t4 + _hc2[1]*_t1*_t19*_t2 + 0.2e1*_hc2[1]*_t12*_t2 - _t11*_t19 - _t45*_t46;
  out[7] = d3f_drs_dxt2;
  const double d3f_drs2_dxt = 0.2e1*_hc0[0]*_hc0[1]*_hc2[0]*_t2*_t37 + 0.2e1*_hc0[0]*_hc0[1]*_hc2[2]*_t2 + 0.4e1*_hc0[0]*_hc0[2]*_hc1[1]*_hc1[2]*_hc2[0]*_t2 + 0.4e1*_hc0[0]*_hc0[4]*_hc2[1]*_t2 + 0.2e1*_hc0[0]*_hc0[8]*_hc2[0]*_t2 + 0.4e1*_hc0[1]*_hc0[2]*_hc2[1]*_t2 + 0.2e1*_hc0[1]*_hc0[5]*_hc2[0]*_t2 + 0.4e1*_hc0[2]*_hc0[4]*_hc2[0]*_t2 + 0.2e1*_hc1[1]*_hc1[2]*_hc2[1]*_t1*_t2 + _hc1[1]*_hc1[5]*_hc2[0]*_t1*_t2 - _hc1[1]*_t27 - _hc1[1]*_t29 - _hc1[1]*_t30 - _hc1[1]*_t32 + 0.2e1*_hc1[2]*_hc1[4]*_hc2[0]*_t1*_t2 - _hc1[2]*_t44 - _hc1[2]*_t48 - _hc1[4]*_t36 - _hc1[5]*_t23 - _hc1[8]*_t4 - _t33*_t45 - _t34*_t49 - _t37*_t5;
  out[8] = d3f_drs2_dxt;
  const double d3f_drs3 = -_hc0[5]*_t33*_t40 - _hc1[2]*_t62 - _hc1[2]*_t64 - _hc1[2]*_t66 - _hc1[5]*_t63 - _hc1[5]*_t65 - _hc1[9]*_t4 + _t11*_t67 + _t37*_t63 + _t37*_t65 - _t4*_t68 + _t50 + _t54 + _t56 + _t57 + _t59 + _t61;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxt4 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t4 - _hc1[10]*_t4 + ((_hc1[3]) * (_hc1[3]))*_t74 - 0.6e1*_hc1[3]*_t20 - _hc1[3]*_t73 + 0.4e1*_hc1[6]*_t5 - _hc1[6]*_t71 + _t19*_t73 + 0.24e2*_t39*_t46*_t7 - _t43*_t71;
  out[10] = d4f_dxt4;
  const double d4f_drs_dxt3 = 0.12e2*_hc0[0]*_hc0[1]*_hc1[1]*_hc1[4]*_hc2[0]*_t2 + 0.6e1*_hc0[0]*_hc0[1]*_hc1[2]*_hc1[3]*_hc2[0]*_t2 + 0.6e1*_hc0[0]*_hc0[1]*_hc2[1]*_t19*_t2 + 0.6e1*_hc0[0]*_hc0[2]*_hc1[1]*_hc1[3]*_hc2[0]*_t2 + 0.6e1*_hc0[0]*_hc0[4]*_hc2[0]*_t19*_t2 + 0.6e1*_hc0[1]*_hc0[2]*_hc2[0]*_t19*_t2 - _hc0[1]*_hc1[7]*_t41 - _hc0[1]*_t19*_t79 - _hc0[1]*_t72*_t77 + 0.6e1*_hc1[1]*_hc1[2]*_hc2[0]*_t12*_t2 + 0.3e1*_hc1[1]*_hc1[3]*_hc2[1]*_t1*_t2 + 0.3e1*_hc1[1]*_hc1[7]*_hc2[0]*_t1*_t2 - _hc1[11]*_t4 + _hc1[2]*_hc1[6]*_hc2[0]*_t1*_t2 + _hc1[2]*_hc2[0]*_t1*_t2*_t43 + 0.3e1*_hc1[3]*_hc1[4]*_hc2[0]*_t1*_t2 - 0.3e1*_hc1[3]*_t26 - _hc1[3]*_t75 - _hc1[3]*_t76 - 0.3e1*_hc1[4]*_t20 - _hc1[6]*_t10 - _hc1[6]*_t6 - _t10*_t43 - _t12*_t78 - 0.6e1*_t21*_t42 - _t39*_t55 - _t43*_t6;
  out[11] = d4f_drs_dxt3;
  const double d4f_drs2_dxt2 = 0.8e1*_hc0[0]*_hc0[1]*_hc1[1]*_hc1[2]*_hc2[1]*_t2 + 0.4e1*_hc0[0]*_hc0[1]*_hc1[1]*_hc1[5]*_hc2[0]*_t2 + 0.8e1*_hc0[0]*_hc0[1]*_hc1[2]*_hc1[4]*_hc2[0]*_t2 + 0.8e1*_hc0[0]*_hc0[2]*_hc1[1]*_hc1[4]*_hc2[0]*_t2 + 0.4e1*_hc0[0]*_hc0[2]*_hc1[2]*_hc1[3]*_hc2[0]*_t2 + 0.4e1*_hc0[0]*_hc0[2]*_hc2[1]*_t19*_t2 + 0.8e1*_hc0[0]*_hc0[4]*_hc1[1]*_hc1[2]*_hc2[0]*_t2 + 0.2e1*_hc0[0]*_hc0[5]*_hc2[0]*_t19*_t2 - _hc0[0]*_hc1[7]*_t34 + 0.8e1*_hc0[1]*_hc0[2]*_hc1[1]*_hc1[2]*_hc2[0]*_t2 + 0.8e1*_hc0[1]*_hc0[4]*_hc2[1]*_t2 + 0.4e1*_hc0[1]*_hc0[8]*_hc2[0]*_t2 - 0.4e1*_hc0[1]*_hc1[1]*_t52 + 0.4e1*((_hc0[4]) * (_hc0[4]))*_hc2[0]*_t2 - _hc0[4]*_t49*_t81 - _hc0[5]*_hc1[1]*_t15 - _hc0[8]*_t14*_t46 + 0.4e1*_hc1[1]*_hc1[4]*_hc2[1]*_t1*_t2 + 0.2e1*_hc1[1]*_hc1[8]*_hc2[0]*_t1*_t2 - 0.8e1*_hc1[1]*_t82 - _hc1[12]*_t4 + 0.2e1*_hc1[2]*_hc1[3]*_hc2[1]*_t1*_t2 + 0.2e1*_hc1[2]*_hc1[7]*_hc2[0]*_t1*_t2 - 0.4e1*_hc1[2]*_t12*_t21 - 0.2e1*_hc1[2]*_t19*_t6 + _hc1[3]*_hc1[5]*_hc2[0]*_t1*_t2 - _hc1[3]*_t27 - _hc1[3]*_t29 - _hc1[3]*_t30 - _hc1[3]*_t32 + 0.2e1*((_hc1[4]) * (_hc1[4]))*_hc2[0]*_t1*_t2 - _hc1[4]*_t22*_t69 - 0.4e1*_hc1[4]*_t26 - _hc1[4]*_t47*_t81 - _hc1[5]*_t13 - _hc1[5]*_t20 - _hc1[7]*_t36 - _hc1[8]*_t16 + _hc2[0]*_t1*_t19*_t2*_t37 + 0.2e1*_hc2[0]*_t12*_t2*_t37 + 0.2e1*_hc2[0]*_t19*_t2*_t31 + _hc2[2]*_t1*_t19*_t2 + 0.2e1*_hc2[2]*_t12*_t2 - _t17*_t37 - _t18*_t37 - _t19*_t35 - _t70*_t83 - _t77*_t80 - _t77*_t85;
  out[12] = d4f_drs2_dxt2;
  const double d4f_drs3_dxt = 0.6e1*_hc0[0]*_hc0[1]*_hc1[2]*_hc1[5]*_hc2[0]*_t2 + 0.6e1*_hc0[0]*_hc0[1]*_hc2[1]*_t2*_t37 + 0.2e1*_hc0[0]*_hc0[1]*_hc2[3]*_t2 + 0.2e1*_hc0[0]*_hc0[13]*_hc2[0]*_t2 + 0.12e2*_hc0[0]*_hc0[2]*_hc1[1]*_hc1[2]*_hc2[1]*_t2 + 0.6e1*_hc0[0]*_hc0[2]*_hc1[1]*_hc1[5]*_hc2[0]*_t2 + 0.12e2*_hc0[0]*_hc0[2]*_hc1[2]*_hc1[4]*_hc2[0]*_t2 + 0.6e1*_hc0[0]*_hc0[4]*_hc2[0]*_t2*_t37 + 0.6e1*_hc0[0]*_hc0[4]*_hc2[2]*_t2 + 0.6e1*_hc0[0]*_hc0[5]*_hc1[1]*_hc1[2]*_hc2[0]*_t2 + 0.6e1*_hc0[0]*_hc0[8]*_hc2[1]*_t2 + 0.6e1*_hc0[1]*_hc0[2]*_hc2[0]*_t2*_t37 + 0.6e1*_hc0[1]*_hc0[2]*_hc2[2]*_t2 - _hc0[1]*_hc0[5]*_hc1[2]*_t40 + 0.6e1*_hc0[1]*_hc0[5]*_hc2[1]*_t2 + 0.2e1*_hc0[1]*_hc0[9]*_hc2[0]*_t2 - _hc0[1]*_hc1[2]*_t53 - _hc0[1]*_hc1[5]*_t55 + 0.12e2*_hc0[2]*_hc0[4]*_hc2[1]*_t2 + 0.6e1*_hc0[2]*_hc0[8]*_hc2[0]*_t2 - _hc0[2]*_t72*_t83 + 0.6e1*_hc0[4]*_hc0[5]*_hc2[0]*_t2 - _hc0[8]*_t79 + 0.6e1*_hc1[1]*_hc1[2]*_hc2[0]*_t2*_t31 + 0.3e1*_hc1[1]*_hc1[2]*_hc2[2]*_t1*_t2 + 0.3e1*_hc1[1]*_hc1[5]*_hc2[1]*_t1*_t2 + _hc1[1]*_hc1[9]*_hc2[0]*_t1*_t2 + _hc1[1]*_hc2[0]*_t1*_t2*_t68 - _hc1[1]*_t50 - _hc1[1]*_t54 - _hc1[1]*_t56 - _hc1[1]*_t57 - _hc1[1]*_t59 - _hc1[1]*_t61 - _hc1[13]*_t4 + 0.6e1*_hc1[2]*_hc1[4]*_hc2[1]*_t1*_t2 + 0.3e1*_hc1[2]*_hc1[8]*_hc2[0]*_t1*_t2 + 0.3e1*_hc1[4]*_hc1[5]*_hc2[0]*_t1*_t2 - _hc1[4]*_t62 - _hc1[4]*_t64 - _hc1[4]*_t66 - _hc1[5]*_t75 - _hc1[5]*_t76 - _hc1[8]*_t63 - _hc1[8]*_t65 - _hc1[9]*_t23 - 0.12e2*_t22*_t83 - _t23*_t68 - _t24*_t88 - _t25*_t88 - _t26*_t67 - _t37*_t46*_t58 - _t78*_t86 - _t82*_t87;
  out[13] = d4f_drs3_dxt;
  const double d4f_drs4 = _hc0[0]*_hc2[3]*_t2*_t84 + _hc0[14]*_t9 + ((_hc0[5]) * (_hc0[5]))*_t40 - _hc0[5]*_t22*_t95 + 0.12e2*_hc0[5]*_t52 - _hc0[9]*_t33*_t81 + _hc0[9]*_t80 + _hc0[9]*_t85 - _hc1[14]*_t4 + ((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]))*_t4 - _hc1[2]*_t31*_t89 - 0.4e1*_hc1[2]*_t50 - _hc1[2]*_t52*_t92 + ((_hc1[5]) * (_hc1[5]))*_t74 + _hc1[5]*_t33*_t7*_t92 - 0.6e1*_hc1[5]*_t38 + _hc1[5]*_t6*_t87 - _hc1[5]*_t93 - _hc1[5]*_t96 - _hc1[5]*_t97 - _hc1[5]*_t99 + 0.4e1*_hc1[9]*_t11 - _hc1[9]*_t94 - _hc1[9]*_t98 + _hc2[4]*_t3 + _t37*_t93 + _t37*_t96 + _t37*_t97 + _t37*_t99 + _t51*_t91 - _t68*_t94 - _t68*_t98 - _t7*_t90*_t95 + _t89*_t90;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_p86_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double xs0, double xs1, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pz_zeta0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(p86_H_z0_k, _KMAX)(p, rs, xt, _hc1);

  const double f = _hc0[0] + _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dxs1 = 0;
  out[1] = df_dxs1;
  const double df_dxs0 = 0;
  out[2] = df_dxs0;
  const double df_dxt = _hc1[1];
  out[3] = df_dxt;
  const double df_drs = _hc0[1] + _hc1[2];
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxs12 = 0;
  out[5] = d2f_dxs12;
  const double d2f_dxs0_dxs1 = 0;
  out[6] = d2f_dxs0_dxs1;
  const double d2f_dxs02 = 0;
  out[7] = d2f_dxs02;
  const double d2f_dxt_dxs1 = 0;
  out[8] = d2f_dxt_dxs1;
  const double d2f_dxt_dxs0 = 0;
  out[9] = d2f_dxt_dxs0;
  const double d2f_dxt2 = _hc1[3];
  out[10] = d2f_dxt2;
  const double d2f_drs_dxs1 = 0;
  out[11] = d2f_drs_dxs1;
  const double d2f_drs_dxs0 = 0;
  out[12] = d2f_drs_dxs0;
  const double d2f_drs_dxt = _hc1[4];
  out[13] = d2f_drs_dxt;
  const double d2f_drs2 = _hc0[2] + _hc1[5];
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxs13 = 0;
  out[15] = d3f_dxs13;
  const double d3f_dxs0_dxs12 = 0;
  out[16] = d3f_dxs0_dxs12;
  const double d3f_dxs02_dxs1 = 0;
  out[17] = d3f_dxs02_dxs1;
  const double d3f_dxs03 = 0;
  out[18] = d3f_dxs03;
  const double d3f_dxt_dxs12 = 0;
  out[19] = d3f_dxt_dxs12;
  const double d3f_dxt_dxs0_dxs1 = 0;
  out[20] = d3f_dxt_dxs0_dxs1;
  const double d3f_dxt_dxs02 = 0;
  out[21] = d3f_dxt_dxs02;
  const double d3f_dxt2_dxs1 = 0;
  out[22] = d3f_dxt2_dxs1;
  const double d3f_dxt2_dxs0 = 0;
  out[23] = d3f_dxt2_dxs0;
  const double d3f_dxt3 = _hc1[6];
  out[24] = d3f_dxt3;
  const double d3f_drs_dxs12 = 0;
  out[25] = d3f_drs_dxs12;
  const double d3f_drs_dxs0_dxs1 = 0;
  out[26] = d3f_drs_dxs0_dxs1;
  const double d3f_drs_dxs02 = 0;
  out[27] = d3f_drs_dxs02;
  const double d3f_drs_dxt_dxs1 = 0;
  out[28] = d3f_drs_dxt_dxs1;
  const double d3f_drs_dxt_dxs0 = 0;
  out[29] = d3f_drs_dxt_dxs0;
  const double d3f_drs_dxt2 = _hc1[7];
  out[30] = d3f_drs_dxt2;
  const double d3f_drs2_dxs1 = 0;
  out[31] = d3f_drs2_dxs1;
  const double d3f_drs2_dxs0 = 0;
  out[32] = d3f_drs2_dxs0;
  const double d3f_drs2_dxt = _hc1[8];
  out[33] = d3f_drs2_dxt;
  const double d3f_drs3 = _hc0[3] + _hc1[9];
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dxs14 = 0;
  out[35] = d4f_dxs14;
  const double d4f_dxs0_dxs13 = 0;
  out[36] = d4f_dxs0_dxs13;
  const double d4f_dxs02_dxs12 = 0;
  out[37] = d4f_dxs02_dxs12;
  const double d4f_dxs03_dxs1 = 0;
  out[38] = d4f_dxs03_dxs1;
  const double d4f_dxs04 = 0;
  out[39] = d4f_dxs04;
  const double d4f_dxt_dxs13 = 0;
  out[40] = d4f_dxt_dxs13;
  const double d4f_dxt_dxs0_dxs12 = 0;
  out[41] = d4f_dxt_dxs0_dxs12;
  const double d4f_dxt_dxs02_dxs1 = 0;
  out[42] = d4f_dxt_dxs02_dxs1;
  const double d4f_dxt_dxs03 = 0;
  out[43] = d4f_dxt_dxs03;
  const double d4f_dxt2_dxs12 = 0;
  out[44] = d4f_dxt2_dxs12;
  const double d4f_dxt2_dxs0_dxs1 = 0;
  out[45] = d4f_dxt2_dxs0_dxs1;
  const double d4f_dxt2_dxs02 = 0;
  out[46] = d4f_dxt2_dxs02;
  const double d4f_dxt3_dxs1 = 0;
  out[47] = d4f_dxt3_dxs1;
  const double d4f_dxt3_dxs0 = 0;
  out[48] = d4f_dxt3_dxs0;
  const double d4f_dxt4 = _hc1[10];
  out[49] = d4f_dxt4;
  const double d4f_drs_dxs13 = 0;
  out[50] = d4f_drs_dxs13;
  const double d4f_drs_dxs0_dxs12 = 0;
  out[51] = d4f_drs_dxs0_dxs12;
  const double d4f_drs_dxs02_dxs1 = 0;
  out[52] = d4f_drs_dxs02_dxs1;
  const double d4f_drs_dxs03 = 0;
  out[53] = d4f_drs_dxs03;
  const double d4f_drs_dxt_dxs12 = 0;
  out[54] = d4f_drs_dxt_dxs12;
  const double d4f_drs_dxt_dxs0_dxs1 = 0;
  out[55] = d4f_drs_dxt_dxs0_dxs1;
  const double d4f_drs_dxt_dxs02 = 0;
  out[56] = d4f_drs_dxt_dxs02;
  const double d4f_drs_dxt2_dxs1 = 0;
  out[57] = d4f_drs_dxt2_dxs1;
  const double d4f_drs_dxt2_dxs0 = 0;
  out[58] = d4f_drs_dxt2_dxs0;
  const double d4f_drs_dxt3 = _hc1[11];
  out[59] = d4f_drs_dxt3;
  const double d4f_drs2_dxs12 = 0;
  out[60] = d4f_drs2_dxs12;
  const double d4f_drs2_dxs0_dxs1 = 0;
  out[61] = d4f_drs2_dxs0_dxs1;
  const double d4f_drs2_dxs02 = 0;
  out[62] = d4f_drs2_dxs02;
  const double d4f_drs2_dxt_dxs1 = 0;
  out[63] = d4f_drs2_dxt_dxs1;
  const double d4f_drs2_dxt_dxs0 = 0;
  out[64] = d4f_drs2_dxt_dxs0;
  const double d4f_drs2_dxt2 = _hc1[12];
  out[65] = d4f_drs2_dxt2;
  const double d4f_drs3_dxs1 = 0;
  out[66] = d4f_drs3_dxs1;
  const double d4f_drs3_dxs0 = 0;
  out[67] = d4f_drs3_dxs0;
  const double d4f_drs3_dxt = _hc1[13];
  out[68] = d4f_drs3_dxt;
  const double d4f_drs4 = _hc0[4] + _hc1[14];
  out[69] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_c_p86_params *params = (const gga_c_p86_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = (0.1e1 / 0.2e1)/xc_powr(na, 1, 3);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = xc_powr(gaa, 1, 2);
  const double _t6 = xc_powr(na, -4, 3);
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(f_p86_z0_k, _KMAX)(p, _t1*_t4, _t5*_t6, 0, 0, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t7 = xc_powr(na, -7, 3);
  const double _t8 = _t5*_t7;
  const double _t9 = (0.4e1 / 0.3e1)*_t8;
  const double _t11 = (0.1e1 / 0.6e1)*_t6;
  const double _t12 = (0.1e1 / _t5);
  const double _t10 = _hc0[4]*_t4;
  const double _t13 = _hc0[3]*_t12;
  const double dF_dna = _hc0[0] + na*(-_hc0[3]*_t9 - _t10*_t11);
  const double dF_dgaa = _t1*_t13;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t14 = (0.8e1 / 0.3e1)*_t8;
  const double _t15 = (0.1e1 / 0.3e1)*_t6;
  const double _t17 = xc_powr(na, -10, 3);
  const double _t18 = (0.28e2 / 0.9e1)*_t17;
  const double _t19 = (0.2e1 / 0.9e1)*_t7;
  const double _t21 = _t11*_t4;
  const double _t24 = (0.1e1 / 0.2e1)*_t6;
  const double _t25 = xc_powr(na, -11, 3);
  const double _t26 = (0.2e1 / 0.3e1)*_t25;
  const double _t28 = (0.2e1 / 0.3e1)*_t7;
  const double _t29 = _t12*_t4;
  const double _t31 = xc_powr(na, -8, 3);
  const double _t32 = (0.1e1 / 0.12e2)*_t31;
  const double _t33 = (0.1e1 / gaa);
  const double _t34 = (0.1e1 / 0.4e1)*_t31;
  const double _t35 = xc_powr(gaa, -3, 2);
  const double _t37 = (0.1e1 / 0.4e1)*_t6;
  const double _t16 = _hc0[3]*_t5;
  const double _t20 = (0.4e1 / 0.3e1)*_hc0[10];
  const double _t22 = -_hc0[13]*_t21 - _t20*_t8;
  const double _t23 = -_hc0[13]*_t9 - _hc0[14]*_t21;
  const double _t27 = _hc0[10]*_t26;
  const double _t30 = _hc0[13]*_t29;
  const double _t36 = _hc0[3]*_t35;
  const double _t38 = _hc0[10]*_t33*_t34 - _t36*_t37;
  const double d2F_dna2 = -_hc0[3]*_t14 - _t10*_t15 + na*(_t10*_t19 + _t16*_t18 - _t21*_t23 - _t22*_t9);
  const double d2F_dna_dgaa = _t13*_t24 + na*(-_t13*_t28 - _t27 - _t30*_t32);
  const double d2F_dgaa2 = _t38*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t39 = (0.28e2 / 0.3e1)*_t17;
  const double _t40 = 0.4e1*_t8;
  const double _t42 = xc_powr(na, -13, 3);
  const double _t43 = (0.280e3 / 0.27e2)*_t42;
  const double _t44 = (0.14e2 / 0.27e2)*_t17;
  const double _t45 = _t18*_t5;
  const double _t46 = _t19*_t4;
  const double _t53 = (0.4e1 / 0.3e1)*_t7;
  const double _t54 = xc_powr(na, -14, 3);
  const double _t55 = (0.14e2 / 0.9e1)*_t54;
  const double _t57 = (0.14e2 / 0.9e1)*_t17;
  const double _t58 = (0.1e1 / 0.9e1)*_t25;
  const double _t59 = _t12*_t28;
  const double _t61 = _t29*_t32;
  const double _t65 = _t35*_t37;
  const double _t68 = (0.1e1 / (gaa * gaa));
  const double _t69 = xc_powr(gaa, -5, 2);
  const double _t71 = (0.3e1 / 0.8e1)*_t6;
  const double _t41 = _t23*_t4;
  const double _t47 = -_hc0[24]*_t9 - _hc0[30]*_t21;
  const double _t48 = -_hc0[30]*_t9 - _hc0[33]*_t21;
  const double _t49 = _hc0[10]*_t45 + _hc0[13]*_t46 - _t21*_t48 - _t47*_t9;
  const double _t50 = -_hc0[33]*_t9 - _hc0[34]*_t21;
  const double _t51 = _hc0[13]*_t45 + _hc0[14]*_t46 - _t21*_t50 - _t48*_t9;
  const double _t52 = _t20*_t25;
  const double _t56 = _hc0[10]*_t55;
  const double _t60 = _hc0[24]*_t26;
  const double _t62 = -_hc0[10]*_t59 - _hc0[30]*_t61 - _t60;
  const double _t63 = _hc0[30]*_t26;
  const double _t64 = -_hc0[13]*_t59 - _hc0[33]*_t61 - _t63;
  const double _t66 = -_hc0[10]*_t65 + (0.1e1 / 0.4e1)*_hc0[24]*_t31*_t33;
  const double _t67 = -_hc0[13]*_t65 + (0.1e1 / 0.4e1)*_hc0[30]*_t31*_t33;
  const double _t70 = _hc0[3]*_t69;
  const double _t72 = _t12*_t66;
  const double _t73 = -_hc0[10]*_t34*_t68 + _t24*_t72 + _t70*_t71;
  const double d3F_dna3 = _t10*_t28 + _t16*_t39 - _t22*_t40 - _t24*_t41 + na*(-_t10*_t44 - _t16*_t43 + (0.56e2 / 0.9e1)*_t17*_t22*_t5 + (0.4e1 / 0.9e1)*_t2*_t23*_t3*_t7 - _t21*_t51 - _t49*_t9);
  const double d3F_dna2_dgaa = -_t13*_t53 - 0.1e1 / 0.6e1*_t30*_t31 - _t52 + na*(_t13*_t57 - _t21*_t64 - _t22*_t59 + _t30*_t58 + _t56 - _t62*_t9);
  const double d3F_dna_dgaa2 = _t38 + na*((0.1e1 / 0.3e1)*_hc0[3]*_t35*_t7 - _t21*_t67 - _t27*_t33 - _t66*_t9);
  const double d3F_dgaa3 = _t73*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double _t75 = _t43*_t5;
  const double _t76 = _t4*_t44;
  const double _t80 = 0.2e1*_t7;
  const double _t81 = _t12*_t57;
  const double _t82 = _t29*_t58;
  const double _t86 = _t69*_t71;
  const double _t87 = _t34*_t68;
  const double _t88 = _t12*_t24;
  const double _t74 = _t4*_t51;
  const double _t77 = -_hc0[59]*_t9 - _hc0[65]*_t21;
  const double _t78 = -_hc0[65]*_t9 - _hc0[68]*_t21;
  const double _t79 = _hc0[30]*_t45 + _hc0[33]*_t46 - _t21*_t78 - _t77*_t9;
  const double _t83 = -_hc0[30]*_t59 - _hc0[59]*_t26 - _hc0[65]*_t61;
  const double _t84 = -_hc0[24]*_t65 + (0.1e1 / 0.4e1)*_hc0[49]*_t31*_t33;
  const double _t85 = -_hc0[30]*_t65 + (0.1e1 / 0.4e1)*_hc0[59]*_t31*_t33;
  const double _t89 = _hc0[10]*_t86 - _hc0[24]*_t87 + _t84*_t88;
  const double d4F_dna4 = -0.56e2 / 0.27e2*_t10*_t17 - 0.1120e4 / 0.27e2*_t16*_t42 + (0.224e3 / 0.9e1)*_t17*_t22*_t5 + (0.16e2 / 0.9e1)*_t2*_t23*_t3*_t7 - 0.16e2 / 0.3e1*_t49*_t8 - 0.2e1 / 0.3e1*_t6*_t74 + na*((0.140e3 / 0.81e2)*_t10*_t42 + (0.3640e4 / 0.81e2)*_t16/xc_powr(na, 16, 3) - _t21*(-_hc0[13]*_t75 - _hc0[14]*_t76 + (0.56e2 / 0.9e1)*_t17*_t48*_t5 + (0.4e1 / 0.9e1)*_t2*_t3*_t50*_t7 - _t21*(_hc0[33]*_t45 + _hc0[34]*_t46 - _t21*(-_hc0[68]*_t9 - _hc0[69]*_t21) - _t78*_t9) - _t79*_t9) - 0.280e3 / 0.9e1*_t22*_t42*_t5 + _t28*_t74 + _t39*_t49*_t5 - _t41*_t57 - _t9*(-_hc0[10]*_t75 - _hc0[13]*_t76 + (0.56e2 / 0.9e1)*_t17*_t47*_t5 + (0.4e1 / 0.9e1)*_t2*_t3*_t48*_t7 - _t21*_t79 - _t9*(_hc0[24]*_t45 + _hc0[30]*_t46 - _t21*_t77 - _t9*(-_hc0[49]*_t9 - _hc0[59]*_t21))));
  const double d4F_dna3_dgaa = (0.14e2 / 0.3e1)*_hc0[10]*_t54 - _t12*_t22*_t80 + (0.14e2 / 0.3e1)*_t13*_t17 - _t24*_t4*_t64 + (0.1e1 / 0.3e1)*_t25*_t30 - _t40*_t62 + na*(-0.140e3 / 0.27e2*_hc0[10]/xc_powr(na, 17, 3) + (0.28e2 / 0.9e1)*_t12*_t17*_t22 - 0.140e3 / 0.27e2*_t13*_t42 + (0.56e2 / 0.9e1)*_t17*_t5*_t62 + (0.4e1 / 0.9e1)*_t2*_t3*_t64*_t7 - _t21*(_hc0[13]*_t81 + _hc0[30]*_t55 + _hc0[33]*_t82 - _t21*(-_hc0[33]*_t59 - _hc0[65]*_t26 - _hc0[68]*_t61) - _t48*_t59 - _t83*_t9) - 0.7e1 / 0.27e2*_t30*_t54 - _t49*_t59 - _t9*(_hc0[10]*_t81 + _hc0[24]*_t55 + _hc0[30]*_t82 - _t21*_t83 - _t47*_t59 - _t9*(-_hc0[24]*_t59 - _hc0[49]*_t26 - _hc0[59]*_t61)));
  const double d4F_dna2_dgaa2 = (0.2e1 / 0.3e1)*_hc0[3]*_t35*_t7 - _t14*_t66 - _t15*_t4*_t67 - _t33*_t52 + na*(-_t12*_t53*_t62 - 0.7e1 / 0.9e1*_t17*_t36 - _t21*((0.1e1 / 0.3e1)*_hc0[13]*_t35*_t7 - _t21*(-_hc0[33]*_t65 + (0.1e1 / 0.4e1)*_hc0[65]*_t31*_t33) - _t33*_t63 - _t85*_t9) + (0.1e1 / 0.3e1)*_t22*_t35*_t7 + _t33*_t56 + _t45*_t66 + _t46*_t67 - _t9*((0.1e1 / 0.3e1)*_hc0[10]*_t35*_t7 - _t21*_t85 - _t33*_t60 - _t84*_t9));
  const double d4F_dna_dgaa3 = _t73 + na*((0.1e1 / 0.2e1)*_hc0[10]*_t25*_t68 - _t21*(_hc0[13]*_t86 - _hc0[30]*_t87 + _t85*_t88) - 0.1e1 / 0.2e1*_t7*_t70 - _t72*_t80 - _t89*_t9);
  const double d4F_dgaa4 = na*((0.9e1 / 0.16e2)*_hc0[10]*_t31/(gaa * gaa * gaa) - 0.15e2 / 0.16e2*_hc0[3]*_t6/xc_powr(gaa, 7, 2) - 0.3e1 / 0.4e1*_t35*_t6*_t66 + _t88*_t89);
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
  double _hc0[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_p86_k, _KMAX)(p, _t2*_t6, _t7*_t8, _t11*_t9, 0, 0, _hc0);
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
  const double _t16 = _hc0[3]*_t15;
  const double _t18 = _hc0[5]*_t5;
  const double _t20 = _t16*_t17 + _t18*_t19;
  const double _t23 = _hc0[3]*_t22;
  const double _t24 = _t2*_t23;
  const double _t25 = (0.1e1 / 0.2e1)*_t24;
  const double dF_dna = _hc0[0] + _t1*(_hc0[4]*_t14 - _t20);
  const double dF_dnb = _hc0[0] + _t1*(_hc0[4]*_t21 - _t20);
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
  const double _t83 = (0.1e1 / _t10);
  const double _t86 = xc_powr(_t10, -3, 2);
  const double _t92 = xc_powr(_t1, -5, 3);
  const double _t26 = _hc0[3]*_t11;
  const double _t30 = _t18*_t29 + _t26*_t28;
  const double _t36 = _hc0[4]*_t35;
  const double _t39 = _hc0[14]*_t37 + _hc0[19]*_t38;
  const double _t40 = _hc0[15]*_t14 - _t39;
  const double _t41 = _t14*_t40;
  const double _t42 = _hc0[11]*_t37 + _hc0[18]*_t38;
  const double _t43 = _hc0[14]*_t14 - _t42;
  const double _t44 = _hc0[18]*_t37 + _hc0[20]*_t38;
  const double _t45 = _hc0[19]*_t14 - _t44;
  const double _t46 = _t36 - _t37*_t43 - _t38*_t45 + _t41;
  const double _t48 = _t16*_t47;
  const double _t50 = _t18*_t49;
  const double _t51 = _t48 + _t50;
  const double _t52 = _hc0[15]*_t21 - _t39;
  const double _t53 = _t14*_t52;
  const double _t54 = _hc0[14]*_t21 - _t42;
  const double _t55 = _hc0[19]*_t21 - _t44;
  const double _t56 = _t30 - _t37*_t54 - _t38*_t55;
  const double _t58 = _hc0[4]*_t57;
  const double _t59 = _t21*_t52;
  const double _t60 = _t58 + _t59;
  const double _t61 = _t23*_t9;
  const double _t62 = (0.1e1 / 0.2e1)*_t61;
  const double _t63 = -0.1e1 / 0.2e1*_hc0[14]*_t14*_t22*_t9;
  const double _t65 = _hc0[11]*_t64;
  const double _t66 = (0.2e1 / 0.3e1)*_t65;
  const double _t67 = _t15*_t23;
  const double _t70 = _hc0[18]*_t69;
  const double _t71 = _t22*_t70;
  const double _t72 = _t66 + (0.2e1 / 0.3e1)*_t67 + _t68*_t71;
  const double _t73 = _t1*(-_t63 - _t72) + _t62;
  const double _t74 = -_hc0[14]*_t14*_t22*_t9;
  const double _t75 = (0.4e1 / 0.3e1)*_t65;
  const double _t77 = (0.4e1 / 0.3e1)*_t67 + _t71*_t76 + _t75;
  const double _t78 = _t74 + _t77;
  const double _t79 = -0.1e1 / 0.2e1*_hc0[14]*_t21*_t22*_t9;
  const double _t80 = _t1*(-_t72 - _t79) + _t62;
  const double _t81 = -_hc0[14]*_t21*_t22*_t9;
  const double _t82 = _t77 + _t81;
  const double _t84 = _hc0[11]*_t83;
  const double _t85 = _t69*_t84;
  const double _t87 = _hc0[3]*_t86;
  const double _t88 = _t87*_t9;
  const double _t89 = (0.1e1 / 0.4e1)*_t85 - 0.1e1 / 0.4e1*_t88;
  const double _t90 = _t1*_t89;
  const double _t91 = (0.1e1 / 0.2e1)*_t85 - 0.1e1 / 0.2e1*_t88;
  const double _t93 = _t84*_t92;
  const double _t94 = _t2*_t87;
  const double d2F_dna2 = 0.2e1*_hc0[4]*_t14 + _t1*(_t30 + _t46) - _t51;
  const double d2F_dna_dnb = _hc0[4]*_t14 + _hc0[4]*_t21 + _t1*(_hc0[4]*_t34 + _t53 + _t56) - _t48 - _t50;
  const double d2F_dnb2 = 0.2e1*_hc0[4]*_t21 + _t1*(_t56 + _t60) - _t51;
  const double d2F_dna_dgaa = _t73;
  const double d2F_dna_dgab = -_t1*_t78 + _t61;
  const double d2F_dna_dgbb = _t73;
  const double d2F_dnb_dgaa = _t80;
  const double d2F_dnb_dgab = -_t1*_t82 + _t61;
  const double d2F_dnb_dgbb = _t80;
  const double d2F_dgaa2 = _t90;
  const double d2F_dgaa_dgab = _t1*_t91;
  const double d2F_dgaa_dgbb = _t90;
  const double d2F_dgab2 = _t93 - _t94;
  const double d2F_dgab_dgbb = (0.1e1 / 0.2e1)*_t93 - 0.1e1 / 0.2e1*_t94;
  const double d2F_dgbb2 = _t90;
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
  const double _t95 = xc_powr(_t1, -13, 3);
  const double _t96 = (0.280e3 / 0.27e2)*_t95;
  const double _t98 = (0.14e2 / 0.27e2)*_t27;
  const double _t102 = (0.56e2 / 0.9e1)*_t27;
  const double _t104 = (0.4e1 / 0.9e1)*_t15;
  const double _t106 = 0.6e1*_t32;
  const double _t107 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t108 = _t107*_t7;
  const double _t109 = 0.6e1*_t108;
  const double _t110 = _t106 - _t109;
  const double _t118 = _t11*_t28;
  const double _t119 = _t29*_t5;
  const double _t123 = 0.2e1*_t35;
  const double _t136 = 0.4e1*_t15;
  const double _t137 = _t6*_t9;
  const double _t138 = (0.28e2 / 0.3e1)*_t27;
  const double _t139 = (0.2e1 / 0.3e1)*_t15;
  const double _t141 = -_t109 + 0.2e1*_t32;
  const double _t159 = 0.4e1*_t32;
  const double _t170 = -_t106 - _t109;
  const double _t175 = xc_powr(_t1, -14, 3);
  const double _t177 = (0.14e2 / 0.9e1)*_t27;
  const double _t178 = (0.1e1 / 0.9e1)*_t5;
  const double _t182 = (0.2e1 / 0.3e1)*_t64;
  const double _t185 = _t22*_t69;
  const double _t186 = _t185*_t68;
  const double _t191 = _t139*_t22;
  const double _t194 = _t22*_t9;
  const double _t203 = (0.4e1 / 0.3e1)*_t64;
  const double _t205 = (0.4e1 / 0.3e1)*_t15;
  const double _t206 = _t185*_t76;
  const double _t211 = _t205*_t22;
  const double _t219 = (0.1e1 / 0.3e1)*_t5;
  const double _t244 = _t86*_t9;
  const double _t245 = (0.1e1 / 0.4e1)*_t244;
  const double _t252 = (0.1e1 / 0.2e1)*_t244;
  const double _t264 = xc_powi(_t1, -5);
  const double _t267 = _t107*_t83;
  const double _t280 = (0.1e1 / (_t10 * _t10));
  const double _t282 = (0.1e1 / 0.4e1)*_t69;
  const double _t283 = xc_powr(_t10, -5, 2);
  const double _t290 = (0.1e1 / 0.2e1)*_t194;
  const double _t97 = _t26*_t96;
  const double _t99 = _t18*_t98;
  const double _t100 = -_t97 - _t99;
  const double _t101 = _t11*_t43;
  const double _t103 = _t45*_t5;
  const double _t105 = _t101*_t102 + _t103*_t104;
  const double _t111 = _hc0[4]*_t110;
  const double _t112 = _hc0[39]*_t37 + _hc0[50]*_t38;
  const double _t113 = _hc0[40]*_t14 - _t112;
  const double _t114 = _hc0[36]*_t37 + _hc0[49]*_t38;
  const double _t115 = _hc0[39]*_t14 - _t114;
  const double _t116 = _hc0[49]*_t37 + _hc0[54]*_t38;
  const double _t117 = _hc0[50]*_t14 - _t116;
  const double _t120 = _hc0[14]*_t118 + _hc0[19]*_t119;
  const double _t121 = _hc0[15]*_t35 + _t113*_t14 - _t115*_t37 - _t117*_t38 + _t120;
  const double _t122 = _t121*_t14;
  const double _t124 = _hc0[14]*_t35;
  const double _t125 = _hc0[30]*_t37 + _hc0[46]*_t38;
  const double _t126 = _hc0[36]*_t14 - _t125;
  const double _t127 = _hc0[46]*_t37 + _hc0[53]*_t38;
  const double _t128 = _hc0[49]*_t14 - _t127;
  const double _t129 = _hc0[11]*_t118 + _hc0[18]*_t119;
  const double _t130 = _t115*_t14 + _t124 - _t126*_t37 - _t128*_t38 + _t129;
  const double _t131 = _hc0[53]*_t37 + _hc0[55]*_t38;
  const double _t132 = _hc0[54]*_t14 - _t131;
  const double _t133 = _hc0[18]*_t118 + _hc0[20]*_t119;
  const double _t134 = _hc0[19]*_t35 + _t117*_t14 - _t128*_t37 - _t132*_t38 + _t133;
  const double _t135 = _t111 + _t122 + _t123*_t40 - _t130*_t37 - _t134*_t38;
  const double _t140 = _t138*_t26 + _t139*_t18;
  const double _t142 = _hc0[4]*_t141;
  const double _t143 = _hc0[40]*_t21 - _t112;
  const double _t144 = _hc0[39]*_t21 - _t114;
  const double _t145 = _hc0[50]*_t21 - _t116;
  const double _t146 = _t120 - _t144*_t37 - _t145*_t38;
  const double _t147 = _hc0[15]*_t34 + _t14*_t143 + _t146;
  const double _t148 = _t14*_t147;
  const double _t149 = _t35*_t52;
  const double _t150 = _hc0[36]*_t21 - _t125;
  const double _t151 = _hc0[49]*_t21 - _t127;
  const double _t152 = _t129 - _t150*_t37 - _t151*_t38;
  const double _t153 = _hc0[14]*_t34 + _t14*_t144 + _t152;
  const double _t154 = _hc0[54]*_t21 - _t131;
  const double _t155 = _t133 - _t151*_t37 - _t154*_t38;
  const double _t156 = _hc0[19]*_t34 + _t14*_t145 + _t155;
  const double _t157 = _t15*_t54;
  const double _t158 = _t5*_t55;
  const double _t160 = _hc0[4]*_t159;
  const double _t161 = _t160*_t7 + 0.2e1*_t53;
  const double _t162 = _hc0[19]*_t57 + _t145*_t21 + _t155;
  const double _t163 = _t162*_t38;
  const double _t164 = _hc0[14]*_t57;
  const double _t165 = _t144*_t21 + _t152 + _t164;
  const double _t166 = _t165*_t37;
  const double _t167 = _hc0[15]*_t57 + _t143*_t21 + _t146;
  const double _t168 = _t11*_t54;
  const double _t169 = -_t136*_t168 - _t137*_t55 + _t140;
  const double _t171 = _hc0[4]*_t170;
  const double _t172 = _t167*_t21;
  const double _t173 = 0.2e1*_t52;
  const double _t174 = _t171 + _t172 + _t173*_t57;
  const double _t176 = _hc0[11]*_t175;
  const double _t179 = _hc0[18]*_t22;
  const double _t180 = _t179*_t64;
  const double _t181 = (0.14e2 / 0.9e1)*_t176 + _t177*_t23 + _t178*_t180;
  const double _t183 = _hc0[36]*_t182;
  const double _t184 = _hc0[14]*_t22;
  const double _t187 = _hc0[49]*_t186 + _t139*_t184 + _t183;
  const double _t188 = (0.1e1 / 0.2e1)*_hc0[39]*_t14*_t22*_t9 - _t187;
  const double _t189 = _t14*_t188;
  const double _t190 = _hc0[30]*_t182;
  const double _t192 = _hc0[11]*_t191 + _hc0[46]*_t186 + _t190;
  const double _t193 = (0.1e1 / 0.2e1)*_hc0[36]*_t14*_t22*_t9 - _t192;
  const double _t195 = _t124*_t194;
  const double _t196 = _hc0[46]*_t182;
  const double _t197 = _hc0[18]*_t191 + _hc0[53]*_t186 + _t196;
  const double _t198 = (0.1e1 / 0.2e1)*_hc0[49]*_t14*_t22*_t9 - _t197;
  const double _t199 = _t189 - _t191*_t43 - _t193*_t37 + (0.1e1 / 0.2e1)*_t195 - _t198*_t38;
  const double _t200 = _t1*(_t181 + _t199) - _t78;
  const double _t201 = _t180*_t5;
  const double _t202 = (0.28e2 / 0.9e1)*_t176 + (0.2e1 / 0.9e1)*_t201 + _t23*_t28;
  const double _t204 = _hc0[36]*_t203;
  const double _t207 = _hc0[49]*_t206 + _t184*_t205 + _t204;
  const double _t208 = _hc0[39]*_t14*_t22*_t9 - _t207;
  const double _t209 = _t14*_t208;
  const double _t210 = _hc0[30]*_t203;
  const double _t212 = _hc0[11]*_t211 + _hc0[46]*_t206 + _t210;
  const double _t213 = _hc0[36]*_t14*_t22*_t9 - _t212;
  const double _t214 = _hc0[46]*_t203;
  const double _t215 = _hc0[18]*_t211 + _hc0[53]*_t206 + _t214;
  const double _t216 = _hc0[49]*_t14*_t22*_t9 - _t215;
  const double _t217 = _t195 + _t209 - _t211*_t43 - _t213*_t37 - _t216*_t38;
  const double _t218 = (0.8e1 / 0.3e1)*_t65;
  const double _t220 = _t218 + _t219*_t71 + (0.8e1 / 0.3e1)*_t67;
  const double _t221 = (0.1e1 / 0.2e1)*_hc0[39]*_t21*_t22*_t9 - _t187;
  const double _t222 = _t14*_t221;
  const double _t223 = _t184*_t95;
  const double _t224 = _t223*_t7;
  const double _t225 = (0.1e1 / 0.2e1)*_hc0[36]*_t21*_t22*_t9 - _t192;
  const double _t226 = _t157*_t22;
  const double _t227 = (0.1e1 / 0.2e1)*_hc0[49]*_t21*_t22*_t9 - _t197;
  const double _t228 = _t181 - _t225*_t37 - 0.2e1 / 0.3e1*_t226 - _t227*_t38;
  const double _t229 = _t1*(_t222 + _t224 + _t228) - _t63 - _t77 - _t79;
  const double _t230 = _hc0[39]*_t21*_t22*_t9 - _t207;
  const double _t231 = _t14*_t230;
  const double _t232 = -0.4e1 / 0.3e1*_t226;
  const double _t233 = 0.2e1*_t224;
  const double _t234 = _t232 + _t233;
  const double _t235 = _hc0[36]*_t21*_t22*_t9 - _t212;
  const double _t236 = _hc0[49]*_t21*_t22*_t9 - _t215;
  const double _t237 = _t202 - _t235*_t37 - _t236*_t38;
  const double _t238 = _t21*_t221;
  const double _t239 = _t164*_t194;
  const double _t240 = _t238 + (0.1e1 / 0.2e1)*_t239;
  const double _t241 = _t1*(_t228 + _t240) - _t82;
  const double _t242 = _t21*_t230;
  const double _t243 = _t239 + _t242;
  const double _t246 = -_hc0[14]*_t245 + (0.1e1 / 0.4e1)*_hc0[36]*_t69*_t83;
  const double _t247 = _t66*_t83;
  const double _t248 = -_hc0[11]*_t245 + (0.1e1 / 0.4e1)*_hc0[30]*_t69*_t83;
  const double _t249 = -_hc0[18]*_t245 + (0.1e1 / 0.4e1)*_hc0[46]*_t69*_t83;
  const double _t250 = -0.1e1 / 0.3e1*_hc0[3]*_t15*_t86 + _t247 + _t248*_t37 + _t249*_t38;
  const double _t251 = _t1*(_t14*_t246 - _t250) + _t89;
  const double _t253 = -_hc0[14]*_t252 + (0.1e1 / 0.2e1)*_hc0[36]*_t69*_t83;
  const double _t254 = -_hc0[11]*_t252 + (0.1e1 / 0.2e1)*_hc0[30]*_t69*_t83;
  const double _t255 = -_hc0[18]*_t252 + (0.1e1 / 0.2e1)*_hc0[46]*_t69*_t83;
  const double _t256 = -0.2e1 / 0.3e1*_hc0[3]*_t15*_t86;
  const double _t257 = _t75*_t83;
  const double _t258 = _t256 + _t257;
  const double _t259 = _t254*_t37 + _t255*_t38 + _t258;
  const double _t260 = _hc0[14]*_t14;
  const double _t261 = _t244*_t260;
  const double _t262 = -_hc0[36]*_t14*_t69*_t83 + _t261;
  const double _t263 = -0.4e1 / 0.3e1*_hc0[3]*_t15*_t86;
  const double _t265 = _hc0[30]*_t22;
  const double _t266 = _t264*_t265;
  const double _t268 = -0.1e1 / 0.6e1*_hc0[18]*_t3*_t4*_t69*_t86 + _hc0[46]*_t267*_t76 + _t257 + _t263 + (0.4e1 / 0.3e1)*_t266;
  const double _t269 = _t262 + _t268;
  const double _t270 = _t85 - _t88;
  const double _t271 = -0.1e1 / 0.2e1*_hc0[36]*_t14*_t69*_t83 + _t252*_t260;
  const double _t272 = _hc0[46]*_t267;
  const double _t273 = -0.1e1 / 0.12e2*_hc0[18]*_t3*_t4*_t69*_t86 + _t247 + _t256 + (0.2e1 / 0.3e1)*_t266 + _t272*_t68;
  const double _t274 = _t1*(_t21*_t246 - _t250) + _t89;
  const double _t275 = _hc0[14]*_t21;
  const double _t276 = _t244*_t275;
  const double _t277 = -_hc0[36]*_t21*_t69*_t83 + _t276;
  const double _t278 = _t268 + _t277;
  const double _t279 = -0.1e1 / 0.2e1*_hc0[36]*_t21*_t69*_t83 + _t252*_t275;
  const double _t281 = _hc0[11]*_t280;
  const double _t284 = _hc0[3]*_t283;
  const double _t285 = _t284*_t9;
  const double _t286 = _t22*_t248;
  const double _t287 = _t286*_t9;
  const double _t288 = -_t281*_t282 + (0.3e1 / 0.8e1)*_t285 + (0.1e1 / 0.2e1)*_t287;
  const double _t289 = _t1*_t288;
  const double _t291 = _t281*_t69;
  const double _t292 = (0.3e1 / 0.4e1)*_t285;
  const double _t293 = -0.1e1 / 0.2e1*_t291 + _t292;
  const double _t294 = _t254*_t290 + _t293;
  const double _t295 = _hc0[30]*_t86;
  const double _t296 = _t107*_t295;
  const double _t297 = (0.3e1 / 0.2e1)*_t285 - 0.3e1 / 0.2e1*_t291 + (0.1e1 / 0.2e1)*_t296;
  const double _t298 = -0.3e1 / 0.4e1*_t291 + _t292 + (0.1e1 / 0.4e1)*_t296;
  const double _t299 = _t295*_t32;
  const double _t300 = _t281*_t92;
  const double _t301 = _t2*_t284;
  const double d3F_dna3 = _t1*(_t100 + _t105 + _t135) - _t101*_t136 - _t137*_t45 + _t140 + 0.3e1*_t36 + 0.3e1*_t41;
  const double d3F_dna2_dnb = _t1*(_t100 + _t118*_t43 + _t118*_t54 + _t119*_t45 + _t119*_t55 + _t142 + _t148 + _t149 - _t153*_t37 - _t156*_t38 + _t34*_t40) + _t140 - _t157*_t47 - _t158*_t49 + _t161 + _t46;
  const double d3F_dna_dnb2 = _t1*(-_hc0[4]*_t109 - _hc0[4]*_t33 + (0.56e2 / 0.9e1)*_t11*_t27*_t54 + _t14*_t167 + (0.4e1 / 0.9e1)*_t15*_t3*_t4*_t55 - _t163 - _t166 + 0.4e1*_t32*_t52*_t7 - _t97 - _t99) + _t161 + _t169 + _t60;
  const double d3F_dnb3 = _t1*(_t100 + _t102*_t168 + _t104*_t158 - _t163 - _t166 + _t174) + _t169 + 0.3e1*_t58 + 0.3e1*_t59;
  const double d3F_dna2_dgaa = _t200;
  const double d3F_dna2_dgab = 0.2e1*_hc0[14]*_t14*_t22*_t9 + _t1*(_t202 + _t217) - _t220;
  const double d3F_dna2_dgbb = _t200;
  const double d3F_dna_dnb_dgaa = _t229;
  const double d3F_dna_dnb_dgab = _t1*(_t231 + _t234 + _t237) - _t220 - _t74 - _t81;
  const double d3F_dna_dnb_dgbb = _t229;
  const double d3F_dnb2_dgaa = _t241;
  const double d3F_dnb2_dgab = 0.2e1*_hc0[14]*_t21*_t22*_t9 + _t1*(_t232 + _t237 + _t243) - _t220;
  const double d3F_dnb2_dgbb = _t241;
  const double d3F_dna_dgaa2 = _t251;
  const double d3F_dna_dgaa_dgab = _t1*(_t14*_t253 - _t259) + _t91;
  const double d3F_dna_dgaa_dgbb = _t251;
  const double d3F_dna_dgab2 = -_t1*_t269 + _t270;
  const double d3F_dna_dgab_dgbb = _t1*(-_t271 - _t273) + _t91;
  const double d3F_dna_dgbb2 = _t251;
  const double d3F_dnb_dgaa2 = _t274;
  const double d3F_dnb_dgaa_dgab = _t1*(_t21*_t253 - _t259) + _t91;
  const double d3F_dnb_dgaa_dgbb = _t274;
  const double d3F_dnb_dgab2 = -_t1*_t278 + _t270;
  const double d3F_dnb_dgab_dgbb = _t1*(-_t273 - _t279) + _t91;
  const double d3F_dnb_dgbb2 = _t274;
  const double d3F_dgaa3 = _t289;
  const double d3F_dgaa2_dgab = _t1*_t294;
  const double d3F_dgaa2_dgbb = _t289;
  const double d3F_dgaa_dgab2 = _t1*_t297;
  const double d3F_dgaa_dgab_dgbb = _t1*_t298;
  const double d3F_dgaa_dgbb2 = _t289;
  const double d3F_dgab3 = _t299 - 0.3e1*_t300 + 0.3e1*_t301;
  const double d3F_dgab2_dgbb = (0.1e1 / 0.2e1)*_t299 - 0.3e1 / 0.2e1*_t300 + (0.3e1 / 0.2e1)*_t301;
  const double d3F_dgab_dgbb2 = _t2*_t286 - 0.1e1 / 0.2e1*_t300 + (0.3e1 / 0.4e1)*_t301;
  const double d3F_dgbb3 = _t289;
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
  const double _t302 = 0.24e2*_t107;
  const double _t303 = 0.24e2*_t264*_t7;
  const double _t317 = _t102*_t11;
  const double _t322 = _t104*_t5;
  const double _t323 = _t11*_t96;
  const double _t325 = _t5*_t98;
  const double _t349 = xc_powr(_t1, -16, 3);
  const double _t351 = (0.16e2 / 0.3e1)*_t15;
  const double _t353 = (0.2e1 / 0.3e1)*_t9;
  const double _t356 = 0.12e2*_t107;
  const double _t374 = (0.28e2 / 0.27e2)*_t27;
  const double _t377 = _t11*_t136;
  const double _t378 = _t106*_t7;
  const double _t386 = _t159*_t7;
  const double _t398 = _t32*_t7;
  const double _t399 = _t15*_t47;
  const double _t401 = _t49*_t5;
  const double _t402 = 0.2e1*_t57;
  const double _t404 = 0.18e2*_t108;
  const double _t414 = (0.14e2 / 0.9e1)*_t175;
  const double _t415 = _t22*_t64;
  const double _t416 = _t178*_t415;
  const double _t421 = _t177*_t22;
  const double _t425 = xc_powr(_t1, -17, 3);
  const double _t434 = 0.2e1*_t15;
  const double _t442 = (0.28e2 / 0.9e1)*_t175;
  const double _t443 = (0.2e1 / 0.9e1)*_t5;
  const double _t444 = _t415*_t443;
  const double _t449 = _t22*_t28;
  const double _t460 = _t7*_t95;
  const double _t461 = _t22*_t460;
  const double _t492 = _t69*_t83;
  const double _t493 = (0.1e1 / 0.4e1)*_t492;
  const double _t514 = (0.1e1 / 0.2e1)*_t492;
  const double _t534 = _t22*_t264;
  const double _t535 = (0.4e1 / 0.3e1)*_t534;
  const double _t536 = _t267*_t76;
  const double _t538 = (0.8e1 / 0.3e1)*_t15*_t22;
  const double _t543 = xc_powi(_t1, -6);
  const double _t547 = (0.2e1 / 0.3e1)*_t534;
  const double _t548 = _t267*_t68;
  const double _t571 = _t283*_t9;
  const double _t572 = (0.3e1 / 0.8e1)*_t571;
  const double _t573 = _t280*_t282;
  const double _t579 = (0.3e1 / 0.4e1)*_t571;
  const double _t581 = _t280*_t69;
  const double _t582 = (0.1e1 / 0.2e1)*_t581;
  const double _t589 = (0.3e1 / 0.2e1)*_t571;
  const double _t590 = (0.3e1 / 0.2e1)*_t581;
  const double _t591 = _t107*_t86;
  const double _t592 = (0.1e1 / 0.2e1)*_t591;
  const double _t598 = (0.3e1 / 0.4e1)*_t581;
  const double _t599 = (0.1e1 / 0.4e1)*_t591;
  const double _t603 = 0.3e1*_t581;
  const double _t613 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t304 = _hc0[110]*_t38 + _hc0[89]*_t37;
  const double _t305 = _hc0[109]*_t38 + _hc0[86]*_t37;
  const double _t306 = _hc0[89]*_t14 - _t305;
  const double _t307 = _hc0[109]*_t37 + _hc0[120]*_t38;
  const double _t308 = _hc0[110]*_t14 - _t307;
  const double _t309 = _hc0[39]*_t118 + _hc0[50]*_t119;
  const double _t310 = _hc0[39]*_t35;
  const double _t311 = _hc0[106]*_t38 + _hc0[80]*_t37;
  const double _t312 = _hc0[86]*_t14 - _t311;
  const double _t313 = _hc0[106]*_t37 + _hc0[119]*_t38;
  const double _t314 = _hc0[109]*_t14 - _t313;
  const double _t315 = _hc0[36]*_t118 + _hc0[49]*_t119;
  const double _t316 = _t14*_t306 + _t310 - _t312*_t37 - _t314*_t38 + _t315;
  const double _t318 = _hc0[119]*_t37 + _hc0[124]*_t38;
  const double _t319 = _hc0[120]*_t14 - _t318;
  const double _t320 = _hc0[49]*_t118 + _hc0[54]*_t119;
  const double _t321 = _hc0[50]*_t35 + _t14*_t308 - _t314*_t37 - _t319*_t38 + _t320;
  const double _t324 = _hc0[14]*_t323;
  const double _t326 = _hc0[19]*_t325;
  const double _t327 = -_t324 - _t326;
  const double _t328 = _t101*_t95;
  const double _t329 = _hc0[36]*_t35;
  const double _t330 = _hc0[100]*_t38 + _hc0[70]*_t37;
  const double _t331 = _hc0[100]*_t37 + _hc0[116]*_t38;
  const double _t332 = _hc0[106]*_t14 - _t331;
  const double _t333 = _hc0[30]*_t118 + _hc0[46]*_t119;
  const double _t334 = _hc0[49]*_t35;
  const double _t335 = _hc0[116]*_t37 + _hc0[123]*_t38;
  const double _t336 = _hc0[119]*_t14 - _t335;
  const double _t337 = _hc0[46]*_t118 + _hc0[53]*_t119;
  const double _t338 = _t14*_t314 - _t332*_t37 + _t334 - _t336*_t38 + _t337;
  const double _t339 = _hc0[11]*_t323;
  const double _t340 = _hc0[18]*_t325;
  const double _t341 = -_t339 - _t340;
  const double _t342 = _t11*_t130;
  const double _t343 = _hc0[123]*_t37 + _hc0[125]*_t38;
  const double _t344 = _hc0[53]*_t118 + _hc0[55]*_t119;
  const double _t345 = _hc0[18]*_t323;
  const double _t346 = _hc0[20]*_t325;
  const double _t347 = -_t345 - _t346;
  const double _t348 = _t134*_t5;
  const double _t350 = (0.140e3 / 0.81e2)*_t18*_t95 + (0.3640e4 / 0.81e2)*_t26*_t349;
  const double _t352 = _t101*_t27;
  const double _t354 = _t103*_t15;
  const double _t355 = -0.56e2 / 0.27e2*_t18*_t27 - 0.1120e4 / 0.27e2*_t26*_t95;
  const double _t357 = _hc0[90]*_t21 - _t304;
  const double _t358 = _hc0[89]*_t21 - _t305;
  const double _t359 = _hc0[110]*_t21 - _t307;
  const double _t360 = _t309 - _t358*_t37 - _t359*_t38;
  const double _t361 = _hc0[86]*_t21 - _t311;
  const double _t362 = _hc0[109]*_t21 - _t313;
  const double _t363 = _t315 - _t361*_t37 - _t362*_t38;
  const double _t364 = _hc0[39]*_t34 + _t14*_t358 + _t363;
  const double _t365 = _hc0[120]*_t21 - _t318;
  const double _t366 = _t320 - _t362*_t37 - _t365*_t38;
  const double _t367 = _hc0[50]*_t34 + _t14*_t359 + _t366;
  const double _t368 = _hc0[14]*_t141;
  const double _t369 = _hc0[106]*_t21 - _t331;
  const double _t370 = _t333 - _t369*_t38 - _t37*(_hc0[80]*_t21 - _t330);
  const double _t371 = _hc0[119]*_t21 - _t335;
  const double _t372 = _t337 - _t369*_t37 - _t371*_t38;
  const double _t373 = _hc0[49]*_t34 + _t14*_t362 + _t372;
  const double _t375 = _t344 - _t37*_t371 - _t38*(_hc0[124]*_t21 - _t343);
  const double _t376 = _t153*_t317 + _t156*_t322 + _t350;
  const double _t379 = _hc0[4]*_t303;
  const double _t380 = _hc0[50]*_t57 + _t21*_t359 + _t366;
  const double _t381 = _t38*_t380;
  const double _t382 = _hc0[39]*_t57;
  const double _t383 = _t21*_t358 + _t363 + _t382;
  const double _t384 = _t37*_t383;
  const double _t385 = _hc0[40]*_t57 + _t21*_t357 + _t360;
  const double _t387 = _t168*_t95;
  const double _t388 = _hc0[49]*_t57;
  const double _t389 = _t21*_t362 + _t372 + _t388;
  const double _t390 = _t38*_t389;
  const double _t391 = _hc0[36]*_t57;
  const double _t392 = _t37*(_t21*_t361 + _t370 + _t391);
  const double _t393 = _t38*(_hc0[54]*_t57 + _t21*_t365 + _t375);
  const double _t394 = _t37*_t389;
  const double _t395 = _t14*_t167;
  const double _t396 = _hc0[4]*_t356;
  const double _t397 = 0.8e1*_t52;
  const double _t400 = _t168*_t27;
  const double _t403 = _hc0[15]*_t170 + _t143*_t402 + _t144*_t317 + _t145*_t322 + _t21*_t385 + _t327 - _t381 - _t384;
  const double _t405 = _t11*_t165;
  const double _t406 = _t162*_t5;
  const double _t407 = _t138*_t405 + _t139*_t406 - _t158*_t177 + _t350 - _t37*(_hc0[14]*_t170 + _t144*_t402 + _t150*_t317 + _t151*_t322 + _t21*_t383 + _t341 - _t390 - _t392) - _t38*(_hc0[19]*_t170 + _t145*_t402 + _t151*_t317 + _t154*_t322 + _t21*_t380 + _t347 - _t393 - _t394) - 0.280e3 / 0.9e1*_t387;
  const double _t408 = (0.16e2 / 0.9e1)*_t15*_t158 - _t351*_t405 - _t353*_t406 + _t355 + (0.224e3 / 0.9e1)*_t400;
  const double _t409 = _hc0[109]*_t186 + _hc0[39]*_t191 + _hc0[86]*_t182;
  const double _t410 = _hc0[106]*_t186 + _hc0[36]*_t191 + _hc0[80]*_t182;
  const double _t411 = (0.1e1 / 0.2e1)*_hc0[86]*_t14*_t22*_t9 - _t410;
  const double _t412 = _hc0[106]*_t182 + _hc0[119]*_t186 + _hc0[49]*_t191;
  const double _t413 = (0.1e1 / 0.2e1)*_hc0[109]*_t14*_t22*_t9 - _t412;
  const double _t417 = _hc0[36]*_t414 + _hc0[49]*_t416 + _t177*_t184;
  const double _t418 = _hc0[100]*_t186 + _hc0[30]*_t191 + _hc0[70]*_t182;
  const double _t419 = _hc0[100]*_t182 + _hc0[116]*_t186 + _hc0[46]*_t191;
  const double _t420 = (0.1e1 / 0.2e1)*_hc0[106]*_t14*_t22*_t9 - _t419;
  const double _t422 = _hc0[11]*_t421 + _hc0[30]*_t414 + _hc0[46]*_t416;
  const double _t423 = _hc0[116]*_t182 + _hc0[123]*_t186 + _hc0[53]*_t191;
  const double _t424 = _hc0[18]*_t421 + _hc0[46]*_t414 + _hc0[53]*_t416;
  const double _t426 = _hc0[11]*_t425;
  const double _t427 = (0.140e3 / 0.27e2)*_t426;
  const double _t428 = (0.140e3 / 0.27e2)*_t23*_t95;
  const double _t429 = _t179*_t5;
  const double _t430 = _t175*_t429;
  const double _t431 = (0.7e1 / 0.27e2)*_t430;
  const double _t432 = _t427 + _t428 + _t431;
  const double _t433 = _t22*_t43;
  const double _t435 = (0.14e2 / 0.3e1)*_t176 + (0.1e1 / 0.3e1)*_t201 + (0.14e2 / 0.3e1)*_t23*_t27;
  const double _t436 = _t1*((0.1e1 / 0.2e1)*_hc0[14]*_t110*_t22*_t9 + (0.56e2 / 0.9e1)*_t11*_t193*_t27 - _t130*_t191 + _t14*(-_t115*_t191 + _t14*((0.1e1 / 0.2e1)*_hc0[89]*_t14*_t22*_t9 - _t409) + _t290*_t310 - _t37*_t411 - _t38*_t413 + _t417) + (0.4e1 / 0.9e1)*_t15*_t198*_t3*_t4 + 0.2e1*_t188*_t35 + (0.28e2 / 0.9e1)*_t22*_t27*_t43 - _t37*(-_t126*_t191 + _t14*_t411 + _t290*_t329 - _t37*((0.1e1 / 0.2e1)*_hc0[80]*_t14*_t22*_t9 - _t418) - _t38*_t420 + _t422) - _t38*(-_t128*_t191 + _t14*_t413 + _t290*_t334 - _t37*_t420 - _t38*((0.1e1 / 0.2e1)*_hc0[119]*_t14*_t22*_t9 - _t423) + _t424) - _t432) - _t137*_t198 + 0.3e1*_t189 - _t193*_t377 + (0.3e1 / 0.2e1)*_t195 - _t433*_t434 + _t435;
  const double _t437 = _hc0[109]*_t206 + _hc0[39]*_t211 + _hc0[86]*_t203;
  const double _t438 = _hc0[106]*_t206 + _hc0[36]*_t211 + _hc0[80]*_t203;
  const double _t439 = _hc0[86]*_t14*_t22*_t9 - _t438;
  const double _t440 = _hc0[106]*_t203 + _hc0[119]*_t206 + _hc0[49]*_t211;
  const double _t441 = _hc0[109]*_t14*_t22*_t9 - _t440;
  const double _t445 = _hc0[36]*_t442 + _hc0[49]*_t444 + _t184*_t28;
  const double _t446 = _hc0[100]*_t206 + _hc0[30]*_t211 + _hc0[70]*_t203;
  const double _t447 = _hc0[100]*_t203 + _hc0[116]*_t206 + _hc0[46]*_t211;
  const double _t448 = _hc0[106]*_t14*_t22*_t9 - _t447;
  const double _t450 = _hc0[11]*_t449 + _hc0[30]*_t442 + _hc0[46]*_t444;
  const double _t451 = _hc0[116]*_t203 + _hc0[123]*_t206 + _hc0[53]*_t211;
  const double _t452 = _hc0[18]*_t449 + _hc0[46]*_t442 + _hc0[53]*_t444;
  const double _t453 = (0.280e3 / 0.27e2)*_t426;
  const double _t454 = _t23*_t96;
  const double _t455 = (0.14e2 / 0.27e2)*_t430;
  const double _t456 = _t453 + _t454 + _t455;
  const double _t457 = _t138*_t23 + (0.28e2 / 0.3e1)*_t176 + _t182*_t429;
  const double _t458 = 0.2e1*_t222;
  const double _t459 = (0.1e1 / 0.2e1)*_hc0[109]*_t21*_t22*_t9 - _t412;
  const double _t462 = _hc0[49]*_t461;
  const double _t463 = (0.1e1 / 0.2e1)*_hc0[106]*_t21*_t22*_t9 - _t419;
  const double _t464 = -_t151*_t191 - _t37*_t463 - _t38*((0.1e1 / 0.2e1)*_hc0[119]*_t21*_t22*_t9 - _t423) + _t424;
  const double _t465 = (0.1e1 / 0.2e1)*_hc0[86]*_t21*_t22*_t9 - _t410;
  const double _t466 = _hc0[36]*_t461;
  const double _t467 = -_t150*_t191 - _t37*((0.1e1 / 0.2e1)*_hc0[80]*_t21*_t22*_t9 - _t418) - _t38*_t463 + _t422;
  const double _t468 = (0.1e1 / 0.2e1)*_hc0[89]*_t21*_t22*_t9 - _t409;
  const double _t469 = _hc0[39]*_t461;
  const double _t470 = -_t144*_t191 - _t37*_t465 - _t38*_t459 + _t417;
  const double _t471 = _t1*(_t118*_t193 + _t118*_t225 + _t119*_t198 + _t119*_t227 + _t14*(_t14*_t468 + _t469 + _t470) - _t153*_t191 + _t188*_t34 + _t221*_t35 + _t290*_t368 - _t37*(_t14*_t465 + _t466 + _t467) - _t38*(_t14*_t459 + _t462 + _t464) + _t421*_t43 + _t421*_t54 - _t427 - _t428 - _t431) + _t199 - _t225*_t399 - _t227*_t401 + _t234 + _t435 + _t458;
  const double _t472 = _hc0[109]*_t21*_t22*_t9 - _t440;
  const double _t473 = _hc0[106]*_t21*_t22*_t9 - _t447;
  const double _t474 = -_t151*_t211 - _t37*_t473 - _t38*(_hc0[119]*_t21*_t22*_t9 - _t451) + _t452;
  const double _t475 = _hc0[86]*_t21*_t22*_t9 - _t438;
  const double _t476 = -_t150*_t211 - _t37*(_hc0[80]*_t21*_t22*_t9 - _t446) - _t38*_t473 + _t450;
  const double _t477 = _hc0[89]*_t21*_t22*_t9 - _t437;
  const double _t478 = -_t144*_t211 - _t37*_t475 - _t38*_t472 + _t445;
  const double _t479 = 0.4e1*_t224 + 0.2e1*_t231;
  const double _t480 = _t21*_t468 + _t290*_t382 + _t470;
  const double _t481 = _t184*_t349*_t7;
  const double _t482 = -0.56e2 / 0.9e1*_t11*_t225*_t27 - 0.4e1 / 0.9e1*_t15*_t227*_t3*_t4 + _t165*_t191 - 0.28e2 / 0.9e1*_t22*_t27*_t54 + _t37*(_t21*_t465 + _t290*_t391 + _t467) + _t38*(_t21*_t459 + _t290*_t388 + _t464) + _t432;
  const double _t483 = -_t137*_t227 - _t225*_t377 - 0.2e1*_t226 + _t435;
  const double _t484 = _t1*(_t14*_t480 + 0.4e1*_t221*_t32*_t7 - _t223 - 0.3e1*_t481 - _t482) + _t233 + _t240 + _t458 + _t483;
  const double _t485 = _t194*_t382 + _t21*_t477 + _t478;
  const double _t486 = -0.56e2 / 0.9e1*_t11*_t235*_t27 - 0.4e1 / 0.9e1*_t15*_t236*_t3*_t4 + _t165*_t211 - 0.56e2 / 0.9e1*_t22*_t27*_t54 + _t37*(_t194*_t391 + _t21*_t475 + _t476) + _t38*(_t194*_t388 + _t21*_t472 + _t474) + _t456;
  const double _t487 = -_t136*_t22*_t54 - _t137*_t236 - _t235*_t377 + _t457;
  const double _t488 = _t1*((0.1e1 / 0.2e1)*_hc0[14]*_t170*_t22*_t9 + _t21*_t480 + 0.2e1*_t221*_t57 - _t482) + 0.3e1*_t238 + (0.3e1 / 0.2e1)*_t239 + _t483;
  const double _t489 = -_hc0[39]*_t245 + (0.1e1 / 0.4e1)*_hc0[86]*_t69*_t83;
  const double _t490 = _t183*_t83;
  const double _t491 = -_hc0[36]*_t245 + (0.1e1 / 0.4e1)*_hc0[80]*_t69*_t83;
  const double _t494 = _hc0[106]*_t493 - _hc0[49]*_t245;
  const double _t495 = -0.1e1 / 0.3e1*_hc0[14]*_t15*_t86 + _t37*_t491 + _t38*_t494 + _t490;
  const double _t496 = _t190*_t83;
  const double _t497 = _t295*_t9;
  const double _t498 = (0.1e1 / 0.4e1)*_hc0[70]*_t69*_t83 - 0.1e1 / 0.4e1*_t497;
  const double _t499 = _hc0[100]*_t493 - _hc0[46]*_t245;
  const double _t500 = -0.1e1 / 0.3e1*_hc0[11]*_t15*_t86 + _t37*_t498 + _t38*_t499 + _t496;
  const double _t501 = _t193*_t211;
  const double _t502 = -_t501;
  const double _t503 = _t196*_t83;
  const double _t504 = -0.1e1 / 0.3e1*_hc0[18]*_t15*_t86 + _t37*_t499 + _t38*(_hc0[116]*_t493 - _hc0[53]*_t245) + _t503;
  const double _t505 = _t118*_t248 + _t119*_t249 - 0.7e1 / 0.9e1*_t27*_t87 + _t414*_t84;
  const double _t506 = _t248*_t399;
  const double _t507 = _t249*_t401;
  const double _t508 = _t258 + _t506 + _t507;
  const double _t509 = _t1*(_t14*(_t14*_t489 - _t495) + (0.1e1 / 0.3e1)*_t15*_t43*_t86 + _t246*_t35 - _t37*(_t14*_t491 - _t500) - _t38*(_t14*_t494 - _t504) + _t502 + _t505) + 0.2e1*_t14*_t246 - _t508;
  const double _t510 = -_hc0[39]*_t252 + (0.1e1 / 0.2e1)*_hc0[86]*_t69*_t83;
  const double _t511 = -0.2e1 / 0.3e1*_hc0[14]*_t15*_t86;
  const double _t512 = _t204*_t83;
  const double _t513 = -_hc0[36]*_t252 + (0.1e1 / 0.2e1)*_hc0[80]*_t69*_t83;
  const double _t515 = _hc0[106]*_t514 - _hc0[49]*_t252;
  const double _t516 = _t37*_t513 + _t38*_t515 + _t511 + _t512;
  const double _t517 = -0.2e1 / 0.3e1*_hc0[11]*_t15*_t86;
  const double _t518 = _t210*_t83;
  const double _t519 = (0.1e1 / 0.2e1)*_hc0[70]*_t69*_t83 - 0.1e1 / 0.2e1*_t497;
  const double _t520 = _hc0[100]*_t514 - _hc0[46]*_t252;
  const double _t521 = _t37*_t519 + _t38*_t520 + _t517 + _t518;
  const double _t522 = _t191*_t213;
  const double _t523 = -0.2e1 / 0.3e1*_hc0[18]*_t15*_t86;
  const double _t524 = _t214*_t83;
  const double _t525 = _t37*_t520 + _t38*(_hc0[116]*_t514 - _hc0[53]*_t252) + _t523 + _t524;
  const double _t526 = _t177*_t87;
  const double _t527 = _t442*_t84;
  const double _t528 = _t118*_t254 + _t119*_t255 - _t526 + _t527;
  const double _t529 = _t218*_t83;
  const double _t530 = _t254*_t399;
  const double _t531 = _t255*_t401;
  const double _t532 = _t263 + _t529 + _t530 + _t531;
  const double _t533 = _hc0[39]*_t14;
  const double _t537 = _hc0[106]*_t536 - 0.4e1 / 0.3e1*_hc0[14]*_t15*_t86 - 0.1e1 / 0.6e1*_hc0[49]*_t3*_t4*_t69*_t86 + _hc0[80]*_t535 + _t512;
  const double _t539 = _hc0[36]*_t14;
  const double _t540 = _hc0[100]*_t536 - 0.4e1 / 0.3e1*_hc0[11]*_t15*_t86 - 0.1e1 / 0.6e1*_hc0[46]*_t3*_t4*_t69*_t86 + _hc0[70]*_t535 + _t518;
  const double _t541 = _hc0[49]*_t14;
  const double _t542 = _hc0[100]*_t535 + _hc0[116]*_t536 - 0.4e1 / 0.3e1*_hc0[18]*_t15*_t86 - 0.1e1 / 0.6e1*_hc0[53]*_t3*_t4*_t69*_t86 + _t524;
  const double _t544 = _hc0[18]*_t64*_t86;
  const double _t545 = _hc0[46]*_t264*_t443*_t83 + (0.28e2 / 0.9e1)*_t265*_t543 - _t28*_t87 - _t443*_t544 + _t527;
  const double _t546 = -0.1e1 / 0.3e1*_hc0[18]*_t3*_t4*_t69*_t86 - 0.8e1 / 0.3e1*_hc0[3]*_t15*_t86 + _t219*_t272 + (0.8e1 / 0.3e1)*_t266 + _t529;
  const double _t549 = _hc0[106]*_t548 - 0.1e1 / 0.12e2*_hc0[49]*_t3*_t4*_t69*_t86 + _hc0[80]*_t547 + _t490 + _t511;
  const double _t550 = _hc0[100]*_t548 - 0.1e1 / 0.12e2*_hc0[46]*_t3*_t4*_t69*_t86 + _hc0[70]*_t547 + _t496 + _t517;
  const double _t551 = _hc0[100]*_t547 + _hc0[116]*_t548 - 0.1e1 / 0.12e2*_hc0[53]*_t3*_t4*_t69*_t86 + _t503 + _t523;
  const double _t552 = -0.14e2 / 0.9e1*_hc0[11]*_t175*_t83 - 0.14e2 / 0.9e1*_hc0[30]*_t22*_t543 - 0.1e1 / 0.9e1*_hc0[46]*_t264*_t3*_t4*_t83 + _t178*_t544 + _t526;
  const double _t553 = _t21*_t489 - _t495;
  const double _t554 = _t211*_t225;
  const double _t555 = -_t554;
  const double _t556 = _t157*_t86;
  const double _t557 = -_t37*(_t21*_t491 - _t500) - _t38*(_t21*_t494 - _t504) + _t505 + _t555 + (0.1e1 / 0.3e1)*_t556;
  const double _t558 = _t1*(_t14*_t553 + _t246*_t34 + _t557) + _t139*_t87 + _t14*_t246 + _t21*_t246 - _t257 - _t506 - _t507;
  const double _t559 = _t21*_t510 - _t516;
  const double _t560 = _t191*_t235;
  const double _t561 = -_t37*(_t21*_t513 - _t521) - _t38*(_t21*_t515 - _t525) + _t528 + _t555 + (0.2e1 / 0.3e1)*_t556 - _t560;
  const double _t562 = _hc0[39]*_t21;
  const double _t563 = _hc0[86]*_t21*_t69*_t83 - _t244*_t562 - _t537;
  const double _t564 = _hc0[14]*_t460*_t86;
  const double _t565 = _hc0[36]*_t21;
  const double _t566 = _hc0[49]*_t21;
  const double _t567 = -_t235*_t538 - _t37*(_hc0[80]*_t21*_t69*_t83 - _t244*_t565 - _t540) - _t38*(_hc0[106]*_t21*_t69*_t83 - _t244*_t566 - _t542) + _t545 + (0.4e1 / 0.3e1)*_t556;
  const double _t568 = (0.1e1 / 0.2e1)*_hc0[86]*_t21*_t69*_t83 - _t252*_t562 - _t549;
  const double _t569 = -0.2e1 / 0.3e1*_t15*_t54*_t86 + _t37*((0.1e1 / 0.2e1)*_hc0[80]*_t21*_t69*_t83 - _t252*_t565 - _t550) + _t38*((0.1e1 / 0.2e1)*_hc0[106]*_t21*_t69*_t83 - _t252*_t566 - _t551) + _t552 + _t554 + _t560;
  const double _t570 = _t1*(_t21*_t553 + _t246*_t57 + _t557) + 0.2e1*_t21*_t246 - _t508;
  const double _t574 = _hc0[14]*_t572 - _hc0[36]*_t573 + _t290*_t491;
  const double _t575 = _t16*_t283;
  const double _t576 = _hc0[11]*_t572 - _hc0[30]*_t573 + _t290*_t498;
  const double _t577 = -0.1e1 / 0.2e1*_hc0[11]*_t280*_t64 + _t286*_t434 + _t37*_t576 + _t38*(_hc0[18]*_t572 - _hc0[46]*_t573 + _t290*_t499) + (0.1e1 / 0.2e1)*_t575;
  const double _t578 = _t1*(_t14*_t574 - _t577) + _t288;
  const double _t580 = _hc0[14]*_t579;
  const double _t583 = -_hc0[36]*_t582 + _t290*_t513 + _t580;
  const double _t584 = _hc0[11]*_t579;
  const double _t585 = -_hc0[30]*_t582 + _t290*_t519 + _t584;
  const double _t586 = _hc0[18]*_t579;
  const double _t587 = _t205*_t286 + _t575;
  const double _t588 = -_hc0[11]*_t280*_t64 + _t211*_t254 + _t37*_t585 + _t38*(-_hc0[46]*_t582 + _t290*_t520 + _t586) + _t587;
  const double _t593 = _hc0[14]*_t589 - _hc0[36]*_t590 + _hc0[80]*_t592;
  const double _t594 = 0.2e1*_t575;
  const double _t595 = _t264*_t295;
  const double _t596 = _hc0[11]*_t589 - _hc0[30]*_t590 + _hc0[70]*_t592;
  const double _t597 = -0.8e1 / 0.3e1*_hc0[11]*_t280*_t64 + _t254*_t538 + _t37*_t596 + _t38*(_hc0[100]*_t592 + _hc0[18]*_t589 - _hc0[46]*_t590) + _t594 + (0.2e1 / 0.3e1)*_t595;
  const double _t600 = -_hc0[36]*_t598 + _hc0[80]*_t599 + _t580;
  const double _t601 = -_hc0[30]*_t598 + _hc0[70]*_t599 + _t584;
  const double _t602 = -0.4e1 / 0.3e1*_hc0[11]*_t280*_t64 + _t191*_t254 + _t37*_t601 + _t38*(_hc0[100]*_t599 - _hc0[46]*_t598 + _t586) + _t587 + (0.1e1 / 0.3e1)*_t595;
  const double _t604 = _hc0[70]*_t83/xc_powr(_t1, 19, 3);
  const double _t605 = _t283*_t70;
  const double _t606 = _hc0[100]*_t349*_t86;
  const double _t607 = -0.4e1*_hc0[11]*_t280*_t64 - 0.1e1 / 0.2e1*_hc0[46]*_t107*_t280*_t3*_t4 + 0.4e1*_t575 + _t6*_t605 + (0.4e1 / 0.3e1)*_t604 + _t606*_t76;
  const double _t608 = 0.3e1*_t285 - 0.3e1*_t291 + _t296;
  const double _t609 = -0.2e1*_hc0[11]*_t280*_t64 + _hc0[18]*_t282*_t283*_t5 - 0.1e1 / 0.4e1*_hc0[46]*_t107*_t280*_t3*_t4 + _t594 + (0.2e1 / 0.3e1)*_t604 + _t606*_t68;
  const double _t610 = -0.2e1 / 0.3e1*_hc0[11]*_t280*_t64 - 0.1e1 / 0.12e2*_hc0[46]*_t107*_t280*_t3*_t4 + _t203*_t498 + _t206*_t499 + (0.1e1 / 0.8e1)*_t5*_t605 + _t587;
  const double _t611 = _t287 + _t293;
  const double _t612 = _t1*(_t21*_t574 - _t577) + _t288;
  const double _t614 = _hc0[11]*_t613;
  const double _t615 = _t614*_t69;
  const double _t616 = _hc0[3]/xc_powr(_t10, 7, 2);
  const double _t617 = _t616*_t9;
  const double _t618 = _t22*_t576;
  const double _t619 = _t1*(-0.3e1 / 0.4e1*_t244*_t248 + (0.9e1 / 0.16e2)*_t615 - 0.15e2 / 0.16e2*_t617 + (0.1e1 / 0.2e1)*_t618*_t9);
  const double _t620 = _t244*_t254;
  const double _t621 = _t248*_t252 + (0.15e2 / 0.8e1)*_t617;
  const double _t622 = (0.15e2 / 0.4e1)*_t617;
  const double _t623 = _hc0[30]*_t283;
  const double _t624 = _t107*_t623;
  const double _t625 = _hc0[70]*_t280;
  const double _t626 = _t349*_t625;
  const double _t627 = _t625*_t95;
  const double _t628 = _t614*_t92;
  const double _t629 = _t2*_t616;
  const double _t630 = _t32*_t623;
  const double _t631 = _t2*_t248*_t86;
  const double d4F_dna4 = _t1*(_hc0[4]*(-_t302 + _t303) - _t103*_t177 + 0.3e1*_t110*_t40 + 0.3e1*_t121*_t35 + _t138*_t342 + _t139*_t348 + _t14*(_hc0[15]*_t110 + _t113*_t123 + _t115*_t317 + _t117*_t322 + _t14*(_hc0[40]*_t35 + _t14*(_hc0[90]*_t14 - _t304) - _t306*_t37 - _t308*_t38 + _t309) - _t316*_t37 - _t321*_t38 + _t327) - 0.280e3 / 0.9e1*_t328 + _t350 - _t37*(_hc0[14]*_t110 + _t115*_t123 + _t126*_t317 + _t128*_t322 + _t14*_t316 - _t338*_t38 + _t341 - _t37*(_t14*_t312 + _t329 - _t332*_t38 + _t333 - _t37*(_hc0[80]*_t14 - _t330))) - _t38*(_hc0[19]*_t110 + _t117*_t123 + _t128*_t317 + _t132*_t322 + _t14*_t321 - _t338*_t37 + _t347 - _t38*(_hc0[54]*_t35 + _t14*_t319 - _t336*_t37 + _t344 - _t38*(_hc0[124]*_t14 - _t343)))) + 0.4e1*_t111 + 0.4e1*_t122 - _t342*_t351 - _t348*_t353 + 0.8e1*_t35*_t40 + (0.224e3 / 0.9e1)*_t352 + (0.16e2 / 0.9e1)*_t354 + _t355;
  const double d4F_dna3_dnb = _t1*(_hc0[4]*(_t303 - _t356) - _t103*_t374 + _t110*_t52 + _t118*_t130 + _t119*_t134 + _t121*_t34 + _t123*_t147 + _t14*(_hc0[15]*_t141 + _t113*_t34 + _t115*_t118 + _t117*_t119 + _t118*_t144 + _t119*_t145 + _t14*(_hc0[40]*_t34 + _t14*_t357 + _t360) + _t143*_t35 + _t327 - _t364*_t37 - _t367*_t38) + 0.2e1*_t141*_t40 - _t158*_t98 - _t168*_t96 - 0.560e3 / 0.27e2*_t328 - _t37*(_t115*_t34 + _t118*_t126 + _t118*_t150 + _t119*_t128 + _t119*_t151 + _t14*_t364 + _t144*_t35 + _t341 + _t368 - _t37*(_hc0[36]*_t34 + _t14*_t361 + _t370) - _t373*_t38) + _t376 - _t38*(_hc0[19]*_t141 + _t117*_t34 + _t118*_t128 + _t118*_t151 + _t119*_t132 + _t119*_t154 + _t14*_t367 + _t145*_t35 + _t347 - _t37*_t373 - _t38*(_hc0[54]*_t34 + _t14*_t365 + _t375))) + _t135 - _t137*_t156 + _t138*_t168 + _t139*_t158 + 0.3e1*_t142 + 0.3e1*_t148 + 0.3e1*_t149 - _t153*_t377 + (0.140e3 / 0.9e1)*_t352 + (0.10e2 / 0.9e1)*_t354 + _t355 + _t378*_t40;
  const double d4F_dna2_dnb2 = _t1*(-_t101*_t96 - _t103*_t98 - _t109*_t40 + _t118*_t165 + _t119*_t162 + _t14*(-_hc0[15]*_t109 - _hc0[15]*_t33 + (0.56e2 / 0.9e1)*_t11*_t144*_t27 + _t14*_t385 + 0.4e1*_t143*_t32*_t7 + (0.4e1 / 0.9e1)*_t145*_t15*_t3*_t4 - _t324 - _t326 - _t381 - _t384) + _t141*_t173 + _t147*_t386 - _t158*_t374 + _t167*_t35 - _t33*_t40 - _t37*(-_hc0[14]*_t109 - _hc0[14]*_t33 + (0.56e2 / 0.9e1)*_t11*_t150*_t27 + _t14*_t383 + 0.4e1*_t144*_t32*_t7 + (0.4e1 / 0.9e1)*_t15*_t151*_t3*_t4 - _t339 - _t340 - _t390 - _t392) + _t376 + _t379 - _t38*(-_hc0[19]*_t109 - _hc0[19]*_t33 + (0.56e2 / 0.9e1)*_t11*_t151*_t27 + _t14*_t380 + 0.4e1*_t145*_t32*_t7 + (0.4e1 / 0.9e1)*_t15*_t154*_t3*_t4 - _t345 - _t346 - _t393 - _t394) - 0.560e3 / 0.27e2*_t387) + _t105 + 0.2e1*_t142 + 0.2e1*_t148 + 0.2e1*_t149 - _t153*_t399 - _t156*_t401 + _t158*_t205 - _t160 - _t162*_t401 - _t165*_t399 + _t355 + _t386*_t40 + 0.2e1*_t395 - _t396*_t7 + _t397*_t398 + (0.56e2 / 0.3e1)*_t400;
  const double d4F_dna_dnb3 = -_hc0[4]*_t106 - _hc0[4]*_t404 + _t1*(-_t106*_t52 + _t14*_t403 + _t167*_t378 + _t379 + _t396 - _t404*_t52 + _t407) + _t174 + 0.3e1*_t395 + 0.12e2*_t398*_t52 + _t408;
  const double d4F_dnb4 = _t1*(_hc0[4]*(_t302 + _t303) + 0.3e1*_t167*_t57 + 0.3e1*_t170*_t52 + _t21*_t403 + _t407) + 0.4e1*_t171 + 0.4e1*_t172 + _t397*_t57 + _t408;
  const double d4F_dna3_dgaa = _t436;
  const double d4F_dna3_dgab = _t1*(_hc0[14]*_t110*_t22*_t9 + (0.56e2 / 0.9e1)*_t11*_t213*_t27 - _t130*_t211 + _t14*(-_t115*_t211 + _t14*(_hc0[89]*_t14*_t22*_t9 - _t437) + _t194*_t310 - _t37*_t439 - _t38*_t441 + _t445) + (0.4e1 / 0.9e1)*_t15*_t216*_t3*_t4 + 0.2e1*_t208*_t35 + (0.56e2 / 0.9e1)*_t22*_t27*_t43 - _t37*(-_t126*_t211 + _t14*_t439 + _t194*_t329 - _t37*(_hc0[80]*_t14*_t22*_t9 - _t446) - _t38*_t448 + _t450) - _t38*(-_t128*_t211 + _t14*_t441 + _t194*_t334 - _t37*_t448 - _t38*(_hc0[119]*_t14*_t22*_t9 - _t451) + _t452) - _t456) - _t136*_t433 - _t137*_t216 + 0.3e1*_t195 + 0.3e1*_t209 - _t213*_t377 + _t457;
  const double d4F_dna3_dgbb = _t436;
  const double d4F_dna2_dnb_dgaa = _t471;
  const double d4F_dna2_dnb_dgab = _t1*(_t118*_t213 + _t118*_t235 + _t119*_t216 + _t119*_t236 + _t14*(_t14*_t477 + 0.2e1*_t469 + _t478) - _t153*_t211 + _t194*_t368 + _t208*_t34 + _t230*_t35 + _t28*_t433 - _t37*(_t14*_t475 + 0.2e1*_t466 + _t476) - _t38*(_t14*_t472 + 0.2e1*_t462 + _t474) + _t449*_t54 - _t453 - _t454 - _t455) + _t217 - 0.8e1 / 0.3e1*_t226 - _t235*_t399 - _t236*_t401 + _t457 + _t479;
  const double d4F_dna2_dnb_dgbb = _t471;
  const double d4F_dna_dnb2_dgaa = _t484;
  const double d4F_dna_dnb2_dgab = _t1*(_t14*_t485 - 0.2e1*_t223 + 0.4e1*_t230*_t32*_t7 - 0.6e1*_t481 - _t486) + _t243 + _t479 + _t487;
  const double d4F_dna_dnb2_dgbb = _t484;
  const double d4F_dnb3_dgaa = _t488;
  const double d4F_dnb3_dgab = _t1*(_hc0[14]*_t170*_t22*_t9 + _t21*_t485 + 0.2e1*_t230*_t57 - _t486) + 0.3e1*_t239 + 0.3e1*_t242 + _t487;
  const double d4F_dnb3_dgbb = _t488;
  const double d4F_dna2_dgaa2 = _t509;
  const double d4F_dna2_dgaa_dgab = _t1*(_t139*_t43*_t86 + _t14*(_t14*_t510 - _t516) + _t253*_t35 - _t37*(_t14*_t513 - _t521) - _t38*(_t14*_t515 - _t525) + _t502 - _t522 + _t528) + 0.2e1*_t14*_t253 - _t532;
  const double d4F_dna2_dgaa_dgbb = _t509;
  const double d4F_dna2_dgab2 = 0.2e1*_hc0[36]*_t14*_t69*_t83 + _t1*(-_t124*_t244 + _t14*(_hc0[86]*_t14*_t69*_t83 - _t244*_t533 - _t537) + _t205*_t43*_t86 - _t213*_t538 + _t329*_t492 - _t37*(_hc0[80]*_t14*_t69*_t83 - _t244*_t539 - _t540) - _t38*(_hc0[106]*_t14*_t69*_t83 - _t244*_t541 - _t542) + _t545) - 0.2e1*_t261 - _t546;
  const double d4F_dna2_dgab_dgbb = _t1*((0.1e1 / 0.2e1)*_hc0[36]*_t35*_t69*_t83 - _t124*_t252 + _t14*((0.1e1 / 0.2e1)*_hc0[86]*_t14*_t69*_t83 - _t252*_t533 - _t549) + (0.2e1 / 0.3e1)*_t15*_t43*_t86 - _t37*((0.1e1 / 0.2e1)*_hc0[80]*_t14*_t69*_t83 - _t252*_t539 - _t550) - _t38*((0.1e1 / 0.2e1)*_hc0[106]*_t14*_t69*_t83 - _t252*_t541 - _t551) - _t501 - _t522 - _t552) - _t269;
  const double d4F_dna2_dgbb2 = _t509;
  const double d4F_dna_dnb_dgaa2 = _t558;
  const double d4F_dna_dnb_dgaa_dgab = _t1*(_t14*_t559 + _t253*_t34 + _t561) + _t14*_t253 + _t205*_t87 + _t21*_t253 - _t529 - _t530 - _t531;
  const double d4F_dna_dnb_dgaa_dgbb = _t558;
  const double d4F_dna_dnb_dgab2 = _t1*(0.2e1*_hc0[36]*_t425*_t7*_t83 + _t14*_t563 - 0.2e1*_t564 + _t567) - _t262 - _t277 - _t546;
  const double d4F_dna_dnb_dgab_dgbb = _t1*(_hc0[36]*_t425*_t7*_t83 + _t14*_t568 - _t564 - _t569) - _t268 - _t271 - _t279;
  const double d4F_dna_dnb_dgbb2 = _t558;
  const double d4F_dnb2_dgaa2 = _t570;
  const double d4F_dnb2_dgaa_dgab = _t1*(_t21*_t559 + _t253*_t57 + _t561) + 0.2e1*_t21*_t253 - _t532;
  const double d4F_dnb2_dgaa_dgbb = _t570;
  const double d4F_dnb2_dgab2 = 0.2e1*_hc0[36]*_t21*_t69*_t83 + _t1*(-_t164*_t244 + _t21*_t563 + _t391*_t492 + _t567) - 0.2e1*_t276 - _t546;
  const double d4F_dnb2_dgab_dgbb = _t1*((0.1e1 / 0.2e1)*_hc0[36]*_t57*_t69*_t83 - _t164*_t252 + _t21*_t568 - _t569) - _t278;
  const double d4F_dnb2_dgbb2 = _t570;
  const double d4F_dna_dgaa3 = _t578;
  const double d4F_dna_dgaa2_dgab = _t1*(_t14*_t583 - _t588) + _t294;
  const double d4F_dna_dgaa2_dgbb = _t578;
  const double d4F_dna_dgaa_dgab2 = _t1*(_t14*_t593 - _t597) + _t297;
  const double d4F_dna_dgaa_dgab_dgbb = _t1*(_t14*_t600 - _t602) + _t298;
  const double d4F_dna_dgaa_dgbb2 = _t578;
  const double d4F_dna_dgab3 = _t1*(0.3e1*_hc0[14]*_t14*_t283*_t9 + _hc0[80]*_t107*_t14*_t86 - _t539*_t603 - _t607) + _t608;
  const double d4F_dna_dgab2_dgbb = _t1*((0.3e1 / 0.2e1)*_hc0[14]*_t14*_t283*_t9 + (0.1e1 / 0.2e1)*_hc0[80]*_t107*_t14*_t86 - _t539*_t590 - _t609) + _t297;
  const double d4F_dna_dgab_dgbb2 = _t1*((0.3e1 / 0.4e1)*_hc0[14]*_t14*_t283*_t9 + _t14*_t22*_t491*_t9 - _t539*_t582 - _t610) + _t611;
  const double d4F_dna_dgbb3 = _t578;
  const double d4F_dnb_dgaa3 = _t612;
  const double d4F_dnb_dgaa2_dgab = _t1*(_t21*_t583 - _t588) + _t294;
  const double d4F_dnb_dgaa2_dgbb = _t612;
  const double d4F_dnb_dgaa_dgab2 = _t1*(_t21*_t593 - _t597) + _t297;
  const double d4F_dnb_dgaa_dgab_dgbb = _t1*(_t21*_t600 - _t602) + _t298;
  const double d4F_dnb_dgaa_dgbb2 = _t612;
  const double d4F_dnb_dgab3 = _t1*(0.3e1*_hc0[14]*_t21*_t283*_t9 + _hc0[80]*_t107*_t21*_t86 - _t565*_t603 - _t607) + _t608;
  const double d4F_dnb_dgab2_dgbb = _t1*((0.3e1 / 0.2e1)*_hc0[14]*_t21*_t283*_t9 + (0.1e1 / 0.2e1)*_hc0[80]*_t107*_t21*_t86 - _t565*_t590 - _t609) + _t297;
  const double d4F_dnb_dgab_dgbb2 = _t1*((0.3e1 / 0.4e1)*_hc0[14]*_t21*_t283*_t9 + _t21*_t22*_t491*_t9 - _t565*_t582 - _t610) + _t611;
  const double d4F_dnb_dgbb3 = _t612;
  const double d4F_dgaa4 = _t619;
  const double d4F_dgaa3_dgab = _t1*((0.9e1 / 0.8e1)*_hc0[11]*_t613*_t69 + (0.1e1 / 0.2e1)*_t22*_t585*_t9 - 0.1e1 / 0.2e1*_t620 - _t621);
  const double d4F_dgaa3_dgbb = _t619;
  const double d4F_dgaa2_dgab2 = _t1*((0.5e1 / 0.2e1)*_hc0[11]*_t613*_t69 + (0.1e1 / 0.2e1)*_t22*_t596*_t9 - _t620 - _t622 - 0.1e1 / 0.4e1*_t624);
  const double d4F_dgaa2_dgab_dgbb = _t1*((0.5e1 / 0.4e1)*_hc0[11]*_t613*_t69 + (0.1e1 / 0.2e1)*_t22*_t601*_t9 - 0.1e1 / 0.4e1*_t620 - _t621 - 0.1e1 / 0.8e1*_t624);
  const double d4F_dgaa2_dgbb2 = _t619;
  const double d4F_dgaa_dgab3 = _t1*((0.15e2 / 0.2e1)*_t615 - 0.15e2 / 0.2e1*_t617 - 0.3e1*_t624 + (0.1e1 / 0.2e1)*_t626);
  const double d4F_dgaa_dgab2_dgbb = _t1*((0.15e2 / 0.4e1)*_t615 - _t622 - 0.3e1 / 0.2e1*_t624 + (0.1e1 / 0.4e1)*_t626);
  const double d4F_dgaa_dgab_dgbb2 = _t1*((0.7e1 / 0.4e1)*_hc0[11]*_t613*_t69 + (0.1e1 / 0.2e1)*_t498*_t69*_t83 - _t621 - 0.1e1 / 0.2e1*_t624);
  const double d4F_dgaa_dgbb3 = _t619;
  const double d4F_dgab4 = -_t106*_t623 + _t627 + 0.15e2*_t628 - 0.15e2*_t629;
  const double d4F_dgab3_dgbb = (0.1e1 / 0.2e1)*_t627 + (0.15e2 / 0.2e1)*_t628 - 0.15e2 / 0.2e1*_t629 - 0.3e1*_t630;
  const double d4F_dgab2_dgbb2 = (0.7e1 / 0.2e1)*_hc0[11]*_t613*_t92 + _t498*_t83*_t92 - 0.15e2 / 0.4e1*_t629 - _t630 - _t631;
  const double d4F_dgab_dgbb3 = _t2*_t618 + (0.9e1 / 0.8e1)*_t628 - 0.15e2 / 0.8e1*_t629 - 0.3e1 / 0.2e1*_t631;
  const double d4F_dgbb4 = _t619;
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