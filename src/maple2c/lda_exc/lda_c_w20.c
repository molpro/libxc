/*
  Generated from python/lda_exc/lda_c_w20.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_w20
*/

#ifndef _LDA_C_W20_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_W20_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_W20_HELPER_BODIES
#include "lda_c_w20.c"
#undef _LDA_C_W20_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_W20_HELPER_BODIES
#include "lda_c_w20.c"
#undef _LDA_C_W20_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_W20_HELPER_BODIES
#include "lda_c_w20.c"
#undef _LDA_C_W20_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_W20_HELPER_BODIES
#include "lda_c_w20.c"
#undef _LDA_C_W20_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_W20_HELPER_BODIES
#include "lda_c_w20.c"
#undef _LDA_C_W20_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_w20.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_W20_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_a0_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (0.1e1 - M_LN2)/(M_PI * M_PI);

  const double f = my_piecewise3(z == 0, _t1, (0.1e1 / 0.2e1)*_t1);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_a1_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (0.1e1 / (M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t2 = 0.12e2*M_LN2;
  const double _t3 = (M_PI * M_PI);

  const double f = my_piecewise3(z == 0, (0.1e1 / 0.12e2)*xc_powr(0.2e1, 2, 3)*M_CBRT3*_t1*(-_t2 + (0.7e1 / 0.6e1)*_t3 - 0.1e1), (0.1e1 / 0.24e2)*xc_powr(0.6e1, 1, 3)*_t1*(-_t2 + (0.13e2 / 0.12e2)*_t3 + 0.1e1 / 0.2e1));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_b0_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = -0.1e1 / 0.6e1*M_LN2 + 0.90154267736969573/(M_PI * M_PI);

  const double f = my_piecewise3(z == 0, -_t1 - 0.071099999999999997, -_t1 - 0.049917000000000003);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_b1_k, _KMAX)(const xc_func_type *p, double z, double *out) {


  const double f = my_piecewise3(z == 0, -0.01, 0);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_cs_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.5e1 / 0.3e1, _hc1);
  const double _t1 = (0.9e1 / 0.80e2)*xc_powr(0.2e1, 2, 3)*M_CBRT3*(M_CBRTPI * M_CBRTPI);

  const double f = _t1*(_hc0[0] + _hc1[0] + 0.2e1);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t1*(_hc0[2] - _hc1[2]);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t1*(_hc0[5] + _hc1[5]);
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t1*(_hc0[9] - _hc1[9]);
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t1*(_hc0[14] + _hc1[14]);
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_cx_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, -z, _hc1);
  const double _t1 = (0.3e1 / 0.16e2)*M_CBRT2*xc_powr(0.3e1, 2, 3)/(M_CBRTPI * M_CBRTPI);

  const double f = -_t1*(_hc0[0] + _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_t1*(_hc0[1] - _hc1[1]);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -_t1*(_hc0[2] + _hc1[2]);
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_t1*(_hc0[3] - _hc1[3]);
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = -_t1*(_hc0[4] + _hc1[4]);
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_DF_k, _KMAX)(const xc_func_type *p, double rs, double z, double cfterm, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_a0_k, _KMAX)(p, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_b0_k, _KMAX)(p, z, _hc1);
  const double _t1 = (rs * rs);
  const double _t2 = (0.1e1 / 0.10000e5)*_t1;
  const double _t3 = xc_expm1(-_t2);
  const double _t4 = (0.1e1 / (_hc0[0]));
  const double _t5 = 0.2e1*_t4;
  const double _t6 = _t3*_t5;
  const double _t7 = exp(-_hc1[0]*_t5 - _t2);
#if _KMAX >= 1
  const double _t8 = _t3 + 0.1e1;
  const double _t9 = _t4*_t8;
  const double _t10 = (0.1e1 / 0.2500e4)*_t9;
  const double _t11 = _t10*rs;
  const double _t12 = (0.1e1 / 0.5000e4)*_t7;
#endif
#if _KMAX >= 2
  const double _t13 = _t1*_t9;
  const double _t14 = (0.1e1 / 0.12500000e8)*_t13;
  const double _t15 = _t1*_t7;
#endif
#if _KMAX >= 3
  const double _t16 = (rs * rs * rs);
  const double _t17 = (0.1e1 / 0.62500000000e11)*_t16*_t9;
#endif
#if _KMAX >= 4
  const double _t18 = (rs * rs * rs * rs);
#endif

  const double f = _t6*cfterm + _t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dcfterm = _t6;
  out[1] = df_dcfterm;
  const double df_dz = 0;
  out[2] = df_dz;
  const double df_drs = -_t11*cfterm - _t12*rs;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dcfterm2 = 0;
  out[4] = d2f_dcfterm2;
  const double d2f_dz_dcfterm = 0;
  out[5] = d2f_dz_dcfterm;
  const double d2f_dz2 = 0;
  out[6] = d2f_dz2;
  const double d2f_drs_dcfterm = -_t11;
  out[7] = d2f_drs_dcfterm;
  const double d2f_drs_dz = 0;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = -_t10*cfterm - _t12 + _t14*cfterm + (0.1e1 / 0.25000000e8)*_t15;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dcfterm3 = 0;
  out[10] = d3f_dcfterm3;
  const double d3f_dz_dcfterm2 = 0;
  out[11] = d3f_dz_dcfterm2;
  const double d3f_dz2_dcfterm = 0;
  out[12] = d3f_dz2_dcfterm;
  const double d3f_dz3 = 0;
  out[13] = d3f_dz3;
  const double d3f_drs_dcfterm2 = 0;
  out[14] = d3f_drs_dcfterm2;
  const double d3f_drs_dz_dcfterm = 0;
  out[15] = d3f_drs_dz_dcfterm;
  const double d3f_drs_dz2 = 0;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dcfterm = -_t10 + _t14;
  out[17] = d3f_drs2_dcfterm;
  const double d3f_drs2_dz = 0;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = -0.1e1 / 0.125000000000e12*_t16*_t7 - _t17*cfterm + (0.3e1 / 0.12500000e8)*_t4*_t8*cfterm*rs + (0.3e1 / 0.25000000e8)*_t7*rs;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dcfterm4 = 0;
  out[20] = d4f_dcfterm4;
  const double d4f_dz_dcfterm3 = 0;
  out[21] = d4f_dz_dcfterm3;
  const double d4f_dz2_dcfterm2 = 0;
  out[22] = d4f_dz2_dcfterm2;
  const double d4f_dz3_dcfterm = 0;
  out[23] = d4f_dz3_dcfterm;
  const double d4f_dz4 = 0;
  out[24] = d4f_dz4;
  const double d4f_drs_dcfterm3 = 0;
  out[25] = d4f_drs_dcfterm3;
  const double d4f_drs_dz_dcfterm2 = 0;
  out[26] = d4f_drs_dz_dcfterm2;
  const double d4f_drs_dz2_dcfterm = 0;
  out[27] = d4f_drs_dz2_dcfterm;
  const double d4f_drs_dz3 = 0;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dcfterm2 = 0;
  out[29] = d4f_drs2_dcfterm2;
  const double d4f_drs2_dz_dcfterm = 0;
  out[30] = d4f_drs2_dz_dcfterm;
  const double d4f_drs2_dz2 = 0;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dcfterm = -_t17 + (0.3e1 / 0.12500000e8)*_t4*_t8*rs;
  out[32] = d4f_drs3_dcfterm;
  const double d4f_drs3_dz = 0;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = -0.3e1 / 0.31250000000e11*_t13*cfterm - 0.3e1 / 0.62500000000e11*_t15 + (0.1e1 / 0.625000000000000e15)*_t18*_t7 + (0.1e1 / 0.312500000000000e15)*_t18*_t9*cfterm + (0.3e1 / 0.25000000e8)*_t7 + (0.3e1 / 0.12500000e8)*_t9*cfterm;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_E_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_a0_k, _KMAX)(p, z, _hc0);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = (rs * rs);
  const double _t3 = xc_expm1(-0.1e1 / 0.10000e5*_t2);
