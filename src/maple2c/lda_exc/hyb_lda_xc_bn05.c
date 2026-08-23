/*
  Generated from python/lda_exc/hyb_lda_xc_bn05.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py hyb_lda_xc_bn05
*/

#ifndef _HYB_LDA_XC_BN05_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _HYB_LDA_XC_BN05_KERNEL_BODY
#define _KMAX 0
#define _HYB_LDA_XC_BN05_HELPER_BODIES
#include "hyb_lda_xc_bn05.c"
#undef _HYB_LDA_XC_BN05_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _HYB_LDA_XC_BN05_HELPER_BODIES
#include "hyb_lda_xc_bn05.c"
#undef _HYB_LDA_XC_BN05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _HYB_LDA_XC_BN05_HELPER_BODIES
#include "hyb_lda_xc_bn05.c"
#undef _HYB_LDA_XC_BN05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _HYB_LDA_XC_BN05_HELPER_BODIES
#include "hyb_lda_xc_bn05.c"
#undef _HYB_LDA_XC_BN05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _HYB_LDA_XC_BN05_HELPER_BODIES
#include "hyb_lda_xc_bn05.c"
#undef _HYB_LDA_XC_BN05_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "hyb_lda_xc_bn05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_HYB_LDA_XC_BN05_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_yukawa_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

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
  XC_CAT(attenuation_yukawa_k, _KMAX)(p, (0.1e1 / 0.6e1)*M_CBRT3*_t1*_t4*_t6, _hc1);
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_lda_x_yukawa_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_x_yukawa_spin_k, _KMAX)(p, rs, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_x_yukawa_spin_k, _KMAX)(p, rs, -z, _hc1);

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = 0.01328816518*rs + 0.062181399999999998;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = (rs * rs);
  const double _t6 = 0.10186556948*_t3 + 0.47231125997999995*_t4 + 0.030651699315999998*_t5 + 0.22308199064000001*rs;
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = xc_log1p(_t7);
  const double _t9 = _t2*_t8;
  const double _t10 = 0.029729725187999999*_t3 + 0.3497952466*_t4 + 0.016775784198*_t5 + 0.12236585478000001*rs;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_log1p(_t11);
  const double _t13 = -0.00375733525*rs - 0.0337738;
  const double _t14 = 0.58482236226346462*_t13;
  const double _t15 = _t12*_t14;
  const double _t16 = (zeta * zeta * zeta * zeta);
  const double _t17 = 0.0063885170359999997*rs + 0.031090699999999999;
  const double _t18 = -_t17;
  const double _t19 = 0.10465751433999999*_t3 + 0.43896648423000001*_t4 + 0.019436972918999998*_t5 + 0.19269083139000001*rs;
  const double _t20 = (0.1e1 / _t19);
  const double _t21 = xc_log1p(_t20);
  const double _t22 = _t15 + _t18*_t21 - _t9;
  const double _t23 = _t16*_t22;
#if _KMAX >= 1
  const double _t24 = _hc0[0]*_t22;
  const double _t25 = (zeta * zeta * zeta);
  const double _t26 = 0.4e1*_t25;
  const double _t27 = 0.0021973736767207854*_t12;
  const double _t28 = sqrt(rs);
  const double _t29 = (0.1e1 / _t4);
  const double _t30 = -0.15698627151*_t28 - 0.219483242115*_t29 - 0.038873945837999996*rs - 0.19269083139000001;
  const double _t31 = (0.1e1 / (_t19 * _t19));
  const double _t32 = _t20 + 0.1e1;
  const double _t33 = (0.1e1 / _t32);
  const double _t34 = -0.044594587781999998*_t28 - 0.1748976233*_t29 - 0.033551568396000001*rs - 0.12236585478000001;
  const double _t35 = (0.1e1 / (_t10 * _t10));
  const double _t36 = _t11 + 0.1e1;
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = _t7 + 0.1e1;
  const double _t39 = (0.1e1 / _t38);
  const double _t40 = _t39/(_t6 * _t6);
  const double _t41 = -0.15279835421999999*_t28 - 0.23615562998999998*_t29 - 0.061303398631999996*rs - 0.22308199064000001;
  const double _t42 = _t2*_t41;
  const double _t43 = _t40*_t42 - 0.01328816518*_t8;
  const double _t44 = 0.58482236226346462*_t13*_t34*_t35*_t37 + _t18*_t30*_t31*_t33 - 0.0063885170359999997*_t21 - _t27 - _t43;
  const double _t45 = _t16*_t44;
  const double _t46 = _t35*_t37;
  const double _t47 = _t34*_t46;
  const double _t48 = _t14*_t47;
#endif
#if _KMAX >= 2
  const double _t49 = (zeta * zeta);
  const double _t50 = 0.12e2*_t49;
  const double _t51 = _t22*_t25;
  const double _t52 = 0.8e1*_hc0[1];
  const double _t53 = _hc0[0]*_t44;
  const double _t54 = 0.026576330360000001*_t40*_t41;
  const double _t55 = 0.0043947473534415708*_t47;
  const double _t56 = (0.1e1 / _t28);
  const double _t57 = xc_powr(rs, -3, 2);
  const double _t58 = -0.076399177109999994*_t56 + 0.11807781499499999*_t57 - 0.061303398631999996;
  const double _t59 = _t40*_t58;
  const double _t60 = _t2*_t59;
  const double _t61 = -0.022297293890999999*_t56 + 0.08744881165*_t57 - 0.033551568396000001;
  const double _t62 = _t46*_t61;
  const double _t63 = _t14*_t62;
  const double _t64 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t65 = (0.1e1 / (_t38 * _t38));
  const double _t66 = (_t41 * _t41);
  const double _t67 = _t65*_t66;
  const double _t68 = _t64*_t67;
  const double _t69 = (0.1e1 / (_t10 * _t10 * _t10 * _t10));
  const double _t70 = (0.1e1 / (_t36 * _t36));
  const double _t71 = (_t34 * _t34);
  const double _t72 = _t70*_t71;
  const double _t73 = _t69*_t72;
  const double _t74 = _t14*_t73;
  const double _t75 = _t39/(_t6 * _t6 * _t6);
  const double _t76 = -0.30559670843999998*_t28 - 0.47231125997999995*_t29 - 0.12260679726399999*rs - 0.44616398128000001;
  const double _t77 = _t42*_t76;
  const double _t78 = _t75*_t77;
  const double _t79 = _t37/(_t10 * _t10 * _t10);
  const double _t80 = -0.089189175563999995*_t28 - 0.3497952466*_t29 - 0.067103136792000001*rs - 0.24473170956000001;
  const double _t81 = _t34*_t80;
  const double _t82 = _t79*_t81;
  const double _t83 = _t14*_t82;
  const double _t84 = _t31*_t33;
  const double _t85 = -0.078493135754999999*_t56 + 0.1097416210575*_t57 - 0.038873945837999996;
  const double _t86 = _t84*_t85;
  const double _t87 = 0.0021973736767207854*rs + 0.019751673498613801;
  const double _t88 = (0.1e1 / (_t19 * _t19 * _t19 * _t19));
  const double _t89 = (0.1e1 / (_t32 * _t32));
  const double _t90 = (_t30 * _t30);
  const double _t91 = _t89*_t90;
  const double _t92 = _t88*_t91;
  const double _t93 = _t2*_t64;
  const double _t94 = _t33/(_t19 * _t19 * _t19);
  const double _t95 = -0.31397254301999999*_t28 - 0.43896648423000001*_t29 - 0.077747891675999992*rs - 0.38538166278000002;
  const double _t96 = _t18*_t30;
  const double _t97 = _t95*_t96;
  const double _t98 = _t17*_t92 + _t18*_t86 - 0.012777034071999999*_t30*_t84 + _t54 - _t55 - _t60 + _t63 + _t67*_t93 + _t73*_t87 - _t78 + _t83 + _t94*_t97;
  const double _t99 = _t16*_t98;
#endif
#if _KMAX >= 3
  const double _t100 = 0.24e2*_t24;
  const double _t101 = _t22*_t49;
  const double _t102 = 0.36e2*_hc0[1];
  const double _t103 = 0.12e2*_hc0[2];
  const double _t104 = _t25*_t44;
  const double _t105 = _hc0[0]*_t98;
  const double _t106 = 0.039864495540000003*_t59;
  const double _t107 = 0.0065921210301623562*_t62;
  const double _t108 = (0.1e1 / _t3);
  const double _t109 = xc_powr(rs, -5, 2);
  const double _t110 = 0.038199588554999997*_t108 - 0.17711672249249999*_t109;
  const double _t111 = _t110*_t40;
  const double _t112 = _t111*_t2;
  const double _t113 = 0.039864495540000003*_t68;
  const double _t114 = 0.011148646945499999*_t108 - 0.13117321747499999*_t109;
  const double _t115 = _t114*_t46;
  const double _t116 = _t115*_t14;
  const double _t117 = 0.0065921210301623562*_t73;
  const double _t118 = 0.026576330360000001*rs + 0.1243628;
  const double _t119 = (_t41 * _t41 * _t41);
  const double _t120 = (0.1e1 / (_t38 * _t38 * _t38));
  const double _t121 = xc_powi(_t6, -6);
  const double _t122 = _t120*_t121;
  const double _t123 = _t119*_t122;
  const double _t124 = (_t34 * _t34 * _t34);
  const double _t125 = (0.1e1 / (_t36 * _t36 * _t36));
  const double _t126 = xc_powi(_t10, -6);
  const double _t127 = _t125*_t126;
  const double _t128 = _t124*_t127;
  const double _t129 = 1.1696447245269292*_t13;
  const double _t130 = _t128*_t129;
  const double _t131 = _t41*_t75;
  const double _t132 = 0.039864495540000003*_t131*_t76;
  const double _t133 = 0.0065921210301623562*_t82;
  const double _t134 = -0.15279835421999999*_t56 + 0.23615562998999998*_t57 - 0.12260679726399999;
  const double _t135 = _t42*_t75;
  const double _t136 = _t134*_t135;
  const double _t137 = _t64*_t65;
  const double _t138 = _t137*_t42;
  const double _t139 = _t134*_t138;
  const double _t140 = _t138*_t58;
  const double _t141 = _t75*_t76;
  const double _t142 = _t141*_t58;
  const double _t143 = 0.2e1*_t2;
  const double _t144 = _t142*_t143;
  const double _t145 = -0.044594587781999998*_t56 + 0.1748976233*_t57 - 0.067103136792000001;
  const double _t146 = _t69*_t70;
  const double _t147 = _t14*_t34;
  const double _t148 = _t146*_t147;
  const double _t149 = _t145*_t148;
  const double _t150 = _t146*_t61;
  const double _t151 = _t147*_t150;
  const double _t152 = _t145*_t79;
  const double _t153 = _t147*_t152;
  const double _t154 = _t79*_t80;
  const double _t155 = _t154*_t61;
  const double _t156 = _t129*_t155;
  const double _t157 = -0.61119341687999995*_t28 - 0.94462251995999991*_t29 - 0.24521359452799998*rs - 0.89232796256000002;
  const double _t158 = xc_powi(_t6, -5);
  const double _t159 = _t158*_t67;
  const double _t160 = _t159*_t2;
  const double _t161 = _t157*_t160;
  const double _t162 = _t160*_t76;
  const double _t163 = -0.17837835112799999*_t28 - 0.6995904932*_t29 - 0.134206273584*rs - 0.48946341912000002;
  const double _t164 = xc_powi(_t10, -5);
  const double _t165 = _t164*_t72;
  const double _t166 = _t14*_t165;
  const double _t167 = _t163*_t166;
  const double _t168 = _t166*_t80;
  const double _t169 = -0.45839506265999996*_t28 - 0.70846688996999996*_t29 - 0.18391019589599999*rs - 0.66924597192000002;
  const double _t170 = _t169*_t39;
  const double _t171 = _t170*_t64;
  const double _t172 = _t171*_t77;
  const double _t173 = -0.13378376334600001*_t28 - 0.52469286989999997*_t29 - 0.100654705188*rs - 0.36709756434000002;
  const double _t174 = _t173*_t37*_t69;
  const double _t175 = _t174*_t81;
  const double _t176 = _hc0[0]*_t14;
  const double _t177 = 0.039246567877499999*_t108 - 0.16461243158625*_t109;
  const double _t178 = _t177*_t84;
  const double _t179 = (_t30 * _t30 * _t30);
  const double _t180 = (0.1e1 / (_t32 * _t32 * _t32));
  const double _t181 = xc_powi(_t19, -6);
  const double _t182 = _t180*_t181;
  const double _t183 = _t179*_t182;
  const double _t184 = _t30*_t94;
  const double _t185 = -0.15698627151*_t56 + 0.219483242115*_t57 - 0.077747891675999992;
  const double _t186 = _t185*_t96;
  const double _t187 = _t88*_t89;
  const double _t188 = _t187*_t85;
  const double _t189 = _t94*_t95;
  const double _t190 = _t189*_t85;
  const double _t191 = 0.2e1*_t18;
  const double _t192 = -0.62794508603999999*_t28 - 0.87793296846000002*_t29 - 0.15549578335199998*rs - 0.77076332556000005;
  const double _t193 = xc_powi(_t19, -5);
  const double _t194 = _t193*_t91;
  const double _t195 = _t18*_t194;
  const double _t196 = -0.47095881452999999*_t28 - 0.65844972634499999*_t29 - 0.11662183751399999*rs - 0.57807249417000006;
  const double _t197 = _t196*_t33*_t88;
  const double _t198 = _t14*_t175;
  const double _t199 = _t106 - _t107 - _t112 - _t113 + _t116 + _t117 + _t118*_t123 + _t128*(-0.0043947473534415708*rs - 0.039503346997227602) + _t132 - _t133 - _t136 + _t139 + _t140 - _t144 - _t149 - _t151 + _t153 + _t156 + _t161 + _t162 - _t167 - _t168 - _t172 + _t178*_t18 + _t183*(-0.012777034071999999*rs - 0.062181399999999998) - 0.019165551108000001*_t184*_t95 - _t186*_t187 + _t186*_t94 - _t188*_t96 + _t190*_t191 - _t192*_t195 - _t195*_t95 + _t197*_t97 + _t198 - 0.019165551108000001*_t86 + 0.019165551108000001*_t92;
  const double _t200 = _t16*_t199;
#endif
#if _KMAX >= 4
  const double _t201 = 0.053152660720000001*_t111;
  const double _t202 = 0.0087894947068831416*_t115;
  const double _t203 = pow(rs, -2.5);
  const double _t204 = xc_powr(rs, -7, 2);
  const double _t205 = _t2*_t40*(-0.057299382832499995*_t203 + 0.44279180623124997*_t204);
  const double _t206 = 0.10630532144*_t123;
  const double _t207 = _t14*_t46*(-0.016722970418250001*_t203 + 0.32793304368749998*_t204);
  const double _t208 = 0.017578989413766283*_t128;
  const double _t209 = (_t58 * _t58)*_t65;
  const double _t210 = _t146*(_t61 * _t61);
  const double _t211 = 0.079728991080000006*rs + 0.37308839999999999;
  const double _t212 = (_t41 * _t41 * _t41 * _t41)/((_t38 * _t38 * _t38 * _t38)*xc_powi(_t6, 8));
  const double _t213 = (_t34 * _t34 * _t34 * _t34)/(xc_powi(_t10, 8)*(_t36 * _t36 * _t36 * _t36));
  const double _t214 = 0.053152660720000001*_t134;
  const double _t215 = _t137*_t41;
  const double _t216 = _t214*_t215;
  const double _t217 = 0.053152660720000001*_t215*_t58;
  const double _t218 = _t131*_t214;
  const double _t219 = 0.10630532144*_t142;
  const double _t220 = 0.0087894947068831416*_t34;
  const double _t221 = _t145*_t220;
  const double _t222 = _t146*_t221;
  const double _t223 = _t150*_t220;
  const double _t224 = _t221*_t79;
  const double _t225 = 0.017578989413766283*_t155;
  const double _t226 = _t134*_t58;
  const double _t227 = _t226*_t65*_t93;
  const double _t228 = 0.3e1*_t2;
  const double _t229 = _t226*_t228*_t75;
  const double _t230 = _t14*_t145;
  const double _t231 = _t150*_t230;
  const double _t232 = 1.7544670867903939*_t13;
  const double _t233 = _t232*_t61;
  const double _t234 = _t152*_t233;
  const double _t235 = 0.076399177109999994*_t108 - 0.35423344498499998*_t109;
  const double _t236 = _t135*_t235;
  const double _t237 = 0.032486556321720157*_t28 + 0.050209200311905303*_t29 + 0.013033754993878433*rs + 0.047429605444920545;
  const double _t238 = 0.016243278160860079*_t28 + 0.025104600155952651*_t29 + 0.0065168774969392163*rs + 0.023714802722460272;
  const double _t239 = 0.2e1*_t110*_t138;
  const double _t240 = _t138*_t235;
  const double _t241 = _t110*_t141*_t228;
  const double _t242 = _t114*_t129*_t146*_t34;
  const double _t243 = 0.022297293890999999*_t108 - 0.26234643494999998*_t109;
  const double _t244 = _t148*_t243;
  const double _t245 = _t114*_t154*_t232;
  const double _t246 = _t147*_t243*_t79;
  const double _t247 = 0.0087894947068831416*_t165;
  const double _t248 = _hc0[0]*_t163;
  const double _t249 = _hc0[0]*_t80;
  const double _t250 = -0.22919753132999998*_t56 + 0.35423344498499998*_t57 - 0.18391019589599999;
  const double _t251 = _t122*_t143*_t66;
  const double _t252 = _t250*_t251;
  const double _t253 = _t134*_t251;
  const double _t254 = _t251*_t58;
  const double _t255 = _t160*(-0.30559670843999998*_t56 + 0.47231125997999995*_t57 - 0.24521359452799998);
  const double _t256 = 0.2e1*_t134;
  const double _t257 = _t160*_t256;
  const double _t258 = -0.066891881673000003*_t56 + 0.26234643494999998*_t57 - 0.100654705188;
  const double _t259 = _t127*_t71;
  const double _t260 = _t129*_t259;
  const double _t261 = _t258*_t260;
  const double _t262 = _t145*_t260;
  const double _t263 = _t129*_t61;
  const double _t264 = _t259*_t263;
  const double _t265 = _t166*(-0.089189175563999995*_t56 + 0.3497952466*_t57 - 0.134206273584);
  const double _t266 = _t129*_t145;
  const double _t267 = _t165*_t266;
  const double _t268 = _t119*_t120*_t143/xc_powi(_t6, 7);
  const double _t269 = _t268*(-0.91679012531999993*_t28 - 1.4169337799399999*_t29 - 0.36782039179199999*rs - 1.33849194384);
  const double _t270 = _t157*_t268;
  const double _t271 = _t268*_t76;
  const double _t272 = _t124*_t125*_t129/xc_powi(_t10, 7);
  const double _t273 = _t272*(-0.26756752669200001*_t28 - 1.0493857397999999*_t29 - 0.201309410376*rs - 0.73419512868000003);
  const double _t274 = _t163*_t272;
  const double _t275 = _t272*_t80;
  const double _t276 = 0.053152660720000001*_t171*_t41*_t76;
  const double _t277 = 0.0087894947068831416*_t175;
  const double _t278 = _t250*_t39*_t64*_t77;
  const double _t279 = _t158*_t65;
  const double _t280 = _t157*_t42;
  const double _t281 = _t256*_t279*_t280;
  const double _t282 = _t134*_t279*_t77;
  const double _t283 = _t279*_t58;
  const double _t284 = _t280*_t283;
  const double _t285 = 0.2e1*_t283*_t77;
  const double _t286 = _t171*_t256*_t42;
  const double _t287 = 0.3e1*_t170*_t58*_t76*_t93;
  const double _t288 = _t266*_t34;
  const double _t289 = _t164*_t70;
  const double _t290 = _t248*_t289;
  const double _t291 = _t289*_t81;
  const double _t292 = _t230*_t291;
  const double _t293 = _t147*_t61;
  const double _t294 = _t263*_t291;
  const double _t295 = _t258*_t69;
  const double _t296 = _t37*_t81;
  const double _t297 = _t176*_t296;
  const double _t298 = _t174*_t288;
  const double _t299 = _t174*_t233;
  const double _t300 = -0.76399177109999994*_t28 - 1.1807781499499999*_t29 - 0.30651699315999997*rs - 1.1154099531999999;
  const double _t301 = _t121*_t157*_t2*_t300*_t67;
  const double _t302 = _t121*_t2*_t67*_t76;
  const double _t303 = _t300*_t302;
  const double _t304 = _t169*_t302;
  const double _t305 = -0.22297293890999997*_t28 - 0.87448811650000002*_t29 - 0.16775784197999999*rs - 0.61182927389999997;
  const double _t306 = _t126*_t163*_t305*_t72;
  const double _t307 = _t126*_t72*_t80;
  const double _t308 = _t176*_t307;
  const double _t309 = _t157*_t158*_t170*_t77;
  const double _t310 = _t163*_t164*_t173;
  const double _t311 = 0.025554068143999999*_t30;
  const double _t312 = _t18*_t185;
  const double _t313 = _t96*(0.078493135754999999*_t108 - 0.32922486317249999*_t109);
  const double _t314 = 0.3e1*_t18;
  const double _t315 = -0.235479407265*_t56 + 0.32922486317249999*_t57 - 0.11662183751399999;
  const double _t316 = _t182*_t90;
  const double _t317 = _t191*_t316;
  const double _t318 = _t179*_t180*_t191/xc_powi(_t19, 7);
  const double _t319 = _t197*_t95;
  const double _t320 = _t33*_t97;
  const double _t321 = _t163*_t289;
  const double _t322 = _t14*_t296;
  const double _t323 = _t193*_t89;
  const double _t324 = 0.2e1*_t186;
  const double _t325 = _t323*_t85;
  const double _t326 = _t14*_t307;
  const double _t327 = -0.78493135754999999*_t28 - 1.0974162105750001*_t29 - 0.19436972918999998*rs - 0.96345415695000003;
  const double _t328 = _t18*_t181*_t91;
  const double _t329 = _t328*_t95;
#endif

  const double f = -_hc0[0]*_t15 + _hc0[0]*_t23 + _t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = -_hc0[1]*_t15 + _hc0[1]*_t23 + _t24*_t26;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t27 + _hc0[0]*_t45 - _hc0[0]*_t48 + _t43;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = -_hc0[2]*_t15 + _hc0[2]*_t23 + _t24*_t50 + _t51*_t52;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t27 + _hc0[1]*_t45 - _hc0[1]*_t48 + _t26*_t53;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[0]*_t55 - _hc0[0]*_t63 + _hc0[0]*_t74 - _hc0[0]*_t83 + _hc0[0]*_t99 + _t1*_t68 - _t54 + _t60 + _t78;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = -_hc0[3]*_t15 + _hc0[3]*_t23 + _t100*zeta + _t101*_t102 + _t103*_t51;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc0[2]*_t27 + _hc0[2]*_t45 - _hc0[2]*_t48 + _t104*_t52 + _t50*_t53;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc0[1]*_t55 - _hc0[1]*_t63 + _hc0[1]*_t74 - _hc0[1]*_t83 + _hc0[1]*_t99 + _t105*_t26;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = _hc0[0]*_t107 - _hc0[0]*_t116 - _hc0[0]*_t117 - _hc0[0]*_t130 + _hc0[0]*_t133 + _hc0[0]*_t149 + _hc0[0]*_t151 - _hc0[0]*_t153 - _hc0[0]*_t156 + _hc0[0]*_t167 + _hc0[0]*_t168 + _hc0[0]*_t200 - _t106 + _t112 + _t113 - _t118*_t123 - _t132 + _t136 - _t139 - _t140 + _t144 - _t161 - _t162 + _t172 - _t175*_t176;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = 0.96e2*_hc0[1]*_t22*zeta + 0.72e2*_hc0[2]*_t101 + 0.16e2*_hc0[3]*_t51 - _hc0[4]*_t15 + _hc0[4]*_t23 + _t100;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = _hc0[3]*_t27 + _hc0[3]*_t45 - _hc0[3]*_t48 + _t102*_t44*_t49 + _t103*_t104 + 0.24e2*_t53*zeta;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = _hc0[2]*_t55 - _hc0[2]*_t63 + _hc0[2]*_t74 - _hc0[2]*_t83 + _hc0[2]*_t99 + _t105*_t50 + _t25*_t52*_t98;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = _hc0[0]*_t199*_t26 + _hc0[1]*_t107 - _hc0[1]*_t116 - _hc0[1]*_t117 - _hc0[1]*_t130 + _hc0[1]*_t133 + _hc0[1]*_t149 + _hc0[1]*_t151 - _hc0[1]*_t153 - _hc0[1]*_t156 + _hc0[1]*_t167 + _hc0[1]*_t168 - _hc0[1]*_t198 + _hc0[1]*_t200;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = 3.5089341735807877*_hc0[0]*_t13*_t213 + _hc0[0]*_t16*(-_t14*_t306 + _t159*_t237 + _t159*_t238 + _t165*(-0.0015678555730620984*_t28 - 0.0061490469369671664*_t29 - 0.0011796053312970788*rs - 0.0043021361315681648) + _t165*(-0.00078392778653104919*_t28 - 0.0030745234684835832*_t29 - 0.0005898026656485394*rs - 0.0021510680657840824) + _t17*_t187*(_t85 * _t85) - _t173*_t326 - 0.2e1*_t177*_t187*_t96 + _t177*_t189*_t314 - 0.025554068143999999*_t178 + _t18*_t84*(-0.058869851816249999*_t203 + 0.41153107896562502*_t204) - 0.051108136287999997*_t183 - 0.025554068143999999*_t184*_t185 + _t185*_t187*_t311 - 0.2e1*_t185*_t195 - _t185*_t323*_t97 - _t187*_t313 + _t188*_t311 - _t188*_t312 - 0.051108136287999997*_t190 + _t192*_t193*_t196*_t320 + _t192*_t318 - _t192*_t323*_t324 - _t192*_t325*_t96 - _t192*_t327*_t328 + _t194*(-0.016046551519356102*_t28 - 0.022434758901891044*_t29 - 0.0039735498438816684*rs - 0.019696138544256298) + _t194*(-0.0080232757596780512*_t28 - 0.011217379450945522*_t29 - 0.0019867749219408342*rs - 0.0098480692721281491) - _t195*(-0.31397254301999999*_t56 + 0.43896648423000001*_t57 - 0.15549578335199998) - _t196*_t329 + _t197*_t324 + _t201 - _t202 - _t205 + _t206 + _t207 - _t208 + _t209*_t93 + _t210*_t87 - _t211*_t212 + _t213*(0.013184242060324712*rs + 0.11851004099168281) - _t216 - _t217 + _t218 + _t219 + _t222 + _t223 - _t224 - _t225 + _t227 - _t229 - _t231 + _t234 - _t236 + _t239 + _t240 - _t241 - _t242 - _t244 + _t245 + _t246 - _t252 - _t253 - _t254 + _t255 + _t257 + _t261 + _t262 + _t264 - _t265 - _t267 - _t269 - _t270 - _t271 + _t273 + _t274 + _t275 + _t276 - _t277 - _t278 + _t281 + _t282 + _t284 + _t285 - _t286 - _t287 - _t288*_t321 - _t292 - _t293*_t321 - _t294 + _t295*_t322 + _t298 + _t299*_t80 + _t301 + _t303 + _t304 - _t305*_t326 - _t309 + _t310*_t322 - _t311*_t319 + 0.2e1*_t312*_t316 + 0.3e1*_t312*_t85*_t94 + _t313*_t94 + _t314*_t319*_t85 + _t315*_t317 + _t315*_t320*_t88 + _t317*_t85 + _t318*_t95 + _t318*(-0.94191762905999998*_t28 - 1.31689945269*_t29 - 0.23324367502799997*rs - 1.1561449883400001) - 0.2e1*_t325*_t97 - _t327*_t329 + (_t30 * _t30 * _t30 * _t30)*(0.038331102216000001*rs + 0.18654419999999999)/(xc_powi(_t19, 8)*(_t32 * _t32 * _t32 * _t32))) + _hc0[0]*_t202 - _hc0[0]*_t207 + _hc0[0]*_t208 - _hc0[0]*_t222 - _hc0[0]*_t223 + _hc0[0]*_t224 + _hc0[0]*_t225 + _hc0[0]*_t231 - _hc0[0]*_t234 + _hc0[0]*_t242 + _hc0[0]*_t244 - _hc0[0]*_t245 - _hc0[0]*_t246 - _hc0[0]*_t261 - _hc0[0]*_t262 - _hc0[0]*_t264 + _hc0[0]*_t265 + _hc0[0]*_t267 - _hc0[0]*_t273 - _hc0[0]*_t274 - _hc0[0]*_t275 + _hc0[0]*_t277 + _hc0[0]*_t292 + _hc0[0]*_t294 - _hc0[0]*_t298 + _t1*_t209*_t64 - _t159*_t237 - _t159*_t238 + _t173*_t308 + _t176*_t210 + _t176*_t306 - _t201 + _t205 - _t206 + _t211*_t212 + _t216 + _t217 - _t218 - _t219 - _t227 + _t229 + _t236 - _t239 - _t240 + _t241 - _t247*_t248 - _t247*_t249 - _t249*_t299 + _t252 + _t253 + _t254 - _t255 - _t257 + _t269 + _t270 + _t271 - _t276 + _t278 - _t281 - _t282 - _t284 - _t285 + _t286 + _t287 + _t288*_t290 + _t290*_t293 - _t295*_t297 - _t297*_t310 - _t301 - _t303 - _t304 + _t305*_t308 + _t309;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 0.01328816518*rs + 0.062181399999999998;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = 0.10186556948*_t3 + 0.47231125997999995*_t4 + 0.030651699315999998*(rs * rs) + 0.22308199064000001*rs;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = xc_log1p(_t6);
#if _KMAX >= 1
  const double _t8 = sqrt(rs);
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = -0.15279835421999999*_t8 - 0.23615562998999998*_t9 - 0.061303398631999996*rs - 0.22308199064000001;
  const double _t11 = (0.1e1 / (_t5 * _t5));
  const double _t12 = _t6 + 0.1e1;
  const double _t13 = (0.1e1 / _t12);
#endif
#if _KMAX >= 2
  const double _t14 = _t11*_t13;
  const double _t15 = (0.1e1 / _t8);
  const double _t16 = xc_powr(rs, -3, 2);
  const double _t17 = -0.076399177109999994*_t15 + 0.11807781499499999*_t16 - 0.061303398631999996;
  const double _t18 = _t14*_t17;
  const double _t19 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t20 = (0.1e1 / (_t12 * _t12));
  const double _t21 = (_t10 * _t10);
  const double _t22 = _t20*_t21;
  const double _t23 = _t19*_t22;
  const double _t24 = _t13/(_t5 * _t5 * _t5);
  const double _t25 = -0.30559670843999998*_t8 - 0.47231125997999995*_t9 - 0.12260679726399999*rs - 0.44616398128000001;
  const double _t26 = _t10*_t2;
  const double _t27 = _t25*_t26;
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / _t3);
  const double _t29 = xc_powr(rs, -5, 2);
  const double _t30 = 0.038199588554999997*_t28 - 0.17711672249249999*_t29;
  const double _t31 = _t14*_t30;
  const double _t32 = (_t10 * _t10 * _t10);
  const double _t33 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t34 = xc_powi(_t5, -6);
  const double _t35 = _t33*_t34;
  const double _t36 = _t32*_t35;
  const double _t37 = _t10*_t24;
  const double _t38 = -0.15279835421999999*_t15 + 0.23615562998999998*_t16 - 0.12260679726399999;
  const double _t39 = _t26*_t38;
  const double _t40 = _t19*_t20;
  const double _t41 = _t17*_t40;
  const double _t42 = _t24*_t25;
  const double _t43 = _t17*_t42;
  const double _t44 = 0.2e1*_t2;
  const double _t45 = -0.61119341687999995*_t8 - 0.94462251995999991*_t9 - 0.24521359452799998*rs - 0.89232796256000002;
  const double _t46 = xc_powi(_t5, -5);
  const double _t47 = _t22*_t46;
  const double _t48 = _t2*_t47;
  const double _t49 = -0.45839506265999996*_t8 - 0.70846688996999996*_t9 - 0.18391019589599999*rs - 0.66924597192000002;
  const double _t50 = _t13*_t19*_t49;
#endif
#if _KMAX >= 4
  const double _t51 = 0.053152660720000001*_t10;
  const double _t52 = _t2*_t38;
  const double _t53 = _t26*(0.076399177109999994*_t28 - 0.35423344498499998*_t29);
  const double _t54 = 0.3e1*_t2;
  const double _t55 = -0.22919753132999998*_t15 + 0.35423344498499998*_t16 - 0.18391019589599999;
  const double _t56 = _t21*_t35;
  const double _t57 = _t44*_t56;
  const double _t58 = _t32*_t33*_t44/xc_powi(_t5, 7);
  const double _t59 = _t25*_t50;
  const double _t60 = _t13*_t27;
  const double _t61 = _t20*_t46;
  const double _t62 = 0.2e1*_t39;
  const double _t63 = _t17*_t61;
  const double _t64 = -0.76399177109999994*_t8 - 1.1807781499499999*_t9 - 0.30651699315999997*rs - 1.1154099531999999;
  const double _t65 = _t2*_t22*_t25*_t34;
