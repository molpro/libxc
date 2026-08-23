/*
  Generated from python/gga_exc/gga_c_pbe_vwn.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_c_pbe_vwn
*/

#ifndef _GGA_C_PBE_VWN_KERNEL_BODY
#define maple2c_order 3
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC)

/* ---- top-level dispatch ---- */

#define _GGA_C_PBE_VWN_KERNEL_BODY
#define _KMAX 0
#define _GGA_C_PBE_VWN_HELPER_BODIES
#include "gga_c_pbe_vwn.c"
#undef _GGA_C_PBE_VWN_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_C_PBE_VWN_HELPER_BODIES
#include "gga_c_pbe_vwn.c"
#undef _GGA_C_PBE_VWN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_C_PBE_VWN_HELPER_BODIES
#include "gga_c_pbe_vwn.c"
#undef _GGA_C_PBE_VWN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_C_PBE_VWN_HELPER_BODIES
#include "gga_c_pbe_vwn.c"
#undef _GGA_C_PBE_VWN_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_c_pbe_vwn.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_c_pbe_vwn.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_c_pbe_vwn.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_c_pbe_vwn.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_c_pbe_vwn.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_c_pbe_vwn.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_c_pbe_vwn.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_c_pbe_vwn.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_C_PBE_VWN_HELPER_BODIES)

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
  const double _t21 = _t10*(_t13 * _t13 * _t13)/(_t12 * _t12 * _t12);
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
  const double d3f_dn3 = my_piecewise3(_t1, _t2*(_t9 * _t9 * _t9), _t10*(_t6 * _t6 * _t6));
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t1, 0, 0.2e1*_t11*_t14 + _t14*_t16*n);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t1, 0, _t11*_t17*_t20 - _t18*_t7 - _t18 + 0.2e1*_t19);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t1, 0, -0.3e1*_t20*_t21 + _t21*(n * n * n) + 0.2e1*_t21*n);
  out[9] = d3f_dz3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(Q_vwn_k, _KMAX)(const xc_func_type *p, double b, double c, double *out) {

  const double _t1 = (b * b);
  const double _t2 = -_t1 + 0.4e1*c;
  const double _t3 = xc_powr(_t2, 1, 2);
#if _KMAX >= 1
  const double _t4 = (0.1e1 / _t3);
#endif
#if _KMAX >= 2
  const double _t5 = xc_powr(_t2, -3, 2);
  const double _t6 = 0.2e1*_t5;
#endif
#if _KMAX >= 3
  const double _t7 = xc_powr(_t2, -5, 2);
#endif

  const double f = _t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dc = 0.2e1*_t4;
  out[1] = df_dc;
  const double df_db = -_t4*b;
  out[2] = df_db;
#endif
#if _KMAX >= 2
  const double d2f_dc2 = -0.4e1*_t5;
  out[3] = d2f_dc2;
  const double d2f_db_dc = _t6*b;
  out[4] = d2f_db_dc;
  const double d2f_db2 = -_t1*_t5 - _t4;
  out[5] = d2f_db2;
#endif
#if _KMAX >= 3
  const double d3f_dc3 = 0.24e2*_t7;
  out[6] = d3f_dc3;
  const double d3f_db_dc2 = -0.12e2*_t7*b;
  out[7] = d3f_db_dc2;
  const double d3f_db2_dc = 0.6e1*_t1*_t7 + _t6;
  out[8] = d3f_db2_dc;
  const double d3f_db3 = -0.3e1*_t5*b - 0.3e1*_t7*(b * b * b);
  out[9] = d3f_db3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f1_vwn_k, _KMAX)(const xc_func_type *p, double b, double c, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(Q_vwn_k, _KMAX)(p, b, c, _hc0);
  const double _t1 = 0.2e1/_hc0[0];
#if _KMAX >= 1
  const double _t2 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t3 = 0.2e1*_t2;
  const double _t4 = _hc0[1]*_t3;
  const double _t5 = _t3*b;
#endif
#if _KMAX >= 2
  const double _t6 = _hc0[3]*_t3;
  const double _t7 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t8 = ((_hc0[1]) * (_hc0[1]));
  const double _t9 = 0.4e1*_t2;
  const double _t10 = ((_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 3
  const double _t11 = 0.12e2*b/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
#endif

  const double f = _t1*b;
  out[0] = f;
#if _KMAX >= 1
  const double df_dc = -_t4*b;
  out[1] = df_dc;
  const double df_db = -_hc0[2]*_t5 + _t1;
  out[2] = df_db;
#endif
#if _KMAX >= 2
  const double d2f_dc2 = -_t6*b + 0.4e1*_t7*_t8*b;
  out[3] = d2f_dc2;
  const double d2f_db_dc = 0.4e1*_hc0[1]*_hc0[2]*_t7*b - _hc0[4]*_t5 - _t4;
  out[4] = d2f_db_dc;
  const double d2f_db2 = -_hc0[2]*_t9 - _hc0[5]*_t5 + 0.4e1*_t10*_t7*b;
  out[5] = d2f_db2;
#endif
#if _KMAX >= 3
  const double d3f_dc3 = -((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t11 + 0.12e2*_hc0[1]*_hc0[3]*_t7*b - _hc0[6]*_t5;
  out[6] = d3f_dc3;
  const double d3f_db_dc2 = 0.8e1*_hc0[1]*_hc0[4]*_t7*b + 0.4e1*_hc0[2]*_hc0[3]*_t7*b - _hc0[2]*_t11*_t8 - _hc0[7]*_t5 - _t6 + 0.4e1*_t7*_t8;
  out[7] = d3f_db_dc2;
  const double d3f_db2_dc = 0.8e1*_hc0[1]*_hc0[2]*_t7 + 0.4e1*_hc0[1]*_hc0[5]*_t7*b - _hc0[1]*_t10*_t11 + 0.8e1*_hc0[2]*_hc0[4]*_t7*b - _hc0[4]*_t9 - _hc0[8]*_t5;
  out[8] = d3f_db2_dc;
  const double d3f_db3 = -((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t11 + 0.12e2*_hc0[2]*_hc0[5]*_t7*b - 0.6e1*_hc0[5]*_t2 - _hc0[9]*_t5 + 0.12e2*_t10*_t7;
  out[9] = d3f_db3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f2_vwn_k, _KMAX)(const xc_func_type *p, double b, double c, double x0, double *out) {

  const double _t1 = (x0 * x0);
  const double _t2 = b*x0;
  const double _t3 = _t1 + _t2 + c;
  const double _t4 = (0.1e1 / _t3);
#if _KMAX >= 1
  const double _t5 = 0.2e1*x0;
  const double _t6 = -_t5 - b;
  const double _t7 = (0.1e1 / (_t3 * _t3));
  const double _t8 = _t2*_t7;
  const double _t9 = _t7*b;
#endif
#if _KMAX >= 2
  const double _t10 = 0.2e1*_t8;
  const double _t11 = 0.2e1*b;
  const double _t12 = _t11*_t7;
  const double _t13 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t14 = 0.4e1*x0;
  const double _t15 = -_t11 - _t14;
  const double _t16 = _t13*_t15;
  const double _t17 = _t16*_t2;
  const double _t18 = 0.2e1*_t2;
  const double _t19 = _t1*b;
  const double _t20 = _t11*_t13;
  const double _t21 = (x0 * x0 * x0);
#endif
#if _KMAX >= 3
  const double _t22 = 0.4e1*_t17;
  const double _t23 = 0.4e1*_t13*_t2;
  const double _t24 = -0.3e1*b - 0.6e1*x0;
  const double _t25 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t26 = _t24*_t25;
  const double _t27 = _t15*_t26;
  const double _t28 = 0.6e1*_t25;
  const double _t29 = _t11*_t26;
  const double _t30 = _t28*b;
#endif

  const double f = _t2*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx0 = _t4*b + _t6*_t8;
  out[1] = df_dx0;
  const double df_dc = -_t8;
  out[2] = df_dc;
  const double df_db = -_t1*_t9 + _t4*x0;
  out[3] = df_db;
#endif
#if _KMAX >= 2
  const double d2f_dx02 = -_t10 + _t12*_t6 + _t17*_t6;
  out[4] = d2f_dx02;
  const double d2f_dc_dx0 = -_t17 - _t9;
  out[5] = d2f_dc_dx0;
  const double d2f_dc2 = _t13*_t18;
  out[6] = d2f_dc2;
  const double d2f_db_dx0 = -_t10 - _t16*_t19 + _t4 + _t6*_t7*x0;
  out[7] = d2f_db_dx0;
  const double d2f_db_dc = _t1*_t20 - _t7*x0;
  out[8] = d2f_db_dc;
  const double d2f_db2 = -0.2e1*_t1*_t7 + _t20*_t21;
  out[9] = d2f_db2;
#endif
#if _KMAX >= 3
  const double d3f_dx03 = 0.3e1*_t13*_t15*_t6*b + _t15*_t24*_t25*_t6*b*x0 - _t22 - _t23*_t6 - 0.6e1*_t9;
  out[10] = d3f_dx03;
  const double d3f_dc_dx02 = 0.4e1*_t13*b*x0 - _t15*_t20 - _t2*_t27;
  out[11] = d3f_dc_dx02;
  const double d3f_dc2_dx0 = _t18*_t26 + _t20;
  out[12] = d3f_dc2_dx0;
  const double d3f_dc3 = -_t2*_t28;
  out[13] = d3f_dc3;
  const double d3f_db_dx02 = 0.4e1*_t1*_t13*b - _t12 + _t13*_t15*_t6*x0 - _t19*_t27 - _t22 - _t5*_t7 + 0.2e1*_t6*_t7;
  out[14] = d3f_db_dx02;
  const double d3f_db_dc_dx0 = _t1*_t29 - _t16*x0 + _t23 - _t7;
  out[15] = d3f_db_dc_dx0;
  const double d3f_db_dc2 = 0.2e1*_t13*x0 - _t19*_t28;
  out[16] = d3f_db_dc2;
  const double d3f_db2_dx0 = -0.2e1*_t1*_t16 + 0.6e1*_t13*_t19 - _t14*_t7 + _t21*_t29;
  out[17] = d3f_db2_dx0;
  const double d3f_db2_dc = 0.4e1*_t1*_t13 - _t21*_t30;
  out[18] = d3f_db2_dc;
  const double d3f_db3 = 0.6e1*_t13*_t21 - _t30*(x0 * x0 * x0 * x0);
  out[19] = d3f_db3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f3_vwn_k, _KMAX)(const xc_func_type *p, double b, double c, double x0, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(Q_vwn_k, _KMAX)(p, b, c, _hc0);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = 0.2e1*b + 0.4e1*x0;
#if _KMAX >= 1
  const double _t3 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t4 = _t2*_t3;
#endif
#if _KMAX >= 2
  const double _t5 = 0.4e1*_t3;
  const double _t6 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t7 = ((_hc0[1]) * (_hc0[1]));
  const double _t8 = _hc0[2]*_t5;
  const double _t9 = 0.2e1*_t3;
  const double _t10 = ((_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 3
  const double _t11 = 0.6e1*_t2/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t12 = -0.8e1*_hc0[1]*_hc0[2]*_t6 + _hc0[4]*_t5;
#endif

  const double f = _t1*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx0 = 0.4e1*_t1;
  out[1] = df_dx0;
  const double df_dc = -_hc0[1]*_t4;
  out[2] = df_dc;
  const double df_db = -_hc0[2]*_t4 + 0.2e1*_t1;
  out[3] = df_db;
#endif
#if _KMAX >= 2
  const double d2f_dx02 = 0;
  out[4] = d2f_dx02;
  const double d2f_dc_dx0 = -_hc0[1]*_t5;
  out[5] = d2f_dc_dx0;
  const double d2f_dc2 = -_hc0[3]*_t4 + 0.2e1*_t2*_t6*_t7;
  out[6] = d2f_dc2;
  const double d2f_db_dx0 = -_t8;
  out[7] = d2f_db_dx0;
  const double d2f_db_dc = 0.2e1*_hc0[1]*_hc0[2]*_t2*_t6 - _hc0[1]*_t9 - _hc0[4]*_t4;
  out[8] = d2f_db_dc;
  const double d2f_db2 = -_hc0[5]*_t4 + 0.2e1*_t10*_t2*_t6 - _t8;
  out[9] = d2f_db2;
#endif
#if _KMAX >= 3
  const double d3f_dx03 = 0;
  out[10] = d3f_dx03;
  const double d3f_dc_dx02 = 0;
  out[11] = d3f_dc_dx02;
  const double d3f_dc2_dx0 = -_hc0[3]*_t5 + 0.8e1*_t6*_t7;
  out[12] = d3f_dc2_dx0;
  const double d3f_dc3 = -((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t11 + 0.6e1*_hc0[1]*_hc0[3]*_t2*_t6 - _hc0[6]*_t4;
  out[13] = d3f_dc3;
  const double d3f_db_dx02 = 0;
  out[14] = d3f_db_dx02;
  const double d3f_db_dc_dx0 = -_t12;
  out[15] = d3f_db_dc_dx0;
  const double d3f_db_dc2 = 0.4e1*_hc0[1]*_hc0[4]*_t2*_t6 + 0.2e1*_hc0[2]*_hc0[3]*_t2*_t6 - _hc0[2]*_t11*_t7 - _hc0[3]*_t9 - _hc0[7]*_t4 + 0.4e1*_t6*_t7;
  out[16] = d3f_db_dc2;
  const double d3f_db2_dx0 = -_hc0[5]*_t5 + 0.8e1*_t10*_t6;
  out[17] = d3f_db2_dx0;
  const double d3f_db2_dc = 0.2e1*_hc0[1]*_hc0[5]*_t2*_t6 - _hc0[1]*_t10*_t11 + 0.4e1*_hc0[2]*_hc0[4]*_t2*_t6 - _hc0[8]*_t4 - _t12;
  out[18] = d3f_db2_dc;
  const double d3f_db3 = -((_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t11 + 0.6e1*_hc0[2]*_hc0[5]*_t2*_t6 - 0.6e1*_hc0[5]*_t3 - _hc0[9]*_t4 + 0.12e2*_t10*_t6;
  out[19] = d3f_db3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fx_vwn_k, _KMAX)(const xc_func_type *p, double b, double c, double rs, double *out) {

  const double _t1 = xc_powr(rs, 1, 2);
#if _KMAX >= 1
  const double _t2 = (0.1e1 / 0.2e1)/_t1;
#endif
#if _KMAX >= 2
  const double _t3 = (0.1e1 / 0.4e1)/xc_powr(rs, 3, 2);
#endif

  const double f = _t1*b + c + rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2*b + 0.1e1;
  out[1] = df_drs;
  const double df_dc = 0.1e1;
  out[2] = df_dc;
  const double df_db = _t1;
  out[3] = df_db;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -_t3*b;
  out[4] = d2f_drs2;
  const double d2f_dc_drs = 0;
  out[5] = d2f_dc_drs;
  const double d2f_dc2 = 0;
  out[6] = d2f_dc2;
  const double d2f_db_drs = _t2;
  out[7] = d2f_db_drs;
  const double d2f_db_dc = 0;
  out[8] = d2f_db_dc;
  const double d2f_db2 = 0;
  out[9] = d2f_db2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.3e1 / 0.8e1)*b/xc_powr(rs, 5, 2);
  out[10] = d3f_drs3;
  const double d3f_dc_drs2 = 0;
  out[11] = d3f_dc_drs2;
  const double d3f_dc2_drs = 0;
  out[12] = d3f_dc2_drs;
  const double d3f_dc3 = 0;
  out[13] = d3f_dc3;
  const double d3f_db_drs2 = -_t3;
  out[14] = d3f_db_drs2;
  const double d3f_db_dc_drs = 0;
  out[15] = d3f_db_dc_drs;
  const double d3f_db_dc2 = 0;
  out[16] = d3f_db_dc2;
  const double d3f_db2_drs = 0;
  out[17] = d3f_db2_drs;
  const double d3f_db2_dc = 0;
  out[18] = d3f_db2_dc;
  const double d3f_db3 = 0;
  out[19] = d3f_db3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_aux_k, _KMAX)(const xc_func_type *p, double A, double b, double c, double x0, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f2_vwn_k, _KMAX)(p, b, c, x0, _hc0);
  double _hc1[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f3_vwn_k, _KMAX)(p, b, c, x0, _hc1);
  double _hc2[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f1_vwn_k, _KMAX)(p, b, c, _hc2);
  double _hc3[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(Q_vwn_k, _KMAX)(p, b, c, _hc3);
  double _hc4[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(fx_vwn_k, _KMAX)(p, b, c, rs, _hc4);
  const double _t1 = (0.1e1 / (_hc4[0]));
  const double _t2 = -_hc4[0] + rs;
  const double _t3 = _t1*_t2;
  const double _t4 = -_hc0[0]*_hc1[0] + _hc2[0];
  const double _t5 = xc_powr(rs, 1, 2);
  const double _t6 = 0.2e1*_t5;
  const double _t7 = _t6 + b;
  const double _t8 = (0.1e1 / _t7);
  const double _t9 = atan(_hc3[0]*_t8);
  const double _t10 = _t5 - x0;
  const double _t11 = -_hc4[0] + (_t10 * _t10);
  const double _t12 = _t1*_t11;
  const double _t13 = xc_log1p(_t12);
  const double _t14 = -_hc0[0]*_t13 + _t4*_t9 + xc_log1p(_t3);
#if _KMAX >= 1
  const double _t15 = _t3 + 0.1e1;
  const double _t16 = (0.1e1 / _t15);
  const double _t17 = 0.1e1 - _hc4[1];
  const double _t18 = _t1*_t17;
  const double _t19 = (0.1e1 / ((_hc4[0]) * (_hc4[0])));
  const double _t20 = _hc4[1]*_t19;
  const double _t21 = _t18 - _t2*_t20;
  const double _t22 = ((_hc3[0]) * (_hc3[0]));
  const double _t23 = (0.1e1 / (_t7 * _t7));
  const double _t24 = _t22*_t23 + 0.1e1;
  const double _t25 = (0.1e1 / _t24);
  const double _t26 = _t25*_t4;
  const double _t27 = (0.1e1 / _t5);
  const double _t28 = _hc3[0]*_t23;
  const double _t29 = _t27*_t28;
  const double _t30 = -_hc4[1] + _t10*_t27;
  const double _t31 = _t1*_t30;
  const double _t32 = -_t11*_t20 + _t31;
  const double _t33 = _t12 + 0.1e1;
  const double _t34 = (0.1e1 / _t33);
  const double _t35 = _hc0[0]*_t34;
  const double _t36 = _t16*_t21 - _t26*_t29 - _t32*_t35;
  const double _t37 = -_hc0[0]*_hc1[1] - _hc0[1]*_hc1[0];
  const double _t38 = -_t6 + 0.2e1*x0;
  const double _t39 = _t1*_t35;
  const double _t40 = -_hc0[1]*_t13 + _t37*_t9 - _t38*_t39;
  const double _t41 = -_hc0[0]*_hc1[2] - _hc0[2]*_hc1[0] + _hc2[1];
  const double _t42 = _hc4[2]*_t1;
  const double _t43 = _hc4[2]*_t19;
  const double _t44 = _t2*_t43;
  const double _t45 = _t42 + _t44;
  const double _t46 = -_t45;
  const double _t47 = _hc3[1]*_t8;
  const double _t48 = _t11*_t43;
  const double _t49 = _t42 + _t48;
  const double _t50 = -_t49;
  const double _t51 = -_hc0[2]*_t13 + _t16*_t46 + _t26*_t47 - _t35*_t50 + _t41*_t9;
  const double _t52 = -_hc0[0]*_hc1[3] - _hc0[3]*_hc1[0] + _hc2[2];
  const double _t53 = _hc4[3]*_t1;
  const double _t54 = _hc4[3]*_t19;
  const double _t55 = _t2*_t54;
  const double _t56 = _t53 + _t55;
  const double _t57 = -_t56;
  const double _t58 = _hc3[2]*_t8 - _t28;
  const double _t59 = _t11*_t54;
  const double _t60 = _t53 + _t59;
  const double _t61 = -_t60;
  const double _t62 = -_hc0[3]*_t13 + _t16*_t57 + _t26*_t58 - _t35*_t61 + _t52*_t9;
#endif
#if _KMAX >= 2
  const double _t63 = xc_powr(rs, -3, 2);
  const double _t64 = (0.1e1 / 0.2e1)*_t63;
  const double _t65 = _t26*_t28;
  const double _t66 = (0.1e1 / rs);
  const double _t67 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t68 = 0.2e1*_t67;
  const double _t69 = _hc3[0]*_t68;
  const double _t70 = xc_powi(_t7, -5);
  const double _t71 = ((_hc3[0]) * (_hc3[0]) * (_hc3[0]));
  const double _t72 = (0.1e1 / (_t24 * _t24));
  const double _t73 = _t4*_t72;
  const double _t74 = 0.2e1*_t66;
  const double _t75 = _hc4[4]*_t19;
  const double _t76 = 0.2e1*_hc4[1];
  const double _t77 = _t19*_t76;
  const double _t78 = (0.1e1 / ((_hc4[0]) * (_hc4[0]) * (_hc4[0])));
  const double _t79 = ((_hc4[1]) * (_hc4[1]));
  const double _t80 = _hc4[4]*_t1 + _t17*_t77 + _t2*_t75 - 0.2e1*_t2*_t78*_t79;
  const double _t81 = -_t80;
  const double _t82 = (0.1e1 / (_t15 * _t15));
  const double _t83 = -_t21;
  const double _t84 = _t82*_t83;
  const double _t85 = -_t32;
  const double _t86 = (0.1e1 / (_t33 * _t33));
  const double _t87 = _hc0[0]*_t86;
  const double _t88 = _t85*_t87;
  const double _t89 = 0.2e1*_t78;
  const double _t90 = _t11*_t89;
  const double _t91 = -_hc4[4] - _t10*_t64 + (0.1e1 / 0.2e1)*_t66;
  const double _t92 = _t1*_t91 - _t11*_t75 - _t30*_t77 + _t79*_t90;
  const double _t93 = _t16*_t81 + _t21*_t84 + _t26*_t66*_t69 - _t32*_t88 - _t35*_t92 + _t64*_t65 - _t70*_t71*_t73*_t74;
  const double _t94 = _t25*_t37;
  const double _t95 = _t32*_t34;
  const double _t96 = _t1*_t38;
  const double _t97 = _hc0[0]*_hc4[1]*_t19*_t34*_t38 + _hc0[0]*_t1*_t27*_t34 - _hc0[1]*_t95 - _t29*_t94 - _t88*_t96;
  const double _t98 = 0.2e1*_hc0[1];
  const double _t99 = -_hc0[4]*_hc1[0] - _hc1[1]*_t98;
  const double _t100 = _t34*_t96;
  const double _t101 = (_t38 * _t38);
  const double _t102 = _hc0[0]*_t101*_t19*_t86 - _hc0[4]*_t13 - _t100*_t98 - 0.2e1*_t39 + _t9*_t99;
  const double _t103 = _hc3[1]*_t23;
  const double _t104 = _t103*_t27;
  const double _t105 = _t25*_t41;
  const double _t106 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t107 = _hc4[2]*_t20;
  const double _t108 = _t76*_t78;
  const double _t109 = _hc4[2]*_t2;
  const double _t110 = _t107 + _t108*_t109 - _t17*_t43;
  const double _t111 = _hc4[2]*_t108*_t11 + _t107 - _t30*_t43;
  const double _t112 = -_hc0[2]*_t95 + 0.2e1*_hc3[1]*_t106*_t22*_t27*_t4*_t72 - _t104*_t26 - _t105*_t29 + _t110*_t16 - _t111*_t35 + _t46*_t82*_t83 - _t50*_t88;
  const double _t113 = -_hc0[0]*_hc1[5] - _hc0[1]*_hc1[2] - _hc0[2]*_hc1[1] - _hc0[5]*_hc1[0];
  const double _t114 = _hc0[2]*_t34;
  const double _t115 = _t35*_t38;
  const double _t116 = _hc0[1]*_t34;
  const double _t117 = _t50*_t87;
  const double _t118 = -_hc0[5]*_t13 + _t113*_t9 - _t114*_t96 + _t115*_t43 - _t116*_t50 + _t117*_t96 + _t47*_t94;
  const double _t119 = 0.2e1*_hc0[2];
  const double _t120 = -_hc0[0]*_hc1[6] - _hc0[6]*_hc1[0] - _hc1[2]*_t119 + _hc2[3];
  const double _t121 = ((_hc4[2]) * (_hc4[2]));
  const double _t122 = 0.2e1*_t19;
  const double _t123 = _t121*_t122;
  const double _t124 = _t2*_t89;
  const double _t125 = _t121*_t124 + _t123;
  const double _t126 = ((_hc3[1]) * (_hc3[1]));
  const double _t127 = _t126*_t69;
  const double _t128 = _t34*_t50;
  const double _t129 = _t121*_t90 + _t123;
  const double _t130 = _t49*_t87;
  const double _t131 = -_hc0[6]*_t13 + 0.2e1*_hc3[1]*_t25*_t41*_t8 + _hc3[3]*_t25*_t4*_t8 - _t119*_t128 + _t120*_t9 + _t125*_t16 - _t127*_t73 - _t129*_t35 - _t130*_t50 + _t45*_t46*_t82;
  const double _t132 = _t25*_t52;
  const double _t133 = _hc3[2]*_t23;
  const double _t134 = -_t133*_t27 + _t27*_t69;
  const double _t135 = _hc4[7]*_t19;
  const double _t136 = -_hc4[1]*_hc4[3]*_t19 + _hc4[7]*_t1;
  const double _t137 = -0.2e1*_hc4[1]*_hc4[3]*_t2*_t78 + _t135*_t2 + _t136 + _t17*_t54;
  const double _t138 = -_t137;
  const double _t139 = -0.2e1*_hc4[1]*_hc4[3]*_t11*_t78 + _t11*_t135 + _t136 + _t30*_t54;
  const double _t140 = -_t139;
  const double _t141 = -_hc0[3]*_t95 - _t132*_t29 + _t134*_t25*_t4 + _t138*_t16 - _t140*_t35 + 0.2e1*_t22*_t27*_t4*_t58*_t67*_t72 + _t57*_t82*_t83 - _t61*_t88;
  const double _t142 = -_hc0[0]*_hc1[7] - _hc0[1]*_hc1[3] - _hc0[3]*_hc1[1] - _hc0[7]*_hc1[0];
  const double _t143 = _hc0[3]*_t34;
  const double _t144 = _t25*_t58;
  const double _t145 = _t61*_t87;
  const double _t146 = -_hc0[7]*_t13 + _t115*_t54 - _t116*_t61 + _t142*_t9 - _t143*_t96 + _t144*_t37 + _t145*_t96;
  const double _t147 = -_hc0[0]*_hc1[8] - _hc0[2]*_hc1[3] - _hc0[3]*_hc1[2] - _hc0[8]*_hc1[0] + _hc2[4];
  const double _t148 = 0.2e1*_t43;
  const double _t149 = _hc4[3]*_t148;
  const double _t150 = _hc4[2]*_hc4[3];
  const double _t151 = _t124*_t150 + _t149;
  const double _t152 = _hc3[4]*_t8 - _t103;
  const double _t153 = _t149 + _t150*_t90;
  const double _t154 = _t58*_t73;
  const double _t155 = 0.2e1*_t28;
  const double _t156 = _hc3[1]*_t155;
  const double _t157 = -_hc0[3]*_t128 - _hc0[8]*_t13 + _hc3[1]*_t25*_t52*_t8 - _t114*_t61 - _t130*_t61 + _t147*_t9 + _t151*_t16 + _t152*_t25*_t4 - _t153*_t35 - _t154*_t156 + _t25*_t41*_t58 + _t45*_t57*_t82;
  const double _t158 = 0.2e1*_hc0[3];
  const double _t159 = -_hc0[0]*_hc1[9] - _hc0[9]*_hc1[0] - _hc1[3]*_t158 + _hc2[5];
  const double _t160 = ((_hc4[3]) * (_hc4[3]));
  const double _t161 = _t122*_t160;
  const double _t162 = _t124*_t160 + _t161;
  const double _t163 = _t57*_t82;
  const double _t164 = _t34*_t61;
  const double _t165 = 0.2e1*_t52;
  const double _t166 = _t160*_t90 + _t161;
  const double _t167 = _hc3[5]*_t8 - 0.2e1*_t133 + _t69;
  const double _t168 = _t22*_t68;
  const double _t169 = -_hc3[2]*_t155 + _t168;
  const double _t170 = -_hc0[9]*_t13 + _t144*_t165 - _t145*_t60 + _t154*_t169 - _t158*_t164 + _t159*_t9 + _t16*_t162 + _t163*_t56 - _t166*_t35 + _t167*_t26;
#endif
#if _KMAX >= 3
  const double _t171 = xc_powr(rs, -5, 2);
  const double _t172 = _hc3[0]*_t67;
  const double _t173 = (0.1e1 / (rs * rs));
  const double _t174 = 0.6e1*_t106;
  const double _t175 = _hc3[0]*_t174;
  const double _t176 = xc_powi(_t7, -6);
  const double _t177 = (0.1e1 / (_t24 * _t24 * _t24));
  const double _t178 = _t177*_t4;
  const double _t179 = 0.8e1*_t178;
  const double _t180 = (0.1e1 / (_t15 * _t15 * _t15));
  const double _t181 = 0.2e1*_hc4[1]*_t19*_t2 - 0.2e1*_t18;
  const double _t182 = _hc4[10]*_t19;
  const double _t183 = 0.3e1*_t75;
  const double _t184 = 0.6e1/((_hc4[0]) * (_hc4[0]) * (_hc4[0]) * (_hc4[0]));
  const double _t185 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]))*_t184;
  const double _t186 = _t32*_t85;
  const double _t187 = 0.2e1*_hc4[1]*_t11*_t19 - 0.2e1*_t31;
  const double _t188 = (0.1e1 / (_t33 * _t33 * _t33));
  const double _t189 = _hc0[0]*_t188;
  const double _t190 = _t187*_t189;
  const double _t191 = -_t92;
  const double _t192 = _t191*_t87;
  const double _t193 = 0.2e1*_t88;
  const double _t194 = _t79*_t89;
  const double _t195 = _t37*_t72;
  const double _t196 = _t70*_t71;
  const double _t197 = _t196*_t74;
  const double _t198 = _hc0[1]*_t86;
  const double _t199 = _t85*_t96;
  const double _t200 = _t101*_t87;
  const double _t201 = _t27*_t38;
  const double _t202 = _t122*_t87;
  const double _t203 = _t25*_t29;
  const double _t204 = _t86*_t98;
  const double _t205 = 0.3e1*_hc0[4];
  const double _t206 = _t101*_t19;
  const double _t207 = _hc3[1]*_t73;
  const double _t208 = ((_hc3[0]) * (_hc3[0]) * (_hc3[0]) * (_hc3[0]));
  const double _t209 = _t41*_t72;
  const double _t210 = _hc4[4]*_t43;
  const double _t211 = -_hc4[2]*_t194;
  const double _t212 = 0.4e1*_t78;
  const double _t213 = _hc4[1]*_t212;
  const double _t214 = _hc4[2]*_t213;
  const double _t215 = _hc4[2]*_hc4[4];
  const double _t216 = _t2*_t79;
  const double _t217 = _hc4[2]*_t184;
  const double _t218 = _hc0[2]*_t86;
  const double _t219 = _t50*_t85;
  const double _t220 = _t11*_t79;
  const double _t221 = _t27*_t35;
  const double _t222 = _t108*_t115;
  const double _t223 = _t1*_t27;
  const double _t224 = _t20*_t38;
  const double _t225 = _t198*_t50;
  const double _t226 = _t119*_t34;
  const double _t227 = 0.2e1*_hc0[5];
  const double _t228 = _t25*_t47;
  const double _t229 = _t34*_t98;
  const double _t230 = _t38*_t43;
  const double _t231 = _t200*_t89;
  const double _t232 = 0.2e1*_t1;
  const double _t233 = _t50*_t96;
  const double _t234 = _t101*_t122*_t189;
  const double _t235 = _hc3[3]*_t23;
  const double _t236 = _hc4[1]*_t121;
  const double _t237 = _t212*_t236;
  const double _t238 = _t184*_t236;
  const double _t239 = -_t110;
  const double _t240 = _t119*_t86;
  const double _t241 = -_t111;
  const double _t242 = _t49*_t50;
  const double _t243 = _t87*_t96;
  const double _t244 = 0.2e1*_t96;
  const double _t245 = _t189*_t244;
  const double _t246 = 0.3e1*_hc0[2];
  const double _t247 = 0.3e1*_hc0[6];
  const double _t248 = ((_hc4[2]) * (_hc4[2]) * (_hc4[2]));
  const double _t249 = 0.6e1*_t78;
  const double _t250 = _t248*_t249;
  const double _t251 = _t184*_t248;
  const double _t252 = ((_hc3[1]) * (_hc3[1]) * (_hc3[1]));
  const double _t253 = -_t125;
  const double _t254 = 0.2e1*_t42;
  const double _t255 = _t254 + 0.2e1*_t44;
  const double _t256 = 0.2e1*_t130;
  const double _t257 = -_t129;
  const double _t258 = _t189*(_t254 + 0.2e1*_t48);
  const double _t259 = _t22*_t67;
  const double _t260 = _t174*_t22;
  const double _t261 = _hc0[3]*_t86;
  const double _t262 = _hc4[14]*_t19;
  const double _t263 = _hc4[7]*_t122;
  const double _t264 = _hc4[3]*_t184;
  const double _t265 = -0.2e1*_hc4[1]*_hc4[7]*_t19 + _hc4[14]*_t1 + _hc4[3]*_t194;
  const double _t266 = _t61*_t85;
  const double _t267 = _t158*_t34;
  const double _t268 = 0.2e1*_hc0[7];
  const double _t269 = _t38*_t54;
  const double _t270 = _t61*_t96;
  const double _t271 = _hc3[1]*_t68;
  const double _t272 = _t23*_t27;
  const double _t273 = _t155*_t207;
  const double _t274 = _t150*_t89;
  const double _t275 = _hc4[2]*_hc4[7];
  const double _t276 = _hc4[7]*_t148 - _t150*_t213;
  const double _t277 = _t261*_t50;
  const double _t278 = _hc4[1]*_t11;
  const double _t279 = _t49*_t61;
  const double _t280 = _t218*_t61;
  const double _t281 = _t198*_t61;
  const double _t282 = _hc4[3]*_t121;
  const double _t283 = _t249*_t282;
  const double _t284 = _t184*_t282;
  const double _t285 = 0.2e1*_hc0[8];
  const double _t286 = _t52*_t72;
  const double _t287 = 0.4e1*_t28;
  const double _t288 = 0.2e1*_t23;
  const double _t289 = _hc3[1]*_t287;
  const double _t290 = _t289*_t58;
  const double _t291 = 0.4e1*_t259;
  const double _t292 = _t27*_t291;
  const double _t293 = _t160*_t89;
  const double _t294 = _t160*_t184;
  const double _t295 = _hc4[7]*_t212;
  const double _t296 = 0.4e1*_hc4[7]*_t54 - _t160*_t213;
  const double _t297 = _t56*_t57;
  const double _t298 = _t56*_t82;
  const double _t299 = _t169*_t73;
  const double _t300 = _t158*_t86;
  const double _t301 = _t169*_t58;
  const double _t302 = _t178*_t301;
  const double _t303 = _t60*_t61;
  const double _t304 = _t60*_t87;
  const double _t305 = _t189*_t303;
  const double _t306 = _hc4[2]*_t160;
  const double _t307 = _t249*_t306;
  const double _t308 = _t184*_t306;
  const double _t309 = 0.3e1*_hc0[3];
  const double _t310 = 0.3e1*_hc0[9];
  const double _t311 = ((_hc4[3]) * (_hc4[3]) * (_hc4[3]));
  const double _t312 = _t249*_t311;
  const double _t313 = _t184*_t311;
  const double _t314 = 0.2e1*_t53;
#endif

  const double f = A*_t14;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = A*_t36;
  out[1] = df_drs;
  const double df_dx0 = A*_t40;
  out[2] = df_dx0;
  const double df_dc = A*_t51;
  out[3] = df_dc;
  const double df_db = A*_t62;
  out[4] = df_db;
  const double df_dA = _t14;
  out[5] = df_dA;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = A*_t93;
  out[6] = d2f_drs2;
  const double d2f_dx0_drs = A*_t97;
  out[7] = d2f_dx0_drs;
  const double d2f_dx02 = A*_t102;
  out[8] = d2f_dx02;
  const double d2f_dc_drs = A*_t112;
  out[9] = d2f_dc_drs;
  const double d2f_dc_dx0 = A*_t118;
  out[10] = d2f_dc_dx0;
  const double d2f_dc2 = A*_t131;
  out[11] = d2f_dc2;
  const double d2f_db_drs = A*_t141;
  out[12] = d2f_db_drs;
  const double d2f_db_dx0 = A*_t146;
  out[13] = d2f_db_dx0;
  const double d2f_db_dc = A*_t157;
  out[14] = d2f_db_dc;
  const double d2f_db2 = A*_t170;
  out[15] = d2f_db2;
  const double d2f_dA_drs = _t36;
  out[16] = d2f_dA_drs;
  const double d2f_dA_dx0 = _t40;
  out[17] = d2f_dA_dx0;
  const double d2f_dA_dc = _t51;
  out[18] = d2f_dA_dc;
  const double d2f_dA_db = _t62;
  out[19] = d2f_dA_db;
  const double d2f_dA2 = 0;
  out[20] = d2f_dA2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = A*(-xc_powi((_hc3[0]), 5)*_t179*_t63/xc_powi(_t7, 8) + _t16*(0.3e1*_hc4[1]*_hc4[4]*_t19 + 0.6e1*_hc4[1]*_hc4[4]*_t2*_t78 - _hc4[10]*_t1 - _t17*_t183 + 0.6e1*_t17*_t78*_t79 - _t182*_t2 - _t185*_t2) - 0.3e1 / 0.4e1*_t171*_t65 - 0.3e1*_t172*_t173*_t26 + 0.3e1*_t173*_t4*_t70*_t71*_t72 - _t175*_t26*_t63 + 0.14e2*_t176*_t4*_t63*_t71*_t72 + _t180*_t181*_t21*_t83 - _t186*_t190 - _t192*_t32 - _t193*_t92 + _t21*_t80*_t82 - _t35*(0.6e1*_hc4[1]*_hc4[4]*_t11*_t78 + _t1*(-_hc4[10] + (0.3e1 / 0.4e1)*_t10*_t171 - 0.3e1 / 0.4e1*_t173) - _t11*_t182 - _t11*_t185 - _t183*_t30 - 0.3e1*_t20*_t91 + 0.6e1*_t30*_t78*_t79) + 0.2e1*_t81*_t82*_t83);
  out[21] = d3f_drs3;
  const double d3f_dx0_drs2 = A*(0.2e1*_hc0[0]*_hc4[1]*_t19*_t38*_t85*_t86 + _hc0[0]*_hc4[4]*_t19*_t34*_t38 + 0.2e1*_hc0[0]*_t1*_t27*_t85*_t86 + (0.1e1 / 0.2e1)*_hc3[0]*_t23*_t25*_t37*_t63 + 0.2e1*_hc3[0]*_t25*_t37*_t66*_t67 - _t115*_t194 - _t116*_t92 - _t186*_t198 - _t190*_t199 - _t192*_t96 - _t195*_t197 - _t27*_t35*_t77 - _t39*_t64);
  out[22] = d3f_dx0_drs2;
  const double d3f_dx02_drs = A*(0.2e1*_hc0[0]*_hc4[1]*_t19*_t34 + _hc0[0]*_t101*_t188*_t19*(_t1*(_t201 + _t76) + _t11*_t77) + 0.2e1*_hc0[1]*_hc4[1]*_t19*_t34*_t38 + 0.2e1*_hc0[1]*_t1*_t27*_t34 - _hc0[4]*_t95 - _t1*_t193 - _t108*_t200 - _t199*_t204 - _t201*_t202 - _t203*_t99);
  out[23] = d3f_dx02_drs;
  const double d3f_dx03 = A*(-_hc0[10]*_t13 - 0.6e1*_t1*_t116 - _t100*_t205 - _t189*(_t38 * _t38 * _t38)*_t89 + _t19*_t87*(-0.8e1*_t5 + 0.8e1*x0) + 0.3e1*_t198*_t206 + _t202*_t38 + _t9*(-_hc0[10]*_hc1[0] - _hc1[1]*_t205));
  out[24] = d3f_dx03;
  const double d3f_dc_drs2 = A*((0.1e1 / 0.2e1)*_hc3[0]*_t23*_t25*_t41*_t63 + 0.2e1*_hc3[0]*_t25*_t41*_t66*_t67 + 0.8e1*_hc3[1]*_t177*_t208*_t4*_t66/xc_powi(_t7, 7) + (0.1e1 / 0.2e1)*_hc3[1]*_t23*_t25*_t4*_t63 + 0.2e1*_hc3[1]*_t25*_t4*_t66*_t67 - _t106*_t207*_t22*_t63 + 0.2e1*_t110*_t82*_t83 - _t111*_t193 - _t114*_t92 + _t16*(_t124*_t215 + _t17*_t214 + 0.2e1*_t210 + _t211 - _t216*_t217) + _t180*_t181*_t46*_t83 - _t186*_t218 - _t190*_t219 - _t192*_t50 - _t197*_t209 - 0.10e2*_t207*_t22*_t66*_t70 - _t35*(_t210 + _t211 + _t214*_t30 + _t215*_t90 - _t217*_t220 - _t43*_t91) + _t46*_t80*_t82);
  out[25] = d3f_dc_drs2;
  const double d3f_dc_dx0_drs = A*(_hc0[0]*_hc4[2]*_t19*_t38*_t85*_t86 + _hc0[0]*_t1*_t111*_t38*_t86 + _hc0[0]*_t1*_t187*_t188*_t38*_t50 + _hc0[2]*_hc4[1]*_t19*_t34*_t38 + _hc0[2]*_t1*_t27*_t34 - _hc0[5]*_t95 + 0.2e1*_hc3[1]*_t106*_t22*_t27*_t37*_t72 - _hc4[2]*_t222 - _t104*_t94 - _t111*_t116 - _t113*_t203 - _t117*_t223 - _t117*_t224 - _t199*_t218 - _t221*_t43 - _t225*_t85);
  out[26] = d3f_dc_dx0_drs;
  const double d3f_dc_dx02 = A*(-_hc0[11]*_t13 - _hc0[4]*_t128 - _hc4[2]*_t231 - _t1*_t226 - _t100*_t227 + _t117*_t232 + _t148*_t35 + _t204*_t233 + _t206*_t218 + _t228*_t99 + _t229*_t230 - _t234*_t50 + _t9*(-_hc0[11]*_hc1[0] - _hc0[4]*_hc1[2] - _hc1[1]*_t227 - _hc1[5]*_t98));
  out[27] = d3f_dc_dx02;
  const double d3f_dc2_drs = A*(-_hc0[6]*_t95 + 0.6e1*_hc3[0]*_t106*_t126*_t27*_t4*_t72 + 0.4e1*_hc3[1]*_t106*_t22*_t27*_t41*_t72 + 0.2e1*_hc3[3]*_t106*_t22*_t27*_t4*_t72 - 0.2e1*_t104*_t105 + _t110*_t45*_t82 - _t111*_t130 - _t111*_t226 - _t117*_t241 - _t120*_t203 + _t125*_t82*_t83 - _t126*_t176*_t179*_t27*_t71 - _t129*_t88 + _t16*(0.2e1*_t121*_t17*_t78 - _t2*_t238 - _t237) + _t180*_t181*_t45*_t46 - _t190*_t242 - _t219*_t240 - _t235*_t26*_t27 + _t239*_t46*_t82 - _t35*(-_t11*_t238 + 0.2e1*_t121*_t30*_t78 - _t237));
  out[28] = d3f_dc2_drs;
  const double d3f_dc2_dx0 = A*(-_hc0[12]*_t13 - _hc0[6]*_t100 + _hc3[3]*_t8*_t94 + 0.2e1*_t113*_t228 - _t115*_t121*_t89 - _t116*_t129 - _t117*_t230 - _t127*_t195 - _t128*_t227 + _t129*_t243 + _t130*_t230 - _t225*_t49 + _t226*_t230 + _t233*_t240 + _t242*_t245 + _t9*(-_hc0[0]*_hc1[12] - _hc0[1]*_hc1[6] - _hc0[12]*_hc1[0] - _hc0[6]*_hc1[1] - _hc1[2]*_t227 - _hc1[5]*_t119));
  out[29] = d3f_dc2_dx0;
  const double d3f_dc3 = A*(-_hc0[13]*_t13 - 0.6e1*_hc3[1]*_hc3[3]*_t172*_t73 + 0.3e1*_hc3[1]*_t120*_t25*_t8 + 0.3e1*_hc3[3]*_t25*_t41*_t8 + _hc3[6]*_t25*_t4*_t8 - 0.3e1*_t114*_t129 - _t117*_t257 + 0.2e1*_t125*_t45*_t82 - 0.6e1*_t126*_t172*_t209 - _t128*_t247 - _t129*_t256 + _t16*(-_t2*_t251 - _t250) + 0.8e1*_t177*_t22*_t252*_t4*_t70 + _t180*_t255*_t45*_t46 - _t242*_t246*_t86 - _t242*_t258 - _t252*_t68*_t73 + _t253*_t46*_t82 - _t35*(-_t11*_t251 - _t250) + _t9*(-_hc0[0]*_hc1[13] - _hc0[13]*_hc1[0] - _hc1[2]*_t247 - _hc1[6]*_t246 + _hc2[6]));
  out[30] = d3f_dc3;
  const double d3f_db_drs2 = A*((0.1e1 / 0.2e1)*_hc3[0]*_t23*_t25*_t52*_t63 + 0.2e1*_hc3[0]*_t25*_t52*_t66*_t67 + 0.4e1*_t134*_t22*_t27*_t4*_t67*_t72 + 0.2e1*_t138*_t82*_t83 - _t140*_t193 - _t143*_t92 - _t145*_t191 - _t154*_t259*_t63 - _t154*_t260*_t66 + _t16*(0.4e1*_hc4[1]*_hc4[3]*_t17*_t78 + 0.4e1*_hc4[1]*_hc4[7]*_t2*_t78 + 0.2e1*_hc4[3]*_hc4[4]*_t19 + 0.2e1*_hc4[3]*_hc4[4]*_t2*_t78 - _t17*_t263 - _t2*_t262 - _t216*_t264 - _t265) - _t165*_t196*_t66*_t72 + 0.8e1*_t176*_t177*_t208*_t4*_t58*_t66 + _t180*_t181*_t57*_t83 - _t186*_t261 - _t190*_t266 + _t25*_t4*((0.1e1 / 0.2e1)*_hc3[2]*_t23*_t63 + 0.2e1*_hc3[2]*_t66*_t67 - _t172*_t63 - _t175*_t66) - _t35*(0.4e1*_hc4[1]*_hc4[3]*_t30*_t78 + 0.4e1*_hc4[1]*_hc4[7]*_t11*_t78 + 0.2e1*_hc4[3]*_hc4[4]*_t11*_t78 + _hc4[3]*_hc4[4]*_t19 - _t11*_t262 - _t220*_t264 - _t263*_t30 - _t265 - _t54*_t91) + _t57*_t80*_t82);
  out[31] = d3f_db_drs2;
  const double d3f_db_dx0_drs = A*(_hc0[0]*_hc4[3]*_t19*_t38*_t85*_t86 + _hc0[0]*_hc4[7]*_t19*_t34*_t38 + _hc0[0]*_t1*_t140*_t38*_t86 + _hc0[0]*_t1*_t187*_t188*_t38*_t61 + _hc0[3]*_hc4[1]*_t19*_t34*_t38 + _hc0[3]*_t1*_t27*_t34 - _hc0[7]*_t95 - _hc4[3]*_t222 - _t116*_t140 + _t134*_t25*_t37 - _t142*_t203 - _t145*_t223 - _t145*_t224 - _t198*_t266 - _t199*_t261 + 0.2e1*_t22*_t27*_t37*_t58*_t67*_t72 - _t221*_t54);
  out[32] = d3f_db_dx0_drs;
  const double d3f_db_dx02 = A*(-_hc0[14]*_t13 - _hc0[4]*_t164 - _hc4[3]*_t231 - _t1*_t267 - _t100*_t268 + _t144*_t99 + _t145*_t232 + _t204*_t270 + _t206*_t261 + _t229*_t269 - _t234*_t61 + 0.2e1*_t35*_t54 + _t9*(-_hc0[14]*_hc1[0] - _hc0[4]*_hc1[3] - _hc1[1]*_t268 - _hc1[7]*_t98));
  out[33] = d3f_db_dx02;
  const double d3f_db_dc_drs = A*(-_hc0[8]*_t95 + 0.4e1*_hc3[0]*_hc3[1]*_t27*_t4*_t58*_t67*_t72 + 0.2e1*_hc3[1]*_t106*_t22*_t27*_t52*_t72 - _hc3[1]*_t179*_t196*_t27*_t58 - _t104*_t132 - _t111*_t143 - _t114*_t140 - _t130*_t140 + _t134*_t25*_t41 - _t134*_t273 + _t138*_t45*_t82 - _t145*_t241 - _t147*_t203 + _t151*_t82*_t83 + 0.2e1*_t152*_t22*_t27*_t4*_t67*_t72 - _t153*_t88 + _t16*(-_hc4[1]*_t109*_t264 + _t124*_t275 + _t17*_t274 + _t276) + _t180*_t181*_t45*_t57 - _t190*_t279 - _t218*_t266 + 0.2e1*_t22*_t27*_t41*_t58*_t67*_t72 + _t239*_t57*_t82 + _t25*_t4*(-_hc3[4]*_t272 + _t27*_t271) - _t277*_t85 - _t35*(-_t150*_t184*_t278 + _t274*_t30 + _t275*_t90 + _t276));
  out[34] = d3f_db_dc_drs;
  const double d3f_db_dc_dx0 = A*(-_hc0[15]*_t13 - _hc0[5]*_t164 - _hc0[7]*_t128 - _hc0[8]*_t100 + _t113*_t144 + _t114*_t269 - _t115*_t274 - _t116*_t153 + _t130*_t269 + _t142*_t228 + _t143*_t230 - _t145*_t230 + _t152*_t94 + _t153*_t243 - _t156*_t195*_t58 + _t245*_t279 + _t277*_t96 + _t280*_t96 - _t281*_t49 + _t9*(-_hc0[0]*_hc1[15] - _hc0[1]*_hc1[8] - _hc0[15]*_hc1[0] - _hc0[2]*_hc1[7] - _hc0[3]*_hc1[5] - _hc0[5]*_hc1[3] - _hc0[7]*_hc1[2] - _hc0[8]*_hc1[1]));
  out[35] = d3f_db_dc_dx0;
  const double d3f_db_dc2 = A*(-_hc0[16]*_t13 - _hc0[6]*_t164 + 0.2e1*_hc3[1]*_t147*_t25*_t8 - _hc3[3]*_t154*_t155 + _hc3[3]*_t25*_t52*_t8 + 0.8e1*_t106*_t126*_t177*_t22*_t4*_t58 + _t120*_t25*_t58 - _t126*_t154*_t288 - _t127*_t286 - _t128*_t285 - _t129*_t143 - _t145*_t257 + 0.2e1*_t151*_t45*_t82 - _t152*_t207*_t287 + 0.2e1*_t152*_t25*_t41 - _t153*_t226 - _t153*_t256 + _t16*(-_t2*_t284 - _t283) + _t180*_t255*_t45*_t57 - _t209*_t290 - _t240*_t279 + _t25*_t4*(_hc3[7]*_t8 - _t235) + _t253*_t57*_t82 - _t258*_t279 - _t277*_t49 - _t35*(-_t11*_t284 - _t283) + _t9*(-_hc0[0]*_hc1[16] - _hc0[16]*_hc1[0] - _hc0[3]*_hc1[6] - _hc0[6]*_hc1[3] - _hc1[2]*_t285 - _hc1[8]*_t119 + _hc2[7]));
  out[36] = d3f_db_dc2;
  const double d3f_db2_drs = A*(-_hc0[9]*_t95 + _t134*_t165*_t25 + _t134*_t299 + _t137*_t163 + _t138*_t298 - _t139*_t145 - _t140*_t267 - _t140*_t304 + _t154*(0.4e1*_hc3[0]*_hc3[2]*_t27*_t67 - _t260*_t27) - _t159*_t203 + _t16*(-_hc4[1]*_t2*_t294 + _hc4[3]*_t2*_t295 + _t17*_t293 + _t296) + _t162*_t84 - _t166*_t88 + _t167*_t168*_t27*_t73 + _t180*_t181*_t297 - _t190*_t303 + _t26*(0.4e1*_hc3[2]*_t27*_t67 - _hc3[5]*_t272 - _t175*_t27) - _t266*_t300 + _t286*_t292*_t58 + _t292*_t302 - _t35*(_hc4[3]*_t11*_t295 - _t278*_t294 + _t293*_t30 + _t296));
  out[37] = d3f_db2_drs;
  const double d3f_db2_dx0 = A*(-_hc0[17]*_t13 - _hc0[9]*_t100 - _t115*_t293 - _t116*_t166 + 0.2e1*_t142*_t144 - _t145*_t269 - _t164*_t268 + _t166*_t243 + _t167*_t94 + _t195*_t301 + _t244*_t305 + _t267*_t269 + _t269*_t304 + _t270*_t300 - _t281*_t60 + _t9*(-_hc0[0]*_hc1[17] - _hc0[1]*_hc1[9] - _hc0[17]*_hc1[0] - _hc0[9]*_hc1[1] - _hc1[3]*_t268 - _hc1[7]*_t158));
  out[38] = d3f_db2_dx0;
  const double d3f_db2_dc = A*(-_hc0[18]*_t13 - _hc0[9]*_t128 + _hc3[1]*_t159*_t25*_t8 - _t114*_t166 - _t130*_t166 + _t145*_t153 + 0.2e1*_t147*_t25*_t58 + _t151*_t56*_t82 - _t151*_t57*_t82 + _t152*_t169*_t4*_t72 + 0.2e1*_t152*_t25*_t52 - _t153*_t267 - _t153*_t304 + _t16*(-_t2*_t308 - _t307) + _t162*_t45*_t82 - _t164*_t285 + _t167*_t25*_t41 - _t167*_t273 + _t169*_t41*_t58*_t72 + _t180*_t255*_t56*_t57 + _t25*_t4*(-_hc3[4]*_t288 + _hc3[8]*_t8 + _t271) - _t258*_t303 - _t279*_t300 - _t280*_t60 - _t286*_t290 - _t289*_t302 - _t35*(-_t11*_t308 - _t307) + _t4*_t58*_t72*(0.4e1*_hc3[0]*_hc3[1]*_t67 - 0.2e1*_hc3[2]*_t103 - _hc3[4]*_t155) + _t9*(-_hc0[0]*_hc1[18] - _hc0[18]*_hc1[0] - _hc0[2]*_hc1[9] - _hc0[9]*_hc1[2] - _hc1[3]*_t285 - _hc1[8]*_t158 + _hc2[8]));
  out[39] = d3f_db2_dc;
  const double d3f_db3 = A*(-_hc0[19]*_t13 + 0.3e1*_t132*_t167 - 0.3e1*_t143*_t166 + 0.3e1*_t144*_t159 + _t145*_t166 + _t154*(0.8e1*_hc3[0]*_hc3[2]*_t67 - ((_hc3[2]) * (_hc3[2]))*_t288 - _hc3[5]*_t155 - _t260) + _t16*(-_t2*_t313 - _t312) - _t162*_t163 + 0.2e1*_t162*_t298 - _t164*_t310 - 0.2e1*_t166*_t304 + 0.2e1*_t167*_t299 + _t180*_t297*(_t314 + 0.2e1*_t55) + _t26*(0.6e1*_hc3[2]*_t67 - 0.3e1*_hc3[5]*_t23 + _hc3[9]*_t8 - _t175) + 0.3e1*_t301*_t52*_t72 + _t302*(-_hc3[2]*_t287 + _t291) - _t303*_t309*_t86 - _t305*(_t314 + 0.2e1*_t59) - _t35*(-_t11*_t313 - _t312) + _t9*(-_hc0[0]*_hc1[19] - _hc0[19]*_hc1[0] - _hc1[3]*_t310 - _hc1[9]*_t309 + _hc2[9]));
  out[40] = d3f_db3;
  const double d3f_dA_drs2 = _t93;
  out[41] = d3f_dA_drs2;
  const double d3f_dA_dx0_drs = _t97;
  out[42] = d3f_dA_dx0_drs;
  const double d3f_dA_dx02 = _t102;
  out[43] = d3f_dA_dx02;
  const double d3f_dA_dc_drs = _t112;
  out[44] = d3f_dA_dc_drs;
  const double d3f_dA_dc_dx0 = _t118;
  out[45] = d3f_dA_dc_dx0;
  const double d3f_dA_dc2 = _t131;
  out[46] = d3f_dA_dc2;
  const double d3f_dA_db_drs = _t141;
  out[47] = d3f_dA_db_drs;
  const double d3f_dA_db_dx0 = _t146;
  out[48] = d3f_dA_db_dx0;
  const double d3f_dA_db_dc = _t157;
  out[49] = d3f_dA_db_dc;
  const double d3f_dA_db2 = _t170;
  out[50] = d3f_dA_db2;
  const double d3f_dA2_drs = 0;
  out[51] = d3f_dA2_drs;
  const double d3f_dA2_dx0 = 0;
  out[52] = d3f_dA2_dx0;
  const double d3f_dA2_dc = 0;
  out[53] = d3f_dA2_dc;
  const double d3f_dA2_db = 0;
  out[54] = d3f_dA2_db;
  const double d3f_dA3 = 0;
  out[55] = d3f_dA3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(DMC_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_aux_k, _KMAX)(p, 0.031090699999999999, 3.7274400000000001, 12.9352, -0.10498, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_aux_k, _KMAX)(p, 0.015545349999999999, 7.0604199999999997, 18.0578, -0.32500000000000001, rs, _hc1);

  const double f = -_hc0[0] + _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
  const double df_drs = -_hc0[1] + _hc1[1];
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = 0;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -_hc0[6] + _hc1[6];
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = 0;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = 0;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = -_hc0[21] + _hc1[21];
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeta_k, _KMAX)(const xc_func_type *p, double rs, double t, double *out) {
  const gga_c_pbe_vwn_params *params = (const gga_c_pbe_vwn_params *)(p->params);


  const double f = params->beta;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_drs = 0;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_drs_dt = 0;
  out[4] = d2f_drs_dt;
  const double d2f_drs2 = 0;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_drs_dt2 = 0;
  out[7] = d3f_drs_dt2;
  const double d3f_drs2_dt = 0;
  out[8] = d3f_drs2_dt;
  const double d3f_drs3 = 0;
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tp_k, _KMAX)(const xc_func_type *p, double rs, double z, double xt, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);
  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t3 = _t1/_t2;
  const double _t4 = xc_powr(rs, -1, 2);
  const double _t5 = (0.1e1 / 0.8e1)*_t4;
  const double _t6 = _t3*_t5;
#if _KMAX >= 1
  const double _t7 = -0.1e1 / 0.2e1*_hc0[2] + (0.1e1 / 0.2e1)*_hc1[2];
  const double _t8 = _t1/(_t2 * _t2);
  const double _t9 = _t5*_t8;
  const double _t10 = _t7*_t9;
  const double _t11 = (0.1e1 / 0.16e2)/xc_powr(rs, 3, 2);
  const double _t12 = _t11*_t3;
#endif
#if _KMAX >= 2
  const double _t13 = -0.1e1 / 0.2e1*_hc0[5] - 0.1e1 / 0.2e1*_hc1[5];
  const double _t14 = _t13*_t9;
  const double _t15 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t16 = -_hc0[2] + _hc1[2];
  const double _t17 = _t1*_t15*_t16;
  const double _t18 = _t5*_t7;
  const double _t19 = _t17*_t18;
  const double _t20 = _t11*_t8;
  const double _t21 = _t20*_t7;
  const double _t22 = (0.3e1 / 0.32e2)/xc_powr(rs, 5, 2);
  const double _t23 = _t22*_t3;
#endif
#if _KMAX >= 3
  const double _t24 = _t13*xt;
  const double _t25 = _t1*_t18*xt;
  const double _t26 = _t7*xt;
#endif

  const double f = _t6*xt;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxt = _t6;
  out[1] = df_dxt;
  const double df_dz = _t10*xt;
  out[2] = df_dz;
  const double df_drs = -_t12*xt;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dxt2 = 0;
  out[4] = d2f_dxt2;
  const double d2f_dz_dxt = _t10;
  out[5] = d2f_dz_dxt;
  const double d2f_dz2 = _t14*xt + _t19*xt;
  out[6] = d2f_dz2;
  const double d2f_drs_dxt = -_t12;
  out[7] = d2f_drs_dxt;
  const double d2f_drs_dz = -_t21*xt;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = _t23*xt;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dxt3 = 0;
  out[10] = d3f_dxt3;
  const double d3f_dz_dxt2 = 0;
  out[11] = d3f_dz_dxt2;
  const double d3f_dz2_dxt = _t14 + _t19;
  out[12] = d3f_dz2_dxt;
  const double d3f_dz3 = _t15*_t25*(-_hc0[5] - _hc1[5]) + _t16*_t25*(-0.3e1 / 0.2e1*_hc0[2] + (0.3e1 / 0.2e1)*_hc1[2])/(_t2 * _t2 * _t2 * _t2) + (0.1e1 / 0.4e1)*_t17*_t24*_t4 + _t9*xt*(-0.1e1 / 0.2e1*_hc0[9] + (0.1e1 / 0.2e1)*_hc1[9]);
  out[13] = d3f_dz3;
  const double d3f_drs_dxt2 = 0;
  out[14] = d3f_drs_dxt2;
  const double d3f_drs_dz_dxt = -_t21;
  out[15] = d3f_drs_dz_dxt;
  const double d3f_drs_dz2 = -_t11*_t17*_t26 - _t20*_t24;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dxt = _t23;
  out[17] = d3f_drs2_dxt;
  const double d3f_drs2_dz = _t22*_t26*_t8;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = -0.15e2 / 0.64e2*_t3*xt/xc_powr(rs, 7, 2);
  out[19] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fx_vwn_b3p72744000000000_c12p9352000000000_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(rs, 1, 2);

  const double f = 3.7274400000000001*_t1 + rs + 12.9352;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.1e1 + 1.86372/_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.93186000000000002/xc_powr(rs, 3, 2);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 1.3977900000000001/xc_powr(rs, 5, 2);
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_aux_A0p0310907000000000_b3p72744000000000_c12p9352000000000_x0m0p104980000000000_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(fx_vwn_b3p72744000000000_c12p9352000000000_k, _KMAX)(p, rs, _hc0);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = -_hc0[0] + rs;
  const double _t3 = _t1*_t2;
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = 0.2e1*_t4 + 3.7274400000000001;
  const double _t6 = _t4 + 0.10498;
  const double _t7 = -_hc0[0] + (_t6 * _t6);
  const double _t8 = _t1*_t7;
#if _KMAX >= 1
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = (0.1e1 / (_t5 * _t5));
  const double _t11 = 37.846991046399992*_t10 + 0.1e1;
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = _t10*_t12;
  const double _t14 = 0.1e1 - _hc0[1];
  const double _t15 = _t1*_t14;
  const double _t16 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t17 = _hc0[1]*_t16;
  const double _t18 = _t15 - _t17*_t2;
  const double _t19 = _t3 + 0.1e1;
  const double _t20 = 0.031090699999999999/_t19;
  const double _t21 = -_hc0[1] + _t6*_t9;
  const double _t22 = _t1*_t21;
  const double _t23 = -_t17*_t7 + _t22;
  const double _t24 = _t8 + 0.1e1;
  const double _t25 = 0.00096902277115443745/_t24;
#endif
#if _KMAX >= 2
  const double _t26 = xc_powr(rs, -3, 2);
  const double _t27 = (0.1e1 / rs);
  const double _t28 = (0.1e1 / (_t11 * _t11));
  const double _t29 = _t28/xc_powi(_t5, 5);
  const double _t30 = _t12/(_t5 * _t5 * _t5);
  const double _t31 = _hc0[2]*_t16;
  const double _t32 = 0.2e1*_t17;
  const double _t33 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t34 = ((_hc0[1]) * (_hc0[1]));
  const double _t35 = _hc0[2]*_t1 + _t14*_t32 + _t2*_t31 - 0.2e1*_t2*_t33*_t34;
  const double _t36 = -_t35;
  const double _t37 = (0.1e1 / (_t19 * _t19));
  const double _t38 = -_t18;
  const double _t39 = _t37*_t38;
  const double _t40 = 0.031090699999999999*_t18;
  const double _t41 = (0.1e1 / (_t24 * _t24));
  const double _t42 = -_t23;
  const double _t43 = _t41*_t42;
  const double _t44 = 0.00096902277115443745*_t23;
  const double _t45 = -_hc0[2] - 0.1e1 / 0.2e1*_t26*_t6 + (0.1e1 / 0.2e1)*_t27;
  const double _t46 = _t1*_t45 - _t21*_t32 - _t31*_t7 + 0.2e1*_t33*_t34*_t7;
#endif
#if _KMAX >= 3
  const double _t47 = xc_powr(rs, -5, 2);
  const double _t48 = (0.1e1 / (rs * rs));
  const double _t49 = _hc0[3]*_t16;
  const double _t50 = 0.3e1*_t31;
  const double _t51 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
#endif

  const double f = 0.038783294878113016*atan(6.1519908197590798/_t5) + 0.031090699999999999*xc_log1p(_t3) + 0.00096902277115443745*xc_log1p(_t8);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.2385944740501606*_t13*_t9 + _t18*_t20 + _t23*_t25;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.1192972370250803*_t13*_t26 + _t20*_t36 + _t25*_t46 - 18.060165846193886*_t27*_t29 + 0.4771889481003212*_t27*_t30 + _t39*_t40 + _t43*_t44;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -1.4315668443009635*_t12*_t26/(_t5 * _t5 * _t5 * _t5) - 0.17894585553762044*_t13*_t47 + _t20*(0.3e1*_hc0[1]*_hc0[2]*_t16 + 0.6e1*_hc0[1]*_hc0[2]*_t2*_t33 - _hc0[3]*_t1 + 0.6e1*_t14*_t33*_t34 - _t14*_t50 - _t2*_t49 - 0.6e1*_t2*_t51) + _t25*(0.6e1*_hc0[1]*_hc0[2]*_t33*_t7 + _t1*(-_hc0[3] + (0.3e1 / 0.4e1)*_t47*_t6 - 0.3e1 / 0.4e1*_t48) - 0.3e1*_t17*_t45 + 0.6e1*_t21*_t33*_t34 - _t21*_t50 - _t49*_t7 - 0.6e1*_t51*_t7) + 126.42116092335721*_t26*_t28/xc_powi(_t5, 6) + 27.090248769290831*_t29*_t48 - 0.71578342215048174*_t30*_t48 + _t35*_t37*_t40 + 0.062181399999999998*_t36*_t39 - _t41*_t44*_t46 + 0.0019380455423088749*_t43*_t46 + _t42*_t44*(0.2e1*_hc0[1]*_t16*_t7 - 0.2e1*_t22)/(_t24 * _t24 * _t24) + _t38*_t40*(0.2e1*_hc0[1]*_t16*_t2 - 0.2e1*_t15)/(_t19 * _t19 * _t19) - 2734.0917403095959*_t26/((_t11 * _t11 * _t11)*xc_powi(_t5, 8));
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tp_z0_k, _KMAX)(const xc_func_type *p, double rs, double xt, double *out) {

  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = (0.1e1 / 0.8e1)*_t1/xc_powr(rs, 1, 2);
#if _KMAX >= 1
  const double _t3 = (0.1e1 / 0.16e2)*_t1/xc_powr(rs, 3, 2);
#endif
#if _KMAX >= 2
  const double _t4 = (0.3e1 / 0.32e2)*_t1/xc_powr(rs, 5, 2);
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
  const double d3f_drs3 = -0.15e2 / 0.64e2*_t1*xt/xc_powr(rs, 7, 2);
  out[9] = d3f_drs3;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_c_pbe_vwn_params *params = (const gga_c_pbe_vwn_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = _t4/xc_powr(na, 1, 3);
  const double _t6 = xc_powr(gaa, 1, 2);
  const double _t7 = xc_powr(na, -4, 3);
  const double _t10 = (0.1e1 / (params->gamma));
  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_aux_A0p0310907000000000_b3p72744000000000_c12p9352000000000_x0m0p104980000000000_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tp_z0_k, _KMAX)(p, _t5, _t6*_t7, _hc1);
  double _hc2[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, 0, 0, _hc2);
  const double _t8 = ((_hc1[0]) * (_hc1[0]));
  const double _t9 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t11 = xc_expm1(-_hc0[0]*_t10);
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = _hc2[0]*_t10;
  const double _t14 = _t12*_t13;
  const double _t15 = _t14*params->BB;
  const double _t16 = _t15*_t9 + _t8;
  const double _t17 = _t12*_t16;
  const double _t18 = _t13*_t17 + 0.1e1;
  const double _t19 = (0.1e1 / _t18);
  const double _t20 = _t13*_t19;
  const double _t21 = _t16*_t20;
  const double _t22 = _hc0[0] + params->gamma*xc_log1p(_t21);
  const double zk = _t22;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t23 = _t3*_t7;
  const double _t24 = (0.1e1 / 0.6e1)*_t23;
  const double _t28 = xc_powr(na, -7, 3);
  const double _t34 = (0.1e1 / ((params->gamma) * (params->gamma)));
  const double _t56 = (0.1e1 / _t6);
  double _hc3[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tp_z0_k, _KMAX)(p, _t5, 0, _hc3);
  const double _t25 = _hc0[1]*_t24;
  const double _t26 = _t21 + 0.1e1;
  const double _t27 = (0.1e1 / _t26);
  const double _t29 = _hc3[1]*_t6;
  const double _t30 = _t28*_t29;
  const double _t31 = _hc1[2]*_t23;
  const double _t32 = -0.8e1 / 0.3e1*_t30 - 0.1e1 / 0.3e1*_t31;
  const double _t33 = _hc1[0]*_t32;
  const double _t35 = (0.1e1 / (_t11 * _t11));
  const double _t36 = _t11 + 0.1e1;
  const double _t37 = _t35*_t36;
  const double _t38 = _t34*_t37;
  const double _t39 = _hc2[0]*_t38;
  const double _t40 = _t9*params->BB;
  const double _t41 = _t39*_t40;
  const double _t42 = -0.16e2 / 0.3e1*_t30 - 0.2e1 / 0.3e1*_t31;
  const double _t43 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t44 = _t15*_t43;
  const double _t45 = -_t25*_t41 + _t33 + _t42*_t44;
  const double _t46 = _t20*_t45;
  const double _t47 = (0.1e1 / (_t18 * _t18));
  const double _t48 = _t13*_t47;
  const double _t49 = _hc2[0]*_t16;
  const double _t50 = _t38*_t49;
  const double _t51 = _t14*_t45;
  const double _t52 = _t25*_t50 - _t51;
  const double _t53 = _t16*_t52;
  const double _t54 = _t48*_t53;
  const double _t55 = _t46 + _t54;
  const double _t57 = _hc3[1]*_t56;
  const double _t58 = _t57*_t7;
  const double _t59 = _hc1[0]*_t58;
  const double _t60 = 0.2e1*_t44*_t58 + _t59;
  const double _t61 = ((_hc2[0]) * (_hc2[0]))*_t34;
  const double _t62 = _t47*_t61;
  const double _t63 = _t60*_t62;
  const double _t64 = _t17*_t63;
  const double _t65 = -_hc2[0]*_t10*_t19*_t60 + _t64;
  const double _t66 = -_t65;
  const double _t67 = _t27*params->gamma;
  const double _t68 = _t66*_t67;
  const double dF_dna = _t22 + na*(-_t25 + _t27*_t55*params->gamma);
  const double dF_dgaa = _t68*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double _t69 = (0.1e1 / 0.3e1)*_t23;
  const double _t71 = _t28*_t3;
  const double _t72 = (0.2e1 / 0.9e1)*_t71;
  const double _t74 = xc_powr(0.6e1, 2, 3);
  const double _t75 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t76 = _t74*_t75;
  const double _t78 = xc_powr(na, -8, 3);
  const double _t79 = (0.1e1 / 0.36e2)*_t78;
  const double _t90 = _t76*_t79;
  const double _t91 = (0.1e1 / ((params->gamma) * (params->gamma) * (params->gamma)));
  const double _t96 = (0.1e1 / 0.18e2)*_t78;
  const double _t107 = _t4*_t7;
  const double _t111 = xc_powr(na, -10, 3);
  const double _t115 = xc_powr(na, -11, 3);
  const double _t116 = _t115*_t3;
  const double _t118 = (0.4e1 / 0.3e1)*_t28;
  const double _t134 = (0.1e1 / 0.6e1)*_t78;
  const double _t141 = (0.8e1 / 0.3e1)*_t28;
  const double _t164 = xc_powr(gaa, -3, 2);
  const double _t168 = (0.1e1 / gaa);
  const double _t70 = _hc0[1]*_t69;
  const double _t73 = _hc0[1]*_t72;
  const double _t77 = _hc0[2]*_t76;
  const double _t80 = _t77*_t79;
  const double _t81 = -_t55;
  const double _t82 = params->gamma/(_t26 * _t26);
  const double _t83 = _t55*_t82;
  const double _t84 = _t81*_t83;
  const double _t85 = _t48*_t52;
  const double _t86 = 0.2e1*_t85;
  const double _t87 = _t50*_t70 - 0.2e1*_t51;
  const double _t88 = (0.1e1 / (_t18 * _t18 * _t18));
  const double _t89 = _t13*_t53*_t88;
  const double _t92 = _t35*_t91;
  const double _t93 = _t36*_t92;
  const double _t94 = ((_hc0[1]) * (_hc0[1]));
  const double _t95 = _hc2[0]*_t94;
  const double _t97 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t98 = (_t36 * _t36);
  const double _t99 = _t91*_t97*_t98;
  const double _t100 = _t76*_t95;
  const double _t101 = _t100*_t99;
  const double _t102 = _t101*_t96;
  const double _t103 = -0.4e1 / 0.3e1*_t30 - 0.1e1 / 0.6e1*_t31;
  const double _t104 = _t39*_t70;
  const double _t105 = _t43*params->BB;
  const double _t106 = _t105*_t42;
  const double _t108 = -_hc1[2]*_t107 - 0.4e1*_t30;
  const double _t109 = _t15*_t8;
  const double _t110 = _t109*_t42;
  const double _t112 = _t111*_t29;
  const double _t113 = _hc1[2]*_t71;
  const double _t114 = _hc3[4]*_t6;
  const double _t117 = _t114*_t116;
  const double _t119 = -_hc1[5]*_t24 - _t114*_t118;
  const double _t120 = _t119*_t23;
  const double _t121 = (0.56e2 / 0.9e1)*_t112 + (0.4e1 / 0.9e1)*_t113 + (0.4e1 / 0.9e1)*_t117 - 0.1e1 / 0.3e1*_t120;
  const double _t122 = (0.112e3 / 0.9e1)*_t112 + (0.8e1 / 0.9e1)*_t113 + (0.8e1 / 0.9e1)*_t117 - 0.2e1 / 0.3e1*_t120;
  const double _t123 = _hc1[0]*_t121 + _t102*_t40 + _t103*_t32 - _t104*_t106 + _t108*_t110 + _t122*_t44 - _t40*_t90*_t93*_t95 + _t41*_t73 + _t41*_t80;
  const double _t124 = _t49*_t76*_t94;
  const double _t125 = _t123*_t14;
  const double _t126 = (0.1e1 / 0.3e1)*_hc0[1]*_hc2[0]*_t1*_t2*_t34*_t35*_t36*_t45*_t7 + (0.1e1 / 0.36e2)*_hc2[0]*_t16*_t35*_t36*_t74*_t75*_t78*_t91*_t94 - _t124*_t96*_t99 - _t125 - _t50*_t73 - _t50*_t80;
  const double _t127 = _t16*_t48;
  const double _t128 = _t123*_t20 + _t126*_t127 + _t45*_t86 + _t87*_t89;
  const double _t129 = _t128*_t67;
  const double _t130 = _t65*_t83;
  const double _t131 = _t12*_t63;
  const double _t132 = _hc3[4]*_t56;
  const double _t133 = _t132*_t3;
  const double _t135 = -_t118*_t57 - _t133*_t134;
  const double _t136 = (0.1e1 / 0.2e1)*_t58;
  const double _t137 = _hc0[1]*_t3;
  const double _t138 = _t105*_t57;
  const double _t139 = _t138*_t39;
  const double _t140 = _t137*_t139;
  const double _t142 = _t133*_t78;
  const double _t143 = -_t141*_t57 - 0.1e1 / 0.3e1*_t142;
  const double _t144 = (0.3e1 / 0.2e1)*_t58;
  const double _t145 = _hc1[0]*_t135 + _t110*_t144 + _t136*_t32 - 0.1e1 / 0.3e1*_t140*_t78 + _t143*_t44;
  const double _t146 = _t48*_t60;
  const double _t147 = _t17*_t60;
  const double _t148 = _t52*_t88;
  const double _t149 = _t148*_t61;
  const double _t150 = 0.2e1*_t149;
  const double _t151 = _t39*_t60;
  const double _t152 = _t14*_t145;
  const double _t153 = _t151*_t25 - _t152;
  const double _t154 = _t127*_t153 - _t131*_t45 + _t145*_t20 + _t146*_t52 - _t147*_t150;
  const double _t155 = _t154*_t67;
  const double _t156 = _t65*_t82;
  const double _t157 = _t156*_t66;
  const double _t158 = _t12*_t62;
  const double _t159 = (_t60 * _t60);
  const double _t160 = 0.2e1*_t159;
  const double _t161 = _t16*_t88;
  const double _t162 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t163 = _t162*_t92;
  const double _t165 = _hc3[1]*_t164;
  const double _t166 = _t165*_t7;
  const double _t167 = ((_hc3[1]) * (_hc3[1]));
  const double _t169 = -0.1e1 / 0.2e1*_hc1[0]*_t166 + 0.3e1*_hc2[0]*_t10*_t12*_t167*_t168*_t78*_t8*params->BB - _t166*_t44 + (0.1e1 / 0.2e1)*_t167*_t168*_t78;
  const double _t170 = _t17*_t62;
  const double _t171 = -_t158*_t160 + _t160*_t161*_t163 - _t169*_t170 + _t169*_t20;
  const double _t172 = _t171*_t67;
  const double d2F_dna2 = 0.2e1*_t55*_t67 - _t70 + na*(_t129 + _t73 + _t80 + _t84);
  const double d2F_dna_dgaa = _t68 + na*(_t130 + _t155);
  const double d2F_dgaa2 = _t157*na + _t172*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double _t173 = (0.2e1 / 0.3e1)*_t28;
  const double _t175 = (0.1e1 / 0.12e2)*_t78;
  const double _t177 = (0.1e1 / (na * na * na * na));
  const double _t178 = _t177/M_PI;
  const double _t179 = (0.1e1 / 0.36e2)*_t178;
  const double _t182 = (0.1e1 / 0.9e1)*_t115;
  const double _t202 = (0.1e1 / ((params->gamma) * (params->gamma) * (params->gamma) * (params->gamma)));
  const double _t209 = (0.2e1 / 0.9e1)*_t115;
  const double _t225 = (0.28e2 / 0.9e1)*_t111;
  const double _t228 = (0.2e1 / 0.3e1)*_t23;
  const double _t241 = _t175*_t3;
  const double _t174 = _t137*_t173;
  const double _t176 = _t175*_t77;
  const double _t180 = _hc0[3]*_t179;
  const double _t181 = (0.14e2 / 0.27e2)*_t111*_t137;
  const double _t183 = _t182*_t77;
  const double _t184 = params->gamma/(_t26 * _t26 * _t26);
  const double _t185 = _t184*_t55;
  const double _t186 = _t185*_t81;
  const double _t187 = _t81*_t82;
  const double _t188 = _t13*_t87;
  const double _t189 = _t148*_t188;
  const double _t190 = _hc0[1]*_t107;
  const double _t191 = (0.1e1 / (_t18 * _t18 * _t18 * _t18));
  const double _t192 = _t191*_t53;
  const double _t193 = _t45*_t48;
  const double _t194 = _t124*_t99;
  const double _t195 = _t161*_t188;
  const double _t196 = 0.2e1*_t126;
  const double _t197 = (0.1e1 / 0.12e2)*_t93;
  const double _t198 = _hc0[1]*_hc0[2]*_t178;
  const double _t199 = _hc2[0]*_t198*_t40;
  const double _t200 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc2[0];
  const double _t201 = _t179*_t200*_t37;
  const double _t203 = _t202*_t40;
  const double _t204 = (0.1e1 / 0.6e1)*_t99;
  const double _t205 = (0.1e1 / 0.6e1)*_t178*_t200;
  const double _t206 = _t205*_t98;
  const double _t207 = _t205*(_t36 * _t36 * _t36)/(_t11 * _t11 * _t11 * _t11);
  const double _t208 = _t182*_t93;
  const double _t210 = _t106*_t39;
  const double _t211 = _t175*_t93;
  const double _t212 = _t100*_t106;
  const double _t213 = _t134*_t99;
  const double _t214 = _t15*_t42;
  const double _t215 = _t108*_t214;
  const double _t216 = _t190*_t39;
  const double _t217 = _t8*params->BB;
  const double _t218 = _t217*_t42;
  const double _t219 = _hc1[2]*_t3;
  const double _t220 = _t108*_t109;
  const double _t221 = _t29/xc_powr(na, 13, 3);
  const double _t222 = _t111*_t219;
  const double _t223 = _t114*_t3/xc_powr(na, 14, 3);
  const double _t224 = _t6*(_hc3[4]*_t72 + _hc3[8]*_t90);
  const double _t226 = _hc3[8]*_t6;
  const double _t227 = _hc1[5]*_t72 + _t114*_t225 + (0.2e1 / 0.9e1)*_t116*_t226 - _t24*(-_hc1[9]*_t24 - _t118*_t226);
  const double _t229 = _hc1[0]*((0.8e1 / 0.9e1)*_t1*_t119*_t2*_t28 - _t141*_t224 - 0.560e3 / 0.27e2*_t221 - 0.28e2 / 0.27e2*_t222 - 0.56e2 / 0.27e2*_t223 - _t227*_t69) + _t100*_t208*_t40 - _t101*_t209*_t40 + 0.2e1*_t103*_t121 - _t105*_t122*_t216 - _t108*_t216*_t218 + _t110*(-_t107*_t119 + (0.28e2 / 0.3e1)*_t112 + (0.2e1 / 0.3e1)*_t117 + _t173*_t219) + 0.2e1*_t122*_t220 + _t174*_t210 + _t176*_t210 - _t180*_t41 - _t181*_t41 - _t183*_t41 + _t197*_t199 - _t199*_t204 - _t201*_t203 + _t203*_t206*_t97 - _t203*_t207 - _t211*_t212 + _t212*_t213 + _t215*_t33 + _t32*((0.28e2 / 0.9e1)*_t112 + (0.2e1 / 0.9e1)*_t113 + (0.2e1 / 0.9e1)*_t117 - _t119*_t24) + _t44*((0.16e2 / 0.9e1)*_t1*_t119*_t2*_t28 - 0.1120e4 / 0.27e2*_t221 - 0.56e2 / 0.27e2*_t222 - 0.112e3 / 0.27e2*_t223 - 0.16e2 / 0.3e1*_t224*_t28 - _t227*_t228);
  const double _t230 = _t198*_t49;
  const double _t231 = _t16*_t202;
  const double _t232 = _t231*_t97;
  const double _t233 = _t39*_t45;
  const double _t234 = _t100*_t45;
  const double _t235 = -0.2e1*_t20*_t60 + 0.2e1*_t64;
  const double _t236 = 0.4e1*_t12*_t149;
  const double _t237 = 0.2e1*_t153;
  const double _t238 = _t147*_t61;
  const double _t239 = _t138*_t177;
  const double _t240 = _t116*_t132;
  const double _t242 = -_hc3[8]*_t241*_t56 - _t132*_t173;
  const double _t243 = _hc0[1]*_t39*_t4;
  const double _t244 = _hc1[0]*(_t225*_t57 + (0.4e1 / 0.9e1)*_t240 - _t242*_t69) - 0.1e1 / 0.18e2*_t100*_t239*_t93 + (0.1e1 / 0.9e1)*_t101*_t239 + _t103*_t135 - _t104*_t105*_t143 + _t109*_t122*_t144 + _t110*(-0.1e1 / 0.4e1*_t142 - 0.2e1*_t28*_t57) + (0.4e1 / 0.9e1)*_t115*_t140 + _t121*_t136 + (0.1e1 / 0.18e2)*_t139*_t177*_t77 + _t143*_t220 + _t215*_t59 - _t218*_t243*_t57*_t78 + _t32*(-_t133*_t175 - _t173*_t57) + _t44*((0.56e2 / 0.9e1)*_t111*_t57 - _t228*_t242 + (0.8e1 / 0.9e1)*_t240);
  const double _t245 = _t238*_t88;
  const double _t246 = _t235*_t65;
  const double _t247 = -_t171;
  const double _t248 = 0.2e1*_t156;
  const double _t249 = _hc3[4]*_t164;
  const double _t250 = _t167*_t78;
  const double _t251 = (0.3e1 / 0.2e1)*_hc1[0]*_t168*_t214*_t250 + _hc1[0]*(_t165*_t173 + _t241*_t249) + _t105*_t134*_t137*_t165*_t39 + 0.3e1*_t109*_t143*_t58 - 0.3e1 / 0.4e1*_t110*_t166 + _t135*_t58 - 0.1e1 / 0.4e1*_t166*_t32 - _t167*_t168*_t177*_t217*_t243 + _t44*(_t118*_t165 + _t134*_t249*_t3);
  const double _t252 = _t66*na;
  const double _t253 = (_t60 * _t60 * _t60);
  const double _t254 = _hc3[1]*_t7/xc_powr(gaa, 5, 2);
  const double _t255 = _t250/(gaa * gaa);
  const double _t256 = 0.3e1*_hc1[0]*((_hc3[1]) * (_hc3[1]) * (_hc3[1]))*_t15*_t164*_t177 + (0.3e1 / 0.4e1)*_hc1[0]*_t254 - 0.9e1 / 0.2e1*_t109*_t255 + (0.3e1 / 0.2e1)*_t254*_t44 - 0.3e1 / 0.4e1*_t255;
  const double d3F_dna3 = 0.3e1*_t129 + _t174 + _t176 + 0.3e1*_t84 + na*(0.2e1*_t128*_t187 - _t128*_t83 - _t180 - _t181 - _t183 + _t186*(-0.2e1*_t46 - 0.2e1*_t54) + _t67*(0.3e1*_t123*_t85 + 0.3e1*_t126*_t193 + _t127*(_t123*_t216 - _t124*_t208 - _t14*_t229 - _t174*_t233 - _t176*_t233 + _t180*_t50 + _t181*_t50 + _t183*_t50 + _t194*_t209 - _t197*_t230 + _t201*_t231 + _t204*_t230 - _t206*_t232 + _t207*_t231 + _t211*_t234 - _t213*_t234) + _t188*_t192*(_t190*_t50 - 0.3e1*_t51) + 0.3e1*_t189*_t45 + _t195*_t196 + _t20*_t229 + _t89*((0.2e1 / 0.3e1)*_hc0[1]*_hc2[0]*_t1*_t2*_t34*_t35*_t36*_t45*_t7 - 0.4e1 / 0.9e1*_hc0[1]*_t50*_t71 + (0.1e1 / 0.18e2)*_hc2[0]*_t16*_t35*_t36*_t74*_t75*_t78*_t91*_t94 - 0.2e1*_t125 - 0.1e1 / 0.9e1*_t194*_t78 - _t50*_t77*_t96)));
  const double d3F_dna2_dgaa = 0.2e1*_t130 + 0.2e1*_t155 + na*(_t128*_t156 + _t154*_t187 - _t154*_t83 + _t186*_t235 + _t67*(-_t123*_t131 + _t126*_t146 + _t127*((0.1e1 / 0.3e1)*_hc0[1]*_hc2[0]*_t1*_t145*_t2*_t34*_t35*_t36*_t7 + (0.1e1 / 0.36e2)*_hc2[0]*_t35*_t36*_t60*_t74*_t75*_t78*_t91*_t94 - _t102*_t60 - _t14*_t244 - _t151*_t73 - _t151*_t80) + _t145*_t86 + _t153*_t195 + _t189*_t60 - 0.3e1*_t191*_t238*_t52*_t87 + _t193*_t237 - _t196*_t245 + _t20*_t244 - _t236*_t45*_t60 + _t89*(_t151*_t70 - 0.2e1*_t152)));
  const double d3F_dna_dgaa2 = _t157 + _t172 + na*(_t154*_t248 + _t185*_t246 + _t247*_t83 + _t67*(_t127*(-_t14*_t251 + _t169*_t25*_t39) - 0.2e1*_t131*_t145 + _t146*_t237 - _t150*_t169*_t17 - 0.4e1*_t153*_t245 - _t158*_t169*_t45 + 0.6e1*_t159*_t163*_t192 - _t159*_t236 + _t160*_t163*_t45*_t88 + _t169*_t85 + _t20*_t251));
  const double d3F_dgaa3 = _t171*_t248*na + _t184*_t246*_t252 + _t247*_t252*_t82 + _t67*na*(-0.6e1*((_hc2[0]) * (_hc2[0]) * (_hc2[0]) * (_hc2[0]))*_t191*_t232*_t253 + _hc2[0]*_t10*_t19*_t256 - 0.6e1*_t131*_t169 + 0.6e1*_t16*_t162*_t169*_t35*_t60*_t88*_t91 + 0.6e1*_t162*_t253*_t35*_t88*_t91 - _t170*_t256);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
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
  const double _t5 = xc_powr(0.6e1, 1, 3);
  const double _t6 = (0.1e1 / (M_CBRTPI));
  const double _t7 = _t5*_t6;
  const double _t8 = (0.1e1 / 0.2e1)*_t7;
  const double _t9 = _t8/xc_powr(_t2, 1, 3);
  const double _t10 = xc_powr(_t2, -4, 3);
  const double _t11 = gaa + 0.2e1*gab + gbb;
  const double _t12 = xc_powr(_t11, 1, 2);
  const double _t16 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t17 = (_t1 * _t1 * _t1 * _t1);
  const double _t18 = _t16*_t17;
  const double _t19 = (0.1e1 / (_t2 * _t2));
  const double _t20 = 0.4e1*_t19;
  const double _t21 = (_t1 * _t1);
  const double _t22 = _t19*_t21 + 0.1e1;
  const double _t23 = -0.9e1 / 0.4e1 + (0.9e1 / 0.4e1)*M_CBRT2;
  const double _t33 = (0.1e1 / (params->gamma));
  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t4, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -_t4, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(DMC_k, _KMAX)(p, _t9, 0, _hc2);
  double _hc3[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, _t4, _hc3);
  double _hc4[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_aux_k, _KMAX)(p, -(0.1e1 / 0.6e1)/(M_PI * M_PI), 1.13107, 13.0045, -0.0047584000000000003, _t9, _hc4);
  double _hc5[(_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_aux_k, _KMAX)(p, 0.031090699999999999, 3.7274400000000001, 12.9352, -0.10498, _t9, _hc5);
  double _hc6[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(tp_k, _KMAX)(p, _t9, _t4, _t10*_t12, _hc6);
  double _hc7[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeta_k, _KMAX)(p, 0, 0, _hc7);
  const double _t13 = ((_hc6[0]) * (_hc6[0]));
  const double _t14 = ((_hc6[0]) * (_hc6[0]) * (_hc6[0]) * (_hc6[0]));
  const double _t15 = _hc2[0]*_hc3[0];
  const double _t24 = _hc4[0]*_t23;
  const double _t25 = _hc3[0]*_t24;
  const double _t26 = _t22*_t25;
  const double _t27 = _t20*_t26;
  const double _t28 = _t27*nb;
  const double _t29 = _hc5[0] + _t15*_t18 + _t28*na;
  const double _t30 = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
  const double _t31 = (_t30 * _t30 * _t30);
  const double _t32 = (0.1e1 / _t31);
  const double _t34 = _t32*_t33;
  const double _t35 = xc_expm1(-_t29*_t34);
  const double _t36 = (0.1e1 / _t35);
  const double _t37 = _hc7[0]*_t33;
  const double _t38 = _t36*_t37;
  const double _t39 = _t38*params->BB;
  const double _t40 = _t13 + _t14*_t39;
  const double _t41 = _t36*_t40;
  const double _t42 = _t37*_t41 + 0.1e1;
  const double _t43 = (0.1e1 / _t42);
  const double _t44 = _t37*_t43;
  const double _t45 = _t40*_t44;
  const double _t46 = xc_log1p(_t45);
  const double _t47 = _t31*params->gamma;
  const double _t48 = _t29 + _t46*_t47;
  const double zk = _t48;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t50 = (_t1 * _t1 * _t1);
  const double _t51 = _t16*_t50;
  const double _t53 = xc_powi(_t2, -5);
  const double _t54 = _t17*_t53;
  const double _t56 = _t10*_t7;
  const double _t57 = (0.1e1 / 0.6e1)*_t56;
  const double _t61 = xc_powr(_t2, -16, 3);
  const double _t62 = _t17*_t61;
  const double _t65 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t66 = 0.8e1*_t65;
  const double _t73 = xc_powr(_t2, -10, 3);
  const double _t74 = _t7*_t73;
  const double _t79 = -_t3;
  const double _t80 = _t1*_t19;
  const double _t81 = _t79 + _t80;
  const double _t82 = -_t81;
  const double _t83 = xc_powr(_t2, -7, 3);
  const double _t84 = _t12*_t83;
  const double _t101 = 0.2e1*_t65;
  const double _t102 = _t101*_t21;
  const double _t103 = 0.2e1*nb;
  const double _t104 = -_t103 + 0.2e1*na;
  const double _t105 = -_t102 + _t104*_t19;
  const double _t144 = _t20*na;
  const double _t149 = _t3 + _t80;
  const double _t150 = -_t149;
  const double _t161 = -_t104;
  const double _t162 = -_t102 + _t161*_t19;
  const double _t183 = (0.1e1 / _t12);
  double _hc8[(_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(tp_k, _KMAX)(p, _t9, _t4, 0, _hc8);
  const double _t49 = 0.4e1*_t15;
  const double _t52 = _t49*_t51;
  const double _t55 = _t49*_t54;
  const double _t58 = _hc5[1]*_t57;
  const double _t59 = _hc2[2]*_t7;
  const double _t60 = _hc3[0]*_t59;
  const double _t63 = _t60*_t62;
  const double _t64 = (0.1e1 / 0.6e1)*_t63;
  const double _t67 = _t26*_t66;
  const double _t68 = _t67*na;
  const double _t69 = _t68*nb;
  const double _t70 = _hc3[0]*_t23;
  const double _t71 = _t22*_t70;
  const double _t72 = _t71*na;
  const double _t75 = _hc4[1]*_t74;
  const double _t76 = (0.2e1 / 0.3e1)*_t75;
  const double _t77 = _t72*_t76;
  const double _t78 = _t77*nb;
  const double _t85 = _hc8[1]*_t84;
  const double _t86 = _hc6[3]*_t56;
  const double _t87 = (0.8e1 / 0.3e1)*_t85 + (0.1e1 / 0.3e1)*_t86;
  const double _t88 = 0.2e1*_hc6[2]*_t82 - _t87;
  const double _t89 = _hc6[0]*_t88;
  const double _t90 = (0.16e2 / 0.3e1)*_t85 + (0.2e1 / 0.3e1)*_t86;
  const double _t91 = 0.4e1*_hc6[2]*_t82 - _t90;
  const double _t92 = ((_hc6[0]) * (_hc6[0]) * (_hc6[0]));
  const double _t93 = _t39*_t92;
  const double _t94 = _hc0[2]*_t82;
  const double _t95 = _hc1[2]*_t81;
  const double _t96 = (0.3e1 / 0.2e1)*_t95;
  const double _t97 = (0.3e1 / 0.2e1)*_t94 + _t96;
  const double _t98 = -_t97;
  const double _t99 = _t33/(_t30 * _t30 * _t30 * _t30);
  const double _t100 = _t29*_t99;
  const double _t106 = _t105*_t25;
  const double _t107 = _t106*na;
  const double _t108 = _t107*_t20;
  const double _t109 = _t108*nb;
  const double _t110 = _t55 + _t58 + _t64 + _t69 + _t78;
  const double _t111 = -_t109 + _t110 - _t28 - _t52;
  const double _t112 = _hc2[0]*_hc3[1]*_t16*_t17*_t82 + 0.4e1*_hc3[1]*_hc4[0]*_t19*_t22*_t23*_t82*na*nb - _t111;
  const double _t113 = -_t100*_t98 - _t112*_t34;
  const double _t114 = (0.1e1 / (_t35 * _t35));
  const double _t115 = _t35 + 0.1e1;
  const double _t116 = _t114*_t115;
  const double _t117 = _t116*_t37;
  const double _t118 = _t113*_t117;
  const double _t119 = _t14*params->BB;
  const double _t120 = _t118*_t119;
  const double _t121 = -_t120 + _t89 + _t91*_t93;
  const double _t122 = _t121*_t44;
  const double _t123 = (0.1e1 / (_t42 * _t42));
  const double _t124 = _t123*_t37;
  const double _t125 = _t37*_t40;
  const double _t126 = _t113*_t125;
  const double _t127 = _t116*_t126;
  const double _t128 = _t121*_t38;
  const double _t129 = _t127 - _t128;
  const double _t130 = _t129*_t40;
  const double _t131 = _t124*_t130;
  const double _t132 = _t122 + _t131;
  const double _t133 = _t45 + 0.1e1;
  const double _t134 = (0.1e1 / _t133);
  const double _t135 = _t134*_t47;
  const double _t136 = _t132*_t135;
  const double _t137 = (_t30 * _t30);
  const double _t138 = _t137*params->gamma;
  const double _t139 = _t138*_t46;
  const double _t140 = _t139*_t97;
  const double _t141 = _hc2[0]*_t18;
  const double _t142 = _hc3[1]*_t82;
  const double _t143 = _t141*_t142;
  const double _t145 = _t22*_t24;
  const double _t146 = _t142*_t145;
  const double _t147 = _t144*_t146;
  const double _t148 = _t109 + _t136 + _t140 + _t143 + _t147*nb + _t28;
  const double _t151 = 0.2e1*_hc6[2]*_t150 - _t87;
  const double _t152 = _hc6[0]*_t151;
  const double _t153 = 0.4e1*_hc6[2]*_t150 - _t90;
  const double _t154 = _hc1[2]*_t149;
  const double _t155 = (0.3e1 / 0.2e1)*_t154;
  const double _t156 = _hc0[2]*_t150;
  const double _t157 = _t155 + (0.3e1 / 0.2e1)*_t156;
  const double _t158 = -_t157;
  const double _t159 = _t100*_t158;
  const double _t160 = _t27*na;
  const double _t163 = _t162*_t25;
  const double _t164 = _t163*nb;
  const double _t165 = _t164*_t20;
  const double _t166 = _t165*na;
  const double _t167 = _t110 - _t160 - _t166 + _t52;
  const double _t168 = -_hc2[0]*_hc3[1]*_t150*_t16*_t17 - 0.4e1*_hc3[1]*_hc4[0]*_t150*_t19*_t22*_t23*na*nb + _t167;
  const double _t169 = -_t168;
  const double _t170 = _t169*_t34;
  const double _t171 = -_t159 - _t170;
  const double _t172 = _t117*_t171;
  const double _t173 = _t119*_t172;
  const double _t174 = _t152 + _t153*_t93 - _t173;
  const double _t175 = _t174*_t44;
  const double _t176 = _t116*_t125;
  const double _t177 = _t171*_t176;
  const double _t178 = _t174*_t38;
  const double _t179 = _t177 - _t178;
  const double _t180 = _t124*_t40;
  const double _t181 = _t179*_t180;
  const double _t182 = _t175 + _t181;
  const double _t184 = _hc8[1]*_t183;
  const double _t185 = _t10*_t184;
  const double _t186 = _hc6[0]*_t185;
  const double _t187 = _t185*_t93;
  const double _t188 = _t186 + 0.2e1*_t187;
  const double _t189 = ((_hc7[0]) * (_hc7[0]))/((params->gamma) * (params->gamma));
  const double _t190 = _t123*_t189;
  const double _t191 = _t190*_t41;
  const double _t192 = _t188*_t191;
  const double _t193 = -_hc7[0]*_t188*_t33*_t43 + _t192;
  const double _t194 = -_t193;
  const double _t195 = _t135*_t194;
  const double _t196 = _t195*_t2;
  const double _t197 = 0.2e1*_t186;
  const double _t198 = 0.4e1*_t187 + _t197;
  const double _t199 = _t191*_t198;
  const double _t200 = -_hc7[0]*_t198*_t33*_t43 + _t199;
  const double _t201 = -_t200;
  const double _t202 = _t135*_t201;
  const double dF_dna = _t2*(_t148 + _t52 - _t55 - _t58 - _t64 - _t69 - _t78) + _t48;
  const double dF_dnb = _t2*(_t134*_t182*_t31*params->gamma + _t137*_t157*_t46*params->gamma - _t168) + _t48;
  const double dF_dgaa = _t196;
  const double dF_dgab = _t2*_t202;
  const double dF_dgbb = _t196;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 1] += dF_dgab;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double _t208 = 0.8e1*_t54;
  const double _t209 = 0.16e2*_t65;
  const double _t216 = _t209*na;
  const double _t220 = na*nb;
  const double _t223 = _t22*_t23;
  const double _t227 = _t16*_t21;
  const double _t230 = _t7*_t83;
  const double _t231 = (0.2e1 / 0.9e1)*_t230;
  const double _t232 = xc_powr(0.6e1, 2, 3);
  const double _t233 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t234 = _t232*_t233;
  const double _t236 = xc_powr(_t2, -8, 3);
  const double _t237 = (0.1e1 / 0.36e2)*_t236;
  const double _t241 = xc_powi(_t2, -6);
  const double _t244 = _t234*_t237;
  const double _t246 = xc_powr(_t2, -19, 3);
  const double _t247 = _t17*_t246;
  const double _t249 = 0.24e2*_t16;
  const double _t253 = xc_powr(_t2, -14, 3);
  const double _t256 = xc_powr(_t2, -13, 3);
  const double _t266 = 0.2e1*_t19;
  const double _t267 = _t1*_t101;
  const double _t268 = -_t266 + _t267;
  const double _t271 = (_t82 * _t82);
  const double _t274 = 0.8e1*_t19;
  const double _t277 = _t50*_t61;
  const double _t279 = 0.4e1*_t65;
  const double _t280 = 0.6e1*_t16;
  const double _t281 = _t21*_t280 + _t266;
  const double _t282 = -_t104*_t279 + _t281;
  const double _t295 = _t274*na;
  const double _t308 = _t10*_t8;
  const double _t314 = (0.4e1 / 0.3e1)*_t84;
  const double _t325 = _t12*_t73;
  const double _t352 = -_t268;
  const double _t354 = (_t81 * _t81);
  const double _t393 = (0.1e1 / 0.3e1)*_t56;
  const double _t407 = _t1*_t279;
  const double _t415 = (0.2e1 / 0.3e1)*_t56;
  const double _t425 = 0.3e1*_t65;
  const double _t438 = xc_powi(_t2, -7);
  const double _t439 = xc_powi(_t1, 5);
  const double _t443 = 0.4e1*_t54;
  const double _t448 = _t66*na;
  const double _t450 = -_t101*_t104 - _t101*_t161 + 0.6e1*_t16*_t21 - _t266;
  const double _t461 = _t53*na;
  const double _t504 = _t266 + _t267;
  const double _t506 = (_t150 * _t150);
  const double _t510 = -_t161*_t279 + _t281;
  const double _t537 = (_t149 * _t149);
  const double _t540 = -_t504;
  const double _t576 = _t183*_t7;
  const double _t647 = xc_powr(_t11, -3, 2);
  const double _t652 = (0.1e1 / _t11);
  const double _t656 = (0.1e1 / ((params->gamma) * (params->gamma) * (params->gamma)));
  const double _t203 = 0.8e1*_t15;
  const double _t204 = _t203*_t51;
  const double _t205 = _hc2[0]*_t142;
  const double _t206 = _t205*_t51;
  const double _t207 = 0.8e1*_t206;
  const double _t210 = _t209*_t26;
  const double _t211 = _t210*nb;
  const double _t212 = _t107*_t209;
  const double _t213 = _t59*_t62;
  const double _t214 = _t142*_t213;
  const double _t215 = _t146*nb;
  const double _t217 = (0.4e1 / 0.3e1)*_t75;
  const double _t218 = _t217*_t71;
  const double _t219 = _t218*nb;
  const double _t221 = _t105*_t70;
  const double _t222 = _t220*_t221;
  const double _t224 = _t142*_t223;
  const double _t225 = _t220*_t224;
  const double _t226 = -_t205*_t208 - _t211 - _t212*nb - 0.1e1 / 0.3e1*_t214 - _t215*_t216 - _t217*_t222 - _t217*_t225 - _t219;
  const double _t228 = _t15*_t227;
  const double _t229 = 0.12e2*_t228;
  const double _t235 = _hc2[5]*_t234;
  const double _t238 = _hc2[2]*_t231 + _t235*_t237;
  const double _t239 = _hc3[0]*_t18;
  const double _t240 = _t238*_t239;
  const double _t242 = _t15*_t17;
  const double _t243 = _t241*_t242;
  const double _t245 = (0.4e1 / 0.3e1)*_t60;
  const double _t248 = _t26*nb;
  const double _t250 = _t248*_t249;
  const double _t251 = (0.1e1 / 0.9e1)*_t72;
  const double _t252 = _t251*nb;
  const double _t254 = _hc4[6]*_t234;
  const double _t255 = _t253*_t254;
  const double _t257 = _hc4[1]*_t7;
  const double _t258 = _t256*_t257;
  const double _t259 = _t258*_t72;
  const double _t260 = (0.32e2 / 0.9e1)*_t259;
  const double _t261 = _hc5[1]*_t231 + _hc5[6]*_t244 + _t240 + 0.20e2*_t243 + _t245*_t247 + _t250*na + _t252*_t255 + _t260*nb;
  const double _t262 = _t229 + _t261;
  const double _t263 = _t15*_t50;
  const double _t264 = _t263*_t53;
  const double _t265 = 0.32e2*_t264;
  const double _t269 = _hc3[1]*_t141;
  const double _t270 = _t268*_t269;
  const double _t272 = _hc3[2]*_t141;
  const double _t273 = _t271*_t272;
  const double _t275 = _t106*_t274;
  const double _t276 = _t275*nb;
  const double _t278 = _t245*_t277;
  const double _t283 = _t25*_t282;
  const double _t284 = _t144*_t283;
  const double _t285 = _t145*_t274;
  const double _t286 = _t142*_t285;
  const double _t287 = _t286*nb;
  const double _t288 = _hc3[1]*_t268;
  const double _t289 = _t144*_t145;
  const double _t290 = _t288*_t289;
  const double _t291 = _hc3[2]*_t271;
  const double _t292 = _t289*_t291;
  const double _t293 = _t142*_t24;
  const double _t294 = _t105*_t293;
  const double _t296 = _t294*_t295;
  const double _t297 = -_t265 + _t270 + _t273 + _t276 - _t278 + _t284*nb + _t287 + _t290*nb + _t292*nb + _t296*nb;
  const double _t298 = _t207 + _t226 + _t262 + _t297;
  const double _t299 = _t124*_t129;
  const double _t300 = 0.2e1*_t299;
  const double _t301 = (0.1e1 / (_t42 * _t42 * _t42));
  const double _t302 = 0.2e1*_t127;
  const double _t303 = -0.2e1*_t128 + _t302;
  const double _t304 = _t301*_t303;
  const double _t305 = _t130*_t37;
  const double _t306 = (0.4e1 / 0.3e1)*_t85 + (0.1e1 / 0.6e1)*_t86;
  const double _t307 = _hc6[2]*_t82 - _t306;
  const double _t309 = _hc6[3]*_t308 + 0.4e1*_t85;
  const double _t310 = 0.3e1*_hc6[2]*_t82 - _t309;
  const double _t311 = _t13*_t39;
  const double _t312 = _t311*_t91;
  const double _t313 = _hc6[2]*_t268;
  const double _t315 = _hc6[8]*_t57 + _hc8[5]*_t314;
  const double _t316 = _hc6[6]*_t82 - _t315;
  const double _t317 = _t316*_t82;
  const double _t318 = -_hc8[7]*_t57;
  const double _t319 = _hc8[5]*_t82;
  const double _t320 = _t318 + _t319;
  const double _t321 = _t320*_t84;
  const double _t322 = _hc6[9]*_t57 + _hc8[7]*_t314;
  const double _t323 = _hc6[8]*_t82 - _t322;
  const double _t324 = _t323*_t56;
  const double _t326 = _hc8[1]*_t325;
  const double _t327 = _hc6[3]*_t230;
  const double _t328 = (0.56e2 / 0.9e1)*_t326 + (0.4e1 / 0.9e1)*_t327;
  const double _t329 = 0.2e1*_t313 + 0.2e1*_t317 - 0.8e1 / 0.3e1*_t321 - 0.1e1 / 0.3e1*_t324 + _t328;
  const double _t330 = (0.112e3 / 0.9e1)*_t326 + (0.8e1 / 0.9e1)*_t327;
  const double _t331 = 0.4e1*_t313 + 0.4e1*_t317 - 0.16e2 / 0.3e1*_t321 - 0.2e1 / 0.3e1*_t324 + _t330;
  const double _t332 = (_t113 * _t113);
  const double _t333 = _t117*_t332;
  const double _t334 = _t119*_t333;
  const double _t335 = (_t115 * _t115);
  const double _t336 = (0.1e1 / (_t35 * _t35 * _t35));
  const double _t337 = _t335*_t336;
  const double _t338 = 0.2e1*_t337;
  const double _t339 = _t332*_t37;
  const double _t340 = _t338*_t339;
  const double _t341 = _t119*_t340;
  const double _t342 = 0.2e1*_t118;
  const double _t343 = _t92*params->BB;
  const double _t344 = _t343*_t91;
  const double _t345 = -0.2e1*_t94 - 0.2e1*_t95;
  const double _t346 = _t33/xc_powi(_t30, 5);
  const double _t347 = _t29*_t346;
  const double _t348 = _t347*_t98;
  const double _t349 = _t345*_t348;
  const double _t350 = _hc0[2]*_t268;
  const double _t351 = _hc0[5]*_t271;
  const double _t353 = _hc1[2]*_t352;
  const double _t355 = _hc1[5]*_t354;
  const double _t356 = (0.3e1 / 0.2e1)*_t350 + (0.3e1 / 0.2e1)*_t351 + (0.3e1 / 0.2e1)*_t353 + (0.3e1 / 0.2e1)*_t355;
  const double _t357 = -_t356;
  const double _t358 = _t100*_t357;
  const double _t359 = _t98*_t99;
  const double _t360 = _t112*_t359;
  const double _t361 = _t298*_t34;
  const double _t362 = -_t349 - _t358 - 0.2e1*_t360 - _t361;
  const double _t363 = _t117*_t362;
  const double _t364 = _hc6[0]*_t329 - _t119*_t363 + _t307*_t88 + _t310*_t312 + _t331*_t93 - _t334 + _t341 - _t342*_t344;
  const double _t365 = _t176*_t332;
  const double _t366 = _t125*_t332;
  const double _t367 = _t338*_t366;
  const double _t368 = _t118*_t121;
  const double _t369 = _t176*_t362;
  const double _t370 = _t364*_t38;
  const double _t371 = _t365 - _t367 + 0.2e1*_t368 + _t369 - _t370;
  const double _t372 = _t121*_t300 + _t180*_t371 + _t304*_t305 + _t364*_t44;
  const double _t373 = _t135*_t372;
  const double _t374 = _t139*_t356;
  const double _t375 = -_t132;
  const double _t376 = (0.1e1 / (_t133 * _t133));
  const double _t377 = _t376*_t47;
  const double _t378 = _t132*_t377;
  const double _t379 = _t375*_t378;
  const double _t380 = _t94 + _t95;
  const double _t381 = _t46*params->gamma;
  const double _t382 = _t30*_t381;
  const double _t383 = _t382*_t97;
  const double _t384 = _t380*_t383;
  const double _t385 = _t134*_t138;
  const double _t386 = _t385*_t97;
  const double _t387 = _t132*_t386;
  const double _t388 = _t373 + _t374 + _t379 + _t384 + 0.2e1*_t387;
  const double _t389 = _t26*_t274;
  const double _t390 = _t389*nb;
  const double _t391 = _t276*na;
  const double _t392 = _t203*_t54;
  const double _t394 = _hc5[1]*_t393;
  const double _t395 = (0.1e1 / 0.3e1)*_t63;
  const double _t396 = _t211*na;
  const double _t397 = _t219*na;
  const double _t398 = -_t392 - _t394 - _t395 - _t396 - _t397;
  const double _t399 = _t124*_t179;
  const double _t400 = 0.2e1*_t177;
  const double _t401 = -0.2e1*_t178 + _t400;
  const double _t402 = _t301*_t401;
  const double _t403 = _hc6[2]*_t150 - _t306;
  const double _t404 = 0.3e1*_hc6[2]*_t150 - _t309;
  const double _t405 = _hc6[6]*_t150 - _t315;
  const double _t406 = _t405*_t82;
  const double _t408 = _hc8[5]*_t150;
  const double _t409 = _t318 + _t408;
  const double _t410 = _t409*_t84;
  const double _t411 = _hc6[8]*_t150 - _t322;
  const double _t412 = _t328 - _t393*_t411 - 0.8e1 / 0.3e1*_t410;
  const double _t413 = _hc6[2]*_t407 + 0.2e1*_t406 + _t412;
  const double _t414 = _hc6[2]*_t66;
  const double _t416 = _t330 - 0.16e2 / 0.3e1*_t410 - _t411*_t415;
  const double _t417 = _t1*_t414 + 0.4e1*_t406 + _t416;
  const double _t418 = _t153*_t343;
  const double _t419 = _t172*_t343;
  const double _t420 = _t171*_t338;
  const double _t421 = _t119*_t37;
  const double _t422 = _t113*_t421;
  const double _t423 = -0.2e1*_t154 - 0.2e1*_t156;
  const double _t424 = _t348*_t423;
  const double _t426 = _hc1[5]*_t81;
  const double _t427 = _t149*_t426;
  const double _t428 = _hc0[5]*_t82;
  const double _t429 = _t150*_t428;
  const double _t430 = _hc0[2]*_t1*_t425 - 0.3e1*_hc1[2]*_t1*_t65 + (0.3e1 / 0.2e1)*_t427 + (0.3e1 / 0.2e1)*_t429;
  const double _t431 = -_t430;
  const double _t432 = _t100*_t431;
  const double _t433 = _t158*_t99;
  const double _t434 = _t112*_t433;
  const double _t435 = _t169*_t99;
  const double _t436 = _t435*_t98;
  const double _t437 = -_t229;
  const double _t440 = _hc2[0]*_hc3[1];
  const double _t441 = _t439*_t440;
  const double _t442 = _t438*_t441;
  const double _t444 = _t150*_t440;
  const double _t445 = _t444*_t51;
  const double _t446 = _t272*_t82;
  const double _t447 = _t150*_t446;
  const double _t449 = _t107*nb;
  const double _t451 = _t25*nb;
  const double _t452 = _t144*_t451;
  const double _t453 = _hc3[1]*_t150;
  const double _t454 = _t453*nb;
  const double _t455 = _t145*_t454;
  const double _t456 = _t213*_t453;
  const double _t457 = _t162*_t293;
  const double _t458 = _t457*nb;
  const double _t459 = _t105*_t24;
  const double _t460 = _t454*_t459;
  const double _t462 = _t145*nb;
  const double _t463 = _hc3[1]*_t462;
  const double _t464 = 0.8e1*_t461*_t463;
  const double _t465 = _t71*nb;
  const double _t466 = _t289*nb;
  const double _t467 = _hc3[2]*_t82;
  const double _t468 = _t150*_t467;
  const double _t469 = _t162*_t70;
  const double _t470 = _t220*_t469;
  const double _t471 = _t220*_t76;
  const double _t472 = _t223*_t454;
  const double _t473 = _t472*na;
  const double _t474 = _t1*_t464 + _t108 + _t144*_t458 + _t144*_t460 + _t147 - _t164*_t448 + _t165 + _t20*_t455 - _t205*_t443 - 0.4e1*_t206 - 0.1e1 / 0.6e1*_t214 - _t215*_t448 - _t222*_t76 - _t224*_t471 + _t261 + _t27 + _t437 + 0.2e1*_t442 - _t443*_t444 + 0.4e1*_t445 + _t447 - _t448*_t455 - _t449*_t66 + _t450*_t452 - 0.1e1 / 0.6e1*_t456 - _t465*_t76 + _t466*_t468 - _t470*_t76 - _t473*_t76 - _t67*nb - _t68 - _t77;
  const double _t475 = _t34*_t474;
  const double _t476 = -_t424 - _t432 - _t434 - _t436 - _t475;
  const double _t477 = _t117*_t476;
  const double _t478 = _hc6[0]*_t413 - _t113*_t173 - _t118*_t418 - _t119*_t477 + _t312*_t404 + _t403*_t88 + _t417*_t93 - _t419*_t91 + _t420*_t422;
  const double _t479 = _t126*_t338;
  const double _t480 = _t171*_t479;
  const double _t481 = _t121*_t172;
  const double _t482 = _t118*_t174;
  const double _t483 = _t176*_t476;
  const double _t484 = _t38*_t478;
  const double _t485 = _t127*_t171 - _t480 + _t481 + _t482 + _t483 - _t484;
  const double _t486 = _t121*_t399 + _t174*_t299 + _t180*_t485 + _t305*_t402 + _t44*_t478;
  const double _t487 = _t135*_t486;
  const double _t488 = _t139*_t430;
  const double _t489 = _t182*_t386;
  const double _t490 = _t157*_t385;
  const double _t491 = _t132*_t490;
  const double _t492 = -_t182;
  const double _t493 = _t378*_t492;
  const double _t494 = _t154 + _t156;
  const double _t495 = _t383*_t494;
  const double _t496 = _t135*_t182;
  const double _t497 = _t139*_t157;
  const double _t498 = _t150*_t269;
  const double _t499 = -_t204;
  const double _t500 = 0.8e1*_t445;
  const double _t501 = _t164*_t209;
  const double _t502 = _t217*na;
  const double _t503 = -_t208*_t444 - _t210*na - _t216*_t455 - _t217*_t470 - _t218*na - 0.1e1 / 0.3e1*_t456 - _t472*_t502 - _t501*na;
  const double _t505 = _t269*_t504;
  const double _t507 = _t272*_t506;
  const double _t508 = _t163*_t274;
  const double _t509 = _t508*na;
  const double _t511 = _t451*_t510;
  const double _t512 = _t285*_t453;
  const double _t513 = _t512*na;
  const double _t514 = _hc3[1]*_t504;
  const double _t515 = _hc3[2]*_t506;
  const double _t516 = _t162*_t24;
  const double _t517 = _t454*_t516;
  const double _t518 = _t144*_t511 + _t265 + _t278 + _t295*_t517 + _t466*_t514 + _t466*_t515 + _t505 + _t507 + _t509 + _t513;
  const double _t519 = _t262 - _t500 + _t503 + _t518;
  const double _t520 = 0.2e1*_t399;
  const double _t521 = _t125*_t402;
  const double _t522 = _t311*_t404;
  const double _t523 = _hc6[2]*_t504;
  const double _t524 = _t150*_t405;
  const double _t525 = _t412 + 0.2e1*_t523 + 0.2e1*_t524;
  const double _t526 = _t416 + 0.4e1*_t523 + 0.4e1*_t524;
  const double _t527 = (_t171 * _t171);
  const double _t528 = _t117*_t527;
  const double _t529 = _t119*_t528;
  const double _t530 = _t37*_t527;
  const double _t531 = _t338*_t530;
  const double _t532 = _t119*_t531;
  const double _t533 = 0.2e1*_t172;
  const double _t534 = _t418*_t533;
  const double _t535 = _t347*_t423;
  const double _t536 = _t158*_t535;
  const double _t538 = _hc1[5]*_t537;
  const double _t539 = _hc0[2]*_t504;
  const double _t541 = _hc1[2]*_t540;
  const double _t542 = _hc0[5]*_t506;
  const double _t543 = (0.3e1 / 0.2e1)*_t538 + (0.3e1 / 0.2e1)*_t539 + (0.3e1 / 0.2e1)*_t541 + (0.3e1 / 0.2e1)*_t542;
  const double _t544 = -_t543;
  const double _t545 = _t100*_t544;
  const double _t546 = 0.2e1*_t435;
  const double _t547 = _t34*_t519;
  const double _t548 = -_t158*_t546 - _t536 - _t545 - _t547;
  const double _t549 = _t117*_t548;
  const double _t550 = _hc6[0]*_t525 - _t119*_t549 + _t151*_t403 + _t153*_t522 + _t526*_t93 - _t529 + _t532 - _t534;
  const double _t551 = _t176*_t527;
  const double _t552 = _t125*_t338;
  const double _t553 = _t527*_t552;
  const double _t554 = 0.2e1*_t174;
  const double _t555 = _t172*_t554;
  const double _t556 = _t176*_t548;
  const double _t557 = _t38*_t550;
  const double _t558 = _t551 - _t553 + _t555 + _t556 - _t557;
  const double _t559 = _t174*_t520 + _t179*_t521 + _t180*_t558 + _t44*_t550;
  const double _t560 = _t135*_t559;
  const double _t561 = _t139*_t543;
  const double _t562 = _t182*_t377;
  const double _t563 = _t492*_t562;
  const double _t564 = _t382*_t494;
  const double _t565 = _t157*_t564;
  const double _t566 = 0.2e1*_t490;
  const double _t567 = _t182*_t566 + _t560 + _t561 + _t563 + _t565;
  const double _t568 = _t389*na;
  const double _t569 = _t509*nb;
  const double _t570 = _t194*_t386;
  const double _t571 = _t193*_t378;
  const double _t572 = _t190*_t36;
  const double _t573 = _t121*_t188;
  const double _t574 = _t185*_t88;
  const double _t575 = _t184*_t83;
  const double _t577 = _hc8[7]*_t576;
  const double _t578 = _t236*_t577;
  const double _t579 = (0.4e1 / 0.3e1)*_t575 + (0.1e1 / 0.6e1)*_t578;
  const double _t580 = _hc8[5]*_t10*_t183*_t82 - _t579;
  const double _t581 = _t185*_t312;
  const double _t582 = (0.8e1 / 0.3e1)*_t575 + (0.1e1 / 0.3e1)*_t578;
  const double _t583 = 0.2e1*_hc8[5]*_t10*_t183*_t82 - _t582;
  const double _t584 = _t342*_t343;
  const double _t585 = _hc6[0]*_t580 - _t185*_t584 + (0.1e1 / 0.2e1)*_t574 + (0.3e1 / 0.2e1)*_t581 + _t583*_t93;
  const double _t586 = 0.2e1*_t41;
  const double _t587 = _t189*_t301;
  const double _t588 = _t129*_t587;
  const double _t589 = _t188*_t588;
  const double _t590 = _t118*_t188;
  const double _t591 = _t38*_t585;
  const double _t592 = _t590 - _t591;
  const double _t593 = _t180*_t592 + _t188*_t299 + _t44*_t585 - _t572*_t573 - _t586*_t589;
  const double _t594 = _t135*_t593;
  const double _t595 = _t570 + _t571 + _t594;
  const double _t596 = _t195 + _t2*_t595;
  const double _t597 = _t201*_t386;
  const double _t598 = _t200*_t378;
  const double _t599 = _t198*_t572;
  const double _t600 = (0.16e2 / 0.3e1)*_t575 + (0.2e1 / 0.3e1)*_t578;
  const double _t601 = 0.4e1*_hc8[5]*_t10*_t183*_t82 - _t600;
  const double _t602 = _t118*_t343;
  const double _t603 = 0.4e1*_t185;
  const double _t604 = _hc6[0]*_t583 + _t574 + 0.3e1*_t581 + _t601*_t93 - _t602*_t603;
  const double _t605 = _t198*_t586;
  const double _t606 = _t118*_t198;
  const double _t607 = _t38*_t604;
  const double _t608 = _t606 - _t607;
  const double _t609 = -_t121*_t599 + _t180*_t608 + _t198*_t299 + _t44*_t604 - _t588*_t605;
  const double _t610 = _t135*_t609;
  const double _t611 = _t597 + _t598 + _t610;
  const double _t612 = _t194*_t490;
  const double _t613 = _t193*_t562;
  const double _t614 = _t188*_t572;
  const double _t615 = _t151*_t185;
  const double _t616 = _hc8[5]*_t10*_t150*_t183 - _t579;
  const double _t617 = _t153*_t311;
  const double _t618 = _t185*_t617;
  const double _t619 = 0.2e1*_hc8[5]*_t10*_t150*_t183 - _t582;
  const double _t620 = _t343*_t533;
  const double _t621 = _t185*_t620;
  const double _t622 = _hc6[0]*_t616 + (0.1e1 / 0.2e1)*_t615 + (0.3e1 / 0.2e1)*_t618 + _t619*_t93 - _t621;
  const double _t623 = _t179*_t587;
  const double _t624 = _t188*_t586;
  const double _t625 = _t172*_t188;
  const double _t626 = _t38*_t622;
  const double _t627 = _t625 - _t626;
  const double _t628 = -_t174*_t614 + _t180*_t627 + _t188*_t399 + _t44*_t622 - _t623*_t624;
  const double _t629 = _t135*_t628;
  const double _t630 = _t612 + _t613 + _t629;
  const double _t631 = _t195 + _t2*_t630;
  const double _t632 = _t201*_t490;
  const double _t633 = _t200*_t562;
  const double _t634 = 0.4e1*_hc8[5]*_t10*_t150*_t183 - _t600;
  const double _t635 = _t419*_t603;
  const double _t636 = _hc6[0]*_t619 + _t615 + 0.3e1*_t618 + _t634*_t93 - _t635;
  const double _t637 = _t172*_t198;
  const double _t638 = _t38*_t636;
  const double _t639 = _t637 - _t638;
  const double _t640 = -_t174*_t599 + _t180*_t639 + _t198*_t399 + _t44*_t636 - _t605*_t623;
  const double _t641 = _t135*_t640;
  const double _t642 = _t632 + _t633 + _t641;
  const double _t643 = _t193*_t377;
  const double _t644 = _t194*_t643;
  const double _t645 = (_t188 * _t188);
  const double _t646 = 0.2e1*_t572;
  const double _t648 = _hc8[1]*_t647;
  const double _t649 = _t10*_t648;
  const double _t650 = _hc6[0]*_t649;
  const double _t651 = ((_hc8[1]) * (_hc8[1]));
  const double _t653 = _t649*_t93;
  const double _t654 = 0.3e1*_hc7[0]*_t13*_t236*_t33*_t36*_t651*_t652*params->BB + (0.1e1 / 0.2e1)*_t236*_t651*_t652 - 0.1e1 / 0.2e1*_t650 - _t653;
  const double _t655 = ((_hc7[0]) * (_hc7[0]) * (_hc7[0]));
  const double _t657 = _t114*_t301*_t655*_t656;
  const double _t658 = 0.2e1*_t657;
  const double _t659 = _t40*_t645;
  const double _t660 = -_t191*_t654 + _t44*_t654 - _t645*_t646 + _t658*_t659;
  const double _t661 = _t135*_t660;
  const double _t662 = _t2*_t644 + _t2*_t661;
  const double _t663 = _t200*_t377;
  const double _t664 = _t194*_t663;
  const double _t665 = 0.6e1*_hc7[0]*_t13*_t236*_t33*_t36*_t651*_t652*params->BB + _t236*_t651*_t652 - _t650 - 0.2e1*_t653;
  const double _t666 = 0.2e1*_t599;
  const double _t667 = _t188*_t198;
  const double _t668 = -_t188*_t666 - _t191*_t665 + _t40*_t658*_t667 + _t44*_t665;
  const double _t669 = _t135*_t668;
  const double _t670 = _t2*_t669;
  const double _t671 = _t201*_t663;
  const double _t672 = (_t198 * _t198);
  const double _t673 = 0.12e2*_hc7[0]*_t13*_t236*_t33*_t36*_t651*_t652*params->BB + 0.2e1*_t236*_t651*_t652 - 0.2e1*_t650 - 0.4e1*_t653;
  const double _t674 = _t658*_t672;
  const double _t675 = -_t191*_t673 + _t40*_t674 + _t44*_t673 - _t646*_t672;
  const double _t676 = _t135*_t675;
  const double _t677 = _t201*_t643;
  const double d2F_dna2 = 0.2e1*_t136 + 0.2e1*_t140 + 0.2e1*_t143 + _t2*(_t298 + _t388) + _t204 + _t287*na + _t390 + _t391 + _t398;
  const double d2F_dna_dnb = _t144*_t455 + _t148 + _t160 + _t166 + _t2*(_t474 + _t487 + _t488 + _t489 + _t491 + _t493 + _t495) + _t398 + _t496 + _t497 + _t498;
  const double d2F_dnb2 = _t2*(_t519 + _t567) + _t398 + 0.2e1*_t496 + 0.2e1*_t497 + 0.2e1*_t498 + _t499 + _t513*nb + _t568 + _t569;
  const double d2F_dna_dgaa = _t596;
  const double d2F_dna_dgab = _t2*_t611 + _t202;
  const double d2F_dna_dgbb = _t596;
  const double d2F_dnb_dgaa = _t631;
  const double d2F_dnb_dgab = _t2*_t642 + _t202;
  const double d2F_dnb_dgbb = _t631;
  const double d2F_dgaa2 = _t662;
  const double d2F_dgaa_dgab = _t2*_t664 + _t670;
  const double d2F_dgaa_dgbb = _t662;
  const double d2F_dgab2 = _t2*_t671 + _t2*_t676;
  const double d2F_dgab_dgbb = _t2*_t677 + _t670;
  const double d2F_dgbb2 = _t662;
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
  const double _t700 = -_t1*_t19;
  const double _t701 = _t3 + _t700;
  const double _t711 = 0.6e1*_t65;
  const double _t712 = _t1*_t280;
  const double _t713 = -_t711 + _t712;
  const double _t714 = -_t713;
  const double _t721 = (0.28e2 / 0.9e1)*_t325;
  const double _t757 = (_t82 * _t82 * _t82);
  const double _t762 = -_t20 + _t407;
  const double _t767 = 0.12e2*_t104*_t16;
  const double _t774 = _t50*_t53;
  const double _t776 = 0.12e2*_t54;
  const double _t782 = 0.12e2*_t51;
  const double _t784 = 0.60e2*_t241;
  const double _t787 = 0.48e2*_t65;
  const double _t788 = _t19*nb;
  const double _t789 = 0.12e2*_t788;
  const double _t793 = 0.72e2*_t16;
  const double _t797 = 0.24e2*na;
  const double _t798 = _t65*_t797;
  const double _t802 = _t21*_t53;
  const double _t803 = 0.24e2*_t802;
  const double _t804 = 0.12e2*_t65 + _t803;
  const double _t808 = 0.24e2*_t788;
  const double _t815 = _t789*na;
  const double _t823 = _t103*na;
  const double _t828 = _t220*_t23;
  const double _t829 = _t105*_t828;
  const double _t835 = (0.1e1 / M_PI);
  const double _t837 = (0.14e2 / 0.27e2)*_t74;
  const double _t838 = xc_powr(_t2, -11, 3);
  const double _t877 = 0.24e2*_t19;
  const double _t878 = _t788*_t797;
  const double _t879 = (0.1e1 / 0.12e2)*_t236;
  const double _t894 = _t700 + _t79;
  const double _t906 = -0.2e1*_t65 + _t712;
  const double _t907 = -_t906;
  const double _t927 = _t1*_t711;
  const double _t929 = _t271*_t894;
  const double _t943 = 0.4e1*_t51;
  const double _t945 = 0.4e1*_t438*_t439;
  const double _t947 = 0.20e2*_t241;
  const double _t949 = 0.40e2*_t241;
  const double _t951 = _t274*_t450;
  const double _t954 = 0.48e2*_t16;
  const double _t955 = _t279 - _t803;
  const double _t957 = 0.16e2*_t1;
  const double _t966 = _t144*nb;
  const double _t969 = _t461*_t957;
  const double _t986 = 0.12e2*_t16*_t161;
  const double _t1009 = _t220*_t223;
  const double _t1036 = 0.32e2*_t65;
  const double _t1063 = _t506*_t701;
  const double _t1075 = _t104*_t280 + _t955 + _t986;
  const double _t1126 = _t711 + _t712;
  const double _t1127 = -_t1126;
  const double _t1132 = (_t150 * _t150 * _t150);
  const double _t1133 = _t20 + _t407;
  const double _t1135 = 0.12e2*_t19;
  const double _t1139 = _t1135*na;
  const double _t1158 = _t183*_t83;
  const double _t1159 = (0.2e1 / 0.3e1)*_t1158;
  const double _t1160 = _t576*_t879;
  const double _t1164 = _t10*_t183;
  const double _t1187 = (0.4e1 / 0.3e1)*_t1158;
  const double _t1188 = (0.1e1 / 0.6e1)*_t236;
  const double _t1189 = _t1188*_t576;
  const double _t1266 = _t10*_t647;
  const double _t1269 = _t647*_t7;
  const double _t678 = 0.3e1*_t121;
  const double _t679 = _t129*_t37;
  const double _t680 = _t304*_t679;
  const double _t681 = (0.1e1 / (_t42 * _t42 * _t42 * _t42));
  const double _t682 = _t305*_t681;
  const double _t683 = _t303*_t682;
  const double _t684 = 0.3e1*_t364;
  const double _t685 = _t124*_t371;
  const double _t686 = 0.4e1*_t337;
  const double _t687 = _t301*_t305;
  const double _t688 = _t125*_t304;
  const double _t689 = 0.2e1*_t371;
  const double _t690 = _t39*_t91;
  const double _t691 = _t310*_t690;
  const double _t692 = _hc6[3]*_t231 + (0.28e2 / 0.9e1)*_t326;
  const double _t693 = (0.28e2 / 0.3e1)*_t326 + (0.2e1 / 0.3e1)*_t327;
  const double _t694 = _t310*_t311;
  const double _t695 = (_t113 * _t113 * _t113);
  const double _t696 = _t117*_t119;
  const double _t697 = _t421*_t695;
  const double _t698 = 0.6e1*(_t115 * _t115 * _t115)/(_t35 * _t35 * _t35 * _t35);
  const double _t699 = 0.3e1*_t333;
  const double _t702 = 0.4e1*_hc6[2]*_t701 - _t90;
  const double _t703 = _t343*_t702;
  const double _t704 = 0.6e1*_t337;
  const double _t705 = _t339*_t704;
  const double _t706 = _t13*params->BB;
  const double _t707 = _t706*_t91;
  const double _t708 = _t310*_t707;
  const double _t709 = 0.3e1*_t118;
  const double _t710 = 0.3e1*_t331;
  const double _t715 = _hc6[2]*_t714;
  const double _t716 = _hc6[16]*_t57 + _hc8[12]*_t314;
  const double _t717 = -_hc8[15]*_t57;
  const double _t718 = _hc8[12]*_t82 + _t717;
  const double _t719 = _hc6[18]*_t57 + _hc8[15]*_t314;
  const double _t720 = _hc6[16]*_t82 - _t719;
  const double _t722 = _hc6[8]*_t231 + _hc8[5]*_t721;
  const double _t723 = _t82*(_hc6[6]*_t268 - _t314*_t718 - _t57*_t720 + _t722 + _t82*(_hc6[13]*_t82 - _t716));
  const double _t724 = _t268*_t316;
  const double _t725 = _hc8[7]*_t231;
  const double _t726 = _hc8[5]*_t268;
  const double _t727 = -_hc8[17]*_t57;
  const double _t728 = _hc8[15]*_t82 + _t727;
  const double _t729 = _t84*(-_t57*_t728 + _t718*_t82 + _t725 + _t726);
  const double _t730 = _hc6[19]*_t57 + _hc8[17]*_t314;
  const double _t731 = _hc6[9]*_t231 + _hc8[7]*_t721;
  const double _t732 = _hc6[8]*_t268 - _t314*_t728 - _t57*(_hc6[18]*_t82 - _t730) + _t720*_t82 + _t731;
  const double _t733 = _hc8[1]*_t12*_t256;
  const double _t734 = (0.560e3 / 0.27e2)*_t733;
  const double _t735 = _hc6[3]*_t74;
  const double _t736 = (0.28e2 / 0.27e2)*_t735;
  const double _t737 = -_t734 - _t736;
  const double _t738 = _t320*_t325;
  const double _t739 = _t230*_t323;
  const double _t740 = (0.112e3 / 0.9e1)*_t738 + (0.8e1 / 0.9e1)*_t739;
  const double _t741 = (0.1120e4 / 0.27e2)*_t733;
  const double _t742 = (0.56e2 / 0.27e2)*_t735;
  const double _t743 = -_t741 - _t742;
  const double _t744 = (0.3e1 / 0.2e1)*_hc0[2];
  const double _t745 = _t100*(-_t701*_t744 - _t96);
  const double _t746 = _t269*_t701;
  const double _t747 = _t220*_t285;
  const double _t748 = _hc3[1]*_t747;
  const double _t749 = _t392 + _t394 + _t395 + _t396 + _t397;
  const double _t750 = _t32*_t33*(-_t390 - _t391 + _t499 - _t701*_t748 - 0.2e1*_t746 + _t749) - 0.2e1*_t745;
  const double _t751 = -0.2e1*_t349 - 0.2e1*_t358 - 0.4e1*_t360 - 0.2e1*_t361;
  const double _t752 = _t338*_t422;
  const double _t753 = _t345*_t98;
  const double _t754 = _t29*_t33/xc_powi(_t30, 6);
  const double _t755 = _t753*_t754;
  const double _t756 = _t345*_t347;
  const double _t758 = (0.3e1 / 0.2e1)*_hc0[9];
  const double _t759 = (0.3e1 / 0.2e1)*_hc1[2];
  const double _t760 = (0.3e1 / 0.2e1)*_hc1[9];
  const double _t761 = (0.3e1 / 0.2e1)*_t428;
  const double _t763 = (0.3e1 / 0.2e1)*_t426;
  const double _t764 = _t268*_t761 + _t352*_t763 + _t713*_t759 + _t714*_t744 + _t757*_t758 + _t760*(_t81 * _t81 * _t81) + _t761*_t762 - _t762*_t763;
  const double _t765 = _t112*_t346;
  const double _t766 = _t112*_t99;
  const double _t768 = _hc3[0]*_t238;
  const double _t769 = _t51*_t768;
  const double _t770 = 0.12e2*_t769;
  const double _t771 = _t241*_t263;
  const double _t772 = 0.240e3*_t771;
  const double _t773 = _hc3[3]*_t141;
  const double _t775 = _t205*_t774;
  const double _t777 = _t268*_t440;
  const double _t778 = _hc2[0]*_hc3[2];
  const double _t779 = _t271*_t778;
  const double _t780 = _t18*_t238;
  const double _t781 = _t142*_t780;
  const double _t783 = _t205*_t227;
  const double _t785 = _t17*_t205;
  const double _t786 = _t106*nb;
  const double _t790 = _t283*_t789;
  const double _t791 = _t246*_t50*_t60;
  const double _t792 = 0.16e2*_t791;
  const double _t794 = _t248*_t793;
  const double _t795 = _t215*_t787;
  const double _t796 = _t283*nb;
  const double _t799 = _t277*_t59;
  const double _t800 = 0.4e1*_t142;
  const double _t801 = _t247*_t59;
  const double _t805 = _t145*_t789;
  const double _t806 = _t288*_t805;
  const double _t807 = _t291*_t805;
  const double _t809 = _hc2[2]*_t62*_t8;
  const double _t810 = _t462*_t798;
  const double _t811 = 0.4e1*_t75;
  const double _t812 = _t221*nb;
  const double _t813 = _hc3[1]*_t466;
  const double _t814 = _hc3[3]*_t466;
  const double _t816 = _t459*_t815;
  const double _t817 = _t215*na;
  const double _t818 = _t255*_t465;
  const double _t819 = _t258*_t465;
  const double _t820 = _t223*_t75;
  const double _t821 = _t800*_t820;
  const double _t822 = _t282*_t70;
  const double _t824 = _t75*_t823;
  const double _t825 = _t466*_t467;
  const double _t826 = _t222*_t255;
  const double _t827 = _t222*_t258;
  const double _t830 = _t820*_t823;
  const double _t831 = _t225*_t255;
  const double _t832 = _t225*_t258;
  const double _t833 = _t15*_t802;
  const double _t834 = _t21*_t60*_t61;
  const double _t836 = (0.1e1 / 0.36e2)*_hc5[21]*_t16*_t835;
  const double _t839 = -_hc2[2]*_t837 - 0.2e1 / 0.27e2*_t235*_t838 - _t57*(_hc2[5]*_t231 + _hc2[9]*_t244);
  const double _t840 = 0.120e3*_t242*_t438;
  const double _t841 = _t768*_t776;
  const double _t842 = _hc5[1]*_t837;
  const double _t843 = _hc5[6]*_t234;
  const double _t844 = (0.1e1 / 0.9e1)*_t838*_t843;
  const double _t845 = 0.10e2*_t17*_t60/xc_powr(_t2, 22, 3);
  const double _t846 = 0.96e2*_t248*_t461;
  const double _t847 = _hc4[21]*_t241*_t252*_t835;
  const double _t848 = _t72*nb;
  const double _t849 = (0.524e3 / 0.27e2)*_t257*_t61*_t848;
  const double _t850 = (0.10e2 / 0.9e1)*_t254*_t848/xc_powr(_t2, 17, 3);
  const double _t851 = _t239*_t839 - _t836 - _t840 - _t841 - _t842 - _t844 - _t845 - _t846 - _t847 - _t849 - _t850;
  const double _t852 = -0.144e3*_t833 - 0.6e1*_t834 + _t851;
  const double _t853 = _t15*_t767 - _t220*_t294*_t787 + _t268*_t446 + _t268*_t825 + _t269*_t714 + _t282*_t293*_t815 - _t288*_t809 - _t288*_t810 + _t288*_t816 - _t288*_t830 - _t291*_t809 - _t291*_t810 + _t291*_t816 - _t291*_t830 + _t294*_t808 + _t446*_t762 + _t449*_t793 + _t452*(0.18e2*_t104*_t16 - _t804) + _t714*_t813 - _t75*_t800*_t829 + _t757*_t773 + _t757*_t814 + _t762*_t825 + _t770 + _t772 - 0.96e2*_t775 - _t776*_t777 - _t776*_t779 + _t777*_t782 + _t779*_t782 + 0.3e1*_t781 + 0.36e2*_t783 + _t784*_t785 - _t786*_t787 + _t790 + _t792 + _t793*_t817 + _t794 - _t795 - _t796*_t798 - _t799*_t800 + _t800*_t801 + _t806 + _t807 - _t811*_t812 + (0.1e1 / 0.3e1)*_t818 + (0.32e2 / 0.3e1)*_t819 - _t821*nb - _t822*_t824 + (0.1e1 / 0.3e1)*_t826 + (0.32e2 / 0.3e1)*_t827 + (0.1e1 / 0.3e1)*_t831 + (0.32e2 / 0.3e1)*_t832 + _t852;
  const double _t854 = _t100*_t764 - 0.3e1*_t298*_t359 - _t34*_t853 - _t348*(-0.2e1*_t350 - 0.2e1*_t351 - 0.2e1*_t353 - 0.2e1*_t355) - 0.2e1*_t357*_t756 - 0.3e1*_t357*_t766 - 0.3e1*_t753*_t765 - _t755*(-0.5e1 / 0.2e1*_t94 - 0.5e1 / 0.2e1*_t95);
  const double _t855 = _hc6[0]*(-_t393*_t732 + 0.2e1*_t715 + 0.2e1*_t723 + 0.4e1*_t724 - 0.8e1 / 0.3e1*_t729 + _t737 + _t740) - _t120*_t362 - _t120*_t751 + 0.2e1*_t307*_t329 + _t312*(-_t308*_t323 + 0.3e1*_t313 + 0.3e1*_t317 - 0.4e1*_t321 + _t693) + 0.2e1*_t331*_t694 + _t338*_t697 + _t341*_t750 - 0.3e1*_t344*_t363 + _t362*_t752 - _t602*_t710 + _t691*_t89 - _t695*_t696 - _t696*_t854 - _t697*_t698 - _t699*_t703 + _t703*_t705 - _t708*_t709 + _t751*_t752 + _t88*(_t313 - _t314*_t320 + _t317 - _t323*_t57 + _t692) + _t93*(-_t415*_t732 + 0.4e1*_t715 + 0.4e1*_t723 + 0.8e1*_t724 - 0.16e2 / 0.3e1*_t729 + (0.224e3 / 0.9e1)*_t738 + (0.16e2 / 0.9e1)*_t739 + _t743);
  const double _t856 = _t125*_t698;
  const double _t857 = _t32*_t33*(_t111 - _t701*_t813 - _t746) - _t745;
  const double _t858 = _hc6[0]*(0.2e1*_hc6[2]*_t701 - _t87) - _t696*_t857 + _t702*_t93;
  const double _t859 = _t381*_t97;
  const double _t860 = _t380*_t859;
  const double _t861 = _t375*_t377;
  const double _t862 = _t380*_t382;
  const double _t863 = _t356*_t385;
  const double _t864 = 0.3e1*_t132;
  const double _t865 = _t132*_t375;
  const double _t866 = _t47/(_t133 * _t133 * _t133);
  const double _t867 = _t865*_t866;
  const double _t868 = _t134*_t30*params->gamma;
  const double _t869 = _t380*_t868;
  const double _t870 = _t869*_t97;
  const double _t871 = _t138*_t376;
  const double _t872 = _t871*_t97;
  const double _t873 = 0.96e2*_t264;
  const double _t874 = _t205*_t54;
  const double _t875 = 0.4e1*_t60;
  const double _t876 = _t277*_t875;
  const double _t880 = _t255*_t72;
  const double _t881 = (0.1e1 / 0.3e1)*_t880;
  const double _t882 = (0.32e2 / 0.3e1)*_t259;
  const double _t883 = (0.2e1 / 0.3e1)*_hc5[1]*_t230 + 0.3e1*_t240 + 0.60e2*_t243 + _t247*_t875 + _t794*na + _t843*_t879 + _t881*nb + _t882*nb;
  const double _t884 = 0.36e2*_t228 + _t883;
  const double _t885 = _t121*_t402;
  const double _t886 = 0.3e1*_t177 - 0.3e1*_t178;
  const double _t887 = _t121*_t124;
  const double _t888 = 0.2e1*_t887;
  const double _t889 = _t171*_t686;
  const double _t890 = 0.2e1*_t481;
  const double _t891 = -_t314*_t409 - _t411*_t57 + _t692;
  const double _t892 = _hc6[2]*_t1;
  const double _t893 = -_t308*_t411 - 0.4e1*_t410 + _t693;
  const double _t895 = 0.4e1*_hc6[2]*_t894 - _t90;
  const double _t896 = _t343*_t895;
  const double _t897 = _t404*_t707;
  const double _t898 = _t343*_t417;
  const double _t899 = _t100*(-_t155 - _t744*_t894);
  const double _t900 = _t269*_t894;
  const double _t901 = _t32*_t33*(_t167 - _t813*_t894 - _t900) - _t899;
  const double _t902 = _t32*_t33*(_t204 - _t568 - _t569 - _t748*_t894 + _t749 - 0.2e1*_t900) - 0.2e1*_t899;
  const double _t903 = _t698*_t901;
  const double _t904 = _t113*_t37;
  const double _t905 = _t889*_t904;
  const double _t908 = _hc6[2]*_t907;
  const double _t909 = _hc6[13]*_t150 - _t716;
  const double _t910 = _hc8[12]*_t150 + _t717;
  const double _t911 = _hc6[16]*_t150 - _t719;
  const double _t912 = -_t314*_t910 - _t57*_t911 + _t722;
  const double _t913 = _t82*(_hc6[6]*_t267 + _t82*_t909 + _t912);
  const double _t914 = _t268*_t405;
  const double _t915 = _hc8[15]*_t150 + _t727;
  const double _t916 = -_t57*_t915 + _t725;
  const double _t917 = _t84*(_hc8[5]*_t267 + _t82*_t910 + _t916);
  const double _t918 = _t325*_t409;
  const double _t919 = -_t314*_t915 - _t57*(_hc6[18]*_t150 - _t730) + _t731;
  const double _t920 = _hc6[8]*_t267 + _t82*_t911 + _t919;
  const double _t921 = _t230*_t411;
  const double _t922 = (0.112e3 / 0.9e1)*_t918 + (0.8e1 / 0.9e1)*_t921;
  const double _t923 = _t420*_t421;
  const double _t924 = 0.2e1*_t477;
  const double _t925 = -0.2e1*_t424 - 0.2e1*_t432 - 0.2e1*_t434 - 0.2e1*_t436 - 0.2e1*_t475;
  const double _t926 = -0.5e1 / 0.2e1*_t154 - 0.5e1 / 0.2e1*_t156;
  const double _t928 = (0.3e1 / 0.2e1)*_hc1[5]*_t149;
  const double _t930 = _hc0[5]*_t150;
  const double _t931 = (0.3e1 / 0.2e1)*_t930;
  const double _t932 = -0.6e1*_hc1[5]*_t1*_t65*_t81 + _t149*_t354*_t760 + _t268*_t931 + _t352*_t928 + _t428*_t927 + _t744*_t907 + _t758*_t929 + _t759*_t906;
  const double _t933 = _t423*_t98;
  const double _t934 = 0.2e1*_t933;
  const double _t935 = _t169*_t346;
  const double _t936 = 0.2e1*_t431;
  const double _t937 = 0.2e1*_t474;
  const double _t938 = _t441/xc_powi(_t2, 8);
  const double _t939 = _t17*_t440;
  const double _t940 = _t438*_t939;
  const double _t941 = _t453*_t780;
  const double _t942 = _t444*_t774;
  const double _t944 = _t778*_t82;
  const double _t946 = _t227*_t444;
  const double _t948 = _t150*_t939;
  const double _t950 = _t150*_t272;
  const double _t952 = _t451*_t951;
  const double _t953 = _t26*na;
  const double _t956 = _t274*_t454;
  const double _t958 = _t463*_t957;
  const double _t959 = _t164*na;
  const double _t960 = (0.4e1 / 0.3e1)*_t453;
  const double _t961 = (0.1e1 / 0.6e1)*_t213;
  const double _t962 = _t142*_t801;
  const double _t963 = _t1*_t241*_t463*na;
  const double _t964 = _t448*_t462;
  const double _t965 = _t24*_t454;
  const double _t967 = _t516*_t966;
  const double _t968 = _t285*_t468;
  const double _t970 = _hc3[1]*_t969*nb;
  const double _t971 = _t455*na;
  const double _t972 = _hc3[2]*_t150;
  const double _t973 = _t466*_t972;
  const double _t974 = _t295*_t459;
  const double _t975 = _t468*nb;
  const double _t976 = _t462*_t969;
  const double _t977 = _t217*nb;
  const double _t978 = _t255*_t470;
  const double _t979 = _t258*_t470;
  const double _t980 = _t142*_t217;
  const double _t981 = (0.2e1 / 0.3e1)*_hc3[1];
  const double _t982 = _t220*_t820*_t981;
  const double _t983 = _t223*_t471;
  const double _t984 = _t255*_t473;
  const double _t985 = _t258*_t473;
  const double _t987 = _t15*_t986;
  const double _t988 = 0.4e1*_t769;
  const double _t989 = 0.80e2*_t771;
  const double _t990 = _t150*_t944;
  const double _t991 = 0.8e1*_t51*_t990;
  const double _t992 = (0.16e2 / 0.3e1)*_t791;
  const double _t993 = _t987 + _t988 + _t989 + _t991 + _t992;
  const double _t994 = _t208*_t990;
  const double _t995 = _t439*_t59*_t981/xc_powr(_t2, 25, 3);
  const double _t996 = _t216*_t450*_t451;
  const double _t997 = _t146*_t216;
  const double _t998 = _t209*_t455;
  const double _t999 = _t216*_t458;
  const double _t1000 = _t216*_t460;
  const double _t1001 = _t221*_t502;
  const double _t1002 = _t469*_t977;
  const double _t1003 = (0.1e1 / 0.3e1)*_t213*_t468;
  const double _t1004 = _t216*_t462*_t468;
  const double _t1005 = _t220*_t70;
  const double _t1006 = _t1005*_t217*_t450;
  const double _t1007 = _t224*_t502;
  const double _t1008 = _t217*_t472;
  const double _t1010 = (0.8e1 / 0.3e1)*_hc3[1]*_t1*_t1009*_t246*_t257;
  const double _t1011 = _t162*_t828*_t980;
  const double _t1012 = _t23*_t454;
  const double _t1013 = _t1012*_t502;
  const double _t1014 = _t1013*_t105;
  const double _t1015 = _t1009*_t217*_t468;
  const double _t1016 = -_t1000 - _t1001 - _t1002 - _t1003 - _t1004 - _t1006 - _t1007 - _t1008 - _t1010 - _t1011 - _t1014 - _t1015 - _t210 - _t212 - _t218 - _t501 + 0.48e2*_t833 + 0.2e1*_t834 + _t851 - _t994 - _t995 - _t996 - _t997 - _t998 - _t999;
  const double _t1017 = _t1016 + _t144*_t282*_t965 - _t209*_t215 - _t209*_t786 - _t216*_t294*nb - _t217*_t812 + _t220*_t293*_t951 - _t224*_t977 + _t248*_t954 + _t249*_t953 + _t249*_t959 + _t249*_t971 + _t251*_t255 + _t260 + _t268*_t950 + _t268*_t973 - _t268*_t982 + _t269*_t907 + _t274*_t458 + _t275 + _t284 + _t286 - _t288*_t961 - _t288*_t964 + _t288*_t967 + _t290 - _t291*_t961 - _t291*_t964 + _t291*_t967 - _t291*_t983 + _t292 + _t296 - _t443*_t777 - _t443*_t779 - _t448*_t796 + _t449*_t954 + _t452*(_t161*_t280 + _t767 + _t955) + _t459*_t956 + _t459*_t970 + _t467*_t976 - _t471*_t822 + _t53*_t958 + _t773*_t929 - _t777*_t943 - _t779*_t943 + 0.2e1*_t781 - 0.24e2*_t783 + _t785*_t949 - _t799*_t960 + _t801*_t960 + _t813*_t907 + _t814*_t929 + _t817*_t954 + (0.2e1 / 0.9e1)*_t818 + (0.64e2 / 0.9e1)*_t819 + (0.2e1 / 0.9e1)*_t826 + (0.64e2 / 0.9e1)*_t827 - _t829*_t980 + (0.2e1 / 0.9e1)*_t831 + (0.64e2 / 0.9e1)*_t832 - 0.16e2*_t938 + 0.16e2*_t940 + _t941 - 0.32e2*_t942 + _t944*_t945 + 0.12e2*_t946 + _t947*_t948 + _t952 + (0.8e1 / 0.3e1)*_t962 - 0.32e2*_t963 + _t968*nb + _t974*_t975 + (0.1e1 / 0.9e1)*_t978 + (0.32e2 / 0.9e1)*_t979 + (0.1e1 / 0.9e1)*_t984 + (0.32e2 / 0.9e1)*_t985 + _t993;
  const double _t1018 = _t100*_t932 - _t1017*_t34 - _t298*_t433 - _t348*(-_hc0[2]*_t407 + 0.4e1*_hc1[2]*_t1*_t65 - 0.2e1*_t427 - 0.2e1*_t429) - _t357*_t435 - _t357*_t535 - _t359*_t937 - _t431*_t756 - _t753*_t935 - _t755*_t926 - _t765*_t934 - _t766*_t936;
  const double _t1019 = _hc6[0]*(_t316*_t407 - _t393*_t920 + _t737 + (0.56e2 / 0.9e1)*_t738 + (0.4e1 / 0.9e1)*_t739 + 0.2e1*_t908 + 0.2e1*_t913 + 0.2e1*_t914 - 0.8e1 / 0.3e1*_t917 + (0.56e2 / 0.9e1)*_t918 + (0.4e1 / 0.9e1)*_t921) - _t1018*_t696 - _t113*_t344*_t533 - _t119*_t339*_t903 - _t120*_t925 + _t152*_t691 - _t172*_t708 - _t173*_t362 + _t307*_t413 + _t312*(0.3e1*_t406 + _t711*_t892 + _t893) + _t329*_t403 - _t331*_t419 + _t331*_t522 - _t333*_t896 - _t334*_t901 + _t340*_t896 + _t341*_t901 + _t341*_t902 - _t342*_t897 - _t342*_t898 + _t344*_t905 - _t344*_t924 + _t362*_t923 - _t363*_t418 + _t417*_t694 + _t752*_t925 + _t88*(_hc6[2]*_t267 + _t406 + _t891) + _t93*(_t1*_t316*_t66 - _t415*_t920 + _t740 + _t743 + 0.4e1*_t908 + 0.4e1*_t913 + 0.4e1*_t914 - 0.16e2 / 0.3e1*_t917 + _t922);
  const double _t1020 = _hc6[0]*(0.2e1*_hc6[2]*_t894 - _t87) - _t696*_t901 + _t895*_t93;
  const double _t1021 = _t171*_t552;
  const double _t1022 = 0.2e1*_t121;
  const double _t1023 = 0.2e1*_t478;
  const double _t1024 = _t372*_t377;
  const double _t1025 = (0.1e1 / 0.2e1)*_t154 + (0.1e1 / 0.2e1)*_t156;
  const double _t1026 = 0.2e1*_t386;
  const double _t1027 = _t385*_t430;
  const double _t1028 = 0.2e1*_t1027;
  const double _t1029 = _t182*_t97;
  const double _t1030 = -0.2e1*_t175 - 0.2e1*_t181;
  const double _t1031 = _t157*_t871;
  const double _t1032 = _t494*_t868;
  const double _t1033 = _t1032*_t97;
  const double _t1034 = 0.2e1*_t132;
  const double _t1035 = 0.2e1*_t492;
  const double _t1037 = (0.8e1 / 0.3e1)*_t75;
  const double _t1038 = _t275*na + _t286*na + _t295*_t458 + _t389 + _t437 + 0.4e1*_t442 + 0.2e1*_t447 + _t454*_t974 + _t461*_t958 + _t468*_t747 + 0.2e1*_t487 + 0.2e1*_t488 + 0.2e1*_t489 + 0.2e1*_t491 + 0.2e1*_t493 + 0.2e1*_t495 + _t508*nb + _t512*nb + _t883 + _t952*na;
  const double _t1039 = _t402*_t679;
  const double _t1040 = _t179*_t37;
  const double _t1041 = _t401*_t886;
  const double _t1042 = _t125*_t686;
  const double _t1043 = 0.4e1*_t174;
  const double _t1044 = -_t1042*_t527 + _t1043*_t172 + 0.2e1*_t551 + 0.2e1*_t556 - 0.2e1*_t557;
  const double _t1045 = _t124*_t485;
  const double _t1046 = 0.2e1*_t521;
  const double _t1047 = _t523 + _t524 + _t891;
  const double _t1048 = 0.3e1*_t523 + 0.3e1*_t524 + _t893;
  const double _t1049 = _t118*_t706;
  const double _t1050 = _t153*_t404;
  const double _t1051 = _t16*_t892;
  const double _t1052 = _hc8[5]*_t504;
  const double _t1053 = _t84*(_t1052 + _t150*_t910 + _t916);
  const double _t1054 = (0.8e1 / 0.3e1)*_t1053;
  const double _t1055 = _hc6[8]*_t504 + _t150*_t911 + _t919;
  const double _t1056 = _t1055*_t393;
  const double _t1057 = _hc6[6]*_t504 + _t150*_t909 + _t912;
  const double _t1058 = (0.16e2 / 0.3e1)*_t1053;
  const double _t1059 = _t1055*_t415;
  const double _t1060 = -0.2e1*_t159 - 0.2e1*_t170;
  const double _t1061 = _t754*_t926;
  const double _t1062 = -0.2e1*_t538 - 0.2e1*_t539 - 0.2e1*_t541 - 0.2e1*_t542;
  const double _t1064 = -0.9e1*_hc0[2]*_t1*_t16 - 0.3e1*_hc0[2]*_t65 + 0.9e1*_hc1[2]*_t1*_t16 + _hc1[2]*_t425 - 0.6e1*_hc1[5]*_t1*_t149*_t65 + _t1063*_t758 + _t504*_t761 + _t537*_t760*_t81 + _t540*_t763 + _t927*_t930;
  const double _t1065 = _t158*_t423;
  const double _t1066 = 0.18e2*_t940;
  const double _t1067 = 0.22e2*_t938;
  const double _t1068 = _t440*_t504;
  const double _t1069 = _t1068*_t443;
  const double _t1070 = _t506*_t778;
  const double _t1071 = _t1070*_t443;
  const double _t1072 = 0.24e2*_t946;
  const double _t1073 = _t163*na;
  const double _t1074 = _t1073*_t209;
  const double _t1076 = _t448*_t511;
  const double _t1077 = _t145*_t453;
  const double _t1078 = _t1077*_t216;
  const double _t1079 = _t514*_t961;
  const double _t1080 = _t515*_t961;
  const double _t1081 = _t463*_t504;
  const double _t1082 = _t1081*_t448;
  const double _t1083 = _t462*_t515;
  const double _t1084 = _t1083*_t448;
  const double _t1085 = _t216*_t517;
  const double _t1086 = 0.56e2*_t963;
  const double _t1087 = _t469*_t502;
  const double _t1088 = _t1005*_t510*_t76;
  const double _t1089 = _t820*na;
  const double _t1090 = _t1089*_t960;
  const double _t1091 = _t504*_t982;
  const double _t1092 = _t515*_t983;
  const double _t1093 = _t1013*_t162;
  const double _t1094 = _t100*_t1064 - _t1061*_t933 - _t1062*_t348 - _t1065*_t765 - _t34*(0.48e2*_hc2[0]*_hc3[0]*_t21*_t53 + 0.40e2*_hc2[0]*_hc3[1]*_t150*_t17*_t241 + 0.12e2*_hc2[0]*_hc3[1]*_t16*_t21*_t82 + 0.4e1*_hc2[0]*_hc3[1]*_t16*_t50*_t504 + 0.20e2*_hc2[0]*_hc3[1]*_t17*_t241*_t82 + 0.32e2*_hc2[0]*_hc3[1]*_t50*_t53*_t82 + 0.4e1*_hc2[0]*_hc3[2]*_t150*_t438*_t439 + _hc2[0]*_hc3[2]*_t16*_t17*_t504*_t82 + 0.4e1*_hc2[0]*_hc3[2]*_t16*_t50*_t506 + _hc2[0]*_hc3[3]*_t16*_t17*_t506*_t701 + 0.2e1*_hc2[2]*_hc3[0]*_t21*_t5*_t6*_t61 + (0.8e1 / 0.3e1)*_hc2[2]*_hc3[1]*_t150*_t17*_t246*_t5*_t6 + (0.4e1 / 0.3e1)*_hc2[2]*_hc3[1]*_t17*_t246*_t5*_t6*_t82 + (0.4e1 / 0.3e1)*_hc2[2]*_hc3[1]*_t5*_t50*_t6*_t61*_t82 + 0.24e2*_hc3[0]*_hc4[0]*_t105*_t16*_t23*na*nb + 0.4e1*_hc3[0]*_hc4[0]*_t1075*_t19*_t23*na*nb + 0.48e2*_hc3[0]*_hc4[0]*_t16*_t162*_t23*na*nb + 0.48e2*_hc3[0]*_hc4[0]*_t16*_t22*_t23*na + 0.24e2*_hc3[0]*_hc4[0]*_t16*_t22*_t23*nb + 0.8e1*_hc3[0]*_hc4[0]*_t162*_t19*_t23 + 0.8e1*_hc3[0]*_hc4[0]*_t19*_t23*_t450*na + 0.4e1*_hc3[0]*_hc4[0]*_t19*_t23*_t510*nb + (0.32e2 / 0.9e1)*_hc3[0]*_hc4[1]*_t105*_t23*_t256*_t5*_t6*na*nb + (0.64e2 / 0.9e1)*_hc3[0]*_hc4[1]*_t162*_t23*_t256*_t5*_t6*na*nb + (0.64e2 / 0.9e1)*_hc3[0]*_hc4[1]*_t22*_t23*_t256*_t5*_t6*na + (0.32e2 / 0.9e1)*_hc3[0]*_hc4[1]*_t22*_t23*_t256*_t5*_t6*nb + (0.1e1 / 0.9e1)*_hc3[0]*_hc4[6]*_t105*_t23*_t232*_t233*_t253*na*nb + (0.2e1 / 0.9e1)*_hc3[0]*_hc4[6]*_t162*_t23*_t232*_t233*_t253*na*nb + (0.2e1 / 0.9e1)*_hc3[0]*_hc4[6]*_t22*_t23*_t232*_t233*_t253*na + (0.1e1 / 0.9e1)*_hc3[0]*_hc4[6]*_t22*_t23*_t232*_t233*_t253*nb + _hc3[0]*_t16*_t17*_t839 + 0.16e2*_hc3[1]*_hc4[0]*_t1*_t162*_t23*_t53*na*nb + 0.16e2*_hc3[1]*_hc4[0]*_t1*_t22*_t23*_t53*na + 0.8e1*_hc3[1]*_hc4[0]*_t105*_t150*_t19*_t23*na + 0.4e1*_hc3[1]*_hc4[0]*_t105*_t19*_t23*_t504*na*nb + 0.48e2*_hc3[1]*_hc4[0]*_t150*_t16*_t22*_t23*na*nb + 0.8e1*_hc3[1]*_hc4[0]*_t150*_t162*_t19*_t23*nb + 0.8e1*_hc3[1]*_hc4[0]*_t150*_t19*_t22*_t23 + 0.8e1*_hc3[1]*_hc4[0]*_t150*_t19*_t23*_t450*na*nb + 0.24e2*_hc3[1]*_hc4[0]*_t16*_t22*_t23*_t82*na*nb + 0.8e1*_hc3[1]*_hc4[0]*_t162*_t19*_t23*_t82*na + 0.4e1*_hc3[1]*_hc4[0]*_t19*_t22*_t23*_t504*nb + 0.4e1*_hc3[1]*_hc4[0]*_t19*_t23*_t510*_t82*na*nb + (0.64e2 / 0.9e1)*_hc3[1]*_hc4[1]*_t150*_t22*_t23*_t256*_t5*_t6*na*nb + (0.32e2 / 0.9e1)*_hc3[1]*_hc4[1]*_t22*_t23*_t256*_t5*_t6*_t82*na*nb + (0.2e1 / 0.9e1)*_hc3[1]*_hc4[6]*_t150*_t22*_t23*_t232*_t233*_t253*na*nb + (0.1e1 / 0.9e1)*_hc3[1]*_hc4[6]*_t22*_t23*_t232*_t233*_t253*_t82*na*nb + 0.2e1*_hc3[1]*_t150*_t16*_t17*_t238 + _hc3[1]*_t16*_t17*_t238*_t82 + 0.16e2*_hc3[2]*_hc4[0]*_t1*_t150*_t22*_t23*_t53*na*nb + 0.4e1*_hc3[2]*_hc4[0]*_t105*_t19*_t23*_t506*na*nb + 0.8e1*_hc3[2]*_hc4[0]*_t150*_t162*_t19*_t23*_t82*na*nb + 0.8e1*_hc3[2]*_hc4[0]*_t150*_t19*_t22*_t23*_t82*na + 0.4e1*_hc3[2]*_hc4[0]*_t19*_t22*_t23*_t504*_t82*na*nb + 0.4e1*_hc3[2]*_hc4[0]*_t19*_t22*_t23*_t506*nb + 0.4e1*_hc3[3]*_hc4[0]*_t19*_t22*_t23*_t506*_t701*na*nb - _t1000 - _t1001 - _t1002 - _t1003 - _t1004 - _t1006 - _t1007 - _t1008 - _t1010 - _t1011 - _t1014 - _t1015 - _t1066 - _t1067 - _t1069 - _t1071 - _t1072 - _t1074 - _t1076 - _t1078 - _t1079 - _t1080 - _t1082 - _t1084 - _t1085 - _t1086 - _t1087 - _t1088 - _t1090 - _t1091 - _t1092 - _t1093 - _t210 - _t212 - _t218 - _t464 - _t501 - _t836 - _t840 - _t841 - _t842 - _t844 - _t845 - _t846 - _t847 - _t849 - _t850 - _t993 - _t994 - _t995 - _t996 - _t997 - _t998 - _t999) - _t359*_t519 - _t431*_t546 - _t433*_t937 - _t535*_t936 - _t544*_t766 - _t934*_t935;
  const double _t1095 = _hc6[0]*_hc7[0]*_t151*_t33*_t36*_t404*_t91*params->BB + _hc6[0]*(-_hc6[2]*_t279 + 0.8e1*_t1*_t405*_t65 - 0.12e2*_t1051 - _t1054 - _t1056 + 0.2e1*_t1057*_t82 + (0.112e3 / 0.9e1)*_t12*_t409*_t73 + (0.8e1 / 0.9e1)*_t411*_t5*_t6*_t83 - _t734 - _t736) + _hc7[0]*_t1048*_t13*_t33*_t36*_t91*params->BB + 0.2e1*_hc7[0]*_t1060*_t113*_t14*_t171*_t33*_t335*_t336*params->BB + 0.2e1*_hc7[0]*_t113*_t14*_t33*_t335*_t336*_t548*params->BB + 0.4e1*_hc7[0]*_t113*_t153*_t171*_t33*_t335*_t336*_t92*params->BB + 0.2e1*_hc7[0]*_t13*_t33*_t36*_t404*_t417*params->BB + 0.4e1*_hc7[0]*_t14*_t171*_t33*_t335*_t336*_t476*params->BB + 0.2e1*_hc7[0]*_t14*_t33*_t335*_t336*_t527*_t857*params->BB + 0.2e1*_hc7[0]*_t33*_t335*_t336*_t527*_t702*_t92*params->BB + _hc7[0]*_t33*_t36*_t92*params->BB*(0.16e2*_t1*_t405*_t65 - 0.24e2*_t1051 + 0.4e1*_t1057*_t82 - _t1058 - _t1059 + (0.224e3 / 0.9e1)*_t12*_t409*_t73 + (0.16e2 / 0.9e1)*_t411*_t5*_t6*_t83 - _t414 - _t741 - _t742) + _t1047*_t88 - _t1049*_t1050 - _t1094*_t696 - _t113*_t534 - _t119*_t530*_t698*_t857 - _t120*_t548 - 0.2e1*_t173*_t476 - _t344*_t549 + 0.2e1*_t403*_t413 - _t418*_t924 - _t526*_t602 - _t528*_t703 - _t529*_t857 - _t533*_t897 - _t533*_t898;
  const double _t1096 = _t385*_t543;
  const double _t1097 = -_t559;
  const double _t1098 = _t1025*_t494;
  const double _t1099 = _t538 + _t539 + _t541 + _t542;
  const double _t1100 = _t377*_t486;
  const double _t1101 = 0.2e1*_t564;
  const double _t1102 = _t1032*_t157;
  const double _t1103 = _t492*_t866;
  const double _t1104 = _t1030*_t1103;
  const double _t1105 = _t1029*_t871;
  const double _t1106 = _t1031*_t132;
  const double _t1107 = _t25*na;
  const double _t1108 = _hc3[1]*_t145;
  const double _t1109 = _t453*_t801;
  const double _t1110 = _t459*_t966;
  const double _t1111 = _t444*_t54;
  const double _t1112 = _t1040*_t402;
  const double _t1113 = 0.3e1*_t174;
  const double _t1114 = _t125*_t179;
  const double _t1115 = 0.3e1*_t550;
  const double _t1116 = _t124*_t174;
  const double _t1117 = _t1114*_t301;
  const double _t1118 = _t153*_t39;
  const double _t1119 = (_t171 * _t171 * _t171);
  const double _t1120 = _t1119*_t421;
  const double _t1121 = 0.3e1*_t528;
  const double _t1122 = _t530*_t704;
  const double _t1123 = _t172*_t706;
  const double _t1124 = 0.3e1*_t1123;
  const double _t1125 = 0.3e1*_t526;
  const double _t1128 = _hc6[2]*_t1127;
  const double _t1129 = _t1057*_t150;
  const double _t1130 = _t405*_t504;
  const double _t1131 = -0.4e1*_t158*_t435 - 0.2e1*_t536 - 0.2e1*_t545 - 0.2e1*_t547;
  const double _t1134 = _t1126*_t759 + _t1127*_t744 + _t1132*_t758 - _t1133*_t928 + _t1133*_t931 + (_t149 * _t149 * _t149)*_t760 + _t504*_t931 + _t540*_t928;
  const double _t1136 = _t1107*_t510;
  const double _t1137 = _t1077*na;
  const double _t1138 = 0.4e1*_t453;
  const double _t1140 = _t516*na;
  const double _t1141 = _t469*_t811;
  const double _t1142 = _t1140*_t789;
  const double _t1143 = -_t1012*_t162*_t811*na - _t1068*_t776 - _t1068*_t782 - _t1070*_t776 - _t1070*_t782 - _t1073*_t787 - _t1081*_t798 - _t1083*_t798 - _t1089*_t1138 + _t1108*_t1139*_t504 + 0.4e1*_t1109 + _t1127*_t269 + _t1127*_t813 + _t1132*_t773 + _t1132*_t814 + _t1133*_t950 + _t1133*_t973 + _t1135*_t1136 - _t1137*_t787 + _t1138*_t799 + _t1139*_t145*_t515 + _t1140*_t453*_t877 - _t1140*_t454*_t787 - _t1141*na + _t1142*_t514 + _t1142*_t515 + _t24*_t453*_t510*_t815 + _t452*(0.18e2*_t16*_t161 - _t804) + _t504*_t950 + _t504*_t973 - _t510*_t70*_t824 - _t511*_t798 - _t514*_t809 - _t514*_t830 - _t515*_t809 - _t515*_t830 - _t770 - _t772 + _t784*_t948 - _t792 + _t793*_t953 + _t793*_t959 + _t793*_t971 + _t852 + _t881 + _t882 + 0.3e1*_t941 + 0.96e2*_t942 + 0.36e2*_t946 + (0.1e1 / 0.3e1)*_t978 + (0.32e2 / 0.3e1)*_t979 + (0.1e1 / 0.3e1)*_t984 + (0.32e2 / 0.3e1)*_t985 + _t987;
  const double _t1144 = _t100*_t1134 - _t1061*_t1065 - _t1062*_t158*_t347 - 0.3e1*_t1065*_t935 - _t1143*_t34 - 0.3e1*_t433*_t519 - 0.3e1*_t435*_t544 - 0.2e1*_t535*_t544;
  const double _t1145 = _hc6[0]*(-_t1054 - _t1056 + 0.2e1*_t1128 + 0.2e1*_t1129 + 0.4e1*_t1130 + _t737 + _t922) + _t1047*_t151 + _t1048*_t617 - _t1050*_t1124 + _t1118*_t152*_t404 - _t1119*_t696 + _t1120*_t338 - _t1120*_t698 - _t1121*_t896 + _t1122*_t896 - _t1125*_t419 - _t1131*_t173 + _t1131*_t923 - _t1144*_t696 - _t173*_t548 + 0.2e1*_t403*_t525 - 0.3e1*_t418*_t549 + 0.2e1*_t522*_t526 + _t532*_t902 + _t548*_t923 + _t93*(-_t1058 - _t1059 + 0.4e1*_t1128 + 0.4e1*_t1129 + 0.8e1*_t1130 + _t743 + (0.224e3 / 0.9e1)*_t918 + (0.16e2 / 0.9e1)*_t921);
  const double _t1146 = _t377*_t492;
  const double _t1147 = 0.3e1*_t182;
  const double _t1148 = _t805*na;
  const double _t1149 = -0.2e1*_t188*_t44 + 0.2e1*_t192;
  const double _t1150 = 0.4e1*_t36;
  const double _t1151 = _t1150*_t588;
  const double _t1152 = 0.3e1*_t189*_t41*_t681;
  const double _t1153 = _t1152*_t129;
  const double _t1154 = _t1153*_t303;
  const double _t1155 = (0.2e1 / 0.3e1)*_t575 + _t577*_t879;
  const double _t1156 = 0.2e1*_t575 + (0.1e1 / 0.4e1)*_t578;
  const double _t1157 = _t185*_t329;
  const double _t1161 = _hc8[15]*_t1160 + _hc8[5]*_t1159;
  const double _t1162 = _t82*((0.1e1 / 0.2e1)*_hc8[12]*_t10*_t183*_t82 - _t1161);
  const double _t1163 = _t1158*_t320;
  const double _t1165 = _t1164*_t726;
  const double _t1166 = _hc8[17]*_t1160 + _hc8[7]*_t1159;
  const double _t1167 = (0.1e1 / 0.2e1)*_hc8[15]*_t10*_t183*_t82 - _t1166;
  const double _t1168 = _t184*_t73;
  const double _t1169 = _t577*_t838;
  const double _t1170 = (0.28e2 / 0.9e1)*_t1168 + (0.2e1 / 0.9e1)*_t1169;
  const double _t1171 = _t185*_t311;
  const double _t1172 = (0.3e1 / 0.2e1)*_t1171;
  const double _t1173 = (0.56e2 / 0.9e1)*_t1168 + (0.4e1 / 0.9e1)*_t1169;
  const double _t1174 = -0.8e1 / 0.3e1*_t1163 + 0.2e1*_t1165 + _t1173;
  const double _t1175 = _t185*_t343;
  const double _t1176 = 0.2e1*_t1175;
  const double _t1177 = _t1175*_t339;
  const double _t1178 = _t185*_t707;
  const double _t1179 = _hc6[0]*(0.2e1*_t1162 - 0.4e1 / 0.3e1*_t1163 + _t1165 - _t1167*_t393 + _t1170) + (0.1e1 / 0.2e1)*_t1157 + _t1172*_t331 - _t1176*_t333 - _t1176*_t363 + _t1177*_t686 - _t1178*_t709 + _t186*_t691 + _t307*_t580 + _t312*((0.3e1 / 0.2e1)*_hc8[5]*_t10*_t183*_t82 - _t1156) - _t583*_t584 + _t583*_t694 + _t88*((0.1e1 / 0.2e1)*_hc8[5]*_t10*_t183*_t82 - _t1155) + _t93*(0.4e1*_t1162 - _t1167*_t415 + _t1174);
  const double _t1180 = _t41*_t587;
  const double _t1181 = _t1180*_t689;
  const double _t1182 = _t2*(_t1024*_t193 + _t1026*_t593 + _t1034*_t193*_t872 + _t1149*_t867 + _t135*(-_t1151*_t573 - _t1154*_t188 + _t1179*_t44 - _t1181*_t188 + _t180*(-_t1179*_t38 + _t188*_t333 - _t188*_t340 + _t188*_t363 + _t342*_t585) + _t188*_t680 + _t188*_t685 + _t300*_t585 - _t364*_t614 + _t592*_t688 + _t592*_t888 + _t687*(0.2e1*_t590 - 0.2e1*_t591)) + _t194*_t863 + _t194*_t870 - _t378*_t593 + _t593*_t861) + 0.2e1*_t570 + 0.2e1*_t571 + 0.2e1*_t594;
  const double _t1183 = _t200*_t872;
  const double _t1184 = -0.2e1*_t198*_t44 + 0.2e1*_t199;
  const double _t1185 = _hc8[7]*_t236;
  const double _t1186 = _t1185*_t183*_t8 + 0.4e1*_t575;
  const double _t1190 = _hc8[15]*_t1189 + _hc8[5]*_t1187;
  const double _t1191 = _t82*(_hc8[12]*_t10*_t183*_t82 - _t1190);
  const double _t1192 = _hc8[17]*_t1189 + _hc8[7]*_t1187;
  const double _t1193 = _hc8[15]*_t10*_t183*_t82 - _t1192;
  const double _t1194 = (0.112e3 / 0.9e1)*_t1168 + (0.8e1 / 0.9e1)*_t1169;
  const double _t1195 = _t343*_t603;
  const double _t1196 = 0.8e1*_t337;
  const double _t1197 = _hc6[0]*(_t1174 + 0.2e1*_t1191 - _t1193*_t393) + _t1157 + _t1171*_t710 + _t1177*_t1196 - 0.6e1*_t1178*_t118 - _t1195*_t333 - _t1195*_t363 + _t197*_t691 + _t307*_t583 + _t312*(0.3e1*_hc8[5]*_t10*_t183*_t82 - _t1186) + _t580*_t88 - _t584*_t601 + _t601*_t694 + _t93*(-0.16e2 / 0.3e1*_t1163 + 0.4e1*_t1165 + 0.4e1*_t1191 - _t1193*_t415 + _t1194);
  const double _t1198 = _t1103*_t132;
  const double _t1199 = -_t628;
  const double _t1200 = _t36*_t554;
  const double _t1201 = _t36*_t623;
  const double _t1202 = _t1153*_t401;
  const double _t1203 = 0.2e1*_t625 - 0.2e1*_t626;
  const double _t1204 = (0.1e1 / 0.2e1)*_hc8[5]*_t10*_t150*_t183 - _t1155;
  const double _t1205 = _t186*_t404;
  const double _t1206 = (0.3e1 / 0.2e1)*_hc8[5]*_t10*_t150*_t183 - _t1156;
  const double _t1207 = _t185*_t413;
  const double _t1208 = (0.1e1 / 0.2e1)*_hc8[12]*_t10*_t150*_t183 - _t1161;
  const double _t1209 = _t1208*_t82;
  const double _t1210 = _hc8[5]*_t1*_t183*_t256;
  const double _t1211 = (0.1e1 / 0.2e1)*_hc8[15]*_t10*_t150*_t183 - _t1166;
  const double _t1212 = _t1170 - _t1187*_t409 - _t1211*_t393;
  const double _t1213 = -_t1211*_t415;
  const double _t1214 = _t1158*_t409;
  const double _t1215 = _t1173 - 0.8e1 / 0.3e1*_t1214;
  const double _t1216 = 0.4e1*_t1210 + _t1215;
  const double _t1217 = _t153*_t185;
  const double _t1218 = _t1049*_t1217;
  const double _t1219 = _t1178*_t172;
  const double _t1220 = _hc6[0]*(0.2e1*_t1209 + 0.2e1*_t1210 + _t1212) - _t113*_t621 + _t1172*_t417 + _t1175*_t905 - _t1175*_t924 + _t1204*_t88 + _t1205*_t690 + _t1206*_t312 + (0.1e1 / 0.2e1)*_t1207 - 0.3e1 / 0.2e1*_t1218 - 0.3e1 / 0.2e1*_t1219 + _t403*_t580 - _t419*_t583 + _t522*_t583 - _t602*_t619 + _t93*(0.4e1*_t1209 + _t1213 + _t1216);
  const double _t1221 = _t485*_t587;
  const double _t1222 = _t420*_t904;
  const double _t1223 = _t2*(_t1027*_t194 + _t1033*_t194 + _t1100*_t193 + _t1105*_t193 + _t1106*_t193 + _t1146*_t593 + _t1149*_t1198 + _t1199*_t378 + _t135*(_t1039*_t188 + _t1045*_t188 + _t1116*_t592 - _t1200*_t589 - 0.2e1*_t1201*_t573 - _t1202*_t188 + _t1203*_t687 + _t1220*_t44 - _t1221*_t624 + _t180*(_t113*_t625 + _t118*_t622 - _t1220*_t38 - _t1222*_t188 + _t172*_t585 + _t188*_t477) + _t299*_t622 + _t399*_t585 - _t478*_t614 + _t521*_t592 + _t627*_t887) + _t386*_t628 + _t490*_t593) + _t595 + _t630;
  const double _t1224 = -_t640;
  const double _t1225 = _t1201*_t198;
  const double _t1226 = 0.2e1*_t637 - 0.2e1*_t638;
  const double _t1227 = _t197*_t404;
  const double _t1228 = 0.3e1*_hc8[5]*_t10*_t150*_t183 - _t1186;
  const double _t1229 = _hc8[12]*_t10*_t150*_t183 - _t1190;
  const double _t1230 = _t1229*_t82;
  const double _t1231 = _hc8[15]*_t10*_t150*_t183 - _t1192;
  const double _t1232 = -_t1231*_t393;
  const double _t1233 = _t1194 - 0.16e2 / 0.3e1*_t1214 - _t1231*_t415;
  const double _t1234 = _hc6[0]*(_t1216 + 0.2e1*_t1230 + _t1232) - _t113*_t635 + 0.3e1*_t1171*_t417 + _t1175*_t1196*_t171*_t904 - _t1195*_t477 + _t1207 - 0.3e1*_t1218 - 0.3e1*_t1219 + _t1227*_t690 + _t1228*_t312 + _t403*_t583 - _t419*_t601 + _t522*_t601 - _t602*_t634 + _t616*_t88 + _t93*(0.8e1*_t1210 + 0.4e1*_t1230 + _t1233);
  const double _t1235 = 0.2e1*_t182;
  const double _t1236 = _t1103*_t182;
  const double _t1237 = _t377*_t559;
  const double _t1238 = 0.2e1*_t1116;
  const double _t1239 = _t1152*_t179*_t401;
  const double _t1240 = _t185*_t525;
  const double _t1241 = _t1208*_t150;
  const double _t1242 = _t1052*_t1164;
  const double _t1243 = _t1215 + 0.2e1*_t1242;
  const double _t1244 = _t1175*_t530;
  const double _t1245 = _hc6[0]*(_t1212 + 0.2e1*_t1241 + _t1242) + _t1118*_t1205 - _t1124*_t1217 + _t1172*_t526 - _t1176*_t528 - _t1176*_t549 + _t1204*_t151 + _t1206*_t617 + (0.1e1 / 0.2e1)*_t1240 + _t1244*_t686 + _t403*_t616 + _t522*_t619 - _t619*_t620 + _t93*(_t1213 + 0.4e1*_t1241 + _t1243);
  const double _t1246 = _t124*_t558;
  const double _t1247 = _t558*_t587;
  const double _t1248 = _t2*(_t1031*_t1235*_t193 + _t1096*_t194 + _t1102*_t194 + _t1146*_t628 + _t1149*_t1236 + _t1199*_t562 + _t1237*_t193 + _t135*(-_t1043*_t1201*_t188 + _t1112*_t188 + _t1117*_t1203 + _t1238*_t627 - _t1239*_t188 + _t1245*_t44 + _t1246*_t188 - _t1247*_t624 + _t180*(-_t1245*_t38 + _t188*_t528 - _t188*_t531 + _t188*_t549 + _t533*_t622) + _t520*_t622 + _t521*_t627 - _t550*_t614) + _t566*_t628) + 0.2e1*_t612 + 0.2e1*_t613 + 0.2e1*_t629;
  const double _t1249 = _t1031*_t200;
  const double _t1250 = _t1229*_t150;
  const double _t1251 = _hc6[0]*(_t1232 + _t1243 + 0.2e1*_t1250) + _t1118*_t1227 - 0.6e1*_t1123*_t1217 + _t1125*_t1171 - _t1195*_t528 - _t1195*_t549 + _t1196*_t1244 + _t1228*_t617 + _t1240 + _t151*_t616 + _t403*_t619 + _t522*_t634 - _t620*_t634 + _t93*(_t1233 + 0.4e1*_t1242 + 0.4e1*_t1250);
  const double _t1252 = _t193*_t194;
  const double _t1253 = _t132*_t866;
  const double _t1254 = _t1253*_t193;
  const double _t1255 = -_t660;
  const double _t1256 = 0.2e1*_t643;
  const double _t1257 = _t121*_t572;
  const double _t1258 = 0.2e1*_t614;
  const double _t1259 = 0.6e1*_t681;
  const double _t1260 = _t114*_t655*_t656;
  const double _t1261 = _t1259*_t1260;
  const double _t1262 = _t1261*_t130;
  const double _t1263 = _t586*_t588;
  const double _t1264 = _t124*_t188;
  const double _t1265 = 0.2e1*_t1264;
  const double _t1267 = _t1266*_t319;
  const double _t1268 = _t648*_t83;
  const double _t1270 = _hc8[7]*_t1269;
  const double _t1271 = (0.2e1 / 0.3e1)*_t1268 + _t1270*_t879;
  const double _t1272 = _t649*_t88;
  const double _t1273 = _t1188*_t1270 + (0.4e1 / 0.3e1)*_t1268;
  const double _t1274 = -_t1267 + _t1273;
  const double _t1275 = _t312*_t649;
  const double _t1276 = _t236*_t651;
  const double _t1277 = _t1276*_t652;
  const double _t1278 = _t1277*_t690;
  const double _t1279 = _hc6[0]*_t1278;
  const double _t1280 = _t602*_t649;
  const double _t1281 = _t1049*_t1277;
  const double _t1282 = _t185*_t583;
  const double _t1283 = 0.3e1*_t311;
  const double _t1284 = _t1282*_t1283 + _t185*_t580;
  const double _t1285 = _hc6[0]*(-0.1e1 / 0.2e1*_t1267 + _t1271) - 0.1e1 / 0.4e1*_t1272 + _t1274*_t93 - 0.3e1 / 0.4e1*_t1275 + (0.3e1 / 0.2e1)*_t1279 + _t1280 - 0.3e1*_t1281 + _t1284;
  const double _t1286 = 0.4e1*_t1180;
  const double _t1287 = _t1286*_t188;
  const double _t1288 = _t644 + _t661;
  const double _t1289 = _t1288 + _t2*(_t1149*_t1254 + _t1252*_t872 + _t1255*_t378 + _t1256*_t593 + _t135*(-_t1151*_t645 + _t121*_t645*_t658 - _t1257*_t654 - _t1258*_t585 + _t1262*_t645 - _t1263*_t654 + _t1265*_t592 + _t1285*_t44 - _t1287*_t592 + _t180*(_t118*_t654 - _t1285*_t38) + _t299*_t654) + _t386*_t660);
  const double _t1290 = _t124*_t198;
  const double _t1291 = _t587*_t605;
  const double _t1292 = _t587*_t624;
  const double _t1293 = _t1185*_t1269;
  const double _t1294 = (0.8e1 / 0.3e1)*_t1268 + (0.1e1 / 0.3e1)*_t1293;
  const double _t1295 = -0.2e1*_t1267 + _t1294;
  const double _t1296 = 0.3e1*_hc6[0];
  const double _t1297 = _hc6[0]*_t1274 + _t1172*_t601 - 0.1e1 / 0.2e1*_t1272 - 0.3e1 / 0.2e1*_t1275 + _t1278*_t1296 - 0.6e1*_t1281 + (0.1e1 / 0.2e1)*_t1282 + _t1284 + _t1295*_t93 + _t584*_t649;
  const double _t1298 = -_t668;
  const double _t1299 = _t1298*_t378 + _t135*(-_t1151*_t667 - _t1257*_t665 + _t1262*_t667 - _t1263*_t665 + _t1264*_t608 + _t1290*_t592 - _t1291*_t592 - _t1292*_t608 + _t1297*_t44 + _t180*(_t118*_t665 - _t1297*_t38) + _t198*_t573*_t658 + _t299*_t665 - _t585*_t599 - _t604*_t614) + _t386*_t668 + _t593*_t663 + _t609*_t643;
  const double _t1300 = _t664 + _t669;
  const double _t1301 = _t1253*_t200;
  const double _t1302 = -_t675;
  const double _t1303 = 0.2e1*_t663;
  const double _t1304 = 0.2e1*_t1290;
  const double _t1305 = (0.16e2 / 0.3e1)*_t1268 + (0.2e1 / 0.3e1)*_t1293;
  const double _t1306 = 0.6e1*_t1171;
  const double _t1307 = _hc6[0]*_t1295 - _t1272 - 0.3e1*_t1275 + 0.6e1*_t1279 + 0.4e1*_t1280 - 0.12e2*_t1281 + 0.2e1*_t1282 + _t1306*_t601 + _t93*(-0.4e1*_t1267 + _t1305);
  const double _t1308 = _t1286*_t198;
  const double _t1309 = _t671 + _t676;
  const double _t1310 = _t193*_t201;
  const double _t1311 = _t669 + _t677;
  const double _t1312 = _t182*_t866;
  const double _t1313 = _t1312*_t193;
  const double _t1314 = _t554*_t657;
  const double _t1315 = _t174*_t572;
  const double _t1316 = _t1150*_t623;
  const double _t1317 = _t586*_t623;
  const double _t1318 = _t1266*_t408;
  const double _t1319 = _t151*_t649;
  const double _t1320 = _t1273 - _t1318;
  const double _t1321 = _t617*_t649;
  const double _t1322 = _t1118*_t1277;
  const double _t1323 = _hc6[0]*_t1322;
  const double _t1324 = _t419*_t649;
  const double _t1325 = _t185*_t619;
  const double _t1326 = _t1283*_t1325 + _t185*_t616;
  const double _t1327 = _hc6[0]*(_t1271 - 0.1e1 / 0.2e1*_t1318) - _t1124*_t1277 - 0.1e1 / 0.4e1*_t1319 + _t1320*_t93 - 0.3e1 / 0.4e1*_t1321 + (0.3e1 / 0.2e1)*_t1323 + _t1324 + _t1326;
  const double _t1328 = _t1288 + _t2*(_t1031*_t1252 + _t1149*_t1313 + _t1255*_t562 + _t1256*_t628 + _t135*(-_t1258*_t622 + _t1261*_t179*_t659 + _t1265*_t627 - _t1287*_t627 + _t1314*_t645 - _t1315*_t654 - _t1316*_t645 - _t1317*_t654 + _t1327*_t44 + _t180*(-_t1327*_t38 + _t172*_t654) + _t399*_t654) + _t490*_t660);
  const double _t1329 = _t40*_t681;
  const double _t1330 = 0.6e1*_t1260*_t1329*_t179;
  const double _t1331 = _t1294 - 0.2e1*_t1318;
  const double _t1332 = _t1123*_t1277;
  const double _t1333 = _hc6[0]*_t1320 + _t1172*_t634 + _t1296*_t1322 - 0.1e1 / 0.2e1*_t1319 - 0.3e1 / 0.2e1*_t1321 + (0.1e1 / 0.2e1)*_t1325 + _t1326 + _t1331*_t93 - 0.6e1*_t1332 + _t620*_t649;
  const double _t1334 = _t1298*_t562 + _t135*(_t1264*_t639 + _t1290*_t627 - _t1291*_t627 - _t1292*_t639 + _t1314*_t667 - _t1315*_t665 - _t1316*_t667 - _t1317*_t665 + _t1330*_t667 + _t1333*_t44 + _t180*(-_t1333*_t38 + _t172*_t665) + _t399*_t665 - _t599*_t622 - _t614*_t636) + _t490*_t668 + _t628*_t663 + _t640*_t643;
  const double _t1335 = _t1312*_t200;
  const double _t1336 = _hc6[0]*_t1331 + _t1306*_t634 - _t1319 - 0.3e1*_t1321 + 0.6e1*_t1323 + 0.4e1*_t1324 + 0.2e1*_t1325 - 0.12e2*_t1332 + _t93*(_t1305 - 0.4e1*_t1318);
  const double _t1337 = _t2*_t866;
  const double _t1338 = _t1252*_t1337;
  const double _t1339 = _t2*_t377;
  const double _t1340 = _t1339*_t194;
  const double _t1341 = _t1256*_t2;
  const double _t1342 = (_t188 * _t188 * _t188);
  const double _t1343 = ((_hc7[0]) * (_hc7[0]) * (_hc7[0]) * (_hc7[0]))*_t336/((params->gamma) * (params->gamma) * (params->gamma) * (params->gamma));
  const double _t1344 = _t1329*_t1343;
  const double _t1345 = _hc8[1]*_t10/xc_powr(_t11, 5, 2);
  const double _t1346 = _hc6[0]*_t1345;
  const double _t1347 = _t1276/(_t11 * _t11);
  const double _t1348 = ((_hc8[1]) * (_hc8[1]) * (_hc8[1]))*_t39*_t647;
  const double _t1349 = _t1348*_t16;
  const double _t1350 = _t1345*_t93;
  const double _t1351 = _t1347*_t311;
  const double _t1352 = _t1296*_t1349 + (0.3e1 / 0.4e1)*_t1346 - 0.3e1 / 0.4e1*_t1347 + (0.3e1 / 0.2e1)*_t1350 - 0.9e1 / 0.2e1*_t1351;
  const double _t1353 = _t135*_t2;
  const double _t1354 = _t1149*_t1338 + _t1255*_t1340 + _t1341*_t660 + _t1353*(_hc7[0]*_t1352*_t33*_t43 + 0.6e1*_t114*_t1342*_t301*_t655*_t656 + 0.6e1*_t114*_t188*_t301*_t40*_t654*_t655*_t656 - 0.6e1*_t1342*_t1344 - _t1352*_t191 - 0.6e1*_t614*_t654);
  const double _t1355 = _hc6[0]*_t1348;
  const double _t1356 = (0.3e1 / 0.2e1)*_t1346 - 0.3e1 / 0.2e1*_t1347 + 0.3e1*_t1350 - 0.9e1*_t1351 + _t1355*_t280;
  const double _t1357 = 0.4e1*_t665;
  const double _t1358 = _t1353*(_hc7[0]*_t1356*_t33*_t43 + 0.4e1*_t114*_t188*_t301*_t40*_t655*_t656*_t665 + 0.2e1*_t114*_t198*_t301*_t40*_t654*_t655*_t656 + 0.6e1*_t114*_t198*_t301*_t645*_t655*_t656 - _t1259*_t1343*_t198*_t659 - _t1356*_t191 - _t1357*_t614 - _t654*_t666);
  const double _t1359 = _t2*_t643;
  const double _t1360 = _t2*_t663;
  const double _t1361 = _t1298*_t1340 + _t1358 + _t1359*_t668 + _t1360*_t660;
  const double _t1362 = _t1337*_t200;
  const double _t1363 = _t1362*_t194;
  const double _t1364 = _t1303*_t2;
  const double _t1365 = 0.12e2*_hc6[0]*_t1349 + 0.3e1*_t1346 - 0.3e1*_t1347 + 0.6e1*_t1350 - 0.18e2*_t1351;
  const double _t1366 = 0.6e1*_t1344;
  const double _t1367 = _t1353*(_hc7[0]*_t1365*_t33*_t43 + 0.2e1*_t114*_t188*_t301*_t40*_t655*_t656*_t673 + 0.6e1*_t114*_t188*_t301*_t655*_t656*_t672 + 0.4e1*_t114*_t198*_t301*_t40*_t655*_t656*_t665 - _t1258*_t673 - _t1357*_t599 - _t1365*_t191 - _t1366*_t188*_t672);
  const double _t1368 = _t1362*_t201;
  const double _t1369 = _t1339*_t201;
  const double _t1370 = (_t198 * _t198 * _t198);
  const double _t1371 = 0.6e1*_t1346 - 0.6e1*_t1347 + 0.12e2*_t1350 - 0.36e2*_t1351 + _t1355*_t249;
  const double d3F_dna3 = _t146*_t808 + _t2*(_t135*(_t180*(_t118*_t684 + _t127*_t362 + _t127*_t751 + _t176*_t695 + _t176*_t854 - _t362*_t479 + _t363*_t678 - _t367*_t750 - _t38*_t855 - _t479*_t751 - _t552*_t695 + _t695*_t856 + _t699*_t858 - _t705*_t858) + _t299*_t684 + _t44*_t855 + _t678*_t680 + _t678*_t685 + _t683*(0.3e1*_t127 - 0.3e1*_t128) + _t687*(0.2e1*_t365 - _t366*_t686 + 0.4e1*_t368 + 0.2e1*_t369 - 0.2e1*_t370) + _t688*_t689) + _t139*_t764 + 0.2e1*_t356*_t862 - _t372*_t378 + 0.3e1*_t372*_t386 + 0.2e1*_t372*_t861 + _t375*_t864*_t872 + _t383*(_t350 + _t351 + _t353 + _t355) + _t853 + _t860*((0.1e1 / 0.2e1)*_t94 + (0.1e1 / 0.2e1)*_t95) + _t863*_t864 + _t864*_t870 + _t867*(-0.2e1*_t122 - 0.2e1*_t131)) + 0.24e2*_t206 - _t214 - _t220*_t821 - _t222*_t811 - _t248*_t787 + 0.3e1*_t270 + 0.3e1*_t273 + _t294*_t878 + 0.3e1*_t373 + 0.3e1*_t374 + 0.3e1*_t379 + 0.3e1*_t384 + 0.6e1*_t387 - _t449*_t787 - _t465*_t811 + _t786*_t877 + _t790*na - _t795*na + _t806*na + _t807*na - _t873 - 0.24e2*_t874 - _t876 + _t884;
  const double d3F_dna2_dnb = -_t1036*_t248 - _t1036*_t449 - _t1036*_t817 - _t1037*_t222 - _t1037*_t225 - _t1037*_t465 + _t1038 + _t2*(_t1017 + _t1024*_t492 + _t1025*_t860 + _t1026*_t486 + _t1028*_t132 + _t1029*_t869 + _t1030*_t867 + _t1031*_t865 + _t1033*_t1034 + _t1035*_t132*_t872 + _t135*(_t1019*_t44 + _t174*_t680 + _t174*_t685 + _t180*(_t1018*_t176 - _t1019*_t38 + _t1020*_t333 - _t1020*_t340 - _t1021*_t362 + _t1022*_t477 + _t1023*_t118 + _t113*_t890 - _t121*_t905 + _t127*_t925 + _t172*_t364 + _t174*_t363 + _t177*_t362 + _t365*_t901 + _t366*_t903 - _t367*_t901 - _t367*_t902 - _t479*_t925) + _t300*_t478 + _t364*_t399 + _t371*_t521 + _t485*_t688 + _t485*_t888 + 0.2e1*_t679*_t885 + _t683*_t886 + _t687*(-_t126*_t889 + _t171*_t302 + 0.2e1*_t482 + 0.2e1*_t483 - 0.2e1*_t484 + _t890)) + _t139*_t932 + _t182*_t863 + _t356*_t564 + _t372*_t490 - _t378*_t486 + _t383*(_hc0[2]*_t267 - _hc1[2]*_t267 + _t427 + _t429) + _t430*_t862 + _t486*_t861) - 0.2e1 / 0.3e1*_t214 + _t297 + _t388 + _t500 + _t503 - 0.16e2*_t874;
  const double d3F_dna_dnb2 = -_t1036*_t953 - _t1036*_t959 - _t1036*_t971 - _t1037*_t470 - _t1037*_t473 - _t1037*_t72 + _t1038 - 0.16e2*_t1111 + _t2*(_t1016 + _t1028*_t182 + 0.2e1*_t1029*_t1032 + _t1035*_t1100 + _t1035*_t1106 + _t1063*_t773 + _t1063*_t814 + _t1064*_t139 - _t1066 - _t1067 + _t1068*_t943 - _t1069 + _t1070*_t943 - _t1071 - _t1072 - _t1074 + _t1075*_t452 - _t1076 - _t1078 - _t1079 - _t1080 + _t1081*_t20 - _t1082 + _t1083*_t20 - _t1084 - _t1085 - _t1086 - _t1087 - _t1088 - _t1090 - _t1091 - _t1092 - _t1093 + _t1096*_t132 + _t1097*_t378 + _t1098*_t859 + _t1099*_t383 + _t1101*_t430 + _t1102*_t132 + _t1104*_t132 + _t1105*_t492 + _t1107*_t951 + _t1108*_t969 + (0.8e1 / 0.3e1)*_t1109 + _t1110*_t514 + _t1110*_t515 + _t135*(_t1039*_t554 + _t1040*_t885 + _t1041*_t682 + _t1044*_t687 + _t1045*_t554 + _t1046*_t485 + _t1095*_t44 + _t180*(_t1023*_t172 - _t1042*_t171*_t476 - _t1060*_t480 + _t1094*_t176 - _t1095*_t38 + _t113*_t555 + _t118*_t550 + _t121*_t549 + _t127*_t548 - _t174*_t905 + _t400*_t476 + _t477*_t554 - _t479*_t548 + _t527*_t856*_t857 + _t528*_t858 - _t531*_t858 + _t551*_t857 - _t553*_t857) + _t299*_t550 + _t478*_t520 + _t558*_t887) + (0.4e1 / 0.3e1)*_t142*_t799 + _t150*_t778*_t945 + _t20*_t511 + _t249*_t449 + _t249*_t817 + _t250 + (0.64e2 / 0.9e1)*_t259 + _t293*_t510*_t966 + _t295*_t457 + _t295*_t516*_t975 + _t386*_t559 + _t446*_t504 + _t453*_t974 - _t464 + _t486*_t566 + _t504*_t825 + _t508 + _t512 + _t516*_t956 + _t516*_t970 + 0.32e2*_t775 + _t781 + 0.12e2*_t783 + _t785*_t947 + (0.1e1 / 0.9e1)*_t818 + (0.32e2 / 0.9e1)*_t819 + (0.1e1 / 0.9e1)*_t826 + (0.32e2 / 0.9e1)*_t827 + (0.1e1 / 0.9e1)*_t831 + (0.32e2 / 0.9e1)*_t832 + (0.2e1 / 0.9e1)*_t880 + 0.2e1*_t941 + _t948*_t949 + _t951*_t965*na + _t953*_t954 + _t954*_t959 + _t954*_t971 + (0.4e1 / 0.3e1)*_t962 + _t968*na + _t972*_t976 + (0.2e1 / 0.9e1)*_t978 + (0.64e2 / 0.9e1)*_t979 + (0.2e1 / 0.9e1)*_t984 + (0.64e2 / 0.9e1)*_t985 - _t987 - _t988 - _t989 - _t991 - _t992) - _t207 + _t226 - 0.2e1 / 0.3e1*_t456 + _t518 + _t567;
  const double d3F_dnb3 = _t1073*_t877 - 0.24e2*_t1111 + _t1136*_t789 + _t1137*_t877 - _t1141*_t220 + _t1148*_t514 + _t1148*_t515 + 0.6e1*_t182*_t490 + _t2*(_t1031*_t1147*_t492 + _t1096*_t1147 + _t1097*_t562 + _t1098*_t157*_t381 + _t1099*_t157*_t382 + _t1101*_t543 + _t1102*_t1147 + _t1104*_t182 + _t1134*_t139 + _t1143 + 0.2e1*_t1146*_t559 + _t135*(_t1041*_t1114*_t681 + _t1044*_t1117 + _t1046*_t558 + _t1112*_t1113 + _t1115*_t399 + 0.3e1*_t1116*_t558 + _t1145*_t44 + _t180*(_t1020*_t1121 - _t1020*_t1122 - _t1021*_t1131 - _t1021*_t548 + _t1113*_t549 + _t1115*_t172 + _t1119*_t176 - _t1119*_t552 + _t1119*_t856 + _t1131*_t177 + _t1144*_t176 - _t1145*_t38 + _t177*_t548 - _t553*_t902)) + 0.3e1*_t490*_t559) - 0.24e2*_t445 + _t453*_t516*_t878 - _t456 - _t473*_t811 + 0.3e1*_t505 + 0.3e1*_t507 + 0.3e1*_t560 + 0.3e1*_t561 + 0.3e1*_t563 + 0.3e1*_t565 - _t72*_t811 - _t787*_t953 - _t787*_t959 - _t787*_t971 + _t873 + _t876 + _t884;
  const double d3F_dna2_dgaa = _t1182;
  const double d3F_dna2_dgab = _t2*(_t1024*_t200 + _t1026*_t609 + _t1034*_t1183 + _t1184*_t867 + _t135*(-_t1151*_t121*_t198 - _t1154*_t198 - _t1181*_t198 + _t1197*_t44 + _t180*(-_t1197*_t38 + _t198*_t333 - _t198*_t340 + _t198*_t363 + _t342*_t604) + _t198*_t680 + _t198*_t685 + _t300*_t604 - _t364*_t599 + _t608*_t688 + _t608*_t888 + _t687*(0.2e1*_t606 - 0.2e1*_t607)) + _t201*_t863 + _t201*_t870 - _t378*_t609 + _t609*_t861) + 0.2e1*_t597 + 0.2e1*_t598 + 0.2e1*_t610;
  const double d3F_dna2_dgbb = _t1182;
  const double d3F_dna_dnb_dgaa = _t1223;
  const double d3F_dna_dnb_dgab = _t2*(_t1027*_t201 + _t1033*_t201 + _t1100*_t200 + _t1105*_t200 + _t1106*_t200 + _t1146*_t609 + _t1184*_t1198 + _t1224*_t378 + _t135*(-_t1022*_t1225 + _t1039*_t198 + _t1045*_t198 + _t1116*_t608 - _t1200*_t198*_t588 - _t1202*_t198 - _t1221*_t605 + _t1226*_t687 + _t1234*_t44 + _t180*(_t113*_t637 + _t118*_t636 - _t1222*_t198 - _t1234*_t38 + _t172*_t604 + _t198*_t477) + _t299*_t636 + _t399*_t604 - _t478*_t599 + _t521*_t608 + _t639*_t887) + _t386*_t640 + _t490*_t609) + _t611 + _t642;
  const double d3F_dna_dnb_dgbb = _t1223;
  const double d3F_dnb2_dgaa = _t1248;
  const double d3F_dnb2_dgab = _t2*(_t1096*_t201 + _t1102*_t201 + _t1146*_t640 + _t1184*_t1236 + _t1224*_t562 + _t1235*_t1249 + _t1237*_t200 + _t135*(-_t1043*_t1225 + _t1112*_t198 + _t1117*_t1226 + _t1238*_t639 - _t1239*_t198 + _t1246*_t198 - _t1247*_t605 + _t1251*_t44 + _t180*(-_t1251*_t38 + _t198*_t528 - _t198*_t531 + _t198*_t549 + _t533*_t636) + _t520*_t636 + _t521*_t639 - _t550*_t599) + _t566*_t640) + 0.2e1*_t632 + 0.2e1*_t633 + 0.2e1*_t641;
  const double d3F_dnb2_dgbb = _t1248;
  const double d3F_dna_dgaa2 = _t1289;
  const double d3F_dna_dgaa_dgab = _t1300 + _t2*(_t1183*_t194 + _t1184*_t1254 + _t1299);
  const double d3F_dna_dgaa_dgbb = _t1289;
  const double d3F_dna_dgab2 = _t1309 + _t2*(_t1183*_t201 + _t1184*_t1301 + _t1302*_t378 + _t1303*_t609 + _t135*(-_t1151*_t672 + _t121*_t674 - _t1257*_t673 + _t1262*_t672 - _t1263*_t673 + _t1304*_t608 + _t1307*_t44 - _t1308*_t608 + _t180*(_t118*_t673 - _t1307*_t38) + _t299*_t673 - _t604*_t666) + _t386*_t675);
  const double d3F_dna_dgab_dgbb = _t1311 + _t2*(_t1149*_t1301 + _t1299 + _t1310*_t872);
  const double d3F_dna_dgbb2 = _t1289;
  const double d3F_dnb_dgaa2 = _t1328;
  const double d3F_dnb_dgaa_dgab = _t1300 + _t2*(_t1184*_t1313 + _t1249*_t194 + _t1334);
  const double d3F_dnb_dgaa_dgbb = _t1328;
  const double d3F_dnb_dgab2 = _t1309 + _t2*(_t1184*_t1335 + _t1249*_t201 + _t1302*_t562 + _t1303*_t640 + _t135*(_t1304*_t639 - _t1308*_t639 + _t1314*_t672 - _t1315*_t673 - _t1316*_t672 - _t1317*_t673 + _t1330*_t672 + _t1336*_t44 + _t180*(-_t1336*_t38 + _t172*_t673) + _t399*_t673 - _t636*_t666) + _t490*_t675);
  const double d3F_dnb_dgab_dgbb = _t1311 + _t2*(_t1031*_t1310 + _t1149*_t1335 + _t1334);
  const double d3F_dnb_dgbb2 = _t1328;
  const double d3F_dgaa3 = _t1354;
  const double d3F_dgaa2_dgab = _t1184*_t1338 + _t1361;
  const double d3F_dgaa2_dgbb = _t1354;
  const double d3F_dgaa_dgab2 = _t1184*_t1363 + _t1302*_t1340 + _t1364*_t668 + _t1367;
  const double d3F_dgaa_dgab_dgbb = _t1149*_t1363 + _t1361;
  const double d3F_dgaa_dgbb2 = _t1354;
  const double d3F_dgab3 = _t1184*_t1368 + _t1302*_t1369 + _t1353*(_hc7[0]*_t1371*_t33*_t43 + 0.6e1*_t114*_t1370*_t301*_t655*_t656 + 0.6e1*_t114*_t198*_t301*_t40*_t655*_t656*_t673 - _t1366*_t1370 - _t1371*_t191 - 0.6e1*_t599*_t673) + _t1364*_t675;
  const double d3F_dgab2_dgbb = _t1149*_t1368 + _t1298*_t1369 + _t1359*_t675 + _t1360*_t668 + _t1367;
  const double d3F_dgab_dgbb2 = _t1149*_t1310*_t1337 + _t1255*_t1369 + _t1341*_t668 + _t1358;
  const double d3F_dgbb3 = _t1354;
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
#endif
}
#endif