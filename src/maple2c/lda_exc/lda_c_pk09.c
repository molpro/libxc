/*
  Generated from python/lda_exc/lda_c_pk09.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_pk09
*/

#ifndef _LDA_C_PK09_KERNEL_BODY
#define maple2c_order 3
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_PK09_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_PK09_HELPER_BODIES
#include "lda_c_pk09.c"
#undef _LDA_C_PK09_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_PK09_HELPER_BODIES
#include "lda_c_pk09.c"
#undef _LDA_C_PK09_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_PK09_HELPER_BODIES
#include "lda_c_pk09.c"
#undef _LDA_C_PK09_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_PK09_HELPER_BODIES
#include "lda_c_pk09.c"
#undef _LDA_C_PK09_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_pk09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_pk09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_pk09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_pk09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_pk09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_pk09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_pk09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_pk09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_PK09_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_gen_k, _KMAX)(const xc_func_type *p, double z, double n, double *out) {

  const double _t1 = z + 0.1e1;
  const double _t2 = _t1 <= p->zeta_threshold;
  const double _t3 = pow(p->zeta_threshold, n);
  const double _t4 = pow(_t1, n);
#if _KMAX >= 1
  const double _t5 = log(p->zeta_threshold);
  const double _t6 = log(_t1);
  const double _t7 = _t4*_t6;
  const double _t8 = (0.1e1 / _t1);
  const double _t9 = _t4*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = _t4*(_t6 * _t6);
  const double _t11 = _t7*_t8;
  const double _t12 = (0.1e1 / (_t1 * _t1));
  const double _t13 = _t12*_t4;
  const double _t14 = _t13*n;
  const double _t15 = (n * n);
#endif
#if _KMAX >= 3
  const double _t16 = _t12*_t7;
  const double _t17 = _t4/(_t1 * _t1 * _t1);
#endif

  const double f = my_piecewise3(_t2, _t3, _t4);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = my_piecewise3(_t2, _t3*_t5, _t7);
  out[1] = df_dn;
  const double df_dz = my_piecewise3(_t2, 0, _t9*n);
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = my_piecewise3(_t2, _t3*(_t5 * _t5), _t10);
  out[3] = d2f_dn2;
  const double d2f_dz_dn = my_piecewise3(_t2, 0, _t11*n + _t9);
  out[4] = d2f_dz_dn;
  const double d2f_dz2 = my_piecewise3(_t2, 0, _t13*_t15 - _t14);
  out[5] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = my_piecewise3(_t2, _t3*(_t5 * _t5 * _t5), _t4*(_t6 * _t6 * _t6));
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t2, 0, _t10*_t8*n + 0.2e1*_t11);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t2, 0, -_t13 + 0.2e1*_t14 + _t15*_t16 - _t16*n);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t2, 0, -0.3e1*_t15*_t17 + _t17*(n * n * n) + 0.2e1*_t17*n);
  out[9] = d3f_dz3;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_r_num_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (rs * rs * rs);
  const double _t3 = (rs * rs * rs * rs);

  const double f = 49.341312958396707*_t1 - 23.82423721683793*_t2 + 0.94408074169510479*_t3 + 0.00029303914417833798*xc_powi(rs, 5) + 24.005021512787114*rs - 113.69336978972719;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -71.472711650513791*_t1 + 3.7763229667804192*_t2 + 0.00146519572089169*_t3 + 98.682625916793415*rs + 24.005021512787114;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 11.328968900341258*_t1 + 0.0058607828835667598*_t2 - 142.94542330102758*rs + 98.682625916793415;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.017582348650700279*_t1 + 22.657937800682515*rs - 142.94542330102758;
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_r_den_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (rs * rs * rs);

  const double f = 54.403433137390837*_t1 - 25.15400990418799*_t2 + 1.0*(rs * rs * rs * rs) + 16.266312944424241*rs - 109.7426349321691;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -75.46202971256397*_t1 + 4.0*_t2 + 108.80686627478167*rs + 16.266312944424241;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 12.0*_t1 - 150.92405942512794*rs + 108.80686627478167;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 24.0*rs - 150.92405942512794;
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_r_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_r_den_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_r_num_k, _KMAX)(p, rs, _hc1);
  const double _t1 = my_piecewise3(_hc0[0] >= 0, _hc0[0], -_hc0[0]) <= 9.9999999999999998e-13;
  const double _t2 = (0.1e1 / (_hc0[0]));
#if _KMAX >= 1
  const double _t3 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t4 = _hc1[0]*_t3;
#endif
#if _KMAX >= 2
  const double _t5 = _hc0[1]*_t3;
  const double _t6 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t7 = ((_hc0[1]) * (_hc0[1]));
#endif

  const double f = my_piecewise3(_t1, 0, _hc1[0]*_t2);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = my_piecewise3(_t1, 0, -_hc0[1]*_t4 + _hc1[1]*_t2);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = my_piecewise3(_t1, 0, -_hc0[2]*_t4 + 0.2e1*_hc1[0]*_t6*_t7 - 0.2e1*_hc1[1]*_t5 + _hc1[2]*_t2);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = my_piecewise3(_t1, 0, 0.6e1*_hc0[1]*_hc0[2]*_hc1[0]*_t6 - 0.3e1*_hc0[2]*_hc1[1]*_t3 - _hc0[3]*_t4 + 0.6e1*_hc1[1]*_t6*_t7 - 0.3e1*_hc1[2]*_t5 + _hc1[3]*_t2 - 0.6e1*((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0]/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_s_num_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (z * z);
  const double _t2 = (z * z * z);

  const double f = -1.4269304149842164*_t1 + 0.58034406381224798*_t2 - 0.0109912236729144*(z * z * z * z) + 1.1801314654631911*z - 0.32481568604919886;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 1.7410321914367439*_t1 - 0.0439648946916576*_t2 - 2.8538608299684328*z + 1.1801314654631911;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -0.1318946840749728*_t1 + 3.4820643828734879*z - 2.8538608299684328;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 3.4820643828734879 - 0.2637893681499456*z;
  out[3] = d3f_dz3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_s_den_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (z * z);

  const double f = -2.5218818358694818*_t1 + 1.0*(z * z * z) + 2.0970850588349074*z - 0.5778610319323943;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 3.0*_t1 - 5.0437636717389636*z + 2.0970850588349074;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 6.0*z - 5.0437636717389636;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 6.0;
  out[3] = d3f_dz3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_s_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_s_den_k, _KMAX)(p, z, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_s_num_k, _KMAX)(p, z, _hc1);
  const double _t1 = (0.1e1 / (_hc0[0]));
#if _KMAX >= 1
  const double _t2 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t3 = _hc1[0]*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = _hc0[1]*_t2;
  const double _t5 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t6 = ((_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc0[1]*_t3 + _hc1[1]*_t1;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -_hc0[2]*_t3 + 0.2e1*_hc1[0]*_t5*_t6 - 0.2e1*_hc1[1]*_t4 + _hc1[2]*_t1;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0.6e1*_hc0[1]*_hc0[2]*_hc1[0]*_t5 - 0.3e1*_hc0[2]*_hc1[1]*_t2 - _hc0[3]*_t3 + 0.6e1*_hc1[1]*_t5*_t6 - 0.3e1*_hc1[2]*_t4 + _hc1[3]*_t1 - 0.6e1*((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0]/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  out[3] = d3f_dz3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ss_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_r_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_s_k, _KMAX)(p, z, _hc1);
  const double _t1 = 1.28*_hc0[0];
#if _KMAX >= 1
  const double _t2 = 1.28*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t3 = 1.28*_hc0[2];
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc1[1]*_t1;
  out[1] = df_dz;
  const double df_drs = _hc1[0]*_t2;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc1[2]*_t1;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc1[1]*_t2;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[0]*_t3;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc1[3]*_t1;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc1[2]*_t2;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc1[1]*_t3;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = 1.28*_hc0[3]*_hc1[0];
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(alpha_z_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(ss_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_gen_k, _KMAX)(p, z, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_gen_k, _KMAX)(p, -z, _hc0[0], _hc2);
  const double _t1 = _hc1[0] + _hc2[0];
#if _KMAX >= 1
  const double _t2 = _hc0[1]*_hc1[1];
  const double _t3 = _hc0[1]*_hc2[1];
  const double _t4 = -_hc1[2] + _hc2[2] - _t2 - _t3;
  const double _t5 = 0.2e1/(_t1 * _t1);
  const double _t6 = _hc0[2]*_hc1[1];
  const double _t7 = _hc0[2]*_hc2[1];
  const double _t8 = -_t6 - _t7;
#endif
#if _KMAX >= 2
  const double _t9 = -0.2e1*_hc1[2] + 0.2e1*_hc2[2] - 0.2e1*_t2 - 0.2e1*_t3;
  const double _t10 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t11 = 0.2e1*_t10;
  const double _t12 = _t11*_t9;
  const double _t13 = _hc0[1]*_hc1[4];
  const double _t14 = _hc0[3]*_hc1[1];
  const double _t15 = _hc0[3]*_hc2[1];
  const double _t16 = _hc0[1]*_hc1[3] + _hc1[4];
  const double _t17 = _hc0[1]*_t16;
  const double _t18 = _hc0[1]*_hc2[3] - _hc2[4];
  const double _t19 = _hc0[1]*_t18;
  const double _t20 = _hc0[1]*_hc2[4] - _hc1[5] - _hc2[5] - _t13 - _t14 - _t15 - _t17 - _t19;
  const double _t21 = _hc0[4]*_hc1[1];
  const double _t22 = _hc0[4]*_hc2[1];
  const double _t23 = _hc0[2]*_t16;
  const double _t24 = _hc0[2]*_t18;
  const double _t25 = -_t21 - _t22 - _t23 - _t24;
  const double _t26 = -0.2e1*_t6 - 0.2e1*_t7;
  const double _t27 = _t11*_t8;
  const double _t28 = _hc0[5]*_hc1[1];
  const double _t29 = _hc0[5]*_hc2[1];
  const double _t30 = ((_hc0[2]) * (_hc0[2]));
  const double _t31 = _hc1[3]*_t30;
  const double _t32 = _hc2[3]*_t30;
  const double _t33 = -_t28 - _t29 - _t31 - _t32;
#endif
#if _KMAX >= 3
  const double _t34 = 0.2e1/(_t1 * _t1 * _t1 * _t1);
  const double _t35 = _t34*(-0.3e1*_hc1[2] + 0.3e1*_hc2[2] - 0.3e1*_t2 - 0.3e1*_t3);
  const double _t36 = _t35*_t9;
  const double _t37 = 0.2e1*_hc0[1]*_hc2[4] - 0.2e1*_hc1[5] - 0.2e1*_hc2[5] - 0.2e1*_t13 - 0.2e1*_t14 - 0.2e1*_t15 - 0.2e1*_t17 - 0.2e1*_t19;
  const double _t38 = 0.4e1*_t10;
  const double _t39 = _t38*_t9;
  const double _t40 = _hc0[1]*_hc1[7] + _hc1[8];
  const double _t41 = 0.2e1*_hc0[3];
  const double _t42 = _hc0[1]*_hc2[7];
  const double _t43 = _hc0[1]*_hc1[6] + _hc1[7];
  const double _t44 = _hc0[1]*_t43 + _hc0[3]*_hc1[3] + _t40;
  const double _t45 = _hc0[1]*_hc2[6] - _hc2[7];
  const double _t46 = _hc0[1]*_t45 + _hc0[3]*_hc2[3] + _hc2[8] - _t42;
  const double _t47 = 0.2e1*_hc0[4];
  const double _t48 = _t26*_t8;
  const double _t49 = _hc0[2]*_t47;
  const double _t50 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t51 = 0.3e1*_hc0[2]*_hc0[5];
#endif

  const double f = 0.2e1/_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t4*_t5;
  out[1] = df_dz;
  const double df_drs = _t5*_t8;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t12*_t4 + _t20*_t5;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _t12*_t8 + _t25*_t5;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _t26*_t27 + _t33*_t5;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t11*_t37*_t4 + _t20*_t39 + _t36*_t4 + _t5*(-_hc0[1]*_hc1[8] - _hc0[1]*_hc2[8] - _hc0[1]*_t40 - _hc0[1]*_t44 - _hc0[1]*_t46 + _hc0[1]*(-_hc2[8] + _t42) - _hc0[3]*_hc1[4] + _hc0[3]*_hc2[4] - _hc0[6]*_hc1[1] - _hc0[6]*_hc2[1] - _hc1[9] + _hc2[9] - _t16*_t41 - _t18*_t41);
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _t25*_t39 + _t27*_t37 + _t36*_t8 + _t5*(-_hc0[2]*_t44 - _hc0[2]*_t46 - _hc0[7]*_hc1[1] - _hc0[7]*_hc2[1] - _t16*_t47 - _t18*_t47);
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _t11*_t25*_t26 + _t12*_t33 + _t27*(-0.2e1*_t21 - 0.2e1*_t22 - 0.2e1*_t23 - 0.2e1*_t24) + _t35*_t48 + _t5*(-_hc0[5]*_t16 - _hc0[5]*_t18 - _hc0[8]*_hc1[1] - _hc0[8]*_hc2[1] - _hc1[3]*_t49 - _hc2[3]*_t49 - _t30*_t43 - _t30*_t45);
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _t26*_t33*_t38 + _t27*(-0.2e1*_t28 - 0.2e1*_t29 - 0.2e1*_t31 - 0.2e1*_t32) + _t34*_t48*(-0.3e1*_t6 - 0.3e1*_t7) + _t5*(-_hc0[9]*_hc1[1] - _hc0[9]*_hc2[1] - _hc1[3]*_t51 - _hc1[6]*_t50 - _hc2[3]*_t51 - _hc2[6]*_t50);
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(alpha_n_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(rs, 1, 3);
  const double _t2 = exp(-0.46958449007619002*_t1);
  const double _t3 = xc_powr(rs, 2, 3);
  const double _t4 = exp(-1.7093947680216799*_t1);
#if _KMAX >= 1
  const double _t5 = (0.1e1 / _t3);
  const double _t6 = (0.1e1 / _t1);
#endif
#if _KMAX >= 2
  const double _t7 = _t2/xc_powr(rs, 5, 3);
  const double _t8 = _t4/xc_powr(rs, 4, 3);
  const double _t9 = (0.1e1 / rs);
#endif
#if _KMAX >= 3
  const double _t10 = xc_powr(rs, -7, 3);
  const double _t11 = (0.1e1 / (rs * rs));
#endif

  const double f = 0.077123208419481004*_t1*_t2 + 0.59934325690351498*_t3*_t4 + 0.41081146652127998;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.025707736139826999*_t2*_t5 - 0.012071954166233903*_t2*_t6 + 0.39956217126900995*_t4*_t6 - 0.34150474253331398*_t4;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.0018896008137913613*_t2*_t9 + 0.19458880671367923*_t4*_t5 - 0.22766982835554264*_t4*_t9 - 0.017138490759884665*_t7 - 0.13318739042300332*_t8;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.0026826564813853112*_t10*_t2 + 0.17758318723067107*_t10*_t4 - 0.0018896008137913613*_t11*_t2 + 0.30355977114072352*_t11*_t4 + 0.028564151266474443*_t2/xc_powr(rs, 8, 3) - 0.00029577574486392333*_t7 - 0.11087636270398173*_t8;
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(alpha_eff_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(alpha_n_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(alpha_z_k, _KMAX)(p, rs, z, _hc1);
#if _KMAX >= 2
  const double _t1 = 0.2e1*_hc0[1];
#endif

  const double f = _hc0[0]*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[0]*_hc1[1];
  out[1] = df_dz;
  const double df_drs = _hc0[0]*_hc1[2] + _hc0[1]*_hc1[0];
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[0]*_hc1[3];
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[0]*_hc1[4] + _hc0[1]*_hc1[1];
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[0]*_hc1[5] + _hc0[2]*_hc1[0] + _hc1[2]*_t1;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[0]*_hc1[6];
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[0]*_hc1[7] + _hc0[1]*_hc1[3];
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc0[0]*_hc1[8] + _hc0[2]*_hc1[1] + _hc1[4]*_t1;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[0]*_hc1[9] + 0.3e1*_hc0[1]*_hc1[5] + 0.3e1*_hc0[2]*_hc1[2] + _hc0[3]*_hc1[0];
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(beta_eff_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(rs, 1, 3);
  const double _t2 = exp(-0.837303782322808*_t1);
  const double _t3 = exp(-1.03665759464352*_t1);
#if _KMAX >= 2
  const double _t4 = xc_powr(rs, -7, 4);
  const double _t5 = _t3/xc_powr(rs, 5, 3);
#endif

  const double f = 2.619709858963178*_t1*_t3 - 2.22609499098519*_t2*xc_powr(rs, 1, 4) + 0.53807448350043696;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.5565237477462975*_t2/xc_powr(rs, 3, 4) + 0.62130591858725225*_t2/pow(rs, 0.5e1 / 0.12e2) + 0.87323661965439267*_t3/xc_powr(rs, 2, 3) - 0.90524737368556105*_t3/_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.41739281080972312*_t2*_t4 - 0.17340726520421764*_t2/pow(rs, 0.13e2 / 0.12e2) - 0.10355098643120871*_t2/pow(rs, 0.17e2 / 0.12e2) + 0.31281052165407915*_t3/rs - 6.9388939039072284e-18*_t3/xc_powr(rs, 4, 3) - 0.58215774643626178*_t5;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.048398186345915228*_t2*_t4 - 0.73043741891701547*_t2/xc_powr(rs, 11, 4) + 0.21675908150527205*_t2/pow(rs, 0.25e2 / 0.12e2) + 0.030202371042435871*_t2/pow(rs, 0.29e2 / 0.12e2) - 0.31281052165407915*_t3/(rs * rs) + 0.2011660830412358*_t3/xc_powr(rs, 7, 3) + 0.97026291072710297*_t3/xc_powr(rs, 8, 3) - 0.10809246765236747*_t5;
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(k_fs_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.1e1 / 0.3e1, _hc0);
  const double _t1 = _hc0[0] + 0.1e1;
  const double _t2 = xc_powr(0.18e2, 1, 3)*M_CBRTPI;
  const double _t3 = (0.1e1 / 0.2e1)*_t2;
  const double _t4 = _t3/rs;
#if _KMAX >= 1
  const double _t5 = _t3/(rs * rs);
#endif
#if _KMAX >= 2
  const double _t6 = _t2/(rs * rs * rs);
#endif

  const double f = _t1*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[2]*_t4;
  out[1] = df_dz;
  const double df_drs = -_t1*_t5;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[5]*_t4;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = -_hc0[2]*_t5;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _t1*_t6;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[9]*_t4;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = -_hc0[5]*_t5;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc0[2]*_t6;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = -0.3e1*_t1*_t2/(rs * rs * rs * rs);
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(k_uu_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(alpha_eff_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(k_fs_k, _KMAX)(p, rs, z, _hc1);
  const double _t1 = _hc0[0]*_hc1[0];
  const double _t2 = _t1 > 9.9999999999999994e-12;
#if _KMAX >= 2
  const double _t3 = 0.2e1*_hc0[1];
  const double _t4 = 0.2e1*_hc0[2];
#endif
#if _KMAX >= 3
  const double _t5 = 0.2e1*_hc0[4];
#endif

  const double f = my_piecewise3(_t2, _t1, 9.9999999999999994e-12);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, _hc0[0]*_hc1[1] + _hc0[1]*_hc1[0], 0);
  out[1] = df_dz;
  const double df_drs = my_piecewise3(_t2, _hc0[0]*_hc1[2] + _hc0[2]*_hc1[0], 0);
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, _hc0[0]*_hc1[3] + _hc0[3]*_hc1[0] + _hc1[1]*_t3, 0);
  out[3] = d2f_dz2;
  const double d2f_drs_dz = my_piecewise3(_t2, _hc0[0]*_hc1[4] + _hc0[1]*_hc1[2] + _hc0[2]*_hc1[1] + _hc0[4]*_hc1[0], 0);
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = my_piecewise3(_t2, _hc0[0]*_hc1[5] + _hc0[5]*_hc1[0] + _hc1[2]*_t4, 0);
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, _hc0[0]*_hc1[6] + 0.3e1*_hc0[1]*_hc1[3] + 0.3e1*_hc0[3]*_hc1[1] + _hc0[6]*_hc1[0], 0);
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = my_piecewise3(_t2, _hc0[0]*_hc1[7] + _hc0[2]*_hc1[3] + _hc0[3]*_hc1[2] + _hc0[7]*_hc1[0] + _hc1[1]*_t5 + _hc1[4]*_t3, 0);
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = my_piecewise3(_t2, _hc0[0]*_hc1[8] + _hc0[1]*_hc1[5] + _hc0[5]*_hc1[1] + _hc0[8]*_hc1[0] + _hc1[2]*_t5 + _hc1[4]*_t4, 0);
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = my_piecewise3(_t2, _hc0[0]*_hc1[9] + 0.3e1*_hc0[2]*_hc1[5] + 0.3e1*_hc0[5]*_hc1[2] + _hc0[9]*_hc1[0], 0);
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(k_dd_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  const double _t1 = -z;
  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(alpha_eff_k, _KMAX)(p, rs, _t1, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(k_fs_k, _KMAX)(p, rs, _t1, _hc1);
  const double _t2 = _hc0[0]*_hc1[0];
  const double _t3 = _t2 > 9.9999999999999994e-12;
#if _KMAX >= 2
  const double _t4 = 0.2e1*_hc0[1];
  const double _t5 = 0.2e1*_hc0[2];
#endif
#if _KMAX >= 3
  const double _t6 = 0.2e1*_hc0[4];
#endif

  const double f = my_piecewise3(_t3, _t2, 9.9999999999999994e-12);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t3, -_hc0[0]*_hc1[1] - _hc0[1]*_hc1[0], 0);
  out[1] = df_dz;
  const double df_drs = my_piecewise3(_t3, _hc0[0]*_hc1[2] + _hc0[2]*_hc1[0], 0);
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t3, _hc0[0]*_hc1[3] + _hc0[3]*_hc1[0] + _hc1[1]*_t4, 0);
  out[3] = d2f_dz2;
  const double d2f_drs_dz = my_piecewise3(_t3, -_hc0[0]*_hc1[4] - _hc0[1]*_hc1[2] - _hc0[2]*_hc1[1] - _hc0[4]*_hc1[0], 0);
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = my_piecewise3(_t3, _hc0[0]*_hc1[5] + _hc0[5]*_hc1[0] + _hc1[2]*_t5, 0);
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t3, -_hc0[0]*_hc1[6] - 0.3e1*_hc0[1]*_hc1[3] - 0.3e1*_hc0[3]*_hc1[1] - _hc0[6]*_hc1[0], 0);
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = my_piecewise3(_t3, _hc0[0]*_hc1[7] + _hc0[2]*_hc1[3] + _hc0[3]*_hc1[2] + _hc0[7]*_hc1[0] + _hc1[1]*_t6 + _hc1[4]*_t4, 0);
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = my_piecewise3(_t3, -_hc0[0]*_hc1[8] - _hc0[1]*_hc1[5] - _hc0[5]*_hc1[1] - _hc0[8]*_hc1[0] - _hc1[2]*_t6 - _hc1[4]*_t5, 0);
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = my_piecewise3(_t3, _hc0[0]*_hc1[9] + 0.3e1*_hc0[2]*_hc1[5] + 0.3e1*_hc0[5]*_hc1[2] + _hc0[9]*_hc1[0], 0);
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(k_ud_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(k_fs_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(k_fs_k, _KMAX)(p, rs, -z, _hc1);
  double _hc2[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(beta_eff_k, _KMAX)(p, rs, _hc2);
  const double _t1 = _hc0[0] + _hc1[0];
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = _hc2[0]*_t2;
  const double _t4 = _hc0[0]*_hc1[0];
  const double _t5 = 0.2e1*_t4;
  const double _t6 = _t3*_t5;
  const double _t7 = _t6 > 9.9999999999999994e-12;
#if _KMAX >= 1
  const double _t8 = 0.2e1*_hc1[1];
  const double _t9 = _hc0[0]*_t3;
  const double _t10 = 0.2e1*_hc0[1];
  const double _t11 = _hc1[0]*_t3;
  const double _t12 = (0.1e1 / (_t1 * _t1));
  const double _t13 = _hc2[0]*_t12;
  const double _t14 = -_hc0[1] + _hc1[1];
  const double _t15 = _t14*_t5;
  const double _t16 = _hc2[1]*_t2;
  const double _t17 = 0.2e1*_hc1[2];
  const double _t18 = 0.2e1*_hc0[2];
  const double _t19 = -_hc0[2] - _hc1[2];
  const double _t20 = _t13*_t5;
#endif
#if _KMAX >= 2
  const double _t21 = 0.2e1*_hc1[3];
  const double _t22 = 0.4e1*_t3;
  const double _t23 = _hc0[1]*_hc1[1];
  const double _t24 = 0.2e1*_hc0[3];
  const double _t25 = 0.4e1*_t14;
  const double _t26 = _hc0[0]*_t13;
  const double _t27 = _hc1[1]*_t26;
  const double _t28 = _hc1[0]*_t13;
  const double _t29 = _hc0[1]*_t28;
  const double _t30 = -_hc0[3] - _hc1[3];
  const double _t31 = 0.2e1*_hc1[1] - _t10;
  const double _t32 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t33 = _hc2[0]*_t32;
  const double _t34 = _t31*_t33;
  const double _t35 = _hc0[0]*_t16;
  const double _t36 = _hc1[0]*_t16;
  const double _t37 = _t10*_t3;
  const double _t38 = _t3*_t8;
  const double _t39 = 0.2e1*_hc0[4];
  const double _t40 = -_hc0[4] + _hc1[4];
  const double _t41 = _hc2[1]*_t12;
  const double _t42 = _t14*_t26;
  const double _t43 = _t14*_t28;
  const double _t44 = _t19*_t26;
  const double _t45 = _t19*_t28;
  const double _t46 = _t19*_t5;
  const double _t47 = _hc2[2]*_t2;
  const double _t48 = 0.4e1*_t35;
  const double _t49 = 0.2e1*_hc1[5];
  const double _t50 = 0.4e1*_hc0[2];
  const double _t51 = _hc0[2]*_t22;
  const double _t52 = 0.2e1*_hc0[5];
  const double _t53 = -_hc0[5] - _hc1[5];
  const double _t54 = 0.4e1*_t19;
  const double _t55 = _t4*_t41;
  const double _t56 = 0.4e1*_t44;
  const double _t57 = -_t17 - _t18;
  const double _t58 = _t33*_t46;
#endif
#if _KMAX >= 3
  const double _t59 = 0.2e1*_t9;
  const double _t60 = 0.6e1*_t3;
  const double _t61 = 0.2e1*_t11;
  const double _t62 = _t13*_t23;
  const double _t63 = 0.6e1*_t30;
  const double _t64 = -_t21 - _t24;
  const double _t65 = _hc0[0]*_hc1[1];
  const double _t66 = _t34*_t65;
  const double _t67 = 0.6e1*_t14;
  const double _t68 = _hc0[1]*_hc1[0];
  const double _t69 = _t34*_t68;
  const double _t70 = _t34*_t4;
  const double _t71 = _t15*_t31;
  const double _t72 = _hc2[0]/(_t1 * _t1 * _t1 * _t1);
  const double _t73 = _t72*(-0.3e1*_hc0[1] + 0.3e1*_hc1[1]);
  const double _t74 = 0.4e1*_t16;
  const double _t75 = _hc0[4]*_t22;
  const double _t76 = 0.4e1*_t40;
  const double _t77 = _t25*_t41;
  const double _t78 = _hc0[1]*_hc1[2];
  const double _t79 = _t13*_t78;
  const double _t80 = _hc1[1]*_t50;
  const double _t81 = _t13*_t80;
  const double _t82 = 0.4e1*_hc0[4];
  const double _t83 = _hc2[1]*_t32;
  const double _t84 = _t14*_t34;
  const double _t85 = _t46*_t73;
  const double _t86 = _hc0[0]*_t47;
  const double _t87 = _hc1[0]*_t47;
  const double _t88 = _hc2[2]*_t12;
  const double _t89 = _hc0[0]*_hc1[2];
  const double _t90 = _t14*_t50;
  const double _t91 = _hc1[0]*_t41;
  const double _t92 = _t26*_t53;
  const double _t93 = _t41*_t54;
  const double _t94 = _t28*_t53;
  const double _t95 = _t33*_t57;
  const double _t96 = _hc0[0]*_t19;
  const double _t97 = _t95*_t96;
  const double _t98 = _hc1[0]*_t19;
  const double _t99 = _t95*_t98;
  const double _t100 = 0.6e1*_hc1[2];
  const double _t101 = 0.6e1*_hc1[5];
  const double _t102 = 0.6e1*_hc0[2];
  const double _t103 = 0.12e2*_hc1[2];
  const double _t104 = _hc0[2]*_t103;
  const double _t105 = 0.6e1*_hc0[5];
  const double _t106 = 0.6e1*_t19*_t4;
#endif

  const double f = my_piecewise3(_t7, _t6, 9.9999999999999994e-12);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t7, _t10*_t11 + _t13*_t15 - _t8*_t9, 0);
  out[1] = df_dz;
  const double df_drs = my_piecewise3(_t7, _t11*_t18 + _t16*_t5 + _t17*_t9 + _t19*_t20, 0);
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t7, _t11*_t24 + _t15*_t34 + _t20*_t30 + _t21*_t9 - _t22*_t23 - _t25*_t27 + _t25*_t29, 0);
  out[3] = d2f_dz2;
  const double d2f_drs_dz = my_piecewise3(_t7, -_hc0[2]*_t38 + _hc1[2]*_t37 - 0.2e1*_hc1[4]*_t9 + _t10*_t36 + _t10*_t45 + _t11*_t39 + _t15*_t41 + _t17*_t42 + _t18*_t43 + _t20*_t40 + _t34*_t46 - _t35*_t8 - _t44*_t8, 0);
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = my_piecewise3(_t7, _hc1[2]*_t48 + _hc1[2]*_t51 + _hc1[2]*_t56 + _t11*_t52 + _t20*_t53 + _t36*_t50 + _t45*_t50 + _t47*_t5 + _t49*_t9 + _t54*_t55 + _t57*_t58, 0);
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t7, _hc0[1]*_hc1[3]*_t60 - _hc0[3]*_hc1[1]*_t60 + 0.6e1*_hc0[3]*_t43 + _hc0[6]*_t61 + 0.6e1*_hc1[3]*_t42 - _hc1[6]*_t59 - 0.12e2*_t14*_t62 + _t15*_t33*_t64 + _t20*(-_hc0[6] + _hc1[6]) - _t27*_t63 + _t29*_t63 + 0.4e1*_t30*_t70 - _t66*_t67 + _t67*_t69 + _t71*_t73, 0);
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = my_piecewise3(_t7, _hc0[0]*_t17*_t84 - _hc0[1]*_hc1[4]*_t22 + _hc0[3]*_t17*_t3 + _hc0[7]*_t61 + _hc1[0]*_t18*_t84 - _hc1[1]*_t75 + _hc1[3]*_t18*_t3 - _hc1[4]*_t25*_t26 + _hc1[7]*_t59 - _t14*_t81 + _t17*_t26*_t30 + _t18*_t28*_t30 + _t20*(-_hc0[7] - _hc1[7]) + _t21*_t35 + _t21*_t44 - _t23*_t74 + _t24*_t36 + _t24*_t45 + _t25*_t79 - _t27*_t76 + _t29*_t76 + _t30*_t41*_t5 + _t31*_t85 + _t43*_t82 - _t54*_t62 - _t54*_t66 + _t54*_t69 + _t58*_t64 - _t65*_t77 + _t68*_t77 + _t70*_t76 + _t71*_t83, 0);
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = my_piecewise3(_t7, -_hc0[5]*_t38 + _hc0[8]*_t61 + _hc1[2]*_t13*_t90 + _hc1[2]*_t26*_t76 + _hc1[2]*_t75 - _hc1[4]*_t48 - _hc1[4]*_t51 - _hc1[4]*_t56 + _hc1[5]*_t37 - _hc1[8]*_t59 + _t10*_t87 + _t10*_t94 + _t10*_t99 + _t15*_t88 - _t16*_t80 - _t19*_t81 + _t20*(-_hc0[8] + _hc1[8]) + _t28*_t40*_t50 + _t31*_t4*_t54*_t83 + _t34*_t5*_t53 + _t34*_t50*_t98 + _t34*_t54*_t89 + _t36*_t82 + _t40*_t5*_t95 + _t42*_t49 + _t43*_t52 + _t45*_t82 + _t54*_t79 + _t55*_t76 + _t57*_t85 + _t58*(0.2e1*_hc1[4] - _t39) - _t65*_t93 + _t68*_t93 + _t74*_t78 + _t77*_t89 - _t8*_t86 - _t8*_t92 - _t8*_t97 + _t90*_t91, 0);
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = my_piecewise3(_t7, _hc0[2]*_hc1[5]*_t60 + 0.12e2*_hc0[2]*_t19*_t91 + _hc0[5]*_hc1[2]*_t60 + _hc0[9]*_t61 + _hc1[9]*_t59 + _hc2[3]*_t2*_t5 + _t100*_t86 + _t100*_t92 + _t100*_t97 + _t101*_t35 + _t101*_t44 + _t102*_t87 + _t102*_t94 + _t102*_t99 + _t103*_t41*_t96 + _t104*_t13*_t19 + _t104*_t16 + _t105*_t36 + _t105*_t45 + _t106*_t57*_t83 + _t106*_t88 + _t20*(-_hc0[9] - _hc1[9]) + 0.4e1*_t4*_t53*_t95 + _t46*_t57*_t72*(-0.3e1*_hc0[2] - 0.3e1*_hc1[2]) + 0.6e1*_t53*_t55 + _t58*(-_t49 - _t52), 0);
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(D_1_k, _KMAX)(const xc_func_type *p, double k, double *out) {


  const double f = 0.028359261614488257*(k * k) + 0.022627416997969521*k + 0.0053173615527165481;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = 0.056718523228976513*k + 0.022627416997969521;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = 0.056718523228976513;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = 0;
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(D_2_k, _KMAX)(const xc_func_type *p, double k, double *out) {


  const double f = 0.1846304394851914*(k * k) + 0.1473137771194929*k + 0.0346182074034769;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = 0.3692608789703828*k + 0.1473137771194929;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = 0.3692608789703828;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = 0;
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(D_3_k, _KMAX)(const xc_func_type *p, double k, double *out) {


  const double f = 0.09576892532004281*(k * k) + 0.076412546917544731*k + 0.01795667349750801;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = 0.19153785064008562*k + 0.076412546917544731;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = 0.19153785064008562;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = 0;
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(D_4_k, _KMAX)(const xc_func_type *p, double k, double *out) {


  const double f = 0.1915378506400854*(k * k) + 0.1528250938350897*k + 0.03591334699501599;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = 0.3830757012801708*k + 0.1528250938350897;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = 0.3830757012801708;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = 0;
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(D_5_k, _KMAX)(const xc_func_type *p, double k, double *out) {


  const double f = 0.40106052394096008*(k * k) + 0.32000000000000001*k + 0.075198848238930015;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = 0.80212104788192016*k + 0.32000000000000001;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = 0.80212104788192016;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = 0;
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(D_6_k, _KMAX)(const xc_func_type *p, double k, double *out) {


  const double f = 0.5*(k * k) + 0.41070969677818546*k + 0.10532352447676886;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = 1.0*k + 0.41070969677818546;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = 1.0;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = 0;
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(D_7_k, _KMAX)(const xc_func_type *p, double k, double *out) {


  const double f = 0.78125*(k * k) + 0.62334731312723856*k + 0.146484375;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = 1.5625*k + 0.62334731312723856;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = 1.5625;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = 0;
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(D_8_k, _KMAX)(const xc_func_type *p, double k, double *out) {

  const double _t1 = 0.25*(k * k) + 0.25288291961698951*k + 0.072048583112714978;
  const double _t2 = xc_powr(_t1, 1, 2);
#if _KMAX >= 1
  const double _t3 = 0.25*k + 0.12644145980849475;
  const double _t4 = (0.1e1 / _t2);
#endif
#if _KMAX >= 2
  const double _t5 = xc_powr(_t1, -3, 2);
  const double _t6 = -_t3;
  const double _t7 = _t5*_t6;
#endif

  const double f = _t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = _t3*_t4;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = _t3*_t7 + 0.25*_t4;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = -0.25*_t3*_t5 + 0.5*_t7 + _t3*_t6*(-0.75*k - 0.37932437942548426)/xc_powr(_t1, 5, 2);
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(Q_1ud_k, _KMAX)(const xc_func_type *p, double k, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(D_1_k, _KMAX)(p, k, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(D_4_k, _KMAX)(p, k, _hc1);
  double _hc2[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(D_2_k, _KMAX)(p, k, _hc2);
  double _hc3[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(D_3_k, _KMAX)(p, k, _hc3);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = (0.1e1 / (k * k));
  const double _t3 = (0.1e1 / k);
  const double _t4 = log(k);
  const double _t5 = _t3*_t4;
  const double _t6 = log(_hc0[0]);
  const double _t7 = _hc3[0]*_t6;
  const double _t8 = 5.939656549519008*k + 2.3695801286664182;
  const double _t9 = atan(_t8);
  const double _t10 = _hc2[0]*_t9;
  const double _t11 = _hc1[0]*_t5 - _t10*_t3 + 0.2220173534761558*_t2 - _t3*_t7 + 0.89853746026347341*_t3 - 0.05118886552595877*k + 1.0150830754383912;
#if _KMAX >= 1
  const double _t12 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t13 = _t11*_t12;
  const double _t14 = (0.1e1 / (k * k * k));
  const double _t15 = _t3*_t6;
  const double _t16 = _hc3[0]*_t3;
  const double _t17 = _hc0[1]*_t1;
  const double _t18 = _t3*_t9;
  const double _t19 = (_t8 * _t8) + 0.1e1;
  const double _t20 = (0.1e1 / _t19);
  const double _t21 = _hc2[0]*_t20;
  const double _t22 = 5.939656549519008*_t3;
  const double _t23 = -_hc1[0]*_t2*_t4 + _hc1[0]*_t2 + _hc1[1]*_t3*_t4 + _hc2[0]*_t2*_t9 - _hc2[1]*_t18 + _hc3[0]*_t2*_t6 - _hc3[1]*_t15 - 0.4440347069523116*_t14 - _t16*_t17 - 0.89853746026347341*_t2 - _t21*_t22 - 0.05118886552595877;
#endif
#if _KMAX >= 2
  const double _t24 = ((_hc0[1]) * (_hc0[1]));
  const double _t25 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t26 = _t24*_t25;
  const double _t27 = _hc0[1]*_t12;
  const double _t28 = (0.1e1 / (k * k * k * k));
  const double _t29 = _hc1[0]*_t14;
  const double _t30 = 0.2e1*_t2;
  const double _t31 = _hc1[1]*_t30;
  const double _t32 = 0.2e1*_t14;
  const double _t33 = _hc3[1]*_t6;
  const double _t34 = _hc3[0]*_t17;
  const double _t35 = _t17*_t3;
  const double _t36 = _hc0[2]*_t1;
  const double _t37 = _hc2[1]*_t9;
  const double _t38 = _t12*_t24;
  const double _t39 = -70.559039852488096*k - 28.148984261687169;
  const double _t40 = (0.1e1 / (_t19 * _t19));
  const double _t41 = _hc1[2]*_t5 - _hc2[0]*_t22*_t39*_t40 - 11.879313099038016*_hc2[1]*_t20*_t3 - _hc2[2]*_t18 - 0.2e1*_hc3[1]*_t35 - _hc3[2]*_t15 - _t10*_t32 + 1.7970749205269468*_t14 - _t16*_t36 + _t16*_t38 + 11.879313099038016*_t2*_t21 + 1.3321041208569348*_t28 + 0.2e1*_t29*_t4 - 0.3e1*_t29 + _t30*_t33 + _t30*_t34 + _t30*_t37 - _t31*_t4 + _t31 - _t32*_t7;
#endif
#if _KMAX >= 3
  const double _t42 = 0.6e1*_t11;
  const double _t43 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t44 = 0.3e1*_t2;
  const double _t45 = 0.6e1*_t14;
  const double _t46 = 17.818969648557024*_t3;
#endif

  const double f = _t1*_t11;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = -_hc0[1]*_t13 + _t1*_t23;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = -_hc0[2]*_t13 + _t1*_t41 + 0.2e1*_t11*_t26 - 0.2e1*_t23*_t27;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = _hc0[1]*_hc0[2]*_t25*_t42 - 0.3e1*_hc0[2]*_t12*_t23 + _t1*(0.3e1*_hc0[1]*_hc0[2]*_hc3[0]*_t12*_t3 + 0.6e1*_hc0[1]*_hc3[1]*_t1*_t2 + 0.3e1*_hc0[2]*_hc3[0]*_t1*_t2 - 0.6e1*_hc1[0]*_t28*_t4 + 0.11e2*_hc1[0]*_t28 + 0.6e1*_hc1[1]*_t14*_t4 - 0.9e1*_hc1[1]*_t14 + 0.3e1*_hc1[2]*_t2 - _hc1[2]*_t4*_t44 + 17.818969648557024*_hc2[0]*_t2*_t39*_t40 + 0.6e1*_hc2[0]*_t28*_t9 + 419.09646318760362*_hc2[0]*_t3*_t40 - _hc2[0]*_t22*_t39*(-141.11807970497619*k - 56.297968523374338)/(_t19 * _t19 * _t19) + 35.637939297114048*_hc2[1]*_t2*_t20 - _hc2[1]*_t39*_t40*_t46 + 0.3e1*_hc2[2]*_t2*_t9 - _hc2[2]*_t20*_t46 + 0.6e1*_hc3[0]*_t28*_t6 - _hc3[0]*_t38*_t44 + 0.3e1*_hc3[1]*_t12*_t24*_t3 - 0.3e1*_hc3[1]*_t3*_t36 + 0.3e1*_hc3[2]*_t2*_t6 - 0.3e1*_hc3[2]*_t35 - 35.637939297114048*_t14*_t21 - 0.2e1*_t16*_t25*_t43 - 5.3912247615808405*_t28 - _t33*_t45 - _t34*_t45 - _t37*_t45 - 5.3284164834277392/xc_powi(k, 5)) + 0.6e1*_t23*_t26 - 0.3e1*_t27*_t41 - _t42*_t43/((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(Q_2ud_k, _KMAX)(const xc_func_type *p, double k, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(D_5_k, _KMAX)(p, k, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(D_6_k, _KMAX)(p, k, _hc1);
  const double _t1 = (0.1e1 / (k * k));
  const double _t2 = (0.1e1 / k);
  const double _t3 = log(_hc0[0]);
  const double _t4 = log(_hc1[0]);
  const double _t5 = 0.24690398117909756*_t4;
  const double _t6 = log(k);
  const double _t7 = 22.566445316250381*_t6;
  const double _t8 = k + 0.48225718199447272;
  const double _t9 = log(_t8);
  const double _t10 = 5.939656549519008*k + 2.3695801286664182;
  const double _t11 = atan(_t10);
#if _KMAX >= 1
  const double _t12 = (0.1e1 / (k * k * k));
  const double _t13 = 11.28322265812519*_t2;
  const double _t14 = (0.1e1 / (_hc0[0]));
  const double _t15 = _hc0[1]*_t14;
  const double _t16 = 0.24690398117909756*_t2;
  const double _t17 = (0.1e1 / (_hc1[0]));
  const double _t18 = _hc1[1]*_t17;
  const double _t19 = (0.1e1 / _t8);
  const double _t20 = 29.624002304690129*_t2;
  const double _t21 = (_t10 * _t10) + 0.1e1;
  const double _t22 = (0.1e1 / _t21);
  const double _t23 = 694.55399192939451*_t2;
#endif
#if _KMAX >= 2
  const double _t24 = (0.1e1 / (k * k * k * k));
  const double _t25 = _hc1[2]*_t17;
  const double _t26 = (0.1e1 / (_t8 * _t8));
  const double _t27 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t28 = ((_hc0[1]) * (_hc0[1]))*_t27;
  const double _t29 = (0.1e1 / ((_hc1[0]) * (_hc1[0])));
  const double _t30 = ((_hc1[1]) * (_hc1[1]));
  const double _t31 = -70.559039852488096*k - 28.148984261687169;
  const double _t32 = (0.1e1 / (_t21 * _t21));
#endif
#if _KMAX >= 3
  const double _t33 = 33.849667974375571*_t1;
  const double _t34 = 0.74071194353729267*_t1;
#endif

  const double f = -32.401470851677137*_t1 + 116.93504264748091*_t11*_t2 + 11.28322265812519*_t2*_t3 - _t2*_t5 - _t2*_t7 + 29.624002304690129*_t2*_t9 - 132.47909028779436*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = -116.93504264748091*_t1*_t11 - 11.28322265812519*_t1*_t3 + _t1*_t5 + _t1*_t7 - 29.624002304690129*_t1*_t9 + 109.91264497154397*_t1 + 64.802941703354274*_t12 + _t13*_t15 - _t16*_t18 + _t19*_t20 + _t22*_t23;
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = 11.28322265812519*_hc0[2]*_t14*_t2 + 0.49380796235819511*_hc1[1]*_t1*_t17 - 22.566445316250381*_t1*_t15 - 59.248004609380258*_t1*_t19 - 1389.107983858789*_t1*_t22 + 233.87008529496182*_t11*_t12 + 22.566445316250381*_t12*_t3 - 0.49380796235819511*_t12*_t4 - 45.132890632500761*_t12*_t6 + 59.248004609380258*_t12*_t9 - 197.25884462683757*_t12 - _t13*_t28 - _t16*_t25 + 0.24690398117909756*_t2*_t29*_t30 + 694.55399192939451*_t2*_t31*_t32 - _t20*_t26 - 194.40882511006282*_t24;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = -33.849667974375571*_hc0[1]*_hc0[2]*_t2*_t27 - _hc0[2]*_t14*_t33 + 0.74071194353729267*_hc1[1]*_hc1[2]*_t2*_t29 + 88.872006914070387*_t1*_t26 - 2083.6619757881835*_t1*_t31*_t32 - 701.61025588488546*_t11*_t24 + 67.699335948751142*_t12*_t15 - 1.4814238870745853*_t12*_t18 + 177.74401382814077*_t12*_t19 + 4167.323951576367*_t12*_t22 - 49007.062796250842*_t2*_t32 + 59.248004609380258*_t2/(_t8 * _t8 * _t8) - 67.699335948751142*_t24*_t3 + 1.4814238870745853*_t24*_t4 + 135.39867189750228*_t24*_t6 - 177.74401382814077*_t24*_t9 + 546.64364324801194*_t24 + _t25*_t34 + _t28*_t33 - _t29*_t30*_t34 + 777.63530044025128/xc_powi(k, 5) + _t23*_t31*(-141.11807970497619*k - 56.297968523374338)/(_t21 * _t21 * _t21) - 0.49380796235819511*((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t2/((_hc1[0]) * (_hc1[0]) * (_hc1[0])) + 22.566445316250381*((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t2/((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(Q_3ud_k, _KMAX)(const xc_func_type *p, double k, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(D_7_k, _KMAX)(p, k, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(D_8_k, _KMAX)(p, k, _hc1);
  const double _t1 = (0.1e1 / (k * k));
  const double _t2 = 42.649054489103107*_t1;
  const double _t3 = (0.1e1 / k);
  const double _t4 = log(_hc0[0]);
  const double _t5 = 14.565097171165967*_t4;
  const double _t6 = 0.78125*k + 0.32086695060795739;
  const double _t7 = atan(0.16004110557090127/_t6);
  const double _t8 = (0.1e1 / (_hc1[0]));
  const double _t9 = 0.47106059793499186*k + 0.26841867131910734;
  const double _t10 = _t8*_t9;
  const double _t11 = xc_atanh(_t10);
  const double _t12 = 13.284449507299844*_t11;
#if _KMAX >= 1
  const double _t13 = (0.1e1 / (k * k * k));
  const double _t14 = 14.565097171165967*_t3;
  const double _t15 = (0.1e1 / (_hc0[0]));
  const double _t16 = _hc0[1]*_t15;
  const double _t17 = (0.1e1 / (_t6 * _t6));
  const double _t18 = 0.025613155472356366*_t17 + 0.1e1;
  const double _t19 = (0.1e1 / _t18);
  const double _t20 = _t19*_t3;
  const double _t21 = (0.1e1 / ((_hc1[0]) * (_hc1[0])));
  const double _t22 = _t10 + 0.1e1;
  const double _t23 = (0.1e1 / _t22);
  const double _t24 = 0.1e1 - _t10;
  const double _t25 = (0.1e1 / _t24);
  const double _t26 = _t23*_t25;
  const double _t27 = _t26*_t3;
#endif
#if _KMAX >= 2
  const double _t28 = (0.1e1 / (k * k * k * k));
  const double _t29 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t30 = ((_hc0[1]) * (_hc0[1]))*_t29;
  const double _t31 = _t1*_t19;
  const double _t32 = xc_powi(_t6, -5);
  const double _t33 = (0.1e1 / (_t18 * _t18));
  const double _t34 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t35 = _hc1[1]*_t21;
  const double _t36 = -26.568899014599687*_t35*_t9 + 12.515561456291745*_t8;
  const double _t37 = 13.284449507299844*_t3;
  const double _t38 = (0.1e1 / (_t22 * _t22));
  const double _t39 = -_hc1[1]*_t21*_t9 + 0.47106059793499186*_t8;
  const double _t40 = -_t39;
  const double _t41 = (_t40 * _t40);
  const double _t42 = _t25*_t38*_t41;
  const double _t43 = (0.1e1 / (_t24 * _t24));
  const double _t44 = (_t39 * _t39);
  const double _t45 = _hc1[2]*_t21*_t9;
  const double _t46 = 0.94212119586998372*k + 0.53683734263821468;
  const double _t47 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t48 = ((_hc1[1]) * (_hc1[1]));
  const double _t49 = _t47*_t48;
#endif
#if _KMAX >= 3
  const double _t50 = 26.568899014599687*_t3*_t38;
  const double _t51 = -_t36;
  const double _t52 = 0.94212119586998372*_t35 + _t45;
  const double _t53 = _t46*_t47*_t48 - _t52;
  const double _t54 = _t37*_t39;
  const double _t55 = _t23*_t43*_t54;
#endif

  const double f = -_hc1[0]*_t2 - _t12*_t3 - _t3*_t5 + 111.81154810579779*_t3*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dk = 85.298108978206215*_hc1[0]*_t13 - _hc1[1]*_t2 + _t1*_t12 + _t1*_t5 - 111.81154810579779*_t1*_t7 - _t14*_t16 - 13.980034198785852*_t17*_t20 + _t27*(13.284449507299844*_hc1[1]*_t21*_t9 - 6.2577807281458724*_t8);
  out[1] = df_dk;
#endif
#if _KMAX >= 2
  const double d2f_dk2 = -_hc0[2]*_t14*_t15 - 255.89432693461864*_hc1[0]*_t28 + 170.59621795641243*_hc1[1]*_t13 - _hc1[2]*_t2 + 29.130194342331934*_t1*_t16 + _t1*_t26*_t36 - 26.568899014599687*_t11*_t13 - 29.130194342331934*_t13*_t4 + 223.62309621159558*_t13*_t7 + _t14*_t30 + 27.960068397571703*_t17*_t31 + 21.843803435602893*_t20*_t34 - _t23*_t37*_t43*_t44 + _t27*(12.515561456291745*_t35 + 13.284449507299844*_t45 - 13.284449507299844*_t46*_t49) - 0.55948873350368903*_t3*_t32*_t33 + _t37*_t42;
  out[2] = d2f_dk2;
#endif
#if _KMAX >= 3
  const double d3f_dk3 = 43.695291513497901*_hc0[1]*_hc0[2]*_t29*_t3 + 43.695291513497901*_hc0[2]*_t1*_t15 + 1023.5773077384746*_hc1[0]/xc_powi(k, 5) - 767.68298080385593*_hc1[1]*_t28 + 255.89432693461864*_hc1[2]*_t13 - _hc1[3]*_t2 + _t1*_t23*_t25*(-37.546684368875234*_t35 - 39.853348521899531*_t45 + 39.853348521899531*_t46*_t47*_t48) + 39.853348521899531*_t1*_t23*_t43*_t44 - 43.695291513497901*_t1*_t30 + 1.6784662005110671*_t1*_t32*_t33 - 39.853348521899531*_t1*_t42 + 79.706697043799062*_t11*_t28 - 87.390583026995802*_t13*_t16 - 83.880205192715109*_t13*_t17*_t19 + _t13*_t23*_t25*(79.706697043799062*_hc1[1]*_t21*_t9 - 37.546684368875234*_t8) - 51.19641430219428*_t20/(_t6 * _t6 * _t6 * _t6) + _t23*_t25*_t3*(-79.706697043799062*_hc1[1]*_hc1[2]*_t47*_t9 + 18.773342184437617*_hc1[2]*_t21 + 13.284449507299844*_hc1[3]*_t21*_t9 - 37.546684368875234*_t49 - 13.284449507299844*((_hc1[1]) * (_hc1[1]) * (_hc1[1]))*(-2.8263635876099512*k - 1.610512027914644)/((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]))) + _t23*_t3*_t44*_t51/(_t24 * _t24 * _t24) - _t25*_t38*_t54*(-_t46*_t49 + _t52) - _t25*_t40*_t50*_t53 + 87.390583026995802*_t28*_t4 - 670.86928863478673*_t28*_t7 + 3.0597040113482994*_t3*_t33/xc_powi(_t6, 6) - 65.531410306808679*_t31*_t34 - (_t40 * _t40 * _t40)*_t43*_t50 - _t53*_t55 - _t55*(-1.8842423917399674*_t35 - 0.2e1*_t45 + _t47*_t48*(1.8842423917399674*k + 1.0736746852764294)) + _t25*_t3*_t41*_t51/(_t22 * _t22 * _t22) - 0.044782099738317954*_t3/((_t18 * _t18 * _t18)*xc_powi(_t6, 8)) - 29.130194342331934*((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t3/((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  out[3] = d3f_dk3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ec_par_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1, _hc0);
  double _hc1[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(k_uu_k, _KMAX)(p, rs, z, _hc1);
  double _hc2[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_1ud_k, _KMAX)(p, _hc1[0], _hc2);
  double _hc3[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_2ud_k, _KMAX)(p, _hc1[0], _hc3);
  double _hc4[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_3ud_k, _KMAX)(p, _hc1[0], _hc4);
  double _hc5[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1, _hc5);
  double _hc6[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(k_dd_k, _KMAX)(p, rs, z, _hc6);
  double _hc7[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_1ud_k, _KMAX)(p, _hc6[0], _hc7);
  double _hc8[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_2ud_k, _KMAX)(p, _hc6[0], _hc8);
  double _hc9[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_3ud_k, _KMAX)(p, _hc6[0], _hc9);
  const double _t1 = _hc2[0] + _hc3[0] + _hc4[0];
  const double _t2 = (0.1e1 / 0.8e1)*_hc0[0] + 0.1e1 / 0.8e1;
  const double _t3 = _hc7[0] + _hc8[0] + _hc9[0];
  const double _t4 = (0.1e1 / 0.8e1)*_hc5[0] + 0.1e1 / 0.8e1;
#if _KMAX >= 1
  const double _t5 = (0.1e1 / 0.8e1)*_t1;
  const double _t6 = (0.1e1 / 0.8e1)*_t3;
  const double _t7 = _hc1[1]*_hc2[1] + _hc1[1]*_hc3[1] + _hc1[1]*_hc4[1];
  const double _t8 = _hc6[1]*_hc7[1] + _hc6[1]*_hc8[1] + _hc6[1]*_hc9[1];
  const double _t9 = _hc1[2]*_hc2[1] + _hc1[2]*_hc3[1] + _hc1[2]*_hc4[1];
  const double _t10 = _hc6[2]*_hc7[1] + _hc6[2]*_hc8[1] + _hc6[2]*_hc9[1];
#endif
#if _KMAX >= 2
  const double _t11 = (0.1e1 / 0.4e1)*_hc0[2];
  const double _t12 = (0.1e1 / 0.4e1)*_hc5[2];
  const double _t13 = ((_hc1[1]) * (_hc1[1]));
  const double _t14 = _hc1[3]*_hc2[1] + _hc1[3]*_hc3[1] + _hc1[3]*_hc4[1] + _hc2[2]*_t13 + _hc3[2]*_t13 + _hc4[2]*_t13;
  const double _t15 = ((_hc6[1]) * (_hc6[1]));
  const double _t16 = _hc6[3]*_hc7[1] + _hc6[3]*_hc8[1] + _hc6[3]*_hc9[1] + _hc7[2]*_t15 + _hc8[2]*_t15 + _hc9[2]*_t15;
  const double _t17 = (0.1e1 / 0.8e1)*_t9;
  const double _t18 = (0.1e1 / 0.8e1)*_t10;
  const double _t19 = _hc1[1]*_hc1[2];
  const double _t20 = _hc1[4]*_hc2[1] + _hc1[4]*_hc3[1] + _hc1[4]*_hc4[1] + _hc2[2]*_t19 + _hc3[2]*_t19 + _hc4[2]*_t19;
  const double _t21 = _hc6[1]*_hc6[2];
  const double _t22 = _hc6[4]*_hc7[1] + _hc6[4]*_hc8[1] + _hc6[4]*_hc9[1] + _hc7[2]*_t21 + _hc8[2]*_t21 + _hc9[2]*_t21;
  const double _t23 = ((_hc1[2]) * (_hc1[2]));
  const double _t24 = _hc1[5]*_hc2[1] + _hc1[5]*_hc3[1] + _hc1[5]*_hc4[1] + _hc2[2]*_t23 + _hc3[2]*_t23 + _hc4[2]*_t23;
  const double _t25 = ((_hc6[2]) * (_hc6[2]));
  const double _t26 = _hc6[5]*_hc7[1] + _hc6[5]*_hc8[1] + _hc6[5]*_hc9[1] + _hc7[2]*_t25 + _hc8[2]*_t25 + _hc9[2]*_t25;
#endif
#if _KMAX >= 3
  const double _t27 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t28 = _hc1[1]*_hc2[2];
  const double _t29 = 0.3e1*_hc1[3];
  const double _t30 = _hc1[1]*_t29;
  const double _t31 = ((_hc6[1]) * (_hc6[1]) * (_hc6[1]));
  const double _t32 = _hc6[1]*_hc7[2];
  const double _t33 = 0.3e1*_hc6[3];
  const double _t34 = _hc6[1]*_t33;
  const double _t35 = _hc1[2]*_hc1[3];
  const double _t36 = 0.2e1*_hc1[4];
  const double _t37 = _hc1[1]*_t36;
  const double _t38 = _hc1[2]*_t13;
  const double _t39 = _hc6[2]*_hc6[3];
  const double _t40 = 0.2e1*_hc6[4];
  const double _t41 = _hc6[1]*_t40;
  const double _t42 = _hc6[2]*_t15;
  const double _t43 = _hc1[1]*_hc1[5];
  const double _t44 = _hc1[2]*_t36;
  const double _t45 = _hc1[1]*_t23;
  const double _t46 = _hc6[1]*_hc6[5];
  const double _t47 = _hc6[2]*_t40;
  const double _t48 = _hc6[1]*_t25;
  const double _t49 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t50 = 0.3e1*_hc1[2]*_hc1[5];
  const double _t51 = ((_hc6[2]) * (_hc6[2]) * (_hc6[2]));
  const double _t52 = 0.3e1*_hc6[2]*_hc6[5];
#endif

  const double f = _t1*_t2 + _t3*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[2]*_t5 - _hc5[2]*_t6 + _t2*_t7 + _t4*_t8;
  out[1] = df_dz;
  const double df_drs = _t10*_t4 + _t2*_t9;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[5]*_t5 + _hc5[5]*_t6 + _t11*_t7 - _t12*_t8 + _t14*_t2 + _t16*_t4;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[2]*_t17 - _hc5[2]*_t18 + _t2*_t20 + _t22*_t4;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _t2*_t24 + _t26*_t4;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = (0.3e1 / 0.8e1)*_hc0[2]*_t14 + (0.3e1 / 0.8e1)*_hc0[5]*_t7 + _hc0[9]*_t5 - 0.3e1 / 0.8e1*_hc5[2]*_t16 + (0.3e1 / 0.8e1)*_hc5[5]*_t8 - _hc5[9]*_t6 + _t2*(_hc1[6]*_hc2[1] + _hc1[6]*_hc3[1] + _hc1[6]*_hc4[1] + _hc2[3]*_t27 + _hc3[2]*_t30 + _hc3[3]*_t27 + _hc4[2]*_t30 + _hc4[3]*_t27 + _t28*_t29) + _t4*(_hc6[6]*_hc7[1] + _hc6[6]*_hc8[1] + _hc6[6]*_hc9[1] + _hc7[3]*_t31 + _hc8[2]*_t34 + _hc8[3]*_t31 + _hc9[2]*_t34 + _hc9[3]*_t31 + _t32*_t33);
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[5]*_t17 + _hc5[5]*_t18 + _t11*_t20 - _t12*_t22 + _t2*(_hc1[7]*_hc2[1] + _hc1[7]*_hc3[1] + _hc1[7]*_hc4[1] + _hc2[2]*_t35 + _hc2[3]*_t38 + _hc3[2]*_t35 + _hc3[2]*_t37 + _hc3[3]*_t38 + _hc4[2]*_t35 + _hc4[2]*_t37 + _hc4[3]*_t38 + _t28*_t36) + _t4*(_hc6[7]*_hc7[1] + _hc6[7]*_hc8[1] + _hc6[7]*_hc9[1] + _hc7[2]*_t39 + _hc7[3]*_t42 + _hc8[2]*_t39 + _hc8[2]*_t41 + _hc8[3]*_t42 + _hc9[2]*_t39 + _hc9[2]*_t41 + _hc9[3]*_t42 + _t32*_t40);
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = (0.1e1 / 0.8e1)*_hc0[2]*_t24 - 0.1e1 / 0.8e1*_hc5[2]*_t26 + _t2*(_hc1[8]*_hc2[1] + _hc1[8]*_hc3[1] + _hc1[8]*_hc4[1] + _hc2[2]*_t43 + _hc2[2]*_t44 + _hc2[3]*_t45 + _hc3[2]*_t43 + _hc3[2]*_t44 + _hc3[3]*_t45 + _hc4[2]*_t43 + _hc4[2]*_t44 + _hc4[3]*_t45) + _t4*(_hc6[8]*_hc7[1] + _hc6[8]*_hc8[1] + _hc6[8]*_hc9[1] + _hc7[2]*_t46 + _hc7[2]*_t47 + _hc7[3]*_t48 + _hc8[2]*_t46 + _hc8[2]*_t47 + _hc8[3]*_t48 + _hc9[2]*_t46 + _hc9[2]*_t47 + _hc9[3]*_t48);
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _t2*(_hc1[9]*_hc2[1] + _hc1[9]*_hc3[1] + _hc1[9]*_hc4[1] + _hc2[2]*_t50 + _hc2[3]*_t49 + _hc3[2]*_t50 + _hc3[3]*_t49 + _hc4[2]*_t50 + _hc4[3]*_t49) + _t4*(_hc6[9]*_hc7[1] + _hc6[9]*_hc8[1] + _hc6[9]*_hc9[1] + _hc7[2]*_t52 + _hc7[3]*_t51 + _hc8[2]*_t52 + _hc8[3]*_t51 + _hc9[2]*_t52 + _hc9[3]*_t51);
  out[9] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(k_fs_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(0.18e2, 1, 3)*M_CBRTPI;
  const double _t2 = (0.1e1 / 0.2e1)*_t1;

  const double f = _t2/rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t2/(rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1/(rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.3e1*_t1/(rs * rs * rs * rs);
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(k_ud_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(beta_eff_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(k_fs_z0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = _hc0[0]*_hc1[0];
  const double _t2 = 1.0*_t1 - 9.9999999999999994e-12 > 0;

  const double f = my_piecewise3(_t2, _t1, 9.9999999999999994e-12);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = my_piecewise3(_t2, _hc0[0]*_hc1[1] + _hc0[1]*_hc1[0], 0);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = my_piecewise3(_t2, _hc0[0]*_hc1[2] + 0.2e1*_hc0[1]*_hc1[1] + _hc0[2]*_hc1[0], 0);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = my_piecewise3(_t2, _hc0[0]*_hc1[3] + 0.3e1*_hc0[1]*_hc1[2] + 0.3e1*_hc0[2]*_hc1[1] + _hc0[3]*_hc1[0], 0);
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ss_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_r_k, _KMAX)(p, rs, _hc0);

  const double f = 0.71948800000000007*_hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.71948800000000007*_hc0[1];
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.71948800000000007*_hc0[2];
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.71948800000000007*_hc0[3];
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_gen_z0_k, _KMAX)(const xc_func_type *p, double n, double *out) {


  const double f = 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = 0;
  out[1] = df_dn;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = 0;
  out[2] = d2f_dn2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = 0;
  out[3] = d3f_dn3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(alpha_z_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_gen_z0_k, _KMAX)(p, 0, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ss_z0_k, _KMAX)(p, rs, _hc1);

  const double f = (0.1e1 / (_hc0[0]));
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0;
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
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(alpha_eff_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(alpha_n_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(alpha_z_z0_k, _KMAX)(p, rs, _hc1);

  const double f = _hc0[0]*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[0]*_hc1[1] + _hc0[1]*_hc1[0];
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[0]*_hc1[2] + 0.2e1*_hc0[1]*_hc1[1] + _hc0[2]*_hc1[0];
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[0]*_hc1[3] + 0.3e1*_hc0[1]*_hc1[2] + 0.3e1*_hc0[2]*_hc1[1] + _hc0[3]*_hc1[0];
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(k_dd_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(alpha_eff_z0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(k_fs_z0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = _hc0[0]*_hc1[0];
  const double _t2 = 1.0*_t1 - 9.9999999999999994e-12 > 0;

  const double f = my_piecewise3(_t2, _t1, 9.9999999999999994e-12);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = my_piecewise3(_t2, _hc0[0]*_hc1[1] + _hc0[1]*_hc1[0], 0);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = my_piecewise3(_t2, _hc0[0]*_hc1[2] + 0.2e1*_hc0[1]*_hc1[1] + _hc0[2]*_hc1[0], 0);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = my_piecewise3(_t2, _hc0[0]*_hc1[3] + 0.3e1*_hc0[1]*_hc1[2] + 0.3e1*_hc0[2]*_hc1[1] + _hc0[3]*_hc1[0], 0);
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(k_uu_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(alpha_eff_z0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(k_fs_z0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = _hc0[0]*_hc1[0];
  const double _t2 = 1.0*_t1 - 9.9999999999999994e-12 > 0;

  const double f = my_piecewise3(_t2, _t1, 9.9999999999999994e-12);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = my_piecewise3(_t2, _hc0[0]*_hc1[1] + _hc0[1]*_hc1[0], 0);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = my_piecewise3(_t2, _hc0[0]*_hc1[2] + 0.2e1*_hc0[1]*_hc1[1] + _hc0[2]*_hc1[0], 0);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = my_piecewise3(_t2, _hc0[0]*_hc1[3] + 0.3e1*_hc0[1]*_hc1[2] + 0.3e1*_hc0[2]*_hc1[1] + _hc0[3]*_hc1[0], 0);
  out[3] = d3f_drs3;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ec_par_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(k_dd_z0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_1ud_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(k_uu_z0_k, _KMAX)(p, rs, _hc2);
  double _hc3[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_1ud_k, _KMAX)(p, _hc2[0], _hc3);
  double _hc4[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_2ud_k, _KMAX)(p, _hc0[0], _hc4);
  double _hc5[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_2ud_k, _KMAX)(p, _hc2[0], _hc5);
  double _hc6[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_3ud_k, _KMAX)(p, _hc0[0], _hc6);
  double _hc7[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_3ud_k, _KMAX)(p, _hc2[0], _hc7);
#if _KMAX >= 1
  const double _t1 = (0.1e1 / 0.8e1)*_hc0[1];
  const double _t2 = (0.1e1 / 0.8e1)*_hc2[1];
#endif
#if _KMAX >= 2
  const double _t3 = (0.1e1 / 0.8e1)*_hc0[2];
  const double _t4 = (0.1e1 / 0.8e1)*_hc2[2];
  const double _t5 = (0.1e1 / 0.8e1)*((_hc0[1]) * (_hc0[1]));
  const double _t6 = (0.1e1 / 0.8e1)*((_hc2[1]) * (_hc2[1]));
#endif
#if _KMAX >= 3
  const double _t7 = (0.1e1 / 0.8e1)*_hc0[3];
  const double _t8 = (0.1e1 / 0.8e1)*_hc2[3];
  const double _t9 = (0.3e1 / 0.8e1)*_hc0[1]*_hc0[2];
  const double _t10 = (0.3e1 / 0.8e1)*_hc2[1]*_hc2[2];
  const double _t11 = (0.1e1 / 0.8e1)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t12 = (0.1e1 / 0.8e1)*((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
#endif

  const double f = (0.1e1 / 0.8e1)*_hc1[0] + (0.1e1 / 0.8e1)*_hc3[0] + (0.1e1 / 0.8e1)*_hc4[0] + (0.1e1 / 0.8e1)*_hc5[0] + (0.1e1 / 0.8e1)*_hc6[0] + (0.1e1 / 0.8e1)*_hc7[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc1[1]*_t1 + _hc3[1]*_t2 + _hc4[1]*_t1 + _hc5[1]*_t2 + _hc6[1]*_t1 + _hc7[1]*_t2;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc1[1]*_t3 + _hc1[2]*_t5 + _hc3[1]*_t4 + _hc3[2]*_t6 + _hc4[1]*_t3 + _hc4[2]*_t5 + _hc5[1]*_t4 + _hc5[2]*_t6 + _hc6[1]*_t3 + _hc6[2]*_t5 + _hc7[1]*_t4 + _hc7[2]*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc1[1]*_t7 + _hc1[2]*_t9 + _hc1[3]*_t11 + _hc3[1]*_t8 + _hc3[2]*_t10 + _hc3[3]*_t12 + _hc4[1]*_t7 + _hc4[2]*_t9 + _hc4[3]*_t11 + _hc5[1]*_t8 + _hc5[2]*_t10 + _hc5[3]*_t12 + _hc6[1]*_t7 + _hc6[2]*_t9 + _hc6[3]*_t11 + _hc7[1]*_t8 + _hc7[2]*_t10 + _hc7[3]*_t12;
  out[3] = d3f_drs3;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3)/M_CBRTPI;
  const double _t2 = (0.1e1 / 0.2e1)*_t1/xc_powr(na, 1, 3);
  double _hc0[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(k_ud_z0_k, _KMAX)(p, _t2, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_1ud_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_2ud_k, _KMAX)(p, _hc0[0], _hc2);
  double _hc3[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_3ud_k, _KMAX)(p, _hc0[0], _hc3);
  double _hc4[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ec_par_z0_k, _KMAX)(p, _t2, _hc4);
  const double _t3 = na*((0.1e1 / 0.4e1)*_hc1[0] + (0.1e1 / 0.4e1)*_hc2[0] + (0.1e1 / 0.4e1)*_hc3[0] + _hc4[0]);
  const double zk = _t3;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t4 = (na * na);
  const double _t5 = xc_powr(na, -4, 3);
  const double _t10 = (0.1e1 / 0.24e2)*_t5;
  const double _t6 = _hc4[1]*_t1;
  const double _t7 = _t5*_t6;
  const double _t8 = _hc0[1]*_t1;
  const double _t9 = _hc1[1]*_t8;
  const double _t11 = _t10*_t8;
  const double _t12 = -_hc2[1]*_t11 - _hc3[1]*_t11 - _t10*_t9 - 0.1e1 / 0.6e1*_t7;
  const double dF_dna = _t12*_t4 + 0.2e1*_t3;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t13 = xc_powr(na, -7, 3);
  const double _t14 = xc_powr(na, -8, 3);
  const double _t15 = xc_powr(0.6e1, 2, 3);
  const double _t16 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t18 = (0.1e1 / 0.18e2)*_t13;
  const double _t20 = (0.1e1 / 0.144e3)*_t14;
  const double _t21 = _t15*_t16;
  const double _t17 = _hc4[2]*_t15*_t16;
  const double _t19 = _t18*_t8;
  const double _t22 = _hc0[2]*_t21;
  const double _t23 = _hc1[1]*_t22;
  const double _t24 = _t20*_t22;
  const double _t25 = ((_hc0[1]) * (_hc0[1]))*_t21;
  const double _t26 = _t20*_t25;
  const double _t27 = _hc1[2]*_t26 + _hc2[1]*_t19 + _hc2[1]*_t24 + _hc2[2]*_t26 + _hc3[1]*_t19 + _hc3[1]*_t24 + _hc3[2]*_t26 + (0.2e1 / 0.9e1)*_t13*_t6 + (0.1e1 / 0.36e2)*_t14*_t17 + _t18*_t9 + _t20*_t23;
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc1[0] + (0.1e1 / 0.2e1)*_hc2[0] + (0.1e1 / 0.2e1)*_hc3[0] + 0.2e1*_hc4[0] + 0.4e1*_t12*na + _t27*_t4;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / 0.4e1)*_t5;
  const double _t30 = 0.1e1/(M_PI*(na * na * na * na));
  const double _t31 = (0.1e1 / 0.144e3)*_t30;
  const double _t34 = xc_powr(na, -10, 3);
  const double _t35 = xc_powr(na, -11, 3);
  const double _t37 = (0.7e1 / 0.54e2)*_t34;
  const double _t39 = (0.1e1 / 0.36e2)*_t35;
  const double _t29 = _t28*_t8;
  const double _t32 = _hc0[3]*_t31;
  const double _t33 = (0.1e1 / 0.48e2)*_hc0[1]*_hc0[2]*_t30;
  const double _t36 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t31;
  const double _t38 = _t37*_t8;
  const double _t40 = _t22*_t39;
  const double _t41 = _t25*_t39;
  const double d3F_dna3 = -_hc2[1]*_t29 - _hc3[1]*_t29 + 0.6e1*_t27*na - _t28*_t9 + _t4*(-_hc1[1]*_t32 - _hc1[2]*_t33 - _hc1[2]*_t41 - _hc1[3]*_t36 - _hc2[1]*_t32 - _hc2[1]*_t38 - _hc2[1]*_t40 - _hc2[2]*_t33 - _hc2[2]*_t41 - _hc2[3]*_t36 - _hc3[1]*_t32 - _hc3[1]*_t38 - _hc3[1]*_t40 - _hc3[2]*_t33 - _hc3[2]*_t41 - _hc3[3]*_t36 - 0.1e1 / 0.36e2*_hc4[3]*_t30 - 0.1e1 / 0.9e1*_t17*_t35 - _t23*_t39 - 0.14e2 / 0.27e2*_t34*_t6 - _t37*_t9) - _t7;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4/xc_powr(_t1, 1, 3);
  const double _t6 = na - nb;
  const double _t7 = (0.1e1 / _t1);
  const double _t8 = _t6*_t7;
  const double _t10 = (_t1 * _t1);
  const double _t11 = (0.1e1 / _t10);
  double _hc0[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(k_ud_k, _KMAX)(p, _t5, _t8, _hc0);
  double _hc1[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_1ud_k, _KMAX)(p, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_2ud_k, _KMAX)(p, _hc0[0], _hc2);
  double _hc3[(_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(Q_3ud_k, _KMAX)(p, _hc0[0], _hc3);
  double _hc4[(_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(ec_par_k, _KMAX)(p, _t5, _t8, _hc4);
  const double _t9 = _hc1[0] + _hc2[0] + _hc3[0];
  const double _t12 = _t11*_t9;
  const double _t13 = _t12*nb;
  const double _t14 = _hc4[0] + _t13*na;
  const double zk = _t1*_t14;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t15 = 0.2e1*na;
  const double _t16 = 0.2e1*nb;
  const double _t17 = _t15 + _t16;
  const double _t19 = _t11*_t6;
  const double _t20 = -_t19 + _t7;
  const double _t22 = _t4/xc_powr(_t1, 4, 3);
  const double _t23 = (0.1e1 / 0.6e1)*_t22;
  const double _t27 = _t11*na;
  const double _t30 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t36 = -_t19 - _t7;
  const double _t41 = _t27*nb;
  const double _t18 = _t14*_t17;
  const double _t21 = _hc4[1]*_t20;
  const double _t24 = -_hc0[2]*_t23;
  const double _t25 = _hc0[1]*_t20 + _t24;
  const double _t26 = _hc1[1]*_t25 + _hc2[1]*_t25 + _hc3[1]*_t25;
  const double _t28 = _t26*_t27;
  const double _t29 = _t28*nb;
  const double _t31 = _t30*_t9;
  const double _t32 = _t15*_t31;
  const double _t33 = _hc4[2]*_t22;
  const double _t34 = -_t32*nb - 0.1e1 / 0.6e1*_t33;
  const double _t35 = _t13 + _t21 + _t29 + _t34;
  const double _t37 = _hc4[1]*_t36;
  const double _t38 = _t12*na;
  const double _t39 = _hc0[1]*_t36 + _t24;
  const double _t40 = _hc1[1]*_t39 + _hc2[1]*_t39 + _hc3[1]*_t39;
  const double _t42 = _t40*_t41;
  const double _t43 = _t34 + _t37 + _t38 + _t42;
  const double dF_dna = _t10*_t35 + _t18;
  const double dF_dnb = _t10*_t43 + _t18;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t44 = 0.2e1*_t11;
  const double _t45 = 0.2e1*_t30;
  const double _t46 = _t45*_t6;
  const double _t47 = -_t44 + _t46;
  const double _t51 = _t11*_t16;
  const double _t54 = xc_powr(_t1, -7, 3);
  const double _t55 = (0.2e1 / 0.9e1)*_t54;
  const double _t71 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t72 = 0.6e1*_t71;
  const double _t74 = _t4*_t55;
  const double _t80 = _t11*nb;
  const double _t89 = _t15*nb;
  const double _t95 = _t44 + _t46;
  const double _t101 = 0.4e1*_t30;
  const double _t48 = -_hc4[4]*_t23;
  const double _t49 = _hc4[3]*_t20 + _t48;
  const double _t50 = 0.4e1*_t31;
  const double _t52 = (_t25 * _t25);
  const double _t53 = _hc0[2]*_t4;
  const double _t56 = _t53*_t55;
  const double _t57 = _hc0[1]*_t47;
  const double _t58 = -_hc0[5]*_t23;
  const double _t59 = _hc0[4]*_t20 + _t58;
  const double _t60 = -_hc0[4]*_t23;
  const double _t61 = _hc0[3]*_t20 + _t60;
  const double _t62 = _t20*_t61;
  const double _t63 = -_t23*_t59 + _t56 + _t57 + _t62;
  const double _t64 = _hc1[1]*_t63 + _hc1[2]*_t52 + _hc2[1]*_t63 + _hc2[2]*_t52 + _hc3[1]*_t63 + _hc3[2]*_t52;
  const double _t65 = _t27*_t64;
  const double _t66 = _t26*_t30;
  const double _t67 = 0.4e1*_t66;
  const double _t68 = _t67*na;
  const double _t69 = -_hc4[5]*_t23;
  const double _t70 = _hc4[4]*_t20 + _t69;
  const double _t73 = _t72*_t9*na;
  const double _t75 = _hc4[2]*_t74 + _t73*nb;
  const double _t76 = _hc4[1]*_t47 + _t20*_t49 - _t23*_t70 + _t26*_t51 - _t50*nb + _t65*nb - _t68*nb + _t75;
  const double _t77 = _t17*_t35;
  const double _t78 = 0.2e1*_hc4[0] + _t13*_t15;
  const double _t79 = _hc4[3]*_t36 + _t48;
  const double _t81 = _t40*_t80;
  const double _t82 = _t25*_t39;
  const double _t83 = _hc0[3]*_t36 + _t60;
  const double _t84 = _t20*_t83;
  const double _t85 = _hc0[4]*_t36 + _t58;
  const double _t86 = -_t23*_t85 + _t56;
  const double _t87 = _hc0[1]*_t46 + _t84 + _t86;
  const double _t88 = _hc1[1]*_t87 + _hc1[2]*_t82 + _hc2[1]*_t87 + _hc2[2]*_t82 + _hc3[1]*_t87 + _hc3[2]*_t82;
  const double _t90 = _t40*nb;
  const double _t91 = _hc4[4]*_t36 + _t69;
  const double _t92 = -_t23*_t91 + _t75;
  const double _t93 = _hc4[1]*_t46 + _t12 - _t15*_t30*_t90 - _t16*_t31 + _t20*_t79 + _t28 - _t32 + _t41*_t88 - _t66*_t89 + _t81 + _t92;
  const double _t94 = _t17*_t43;
  const double _t96 = (_t39 * _t39);
  const double _t97 = _hc0[1]*_t95;
  const double _t98 = _t36*_t83;
  const double _t99 = _t86 + _t97 + _t98;
  const double _t100 = _hc1[1]*_t99 + _hc1[2]*_t96 + _hc2[1]*_t99 + _hc2[2]*_t96 + _hc3[1]*_t99 + _hc3[2]*_t96;
  const double _t102 = _t101*_t90;
  const double _t103 = _hc4[1]*_t95 + _t100*_t41 - _t102*na + _t11*_t15*_t40 + _t36*_t79 - _t50*na + _t92;
  const double d2F_dna2 = _t10*_t76 + 0.2e1*_t77 + _t78;
  const double d2F_dna_dnb = _t10*_t93 + _t77 + _t78 + _t94;
  const double d2F_dnb2 = _t10*_t103 + _t78 + 0.2e1*_t94;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t104 = 0.6e1*_t30;
  const double _t105 = _t6*_t72;
  const double _t106 = _t104 - _t105;
  const double _t111 = 0.2e1*_t47;
  const double _t112 = 0.12e2*nb;
  const double _t119 = (0.4e1 / 0.9e1)*_t54;
  const double _t121 = (0.1e1 / 0.3e1)*_t22;
  const double _t123 = (0.14e2 / 0.27e2)/xc_powr(_t1, 10, 3);
  const double _t126 = _t119*_t4;
  const double _t134 = na*nb;
  const double _t135 = _t104*_t134;
  const double _t143 = _t112*na;
  const double _t145 = -_t105 + 0.2e1*_t30;
  const double _t159 = _t30*_t89;
  const double _t175 = -_t104 - _t105;
  const double _t176 = 0.2e1*_t95;
  const double _t107 = _hc4[4]*_t74;
  const double _t108 = -_hc4[8]*_t23;
  const double _t109 = _hc4[7]*_t20 + _t108;
  const double _t110 = -_hc4[7]*_t23;
  const double _t113 = _t71*_t9;
  const double _t114 = 0.18e2*_t113;
  const double _t115 = (_t25 * _t25 * _t25);
  const double _t116 = _hc1[2]*_t25;
  const double _t117 = _hc2[2]*_t25;
  const double _t118 = _hc3[2]*_t25;
  const double _t120 = _t119*_t53;
  const double _t122 = _t120 - _t121*_t59 + 0.2e1*_t57 + 0.2e1*_t62;
  const double _t124 = _t123*_t53;
  const double _t125 = -_t124;
  const double _t127 = _hc0[5]*_t74;
  const double _t128 = -_hc0[9]*_t23;
  const double _t129 = -_hc0[8]*_t23;
  const double _t130 = _hc0[7]*_t20 + _t129;
  const double _t131 = _hc0[4]*_t74;
  const double _t132 = -_hc0[7]*_t23;
  const double _t133 = _hc0[1]*_t106 + _t111*_t61 + _t125 + _t126*_t59 + _t20*(_hc0[3]*_t47 - _t130*_t23 + _t131 + _t20*(_hc0[6]*_t20 + _t132)) - _t23*(_hc0[4]*_t47 + _t127 + _t130*_t20 - _t23*(_hc0[8]*_t20 + _t128));
  const double _t136 = _t26*_t71;
  const double _t137 = _hc4[5]*_t74;
  const double _t138 = -_hc4[9]*_t23;
  const double _t139 = 0.24e2*_t134*_t9/xc_powi(_t1, 5);
  const double _t140 = _hc4[2]*_t123*_t4;
  const double _t141 = -_t139 - _t140;
  const double _t142 = _t17*_t76;
  const double _t144 = -_t143*_t31 - _t33;
  const double _t146 = _hc4[6]*_t36 + _t110;
  const double _t147 = _hc4[7]*_t36 + _t108;
  const double _t148 = _t107 - _t147*_t23;
  const double _t149 = _t39*_t52;
  const double _t150 = _t120 - _t121*_t85;
  const double _t151 = _hc0[1]*_t101*_t6 + _t150 + 0.2e1*_t84;
  const double _t152 = _t39*_t63;
  const double _t153 = _hc0[7]*_t36 + _t129;
  const double _t154 = _t127 - _t23*(_hc0[8]*_t36 + _t128);
  const double _t155 = _hc0[6]*_t36 + _t132;
  const double _t156 = _t131 - _t153*_t23;
  const double _t157 = _hc0[1]*_t145 + _t125 + _t20*(_hc0[3]*_t46 + _t155*_t20 + _t156) - _t23*(_hc0[4]*_t46 + _t153*_t20 + _t154) + _t46*_t61 + _t47*_t83 + _t59*_t74 + _t74*_t85;
  const double _t158 = _t101*_t134*_t88;
  const double _t160 = _t90*na;
  const double _t161 = _t137 - _t23*(_hc4[8]*_t36 + _t138);
  const double _t162 = _t144 + 0.2e1*_t17*_t93;
  const double _t163 = _t40*na;
  const double _t164 = _t23*(_hc4[4]*_t95 + _t147*_t36 + _t161);
  const double _t165 = _hc4[3]*_t95 + _t146*_t36 + _t148;
  const double _t166 = _t25*_t96;
  const double _t167 = _hc1[2]*_t39;
  const double _t168 = 0.2e1*_t87;
  const double _t169 = _hc2[2]*_t39;
  const double _t170 = _hc3[2]*_t39;
  const double _t171 = _t23*(_hc0[4]*_t95 + _t153*_t36 + _t154);
  const double _t172 = _hc0[3]*_t95 + _t155*_t36 + _t156;
  const double _t173 = -_hc0[1]*_t105 - _hc0[1]*_t45 - _t124 - _t171 + _t172*_t20 + (0.4e1 / 0.9e1)*_t2*_t3*_t54*_t85 + 0.4e1*_t30*_t6*_t83;
  const double _t174 = _t103*_t17;
  const double _t177 = (_t39 * _t39 * _t39);
  const double _t178 = _t150 + 0.2e1*_t97 + 0.2e1*_t98;
  const double _t179 = _hc0[1]*_t175 + _t125 + _t126*_t85 - _t171 + _t172*_t36 + _t176*_t83;
  const double d3F_dna3 = _t10*(_hc4[1]*_t106 + _t111*_t49 - _t112*_t66 + _t114*nb + _t126*_t70 + 0.18e2*_t134*_t136 - _t135*_t64 + _t141 + _t20*(_hc4[3]*_t47 + _t107 - _t109*_t23 + _t20*(_hc4[6]*_t20 + _t110)) - _t23*(_hc4[4]*_t47 + _t109*_t20 + _t137 - _t23*(_hc4[8]*_t20 + _t138)) + _t41*(_hc1[1]*_t133 + _hc1[3]*_t115 + _hc2[1]*_t133 + _hc2[3]*_t115 + _hc3[1]*_t133 + _hc3[3]*_t115 + _t116*_t122 + _t116*_t63 + _t117*_t122 + _t117*_t63 + _t118*_t122 + _t118*_t63) + 0.3e1*_t64*_t80) + 0.6e1*_t13 + 0.3e1*_t142 + _t144 + 0.6e1*_t21 + 0.6e1*_t29;
  const double d3F_dna2_dnb = _t10*(_hc4[1]*_t145 - _t102 + _t112*_t113 + _t136*_t143 + _t141 - _t158 - _t159*_t64 + _t160*_t72 + _t20*(_hc4[3]*_t46 + _t146*_t20 + _t148) - _t23*(_hc4[4]*_t46 + _t147*_t20 + _t161) + _t26*_t44 + _t41*(_hc1[1]*_t157 + _hc1[2]*_t152 + _hc1[3]*_t149 + _hc2[1]*_t157 + _hc2[2]*_t152 + _hc2[3]*_t149 + _hc3[1]*_t157 + _hc3[2]*_t152 + _hc3[3]*_t149 + _t116*_t151 + _t117*_t151 + _t118*_t151) + _t46*_t49 + _t47*_t79 - _t50 + _t51*_t88 + _t65 - _t67*nb - _t68 + _t70*_t74 + _t73 + _t74*_t91) + _t12*_t15 + 0.4e1*_t13 + _t142 + _t15*_t81 + _t162 + 0.4e1*_t21 + 0.4e1*_t29 + 0.2e1*_t37;
  const double d3F_dna_dnb2 = _t10*(-_hc4[1]*_t105 - _hc4[1]*_t45 + _t100*_t11*nb - _t100*_t159 - _t101*_t163 - _t102 + 0.2e1*_t11*_t40 + 0.2e1*_t11*_t88*na + _t11*na*nb*(_hc1[1]*_t173 + _hc1[3]*_t166 + _hc2[1]*_t173 + _hc2[3]*_t166 + _hc3[1]*_t173 + _hc3[3]*_t166 + _t116*_t99 + _t117*_t99 + _t118*_t99 + _t167*_t168 + _t168*_t169 + _t168*_t170) - _t139 - _t140 - _t158 - _t164 + _t165*_t20 + (0.4e1 / 0.9e1)*_t2*_t3*_t54*_t91 + 0.6e1*_t26*_t71*na*nb + 0.4e1*_t30*_t6*_t79 + 0.12e2*_t40*_t71*na*nb - _t50 - _t68 + 0.12e2*_t71*_t9*na + 0.6e1*_t71*_t9*nb) + _t12*_t16 + _t15*_t26*_t80 + _t162 + _t174 + 0.2e1*_t21 + 0.4e1*_t37 + 0.4e1*_t38 + 0.4e1*_t42;
  const double d3F_dnb3 = _t10*(_hc4[1]*_t175 - _t100*_t135 + 0.3e1*_t100*_t27 + _t114*na + _t126*_t91 + _t141 + 0.18e2*_t160*_t71 - 0.12e2*_t163*_t30 - _t164 + _t165*_t36 + _t176*_t79 + _t41*(_hc1[1]*_t179 + _hc1[3]*_t177 + _hc2[1]*_t179 + _hc2[3]*_t177 + _hc3[1]*_t179 + _hc3[3]*_t177 + _t167*_t178 + _t167*_t99 + _t169*_t178 + _t169*_t99 + _t170*_t178 + _t170*_t99)) + _t144 + 0.3e1*_t174 + 0.6e1*_t37 + 0.6e1*_t38 + 0.6e1*_t42;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#endif
}
#endif