#endif

  const double f = _t2*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t11*_t13*_t2 - 0.01328816518*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1*_t23 - 0.026576330360000001*_t10*_t14 + _t18*_t2 + _t24*_t27;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.039864495540000003*_t18 + _t2*_t31 + 0.039864495540000003*_t23 + _t24*_t39 - 0.039864495540000003*_t25*_t37 - _t25*_t48 - _t26*_t41 + _t27*_t50 + _t36*(-0.026576330360000001*rs - 0.1243628) - _t39*_t40 + _t43*_t44 - _t45*_t48;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t1*(_t17 * _t17)*_t40 + (_t10 * _t10 * _t10 * _t10)*(0.079728991080000006*rs + 0.37308839999999999)/((_t12 * _t12 * _t12 * _t12)*xc_powi(_t5, 8)) + _t14*_t2*(-0.057299382832499995*pow(rs, -2.5) + 0.44279180623124997/xc_powr(rs, 7, 2)) + 0.3e1*_t17*_t24*_t52 + _t17*_t54*_t59 + _t17*_t57 + _t19*_t55*_t60 - _t2*_t22*_t34*_t45*_t64 + _t24*_t53 + _t25*_t58 - 0.2e1*_t26*_t30*_t40 - _t26*_t45*_t63 - _t27*_t38*_t61 - 0.2e1*_t27*_t63 + _t30*_t42*_t54 - 0.053152660720000001*_t31 - 0.10630532144*_t36 - 0.053152660720000001*_t37*_t38 + _t38*_t40*_t51 - 0.2e1*_t38*_t48 - _t40*_t53 + _t41*_t51 - _t41*_t52 - 0.10630532144*_t43 + _t45*_t46*_t49*_t60 + _t45*_t58 - _t45*_t61*_t62 + _t47*(-0.032486556321720157*_t8 - 0.050209200311905303*_t9 - 0.013033754993878433*rs - 0.047429605444920545) + _t47*(-0.016243278160860079*_t8 - 0.025104600155952651*_t9 - 0.0065168774969392163*rs - 0.023714802722460272) - _t48*(-0.30559670843999998*_t15 + 0.47231125997999995*_t16 - 0.24521359452799998) - _t49*_t65 + _t50*_t62 - _t51*_t59 + 0.2e1*_t52*_t56 + _t55*_t57 + _t58*(-0.91679012531999993*_t8 - 1.4169337799399999*_t9 - 0.36782039179199999*rs - 1.33849194384) - _t64*_t65;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_yukawa_spin_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

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
  XC_CAT(attenuation_yukawa_k, _KMAX)(p, (0.1e1 / 0.6e1)*M_CBRT3*_t1*_t2*p->cam_omega*rs, _hc0);
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_lda_x_yukawa_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_yukawa_spin_z0_k, _KMAX)(p, rs, _hc0);

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
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = xc_powr(0.6e1, 2, 3);
  const double _t7 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t8 = _t6*_t7;
  const double _t9 = -0.45000000000000001*_t4 + (0.1e1 / 0.4e1)*_t8/xc_powr(na, 2, 3) + 3.2000000000000002;
  const double _t10 = (0.1e1 / _t9);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_lda_x_yukawa_z0_k, _KMAX)(p, _t5, _hc1);
  const double _t11 = 3.4601999999999999*_hc0[0];
  const double _t12 = _hc1[0] + _t10*_t11;
  const double zk = _t12;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t13 = _t3/xc_powr(na, 4, 3);
  const double _t17 = xc_powr(na, -5, 3);
  const double _t18 = -0.14999999999999999*_t13 + (0.1e1 / 0.6e1)*_t17*_t6*_t7;
  const double _t19 = (0.1e1 / (_t9 * _t9));
  const double _t14 = _hc1[1]*_t13;
  const double _t15 = _hc0[1]*_t10;
  const double _t16 = _t13*_t15;
  const double dF_dna = _t12 + na*(3.4601999999999999*_hc0[0]*_t18*_t19 - 0.1e1 / 0.6e1*_t14 - 0.57669999999999999*_t16);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t21 = 6.9203999999999999*_t18;
  const double _t22 = xc_powr(na, -7, 3);
  const double _t23 = _t22*_t3;
  const double _t25 = xc_powr(na, -8, 3);
  const double _t26 = _t25*_t8;
  const double _t31 = 0.19999999999999998*_t23 - 0.5e1 / 0.18e2*_t26;
  const double _t33 = _t18*_t19;
  const double _t36 = (0.1e1 / (_t9 * _t9 * _t9));
  const double _t37 = -0.29999999999999999*_t13 + (0.1e1 / 0.3e1)*_t17*_t6*_t7;
  const double _t38 = _t36*_t37;
  const double _t20 = _hc0[0]*_t19;
  const double _t24 = _hc1[1]*_t23;
  const double _t27 = _hc1[2]*_t26;
  const double _t28 = _t15*_t23;
  const double _t29 = _hc0[2]*_t10;
  const double _t30 = _t26*_t29;
  const double _t32 = _t11*_t19;
  const double _t34 = _hc0[1]*_t33;
  const double _t35 = _t13*_t34;
  const double _t39 = _t11*_t18;
  const double d2F_dna2 = -0.1e1 / 0.3e1*_t14 - 1.1534*_t16 + _t20*_t21 + na*((0.2e1 / 0.9e1)*_t24 + (0.1e1 / 0.36e2)*_t27 + 0.76893333333333325*_t28 + 0.096116666666666656*_t30 + _t31*_t32 - 1.1534*_t35 + _t38*_t39);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t40 = 10.380599999999999*_t31;
  const double _t42 = (0.1e1 / (na * na * na * na));
  const double _t43 = (0.1e1 / M_PI);
  const double _t46 = _t3/xc_powr(na, 10, 3);
  const double _t48 = xc_powr(na, -11, 3);
  const double _t49 = _t48*_t8;
  const double _t55 = -0.46666666666666667*_t46 + (0.20e2 / 0.27e2)*_t48*_t6*_t7;
  const double _t56 = _t19*_t31;
  const double _t59 = 0.39999999999999997*_t23 - 0.5e1 / 0.9e1*_t26;
  const double _t60 = _t18*_t38;
  const double _t61 = -0.44999999999999996*_t13 + (0.1e1 / 0.2e1)*_t17*_t6*_t7;
  const double _t62 = (0.1e1 / (_t9 * _t9 * _t9 * _t9));
  const double _t41 = 10.380599999999999*_hc0[0]*_t38;
  const double _t44 = _hc1[3]*_t43;
  const double _t45 = _t42*_t44;
  const double _t47 = _hc1[1]*_t46;
  const double _t50 = _hc1[2]*_t49;
  const double _t51 = _hc0[3]*_t10*_t43;
  const double _t52 = _t42*_t51;
  const double _t53 = _t15*_t46;
  const double _t54 = _t29*_t49;
  const double _t57 = _hc0[1]*_t13;
  const double _t58 = 1.7301*_t57;
  const double d3F_dna3 = _t18*_t41 + _t20*_t40 + (0.2e1 / 0.3e1)*_t24 + (0.1e1 / 0.12e2)*_t27 + 2.3068*_t28 + 0.28835*_t30 - 3.4601999999999999*_t35 + na*(3.4601999999999999*_hc0[0]*_t18*_t36*_t59 + 3.4601999999999999*_hc0[0]*_t18*_t37*_t61*_t62 + 3.4601999999999999*_hc0[0]*_t19*_t55 + 6.9203999999999999*_hc0[0]*_t31*_t36*_t37 + 2.3068*_hc0[1]*_t1*_t18*_t19*_t2*_t22 + 0.28835*_hc0[2]*_t18*_t19*_t25*_t6*_t7 - 0.1e1 / 0.36e2*_t45 - 0.14e2 / 0.27e2*_t47 - 0.1e1 / 0.9e1*_t50 - 0.096116666666666642*_t52 - 1.7941777777777776*_t53 - 0.38446666666666657*_t54 - _t56*_t58 - _t58*_t60);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t64 = xc_powi(na, -5);
  const double _t65 = _t1/((M_PI * M_CBRTPI)*xc_powr(na, 16, 3));
  const double _t66 = _t3/xc_powr(na, 13, 3);
  const double _t67 = _t8/xc_powr(na, 14, 3);
  const double _t71 = _t36*_t59;
  const double _t73 = _t61*_t62;
  const double _t74 = _t37*_t73;
  const double _t63 = 6.920399999999999*_t57;
  const double _t68 = 4.6135999999999999*_hc0[1]*_t23;
  const double _t69 = 2.3068*_t57;
  const double _t70 = 0.57669999999999999*_hc0[2]*_t26;
  const double _t72 = _t18*_t69;
  const double _t75 = _t37*_t39;
  const double d4F_dna4 = 13.8408*_hc0[0]*_t18*_t36*_t59 + 13.8408*_hc0[0]*_t18*_t37*_t61*_t62 + 13.8408*_hc0[0]*_t19*_t55 + 27.681599999999996*_hc0[0]*_t31*_t36*_t37 + 9.2271999999999998*_hc0[1]*_t1*_t18*_t19*_t2*_t22 + 1.1534*_hc0[2]*_t18*_t19*_t25*_t6*_t7 - 0.1e1 / 0.9e1*_t45 - 0.56e2 / 0.27e2*_t47 - 0.4e1 / 0.9e1*_t50 - 0.38446666666666662*_t52 - 7.1767111111111115*_t53 - 1.5378666666666665*_t54 - _t56*_t63 - _t60*_t63 + na*(_hc0[0]*_t21*_t59*_t73 + _hc0[0]*_t40*_t71 + _hc0[0]*_t40*_t74 - 1.5378666666666665*_hc0[2]*_t33*_t49 - 0.38446666666666662*_hc0[3]*_t33*_t42*_t43 + 0.01601944444444444*_hc0[4]*_t10*_t65 + (0.140e3 / 0.81e2)*_hc1[1]*_t66 + (0.40e2 / 0.81e2)*_hc1[2]*_t67 + (0.1e1 / 0.216e3)*_hc1[4]*_t65 + 5.9805925925925925*_t15*_t66 - _t19*_t55*_t69 + 1.7087407407407402*_t29*_t67 - 4.6135999999999999*_t31*_t38*_t57 + _t32*(1.5555555555555556*_t66 - 0.220e3 / 0.81e2*_t67) - 7.1767111111111115*_t34*_t46 + _t36*_t39*(-0.93333333333333335*_t46 + (0.40e2 / 0.27e2)*_t48*_t6*_t7) + _t41*_t55 + (0.2e1 / 0.9e1)*_t44*_t64 + 0.76893333333333314*_t51*_t64 + _t56*_t68 + _t56*_t70 + _t60*_t68 + _t60*_t70 + _t61*_t75*(-0.59999999999999998*_t13 + (0.2e1 / 0.3e1)*_t17*_t6*_t7)/xc_powi(_t9, 5) + _t62*_t75*(0.59999999999999987*_t23 - 0.5e1 / 0.6e1*_t26) - _t71*_t72 - _t72*_t74);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = _t4/xc_powr(_t1, 1, 3);
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = na - nb;
  const double _t8 = (0.1e1 / _t1);
  const double _t9 = _t7*_t8;
  const double _t10 = xc_powr(0.6e1, 2, 3);
  const double _t11 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t12 = _t10*_t11;
  const double _t13 = -0.45000000000000001*_t5 + 3.2000000000000002 + (0.1e1 / 0.4e1)*_t12/xc_powr(_t1, 2, 3);
  const double _t14 = (0.1e1 / _t13);
  const double _t15 = 3.4601999999999999*_t14;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, _t6, _t9, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_lda_x_yukawa_k, _KMAX)(p, _t6, _t9, _hc1);
  const double _t16 = _hc0[0]*_t15 + _hc1[0];
  const double zk = _t16;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t17 = (0.1e1 / (_t13 * _t13));
  const double _t18 = _t4/xc_powr(_t1, 4, 3);
  const double _t19 = xc_powr(_t1, -5, 3);
  const double _t20 = (0.1e1 / 0.6e1)*_t10*_t11*_t19 - 0.14999999999999999*_t18;
  const double _t21 = _t17*_t20;
  const double _t23 = (0.1e1 / 0.6e1)*_t18;
  const double _t25 = (0.1e1 / (_t1 * _t1));
  const double _t26 = _t25*_t7;
  const double _t27 = -_t26 + _t8;
  const double _t32 = -_t26 - _t8;
  const double _t22 = 3.4601999999999999*_hc0[0];
  const double _t24 = -_hc1[2]*_t23 + _t21*_t22;
  const double _t28 = _hc1[1]*_t27;
  const double _t29 = -_hc0[2]*_t23;
  const double _t30 = _hc0[1]*_t27 + _t29;
  const double _t31 = _t15*_t30 + _t28;
  const double _t33 = _hc1[1]*_t32;
  const double _t34 = _hc0[1]*_t32 + _t29;
  const double _t35 = _t15*_t34 + _t33;
  const double dF_dna = _t1*(_t24 + _t31) + _t16;
  const double dF_dnb = _t1*(_t24 + _t35) + _t16;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t36 = 6.9203999999999999*_t21;
  const double _t38 = xc_powr(_t1, -7, 3);
  const double _t39 = _t38*_t4;
  const double _t40 = _t12/xc_powr(_t1, 8, 3);
  const double _t41 = 0.19999999999999998*_t39 - 0.5e1 / 0.18e2*_t40;
  const double _t42 = _t17*_t41;
  const double _t43 = (0.2e1 / 0.9e1)*_t39;
  const double _t44 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t45 = (0.1e1 / 0.3e1)*_t10*_t11*_t19 - 0.29999999999999999*_t18;
  const double _t46 = _t44*_t45;
  const double _t47 = _t20*_t46;
  const double _t49 = 0.2e1*_t25;
  const double _t50 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t51 = 0.2e1*_t50;
  const double _t52 = _t51*_t7;
  const double _t53 = -_t49 + _t52;
  const double _t67 = 6.9203999999999999*_t14;
  const double _t68 = (0.1e1 / 0.3e1)*_t18;
  const double _t76 = 3.4601999999999999*_t21;
  const double _t80 = _t49 + _t52;
  const double _t37 = _t30*_t36;
  const double _t48 = _hc1[2]*_t43 + _t22*_t42 + _t22*_t47;
  const double _t54 = _hc1[1]*_t53;
  const double _t55 = -_hc1[4]*_t23;
  const double _t56 = _hc1[3]*_t27 + _t55;
  const double _t57 = _t27*_t56;
  const double _t58 = _hc0[2]*_t43;
  const double _t59 = -_hc0[5]*_t23;
  const double _t60 = _hc0[4]*_t27 + _t59;
  const double _t61 = -_hc0[4]*_t23;
  const double _t62 = _hc0[3]*_t27 + _t61;
  const double _t63 = _hc0[1]*_t53 - _t23*_t60 + _t27*_t62 + _t58;
  const double _t64 = -_hc1[5]*_t23;
  const double _t65 = _hc1[4]*_t27 + _t64;
  const double _t66 = _t15*_t63 - _t23*_t65 + _t54 + _t57;
  const double _t69 = _hc0[0]*_t36 - _hc1[2]*_t68;
  const double _t70 = _hc1[3]*_t32 + _t55;
  const double _t71 = _t27*_t70;
  const double _t72 = _hc0[3]*_t32 + _t61;
  const double _t73 = _hc0[4]*_t32 + _t59;
  const double _t74 = -_t23*_t73 + _t58;
  const double _t75 = _hc0[1]*_t52 + _t27*_t72 + _t74;
  const double _t77 = _hc1[4]*_t32 + _t64;
  const double _t78 = -_t23*_t77 + _t48;
  const double _t79 = _t34*_t36;
  const double _t81 = _hc1[1]*_t80;
  const double _t82 = _t32*_t70;
  const double _t83 = _hc0[1]*_t80 + _t32*_t72 + _t74;
  const double _t84 = _t15*_t83 + _t81 + _t82;
  const double d2F_dna2 = _t1*(_t37 + _t48 + _t66) + 0.2e1*_t28 + _t30*_t67 + _t69;
  const double d2F_dna_dnb = _t1*(_hc1[1]*_t52 + _t15*_t75 + _t30*_t76 + _t34*_t76 + _t71 + _t78) + _t31 + _t35 + _t69;
  const double d2F_dnb2 = _t1*(_t78 + _t79 + _t84) + 0.2e1*_t33 + _t34*_t67 + _t69;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t85 = 10.380599999999999*_t21;
  const double _t86 = (0.4e1 / 0.9e1)*_t39;
  const double _t88 = 10.380599999999999*_t42;
  const double _t89 = 10.380599999999999*_t47;
  const double _t91 = _t4/xc_powr(_t1, 10, 3);
  const double _t92 = xc_powr(_t1, -11, 3);
  const double _t93 = (0.20e2 / 0.27e2)*_t10*_t11*_t92 - 0.46666666666666667*_t91;
  const double _t95 = (0.14e2 / 0.27e2)*_t91;
  const double _t96 = 0.39999999999999997*_t39 - 0.5e1 / 0.9e1*_t40;
  const double _t97 = _t44*_t96;
  const double _t101 = (0.1e1 / (_t13 * _t13 * _t13 * _t13));
  const double _t102 = (0.1e1 / 0.2e1)*_t10*_t11*_t19 - 0.44999999999999996*_t18;
  const double _t103 = _t101*_t102;
  const double _t104 = _t103*_t45;
  const double _t106 = 0.6e1*_t50;
  const double _t107 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t108 = _t107*_t7;
  const double _t109 = 0.6e1*_t108;
  const double _t110 = _t106 - _t109;
  const double _t119 = 0.2e1*_t53;
  const double _t138 = 10.380599999999999*_t14;
  const double _t140 = (0.1e1 / 0.2e1)*_t18;
  const double _t141 = (0.2e1 / 0.3e1)*_t39;
  const double _t144 = -_t109 + 0.2e1*_t50;
  const double _t160 = 3.4601999999999999*_t42;
  const double _t161 = 6.9203999999999999*_t42;
  const double _t165 = 3.4601999999999999*_t47;
  const double _t166 = 6.9203999999999999*_t47;
  const double _t167 = 0.4e1*_t50;
  const double _t176 = _t167*_t7;
  const double _t182 = -_t106 - _t109;
  const double _t185 = 0.2e1*_t80;
  const double _t87 = _t65*_t86;
  const double _t90 = _t30*_t88 + _t30*_t89;
  const double _t94 = _t17*_t22;
  const double _t98 = _t20*_t22;
  const double _t99 = _hc0[0]*_t41;
  const double _t100 = _t46*_t99;
  const double _t105 = -_hc1[2]*_t95 + 6.9203999999999999*_t100 + _t104*_t98 + _t93*_t94 + _t97*_t98;
  const double _t111 = _hc1[1]*_t110;
  const double _t112 = _hc1[4]*_t43;
  const double _t113 = -_hc1[8]*_t23;
  const double _t114 = _hc1[7]*_t27 + _t113;
  const double _t115 = -_hc1[7]*_t23;
  const double _t116 = _hc1[6]*_t27 + _t115;
  const double _t117 = _hc1[3]*_t53 + _t112 - _t114*_t23 + _t116*_t27;
  const double _t118 = _t117*_t27;
  const double _t120 = _hc0[2]*_t95;
  const double _t121 = -_t120;
  const double _t122 = _hc0[5]*_t43;
  const double _t123 = -_hc0[9]*_t23;
  const double _t124 = _hc0[8]*_t27 + _t123;
  const double _t125 = -_hc0[8]*_t23;
  const double _t126 = _hc0[7]*_t27 + _t125;
  const double _t127 = _hc0[4]*_t53 + _t122 - _t124*_t23 + _t126*_t27;
  const double _t128 = _hc0[4]*_t43;
  const double _t129 = -_hc0[7]*_t23;
  const double _t130 = _hc0[6]*_t27 + _t129;
  const double _t131 = _hc0[3]*_t53 - _t126*_t23 + _t128 + _t130*_t27;
  const double _t132 = _hc0[1]*_t110 + _t119*_t62 + _t121 - _t127*_t23 + _t131*_t27 + _t60*_t86;
  const double _t133 = _hc1[5]*_t43;
  const double _t134 = -_hc1[9]*_t23;
  const double _t135 = _hc1[8]*_t27 + _t134;
  const double _t136 = _hc1[4]*_t53 + _t114*_t27 + _t133 - _t135*_t23;
  const double _t137 = _t111 + _t118 + _t119*_t56 + _t132*_t15 - _t136*_t23;
  const double _t139 = _t21*_t30;
  const double _t142 = _hc0[0]*_t88 + _hc0[0]*_t89 + _hc1[2]*_t141;
  const double _t143 = _t36*_t75;
  const double _t145 = _hc1[1]*_t144;
  const double _t146 = _hc1[6]*_t32 + _t115;
  const double _t147 = _hc1[7]*_t32 + _t113;
  const double _t148 = _t112 - _t147*_t23;
  const double _t149 = _hc1[3]*_t52 + _t146*_t27 + _t148;
  const double _t150 = _t149*_t27;
  const double _t151 = _t53*_t70;
  const double _t152 = _hc0[7]*_t32 + _t125;
  const double _t153 = _hc0[8]*_t32 + _t123;
  const double _t154 = _t122 - _t153*_t23;
  const double _t155 = _hc0[4]*_t52 + _t152*_t27 + _t154;
  const double _t156 = _hc0[6]*_t32 + _t129;
  const double _t157 = _t128 - _t152*_t23;
  const double _t158 = _hc0[3]*_t52 + _t156*_t27 + _t157;
  const double _t159 = _hc0[1]*_t144 + _t121 - _t155*_t23 + _t158*_t27 + _t43*_t60 + _t43*_t73 + _t52*_t62 + _t53*_t72;
  const double _t162 = _hc1[8]*_t32 + _t134;
  const double _t163 = _t133 - _t162*_t23;
  const double _t164 = _hc1[4]*_t52 + _t147*_t27 + _t163;
  const double _t168 = _hc1[1]*_t167;
  const double _t169 = _t168*_t7 + _t67*_t75 + 0.2e1*_t71;
  const double _t170 = _hc1[3]*_t80 + _t146*_t32 + _t148;
  const double _t171 = _t170*_t27;
  const double _t172 = _hc0[4]*_t80 + _t152*_t32 + _t154;
  const double _t173 = _t172*_t23;
  const double _t174 = _hc0[3]*_t80 + _t156*_t32 + _t157;
  const double _t175 = -_hc0[1]*_t109 - _hc0[1]*_t51 - _t120 - _t173 + _t174*_t27 + (0.4e1 / 0.9e1)*_t2*_t3*_t38*_t73 + 0.4e1*_t50*_t7*_t72;
  const double _t177 = _hc1[4]*_t80 + _t147*_t32 + _t163;
  const double _t178 = _t105 - _t177*_t23 + _t77*_t86;
  const double _t179 = _t21*_t34;
  const double _t180 = -_t140*_t77 + _t142;
  const double _t181 = _t34*_t88 + _t34*_t89;
  const double _t183 = _hc1[1]*_t182;
  const double _t184 = _t170*_t32;
  const double _t186 = _hc0[1]*_t182 + _t121 - _t173 + _t174*_t32 + _t185*_t72 + _t73*_t86;
  const double _t187 = _t15*_t186 + _t183 + _t184 + _t185*_t70;
  const double d3F_dna3 = _t1*(_t105 + _t137 + _t63*_t85 + _t87 + _t90) + _t138*_t63 + 20.761199999999999*_t139 - _t140*_t65 + _t142 + 0.3e1*_t54 + 0.3e1*_t57;
  const double d3F_dna2_dnb = _t1*(_t105 + _t143 + _t145 + _t15*_t159 + _t150 + _t151 + _t160*_t34 + _t161*_t30 - _t164*_t23 + _t165*_t34 + _t166*_t30 + _t43*_t65 + _t43*_t77 + _t52*_t56 + _t63*_t76) + 13.8408*_t139 + _t142 + _t169 + _t66 - _t68*_t77 + _t79;
  const double d3F_dna_dnb2 = _t1*(-_hc1[1]*_t109 - _hc1[1]*_t51 + _t143 + _t15*_t175 + _t160*_t30 + _t161*_t34 + _t165*_t30 + _t166*_t34 + _t171 + _t176*_t70 + _t178 + _t76*_t83) + _t169 + 13.8408*_t179 + _t180 + _t37 + _t84;
  const double d3F_dnb3 = _t1*(_t178 + _t181 + _t187 + _t83*_t85) + _t138*_t83 + 20.761199999999999*_t179 + _t180 + 0.3e1*_t81 + 0.3e1*_t82;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t188 = 0.24e2*_t107;
  const double _t189 = 0.24e2*_t7/xc_powi(_t1, 5);
  const double _t190 = -_t188 + _t189;
  const double _t201 = 0.3e1*_t53;
  const double _t202 = 0.3e1*_t110;
  const double _t203 = _t4/xc_powr(_t1, 13, 3);
  const double _t204 = (0.140e3 / 0.81e2)*_t203;
  const double _t206 = (0.14e2 / 0.9e1)*_t91;
  const double _t222 = _t17*_t93;
  const double _t224 = 13.8408*_t21;
  const double _t229 = _t20*_t97;
  const double _t230 = _t41*_t46;
  const double _t232 = _t104*_t20;
  const double _t233 = 10.380599999999999*_t97;
  const double _t234 = 10.380599999999999*_t104;
  const double _t238 = 13.8408*_t14;
  const double _t240 = 41.522399999999998*_t21;
  const double _t241 = (0.2e1 / 0.3e1)*_t18;
  const double _t244 = 13.8408*_t222;
  const double _t245 = 13.8408*_t229;
  const double _t249 = 0.12e2*_t107;
  const double _t250 = _t189 - _t249;
  const double _t257 = 0.2e1*_t144;
  const double _t264 = (0.28e2 / 0.27e2)*_t91;
  const double _t270 = _t20*_t233;
  const double _t273 = _t20*_t234;
  const double _t277 = _t106*_t7;
  const double _t293 = _t50*_t7;
  const double _t299 = 0.18e2*_t108;
  const double _t304 = _t188 + _t189;
  const double _t305 = 0.3e1*_t182;
  const double _t306 = 0.3e1*_t80;
  const double _t191 = _hc1[4]*_t95;
  const double _t192 = -_t191;
  const double _t193 = _hc1[8]*_t43;
  const double _t194 = -_hc1[13]*_t23;
  const double _t195 = _hc1[12]*_t27 + _t194;
  const double _t196 = -_hc1[12]*_t23;
  const double _t197 = _hc1[11]*_t27 + _t196;
  const double _t198 = _hc1[7]*_t53 + _t193 - _t195*_t23 + _t197*_t27;
  const double _t199 = _hc1[7]*_t43;
  const double _t200 = -_hc1[11]*_t23;
  const double _t205 = _hc0[2]*_t204;
  const double _t207 = _hc0[5]*_t95;
  const double _t208 = -_t207;
  const double _t209 = _hc0[9]*_t43;
  const double _t210 = -_hc0[14]*_t23;
  const double _t211 = -_hc0[13]*_t23;
  const double _t212 = _hc0[12]*_t27 + _t211;
  const double _t213 = _hc0[8]*_t43;
  const double _t214 = -_hc0[12]*_t23;
  const double _t215 = _hc0[11]*_t27 + _t214;
  const double _t216 = _hc0[7]*_t53 - _t212*_t23 + _t213 + _t215*_t27;
  const double _t217 = _hc0[4]*_t95;
  const double _t218 = -_t217;
  const double _t219 = _hc0[7]*_t43;
  const double _t220 = -_hc0[11]*_t23;
  const double _t221 = 20.761199999999999*_t63;
  const double _t223 = 13.8408*_t30;
  const double _t225 = _hc1[5]*_t95;
  const double _t226 = -_t225;
  const double _t227 = _hc1[9]*_t43;
  const double _t228 = -_hc1[14]*_t23;
  const double _t231 = _t230*_t30;
  const double _t235 = _t45*_t98;
  const double _t236 = _hc0[0]*_t20;
  const double _t237 = 10.380599999999999*_hc0[0]*_t46*_t93 + _hc1[2]*_t204 + _t101*_t235*(0.59999999999999987*_t39 - 0.5e1 / 0.6e1*_t40) + _t102*_t235*((0.2e1 / 0.3e1)*_t10*_t11*_t19 - 0.59999999999999998*_t18)/xc_powi(_t13, 5) + 6.9203999999999999*_t103*_t236*_t96 + _t233*_t99 + _t234*_t99 + _t44*_t98*((0.40e2 / 0.27e2)*_t10*_t11*_t92 - 0.93333333333333335*_t91) + _t94*(1.5555555555555556*_t203 - 0.220e3 / 0.81e2*_t12/xc_powr(_t1, 14, 3));
  const double _t239 = _t30*_t42;
  const double _t242 = _t39*_t65;
  const double _t243 = _t30*_t47;
  const double _t246 = _hc0[0]*_t244 + _hc0[0]*_t245 - 0.56e2 / 0.27e2*_hc1[2]*_t91 + 27.681599999999996*_t100 + 13.8408*_t104*_t236;
  const double _t247 = _t21*_t75;
  const double _t248 = 20.761199999999999*_t247;
  const double _t251 = _hc1[11]*_t32 + _t196;
  const double _t252 = _hc1[12]*_t32 + _t194;
  const double _t253 = _t193 - _t23*_t252;
  const double _t254 = _hc1[7]*_t52 + _t251*_t27 + _t253;
  const double _t255 = _hc1[10]*_t32 + _t200;
  const double _t256 = _t199 - _t23*_t251;
  const double _t258 = _hc0[11]*_t32 + _t214;
  const double _t259 = _hc0[12]*_t32 + _t211;
  const double _t260 = _t213 - _t23*_t259;
  const double _t261 = _hc0[7]*_t52 + _t258*_t27 + _t260;
  const double _t262 = _hc0[10]*_t32 + _t220;
  const double _t263 = _t219 - _t23*_t258;
  const double _t265 = _t209 - _t23*(_hc0[13]*_t32 + _t210);
  const double _t266 = _t155*_t86 + _t205;
  const double _t267 = _t222*_t30;
  const double _t268 = _t222*_t34;
  const double _t269 = _t227 - _t23*(_hc1[13]*_t32 + _t228);
  const double _t271 = _t229*_t34;
  const double _t272 = _t230*_t34;
  const double _t274 = _t232*_t34;
  const double _t275 = _t75*_t88 + _t75*_t89;
  const double _t276 = _t164*_t86 + _t237;
  const double _t278 = _hc1[1]*_t189;
  const double _t279 = _hc1[7]*_t80 + _t251*_t32 + _t253;
  const double _t280 = _t23*_t279;
  const double _t281 = _hc1[6]*_t80 + _t255*_t32 + _t256;
  const double _t282 = _hc0[1]*_t189;
  const double _t283 = _hc0[7]*_t80 + _t258*_t32 + _t260;
  const double _t284 = _t23*_t283;
  const double _t285 = _hc0[6]*_t80 + _t262*_t32 + _t263;
  const double _t286 = _t23*(_hc0[8]*_t80 + _t259*_t32 + _t265);
  const double _t287 = 13.8408*_t75;
  const double _t288 = _t23*(_hc1[8]*_t80 + _t252*_t32 + _t269);
  const double _t289 = _t229*_t30;
  const double _t290 = _t232*_t30;
  const double _t291 = _hc1[1]*_t249;
  const double _t292 = 0.8e1*_t70;
  const double _t294 = _t34*_t42;
  const double _t295 = _t39*_t77;
  const double _t296 = _t34*_t47;
  const double _t297 = _hc1[3]*_t182 + _t146*_t185 + _t147*_t86 + _t192 - _t280 + _t281*_t32;
  const double _t298 = _hc0[3]*_t182 + _t152*_t86 + _t156*_t185 + _t218 - _t284 + _t285*_t32;
  const double _t300 = _t141*_t172 + _t205 - _t206*_t73 - _t23*(_hc0[4]*_t182 + _t152*_t185 + _t153*_t86 + _t208 + _t283*_t32 - _t286);
  const double _t301 = _t141*_t177 - _t206*_t77 - _t23*(_hc1[4]*_t182 + _t147*_t185 + _t162*_t86 + _t226 + _t279*_t32 - _t288) + _t237;
  const double _t302 = 20.761199999999999*_t83;
  const double _t303 = -_t177*_t241 + _t246 + (0.16e2 / 0.9e1)*_t295;
  const double d4F_dna4 = _t1*(_hc1[1]*_t190 + _t117*_t201 + _t132*_t224 + _t136*_t141 + _t15*(_hc0[1]*_t190 + _t127*_t141 + _t131*_t201 + _t202*_t62 + _t205 - _t206*_t60 - _t23*(_hc0[4]*_t110 + _t119*_t126 + _t124*_t86 + _t208 + _t216*_t27 - _t23*(_hc0[8]*_t53 + _t209 + _t212*_t27 - _t23*(_hc0[13]*_t27 + _t210))) + _t27*(_hc0[3]*_t110 + _t119*_t130 + _t126*_t86 - _t216*_t23 + _t218 + _t27*(_hc0[6]*_t53 - _t215*_t23 + _t219 + _t27*(_hc0[10]*_t27 + _t220)))) + _t202*_t56 - _t206*_t65 + _t221*_t42 + _t221*_t47 + _t222*_t223 + _t223*_t229 + _t223*_t232 - _t23*(_hc1[4]*_t110 + _t114*_t119 + _t135*_t86 + _t198*_t27 + _t226 - _t23*(_hc1[8]*_t53 + _t195*_t27 + _t227 - _t23*(_hc1[13]*_t27 + _t228))) + 27.6816*_t231 + _t237 + _t27*(_hc1[3]*_t110 + _t114*_t86 + _t116*_t119 + _t192 - _t198*_t23 + _t27*(_hc1[6]*_t53 - _t197*_t23 + _t199 + _t27*(_hc1[10]*_t27 + _t200)))) + 0.4e1*_t111 + 0.4e1*_t118 + _t132*_t238 - _t136*_t241 + 41.522399999999998*_t239 + _t240*_t63 + (0.16e2 / 0.9e1)*_t242 + 41.522399999999998*_t243 + _t246 + 0.8e1*_t53*_t56;
  const double d4F_dna3_dnb = _t1*(_hc1[1]*_t250 + _t110*_t70 + _t117*_t52 + _t119*_t149 + _t132*_t76 + _t136*_t43 + _t15*(_hc0[1]*_t250 + _t110*_t72 + _t119*_t158 + _t127*_t43 + _t131*_t52 - _t23*(_hc0[4]*_t144 + _t124*_t43 + _t126*_t52 + _t152*_t53 + _t153*_t43 + _t208 - _t23*(_hc0[8]*_t52 + _t259*_t27 + _t265) + _t261*_t27) + _t257*_t62 - _t264*_t60 + _t266 + _t27*(_hc0[3]*_t144 + _t126*_t43 + _t130*_t52 + _t152*_t43 + _t156*_t53 + _t218 - _t23*_t261 + _t27*(_hc0[6]*_t52 + _t262*_t27 + _t263)) - _t73*_t95) + _t159*_t85 - _t23*(_hc1[4]*_t144 + _t114*_t52 + _t135*_t43 + _t147*_t53 + _t162*_t43 + _t226 - _t23*(_hc1[8]*_t52 + _t252*_t27 + _t269) + _t254*_t27) + 20.761199999999999*_t231 + _t257*_t56 - _t264*_t65 + 10.380599999999999*_t267 + 3.4601999999999999*_t268 + _t27*(_hc1[3]*_t144 + _t114*_t43 + _t116*_t52 + _t146*_t53 + _t147*_t43 + _t192 - _t23*_t254 + _t27*(_hc1[6]*_t52 + _t255*_t27 + _t256)) + _t270*_t30 + 3.4601999999999999*_t271 + 6.9203999999999999*_t272 + _t273*_t30 + 3.4601999999999999*_t274 + _t275 + _t276 + _t63*_t88 + _t63*_t89 - _t77*_t95) + _t137 + _t138*_t159 - _t140*_t164 + _t141*_t77 + 0.3e1*_t145 + 0.3e1*_t150 + 0.3e1*_t151 + _t181 + _t21*_t221 + 31.141799999999996*_t239 + (0.10e2 / 0.9e1)*_t242 + 31.141799999999996*_t243 + _t246 + _t248 + _t277*_t56;
  const double d4F_dna2_dnb2 = _t1*(-_t109*_t56 + _t149*_t176 + _t15*(-_t109*_t62 + _t158*_t176 + _t172*_t43 + _t174*_t53 - _t23*(-_hc0[4]*_t109 - _hc0[4]*_t51 + 0.4e1*_t152*_t50*_t7 + (0.4e1 / 0.9e1)*_t153*_t2*_t3*_t38 - _t207 + _t27*_t283 - _t286) + _t257*_t72 - _t264*_t73 + _t266 + _t27*(-_hc0[3]*_t109 - _hc0[3]*_t51 + (0.4e1 / 0.9e1)*_t152*_t2*_t3*_t38 + 0.4e1*_t156*_t50*_t7 - _t217 + _t27*_t285 - _t284) + _t282 - _t51*_t62 - _t60*_t95) + _t159*_t36 + _t160*_t63 + _t160*_t83 + _t165*_t63 + _t165*_t83 + _t170*_t53 + _t175*_t36 + _t177*_t43 + _t223*_t230 - _t23*(-_hc1[4]*_t109 - _hc1[4]*_t51 + 0.4e1*_t147*_t50*_t7 + (0.4e1 / 0.9e1)*_t162*_t2*_t3*_t38 - _t225 + _t27*_t279 - _t288) + _t257*_t70 - _t264*_t77 + 6.9203999999999999*_t267 + 6.9203999999999999*_t268 + _t27*(-_hc1[3]*_t109 - _hc1[3]*_t51 + 0.4e1*_t146*_t50*_t7 + (0.4e1 / 0.9e1)*_t147*_t2*_t3*_t38 - _t191 + _t27*_t281 - _t280) + 6.9203999999999999*_t271 + 13.8408*_t272 + 6.9203999999999999*_t274 + _t276 + _t278 + _t287*_t42 + _t287*_t47 + 6.9203999999999999*_t289 + 6.9203999999999999*_t290 - _t51*_t56 - _t65*_t95) + 0.2e1*_t145 + 0.2e1*_t150 + 0.2e1*_t151 + _t159*_t67 - _t164*_t68 - _t168 + 0.2e1*_t171 + _t175*_t67 + _t176*_t56 - _t177*_t68 + 20.761199999999999*_t239 + 20.761199999999999*_t243 + _t246 + 27.6816*_t247 - _t291*_t7 + _t292*_t293 + 20.761199999999999*_t294 + (0.4e1 / 0.3e1)*_t295 + 20.761199999999999*_t296 + _t36*_t63 + _t36*_t83 + _t87;
  const double d4F_dna_dnb3 = -_hc1[1]*_t106 - _hc1[1]*_t299 + _t1*(-_t106*_t70 + _t15*(_hc0[1]*_t249 - _t106*_t72 + _t174*_t277 + _t27*_t298 + _t282 - _t299*_t72 + _t300) + _t170*_t277 + _t175*_t85 + _t186*_t76 + 6.9203999999999999*_t231 + 3.4601999999999999*_t267 + 10.380599999999999*_t268 + _t27*_t297 + _t270*_t34 + 20.761199999999999*_t272 + _t273*_t34 + _t275 + _t278 + 3.4601999999999999*_t289 + 3.4601999999999999*_t290 + _t291 - _t299*_t70 + _t301 + _t83*_t88 + _t83*_t89) + _t138*_t175 + 0.3e1*_t171 + _t187 + _t21*_t302 + _t248 + 0.12e2*_t293*_t70 + 31.141799999999996*_t294 + 31.141799999999996*_t296 + _t303 + _t90;
  const double d4F_dnb4 = _t1*(_hc1[1]*_t304 + _t15*(_hc0[1]*_t304 + _t174*_t306 + _t298*_t32 + _t300 + _t305*_t72) + _t170*_t306 + _t186*_t224 + _t244*_t34 + _t245*_t34 + 27.6816*_t272 + 13.8408*_t274 + _t297*_t32 + _t301 + _t302*_t42 + _t302*_t47 + _t305*_t70) + 0.4e1*_t183 + 0.4e1*_t184 + _t186*_t238 + _t240*_t83 + _t292*_t80 + 41.522399999999998*_t294 + 41.522399999999998*_t296 + _t303;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif