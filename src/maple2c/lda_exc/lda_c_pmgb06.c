/*
  Generated from python/lda_exc/lda_c_pmgb06.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_pmgb06
*/

#ifndef _LDA_C_PMGB06_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_PMGB06_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_PMGB06_HELPER_BODIES
#include "lda_c_pmgb06.c"
#undef _LDA_C_PMGB06_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_PMGB06_HELPER_BODIES
#include "lda_c_pmgb06.c"
#undef _LDA_C_PMGB06_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_PMGB06_HELPER_BODIES
#include "lda_c_pmgb06.c"
#undef _LDA_C_PMGB06_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_PMGB06_HELPER_BODIES
#include "lda_c_pmgb06.c"
#undef _LDA_C_PMGB06_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_PMGB06_HELPER_BODIES
#include "lda_c_pmgb06.c"
#undef _LDA_C_PMGB06_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_pmgb06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_PMGB06_HELPER_BODIES)

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
  const double _t10 = _t9*n;
#endif
#if _KMAX >= 2
  const double _t11 = _t4*(_t6 * _t6);
  const double _t12 = _t7*_t8;
  const double _t13 = (0.1e1 / (_t1 * _t1));
  const double _t14 = _t13*_t4;
  const double _t15 = _t14*n;
  const double _t16 = (n * n);
#endif
#if _KMAX >= 3
  const double _t17 = (_t6 * _t6 * _t6);
  const double _t18 = _t11*_t8;
  const double _t19 = _t13*_t7;
  const double _t20 = _t19*n;
  const double _t21 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t22 = _t21*_t4;
  const double _t23 = 0.2e1*_t22;
  const double _t24 = (n * n * n);
  const double _t25 = 0.3e1*_t16;
  const double _t26 = _t22*_t25;
#endif
#if _KMAX >= 4
  const double _t27 = _t11*_t13;
  const double _t28 = 0.6e1*n;
  const double _t29 = _t21*_t7;
  const double _t30 = _t4/(_t1 * _t1 * _t1 * _t1);
#endif

  const double f = my_piecewise3(_t2, _t3, _t4);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = my_piecewise3(_t2, _t3*_t5, _t7);
  out[1] = df_dn;
  const double df_dz = my_piecewise3(_t2, 0, _t10);
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = my_piecewise3(_t2, _t3*(_t5 * _t5), _t11);
  out[3] = d2f_dn2;
  const double d2f_dz_dn = my_piecewise3(_t2, 0, _t12*n + _t9);
  out[4] = d2f_dz_dn;
  const double d2f_dz2 = my_piecewise3(_t2, 0, _t14*_t16 - _t15);
  out[5] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = my_piecewise3(_t2, _t3*(_t5 * _t5 * _t5), _t17*_t4);
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t2, 0, 0.2e1*_t12 + _t18*n);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t2, 0, -_t14 + 0.2e1*_t15 + _t16*_t19 - _t20);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t2, 0, _t22*_t24 + _t23*n - _t26);
  out[9] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dn4 = my_piecewise3(_t2, _t3*(_t5 * _t5 * _t5 * _t5), _t4*(_t6 * _t6 * _t6 * _t6));
  out[10] = d4f_dn4;
  const double d4f_dz_dn3 = my_piecewise3(_t2, 0, _t10*_t17 + 0.3e1*_t18);
  out[11] = d4f_dz_dn3;
  const double d4f_dz2_dn2 = my_piecewise3(_t2, 0, 0.2e1*_t14 + _t16*_t27 - 0.2e1*_t19 + 0.4e1*_t20 - _t27*n);
  out[12] = d4f_dz2_dn2;
  const double d4f_dz3_dn = my_piecewise3(_t2, 0, -_t22*_t28 + _t23 + _t24*_t29 - _t25*_t29 + _t26 + 0.2e1*_t29*n);
  out[13] = d4f_dz3_dn;
  const double d4f_dz4 = my_piecewise3(_t2, 0, 0.11e2*_t16*_t30 - 0.6e1*_t24*_t30 - _t28*_t30 + _t30*(n * n * n * n));
  out[14] = d4f_dz4;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_g0_poly_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (rs * rs * rs);
  const double _t3 = -0.2e1 / 0.15e2*xc_powr(0.2e1, 2, 3)*M_CBRT3*(-0.3e1 + 0.6e1*M_LN2 + (M_PI * M_PI))/(M_PI * M_CBRTPI) + 0.75239999999999996;

  const double f = 0.081930000000000003*_t1 - 0.01277*_t2 + _t3*rs + 0.001859*(rs * rs * rs * rs);
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.038309999999999997*_t1 + 0.0074359999999999999*_t2 + _t3 + 0.16386000000000001*rs;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.022308000000000001*_t1 - 0.076619999999999994*rs + 0.16386000000000001;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.044616000000000003*rs - 0.076619999999999994;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.044616000000000003;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_g0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_g0_poly_k, _KMAX)(p, rs, _hc0);
  const double _t1 = _hc0[0] + 0.1e1;
  const double _t2 = exp(-0.75239999999999996*rs);
  const double _t3 = (0.1e1 / 0.2e1)*_t2;
#if _KMAX >= 1
  const double _t4 = _t1*_t2;
#endif
#if _KMAX >= 2
  const double _t5 = _hc0[1]*_t2;
#endif
#if _KMAX >= 3
  const double _t6 = _hc0[2]*_t2;
#endif

  const double f = _t1*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _hc0[1]*_t3 - 0.37619999999999998*_t4;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[2]*_t3 + 0.28305287999999995*_t4 - 0.75239999999999996*_t5;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = _hc0[3]*_t3 - 0.21296898691199995*_t4 + 0.84915863999999985*_t5 - 1.1286*_t6;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -1.5047999999999999*_hc0[3]*_t2 + _hc0[4]*_t3 + 0.16023786575258875*_t4 - 0.85187594764799979*_t5 + 1.6983172799999999*_t6;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_g0_m_half_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_g0_poly_k, _KMAX)(p, rs, _hc0);
  const double _t1 = xc_expm1(-0.75239999999999996*rs);
  const double _t2 = (0.1e1 / 0.2e1)*_hc0[0] + 0.1e1 / 0.2e1;
#if _KMAX >= 1
  const double _t3 = (0.1e1 / 0.2e1)*_hc0[1];
  const double _t4 = -0.75239999999999996*_t1 - 0.75239999999999996;
#endif
#if _KMAX >= 2
  const double _t5 = (0.1e1 / 0.2e1)*_hc0[2];
  const double _t6 = 0.5661057599999999*_t1 + 0.5661057599999999;
#endif
#if _KMAX >= 3
  const double _t7 = (0.1e1 / 0.2e1)*_hc0[3];
  const double _t8 = -0.42593797382399989*_t1 - 0.42593797382399989;
#endif
#if _KMAX >= 4
  const double _t9 = (0.1e1 / 0.2e1)*_hc0[4];
#endif

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + _t1*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t1*_t3 + _t2*_t4 + _t3;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _hc0[1]*_t4 + _t1*_t5 + _t2*_t6 + _t5;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.3e1 / 0.2e1)*_hc0[1]*_t6 + (0.3e1 / 0.2e1)*_hc0[2]*_t4 + _t1*_t7 + _t2*_t8 + _t7;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.2e1*_hc0[1]*_t8 + 0.3e1*_hc0[2]*_t6 + 0.2e1*_hc0[3]*_t4 + _t1*_t9 + _t2*(0.3204757315051775*_t1 + 0.3204757315051775) + _t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_gc0_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_g0_m_half_k, _KMAX)(p, rs, _hc0);

  const double f = _hc0[0] + (0.1e1 / 0.2e1)*(z * z);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = z;
  out[1] = df_dz;
  const double df_drs = _hc0[1];
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0.1e1;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = 0;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc0[2];
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = 0;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = 0;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc0[3];
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
  const double d4f_drs4 = _hc0[4];
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_phi_k, _KMAX)(const xc_func_type *p, double n, double z, double *out) {

  const double _t1 = (0.1e1 / 0.3e1)*n;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_gen_k, _KMAX)(p, z, _t1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_gen_k, _KMAX)(p, -z, _t1, _hc1);

  const double f = (0.1e1 / 0.2e1)*_hc0[0] + (0.1e1 / 0.2e1)*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = (0.1e1 / 0.2e1)*_hc0[2] - 0.1e1 / 0.2e1*_hc1[2];
  out[1] = df_dz;
  const double df_dn = (0.1e1 / 0.6e1)*_hc0[1] + (0.1e1 / 0.6e1)*_hc1[1];
  out[2] = df_dn;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = (0.1e1 / 0.2e1)*_hc0[5] + (0.1e1 / 0.2e1)*_hc1[5];
  out[3] = d2f_dz2;
  const double d2f_dn_dz = (0.1e1 / 0.6e1)*_hc0[4] - 0.1e1 / 0.6e1*_hc1[4];
  out[4] = d2f_dn_dz;
  const double d2f_dn2 = (0.1e1 / 0.18e2)*_hc0[3] + (0.1e1 / 0.18e2)*_hc1[3];
  out[5] = d2f_dn2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = (0.1e1 / 0.2e1)*_hc0[9] - 0.1e1 / 0.2e1*_hc1[9];
  out[6] = d3f_dz3;
  const double d3f_dn_dz2 = (0.1e1 / 0.6e1)*_hc0[8] + (0.1e1 / 0.6e1)*_hc1[8];
  out[7] = d3f_dn_dz2;
  const double d3f_dn2_dz = (0.1e1 / 0.18e2)*_hc0[7] - 0.1e1 / 0.18e2*_hc1[7];
  out[8] = d3f_dn2_dz;
  const double d3f_dn3 = (0.1e1 / 0.54e2)*_hc0[6] + (0.1e1 / 0.54e2)*_hc1[6];
  out[9] = d3f_dn3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = (0.1e1 / 0.2e1)*_hc0[14] + (0.1e1 / 0.2e1)*_hc1[14];
  out[10] = d4f_dz4;
  const double d4f_dn_dz3 = (0.1e1 / 0.6e1)*_hc0[13] - 0.1e1 / 0.6e1*_hc1[13];
  out[11] = d4f_dn_dz3;
  const double d4f_dn2_dz2 = (0.1e1 / 0.18e2)*_hc0[12] + (0.1e1 / 0.18e2)*_hc1[12];
  out[12] = d4f_dn2_dz2;
  const double d4f_dn3_dz = (0.1e1 / 0.54e2)*_hc0[11] - 0.1e1 / 0.54e2*_hc1[11];
  out[13] = d4f_dn3_dz;
  const double d4f_dn4 = (0.1e1 / 0.162e3)*_hc0[10] + (0.1e1 / 0.162e3)*_hc1[10];
  out[14] = d4f_dn4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_Q_num_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x);
  const double _t2 = xc_powr(0.2e1, 2, 3)*M_CBRT3*(M_CBRTPI * M_CBRTPI)/(-0.4e1 + 0.4e1*M_LN2);
  const double _t3 = 3.4485100000000002 - _t2;

  const double f = _t1*_t3 + 3.91744*(x * x * x) + 5.84605*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 11.752320000000001*_t1 + 0.2e1*_t3*x + 5.84605;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.2e1*_t2 + 23.504640000000002*x + 6.8970200000000004;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 23.504640000000002;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_Q_den_k, _KMAX)(const xc_func_type *p, double x, double *out) {


  const double f = 3.4485100000000002*(x * x) + 5.84605*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = 6.8970200000000004*x + 5.84605;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 6.8970200000000004;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_Q_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_Q_den_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_Q_num_k, _KMAX)(p, x, _hc1);
  const double _t1 = (0.1e1 / (_hc0[0]));
  const double _t2 = -_hc0[0] + _hc1[0];
  const double _t3 = _t1*_t2;
  const double _t4 = (-0.2e1 + 0.2e1*M_LN2)/(M_PI * M_PI);
#if _KMAX >= 1
  const double _t5 = -_hc0[1] + _hc1[1];
  const double _t6 = _t1*_t5;
  const double _t7 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t8 = _t2*_t7;
  const double _t9 = -_hc0[1]*_t8 + _t6;
  const double _t10 = _t3 + 0.1e1;
  const double _t11 = _t4/_t10;
#endif
#if _KMAX >= 2
  const double _t12 = -_t9;
  const double _t13 = _t4/(_t10 * _t10);
  const double _t14 = _t13*_t9;
  const double _t15 = -_hc0[2] + _hc1[2];
  const double _t16 = _t1*_t15;
  const double _t17 = _hc0[1]*_t7;
  const double _t18 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t19 = ((_hc0[1]) * (_hc0[1]));
  const double _t20 = _t18*_t19;
  const double _t21 = _t2*_t20;
  const double _t22 = -_hc0[2]*_t8 + _t16 - 0.2e1*_t17*_t5 + 0.2e1*_t21;
#endif
#if _KMAX >= 3
  const double _t23 = 0.2e1*_hc0[1]*_t2*_t7 - 0.2e1*_t6;
  const double _t24 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t25 = _t12*_t24*_t4*_t9;
  const double _t26 = _hc0[2]*_t7;
  const double _t27 = 0.6e1*_t2;
  const double _t28 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t29 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t28;
  const double _t30 = _hc0[1]*_hc0[2]*_t18*_t27 + _hc1[3]*_t1 - 0.3e1*_t15*_t17 + 0.6e1*_t20*_t5 - 0.3e1*_t26*_t5 - _t27*_t29;
  const double _t31 = -_t22;
  const double _t32 = _t12*_t13;
#endif
#if _KMAX >= 4
  const double _t33 = 0.3e1*_t22;
  const double _t34 = _t23*_t24*_t4;
#endif

  const double f = _t4*xc_log1p(_t3);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t11*_t9;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _t11*_t22 + _t12*_t14;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _t11*_t30 + _t14*_t31 + 0.2e1*_t22*_t32 + _t23*_t25;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t11*(0.24e2*_hc0[1]*_hc0[2]*_t18*_t5 + 0.6e1*((_hc0[2]) * (_hc0[2]))*_t18*_t2 - 0.36e2*_hc0[2]*_t19*_t2*_t28 - 0.4e1*_hc1[3]*_t17 + 0.12e2*_t15*_t18*_t19 - 0.6e1*_t15*_t26 - 0.24e2*_t29*_t5 + 0.24e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t2/xc_powi((_hc0[0]), 5)) + _t12*_t33*_t34 + _t13*_t31*_t33 - _t14*_t30 + _t25*(0.4e1*_hc0[1]*_t5*_t7 + 0.2e1*_hc0[2]*_t2*_t7 - 0.2e1*_t16 - 0.4e1*_t21) + 0.3e1*_t30*_t32 + 0.2e1*_t31*_t34*_t9 + _t12*_t23*_t4*_t9*(0.3e1*_hc0[1]*_t2*_t7 - 0.3e1*_t6)/(_t10 * _t10 * _t10 * _t10);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_b0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {


  const double f = 0.78494900000000001*rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.78494900000000001;
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
#if _KMAX >= 4
  const double d4f_drs4 = 0;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_gpp1_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = 0.040000000000000001*_t1 + 0.43190000000000001*rs + 0.1e1;
  const double _t4 = xc_powr(0.6e1, 1, 3);
  const double _t5 = (M_CBRTPI * M_CBRTPI);
  const double _t6 = _t4*_t5;
  const double _t7 = _t6/_t3;
  const double _t8 = _t2*_t7;
  const double _t9 = 0.1e1 - 0.022669999999999999*rs;
  const double _t10 = (0.3e1 / 0.5e1)*_t9;
#if _KMAX >= 1
  const double _t11 = (0.1e1 / (rs * rs * rs));
  const double _t12 = _t11*_t7;
  const double _t13 = -0.080000000000000002*rs - 0.43190000000000001;
  const double _t14 = (0.1e1 / (_t3 * _t3));
#endif
#if _KMAX >= 2
  const double _t15 = _t14*_t6;
  const double _t16 = _t15*_t2;
  const double _t17 = (0.1e1 / (rs * rs * rs * rs));
  const double _t18 = _t17*_t7;
  const double _t19 = (0.18e2 / 0.5e1)*_t9;
  const double _t20 = _t11*_t15;
  const double _t21 = _t6/(_t3 * _t3 * _t3);
  const double _t22 = _t2*_t21;
  const double _t23 = -0.16*rs - 0.86380000000000001;
  const double _t24 = _t13*_t23;
  const double _t25 = _t22*_t24;
#endif
#if _KMAX >= 3
  const double _t26 = xc_powi(rs, -5);
  const double _t27 = _t26*_t7;
  const double _t28 = _t22*_t9;
  const double _t29 = 0.096000000000000002*_t28;
  const double _t30 = _t11*_t21;
  const double _t31 = _t24*_t30;
  const double _t32 = -0.23999999999999999*rs - 1.2957000000000001;
  const double _t33 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
#endif
#if _KMAX >= 4
  const double _t34 = _t15*_t17;
  const double _t35 = 0.0087052799999999993*_t22;
  const double _t36 = 0.76800000000000002*_t30;
  const double _t37 = _t23*_t9;
  const double _t38 = _t13*_t9;
  const double _t39 = _t2*_t33*_t6;
  const double _t40 = _t32*_t39;
  const double _t41 = _t24*_t9;
  const double _t42 = _t32*_t6;
#endif

  const double f = _t10*_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.6e1 / 0.5e1*_t12*_t9 + (0.3e1 / 0.5e1)*_t13*_t14*_t2*_t4*_t5*_t9 - 0.013602*_t8;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t10*_t25 + 0.054407999999999998*_t12 - 0.027203999999999999*_t13*_t16 - 0.12e2 / 0.5e1*_t13*_t20*_t9 - 0.048000000000000001*_t16*_t9 + _t18*_t19;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.16322399999999998*_t11*_t13*_t14*_t4*_t5 + 0.28800000000000003*_t11*_t14*_t4*_t5*_t9 + (0.54e2 / 0.5e1)*_t13*_t14*_t17*_t4*_t5*_t9 + (0.3e1 / 0.5e1)*_t13*_t2*_t23*_t32*_t33*_t4*_t5*_t9 - _t13*_t29 + 0.0032644799999999997*_t14*_t2*_t4*_t5 - 0.244836*_t18 - _t19*_t31 - _t23*_t29 - 0.040805999999999995*_t25 - 0.72e2 / 0.5e1*_t27*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t10*_t2*_t24*_t42*(-0.32000000000000001*rs - 1.7276)/xc_powi(_t3, 5) - 0.24e2 / 0.5e1*_t11*_t33*_t41*_t42 - 0.97934399999999999*_t13*_t34 + _t13*_t35 - 0.288e3 / 0.5e1*_t15*_t26*_t38 + (0.108e3 / 0.5e1)*_t17*_t21*_t41 - 0.026115840000000001*_t20 + _t23*_t35 - 0.054407999999999998*_t24*_t40 + 1.3057920000000001*_t27 + 0.023040000000000001*_t28 + 0.32644799999999996*_t31 - 1.7280000000000002*_t34*_t9 + _t36*_t37 + _t36*_t38 - 0.14400000000000002*_t37*_t40 - 0.192*_t38*_t40 - 0.14399999999999999*_t39*_t41 + 0.72e2*_t7*_t9/xc_powi(rs, 6);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_D2_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs);
  const double _t2 = 0.67600000000000005*_t1 - 0.38800000000000001*rs;
  const double _t3 = (0.1e1 / _t1);
  const double _t4 = exp(-0.54700000000000004*rs);
  const double _t5 = _t3*_t4;
  const double _t6 = _t2*_t5;
#if _KMAX >= 1
  const double _t7 = 1.3520000000000001*rs - 0.38800000000000001;
  const double _t8 = (0.1e1 / (rs * rs * rs));
  const double _t9 = _t4*_t8;
  const double _t10 = _t2*_t9;
#endif
#if _KMAX >= 2
  const double _t11 = _t5*_t7;
  const double _t12 = _t7*_t9;
  const double _t13 = (0.1e1 / (rs * rs * rs * rs));
  const double _t14 = _t13*_t4;
  const double _t15 = _t14*_t2;
#endif
#if _KMAX >= 3
  const double _t16 = _t4/xc_powi(rs, 5);
  const double _t17 = _t16*_t2;
#endif

  const double f = _t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -0.2e1*_t10 + _t3*_t4*_t7 - 0.54700000000000004*_t6;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 2.1880000000000002*_t10 - 1.0940000000000001*_t11 - 0.4e1*_t12 + 0.6e1*_t15 + 1.3520000000000001*_t5 + 0.29920900000000006*_t6;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -1.7952540000000003*_t10 + 0.18e2*_t13*_t4*_t7 - 9.8460000000000001*_t15 - 0.24e2*_t17 + 0.89762700000000017*_t3*_t4*_t7 + 6.5640000000000001*_t4*_t7*_t8 - 2.2186320000000004*_t5 - 0.16366732300000003*_t6 - 8.1120000000000001*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 1.3093385840000002*_t10 - 0.65466929200000012*_t11 - 7.1810160000000014*_t12 - 39.384*_t14*_t7 + 48.671999999999997*_t14 + 10.771524000000003*_t15 - 0.96e2*_t16*_t7 + 52.512*_t17 + 0.120e3*_t2*_t4/xc_powi(rs, 6) + 2.4271834080000008*_t5 + 0.089526025681000029*_t6 + 17.749056000000003*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_D3_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = (rs * rs) - 4.9500000000000002*rs;
  const double _t2 = (0.1e1 / (rs * rs * rs));
  const double _t3 = exp(-0.31*rs);
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
#if _KMAX >= 1
  const double _t6 = 0.2e1*rs - 4.9500000000000002;
  const double _t7 = (0.1e1 / (rs * rs * rs * rs));
  const double _t8 = _t3*_t7;
  const double _t9 = _t1*_t8;
#endif
#if _KMAX >= 2
  const double _t10 = _t4*_t6;
  const double _t11 = _t6*_t8;
  const double _t12 = xc_powi(rs, -5);
  const double _t13 = _t12*_t3;
  const double _t14 = _t1*_t13;
#endif
#if _KMAX >= 3
  const double _t15 = _t3/xc_powi(rs, 6);
  const double _t16 = _t1*_t15;
#endif

  const double f = _t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2*_t3*_t6 - 0.31*_t5 - 0.3e1*_t9;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.62*_t10 - 0.6e1*_t11 + 0.12e2*_t14 + 0.2e1*_t4 + 0.096100000000000005*_t5 + 1.8599999999999999*_t9;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.36e2*_t12*_t3*_t6 - 11.16*_t14 - 0.60e2*_t16 + 0.2883*_t2*_t3*_t6 + 5.5800000000000001*_t3*_t6*_t7 - 1.8599999999999999*_t4 - 0.029791000000000002*_t5 - 0.18e2*_t8 - 0.8649*_t9;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.360e3*_t1*_t3/xc_powi(rs, 7) - 0.11916399999999999*_t10 - 3.4596*_t11 - 44.640000000000001*_t13*_t6 + 0.144e3*_t13 + 6.9192*_t14 - 0.240e3*_t15*_t6 + 74.400000000000006*_t16 + 1.1532*_t4 + 0.0092352100000000006*_t5 + 22.32*_t8 + 0.35749200000000003*_t9;
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_a5_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, rs, z, _hc1);
  const double _t1 = xc_powi((_hc0[0]), 8);
#if _KMAX >= 1
  const double _t2 = xc_powi((_hc0[0]), 7)*_hc0[1];
  const double _t3 = 0.8e1*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = 0.16e2*_t2;
  const double _t5 = xc_powi((_hc0[0]), 6)*((_hc0[1]) * (_hc0[1]));
  const double _t6 = 0.56e2*_t5;
#endif
#if _KMAX >= 3
  const double _t7 = 0.24e2*_t2;
  const double _t8 = xc_powi((_hc0[0]), 5)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t9 = 0.336e3*_t8;
  const double _t10 = 0.168e3*_t5;
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _hc1[1]*_t1;
  out[1] = df_dz;
  const double df_drs = _hc1[0]*_t3 + _hc1[2]*_t1;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _hc1[3]*_t1;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc1[1]*_t3 + _hc1[4]*_t1;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = _hc1[0]*_t6 + _hc1[2]*_t4 + _hc1[5]*_t1;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _hc1[6]*_t1;
  out[6] = d3f_dz3;
  const double d3f_drs_dz2 = _hc1[3]*_t3 + _hc1[7]*_t1;
  out[7] = d3f_drs_dz2;
  const double d3f_drs2_dz = _hc1[1]*_t6 + _hc1[4]*_t4 + _hc1[8]*_t1;
  out[8] = d3f_drs2_dz;
  const double d3f_drs3 = _hc1[0]*_t9 + _hc1[2]*_t10 + _hc1[5]*_t7 + _hc1[9]*_t1;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _hc1[10]*_t1;
  out[10] = d4f_dz4;
  const double d4f_drs_dz3 = _hc1[11]*_t1 + _hc1[6]*_t3;
  out[11] = d4f_drs_dz3;
  const double d4f_drs2_dz2 = _hc1[12]*_t1 + _hc1[3]*_t6 + _hc1[7]*_t4;
  out[12] = d4f_drs2_dz2;
  const double d4f_drs3_dz = _hc1[1]*_t9 + _hc1[13]*_t1 + _hc1[4]*_t10 + _hc1[8]*_t7;
  out[13] = d4f_drs3_dz;
  const double d4f_drs4 = 0.1680e4*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0] + _hc1[14]*_t1 + 0.1344e4*_hc1[2]*_t8 + 0.336e3*_hc1[5]*_t5 + 0.32e2*_hc1[9]*_t2;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_gc0_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_g0_m_half_k, _KMAX)(p, rs, _hc0);

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pmgb_a5_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_b0_k, _KMAX)(p, rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, rs, _hc1);
  const double _t1 = xc_powi((_hc0[0]), 8);
#if _KMAX >= 1
  const double _t2 = xc_powi((_hc0[0]), 7)*_hc0[1];
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi((_hc0[0]), 6)*((_hc0[1]) * (_hc0[1]));
#endif
#if _KMAX >= 3
  const double _t4 = xc_powi((_hc0[0]), 5)*((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = 0.8e1*_hc1[0]*_t2 + _hc1[1]*_t1;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = 0.56e2*_hc1[0]*_t3 + 0.16e2*_hc1[1]*_t2 + _hc1[2]*_t1;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = 0.336e3*_hc1[0]*_t4 + 0.168e3*_hc1[1]*_t3 + 0.24e2*_hc1[2]*_t2 + _hc1[3]*_t1;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = 0.1680e4*((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0] + 0.1344e4*_hc1[1]*_t4 + 0.336e3*_hc1[2]*_t3 + 0.32e2*_hc1[3]*_t2 + _hc1[4]*_t1;
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
  const double _t2 = M_CBRTPI;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = xc_powr(na, -1, 3);
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = _t4*_t6;
  const double _t8 = xc_powr(0.12e2, 1, 3);
  const double _t9 = _t3*_t8;
  const double _t10 = xc_powr(M_PI, 1, 6);
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_powr(0.2e1, 2, 3)*xc_powr(0.3e1, 1, 6)*_t11*p->cam_omega;
  const double _t14 = ((p->cam_omega) * (p->cam_omega));
  const double _t17 = xc_powi((p->cam_omega), 8);
  const double _t19 = xc_powr(0.2e1, 1, 2);
  const double _t20 = xc_powr(M_PI, 1, 2);
  const double _t21 = _t19*_t20;
  const double _t23 = xc_powi((p->cam_omega), 5);
  const double _t26 = xc_powi((p->cam_omega), 6);
  const double _t30 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t36 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t39 = xc_powr(0.3e1, 2, 3);
  const double _t40 = (M_PI * M_CBRTPI);
  const double _t41 = _t39*_t40;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_b0_k, _KMAX)(p, _t7, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_g0_k, _KMAX)(p, _t7, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_gpp1_k, _KMAX)(p, _t6*_t9, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_D3_k, _KMAX)(p, _t7, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, _t7, _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_gc0_z0_k, _KMAX)(p, _t7, _hc5);
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_D2_k, _KMAX)(p, _t7, _hc6);
  double _hc7[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_a5_z0_k, _KMAX)(p, _t7, _hc7);
  double _hc8[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_Q_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t12/xc_powr(na, 1, 6), _hc8);
  const double _t13 = ((_hc0[0]) * (_hc0[0]));
  const double _t15 = _t13*_t14 + 0.1e1;
  const double _t16 = (0.1e1 / (_t15 * _t15 * _t15 * _t15));
  const double _t18 = xc_powi((_hc0[0]), 8);
  const double _t22 = _t18*_t21;
  const double _t24 = _hc1[0]*_t23;
  const double _t25 = (0.2e1 / 0.3e1)*_t22*_t24;
  const double _t27 = xc_powi((_hc0[0]), 6);
  const double _t28 = M_PI*_hc5[0];
  const double _t29 = (0.1e1 / 0.2e1)*_t18*_t28;
  const double _t31 = (0.8e1 / 0.3e1)*_hc1[0]*_t21*_t27;
  const double _t32 = (0.1e1 / 0.2e1)*_hc2[0];
  const double _t33 = _hc3[0] + _t32;
  const double _t34 = (0.3e1 / 0.20e2)*_t22;
  const double _t35 = _t33*_t34;
  const double _t37 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t38 = 0.2e1*_t27*_t28;
  const double _t42 = _hc6[0] + _t32 - 0.1e1 / 0.5e1*_t41*xc_powr(na, 2, 3);
  const double _t43 = M_PI*_t18;
  const double _t44 = (0.3e1 / 0.16e2)*_t43;
  const double _t45 = _t42*_t44;
  const double _t46 = _hc7[0]*_t17 + _hc8[0] - _t25*na + _t26*(0.4e1*_hc4[0]*_t27 - _t29*na) + _t30*(-_t31*na - _t35*na) + _t36*(0.6e1*_hc4[0]*_t37 - _t38*na - _t45*na);
  const double _t47 = _t16*_t46;
  const double zk = _t47;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t52 = _t4*_t5;
  const double _t53 = xc_powr(na, -4, 3);
  const double _t54 = _t4*_t53;
  const double _t55 = (0.1e1 / 0.6e1)*_t54;
  const double _t58 = xc_powr(0.2e1, 5, 6);
  const double _t59 = M_CBRT3;
  const double _t60 = _t58*_t59;
  const double _t61 = _t10*_t60;
  const double _t70 = (M_CBRTPI * M_CBRTPI);
  double _hc9[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_b0_k, _KMAX)(p, 0, _hc9);
  const double _t48 = (0.4e1 / 0.3e1)*_hc9[1];
  const double _t49 = _t14/xc_powi(_t15, 5);
  const double _t50 = _hc0[0]*_t49;
  const double _t51 = _t46*_t50;
  const double _t56 = _hc7[1]*_t17;
  const double _t57 = _hc8[1]*_t12;
  const double _t62 = _hc1[1]*_t61;
  const double _t63 = _t18*_t23;
  const double _t64 = _t62*_t63;
  const double _t65 = xc_powi((_hc0[0]), 7);
  const double _t66 = _hc9[1]*_t65;
  const double _t67 = _t61*_t66;
  const double _t68 = _t5*_t67;
  const double _t69 = _hc4[1]*_t54;
  const double _t71 = 0.4e1*_hc4[0];
  const double _t72 = _t54*_t71;
  const double _t73 = xc_powi((_hc0[0]), 5);
  const double _t74 = _hc9[1]*_t73;
  const double _t75 = _hc2[1]*_t9;
  const double _t76 = (0.1e1 / 0.12e2)*_t53*_t75;
  const double _t77 = -_hc3[1]*_t55 - _t76;
  const double _t78 = _t34*na;
  const double _t79 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t80 = _hc9[1]*_t79;
  const double _t81 = -_hc6[1]*_t55 - 0.2e1 / 0.15e2*_t41*_t5 - _t76;
  const double _t82 = _t44*na;
  const double _t83 = (0.8e1 / 0.9e1)*_t24*_t68 - _t25 + _t26*((0.2e1 / 0.3e1)*_hc5[0]*_hc9[1]*_t1*_t5*_t65*_t70 + (0.1e1 / 0.12e2)*_hc5[1]*_t1*_t18*_t5*_t70 - 0.2e1 / 0.3e1*_t27*_t69 - _t29 - _t72*_t74) + _t30*((0.8e1 / 0.3e1)*_hc1[0]*_hc9[1]*_t10*_t5*_t58*_t59*_t73 + (0.4e1 / 0.9e1)*_hc1[1]*_t10*_t27*_t5*_t58*_t59 + (0.1e1 / 0.5e1)*_hc9[1]*_t10*_t33*_t5*_t58*_t59*_t65 - _t31 - _t35 - _t77*_t78) + _t36*(0.2e1*_hc5[0]*_hc9[1]*_t1*_t5*_t70*_t73 + (0.1e1 / 0.3e1)*_hc5[1]*_t1*_t27*_t5*_t70 + (0.1e1 / 0.4e1)*_hc9[1]*_t1*_t42*_t5*_t65*_t70 - _t37*_t69 - _t38 - _t45 - _t72*_t80 - _t81*_t82) + (0.1e1 / 0.9e1)*_t5*_t64 - _t55*_t56 - 0.1e1 / 0.12e2*_t57/xc_powr(na, 7, 6);
  const double _t84 = _t16*_t83;
  const double dF_dna = _t47 + _t48*_t51*_t52 + _t84*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t86 = xc_powr(na, -5, 3);
  const double _t87 = (0.2e1 / 0.9e1)*_t86;
  const double _t88 = (0.1e1 / _t70);
  const double _t89 = xc_powr(0.6e1, 2, 3);
  const double _t90 = _t88*_t89;
  const double _t100 = xc_powr(na, -7, 3);
  const double _t101 = (0.2e1 / 0.9e1)*_t100;
  const double _t103 = _t100*_t4;
  const double _t105 = xc_powr(na, -8, 3);
  const double _t106 = _t105*_t88;
  const double _t107 = (0.1e1 / 0.36e2)*_t106;
  const double _t108 = _t107*_t89;
  const double _t110 = xc_powr(0.2e1, 1, 6);
  const double _t111 = _t11*_t110*_t39;
  const double _t116 = _t111*_t86;
  const double _t127 = _t1*_t70;
  const double _t130 = _t106*_t89;
  const double _t132 = _t2*_t89;
  const double _t135 = (0.16e2 / 0.3e1)*_t103;
  const double _t140 = (0.4e1 / 0.3e1)*_t130;
  const double _t85 = _hc9[1]*_t51;
  const double _t91 = _t46*_t90;
  const double _t92 = ((_hc9[1]) * (_hc9[1]));
  const double _t93 = _t49*_t92;
  const double _t94 = _t36/xc_powi(_t15, 6);
  const double _t95 = _t13*_t92;
  const double _t96 = (0.20e2 / 0.9e1)*_t95;
  const double _t97 = _t50*_t52;
  const double _t98 = _hc9[1]*_t97;
  const double _t99 = (0.8e1 / 0.3e1)*_t83;
  const double _t102 = _t4*_t56;
  const double _t104 = _hc8[2]*_t14;
  const double _t109 = _hc7[2]*_t17;
  const double _t112 = _hc1[2]*_t111;
  const double _t113 = _t112*_t63;
  const double _t114 = (0.1e1 / 0.27e2)*_t113;
  const double _t115 = (0.2e1 / 0.27e2)*_t63;
  const double _t117 = _t23*_t66;
  const double _t118 = (0.16e2 / 0.27e2)*_t117;
  const double _t119 = _t53*_t67;
  const double _t120 = _t27*_t86;
  const double _t121 = _t111*_t92;
  const double _t122 = _t120*_t121;
  const double _t123 = (0.56e2 / 0.27e2)*_t24;
  const double _t124 = (0.8e1 / 0.9e1)*_t27;
  const double _t125 = _hc4[1]*_t103;
  const double _t126 = (0.1e1 / 0.18e2)*_t18;
  const double _t128 = _hc5[1]*_t127;
  const double _t129 = _t128*_t53;
  const double _t131 = _hc4[2]*_t27;
  const double _t133 = _hc5[2]*_t132;
  const double _t134 = _t133*_t86;
  const double _t136 = _hc4[0]*_t74;
  const double _t137 = _hc9[1]*_t127;
  const double _t138 = _t137*_t65;
  const double _t139 = _t138*_t53;
  const double _t141 = _hc4[1]*_t74;
  const double _t142 = _hc5[1]*_t132;
  const double _t143 = _t142*_t66;
  const double _t144 = _hc4[0]*_t37*_t92;
  const double _t145 = _t132*_t92;
  const double _t146 = _t120*_t145;
  const double _t147 = (0.4e1 / 0.27e2)*_t112;
  const double _t148 = _t74*_t86;
  const double _t149 = _hc1[1]*_t111;
  const double _t150 = (0.16e2 / 0.9e1)*_t149;
  const double _t151 = _t37*_t92;
  const double _t152 = (0.40e2 / 0.9e1)*_hc1[0];
  const double _t153 = _t151*_t152;
  const double _t154 = (0.7e1 / 0.15e2)*_t33;
  const double _t155 = _hc3[1]*_t4;
  const double _t156 = xc_powr(0.18e2, 1, 3)*_hc2[2];
  const double _t157 = (0.1e1 / 0.9e1)*_t100*_t75 + _t107*_t156;
  const double _t158 = _hc3[2]*_t108 + _t101*_t155 + _t157;
  const double _t159 = (0.4e1 / 0.3e1)*_t37;
  const double _t160 = (0.2e1 / 0.9e1)*_t27;
  const double _t161 = _hc4[2]*_t37;
  const double _t162 = _hc4[0]*_t79;
  const double _t163 = _hc9[1]*_t162;
  const double _t164 = _hc5[0]*_t137*_t73;
  const double _t165 = _hc4[1]*_t80;
  const double _t166 = _hc4[0]*_t95;
  const double _t167 = _hc5[0]*_t145;
  const double _t168 = (0.5e1 / 0.3e1)*_t37;
  const double _t169 = _t138*_t81;
  const double _t170 = _hc6[1]*_t4;
  const double _t171 = _hc6[2]*_t108 + _t101*_t170 + _t157 + (0.2e1 / 0.45e2)*_t41*_t53;
  const double _t172 = -_hc1[1]*_t116*_t118 + _t101*_t102 + (0.1e1 / 0.72e2)*_t103*_t104 + _t108*_t109 - _t114*_t86 + _t115*_t53*_t62 + (0.16e2 / 0.27e2)*_t119*_t24 - _t122*_t123 + _t26*((0.4e1 / 0.9e1)*_hc5[0]*_t139 - 0.7e1 / 0.9e1*_hc5[0]*_t146 + _t124*_t125 + _t126*_t129 + (0.1e1 / 0.9e1)*_t130*_t131 + (0.10e2 / 0.3e1)*_t130*_t144 - 0.1e1 / 0.72e2*_t134*_t18 + _t135*_t136 + _t140*_t141 - _t143*_t87) + _t30*((0.16e2 / 0.9e1)*_hc1[0]*_hc9[1]*_t10*_t53*_t58*_t59*_t73 + (0.8e1 / 0.27e2)*_hc1[1]*_t10*_t27*_t53*_t58*_t59 + (0.2e1 / 0.15e2)*_hc9[1]*_t10*_t33*_t53*_t58*_t59*_t65 + (0.2e1 / 0.5e1)*_hc9[1]*_t10*_t5*_t58*_t59*_t65*_t77 - _t116*_t153 - _t120*_t147 - _t122*_t154 - _t148*_t150 - _t158*_t78 - 0.3e1 / 0.10e2*_t22*_t77) + _t36*(_t125*_t159 + _t129*_t160 + (0.1e1 / 0.6e1)*_t130*_t161 + 0.2e1*_t130*_t166 - 0.1e1 / 0.18e2*_t134*_t27 + _t135*_t163 + (0.1e1 / 0.6e1)*_t139*_t42 + _t140*_t165 - 0.2e1 / 0.3e1*_t142*_t148 - 0.7e1 / 0.24e2*_t146*_t42 + (0.4e1 / 0.3e1)*_t164*_t53 - _t167*_t168*_t86 + _t169*_t6 - _t171*_t82 - 0.3e1 / 0.8e1*_t43*_t81) + (0.7e1 / 0.72e2)*_t57/xc_powr(na, 13, 6);
  const double _t173 = _t16*_t172;
  const double d2F_dna2 = _t173*na + (0.8e1 / 0.9e1)*_t54*_t85 + 0.2e1*_t84 + _t86*_t91*_t94*_t96 - _t87*_t91*_t93 + _t98*_t99;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t174 = (0.1e1 / (na * na * na));
  const double _t175 = (0.20e2 / 0.3e1)*_t174;
  const double _t176 = (0.1e1 / M_PI);
  const double _t183 = (0.80e2 / 0.3e1)*_t174;
  const double _t190 = _t86*_t90;
  const double _t193 = (0.1e1 / (na * na * na * na));
  const double _t194 = (0.1e1 / 0.36e2)*_t193;
  const double _t195 = _t176*_t194;
  const double _t197 = (0.1e1 / _t20);
  const double _t199 = xc_powr(na, -10, 3);
  const double _t200 = (0.14e2 / 0.27e2)*_t199;
  const double _t201 = _t199*_t4;
  const double _t202 = xc_powr(na, -11, 3);
  const double _t203 = (0.1e1 / 0.9e1)*_t202;
  const double _t204 = _t203*_t90;
  const double _t205 = _t19*_t197;
  const double _t208 = _t174*_t23;
  const double _t225 = _t202*_t90;
  const double _t226 = _t176*_t193;
  const double _t230 = (0.112e3 / 0.9e1)*_t201;
  const double _t232 = (0.16e2 / 0.3e1)*_t225;
  const double _t177 = _t176*_t46;
  const double _t178 = ((_hc9[1]) * (_hc9[1]) * (_hc9[1]));
  const double _t179 = _hc0[0]*_t178;
  const double _t180 = _t179*_t94;
  const double _t181 = _t177*_t180;
  const double _t182 = _t46*_t93;
  const double _t184 = _t178*_t79;
  const double _t185 = _t26/xc_powi(_t15, 7);
  const double _t186 = _t184*_t185;
  const double _t187 = _t46*_t94;
  const double _t188 = _hc9[1]*_t50;
  const double _t189 = _t83*_t93;
  const double _t191 = _t94*_t95;
  const double _t192 = _t191*_t83;
  const double _t196 = _hc7[3]*_t17;
  const double _t198 = xc_powr(0.3e1, 1, 2)*_hc8[3]*_t197*_t30;
  const double _t206 = _hc1[3]*_t205;
  const double _t207 = _t174*_t206;
  const double _t209 = _hc1[2]*_t205;
  const double _t210 = _t209*_t66;
  const double _t211 = _t174*_t73;
  const double _t212 = _t178*_t211;
  const double _t213 = _hc1[1]*_t205;
  const double _t214 = _t213*_t92;
  const double _t215 = _t100*_t67;
  const double _t216 = _t105*_t27;
  const double _t217 = _t121*_t216;
  const double _t218 = _hc4[3]*_t176;
  const double _t219 = _t193*_t27;
  const double _t220 = _t193*_t73;
  const double _t221 = _hc4[2]*_hc9[1];
  const double _t222 = 0.2e1*_t221;
  const double _t223 = _hc4[1]*_t27;
  const double _t224 = _t128*_t18;
  const double _t227 = _t178*_t226;
  const double _t228 = _t193*_t37;
  const double _t229 = _t176*_t92;
  const double _t231 = _hc5[0]*_t138;
  const double _t233 = (0.80e2 / 0.9e1)*_t184;
  const double _t234 = _hc1[0]*_t205;
  const double _t235 = _t205*_t33;
  const double _t236 = _hc2[3]*_t176;
  const double _t237 = _t156*_t88;
  const double _t238 = _t194*_t236 + (0.7e1 / 0.27e2)*_t199*_t75 + _t203*_t237;
  const double _t239 = -_hc3[2]*_t204 - _hc3[3]*_t195 - _t155*_t200 - _t238;
  const double _t240 = _hc4[1]*_t37;
  const double _t241 = _t128*_t27;
  const double _t242 = _hc4[1]*_t95;
  const double _t243 = _t138*_t42;
  const double _t244 = -_hc6[2]*_t204 - _hc6[3]*_t195 - 0.8e1 / 0.135e3*_t100*_t41 - _t170*_t200 - _t238;
  const double _t245 = -0.8e1 / 0.81e2*_t100*_t64 - _t102*_t200 - 0.7e1 / 0.144e3*_t104*_t201 + _t105*_t114 + _t105*_t118*_t149 - _t109*_t204 + _t123*_t217 - _t195*_t196 - 0.1e1 / 0.432e3*_t198/xc_powr(na, 7, 2) + (0.56e2 / 0.9e1)*_t205*_t212*_t24 + (0.1e1 / 0.54e2)*_t207*_t63 + (0.4e1 / 0.9e1)*_t208*_t210 + (0.28e2 / 0.9e1)*_t208*_t214*_t27 - 0.64e2 / 0.81e2*_t215*_t24 + _t26*(-0.10e2*_hc4[1]*_t228*_t229 + (0.7e1 / 0.9e1)*_hc5[0]*_t105*_t2*_t27*_t89*_t92 + (0.14e2 / 0.3e1)*_hc5[0]*_t174*_t178*_t73 + (0.2e1 / 0.9e1)*_hc5[1]*_hc9[1]*_t105*_t2*_t65*_t89 + (0.7e1 / 0.3e1)*_hc5[1]*_t174*_t27*_t92 + (0.1e1 / 0.3e1)*_hc5[2]*_hc9[1]*_t174*_t65 + (0.1e1 / 0.72e2)*_hc5[2]*_t105*_t18*_t2*_t89 + (0.1e1 / 0.72e2)*_hc5[3]*_t174*_t18 - 0.2e1 / 0.27e2*_t100*_t224 - 0.16e2 / 0.27e2*_t100*_t231 - 0.4e1 / 0.9e1*_t131*_t225 - _t136*_t230 - _t141*_t232 - 0.40e2 / 0.3e1*_t144*_t225 - 0.40e2 / 0.3e1*_t162*_t227 - _t176*_t220*_t222 - 0.56e2 / 0.27e2*_t201*_t223 - 0.1e1 / 0.9e1*_t218*_t219) + _t30*(-0.64e2 / 0.27e2*_hc1[0]*_t100*_t61*_t74 - 0.32e2 / 0.81e2*_t100*_t27*_t62 - 0.8e1 / 0.45e2*_t100*_t33*_t67 + _t105*_t111*_t153 + _t105*_t150*_t74 + (0.2e1 / 0.5e1)*_t119*_t77 - 0.7e1 / 0.5e1*_t122*_t77 + _t147*_t216 + _t151*_t175*_t213 + _t154*_t217 - 0.9e1 / 0.20e2*_t158*_t22 + (0.3e1 / 0.5e1)*_t158*_t68 + _t174*_t233*_t234 + (0.2e1 / 0.27e2)*_t207*_t27 + _t209*_t211*_t48 + (0.7e1 / 0.5e1)*_t212*_t235 - _t239*_t78) + _t36*(-_hc0[0]*_t227*_t71 + (0.5e1 / 0.3e1)*_hc5[0]*_t105*_t2*_t37*_t89*_t92 + (0.20e2 / 0.3e1)*_hc5[0]*_t174*_t178*_t79 + (0.2e1 / 0.3e1)*_hc5[1]*_hc9[1]*_t105*_t2*_t73*_t89 + 0.5e1*_hc5[1]*_t174*_t37*_t92 + _hc5[2]*_hc9[1]*_t174*_t73 + (0.1e1 / 0.18e2)*_hc5[2]*_t105*_t2*_t27*_t89 + (0.1e1 / 0.18e2)*_hc5[3]*_t174*_t27 + (0.3e1 / 0.4e1)*_hc9[1]*_t1*_t171*_t5*_t65*_t70 + (0.1e1 / 0.2e1)*_hc9[1]*_t1*_t53*_t65*_t70*_t81 - 0.16e2 / 0.9e1*_t100*_t164 - 0.8e1 / 0.27e2*_t100*_t241 - _t101*_t243 + (0.7e1 / 0.24e2)*_t105*_t2*_t27*_t42*_t89*_t92 - 0.7e1 / 0.8e1*_t146*_t81 - 0.2e1 / 0.3e1*_t161*_t225 - _t163*_t230 - _t165*_t232 - 0.8e1*_t166*_t225 - 0.9e1 / 0.16e2*_t171*_t43 + (0.7e1 / 0.4e1)*_t174*_t178*_t42*_t73 - 0.28e2 / 0.9e1*_t201*_t240 - 0.1e1 / 0.6e1*_t218*_t228 - _t222*_t226*_t79 - 0.6e1*_t226*_t242 - _t244*_t82) - 0.91e2 / 0.432e3*_t57/xc_powr(na, 19, 6);
  const double _t246 = _t16*_t245;
  const double d3F_dna3 = -0.32e2 / 0.27e2*_t103*_t85 + (0.2e1 / 0.9e1)*_t130*_t182 - _t130*_t187*_t96 + 0.4e1*_t172*_t98 + 0.3e1*_t173 - _t175*_t181 + _t177*_t183*_t186 + _t188*_t54*_t99 - 0.2e1 / 0.3e1*_t189*_t190 + (0.20e2 / 0.3e1)*_t190*_t192 + _t246*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t247 = (0.80e2 / 0.3e1)*_t193;
  const double _t248 = (0.1e1 / _t40);
  const double _t249 = xc_powr(na, -13, 3);
  const double _t256 = xc_powi(na, -5);
  const double _t257 = (0.2e1 / 0.9e1)*_t256;
  const double _t258 = _t176*_t257;
  const double _t259 = _t248/xc_powr(na, 16, 3);
  const double _t260 = (0.1e1 / 0.216e3)*_t259;
  const double _t261 = _t1*_t260;
  const double _t262 = (0.140e3 / 0.81e2)*_t249;
  const double _t263 = _t249*_t4;
  const double _t264 = xc_powr(na, -14, 3);
  const double _t265 = (0.40e2 / 0.81e2)*_t264;
  const double _t266 = _t265*_t90;
  const double _t267 = _t264*_t90;
  const double _t269 = _t249*_t60/xc_powr(M_PI, 5, 6);
  const double _t284 = _t176*_t256;
  const double _t286 = _t1*_t259;
  const double _t292 = (0.1120e4 / 0.27e2)*_t263;
  const double _t294 = (0.640e3 / 0.27e2)*_t267;
  const double _t250 = ((_hc9[1]) * (_hc9[1]) * (_hc9[1]) * (_hc9[1]));
  const double _t251 = _t1*_t248*_t249*_t250;
  const double _t252 = _t185*_t46;
  const double _t253 = _t176*_t83;
  const double _t254 = (0.16e2 / 0.3e1)*_hc9[1];
  const double _t255 = _t172*_t190;
  const double _t268 = _t178*_t220;
  const double _t270 = _hc1[4]*_t269;
  const double _t271 = _hc1[3]*_t269;
  const double _t272 = _t202*_t27;
  const double _t273 = _t121*_t272;
  const double _t274 = _t250*_t269;
  const double _t275 = _t274*_t37;
  const double _t276 = _t178*_t73;
  const double _t277 = _hc1[1]*_t269;
  const double _t278 = _hc1[2]*_t269;
  const double _t279 = _hc5[3]*_t193;
  const double _t280 = _hc5[2]*_hc9[1];
  const double _t281 = _t218*_t256;
  const double _t282 = _hc5[0]*_t178;
  const double _t283 = _hc5[1]*_t92;
  const double _t285 = 0.16e2*_t221*_t284;
  const double _t287 = _hc4[4]*_t286;
  const double _t288 = _hc5[4]*_t263;
  const double _t289 = _t133*_t202;
  const double _t290 = _t178*_t284;
  const double _t291 = (0.4e1 / 0.9e1)*_hc4[3]*_t286;
  const double _t293 = _hc5[3]*_t263;
  const double _t295 = _hc4[0]*_t250*_t286;
  const double _t296 = _hc4[1]*_t286;
  const double _t297 = _t250*_t263;
  const double _t298 = _t297*_t37;
  const double _t299 = _hc5[1]*_t263;
  const double _t300 = _hc5[2]*_t263*_t92;
  const double _t301 = _t202*_t74;
  const double _t302 = _hc2[4]*_t260*_t8 + _t236*_t257 + _t237*_t265 + (0.70e2 / 0.81e2)*_t249*_t75;
  const double d4F_dna4 = -0.128e3 / 0.27e2*_t103*_t188*_t83 - 0.80e2 / 0.3e1*_t13*_t251*_t252 + (0.8e1 / 0.9e1)*_t130*_t189 - 0.80e2 / 0.9e1*_t130*_t192 + _t16*na*(_hc7[4]*_t17*_t261 + (0.1e1 / 0.5184e4)*_hc8[4]*_t267*_t36 + _t102*_t262 + (0.511e3 / 0.2592e4)*_t104*_t263 + _t109*_t266 - 0.16e2 / 0.243e3*_t113*_t202 - _t115*_t193*_t206 - 0.256e3 / 0.243e3*_t117*_t149*_t202 - 0.8e1 / 0.81e2*_t117*_t271 - 0.16e2 / 0.9e1*_t193*_t210*_t23 + _t196*_t258 + (0.7e1 / 0.432e3)*_t198/xc_powr(na, 9, 2) + (0.448e3 / 0.243e3)*_t199*_t24*_t67 + (0.56e2 / 0.243e3)*_t199*_t64 - 0.224e3 / 0.9e1*_t205*_t24*_t268 - 0.112e3 / 0.9e1*_t214*_t219*_t23 - 0.28e2 / 0.27e2*_t23*_t27*_t278*_t92 - 0.112e3 / 0.27e2*_t23*_t276*_t277 - 0.896e3 / 0.243e3*_t24*_t273 - 0.140e3 / 0.27e2*_t24*_t275 + _t26*(-0.35e2 / 0.9e1*_hc5[0]*_t298 + _t124*_t281 - _t126*_t279 + (0.20e2 / 0.3e1)*_t13*_t295 + (0.160e3 / 0.81e2)*_t131*_t267 + _t136*_t292 + _t141*_t294 - 0.32e2 / 0.81e2*_t143*_t202 + (0.1600e4 / 0.27e2)*_t144*_t267 + (0.10e2 / 0.3e1)*_t161*_t286*_t92 + (0.320e3 / 0.3e1)*_t162*_t290 - 0.112e3 / 0.81e2*_t167*_t272 - 0.1e1 / 0.432e3*_t18*_t288 - 0.2e1 / 0.81e2*_t18*_t289 - 0.4e1 / 0.3e1*_t193*_t280*_t65 + (0.14e2 / 0.81e2)*_t199*_t224 + (0.112e3 / 0.81e2)*_t199*_t231 - 0.28e2 / 0.3e1*_t219*_t283 - 0.56e2 / 0.3e1*_t220*_t282 + (0.560e3 / 0.81e2)*_t223*_t263 + 0.80e2*_t229*_t240*_t256 + _t233*_t296 + (0.1e1 / 0.54e2)*_t27*_t287 - 0.7e1 / 0.9e1*_t27*_t300 - 0.28e2 / 0.9e1*_t276*_t299 + _t285*_t73 + _t291*_t74 - 0.2e1 / 0.27e2*_t293*_t66) - 0.1e1 / 0.324e3*_t270*_t63 + _t30*((0.448e3 / 0.81e2)*_hc1[0]*_hc9[1]*_t10*_t199*_t58*_t59*_t73 - 0.640e3 / 0.81e2*_hc1[0]*_t111*_t151*_t202 + (0.224e3 / 0.243e3)*_hc1[1]*_t10*_t199*_t27*_t58*_t59 + (0.4e1 / 0.5e1)*_hc9[1]*_t10*_t158*_t53*_t58*_t59*_t65 + (0.56e2 / 0.135e3)*_hc9[1]*_t10*_t199*_t33*_t58*_t59*_t65 + (0.4e1 / 0.5e1)*_hc9[1]*_t10*_t239*_t5*_t58*_t59*_t65 + (0.28e2 / 0.15e2)*_t105*_t11*_t110*_t27*_t39*_t77*_t92 - 0.64e2 / 0.243e3*_t112*_t272 - 0.14e2 / 0.5e1*_t122*_t158 - _t13*_t152*_t274 - 0.256e3 / 0.81e2*_t149*_t301 - 0.20e2 / 0.9e1*_t151*_t278 + (0.28e2 / 0.5e1)*_t174*_t178*_t19*_t197*_t73*_t77 - 0.320e3 / 0.9e1*_t184*_t193*_t234 - 0.160e3 / 0.27e2*_t184*_t277 - 0.8e1 / 0.27e2*_t206*_t219 - _t209*_t220*_t254 - 0.80e2 / 0.3e1*_t214*_t228 - 0.32e2 / 0.45e2*_t215*_t77 - 0.3e1 / 0.5e1*_t22*_t239 - 0.28e2 / 0.5e1*_t235*_t268 - 0.1e1 / 0.81e2*_t27*_t270 - 0.8e1 / 0.27e2*_t271*_t74 - 0.112e3 / 0.135e3*_t273*_t33 - 0.7e1 / 0.6e1*_t275*_t33 - _t78*(_hc3[2]*_t266 + _hc3[3]*_t258 + _hc3[4]*_t261 + _t155*_t262 + _t302)) + _t36*(0.32e2*_hc0[0]*_hc4[0]*_t290 + 0.2e1*_hc4[2]*_t286*_t95 - 0.10e2 / 0.3e1*_hc5[0]*_t13*_t297 - 0.8e1 / 0.9e1*_t100*_t169 + _t138*_t244*_t5 + _t139*_t171 - 0.32e2 / 0.27e2*_t142*_t301 + (0.7e1 / 0.6e1)*_t145*_t216*_t81 - 0.14e2 / 0.27e2*_t145*_t272*_t42 - 0.7e1 / 0.4e1*_t146*_t171 + _t159*_t281 - _t160*_t279 + (0.80e2 / 0.27e2)*_t161*_t267 + _t163*_t292 + (0.112e3 / 0.27e2)*_t164*_t199 + _t165*_t294 + (0.320e3 / 0.9e1)*_t166*_t267 - 0.80e2 / 0.27e2*_t167*_t202*_t37 - _t168*_t300 + (0.8e1 / 0.3e1)*_t179*_t296 - 0.40e2 / 0.9e1*_t184*_t299 + (0.56e2 / 0.81e2)*_t199*_t241 + _t200*_t243 + 0.7e1*_t212*_t81 - 0.4e1*_t220*_t280 - 0.20e2*_t228*_t283 + (0.280e3 / 0.27e2)*_t240*_t263 + 0.48e2*_t242*_t284 - 0.3e1 / 0.4e1*_t244*_t43 - _t247*_t282*_t79 - 0.7e1*_t268*_t42 - 0.1e1 / 0.108e3*_t27*_t288 - 0.8e1 / 0.81e2*_t27*_t289 + _t285*_t79 + (0.1e1 / 0.36e2)*_t287*_t37 + _t291*_t80 - 0.2e1 / 0.9e1*_t293*_t74 + (0.2e1 / 0.3e1)*_t295 - 0.35e2 / 0.24e2*_t298*_t42 - _t82*(_hc6[2]*_t266 + _hc6[3]*_t258 + _hc6[4]*_t261 + _t170*_t262 + (0.56e2 / 0.405e3)*_t199*_t41 + _t302)) + (0.1729e4 / 0.2592e4)*_t57/xc_powr(na, 25, 6)) + _t172*_t254*_t50*_t54 + (0.320e3 / 0.3e1)*_t174*_t186*_t253 - _t180*_t183*_t253 + _t181*_t247 - 0.32e2 / 0.81e2*_t182*_t225 + (0.320e3 / 0.81e2)*_t187*_t225*_t95 + (0.10e2 / 0.9e1)*_t187*_t251 + (0.40e2 / 0.3e1)*_t191*_t255 + (0.224e3 / 0.81e2)*_t201*_t85 - 0.320e3 / 0.3e1*_t227*_t252*_t79 + _t245*_t254*_t97 + 0.4e1*_t246 - 0.4e1 / 0.3e1*_t255*_t93 + (0.560e3 / 0.9e1)*_t17*_t251*_t37*_t46/xc_powi(_t15, 8);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(_t1, -1, 3);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = M_CBRTPI;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t3*_t5;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = _t2*_t7;
  const double _t9 = na - nb;
  const double _t10 = (0.1e1 / _t1);
  const double _t11 = _t10*_t9;
  const double _t12 = xc_powr(0.2e1, 2, 3);
  const double _t13 = xc_powr(0.3e1, 1, 6);
  const double _t14 = xc_powr(M_PI, 1, 6);
  const double _t15 = (0.1e1 / _t14);
  const double _t16 = _t12*_t13*_t15*p->cam_omega;
  const double _t18 = xc_powr(_t1, -1, 6);
  const double _t19 = (0.1e1 / 0.2e1)*_t18;
  const double _t21 = ((p->cam_omega) * (p->cam_omega));
  const double _t24 = xc_powi((p->cam_omega), 8);
  const double _t26 = na*nb;
  const double _t28 = xc_powi((p->cam_omega), 5);
  const double _t30 = xc_powr(0.2e1, 1, 2);
  const double _t31 = xc_powr(M_PI, 1, 2);
  const double _t32 = _t30*_t31;
  const double _t37 = xc_powi((p->cam_omega), 6);
  const double _t39 = 0.2e1*nb;
  const double _t44 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t48 = (0.1e1 / (_t1 * _t1));
  const double _t49 = 0.4e1*_t48;
  const double _t58 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t64 = xc_powr(0.3e1, 2, 3);
  const double _t66 = xc_powr(_t1, 2, 3);
  const double _t67 = (M_PI * M_CBRTPI);
  const double _t68 = (0.1e1 / 0.5e1)*_t67;
  const double _t69 = _t66*_t68;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_b0_k, _KMAX)(p, _t8, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t11, 0.2e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_gpp1_k, _KMAX)(p, _t7/xc_powr(na, 1, 3), _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, -_t11, 0.2e1, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_gpp1_k, _KMAX)(p, _t7/xc_powr(nb, 1, 3), _hc4);
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_D3_k, _KMAX)(p, _t8, _hc5);
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_g0_k, _KMAX)(p, _t8, _hc6);
  double _hc7[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, _t8, _t11, _hc7);
  double _hc8[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_D2_k, _KMAX)(p, _t8, _hc8);
  double _hc9[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pmgb_phi_k, _KMAX)(p, 0.8e1, _t11, _hc9);
  double _hc10[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pmgb_gc0_k, _KMAX)(p, _t8, _t11, _hc10);
  double _hc11[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pmgb_a5_k, _KMAX)(p, _t8, _t11, _hc11);
  double _hc12[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pmgb_phi_k, _KMAX)(p, 0.2e1, _t11, _hc12);
  const double _t17 = _t16/_hc12[0];
  const double _t20 = ((_hc0[0]) * (_hc0[0]));
  const double _t22 = _t20*_t21 + 0.1e1;
  const double _t23 = (0.1e1 / (_t22 * _t22 * _t22 * _t22));
  const double _t25 = ((_hc12[0]) * (_hc12[0]) * (_hc12[0]));
  const double _t27 = _hc6[0]*_t10;
  const double _t29 = xc_powi((_hc0[0]), 8);
  const double _t33 = _t29*_t32;
  const double _t34 = _t28*_t33;
  const double _t35 = (0.8e1 / 0.3e1)*_t34;
  const double _t36 = _t27*_t35;
  const double _t38 = xc_powi((_hc0[0]), 6);
  const double _t40 = M_PI*_t29;
  const double _t41 = _hc10[0]*_t10;
  const double _t42 = _t40*_t41;
  const double _t43 = _t39*_t42;
  const double _t45 = _t32*_t38;
  const double _t46 = (0.32e2 / 0.3e1)*_t45;
  const double _t47 = _t27*_t46;
  const double _t50 = _hc5[0]*_t49;
  const double _t51 = _t50*nb;
  const double _t52 = (0.1e1 / 0.4e1)*_hc1[0] + 0.1e1 / 0.4e1;
  const double _t53 = (0.1e1 / 0.4e1)*_hc3[0] + 0.1e1 / 0.4e1;
  const double _t54 = _hc2[0]*_t52 + _hc4[0]*_t53;
  const double _t55 = _t51*na + _t54;
  const double _t56 = (0.3e1 / 0.20e2)*_t33;
  const double _t57 = _t55*_t56;
  const double _t59 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t60 = M_PI*_t38;
  const double _t61 = 0.8e1*_t60;
  const double _t62 = _t41*_t61;
  const double _t63 = _t62*nb;
  const double _t65 = _hc9[0]*_t64;
  const double _t70 = _hc8[0]*_t49*na*nb + _t54 - _t65*_t69;
  const double _t71 = (0.3e1 / 0.16e2)*_t40;
  const double _t72 = _t70*_t71;
  double _hc13[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_Q_k, _KMAX)(p, _t17*_t19, _hc13);
  const double _t73 = _hc11[0]*_t24 + _hc13[0]*_t25 - _t26*_t36 + _t37*(0.4e1*_hc7[0]*_t38 - _t43*na) + _t44*(-_t1*_t57 - _t26*_t47) + _t58*(0.6e1*_hc7[0]*_t59 - _t1*_t72 - _t63*na);
  const double _t74 = _t23*_t73;
  const double zk = _t74;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t76 = -_t10;
  const double _t77 = _t48*_t9;
  const double _t78 = _t76 + _t77;
  const double _t79 = -_t78;
  const double _t83 = (0.1e1 / 0.6e1)*_t6;
  const double _t87 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t88 = 0.8e1*_t87;
  const double _t91 = xc_powr(_t1, -10, 3);
  const double _t92 = _t6*_t91;
  const double _t93 = (0.2e1 / 0.3e1)*_t92;
  const double _t99 = xc_powr(0.2e1, 5, 6);
  const double _t100 = M_CBRT3;
  const double _t101 = _t100*_t99;
  const double _t102 = _t101*_t14;
  const double _t108 = (0.16e2 / 0.9e1)*_t26;
  const double _t109 = xc_powr(_t1, -7, 3);
  const double _t110 = _t102*_t109;
  const double _t118 = xc_powr(_t1, -4, 3);
  const double _t119 = (0.1e1 / 0.6e1)*_t118;
  const double _t124 = _t88*nb;
  const double _t127 = (0.2e1 / 0.15e2)*_t2;
  const double _t128 = _t93*nb;
  const double _t133 = _t119*_t6;
  const double _t144 = (M_CBRTPI * M_CBRTPI);
  const double _t148 = _t39*na;
  const double _t149 = 0.2e1*_t48;
  const double _t153 = _t144*_t3;
  const double _t161 = xc_powr(_t1, -7, 6);
  const double _t162 = (0.1e1 / 0.12e2)*_t161;
  const double _t175 = (0.4e1 / 0.9e1)*_t109;
  const double _t182 = (0.32e2 / 0.9e1)*_t28;
  const double _t193 = _t10 + _t77;
  const double _t194 = -_t193;
  const double _t198 = xc_powr(nb, -4, 3);
  const double _t199 = _t198*_t83;
  const double _t209 = 0.2e1*na;
  const double _t75 = (0.1e1 / 0.4e1)*_hc2[0];
  const double _t80 = _hc1[2]*_t79;
  const double _t81 = (0.1e1 / 0.4e1)*_hc4[0];
  const double _t82 = _hc3[2]*_t78;
  const double _t84 = _hc2[1]/xc_powr(na, 4, 3);
  const double _t85 = _t83*_t84;
  const double _t86 = _t52*_t85;
  const double _t89 = _hc5[0]*na;
  const double _t90 = _t88*_t89;
  const double _t94 = _hc5[1]*na;
  const double _t95 = _t93*_t94;
  const double _t96 = -_t90*nb - _t95*nb;
  const double _t97 = _t51 + _t75*_t80 + _t81*_t82 - _t86 + _t96;
  const double _t98 = _t56*_t97;
  const double _t103 = xc_powi((_hc0[0]), 7);
  const double _t107 = _hc6[0]*_t48;
  const double _t111 = _hc6[1]*_t110;
  const double _t112 = _hc6[0]*_t110;
  const double _t113 = xc_powi((_hc0[0]), 5);
  const double _t117 = _hc7[2]*_t6;
  const double _t120 = -_t117*_t119;
  const double _t121 = _hc7[1]*_t79 + _t120;
  const double _t122 = _hc9[1]*_t64;
  const double _t123 = _t122*_t69;
  const double _t125 = _hc8[0]*na;
  const double _t126 = _t65*_t67;
  const double _t129 = _hc8[1]*na;
  const double _t130 = _t124*_t125 + _t126*_t127 + _t128*_t129;
  const double _t131 = (0.1e1 / 0.4e1)*_hc1[2]*_hc2[0]*_t79 + (0.1e1 / 0.4e1)*_hc3[2]*_hc4[0]*_t78 + 0.4e1*_hc8[0]*_t48*nb - _t123*_t79 - _t130 - _t86;
  const double _t132 = _t131*_t71;
  const double _t137 = _t61*na;
  const double _t139 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t140 = 0.4e1*_hc7[0];
  const double _t146 = 0.4e1*_t38;
  const double _t150 = _hc10[0]*_t40;
  const double _t151 = _t149*_t150;
  const double _t152 = _t151*na;
  const double _t156 = _hc10[0]*_t109;
  const double _t160 = -_hc11[2]*_t133;
  const double _t163 = _t162*_t17;
  const double _t164 = ((_hc12[0]) * (_hc12[0]));
  const double _t165 = (0.1e1 / _t164);
  const double _t166 = _t16*_t165;
  const double _t167 = _hc12[1]*_t166;
  const double _t168 = _t167*_t19;
  const double _t169 = -_t163 - _t168*_t79;
  const double _t172 = _hc12[1]*_t164;
  const double _t173 = 0.3e1*_t172;
  const double _t174 = _t107*_t35;
  const double _t176 = _hc6[1]*_t102;
  const double _t177 = _t28*_t29;
  const double _t178 = _t176*_t177;
  const double _t179 = _t175*_t178;
  const double _t187 = _t21/xc_powi(_t22, 5);
  const double _t195 = _hc1[2]*_t75;
  const double _t196 = _hc3[2]*_t81;
  const double _t197 = _hc4[1]*_t53;
  const double _t200 = _t197*_t199;
  const double _t201 = _t193*_t196 + _t194*_t195 - _t200 + _t50*na + _t96;
  const double _t202 = _t201*_t56;
  const double _t203 = _hc7[1]*_t194 + _t120;
  const double _t204 = (0.1e1 / 0.4e1)*_hc1[2]*_hc2[0]*_t194 + (0.1e1 / 0.4e1)*_hc3[2]*_hc4[0]*_t193 + 0.4e1*_hc8[0]*_t48*na - _t123*_t194 - _t130 - _t200;
  const double _t205 = _t204*_t71;
  const double _t208 = _t137*nb;
  const double _t212 = -_t163 - _t168*_t194;
  double _hc14[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pmgb_b0_k, _KMAX)(p, 0, _hc14);
  double _hc15[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pmgb_gc0_k, _KMAX)(p, 0, _t11, _hc15);
  double _hc16[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pmgb_gc0_k, _KMAX)(p, _t8, 0, _hc16);
  const double _t104 = _hc14[1]*_t103;
  const double _t105 = _t104*_t2;
  const double _t106 = (0.1e1 / 0.5e1)*_t105;
  const double _t114 = _hc14[1]*_t113;
  const double _t115 = _t114*_t26;
  const double _t116 = _t102*_t106*_t55 + _t107*_t26*_t46 + _t108*_t111*_t38 + (0.32e2 / 0.3e1)*_t112*_t115 - _t57;
  const double _t134 = -_hc16[2]*_t133;
  const double _t135 = _hc15[1]*_t79 + _t134;
  const double _t136 = _t10*_t135;
  const double _t138 = _t136*_t137;
  const double _t141 = _hc14[1]*_t118;
  const double _t142 = _t141*_t6;
  const double _t143 = _t140*_t142;
  const double _t145 = -0.8e1*_hc10[0]*_hc14[1]*_t109*_t113*_t144*_t3*na*nb - 0.8e1*M_PI*_hc10[0]*_t38*_t48*na*nb - 0.1e1 / 0.4e1*_hc14[1]*_t103*_t144*_t2*_t3*_t70 + _t139*_t143 + _t72;
  const double _t147 = _t136*_t40;
  const double _t154 = _hc14[1]*_t153;
  const double _t155 = _t103*_t154;
  const double _t157 = _t155*_t156;
  const double _t158 = (0.8e1 / 0.3e1)*_t157;
  const double _t159 = -_t113*_t143 + _t152*nb + _t158*_t26;
  const double _t170 = _hc13[1]*_t25;
  const double _t171 = _hc13[0]*_t79;
  const double _t180 = _t104*_t110;
  const double _t181 = _hc6[0]*_t180;
  const double _t183 = _t181*_t182;
  const double _t184 = _t174*_t26 + _t179*_t26 + _t183*_t26;
  const double _t185 = _t169*_t170 + _t171*_t173 + _t184 + _t24*(_hc11[1]*_t79 + _t160) - _t36*nb + _t37*(_t121*_t146 - _t147*_t148 + _t159 - _t43) + _t44*(-_t1*_t98 + _t116 - _t47*nb) + _t58*(-_t1*_t132 + 0.6e1*_t121*_t59 - _t138*nb - _t145 - _t63);
  const double _t186 = _t185*_t23;
  const double _t188 = _t187*_t73;
  const double _t189 = _hc0[0]*_t188;
  const double _t190 = _hc14[1]*_t2*_t6;
  const double _t191 = (0.4e1 / 0.3e1)*_t190;
  const double _t192 = _t189*_t191 + _t74;
  const double _t206 = _hc15[1]*_t194 + _t134;
  const double _t207 = _t10*_t206;
  const double _t210 = _t207*_t40;
  const double _t211 = _t210*_t39;
  const double _t213 = _hc13[0]*_t173;
  const double _t214 = _t170*_t212 + _t184 + _t194*_t213 + _t24*(_hc11[1]*_t194 + _t160) - _t36*na + _t37*(_t146*_t203 + _t159 - _t209*_t42 - _t211*na) + _t44*(-_t1*_t202 + _t116 - _t47*na) + _t58*(-_t1*_t205 - _t145 + 0.6e1*_t203*_t59 - _t207*_t208 - _t62*na);
  const double _t215 = _t214*_t23;
  const double dF_dna = _t1*_t186 + _t192;
  const double dF_dnb = _t1*_t215 + _t192;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t217 = 0.16e2*_t87;
  const double _t219 = (0.4e1 / 0.3e1)*_t92;
  const double _t221 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t222 = 0.24e2*_t221;
  const double _t224 = xc_powr(_t1, -14, 3);
  const double _t225 = xc_powr(0.6e1, 2, 3);
  const double _t226 = (0.1e1 / _t144);
  const double _t227 = _t225*_t226;
  const double _t228 = _t224*_t227;
  const double _t230 = (0.1e1 / 0.9e1)*na;
  const double _t232 = xc_powr(_t1, -13, 3);
  const double _t233 = _t232*_t6;
  const double _t234 = (0.32e2 / 0.9e1)*_t233;
  const double _t237 = 0.2e1*_t87;
  const double _t238 = _t237*_t9;
  const double _t239 = -_t149 + _t238;
  const double _t240 = (_t79 * _t79);
  const double _t242 = -_t239;
  const double _t243 = (_t78 * _t78);
  const double _t245 = xc_powr(na, -8, 3);
  const double _t246 = (0.1e1 / 0.36e2)*_t227;
  const double _t248 = (0.2e1 / 0.9e1)*_t6;
  const double _t249 = xc_powr(na, -7, 3);
  const double _t258 = xc_powr(0.2e1, 1, 6);
  const double _t259 = _t15*_t258*_t64;
  const double _t266 = xc_powr(_t1, -11, 3);
  const double _t267 = _t259*_t266;
  const double _t280 = (0.160e3 / 0.9e1)*_t26;
  const double _t285 = (0.2e1 / 0.9e1)*_t109;
  const double _t294 = _t68*xc_powr(0.3e1*na + 0.3e1*nb, 2, 3);
  const double _t299 = (0.4e1 / 0.15e2)*_t2;
  const double _t300 = (0.2e1 / 0.45e2)*_t118;
  const double _t308 = xc_powr(_t1, -8, 3);
  const double _t309 = (0.1e1 / 0.36e2)*_t308;
  const double _t310 = _t285*_t6;
  const double _t318 = _t217*na;
  const double _t324 = _t225*_t4;
  const double _t327 = (0.20e2 / 0.3e1)*_t26;
  const double _t332 = (0.80e2 / 0.3e1)*_t26;
  const double _t335 = 0.4e1*nb;
  const double _t353 = _t109*_t6;
  const double _t360 = (0.28e2 / 0.9e1)*_t26;
  const double _t368 = (0.1e1 / 0.6e1)*_t161;
  const double _t370 = xc_powr(_t1, -13, 6);
  const double _t373 = _t16*_t18;
  const double _t385 = 0.3e1*_t239;
  const double _t400 = (0.64e2 / 0.9e1)*_t28;
  const double _t429 = (0.1e1 / 0.2e1)*_t87;
  const double _t474 = _t64*_t69;
  const double _t476 = _t194*_t79;
  const double _t490 = xc_powr(_t1, -19, 6);
  const double _t502 = 0.6e1*_t87;
  const double _t503 = _t502*_t9;
  const double _t509 = _t149 + _t238;
  const double _t510 = (_t194 * _t194);
  const double _t511 = -_t509;
  const double _t512 = (_t193 * _t193);
  const double _t513 = xc_powr(nb, -8, 3);
  const double _t515 = xc_powr(nb, -7, 3);
  const double _t529 = 0.4e1*na;
  const double _t541 = 0.3e1*_t509;
  const double _t216 = (0.3e1 / 0.10e2)*_t33;
  const double _t218 = _hc5[0]*_t217;
  const double _t220 = _hc5[1]*_t219;
  const double _t223 = _t222*_t89;
  const double _t229 = _hc5[2]*_t228;
  const double _t231 = _t229*_t230;
  const double _t235 = _t234*_t94;
  const double _t236 = _t223*nb + _t231*nb + _t235*nb;
  const double _t241 = _hc1[5]*_t75;
  const double _t244 = _hc3[5]*_t81;
  const double _t247 = _hc2[2]*_t52;
  const double _t250 = _hc2[1]*_t249;
  const double _t251 = _t6*_t84;
  const double _t252 = (0.1e1 / 0.12e2)*_t251;
  const double _t253 = _t195*_t239 + _t196*_t242 + _t240*_t241 + _t243*_t244 + _t245*_t246*_t247 + _t248*_t250*_t52 - _t252*_t80;
  const double _t254 = -_t218*nb - _t220*nb + _t236 + _t253;
  const double _t255 = _t254*_t56;
  const double _t260 = _t259*_t38;
  const double _t262 = (0.7e1 / 0.15e2)*_t55;
  const double _t263 = _hc6[0]*_t45;
  const double _t264 = (0.64e2 / 0.3e1)*_t263;
  const double _t265 = _t264*_t87;
  const double _t268 = _hc6[2]*_t267;
  const double _t269 = _t268*_t38;
  const double _t270 = (0.16e2 / 0.27e2)*_t269;
  const double _t271 = _t176*_t38;
  const double _t272 = _t271*_t91;
  const double _t273 = (0.160e3 / 0.27e2)*_t272;
  const double _t274 = _hc6[1]*_t267;
  const double _t286 = _t117*_t285;
  const double _t287 = -_hc7[5]*_t133;
  const double _t288 = _hc7[4]*_t79 + _t287;
  const double _t289 = -_hc7[4]*_t133;
  const double _t290 = _hc7[3]*_t79 + _t289;
  const double _t291 = _hc7[1]*_t239 - _t133*_t288 + _t286 + _t290*_t79;
  const double _t292 = (0.3e1 / 0.8e1)*_t40;
  const double _t293 = _hc8[0]*_t217;
  const double _t295 = _hc9[3]*_t240;
  const double _t296 = _hc8[1]*_t219;
  const double _t297 = _t122*_t67;
  const double _t298 = _t297*_t79;
  const double _t301 = _hc8[2]*_t228;
  const double _t302 = _t125*_t222*nb + _t126*_t300 + _t129*_t234*nb + _t230*_t301*nb;
  const double _t303 = -_t123*_t239 + _t253 - _t293*nb - _t294*_t295 - _t296*nb - _t298*_t299 + _t302;
  const double _t304 = _t303*_t71;
  const double _t305 = 0.16e2*_t60;
  const double _t316 = 0.8e1*_t121;
  const double _t317 = _hc10[0]*_t60;
  const double _t319 = _t317*_t318;
  const double _t320 = _t319*nb;
  const double _t321 = _t225*_t38*_t4;
  const double _t322 = (0.7e1 / 0.24e2)*_t321;
  const double _t330 = _hc10[0]*_t91;
  const double _t336 = _t150*_t49;
  const double _t339 = _t40*_t49;
  const double _t346 = _t150*_t87;
  const double _t347 = _t335*_t346;
  const double _t352 = (0.16e2 / 0.3e1)*_hc7[0];
  const double _t362 = _hc11[2]*_t310;
  const double _t363 = -_hc11[5]*_t133;
  const double _t364 = _hc11[4]*_t79 + _t363;
  const double _t365 = -_hc11[4]*_t133;
  const double _t366 = _hc11[3]*_t79 + _t365;
  const double _t367 = _t167*_t79;
  const double _t369 = _t367*_t368;
  const double _t371 = _t17*_t370;
  const double _t372 = (0.7e1 / 0.72e2)*_t371;
  const double _t374 = ((_hc12[1]) * (_hc12[1]));
  const double _t375 = (0.1e1 / _t25);
  const double _t376 = _t374*_t375;
  const double _t377 = _t373*_t376;
  const double _t378 = _t240*_t377;
  const double _t379 = _hc12[3]*_t240;
  const double _t380 = _t166*_t19;
  const double _t381 = _t372 + _t378 - _t379*_t380;
  const double _t382 = -_t168*_t239 + _t369 + _t381;
  const double _t383 = (_t169 * _t169);
  const double _t387 = 0.3e1*_t164;
  const double _t391 = _hc12[0]*_t374;
  const double _t395 = _t169*_t79;
  const double _t396 = (0.16e2 / 0.3e1)*_t34;
  const double _t397 = _t107*_t396;
  const double _t398 = (0.8e1 / 0.9e1)*_t177;
  const double _t399 = _t111*_t398;
  const double _t402 = _t396*_t87;
  const double _t403 = _hc6[0]*_t402;
  const double _t404 = _t178*_t91;
  const double _t405 = (0.40e2 / 0.27e2)*_t404;
  const double _t406 = _t177*_t26;
  const double _t407 = _hc6[0]*_t28;
  const double _t418 = _hc0[0]*_t187;
  const double _t424 = _t58/xc_powi(_t22, 6);
  const double _t430 = _hc1[2]*_hc2[0];
  const double _t431 = _t429*_t430;
  const double _t432 = _hc3[2]*_hc4[0];
  const double _t433 = _t429*_t432;
  const double _t434 = _t433*_t9;
  const double _t435 = _t241*_t79;
  const double _t436 = _t244*_t78;
  const double _t437 = _hc1[2]*_t194;
  const double _t438 = (0.1e1 / 0.24e2)*_t251;
  const double _t439 = _t437*_t438;
  const double _t440 = _hc4[1]*_t6;
  const double _t441 = _t198*_t440;
  const double _t442 = (0.1e1 / 0.24e2)*_t441;
  const double _t443 = _t442*_t82;
  const double _t444 = -_hc5[0]*_t124 - _hc5[1]*_t128 + _t193*_t436 + _t194*_t435 + _t236 + _t431*_t9 - _t434 - _t439 - _t443 + _t50 - _t90 - _t95;
  const double _t445 = _t1*_t56;
  const double _t446 = _hc10[0]*_t48;
  const double _t447 = _t61*nb;
  const double _t450 = _hc7[0]*_t20;
  const double _t464 = _hc7[3]*_t194 + _t289;
  const double _t465 = _hc7[4]*_t194 + _t287;
  const double _t466 = -_t133*_t465 + _t286;
  const double _t467 = _hc7[1]*_t238 + _t464*_t79 + _t466;
  const double _t468 = 0.6e1*_t59;
  const double _t471 = (0.2e1 / 0.5e1)*_t297;
  const double _t472 = _t109*_t471;
  const double _t473 = _t194*_t297;
  const double _t475 = _hc9[3]*_t474;
  const double _t477 = (0.1e1 / 0.2e1)*_hc1[2]*_hc2[0]*_t87*_t9 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t194*_t79 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t193*_t78 - _hc8[0]*_t124 + 0.24e2*_hc8[0]*_t221*na*nb + 0.4e1*_hc8[0]*_t48 - _hc8[1]*_t128 + (0.32e2 / 0.9e1)*_hc8[1]*_t232*_t3*_t5*na*nb + (0.1e1 / 0.9e1)*_hc8[2]*_t224*_t225*_t226*na*nb + (0.2e1 / 0.45e2)*_hc9[0]*_t118*_t64*_t67 - _t125*_t88 - _t127*_t298 - _t127*_t473 - _t129*_t93 - _t434 - _t439 - _t443 - _t472*_t9 - _t475*_t476;
  const double _t478 = _t1*_t71;
  const double _t481 = _t40*nb;
  const double _t482 = _t149*_t481;
  const double _t484 = _hc11[3]*_t194 + _t365;
  const double _t485 = _hc11[4]*_t194 + _t363;
  const double _t486 = -_t133*_t485 + _t362;
  const double _t487 = _t167*_t194;
  const double _t488 = _t377*_t476;
  const double _t489 = _hc12[3]*_t380;
  const double _t491 = _t167*_t490;
  const double _t492 = _t491*_t9;
  const double _t493 = _t372 - _t492;
  const double _t494 = _t162*_t367 + _t162*_t487 - _t476*_t489 + _t488 + _t493;
  const double _t497 = _t212*_t79;
  const double _t504 = _hc6[0]*na;
  const double _t514 = _hc4[2]*_t53;
  const double _t516 = _hc3[2]*_t193;
  const double _t517 = (0.1e1 / 0.12e2)*_t441;
  const double _t518 = _t195*_t509 + _t196*_t511 + _t197*_t248*_t515 + _t241*_t510 + _t244*_t512 + _t246*_t513*_t514 - _t516*_t517;
  const double _t519 = -_t218*na - _t220*na + _t236 + _t518;
  const double _t520 = _t519*_t56;
  const double _t521 = _hc7[1]*_t509 + _t194*_t464 + _t466;
  const double _t522 = _hc9[3]*_t510;
  const double _t523 = -_t123*_t509 - _t293*na - _t294*_t522 - _t296*na - _t299*_t473 + _t302 + _t518;
  const double _t524 = _t523*_t71;
  const double _t528 = 0.8e1*_t203;
  const double _t532 = _t339*nb;
  const double _t535 = _t368*_t487;
  const double _t536 = _t377*_t510;
  const double _t537 = _hc12[3]*_t510;
  const double _t538 = _t372 - _t380*_t537 + _t536;
  const double _t539 = -_t168*_t509 + _t535 + _t538;
  const double _t540 = (_t212 * _t212);
  double _hc17[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pmgb_gc0_k, _KMAX)(p, 0, 0, _hc17);
  const double _t256 = ((_hc14[1]) * (_hc14[1]));
  const double _t257 = _t256/xc_powr(_t1, 5, 3);
  const double _t261 = _t257*_t260;
  const double _t275 = _t114*_t274;
  const double _t276 = _t256*_t266;
  const double _t277 = _t276*_t59;
  const double _t278 = _t259*_t277;
  const double _t279 = _hc6[0]*_t278;
  const double _t281 = _t102*_t114;
  const double _t282 = _hc6[0]*_t281;
  const double _t283 = _t282*_t91;
  const double _t284 = -0.2e1 / 0.15e2*_hc14[1]*_t100*_t103*_t118*_t14*_t55*_t99 + _t26*_t265 + _t26*_t270 + _t26*_t273 + (0.64e2 / 0.9e1)*_t26*_t275 + (0.320e3 / 0.9e1)*_t26*_t283 + _t261*_t262 + _t279*_t280;
  const double _t306 = _t136*_t305;
  const double _t307 = _hc16[5]*_t227;
  const double _t311 = _hc16[2]*_t310 + _t307*_t309;
  const double _t312 = _hc15[1]*_t239 + _hc17[3]*_t240 + _t311;
  const double _t313 = _t10*_t312;
  const double _t314 = _t137*_t313;
  const double _t315 = _t139*_t142;
  const double _t323 = _t257*_t322*_t70;
  const double _t325 = _t277*_t324;
  const double _t326 = _hc10[0]*_t325;
  const double _t328 = _t326*_t327;
  const double _t329 = _t113*_t154;
  const double _t331 = _t329*_t330;
  const double _t333 = _t331*_t332;
  const double _t334 = -0.16e2 / 0.3e1*_hc14[1]*_hc7[0]*_t109*_t139*_t3*_t5 - 0.1e1 / 0.6e1*_hc14[1]*_t103*_t118*_t144*_t3*_t70 - 0.2e1*_hc7[0]*_t20*_t225*_t226*_t256*_t308 + _t320 + _t323 + _t328 + _t333;
  const double _t337 = _t113*_t142;
  const double _t338 = _t313*_t40;
  const double _t340 = _t135*na;
  const double _t341 = _t339*_t340;
  const double _t342 = (0.16e2 / 0.3e1)*_t157;
  const double _t343 = _t109*_t155;
  const double _t344 = (0.16e2 / 0.3e1)*_t343;
  const double _t345 = _t340*_t344;
  const double _t348 = _t256*_t308;
  const double _t349 = _t227*_t348;
  const double _t350 = _t349*_t59;
  const double _t351 = (0.10e2 / 0.3e1)*_t350;
  const double _t354 = _hc14[1]*_t353;
  const double _t355 = _t113*_t354;
  const double _t356 = _t155*_t330;
  const double _t357 = (0.80e2 / 0.9e1)*_t356;
  const double _t358 = _t276*_t321;
  const double _t359 = _hc10[0]*_t358;
  const double _t361 = _hc7[0]*_t351 - _t26*_t357 - _t347*na + _t352*_t355 - _t359*_t360;
  const double _t384 = _hc13[2]*_t25;
  const double _t386 = _hc13[0]*_t172;
  const double _t388 = _hc12[3]*_hc13[0];
  const double _t389 = _t240*_t388;
  const double _t390 = 0.6e1*_hc13[0];
  const double _t392 = _t390*_t391;
  const double _t393 = 0.6e1*_hc13[1];
  const double _t394 = _t172*_t393;
  const double _t401 = _t181*_t400;
  const double _t408 = _t102*_t104*_t91;
  const double _t409 = _t407*_t408;
  const double _t410 = _t260*_t276;
  const double _t411 = _t407*_t410;
  const double _t412 = _t104*_t28;
  const double _t413 = _t274*_t412;
  const double _t414 = (0.64e2 / 0.27e2)*_t413;
  const double _t415 = -_t26*_t403 - _t26*_t405 - 0.320e3 / 0.27e2*_t26*_t409 - 0.224e3 / 0.27e2*_t26*_t411 - _t26*_t414 - 0.4e1 / 0.27e2*_t268*_t406;
  const double _t416 = _t170*_t382 + _t24*(_hc11[1]*_t239 - _t133*_t364 + _t362 + _t366*_t79) + _t240*_t392 + _t37*(_t146*_t291 - _t147*_t335 - _t148*_t338 - _t316*_t337 + _t336*nb + _t341*nb + _t342*nb + _t345*nb + _t361) + _t383*_t384 + _t385*_t386 + _t387*_t389 + _t394*_t395 + _t397*nb + _t399*nb + _t401*nb + _t415 + _t44*((0.64e2 / 0.3e1)*_hc14[1]*_hc6[0]*_t100*_t109*_t113*_t14*_t99*nb + (0.2e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t14*_t2*_t97*_t99 + (0.64e2 / 0.3e1)*_hc6[0]*_t30*_t31*_t38*_t48*nb + (0.32e2 / 0.9e1)*_hc6[1]*_t100*_t109*_t14*_t38*_t99*nb - _t1*_t255 - _t216*_t97 - _t284) + _t58*(0.16e2*_hc10[0]*_hc14[1]*_t109*_t113*_t144*_t3*nb + 0.16e2*M_PI*_hc10[0]*_t38*_t48*nb + (0.1e1 / 0.2e1)*_hc14[1]*_t103*_t131*_t144*_t2*_t3 + 0.16e2*_hc14[1]*_t109*_t113*_t135*_t144*_t3*na*nb - _t1*_t304 - _t131*_t292 + 0.16e2*M_PI*_t135*_t38*_t48*na*nb + 0.6e1*_t291*_t59 - _t306*nb - _t314*nb - _t315*_t316 - _t334);
  const double _t417 = _t23*_t416;
  const double _t419 = _t185*_t418;
  const double _t420 = (0.8e1 / 0.3e1)*_t190;
  const double _t421 = _t227*_t257;
  const double _t422 = (0.2e1 / 0.9e1)*_t188;
  const double _t423 = (0.8e1 / 0.9e1)*_t142;
  const double _t425 = _t424*_t73;
  const double _t426 = (0.20e2 / 0.9e1)*_t425;
  const double _t427 = _t20*_t421;
  const double _t428 = _t189*_t423 - _t421*_t422 + _t426*_t427;
  const double _t448 = _t139*_t354;
  const double _t449 = 0.8e1*_t156*_t329;
  const double _t451 = 0.2e1*_t349;
  const double _t452 = _t135*_t48;
  const double _t453 = _t206*_t48;
  const double _t454 = 0.4e1*_t315;
  const double _t455 = _t340*nb;
  const double _t456 = _t109*_t329;
  const double _t457 = 0.8e1*_t456;
  const double _t458 = _t155*_t70;
  const double _t459 = _t206*na;
  const double _t460 = _t459*nb;
  const double _t461 = _hc17[3]*_t194;
  const double _t462 = _hc15[1]*_t238 + _t311 + _t461*_t79;
  const double _t463 = _t10*_t462;
  const double _t469 = _t155*_t2;
  const double _t470 = (0.1e1 / 0.4e1)*_t469;
  const double _t479 = 0.4e1*_t337;
  const double _t480 = _t40*_t463;
  const double _t483 = (0.8e1 / 0.3e1)*_t343;
  const double _t495 = _t169*_t384;
  const double _t496 = _hc13[1]*_t173;
  const double _t498 = _t194*_t496;
  const double _t499 = _hc12[3]*_t171;
  const double _t500 = _t387*_t499;
  const double _t501 = _t392*_t79;
  const double _t505 = _t180*_t504;
  const double _t506 = _t169*_t498 + _t170*_t494 + _t174*na + _t174*nb + _t179*na + _t179*nb + _t182*_t505 + _t183*nb + _t194*_t500 + _t194*_t501 + _t212*_t495 + _t24*(_hc11[1]*_t238 + _t484*_t79 + _t486) - _t36 + _t37*(-_t121*_t479 + _t146*_t467 - _t147*_t209 - _t148*_t480 + _t151*nb + _t152 + _t158*na + _t158*nb - _t203*_t479 - _t211 + _t340*_t482 + _t361 - 0.2e1*_t42 + _t455*_t483 + _t459*_t482 + _t460*_t483) + _t386*_t503 + _t415 + _t44*((0.32e2 / 0.3e1)*_hc14[1]*_hc6[0]*_t100*_t109*_t113*_t14*_t99*na + (0.32e2 / 0.3e1)*_hc14[1]*_hc6[0]*_t100*_t109*_t113*_t14*_t99*nb + (0.1e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t14*_t2*_t201*_t99 + (0.1e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t14*_t2*_t97*_t99 + (0.32e2 / 0.3e1)*_hc6[0]*_t30*_t31*_t38*_t48*na + (0.32e2 / 0.3e1)*_hc6[0]*_t30*_t31*_t38*_t48*nb + (0.16e2 / 0.9e1)*_hc6[1]*_t100*_t109*_t14*_t38*_t99*na + (0.16e2 / 0.9e1)*_hc6[1]*_t100*_t109*_t14*_t38*_t99*nb - _t202 - _t284 - _t444*_t445 - _t47 - _t98) + _t496*_t497 + _t58*(_t119*_t458 - _t121*_t454 + _t131*_t470 - _t132 + _t137*_t446 - _t138 - _t203*_t454 + _t204*_t470 - _t205 - _t207*_t447 + _t208*_t452 + _t208*_t453 - _t208*_t463 - _t320 - _t323 - _t328 - _t333 + _t352*_t448 + _t446*_t447 + _t449*na + _t449*nb + _t450*_t451 + _t455*_t457 + _t457*_t460 + _t467*_t468 - _t477*_t478 - _t62);
  const double _t507 = _t23*_t506;
  const double _t508 = _t214*_t418;
  const double _t525 = _t207*_t305;
  const double _t526 = _hc15[1]*_t509 + _hc17[3]*_t510 + _t311;
  const double _t527 = _t10*_t526;
  const double _t530 = _t40*_t527;
  const double _t531 = _t39*_t530;
  const double _t533 = _t206*_t532;
  const double _t534 = _t344*_t459;
  const double _t542 = _t387*_t388;
  const double _t543 = _t194*_t394;
  const double _t544 = _t170*_t539 + _t212*_t543 + _t24*(_hc11[1]*_t509 + _t194*_t484 + _t486) + _t37*(_t146*_t521 - _t210*_t529 + _t336*na - _t337*_t528 + _t342*na + _t361 - _t531*na + _t533*na + _t534*nb) + _t384*_t540 + _t386*_t541 + _t392*_t510 + _t397*na + _t399*na + _t400*_t505 + _t415 + _t44*((0.64e2 / 0.3e1)*_hc14[1]*_hc6[0]*_t100*_t109*_t113*_t14*_t99*na + (0.2e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t14*_t2*_t201*_t99 + (0.64e2 / 0.3e1)*_hc6[0]*_t30*_t31*_t38*_t48*na + (0.32e2 / 0.9e1)*_hc6[1]*_t100*_t109*_t14*_t38*_t99*na - _t1*_t520 - _t201*_t216 - _t284) + _t510*_t542 + _t58*(0.16e2*_hc10[0]*_hc14[1]*_t109*_t113*_t144*_t3*na + 0.16e2*M_PI*_hc10[0]*_t38*_t48*na + (0.1e1 / 0.2e1)*_hc14[1]*_t103*_t144*_t2*_t204*_t3 + 0.16e2*_hc14[1]*_t109*_t113*_t144*_t206*_t3*na*nb - _t1*_t524 - _t204*_t292 + 0.16e2*M_PI*_t206*_t38*_t48*na*nb - _t208*_t527 - _t315*_t528 - _t334 + 0.6e1*_t521*_t59 - _t525*na);
  const double _t545 = _t23*_t544;
  const double d2F_dna2 = _t1*_t417 + 0.2e1*_t186 + _t419*_t420 + _t428;
  const double d2F_dna_dnb = _t1*_t507 + _t186 + _t191*_t419 + _t191*_t508 + _t215 + _t428;
  const double d2F_dnb2 = _t1*_t545 + 0.2e1*_t215 + _t420*_t508 + _t428;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t548 = _t221*_t9;
  const double _t549 = 0.6e1*_t548;
  const double _t550 = -_t502 + _t549;
  const double _t551 = -_t550;
  const double _t552 = (_t79 * _t79 * _t79);
  const double _t554 = (_t78 * _t78 * _t78);
  const double _t557 = (0.1e1 / (na * na * na * na));
  const double _t558 = (0.1e1 / M_PI);
  const double _t559 = (0.1e1 / 0.36e2)*_t558;
  const double _t560 = _t557*_t559;
  const double _t562 = 0.4e1*_t87*_t9;
  const double _t563 = -_t49 + _t562;
  const double _t564 = -_t563;
  const double _t566 = xc_powr(na, -10, 3);
  const double _t567 = (0.14e2 / 0.27e2)*_t6;
  const double _t568 = _t566*_t567;
  const double _t570 = xc_powr(na, -11, 3);
  const double _t571 = (0.1e1 / 0.9e1)*_t227;
  const double _t572 = _t570*_t571;
  const double _t583 = (0.1e1 / 0.48e2)*_t227;
  const double _t584 = _t245*_t583;
  const double _t585 = xc_powi(_t1, -5);
  const double _t586 = 0.96e2*_t585;
  const double _t588 = xc_powi(_t1, -6);
  const double _t589 = _t588*nb;
  const double _t593 = xc_powr(_t1, -16, 3);
  const double _t594 = _t593*_t6;
  const double _t595 = (0.524e3 / 0.27e2)*_t594;
  const double _t597 = xc_powr(_t1, -17, 3);
  const double _t598 = _t227*_t597;
  const double _t600 = (0.10e2 / 0.9e1)*_t26;
  const double _t606 = (0.160e3 / 0.9e1)*_t91;
  const double _t615 = (0.320e3 / 0.3e1)*_t91;
  const double _t620 = (0.1e1 / _t31);
  const double _t621 = _t30*_t620;
  const double _t626 = 0.64e2*_t26;
  const double _t632 = _t26*_t585;
  const double _t633 = _t621*_t632;
  const double _t640 = _t224*_t259;
  const double _t642 = _t232*_t26;
  const double _t644 = (0.14e2 / 0.27e2)*_t91;
  const double _t648 = 0.2e1*_t239;
  const double _t663 = (0.2e1 / 0.5e1)*_t2;
  const double _t664 = _t64*_t67;
  const double _t669 = (0.8e1 / 0.135e3)*_t109;
  const double _t689 = (0.2e1 / 0.27e2)*_t266;
  const double _t691 = _t6*_t644;
  const double _t695 = _t10*nb;
  const double _t717 = 0.6e1*nb;
  const double _t718 = 0.12e2*_t87;
  const double _t740 = _t175*_t6;
  const double _t759 = 0.3e1*_t373;
  const double _t760 = _t16*_t161;
  const double _t768 = (0.1e1 / 0.3e1)*_t161;
  const double _t774 = 0.3e1*_t551;
  const double _t783 = -_t48*_t9;
  const double _t784 = _t10 + _t783;
  const double _t797 = (0.40e2 / 0.9e1)*nb;
  const double _t808 = _t585*_t621;
  const double _t843 = 0.48e2*_t221;
  const double _t844 = _t549 - 0.2e1*_t87;
  const double _t845 = -_t844;
  const double _t847 = _t76 + _t783;
  const double _t848 = _t240*_t847;
  const double _t852 = _t79*_t87;
  const double _t858 = (0.2e1 / 0.9e1)*nb;
  const double _t860 = (0.64e2 / 0.9e1)*_t233;
  const double _t868 = (0.1e1 / 0.144e3)*_t227;
  const double _t869 = _t245*_t868;
  const double _t870 = _t87*_t9;
  const double _t885 = (0.4e1 / 0.15e2)*_t118;
  const double _t951 = (0.16e2 / 0.3e1)*nb;
  const double _t955 = (0.28e2 / 0.9e1)*nb;
  const double _t958 = 0.12e2*_t221;
  const double _t968 = (0.196e3 / 0.9e1)*_t224;
  const double _t978 = xc_powr(_t1, -25, 6);
  const double _t981 = _t194*_t239;
  const double _t983 = _t79*_t9;
  const double _t1033 = (0.448e3 / 0.27e2)*nb;
  const double _t1048 = (0.1e1 / 0.9e1)*nb;
  const double _t1049 = (0.2e1 / 0.9e1)*na;
  const double _t1050 = (0.3e1 / 0.2e1)*_t548;
  const double _t1051 = _t510*_t784;
  const double _t1057 = (0.1e1 / 0.18e2)*_t515;
  const double _t1060 = _t193*_t78;
  const double _t1073 = (0.2e1 / 0.3e1)*_t9;
  const double _t1075 = _t194*_t9;
  const double _t1103 = 0.18e2*_t548;
  const double _t1112 = _t718*_t9;
  const double _t1114 = _t194*_t870;
  const double _t1118 = _t502 + _t549;
  const double _t1119 = -_t1118;
  const double _t1120 = (_t194 * _t194 * _t194);
  const double _t1121 = (_t193 * _t193 * _t193);
  const double _t1123 = (0.1e1 / (nb * nb * nb * nb));
  const double _t1124 = _t1123*_t559;
  const double _t1126 = _t49 + _t562;
  const double _t1127 = -_t1126;
  const double _t1128 = xc_powr(nb, -10, 3);
  const double _t1129 = _t1128*_t567;
  const double _t1131 = xc_powr(nb, -11, 3);
  const double _t1132 = _t1131*_t571;
  const double _t1142 = 0.2e1*_t509;
  const double _t1144 = _t1126*_t194;
  const double _t1151 = 0.6e1*na;
  const double _t1159 = _t194*_t509;
  const double _t1165 = 0.3e1*_t1119;
  const double _t1172 = (0.40e2 / 0.9e1)*na;
  const double _t546 = (0.9e1 / 0.20e2)*_t33;
  const double _t547 = 0.72e2*_hc5[0]*_t221;
  const double _t553 = _hc1[9]*_t75;
  const double _t555 = _hc3[9]*_t81;
  const double _t556 = _hc2[3]*_t52;
  const double _t561 = _t556*_t560;
  const double _t565 = _hc2[1]*_t52;
  const double _t569 = _t565*_t568;
  const double _t573 = _t247*_t572;
  const double _t574 = (0.1e1 / 0.3e1)*_hc5[2]*_t228;
  const double _t575 = (0.32e2 / 0.3e1)*_hc5[1]*_t233;
  const double _t576 = (0.1e1 / 0.8e1)*_t251;
  const double _t577 = _hc1[2]*_t239;
  const double _t578 = _t576*_t577;
  const double _t579 = _hc1[5]*_t240;
  const double _t580 = _t576*_t579;
  const double _t581 = _t250*_t83;
  const double _t582 = _hc2[2]*_t80;
  const double _t587 = _t586*_t89;
  const double _t590 = _hc5[3]*_t558;
  const double _t591 = (0.1e1 / 0.9e1)*_t590;
  const double _t592 = _t589*_t591;
  const double _t596 = _t595*_t94;
  const double _t599 = _hc5[2]*_t598;
  const double _t601 = -_t587*nb - _t592*na - _t596*nb - _t599*_t600;
  const double _t602 = _t195*_t551 + _t196*_t550 + _t239*_t435 + _t242*_t436 + _t435*_t563 + _t436*_t564 + _t547*nb + _t552*_t553 + _t554*_t555 - _t561 - _t569 - _t573 + _t574*nb + _t575*nb - _t578 - _t580 + _t581*_t80 + _t582*_t584 + _t601;
  const double _t603 = _t56*_t602;
  const double _t604 = _t263*_t87;
  const double _t605 = 0.64e2*_t604;
  const double _t607 = _t271*_t606;
  const double _t608 = (0.16e2 / 0.9e1)*_t268*_t38;
  const double _t610 = _t102*_t97;
  const double _t613 = _t102*_t254;
  const double _t622 = _t55*_t621;
  const double _t628 = _hc6[3]*_t621;
  const double _t629 = _t585*_t628;
  const double _t630 = (0.8e1 / 0.27e2)*_t629;
  const double _t631 = _t26*_t38;
  const double _t637 = _hc6[2]*_t224;
  const double _t639 = _hc6[0]*_t633;
  const double _t641 = _hc6[1]*_t640;
  const double _t645 = _t117*_t644;
  const double _t646 = -_t645;
  const double _t647 = _t288*_t6;
  const double _t649 = _hc7[5]*_t310;
  const double _t650 = -_hc7[9]*_t133;
  const double _t651 = _hc7[8]*_t79 + _t650;
  const double _t652 = -_hc7[8]*_t133;
  const double _t653 = _hc7[7]*_t79 + _t652;
  const double _t654 = _hc7[4]*_t239 - _t133*_t651 + _t649 + _t653*_t79;
  const double _t655 = _hc7[4]*_t310;
  const double _t656 = -_hc7[7]*_t133;
  const double _t657 = _hc7[6]*_t79 + _t656;
  const double _t658 = _hc7[3]*_t239 - _t133*_t653 + _t655 + _t657*_t79;
  const double _t659 = _hc7[1]*_t551 - _t133*_t654 + _t175*_t647 + _t290*_t648 + _t646 + _t658*_t79;
  const double _t660 = (0.9e1 / 0.16e2)*_t40;
  const double _t661 = _hc9[6]*_t294;
  const double _t662 = _t2*_t471;
  const double _t665 = _t295*_t664;
  const double _t666 = _t475*_t79;
  const double _t667 = _t125*_t586;
  const double _t668 = _t667*nb;
  const double _t670 = _t126*_t669;
  const double _t671 = _hc8[3]*_t558;
  const double _t672 = (0.1e1 / 0.9e1)*_t589*_t671;
  const double _t673 = _t672*na;
  const double _t674 = _hc8[2]*_t598;
  const double _t675 = _t600*_t674;
  const double _t676 = _t129*_t595;
  const double _t677 = _t676*nb;
  const double _t678 = _t668 + _t670 + _t673 + _t675 + _t677;
  const double _t679 = (0.1e1 / 0.4e1)*_hc1[2]*_hc2[0]*_t551 + (0.1e1 / 0.6e1)*_hc1[2]*_hc2[1]*_t249*_t3*_t5*_t79 + (0.1e1 / 0.48e2)*_hc1[2]*_hc2[2]*_t225*_t226*_t245*_t79 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t239*_t79 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t563*_t79 + (0.1e1 / 0.4e1)*_hc1[9]*_hc2[0]*_t552 + (0.1e1 / 0.4e1)*_hc3[2]*_hc4[0]*_t550 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t242*_t78 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t564*_t78 + (0.1e1 / 0.4e1)*_hc3[9]*_hc4[0]*_t554 + 0.72e2*_hc8[0]*_t221*nb + (0.32e2 / 0.3e1)*_hc8[1]*_t232*_t3*_t5*nb + (0.1e1 / 0.3e1)*_hc8[2]*_t224*_t225*_t226*nb + (0.2e1 / 0.15e2)*_hc9[1]*_t118*_t64*_t67*_t79 - _t123*_t551 - _t239*_t662 - _t239*_t666 - _t552*_t661 - _t561 - _t563*_t666 - _t569 - _t573 - _t578 - _t580 - _t663*_t665 - _t678;
  const double _t680 = _t679*_t71;
  const double _t681 = 0.24e2*_t60;
  const double _t683 = 0.48e2*_t60;
  const double _t684 = _hc10[0]*_t87;
  const double _t685 = _t683*_t684;
  const double _t697 = 0.12e2*_t291;
  const double _t698 = _t683*_t87;
  const double _t715 = (0.112e3 / 0.9e1)*_hc7[0];
  const double _t719 = _t150*_t718;
  const double _t731 = (0.40e2 / 0.3e1)*_hc7[0];
  const double _t738 = _hc11[2]*_t691;
  const double _t739 = -_t738;
  const double _t741 = _hc11[5]*_t310;
  const double _t742 = -_hc11[9]*_t133;
  const double _t743 = _hc11[8]*_t79 + _t742;
  const double _t744 = -_hc11[8]*_t133;
  const double _t745 = _hc11[7]*_t79 + _t744;
  const double _t746 = _hc11[4]*_t239 - _t133*_t743 + _t741 + _t745*_t79;
  const double _t747 = _hc11[4]*_t310;
  const double _t748 = -_hc11[7]*_t133;
  const double _t749 = _hc11[6]*_t79 + _t748;
  const double _t750 = _hc11[3]*_t239 - _t133*_t745 + _t747 + _t749*_t79;
  const double _t751 = _t17*_t490;
  const double _t752 = (0.91e2 / 0.432e3)*_t751;
  const double _t753 = _t367*_t370;
  const double _t754 = _hc12[6]*_t552;
  const double _t755 = (0.1e1 / ((_hc12[0]) * (_hc12[0]) * (_hc12[0]) * (_hc12[0])));
  const double _t756 = ((_hc12[1]) * (_hc12[1]) * (_hc12[1]));
  const double _t757 = _t552*_t756;
  const double _t758 = _t755*_t757;
  const double _t761 = _t376*_t760;
  const double _t762 = _t240*_t761;
  const double _t763 = _t489*_t79;
  const double _t764 = 0.3e1*_hc12[1]*_hc12[3]*_t12*_t13*_t15*_t18*_t375*_t552*p->cam_omega + (0.1e1 / 0.4e1)*_hc12[1]*_t12*_t13*_t15*_t161*_t165*_t239*p->cam_omega + (0.1e1 / 0.4e1)*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t240*p->cam_omega + _t12*_t13*_t15*_t18*_t239*_t374*_t375*_t79*p->cam_omega + _t12*_t13*_t15*_t18*_t374*_t375*_t563*_t79*p->cam_omega - _t168*_t551 - _t239*_t763 - _t380*_t754 - _t563*_t763 - _t752 - 0.7e1 / 0.24e2*_t753 - _t758*_t759 - 0.1e1 / 0.2e1*_t762;
  const double _t765 = (_t169 * _t169 * _t169);
  const double _t767 = _t167*_t18;
  const double _t769 = (0.7e1 / 0.36e2)*_t371;
  const double _t770 = _t166*_t18;
  const double _t771 = _t379*_t770;
  const double _t772 = 0.2e1*_t378 + _t769 - _t771;
  const double _t773 = -_t239*_t767 + _t367*_t768 + _t772;
  const double _t776 = _t164*_t385;
  const double _t778 = 0.9e1*_t172;
  const double _t779 = _t382*_t778;
  const double _t781 = _t239*_t778;
  const double _t785 = _t778*_t784;
  const double _t786 = -_t163 - _t168*_t784;
  const double _t788 = 0.9e1*_t164;
  const double _t790 = 0.18e2*_hc12[0];
  const double _t791 = _hc12[1]*_t790;
  const double _t793 = _t240*_t391;
  const double _t795 = _hc6[0]*_t34;
  const double _t796 = _t217*_t795;
  const double _t798 = _t268*nb;
  const double _t799 = (0.4e1 / 0.9e1)*_t177;
  const double _t800 = _hc6[0]*nb;
  const double _t801 = _t28*_t800;
  const double _t806 = _t221*_t795;
  const double _t807 = _t177*_t629;
  const double _t809 = _hc6[2]*_t808;
  const double _t810 = _t259*_t637;
  const double _t811 = _t177*_t810;
  const double _t816 = _t224*_t260;
  const double _t818 = _t26*_t407;
  const double _t829 = (0.20e2 / 0.3e1)*_t20;
  const double _t833 = (0.20e2 / 0.3e1)*_t424;
  const double _t835 = _t37/xc_powi(_t22, 7);
  const double _t836 = (0.80e2 / 0.3e1)*_t835;
  const double _t842 = _hc5[0]*nb;
  const double _t846 = _t194*_t241;
  const double _t849 = _t193*_t244;
  const double _t850 = _t243*_t555;
  const double _t851 = _hc1[5]*_hc2[0];
  const double _t853 = _t851*_t852;
  const double _t854 = _hc3[5]*_hc4[0];
  const double _t855 = _t854*_t87;
  const double _t856 = _t78*_t855;
  const double _t857 = _t856*_t9;
  const double _t859 = _hc5[1]*nb;
  const double _t861 = _hc3[2]*_t442;
  const double _t862 = _t242*_t861;
  const double _t863 = _hc3[5]*_t243;
  const double _t864 = _t442*_t863;
  const double _t865 = _t250*_t6;
  const double _t866 = (0.1e1 / 0.18e2)*_t865;
  const double _t867 = _hc2[2]*_t437;
  const double _t871 = _hc1[2]*_t85;
  const double _t872 = _t870*_t871;
  const double _t873 = _hc1[5]*_t476;
  const double _t874 = _t252*_t873;
  const double _t875 = -_t218 - _t220 + _t601;
  const double _t876 = _t193*_t850 + _t195*_t845 + _t196*_t844 + _t223 + _t229*_t858 + _t231 + _t235 + _t239*_t846 + _t242*_t849 + _t437*_t866 + _t553*_t848 + _t842*_t843 + _t853*_t9 - _t857 + _t859*_t860 - _t862 - _t864 + _t867*_t869 - _t872 - _t874 + _t875;
  const double _t877 = (0.128e3 / 0.3e1)*_t604;
  const double _t878 = (0.320e3 / 0.27e2)*_t272;
  const double _t879 = (0.32e2 / 0.27e2)*_t38;
  const double _t880 = _t38*na;
  const double _t881 = (0.16e2 / 0.27e2)*_t268;
  const double _t884 = _t102*_t201;
  const double _t888 = (0.320e3 / 0.9e1)*_t504;
  const double _t894 = (0.32e2 / 0.9e1)*_t38;
  const double _t896 = _hc7[7]*_t194 + _t652;
  const double _t897 = _hc7[8]*_t194 + _t650;
  const double _t898 = -_t133*_t897 + _t649;
  const double _t899 = _hc7[4]*_t238 + _t79*_t896 + _t898;
  const double _t900 = _hc7[6]*_t194 + _t656;
  const double _t901 = -_t133*_t896 + _t655;
  const double _t902 = _hc7[3]*_t238 + _t79*_t900 + _t901;
  const double _t903 = _hc7[1]*_t845 - _t133*_t899 + _t238*_t290 + _t239*_t464 + _t288*_t310 + _t310*_t465 + _t646 + _t79*_t902;
  const double _t904 = _t127*_t297;
  const double _t905 = _t297*_t91;
  const double _t906 = (0.8e1 / 0.15e2)*_t905;
  const double _t907 = _t194*_t475;
  const double _t908 = _hc9[3]*_t664;
  const double _t909 = _t109*_t908;
  const double _t910 = (0.4e1 / 0.5e1)*_t909;
  const double _t911 = _t79*_t910;
  const double _t912 = _t476*_t908;
  const double _t913 = _t299*_t912;
  const double _t914 = (0.1e1 / 0.4e1)*_hc1[2]*_hc2[0]*_t845 + (0.1e1 / 0.18e2)*_hc1[2]*_hc2[1]*_t194*_t249*_t3*_t5 + (0.1e1 / 0.144e3)*_hc1[2]*_hc2[2]*_t194*_t225*_t226*_t245 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t194*_t239 + _hc1[5]*_hc2[0]*_t79*_t87*_t9 + (0.1e1 / 0.4e1)*_hc1[9]*_hc2[0]*_t240*_t847 + (0.1e1 / 0.4e1)*_hc3[2]*_hc4[0]*_t844 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t193*_t242 + (0.1e1 / 0.4e1)*_hc3[9]*_hc4[0]*_t193*_t243 + 0.24e2*_hc8[0]*_t221*na + 0.48e2*_hc8[0]*_t221*nb + (0.32e2 / 0.9e1)*_hc8[1]*_t232*_t3*_t5*na + (0.64e2 / 0.9e1)*_hc8[1]*_t232*_t3*_t5*nb + (0.1e1 / 0.9e1)*_hc8[2]*_t224*_t225*_t226*na + (0.2e1 / 0.9e1)*_hc8[2]*_t224*_t225*_t226*nb + (0.2e1 / 0.45e2)*_hc9[1]*_t118*_t194*_t64*_t67 + (0.4e1 / 0.45e2)*_hc9[1]*_t118*_t64*_t67*_t79 - _t123*_t845 - _t127*_t665 - _t239*_t904 - _t239*_t907 - _t293 - _t296 - _t661*_t848 - _t678 - _t857 - _t862 - _t864 - _t872 - _t874 - _t9*_t906 - _t9*_t911 - _t913;
  const double _t915 = _t305*nb;
  const double _t916 = _t60*_t684;
  const double _t917 = 0.32e2*_t916;
  const double _t921 = _t60*nb;
  const double _t923 = 0.32e2*_t60;
  const double _t924 = _t923*nb;
  const double _t927 = _hc10[0]*na;
  const double _t930 = _t91*_t927;
  const double _t936 = 0.8e1*_t467;
  const double _t938 = 0.4e1*_t40;
  const double _t943 = _t26*_t40;
  const double _t944 = _t149*_t943;
  const double _t946 = _hc10[0]*nb;
  const double _t957 = _t532*na;
  const double _t959 = _t150*na;
  const double _t960 = _t958*_t959;
  const double _t961 = _hc10[0]*_t585;
  const double _t966 = _hc10[0]*_t26;
  const double _t971 = _hc11[7]*_t194 + _t744;
  const double _t972 = _hc11[8]*_t194 + _t742;
  const double _t973 = -_t133*_t972 + _t741;
  const double _t974 = _hc11[4]*_t238 + _t79*_t971 + _t973;
  const double _t975 = _hc11[6]*_t194 + _t748;
  const double _t976 = -_t133*_t971 + _t747;
  const double _t977 = _hc11[3]*_t238 + _t79*_t975 + _t976;
  const double _t979 = (0.7e1 / 0.36e2)*_t753;
  const double _t980 = _t370*_t487;
  const double _t982 = _hc12[6]*_t848;
  const double _t984 = _hc12[3]*_t166;
  const double _t985 = _t490*_t984;
  const double _t986 = 0.2e1*_t985;
  const double _t987 = _t756*_t848;
  const double _t988 = _t755*_t759;
  const double _t989 = _t476*_t761;
  const double _t990 = -0.1e1 / 0.6e1*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t194*_t79*p->cam_omega + _t752 + (0.1e1 / 0.3e1)*_t989;
  const double _t991 = 0.3e1*_hc12[1]*_hc12[3]*_t12*_t13*_t15*_t18*_t240*_t375*_t847*p->cam_omega + (0.1e1 / 0.12e2)*_hc12[1]*_t12*_t13*_t15*_t161*_t165*_t239*p->cam_omega + (0.1e1 / 0.3e1)*_hc12[1]*_t12*_t13*_t15*_t165*_t9*_t978*p->cam_omega + (0.1e1 / 0.12e2)*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t240*p->cam_omega + _t12*_t13*_t15*_t18*_t194*_t239*_t374*_t375*p->cam_omega + 0.4e1*_t12*_t13*_t15*_t374*_t375*_t490*_t79*_t9*p->cam_omega - _t168*_t845 - _t380*_t982 - _t489*_t981 - 0.1e1 / 0.6e1*_t762 - _t979 - 0.7e1 / 0.72e2*_t980 - _t983*_t986 - _t987*_t988 - _t990;
  const double _t992 = _hc12[3]*_t770;
  const double _t993 = _t369 - _t476*_t992 + 0.2e1*_t488 - 0.2e1*_t492 + _t535 + _t769;
  const double _t995 = -_t163 - _t168*_t847;
  const double _t1000 = _t173*_t847;
  const double _t1006 = 0.6e1*_t995;
  const double _t1009 = _t169*_t212;
  const double _t1011 = 0.6e1*_t172;
  const double _t1013 = _hc12[3]*_t164;
  const double _t1014 = _t1013*_t395;
  const double _t1016 = _t194*_t391;
  const double _t1027 = _t795*_t87;
  const double _t1028 = (0.32e2 / 0.3e1)*_t1027;
  const double _t1029 = (0.80e2 / 0.27e2)*_t404;
  const double _t1030 = _t177*_t798;
  const double _t1031 = _t177*na;
  const double _t1032 = _t1031*_t268;
  const double _t1036 = _t407*_t880;
  const double _t1041 = _t1*_t23;
  const double _t1052 = _t512*_t555;
  const double _t1053 = _t194*_t851;
  const double _t1054 = _hc1[2]*_t509;
  const double _t1055 = _hc1[5]*_t510;
  const double _t1056 = _t440*_t82;
  const double _t1058 = _hc4[2]*_t513;
  const double _t1059 = _t1058*_t868;
  const double _t1061 = _hc3[5]*_t517;
  const double _t1062 = _hc4[1]*_t199;
  const double _t1063 = _hc3[2]*_t1062;
  const double _t1064 = -_t1050*_t430 + _t1050*_t432 + _t1051*_t553 + _t1052*_t78 + _t1053*_t870 - _t1054*_t438 - _t1055*_t438 + _t1056*_t1057 + _t1059*_t82 - _t1060*_t1061 + _t1063*_t870 - _t193*_t855*_t9 - _t431 + _t433 + _t435*_t509 + _t436*_t511;
  const double _t1065 = _t1048*_t229 + _t1049*_t229 + _t1064 + _t222*_t842 + _t234*_t859 + _t843*_t89 + _t860*_t94 + _t875;
  const double _t1066 = _t102*_t519;
  const double _t1067 = _hc7[4]*_t509 + _t194*_t896 + _t898;
  const double _t1068 = _t1067*_t133;
  const double _t1069 = _hc7[3]*_t509 + _t194*_t900 + _t901;
  const double _t1070 = -_hc7[1]*_t237 - _hc7[1]*_t549 - _t1068 + _t1069*_t79 + (0.4e1 / 0.9e1)*_t109*_t3*_t465*_t5 + 0.4e1*_t464*_t87*_t9 - _t645;
  const double _t1071 = _hc8[0]*nb;
  const double _t1072 = _t522*_t664;
  const double _t1074 = _hc8[1]*nb;
  const double _t1076 = _t1048*_t301 + _t1049*_t301 - _t1051*_t661 + _t1064 + _t1071*_t222 - _t1072*_t127 + _t1073*_t905 + _t1074*_t234 - _t1075*_t910 + (0.4e1 / 0.45e2)*_t118*_t473 + _t125*_t843 + _t129*_t860 - _t293 - _t296 + _t298*_t300 + _t472 - _t509*_t666 - _t509*_t904 - _t668 - _t670 - _t673 - _t675 - _t677 - _t913;
  const double _t1077 = _t317*nb;
  const double _t1078 = _t305*na;
  const double _t1080 = _t137*_t695;
  const double _t1081 = _t318*_t921;
  const double _t1088 = _t40*na;
  const double _t1089 = _t1088*_t39;
  const double _t1093 = _hc11[4]*_t509 + _t194*_t971 + _t973;
  const double _t1094 = _t1093*_t133;
  const double _t1095 = _hc11[3]*_t509 + _t194*_t975 + _t976;
  const double _t1096 = _t510*_t761;
  const double _t1097 = (0.7e1 / 0.36e2)*_t980;
  const double _t1098 = _hc12[6]*_t1051;
  const double _t1099 = _t1051*_t756;
  const double _t1100 = 0.3e1*_hc12[1]*_hc12[3]*_t12*_t13*_t15*_t18*_t375*_t510*_t784*p->cam_omega + (0.1e1 / 0.12e2)*_hc12[1]*_t12*_t13*_t15*_t161*_t165*_t509*p->cam_omega + _hc12[1]*_t12*_t13*_t15*_t165*_t490*p->cam_omega + (0.10e2 / 0.3e1)*_hc12[1]*_t12*_t13*_t15*_t165*_t9*_t978*p->cam_omega + (0.1e1 / 0.12e2)*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t510*p->cam_omega - _t1075*_t986 - 0.1e1 / 0.6e1*_t1096 - _t1097 - _t1098*_t380 - _t1099*_t988 + _t12*_t13*_t15*_t18*_t374*_t375*_t509*_t79*p->cam_omega + 0.4e1*_t12*_t13*_t15*_t194*_t374*_t375*_t490*_t9*p->cam_omega - _t509*_t763 - 0.7e1 / 0.72e2*_t753 - _t990;
  const double _t1106 = _t173*_t784;
  const double _t1107 = _t164*_t541;
  const double _t1110 = _t391*_t510;
  const double _t1122 = _hc4[3]*_t53;
  const double _t1125 = _t1122*_t1124;
  const double _t1130 = _t1129*_t197;
  const double _t1133 = _t1132*_t514;
  const double _t1134 = (0.1e1 / 0.8e1)*_t441;
  const double _t1135 = _hc3[2]*_t511;
  const double _t1136 = _t1134*_t1135;
  const double _t1137 = _hc3[5]*_t512;
  const double _t1138 = _t1134*_t1137;
  const double _t1139 = _hc4[1]*_t516;
  const double _t1140 = _t1058*_t516*_t583 + _t1118*_t196 + _t1119*_t195 + _t1120*_t553 + _t1121*_t555 - _t1125 + _t1126*_t846 + _t1127*_t849 - _t1130 - _t1133 - _t1136 - _t1138 + _t1139*_t515*_t83 + _t509*_t846 + _t511*_t849 + _t547*na + _t574*na + _t575*na + _t601;
  const double _t1141 = _t1140*_t56;
  const double _t1143 = _hc7[1]*_t1119 - _t1068 + _t1069*_t194 + _t1142*_t464 + _t465*_t740 + _t646;
  const double _t1145 = (0.1e1 / 0.4e1)*_hc1[2]*_hc2[0]*_t1119 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t1126*_t194 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t194*_t509 + (0.1e1 / 0.4e1)*_hc1[9]*_hc2[0]*_t1120 + (0.1e1 / 0.4e1)*_hc3[2]*_hc4[0]*_t1118 + (0.1e1 / 0.6e1)*_hc3[2]*_hc4[1]*_t193*_t3*_t5*_t515 + (0.1e1 / 0.48e2)*_hc3[2]*_hc4[2]*_t193*_t225*_t226*_t513 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t1127*_t193 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t193*_t511 + (0.1e1 / 0.4e1)*_hc3[9]*_hc4[0]*_t1121 + 0.72e2*_hc8[0]*_t221*na + (0.32e2 / 0.3e1)*_hc8[1]*_t232*_t3*_t5*na + (0.1e1 / 0.3e1)*_hc8[2]*_t224*_t225*_t226*na + (0.2e1 / 0.15e2)*_hc9[1]*_t118*_t194*_t64*_t67 - _t1072*_t663 - _t1119*_t123 - _t1120*_t661 - _t1125 - _t1130 - _t1133 - _t1136 - _t1138 - _t1144*_t475 - _t509*_t662 - _t509*_t907 - _t678;
  const double _t1146 = _t1145*_t71;
  const double _t1149 = 0.12e2*_t521;
  const double _t1150 = _t698*nb;
  const double _t1156 = _hc12[6]*_t1120;
  const double _t1157 = _t1120*_t756;
  const double _t1158 = _t1157*_t755;
  const double _t1160 = 0.3e1*_hc12[1]*_hc12[3]*_t1120*_t12*_t13*_t15*_t18*_t375*p->cam_omega + (0.1e1 / 0.4e1)*_hc12[1]*_t12*_t13*_t15*_t161*_t165*_t509*p->cam_omega + (0.1e1 / 0.4e1)*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t510*p->cam_omega - 0.1e1 / 0.2e1*_t1096 - _t1119*_t168 + _t1126*_t12*_t13*_t15*_t18*_t194*_t374*_t375*p->cam_omega - _t1144*_t489 - _t1156*_t380 - _t1158*_t759 - _t1159*_t489 + _t12*_t13*_t15*_t18*_t194*_t374*_t375*_t509*p->cam_omega - _t752 - 0.7e1 / 0.24e2*_t980;
  const double _t1161 = (_t212 * _t212 * _t212);
  const double _t1162 = _t537*_t770;
  const double _t1163 = -_t1162 + 0.2e1*_t536 + _t769;
  const double _t1164 = _t1163 + _t487*_t768 - _t509*_t767;
  const double _t1167 = _t194*_t778;
  const double _t1168 = _t509*_t778;
  const double _t1169 = _t778*_t847;
  const double _t1170 = _t537*_t788;
  const double _t1171 = 0.18e2*_t1110;
  const double _t1173 = _t268*_t799;
  const double _t609 = _t261*_t97;
  const double _t611 = _t103*_t141;
  const double _t612 = (0.2e1 / 0.5e1)*_t611;
  const double _t614 = (0.3e1 / 0.5e1)*_t105;
  const double _t616 = _t282*_t615;
  const double _t617 = (0.160e3 / 0.3e1)*_t279;
  const double _t618 = (0.64e2 / 0.3e1)*_t114;
  const double _t619 = _t274*_t618;
  const double _t623 = ((_hc14[1]) * (_hc14[1]) * (_hc14[1]));
  const double _t624 = _t113*_t623;
  const double _t625 = _t624*_t87;
  const double _t627 = (0.8e1 / 0.45e2)*_t180;
  const double _t634 = _hc6[2]*_t114;
  const double _t635 = _t256*_t59;
  const double _t636 = _hc6[1]*_t635;
  const double _t638 = _t139*_t623;
  const double _t643 = (0.1120e4 / 0.9e1)*_hc6[0]*_t26*_t635*_t640 + (0.448e3 / 0.9e1)*_t115*_t641 + _t221*_t263*_t626 + (0.1888e4 / 0.81e2)*_t232*_t26*_t271 + (0.112e3 / 0.27e2)*_t26*_t260*_t637 + _t260*_t262*_t348 + (0.3776e4 / 0.27e2)*_t282*_t642 - _t55*_t627 + (0.7e1 / 0.5e1)*_t622*_t625 + _t630*_t631 + (0.16e2 / 0.3e1)*_t633*_t634 + (0.80e2 / 0.3e1)*_t633*_t636 + (0.320e3 / 0.9e1)*_t638*_t639;
  const double _t682 = _t313*_t681;
  const double _t686 = _hc16[9]*_t227;
  const double _t687 = _hc16[5]*_t310 + _t309*_t686;
  const double _t688 = _t133*_t687;
  const double _t690 = _t307*_t689;
  const double _t692 = _hc16[2]*_t691;
  const double _t693 = _t688 + _t690 + _t692;
  const double _t694 = _hc15[1]*_t551 + 0.3e1*_hc17[3]*_t239*_t79 - _t693;
  const double _t696 = _t694*_t695;
  const double _t699 = _t340*_t698;
  const double _t700 = _t257*_t321;
  const double _t701 = _t131*_t700;
  const double _t702 = 0.20e2*_t326;
  const double _t703 = 0.80e2*_t331;
  const double _t704 = 0.20e2*_t325;
  const double _t705 = _t340*_t704;
  const double _t706 = _t329*_t91;
  const double _t707 = 0.80e2*_t706;
  const double _t708 = _t340*_t707;
  const double _t709 = _t558*_t623;
  const double _t710 = _t221*_t709;
  const double _t711 = _hc0[0]*_t710;
  const double _t712 = _t227*_t276;
  const double _t713 = _hc14[1]*_t92;
  const double _t714 = _t139*_t713;
  const double _t716 = -0.944e3 / 0.9e1*_hc10[0]*_hc14[1]*_t113*_t144*_t232*_t3*na*nb - 0.80e2 / 0.3e1*_hc10[0]*_t139*_t585*_t623*na*nb - 0.48e2*M_PI*_hc10[0]*_t221*_t38*na*nb - 0.140e3 / 0.3e1*_hc10[0]*_t224*_t225*_t256*_t4*_t59*na*nb - 0.7e1 / 0.4e1*_t113*_t623*_t70*_t87 + _t140*_t711 - 0.7e1 / 0.24e2*_t225*_t256*_t308*_t38*_t4*_t70 + _t285*_t458 + 0.8e1*_t450*_t712 + _t714*_t715;
  const double _t720 = _t10*_t694;
  const double _t721 = _t40*_t720;
  const double _t722 = _t340*_t718;
  const double _t723 = (0.28e2 / 0.3e1)*_t359;
  const double _t724 = (0.80e2 / 0.3e1)*_t356;
  const double _t725 = (0.28e2 / 0.3e1)*_t358;
  const double _t726 = _t340*_t725;
  const double _t727 = (0.80e2 / 0.3e1)*_t340;
  const double _t728 = _t155*_t91;
  const double _t729 = _t727*_t728;
  const double _t730 = _t139*_t710;
  const double _t732 = _t730*_t731;
  const double _t733 = _t59*_t712;
  const double _t734 = _t731*_t733;
  const double _t735 = _t113*_t713;
  const double _t736 = _t715*_t735;
  const double _t737 = -0.944e3 / 0.27e2*_hc10[0]*_hc14[1]*_t103*_t144*_t232*_t3*na*nb - 0.56e2 / 0.3e1*_hc10[0]*_t113*_t585*_t623*na*nb - 0.12e2*M_PI*_hc10[0]*_t221*_t29*na*nb - 0.196e3 / 0.9e1*_hc10[0]*_t224*_t225*_t256*_t38*_t4*na*nb + _t732 + _t734 + _t736;
  const double _t766 = _hc13[3]*_t25;
  const double _t775 = _hc13[0]*_t387;
  const double _t777 = _hc13[1]*_t79;
  const double _t780 = _hc13[1]*_t169;
  const double _t782 = _hc13[2]*_t383;
  const double _t787 = _hc13[1]*_t786;
  const double _t789 = _t787*_t788;
  const double _t792 = _t388*_t791;
  const double _t794 = 0.18e2*_t787;
  const double _t802 = _t408*_t801;
  const double _t803 = _t410*_t801;
  const double _t804 = _t104*_t400;
  const double _t805 = _t274*_t804;
  const double _t812 = _hc6[1]*_t256;
  const double _t813 = _t28*_t812;
  const double _t814 = _t28*_t624;
  const double _t815 = _t412*_t641;
  const double _t817 = (0.1568e4 / 0.27e2)*_t256;
  const double _t819 = _t102*_t104*_t407;
  const double _t820 = _t108*_t412*_t809 + (0.472e3 / 0.81e2)*_t178*_t642 + 0.16e2*_t26*_t806 + (0.2e1 / 0.27e2)*_t26*_t807 + (0.28e2 / 0.27e2)*_t26*_t811 + (0.448e3 / 0.27e2)*_t26*_t815 + (0.112e3 / 0.9e1)*_t631*_t808*_t813 + (0.224e3 / 0.9e1)*_t639*_t814 + (0.3776e4 / 0.81e2)*_t642*_t819 + _t816*_t817*_t818;
  const double _t821 = _t170*_t764 + _t239*_t501 + _t24*(_hc11[1]*_t551 - _t133*_t746 + _t364*_t740 + _t366*_t648 + _t739 + _t750*_t79) + _t37*(0.16e2*_hc14[1]*_t103*_t109*_t135*_t144*_t3*nb + 0.8e1*_hc14[1]*_t103*_t109*_t144*_t3*_t312*na*nb + 0.16e2*_hc14[1]*_t109*_t113*_t121*_t3*_t5 + 0.10e2*_t121*_t225*_t226*_t256*_t308*_t59 + 0.12e2*M_PI*_t135*_t29*_t48*nb - _t148*_t721 + 0.6e1*M_PI*_t29*_t312*_t48*na*nb - _t337*_t697 - _t338*_t717 + 0.4e1*_t38*_t659 - _t481*_t722 - _t719*nb - _t723*nb - _t724*nb - _t726*nb - _t729*nb - _t737) + _t379*_t789 + _t382*_t495 + _t386*_t774 + _t390*_t757 - _t404*_t797 + _t44*(-_t1*_t603 - _t254*_t546 - _t605*nb - _t607*nb - _t608*nb - 0.7e1 / 0.5e1*_t609 + _t610*_t612 + _t613*_t614 - _t616*nb - _t617*nb - _t619*nb + _t643) + _t495*_t773 + _t499*_t776 + _t500*_t563 + _t501*_t563 + _t552*_t792 + _t58*((0.1e1 / 0.2e1)*_hc14[1]*_t103*_t118*_t131*_t144*_t3 + (0.3e1 / 0.4e1)*_hc14[1]*_t103*_t144*_t2*_t3*_t303 + 0.48e2*_hc14[1]*_t109*_t113*_t135*_t144*_t3*nb + 0.24e2*_hc14[1]*_t109*_t113*_t144*_t3*_t312*na*nb + 0.16e2*_hc14[1]*_t109*_t121*_t139*_t3*_t5 - _t1*_t680 + 0.6e1*_t121*_t20*_t225*_t226*_t256*_t308 + 0.48e2*M_PI*_t135*_t38*_t48*nb - _t137*_t696 - _t303*_t660 + 0.24e2*M_PI*_t312*_t38*_t48*na*nb - _t315*_t697 + 0.6e1*_t59*_t659 - _t682*nb - _t685*nb - _t699*nb - 0.7e1 / 0.8e1*_t701 - _t702*nb - _t703*nb - _t705*nb - _t708*nb - _t716) + _t754*_t775 + _t765*_t766 + _t777*_t779 + _t780*_t781 + _t782*_t785 + _t793*_t794 - _t796*nb - _t798*_t799 - 0.320e3 / 0.9e1*_t802 - 0.224e3 / 0.9e1*_t803 - _t805*nb + _t820;
  const double _t822 = _t23*_t821;
  const double _t823 = _t187*_t421;
  const double _t824 = _t185*_t823;
  const double _t825 = _t416*_t418;
  const double _t826 = 0.4e1*_t190;
  const double _t827 = _t142*_t419;
  const double _t828 = _t185*_t424;
  const double _t830 = _t421*_t829;
  const double _t831 = _t73*_t87;
  const double _t832 = _hc0[0]*_t709;
  const double _t834 = _t832*_t833;
  const double _t837 = _t139*_t709;
  const double _t838 = _t836*_t837;
  const double _t839 = (0.32e2 / 0.27e2)*_t354;
  const double _t840 = _t20*_t349;
  const double _t841 = -_t189*_t839 + _t349*_t422 - _t426*_t840 - _t831*_t834 + _t831*_t838;
  const double _t882 = _t201*_t261;
  const double _t883 = (0.2e1 / 0.15e2)*_t611;
  const double _t886 = _t104*_t885;
  const double _t887 = _t283*nb;
  const double _t889 = _t281*_t91;
  const double _t890 = _t279*nb;
  const double _t891 = _t278*_t504;
  const double _t892 = _t275*nb;
  const double _t893 = _t114*_t274*na;
  const double _t895 = _t102*_t104*_t444*_t663 + _t111*_t894 + _t112*_t618 - _t216*_t444 + _t264*_t48 + _t643;
  const double _t918 = _hc17[3]*_t79;
  const double _t919 = _hc15[1]*_t845 + _t239*_t461 + _t562*_t918 - _t688 - _t690 - _t692;
  const double _t920 = _t695*_t919;
  const double _t922 = _t206*_t921;
  const double _t925 = _t340*_t87;
  const double _t926 = _t257*_t322;
  const double _t928 = _t325*_t927;
  const double _t929 = _t326*nb;
  const double _t931 = _t329*_t930;
  const double _t932 = _t331*nb;
  const double _t933 = _t325*_t459;
  const double _t934 = _t325*_t455;
  const double _t935 = _t459*_t706;
  const double _t937 = -0.16e2*_hc10[0]*_hc14[1]*_t109*_t113*_t144*_t3 - 0.16e2*M_PI*_hc10[0]*_t38*_t48 - 0.1e1 / 0.2e1*_hc14[1]*_t103*_t144*_t2*_t3*_t477 - 0.16e2*_hc14[1]*_t109*_t113*_t135*_t144*_t3*na - 0.16e2*_hc14[1]*_t109*_t113*_t144*_t206*_t3*nb - 0.16e2*_hc14[1]*_t109*_t113*_t144*_t3*_t462*na*nb - 0.16e2*M_PI*_t135*_t38*_t48*na - 0.16e2*M_PI*_t206*_t38*_t48*nb + _t292*_t477 + _t315*_t936 - 0.16e2*M_PI*_t38*_t462*_t48*na*nb + _t716;
  const double _t939 = _t459*_t87;
  const double _t940 = _t40*_t939;
  const double _t941 = _t10*_t919;
  const double _t942 = _t40*_t941;
  const double _t945 = _t155*_t606;
  const double _t947 = _t155*_t930;
  const double _t948 = _t359*nb;
  const double _t949 = _t358*_t927;
  const double _t950 = _t135*_t343;
  const double _t952 = (0.80e2 / 0.9e1)*_t728;
  const double _t953 = _t358*_t455;
  const double _t954 = _t358*_t459;
  const double _t956 = _t26*_t312;
  const double _t962 = (0.56e2 / 0.3e1)*_t624;
  const double _t963 = _t206*_t343;
  const double _t964 = _t26*_t462;
  const double _t965 = _t256*_t321;
  const double _t967 = _t965*_t966;
  const double _t969 = (0.944e3 / 0.27e2)*_t155;
  const double _t970 = _t232*_t966*_t969 + _t26*_t961*_t962 + _t336 - _t337*_t936 + _t341 + _t342 + _t344*_t964 + _t345 + _t462*_t957 + _t533 - _t732 - _t734 - _t736 + _t951*_t963 + _t960*nb + _t967*_t968;
  const double _t994 = _t212*_t384;
  const double _t996 = _t383*_t766;
  const double _t997 = _t390*_t756;
  const double _t998 = _hc13[1]*_t212;
  const double _t999 = _t172*_t998;
  const double _t1001 = _t194*_t388;
  const double _t1002 = _hc13[1]*_t995;
  const double _t1003 = _t1002*_t387;
  const double _t1004 = _hc12[6]*_t775;
  const double _t1005 = _t194*_t392;
  const double _t1007 = _hc13[1]*_t793;
  const double _t1008 = _t394*_t79;
  const double _t1010 = _hc13[2]*_t1009;
  const double _t1012 = _t1010*_t1011;
  const double _t1015 = _t194*_t393;
  const double _t1017 = 0.12e2*_hc13[1];
  const double _t1018 = _t1016*_t1017;
  const double _t1019 = _t172*_t780;
  const double _t1020 = _t1019*_t718;
  const double _t1021 = _t164*_t499;
  const double _t1022 = _t1021*_t718;
  const double _t1023 = _t389*_t791;
  const double _t1024 = 0.24e2*_hc13[0];
  const double _t1025 = _t1024*_t391;
  const double _t1026 = _t1025*_t852;
  const double _t1034 = _t28*_t408;
  const double _t1035 = _t1034*_t504;
  const double _t1037 = _t1036*_t259*_t276;
  const double _t1038 = (0.128e3 / 0.27e2)*_t413;
  const double _t1039 = _t397 + _t399 + _t401 + _t820;
  const double _t1040 = _t1000*_t782 + _t1001*_t776 + _t1003*_t379 + _t1004*_t848 + _t1005*_t239 + _t1006*_t1007 + _t1008*_t494 + _t1012*_t79 + _t1014*_t1015 + _t1018*_t395 + _t1020*_t9 + _t1022*_t9 + _t1023*_t847 + _t1026*_t9 - _t1028*nb - _t1029*nb - 0.8e1 / 0.27e2*_t1030 - 0.4e1 / 0.27e2*_t1032 - _t1033*_t411 - 0.320e3 / 0.27e2*_t1035 - 0.224e3 / 0.27e2*_t1037 - _t1038*nb + _t1039 + _t170*_t991 + _t213*_t845 + _t24*(_hc11[1]*_t845 - _t133*_t974 + _t238*_t366 + _t239*_t484 + _t310*_t364 + _t310*_t485 + _t739 + _t79*_t977) + _t37*((0.20e2 / 0.3e1)*_t121*_t350 + (0.32e2 / 0.3e1)*_t121*_t355 - _t124*_t150 - _t124*_t340*_t40 + _t135*_t532 - _t136*_t938 + _t146*_t903 - _t148*_t942 + _t203*_t351 + (0.16e2 / 0.3e1)*_t203*_t355 - _t209*_t338 - _t291*_t479 + _t312*_t944 - _t335*_t480 - _t335*_t940 - _t346*_t529 - _t455*_t945 - _t460*_t952 + _t483*_t956 - _t945*_t946 - 0.80e2 / 0.9e1*_t947 - 0.56e2 / 0.9e1*_t948 - 0.28e2 / 0.9e1*_t949 + _t950*_t951 - 0.56e2 / 0.9e1*_t953 - _t954*_t955 + _t970) + _t382*_t498 + _t382*_t994 + _t385*_t999 - _t402*_t504 - _t405*na - _t414*na + _t44*(_t106*_t613 - _t255 - _t265*na - _t273*na - _t445*_t876 - 0.14e2 / 0.15e2*_t609 + _t610*_t886 - _t798*_t879 - _t877*nb - _t878*nb - _t880*_t881 - 0.7e1 / 0.15e2*_t882 + _t883*_t884 - 0.640e3 / 0.9e1*_t887 - _t888*_t889 - 0.320e3 / 0.9e1*_t890 - 0.160e3 / 0.9e1*_t891 - 0.128e3 / 0.9e1*_t892 - 0.64e2 / 0.9e1*_t893 + _t895) + _t495*_t993 + _t58*((0.1e1 / 0.3e1)*_hc14[1]*_t103*_t118*_t131*_t144*_t3 + (0.1e1 / 0.6e1)*_hc14[1]*_t103*_t118*_t144*_t204*_t3 + (0.1e1 / 0.4e1)*_hc14[1]*_t103*_t144*_t2*_t3*_t303 + 0.16e2*_hc14[1]*_t109*_t113*_t135*_t144*_t3*nb + 0.8e1*_hc14[1]*_t109*_t113*_t144*_t3*_t312*na*nb + (0.32e2 / 0.3e1)*_hc14[1]*_t109*_t121*_t139*_t3*_t5 + (0.16e2 / 0.3e1)*_hc14[1]*_t109*_t139*_t203*_t3*_t5 + 0.4e1*_t121*_t20*_t225*_t226*_t256*_t308 + 0.16e2*M_PI*_t135*_t38*_t48*nb - _t137*_t920 + 0.2e1*_t20*_t203*_t225*_t226*_t256*_t308 - _t204*_t926 - _t291*_t454 - _t304 - _t306 + 0.8e1*M_PI*_t312*_t38*_t48*na*nb - _t314 - _t318*_t922 - _t319 - 0.160e3 / 0.3e1*_t455*_t706 - _t463*_t915 - _t478*_t914 + 0.6e1*_t59*_t903 - 0.7e1 / 0.12e2*_t701 - _t917*nb - _t924*_t925 - 0.20e2 / 0.3e1*_t928 - 0.40e2 / 0.3e1*_t929 - 0.80e2 / 0.3e1*_t931 - 0.160e3 / 0.3e1*_t932 - 0.20e2 / 0.3e1*_t933*nb - 0.40e2 / 0.3e1*_t934 - 0.80e2 / 0.3e1*_t935*nb - _t937) - 0.640e3 / 0.27e2*_t802 + _t848*_t997 + _t995*_t996;
  const double _t1042 = _t214*_t823;
  const double _t1043 = (0.20e2 / 0.9e1)*_t427;
  const double _t1044 = _t214*_t424;
  const double _t1045 = (0.40e2 / 0.9e1)*_t427;
  const double _t1046 = _t418*_t506;
  const double _t1047 = _t1046*_t420 + 0.2e1*_t507 + _t841;
  const double _t1079 = -_hc15[1]*_t237 - _hc15[1]*_t549 + 0.4e1*_hc17[3]*_t194*_t87*_t9 + _hc17[3]*_t509*_t79 - _t693;
  const double _t1082 = _t923*_t939;
  const double _t1083 = _t204*_t700;
  const double _t1084 = (0.40e2 / 0.3e1)*_t933;
  const double _t1085 = (0.160e3 / 0.3e1)*_t935;
  const double _t1086 = _t40*_t459;
  const double _t1087 = _t10*_t1079;
  const double _t1090 = _t459*_t945;
  const double _t1091 = (0.56e2 / 0.9e1)*_t954;
  const double _t1092 = _t26*_t526;
  const double _t1101 = _t540*_t766;
  const double _t1102 = 0.2e1*_t994;
  const double _t1104 = _t496*_t79;
  const double _t1105 = _hc13[2]*_t540;
  const double _t1108 = _t387*_t787;
  const double _t1109 = _t393*_t786;
  const double _t1111 = _t1013*_t1015;
  const double _t1113 = _t1001*_t164;
  const double _t1115 = _t1004*_t1051 + _t1012*_t194 + _t1018*_t497 + _t1019*_t541 + _t1025*_t1114 - _t1028*na - _t1029*na - 0.4e1 / 0.27e2*_t1030 - 0.8e1 / 0.27e2*_t1032 - 0.640e3 / 0.27e2*_t1035 - 0.448e3 / 0.27e2*_t1037 - _t1038*na + _t1039 + _t1051*_t792 + _t1051*_t997 + _t1100*_t170 + _t1101*_t786 + _t1102*_t494 - _t1103*_t386 + _t1104*_t539 + _t1105*_t1106 + _t1107*_t499 + _t1108*_t537 + _t1109*_t1110 + _t1111*_t497 + _t1112*_t1113 + _t1112*_t999 + _t24*(-_hc11[1]*_t237 - _hc11[1]*_t549 + (0.4e1 / 0.9e1)*_t109*_t3*_t485*_t5 - _t1094 + _t1095*_t79 + 0.4e1*_t484*_t87*_t9 - _t738) + _t37*(_t1070*_t146 - _t1086*_t124 - _t1087*_t1089 - _t1090*nb - _t1091*nb + _t1092*_t483 + _t121*_t351 + (0.16e2 / 0.3e1)*_t121*_t355 + (0.20e2 / 0.3e1)*_t203*_t350 + (0.32e2 / 0.3e1)*_t203*_t355 - _t207*_t938 - _t335*_t40*_t925 + _t339*_t459 - _t347 - _t357*nb - _t455*_t952 - _t479*_t521 - _t480*_t529 + _t526*_t944 - _t531 + _t534 - _t88*_t959 - _t927*_t945 - 0.28e2 / 0.9e1*_t948 - 0.56e2 / 0.9e1*_t949 - 0.28e2 / 0.9e1*_t953 + _t970) - _t386*_t502 - _t403*nb - _t405*nb - _t414*nb + _t44*(_t106*_t1066 - _t1065*_t445 - _t265*nb - _t268*_t879*na - _t270*nb - _t273*nb - _t278*_t888 - 0.640e3 / 0.9e1*_t504*_t889 - _t520 - 0.7e1 / 0.15e2*_t609 + _t610*_t883 - _t877*na - _t878*na - 0.14e2 / 0.15e2*_t882 + _t884*_t886 - 0.320e3 / 0.9e1*_t887 - 0.160e3 / 0.9e1*_t890 - 0.64e2 / 0.9e1*_t892 - 0.128e3 / 0.9e1*_t893 + _t895) + _t494*_t543 + _t495*_t539 + _t501*_t509 + _t58*((0.1e1 / 0.6e1)*_hc14[1]*_t103*_t118*_t131*_t144*_t3 + (0.1e1 / 0.3e1)*_hc14[1]*_t103*_t118*_t144*_t204*_t3 + (0.1e1 / 0.4e1)*_hc14[1]*_t103*_t144*_t2*_t3*_t523 + 0.16e2*_hc14[1]*_t109*_t113*_t144*_t206*_t3*na + 0.8e1*_hc14[1]*_t109*_t113*_t144*_t3*_t526*na*nb + (0.16e2 / 0.3e1)*_hc14[1]*_t109*_t121*_t139*_t3*_t5 + (0.32e2 / 0.3e1)*_hc14[1]*_t109*_t139*_t203*_t3*_t5 + 0.6e1*_t1070*_t59 - _t1076*_t478 - _t1077*_t217 - _t1078*_t463 - _t1079*_t1080 - _t1081*_t135 - _t1082*nb - 0.7e1 / 0.12e2*_t1083 - _t1084*nb - _t1085*nb + 0.2e1*_t121*_t20*_t225*_t226*_t256*_t308 - _t131*_t926 + 0.4e1*_t20*_t203*_t225*_t226*_t256*_t308 + 0.16e2*M_PI*_t206*_t38*_t48*na + 0.8e1*M_PI*_t38*_t48*_t526*na*nb - _t447*_t527 - _t454*_t521 - _t524 - _t525 - _t706*_t727*nb - _t917*na - 0.40e2 / 0.3e1*_t928 - 0.20e2 / 0.3e1*_t929 - 0.160e3 / 0.3e1*_t931 - 0.80e2 / 0.3e1*_t932 - 0.20e2 / 0.3e1*_t934 - _t937) - 0.320e3 / 0.27e2*_t802 - 0.224e3 / 0.27e2*_t803;
  const double _t1116 = _t418*_t544;
  const double _t1117 = _t142*_t508;
  const double _t1147 = _t527*_t681;
  const double _t1148 = _hc15[1]*_t1119 + 0.3e1*_hc17[3]*_t194*_t509 - _t693;
  const double _t1152 = _t10*_t1148;
  const double _t1153 = _t1152*_t39;
  const double _t1154 = _t459*_t481;
  const double _t1155 = (0.80e2 / 0.3e1)*_t728;
  const double _t1166 = _hc13[1]*_t539;
  const double _t1174 = _t1001*_t1107 + _t1002*_t1170 + _t1002*_t1171 + _t1004*_t1120 + _t1005*_t1126 + _t1005*_t509 - _t1034*_t888 - 0.224e3 / 0.9e1*_t1037 + _t1105*_t1169 + _t1120*_t792 + _t1120*_t997 + _t1144*_t542 + _t1160*_t170 + _t1161*_t766 + _t1164*_t994 + _t1165*_t386 + _t1166*_t1167 + _t1168*_t998 - _t1172*_t404 - _t1173*na + _t24*(_hc11[1]*_t1119 - _t1094 + _t1095*_t194 + _t1142*_t484 + _t485*_t740 + _t739) - _t318*_t795 + _t37*(0.16e2*_hc14[1]*_t103*_t109*_t144*_t206*_t3*na + 0.8e1*_hc14[1]*_t103*_t109*_t144*_t3*_t526*na*nb + 0.16e2*_hc14[1]*_t109*_t113*_t203*_t3*_t5 - _t1088*_t1153 + 0.4e1*_t1143*_t38 - _t1149*_t337 - _t1151*_t530 - _t1154*_t718 - _t1155*_t460 + 0.10e2*_t203*_t225*_t226*_t256*_t308*_t59 + 0.12e2*M_PI*_t206*_t29*_t48*na + 0.6e1*M_PI*_t29*_t48*_t526*na*nb - _t460*_t725 - _t719*na - _t737 - 0.80e2 / 0.3e1*_t947 - 0.28e2 / 0.3e1*_t949) + _t44*(-_t1*_t1141 + _t1066*_t614 - _t281*_t504*_t615 - _t519*_t546 - _t605*na - _t607*na - _t608*na + _t612*_t884 - _t619*na + _t643 - 0.7e1 / 0.5e1*_t882 - 0.160e3 / 0.3e1*_t891) + _t539*_t994 + _t58*((0.1e1 / 0.2e1)*_hc14[1]*_t103*_t118*_t144*_t204*_t3 + (0.3e1 / 0.4e1)*_hc14[1]*_t103*_t144*_t2*_t3*_t523 + 0.48e2*_hc14[1]*_t109*_t113*_t144*_t206*_t3*na + 0.24e2*_hc14[1]*_t109*_t113*_t144*_t3*_t526*na*nb + 0.16e2*_hc14[1]*_t109*_t139*_t203*_t3*_t5 - _t1*_t1146 - _t1080*_t1148 - 0.7e1 / 0.8e1*_t1083 + 0.6e1*_t1143*_t59 - _t1147*na - _t1149*_t315 - _t1150*_t459 + 0.6e1*_t20*_t203*_t225*_t226*_t256*_t308 + 0.48e2*M_PI*_t206*_t38*_t48*na + 0.24e2*M_PI*_t38*_t48*_t526*na*nb - _t460*_t704 - _t460*_t707 - _t523*_t660 - _t685*na - _t716 - 0.20e2*_t928 - 0.80e2*_t931) - _t805*na + _t820;
  const double _t1175 = _t1174*_t23;
  const double d3F_dna3 = _t1*_t822 + 0.3e1*_t417 - 0.2e1 / 0.3e1*_t824 + _t825*_t826 + (0.8e1 / 0.3e1)*_t827 + _t828*_t830 + _t841;
  const double d3F_dna2_dnb = _t1040*_t1041 - 0.2e1 / 0.9e1*_t1042 + _t1043*_t1044 + _t1045*_t828 + _t1047 + _t191*_t825 + _t417 + _t423*_t508 - 0.4e1 / 0.9e1*_t824 + (0.16e2 / 0.9e1)*_t827;
  const double d3F_dna_dnb2 = _t1041*_t1115 - 0.4e1 / 0.9e1*_t1042 + _t1043*_t828 + _t1044*_t1045 + _t1047 + _t1116*_t191 + (0.16e2 / 0.9e1)*_t1117 + _t419*_t423 + _t545 - 0.2e1 / 0.9e1*_t824;
  const double d3F_dnb3 = _t1*_t1175 - 0.2e1 / 0.3e1*_t1042 + _t1044*_t830 + _t1116*_t826 + (0.8e1 / 0.3e1)*_t1117 + 0.3e1*_t545 + _t841;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t1177 = 0.384e3*_t585;
  const double _t1178 = (0.4e1 / 0.9e1)*_t589;
  const double _t1179 = (0.2096e4 / 0.27e2)*_t594;
  const double _t1180 = 0.480e3*_t589;
  const double _t1181 = xc_powi(_t1, -7);
  const double _t1182 = _t108*_t1181;
  const double _t1183 = xc_powr(_t1, -22, 3);
  const double _t1184 = (0.1e1 / _t67);
  const double _t1185 = _t1184*_t3;
  const double _t1186 = (0.1e1 / 0.54e2)*_t1183*_t1185*_t26;
  const double _t1187 = xc_powr(_t1, -20, 3);
  const double _t1188 = (0.772e3 / 0.81e2)*_t1187*_t227*_t26;
  const double _t1189 = xc_powr(_t1, -19, 3);
  const double _t1190 = _t1189*_t6;
  const double _t1191 = (0.9680e4 / 0.81e2)*_t1190*nb;
  const double _t1193 = (_t79 * _t79 * _t79 * _t79);
  const double _t1195 = _t585*_t9;
  const double _t1196 = 0.24e2*_t1195;
  const double _t1197 = _t1196 - _t222;
  const double _t1198 = (_t239 * _t239);
  const double _t1200 = _t551*_t79;
  const double _t1202 = _t9*_t958;
  const double _t1203 = _t1202 - _t718;
  const double _t1204 = -_t1203;
  const double _t1206 = 0.6e1*_t48;
  const double _t1207 = _t1151 - _t717;
  const double _t1208 = -_t1206 + _t1207*_t87;
  const double _t1210 = -_t335 + _t529;
  const double _t1211 = _t1210*_t87 - _t49;
  const double _t1212 = _t209 - _t39;
  const double _t1213 = _t1212*_t87 - _t149;
  const double _t1215 = (0.2e1 / 0.9e1)*_t558;
  const double _t1216 = (0.1e1 / 0.216e3)*_t1185;
  const double _t1217 = (0.40e2 / 0.81e2)*_t227;
  const double _t1218 = (0.140e3 / 0.81e2)*_t6;
  const double _t1220 = (0.1e1 / 0.24e2)*_t227;
  const double _t1229 = _t101/xc_powr(M_PI, 5, 6);
  const double _t1231 = _t589*na;
  const double _t1233 = _t1231*_t621;
  const double _t1234 = _t1189*_t1229;
  const double _t1236 = _t589*_t621;
  const double _t1238 = _t26*_t597;
  const double _t1240 = _t26*_t593;
  const double _t1241 = _t1234*_t26;
  const double _t1244 = _t1238*_t259;
  const double _t1247 = (0.140e3 / 0.81e2)*_t232;
  const double _t1250 = (0.2e1 / 0.3e1)*_t353;
  const double _t1269 = (0.8e1 / 0.15e2)*_t2;
  const double _t1283 = _t1247*_t6;
  const double _t1299 = 0.192e3*_t585;
  const double _t1325 = _t585*nb;
  const double _t1336 = (0.160e3 / 0.3e1)*_t91;
  const double _t1371 = (0.7e1 / 0.12e2)*_t370;
  const double _t1379 = _t1193*_t373;
  const double _t1392 = _t239*_t79;
  const double _t1394 = _t563*_t79;
  const double _t1408 = 0.6e1*_t373;
  const double _t1412 = (0.1e1 / 0.2e1)*_t161;
  const double _t1426 = 0.12e2*_t551;
  const double _t1449 = _t1325*_t621;
  const double _t1452 = (0.448e3 / 0.9e1)*_t28;
  const double _t1457 = _t232*nb;
  const double _t1485 = 0.288e3*_t585;
  const double _t1486 = _t1196 - _t958;
  const double _t1487 = -_t1486;
  const double _t1488 = (0.1e1 / 0.3e1)*_t589;
  const double _t1489 = _t588*na;
  const double _t1490 = _t552*_t847;
  const double _t1491 = _t79*_t845;
  const double _t1492 = _t1202 - 0.4e1*_t87;
  const double _t1493 = -_t1492;
  const double _t1494 = _t429*_t9;
  const double _t1496 = (0.524e3 / 0.9e1)*_t594;
  const double _t1497 = (0.10e2 / 0.3e1)*nb;
  const double _t1498 = (0.10e2 / 0.9e1)*na;
  const double _t1499 = (0.3e1 / 0.2e1)*_t870;
  const double _t1506 = (0.1e1 / 0.144e3)*_t558;
  const double _t1523 = _t852*_t9;
  const double _t1534 = 0.2e1*_t845;
  const double _t1539 = _t563*_t9;
  const double _t1541 = _t239*_t9;
  const double _t1545 = _t240*_t9;
  const double _t1549 = _t9*_t91;
  const double _t1551 = _t476*_t563;
  const double _t1568 = _t239*_t503;
  const double _t1613 = 0.36e2*_t221;
  const double _t1621 = 0.16e2*nb;
  const double _t1642 = (0.7e1 / 0.24e2)*_t370;
  const double _t1643 = (0.1e1 / 0.4e1)*_t161;
  const double _t1647 = _t978*_t983;
  const double _t1649 = _t194*_t551;
  const double _t1650 = _t16*_t490;
  const double _t1651 = _t1650*_t9;
  const double _t1669 = _t373*_t476;
  const double _t1670 = _t1669*_t385;
  const double _t1687 = _t784*_t847;
  const double _t1700 = _t194*_t563;
  const double _t1758 = 0.96e2*_t221;
  const double _t1760 = (0.4e1 / 0.9e1)*_t228;
  const double _t1761 = (0.128e3 / 0.9e1)*_t233;
  const double _t1762 = (0.1048e4 / 0.27e2)*_t594;
  const double _t1766 = 0.6e1*_t1195;
  const double _t1768 = (_t9 * _t9);
  const double _t1769 = _t1768*_t588;
  const double _t1770 = 0.2e1*_t1769;
  const double _t1771 = _t240*_t510;
  const double _t1772 = _t1212*_t87 + _t149;
  const double _t1773 = _t1213*_t510;
  const double _t1774 = 0.3e1*_t548;
  const double _t1785 = (0.28e2 / 0.27e2)*_t92;
  const double _t1795 = _t194*_t845;
  const double _t1796 = _t476*_t9;
  const double _t1798 = 0.64e2*_t87;
  const double _t1850 = _t1768/xc_powr(_t1, 37, 6);
  const double _t1851 = (0.7e1 / 0.72e2)*_t370;
  const double _t1857 = _t1075*_t978;
  const double _t1859 = _t509*_t79;
  const double _t1867 = 0.24e2*_t1650*_t1796;
  const double _t1874 = 0.36e2*_t548;
  const double _t1876 = 0.6e1*_t194;
  const double _t1884 = _t1075*_t852;
  const double _t1901 = (0.10e2 / 0.3e1)*na;
  const double _t1902 = (0.10e2 / 0.9e1)*nb;
  const double _t1910 = (0.14e2 / 0.9e1)*_t92;
  const double _t1913 = _t1120*_t784;
  const double _t1916 = _t509*_t9;
  const double _t1917 = _t510*_t9;
  const double _t1918 = _t1144*_t79;
  const double _t1938 = _t1669*_t541;
  const double _t1941 = 0.54e2*_t548;
  const double _t1951 = (_t194 * _t194 * _t194 * _t194);
  const double _t1952 = _t1196 + _t222;
  const double _t1953 = (_t509 * _t509);
  const double _t1954 = _t1202 + _t718;
  const double _t1955 = -_t1954;
  const double _t1956 = _t1126*_t509;
  const double _t1958 = _t1210*_t87 + _t49;
  const double _t1959 = _t1206 + _t1207*_t87;
  const double _t1965 = _t1119*_t194;
  const double _t1966 = _t194*_t1955;
  const double _t1971 = _t1951*_t373;
  const double _t1176 = (0.3e1 / 0.5e1)*_t33;
  const double _t1192 = _hc5[2]*_t1188 + _hc5[4]*_t1186 + _t1180*_t89 + _t1182*_t590 + _t1191*_t94;
  const double _t1194 = _hc1[14]*_t75;
  const double _t1199 = _hc3[14]*_t81;
  const double _t1201 = (0.1e1 / 0.2e1)*_t854;
  const double _t1205 = _t239*_t241;
  const double _t1209 = _t240*_t553;
  const double _t1214 = _t242*_t244;
  const double _t1219 = (0.1e1 / 0.3e1)*_t865;
  const double _t1221 = _hc2[2]*_t1220*_t245;
  const double _t1222 = _hc1[5]*_t79;
  const double _t1223 = _t1222*_t85;
  const double _t1224 = -_hc1[9]*_t552*_t85 - _hc2[1]*_t568*_t80 - _hc2[3]*_t560*_t80 + _hc2[4]*_t1216*_t52/xc_powr(na, 16, 3) + _t1193*_t1194 + _t1197*_t195 - _t1197*_t196 + _t1198*_t241 + _t1199*(_t78 * _t78 * _t78 * _t78) + (0.1e1 / 0.2e1)*_t1200*_t851 + _t1201*_t550*_t78 + _t1203*_t436 + _t1204*_t435 + _t1205*_t563 + _t1208*_t1209 + _t1209*_t1211 + _t1209*_t1213 + _t1214*_t564 + _t1215*_t556/xc_powi(na, 5) + _t1217*_t247/xc_powr(na, 14, 3) + _t1218*_t565/xc_powr(na, 13, 3) + _t1219*_t577 + _t1219*_t579 + _t1221*_t577 + _t1221*_t579 - _t1223*_t239 - _t1223*_t563 + (_t242 * _t242)*_t244 + _t242*_t850 - _t551*_t871 + _t564*_t850 - _t572*_t582 + _t850*(_t1206 - _t503);
  const double _t1232 = _t1231*_t628;
  const double _t1235 = _hc6[4]*_t1234;
  const double _t1237 = _t1236*_t504;
  const double _t1239 = _hc6[2]*_t1238;
  const double _t1243 = _hc6[1]*_t1241;
  const double _t1245 = _hc6[1]*_t1244;
  const double _t1248 = _t117*_t1247;
  const double _t1249 = _t647*_t91;
  const double _t1251 = _hc7[5]*_t691;
  const double _t1252 = -_t1251;
  const double _t1253 = _hc7[9]*_t310;
  const double _t1254 = -_hc7[14]*_t133;
  const double _t1255 = -_hc7[13]*_t133;
  const double _t1256 = _hc7[12]*_t79 + _t1255;
  const double _t1257 = _hc7[8]*_t310;
  const double _t1258 = -_hc7[12]*_t133;
  const double _t1259 = _hc7[11]*_t79 + _t1258;
  const double _t1260 = _hc7[7]*_t239 - _t1256*_t133 + _t1257 + _t1259*_t79;
  const double _t1261 = _hc7[4]*_t691;
  const double _t1262 = -_t1261;
  const double _t1263 = _hc7[7]*_t310;
  const double _t1264 = -_hc7[11]*_t133;
  const double _t1265 = _hc7[1]*_t1197 + _t1248 - 0.14e2 / 0.9e1*_t1249 + _t1250*_t654 - _t133*(_hc7[4]*_t551 + _t1252 + _t1260*_t79 - _t133*(_hc7[8]*_t239 + _t1253 + _t1256*_t79 - _t133*(_hc7[13]*_t79 + _t1254)) + _t648*_t653 + _t651*_t740) + _t290*_t774 + _t385*_t658 + _t79*(_hc7[3]*_t551 - _t1260*_t133 + _t1262 + _t648*_t657 + _t653*_t740 + _t79*(_hc7[6]*_t239 - _t1259*_t133 + _t1263 + _t79*(_hc7[10]*_t79 + _t1264)));
  const double _t1266 = (0.3e1 / 0.4e1)*_t40;
  const double _t1267 = _hc9[10]*_t294;
  const double _t1268 = _t109*_t298;
  const double _t1270 = _t1269*_t297;
  const double _t1271 = _hc9[6]*_t664;
  const double _t1272 = _t1271*_t552;
  const double _t1273 = _t240*_t661;
  const double _t1274 = _t239*_t297;
  const double _t1275 = _t79*_t908;
  const double _t1276 = _t1269*_t1275;
  const double _t1277 = (0.2e1 / 0.5e1)*_t66*_t908;
  const double _t1278 = _t239*_t475;
  const double _t1279 = _hc8[2]*_t1188 + _hc8[4]*_t1186 + _t1180*_t125 + _t1182*_t671 + _t1191*_t129 + (0.56e2 / 0.405e3)*_t126*_t91;
  const double _t1286 = 0.16e2*_t659;
  const double _t1289 = 0.96e2*_t26*_t60;
  const double _t1292 = (0.448e3 / 0.9e1)*_t121;
  const double _t1300 = _t1077*_t1299*na;
  const double _t1301 = _t589*_t927;
  const double _t1305 = _t1190*_t966;
  const double _t1309 = _t593*_t966;
  const double _t1313 = 0.8e1*_t40;
  const double _t1315 = _t150*nb;
  const double _t1317 = _t961*nb;
  const double _t1319 = 0.24e2*_t943;
  const double _t1320 = _t10*_t1089;
  const double _t1321 = _t1313*_t26*_t48;
  const double _t1332 = _t224*_t946;
  const double _t1334 = _t232*_t946;
  const double _t1345 = _hc7[0]*_t585;
  const double _t1352 = _hc11[2]*_t1283;
  const double _t1353 = _t364*_t92;
  const double _t1354 = _hc11[5]*_t691;
  const double _t1355 = -_t1354;
  const double _t1356 = _hc11[9]*_t310;
  const double _t1357 = -_hc11[14]*_t133;
  const double _t1358 = -_hc11[13]*_t133;
  const double _t1359 = _hc11[12]*_t79 + _t1358;
  const double _t1360 = _hc11[8]*_t310;
  const double _t1361 = -_hc11[12]*_t133;
  const double _t1362 = _hc11[11]*_t79 + _t1361;
  const double _t1363 = _hc11[7]*_t239 - _t133*_t1359 + _t1360 + _t1362*_t79;
  const double _t1364 = _hc11[4]*_t691;
  const double _t1365 = -_t1364;
  const double _t1366 = _hc11[7]*_t310;
  const double _t1367 = -_hc11[11]*_t133;
  const double _t1368 = (0.1729e4 / 0.2592e4)*_t17*_t978;
  const double _t1369 = _t491*_t79;
  const double _t1370 = _t167*_t239;
  const double _t1372 = _t167*_t768;
  const double _t1373 = _hc12[10]*_t380;
  const double _t1374 = _t166*_t379;
  const double _t1375 = _t166*_t754;
  const double _t1376 = _hc12[3]*_t552;
  const double _t1377 = _hc12[1]*_t375;
  const double _t1378 = _t1376*_t1377*_t760;
  const double _t1380 = 0.4e1*_t1377;
  const double _t1381 = _hc12[6]*_t1380;
  const double _t1382 = 0.12e2*((_hc12[1]) * (_hc12[1]) * (_hc12[1]) * (_hc12[1]))/xc_powi((_hc12[0]), 5);
  const double _t1383 = _t758*_t760;
  const double _t1384 = _t16*_t376;
  const double _t1385 = _t1384*_t240;
  const double _t1386 = _t1385*_t370;
  const double _t1387 = ((_hc12[3]) * (_hc12[3]));
  const double _t1388 = _t1193*_t1387;
  const double _t1389 = _t375*_t759;
  const double _t1390 = 0.18e2*_t755;
  const double _t1391 = _hc12[3]*_t1390*_t374;
  const double _t1393 = _t768*_t984;
  const double _t1395 = _t377*_t79;
  const double _t1396 = (0.2e1 / 0.3e1)*_t761;
  const double _t1397 = 0.2e1*_t377;
  const double _t1398 = _t239*_t489;
  const double _t1399 = _t239*_t377;
  const double _t1400 = _hc12[6]*_t240;
  const double _t1401 = _t1400*_t380;
  const double _t1402 = _hc12[1]*_t1389;
  const double _t1403 = _t1402*_t379;
  const double _t1404 = _t240*_t756;
  const double _t1405 = _t1404*_t988;
  const double _t1407 = (0.91e2 / 0.216e3)*_t751;
  const double _t1409 = _t79*_t992;
  const double _t1411 = (0.7e1 / 0.24e2)*_t371;
  const double _t1413 = _t167*_t784;
  const double _t1414 = _t1213*_t767;
  const double _t1415 = -_t1213*_t168 + _t1413*_t368 + _t381;
  const double _t1420 = 0.36e2*_t374;
  const double _t1428 = 0.12e2*_t172;
  const double _t1432 = 0.18e2*_t172;
  const double _t1433 = _t1432*_t382;
  const double _t1436 = 0.18e2*_t164;
  const double _t1437 = _hc12[0]*_hc12[1];
  const double _t1441 = _t1428*_t395;
  const double _t1444 = _t391*_t395;
  const double _t1445 = 0.24e2*_t1444;
  const double _t1446 = 0.72e2*_t1437;
  const double _t1447 = _t806*nb;
  const double _t1448 = _t1325*_t177*_t628;
  const double _t1450 = _hc6[2]*_t1449;
  const double _t1451 = _t811*nb;
  const double _t1454 = _t1449*_t38;
  const double _t1455 = _hc6[0]*_t1449;
  const double _t1458 = _t1457*_t178;
  const double _t1459 = _t641*nb;
  const double _t1462 = _t801*_t816;
  const double _t1466 = (0.80e2 / 0.3e1)*_t424;
  const double _t1478 = (0.40e2 / 0.3e1)*_t424;
  const double _t1495 = _t1494*_t851;
  const double _t1500 = _hc3[9]*_hc4[0];
  const double _t1501 = _t1499*_t1500;
  const double _t1502 = _t1501*_t243;
  const double _t1503 = _t1494*_t854;
  const double _t1504 = _t1503*_t242;
  const double _t1505 = _t1503*_t564;
  const double _t1507 = _hc2[3]*_t1506*_t437*_t557;
  const double _t1508 = _t476*_t553;
  const double _t1509 = _t1060*_t555;
  const double _t1510 = _hc1[9]*_hc2[0];
  const double _t1511 = (0.7e1 / 0.54e2)*_hc2[1]*_t437*_t566*_t6;
  const double _t1512 = _hc1[2]*_t576*_t845;
  const double _t1513 = _t550*_t861;
  const double _t1514 = _hc3[9]*_t442*_t554;
  const double _t1515 = _t246*_t570*_t867;
  const double _t1516 = _hc1[5]*_t576*_t981;
  const double _t1517 = _hc1[9]*_t576*_t848;
  const double _t1518 = _hc3[5]*_t78;
  const double _t1519 = _t1518*_t442;
  const double _t1520 = _t1519*_t242;
  const double _t1521 = _t1519*_t564;
  const double _t1522 = _hc1[2]*_t870;
  const double _t1524 = _t7*_t84;
  const double _t1525 = _hc1[5]*_t1523*_t1524;
  const double _t1528 = _hc7[11]*_t194 + _t1258;
  const double _t1529 = _hc7[12]*_t194 + _t1255;
  const double _t1530 = _t1257 - _t133*_t1529;
  const double _t1531 = _hc7[7]*_t238 + _t1528*_t79 + _t1530;
  const double _t1532 = _hc7[10]*_t194 + _t1264;
  const double _t1533 = _t1263 - _t133*_t1528;
  const double _t1535 = _t1253 - _t133*(_hc7[13]*_t194 + _t1254);
  const double _t1536 = _t1248 + _t740*_t899;
  const double _t1537 = _hc7[1]*_t1486 - 0.28e2 / 0.27e2*_t1249 - _t133*(_hc7[4]*_t845 + _t1252 - _t133*(_hc7[8]*_t238 + _t1529*_t79 + _t1535) + _t1531*_t79 + _t238*_t653 + _t239*_t896 + _t310*_t651 + _t310*_t897) + _t1534*_t290 + _t1536 + _t238*_t658 + _t310*_t654 + _t464*_t551 - _t465*_t691 + _t648*_t902 + _t79*(_hc7[3]*_t845 + _t1262 - _t133*_t1531 + _t238*_t657 + _t239*_t900 + _t310*_t653 + _t310*_t896 + _t79*(_hc7[6]*_t238 + _t1532*_t79 + _t1533));
  const double _t1538 = _t1489*_t671;
  const double _t1540 = (0.2e1 / 0.5e1)*_t909;
  const double _t1542 = _t908*_t981;
  const double _t1543 = _t1271*_t848;
  const double _t1544 = _t127*_t1275;
  const double _t1546 = _t109*_t1271;
  const double _t1547 = (0.6e1 / 0.5e1)*_t1546;
  const double _t1548 = (0.8e1 / 0.5e1)*_t908;
  const double _t1550 = _hc9[6]*_t474;
  const double _t1552 = _t1550*_t476;
  const double _t1553 = -0.72e2*_hc8[0]*_t221 - 0.480e3*_hc8[0]*_t588*na*nb - 0.9680e4 / 0.81e2*_hc8[1]*_t1189*_t3*_t5*na*nb - 0.32e2 / 0.3e1*_hc8[1]*_t232*_t3*_t5 - 0.772e3 / 0.81e2*_hc8[2]*_t1187*_t225*_t226*na*nb - 0.1e1 / 0.3e1*_hc8[2]*_t224*_t225*_t226 - 0.16e2 / 0.9e1*_hc8[3]*_t1181*_t558*na*nb - 0.1e1 / 0.54e2*_hc8[4]*_t1183*_t1184*_t3*na*nb - 0.56e2 / 0.405e3*_hc9[0]*_t64*_t67*_t91 - 0.2e1 / 0.15e2*_hc9[3]*_t118*_t194*_t64*_t67*_t79;
  const double _t1559 = _t317*na;
  const double _t1563 = _t961*na;
  const double _t1566 = _t26*_t698;
  const double _t1567 = 0.12e2*_t903;
  const double _t1571 = _t208*_t48;
  const double _t1573 = _t26*_t681;
  const double _t1578 = (0.112e3 / 0.3e1)*_t121;
  const double _t1579 = (0.112e3 / 0.9e1)*_t203;
  const double _t1592 = _t224*_t927;
  const double _t1595 = _t232*_t927;
  const double _t1609 = 0.6e1*_t40;
  const double _t1612 = 0.12e2*_t40;
  const double _t1616 = _t718*_t943;
  const double _t1617 = _t1206*_t943;
  const double _t1633 = _hc11[11]*_t194 + _t1361;
  const double _t1634 = _hc11[12]*_t194 + _t1358;
  const double _t1635 = -_t133*_t1634 + _t1360;
  const double _t1636 = _hc11[7]*_t238 + _t1633*_t79 + _t1635;
  const double _t1637 = _hc11[10]*_t194 + _t1367;
  const double _t1638 = -_t133*_t1633 + _t1366;
  const double _t1639 = -_t133*(_hc11[13]*_t194 + _t1357) + _t1356;
  const double _t1640 = _t1352 + _t740*_t974;
  const double _t1641 = _t167*_t9/xc_powr(_t1, 31, 6);
  const double _t1644 = _t1643*_t167;
  const double _t1645 = _t162*_t167;
  const double _t1646 = _t194*_t491;
  const double _t1648 = _t1647*_t984;
  const double _t1652 = _t1390*_t1651;
  const double _t1653 = _hc12[6]*_t166*_t490;
  const double _t1654 = 0.3e1*_t1653;
  const double _t1655 = _t1384*_t1647;
  const double _t1656 = _t1384*_t490;
  const double _t1657 = _t1387*_t1389;
  const double _t1658 = _t1382*_t373;
  const double _t1659 = _t761*_t981;
  const double _t1660 = (0.1e1 / 0.6e1)*_t761;
  const double _t1661 = _t981*_t984;
  const double _t1662 = _t166*_t982;
  const double _t1663 = _t162*_t984;
  const double _t1664 = _t755*_t760;
  const double _t1665 = _t1664*_t987;
  const double _t1666 = _t1391*_t373;
  const double _t1667 = _t756*_t988;
  const double _t1668 = _t755*_t756;
  const double _t1671 = _t754*_t847;
  const double _t1672 = 0.18e2*_t1377*_t1651;
  const double _t1673 = _hc12[3]*_t848;
  const double _t1674 = _t1377*_t760;
  const double _t1675 = _t1673*_t1674;
  const double _t1676 = _hc12[6]*_t380;
  const double _t1677 = _t1676*_t476;
  const double _t1678 = _hc12[3]*_t1402;
  const double _t1679 = _hc12[3]*_t1377;
  const double _t1680 = _t476*_t984;
  const double _t1681 = _t1384*_t476;
  const double _t1682 = _t1368 + _t1371*_t1681 - _t1642*_t1680;
  const double _t1683 = 0.4e1*_t985;
  const double _t1684 = _t1408*_t755;
  const double _t1685 = -0.1e1 / 0.3e1*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t194*_t79*p->cam_omega + _t1407 + (0.2e1 / 0.3e1)*_t989;
  const double _t1688 = _t1687*_t377;
  const double _t1692 = _t1413*_t162 + _t1645*_t847 - _t1687*_t489 + _t1688 + _t493;
  const double _t1696 = _t169*_t194;
  const double _t1697 = _t1696*_t173;
  const double _t1698 = _hc12[3]*_t497;
  const double _t1711 = _hc12[3]*_t788;
  const double _t1712 = _t1711*_t194;
  const double _t1717 = 0.18e2*_t1016;
  const double _t1718 = 0.18e2*_t391;
  const double _t1719 = _t1436*_t870;
  const double _t1721 = _t806*na;
  const double _t1724 = _t795*_t843;
  const double _t1725 = _t1437*_t1673;
  const double _t1726 = _t1523*_t391;
  const double _t1727 = 0.108e3*_t1437*_t870;
  const double _t1728 = _t807*na;
  const double _t1730 = _t809*na;
  const double _t1732 = _t1031*_t810;
  const double _t1734 = _t808*_t880;
  const double _t1736 = _t504*_t808;
  const double _t1738 = _t178*_t232*na;
  const double _t1740 = _t641*na;
  const double _t1743 = _t1036*_t640;
  const double _t1759 = (0.2e1 / 0.9e1)*_t590;
  const double _t1763 = (0.20e2 / 0.9e1)*_t599;
  const double _t1764 = (0.1e1 / 0.2e1)*_t1053;
  const double _t1765 = _t1201*_t193;
  const double _t1767 = _t1766*_t432;
  const double _t1775 = _t1057*_t440;
  const double _t1776 = _hc3[2]*_t242;
  const double _t1777 = _hc2[2]*_t869;
  const double _t1778 = _hc1[2]*_t1524*_t548 - 0.1e1 / 0.3e1*_hc1[5]*_t1114*_t251 - _hc1[9]*_t1051*_t252 - _hc3[2]*_t517*_t844 - _hc3[9]*_t193*_t243*_t517 + _t1052*_t242 + _t1054*_t1777 + _t1054*_t866 + _t1055*_t1777 + _t1055*_t866 + _t1059*_t1776 + _t1059*_t863 - _t1060*_t1500*_t238 - _t1061*_t193*_t242 + _t1194*_t1771 + _t1199*_t243*_t512 + _t1205*_t509 + _t1209*_t1772 + _t1214*_t511 - _t1222*_t252*_t509 + _t1510*_t238*_t476 + (0.1e1 / 0.3e1)*_t1518*_t441*_t870 + _t1764*_t845 + _t1765*_t844 + _t1766*_t430 - _t1767 + _t1770*_t851 + _t1770*_t854 + _t1773*_t553 + _t1774*_t78*_t854 - _t1774*_t79*_t851 + _t1775*_t1776 + _t1775*_t863 + _t511*_t850 - _t853 + _t856 + _t87*_t871;
  const double _t1781 = _hc7[1]*_t1196;
  const double _t1782 = _hc7[7]*_t509 + _t1528*_t194 + _t1530;
  const double _t1783 = _t133*_t1782;
  const double _t1784 = _hc7[6]*_t509 + _t1532*_t194 + _t1533;
  const double _t1786 = _t133*(_hc7[8]*_t509 + _t1529*_t194 + _t1535);
  const double _t1787 = _t1067*_t310 + _t1069*_t239 - _t133*(-_hc7[4]*_t237 - _hc7[4]*_t549 + (0.4e1 / 0.9e1)*_t109*_t3*_t5*_t897 - _t1251 + _t1782*_t79 - _t1786 + 0.4e1*_t87*_t896*_t9) + _t1534*_t464 + _t1536 + _t1781 - _t1785*_t465 - _t237*_t290 - _t290*_t549 + _t562*_t902 - _t644*_t647 + _t79*(-_hc7[3]*_t237 - _hc7[3]*_t549 + (0.4e1 / 0.9e1)*_t109*_t3*_t5*_t896 - _t1261 - _t1783 + _t1784*_t79 + 0.4e1*_t87*_t9*_t900);
  const double _t1788 = _hc8[3]*_t1215;
  const double _t1789 = _t232*_t297*_t9;
  const double _t1790 = (0.20e2 / 0.9e1)*_t674;
  const double _t1791 = _t109*_t473;
  const double _t1792 = _t297*_t509;
  const double _t1793 = _t1275*_t509;
  const double _t1794 = _t1051*_t1271;
  const double _t1799 = _t1798*_t60;
  const double _t1811 = _t915*na;
  const double _t1820 = (0.64e2 / 0.3e1)*_t467;
  const double _t1835 = _t1088*_t335;
  const double _t1844 = _hc11[1]*_t1196;
  const double _t1845 = _hc11[7]*_t509 + _t1633*_t194 + _t1635;
  const double _t1846 = _t133*_t1845;
  const double _t1847 = _hc11[6]*_t509 + _t1637*_t194 + _t1638;
  const double _t1848 = _t133*(_hc11[8]*_t509 + _t1634*_t194 + _t1639);
  const double _t1849 = _t167*_t978;
  const double _t1852 = _t167*_t509;
  const double _t1853 = _t167*_t368;
  const double _t1854 = _t166*_t537;
  const double _t1855 = _t1384*_t510;
  const double _t1856 = _t1855*_t370;
  const double _t1858 = _t1384*_t1857;
  const double _t1860 = _t1859*_t984;
  const double _t1861 = _t1098*_t166;
  const double _t1862 = _t1099*_t1664;
  const double _t1863 = _t1859*_t761;
  const double _t1864 = _hc12[3]*_t1051;
  const double _t1865 = _t1674*_t1864;
  const double _t1866 = _t1381*_t373;
  const double _t1869 = -_t168*_t1772 + _t1853*_t847 + _t538;
  const double _t1870 = _t172*_t382;
  const double _t1871 = _t387*_t537;
  const double _t1881 = _t1013*_t194;
  const double _t1882 = 0.24e2*_t1016;
  const double _t1883 = 0.24e2*_t172*_t870;
  const double _t1886 = 0.24e2*_t391;
  const double _t1888 = _t1437*_t1864;
  const double _t1889 = _t1016*_t870;
  const double _t1900 = _t1489*_t590;
  const double _t1903 = _hc3[2]*_t441;
  const double _t1904 = (0.1e1 / 0.3e1)*_t440*_t515;
  const double _t1905 = _hc3[2]*_t870;
  const double _t1906 = _hc1[5]*_t438;
  const double _t1907 = _t1058*_t1220;
  const double _t1908 = -0.1e1 / 0.4e1*_hc1[14]*_hc2[0]*_t1120*_t784 - 0.3e1*_hc1[2]*_hc2[0]*_t221 - 0.6e1*_hc1[2]*_hc2[0]*_t585*_t9 + _hc1[2]*_t1119*_t438 - 0.1e1 / 0.4e1*_hc1[5]*_hc2[0]*_t1119*_t79 - 0.3e1 / 0.2e1*_hc1[5]*_hc2[0]*_t509*_t87*_t9 - 0.1e1 / 0.4e1*_hc1[9]*_hc2[0]*_t1126*_t194*_t79 - 0.1e1 / 0.4e1*_hc1[9]*_hc2[0]*_t194*_t509*_t79 - 0.3e1 / 0.2e1*_hc1[9]*_hc2[0]*_t510*_t87*_t9 + _hc1[9]*_t1120*_t438 - 0.1e1 / 0.4e1*_hc3[14]*_hc4[0]*_t1121*_t78 - 0.1e1 / 0.4e1*_hc3[5]*_hc4[0]*_t1118*_t78 - 0.9e1 / 0.2e1*_hc3[5]*_hc4[0]*_t193*_t221*_t9 - 0.3e1 / 0.2e1*_hc3[5]*_hc4[0]*_t193*_t87 - 0.1e1 / 0.2e1*_hc3[5]*_hc4[1]*_t193*_t198*_t3*_t5*_t87*_t9 - 0.1e1 / 0.6e1*_hc3[5]*_hc4[1]*_t193*_t3*_t5*_t515*_t78 - 0.1e1 / 0.48e2*_hc3[5]*_hc4[2]*_t193*_t225*_t226*_t513*_t78 - 0.1e1 / 0.4e1*_hc3[9]*_hc4[0]*_t1127*_t193*_t78 - 0.1e1 / 0.4e1*_hc3[9]*_hc4[0]*_t193*_t511*_t78 + _hc3[9]*_t1134*_t512*_t78 + _hc4[2]*_t1131*_t246*_t82 + _hc4[3]*_t1123*_t1506*_t82 + (0.9e1 / 0.2e1)*_t1053*_t548 + (0.3e1 / 0.2e1)*_t1053*_t87 + (0.7e1 / 0.54e2)*_t1056*_t1128 + _t1134*_t1518*_t511 + _t1144*_t1906 + _t1159*_t1906 + _t1501*_t512 + _t1767 + (0.3e1 / 0.4e1)*_t1903*_t548 + (0.1e1 / 0.4e1)*_t1903*_t87 + _t1904*_t1905 + _t1905*_t1907 + 0.3e1*_t221*_t432 + (0.3e1 / 0.2e1)*_t511*_t855*_t9;
  const double _t1909 = _hc7[3]*_t1119 + _t1142*_t900 + _t1262 - _t1783 + _t1784*_t194 + _t740*_t896;
  const double _t1911 = _t1067*_t1250 + _t1248 - _t133*(_hc7[4]*_t1119 + _t1142*_t896 + _t1252 + _t1782*_t194 - _t1786 + _t740*_t897) - _t1910*_t465;
  const double _t1912 = _hc7[1]*_t958 + _t1069*_t503 - _t1103*_t464 + _t1781 + _t1909*_t79 + _t1911 - _t464*_t502;
  const double _t1914 = _t1120*_t1271;
  const double _t1915 = _t127*_t908;
  const double _t1920 = _t681*na;
  const double _t1921 = 0.12e2*_t1070;
  const double _t1923 = (0.112e3 / 0.3e1)*_t203;
  const double _t1924 = (0.112e3 / 0.9e1)*_t121;
  const double _t1931 = _hc11[3]*_t1119 + _t1142*_t975 + _t1365 - _t1846 + _t1847*_t194 + _t740*_t971;
  const double _t1932 = _t1093*_t1250 - _t133*(_hc11[4]*_t1119 + _t1142*_t971 + _t1355 + _t1845*_t194 - _t1848 + _t740*_t972) + _t1352 - _t1910*_t485;
  const double _t1933 = _t1158*_t760;
  const double _t1934 = _t1156*_t166;
  const double _t1935 = _t510*_t756;
  const double _t1936 = _hc12[3]*_t1120;
  const double _t1937 = _t1674*_t1936;
  const double _t1948 = _hc12[6]*_t510;
  const double _t1957 = _t510*_t553;
  const double _t1960 = _hc3[5]*_t1062*_t193;
  const double _t1961 = -_hc3[9]*_t1062*_t1121 - _hc4[2]*_t1132*_t516 - _hc4[3]*_t1124*_t516 + _hc4[4]*_t1216*_t53/xc_powr(nb, 16, 3) + _t1052*_t1127 + _t1052*_t511 + _t1052*(-_t1206 - _t503) - _t1063*_t1118 + _t1118*_t1765 + _t1119*_t1764 + _t1122*_t1215/xc_powi(nb, 5) - _t1127*_t1960 + _t1127*_t244*_t511 - _t1129*_t1139 + _t1135*_t1904 + _t1135*_t1907 + _t1137*_t1904 + _t1137*_t1907 + _t1194*_t1951 + _t1199*(_t193 * _t193 * _t193 * _t193) + _t1217*_t514/xc_powr(nb, 14, 3) + _t1218*_t197/xc_powr(nb, 13, 3) + _t1772*_t1957 + _t195*_t1952 - _t1952*_t196 + _t1953*_t241 + _t1954*_t849 + _t1955*_t846 + _t1956*_t241 + _t1957*_t1958 + _t1957*_t1959 - _t1960*_t511 + _t244*(_t511 * _t511);
  const double _t1962 = _hc7[1]*_t1952 + _t1069*_t541 + _t1165*_t464 + _t1909*_t194 + _t1911;
  const double _t1963 = _t510*_t661;
  const double _t1964 = _t1269*_t908;
  const double _t1969 = 0.16e2*_t1143;
  const double _t1970 = (0.448e3 / 0.9e1)*_t203;
  const double _t1972 = _t1948*_t380;
  const double _t1973 = _t1402*_t537;
  const double _t1974 = _t1935*_t988;
  const double _t1975 = _t1772*_t767;
  const double _t1978 = _t1428*_t194;
  const double _t1979 = _t1436*_t537;
  const double _t1981 = 0.36e2*_t1110;
  const double _t1225 = _t254*_t261;
  const double _t1226 = _t180*_t97;
  const double _t1227 = ((_hc14[1]) * (_hc14[1]) * (_hc14[1]) * (_hc14[1]));
  const double _t1228 = _t1227*_t59;
  const double _t1230 = _t1228*_t1229;
  const double _t1242 = _t1227*_t20;
  const double _t1246 = -0.56e2 / 0.135e3*_hc14[1]*_t100*_t103*_t14*_t55*_t91*_t99 + _hc6[0]*_t1234*_t1242*_t280 + (0.65920e5 / 0.81e2)*_hc6[0]*_t1244*_t635 + (0.80e2 / 0.9e1)*_hc6[2]*_t1241*_t635 + (0.32e2 / 0.27e2)*_hc6[3]*_t115*_t1234 + (0.26368e5 / 0.81e2)*_t114*_t1245 + (0.7e1 / 0.6e1)*_t1230*_t232*_t55 + _t1232*_t894 + 0.64e2*_t1233*_t634 + 0.320e3*_t1233*_t636 + (0.4e1 / 0.81e2)*_t1235*_t631 + (0.1280e4 / 0.3e1)*_t1237*_t638 + (0.6592e4 / 0.243e3)*_t1239*_t260 + (0.27136e5 / 0.243e3)*_t1240*_t271 + (0.54272e5 / 0.81e2)*_t1240*_t282 + (0.640e3 / 0.27e2)*_t1243*_t638 + (0.28e2 / 0.5e1)*_t221*_t622*_t624 + 0.256e3*_t263*_t632 + (0.112e3 / 0.135e3)*_t410*_t55;
  const double _t1280 = _t121*_t711;
  const double _t1281 = _t135*_t87;
  const double _t1282 = 0.3e1*_hc17[3];
  const double _t1284 = _hc16[2]*_t1283 + _t1250*_t687 - _t133*(-_hc16[5]*_t691 - _t133*(_hc16[14]*_t227*_t309 + _hc16[9]*_t310) - _t686*_t689) + (0.7e1 / 0.27e2)*_t224*_t307;
  const double _t1285 = _hc15[1]*_t1197 + _t1198*_t1282 + _t1284 + 0.4e1*_t551*_t918;
  const double _t1287 = _t121*_t20*_t712;
  const double _t1288 = _t312*_t87;
  const double _t1290 = _t303*_t700;
  const double _t1291 = _t131*_t343;
  const double _t1293 = _t135*nb;
  const double _t1294 = _t1293*_t325;
  const double _t1295 = 0.320e3*_t706;
  const double _t1296 = 0.40e2*_t325;
  const double _t1297 = 0.160e3*_t706;
  const double _t1298 = 0.7e1*_t221*_t624*_t70;
  const double _t1302 = 0.320e3*_t1301*_t638;
  const double _t1303 = (0.14e2 / 0.27e2)*_t358*_t70;
  const double _t1304 = (0.35e2 / 0.24e2)*_t1228*_t233*_t70;
  const double _t1306 = (0.40e2 / 0.3e1)*_t1242*_t1305;
  const double _t1307 = _t324*_t635;
  const double _t1308 = (0.8240e4 / 0.27e2)*_t1307*_t597*_t966;
  const double _t1310 = (0.13568e5 / 0.27e2)*_t1309*_t329;
  const double _t1311 = -0.32e2*_hc0[0]*_hc7[0]*_t558*_t585*_t623 - 0.1120e4 / 0.27e2*_hc14[1]*_hc7[0]*_t139*_t232*_t3*_t5 - 0.14e2 / 0.27e2*_hc14[1]*_t103*_t144*_t3*_t70*_t91 - 0.2e1 / 0.3e1*_hc7[0]*_t1184*_t1227*_t3*_t593 - 0.320e3 / 0.9e1*_hc7[0]*_t20*_t224*_t225*_t226*_t256 + _t1298 + _t1300 + _t1302 + _t1303 + _t1304 + _t1306 + _t1308 + _t1310;
  const double _t1312 = _t1281*_t481;
  const double _t1314 = _t312*_t48;
  const double _t1316 = _t121*_t730;
  const double _t1318 = _t1317*_t624;
  const double _t1322 = _t291*_t350;
  const double _t1323 = _t340*_t481;
  const double _t1324 = _t121*_t733;
  const double _t1326 = _t1325*_t340;
  const double _t1327 = _t1326*_t624;
  const double _t1328 = _t312*nb;
  const double _t1329 = _t1328*_t343;
  const double _t1330 = _t1293*_t155;
  const double _t1331 = _t1293*_t358;
  const double _t1333 = _t1332*_t965;
  const double _t1335 = _t1334*_t155;
  const double _t1337 = _t1336*_t155;
  const double _t1338 = (0.56e2 / 0.3e1)*_t358;
  const double _t1339 = (0.32e2 / 0.3e1)*_t343;
  const double _t1340 = _t26*_t694;
  const double _t1341 = _t224*_t965;
  const double _t1342 = _t1341*_t455;
  const double _t1343 = _t232*_t455;
  const double _t1344 = _t1343*_t155;
  const double _t1346 = (0.320e3 / 0.3e1)*_t139*_t709;
  const double _t1347 = _t1185*_t1227;
  const double _t1348 = _hc7[0]*_t1347*_t593;
  const double _t1349 = (0.1120e4 / 0.27e2)*_hc14[1]*_hc7[0]*_t233;
  const double _t1350 = _t228*_t256;
  const double _t1351 = (0.1600e4 / 0.27e2)*_hc7[0]*_t1350*_t59 + _t113*_t1349 - 0.140e3 / 0.9e1*_t1228*_t1305 - 0.224e3*_t1301*_t624 - 0.13568e5 / 0.81e2*_t1309*_t155 - 0.48e2*_t1325*_t959 + _t1345*_t1346 + _t1348*_t829 - 0.11536e5 / 0.81e2*_t597*_t967;
  const double _t1406 = _hc13[4]*_t25;
  const double _t1410 = _t384*_t773;
  const double _t1416 = _hc12[10]*_t775;
  const double _t1417 = _t240*_t997;
  const double _t1418 = _hc13[0]*_t790;
  const double _t1419 = _hc13[1]*_t757;
  const double _t1421 = _t1420*_t388;
  const double _t1422 = _t388*_t776;
  const double _t1423 = _t1004*_t240;
  const double _t1424 = _t239*_t392;
  const double _t1425 = _t1013*_t390;
  const double _t1427 = _t171*_t391;
  const double _t1429 = _hc13[3]*_t765;
  const double _t1430 = 0.12e2*_t787;
  const double _t1431 = _hc13[1]*_t239;
  const double _t1434 = _t1432*_t782;
  const double _t1435 = _hc13[1]*_t379;
  const double _t1438 = _hc12[6]*_t1024;
  const double _t1439 = _t1437*_t1438;
  const double _t1440 = _hc13[2]*_t773;
  const double _t1442 = _hc13[2]*_t382;
  const double _t1443 = _hc13[1]*_t563;
  const double _t1453 = _t1452*_t812;
  const double _t1456 = _t1455*_t814;
  const double _t1460 = _t1459*_t412;
  const double _t1461 = (0.6272e4 / 0.27e2)*_t256;
  const double _t1463 = _t102*_t232*_t412;
  const double _t1464 = _t1463*_t800;
  const double _t1465 = -0.64e2 / 0.3e1*_hc6[2]*_t1233*_t412 - 0.112e3 / 0.27e2*_hc6[2]*_t1234*_t256*_t28*_t631 - 0.32e2 / 0.81e2*_hc6[3]*_t1241*_t412 - 0.560e3 / 0.27e2*_t1189*_t1230*_t818 - _t1232*_t398 - 0.1e1 / 0.81e2*_t1235*_t406 - 0.448e3 / 0.3e1*_t1236*_t813*_t880 - 0.896e3 / 0.3e1*_t1237*_t814 - 0.92288e5 / 0.243e3*_t1238*_t256*_t260*_t407 - 0.1648e4 / 0.243e3*_t1239*_t177*_t259 - 0.6784e4 / 0.243e3*_t1240*_t178 - 0.54272e5 / 0.243e3*_t1240*_t819 - 0.448e3 / 0.27e2*_t1243*_t814 - 0.26368e5 / 0.243e3*_t1245*_t412 - _t585*_t626*_t795;
  const double _t1467 = _t185*_t87;
  const double _t1468 = _t1467*_t832;
  const double _t1469 = _t416*_t823;
  const double _t1470 = _t187*_t349;
  const double _t1471 = _t1470*_t185;
  const double _t1472 = _t1467*_t835;
  const double _t1473 = _t354*_t419;
  const double _t1474 = _t828*_t840;
  const double _t1475 = _t142*_t825;
  const double _t1476 = _t418*_t821;
  const double _t1477 = (0.16e2 / 0.3e1)*_t190;
  const double _t1479 = _t1478*_t427;
  const double _t1480 = _t1347*_t232;
  const double _t1481 = _t1480*_t73;
  const double _t1482 = _t20*_t712;
  const double _t1483 = _t1466*_t711*_t73 + (0.10e2 / 0.9e1)*_t1480*_t425 - _t1481*_t20*_t836 + (0.560e3 / 0.9e1)*_t1481*_t24*_t59/xc_powi(_t22, 8) + (0.320e3 / 0.81e2)*_t1482*_t425 - 0.32e2 / 0.81e2*_t188*_t712 + (0.224e3 / 0.81e2)*_t189*_t713 - 0.320e3 / 0.3e1*_t73*_t730*_t835;
  const double _t1484 = _t1040*_t23;
  const double _t1526 = _t261*_t444;
  const double _t1527 = -0.2e1 / 0.5e1*_hc14[1]*_t100*_t103*_t118*_t14*_t444*_t99 + _t1246 + (0.7e1 / 0.5e1)*_t1526 + _t605 + _t607 + _t608 + _t616 + _t617 + _t619;
  const double _t1554 = (0.7e1 / 0.4e1)*_t624*_t87;
  const double _t1555 = _t131*_t625;
  const double _t1556 = _t832*_t958;
  const double _t1557 = _t203*_t711;
  const double _t1558 = _t1314*_t681;
  const double _t1560 = _t462*_t48;
  const double _t1561 = _t1560*nb;
  const double _t1562 = _t1317*_t638;
  const double _t1564 = (0.80e2 / 0.3e1)*_t638;
  const double _t1565 = _t153*_t611;
  const double _t1569 = _hc15[1]*_t1486 + _hc17[3]*_t1568 + _t1282*_t1491 + _t1284 + _t461*_t551;
  const double _t1570 = 0.6e1*_t840;
  const double _t1572 = 0.16e2*_t448;
  const double _t1574 = _t48*_t919;
  const double _t1575 = _t459*_t921;
  const double _t1576 = _t135*_t456;
  const double _t1577 = _t1326*_t638;
  const double _t1580 = _t155*_t204;
  const double _t1581 = (0.3e1 / 0.4e1)*_t469;
  const double _t1582 = _t321*_t348;
  const double _t1583 = _t131*_t1582;
  const double _t1584 = _t322*_t348;
  const double _t1585 = _t1325*_t459;
  const double _t1586 = _t1293*_t706;
  const double _t1587 = _t312*na;
  const double _t1588 = 0.24e2*_t456;
  const double _t1589 = 0.48e2*_t456;
  const double _t1590 = _t462*nb;
  const double _t1591 = _t1307*_t1332;
  const double _t1593 = _t1307*_t1592;
  const double _t1594 = _t1334*_t329;
  const double _t1596 = _t1595*_t329;
  const double _t1597 = _t26*_t919;
  const double _t1598 = _t1307*_t224;
  const double _t1599 = _t1598*_t455;
  const double _t1600 = (0.140e3 / 0.3e1)*_t1598;
  const double _t1601 = _t1343*_t329;
  const double _t1602 = (0.944e3 / 0.9e1)*_t329;
  const double _t1603 = _t232*_t460;
  const double _t1604 = _t1565*_t477;
  const double _t1605 = _t477*_t700;
  const double _t1606 = _t206*nb;
  const double _t1607 = -_t1298 - _t1300 - _t1302 - _t1303 - _t1304 - _t1306 - _t1308 - _t1310 + 0.32e2*_t1345*_t832 + (0.2e1 / 0.3e1)*_t1348 + _t1349*_t139 + (0.320e3 / 0.9e1)*_t1350*_t450 + _t458*_t644;
  const double _t1608 = -_t1150*_t206 - _t1566*_t462 + _t1570*_t467 + _t1572*_t467 + (0.1e1 / 0.2e1)*_t1604 - 0.7e1 / 0.8e1*_t1605 - _t1606*_t704 - _t1606*_t707 + _t1607 - _t685 - _t699 - _t702 - _t703 - _t704*_t964 - _t705 - _t707*_t964 - _t708;
  const double _t1610 = _t40*_t452;
  const double _t1611 = _t1206*_t312;
  const double _t1614 = _t203*_t730;
  const double _t1615 = _t1563*_t624;
  const double _t1618 = 0.16e2*_t355;
  const double _t1619 = _t203*_t733;
  const double _t1620 = 0.8e1*_t343;
  const double _t1622 = _t343*_t462;
  const double _t1623 = _t1592*_t965;
  const double _t1624 = _t155*_t1595;
  const double _t1625 = _t312*_t332;
  const double _t1626 = _t965*_t968;
  const double _t1627 = _t155*_t459;
  const double _t1628 = _t1457*_t1627;
  const double _t1629 = _t206*_t481;
  const double _t1630 = _t350*_t467;
  const double _t1631 = (0.80e2 / 0.3e1)*_t1606;
  const double _t1632 = -_t1155*_t964 + _t1351 - _t1606*_t725 - _t1616*_t462 + _t1618*_t467 - _t1629*_t718 + 0.10e2*_t1630 - _t1631*_t728 - _t40*_t722 - _t719 - _t723 - _t724 - _t725*_t964 - _t726 - _t729;
  const double _t1686 = _t382*_t384;
  const double _t1689 = _t1009*_t766;
  const double _t1690 = _t476*_t997;
  const double _t1691 = _hc13[1]*_t494;
  const double _t1693 = _t1387*_t1418;
  const double _t1694 = 0.36e2*_hc13[0];
  const double _t1695 = _t1694*_t870;
  const double _t1699 = _hc13[1]*_t1698;
  const double _t1701 = _hc12[6]*_t171;
  const double _t1702 = _t1701*_t387;
  const double _t1703 = _t1701*_t194;
  const double _t1704 = _t391*_t393;
  const double _t1705 = _t1704*_t497;
  const double _t1706 = _t164*_t388;
  const double _t1707 = _hc13[2]*_t395;
  const double _t1708 = _hc13[2]*_t497;
  const double _t1709 = _hc13[3]*_t383;
  const double _t1710 = _t382*_t777;
  const double _t1713 = _hc13[2]*_t786*_t995;
  const double _t1714 = _t1687*_t782;
  const double _t1715 = _hc13[0]*_t391;
  const double _t1716 = _t1112*_t1715;
  const double _t1720 = _hc13[0]*_t1719;
  const double _t1722 = _t499*_t791;
  const double _t1723 = _t1013*_t780;
  const double _t1729 = _t1450*_t412;
  const double _t1731 = _t1730*_t412;
  const double _t1733 = _t1454*_t813;
  const double _t1735 = _t1734*_t813;
  const double _t1737 = _t1736*_t814;
  const double _t1739 = _t104*_t1452;
  const double _t1741 = _t1740*_t412;
  const double _t1742 = _t1462*_t256;
  const double _t1744 = _t1463*_t504;
  const double _t1745 = -_t1173 - 0.40e2 / 0.9e1*_t404 - 0.320e3 / 0.9e1*_t409 - 0.224e3 / 0.9e1*_t411 - _t796 - _t805;
  const double _t1746 = _t1468*_t424;
  const double _t1747 = _t1472*_t837;
  const double _t1748 = _t214*_t87;
  const double _t1749 = _t1470*_t214;
  const double _t1750 = _t1040*_t418;
  const double _t1751 = _t833*_t840;
  const double _t1752 = _t1044*_t840;
  const double _t1753 = _t424*_t830;
  const double _t1754 = _t506*_t823;
  const double _t1755 = _t1046*_t142;
  const double _t1756 = _t1483 + _t1753*_t506 - 0.2e1 / 0.3e1*_t1754 + (0.8e1 / 0.3e1)*_t1755;
  const double _t1757 = _t1115*_t23;
  const double _t1779 = _t261*_t519;
  const double _t1780 = _t180*_t201;
  const double _t1797 = _t204*_t625;
  const double _t1800 = _t48*_t526;
  const double _t1801 = _t1560*na;
  const double _t1802 = _t1563*_t638;
  const double _t1803 = (0.1e1 / 0.2e1)*_t469;
  const double _t1804 = _t20*_t203*_t712;
  const double _t1805 = _hc17[3]*_t237;
  const double _t1806 = _hc17[3]*_t509;
  const double _t1807 = _hc15[1]*_t1196 + _t1284;
  const double _t1808 = 0.8e1*_hc17[3]*_t1769 + _t1534*_t461 - _t1805*_t79 + _t1806*_t239 + _t1807 - _t549*_t918 + _t79*(-_hc17[3]*_t549 - _t1805);
  const double _t1809 = 0.8e1*_t315;
  const double _t1810 = _t20*_t451;
  const double _t1812 = _t1079*_t48;
  const double _t1813 = _t206*_t456;
  const double _t1814 = _t340*_t921;
  const double _t1815 = (0.224e3 / 0.9e1)*_t714;
  const double _t1816 = _t131*_t155;
  const double _t1817 = _t119*_t155;
  const double _t1818 = _t1582*_t204;
  const double _t1819 = (0.16e2 / 0.3e1)*_t448;
  const double _t1821 = _t1585*_t638;
  const double _t1822 = 0.16e2*_t456;
  const double _t1823 = _t526*nb;
  const double _t1824 = 0.32e2*_t456;
  const double _t1825 = _t462*na;
  const double _t1826 = (0.320e3 / 0.3e1)*_t706;
  const double _t1827 = _t1079*_t26;
  const double _t1828 = _t332*_t526;
  const double _t1829 = _t325*_t327;
  const double _t1830 = _t1598*_t460;
  const double _t1831 = _t1603*_t329;
  const double _t1832 = _t135*_t40;
  const double _t1833 = _t1087*_t40;
  const double _t1834 = 0.8e1*_t337;
  const double _t1836 = _t526*_t87;
  const double _t1837 = (0.224e3 / 0.9e1)*_t735;
  const double _t1838 = (0.16e2 / 0.3e1)*_t355;
  const double _t1839 = _t1585*_t624;
  const double _t1840 = (0.320e3 / 0.9e1)*_t728;
  const double _t1841 = (0.112e3 / 0.9e1)*_t358;
  const double _t1842 = _t358*_t360;
  const double _t1843 = _t1341*_t460;
  const double _t1868 = _t384*_t494;
  const double _t1872 = 0.12e2*_t1715;
  const double _t1873 = 0.12e2*_t1002;
  const double _t1875 = _hc13[2]*_t212;
  const double _t1877 = _hc13[3]*_t540*_t786;
  const double _t1878 = _t393*_t509;
  const double _t1879 = 0.12e2*_t998;
  const double _t1880 = _t494*_t777;
  const double _t1885 = _t1010*_t476;
  const double _t1887 = _t1013*_t998;
  const double _t1890 = _t1452*_t624;
  const double _t1891 = _t1743*_t256;
  const double _t1892 = 0.72e2*_t1195*_t386 + _t1465;
  const double _t1893 = _t1748*_t832;
  const double _t1894 = _t544*_t823;
  const double _t1895 = _t1748*_t835;
  const double _t1896 = _t1895*_t837;
  const double _t1897 = _t354*_t508;
  const double _t1898 = _t1115*_t418;
  const double _t1899 = _t1043*_t424;
  const double _t1919 = _t60*_t939;
  const double _t1922 = _hc15[1]*_t958 - _t1103*_t461 + _t1119*_t918 + _t1806*_t503 + _t1807 - _t461*_t502;
  const double _t1925 = _t523*_t700;
  const double _t1926 = _t204*_t343;
  const double _t1927 = _t526*na;
  const double _t1928 = _t1148*_t26;
  const double _t1929 = _t1206*_t526;
  const double _t1930 = _t350*_t521;
  const double _t1939 = _hc13[3]*_t1161;
  const double _t1940 = _hc13[1]*_t1692;
  const double _t1942 = _t1708*_t173;
  const double _t1943 = _hc12[3]*_t780;
  const double _t1944 = _t539*_t777;
  const double _t1945 = _t1105*_t1687;
  const double _t1946 = _t1166*_t1432;
  const double _t1947 = _t1105*_t1432;
  const double _t1949 = _t1174*_t418;
  const double _t1950 = _t1116*_t142;
  const double _t1967 = _t1152*na;
  const double _t1968 = _hc15[1]*_t1952 + 0.4e1*_t1119*_t461 + _t1282*_t1953 + _t1284;
  const double _t1976 = _t510*_t997;
  const double _t1977 = _t1004*_t510;
  const double _t1980 = _hc13[1]*_t1869;
  const double _t1982 = _t1875*_t1978;
  const double _t1983 = _t510*_t792;
  const double d4F_dna4 = _t1041*(0.36e2*_t1007*_t1415 + _t1014*_t1017*_t563 + 0.12e2*_t1014*_t1431 + _t1019*_t1426 + _t1023*_t1208 + _t1023*_t1211 + _t1023*_t1213 + _t1193*_t1416 + _t1193*_t1421 + _t1193*_t1439 + _t1197*_t213 + _t1198*_t392 + _t1198*_t542 + _t1200*_t1425 + _t1204*_t500 + _t1204*_t501 + _t1208*_t1417 + _t1208*_t1423 + _t1211*_t1417 + _t1211*_t1423 + _t1213*_t1417 + _t1213*_t1423 + _t1213*_t1434 + _t1376*_t1446*_t787 + _t1388*_t1418 + _t1406*(_t169 * _t169 * _t169 * _t169) + _t1410*_t382 + _t1415*_t1435*_t1436 + _t1415*_t996 + 0.24e2*_t1419*_t786 + _t1422*_t563 + _t1424*_t563 + _t1426*_t1427 + _t1428*_t1429*_t784 + _t1428*_t764*_t777 + _t1430*_t164*_t754 + _t1431*_t1433 + _t1431*_t1445 + _t1436*_t379*_t782 + _t1440*_t1441 + _t1441*_t1442 + _t1443*_t1445 + 0.64e2*_t1447 + (0.8e1 / 0.27e2)*_t1448 + _t1450*_t804 + (0.112e3 / 0.27e2)*_t1451 + _t1453*_t1454 + (0.896e3 / 0.9e1)*_t1456 + (0.1888e4 / 0.81e2)*_t1458 + (0.1792e4 / 0.27e2)*_t1460 + _t1461*_t1462 + (0.15104e5 / 0.81e2)*_t1464 + _t1465 + _t170*(-_t1193*_t1373 - _t1197*_t168 + _t1198*_t377 - _t1198*_t489 + _t1200*_t1397 - _t1200*_t992 + _t1204*_t1395 - _t1204*_t763 - _t1208*_t1401 + _t1208*_t1403 - _t1208*_t1405 - _t1211*_t1401 + _t1211*_t1403 - _t1211*_t1405 - _t1213*_t1401 + _t1213*_t1403 - _t1213*_t1405 + _t1368 + (0.91e2 / 0.108e3)*_t1369 - _t1370*_t1371 - _t1371*_t1374 + _t1372*_t551 + _t1375*_t768 - 0.2e1*_t1378 + _t1379*_t1381 + _t1379*_t1382 - _t1379*_t1391 + 0.2e1*_t1383 + (0.7e1 / 0.6e1)*_t1386 + _t1388*_t1389 + _t1392*_t1393 - _t1392*_t1396 + _t1393*_t1394 - _t1394*_t1396 - _t1398*_t563 + _t1399*_t563) + _t24*(_hc11[1]*_t1197 + _t1250*_t746 - _t133*(_hc11[4]*_t551 - _t133*(_hc11[8]*_t239 - _t133*(_hc11[13]*_t79 + _t1357) + _t1356 + _t1359*_t79) + _t1355 + _t1363*_t79 + _t648*_t745 + _t740*_t743) + _t1352 - 0.14e2 / 0.9e1*_t1353 + _t366*_t774 + _t385*_t750 + _t79*(_hc11[3]*_t551 - _t133*_t1363 + _t1365 + _t648*_t749 + _t740*_t745 + _t79*(_hc11[6]*_t239 - _t133*_t1362 + _t1366 + _t79*(_hc11[10]*_t79 + _t1367)))) + _t37*(_t1265*_t146 - _t1285*_t1320 - _t1286*_t337 - _t1288*_t1319 - _t1292*_t735 - 0.48e2*_t1312 - _t1313*_t696 + 0.24e2*_t1314*_t481 + _t1315*_t843 - 0.160e3 / 0.3e1*_t1316 + (0.224e3 / 0.3e1)*_t1318 + _t1321*_t694 + 0.20e2*_t1322 + _t1323*_t843 - 0.160e3 / 0.3e1*_t1324 + (0.224e3 / 0.3e1)*_t1327 + 0.32e2*_t1329 - _t1330*_t615 - 0.112e3 / 0.3e1*_t1331 + (0.784e3 / 0.9e1)*_t1333 + (0.3776e4 / 0.27e2)*_t1335 - _t1337*_t956 - _t1338*_t956 + _t1339*_t1340 + (0.784e3 / 0.9e1)*_t1342 + (0.3776e4 / 0.27e2)*_t1344 + _t1351 + 0.32e2*_t291*_t355) + (_t382 * _t382)*_t384 + _t44*((0.15104e5 / 0.27e2)*_hc14[1]*_hc6[0]*_t100*_t113*_t14*_t232*_t99*nb + (0.1792e4 / 0.9e1)*_hc14[1]*_hc6[1]*_t113*_t15*_t224*_t258*_t64*nb + (0.64e2 / 0.3e1)*_hc14[1]*_hc6[2]*_t113*_t30*_t585*_t620*nb + (0.4e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t118*_t14*_t254*_t99 + (0.4e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t14*_t2*_t602*_t99 + (0.1280e4 / 0.9e1)*_hc6[0]*_t139*_t30*_t585*_t620*_t623*nb + (0.4480e4 / 0.9e1)*_hc6[0]*_t15*_t224*_t256*_t258*_t59*_t64*nb + 0.256e3*_hc6[0]*_t221*_t30*_t31*_t38*nb + (0.7552e4 / 0.81e2)*_hc6[1]*_t100*_t14*_t232*_t38*_t99*nb + (0.320e3 / 0.3e1)*_hc6[1]*_t256*_t30*_t585*_t59*_t620*nb + (0.448e3 / 0.27e2)*_hc6[2]*_t15*_t224*_t258*_t38*_t64*nb + (0.32e2 / 0.27e2)*_hc6[3]*_t30*_t38*_t585*_t620*nb + (0.28e2 / 0.5e1)*_t113*_t30*_t620*_t623*_t87*_t97 - _t1176*_t602 - 0.14e2 / 0.5e1*_t1225 - 0.32e2 / 0.45e2*_t1226 - _t1246 + (0.28e2 / 0.15e2)*_t15*_t256*_t258*_t308*_t38*_t64*_t97 - _t445*(-_t1177*_t842 - _t1178*_t590 - _t1179*_t859 + _t1192 + _t1224 - _t599*_t797)) + 0.2e1*_t495*_t764 + _t495*(0.6e1*_hc12[1]*_hc12[3]*_t12*_t13*_t15*_t18*_t375*_t552*p->cam_omega + (0.1e1 / 0.2e1)*_hc12[1]*_t12*_t13*_t15*_t161*_t165*_t239*p->cam_omega + (0.1e1 / 0.2e1)*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t240*p->cam_omega + 0.2e1*_t12*_t13*_t15*_t18*_t239*_t374*_t375*_t79*p->cam_omega + 0.2e1*_t12*_t13*_t15*_t18*_t374*_t375*_t563*_t79*p->cam_omega - _t1407 - _t1408*_t758 - _t1409*_t239 - _t1409*_t563 - _t551*_t767 - 0.7e1 / 0.12e2*_t753 - _t754*_t770 - _t762) + _t58*((0.3776e4 / 0.9e1)*_hc10[0]*_hc14[1]*_t113*_t144*_t232*_t3*nb + (0.320e3 / 0.3e1)*_hc10[0]*_t139*_t585*_t623*nb + 0.192e3*M_PI*_hc10[0]*_t221*_t38*nb + (0.560e3 / 0.3e1)*_hc10[0]*_t224*_t225*_t256*_t4*_t59*nb + _hc14[1]*_t103*_t118*_t144*_t3*_t303 + _hc14[1]*_t103*_t144*_t2*_t3*_t679 + 0.96e2*_hc14[1]*_t109*_t113*_t144*_t3*_t312*nb + 0.32e2*_hc14[1]*_t109*_t113*_t144*_t3*_t694*na*nb + 0.32e2*_hc14[1]*_t109*_t139*_t291*_t3*_t5 + (0.3776e4 / 0.9e1)*_hc14[1]*_t113*_t135*_t144*_t232*_t3*na*nb - _t1080*_t1285 + 0.7e1*_t113*_t131*_t623*_t87 + 0.6e1*_t1265*_t59 - _t1266*_t679 - 0.16e2*_t1280 - 0.192e3*_t1281*_t921 - _t1286*_t315 - 0.32e2*_t1287 - _t1288*_t1289 - 0.7e1 / 0.4e1*_t1290 - 0.8e1 / 0.9e1*_t1291 - _t1292*_t714 - _t1293*_t1295 - 0.80e2*_t1294 - _t1296*_t956 - _t1297*_t956 + (0.7e1 / 0.6e1)*_t131*_t225*_t256*_t308*_t38*_t4 - _t1311 + (0.320e3 / 0.3e1)*_t135*_t139*_t585*_t623*na*nb + 0.192e3*M_PI*_t135*_t221*_t38*na*nb + (0.560e3 / 0.3e1)*_t135*_t224*_t225*_t256*_t4*_t59*na*nb + 0.12e2*_t20*_t225*_t226*_t256*_t291*_t308 + 0.96e2*M_PI*_t312*_t38*_t48*nb + 0.32e2*M_PI*_t38*_t48*_t694*na*nb - _t478*(-_t1071*_t1177 - _t1074*_t1179 - _t1178*_t671 - _t1193*_t1267 - _t1197*_t123 - _t1198*_t475 - _t1200*_t1277 - _t1204*_t666 - _t1208*_t1273 - _t1211*_t1273 - _t1213*_t1273 + _t1224 - 0.32e2 / 0.135e3*_t1268 - _t1269*_t1272 - _t1270*_t551 + _t1274*_t885 - _t1276*_t239 - _t1276*_t563 - _t1278*_t563 + _t1279 + _t665*_t885 - _t674*_t797) - _t694*_t695*_t923) + 0.36e2*_t782*_t793 + _t996*(_t1372*_t784 - _t1414 + _t772) + _t996*(_t1411 + _t1412*_t1413 - 0.3e1 / 0.2e1*_t1414 + 0.3e1*_t378 - 0.3e1 / 0.2e1*_t771)) + _t1346*_t1472 - _t1466*_t1468 - 0.4e1 / 0.3e1*_t1469 + (0.8e1 / 0.9e1)*_t1471 - 0.128e3 / 0.27e2*_t1473 - 0.80e2 / 0.9e1*_t1474 + (0.16e2 / 0.3e1)*_t1475 + _t1476*_t1477 + _t1479*_t416 + _t1483 + 0.4e1*_t822;
  const double d4F_dna3_dnb = _t1041*(_hc13[1]*_t1433*_t870 + _t1000*_t1429 + _t1002*_t1376*_t791 + _t1003*_t754 + _t1005*_t551 + _t1006*_t1419 + 0.18e2*_t1007*_t1692 + _t1010*_t781 + _t1024*_t1437*_t1671 + _t1113*_t774 + _t1400*_t1720 + _t1404*_t1695 + _t1406*_t765*_t995 + _t1410*_t494 + _t1416*_t1490 + _t1421*_t1490 + _t1434*_t870 + _t1435*_t1692*_t788 + _t1440*_t1697 + _t1442*_t1697 + _t1443*_t1698*_t387 + (0.224e3 / 0.3e1)*_t1456 + (0.472e3 / 0.27e2)*_t1458 + _t1459*_t1739 + (0.3776e4 / 0.27e2)*_t1464 + _t1465 + _t1486*_t213 + _t1490*_t1693 + _t1491*_t392 + _t1491*_t542 + _t1493*_t500 + _t1493*_t501 + 0.36e2*_t1523*_t1723 + _t1568*_t1706 + _t1686*_t494 + _t1689*_t382 + _t1689*_t773 + _t1690*_t239 + _t1690*_t563 + _t1691*_t781 + _t1699*_t776 + _t170*((0.91e2 / 0.144e3)*_t1369 - _t1370*_t1642 + _t1371*_t1385 - _t1373*_t1490 - _t1374*_t1642 + _t1375*_t162 - 0.1e1 / 0.2e1*_t1378 + _t1380*_t1671*_t373 + (0.1e1 / 0.2e1)*_t1383 - _t1392*_t1660 + _t1392*_t1663 - _t1394*_t1660 + _t1394*_t1663 + _t1395*_t1493 - _t1404*_t1652 - _t1486*_t168 + _t1490*_t1657 + _t1490*_t1658 - _t1490*_t1666 + _t1491*_t377 - _t1491*_t489 - _t1493*_t763 + 0.2e1*_t1539*_t1656 - _t1539*_t985 - _t1541*_t985 - _t1545*_t1654 - _t1551*_t1667 - _t1551*_t1676 + _t1551*_t1678 - 0.7e1 / 0.12e2*_t1641 + _t1643*_t1661 + _t1643*_t1662 + _t1644*_t845 + _t1645*_t551 + (0.91e2 / 0.432e3)*_t1646 + _t1648 + _t1649*_t377 - _t1649*_t489 - 0.2e1*_t1655 + _t1656*_t648*_t9 - 0.1e1 / 0.2e1*_t1659 + (0.3e1 / 0.2e1)*_t1665 - _t1668*_t1670 + _t1670*_t1679 + _t1672*_t379 - 0.3e1 / 0.2e1*_t1675 - _t1677*_t239 + _t1682) + _t1700*_t1702 + _t1700*_t1722 + _t1703*_t776 + _t1705*_t239 + _t1705*_t563 + _t1706*_t503*_t563 + _t1707*_t778*_t993 + _t1708*_t779 + _t1709*_t785*_t995 + _t1710*_t1712 + _t1710*_t1717 + _t1711*_t1714 + _t1711*_t780*_t981 + _t1713*_t379*_t788 + 0.18e2*_t1713*_t793 + _t1714*_t1718 + _t1716*_t239 + _t1716*_t563 + _t1717*_t239*_t780 + 0.16e2*_t1721 + _t1722*_t981 + _t1724*nb + 0.54e2*_t1725*_t787 + 0.72e2*_t1726*_t780 + _t1727*_t389 + (0.2e1 / 0.27e2)*_t1728 + (0.16e2 / 0.3e1)*_t1729 + (0.16e2 / 0.9e1)*_t1731 + (0.28e2 / 0.27e2)*_t1732 + (0.112e3 / 0.3e1)*_t1733 + (0.112e3 / 0.9e1)*_t1735 + (0.224e3 / 0.9e1)*_t1737 + (0.472e3 / 0.81e2)*_t1738 + (0.448e3 / 0.27e2)*_t1741 + (0.1568e4 / 0.9e1)*_t1742 + _t1743*_t817 + (0.3776e4 / 0.81e2)*_t1744 + _t1745 + _t24*(_hc11[1]*_t1486 - _t133*(_hc11[4]*_t845 - _t133*(_hc11[8]*_t238 + _t1634*_t79 + _t1639) + _t1355 + _t1636*_t79 + _t238*_t745 + _t239*_t971 + _t310*_t743 + _t310*_t972) - 0.28e2 / 0.27e2*_t1353 + _t1534*_t366 + _t1640 + _t238*_t750 + _t310*_t746 + _t484*_t551 - _t485*_t691 + _t648*_t977 + _t79*(_hc11[3]*_t845 - _t133*_t1636 + _t1365 + _t238*_t749 + _t239*_t975 + _t310*_t745 + _t310*_t971 + _t79*(_hc11[6]*_t238 + _t1637*_t79 + _t1638))) + _t37*(_t1088*_t1611 + _t1154*_t958 - 0.24e2*_t1312 + _t1315*_t1613 - 0.40e2*_t1316 + 0.56e2*_t1318 - _t1320*_t1569 + 0.10e2*_t1322 + _t1323*_t1613 - 0.40e2*_t1324 + 0.56e2*_t1327 + 0.8e1*_t1329 - _t1330*_t1336 - 0.56e2 / 0.3e1*_t1331 + (0.196e3 / 0.3e1)*_t1333 + (0.944e3 / 0.9e1)*_t1335 + _t1340*_t483 + (0.196e3 / 0.3e1)*_t1342 + (0.944e3 / 0.9e1)*_t1344 + _t146*_t1537 + _t1561*_t1612 - _t1567*_t337 - _t1578*_t735 - _t1579*_t735 + _t1585*_t962 + _t1587*_t1620 + _t1597*_t1620 - _t1609*_t313 + 0.12e2*_t1610 + _t1611*_t481 - 0.40e2 / 0.3e1*_t1614 + (0.56e2 / 0.3e1)*_t1615 - _t1616*_t312 + _t1617*_t919 + _t1618*_t291 - 0.40e2 / 0.3e1*_t1619 + _t1621*_t1622 + (0.196e3 / 0.9e1)*_t1623 + (0.944e3 / 0.27e2)*_t1624 - _t1625*_t728 + _t1626*_t460 + (0.944e3 / 0.27e2)*_t1628 + _t1632 - _t209*_t721 - _t479*_t659 + _t694*_t944 - _t717*_t942 - _t725*_t956 + 0.16e2*_t950 + _t960) + _t44*((0.3776e4 / 0.27e2)*_hc14[1]*_hc6[0]*_t100*_t113*_t14*_t232*_t99*na + (0.3776e4 / 0.9e1)*_hc14[1]*_hc6[0]*_t100*_t113*_t14*_t232*_t99*nb + (0.448e3 / 0.9e1)*_hc14[1]*_hc6[1]*_t113*_t15*_t224*_t258*_t64*na + (0.448e3 / 0.3e1)*_hc14[1]*_hc6[1]*_t113*_t15*_t224*_t258*_t64*nb + (0.16e2 / 0.3e1)*_hc14[1]*_hc6[2]*_t113*_t30*_t585*_t620*na + 0.16e2*_hc14[1]*_hc6[2]*_t113*_t30*_t585*_t620*nb + (0.2e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t118*_t14*_t254*_t99 + (0.1e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t14*_t2*_t602*_t99 + (0.3e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t14*_t2*_t876*_t99 + (0.320e3 / 0.9e1)*_hc6[0]*_t139*_t30*_t585*_t620*_t623*na + (0.320e3 / 0.3e1)*_hc6[0]*_t139*_t30*_t585*_t620*_t623*nb + (0.1120e4 / 0.9e1)*_hc6[0]*_t15*_t224*_t256*_t258*_t59*_t64*na + (0.1120e4 / 0.3e1)*_hc6[0]*_t15*_t224*_t256*_t258*_t59*_t64*nb + 0.64e2*_hc6[0]*_t221*_t30*_t31*_t38*na + 0.192e3*_hc6[0]*_t221*_t30*_t31*_t38*nb + (0.1888e4 / 0.81e2)*_hc6[1]*_t100*_t14*_t232*_t38*_t99*na + (0.1888e4 / 0.27e2)*_hc6[1]*_t100*_t14*_t232*_t38*_t99*nb + (0.80e2 / 0.3e1)*_hc6[1]*_t256*_t30*_t585*_t59*_t620*na + 0.80e2*_hc6[1]*_t256*_t30*_t585*_t59*_t620*nb + (0.112e3 / 0.27e2)*_hc6[2]*_t15*_t224*_t258*_t38*_t64*na + (0.112e3 / 0.9e1)*_hc6[2]*_t15*_t224*_t258*_t38*_t64*nb + (0.8e1 / 0.27e2)*_hc6[3]*_t30*_t38*_t585*_t620*na + (0.8e1 / 0.9e1)*_hc6[3]*_t30*_t38*_t585*_t620*nb + (0.7e1 / 0.5e1)*_t113*_t201*_t30*_t620*_t623*_t87 + (0.21e2 / 0.5e1)*_t113*_t30*_t620*_t623*_t87*_t97 - 0.7e1 / 0.5e1*_t1225 - 0.8e1 / 0.15e2*_t1226 + (0.7e1 / 0.15e2)*_t15*_t201*_t256*_t258*_t308*_t38*_t64 + (0.7e1 / 0.5e1)*_t15*_t256*_t258*_t308*_t38*_t64*_t97 - _t1527 - _t201*_t627 - _t445*(_hc2[2]*_t584*_t873 + _t1192 + _t1194*_t1490 + _t1199*_t193*_t554 + _t1219*_t1522 + _t1221*_t1522 - _t1485*_t842 + _t1486*_t195 + _t1487*_t196 - _t1488*_t590 - _t1489*_t591 + _t1491*_t241 + _t1492*_t436 + _t1493*_t435 + _t1495*_t239 + _t1495*_t563 - _t1496*_t859 - _t1497*_t599 - _t1498*_t599 + _t1499*_t1510*_t240 - _t1502 - _t1504 - _t1505 - _t1507 + _t1508*_t239 + _t1508*_t563 + _t1509*_t242 + _t1509*_t564 - _t1511 - _t1512 - _t1513 - _t1514 - _t1515 - _t1516 - _t1517 - _t1520 - _t1521 - _t1525 + _t436*_t844 + _t547 + _t550*_t849 + _t551*_t846 + _t574 + _t575 + _t581*_t873 - _t587 - _t596) - _t546*_t876 - _t603) + _t495*_t991 + _t495*(0.6e1*_hc12[1]*_hc12[3]*_t12*_t13*_t15*_t18*_t240*_t375*_t847*p->cam_omega + (0.1e1 / 0.6e1)*_hc12[1]*_t12*_t13*_t15*_t161*_t165*_t239*p->cam_omega + (0.2e1 / 0.3e1)*_hc12[1]*_t12*_t13*_t15*_t165*_t9*_t978*p->cam_omega + (0.1e1 / 0.6e1)*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t240*p->cam_omega - _t1097 + 0.2e1*_t12*_t13*_t15*_t18*_t194*_t239*_t374*_t375*p->cam_omega + 0.8e1*_t12*_t13*_t15*_t374*_t375*_t490*_t79*_t9*p->cam_omega - _t1683*_t983 - _t1684*_t987 - _t1685 - 0.7e1 / 0.18e2*_t753 - 0.1e1 / 0.3e1*_t762 - _t767*_t845 - _t770*_t982 - _t981*_t992) + _t498*_t764 + _t58*(0.144e3*_t1077*_t221 - _t1080*_t1569 - _t121*_t1556 - 0.96e2*_t1281*_t921 - 0.24e2*_t1287 - 0.7e1 / 0.8e1*_t1290 - 0.2e1 / 0.3e1*_t1291 - 0.40e2*_t1294 + _t1328*_t1588 + _t1340*_t457 - _t137*_t720 - _t1482*_t528 + _t1537*_t468 + _t1554*_t204 + (0.21e2 / 0.4e1)*_t1555 - 0.4e1*_t1557 + _t1558*na + _t1558*nb + _t1559*_t843 + _t1561*_t683 + 0.80e2*_t1562 + _t1563*_t1564 + _t1564*_t1585 + (0.1e1 / 0.2e1)*_t1565*_t303 - _t1566*_t312 - _t1567*_t315 + _t1570*_t291 + _t1571*_t694 + _t1572*_t291 + _t1573*_t1574 + _t1575*_t843 + 0.48e2*_t1576 + 0.80e2*_t1577 - _t1578*_t714 - _t1579*_t714 - _t1580*_t285 + _t1581*_t914 + (0.7e1 / 0.8e1)*_t1583 + _t1584*_t204 - 0.160e3*_t1586 + _t1587*_t1588 + _t1588*_t1597 + _t1589*_t1590 + 0.140e3*_t1591 + (0.140e3 / 0.3e1)*_t1593 + (0.944e3 / 0.3e1)*_t1594 + (0.944e3 / 0.9e1)*_t1596 + 0.140e3*_t1599 + _t1600*_t460 + (0.944e3 / 0.3e1)*_t1601 + _t1602*_t1603 + _t1608 + 0.144e3*_t221*_t340*_t921 + _t452*_t683 - _t454*_t659 + (0.1e1 / 0.4e1)*_t469*_t679 - _t478*((0.1e1 / 0.4e1)*_hc1[14]*_hc2[0]*_t552*_t847 + (0.1e1 / 0.4e1)*_hc1[2]*_hc2[0]*_t1486 + (0.1e1 / 0.3e1)*_hc1[2]*_hc2[1]*_t249*_t3*_t5*_t87*_t9 + (0.1e1 / 0.24e2)*_hc1[2]*_hc2[2]*_t225*_t226*_t245*_t87*_t9 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t1493*_t79 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t194*_t551 + (0.1e1 / 0.2e1)*_hc1[5]*_hc2[0]*_t239*_t87*_t9 + (0.1e1 / 0.2e1)*_hc1[5]*_hc2[0]*_t563*_t87*_t9 + (0.1e1 / 0.4e1)*_hc1[5]*_hc2[0]*_t79*_t845 + (0.1e1 / 0.6e1)*_hc1[5]*_hc2[1]*_t194*_t249*_t3*_t5*_t79 + (0.1e1 / 0.48e2)*_hc1[5]*_hc2[2]*_t194*_t225*_t226*_t245*_t79 + (0.1e1 / 0.4e1)*_hc1[9]*_hc2[0]*_t194*_t239*_t79 + (0.1e1 / 0.4e1)*_hc1[9]*_hc2[0]*_t194*_t563*_t79 + (0.3e1 / 0.2e1)*_hc1[9]*_hc2[0]*_t240*_t87*_t9 + (0.1e1 / 0.4e1)*_hc3[14]*_hc4[0]*_t193*_t554 + (0.1e1 / 0.4e1)*_hc3[2]*_hc4[0]*_t1487 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t1492*_t78 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t193*_t550 + (0.1e1 / 0.4e1)*_hc3[5]*_hc4[0]*_t78*_t844 + (0.1e1 / 0.4e1)*_hc3[9]*_hc4[0]*_t193*_t242*_t78 + (0.1e1 / 0.4e1)*_hc3[9]*_hc4[0]*_t193*_t564*_t78 + (0.2e1 / 0.15e2)*_hc9[1]*_t118*_t239*_t64*_t67 + (0.4e1 / 0.15e2)*_hc9[1]*_t232*_t64*_t67*_t9 + (0.2e1 / 0.15e2)*_hc9[3]*_t118*_t240*_t64*_t67 - _t1071*_t1485 - _t1074*_t1496 - _t123*_t1486 - _t1267*_t1490 - 0.8e1 / 0.45e2*_t1268 - _t127*_t1272 - _t1488*_t671 - _t1491*_t475 - _t1493*_t666 - _t1497*_t674 - _t1498*_t674 - _t1502 - _t1504 - _t1505 - _t1507 - _t1511 - _t1512 - _t1513 - _t1514 - _t1515 - _t1516 - _t1517 - _t1520 - _t1521 - _t1525 - 0.1e1 / 0.9e1*_t1538 - _t1539*_t1540 - _t1540*_t1541 - _t1542*_t663 - _t1543*_t663 - _t1544*_t239 - _t1544*_t563 - _t1545*_t1547 - _t1548*_t1549*_t79 - _t1550*_t1551 - _t1552*_t239 - _t1553 - _t473*_t669 - _t551*_t904 - _t551*_t907 - _t662*_t845 - _t667 - _t676) - _t660*_t914 - _t680 - _t681*_t920 - _t682 - _t704*_t956 - _t707*_t956) + _t764*_t994 + _t774*_t999 + _t777*_t778*_t991 + _t778*_t780*_t845 + _t789*_t982 + _t794*_t987 + _t807*_t858 + _t811*_t955 + _t996*(_t1411 + _t1413*_t1643 + _t1644*_t847 - 0.3e1 / 0.2e1*_t1687*_t992 + 0.3e1*_t1688 - 0.3e1*_t492)) - 0.2e1 / 0.3e1*_t1469 + (0.2e1 / 0.3e1)*_t1471 - 0.32e2 / 0.9e1*_t1473 + (0.8e1 / 0.3e1)*_t1475 + _t1476*_t191 + 0.3e1*_t1484 - 0.20e2*_t1746 + 0.80e2*_t1747 - _t1748*_t834 + _t1748*_t838 + (0.2e1 / 0.9e1)*_t1749 + _t1750*_t826 - _t1751*_t185 - 0.20e2 / 0.9e1*_t1752 + _t1753*_t416 + _t1756 - _t508*_t839 + _t822;
  const double d4F_dna2_dnb2 = _t1041*(0.48e2*_hc13[0]*_t1884*_t756 + _hc13[1]*_t1006*_t164*_t982 + _hc13[1]*_t1415*_t1871 + _hc13[1]*_t1870*_t541 + _hc13[2]*_t1011*_t1696*_t993 + 0.144e3*_t1001*_t1437*_t1523 + 0.36e2*_t1002*_t1725 + _t1004*_t1773 + _t1006*_t1709*_t172*_t847 + _t1008*_t1100 + _t1010*_t1883 + _t1011*_t1707*_t539 + _t1011*_t1877*_t784 + 0.12e2*_t1013*_t1885 + _t1014*_t1878 + _t1016*_t1879*_t239 + _t1017*_t1444*_t509 - _t1019*_t1874 - _t1020 - _t1021*_t1874 - _t1022 + _t1023*_t1772 - _t1026 - 0.64e2 / 0.3e1*_t1027 + _t1098*_t1109*_t164 + _t1099*_t1430 + _t1101*_t1415 + _t1102*_t991 + _t1105*_t1213*_t173 + _t1105*_t379*_t387 + 0.6e1*_t1105*_t793 + _t1110*_t1415*_t393 + 0.6e1*_t1110*_t782 + _t1111*_t212*_t239 + 0.24e2*_t1114*_t1723 + _t1166*_t172*_t385 + _t1406*_t383*_t540 + _t1416*_t1771 + _t1417*_t1772 + _t1420*_t389*_t510 + _t1422*_t509 + _t1423*_t1772 + _t1424*_t509 + _t1425*_t1795 - 0.72e2*_t1427*_t548 + _t1428*_t1708*_t494 + _t1435*_t1869*_t387 + _t1438*_t164*_t1884 + _t1439*_t1771 + 0.32e2*_t1447 + (0.4e1 / 0.27e2)*_t1448 + (0.56e2 / 0.27e2)*_t1451 + _t1455*_t1890 + (0.944e3 / 0.81e2)*_t1458 + (0.896e3 / 0.27e2)*_t1460 + (0.7552e4 / 0.81e2)*_t1464 + 0.24e2*_t1523*_t1887 + _t1686*_t539 + 0.2e1*_t1689*_t993 + _t1691*_t1883 + _t1693*_t1771 + _t170*(_t1073*_t194*_t978*_t984 + _t1368 + (0.91e2 / 0.216e3)*_t1369 - _t1370*_t1851 - _t1373*_t1771 - _t1374*_t1851 + 0.8e1*_t1384*_t1850 + (0.7e1 / 0.36e2)*_t1386 - _t1398*_t509 + _t1399*_t509 - _t1401*_t1772 + _t1403*_t1772 - _t1405*_t1772 + _t1534*_t194*_t377 - 0.124e3 / 0.9e1*_t1641 + (0.91e2 / 0.216e3)*_t1646 + (0.20e2 / 0.3e1)*_t1648 - 0.4e1*_t1653*_t1796 - 0.40e2 / 0.3e1*_t1655 - 0.4e1*_t1656*_t79 + _t1657*_t1771 + _t1658*_t1771 - 0.1e1 / 0.3e1*_t1659 + _t1661*_t368 + _t1662*_t368 + _t1665 - _t1666*_t1771 - _t1667*_t1773 - _t1668*_t1867 - _t1675 - _t1676*_t1773 + _t1678*_t1773 + _t1679*_t1867 - 0.7e1 / 0.18e2*_t1680*_t370 + (0.7e1 / 0.9e1)*_t1681*_t370 + _t1771*_t1866 - _t1795*_t992 - 0.1e1 / 0.3e1*_t1849 - 0.4e1*_t1850*_t984 - _t1851*_t1852 - _t1851*_t1854 + _t1853*_t845 + (0.7e1 / 0.36e2)*_t1856 - 0.4e1 / 0.3e1*_t1858 + _t1860*_t368 + _t1861*_t368 + _t1862 - 0.1e1 / 0.3e1*_t1863 - _t1865 + _t79*_t986) + 0.24e2*_t1706*_t1769 + 0.48e2*_t1715*_t1769 + 0.32e2*_t1721 + 0.48e2*_t1726*_t998 + (0.4e1 / 0.27e2)*_t1728 + (0.32e2 / 0.9e1)*_t1729 + _t173*_t1772*_t782 + (0.32e2 / 0.9e1)*_t1731 + (0.56e2 / 0.27e2)*_t1732 + (0.224e3 / 0.9e1)*_t1733 + (0.224e3 / 0.9e1)*_t1735 + _t1736*_t1890 + (0.944e3 / 0.81e2)*_t1738 + (0.896e3 / 0.27e2)*_t1741 + (0.3136e4 / 0.27e2)*_t1742 + (0.7552e4 / 0.81e2)*_t1744 - _t177*_t881 + _t1773*_t792 + _t1773*_t997 + _t1795*_t1872 + _t1868*_t993 + _t1869*_t393*_t793 + _t1869*_t996 + _t1870*_t1875*_t1876 + _t1871*_t782 + _t1873*_t987 + 0.12e2*_t1880*_t1881 + _t1880*_t1882 + _t1885*_t1886 + 0.36e2*_t1888*_t787 + 0.48e2*_t1889*_t780 + (0.3136e4 / 0.27e2)*_t1891 + _t1892 + _t212*_t394*_t845 + _t24*(_t1093*_t310 + _t1095*_t239 - _t133*(-_hc11[4]*_t237 - _hc11[4]*_t549 + (0.4e1 / 0.9e1)*_t109*_t3*_t5*_t972 - _t1354 + _t1845*_t79 - _t1848 + 0.4e1*_t87*_t9*_t971) + _t1534*_t484 + _t1640 - _t1785*_t485 + _t1844 - _t237*_t366 - _t364*_t691 - _t366*_t549 + _t562*_t977 + _t79*(-_hc11[3]*_t237 - _hc11[3]*_t549 + (0.4e1 / 0.9e1)*_t109*_t3*_t5*_t971 - _t1364 - _t1846 + _t1847*_t79 + 0.4e1*_t87*_t9*_t975)) + _t37*(-_t1070*_t1834 + _t1079*_t957 - _t1086*_t88 - _t1090 - _t1091 - _t1092*_t952 + _t1154*_t222 - _t121*_t1837 - _t124*_t1832 - _t1288*_t1835 - _t1293*_t945 + _t1313*_t1561 + _t1313*_t1801 + _t1313*_t453 - _t1313*_t463 + _t1315*_t222 - 0.80e2 / 0.3e1*_t1316 + (0.112e3 / 0.3e1)*_t1318 - _t1320*_t1808 + _t1323*_t222 - 0.80e2 / 0.3e1*_t1324 + (0.112e3 / 0.3e1)*_t1327 - 0.56e2 / 0.9e1*_t1331 + (0.392e3 / 0.9e1)*_t1333 + (0.1888e4 / 0.27e2)*_t1335 + _t1339*_t1590 + (0.392e3 / 0.9e1)*_t1342 + (0.1888e4 / 0.27e2)*_t1344 + _t1351 + _t146*_t1787 - _t150*_t217 + _t1587*_t339 + _t1587*_t344 + _t1597*_t344 - _t1606*_t1840 - _t1606*_t1841 + 0.8e1*_t1610 - 0.80e2 / 0.3e1*_t1614 + (0.112e3 / 0.3e1)*_t1615 - 0.80e2 / 0.3e1*_t1619 + (0.32e2 / 0.3e1)*_t1622*na + (0.392e3 / 0.9e1)*_t1623 + (0.1888e4 / 0.27e2)*_t1624 + (0.1888e4 / 0.27e2)*_t1628 - _t1629*_t217 + (0.40e2 / 0.3e1)*_t1630 + _t1820*_t355 + _t1823*_t344 + _t1827*_t344 - _t1832*_t318 - _t1833*_t335 - _t1834*_t903 - _t1835*_t1836 - _t1837*_t203 + _t1838*_t291 + _t1838*_t521 + (0.112e3 / 0.3e1)*_t1839 - _t1840*_t340 - _t1840*_t964 - _t1841*_t340 - _t1841*_t964 - _t1842*_t312 - _t1842*_t526 + (0.392e3 / 0.9e1)*_t1843 + _t222*_t959 + _t291*_t351 - _t318*_t462*_t481 + _t351*_t521 - 0.320e3 / 0.9e1*_t356 - 0.112e3 / 0.9e1*_t359 + _t526*_t532 - _t529*_t942 + _t919*_t957 + (0.32e2 / 0.3e1)*_t950 - _t952*_t956 + (0.32e2 / 0.3e1)*_t963) - 0.160e3 / 0.27e2*_t404 - 0.1280e4 / 0.27e2*_t409 - 0.896e3 / 0.27e2*_t411 - 0.256e3 / 0.27e2*_t413 + _t44*((0.7552e4 / 0.27e2)*_hc14[1]*_hc6[0]*_t100*_t113*_t14*_t232*_t99*na + (0.7552e4 / 0.27e2)*_hc14[1]*_hc6[0]*_t100*_t113*_t14*_t232*_t99*nb + (0.896e3 / 0.9e1)*_hc14[1]*_hc6[1]*_t113*_t15*_t224*_t258*_t64*na + (0.896e3 / 0.9e1)*_hc14[1]*_hc6[1]*_t113*_t15*_t224*_t258*_t64*nb + (0.32e2 / 0.3e1)*_hc14[1]*_hc6[2]*_t113*_t30*_t585*_t620*na + (0.32e2 / 0.3e1)*_hc14[1]*_hc6[2]*_t113*_t30*_t585*_t620*nb + (0.2e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t1065*_t14*_t2*_t99 + (0.2e1 / 0.15e2)*_hc14[1]*_t100*_t103*_t118*_t14*_t254*_t99 + (0.8e1 / 0.15e2)*_hc14[1]*_t100*_t103*_t118*_t14*_t444*_t99 + (0.2e1 / 0.15e2)*_hc14[1]*_t100*_t103*_t118*_t14*_t519*_t99 + (0.2e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t14*_t2*_t876*_t99 + (0.640e3 / 0.9e1)*_hc6[0]*_t139*_t30*_t585*_t620*_t623*na + (0.640e3 / 0.9e1)*_hc6[0]*_t139*_t30*_t585*_t620*_t623*nb + (0.2240e4 / 0.9e1)*_hc6[0]*_t15*_t224*_t256*_t258*_t59*_t64*na + (0.2240e4 / 0.9e1)*_hc6[0]*_t15*_t224*_t256*_t258*_t59*_t64*nb + 0.128e3*_hc6[0]*_t221*_t30*_t31*_t38*na + 0.128e3*_hc6[0]*_t221*_t30*_t31*_t38*nb + (0.3776e4 / 0.81e2)*_hc6[1]*_t100*_t14*_t232*_t38*_t99*na + (0.3776e4 / 0.81e2)*_hc6[1]*_t100*_t14*_t232*_t38*_t99*nb + (0.160e3 / 0.3e1)*_hc6[1]*_t256*_t30*_t585*_t59*_t620*na + (0.160e3 / 0.3e1)*_hc6[1]*_t256*_t30*_t585*_t59*_t620*nb + (0.224e3 / 0.27e2)*_hc6[2]*_t15*_t224*_t258*_t38*_t64*na + (0.224e3 / 0.27e2)*_hc6[2]*_t15*_t224*_t258*_t38*_t64*nb + (0.16e2 / 0.27e2)*_hc6[3]*_t30*_t38*_t585*_t620*na + (0.16e2 / 0.27e2)*_hc6[3]*_t30*_t38*_t585*_t620*nb - _t1065*_t216 + (0.14e2 / 0.5e1)*_t113*_t201*_t30*_t620*_t623*_t87 + (0.14e2 / 0.5e1)*_t113*_t30*_t620*_t623*_t87*_t97 - 0.7e1 / 0.15e2*_t1225 - 0.16e2 / 0.45e2*_t1226 - _t1246 + (0.14e2 / 0.15e2)*_t15*_t201*_t256*_t258*_t308*_t38*_t64 + (0.14e2 / 0.15e2)*_t15*_t256*_t258*_t308*_t38*_t64*_t97 - 0.28e2 / 0.15e2*_t1526 - 0.7e1 / 0.15e2*_t1779 - 0.16e2 / 0.45e2*_t1780 - _t216*_t876 - 0.64e2 / 0.27e2*_t269 - 0.640e3 / 0.27e2*_t272 - 0.256e3 / 0.9e1*_t275 - 0.640e3 / 0.9e1*_t279 - 0.1280e4 / 0.9e1*_t283 - _t445*(_hc5[0]*_t1758 + _hc5[1]*_t1761 + _hc5[2]*_t1760 + _t1192 - _t1299*_t842 - _t1299*_t89 - _t1489*_t1759 - _t1759*_t589 - _t1762*_t859 - _t1762*_t94 - _t1763*na - _t1763*nb + _t1778) - 0.256e3 / 0.3e1*_t604) + _t495*(0.6e1*_hc12[1]*_hc12[3]*_t12*_t13*_t15*_t18*_t375*_t510*_t784*p->cam_omega + (0.1e1 / 0.6e1)*_hc12[1]*_t12*_t13*_t15*_t161*_t165*_t509*p->cam_omega + 0.2e1*_hc12[1]*_t12*_t13*_t15*_t165*_t490*p->cam_omega + (0.20e2 / 0.3e1)*_hc12[1]*_t12*_t13*_t15*_t165*_t9*_t978*p->cam_omega + (0.1e1 / 0.6e1)*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t510*p->cam_omega - _t1075*_t1683 - 0.1e1 / 0.3e1*_t1096 - _t1098*_t770 - _t1099*_t1684 + 0.2e1*_t12*_t13*_t15*_t18*_t374*_t375*_t509*_t79*p->cam_omega + 0.8e1*_t12*_t13*_t15*_t194*_t374*_t375*_t490*_t9*p->cam_omega - _t1409*_t509 - _t1685 - _t979 - 0.7e1 / 0.18e2*_t980) + _t543*_t991 + _t58*(-_t1070*_t1809 + _t1076*_t1803 - _t1076*_t292 + _t1077*_t1758 + _t1078*_t1314 - _t1078*_t941 - _t1080*_t1808 - _t1081*_t312 - _t1081*_t526 - _t1082 - _t1084 - _t1085 - _t1087*_t915 - _t121*_t1815 - 0.8e1*_t1280 - _t1281*_t924 - 0.16e2*_t1287 - 0.40e2 / 0.3e1*_t1294 + (0.7e1 / 0.2e1)*_t1555 - 0.8e1*_t1557 + _t1559*_t1758 + _t1561*_t923 + (0.160e3 / 0.3e1)*_t1562 + _t1574*_t1811 + _t1575*_t1758 + 0.32e2*_t1576 + (0.160e3 / 0.3e1)*_t1577 - _t1580*_t175 + (0.7e1 / 0.12e2)*_t1583 - 0.160e3 / 0.3e1*_t1586 + _t1587*_t1822 + _t1590*_t1824 + (0.280e3 / 0.3e1)*_t1591 + (0.280e3 / 0.3e1)*_t1593 + (0.1888e4 / 0.9e1)*_t1594 + (0.1888e4 / 0.9e1)*_t1596 + _t1597*_t1822 + (0.280e3 / 0.3e1)*_t1599 + (0.1888e4 / 0.9e1)*_t1601 + (0.2e1 / 0.3e1)*_t1604 - 0.7e1 / 0.6e1*_t1605 - _t1606*_t1826 + _t1607 - _t1625*_t706 - _t1631*_t325 - _t175*_t1816 + _t1758*_t1814 + _t1787*_t468 + (0.7e1 / 0.2e1)*_t1797 - _t1798*_t922 - _t1799*_t340 - _t1799*_t964 + _t1800*_t915 + _t1801*_t923 + (0.160e3 / 0.3e1)*_t1802 + _t1803*_t914 - 0.16e2*_t1804 - _t1809*_t903 + _t1810*_t291 + _t1810*_t521 + _t1811*_t1812 + 0.32e2*_t1813 - _t1815*_t203 + _t1817*_t303 + _t1817*_t523 + (0.7e1 / 0.12e2)*_t1818 + _t1819*_t291 + _t1819*_t521 + _t1820*_t448 + (0.160e3 / 0.3e1)*_t1821 + _t1822*_t1823 + _t1822*_t1827 + _t1824*_t1825 - _t1826*_t340 - _t1826*_t964 - _t1828*_t706 - _t1829*_t312 - _t1829*_t526 + (0.280e3 / 0.3e1)*_t1830 + (0.1888e4 / 0.9e1)*_t1831 - _t292*_t914 - _t303*_t926 - _t325*_t727 - 0.80e2 / 0.3e1*_t325*_t964 - 0.80e2 / 0.3e1*_t326 - 0.320e3 / 0.3e1*_t331 + _t452*_t923 + _t453*_t923 - _t463*_t923 - _t478*(_hc8[0]*_t1758 + _hc8[1]*_t1761 + _hc8[2]*_t1760 - _t1071*_t1299 + _t1072*_t300 - _t1074*_t1762 - 0.16e2 / 0.15e2*_t1075*_t908*_t91 + (0.8e1 / 0.45e2)*_t118*_t912 - _t125*_t1299 - _t1267*_t1771 - 0.16e2 / 0.135e3*_t1268 - _t1273*_t1772 + _t1274*_t300 + (0.4e1 / 0.3e1)*_t1275*_t1549 - _t1277*_t1795 - _t1278*_t509 + _t1279 - _t129*_t1762 - _t1489*_t1788 - _t1542*_t299 - _t1543*_t299 - 0.8e1 / 0.5e1*_t1546*_t1796 - _t1548*_t1768*_t593 - _t1773*_t661 + _t1778 - _t1788*_t589 - 0.128e3 / 0.45e2*_t1789 - _t1790*na - _t1790*nb - 0.16e2 / 0.135e3*_t1791 + _t1792*_t300 - _t1793*_t299 - _t1794*_t299 - _t297*_t299*_t845 + _t300*_t665 + _t906 + _t911) - _t523*_t926 + _t840*_t936 - 0.64e2*_t916)) + _t1116*_t423 - 0.2e1 / 0.9e1*_t1469 + (0.4e1 / 0.9e1)*_t1471 - 0.64e2 / 0.27e2*_t1473 - 0.40e2 / 0.9e1*_t1474 - _t1478*_t1893 + _t1483 + 0.2e1*_t1484 - 0.40e2 / 0.3e1*_t1746 + (0.160e3 / 0.3e1)*_t1747 + (0.4e1 / 0.9e1)*_t1749 + _t1750*_t420 - 0.40e2 / 0.9e1*_t1752 - 0.8e1 / 0.9e1*_t1754 + (0.32e2 / 0.9e1)*_t1755 + 0.2e1*_t1757 - 0.2e1 / 0.9e1*_t1894 + (0.160e3 / 0.3e1)*_t1896 - 0.64e2 / 0.27e2*_t1897 + _t1898*_t420 + _t1899*_t416 + _t1899*_t544 + _t423*_t825 + (0.80e2 / 0.9e1)*_t424*_t427*_t506;
  const double d4F_dna_dnb3 = _t1041*(_hc13[1]*_t1100*_t1167 + _hc13[1]*_t1718*_t497*_t509 + _hc13[2]*_t1167*_t169*_t539 - _t1001*_t1436*_t87 + _t1002*_t1098*_t788 + 0.18e2*_t1002*_t1099 + 0.54e2*_t1002*_t1888 + _t1010*_t1168 + _t1016*_t169*_t1878 - _t1016*_t1694*_t87 + _t1019*_t1165 + _t1021*_t1165 + _t1033*_t815 + _t1049*_t807 + 0.3e1*_t1100*_t994 + 0.3e1*_t1101*_t1692 + _t1104*_t1160 + _t1106*_t1939 + _t1107*_t1703 + _t1107*_t194*_t1943 + _t1108*_t1156 + _t1109*_t1157 - _t1113*_t1941 + 0.36e2*_t1114*_t1887 + _t1119*_t501 + _t1144*_t169*_t1704 + _t1144*_t1702 + _t1144*_t1722 + _t1144*_t1943*_t387 + _t1159*_t1722 + _t1160*_t495 + _t1161*_t1406*_t786 + _t1164*_t1689 + _t1164*_t1942 + _t1168*_t1691 + _t1169*_t1877 + _t1170*_t1713 + _t1170*_t1940 + _t1171*_t1713 + _t1171*_t1940 + _t1416*_t1913 + _t1421*_t1913 + _t1432*_t1875*_t194*_t494 + _t1439*_t1913 + (0.2e1 / 0.27e2)*_t1448 + (0.28e2 / 0.27e2)*_t1451 + (0.224e3 / 0.9e1)*_t1456 + (0.472e3 / 0.81e2)*_t1458 + (0.3776e4 / 0.81e2)*_t1464 + _t1613*_t386 + _t1621*_t806 + _t1689*_t539 + _t1690*_t509 + _t1693*_t1913 + _t1695*_t1935 + _t1695*_t391*_t509 + _t1699*_t509*_t788 + _t170*(_t1119*_t1395 + _t1119*_t1645 - _t1119*_t763 - _t1144*_t1660 + _t1144*_t1663 - _t1159*_t1660 + _t1159*_t1663 + (0.91e2 / 0.432e3)*_t1369 + _t1371*_t1855 - _t1373*_t1913 + _t162*_t1934 - 0.169e3 / 0.12e2*_t1641 - _t1642*_t1852 - _t1642*_t1854 + _t1643*_t1860 + _t1643*_t1861 + (0.91e2 / 0.144e3)*_t1646 - _t1652*_t1935 - _t1654*_t1917 - _t1656*_t1876 + 0.6e1*_t1656*_t1916 + _t1657*_t1913 + _t1658*_t1913 - _t1666*_t1913 - _t1667*_t1918 - _t1668*_t1938 + _t1672*_t537 - _t1676*_t1918 - _t1677*_t509 + _t1678*_t1918 + _t1679*_t1938 + _t1682 - 0.13e2 / 0.2e1*_t1849 + 0.10e2*_t1857*_t984 - 0.20e2*_t1858 + (0.3e1 / 0.2e1)*_t1862 - 0.1e1 / 0.2e1*_t1863 - 0.3e1 / 0.2e1*_t1865 + _t1866*_t1913 + (0.1e1 / 0.2e1)*_t1933 - 0.1e1 / 0.2e1*_t1937 + 0.3e1*_t194*_t985 - _t541*_t9*_t985) + _t1711*_t1945 + _t1712*_t1944 - 0.108e3*_t1715*_t194*_t548 + _t1717*_t1944 + _t1718*_t1945 + _t1719*_t388*_t509 + _t1720*_t1948 + _t1724*na + _t1727*_t388*_t510 + (0.16e2 / 0.9e1)*_t1729 + (0.16e2 / 0.3e1)*_t1731 + (0.28e2 / 0.9e1)*_t1732 + (0.112e3 / 0.9e1)*_t1733 + (0.112e3 / 0.3e1)*_t1735 + (0.224e3 / 0.3e1)*_t1737 + (0.472e3 / 0.27e2)*_t1738 + _t1739*_t1740 + (0.1568e4 / 0.27e2)*_t1742 + (0.3776e4 / 0.27e2)*_t1744 + _t1745 + 0.3e1*_t1868*_t539 + 0.72e2*_t1889*_t998 + (0.1568e4 / 0.9e1)*_t1891 + _t1892 + _t1918*_t997 + _t1936*_t787*_t791 - _t1941*_t999 + _t1942*_t539 + _t1946*_t870 + _t1947*_t870 + _t24*(_hc11[1]*_t958 + _t1095*_t503 - _t1103*_t484 + _t1844 + _t1931*_t79 + _t1932 - _t484*_t502) + _t37*(_t1079*_t1617 + _t1088*_t1929 - _t1092*_t725 - _t1143*_t479 + _t1148*_t944 - _t1151*_t1833 - _t1153*_t40 + _t1154*_t1613 + _t1315*_t958 - 0.40e2 / 0.3e1*_t1316 + (0.56e2 / 0.3e1)*_t1318 - _t1320*_t1922 + _t1323*_t958 - 0.40e2 / 0.3e1*_t1324 + _t1326*_t962 + (0.196e3 / 0.9e1)*_t1333 + (0.944e3 / 0.27e2)*_t1335 - _t1336*_t1627 + _t1343*_t969 + _t146*_t1912 - _t1609*_t527 + _t1612*_t1801 + _t1612*_t453 + _t1613*_t959 - 0.40e2*_t1614 + 0.56e2*_t1615 - _t1616*_t526 + _t1618*_t521 - 0.40e2*_t1619 + _t1620*_t1823 + _t1620*_t1827 + _t1620*_t1927 + (0.196e3 / 0.3e1)*_t1623 + (0.944e3 / 0.9e1)*_t1624 + _t1626*_t455 + (0.944e3 / 0.9e1)*_t1628 + _t1632 + 0.16e2*_t1825*_t343 - _t1828*_t728 + 0.56e2*_t1839 + (0.196e3 / 0.3e1)*_t1843 - _t1921*_t337 - _t1923*_t735 - _t1924*_t735 + _t1928*_t483 + _t1929*_t481 + 0.10e2*_t1930 - 0.24e2*_t940 - 0.56e2 / 0.3e1*_t954 + 0.16e2*_t963) + _t44*((0.3776e4 / 0.9e1)*_hc14[1]*_hc6[0]*_t100*_t113*_t14*_t232*_t99*na + (0.3776e4 / 0.27e2)*_hc14[1]*_hc6[0]*_t100*_t113*_t14*_t232*_t99*nb + (0.448e3 / 0.3e1)*_hc14[1]*_hc6[1]*_t113*_t15*_t224*_t258*_t64*na + (0.448e3 / 0.9e1)*_hc14[1]*_hc6[1]*_t113*_t15*_t224*_t258*_t64*nb + 0.16e2*_hc14[1]*_hc6[2]*_t113*_t30*_t585*_t620*na + (0.16e2 / 0.3e1)*_hc14[1]*_hc6[2]*_t113*_t30*_t585*_t620*nb + (0.3e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t1065*_t14*_t2*_t99 + (0.1e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t1140*_t14*_t2*_t99 + (0.2e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t118*_t14*_t519*_t99 + (0.320e3 / 0.3e1)*_hc6[0]*_t139*_t30*_t585*_t620*_t623*na + (0.320e3 / 0.9e1)*_hc6[0]*_t139*_t30*_t585*_t620*_t623*nb + (0.1120e4 / 0.3e1)*_hc6[0]*_t15*_t224*_t256*_t258*_t59*_t64*na + (0.1120e4 / 0.9e1)*_hc6[0]*_t15*_t224*_t256*_t258*_t59*_t64*nb + 0.192e3*_hc6[0]*_t221*_t30*_t31*_t38*na + 0.64e2*_hc6[0]*_t221*_t30*_t31*_t38*nb + (0.1888e4 / 0.27e2)*_hc6[1]*_t100*_t14*_t232*_t38*_t99*na + (0.1888e4 / 0.81e2)*_hc6[1]*_t100*_t14*_t232*_t38*_t99*nb + 0.80e2*_hc6[1]*_t256*_t30*_t585*_t59*_t620*na + (0.80e2 / 0.3e1)*_hc6[1]*_t256*_t30*_t585*_t59*_t620*nb + (0.112e3 / 0.9e1)*_hc6[2]*_t15*_t224*_t258*_t38*_t64*na + (0.112e3 / 0.27e2)*_hc6[2]*_t15*_t224*_t258*_t38*_t64*nb + (0.8e1 / 0.9e1)*_hc6[3]*_t30*_t38*_t585*_t620*na + (0.8e1 / 0.27e2)*_hc6[3]*_t30*_t38*_t585*_t620*nb - _t1065*_t546 + (0.21e2 / 0.5e1)*_t113*_t201*_t30*_t620*_t623*_t87 + (0.7e1 / 0.5e1)*_t113*_t30*_t620*_t623*_t87*_t97 - _t1141 + (0.7e1 / 0.5e1)*_t15*_t201*_t256*_t258*_t308*_t38*_t64 + (0.7e1 / 0.15e2)*_t15*_t256*_t258*_t308*_t38*_t64*_t97 - _t1527 - 0.7e1 / 0.5e1*_t1779 - 0.8e1 / 0.15e2*_t1780 - _t445*(0.72e2*_hc5[0]*_t221 + 0.480e3*_hc5[0]*_t588*na*nb + (0.9680e4 / 0.81e2)*_hc5[1]*_t1189*_t3*_t5*na*nb + (0.32e2 / 0.3e1)*_hc5[1]*_t232*_t3*_t5 + (0.772e3 / 0.81e2)*_hc5[2]*_t1187*_t225*_t226*na*nb + (0.1e1 / 0.3e1)*_hc5[2]*_t224*_t225*_t226 + (0.16e2 / 0.9e1)*_hc5[3]*_t1181*_t558*na*nb + (0.1e1 / 0.54e2)*_hc5[4]*_t1183*_t1184*_t3*na*nb - _t1485*_t89 - _t1496*_t94 - 0.1e1 / 0.3e1*_t1900 - _t1901*_t599 - _t1902*_t599 - _t1908 - _t586*_t842 - _t592 - _t595*_t859) - _t627*_t97) + _t58*(_t1076*_t1581 - _t1076*_t660 + _t1077*_t843 - _t1080*_t1922 - _t1087*_t1920 - _t1092*_t704 - _t1092*_t707 - _t1143*_t454 + (0.1e1 / 0.4e1)*_t1145*_t469 - _t1146 - _t1147 + _t1148*_t1571 - _t1152*_t447 - 0.4e1*_t1280 + _t131*_t1554 + _t131*_t1584 + _t1326*_t1564 + _t1343*_t1602 - _t1482*_t316 - _t1556*_t203 + 0.144e3*_t1559*_t221 + (0.80e2 / 0.3e1)*_t1562 + (0.1e1 / 0.2e1)*_t1565*_t523 - _t1566*_t526 + _t1570*_t521 + _t1572*_t521 + _t1573*_t1812 + 0.144e3*_t1575*_t221 + _t1588*_t1823 + _t1588*_t1827 + _t1588*_t1927 + _t1589*_t1825 + (0.140e3 / 0.3e1)*_t1591 + 0.140e3*_t1593 + (0.944e3 / 0.9e1)*_t1594 + (0.944e3 / 0.3e1)*_t1596 + _t1600*_t455 + _t1608 + (0.21e2 / 0.4e1)*_t1797 + _t1800*_t1920 + _t1800*_t681*nb + _t1801*_t683 + 0.80e2*_t1802 - 0.24e2*_t1804 + 0.48e2*_t1813 + _t1814*_t843 - _t1816*_t285 + (0.7e1 / 0.8e1)*_t1818 + 0.80e2*_t1821 + 0.140e3*_t1830 + (0.944e3 / 0.3e1)*_t1831 + _t1912*_t468 - 0.96e2*_t1919 - _t1921*_t315 - _t1923*_t714 - _t1924*_t714 - 0.7e1 / 0.8e1*_t1925 - 0.2e1 / 0.3e1*_t1926 + _t1928*_t457 + _t453*_t683 - _t478*((0.2e1 / 0.15e2)*_hc9[1]*_t118*_t509*_t64*_t67 + (0.6e1 / 0.5e1)*_hc9[3]*_t109*_t194*_t64*_t67 + (0.2e1 / 0.15e2)*_hc9[3]*_t118*_t510*_t64*_t67 + 0.2e1*_hc9[3]*_t194*_t64*_t67*_t9*_t91 - _t1071*_t586 - _t1074*_t595 - _t1119*_t666 - _t1119*_t904 - _t1144*_t1915 - _t1159*_t1915 - _t125*_t1485 - _t1267*_t1913 - _t127*_t1914 - _t129*_t1496 - 0.1e1 / 0.3e1*_t1538 - _t1547*_t1917 - _t1550*_t1918 - _t1552*_t509 - _t1553 - 0.32e2 / 0.15e2*_t1789 - 0.8e1 / 0.45e2*_t1791 - _t1793*_t663 - _t1794*_t663 - _t1901*_t674 - _t1902*_t674 - _t1908 - 0.6e1 / 0.5e1*_t1916*_t909 - _t298*_t669 - _t672 - 0.8e1 / 0.5e1*_t905) - 0.40e2*_t933 - 0.160e3*_t935) - 0.18e2*_t87*_t999) + _t1175 - _t1467*_t834 + _t1467*_t838 + (0.2e1 / 0.9e1)*_t1471 - 0.20e2 / 0.9e1*_t1474 + (0.2e1 / 0.3e1)*_t1749 - _t1751*_t214 + _t1753*_t544 + _t1756 + 0.3e1*_t1757 - 0.20e2*_t1893*_t424 - 0.2e1 / 0.3e1*_t1894 + 0.80e2*_t1896 - 0.32e2 / 0.9e1*_t1897 + _t1898*_t826 + _t191*_t1949 + (0.8e1 / 0.3e1)*_t1950 - _t419*_t839;
  const double d4F_dnb4 = _t1041*(_hc13[1]*_t1160*_t1978 + 0.24e2*_t1002*_t1157 + _t1002*_t1446*_t1936 + _t1005*_t1955 + _t1013*_t1144*_t1879 + _t1031*_t630 + _t1101*_t1869 + _t1101*(_t1163 + _t1372*_t847 - _t1975) + _t1101*(-0.3e1 / 0.2e1*_t1162 + _t1411 + _t1412*_t167*_t847 - 0.3e1 / 0.2e1*_t1975 + 0.3e1*_t536) + _t1102*_t1160 + _t1105*_t1979 + _t1105*_t1981 + _t1107*_t1126*_t388 + 0.12e2*_t1119*_t999 + _t1144*_t1886*_t998 + _t1156*_t164*_t1873 + _t1164*_t1982 + _t1164*_t384*_t539 + _t1406*(_t212 * _t212 * _t212 * _t212) + _t1416*_t1951 + _t1421*_t1951 + _t1425*_t1965 + _t1428*_t1939*_t847 + _t1439*_t1951 + _t1453*_t1734 + _t1461*_t1743 + _t1465 + _t1693*_t1951 + _t170*(_t1119*_t1372 + _t1144*_t1393 - _t1144*_t1396 + _t1159*_t1393 - _t1159*_t1396 + _t1368 - _t1371*_t1852 - _t1371*_t1854 - _t1373*_t1951 + _t1381*_t1971 - _t1391*_t1971 + _t1397*_t1965 + (0.91e2 / 0.108e3)*_t1646 + _t1657*_t1951 + _t1658*_t1951 - _t168*_t1952 - _t1772*_t1972 + _t1772*_t1973 - _t1772*_t1974 + (0.7e1 / 0.6e1)*_t1856 + 0.2e1*_t1933 + _t1934*_t768 - 0.2e1*_t1937 + _t1953*_t377 - _t1953*_t489 + _t1956*_t377 - _t1956*_t489 - _t1958*_t1972 + _t1958*_t1973 - _t1958*_t1974 - _t1959*_t1972 + _t1959*_t1973 - _t1959*_t1974 - _t1965*_t992 + _t1966*_t377 - _t1966*_t489) + 0.64e2*_t1721 + _t1730*_t804 + (0.112e3 / 0.27e2)*_t1732 + (0.896e3 / 0.9e1)*_t1737 + (0.1888e4 / 0.81e2)*_t1738 + (0.1792e4 / 0.27e2)*_t1741 + (0.15104e5 / 0.81e2)*_t1744 + _t1772*_t1947 + _t1772*_t1976 + _t1772*_t1977 + _t1772*_t1983 + _t1872*_t1965 + _t1879*_t1881*_t509 + _t1882*_t509*_t998 + _t1946*_t509 + _t1952*_t213 + _t1953*_t392 + _t1953*_t542 + _t1956*_t392 + _t1958*_t1976 + _t1958*_t1977 + _t1958*_t1983 + _t1959*_t1976 + _t1959*_t1977 + _t1959*_t1983 + _t1966*_t542 + _t1979*_t1980 + _t1980*_t1981 + _t1982*_t539 + _t24*(_hc11[1]*_t1952 + _t1095*_t541 + _t1165*_t484 + _t1931*_t194 + _t1932) + _t37*(0.24e2*_t1088*_t1800 - _t1092*_t1337 - _t1092*_t1338 + _t1148*_t1321 + _t1154*_t843 - _t1313*_t1967 - _t1319*_t1836 - _t1320*_t1968 + _t1339*_t1928 + _t1351 + _t146*_t1962 - 0.160e3 / 0.3e1*_t1614 + (0.224e3 / 0.3e1)*_t1615 - 0.160e3 / 0.3e1*_t1619 + (0.784e3 / 0.9e1)*_t1623 + (0.3776e4 / 0.27e2)*_t1624 - _t1627*_t615 + (0.3776e4 / 0.27e2)*_t1628 + (0.224e3 / 0.3e1)*_t1839 + (0.784e3 / 0.9e1)*_t1843 + 0.32e2*_t1927*_t343 + 0.20e2*_t1930 - _t1969*_t337 - _t1970*_t735 + 0.32e2*_t355*_t521 + _t843*_t959 - 0.48e2*_t940 - 0.112e3 / 0.3e1*_t954) + _t384*(_t539 * _t539) + _t44*((0.15104e5 / 0.27e2)*_hc14[1]*_hc6[0]*_t100*_t113*_t14*_t232*_t99*na + (0.1792e4 / 0.9e1)*_hc14[1]*_hc6[1]*_t113*_t15*_t224*_t258*_t64*na + (0.64e2 / 0.3e1)*_hc14[1]*_hc6[2]*_t113*_t30*_t585*_t620*na + (0.4e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t1140*_t14*_t2*_t99 + (0.4e1 / 0.5e1)*_hc14[1]*_t100*_t103*_t118*_t14*_t519*_t99 + (0.1280e4 / 0.9e1)*_hc6[0]*_t139*_t30*_t585*_t620*_t623*na + (0.4480e4 / 0.9e1)*_hc6[0]*_t15*_t224*_t256*_t258*_t59*_t64*na + 0.256e3*_hc6[0]*_t221*_t30*_t31*_t38*na + (0.7552e4 / 0.81e2)*_hc6[1]*_t100*_t14*_t232*_t38*_t99*na + (0.320e3 / 0.3e1)*_hc6[1]*_t256*_t30*_t585*_t59*_t620*na + (0.448e3 / 0.27e2)*_hc6[2]*_t15*_t224*_t258*_t38*_t64*na + (0.32e2 / 0.27e2)*_hc6[3]*_t30*_t38*_t585*_t620*na + (0.28e2 / 0.5e1)*_t113*_t201*_t30*_t620*_t623*_t87 - _t1140*_t1176 - _t1246 + (0.28e2 / 0.15e2)*_t15*_t201*_t256*_t258*_t308*_t38*_t64 - 0.14e2 / 0.5e1*_t1779 - 0.32e2 / 0.45e2*_t1780 - _t445*(-_t1172*_t599 - _t1177*_t89 - _t1179*_t94 + _t1192 - 0.4e1 / 0.9e1*_t1900 + _t1961)) + _t58*((0.3776e4 / 0.9e1)*_hc10[0]*_hc14[1]*_t113*_t144*_t232*_t3*na + (0.320e3 / 0.3e1)*_hc10[0]*_t139*_t585*_t623*na + 0.192e3*M_PI*_hc10[0]*_t221*_t38*na + (0.560e3 / 0.3e1)*_hc10[0]*_t224*_t225*_t256*_t4*_t59*na + _hc14[1]*_t103*_t1145*_t144*_t2*_t3 + _hc14[1]*_t103*_t118*_t144*_t3*_t523 + 0.32e2*_hc14[1]*_t109*_t113*_t1148*_t144*_t3*na*nb + 0.96e2*_hc14[1]*_t109*_t113*_t144*_t3*_t526*na + 0.32e2*_hc14[1]*_t109*_t139*_t3*_t5*_t521 + (0.3776e4 / 0.9e1)*_hc14[1]*_t113*_t144*_t206*_t232*_t3*na*nb - _t1080*_t1968 - _t1092*_t1296 - _t1092*_t1297 + 0.7e1*_t113*_t204*_t623*_t87 - _t1145*_t1266 + 0.32e2*M_PI*_t1148*_t38*_t48*na*nb - _t1289*_t1836 - _t1295*_t459 - _t1311 + (0.320e3 / 0.3e1)*_t139*_t206*_t585*_t623*na*nb - 0.16e2*_t1557 - 0.32e2*_t1804 - 0.192e3*_t1919 - 0.7e1 / 0.4e1*_t1925 - 0.8e1 / 0.9e1*_t1926 + 0.6e1*_t1962*_t59 - _t1967*_t923 - _t1969*_t315 - _t1970*_t714 + 0.12e2*_t20*_t225*_t226*_t256*_t308*_t521 + (0.7e1 / 0.6e1)*_t204*_t225*_t256*_t308*_t38*_t4 + 0.192e3*M_PI*_t206*_t221*_t38*na*nb + (0.560e3 / 0.3e1)*_t206*_t224*_t225*_t256*_t4*_t59*na*nb + 0.96e2*M_PI*_t38*_t48*_t526*na - _t478*(_t1072*_t885 - _t1119*_t1270 - _t1144*_t1964 - _t1159*_t1964 - _t1172*_t674 - _t1177*_t125 - _t1179*_t129 - _t123*_t1952 - _t1267*_t1951 - _t1269*_t1914 - _t1277*_t1965 + _t1279 - 0.4e1 / 0.9e1*_t1538 - _t1772*_t1963 - 0.32e2 / 0.135e3*_t1791 + _t1792*_t885 - _t1953*_t475 - _t1956*_t475 - _t1958*_t1963 - _t1959*_t1963 + _t1961 - _t1966*_t475) - 0.80e2*_t933) + _t994*(0.6e1*_hc12[1]*_hc12[3]*_t1120*_t12*_t13*_t15*_t18*_t375*p->cam_omega + (0.1e1 / 0.2e1)*_hc12[1]*_t12*_t13*_t15*_t161*_t165*_t509*p->cam_omega + (0.1e1 / 0.2e1)*_hc12[3]*_t12*_t13*_t15*_t161*_t165*_t510*p->cam_omega - _t1096 - _t1119*_t767 + 0.2e1*_t1126*_t12*_t13*_t15*_t18*_t194*_t374*_t375*p->cam_omega - _t1144*_t992 - _t1156*_t770 - _t1158*_t1408 - _t1159*_t992 + 0.2e1*_t12*_t13*_t15*_t18*_t194*_t374*_t375*_t509*p->cam_omega - _t1407 - 0.7e1 / 0.12e2*_t980)) + 0.4e1*_t1175 + _t1346*_t1895 - _t1466*_t1893 + _t1477*_t1949 + _t1479*_t544 + _t1483 + (0.8e1 / 0.9e1)*_t1749 - 0.80e2 / 0.9e1*_t1752 - 0.4e1 / 0.3e1*_t1894 - 0.128e3 / 0.27e2*_t1897 + (0.16e2 / 0.3e1)*_t1950;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif