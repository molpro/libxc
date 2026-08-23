/*
  Generated from python/lda_exc/lda_c_2d_amgb.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_2d_amgb
*/

#ifndef _LDA_C_2D_AMGB_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_2D_AMGB_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_2D_AMGB_HELPER_BODIES
#include "lda_c_2d_amgb.c"
#undef _LDA_C_2D_AMGB_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_2D_AMGB_HELPER_BODIES
#include "lda_c_2d_amgb.c"
#undef _LDA_C_2D_AMGB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_2D_AMGB_HELPER_BODIES
#include "lda_c_2d_amgb.c"
#undef _LDA_C_2D_AMGB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_2D_AMGB_HELPER_BODIES
#include "lda_c_2d_amgb.c"
#undef _LDA_C_2D_AMGB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_2D_AMGB_HELPER_BODIES
#include "lda_c_2d_amgb.c"
#undef _LDA_C_2D_AMGB_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_2d_amgb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_2D_AMGB_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_zeta_2d_m1_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.3e1 / 0.2e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.3e1 / 0.2e1, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5];
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = (0.1e1 / 0.2e1)*_hc0[9] - 0.1e1 / 0.2e1*_hc1[9];
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.1e1 / 0.2e1)*_hc0[14] + (0.1e1 / 0.2e1)*_hc1[14];
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(amgb_ex6_residual_orig_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_2d_m1_k, _KMAX)(p, z, _hc0);
  const double _t1 = (z * z);

  const double f = _hc0[0] - 0.3e1 / 0.8e1*_t1 - 0.3e1 / 0.128e3*(z * z * z * z);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[1] - 0.3e1 / 0.32e2*(z * z * z) - 0.3e1 / 0.4e1*z;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[2] - 0.9e1 / 0.32e2*_t1 - 0.3e1 / 0.4e1;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[3] - 0.9e1 / 0.16e2*z;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc0[4] - 0.9e1 / 0.16e2;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(amgb_ex6_residual_taylor_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = xc_powi(z, 6);
  const double _t2 = xc_powi(z, 8);
  const double _t3 = xc_powi(z, 10);
  const double _t4 = xc_powi(z, 12);
  const double _t5 = xc_powi(z, 14);
  const double _t6 = xc_powi(z, 16);
  const double _t7 = xc_powi(z, 18);
  const double _t8 = xc_powi(z, 20);
  const double _t9 = xc_powi(z, 22);
  const double _t10 = xc_powi(z, 24);
  const double _t11 = xc_powi(z, 26);
  const double _t12 = xc_powi(z, 28);
#if _KMAX >= 1
  const double _t13 = xc_powi(z, 5);
  const double _t14 = xc_powi(z, 7);
  const double _t15 = xc_powi(z, 9);
  const double _t16 = xc_powi(z, 11);
  const double _t17 = xc_powi(z, 13);
  const double _t18 = xc_powi(z, 15);
  const double _t19 = xc_powi(z, 17);
  const double _t20 = xc_powi(z, 19);
  const double _t21 = xc_powi(z, 21);
  const double _t22 = xc_powi(z, 23);
  const double _t23 = xc_powi(z, 25);
  const double _t24 = xc_powi(z, 27);
#endif
#if _KMAX >= 2
  const double _t25 = (z * z * z * z);
#endif

  const double f = (0.7e1 / 0.1024e4)*_t1 + (0.11435320455e11 / 0.70368744177664e14)*_t10 + (0.74417546961e11 / 0.562949953421312e15)*_t11 + (0.983965343151e12 / 0.9007199254740992e16)*_t12 + (0.99e2 / 0.32768e5)*_t2 + (0.429e3 / 0.262144e6)*_t3 + (0.4199e4 / 0.4194304e7)*_t4 + (0.22287e5 / 0.33554432e8)*_t5 + (0.1002915e7 / 0.2147483648e10)*_t6 + (0.5892945e7 / 0.17179869184e11)*_t7 + (0.71645805e8 / 0.274877906944e12)*_t8 + (0.447553665e9 / 0.2199023255552e13)*_t9 + (0.6593698793759e13 / 0.72057594037927936e17)*xc_powi(z, 30);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.21e2 / 0.512e3)*_t13 + (0.99e2 / 0.4096e4)*_t14 + (0.2145e4 / 0.131072e6)*_t15 + (0.12597e5 / 0.1048576e7)*_t16 + (0.156009e6 / 0.16777216e8)*_t17 + (0.1002915e7 / 0.134217728e9)*_t18 + (0.53036505e8 / 0.8589934592e10)*_t19 + (0.358229025e9 / 0.68719476736e11)*_t20 + (0.4923090315e10 / 0.1099511627776e13)*_t21 + (0.34305961365e11 / 0.8796093022208e13)*_t22 + (0.967428110493e12 / 0.281474976710656e15)*_t23 + (0.6887757402057e13 / 0.2251799813685248e16)*_t24 + (0.98905481906385e14 / 0.36028797018963968e17)*xc_powi(z, 29);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.693e3 / 0.4096e4)*_t1 + (0.24185702762325e14 / 0.281474976710656e15)*_t10 + (0.185969449855539e15 / 0.2251799813685248e16)*_t11 + (0.2868258975285165e16 / 0.36028797018963968e17)*_t12 + (0.19305e5 / 0.131072e6)*_t2 + (0.105e3 / 0.512e3)*_t25 + (0.138567e6 / 0.1048576e7)*_t3 + (0.2028117e7 / 0.16777216e8)*_t4 + (0.15043725e8 / 0.134217728e9)*_t5 + (0.901620585e9 / 0.8589934592e10)*_t6 + (0.6806351475e10 / 0.68719476736e11)*_t7 + (0.103384896615e12 / 0.1099511627776e13)*_t8 + (0.789037111395e12 / 0.8796093022208e13)*_t9;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = (0.2079e4 / 0.2048e4)*_t13 + (0.19305e5 / 0.16384e5)*_t14 + (0.692835e6 / 0.524288e6)*_t15 + (0.6084351e7 / 0.4194304e7)*_t16 + (0.105306075e9 / 0.67108864e8)*_t17 + (0.901620585e9 / 0.536870912e9)*_t18 + (0.61257163275e11 / 0.34359738368e11)*_t19 + (0.516924483075e12 / 0.274877906944e12)*_t20 + (0.8679408225345e13 / 0.4398046511104e13)*_t21 + (0.72557108286975e14 / 0.35184372088832e14)*_t22 + (0.2417602848122007e16 / 0.1125899906842624e16)*_t23 + (0.20077812826996155e17 / 0.9007199254740992e16)*_t24 + (0.105e3 / 0.128e3)*(z * z * z);
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.135135e6 / 0.16384e5)*_t1 + (0.60440071203050175e17 / 0.1125899906842624e16)*_t10 + (0.542100946328896185e18 / 0.9007199254740992e16)*_t11 + (0.6235515e7 / 0.524288e6)*_t2 + (0.10395e5 / 0.2048e4)*_t25 + (0.66927861e8 / 0.4194304e7)*_t3 + (0.1368978975e10 / 0.67108864e8)*_t4 + (0.13524308775e11 / 0.536870912e9)*_t5 + (0.1041371775675e13 / 0.34359738368e11)*_t6 + (0.9821565178425e13 / 0.274877906944e12)*_t7 + (0.182267572732245e15 / 0.4398046511104e13)*_t8 + (0.1668813490600425e16 / 0.35184372088832e14)*_t9 + (0.315e3 / 0.128e3)*(z * z);
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(amgb_ex6_residual_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(amgb_ex6_residual_taylor_k, _KMAX)(p, z, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(amgb_ex6_residual_orig_k, _KMAX)(p, z, _hc1);
  const double _t1 = my_piecewise3(z >= 0, z, -z) < 0.1e1 / 0.2e1;

  const double f = my_piecewise3(_t1, _hc0[0], _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t1, _hc0[1], _hc1[1]);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t1, _hc0[2], _hc1[2]);
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t1, _hc0[3], _hc1[3]);
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t1, _hc0[4], _hc1[4]);
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(amgb_ex6_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(amgb_ex6_residual_k, _KMAX)(p, z, _hc0);
  const double _t1 = xc_powr(0.2e1, 1, 2)/M_PI;
  const double _t2 = (0.4e1 / 0.3e1)*_t1;
  const double _t3 = _t2/rs;
#if _KMAX >= 1
  const double _t4 = _t2/(rs * rs);
#endif
#if _KMAX >= 2
  const double _t5 = _hc0[0]*_t1;
  const double _t6 = (0.8e1 / 0.3e1)/(rs * rs * rs);
#endif
#if _KMAX >= 3
  const double _t7 = _t1*_t6;
  const double _t8 = 0.8e1/(rs * rs * rs * rs);
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
  const double d4f_drs4 = -0.32e2*_t5/xc_powi(rs, 5);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_amgb_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(amgb_ex6_k, _KMAX)(p, rs, z, _hc0);
  const double _t1 = xc_expm1(-1.3386*rs);
  const double _t2 = (z * z * z * z);
  const double _t3 = (rs * rs * rs);
  const double _t4 = 1.1630990000000001*_t3 + 1.424301*rs;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = xc_log1p(_t5);
  const double _t7 = (rs * rs);
  const double _t8 = 0.027238382861200002*_t3 - 0.016361799999999999*_t7 + 0.037093000000000001*rs;
  const double _t9 = -_t8;
  const double _t10 = _t6*_t9;
  const double _t11 = _t10 + 0.0234188;
  const double _t12 = 0.0033629749999999998*_t3 + 0.057238400000000002*_t7 + 0.086313600000000004*rs;
  const double _t13 = pow(rs, 1.5);
  const double _t14 = -0.02069*_t13 + 0.017469999999999999*_t3 + 0.33996999999999999*_t7 + 1.0022*rs;
  const double _t15 = (0.1e1 / _t14);
  const double _t16 = xc_log1p(_t15);
  const double _t17 = (z * z);
  const double _t18 = 9.1506446900000012e-5*_t3 + 0.0076676499999999998*_t7 + 0.033939999999999998*rs;
  const double _t19 = -_t18;
  const double _t20 = 0.00077990000000000004*_t3 + 0.066846699999999995*_t7 + 0.4133*rs;
  const double _t21 = (0.1e1 / _t20);
  const double _t22 = xc_log1p(_t21);
  const double _t23 = _t19*_t22;
  const double _t24 = _t23 + 0.117331;
#if _KMAX >= 1
  const double _t25 = 0.4e1*(z * z * z);
  const double _t26 = 0.2e1*z;
  const double _t27 = -1.3386*_t1 - 1.3386;
  const double _t28 = 0.010088924999999999*_t7 + 0.1144768*rs + 0.086313600000000004;
  const double _t29 = _t15 + 0.1e1;
  const double _t30 = (0.1e1 / _t29);
  const double _t31 = _t30/(_t14 * _t14);
  const double _t32 = sqrt(rs);
  const double _t33 = 0.031035*_t32 - 0.052409999999999998*_t7 - 0.67993999999999999*rs - 1.0022;
  const double _t34 = _t12*_t33;
  const double _t35 = -0.081715148583600003*_t7 + 0.032723599999999999*rs - 0.037093000000000001;
  const double _t36 = _t5 + 0.1e1;
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = (0.1e1 / (_t4 * _t4));
  const double _t39 = _t37*_t38;
  const double _t40 = -3.4892970000000005*_t7 - 1.424301;
  const double _t41 = _t40*_t9;
  const double _t42 = _t35*_t6 + _t39*_t41;
  const double _t43 = -0.00027451934070000004*_t7 - 0.0153353*rs - 0.033939999999999998;
  const double _t44 = _t22*_t43;
  const double _t45 = _t21 + 0.1e1;
  const double _t46 = (0.1e1 / _t45);
  const double _t47 = _t46/(_t20 * _t20);
  const double _t48 = -0.0023397000000000001*_t7 - 0.13369339999999999*rs - 0.4133;
  const double _t49 = _t19*_t48;
  const double _t50 = _t47*_t49;
  const double _t51 = _t44 + _t50;
#endif
#if _KMAX >= 2
  const double _t52 = 0.12e2*_t17;
  const double _t53 = 1.79184996*_t1 + 1.79184996;
  const double _t54 = 0.2e1*_t27;
  const double _t55 = 0.020177849999999997*rs + 0.1144768;
  const double _t56 = (0.1e1 / _t32);
  const double _t57 = 0.0155175*_t56 - 0.10482*rs - 0.67993999999999999;
  const double _t58 = _t12*_t31;
  const double _t59 = _t31*_t33;
  const double _t60 = -_t12;
  const double _t61 = (0.1e1 / (_t14 * _t14 * _t14 * _t14));
  const double _t62 = (0.1e1 / (_t29 * _t29));
  const double _t63 = (_t33 * _t33);
  const double _t64 = _t62*_t63;
  const double _t65 = _t61*_t64;
  const double _t66 = _t30/(_t14 * _t14 * _t14);
  const double _t67 = 0.06207*_t32 - 0.10482*_t7 - 1.35988*rs - 2.0044;
  const double _t68 = _t34*_t67;
  const double _t69 = 0.032723599999999999 - 0.16343029716720001*rs;
  const double _t70 = 6.9785940000000011*_t39*_t9;
  const double _t71 = _t35*_t39;
  const double _t72 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t73 = (0.1e1 / (_t36 * _t36));
  const double _t74 = (_t40 * _t40);
  const double _t75 = _t73*_t74;
  const double _t76 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t77 = _t37*_t76;
  const double _t78 = -6.9785940000000011*_t7 - 2.8486020000000001;
  const double _t79 = _t41*_t78;
  const double _t80 = 0.2e1*_t40*_t71 + _t6*_t69 - _t70*rs + _t72*_t75*_t8 + _t77*_t79;
  const double _t81 = -0.00054903868140000007*rs - 0.0153353;
  const double _t82 = _t22*_t81;
  const double _t83 = -0.0046794000000000002*rs - 0.13369339999999999;
  const double _t84 = _t19*_t47;
  const double _t85 = _t83*_t84;
  const double _t86 = _t43*_t47;
  const double _t87 = _t48*_t86;
  const double _t88 = (0.1e1 / (_t20 * _t20 * _t20 * _t20));
  const double _t89 = (0.1e1 / (_t45 * _t45));
  const double _t90 = (_t48 * _t48);
  const double _t91 = _t89*_t90;
  const double _t92 = _t88*_t91;
  const double _t93 = _t46/(_t20 * _t20 * _t20);
  const double _t94 = -0.0046794000000000002*_t7 - 0.26738679999999998*rs - 0.8266;
  const double _t95 = _t49*_t94;
  const double _t96 = _t93*_t95;
  const double _t97 = _t18*_t92 + _t82 + _t85 + 0.2e1*_t87 + _t96;
#endif
#if _KMAX >= 3
  const double _t98 = 0.24e2*z;
  const double _t99 = -2.3985703564560001*_t1 - 2.3985703564560001;
  const double _t100 = 0.3e1*_t53;
  const double _t101 = 0.3e1*_t27;
  const double _t102 = _t28*_t31;
  const double _t103 = 0.3e1*_t57;
  const double _t104 = (0.1e1 / _t13);
  const double _t105 = -0.00775875*_t104 - 0.10482;
  const double _t106 = (_t33 * _t33 * _t33);
  const double _t107 = (0.1e1 / (_t29 * _t29 * _t29));
  const double _t108 = xc_powi(_t14, -6);
  const double _t109 = _t107*_t108;
  const double _t110 = _t106*_t109;
  const double _t111 = 0.031035*_t56 - 0.20963999999999999*rs - 1.35988;
  const double _t112 = _t111*_t34;
  const double _t113 = _t61*_t62;
  const double _t114 = _t113*_t34;
  const double _t115 = 0.2e1*_t57;
  const double _t116 = _t12*_t67;
  const double _t117 = _t116*_t66;
  const double _t118 = _t28*_t67;
  const double _t119 = _t33*_t66;
  const double _t120 = xc_powi(_t14, -5);
  const double _t121 = _t120*_t64;
  const double _t122 = 0.12414*_t32 - 0.20963999999999999*_t7 - 2.71976*rs - 4.0087999999999999;
  const double _t123 = _t12*_t121;
  const double _t124 = 0.093104999999999993*_t32 - 0.15722999999999998*_t7 - 2.0398199999999997*rs - 3.0065999999999997;
  const double _t125 = _t30*_t61*_t68;
  const double _t126 = 20.935782000000003*rs;
  const double _t127 = _t78*_t9;
  const double _t128 = 13.957188000000002*_t77;
  const double _t129 = _t128*_t41;
  const double _t130 = (_t40 * _t40 * _t40);
  const double _t131 = xc_powi(_t4, -6);
  const double _t132 = (0.1e1 / (_t36 * _t36 * _t36));
  const double _t133 = -13.957188000000002*_t7 - 5.6972040000000002;
  const double _t134 = xc_powi(_t4, -5);
  const double _t135 = _t134*_t75;
  const double _t136 = _t133*_t135;
  const double _t137 = -10.467891000000002*_t7 - 4.2729030000000003;
  const double _t138 = -_t126*_t71 - _t127*_t128*rs - _t127*_t135 - _t129*rs + _t130*_t131*_t132*(-0.054476765722400004*_t3 + 0.032723599999999999*_t7 - 0.074186000000000002*rs) - _t136*_t9 + _t137*_t37*_t40*_t72*_t78*_t9 + 0.3e1*_t35*_t37*_t40*_t76*_t78 + 0.3e1*_t37*_t38*_t40*_t69 + 20.935782000000003*_t40*_t72*_t73*_t9*rs - 0.16343029716720001*_t6 - _t70 + _t72*_t73*_t74*(0.2451454457508*_t7 - 0.098170800000000003*rs + 0.111279);
  const double _t139 = 0.3e1*_t83;
  const double _t140 = _t47*_t48;
  const double _t141 = 0.00018301289380000002*_t3 + 0.0153353*_t7 + 0.067879999999999996*rs;
  const double _t142 = (_t48 * _t48 * _t48);
  const double _t143 = (0.1e1 / (_t45 * _t45 * _t45));
  const double _t144 = xc_powi(_t20, -6);
  const double _t145 = _t143*_t144;
  const double _t146 = _t142*_t145;
  const double _t147 = -0.0093588000000000005*rs - 0.26738679999999998;
  const double _t148 = _t147*_t49;
  const double _t149 = _t88*_t89;
  const double _t150 = _t149*_t49;
  const double _t151 = _t19*_t94;
  const double _t152 = _t151*_t93;
  const double _t153 = 0.2e1*_t83;
  const double _t154 = _t43*_t94;
  const double _t155 = _t48*_t93;
  const double _t156 = -0.0093588000000000005*_t7 - 0.53477359999999996*rs - 1.6532;
  const double _t157 = xc_powi(_t20, -5);
  const double _t158 = _t157*_t91;
  const double _t159 = _t158*_t19;
  const double _t160 = -0.0070191000000000003*_t7 - 0.4010802*rs - 1.2399;
  const double _t161 = _t46*_t88*_t95;
  const double _t162 = _t139*_t86 + 0.3e1*_t140*_t81 - _t141*_t146 - _t148*_t149 + _t148*_t93 - _t150*_t83 - _t151*_t158 + _t152*_t153 + 0.3e1*_t154*_t155 - _t156*_t159 + _t160*_t161 - 0.00054903868140000007*_t22 - 0.0046794000000000002*_t84 + _t92*(0.00082355802210000006*_t7 + 0.046005900000000002*rs + 0.10181999999999999);
#endif
#if _KMAX >= 4
  const double _t163 = 0.6e1*_t55;
  const double _t164 = _t113*_t57;
  const double _t165 = _t111*_t12;
  const double _t166 = 0.4e1*_t28;
  const double _t167 = _t166*_t33;
  const double _t168 = -0.0155175*_t104 - 0.20963999999999999;
  const double _t169 = _t109*_t63;
  const double _t170 = 0.046552499999999997*_t56 - 0.31445999999999996*rs - 2.0398199999999997;
  const double _t171 = 0.2e1*_t12;
  const double _t172 = 0.4e1*_t121;
  const double _t173 = _t106*_t107/xc_powi(_t14, 7);
  const double _t174 = _t171*_t173;
  const double _t175 = _t120*_t62;
  const double _t176 = _t175*_t68;
  const double _t177 = _t122*_t175;
  const double _t178 = 0.2e1*_t112;
  const double _t179 = _t116*_t124;
  const double _t180 = _t30*_t61;
  const double _t181 = _t124*_t180;
  const double _t182 = _t108*_t64;
  const double _t183 = _t182*(0.15517500000000001*_t32 - 0.26205000000000001*_t7 - 3.3997000000000002*rs - 5.0110000000000001);
  const double _t184 = _t35*_t78;
  const double _t185 = 55.828752000000009*rs;
  const double _t186 = _t131*_t9;
  const double _t187 = _t137*_t37*_t72;
  const double _t188 = xc_powi(_t4, -7);
  const double _t189 = -17.446485000000003*_t7 - 7.121505;
  const double _t190 = _t127*_t131*_t75;
  const double _t191 = 0.6e1*_t81;
  const double _t192 = _t149*_t83;
  const double _t193 = _t147*_t19;
  const double _t194 = 0.4e1*_t43;
  const double _t195 = _t194*_t48;
  const double _t196 = -0.014038200000000001*rs - 0.4010802;
  const double _t197 = 0.2e1*_t19;
  const double _t198 = _t145*_t90;
  const double _t199 = 0.4e1*_t158;
  const double _t200 = _t142*_t143/xc_powi(_t20, 7);
  const double _t201 = _t197*_t200;
  const double _t202 = _t157*_t89;
  const double _t203 = _t156*_t202;
  const double _t204 = 0.2e1*_t148;
  const double _t205 = _t202*_t95;
  const double _t206 = _t46*_t88;
  const double _t207 = _t160*_t206;
  const double _t208 = _t151*_t160;
  const double _t209 = _t144*_t91;
  const double _t210 = _t209*(-0.011698500000000001*_t7 - 0.66846699999999992*rs - 2.0665);
#endif

  const double f = _hc0[0]*_t1 + _t11*_t2 + _t12*_t16 + _t17*_t24 - 0.1925;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc0[1]*_t1 + _t11*_t25 + _t24*_t26;
  out[1] = df_dz;
  const double df_drs = _hc0[0]*_t27 + _hc0[2]*_t1 + _t16*_t28 + _t17*_t51 + _t2*_t42 + _t31*_t34;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc0[3]*_t1 + _t11*_t52 + 0.2e1*_t23 + 0.23466200000000001;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_t27 + _hc0[4]*_t1 + _t25*_t42 + _t26*_t51;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[0]*_t53 + _hc0[2]*_t54 + _hc0[5]*_t1 + _t16*_t55 + _t17*_t97 + _t2*_t80 + 0.2e1*_t28*_t59 + _t57*_t58 + _t60*_t65 + _t66*_t68;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc0[6]*_t1 + _t11*_t98;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc0[3]*_t27 + _hc0[7]*_t1 + _t42*_t52 + 0.2e1*_t44 + 0.2e1*_t50;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc0[1]*_t53 + _hc0[4]*_t54 + _hc0[8]*_t1 + _t25*_t80 + _t26*_t97;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[0]*_t99 + _hc0[2]*_t100 + _hc0[5]*_t101 + _hc0[9]*_t1 + _t102*_t103 + _t105*_t58 + _t110*(0.0067259499999999996*_t3 + 0.1144768*_t7 + 0.17262720000000001*rs) - _t112*_t113 + _t112*_t66 - _t114*_t57 + _t115*_t117 - _t116*_t121 + 0.3e1*_t118*_t119 - _t122*_t123 + _t124*_t125 + _t138*_t2 + 0.020177849999999997*_t16 + _t162*_t17 + 0.3e1*_t55*_t59 + _t65*(-0.030266774999999996*_t7 - 0.34343040000000002*rs - 0.25894080000000003);
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc0[10]*_t1 + 0.24e2*_t10 + 0.56205119999999997;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc0[11]*_t1 + _hc0[6]*_t27 + _t42*_t98;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc0[12]*_t1 + _hc0[3]*_t53 + _hc0[7]*_t54 + _t141*_t92 + _t52*_t80 + 0.2e1*_t82 + 0.2e1*_t85 + 0.4e1*_t87 + 0.2e1*_t96;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc0[1]*_t99 + _hc0[13]*_t1 + _hc0[4]*_t100 + _hc0[8]*_t101 + _t138*_t25 + _t162*_t26;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = _hc0[0]*(3.2107262791520017*_t1 + 3.2107262791520017) + _hc0[14]*_t1 + 0.4e1*_hc0[2]*_t99 + 0.6e1*_hc0[5]*_t53 + 0.4e1*_hc0[9]*_t27 + 0.4e1*_t102*_t105 + _t103*_t165*_t66 + _t103*_t179*_t180 - 0.2e1*_t105*_t114 + 0.3e1*_t105*_t117 + _t110*(0.080711399999999989*_t7 + 0.91581440000000003*rs + 0.69050880000000003) - _t111*_t113*_t167 + _t111*_t119*_t166 - 0.2e1*_t111*_t123 - _t111*_t176 + _t113*(_t57 * _t57)*_t60 - _t114*_t168 + _t115*_t12*_t169 - _t115*_t176 + 0.2e1*_t116*_t173 - _t116*_t183 - _t118*_t172 + 0.4e1*_t118*_t181*_t33 + 0.8e1*_t118*_t57*_t66 + _t119*_t163*_t67 - _t12*_t122*_t183 + _t120*_t122*_t124*_t30*_t68 - _t122*_t172*_t28 + _t122*_t174 - _t123*(0.06207*_t56 - 0.41927999999999999*rs - 2.71976) + _t125*_t170 + _t163*_t31*_t57 - _t164*_t165 - _t164*_t167 + 0.2e1*_t165*_t169 + _t168*_t34*_t66 + _t169*_t170*_t171 + _t17*(_t139*_t193*_t93 + _t139*_t206*_t208 - 0.0021961547256000003*_t140 + _t146*(-0.0021961547256000003*_t7 - 0.1226824*rs - 0.27151999999999998) - _t147*_t149*_t195 + _t147*_t155*_t194 - 0.2e1*_t147*_t159 - _t147*_t205 + _t149*_t18*(_t83 * _t83) + 0.018717600000000001*_t150 + 0.2e1*_t151*_t200 - _t151*_t210 - 0.014038200000000001*_t152 + _t153*_t19*_t198 - _t153*_t205 - _t154*_t199 + 0.4e1*_t154*_t207*_t48 + 0.8e1*_t154*_t83*_t93 + _t155*_t191*_t94 + _t156*_t157*_t160*_t46*_t95 - _t156*_t19*_t210 - _t156*_t199*_t43 + _t156*_t201 - _t159*(-0.018717600000000001*rs - 0.53477359999999996) + _t161*_t196 + _t191*_t47*_t83 - _t192*_t193 - _t192*_t195 + 0.2e1*_t193*_t198 + _t196*_t197*_t198 + _t201*(-0.014038200000000001*_t7 - 0.8021604*rs - 2.4798) - _t203*_t204 - _t203*_t49*_t83 + _t204*_t207 - _t208*_t209 - 0.0093588000000000005*_t49*_t93 - 0.018717600000000001*_t86 + _t92*(0.0032942320884000002*rs + 0.092011800000000005) + (_t48 * _t48 * _t48 * _t48)*(0.00054903868140000007*_t3 + 0.046005900000000002*_t7 + 0.20363999999999999*rs)/(xc_powi(_t20, 8)*(_t45 * _t45 * _t45 * _t45))) + _t174*(0.18620999999999999*_t32 - 0.31445999999999996*_t7 - 4.0796399999999995*rs - 6.0131999999999994) - _t177*_t178 - _t177*_t34*_t57 + _t178*_t181 - _t179*_t182 + _t2*(-_t126*_t127*_t187 - _t126*_t37*_t72*_t79 - 20.935782000000003*_t127*_t77 - _t129 + _t130*_t131*_t132*(-0.65372118866880002*_t7 + 0.26178879999999999*rs - 0.29674400000000001) + 0.2e1*_t130*_t132*_t133*_t188*_t9 + 0.2e1*_t130*_t132*_t188*_t78*_t9 + 0.2e1*_t130*_t132*_t188*_t9*(-20.935782000000003*_t7 - 8.5458060000000007) - 83.743128000000013*_t132*_t186*_t74*rs + _t133*_t134*_t137*_t37*_t40*_t78*_t9 + 34.892970000000005*_t133*_t134*_t40*_t73*_t9*rs - _t133*_t186*_t189*_t75 + 27.914376000000004*_t134*_t40*_t73*_t78*_t9*rs + 55.828752000000009*_t134*_t73*_t74*_t9*rs - 0.4e1*_t135*_t184 - 0.4e1*_t136*_t35 - _t137*_t190 + 0.4e1*_t137*_t35*_t37*_t40*_t72*_t78 - _t184*_t185*_t77 - _t185*_t35*_t40*_t77 - 27.914376000000004*_t187*_t41*rs - _t189*_t190 + 83.743128000000013*_t35*_t40*_t72*_t73*rs + 0.6e1*_t37*_t40*_t69*_t76*_t78 + 292.20464530101611*_t37*_t7*_t76*_t9 - 0.65372118866880002*_t39*_t40 - 41.871564000000006*_t39*_t69*rs + 27.914376000000004*_t40*_t72*_t73*_t9 - 146.10232265050806*_t7*_t72*_t73*_t9 - 27.914376000000004*_t71 + _t72*_t73*_t74*(0.98058178300319998*rs - 0.19634160000000001) + (_t40 * _t40 * _t40 * _t40)*(0.16343029716720001*_t3 - 0.098170800000000003*_t7 + 0.22255800000000001*rs)/((_t36 * _t36 * _t36 * _t36)*xc_powi(_t4, 8))) + 0.011638124999999999*_t58*pow(rs, -2.5) + 0.080711399999999989*_t59 + _t65*(-0.12106709999999998*rs - 0.68686080000000005) + (_t33 * _t33 * _t33 * _t33)*(-0.020177849999999997*_t3 - 0.34343040000000002*_t7 - 0.51788160000000005*rs)/(xc_powi(_t14, 8)*(_t29 * _t29 * _t29 * _t29));
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_amgb_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (rs * rs * rs);
  const double _t3 = 0.057238400000000002*_t1 + 0.0033629749999999998*_t2 + 0.086313600000000004*rs;
  const double _t4 = pow(rs, 1.5);
  const double _t5 = 0.33996999999999999*_t1 + 0.017469999999999999*_t2 - 0.02069*_t4 + 1.0022*rs;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = xc_log1p(_t6);
#if _KMAX >= 1
  const double _t8 = 0.010088924999999999*_t1 + 0.1144768*rs + 0.086313600000000004;
  const double _t9 = _t6 + 0.1e1;
  const double _t10 = (0.1e1 / _t9);
  const double _t11 = _t10/(_t5 * _t5);
  const double _t12 = sqrt(rs);
  const double _t13 = -0.052409999999999998*_t1 + 0.031035*_t12 - 0.67993999999999999*rs - 1.0022;
  const double _t14 = _t13*_t3;
#endif
#if _KMAX >= 2
  const double _t15 = 0.020177849999999997*rs + 0.1144768;
  const double _t16 = (0.1e1 / _t12);
  const double _t17 = 0.0155175*_t16 - 0.10482*rs - 0.67993999999999999;
  const double _t18 = _t11*_t3;
  const double _t19 = _t11*_t13;
  const double _t20 = -_t3;
  const double _t21 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t22 = (0.1e1 / (_t9 * _t9));
  const double _t23 = (_t13 * _t13);
  const double _t24 = _t22*_t23;
  const double _t25 = _t21*_t24;
  const double _t26 = _t10/(_t5 * _t5 * _t5);
  const double _t27 = -0.10482*_t1 + 0.06207*_t12 - 1.35988*rs - 2.0044;
  const double _t28 = _t14*_t27;
#endif
#if _KMAX >= 3
  const double _t29 = _t11*_t8;
  const double _t30 = 0.3e1*_t17;
  const double _t31 = (0.1e1 / _t4);
  const double _t32 = -0.00775875*_t31 - 0.10482;
  const double _t33 = (_t13 * _t13 * _t13);
  const double _t34 = (0.1e1 / (_t9 * _t9 * _t9));
  const double _t35 = xc_powi(_t5, -6);
  const double _t36 = _t34*_t35;
  const double _t37 = _t33*_t36;
  const double _t38 = 0.031035*_t16 - 0.20963999999999999*rs - 1.35988;
  const double _t39 = _t14*_t38;
  const double _t40 = _t21*_t22;
  const double _t41 = _t14*_t40;
  const double _t42 = 0.2e1*_t17;
  const double _t43 = _t27*_t3;
  const double _t44 = _t26*_t43;
  const double _t45 = _t27*_t8;
  const double _t46 = _t13*_t26;
  const double _t47 = xc_powi(_t5, -5);
  const double _t48 = _t24*_t47;
  const double _t49 = -0.20963999999999999*_t1 + 0.12414*_t12 - 2.71976*rs - 4.0087999999999999;
  const double _t50 = _t3*_t48;
  const double _t51 = -0.15722999999999998*_t1 + 0.093104999999999993*_t12 - 2.0398199999999997*rs - 3.0065999999999997;
  const double _t52 = _t10*_t21*_t28;
#endif
#if _KMAX >= 4
  const double _t53 = 0.6e1*_t15;
  const double _t54 = _t17*_t40;
  const double _t55 = _t3*_t38;
  const double _t56 = 0.4e1*_t8;
  const double _t57 = _t13*_t56;
  const double _t58 = -0.0155175*_t31 - 0.20963999999999999;
  const double _t59 = _t23*_t36;
  const double _t60 = 0.046552499999999997*_t16 - 0.31445999999999996*rs - 2.0398199999999997;
  const double _t61 = 0.2e1*_t3;
  const double _t62 = 0.4e1*_t48;
  const double _t63 = _t33*_t34/xc_powi(_t5, 7);
  const double _t64 = _t61*_t63;
  const double _t65 = _t22*_t47;
  const double _t66 = _t28*_t65;
  const double _t67 = _t49*_t65;
  const double _t68 = 0.2e1*_t39;
  const double _t69 = _t43*_t51;
  const double _t70 = _t10*_t21;
  const double _t71 = _t51*_t70;
  const double _t72 = _t24*_t35;
  const double _t73 = _t72*(-0.26205000000000001*_t1 + 0.15517500000000001*_t12 - 3.3997000000000002*rs - 5.0110000000000001);
#endif

  const double f = _t3*_t7 - 0.1925;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t11*_t14 + _t7*_t8;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t15*_t7 + _t17*_t18 + 0.2e1*_t19*_t8 + _t20*_t25 + _t26*_t28;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.3e1*_t15*_t19 - _t17*_t41 + _t18*_t32 + _t25*(-0.030266774999999996*_t1 - 0.34343040000000002*rs - 0.25894080000000003) + _t26*_t39 + _t29*_t30 + _t37*(0.1144768*_t1 + 0.0067259499999999996*_t2 + 0.17262720000000001*rs) - _t39*_t40 + _t42*_t44 - _t43*_t48 + 0.3e1*_t45*_t46 - _t49*_t50 + _t51*_t52 + 0.020177849999999997*_t7;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t10*_t28*_t47*_t49*_t51 + _t11*_t17*_t53 + (_t13 * _t13 * _t13 * _t13)*(-0.34343040000000002*_t1 - 0.020177849999999997*_t2 - 0.51788160000000005*rs)/(xc_powi(_t5, 8)*(_t9 * _t9 * _t9 * _t9)) + 0.4e1*_t13*_t45*_t71 - _t14*_t17*_t67 + _t14*_t26*_t58 + (_t17 * _t17)*_t20*_t40 + 0.8e1*_t17*_t26*_t45 + 0.011638124999999999*_t18*pow(rs, -2.5) + 0.080711399999999989*_t19 + _t25*(-0.12106709999999998*rs - 0.68686080000000005) + _t26*_t30*_t55 + _t27*_t46*_t53 + 0.4e1*_t29*_t32 + _t3*_t42*_t59 - _t3*_t49*_t73 + _t30*_t69*_t70 - 0.2e1*_t32*_t41 + 0.3e1*_t32*_t44 + _t37*(0.080711399999999989*_t1 + 0.91581440000000003*rs + 0.69050880000000003) - _t38*_t40*_t57 + _t38*_t46*_t56 - 0.2e1*_t38*_t50 - _t38*_t66 - _t41*_t58 - _t42*_t66 + 0.2e1*_t43*_t63 - _t43*_t73 - _t45*_t62 - _t49*_t62*_t8 + _t49*_t64 - _t50*(0.06207*_t16 - 0.41927999999999999*rs - 2.71976) + _t52*_t60 - _t54*_t55 - _t54*_t57 + 0.2e1*_t55*_t59 + _t59*_t60*_t61 + _t64*(-0.31445999999999996*_t1 + 0.18620999999999999*_t12 - 4.0796399999999995*rs - 6.0131999999999994) - _t67*_t68 + _t68*_t71 - _t69*_t72;
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(M_PI, -1, 2);
  const double _t2 = _t1/xc_powr(na, 1, 2);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_amgb_z0_k, _KMAX)(p, _t2, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[0] - 0.1e1 / 0.2e1*_hc0[1]*_t2;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t3 = (0.1e1 / M_PI);
  const double _t4 = _hc0[1]*_t1;
  const double d2F_dna2 = (0.1e1 / 0.4e1)*_hc0[2]*_t3/(na * na) - 0.1e1 / 0.4e1*_t4/xc_powr(na, 3, 2);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t5 = xc_powr(na, -7, 2);
  const double _t6 = _hc0[3]/xc_powr(M_PI, 3, 2);
  const double _t7 = _hc0[2]*_t3;
  const double d3F_dna3 = (0.3e1 / 0.8e1)*_hc0[1]*_t1/xc_powr(na, 5, 2) - 0.1e1 / 0.8e1*_t5*_t6 - 0.3e1 / 0.8e1*_t7/(na * na * na);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.16e2)*_hc0[4]/((M_PI * M_PI)*xc_powi(na, 5)) - 0.15e2 / 0.16e2*_t4*_t5 + (0.5e1 / 0.8e1)*_t6/xc_powr(na, 9, 2) + (0.15e2 / 0.16e2)*_t7/(na * na * na * na);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = xc_powr(M_PI, -1, 2);
  const double _t2 = na + nb;
  const double _t3 = na - nb;
  const double _t4 = (0.1e1 / _t2);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_amgb_k, _KMAX)(p, _t1/xc_powr(_t2, 1, 2), _t3*_t4, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t5 = _t1/xc_powr(_t2, 3, 2);
  const double _t8 = (0.1e1 / (_t2 * _t2));
  const double _t9 = _t3*_t8;
  const double _t10 = _t4 - _t9;
  const double _t12 = -_t4 - _t9;
  const double _t6 = _hc0[2]*_t5;
  const double _t7 = -0.1e1 / 0.2e1*_t6;
  const double _t11 = _hc0[1]*_t10;
  const double _t13 = _hc0[1]*_t12;
  const double dF_dna = _hc0[0] + _t2*(_t11 + _t7);
  const double dF_dnb = _hc0[0] + _t2*(_t13 + _t7);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t16 = xc_powr(_t2, -5, 2);
  const double _t17 = (0.3e1 / 0.4e1)*_t16;
  const double _t19 = 0.2e1*_t8;
  const double _t20 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t21 = 0.2e1*_t20;
  const double _t22 = _t21*_t3;
  const double _t23 = -_t19 + _t22;
  const double _t25 = (0.1e1 / 0.2e1)*_t5;
  const double _t37 = _t19 + _t22;
  const double _t14 = -_t6;
  const double _t15 = _hc0[2]*_t1;
  const double _t18 = _t15*_t17;
  const double _t24 = _hc0[1]*_t23;
  const double _t26 = -_hc0[4]*_t25;
  const double _t27 = _hc0[3]*_t10 + _t26;
  const double _t28 = _t10*_t27;
  const double _t29 = -_hc0[5]*_t25;
  const double _t30 = _hc0[4]*_t10 + _t29;
  const double _t31 = _t24 - _t25*_t30 + _t28;
  const double _t32 = _hc0[3]*_t12 + _t26;
  const double _t33 = _t10*_t32;
  const double _t34 = _hc0[4]*_t12 + _t29;
  const double _t35 = _t34*_t5;
  const double _t36 = _t18 - 0.1e1 / 0.2e1*_t35;
  const double _t38 = _hc0[1]*_t37;
  const double _t39 = _t12*_t32;
  const double _t40 = _t38 + _t39;
  const double d2F_dna2 = 0.2e1*_t11 + _t14 + _t2*(_t18 + _t31);
  const double d2F_dna_dnb = _t11 + _t13 + _t14 + _t2*(_hc0[1]*_t22 + _t33 + _t36);
  const double d2F_dnb2 = 0.2e1*_t13 + _t14 + _t2*(_t36 + _t40);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t43 = xc_powr(_t2, -7, 2);
  const double _t44 = (0.15e2 / 0.8e1)*_t43;
  const double _t47 = _t1*_t16;
  const double _t49 = 0.6e1*_t20;
  const double _t50 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t51 = _t3*_t50;
  const double _t52 = 0.6e1*_t51;
  const double _t53 = _t49 - _t52;
  const double _t55 = _t1*_t17;
  const double _t63 = 0.2e1*_t23;
  const double _t69 = 0.2e1*_t20 - _t52;
  const double _t81 = 0.4e1*_t20;
  const double _t89 = (0.3e1 / 0.2e1)*_t47;
  const double _t90 = -_t49 - _t52;
  const double _t41 = (0.9e1 / 0.4e1)*_t15*_t16;
  const double _t42 = (0.3e1 / 0.2e1)*_t30;
  const double _t45 = _t15*_t44;
  const double _t46 = -_t45;
  const double _t48 = _t42*_t47;
  const double _t54 = _hc0[1]*_t53;
  const double _t56 = _hc0[4]*_t55;
  const double _t57 = -_hc0[8]*_t25;
  const double _t58 = _hc0[7]*_t10 + _t57;
  const double _t59 = -_hc0[7]*_t25;
  const double _t60 = _hc0[6]*_t10 + _t59;
  const double _t61 = _hc0[3]*_t23 + _t10*_t60 - _t25*_t58 + _t56;
  const double _t62 = _t10*_t61;
  const double _t64 = _hc0[5]*_t55;
  const double _t65 = -_hc0[9]*_t25;
  const double _t66 = _hc0[8]*_t10 + _t65;
  const double _t67 = _hc0[4]*_t23 + _t10*_t58 - _t25*_t66 + _t64;
  const double _t68 = -_t25*_t67 + _t27*_t63 + _t54 + _t62;
  const double _t70 = _hc0[1]*_t69;
  const double _t71 = _t23*_t32;
  const double _t72 = _hc0[7]*_t12 + _t57;
  const double _t73 = _hc0[8]*_t12 + _t65;
  const double _t74 = -_t25*_t73 + _t64;
  const double _t75 = _hc0[4]*_t22 + _t10*_t72 + _t74;
  const double _t76 = _t5*_t75;
  const double _t77 = _hc0[6]*_t12 + _t59;
  const double _t78 = -_t25*_t72 + _t56;
  const double _t79 = _hc0[3]*_t22 + _t10*_t77 + _t78;
  const double _t80 = _t10*_t79;
  const double _t82 = _hc0[1]*_t81;
  const double _t83 = _t3*_t82 + 0.2e1*_t33;
  const double _t84 = _hc0[4]*_t37 + _t12*_t72 + _t74;
  const double _t85 = _t5*_t84;
  const double _t86 = (0.1e1 / 0.2e1)*_t85;
  const double _t87 = _hc0[3]*_t37 + _t12*_t77 + _t78;
  const double _t88 = -0.3e1 / 0.2e1*_t35 + _t41;
  const double _t91 = _hc0[1]*_t90;
  const double _t92 = _t12*_t87;
  const double _t93 = 0.2e1*_t32;
  const double _t94 = _t37*_t93 + _t91 + _t92;
  const double d3F_dna3 = _t2*(_t46 + _t48 + _t68) + 0.3e1*_t24 + 0.3e1*_t28 + _t41 - _t42*_t5;
  const double d3F_dna2_dnb = _t2*(_t22*_t27 + _t30*_t55 + _t34*_t55 + _t46 + _t70 + _t71 - 0.1e1 / 0.2e1*_t76 + _t80) + _t31 - _t35 + _t41 + _t83;
  const double d3F_dna_dnb2 = _t2*(-_hc0[1]*_t21 - _hc0[1]*_t52 + (0.3e1 / 0.2e1)*_t1*_t16*_t34 + _t10*_t87 + 0.4e1*_t20*_t3*_t32 - _t45 - _t86) + _t40 + _t83 + _t88;
  const double d3F_dnb3 = _t2*(_t34*_t89 + _t46 - _t86 + _t94) + 0.3e1*_t38 + 0.3e1*_t39 + _t88;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t98 = 0.24e2*_t50;
  const double _t99 = 0.24e2*_t3/xc_powi(_t2, 5);
  const double _t100 = _t1*_t43;
  const double _t102 = (0.9e1 / 0.4e1)*_t47;
  const double _t103 = _t1*_t44;
  const double _t118 = 0.12e2*_t50;
  const double _t127 = _t3*_t49;
  const double _t130 = _t3*_t81;
  const double _t132 = _t20*_t3;
  const double _t140 = 0.2e1*_t37;
  const double _t142 = 0.18e2*_t51;
  const double _t95 = -0.15e2 / 0.2e1*_t15*_t43;
  const double _t96 = _t30*_t47;
  const double _t97 = (0.105e3 / 0.16e2)*_t15/xc_powr(_t2, 9, 2);
  const double _t101 = _t100*_t30;
  const double _t104 = _hc0[5]*_t103;
  const double _t105 = -_t104;
  const double _t106 = _hc0[9]*_t55;
  const double _t107 = -_hc0[14]*_t25;
  const double _t108 = -_hc0[13]*_t25;
  const double _t109 = _hc0[12]*_t10 + _t108;
  const double _t110 = _hc0[8]*_t55;
  const double _t111 = -_hc0[12]*_t25;
  const double _t112 = _hc0[11]*_t10 + _t111;
  const double _t113 = _hc0[7]*_t23 + _t10*_t112 - _t109*_t25 + _t110;
  const double _t114 = _hc0[4]*_t103;
  const double _t115 = -_t114;
  const double _t116 = _hc0[7]*_t55;
  const double _t117 = -_hc0[11]*_t25;
  const double _t119 = _hc0[11]*_t12 + _t111;
  const double _t120 = _hc0[12]*_t12 + _t108;
  const double _t121 = _t110 - _t120*_t25;
  const double _t122 = _hc0[7]*_t22 + _t10*_t119 + _t121;
  const double _t123 = _hc0[10]*_t12 + _t117;
  const double _t124 = _t116 - _t119*_t25;
  const double _t125 = _t106 - _t25*(_hc0[13]*_t12 + _t107);
  const double _t126 = _t75*_t89 + _t97;
  const double _t128 = _hc0[1]*_t118;
  const double _t129 = _t34*_t47;
  const double _t131 = 0.8e1*_t32;
  const double _t133 = _t10*_t87;
  const double _t134 = _hc0[1]*_t99;
  const double _t135 = _hc0[7]*_t37 + _t119*_t12 + _t121;
  const double _t136 = _t135*_t25;
  const double _t137 = _hc0[6]*_t37 + _t12*_t123 + _t124;
  const double _t138 = _t100*_t34;
  const double _t139 = _t25*(_hc0[8]*_t37 + _t12*_t120 + _t125);
  const double _t141 = _hc0[3]*_t90 + _t115 + _t12*_t137 - _t136 + _t140*_t77 + _t72*_t89;
  const double _t143 = _t102*_t84 - 0.45e2 / 0.8e1*_t138 - _t25*(_hc0[4]*_t90 + _t105 + _t12*_t135 - _t139 + _t140*_t72 + _t73*_t89) + _t97;
  const double _t144 = 0.6e1*_t129 - 0.2e1*_t85 + _t95;
  const double d4F_dna4 = _t2*(_hc0[1]*(-_t98 + _t99) + _t10*(_hc0[3]*_t53 + _t10*(_hc0[6]*_t23 + _t10*(_hc0[10]*_t10 + _t117) - _t112*_t25 + _t116) - _t113*_t25 + _t115 + _t58*_t89 + _t60*_t63) - 0.45e2 / 0.8e1*_t101 + _t102*_t67 + 0.3e1*_t23*_t61 - _t25*(_hc0[4]*_t53 + _t10*_t113 + _t105 - _t25*(_hc0[8]*_t23 + _t10*_t109 + _t106 - _t25*(_hc0[13]*_t10 + _t107)) + _t58*_t63 + _t66*_t89) + 0.3e1*_t27*_t53 + _t97) + 0.8e1*_t23*_t27 - 0.2e1*_t5*_t67 + 0.4e1*_t54 + 0.4e1*_t62 + _t95 + 0.6e1*_t96;
  const double d4F_dna3_dnb = _t102*_t34 + _t127*_t27 + _t2*(_hc0[1]*(-_t118 + _t99) + _t10*(_hc0[3]*_t69 + _t10*(_hc0[6]*_t22 + _t10*_t123 + _t124) + _t115 - _t122*_t25 + _t22*_t60 + _t23*_t77 + _t55*_t58 + _t55*_t72) - 0.15e2 / 0.4e1*_t101 - _t103*_t34 + _t126 + _t22*_t61 - _t25*(_hc0[4]*_t69 + _t10*_t122 + _t105 + _t22*_t58 + _t23*_t72 - _t25*(_hc0[8]*_t22 + _t10*_t120 + _t125) + _t55*_t66 + _t55*_t73) + 0.2e1*_t27*_t69 + _t32*_t53 + _t55*_t67 + _t63*_t79) + _t68 + 0.3e1*_t70 + 0.3e1*_t71 - 0.3e1 / 0.2e1*_t76 + 0.3e1*_t80 + _t95 + (0.15e2 / 0.4e1)*_t96;
  const double d4F_dna2_dnb2 = -_t128*_t3 + (0.9e1 / 0.2e1)*_t129 + _t130*_t27 + _t131*_t132 + 0.2e1*_t133 + _t2*(_t10*(-_hc0[3]*_t21 - _hc0[3]*_t52 + (0.3e1 / 0.2e1)*_t1*_t16*_t72 + _t10*_t137 - _t114 - _t136 + 0.4e1*_t20*_t3*_t77) - _t103*_t30 + _t126 + _t130*_t79 + _t134 - 0.15e2 / 0.4e1*_t138 - _t21*_t27 + _t23*_t87 - _t25*(-_hc0[4]*_t21 - _hc0[4]*_t52 + (0.3e1 / 0.2e1)*_t1*_t16*_t73 + _t10*_t135 - _t104 - _t139 + 0.4e1*_t20*_t3*_t72) - _t27*_t52 + _t55*_t84 + _t69*_t93) + _t48 + 0.2e1*_t70 + 0.2e1*_t71 - _t76 + 0.2e1*_t80 - _t82 - _t85 + _t95;
  const double d4F_dna_dnb3 = -_hc0[1]*_t142 - _hc0[1]*_t49 + 0.12e2*_t132*_t32 + 0.3e1*_t133 + _t144 + _t2*(_t10*_t141 + _t127*_t87 + _t128 + _t134 - _t142*_t32 + _t143 - _t32*_t49) + _t94;
  const double d4F_dnb4 = _t131*_t37 + _t144 + _t2*(_hc0[1]*(_t98 + _t99) + _t12*_t141 + _t143 + 0.3e1*_t32*_t90 + 0.3e1*_t37*_t87) + 0.4e1*_t91 + 0.4e1*_t92;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif