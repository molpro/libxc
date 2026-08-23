/*
  Generated from python/mgga_exc/mgga_x_vcml.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_vcml
*/

#ifndef _MGGA_X_VCML_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_VCML_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_VCML_HELPER_BODIES
#include "mgga_x_vcml.c"
#undef _MGGA_X_VCML_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_VCML_HELPER_BODIES
#include "mgga_x_vcml.c"
#undef _MGGA_X_VCML_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_VCML_HELPER_BODIES
#include "mgga_x_vcml.c"
#undef _MGGA_X_VCML_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_VCML_HELPER_BODIES
#include "mgga_x_vcml.c"
#undef _MGGA_X_VCML_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_VCML_HELPER_BODIES
#include "mgga_x_vcml.c"
#undef _MGGA_X_VCML_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_vcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_VCML_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeef_xi_k, _KMAX)(const xc_func_type *p, double p_, double *out) {

  const double _t1 = p_ + 6.5124000000000004;
  const double _t2 = (0.1e1 / _t1);
#if _KMAX >= 1
  const double _t3 = (0.1e1 / (_t1 * _t1));
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (_t1 * _t1 * _t1));
#endif
#if _KMAX >= 3
  const double _t5 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
#endif

  const double f = 0.2e1*_t2*p_ - 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dp_ = 0.2e1*_t2 - 0.2e1*_t3*p_;
  out[1] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_dp_2 = -0.4e1*_t3 + 0.4e1*_t4*p_;
  out[2] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_dp_3 = 0.12e2*_t4 - 0.12e2*_t5*p_;
  out[3] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_dp_4 = -0.48e2*_t5 + 0.48e2*p_/xc_powi(_t1, 5);
  out[4] = d4f_dp_4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeef_xj0_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = a + 0.1e1;
  const double _t2 = (_t1 * _t1 * _t1);
  const double _t3 = 0.1e1 - a;
  const double _t4 = (_t3 * _t3 * _t3);
  const double _t5 = (a * a * a);
  const double _t6 = 0.4e1*_t5 + 0.1e1;
  const double _t7 = _t5*_t6 + 0.1e1;
  const double _t8 = (0.1e1 / _t7);
  const double _t9 = _t4*_t8;
#if _KMAX >= 1
  const double _t10 = (_t3 * _t3);
  const double _t11 = _t2*_t8;
  const double _t12 = 0.3e1*_t11;
  const double _t13 = (_t1 * _t1);
  const double _t14 = xc_powi(a, 5);
  const double _t15 = 0.12e2*_t14;
  const double _t16 = (a * a);
  const double _t17 = -0.12e2*_t5 - 0.3e1;
  const double _t18 = -_t15 + _t16*_t17;
  const double _t19 = (0.1e1 / (_t7 * _t7));
  const double _t20 = _t19*_t4;
  const double _t21 = _t2*_t20;
#endif
#if _KMAX >= 2
  const double _t22 = 0.2e1*a;
  const double _t23 = _t22 - 0.2e1;
  const double _t24 = 0.6e1*a;
  const double _t25 = _t10*_t8;
  const double _t26 = (a * a * a * a);
  const double _t27 = -_t24*_t6 - 0.96e2*_t26;
  const double _t28 = 0.72e2*_t14 - 0.6e1*_t16*_t17;
  const double _t29 = _t10*_t19;
  const double _t30 = _t2*_t29;
  const double _t31 = _t13*_t20;
  const double _t32 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t33 = 0.24e2*_t14;
  const double _t34 = _t16*(-0.24e2*_t5 - 0.6e1) - _t33;
  const double _t35 = _t32*_t34;
  const double _t36 = _t18*_t35;
  const double _t37 = _t2*_t4;
#endif
#if _KMAX >= 3
  const double _t38 = _t13*_t8;
  const double _t39 = 0.54e2*a;
  const double _t40 = -0.480e3*_t5 - 0.6e1;
  const double _t41 = 0.864e3*_t26 + _t39*_t6;
  const double _t42 = _t16*_t6;
  const double _t43 = -_t15 - 0.3e1*_t42;
  const double _t44 = _t19*_t43;
  const double _t45 = _t23*_t44;
  const double _t46 = 0.9e1*_t2;
  const double _t47 = _t13*_t29;
  const double _t48 = _t22 + 0.2e1;
  const double _t49 = _t18*_t48;
  const double _t50 = _t6*a;
  const double _t51 = -0.192e3*_t26 - 0.12e2*_t50;
  const double _t52 = _t18*_t37;
  const double _t53 = _t32*_t52;
  const double _t54 = _t27*_t35;
  const double _t55 = _t10*_t36;
  const double _t56 = _t13*_t4;
  const double _t57 = -0.36e2*_t14 + _t16*(-0.36e2*_t5 - 0.9e1);
  const double _t58 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t59 = _t34*_t52*_t58;
#endif
#if _KMAX >= 4
  const double _t60 = 0.5760e4*_t5 + 0.72e2;
  const double _t61 = 0.24e2*_t2;
  const double _t62 = 0.18e2*_t27;
  const double _t63 = _t2*_t23;
  const double _t64 = 0.108e3*_t13;
  const double _t65 = 0.3e1*_t37;
  const double _t66 = _t32*_t51;
  const double _t67 = _t27*_t65;
  const double _t68 = 0.12e2*_t18;
  const double _t69 = _t66*_t68;
  const double _t70 = _t10*_t2;
  const double _t71 = _t57*_t58;
  const double _t72 = _t34*_t71;
  const double _t73 = _t68*_t72;
#endif

  const double f = _t2*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t10*_t12 + 0.3e1*_t13*_t9 + _t18*_t21;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -_t12*_t23 - 0.18e2*_t13*_t25 + _t21*_t27 + _t28*_t30 - _t28*_t31 + _t36*_t37 + _t9*(_t24 + 0.6e1);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -0.6e1*_t11 + 0.9e1*_t20*_t49 + _t21*_t40 - 0.27e2*_t23*_t38 + _t25*(-_t39 - 0.54e2) + _t30*_t41 - _t31*_t41 + 0.9e1*_t36*_t56 + 0.2e1*_t37*_t54 - _t45*_t46 - _t46*_t55 + _t47*(0.648e3*_t14 - 0.54e2*_t16*_t17) + _t51*_t53 + _t57*_t59 + 0.6e1*_t9;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -_t10*_t54*_t61 - 0.1440e4*_t16*_t21 - _t19*_t62*_t63 + _t20*_t48*_t62 + _t20*(-0.288e3*_t14 + 0.24e2*_t16*_t17) - 0.54e2*_t23*_t48*_t8 - 0.72e2*_t25 - 0.108e3*_t29*_t49 + _t30*_t60 - _t31*_t60 - 0.18e2*_t32*_t43*_t63*(-_t33 - 0.6e1*_t42) + _t34*_t52*_t57*(-0.48e2*_t14 + _t16*(-0.48e2*_t5 - 0.12e2))/xc_powi(_t7, 5) + _t35*_t40*_t65 + 0.18e2*_t36*_t4*_t48 - 0.72e2*_t38 - _t44*_t61 - _t45*_t64 + _t47*(0.10368e5*_t26 + 0.648e3*_t50) + 0.2e1*_t51*_t52*_t71 + _t53*(-0.960e3*_t5 - 0.12e2) + 0.24e2*_t54*_t56 - _t55*_t64 + _t56*_t69 + _t56*_t73 + _t59*(-0.288e3*_t26 - 0.18e2*_t50) + _t66*_t67 + _t67*_t72 - _t69*_t70 - _t70*_t73;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeef_xj_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = a > 10000.0;
  const double _t2 = a >= 10000.0;
  const double _t3 = my_piecewise3(_t1, a, 10000.0);
  const double _t4 = (0.1e1 / (_t3 * _t3 * _t3));
#if _KMAX >= 1
  const double _t5 = my_piecewise3(_t1, 0.1e1, 0);
  const double _t6 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t7 = my_piecewise3(_t1, 0, 0.1e1);
#endif
#if _KMAX >= 2
  const double _t8 = xc_powi(_t3, -5);
  const double _t9 = (_t5 * _t5);
#endif
#if _KMAX >= 3
  const double _t10 = xc_powi(_t3, -6);
  const double _t11 = (_t5 * _t5 * _t5);
#endif
#if _KMAX >= 4
  const double _t12 = (_t5 * _t5 * _t5 * _t5);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(mbeef_xj0_k, _KMAX)(p, my_piecewise3(_t1, 10000.0, a), _hc0);

  const double f = my_piecewise3(_t2, (0.1e1 / 0.16e2)*_t4 - 0.1e1 / 0.4e1 + (0.3e1 / 0.4e1)/(_t3 * _t3), _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, -0.3e1 / 0.2e1*_t4*_t5 - 0.3e1 / 0.16e2*_t5*_t6, _hc0[1]*_t7);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, (0.9e1 / 0.2e1)*_t6*_t9 + (0.3e1 / 0.4e1)*_t8*_t9, _hc0[2]*(_t7 * _t7));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, -0.15e2 / 0.4e1*_t10*_t11 - 0.18e2*_t11*_t8, _hc0[3]*(_t7 * _t7 * _t7));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, 0.90e2*_t10*_t12 + (0.45e2 / 0.2e1)*_t12/xc_powi(_t3, 7), _hc0[4]*(_t7 * _t7 * _t7 * _t7));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mgga_alpha_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = (0.5e1 / 0.9e1)*_t1;

  const double f = _t2*(t - 0.1e1 / 0.8e1*x2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t2;
  out[1] = df_dt;
  const double df_dx2 = -0.5e1 / 0.72e2*_t1;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = 0;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = 0;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = 0;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = 0;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = 0;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = 0;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = 0;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = 0;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 0;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeef_expansion_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mgga_alpha_pf_k, _KMAX)(p, x2, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(mbeef_xj_k, _KMAX)(p, _hc0[0], _hc1);
  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t5 = ((_hc1[0]) * (_hc1[0]));
  const double _t6 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t7 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t8 = xc_powi((_hc1[0]), 5);
  const double _t9 = xc_powi((_hc1[0]), 6);
  const double _t10 = xc_powi((_hc1[0]), 7);
  const double _t18 = (0.3e1 / 0.2e1)*_t5 - 0.1e1 / 0.2e1;
  const double _t21 = -0.3e1 / 0.2e1*_hc1[0] + (0.5e1 / 0.2e1)*_t6;
  const double _t26 = -0.15e2 / 0.4e1*_t5 + (0.35e2 / 0.8e1)*_t7 + 0.3e1 / 0.8e1;
  const double _t30 = (0.15e2 / 0.8e1)*_hc1[0] - 0.35e2 / 0.4e1*_t6 + (0.63e2 / 0.8e1)*_t8;
  const double _t37 = (0.105e3 / 0.16e2)*_t5 - 0.315e3 / 0.16e2*_t7 + (0.231e3 / 0.16e2)*_t9 - 0.5e1 / 0.16e2;
  const double _t43 = -0.35e2 / 0.16e2*_hc1[0] + (0.429e3 / 0.16e2)*_t10 + (0.315e3 / 0.16e2)*_t6 - 0.693e3 / 0.16e2*_t8;
#if _KMAX >= 1
  const double _t71 = _hc0[1]*_hc1[1];
  const double _t72 = _hc1[0]*_t71;
  const double _t74 = _t5*_t71;
  const double _t75 = _t6*_t71;
  const double _t76 = _t7*_t71;
  const double _t77 = _t71*_t8;
  const double _t78 = _t71*_t9;
  const double _t79 = 0.3e1*_t72;
  const double _t80 = -0.3e1 / 0.2e1*_t71 + (0.15e2 / 0.2e1)*_t74;
  const double _t81 = -0.15e2 / 0.2e1*_t72 + (0.35e2 / 0.2e1)*_t75;
  const double _t82 = (0.15e2 / 0.8e1)*_t71 - 0.105e3 / 0.4e1*_t74 + (0.315e3 / 0.8e1)*_t76;
  const double _t83 = (0.105e3 / 0.8e1)*_t72 - 0.315e3 / 0.4e1*_t75 + (0.693e3 / 0.8e1)*_t77;
  const double _t84 = -0.35e2 / 0.16e2*_t71 + (0.945e3 / 0.16e2)*_t74 - 0.3465e4 / 0.16e2*_t76 + (0.3003e4 / 0.16e2)*_t78;
  const double _t85 = _hc0[2]*_hc1[1];
  const double _t86 = _hc1[0]*_t85;
  const double _t87 = _t5*_t85;
  const double _t88 = _t6*_t85;
  const double _t89 = _t7*_t85;
  const double _t90 = _t8*_t85;
  const double _t91 = _t85*_t9;
  const double _t96 = 0.3e1*_t86;
  const double _t102 = -0.3e1 / 0.2e1*_t85 + (0.15e2 / 0.2e1)*_t87;
  const double _t103 = -0.15e2 / 0.2e1*_t86 + (0.35e2 / 0.2e1)*_t88;
  const double _t107 = (0.15e2 / 0.8e1)*_t85 - 0.105e3 / 0.4e1*_t87 + (0.315e3 / 0.8e1)*_t89;
  const double _t109 = (0.105e3 / 0.8e1)*_t86 - 0.315e3 / 0.4e1*_t88 + (0.693e3 / 0.8e1)*_t90;
  const double _t117 = -0.35e2 / 0.16e2*_t85 + (0.945e3 / 0.16e2)*_t87 - 0.3465e4 / 0.16e2*_t89 + (0.3003e4 / 0.16e2)*_t91;
#endif
#if _KMAX >= 2
  const double _t152 = ((_hc0[1]) * (_hc0[1]));
  const double _t153 = _hc1[2]*_t152;
  const double _t154 = _hc1[0]*_t153;
  const double _t155 = ((_hc1[1]) * (_hc1[1]));
  const double _t156 = _t152*_t155;
  const double _t157 = _hc1[0]*_t156;
  const double _t158 = _t153*_t5;
  const double _t159 = _t153*_t6;
  const double _t160 = _t153*_t7;
  const double _t161 = _t153*_t8;
  const double _t162 = _t153*_t9;
  const double _t163 = _t156*_t5;
  const double _t164 = _t156*_t6;
  const double _t165 = _t156*_t7;
  const double _t166 = _t156*_t8;
  const double _t167 = 0.3e1*_t154;
  const double _t168 = 0.3e1*_t156;
  const double _t169 = -0.3e1 / 0.2e1*_t153 + 0.15e2*_t157 + (0.15e2 / 0.2e1)*_t158;
  const double _t170 = -0.15e2 / 0.2e1*_t154 - 0.15e2 / 0.2e1*_t156 + (0.35e2 / 0.2e1)*_t159 + (0.105e3 / 0.2e1)*_t163;
  const double _t171 = (0.15e2 / 0.8e1)*_t153 - 0.105e3 / 0.2e1*_t157 - 0.105e3 / 0.4e1*_t158 + (0.315e3 / 0.8e1)*_t160 + (0.315e3 / 0.2e1)*_t164;
  const double _t172 = (0.105e3 / 0.8e1)*_t154 + (0.105e3 / 0.8e1)*_t156 - 0.315e3 / 0.4e1*_t159 + (0.693e3 / 0.8e1)*_t161 - 0.945e3 / 0.4e1*_t163 + (0.3465e4 / 0.8e1)*_t165;
  const double _t173 = -0.35e2 / 0.16e2*_t153 + (0.945e3 / 0.8e1)*_t157 + (0.945e3 / 0.16e2)*_t158 - 0.3465e4 / 0.16e2*_t160 + (0.3003e4 / 0.16e2)*_t162 - 0.3465e4 / 0.4e1*_t164 + (0.9009e4 / 0.8e1)*_t166;
  const double _t174 = _hc0[1]*_hc0[2];
  const double _t175 = _hc1[2]*_t174;
  const double _t176 = _hc1[0]*_t175;
  const double _t177 = _t155*_t174;
  const double _t178 = _hc1[0]*_t177;
  const double _t179 = _t175*_t5;
  const double _t180 = _t175*_t6;
  const double _t181 = _t175*_t7;
  const double _t182 = _t175*_t8;
  const double _t183 = _t175*_t9;
  const double _t184 = _t177*_t5;
  const double _t185 = _t177*_t6;
  const double _t186 = _t177*_t7;
  const double _t187 = _t177*_t8;
  const double _t189 = 0.3e1*_t176;
  const double _t191 = 0.3e1*_t177;
  const double _t192 = -0.3e1 / 0.2e1*_t175 + 0.15e2*_t178 + (0.15e2 / 0.2e1)*_t179;
  const double _t193 = -0.15e2 / 0.2e1*_t176 - 0.15e2 / 0.2e1*_t177 + (0.35e2 / 0.2e1)*_t180 + (0.105e3 / 0.2e1)*_t184;
  const double _t194 = (0.15e2 / 0.8e1)*_t175 - 0.105e3 / 0.2e1*_t178 - 0.105e3 / 0.4e1*_t179 + (0.315e3 / 0.8e1)*_t181 + (0.315e3 / 0.2e1)*_t185;
  const double _t195 = (0.105e3 / 0.8e1)*_t176 + (0.105e3 / 0.8e1)*_t177 - 0.315e3 / 0.4e1*_t180 + (0.693e3 / 0.8e1)*_t182 - 0.945e3 / 0.4e1*_t184 + (0.3465e4 / 0.8e1)*_t186;
  const double _t196 = -0.35e2 / 0.16e2*_t175 + (0.945e3 / 0.8e1)*_t178 + (0.945e3 / 0.16e2)*_t179 - 0.3465e4 / 0.16e2*_t181 + (0.3003e4 / 0.16e2)*_t183 - 0.3465e4 / 0.4e1*_t185 + (0.9009e4 / 0.8e1)*_t187;
  const double _t197 = ((_hc0[2]) * (_hc0[2]));
  const double _t198 = _hc1[2]*_t197;
  const double _t199 = _hc1[0]*_t198;
  const double _t200 = _t155*_t197;
  const double _t201 = xc_powr(0.6e1, 2, 3);
  const double _t202 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t203 = _t201*_t202;
  const double _t205 = _hc1[0]*_t200;
  const double _t206 = _t198*_t5;
  const double _t207 = _t198*_t6;
  const double _t208 = _t198*_t7;
  const double _t209 = _t198*_t8;
  const double _t210 = _t198*_t9;
  const double _t215 = _t200*_t5;
  const double _t216 = _t200*_t6;
  const double _t217 = _t200*_t7;
  const double _t218 = _t200*_t8;
  const double _t220 = 6.8414605478279151e-5*_hc1[0];
  const double _t230 = 0.3e1*_t199;
  const double _t235 = 0.3e1*_t200;
  const double _t249 = 0.2e1*_t85;
  const double _t251 = 0.6e1*_t86;
  const double _t253 = -0.3e1 / 0.2e1*_t198 + 0.15e2*_t205 + (0.15e2 / 0.2e1)*_t206;
  const double _t264 = 0.2e1*_t102;
  const double _t266 = 0.2e1*_t103;
  const double _t267 = -0.15e2 / 0.2e1*_t199 - 0.15e2 / 0.2e1*_t200 + (0.35e2 / 0.2e1)*_t207 + (0.105e3 / 0.2e1)*_t215;
  const double _t269 = 0.2e1*_t107;
  const double _t271 = 0.2e1*_t109;
  const double _t273 = (0.15e2 / 0.8e1)*_t198 - 0.105e3 / 0.2e1*_t205 - 0.105e3 / 0.4e1*_t206 + (0.315e3 / 0.8e1)*_t208 + (0.315e3 / 0.2e1)*_t216;
  const double _t276 = 0.2e1*_t117;
  const double _t281 = (0.105e3 / 0.8e1)*_t199 + (0.105e3 / 0.8e1)*_t200 - 0.315e3 / 0.4e1*_t207 + (0.693e3 / 0.8e1)*_t209 - 0.945e3 / 0.4e1*_t215 + (0.3465e4 / 0.8e1)*_t217;
  const double _t288 = -0.35e2 / 0.16e2*_t198 + (0.945e3 / 0.8e1)*_t205 + (0.945e3 / 0.16e2)*_t206 - 0.3465e4 / 0.16e2*_t208 + (0.3003e4 / 0.16e2)*_t210 - 0.3465e4 / 0.4e1*_t216 + (0.9009e4 / 0.8e1)*_t218;
#endif
#if _KMAX >= 3
  const double _t308 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t309 = _hc1[3]*_t308;
  const double _t310 = _hc1[0]*_t309;
  const double _t311 = _hc1[1]*_hc1[2];
  const double _t312 = _t308*_t311;
  const double _t313 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t314 = _t308*_t313;
  const double _t315 = _hc1[0]*_t312;
  const double _t317 = _hc1[0]*_t314;
  const double _t318 = _t309*_t5;
  const double _t319 = _t309*_t6;
  const double _t320 = _t309*_t7;
  const double _t321 = _t309*_t8;
  const double _t322 = _t309*_t9;
  const double _t323 = _t312*_t5;
  const double _t324 = _t312*_t6;
  const double _t325 = _t312*_t7;
  const double _t326 = _t312*_t8;
  const double _t327 = _t314*_t5;
  const double _t328 = _t314*_t6;
  const double _t329 = _t314*_t7;
  const double _t330 = 0.3e1*_t310;
  const double _t331 = 0.9e1*_t312;
  const double _t332 = -0.3e1 / 0.2e1*_t309 + 0.15e2*_t314 + 0.45e2*_t315 + (0.15e2 / 0.2e1)*_t318;
  const double _t333 = -0.15e2 / 0.2e1*_t310 - 0.45e2 / 0.2e1*_t312 + 0.105e3*_t317 + (0.35e2 / 0.2e1)*_t319 + (0.315e3 / 0.2e1)*_t323;
  const double _t334 = (0.945e3 / 0.2e1)*_t314;
  const double _t335 = (0.15e2 / 0.8e1)*_t309 - 0.105e3 / 0.2e1*_t314 - 0.315e3 / 0.2e1*_t315 - 0.105e3 / 0.4e1*_t318 + (0.315e3 / 0.8e1)*_t320 + (0.945e3 / 0.2e1)*_t324 + _t334*_t5;
  const double _t336 = (0.315e3 / 0.8e1)*_t308;
  const double _t337 = -_hc1[0]*_t334 + (0.105e3 / 0.8e1)*_t310 + _t311*_t336 - 0.315e3 / 0.4e1*_t319 + (0.693e3 / 0.8e1)*_t321 - 0.2835e4 / 0.4e1*_t323 + (0.10395e5 / 0.8e1)*_t325 + (0.3465e4 / 0.2e1)*_t328;
  const double _t338 = -0.35e2 / 0.16e2*_t309 + (0.945e3 / 0.8e1)*_t314 + (0.2835e4 / 0.8e1)*_t315 + (0.945e3 / 0.16e2)*_t318 - 0.3465e4 / 0.16e2*_t320 + (0.3003e4 / 0.16e2)*_t322 - 0.10395e5 / 0.4e1*_t324 + (0.27027e5 / 0.8e1)*_t326 - 0.10395e5 / 0.4e1*_t327 + (0.45045e5 / 0.8e1)*_t329;
  const double _t339 = _hc0[2]*_t152;
  const double _t340 = _hc1[3]*_t339;
  const double _t341 = _hc1[0]*_t340;
  const double _t342 = _t153*_t85;
  const double _t343 = _t313*_t339;
  const double _t344 = _t153*_t86;
  const double _t345 = _hc1[0]*_t343;
  const double _t346 = _t340*_t5;
  const double _t347 = _t340*_t6;
  const double _t348 = _t340*_t7;
  const double _t349 = _t340*_t8;
  const double _t350 = _t340*_t9;
  const double _t351 = _t153*_t87;
  const double _t352 = _t153*_t88;
  const double _t353 = _t153*_t89;
  const double _t354 = _t153*_t90;
  const double _t355 = _t343*_t5;
  const double _t356 = _t343*_t6;
  const double _t357 = _t343*_t7;
  const double _t358 = 0.3e1*_t341;
  const double _t359 = 0.9e1*_t342;
  const double _t360 = 0.15e2*_t313;
  const double _t361 = _t339*_t360 - 0.3e1 / 0.2e1*_t340 + 0.45e2*_t344 + (0.15e2 / 0.2e1)*_t346;
  const double _t362 = -0.15e2 / 0.2e1*_t341 - 0.45e2 / 0.2e1*_t342 + 0.105e3*_t345 + (0.35e2 / 0.2e1)*_t347 + (0.315e3 / 0.2e1)*_t351;
  const double _t363 = (0.945e3 / 0.2e1)*_t343;
  const double _t364 = (0.15e2 / 0.8e1)*_t340 - 0.105e3 / 0.2e1*_t343 - 0.315e3 / 0.2e1*_t344 - 0.105e3 / 0.4e1*_t346 + (0.315e3 / 0.8e1)*_t348 + (0.945e3 / 0.2e1)*_t352 + _t363*_t5;
  const double _t365 = -_hc1[0]*_t363 + (0.105e3 / 0.8e1)*_t341 + (0.315e3 / 0.8e1)*_t342 - 0.315e3 / 0.4e1*_t347 + (0.693e3 / 0.8e1)*_t349 - 0.2835e4 / 0.4e1*_t351 + (0.10395e5 / 0.8e1)*_t353 + (0.3465e4 / 0.2e1)*_t356;
  const double _t366 = -0.35e2 / 0.16e2*_t340 + (0.945e3 / 0.8e1)*_t343 + (0.2835e4 / 0.8e1)*_t344 + (0.945e3 / 0.16e2)*_t346 - 0.3465e4 / 0.16e2*_t348 + (0.3003e4 / 0.16e2)*_t350 - 0.10395e5 / 0.4e1*_t352 + (0.27027e5 / 0.8e1)*_t354 - 0.10395e5 / 0.4e1*_t355 + (0.45045e5 / 0.8e1)*_t357;
  const double _t367 = _hc0[1]*_t197;
  const double _t368 = _hc1[3]*_t367;
  const double _t369 = _hc1[0]*_t368;
  const double _t370 = _t198*_t71;
  const double _t371 = _t313*_t367;
  const double _t372 = _t198*_t72;
  const double _t373 = _hc1[0]*_t371;
  const double _t374 = _t368*_t5;
  const double _t375 = _t368*_t6;
  const double _t376 = _t368*_t7;
  const double _t377 = _t368*_t8;
  const double _t378 = _t368*_t9;
  const double _t379 = _t198*_t74;
  const double _t380 = _t198*_t75;
  const double _t381 = _t198*_t76;
  const double _t382 = _t198*_t77;
  const double _t383 = _t371*_t5;
  const double _t384 = _t371*_t6;
  const double _t385 = _t371*_t7;
  const double _t391 = 0.3e1*_t369;
  const double _t392 = 0.9e1*_t370;
  const double _t393 = 0.2e1*_t175;
  const double _t394 = 0.6e1*_t176;
  const double _t395 = 0.6e1*_t177;
  const double _t396 = _t360*_t367 - 0.3e1 / 0.2e1*_t368 + 0.45e2*_t372 + (0.15e2 / 0.2e1)*_t374;
  const double _t397 = 0.2e1*_t192;
  const double _t398 = -0.15e2 / 0.2e1*_t369 - 0.45e2 / 0.2e1*_t370 + 0.105e3*_t373 + (0.35e2 / 0.2e1)*_t375 + (0.315e3 / 0.2e1)*_t379;
  const double _t399 = 0.2e1*_t193;
  const double _t400 = 0.2e1*_t194;
  const double _t401 = (0.945e3 / 0.2e1)*_t371;
  const double _t402 = (0.15e2 / 0.8e1)*_t368 - 0.105e3 / 0.2e1*_t371 - 0.315e3 / 0.2e1*_t372 - 0.105e3 / 0.4e1*_t374 + (0.315e3 / 0.8e1)*_t376 + (0.945e3 / 0.2e1)*_t380 + _t401*_t5;
  const double _t403 = 0.2e1*_t195;
  const double _t404 = 0.2e1*_t196;
  const double _t405 = -_hc1[0]*_t401 + (0.105e3 / 0.8e1)*_t369 + (0.315e3 / 0.8e1)*_t370 - 0.315e3 / 0.4e1*_t375 + (0.693e3 / 0.8e1)*_t377 - 0.2835e4 / 0.4e1*_t379 + (0.10395e5 / 0.8e1)*_t381 + (0.3465e4 / 0.2e1)*_t384;
  const double _t406 = -0.35e2 / 0.16e2*_t368 + (0.945e3 / 0.8e1)*_t371 + (0.2835e4 / 0.8e1)*_t372 + (0.945e3 / 0.16e2)*_t374 - 0.3465e4 / 0.16e2*_t376 + (0.3003e4 / 0.16e2)*_t378 - 0.10395e5 / 0.4e1*_t380 + (0.27027e5 / 0.8e1)*_t382 - 0.10395e5 / 0.4e1*_t383 + (0.45045e5 / 0.8e1)*_t385;
  const double _t407 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t409 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t410 = _hc1[3]*_t409;
  const double _t414 = _hc1[0]*_t410;
  const double _t415 = _t311*_t409;
  const double _t418 = _t313*_t409;
  const double _t422 = _hc1[0]*_t415;
  const double _t429 = _hc1[0]*_t418;
  const double _t430 = _t410*_t5;
  const double _t431 = _t410*_t6;
  const double _t432 = _t410*_t7;
  const double _t433 = _t410*_t8;
  const double _t434 = _t410*_t9;
  const double _t439 = _t415*_t5;
  const double _t440 = _t415*_t6;
  const double _t441 = _t415*_t7;
  const double _t442 = _t415*_t8;
  const double _t446 = _t418*_t5;
  const double _t447 = _t418*_t6;
  const double _t448 = _t418*_t7;
  const double _t451 = 0.00020524381643483745*_t85;
  const double _t453 = 3.9156152961095439e-5*_t86;
  const double _t454 = 0.3e1*_t414;
  const double _t455 = 0.9e1*_t415;
  const double _t471 = 1.3547712039811658e-5*_t102;
  const double _t474 = 4.9695206811589548e-6*_t103;
  const double _t481 = 0.3e1*_t198;
  const double _t483 = 0.9e1*_t199;
  const double _t485 = 1.3254323669570616e-6*_t107;
  const double _t486 = 0.9e1*_t200;
  const double _t488 = 1.4138834233816784e-5*_t109;
  const double _t492 = -0.3e1 / 0.2e1*_t410 + 0.15e2*_t418 + 0.45e2*_t422 + (0.15e2 / 0.2e1)*_t430;
  const double _t495 = 2.9592221473817311e-6*_t117;
  const double _t496 = 0.3e1*_t85;
  const double _t498 = 0.9e1*_t86;
  const double _t505 = -0.15e2 / 0.2e1*_t414 - 0.45e2 / 0.2e1*_t415 + 0.105e3*_t429 + (0.35e2 / 0.2e1)*_t431 + (0.315e3 / 0.2e1)*_t439;
  const double _t507 = 0.3e1*_t102;
  const double _t508 = 0.3e1*_t103;
  const double _t509 = 0.3e1*_t253;
  const double _t515 = 0.3e1*_t107;
  const double _t517 = 0.3e1*_t109;
  const double _t521 = 0.3e1*_t267;
  const double _t523 = 0.3e1*_t117;
  const double _t525 = (0.945e3 / 0.2e1)*_t418;
  const double _t526 = (0.15e2 / 0.8e1)*_t410 - 0.105e3 / 0.2e1*_t418 - 0.315e3 / 0.2e1*_t422 - 0.105e3 / 0.4e1*_t430 + (0.315e3 / 0.8e1)*_t432 + (0.945e3 / 0.2e1)*_t440 + _t5*_t525;
  const double _t530 = 0.3e1*_t273;
  const double _t537 = -_hc1[0]*_t525 + (0.105e3 / 0.8e1)*_t414 + (0.315e3 / 0.8e1)*_t415 - 0.315e3 / 0.4e1*_t431 + (0.693e3 / 0.8e1)*_t433 - 0.2835e4 / 0.4e1*_t439 + (0.10395e5 / 0.8e1)*_t441 + (0.3465e4 / 0.2e1)*_t447;
  const double _t542 = 0.3e1*_t281;
  const double _t546 = 0.3e1*_t288;
  const double _t549 = -0.35e2 / 0.16e2*_t410 + (0.945e3 / 0.8e1)*_t418 + (0.2835e4 / 0.8e1)*_t422 + (0.945e3 / 0.16e2)*_t430 - 0.3465e4 / 0.16e2*_t432 + (0.3003e4 / 0.16e2)*_t434 - 0.10395e5 / 0.4e1*_t440 + (0.27027e5 / 0.8e1)*_t442 - 0.10395e5 / 0.4e1*_t446 + (0.45045e5 / 0.8e1)*_t448;
#endif
#if _KMAX >= 4
  const double _t556 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t557 = _hc1[4]*_t556;
  const double _t558 = _hc1[0]*_t557;
  const double _t559 = _hc1[1]*_hc1[3];
  const double _t560 = _t556*_t559;
  const double _t561 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t562 = _t556*_t561;
  const double _t563 = ((_hc1[2]) * (_hc1[2]));
  const double _t564 = _t556*_t563;
  const double _t565 = _hc1[0]*_t560;
  const double _t567 = _hc1[0]*_t562;
  const double _t568 = _hc1[0]*_t564;
  const double _t569 = _t5*_t557;
  const double _t570 = _t557*_t6;
  const double _t571 = _t557*_t7;
  const double _t572 = _t557*_t8;
  const double _t573 = _t557*_t9;
  const double _t574 = _hc1[2]*_t155;
  const double _t575 = _t556*_t574;
  const double _t576 = _hc1[0]*_t575;
  const double _t577 = _t5*_t560;
  const double _t578 = _t560*_t6;
  const double _t579 = _t560*_t7;
  const double _t580 = _t560*_t8;
  const double _t581 = 1.5891319433288769*_t5;
  const double _t582 = _t5*_t564;
  const double _t583 = _t562*_t6;
  const double _t584 = _t564*_t6;
  const double _t585 = _t564*_t7;
  const double _t586 = _t564*_t8;
  const double _t587 = _t5*_t575;
  const double _t588 = _t575*_t6;
  const double _t589 = _t575*_t7;
  const double _t590 = 0.3e1*_t558;
  const double _t591 = 0.12e2*_t560;
  const double _t592 = 0.9e1*_t564;
  const double _t593 = -0.3e1 / 0.2e1*_t557 + 0.60e2*_t565 + 0.45e2*_t568 + (0.15e2 / 0.2e1)*_t569 + 0.90e2*_t575;
  const double _t594 = -0.15e2 / 0.2e1*_t558 - 0.30e2*_t560 + 0.105e3*_t562 - 0.45e2 / 0.2e1*_t564 + (0.35e2 / 0.2e1)*_t570 + 0.630e3*_t576 + 0.210e3*_t577 + (0.315e3 / 0.2e1)*_t582;
  const double _t595 = 0.2835e4*_t575;
  const double _t596 = _t5*_t595 + (0.15e2 / 0.8e1)*_t557 - 0.210e3*_t565 + 0.945e3*_t567 - 0.315e3 / 0.2e1*_t568 - 0.105e3 / 0.4e1*_t569 + (0.315e3 / 0.8e1)*_t571 - 0.315e3*_t575 + 0.630e3*_t578 + (0.945e3 / 0.2e1)*_t584;
  const double _t597 = (0.10395e5 / 0.2e1)*_t562;
  const double _t598 = -_hc1[0]*_t595 + _t5*_t597 + (0.105e3 / 0.8e1)*_t558 + (0.105e3 / 0.2e1)*_t560 - 0.945e3 / 0.2e1*_t562 + (0.315e3 / 0.8e1)*_t564 - 0.315e3 / 0.4e1*_t570 + (0.693e3 / 0.8e1)*_t572 - 0.945e3*_t577 + (0.3465e4 / 0.2e1)*_t579 - 0.2835e4 / 0.4e1*_t582 + (0.10395e5 / 0.8e1)*_t585 + 0.10395e5*_t588;
  const double _t599 = -_hc1[0]*_t597 - 0.35e2 / 0.16e2*_t557 + (0.945e3 / 0.2e1)*_t565 + (0.2835e4 / 0.8e1)*_t568 + (0.945e3 / 0.16e2)*_t569 - 0.3465e4 / 0.16e2*_t571 + (0.3003e4 / 0.16e2)*_t573 + (0.2835e4 / 0.4e1)*_t575 - 0.3465e4*_t578 + (0.9009e4 / 0.2e1)*_t580 + (0.45045e5 / 0.2e1)*_t583 - 0.10395e5 / 0.4e1*_t584 + (0.27027e5 / 0.8e1)*_t586 - 0.31185e5 / 0.2e1*_t587 + (0.135135e6 / 0.4e1)*_t589;
  const double _t600 = _hc0[2]*_t308;
  const double _t601 = _hc1[4]*_t600;
  const double _t602 = _hc1[0]*_t601;
  const double _t603 = _t309*_t85;
  const double _t604 = _t561*_t600;
  const double _t605 = _t563*_t600;
  const double _t606 = _t309*_t86;
  const double _t607 = _hc1[0]*_t604;
  const double _t608 = _hc1[0]*_t605;
  const double _t609 = _t5*_t601;
  const double _t610 = _t6*_t601;
  const double _t611 = _t601*_t7;
  const double _t612 = _t601*_t8;
  const double _t613 = _t601*_t9;
  const double _t614 = _t574*_t600;
  const double _t615 = _hc1[0]*_t614;
  const double _t616 = _t309*_t87;
  const double _t617 = _t309*_t88;
  const double _t618 = _t309*_t89;
  const double _t619 = _t309*_t90;
  const double _t620 = _t5*_t605;
  const double _t621 = _t6*_t604;
  const double _t622 = _t6*_t605;
  const double _t623 = _t605*_t7;
  const double _t624 = _t605*_t8;
  const double _t625 = _t5*_t614;
  const double _t626 = _t6*_t614;
  const double _t627 = _t614*_t7;
  const double _t628 = 0.3e1*_t602;
  const double _t629 = 0.12e2*_t603;
  const double _t630 = 0.9e1*_t605;
  const double _t631 = (0.3e1 / 0.2e1)*_hc1[4];
  const double _t632 = -_t600*_t631 + 0.60e2*_t606 + 0.45e2*_t608 + (0.15e2 / 0.2e1)*_t609 + 0.90e2*_t614;
  const double _t633 = -0.15e2 / 0.2e1*_t602 - 0.30e2*_t603 + 0.105e3*_t604 - 0.45e2 / 0.2e1*_t605 + (0.35e2 / 0.2e1)*_t610 + 0.630e3*_t615 + 0.210e3*_t616 + (0.315e3 / 0.2e1)*_t620;
  const double _t634 = _hc0[2]*_t336;
  const double _t635 = 0.2835e4*_t614;
  const double _t636 = _hc1[4]*_t634*_t7 + _t5*_t635 + (0.15e2 / 0.8e1)*_t601 - 0.210e3*_t606 + 0.945e3*_t607 - 0.315e3 / 0.2e1*_t608 - 0.105e3 / 0.4e1*_t609 - 0.315e3*_t614 + 0.630e3*_t617 + (0.945e3 / 0.2e1)*_t622;
  const double _t637 = (0.10395e5 / 0.2e1)*_t604;
  const double _t638 = -_hc1[0]*_t635 + _t5*_t637 + _t563*_t634 + (0.105e3 / 0.8e1)*_t602 + (0.105e3 / 0.2e1)*_t603 - 0.945e3 / 0.2e1*_t604 - 0.315e3 / 0.4e1*_t610 + (0.693e3 / 0.8e1)*_t612 - 0.945e3*_t616 + (0.3465e4 / 0.2e1)*_t618 - 0.2835e4 / 0.4e1*_t620 + (0.10395e5 / 0.8e1)*_t623 + 0.10395e5*_t626;
  const double _t639 = -_hc1[0]*_t637 - 0.35e2 / 0.16e2*_t601 + (0.945e3 / 0.2e1)*_t606 + (0.2835e4 / 0.8e1)*_t608 + (0.945e3 / 0.16e2)*_t609 - 0.3465e4 / 0.16e2*_t611 + (0.3003e4 / 0.16e2)*_t613 + (0.2835e4 / 0.4e1)*_t614 - 0.3465e4*_t617 + (0.9009e4 / 0.2e1)*_t619 + (0.45045e5 / 0.2e1)*_t621 - 0.10395e5 / 0.4e1*_t622 + (0.27027e5 / 0.8e1)*_t624 - 0.31185e5 / 0.2e1*_t625 + (0.135135e6 / 0.4e1)*_t627;
  const double _t640 = _t152*_t197;
  const double _t641 = _hc1[4]*_t640;
  const double _t642 = _hc1[0]*_t641;
  const double _t643 = _t559*_t640;
  const double _t644 = _t561*_t640;
  const double _t645 = _t563*_t640;
  const double _t646 = _hc1[0]*_t643;
  const double _t647 = _hc1[0]*_t644;
  const double _t648 = _hc1[0]*_t645;
  const double _t649 = _t5*_t641;
  const double _t650 = _t6*_t641;
  const double _t651 = _t641*_t7;
  const double _t652 = _t641*_t8;
  const double _t653 = _t641*_t9;
  const double _t654 = _t153*_t200;
  const double _t655 = _t154*_t200;
  const double _t656 = _t5*_t643;
  const double _t657 = _t6*_t643;
  const double _t658 = _t643*_t7;
  const double _t659 = _t643*_t8;
  const double _t660 = _t5*_t645;
  const double _t661 = _t6*_t644;
  const double _t662 = _t6*_t645;
  const double _t663 = _t645*_t7;
  const double _t664 = _t645*_t8;
  const double _t665 = _t158*_t200;
  const double _t666 = _t159*_t200;
  const double _t667 = _t160*_t200;
  const double _t668 = 0.3e1*_t642;
  const double _t669 = 0.12e2*_t643;
  const double _t670 = 0.9e1*_t645;
  const double _t671 = 0.2e1*_t340;
  const double _t672 = 0.6e1*_t341;
  const double _t673 = 0.18e2*_t342;
  const double _t674 = 0.2e1*_t361;
  const double _t675 = -_t631*_t640 + 0.60e2*_t646 + 0.45e2*_t648 + (0.15e2 / 0.2e1)*_t649 + 0.90e2*_t654;
  const double _t676 = 0.2e1*_t362;
  const double _t677 = 0.2e1*_t364;
  const double _t678 = -0.15e2 / 0.2e1*_t642 - 0.30e2*_t643 + 0.105e3*_t644 - 0.45e2 / 0.2e1*_t645 + (0.35e2 / 0.2e1)*_t650 + 0.630e3*_t655 + 0.210e3*_t656 + (0.315e3 / 0.2e1)*_t660;
  const double _t679 = 0.2e1*_t365;
  const double _t680 = 0.2e1*_t366;
  const double _t681 = 0.2835e4*_t200;
  const double _t682 = _t158*_t681 + (0.15e2 / 0.8e1)*_t641 - 0.210e3*_t646 + 0.945e3*_t647 - 0.315e3 / 0.2e1*_t648 - 0.105e3 / 0.4e1*_t649 + (0.315e3 / 0.8e1)*_t651 - 0.315e3*_t654 + 0.630e3*_t657 + (0.945e3 / 0.2e1)*_t662;
  const double _t683 = (0.10395e5 / 0.2e1)*_t644;
  const double _t684 = -_t154*_t681 + _t5*_t683 + (0.105e3 / 0.8e1)*_t642 + (0.105e3 / 0.2e1)*_t643 - 0.945e3 / 0.2e1*_t644 + (0.315e3 / 0.8e1)*_t645 - 0.315e3 / 0.4e1*_t650 + (0.693e3 / 0.8e1)*_t652 - 0.945e3*_t656 + (0.3465e4 / 0.2e1)*_t658 - 0.2835e4 / 0.4e1*_t660 + (0.10395e5 / 0.8e1)*_t663 + 0.10395e5*_t666;
  const double _t685 = -_hc1[0]*_t683 - 0.35e2 / 0.16e2*_t641 + (0.945e3 / 0.2e1)*_t646 + (0.2835e4 / 0.8e1)*_t648 + (0.945e3 / 0.16e2)*_t649 - 0.3465e4 / 0.16e2*_t651 + (0.3003e4 / 0.16e2)*_t653 + (0.2835e4 / 0.4e1)*_t654 - 0.3465e4*_t657 + (0.9009e4 / 0.2e1)*_t659 + (0.45045e5 / 0.2e1)*_t661 - 0.10395e5 / 0.4e1*_t662 + (0.27027e5 / 0.8e1)*_t664 - 0.31185e5 / 0.2e1*_t665 + (0.135135e6 / 0.4e1)*_t667;
  const double _t686 = _hc0[1]*_t409;
  const double _t687 = _hc1[4]*_t686;
  const double _t688 = _hc1[0]*_t687;
  const double _t689 = _t410*_t71;
  const double _t690 = _t561*_t686;
  const double _t691 = _t563*_t686;
  const double _t692 = _t410*_t72;
  const double _t693 = _hc1[0]*_t690;
  const double _t694 = _hc1[0]*_t691;
  const double _t695 = _t5*_t687;
  const double _t696 = _t6*_t687;
  const double _t697 = _t687*_t7;
  const double _t698 = _t687*_t8;
  const double _t699 = _t687*_t9;
  const double _t700 = _t574*_t686;
  const double _t701 = _hc1[0]*_t700;
  const double _t702 = _t410*_t74;
  const double _t703 = _t410*_t75;
  const double _t704 = _t410*_t76;
  const double _t705 = _t410*_t77;
  const double _t706 = _t5*_t691;
  const double _t707 = _t6*_t690;
  const double _t708 = _t6*_t691;
  const double _t709 = _t691*_t7;
  const double _t710 = _t691*_t8;
  const double _t711 = _t5*_t700;
  const double _t712 = _t6*_t700;
  const double _t713 = _t7*_t700;
  const double _t714 = 0.00020524381643483745*_t175;
  const double _t716 = 0.3e1*_t688;
  const double _t717 = 0.12e2*_t689;
  const double _t718 = 0.9e1*_t691;
  const double _t719 = 0.3e1*_t368;
  const double _t720 = 0.9e1*_t369;
  const double _t721 = 0.27e2*_t370;
  const double _t722 = 0.3e1*_t175;
  const double _t723 = 0.9e1*_t176;
  const double _t724 = 0.9e1*_t177;
  const double _t725 = -_t631*_t686 + 0.60e2*_t692 + 0.45e2*_t694 + (0.15e2 / 0.2e1)*_t695 + 0.90e2*_t700;
  const double _t726 = 0.3e1*_t192;
  const double _t727 = 0.3e1*_t396;
  const double _t728 = 0.3e1*_t193;
  const double _t729 = 0.3e1*_t398;
  const double _t730 = 0.3e1*_t194;
  const double _t731 = -0.15e2 / 0.2e1*_t688 - 0.30e2*_t689 + 0.105e3*_t690 - 0.45e2 / 0.2e1*_t691 + (0.35e2 / 0.2e1)*_t696 + 0.630e3*_t701 + 0.210e3*_t702 + (0.315e3 / 0.2e1)*_t706;
  const double _t732 = 0.3e1*_t195;
  const double _t733 = 0.3e1*_t402;
  const double _t734 = 0.3e1*_t196;
  const double _t735 = 0.3e1*_t405;
  const double _t736 = 0.2835e4*_t700;
  const double _t737 = _t5*_t736 + (0.15e2 / 0.8e1)*_t687 - 0.210e3*_t692 + 0.945e3*_t693 - 0.315e3 / 0.2e1*_t694 - 0.105e3 / 0.4e1*_t695 + (0.315e3 / 0.8e1)*_t697 - 0.315e3*_t700 + 0.630e3*_t703 + (0.945e3 / 0.2e1)*_t708;
  const double _t738 = 0.3e1*_t406;
  const double _t739 = (0.10395e5 / 0.2e1)*_t690;
  const double _t740 = -_hc1[0]*_t736 + _t5*_t739 + (0.105e3 / 0.8e1)*_t688 + (0.105e3 / 0.2e1)*_t689 - 0.945e3 / 0.2e1*_t690 + (0.315e3 / 0.8e1)*_t691 - 0.315e3 / 0.4e1*_t696 + (0.693e3 / 0.8e1)*_t698 - 0.945e3*_t702 + (0.3465e4 / 0.2e1)*_t704 - 0.2835e4 / 0.4e1*_t706 + (0.10395e5 / 0.8e1)*_t709 + 0.10395e5*_t712;
  const double _t741 = -_hc1[0]*_t739 - 0.35e2 / 0.16e2*_t687 + (0.945e3 / 0.2e1)*_t692 + (0.2835e4 / 0.8e1)*_t694 + (0.945e3 / 0.16e2)*_t695 - 0.3465e4 / 0.16e2*_t697 + (0.3003e4 / 0.16e2)*_t699 + (0.2835e4 / 0.4e1)*_t700 - 0.3465e4*_t703 + (0.9009e4 / 0.2e1)*_t705 + (0.45045e5 / 0.2e1)*_t707 - 0.10395e5 / 0.4e1*_t708 + (0.27027e5 / 0.8e1)*_t710 - 0.31185e5 / 0.2e1*_t711 + (0.135135e6 / 0.4e1)*_t713;
  const double _t742 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t743 = _hc1[4]*_t742;
  const double _t744 = _hc1[0]*_t743;
  const double _t745 = _t559*_t742;
  const double _t746 = _t561*_t742;
  const double _t747 = _t563*_t742;
  const double _t748 = _hc1[0]*_t745;
  const double _t749 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t750 = _t1*_t749;
  const double _t752 = _hc1[0]*_t746;
  const double _t753 = _hc1[0]*_t747;
  const double _t754 = _t5*_t743;
  const double _t755 = _t6*_t743;
  const double _t756 = _t7*_t743;
  const double _t757 = _t743*_t8;
  const double _t758 = _t743*_t9;
  const double _t759 = _t574*_t742;
  const double _t762 = _hc1[0]*_t759;
  const double _t763 = _t5*_t745;
  const double _t764 = _t6*_t745;
  const double _t765 = _t7*_t745;
  const double _t766 = _t745*_t8;
  const double _t771 = _t5*_t747;
  const double _t772 = _t6*_t746;
  const double _t773 = _t6*_t747;
  const double _t774 = _t7*_t747;
  const double _t775 = _t747*_t8;
  const double _t785 = _t5*_t759;
  const double _t786 = _t6*_t759;
  const double _t787 = _t7*_t759;
  const double _t793 = 0.3e1*_t744;
  const double _t794 = 0.12e2*_t745;
  const double _t802 = 0.00041048763286967491*_t198;
  const double _t803 = 0.9e1*_t747;
  const double _t809 = 0.4e1*_t410;
  const double _t810 = 0.12e2*_t414;
  const double _t811 = 0.36e2*_t415;
  const double _t812 = 0.4e1*_t85;
  const double _t813 = 2.7095424079623316e-5*_t253;
  const double _t814 = 0.12e2*_t86;
  const double _t815 = 0.6e1*_t198;
  const double _t816 = 0.18e2*_t199;
  const double _t817 = 0.18e2*_t200;
  const double _t818 = 0.4e1*_t102;
  const double _t819 = -0.3e1 / 0.2e1*_t743 + 0.60e2*_t748 + 0.45e2*_t753 + (0.15e2 / 0.2e1)*_t754 + 0.90e2*_t759;
  const double _t820 = 0.4e1*_t103;
  const double _t821 = 9.9390413623179096e-6*_t267;
  const double _t822 = 0.4e1*_t107;
  const double _t823 = 0.4e1*_t109;
  const double _t824 = 2.6508647339141231e-6*_t273;
  const double _t825 = 0.4e1*_t492;
  const double _t826 = 0.4e1*_t117;
  const double _t827 = 0.6e1*_t253;
  const double _t828 = 2.8277668467633569e-5*_t281;
  const double _t829 = 0.4e1*_t505;
  const double _t830 = 0.6e1*_t267;
  const double _t831 = -0.15e2 / 0.2e1*_t744 - 0.30e2*_t745 + 0.105e3*_t746 - 0.45e2 / 0.2e1*_t747 + (0.35e2 / 0.2e1)*_t755 + 0.630e3*_t762 + 0.210e3*_t763 + (0.315e3 / 0.2e1)*_t771;
  const double _t832 = 5.9184442947634622e-6*_t288;
  const double _t833 = 0.6e1*_t273;
  const double _t834 = 0.4e1*_t526;
  const double _t835 = 0.6e1*_t281;
  const double _t836 = 0.2835e4*_t759;
  const double _t837 = _t5*_t836 + (0.15e2 / 0.8e1)*_t743 - 0.210e3*_t748 + 0.945e3*_t752 - 0.315e3 / 0.2e1*_t753 - 0.105e3 / 0.4e1*_t754 + (0.315e3 / 0.8e1)*_t756 - 0.315e3*_t759 + 0.630e3*_t764 + (0.945e3 / 0.2e1)*_t773;
  const double _t838 = 0.4e1*_t537;
  const double _t839 = 0.6e1*_t288;
  const double _t840 = 0.4e1*_t549;
  const double _t841 = (0.10395e5 / 0.2e1)*_t746;
  const double _t842 = -_hc1[0]*_t836 + _t5*_t841 + (0.105e3 / 0.8e1)*_t744 + (0.105e3 / 0.2e1)*_t745 - 0.945e3 / 0.2e1*_t746 + (0.315e3 / 0.8e1)*_t747 - 0.315e3 / 0.4e1*_t755 + (0.693e3 / 0.8e1)*_t757 - 0.945e3*_t763 + (0.3465e4 / 0.2e1)*_t765 - 0.2835e4 / 0.4e1*_t771 + (0.10395e5 / 0.8e1)*_t774 + 0.10395e5*_t786;
  const double _t843 = -_hc1[0]*_t841 - 0.35e2 / 0.16e2*_t743 + (0.945e3 / 0.2e1)*_t748 + (0.2835e4 / 0.8e1)*_t753 + (0.945e3 / 0.16e2)*_t754 - 0.3465e4 / 0.16e2*_t756 + (0.3003e4 / 0.16e2)*_t758 + (0.2835e4 / 0.4e1)*_t759 - 0.3465e4*_t764 + (0.9009e4 / 0.2e1)*_t766 + (0.45045e5 / 0.2e1)*_t772 - 0.10395e5 / 0.4e1*_t773 + (0.27027e5 / 0.8e1)*_t775 - 0.31185e5 / 0.2e1*_t785 + (0.135135e6 / 0.4e1)*_t787;
#endif
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(mbeef_xi_k, _KMAX)(p, (0.1e1 / 0.24e2)*_t3*x2, _hc2);
  const double _t4 = 0.12131628073942294*_hc2[0];
  const double _t11 = ((_hc2[0]) * (_hc2[0]));
  const double _t12 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t13 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t14 = xc_powi((_hc2[0]), 5);
  const double _t15 = xc_powi((_hc2[0]), 6);
  const double _t16 = xc_powi((_hc2[0]), 7);
  const double _t17 = 0.0065678021259147985 - 0.019703406377744395*_t11;
  const double _t19 = _hc2[0]*_t18;
  const double _t20 = 0.025235144319018442*_hc2[0] - 0.042058573865030738*_t12;
  const double _t22 = 0.0024977311122498513*_hc2[0];
  const double _t23 = 0.0079128338448365423*_t11 - 0.0092316394856426326*_t13 - 0.00079128338448365422;
  const double _t24 = 0.00041766563158501802 - 0.001252996894755054*_t11;
  const double _t25 = -0.0031142355927808562*_hc2[0] + 0.014533099432977329*_t12 - 0.013079789489679596*_t14;
  const double _t27 = 0.0050995906979556666*_hc2[0];
  const double _t28 = 0.00043352678527397305 - 0.0013005803558219191*_t11;
  const double _t29 = 0.00011735382208523729*_hc2[0] - 0.00019558970347539548*_t12;
  const double _t31 = 0.0016437722411542371*_hc2[0];
  const double _t32 = 0.018510737975512792*_t11 - 0.055532213926538377*_t13 + 0.040723623546128143*_t15 - 0.00088146371311965678;
  const double _t33 = -0.0041733096479344179*_hc2[0] + 0.0069555160798906965*_t12;
  const double _t34 = 0.0055795050644137211*_t11 - 0.0065094225751493413*_t13 - 0.00055795050644137211;
  const double _t35 = -0.00037864817792516461*_hc2[0] + 0.0034078336013264815*_t12 - 0.0074972339229182593*_t14 + 0.0046411448094255891*_t16;
  const double _t36 = 0.00047707398539125966*_t11 - 0.00015902466179708655;
  const double _t38 = 0.0005970286163074767*_hc2[0];
  const double _t39 = 0.0094911094708101469*_hc2[0] - 0.044291844197114019*_t12 + 0.039862659777402617*_t14;
  const double _t40 = 0.00096423059828501737*_t11 - 0.0011249356979991869*_t13 - 9.6423059828501736e-5;
  const double _t41 = 0.00012724150722787791*_t11 - 4.241383574262597e-5;
  const double _t42 = 0.007056654498421314*_hc2[0] - 0.01176109083070219*_t12;
  const double _t44 = 0.0023160016166370034*_hc2[0];
  const double _t45 = -6.8550226578722701e-5*_hc2[0] + 0.0003199010573673726*_t12 - 0.00028791095163063534*_t14;
  const double _t46 = -0.050082411905177027*_t11 + 0.15024723571553108*_t13 - 0.11018130619138946*_t15 + 0.0023848767573893822;
  const double _t47 = 0.00029063821948419402*_hc2[0] - 0.0004843970324736567*_t12;
  const double _t48 = -0.0037092583991169622*_t11 + 0.0043274681323031226*_t13 + 0.00037092583991169622;
  const double _t49 = 0.0004524426954821371 - 0.0013573280864464113*_t11;
  const double _t50 = 0.022023100661753209*_hc2[0] - 0.19820790595577888*_t12 + 0.43605739310271355*_t14 - 0.26994029096834648*_t16;
  const double _t51 = -0.060346884138922015*_t11 + 0.18104065241676605*_t13 - 0.13276314510562843*_t15 + 0.0028736611494724769;
  const double _t52 = -0.0019217178983580926*_hc2[0] + 0.0089680168590044322*_t12 - 0.008071215173103989*_t14;
  const double _t53 = 0.00027229148830605109*_t11 - 0.00031767340302372627*_t13 - 2.7229148830605109e-5;
  const double _t54 = 0.00028408532614864619*_t11 - 9.4695108716215395e-5;
  const double _t55 = 0.0010345430913659415*_hc2[0] - 0.0017242384856099024*_t12;
  const double _t56 = -0.023463736563284666*_hc2[0] + 0.211173629069562*_t12 - 0.46458198395303639*_t14 + 0.28759837101854634*_t16;
  const double _t57 = -0.0072265309231031387*_hc2[0] + 0.033723810974481314*_t12 - 0.030351429877033182*_t14;
  const double _t58 = -0.00064628489004133276*_hc2[0] + 0.0010771414834022213*_t12;
  const double _t59 = 0.0054908919820669845*_t11 - 0.016472675946200954*_t13 + 0.012079962360547366*_t15 - 0.0002614710467650945;
  const double _t60 = -0.00049942400989450275*_t11 + 0.00058266134487691988*_t13 + 4.9942400989450275e-5;
  const double _t61 = 0.00068663611972714207*_hc2[0] - 0.0061797250775442786*_t12 + 0.013595395170597413*_t14 - 0.0084161970103698271*_t16;
  const double _t62 = -0.020538352349837296*_t11 + 0.061615057049511887*_t13 - 0.045184375169642051*_t15 + 0.00097801677856368075;
  const double _t63 = 6.722614891607745e-5*_t11 - 7.8430507068757025e-5*_t13 - 6.722614891607745e-6;
  const double _t64 = -0.014166480912371666*_hc2[0] + 0.066110244257734442*_t12 - 0.059499219831960998*_t14;
  const double _t65 = -0.0084785158963974842*_hc2[0] + 0.076306643067577358*_t12 - 0.16787461474867019*_t14 + 0.10392238055870059*_t16;
  const double _t66 = -0.00097388600047288237*_hc2[0] + 0.0045448013355401177*_t12 - 0.004090321201986106*_t14;
  const double _t67 = 0.012234580488066425*_t11 - 0.036703741464199274*_t13 + 0.026916077073746134*_t15 - 0.00058259907086030594;
  const double _t68 = 0.00041770618692391807*_hc2[0] - 0.0037593556823152626*_t12 + 0.0082705825010935778*_t14 - 0.0051198844054388815*_t16;
  const double _t69 = -0.0011915181082004501*_t11 + 0.0035745543246013504*_t13 - 0.0026213398380409903*_t15 + 5.6738957533354769e-5;
  const double _t70 = 0.00064479854637887903*_hc2[0] - 0.0058031869174099112*_t12 + 0.012767011218301805*_t14 - 0.0079033878970439743*_t16;
#if _KMAX >= 1
  const double _t73 = 0.0037023943917136176*_hc2[0];
  const double _t92 = _hc2[1]*_t3;
  const double _t93 = 0.0050548450308092892*_t92;
  const double _t94 = _hc2[0]*_t92;
  const double _t95 = 0.0016419505314786996*_t94;
  const double _t97 = _t11*_t92;
  const double _t98 = _t12*_t92;
  const double _t99 = _t13*_t92;
  const double _t100 = _t14*_t92;
  const double _t101 = _t15*_t92;
  const double _t104 = 0.00010407212967707714*_t92;
  const double _t105 = 0.00010838169631849326*_t94;
  const double _t106 = 0.00021248294574815278*_t92;
  const double _t108 = 3.9756165449271639e-5*_t94;
  const double _t110 = 6.8490510048093213e-5*_t92;
  const double _t111 = 0.0010514643466257684*_hc2[1]*_t1*_t2 - 0.0052573217331288422*_t97;
  const double _t112 = 1.0603458935656492e-5*_t94;
  const double _t113 = 0.00065940282040304519*_hc2[0]*_hc2[1]*_t1*_t2 - 0.0015386065809404388*_t98;
  const double _t114 = 2.4876192346144862e-5*_t92;
  const double _t115 = 0.00011311067387053428*_t94;
  const double _t116 = 9.6500067359875142e-5*_t92;
  const double _t118 = 2.3673777179053849e-5*_t94;
  const double _t119 = 4.8897425868848869e-6*_hc2[1]*_t1*_t2 - 2.4448712934424435e-5*_t97;
  const double _t120 = 0.00046495875536781009*_hc2[0]*_hc2[1]*_t1*_t2 - 0.0010849037625248902*_t98;
  const double _t121 = -0.00017388790199726741*_t92 + 0.00086943950998633706*_t97;
  const double _t122 = 8.0352549857084781e-5*_hc2[0]*_hc2[1]*_t1*_t2 - 0.00018748928299986449*_t98;
  const double _t123 = 0.00029402727076755475*_hc2[1]*_t1*_t2 - 0.0014701363538377737*_t97;
  const double _t124 = 0.0018166374291221661*_hc2[1]*_t1*_t11*_t2 - 0.00012975981636586901*_t92 - 0.0027249561436832492*_t99;
  const double _t125 = -0.00030910486659308019*_t94 + 0.0007212446887171871*_t98;
  const double _t126 = 0.010180905886532036*_t100 + 0.0015425614979593994*_t94 - 0.0092553689877563962*_t98;
  const double _t127 = 1.2109925811841418e-5*_hc2[1]*_t1*_t2 - 6.0549629059207088e-5*_t97;
  const double _t128 = 2.2690957358837591e-5*_hc2[0]*_hc2[1]*_t1*_t2 - 5.2945567170621045e-5*_t98;
  const double _t129 = 4.3105962140247561e-5*_hc2[1]*_t1*_t2 - 0.00021552981070123781*_t97;
  const double _t130 = -4.1618667491208562e-5*_t94 + 9.7110224146153314e-5*_t98;
  const double _t131 = 0.00039546289461708946*_t92 - 0.0055364805246392524*_t97 + 0.0083047207869588785*_t99;
  const double _t132 = -2.6928537085055532e-5*_t92 + 0.00013464268542527766*_t97;
  const double _t133 = 0.025041205952588513*_hc2[1]*_t1*_t12*_t2 - 0.027545326547847364*_t100 - 0.0041735343254314189*_t94;
  const double _t134 = 5.6021790763397875e-6*_hc2[0]*_hc2[1]*_t1*_t2 - 1.3071751178126171e-5*_t98;
  const double _t135 = 3.9987632170921575e-5*_hc2[1]*_t1*_t11*_t2 - 2.8562594407801125e-6*_t92 - 5.9981448256382363e-5*_t99;
  const double _t136 = 0.030173442069461008*_hc2[1]*_t1*_t12*_t2 - 0.033190786276407108*_t100 - 0.0050289070115768346*_t94;
  const double _t137 = 0.001121002107375554*_hc2[1]*_t1*_t11*_t2 - 8.0071579098253859e-5*_t92 - 0.001681503161063331*_t99;
  const double _t138 = 0.0013536672360824635*_t101 - 1.5777007413548526e-5*_t92 + 0.00042597920016581019*_t97 - 0.001561923733941304*_t99;
  const double _t139 = 0.0030199905901368415*_t100 + 0.00045757433183891538*_t94 - 0.0027454459910334923*_t98;
  const double _t140 = 0.0042154763718101642*_hc2[1]*_t1*_t11*_t2 - 0.00030110545512929745*_t92 - 0.0063232145577152463*_t99;
  const double _t141 = 0.010269176174918648*_hc2[1]*_t1*_t12*_t2 - 0.011296093792410513*_t100 - 0.0017115293624864413*_t94;
  const double _t142 = 0.0082637805322168052*_hc2[1]*_t1*_t11*_t2 - 0.0005902700380154861*_t92 - 0.012395670798325208*_t99;
  const double _t143 = 0.0067290192684365336*_t100 + 0.0010195483740055354*_t94 - 0.0061172902440332124*_t98;
  const double _t144 = 0.090845290229731989*_hc2[1]*_t1*_t13*_t2 + 0.00091762919423971706*_hc2[1]*_t1*_t2 - 0.078732584865767723*_t101 - 0.02477598824447236*_t97;
  const double _t145 = 0.00056810016694251472*_hc2[1]*_t1*_t11*_t2 - 4.0578583353036766e-5*_t92 - 0.00085215025041377207*_t99;
  const double _t146 = 0.00059575905410022507*_hc2[1]*_t1*_t12*_t2 - 0.00065533495951024758*_t100 - 9.9293175683370845e-5*_t94;
  const double _t147 = 0.083882858213742682*_t101 - 0.00097765569013686109*_t92 + 0.02639670363369525*_t97 - 0.096787913323549248*_t99;
  const double _t148 = 0.002832373993874461*_hc2[1]*_t1*_t13*_t2 + 2.8609838321964253e-5*_hc2[1]*_t1*_t2 - 0.0024547241280245329*_t101 - 0.00077246563469303483*_t97;
  const double _t149 = 0.030310694329621006*_t101 - 0.00035327149568322851*_t92 + 0.0095383303834471697*_t97 - 0.034973878072639622*_t99;
  const double _t150 = 0.001723038021061162*_hc2[1]*_t1*_t13*_t2 + 1.7404424455163253e-5*_hc2[1]*_t1*_t2 - 0.0014932996182530071*_t101 - 0.00046991946028940783*_t97;
  const double _t151 = 0.002659794003812876*_hc2[1]*_t1*_t13*_t2 + 2.6866606099119959e-5*_hc2[1]*_t1*_t2 - 0.0023051548033044925*_t101 - 0.0007253983646762389*_t97;
#endif
#if _KMAX >= 2
  const double _t188 = 0.0001542664329880674*_t92;
  const double _t190 = 0.00031324922368876351*_t94;
  const double _t204 = _hc2[2]*_t203;
  const double _t211 = 0.00021061854295038705*_t204;
  const double _t212 = _hc2[0]*_t204;
  const double _t213 = ((_hc2[1]) * (_hc2[1]));
  const double _t214 = _t203*_t213;
  const double _t219 = 0.010109690061618578*_t92;
  const double _t221 = _hc2[0]*_t214;
  const double _t222 = _t11*_t204;
  const double _t223 = _t12*_t204;
  const double _t224 = _t13*_t204;
  const double _t225 = _t14*_t204;
  const double _t226 = _t15*_t204;
  const double _t227 = 0.0003085328659761348*_t92;
  const double _t228 = 0.0032839010629573992*_t94;
  const double _t229 = 0.00062649844737752702*_t94;
  const double _t231 = _t11*_t214;
  const double _t232 = _t12*_t214;
  const double _t233 = _t13*_t214;
  const double _t234 = _t14*_t214;
  const double _t236 = 4.3363387365448807e-6*_t204;
  const double _t237 = 4.5159040132705527e-6*_t212;
  const double _t238 = 4.5159040132705527e-6*_t214;
  const double _t239 = 0.00020814425935415428*_t92;
  const double _t240 = 8.853456072839699e-6*_t204;
  const double _t241 = 0.00042496589149630555*_t92;
  const double _t242 = 0.00021676339263698653*_t94;
  const double _t243 = 1.6565068937196516e-6*_t212;
  const double _t244 = 1.6565068937196516e-6*_t214;
  const double _t245 = 2.8537712520038839e-6*_t204;
  const double _t246 = 7.9512330898543277e-5*_t94;
  const double _t247 = 4.4181078898568719e-7*_t212;
  const double _t248 = 4.4181078898568719e-7*_t214;
  const double _t250 = 1.0365080144227026e-6*_t204;
  const double _t252 = 4.7129447446055948e-6*_t212;
  const double _t254 = 0.00013698102009618643*_t92;
  const double _t255 = 4.7129447446055948e-6*_t214;
  const double _t256 = 4.0208361399947976e-6*_t204;
  const double _t257 = 4.9752384692289725e-5*_t92;
  const double _t258 = 2.1206917871312985e-5*_t94;
  const double _t259 = 9.8640738246057703e-7*_t212;
  const double _t260 = 9.8640738246057703e-7*_t214;
  const double _t261 = 0.00022622134774106855*_t94;
  const double _t262 = 4.3811014442740352e-5*_hc2[2]*_t201*_t202 - 0.00043811014442740352*_t221 - 0.00021905507221370176*_t222;
  const double _t263 = 0.00019300013471975028*_t92;
  const double _t265 = 4.7347554358107698e-5*_t94;
  const double _t268 = 2.0373927445353696e-7*_hc2[2]*_t201*_t202 - 2.0373927445353696e-6*_t221 - 1.0186963722676848e-6*_t222;
  const double _t270 = -7.2453292498861422e-6*_t204 + 7.2453292498861422e-5*_t221 + 3.6226646249430711e-5*_t222;
  const double _t272 = 1.2251136281981448e-5*_hc2[2]*_t201*_t202 - 0.00012251136281981448*_t221 - 6.1255681409907239e-5*_t222;
  const double _t274 = 5.0458024216005906e-7*_hc2[2]*_t201*_t202 - 5.0458024216005906e-6*_t221 - 2.5229012108002953e-6*_t222;
  const double _t275 = 2.747511751679355e-5*_hc2[0]*_hc2[2]*_t201*_t202 + 2.747511751679355e-5*_t201*_t202*_t213 - 6.4108607539184949e-5*_t223 - 0.00019232582261755485*_t231;
  const double _t277 = 1.7960817558436482e-6*_hc2[2]*_t201*_t202 - 1.7960817558436482e-5*_t221 - 8.9804087792182408e-6*_t222;
  const double _t278 = -1.1220223785439805e-6*_t204 + 1.1220223785439805e-5*_t221 + 5.6101118927199024e-6*_t222;
  const double _t279 = 1.9373281473658754e-5*_hc2[0]*_hc2[2]*_t201*_t202 + 1.9373281473658754e-5*_t201*_t202*_t213 - 4.5204323438537092e-5*_t223 - 0.00013561297031561128*_t231;
  const double _t280 = 3.3480229107118659e-6*_hc2[0]*_hc2[2]*_t201*_t202 + 3.3480229107118659e-6*_t201*_t202*_t213 - 7.8120534583276871e-6*_t223 - 2.3436160374983061e-5*_t231;
  const double _t282 = -1.2879369441378341e-5*_t212 - 1.2879369441378341e-5*_t214 + 3.0051862029882796e-5*_t223 + 9.0155586089648388e-5*_t231;
  const double _t283 = 0.00015138645242684718*_hc2[0]*_t201*_t202*_t213 + 7.5693226213423588e-5*_hc2[2]*_t11*_t201*_t202 - 5.406659015244542e-6*_t204 - 0.00011353983932013538*_t224 - 0.00045415935728054153*_t232;
  const double _t284 = 9.4545655661823296e-7*_hc2[0]*_hc2[2]*_t201*_t202 + 9.4545655661823296e-7*_t201*_t202*_t213 - 2.2060652987758769e-6*_t223 - 6.6181958963276306e-6*_t231;
  const double _t285 = -1.7341111454670235e-6*_t212 - 1.7341111454670235e-6*_t214 + 4.0462593394230547e-6*_t223 + 1.2138778018269164e-5*_t231;
  const double _t286 = 1.6477620609045394e-5*_t204 - 0.00046137337705327103*_t221 - 0.00023068668852663552*_t222 + 0.00034603003278995327*_t224 + 0.0013841201311598131*_t232;
  const double _t287 = 2.3342412818082448e-7*_hc2[0]*_hc2[2]*_t201*_t202 + 2.3342412818082448e-7*_t201*_t202*_t213 - 5.4465629908859046e-7*_t223 - 1.6339688972657714e-6*_t231;
  const double _t289 = 3.3323026809101313e-6*_hc2[0]*_t201*_t202*_t213 + 1.6661513404550657e-6*_hc2[2]*_t11*_t201*_t202 - 1.1901081003250469e-7*_t204 - 2.4992270106825985e-6*_t224 - 9.9969080427303939e-6*_t232;
  const double _t290 = 9.3416842281296169e-5*_hc2[0]*_t201*_t202*_t213 + 4.6708421140648085e-5*_hc2[2]*_t11*_t201*_t202 - 3.3363157957605775e-6*_t204 - 7.0062631710972127e-5*_t224 - 0.00028025052684388851*_t232;
  const double _t291 = 0.00035128969765084702*_hc2[0]*_t201*_t202*_t213 + 0.00017564484882542351*_hc2[2]*_t11*_t201*_t202 - 1.2546060630387394e-5*_t204 - 0.00026346727323813526*_t224 - 0.0010538690929525411*_t232;
  const double _t292 = 6.4273395748308307e-5*_t212 + 6.4273395748308307e-5*_t214 - 0.00038564037448984984*_t223 + 0.00042420441193883483*_t225 - 0.0011569211234695495*_t231 + 0.0021210220596941741*_t233;
  const double _t293 = 0.00068864837768473377*_hc2[0]*_t201*_t202*_t213 + 0.00034432418884236689*_hc2[2]*_t11*_t201*_t202 - 2.4594584917311921e-5*_t204 - 0.00051648628326355034*_t224 - 0.0020659451330542014*_t232;
  const double _t294 = 4.7341680578542893e-5*_hc2[0]*_t201*_t202*_t213 + 2.3670840289271446e-5*_hc2[2]*_t11*_t201*_t202 - 1.6907743063765319e-6*_t204 - 3.550626043390717e-5*_t224 - 0.00014202504173562868*_t232;
  const double _t295 = 0.0010433835813578547*_hc2[2]*_t12*_t201*_t202 + 0.0031301507440735642*_t11*_t201*_t202*_t213 - 0.00017389726355964246*_t212 - 0.00017389726355964246*_t214 - 0.0011477219394936402*_t225 - 0.0057386096974682009*_t233;
  const double _t296 = 0.0012572267528942087*_hc2[2]*_t12*_t201*_t202 + 0.003771680258682626*_t11*_t201*_t202*_t213 - 0.00020953779214903478*_t212 - 0.00020953779214903478*_t214 - 0.0013829494281836295*_t225 - 0.0069147471409181474*_t233;
  const double _t297 = 1.9065597159954807e-5*_t212 + 1.9065597159954807e-5*_t214 - 0.00011439358295972884*_t223 + 0.00012583294125570173*_t225 - 0.00034318074887918653*_t231 + 0.00062916470627850864*_t233;
  const double _t298 = -6.5737530889785523e-7*_t204 + 3.5498266680484182e-5*_t221 + 1.7749133340242091e-5*_t222 - 6.5080155580887668e-5*_t224 + 5.6402801503435979e-5*_t226 - 0.00026032062232355067*_t232 + 0.00033841680902061587*_t234;
  const double _t299 = 0.00042788234062161033*_hc2[2]*_t12*_t201*_t202 + 0.001283647021864831*_t11*_t201*_t202*_t213 - 7.1313723436935055e-5*_t212 - 7.1313723436935055e-5*_t214 - 0.00047067057468377136*_t225 - 0.0023533528734188568*_t233;
  const double _t300 = 4.2481182250230642e-5*_t212 + 4.2481182250230642e-5*_t214 - 0.00025488709350138386*_t223 + 0.00028037580285152223*_t225 - 0.00076466128050415155*_t231 + 0.0014018790142576112*_t233;
  const double _t301 = 0.0037852204262388329*_hc2[2]*_t13*_t201*_t202 + 3.8234549759988212e-5*_hc2[2]*_t201*_t202 + 0.015140881704955332*_t12*_t201*_t202*_t213 - 0.0020646656870393634*_t221 - 0.0010323328435196817*_t222 - 0.0032805243694069884*_t226 - 0.019683146216441931*_t234;
  const double _t302 = 2.4823293920842711e-5*_hc2[2]*_t12*_t201*_t202 + 7.4469881762528134e-5*_t11*_t201*_t202*_t213 - 4.1372156534737852e-6*_t212 - 4.1372156534737852e-6*_t214 - 2.7305623312926982e-5*_t225 - 0.00013652811656463491*_t233;
  const double _t303 = -4.0735653755702546e-5*_t204 + 0.0021997253028079375*_t221 + 0.0010998626514039687*_t222 - 0.004032829721814552*_t224 + 0.0034951190922392784*_t226 - 0.016131318887258208*_t232 + 0.02097071455343567*_t234;
  const double _t304 = 0.00011801558307810254*_hc2[2]*_t13*_t201*_t202 + 1.1920765967485105e-6*_hc2[2]*_t201*_t202 + 0.00047206233231241017*_t12*_t201*_t202*_t213 - 6.4372136224419569e-5*_t221 - 3.2186068112209784e-5*_t222 - 0.0001022801720010222*_t226 - 0.00061368103200613322*_t234;
  const double _t305 = -1.4719645653467855e-5*_t204 + 0.00079486086528726415*_t221 + 0.00039743043264363207*_t222 - 0.0014572449196933176*_t224 + 0.0012629455970675419*_t226 - 0.0058289796787732704*_t232 + 0.0075776735824052515*_t234;
  const double _t306 = 7.1793250877548418e-5*_hc2[2]*_t13*_t201*_t202 + 7.2518435229846887e-7*_hc2[2]*_t201*_t202 + 0.00028717300351019367*_t12*_t201*_t202*_t213 - 3.9159955024117319e-5*_t221 - 1.9579977512058659e-5*_t222 - 6.2220817427208629e-5*_t226 - 0.00037332490456325177*_t234;
  const double _t307 = 0.00011082475015886983*_hc2[2]*_t13*_t201*_t202 + 1.119441920796665e-6*_hc2[2]*_t201*_t202 + 0.00044329900063547933*_t12*_t201*_t202*_t213 - 6.0449863723019909e-5*_t221 - 3.0224931861509954e-5*_t222 - 9.6048116804353855e-5*_t226 - 0.00057628870082612313*_t234;
#endif
#if _KMAX >= 3
  const double _t316 = 0.011107183175140853*_hc2[0];
  const double _t386 = 6.427768041169475e-6*_t204;
  const double _t387 = 6.8414605478279151e-5*_t212;
  const double _t388 = 6.8414605478279151e-5*_t214;
  const double _t389 = 1.3052050987031813e-5*_t212;
  const double _t390 = 1.3052050987031813e-5*_t214;
  const double _t408 = _hc2[3]*_t407;
  const double _t411 = 5.2654635737596762e-5*_t408;
  const double _t412 = _hc2[0]*_t408;
  const double _t413 = _hc2[1]*_hc2[2]*_t407;
  const double _t416 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t417 = _t407*_t416;
  const double _t419 = 1.7103651369569788e-5*_t412;
  const double _t420 = 5.1310954108709363e-5*_t413;
  const double _t421 = _hc2[0]*_t413;
  const double _t423 = _hc2[0]*_t417;
  const double _t424 = _t11*_t408;
  const double _t425 = _t12*_t408;
  const double _t426 = _t13*_t408;
  const double _t427 = _t14*_t408;
  const double _t428 = _t15*_t408;
  const double _t435 = _t11*_t413;
  const double _t436 = _t12*_t413;
  const double _t437 = _t13*_t413;
  const double _t438 = _t14*_t413;
  const double _t443 = _t11*_t417;
  const double _t444 = _t12*_t417;
  const double _t445 = _t13*_t417;
  const double _t449 = 0.00063185562885116115*_t204;
  const double _t450 = 1.9283304123508425e-5*_t204;
  const double _t452 = 0.015164535092427867*_t92;
  const double _t456 = 0.0004627992989642022*_t92;
  const double _t457 = 0.0049258515944360989*_t94;
  const double _t458 = 3.9156152961095439e-5*_t214;
  const double _t459 = 1.0840846841362202e-6*_t408;
  const double _t460 = 0.00093974767106629054*_t94;
  const double _t461 = 1.1289760033176382e-6*_t412;
  const double _t462 = 3.3869280099529145e-6*_t413;
  const double _t463 = 2.2133640182099247e-6*_t408;
  const double _t464 = 4.1412672342991291e-7*_t412;
  const double _t465 = 1.2423801702897387e-6*_t413;
  const double _t466 = 7.1344281300097096e-7*_t408;
  const double _t467 = 1.3009016209634642e-5*_t204;
  const double _t468 = 1.104526972464218e-7*_t412;
  const double _t469 = 3.3135809173926539e-7*_t413;
  const double _t470 = 2.6560368218519097e-5*_t204;
  const double _t472 = 2.5912700360567565e-7*_t408;
  const double _t473 = 1.3547712039811658e-5*_t214;
  const double _t475 = 4.9695206811589548e-6*_t214;
  const double _t476 = 1.1782361861513987e-6*_t412;
  const double _t477 = 3.5347085584541961e-6*_t413;
  const double _t478 = 1.0052090349986994e-6*_t408;
  const double _t479 = 2.4660184561514426e-7*_t412;
  const double _t480 = 7.3980553684543277e-7*_t413;
  const double _t482 = 8.5613137560116516e-6*_t204;
  const double _t484 = 3.1095240432681079e-6*_t204;
  const double _t487 = 1.3254323669570616e-6*_t214;
  const double _t489 = 1.4138834233816784e-5*_t214;
  const double _t490 = 1.0952753610685088e-5*_hc2[3]*_t407 - 0.00010952753610685088*_t417 - 0.00032858260832055264*_t421 - 5.476376805342544e-5*_t424;
  const double _t491 = 0.00031221638903123141*_t92;
  const double _t493 = 1.2062508419984393e-5*_t204;
  const double _t494 = 0.00032514508895547979*_t94;
  const double _t497 = 2.9592221473817311e-6*_t214;
  const double _t499 = 5.0934818613384239e-8*_hc2[3]*_t407 - 5.0934818613384239e-7*_t417 - 1.5280445584015272e-6*_t421 - 2.546740930669212e-7*_t424;
  const double _t500 = -1.8113323124715355e-6*_t408 + 1.8113323124715355e-5*_t417 + 5.4339969374146066e-5*_t421 + 9.0566615623576777e-6*_t424;
  const double _t501 = 6.8687793791983874e-6*_hc2[0]*_hc2[3]*_t407 + 2.0606338137595162e-5*_hc2[1]*_hc2[2]*_t407 - 9.6162911308777423e-5*_t423 - 1.6027151884796237e-5*_t425 - 0.00014424436696316614*_t435;
  const double _t502 = 3.062784070495362e-6*_hc2[3]*_t407 - 3.062784070495362e-5*_t417 - 9.1883522114860858e-5*_t421 - 1.531392035247681e-5*_t424;
  const double _t503 = 0.00063744883724445832*_t92;
  const double _t504 = 1.2614506054001477e-7*_hc2[3]*_t407 - 1.2614506054001477e-6*_t417 - 3.784351816200443e-6*_t421 - 6.3072530270007383e-7*_t424;
  const double _t506 = 0.00011926849634781492*_t94;
  const double _t510 = 4.4902043896091201e-7*_hc2[3]*_t407 - 4.4902043896091204e-6*_t417 - 1.3470613168827361e-5*_t421 - 2.2451021948045602e-6*_t424;
  const double _t511 = 4.8433203684146885e-6*_hc2[0]*_hc2[3]*_t407 + 1.4529961105244065e-5*_hc2[1]*_hc2[2]*_t407 - 6.7806485157805639e-5*_t423 - 1.1301080859634273e-5*_t425 - 0.00010170972773670846*_t435;
  const double _t512 = -2.8050559463599513e-7*_t408 + 2.8050559463599512e-6*_t417 + 8.4151678390798536e-6*_t421 + 1.4025279731799756e-6*_t424;
  const double _t513 = 8.3700572767796648e-7*_hc2[0]*_hc2[3]*_t407 + 2.5110171830338995e-6*_hc2[1]*_hc2[2]*_t407 - 1.1718080187491531e-5*_t423 - 1.9530133645819218e-6*_t425 - 1.7577120281237296e-5*_t435;
  const double _t514 = -3.2198423603445853e-6*_t412 - 9.6595270810337558e-6*_t413 + 4.5077793044824194e-5*_t423 + 7.512965507470699e-6*_t425 + 6.761668956723629e-5*_t435;
  const double _t516 = 0.00020547153014427964*_t92;
  const double _t518 = 3.1810376806969477e-5*_t94;
  const double _t519 = 2.3636413915455824e-7*_hc2[0]*_hc2[3]*_t407 + 7.0909241746367471e-7*_hc2[1]*_hc2[2]*_t407 - 3.3090979481638153e-6*_t423 - 5.5151632469396922e-7*_t425 - 4.9636469222457229e-6*_t435;
  const double _t520 = -4.3352778636675586e-7*_t412 - 1.3005833591002676e-6*_t413 + 6.0693890091345821e-6*_t423 + 1.0115648348557637e-6*_t425 + 9.1040835137018731e-6*_t435;
  const double _t522 = 0.00011353983932013538*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 1.8923306553355897e-5*_hc2[3]*_t11*_t407 + 3.7846613106711794e-5*_t407*_t416 - 1.3516647538111355e-6*_t408 - 2.8384959830033845e-5*_t426 - 0.00034061951796040615*_t436 - 0.00034061951796040615*_t443;
  const double _t524 = 5.835603204520612e-8*_hc2[0]*_hc2[3]*_t407 + 1.7506809613561836e-7*_hc2[1]*_hc2[2]*_t407 - 8.169844486328857e-7*_t423 - 1.3616407477214762e-7*_t425 - 1.2254766729493285e-6*_t435;
  const double _t527 = 7.4628577038434587e-5*_t92;
  const double _t528 = 0.00033933202161160282*_t94;
  const double _t529 = 4.1194051522613486e-6*_t408 - 0.00011534334426331776*_t417 - 0.00034603003278995328*_t421 - 5.767167213165888e-5*_t424 + 8.6507508197488318e-5*_t426 + 0.0010380900983698598*_t436 + 0.0010380900983698598*_t443;
  const double _t531 = 2.4992270106825985e-6*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 4.1653783511376642e-7*_hc2[3]*_t11*_t407 + 8.3307567022753283e-7*_t407*_t416 - 2.9752702508126173e-8*_t408 - 6.2480675267064963e-7*_t426 - 7.4976810320477956e-6*_t436 - 7.4976810320477953e-6*_t443;
  const double _t532 = 1.6068348937077077e-5*_t412 + 4.820504681123123e-5*_t413 - 0.00057846056173477476*_t423 - 9.6410093622462461e-5*_t425 + 0.00010605110298470871*_t427 - 0.00086769084260216215*_t435 + 0.0015907665447706306*_t437 + 0.0021210220596941741*_t444;
  const double _t533 = 7.0062631710972127e-5*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 1.1677105285162021e-5*_hc2[3]*_t11*_t407 + 2.3354210570324042e-5*_t407*_t416 - 8.3407894894014437e-7*_t408 - 1.7515657927743032e-5*_t426 - 0.00021018789513291638*_t436 - 0.00021018789513291638*_t443;
  const double _t534 = 0.00026346727323813527*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 4.3911212206355878e-5*_hc2[3]*_t11*_t407 + 8.7822424412711755e-5*_t407*_t416 - 3.1365151575968484e-6*_t408 - 6.5866818309533816e-5*_t426 - 0.00079040181971440579*_t436 - 0.00079040181971440579*_t443;
  const double _t535 = 0.00028950020207962543*_t92;
  const double _t536 = 7.1021331537161546e-5*_t94;
  const double _t538 = 0.00051648628326355033*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 8.6081047210591722e-5*_hc2[3]*_t11*_t407 + 0.00017216209442118344*_t407*_t416 - 6.1486462293279803e-6*_t408 - 0.00012912157081588758*_t426 - 0.001549458849790651*_t436 - 0.001549458849790651*_t443;
  const double _t539 = 0.0015650753720367821*_hc2[0]*_t407*_t416 + 0.0023476130580551732*_hc2[1]*_hc2[2]*_t11*_t407 + 0.00026084589533946368*_hc2[3]*_t12*_t407 - 4.3474315889910615e-5*_t412 - 0.00013042294766973184*_t413 - 0.00028693048487341005*_t427 - 0.0043039572731011507*_t437 - 0.0057386096974682009*_t444;
  const double _t540 = 3.550626043390717e-5*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 5.9177100723178616e-6*_hc2[3]*_t11*_t407 + 1.1835420144635723e-5*_t407*_t416 - 4.2269357659413298e-7*_t408 - 8.8765651084767924e-6*_t426 - 0.00010651878130172151*_t436 - 0.00010651878130172151*_t443;
  const double _t541 = 0.001885840129341313*_hc2[0]*_t407*_t416 + 0.0028287601940119695*_hc2[1]*_hc2[2]*_t11*_t407 + 0.00031430668822355217*_hc2[3]*_t12*_t407 - 5.2384448037258695e-5*_t412 - 0.00015715334411177609*_t413 - 0.00034573735704590738*_t427 - 0.0051860603556886107*_t437 - 0.0069147471409181475*_t444;
  const double _t543 = 4.7663992899887018e-6*_t412 + 1.4299197869966105e-5*_t413 - 0.00017159037443959327*_t423 - 2.8598395739932211e-5*_t425 + 3.1458235313925432e-5*_t427 - 0.0002573855616593899*_t435 + 0.00047187352970888148*_t437 + 0.00062916470627850864*_t444;
  const double _t544 = 0.00064182351093241549*_hc2[0]*_t407*_t416 + 0.00096273526639862324*_hc2[1]*_hc2[2]*_t11*_t407 + 0.00010697058515540258*_hc2[3]*_t12*_t407 - 1.7828430859233764e-5*_t412 - 5.3485292577701291e-5*_t413 - 0.00011766764367094284*_t427 - 0.0017650146550641426*_t437 - 0.0023533528734188568*_t444;
  const double _t545 = 1.0620295562557661e-5*_t412 + 3.1860886687672982e-5*_t413 - 0.00038233064025207578*_t423 - 6.3721773375345964e-5*_t425 + 7.0093950712880559e-5*_t427 - 0.00057349596037811367*_t435 + 0.0010514092606932084*_t437 + 0.0014018790142576112*_t444;
  const double _t547 = -1.6434382722446381e-7*_t408 + 8.8745666701210456e-6*_t417 + 2.6623700010363137e-5*_t421 + 4.4372833350605228e-6*_t424 - 1.6270038895221917e-5*_t426 + 1.4100700375858995e-5*_t428 - 0.000195240466742663*_t436 + 0.0002538126067654619*_t438 - 0.000195240466742663*_t443 + 0.00042302101127576984*_t445;
  const double _t548 = 3.7234940881264067e-5*_hc2[0]*_t407*_t416 + 5.5852411321896101e-5*_hc2[1]*_hc2[2]*_t11*_t407 + 6.2058234802106778e-6*_hc2[3]*_t12*_t407 - 1.0343039133684463e-6*_t412 - 3.1029117401053389e-6*_t413 - 6.8264058282317456e-6*_t427 - 0.00010239608742347618*_t437 - 0.00013652811656463491*_t444;
  const double _t550 = 0.011355661278716499*_hc2[1]*_hc2[2]*_t12*_t407 + 0.00094630510655970823*_hc2[3]*_t13*_t407 + 9.5586374399970529e-6*_hc2[3]*_t407 + 0.011355661278716499*_t11*_t407*_t416 - 0.00051616642175984084*_t417 - 0.0015484992652795225*_t421 - 0.00025808321087992042*_t424 - 0.00082013109235174712*_t428 - 0.014762359662331448*_t438 - 0.024603932770552413*_t445;
  const double _t551 = -1.0183913438925636e-5*_t408 + 0.00054993132570198437*_t417 + 0.0016497939771059531*_t421 + 0.00027496566285099218*_t424 - 0.001008207430453638*_t426 + 0.0008737797730598196*_t428 - 0.012098489165443656*_t436 + 0.015728035915076753*_t438 - 0.012098489165443656*_t443 + 0.026213393191794588*_t445;
  const double _t552 = 0.00035404674923430763*_hc2[1]*_hc2[2]*_t12*_t407 + 2.9503895769525636e-5*_hc2[3]*_t13*_t407 + 2.9801914918712763e-7*_hc2[3]*_t407 + 0.00035404674923430763*_t11*_t407*_t416 - 1.6093034056104892e-5*_t417 - 4.8279102168314677e-5*_t421 - 8.0465170280524461e-6*_t424 - 2.5570043000255551e-5*_t428 - 0.00046026077400459992*_t438 - 0.00076710129000766653*_t445;
  const double _t553 = -3.6799114133669636e-6*_t408 + 0.00019871521632181604*_t417 + 0.00059614564896544811*_t421 + 9.9357608160908018e-5*_t424 - 0.0003643112299233294*_t426 + 0.00031573639926688548*_t428 - 0.0043717347590799528*_t436 + 0.0056832551868039386*_t438 - 0.0043717347590799528*_t443 + 0.0094720919780065644*_t445;
  const double _t554 = 0.00021537975263264525*_hc2[1]*_hc2[2]*_t12*_t407 + 1.7948312719387105e-5*_hc2[3]*_t13*_t407 + 1.8129608807461722e-7*_hc2[3]*_t407 + 0.00021537975263264525*_t11*_t407*_t416 - 9.7899887560293297e-6*_t417 - 2.9369966268087989e-5*_t421 - 4.8949943780146649e-6*_t424 - 1.5555204356802157e-5*_t428 - 0.00027999367842243883*_t438 - 0.00046665613070406472*_t445;
  const double _t555 = 0.0003324742504766095*_hc2[1]*_hc2[2]*_t12*_t407 + 2.7706187539717458e-5*_hc2[3]*_t13*_t407 + 2.7986048019916624e-7*_hc2[3]*_t407 + 0.0003324742504766095*_t11*_t407*_t416 - 1.5112465930754977e-5*_t417 - 4.5337397792264931e-5*_t421 - 7.5562329653774886e-6*_t424 - 2.4012029201088464e-5*_t428 - 0.00043221652561959235*_t438 - 0.00072036087603265391*_t445;
#endif
#if _KMAX >= 4
  const double _t566 = 0.01480957756685447*_hc2[0];
  const double _t715 = 3.9156152961095439e-5*_t212;
  const double _t751 = _hc2[4]*_t750;
  const double _t760 = _hc2[0]*_t751;
  const double _t761 = _hc2[1]*_hc2[3]*_t750;
  const double _t767 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t768 = _t750*_t767;
  const double _t769 = ((_hc2[2]) * (_hc2[2]));
  const double _t770 = _t750*_t769;
  const double _t776 = _hc2[0]*_t761;
  const double _t777 = _hc2[0]*_t768;
  const double _t778 = _hc2[0]*_t770;
  const double _t779 = _t11*_t751;
  const double _t780 = _t12*_t751;
  const double _t781 = _t13*_t751;
  const double _t782 = _t14*_t751;
  const double _t783 = _t15*_t751;
  const double _t784 = _hc2[2]*_t213*_t750;
  const double _t788 = _hc2[0]*_t784;
  const double _t789 = _t11*_t761;
  const double _t790 = _t12*_t761;
  const double _t791 = _t13*_t761;
  const double _t792 = _t14*_t761;
  const double _t795 = _t11*_t768;
  const double _t796 = _t11*_t770;
  const double _t797 = _t12*_t768;
  const double _t798 = _t12*_t770;
  const double _t799 = _t13*_t770;
  const double _t800 = _t14*_t770;
  const double _t801 = 3.856660824701685e-5*_t204;
  const double _t804 = _t11*_t784;
  const double _t805 = _t12*_t784;
  const double _t806 = _t13*_t784;
  const double _t807 = 7.8312305922190878e-5*_t212;
  const double _t808 = 7.8312305922190878e-5*_t214;
#endif

  const double f = _hc1[0]*_t17 + _hc1[0]*_t20 + _hc1[0]*_t23 + _hc1[0]*_t25 + _hc1[0]*_t32 + _hc1[0]*_t35 + _hc1[0]*_t4 + 0.19451907596748125*_hc1[0] - 0.13375053494735893*_hc2[0] - 0.054303814303104071*_t10 - 0.38230940935406268*_t11 - 0.0080475072989145792*_t12 - 0.057084476241712602*_t13 + 0.050197247070683313*_t14 + 0.073000610738035553*_t15 - 0.040204197854033483*_t16 + _t18*_t24 + _t18*_t29 + _t18*_t34 + _t18*_t39 + _t18*_t46 + _t18*_t50 + 0.0012341314639045392*_t19 + _t21*_t22 + _t21*_t28 + _t21*_t33 + _t21*_t40 + _t21*_t45 + _t21*_t51 + _t21*_t56 + _t26*_t27 + _t26*_t36 + _t26*_t42 + _t26*_t48 + _t26*_t52 + _t26*_t59 + _t26*_t61 + _t30*_t31 + _t30*_t41 + _t30*_t47 + _t30*_t53 + _t30*_t57 + _t30*_t62 + _t30*_t65 + _t37*_t38 + _t37*_t49 + _t37*_t55 + _t37*_t60 + _t37*_t64 + _t37*_t67 + _t37*_t68 + _t43*_t44 + _t43*_t54 + _t43*_t58 + _t43*_t63 + _t43*_t66 + _t43*_t69 + _t43*_t70 + 0.006355922279331541*_t5 - 0.0059231370499700734*_t6 - 0.01228729376505733*_t7 + 0.052279783829707639*_t8 + 0.0044142553981357691*_t9 + 1.2331691431913853;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t17*_t71 + _t20*_t71 + _t22*_t80 + _t23*_t71 + _t24*_t79 + _t25*_t71 + _t27*_t81 + _t28*_t80 + _t29*_t79 + _t31*_t82 + _t32*_t71 + _t33*_t80 + _t34*_t79 + _t35*_t71 + _t36*_t81 + _t38*_t83 + _t39*_t79 + _t4*_t71 + _t40*_t80 + _t41*_t82 + _t42*_t81 + _t44*_t84 + _t45*_t80 + _t46*_t79 + _t47*_t82 + _t48*_t81 + _t49*_t83 + _t50*_t79 + _t51*_t80 + _t52*_t81 + _t53*_t82 + _t54*_t84 + _t55*_t83 + _t56*_t80 + _t57*_t82 + _t58*_t84 + _t59*_t81 + _t60*_t83 + _t61*_t81 + _t62*_t82 + _t63*_t84 + _t64*_t83 + _t65*_t82 + _t66*_t84 + _t67*_t83 + _t68*_t83 + _t69*_t84 + _t70*_t84 + 0.19451907596748125*_t71 + _t72*_t73 + 0.012711844558663082*_t72 - 0.01776941114991022*_t74 - 0.049149175060229318*_t75 + 0.2613989191485382*_t76 + 0.026485532388814615*_t77 - 0.3801267001217285*_t78;
  out[1] = df_dt;
  const double df_dx2 = _hc1[0]*_t111 + _hc1[0]*_t113 + _hc1[0]*_t124 + _hc1[0]*_t126 + _hc1[0]*_t138 + _hc1[0]*_t93 - _hc1[0]*_t95 + 0.018250152684508888*_t100 - 0.011726224374093099*_t101 + _t102*_t22 + _t102*_t28 + _t102*_t33 + _t102*_t40 + _t102*_t45 + _t102*_t51 + _t102*_t56 + _t103*_t27 + _t103*_t36 + _t103*_t42 + _t103*_t48 + _t103*_t52 + _t103*_t59 + _t103*_t61 + _t104*_t21 - _t105*_t21 + _t106*_t26 + _t107*_t31 + _t107*_t41 + _t107*_t47 + _t107*_t53 + _t107*_t57 + _t107*_t62 + _t107*_t65 + _t108*_t26 + _t109*_t38 + _t109*_t49 + _t109*_t55 + _t109*_t60 + _t109*_t64 + _t109*_t67 + _t109*_t68 + _t110*_t30 + _t112*_t30 + _t114*_t37 - _t115*_t37 + _t116*_t43 + _t117*_t44 + _t117*_t54 + _t117*_t58 + _t117*_t63 + _t117*_t66 + _t117*_t69 + _t117*_t70 + _t118*_t43 + _t119*_t18 + _t120*_t18 + _t121*_t21 + _t122*_t21 + _t123*_t26 + _t125*_t26 + _t127*_t30 + _t128*_t30 + _t129*_t37 + _t130*_t37 + _t131*_t18 + _t132*_t43 + _t133*_t18 + _t134*_t43 + _t135*_t21 + _t136*_t21 + _t137*_t26 + _t139*_t26 + _t140*_t30 + _t141*_t30 + _t142*_t37 + _t143*_t37 + _t144*_t18 + _t145*_t43 + _t146*_t43 + _t147*_t21 + _t148*_t26 + _t149*_t30 + _t150*_t37 + _t151*_t43 + _t17*_t85 + 5.14221443293558e-5*_t18*_t92 - 0.0001044164078962545*_t19*_t92 + _t20*_t85 + _t23*_t85 + _t24*_t96 + _t25*_t85 + _t29*_t96 + _t32*_t85 + _t34*_t96 + _t35*_t85 + _t39*_t96 + _t4*_t85 + _t46*_t96 + _t50*_t96 + _t73*_t86 + 0.19451907596748125*_t85 + 0.012711844558663082*_t86 - 0.01776941114991022*_t87 - 0.049149175060229318*_t88 + 0.2613989191485382*_t89 + 0.026485532388814615*_t90 - 0.3801267001217285*_t91 - 0.0055729389561399555*_t92 - 0.03185911744617189*_t94 - 0.0010059384123643224*_t97 - 0.0095140793736187669*_t98 + 0.010457759806392357*_t99;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t153*_t17 + _t153*_t20 + _t153*_t23 + _t153*_t25 + _t153*_t32 + _t153*_t35 + _t153*_t4 + 0.19451907596748125*_t153 + _t154*_t73 + 0.012711844558663082*_t154 + _t156*_t73 + 0.012711844558663082*_t156 - 0.03553882229982044*_t157 - 0.01776941114991022*_t158 - 0.049149175060229318*_t159 + 0.2613989191485382*_t160 + 0.026485532388814615*_t161 - 0.3801267001217285*_t162 - 0.14744752518068795*_t163 + 1.0455956765941528*_t164 + 0.13242766194407307*_t165 - 2.280760200730371*_t166 + _t167*_t24 + _t167*_t29 + _t167*_t34 + _t167*_t39 + _t167*_t46 + _t167*_t50 + _t168*_t24 + _t168*_t29 + _t168*_t34 + _t168*_t39 + _t168*_t46 + _t168*_t50 + _t169*_t22 + _t169*_t28 + _t169*_t33 + _t169*_t40 + _t169*_t45 + _t169*_t51 + _t169*_t56 + _t170*_t27 + _t170*_t36 + _t170*_t42 + _t170*_t48 + _t170*_t52 + _t170*_t59 + _t170*_t61 + _t171*_t31 + _t171*_t41 + _t171*_t47 + _t171*_t53 + _t171*_t57 + _t171*_t62 + _t171*_t65 + _t172*_t38 + _t172*_t49 + _t172*_t55 + _t172*_t60 + _t172*_t64 + _t172*_t67 + _t172*_t68 + _t173*_t44 + _t173*_t54 + _t173*_t58 + _t173*_t63 + _t173*_t66 + _t173*_t69 + _t173*_t70;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = _t104*_t80 - _t105*_t80 + _t106*_t81 + _t108*_t81 + _t110*_t82 + _t111*_t71 + _t112*_t82 + _t113*_t71 + _t114*_t83 - _t115*_t83 + _t116*_t84 + _t118*_t84 + _t119*_t79 + _t120*_t79 + _t121*_t80 + _t122*_t80 + _t123*_t81 + _t124*_t71 + _t125*_t81 + _t126*_t71 + _t127*_t82 + _t128*_t82 + _t129*_t83 + _t130*_t83 + _t131*_t79 + _t132*_t84 + _t133*_t79 + _t134*_t84 + _t135*_t80 + _t136*_t80 + _t137*_t81 + _t138*_t71 + _t139*_t81 + _t140*_t82 + _t141*_t82 + _t142*_t83 + _t143*_t83 + _t144*_t79 + _t145*_t84 + _t146*_t84 + _t147*_t80 + _t148*_t81 + _t149*_t82 + _t150*_t83 + _t151*_t84 + _t17*_t175 + _t175*_t20 + _t175*_t23 + _t175*_t25 + _t175*_t32 + _t175*_t35 + _t175*_t4 + 0.19451907596748125*_t175 + _t176*_t73 + 0.012711844558663082*_t176 + _t177*_t73 + 0.012711844558663082*_t177 - 0.03553882229982044*_t178 - 0.01776941114991022*_t179 - 0.049149175060229318*_t180 + 0.2613989191485382*_t181 + 0.026485532388814615*_t182 - 0.3801267001217285*_t183 - 0.14744752518068795*_t184 + 1.0455956765941528*_t185 + 0.13242766194407307*_t186 - 2.280760200730371*_t187 + _t188*_t72 + _t189*_t24 + _t189*_t29 + _t189*_t34 + _t189*_t39 + _t189*_t46 + _t189*_t50 - _t190*_t72 + _t191*_t24 + _t191*_t29 + _t191*_t34 + _t191*_t39 + _t191*_t46 + _t191*_t50 + _t192*_t22 + _t192*_t28 + _t192*_t33 + _t192*_t40 + _t192*_t45 + _t192*_t51 + _t192*_t56 + _t193*_t27 + _t193*_t36 + _t193*_t42 + _t193*_t48 + _t193*_t52 + _t193*_t59 + _t193*_t61 + _t194*_t31 + _t194*_t41 + _t194*_t47 + _t194*_t53 + _t194*_t57 + _t194*_t62 + _t194*_t65 + _t195*_t38 + _t195*_t49 + _t195*_t55 + _t195*_t60 + _t195*_t64 + _t195*_t67 + _t195*_t68 + _t196*_t44 + _t196*_t54 + _t196*_t58 + _t196*_t63 + _t196*_t66 + _t196*_t69 + _t196*_t70 + _t71*_t93 - _t71*_t95;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = _hc1[0]*_t211 + _hc1[0]*_t262 + _hc1[0]*_t275 + _hc1[0]*_t283 + _hc1[0]*_t292 + _hc1[0]*_t298 + _t102*_t239 - _t102*_t242 + _t103*_t241 + _t103*_t246 + _t107*_t254 + _t107*_t258 + _t109*_t257 - _t109*_t261 + _t111*_t249 + _t113*_t249 + _t117*_t263 + _t117*_t265 + _t119*_t251 + _t120*_t251 + _t121*_t264 + _t122*_t264 + _t123*_t266 + _t124*_t249 + _t125*_t266 + _t126*_t249 + _t127*_t269 + _t128*_t269 + _t129*_t271 + _t130*_t271 + _t131*_t251 + _t132*_t276 + _t133*_t251 + _t134*_t276 + _t135*_t264 + _t136*_t264 + _t137*_t266 + _t138*_t249 + _t139*_t266 + _t140*_t269 + _t141*_t269 + _t142*_t271 + _t143*_t271 + _t144*_t251 + _t145*_t276 + _t146*_t276 + _t147*_t264 + _t148*_t266 + _t149*_t269 + _t150*_t271 + _t151*_t276 + _t17*_t198 + 2.1425893470564917e-6*_t18*_t204 - 4.3506836623439377e-6*_t18*_t214 + _t18*_t268 + _t18*_t279 + _t18*_t286 + _t18*_t295 + _t18*_t301 - 4.3506836623439377e-6*_t19*_t204 + _t198*_t20 + _t198*_t23 + _t198*_t25 + _t198*_t32 + _t198*_t35 + _t198*_t4 + 0.19451907596748125*_t198 + _t199*_t73 + 0.012711844558663082*_t199 + _t200*_t73 + 0.012711844558663082*_t200 - 0.00023220578983916481*_t204 - 0.03553882229982044*_t205 - 0.01776941114991022*_t206 - 0.049149175060229318*_t207 + 0.2613989191485382*_t208 + 0.026485532388814615*_t209 + _t21*_t236 - _t21*_t237 - _t21*_t238 + _t21*_t270 + _t21*_t280 + _t21*_t289 + _t21*_t296 + _t21*_t303 - 0.3801267001217285*_t210 - _t212*_t220 - 0.0013274632269238288*_t212 - _t214*_t220 - 0.0013274632269238288*_t214 - 0.14744752518068795*_t215 + 1.0455956765941528*_t216 + 0.13242766194407307*_t217 - 2.280760200730371*_t218 + _t219*_t85 + _t22*_t253 - 8.38282010303602e-5*_t221 - 4.19141005151801e-5*_t222 - 0.00039641997390078196*_t223 + 0.00043573999193301487*_t224 + 0.00076042302852120369*_t225 - 0.00048859268225387913*_t226 + _t227*_t86 - _t228*_t85 - _t229*_t86 + _t230*_t24 + _t230*_t29 + _t230*_t34 + _t230*_t39 + _t230*_t46 + _t230*_t50 - 0.0011892599217023459*_t231 + 0.0017429599677320595*_t232 + 0.0038021151426060184*_t233 - 0.0029315560935232748*_t234 + _t235*_t24 + _t235*_t29 + _t235*_t34 + _t235*_t39 + _t235*_t46 + _t235*_t50 + _t240*_t26 + _t243*_t26 + _t244*_t26 + _t245*_t30 + _t247*_t30 + _t248*_t30 + _t250*_t37 - _t252*_t37 + _t253*_t28 + _t253*_t33 + _t253*_t40 + _t253*_t45 + _t253*_t51 + _t253*_t56 - _t255*_t37 + _t256*_t43 + _t259*_t43 + _t26*_t272 + _t26*_t282 + _t26*_t290 + _t26*_t297 + _t26*_t304 + _t260*_t43 + _t267*_t27 + _t267*_t36 + _t267*_t42 + _t267*_t48 + _t267*_t52 + _t267*_t59 + _t267*_t61 + _t273*_t31 + _t273*_t41 + _t273*_t47 + _t273*_t53 + _t273*_t57 + _t273*_t62 + _t273*_t65 + _t274*_t30 + _t277*_t37 + _t278*_t43 + _t281*_t38 + _t281*_t49 + _t281*_t55 + _t281*_t60 + _t281*_t64 + _t281*_t67 + _t281*_t68 + _t284*_t30 + _t285*_t37 + _t287*_t43 + _t288*_t44 + _t288*_t54 + _t288*_t58 + _t288*_t63 + _t288*_t66 + _t288*_t69 + _t288*_t70 + _t291*_t30 + _t293*_t37 + _t294*_t43 + _t299*_t30 + _t30*_t305 + _t300*_t37 + _t302*_t43 + _t306*_t37 + _t307*_t43;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t17*_t309 + _t20*_t309 + _t22*_t332 + _t23*_t309 + _t24*_t330 + _t24*_t331 + _t25*_t309 + _t27*_t333 + _t28*_t332 + _t29*_t330 + _t29*_t331 + _t309*_t32 + _t309*_t35 + _t309*_t4 + 0.19451907596748125*_t309 + _t31*_t335 + _t310*_t73 + 0.012711844558663082*_t310 + _t312*_t316 + 0.038135533675989246*_t312 - 0.03553882229982044*_t314 - 0.10661646689946132*_t315 - 0.29489505036137591*_t317 - 0.01776941114991022*_t318 - 0.049149175060229318*_t319 + 0.2613989191485382*_t320 + 0.026485532388814615*_t321 - 0.3801267001217285*_t322 - 0.44234257554206386*_t323 + 3.1367870297824584*_t324 + 0.39728298583221922*_t325 - 6.842280602191113*_t326 + 3.1367870297824584*_t327 + 0.5297106477762923*_t328 - 11.403801003651855*_t329 + _t33*_t332 + _t330*_t34 + _t330*_t39 + _t330*_t46 + _t330*_t50 + _t331*_t34 + _t331*_t39 + _t331*_t46 + _t331*_t50 + _t332*_t40 + _t332*_t45 + _t332*_t51 + _t332*_t56 + _t333*_t36 + _t333*_t42 + _t333*_t48 + _t333*_t52 + _t333*_t59 + _t333*_t61 + _t335*_t41 + _t335*_t47 + _t335*_t53 + _t335*_t57 + _t335*_t62 + _t335*_t65 + _t337*_t38 + _t337*_t49 + _t337*_t55 + _t337*_t60 + _t337*_t64 + _t337*_t67 + _t337*_t68 + _t338*_t44 + _t338*_t54 + _t338*_t58 + _t338*_t63 + _t338*_t66 + _t338*_t69 + _t338*_t70;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = _t104*_t169 - _t105*_t169 + _t106*_t170 + _t108*_t170 + _t110*_t171 + _t111*_t153 + _t112*_t171 + _t113*_t153 + _t114*_t172 - _t115*_t172 + _t116*_t173 + _t118*_t173 + _t119*_t167 + _t119*_t168 + _t120*_t167 + _t120*_t168 + _t121*_t169 + _t122*_t169 + _t123*_t170 + _t124*_t153 + _t125*_t170 + _t126*_t153 + _t127*_t171 + _t128*_t171 + _t129*_t172 + _t130*_t172 + _t131*_t167 + _t131*_t168 + _t132*_t173 + _t133*_t167 + _t133*_t168 + _t134*_t173 + _t135*_t169 + _t136*_t169 + _t137*_t170 + _t138*_t153 + _t139*_t170 + _t140*_t171 + _t141*_t171 + _t142*_t172 + _t143*_t172 + _t144*_t167 + _t144*_t168 + _t145*_t173 + _t146*_t173 + _t147*_t169 + _t148*_t170 + _t149*_t171 + _t150*_t172 + _t151*_t173 + _t153*_t93 - _t153*_t95 + _t154*_t188 - _t154*_t190 + _t156*_t188 - _t156*_t190 + _t17*_t340 + _t20*_t340 + _t22*_t361 + _t23*_t340 + _t24*_t358 + _t24*_t359 + _t25*_t340 + _t27*_t362 + _t28*_t361 + _t29*_t358 + _t29*_t359 + _t31*_t364 + _t316*_t342 + _t32*_t340 + _t33*_t361 + _t34*_t358 + _t34*_t359 + _t340*_t35 + _t340*_t4 + 0.19451907596748125*_t340 + _t341*_t73 + 0.012711844558663082*_t341 + 0.038135533675989246*_t342 - 0.03553882229982044*_t343 - 0.10661646689946132*_t344 - 0.29489505036137591*_t345 - 0.01776941114991022*_t346 - 0.049149175060229318*_t347 + 0.2613989191485382*_t348 + 0.026485532388814615*_t349 - 0.3801267001217285*_t350 - 0.44234257554206386*_t351 + 3.1367870297824584*_t352 + 0.39728298583221922*_t353 - 6.842280602191113*_t354 + 3.1367870297824584*_t355 + 0.5297106477762923*_t356 - 11.403801003651855*_t357 + _t358*_t39 + _t358*_t46 + _t358*_t50 + _t359*_t39 + _t359*_t46 + _t359*_t50 + _t36*_t362 + _t361*_t40 + _t361*_t45 + _t361*_t51 + _t361*_t56 + _t362*_t42 + _t362*_t48 + _t362*_t52 + _t362*_t59 + _t362*_t61 + _t364*_t41 + _t364*_t47 + _t364*_t53 + _t364*_t57 + _t364*_t62 + _t364*_t65 + _t365*_t38 + _t365*_t49 + _t365*_t55 + _t365*_t60 + _t365*_t64 + _t365*_t67 + _t365*_t68 + _t366*_t44 + _t366*_t54 + _t366*_t58 + _t366*_t63 + _t366*_t66 + _t366*_t69 + _t366*_t70;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = _t111*_t393 + _t113*_t393 + _t119*_t394 + _t119*_t395 + _t120*_t394 + _t120*_t395 + _t121*_t397 + _t122*_t397 + _t123*_t399 + _t124*_t393 + _t125*_t399 + _t126*_t393 + _t127*_t400 + _t128*_t400 + _t129*_t403 + _t130*_t403 + _t131*_t394 + _t131*_t395 + _t132*_t404 + _t133*_t394 + _t133*_t395 + _t134*_t404 + _t135*_t397 + _t136*_t397 + _t137*_t399 + _t138*_t393 + _t139*_t399 + _t140*_t400 + _t141*_t400 + _t142*_t403 + _t143*_t403 + _t144*_t394 + _t144*_t395 + _t145*_t404 + _t146*_t404 + _t147*_t397 + _t148*_t399 + _t149*_t400 + _t150*_t403 + _t151*_t404 + _t17*_t368 + _t175*_t219 - _t175*_t228 + _t176*_t227 - _t176*_t229 + _t177*_t227 - _t177*_t229 + _t192*_t239 - _t192*_t242 + _t193*_t241 + _t193*_t246 + _t194*_t254 + _t194*_t258 + _t195*_t257 - _t195*_t261 + _t196*_t263 + _t196*_t265 + _t20*_t368 + _t211*_t71 + _t22*_t396 + _t23*_t368 + _t236*_t80 - _t237*_t80 - _t238*_t80 + _t24*_t391 + _t24*_t392 + _t240*_t81 + _t243*_t81 + _t244*_t81 + _t245*_t82 + _t247*_t82 + _t248*_t82 + _t25*_t368 + _t250*_t83 - _t252*_t83 - _t255*_t83 + _t256*_t84 + _t259*_t84 + _t260*_t84 + _t262*_t71 + _t268*_t79 + _t27*_t398 + _t270*_t80 + _t272*_t81 + _t274*_t82 + _t275*_t71 + _t277*_t83 + _t278*_t84 + _t279*_t79 + _t28*_t396 + _t280*_t80 + _t282*_t81 + _t283*_t71 + _t284*_t82 + _t285*_t83 + _t286*_t79 + _t287*_t84 + _t289*_t80 + _t29*_t391 + _t29*_t392 + _t290*_t81 + _t291*_t82 + _t292*_t71 + _t293*_t83 + _t294*_t84 + _t295*_t79 + _t296*_t80 + _t297*_t81 + _t298*_t71 + _t299*_t82 + _t300*_t83 + _t301*_t79 + _t302*_t84 + _t303*_t80 + _t304*_t81 + _t305*_t82 + _t306*_t83 + _t307*_t84 + _t31*_t402 + _t316*_t370 + _t32*_t368 + _t33*_t396 + _t34*_t391 + _t34*_t392 + _t35*_t368 + _t36*_t398 + _t368*_t4 + 0.19451907596748125*_t368 + _t369*_t73 + 0.012711844558663082*_t369 + 0.038135533675989246*_t370 - 0.03553882229982044*_t371 - 0.10661646689946132*_t372 - 0.29489505036137591*_t373 - 0.01776941114991022*_t374 - 0.049149175060229318*_t375 + 0.2613989191485382*_t376 + 0.026485532388814615*_t377 - 0.3801267001217285*_t378 - 0.44234257554206386*_t379 + _t38*_t405 + 3.1367870297824584*_t380 + 0.39728298583221922*_t381 - 6.842280602191113*_t382 + 3.1367870297824584*_t383 + 0.5297106477762923*_t384 - 11.403801003651855*_t385 + _t386*_t72 - _t387*_t71 - _t388*_t71 - _t389*_t72 + _t39*_t391 + _t39*_t392 - _t390*_t72 + _t391*_t46 + _t391*_t50 + _t392*_t46 + _t392*_t50 + _t396*_t40 + _t396*_t45 + _t396*_t51 + _t396*_t56 + _t398*_t42 + _t398*_t48 + _t398*_t52 + _t398*_t59 + _t398*_t61 + _t402*_t41 + _t402*_t47 + _t402*_t53 + _t402*_t57 + _t402*_t62 + _t402*_t65 + _t405*_t49 + _t405*_t55 + _t405*_t60 + _t405*_t64 + _t405*_t67 + _t405*_t68 + _t406*_t44 + _t406*_t54 + _t406*_t58 + _t406*_t63 + _t406*_t66 + _t406*_t69 + _t406*_t70;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = _hc1[0]*_t411 - _hc1[0]*_t419 - _hc1[0]*_t420 + _hc1[0]*_t490 + _hc1[0]*_t501 + _hc1[0]*_t522 + _hc1[0]*_t532 + _hc1[0]*_t547 + _t102*_t467 - _t102*_t473 + _t103*_t470 + _t103*_t475 + _t107*_t482 + _t107*_t487 + _t109*_t484 - _t109*_t489 + _t111*_t481 + _t113*_t481 + _t117*_t493 + _t117*_t497 + _t119*_t483 + _t119*_t486 + _t120*_t483 + _t120*_t486 + _t121*_t509 + _t122*_t509 + _t123*_t521 + _t124*_t481 + _t125*_t521 + _t126*_t481 + _t127*_t530 + _t128*_t530 + _t129*_t542 + _t130*_t542 + _t131*_t483 + _t131*_t486 + _t132*_t546 + _t133*_t483 + _t133*_t486 + _t134*_t546 + _t135*_t509 + _t136*_t509 + _t137*_t521 + _t138*_t481 + _t139*_t521 + _t140*_t530 + _t141*_t530 + _t142*_t542 + _t143*_t542 + _t144*_t483 + _t144*_t486 + _t145*_t546 + _t146*_t546 + _t147*_t509 + _t148*_t521 + _t149*_t530 + _t150*_t542 + _t151*_t546 + _t17*_t410 + 5.3564733676412292e-7*_t18*_t408 - 3.2630127467579532e-6*_t18*_t413 + _t18*_t499 + _t18*_t511 + _t18*_t529 + _t18*_t539 + _t18*_t550 - 1.0876709155859844e-6*_t19*_t408 + _t198*_t452 - _t198*_t457 + _t199*_t456 - _t199*_t460 + _t20*_t410 + _t200*_t456 - _t200*_t460 + _t21*_t459 - _t21*_t461 - _t21*_t462 + _t21*_t500 + _t21*_t513 + _t21*_t531 + _t21*_t541 + _t21*_t551 - _t212*_t451 - _t212*_t453 - _t212*_t471 + _t212*_t474 + _t212*_t485 - _t212*_t488 + _t212*_t495 - _t214*_t451 + _t22*_t492 + _t23*_t410 + _t24*_t454 + _t24*_t455 + _t25*_t410 + _t253*_t491 - _t253*_t494 + _t26*_t463 + _t26*_t464 + _t26*_t465 + _t26*_t502 + _t26*_t514 + _t26*_t533 + _t26*_t543 + _t26*_t552 + _t262*_t496 + _t267*_t503 + _t267*_t506 + _t268*_t498 + _t27*_t505 + _t270*_t507 + _t272*_t508 + _t273*_t516 + _t273*_t518 + _t274*_t515 + _t275*_t496 + _t277*_t517 + _t278*_t523 + _t279*_t498 + _t28*_t492 + _t280*_t507 + _t281*_t527 - _t281*_t528 + _t282*_t508 + _t283*_t496 + _t284*_t515 + _t285*_t517 + _t286*_t498 + _t287*_t523 + _t288*_t535 + _t288*_t536 + _t289*_t507 + _t29*_t454 + _t29*_t455 + _t290*_t508 + _t291*_t515 + _t292*_t496 + _t293*_t517 + _t294*_t523 + _t295*_t498 + _t296*_t507 + _t297*_t508 + _t298*_t496 + _t299*_t515 + _t30*_t466 + _t30*_t468 + _t30*_t469 + _t30*_t504 + _t30*_t519 + _t30*_t534 + _t30*_t544 + _t30*_t553 + _t300*_t517 + _t301*_t498 + _t302*_t523 + _t303*_t507 + _t304*_t508 + _t305*_t515 + _t306*_t517 + _t307*_t523 + _t31*_t526 + _t316*_t415 + _t32*_t410 + _t33*_t492 + _t34*_t454 + _t34*_t455 + _t35*_t410 + _t36*_t505 + _t37*_t472 - _t37*_t476 - _t37*_t477 + _t37*_t510 + _t37*_t520 + _t37*_t538 + _t37*_t545 + _t37*_t554 + _t38*_t537 + _t39*_t454 + _t39*_t455 + _t4*_t410 + _t40*_t492 - 5.8051447459791203e-5*_t408 + _t41*_t526 + 0.19451907596748125*_t410 - 0.00033186580673095719*_t412 - 0.00099559742019287157*_t413 + _t414*_t73 + 0.012711844558663082*_t414 + 0.038135533675989246*_t415 - 2.095705025759005e-5*_t417 - 0.03553882229982044*_t418 + _t42*_t505 - 6.287115077277015e-5*_t421 - 0.10661646689946132*_t422 - 0.00059462996085117293*_t423 - 1.0478525128795025e-5*_t424 - 9.910499347519549e-5*_t425 + 0.00010893499798325372*_t426 + 0.00019010575713030092*_t427 - 0.00012214817056346978*_t428 - 0.29489505036137591*_t429 + _t43*_t478 + _t43*_t479 + _t43*_t480 + _t43*_t512 + _t43*_t524 + _t43*_t540 + _t43*_t548 + _t43*_t555 - 0.01776941114991022*_t430 - 0.049149175060229318*_t431 + 0.2613989191485382*_t432 + 0.026485532388814615*_t433 - 0.3801267001217285*_t434 - 0.0008919449412767594*_t435 + 0.0013072199757990446*_t436 + 0.0028515863569545138*_t437 - 0.0021986670701424561*_t438 - 0.44234257554206386*_t439 + _t44*_t549 + 3.1367870297824584*_t440 + 0.39728298583221922*_t441 - 6.842280602191113*_t442 + 0.0013072199757990446*_t443 + 0.0038021151426060184*_t444 - 0.0036644451169040935*_t445 + 3.1367870297824584*_t446 + 0.5297106477762923*_t447 - 11.403801003651855*_t448 + _t449*_t85 + _t45*_t492 + _t450*_t86 + _t454*_t46 + _t454*_t50 + _t455*_t46 + _t455*_t50 - _t458*_t86 + _t47*_t526 + _t48*_t505 + _t49*_t537 + _t492*_t51 + _t492*_t56 + _t505*_t52 + _t505*_t59 + _t505*_t61 + _t526*_t53 + _t526*_t57 + _t526*_t62 + _t526*_t65 + _t537*_t55 + _t537*_t60 + _t537*_t64 + _t537*_t67 + _t537*_t68 + _t54*_t549 + _t549*_t58 + _t549*_t63 + _t549*_t66 + _t549*_t69 + _t549*_t70;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t17*_t557 + _t20*_t557 + _t22*_t593 + _t23*_t557 + _t24*_t590 + _t24*_t591 + _t24*_t592 + _t25*_t557 + _t27*_t594 + _t28*_t593 + _t29*_t590 + _t29*_t591 + _t29*_t592 + _t31*_t596 + _t316*_t564 + _t32*_t557 + _t33*_t593 + _t34*_t590 + _t34*_t591 + _t34*_t592 + _t35*_t557 + _t36*_t594 + _t38*_t598 + _t39*_t590 + _t39*_t591 + _t39*_t592 + _t4*_t557 + _t40*_t593 + _t41*_t596 + _t42*_t594 + _t44*_t599 + _t45*_t593 + _t46*_t590 + _t46*_t591 + _t46*_t592 + _t47*_t596 + _t48*_t594 + _t49*_t598 + _t50*_t590 + _t50*_t591 + _t50*_t592 + _t51*_t593 + _t52*_t594 + _t53*_t596 + _t54*_t599 + _t55*_t598 + 0.19451907596748125*_t557 + _t558*_t73 + 0.012711844558663082*_t558 + _t56*_t593 + _t560*_t566 + 0.050847378234652328*_t560 + _t562*_t581 - 0.29489505036137591*_t562 + 0.038135533675989246*_t564 - 0.14215528919928176*_t565 + 6.2735740595649168*_t567 - 0.10661646689946132*_t568 - 0.01776941114991022*_t569 + _t57*_t596 - 0.049149175060229318*_t570 + 0.2613989191485382*_t571 + 0.026485532388814615*_t572 - 0.3801267001217285*_t573 - 0.21323293379892264*_t575 - 1.7693703021682555*_t576 - 0.58979010072275182*_t577 + 4.1823827063766111*_t578 + 0.5297106477762923*_t579 + _t58*_t599 - 9.123040802921484*_t580 - 0.44234257554206386*_t582 - 45.61520401460742*_t583 + 3.1367870297824584*_t584 + 0.39728298583221922*_t585 - 6.842280602191113*_t586 + 18.820722178694751*_t587 + 3.1782638866577538*_t588 - 68.422806021911128*_t589 + _t59*_t594 + _t594*_t61 + _t596*_t62 + _t596*_t65 + _t598*_t60 + _t598*_t64 + _t598*_t67 + _t598*_t68 + _t599*_t63 + _t599*_t66 + _t599*_t69 + _t599*_t70;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = _t104*_t332 - _t105*_t332 + _t106*_t333 + _t108*_t333 + _t110*_t335 + _t111*_t309 + _t112*_t335 + _t113*_t309 + _t114*_t337 - _t115*_t337 + _t116*_t338 + _t118*_t338 + _t119*_t330 + _t119*_t331 + _t120*_t330 + _t120*_t331 + _t121*_t332 + _t122*_t332 + _t123*_t333 + _t124*_t309 + _t125*_t333 + _t126*_t309 + _t127*_t335 + _t128*_t335 + _t129*_t337 + _t130*_t337 + _t131*_t330 + _t131*_t331 + _t132*_t338 + _t133*_t330 + _t133*_t331 + _t134*_t338 + _t135*_t332 + _t136*_t332 + _t137*_t333 + _t138*_t309 + _t139*_t333 + _t140*_t335 + _t141*_t335 + _t142*_t337 + _t143*_t337 + _t144*_t330 + _t144*_t331 + _t145*_t338 + _t146*_t338 + _t147*_t332 + _t148*_t333 + _t149*_t335 + _t150*_t337 + _t151*_t338 + _t17*_t601 + _t188*_t310 - _t190*_t310 + _t20*_t601 + _t22*_t632 + _t23*_t601 + _t24*_t628 + _t24*_t629 + _t24*_t630 + _t25*_t601 + _t27*_t633 + _t28*_t632 + _t29*_t628 + _t29*_t629 + _t29*_t630 + _t309*_t93 - _t309*_t95 + _t31*_t636 + _t312*_t456 - _t312*_t460 + _t316*_t605 + _t32*_t601 + _t33*_t632 + _t34*_t628 + _t34*_t629 + _t34*_t630 + _t35*_t601 + _t36*_t633 + _t38*_t638 + _t39*_t628 + _t39*_t629 + _t39*_t630 + _t4*_t601 + _t40*_t632 + _t41*_t636 + _t42*_t633 + _t44*_t639 + _t45*_t632 + _t46*_t628 + _t46*_t629 + _t46*_t630 + _t47*_t636 + _t48*_t633 + _t49*_t638 + _t50*_t628 + _t50*_t629 + _t50*_t630 + _t51*_t632 + _t52*_t633 + _t53*_t636 + _t54*_t639 + _t55*_t638 + _t56*_t632 + _t566*_t603 + _t57*_t636 + _t58*_t639 + _t581*_t604 + _t59*_t633 + _t60*_t638 + 0.19451907596748125*_t601 + _t602*_t73 + 0.012711844558663082*_t602 + 0.050847378234652328*_t603 - 0.29489505036137591*_t604 + 0.038135533675989246*_t605 - 0.14215528919928176*_t606 + 6.2735740595649168*_t607 - 0.10661646689946132*_t608 - 0.01776941114991022*_t609 + _t61*_t633 - 0.049149175060229318*_t610 + 0.2613989191485382*_t611 + 0.026485532388814615*_t612 - 0.3801267001217285*_t613 - 0.21323293379892264*_t614 - 1.7693703021682555*_t615 - 0.58979010072275182*_t616 + 4.1823827063766111*_t617 + 0.5297106477762923*_t618 - 9.123040802921484*_t619 + _t62*_t636 - 0.44234257554206386*_t620 - 45.61520401460742*_t621 + 3.1367870297824584*_t622 + 0.39728298583221922*_t623 - 6.842280602191113*_t624 + 18.820722178694751*_t625 + 3.1782638866577538*_t626 - 68.422806021911128*_t627 + _t63*_t639 + _t636*_t65 + _t638*_t64 + _t638*_t67 + _t638*_t68 + _t639*_t66 + _t639*_t69 + _t639*_t70;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = _t111*_t671 + _t113*_t671 + _t119*_t672 + _t119*_t673 + _t120*_t672 + _t120*_t673 + _t121*_t674 + _t122*_t674 + _t123*_t676 + _t124*_t671 + _t125*_t676 + _t126*_t671 + _t127*_t677 + _t128*_t677 + _t129*_t679 + _t130*_t679 + _t131*_t672 + _t131*_t673 + _t132*_t680 + _t133*_t672 + _t133*_t673 + _t134*_t680 + _t135*_t674 + _t136*_t674 + _t137*_t676 + _t138*_t671 + _t139*_t676 + _t140*_t677 + _t141*_t677 + _t142*_t679 + _t143*_t679 + _t144*_t672 + _t144*_t673 + _t145*_t680 + _t146*_t680 + _t147*_t674 + _t148*_t676 + _t149*_t677 + _t150*_t679 + _t151*_t680 + _t153*_t211 + _t153*_t262 + _t153*_t275 + _t153*_t283 + _t153*_t292 + _t153*_t298 - _t153*_t387 - _t153*_t388 + _t154*_t386 - _t154*_t389 - _t154*_t390 + _t156*_t386 - _t156*_t389 - _t156*_t390 + _t167*_t268 + _t167*_t279 + _t167*_t286 + _t167*_t295 + _t167*_t301 + _t168*_t268 + _t168*_t279 + _t168*_t286 + _t168*_t295 + _t168*_t301 + _t169*_t236 - _t169*_t237 - _t169*_t238 + _t169*_t270 + _t169*_t280 + _t169*_t289 + _t169*_t296 + _t169*_t303 + _t17*_t641 + _t170*_t240 + _t170*_t243 + _t170*_t244 + _t170*_t272 + _t170*_t282 + _t170*_t290 + _t170*_t297 + _t170*_t304 + _t171*_t245 + _t171*_t247 + _t171*_t248 + _t171*_t274 + _t171*_t284 + _t171*_t291 + _t171*_t299 + _t171*_t305 + _t172*_t250 - _t172*_t252 - _t172*_t255 + _t172*_t277 + _t172*_t285 + _t172*_t293 + _t172*_t300 + _t172*_t306 + _t173*_t256 + _t173*_t259 + _t173*_t260 + _t173*_t278 + _t173*_t287 + _t173*_t294 + _t173*_t302 + _t173*_t307 + _t20*_t641 + _t219*_t340 + _t22*_t675 + _t227*_t341 - _t228*_t340 - _t229*_t341 + _t23*_t641 + _t239*_t361 + _t24*_t668 + _t24*_t669 + _t24*_t670 + _t241*_t362 - _t242*_t361 + _t246*_t362 + _t25*_t641 + _t254*_t364 + _t257*_t365 + _t258*_t364 - _t261*_t365 + _t263*_t366 + _t265*_t366 + _t27*_t678 + _t28*_t675 + _t29*_t668 + _t29*_t669 + _t29*_t670 + _t31*_t682 + _t316*_t645 + _t32*_t641 + _t33*_t675 + _t34*_t668 + _t34*_t669 + _t34*_t670 + 0.0009255985979284044*_t342*_t92 - 0.0018794953421325811*_t342*_t94 + _t35*_t641 + _t36*_t678 + _t38*_t684 + _t39*_t668 + _t39*_t669 + _t39*_t670 + _t4*_t641 + _t40*_t675 + _t41*_t682 + _t42*_t678 + _t44*_t685 + _t45*_t675 + _t46*_t668 + _t46*_t669 + _t46*_t670 + _t47*_t682 + _t48*_t678 + _t49*_t684 + _t50*_t668 + _t50*_t669 + _t50*_t670 + _t51*_t675 + _t52*_t678 + _t53*_t682 + _t54*_t685 + _t55*_t684 + _t56*_t675 + _t566*_t643 + _t57*_t682 + _t58*_t685 + _t581*_t644 + _t59*_t678 + _t60*_t684 + _t61*_t678 + _t62*_t682 + _t63*_t685 + _t64*_t684 + 0.19451907596748125*_t641 + _t642*_t73 + 0.012711844558663082*_t642 + 0.050847378234652328*_t643 - 0.29489505036137591*_t644 + 0.038135533675989246*_t645 - 0.14215528919928176*_t646 + 6.2735740595649168*_t647 - 0.10661646689946132*_t648 - 0.01776941114991022*_t649 + _t65*_t682 - 0.049149175060229318*_t650 + 0.2613989191485382*_t651 + 0.026485532388814615*_t652 - 0.3801267001217285*_t653 - 0.21323293379892264*_t654 - 1.7693703021682555*_t655 - 0.58979010072275182*_t656 + 4.1823827063766111*_t657 + 0.5297106477762923*_t658 - 9.123040802921484*_t659 + _t66*_t685 - 0.44234257554206386*_t660 - 45.61520401460742*_t661 + 3.1367870297824584*_t662 + 0.39728298583221922*_t663 - 6.842280602191113*_t664 + 18.820722178694751*_t665 + 3.1782638866577538*_t666 - 68.422806021911128*_t667 + _t67*_t684 + _t68*_t684 + _t685*_t69 + _t685*_t70;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = _t111*_t719 + _t113*_t719 + _t119*_t720 + _t119*_t721 + _t120*_t720 + _t120*_t721 + _t121*_t727 + _t122*_t727 + _t123*_t729 + _t124*_t719 + _t125*_t729 + _t126*_t719 + _t127*_t733 + _t128*_t733 + _t129*_t735 + _t130*_t735 + _t131*_t720 + _t131*_t721 + _t132*_t738 + _t133*_t720 + _t133*_t721 + _t134*_t738 + _t135*_t727 + _t136*_t727 + _t137*_t729 + _t138*_t719 + _t139*_t729 + _t140*_t733 + _t141*_t733 + _t142*_t735 + _t143*_t735 + _t144*_t720 + _t144*_t721 + _t145*_t738 + _t146*_t738 + _t147*_t727 + _t148*_t729 + _t149*_t733 + _t150*_t735 + _t151*_t738 + _t17*_t687 + _t175*_t449 + _t176*_t450 - _t176*_t458 - _t176*_t715 + _t177*_t450 - _t177*_t458 - _t177*_t715 - 1.3547712039811658e-5*_t192*_t212 + _t192*_t467 - _t192*_t473 + 4.9695206811589548e-6*_t193*_t212 + _t193*_t470 + _t193*_t475 + 1.3254323669570616e-6*_t194*_t212 + _t194*_t482 + _t194*_t487 - 1.4138834233816784e-5*_t195*_t212 + _t195*_t484 - _t195*_t489 + 2.9592221473817311e-6*_t196*_t212 + _t196*_t493 + _t196*_t497 + _t20*_t687 - _t212*_t714 - _t214*_t714 + _t22*_t725 + _t23*_t687 + _t24*_t716 + _t24*_t717 + _t24*_t718 + _t25*_t687 + _t262*_t722 + _t268*_t723 + _t268*_t724 + _t27*_t731 + _t270*_t726 + _t272*_t728 + _t274*_t730 + _t275*_t722 + _t277*_t732 + _t278*_t734 + _t279*_t723 + _t279*_t724 + _t28*_t725 + _t280*_t726 + _t282*_t728 + _t283*_t722 + _t284*_t730 + _t285*_t732 + _t286*_t723 + _t286*_t724 + _t287*_t734 + _t289*_t726 + _t29*_t716 + _t29*_t717 + _t29*_t718 + _t290*_t728 + _t291*_t730 + _t292*_t722 + _t293*_t732 + _t294*_t734 + _t295*_t723 + _t295*_t724 + _t296*_t726 + _t297*_t728 + _t298*_t722 + _t299*_t730 + _t300*_t732 + _t301*_t723 + _t301*_t724 + _t302*_t734 + _t303*_t726 + _t304*_t728 + _t305*_t730 + _t306*_t732 + _t307*_t734 + _t31*_t737 + _t316*_t691 + _t32*_t687 + _t33*_t725 + _t34*_t716 + _t34*_t717 + _t34*_t718 + _t35*_t687 + _t36*_t731 + _t368*_t452 - _t368*_t457 + _t369*_t456 - _t369*_t460 + 0.0013883978968926066*_t370*_t92 - 0.0028192430131988716*_t370*_t94 + _t38*_t740 + _t39*_t716 + _t39*_t717 + _t39*_t718 + _t396*_t491 - _t396*_t494 + _t398*_t503 + _t398*_t506 + _t4*_t687 + _t40*_t725 + _t402*_t516 + _t402*_t518 + _t405*_t527 - _t405*_t528 + _t406*_t535 + _t406*_t536 + 1.6069420102923688e-6*_t408*_t72 + _t41*_t737 + _t411*_t71 - 3.2630127467579532e-6*_t412*_t72 - 9.7890382402738597e-6*_t413*_t72 - _t419*_t71 + _t42*_t731 - _t420*_t71 + _t44*_t741 + _t45*_t725 + _t459*_t80 + _t46*_t716 + _t46*_t717 + _t46*_t718 - _t461*_t80 - _t462*_t80 + _t463*_t81 + _t464*_t81 + _t465*_t81 + _t466*_t82 + _t468*_t82 + _t469*_t82 + _t47*_t737 + _t472*_t83 - _t476*_t83 - _t477*_t83 + _t478*_t84 + _t479*_t84 + _t48*_t731 + _t480*_t84 + _t49*_t740 + _t490*_t71 + _t499*_t79 + _t50*_t716 + _t50*_t717 + _t50*_t718 + _t500*_t80 + _t501*_t71 + _t502*_t81 + _t504*_t82 + _t51*_t725 + _t510*_t83 + _t511*_t79 + _t512*_t84 + _t513*_t80 + _t514*_t81 + _t519*_t82 + _t52*_t731 + _t520*_t83 + _t522*_t71 + _t524*_t84 + _t529*_t79 + _t53*_t737 + _t531*_t80 + _t532*_t71 + _t533*_t81 + _t534*_t82 + _t538*_t83 + _t539*_t79 + _t54*_t741 + _t540*_t84 + _t541*_t80 + _t543*_t81 + _t544*_t82 + _t545*_t83 + _t547*_t71 + _t548*_t84 + _t55*_t740 + _t550*_t79 + _t551*_t80 + _t552*_t81 + _t553*_t82 + _t554*_t83 + _t555*_t84 + _t56*_t725 + _t566*_t689 + _t57*_t737 + _t58*_t741 + _t581*_t690 + _t59*_t731 + _t60*_t740 + _t61*_t731 + _t62*_t737 + _t63*_t741 + _t64*_t740 + _t65*_t737 + _t66*_t741 + _t67*_t740 + _t68*_t740 + 0.19451907596748125*_t687 + _t688*_t73 + 0.012711844558663082*_t688 + 0.050847378234652328*_t689 + _t69*_t741 - 0.29489505036137591*_t690 + 0.038135533675989246*_t691 - 0.14215528919928176*_t692 + 6.2735740595649168*_t693 - 0.10661646689946132*_t694 - 0.01776941114991022*_t695 - 0.049149175060229318*_t696 + 0.2613989191485382*_t697 + 0.026485532388814615*_t698 - 0.3801267001217285*_t699 + _t70*_t741 - 0.21323293379892264*_t700 - 1.7693703021682555*_t701 - 0.58979010072275182*_t702 + 4.1823827063766111*_t703 + 0.5297106477762923*_t704 - 9.123040802921484*_t705 - 0.44234257554206386*_t706 - 45.61520401460742*_t707 + 3.1367870297824584*_t708 + 0.39728298583221922*_t709 - 6.842280602191113*_t710 + 18.820722178694751*_t711 + 3.1782638866577538*_t712 - 68.422806021911128*_t713;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 2.1939431557331984e-6*_hc1[0]*_t751 - 7.1265214039874116e-7*_hc1[0]*_t760 - 2.8506085615949646e-6*_hc1[0]*_t761 - 2.1379564211962235e-6*_hc1[0]*_t770 + _hc1[0]*(4.5636473377854533e-7*_hc2[4]*_t1*_t749 - 1.8254589351141813e-5*_t776 - 1.369094201335636e-5*_t778 - 2.2818236688927266e-6*_t779 - 2.738188402671272e-5*_t784) + _hc1[0]*(2.8619914079993281e-7*_hc2[0]*_hc2[4]*_t1*_t749 + 1.1447965631997312e-6*_hc2[1]*_hc2[3]*_t1*_t749 + 8.5859742239979842e-7*_t1*_t749*_t769 - 4.0067879711990593e-6*_t768 - 6.6779799519984322e-7*_t780 - 2.4040727827194356e-5*_t788 - 8.0135759423981186e-6*_t789 - 6.010181956798589e-6*_t796) + _hc1[0]*(6.3077688511186323e-6*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 4.7308266383389742e-6*_hc2[0]*_t1*_t749*_t769 + 9.4616532766779485e-6*_hc2[2]*_t1*_t213*_t749 + 7.8847110638982904e-7*_hc2[4]*_t1*_t11*_t749 - 5.6319364742130646e-8*_t751 - 2.8384959830033846e-5*_t777 - 1.1827066595847436e-6*_t781 - 1.8923306553355897e-5*_t790 - 1.4192479915016923e-5*_t798 - 8.5154879490101536e-5*_t804) + _hc1[0]*(6.695145390448782e-7*_t760 + 2.6780581561795128e-6*_t761 - 2.4102523405615615e-5*_t768 + 2.0085436171346346e-6*_t770 - 4.0170872342692692e-6*_t780 + 4.4187959576961961e-6*_t782 - 0.00014461514043369369*_t788 - 4.820504681123123e-5*_t789 + 8.8375919153923922e-5*_t791 + 0.00026512775746177177*_t795 - 3.6153785108423423e-5*_t796 + 6.6281939365442942e-5*_t799 + 0.00053025551492354353*_t805) + _hc1[0]*(-6.847659467685992e-9*_t751 + 1.4790944450201743e-6*_t776 - 1.6270038895221917e-5*_t777 + 1.1093208337651307e-6*_t778 + 1.8488680562752178e-7*_t779 - 6.7791828730091321e-7*_t781 + 5.8752918232745811e-7*_t783 + 2.2186416675302614e-6*_t784 - 1.0846692596814611e-5*_t790 + 1.4100700375858995e-5*_t792 + 7.0503501879294973e-5*_t797 - 8.1350194476109585e-6*_t798 + 1.0575525281894246e-5*_t800 - 4.8810116685665751e-5*_t804 + 0.00010575525281894246*_t806) + 4.3363387365448807e-6*_t102*_t408 - 4.5159040132705527e-6*_t102*_t412 + 8.853456072839699e-6*_t103*_t408 + 1.6565068937196516e-6*_t103*_t412 + 2.8537712520038839e-6*_t107*_t408 + 4.4181078898568719e-7*_t107*_t412 + 1.0365080144227026e-6*_t109*_t408 - 4.7129447446055948e-6*_t109*_t412 + _t111*_t809 + _t113*_t809 + 4.0208361399947976e-6*_t117*_t408 + 9.8640738246057703e-7*_t117*_t412 + _t119*_t810 + _t119*_t811 + _t120*_t810 + _t120*_t811 + _t121*_t825 + _t122*_t825 + _t123*_t829 + _t124*_t809 + _t125*_t829 + _t126*_t809 + _t127*_t834 + _t128*_t834 + _t129*_t838 + _t130*_t838 + _t131*_t810 + _t131*_t811 + _t132*_t840 + _t133*_t810 + _t133*_t811 + _t134*_t840 + _t135*_t825 + _t136*_t825 + _t137*_t829 + _t138*_t809 + _t139*_t829 + _t140*_t834 + _t141*_t834 + _t142*_t838 + _t143*_t838 + _t144*_t810 + _t144*_t811 + _t145*_t840 + _t146*_t840 + _t147*_t825 + _t148*_t829 + _t149*_t834 + _t150*_t838 + _t151*_t840 + _t17*_t743 + 2.2318639031838455e-8*_t18*_t751 - 1.8127848593099739e-7*_t18*_t761 - 1.3595886444824805e-7*_t18*_t770 + _t18*(2.12228410889101e-9*_hc2[4]*_t1*_t749 - 8.4891364355640399e-8*_t776 - 6.3668523266730299e-8*_t778 - 1.061142054445505e-8*_t779 - 1.273370465334606e-7*_t784) + _t18*(2.0180501535061202e-7*_hc2[0]*_hc2[4]*_t1*_t749 + 8.0722006140244808e-7*_hc2[1]*_hc2[3]*_t1*_t749 + 6.0541504605183606e-7*_t1*_t749*_t769 - 2.8252702149085683e-6*_t768 - 4.7087836915142805e-7*_t780 - 1.695162128945141e-5*_t788 - 5.6505404298171366e-6*_t789 - 4.2379053223628524e-6*_t796) + _t18*(1.7164188134422286e-7*_t751 - 1.922389071055296e-5*_t776 + 8.6507508197488318e-5*_t777 - 1.441791803291472e-5*_t778 - 2.40298633881912e-6*_t779 + 3.60447950822868e-6*_t781 - 2.883583606582944e-5*_t784 + 5.7671672131658879e-5*_t790 + 4.3253754098744159e-5*_t798 + 0.00025952252459246495*_t804) + _t18*(0.00039126884300919553*_hc2[0]*_hc2[2]*_t1*_t213*_t749 + 0.00013042294766973184*_hc2[1]*_hc2[3]*_t1*_t11*_t749 + 1.0868578972477653e-5*_hc2[4]*_t1*_t12*_t749 + 9.7817210752298882e-5*_t1*_t11*_t749*_t769 + 6.5211473834865922e-5*_t1*_t749*_t767 - 1.8114298287462756e-6*_t760 - 7.2457193149851025e-6*_t761 - 5.4342894862388268e-6*_t770 - 1.1955436869725419e-5*_t782 - 0.00023910873739450837*_t791 - 0.00071732621218352511*_t795 - 0.00017933155304588128*_t799 - 0.0014346524243670503*_t805) + _t18*(0.00094630510655970823*_hc2[0]*_t1*_t749*_t767 + 0.00063087007103980549*_hc2[1]*_hc2[3]*_t1*_t12*_t749 + 0.0028389153196791247*_hc2[2]*_t1*_t11*_t213*_t749 + 3.9429379439987843e-5*_hc2[4]*_t1*_t13*_t749 + 3.9827655999987721e-7*_hc2[4]*_t1*_t749 + 0.00047315255327985411*_t1*_t12*_t749*_t769 - 8.6027736959973474e-5*_t776 - 6.4520802719980105e-5*_t778 - 1.0753467119996684e-5*_t779 - 3.4172128847989464e-5*_t783 - 0.00012904160543996021*_t784 - 0.00082013109235174711*_t792 - 0.0041006554617587356*_t797 - 0.00061509831926381033*_t800 - 0.0061509831926381033*_t806) - 4.5319621482749348e-8*_t19*_t751 + 0.0012637112577023223*_t198*_t204 + _t199*_t801 - _t199*_t807 - _t199*_t808 + _t20*_t743 + _t200*_t801 - _t200*_t807 - _t200*_t808 + 2.6018032419269284e-5*_t204*_t253 + 5.3120736437038194e-5*_t204*_t267 + 1.7122627512023303e-5*_t204*_t273 + 6.2190480865362157e-6*_t204*_t281 + 2.4125016839968785e-5*_t204*_t288 + 4.5170195172342508e-8*_t21*_t751 - 4.7040666804901591e-8*_t21*_t760 - 1.8816266721960636e-7*_t21*_t761 - 1.4112200041470477e-7*_t21*_t770 + _t21*(-7.5472179686313981e-8*_t751 + 3.0188871874525592e-6*_t776 + 2.2641653905894194e-6*_t778 + 3.7736089843156991e-7*_t779 + 4.5283307811788389e-6*_t784) + _t21*(3.4875238653248603e-8*_hc2[0]*_hc2[4]*_t1*_t749 + 1.3950095461299441e-7*_hc2[1]*_hc2[3]*_t1*_t749 + 1.0462571595974581e-7*_t1*_t749*_t769 - 4.8825334114548044e-7*_t768 - 8.1375556857580073e-8*_t780 - 2.9295200468728826e-6*_t788 - 9.7650668229096088e-7*_t789 - 7.3238001171822066e-7*_t796) + _t21*(1.3884594503792214e-7*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 1.0413445877844161e-7*_hc2[0]*_t1*_t749*_t769 + 2.0826891755688321e-7*_hc2[2]*_t1*_t213*_t749 + 1.7355743129740267e-8*_hc2[4]*_t1*_t11*_t749 - 1.2396959378385905e-9*_t751 - 6.2480675267064962e-7*_t777 - 2.6033614694610401e-8*_t781 - 4.1653783511376642e-7*_t790 - 3.1240337633532482e-7*_t798 - 1.8744202580119489e-6*_t804) + _t21*(0.00047146003233532825*_hc2[0]*_hc2[2]*_t1*_t213*_t749 + 0.00015715334411177609*_hc2[1]*_hc2[3]*_t1*_t11*_t749 + 1.3096112009314674e-5*_hc2[4]*_t1*_t12*_t749 + 0.00011786500808383206*_t1*_t11*_t749*_t769 + 7.8576672055888043e-5*_t1*_t749*_t767 - 2.182685334885779e-6*_t760 - 8.7307413395431159e-6*_t761 - 6.548056004657337e-6*_t770 - 1.4405723210246141e-5*_t782 - 0.00028811446420492281*_t791 - 0.00086434339261476844*_t795 - 0.00021608584815369211*_t799 - 0.0017286867852295369*_t805) + _t21*(-4.2432972662190152e-7*_t751 + 9.1655220950330728e-5*_t776 - 0.001008207430453638*_t777 + 6.8741415712748046e-5*_t778 + 1.1456902618791341e-5*_t779 - 4.200864293556825e-5*_t781 + 3.640749054415915e-5*_t783 + 0.00013748283142549609*_t784 - 0.000672138286969092*_t790 + 0.0008737797730598196*_t792 + 0.004368898865299098*_t797 - 0.000504103715226819*_t798 + 0.0006553348297948647*_t800 - 0.003024622291360914*_t804 + 0.006553348297948647*_t806) - _t212*_t802 - _t212*_t813 + _t212*_t821 + _t212*_t824 - _t212*_t828 + _t212*_t832 - _t214*_t802 - _t214*_t813 + _t214*_t821 + _t214*_t824 - _t214*_t828 + _t214*_t832 + _t22*_t819 + _t23*_t743 + _t24*_t793 + _t24*_t794 + _t24*_t803 + _t25*_t743 + 9.2223500758746864e-8*_t26*_t751 + 1.7255280142913038e-8*_t26*_t760 + 6.9021120571652152e-8*_t26*_t761 + 5.1765840428739114e-8*_t26*_t770 + _t26*(1.2761600293730675e-7*_hc2[4]*_t1*_t749 - 5.10464011749227e-6*_t776 - 3.8284800881192025e-6*_t778 - 6.3808001468653375e-7*_t779 - 7.6569601762384049e-6*_t784) + _t26*(-1.3416009834769105e-7*_t760 - 5.3664039339076421e-7*_t761 + 1.8782413768676747e-6*_t768 - 4.0248029504307316e-7*_t770 + 3.1304022947794579e-7*_t780 + 1.1269448261206048e-5*_t788 + 3.7564827537353495e-6*_t789 + 2.8173620653015121e-6*_t796) + _t26*(3.8923684283873404e-6*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 2.9192763212905053e-6*_hc2[0]*_t1*_t749*_t769 + 5.8385526425810106e-6*_hc2[2]*_t1*_t213*_t749 + 4.8654605354841755e-7*_hc2[4]*_t1*_t11*_t749 - 3.4753289539172682e-8*_t751 - 1.7515657927743032e-5*_t777 - 7.2981908032262632e-7*_t781 - 1.1677105285162021e-5*_t790 - 8.7578289638715159e-6*_t798 - 5.2546973783229095e-5*_t804) + _t26*(1.9859997041619591e-7*_t760 + 7.9439988166478364e-7*_t761 - 7.1495989349830527e-6*_t768 + 5.9579991124858773e-7*_t770 - 1.1915998224971755e-6*_t780 + 1.310759804746893e-6*_t782 - 4.2897593609898316e-5*_t788 - 1.4299197869966105e-5*_t789 + 2.621519609493786e-5*_t791 + 7.864558828481358e-5*_t795 - 1.0724398402474579e-5*_t796 + 1.9661397071203395e-5*_t799 + 0.00015729117656962716*_t805) + _t26*(2.9503895769525636e-5*_hc2[0]*_t1*_t749*_t767 + 1.9669263846350424e-5*_hc2[1]*_hc2[3]*_t1*_t12*_t749 + 8.8511687308576907e-5*_hc2[2]*_t1*_t11*_t213*_t749 + 1.2293289903969015e-6*_hc2[4]*_t1*_t13*_t749 + 1.2417464549463651e-8*_hc2[4]*_t1*_t749 + 1.4751947884762818e-5*_t1*_t12*_t749*_t769 - 2.6821723426841487e-6*_t776 - 2.0116292570131115e-6*_t778 - 3.3527154283551859e-7*_t779 - 1.0654184583439813e-6*_t783 - 4.0232585140262231e-6*_t784 - 2.5570043000255551e-5*_t792 - 0.00012785021500127775*_t797 - 1.9177532250191663e-5*_t800 - 0.00019177532250191663*_t806) + _t262*_t815 + _t268*_t816 + _t268*_t817 + _t27*_t831 + _t270*_t827 + _t272*_t830 + _t274*_t833 + _t275*_t815 + _t277*_t835 + _t278*_t839 + _t279*_t816 + _t279*_t817 + _t28*_t819 + _t280*_t827 + _t282*_t830 + _t283*_t815 + _t284*_t833 + _t285*_t835 + _t286*_t816 + _t286*_t817 + _t287*_t839 + _t289*_t827 + _t29*_t793 + _t29*_t794 + _t29*_t803 + _t290*_t830 + _t291*_t833 + _t292*_t815 + _t293*_t835 + _t294*_t839 + _t295*_t816 + _t295*_t817 + _t296*_t827 + _t297*_t830 + _t298*_t815 + _t299*_t833 + 2.9726783875040457e-8*_t30*_t751 + 4.6021957186009082e-9*_t30*_t760 + 1.8408782874403633e-8*_t30*_t761 + 1.3806587155802725e-8*_t30*_t770 + _t30*(5.2560441891672819e-9*_hc2[4]*_t1*_t749 - 2.1024176756669128e-7*_t776 - 1.5768132567501846e-7*_t778 - 2.628022094583641e-8*_t779 - 3.1536265135003691e-7*_t784) + _t30*(9.8485057981065933e-9*_hc2[0]*_hc2[4]*_t1*_t749 + 3.9394023192426373e-8*_hc2[1]*_hc2[3]*_t1*_t749 + 2.954551739431978e-8*_t1*_t749*_t769 - 1.3787908117349231e-7*_t768 - 2.2979846862248718e-8*_t780 - 8.2727448704095382e-7*_t788 - 2.7575816234698461e-7*_t789 - 2.0681862176023846e-7*_t796) + _t30*(1.4637070735451959e-5*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 1.0977803051588969e-5*_hc2[0]*_t1*_t749*_t769 + 2.1955606103177939e-5*_hc2[2]*_t1*_t213*_t749 + 1.8296338419314949e-6*_hc2[4]*_t1*_t11*_t749 - 1.3068813156653535e-7*_t751 - 6.5866818309533816e-5*_t777 - 2.7444507628972423e-6*_t781 - 4.3911212206355877e-5*_t790 - 3.2933409154766908e-5*_t798 - 0.00019760045492860145*_t804) + _t30*(0.00016045587773310387*_hc2[0]*_hc2[2]*_t1*_t213*_t749 + 5.3485292577701291e-5*_hc2[1]*_hc2[3]*_t1*_t11*_t749 + 4.4571077148084409e-6*_hc2[4]*_t1*_t12*_t749 + 4.0113969433275968e-5*_t1*_t11*_t749*_t769 + 2.6742646288850646e-5*_t1*_t749*_t767 - 7.4285128580140682e-7*_t760 - 2.9714051432056273e-6*_t761 - 2.2285538574042205e-6*_t770 - 4.902818486289285e-6*_t782 - 9.80563697257857e-5*_t791 - 0.0002941691091773571*_t795 - 7.3542277294339275e-5*_t799 - 0.0005883382183547142*_t805) + _t30*(-1.5332964222362349e-7*_t751 + 3.3119202720302673e-5*_t776 - 0.0003643112299233294*_t777 + 2.4839402040227005e-5*_t778 + 4.1399003400378341e-6*_t779 - 1.5179634580138725e-5*_t781 + 1.3155683302786895e-5*_t783 + 4.9678804080454009e-5*_t784 - 0.0002428741532822196*_t790 + 0.00031573639926688548*_t792 + 0.0015786819963344274*_t797 - 0.0001821556149616647*_t798 + 0.00023680229945016411*_t800 - 0.0010929336897699882*_t804 + 0.0023680229945016411*_t806) + _t300*_t835 + _t301*_t816 + _t301*_t817 + _t302*_t839 + _t303*_t827 + _t304*_t830 + _t305*_t833 + _t306*_t835 + _t307*_t839 + _t31*_t837 + _t316*_t747 + _t32*_t743 + _t33*_t819 + _t34*_t793 + _t34*_t794 + _t34*_t803 + _t35*_t743 + _t36*_t831 + 1.0796958483569819e-8*_t37*_t751 - 4.9093174422974946e-8*_t37*_t760 - 1.9637269769189978e-7*_t37*_t761 - 1.4727952326892484e-7*_t37*_t770 + _t37*(1.8709184956704667e-8*_hc2[4]*_t1*_t749 - 7.4836739826818673e-7*_t776 - 5.6127554870114005e-7*_t778 - 9.3545924783523342e-8*_t779 - 1.1225510974022801e-6*_t784) + _t37*(-1.8063657765281494e-8*_t760 - 7.2254631061125978e-8*_t761 + 2.5289120871394092e-7*_t768 - 5.4190973295844484e-8*_t770 + 4.214853478565682e-8*_t780 + 1.5173472522836455e-6*_t788 + 5.0578241742788184e-7*_t789 + 3.7933681307091138e-7*_t796) + _t37*(2.8693682403530574e-5*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 2.152026180264793e-5*_hc2[0]*_t1*_t749*_t769 + 4.3040523605295861e-5*_hc2[2]*_t1*_t213*_t749 + 3.5867103004413217e-6*_hc2[4]*_t1*_t11*_t749 - 2.5619359288866585e-7*_t751 - 0.00012912157081588758*_t777 - 5.3800654506619827e-6*_t781 - 8.6081047210591723e-5*_t790 - 6.4560785407943792e-5*_t798 - 0.00038736471244766275*_t804) + _t37*(4.425123151065692e-7*_t760 + 1.7700492604262768e-6*_t761 - 1.5930443343836491e-5*_t768 + 1.3275369453197076e-6*_t770 - 2.6550738906394152e-6*_t780 + 2.9205812797033566e-6*_t782 - 9.5582660063018946e-5*_t788 - 3.1860886687672982e-5*_t789 + 5.8411625594067134e-5*_t791 + 0.0001752348767822014*_t795 - 2.3895665015754736e-5*_t796 + 4.380871919555035e-5*_t799 + 0.00035046975356440279*_t805) + _t37*(1.7948312719387105e-5*_hc2[0]*_t1*_t749*_t767 + 1.1965541812924736e-5*_hc2[1]*_hc2[3]*_t1*_t12*_t749 + 5.3844938158161314e-5*_hc2[2]*_t1*_t11*_t213*_t749 + 7.4784636330779602e-7*_hc2[4]*_t1*_t13*_t749 + 7.5540036697757174e-9*_hc2[4]*_t1*_t749 + 8.9741563596935523e-6*_t1*_t12*_t749*_t769 - 1.631664792671555e-6*_t776 - 1.2237485945036662e-6*_t778 - 2.0395809908394437e-7*_t779 - 6.4813351486675655e-7*_t783 - 2.4474971890073324e-6*_t784 - 1.5555204356802157e-5*_t792 - 7.7776021784010786e-5*_t797 - 1.1666403267601618e-5*_t800 - 0.00011666403267601618*_t806) + _t38*_t842 + _t39*_t793 + _t39*_t794 + _t39*_t803 + _t4*_t743 + _t40*_t819 + 0.00021061854295038705*_t408*_t85 + 6.427768041169475e-6*_t408*_t86 + _t41*_t837 + 0.020219380123237157*_t410*_t92 - 0.0065678021259147985*_t410*_t94 - 6.8414605478279151e-5*_t412*_t85 - 1.3052050987031813e-5*_t412*_t86 - _t413*_t451 - _t413*_t453 - _t413*_t471 + _t413*_t474 + _t413*_t485 - _t413*_t488 + _t413*_t495 + 0.0006170657319522696*_t414*_t92 - 0.001252996894755054*_t414*_t94 + 0.0018511971958568088*_t415*_t92 - 0.0037589906842651621*_t415*_t94 + _t42*_t831 + 4.1883709791612475e-8*_t43*_t751 + 1.0275076900631011e-8*_t43*_t760 + 4.1100307602524043e-8*_t43*_t761 + 3.0825230701893032e-8*_t43*_t770 + _t43*(-1.168773310983313e-8*_t751 + 4.6750932439332521e-7*_t776 + 3.506319932949939e-7*_t778 + 5.8438665549165651e-8*_t779 + 7.012639865899878e-7*_t784) + _t43*(2.4315013352169217e-9*_hc2[0]*_hc2[4]*_t1*_t749 + 9.7260053408676867e-9*_hc2[1]*_hc2[3]*_t1*_t749 + 7.2945040056507651e-9*_t1*_t749*_t769 - 3.4041018693036904e-8*_t768 - 5.6735031155061507e-9*_t780 - 2.0424611215822142e-7*_t788 - 6.8082037386073808e-8*_t789 - 5.1061528039555356e-8*_t796) + _t43*(1.9725700241059539e-6*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 1.4794275180794654e-6*_hc2[0]*_t1*_t749*_t769 + 2.9588550361589308e-6*_hc2[2]*_t1*_t213*_t749 + 2.4657125301324424e-7*_hc2[4]*_t1*_t11*_t749 - 1.7612232358088874e-8*_t751 - 8.8765651084767926e-6*_t777 - 3.6985687951986635e-7*_t781 - 5.9177100723178617e-6*_t790 - 4.4382825542383963e-6*_t798 - 2.6629695325430377e-5*_t804) + _t43*(9.3087352203160168e-6*_hc2[0]*_hc2[2]*_t1*_t213*_t749 + 3.1029117401053389e-6*_hc2[1]*_hc2[3]*_t1*_t11*_t749 + 2.5857597834211158e-7*_hc2[4]*_t1*_t12*_t749 + 2.3271838050790042e-6*_t1*_t11*_t749*_t769 + 1.5514558700526695e-6*_t1*_t749*_t767 - 4.3095996390351929e-8*_t760 - 1.7238398556140772e-7*_t761 - 1.2928798917105579e-7*_t770 - 2.8443357617632273e-7*_t782 - 5.6886715235264547e-6*_t791 - 1.7066014570579364e-5*_t795 - 4.266503642644841e-6*_t799 - 3.4132029141158728e-5*_t805) + _t43*(2.7706187539717458e-5*_hc2[0]*_t1*_t749*_t767 + 1.8470791693144972e-5*_hc2[1]*_hc2[3]*_t1*_t12*_t749 + 8.3118562619152374e-5*_hc2[2]*_t1*_t11*_t213*_t749 + 1.1544244808215608e-6*_hc2[4]*_t1*_t13*_t749 + 1.1660853341631927e-8*_hc2[4]*_t1*_t749 + 1.3853093769858729e-5*_t1*_t12*_t749*_t769 - 2.5187443217924962e-6*_t776 - 1.8890582413443721e-6*_t778 - 3.1484304022406202e-7*_t779 - 1.0005012167120193e-6*_t783 - 3.7781164826887443e-6*_t784 - 2.4012029201088464e-5*_t792 - 0.00012006014600544232*_t797 - 1.8009021900816348e-5*_t800 - 0.00018009021900816348*_t806) + _t44*_t843 + _t45*_t819 + _t46*_t793 + _t46*_t794 + _t46*_t803 + _t47*_t837 + _t48*_t831 + _t49*_t842 + _t490*_t812 + 0.00041628851870830855*_t492*_t92 - 0.00043352678527397305*_t492*_t94 + _t499*_t814 + _t50*_t793 + _t50*_t794 + _t50*_t803 + _t500*_t818 + _t501*_t812 + _t502*_t820 + _t504*_t822 + 0.0008499317829926111*_t505*_t92 + 0.00015902466179708655*_t505*_t94 + _t51*_t819 + _t510*_t823 + _t511*_t814 + _t512*_t826 + _t513*_t818 + _t514*_t820 + _t519*_t822 + _t52*_t831 + _t520*_t823 + _t522*_t812 + _t524*_t826 + 0.00027396204019237285*_t526*_t92 + 4.241383574262597e-5*_t526*_t94 + _t529*_t814 + _t53*_t837 + _t531*_t818 + _t532*_t812 + _t533*_t820 + _t534*_t822 + 9.950476938457945e-5*_t537*_t92 - 0.0004524426954821371*_t537*_t94 + _t538*_t823 + _t539*_t814 + _t54*_t843 + _t540*_t826 + _t541*_t818 + _t543*_t820 + _t544*_t822 + _t545*_t823 + _t547*_t812 + _t548*_t826 + 0.00038600026943950057*_t549*_t92 + 9.4695108716215395e-5*_t549*_t94 + _t55*_t842 + _t550*_t814 + _t551*_t818 + _t552*_t820 + _t553*_t822 + _t554*_t823 + _t555*_t826 + _t56*_t819 + _t566*_t745 + _t57*_t837 + _t58*_t843 + _t581*_t746 + _t59*_t831 + _t60*_t842 + _t61*_t831 + _t62*_t837 + _t63*_t843 + _t64*_t842 + _t65*_t837 + _t66*_t843 + _t67*_t842 + _t68*_t842 + _t69*_t843 + _t70*_t843 + _t73*_t744 + 0.19451907596748125*_t743 + 0.012711844558663082*_t744 + 0.050847378234652328*_t745 - 0.29489505036137591*_t746 + 0.038135533675989246*_t747 - 0.14215528919928176*_t748 - 2.4188103108246335e-6*_t751 + 6.2735740595649168*_t752 - 0.10661646689946132*_t753 - 0.01776941114991022*_t754 - 0.049149175060229318*_t755 + 0.2613989191485382*_t756 + 0.026485532388814615*_t757 - 0.3801267001217285*_t758 - 0.21323293379892264*_t759 - 1.3827741947123216e-5*_t760 - 5.5310967788492865e-5*_t761 - 1.7693703021682555*_t762 - 0.58979010072275182*_t763 + 4.1823827063766111*_t764 + 0.5297106477762923*_t765 - 9.123040802921484*_t766 - 2.4776248368798873e-5*_t768 - 4.1483225841369649e-5*_t770 - 0.44234257554206386*_t771 - 45.61520401460742*_t772 + 3.1367870297824584*_t773 + 0.39728298583221922*_t774 - 6.842280602191113*_t775 - 3.4928417095983417e-6*_t776 + 0.00010893499798325372*_t777 - 2.6196312821987563e-6*_t778 - 4.3660521369979271e-7*_t779 - 4.1293747281331455e-6*_t780 + 4.5389582493022382e-6*_t781 + 7.9210732137625384e-6*_t782 - 5.089507106811241e-6*_t783 - 5.2392625643975125e-6*_t784 + 18.820722178694751*_t785 + 3.1782638866577538*_t786 - 68.422806021911128*_t787 - 0.00014865749021279323*_t788 - 4.9552496737597745e-5*_t789 + 7.2623331988835812e-5*_t790 + 0.00015842146427525077*_t791 - 0.00012214817056346978*_t792 + 0.0004752643928257523*_t795 - 3.7164372553198308e-5*_t796 - 0.00061074085281734892*_t797 + 5.4467498991626859e-5*_t798 + 0.00011881609820643808*_t799 - 9.1611127922602337e-5*_t800 + 0.00032680499394976115*_t804 + 0.0009505287856515046*_t805 - 0.00091611127922602337*_t806;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mcml_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mbeef_expansion_pf_k, _KMAX)(p, x2, t, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1];
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx2 = _hc0[2];
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[3];
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx2_dt = _hc0[4];
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = 0;
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = _hc0[5];
  out[9] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[6];
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx2_dt2 = _hc0[7];
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = 0;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = 0;
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = _hc0[8];
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = 0;
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = _hc0[9];
  out[19] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc0[10];
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx2_dt3 = _hc0[11];
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = 0;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = 0;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = 0;
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = _hc0[12];
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = 0;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = 0;
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = _hc0[13];
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = 0;
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = _hc0[14];
  out[34] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = xc_powr(n_s, -8, 3);
  const double _t6 = xc_powr(n_s, -5, 3);
  const double _t7 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t11 = xc_powr(n_s, -4, 3);
  const double _t14 = (0.5e1 / 0.3e1)*_t5;
  const double _t16 = xc_powr(n_s, -11, 3);
  const double _t17 = (0.8e1 / 0.3e1)*_t16;
#endif
#if _KMAX >= 2
  const double _t21 = xc_powr(n_s, -10, 3);
  const double _t23 = xc_powr(n_s, -13, 3);
  const double _t25 = xc_powr(n_s, -16, 3);
  const double _t27 = (0.5e1 / 0.3e1)*tau_s;
  const double _t28 = _t23*_t27;
  const double _t29 = (0.8e1 / 0.3e1)*sigma_ss;
  const double _t33 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t34 = xc_powr(n_s, -19, 3);
  const double _t35 = _t29*_t34;
  const double _t39 = xc_powr(n_s, -7, 3);
  const double _t42 = xc_powr(0.6e1, 2, 3);
  const double _t43 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t47 = (0.1e1 / 0.3e1)*_t11;
  const double _t48 = (0.40e2 / 0.9e1)*_t16;
  const double _t50 = xc_powr(n_s, -14, 3);
  const double _t51 = (0.88e2 / 0.9e1)*_t50;
#endif
#if _KMAX >= 3
  const double _t63 = xc_powi(n_s, -5);
  const double _t65 = xc_powi(n_s, -6);
  const double _t67 = xc_powi(n_s, -7);
  const double _t69 = xc_powi(n_s, -8);
  const double _t71 = (0.10e2 / 0.3e1)*_t23;
  const double _t76 = xc_powr(n_s, -17, 3);
  const double _t77 = (0.13e2 / 0.3e1)*_t25;
  const double _t81 = xc_powr(n_s, -20, 3);
  const double _t82 = (0.16e2 / 0.3e1)*_t34;
  const double _t83 = xc_powi(n_s, -9);
  const double _t91 = (0.40e2 / 0.9e1)*tau_s;
  const double _t93 = (0.88e2 / 0.9e1)*sigma_ss;
  const double _t94 = _t25*_t29;
  const double _t98 = _t14*tau_s;
  const double _t101 = xc_powr(n_s, -22, 3);
  const double _t103 = _t25*_t27;
  const double _t105 = _t17*sigma_ss;
  const double _t115 = (0.440e3 / 0.27e2)*_t50;
  const double _t117 = (0.1232e4 / 0.27e2)*_t76;
#endif
#if _KMAX >= 4
  const double _t142 = xc_powr(n_s, -23, 3);
  const double _t143 = xc_powr(n_s, -26, 3);
  const double _t144 = xc_powr(n_s, -29, 3);
  const double _t145 = xc_powr(n_s, -32, 3);
  const double _t149 = xc_powr(n_s, -25, 3);
  const double _t154 = _t29*_t67;
  const double _t156 = _t29*_t69;
  const double _t160 = (0.440e3 / 0.27e2)*tau_s;
  const double _t161 = (0.1232e4 / 0.27e2)*sigma_ss;
  const double _t164 = _t34*_t93;
  const double _t168 = _t115*tau_s;
  const double _t169 = _t117*sigma_ss;
  const double _t170 = _t48*tau_s;
  const double _t171 = _t51*sigma_ss;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t7)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t7)) XC_CAT(mcml_f_pf_k, _KMAX)(p, _t5*sigma_ss, 0, _t6*tau_s, _hc1);
  const double _t8 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t9 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[1]*_t6);
  const double _t10 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[3]*_t5);
  const double _t12 = _hc0[2]*_t3;
  const double _t13 = (0.1e1 / 0.6e1)*_t12;
  const double _t15 = _hc1[1]*_t14;
  const double _t18 = _hc1[3]*_t17;
  const double _t19 = -_t15*tau_s - _t18*sigma_ss;
  const double _t20 = my_piecewise3(_t7, 0, _hc0[0]*_t19 - _hc1[0]*_t11*_t13);
#endif
#if _KMAX >= 2
  const double _t22 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[4]*_t21);
  const double _t24 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[7]*_t23);
  const double _t26 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[9]*_t25);
  const double _t30 = _hc1[7]*_t25;
  const double _t31 = -_hc1[4]*_t28 - _t15 - _t29*_t30;
  const double _t32 = my_piecewise3(_t7, 0, _hc0[0]*_t31 - _hc1[1]*_t13/(n_s * n_s * n_s));
  const double _t36 = -_hc1[9]*_t35 - _t18 - _t27*_t30;
  const double _t37 = my_piecewise3(_t7, 0, _hc0[0]*_t36 - _hc1[3]*_t13*_t33);
  const double _t38 = (0.2e1 / 0.9e1)*_hc1[0];
  const double _t40 = _t12*_t39;
  const double _t41 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t44 = _hc0[5]*_t42*_t43;
  const double _t45 = _t44*_t5;
  const double _t46 = _t12*_t19;
  const double _t49 = _hc1[1]*_t48;
  const double _t52 = _hc1[3]*_t51;
  const double _t53 = _hc1[7]*_t14;
  const double _t54 = _hc1[9]*_t17;
  const double _t55 = -_t53*tau_s - _t54*sigma_ss;
  const double _t56 = _t17*_t55;
  const double _t57 = _hc1[4]*_t14;
  const double _t58 = _hc1[7]*_t17;
  const double _t59 = -_t57*tau_s - _t58*sigma_ss;
  const double _t60 = _t14*_t59;
  const double _t61 = _t49*tau_s + _t52*sigma_ss - _t56*sigma_ss - _t60*tau_s;
  const double _t62 = my_piecewise3(_t7, 0, _hc0[0]*_t61 + _t38*_t40 + _t41*_t45 - _t46*_t47);
#endif
#if _KMAX >= 3
  const double _t64 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[10]*_t63);
  const double _t66 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[14]*_t65);
  const double _t68 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[17]*_t67);
  const double _t70 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[19]*_t69);
  const double _t72 = _hc1[10]*_t65;
  const double _t73 = _hc1[14]*_t67;
  const double _t74 = -_hc1[4]*_t71 - _t27*_t72 - _t29*_t73;
  const double _t75 = my_piecewise3(_t7, 0, _hc0[0]*_t74 - _hc1[4]*_t13*_t50);
  const double _t78 = _hc1[17]*_t69;
  const double _t79 = -_hc1[7]*_t77 - _t27*_t73 - _t29*_t78;
  const double _t80 = my_piecewise3(_t7, 0, _hc0[0]*_t79 - _hc1[7]*_t13*_t76);
  const double _t84 = _hc1[19]*_t83;
  const double _t85 = -_hc1[9]*_t82 - _t27*_t78 - _t29*_t84;
  const double _t86 = my_piecewise3(_t7, 0, _hc0[0]*_t85 - _hc1[9]*_t13*_t81);
  const double _t87 = (0.2e1 / 0.9e1)*_t12;
  const double _t88 = (0.1e1 / 0.36e2)*_t44;
  const double _t89 = _t12*_t47;
  const double _t90 = _hc1[4]*_t25;
  const double _t92 = _hc1[7]*_t34;
  const double _t95 = -_hc1[14]*_t28 - _hc1[17]*_t94 - _t53;
  const double _t96 = _t17*_t95;
  const double _t97 = -_hc1[10]*_t28 - _hc1[14]*_t94 - _t57;
  const double _t99 = _t49 - _t60 + _t90*_t91 + _t92*_t93 - _t96*sigma_ss - _t97*_t98;
  const double _t100 = my_piecewise3(_t7, 0, _hc0[0]*_t99 + _hc1[1]*_t23*_t88 + _hc1[1]*_t33*_t87 - _t31*_t89);
  const double _t102 = _hc1[9]*_t101;
  const double _t104 = -_hc1[17]*_t103 - _hc1[19]*_t35 - _t54;
  const double _t106 = -_hc1[14]*_t103 - _hc1[17]*_t35 - _t58;
  const double _t107 = _t106*_t14;
  const double _t108 = _t102*_t93 - _t104*_t105 - _t107*tau_s + _t52 - _t56 + _t91*_t92;
  const double _t109 = my_piecewise3(_t7, 0, _hc0[0]*_t108 + _hc1[3]*_t25*_t88 + _hc1[3]*_t63*_t87 - _t36*_t89);
  const double _t110 = _hc0[9]/M_PI;
  const double _t111 = _t110*_t33;
  const double _t112 = (0.14e2 / 0.27e2)*_t12;
  const double _t113 = (0.1e1 / 0.9e1)*_t44;
  const double _t114 = _hc0[2]*_t11*_t4;
  const double _t116 = _hc1[1]*_t115;
  const double _t118 = _hc1[3]*_t117;
  const double _t119 = _hc1[7]*_t48;
  const double _t120 = _hc1[9]*_t51;
  const double _t121 = _hc1[17]*_t14;
  const double _t122 = _hc1[19]*_t17;
  const double _t123 = -_t121*tau_s - _t122*sigma_ss;
  const double _t124 = _t123*_t17;
  const double _t125 = _hc1[14]*_t14;
  const double _t126 = _hc1[17]*_t17;
  const double _t127 = -_t125*tau_s - _t126*sigma_ss;
  const double _t128 = _t127*_t14;
  const double _t129 = _t119*tau_s + _t120*sigma_ss - _t124*sigma_ss - _t128*tau_s;
  const double _t130 = _t129*_t17;
  const double _t131 = _hc1[4]*_t48;
  const double _t132 = _hc1[7]*_t51;
  const double _t133 = _t127*_t17;
  const double _t134 = _hc1[10]*_t14;
  const double _t135 = _hc1[14]*_t17;
  const double _t136 = -_t134*tau_s - _t135*sigma_ss;
  const double _t137 = _t136*_t14;
  const double _t138 = _t131*tau_s + _t132*sigma_ss - _t133*sigma_ss - _t137*tau_s;
  const double _t139 = _t138*_t14;
  const double _t140 = -_t116*tau_s - _t118*sigma_ss - _t130*sigma_ss - _t139*tau_s + (0.80e2 / 0.9e1)*_t16*_t59*tau_s + (0.176e3 / 0.9e1)*_t50*_t55*sigma_ss;
  const double _t141 = my_piecewise3(_t7, 0, _hc0[0]*_t140 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t19*_t2*_t39 + (0.1e1 / 0.12e2)*_hc0[5]*_t19*_t42*_t43*_t5 - _hc1[0]*_t112*_t21 - _hc1[0]*_t113*_t16 - _t111*_t41 - _t114*_t61);
#endif
#if _KMAX >= 4
  const double _t146 = _hc1[20]*_t27;
  const double _t147 = _hc1[25]*_t143;
  const double _t148 = _hc1[29]*_t144;
  const double _t150 = _hc1[32]*_t145;
  const double _t151 = _hc1[34]*_t29;
  const double _t152 = _hc1[10]*_t91;
  const double _t153 = _hc1[25]*_t27;
  const double _t155 = _hc1[29]*_t27;
  const double _t157 = _hc1[19]*_t93;
  const double _t158 = _hc1[1]*_t76;
  const double _t159 = (0.1e1 / 0.36e2)*_t110;
  const double _t162 = _hc1[7]*_t101;
  const double _t163 = _hc1[14]*_t91;
  const double _t165 = -_hc1[25]*_t28 - _hc1[29]*_t94 - _t125;
  const double _t166 = _hc1[3]*_t81;
  const double _t167 = -_hc1[29]*_t103 - _hc1[32]*_t35 - _t126;
  const double _t172 = -_hc1[29]*_t98 - _hc1[32]*_t105;
  const double _t173 = -_hc1[25]*_t98 - _hc1[29]*_t105;
  const double _t174 = _hc1[14]*_t170 + _hc1[17]*_t171 - _t105*_t172 - _t173*_t98;
