/*
  Generated from python/lda_exc/lda_x_erf.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_x_erf
*/

#ifndef _LDA_X_ERF_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_X_ERF_KERNEL_BODY
#define _KMAX 0
#define _LDA_X_ERF_HELPER_BODIES
#include "lda_x_erf.c"
#undef _LDA_X_ERF_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_X_ERF_HELPER_BODIES
#include "lda_x_erf.c"
#undef _LDA_X_ERF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_X_ERF_HELPER_BODIES
#include "lda_x_erf.c"
#undef _LDA_X_ERF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_X_ERF_HELPER_BODIES
#include "lda_x_erf.c"
#undef _LDA_X_ERF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_X_ERF_HELPER_BODIES
#include "lda_x_erf.c"
#undef _LDA_X_ERF_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_x_erf.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_X_ERF_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux1_k, _KMAX)(const xc_func_type *p, double a, double *out) {

#if _KMAX >= 1
  const double _t1 = (0.1e1 / (a * a));
  const double _t2 = exp(-0.1e1 / 0.4e1*_t1);
#endif
#if _KMAX >= 2
  const double _t3 = _t2/xc_powi(a, 5);
#endif

  const double f = xc_powr(M_PI, 1, 2)*erf((0.1e1 / 0.2e1)/a);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t1*_t2;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.2e1*_t2/(a * a * a) - 0.1e1 / 0.2e1*_t3;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -0.6e1*_t2/(a * a * a * a) + (0.7e1 / 0.2e1)*_t2/xc_powi(a, 6) - 0.1e1 / 0.4e1*_t2/xc_powi(a, 8);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.24e2*_t2/xc_powi(a, 7) + (0.15e2 / 0.4e1)*_t2/xc_powi(a, 9) - 0.1e1 / 0.8e1*_t2/xc_powi(a, 11) + 0.24e2*_t3;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux2_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = xc_expm1(-(0.1e1 / 0.4e1)/(a * a));
#if _KMAX >= 1
  const double _t2 = _t1 + 0.1e1;
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi(a, -6);
#endif
#if _KMAX >= 3
  const double _t4 = (0.9e1 / 0.4e1)*_t2;
#endif

  const double f = _t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = (0.1e1 / 0.2e1)*_t2/(a * a * a);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = (0.1e1 / 0.4e1)*_t2*_t3 - 0.3e1 / 0.2e1*_t2/(a * a * a * a);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.6e1*_t2/xc_powi(a, 5) + (0.1e1 / 0.8e1)*_t2/xc_powi(a, 9) - _t4/xc_powi(a, 7);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.30e2*_t2*_t3 + (0.75e2 / 0.4e1)*_t2/xc_powi(a, 8) + (0.1e1 / 0.16e2)*_t2/xc_powi(a, 12) - _t4/xc_powi(a, 10);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux3_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux2_k, _KMAX)(p, a, _hc0);
  const double _t1 = 0.2e1*(a * a);
#if _KMAX >= 1
  const double _t2 = 0.4e1*_hc0[0];
#endif

  const double f = _hc0[0]*_t1 + 0.1e1 / 0.2e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _hc0[1]*_t1 + _t2*a;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.8e1*_hc0[1]*a + _hc0[2]*_t1 + _t2;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.12e2*_hc0[1] + 0.12e2*_hc0[2]*a + _hc0[3]*_t1;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.24e2*_hc0[2] + 0.16e2*_hc0[3]*a + _hc0[4]*_t1;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf0_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux3_k, _KMAX)(p, a, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux2_k, _KMAX)(p, a, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux1_k, _KMAX)(p, a, _hc2);
  const double _t1 = a*(-_hc0[0] + _hc1[0]);
  const double _t2 = (0.8e1 / 0.3e1)*a;
#if _KMAX >= 1
  const double _t3 = a*(-_hc0[1] + _hc1[1]);
#endif
#if _KMAX >= 2
  const double _t4 = a*(-_hc0[2] + _hc1[2]);
#endif
#if _KMAX >= 3
  const double _t5 = a*(-_hc0[3] + _hc1[3]);
