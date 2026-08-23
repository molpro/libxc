/*
  Generated from python/mgga_exc/mgga_xc_cc06.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_xc_cc06
*/

#ifndef _MGGA_XC_CC06_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_XC_CC06_KERNEL_BODY
#define _KMAX 0
#define _MGGA_XC_CC06_HELPER_BODIES
#include "mgga_xc_cc06.c"
#undef _MGGA_XC_CC06_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_XC_CC06_HELPER_BODIES
#include "mgga_xc_cc06.c"
#undef _MGGA_XC_CC06_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_XC_CC06_HELPER_BODIES
#include "mgga_xc_cc06.c"
#undef _MGGA_XC_CC06_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_XC_CC06_HELPER_BODIES
#include "mgga_xc_cc06.c"
#undef _MGGA_XC_CC06_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_XC_CC06_HELPER_BODIES
#include "mgga_xc_cc06.c"
#undef _MGGA_XC_CC06_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_xc_cc06.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_XC_CC06_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc0);
  const double _t1 = xc_powr(0.6e1, 1, 3)*M_CBRT3/(M_CBRTPI*M_CBRTPI);
  const double _t2 = (0.3e1 / 0.16e2)*_t1;
  const double _t3 = _t2/rs;
#if _KMAX >= 1
  const double _t4 = _t2/(rs * rs);
#endif
#if _KMAX >= 2
  const double _t5 = _hc0[0]*_t1;
  const double _t6 = (0.3e1 / 0.8e1)/(rs * rs * rs);
#endif
#if _KMAX >= 3
  const double _t7 = _t1*_t6;
  const double _t8 = (0.9e1 / 0.8e1)/(rs * rs * rs * rs);
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
  const double d4f_drs4 = -0.9e1 / 0.2e1*_t5/xc_powi(rs, 5);
  out[14] = d4f_drs4;
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
  const double _t1 = 0.0132882934*rs + 0.062182000000000001;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = (rs * rs);
  const double _t6 = 0.1018665524*_t3 + 0.4723158174*_t4 + 0.030651995080000001*_t5 + 0.2230841432*rs;
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = xc_log1p(_t7);
  const double _t9 = _t2*_t8;
  const double _t10 = 0.029729901239999999*_t3 + 0.34979731799999997*_t4 + 0.016775883539999998*_t5 + 0.12236657939999999*rs;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_log1p(_t11);
  const double _t13 = -0.0037573575*rs - 0.033773999999999998;
  const double _t14 = 0.58482233974552045*_t13;
  const double _t15 = _t12*_t14;
  const double _t16 = (zeta * zeta * zeta * zeta);
  const double _t17 = 0.0063883732000000002*rs + 0.03109;
  const double _t18 = -_t17;
  const double _t19 = 0.104655158*_t3 + 0.438956601*_t4 + 0.019436535299999998*_t5 + 0.19268649300000001*rs;
  const double _t20 = (0.1e1 / _t19);
  const double _t21 = xc_log1p(_t20);
  const double _t22 = _t15 + _t18*_t21 - _t9;
  const double _t23 = _t16*_t22;
#if _KMAX >= 1
  const double _t24 = _hc0[0]*_t22;
  const double _t25 = (zeta * zeta * zeta);
  const double _t26 = 0.4e1*_t25;
  const double _t27 = 0.0021973866044103793*_t12;
  const double _t28 = sqrt(rs);
  const double _t29 = (0.1e1 / _t4);
  const double _t30 = -0.15698273699999998*_t28 - 0.2194783005*_t29 - 0.038873070599999997*rs - 0.19268649300000001;
  const double _t31 = (0.1e1 / (_t19 * _t19));
  const double _t32 = _t20 + 0.1e1;
  const double _t33 = (0.1e1 / _t32);
  const double _t34 = -0.04459485186*_t28 - 0.17489865899999998*_t29 - 0.033551767079999996*rs - 0.12236657939999999;
  const double _t35 = (0.1e1 / (_t10 * _t10));
  const double _t36 = _t11 + 0.1e1;
  const double _t37 = (0.1e1 / _t36);
  const double _t38 = _t7 + 0.1e1;
  const double _t39 = (0.1e1 / _t38);
  const double _t40 = _t39/(_t6 * _t6);
  const double _t41 = -0.15279982860000002*_t28 - 0.2361579087*_t29 - 0.061303990160000002*rs - 0.2230841432;
  const double _t42 = _t2*_t41;
  const double _t43 = _t40*_t42 - 0.0132882934*_t8;
  const double _t44 = 0.58482233974552045*_t13*_t34*_t35*_t37 + _t18*_t30*_t31*_t33 - 0.0063883732000000002*_t21 - _t27 - _t43;
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
  const double _t54 = 0.0265765868*_t40*_t41;
  const double _t55 = 0.0043947732088207587*_t47;
  const double _t56 = (0.1e1 / _t28);
  const double _t57 = xc_powr(rs, -3, 2);
  const double _t58 = -0.07639991430000001*_t56 + 0.11807895435*_t57 - 0.061303990160000002;
  const double _t59 = _t40*_t58;
  const double _t60 = _t2*_t59;
  const double _t61 = -0.02229742593*_t56 + 0.087449329499999992*_t57 - 0.033551767079999996;
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
  const double _t76 = -0.30559965720000004*_t28 - 0.4723158174*_t29 - 0.12260798032*rs - 0.4461682864;
  const double _t77 = _t42*_t76;
  const double _t78 = _t75*_t77;
  const double _t79 = _t37/(_t10 * _t10 * _t10);
  const double _t80 = -0.089189703719999999*_t28 - 0.34979731799999997*_t29 - 0.067103534159999992*rs - 0.24473315879999999;
  const double _t81 = _t34*_t80;
  const double _t82 = _t79*_t81;
  const double _t83 = _t14*_t82;
  const double _t84 = _t31*_t33;
  const double _t85 = -0.078491368499999992*_t56 + 0.10973915025*_t57 - 0.038873070599999997;
  const double _t86 = _t84*_t85;
  const double _t87 = 0.0021973866044103793*rs + 0.019751789702565206;
  const double _t88 = (0.1e1 / (_t19 * _t19 * _t19 * _t19));
  const double _t89 = (0.1e1 / (_t32 * _t32));
  const double _t90 = (_t30 * _t30);
  const double _t91 = _t89*_t90;
  const double _t92 = _t88*_t91;
  const double _t93 = _t2*_t64;
  const double _t94 = _t33/(_t19 * _t19 * _t19);
  const double _t95 = -0.31396547399999997*_t28 - 0.438956601*_t29 - 0.077746141199999994*rs - 0.38537298600000003;
  const double _t96 = _t18*_t30;
  const double _t97 = _t95*_t96;
  const double _t98 = _t17*_t92 + _t18*_t86 - 0.0127767464*_t30*_t84 + _t54 - _t55 - _t60 + _t63 + _t67*_t93 + _t73*_t87 - _t78 + _t83 + _t94*_t97;
  const double _t99 = _t16*_t98;
#endif
#if _KMAX >= 3
  const double _t100 = 0.24e2*_t24;
  const double _t101 = _t22*_t49;
  const double _t102 = 0.36e2*_hc0[1];
  const double _t103 = 0.12e2*_hc0[2];
  const double _t104 = _t25*_t44;
  const double _t105 = _hc0[0]*_t98;
  const double _t106 = 0.039864880200000001*_t59;
  const double _t107 = 0.006592159813231138*_t62;
  const double _t108 = (0.1e1 / _t3);
  const double _t109 = xc_powr(rs, -5, 2);
  const double _t110 = 0.038199957150000005*_t108 - 0.17711843152500001*_t109;
  const double _t111 = _t110*_t40;
  const double _t112 = _t111*_t2;
  const double _t113 = 0.039864880200000001*_t68;
  const double _t114 = 0.011148712965*_t108 - 0.13117399424999998*_t109;
  const double _t115 = _t114*_t46;
  const double _t116 = _t115*_t14;
  const double _t117 = 0.006592159813231138*_t73;
  const double _t118 = 0.0265765868*rs + 0.124364;
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
  const double _t129 = 1.1696446794910409*_t13;
  const double _t130 = _t128*_t129;
  const double _t131 = _t41*_t75;
  const double _t132 = 0.039864880200000001*_t131*_t76;
  const double _t133 = 0.006592159813231138*_t82;
  const double _t134 = -0.15279982860000002*_t56 + 0.2361579087*_t57 - 0.12260798032;
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
  const double _t145 = -0.04459485186*_t56 + 0.17489865899999998*_t57 - 0.067103534159999992;
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
  const double _t157 = -0.61119931440000008*_t28 - 0.94463163480000001*_t29 - 0.24521596064000001*rs - 0.89233657280000001;
  const double _t158 = xc_powi(_t6, -5);
  const double _t159 = _t158*_t67;
  const double _t160 = _t159*_t2;
  const double _t161 = _t157*_t160;
  const double _t162 = _t160*_t76;
  const double _t163 = -0.17837940744*_t28 - 0.69959463599999994*_t29 - 0.13420706831999998*rs - 0.48946631759999998;
  const double _t164 = xc_powi(_t10, -5);
  const double _t165 = _t164*_t72;
  const double _t166 = _t14*_t165;
  const double _t167 = _t163*_t166;
  const double _t168 = _t166*_t80;
  const double _t169 = -0.45839948580000006*_t28 - 0.70847372610000003*_t29 - 0.18391197048000002*rs - 0.66925242959999998;
  const double _t170 = _t169*_t39;
  const double _t171 = _t170*_t64;
  const double _t172 = _t171*_t77;
  const double _t173 = -0.13378455557999999*_t28 - 0.52469597699999992*_t29 - 0.10065530123999999*rs - 0.36709973819999997;
  const double _t174 = _t173*_t37*_t69;
  const double _t175 = _t174*_t81;
  const double _t176 = _hc0[0]*_t14;
  const double _t177 = 0.039245684249999996*_t108 - 0.16460872537499999*_t109;
  const double _t178 = _t177*_t84;
  const double _t179 = (_t30 * _t30 * _t30);
  const double _t180 = (0.1e1 / (_t32 * _t32 * _t32));
  const double _t181 = xc_powi(_t19, -6);
  const double _t182 = _t180*_t181;
  const double _t183 = _t179*_t182;
  const double _t184 = _t30*_t94;
  const double _t185 = -0.15698273699999998*_t56 + 0.2194783005*_t57 - 0.077746141199999994;
  const double _t186 = _t185*_t96;
  const double _t187 = _t88*_t89;
  const double _t188 = _t187*_t85;
  const double _t189 = _t94*_t95;
  const double _t190 = _t189*_t85;
  const double _t191 = 0.2e1*_t18;
  const double _t192 = -0.62793094799999993*_t28 - 0.877913202*_t29 - 0.15549228239999999*rs - 0.77074597200000006;
  const double _t193 = xc_powi(_t19, -5);
  const double _t194 = _t193*_t91;
  const double _t195 = _t18*_t194;
  const double _t196 = -0.47094821099999995*_t28 - 0.65843490149999995*_t29 - 0.11661921179999998*rs - 0.57805947899999999;
  const double _t197 = _t196*_t33*_t88;
  const double _t198 = _t14*_t175;
  const double _t199 = _t106 - _t107 - _t112 - _t113 + _t116 + _t117 + _t118*_t123 + _t128*(-0.0043947732088207587*rs - 0.039503579405130412) + _t132 - _t133 - _t136 + _t139 + _t140 - _t144 - _t149 - _t151 + _t153 + _t156 + _t161 + _t162 - _t167 - _t168 - _t172 + _t178*_t18 + _t183*(-0.0127767464*rs - 0.062179999999999999) - 0.019165119600000002*_t184*_t95 - _t186*_t187 + _t186*_t94 - _t188*_t96 + _t190*_t191 - _t192*_t195 - _t195*_t95 + _t197*_t97 + _t198 - 0.019165119600000002*_t86 + 0.019165119600000002*_t92;
  const double _t200 = _t16*_t199;
#endif
#if _KMAX >= 4
  const double _t201 = 0.053153173599999999*_t111;
  const double _t202 = 0.0087895464176415174*_t115;
  const double _t203 = pow(rs, -2.5);
  const double _t204 = xc_powr(rs, -7, 2);
  const double _t205 = _t2*_t40*(-0.057299935725000008*_t203 + 0.44279607881250005*_t204);
  const double _t206 = 0.1063063472*_t123;
  const double _t207 = _t14*_t46*(-0.016723069447499999*_t203 + 0.32793498562499995*_t204);
  const double _t208 = 0.017579092835283035*_t128;
  const double _t209 = (_t58 * _t58)*_t65;
  const double _t210 = _t146*(_t61 * _t61);
  const double _t211 = 0.079729760400000002*rs + 0.37309199999999998;
  const double _t212 = (_t41 * _t41 * _t41 * _t41)/((_t38 * _t38 * _t38 * _t38)*xc_powi(_t6, 8));
  const double _t213 = (_t34 * _t34 * _t34 * _t34)/(xc_powi(_t10, 8)*(_t36 * _t36 * _t36 * _t36));
  const double _t214 = 0.053153173599999999*_t134;
  const double _t215 = _t137*_t41;
  const double _t216 = _t214*_t215;
  const double _t217 = 0.053153173599999999*_t215*_t58;
  const double _t218 = _t131*_t214;
  const double _t219 = 0.1063063472*_t142;
  const double _t220 = 0.0087895464176415174*_t34;
  const double _t221 = _t145*_t220;
  const double _t222 = _t146*_t221;
  const double _t223 = _t150*_t220;
  const double _t224 = _t221*_t79;
  const double _t225 = 0.017579092835283035*_t155;
  const double _t226 = _t134*_t58;
  const double _t227 = _t226*_t65*_t93;
  const double _t228 = 0.3e1*_t2;
  const double _t229 = _t226*_t228*_t75;
  const double _t230 = _t14*_t145;
  const double _t231 = _t150*_t230;
  const double _t232 = 1.7544670192365612*_t13;
  const double _t233 = _t232*_t61;
  const double _t234 = _t152*_t233;
  const double _t235 = 0.07639991430000001*_t108 - 0.35423686305000002*_t109;
  const double _t236 = _t135*_t235;
  const double _t237 = 0.032487183262504181*_t28 + 0.050210169272576204*_t29 + 0.013034006525388686*rs + 0.047430520763667439;
  const double _t238 = 0.01624359163125209*_t28 + 0.025105084636288102*_t29 + 0.0065170032626943432*rs + 0.023715260381833719;
  const double _t239 = 0.2e1*_t110*_t138;
  const double _t240 = _t138*_t235;
  const double _t241 = _t110*_t141*_t228;
  const double _t242 = _t114*_t129*_t146*_t34;
  const double _t243 = 0.02229742593*_t108 - 0.26234798849999996*_t109;
  const double _t244 = _t148*_t243;
  const double _t245 = _t114*_t154*_t232;
  const double _t246 = _t147*_t243*_t79;
  const double _t247 = 0.0087895464176415174*_t165;
  const double _t248 = _hc0[0]*_t163;
  const double _t249 = _hc0[0]*_t80;
  const double _t250 = -0.22919974290000003*_t56 + 0.35423686305000002*_t57 - 0.18391197048000002;
  const double _t251 = _t122*_t143*_t66;
  const double _t252 = _t250*_t251;
  const double _t253 = _t134*_t251;
  const double _t254 = _t251*_t58;
  const double _t255 = _t160*(-0.30559965720000004*_t56 + 0.4723158174*_t57 - 0.24521596064000001);
  const double _t256 = 0.2e1*_t134;
  const double _t257 = _t160*_t256;
  const double _t258 = -0.066892277789999996*_t56 + 0.26234798849999996*_t57 - 0.10065530123999999;
  const double _t259 = _t127*_t129*_t71;
  const double _t260 = _t258*_t259;
  const double _t261 = _t145*_t259;
  const double _t262 = _t259*_t61;
  const double _t263 = _t166*(-0.089189703719999999*_t56 + 0.34979731799999997*_t57 - 0.13420706831999998);
  const double _t264 = _t129*_t145;
  const double _t265 = _t165*_t264;
  const double _t266 = _t119*_t120*_t143/xc_powi(_t6, 7);
  const double _t267 = _t266*(-0.91679897160000012*_t28 - 1.4169474522000001*_t29 - 0.36782394096000004*rs - 1.3385048592);
  const double _t268 = _t157*_t266;
  const double _t269 = _t266*_t76;
  const double _t270 = _t124*_t125*_t129/xc_powi(_t10, 7);
  const double _t271 = _t270*(-0.26756911115999998*_t28 - 1.0493919539999998*_t29 - 0.20131060247999999*rs - 0.73419947639999994);
  const double _t272 = _t163*_t270;
  const double _t273 = _t270*_t80;
  const double _t274 = 0.053153173599999999*_t171*_t41*_t76;
  const double _t275 = 0.0087895464176415174*_t175;
  const double _t276 = _t250*_t39*_t64*_t77;
  const double _t277 = _t158*_t65;
  const double _t278 = _t157*_t42;
  const double _t279 = _t256*_t277*_t278;
  const double _t280 = _t134*_t277*_t77;
  const double _t281 = _t277*_t58;
  const double _t282 = _t278*_t281;
  const double _t283 = 0.2e1*_t281*_t77;
  const double _t284 = _t171*_t256*_t42;
  const double _t285 = 0.3e1*_t170*_t58*_t76*_t93;
  const double _t286 = _t264*_t34;
  const double _t287 = _t164*_t70;
  const double _t288 = _t286*_t287;
  const double _t289 = _t230*_t287*_t81;
  const double _t290 = _t287*_t61;
  const double _t291 = _t147*_t290;
  const double _t292 = _t129*_t290*_t81;
  const double _t293 = _t258*_t69;
  const double _t294 = _t37*_t81;
  const double _t295 = _t176*_t294;
  const double _t296 = _t174*_t286;
  const double _t297 = _t174*_t233;
  const double _t298 = _t121*_t2*_t67*(-0.76399914300000016*_t28 - 1.1807895435*_t29 - 0.3065199508*rs - 1.115420716);
  const double _t299 = _t157*_t298;
  const double _t300 = _t298*_t76;
  const double _t301 = _t121*_t169*_t2*_t67*_t76;
  const double _t302 = _t126*_t72*(-0.22297425930000001*_t28 - 0.87449329499999995*_t29 - 0.16775883539999997*rs - 0.61183289699999999);
  const double _t303 = _t176*_t302;
  const double _t304 = _t126*_t173*_t72*_t80;
  const double _t305 = _t157*_t158*_t170*_t77;
  const double _t306 = _t163*_t164*_t173;
  const double _t307 = 0.025553492800000001*_t30;
  const double _t308 = _t18*_t185;
  const double _t309 = _t96*(0.078491368499999992*_t108 - 0.32921745074999997*_t109);
  const double _t310 = 0.3e1*_t18;
  const double _t311 = -0.23547410549999997*_t56 + 0.32921745074999997*_t57 - 0.11661921179999998;
  const double _t312 = _t182*_t90;
  const double _t313 = _t191*_t312;
  const double _t314 = _t179*_t180*_t191/xc_powi(_t19, 7);
  const double _t315 = _t197*_t95;
  const double _t316 = _t33*_t97;
  const double _t317 = _t14*_t294;
  const double _t318 = _t193*_t89;
  const double _t319 = 0.2e1*_t186;
  const double _t320 = _t318*_t85;
  const double _t321 = _t14*_t302;
  const double _t322 = -0.78491368499999992*_t28 - 1.0973915025000001*_t29 - 0.19436535299999999*rs - 0.96343246500000013;
  const double _t323 = _t18*_t181*_t91;
  const double _t324 = _t323*_t95;
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
  const double d4f_drs4 = 3.5089340384731225*_hc0[0]*_t13*_t213 + _hc0[0]*_t16*(-_t14*_t304 + _t159*_t237 + _t159*_t238 - _t163*_t288 - _t163*_t291 - _t163*_t321 + _t165*(-0.0015678740816452686*_t28 - 0.0061491195266550206*_t29 - 0.0011796192565742263*rs - 0.0043021869184172654) + _t165*(-0.00078393704082263429*_t28 - 0.0030745597633275103*_t29 - 0.00058980962828711315*rs - 0.0021510934592086327) + _t17*_t187*(_t85 * _t85) - 0.2e1*_t177*_t187*_t96 + _t177*_t189*_t310 - 0.025553492800000001*_t178 + _t18*_t84*(-0.058868526374999994*_t203 + 0.41152181343749994*_t204) - 0.051106985600000002*_t183 - 0.025553492800000001*_t184*_t185 + _t185*_t187*_t307 - 0.2e1*_t185*_t195 - _t185*_t318*_t97 - _t187*_t309 + _t188*_t307 - _t188*_t308 - 0.051106985600000002*_t190 + _t192*_t193*_t196*_t316 + _t192*_t314 - _t192*_t318*_t319 - _t192*_t320*_t96 - _t192*_t322*_t323 + _t194*(-0.016045828958615175*_t28 - 0.022433748686331946*_t29 - 0.0039733709187639663*rs - 0.019695251646131003) + _t194*(-0.0080229144793075875*_t28 - 0.011216874343165973*_t29 - 0.0019866854593819832*rs - 0.0098476258230655016) - _t195*(-0.31396547399999997*_t56 + 0.438956601*_t57 - 0.15549228239999999) - _t196*_t324 + _t197*_t319 + _t201 - _t202 - _t205 + _t206 + _t207 - _t208 + _t209*_t93 + _t210*_t87 - _t211*_t212 + _t213*(0.013184319626462274*rs + 0.11851073821539124) - _t216 - _t217 + _t218 + _t219 + _t222 + _t223 - _t224 - _t225 + _t227 - _t229 - _t231 + _t234 - _t236 + _t239 + _t240 - _t241 - _t242 - _t244 + _t245 + _t246 - _t252 - _t253 - _t254 + _t255 + _t257 + _t260 + _t261 + _t262 - _t263 - _t265 - _t267 - _t268 - _t269 + _t271 + _t272 + _t273 + _t274 - _t275 - _t276 + _t279 + _t280 + _t282 + _t283 - _t284 - _t285 - _t289 - _t292 + _t293*_t317 + _t296 + _t297*_t80 + _t299 + _t300 + _t301 - _t305 + _t306*_t317 - _t307*_t315 + 0.2e1*_t308*_t312 + 0.3e1*_t308*_t85*_t94 + _t309*_t94 + _t310*_t315*_t85 + _t311*_t313 + _t311*_t316*_t88 + _t313*_t85 + _t314*_t95 + _t314*(-0.9418964219999999*_t28 - 1.3168698029999999*_t29 - 0.23323842359999997*rs - 1.156118958) - 0.2e1*_t320*_t97 - _t321*_t80 - _t322*_t324 + (_t30 * _t30 * _t30 * _t30)*(0.038330239200000005*rs + 0.18653999999999998)/(xc_powi(_t19, 8)*(_t32 * _t32 * _t32 * _t32))) + _hc0[0]*_t202 - _hc0[0]*_t207 + _hc0[0]*_t208 - _hc0[0]*_t222 - _hc0[0]*_t223 + _hc0[0]*_t224 + _hc0[0]*_t225 + _hc0[0]*_t231 - _hc0[0]*_t234 + _hc0[0]*_t242 + _hc0[0]*_t244 - _hc0[0]*_t245 - _hc0[0]*_t246 - _hc0[0]*_t260 - _hc0[0]*_t261 - _hc0[0]*_t262 + _hc0[0]*_t263 + _hc0[0]*_t265 - _hc0[0]*_t271 - _hc0[0]*_t272 - _hc0[0]*_t273 + _hc0[0]*_t275 + _hc0[0]*_t289 + _hc0[0]*_t292 - _hc0[0]*_t296 + _t1*_t209*_t64 - _t159*_t237 - _t159*_t238 + _t163*_t303 + _t176*_t210 + _t176*_t304 - _t201 + _t205 - _t206 + _t211*_t212 + _t216 + _t217 - _t218 - _t219 - _t227 + _t229 + _t236 - _t239 - _t240 + _t241 - _t247*_t248 - _t247*_t249 + _t248*_t288 + _t248*_t291 - _t249*_t297 + _t252 + _t253 + _t254 - _t255 - _t257 + _t267 + _t268 + _t269 - _t274 + _t276 - _t279 - _t280 - _t282 - _t283 + _t284 + _t285 - _t293*_t295 - _t295*_t306 - _t299 - _t300 - _t301 + _t303*_t80 + _t305;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_z0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)*M_CBRT3/(M_CBRTPI*M_CBRTPI);
  const double _t2 = (0.3e1 / 0.16e2)*_t1;

  const double f = -_t2/rs;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t2/(rs * rs);
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = -0.3e1 / 0.8e1*_t1/(rs * rs * rs);
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.9e1 / 0.8e1)*_t1/(rs * rs * rs * rs);
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = -0.9e1 / 0.2e1*_t1/xc_powi(rs, 5);
  out[4] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {

  const double _t1 = 0.0132882934*rs + 0.062182000000000001;
  const double _t2 = -_t1;
  const double _t3 = pow(rs, 1.5);
  const double _t4 = xc_powr(rs, 1, 2);
  const double _t5 = 0.1018665524*_t3 + 0.4723158174*_t4 + 0.030651995080000001*(rs * rs) + 0.2230841432*rs;
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = xc_log1p(_t6);
#if _KMAX >= 1
  const double _t8 = sqrt(rs);
  const double _t9 = (0.1e1 / _t4);
  const double _t10 = -0.15279982860000002*_t8 - 0.2361579087*_t9 - 0.061303990160000002*rs - 0.2230841432;
  const double _t11 = (0.1e1 / (_t5 * _t5));
  const double _t12 = _t6 + 0.1e1;
  const double _t13 = (0.1e1 / _t12);
#endif
#if _KMAX >= 2
  const double _t14 = _t11*_t13;
  const double _t15 = (0.1e1 / _t8);
  const double _t16 = xc_powr(rs, -3, 2);
  const double _t17 = -0.07639991430000001*_t15 + 0.11807895435*_t16 - 0.061303990160000002;
  const double _t18 = _t14*_t17;
  const double _t19 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t20 = (0.1e1 / (_t12 * _t12));
  const double _t21 = (_t10 * _t10);
  const double _t22 = _t20*_t21;
  const double _t23 = _t19*_t22;
  const double _t24 = _t13/(_t5 * _t5 * _t5);
  const double _t25 = -0.30559965720000004*_t8 - 0.4723158174*_t9 - 0.12260798032*rs - 0.4461682864;
  const double _t26 = _t10*_t2;
  const double _t27 = _t25*_t26;
#endif
#if _KMAX >= 3
  const double _t28 = (0.1e1 / _t3);
  const double _t29 = xc_powr(rs, -5, 2);
  const double _t30 = 0.038199957150000005*_t28 - 0.17711843152500001*_t29;
  const double _t31 = _t14*_t30;
  const double _t32 = (_t10 * _t10 * _t10);
  const double _t33 = (0.1e1 / (_t12 * _t12 * _t12));
  const double _t34 = xc_powi(_t5, -6);
  const double _t35 = _t33*_t34;
  const double _t36 = _t32*_t35;
  const double _t37 = _t10*_t24;
  const double _t38 = -0.15279982860000002*_t15 + 0.2361579087*_t16 - 0.12260798032;
  const double _t39 = _t26*_t38;
  const double _t40 = _t19*_t20;
  const double _t41 = _t17*_t40;
  const double _t42 = _t24*_t25;
  const double _t43 = _t17*_t42;
  const double _t44 = 0.2e1*_t2;
  const double _t45 = -0.61119931440000008*_t8 - 0.94463163480000001*_t9 - 0.24521596064000001*rs - 0.89233657280000001;
  const double _t46 = xc_powi(_t5, -5);
  const double _t47 = _t22*_t46;
  const double _t48 = _t2*_t47;
  const double _t49 = -0.45839948580000006*_t8 - 0.70847372610000003*_t9 - 0.18391197048000002*rs - 0.66925242959999998;
  const double _t50 = _t13*_t19*_t49;
#endif
#if _KMAX >= 4
  const double _t51 = 0.053153173599999999*_t10;
  const double _t52 = _t2*_t38;
  const double _t53 = _t26*(0.07639991430000001*_t28 - 0.35423686305000002*_t29);
  const double _t54 = 0.3e1*_t2;
  const double _t55 = -0.22919974290000003*_t15 + 0.35423686305000002*_t16 - 0.18391197048000002;
  const double _t56 = _t21*_t35;
  const double _t57 = _t44*_t56;
  const double _t58 = _t32*_t33*_t44/xc_powi(_t5, 7);
  const double _t59 = _t25*_t50;
  const double _t60 = _t13*_t27;
  const double _t61 = _t20*_t46;
  const double _t62 = 0.2e1*_t39;
  const double _t63 = _t17*_t61;
  const double _t64 = _t2*_t22*_t34*(-0.76399914300000016*_t8 - 1.1807895435*_t9 - 0.3065199508*rs - 1.115420716);
#endif

  const double f = _t2*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = _t10*_t11*_t13*_t2 - 0.0132882934*_t7;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t1*_t23 - 0.0265765868*_t10*_t14 + _t18*_t2 + _t24*_t27;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = -0.039864880200000001*_t18 + _t2*_t31 + 0.039864880200000001*_t23 + _t24*_t39 - 0.039864880200000001*_t25*_t37 - _t25*_t48 - _t26*_t41 + _t27*_t50 + _t36*(-0.0265765868*rs - 0.124364) - _t39*_t40 + _t43*_t44 - _t45*_t48;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t1*(_t17 * _t17)*_t40 + (_t10 * _t10 * _t10 * _t10)*(0.079729760400000002*rs + 0.37309199999999998)/((_t12 * _t12 * _t12 * _t12)*xc_powi(_t5, 8)) + _t14*_t2*(-0.057299935725000008*pow(rs, -2.5) + 0.44279607881250005/xc_powr(rs, 7, 2)) + 0.3e1*_t17*_t24*_t52 + _t17*_t54*_t59 + _t17*_t57 + _t19*_t55*_t60 - _t2*_t22*_t25*_t34*_t49 + _t24*_t53 + _t25*_t58 - _t25*_t64 - 0.2e1*_t26*_t30*_t40 - _t26*_t45*_t63 - _t27*_t38*_t61 - 0.2e1*_t27*_t63 + _t30*_t42*_t54 - 0.053153173599999999*_t31 - 0.1063063472*_t36 - 0.053153173599999999*_t37*_t38 + _t38*_t40*_t51 - 0.2e1*_t38*_t48 - _t40*_t53 + _t41*_t51 - _t41*_t52 - 0.1063063472*_t43 + _t45*_t46*_t49*_t60 + _t45*_t58 - _t45*_t61*_t62 - _t45*_t64 + _t47*(-0.032487183262504181*_t8 - 0.050210169272576204*_t9 - 0.013034006525388686*rs - 0.047430520763667439) + _t47*(-0.01624359163125209*_t8 - 0.025105084636288102*_t9 - 0.0065170032626943432*rs - 0.023715260381833719) - _t48*(-0.30559965720000004*_t15 + 0.4723158174*_t16 - 0.24521596064000001) + _t50*_t62 - _t51*_t59 + 0.2e1*_t52*_t56 + _t55*_t57 + _t58*(-0.91679897160000012*_t8 - 1.4169474522000001*_t9 - 0.36782394096000004*rs - 1.3385048592);
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = _t1/M_CBRTPI;
  const double _t3 = (0.1e1 / 0.2e1)*_t2/xc_powr(na, 1, 3);
  const double _t4 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  const double _t6 = xc_powr(na, -5, 3);
  const double _t7 = xc_powr(0.6e1, 2, 3);
  const double _t8 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t9 = _t7*_t8;
  const double _t10 = _t6*_t9;
  const double _t11 = _t10*la;
  const double _t12 = 0.002*_t11 - 0.00069999999999999999;
  const double _t13 = 0.0064999999999999997*_t11 + 0.1e1;
  const double _t14 = (0.1e1 / _t13);
  const double _t15 = _t12*_t14 + 0.1e1;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_spin_z0_k, _KMAX)(p, _t3, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, _t3, _hc1);
  const double _t5 = _hc1[0] + 0.2e1*my_piecewise3(_t4, 0, _hc0[0]);
  const double _t16 = _t15*_t5;
  const double zk = _t16;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t17 = (0.1e1 / 0.6e1)/xc_powr(na, 4, 3);
  const double _t22 = xc_powr(na, -8, 3);
  const double _t23 = _t22*_t9;
  const double _t24 = 0.0033333333333333335*_t14*_t23;
  const double _t25 = (0.1e1 / (_t13 * _t13));
  const double _t26 = _t12*_t25;
  const double _t27 = 0.010833333333333334*_t23*_t26*la - _t24*la;
  const double _t29 = -0.0064999999999999997*_t10*_t26 + 0.002*_t14*_t6*_t7*_t8;
  const double _t18 = _hc1[1]*_t2;
  const double _t19 = _hc0[1]*_t2;
  const double _t20 = -_t17*_t18 + 0.2e1*my_piecewise3(_t4, 0, -_t17*_t19);
  const double _t21 = _t15*_t20;
  const double _t28 = _t27*_t5;
  const double _t30 = _t29*_t5;
  const double dF_dna = _t16 + _t21*na + _t28*na;
  const double dF_dla = _t30*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
#endif
#if _KMAX >= 2
  const double _t31 = (0.2e1 / 0.9e1)/xc_powr(na, 7, 3);
  const double _t32 = (0.1e1 / 0.36e2)*_t23;
  const double _t37 = xc_powr(na, -11, 3);
  const double _t38 = _t37*_t9;
  const double _t39 = (la * la);
  const double _t40 = xc_powr(na, -16, 3);
  const double _t41 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t42 = _t1*_t41;
  const double _t43 = _t25*_t42;
  const double _t44 = _t40*_t43;
  const double _t45 = 0.028888888888888888*_t26*_t38;
  const double _t46 = _t40*_t42;
  const double _t47 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t48 = _t12*_t47;
  const double _t49 = _t46*_t48;
  const double _t50 = 0.0088888888888888889*_t14*_t38*la - 0.00043333333333333342*_t39*_t44 + 0.0014083333333333335*_t39*_t49 - _t45*la;
  const double _t53 = xc_powr(na, -13, 3);
  const double _t54 = _t42*_t48;
  const double _t55 = _t53*_t54;
  const double _t56 = 0.00026000000000000003*_t1*_t25*_t41*_t53*la + 0.010833333333333334*_t12*_t22*_t25*_t7*_t8 - _t24 - 0.00084500000000000005*_t55*la;
  const double _t57 = xc_powr(na, -10, 3);
  const double _t58 = -0.000156*_t43*_t57 + 0.00050699999999999996*_t54*_t57;
  const double _t33 = _hc1[2]*_t32 + _t18*_t31 + 0.2e1*my_piecewise3(_t4, 0, _hc0[2]*_t32 + _t19*_t31);
  const double _t34 = _t15*_t33;
  const double _t35 = _t20*na;
  const double _t36 = 0.2e1*_t35;
  const double _t51 = _t5*na;
  const double _t52 = _t20*_t29;
  const double _t59 = _t5*_t58;
  const double d2F_dna2 = 0.2e1*_t21 + _t27*_t36 + 0.2e1*_t28 + _t34*na + _t50*_t51;
  const double d2F_dna_dla = _t30 + _t51*_t56 + _t52*na;
  const double d2F_dla2 = _t59*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
#endif
#if _KMAX >= 3
  const double _t61 = (0.1e1 / 0.36e2)/(na * na * na * na);
  const double _t62 = (0.1e1 / M_PI);
  const double _t64 = (0.14e2 / 0.27e2)*_t57;
  const double _t65 = (0.1e1 / 0.9e1)*_t38;
  const double _t70 = 0.3e1*na;
  const double _t73 = xc_powi(na, -8);
  const double _t74 = (la * la * la);
  const double _t75 = (0.1e1 / (M_PI * M_PI));
  const double _t76 = _t47*_t75;
  const double _t77 = _t74*_t76;
  const double _t78 = xc_powr(na, -14, 3);
  const double _t79 = _t78*_t9;
  const double _t80 = 0.03259259259259259*_t14*_t79;
  const double _t81 = xc_powr(na, -19, 3);
  const double _t82 = _t39*_t43;
  const double _t83 = (0.1e1 / (_t13 * _t13 * _t13 * _t13));
  const double _t84 = _t12*_t75*_t83;
  const double _t85 = _t74*_t84;
  const double _t86 = _t39*_t54;
  const double _t87 = 0.10592592592592592*_t26*_t79*la - 8.4500000000000008e-5*_t73*_t77 + 0.00027462500000000002*_t73*_t85 - _t80*la + 0.0034666666666666669*_t81*_t82 - 0.011266666666666668*_t81*_t86;
  const double _t90 = xc_powi(na, -7);
  const double _t91 = 0.0050699999999999999*_t1*_t12*_t40*_t41*_t47*la + 0.0088888888888888889*_t14*_t37*_t7*_t8 + 5.0700000000000013e-5*_t39*_t47*_t75*_t90 - 0.00016477500000000003*_t39*_t84*_t90 - 0.0015600000000000002*_t44*la - _t45;
  const double _t93 = xc_powi(na, -6);
  const double _t94 = _t76*_t93;
  const double _t95 = 0.00052000000000000006*_t43*_t53 - 0.0016900000000000001*_t55 + 9.8864999999999996e-5*_t84*_t93*la - 3.0420000000000004e-5*_t94*la;
  const double _t96 = xc_powi(na, -5);
  const double _t97 = 1.8252000000000001e-5*_t47*_t75*_t96 - 5.9318999999999992e-5*_t84*_t96;
  const double _t60 = 0.6e1*_t20;
  const double _t63 = _hc1[3]*_t62;
  const double _t66 = _hc0[3]*_t62;
  const double _t67 = -_hc1[2]*_t65 - _t18*_t64 - _t61*_t63 + 0.2e1*my_piecewise3(_t4, 0, -_hc0[2]*_t65 - _t19*_t64 - _t61*_t66);
  const double _t68 = _t15*_t67;
  const double _t69 = _t27*_t33;
  const double _t71 = 0.3e1*_t5;
  const double _t72 = _t20*_t50;
  const double _t88 = _t29*_t33;
  const double _t89 = 0.2e1*_t5;
  const double _t92 = _t20*_t58;
  const double _t98 = _t5*_t97;
  const double d3F_dna3 = _t27*_t60 + 0.3e1*_t34 + _t50*_t71 + _t51*_t87 + _t68*na + _t69*_t70 + _t70*_t72;
  const double d3F_dna2_dla = _t36*_t56 + _t51*_t91 + 0.2e1*_t52 + _t56*_t89 + _t88*na;
  const double d3F_dna_dla2 = _t51*_t95 + _t59 + _t92*na;
  const double d3F_dla3 = _t98*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
#endif
#if _KMAX >= 4
  const double _t99 = (0.2e1 / 0.9e1)*_t96;
  const double _t100 = (0.1e1 / 0.216e3)*_t46;
  const double _t101 = (0.140e3 / 0.81e2)*_t53;
  const double _t102 = (0.40e2 / 0.81e2)*_t79;
  const double _t105 = 0.4e1*_t87;
  const double _t106 = xc_powi(na, -9);
  const double _t107 = _t9*la/xc_powr(na, 17, 3);
  const double _t108 = xc_powr(na, -22, 3);
  const double _t109 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t110 = _t109*_t7;
  const double _t111 = _t110*_t83;
  const double _t112 = (la * la * la * la)/xc_powr(na, 32, 3);
  const double _t113 = _t110*_t12/xc_powi(_t13, 5);
  const double _t114 = xc_powr(na, -29, 3);
  const double _t115 = _t90*la;
  const double _t116 = _t39/xc_powr(na, 26, 3);
  const double _t117 = xc_powr(na, -23, 3);
  const double _t118 = xc_powr(na, -20, 3);
  const double _t103 = _t67*na;
  const double _t104 = _t33*na;
  const double d4F_dna4 = 0.4e1*_t103*_t27 + 0.6e1*_t104*_t50 + _t105*_t35 + _t105*_t5 + _t15*na*(_hc1[2]*_t102 + _hc1[4]*_t100 + _t101*_t18 + _t63*_t99 + 0.2e1*my_piecewise3(_t4, 0, _hc0[2]*_t102 + _hc0[4]*_t100 + _t101*_t19 + _t66*_t99)) + _t51*(0.0013520000000000003*_t106*_t77 - 0.0043940000000000003*_t106*_t85 + 0.15209876543209877*_t107*_t14 - 0.49432098765432103*_t107*_t26 - 0.026192592592592594*_t108*_t82 + 0.085125925925925938*_t108*_t86 - 3.661666666666667e-6*_t111*_t112 + 1.1900416666666667e-5*_t112*_t113) + 0.4e1*_t68 + 0.12e2*_t69 + 0.12e2*_t72;
  const double d4F_dna3_dla = _t103*_t29 + 0.3e1*_t104*_t56 + 0.3e1*_t35*_t91 + _t51*(0.0094755555555555565*_t1*_t25*_t41*_t81*la + 2.1970000000000003e-6*_t109*_t114*_t7*_t74*_t83 - 7.1402499999999999e-6*_t113*_t114*_t74 + 0.10592592592592592*_t12*_t25*_t7*_t78*_t8 + 0.0021420750000000002*_t12*_t39*_t73*_t75*_t83 - 0.00065910000000000014*_t39*_t73*_t76 - 0.030795555555555555*_t54*_t81*la - _t80) + _t56*_t60 + _t71*_t91 + 0.3e1*_t88;
  const double d4F_dna2_dla2 = _t104*_t58 + _t36*_t95 + _t51*(-1.3182000000000004e-6*_t111*_t116 + 4.2841500000000003e-6*_t113*_t116 + 0.00028392000000000001*_t115*_t76 - 0.00092274000000000002*_t115*_t84 - 0.0022533333333333333*_t44 + 0.0073233333333333327*_t49) + _t89*_t95 + 0.2e1*_t92;
  const double d4F_dna_dla3 = _t35*_t97 + _t51*(7.9092000000000004e-7*_t109*_t117*_t7*_t83*la - 2.5704899999999999e-6*_t113*_t117*la + 0.00029659499999999997*_t12*_t75*_t83*_t93 - 9.1260000000000004e-5*_t94) + _t98;
  const double d4F_dla4 = _t51*(-4.7455200000000003e-7*_t111*_t118 + 1.5422939999999997e-6*_t113*_t118);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;

  const double _t1 = -nb;
  const double _t2 = _t1 + na;
  const double _t3 = na + nb;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = -_t5;
  const double _t7 = xc_powr(0.6e1, 1, 3);
  const double _t8 = (0.1e1 / (M_CBRTPI));
  const double _t9 = _t7*_t8;
  const double _t10 = (0.1e1 / 0.2e1)*_t9/xc_powr(_t3, 1, 3);
  const double _t11 = -p->dens_threshold + na <= 0;
  const double _t12 = -_t1 - p->dens_threshold <= 0;
  const double _t14 = xc_powr(na, -5, 3);
  const double _t19 = xc_powr(nb, -5, 3);
  const double _t20 = _t19*lb;
  const double _t22 = xc_powr(0.3e1, 2, 3);
  const double _t23 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t24 = _t22*_t23;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t5, 0.5e1 / 0.3e1, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, _t6, 0.5e1 / 0.3e1, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, _t10, _t5, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t11)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t10, _t5, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t12)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t10, _t6, _hc4);
  const double _t13 = _hc2[0] + my_piecewise3(_t11, 0, _hc3[0]) + my_piecewise3(_t12, 0, _hc4[0]);
  const double _t15 = _hc0[0] + 0.1e1;
  const double _t16 = _t15*la;
  const double _t17 = _t14*_t16;
  const double _t18 = _hc1[0] + 0.1e1;
  const double _t21 = _t18*_t20;
  const double _t25 = _t24*(_t17 + _t21);
  const double _t26 = 0.001*_t25 - 0.00069999999999999999;
  const double _t27 = 0.0032499999999999999*_t25 + 0.1e1;
  const double _t28 = (0.1e1 / _t27);
  const double _t29 = _t26*_t28 + 0.1e1;
  const double _t30 = _t13*_t29;
  const double zk = _t30;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t32 = (0.1e1 / 0.6e1)/xc_powr(_t3, 4, 3);
  const double _t34 = -_t4;
  const double _t35 = (0.1e1 / (_t3 * _t3));
  const double _t36 = _t2*_t35;
  const double _t37 = _t34 + _t36;
  const double _t38 = -_t37;
  const double _t39 = _t32*_t9;
  const double _t44 = xc_powr(na, -8, 3);
  const double _t45 = (0.5e1 / 0.3e1)*_t44;
  const double _t54 = _t36 + _t4;
  const double _t55 = -_t54;
  const double _t58 = xc_powr(nb, -8, 3);
  const double _t31 = _hc2[2]*_t9;
  const double _t33 = -_t31*_t32;
  const double _t40 = -_hc3[2]*_t39;
  const double _t41 = -_hc4[2]*_t39;
  const double _t42 = _hc2[1]*_t38 + _t33 + my_piecewise3(_t11, 0, _hc3[1]*_t38 + _t40) + my_piecewise3(_t12, 0, _hc4[1]*_t37 + _t41);
  const double _t43 = _t29*_t42;
  const double _t46 = _hc0[2]*_t14;
  const double _t47 = _t38*_t46;
  const double _t48 = _hc1[2]*_t20;
  const double _t49 = -_t16*_t45 + _t37*_t48 + _t47*la;
  const double _t50 = (0.1e1 / (_t27 * _t27));
  const double _t51 = 0.0032499999999999999*_t26*_t50;
  const double _t52 = 0.001*_t22*_t23*_t28*_t49 - _t24*_t49*_t51;
  const double _t53 = _t13*_t52;
  const double _t56 = _hc2[1]*_t55 + _t33 + my_piecewise3(_t11, 0, _hc3[1]*_t55 + _t40) + my_piecewise3(_t12, 0, _hc4[1]*_t54 + _t41);
  const double _t57 = _t29*_t56;
  const double _t59 = _t18*_t58;
  const double _t60 = (0.5e1 / 0.3e1)*_t59;
  const double _t61 = _t46*la;
  const double _t62 = _t48*_t54 + _t55*_t61 - _t60*lb;
  const double _t63 = _t24*_t51;
  const double _t64 = 0.001*_t22*_t23*_t28*_t62 - _t62*_t63;
  const double _t65 = _t13*_t64;
  const double _t66 = _t14*_t15;
  const double _t67 = 0.001*_t14*_t15*_t22*_t23*_t28 - _t63*_t66;
  const double _t68 = _t13*_t67;
  const double _t69 = _t18*_t19;
  const double _t70 = 0.001*_t18*_t19*_t22*_t23*_t28 - _t63*_t69;
  const double _t71 = _t13*_t70;
  const double dF_dna = _t3*_t43 + _t3*_t53 + _t30;
  const double dF_dnb = _t3*_t57 + _t3*_t65 + _t30;
  const double dF_dla = _t3*_t68;
  const double dF_dlb = _t3*_t71;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 1] += dF_dlb;
#endif
#if _KMAX >= 2
  const double _t74 = xc_powr(_t3, -7, 3);
  const double _t75 = (0.2e1 / 0.9e1)*_t74;
  const double _t77 = 0.2e1*_t35;
  const double _t78 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t79 = 0.2e1*_t78;
  const double _t80 = _t2*_t79;
  const double _t81 = -_t77 + _t80;
  const double _t86 = _t75*_t9;
  const double _t93 = -_t81;
  const double _t101 = M_CBRT3;
  const double _t102 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t103 = _t101*_t102;
  const double _t106 = xc_powr(na, -11, 3);
  const double _t113 = (_t38 * _t38);
  const double _t117 = (_t37 * _t37);
  const double _t153 = _t77 + _t80;
  const double _t154 = -_t153;
  const double _t158 = xc_powr(nb, -11, 3);
  const double _t163 = (_t54 * _t54);
  const double _t167 = (_t55 * _t55);
  const double _t193 = xc_powr(na, -10, 3);
  const double _t204 = xc_powr(nb, -10, 3);
  const double _t72 = _t42*_t52;
  const double _t73 = 0.2e1*_t72;
  const double _t76 = _t31*_t75;
  const double _t82 = -_hc2[5]*_t39;
  const double _t83 = _hc2[4]*_t38 + _t82;
  const double _t84 = -_hc2[4]*_t39;
  const double _t85 = _hc2[3]*_t38 + _t84;
  const double _t87 = _hc3[2]*_t86;
  const double _t88 = -_hc3[5]*_t39;
  const double _t89 = _hc3[4]*_t38 + _t88;
  const double _t90 = -_hc3[4]*_t39;
  const double _t91 = _hc3[3]*_t38 + _t90;
  const double _t92 = _hc4[2]*_t86;
  const double _t94 = -_hc4[5]*_t39;
  const double _t95 = _hc4[4]*_t37 + _t94;
  const double _t96 = -_hc4[4]*_t39;
  const double _t97 = _hc4[3]*_t37 + _t96;
  const double _t98 = _hc2[1]*_t81 + _t38*_t85 - _t39*_t83 + _t76 + my_piecewise3(_t11, 0, _hc3[1]*_t81 + _t38*_t91 - _t39*_t89 + _t87) + my_piecewise3(_t12, 0, _hc4[1]*_t93 + _t37*_t97 - _t39*_t95 + _t92);
  const double _t99 = _t29*_t98;
  const double _t100 = (_t49 * _t49);
  const double _t104 = 1.95e-5*_t50;
  const double _t105 = (0.1e1 / (_t27 * _t27 * _t27));
  const double _t107 = _t106*_t16;
  const double _t108 = _hc0[2]*_t44;
  const double _t109 = _t108*_t38;
  const double _t110 = (0.10e2 / 0.3e1)*_t109;
  const double _t111 = _t46*_t81;
  const double _t112 = _t111*la;
  const double _t114 = _hc0[5]*_t14;
  const double _t115 = _t113*_t114;
  const double _t116 = _t115*la;
  const double _t118 = _hc1[5]*_t20;
  const double _t119 = _t117*_t118;
  const double _t120 = (0.40e2 / 0.9e1)*_t107 - _t110*la + _t112 + _t116 + _t119 + _t48*_t93;
  const double _t121 = 6.3374999999999995e-5*_t100*_t101*_t102*_t105*_t26 - _t100*_t103*_t104 + 0.001*_t120*_t22*_t23*_t28 - _t120*_t63;
  const double _t122 = _t121*_t13;
  const double _t123 = _t42*_t64;
  const double _t124 = _t52*_t56;
  const double _t125 = _hc2[3]*_t55 + _t84;
  const double _t126 = _hc3[3]*_t55 + _t90;
  const double _t127 = _hc3[4]*_t55 + _t88;
  const double _t128 = -_t127*_t39 + _t87;
  const double _t129 = _hc4[4]*_t54 + _t94;
  const double _t130 = _t129*_t39;
  const double _t131 = _hc4[3]*_t54 + _t96;
  const double _t132 = _hc2[4]*_t55 + _t82;
  const double _t133 = -_t132*_t39 + _t76;
  const double _t134 = _hc2[1]*_t80 + _t125*_t38 + _t133 + my_piecewise3(_t11, 0, _hc3[1]*_t80 + _t126*_t38 + _t128) + my_piecewise3(_t12, 0, -_hc4[1]*_t80 + (0.2e1 / 0.9e1)*_hc4[2]*_t7*_t74*_t8 - _t130 + _t131*_t37);
  const double _t135 = _t134*_t29;
  const double _t136 = _t103*_t104;
  const double _t137 = _t136*_t49;
  const double _t138 = _hc1[2]*_t58;
  const double _t139 = (0.5e1 / 0.3e1)*_t138;
  const double _t140 = _t139*_t37;
  const double _t141 = _hc0[2]*_t55;
  const double _t142 = _t141*_t45;
  const double _t143 = _t118*_t37;
  const double _t144 = _t143*_t54;
  const double _t145 = _t114*_t38;
  const double _t146 = _t145*_t55;
  const double _t147 = _t146*la;
  const double _t148 = -_t140*lb - _t142*la + _t144 + _t147 - _t48*_t80 + _t61*_t80;
  const double _t149 = 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t49*_t62 - _t137*_t62 + 0.001*_t148*_t22*_t23*_t28 - _t148*_t63;
  const double _t150 = _t13*_t149;
  const double _t151 = _t3*_t56;
  const double _t152 = 0.2e1*_t64;
  const double _t155 = _hc2[1]*_t153 + _t125*_t55 + _t133 + my_piecewise3(_t11, 0, _hc3[1]*_t153 + _t126*_t55 + _t128) + my_piecewise3(_t12, 0, _hc4[1]*_t154 - _t130 + _t131*_t54 + _t92);
  const double _t156 = _t155*_t29;
  const double _t157 = (_t62 * _t62);
  const double _t159 = _t158*_t18;
  const double _t160 = (0.40e2 / 0.9e1)*_t159;
  const double _t161 = (0.10e2 / 0.3e1)*_t138;
  const double _t162 = _t161*_t54;
  const double _t164 = _t118*_t163;
  const double _t165 = _t153*_t46;
  const double _t166 = _t165*la;
  const double _t168 = _t114*_t167;
  const double _t169 = _t168*la;
  const double _t170 = _t154*_t48 + _t160*lb - _t162*lb + _t164 + _t166 + _t169;
  const double _t171 = 6.3374999999999995e-5*_t101*_t102*_t105*_t157*_t26 - _t136*_t157 + 0.001*_t170*_t22*_t23*_t28 - _t170*_t63;
  const double _t172 = _t13*_t171;
  const double _t173 = _t42*_t67;
  const double _t174 = _t15*_t44;
  const double _t175 = -0.5e1 / 0.3e1*_t174 + _t47;
  const double _t176 = 6.3374999999999995e-5*_t101*_t102*_t105*_t14*_t15*_t26*_t49 - _t137*_t66 + 0.001*_t175*_t22*_t23*_t28 - _t175*_t63;
  const double _t177 = _t13*_t176;
  const double _t178 = _t42*_t70;
  const double _t179 = _hc1[2]*_t19;
  const double _t180 = _t179*_t37;
  const double _t181 = 0.001*_hc1[2]*_t19*_t22*_t23*_t28*_t37 + 6.3374999999999995e-5*_t101*_t102*_t105*_t18*_t19*_t26*_t49 - _t137*_t69 - _t180*_t63;
  const double _t182 = _t13*_t181;
  const double _t183 = _t56*_t67;
  const double _t184 = _t46*_t55;
  const double _t185 = _t136*_t62;
  const double _t186 = 0.001*_hc0[2]*_t14*_t22*_t23*_t28*_t55 + 6.3374999999999995e-5*_t101*_t102*_t105*_t14*_t15*_t26*_t62 - _t184*_t63 - _t185*_t66;
  const double _t187 = _t13*_t186;
  const double _t188 = _t56*_t70;
  const double _t189 = _t179*_t54;
  const double _t190 = _t189 - _t60;
  const double _t191 = 6.3374999999999995e-5*_t101*_t102*_t105*_t18*_t19*_t26*_t62 - _t185*_t69 + 0.001*_t190*_t22*_t23*_t28 - _t190*_t63;
  const double _t192 = _t13*_t191;
  const double _t194 = (_t15 * _t15);
  const double _t195 = _t193*_t194;
  const double _t196 = 6.3374999999999995e-5*_t105*_t26;
  const double _t197 = _t103*_t196;
  const double _t198 = -_t136*_t195 + _t195*_t197;
  const double _t199 = _t13*_t198;
  const double _t200 = _t136*_t66;
  const double _t201 = _t66*_t69;
  const double _t202 = _t197*_t201 - _t200*_t69;
  const double _t203 = _t13*_t202;
  const double _t205 = (_t18 * _t18);
  const double _t206 = _t204*_t205;
  const double _t207 = -_t136*_t206 + _t197*_t206;
  const double _t208 = _t13*_t207;
  const double d2F_dna2 = _t122*_t3 + _t3*_t73 + _t3*_t99 + 0.2e1*_t43 + 0.2e1*_t53;
  const double d2F_dna_dnb = _t123*_t3 + _t124*_t3 + _t135*_t3 + _t150*_t3 + _t43 + _t53 + _t57 + _t65;
  const double d2F_dnb2 = _t151*_t152 + _t156*_t3 + _t172*_t3 + 0.2e1*_t57 + 0.2e1*_t65;
  const double d2F_dna_dla = _t173*_t3 + _t177*_t3 + _t68;
  const double d2F_dna_dlb = _t178*_t3 + _t182*_t3 + _t71;
  const double d2F_dnb_dla = _t183*_t3 + _t187*_t3 + _t68;
  const double d2F_dnb_dlb = _t188*_t3 + _t192*_t3 + _t71;
  const double d2F_dla2 = _t199*_t3;
  const double d2F_dla_dlb = _t203*_t3;
  const double d2F_dlb2 = _t208*_t3;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 1] += d2F_dna_dlb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 2] += d2F_dnb_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += d2F_dnb_dlb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 1] += d2F_dla_dlb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 2] += d2F_dlb2;
#endif
#if _KMAX >= 3
  const double _t213 = xc_powr(_t3, -10, 3);
  const double _t214 = (0.14e2 / 0.27e2)*_t213;
  const double _t216 = 0.6e1*_t78;
  const double _t217 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t218 = _t2*_t217;
  const double _t219 = 0.6e1*_t218;
  const double _t220 = -_t216 + _t219;
  const double _t221 = -_t220;
  const double _t223 = (0.4e1 / 0.9e1)*_t74;
  const double _t224 = 0.2e1*_t81;
  const double _t235 = _t214*_t9;
  const double _t238 = _t223*_t9;
  const double _t250 = 0.2e1*_t93;
  const double _t263 = (0.1e1 / (M_PI * M_PI));
  const double _t270 = xc_powr(na, -14, 3);
  const double _t271 = (0.440e3 / 0.27e2)*_t270;
  const double _t277 = (_t38 * _t38 * _t38);
  const double _t287 = (_t37 * _t37 * _t37);
  const double _t291 = 0.4e1*_t35;
  const double _t292 = 0.4e1*_t78;
  const double _t293 = _t2*_t292;
  const double _t294 = -_t291 + _t293;
  const double _t297 = -_t294;
  const double _t302 = _t219 - 0.2e1*_t78;
  const double _t303 = -_t302;
  const double _t334 = (0.20e2 / 0.3e1)*la;
  const double _t346 = _t117*_t54;
  const double _t348 = (0.10e2 / 0.3e1)*la;
  const double _t349 = _t348*_t44;
  const double _t352 = -_t2*_t35;
  const double _t353 = _t34 + _t352;
  const double _t383 = _t2*_t78;
  const double _t391 = (0.10e2 / 0.3e1)*_t54;
  const double _t392 = _t37*lb;
  const double _t394 = _t163*_t37;
  const double _t396 = _t352 + _t4;
  const double _t404 = _t216 + _t219;
  const double _t405 = -_t404;
  const double _t406 = 0.2e1*_t153;
  const double _t413 = 0.2e1*_t154;
  const double _t415 = xc_powr(nb, -14, 3);
  const double _t418 = (0.40e2 / 0.3e1)*lb;
  const double _t420 = (_t54 * _t54 * _t54);
  const double _t429 = (_t55 * _t55 * _t55);
  const double _t432 = _t291 + _t293;
  const double _t433 = -_t432;
  const double _t532 = xc_powi(na, -5);
  const double _t543 = xc_powi(nb, -5);
  const double _t209 = _t52*_t98;
  const double _t210 = 0.3e1*_t209;
  const double _t211 = _t3*_t42;
  const double _t212 = 0.3e1*_t211;
  const double _t215 = -_t214*_t31;
  const double _t222 = _t83*_t9;
  const double _t225 = _hc2[5]*_t86;
  const double _t226 = -_hc2[9]*_t39;
  const double _t227 = _hc2[8]*_t38 + _t226;
  const double _t228 = -_hc2[8]*_t39;
  const double _t229 = _hc2[7]*_t38 + _t228;
  const double _t230 = _hc2[4]*_t81 + _t225 - _t227*_t39 + _t229*_t38;
  const double _t231 = _hc2[4]*_t86;
  const double _t232 = -_hc2[7]*_t39;
  const double _t233 = _hc2[6]*_t38 + _t232;
  const double _t234 = _hc2[3]*_t81 - _t229*_t39 + _t231 + _t233*_t38;
  const double _t236 = _hc3[2]*_t235;
  const double _t237 = -_t236;
  const double _t239 = _hc3[5]*_t86;
  const double _t240 = -_hc3[9]*_t39;
  const double _t241 = _hc3[8]*_t38 + _t240;
  const double _t242 = -_hc3[8]*_t39;
  const double _t243 = _hc3[7]*_t38 + _t242;
  const double _t244 = _hc3[4]*_t81 + _t239 - _t241*_t39 + _t243*_t38;
  const double _t245 = _hc3[4]*_t86;
  const double _t246 = -_hc3[7]*_t39;
  const double _t247 = _hc3[6]*_t38 + _t246;
  const double _t248 = _hc3[3]*_t81 - _t243*_t39 + _t245 + _t247*_t38;
  const double _t249 = -_hc4[2]*_t235;
  const double _t251 = _hc4[5]*_t86;
  const double _t252 = -_hc4[9]*_t39;
  const double _t253 = _hc4[8]*_t37 + _t252;
  const double _t254 = -_hc4[8]*_t39;
  const double _t255 = _hc4[7]*_t37 + _t254;
  const double _t256 = _hc4[4]*_t93 + _t251 - _t253*_t39 + _t255*_t37;
  const double _t257 = _hc4[4]*_t86;
  const double _t258 = -_hc4[7]*_t39;
  const double _t259 = _hc4[6]*_t37 + _t258;
  const double _t260 = _hc4[3]*_t93 - _t255*_t39 + _t257 + _t259*_t37;
  const double _t261 = _hc2[1]*_t221 + _t215 + _t222*_t223 + _t224*_t85 - _t230*_t39 + _t234*_t38 + my_piecewise3(_t11, 0, _hc3[1]*_t221 + _t224*_t91 + _t237 + _t238*_t89 - _t244*_t39 + _t248*_t38) + my_piecewise3(_t12, 0, _hc4[1]*_t220 + _t238*_t95 + _t249 + _t250*_t97 - _t256*_t39 + _t260*_t37);
  const double _t262 = _t261*_t29;
  const double _t264 = (_t49 * _t49 * _t49);
  const double _t265 = (0.1e1 / (_t27 * _t27 * _t27 * _t27));
  const double _t266 = _t26*_t265;
  const double _t267 = 1.8537187499999998e-6*_t266;
  const double _t268 = (0.20e2 / 0.3e1)*_t109;
  const double _t269 = (0.80e2 / 0.9e1)*_t107 + 0.2e1*_t116 + 0.2e1*_t119 + _t224*_t61 + _t250*_t48 - _t268*la;
  const double _t272 = _hc0[2]*_t38;
  const double _t273 = _t106*_t272;
  const double _t274 = (0.40e2 / 0.3e1)*_t273;
  const double _t275 = _t221*_t46;
  const double _t276 = _t275*la;
  const double _t278 = _hc0[9]*_t14;
  const double _t279 = _t277*_t278;
  const double _t280 = _t279*la;
  const double _t281 = _t220*_t48;
  const double _t282 = _t108*_t81;
  const double _t283 = 0.5e1*_t282;
  const double _t284 = _hc0[5]*_t113;
  const double _t285 = _t284*_t44;
  const double _t286 = 0.5e1*_t285;
  const double _t288 = _hc1[9]*_t20;
  const double _t289 = _t287*_t288;
  const double _t290 = _t145*_t81;
  const double _t295 = _t145*_t294;
  const double _t296 = _t295*la;
  const double _t298 = _t143*_t297;
  const double _t299 = _t143*_t93 - _t16*_t271 + _t274*la + _t276 + _t280 + _t281 - _t283*la - _t286*la + _t289 + _t290*la + _t296 + _t298;
  const double _t300 = 6.3374999999999995e-5*_t101*_t102*_t105*_t120*_t26*_t49 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t269*_t49 + 5.7037500000000002e-7*_t105*_t263*_t264 - _t120*_t137 - _t137*_t269 + 0.001*_t22*_t23*_t28*_t299 - _t263*_t264*_t267 - _t299*_t63;
  const double _t301 = _t13*_t300;
  const double _t304 = _hc2[7]*_t55 + _t228;
  const double _t305 = _hc2[8]*_t55 + _t226;
  const double _t306 = _t225 - _t305*_t39;
  const double _t307 = _hc2[4]*_t80 + _t304*_t38 + _t306;
  const double _t308 = _hc2[6]*_t55 + _t232;
  const double _t309 = _t231 - _t304*_t39;
  const double _t310 = _hc2[3]*_t80 + _t308*_t38 + _t309;
  const double _t311 = _hc4[8]*_t54 + _t252;
  const double _t312 = _t311*_t39;
  const double _t313 = _hc4[7]*_t54 + _t254;
  const double _t314 = -_hc4[4]*_t80 + (0.2e1 / 0.9e1)*_hc4[5]*_t7*_t74*_t8 - _t312 + _t313*_t37;
  const double _t315 = _t313*_t39;
  const double _t316 = _hc4[6]*_t54 + _t258;
  const double _t317 = -_hc4[3]*_t80 + (0.2e1 / 0.9e1)*_hc4[4]*_t7*_t74*_t8 - _t315 + _t316*_t37;
  const double _t318 = _hc3[7]*_t55 + _t242;
  const double _t319 = _hc3[8]*_t55 + _t240;
  const double _t320 = _t239 - _t319*_t39;
  const double _t321 = _hc3[4]*_t80 + _t318*_t38 + _t320;
  const double _t322 = _hc3[6]*_t55 + _t246;
  const double _t323 = _t245 - _t318*_t39;
  const double _t324 = _hc3[3]*_t80 + _t322*_t38 + _t323;
  const double _t325 = _hc2[1]*_t303 + _t125*_t81 + _t132*_t86 + _t215 - _t307*_t39 + _t310*_t38 + _t80*_t85 + _t83*_t86 + my_piecewise3(_t11, 0, _hc3[1]*_t303 + _t126*_t81 + _t127*_t86 + _t237 - _t321*_t39 + _t324*_t38 + _t80*_t91 + _t86*_t89) + my_piecewise3(_t12, 0, _hc4[1]*_t302 + _t129*_t86 + _t131*_t93 + _t249 - _t314*_t39 + _t317*_t37 - _t80*_t97 + _t86*_t95);
  const double _t326 = _t29*_t3;
  const double _t327 = _t64*_t98;
  const double _t328 = _t263*_t267;
  const double _t329 = _t100*_t328;
  const double _t330 = _t161*_t37;
  const double _t331 = _t108*_t55;
  const double _t332 = (0.10e2 / 0.3e1)*_t331;
  const double _t333 = 0.2e1*_t144 + 0.2e1*_t147 - _t293*_t48 + _t293*_t61 - _t330*lb - _t332*la;
  const double _t335 = _t108*_t334;
  const double _t336 = _t335*_t78;
  const double _t337 = _t303*_t46;
  const double _t338 = _t106*_t141;
  const double _t339 = (0.40e2 / 0.9e1)*_t338;
  const double _t340 = _t139*_t93;
  const double _t341 = _hc1[5]*_t58;
  const double _t342 = _t117*_t341;
  const double _t343 = (0.5e1 / 0.3e1)*_t342;
  const double _t344 = _t145*la;
  const double _t345 = _t118*_t54;
  const double _t347 = _t288*_t346;
  const double _t350 = _hc0[5]*_t38;
  const double _t351 = _t350*_t55;
  const double _t354 = _t113*_t278;
  const double _t355 = _t353*_t354;
  const double _t356 = _t355*la;
  const double _t357 = _t114*la;
  const double _t358 = _t357*_t55;
  const double _t359 = -_t143*_t293 - _t2*_t336 + _t293*_t344 + _t302*_t48 + _t337*la + _t339*la - _t340*lb - _t343*lb + _t345*_t93 + _t347 - _t349*_t351 + _t356 + _t358*_t81;
  const double _t360 = 5.7037500000000002e-7*_t100*_t105*_t263*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t120*_t26*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t333*_t49 - _t120*_t185 - _t137*_t333 + 0.001*_t22*_t23*_t28*_t359 - _t329*_t62 - _t359*_t63;
  const double _t361 = _t13*_t3;
  const double _t362 = _t134*_t3;
  const double _t363 = 0.2e1*_t52;
  const double _t364 = 0.2e1*_t149;
  const double _t365 = 0.2e1*_t123 + 0.2e1*_t124 + 0.2e1*_t135 + 0.2e1*_t150;
  const double _t366 = _t56*_t64;
  const double _t367 = _hc2[3]*_t153 + _t308*_t55 + _t309;
  const double _t368 = _hc3[4]*_t153 + _t318*_t55 + _t320;
  const double _t369 = _t368*_t39;
  const double _t370 = _hc3[3]*_t153 + _t322*_t55 + _t323;
  const double _t371 = _hc4[3]*_t154 + _t257 - _t315 + _t316*_t54;
  const double _t372 = _hc4[4]*_t154 + _t251 - _t312 + _t313*_t54;
  const double _t373 = _t129*_t238 + _t249 - _t372*_t39;
  const double _t374 = _hc2[4]*_t153 + _t304*_t55 + _t306;
  const double _t375 = _t132*_t238 + _t215 - _t374*_t39;
  const double _t376 = -_hc2[1]*_t219 - _hc2[1]*_t79 + _t125*_t293 + _t367*_t38 + _t375 + my_piecewise3(_t11, 0, -_hc3[1]*_t219 - _hc3[1]*_t79 + 0.4e1*_t126*_t2*_t78 + (0.4e1 / 0.9e1)*_t127*_t7*_t74*_t8 - _t236 - _t369 + _t370*_t38) + my_piecewise3(_t12, 0, _hc4[1]*_t219 + _hc4[1]*_t79 - _t131*_t293 + _t37*_t371 + _t373);
  const double _t377 = _t155*_t52;
  const double _t378 = _t157*_t328;
  const double _t379 = 3.8999999999999999e-5*_t50;
  const double _t380 = _t103*_t62;
  const double _t381 = (0.20e2 / 0.3e1)*_t138;
  const double _t382 = _t381*lb;
  const double _t384 = _hc1[2]*_t158;
  const double _t385 = (0.40e2 / 0.9e1)*_t384;
  const double _t386 = _t37*_t385;
  const double _t387 = _hc0[2]*_t153;
  const double _t388 = _t387*_t45;
  const double _t389 = _hc0[5]*_t167;
  const double _t390 = _t389*_t45;
  const double _t393 = _t341*_t392;
  const double _t395 = _t288*_t394;
  const double _t397 = _t167*_t278;
  const double _t398 = _t396*_t397*la;
  const double _t399 = _t143*_t154 + _t145*_t153*la + _t219*_t48 - _t219*_t61 - _t293*_t345 + _t293*_t358 + _t382*_t383 + _t386*lb - _t388*la - _t390*la - _t391*_t393 + _t395 + _t398 + _t48*_t79 - _t61*_t79;
  const double _t400 = 0.00012674999999999999*_t101*_t102*_t105*_t148*_t26*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t170*_t26*_t49 + 5.7037500000000002e-7*_t105*_t157*_t263*_t49 - _t137*_t170 - _t148*_t379*_t380 + 0.001*_t22*_t23*_t28*_t399 - _t378*_t49 - _t399*_t63;
  const double _t401 = _t155*_t3;
  const double _t402 = 0.3e1*_t64;
  const double _t403 = 0.3e1*_t151;
  const double _t407 = 0.2e1*_t131;
  const double _t408 = _hc2[1]*_t405 + _t125*_t406 + _t367*_t55 + _t375 + my_piecewise3(_t11, 0, _hc3[1]*_t405 + _t126*_t406 + _t127*_t238 + _t237 - _t369 + _t370*_t55) + my_piecewise3(_t12, 0, _hc4[1]*_t404 + _t154*_t407 + _t371*_t54 + _t373);
  const double _t409 = _t29*_t408;
  const double _t410 = (_t62 * _t62 * _t62);
  const double _t411 = (0.80e2 / 0.9e1)*_t159;
  const double _t412 = _t381*_t54;
  const double _t414 = 0.2e1*_t164 + 0.2e1*_t169 + _t406*_t61 + _t411*lb - _t412*lb + _t413*_t48;
  const double _t416 = _t18*_t415;
  const double _t417 = (0.440e3 / 0.27e2)*_t416;
  const double _t419 = _t384*_t54;
  const double _t421 = _t288*_t420;
  const double _t422 = _t405*_t46;
  const double _t423 = _t422*la;
  const double _t424 = _t404*_t48;
  const double _t425 = _t163*_t341;
  const double _t426 = 0.5e1*_t425;
  const double _t427 = 0.5e1*_t138;
  const double _t428 = _t154*_t427;
  const double _t430 = _t278*_t429;
  const double _t431 = _t430*la;
  const double _t434 = _t345*_t433;
  const double _t435 = _t358*_t432;
  const double _t436 = _t153*_t358 + _t154*_t345 - _t417*lb + _t418*_t419 + _t421 + _t423 + _t424 - _t426*lb - _t428*lb + _t431 + _t434 + _t435;
  const double _t437 = 6.3374999999999995e-5*_t101*_t102*_t105*_t170*_t26*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t414*_t62 + 5.7037500000000002e-7*_t105*_t263*_t410 - _t170*_t185 - _t185*_t414 + 0.001*_t22*_t23*_t28*_t436 - _t328*_t410 - _t436*_t63;
  const double _t438 = _t13*_t437;
  const double _t439 = 0.2e1*_t211;
  const double _t440 = _t67*_t98;
  const double _t441 = _t106*_t15;
  const double _t442 = -_t110 + _t111 + _t115 + (0.40e2 / 0.9e1)*_t441;
  const double _t443 = -0.10e2 / 0.3e1*_t174 + 0.2e1*_t47;
  const double _t444 = _t120*_t136;
  const double _t445 = 5.7037500000000002e-7*_t100*_t105*_t14*_t15*_t263 + 6.3374999999999995e-5*_t101*_t102*_t105*_t120*_t14*_t15*_t26 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t443*_t49 - _t137*_t443 + 0.001*_t22*_t23*_t28*_t442 - _t329*_t66 - _t442*_t63 - _t444*_t66;
  const double _t446 = _t13*_t445;
  const double _t447 = _t70*_t98;
  const double _t448 = _hc1[5]*_t19;
  const double _t449 = _t117*_t448;
  const double _t450 = _t179*_t93 + _t449;
  const double _t451 = 0.001*_t24*_t28;
  const double _t452 = 5.7037500000000002e-7*_t105*_t263;
  const double _t453 = _t100*_t452;
  const double _t454 = _t103*_t379;
  const double _t455 = _t180*_t49;
  const double _t456 = 0.00012674999999999999*_t105*_t26;
  const double _t457 = _t103*_t456;
  const double _t458 = _t120*_t197;
  const double _t459 = -_t329*_t69 - _t444*_t69 + _t450*_t451 - _t450*_t63 + _t453*_t69 - _t454*_t455 + _t455*_t457 + _t458*_t69;
  const double _t460 = _t13*_t459;
  const double _t461 = -_t142 + _t146 + _t46*_t80;
  const double _t462 = _t197*_t49;
  const double _t463 = _t196*_t380;
  const double _t464 = _t452*_t49;
  const double _t465 = _t464*_t62;
  const double _t466 = _t328*_t49;
  const double _t467 = _t466*_t62;
  const double _t468 = _t136*_t148;
  const double _t469 = _t148*_t197;
  const double _t470 = -_t137*_t184 - _t175*_t185 + _t175*_t463 + _t184*_t462 + _t451*_t461 - _t461*_t63 + _t465*_t66 - _t467*_t66 - _t468*_t66 + _t469*_t66;
  const double _t471 = _hc1[5]*_t19*_t37*_t54 - _t140 - _t179*_t80;
  const double _t472 = -_t137*_t190 - _t180*_t185 + _t180*_t463 + _t190*_t462 + _t451*_t471 + _t465*_t69 - _t467*_t69 - _t468*_t69 + _t469*_t69 - _t471*_t63;
  const double _t473 = 0.2e1*_t151;
  const double _t474 = _t155*_t67;
  const double _t475 = _t165 + _t168;
  const double _t476 = _t157*_t452;
  const double _t477 = _t379*_t380;
  const double _t478 = _t380*_t456;
  const double _t479 = _t136*_t170;
  const double _t480 = _t170*_t197;
  const double _t481 = -_t184*_t477 + _t184*_t478 - _t378*_t66 + _t451*_t475 - _t475*_t63 + _t476*_t66 - _t479*_t66 + _t480*_t66;
  const double _t482 = _t13*_t481;
  const double _t483 = _t155*_t70;
  const double _t484 = _t163*_t448;
  const double _t485 = _t154*_t179;
  const double _t486 = _t160 - _t162 + _t484 + _t485;
  const double _t487 = 0.2e1*_t189 - 0.10e2 / 0.3e1*_t59;
  const double _t488 = 6.3374999999999995e-5*_t101*_t102*_t105*_t170*_t18*_t19*_t26 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t487*_t62 + 5.7037500000000002e-7*_t105*_t157*_t18*_t19*_t263 - _t185*_t487 + 0.001*_t22*_t23*_t28*_t486 - _t378*_t69 - _t479*_t69 - _t486*_t63;
  const double _t489 = _t13*_t488;
  const double _t490 = _t198*_t42;
  const double _t491 = _t454*_t66;
  const double _t492 = _t175*_t66;
  const double _t493 = -_t175*_t491 + _t195*_t464 - _t195*_t466 + _t457*_t492;
  const double _t494 = _t13*_t493;
  const double _t495 = _t202*_t42;
  const double _t496 = _t136*_t175;
  const double _t497 = _t197*_t66;
  const double _t498 = _t175*_t197;
  const double _t499 = _t464*_t66;
  const double _t500 = _t466*_t66;
  const double _t501 = -_t180*_t200 + _t180*_t497 - _t496*_t69 + _t498*_t69 + _t499*_t69 - _t500*_t69;
  const double _t502 = _t13*_t501;
  const double _t503 = _t207*_t42;
  const double _t504 = _t204*_t454;
  const double _t505 = _hc1[2]*_t37;
  const double _t506 = _t18*_t505;
  const double _t507 = _t204*_t506;
  const double _t508 = _t206*_t464 - _t206*_t466 + _t457*_t507 - _t504*_t506;
  const double _t509 = _t13*_t508;
  const double _t510 = _t198*_t56;
  const double _t511 = _t193*_t454;
  const double _t512 = _t141*_t15;
  const double _t513 = _t193*_t512;
  const double _t514 = _t452*_t62;
  const double _t515 = _t328*_t62;
  const double _t516 = _t195*_t514 - _t195*_t515 + _t457*_t513 - _t511*_t512;
  const double _t517 = _t13*_t516;
  const double _t518 = _t202*_t56;
  const double _t519 = _t136*_t69;
  const double _t520 = _t136*_t190;
  const double _t521 = _t197*_t69;
  const double _t522 = _t190*_t197;
  const double _t523 = _t514*_t66;
  const double _t524 = _t515*_t66;
  const double _t525 = -_t184*_t519 + _t184*_t521 - _t520*_t66 + _t522*_t66 + _t523*_t69 - _t524*_t69;
  const double _t526 = _t13*_t525;
  const double _t527 = _t207*_t56;
  const double _t528 = _t190*_t454;
  const double _t529 = _t190*_t69;
  const double _t530 = _t206*_t514 - _t206*_t515 + _t457*_t529 - _t528*_t69;
  const double _t531 = _t13*_t530;
  const double _t533 = (_t15 * _t15 * _t15);
  const double _t534 = _t532*_t533;
  const double _t535 = 5.7037500000000002e-7*_t105*_t263*_t532*_t533 - _t328*_t534;
  const double _t536 = _t13*_t535;
  const double _t537 = _t195*_t328;
  const double _t538 = 5.7037500000000002e-7*_t105*_t18*_t19*_t193*_t194*_t263 - _t537*_t69;
  const double _t539 = _t13*_t538;
  const double _t540 = _t206*_t328;
  const double _t541 = 5.7037500000000002e-7*_t105*_t14*_t15*_t204*_t205*_t263 - _t540*_t66;
  const double _t542 = _t13*_t541;
  const double _t544 = (_t18 * _t18 * _t18);
  const double _t545 = _t543*_t544;
  const double _t546 = 5.7037500000000002e-7*_t105*_t263*_t543*_t544 - _t328*_t545;
  const double _t547 = _t13*_t546;
  const double d3F_dna3 = _t121*_t212 + 0.3e1*_t122 + _t210*_t3 + _t262*_t3 + _t3*_t301 + 0.6e1*_t72 + 0.3e1*_t99;
  const double d3F_dna2_dnb = _t121*_t151 + _t122 + _t211*_t364 + _t3*_t327 + _t325*_t326 + _t360*_t361 + _t362*_t363 + _t365 + _t73 + _t99;
  const double d3F_dna_dnb2 = _t151*_t364 + _t152*_t362 + _t156 + _t171*_t211 + _t172 + _t3*_t377 + _t326*_t376 + _t361*_t400 + _t365 + 0.2e1*_t366;
  const double d3F_dnb3 = 0.3e1*_t156 + _t171*_t403 + 0.3e1*_t172 + _t3*_t409 + _t3*_t438 + 0.6e1*_t366 + _t401*_t402;
  const double d3F_dna2_dla = 0.2e1*_t173 + _t176*_t439 + 0.2e1*_t177 + _t3*_t440 + _t3*_t446;
  const double d3F_dna2_dlb = 0.2e1*_t178 + _t181*_t439 + 0.2e1*_t182 + _t3*_t447 + _t3*_t460;
  const double d3F_dna_dnb_dla = _t151*_t176 + _t173 + _t177 + _t183 + _t186*_t211 + _t187 + _t361*_t470 + _t362*_t67;
  const double d3F_dna_dnb_dlb = _t151*_t181 + _t178 + _t182 + _t188 + _t191*_t211 + _t192 + _t361*_t472 + _t362*_t70;
  const double d3F_dnb2_dla = 0.2e1*_t183 + _t186*_t473 + 0.2e1*_t187 + _t3*_t474 + _t3*_t482;
  const double d3F_dnb2_dlb = 0.2e1*_t188 + _t191*_t473 + 0.2e1*_t192 + _t3*_t483 + _t3*_t489;
  const double d3F_dna_dla2 = _t199 + _t3*_t490 + _t3*_t494;
  const double d3F_dna_dla_dlb = _t203 + _t3*_t495 + _t3*_t502;
  const double d3F_dna_dlb2 = _t208 + _t3*_t503 + _t3*_t509;
  const double d3F_dnb_dla2 = _t199 + _t3*_t510 + _t3*_t517;
  const double d3F_dnb_dla_dlb = _t203 + _t3*_t518 + _t3*_t526;
  const double d3F_dnb_dlb2 = _t208 + _t3*_t527 + _t3*_t531;
  const double d3F_dla3 = _t3*_t536;
  const double d3F_dla2_dlb = _t3*_t539;
  const double d3F_dla_dlb2 = _t3*_t542;
  const double d3F_dlb3 = _t3*_t547;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 1] += d3F_dna2_dlb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 2] += d3F_dna_dnb_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 3] += d3F_dna_dnb_dlb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 4] += d3F_dnb2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += d3F_dnb2_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 1] += d3F_dna_dla_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 2] += d3F_dna_dlb2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 3] += d3F_dnb_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 4] += d3F_dnb_dla_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += d3F_dnb_dlb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 1] += d3F_dla2_dlb;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 2] += d3F_dla_dlb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 3] += d3F_dlb3;
#endif
#if _KMAX >= 4
  const double _t551 = xc_powr(_t3, -13, 3);
  const double _t552 = (0.140e3 / 0.81e2)*_t551;
  const double _t554 = 0.24e2*_t217;
  const double _t555 = 0.24e2*_t2/xc_powi(_t3, 5);
  const double _t556 = -_t554 + _t555;
  const double _t557 = (0.14e2 / 0.9e1)*_t213;
  const double _t558 = 0.3e1*_t221;
  const double _t559 = (0.2e1 / 0.3e1)*_t74*_t9;
  const double _t560 = 0.3e1*_t81;
  const double _t575 = _t552*_t9;
  const double _t577 = _t557*_t9;
  const double _t593 = -_t556;
  const double _t594 = 0.3e1*_t93;
  const double _t608 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t609 = _t22*_t608;
  const double _t613 = 0.10e2*la;
  const double _t615 = (0.80e2 / 0.3e1)*la;
  const double _t618 = _t106*_t615;
  const double _t620 = _t334*_t44;
  const double _t622 = 0.12e2*_t78;
  const double _t623 = 0.12e2*_t217;
  const double _t624 = _t2*_t623;
  const double _t625 = -_t622 + _t624;
  const double _t629 = 0.6e1*_t35;
  const double _t630 = 0.6e1*na - 0.6e1*nb;
  const double _t632 = 0.4e1*na - 0.4e1*nb;
  const double _t633 = 0.2e1*na - 0.2e1*nb;
  const double _t634 = _t633*_t78 - _t77;
  const double _t635 = _t2*_t216;
  const double _t646 = _t555 - _t623;
  const double _t653 = 0.2e1*_t303;
  const double _t654 = (0.28e2 / 0.27e2)*_t213;
  const double _t662 = _t654*_t9;
  const double _t665 = -_t646;
  const double _t672 = 0.2e1*_t302;
  const double _t677 = 0.5e1*la;
  const double _t681 = (0.10e2 / 0.3e1)*lb;
  const double _t682 = 0.8e1*_t383;
  const double _t684 = (0.5e1 / 0.3e1)*lb;
  const double _t686 = 0.20e2*la;
  const double _t688 = _t624 - 0.4e1*_t78;
  const double _t689 = _t106*la;
  const double _t690 = _t44*_t677;
  const double _t693 = _t55*_t81;
  const double _t696 = _t54*_t93;
  const double _t698 = _t55*la;
  const double _t727 = _t153*_t348;
  const double _t729 = (0.40e2 / 0.9e1)*_t689;
  const double _t732 = _t633*_t78 + _t77;
  const double _t735 = 0.8e1*(_t2 * _t2)/xc_powi(_t3, 6);
  const double _t742 = 0.18e2*_t218;
  const double _t754 = 0.10e2*lb;
  const double _t756 = _t45*la;
  const double _t758 = (0.80e2 / 0.3e1)*lb;
  const double _t763 = _t54*lb;
  const double _t766 = _t554 + _t555;
  const double _t767 = 0.3e1*_t405;
  const double _t768 = 0.3e1*_t153;
  const double _t769 = -_t766;
  const double _t770 = 0.3e1*_t154;
  const double _t776 = _t622 + _t624;
  const double _t548 = _t121*_t42;
  const double _t549 = _t3*_t98;
  const double _t550 = _t261*_t3;
  const double _t553 = _t31*_t552;
  const double _t561 = _hc2[5]*_t235;
  const double _t562 = -_t561;
  const double _t563 = _hc2[9]*_t86;
  const double _t564 = -_hc2[14]*_t39;
  const double _t565 = -_hc2[13]*_t39;
  const double _t566 = _hc2[12]*_t38 + _t565;
  const double _t567 = _hc2[8]*_t86;
  const double _t568 = -_hc2[12]*_t39;
  const double _t569 = _hc2[11]*_t38 + _t568;
  const double _t570 = _hc2[7]*_t81 + _t38*_t569 - _t39*_t566 + _t567;
  const double _t571 = _hc2[4]*_t235;
  const double _t572 = -_t571;
  const double _t573 = _hc2[7]*_t86;
  const double _t574 = -_hc2[11]*_t39;
  const double _t576 = _hc3[2]*_t575;
  const double _t578 = _hc3[5]*_t235;
  const double _t579 = -_t578;
  const double _t580 = _hc3[9]*_t86;
  const double _t581 = -_hc3[14]*_t39;
  const double _t582 = -_hc3[13]*_t39;
  const double _t583 = _hc3[12]*_t38 + _t582;
  const double _t584 = _hc3[8]*_t86;
  const double _t585 = -_hc3[12]*_t39;
  const double _t586 = _hc3[11]*_t38 + _t585;
  const double _t587 = _hc3[7]*_t81 + _t38*_t586 - _t39*_t583 + _t584;
  const double _t588 = _hc3[4]*_t235;
  const double _t589 = -_t588;
  const double _t590 = _hc3[7]*_t86;
  const double _t591 = -_hc3[11]*_t39;
  const double _t592 = _hc4[2]*_t575;
  const double _t595 = -_hc4[5]*_t235;
  const double _t596 = _hc4[9]*_t86;
  const double _t597 = -_hc4[14]*_t39;
  const double _t598 = -_hc4[13]*_t39;
  const double _t599 = _hc4[12]*_t37 + _t598;
  const double _t600 = _hc4[8]*_t86;
  const double _t601 = -_hc4[12]*_t39;
  const double _t602 = _hc4[11]*_t37 + _t601;
  const double _t603 = _hc4[7]*_t93 + _t37*_t602 - _t39*_t599 + _t600;
  const double _t604 = -_hc4[4]*_t235;
  const double _t605 = _hc4[7]*_t86;
  const double _t606 = -_hc4[11]*_t39;
  const double _t607 = (_t49 * _t49 * _t49 * _t49);
  const double _t610 = 7.4148750000000004e-9*_t265;
  const double _t611 = xc_powi(_t27, -5);
  const double _t612 = (_t120 * _t120);
  const double _t614 = (0.40e2 / 0.3e1)*_t107 - _t109*_t613 + 0.3e1*_t112 + 0.3e1*_t116 + 0.3e1*_t119 + _t48*_t594;
  const double _t616 = _t143*_t250 - 0.880e3 / 0.27e2*_t16*_t270 + _t224*_t344 + _t273*_t615 + 0.2e1*_t276 + 0.2e1*_t280 + 0.2e1*_t281 - _t282*_t613 - _t285*_t613 + 0.2e1*_t289 + 0.2e1*_t296 + 0.2e1*_t298;
  const double _t617 = _hc0[14]*_t14*la;
  const double _t619 = _hc0[2]*_t618;
  const double _t621 = _hc1[14]*_t20;
  const double _t626 = _t350*_t620;
  const double _t627 = _t357*_t81;
  const double _t628 = _t118*_t93;
  const double _t631 = _t354*la;
  const double _t636 = _t117*_t288;
  const double _t637 = -_hc0[9]*_t277*_t620 + _t118*(_t93 * _t93) + 0.2e1*_t143*_t220 + _t143*_t625 + (0.6160e4 / 0.81e2)*_t16/xc_powr(na, 17, 3) - _t221*_t335 + 0.2e1*_t221*_t344 - 0.1760e4 / 0.27e2*_t270*_t272*la + _t284*_t618 - _t294*_t626 + _t294*_t627 + _t297*_t628 + _t297*_t636 - _t344*_t625 + _t357*(_t81 * _t81) + (_t37 * _t37 * _t37 * _t37)*_t621 + (_t38 * _t38 * _t38 * _t38)*_t617 + _t48*_t593 + _t556*_t61 + _t619*_t81 - _t626*_t81 + _t631*_t634 + _t631*(-_t291 + _t632*_t78) + _t631*(-_t629 + _t630*_t78) + _t636*_t93 + _t636*(_t629 - _t635);
  const double _t638 = _t134*_t52;
  const double _t639 = _t121*_t56;
  const double _t640 = _t149*_t42;
  const double _t641 = 0.3e1*_t362;
  const double _t642 = 0.3e1*_t149;
  const double _t643 = _t29*_t325;
  const double _t644 = _t3*_t325;
  const double _t645 = _t13*_t360;
  const double _t647 = _hc2[11]*_t55 + _t568;
  const double _t648 = _hc2[12]*_t55 + _t565;
  const double _t649 = -_t39*_t648 + _t567;
  const double _t650 = _hc2[7]*_t80 + _t38*_t647 + _t649;
  const double _t651 = _hc2[10]*_t55 + _t574;
  const double _t652 = -_t39*_t647 + _t573;
  const double _t655 = -_t39*(_hc2[13]*_t55 + _t564) + _t563;
  const double _t656 = _hc3[11]*_t55 + _t585;
  const double _t657 = _hc3[12]*_t55 + _t582;
  const double _t658 = -_t39*_t657 + _t584;
  const double _t659 = _hc3[7]*_t80 + _t38*_t656 + _t658;
  const double _t660 = _hc3[10]*_t55 + _t591;
  const double _t661 = -_t39*_t656 + _t590;
  const double _t663 = -_t39*(_hc3[13]*_t55 + _t581) + _t580;
  const double _t664 = _t238*_t321 + _t576;
  const double _t666 = _hc4[12]*_t54 + _t598;
  const double _t667 = _t39*_t666;
  const double _t668 = _hc4[11]*_t54 + _t601;
  const double _t669 = -_hc4[7]*_t80 + (0.2e1 / 0.9e1)*_hc4[8]*_t7*_t74*_t8 + _t37*_t668 - _t667;
  const double _t670 = _t39*_t668;
  const double _t671 = _hc4[10]*_t54 + _t606;
  const double _t673 = _t39*(_hc4[13]*_t54 + _t597);
  const double _t674 = _t238*_t314 + _t592;
  const double _t675 = _t238*_t307 + _t553;
  const double _t676 = _t609*_t610;
  const double _t678 = 0.3e1*_t144 + 0.3e1*_t147 - _t331*_t677 - _t392*_t427 - _t48*_t635 + _t61*_t635;
  const double _t679 = _t108*_t383;
  const double _t680 = _t161*lb;
  const double _t683 = -_t143*_t682 + _t224*_t358 + _t250*_t345 + (0.80e2 / 0.9e1)*_t338*la - _t342*_t681 + _t344*_t682 + 0.2e1*_t347 - _t351*_t620 + 0.2e1*_t356 + _t48*_t672 + _t61*_t653 - 0.40e2 / 0.3e1*_t679*la - _t680*_t93;
  const double _t685 = _hc1[9]*_t58;
  const double _t687 = _t350*_t44;
  const double _t691 = _t341*_t37;
  const double _t692 = _t684*_t691;
  const double _t694 = _t288*_t37;
  const double _t695 = _t54*_t694;
  const double _t697 = _t278*_t38;
  const double _t699 = _t697*_t698;
  const double _t700 = -_hc0[5]*_t690*_t693 - _hc0[9]*_t113*_t353*_t690 - _t108*_t303*_t677 - _t118*_t297*_t80 - _t139*_t220*lb - _t141*_t271*la + _t143*_t302 + _t143*_t688 + _t220*_t345 + _t221*_t358 + _t277*_t353*_t617 + _t287*_t54*_t621 - _t287*_t684*_t685 + _t294*_t357*_t80 + _t294*_t699 - _t297*_t692 + _t297*_t695 + _t303*_t344 - _t344*_t688 + (0.40e2 / 0.3e1)*_t351*_t689 + _t383*_t619 - _t383*_t686*_t687 + _t48*_t665 + _t61*_t646 + _t627*_t80 - _t628*_t80 + _t631*_t635 - _t635*_t636 - _t692*_t93 + _t693*_t697*la + _t694*_t696;
  const double _t701 = _t134*_t64;
  const double _t702 = _t171*_t42;
  const double _t703 = _t149*_t56;
  const double _t704 = _t29*_t376;
  const double _t705 = _t3*_t376;
  const double _t706 = _t13*_t400;
  const double _t707 = _hc2[1]*_t555;
  const double _t708 = _hc2[7]*_t153 + _t55*_t647 + _t649;
  const double _t709 = _t39*_t708;
  const double _t710 = _hc2[6]*_t153 + _t55*_t651 + _t652;
  const double _t711 = _t39*(_hc2[8]*_t153 + _t55*_t648 + _t655);
  const double _t712 = _hc3[1]*_t555;
  const double _t713 = _hc3[7]*_t153 + _t55*_t656 + _t658;
  const double _t714 = _t39*_t713;
  const double _t715 = _hc3[6]*_t153 + _t55*_t660 + _t661;
  const double _t716 = _t39*(_hc3[8]*_t153 + _t55*_t657 + _t663);
  const double _t717 = _hc4[6]*_t154 + _t54*_t671 + _t605 - _t670;
  const double _t718 = _hc4[7]*_t154 + _t54*_t668 + _t600 - _t667;
  const double _t719 = _t238*_t313 - _t39*_t718 + _t604;
  const double _t720 = _hc4[1]*_t555;
  const double _t721 = _t238*_t311 - _t39*(_hc4[8]*_t154 + _t54*_t666 + _t596 - _t673) + _t595;
  const double _t722 = _t333*_t49;
  const double _t723 = _t263*_t266;
  const double _t724 = 3.7074374999999995e-6*_t62;
  const double _t725 = _t723*_t724;
  const double _t726 = _t138*_t78;
  const double _t728 = -_t108*_t727 + _t143*_t413 + _t2*_t418*_t726 + _t292*_t48 - _t292*_t61 + _t344*_t406 - _t345*_t682 - _t349*_t389 + _t358*_t682 + (0.80e2 / 0.9e1)*_t384*_t392 - 0.20e2 / 0.3e1*_t393*_t54 + 0.2e1*_t395 + 0.2e1*_t398 + _t48*_t624 - _t61*_t624;
  const double _t730 = _hc1[5]*_t158;
  const double _t731 = _t730*lb;
  const double _t733 = _t397*la;
  const double _t734 = _t163*_t288;
  const double _t736 = -_t48*_t555 + _t555*_t61;
  const double _t737 = -0.40e2 / 0.3e1*_hc0[5]*_t383*_t44*_t698 - _hc0[9]*_t167*_t349*_t396 + _t108*_t218*_t686 + _t113*_t167*_t617 + _t117*_t163*_t621 + (0.40e2 / 0.9e1)*_t117*_t731 + _t118*_t735 + _t143*_t292 + _t143*_t624 + _t153*_t627 + _t154*_t628 + _t154*_t636 - _t292*_t344 - _t302*_t680 + _t336 - _t341*_t681*_t696 - _t344*_t624 + _t345*_t672 - _t346*_t681*_t685 + _t357*_t735 + _t358*_t653 + _t383*_t418*_t691 + _t385*_t93*lb + _t387*_t729 + _t389*_t729 + _t631*_t732 + _t634*_t733 - _t682*_t695 + _t682*_t699 - _t687*_t727 + _t734*_t93 + _t736;
  const double _t738 = _t155*_t64;
  const double _t739 = _t171*_t56;
  const double _t740 = _t3*_t408;
  const double _t741 = _hc2[3]*_t405 + _t238*_t304 + _t308*_t406 + _t55*_t710 + _t572 - _t709;
  const double _t743 = _hc3[3]*_t405 + _t238*_t318 + _t322*_t406 + _t55*_t715 + _t589 - _t714;
  const double _t744 = -_t127*_t577 + _t368*_t559 - _t39*(_hc3[4]*_t405 + _t238*_t319 + _t318*_t406 + _t55*_t713 + _t579 - _t716) + _t576;
  const double _t745 = _t129*_t577;
  const double _t746 = _t39*(_hc4[4]*_t404 + _t313*_t413 + _t54*_t718 + _t721);
  const double _t747 = _hc4[3]*_t404 + _t316*_t413 + _t54*_t717 + _t719;
  const double _t748 = -_t132*_t577 + _t374*_t559 - _t39*(_hc2[4]*_t405 + _t238*_t305 + _t304*_t406 + _t55*_t708 + _t562 - _t711) + _t553;
  const double _t749 = _t148*_t263;
  const double _t750 = 5.5611562499999989e-6*_t266;
  const double _t751 = _t157*_t750;
  const double _t752 = 5.8499999999999999e-5*_t50;
  const double _t753 = _t103*_t148;
  const double _t755 = _hc1[2]*_t415;
  const double _t757 = _t685*lb;
  const double _t759 = _t384*_t758;
  const double _t760 = _hc0[5]*_t55*_t756;
  const double _t761 = _t118*_t154;
  const double _t762 = _t153*_t357;
  const double _t764 = _t341*_t763;
  const double _t765 = -_hc0[2]*_t405*_t756 - _hc0[9]*_t429*_t756 - 0.30e2*_t138*_t218*lb + _t143*_t404 + _t153*_t699 - _t153*_t760 - 0.5e1*_t154*_t393 + _t154*_t695 + _t216*_t345 - _t216*_t358 + _t344*_t405 + _t345*_t742 - _t358*_t742 + _t37*_t418*_t54*_t730 + _t37*_t420*_t621 - _t383*_t759 + 0.20e2*_t383*_t764 - 0.440e3 / 0.27e2*_t392*_t755 - 0.5e1*_t394*_t757 + _t396*_t429*_t617 + _t432*_t699 - _t432*_t760 + _t433*_t695 - _t48*_t623 + _t61*_t623 + _t635*_t733 - _t635*_t734 - _t635*_t761 + _t635*_t762 - _t726*_t754 + _t736;
  const double _t771 = (_t62 * _t62 * _t62 * _t62);
  const double _t772 = (_t170 * _t170);
  const double _t773 = _t138*_t754;
  const double _t774 = _t159*_t418 + 0.3e1*_t164 + 0.3e1*_t166 + 0.3e1*_t169 + _t48*_t770 - _t54*_t773;
  const double _t775 = -_t154*_t773 + _t345*_t413 + _t358*_t406 - 0.880e3 / 0.27e2*_t416*lb + _t419*_t758 + 0.2e1*_t421 + 0.2e1*_t423 + 0.2e1*_t424 - _t425*_t754 + 0.2e1*_t431 + 0.2e1*_t434 + 0.2e1*_t435;
  const double _t777 = (0.20e2 / 0.3e1)*_t764;
  const double _t778 = _t118*(_t154 * _t154) + (_t153 * _t153)*_t357 + _t154*_t734 + _t154*_t759 - _t154*_t777 + (0.80e2 / 0.3e1)*_t163*_t731 + (0.6160e4 / 0.81e2)*_t18*lb/xc_powr(nb, 17, 3) + 0.2e1*_t345*_t404 + _t345*_t776 + 0.2e1*_t358*_t405 - _t358*_t776 - _t382*_t404 - 0.20e2 / 0.3e1*_t420*_t757 + _t432*_t762 + _t433*_t734 + _t433*_t761 - _t433*_t777 + _t48*_t769 + (_t54 * _t54 * _t54 * _t54)*_t621 + (_t55 * _t55 * _t55 * _t55)*_t617 + _t61*_t766 + _t732*_t733 + _t733*(_t291 + _t632*_t78) + _t733*(_t629 + _t630*_t78) + _t734*(-_t629 - _t635) - 0.1760e4 / 0.27e2*_t755*_t763;
  const double _t779 = 0.6e1*_t42;
  const double _t780 = 0.3e1*_t549;
  const double _t781 = _t264*_t676;
  const double _t782 = -0.5e1*_t174 + 0.3e1*_t47;
  const double _t783 = 0.2e1*_t115 + _t224*_t46 - _t268 + (0.80e2 / 0.9e1)*_t441;
  const double _t784 = -_t15*_t271 + _t274 + _t275 + _t279 - _t283 - _t286 + _t290 + _t295;
  const double _t785 = _t136*_t299;
  const double _t786 = _t105*_t263;
  const double _t787 = 1.7111250000000001e-6*_t786;
  const double _t788 = _t100*_t180;
  const double _t789 = 2.4098343749999995e-8*_t26*_t609*_t611;
  const double _t790 = _t263*_t750;
  const double _t791 = _t179*_t250 + 0.2e1*_t449;
  const double _t792 = _hc1[9]*_t19;
  const double _t793 = _t37*_t448;
  const double _t794 = _t179*_t220 + _t287*_t792 + _t297*_t793 + _t793*_t93;
  const double _t795 = _t136*_t180;
  const double _t796 = _t180*_t197;
  const double _t797 = _t464*_t69;
  const double _t798 = _t466*_t69;
  const double _t799 = 0.2e1*_t42;
  const double _t800 = _t100*_t676;
  const double _t801 = _t62*_t800;
  const double _t802 = 0.2e1*_t146 + _t293*_t46 - _t332;
  const double _t803 = _t100*_t789;
  const double _t804 = _t62*_t803;
  const double _t805 = _t120*_t514;
  const double _t806 = _t120*_t515;
  const double _t807 = _t114*_t55;
  const double _t808 = _t145*_t293 + _t337 + _t339 - 0.10e2 / 0.3e1*_t351*_t44 + _t355 - 0.20e2 / 0.3e1*_t679 + _t807*_t81;
  const double _t809 = _t328*_t722;
  const double _t810 = _t136*_t359;
  const double _t811 = _t197*_t359;
  const double _t812 = 0.2e1*_t362;
  const double _t813 = 0.2e1*_t134;
  const double _t814 = 0.2e1*_t13;
  const double _t815 = 0.2e1*_t56;
  const double _t816 = _t176*_t815 + _t186*_t799 + _t470*_t814 + _t67*_t813;
  const double _t817 = 1.14075e-6*_t62;
  const double _t818 = _t786*_t817;
  const double _t819 = 0.2e1*_hc1[5]*_t19*_t37*_t54 - _t179*_t293 - _t330;
  const double _t820 = _t448*_t54;
  const double _t821 = _t179*_t302 - _t293*_t793 - _t340 - _t343 + _t346*_t792 + _t820*_t93;
  const double _t822 = _t181*_t815 + _t191*_t799 + _t472*_t814 + _t70*_t813;
  const double _t823 = _t49*_t66;
  const double _t824 = _t157*_t676;
  const double _t825 = _t184*_t49;
  const double _t826 = _t157*_t789;
  const double _t827 = _t184*_t454;
  const double _t828 = _hc0[5]*_t14*_t153*_t38 + 0.4e1*_hc0[5]*_t14*_t2*_t55*_t78 + _hc0[9]*_t14*_t167*_t396 - _t219*_t46 - _t388 - _t390 - _t46*_t79;
  const double _t829 = _t456*_t753;
  const double _t830 = _t66*_t749;
  const double _t831 = _t105*_t817;
  const double _t832 = _t266*_t724;
  const double _t833 = _t136*_t399;
  const double _t834 = _t197*_t399;
  const double _t835 = _t49*_t69;
  const double _t836 = _t154*_t793 + _t179*_t219 + _t179*_t79 - _t293*_t820 + _t381*_t383 + _t386 - _t391*_t691 + _t394*_t792;
  const double _t837 = _t69*_t749;
  const double _t838 = 0.6e1*_t56;
  const double _t839 = 0.3e1*_t401;
  const double _t840 = _t410*_t676;
  const double _t841 = _t184*_t263;
  const double _t842 = 0.2e1*_t168 + _t406*_t46;
  const double _t843 = _t153*_t807 + _t422 + _t430 + _t432*_t807;
  const double _t844 = _t184*_t414;
  const double _t845 = _t136*_t436;
  const double _t846 = 0.3e1*_t189 - 0.5e1*_t59;
  const double _t847 = _t411 - _t412 + 0.2e1*_t484 + 0.2e1*_t485;
  const double _t848 = _t154*_t820 + _t179*_t404 - _t417 + (0.40e2 / 0.3e1)*_t419 + _t420*_t792 - _t426 - _t428 + _t433*_t820;
  const double _t849 = _t515*_t69;
  const double _t850 = 1.14075e-6*_t786;
  const double _t851 = _t443*_t823;
  const double _t852 = _t457*_t66;
  const double _t853 = 3.7074374999999995e-6*_t723;
  const double _t854 = _t120*_t452;
  const double _t855 = _t120*_t328;
  const double _t856 = _t180*_t823;
  const double _t857 = ((_hc1[2]) * (_hc1[2]))*_t117;
  const double _t858 = _t454*_t69;
  const double _t859 = 2.2815000000000001e-6*_t786;
  const double _t860 = _t49*_t507;
  const double _t861 = _t457*_t69;
  const double _t862 = 7.414874999999999e-6*_t723;
  const double _t863 = _t184*_t457;
  const double _t864 = _t49*_t850;
  const double _t865 = _t49*_t853;
  const double _t866 = _t49*_t676;
  const double _t867 = _t62*_t866;
  const double _t868 = _t49*_t789;
  const double _t869 = _t62*_t868;
  const double _t870 = _t148*_t452;
  const double _t871 = _t148*_t328;
  const double _t872 = _t62*_t676;
  const double _t873 = _t69*_t823;
  const double _t874 = _t62*_t789;
  const double _t875 = ((_hc0[2]) * (_hc0[2]))*_t167;
  const double _t876 = _t513*_t62;
  const double _t877 = _t170*_t452;
  const double _t878 = _t170*_t328;
  const double _t879 = _t184*_t69;
  const double _t880 = _t487*_t69;
  const double _t881 = _t175*_t195;
  const double _t882 = _t195*_t69;
  const double _t883 = _t66*_t853;
  const double _t884 = _t206*_t676;
  const double _t885 = _t190*_t206;
  const double _t886 = (_t15 * _t15 * _t15 * _t15)/xc_powr(na, 20, 3);
  const double _t887 = _t534*_t69;
  const double _t888 = _t545*_t66;
  const double _t889 = (_t18 * _t18 * _t18 * _t18)/xc_powr(nb, 20, 3);
  const double d4F_dna4 = 0.6e1*_t121*_t549 + 0.12e2*_t209 + 0.4e1*_t211*_t300 + 0.4e1*_t262 + 0.4e1*_t301 + _t326*(_hc2[1]*_t556 - _t222*_t557 + _t230*_t559 + _t234*_t560 + _t38*(_hc2[3]*_t221 + _t224*_t233 + _t229*_t238 + _t38*(_hc2[6]*_t81 + _t38*(_hc2[10]*_t38 + _t574) - _t39*_t569 + _t573) - _t39*_t570 + _t572) - _t39*(_hc2[4]*_t221 + _t224*_t229 + _t227*_t238 + _t38*_t570 - _t39*(_hc2[8]*_t81 + _t38*_t566 - _t39*(_hc2[13]*_t38 + _t564) + _t563) + _t562) + _t553 + _t558*_t85 + my_piecewise3(_t11, 0, _hc3[1]*_t556 + _t244*_t559 + _t248*_t560 + _t38*(_hc3[3]*_t221 + _t224*_t247 + _t238*_t243 + _t38*(_hc3[6]*_t81 + _t38*(_hc3[10]*_t38 + _t591) - _t39*_t586 + _t590) - _t39*_t587 + _t589) - _t39*(_hc3[4]*_t221 + _t224*_t243 + _t238*_t241 + _t38*_t587 - _t39*(_hc3[8]*_t81 + _t38*_t583 - _t39*(_hc3[13]*_t38 + _t581) + _t580) + _t579) + _t558*_t91 + _t576 - _t577*_t89) + my_piecewise3(_t12, 0, _hc4[1]*_t593 + 0.3e1*_t220*_t97 + _t256*_t559 + _t260*_t594 + _t37*(_hc4[3]*_t220 + _t238*_t255 + _t250*_t259 + _t37*(_hc4[6]*_t93 + _t37*(_hc4[10]*_t37 + _t606) - _t39*_t602 + _t605) - _t39*_t603 + _t604) - _t39*(_hc4[4]*_t220 + _t238*_t253 + _t250*_t255 + _t37*_t603 - _t39*(_hc4[8]*_t93 + _t37*_t599 - _t39*(_hc4[13]*_t37 + _t597) + _t596) + _t595) - _t577*_t95 + _t592)) + _t361*(5.7037500000000002e-7*_t100*_t105*_t120*_t263 + 5.7037500000000002e-7*_t100*_t105*_t263*_t269 + 5.7037500000000002e-7*_t100*_t105*_t263*_t614 + 6.3374999999999995e-5*_t101*_t102*_t105*_t120*_t26*_t269 + 0.00012674999999999999*_t101*_t102*_t105*_t26*_t299*_t49 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t49*_t616 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t612 - _t120*_t329 - _t136*_t612 - _t137*_t616 + 0.001*_t22*_t23*_t28*_t637 + 2.4098343749999995e-8*_t22*_t26*_t607*_t608*_t611 - _t269*_t329 - _t269*_t444 - _t299*_t454*_t49 - _t329*_t614 - _t607*_t609*_t610 - _t63*_t637) + 0.4e1*_t52*_t550 + 0.12e2*_t548;
  const double d4F_dna3_dnb = _t121*_t641 + _t151*_t300 + _t210 + _t212*_t360 + _t262 + _t301 + _t326*(_hc2[1]*_t646 + _t125*_t221 - _t132*_t235 - _t222*_t654 + _t224*_t310 + _t230*_t86 + _t234*_t80 + _t38*(_hc2[3]*_t303 + _t229*_t86 + _t233*_t80 + _t304*_t86 + _t308*_t81 + _t38*(_hc2[6]*_t80 + _t38*_t651 + _t652) - _t39*_t650 + _t572) - _t39*(_hc2[4]*_t303 + _t227*_t86 + _t229*_t80 + _t304*_t81 + _t305*_t86 + _t38*_t650 - _t39*(_hc2[8]*_t80 + _t38*_t648 + _t655) + _t562) + _t653*_t85 + _t675 + my_piecewise3(_t11, 0, _hc3[1]*_t646 + _t126*_t221 - _t127*_t235 + _t224*_t324 + _t244*_t86 + _t248*_t80 + _t38*(_hc3[3]*_t303 + _t243*_t86 + _t247*_t80 + _t318*_t86 + _t322*_t81 + _t38*(_hc3[6]*_t80 + _t38*_t660 + _t661) - _t39*_t659 + _t589) - _t39*(_hc3[4]*_t303 + _t241*_t86 + _t243*_t80 + _t318*_t81 + _t319*_t86 + _t38*_t659 - _t39*(_hc3[8]*_t80 + _t38*_t657 + _t663) + _t579) + _t653*_t91 - _t662*_t89 + _t664) + my_piecewise3(_t12, 0, _hc4[1]*_t665 - _t129*_t235 + _t131*_t220 + _t250*_t317 + _t256*_t86 - _t260*_t80 + _t37*(_hc4[3]*_t302 + _t255*_t86 - _t259*_t80 + _t313*_t86 + _t316*_t93 + _t37*(-_hc4[6]*_t80 + (0.2e1 / 0.9e1)*_hc4[7]*_t7*_t74*_t8 + _t37*_t671 - _t670) - _t39*_t669 + _t604) - _t39*(_hc4[4]*_t302 + _t253*_t86 - _t255*_t80 + _t311*_t86 + _t313*_t93 + _t37*_t669 - _t39*(-_hc4[8]*_t80 + (0.2e1 / 0.9e1)*_hc4[9]*_t7*_t74*_t8 + _t37*_t666 - _t673) + _t595) - _t662*_t95 + _t672*_t97 + _t674)) + 0.3e1*_t327 + _t361*(5.7037500000000002e-7*_t100*_t105*_t263*_t678 + 6.3374999999999995e-5*_t101*_t102*_t105*_t120*_t148*_t26 + 6.3374999999999995e-5*_t101*_t102*_t105*_t148*_t26*_t269 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t299*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t359*_t49 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t49*_t683 + 5.7037500000000002e-7*_t105*_t120*_t263*_t49*_t62 + 5.7037500000000002e-7*_t105*_t263*_t269*_t49*_t62 - _t120*_t467 - _t137*_t359 - _t137*_t683 - _t148*_t444 - _t185*_t299 + 0.001*_t22*_t23*_t28*_t700 + 2.4098343749999995e-8*_t22*_t26*_t264*_t608*_t611*_t62 - _t264*_t62*_t676 - _t269*_t467 - _t269*_t468 - _t329*_t678 - _t63*_t700) + 0.3e1*_t52*_t644 + 0.3e1*_t548 + _t549*_t642 + _t550*_t64 + 0.6e1*_t638 + 0.3e1*_t639 + 0.6e1*_t640 + 0.3e1*_t643 + 0.3e1*_t645;
  const double d4F_dna2_dnb2 = _t121*_t401 + 0.4e1*_t149*_t362 + _t152*_t644 + _t171*_t549 + _t326*(_t125*_t653 - _t132*_t662 - _t214*_t222 - _t219*_t85 + _t293*_t310 + _t367*_t81 + _t374*_t86 + _t38*(-_hc2[3]*_t219 - _hc2[3]*_t79 + 0.4e1*_t2*_t308*_t78 + (0.4e1 / 0.9e1)*_t304*_t7*_t74*_t8 + _t38*_t710 - _t571 - _t709) - _t39*(-_hc2[4]*_t219 - _hc2[4]*_t79 + 0.4e1*_t2*_t304*_t78 + (0.4e1 / 0.9e1)*_t305*_t7*_t74*_t8 + _t38*_t708 - _t561 - _t711) + _t675 + _t707 - _t79*_t85 + my_piecewise3(_t11, 0, _t126*_t653 - _t127*_t662 - _t219*_t91 - _t235*_t89 + _t293*_t324 + _t368*_t86 + _t370*_t81 + _t38*(-_hc3[3]*_t219 - _hc3[3]*_t79 + 0.4e1*_t2*_t322*_t78 + (0.4e1 / 0.9e1)*_t318*_t7*_t74*_t8 + _t38*_t715 - _t588 - _t714) - _t39*(-_hc3[4]*_t219 - _hc3[4]*_t79 + 0.4e1*_t2*_t318*_t78 + (0.4e1 / 0.9e1)*_t319*_t7*_t74*_t8 + _t38*_t713 - _t578 - _t716) + _t664 + _t712 - _t79*_t91) + my_piecewise3(_t12, 0, -_t129*_t662 + _t219*_t97 - _t235*_t95 - _t293*_t317 + _t302*_t407 + _t37*(_hc4[3]*_t219 + _hc4[3]*_t79 - _t293*_t316 + _t37*_t717 + _t719) + _t371*_t93 + _t372*_t86 - _t39*(_hc4[4]*_t219 + _hc4[4]*_t79 - _t293*_t313 + _t37*_t718 + _t721) + _t674 - _t720 + _t79*_t97)) + 0.2e1*_t327 + _t360*_t473 + _t361*(5.7037500000000002e-7*_t100*_t105*_t170*_t263 + 2.4098343749999995e-8*_t100*_t157*_t22*_t26*_t608*_t611 - _t100*_t157*_t676 + 6.3374999999999995e-5*_t101*_t102*_t105*_t120*_t170*_t26 + 6.3374999999999995e-5*_t101*_t102*_t105*_t148*_t26*_t333 + 0.00012674999999999999*_t101*_t102*_t105*_t26*_t359*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t49*_t728 + 5.7037500000000002e-7*_t105*_t120*_t157*_t263 + 1.14075e-6*_t105*_t263*_t333*_t49*_t62 - _t120*_t378 - _t137*_t728 - _t170*_t329 - _t170*_t444 + 0.001*_t22*_t23*_t28*_t737 - _t333*_t468 - _t359*_t477 - _t63*_t737 - _t722*_t725) + _t363*_t705 + 0.2e1*_t377 + _t400*_t439 + 0.4e1*_t638 + 0.2e1*_t639 + 0.4e1*_t640 + 0.2e1*_t643 + 0.2e1*_t645 + 0.4e1*_t701 + 0.2e1*_t702 + 0.4e1*_t703 + 0.2e1*_t704 + 0.2e1*_t706;
  const double d4F_dna_dnb3 = _t171*_t641 + _t211*_t437 + _t326*(_hc2[1]*_t623 - _t125*_t216 - _t125*_t742 + _t367*_t635 + _t38*_t741 + _t707 + _t748 + my_piecewise3(_t11, 0, _hc3[1]*_t623 - _t126*_t216 - _t126*_t742 + _t370*_t635 + _t38*_t743 + _t712 + _t744) + my_piecewise3(_t12, 0, -_hc4[1]*_t623 + (0.140e3 / 0.81e2)*_hc4[2]*_t551*_t7*_t8 + 0.18e2*_t131*_t2*_t217 + 0.6e1*_t131*_t78 + _t37*_t747 - _t371*_t635 + (0.2e1 / 0.3e1)*_t372*_t7*_t74*_t8 - _t720 - _t745 - _t746)) + _t361*(0.00019012499999999997*_t101*_t102*_t105*_t148*_t170*_t26 + 0.00019012499999999997*_t101*_t102*_t105*_t26*_t399*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t436*_t49 + 1.7111250000000001e-6*_t105*_t148*_t157*_t263 + 5.7037500000000002e-7*_t105*_t170*_t263*_t49*_t62 + 5.7037500000000002e-7*_t105*_t263*_t414*_t49*_t62 - _t137*_t436 - _t170*_t467 - _t170*_t752*_t753 + 0.001*_t22*_t23*_t28*_t765 + 2.4098343749999995e-8*_t22*_t26*_t410*_t49*_t608*_t611 - _t380*_t399*_t752 - _t410*_t49*_t676 - _t414*_t467 - _t63*_t765 - _t749*_t751) + 0.3e1*_t377 + _t400*_t403 + _t401*_t642 + _t402*_t705 + _t409 + _t438 + _t52*_t740 + 0.6e1*_t701 + 0.3e1*_t702 + 0.6e1*_t703 + 0.3e1*_t704 + 0.3e1*_t706 + 0.3e1*_t738 + 0.3e1*_t739;
  const double d4F_dnb4 = 0.4e1*_t151*_t437 + 0.6e1*_t171*_t401 + _t326*(_hc2[1]*_t766 + _t125*_t767 + _t367*_t768 + _t55*_t741 + _t748 + my_piecewise3(_t11, 0, _hc3[1]*_t766 + _t126*_t767 + _t370*_t768 + _t55*_t743 + _t744) + my_piecewise3(_t12, 0, _hc4[1]*_t769 + 0.3e1*_t131*_t404 + _t371*_t770 + _t372*_t559 + _t54*_t747 + _t592 - _t745 - _t746)) + _t361*(6.3374999999999995e-5*_t101*_t102*_t105*_t170*_t26*_t414 + 0.00012674999999999999*_t101*_t102*_t105*_t26*_t436*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t62*_t775 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t772 + 5.7037500000000002e-7*_t105*_t157*_t170*_t263 + 5.7037500000000002e-7*_t105*_t157*_t263*_t414 + 5.7037500000000002e-7*_t105*_t157*_t263*_t774 - _t136*_t772 - _t170*_t378 - _t185*_t775 + 0.001*_t22*_t23*_t28*_t778 + 2.4098343749999995e-8*_t22*_t26*_t608*_t611*_t771 - _t378*_t414 - _t378*_t774 - _t414*_t479 - _t436*_t477 - _t63*_t778 - _t676*_t771) + 0.4e1*_t409 + 0.4e1*_t438 + 0.4e1*_t64*_t740 + 0.12e2*_t738 + 0.12e2*_t739;
  const double d4F_dna3_dla = _t176*_t779 + _t176*_t780 + _t212*_t445 + _t361*(5.7037500000000002e-7*_t100*_t105*_t263*_t782 + 6.3374999999999995e-5*_t101*_t102*_t105*_t120*_t175*_t26 + 6.3374999999999995e-5*_t101*_t102*_t105*_t14*_t15*_t26*_t299 + 6.3374999999999995e-5*_t101*_t102*_t105*_t175*_t26*_t269 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t442*_t49 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t49*_t783 + 5.7037500000000002e-7*_t105*_t120*_t14*_t15*_t263*_t49 + 5.7037500000000002e-7*_t105*_t14*_t15*_t263*_t269*_t49 - _t120*_t500 - _t137*_t442 - _t137*_t783 + 2.4098343749999995e-8*_t14*_t15*_t22*_t26*_t264*_t608*_t611 - _t175*_t444 + 0.001*_t22*_t23*_t28*_t784 - _t269*_t496 - _t269*_t500 - _t329*_t782 - _t63*_t784 - _t66*_t781 - _t66*_t785) + 0.3e1*_t440 + 0.3e1*_t446 + _t550*_t67;
  const double d4F_dna3_dlb = _t181*_t779 + _t181*_t780 + _t212*_t459 + _t361*(_t120*_t797 - _t120*_t798 - _t137*_t450 - _t137*_t791 - _t180*_t444 + _t180*_t458 + _t197*_t299*_t69 + _t264*_t69*_t789 - _t269*_t795 + _t269*_t796 + _t269*_t797 - _t269*_t798 + _t450*_t462 + _t451*_t794 + _t462*_t791 - _t63*_t794 - _t69*_t781 - _t69*_t785 + _t787*_t788 - _t788*_t790) + 0.3e1*_t447 + 0.3e1*_t460 + _t550*_t70;
  const double d4F_dna2_dnb_dla = _t151*_t445 + _t176*_t799 + _t176*_t812 + _t186*_t549 + _t361*(-_t137*_t802 - _t184*_t329 - _t184*_t444 + _t184*_t453 + _t184*_t458 - _t185*_t442 - _t333*_t496 + _t333*_t498 + _t333*_t499 + _t442*_t463 + _t443*_t465 - _t443*_t467 + _t451*_t808 + _t462*_t802 - _t63*_t808 - _t66*_t801 + _t66*_t804 + _t66*_t805 - _t66*_t806 - _t66*_t809 - _t66*_t810 + _t66*_t811) + _t439*_t470 + _t440 + _t446 + _t644*_t67 + _t816;
  const double d4F_dna2_dnb_dlb = _t151*_t459 + _t181*_t799 + _t181*_t812 + _t191*_t549 + _t361*(-_t137*_t819 - _t185*_t450 - _t190*_t329 - _t190*_t444 + _t190*_t453 + _t190*_t458 - _t333*_t795 + _t333*_t796 + _t333*_t797 + _t450*_t463 + _t451*_t821 - _t455*_t725 + _t455*_t818 + _t462*_t819 - _t63*_t821 - _t69*_t801 + _t69*_t804 + _t69*_t805 - _t69*_t806 - _t69*_t809 - _t69*_t810 + _t69*_t811) + _t439*_t472 + _t447 + _t460 + _t644*_t70 + _t822;
  const double d4F_dna_dnb2_dla = _t176*_t401 + _t186*_t812 + _t186*_t815 + _t211*_t481 + _t361*(-_t137*_t475 - _t148*_t827 + _t170*_t499 - _t170*_t500 - _t175*_t378 + _t175*_t476 - _t175*_t479 + _t175*_t480 + _t184*_t829 + _t451*_t828 - _t461*_t477 + _t461*_t478 + _t462*_t475 - _t63*_t828 - _t66*_t833 + _t66*_t834 - _t725*_t825 + _t818*_t825 - _t823*_t824 + _t823*_t826 + _t830*_t831 - _t830*_t832) + _t470*_t473 + _t474 + _t482 + _t67*_t705 + _t816;
  const double d4F_dna_dnb2_dlb = _t181*_t401 + _t191*_t812 + _t191*_t815 + _t211*_t488 + _t361*(-_t137*_t486 - _t148*_t528 + _t170*_t797 - _t170*_t798 - _t180*_t378 + _t180*_t476 - _t180*_t479 + _t180*_t480 + _t190*_t829 + _t451*_t836 + _t462*_t486 + _t465*_t487 - _t467*_t487 - _t471*_t477 + _t471*_t478 - _t63*_t836 - _t69*_t833 + _t69*_t834 - _t824*_t835 + _t826*_t835 + _t831*_t837 - _t832*_t837) + _t472*_t473 + _t483 + _t489 + _t70*_t705 + _t822;
  const double d4F_dnb3_dla = _t186*_t838 + _t186*_t839 + _t361*(1.7111250000000001e-6*_t105*_t157*_t841 - _t136*_t844 + _t170*_t523 - _t170*_t524 - _t184*_t479 + _t184*_t480 - _t185*_t475 - _t185*_t842 + _t197*_t436*_t66 + _t197*_t844 + _t410*_t66*_t789 + _t414*_t523 - _t414*_t524 + _t451*_t843 + _t463*_t475 + _t463*_t842 - _t63*_t843 - _t66*_t840 - _t66*_t845 - _t751*_t841) + _t403*_t481 + 0.3e1*_t474 + 0.3e1*_t482 + _t67*_t740;
  const double d4F_dnb3_dlb = _t191*_t838 + _t191*_t839 + _t361*(6.3374999999999995e-5*_t101*_t102*_t105*_t170*_t190*_t26 + 6.3374999999999995e-5*_t101*_t102*_t105*_t18*_t19*_t26*_t436 + 6.3374999999999995e-5*_t101*_t102*_t105*_t190*_t26*_t414 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t486*_t62 + 6.3374999999999995e-5*_t101*_t102*_t105*_t26*_t62*_t847 + 5.7037500000000002e-7*_t105*_t157*_t263*_t846 + 5.7037500000000002e-7*_t105*_t170*_t18*_t19*_t263*_t62 + 5.7037500000000002e-7*_t105*_t18*_t19*_t263*_t414*_t62 - _t170*_t849 + 2.4098343749999995e-8*_t18*_t19*_t22*_t26*_t410*_t608*_t611 - _t185*_t486 - _t185*_t847 - _t190*_t479 + 0.001*_t22*_t23*_t28*_t848 - _t378*_t846 - _t414*_t520 - _t414*_t849 - _t63*_t848 - _t69*_t840 - _t69*_t845) + _t403*_t488 + 0.3e1*_t483 + 0.3e1*_t489 + _t70*_t740;
  const double d4F_dna2_dla2 = _t198*_t549 + _t361*(-_t195*_t800 + _t195*_t803 + _t195*_t854 - _t195*_t855 - _t442*_t491 + _t442*_t852 - _t443*_t496 + _t443*_t498 + _t850*_t851 - _t851*_t853) + _t439*_t493 + 0.2e1*_t490 + 0.2e1*_t494;
  const double d4F_dna2_dla_dlb = _t202*_t549 + _t361*(-_t200*_t450 - _t201*_t800 + _t201*_t803 + _t201*_t854 - _t201*_t855 - _t442*_t519 + _t442*_t521 - _t443*_t795 + _t443*_t796 + _t443*_t797 - _t443*_t798 + _t450*_t497 + _t850*_t856 - _t853*_t856) + _t439*_t501 + 0.2e1*_t495 + 0.2e1*_t502;
  const double d4F_dna2_dlb2 = _t207*_t549 + _t361*(_t204*_t457*_t857 - _t206*_t800 + _t206*_t803 + _t206*_t854 - _t206*_t855 - _t450*_t858 + _t450*_t861 - _t504*_t857 + _t859*_t860 - _t860*_t862) + _t439*_t508 + 0.2e1*_t503 + 0.2e1*_t509;
  const double d4F_dna_dnb_dla2 = _t151*_t493 + _t198*_t362 + _t211*_t516 + _t361*(-_t175*_t827 + _t175*_t863 - _t195*_t867 + _t195*_t869 + _t195*_t870 - _t195*_t871 - _t461*_t491 + _t461*_t852 - _t492*_t725 + _t492*_t818 + _t513*_t864 - _t513*_t865) + _t490 + _t494 + _t510 + _t517;
  const double d4F_dna_dnb_dla_dlb = _t151*_t501 + _t202*_t362 + _t211*_t525 + _t361*(_t175*_t514*_t69 - _t175*_t849 + _t180*_t523 - _t180*_t524 - _t184*_t795 + _t184*_t796 + _t184*_t797 - _t184*_t798 - _t190*_t496 + _t190*_t498 + _t190*_t499 - _t190*_t500 - _t200*_t471 + _t201*_t870 - _t201*_t871 - _t461*_t519 + _t461*_t521 + _t471*_t497 - _t872*_t873 + _t873*_t874) + _t495 + _t502 + _t518 + _t526;
  const double d4F_dna_dnb_dlb2 = _t151*_t508 + _t207*_t362 + _t211*_t530 + _t361*(_t180*_t190*_t457 - _t180*_t528 - _t206*_t867 + _t206*_t869 + _t206*_t870 - _t206*_t871 - _t471*_t858 + _t471*_t861 - _t507*_t725 + _t507*_t818 + _t529*_t864 - _t529*_t865) + _t503 + _t509 + _t527 + _t531;
  const double d4F_dnb2_dla2 = _t198*_t401 + _t361*(_t103*_t105*_t193*_t875*(0.00012674999999999999*_t24*(0.001*_t17 + 0.001*_t21) - 8.8724999999999995e-8) - _t195*_t824 + _t195*_t826 + _t195*_t877 - _t195*_t878 - _t475*_t491 + _t475*_t852 - _t511*_t875 + _t859*_t876 - _t862*_t876) + _t473*_t516 + 0.2e1*_t510 + 0.2e1*_t517;
  const double d4F_dnb2_dla_dlb = _t202*_t401 + _t361*(-_t184*_t528 + _t190*_t863 - _t200*_t486 - _t201*_t824 + _t201*_t826 + _t201*_t877 - _t201*_t878 - _t475*_t519 + _t475*_t521 + _t486*_t497 + _t487*_t523 - _t487*_t524 - _t725*_t879 + _t818*_t879) + _t473*_t525 + 0.2e1*_t518 + 0.2e1*_t526;
  const double d4F_dnb2_dlb2 = _t207*_t401 + _t361*(-_t206*_t824 + _t206*_t826 + _t206*_t877 - _t206*_t878 - _t486*_t858 + _t486*_t861 - _t487*_t520 + _t487*_t522 - _t725*_t880 + _t818*_t880) + _t473*_t530 + 0.2e1*_t527 + 0.2e1*_t531;
  const double d4F_dna_dla3 = _t211*_t535 + _t361*(-_t534*_t866 + _t534*_t868 + _t787*_t881 - _t790*_t881) + _t536;
  const double d4F_dna_dla2_dlb = _t211*_t538 + _t361*(5.7037500000000002e-7*_hc1[2]*_t105*_t19*_t193*_t194*_t263*_t37 + 1.14075e-6*_t105*_t14*_t15*_t175*_t18*_t19*_t263 + 2.4098343749999995e-8*_t18*_t19*_t193*_t194*_t22*_t26*_t49*_t608*_t611 - _t180*_t537 - _t492*_t69*_t853 - _t866*_t882) + _t539;
  const double d4F_dna_dla_dlb2 = _t211*_t541 + _t361*(1.14075e-6*_hc1[2]*_t105*_t14*_t15*_t18*_t204*_t263*_t37 + 5.7037500000000002e-7*_t105*_t175*_t204*_t205*_t263 + 2.4098343749999995e-8*_t14*_t15*_t204*_t205*_t22*_t26*_t49*_t608*_t611 - _t175*_t540 - _t507*_t883 - _t823*_t884) + _t542;
  const double d4F_dna_dlb3 = _t211*_t546 + _t361*(1.7111250000000001e-6*_hc1[2]*_t105*_t205*_t263*_t37*_t543 - _t205*_t505*_t543*_t790 + 2.4098343749999995e-8*_t22*_t26*_t49*_t543*_t544*_t608*_t611 - _t545*_t866) + _t547;
  const double d4F_dnb_dla3 = _t151*_t535 + _t361*(1.7111250000000001e-6*_hc0[2]*_t105*_t194*_t263*_t532*_t55 - _t141*_t194*_t532*_t790 + 2.4098343749999995e-8*_t22*_t26*_t532*_t533*_t608*_t611*_t62 - _t534*_t872) + _t536;
  const double d4F_dnb_dla2_dlb = _t151*_t538 + _t361*(1.14075e-6*_hc0[2]*_t105*_t15*_t18*_t19*_t193*_t263*_t55 + 5.7037500000000002e-7*_t105*_t190*_t193*_t194*_t263 + 2.4098343749999995e-8*_t18*_t19*_t193*_t194*_t22*_t26*_t608*_t611*_t62 - _t190*_t537 - _t513*_t69*_t853 - _t872*_t882) + _t539;
  const double d4F_dnb_dla_dlb2 = _t151*_t541 + _t361*(5.7037500000000002e-7*_hc0[2]*_t105*_t14*_t204*_t205*_t263*_t55 + 1.14075e-6*_t105*_t14*_t15*_t18*_t19*_t190*_t263 + 2.4098343749999995e-8*_t14*_t15*_t204*_t205*_t22*_t26*_t608*_t611*_t62 - _t184*_t540 - _t206*_t66*_t872 - _t529*_t883) + _t542;
  const double d4F_dnb_dlb3 = _t151*_t546 + _t361*(-_t545*_t872 + _t545*_t874 + _t787*_t885 - _t790*_t885) + _t547;
  const double d4F_dla4 = _t361*(-_t676*_t886 + _t789*_t886);
  const double d4F_dla3_dlb = _t361*(-_t676*_t887 + _t789*_t887);
  const double d4F_dla2_dlb2 = _t361*(_t195*_t206*_t789 - _t195*_t884);
  const double d4F_dla_dlb3 = _t361*(-_t676*_t888 + _t789*_t888);
  const double d4F_dlb4 = _t361*(-_t676*_t889 + _t789*_t889);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 1] += d4F_dna3_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 2] += d4F_dna2_dnb_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 3] += d4F_dna2_dnb_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 4] += d4F_dna_dnb2_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 5] += d4F_dna_dnb2_dlb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 6] += d4F_dnb3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += d4F_dnb3_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 1] += d4F_dna2_dla_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 2] += d4F_dna2_dlb2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 3] += d4F_dna_dnb_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 4] += d4F_dna_dnb_dla_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 5] += d4F_dna_dnb_dlb2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 6] += d4F_dnb2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 7] += d4F_dnb2_dla_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += d4F_dnb2_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 1] += d4F_dna_dla2_dlb;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 2] += d4F_dna_dla_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 3] += d4F_dna_dlb3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 4] += d4F_dnb_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 5] += d4F_dnb_dla2_dlb;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 6] += d4F_dnb_dla_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += d4F_dnb_dlb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 1] += d4F_dla3_dlb;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 2] += d4F_dla2_dlb2;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 3] += d4F_dla_dlb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 4] += d4F_dlb4;
#endif
#endif
}
#endif