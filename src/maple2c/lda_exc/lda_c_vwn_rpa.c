/*
  Generated from python/lda_exc/lda_c_vwn_rpa.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_vwn_rpa
*/

#ifndef _LDA_C_VWN_RPA_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_VWN_RPA_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_VWN_RPA_HELPER_BODIES
#include "lda_c_vwn_rpa.c"
#undef _LDA_C_VWN_RPA_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_VWN_RPA_HELPER_BODIES
#include "lda_c_vwn_rpa.c"
#undef _LDA_C_VWN_RPA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_VWN_RPA_HELPER_BODIES
#include "lda_c_vwn_rpa.c"
#undef _LDA_C_VWN_RPA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_VWN_RPA_HELPER_BODIES
#include "lda_c_vwn_rpa.c"
#undef _LDA_C_VWN_RPA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_VWN_RPA_HELPER_BODIES
#include "lda_c_vwn_rpa.c"
#undef _LDA_C_VWN_RPA_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_vwn_rpa.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_VWN_RPA_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(one_minus_f_zeta_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (0.1e1 / 0.2e1)*z;
  const double _t2 = M_CBRT2;
  const double _t3 = _t2/(0.2e1*_t2 - 0.2e1);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t1 - 0.1e1 / 0.2e1, 0.4e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -_t1 - 0.1e1 / 0.2e1, 0.4e1 / 0.3e1, _hc1);

  const double f = _t3*(-0.2e1*_hc0[0] - 0.2e1*_hc1[0] - 0.2e1);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t3*(-_hc0[2] + _hc1[2]);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t3*(-0.1e1 / 0.2e1*_hc0[5] - 0.1e1 / 0.2e1*_hc1[5]);
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t3*(-0.1e1 / 0.4e1*_hc0[9] + (0.1e1 / 0.4e1)*_hc1[9]);
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t3*(-0.1e1 / 0.8e1*_hc0[14] - 0.1e1 / 0.8e1*_hc1[14]);
  out[4] = d4f_dz4;
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
  const double _t8 = 0.12e2*_t7;
  const double _t9 = _t1*_t7;
  const double _t10 = 0.3e1*_t5;
  const double _t11 = (b * b * b);
#endif
#if _KMAX >= 4
  const double _t12 = xc_powr(_t2, -7, 2);
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
  const double d3f_db_dc2 = -_t8*b;
  out[7] = d3f_db_dc2;
  const double d3f_db2_dc = _t6 + 0.6e1*_t9;
  out[8] = d3f_db2_dc;
  const double d3f_db3 = -_t10*b - 0.3e1*_t11*_t7;
  out[9] = d3f_db3;