#endif

  const double f = -_t2*(_hc2[0] + 0.2e1*_t1) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -0.8e1 / 0.3e1*_hc2[0] - 0.16e2 / 0.3e1*_t1 - _t2*(-0.2e1*_hc0[0] + 0.2e1*_hc1[0] + _hc2[1] + 0.2e1*_t3);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = (0.32e2 / 0.3e1)*_hc0[0] - 0.32e2 / 0.3e1*_hc1[0] - 0.16e2 / 0.3e1*_hc2[1] - _t2*(-0.4e1*_hc0[1] + 0.4e1*_hc1[1] + _hc2[2] + 0.2e1*_t4) - 0.32e2 / 0.3e1*_t3;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.32e2*_hc0[1] - 0.32e2*_hc1[1] - 0.8e1*_hc2[2] - _t2*(-0.6e1*_hc0[2] + 0.6e1*_hc1[2] + _hc2[3] + 0.2e1*_t5) - 0.16e2*_t4;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.64e2*_hc0[2] - 0.64e2*_hc1[2] - 0.32e2 / 0.3e1*_hc2[3] - _t2*(-0.8e1*_hc0[3] + 0.8e1*_hc1[3] + _hc2[4] + 0.2e1*a*(-_hc0[4] + _hc1[4])) - 0.64e2 / 0.3e1*_t5;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = a > 1.3500000000000001;
  const double _t2 = a >= 1.3500000000000001;
  const double _t3 = my_piecewise3(_t1, a, 1.3500000000000001);
  const double _t4 = xc_powi(_t3, -14);
  const double _t5 = xc_powi(_t3, -12);
  const double _t6 = xc_powi(_t3, -10);
  const double _t7 = xc_powi(_t3, -8);
  const double _t8 = xc_powi(_t3, -6);
  const double _t9 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
#if _KMAX >= 1
  const double _t10 = my_piecewise3(_t1, 0.1e1, 0);
  const double _t11 = xc_powi(_t3, -15);
  const double _t12 = xc_powi(_t3, -13);
  const double _t13 = xc_powi(_t3, -11);
  const double _t14 = xc_powi(_t3, -9);
  const double _t15 = xc_powi(_t3, -7);
  const double _t16 = xc_powi(_t3, -5);
  const double _t17 = my_piecewise3(_t1, 0, 0.1e1);
#endif
#if _KMAX >= 2
  const double _t18 = xc_powi(_t3, -16);
  const double _t19 = (_t10 * _t10);
#endif
#if _KMAX >= 3
  const double _t20 = (_t10 * _t10 * _t10);
#endif
#if _KMAX >= 4
  const double _t21 = (_t10 * _t10 * _t10 * _t10);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(attenuation_erf0_k, _KMAX)(p, my_piecewise3(_t1, 1.3500000000000001, a), _hc0);

  const double f = my_piecewise3(_t2, (0.1e1 / 0.44590694400e11)*_t4 - 0.1e1 / 0.1073479680e10*_t5 + (0.1e1 / 0.28385280e8)*_t6 - 0.1e1 / 0.829440e6*_t7 + (0.1e1 / 0.26880e5)*_t8 - 0.1e1 / 0.960e3*_t9 + (0.1e1 / 0.36e2)/(_t3 * _t3), _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, -0.1e1 / 0.3185049600e10*_t10*_t11 + (0.1e1 / 0.89456640e8)*_t10*_t12 - 0.1e1 / 0.2838528e7*_t10*_t13 + (0.1e1 / 0.103680e6)*_t10*_t14 - 0.1e1 / 0.4480e4*_t10*_t15 + (0.1e1 / 0.240e3)*_t10*_t16 - 0.1e1 / 0.18e2*_t10/(_t3 * _t3 * _t3), _hc0[1]*_t17);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, (0.1e1 / 0.212336640e9)*_t18*_t19 - 0.1e1 / 0.6881280e7*_t19*_t4 + (0.1e1 / 0.258048e6)*_t19*_t5 - 0.1e1 / 0.11520e5*_t19*_t6 + (0.1e1 / 0.640e3)*_t19*_t7 - 0.1e1 / 0.48e2*_t19*_t8 + (0.1e1 / 0.6e1)*_t19*_t9, _hc0[2]*(_t17 * _t17));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, (0.1e1 / 0.491520e6)*_t11*_t20 - 0.1e1 / 0.21504e5*_t12*_t20 + (0.1e1 / 0.1152e4)*_t13*_t20 - 0.1e1 / 0.80e2*_t14*_t20 + (0.1e1 / 0.8e1)*_t15*_t20 - 0.2e1 / 0.3e1*_t16*_t20 - 0.1e1 / 0.13271040e8*_t20/xc_powi(_t3, 17), _hc0[3]*(_t17 * _t17 * _t17));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, -0.1e1 / 0.32768e5*_t18*_t21 + (0.13e2 / 0.21504e5)*_t21*_t4 - 0.11e2 / 0.1152e4*_t21*_t5 + (0.9e1 / 0.80e2)*_t21*_t6 - 0.7e1 / 0.8e1*_t21*_t7 + (0.10e2 / 0.3e1)*_t21*_t8 + (0.17e2 / 0.13271040e8)*_t21/xc_powi(_t3, 18), _hc0[4]*(_t17 * _t17 * _t17 * _t17));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_erf_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.1e1 / 0.3e1, _hc0);
  const double _t1 = (0.1e1 / (M_CBRTPI));
  const double _t2 = _hc0[0] + 0.1e1;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t3*p->cam_omega;
  const double _t5 = xc_powr(0.2e1, 2, 3);
  const double _t6 = _t5*rs;
  const double _t7 = (0.1e1 / rs);
  const double _t8 = (0.1e1 / M_CBRTPI);
  const double _t9 = M_CBRT3*_t8;
  const double _t12 = xc_powr(0.6e1, 1, 3);
#if _KMAX >= 1
  const double _t18 = xc_powr(0.3e1, 2, 3);
  const double _t19 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t22 = (0.1e1 / (_t2 * _t2));
  const double _t23 = _t22*p->cam_omega;
  const double _t25 = (rs * rs);
  const double _t26 = (0.1e1 / _t25);
#endif
#if _KMAX >= 2
  const double _t30 = ((_hc0[2]) * (_hc0[2]));
  const double _t32 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t33 = _t32*p->cam_omega;
  const double _t34 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t35 = (0.1e1 / M_PI);
  const double _t36 = ((p->cam_omega) * (p->cam_omega));
  const double _t47 = (rs * rs * rs);
  const double _t48 = (0.3e1 / 0.8e1)/_t47;
#endif
#if _KMAX >= 3
  const double _t58 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t62 = xc_powi(_t2, -5);
  const double _t65 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t66 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t69 = xc_powi(_t2, -6);
  const double _t74 = (0.1e1 / (rs * rs * rs * rs));
  const double _t75 = (0.9e1 / 0.8e1)*_t74;
#endif
#if _KMAX >= 4
  const double _t83 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t87 = _t25/xc_powi(_t2, 7);
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_k, _KMAX)(p, (0.1e1 / 0.6e1)*M_CBRT3*_t1*_t4*_t6, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc2);
  const double _t10 = _hc2[0]*_t9;
  const double _t11 = _t10*_t7;
  const double _t13 = _hc1[0]*_t1*_t12;
  const double _t14 = (0.3e1 / 0.16e2)*_t13;
#if _KMAX >= 1
  const double _t15 = _t14*_t9;
  const double _t16 = _t15*_t7;
  const double _t17 = _hc0[2]*_t10;
  const double _t20 = _hc1[1]*_t18*_t19;
  const double _t21 = (0.1e1 / 0.16e2)*_t20;
  const double _t24 = _t21*_t23;
  const double _t27 = _t10*_t26;
  const double _t28 = _t21*_t4;
#endif
#if _KMAX >= 2
  const double _t29 = (0.1e1 / 0.8e1)*_t20;
  const double _t31 = _t10*_t30;
  const double _t37 = _hc1[2]*_t35*_t36;
  const double _t38 = _t37*_t6;
  const double _t39 = _t34*_t38;
  const double _t40 = _t15*_t26;
  const double _t41 = (0.1e1 / 0.32e2)*_t17;
  const double _t42 = _t37*_t5;
  const double _t43 = _t32*_t42;
  const double _t44 = _hc2[1]*_t9;
  const double _t45 = _t28*_t7;
  const double _t46 = _t10*_t13;
  const double _t49 = _t22*_t42;
  const double _t50 = (0.1e1 / 0.32e2)*_t49;
#endif
#if _KMAX >= 3
  const double _t51 = _hc2[2]*_t9;
  const double _t52 = (0.3e1 / 0.16e2)*_t20;
  const double _t53 = (0.3e1 / 0.8e1)*_t20;
  const double _t54 = _t33*_t53;
  const double _t55 = _hc0[5]*_t17;
  const double _t56 = _t30*_t44;
  const double _t57 = _t10*p->cam_omega;
  const double _t59 = _t17*_t34;
  const double _t60 = _hc0[5]*_t38;
  const double _t61 = (0.3e1 / 0.32e2)*_t39;
  const double _t63 = _t10*_t58;
  const double _t64 = _t62*_t63;
  const double _t67 = _hc1[3]*_t12*_t65*_t66;
  const double _t68 = (0.1e1 / 0.96e2)*_t67;
  const double _t70 = _t34*_t42;
  const double _t71 = _t31*_t62;
  const double _t72 = _t13*_t48;
  const double _t73 = _t50*_t7;
  const double _t76 = _t10*_t48;
  const double _t77 = _t20*_t4;
  const double _t78 = (0.3e1 / 0.32e2)*_t49;
  const double _t79 = _t32*_t68;
#endif
#if _KMAX >= 4
  const double _t80 = (0.3e1 / 0.2e1)*_t20;
  const double _t81 = _t20*_t33;
  const double _t82 = _t30*_t51;
  const double _t84 = ((_hc0[5]) * (_hc0[5]))*_t10;
  const double _t85 = _t10*_t83;
  const double _t86 = (0.1e1 / 0.288e3)*_hc1[4]*_t18*((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega))/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t88 = (0.9e1 / 0.32e2)*_t70;
  const double _t89 = _t67*rs;
  const double _t90 = _t62*_t89;
#endif

  const double f = -_t11*_t14;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc2[1]*_t16 + _t17*_t24;
  out[1] = df_dz;
  const double df_drs = -_t11*_t28 + _t14*_t27;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.8e1)*M_CBRT3*_hc0[2]*_hc1[1]*_hc2[1]*_t18*_t19*_t22*_t8*p->cam_omega + (0.1e1 / 0.16e2)*M_CBRT3*_hc0[5]*_hc1[1]*_hc2[0]*_t18*_t19*_t22*_t8*p->cam_omega - _hc2[2]*_t16 - _t29*_t31*_t33 - 0.1e1 / 0.32e2*_t31*_t39;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc2[1]*_t40 + _t41*_t43 - _t44*_t45;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = (0.1e1 / 0.8e1)*M_CBRT3*_hc1[1]*_hc2[0]*_t18*_t19*_t26*_t3*_t8*p->cam_omega - _t11*_t50 - _t46*_t48;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[2]*_t23*_t51*_t52 + _hc0[5]*_t23*_t44*_t52 + _hc0[9]*_t10*_t24 - _hc2[3]*_t16 + _t25*_t63*_t68*_t69 + _t34*_t53*_t57*_t58 + (0.3e1 / 0.16e2)*_t38*_t64 - _t54*_t55 - _t54*_t56 - _t56*_t61 - 0.3e1 / 0.32e2*_t59*_t60;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = (0.1e1 / 0.16e2)*M_CBRT3*_hc0[2]*_hc1[2]*_hc2[1]*_t32*_t35*_t36*_t5*_t8 + (0.1e1 / 0.32e2)*M_CBRT3*_hc0[5]*_hc1[2]*_hc2[0]*_t32*_t35*_t36*_t5*_t8 + (0.3e1 / 0.16e2)*M_CBRT3*_hc1[0]*_hc2[2]*_t1*_t12*_t26*_t8 - 0.3e1 / 0.32e2*_t31*_t70 - _t45*_t51 - _t68*_t71*rs;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _t26*_t29*_t4*_t44 - _t44*_t72 - _t44*_t73 + _t59*_t68;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = -_t11*_t79 + _t27*_t78 + _t46*_t75 - _t76*_t77;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.1e1 / 0.16e2)*M_CBRT3*_hc0[14]*_hc1[1]*_hc2[0]*_t18*_t19*_t22*_t8*p->cam_omega + (0.1e1 / 0.4e1)*M_CBRT3*_hc0[2]*_hc1[1]*_hc2[3]*_t18*_t19*_t22*_t8*p->cam_omega + (0.9e1 / 0.4e1)*M_CBRT3*_hc0[5]*_hc1[1]*_hc2[0]*_t18*_t19*_t30*_t34*_t8*p->cam_omega + (0.3e1 / 0.8e1)*M_CBRT3*_hc0[5]*_hc1[1]*_hc2[2]*_t18*_t19*_t22*_t8*p->cam_omega + (0.9e1 / 0.8e1)*M_CBRT3*_hc0[5]*_hc1[2]*_hc2[0]*_t30*_t35*_t36*_t5*_t62*_t8*rs + (0.1e1 / 0.16e2)*M_CBRT3*_hc0[5]*_hc1[3]*_hc2[0]*_t12*_t25*_t30*_t65*_t66*_t69*_t8 + (0.1e1 / 0.4e1)*M_CBRT3*_hc0[9]*_hc1[1]*_hc2[1]*_t18*_t19*_t22*_t8*p->cam_omega + (0.3e1 / 0.2e1)*M_CBRT3*_hc1[1]*_hc2[1]*_t18*_t19*_t34*_t58*_t8*p->cam_omega + (0.3e1 / 0.4e1)*M_CBRT3*_hc1[2]*_hc2[1]*_t35*_t36*_t5*_t58*_t62*_t8*rs + (0.1e1 / 0.24e2)*M_CBRT3*_hc1[3]*_hc2[1]*_t12*_t25*_t58*_t65*_t66*_t69*_t8 - _hc0[2]*_hc0[5]*_t33*_t44*_t80 - 0.3e1 / 0.8e1*_hc0[2]*_t34*_t44*_t60 - 0.1e1 / 0.2e1*_hc0[9]*_t17*_t81 - 0.1e1 / 0.8e1*_hc0[9]*_t38*_t59 - _hc2[4]*_t16 - 0.9e1 / 0.8e1*_t38*_t69*_t85 - 0.3e1 / 0.16e2*_t39*_t82 - _t54*_t84 - _t57*_t62*_t80*_t83 - _t61*_t84 - 0.1e1 / 0.8e1*_t67*_t85*_t87 - 0.3e1 / 0.4e1*_t81*_t82 - _t47*_t85*_t86/xc_powi(_t2, 8);
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = (0.3e1 / 0.32e2)*_hc0[2]*_t43*_t51 - _hc0[5]*_t41*_t90 + (0.3e1 / 0.32e2)*_hc0[5]*_t43*_t44 + (0.1e1 / 0.32e2)*_hc0[9]*_t10*_t43 + _hc2[3]*_t40 - _hc2[3]*_t45*_t9 + (0.3e1 / 0.8e1)*_t42*_t64 - _t55*_t88 - _t56*_t88 - 0.1e1 / 0.32e2*_t56*_t90 + (0.1e1 / 0.12e2)*_t63*_t69*_t89 + _t63*_t86*_t87;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = (0.1e1 / 0.48e2)*M_CBRT3*_hc0[2]*_hc1[3]*_hc2[1]*_t12*_t34*_t65*_t66*_t8 + (0.1e1 / 0.96e2)*M_CBRT3*_hc0[5]*_hc1[3]*_hc2[0]*_t12*_t34*_t65*_t66*_t8 + (0.1e1 / 0.8e1)*M_CBRT3*_hc1[1]*_hc2[2]*_t18*_t19*_t26*_t3*_t8*p->cam_omega - _t31*_t69*_t86*rs - _t51*_t72 - _t51*_t73 - 0.1e1 / 0.24e2*_t67*_t71;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _t13*_t44*_t75 + _t17*_t62*_t86 + _t26*_t44*_t78 - _t44*_t48*_t77 - _t44*_t7*_t79;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = (0.3e1 / 0.2e1)*M_CBRT3*_hc1[1]*_hc2[0]*_t18*_t19*_t3*_t74*_t8*p->cam_omega + (0.1e1 / 0.24e2)*M_CBRT3*_hc1[3]*_hc2[0]*_t12*_t26*_t32*_t65*_t66*_t8 - _t11*_t34*_t86 - 0.9e1 / 0.2e1*_t46/xc_powi(rs, 5) - _t49*_t76;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_lda_x_erf_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_x_erf_spin_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_x_erf_spin_k, _KMAX)(p, rs, -z, _hc1);

  const double f = _hc0[0] + _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[1] - _hc1[1];
  out[1] = df_dz;
  const double df_drs = _hc0[2] + _hc1[2];
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[3] + _hc1[3];
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[4] - _hc1[4];
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[5] + _hc1[5];
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[6] - _hc1[6];
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[7] + _hc1[7];
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc0[8] - _hc1[8];
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[9] + _hc1[9];
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc0[10] + _hc1[10];
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc0[11] - _hc1[11];
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc0[12] + _hc1[12];
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[13] - _hc1[13];
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[14] + _hc1[14];
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_erf_spin_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / M_CBRTPI);
  const double _t5 = M_CBRT3*_t4;
  const double _t6 = _t5/rs;
  const double _t7 = _t3*_t6;
#if _KMAX >= 1
  const double _t10 = (0.1e1 / (rs * rs));
  const double _t11 = _t3*_t5;
  const double _t12 = xc_powr(0.3e1, 2, 3);
  const double _t13 = _t12*_t6;
  const double _t14 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
#endif
#if _KMAX >= 2
  const double _t17 = (0.3e1 / 0.8e1)/(rs * rs * rs);
#endif
#if _KMAX >= 3
  const double _t19 = (0.1e1 / (rs * rs * rs * rs));
  const double _t20 = _t17*_t5;
  const double _t21 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t22 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_k, _KMAX)(p, (0.1e1 / 0.6e1)*M_CBRT3*_t1*_t2*p->cam_omega*rs, _hc0);
  const double _t8 = _hc0[0]*_t2;
  const double _t9 = (0.3e1 / 0.16e2)*_t8;
#if _KMAX >= 1
  const double _t15 = _hc0[1]*_t14*p->cam_omega;
#endif
#if _KMAX >= 2
  const double _t16 = _t11*_t8;
  const double _t18 = _hc0[2]*_t1*((p->cam_omega) * (p->cam_omega))/M_PI;
#endif

  const double f = -_t7*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t11*_t9 - 0.1e1 / 0.16e2*_t13*_t15;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = (0.1e1 / 0.8e1)*M_CBRT3*_hc0[1]*_t10*_t12*_t14*_t4*p->cam_omega - _t16*_t17 - 0.1e1 / 0.32e2*_t18*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.1e1 / 0.96e2*_hc0[3]*_t21*_t22*_t7 + (0.3e1 / 0.32e2)*_t10*_t18*_t5 - _t12*_t15*_t20 + (0.9e1 / 0.8e1)*_t16*_t19;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = (0.3e1 / 0.2e1)*M_CBRT3*_hc0[1]*_t12*_t14*_t19*_t4*p->cam_omega + (0.1e1 / 0.24e2)*M_CBRT3*_hc0[3]*_t10*_t21*_t22*_t3*_t4 - 0.1e1 / 0.288e3*_hc0[4]*_t13*((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega))/(M_PI * M_CBRTPI * M_CBRTPI) - 0.9e1 / 0.2e1*_t16/xc_powi(rs, 5) - _t18*_t20;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_lda_x_erf_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_erf_spin_z0_k, _KMAX)(p, rs, _hc0);

  const double f = 0.2e1*_hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.2e1*_hc0[1];
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.2e1*_hc0[2];
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.2e1*_hc0[3];
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.2e1*_hc0[4];
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
  XC_CAT(f_lda_x_erf_z0_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t4, _hc0);
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
  XC_CAT(f_lda_x_erf_k, _KMAX)(p, _t5/xc_powr(_t1, 1, 3), _t6*_t7, _hc0);
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