#if _KMAX >= 1
  const double _t4 = _t3 + 0.1e1;
  const double _t5 = _t1*_t4;
  const double _t6 = 0.00060000000000000006*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = _t2*_t5;
#endif

  const double f = 3.0*_t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
  const double df_drs = -_t6*rs;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = 0;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -_t6 + 1.2000000000000002e-7*_t7;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = 0;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = 0;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = 3.6000000000000005e-7*_t1*_t4*rs - 2.4000000000000004e-11*_t5*(rs * rs * rs);
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = 0;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = 0;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = 0;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 4.8000000000000015e-15*_t5*(rs * rs * rs * rs) + 3.6000000000000005e-7*_t5 - 1.4400000000000002e-10*_t7;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_G_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_a1_k, _KMAX)(p, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_b1_k, _KMAX)(p, z, _hc1);
  const double _t1 = (rs * rs);
  const double _t2 = exp(-0.1e1 / 0.10000e5*_t1);
  const double _t3 = _t2 + 0.10e2*xc_powr(rs, 5, 4);
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = (0.1e1 / rs);
  const double _t6 = -_hc0[0]*xc_log1p(_t5) + _hc1[0];
  const double _t7 = _t4*_t6;
  const double _t8 = _t2*_t7;
  const double _t9 = _t8*rs;
#if _KMAX >= 1
  const double _t10 = _t5 + 0.1e1;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = _hc0[0]*_t4;
  const double _t13 = _t11*_t12;
  const double _t14 = _t13*_t2;
  const double _t15 = _t2*rs;
  const double _t16 = xc_powr(rs, 1, 4);
  const double _t17 = -0.25e2 / 0.2e1*_t16 + (0.1e1 / 0.5000e4)*_t2*rs;
  const double _t18 = (0.1e1 / (_t3 * _t3));
  const double _t19 = _t18*_t6;
  const double _t20 = _t17*_t19;
  const double _t21 = _t15*_t20;
#endif
#if _KMAX >= 2
  const double _t22 = (0.1e1 / 0.2500e4)*_t2;
  const double _t23 = (0.3e1 / 0.5000e4)*_t2;
  const double _t24 = (rs * rs * rs);
  const double _t25 = (0.1e1 / _t24);
  const double _t26 = (0.1e1 / (_t10 * _t10));
  const double _t27 = _t12*_t2;
  const double _t28 = _t26*_t27;
  const double _t29 = _t25*_t28;
  const double _t30 = _t24*_t8;
  const double _t31 = _t2*_t20;
  const double _t32 = _hc0[0]*_t18;
  const double _t33 = _t11*_t32;
  const double _t34 = _t17*_t2;
  const double _t35 = _t33*_t34;
  const double _t36 = _t35*_t5;
  const double _t37 = xc_powr(rs, -3, 4);
  const double _t38 = _t1*_t2;
  const double _t39 = (0.1e1 / 0.5000e4)*_t2 - 0.25e2 / 0.8e1*_t37 - 0.1e1 / 0.25000000e8*_t38;
  const double _t40 = _t19*_t39;
  const double _t41 = _t15*_t40;
  const double _t42 = _t15*_t17;
  const double _t43 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t44 = -0.25e2*_t16 + (0.1e1 / 0.2500e4)*_t2*rs;
  const double _t45 = _t43*_t44;
  const double _t46 = _t45*_t6;
  const double _t47 = _t42*_t46;
#endif
#if _KMAX >= 3
  const double _t48 = (0.3e1 / 0.25000000e8)*_t2;
  const double _t49 = _t48*rs;
  const double _t50 = xc_powi(rs, 5);
  const double _t51 = (0.1e1 / _t50);
  const double _t52 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t53 = _t27*_t52;
  const double _t54 = (rs * rs * rs * rs);
  const double _t55 = (0.1e1 / _t54);
  const double _t56 = _t26/_t1;
  const double _t57 = 0.3e1*_t2;
  const double _t58 = _t17*_t57;
  const double _t59 = _t26*_t32;
  const double _t60 = _t25*_t59;
  const double _t61 = xc_powr(rs, -7, 4);
  const double _t62 = _t2*_t24;
  const double _t63 = -_t49 + (0.75e2 / 0.32e2)*_t61 + (0.1e1 / 0.125000000000e12)*_t62;
  const double _t64 = _t19*_t63;
  const double _t65 = _t33*_t5;
  const double _t66 = _t1*_t23;
  const double _t67 = _hc0[0]*_t11;
  const double _t68 = _t45*_t67;
  const double _t69 = _t5*_t68;
  const double _t70 = _t17*_t46;
  const double _t71 = _t42*_t6;
  const double _t72 = (0.1e1 / 0.2500e4)*_t2 - 0.25e2 / 0.4e1*_t37 - 0.1e1 / 0.12500000e8*_t38;
  const double _t73 = _t43*_t72;
  const double _t74 = _t15*_t46;
  const double _t75 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t76 = -0.75e2 / 0.2e1*_t16 + (0.3e1 / 0.5000e4)*_t2*rs;
  const double _t77 = _t44*_t75*_t76;
#endif
#if _KMAX >= 4
  const double _t78 = _t32*_t34;
  const double _t79 = _t2*_t54;
  const double _t80 = _t2*_t39;
  const double _t81 = 0.4e1*_t2;
  const double _t82 = (0.3e1 / 0.12500000e8)*_t62;
  const double _t83 = (0.1e1 / 0.1250e4)*_t38;
  const double _t84 = 0.8e1*_t80;
  const double _t85 = _t6*_t73;
  const double _t86 = _t17*_t81;
  const double _t87 = _t5*_t67*_t86;
  const double _t88 = _t17*_t83;
  const double _t89 = _t6*_t77;
  const double _t90 = 0.3e1*_t15*_t39;
  const double _t91 = _t71*_t75;