#endif
#if _KMAX >= 4
  const double d4f_dc4 = -0.240e3*_t12;
  out[10] = d4f_dc4;
  const double d4f_db_dc3 = 0.120e3*_t12*b;
  out[11] = d4f_db_dc3;
  const double d4f_db2_dc2 = -0.60e2*_t1*_t12 - _t8;
  out[12] = d4f_db2_dc2;
  const double d4f_db3_dc = 0.30e2*_t11*_t12 + 0.18e2*_t7*b;
  out[13] = d4f_db3_dc;
  const double d4f_db4 = -_t10 - 0.15e2*_t12*(b * b * b * b) - 0.18e2*_t9;
  out[14] = d4f_db4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f1_vwn_k, _KMAX)(const xc_func_type *p, double b, double c, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
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
  const double _t11 = _hc0[6]*_t3;
  const double _t12 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t13 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t14 = 0.12e2*_t13;
  const double _t15 = _t12*_t14;
  const double _t16 = _t14*b;
  const double _t17 = _t16*_t8;
  const double _t18 = _hc0[1]*_t10;
  const double _t19 = 0.6e1*_t2;
  const double _t20 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 4
  const double _t21 = 0.16e2*_hc0[1];
  const double _t22 = xc_powi((_hc0[0]), -5);
  const double _t23 = _t22*b;
  const double _t24 = 0.48e2*_t23;
  const double _t25 = 0.12e2*_t7;
  const double _t26 = _t25*b;
  const double _t27 = _t13*_t8;
  const double _t28 = _t27*b;
  const double _t29 = 0.36e2*_t13;
  const double _t30 = _hc0[1]*_hc0[2]*b;
  const double _t31 = _t29*_t30;
  const double _t32 = _hc0[4]*_t7;
  const double _t33 = 0.8e1*_t7;
  const double _t34 = _t33*b;
  const double _t35 = 0.4e1*_t7*b;
  const double _t36 = 0.24e2*_hc0[2];
  const double _t37 = 0.48e2*_t20;
  const double _t38 = _t10*b;
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
  const double d3f_dc3 = 0.12e2*_hc0[1]*_hc0[3]*_t7*b - _t11*b - _t15*b;
  out[6] = d3f_dc3;
  const double d3f_db_dc2 = 0.8e1*_hc0[1]*_hc0[4]*_t7*b + 0.4e1*_hc0[2]*_hc0[3]*_t7*b - _hc0[2]*_t17 - _hc0[7]*_t5 - _t6 + 0.4e1*_t7*_t8;
  out[7] = d3f_db_dc2;
  const double d3f_db2_dc = 0.8e1*_hc0[1]*_hc0[2]*_t7 + 0.4e1*_hc0[1]*_hc0[5]*_t7*b + 0.8e1*_hc0[2]*_hc0[4]*_t7*b - _hc0[4]*_t9 - _hc0[8]*_t5 - _t16*_t18;
  out[8] = d3f_db2_dc;
  const double d3f_db3 = 0.12e2*_hc0[2]*_hc0[5]*_t7*b - _hc0[5]*_t19 - _hc0[9]*_t5 + 0.12e2*_t10*_t7 - _t16*_t20;
  out[9] = d3f_db3;
#endif
#if _KMAX >= 4
  const double d4f_dc4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t24 - _hc0[10]*_t5 + ((_hc0[3]) * (_hc0[3]))*_t26 - 0.72e2*_hc0[3]*_t28 + _hc0[6]*_t21*_t7*b;
  out[10] = d4f_dc4;
  const double d4f_db_dc3 = 0.12e2*_hc0[1]*_hc0[3]*_t7 + 0.12e2*_hc0[1]*_hc0[7]*_t7*b - _hc0[11]*_t5 + 0.4e1*_hc0[2]*_hc0[6]*_t7*b + 0.48e2*_hc0[2]*_t12*_t22*b + 0.12e2*_hc0[3]*_hc0[4]*_t7*b - _hc0[3]*_t31 - 0.36e2*_hc0[4]*_t28 - _t11 - _t15;
  out[11] = d4f_db_dc3;
  const double d4f_db2_dc2 = _hc0[1]*_hc0[8]*_t34 - _hc0[12]*_t5 + _hc0[2]*_hc0[3]*_t33 + _hc0[2]*_hc0[7]*_t34 + _hc0[3]*_hc0[5]*_t35 - _hc0[3]*_t10*_t16 + ((_hc0[4]) * (_hc0[4]))*_t34 - 0.48e2*_hc0[4]*_t13*_t30 - _hc0[5]*_t17 - _hc0[7]*_t9 + _t10*_t24*_t8 + _t21*_t32 - _t27*_t36;
  out[12] = d4f_db2_dc2;
  const double d4f_db3_dc = _hc0[1]*_hc0[5]*_t25 + _hc0[1]*_hc0[9]*_t35 + _hc0[1]*_t23*_t37 - _hc0[13]*_t5 + _hc0[2]*_hc0[8]*_t26 + _hc0[4]*_hc0[5]*_t26 - _hc0[4]*_t29*_t38 - _hc0[5]*_t31 - _hc0[8]*_t19 - _t18*_t29 + _t32*_t36;
  out[13] = d4f_db3_dc;
  const double d4f_db4 = -_hc0[14]*_t5 + 0.48e2*((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t22*b + 0.48e2*_hc0[2]*_hc0[5]*_t7 + 0.16e2*_hc0[2]*_hc0[9]*_t7*b + 0.12e2*((_hc0[5]) * (_hc0[5]))*_t7*b - 0.72e2*_hc0[5]*_t13*_t38 - 0.8e1*_hc0[9]*_t2 - _t13*_t37;
  out[14] = d4f_db4;
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
  const double _t18 = 0.2e1*_t13;
  const double _t19 = _t16*b;
  const double _t20 = _t11*_t13;
  const double _t21 = (x0 * x0 * x0);
#endif
#if _KMAX >= 3
  const double _t22 = 0.4e1*_t17;
  const double _t23 = _t13*_t2;
  const double _t24 = 0.4e1*_t23;
  const double _t25 = 0.3e1*b;
  const double _t26 = 0.6e1*x0;
  const double _t27 = -_t25 - _t26;
  const double _t28 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t29 = _t27*_t28;
  const double _t30 = _t15*_t29;
  const double _t31 = _t2*_t29;
  const double _t32 = 0.6e1*_t28;
  const double _t33 = _t2*_t32;
  const double _t34 = _t1*b;
  const double _t35 = _t32*b;
  const double _t36 = _t1*_t13;
  const double _t37 = 0.6e1*b;
  const double _t38 = _t15*_t18;
  const double _t39 = _t11*_t21;
  const double _t40 = 0.6e1*_t21;
  const double _t41 = (x0 * x0 * x0 * x0);
#endif
#if _KMAX >= 4
  const double _t42 = _t13*b;
  const double _t43 = _t15*_t33;
  const double _t44 = 0.8e1*_t31;
  const double _t45 = 0.4e1*b;
  const double _t46 = 0.8e1*x0;
  const double _t47 = -_t45 - _t46;
  const double _t48 = xc_powi(_t3, -5);
  const double _t49 = -0.24e2*_t13*b*x0 + _t27*_t43;
  const double _t50 = _t47*_t48;
  const double _t51 = _t2*_t50;
  const double _t52 = _t27*_t51;
  const double _t53 = 0.12e2*_t28;
  const double _t54 = _t2*_t53;
  const double _t55 = 0.24e2*_t48;
  const double _t56 = _t13*_t14;
  const double _t57 = _t27*_t50;
  const double _t58 = _t1*_t53;
  const double _t59 = _t58*b;
  const double _t60 = _t37*_t50;
  const double _t61 = _t21*b;
  const double _t62 = 0.18e2*_t28;
  const double _t63 = 0.24e2*_t28;
  const double _t64 = _t55*b;
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
  const double d2f_dc2 = _t18*_t2;
  out[6] = d2f_dc2;
  const double d2f_db_dx0 = -_t1*_t19 - _t10 + _t4 + _t6*_t7*x0;
  out[7] = d2f_db_dx0;
  const double d2f_db_dc = _t1*_t20 - _t7*x0;
  out[8] = d2f_db_dc;
  const double d2f_db2 = -0.2e1*_t1*_t7 + _t20*_t21;
  out[9] = d2f_db2;
#endif
#if _KMAX >= 3
  const double d3f_dx03 = 0.3e1*_t13*_t15*_t6*b + _t15*_t27*_t28*_t6*b*x0 - _t22 - _t24*_t6 - 0.6e1*_t9;
  out[10] = d3f_dx03;
  const double d3f_dc_dx02 = 0.4e1*_t13*b*x0 - _t15*_t20 - _t2*_t30;
  out[11] = d3f_dc_dx02;
  const double d3f_dc2_dx0 = _t20 + 0.2e1*_t31;
  out[12] = d3f_dc2_dx0;
  const double d3f_dc3 = -_t33;
  out[13] = d3f_dc3;
  const double d3f_db_dx02 = 0.4e1*_t1*_t13*b - _t12 + _t13*_t15*_t6*x0 - _t22 - _t30*_t34 - _t5*_t7 + 0.2e1*_t6*_t7;
  out[14] = d3f_db_dx02;
  const double d3f_db_dc_dx0 = _t1*_t11*_t29 - _t16*x0 + _t24 - _t7;
  out[15] = d3f_db_dc_dx0;
  const double d3f_db_dc2 = -_t1*_t35 + 0.2e1*_t13*x0;
  out[16] = d3f_db_dc2;
  const double d3f_db2_dx0 = -_t1*_t38 - _t14*_t7 + _t29*_t39 + _t36*_t37;
  out[17] = d3f_db2_dx0;
  const double d3f_db2_dc = 0.4e1*_t1*_t13 - _t28*_t40*b;
  out[18] = d3f_db2_dc;
  const double d3f_db3 = 0.6e1*_t13*_t21 - _t35*_t41;
  out[19] = d3f_db3;
#endif
#if _KMAX >= 4
  const double d4f_dx04 = 0.4e1*_t15*_t27*_t28*_t6*b + _t15*_t27*_t47*_t48*_t6*b*x0 - 0.16e2*_t19 - 0.16e2*_t42*_t6 - _t43*_t6 - _t44*_t6 - _t49;
  out[20] = d4f_dx04;
  const double d4f_dc_dx03 = -_t15*_t52 - _t25*_t30 + 0.12e2*_t42 + _t43 + _t44;
  out[21] = d4f_dc_dx03;
  const double d4f_dc2_dx02 = _t29*_t45 + 0.2e1*_t52 - _t54;
  out[22] = d4f_dc2_dx02;
  const double d4f_dc3_dx0 = -_t35 - 0.6e1*_t51;
  out[23] = d4f_dc3_dx0;
  const double d4f_dc4 = _t2*_t55;
  out[24] = d4f_dc4;
  const double d4f_db_dx03 = 0.6e1*_t1*_t15*_t28*b + 0.8e1*_t1*_t27*_t28*b + 0.3e1*_t13*_t15*_t6 - _t14*_t16 + _t15*_t27*_t28*_t6*x0 - _t15*_t34*_t57 - 0.6e1*_t19 - _t49 - _t56*_t6 - 0.6e1*_t7;
  out[25] = d4f_db_dx03;
  const double d4f_db_dc_dx02 = _t1*_t11*_t57 + _t13*_t45 - _t30*x0 - _t38 + _t44 + _t56 - _t59;
  out[26] = d4f_db_dc_dx02;
  const double d4f_db_dc2_dx0 = -_t1*_t60 + 0.2e1*_t13 + 0.2e1*_t27*_t28*x0 - _t54;
  out[27] = d4f_db_dc2_dx0;
  const double d4f_db_dc3 = -_t26*_t28 + _t34*_t55;
  out[28] = d4f_db_dc3;
  const double d4f_db2_dx02 = -0.2e1*_t1*_t30 - _t16*_t46 + 0.12e2*_t23 + _t27*_t59 + 0.8e1*_t36 + _t39*_t57 - _t53*_t61 - 0.4e1*_t7;
  out[29] = d4f_db2_dx02;
  const double d4f_db2_dc_dx0 = 0.4e1*_t1*_t27*_t28 + 0.8e1*_t13*x0 - _t34*_t62 - _t40*_t50*b;
  out[30] = d4f_db2_dc_dx0;
  const double d4f_db2_dc2 = _t55*_t61 - _t58;
  out[31] = d4f_db2_dc2;
  const double d4f_db3_dx0 = 0.18e2*_t1*_t13 + 0.6e1*_t21*_t27*_t28 - _t41*_t60 - _t61*_t63;
  out[32] = d4f_db3_dx0;
  const double d4f_db3_dc = -_t21*_t62 + _t41*_t64;
  out[33] = d4f_db3_dc;
  const double d4f_db4 = -_t41*_t63 + _t64*xc_powi(x0, 5);
  out[34] = d4f_db4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f3_vwn_k, _KMAX)(const xc_func_type *p, double b, double c, double x0, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
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
  const double _t11 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t12 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t13 = _t11*_t12;
  const double _t14 = 0.6e1*_t2;
  const double _t15 = -0.8e1*_hc0[1]*_hc0[2]*_t6 + _hc0[4]*_t5;
  const double _t16 = _hc0[2]*_t7;
  const double _t17 = _t11*_t14;
  const double _t18 = _hc0[1]*_t10;
  const double _t19 = _t11*_t18;
  const double _t20 = 0.6e1*_t3;
  const double _t21 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t22 = _t11*_t21;
#endif
#if _KMAX >= 4
  const double _t23 = _hc0[1]*_t6;
  const double _t24 = xc_powi((_hc0[0]), -5);
  const double _t25 = 0.24e2*_t2;
  const double _t26 = _t24*_t25;
  const double _t27 = _t14*_t6;
  const double _t28 = _t11*_t2;
  const double _t29 = _t28*_t7;
  const double _t30 = _hc0[7]*_t5;
  const double _t31 = 0.24e2*_t11;
  const double _t32 = _t16*_t31;
  const double _t33 = _hc0[1]*_hc0[2];
  const double _t34 = 0.18e2*_t28*_t33;
  const double _t35 = 0.18e2*_hc0[4];
  const double _t36 = _hc0[3]*_t6;
  const double _t37 = 0.4e1*_t2;
  const double _t38 = _hc0[2]*_t6;
  const double _t39 = 0.2e1*_t2;
  const double _t40 = _t10*_t28;
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
  const double d3f_dc3 = 0.6e1*_hc0[1]*_hc0[3]*_t2*_t6 - _hc0[6]*_t4 - _t13*_t14;
  out[13] = d3f_dc3;
  const double d3f_db_dx02 = 0;
  out[14] = d3f_db_dx02;
  const double d3f_db_dc_dx0 = -_t15;
  out[15] = d3f_db_dc_dx0;
  const double d3f_db_dc2 = 0.4e1*_hc0[1]*_hc0[4]*_t2*_t6 + 0.2e1*_hc0[2]*_hc0[3]*_t2*_t6 - _hc0[3]*_t9 - _hc0[7]*_t4 - _t16*_t17 + 0.4e1*_t6*_t7;
  out[16] = d3f_db_dc2;
  const double d3f_db2_dx0 = -_hc0[5]*_t5 + 0.8e1*_t10*_t6;
  out[17] = d3f_db2_dx0;
  const double d3f_db2_dc = 0.2e1*_hc0[1]*_hc0[5]*_t2*_t6 + 0.4e1*_hc0[2]*_hc0[4]*_t2*_t6 - _hc0[8]*_t4 - _t14*_t19 - _t15;
  out[18] = d3f_db2_dc;
  const double d3f_db3 = 0.6e1*_hc0[2]*_hc0[5]*_t2*_t6 - _hc0[5]*_t20 - _hc0[9]*_t4 + 0.12e2*_t10*_t6 - _t14*_t22;
  out[19] = d3f_db3;
#endif
#if _KMAX >= 4
  const double d4f_dx04 = 0;
  out[20] = d4f_dx04;
  const double d4f_dc_dx03 = 0;
  out[21] = d4f_dc_dx03;
  const double d4f_dc2_dx02 = 0;
  out[22] = d4f_dc2_dx02;
  const double d4f_dc3_dx0 = 0.24e2*_hc0[1]*_hc0[3]*_t6 - _hc0[6]*_t5 - 0.24e2*_t13;
  out[23] = d4f_dc3_dx0;
  const double d4f_dc4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t26 - _hc0[10]*_t4 + ((_hc0[3]) * (_hc0[3]))*_t27 - 0.36e2*_hc0[3]*_t29 + 0.8e1*_hc0[6]*_t2*_t23;
  out[24] = d4f_dc4;
  const double d4f_db_dx03 = 0;
  out[25] = d4f_db_dx03;
  const double d4f_db_dc_dx02 = 0;
  out[26] = d4f_db_dc_dx02;
  const double d4f_db_dc2_dx0 = 0.16e2*_hc0[1]*_hc0[4]*_t6 + 0.8e1*_hc0[2]*_hc0[3]*_t6 - _t30 - _t32;
  out[27] = d4f_db_dc2_dx0;
  const double d4f_db_dc3 = 0.12e2*_hc0[1]*_hc0[3]*_t6 + 0.6e1*_hc0[1]*_hc0[7]*_t2*_t6 - _hc0[11]*_t4 + 0.2e1*_hc0[2]*_hc0[6]*_t2*_t6 + 0.24e2*_hc0[2]*_t12*_t2*_t24 + 0.6e1*_hc0[3]*_hc0[4]*_t2*_t6 - _hc0[3]*_t34 - _hc0[6]*_t9 - 0.12e2*_t13 - _t29*_t35;
  out[28] = d4f_db_dc3;
  const double d4f_db2_dx02 = 0;
  out[29] = d4f_db2_dx02;
  const double d4f_db2_dc_dx0 = 0.8e1*_hc0[1]*_hc0[5]*_t6 + 0.16e2*_hc0[2]*_hc0[4]*_t6 - _hc0[8]*_t5 - _t18*_t31;
  out[30] = d4f_db2_dc_dx0;
  const double d4f_db2_dc2 = -_hc0[12]*_t4 + 0.8e1*_hc0[2]*_t36 - _hc0[3]*_t10*_t17 + ((_hc0[4]) * (_hc0[4]))*_t37*_t6 - _hc0[4]*_t11*_t25*_t33 + 0.16e2*_hc0[4]*_t23 - _hc0[5]*_t17*_t7 + _hc0[5]*_t36*_t39 + _hc0[7]*_t37*_t38 + _hc0[8]*_t23*_t37 + _t10*_t26*_t7 - _t30 - _t32;
  out[31] = d4f_db2_dc2;
  const double d4f_db3_dx0 = 0.24e2*_hc0[2]*_hc0[5]*_t6 - _hc0[9]*_t5 - 0.24e2*_t22;
  out[32] = d4f_db3_dx0;
  const double d4f_db3_dc = _hc0[1]*_t21*_t26 - _hc0[13]*_t4 + _hc0[2]*_hc0[8]*_t27 + _hc0[4]*_hc0[5]*_t27 + 0.24e2*_hc0[4]*_t38 + 0.12e2*_hc0[5]*_t23 - _hc0[5]*_t34 - _hc0[8]*_t20 + _hc0[9]*_t23*_t39 - 0.36e2*_t19 - _t35*_t40;
  out[33] = d4f_db3_dc;
  const double d4f_db4 = -_hc0[14]*_t4 + 0.24e2*((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t2*_t24 + 0.48e2*_hc0[2]*_hc0[5]*_t6 + 0.8e1*_hc0[2]*_hc0[9]*_t2*_t6 + 0.6e1*((_hc0[5]) * (_hc0[5]))*_t2*_t6 - 0.36e2*_hc0[5]*_t40 - 0.8e1*_hc0[9]*_t3 - 0.48e2*_t22;
  out[34] = d4f_db4;
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
#if _KMAX >= 3
  const double _t4 = (0.3e1 / 0.8e1)/xc_powr(rs, 5, 2);
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
  const double d3f_drs3 = _t4*b;
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
#if _KMAX >= 4
  const double d4f_drs4 = -0.15e2 / 0.16e2*b/xc_powr(rs, 7, 2);
  out[20] = d4f_drs4;
  const double d4f_dc_drs3 = 0;
  out[21] = d4f_dc_drs3;
  const double d4f_dc2_drs2 = 0;
  out[22] = d4f_dc2_drs2;
  const double d4f_dc3_drs = 0;
  out[23] = d4f_dc3_drs;
  const double d4f_dc4 = 0;
  out[24] = d4f_dc4;
  const double d4f_db_drs3 = _t4;
  out[25] = d4f_db_drs3;
  const double d4f_db_dc_drs2 = 0;
  out[26] = d4f_db_dc_drs2;
  const double d4f_db_dc2_drs = 0;
  out[27] = d4f_db_dc2_drs;
  const double d4f_db_dc3 = 0;
  out[28] = d4f_db_dc3;
  const double d4f_db2_drs2 = 0;
  out[29] = d4f_db2_drs2;
  const double d4f_db2_dc_drs = 0;
  out[30] = d4f_db2_dc_drs;
  const double d4f_db2_dc2 = 0;
  out[31] = d4f_db2_dc2;
  const double d4f_db3_drs = 0;
  out[32] = d4f_db3_drs;
  const double d4f_db3_dc = 0;
  out[33] = d4f_db3_dc;
  const double d4f_db4 = 0;
  out[34] = d4f_db4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_aux_k, _KMAX)(const xc_func_type *p, double A, double b, double c, double x0, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f2_vwn_k, _KMAX)(p, b, c, x0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(f3_vwn_k, _KMAX)(p, b, c, x0, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f1_vwn_k, _KMAX)(p, b, c, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(Q_vwn_k, _KMAX)(p, b, c, _hc3);
  double _hc4[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
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
  const double _t11 = (_t10 * _t10);
  const double _t12 = -_hc4[0] + _t11;
  const double _t13 = _t1*_t12;
  const double _t14 = xc_log1p(_t13);
  const double _t15 = -_hc0[0]*_t14 + _t4*_t9 + xc_log1p(_t3);
#if _KMAX >= 1
  const double _t16 = _t3 + 0.1e1;
  const double _t17 = (0.1e1 / _t16);
  const double _t18 = 0.1e1 - _hc4[1];
  const double _t19 = _t1*_t18;
  const double _t20 = (0.1e1 / ((_hc4[0]) * (_hc4[0])));
  const double _t21 = _hc4[1]*_t20;
  const double _t22 = _t19 - _t2*_t21;
  const double _t23 = ((_hc3[0]) * (_hc3[0]));
  const double _t24 = (0.1e1 / (_t7 * _t7));
  const double _t25 = _t23*_t24 + 0.1e1;
  const double _t26 = (0.1e1 / _t25);
  const double _t27 = _t26*_t4;
  const double _t28 = (0.1e1 / _t5);
  const double _t29 = _hc3[0]*_t24;
  const double _t30 = _t28*_t29;
  const double _t31 = -_hc4[1] + _t10*_t28;
  const double _t32 = _t1*_t31;
  const double _t33 = -_t12*_t21 + _t32;
  const double _t34 = _t13 + 0.1e1;
  const double _t35 = (0.1e1 / _t34);
  const double _t36 = _hc0[0]*_t35;
  const double _t37 = _t17*_t22 - _t27*_t30 - _t33*_t36;
  const double _t38 = -_hc0[0]*_hc1[1] - _hc0[1]*_hc1[0];
  const double _t39 = -_t6 + 0.2e1*x0;
  const double _t40 = _t1*_t36;
  const double _t41 = -_hc0[1]*_t14 + _t38*_t9 - _t39*_t40;
  const double _t42 = -_hc0[0]*_hc1[2] - _hc0[2]*_hc1[0] + _hc2[1];
  const double _t43 = _hc4[2]*_t1;
  const double _t44 = _hc4[2]*_t20;
  const double _t45 = _t2*_t44;
  const double _t46 = _t43 + _t45;
  const double _t47 = -_t46;
  const double _t48 = _hc3[1]*_t8;
  const double _t49 = _t12*_t44;
  const double _t50 = _t43 + _t49;
  const double _t51 = -_t50;
  const double _t52 = -_hc0[2]*_t14 + _t17*_t47 + _t27*_t48 - _t36*_t51 + _t42*_t9;
  const double _t53 = -_hc0[0]*_hc1[3] - _hc0[3]*_hc1[0] + _hc2[2];
  const double _t54 = _hc4[3]*_t1;
  const double _t55 = _hc4[3]*_t20;
  const double _t56 = _t2*_t55;
  const double _t57 = _t54 + _t56;
  const double _t58 = -_t57;
  const double _t59 = _hc3[2]*_t8 - _t29;
  const double _t60 = _t12*_t55;
  const double _t61 = _t54 + _t60;
  const double _t62 = -_t61;
  const double _t63 = -_hc0[3]*_t14 + _t17*_t58 + _t27*_t59 - _t36*_t62 + _t53*_t9;
#endif
#if _KMAX >= 2
  const double _t64 = xc_powr(rs, -3, 2);
  const double _t65 = (0.1e1 / 0.2e1)*_t64;
  const double _t66 = _t27*_t29;
  const double _t67 = (0.1e1 / rs);
  const double _t68 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t69 = 0.2e1*_t68;
  const double _t70 = _hc3[0]*_t69;
  const double _t71 = _t67*_t70;
  const double _t72 = (0.1e1 / (_t25 * _t25));
  const double _t73 = _t4*_t72;
  const double _t74 = xc_powi(_t7, -5);
  const double _t75 = ((_hc3[0]) * (_hc3[0]) * (_hc3[0]));
  const double _t76 = _t74*_t75;
  const double _t77 = _t67*_t76;
  const double _t78 = _hc4[4]*_t1;
  const double _t79 = _hc4[4]*_t20;
  const double _t80 = 0.2e1*_hc4[1];
  const double _t81 = _t20*_t80;
  const double _t82 = (0.1e1 / ((_hc4[0]) * (_hc4[0]) * (_hc4[0])));
  const double _t83 = ((_hc4[1]) * (_hc4[1]));
  const double _t84 = _t18*_t81 + _t2*_t79 - 0.2e1*_t2*_t82*_t83 + _t78;
  const double _t85 = -_t84;
  const double _t86 = (0.1e1 / (_t16 * _t16));
  const double _t87 = -_t22;
  const double _t88 = _t86*_t87;
  const double _t89 = (0.1e1 / (_t34 * _t34));
  const double _t90 = _hc0[0]*_t89;
  const double _t91 = -_t33;
  const double _t92 = _t33*_t91;
  const double _t93 = _t82*_t83;
  const double _t94 = 0.2e1*_t93;
  const double _t95 = _t10*_t64;
  const double _t96 = -_hc4[4] + (0.1e1 / 0.2e1)*_t67 - 0.1e1 / 0.2e1*_t95;
  const double _t97 = _t1*_t96;
  const double _t98 = -_t12*_t79 + _t12*_t94 - _t31*_t81 + _t97;
  const double _t99 = _t17*_t85 + _t22*_t88 + _t27*_t71 - _t36*_t98 + _t65*_t66 - 0.2e1*_t73*_t77 - _t90*_t92;
  const double _t100 = _t26*_t38;
  const double _t101 = _t33*_t35;
  const double _t102 = _t1*_t39;
  const double _t103 = _t90*_t91;
  const double _t104 = _hc0[0]*_hc4[1]*_t20*_t35*_t39 + _hc0[0]*_t1*_t28*_t35 - _hc0[1]*_t101 - _t100*_t30 - _t102*_t103;
  const double _t105 = 0.2e1*_hc0[1];
  const double _t106 = -_hc0[4]*_hc1[0] - _hc1[1]*_t105;
  const double _t107 = _t102*_t35;
  const double _t108 = (_t39 * _t39);
  const double _t109 = _hc0[0]*_t108*_t20*_t89 - _hc0[4]*_t14 - _t105*_t107 + _t106*_t9 - 0.2e1*_t40;
  const double _t110 = _hc3[1]*_t24;
  const double _t111 = _t110*_t28;
  const double _t112 = _t26*_t42;
  const double _t113 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t114 = _hc4[2]*_t21;
  const double _t115 = _t80*_t82;
  const double _t116 = _hc4[2]*_t2;
  const double _t117 = _t114 + _t115*_t116 - _t18*_t44;
  const double _t118 = _hc4[2]*_t115*_t12 + _t114 - _t31*_t44;
  const double _t119 = _t51*_t90;
  const double _t120 = -_hc0[2]*_t101 + 0.2e1*_hc3[1]*_t113*_t23*_t28*_t4*_t72 - _t111*_t27 - _t112*_t30 + _t117*_t17 - _t118*_t36 - _t119*_t91 + _t47*_t86*_t87;
  const double _t121 = -_hc0[0]*_hc1[5] - _hc0[1]*_hc1[2] - _hc0[2]*_hc1[1] - _hc0[5]*_hc1[0];
  const double _t122 = _hc0[2]*_t35;
  const double _t123 = _t36*_t39;
  const double _t124 = _hc0[1]*_t35;
  const double _t125 = -_hc0[5]*_t14 + _t100*_t48 + _t102*_t119 - _t102*_t122 + _t121*_t9 + _t123*_t44 - _t124*_t51;
  const double _t126 = 0.2e1*_hc0[2];
  const double _t127 = -_hc0[0]*_hc1[6] - _hc0[6]*_hc1[0] - _hc1[2]*_t126 + _hc2[3];
  const double _t128 = ((_hc4[2]) * (_hc4[2]));
  const double _t129 = 0.2e1*_t20;
  const double _t130 = _t128*_t129;
  const double _t131 = 0.2e1*_t82;
  const double _t132 = _t128*_t2;
  const double _t133 = _t130 + _t131*_t132;
  const double _t134 = ((_hc3[1]) * (_hc3[1]));
  const double _t135 = _t134*_t70;
  const double _t136 = _t35*_t51;
  const double _t137 = _t12*_t131;
  const double _t138 = _t128*_t137 + _t130;
  const double _t139 = -_hc0[6]*_t14 + 0.2e1*_hc3[1]*_t26*_t42*_t8 + _hc3[3]*_t26*_t4*_t8 - _t119*_t50 - _t126*_t136 + _t127*_t9 + _t133*_t17 - _t135*_t73 - _t138*_t36 + _t46*_t47*_t86;
  const double _t140 = _t26*_t53;
  const double _t141 = _hc3[2]*_t24;
  const double _t142 = -_t141*_t28 + _t28*_t70;
  const double _t143 = _t18*_t55;
  const double _t144 = _hc4[7]*_t20;
  const double _t145 = _hc4[7]*_t1;
  const double _t146 = -_hc4[1]*_hc4[3]*_t20 + _t145;
  const double _t147 = -0.2e1*_hc4[1]*_hc4[3]*_t2*_t82 + _t143 + _t144*_t2 + _t146;
  const double _t148 = -_t147;
  const double _t149 = _t62*_t90;
  const double _t150 = _t31*_t55;
  const double _t151 = -0.2e1*_hc4[1]*_hc4[3]*_t12*_t82 + _t12*_t144 + _t146 + _t150;
  const double _t152 = -_t151;
  const double _t153 = -_hc0[3]*_t101 - _t140*_t30 + _t142*_t26*_t4 + _t148*_t17 - _t149*_t91 - _t152*_t36 + 0.2e1*_t23*_t28*_t4*_t59*_t68*_t72 + _t58*_t86*_t87;
  const double _t154 = -_hc0[0]*_hc1[7] - _hc0[1]*_hc1[3] - _hc0[3]*_hc1[1] - _hc0[7]*_hc1[0];
  const double _t155 = _hc0[3]*_t35;
  const double _t156 = _t26*_t59;
  const double _t157 = -_hc0[7]*_t14 + _t102*_t149 - _t102*_t155 + _t123*_t55 - _t124*_t62 + _t154*_t9 + _t156*_t38;
  const double _t158 = -_hc0[0]*_hc1[8] - _hc0[2]*_hc1[3] - _hc0[3]*_hc1[2] - _hc0[8]*_hc1[0] + _hc2[4];
  const double _t159 = 0.2e1*_t44;
  const double _t160 = _hc4[3]*_t159;
  const double _t161 = _hc4[3]*_t131;
  const double _t162 = _t116*_t161 + _t160;
  const double _t163 = _hc3[4]*_t8 - _t110;
  const double _t164 = _hc4[2]*_hc4[3];
  const double _t165 = _t137*_t164 + _t160;
  const double _t166 = _t59*_t72;
  const double _t167 = _t166*_t4;
  const double _t168 = 0.2e1*_t29;
  const double _t169 = _hc3[1]*_t168;
  const double _t170 = -_hc0[3]*_t136 - _hc0[8]*_t14 + _hc3[1]*_t26*_t53*_t8 - _t122*_t62 - _t149*_t50 + _t158*_t9 + _t162*_t17 + _t163*_t26*_t4 - _t165*_t36 - _t167*_t169 + _t26*_t42*_t59 + _t46*_t58*_t86;
  const double _t171 = 0.2e1*_hc0[3];
  const double _t172 = -_hc0[0]*_hc1[9] - _hc0[9]*_hc1[0] - _hc1[3]*_t171 + _hc2[5];
  const double _t173 = ((_hc4[3]) * (_hc4[3]));
  const double _t174 = _t129*_t173;
  const double _t175 = _t131*_t173;
  const double _t176 = _t174 + _t175*_t2;
  const double _t177 = _t58*_t86;
  const double _t178 = _t35*_t62;
  const double _t179 = 0.2e1*_t53;
  const double _t180 = _t137*_t173 + _t174;
  const double _t181 = _hc3[5]*_t8 - 0.2e1*_t141 + _t70;
  const double _t182 = _t23*_t69;
  const double _t183 = -_hc3[2]*_t168 + _t182;
  const double _t184 = _t183*_t4;
  const double _t185 = -_hc0[9]*_t14 - _t149*_t61 + _t156*_t179 + _t166*_t184 + _t17*_t176 - _t171*_t178 + _t172*_t9 + _t177*_t57 - _t180*_t36 + _t181*_t27;
#endif
#if _KMAX >= 3
  const double _t186 = xc_powr(rs, -5, 2);
  const double _t187 = (0.3e1 / 0.4e1)*_t186;
  const double _t188 = (0.1e1 / (rs * rs));
  const double _t189 = 0.3e1*_t188;
  const double _t190 = _hc3[0]*_t68;
  const double _t191 = _t190*_t27;
  const double _t192 = 0.6e1*_t113;
  const double _t193 = _hc3[0]*_t192;
  const double _t194 = _t193*_t64;
  const double _t195 = xc_powi(_t7, -6);
  const double _t196 = _t4*_t64;
  const double _t197 = (0.1e1 / (_t25 * _t25 * _t25));
  const double _t198 = 0.8e1*_t197;
  const double _t199 = xc_powi((_hc3[0]), 5);
  const double _t200 = xc_powi(_t7, -8);
  const double _t201 = _t199*_t200;
  const double _t202 = _t198*_t201;
  const double _t203 = (0.1e1 / (_t16 * _t16 * _t16));
  const double _t204 = 0.2e1*_hc4[1]*_t2*_t20 - 0.2e1*_t19;
  const double _t205 = _hc4[10]*_t20;
  const double _t206 = 0.3e1*_t79;
  const double _t207 = (0.1e1 / ((_hc4[0]) * (_hc4[0]) * (_hc4[0]) * (_hc4[0])));
  const double _t208 = 0.6e1*_t207;
  const double _t209 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]));
  const double _t210 = _t2*_t209;
  const double _t211 = -0.6e1*_hc4[1]*_hc4[4]*_t2*_t82 - 0.3e1*_hc4[1]*_hc4[4]*_t20 + _hc4[10]*_t1 + _t18*_t206 - 0.6e1*_t18*_t82*_t83 + _t2*_t205 + _t208*_t210;
  const double _t212 = -_t211;
  const double _t213 = 0.2e1*_hc4[1]*_t12*_t20 - 0.2e1*_t32;
  const double _t214 = (0.1e1 / (_t34 * _t34 * _t34));
  const double _t215 = _hc0[0]*_t214;
  const double _t216 = _t213*_t215;
  const double _t217 = -_t98;
  const double _t218 = _t33*_t90;
  const double _t219 = 0.2e1*_t103;
  const double _t220 = _t12*_t208;
  const double _t221 = -_hc4[10] + (0.3e1 / 0.4e1)*_t10*_t186 - 0.3e1 / 0.4e1*_t188;
  const double _t222 = 0.3e1*_hc4[1];
  const double _t223 = _t20*_t222;
  const double _t224 = -0.6e1*_hc4[1]*_hc4[4]*_t12*_t82 - _t1*_t221 + _t12*_t205 + _t206*_t31 + _t209*_t220 + _t223*_t96 - 0.6e1*_t31*_t82*_t83;
  const double _t225 = -_t224;
  const double _t226 = _t17*_t212 - _t187*_t66 + 0.3e1*_t188*_t4*_t72*_t74*_t75 - _t189*_t191 - _t194*_t27 + 0.14e2*_t195*_t4*_t64*_t72*_t75 - _t196*_t202 + _t203*_t204*_t22*_t87 - _t216*_t92 - _t217*_t218 - _t219*_t98 + _t22*_t84*_t86 - _t225*_t36 + 0.2e1*_t85*_t86*_t87;
  const double _t227 = _t38*_t72;
  const double _t228 = 0.2e1*_t77;
  const double _t229 = _t89*_t92;
  const double _t230 = _t216*_t91;
  const double _t231 = _t217*_t90;
  const double _t232 = 0.2e1*_hc0[0]*_hc4[1]*_t20*_t39*_t89*_t91 + _hc0[0]*_hc4[4]*_t20*_t35*_t39 + 0.2e1*_hc0[0]*_t1*_t28*_t89*_t91 - _hc0[1]*_t229 + (0.1e1 / 0.2e1)*_hc3[0]*_t24*_t26*_t38*_t64 + 0.2e1*_hc3[0]*_t26*_t38*_t67*_t68 - _t102*_t230 - _t102*_t231 - _t123*_t94 - _t124*_t98 - _t227*_t228 - _t28*_t36*_t81 - _t40*_t65;
  const double _t233 = _t108*_t90;
  const double _t234 = _t28*_t39;
  const double _t235 = _t129*_t90;
  const double _t236 = _t106*_t26;
  const double _t237 = 0.2e1*_t1;
  const double _t238 = _t89*_t91;
  const double _t239 = _t105*_t238;
  const double _t240 = _t1*(_t234 + _t80) + _t12*_t81;
  const double _t241 = 0.2e1*_hc0[0]*_hc4[1]*_t20*_t35 + _hc0[0]*_t108*_t20*_t214*_t240 + 0.2e1*_hc0[1]*_hc4[1]*_t20*_t35*_t39 + 0.2e1*_hc0[1]*_t1*_t28*_t35 - _hc0[4]*_t101 - _t102*_t239 - _t103*_t237 - _t115*_t233 - _t234*_t235 - _t236*_t30;
  const double _t242 = 0.3e1*_hc1[1];
  const double _t243 = -_hc0[10]*_hc1[0] - _hc0[4]*_t242;
  const double _t244 = _t1*_t124;
  const double _t245 = -0.8e1*_t5 + 0.8e1*x0;
  const double _t246 = _t20*_t90;
  const double _t247 = _hc0[4]*_t35;
  const double _t248 = (_t39 * _t39 * _t39);
  const double _t249 = _t131*_t248;
  const double _t250 = _t108*_t20;
  const double _t251 = _t250*_t89;
  const double _t252 = 0.3e1*_hc0[1]*_t251 - _hc0[10]*_t14 - 0.3e1*_t102*_t247 - _t215*_t249 + _t235*_t39 + _t243*_t9 - 0.6e1*_t244 + _t245*_t246;
  const double _t253 = _t64*_t73;
  const double _t254 = _t113*_t23;
  const double _t255 = _hc3[1]*_t254;
  const double _t256 = _t23*_t74;
  const double _t257 = _hc3[1]*_t67;
  const double _t258 = _t256*_t257;
  const double _t259 = 0.10e2*_t258;
  const double _t260 = ((_hc3[0]) * (_hc3[0]) * (_hc3[0]) * (_hc3[0]));
  const double _t261 = xc_powi(_t7, -7);
  const double _t262 = _t42*_t72;
  const double _t263 = 0.2e1*_hc4[4];
  const double _t264 = -_hc4[2]*_t94;
  const double _t265 = 0.4e1*_t82;
  const double _t266 = _hc4[1]*_t265;
  const double _t267 = _hc4[2]*_t18;
  const double _t268 = _t263*_t82;
  const double _t269 = _t2*_t208;
  const double _t270 = _hc4[2]*_t83;
  const double _t271 = _t116*_t268 + _t263*_t44 + _t264 + _t266*_t267 - _t269*_t270;
  const double _t272 = _t216*_t51;
  const double _t273 = _hc4[2]*_t12*_t268 + _hc4[2]*_t266*_t31 + _hc4[4]*_t44 - _t220*_t270 + _t264 - _t44*_t96;
  const double _t274 = -_hc0[2]*_t229 + (0.1e1 / 0.2e1)*_hc3[0]*_t24*_t26*_t42*_t64 + 0.2e1*_hc3[0]*_t26*_t42*_t67*_t68 + 0.8e1*_hc3[1]*_t197*_t260*_t261*_t4*_t67 + (0.1e1 / 0.2e1)*_hc3[1]*_t24*_t26*_t4*_t64 + 0.2e1*_hc3[1]*_t26*_t4*_t67*_t68 + 0.2e1*_t117*_t86*_t87 - _t118*_t219 - _t119*_t217 - _t122*_t98 + _t17*_t271 + _t203*_t204*_t47*_t87 - _t228*_t262 - _t253*_t255 - _t259*_t73 - _t272*_t91 - _t273*_t36 + _t47*_t84*_t86;
  const double _t275 = _t28*_t36;
  const double _t276 = _t115*_t123;
  const double _t277 = _t26*_t30;
  const double _t278 = _t1*_t28;
  const double _t279 = _t21*_t39;
  const double _t280 = _hc0[2]*_t238;
  const double _t281 = _hc0[1]*_t51;
  const double _t282 = _hc0[0]*_hc4[2]*_t20*_t39*_t89*_t91 + _hc0[0]*_t1*_t118*_t39*_t89 + _hc0[0]*_t1*_t213*_t214*_t39*_t51 + _hc0[2]*_hc4[1]*_t20*_t35*_t39 + _hc0[2]*_t1*_t28*_t35 - _hc0[5]*_t101 + 0.2e1*_hc3[1]*_t113*_t23*_t28*_t38*_t72 - _hc4[2]*_t276 - _t100*_t111 - _t102*_t280 - _t118*_t124 - _t119*_t278 - _t119*_t279 - _t121*_t277 - _t238*_t281 - _t275*_t44;
  const double _t283 = _t126*_t35;
  const double _t284 = 0.2e1*_hc0[5];
  const double _t285 = -_hc0[11]*_hc1[0] - _hc0[4]*_hc1[2] - _hc1[1]*_t284 - _hc1[5]*_t105;
  const double _t286 = _hc0[2]*_t89;
  const double _t287 = _t35*_t39;
  const double _t288 = _t287*_t44;
  const double _t289 = _hc4[2]*_t131;
  const double _t290 = _t51*_t89;
  const double _t291 = _t105*_t290;
  const double _t292 = _t108*_t215;
  const double _t293 = _t129*_t292;
  const double _t294 = -_hc0[11]*_t14 - _hc0[4]*_t136 - _t1*_t283 + _t102*_t291 + _t105*_t288 - _t107*_t284 + _t119*_t237 + _t159*_t36 - _t233*_t289 + _t236*_t48 + _t250*_t286 + _t285*_t9 - _t293*_t51;
  const double _t295 = _hc3[3]*_t24;
  const double _t296 = _t28*_t295;
  const double _t297 = _t198*_t4;
  const double _t298 = _t195*_t75;
  const double _t299 = _t134*_t28*_t298;
  const double _t300 = _hc4[1]*_t128;
  const double _t301 = _t265*_t300;
  const double _t302 = _t132*_t208;
  const double _t303 = _hc4[1]*_t302 - 0.2e1*_t128*_t18*_t82 + _t301;
  const double _t304 = -_t303;
  const double _t305 = -_t117;
  const double _t306 = -0.2e1*_t128*_t31*_t82 + _t220*_t300 + _t301;
  const double _t307 = -_t306;
  const double _t308 = _t126*_t238;
  const double _t309 = _t50*_t90;
  const double _t310 = -_t118;
  const double _t311 = -_hc0[6]*_t101 + 0.6e1*_hc3[0]*_t113*_t134*_t28*_t4*_t72 + 0.4e1*_hc3[1]*_t113*_t23*_t28*_t42*_t72 + 0.2e1*_hc3[3]*_t113*_t23*_t28*_t4*_t72 - _t103*_t138 - 0.2e1*_t111*_t112 + _t117*_t46*_t86 - _t118*_t283 - _t118*_t309 - _t119*_t310 - _t127*_t277 + _t133*_t86*_t87 + _t17*_t304 + _t203*_t204*_t46*_t47 - _t27*_t296 - _t272*_t50 - _t297*_t299 + _t305*_t47*_t86 - _t307*_t36 - _t308*_t51;
  const double _t312 = _hc3[3]*_t8;
  const double _t313 = _t39*_t44;
  const double _t314 = -_hc0[0]*_hc1[12] - _hc0[1]*_hc1[6] - _hc0[12]*_hc1[0] - _hc0[6]*_hc1[1] - _hc1[2]*_t284 - _hc1[5]*_t126;
  const double _t315 = _t128*_t131;
  const double _t316 = _t26*_t48;
  const double _t317 = 0.2e1*_t316;
  const double _t318 = _t126*_t290;
  const double _t319 = _t102*_t90;
  const double _t320 = _t50*_t89;
  const double _t321 = _t50*_t51;
  const double _t322 = _t215*_t321;
  const double _t323 = 0.2e1*_t102;
  const double _t324 = -_hc0[12]*_t14 - _hc0[6]*_t107 + _t100*_t312 + _t102*_t318 - _t119*_t313 + _t121*_t317 - _t123*_t315 - _t124*_t138 - _t135*_t227 - _t136*_t284 + _t138*_t319 - _t281*_t320 + _t283*_t313 + _t309*_t313 + _t314*_t9 + _t322*_t323;
  const double _t325 = 0.3e1*_hc0[2];
  const double _t326 = 0.3e1*_hc1[2];
  const double _t327 = -_hc0[0]*_hc1[13] - _hc0[13]*_hc1[0] - _hc0[6]*_t326 - _hc1[6]*_t325 + _hc2[6];
  const double _t328 = ((_hc4[2]) * (_hc4[2]) * (_hc4[2]));
  const double _t329 = 0.6e1*_t82;
  const double _t330 = _t328*_t329;
  const double _t331 = _t269*_t328 + _t330;
  const double _t332 = -_t331;
  const double _t333 = ((_hc3[1]) * (_hc3[1]) * (_hc3[1]));
  const double _t334 = _t333*_t72;
  const double _t335 = _t334*_t69;
  const double _t336 = 0.6e1*_t68;
  const double _t337 = _hc3[0]*_t336;
  const double _t338 = _t337*_t73;
  const double _t339 = _hc3[1]*_hc3[3];
  const double _t340 = _hc3[0]*_t134;
  const double _t341 = _t336*_t340;
  const double _t342 = 0.3e1*_hc0[6];
  const double _t343 = _t220*_t328 + _t330;
  const double _t344 = -_t343;
  const double _t345 = 0.3e1*_t122;
  const double _t346 = -_t133;
  const double _t347 = 0.2e1*_t43;
  const double _t348 = _t347 + 0.2e1*_t45;
  const double _t349 = _t325*_t51;
  const double _t350 = 0.2e1*_t309;
  const double _t351 = -_t138;
  const double _t352 = _t347 + 0.2e1*_t49;
  const double _t353 = _t215*_t352;
  const double _t354 = -_hc0[13]*_t14 + 0.3e1*_hc3[1]*_t127*_t26*_t8 + 0.3e1*_hc3[3]*_t26*_t42*_t8 + _hc3[6]*_t26*_t4*_t8 - _t119*_t351 + 0.2e1*_t133*_t46*_t86 - _t136*_t342 - _t138*_t345 - _t138*_t350 + _t17*_t332 + 0.8e1*_t197*_t23*_t333*_t4*_t74 + _t203*_t348*_t46*_t47 - _t262*_t341 - _t320*_t349 - _t321*_t353 + _t327*_t9 - _t335*_t4 - _t338*_t339 - _t344*_t36 + _t346*_t47*_t86;
  const double _t355 = _t64*_t68;
  const double _t356 = _t23*_t355;
  const double _t357 = _t192*_t23;
  const double _t358 = _t357*_t67;
  const double _t359 = -_hc3[0]*_t355 + (0.1e1 / 0.2e1)*_hc3[2]*_t24*_t64 + 0.2e1*_hc3[2]*_t67*_t68 - _t193*_t67;
  const double _t360 = _hc4[14]*_t20;
  const double _t361 = _hc4[7]*_t129;
  const double _t362 = _hc4[3]*_t83;
  const double _t363 = -0.2e1*_hc4[1]*_hc4[7]*_t20 + _hc4[14]*_t1 + _hc4[3]*_t94;
  const double _t364 = -0.4e1*_hc4[1]*_hc4[3]*_t18*_t82 - 0.4e1*_hc4[1]*_hc4[7]*_t2*_t82 - 0.2e1*_hc4[3]*_hc4[4]*_t2*_t82 - 0.2e1*_hc4[3]*_hc4[4]*_t20 + _t18*_t361 + _t2*_t360 + _t269*_t362 + _t363;
  const double _t365 = -_t364;
  const double _t366 = _t216*_t62;
  const double _t367 = -0.4e1*_hc4[1]*_hc4[3]*_t31*_t82 - 0.4e1*_hc4[1]*_hc4[7]*_t12*_t82 - 0.2e1*_hc4[3]*_hc4[4]*_t12*_t82 - _hc4[3]*_hc4[4]*_t20 + _t12*_t360 + _t220*_t362 + _t31*_t361 + _t363 + _t55*_t96;
  const double _t368 = -_t367;
  const double _t369 = -_hc0[3]*_t229 + (0.1e1 / 0.2e1)*_hc3[0]*_t24*_t26*_t53*_t64 + 0.2e1*_hc3[0]*_t26*_t53*_t67*_t68 + 0.4e1*_t142*_t23*_t28*_t4*_t68*_t72 + 0.2e1*_t148*_t86*_t87 - _t149*_t217 - _t152*_t219 - _t155*_t98 - _t167*_t356 - _t167*_t358 + _t17*_t365 - _t179*_t72*_t77 + 0.8e1*_t195*_t197*_t260*_t4*_t59*_t67 + _t203*_t204*_t58*_t87 + _t26*_t359*_t4 - _t36*_t368 - _t366*_t91 + _t58*_t84*_t86;
  const double _t370 = _hc0[3]*_t238;
  const double _t371 = _t238*_t62;
  const double _t372 = _hc0[0]*_hc4[3]*_t20*_t39*_t89*_t91 + _hc0[0]*_hc4[7]*_t20*_t35*_t39 + _hc0[0]*_t1*_t152*_t39*_t89 + _hc0[0]*_t1*_t213*_t214*_t39*_t62 - _hc0[1]*_t371 + _hc0[3]*_hc4[1]*_t20*_t35*_t39 + _hc0[3]*_t1*_t28*_t35 - _hc0[7]*_t101 - _hc4[3]*_t276 - _t102*_t370 - _t124*_t152 + _t142*_t26*_t38 - _t149*_t278 - _t149*_t279 - _t154*_t277 + 0.2e1*_t23*_t28*_t38*_t59*_t68*_t72 - _t275*_t55;
  const double _t373 = _t171*_t35;
  const double _t374 = 0.2e1*_hc0[7];
  const double _t375 = -_hc0[14]*_hc1[0] - _hc0[4]*_hc1[3] - _hc1[1]*_t374 - _hc1[7]*_t105;
  const double _t376 = _t287*_t55;
  const double _t377 = _t62*_t89;
  const double _t378 = _t102*_t377;
  const double _t379 = _t215*_t62;
  const double _t380 = _t129*_t379;
  const double _t381 = -_hc0[14]*_t14 + _hc0[3]*_t251 - _hc0[4]*_t178 - _t1*_t373 + _t105*_t376 + _t105*_t378 + _t106*_t156 - _t107*_t374 - _t108*_t380 + _t149*_t237 - _t161*_t233 + 0.2e1*_t36*_t55 + _t375*_t9;
  const double _t382 = _hc3[1]*_t69;
  const double _t383 = _t24*_t28;
  const double _t384 = -_hc3[4]*_t383 + _t28*_t382;
  const double _t385 = _t28*_t4;
  const double _t386 = _t385*_t76;
  const double _t387 = 0.8e1*_hc3[1];
  const double _t388 = _t197*_t59;
  const double _t389 = _t387*_t388;
  const double _t390 = _t142*_t72;
  const double _t391 = _t390*_t4;
  const double _t392 = _t116*_t131;
  const double _t393 = _hc4[1]*_t164;
  const double _t394 = _hc4[7]*_t159 - _t164*_t266;
  const double _t395 = _hc4[7]*_t392 + _t161*_t267 - _t269*_t393 + _t394;
  const double _t396 = _hc0[3]*_t51;
  const double _t397 = _hc4[2]*_t31;
  const double _t398 = _hc4[2]*_t137;
  const double _t399 = _hc4[7]*_t398 + _t161*_t397 - _t220*_t393 + _t394;
  const double _t400 = -_hc0[2]*_t371 - _hc0[8]*_t101 + 0.4e1*_hc3[0]*_hc3[1]*_t28*_t4*_t59*_t68*_t72 + 0.2e1*_hc3[1]*_t113*_t23*_t28*_t53*_t72 - _t103*_t165 - _t111*_t140 - _t118*_t155 - _t122*_t152 + _t142*_t26*_t42 + _t148*_t46*_t86 - _t149*_t310 - _t152*_t309 - _t158*_t277 + _t162*_t86*_t87 + 0.2e1*_t163*_t23*_t28*_t4*_t68*_t72 - _t169*_t391 + _t17*_t395 + _t203*_t204*_t46*_t58 + 0.2e1*_t23*_t28*_t42*_t59*_t68*_t72 - _t238*_t396 + _t26*_t384*_t4 + _t305*_t58*_t86 - _t36*_t399 - _t366*_t50 - _t386*_t389;
  const double _t401 = _t122*_t39;
  const double _t402 = _t155*_t39;
  const double _t403 = _hc4[2]*_t161;
  const double _t404 = -_hc0[0]*_hc1[15] - _hc0[1]*_hc1[8] - _hc0[15]*_hc1[0] - _hc0[2]*_hc1[7] - _hc0[3]*_hc1[5] - _hc0[5]*_hc1[3] - _hc0[7]*_hc1[2] - _hc0[8]*_hc1[1];
  const double _t405 = _t39*_t55;
  const double _t406 = _t286*_t62;
  const double _t407 = _t396*_t89;
  const double _t408 = _t165*_t90;
  const double _t409 = _t166*_t38;
  const double _t410 = _hc0[1]*_t62;
  const double _t411 = _t379*_t50;
  const double _t412 = -_hc0[15]*_t14 - _hc0[5]*_t178 - _hc0[7]*_t136 - _hc0[8]*_t107 + _t100*_t163 + _t102*_t406 + _t102*_t407 + _t102*_t408 + _t121*_t156 - _t123*_t403 - _t124*_t165 - _t149*_t313 + _t154*_t316 - _t169*_t409 + _t309*_t405 - _t320*_t410 + _t323*_t411 + _t401*_t55 + _t402*_t44 + _t404*_t9;
  const double _t413 = _t128*_t329;
  const double _t414 = _hc4[3]*_t413;
  const double _t415 = _hc4[3]*_t302 + _t414;
  const double _t416 = -_t415;
  const double _t417 = 0.2e1*_hc0[8];
  const double _t418 = -_hc0[0]*_hc1[16] - _hc0[16]*_hc1[0] - _hc0[3]*_hc1[6] - _hc0[6]*_hc1[3] - _hc1[2]*_t417 - _hc1[8]*_t126 + _hc2[7];
  const double _t419 = _t135*_t72;
  const double _t420 = _hc3[7]*_t8 - _t295;
  const double _t421 = _t128*_t220;
  const double _t422 = _hc4[3]*_t421 + _t414;
  const double _t423 = -_t422;
  const double _t424 = _t163*_t72;
  const double _t425 = _t4*_t424;
  const double _t426 = 0.4e1*_t29;
  const double _t427 = _hc3[1]*_t426;
  const double _t428 = _hc3[3]*_t168;
  const double _t429 = 0.2e1*_t24;
  const double _t430 = _t134*_t429;
  const double _t431 = _t166*_t42;
  const double _t432 = _t320*_t62;
  const double _t433 = _t353*_t62;
  const double _t434 = -_hc0[16]*_t14 - _hc0[6]*_t178 + 0.2e1*_hc3[1]*_t158*_t26*_t8 + _hc3[3]*_t26*_t53*_t8 + 0.8e1*_t113*_t134*_t197*_t23*_t4*_t59 - _t126*_t432 + _t127*_t26*_t59 - _t136*_t417 - _t138*_t155 - _t149*_t351 + 0.2e1*_t162*_t46*_t86 + 0.2e1*_t163*_t26*_t42 - _t165*_t283 - _t165*_t350 - _t167*_t428 - _t167*_t430 + _t17*_t416 + _t203*_t348*_t46*_t58 + _t26*_t4*_t420 - _t320*_t396 + _t346*_t58*_t86 - _t36*_t423 + _t418*_t9 - _t419*_t53 - _t425*_t427 - _t427*_t431 - _t433*_t50;
  const double _t435 = _t142*_t26;
  const double _t436 = _t166*_t53;
  const double _t437 = 0.4e1*_t68;
  const double _t438 = _t23*_t437;
  const double _t439 = _t28*_t438;
  const double _t440 = _hc4[1]*_t173;
  const double _t441 = _hc4[3]*_t2;
  const double _t442 = _hc4[7]*_t265;
  const double _t443 = _t173*_t265;
  const double _t444 = 0.4e1*_t55;
  const double _t445 = -_hc4[1]*_t443 + _hc4[7]*_t444;
  const double _t446 = _t175*_t18 - _t269*_t440 + _t441*_t442 + _t445;
  const double _t447 = 0.4e1*_hc3[2]*_t28*_t68 - _hc3[5]*_t383 - _t193*_t28;
  const double _t448 = _t203*_t204;
  const double _t449 = _t57*_t58;
  const double _t450 = _t181*_t72;
  const double _t451 = _t4*_t450;
  const double _t452 = _t182*_t28;
  const double _t453 = _t57*_t86;
  const double _t454 = 0.4e1*_hc3[0]*_hc3[2]*_t28*_t68 - _t28*_t357;
  const double _t455 = _t184*_t72;
  const double _t456 = _t184*_t388;
  const double _t457 = _t152*_t35;
  const double _t458 = _hc4[3]*_t12;
  const double _t459 = _t175*_t31 - _t220*_t440 + _t442*_t458 + _t445;
  const double _t460 = _t61*_t90;
  const double _t461 = -_hc0[9]*_t101 - _t103*_t180 + _t142*_t455 + _t147*_t177 + _t148*_t453 - _t149*_t151 - _t152*_t460 + _t167*_t454 + _t17*_t446 - _t171*_t371 - _t171*_t457 - _t172*_t277 + _t176*_t88 + _t179*_t435 + _t27*_t447 - _t36*_t459 - _t366*_t61 + _t436*_t439 + _t439*_t456 + _t448*_t449 + _t451*_t452;
  const double _t462 = _hc0[9]*_t35;
  const double _t463 = -_hc0[0]*_hc1[17] - _hc0[1]*_hc1[9] - _hc0[17]*_hc1[0] - _hc0[9]*_hc1[1] - _hc1[3]*_t374 - _hc1[7]*_t171;
  const double _t464 = 0.2e1*_t156;
  const double _t465 = _t180*_t90;
  const double _t466 = _t410*_t89;
  const double _t467 = _t166*_t183;
  const double _t468 = _t379*_t61;
  const double _t469 = -_hc0[17]*_t14 + _t100*_t181 - _t102*_t462 + _t102*_t465 - _t123*_t175 - _t124*_t180 - _t149*_t405 + _t154*_t464 + _t171*_t378 - _t178*_t374 + _t323*_t468 + _t373*_t405 + _t38*_t467 + _t405*_t460 + _t463*_t9 - _t466*_t61;
  const double _t470 = _t173*_t329;
  const double _t471 = _hc4[2]*_t470;
  const double _t472 = _hc4[2]*_t173;
  const double _t473 = _t269*_t472 + _t471;
  const double _t474 = -_t473;
  const double _t475 = -_hc0[0]*_hc1[18] - _hc0[18]*_hc1[0] - _hc0[2]*_hc1[9] - _hc0[9]*_hc1[2] - _hc1[3]*_t417 - _hc1[8]*_t171 + _hc2[8];
  const double _t476 = -_t162;
  const double _t477 = _t220*_t472 + _t471;
  const double _t478 = -_t477;
  const double _t479 = -_hc3[4]*_t429 + _hc3[8]*_t8 + _t382;
  const double _t480 = -_t165;
  const double _t481 = 0.2e1*_hc3[2];
  const double _t482 = 0.4e1*_hc3[0]*_hc3[1]*_t68 - _hc3[4]*_t168 - _t110*_t481;
  const double _t483 = -_hc0[18]*_t14 - _hc0[9]*_t136 + _hc3[1]*_t172*_t26*_t8 - _t122*_t180 - _t149*_t480 + 0.2e1*_t158*_t26*_t59 + _t162*_t57*_t86 + _t163*_t183*_t4*_t72 + 0.2e1*_t163*_t26*_t53 - _t165*_t373 - _t165*_t460 - _t169*_t451 + _t17*_t474 - _t171*_t432 + _t176*_t46*_t86 - _t178*_t417 - _t180*_t309 + _t181*_t26*_t42 + _t183*_t42*_t59*_t72 + _t203*_t348*_t57*_t58 + _t26*_t4*_t479 - _t36*_t478 + _t4*_t482*_t59*_t72 - _t406*_t61 - _t427*_t436 - _t427*_t456 - _t433*_t61 + _t475*_t9 + _t476*_t58*_t86;
  const double _t484 = 0.3e1*_hc0[3];
  const double _t485 = 0.3e1*_hc1[3];
  const double _t486 = -_hc0[0]*_hc1[19] - _hc0[19]*_hc1[0] - _hc0[9]*_t485 - _hc1[9]*_t484 + _hc2[9];
  const double _t487 = ((_hc4[3]) * (_hc4[3]) * (_hc4[3]));
  const double _t488 = _t329*_t487;
  const double _t489 = _t269*_t487 + _t488;
  const double _t490 = -_t489;
  const double _t491 = 0.3e1*_hc0[9];
  const double _t492 = 0.2e1*_t453;
  const double _t493 = _t220*_t487 + _t488;
  const double _t494 = -_t493;
  const double _t495 = 0.3e1*_t155;
  const double _t496 = -_t176;
  const double _t497 = 0.3e1*_t172;
  const double _t498 = _t181*_t26;
  const double _t499 = 0.3e1*_t53;
  const double _t500 = 0.2e1*_t54;
  const double _t501 = _t500 + 0.2e1*_t56;
  const double _t502 = _t203*_t449;
  const double _t503 = 0.3e1*_t24;
  const double _t504 = 0.6e1*_hc3[2]*_t68 - _hc3[5]*_t503 + _hc3[9]*_t8 - _t193;
  const double _t505 = _t61*_t89;
  const double _t506 = _t505*_t62;
  const double _t507 = 0.2e1*_t460;
  const double _t508 = -_t180;
  const double _t509 = 0.2e1*_t455;
  const double _t510 = _t500 + 0.2e1*_t60;
  const double _t511 = _t510*_t61;
  const double _t512 = ((_hc3[2]) * (_hc3[2]));
  const double _t513 = 0.8e1*_hc3[0]*_hc3[2]*_t68 - _hc3[5]*_t168 - _t357 - _t429*_t512;
  const double _t514 = -_hc3[2]*_t426 + _t438;
  const double _t515 = -_hc0[19]*_t14 - _t149*_t508 + _t156*_t497 + _t167*_t513 + _t17*_t490 + _t176*_t492 + _t177*_t496 - _t178*_t491 - _t180*_t495 - _t180*_t507 + _t181*_t509 + _t27*_t504 - _t36*_t494 - _t379*_t511 + _t456*_t514 + _t467*_t499 - _t484*_t506 + _t486*_t9 + _t498*_t499 + _t501*_t502;
#endif
#if _KMAX >= 4
  const double _t516 = (0.15e2 / 0.8e1)/xc_powr(rs, 7, 2);
  const double _t517 = (0.1e1 / (rs * rs * rs));
  const double _t518 = (0.15e2 / 0.2e1)*_t517;
  const double _t519 = _hc3[0]*_t113;
  const double _t520 = 0.24e2*_t74;
  const double _t521 = _hc3[0]*_t520;
  const double _t522 = _t261*_t75;
  const double _t523 = _t197*_t201;
  const double _t524 = 0.24e2*_t4;
  const double _t525 = _t188*_t4;
  const double _t526 = _t197*_t525;
  const double _t527 = xc_powi(_t7, -9);
  const double _t528 = _t199*_t527;
  const double _t529 = (0.1e1 / (_t25 * _t25 * _t25 * _t25));
  const double _t530 = 0.48e2*_t529;
  const double _t531 = _t84*_t86;
  const double _t532 = 0.2e1*_t448;
  const double _t533 = 0.4e1*_t21;
  const double _t534 = _t20*_t263;
  const double _t535 = 0.4e1*_t93;
  const double _t536 = _t18*_t533 + _t2*_t534 - _t2*_t535 + 0.2e1*_t78;
  const double _t537 = _t22*_t87;
  const double _t538 = _t448*_t87;
  const double _t539 = (0.1e1 / (_t16 * _t16 * _t16 * _t16));
  const double _t540 = 0.3e1*_hc4[1]*_t2*_t20 - 0.3e1*_t19;
  const double _t541 = _t539*_t540;
  const double _t542 = _t204*_t541;
  const double _t543 = ((_hc4[4]) * (_hc4[4]));
  const double _t544 = 0.12e2*_t93;
  const double _t545 = _hc4[20]*_t20;
  const double _t546 = 0.4e1*_t205;
  const double _t547 = xc_powi((_hc4[0]), -5);
  const double _t548 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]) * (_hc4[1]));
  const double _t549 = 0.24e2*_t207;
  const double _t550 = _t209*_t549;
  const double _t551 = _t207*_t83;
  const double _t552 = _t2*_t551;
  const double _t553 = 0.36e2*_hc4[4];
  const double _t554 = _t213*_t92;
  const double _t555 = 0.3e1*_hc4[1]*_t12*_t20 - 0.3e1*_t32;
  const double _t556 = (0.1e1 / (_t34 * _t34 * _t34 * _t34));
  const double _t557 = _hc0[0]*_t556;
  const double _t558 = _t555*_t557;
  const double _t559 = 0.3e1*_t230;
  const double _t560 = _t217*_t33;
  const double _t561 = 0.2e1*_t216;
  const double _t562 = 0.4e1*_hc4[1]*_t20*_t31 + 0.2e1*_hc4[4]*_t12*_t20 - _t12*_t535 - 0.2e1*_t97;
  const double _t563 = _t215*_t562;
  const double _t564 = 0.3e1*_t231;
  const double _t565 = 0.3e1*_t103;
  const double _t566 = _hc4[1]*_t12;
  const double _t567 = 0.8e1*_t82;
  const double _t568 = 0.24e2*_t547;
  const double _t569 = _t12*_t551;
  const double _t570 = _hc4[1]*_t82;
  const double _t571 = _hc4[4]*_t570;
  const double _t572 = 0.6e1*_t79;
  const double _t573 = _hc4[4]*_t329;
  const double _t574 = _t187*_t29;
  const double _t575 = _t189*_t190;
  const double _t576 = _t329*_t83;
  const double _t577 = _t103*_t39;
  const double _t578 = _hc0[1]*_t214;
  const double _t579 = _hc0[1]*_t89;
  const double _t580 = _t213*_t91;
  const double _t581 = _t102*_t580;
  const double _t582 = _t563*_t91;
  const double _t583 = _t102*_t217;
  const double _t584 = _t124*_t39;
  const double _t585 = _t228*_t72;
  const double _t586 = 0.4e1*_t20;
  const double _t587 = _t240*_t292;
  const double _t588 = _t35*_t98;
  const double _t589 = _t214*_t580;
  const double _t590 = _t1*(_t222 + _t28*(-0.3e1*_t5 + 0.3e1*x0)) + _t12*_t223;
  const double _t591 = 0.6e1*_t20;
  const double _t592 = _t245*_t90;
  const double _t593 = _t39*_t90;
  const double _t594 = _t108*_t329*_t579;
  const double _t595 = _hc0[1]*_t238;
  const double _t596 = 0.6e1*_t1;
  const double _t597 = _t102*_t238;
  const double _t598 = _t557*_t590;
  const double _t599 = 0.4e1*_hc0[10];
  const double _t600 = _t108*_t591;
  const double _t601 = _t215*_t39;
  const double _t602 = _hc3[1]*_t192;
  const double _t603 = 0.12e2*_hc3[1];
  const double _t604 = _t260*_t261;
  const double _t605 = xc_powi((_hc3[0]), 6);
  const double _t606 = 0.8e1*_t42;
  const double _t607 = _t523*_t64;
  const double _t608 = _hc4[10]*_t44;
  const double _t609 = 0.12e2*_t571;
  const double _t610 = _t208*_t209;
  const double _t611 = _hc4[2]*_t610;
  const double _t612 = 0.18e2*_t207;
  const double _t613 = _hc4[1]*_hc4[4]*_t612;
  const double _t614 = _hc4[2]*_t568;
  const double _t615 = 0.18e2*_t551;
  const double _t616 = _hc0[2]*_t214;
  const double _t617 = _t51*_t580;
  const double _t618 = 0.2e1*_t217;
  const double _t619 = _hc4[1]*_hc4[2];
  const double _t620 = _t329*_t96;
  const double _t621 = _t1*_t65;
  const double _t622 = _t123*_t268;
  const double _t623 = _t39*_t93;
  const double _t624 = _t255*_t64;
  const double _t625 = _t39*_t79;
  const double _t626 = _hc4[2]*_t266;
  const double _t627 = _t118*_t90;
  const double _t628 = 0.2e1*_t278;
  const double _t629 = _t39*_t81;
  const double _t630 = _t214*_t281;
  const double _t631 = _t281*_t89;
  const double _t632 = _t266*_t36;
  const double _t633 = _t28*_t44;
  const double _t634 = _t105*_t35;
  const double _t635 = _t108*_t115;
  const double _t636 = _t129*_t234;
  const double _t637 = _hc0[4]*_t51;
  const double _t638 = _t129*_t51;
  const double _t639 = _t1*_t35;
  const double _t640 = 0.3e1*_hc1[5];
  const double _t641 = 0.3e1*_t107;
  const double _t642 = _hc4[2]*_t265;
  const double _t643 = _t126*_t214;
  const double _t644 = _t248*_t82;
  const double _t645 = 0.3e1*_t64;
  const double _t646 = _t519*_t645;
  const double _t647 = _t134*_t73;
  const double _t648 = _t521*_t67;
  const double _t649 = -0.12e2*_t128*_t207*_t83;
  const double _t650 = 0.12e2*_t18;
  const double _t651 = _t207*_t300;
  const double _t652 = -_t271;
  const double _t653 = 0.4e1*_hc0[2];
  const double _t654 = _t118*_t238;
  const double _t655 = 0.2e1*_t310;
  const double _t656 = _t216*_t50;
  const double _t657 = 0.2e1*_t656;
  const double _t658 = _t128*_t265;
  const double _t659 = 0.12e2*_t31;
  const double _t660 = _t321*_t558;
  const double _t661 = -_t273;
  const double _t662 = _t198*_t38;
  const double _t663 = 0.2e1*_t110;
  const double _t664 = _t28*_t663;
  const double _t665 = _t208*_t39;
  const double _t666 = _t138*_t90;
  const double _t667 = _t309*_t39;
  const double _t668 = _hc4[2]*_t115;
  const double _t669 = _t118*_t35;
  const double _t670 = _t238*_t51;
  const double _t671 = _hc0[1]*_t320;
  const double _t672 = _t50*_t630;
  const double _t673 = 0.4e1*_t122;
  const double _t674 = 0.2e1*_t107;
  const double _t675 = 0.4e1*_hc0[5];
  const double _t676 = 0.2e1*_hc1[2];
  const double _t677 = 0.2e1*_hc1[1];
  const double _t678 = _t108*_t82*_t89;
  const double _t679 = _hc4[2]*_t678;
  const double _t680 = _t128*_t208;
  const double _t681 = 0.2e1*_t136;
  const double _t682 = _t290*_t653;
  const double _t683 = _t105*_t320;
  const double _t684 = _t102*_t290;
  const double _t685 = _t292*_t50;
  const double _t686 = _t214*_t653;
  const double _t687 = _t557*_t600;
  const double _t688 = _t102*_t89;
  const double _t689 = _t105*_t688;
  const double _t690 = _t82*(-0.2e1*_hc4[0] + 0.2e1*_t11);
  const double _t691 = 0.4e1*_t1;
  const double _t692 = 0.4e1*_t102;
  const double _t693 = _hc3[6]*_t24;
  const double _t694 = _t111*_t26;
  const double _t695 = _t197*_t299;
  const double _t696 = _hc4[1]*_t328;
  const double _t697 = _t612*_t696;
  const double _t698 = _t208*_t328;
  const double _t699 = _t568*_t696;
  const double _t700 = _t44*_t80;
  const double _t701 = 0.2e1*_hc4[2]*_t18*_t20 - _t116*_t266 - _t700;
  const double _t702 = _t138*_t325;
  const double _t703 = _t118*_t320;
  const double _t704 = _t310*_t89;
  const double _t705 = _t351*_t90;
  const double _t706 = _t214*_t50;
  const double _t707 = _t213*_t706;
  const double _t708 = _t353*_t50;
  const double _t709 = _t265*_t566;
  const double _t710 = 0.2e1*_hc4[2]*_t20*_t31 - _hc4[2]*_t709 - _t700;
  const double _t711 = _t353*_t51;
  const double _t712 = _t337*_t339;
  const double _t713 = 0.3e1*_hc1[6];
  const double _t714 = _t26*_t312;
  const double _t715 = _t341*_t72;
  const double _t716 = 0.3e1*_t136;
  const double _t717 = _t138*_t35;
  const double _t718 = 0.3e1*_hc0[5];
  const double _t719 = _t313*_t320;
  const double _t720 = _t159*_t39;
  const double _t721 = _t320*_t51;
  const double _t722 = _t102*_t321;
  const double _t723 = _t215*_t50;
  const double _t724 = _t692*_t723;
  const double _t725 = 0.2e1*_t351;
  const double _t726 = _t321*_t352;
  const double _t727 = 0.3e1*_t102;
  const double _t728 = _t557*_t727;
  const double _t729 = 0.4e1*_hc0[13];
  const double _t730 = 0.6e1*_hc0[6];
  const double _t731 = ((_hc4[2]) * (_hc4[2]) * (_hc4[2]) * (_hc4[2]));
  const double _t732 = _t549*_t731;
  const double _t733 = _t568*_t731;
  const double _t734 = ((_hc3[1]) * (_hc3[1]) * (_hc3[1]) * (_hc3[1]));
  const double _t735 = 0.12e2*_t68;
  const double _t736 = _t128*_t586;
  const double _t737 = -_t132*_t265 - _t736;
  const double _t738 = 0.3e1*_t309;
  const double _t739 = _t286*_t50;
  const double _t740 = 0.3e1*_t138;
  const double _t741 = 0.3e1*_t43;
  const double _t742 = 0.3e1*_t45 + _t741;
  const double _t743 = -_t12*_t658 - _t736;
  const double _t744 = _t557*(0.3e1*_t49 + _t741);
  const double _t745 = _t26*_t499;
  const double _t746 = 0.8e1*_t53;
  const double _t747 = _t195*_t260;
  const double _t748 = _t388*_t747;
  const double _t749 = _hc3[2]*_t64;
  const double _t750 = _hc0[3]*_t214;
  const double _t751 = _hc0[3]*_t89;
  const double _t752 = _t171*_t238;
  const double _t753 = _t558*_t62;
  const double _t754 = _t379*_t562;
  const double _t755 = _hc4[25]*_t20;
  const double _t756 = 0.3e1*_t360;
  const double _t757 = _hc4[10]*_t55;
  const double _t758 = _hc4[3]*_t18;
  const double _t759 = 0.18e2*_hc4[7];
  const double _t760 = _hc4[14]*_t329;
  const double _t761 = _hc4[7]*_t573;
  const double _t762 = _hc4[7]*_t570;
  const double _t763 = -_hc4[25]*_t1 + _hc4[3]*_t610 - _hc4[7]*_t576 + _t222*_t360;
  const double _t764 = _hc4[3]*_t31;
  const double _t765 = _hc4[1]*_hc4[3];
  const double _t766 = _t155*_t81;
  const double _t767 = _t28*_t55;
  const double _t768 = _hc4[3]*_t39;
  const double _t769 = _t266*_t768;
  const double _t770 = _t152*_t90;
  const double _t771 = _hc0[7]*_t35;
  const double _t772 = _t39*_t771;
  const double _t773 = _t208*_t233;
  const double _t774 = _t265*_t90;
  const double _t775 = _t105*_t377;
  const double _t776 = _t108*_t379;
  const double _t777 = _t379*_t586;
  const double _t778 = _t108*_t129;
  const double _t779 = 0.3e1*_hc1[7];
  const double _t780 = _t171*_t214;
  const double _t781 = _t214*_t410;
  const double _t782 = _t53*_t72;
  const double _t783 = 0.12e2*_t67;
  const double _t784 = _t530*_t59;
  const double _t785 = _t142*_t197;
  const double _t786 = 0.16e2*_hc3[1]*_t386;
  const double _t787 = _t207*_t393;
  const double _t788 = 0.12e2*_hc4[7];
  const double _t789 = _t207*_t788;
  const double _t790 = _hc4[4]*_t164;
  const double _t791 = _hc4[7]*_t567;
  const double _t792 = 0.12e2*_t551;
  const double _t793 = _hc4[14]*_t159 + _t164*_t792 - _t619*_t791;
  const double _t794 = _t616*_t62;
  const double _t795 = _t213*_t50;
  const double _t796 = _t164*_t265;
  const double _t797 = _t568*_t83;
  const double _t798 = _t12*_t797;
  const double _t799 = _t115*_t768;
  const double _t800 = _t169*_t38;
  const double _t801 = _hc0[7]*_t51;
  const double _t802 = _hc4[3]*_t678;
  const double _t803 = _t126*_t62;
  const double _t804 = _t1*_t89;
  const double _t805 = _hc4[3]*_t265;
  const double _t806 = _hc0[4]*_t62;
  const double _t807 = _hc3[3]*_t69;
  const double _t808 = _t163*_t197;
  const double _t809 = 0.8e1*_t388;
  const double _t810 = _hc3[1]*_t28;
  const double _t811 = _t388*_t76*_t810;
  const double _t812 = _t390*_t427;
  const double _t813 = -0.18e2*_hc4[1]*_hc4[3]*_t128*_t207 + _hc4[7]*_t413;
  const double _t814 = _t62*_t795;
  const double _t815 = _t152*_t320;
  const double _t816 = _t352*_t50;
  const double _t817 = _t165*_t35;
  const double _t818 = 0.2e1*_t163*_t26;
  const double _t819 = _t803*_t89;
  const double _t820 = _t165*_t688;
  const double _t821 = _t149*_t39;
  const double _t822 = _t166*_t427;
  const double _t823 = _t102*_t62;
  const double _t824 = _t102*_t379;
  const double _t825 = _t352*_t706;
  const double _t826 = _t62*_t816;
  const double _t827 = _hc4[3]*_t328;
  const double _t828 = _t549*_t827;
  const double _t829 = _t568*_t827;
  const double _t830 = 0.3e1*_hc1[8];
  const double _t831 = 0.3e1*_hc0[8];
  const double _t832 = 0.6e1*_t29;
  const double _t833 = _hc3[1]*_t832;
  const double _t834 = _hc3[3]*_t832;
  const double _t835 = 0.6e1*_t134*_t24;
  const double _t836 = _t29*_t603;
  const double _t837 = _t171*_t320;
  const double _t838 = _t351*_t377;
  const double _t839 = 0.3e1*_t165;
  const double _t840 = _t172*_t26;
  const double _t841 = _t182*_t64;
  const double _t842 = 0.12e2*_t254;
  const double _t843 = _t67*_t842;
  const double _t844 = _t23*_t28*_t68;
  const double _t845 = _t67*_t747;
  const double _t846 = _t447*_t73;
  const double _t847 = _t4*_t454;
  const double _t848 = 0.2e1*_t847;
  const double _t849 = _t529*_t59;
  const double _t850 = _t184*_t849;
  const double _t851 = _t184*_t844;
  const double _t852 = 0.2e1*_t147;
  const double _t853 = _t448*_t58;
  const double _t854 = _t148*_t57;
  const double _t855 = _t148*_t86;
  const double _t856 = _hc3[2]*_t113;
  const double _t857 = _t783*_t856;
  const double _t858 = _t23*_t520;
  const double _t859 = _t171*_t62;
  const double _t860 = 0.4e1*_hc0[3];
  const double _t861 = _t171*_t377;
  const double _t862 = ((_hc4[7]) * (_hc4[7]));
  const double _t863 = _t265*_t862;
  const double _t864 = _t207*_t440;
  const double _t865 = _hc4[4]*_t173;
  const double _t866 = _hc4[14]*_t265;
  const double _t867 = _t173*_t2;
  const double _t868 = _hc4[7]*_t549;
  const double _t869 = _hc4[14]*_t444 - 0.16e2*_hc4[3]*_t762 + _t173*_t792 + _t586*_t862;
  const double _t870 = _t213*_t61;
  const double _t871 = 0.2e1*_t151;
  const double _t872 = _t152*_t61;
  const double _t873 = 0.2e1*_hc1[3];
  const double _t874 = 0.4e1*_hc0[7];
  const double _t875 = _t173*_t208;
  const double _t876 = 0.2e1*_t178;
  const double _t877 = _t62*_t860;
  const double _t878 = _t405*_t505;
  const double _t879 = _t62*_t750;
  const double _t880 = _hc4[3]*_t116;
  const double _t881 = _t164*_t788;
  const double _t882 = -0.18e2*_hc4[1]*_hc4[2]*_t173*_t207 + _t82*_t881;
  const double _t883 = _t181*_t197;
  const double _t884 = _hc0[9]*_t51;
  const double _t885 = _t388*_t427;
  const double _t886 = _t519*_t603;
  const double _t887 = _t28*_t437;
  const double _t888 = _t165*_t61;
  const double _t889 = _t352*_t61;
  const double _t890 = _t173*_t82;
  const double _t891 = _t180*_t35;
  const double _t892 = _t405*_t61;
  const double _t893 = _t39*_t460;
  const double _t894 = _t405*_t90;
  const double _t895 = _t183*_t38;
  const double _t896 = 0.2e1*_t480;
  const double _t897 = _t62*_t889;
  const double _t898 = _t128*_t173;
  const double _t899 = _t549*_t898;
  const double _t900 = 0.4e1*_hc0[8];
  const double _t901 = _t12*_t568;
  const double _t902 = _t29*_t387;
  const double _t903 = _hc3[3]*_t426;
  const double _t904 = 0.4e1*_t24;
  const double _t905 = _t134*_t904;
  const double _t906 = _t165*_t505;
  const double _t907 = _t180*_t320;
  const double _t908 = 0.2e1*_t353;
  const double _t909 = 0.4e1*_hc3[4];
  const double _t910 = _t23*_t336;
  const double _t911 = _t28*_t910;
  const double _t912 = _t208*_t487;
  const double _t913 = _hc4[7]*_t612;
  const double _t914 = -0.18e2*_hc4[1]*_t207*_t487 + _t759*_t890;
  const double _t915 = _t176*_t57;
  const double _t916 = _t450*_t53;
  const double _t917 = _t176*_t86;
  const double _t918 = _t449*_t501;
  const double _t919 = _t504*_t73;
  const double _t920 = _t180*_t484;
  const double _t921 = _t203*_t501;
  const double _t922 = 0.2e1*_t145 - _t55*_t80;
  const double _t923 = _t183*_t53;
  const double _t924 = _t388*_t923;
  const double _t925 = _t388*_t514;
  const double _t926 = _t184*_t514;
  const double _t927 = _t214*_t484;
  const double _t928 = 0.24e2*_t856;
  const double _t929 = _t180*_t61;
  const double _t930 = _t849*_t926;
  const double _t931 = _t377*_t484;
  const double _t932 = _t379*_t510;
  const double _t933 = _t215*_t510;
  const double _t934 = 0.3e1*_hc1[9];
  const double _t935 = 0.3e1*_t178;
  const double _t936 = 0.3e1*_t180;
  const double _t937 = 0.2e1*_t405;
  const double _t938 = _t180*_t505;
  const double _t939 = _t215*_t511;
  const double _t940 = 0.2e1*_t508;
  const double _t941 = _t511*_t62;
  const double _t942 = _t557*_t941;
  const double _t943 = _hc4[2]*_t487;
  const double _t944 = _t549*_t943;
  const double _t945 = 0.6e1*_t172;
  const double _t946 = 0.4e1*_hc4[3]*_t44;
  const double _t947 = 0.4e1*_hc0[19];
  const double _t948 = 0.6e1*_hc0[9];
  const double _t949 = ((_hc4[3]) * (_hc4[3]) * (_hc4[3]) * (_hc4[3]));
  const double _t950 = _t549*_t949;
  const double _t951 = _t568*_t949;
  const double _t952 = _t173*_t586;
  const double _t953 = _hc3[5]*_t735;
  const double _t954 = 0.3e1*_t54;
#endif

  const double f = A*_t15;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = A*_t37;
  out[1] = df_drs;
  const double df_dx0 = A*_t41;
  out[2] = df_dx0;
  const double df_dc = A*_t52;
  out[3] = df_dc;
  const double df_db = A*_t63;
  out[4] = df_db;
  const double df_dA = _t15;
  out[5] = df_dA;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = A*_t99;
  out[6] = d2f_drs2;
  const double d2f_dx0_drs = A*_t104;
  out[7] = d2f_dx0_drs;
  const double d2f_dx02 = A*_t109;
  out[8] = d2f_dx02;
  const double d2f_dc_drs = A*_t120;
  out[9] = d2f_dc_drs;
  const double d2f_dc_dx0 = A*_t125;
  out[10] = d2f_dc_dx0;
  const double d2f_dc2 = A*_t139;
  out[11] = d2f_dc2;
  const double d2f_db_drs = A*_t153;
  out[12] = d2f_db_drs;
  const double d2f_db_dx0 = A*_t157;
  out[13] = d2f_db_dx0;
  const double d2f_db_dc = A*_t170;
  out[14] = d2f_db_dc;
  const double d2f_db2 = A*_t185;
  out[15] = d2f_db2;
  const double d2f_dA_drs = _t37;
  out[16] = d2f_dA_drs;
  const double d2f_dA_dx0 = _t41;
  out[17] = d2f_dA_dx0;
  const double d2f_dA_dc = _t52;
  out[18] = d2f_dA_dc;
  const double d2f_dA_db = _t63;
  out[19] = d2f_dA_db;
  const double d2f_dA2 = 0;
  out[20] = d2f_dA2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = A*_t226;
  out[21] = d3f_drs3;
  const double d3f_dx0_drs2 = A*_t232;
  out[22] = d3f_dx0_drs2;
  const double d3f_dx02_drs = A*_t241;
  out[23] = d3f_dx02_drs;
  const double d3f_dx03 = A*_t252;
  out[24] = d3f_dx03;
  const double d3f_dc_drs2 = A*_t274;
  out[25] = d3f_dc_drs2;
  const double d3f_dc_dx0_drs = A*_t282;
  out[26] = d3f_dc_dx0_drs;
  const double d3f_dc_dx02 = A*_t294;
  out[27] = d3f_dc_dx02;
  const double d3f_dc2_drs = A*_t311;
  out[28] = d3f_dc2_drs;
  const double d3f_dc2_dx0 = A*_t324;
  out[29] = d3f_dc2_dx0;
  const double d3f_dc3 = A*_t354;
  out[30] = d3f_dc3;
  const double d3f_db_drs2 = A*_t369;
  out[31] = d3f_db_drs2;
  const double d3f_db_dx0_drs = A*_t372;
  out[32] = d3f_db_dx0_drs;
  const double d3f_db_dx02 = A*_t381;
  out[33] = d3f_db_dx02;
  const double d3f_db_dc_drs = A*_t400;
  out[34] = d3f_db_dc_drs;
  const double d3f_db_dc_dx0 = A*_t412;
  out[35] = d3f_db_dc_dx0;
  const double d3f_db_dc2 = A*_t434;
  out[36] = d3f_db_dc2;
  const double d3f_db2_drs = A*_t461;
  out[37] = d3f_db2_drs;
  const double d3f_db2_dx0 = A*_t469;
  out[38] = d3f_db2_dx0;
  const double d3f_db2_dc = A*_t483;
  out[39] = d3f_db2_dc;
  const double d3f_db3 = A*_t515;
  out[40] = d3f_db3;
  const double d3f_dA_drs2 = _t99;
  out[41] = d3f_dA_drs2;
  const double d3f_dA_dx0_drs = _t104;
  out[42] = d3f_dA_dx0_drs;
  const double d3f_dA_dx02 = _t109;
  out[43] = d3f_dA_dx02;
  const double d3f_dA_dc_drs = _t120;
  out[44] = d3f_dA_dc_drs;
  const double d3f_dA_dc_dx0 = _t125;
  out[45] = d3f_dA_dc_dx0;
  const double d3f_dA_dc2 = _t139;
  out[46] = d3f_dA_dc2;
  const double d3f_dA_db_drs = _t153;
  out[47] = d3f_dA_db_drs;
  const double d3f_dA_db_dx0 = _t157;
  out[48] = d3f_dA_db_dx0;
  const double d3f_dA_db_dc = _t170;
  out[49] = d3f_dA_db_dc;
  const double d3f_dA_db2 = _t185;
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
#if _KMAX >= 4
  const double d4f_drs4 = A*(-xc_powi((_hc3[0]), 7)*_t525*_t530/xc_powi(_t7, 11) + _t17*(0.8e1*_hc4[1]*_hc4[10]*_t2*_t82 + 0.4e1*_hc4[1]*_hc4[10]*_t20 + 0.24e2*_hc4[1]*_hc4[4]*_t18*_t82 - _hc4[20]*_t1 - _hc4[4]*_t544 - _t18*_t546 - _t18*_t550 + 0.6e1*_t2*_t543*_t82 - _t2*_t545 + 0.24e2*_t2*_t547*_t548 + 0.6e1*_t20*_t543 - _t552*_t553) + 0.18e2*_t186*_t27*_t519 - 0.42e2*_t186*_t298*_t73 + _t186*_t523*_t524 + _t188*_t27*_t521 - 0.96e2*_t188*_t522*_t73 + _t191*_t518 + _t203*_t536*_t537 + _t211*_t22*_t86 + 0.3e1*_t212*_t88 - _t218*_t224 + _t22*_t532*_t84 - _t225*_t565 - _t36*(_hc4[10]*_t566*_t567 + _t1*(-_hc4[20] - _t10*_t516 + (0.15e2 / 0.8e1)*_t517) + _t12*_t329*_t543 - _t12*_t545 + _t12*_t548*_t568 - _t221*_t533 - _t31*_t546 - _t31*_t550 + 0.24e2*_t31*_t571 + _t544*_t96 - _t553*_t569 - _t572*_t96) + _t516*_t66 - _t518*_t73*_t76 + 0.120e3*_t526*_t528 + 0.3e1*_t531*_t85 + _t537*_t542 + 0.3e1*_t538*_t85 - _t554*_t558 - _t559*_t98 - _t560*_t561 - _t563*_t92 - _t564*_t98);
  out[56] = d4f_drs4;
  const double d4f_dx0_drs3 = A*(0.3e1*_hc0[0]*_hc4[1]*_t20*_t213*_t214*_t39*_t91 + 0.3e1*_hc0[0]*_hc4[1]*_t20*_t217*_t39*_t89 + (0.3e1 / 0.2e1)*_hc0[0]*_hc4[1]*_t20*_t35*_t64 + _hc0[0]*_hc4[10]*_t20*_t35*_t39 + 0.3e1*_hc0[0]*_hc4[4]*_t20*_t39*_t89*_t91 + (0.3e1 / 0.4e1)*_hc0[0]*_t1*_t186*_t35 + 0.3e1*_hc0[0]*_t1*_t213*_t214*_t28*_t91 + 0.3e1*_hc0[0]*_t1*_t217*_t28*_t89 + 0.6e1*_hc0[0]*_t207*_t209*_t35*_t39 + 0.6e1*_hc0[0]*_t28*_t35*_t82*_t83 - _hc4[1]*_t123*_t573 - 0.3e1 / 0.2e1*_t1*_t103*_t64 - _t100*_t194 - _t100*_t574 - _t100*_t575 - _t102*_t582 - 0.6e1*_t103*_t21*_t28 - _t124*_t225 + 0.3e1*_t188*_t38*_t72*_t74*_t75 + 0.14e2*_t195*_t38*_t64*_t72*_t75 - _t202*_t38*_t64 - _t206*_t275 - _t224*_t319 - _t239*_t98 - _t554*_t578 - _t558*_t581 - _t560*_t579 - _t561*_t583 - _t576*_t577);
  out[57] = d4f_dx0_drs3;
  const double d4f_dx02_drs2 = A*(0.4e1*_hc0[0]*_hc4[1]*_t20*_t89*_t91 + 0.8e1*_hc0[0]*_hc4[1]*_t28*_t39*_t82*_t89 + 0.2e1*_hc0[0]*_hc4[4]*_t20*_t35 + _hc0[0]*_t108*_t20*_t214*(_t1*(_t263 - _t67 + _t95) + _t12*_t534 + _t31*_t533 + _t93*(0.4e1*_hc4[0] - 0.4e1*_t11)) + _hc0[0]*_t108*_t20*_t240*_t556*_t590 + 0.6e1*_hc0[0]*_t108*_t207*_t83*_t89 + _hc0[0]*_t20*_t39*_t64*_t89 + 0.2e1*_hc0[0]*_t20*_t67*_t89 + 0.4e1*_hc0[1]*_hc4[1]*_t20*_t39*_t89*_t91 + 0.2e1*_hc0[1]*_hc4[4]*_t20*_t35*_t39 + 0.4e1*_hc0[1]*_t1*_t28*_t89*_t91 - _hc0[4]*_t229 - _hc0[4]*_t588 + (0.1e1 / 0.2e1)*_hc3[0]*_t106*_t24*_t26*_t64 + 0.2e1*_hc3[0]*_t106*_t26*_t67*_t68 - _t102*_t105*_t589 - _t105*_t583*_t89 - _t106*_t585 - _t124*_t28*_t533 - _t216*_t234*_t586 - _t230*_t237 - _t231*_t237 - _t233*_t268 - _t244*_t64 - _t266*_t587 - _t36*_t535 - _t535*_t584);
  out[58] = d4f_dx02_drs2;
  const double d4f_dx03_drs = A*(0.6e1*_hc0[0]*_hc4[1]*_t207*_t214*_t248 + 0.6e1*_hc0[0]*_t108*_t214*_t28*_t82 + _hc0[0]*_t20*_t213*_t214*_t245 + 0.2e1*_hc0[0]*_t20*_t213*_t214*_t39 + 0.6e1*_hc0[1]*_hc4[1]*_t20*_t35 + 0.3e1*_hc0[1]*_t108*_t20*_t214*_t240 - _hc0[10]*_t101 + 0.3e1*_hc0[4]*_hc4[1]*_t20*_t35*_t39 + 0.3e1*_hc0[4]*_t1*_t28*_t35 - 0.3e1*_hc0[4]*_t597 - _hc4[1]*_t594 - _t115*_t592 - _t234*_t579*_t591 - _t243*_t277 - _t249*_t598 - _t266*_t593 - _t28*_t591*_t90 - _t595*_t596);
  out[59] = d4f_dx03_drs;
  const double d4f_dx04 = A*(-_hc0[20]*_t14 + _hc0[4]*_t600*_t89 - 0.12e2*_t1*_t247 - _t107*_t599 - _t131*_t245*_t601 + 0.8e1*_t20*_t39*_t579 + _t208*(_t39 * _t39 * _t39 * _t39)*_t557 + _t245*_t579*_t586 + 0.12e2*_t246 - _t248*_t567*_t578 - 0.16e2*_t292*_t82 + _t9*(-_hc0[20]*_hc1[0] - _hc1[1]*_t599));
  out[60] = d4f_dx04;
  const double d4f_dc_drs3 = A*((0.3e1 / 0.2e1)*_hc3[1]*_t113*_t186*_t23*_t4*_t72 + 0.15e2*_hc3[1]*_t188*_t23*_t4*_t72*_t74 - _hc3[1]*_t189*_t27*_t68 + 0.54e2*_hc3[1]*_t195*_t23*_t4*_t64*_t72 - 0.96e2*_hc3[1]*_t196*_t197*_t200*_t260 + 0.48e2*_hc3[1]*_t4*_t529*_t605*_t64/xc_powi(_t7, 10) - _t110*_t187*_t27 - _t112*_t193*_t64 - _t112*_t574 - _t112*_t575 + 0.3e1*_t117*_t203*_t204*_t87 + 0.3e1*_t117*_t84*_t86 - _t118*_t559 - _t118*_t564 - _t119*_t224 - _t122*_t225 + _t17*(_hc4[10]*_t392 - _hc4[2]*_t609 - _t116*_t613 + _t210*_t614 + _t267*_t573 - _t267*_t615 + 0.2e1*_t608 + _t611) + 0.3e1*_t188*_t42*_t72*_t74*_t75 + 0.14e2*_t195*_t42*_t64*_t72*_t75 + 0.2e1*_t203*_t204*_t47*_t84 + _t203*_t47*_t536*_t87 + _t204*_t47*_t539*_t540*_t87 + _t211*_t47*_t86 - _t27*_t602*_t64 + 0.3e1*_t271*_t86*_t87 - _t272*_t618 - _t273*_t565 - _t286*_t560 - _t308*_t98 - _t36*(_hc4[10]*_t398 - _hc4[2]*_t12*_t613 + _t12*_t209*_t614 - _t221*_t44 + _t397*_t573 - _t397*_t615 - _t573*_t619 + _t608 + _t611 + _t619*_t620) - _t51*_t582 - _t526*_t603*_t604 - _t554*_t616 - _t558*_t617 - _t606*_t607);
  out[61] = d4f_dc_drs3;
  const double d4f_dc_dx0_drs2 = A*(0.4e1*_hc0[0]*_hc4[1]*_hc4[2]*_t28*_t35*_t82 + 0.2e1*_hc0[0]*_hc4[1]*_t20*_t28*_t51*_t89 + _hc0[0]*_hc4[2]*_t20*_t213*_t214*_t39*_t91 + _hc0[0]*_hc4[2]*_t20*_t217*_t39*_t89 + (0.1e1 / 0.2e1)*_hc0[0]*_hc4[2]*_t20*_t35*_t64 + 0.6e1*_hc0[0]*_hc4[2]*_t207*_t35*_t39*_t83 + 0.2e1*_hc0[0]*_t1*_t118*_t213*_t214*_t39 + _hc0[0]*_t1*_t213*_t39*_t51*_t555*_t556 + _hc0[0]*_t1*_t214*_t39*_t51*_t562 + _hc0[0]*_t1*_t273*_t39*_t89 + (0.1e1 / 0.2e1)*_hc0[0]*_t1*_t51*_t64*_t89 + 0.2e1*_hc0[0]*_t39*_t51*_t82*_t83*_t89 + 0.2e1*_hc0[2]*_hc4[1]*_t20*_t39*_t89*_t91 + _hc0[2]*_hc4[4]*_t20*_t35*_t39 + 0.2e1*_hc0[2]*_t1*_t28*_t89*_t91 - _hc0[5]*_t229 - _hc0[5]*_t588 + (0.1e1 / 0.2e1)*_hc3[0]*_t121*_t24*_t26*_t64 + 0.2e1*_hc3[0]*_t121*_t26*_t67*_t68 + 0.8e1*_hc3[1]*_t197*_t260*_t261*_t38*_t67 + (0.1e1 / 0.2e1)*_hc3[1]*_t24*_t26*_t38*_t64 + 0.2e1*_hc3[1]*_t26*_t38*_t67*_t68 - _hc4[2]*_t622 - _t103*_t159*_t28 - _t118*_t239 - _t119*_t625 - _t121*_t585 - _t122*_t28*_t81 - _t122*_t621 - _t124*_t273 - _t217*_t631 - _t227*_t259 - _t227*_t624 - _t272*_t628 - _t272*_t629 - _t283*_t623 - _t286*_t583 - _t577*_t626 - _t580*_t630 - _t581*_t616 - _t627*_t628 - _t627*_t629);
  out[62] = d4f_dc_dx0_drs2;
  const double d4f_dc_dx02_drs = A*(0.6e1*_hc0[0]*_hc4[1]*_hc4[2]*_t108*_t207*_t89 + 0.4e1*_hc0[0]*_hc4[1]*_t108*_t214*_t51*_t82 + 0.2e1*_hc0[0]*_hc4[2]*_t20*_t89*_t91 + 0.4e1*_hc0[0]*_hc4[2]*_t28*_t39*_t82*_t89 + 0.2e1*_hc0[0]*_t1*_t118*_t89 + 0.2e1*_hc0[0]*_t1*_t213*_t214*_t51 + 0.4e1*_hc0[0]*_t20*_t214*_t28*_t39*_t51 + 0.2e1*_hc0[1]*_hc4[2]*_t20*_t39*_t89*_t91 + 0.2e1*_hc0[1]*_t1*_t118*_t39*_t89 + 0.2e1*_hc0[1]*_t1*_t213*_t214*_t39*_t51 - _hc0[11]*_t101 + 0.2e1*_hc0[2]*_hc4[1]*_t20*_t35 + _hc0[2]*_t108*_t20*_t214*_t240 + 0.2e1*_hc0[5]*_hc4[1]*_t20*_t35*_t39 + 0.2e1*_hc0[5]*_t1*_t28*_t35 + 0.2e1*_hc3[1]*_t106*_t113*_t23*_t28*_t72 - _hc4[2]*_t632 - _t1*_t308 - _t108*_t598*_t638 - _t111*_t236 - _t118*_t247 - _t118*_t293 - _t119*_t81 - _t238*_t637 - _t277*_t285 - _t278*_t291 - _t284*_t597 - _t286*_t635 - _t286*_t636 - _t289*_t587 - _t584*_t626 - _t629*_t631 - _t633*_t634);
  out[63] = d4f_dc_dx02_drs;
  const double d4f_dc_dx03 = A*(0.6e1*_hc0[0]*_hc4[2]*_t207*_t214*_t248 + 0.6e1*_hc0[0]*_t248*_t51*_t556*_t82 + 0.6e1*_hc0[1]*_hc4[2]*_t20*_t35 + 0.6e1*_hc0[1]*_t1*_t51*_t89 - _hc0[10]*_t136 - _hc0[11]*_t641 + _hc0[2]*_t20*_t245*_t89 + 0.2e1*_hc0[2]*_t20*_t39*_t89 - _hc0[21]*_t14 + 0.3e1*_hc0[4]*_hc4[2]*_t20*_t35*_t39 + 0.3e1*_hc0[4]*_t1*_t39*_t51*_t89 + 0.3e1*_hc0[5]*_t108*_t20*_t89 - 0.6e1*_hc0[5]*_t639 + _hc3[1]*_t243*_t26*_t8 - _hc4[2]*_t594 - _t215*_t245*_t638 - _t289*_t592 - _t51*_t586*_t601 - _t593*_t642 - _t600*_t630 - _t643*_t644 + _t9*(-_hc0[10]*_hc1[2] - _hc0[11]*_t242 - _hc0[21]*_hc1[0] - _hc0[4]*_t640));
  out[64] = d4f_dc_dx03;
  const double d4f_dc2_drs2 = A*(-_hc0[6]*_t229 - _hc0[6]*_t588 + (0.1e1 / 0.2e1)*_hc3[0]*_t127*_t24*_t26*_t64 + 0.2e1*_hc3[0]*_t127*_t26*_t67*_t68 + 0.16e2*_hc3[1]*_t197*_t260*_t261*_t42*_t67 + _hc3[1]*_t24*_t26*_t42*_t64 + 0.4e1*_hc3[1]*_t26*_t42*_t67*_t68 + 0.8e1*_hc3[3]*_t197*_t260*_t261*_t4*_t67 + (0.1e1 / 0.2e1)*_hc3[3]*_t24*_t26*_t4*_t64 - _hc3[3]*_t253*_t254 - 0.10e2*_hc3[3]*_t256*_t67*_t73 + 0.2e1*_hc3[3]*_t26*_t4*_t67*_t68 + 0.2e1*_t117*_t203*_t204*_t46 + 0.2e1*_t117*_t305*_t86 - _t118*_t657 - _t119*_t661 - _t127*_t585 + _t133*_t203*_t204*_t87 + _t133*_t84*_t86 + 0.4e1*_t134*_t195*_t197*_t4*_t64*_t75 + 0.72e2*_t134*_t197*_t261*_t4*_t67*_t75 - _t134*_t4*_t528*_t530*_t67 - _t138*_t230 - _t138*_t231 + _t17*(-_hc4[4]*_t302 - _hc4[4]*_t413 + 0.24e2*_t128*_t2*_t547*_t83 - _t649 - _t650*_t651) + 0.2e1*_t203*_t204*_t305*_t47 + _t203*_t46*_t47*_t536 + _t204*_t46*_t47*_t539*_t540 - _t213*_t660 - _t217*_t318 - _t219*_t307 - 0.20e2*_t258*_t262 - 0.2e1*_t262*_t624 + _t271*_t46*_t86 - _t272*_t655 - _t273*_t283 - _t273*_t309 + 0.2e1*_t304*_t86*_t87 - _t321*_t563 - _t36*(-_hc4[4]*_t421 - _hc4[4]*_t658 + 0.24e2*_t12*_t128*_t547*_t83 + 0.2e1*_t128*_t82*_t96 - _t649 - _t651*_t659) + _t47*_t652*_t86 - _t617*_t643 - _t627*_t655 - _t646*_t647 - _t647*_t648 - _t653*_t654);
  out[65] = d4f_dc2_drs2;
  const double d4f_dc2_dx0_drs = A*(0.2e1*_hc0[0]*_hc4[1]*_hc4[2]*_t39*_t51*_t82*_t89 + _hc0[0]*_hc4[2]*_t20*_t213*_t214*_t39*_t50 + _hc0[0]*_hc4[2]*_t20*_t28*_t51*_t89 + _hc0[0]*_hc4[2]*_t20*_t310*_t39*_t89 + 0.2e1*_hc0[0]*_t1*_t118*_t214*_t39*_t50 + _hc0[0]*_t1*_t138*_t213*_t214*_t39 + 0.2e1*_hc0[0]*_t1*_t214*_t310*_t39*_t51 + _hc0[0]*_t1*_t307*_t39*_t89 + 0.2e1*_hc0[0]*_t1*_t39*_t50*_t51*_t555*_t556 - _hc0[12]*_t101 + 0.2e1*_hc0[2]*_hc4[2]*_t20*_t39*_t89*_t91 + 0.2e1*_hc0[2]*_t1*_t118*_t39*_t89 + 0.2e1*_hc0[2]*_t1*_t213*_t214*_t39*_t51 + _hc0[6]*_hc4[1]*_t20*_t35*_t39 + _hc0[6]*_t1*_t28*_t35 - _hc0[6]*_t597 + 0.6e1*_hc3[0]*_t113*_t134*_t28*_t38*_t72 + 0.4e1*_hc3[1]*_t113*_t121*_t23*_t28*_t72 + 0.2e1*_hc3[3]*_t113*_t23*_t28*_t38*_t72 - _t100*_t296 - _t118*_t671 - _t121*_t26*_t664 - _t124*_t307 - _t138*_t595 - _t213*_t672 - _t272*_t313 - _t277*_t314 - _t278*_t318 - _t278*_t666 - _t279*_t666 - _t283*_t633 - _t284*_t669 - _t284*_t670 - _t286*_t51*_t629 - _t299*_t662 - _t309*_t633 - _t310*_t631 - _t313*_t627 - _t315*_t577 - _t322*_t628 - _t322*_t629 - _t36*(-_t28*_t315 - _t300*_t665) - _t401*_t626 - _t667*_t668);
  out[66] = d4f_dc2_dx0_drs;
  const double d4f_dc2_dx02 = A*(-_hc0[11]*_t681 - _hc0[12]*_t674 - _hc0[22]*_t14 + _hc0[6]*_t251 - 0.2e1*_hc0[6]*_t639 + _t1*_t682 - _t106*_t419 - _t119*_t159 - _t138*_t247 + _t138*_t689 + _t159*_t309 + _t233*_t680 + _t236*_t312 + _t237*_t666 - _t250*_t51*_t686 + _t285*_t317 + _t288*_t675 - _t291*_t313 + _t292*_t51*_t642 - _t293*(_t128*_t690 + _t130) + _t313*_t683 - _t320*_t637 + _t322*_t691 - _t36*_t658 + _t44*_t673 + (_t51 * _t51)*_t687 - _t584*_t658 - _t642*_t685 - _t653*_t679 + _t672*_t692 + _t675*_t684 + _t9*(-_hc0[11]*_t676 - _hc0[12]*_t677 - _hc0[22]*_hc1[0] - _hc0[4]*_hc1[6] - _hc1[12]*_t105 - _hc1[5]*_t675));
  out[67] = d4f_dc2_dx02;
  const double d4f_dc3_drs = A*(-_hc0[13]*_t101 + 0.18e2*_hc3[0]*_hc3[1]*_hc3[3]*_t113*_t28*_t4*_t72 + 0.18e2*_hc3[0]*_t113*_t134*_t28*_t42*_t72 + 0.6e1*_hc3[1]*_t113*_t127*_t23*_t28*_t72 + 0.6e1*_hc3[3]*_t113*_t23*_t28*_t42*_t72 + 0.2e1*_hc3[6]*_t113*_t23*_t28*_t4*_t72 - _t103*_t344 - 0.3e1*_t112*_t296 + 0.6e1*_t113*_t28*_t333*_t4*_t72 + _t117*_t203*_t348*_t46 + _t117*_t346*_t86 - _t118*_t705 - _t118*_t708 - _t119*_t306 - 0.3e1*_t127*_t694 + 0.2e1*_t133*_t203*_t204*_t46 + 0.2e1*_t133*_t305*_t86 - _t138*_t657 + _t17*(-_t18*_t698 + _t2*_t699 + _t697) - 0.48e2*_t195*_t197*_t23*_t333*_t385 - _t197*_t28*_t298*_t339*_t524 + 0.48e2*_t200*_t260*_t28*_t333*_t4*_t529 + _t203*_t204*_t346*_t47 + _t203*_t305*_t348*_t47 + _t203*_t46*_t47*_t701 - _t238*_t702 - _t27*_t28*_t693 - _t272*_t351 - _t277*_t327 + _t303*_t47*_t86 + 0.2e1*_t304*_t46*_t86 - _t307*_t345 - _t307*_t350 - _t310*_t711 - _t322*_t710 - _t325*_t703 + _t332*_t86*_t87 - _t342*_t669 - _t342*_t670 + _t348*_t46*_t47*_t539*_t540 - _t349*_t704 - _t349*_t707 - _t352*_t660 - _t36*(_t12*_t699 - _t31*_t698 + _t697) - 0.24e2*_t42*_t695 - _t655*_t666);
  out[68] = d4f_dc3_drs;
  const double d4f_dc3_dx0 = A*(-_hc0[12]*_t716 - _hc0[13]*_t107 - _hc0[23]*_t14 + _hc3[6]*_t100*_t8 + _t102*_t215*_t51*_t725 + _t119*_t315*_t39 + 0.3e1*_t121*_t714 - _t121*_t715 + _t123*_t698 - _t124*_t344 - _t138*_t683 + _t138*_t724 - _t227*_t712 + _t256*_t333*_t662 + _t288*_t342 - _t313*_t349*_t89 + _t313*_t705 + _t313*_t708 - _t313*_t711 + 0.3e1*_t314*_t316 + _t319*_t344 - _t322*_t720 + _t325*_t719 - _t335*_t38 + _t342*_t684 - _t351*_t631 - _t352*_t672 - _t401*_t413 + 0.6e1*_t616*_t722 - _t658*_t667 - _t666*_t720 + _t688*_t702 - _t717*_t718 - _t718*_t721 + _t726*_t728 + _t9*(-_hc0[0]*_hc1[23] - _hc0[1]*_hc1[13] - _hc0[12]*_t326 - _hc0[13]*_hc1[1] - _hc0[23]*_hc1[0] - _hc0[5]*_t713 - _hc0[6]*_t640 - _hc1[12]*_t325));
  out[69] = d4f_dc3_dx0;
  const double d4f_dc4 = A*(-_hc0[24]*_t14 - 0.8e1*_hc3[0]*_hc3[1]*_hc3[6]*_t68*_t73 + 0.24e2*_hc3[0]*_t197*_t4*_t734*_t74 + 0.4e1*_hc3[1]*_t26*_t327*_t8 + _hc3[10]*_t26*_t4*_t8 - ((_hc3[3]) * (_hc3[3]))*_t338 + 0.6e1*_hc3[3]*_t127*_t26*_t8 + 0.48e2*_hc3[3]*_t134*_t197*_t23*_t4*_t74 - _hc3[3]*_t647*_t735 + 0.4e1*_hc3[6]*_t26*_t42*_t8 - _t119*_t343 - _t127*_t340*_t72*_t735 + 0.3e1*_t133*_t203*_t348*_t46 + 0.3e1*_t133*_t346*_t86 - _t136*_t729 - 0.8e1*_t138*_t739 + _t17*(_t2*_t733 + _t732) - 0.24e2*_t190*_t262*_t339 + 0.32e2*_t197*_t23*_t333*_t42*_t74 + 0.2e1*_t203*_t346*_t348*_t47 + _t203*_t46*_t47*_t737 - _t322*_t743 + _t331*_t47*_t86 + 0.3e1*_t332*_t46*_t86 - _t334*_t606*_t68 - _t344*_t673 - _t344*_t738 + _t348*_t46*_t47*_t539*_t742 - _t351*_t682 - _t36*(_t12*_t733 + _t732) - _t4*_t522*_t530*_t734 - _t686*_t726 - _t705*_t740 - _t708*_t740 - _t711*_t725 - _t717*_t730 - _t721*_t730 - _t726*_t744 + _t9*(-_hc0[0]*_hc1[24] - _hc0[24]*_hc1[0] - _hc1[13]*_t653 - _hc1[2]*_t729 - _hc1[6]*_t730 + _hc2[10]));
  out[70] = d4f_dc4;
  const double d4f_db_drs3 = A*(0.9e1*_t113*_t188*_t23*_t4*_t59*_t72 - _t140*_t194 - _t140*_t574 + 0.24e2*_t142*_t195*_t197*_t260*_t4*_t67 + 0.3e1*_t148*_t203*_t204*_t87 + 0.3e1*_t148*_t84*_t86 - _t149*_t224 - _t152*_t559 - _t152*_t564 - _t155*_t225 + _t17*(_hc4[1]*_t2*_t760 + _hc4[10]*_t131*_t441 + _hc4[3]*_t210*_t568 - _hc4[3]*_t609 + _hc4[7]*_t572 - _t18*_t756 - _t2*_t755 + _t2*_t761 - _t441*_t613 - _t552*_t759 + _t573*_t758 - _t615*_t758 + _t650*_t762 + 0.2e1*_t757 + _t763) + (0.3e1 / 0.2e1)*_t186*_t23*_t4*_t59*_t68*_t72 - _t188*_t190*_t745 + 0.3e1*_t188*_t53*_t72*_t74*_t75 + 0.14e2*_t195*_t53*_t64*_t72*_t75 - 0.72e2*_t196*_t388*_t604 + 0.2e1*_t203*_t204*_t58*_t84 + _t203*_t536*_t58*_t87 + _t204*_t539*_t540*_t58*_t87 + _t211*_t58*_t86 + 0.6e1*_t23*_t28*_t359*_t4*_t68*_t72 + 0.24e2*_t23*_t4*_t59*_t64*_t72*_t74 - 0.18e2*_t254*_t391*_t67 + _t26*_t4*(-_hc3[2]*_t189*_t68 - _t141*_t187 + (0.3e1 / 0.2e1)*_t186*_t190 + 0.9e1*_t188*_t519 - _t192*_t749 + _t521*_t64) - 0.3e1*_t356*_t391 - _t36*(_hc4[10]*_hc4[3]*_t137 + _hc4[7]*_t206 - _t12*_t755 + _t12*_t761 - 0.3e1*_t144*_t96 + _t209*_t458*_t568 - _t221*_t55 - _t31*_t756 - _t458*_t613 + _t566*_t760 - _t569*_t759 + _t573*_t764 - _t573*_t765 - _t615*_t764 + _t620*_t765 + _t659*_t762 + _t757 + _t763) + 0.3e1*_t365*_t86*_t87 - _t366*_t618 - _t368*_t565 + 0.48e2*_t4*_t527*_t529*_t59*_t605*_t64 - 0.12e2*_t525*_t748 - _t554*_t750 - _t560*_t751 - _t580*_t753 - _t607*_t746 - _t752*_t98 - _t754*_t91);
  out[71] = d4f_db_drs3;
  const double d4f_db_dx0_drs2 = A*(0.4e1*_hc0[0]*_hc4[1]*_hc4[3]*_t28*_t35*_t82 + 0.2e1*_hc0[0]*_hc4[1]*_t20*_t28*_t62*_t89 + _hc0[0]*_hc4[14]*_t20*_t35*_t39 + _hc0[0]*_hc4[3]*_t20*_t213*_t214*_t39*_t91 + _hc0[0]*_hc4[3]*_t20*_t217*_t39*_t89 + (0.1e1 / 0.2e1)*_hc0[0]*_hc4[3]*_t20*_t35*_t64 + 0.6e1*_hc0[0]*_hc4[3]*_t207*_t35*_t39*_t83 + 0.2e1*_hc0[0]*_hc4[7]*_t20*_t39*_t89*_t91 + 0.2e1*_hc0[0]*_t1*_t152*_t213*_t214*_t39 + _hc0[0]*_t1*_t213*_t39*_t555*_t556*_t62 + _hc0[0]*_t1*_t214*_t39*_t562*_t62 + _hc0[0]*_t1*_t368*_t39*_t89 + (0.1e1 / 0.2e1)*_hc0[0]*_t1*_t62*_t64*_t89 + 0.2e1*_hc0[0]*_t39*_t62*_t82*_t83*_t89 + 0.2e1*_hc0[3]*_hc4[1]*_t20*_t39*_t89*_t91 + _hc0[3]*_hc4[4]*_t20*_t35*_t39 + 0.2e1*_hc0[3]*_t1*_t28*_t89*_t91 - _hc0[7]*_t229 - _hc0[7]*_t588 + (0.1e1 / 0.2e1)*_hc3[0]*_t154*_t24*_t26*_t64 + 0.2e1*_hc3[0]*_t154*_t26*_t67*_t68 - _hc4[3]*_t622 - _hc4[7]*_t123*_t266 - _t103*_t769 - _t124*_t368 + 0.4e1*_t142*_t23*_t28*_t38*_t68*_t72 - _t149*_t625 - _t152*_t239 - _t154*_t585 - _t155*_t621 + 0.8e1*_t195*_t197*_t260*_t38*_t59*_t67 - _t217*_t466 - _t219*_t767 + _t26*_t359*_t38 - _t275*_t361 - _t28*_t766 - _t356*_t409 - _t358*_t409 - _t366*_t628 - _t366*_t629 - _t373*_t623 - _t410*_t589 - _t581*_t750 - _t583*_t751 - _t628*_t770 - _t629*_t770);
  out[72] = d4f_db_dx0_drs2;
  const double d4f_db_dx02_drs = A*(-_hc0[14]*_t101 - _hc0[4]*_t371 + _hc4[3]*_t234*_t774 - _hc4[3]*_t632 - _hc4[7]*_t131*_t233 - _t1*_t752 + _t102*_t105*_t213*_t214*_t62 + _t105*_t144*_t287 + _t106*_t166*_t452 + _t106*_t435 - _t124*_t769 - _t149*_t81 - _t152*_t247 - _t152*_t293 + _t152*_t689 - _t161*_t587 + _t219*_t55 + _t234*_t777 + _t237*_t366 + _t237*_t770 + _t239*_t405 + _t240*_t250*_t750 + _t266*_t776 - _t277*_t375 + _t278*_t35*_t374 - _t278*_t775 + _t36*_t361 - _t374*_t597 - _t466*_t629 - _t598*_t62*_t778 - _t634*_t767 - _t635*_t751 - _t636*_t751 + _t765*_t773 + _t766 + _t772*_t81);
  out[73] = d4f_db_dx02_drs;
  const double d4f_db_dx03 = A*(0.6e1*_hc0[0]*_hc4[3]*_t207*_t214*_t248 + 0.6e1*_hc0[0]*_t248*_t556*_t62*_t82 + 0.6e1*_hc0[1]*_hc4[3]*_t20*_t35 + 0.6e1*_hc0[1]*_t1*_t62*_t89 - _hc0[10]*_t178 - _hc0[14]*_t641 - _hc0[25]*_t14 + _hc0[3]*_t20*_t245*_t89 + 0.2e1*_hc0[3]*_t20*_t39*_t89 + 0.3e1*_hc0[4]*_hc4[3]*_t20*_t35*_t39 + 0.3e1*_hc0[4]*_t1*_t39*_t62*_t89 + 0.3e1*_hc0[7]*_t108*_t20*_t89 - _hc4[3]*_t594 - _t161*_t592 + _t243*_t26*_t59 - _t245*_t380 - _t39*_t777 - _t596*_t771 - _t600*_t781 - _t644*_t780 - _t768*_t774 + _t9*(-_hc0[10]*_hc1[3] - _hc0[14]*_t242 - _hc0[25]*_hc1[0] - _hc0[4]*_t779));
  out[74] = d4f_db_dx03;
  const double d4f_db_dc_drs2 = A*(-_hc0[8]*_t229 - _hc0[8]*_t588 + 0.8e1*_hc3[0]*_hc3[1]*_t142*_t28*_t4*_t68*_t72 + (0.1e1 / 0.2e1)*_hc3[0]*_t158*_t24*_t26*_t64 + 0.2e1*_hc3[0]*_t158*_t26*_t67*_t68 - _hc3[1]*_t167*_t519*_t783 - _hc3[1]*_t167*_t64*_t70 + 0.56e2*_hc3[1]*_t195*_t197*_t4*_t59*_t67*_t75 + 0.8e1*_hc3[1]*_t197*_t260*_t261*_t53*_t67 + 0.4e1*_hc3[1]*_t197*_t4*_t59*_t64*_t74*_t75 + (0.1e1 / 0.2e1)*_hc3[1]*_t24*_t26*_t53*_t64 + 0.2e1*_hc3[1]*_t26*_t53*_t67*_t68 - _t122*_t368 + 0.4e1*_t142*_t23*_t28*_t42*_t68*_t72 + 0.2e1*_t148*_t203*_t204*_t46 + 0.2e1*_t148*_t305*_t86 - _t149*_t661 - _t152*_t308 - _t152*_t657 - _t155*_t273 - _t158*_t585 + _t162*_t203*_t204*_t87 + _t162*_t84*_t86 + 0.8e1*_t163*_t195*_t197*_t260*_t4*_t67 - _t165*_t230 - _t165*_t231 - _t169*_t359*_t73 + _t17*(-_hc4[1]*_t116*_t789 + _hc4[14]*_t392 + _t116*_t362*_t568 - _t164*_t573 + _t267*_t442 - _t269*_t790 - _t650*_t787 + _t793) - _t171*_t654 + 0.8e1*_t195*_t197*_t260*_t42*_t59*_t67 - _t201*_t257*_t4*_t784 + 0.2e1*_t203*_t204*_t305*_t58 + _t203*_t46*_t536*_t58 + _t204*_t46*_t539*_t540*_t58 - _t217*_t406 - _t217*_t407 - _t219*_t399 + 0.4e1*_t23*_t28*_t384*_t4*_t68*_t72 - _t259*_t782 + _t26*_t359*_t42 + _t26*_t4*(-_hc3[1]*_t355 + (0.1e1 / 0.2e1)*_hc3[4]*_t24*_t64 + 0.2e1*_hc3[4]*_t67*_t68 - _t602*_t67) - _t309*_t368 - _t356*_t425 - _t356*_t431 - _t358*_t425 - _t358*_t431 - _t36*(_hc4[14]*_t398 - _hc4[2]*_t566*_t789 - _hc4[4]*_t796 + _t164*_t798 - _t220*_t790 + _t397*_t442 + _t403*_t96 - _t659*_t787 + _t793) + _t365*_t46*_t86 - _t366*_t655 + 0.2e1*_t395*_t86*_t87 - _t396*_t589 - _t50*_t754 + _t58*_t652*_t86 - _t580*_t794 - _t624*_t782 - _t655*_t770 - _t753*_t795 - _t785*_t786);
  out[75] = d4f_db_dc_drs2;
  const double d4f_db_dc_dx0_drs = A*(0.2e1*_hc0[0]*_hc4[1]*_hc4[2]*_t39*_t62*_t82*_t89 + _hc0[0]*_hc4[2]*_t20*_t28*_t62*_t89 + _hc0[0]*_hc4[3]*_t20*_t213*_t214*_t39*_t50 + _hc0[0]*_hc4[3]*_t20*_t310*_t39*_t89 + _hc0[0]*_hc4[7]*_t20*_t39*_t50*_t89 + 0.2e1*_hc0[0]*_t1*_t152*_t214*_t39*_t50 + _hc0[0]*_t1*_t165*_t213*_t214*_t39 + 0.2e1*_hc0[0]*_t1*_t214*_t310*_t39*_t62 + _hc0[0]*_t1*_t39*_t399*_t89 + 0.2e1*_hc0[0]*_t1*_t39*_t50*_t555*_t556*_t62 - _hc0[15]*_t101 + _hc0[2]*_hc4[3]*_t20*_t39*_t89*_t91 + _hc0[2]*_hc4[7]*_t20*_t35*_t39 + _hc0[2]*_t1*_t152*_t39*_t89 + _hc0[2]*_t1*_t213*_t214*_t39*_t62 + _hc0[3]*_hc4[2]*_t20*_t39*_t89*_t91 + _hc0[3]*_t1*_t118*_t39*_t89 + _hc0[3]*_t1*_t213*_t214*_t39*_t51 - _hc0[5]*_t371 - _hc0[5]*_t457 + _hc0[8]*_hc4[1]*_t20*_t35*_t39 + _hc0[8]*_t1*_t28*_t35 - _hc0[8]*_t597 + 0.4e1*_hc3[0]*_hc3[1]*_t28*_t38*_t59*_t68*_t72 + 0.2e1*_hc3[1]*_t113*_t154*_t23*_t28*_t72 - _hc4[3]*_t115*_t401 - _t118*_t771 + _t121*_t142*_t26 + 0.2e1*_t121*_t23*_t28*_t59*_t68*_t72 - _t122*_t767 - _t124*_t399 - _t152*_t671 - _t154*_t694 - _t155*_t633 + 0.2e1*_t163*_t23*_t28*_t38*_t68*_t72 - _t165*_t595 - _t238*_t801 + _t26*_t38*_t384 - _t277*_t404 - _t278*_t406 - _t278*_t407 - _t278*_t408 - _t279*_t406 - _t279*_t407 - _t279*_t408 - _t28*_t38*_t389*_t76 - _t309*_t767 - _t309*_t799 - _t310*_t466 - _t313*_t366 - _t313*_t770 - _t36*(0.2e1*_hc4[2]*_hc4[7]*_t39*_t82 - _t28*_t403 - _t393*_t665) - _t390*_t800 - _t402*_t668 - _t403*_t577 - _t410*_t707 - _t411*_t628 - _t411*_t629);
  out[76] = d4f_db_dc_dx0_drs;
  const double d4f_db_dc_dx02 = A*(-_hc0[11]*_t178 - _hc0[14]*_t136 - _hc0[15]*_t674 - _hc0[26]*_t14 + _hc0[8]*_t251 + _t1*_t171*_t290 - _t106*_t166*_t169 - _t126*_t802 - _t149*_t159 + _t156*_t285 + _t163*_t236 + _t164*_t773 - _t165*_t247 - _t165*_t293 + _t165*_t689 - _t171*_t679 - _t214*_t396*_t778 + _t237*_t408 + _t283*_t55 + _t284*_t376 + _t284*_t378 + _t288*_t374 - _t313*_t775 + _t316*_t375 - _t320*_t806 + _t350*_t55 - _t36*_t796 + _t373*_t44 + _t374*_t684 + _t405*_t683 + _t410*_t692*_t706 + _t411*_t691 - _t417*_t639 - _t50*_t62*_t687 - _t584*_t796 + _t642*_t776 - _t685*_t805 - _t778*_t794 + _t803*_t804 + _t9*(-_hc0[11]*_hc1[3] - _hc0[14]*_hc1[2] - _hc0[15]*_t677 - _hc0[26]*_hc1[0] - _hc0[4]*_hc1[8] - _hc1[15]*_t105 - _hc1[5]*_t374 - _hc1[7]*_t284));
  out[77] = d4f_db_dc_dx02;
  const double d4f_db_dc2_drs = A*(-_hc0[16]*_t101 - _hc0[3]*_t703 - _hc0[6]*_t371 - _hc0[6]*_t457 + 0.8e1*_hc3[0]*_hc3[1]*_t163*_t28*_t4*_t68*_t72 + 0.8e1*_hc3[0]*_hc3[1]*_t28*_t42*_t59*_t68*_t72 + 0.4e1*_hc3[0]*_hc3[3]*_t28*_t4*_t59*_t68*_t72 + 0.6e1*_hc3[0]*_t113*_t134*_t28*_t53*_t72 + 0.4e1*_hc3[1]*_t113*_t158*_t23*_t28*_t72 + 0.2e1*_hc3[3]*_t113*_t23*_t28*_t53*_t72 - _hc3[3]*_t386*_t809 - _t103*_t423 + 0.8e1*_t113*_t134*_t142*_t197*_t23*_t4 - _t126*_t815 + _t127*_t142*_t26 + 0.2e1*_t127*_t23*_t28*_t59*_t68*_t72 - 0.40e2*_t134*_t256*_t385*_t388 + 0.48e2*_t134*_t260*_t261*_t28*_t4*_t529*_t59 + 0.4e1*_t134*_t28*_t4*_t59*_t68*_t72 - _t138*_t370 - _t140*_t296 + _t148*_t203*_t348*_t46 + _t148*_t346*_t86 - _t149*_t306 - _t152*_t705 - _t152*_t708 - _t155*_t307 - _t158*_t26*_t664 + 0.2e1*_t162*_t203*_t204*_t46 + 0.2e1*_t162*_t305*_t86 + 0.4e1*_t163*_t23*_t28*_t42*_t68*_t72 - _t165*_t308 - _t165*_t657 + _t17*(0.24e2*_hc4[1]*_hc4[3]*_t128*_t2*_t547 - _hc4[7]*_t302 - _t680*_t758 - _t813) + _t203*_t204*_t346*_t58 + _t203*_t305*_t348*_t58 + _t203*_t46*_t58*_t701 + 0.2e1*_t23*_t28*_t4*_t420*_t68*_t72 + 0.2e1*_t26*_t384*_t42 + _t26*_t4*(-_hc3[7]*_t383 + _t28*_t807) - _t277*_t418 - _t283*_t399 + _t303*_t58*_t86 - _t310*_t407 - _t310*_t433 + _t348*_t46*_t539*_t540*_t58 - _t350*_t399 - _t351*_t366 - _t36*(0.24e2*_hc4[1]*_hc4[3]*_t12*_t128*_t547 - _hc4[7]*_t421 - _t680*_t764 - _t813) - _t384*_t427*_t73 - _t391*_t428 - _t391*_t430 + 0.2e1*_t395*_t46*_t86 - _t396*_t707 - _t408*_t655 - _t411*_t710 + _t416*_t86*_t87 - _t417*_t669 - _t417*_t670 - 0.16e2*_t42*_t811 - _t42*_t812 - _t643*_t814 - _t695*_t746 - _t704*_t803 - _t753*_t816 - _t786*_t808);
  out[78] = d4f_db_dc2_drs;
  const double d4f_db_dc2_dx0 = A*(-_hc0[12]*_t178 - _hc0[15]*_t681 - _hc0[16]*_t107 - _hc0[27]*_t14 + _hc0[3]*_t719 + _hc0[6]*_t376 + _hc0[6]*_t378 + _hc4[3]*_t123*_t680 + _t100*_t420 + _t102*_t138*_t751 + _t121*_t818 - _t121*_t822 - _t124*_t423 + _t126*_t320*_t405 + _t126*_t820 - _t128*_t373*_t39*_t82 + _t134*_t254*_t38*_t809 - _t138*_t771 - _t154*_t419 + _t154*_t714 + _t156*_t314 - _t165*_t683 + _t165*_t724 - _t284*_t432 - _t284*_t817 + _t288*_t417 - _t313*_t407 - _t313*_t433 - _t313*_t819 + _t315*_t821 + _t317*_t404 + _t319*_t423 - _t320*_t801 - _t351*_t466 - _t38*_t424*_t427 - _t401*_t796 + _t405*_t705 + _t405*_t708 - _t408*_t720 - _t409*_t428 - _t409*_t430 - _t410*_t825 - _t411*_t720 + _t417*_t684 + _t653*_t706*_t823 - _t667*_t796 + _t722*_t780 + _t725*_t824 + _t728*_t826 + _t9*(-_hc0[0]*_hc1[27] - _hc0[1]*_hc1[16] - _hc0[12]*_hc1[3] - _hc0[15]*_t676 - _hc0[16]*_hc1[1] - _hc0[27]*_hc1[0] - _hc0[3]*_hc1[12] - _hc0[6]*_hc1[7] - _hc0[7]*_hc1[6] - _hc1[15]*_t126 - _hc1[5]*_t417 - _hc1[8]*_t284));
  out[79] = d4f_db_dc2_dx0;
  const double d4f_db_dc3 = A*(-_hc0[13]*_t178 - _hc0[16]*_t716 - _hc0[28]*_t14 + 0.24e2*_hc3[0]*_t113*_t197*_t333*_t4*_t59 + 0.24e2*_hc3[1]*_hc3[3]*_t113*_t197*_t23*_t4*_t59 + 0.3e1*_hc3[1]*_t26*_t418*_t8 - 0.6e1*_hc3[3]*_t110*_t167 + 0.3e1*_hc3[3]*_t158*_t26*_t8 - _hc3[6]*_t167*_t168 + _hc3[6]*_t26*_t53*_t8 + 0.24e2*_t113*_t134*_t163*_t197*_t23*_t4 + 0.24e2*_t113*_t134*_t197*_t23*_t42*_t59 + 0.3e1*_t127*_t163*_t26 - _t127*_t166*_t833 - _t138*_t837 - _t149*_t343 - _t155*_t344 - _t158*_t715 + 0.3e1*_t162*_t203*_t348*_t46 + 0.3e1*_t162*_t346*_t86 - 0.6e1*_t165*_t739 + _t17*(_t2*_t829 + _t828) + 0.8e1*_t197*_t23*_t333*_t53*_t74 + 0.2e1*_t203*_t346*_t348*_t58 + _t203*_t46*_t58*_t737 + _t26*_t327*_t59 + _t26*_t4*(_hc3[11]*_t8 - _t693) + 0.3e1*_t26*_t42*_t420 - _t298*_t333*_t4*_t784 - _t325*_t62*_t825 - _t325*_t838 + _t331*_t58*_t86 - _t335*_t53 - _t342*_t432 - _t342*_t817 - _t345*_t423 + _t348*_t46*_t539*_t58*_t742 - _t351*_t407 - _t36*(_t12*_t829 + _t828) - _t396*_t825 - _t411*_t743 + 0.3e1*_t416*_t46*_t86 - _t42*_t424*_t836 - _t420*_t73*_t833 - _t423*_t738 - _t425*_t834 - _t425*_t835 - _t431*_t834 - _t431*_t835 - _t433*_t725 - _t705*_t839 - _t708*_t839 - _t712*_t782 - _t717*_t831 - _t721*_t831 - _t744*_t826 + _t9*(-_hc0[0]*_hc1[28] - _hc0[13]*_hc1[3] - _hc0[16]*_t326 - _hc0[28]*_hc1[0] - _hc0[3]*_hc1[13] - _hc0[6]*_t830 - _hc0[8]*_t713 - _hc1[16]*_t325 + _hc2[11]));
  out[80] = d4f_db_dc3;
  const double d4f_db2_drs2 = A*(-_hc0[9]*_t229 - _hc0[9]*_t588 - _t149*_t367 - _t152*_t238*_t860 + _t167*(-_hc3[0]*_t857 + _t254*_t645 + _t67*_t858 - _t70*_t749) + _t17*(-_hc4[1]*_t441*_t868 - _hc4[4]*_t470 + _t2*_t863 - _t269*_t865 + _t441*_t866 - _t650*_t864 + _t758*_t791 + _t797*_t867 + _t869) - _t172*_t585 + _t176*_t531 + _t176*_t538 + _t177*_t364 + _t179*_t26*_t359 - _t180*_t230 - _t180*_t231 + _t181*_t297*_t845 - _t217*_t861 - _t219*_t459 + _t27*(_hc3[5]*_t24*_t65 + _hc3[5]*_t67*_t69 + _t646 + _t648 - _t69*_t749 - _t857) + _t29*_t65*_t840 - _t356*_t451 - _t358*_t451 + _t359*_t455 - _t36*(-_hc4[3]*_t566*_t868 - _hc4[4]*_t443 + _t12*_t863 + _t173*_t798 + _t175*_t96 - _t220*_t865 + _t458*_t866 - _t659*_t864 + _t764*_t791 + _t869) + _t365*_t453 - _t366*_t871 - _t368*_t373 - _t368*_t460 + _t390*_t746*_t844 + _t390*_t848 - _t436*_t841 - _t436*_t843 + _t439*_t846 + 0.2e1*_t446*_t88 + _t449*_t542 - _t456*_t841 - _t456*_t843 + _t502*_t536 + 0.16e2*_t53*_t67*_t748 + _t532*_t854 - _t561*_t872 - _t589*_t859 - _t61*_t754 + _t71*_t840 - _t753*_t870 - _t770*_t871 + 0.8e1*_t785*_t851 + _t809*_t844*_t847 + 0.24e2*_t845*_t850 + _t852*_t853 + _t852*_t855);
  out[81] = d4f_db2_drs2;
  const double d4f_db2_dx0_drs = A*(0.2e1*_hc0[0]*_hc4[1]*_hc4[3]*_t39*_t62*_t82*_t89 + _hc0[0]*_hc4[3]*_t151*_t20*_t39*_t89 + _hc0[0]*_hc4[3]*_t20*_t213*_t214*_t39*_t61 + _hc0[0]*_hc4[3]*_t20*_t28*_t62*_t89 + _hc0[0]*_hc4[7]*_t20*_t39*_t61*_t89 + 0.2e1*_hc0[0]*_t1*_t151*_t214*_t39*_t62 + 0.2e1*_hc0[0]*_t1*_t152*_t214*_t39*_t61 + _hc0[0]*_t1*_t180*_t213*_t214*_t39 + _hc0[0]*_t1*_t39*_t459*_t89 + 0.2e1*_hc0[0]*_t1*_t39*_t555*_t556*_t61*_t62 - _hc0[17]*_t101 + 0.2e1*_hc0[3]*_hc4[3]*_t20*_t39*_t89*_t91 + 0.2e1*_hc0[3]*_hc4[7]*_t20*_t35*_t39 + 0.2e1*_hc0[3]*_t1*_t152*_t39*_t89 + 0.2e1*_hc0[3]*_t1*_t213*_t214*_t39*_t62 + _hc0[9]*_hc4[1]*_t20*_t35*_t39 + _hc0[9]*_t1*_t28*_t35 - _hc0[9]*_t597 - _hc4[3]*_t266*_t402 - _t124*_t459 + 0.2e1*_t142*_t154*_t26 + _t142*_t183*_t38*_t72 - _t144*_t149*_t39 - _t151*_t466 + 0.4e1*_t154*_t23*_t28*_t59*_t68*_t72 - _t175*_t577 - _t180*_t595 + 0.2e1*_t181*_t23*_t28*_t38*_t68*_t72 + 0.4e1*_t183*_t197*_t23*_t28*_t38*_t59*_t68 + _t26*_t38*_t447 - _t277*_t463 - _t278*_t465 - _t278*_t861 - _t279*_t465 - _t36*(0.4e1*_hc4[3]*_hc4[7]*_t39*_t82 - _t175*_t28 - _t440*_t665) - _t366*_t405 - _t371*_t374 - _t373*_t767 - _t374*_t457 + _t38*_t454*_t59*_t72 - _t405*_t770 - _t460*_t767 - _t460*_t799 - _t468*_t628 - _t468*_t629 - _t579*_t872 - _t62*_t629*_t751 - _t781*_t870);
  out[82] = d4f_db2_dx0_drs;
  const double d4f_db2_dx02 = A*(-_hc0[14]*_t876 - _hc0[17]*_t674 - _hc0[29]*_t14 + _hc0[9]*_t251 + _t105*_t878 + _t106*_t467 - _t108*_t586*_t879 - 0.2e1*_t149*_t55 + _t155*_t444 - _t180*_t247 + _t180*_t689 + _t181*_t236 + _t233*_t875 - _t237*_t462 + _t237*_t465 - _t292*_t61*_t805 - _t293*(_t173*_t690 + _t174) - _t36*_t443 + _t375*_t464 + _t378*_t874 - _t405*_t775 - _t443*_t584 + _t444*_t772 + _t468*_t691 - _t505*_t806 + _t507*_t55 + _t61*_t692*_t781 + (_t62 * _t62)*_t687 + _t776*_t805 - _t802*_t860 + _t804*_t877 + _t9*(-_hc0[14]*_t873 - _hc0[17]*_t677 - _hc0[29]*_hc1[0] - _hc0[4]*_hc1[9] - _hc1[17]*_t105 - _hc1[7]*_t874));
  out[83] = d4f_db2_dx02;
  const double d4f_db2_dc_drs = A*(-_hc0[18]*_t101 + 0.4e1*_hc3[0]*_hc3[1]*_t181*_t28*_t4*_t68*_t72 + 0.8e1*_hc3[0]*_hc3[1]*_t183*_t197*_t28*_t4*_t59*_t68 + 0.8e1*_hc3[0]*_hc3[1]*_t28*_t53*_t59*_t68*_t72 + 0.2e1*_hc3[1]*_t113*_t172*_t23*_t28*_t72 - _t103*_t478 - _t118*_t462 - _t122*_t459 + 0.2e1*_t142*_t158*_t26 + _t142*_t183*_t42*_t72 + _t142*_t4*_t482*_t72 + _t147*_t162*_t86 + _t147*_t203*_t348*_t58 + _t148*_t203*_t348*_t57 + _t148*_t476*_t86 + _t149*_t399 - _t151*_t406 - _t151*_t408 - _t151*_t433 + 0.4e1*_t158*_t23*_t28*_t59*_t68*_t72 + _t162*_t203*_t204*_t57 + 0.4e1*_t163*_t183*_t197*_t23*_t28*_t4*_t68 + 0.4e1*_t163*_t23*_t28*_t53*_t68*_t72 + _t163*_t4*_t454*_t72 - _t165*_t752 - _t169*_t846 + _t17*(0.24e2*_hc4[1]*_hc4[2]*_t173*_t2*_t547 - _t267*_t875 - _t789*_t880 - _t882) - _t171*_t815 - _t172*_t694 + _t176*_t203*_t204*_t46 + _t176*_t305*_t86 - _t180*_t280 - _t180*_t656 + 0.2e1*_t181*_t23*_t28*_t42*_t68*_t72 + 0.4e1*_t183*_t197*_t23*_t28*_t42*_t59*_t68 + _t183*_t384*_t4*_t72 - _t184*_t427*_t785 + 0.4e1*_t197*_t23*_t28*_t4*_t482*_t59*_t68 + _t203*_t204*_t476*_t58 + _t203*_t57*_t58*_t701 - _t216*_t888 + 0.2e1*_t23*_t28*_t4*_t479*_t68*_t72 - _t238*_t884 + 0.2e1*_t26*_t384*_t53 + _t26*_t4*(0.4e1*_hc3[4]*_t28*_t68 - _hc3[8]*_t383 - _t28*_t602) + _t26*_t42*_t447 - _t277*_t475 - _t286*_t872 - _t309*_t459 - _t310*_t465 + _t348*_t539*_t540*_t57*_t58 - _t353*_t872 - _t36*(0.24e2*_hc4[1]*_hc4[2]*_t12*_t173*_t547 - _t12*_t207*_t881 - _t397*_t875 - _t882) - _t366*_t480 - _t371*_t417 - _t373*_t399 - _t386*_t387*_t883 + _t395*_t57*_t86 - _t395*_t58*_t86 - _t399*_t460 + _t4*_t59*_t72*(_hc3[0]*_hc3[4]*_t887 + _hc3[1]*_hc3[2]*_t887 - _t28*_t886) - _t417*_t457 + _t42*_t454*_t59*_t72 + _t446*_t46*_t86 - _t468*_t710 + _t474*_t86*_t87 - _t480*_t770 - _t520*_t75*_t810*_t850 - 0.16e2*_t53*_t811 - _t53*_t812 - _t704*_t859 - _t753*_t889 - _t780*_t814 - _t794*_t870 - _t847*_t885);
  out[84] = d4f_db2_dc_drs;
  const double d4f_db2_dc_dx0 = A*(-_hc0[15]*_t876 - _hc0[17]*_t136 - _hc0[18]*_t107 - _hc0[30]*_t14 - _hc0[5]*_t506 - _hc0[5]*_t891 + _t100*_t479 + _t102*_t180*_t286 + _t102*_t706*_t877 + _t121*_t467 + _t121*_t498 + _t123*_t208*_t472 - _t124*_t478 + _t154*_t818 - _t154*_t822 + _t171*_t820 - _t175*_t667 + _t180*_t323*_t723 - _t180*_t671 + _t215*_t323*_t888 - _t283*_t39*_t890 + _t286*_t892 + _t313*_t462 - _t313*_t465 - _t313*_t861 + _t316*_t463 + _t319*_t478 + _t353*_t892 - _t374*_t432 - _t374*_t817 + _t376*_t417 + _t378*_t417 - _t402*_t796 + _t403*_t821 - _t403*_t893 + _t404*_t464 - _t405*_t406 - _t405*_t408 - _t405*_t433 + _t405*_t837 + _t409*_t482 + _t424*_t895 - _t450*_t800 - _t466*_t480 - _t468*_t720 + _t480*_t894 - _t579*_t888 + _t61*_t643*_t823 + _t688*_t884 + _t728*_t897 - _t781*_t889 + _t824*_t896 - _t885*_t895 + _t9*(-_hc0[0]*_hc1[30] - _hc0[1]*_hc1[18] - _hc0[15]*_t873 - _hc0[17]*_hc1[2] - _hc0[18]*_hc1[1] - _hc0[2]*_hc1[17] - _hc0[30]*_hc1[0] - _hc0[5]*_hc1[9] - _hc0[9]*_hc1[5] - _hc1[15]*_t171 - _hc1[7]*_t417 - _hc1[8]*_t374));
  out[85] = d4f_db2_dc_dx0;
  const double d4f_db2_dc2 = A*(-_hc0[16]*_t876 - _hc0[18]*_t681 - _hc0[31]*_t14 - _hc0[6]*_t506 - _hc0[6]*_t891 + 0.2e1*_hc3[1]*_t26*_t475*_t8 + _hc3[3]*_t172*_t26*_t8 + 0.8e1*_t113*_t134*_t181*_t197*_t23*_t4 + 0.24e2*_t113*_t134*_t183*_t23*_t4*_t529*_t59 + 0.16e2*_t113*_t134*_t197*_t23*_t53*_t59 - _t126*_t906 - _t126*_t907 + _t127*_t181*_t26 + _t127*_t183*_t59*_t72 - _t138*_t462 - _t149*_t422 + 0.4e1*_t158*_t163*_t26 - _t158*_t166*_t902 + 0.2e1*_t162*_t203*_t348*_t57 + 0.2e1*_t162*_t476*_t86 + 0.2e1*_t163*_t183*_t42*_t72 + 0.2e1*_t163*_t4*_t482*_t72 - _t165*_t320*_t860 + _t17*(_t132*_t173*_t568 + _t899) - _t171*_t838 - _t172*_t419 + _t176*_t203*_t348*_t46 + _t176*_t346*_t86 - _t180*_t705 - _t180*_t708 - _t183*_t388*_t42*_t902 + _t183*_t4*_t420*_t72 - _t184*_t808*_t902 + 0.2e1*_t203*_t348*_t476*_t58 + _t203*_t57*_t58*_t737 + _t26*_t4*(_hc3[12]*_t8 - _hc3[7]*_t429 + _t807) + 0.2e1*_t26*_t418*_t59 + 0.2e1*_t26*_t42*_t479 + 0.2e1*_t26*_t420*_t53 - _t283*_t478 - _t320*_t884 + _t348*_t539*_t57*_t58*_t742 - _t350*_t478 - _t36*(_t898*_t901 + _t899) - _t373*_t423 - _t388*_t4*_t482*_t902 + _t4*_t59*_t72*(0.4e1*_hc3[0]*_hc3[3]*_t68 - _hc3[7]*_t168 - _t110*_t909 + 0.4e1*_t134*_t68 - _t295*_t481) - _t408*_t896 + _t415*_t58*_t86 + _t416*_t57*_t86 - _t42*_t427*_t450 + 0.2e1*_t42*_t482*_t59*_t72 - _t423*_t460 - _t424*_t53*_t902 - _t427*_t479*_t73 - _t428*_t451 - _t430*_t451 - _t432*_t900 - _t433*_t896 - _t436*_t903 - _t436*_t905 - _t456*_t903 - _t456*_t905 + 0.2e1*_t46*_t474*_t86 - _t468*_t743 - _t480*_t819 - _t643*_t897 - _t744*_t897 - _t780*_t826 - _t817*_t900 - _t888*_t908 + _t9*(-_hc0[0]*_hc1[31] - _hc0[16]*_t873 - _hc0[18]*_t676 - _hc0[31]*_hc1[0] - _hc0[6]*_hc1[9] - _hc0[9]*_hc1[6] - _hc1[16]*_t171 - _hc1[18]*_t126 - _hc1[8]*_t900 + _hc2[12]));
  out[86] = d4f_db2_dc2;
  const double d4f_db3_drs = A*(-_hc0[19]*_t101 - _t103*_t494 + _t147*_t58*_t921 + _t149*_t459 - _t151*_t931 - _t151*_t932 + _t166*_t172*_t911 + _t166*_t454*_t499 + _t167*(_hc3[0]*_hc3[5]*_t887 - _hc3[0]*_t28*_t928 + _t28*_t858 + _t512*_t887) + _t17*(0.24e2*_hc4[1]*_t2*_t487*_t547 - _t18*_t912 - _t867*_t913 - _t914) - _t177*_t446 + _t181*_t198*_t851 + _t183*_t390*_t499 + _t23*_t28*_t735*_t924 - _t238*_t920 + _t27*(_hc3[5]*_t28*_t336 - _hc3[9]*_t383 + _t28*_t521 - 0.18e2*_t28*_t856) - _t277*_t486 - _t36*(0.24e2*_hc4[1]*_t12*_t487*_t547 - _t12*_t173*_t913 - _t31*_t912 - _t914) - _t366*_t508 - _t371*_t491 + _t385*_t388*_t438*_t513 + _t391*_t513 + _t435*_t497 + _t446*_t492 + _t447*_t509 + _t447*_t745 + _t450*_t848 + _t452*_t919 + _t456*(0.8e1*_hc3[0]*_hc3[2]*_t28*_t68 - _t28*_t842) - _t457*_t491 - _t459*_t495 - _t459*_t507 - _t465*_t871 - _t468*(-_hc4[3]*_t709 + _t12*_t361 + 0.2e1*_t150 + _t922) - _t484*_t872*_t89 + _t490*_t88 + _t496*_t853 + _t496*_t855 + _t502*(0.2e1*_t143 + _t2*_t361 - _t266*_t441 + _t922) - _t508*_t770 - _t511*_t753 + _t532*_t915 + _t541*_t918 - _t561*_t929 - _t62*_t870*_t927 + _t785*_t926 + _t847*_t925 + _t852*_t917 + _t854*_t921 - _t872*_t933 + _t911*_t916 + _t911*_t930);
  out[87] = d4f_db3_drs;
  const double d4f_db3_dx0 = A*(-_hc0[17]*_t935 - _hc0[19]*_t107 - _hc0[32]*_t14 - 0.3e1*_hc0[7]*_t506 + _t100*_t504 + 0.6e1*_t102*_t61*_t879 - _t105*_t938 + _t123*_t912 - _t124*_t494 + 0.3e1*_t154*_t467 + 0.3e1*_t154*_t498 + 0.3e1*_t156*_t463 + _t175*_t821 + _t215*_t692*_t929 + _t319*_t494 + _t378*_t491 - _t402*_t470 + 0.3e1*_t405*_t462 - _t405*_t931 - _t405*_t932 + _t405*_t939 + _t409*_t513 - _t443*_t893 + 0.2e1*_t450*_t895 - _t465*_t937 - _t466*_t508 - _t468*_t937 + _t484*_t878 + _t508*_t894 - _t511*_t781 + _t688*_t920 + _t727*_t942 - _t771*_t936 + _t824*_t940 + _t895*_t925 + _t9*(-_hc0[0]*_hc1[32] - _hc0[1]*_hc1[19] - _hc0[17]*_t485 - _hc0[19]*_hc1[1] - _hc0[32]*_hc1[0] - _hc0[7]*_t934 - _hc0[9]*_t779 - _hc1[17]*_t484));
  out[88] = d4f_db3_dx0;
  const double d4f_db3_dc = A*(-_hc0[18]*_t935 - _hc0[19]*_t136 - _hc0[33]*_t14 - _hc3[1]*_t166*_t29*_t945 + _hc3[1]*_t26*_t486*_t8 - _t122*_t494 - _t126*_t938 - _t149*_t477 + 0.3e1*_t158*_t181*_t26 + 0.3e1*_t158*_t183*_t59*_t72 + _t162*_t203*_t501*_t57 + _t162*_t496*_t86 + 0.3e1*_t163*_t172*_t26 + _t163*_t183*_t197*_t4*_t514 + 0.3e1*_t163*_t183*_t53*_t72 + _t163*_t4*_t513*_t72 - _t169*_t919 + _t17*(_t2*_t568*_t943 + _t944) + 0.2e1*_t176*_t203*_t348*_t57 + 0.2e1*_t176*_t476*_t86 + 0.2e1*_t181*_t183*_t42*_t72 + 0.2e1*_t181*_t4*_t482*_t72 + _t183*_t197*_t4*_t59*(0.8e1*_hc3[0]*_hc3[1]*_t68 - 0.4e1*_hc3[2]*_t110 - _hc3[4]*_t426) + _t183*_t197*_t42*_t514*_t59 + 0.2e1*_t183*_t4*_t479*_t72 - _t184*_t883*_t902 + _t197*_t4*_t482*_t514*_t59 + _t203*_t348*_t496*_t58 + _t203*_t476*_t501*_t58 + _t203*_t57*_t58*(-_t265*_t880 - _t946) + _t26*_t4*(_hc3[13]*_t8 + 0.6e1*_hc3[4]*_t68 - _hc3[8]*_t503 - _t602) + _t26*_t42*_t504 + 0.3e1*_t26*_t475*_t59 + 0.3e1*_t26*_t479*_t53 - _t309*_t494 - _t36*(_t901*_t943 + _t944) - _t4*_t513*_t885 + _t4*_t59*_t72*(0.8e1*_hc3[0]*_hc3[4]*_t68 + 0.8e1*_hc3[1]*_hc3[2]*_t68 - _hc3[5]*_t663 - _hc3[8]*_t168 - _t141*_t909 - _t886) - _t406*_t508 - _t408*_t508 + _t42*_t513*_t59*_t72 - _t432*_t491 - _t433*_t508 + _t46*_t490*_t86 - _t462*_t839 - _t465*_t896 - _t468*(-_t12*_t796 - _t946) + _t473*_t58*_t86 + 0.2e1*_t474*_t57*_t86 - _t478*_t495 - _t478*_t507 - _t480*_t931 - _t480*_t932 + 0.3e1*_t482*_t53*_t59*_t72 - _t484*_t906 - _t484*_t907 + _t501*_t539*_t57*_t58*_t742 - _t506*_t831 - _t511*_t794 - _t744*_t941 - _t831*_t891 - _t833*_t916 - _t833*_t930 - _t836*_t924 - _t888*_t933 - _t897*_t927 + _t9*(-_hc0[0]*_hc1[33] - _hc0[18]*_t485 - _hc0[19]*_hc1[2] - _hc0[2]*_hc1[19] - _hc0[33]*_hc1[0] - _hc0[8]*_t934 - _hc0[9]*_t830 - _hc1[18]*_t484 + _hc2[13]) - _t908*_t929);
  out[89] = d4f_db3_dc;
  const double d4f_db4 = A*(-_hc0[34]*_t14 + 0.4e1*_t140*_t504 - _t149*_t493 - 0.4e1*_t155*_t494 + 0.4e1*_t156*_t486 + _t167*(-0.36e2*_hc3[0]*_t856 + _hc3[0]*_t953 - 0.6e1*_hc3[5]*_t141 - _hc3[9]*_t168 + _t512*_t735 + _t858) + _t17*(_t2*_t951 + _t950) + _t177*_t489 - _t178*_t947 - 0.6e1*_t180*_t462 + 0.3e1*_t181*_t197*_t926 + _t183*_t450*_t746 - _t214*_t511*_t877 + _t27*(_hc3[14]*_t8 - _hc3[9]*_t904 + _t521 - _t928 + _t953) - _t36*(_t12*_t951 + _t950) - _t377*_t508*_t860 + 0.2e1*_t4*_t513*_t925 + 0.4e1*_t436*_t513 + 0.3e1*_t451*_t513 + 0.3e1*_t453*_t490 + 0.3e1*_t455*_t504 + _t456*(0.16e2*_hc3[0]*_hc3[2]*_t68 - _hc3[5]*_t426 - _t512*_t904 - _t842) - 0.3e1*_t460*_t494 - 0.3e1*_t465*_t508 + _t467*_t945 - _t468*(-_t12*_t443 - _t952) + 0.2e1*_t496*_t58*_t921 + 0.3e1*_t496*_t917 + _t498*_t945 + _t502*(-_t2*_t443 - _t952) - _t506*_t948 + _t539*_t918*(0.3e1*_t56 + _t954) - 0.8e1*_t751*_t929 + _t9*(-_hc0[0]*_hc1[34] - _hc0[34]*_hc1[0] - _hc1[19]*_t860 - _hc1[3]*_t947 - _hc1[9]*_t948 + _hc2[14]) + 0.3e1*_t915*_t921 + 0.4e1*_t923*_t925 + _t930*(-_hc3[2]*_t832 + _t910) - _t932*_t940 - _t936*_t939 - _t942*(0.3e1*_t60 + _t954));
  out[90] = d4f_db4;
  const double d4f_dA_drs3 = _t226;
  out[91] = d4f_dA_drs3;
  const double d4f_dA_dx0_drs2 = _t232;
  out[92] = d4f_dA_dx0_drs2;
  const double d4f_dA_dx02_drs = _t241;
  out[93] = d4f_dA_dx02_drs;
  const double d4f_dA_dx03 = _t252;
  out[94] = d4f_dA_dx03;
  const double d4f_dA_dc_drs2 = _t274;
  out[95] = d4f_dA_dc_drs2;
  const double d4f_dA_dc_dx0_drs = _t282;
  out[96] = d4f_dA_dc_dx0_drs;
  const double d4f_dA_dc_dx02 = _t294;
  out[97] = d4f_dA_dc_dx02;
  const double d4f_dA_dc2_drs = _t311;
  out[98] = d4f_dA_dc2_drs;
  const double d4f_dA_dc2_dx0 = _t324;
  out[99] = d4f_dA_dc2_dx0;
  const double d4f_dA_dc3 = _t354;
  out[100] = d4f_dA_dc3;
  const double d4f_dA_db_drs2 = _t369;
  out[101] = d4f_dA_db_drs2;
  const double d4f_dA_db_dx0_drs = _t372;
  out[102] = d4f_dA_db_dx0_drs;
  const double d4f_dA_db_dx02 = _t381;
  out[103] = d4f_dA_db_dx02;
  const double d4f_dA_db_dc_drs = _t400;
  out[104] = d4f_dA_db_dc_drs;
  const double d4f_dA_db_dc_dx0 = _t412;
  out[105] = d4f_dA_db_dc_dx0;
  const double d4f_dA_db_dc2 = _t434;
  out[106] = d4f_dA_db_dc2;
  const double d4f_dA_db2_drs = _t461;
  out[107] = d4f_dA_db2_drs;
  const double d4f_dA_db2_dx0 = _t469;
  out[108] = d4f_dA_db2_dx0;
  const double d4f_dA_db2_dc = _t483;
  out[109] = d4f_dA_db2_dc;
  const double d4f_dA_db3 = _t515;
  out[110] = d4f_dA_db3;
  const double d4f_dA2_drs2 = 0;
  out[111] = d4f_dA2_drs2;
  const double d4f_dA2_dx0_drs = 0;
  out[112] = d4f_dA2_dx0_drs;
  const double d4f_dA2_dx02 = 0;
  out[113] = d4f_dA2_dx02;
  const double d4f_dA2_dc_drs = 0;
  out[114] = d4f_dA2_dc_drs;
  const double d4f_dA2_dc_dx0 = 0;
  out[115] = d4f_dA2_dc_dx0;
  const double d4f_dA2_dc2 = 0;
  out[116] = d4f_dA2_dc2;
  const double d4f_dA2_db_drs = 0;
  out[117] = d4f_dA2_db_drs;
  const double d4f_dA2_db_dx0 = 0;
  out[118] = d4f_dA2_db_dx0;
  const double d4f_dA2_db_dc = 0;
  out[119] = d4f_dA2_db_dc;
  const double d4f_dA2_db2 = 0;
  out[120] = d4f_dA2_db2;
  const double d4f_dA3_drs = 0;
  out[121] = d4f_dA3_drs;
  const double d4f_dA3_dx0 = 0;
  out[122] = d4f_dA3_dx0;
  const double d4f_dA3_dc = 0;
  out[123] = d4f_dA3_dc;
  const double d4f_dA3_db = 0;
  out[124] = d4f_dA3_db;
  const double d4f_dA4 = 0;
  out[125] = d4f_dA4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_vwn_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_aux_k, _KMAX)(p, 0.015545349999999999, 20.123100000000001, 101.578, -0.74329400000000001, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, z, _hc1);
  double _hc2[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1];
  XC_CAT(f_aux_k, _KMAX)(p, 0.031090699999999999, 13.071999999999999, 42.719799999999999, -0.40928599999999998, rs, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(one_minus_f_zeta_k, _KMAX)(p, z, _hc3);

  const double f = _hc0[0]*_hc1[0] + _hc2[0]*_hc3[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[0]*_hc1[1] + _hc2[0]*_hc3[1];
  out[1] = df_dz;
  const double df_drs = _hc0[1]*_hc1[0] + _hc2[1]*_hc3[0];
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[0]*_hc1[2] + _hc2[0]*_hc3[2];
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_hc1[1] + _hc2[1]*_hc3[1];
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[6]*_hc1[0] + _hc2[6]*_hc3[0];
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[0]*_hc1[3] + _hc2[0]*_hc3[3];
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[1]*_hc1[2] + _hc2[1]*_hc3[2];
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc0[6]*_hc1[1] + _hc2[6]*_hc3[1];
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[21]*_hc1[0] + _hc2[21]*_hc3[0];
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc0[0]*_hc1[4] + _hc2[0]*_hc3[4];
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc0[1]*_hc1[3] + _hc2[1]*_hc3[3];
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc0[6]*_hc1[2] + _hc2[6]*_hc3[2];
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[21]*_hc1[1] + _hc2[21]*_hc3[1];
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[56]*_hc1[0] + _hc2[56]*_hc3[0];
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(fx_vwn_b13p0720000000000_c42p7198000000000_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(rs, 1, 2);

  const double f = 13.071999999999999*_t1 + rs + 42.719799999999999;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.1e1 + 6.5359999999999996/_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -3.2679999999999998/xc_powr(rs, 3, 2);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 4.9019999999999992/xc_powr(rs, 5, 2);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -12.254999999999999/xc_powr(rs, 7, 2);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_aux_A0p0310907000000000_b13p0720000000000_c42p7198000000000_x0m0p409286000000000_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(fx_vwn_b13p0720000000000_c42p7198000000000_k, _KMAX)(p, rs, _hc0);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = -_hc0[0] + rs;
  const double _t3 = _t1*_t2;
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = 0.2e1*_t4 + 13.071999999999999;
  const double _t6 = _t4 + 0.40928599999999998;
  const double _t7 = -_hc0[0] + (_t6 * _t6);
  const double _t8 = _t1*_t7;
#if _KMAX >= 1
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = (0.1e1 / (_t5 * _t5));
  const double _t11 = 0.002016000000025997*_t10 + 0.1e1;
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
  const double _t25 = 0.0044313737677495373/_t24;
#endif
#if _KMAX >= 2
  const double _t26 = xc_powr(rs, -3, 2);
  const double _t27 = (0.1e1 / rs);
  const double _t28 = (0.1e1 / (_t11 * _t11));
  const double _t29 = xc_powi(_t5, -5);
  const double _t30 = _t28*_t29;
  const double _t31 = _t12/(_t5 * _t5 * _t5);
  const double _t32 = _hc0[2]*_t1;
  const double _t33 = _hc0[2]*_t16;
  const double _t34 = _t2*_t33;
  const double _t35 = 0.2e1*_t17;
  const double _t36 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t37 = ((_hc0[1]) * (_hc0[1]));
  const double _t38 = _t14*_t35 - 0.2e1*_t2*_t36*_t37 + _t32 + _t34;
  const double _t39 = -_t38;
  const double _t40 = (0.1e1 / (_t19 * _t19));
  const double _t41 = -_t18;
  const double _t42 = _t40*_t41;
  const double _t43 = 0.031090699999999999*_t18;
  const double _t44 = (0.1e1 / (_t24 * _t24));
  const double _t45 = -_t23;
  const double _t46 = _t44*_t45;
  const double _t47 = 0.0044313737677495373*_t23;
  const double _t48 = _t36*_t37;
  const double _t49 = -_hc0[2] - 0.1e1 / 0.2e1*_t26*_t6 + (0.1e1 / 0.2e1)*_t27;
  const double _t50 = _t1*_t49;
  const double _t51 = -_t21*_t35 - _t33*_t7 + 0.2e1*_t48*_t7 + _t50;
#endif
#if _KMAX >= 3
  const double _t52 = xc_powr(rs, -5, 2);
  const double _t53 = (0.1e1 / (rs * rs));
  const double _t54 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t55 = _t54/xc_powi(_t5, 8);
  const double _t56 = _t28/xc_powi(_t5, 6);
  const double _t57 = _t12/(_t5 * _t5 * _t5 * _t5);
  const double _t58 = _t40*_t43;
  const double _t59 = (0.1e1 / (_t19 * _t19 * _t19));
  const double _t60 = 0.2e1*_hc0[1]*_t16*_t2 - 0.2e1*_t15;
  const double _t61 = _t59*_t60;
  const double _t62 = _t41*_t43;
  const double _t63 = _hc0[3]*_t16;
  const double _t64 = 0.3e1*_t33;
  const double _t65 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t66 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t65;
  const double _t67 = -0.3e1*_hc0[1]*_hc0[2]*_t16 - 0.6e1*_hc0[1]*_hc0[2]*_t2*_t36 + _hc0[3]*_t1 - 0.6e1*_t14*_t36*_t37 + _t14*_t64 + _t2*_t63 + 0.6e1*_t2*_t66;
  const double _t68 = -_t67;
  const double _t69 = (0.1e1 / (_t24 * _t24 * _t24));
  const double _t70 = 0.2e1*_hc0[1]*_t16*_t7 - 0.2e1*_t22;
  const double _t71 = _t69*_t70;
  const double _t72 = _t45*_t71;
  const double _t73 = -_t51;
  const double _t74 = _t44*_t73;
  const double _t75 = -_hc0[3] + (0.3e1 / 0.4e1)*_t52*_t6 - 0.3e1 / 0.4e1*_t53;
  const double _t76 = -0.6e1*_hc0[1]*_hc0[2]*_t36*_t7 - _t1*_t75 + 0.3e1*_t17*_t49 - 0.6e1*_t21*_t36*_t37 + _t21*_t64 + _t63*_t7 + 0.6e1*_t66*_t7;
  const double _t77 = -_t76;
#endif
#if _KMAX >= 4
  const double _t78 = xc_powr(rs, -7, 2);
  const double _t79 = (0.1e1 / (rs * rs * rs));
  const double _t80 = 0.093272099999999997*_t39;
  const double _t81 = 0.4e1*_t17;
  const double _t82 = 0.4e1*_t48;
  const double _t83 = ((_hc0[2]) * (_hc0[2]));
  const double _t84 = 0.12e2*_t48;
  const double _t85 = _hc0[4]*_t16;
  const double _t86 = 0.4e1*_t63;
  const double _t87 = xc_powi((_hc0[0]), -5);
  const double _t88 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t89 = 0.24e2*_t66;
  const double _t90 = 0.36e2*_hc0[2]*_t37*_t65;
  const double _t91 = _t45*_t47;
  const double _t92 = 0.013294121303248613*_t51;
  const double _t93 = _hc0[1]*_t36;
#endif

  const double f = 20.521972937705183*atan(0.044899888641576798/_t5) + 0.031090699999999999*xc_log1p(_t3) + 0.0044313737677495373*xc_log1p(_t8);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.92143429960841539*_t13*_t9 + _t18*_t20 + _t23*_t25;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.46071714980420769*_t13*_t26 + _t20*_t39 + _t25*_t51 - 0.00371522309606904*_t27*_t30 + 1.8428685992168308*_t27*_t31 + _t42*_t43 + _t46*_t47;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.69107572470631151*_t13*_t52 + _t20*_t68 + _t25*_t77 - 2.9959559047087078e-5*_t26*_t55 + 0.026006561672483278*_t26*_t56 - 5.5286057976504921*_t26*_t57 + 0.00557283464410356*_t30*_t53 - 2.764302898825246*_t31*_t53 + _t38*_t58 + 0.062181399999999998*_t39*_t42 + 0.0088627475354990746*_t46*_t51 + _t47*_t72 + _t47*_t74 + _t61*_t62;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 22.114423190601968*_t12*_t29*_t53 + 1.7276893117657788*_t13*_t78 + 0.062181399999999998*_t18*_t38*_t61 + _t20*(0.24e2*_hc0[1]*_hc0[2]*_t14*_t36 + 0.4e1*_hc0[1]*_hc0[3]*_t16 + 0.8e1*_hc0[1]*_hc0[3]*_t2*_t36 - _hc0[2]*_t84 - _hc0[4]*_t1 - _t14*_t86 - _t14*_t89 + 0.6e1*_t16*_t83 + 0.6e1*_t2*_t36*_t83 - _t2*_t85 + 0.24e2*_t2*_t87*_t88 - _t2*_t90) + 0.0088627475354990746*_t23*_t71*_t73 + _t25*(0.24e2*_hc0[2]*_t21*_t93 + 0.8e1*_hc0[3]*_t7*_t93 + _t1*(-_hc0[4] - 0.15e2 / 0.8e1*_t6*_t78 + (0.15e2 / 0.8e1)*_t79) - _t21*_t86 - _t21*_t89 - 0.6e1*_t33*_t49 + 0.6e1*_t36*_t7*_t83 + _t49*_t84 - _t7*_t85 + 0.24e2*_t7*_t87*_t88 - _t7*_t90 - _t75*_t81) - 0.17833070861131392*_t28*_t53/xc_powi(_t5, 7) - 0.0139320866102589*_t30*_t79 + 6.9107572470631151*_t31*_t79 + _t38*_t40*_t80 + _t41*_t61*_t80 + 0.093272099999999997*_t42*_t68 + _t44*_t47*_t76 + 0.013294121303248613*_t46*_t77 + 8.9878677141261231e-5*_t52*_t55 - 0.078019685017449839*_t52*_t56 + 16.585817392951476*_t52*_t57 + _t58*_t67 + _t59*_t62*(_t14*_t81 - _t2*_t82 + 0.2e1*_t32 + 0.2e1*_t34) + _t69*_t91*(0.4e1*_hc0[1]*_t16*_t21 + 0.2e1*_hc0[2]*_t16*_t7 - 0.2e1*_t50 - _t7*_t82) + _t72*_t92 + _t74*_t92 + 0.00044939338570630617*_t53*_t54/xc_powi(_t5, 9) + _t70*_t91*(0.3e1*_hc0[1]*_t16*_t7 - 0.3e1*_t22)/(_t24 * _t24 * _t24 * _t24) + _t60*_t62*(0.3e1*_hc0[1]*_t16*_t2 - 0.3e1*_t15)/(_t19 * _t19 * _t19 * _t19) - 3.6239082623823843e-7*_t53/((_t11 * _t11 * _t11 * _t11)*xc_powi(_t5, 11));
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_vwn_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_aux_A0p0310907000000000_b13p0720000000000_c42p7198000000000_x0m0p409286000000000_k, _KMAX)(p, rs, _hc0);
  const double _t1 = M_CBRT2;
  const double _t2 = 0.2e1*_t1*(0.2e1*xc_expm1((0.4e1 / 0.3e1)*xc_log1p(-0.1e1 / 0.2e1)) + 0.1e1)/(0.2e1*_t1 - 0.2e1);

  const double f = -_hc0[0]*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_hc0[1]*_t2;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -_hc0[2]*_t2;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -_hc0[3]*_t2;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -_hc0[4]*_t2;
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = _t3/xc_powr(na, 1, 3);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_vwn_z0_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t4, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[0] - 0.1e1 / 0.6e1*_hc0[1]*_t4;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t6 = xc_powr(0.6e1, 2, 3);
  const double _t7 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t5 = _hc0[1]*_t3;
  const double d2F_dna2 = (0.1e1 / 0.36e2)*_hc0[2]*_t6*_t7/xc_powr(na, 5, 3) - 0.1e1 / 0.9e1*_t5/xc_powr(na, 4, 3);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t8 = _hc0[3]/M_PI;
  const double _t9 = _hc0[2]*_t6*_t7;
  const double d3F_dna3 = (0.4e1 / 0.27e2)*_hc0[1]*_t1*_t2/xc_powr(na, 7, 3) - 0.1e1 / 0.36e2*_t8/(na * na * na) - 0.1e1 / 0.36e2*_t9/xc_powr(na, 8, 3);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.216e3)*_hc0[4]*_t1/((M_PI * M_CBRTPI)*xc_powr(na, 13, 3)) - 0.28e2 / 0.81e2*_t5/xc_powr(na, 10, 3) + (0.1e1 / 0.9e1)*_t8/(na * na * na * na) + (0.4e1 / 0.81e2)*_t9/xc_powr(na, 11, 3);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = na - nb;
  const double _t7 = (0.1e1 / _t1);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_vwn_k, _KMAX)(p, _t5/xc_powr(_t1, 1, 3), _t6*_t7, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t9 = xc_powr(_t1, -4, 3);
  const double _t10 = (0.1e1 / 0.6e1)*_t9;
  const double _t12 = (0.1e1 / (_t1 * _t1));
  const double _t13 = _t12*_t6;
  const double _t14 = -_t13 + _t7;
  const double _t16 = -_t13 - _t7;
  const double _t8 = _hc0[2]*_t4;
  const double _t11 = -_t10*_t8;
  const double _t15 = _hc0[1]*_t14;
  const double _t17 = _hc0[1]*_t16;
  const double dF_dna = _hc0[0] + _t1*(_t11 + _t15);
  const double dF_dnb = _hc0[0] + _t1*(_t11 + _t17);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t18 = (0.1e1 / 0.3e1)*_t9;
  const double _t20 = xc_powr(_t1, -7, 3);
  const double _t21 = (0.2e1 / 0.9e1)*_t20;
  const double _t23 = 0.2e1*_t12;
  const double _t24 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t25 = 0.2e1*_t24;
  const double _t26 = _t25*_t6;
  const double _t27 = -_t23 + _t26;
  const double _t29 = _t10*_t4;
  const double _t40 = _t23 + _t26;
  const double _t19 = -_t18*_t8;
  const double _t22 = _t21*_t8;
  const double _t28 = _hc0[1]*_t27;
  const double _t30 = -_hc0[4]*_t29;
  const double _t31 = _hc0[3]*_t14 + _t30;
  const double _t32 = _t14*_t31;
  const double _t33 = -_hc0[5]*_t29;
  const double _t34 = _hc0[4]*_t14 + _t33;
  const double _t35 = _t28 - _t29*_t34 + _t32;
  const double _t36 = _hc0[3]*_t16 + _t30;
  const double _t37 = _t14*_t36;
  const double _t38 = _hc0[4]*_t16 + _t33;
  const double _t39 = _t22 - _t29*_t38;
  const double _t41 = _hc0[1]*_t40;
  const double _t42 = _t16*_t36;
  const double _t43 = _t41 + _t42;
  const double d2F_dna2 = _t1*(_t22 + _t35) + 0.2e1*_t15 + _t19;
  const double d2F_dna_dnb = _t1*(_hc0[1]*_t26 + _t37 + _t39) + _t15 + _t17 + _t19;
  const double d2F_dnb2 = _t1*(_t39 + _t43) + 0.2e1*_t17 + _t19;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t44 = (0.2e1 / 0.3e1)*_t20;
  const double _t46 = _t5*_t9;
  const double _t47 = xc_powr(_t1, -10, 3);
  const double _t48 = (0.14e2 / 0.27e2)*_t47;
  const double _t52 = (0.4e1 / 0.9e1)*_t20;
  const double _t54 = 0.6e1*_t24;
  const double _t55 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t56 = _t55*_t6;
  const double _t57 = 0.6e1*_t56;
  const double _t58 = _t54 - _t57;
  const double _t60 = _t21*_t4;
  const double _t68 = 0.2e1*_t27;
  const double _t74 = 0.2e1*_t24 - _t57;
  const double _t86 = 0.4e1*_t24;
  const double _t93 = -_t54 - _t57;
  const double _t45 = _t44*_t8;
  const double _t49 = _t48*_t8;
  const double _t50 = -_t49;
  const double _t51 = _t34*_t4;
  const double _t53 = _t51*_t52;
  const double _t59 = _hc0[1]*_t58;
  const double _t61 = _hc0[4]*_t60;
  const double _t62 = -_hc0[8]*_t29;
  const double _t63 = _hc0[7]*_t14 + _t62;
  const double _t64 = -_hc0[7]*_t29;
  const double _t65 = _hc0[6]*_t14 + _t64;
  const double _t66 = _hc0[3]*_t27 + _t14*_t65 - _t29*_t63 + _t61;
  const double _t67 = _t14*_t66;
  const double _t69 = _hc0[5]*_t60;
  const double _t70 = -_hc0[9]*_t29;
  const double _t71 = _hc0[8]*_t14 + _t70;
  const double _t72 = _hc0[4]*_t27 + _t14*_t63 - _t29*_t71 + _t69;
  const double _t73 = -_t29*_t72 + _t31*_t68 + _t59 + _t67;
  const double _t75 = _hc0[1]*_t74;
  const double _t76 = _t27*_t36;
  const double _t77 = _hc0[7]*_t16 + _t62;
  const double _t78 = _hc0[8]*_t16 + _t70;
  const double _t79 = -_t29*_t78 + _t69;
  const double _t80 = _hc0[4]*_t26 + _t14*_t77 + _t79;
  const double _t81 = _hc0[6]*_t16 + _t64;
  const double _t82 = -_t29*_t77 + _t61;
  const double _t83 = _hc0[3]*_t26 + _t14*_t81 + _t82;
  const double _t84 = _t14*_t83;
  const double _t85 = _t38*_t4;
  const double _t87 = _hc0[1]*_t86;
  const double _t88 = 0.2e1*_t37 + _t6*_t87;
  const double _t89 = _hc0[4]*_t40 + _t16*_t77 + _t79;
  const double _t90 = _t29*_t89;
  const double _t91 = _hc0[3]*_t40 + _t16*_t81 + _t82;
  const double _t92 = -_t38*_t46 + _t45;
  const double _t94 = _hc0[1]*_t93;
  const double _t95 = _t16*_t91;
  const double _t96 = 0.2e1*_t36;
  const double _t97 = _t40*_t96 + _t94 + _t95;
  const double d3F_dna3 = _t1*(_t50 + _t53 + _t73) + 0.3e1*_t28 + 0.3e1*_t32 - _t34*_t46 + _t45;
  const double d3F_dna2_dnb = _t1*(_t26*_t31 - _t29*_t80 + _t34*_t60 + _t38*_t60 + _t50 + _t75 + _t76 + _t84) - _t18*_t85 + _t35 + _t45 + _t88;
  const double d3F_dna_dnb2 = _t1*(-_hc0[1]*_t25 - _hc0[1]*_t57 + _t14*_t91 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t38 + 0.4e1*_t24*_t36*_t6 - _t49 - _t90) + _t43 + _t88 + _t92;
  const double d3F_dnb3 = _t1*(_t50 + _t52*_t85 - _t90 + _t97) + 0.3e1*_t41 + 0.3e1*_t42 + _t92;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t101 = (0.2e1 / 0.3e1)*_t9;
  const double _t103 = 0.24e2*_t55;
  const double _t104 = 0.24e2*_t6/xc_powi(_t1, 5);
  const double _t106 = _t4*_t48;
  const double _t109 = _t4*_t52;
  const double _t122 = 0.12e2*_t55;
  const double _t131 = _t54*_t6;
  const double _t133 = _t6*_t86;
  const double _t135 = _t24*_t6;
  const double _t137 = _t18*_t4;
  const double _t145 = 0.2e1*_t40;
  const double _t147 = 0.18e2*_t56;
  const double _t98 = -0.56e2 / 0.27e2*_t47*_t8;
  const double _t99 = _t20*_t51;
  const double _t100 = _t4*_t72;
  const double _t102 = (0.140e3 / 0.81e2)*_t8/xc_powr(_t1, 13, 3);
  const double _t105 = _t47*_t51;
  const double _t107 = _hc0[5]*_t106;
  const double _t108 = -_t107;
  const double _t110 = _hc0[9]*_t60;
  const double _t111 = -_hc0[14]*_t29;
  const double _t112 = -_hc0[13]*_t29;
  const double _t113 = _hc0[12]*_t14 + _t112;
  const double _t114 = _hc0[8]*_t60;
  const double _t115 = -_hc0[12]*_t29;
  const double _t116 = _hc0[11]*_t14 + _t115;
  const double _t117 = _hc0[7]*_t27 - _t113*_t29 + _t114 + _t116*_t14;
  const double _t118 = _hc0[4]*_t106;
  const double _t119 = -_t118;
  const double _t120 = _hc0[7]*_t60;
  const double _t121 = -_hc0[11]*_t29;
  const double _t123 = _hc0[11]*_t16 + _t115;
  const double _t124 = _hc0[12]*_t16 + _t112;
  const double _t125 = _t114 - _t124*_t29;
  const double _t126 = _hc0[7]*_t26 + _t123*_t14 + _t125;
  const double _t127 = _hc0[10]*_t16 + _t121;
  const double _t128 = _t120 - _t123*_t29;
  const double _t129 = _t110 - _t29*(_hc0[13]*_t16 + _t111);
  const double _t130 = _t102 + _t109*_t80;
  const double _t132 = _hc0[1]*_t122;
  const double _t134 = 0.8e1*_t36;
  const double _t136 = _t20*_t85;
  const double _t138 = _t14*_t91;
  const double _t139 = _hc0[1]*_t104;
  const double _t140 = _hc0[7]*_t40 + _t123*_t16 + _t125;
  const double _t141 = _t140*_t29;
  const double _t142 = _hc0[6]*_t40 + _t127*_t16 + _t128;
  const double _t143 = _t47*_t85;
  const double _t144 = _t29*(_hc0[8]*_t40 + _t124*_t16 + _t129);
  const double _t146 = _hc0[3]*_t93 + _t109*_t77 + _t119 - _t141 + _t142*_t16 + _t145*_t81;
  const double _t148 = _t4*_t89;
  const double _t149 = _t102 - 0.14e2 / 0.9e1*_t143 + _t148*_t44 - _t29*(_hc0[4]*_t93 + _t108 + _t109*_t78 + _t140*_t16 - _t144 + _t145*_t77);
  const double _t150 = -_t101*_t148 + (0.16e2 / 0.9e1)*_t136 + _t98;
  const double d4F_dna4 = _t1*(_hc0[1]*(-_t103 + _t104) + _t100*_t44 + _t102 - 0.14e2 / 0.9e1*_t105 + _t14*(_hc0[3]*_t58 + _t109*_t63 - _t117*_t29 + _t119 + _t14*(_hc0[6]*_t27 - _t116*_t29 + _t120 + _t14*(_hc0[10]*_t14 + _t121)) + _t65*_t68) + 0.3e1*_t27*_t66 - _t29*(_hc0[4]*_t58 + _t108 + _t109*_t71 + _t117*_t14 - _t29*(_hc0[8]*_t27 + _t110 + _t113*_t14 - _t29*(_hc0[13]*_t14 + _t111)) + _t63*_t68) + 0.3e1*_t31*_t58) - _t100*_t101 + 0.8e1*_t27*_t31 + 0.4e1*_t59 + 0.4e1*_t67 + _t98 + (0.16e2 / 0.9e1)*_t99;
  const double d4F_dna3_dnb = _t1*(_hc0[1]*(_t104 - _t122) - 0.28e2 / 0.27e2*_t105 + _t130 + _t14*(_hc0[3]*_t74 + _t119 - _t126*_t29 + _t14*(_hc0[6]*_t26 + _t127*_t14 + _t128) + _t26*_t65 + _t27*_t81 + _t60*_t63 + _t60*_t77) + _t26*_t66 - _t29*(_hc0[4]*_t74 + _t108 + _t126*_t14 + _t26*_t63 + _t27*_t77 - _t29*(_hc0[8]*_t26 + _t124*_t14 + _t129) + _t60*_t71 + _t60*_t78) + 0.2e1*_t31*_t74 + _t36*_t58 - _t48*_t85 + _t60*_t72 + _t68*_t83) + _t131*_t31 + _t44*_t85 - _t46*_t80 + _t73 + 0.3e1*_t75 + 0.3e1*_t76 + 0.3e1*_t84 + _t98 + (0.10e2 / 0.9e1)*_t99;
  const double d4F_dna2_dnb2 = _t1*(_t130 + _t133*_t83 + _t139 + _t14*(-_hc0[3]*_t25 - _hc0[3]*_t57 - _t118 + _t14*_t142 - _t141 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t77 + 0.4e1*_t24*_t6*_t81) - 0.28e2 / 0.27e2*_t143 - _t25*_t31 + _t27*_t91 - _t29*(-_hc0[4]*_t25 - _hc0[4]*_t57 - _t107 + _t14*_t140 - _t144 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t78 + 0.4e1*_t24*_t6*_t77) - _t31*_t57 - _t48*_t51 + _t60*_t89 + _t74*_t96) - _t132*_t6 + _t133*_t31 + _t134*_t135 + (0.4e1 / 0.3e1)*_t136 - _t137*_t80 - _t137*_t89 + 0.2e1*_t138 + _t53 + 0.2e1*_t75 + 0.2e1*_t76 + 0.2e1*_t84 - _t87 + _t98;
  const double d4F_dna_dnb3 = -_hc0[1]*_t147 - _hc0[1]*_t54 + _t1*(_t131*_t91 + _t132 + _t139 + _t14*_t146 - _t147*_t36 + _t149 - _t36*_t54) + 0.12e2*_t135*_t36 + 0.3e1*_t138 + _t150 + _t97;
  const double d4F_dnb4 = _t1*(_hc0[1]*(_t103 + _t104) + _t146*_t16 + _t149 + 0.3e1*_t36*_t93 + 0.3e1*_t40*_t91) + _t134*_t40 + _t150 + 0.4e1*_t94 + 0.4e1*_t95;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif