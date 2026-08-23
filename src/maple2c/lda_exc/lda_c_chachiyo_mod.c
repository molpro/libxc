/*
  Generated from python/lda_exc/lda_c_chachiyo_mod.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_chachiyo_mod
*/

#ifndef _LDA_C_CHACHIYO_MOD_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_CHACHIYO_MOD_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#include "lda_c_chachiyo_mod.c"
#undef _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#include "lda_c_chachiyo_mod.c"
#undef _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#include "lda_c_chachiyo_mod.c"
#undef _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#include "lda_c_chachiyo_mod.c"
#undef _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#include "lda_c_chachiyo_mod.c"
#undef _LDA_C_CHACHIYO_MOD_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_chachiyo_mod.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_CHACHIYO_MOD_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(e0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const lda_c_chachiyo_mod_params *params = (const lda_c_chachiyo_mod_params *)(p->params);

  const double _t1 = (0.1e1 / (rs * rs));
  const double _t2 = _t1*params->cp + params->bp/rs;
#if _KMAX >= 1
  const double _t3 = _t1*params->bp;
  const double _t4 = (0.1e1 / (rs * rs * rs));
  const double _t5 = 0.2e1*_t4;
  const double _t6 = _t3 + _t5*params->cp;
  const double _t7 = -_t6;
  const double _t8 = _t2 + 0.1e1;
  const double _t9 = params->ap/_t8;
#endif
#if _KMAX >= 2
  const double _t10 = (0.1e1 / (rs * rs * rs * rs));
  const double _t11 = 0.6e1*_t10;
  const double _t12 = _t11*params->cp + _t5*params->bp;
  const double _t13 = params->ap/(_t8 * _t8);
  const double _t14 = _t13*_t7;
#endif
#if _KMAX >= 3
  const double _t15 = 0.24e2/xc_powi(rs, 5);
  const double _t16 = _t11*params->bp + _t15*params->cp;
  const double _t17 = -_t16;
  const double _t18 = -_t12;
  const double _t19 = _t13*_t6;
  const double _t20 = 0.4e1*_t4;
  const double _t21 = _t20*params->cp + 0.2e1*_t3;
  const double _t22 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t23 = _t22*_t6*_t7*params->ap;
#endif
#if _KMAX >= 4
  const double _t24 = 0.3e1*_t12;
  const double _t25 = _t21*_t22*params->ap;
#endif

  const double f = params->ap*xc_log1p(_t2);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t7*_t9;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t12*_t9 + _t14*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.2e1*_t12*_t19 + _t14*_t18 + _t17*_t9 + _t21*_t23;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t13*_t18*_t24 + _t14*_t16 + 0.3e1*_t17*_t19 + 0.2e1*_t18*_t25*_t7 + _t21*_t6*_t7*params->ap*(0.3e1*_t3 + 0.6e1*_t4*params->cp)/(_t8 * _t8 * _t8 * _t8) + _t23*(-0.12e2*_t10*params->cp - _t20*params->bp) + _t24*_t25*_t6 + _t9*(_t15*params->bp + 0.120e3*params->cp/xc_powi(rs, 6));
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(e1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const lda_c_chachiyo_mod_params *params = (const lda_c_chachiyo_mod_params *)(p->params);

  const double _t1 = (0.1e1 / (rs * rs));
  const double _t2 = _t1*params->cf + params->bf/rs;
#if _KMAX >= 1
  const double _t3 = _t1*params->bf;
  const double _t4 = (0.1e1 / (rs * rs * rs));
  const double _t5 = 0.2e1*_t4;
  const double _t6 = _t3 + _t5*params->cf;
  const double _t7 = -_t6;
  const double _t8 = _t2 + 0.1e1;
  const double _t9 = params->af/_t8;
#endif
#if _KMAX >= 2
  const double _t10 = (0.1e1 / (rs * rs * rs * rs));
  const double _t11 = 0.6e1*_t10;
  const double _t12 = _t11*params->cf + _t5*params->bf;
  const double _t13 = params->af/(_t8 * _t8);
  const double _t14 = _t13*_t7;
#endif
#if _KMAX >= 3
  const double _t15 = 0.24e2/xc_powi(rs, 5);
  const double _t16 = _t11*params->bf + _t15*params->cf;
  const double _t17 = -_t16;
  const double _t18 = -_t12;
  const double _t19 = _t13*_t6;
  const double _t20 = 0.4e1*_t4;
  const double _t21 = _t20*params->cf + 0.2e1*_t3;
  const double _t22 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t23 = _t22*_t6*_t7*params->af;
#endif
#if _KMAX >= 4
  const double _t24 = 0.3e1*_t12;
  const double _t25 = _t21*_t22*params->af;
#endif

  const double f = params->af*xc_log1p(_t2);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t7*_t9;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t12*_t9 + _t14*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.2e1*_t12*_t19 + _t14*_t18 + _t17*_t9 + _t21*_t23;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t13*_t18*_t24 + _t14*_t16 + 0.3e1*_t17*_t19 + 0.2e1*_t18*_t25*_t7 + _t21*_t6*_t7*params->af*(0.3e1*_t3 + 0.6e1*_t4*params->cf)/(_t8 * _t8 * _t8 * _t8) + _t23*(-0.12e2*_t10*params->cf - _t20*params->bf) + _t24*_t25*_t6 + _t9*(_t15*params->bf + 0.120e3*params->cf/xc_powi(rs, 6));
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(g_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -z, 0.2e1 / 0.3e1, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(g_zeta_k, _KMAX)(const xc_func_type *p, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, zeta, 0.2e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -zeta, 0.2e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(g_k, _KMAX)(p, zeta, _hc2);
  const double _t1 = ((_hc2[0]) * (_hc2[0])) + _hc2[0] + 0.1e1;
  const double _t2 = -_hc0[0] - _hc1[0];
#if _KMAX >= 1
  const double _t3 = -_hc0[2] + _hc1[2];
  const double _t4 = 0.2e1*_hc2[0];
  const double _t5 = _hc2[1]*_t4 + _hc2[1];
#endif
#if _KMAX >= 2
  const double _t6 = -_hc0[5] - _hc1[5];
  const double _t7 = 0.2e1*((_hc2[1]) * (_hc2[1])) + _hc2[2]*_t4 + _hc2[2];
#endif
#if _KMAX >= 3
  const double _t8 = -_hc0[9] + _hc1[9];
  const double _t9 = 0.6e1*_hc2[1]*_hc2[2] + _hc2[3]*_t4 + _hc2[3];
#endif

  const double f = _t1*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = _t1*_t3 + _t2*_t5;
  out[1] = df_dzeta;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = _t1*_t6 + _t2*_t7 + 0.2e1*_t3*_t5;
  out[2] = d2f_dzeta2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = _t1*_t8 + _t2*_t9 + 0.3e1*_t3*_t7 + 0.3e1*_t5*_t6;
  out[3] = d3f_dzeta3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = _t1*(-_hc0[14] - _hc1[14]) + _t2*(0.8e1*_hc2[1]*_hc2[3] + 0.6e1*((_hc2[2]) * (_hc2[2])) + _hc2[4]*_t4 + _hc2[4]) + 0.4e1*_t3*_t9 + 0.4e1*_t5*_t8 + 0.6e1*_t6*_t7;
  out[4] = d4f_dzeta4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_chachiyo_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(e0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(e1_k, _KMAX)(p, rs, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(g_zeta_k, _KMAX)(p, zeta, _hc2);
  const double _t1 = -_hc0[0] + _hc1[0];
#if _KMAX >= 1
  const double _t2 = -_hc0[1] + _hc1[1];
#endif
#if _KMAX >= 2
  const double _t3 = -_hc0[2] + _hc1[2];
#endif
#if _KMAX >= 3
  const double _t4 = -_hc0[3] + _hc1[3];
#endif

  const double f = _hc0[0] + _hc2[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = _hc2[1]*_t1;
  out[1] = df_dzeta;
  const double df_drs = _hc0[1] + _hc2[0]*_t2;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = _hc2[2]*_t1;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc2[1]*_t2;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = _hc0[2] + _hc2[0]*_t3;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = _hc2[3]*_t1;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc2[2]*_t2;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = _hc2[1]*_t3;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = _hc0[3] + _hc2[0]*_t4;
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
  const double d4f_drs4 = _hc0[4] + _hc2[0]*(-_hc0[4] + _hc1[4]);
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_chachiyo_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(e0_k, _KMAX)(p, rs, _hc0);

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
  assert(p->params != NULL);
  const lda_c_chachiyo_mod_params *params = (const lda_c_chachiyo_mod_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = _t3/xc_powr(na, 1, 3);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_chachiyo_zeta0_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t4, _hc0);
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
  XC_CAT(f_chachiyo_k, _KMAX)(p, _t5/xc_powr(_t1, 1, 3), _t6*_t7, _hc0);
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