#endif

  const double f = _t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
  const double df_drs = -0.1e1 / 0.5000e4*_t1*_t2*_t7 + _t14*_t5 + _t21 + _t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = 0;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -_t1*_t20*_t22 - _t13*_t22 - _t23*_t7*rs + _t29 + (0.1e1 / 0.25000000e8)*_t30 + 0.2e1*_t31 + 0.2e1*_t36 + _t41 + _t47;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = 0;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = 0;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = (0.3e1 / 0.12500000e8)*_t1*_t8 - _t12*_t23*_t56 - _t13*_t23*_t5 + _t13*_t49 + _t15*_t64 + _t20*_t24*_t48 - 0.9e1 / 0.5000e4*_t21 - _t23*_t7 - 0.3e1*_t28*_t55 - 0.3e1 / 0.2500e4*_t35 + _t39*_t57*_t65 + 0.2e1*_t39*_t74 + _t40*_t57 - _t40*_t66 + _t46*_t58 + 0.2e1*_t51*_t53 - 0.1e1 / 0.125000000000e12*_t54*_t8 + _t58*_t60 + _t58*_t69 - _t66*_t70 + _t71*_t73 + _t71*_t77;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = 0;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = 0;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = 0;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.6e1*_hc0[0]*_t25*_t26*_t34*_t45 - 0.1e1 / 0.31250000000e11*_t13*_t38 + (0.3e1 / 0.6250000e7)*_t14 + _t15*_t19*((0.3e1 / 0.62500000000e11)*_t1*_t2 - _t48 - 0.1e1 / 0.625000000000000e15*_t79 - (0.525e3 / 0.128e3)/xc_powr(rs, 11, 4)) + (0.3e1 / 0.3125000e7)*_t20*_t38 - 0.1e1 / 0.31250000000e11*_t20*_t79 + (0.3e1 / 0.12500000e8)*_t28*_t5 + 0.12e2*_t28*_t51 + (0.3e1 / 0.2500e4)*_t29 - 0.1e1 / 0.12500000000e11*_t30 - 0.3e1 / 0.1250e4*_t31 + (0.3e1 / 0.6250000e7)*_t33*_t42 - 0.3e1 / 0.1250e4*_t33*_t80 - 0.12e2*_t34*_t55*_t59 - 0.3e1 / 0.1250e4*_t34*_t68 - 0.3e1 / 0.1250e4*_t36 - 0.1e1 / 0.625e3*_t38*_t39*_t46 + _t40*_t82 - 0.9e1 / 0.2500e4*_t41 + _t43*_t71*(-0.3e1 / 0.12500000e8*_t15 + (0.75e2 / 0.16e2)*_t61 + (0.1e1 / 0.62500000000e11)*_t62) + _t44*_t91*(-_t1*_t48 + (0.3e1 / 0.5000e4)*_t2 - 0.75e2 / 0.8e1*_t37) + _t46*_t84 - 0.9e1 / 0.2500e4*_t47 + (0.1e1 / 0.625000000000000e15)*_t50*_t8 + 0.8e1*_t51*_t52*_t78 - 0.1e1 / 0.625e3*_t53*_t55 - 0.16e2*_t53/xc_powi(rs, 6) - 0.3e1 / 0.1250e4*_t56*_t78 + 0.6e1*_t60*_t80 + _t63*_t65*_t81 + 0.3e1*_t63*_t74 + _t64*_t81 - _t64*_t83 + _t69*_t84 + _t70*_t82 + 0.2e1*_t72*_t76*_t91 + _t73*_t87 + _t77*_t87 + _t85*_t86 - _t85*_t88 + _t85*_t90 + _t86*_t89 - _t88*_t89 + _t89*_t90 + (0.3e1 / 0.5000000e7)*_t9 + _t44*_t71*_t76*(-0.50e2*_t16 + (0.1e1 / 0.1250e4)*_t2*rs)/xc_powi(_t3, 5) + 0.6e1*_t27/((_t10 * _t10 * _t10 * _t10)*xc_powi(rs, 7));
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_ec_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_a0_k, _KMAX)(p, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_cx_k, _KMAX)(p, z, _hc1);
  double _hc2[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(w20_DF_k, _KMAX)(p, rs, z, -_hc1[0] - 0.90000000000000002, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_cs_k, _KMAX)(p, z, _hc3);
  double _hc4[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(w20_DF_k, _KMAX)(p, rs, z, -_hc3[0], _hc4);
  double _hc5[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(w20_E_k, _KMAX)(p, rs, z, _hc5);
  double _hc6[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(w20_G_k, _KMAX)(p, rs, z, _hc6);
  const double _t1 = (0.1e1 / rs);
  const double _t2 = (0.1e1 / (rs * rs));
  const double _t3 = xc_powr(rs, -3, 2);
  const double _t4 = _hc2[0]*_t1 + _hc4[0]*_t2 + _hc5[0]*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_hc0[0];
#if _KMAX >= 1
  const double _t6 = _hc5[1]*_t3;
  const double _t7 = -_hc3[1]*_hc4[1] + _hc4[2];
  const double _t8 = _t2*_t7;
  const double _t9 = -_hc1[1]*_hc2[1] + _hc2[2];
  const double _t10 = _t1*_t9;
  const double _t11 = _t10 + _t6 + _t8;
  const double _t12 = _t4 + 0.1e1;
  const double _t13 = _t5/_t12;
  const double _t14 = _hc2[0]*_t2;
  const double _t15 = (0.1e1 / (rs * rs * rs));
  const double _t16 = 0.2e1*_t15;
  const double _t17 = xc_powr(rs, -5, 2);
  const double _t18 = (0.3e1 / 0.2e1)*_t17;
  const double _t19 = -_hc2[3]*_t1 + _hc4[0]*_t16 - _hc4[3]*_t2 + _hc5[0]*_t18 - _hc5[2]*_t3 + _t14;
  const double _t20 = -_t19;
#endif
#if _KMAX >= 2
  const double _t21 = _hc5[3]*_t3;
  const double _t22 = 0.2e1*_hc3[1];
  const double _t23 = -_hc3[2]*_hc4[1] - _hc4[5]*_t22 + _hc4[6];
  const double _t24 = _t2*_t23;
  const double _t25 = 0.2e1*_hc1[1];
  const double _t26 = -_hc1[2]*_hc2[1] - _hc2[5]*_t25 + _hc2[6];
  const double _t27 = _t1*_t26;
  const double _t28 = _t21 + _t24 + _t27;
  const double _t29 = -_t11;
  const double _t30 = (0.1e1 / (_t12 * _t12));
  const double _t31 = _t30*_t5;
  const double _t32 = _t29*_t31;
  const double _t33 = _t2*_t9;
  const double _t34 = -_hc3[1]*_hc4[7] + _hc4[8];
  const double _t35 = -_hc1[1]*_hc2[7] + _hc2[8];
  const double _t36 = _hc5[1]*_t18 - _hc5[4]*_t3 - _t1*_t35 + _t16*_t7 - _t2*_t34 + _t33;
  const double _t37 = -_t36;
  const double _t38 = _hc2[9]*_t1;
  const double _t39 = _hc4[9]*_t2;
  const double _t40 = _hc5[5]*_t3;
  const double _t41 = 0.2e1*_t2;
  const double _t42 = (0.1e1 / (rs * rs * rs * rs));
  const double _t43 = 0.6e1*_t42;
  const double _t44 = 0.4e1*_t15;
  const double _t45 = xc_powr(rs, -7, 2);
  const double _t46 = (0.15e2 / 0.4e1)*_t45;
  const double _t47 = 0.3e1*_t17;
  const double _t48 = _hc2[0]*_t16 - _hc2[3]*_t41 + _hc4[0]*_t43 - _hc4[3]*_t44 + _hc5[0]*_t46 - _hc5[2]*_t47 + _t38 + _t39 + _t40;
  const double _t49 = _t20*_t31;
#endif
#if _KMAX >= 3
  const double _t50 = 0.3e1*_hc3[1];
  const double _t51 = 0.3e1*_hc3[2];
  const double _t52 = -_hc3[3]*_hc4[1] - _hc4[12]*_t50 + _hc4[13] - _hc4[5]*_t51;
  const double _t53 = 0.3e1*_hc1[1];
  const double _t54 = 0.3e1*_hc1[2];
  const double _t55 = -_hc1[3]*_hc2[1] - _hc2[12]*_t53 + _hc2[13] - _hc2[5]*_t54;
  const double _t56 = _hc5[6]*_t3 + _t1*_t55 + _t2*_t52;
  const double _t57 = _hc0[0]*_t30;
  const double _t58 = _t29*_t57;
  const double _t59 = -_t28;
  const double _t60 = _t11*_t31;
  const double _t61 = -0.2e1*_t10 - 0.2e1*_t6 - 0.2e1*_t8;
  const double _t62 = _t11*_t61;
  const double _t63 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t64 = _t5*_t63;
  const double _t65 = _t29*_t64;
  const double _t66 = -_hc3[2]*_hc4[7] - _hc4[15]*_t22 + _hc4[16];
  const double _t67 = -_hc1[2]*_hc2[7] - _hc2[15]*_t25 + _hc2[16];
  const double _t68 = _hc5[3]*_t18 - _hc5[7]*_t3 - _t1*_t67 + _t16*_t23 + _t2*_t26 - _t2*_t66;
  const double _t69 = -_t68;
  const double _t70 = _t20*_t61;
  const double _t71 = -_hc3[1]*_hc4[17] + _hc4[18];
  const double _t72 = -_hc1[1]*_hc2[17] + _hc2[18];
  const double _t73 = _hc5[1]*_t46 - _hc5[4]*_t47 + _hc5[8]*_t3 + _t1*_t72 + _t16*_t9 + _t2*_t71 - _t34*_t44 - _t35*_t41 + _t43*_t7;
  const double _t74 = _t19*_t31;
  const double _t75 = _t19*_t64;
  const double _t76 = 0.3e1*_t2;
  const double _t77 = xc_powi(rs, -5);
  const double _t78 = 0.24e2*_t77;
  const double _t79 = 0.6e1*_t15;
  const double _t80 = xc_powr(rs, -9, 2);
  const double _t81 = (0.105e3 / 0.8e1)*_t80;
  const double _t82 = (0.9e1 / 0.2e1)*_t17;
  const double _t83 = _hc2[0]*_t43 - _hc2[19]*_t1 - 0.6e1*_hc2[3]*_t15 + _hc2[9]*_t76 + _hc4[0]*_t78 - _hc4[19]*_t2 - 0.18e2*_hc4[3]*_t42 + _hc4[9]*_t79 + _hc5[0]*_t81 - 0.45e2 / 0.4e1*_hc5[2]*_t45 + _hc5[5]*_t82 - _hc5[9]*_t3;
  const double _t84 = -_t83;
  const double _t85 = _t19*_t57;
  const double _t86 = -_t48;
  const double _t87 = _hc2[3]*_t1;
  const double _t88 = _hc4[3]*_t2;
  const double _t89 = _hc5[2]*_t3;
  const double _t90 = _hc4[0]*_t44 + _hc5[0]*_t47 + 0.2e1*_t14 - 0.2e1*_t87 - 0.2e1*_t88 - 0.2e1*_t89;
  const double _t91 = _t20*_t90;
#endif
#if _KMAX >= 4
  const double _t92 = (0.3e1 / 0.2e1)*_t58;
  const double _t93 = -_t56;
  const double _t94 = (0.3e1 / 0.2e1)*_t57;
  const double _t95 = _t59*_t94;
  const double _t96 = _hc0[0]*_t63;
  const double _t97 = _t59*_t96;
  const double _t98 = _t61*_t96;
  const double _t99 = (0.3e1 / 0.2e1)*_t29*_t98;
  const double _t100 = -0.2e1*_t21 - 0.2e1*_t24 - 0.2e1*_t27;
  const double _t101 = _t100*_t65;
  const double _t102 = _t5/(_t12 * _t12 * _t12 * _t12);
  const double _t103 = _t102*(-0.3e1*_t10 - 0.3e1*_t6 - 0.3e1*_t8);
  const double _t104 = _t103*_t29;
  const double _t105 = _t20*_t75;
  const double _t106 = _t36*_t57;
  const double _t107 = _t19*_t37;
  const double _t108 = _t103*_t19;
  const double _t109 = _t19*_t48;
#endif

  const double f = _hc6[0] - _t5*xc_log1p(_t4);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc6[1] - _t11*_t13;
  out[1] = df_dz;
  const double df_drs = _hc6[2] - _t13*_t20;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc6[3] - _t11*_t32 - _t13*_t28;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc6[4] - _t13*_t37 - _t20*_t32;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc6[5] - _t13*_t48 - _t19*_t49;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc6[6] - _t13*_t56 - _t28*_t58 - _t59*_t60 - _t62*_t65;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc6[7] - _t13*_t69 - _t37*_t58 - _t49*_t59 - _t65*_t70;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc6[8] - _t13*_t73 - _t32*_t48 - _t36*_t49 - _t37*_t74 - _t70*_t75;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc6[9] - _t13*_t84 - _t48*_t85 - _t49*_t86 - _t75*_t91;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc6[10] - _t101*_t11 - _t104*_t62 - _t13*(_hc5[10]*_t3 + _t1*(-0.4e1*_hc1[1]*_hc2[23] - 0.6e1*_hc1[2]*_hc2[12] - 0.4e1*_hc1[3]*_hc2[5] - _hc1[4]*_hc2[1] + _hc2[24]) + _t2*(-0.4e1*_hc3[1]*_hc4[23] - 0.6e1*_hc3[2]*_hc4[12] - 0.4e1*_hc3[3]*_hc4[5] - _hc3[4]*_hc4[1] + _hc4[24])) - _t28*_t95 - _t28*_t99 - _t56*_t92 - _t60*_t93 - _t62*_t97;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc6[11] - _t101*_t20 - _t104*_t70 - _t13*(_hc5[11]*_t3 - _hc5[6]*_t18 + _t1*(-_hc1[3]*_hc2[7] - _hc2[15]*_t54 - _hc2[27]*_t53 + _hc2[28]) - _t16*_t52 - _t2*_t55 + _t2*(-_hc3[3]*_hc4[7] - _hc4[15]*_t51 - _hc4[27]*_t50 + _hc4[28])) - _t37*_t95 - _t37*_t99 - _t49*_t93 - _t69*_t92 - _t70*_t97;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc6[12] - _t100*_t105 - _t106*_t37 - _t107*_t98 - _t108*_t70 - _t13*(_hc5[12]*_t3 + _hc5[3]*_t46 - _hc5[7]*_t47 + _t1*(-_hc1[2]*_hc2[17] - _hc2[30]*_t25 + _hc2[31]) + _t16*_t26 + _t2*(-_hc3[2]*_hc4[17] - _hc4[30]*_t22 + _hc4[31]) + _t23*_t43 - _t41*_t67 - _t44*_t66) - _t31*_t48*_t59 - _t36*_t70*_t96 - _t48*_t61*_t65 - _t49*_t68 - _t58*_t73 - _t69*_t74;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc6[13] - _t105*(_hc5[1]*_t47 - 0.2e1*_hc5[4]*_t3 - 0.2e1*_t1*_t35 - 0.2e1*_t2*_t34 + 0.2e1*_t33 + _t44*_t7) - _t106*_t48 - _t107*_t64*_t90 - _t108*_t91 - _t109*_t98 - _t13*(-_hc5[1]*_t81 + _hc5[13]*_t3 + (0.45e2 / 0.4e1)*_hc5[4]*_t45 - _hc5[8]*_t82 + _t1*(-_hc1[1]*_hc2[32] + _hc2[33]) + 0.6e1*_t15*_t35 + _t2*(-_hc3[1]*_hc4[32] + _hc4[33]) + 0.18e2*_t34*_t42 - _t43*_t9 - _t7*_t78 - _t71*_t79 - _t72*_t76) - _t31*_t37*_t86 - _t32*_t84 - _t36*_t64*_t91 + _t49*_t73 - _t64*_t70*_t86 - _t73*_t85;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = _hc6[14] - _t102*_t19*_t91*(_hc4[0]*_t79 + _hc5[0]*_t82 + 0.3e1*_t14 - 0.3e1*_t87 - 0.3e1*_t88 - 0.3e1*_t89) - _t105*(-_hc2[0]*_t44 + 0.4e1*_hc2[3]*_t2 - 0.12e2*_hc4[0]*_t42 + 0.8e1*_hc4[3]*_t15 - 0.15e2 / 0.2e1*_hc5[0]*_t45 + 0.6e1*_hc5[2]*_t17 - 0.2e1*_t38 - 0.2e1*_t39 - 0.2e1*_t40) - 0.3e1 / 0.2e1*_t109*_t90*_t96 - _t13*(_hc2[0]*_t78 - 0.4e1*_hc2[19]*_t2 - 0.24e2*_hc2[3]*_t42 + _hc2[34]*_t1 + 0.12e2*_hc2[9]*_t15 + 0.120e3*_hc4[0]/xc_powi(rs, 6) - 0.8e1*_hc4[19]*_t15 - 0.96e2*_hc4[3]*_t77 + _hc4[34]*_t2 + 0.36e2*_hc4[9]*_t42 + (0.945e3 / 0.16e2)*_hc5[0]/xc_powr(rs, 11, 2) + _hc5[14]*_t3 - 0.105e3 / 0.2e1*_hc5[2]*_t80 + (0.45e2 / 0.2e1)*_hc5[5]*_t45 - 0.6e1*_hc5[9]*_t17) - _t48*_t86*_t94 - _t49*_t83 - 0.3e1 / 0.2e1*_t84*_t85 - _t86*_t91*_t96;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_w20_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(w20_ec_k, _KMAX)(p, rs, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(w20_ec_k, _KMAX)(p, rs, 0.1e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc2);
  const double _t1 = -_hc0[0] + _hc1[0];
#if _KMAX >= 1
  const double _t2 = -_hc0[2] + _hc1[2];
#endif
#if _KMAX >= 2
  const double _t3 = -_hc0[5] + _hc1[5];
#endif
#if _KMAX >= 3
  const double _t4 = -_hc0[9] + _hc1[9];
#endif

  const double f = _hc0[0] + _hc2[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = _hc2[1]*_t1;
  out[1] = df_dzeta;
  const double df_drs = _hc0[2] + _hc2[0]*_t2;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = _hc2[2]*_t1;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc2[1]*_t2;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[5] + _hc2[0]*_t3;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = _hc2[3]*_t1;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc2[2]*_t2;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc2[1]*_t3;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = _hc0[9] + _hc2[0]*_t4;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = _hc2[4]*_t1;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = _hc2[3]*_t2;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = _hc2[2]*_t3;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = _hc2[1]*_t4;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = _hc0[14] + _hc2[0]*(-_hc0[14] + _hc1[14]);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_DF_z0_cftermm0p9___3_2___1_3__3___2_3___8_pi___2_3___k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (0.1e1 / 0.10000e5)*_t1;
  const double _t3 = M_LN2;
  const double _t4 = (M_PI * M_PI);
  const double _t5 = (0.1e1 / (0.1e1 - _t3));
  const double _t6 = _t4*_t5;
  const double _t7 = 0.2e1*_t6;
  const double _t8 = exp(-_t2 - _t7*((0.1e1 / 0.6e1)*_t3 - 0.071099999999999997 - 0.90154267736969573/_t4));
  const double _t9 = -0.90000000000000002 + (0.3e1 / 0.8e1)*M_CBRT2*xc_powr(0.3e1, 2, 3)/(M_CBRTPI * M_CBRTPI);
  const double _t10 = xc_expm1(-_t2);
#if _KMAX >= 1
  const double _t11 = (0.1e1 / 0.5000e4)*_t8;
  const double _t12 = _t10 + 0.1e1;
  const double _t13 = _t12*_t6*_t9;
  const double _t14 = (0.1e1 / 0.2500e4)*_t13;
#endif
#if _KMAX >= 2
  const double _t15 = _t1*_t8;
  const double _t16 = _t1*_t13;
#endif
#if _KMAX >= 3
  const double _t17 = (rs * rs * rs);
#endif
#if _KMAX >= 4
  const double _t18 = (rs * rs * rs * rs);
#endif

  const double f = _t10*_t7*_t9 + _t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t11*rs - _t14*rs;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -_t11 - _t14 + (0.1e1 / 0.25000000e8)*_t15 + (0.1e1 / 0.12500000e8)*_t16;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.3e1 / 0.12500000e8)*_t12*_t4*_t5*_t9*rs - 0.1e1 / 0.62500000000e11*_t13*_t17 - 0.1e1 / 0.125000000000e12*_t17*_t8 + (0.3e1 / 0.25000000e8)*_t8*rs;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = (0.1e1 / 0.312500000000000e15)*_t13*_t18 + (0.3e1 / 0.12500000e8)*_t13 - 0.3e1 / 0.62500000000e11*_t15 - 0.3e1 / 0.31250000000e11*_t16 + (0.1e1 / 0.625000000000000e15)*_t18*_t8 + (0.3e1 / 0.25000000e8)*_t8;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_DF_z0_cftermm9_2___2_3__3___1_3__pi___2_3__40_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (0.1e1 / 0.10000e5)*_t1;
  const double _t3 = xc_expm1(-_t2);
  const double _t4 = M_LN2;
  const double _t5 = (0.1e1 / (0.1e1 - _t4));
  const double _t6 = xc_powr(0.2e1, 2, 3);
  const double _t7 = M_CBRT3;
  const double _t8 = (M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t9 = _t5*_t6*_t7*_t8;
  const double _t10 = (M_PI * M_PI);
  const double _t11 = exp(-0.2e1*_t10*_t5*((0.1e1 / 0.6e1)*_t4 - 0.071099999999999997 - 0.90154267736969573/_t10) - _t2);
#if _KMAX >= 1
  const double _t12 = _t3 + 0.1e1;
  const double _t13 = _t12*_t9;
  const double _t14 = (0.1e1 / 0.5000e4)*_t11;
#endif
#if _KMAX >= 3
  const double _t15 = (0.27e2 / 0.500000000e9)*_t13;
  const double _t16 = (rs * rs * rs);
#endif
#if _KMAX >= 4
  const double _t17 = (rs * rs * rs * rs);
#endif

  const double f = _t11 - 0.9e1 / 0.20e2*_t3*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = (0.9e1 / 0.100000e6)*_t13*rs - _t14*rs;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (0.1e1 / 0.25000000e8)*_t1*_t11 - 0.9e1 / 0.500000000e9*_t1*_t13 + (0.9e1 / 0.100000e6)*_t12*_t5*_t6*_t7*_t8 - _t14;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.1e1 / 0.125000000000e12*_t11*_t16 + (0.3e1 / 0.25000000e8)*_t11*rs + (0.9e1 / 0.2500000000000e13)*_t13*_t16 - _t15*rs;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.3e1 / 0.62500000000e11*_t1*_t11 + (0.27e2 / 0.1250000000000e13)*_t1*_t12*_t5*_t6*_t7*_t8 + (0.1e1 / 0.625000000000000e15)*_t11*_t17 + (0.3e1 / 0.25000000e8)*_t11 - 0.9e1 / 0.12500000000000000e17*_t13*_t17 - _t15;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_E_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = xc_expm1(-0.1e1 / 0.10000e5*_t1);
  const double _t3 = (M_PI * M_PI);
  const double _t4 = (0.1e1 / (0.1e1 - M_LN2));
  const double _t5 = _t3*_t4;
#if _KMAX >= 1
  const double _t6 = _t2 + 0.1e1;
  const double _t7 = _t5*_t6;
  const double _t8 = 0.00060000000000000006*_t7;
#endif
#if _KMAX >= 2
  const double _t9 = _t1*_t7;
#endif

  const double f = 3.0*_t2*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t8*rs;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -_t8 + 1.2000000000000002e-7*_t9;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 3.6000000000000005e-7*_t3*_t4*_t6*rs - 2.4000000000000004e-11*_t7*(rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 4.8000000000000015e-15*_t7*(rs * rs * rs * rs) + 3.6000000000000005e-7*_t7 - 1.4400000000000002e-10*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_G_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = exp(-0.1e1 / 0.10000e5*_t1);
  const double _t3 = _t2 + 0.10e2*xc_powr(rs, 5, 4);
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = (0.1e1 / rs);
  const double _t6 = xc_powr(0.2e1, 2, 3)*M_CBRT3*(-0.12e2*M_LN2 - 0.1e1 + (0.7e1 / 0.6e1)*(M_PI * M_PI))/(M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t7 = (0.1e1 / 0.12e2)*_t6;
  const double _t8 = -_t7*xc_log1p(_t5) - 0.01;
  const double _t9 = _t4*_t8;
  const double _t10 = _t2*_t9;
  const double _t11 = _t10*rs;
#if _KMAX >= 1
  const double _t12 = _t5 + 0.1e1;
  const double _t13 = (0.1e1 / _t12);
  const double _t14 = _t2*_t4;
  const double _t15 = (0.1e1 / 0.5000e4)*_t2;
  const double _t16 = _t2*rs;
  const double _t17 = xc_powr(rs, 1, 4);
  const double _t18 = -0.25e2 / 0.2e1*_t17 + (0.1e1 / 0.5000e4)*_t2*rs;
  const double _t19 = (0.1e1 / (_t3 * _t3));
  const double _t20 = _t19*_t8;
  const double _t21 = _t18*_t20;
  const double _t22 = _t16*_t21;
#endif
#if _KMAX >= 2
  const double _t23 = _t13*_t6;
  const double _t24 = _t14*_t23;
  const double _t25 = (0.3e1 / 0.5000e4)*_t2;
  const double _t26 = (rs * rs * rs);
  const double _t27 = (0.1e1 / _t26);
  const double _t28 = (0.1e1 / (_t12 * _t12));
  const double _t29 = _t14*_t28;
  const double _t30 = _t27*_t29;
  const double _t31 = _t10*_t26;
  const double _t32 = _t2*_t21;
  const double _t33 = _t19*_t23;
  const double _t34 = _t18*_t2;
  const double _t35 = _t33*_t34;
  const double _t36 = xc_powr(rs, -3, 4);
  const double _t37 = _t1*_t2;
  const double _t38 = (0.1e1 / 0.5000e4)*_t2 - 0.25e2 / 0.8e1*_t36 - 0.1e1 / 0.25000000e8*_t37;
  const double _t39 = _t20*_t38;
  const double _t40 = _t16*_t39;
  const double _t41 = _t16*_t18;
  const double _t42 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t43 = -0.25e2*_t17 + (0.1e1 / 0.2500e4)*_t2*rs;
  const double _t44 = _t42*_t43;
  const double _t45 = _t44*_t8;
  const double _t46 = _t41*_t45;
#endif
#if _KMAX >= 3
  const double _t47 = _t23*_t4;
  const double _t48 = xc_powi(rs, 5);
  const double _t49 = _t6/_t48;
  const double _t50 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t51 = _t14*_t50;
  const double _t52 = (rs * rs * rs * rs);
  const double _t53 = (0.1e1 / _t52);
  const double _t54 = _t29*_t6;
  const double _t55 = (0.1e1 / _t1);
  const double _t56 = _t19*_t28;
  const double _t57 = _t56*_t6;
  const double _t58 = _t34*_t57;
  const double _t59 = (0.3e1 / 0.25000000e8)*_t2;
  const double _t60 = 0.3e1*_t2;
  const double _t61 = xc_powr(rs, -7, 4);
  const double _t62 = _t2*_t26;
  const double _t63 = -_t59*rs + (0.75e2 / 0.32e2)*_t61 + (0.1e1 / 0.125000000000e12)*_t62;
  const double _t64 = _t20*_t63;
  const double _t65 = _t33*_t38;
  const double _t66 = _t2*_t5;
  const double _t67 = _t1*_t25;
  const double _t68 = _t18*_t45;
  const double _t69 = _t23*_t44;
  const double _t70 = _t34*_t5;
  const double _t71 = _t41*_t8;
  const double _t72 = (0.1e1 / 0.2500e4)*_t2 - 0.25e2 / 0.4e1*_t36 - 0.1e1 / 0.12500000e8*_t37;
  const double _t73 = _t42*_t72;
  const double _t74 = _t38*_t45;
  const double _t75 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t76 = -0.75e2 / 0.2e1*_t17 + (0.3e1 / 0.5000e4)*_t2*rs;
  const double _t77 = _t43*_t75*_t76;
#endif
#if _KMAX >= 4
  const double _t78 = (0.1e1 / 0.2e1)*_t6;
  const double _t79 = _t51*_t6;
  const double _t80 = _t15*_t18;
  const double _t81 = _t2*_t52;
  const double _t82 = 0.4e1*_t2;
  const double _t83 = _t27*_t78;
  const double _t84 = (0.3e1 / 0.12500000e8)*_t62;
  const double _t85 = (0.1e1 / 0.1250e4)*_t37;
  const double _t86 = _t73*_t8;
  const double _t87 = _t18*_t82;
  const double _t88 = 0.3e1*_t16;
  const double _t89 = (0.1e1 / 0.3e1)*_t23*_t70;
  const double _t90 = _t18*_t85;
  const double _t91 = _t77*_t8;
  const double _t92 = _t38*_t88;
  const double _t93 = _t71*_t75;
#endif

  const double f = _t11;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t1*_t15*_t9 + _t10 + _t13*_t14*_t5*_t7 + _t22;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.1e1 / 0.2500e4*_t1*_t2*_t21 - 0.1e1 / 0.30000e5*_t24 - _t25*_t9*rs + _t30*_t7 + (0.1e1 / 0.25000000e8)*_t31 + 0.2e1*_t32 + (0.1e1 / 0.6e1)*_t35*_t5 + _t40 + _t46;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.3e1 / 0.12500000e8)*_t1*_t10 - 0.1e1 / 0.125000000000e12*_t10*_t52 + (0.1e1 / 0.100000000e9)*_t16*_t47 + _t16*_t64 + 0.2e1*_t16*_t74 + _t21*_t26*_t59 - 0.9e1 / 0.5000e4*_t22 - 0.1e1 / 0.20000e5*_t24*_t5 - _t25*_t9 + (0.1e1 / 0.4e1)*_t27*_t58 - 0.1e1 / 0.10000e5*_t35 + _t39*_t60 - _t39*_t67 + (0.1e1 / 0.6e1)*_t49*_t51 - 0.1e1 / 0.4e1*_t53*_t54 - 0.1e1 / 0.20000e5*_t54*_t55 + _t60*_t68 + (0.1e1 / 0.4e1)*_t65*_t66 - _t67*_t68 + (0.1e1 / 0.4e1)*_t69*_t70 + _t71*_t73 + _t71*_t77;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = (0.1e1 / 0.625000000000000e15)*_t10*_t48 + (0.3e1 / 0.5000000e7)*_t11 - _t15*_t65 + _t16*_t20*((0.3e1 / 0.62500000000e11)*_t1*_t2 - _t59 - 0.1e1 / 0.625000000000000e15*_t81 - (0.525e3 / 0.128e3)/xc_powr(rs, 11, 4)) + (0.2e1 / 0.3e1)*_t19*_t34*_t49*_t50 + _t2*_t38*_t56*_t83 + 0.8e1*_t2*_t74 + (0.3e1 / 0.3125000e7)*_t21*_t37 - 0.1e1 / 0.31250000000e11*_t21*_t81 + (0.1e1 / 0.25000000e8)*_t24 + _t28*_t34*_t44*_t83 + _t29*_t49 + (0.1e1 / 0.10000e5)*_t30*_t6 - 0.1e1 / 0.12500000000e11*_t31 - 0.3e1 / 0.1250e4*_t32 + (0.1e1 / 0.25000000e8)*_t33*_t41 - _t33*_t5*_t80 + (0.1e1 / 0.3e1)*_t33*_t63*_t66 - 0.1e1 / 0.375000000000e12*_t37*_t47 - 0.1e1 / 0.625e3*_t37*_t74 + (0.2e1 / 0.3e1)*_t38*_t66*_t69 + _t39*_t84 - 0.9e1 / 0.2500e4*_t40 + _t42*_t71*(-0.3e1 / 0.12500000e8*_t16 + (0.75e2 / 0.16e2)*_t61 + (0.1e1 / 0.62500000000e11)*_t62) + _t43*_t93*(-_t1*_t59 + (0.3e1 / 0.5000e4)*_t2 - 0.75e2 / 0.8e1*_t36) + _t45*_t63*_t88 - 0.9e1 / 0.2500e4*_t46 + (0.1e1 / 0.50000000e8)*_t5*_t54 - _t53*_t58 - 0.1e1 / 0.7500e4*_t53*_t79 - _t55*_t57*_t80 + _t64*_t82 - _t64*_t85 + _t68*_t84 - _t69*_t80 + 0.2e1*_t72*_t76*_t93 + _t73*_t89 + _t77*_t89 - 0.4e1 / 0.3e1*_t79/xc_powi(rs, 6) + _t86*_t87 - _t86*_t90 + _t86*_t92 + _t87*_t91 - _t90*_t91 + _t91*_t92 + _t43*_t71*_t76*(-0.50e2*_t17 + (0.1e1 / 0.1250e4)*_t2*rs)/xc_powi(_t3, 5) + _t14*_t78/((_t12 * _t12 * _t12 * _t12)*xc_powi(rs, 7));
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(w20_ec_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_DF_z0_cftermm0p9___3_2___1_3__3___2_3___8_pi___2_3___k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_DF_z0_cftermm9_2___2_3__3___1_3__pi___2_3__40_k, _KMAX)(p, rs, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_E_z0_k, _KMAX)(p, rs, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_G_z0_k, _KMAX)(p, rs, _hc3);
  const double _t1 = (0.1e1 / rs);
  const double _t2 = (0.1e1 / (rs * rs));
  const double _t3 = xc_powr(rs, -3, 2);
  const double _t4 = _hc0[0]*_t1 + _hc1[0]*_t2 + _hc2[0]*_t3;
  const double _t5 = (0.1e1 - M_LN2)/(M_PI * M_PI);
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
#if _KMAX >= 1
  const double _t7 = _hc0[0]*_t2;
  const double _t8 = (0.1e1 / (rs * rs * rs));
  const double _t9 = 0.2e1*_t8;
  const double _t10 = xc_powr(rs, -5, 2);
  const double _t11 = _hc2[0]*_t10;
  const double _t12 = -_hc0[1]*_t1 + _hc1[0]*_t9 - _hc1[1]*_t2 - _hc2[1]*_t3 + (0.3e1 / 0.2e1)*_t11 + _t7;
  const double _t13 = -_t12;
  const double _t14 = _t4 + 0.1e1;
  const double _t15 = _t6/_t14;
#endif
#if _KMAX >= 2
  const double _t16 = _hc0[2]*_t1;
  const double _t17 = _hc1[2]*_t2;
  const double _t18 = _hc2[2]*_t3;
  const double _t19 = (0.1e1 / (rs * rs * rs * rs));
  const double _t20 = 0.6e1*_t19;
  const double _t21 = 0.4e1*_t8;
  const double _t22 = xc_powr(rs, -7, 2);
  const double _t23 = _hc2[0]*_t22;
  const double _t24 = _hc0[0]*_t9 - 0.2e1*_hc0[1]*_t2 + _hc1[0]*_t20 - _hc1[1]*_t21 - 0.3e1*_hc2[1]*_t10 + _t16 + _t17 + _t18 + (0.15e2 / 0.4e1)*_t23;
  const double _t25 = (0.1e1 / (_t14 * _t14));
  const double _t26 = _t12*_t25;
  const double _t27 = _t13*_t6;
#endif
#if _KMAX >= 3
  const double _t28 = xc_powi(rs, -5);
  const double _t29 = 0.24e2*_t28;
  const double _t30 = 0.6e1*_t8;
  const double _t31 = xc_powr(rs, -9, 2);
  const double _t32 = _hc0[0]*_t20 - 0.6e1*_hc0[1]*_t8 + 0.3e1*_hc0[2]*_t2 - _hc0[3]*_t1 + _hc1[0]*_t29 - 0.18e2*_hc1[1]*_t19 + _hc1[2]*_t30 - _hc1[3]*_t2 + (0.105e3 / 0.8e1)*_hc2[0]*_t31 - 0.45e2 / 0.4e1*_hc2[1]*_t22 + (0.9e1 / 0.2e1)*_hc2[2]*_t10 - _hc2[3]*_t3;
  const double _t33 = -_t32;
  const double _t34 = _t26*_t5;
  const double _t35 = -_t24;
  const double _t36 = _t25*_t35;
  const double _t37 = (0.1e1 / (_t14 * _t14 * _t14));
  const double _t38 = _hc0[1]*_t1;
  const double _t39 = _hc1[1]*_t2;
  const double _t40 = _hc2[1]*_t3;
  const double _t41 = _hc1[0]*_t21 + 0.3e1*_t11 - 0.2e1*_t38 - 0.2e1*_t39 - 0.2e1*_t40 + 0.2e1*_t7;
  const double _t42 = _t37*_t41;
  const double _t43 = _t12*_t42;
#endif
#if _KMAX >= 4
  const double _t44 = (0.3e1 / 0.2e1)*_t24*_t5;
  const double _t45 = _t12*_t27;
#endif

  const double f = _hc3[0] - _t6*xc_log1p(_t4);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc3[1] - _t13*_t15;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc3[2] - _t15*_t24 - _t26*_t27;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc3[3] - _t15*_t33 - _t24*_t34 - _t27*_t36 - _t27*_t43;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _hc3[4] - _t13*_t35*_t42*_t5 - _t15*(_hc0[0]*_t29 - 0.24e2*_hc0[1]*_t19 + 0.12e2*_hc0[2]*_t8 - 0.4e1*_hc0[3]*_t2 + _hc0[4]*_t1 + 0.120e3*_hc1[0]/xc_powi(rs, 6) - 0.96e2*_hc1[1]*_t28 + 0.36e2*_hc1[2]*_t19 - 0.8e1*_hc1[3]*_t8 + _hc1[4]*_t2 + (0.945e3 / 0.16e2)*_hc2[0]/xc_powr(rs, 11, 2) - 0.105e3 / 0.2e1*_hc2[1]*_t31 + (0.45e2 / 0.2e1)*_hc2[2]*_t22 - 0.6e1*_hc2[3]*_t10 + _hc2[4]*_t3) - _t25*_t27*_t32 - 0.3e1 / 0.2e1*_t33*_t34 - _t36*_t44 - _t37*_t45*(-_hc0[0]*_t21 + 0.4e1*_hc0[1]*_t2 - 0.12e2*_hc1[0]*_t19 + 0.8e1*_hc1[1]*_t8 + 0.6e1*_hc2[1]*_t10 - 0.2e1*_t16 - 0.2e1*_t17 - 0.2e1*_t18 - 0.15e2 / 0.2e1*_t23) - _t43*_t44 - _t41*_t45*(_hc1[0]*_t30 + (0.9e1 / 0.2e1)*_t11 - 0.3e1*_t38 - 0.3e1*_t39 - 0.3e1*_t40 + 0.3e1*_t7)/(_t14 * _t14 * _t14 * _t14);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_w20_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(w20_ec_z0_k, _KMAX)(p, rs, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[1];
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[2];
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[3];
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _hc0[4];
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
  XC_CAT(f_w20_zeta0_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t4, _hc0);
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
  XC_CAT(f_w20_k, _KMAX)(p, _t5/xc_powr(_t1, 1, 3), _t6*_t7, _hc0);
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