#endif

  const double f = my_piecewise3(_t7, 0, _t8*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t7, 0, _t9*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t7, 0, _t10*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t7, 0, _t20*n_s + _t8);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t7, 0, _t22*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t7, 0, _t24*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t7, 0, _t26*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t7, 0, _t32*n_s + _t9);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t7, 0, _t10 + _t37*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t7, 0, 0.2e1*_t20 + _t62*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t7, 0, _t64*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t7, 0, _t66*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t7, 0, _t68*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t7, 0, _t70*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t7, 0, _t22 + _t75*n_s);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t7, 0, _t24 + _t80*n_s);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t7, 0, _t26 + _t86*n_s);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t7, 0, _t100*n_s + 0.2e1*_t32);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t7, 0, _t109*n_s + 0.2e1*_t37);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t7, 0, _t141*n_s + 0.3e1*_t62);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[0]*_hc1[20]*_t81));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[0]*_hc1[25]*_t142));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[0]*_hc1[29]*_t143));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[0]*_hc1[32]*_t144));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[0]*_hc1[34]*_t145));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t7, 0, _t64 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(-_t142*_t146 - _t147*_t29 - 0.5e1*_t72) - _hc1[10]*_t13*_t34));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t7, 0, _t66 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(-_t147*_t27 - _t148*_t29 - 0.6e1*_t73) - _hc1[14]*_t101*_t13));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t7, 0, _t68 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(-_t148*_t27 - _t150*_t29 - 0.7e1*_t78) - _hc1[17]*_t13*_t149));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t7, 0, _t70 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(-_t150*_t27 - _t151/xc_powr(n_s, 35, 3) - 0.8e1*_t84) - _hc1[19]*_t13/xc_powr(n_s, 28, 3)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t7, 0, 0.2e1*_t75 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(_hc1[14]*_t69*_t93 - _t105*(-_hc1[14]*_t71 - _hc1[29]*_t154 - _t153*_t65) + _t152*_t67 - 0.10e2 / 0.3e1*_t5*_t97 + (0.80e2 / 0.9e1)*_t90 - _t98*(-_hc1[10]*_t71 - _hc1[25]*_t154 - _t146*_t65)) + _hc1[4]*_t65*_t88 + _hc1[4]*_t76*_t87 - _t74*_t89));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t7, 0, 0.2e1*_t80 + n_s*my_piecewise3(_t7, 0, _hc0[0]*((0.40e2 / 0.9e1)*_hc1[14]*_t69*tau_s + (0.88e2 / 0.9e1)*_hc1[17]*_t83*sigma_ss + (0.128e3 / 0.9e1)*_hc1[7]*_t34 - _t105*(-_hc1[17]*_t77 - _hc1[32]*_t156 - _t155*_t67) - _t107 - _t96 - _t98*(-_hc1[14]*_t77 - _hc1[29]*_t156 - _t153*_t67)) + _hc1[7]*_t67*_t88 + _hc1[7]*_t81*_t87 - _t79*_t89));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t7, 0, 0.2e1*_t86 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(_hc1[17]*_t83*_t91 + (0.176e3 / 0.9e1)*_t102 - 0.16e2 / 0.3e1*_t104*_t16 - _t105*(-_hc1[19]*_t82 - _hc1[32]*_t27*_t69 - _t151*_t83) + _t157/xc_powi(n_s, 10) - _t98*(-_hc1[17]*_t82 - _hc1[32]*_t29*_t83 - _t155*_t69)) + _hc1[9]*_t142*_t87 + _hc1[9]*_t69*_t88 - _t85*_t89));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t7, 0, 0.3e1*_t100 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(-_hc1[4]*_t160*_t34 - _t105*(_hc1[17]*_t164 - _t105*(-_hc1[29]*_t28 - _hc1[32]*_t94 - _t121) + _t119 - _t128 + _t163*_t25 - _t165*_t98) - _t116 - _t139 + (0.80e2 / 0.9e1)*_t16*_t59 + (0.80e2 / 0.9e1)*_t16*_t97*tau_s - _t161*_t162 + (0.176e3 / 0.9e1)*_t50*_t95*sigma_ss - _t98*(_hc1[14]*_t164 - _t105*_t165 + _t131 - _t137 + _t152*_t25 - _t98*(-_hc1[20]*_t28 - _hc1[25]*_t94 - _t134))) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t31*_t39 + (0.1e1 / 0.12e2)*_hc0[5]*_t31*_t42*_t43*_t5 - _hc1[1]*_t112*_t63 - _hc1[1]*_t113*_t25 - _t114*_t99 - _t158*_t159));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t7, 0, 0.3e1*_t109 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(-_hc1[9]*_t149*_t161 + (0.176e3 / 0.9e1)*_t104*_t50*sigma_ss - _t105*(_hc1[17]*_t34*_t91 + _t101*_t157 - _t105*(-_hc1[32]*_t103 - _hc1[34]*_t35 - _t122) + _t120 - _t124 - _t167*_t98) + (0.80e2 / 0.9e1)*_t106*_t16*tau_s - _t118 - _t130 - _t160*_t162 + (0.176e3 / 0.9e1)*_t50*_t55 - _t98*(_hc1[17]*_t101*_t93 - _t105*_t167 + _t132 - _t133 + _t163*_t34 - _t98*(-_hc1[25]*_t103 - _hc1[29]*_t35 - _t135))) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t36*_t39 + (0.1e1 / 0.12e2)*_hc0[5]*_t36*_t42*_t43*_t5 - _hc1[3]*_t112*_t65 - _hc1[3]*_t113*_t34 - _t108*_t114 - _t159*_t166));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t7, 0, 0.4e1*_t141 + n_s*my_piecewise3(_t7, 0, _hc0[0]*(-_t105*(-_hc1[7]*_t168 - _hc1[9]*_t169 - _t105*(_hc1[17]*_t170 + _hc1[19]*_t171 - _t105*(-_hc1[32]*_t98 - _hc1[34]*_t105) - _t172*_t98) + (0.176e3 / 0.9e1)*_t123*_t50*sigma_ss + (0.80e2 / 0.9e1)*_t127*_t16*tau_s - _t174*_t98) + (0.88e2 / 0.3e1)*_t129*_t50*sigma_ss + (0.40e2 / 0.3e1)*_t138*_t16*tau_s + (0.6160e4 / 0.81e2)*_t158*tau_s + (0.20944e5 / 0.81e2)*_t166*sigma_ss - 0.440e3 / 0.9e1*_t50*_t59*tau_s - 0.1232e4 / 0.9e1*_t55*_t76*sigma_ss - _t98*(-_hc1[4]*_t168 - _hc1[7]*_t169 - _t105*_t174 + (0.176e3 / 0.9e1)*_t127*_t50*sigma_ss + (0.80e2 / 0.9e1)*_t136*_t16*tau_s - _t98*(_hc1[10]*_t170 + _hc1[14]*_t171 - _t105*_t173 - _t98*(-_hc1[20]*_t98 - _hc1[25]*_t105)))) + (0.1e1 / 0.216e3)*_hc0[14]*_hc1[0]*_t1*_t25/(M_PI * M_CBRTPI) + (0.140e3 / 0.81e2)*_hc1[0]*_t12*_t23 + (0.40e2 / 0.81e2)*_hc1[0]*_t44*_t50 - 0.2e1 / 0.3e1*_t11*_t12*_t140 + _t110*_t38*_t63 - 0.1e1 / 0.9e1*_t111*_t19 - 0.4e1 / 0.9e1*_t16*_t19*_t44 - 0.56e2 / 0.27e2*_t21*_t46 + (0.4e1 / 0.3e1)*_t40*_t61 + (0.1e1 / 0.6e1)*_t45*_t61));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double ta = tau[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / 0.4e1)*gaa;
  const double _t3 = (0.1e1 / 0.2e1)*ta;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, 0, _t3, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[3];
  const double dF_dta = _hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, (0.1e1 / 0.2e1)*la, _t3, _hc1);
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc1[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dta = (0.1e1 / 0.2e1)*_hc0[11];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[10];
  const double d2F_dgaa_dta = (0.1e1 / 0.4e1)*_hc0[8];
  const double d2F_dta2 = (0.1e1 / 0.2e1)*_hc0[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc1[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc1[33];
  const double d3F_dna2_dta = (0.1e1 / 0.4e1)*_hc1[31];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dta = (0.1e1 / 0.8e1)*_hc0[28];
  const double d3F_dna_dta2 = (0.1e1 / 0.4e1)*_hc0[25];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[24];
  const double d3F_dgaa2_dta = (0.1e1 / 0.16e2)*_hc0[22];
  const double d3F_dgaa_dta2 = (0.1e1 / 0.8e1)*_hc0[19];
  const double d3F_dta3 = (0.1e1 / 0.4e1)*_hc0[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc1[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc1[68];
  const double d4F_dna3_dta = (0.1e1 / 0.8e1)*_hc1[66];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc1[65];
  const double d4F_dna2_dgaa_dta = (0.1e1 / 0.16e2)*_hc1[63];
  const double d4F_dna2_dta2 = (0.1e1 / 0.8e1)*_hc1[60];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dta = (0.1e1 / 0.32e2)*_hc0[57];
  const double d4F_dna_dgaa_dta2 = (0.1e1 / 0.16e2)*_hc0[54];
  const double d4F_dna_dta3 = (0.1e1 / 0.8e1)*_hc0[50];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[49];
  const double d4F_dgaa3_dta = (0.1e1 / 0.64e2)*_hc0[47];
  const double d4F_dgaa2_dta2 = (0.1e1 / 0.32e2)*_hc0[44];
  const double d4F_dgaa_dta3 = (0.1e1 / 0.16e2)*_hc0[40];
  const double d4F_dta4 = (0.1e1 / 0.8e1)*_hc0[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;
  const double ta = tau[0];
  const double tb = tau[1];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, 0, ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, 0, tb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc0[3];
  const double dF_dgbb = _hc1[3];
  const double dF_dta = _hc0[1];
  const double dF_dtb = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, ta, _hc2);
  double _hc3[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, lb, tb, _hc3);
  const double d2F_dna2 = _hc2[14];
  const double d2F_dnb2 = _hc3[14];
  const double d2F_dna_dgaa = _hc0[13];
  const double d2F_dnb_dgbb = _hc1[13];
  const double d2F_dna_dta = _hc0[11];
  const double d2F_dnb_dtb = _hc1[11];
  const double d2F_dgaa2 = _hc0[10];
  const double d2F_dgbb2 = _hc1[10];
  const double d2F_dgaa_dta = _hc0[8];
  const double d2F_dgbb_dtb = _hc1[8];
  const double d2F_dta2 = _hc0[5];
  const double d2F_dtb2 = _hc1[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 5] += d2F_dgbb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc2[34];
  const double d3F_dnb3 = _hc3[34];
  const double d3F_dna2_dgaa = _hc2[33];
  const double d3F_dnb2_dgbb = _hc3[33];
  const double d3F_dna2_dta = _hc2[31];
  const double d3F_dnb2_dtb = _hc3[31];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dta = _hc0[28];
  const double d3F_dnb_dgbb_dtb = _hc1[28];
  const double d3F_dna_dta2 = _hc0[25];
  const double d3F_dnb_dtb2 = _hc1[25];
  const double d3F_dgaa3 = _hc0[24];
  const double d3F_dgbb3 = _hc1[24];
  const double d3F_dgaa2_dta = _hc0[22];
  const double d3F_dgbb2_dtb = _hc1[22];
  const double d3F_dgaa_dta2 = _hc0[19];
  const double d3F_dgbb_dtb2 = _hc1[19];
  const double d3F_dta3 = _hc0[15];
  const double d3F_dtb3 = _hc1[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += d3F_dnb_dgbb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 11] += d3F_dgbb2_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 8] += d3F_dgbb_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 3] += d3F_dtb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc2[69];
  const double d4F_dnb4 = _hc3[69];
  const double d4F_dna3_dgaa = _hc2[68];
  const double d4F_dnb3_dgbb = _hc3[68];
  const double d4F_dna3_dta = _hc2[66];
  const double d4F_dnb3_dtb = _hc3[66];
  const double d4F_dna2_dgaa2 = _hc2[65];
  const double d4F_dnb2_dgbb2 = _hc3[65];
  const double d4F_dna2_dgaa_dta = _hc2[63];
  const double d4F_dnb2_dgbb_dtb = _hc3[63];
  const double d4F_dna2_dta2 = _hc2[60];
  const double d4F_dnb2_dtb2 = _hc3[60];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dta = _hc0[57];
  const double d4F_dnb_dgbb2_dtb = _hc1[57];
  const double d4F_dna_dgaa_dta2 = _hc0[54];
  const double d4F_dnb_dgbb_dtb2 = _hc1[54];
  const double d4F_dna_dta3 = _hc0[50];
  const double d4F_dnb_dtb3 = _hc1[50];
  const double d4F_dgaa4 = _hc0[49];
  const double d4F_dgbb4 = _hc1[49];
  const double d4F_dgaa3_dta = _hc0[47];
  const double d4F_dgbb3_dtb = _hc1[47];
  const double d4F_dgaa2_dta2 = _hc0[44];
  const double d4F_dgbb2_dtb2 = _hc1[44];
  const double d4F_dgaa_dta3 = _hc0[40];
  const double d4F_dgbb_dtb3 = _hc1[40];
  const double d4F_dta4 = _hc0[35];
  const double d4F_dtb4 = _hc1[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += d4F_dnb2_dgbb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += d4F_dnb_dgbb2_dtb;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += d4F_dnb_dgbb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += d4F_dnb_dtb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 19] += d4F_dgbb3_dtb;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 17] += d4F_dgbb2_dtb2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 11] += d4F_dgbb_dtb3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 4] += d4F_dtb4;
#endif
#endif
}
#endif