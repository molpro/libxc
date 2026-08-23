/*
  Generated from python/mgga_exc/mgga_x_mcml.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_mcml
*/

#ifndef _MGGA_X_MCML_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_MCML_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_MCML_HELPER_BODIES
#include "mgga_x_mcml.c"
#undef _MGGA_X_MCML_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_MCML_HELPER_BODIES
#include "mgga_x_mcml.c"
#undef _MGGA_X_MCML_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_MCML_HELPER_BODIES
#include "mgga_x_mcml.c"
#undef _MGGA_X_MCML_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_MCML_HELPER_BODIES
#include "mgga_x_mcml.c"
#undef _MGGA_X_MCML_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_MCML_HELPER_BODIES
#include "mgga_x_mcml.c"
#undef _MGGA_X_MCML_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_mcml.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_MCML_HELPER_BODIES)

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
  const double _t220 = 7.489378428659823e-5*_hc1[0];
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
  const double _t360 = -0.3e1 / 0.2e1*_t340 + 0.15e2*_t343 + 0.45e2*_t344 + (0.15e2 / 0.2e1)*_t346;
  const double _t361 = -0.15e2 / 0.2e1*_t341 - 0.45e2 / 0.2e1*_t342 + 0.105e3*_t345 + (0.35e2 / 0.2e1)*_t347 + (0.315e3 / 0.2e1)*_t351;
  const double _t362 = (0.945e3 / 0.2e1)*_t343;
  const double _t363 = (0.15e2 / 0.8e1)*_t340 - 0.105e3 / 0.2e1*_t343 - 0.315e3 / 0.2e1*_t344 - 0.105e3 / 0.4e1*_t346 + (0.315e3 / 0.8e1)*_t348 + (0.945e3 / 0.2e1)*_t352 + _t362*_t5;
  const double _t364 = -_hc1[0]*_t362 + (0.105e3 / 0.8e1)*_t341 + (0.315e3 / 0.8e1)*_t342 - 0.315e3 / 0.4e1*_t347 + (0.693e3 / 0.8e1)*_t349 - 0.2835e4 / 0.4e1*_t351 + (0.10395e5 / 0.8e1)*_t353 + (0.3465e4 / 0.2e1)*_t356;
  const double _t365 = (0.35e2 / 0.16e2)*_hc1[3];
  const double _t366 = -_t339*_t365 + (0.945e3 / 0.8e1)*_t343 + (0.2835e4 / 0.8e1)*_t344 + (0.945e3 / 0.16e2)*_t346 - 0.3465e4 / 0.16e2*_t348 + (0.3003e4 / 0.16e2)*_t350 - 0.10395e5 / 0.4e1*_t352 + (0.27027e5 / 0.8e1)*_t354 - 0.10395e5 / 0.4e1*_t355 + (0.45045e5 / 0.8e1)*_t357;
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
  const double _t396 = -0.3e1 / 0.2e1*_t368 + 0.15e2*_t371 + 0.45e2*_t372 + (0.15e2 / 0.2e1)*_t374;
  const double _t397 = 0.2e1*_t192;
  const double _t398 = -0.15e2 / 0.2e1*_t369 - 0.45e2 / 0.2e1*_t370 + 0.105e3*_t373 + (0.35e2 / 0.2e1)*_t375 + (0.315e3 / 0.2e1)*_t379;
  const double _t399 = 0.2e1*_t193;
  const double _t400 = 0.2e1*_t194;
  const double _t401 = (0.945e3 / 0.2e1)*_t371;
  const double _t402 = (0.15e2 / 0.8e1)*_t368 - 0.105e3 / 0.2e1*_t371 - 0.315e3 / 0.2e1*_t372 - 0.105e3 / 0.4e1*_t374 + (0.315e3 / 0.8e1)*_t376 + (0.945e3 / 0.2e1)*_t380 + _t401*_t5;
  const double _t403 = 0.2e1*_t195;
  const double _t404 = 0.2e1*_t196;
  const double _t405 = -_hc1[0]*_t401 + (0.105e3 / 0.8e1)*_t369 + (0.315e3 / 0.8e1)*_t370 - 0.315e3 / 0.4e1*_t375 + (0.693e3 / 0.8e1)*_t377 - 0.2835e4 / 0.4e1*_t379 + (0.10395e5 / 0.8e1)*_t381 + (0.3465e4 / 0.2e1)*_t384;
  const double _t406 = -_t365*_t367 + (0.945e3 / 0.8e1)*_t371 + (0.2835e4 / 0.8e1)*_t372 + (0.945e3 / 0.16e2)*_t374 - 0.3465e4 / 0.16e2*_t376 + (0.3003e4 / 0.16e2)*_t378 - 0.10395e5 / 0.4e1*_t380 + (0.27027e5 / 0.8e1)*_t382 - 0.10395e5 / 0.4e1*_t383 + (0.45045e5 / 0.8e1)*_t385;
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
  const double _t451 = 0.00022468135285979469*_t85;
  const double _t453 = 5.4084705273069799e-5*_t86;
  const double _t454 = 0.3e1*_t414;
  const double _t455 = 0.9e1*_t415;
  const double _t471 = 1.5064642655480989e-5*_t102;
  const double _t481 = 0.3e1*_t198;
  const double _t483 = 0.9e1*_t199;
  const double _t485 = 1.8588567264865828e-5*_t107;
  const double _t486 = 0.9e1*_t200;
  const double _t488 = 2.0129783238744015e-5*_t109;
  const double _t492 = -0.3e1 / 0.2e1*_t410 + 0.15e2*_t418 + 0.45e2*_t422 + (0.15e2 / 0.2e1)*_t430;
  const double _t495 = 1.8368976199350359e-5*_t117;
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
  const double _t581 = 10.278613503150439*_t5;
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
  const double _t631 = -0.3e1 / 0.2e1*_t601 + 0.60e2*_t606 + 0.45e2*_t608 + (0.15e2 / 0.2e1)*_t609 + 0.90e2*_t614;
  const double _t632 = -0.15e2 / 0.2e1*_t602 - 0.30e2*_t603 + 0.105e3*_t604 - 0.45e2 / 0.2e1*_t605 + (0.35e2 / 0.2e1)*_t610 + 0.630e3*_t615 + 0.210e3*_t616 + (0.315e3 / 0.2e1)*_t620;
  const double _t633 = _hc0[2]*_t336;
  const double _t634 = 0.2835e4*_t614;
  const double _t635 = _hc1[4]*_t633*_t7 + _t5*_t634 + (0.15e2 / 0.8e1)*_t601 - 0.210e3*_t606 + 0.945e3*_t607 - 0.315e3 / 0.2e1*_t608 - 0.105e3 / 0.4e1*_t609 - 0.315e3*_t614 + 0.630e3*_t617 + (0.945e3 / 0.2e1)*_t622;
  const double _t636 = (0.945e3 / 0.2e1)*_t561;
  const double _t637 = (0.10395e5 / 0.2e1)*_t604;
  const double _t638 = -_hc1[0]*_t634 + _t5*_t637 + _t563*_t633 - _t600*_t636 + (0.105e3 / 0.8e1)*_t602 + (0.105e3 / 0.2e1)*_t603 - 0.315e3 / 0.4e1*_t610 + (0.693e3 / 0.8e1)*_t612 - 0.945e3*_t616 + (0.3465e4 / 0.2e1)*_t618 - 0.2835e4 / 0.4e1*_t620 + (0.10395e5 / 0.8e1)*_t623 + 0.10395e5*_t626;
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
  const double _t654 = _t156*_t198;
  const double _t655 = _t157*_t198;
  const double _t656 = _t5*_t643;
  const double _t657 = _t6*_t643;
  const double _t658 = _t643*_t7;
  const double _t659 = _t643*_t8;
  const double _t660 = _t5*_t645;
  const double _t661 = _t6*_t644;
  const double _t662 = _t6*_t645;
  const double _t663 = _t645*_t7;
  const double _t664 = _t645*_t8;
  const double _t665 = _t163*_t198;
  const double _t666 = _t164*_t198;
  const double _t667 = _t165*_t198;
  const double _t668 = 0.3e1*_t642;
  const double _t669 = 0.12e2*_t643;
  const double _t670 = 0.9e1*_t645;
  const double _t671 = 0.2e1*_t340;
  const double _t672 = 0.6e1*_t341;
  const double _t673 = 0.18e2*_t342;
  const double _t674 = 0.2e1*_t360;
  const double _t675 = -0.3e1 / 0.2e1*_t641 + 0.60e2*_t646 + 0.45e2*_t648 + (0.15e2 / 0.2e1)*_t649 + 0.90e2*_t654;
  const double _t676 = 0.2e1*_t361;
  const double _t677 = 0.2e1*_t363;
  const double _t678 = -0.15e2 / 0.2e1*_t642 - 0.30e2*_t643 + 0.105e3*_t644 - 0.45e2 / 0.2e1*_t645 + (0.35e2 / 0.2e1)*_t650 + 0.630e3*_t655 + 0.210e3*_t656 + (0.315e3 / 0.2e1)*_t660;
  const double _t679 = 0.2e1*_t364;
  const double _t680 = 0.2e1*_t366;
  const double _t681 = 0.2835e4*_t198;
  const double _t682 = _t163*_t681 + (0.15e2 / 0.8e1)*_t641 - 0.210e3*_t646 + 0.945e3*_t647 - 0.315e3 / 0.2e1*_t648 - 0.105e3 / 0.4e1*_t649 + (0.315e3 / 0.8e1)*_t651 - 0.315e3*_t654 + 0.630e3*_t657 + (0.945e3 / 0.2e1)*_t662;
  const double _t683 = (0.10395e5 / 0.2e1)*_t644;
  const double _t684 = -_t157*_t681 + _t5*_t683 - _t636*_t640 + (0.105e3 / 0.8e1)*_t642 + (0.105e3 / 0.2e1)*_t643 + (0.315e3 / 0.8e1)*_t645 - 0.315e3 / 0.4e1*_t650 + (0.693e3 / 0.8e1)*_t652 - 0.945e3*_t656 + (0.3465e4 / 0.2e1)*_t658 - 0.2835e4 / 0.4e1*_t660 + (0.10395e5 / 0.8e1)*_t663 + 0.10395e5*_t666;
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
  const double _t714 = 0.00022468135285979469*_t175;
  const double _t716 = 0.3e1*_t688;
  const double _t717 = 0.12e2*_t689;
  const double _t718 = 0.9e1*_t691;
  const double _t719 = 0.3e1*_t368;
  const double _t720 = 0.9e1*_t369;
  const double _t721 = 0.27e2*_t370;
  const double _t722 = 0.3e1*_t175;
  const double _t723 = 0.9e1*_t176;
  const double _t724 = 0.9e1*_t177;
  const double _t725 = -0.3e1 / 0.2e1*_t687 + 0.60e2*_t692 + 0.45e2*_t694 + (0.15e2 / 0.2e1)*_t695 + 0.90e2*_t700;
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
  const double _t740 = -_hc1[0]*_t736 + _t5*_t739 - _t636*_t686 + (0.105e3 / 0.8e1)*_t688 + (0.105e3 / 0.2e1)*_t689 + (0.315e3 / 0.8e1)*_t691 - 0.315e3 / 0.4e1*_t696 + (0.693e3 / 0.8e1)*_t698 - 0.945e3*_t702 + (0.3465e4 / 0.2e1)*_t704 - 0.2835e4 / 0.4e1*_t706 + (0.10395e5 / 0.8e1)*_t709 + 0.10395e5*_t712;
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
  const double _t802 = 0.00044936270571958937*_t198;
  const double _t803 = 0.9e1*_t747;
  const double _t809 = 0.4e1*_t410;
  const double _t810 = 0.12e2*_t414;
  const double _t811 = 0.36e2*_t415;
  const double _t812 = 0.4e1*_t85;
  const double _t813 = 3.0129285310961979e-5*_t253;
  const double _t814 = 0.12e2*_t86;
  const double _t815 = 0.6e1*_t198;
  const double _t816 = 0.18e2*_t199;
  const double _t817 = 0.18e2*_t200;
  const double _t818 = 0.4e1*_t102;
  const double _t819 = -0.3e1 / 0.2e1*_t743 + 0.60e2*_t748 + 0.45e2*_t753 + (0.15e2 / 0.2e1)*_t754 + 0.90e2*_t759;
  const double _t820 = 0.4e1*_t103;
  const double _t821 = 5.8246340031570251e-5*_t267;
  const double _t822 = 0.4e1*_t107;
  const double _t823 = 0.4e1*_t109;
  const double _t824 = 3.7177134529731656e-5*_t273;
  const double _t825 = 0.4e1*_t492;
  const double _t826 = 0.4e1*_t117;
  const double _t827 = 0.6e1*_t253;
  const double _t828 = 4.0259566477488031e-5*_t281;
  const double _t829 = 0.4e1*_t505;
  const double _t830 = 0.6e1*_t267;
  const double _t831 = -0.15e2 / 0.2e1*_t744 - 0.30e2*_t745 + 0.105e3*_t746 - 0.45e2 / 0.2e1*_t747 + (0.35e2 / 0.2e1)*_t755 + 0.630e3*_t762 + 0.210e3*_t763 + (0.315e3 / 0.2e1)*_t771;
  const double _t832 = 3.6737952398700719e-5*_t288;
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
  const double _t4 = 0.1179363564823021*_hc2[0];
  const double _t11 = ((_hc2[0]) * (_hc2[0]));
  const double _t12 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t13 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t14 = xc_powi((_hc2[0]), 5);
  const double _t15 = xc_powi((_hc2[0]), 6);
  const double _t16 = xc_powi((_hc2[0]), 7);
  const double _t17 = 0.00718980329151343 - 0.02156940987454029*_t11;
  const double _t19 = _hc2[0]*_t18;
  const double _t20 = 0.01545857144139162*_hc2[0] - 0.0257642857356527*_t12;
  const double _t22 = 0.002125332357775206*_hc2[0];
  const double _t23 = -0.063120565750733737*_t11 + 0.073640660042522694*_t13 + 0.0063120565750733737;
  const double _t24 = 0.00057690352291274451 - 0.0017307105687382335*_t11;
  const double _t25 = -0.0004832500092613275*_hc2[0] + 0.002255166709886195*_t12 - 0.0020296500388975755*_t14;
  const double _t27 = 0.002915285520983635*_hc2[0];
  const double _t28 = 0.00048206856497539165 - 0.0014462056949261749*_t11;
  const double _t29 = 0.0010635445219816866*_hc2[0] - 0.001772574203302811*_t12;
  const double _t31 = 0.002007295399058147*_hc2[0];
  const double _t32 = 0.015320922596759935*_t11 - 0.045962767790279806*_t13 + 0.033706029712871857*_t15 - 0.00072956774270285405;
  const double _t33 = -0.0055691792569815646*_hc2[0] + 0.0092819654283026075*_t12;
  const double _t34 = -0.00051385823829655126*_t11 + 0.00059950127801264313*_t13 + 5.1385823829655126e-5;
  const double _t35 = -0.00083955746845782459*_hc2[0] + 0.0075560172161204213*_t12 - 0.016623237875464927*_t14 + 0.010290575827668764*_t16;
  const double _t36 = 0.000931941440505124 - 0.002795824321515372*_t11;
  const double _t38 = 0.001491587478361034*_hc2[0];
  const double _t39 = 0.012507841123248501*_hc2[0] - 0.058369925241826335*_t12 + 0.052532932717643702*_t14;
  const double _t40 = -0.004809269447890365*_t11 + 0.0056108143558720925*_t13 + 0.0004809269447890365;
  const double _t41 = 0.0005948341524757065 - 0.0017845024574271195*_t11;
  const double _t42 = 0.0037424258258211975*_hc2[0] - 0.0062373763763686625*_t12;
  const double _t44 = 0.001940164714223896*_hc2[0];
  const double _t45 = 0.00042429115992572775*_hc2[0] - 0.0019800254129867295*_t12 + 0.0017820228716880566*_t14;
  const double _t46 = -0.036081366051713095*_t11 + 0.10824409815513929*_t13 - 0.079379005313768809*_t15 + 0.0017181602881768141;
  const double _t47 = -0.00025093588620949455*_hc2[0] + 0.00041822647701582425*_t12;
  const double _t48 = -0.0015704354653915894*_t11 + 0.0018321747096235209*_t13 + 0.00015704354653915894;
  const double _t49 = 0.00064415306363980849 - 0.0019324591909194255*_t11;
  const double _t50 = -0.0031092928646582272*_hc2[0] + 0.027983635781924044*_t12 - 0.061563998720232898*_t14 + 0.038111046826810841*_t16;
  const double _t51 = -0.042722346728812577*_t11 + 0.12816704018643773*_t13 - 0.093989162803387668*_t15 + 0.0020343974632767893;
  const double _t52 = -0.0018937148691491756*_hc2[0] + 0.0088373360560294861*_t12 - 0.0079536024504265376*_t14;
  const double _t53 = 0.0010207381878334643*_t11 - 0.0011908612191390416*_t13 - 0.00010207381878334642;
  const double _t54 = 0.0005878072383792115 - 0.0017634217151376345*_t11;
  const double _t55 = 0.00090877452512640869*_hc2[0] - 0.0015146242085440145*_t12;
  const double _t56 = -0.027197797458202416*_hc2[0] + 0.24478017712382174*_t12 - 0.53851638967240784*_t14 + 0.3333672888448239*_t16;
  const double _t57 = -0.001100609340742608*_hc2[0] + 0.0051361769234655039*_t12 - 0.0046225592311189536*_t14;
  const double _t58 = -0.0006468617638864578*_hc2[0] + 0.001078102939810763*_t12;
  const double _t59 = 0.002776111012670955*_t11 - 0.0083283330380128653*_t13 + 0.0061074442278761012*_t15 - 0.00013219576250814072;
  const double _t60 = -0.0010410225900262144*_t11 + 0.0012145263550305834*_t13 + 0.00010410225900262144;
  const double _t61 = -0.0053758379467980687*_hc2[0] + 0.048382541521182618*_t12 - 0.10644159134660176*_t14 + 0.06589241369075347*_t16;
  const double _t62 = 0.0074581882271825577*_t11 - 0.022374564681547673*_t13 + 0.016408014099801627*_t15 - 0.00035515182034202656;
  const double _t63 = -1.2048536779195099e-5*_t11 + 1.4056626242394282e-5*_t13 + 1.2048536779195099e-6;
  const double _t64 = -0.0030424151080372988*_hc2[0] + 0.014197937170840728*_t12 - 0.012778143453756655*_t14;
  const double _t65 = -0.0033304122678727513*_hc2[0] + 0.029973710410854761*_t12 - 0.065942162903880476*_t14 + 0.040821338940497437*_t16;
  const double _t66 = -0.00041301744451222444*_hc2[0] + 0.0019274147410570474*_t12 - 0.0017346732669513426*_t14;
  const double _t67 = 0.0027961883328759444*_t11 - 0.008388564998627833*_t13 + 0.0061516143323270776*_t15 - 0.00013315182537504497;
  const double _t68 = 0.00080555112585126725*_hc2[0] - 0.0072499601326614053*_t12 + 0.015949912291855091*_t14 - 0.0098737552282912471*_t16;
  const double _t69 = 0.0024984478281990229*_t11 - 0.0074953434845970685*_t13 + 0.0054965852220378502*_t15 - 0.00011897370610471538;
  const double _t70 = 0.00080839145657850015*_hc2[0] - 0.0072755231092065014*_t12 + 0.016006150840254303*_t14 - 0.0099085695677764733*_t16;
#if _KMAX >= 1
  const double _t73 = 0.00538391567059323*_hc2[0];
  const double _t92 = _hc2[1]*_t3;
  const double _t93 = 0.0049140148534292542*_t92;
  const double _t94 = _hc2[0]*_t92;
  const double _t95 = 0.0017974508228783575*_t94;
  const double _t97 = _t11*_t92;
  const double _t98 = _t12*_t92;
  const double _t99 = _t13*_t92;
  const double _t100 = _t14*_t92;
  const double _t101 = _t15*_t92;
  const double _t104 = 8.8555514907300251e-5*_t92;
  const double _t105 = 0.00012051714124384791*_t94;
  const double _t106 = 0.00012147023004098479*_t92;
  const double _t108 = 0.000232985360126281*_t94;
  const double _t110 = 8.363730829408946e-5*_t92;
  const double _t111 = 0.0006441071433913175*_hc2[1]*_t1*_t2 - 0.0032205357169565875*_t97;
  const double _t112 = 0.00014870853811892663*_t94;
  const double _t113 = -0.0052600471458944781*_t94 + 0.012273443340420449*_t98;
  const double _t114 = 6.2149478265043084e-5*_t92;
  const double _t115 = 0.00016103826590995212*_t94;
  const double _t116 = 8.0840196425995668e-5*_t92;
  const double _t118 = 0.00014695180959480288*_t94;
  const double _t119 = 4.4314355082570275e-5*_hc2[1]*_t1*_t2 - 0.00022157177541285138*_t97;
  const double _t120 = -4.2821519858045939e-5*_t94 + 9.9916879668773855e-5*_t98;
  const double _t121 = -0.00023204913570756519*_t92 + 0.0011602456785378259*_t97;
  const double _t122 = -0.00040077245399086375*_t94 + 0.00093513572597868209*_t98;
  const double _t123 = 0.00015593440940921657*_hc2[1]*_t1*_t2 - 0.00077967204704608281*_t97;
  const double _t124 = 0.00028189583873577438*_hc2[1]*_t1*_t11*_t2 - 2.0135417052555313e-5*_t92 - 0.00042284375810366156*_t99;
  const double _t125 = -0.00013086962211596578*_t94 + 0.00030536245160392016*_t98;
  const double _t126 = 0.0084265074282179643*_t100 + 0.0012767435497299946*_t94 - 0.0076604612983799677*_t98;
  const double _t127 = -1.0455661925395606e-5*_t92 + 5.2278309626978031e-5*_t97;
  const double _t128 = 8.5061515652788688e-5*_hc2[0]*_hc2[1]*_t1*_t2 - 0.00019847686985650694*_t98;
  const double _t129 = 3.7865605213600362e-5*_hc2[1]*_t1*_t2 - 0.00018932802606800181*_t97;
  const double _t130 = -8.6751882502184531e-5*_t94 + 0.00020242105917176391*_t98;
  const double _t131 = 0.00052116004680202087*_t92 - 0.0072962406552282919*_t97 + 0.010944360982842438*_t99;
  const double _t132 = -2.6952573495269075e-5*_t92 + 0.00013476286747634538*_t97;
  const double _t133 = 0.018040683025856548*_hc2[1]*_t1*_t12*_t2 - 0.019844751328442202*_t100 - 0.0030067805043094246*_t94;
  const double _t134 = -1.0040447315995916e-6*_t94 + 2.342771040399047e-6*_t98;
  const double _t135 = 1.7678798330238656e-5*_t92 - 0.00024750317662334119*_t97 + 0.00037125476493501178*_t99;
  const double _t136 = 0.021361173364406288*_hc2[1]*_t1*_t12*_t2 - 0.023497290700846917*_t100 - 0.0035601955607343814*_t94;
  const double _t137 = 0.0011046670070036858*_hc2[1]*_t1*_t11*_t2 - 7.8904786214548984e-5*_t92 - 0.0016570005105055287*_t99;
  const double _t138 = 0.0030014179497367228*_t101 - 3.4981561185742691e-5*_t92 + 0.00094450215201505266*_t97 - 0.0034631745573885265*_t99;
  const double _t139 = 0.0015268610569690253*_t100 + 0.00023134258438924626*_t94 - 0.0013880555063354776*_t98;
  const double _t140 = 0.00064202211543318799*_hc2[1]*_t1*_t11*_t2 - 4.5858722530942e-5*_t92 - 0.00096303317314978198*_t99;
  const double _t141 = 0.0041020035249504067*_t100 + 0.00062151568559854648*_t94 - 0.0037290941135912789*_t98;
  const double _t142 = 0.0017747421463550909*_hc2[1]*_t1*_t11*_t2 - 0.00012676729616822078*_t92 - 0.0026621132195326364*_t99;
  const double _t143 = 0.0015379035830817694*_t100 + 0.0002330156944063287*_t94 - 0.0013980941664379722*_t98;
  const double _t144 = 0.011115721991153162*_t101 - 0.00012955386936075947*_t92 + 0.0034979544727405055*_t97 - 0.012825833066715187*_t99;
  const double _t145 = 0.00024092684263213092*_hc2[1]*_t1*_t11*_t2 - 1.7209060188009352e-5*_t92 - 0.00036139026394819638*_t99;
  const double _t146 = 0.0013741463055094626*_t100 + 0.00020820398568325191*_t94 - 0.0012492239140995114*_t98;
  const double _t147 = 0.097232125913073635*_t101 - 0.001133241560758434*_t92 + 0.030597522140477718*_t97 - 0.11219091451508497*_t99;
  const double _t148 = 0.019218620659803095*_t101 - 0.00022399324778325286*_t92 + 0.0060478176901478273*_t97 - 0.022175331530542033*_t99;
  const double _t149 = 0.011906223857645086*_t101 - 0.0001387671778280313*_t92 + 0.0037467138013568452*_t97 - 0.013737950604975099*_t99;
  const double _t150 = 0.0033228983941364774*_hc2[1]*_t1*_t13*_t2 + 3.3564630243802802e-5*_hc2[1]*_t1*_t2 - 0.0028798452749182804*_t101 - 0.00090624501658267566*_t97;
  const double _t151 = 0.0033346147583863131*_hc2[1]*_t1*_t13*_t2 + 3.3682977357437507e-5*_hc2[1]*_t1*_t2 - 0.002889999457268138*_t101 - 0.00090944038865081267*_t97;
#endif
#if _KMAX >= 2
  const double _t188 = 0.00022432981960805125*_t92;
  const double _t190 = 0.00043267764218455839*_t94;
  const double _t204 = _hc2[2]*_t203;
  const double _t211 = 0.00020475061889288559*_t204;
  const double _t212 = _hc2[0]*_t204;
  const double _t213 = ((_hc2[1]) * (_hc2[1]));
  const double _t214 = _t203*_t213;
  const double _t219 = 0.0098280297068585084*_t92;
  const double _t221 = _hc2[0]*_t214;
  const double _t222 = _t11*_t204;
  const double _t223 = _t12*_t204;
  const double _t224 = _t13*_t204;
  const double _t225 = _t14*_t204;
  const double _t226 = _t15*_t204;
  const double _t227 = 0.0004486596392161025*_t92;
  const double _t228 = 0.003594901645756715*_t94;
  const double _t229 = 0.00086535528436911678*_t94;
  const double _t231 = _t11*_t214;
  const double _t232 = _t12*_t214;
  const double _t233 = _t13*_t214;
  const double _t234 = _t14*_t214;
  const double _t236 = 3.6898131211375105e-6*_t204;
  const double _t237 = 5.0215475518269964e-6*_t212;
  const double _t238 = 5.0215475518269964e-6*_t214;
  const double _t239 = 0.0001771110298146005*_t92;
  const double _t240 = 5.0612595850410331e-6*_t204;
  const double _t241 = 0.00024294046008196959*_t92;
  const double _t242 = 0.00024103428248769583*_t94;
  const double _t243 = 9.7077233385950417e-6*_t212;
  const double _t244 = 9.7077233385950417e-6*_t214;
  const double _t245 = 3.4848878455870608e-6*_t204;
  const double _t246 = 0.000465970720252562*_t94;
  const double _t247 = 6.1961890882886094e-6*_t212;
  const double _t248 = 6.1961890882886094e-6*_t214;
  const double _t250 = 2.5895615943767952e-6*_t204;
  const double _t252 = 6.7099277462480052e-6*_t212;
  const double _t254 = 0.00016727461658817892*_t92;
  const double _t255 = 6.7099277462480052e-6*_t214;
  const double _t256 = 3.3683415177498195e-6*_t204;
  const double _t257 = 0.00012429895653008617*_t92;
  const double _t258 = 0.00029741707623785325*_t94;
  const double _t259 = 6.1229920664501199e-6*_t212;
  const double _t260 = 6.1229920664501199e-6*_t214;
  const double _t261 = 0.00032207653181990425*_t94;
  const double _t262 = 2.6837797641304896e-5*_hc2[2]*_t201*_t202 - 0.00026837797641304896*_t221 - 0.00013418898820652448*_t222;
  const double _t263 = 0.00016168039285199134*_t92;
  const double _t265 = 0.00029390361918960575*_t94;
  const double _t268 = 1.8464314617737615e-6*_hc2[2]*_t201*_t202 - 1.8464314617737615e-5*_t221 - 9.2321573088688074e-6*_t222;
  const double _t270 = -9.6687139878152164e-6*_t204 + 9.6687139878152162e-5*_t221 + 4.8343569939076081e-5*_t222;
  const double _t272 = 6.4972670587173569e-6*_hc2[2]*_t201*_t202 - 6.4972670587173568e-5*_t221 - 3.2486335293586784e-5*_t222;
  const double _t274 = -4.3565258022481693e-7*_t204 + 4.3565258022481694e-6*_t221 + 2.1782629011240847e-6*_t222;
  const double _t275 = -0.00021916863107893659*_t212 - 0.00021916863107893659*_t214 + 0.00051139347251751871*_t223 + 0.0015341804175525561*_t231;
  const double _t277 = 1.5777335505666818e-6*_hc2[2]*_t201*_t202 - 1.5777335505666818e-5*_t221 - 7.8886677528334089e-6*_t222;
  const double _t278 = -1.1230238956362115e-6*_t204 + 1.1230238956362115e-5*_t221 + 5.6151194781810574e-6*_t222;
  const double _t279 = -1.7842299940852474e-6*_t212 - 1.7842299940852474e-6*_t214 + 4.163203319532244e-6*_t223 + 1.2489609958596732e-5*_t231;
  const double _t280 = -1.6698852249619323e-5*_t212 - 1.6698852249619323e-5*_t214 + 3.8963988582445087e-5*_t223 + 0.00011689196574733526*_t231;
  const double _t282 = -5.4529009214985743e-6*_t212 - 5.4529009214985743e-6*_t214 + 1.2723435483496674e-5*_t223 + 3.817030645049002e-5*_t231;
  const double _t283 = 2.3491319894647865e-5*_hc2[0]*_t201*_t202*_t213 + 1.1745659947323933e-5*_hc2[2]*_t11*_t201*_t202 - 8.3897571052313803e-7*_t204 - 1.7618489920985899e-5*_t224 - 7.0473959683943595e-5*_t232;
  const double _t284 = 3.5442298188661954e-6*_hc2[0]*_hc2[2]*_t201*_t202 + 3.5442298188661954e-6*_t201*_t202*_t213 - 8.2698695773544561e-6*_t223 - 2.4809608732063368e-5*_t231;
  const double _t285 = -3.6146617709243555e-6*_t212 - 3.6146617709243555e-6*_t214 + 8.4342107988234963e-6*_t223 + 2.5302632396470489e-5*_t231;
  const double _t286 = 2.1715001950084203e-5*_t204 - 0.00060802005460235767*_t221 - 0.00030401002730117883*_t222 + 0.00045601504095176825*_t224 + 0.001824060163807073*_t232;
  const double _t287 = -4.1835197149982983e-8*_t212 - 4.1835197149982983e-8*_t214 + 9.7615460016626958e-8*_t223 + 2.9284638004988087e-7*_t231;
  const double _t289 = 7.3661659709327735e-7*_t204 - 2.0625264718611766e-5*_t221 - 1.0312632359305883e-5*_t222 + 1.5468948538958824e-5*_t224 + 6.1875794155835297e-5*_t232;
  const double _t290 = 9.2055583916973813e-5*_hc2[0]*_t201*_t202*_t213 + 4.6027791958486907e-5*_hc2[2]*_t11*_t201*_t202 - 3.2876994256062077e-6*_t204 - 6.9041687937730362e-5*_t224 - 0.00027616675175092145*_t232;
  const double _t291 = 5.3501842952765666e-5*_hc2[0]*_t201*_t202*_t213 + 2.6750921476382833e-5*_hc2[2]*_t11*_t201*_t202 - 1.9107801054559167e-6*_t204 - 4.012638221457425e-5*_t224 - 0.000160505528858297*_t232;
  const double _t292 = 5.3197647905416443e-5*_t212 + 5.3197647905416443e-5*_t214 - 0.00031918588743249866*_t223 + 0.00035110447617574852*_t225 - 0.00095755766229749596*_t231 + 0.0017555223808787426*_t233;
  const double _t293 = 0.00014789517886292425*_hc2[0]*_t201*_t202*_t213 + 7.3947589431462124e-5*_hc2[2]*_t11*_t201*_t202 - 5.2819706736758659e-6*_t204 - 0.00011092138414719318*_t224 - 0.00044368553658877273*_t232;
  const double _t294 = 2.0077236886010911e-5*_hc2[0]*_t201*_t202*_t213 + 1.0038618443005455e-5*_hc2[2]*_t11*_t201*_t202 - 7.1704417450038966e-7*_t204 - 1.5057927664508183e-5*_t224 - 6.0231710658032731e-5*_t232;
  const double _t295 = 0.00075169512607735616*_hc2[2]*_t12*_t201*_t202 + 0.0022550853782320685*_t11*_t201*_t202*_t213 - 0.00012528252101289269*_t212 - 0.00012528252101289269*_t214 - 0.00082686463868509176*_t225 - 0.0041343231934254588*_t233;
  const double _t296 = 0.00089004889018359535*_hc2[2]*_t12*_t201*_t202 + 0.002670146670550786*_t11*_t201*_t202*_t213 - 0.00014834148169726589*_t212 - 0.00014834148169726589*_t214 - 0.00097905377920195488*_t225 - 0.0048952688960097743*_t233;
  const double _t297 = 9.6392743495519273e-6*_t212 + 9.6392743495519273e-6*_t214 - 5.7835646097311565e-5*_t223 + 6.3619210707042721e-5*_t225 - 0.00017350693829193469*_t231 + 0.0003180960535352136*_t233;
  const double _t298 = -1.4575650494059455e-6*_t204 + 7.8708512667921056e-5*_t221 + 3.9354256333960528e-5*_t222 - 0.0001442989398911886*_t224 + 0.00012505908123903012*_t226 - 0.00057719575956475442*_t232 + 0.00075035448743418071*_t234;
  const double _t299 = 2.5896486899939437e-5*_t212 + 2.5896486899939437e-5*_t214 - 0.00015537892139963662*_t223 + 0.00017091681353960028*_t225 - 0.00046613676419890987*_t231 + 0.0008545840676980014*_t233;
  const double _t300 = 9.7089872669303627e-6*_t212 + 9.7089872669303627e-6*_t214 - 5.8253923601582175e-5*_t223 + 6.4079315961740391e-5*_t225 - 0.00017476177080474652*_t231 + 0.00032039657980870195*_t233;
  const double _t301 = -5.3980778900316444e-6*_t204 + 0.0002914962060617088*_t221 + 0.0001457481030308544*_t222 - 0.0005344097111131328*_t224 + 0.00046315508296471509*_t226 - 0.0021376388444525312*_t232 + 0.0027789304977882905*_t234;
  const double _t302 = 8.6751660701354962e-6*_t212 + 8.6751660701354962e-6*_t214 - 5.2050996420812977e-5*_t223 + 5.7256096062894274e-5*_t225 - 0.00015615298926243893*_t231 + 0.00028628048031447137*_t233;
  const double _t303 = -4.721839836493475e-5*_t204 + 0.0025497935117064765*_t221 + 0.0012748967558532383*_t222 - 0.0046746214381285403*_t224 + 0.0040513385797114015*_t226 - 0.018698485752514161*_t232 + 0.024308031478268409*_t234;
  const double _t304 = -9.3330519909688695e-6*_t204 + 0.00050398480751231894*_t221 + 0.00025199240375615947*_t222 - 0.00092397214710591805*_t224 + 0.00080077586082512898*_t226 - 0.0036958885884236722*_t232 + 0.0048046551649507739*_t234;
  const double _t305 = -5.7819657428346377e-6*_t204 + 0.00031222615011307043*_t221 + 0.00015611307505653522*_t222 - 0.00057241460854062914*_t224 + 0.00049609266073521191*_t226 - 0.0022896584341625166*_t232 + 0.0029765559644112715*_t234;
  const double _t306 = 0.00013845409975568656*_hc2[2]*_t13*_t201*_t202 + 1.3985262601584501e-6*_hc2[2]*_t201*_t202 + 0.00055381639902274624*_t12*_t201*_t202*_t213 - 7.5520418048556305e-5*_t221 - 3.7760209024278152e-5*_t222 - 0.00011999355312159502*_t226 - 0.00071996131872957009*_t234;
  const double _t307 = 0.00013894228159942971*_hc2[2]*_t13*_t201*_t202 + 1.4034573898932295e-6*_hc2[2]*_t201*_t202 + 0.00055576912639771885*_t12*_t201*_t202*_t213 - 7.5786699054234389e-5*_t221 - 3.7893349527117195e-5*_t222 - 0.00012041664405283909*_t226 - 0.00072249986431703451*_t234;
#endif
#if _KMAX >= 3
  const double _t316 = 0.01615174701177969*_hc2[0];
  const double _t386 = 9.3470758170021355e-6*_t204;
  const double _t387 = 7.489378428659823e-5*_t212;
  const double _t388 = 7.489378428659823e-5*_t214;
  const double _t389 = 1.8028235091023266e-5*_t212;
  const double _t390 = 1.8028235091023266e-5*_t214;
  const double _t408 = _hc2[3]*_t407;
  const double _t411 = 5.1187654723221399e-5*_t408;
  const double _t412 = _hc2[0]*_t408;
  const double _t413 = _hc2[1]*_hc2[2]*_t407;
  const double _t416 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t417 = _t407*_t416;
  const double _t419 = 1.8723446071649557e-5*_t412;
  const double _t420 = 5.6170338214948672e-5*_t413;
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
  const double _t449 = 0.00061425185667865678*_t204;
  const double _t450 = 2.8041227451006406e-5*_t204;
  const double _t452 = 0.014742044560287763*_t92;
  const double _t456 = 0.00067298945882415375*_t92;
  const double _t457 = 0.0053923524686350725*_t94;
  const double _t458 = 5.4084705273069799e-5*_t214;
  const double _t459 = 9.2245328028437762e-7*_t408;
  const double _t460 = 0.0012980329265536752*_t94;
  const double _t461 = 1.2553868879567491e-6*_t412;
  const double _t462 = 3.7661606638702473e-6*_t413;
  const double _t463 = 1.2653148962602583e-6*_t408;
  const double _t464 = 2.4269308346487604e-6*_t412;
  const double _t465 = 7.2807925039462813e-6*_t413;
  const double _t466 = 8.7122196139676522e-7*_t408;
  const double _t467 = 1.1069439363412531e-5*_t204;
  const double _t468 = 1.5490472720721524e-6*_t412;
  const double _t469 = 4.6471418162164572e-6*_t413;
  const double _t470 = 1.5183778755123099e-5*_t204;
  const double _t472 = 6.4739039859419879e-7*_t408;
  const double _t473 = 1.5064642655480989e-5*_t214;
  const double _t474 = 2.9123170015785125e-5*_t212;
  const double _t475 = 2.9123170015785125e-5*_t214;
  const double _t476 = 1.6774819365620013e-6*_t412;
  const double _t477 = 5.0324458096860039e-6*_t413;
  const double _t478 = 8.4208537943745489e-7*_t408;
  const double _t479 = 1.53074801661253e-6*_t412;
  const double _t480 = 4.5922440498375899e-6*_t413;
  const double _t482 = 1.0454663536761182e-5*_t204;
  const double _t484 = 7.7686847831303855e-6*_t204;
  const double _t487 = 1.8588567264865828e-5*_t214;
  const double _t489 = 2.0129783238744015e-5*_t214;
  const double _t490 = 6.7094494103262241e-6*_hc2[3]*_t407 - 6.709449410326224e-5*_t417 - 0.00020128348230978672*_t421 - 3.354724705163112e-5*_t424;
  const double _t491 = 0.00026566654472190075*_t92;
  const double _t493 = 1.0105024553249458e-5*_t204;
  const double _t494 = 0.00036155142373154374*_t94;
  const double _t497 = 1.8368976199350359e-5*_t214;
  const double _t499 = 4.6160786544344037e-7*_hc2[3]*_t407 - 4.6160786544344037e-6*_t417 - 1.3848235963303211e-5*_t421 - 2.3080393272172019e-6*_t424;
  const double _t500 = -2.4171784969538041e-6*_t408 + 2.4171784969538041e-5*_t417 + 7.2515354908614122e-5*_t421 + 1.208589248476902e-5*_t424;
  const double _t501 = -5.4792157769734149e-5*_t412 - 0.00016437647330920245*_t413 + 0.00076709020877627806*_t423 + 0.00012784836812937968*_t425 + 0.0011506353131644171*_t435;
  const double _t502 = 1.6243167646793393e-6*_hc2[3]*_t407 - 1.6243167646793392e-5*_t417 - 4.8729502940380176e-5*_t421 - 8.121583823396696e-6*_t424;
  const double _t503 = 0.00036441069012295438*_t92;
  const double _t504 = -1.0891314505620423e-7*_t408 + 1.0891314505620423e-6*_t417 + 3.267394351686127e-6*_t421 + 5.4456572528102117e-7*_t424;
  const double _t506 = 0.00069895608037884299*_t94;
  const double _t510 = 3.9443338764167045e-7*_hc2[3]*_t407 - 3.9443338764167046e-6*_t417 - 1.1833001629250114e-5*_t421 - 1.9721669382083523e-6*_t424;
  const double _t511 = -4.4605749852131187e-7*_t412 - 1.3381724955639356e-6*_t413 + 6.2448049792983661e-6*_t423 + 1.040800829883061e-6*_t425 + 9.3672074689475491e-6*_t435;
  const double _t512 = -2.8075597390905287e-7*_t408 + 2.8075597390905287e-6*_t417 + 8.422679217271586e-6*_t421 + 1.4037798695452643e-6*_t424;
  const double _t513 = -4.1747130624048309e-6*_t412 - 1.2524139187214493e-5*_t413 + 5.8445982873667631e-5*_t423 + 9.7409971456112718e-6*_t425 + 8.7668974310501446e-5*_t435;
  const double _t514 = -1.3632252303746436e-6*_t412 - 4.0896756911239307e-6*_t413 + 1.908515322524501e-5*_t423 + 3.1808588708741684e-6*_t425 + 2.8627729837867515e-5*_t435;
  const double _t516 = 0.00025091192488226838*_t92;
  const double _t518 = 0.00044612561435677987*_t94;
  const double _t519 = 8.8605745471654886e-7*_hc2[0]*_hc2[3]*_t407 + 2.6581723641496466e-6*_hc2[1]*_hc2[2]*_t407 - 1.2404804366031684e-5*_t423 - 2.067467394338614e-6*_t425 - 1.8607206549047526e-5*_t435;
  const double _t520 = -9.0366544273108888e-7*_t412 - 2.7109963281932666e-6*_t413 + 1.2651316198235244e-5*_t423 + 2.1085526997058741e-6*_t425 + 1.8976974297352866e-5*_t435;
  const double _t522 = 1.7618489920985899e-5*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 2.9364149868309832e-6*_hc2[3]*_t11*_t407 + 5.8728299736619663e-6*_t407*_t416 - 2.0974392763078451e-7*_t408 - 4.4046224802464747e-6*_t426 - 5.2855469762957696e-5*_t436 - 5.2855469762957696e-5*_t443;
  const double _t524 = -1.0458799287495746e-8*_t412 - 3.1376397862487237e-8*_t413 + 1.4642319002494044e-7*_t423 + 2.4403865004156739e-8*_t425 + 2.1963478503741065e-7*_t435;
  const double _t527 = 0.00018644843479512925*_t92;
  const double _t528 = 0.00048311479772985637*_t94;
  const double _t529 = 5.4287504875210507e-6*_t408 - 0.00015200501365058942*_t417 - 0.00045601504095176825*_t421 - 7.6002506825294708e-5*_t424 + 0.00011400376023794206*_t426 + 0.0013680451228553048*_t436 + 0.0013680451228553047*_t443;
  const double _t531 = 1.8415414927331934e-7*_t408 - 5.1563161796529415e-6*_t417 - 1.5468948538958824e-5*_t421 - 2.5781580898264707e-6*_t424 + 3.8672371347397061e-6*_t426 + 4.6406845616876473e-5*_t436 + 4.6406845616876473e-5*_t443;
  const double _t532 = 1.3299411976354111e-5*_t412 + 3.9898235929062332e-5*_t413 - 0.00047877883114874799*_t423 - 7.9796471858124664e-5*_t425 + 8.777611904393713e-5*_t427 - 0.00071816824672312198*_t435 + 0.0013166417856590569*_t437 + 0.0017555223808787426*_t444;
  const double _t533 = 6.9041687937730362e-5*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 1.1506947989621727e-5*_hc2[3]*_t11*_t407 + 2.3013895979243454e-5*_t407*_t416 - 8.2192485640155193e-7*_t408 - 1.7260421984432591e-5*_t426 - 0.00020712506381319109*_t436 - 0.00020712506381319109*_t443;
  const double _t534 = 4.012638221457425e-5*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 6.6877303690957084e-6*_hc2[3]*_t11*_t407 + 1.3375460738191417e-5*_t407*_t416 - 4.7769502636397917e-7*_t408 - 1.0031595553643562e-5*_t426 - 0.00012037914664372275*_t436 - 0.00012037914664372275*_t443;
  const double _t535 = 0.000242520589277987*_t92;
  const double _t536 = 0.00044085542878440863*_t94;
  const double _t538 = 0.00011092138414719319*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 1.8486897357865531e-5*_hc2[3]*_t11*_t407 + 3.6973794715731062e-5*_t407*_t416 - 1.3204926684189665e-6*_t408 - 2.7730346036798296e-5*_t426 - 0.00033276415244157956*_t436 - 0.00033276415244157955*_t443;
  const double _t539 = 0.0011275426891160342*_hc2[0]*_t407*_t416 + 0.0016913140336740514*_hc2[1]*_hc2[2]*_t11*_t407 + 0.00018792378151933904*_hc2[3]*_t12*_t407 - 3.1320630253223173e-5*_t412 - 9.3961890759669518e-5*_t413 - 0.00020671615967127294*_t427 - 0.0031007423950690942*_t437 - 0.0041343231934254589*_t444;
  const double _t540 = 1.5057927664508183e-5*_hc2[0]*_hc2[1]*_hc2[2]*_t407 + 2.5096546107513638e-6*_hc2[3]*_t11*_t407 + 5.0193092215027277e-6*_t407*_t416 - 1.7926104362509741e-7*_t408 - 3.7644819161270457e-6*_t426 - 4.5173782993524549e-5*_t436 - 4.5173782993524548e-5*_t443;
  const double _t541 = 0.001335073335275393*_hc2[0]*_t407*_t416 + 0.0020026100029130895*_hc2[1]*_hc2[2]*_t11*_t407 + 0.00022251222254589884*_hc2[3]*_t12*_t407 - 3.7085370424316473e-5*_t412 - 0.00011125611127294942*_t413 - 0.00024476344480048872*_t427 - 0.0036714516720073308*_t437 - 0.0048952688960097743*_t444;
  const double _t543 = 2.4098185873879818e-6*_t412 + 7.2294557621639455e-6*_t413 - 8.6753469145967347e-5*_t423 - 1.4458911524327891e-5*_t425 + 1.590480267676068e-5*_t427 - 0.00013013020371895102*_t435 + 0.0002385720401514102*_t437 + 0.0003180960535352136*_t444;
  const double _t544 = 6.4741217249848593e-6*_t412 + 1.9422365174954578e-5*_t413 - 0.00023306838209945494*_t423 - 3.8844730349909156e-5*_t425 + 4.2729203384900071e-5*_t427 - 0.0003496025731491824*_t435 + 0.00064093805077350105*_t437 + 0.00085458406769800141*_t444;
  const double _t545 = 2.4272468167325907e-6*_t412 + 7.281740450197772e-6*_t413 - 8.7380885402373262e-5*_t423 - 1.4563480900395544e-5*_t425 + 1.6019828990435098e-5*_t427 - 0.00013107132810355989*_t435 + 0.00024029743485652647*_t437 + 0.00032039657980870195*_t444;
  const double _t547 = -3.6439126235148637e-7*_t408 + 1.9677128166980264e-5*_t417 + 5.9031384500940792e-5*_t421 + 9.838564083490132e-6*_t424 - 3.6074734972797151e-5*_t426 + 3.126477030975753e-5*_t428 - 0.00043289681967356581*_t436 + 0.00056276586557563554*_t438 - 0.00043289681967356581*_t443 + 0.00093794310929272589*_t445;
  const double _t548 = 2.168791517533874e-6*_t412 + 6.5063745526016222e-6*_t413 - 7.8076494631219465e-5*_t423 - 1.3012749105203244e-5*_t425 + 1.4314024015723569e-5*_t427 - 0.0001171147419468292*_t435 + 0.00021471036023585353*_t437 + 0.00028628048031447137*_t444;
  const double _t550 = -1.3495194725079111e-6*_t408 + 7.2874051515427199e-5*_t417 + 0.0002186221545462816*_t421 + 3.6437025757713599e-5*_t424 - 0.0001336024277782832*_t426 + 0.00011578877074117877*_t428 - 0.0016032291333393984*_t436 + 0.0020841978733412179*_t438 - 0.0016032291333393984*_t443 + 0.0034736631222353631*_t445;
  const double _t551 = -1.1804599591233687e-5*_t408 + 0.00063744837792661913*_t417 + 0.0019123451337798574*_t421 + 0.00031872418896330957*_t424 - 0.0011686553595321351*_t426 + 0.0010128346449278504*_t428 - 0.014023864314385621*_t436 + 0.018231023608701307*_t438 - 0.014023864314385621*_t443 + 0.030385039347835511*_t445;
  const double _t552 = -2.3332629977422174e-6*_t408 + 0.00012599620187807973*_t417 + 0.0003779886056342392*_t421 + 6.2998100939039867e-5*_t424 - 0.00023099303677647951*_t426 + 0.00020019396520628225*_t428 - 0.0027719164413177542*_t436 + 0.0036034913737130804*_t438 - 0.0027719164413177541*_t443 + 0.0060058189561884672*_t445;
  const double _t553 = -1.4454914357086594e-6*_t408 + 7.8056537528267608e-5*_t417 + 0.00023416961258480282*_t421 + 3.9028268764133804e-5*_t424 - 0.00014310365213515729*_t426 + 0.00012402316518380298*_t428 - 0.0017172438256218874*_t436 + 0.0022324169733084536*_t438 - 0.0017172438256218874*_t443 + 0.0037206949555140893*_t445;
  const double _t554 = 0.00041536229926705968*_hc2[1]*_hc2[2]*_t12*_t407 + 3.461352493892164e-5*_hc2[3]*_t13*_t407 + 3.4963156503961252e-7*_hc2[3]*_t407 + 0.00041536229926705968*_t11*_t407*_t416 - 1.8880104512139076e-5*_t417 - 5.6640313536417229e-5*_t421 - 9.4400522560695381e-6*_t424 - 2.9998388280398754e-5*_t428 - 0.00053997098904717757*_t438 - 0.00089995164841196261*_t445;
  const double _t555 = 0.00041682684479828914*_hc2[1]*_hc2[2]*_t12*_t407 + 3.4735570399857428e-5*_hc2[3]*_t13*_t407 + 3.5086434747330737e-7*_hc2[3]*_t407 + 0.00041682684479828914*_t11*_t407*_t416 - 1.8946674763558597e-5*_t417 - 5.6840024290675792e-5*_t421 - 9.4733373817792987e-6*_t424 - 3.0104161013209772e-5*_t428 - 0.00054187489823777588*_t438 - 0.00090312483039629313*_t445;
#endif
#if _KMAX >= 4
  const double _t566 = 0.02153566268237292*_hc2[0];
  const double _t715 = 5.4084705273069799e-5*_t212;
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
  const double _t801 = 5.6082454902012813e-5*_t204;
  const double _t804 = _t11*_t784;
  const double _t805 = _t12*_t784;
  const double _t806 = _t13*_t784;
  const double _t807 = 0.0001081694105461396*_t212;
  const double _t808 = 0.0001081694105461396*_t214;
#endif

  const double f = _hc1[0]*_t17 + _hc1[0]*_t20 + _hc1[0]*_t23 + _hc1[0]*_t25 + _hc1[0]*_t32 + _hc1[0]*_t35 + _hc1[0]*_t4 + 0.20748619661467273*_hc1[0] - 0.16159106071513224*_hc2[0] - 0.06746454865517729*_t10 - 0.37102687351218925*_t11 + 0.0074168801870361914*_t12 - 0.0010470532939127497*_t13 - 0.015887583418757175*_t14 + 0.022419222998949864*_t15 + 0.015682422300093093*_t16 + _t18*_t24 + _t18*_t29 + _t18*_t34 + _t18*_t39 + _t18*_t46 + _t18*_t50 + 0.00179463855686441*_t19 + _t21*_t22 + _t21*_t28 + _t21*_t33 + _t21*_t40 + _t21*_t45 + _t21*_t51 + _t21*_t56 + _t26*_t27 + _t26*_t36 + _t26*_t42 + _t26*_t48 + _t26*_t52 + _t26*_t59 + _t26*_t61 + _t30*_t31 + _t30*_t41 + _t30*_t47 + _t30*_t53 + _t30*_t57 + _t30*_t62 + _t30*_t65 + _t37*_t38 + _t37*_t49 + _t37*_t55 + _t37*_t60 + _t37*_t64 + _t37*_t67 + _t37*_t68 + _t43*_t44 + _t43*_t54 + _t43*_t58 + _t43*_t63 + _t43*_t66 + _t43*_t69 + _t43*_t70 - 0.0058828844909941372*_t5 - 0.032121495135261673*_t6 + 0.029439726278665657*_t7 + 0.08753451580964014*_t8 - 0.028551704175417885*_t9 + 1.188675387736428;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t17*_t71 + _t20*_t71 + _t22*_t80 + _t23*_t71 + _t24*_t79 + _t25*_t71 + _t27*_t81 + _t28*_t80 + _t29*_t79 + _t31*_t82 + _t32*_t71 + _t33*_t80 + _t34*_t79 + _t35*_t71 + _t36*_t81 + _t38*_t83 + _t39*_t79 + _t4*_t71 + _t40*_t80 + _t41*_t82 + _t42*_t81 + _t44*_t84 + _t45*_t80 + _t46*_t79 + _t47*_t82 + _t48*_t81 + _t49*_t83 + _t50*_t79 + _t51*_t80 + _t52*_t81 + _t53*_t82 + _t54*_t84 + _t55*_t83 + _t56*_t80 + _t57*_t82 + _t58*_t84 + _t59*_t81 + _t60*_t83 + _t61*_t81 + _t62*_t82 + _t63*_t84 + _t64*_t83 + _t65*_t82 + _t66*_t84 + _t67*_t83 + _t68*_t83 + _t69*_t84 + _t70*_t84 + 0.20748619661467273*_t71 + _t72*_t73 - 0.011765768981988274*_t72 - 0.09636448540578502*_t74 + 0.11775890511466263*_t75 + 0.4376725790482007*_t76 - 0.17131022505250731*_t77 - 0.47225184058624103*_t78;
  out[1] = df_dt;
  const double df_dx2 = _hc1[0]*_t111 + _hc1[0]*_t113 + _hc1[0]*_t124 + _hc1[0]*_t126 + _hc1[0]*_t138 + _hc1[0]*_t93 - _hc1[0]*_t95 + 0.0056048057497374659*_t100 + 0.004574039837527152*_t101 + _t102*_t22 + _t102*_t28 + _t102*_t33 + _t102*_t40 + _t102*_t45 + _t102*_t51 + _t102*_t56 + _t103*_t27 + _t103*_t36 + _t103*_t42 + _t103*_t48 + _t103*_t52 + _t103*_t59 + _t103*_t61 + _t104*_t21 - _t105*_t21 + _t106*_t26 + _t107*_t31 + _t107*_t41 + _t107*_t47 + _t107*_t53 + _t107*_t57 + _t107*_t62 + _t107*_t65 - _t108*_t26 + _t109*_t38 + _t109*_t49 + _t109*_t55 + _t109*_t60 + _t109*_t64 + _t109*_t67 + _t109*_t68 + _t110*_t30 - _t112*_t30 + _t114*_t37 - _t115*_t37 + _t116*_t43 + _t117*_t44 + _t117*_t54 + _t117*_t58 + _t117*_t63 + _t117*_t66 + _t117*_t69 + _t117*_t70 - _t118*_t43 + _t119*_t18 + _t120*_t18 + _t121*_t21 + _t122*_t21 + _t123*_t26 + _t125*_t26 + _t127*_t30 + _t128*_t30 + _t129*_t37 + _t130*_t37 + _t131*_t18 + _t132*_t43 + _t133*_t18 + _t134*_t43 + _t135*_t21 + _t136*_t21 + _t137*_t26 + _t139*_t26 + _t140*_t30 + _t141*_t30 + _t142*_t37 + _t143*_t37 + _t144*_t18 + _t145*_t43 + _t146*_t43 + _t147*_t21 + _t148*_t26 + _t149*_t30 + _t150*_t37 + _t151*_t43 + _t17*_t85 + 7.4776606536017084e-5*_t18*_t92 - 0.00014422588072818613*_t19*_t92 + _t20*_t85 + _t23*_t85 + _t24*_t96 + _t25*_t85 + _t29*_t96 + _t32*_t85 + _t34*_t96 + _t35*_t85 + _t39*_t96 + _t4*_t85 + _t46*_t96 + _t50*_t96 + _t73*_t86 + 0.20748619661467273*_t85 - 0.011765768981988274*_t86 - 0.09636448540578502*_t87 + 0.11775890511466263*_t88 + 0.4376725790482007*_t89 - 0.17131022505250731*_t90 - 0.47225184058624103*_t91 - 0.0067329608631305102*_t92 - 0.030918906126015771*_t94 + 0.00092711002337952392*_t97 - 0.00017450888231879161*_t98 - 0.0033099132122410782*_t99;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t153*_t17 + _t153*_t20 + _t153*_t23 + _t153*_t25 + _t153*_t32 + _t153*_t35 + _t153*_t4 + 0.20748619661467273*_t153 + _t154*_t73 - 0.011765768981988274*_t154 + _t156*_t73 - 0.011765768981988274*_t156 - 0.19272897081157004*_t157 - 0.09636448540578502*_t158 + 0.11775890511466263*_t159 + 0.4376725790482007*_t160 - 0.17131022505250731*_t161 - 0.47225184058624103*_t162 + 0.35327671534398788*_t163 + 1.7506903161928028*_t164 - 0.85655112526253654*_t165 - 2.8335110435174462*_t166 + _t167*_t24 + _t167*_t29 + _t167*_t34 + _t167*_t39 + _t167*_t46 + _t167*_t50 + _t168*_t24 + _t168*_t29 + _t168*_t34 + _t168*_t39 + _t168*_t46 + _t168*_t50 + _t169*_t22 + _t169*_t28 + _t169*_t33 + _t169*_t40 + _t169*_t45 + _t169*_t51 + _t169*_t56 + _t170*_t27 + _t170*_t36 + _t170*_t42 + _t170*_t48 + _t170*_t52 + _t170*_t59 + _t170*_t61 + _t171*_t31 + _t171*_t41 + _t171*_t47 + _t171*_t53 + _t171*_t57 + _t171*_t62 + _t171*_t65 + _t172*_t38 + _t172*_t49 + _t172*_t55 + _t172*_t60 + _t172*_t64 + _t172*_t67 + _t172*_t68 + _t173*_t44 + _t173*_t54 + _t173*_t58 + _t173*_t63 + _t173*_t66 + _t173*_t69 + _t173*_t70;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = _t104*_t80 - _t105*_t80 + _t106*_t81 - _t108*_t81 + _t110*_t82 + _t111*_t71 - _t112*_t82 + _t113*_t71 + _t114*_t83 - _t115*_t83 + _t116*_t84 - _t118*_t84 + _t119*_t79 + _t120*_t79 + _t121*_t80 + _t122*_t80 + _t123*_t81 + _t124*_t71 + _t125*_t81 + _t126*_t71 + _t127*_t82 + _t128*_t82 + _t129*_t83 + _t130*_t83 + _t131*_t79 + _t132*_t84 + _t133*_t79 + _t134*_t84 + _t135*_t80 + _t136*_t80 + _t137*_t81 + _t138*_t71 + _t139*_t81 + _t140*_t82 + _t141*_t82 + _t142*_t83 + _t143*_t83 + _t144*_t79 + _t145*_t84 + _t146*_t84 + _t147*_t80 + _t148*_t81 + _t149*_t82 + _t150*_t83 + _t151*_t84 + _t17*_t175 + _t175*_t20 + _t175*_t23 + _t175*_t25 + _t175*_t32 + _t175*_t35 + _t175*_t4 + 0.20748619661467273*_t175 + _t176*_t73 - 0.011765768981988274*_t176 + _t177*_t73 - 0.011765768981988274*_t177 - 0.19272897081157004*_t178 - 0.09636448540578502*_t179 + 0.11775890511466263*_t180 + 0.4376725790482007*_t181 - 0.17131022505250731*_t182 - 0.47225184058624103*_t183 + 0.35327671534398788*_t184 + 1.7506903161928028*_t185 - 0.85655112526253654*_t186 - 2.8335110435174462*_t187 + _t188*_t72 + _t189*_t24 + _t189*_t29 + _t189*_t34 + _t189*_t39 + _t189*_t46 + _t189*_t50 - _t190*_t72 + _t191*_t24 + _t191*_t29 + _t191*_t34 + _t191*_t39 + _t191*_t46 + _t191*_t50 + _t192*_t22 + _t192*_t28 + _t192*_t33 + _t192*_t40 + _t192*_t45 + _t192*_t51 + _t192*_t56 + _t193*_t27 + _t193*_t36 + _t193*_t42 + _t193*_t48 + _t193*_t52 + _t193*_t59 + _t193*_t61 + _t194*_t31 + _t194*_t41 + _t194*_t47 + _t194*_t53 + _t194*_t57 + _t194*_t62 + _t194*_t65 + _t195*_t38 + _t195*_t49 + _t195*_t55 + _t195*_t60 + _t195*_t64 + _t195*_t67 + _t195*_t68 + _t196*_t44 + _t196*_t54 + _t196*_t58 + _t196*_t63 + _t196*_t66 + _t196*_t69 + _t196*_t70 + _t71*_t93 - _t71*_t95;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = _hc1[0]*_t211 + _hc1[0]*_t262 + _hc1[0]*_t275 + _hc1[0]*_t283 + _hc1[0]*_t292 + _hc1[0]*_t298 + _t102*_t239 - _t102*_t242 + _t103*_t241 - _t103*_t246 + _t107*_t254 - _t107*_t258 + _t109*_t257 - _t109*_t261 + _t111*_t249 + _t113*_t249 + _t117*_t263 - _t117*_t265 + _t119*_t251 + _t120*_t251 + _t121*_t264 + _t122*_t264 + _t123*_t266 + _t124*_t249 + _t125*_t266 + _t126*_t249 + _t127*_t269 + _t128*_t269 + _t129*_t271 + _t130*_t271 + _t131*_t251 + _t132*_t276 + _t133*_t251 + _t134*_t276 + _t135*_t264 + _t136*_t264 + _t137*_t266 + _t138*_t249 + _t139*_t266 + _t140*_t269 + _t141*_t269 + _t142*_t271 + _t143*_t271 + _t144*_t251 + _t145*_t276 + _t146*_t276 + _t147*_t264 + _t148*_t266 + _t149*_t269 + _t150*_t271 + _t151*_t276 + _t17*_t198 + 3.1156919390007118e-6*_t18*_t204 - 6.0094116970077554e-6*_t18*_t214 + _t18*_t268 + _t18*_t279 + _t18*_t286 + _t18*_t295 + _t18*_t301 - 6.0094116970077554e-6*_t19*_t204 + _t198*_t20 + _t198*_t23 + _t198*_t25 + _t198*_t32 + _t198*_t35 + _t198*_t4 + 0.20748619661467273*_t198 + _t199*_t73 - 0.011765768981988274*_t199 + _t200*_t73 - 0.011765768981988274*_t200 - 0.00028054003596377126*_t204 - 0.19272897081157004*_t205 - 0.09636448540578502*_t206 + 0.11775890511466263*_t207 + 0.4376725790482007*_t208 - 0.17131022505250731*_t209 + _t21*_t236 - _t21*_t237 - _t21*_t238 + _t21*_t270 + _t21*_t280 + _t21*_t289 + _t21*_t296 + _t21*_t303 - 0.47225184058624103*_t210 - _t212*_t220 - 0.0012882877552506571*_t212 - _t214*_t220 - 0.0012882877552506571*_t214 + 0.35327671534398788*_t215 + 1.7506903161928028*_t216 - 0.85655112526253654*_t217 - 2.8335110435174462*_t218 + _t219*_t85 + _t22*_t253 + 7.7259168614960327e-5*_t221 + 3.8629584307480164e-5*_t222 - 7.2712034299496505e-6*_t223 - 0.00013791305051004493*_t224 + 0.00023353357290572775*_t225 + 0.000190584993230298*_t226 + _t227*_t86 - _t228*_t85 - _t229*_t86 + _t230*_t24 + _t230*_t29 + _t230*_t34 + _t230*_t39 + _t230*_t46 + _t230*_t50 - 2.1813610289848951e-5*_t231 - 0.00055165220204017971*_t232 + 0.0011676678645286387*_t233 + 0.001143509959381788*_t234 + _t235*_t24 + _t235*_t29 + _t235*_t34 + _t235*_t39 + _t235*_t46 + _t235*_t50 + _t240*_t26 - _t243*_t26 - _t244*_t26 + _t245*_t30 - _t247*_t30 - _t248*_t30 + _t250*_t37 - _t252*_t37 + _t253*_t28 + _t253*_t33 + _t253*_t40 + _t253*_t45 + _t253*_t51 + _t253*_t56 - _t255*_t37 + _t256*_t43 - _t259*_t43 + _t26*_t272 + _t26*_t282 + _t26*_t290 + _t26*_t297 + _t26*_t304 - _t260*_t43 + _t267*_t27 + _t267*_t36 + _t267*_t42 + _t267*_t48 + _t267*_t52 + _t267*_t59 + _t267*_t61 + _t273*_t31 + _t273*_t41 + _t273*_t47 + _t273*_t53 + _t273*_t57 + _t273*_t62 + _t273*_t65 + _t274*_t30 + _t277*_t37 + _t278*_t43 + _t281*_t38 + _t281*_t49 + _t281*_t55 + _t281*_t60 + _t281*_t64 + _t281*_t67 + _t281*_t68 + _t284*_t30 + _t285*_t37 + _t287*_t43 + _t288*_t44 + _t288*_t54 + _t288*_t58 + _t288*_t63 + _t288*_t66 + _t288*_t69 + _t288*_t70 + _t291*_t30 + _t293*_t37 + _t294*_t43 + _t299*_t30 + _t30*_t305 + _t300*_t37 + _t302*_t43 + _t306*_t37 + _t307*_t43;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t17*_t309 + _t20*_t309 + _t22*_t332 + _t23*_t309 + _t24*_t330 + _t24*_t331 + _t25*_t309 + _t27*_t333 + _t28*_t332 + _t29*_t330 + _t29*_t331 + _t309*_t32 + _t309*_t35 + _t309*_t4 + 0.20748619661467273*_t309 + _t31*_t335 + _t310*_t73 - 0.011765768981988274*_t310 + _t312*_t316 - 0.035297306945964823*_t312 - 0.19272897081157004*_t314 - 0.57818691243471013*_t315 + 0.70655343068797577*_t317 - 0.09636448540578502*_t318 + 0.11775890511466263*_t319 + 0.4376725790482007*_t320 - 0.17131022505250731*_t321 - 0.47225184058624103*_t322 + 1.0598301460319637*_t323 + 5.2520709485784084*_t324 - 2.5696533757876097*_t325 - 8.5005331305523386*_t326 + 5.2520709485784084*_t327 - 3.4262045010501462*_t328 - 14.167555217587231*_t329 + _t33*_t332 + _t330*_t34 + _t330*_t39 + _t330*_t46 + _t330*_t50 + _t331*_t34 + _t331*_t39 + _t331*_t46 + _t331*_t50 + _t332*_t40 + _t332*_t45 + _t332*_t51 + _t332*_t56 + _t333*_t36 + _t333*_t42 + _t333*_t48 + _t333*_t52 + _t333*_t59 + _t333*_t61 + _t335*_t41 + _t335*_t47 + _t335*_t53 + _t335*_t57 + _t335*_t62 + _t335*_t65 + _t337*_t38 + _t337*_t49 + _t337*_t55 + _t337*_t60 + _t337*_t64 + _t337*_t67 + _t337*_t68 + _t338*_t44 + _t338*_t54 + _t338*_t58 + _t338*_t63 + _t338*_t66 + _t338*_t69 + _t338*_t70;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = _t104*_t169 - _t105*_t169 + _t106*_t170 - _t108*_t170 + _t110*_t171 + _t111*_t153 - _t112*_t171 + _t113*_t153 + _t114*_t172 - _t115*_t172 + _t116*_t173 - _t118*_t173 + _t119*_t167 + _t119*_t168 + _t120*_t167 + _t120*_t168 + _t121*_t169 + _t122*_t169 + _t123*_t170 + _t124*_t153 + _t125*_t170 + _t126*_t153 + _t127*_t171 + _t128*_t171 + _t129*_t172 + _t130*_t172 + _t131*_t167 + _t131*_t168 + _t132*_t173 + _t133*_t167 + _t133*_t168 + _t134*_t173 + _t135*_t169 + _t136*_t169 + _t137*_t170 + _t138*_t153 + _t139*_t170 + _t140*_t171 + _t141*_t171 + _t142*_t172 + _t143*_t172 + _t144*_t167 + _t144*_t168 + _t145*_t173 + _t146*_t173 + _t147*_t169 + _t148*_t170 + _t149*_t171 + _t150*_t172 + _t151*_t173 + _t153*_t93 - _t153*_t95 + _t154*_t188 - _t154*_t190 + _t156*_t188 - _t156*_t190 + _t17*_t340 + _t20*_t340 + _t22*_t360 + _t23*_t340 + _t24*_t358 + _t24*_t359 + _t25*_t340 + _t27*_t361 + _t28*_t360 + _t29*_t358 + _t29*_t359 + _t31*_t363 + _t316*_t342 + _t32*_t340 + _t33*_t360 + _t34*_t358 + _t34*_t359 + _t340*_t35 + _t340*_t4 + 0.20748619661467273*_t340 + _t341*_t73 - 0.011765768981988274*_t341 - 0.035297306945964823*_t342 - 0.19272897081157004*_t343 - 0.57818691243471013*_t344 + 0.70655343068797577*_t345 - 0.09636448540578502*_t346 + 0.11775890511466263*_t347 + 0.4376725790482007*_t348 - 0.17131022505250731*_t349 - 0.47225184058624103*_t350 + 1.0598301460319637*_t351 + 5.2520709485784084*_t352 - 2.5696533757876097*_t353 - 8.5005331305523386*_t354 + 5.2520709485784084*_t355 - 3.4262045010501462*_t356 - 14.167555217587231*_t357 + _t358*_t39 + _t358*_t46 + _t358*_t50 + _t359*_t39 + _t359*_t46 + _t359*_t50 + _t36*_t361 + _t360*_t40 + _t360*_t45 + _t360*_t51 + _t360*_t56 + _t361*_t42 + _t361*_t48 + _t361*_t52 + _t361*_t59 + _t361*_t61 + _t363*_t41 + _t363*_t47 + _t363*_t53 + _t363*_t57 + _t363*_t62 + _t363*_t65 + _t364*_t38 + _t364*_t49 + _t364*_t55 + _t364*_t60 + _t364*_t64 + _t364*_t67 + _t364*_t68 + _t366*_t44 + _t366*_t54 + _t366*_t58 + _t366*_t63 + _t366*_t66 + _t366*_t69 + _t366*_t70;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = _t111*_t393 + _t113*_t393 + _t119*_t394 + _t119*_t395 + _t120*_t394 + _t120*_t395 + _t121*_t397 + _t122*_t397 + _t123*_t399 + _t124*_t393 + _t125*_t399 + _t126*_t393 + _t127*_t400 + _t128*_t400 + _t129*_t403 + _t130*_t403 + _t131*_t394 + _t131*_t395 + _t132*_t404 + _t133*_t394 + _t133*_t395 + _t134*_t404 + _t135*_t397 + _t136*_t397 + _t137*_t399 + _t138*_t393 + _t139*_t399 + _t140*_t400 + _t141*_t400 + _t142*_t403 + _t143*_t403 + _t144*_t394 + _t144*_t395 + _t145*_t404 + _t146*_t404 + _t147*_t397 + _t148*_t399 + _t149*_t400 + _t150*_t403 + _t151*_t404 + _t17*_t368 + _t175*_t219 - _t175*_t228 + _t176*_t227 - _t176*_t229 + _t177*_t227 - _t177*_t229 + _t192*_t239 - _t192*_t242 + _t193*_t241 - _t193*_t246 + _t194*_t254 - _t194*_t258 + _t195*_t257 - _t195*_t261 + _t196*_t263 - _t196*_t265 + _t20*_t368 + _t211*_t71 + _t22*_t396 + _t23*_t368 + _t236*_t80 - _t237*_t80 - _t238*_t80 + _t24*_t391 + _t24*_t392 + _t240*_t81 - _t243*_t81 - _t244*_t81 + _t245*_t82 - _t247*_t82 - _t248*_t82 + _t25*_t368 + _t250*_t83 - _t252*_t83 - _t255*_t83 + _t256*_t84 - _t259*_t84 - _t260*_t84 + _t262*_t71 + _t268*_t79 + _t27*_t398 + _t270*_t80 + _t272*_t81 + _t274*_t82 + _t275*_t71 + _t277*_t83 + _t278*_t84 + _t279*_t79 + _t28*_t396 + _t280*_t80 + _t282*_t81 + _t283*_t71 + _t284*_t82 + _t285*_t83 + _t286*_t79 + _t287*_t84 + _t289*_t80 + _t29*_t391 + _t29*_t392 + _t290*_t81 + _t291*_t82 + _t292*_t71 + _t293*_t83 + _t294*_t84 + _t295*_t79 + _t296*_t80 + _t297*_t81 + _t298*_t71 + _t299*_t82 + _t300*_t83 + _t301*_t79 + _t302*_t84 + _t303*_t80 + _t304*_t81 + _t305*_t82 + _t306*_t83 + _t307*_t84 + _t31*_t402 + _t316*_t370 + _t32*_t368 + _t33*_t396 + _t34*_t391 + _t34*_t392 + _t35*_t368 + _t36*_t398 + _t368*_t4 + 0.20748619661467273*_t368 + _t369*_t73 - 0.011765768981988274*_t369 - 0.035297306945964823*_t370 - 0.19272897081157004*_t371 - 0.57818691243471013*_t372 + 0.70655343068797577*_t373 - 0.09636448540578502*_t374 + 0.11775890511466263*_t375 + 0.4376725790482007*_t376 - 0.17131022505250731*_t377 - 0.47225184058624103*_t378 + 1.0598301460319637*_t379 + _t38*_t405 + 5.2520709485784084*_t380 - 2.5696533757876097*_t381 - 8.5005331305523386*_t382 + 5.2520709485784084*_t383 - 3.4262045010501462*_t384 - 14.167555217587231*_t385 + _t386*_t72 - _t387*_t71 - _t388*_t71 - _t389*_t72 + _t39*_t391 + _t39*_t392 - _t390*_t72 + _t391*_t46 + _t391*_t50 + _t392*_t46 + _t392*_t50 + _t396*_t40 + _t396*_t45 + _t396*_t51 + _t396*_t56 + _t398*_t42 + _t398*_t48 + _t398*_t52 + _t398*_t59 + _t398*_t61 + _t402*_t41 + _t402*_t47 + _t402*_t53 + _t402*_t57 + _t402*_t62 + _t402*_t65 + _t405*_t49 + _t405*_t55 + _t405*_t60 + _t405*_t64 + _t405*_t67 + _t405*_t68 + _t406*_t44 + _t406*_t54 + _t406*_t58 + _t406*_t63 + _t406*_t66 + _t406*_t69 + _t406*_t70;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = _hc1[0]*_t411 - _hc1[0]*_t419 - _hc1[0]*_t420 + _hc1[0]*_t490 + _hc1[0]*_t501 + _hc1[0]*_t522 + _hc1[0]*_t532 + _hc1[0]*_t547 + _t102*_t467 - _t102*_t473 + _t103*_t470 - _t103*_t474 - _t103*_t475 + _t107*_t482 - _t107*_t487 + _t109*_t484 - _t109*_t489 + _t111*_t481 + _t113*_t481 + _t117*_t493 - _t117*_t497 + _t119*_t483 + _t119*_t486 + _t120*_t483 + _t120*_t486 + _t121*_t509 + _t122*_t509 + _t123*_t521 + _t124*_t481 + _t125*_t521 + _t126*_t481 + _t127*_t530 + _t128*_t530 + _t129*_t542 + _t130*_t542 + _t131*_t483 + _t131*_t486 + _t132*_t546 + _t133*_t483 + _t133*_t486 + _t134*_t546 + _t135*_t509 + _t136*_t509 + _t137*_t521 + _t138*_t481 + _t139*_t521 + _t140*_t530 + _t141*_t530 + _t142*_t542 + _t143*_t542 + _t144*_t483 + _t144*_t486 + _t145*_t546 + _t146*_t546 + _t147*_t509 + _t148*_t521 + _t149*_t530 + _t150*_t542 + _t151*_t546 + _t17*_t410 + 7.7892298475017797e-7*_t18*_t408 - 4.5070587727558166e-6*_t18*_t413 + _t18*_t499 + _t18*_t511 + _t18*_t529 + _t18*_t539 + _t18*_t550 - 1.5023529242519389e-6*_t19*_t408 + _t198*_t452 - _t198*_t457 + _t199*_t456 - _t199*_t460 + _t20*_t410 + _t200*_t456 - _t200*_t460 + _t21*_t459 - _t21*_t461 - _t21*_t462 + _t21*_t500 + _t21*_t513 + _t21*_t531 + _t21*_t541 + _t21*_t551 - _t212*_t451 - _t212*_t453 - _t212*_t471 - _t212*_t485 - _t212*_t488 - _t212*_t495 - _t214*_t451 + _t22*_t492 + _t23*_t410 + _t24*_t454 + _t24*_t455 + _t25*_t410 + _t253*_t491 - _t253*_t494 + _t26*_t463 - _t26*_t464 - _t26*_t465 + _t26*_t502 + _t26*_t514 + _t26*_t533 + _t26*_t543 + _t26*_t552 + _t262*_t496 + _t267*_t503 - _t267*_t506 + _t268*_t498 + _t27*_t505 + _t270*_t507 + _t272*_t508 + _t273*_t516 - _t273*_t518 + _t274*_t515 + _t275*_t496 + _t277*_t517 + _t278*_t523 + _t279*_t498 + _t28*_t492 + _t280*_t507 + _t281*_t527 - _t281*_t528 + _t282*_t508 + _t283*_t496 + _t284*_t515 + _t285*_t517 + _t286*_t498 + _t287*_t523 + _t288*_t535 - _t288*_t536 + _t289*_t507 + _t29*_t454 + _t29*_t455 + _t290*_t508 + _t291*_t515 + _t292*_t496 + _t293*_t517 + _t294*_t523 + _t295*_t498 + _t296*_t507 + _t297*_t508 + _t298*_t496 + _t299*_t515 + _t30*_t466 - _t30*_t468 - _t30*_t469 + _t30*_t504 + _t30*_t519 + _t30*_t534 + _t30*_t544 + _t30*_t553 + _t300*_t517 + _t301*_t498 + _t302*_t523 + _t303*_t507 + _t304*_t508 + _t305*_t515 + _t306*_t517 + _t307*_t523 + _t31*_t526 + _t316*_t415 + _t32*_t410 + _t33*_t492 + _t34*_t454 + _t34*_t455 + _t35*_t410 + _t36*_t505 + _t37*_t472 - _t37*_t476 - _t37*_t477 + _t37*_t510 + _t37*_t520 + _t37*_t538 + _t37*_t545 + _t37*_t554 + _t38*_t537 + _t39*_t454 + _t39*_t455 + _t4*_t410 + _t40*_t492 - 7.0135008990942815e-5*_t408 + _t41*_t526 + 0.20748619661467273*_t410 - 0.00032207193881266429*_t412 - 0.00096621581643799286*_t413 + _t414*_t73 - 0.011765768981988274*_t414 - 0.035297306945964823*_t415 + 1.9314792153740082e-5*_t417 - 0.19272897081157004*_t418 + _t42*_t505 + 5.7944376461220246e-5*_t421 - 0.57818691243471013*_t422 - 1.0906805144924476e-5*_t423 + 9.6573960768700409e-6*_t424 - 1.8178008574874126e-6*_t425 - 3.4478262627511232e-5*_t426 + 5.8383393226431937e-5*_t427 + 4.7646248307574501e-5*_t428 + 0.70655343068797577*_t429 + _t43*_t478 - _t43*_t479 - _t43*_t480 + _t43*_t512 + _t43*_t524 + _t43*_t540 + _t43*_t548 + _t43*_t555 - 0.09636448540578502*_t430 + 0.11775890511466263*_t431 + 0.4376725790482007*_t432 - 0.17131022505250731*_t433 - 0.47225184058624103*_t434 - 1.6360207717386713e-5*_t435 - 0.00041373915153013478*_t436 + 0.00087575089839647905*_t437 + 0.00085763246953634101*_t438 + 1.0598301460319637*_t439 + _t44*_t549 + 5.2520709485784084*_t440 - 2.5696533757876097*_t441 - 8.5005331305523386*_t442 - 0.00041373915153013478*_t443 + 0.0011676678645286387*_t444 + 0.001429387449227235*_t445 + 5.2520709485784084*_t446 - 3.4262045010501462*_t447 - 14.167555217587231*_t448 + _t449*_t85 + _t45*_t492 + _t450*_t86 + _t454*_t46 + _t454*_t50 + _t455*_t46 + _t455*_t50 - _t458*_t86 + _t47*_t526 + _t48*_t505 + _t49*_t537 + _t492*_t51 + _t492*_t56 + _t505*_t52 + _t505*_t59 + _t505*_t61 + _t526*_t53 + _t526*_t57 + _t526*_t62 + _t526*_t65 + _t537*_t55 + _t537*_t60 + _t537*_t64 + _t537*_t67 + _t537*_t68 + _t54*_t549 + _t549*_t58 + _t549*_t63 + _t549*_t66 + _t549*_t69 + _t549*_t70;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t17*_t557 + _t20*_t557 + _t22*_t593 + _t23*_t557 + _t24*_t590 + _t24*_t591 + _t24*_t592 + _t25*_t557 + _t27*_t594 + _t28*_t593 + _t29*_t590 + _t29*_t591 + _t29*_t592 + _t31*_t596 + _t316*_t564 + _t32*_t557 + _t33*_t593 + _t34*_t590 + _t34*_t591 + _t34*_t592 + _t35*_t557 + _t36*_t594 + _t38*_t598 + _t39*_t590 + _t39*_t591 + _t39*_t592 + _t4*_t557 + _t40*_t593 + _t41*_t596 + _t42*_t594 + _t44*_t599 + _t45*_t593 + _t46*_t590 + _t46*_t591 + _t46*_t592 + _t47*_t596 + _t48*_t594 + _t49*_t598 + _t50*_t590 + _t50*_t591 + _t50*_t592 + _t51*_t593 + _t52*_t594 + _t53*_t596 + _t54*_t599 + _t55*_t598 + 0.20748619661467273*_t557 + _t558*_t73 - 0.011765768981988274*_t558 + _t56*_t593 + _t560*_t566 - 0.047063075927953097*_t560 - _t562*_t581 + 0.70655343068797577*_t562 - 0.035297306945964823*_t564 - 0.77091588324628016*_t565 + 10.504141897156817*_t567 - 0.57818691243471013*_t568 - 0.09636448540578502*_t569 + _t57*_t596 + 0.11775890511466263*_t570 + 0.4376725790482007*_t571 - 0.17131022505250731*_t572 - 0.47225184058624103*_t573 - 1.1563738248694203*_t575 + 4.2393205841278546*_t576 + 1.4131068613759515*_t577 + 7.0027612647712112*_t578 - 3.4262045010501462*_t579 + _t58*_t599 - 11.334044174069785*_t580 + 1.0598301460319637*_t582 - 56.670220870348924*_t583 + 5.2520709485784084*_t584 - 2.5696533757876097*_t585 - 8.5005331305523386*_t586 + 31.51242569147045*_t587 - 20.557227006300877*_t588 - 85.005331305523386*_t589 + _t59*_t594 + _t594*_t61 + _t596*_t62 + _t596*_t65 + _t598*_t60 + _t598*_t64 + _t598*_t67 + _t598*_t68 + _t599*_t63 + _t599*_t66 + _t599*_t69 + _t599*_t70;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = _t104*_t332 - _t105*_t332 + _t106*_t333 - _t108*_t333 + _t110*_t335 + _t111*_t309 - _t112*_t335 + _t113*_t309 + _t114*_t337 - _t115*_t337 + _t116*_t338 - _t118*_t338 + _t119*_t330 + _t119*_t331 + _t120*_t330 + _t120*_t331 + _t121*_t332 + _t122*_t332 + _t123*_t333 + _t124*_t309 + _t125*_t333 + _t126*_t309 + _t127*_t335 + _t128*_t335 + _t129*_t337 + _t130*_t337 + _t131*_t330 + _t131*_t331 + _t132*_t338 + _t133*_t330 + _t133*_t331 + _t134*_t338 + _t135*_t332 + _t136*_t332 + _t137*_t333 + _t138*_t309 + _t139*_t333 + _t140*_t335 + _t141*_t335 + _t142*_t337 + _t143*_t337 + _t144*_t330 + _t144*_t331 + _t145*_t338 + _t146*_t338 + _t147*_t332 + _t148*_t333 + _t149*_t335 + _t150*_t337 + _t151*_t338 + _t17*_t601 + _t188*_t310 - _t190*_t310 + _t20*_t601 + _t22*_t631 + _t23*_t601 + _t24*_t628 + _t24*_t629 + _t24*_t630 + _t25*_t601 + _t27*_t632 + _t28*_t631 + _t29*_t628 + _t29*_t629 + _t29*_t630 + _t309*_t93 - _t309*_t95 + _t31*_t635 + _t312*_t456 - _t312*_t460 + _t316*_t605 + _t32*_t601 + _t33*_t631 + _t34*_t628 + _t34*_t629 + _t34*_t630 + _t35*_t601 + _t36*_t632 + _t38*_t638 + _t39*_t628 + _t39*_t629 + _t39*_t630 + _t4*_t601 + _t40*_t631 + _t41*_t635 + _t42*_t632 + _t44*_t639 + _t45*_t631 + _t46*_t628 + _t46*_t629 + _t46*_t630 + _t47*_t635 + _t48*_t632 + _t49*_t638 + _t50*_t628 + _t50*_t629 + _t50*_t630 + _t51*_t631 + _t52*_t632 + _t53*_t635 + _t54*_t639 + _t55*_t638 + _t56*_t631 + _t566*_t603 + _t57*_t635 + _t58*_t639 - _t581*_t604 + _t59*_t632 + _t60*_t638 + 0.20748619661467273*_t601 + _t602*_t73 - 0.011765768981988274*_t602 - 0.047063075927953097*_t603 + 0.70655343068797577*_t604 - 0.035297306945964823*_t605 - 0.77091588324628016*_t606 + 10.504141897156817*_t607 - 0.57818691243471013*_t608 - 0.09636448540578502*_t609 + _t61*_t632 + 0.11775890511466263*_t610 + 0.4376725790482007*_t611 - 0.17131022505250731*_t612 - 0.47225184058624103*_t613 - 1.1563738248694203*_t614 + 4.2393205841278546*_t615 + 1.4131068613759515*_t616 + 7.0027612647712112*_t617 - 3.4262045010501462*_t618 - 11.334044174069785*_t619 + _t62*_t635 + 1.0598301460319637*_t620 - 56.670220870348924*_t621 + 5.2520709485784084*_t622 - 2.5696533757876097*_t623 - 8.5005331305523386*_t624 + 31.51242569147045*_t625 - 20.557227006300877*_t626 - 85.005331305523386*_t627 + _t63*_t639 + _t635*_t65 + _t638*_t64 + _t638*_t67 + _t638*_t68 + _t639*_t66 + _t639*_t69 + _t639*_t70;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = _t111*_t671 + _t113*_t671 + _t119*_t672 + _t119*_t673 + _t120*_t672 + _t120*_t673 + _t121*_t674 + _t122*_t674 + _t123*_t676 + _t124*_t671 + _t125*_t676 + _t126*_t671 + _t127*_t677 + _t128*_t677 + _t129*_t679 + _t130*_t679 + _t131*_t672 + _t131*_t673 + _t132*_t680 + _t133*_t672 + _t133*_t673 + _t134*_t680 + _t135*_t674 + _t136*_t674 + _t137*_t676 + _t138*_t671 + _t139*_t676 + _t140*_t677 + _t141*_t677 + _t142*_t679 + _t143*_t679 + _t144*_t672 + _t144*_t673 + _t145*_t680 + _t146*_t680 + _t147*_t674 + _t148*_t676 + _t149*_t677 + _t150*_t679 + _t151*_t680 + _t153*_t211 + _t153*_t262 + _t153*_t275 + _t153*_t283 + _t153*_t292 + _t153*_t298 - _t153*_t387 - _t153*_t388 + _t154*_t386 - _t154*_t389 - _t154*_t390 + _t156*_t386 - _t156*_t389 - _t156*_t390 + _t167*_t268 + _t167*_t279 + _t167*_t286 + _t167*_t295 + _t167*_t301 + _t168*_t268 + _t168*_t279 + _t168*_t286 + _t168*_t295 + _t168*_t301 + _t169*_t236 - _t169*_t237 - _t169*_t238 + _t169*_t270 + _t169*_t280 + _t169*_t289 + _t169*_t296 + _t169*_t303 + _t17*_t641 + _t170*_t240 - _t170*_t243 - _t170*_t244 + _t170*_t272 + _t170*_t282 + _t170*_t290 + _t170*_t297 + _t170*_t304 + _t171*_t245 - _t171*_t247 - _t171*_t248 + _t171*_t274 + _t171*_t284 + _t171*_t291 + _t171*_t299 + _t171*_t305 + _t172*_t250 - _t172*_t252 - _t172*_t255 + _t172*_t277 + _t172*_t285 + _t172*_t293 + _t172*_t300 + _t172*_t306 + _t173*_t256 - _t173*_t259 - _t173*_t260 + _t173*_t278 + _t173*_t287 + _t173*_t294 + _t173*_t302 + _t173*_t307 + _t20*_t641 + _t219*_t340 + _t22*_t675 + _t227*_t341 - _t228*_t340 - _t229*_t341 + _t23*_t641 + _t239*_t360 + _t24*_t668 + _t24*_t669 + _t24*_t670 + _t241*_t361 - _t242*_t360 - _t246*_t361 + _t25*_t641 + _t254*_t363 + _t257*_t364 - _t258*_t363 - _t261*_t364 + _t263*_t366 - _t265*_t366 + _t27*_t678 + _t28*_t675 + _t29*_t668 + _t29*_t669 + _t29*_t670 + _t31*_t682 + _t316*_t645 + _t32*_t641 + _t33*_t675 + _t34*_t668 + _t34*_t669 + _t34*_t670 + 0.0013459789176483075*_t342*_t92 - 0.0025960658531073503*_t342*_t94 + _t35*_t641 + _t36*_t678 + _t38*_t684 + _t39*_t668 + _t39*_t669 + _t39*_t670 + _t4*_t641 + _t40*_t675 + _t41*_t682 + _t42*_t678 + _t44*_t685 + _t45*_t675 + _t46*_t668 + _t46*_t669 + _t46*_t670 + _t47*_t682 + _t48*_t678 + _t49*_t684 + _t50*_t668 + _t50*_t669 + _t50*_t670 + _t51*_t675 + _t52*_t678 + _t53*_t682 + _t54*_t685 + _t55*_t684 + _t56*_t675 + _t566*_t643 + _t57*_t682 + _t58*_t685 - _t581*_t644 + _t59*_t678 + _t60*_t684 + _t61*_t678 + _t62*_t682 + _t63*_t685 + _t64*_t684 + 0.20748619661467273*_t641 + _t642*_t73 - 0.011765768981988274*_t642 - 0.047063075927953097*_t643 + 0.70655343068797577*_t644 - 0.035297306945964823*_t645 - 0.77091588324628016*_t646 + 10.504141897156817*_t647 - 0.57818691243471013*_t648 - 0.09636448540578502*_t649 + _t65*_t682 + 0.11775890511466263*_t650 + 0.4376725790482007*_t651 - 0.17131022505250731*_t652 - 0.47225184058624103*_t653 - 1.1563738248694203*_t654 + 4.2393205841278546*_t655 + 1.4131068613759515*_t656 + 7.0027612647712112*_t657 - 3.4262045010501462*_t658 - 11.334044174069785*_t659 + _t66*_t685 + 1.0598301460319637*_t660 - 56.670220870348924*_t661 + 5.2520709485784084*_t662 - 2.5696533757876097*_t663 - 8.5005331305523386*_t664 + 31.51242569147045*_t665 - 20.557227006300877*_t666 - 85.005331305523386*_t667 + _t67*_t684 + _t68*_t684 + _t685*_t69 + _t685*_t70;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = _t111*_t719 + _t113*_t719 + _t119*_t720 + _t119*_t721 + _t120*_t720 + _t120*_t721 + _t121*_t727 + _t122*_t727 + _t123*_t729 + _t124*_t719 + _t125*_t729 + _t126*_t719 + _t127*_t733 + _t128*_t733 + _t129*_t735 + _t130*_t735 + _t131*_t720 + _t131*_t721 + _t132*_t738 + _t133*_t720 + _t133*_t721 + _t134*_t738 + _t135*_t727 + _t136*_t727 + _t137*_t729 + _t138*_t719 + _t139*_t729 + _t140*_t733 + _t141*_t733 + _t142*_t735 + _t143*_t735 + _t144*_t720 + _t144*_t721 + _t145*_t738 + _t146*_t738 + _t147*_t727 + _t148*_t729 + _t149*_t733 + _t150*_t735 + _t151*_t738 + _t17*_t687 + _t175*_t449 + _t176*_t450 - _t176*_t458 - _t176*_t715 + _t177*_t450 - _t177*_t458 - _t177*_t715 - 1.5064642655480989e-5*_t192*_t212 + _t192*_t467 - _t192*_t473 + _t193*_t470 - _t193*_t474 - _t193*_t475 - 1.8588567264865828e-5*_t194*_t212 + _t194*_t482 - _t194*_t487 - 2.0129783238744015e-5*_t195*_t212 + _t195*_t484 - _t195*_t489 - 1.8368976199350359e-5*_t196*_t212 + _t196*_t493 - _t196*_t497 + _t20*_t687 - _t212*_t714 - _t214*_t714 + _t22*_t725 + _t23*_t687 + _t24*_t716 + _t24*_t717 + _t24*_t718 + _t25*_t687 + _t262*_t722 + _t268*_t723 + _t268*_t724 + _t27*_t731 + _t270*_t726 + _t272*_t728 + _t274*_t730 + _t275*_t722 + _t277*_t732 + _t278*_t734 + _t279*_t723 + _t279*_t724 + _t28*_t725 + _t280*_t726 + _t282*_t728 + _t283*_t722 + _t284*_t730 + _t285*_t732 + _t286*_t723 + _t286*_t724 + _t287*_t734 + _t289*_t726 + _t29*_t716 + _t29*_t717 + _t29*_t718 + _t290*_t728 + _t291*_t730 + _t292*_t722 + _t293*_t732 + _t294*_t734 + _t295*_t723 + _t295*_t724 + _t296*_t726 + _t297*_t728 + _t298*_t722 + _t299*_t730 + _t300*_t732 + _t301*_t723 + _t301*_t724 + _t302*_t734 + _t303*_t726 + _t304*_t728 + _t305*_t730 + _t306*_t732 + _t307*_t734 + _t31*_t737 + _t316*_t691 + _t32*_t687 + _t33*_t725 + _t34*_t716 + _t34*_t717 + _t34*_t718 + _t35*_t687 + _t36*_t731 + _t368*_t452 - _t368*_t457 + _t369*_t456 - _t369*_t460 + 0.0020189683764724613*_t370*_t92 - 0.0038940987796610255*_t370*_t94 + _t38*_t740 + _t39*_t716 + _t39*_t717 + _t39*_t718 + _t396*_t491 - _t396*_t494 + _t398*_t503 - _t398*_t506 + _t4*_t687 + _t40*_t725 + _t402*_t516 - _t402*_t518 + _t405*_t527 - _t405*_t528 + _t406*_t535 - _t406*_t536 + 2.3367689542505339e-6*_t408*_t72 + _t41*_t737 + _t411*_t71 - 4.5070587727558166e-6*_t412*_t72 - 1.352117631826745e-5*_t413*_t72 - _t419*_t71 + _t42*_t731 - _t420*_t71 + _t44*_t741 + _t45*_t725 + _t459*_t80 + _t46*_t716 + _t46*_t717 + _t46*_t718 - _t461*_t80 - _t462*_t80 + _t463*_t81 - _t464*_t81 - _t465*_t81 + _t466*_t82 - _t468*_t82 - _t469*_t82 + _t47*_t737 + _t472*_t83 - _t476*_t83 - _t477*_t83 + _t478*_t84 - _t479*_t84 + _t48*_t731 - _t480*_t84 + _t49*_t740 + _t490*_t71 + _t499*_t79 + _t50*_t716 + _t50*_t717 + _t50*_t718 + _t500*_t80 + _t501*_t71 + _t502*_t81 + _t504*_t82 + _t51*_t725 + _t510*_t83 + _t511*_t79 + _t512*_t84 + _t513*_t80 + _t514*_t81 + _t519*_t82 + _t52*_t731 + _t520*_t83 + _t522*_t71 + _t524*_t84 + _t529*_t79 + _t53*_t737 + _t531*_t80 + _t532*_t71 + _t533*_t81 + _t534*_t82 + _t538*_t83 + _t539*_t79 + _t54*_t741 + _t540*_t84 + _t541*_t80 + _t543*_t81 + _t544*_t82 + _t545*_t83 + _t547*_t71 + _t548*_t84 + _t55*_t740 + _t550*_t79 + _t551*_t80 + _t552*_t81 + _t553*_t82 + _t554*_t83 + _t555*_t84 + _t56*_t725 + _t566*_t689 + _t57*_t737 + _t58*_t741 - _t581*_t690 + _t59*_t731 + _t60*_t740 + _t61*_t731 + _t62*_t737 + _t63*_t741 + _t64*_t740 + _t65*_t737 + _t66*_t741 + _t67*_t740 + _t68*_t740 + 0.20748619661467273*_t687 + _t688*_t73 - 0.011765768981988274*_t688 - 0.047063075927953097*_t689 + _t69*_t741 + 0.70655343068797577*_t690 - 0.035297306945964823*_t691 - 0.77091588324628016*_t692 + 10.504141897156817*_t693 - 0.57818691243471013*_t694 - 0.09636448540578502*_t695 + 0.11775890511466263*_t696 + 0.4376725790482007*_t697 - 0.17131022505250731*_t698 - 0.47225184058624103*_t699 + _t70*_t741 - 1.1563738248694203*_t700 + 4.2393205841278546*_t701 + 1.4131068613759515*_t702 + 7.0027612647712112*_t703 - 3.4262045010501462*_t704 - 11.334044174069785*_t705 + 1.0598301460319637*_t706 - 56.670220870348924*_t707 + 5.2520709485784084*_t708 - 2.5696533757876097*_t709 - 8.5005331305523386*_t710 + 31.51242569147045*_t711 - 20.557227006300877*_t712 - 85.005331305523386*_t713;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 2.1328189468008916e-6*_hc1[0]*_t751 - 7.8014358631873157e-7*_hc1[0]*_t760 - 3.1205743452749263e-6*_hc1[0]*_t761 - 2.3404307589561947e-6*_hc1[0]*_t770 + _hc1[0]*(2.7956039209692601e-7*_hc2[4]*_t1*_t749 - 1.118241568387704e-5*_t776 - 8.38681176290778e-6*_t778 - 1.39780196048463e-6*_t779 - 1.677362352581556e-5*_t784) + _hc1[0]*(-2.2830065737389229e-6*_t760 - 9.1320262949556915e-6*_t761 + 3.1962092032344919e-5*_t768 - 6.8490197212167686e-6*_t770 + 5.3270153387241533e-6*_t780 + 0.00019177255219406952*_t788 + 6.3924184064689839e-5*_t789 + 4.7943138048517379e-5*_t796) + _hc1[0]*(9.7880499561032773e-7*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 7.3410374670774579e-7*_hc2[0]*_t1*_t749*_t769 + 1.4682074934154916e-6*_hc2[2]*_t1*_t213*_t749 + 1.2235062445129097e-7*_hc2[4]*_t1*_t11*_t749 - 8.7393303179493548e-9*_t751 - 4.4046224802464747e-6*_t777 - 1.8352593667693645e-7*_t781 - 2.9364149868309832e-6*_t790 - 2.2023112401232373e-6*_t798 - 1.3213867440739424e-5*_t804) + _hc1[0]*(5.5414216568142128e-7*_t760 + 2.2165686627256851e-6*_t761 - 1.9949117964531166e-5*_t768 + 1.6624264970442638e-6*_t770 - 3.3248529940885277e-6*_t780 + 3.6573382934973805e-6*_t782 - 0.000119694707787187*_t788 - 3.9898235929062332e-5*_t789 + 7.3146765869947608e-5*_t791 + 0.00021944029760984282*_t795 - 2.9923676946796749e-5*_t796 + 5.4860074402460706e-5*_t799 + 0.00043888059521968565*_t805) + _hc1[0]*(-1.5182969264645265e-8*_t751 + 3.2795213611633774e-6*_t776 - 3.6074734972797151e-5*_t777 + 2.459641020872533e-6*_t778 + 4.0994017014542217e-7*_t779 - 1.5031139571998813e-6*_t781 + 1.3026987629065638e-6*_t783 + 4.9192820417450661e-6*_t784 - 2.4049823315198101e-5*_t790 + 3.126477030975753e-5*_t792 + 0.00015632385154878765*_t797 - 1.8037367486398575e-5*_t798 + 2.3448577732318148e-5*_t800 - 0.00010822420491839145*_t804 + 0.00023448577732318147*_t806) + 3.6898131211375105e-6*_t102*_t408 - 5.0215475518269965e-6*_t102*_t412 + 5.0612595850410331e-6*_t103*_t408 - 9.7077233385950419e-6*_t103*_t412 - 2.9123170015785126e-5*_t103*_t413 + 3.4848878455870608e-6*_t107*_t408 - 6.1961890882886094e-6*_t107*_t412 + 2.5895615943767952e-6*_t109*_t408 - 6.7099277462480052e-6*_t109*_t412 + _t111*_t809 + _t113*_t809 + 3.3683415177498195e-6*_t117*_t408 - 6.1229920664501199e-6*_t117*_t412 + _t119*_t810 + _t119*_t811 + _t120*_t810 + _t120*_t811 + _t121*_t825 + _t122*_t825 + _t123*_t829 + _t124*_t809 + _t125*_t829 + _t126*_t809 + _t127*_t834 + _t128*_t834 + _t129*_t838 + _t130*_t838 + _t131*_t810 + _t131*_t811 + _t132*_t840 + _t133*_t810 + _t133*_t811 + _t134*_t840 + _t135*_t825 + _t136*_t825 + _t137*_t829 + _t138*_t809 + _t139*_t829 + _t140*_t834 + _t141*_t834 + _t142*_t838 + _t143*_t838 + _t144*_t810 + _t144*_t811 + _t145*_t840 + _t146*_t840 + _t147*_t825 + _t148*_t829 + _t149*_t834 + _t150*_t838 + _t151*_t840 + _t17*_t743 + 3.2455124364590749e-8*_t18*_t751 - 2.5039215404198981e-7*_t18*_t761 - 1.8779411553149236e-7*_t18*_t770 + _t18*(1.9233661060143349e-8*_hc2[4]*_t1*_t749 - 7.6934644240573396e-7*_t776 - 5.7700983180430046e-7*_t778 - 9.6168305300716745e-8*_t779 - 1.1540196636086009e-6*_t784) + _t18*(-1.8585729105054661e-8*_t760 - 7.4342916420218646e-8*_t761 + 2.6020020747076525e-7*_t768 - 5.5757187315163984e-8*_t770 + 4.3366701245127543e-8*_t780 + 1.5612012448245915e-6*_t788 + 5.204004149415305e-7*_t789 + 3.9030031120614789e-7*_t796) + _t18*(2.2619793698004378e-7*_t751 - 2.5334168941764903e-5*_t776 + 0.00011400376023794206*_t777 - 1.9000626706323677e-5*_t778 - 3.1667711177206129e-6*_t779 + 4.7501566765809194e-6*_t781 - 3.8001253412647355e-5*_t784 + 7.600250682529471e-5*_t790 + 5.7001880118971032e-5*_t798 + 0.00034201128071382618*_t804) + _t18*(0.00028188567227900856*_hc2[0]*_hc2[2]*_t1*_t213*_t749 + 9.396189075966952e-5*_hc2[1]*_hc2[3]*_t1*_t11*_t749 + 7.8301575633057934e-6*_hc2[4]*_t1*_t12*_t749 + 7.047141806975214e-5*_t1*_t11*_t749*_t769 + 4.698094537983476e-5*_t1*_t749*_t767 - 1.3050262605509655e-6*_t760 - 5.2201050422038622e-6*_t761 - 3.9150787816528966e-6*_t770 - 8.6131733196363725e-6*_t782 - 0.00017226346639272745*_t791 - 0.00051679039917818236*_t795 - 0.00012919759979454559*_t799 - 0.0010335807983563647*_t805) + _t18*(-5.6229978021162963e-8*_t751 + 1.21456752525712e-5*_t776 - 0.0001336024277782832*_t777 + 9.1092564394283999e-6*_t778 + 1.5182094065714e-6*_t779 - 5.5667678240951334e-6*_t781 + 4.8245321142157822e-6*_t783 + 1.82185128788568e-5*_t784 - 8.9068285185522135e-5*_t790 + 0.00011578877074117877*_t792 + 0.00057894385370589385*_t797 - 6.68012138891416e-5*_t798 + 8.684157805588408e-5*_t800 - 0.0004008072833348496*_t804 + 0.00086841578055884077*_t806) - 6.2598038510497453e-8*_t19*_t751 + 0.0012285037133573136*_t198*_t204 + _t199*_t801 - _t199*_t807 - _t199*_t808 + _t20*_t743 + _t200*_t801 - _t200*_t807 - _t200*_t808 + 2.2138878726825063e-5*_t204*_t253 + 3.0367557510246198e-5*_t204*_t267 + 2.0909327073522365e-5*_t204*_t273 + 1.5537369566260771e-5*_t204*_t281 + 2.0210049106498917e-5*_t204*_t288 + 3.8435553345182401e-8*_t21*_t751 - 5.230778699819788e-8*_t21*_t760 - 2.0923114799279152e-7*_t21*_t761 - 1.5692336099459364e-7*_t21*_t770 + _t21*(-1.007157707064085e-7*_t751 + 4.0286308282563402e-6*_t776 + 3.0214731211922551e-6*_t778 + 5.0357885353204253e-7*_t779 + 6.0429462423845102e-6*_t784) + _t21*(-1.7394637760020129e-7*_t760 - 6.9578551040080515e-7*_t761 + 2.435249286402818e-6*_t768 - 5.2183913280060386e-7*_t770 + 4.0587488106713633e-7*_t780 + 1.4611495718416908e-5*_t788 + 4.8704985728056359e-6*_t789 + 3.6528739296042269e-6*_t796) + _t21*(7.6730895530549727e-9*_t751 - 8.5938602994215692e-7*_t776 + 3.8672371347397061e-6*_t777 - 6.4453952245661769e-7*_t778 - 1.0742325374276962e-7*_t779 + 1.6113488061415442e-7*_t781 - 1.2890790449132354e-6*_t784 + 2.5781580898264707e-6*_t790 + 1.933618567369853e-6*_t798 + 1.1601711404219118e-5*_t804) + _t21*(0.00033376833381884826*_hc2[0]*_hc2[2]*_t1*_t213*_t749 + 0.00011125611127294942*_hc2[1]*_hc2[3]*_t1*_t11*_t749 + 9.2713426060791182e-6*_hc2[4]*_t1*_t12*_t749 + 8.3442083454712064e-5*_t1*_t11*_t749*_t769 + 5.5628055636474709e-5*_t1*_t749*_t767 - 1.545223767679853e-6*_t760 - 6.1808950707194122e-6*_t761 - 4.6356713030395591e-6*_t770 - 1.019847686668703e-5*_t782 - 0.0002039695373337406*_t791 - 0.00061190861200122179*_t795 - 0.00015297715300030545*_t799 - 0.0012238172240024436*_t805) + _t21*(-4.9185831630140364e-7*_t751 + 0.00010624139632110319*_t776 - 0.0011686553595321351*_t777 + 7.9681047240827391e-5*_t778 + 1.3280174540137899e-5*_t779 - 4.8693973313838962e-5*_t781 + 4.2201443538660433e-5*_t783 + 0.00015936209448165478*_t784 - 0.00077910357302142339*_t790 + 0.0010128346449278504*_t792 + 0.0050641732246392518*_t797 - 0.00058432767976606754*_t798 + 0.0007596259836958878*_t800 - 0.0035059660785964052*_t804 + 0.0075962598369588778*_t806) - _t212*_t802 - _t212*_t813 - _t212*_t821 - _t212*_t824 - _t212*_t828 - _t212*_t832 - _t214*_t802 - _t214*_t813 - _t214*_t821 - _t214*_t824 - _t214*_t828 - _t214*_t832 + _t22*_t819 + _t23*_t743 + _t24*_t793 + _t24*_t794 + _t24*_t803 + _t25*_t743 + 5.2721454010844095e-8*_t26*_t751 - 1.0112211811036502e-7*_t26*_t760 - 4.0448847244146008e-7*_t26*_t761 - 3.0336635433109506e-7*_t26*_t770 + _t26*(6.767986519497247e-8*_hc2[4]*_t1*_t749 - 2.7071946077988987e-6*_t776 - 2.030395955849174e-6*_t778 - 3.3839932597486233e-7*_t779 - 4.0607919116983481e-6*_t784) + _t26*(-5.6801051265610149e-8*_t760 - 2.272042050624406e-7*_t761 + 7.952147177185421e-7*_t768 - 1.7040315379683045e-7*_t770 + 1.3253578628642368e-7*_t780 + 4.7712883063112525e-6*_t788 + 1.5904294354370842e-6*_t789 + 1.1928220765778131e-6*_t796) + _t26*(3.835649329873909e-6*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 2.8767369974054318e-6*_hc2[0]*_t1*_t749*_t769 + 5.7534739948108635e-6*_hc2[2]*_t1*_t213*_t749 + 4.7945616623423862e-7*_hc2[4]*_t1*_t11*_t749 - 3.4246869016731331e-8*_t751 - 1.7260421984432591e-5*_t777 - 7.1918424935135795e-7*_t781 - 1.1506947989621727e-5*_t790 - 8.6302109922162954e-6*_t798 - 5.1781265953297772e-5*_t804) + _t26*(1.0040910780783258e-7*_t760 + 4.0163643123133031e-7*_t761 - 3.6147278810819728e-6*_t768 + 3.0122732342349773e-7*_t770 - 6.0245464684699547e-7*_t780 + 6.6270011153169501e-7*_t782 - 2.1688367286491837e-5*_t788 - 7.2294557621639456e-6*_t789 + 1.32540022306339e-5*_t791 + 3.97620066919017e-5*_t795 - 5.4220918216229592e-6*_t796 + 9.940501672975425e-6*_t799 + 7.95240133838034e-5*_t805) + _t26*(-9.7219291572592392e-8*_t751 + 2.0999366979679956e-5*_t776 - 0.00023099303677647951*_t777 + 1.5749525234759967e-5*_t778 + 2.6249208724599945e-6*_t779 - 9.6247098656866465e-6*_t781 + 8.3414152169284269e-6*_t783 + 3.1499050469519934e-5*_t784 - 0.00015399535785098634*_t790 + 0.00020019396520628225*_t792 + 0.0010009698260314112*_t797 - 0.00011549651838823976*_t798 + 0.00015014547390471168*_t800 - 0.00069297911032943854*_t804 + 0.0015014547390471168*_t806) + _t262*_t815 + _t268*_t816 + _t268*_t817 + _t27*_t831 + _t270*_t827 + _t272*_t830 + _t274*_t833 + _t275*_t815 + _t277*_t835 + _t278*_t839 + _t279*_t816 + _t279*_t817 + _t28*_t819 + _t280*_t827 + _t282*_t830 + _t283*_t815 + _t284*_t833 + _t285*_t835 + _t286*_t816 + _t286*_t817 + _t287*_t839 + _t289*_t827 + _t29*_t793 + _t29*_t794 + _t29*_t803 + _t290*_t830 + _t291*_t833 + _t292*_t815 + _t293*_t835 + _t294*_t839 + _t295*_t816 + _t295*_t817 + _t296*_t827 + _t297*_t830 + _t298*_t815 + _t299*_t833 + 3.6300915058198551e-8*_t30*_t751 - 6.4543636336339682e-8*_t30*_t760 - 2.5817454534535873e-7*_t30*_t761 - 1.9363090900901905e-7*_t30*_t770 + _t30*(-4.5380477106751764e-9*_t751 + 1.8152190842700706e-7*_t776 + 1.3614143132025529e-7*_t778 + 2.2690238553375882e-8*_t779 + 2.7228286264051058e-7*_t784) + _t30*(3.6919060613189536e-8*_hc2[0]*_hc2[4]*_t1*_t749 + 1.4767624245275814e-7*_hc2[1]*_hc2[3]*_t1*_t749 + 1.1075718183956861e-7*_t1*_t749*_t769 - 5.168668485846535e-7*_t768 - 8.6144474764108917e-8*_t780 - 3.101201091507921e-6*_t788 - 1.033733697169307e-6*_t789 - 7.7530027287698026e-7*_t796) + _t30*(2.2292434563652361e-6*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 1.6719325922739271e-6*_hc2[0]*_t1*_t749*_t769 + 3.3438651845478542e-6*_hc2[2]*_t1*_t213*_t749 + 2.7865543204565451e-7*_hc2[4]*_t1*_t11*_t749 - 1.9903959431832465e-8*_t751 - 1.0031595553643563e-5*_t777 - 4.1798314806848177e-7*_t781 - 6.6877303690957084e-6*_t790 - 5.0157977768217813e-6*_t798 - 3.0094786660930687e-5*_t804) + _t30*(2.6975507187436914e-7*_t760 + 1.0790202874974766e-6*_t761 - 9.711182587477289e-6*_t768 + 8.0926521562310743e-7*_t770 - 1.6185304312462149e-6*_t780 + 1.7803834743708363e-6*_t782 - 5.8267095524863734e-5*_t788 - 1.9422365174954578e-5*_t789 + 3.5607669487416725e-5*_t791 + 0.00010682300846225018*_t795 - 1.4566773881215934e-5*_t796 + 2.6705752115562544e-5*_t799 + 0.00021364601692450035*_t805) + _t30*(-6.0228809821194143e-8*_t751 + 1.3009422921377935e-5*_t776 - 0.00014310365213515729*_t777 + 9.7570671910334511e-6*_t778 + 1.6261778651722419e-6*_t779 - 5.9626521722982202e-6*_t781 + 5.1676318826584575e-6*_t783 + 1.9514134382066902e-5*_t784 - 9.5402434756771524e-5*_t790 + 0.00012402316518380298*_t792 + 0.00062011582591901488*_t797 - 7.1551826067578643e-5*_t798 + 9.3017373887852235e-5*_t800 - 0.00042931095640547186*_t804 + 0.00093017373887852232*_t806) + _t300*_t835 + _t301*_t816 + _t301*_t817 + _t302*_t839 + _t303*_t827 + _t304*_t830 + _t305*_t833 + _t306*_t835 + _t307*_t839 + _t31*_t837 + _t316*_t747 + _t32*_t743 + _t33*_t819 + _t34*_t793 + _t34*_t794 + _t34*_t803 + _t35*_t743 + _t36*_t831 + 2.697459994142495e-8*_t37*_t751 - 6.9895080690083387e-8*_t37*_t760 - 2.7958032276033355e-7*_t37*_t761 - 2.0968524207025016e-7*_t37*_t770 + _t37*(1.6434724485069602e-8*_hc2[4]*_t1*_t749 - 6.573889794027841e-7*_t776 - 4.9304173455208807e-7*_t778 - 8.2173622425348012e-8*_t779 - 9.8608346910417614e-7*_t784) + _t37*(-3.7652726780462037e-8*_t760 - 1.5061090712184815e-7*_t761 + 5.2713817492646852e-7*_t768 - 1.1295818034138611e-7*_t770 + 8.7856362487744756e-8*_t780 + 3.1628290495588111e-6*_t788 + 1.054276349852937e-6*_t789 + 7.9070726238970277e-7*_t796) + _t37*(6.1622991192885104e-6*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 4.6217243394663827e-6*_hc2[0]*_t1*_t749*_t769 + 9.2434486789327655e-6*_hc2[2]*_t1*_t213*_t749 + 7.702873899110638e-7*_hc2[4]*_t1*_t11*_t749 - 5.502052785079027e-8*_t751 - 2.7730346036798296e-5*_t777 - 1.1554310848665957e-6*_t781 - 1.8486897357865531e-5*_t790 - 1.3865173018399148e-5*_t798 - 8.3191038110394889e-5*_t804) + _t37*(1.0113528403052461e-7*_t760 + 4.0454113612209845e-7*_t761 - 3.6408702250988859e-6*_t768 + 3.0340585209157383e-7*_t770 - 6.0681170418314767e-7*_t780 + 6.6749287460146241e-7*_t782 - 2.1845221350593315e-5*_t788 - 7.2817404501977719e-6*_t789 + 1.3349857492029248e-5*_t791 + 4.0049572476087744e-5*_t795 - 5.4613053376483289e-6*_t796 + 1.0012393119021936e-5*_t799 + 8.009914495217549e-5*_t805) + _t37*(3.461352493892164e-5*_hc2[0]*_t1*_t749*_t767 + 2.3075683292614427e-5*_hc2[1]*_hc2[3]*_t1*_t12*_t749 + 0.00010384057481676492*_hc2[2]*_t1*_t11*_t213*_t749 + 1.4422302057884017e-6*_hc2[4]*_t1*_t13*_t749 + 1.4567981876650522e-8*_hc2[4]*_t1*_t749 + 1.730676246946082e-5*_t1*_t12*_t749*_t769 - 3.1466840853565127e-6*_t776 - 2.3600130640173845e-6*_t778 - 3.9333551066956409e-7*_t779 - 1.2499328450166148e-6*_t783 - 4.720026128034769e-6*_t784 - 2.9998388280398754e-5*_t792 - 0.00014999194140199377*_t797 - 2.2498791210299065e-5*_t800 - 0.00022498791210299065*_t806) + _t38*_t842 + _t39*_t793 + _t39*_t794 + _t39*_t803 + _t4*_t743 + _t40*_t819 + 0.00020475061889288559*_t408*_t85 + 9.3470758170021355e-6*_t408*_t86 + _t41*_t837 + 0.019656059413717017*_t410*_t92 - 0.00718980329151343*_t410*_t94 - 7.489378428659823e-5*_t412*_t85 - 1.8028235091023266e-5*_t412*_t86 - _t413*_t451 - _t413*_t453 - _t413*_t471 - _t413*_t485 - _t413*_t488 - _t413*_t495 + 0.000897319278432205*_t414*_t92 - 0.0017307105687382336*_t414*_t94 + 0.002691957835296615*_t415*_t92 - 0.0051921317062147007*_t415*_t94 + _t42*_t831 + 3.5086890809893954e-8*_t43*_t751 - 6.3781167358855415e-8*_t43*_t760 - 2.5512466943542166e-7*_t43*_t761 - 1.9134350207656625e-7*_t43*_t770 + _t43*(-1.169816557954387e-8*_t751 + 4.6792662318175478e-7*_t776 + 3.5094496738631609e-7*_t778 + 5.8490827897719348e-8*_t779 + 7.0188993477263217e-7*_t784) + _t43*(-4.3578330364565607e-10*_t760 - 1.7431332145826243e-9*_t761 + 6.1009662510391849e-9*_t768 - 1.3073499109369682e-9*_t770 + 1.0168277085065308e-9*_t780 + 3.6605797506235109e-8*_t788 + 1.220193250207837e-8*_t789 + 9.1514493765587773e-9*_t796) + _t43*(8.3655153691712128e-7*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t749 + 6.2741365268784096e-7*_hc2[0]*_t1*_t749*_t769 + 1.2548273053756819e-6*_hc2[2]*_t1*_t213*_t749 + 1.0456894211464016e-7*_hc2[4]*_t1*_t11*_t749 - 7.4692101510457256e-9*_t751 - 3.7644819161270457e-6*_t777 - 1.5685341317196024e-7*_t781 - 2.5096546107513638e-6*_t790 - 1.8822409580635229e-6*_t798 - 1.1293445748381137e-5*_t804) + _t43*(9.0366313230578085e-8*_t760 + 3.6146525292231235e-7*_t761 - 3.253187276300811e-6*_t768 + 2.7109893969173426e-7*_t770 - 5.4219787938346852e-7*_t780 + 5.9641766732181537e-7*_t782 - 1.9519123657804867e-5*_t788 - 6.5063745526016222e-6*_t789 + 1.1928353346436307e-5*_t791 + 3.5785060039308922e-5*_t795 - 4.8797809144512166e-6*_t796 + 8.9462650098272304e-6*_t799 + 7.1570120078617843e-5*_t805) + _t43*(3.4735570399857428e-5*_hc2[0]*_t1*_t749*_t767 + 2.3157046933238286e-5*_hc2[1]*_hc2[3]*_t1*_t12*_t749 + 0.00010420671119957229*_hc2[2]*_t1*_t11*_t213*_t749 + 1.4473154333273929e-6*_hc2[4]*_t1*_t13*_t749 + 1.4619347811387807e-8*_hc2[4]*_t1*_t749 + 1.7367785199928714e-5*_t1*_t12*_t749*_t769 - 3.1577791272597662e-6*_t776 - 2.3683343454448247e-6*_t778 - 3.9472239090747078e-7*_t779 - 1.2543400422170738e-6*_t783 - 4.7366686908896493e-6*_t784 - 3.0104161013209772e-5*_t792 - 0.00015052080506604886*_t797 - 2.2578120759907328e-5*_t800 - 0.00022578120759907328*_t806) + _t44*_t843 + _t45*_t819 + _t46*_t793 + _t46*_t794 + _t46*_t803 + _t47*_t837 + _t48*_t831 + _t49*_t842 + _t490*_t812 + 0.000354222059629201*_t492*_t92 - 0.00048206856497539165*_t492*_t94 + _t499*_t814 + _t50*_t793 + _t50*_t794 + _t50*_t803 + _t500*_t818 + _t501*_t812 + _t502*_t820 + _t504*_t822 + 0.00048588092016393917*_t505*_t92 - 0.000931941440505124*_t505*_t94 + _t51*_t819 + _t510*_t823 + _t511*_t814 + _t512*_t826 + _t513*_t818 + _t514*_t820 + _t519*_t822 + _t52*_t831 + _t520*_t823 + _t522*_t812 + _t524*_t826 + 0.00033454923317635784*_t526*_t92 - 0.0005948341524757065*_t526*_t94 + _t529*_t814 + _t53*_t837 + _t531*_t818 + _t532*_t812 + _t533*_t820 + _t534*_t822 + 0.00024859791306017234*_t537*_t92 - 0.00064415306363980849*_t537*_t94 + _t538*_t823 + _t539*_t814 + _t54*_t843 + _t540*_t826 + _t541*_t818 + _t543*_t820 + _t544*_t822 + _t545*_t823 + _t547*_t812 + _t548*_t826 + 0.00032336078570398267*_t549*_t92 - 0.0005878072383792115*_t549*_t94 + _t55*_t842 + _t550*_t814 + _t551*_t818 + _t552*_t820 + _t553*_t822 + _t554*_t823 + _t555*_t826 + _t56*_t819 + _t566*_t745 + _t57*_t837 + _t58*_t843 - _t581*_t746 + _t59*_t831 + _t60*_t842 + _t61*_t831 + _t62*_t837 + _t63*_t843 + _t64*_t842 + _t65*_t837 + _t66*_t843 + _t67*_t842 + _t68*_t842 + _t69*_t843 + _t70*_t843 + _t73*_t744 + 0.20748619661467273*_t743 - 0.011765768981988274*_t744 - 0.047063075927953097*_t745 + 0.70655343068797577*_t746 - 0.035297306945964823*_t747 - 0.77091588324628016*_t748 - 2.922292041289284e-6*_t751 + 10.504141897156817*_t752 - 0.57818691243471013*_t753 - 0.09636448540578502*_t754 + 0.11775890511466263*_t755 + 0.4376725790482007*_t756 - 0.17131022505250731*_t757 - 0.47225184058624103*_t758 - 1.1563738248694203*_t759 - 1.3419664117194345e-5*_t760 - 5.3678656468777381e-5*_t761 + 4.2393205841278546*_t762 + 1.4131068613759515*_t763 + 7.0027612647712112*_t764 - 3.4262045010501462*_t765 - 11.334044174069785*_t766 - 4.5445021437185315e-7*_t768 - 4.0258992351583036e-5*_t770 + 1.0598301460319637*_t771 - 56.670220870348924*_t772 + 5.2520709485784084*_t773 - 2.5696533757876097*_t774 - 8.5005331305523386*_t775 + 3.219132025623347e-6*_t776 - 3.4478262627511233e-5*_t777 + 2.4143490192175103e-6*_t778 + 4.0239150320291837e-7*_t779 - 7.5741702395308859e-8*_t780 - 1.4365942761463013e-6*_t781 + 2.4326413844346641e-6*_t782 + 1.9852603461489375e-6*_t783 + 4.8286980384350206e-6*_t784 + 31.51242569147045*_t785 - 20.557227006300877*_t786 - 85.005331305523386*_t787 - 2.7267012862311189e-6*_t788 - 9.0890042874370631e-7*_t789 - 2.2985508418340822e-5*_t790 + 4.865282768869328e-5*_t791 + 4.7646248307574501e-5*_t792 + 0.00014595848306607984*_t795 - 6.8167532155777973e-7*_t796 + 0.0002382312415378725*_t797 - 1.7239131313755616e-5*_t798 + 3.648962076651996e-5*_t799 + 3.5734686230680875e-5*_t800 - 0.0001034347878825337*_t804 + 0.00029191696613215968*_t805 + 0.00035734686230680875*_t806;
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