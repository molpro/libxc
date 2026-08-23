/*
  Generated from python/mgga_exc/mgga_x_mbeef.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_mbeef
*/

#ifndef _MGGA_X_MBEEF_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_MBEEF_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_MBEEF_HELPER_BODIES
#include "mgga_x_mbeef.c"
#undef _MGGA_X_MBEEF_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_MBEEF_HELPER_BODIES
#include "mgga_x_mbeef.c"
#undef _MGGA_X_MBEEF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_MBEEF_HELPER_BODIES
#include "mgga_x_mbeef.c"
#undef _MGGA_X_MBEEF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_MBEEF_HELPER_BODIES
#include "mgga_x_mbeef.c"
#undef _MGGA_X_MBEEF_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_MBEEF_HELPER_BODIES
#include "mgga_x_mbeef.c"
#undef _MGGA_X_MBEEF_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_mbeef.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_MBEEF_HELPER_BODIES)

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
  const double _t6 = _t5 + 0.1e1;
  const double _t7 = _t5*_t6 + 0.1e1;
  const double _t8 = (0.1e1 / _t7);
  const double _t9 = _t4*_t8;
#if _KMAX >= 1
  const double _t10 = (_t3 * _t3);
  const double _t11 = _t2*_t8;
  const double _t12 = 0.3e1*_t11;
  const double _t13 = (_t1 * _t1);
  const double _t14 = xc_powi(a, 5);
  const double _t15 = 0.3e1*_t14;
  const double _t16 = (a * a);
  const double _t17 = -0.3e1*_t5 - 0.3e1;
  const double _t18 = _t16*_t17;
  const double _t19 = _t15 - _t18;
  const double _t20 = (0.1e1 / (_t7 * _t7));
  const double _t21 = _t20*_t4;
  const double _t22 = _t2*_t21;
#endif
#if _KMAX >= 2
  const double _t23 = 0.2e1*a;
  const double _t24 = _t23 - 0.2e1;
  const double _t25 = 0.6e1*a;
  const double _t26 = _t10*_t8;
  const double _t27 = (a * a * a * a);
  const double _t28 = _t25*_t6 + 0.24e2*_t27;
  const double _t29 = 0.18e2*_t14 - 0.6e1*_t18;
  const double _t30 = _t10*_t20;
  const double _t31 = _t2*_t30;
  const double _t32 = _t13*_t21;
  const double _t33 = 0.6e1*_t14;
  const double _t34 = _t16*(-0.6e1*_t5 - 0.6e1) - _t33;
  const double _t35 = _t34*_t4;
  const double _t36 = -_t19;
  const double _t37 = (0.1e1 / (_t7 * _t7 * _t7));
  const double _t38 = _t2*_t37;
  const double _t39 = _t36*_t38;
#endif
#if _KMAX >= 3
  const double _t40 = _t13*_t8;
  const double _t41 = 0.54e2*a;
  const double _t42 = 0.120e3*_t5 + 0.6e1;
  const double _t43 = 0.216e3*_t27 + _t41*_t6;
  const double _t44 = _t16*_t6;
  const double _t45 = -_t15 - 0.3e1*_t44;
  const double _t46 = _t2*_t20;
  const double _t47 = _t45*_t46;
  const double _t48 = _t13*_t30;
  const double _t49 = _t23 + 0.2e1;
  const double _t50 = _t21*_t49;
  const double _t51 = 0.9e1*_t36;
  const double _t52 = _t6*a;
  const double _t53 = -0.48e2*_t27 - 0.12e2*_t52;
  const double _t54 = _t39*_t4;
  const double _t55 = -_t28;
  const double _t56 = _t35*_t38;
  const double _t57 = _t10*_t39;
  const double _t58 = _t35*_t37;
  const double _t59 = _t13*_t58;
  const double _t60 = -0.9e1*_t14 + _t16*(-0.9e1*_t5 - 0.9e1);
  const double _t61 = (0.1e1 / (_t7 * _t7 * _t7 * _t7));
  const double _t62 = _t2*_t35*_t36*_t61;
#endif
#if _KMAX >= 4
  const double _t63 = 0.1440e4*_t5 + 0.72e2;
  const double _t64 = 0.18e2*_t55;
  const double _t65 = _t24*_t45;
  const double _t66 = 0.108e3*_t13;
  const double _t67 = _t36*_t49;
  const double _t68 = _t4*_t53;
  const double _t69 = 0.3e1*_t55;
  const double _t70 = 0.24e2*_t55;
  const double _t71 = _t10*_t34;
  const double _t72 = _t36*_t37;
  const double _t73 = 0.12e2*_t13;
  const double _t74 = _t2*_t36*_t60;
  const double _t75 = _t61*_t74;
  const double _t76 = _t35*_t60*_t61;
#endif

  const double f = -_t2*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t10*_t12 - 0.3e1*_t13*_t9 + _t19*_t22;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t12*_t24 + 0.18e2*_t13*_t26 + _t22*_t28 - _t29*_t31 + _t29*_t32 - _t35*_t39 + _t9*(-_t25 - 0.6e1);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.6e1*_t11 + _t22*_t42 + 0.27e2*_t24*_t40 + 0.9e1*_t24*_t47 + _t26*(_t41 + 0.54e2) - _t31*_t43 + _t32*_t43 + 0.9e1*_t34*_t57 + _t48*(-0.162e3*_t14 + 0.54e2*_t16*_t17) - _t50*_t51 - _t51*_t59 - _t53*_t54 - 0.2e1*_t55*_t56 - _t60*_t62 - 0.6e1*_t9;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.360e3*_t16*_t22 - _t2*_t69*_t76 + _t20*_t65*_t66 + _t21*(0.72e2*_t14 - 0.24e2*_t18) + _t24*_t46*_t64 + 0.54e2*_t24*_t49*_t8 + 0.72e2*_t26 + 0.108e3*_t30*_t67 - _t31*_t63 + _t32*_t63 - _t35*_t74*(-0.12e2*_t14 + _t16*(-0.12e2*_t5 - 0.12e2))/xc_powi(_t7, 5) - _t36*_t73*_t76 + 0.18e2*_t38*_t65*(-_t33 - 0.6e1*_t44) - _t38*_t68*_t69 + _t38*_t70*_t71 + 0.72e2*_t40 + 0.3e1*_t42*_t56 + 0.24e2*_t47 + _t48*(-0.2592e4*_t27 - 0.648e3*_t52) - _t50*_t64 + 0.12e2*_t53*_t57 - _t54*(-0.240e3*_t5 - 0.12e2) - 0.18e2*_t58*_t67 - _t59*_t70 - _t62*(-0.72e2*_t27 - 0.18e2*_t52) + _t66*_t71*_t72 - _t68*_t72*_t73 - 0.2e1*_t68*_t75 + 0.12e2*_t71*_t75;
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
  const double _t12 = 0.360e3*(_t5 * _t5 * _t5 * _t5);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(mbeef_xj0_k, _KMAX)(p, my_piecewise3(_t1, 10000.0, a), _hc0);

  const double f = my_piecewise3(_t2, -_t4 + 0.1e1 - 0.3e1/(_t3 * _t3), _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, 0.6e1*_t4*_t5 + 0.3e1*_t5*_t6, _hc0[1]*_t7);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, -0.18e2*_t6*_t9 - 0.12e2*_t8*_t9, _hc0[2]*(_t7 * _t7));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, 0.60e2*_t10*_t11 + 0.72e2*_t11*_t8, _hc0[3]*(_t7 * _t7 * _t7));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, -_t10*_t12 - _t12/xc_powi(_t3, 7), _hc0[4]*(_t7 * _t7 * _t7 * _t7));
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
  const double _t220 = 0.00022637680208333332*_hc1[0];
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
  const double _t334 = (0.15e2 / 0.8e1)*_t309 - 0.105e3 / 0.2e1*_t314 - 0.315e3 / 0.2e1*_t315 - 0.105e3 / 0.4e1*_t318 + (0.315e3 / 0.8e1)*_t320 + (0.945e3 / 0.2e1)*_t324 + (0.945e3 / 0.2e1)*_t327;
  const double _t335 = (0.315e3 / 0.8e1)*_t308;
  const double _t336 = (0.105e3 / 0.8e1)*_t310 + _t311*_t335 - 0.945e3 / 0.2e1*_t317 - 0.315e3 / 0.4e1*_t319 + (0.693e3 / 0.8e1)*_t321 - 0.2835e4 / 0.4e1*_t323 + (0.10395e5 / 0.8e1)*_t325 + (0.3465e4 / 0.2e1)*_t328;
  const double _t337 = -0.35e2 / 0.16e2*_t309 + (0.945e3 / 0.8e1)*_t314 + (0.2835e4 / 0.8e1)*_t315 + (0.945e3 / 0.16e2)*_t318 - 0.3465e4 / 0.16e2*_t320 + (0.3003e4 / 0.16e2)*_t322 - 0.10395e5 / 0.4e1*_t324 + (0.27027e5 / 0.8e1)*_t326 - 0.10395e5 / 0.4e1*_t327 + (0.45045e5 / 0.8e1)*_t329;
  const double _t338 = _hc0[2]*_t152;
  const double _t339 = _hc1[3]*_t338;
  const double _t340 = _hc1[0]*_t339;
  const double _t341 = _t153*_t85;
  const double _t342 = _t313*_t338;
  const double _t343 = _t153*_t86;
  const double _t344 = _hc1[0]*_t342;
  const double _t345 = _t339*_t5;
  const double _t346 = _t339*_t6;
  const double _t347 = _t339*_t7;
  const double _t348 = _t339*_t8;
  const double _t349 = _t339*_t9;
  const double _t350 = _t153*_t87;
  const double _t351 = _t153*_t88;
  const double _t352 = _t153*_t89;
  const double _t353 = _t153*_t90;
  const double _t354 = _t342*_t5;
  const double _t355 = _t342*_t6;
  const double _t356 = _t342*_t7;
  const double _t357 = 0.3e1*_t340;
  const double _t358 = 0.9e1*_t341;
  const double _t359 = -0.3e1 / 0.2e1*_t339 + 0.15e2*_t342 + 0.45e2*_t343 + (0.15e2 / 0.2e1)*_t345;
  const double _t360 = -0.15e2 / 0.2e1*_t340 - 0.45e2 / 0.2e1*_t341 + 0.105e3*_t344 + (0.35e2 / 0.2e1)*_t346 + (0.315e3 / 0.2e1)*_t350;
  const double _t361 = (0.15e2 / 0.8e1)*_t339 - 0.105e3 / 0.2e1*_t342 - 0.315e3 / 0.2e1*_t343 - 0.105e3 / 0.4e1*_t345 + (0.315e3 / 0.8e1)*_t347 + (0.945e3 / 0.2e1)*_t351 + (0.945e3 / 0.2e1)*_t354;
  const double _t362 = (0.105e3 / 0.8e1)*_t340 + (0.315e3 / 0.8e1)*_t341 - 0.945e3 / 0.2e1*_t344 - 0.315e3 / 0.4e1*_t346 + (0.693e3 / 0.8e1)*_t348 - 0.2835e4 / 0.4e1*_t350 + (0.10395e5 / 0.8e1)*_t352 + (0.3465e4 / 0.2e1)*_t355;
  const double _t363 = (0.35e2 / 0.16e2)*_hc1[3];
  const double _t364 = -_t338*_t363 + (0.945e3 / 0.8e1)*_t342 + (0.2835e4 / 0.8e1)*_t343 + (0.945e3 / 0.16e2)*_t345 - 0.3465e4 / 0.16e2*_t347 + (0.3003e4 / 0.16e2)*_t349 - 0.10395e5 / 0.4e1*_t351 + (0.27027e5 / 0.8e1)*_t353 - 0.10395e5 / 0.4e1*_t354 + (0.45045e5 / 0.8e1)*_t356;
  const double _t365 = _hc0[1]*_t197;
  const double _t366 = _hc1[3]*_t365;
  const double _t367 = _hc1[0]*_t366;
  const double _t368 = _t198*_t71;
  const double _t369 = _t313*_t365;
  const double _t370 = _t198*_t72;
  const double _t371 = _hc1[0]*_t369;
  const double _t372 = _t366*_t5;
  const double _t373 = _t366*_t6;
  const double _t374 = _t366*_t7;
  const double _t375 = _t366*_t8;
  const double _t376 = _t366*_t9;
  const double _t377 = _t198*_t74;
  const double _t378 = _t198*_t75;
  const double _t379 = _t198*_t76;
  const double _t380 = _t198*_t77;
  const double _t381 = _t369*_t5;
  const double _t382 = _t369*_t6;
  const double _t383 = _t369*_t7;
  const double _t389 = 0.3e1*_t367;
  const double _t390 = 0.9e1*_t368;
  const double _t391 = 0.2e1*_t175;
  const double _t392 = 0.6e1*_t176;
  const double _t393 = 0.6e1*_t177;
  const double _t394 = -0.3e1 / 0.2e1*_t366 + 0.15e2*_t369 + 0.45e2*_t370 + (0.15e2 / 0.2e1)*_t372;
  const double _t395 = 0.2e1*_t192;
  const double _t396 = -0.15e2 / 0.2e1*_t367 - 0.45e2 / 0.2e1*_t368 + 0.105e3*_t371 + (0.35e2 / 0.2e1)*_t373 + (0.315e3 / 0.2e1)*_t377;
  const double _t397 = 0.2e1*_t193;
  const double _t398 = 0.2e1*_t194;
  const double _t399 = (0.15e2 / 0.8e1)*_t366 - 0.105e3 / 0.2e1*_t369 - 0.315e3 / 0.2e1*_t370 - 0.105e3 / 0.4e1*_t372 + (0.315e3 / 0.8e1)*_t374 + (0.945e3 / 0.2e1)*_t378 + (0.945e3 / 0.2e1)*_t381;
  const double _t400 = 0.2e1*_t195;
  const double _t401 = 0.2e1*_t196;
  const double _t402 = (0.105e3 / 0.8e1)*_t367 + (0.315e3 / 0.8e1)*_t368 - 0.945e3 / 0.2e1*_t371 - 0.315e3 / 0.4e1*_t373 + (0.693e3 / 0.8e1)*_t375 - 0.2835e4 / 0.4e1*_t377 + (0.10395e5 / 0.8e1)*_t379 + (0.3465e4 / 0.2e1)*_t382;
  const double _t403 = -_t363*_t365 + (0.945e3 / 0.8e1)*_t369 + (0.2835e4 / 0.8e1)*_t370 + (0.945e3 / 0.16e2)*_t372 - 0.3465e4 / 0.16e2*_t374 + (0.3003e4 / 0.16e2)*_t376 - 0.10395e5 / 0.4e1*_t378 + (0.27027e5 / 0.8e1)*_t380 - 0.10395e5 / 0.4e1*_t381 + (0.45045e5 / 0.8e1)*_t383;
  const double _t404 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t406 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t407 = _hc1[3]*_t406;
  const double _t411 = _hc1[0]*_t407;
  const double _t412 = _t311*_t406;
  const double _t415 = _t313*_t406;
  const double _t419 = _hc1[0]*_t412;
  const double _t426 = _hc1[0]*_t415;
  const double _t427 = _t407*_t5;
  const double _t428 = _t407*_t6;
  const double _t429 = _t407*_t7;
  const double _t430 = _t407*_t8;
  const double _t431 = _t407*_t9;
  const double _t436 = _t412*_t5;
  const double _t437 = _t412*_t6;
  const double _t438 = _t412*_t7;
  const double _t439 = _t412*_t8;
  const double _t443 = _t415*_t5;
  const double _t444 = _t415*_t6;
  const double _t445 = _t415*_t7;
  const double _t448 = 0.00067913040625000001*_t85;
  const double _t450 = 0.00070361079374999999*_t86;
  const double _t451 = 0.3e1*_t411;
  const double _t452 = 0.9e1*_t412;
  const double _t468 = 4.5820787656250002e-5*_t102;
  const double _t478 = 0.3e1*_t198;
  const double _t480 = 0.9e1*_t199;
  const double _t482 = 5.4850160937500001e-6*_t107;
  const double _t483 = 0.9e1*_t200;
  const double _t485 = 1.0452815921874998e-10*_t109;
  const double _t489 = -0.3e1 / 0.2e1*_t407 + 0.15e2*_t415 + 0.45e2*_t419 + (0.15e2 / 0.2e1)*_t427;
  const double _t492 = 3.484604015625e-11*_t117;
  const double _t493 = 0.3e1*_t85;
  const double _t495 = 0.9e1*_t86;
  const double _t502 = -0.15e2 / 0.2e1*_t411 - 0.45e2 / 0.2e1*_t412 + 0.105e3*_t426 + (0.35e2 / 0.2e1)*_t428 + (0.315e3 / 0.2e1)*_t436;
  const double _t504 = 0.3e1*_t102;
  const double _t505 = 0.3e1*_t103;
  const double _t506 = 0.3e1*_t253;
  const double _t512 = 0.3e1*_t107;
  const double _t514 = 0.3e1*_t109;
  const double _t518 = 0.3e1*_t267;
  const double _t520 = 0.3e1*_t117;
  const double _t522 = (0.15e2 / 0.8e1)*_t407 - 0.105e3 / 0.2e1*_t415 - 0.315e3 / 0.2e1*_t419 - 0.105e3 / 0.4e1*_t427 + (0.315e3 / 0.8e1)*_t429 + (0.945e3 / 0.2e1)*_t437 + (0.945e3 / 0.2e1)*_t443;
  const double _t526 = 0.3e1*_t273;
  const double _t533 = (0.105e3 / 0.8e1)*_t411 + (0.315e3 / 0.8e1)*_t412 - 0.945e3 / 0.2e1*_t426 - 0.315e3 / 0.4e1*_t428 + (0.693e3 / 0.8e1)*_t430 - 0.2835e4 / 0.4e1*_t436 + (0.10395e5 / 0.8e1)*_t438 + (0.3465e4 / 0.2e1)*_t444;
  const double _t538 = 0.3e1*_t281;
  const double _t542 = 0.3e1*_t288;
  const double _t545 = -0.35e2 / 0.16e2*_t407 + (0.945e3 / 0.8e1)*_t415 + (0.2835e4 / 0.8e1)*_t419 + (0.945e3 / 0.16e2)*_t427 - 0.3465e4 / 0.16e2*_t429 + (0.3003e4 / 0.16e2)*_t431 - 0.10395e5 / 0.4e1*_t437 + (0.27027e5 / 0.8e1)*_t439 - 0.10395e5 / 0.4e1*_t443 + (0.45045e5 / 0.8e1)*_t445;
#endif
#if _KMAX >= 4
  const double _t552 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t553 = _hc1[4]*_t552;
  const double _t554 = _hc1[0]*_t553;
  const double _t555 = _hc1[1]*_hc1[3];
  const double _t556 = _t552*_t555;
  const double _t557 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t558 = _t552*_t557;
  const double _t559 = ((_hc1[2]) * (_hc1[2]));
  const double _t560 = _t552*_t559;
  const double _t561 = _hc1[0]*_t556;
  const double _t563 = _hc1[0]*_t558;
  const double _t564 = _hc1[0]*_t560;
  const double _t565 = _t5*_t553;
  const double _t566 = _t553*_t6;
  const double _t567 = _t553*_t7;
  const double _t568 = _t553*_t8;
  const double _t569 = _t553*_t9;
  const double _t570 = _hc1[2]*_t155;
  const double _t571 = _t552*_t570;
  const double _t572 = _hc1[0]*_t571;
  const double _t573 = _t5*_t556;
  const double _t574 = _t556*_t6;
  const double _t575 = _t556*_t7;
  const double _t576 = _t556*_t8;
  const double _t577 = _t5*_t558;
  const double _t578 = _t5*_t560;
  const double _t579 = _t558*_t6;
  const double _t580 = _t560*_t6;
  const double _t581 = _t560*_t7;
  const double _t582 = _t560*_t8;
  const double _t583 = _t5*_t571;
  const double _t584 = _t571*_t6;
  const double _t585 = _t571*_t7;
  const double _t586 = 0.3e1*_t554;
  const double _t587 = 0.12e2*_t556;
  const double _t588 = 0.9e1*_t560;
  const double _t589 = -0.3e1 / 0.2e1*_t553 + 0.60e2*_t561 + 0.45e2*_t564 + (0.15e2 / 0.2e1)*_t565 + 0.90e2*_t571;
  const double _t590 = -0.15e2 / 0.2e1*_t554 - 0.30e2*_t556 + 0.105e3*_t558 - 0.45e2 / 0.2e1*_t560 + (0.35e2 / 0.2e1)*_t566 + 0.630e3*_t572 + 0.210e3*_t573 + (0.315e3 / 0.2e1)*_t578;
  const double _t591 = (0.15e2 / 0.8e1)*_t553 - 0.210e3*_t561 + 0.945e3*_t563 - 0.315e3 / 0.2e1*_t564 - 0.105e3 / 0.4e1*_t565 + (0.315e3 / 0.8e1)*_t567 - 0.315e3*_t571 + 0.630e3*_t574 + (0.945e3 / 0.2e1)*_t580 + 0.2835e4*_t583;
  const double _t592 = (0.105e3 / 0.8e1)*_t554 + (0.105e3 / 0.2e1)*_t556 - 0.945e3 / 0.2e1*_t558 + (0.315e3 / 0.8e1)*_t560 - 0.315e3 / 0.4e1*_t566 + (0.693e3 / 0.8e1)*_t568 - 0.2835e4*_t572 - 0.945e3*_t573 + (0.3465e4 / 0.2e1)*_t575 + (0.10395e5 / 0.2e1)*_t577 - 0.2835e4 / 0.4e1*_t578 + (0.10395e5 / 0.8e1)*_t581 + 0.10395e5*_t584;
  const double _t593 = -0.35e2 / 0.16e2*_t553 + (0.945e3 / 0.2e1)*_t561 - 0.10395e5 / 0.2e1*_t563 + (0.2835e4 / 0.8e1)*_t564 + (0.945e3 / 0.16e2)*_t565 - 0.3465e4 / 0.16e2*_t567 + (0.3003e4 / 0.16e2)*_t569 + (0.2835e4 / 0.4e1)*_t571 - 0.3465e4*_t574 + (0.9009e4 / 0.2e1)*_t576 + (0.45045e5 / 0.2e1)*_t579 - 0.10395e5 / 0.4e1*_t580 + (0.27027e5 / 0.8e1)*_t582 - 0.31185e5 / 0.2e1*_t583 + (0.135135e6 / 0.4e1)*_t585;
  const double _t594 = _hc0[2]*_t308;
  const double _t595 = _hc1[4]*_t594;
  const double _t596 = _hc1[0]*_t595;
  const double _t597 = _t309*_t85;
  const double _t598 = _t557*_t594;
  const double _t599 = _t559*_t594;
  const double _t600 = _t309*_t86;
  const double _t601 = _hc1[0]*_t598;
  const double _t602 = _hc1[0]*_t599;
  const double _t603 = _t5*_t595;
  const double _t604 = _t595*_t6;
  const double _t605 = _t595*_t7;
  const double _t606 = _t595*_t8;
  const double _t607 = _t595*_t9;
  const double _t608 = _t570*_t594;
  const double _t609 = _hc1[0]*_t608;
  const double _t610 = _t309*_t87;
  const double _t611 = _t309*_t88;
  const double _t612 = _t309*_t89;
  const double _t613 = _t309*_t90;
  const double _t614 = _t5*_t598;
  const double _t615 = _t5*_t599;
  const double _t616 = _t598*_t6;
  const double _t617 = _t599*_t6;
  const double _t618 = _t599*_t7;
  const double _t619 = _t599*_t8;
  const double _t620 = _t5*_t608;
  const double _t621 = _t6*_t608;
  const double _t622 = _t608*_t7;
  const double _t623 = 0.3e1*_t596;
  const double _t624 = 0.12e2*_t597;
  const double _t625 = 0.9e1*_t599;
  const double _t626 = -0.3e1 / 0.2e1*_t595 + 0.60e2*_t600 + 0.45e2*_t602 + (0.15e2 / 0.2e1)*_t603 + 0.90e2*_t608;
  const double _t627 = -0.15e2 / 0.2e1*_t596 - 0.30e2*_t597 + 0.105e3*_t598 - 0.45e2 / 0.2e1*_t599 + (0.35e2 / 0.2e1)*_t604 + 0.630e3*_t609 + 0.210e3*_t610 + (0.315e3 / 0.2e1)*_t615;
  const double _t628 = _hc0[2]*_t335;
  const double _t629 = _hc1[4]*_t628*_t7 + (0.15e2 / 0.8e1)*_t595 - 0.210e3*_t600 + 0.945e3*_t601 - 0.315e3 / 0.2e1*_t602 - 0.105e3 / 0.4e1*_t603 - 0.315e3*_t608 + 0.630e3*_t611 + (0.945e3 / 0.2e1)*_t617 + 0.2835e4*_t620;
  const double _t630 = _t559*_t628 + (0.105e3 / 0.8e1)*_t596 + (0.105e3 / 0.2e1)*_t597 - 0.945e3 / 0.2e1*_t598 - 0.315e3 / 0.4e1*_t604 + (0.693e3 / 0.8e1)*_t606 - 0.2835e4*_t609 - 0.945e3*_t610 + (0.3465e4 / 0.2e1)*_t612 + (0.10395e5 / 0.2e1)*_t614 - 0.2835e4 / 0.4e1*_t615 + (0.10395e5 / 0.8e1)*_t618 + 0.10395e5*_t621;
  const double _t631 = (0.35e2 / 0.16e2)*_hc1[4];
  const double _t632 = -_t594*_t631 + (0.945e3 / 0.2e1)*_t600 - 0.10395e5 / 0.2e1*_t601 + (0.2835e4 / 0.8e1)*_t602 + (0.945e3 / 0.16e2)*_t603 - 0.3465e4 / 0.16e2*_t605 + (0.3003e4 / 0.16e2)*_t607 + (0.2835e4 / 0.4e1)*_t608 - 0.3465e4*_t611 + (0.9009e4 / 0.2e1)*_t613 + (0.45045e5 / 0.2e1)*_t616 - 0.10395e5 / 0.4e1*_t617 + (0.27027e5 / 0.8e1)*_t619 - 0.31185e5 / 0.2e1*_t620 + (0.135135e6 / 0.4e1)*_t622;
  const double _t633 = _t152*_t197;
  const double _t634 = _hc1[4]*_t633;
  const double _t635 = _hc1[0]*_t634;
  const double _t636 = _t555*_t633;
  const double _t637 = _t557*_t633;
  const double _t638 = _t559*_t633;
  const double _t639 = _hc1[0]*_t636;
  const double _t640 = _hc1[0]*_t637;
  const double _t641 = _hc1[0]*_t638;
  const double _t642 = _t5*_t634;
  const double _t643 = _t6*_t634;
  const double _t644 = _t634*_t7;
  const double _t645 = _t634*_t8;
  const double _t646 = _t634*_t9;
  const double _t647 = _t153*_t200;
  const double _t648 = _t154*_t200;
  const double _t649 = _t5*_t636;
  const double _t650 = _t6*_t636;
  const double _t651 = _t636*_t7;
  const double _t652 = _t636*_t8;
  const double _t653 = _t5*_t637;
  const double _t654 = _t5*_t638;
  const double _t655 = _t6*_t637;
  const double _t656 = _t6*_t638;
  const double _t657 = _t638*_t7;
  const double _t658 = _t638*_t8;
  const double _t659 = _t158*_t200;
  const double _t660 = _t159*_t200;
  const double _t661 = _t160*_t200;
  const double _t662 = 0.3e1*_t635;
  const double _t663 = 0.12e2*_t636;
  const double _t664 = 0.9e1*_t638;
  const double _t665 = 0.2e1*_t339;
  const double _t666 = 0.6e1*_t340;
  const double _t667 = 0.18e2*_t341;
  const double _t668 = 0.2e1*_t359;
  const double _t669 = -0.3e1 / 0.2e1*_t634 + 0.60e2*_t639 + 0.45e2*_t641 + (0.15e2 / 0.2e1)*_t642 + 0.90e2*_t647;
  const double _t670 = 0.2e1*_t360;
  const double _t671 = 0.2e1*_t361;
  const double _t672 = -0.15e2 / 0.2e1*_t635 - 0.30e2*_t636 + 0.105e3*_t637 - 0.45e2 / 0.2e1*_t638 + (0.35e2 / 0.2e1)*_t643 + 0.630e3*_t648 + 0.210e3*_t649 + (0.315e3 / 0.2e1)*_t654;
  const double _t673 = 0.2e1*_t362;
  const double _t674 = 0.2e1*_t364;
  const double _t675 = (0.15e2 / 0.8e1)*_t634 - 0.210e3*_t639 + 0.945e3*_t640 - 0.315e3 / 0.2e1*_t641 - 0.105e3 / 0.4e1*_t642 + (0.315e3 / 0.8e1)*_t644 - 0.315e3*_t647 + 0.630e3*_t650 + (0.945e3 / 0.2e1)*_t656 + 0.2835e4*_t659;
  const double _t676 = (0.105e3 / 0.8e1)*_t635 + (0.105e3 / 0.2e1)*_t636 - 0.945e3 / 0.2e1*_t637 + (0.315e3 / 0.8e1)*_t638 - 0.315e3 / 0.4e1*_t643 + (0.693e3 / 0.8e1)*_t645 - 0.2835e4*_t648 - 0.945e3*_t649 + (0.3465e4 / 0.2e1)*_t651 + (0.10395e5 / 0.2e1)*_t653 - 0.2835e4 / 0.4e1*_t654 + (0.10395e5 / 0.8e1)*_t657 + 0.10395e5*_t660;
  const double _t677 = -_t631*_t633 + (0.945e3 / 0.2e1)*_t639 - 0.10395e5 / 0.2e1*_t640 + (0.2835e4 / 0.8e1)*_t641 + (0.945e3 / 0.16e2)*_t642 - 0.3465e4 / 0.16e2*_t644 + (0.3003e4 / 0.16e2)*_t646 + (0.2835e4 / 0.4e1)*_t647 - 0.3465e4*_t650 + (0.9009e4 / 0.2e1)*_t652 + (0.45045e5 / 0.2e1)*_t655 - 0.10395e5 / 0.4e1*_t656 + (0.27027e5 / 0.8e1)*_t658 - 0.31185e5 / 0.2e1*_t659 + (0.135135e6 / 0.4e1)*_t661;
  const double _t678 = _hc0[1]*_t406;
  const double _t679 = _hc1[4]*_t678;
  const double _t680 = _hc1[0]*_t679;
  const double _t681 = _t407*_t71;
  const double _t682 = _t557*_t678;
  const double _t683 = _t559*_t678;
  const double _t684 = _t407*_t72;
  const double _t685 = _hc1[0]*_t682;
  const double _t686 = _hc1[0]*_t683;
  const double _t687 = _t5*_t679;
  const double _t688 = _t6*_t679;
  const double _t689 = _t679*_t7;
  const double _t690 = _t679*_t8;
  const double _t691 = _t679*_t9;
  const double _t692 = _t570*_t678;
  const double _t693 = _hc1[0]*_t692;
  const double _t694 = _t407*_t74;
  const double _t695 = _t407*_t75;
  const double _t696 = _t407*_t76;
  const double _t697 = _t407*_t77;
  const double _t698 = _t5*_t682;
  const double _t699 = _t5*_t683;
  const double _t700 = _t6*_t682;
  const double _t701 = _t6*_t683;
  const double _t702 = _t683*_t7;
  const double _t703 = _t683*_t8;
  const double _t704 = _t5*_t692;
  const double _t705 = _t6*_t692;
  const double _t706 = _t692*_t7;
  const double _t707 = 0.00067913040625000001*_t175;
  const double _t709 = 0.3e1*_t680;
  const double _t710 = 0.12e2*_t681;
  const double _t711 = 0.9e1*_t683;
  const double _t712 = 0.3e1*_t366;
  const double _t713 = 0.9e1*_t367;
  const double _t714 = 0.27e2*_t368;
  const double _t715 = 0.3e1*_t175;
  const double _t716 = 0.9e1*_t176;
  const double _t717 = 0.9e1*_t177;
  const double _t718 = -0.3e1 / 0.2e1*_t679 + 0.60e2*_t684 + 0.45e2*_t686 + (0.15e2 / 0.2e1)*_t687 + 0.90e2*_t692;
  const double _t719 = 0.3e1*_t192;
  const double _t720 = 0.3e1*_t394;
  const double _t721 = 0.3e1*_t193;
  const double _t722 = 0.3e1*_t396;
  const double _t723 = 0.3e1*_t194;
  const double _t724 = -0.15e2 / 0.2e1*_t680 - 0.30e2*_t681 + 0.105e3*_t682 - 0.45e2 / 0.2e1*_t683 + (0.35e2 / 0.2e1)*_t688 + 0.630e3*_t693 + 0.210e3*_t694 + (0.315e3 / 0.2e1)*_t699;
  const double _t725 = 0.3e1*_t195;
  const double _t726 = 0.3e1*_t399;
  const double _t727 = 0.3e1*_t196;
  const double _t728 = 0.3e1*_t402;
  const double _t729 = (0.15e2 / 0.8e1)*_t679 - 0.210e3*_t684 + 0.945e3*_t685 - 0.315e3 / 0.2e1*_t686 - 0.105e3 / 0.4e1*_t687 + (0.315e3 / 0.8e1)*_t689 - 0.315e3*_t692 + 0.630e3*_t695 + (0.945e3 / 0.2e1)*_t701 + 0.2835e4*_t704;
  const double _t730 = 0.3e1*_t403;
  const double _t731 = (0.105e3 / 0.8e1)*_t680 + (0.105e3 / 0.2e1)*_t681 - 0.945e3 / 0.2e1*_t682 + (0.315e3 / 0.8e1)*_t683 - 0.315e3 / 0.4e1*_t688 + (0.693e3 / 0.8e1)*_t690 - 0.2835e4*_t693 - 0.945e3*_t694 + (0.3465e4 / 0.2e1)*_t696 + (0.10395e5 / 0.2e1)*_t698 - 0.2835e4 / 0.4e1*_t699 + (0.10395e5 / 0.8e1)*_t702 + 0.10395e5*_t705;
  const double _t732 = -_t631*_t678 + (0.945e3 / 0.2e1)*_t684 - 0.10395e5 / 0.2e1*_t685 + (0.2835e4 / 0.8e1)*_t686 + (0.945e3 / 0.16e2)*_t687 - 0.3465e4 / 0.16e2*_t689 + (0.3003e4 / 0.16e2)*_t691 + (0.2835e4 / 0.4e1)*_t692 - 0.3465e4*_t695 + (0.9009e4 / 0.2e1)*_t697 + (0.45045e5 / 0.2e1)*_t700 - 0.10395e5 / 0.4e1*_t701 + (0.27027e5 / 0.8e1)*_t703 - 0.31185e5 / 0.2e1*_t704 + (0.135135e6 / 0.4e1)*_t706;
  const double _t733 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t734 = _hc1[4]*_t733;
  const double _t735 = _hc1[0]*_t734;
  const double _t736 = _t555*_t733;
  const double _t737 = _t557*_t733;
  const double _t738 = _t559*_t733;
  const double _t739 = _hc1[0]*_t736;
  const double _t740 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t741 = _t1*_t740;
  const double _t743 = _hc1[0]*_t737;
  const double _t744 = _hc1[0]*_t738;
  const double _t745 = _t5*_t734;
  const double _t746 = _t6*_t734;
  const double _t747 = _t7*_t734;
  const double _t748 = _t734*_t8;
  const double _t749 = _t734*_t9;
  const double _t750 = _t570*_t733;
  const double _t753 = _hc1[0]*_t750;
  const double _t754 = _t5*_t736;
  const double _t755 = _t6*_t736;
  const double _t756 = _t7*_t736;
  const double _t757 = _t736*_t8;
  const double _t762 = _t5*_t737;
  const double _t763 = _t5*_t738;
  const double _t764 = _t6*_t737;
  const double _t765 = _t6*_t738;
  const double _t766 = _t7*_t738;
  const double _t767 = _t738*_t8;
  const double _t777 = _t5*_t750;
  const double _t778 = _t6*_t750;
  const double _t779 = _t7*_t750;
  const double _t785 = 0.3e1*_t735;
  const double _t786 = 0.12e2*_t736;
  const double _t794 = 0.0013582608125*_t198;
  const double _t795 = 0.9e1*_t738;
  const double _t801 = 0.4e1*_t407;
  const double _t802 = 0.12e2*_t411;
  const double _t803 = 0.36e2*_t412;
  const double _t804 = 0.4e1*_t85;
  const double _t805 = 9.1641575312500004e-5*_t253;
  const double _t806 = 0.12e2*_t86;
  const double _t807 = 0.6e1*_t198;
  const double _t808 = 0.18e2*_t199;
  const double _t809 = 0.18e2*_t200;
  const double _t810 = 0.4e1*_t102;
  const double _t811 = -0.3e1 / 0.2e1*_t734 + 0.60e2*_t739 + 0.45e2*_t744 + (0.15e2 / 0.2e1)*_t745 + 0.90e2*_t750;
  const double _t812 = 0.4e1*_t103;
  const double _t813 = 5.7158142812499996e-5*_t267;
  const double _t814 = 0.4e1*_t107;
  const double _t815 = 0.4e1*_t109;
  const double _t816 = 1.09700321875e-5*_t273;
  const double _t817 = 0.4e1*_t489;
  const double _t818 = 0.4e1*_t117;
  const double _t819 = 0.6e1*_t253;
  const double _t820 = 2.0905631843749997e-10*_t281;
  const double _t821 = 0.4e1*_t502;
  const double _t822 = 0.6e1*_t267;
  const double _t823 = -0.15e2 / 0.2e1*_t735 - 0.30e2*_t736 + 0.105e3*_t737 - 0.45e2 / 0.2e1*_t738 + (0.35e2 / 0.2e1)*_t746 + 0.630e3*_t753 + 0.210e3*_t754 + (0.315e3 / 0.2e1)*_t763;
  const double _t824 = 6.9692080312500001e-11*_t288;
  const double _t825 = 0.6e1*_t273;
  const double _t826 = 0.4e1*_t522;
  const double _t827 = 0.6e1*_t281;
  const double _t828 = (0.15e2 / 0.8e1)*_t734 - 0.210e3*_t739 + 0.945e3*_t743 - 0.315e3 / 0.2e1*_t744 - 0.105e3 / 0.4e1*_t745 + (0.315e3 / 0.8e1)*_t747 - 0.315e3*_t750 + 0.630e3*_t755 + (0.945e3 / 0.2e1)*_t765 + 0.2835e4*_t777;
  const double _t829 = 0.4e1*_t533;
  const double _t830 = 0.6e1*_t288;
  const double _t831 = 0.4e1*_t545;
  const double _t832 = (0.105e3 / 0.8e1)*_t735 + (0.105e3 / 0.2e1)*_t736 - 0.945e3 / 0.2e1*_t737 + (0.315e3 / 0.8e1)*_t738 - 0.315e3 / 0.4e1*_t746 + (0.693e3 / 0.8e1)*_t748 - 0.2835e4*_t753 - 0.945e3*_t754 + (0.3465e4 / 0.2e1)*_t756 + (0.10395e5 / 0.2e1)*_t762 - 0.2835e4 / 0.4e1*_t763 + (0.10395e5 / 0.8e1)*_t766 + 0.10395e5*_t778;
  const double _t833 = -0.35e2 / 0.16e2*_t734 + (0.945e3 / 0.2e1)*_t739 - 0.10395e5 / 0.2e1*_t743 + (0.2835e4 / 0.8e1)*_t744 + (0.945e3 / 0.16e2)*_t745 - 0.3465e4 / 0.16e2*_t747 + (0.3003e4 / 0.16e2)*_t749 + (0.2835e4 / 0.4e1)*_t750 - 0.3465e4*_t755 + (0.9009e4 / 0.2e1)*_t757 + (0.45045e5 / 0.2e1)*_t764 - 0.10395e5 / 0.4e1*_t765 + (0.27027e5 / 0.8e1)*_t767 - 0.31185e5 / 0.2e1*_t777 + (0.135135e6 / 0.4e1)*_t779;
#endif
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(mbeef_xi_k, _KMAX)(p, (0.1e1 / 0.24e2)*_t3*x2, _hc2);
  const double _t4 = 0.100339208*_hc2[0];
  const double _t11 = ((_hc2[0]) * (_hc2[0]));
  const double _t12 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t13 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t14 = xc_powi((_hc2[0]), 5);
  const double _t15 = xc_powi((_hc2[0]), 6);
  const double _t16 = xc_powi((_hc2[0]), 7);
  const double _t17 = 0.021732173 - 0.065196519000000008*_t11;
  const double _t19 = _hc2[0]*_t18;
  const double _t20 = 0.0273266931*_hc2[0] - 0.045544488500000001*_t12;
  const double _t22 = 0.0030334714099999999*_hc2[0];
  const double _t23 = -0.060989465624999996*_t11 + 0.071154376562499996*_t13 + 0.0060989465624999998;
  const double _t24 = 0.0075051817999999999 - 0.0225155454*_t11;
  const double _t25 = -0.016577780100000002*_hc2[0] + 0.077362973799999998*_t12 - 0.069626676420000005*_t14;
  const double _t27 = 0.00119130546*_hc2[0];
  const double _t28 = -0.042101830799999997*_hc2[0] + 0.070169717999999992*_t12;
  const double _t29 = 0.0043987956150000002*_t11 - 0.0014662652050000001;
  const double _t31 = 0.00082213989600000005*_hc2[0];
  const double _t32 = -0.062830524225000003*_t11 + 0.188491572675*_t13 - 0.13822715329500002*_t15 + 0.0029919297250000001;
  const double _t33 = 0.012682621545000002*_hc2[0] - 0.021137702575*_t12;
  const double _t34 = 0.068591734124999998*_t11 - 0.080023689812500007*_t13 - 0.0068591734125000008;
  const double _t35 = -0.020577281965625003*_hc2[0] + 0.18519553769062502*_t12 - 0.40743018291937505*_t14 + 0.25221868466437503*_t16;
  const double _t36 = 0.0027435908550000002*_t11 - 0.00091453028500000004;
  const double _t38 = 5.1420467599999999e-5*_hc2[0];
  const double _t39 = -0.035342831625000001*_hc2[0] + 0.16493321424999999*_t12 - 0.148439892825*_t14;
  const double _t40 = -0.023695936049999998*_t11 + 0.027645258725*_t13 + 0.0023695936049999999;
  const double _t41 = 0.000175520515 - 0.00052656154500000003*_t11;
  const double _t42 = -0.0050896345800000003*_hc2[0] + 0.0084827242999999993*_t12;
  const double _t44 = 9.4035156300000008e-6*_hc2[0];
  const double _t45 = -0.016814463825000001*_hc2[0] + 0.078467497849999998*_t12 - 0.070620748065000002*_t14;
  const double _t46 = 1.1143513171874998e-6*_t11 - 3.3430539515624999e-6*_t13 + 2.4515728978124996e-6*_t15 - 5.3064348437499998e-8;
  const double _t47 = -0.001345109199*_hc2[0] + 0.0022418486649999998*_t12;
  const double _t48 = 2.9655439012500002e-7*_t11 - 3.4598012181250004e-7*_t13 - 2.9655439012500004e-8;
  const double _t49 = 1.0034703284999999e-8*_t11 - 3.3449010949999999e-9;
  const double _t50 = 6.0489773749999992e-7*_hc2[0] - 5.4440796374999991e-6*_t12 + 1.19769752025e-5*_t14 - 7.414317982499999e-6*_t16;
  const double _t51 = -1.739814864375e-7*_t11 + 5.2194445931250005e-7*_t13 - 3.8275927016250001e-7*_t15 + 8.2848326874999996e-9;
  const double _t52 = 3.0419763937499996e-7*_hc2[0] - 1.4195889837499999e-6*_t12 + 1.2776300853749999e-6*_t14;
  const double _t53 = -7.8601451625000001e-8*_t11 + 9.1701693562500003e-8*_t13 + 7.8601451625000007e-9;
  const double _t54 = 1.115073285e-9 - 3.345219855e-9*_t11;
  const double _t55 = 3.25290852e-8*_hc2[0] - 5.4215142000000005e-8*_t12;
  const double _t56 = -1.1067016559375001e-7*_hc2[0] + 9.9603149034375007e-7*_t12 - 2.1912692787562499e-6*_t14 + 1.35650002970625e-6*_t16;
  const double _t57 = -7.0631804812499994e-8*_hc2[0] + 3.2961508912499997e-7*_t12 - 2.9665358021249999e-7*_t14;
  const double _t58 = -1.0123651784999999e-8*_hc2[0] + 1.6872752975e-8*_t12;
  const double _t59 = -2.7325797581250001e-7*_t11 + 8.1977392743750008e-7*_t13 - 6.0116754678750005e-7*_t15 + 1.3012284562500001e-8;
  const double _t60 = -3.42083906625e-8*_t11 + 3.990978910625e-8*_t13 + 3.42083906625e-9;
  const double _t61 = -1.2131628753124999e-7*_hc2[0] + 1.09184658778125e-6*_t12 - 2.4020624931187498e-6*_t14 + 1.4869910671687499e-6*_t16;
  const double _t62 = 1.5513186346875001e-7*_t11 - 4.6539559040625004e-7*_t13 + 3.4129009963125003e-7*_t15 - 7.3872315937499999e-9;
  const double _t63 = 1.8518413687499999e-8*_t11 - 2.1604815968750001e-8*_t13 - 1.85184136875e-9;
  const double _t64 = -2.5963536374999999e-8*_hc2[0] + 1.2116316974999999e-7*_t12 - 1.09046852775e-7*_t14;
  const double _t65 = 7.3965541125000005e-8*_hc2[0] - 6.6568987012500007e-7*_t12 + 1.4645177142750001e-6*_t14 - 9.0660620407500009e-7*_t16;
  const double _t66 = 1.5942607349999999e-8*_hc2[0] - 7.4398834299999995e-8*_t12 + 6.6958950869999996e-8*_t14;
  const double _t67 = 4.5575413012500001e-8*_t11 - 1.367262390375e-7*_t13 + 1.002659086275e-7*_t15 - 2.1702577625000002e-9;
  const double _t68 = 1.6936171043750001e-8*_hc2[0] - 1.5242553939375e-7*_t12 + 3.3533618666625004e-7*_t14 - 2.0758906793625003e-7*_t16;
  const double _t69 = -4.5385788262499996e-8*_t11 + 1.3615736478749999e-7*_t13 - 9.98487341775e-8*_t15 + 2.1612280125e-9;
  const double _t70 = -1.9436495903125003e-8*_hc2[0] + 1.7492846312812501e-7*_t12 - 3.8484261888187503e-7*_t14 + 2.3823590692687501e-7*_t16;
#if _KMAX >= 1
  const double _t73 = 0.02637272316*_hc2[0];
  const double _t92 = _hc2[1]*_t3;
  const double _t93 = 0.0041808003333333333*_t92;
  const double _t94 = _hc2[0]*_t92;
  const double _t95 = 0.0054330432500000001*_t94;
  const double _t97 = _t11*_t92;
  const double _t98 = _t12*_t92;
  const double _t99 = _t13*_t92;
  const double _t100 = _t14*_t92;
  const double _t101 = _t15*_t92;
  const double _t104 = 0.00012639464208333333*_t92;
  const double _t105 = 0.00036656630125000002*_t94;
  const double _t106 = 4.9637727499999999e-5*_t92;
  const double _t108 = 0.00022863257125000001*_t94;
  const double _t110 = 3.4255828999999998e-5*_t92;
  const double _t111 = 0.0011386122125*_hc2[1]*_t1*_t2 - 0.0056930610625000001*_t97;
  const double _t112 = 4.3880128750000001e-5*_t94;
  const double _t113 = -0.0050824554687499994*_t94 + 0.011859062760416665*_t98;
  const double _t114 = 2.1425194833333332e-6*_t92;
  const double _t115 = 8.3622527374999987e-10*_t94;
  const double _t116 = 3.9181315125000004e-7*_t92;
  const double _t118 = 2.7876832125e-10*_t94;
  const double _t119 = -0.0017542429499999997*_t92 + 0.008771214749999999*_t97;
  const double _t120 = 0.0057159778437499992*_hc2[0]*_hc2[1]*_t1*_t2 - 0.013337281635416667*_t98;
  const double _t121 = 0.00052844256437500003*_hc2[1]*_t1*_t2 - 0.002642212821875*_t97;
  const double _t122 = -0.0019746613374999997*_t94 + 0.0046075431208333333*_t98;
  const double _t123 = -0.00021206810749999999*_t92 + 0.0010603405374999999*_t97;
  const double _t124 = 0.0096703717249999998*_hc2[1]*_t1*_t11*_t2 - 0.00069074083750000003*_t92 - 0.014505557587500002*_t99;
  const double _t125 = 2.4712865843750001e-8*_hc2[0]*_hc2[1]*_t1*_t2 - 5.7663353635416669e-8*_t98;
  const double _t126 = 0.031415262112499995*_hc2[1]*_t1*_t12*_t2 - 0.034556788323750004*_t100 - 0.0052358770187499997*_t94;
  const double _t127 = -5.6046216625e-5*_t92 + 0.00028023108312499997*_t97;
  const double _t128 = -6.5501209687499995e-9*_t94 + 1.5283615593749998e-8*_t98;
  const double _t129 = 1.3553785499999999e-9*_hc2[1]*_t1*_t2 - 6.7768927500000006e-9*_t97;
  const double _t130 = -2.850699221875e-9*_t94 + 6.6516315177083328e-9*_t98;
  const double _t131 = 0.020616651781249998*_hc2[1]*_t1*_t11*_t2 - 0.001472617984375*_t92 - 0.030924977671875003*_t99;
  const double _t132 = -4.2181882437499994e-10*_t92 + 2.109094121875e-9*_t97;
  const double _t133 = 6.1289322445312491e-7*_t100 + 9.2862609765624981e-8*_t94 - 5.5717565859374992e-7*_t98;
  const double _t134 = 1.5432011406249998e-9*_hc2[0]*_hc2[1]*_t1*_t2 - 3.6008026614583336e-9*_t98;
  const double _t135 = 0.0098084372312499998*_hc2[1]*_t1*_t11*_t2 - 0.00070060265937499995*_t92 - 0.014712655846875001*_t99;
  const double _t136 = 8.6990743218749999e-8*_hc2[1]*_t1*_t12*_t2 - 9.5689817540625002e-8*_t100 - 1.4498457203124999e-8*_t94;
  const double _t137 = 1.2674901640624998e-8*_t92 - 1.7744862296874999e-7*_t97 + 2.66172934453125e-7*_t99;
  const double _t138 = 0.073563783027109392*_t101 - 0.00085738674856770838*_t92 + 0.023149442211328128*_t97 - 0.08488128810820314*_t99;
  const double _t139 = 1.3662898790625e-7*_hc2[1]*_t1*_t12*_t2 - 1.5029188669687501e-7*_t100 - 2.2771497984375001e-8*_t94;
  const double _t140 = 4.1201886140624996e-8*_hc2[1]*_t1*_t11*_t2 - 2.9429918671874997e-9*_t92 - 6.1802829210937504e-8*_t99;
  const double _t141 = 8.5322524907812507e-8*_t100 + 1.2927655289062501e-8*_t94 - 7.7565931734375007e-8*_t98;
  const double _t142 = 1.5145396218749999e-8*_hc2[1]*_t1*_t11*_t2 - 1.0818140156249999e-9*_t92 - 2.2718094328125002e-8*_t99;
  const double _t143 = 2.5066477156874999e-8*_t100 + 3.7979510843749996e-9*_t94 - 2.2787706506249997e-8*_t98;
  const double _t144 = 2.4952031671875001e-6*_hc2[1]*_t1*_t13*_t2 + 2.5204072395833328e-8*_hc2[1]*_t1*_t2 - 2.1625094115624997e-6*_t101 - 6.8050995468749989e-7*_t97;
  const double _t145 = 6.6427530624999996e-10*_t92 - 9.2998542874999994e-9*_t97 + 1.3949781431249999e-8*_t99;
  const double _t146 = 2.2692894131249998e-8*_hc2[1]*_t1*_t12*_t2 - 2.4962183544375e-8*_t100 - 3.7821490218749997e-9*_t94;
  const double _t147 = 3.9564584199765629e-7*_t101 - 4.6112568997395836e-9*_t92 + 1.2450393629296876e-7*_t97 - 4.5651443307421876e-7*_t99;
  const double _t148 = 4.3370572792421877e-7*_t101 - 5.0548453138020825e-9*_t92 + 1.3648082347265625e-7*_t97 - 5.0042968606640623e-7*_t99;
  const double _t149 = 3.0510785714062501e-7*_hc2[1]*_t1*_t13*_t2 + 3.0818975468750001e-9*_hc2[1]*_t1*_t2 - 2.6442680952187506e-7*_t101 - 8.3211233765625009e-8*_t97;
  const double _t150 = 6.9861705555468757e-8*_hc2[1]*_t1*_t13*_t2 + 7.0567379348958335e-10*_hc2[1]*_t1*_t2 - 6.0546811481406261e-8*_t101 - 1.905319242421875e-8*_t97;
  const double _t151 = 6.948547285367188e-8*_t101 - 8.0985399596354171e-10*_t92 + 2.1866057891015626e-8*_t97 - 8.0175545600390631e-8*_t99;
#endif
#if _KMAX >= 2
  const double _t188 = 0.0010988634649999999*_t92;
  const double _t190 = 0.0056288863499999999*_t94;
  const double _t204 = _hc2[2]*_t203;
  const double _t211 = 0.00017420001388888888*_t204;
  const double _t212 = _hc2[0]*_t204;
  const double _t213 = ((_hc2[1]) * (_hc2[1]));
  const double _t214 = _t203*_t213;
  const double _t219 = 0.0083616006666666666*_t92;
  const double _t221 = _hc2[0]*_t214;
  const double _t222 = _t11*_t204;
  const double _t223 = _t12*_t204;
  const double _t224 = _t13*_t204;
  const double _t225 = _t14*_t204;
  const double _t226 = _t15*_t204;
  const double _t227 = 0.0021977269299999999*_t92;
  const double _t228 = 0.0108660865*_t94;
  const double _t229 = 0.0112577727*_t94;
  const double _t231 = _t11*_t214;
  const double _t232 = _t12*_t214;
  const double _t233 = _t13*_t214;
  const double _t234 = _t14*_t214;
  const double _t236 = 5.2664434201388885e-6*_t204;
  const double _t237 = 1.5273595885416667e-5*_t212;
  const double _t238 = 1.5273595885416667e-5*_t214;
  const double _t239 = 0.00025278928416666666*_t92;
  const double _t240 = 2.0682386458333333e-6*_t204;
  const double _t241 = 9.9275454999999999e-5*_t92;
  const double _t242 = 0.00073313260250000003*_t94;
  const double _t243 = 9.5263571354166665e-6*_t212;
  const double _t244 = 9.5263571354166665e-6*_t214;
  const double _t245 = 1.4273262083333332e-6*_t204;
  const double _t246 = 0.00045726514250000002*_t94;
  const double _t247 = 1.8283386979166667e-6*_t212;
  const double _t248 = 1.8283386979166667e-6*_t214;
  const double _t250 = 8.9271645138888882e-8*_t204;
  const double _t252 = 3.4842719739583328e-11*_t212;
  const double _t254 = 6.8511657999999995e-5*_t92;
  const double _t255 = 3.4842719739583328e-11*_t214;
  const double _t256 = 1.6325547968750001e-8*_t204;
  const double _t257 = 4.2850389666666663e-6*_t92;
  const double _t258 = 8.7760257500000001e-5*_t94;
  const double _t259 = 1.161534671875e-11*_t212;
  const double _t260 = 1.161534671875e-11*_t214;
  const double _t261 = 1.6724505474999997e-9*_t94;
  const double _t262 = 4.7442175520833332e-5*_hc2[2]*_t201*_t202 - 0.00047442175520833331*_t221 - 0.00023721087760416665*_t222;
  const double _t263 = 7.8362630250000007e-7*_t92;
  const double _t265 = 5.5753664250000001e-10*_t94;
  const double _t268 = -7.3093456249999979e-5*_t204 + 0.00073093456249999984*_t221 + 0.00036546728124999992*_t222;
  const double _t270 = 2.2018440182291667e-5*_hc2[2]*_t201*_t202 - 0.00022018440182291666*_t221 - 0.00011009220091145833*_t222;
  const double _t272 = -8.8361711458333331e-6*_t204 + 8.8361711458333317e-5*_t221 + 4.4180855729166659e-5*_t222;
  const double _t274 = -2.3352590260416665e-6*_t204 + 2.3352590260416664e-5*_t221 + 1.1676295130208332e-5*_t222;
  const double _t275 = -0.00021176897786458329*_t212 - 0.00021176897786458329*_t214 + 0.00049412761501736106*_t223 + 0.0014823828450520832*_t231;
  const double _t277 = 5.6474106249999991e-11*_hc2[2]*_t201*_t202 - 5.6474106249999998e-10*_t221 - 2.8237053124999999e-10*_t222;
  const double _t278 = -1.7575784348958331e-11*_t204 + 1.7575784348958334e-10*_t221 + 8.7878921744791668e-11*_t222;
  const double _t279 = 0.0002381657434895833*_hc2[0]*_hc2[2]*_t201*_t202 + 0.0002381657434895833*_t201*_t202*_t213 - 0.00055572006814236111*_t223 - 0.0016671602044270833*_t231;
  const double _t280 = -8.2277555729166649e-5*_t212 - 8.2277555729166649e-5*_t214 + 0.00019198096336805554*_t223 + 0.00057594289010416667*_t231;
  const double _t282 = 1.0297027434895833e-9*_hc2[0]*_hc2[2]*_t201*_t202 + 1.0297027434895833e-9*_t201*_t202*_t213 - 2.4026397348090276e-9*_t223 - 7.2079192044270837e-9*_t231;
  const double _t283 = 0.00080586431041666665*_hc2[0]*_t201*_t202*_t213 + 0.00040293215520833332*_hc2[2]*_t11*_t201*_t202 - 2.8780868229166668e-5*_t204 - 0.0006043982328125001*_t224 - 0.0024175929312500004*_t232;
  const double _t284 = -2.7292170703124996e-10*_t212 - 2.7292170703124996e-10*_t214 + 6.3681731640624986e-10*_t223 + 1.9104519492187498e-9*_t231;
  const double _t285 = -1.1877913424479165e-10*_t212 - 1.1877913424479165e-10*_t214 + 2.771513132378472e-10*_t223 + 8.314539397135416e-10*_t231;
  const double _t286 = 0.0017180543151041664*_hc2[0]*_t201*_t202*_t213 + 0.0008590271575520832*_hc2[2]*_t11*_t201*_t202 - 6.1359082682291657e-5*_t204 - 0.0012885407363281251*_t224 - 0.0051541629453125005*_t232;
  const double _t287 = 6.4300047526041654e-11*_hc2[0]*_hc2[2]*_t201*_t202 + 6.4300047526041654e-11*_t201*_t202*_t213 - 1.5003344422743056e-10*_t223 - 4.5010033268229169e-10*_t231;
  const double _t289 = 0.00081736976927083331*_hc2[0]*_t201*_t202*_t213 + 0.00040868488463541666*_hc2[2]*_t11*_t201*_t202 - 2.919177747395833e-5*_t204 - 0.00061302732695312499*_t224 - 0.0024521093078124999*_t232;
  const double _t290 = 5.2812090169270819e-10*_t204 - 1.4787385247395832e-8*_t221 - 7.3936926236979159e-9*_t222 + 1.1090538935546874e-8*_t224 + 4.4362155742187497e-8*_t232;
  const double _t291 = 3.4334905117187497e-9*_hc2[0]*_t201*_t202*_t213 + 1.7167452558593748e-9*_hc2[2]*_t11*_t201*_t202 - 1.2262466113281249e-10*_t204 - 2.5751178837890627e-9*_t224 - 1.0300471535156251e-8*_t232;
  const double _t292 = 0.0013089692546874997*_hc2[2]*_t12*_t201*_t202 + 0.0039269077640624993*_t11*_t201*_t202*_t213 - 0.00021816154244791664*_t212 - 0.00021816154244791664*_t214 - 0.0014398661801562501*_t225 - 0.0071993309007812511*_t233;
  const double _t293 = 1.2621163515624998e-9*_hc2[0]*_t201*_t202*_t213 + 6.3105817578124989e-10*_hc2[2]*_t11*_t201*_t202 - 4.5075583984374996e-11*_t204 - 9.4658726367187493e-10*_t224 - 3.7863490546874997e-9*_t232;
  const double _t294 = 2.7678137760416664e-11*_t204 - 7.7498785729166655e-10*_t221 - 3.8749392864583327e-10*_t222 + 5.8124089296874996e-10*_t224 + 2.3249635718749998e-9*_t232;
  const double _t295 = 3.8692754069010403e-9*_t212 + 3.8692754069010403e-9*_t214 - 2.3215652441406245e-8*_t223 + 2.5537217685546869e-8*_t225 - 6.9646957324218739e-8*_t231 + 1.2768608842773435e-7*_t233;
  const double _t296 = 3.6246143007812498e-9*_hc2[2]*_t12*_t201*_t202 + 1.087384290234375e-8*_t11*_t201*_t202*_t213 - 6.0410238346354157e-10*_t212 - 6.0410238346354157e-10*_t214 - 3.9870757308593745e-9*_t225 - 1.9935378654296878e-8*_t233;
  const double _t297 = 5.6928744960937502e-9*_hc2[2]*_t12*_t201*_t202 + 1.7078623488281251e-8*_t11*_t201*_t202*_t213 - 9.4881241601562503e-10*_t212 - 9.4881241601562503e-10*_t214 - 6.2621619457031255e-9*_t225 - 3.1310809728515631e-8*_t233;
  const double _t298 = -3.5724447856987849e-5*_t204 + 0.0019291201842773439*_t221 + 0.00096456009213867196*_t222 - 0.0035367203378417972*_t224 + 0.0030651576261295577*_t226 - 0.014146881351367189*_t232 + 0.018390945756777348*_t234;
  const double _t299 = 5.3865230371093748e-10*_t212 + 5.3865230371093748e-10*_t214 - 3.2319138222656253e-9*_t223 + 3.5551052044921878e-9*_t225 - 9.6957414667968758e-9*_t231 + 1.7775526022460939e-8*_t233;
  const double _t300 = 1.5824796184895832e-10*_t212 + 1.5824796184895832e-10*_t214 - 9.4948777109374989e-10*_t223 + 1.044436548203125e-9*_t225 - 2.8484633132812497e-9*_t231 + 5.2221827410156248e-9*_t233;
  const double _t301 = 1.0396679863281249e-7*_hc2[2]*_t13*_t201*_t202 + 1.0501696831597219e-9*_hc2[2]*_t201*_t202 + 4.1586719453124998e-7*_t12*_t201*_t202*_t213 - 5.6709162890624989e-8*_t221 - 2.8354581445312494e-8*_t222 - 9.0104558815104156e-8*_t226 - 5.4062735289062494e-7*_t234;
  const double _t302 = 9.4553725546874991e-10*_hc2[2]*_t12*_t201*_t202 + 2.8366117664062497e-9*_t11*_t201*_t202*_t213 - 1.5758954257812499e-10*_t212 - 1.5758954257812499e-10*_t214 - 1.0400909810156249e-9*_t225 - 5.2004549050781251e-9*_t233;
  const double _t303 = -1.9213570415581598e-10*_t204 + 1.0375328024414063e-8*_t221 + 5.1876640122070313e-9*_t222 - 1.902143471142578e-8*_t224 + 1.648524341656901e-8*_t226 - 7.6085738845703118e-8*_t232 + 9.8911460499414073e-8*_t234;
  const double _t304 = -2.1061855474175343e-10*_t204 + 1.1373401956054688e-8*_t221 + 5.6867009780273439e-9*_t222 - 2.0851236919433593e-8*_t224 + 1.8071071996842446e-8*_t226 - 8.3404947677734372e-8*_t232 + 1.0842643198105469e-7*_t234;
  const double _t305 = 1.2712827380859375e-8*_hc2[2]*_t13*_t201*_t202 + 1.2841239778645834e-10*_hc2[2]*_t201*_t202 + 5.0851309523437502e-8*_t12*_t201*_t202*_t213 - 6.9342694804687505e-9*_t221 - 3.4671347402343752e-9*_t222 - 1.1017783730078127e-8*_t226 - 6.6106702380468766e-8*_t234;
  const double _t306 = 2.9109043981445314e-9*_hc2[2]*_t13*_t201*_t202 + 2.940307472873264e-11*_hc2[2]*_t201*_t202 + 1.1643617592578126e-8*_t12*_t201*_t202*_t213 - 1.5877660353515625e-9*_t221 - 7.9388301767578126e-10*_t222 - 2.5227838117252606e-9*_t226 - 1.5136702870351565e-8*_t234;
  const double _t307 = -3.3743916498480902e-11*_t204 + 1.8221714909179688e-9*_t221 + 9.110857454589844e-10*_t222 - 3.3406477333496096e-9*_t224 + 2.8952280355696617e-9*_t226 - 1.3362590933398439e-8*_t232 + 1.737136821341797e-8*_t234;
#endif
#if _KMAX >= 3
  const double _t316 = 0.07911816948*_hc2[0];
  const double _t384 = 4.578597770833333e-5*_t204;
  const double _t385 = 0.00022637680208333332*_t212;
  const double _t386 = 0.00022637680208333332*_t214;
  const double _t387 = 0.00023453693125*_t212;
  const double _t388 = 0.00023453693125*_t214;
  const double _t405 = _hc2[3]*_t404;
  const double _t408 = 4.355000347222222e-5*_t405;
  const double _t409 = _hc2[0]*_t405;
  const double _t410 = _hc2[1]*_hc2[2]*_t404;
  const double _t413 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t414 = _t404*_t413;
  const double _t416 = 5.6594200520833323e-5*_t409;
  const double _t417 = 0.00016978260156249998*_t410;
  const double _t418 = _hc2[0]*_t410;
  const double _t420 = _hc2[0]*_t414;
  const double _t421 = _t11*_t405;
  const double _t422 = _t12*_t405;
  const double _t423 = _t13*_t405;
  const double _t424 = _t14*_t405;
  const double _t425 = _t15*_t405;
  const double _t432 = _t11*_t410;
  const double _t433 = _t12*_t410;
  const double _t434 = _t13*_t410;
  const double _t435 = _t14*_t410;
  const double _t440 = _t11*_t414;
  const double _t441 = _t12*_t414;
  const double _t442 = _t13*_t414;
  const double _t446 = 0.00052260004166666666*_t204;
  const double _t447 = 0.00013735793312499999*_t204;
  const double _t449 = 0.012542401*_t92;
  const double _t453 = 0.003296590395*_t92;
  const double _t454 = 0.016299129750000002*_t94;
  const double _t455 = 0.00070361079374999999*_t214;
  const double _t456 = 1.3166108550347219e-6*_t405;
  const double _t457 = 0.016886659049999999*_t94;
  const double _t458 = 3.8183989713541668e-6*_t409;
  const double _t459 = 1.1455196914062501e-5*_t410;
  const double _t460 = 5.1705966145833333e-7*_t405;
  const double _t461 = 2.3815892838541662e-6*_t409;
  const double _t462 = 7.1447678515624986e-6*_t410;
  const double _t463 = 3.5683155208333329e-7*_t405;
  const double _t464 = 1.5799330260416666e-5*_t204;
  const double _t465 = 4.5708467447916662e-7*_t409;
  const double _t466 = 1.3712540234374998e-6*_t410;
  const double _t467 = 6.2047159374999999e-6*_t204;
  const double _t469 = 2.2317911284722221e-8*_t405;
  const double _t470 = 4.5820787656250002e-5*_t214;
  const double _t471 = 2.8579071406249998e-5*_t212;
  const double _t472 = 2.8579071406249998e-5*_t214;
  const double _t473 = 8.710679934895832e-12*_t409;
  const double _t474 = 2.6132039804687496e-11*_t410;
  const double _t475 = 4.0813869921875004e-9*_t405;
  const double _t476 = 2.9038366796875e-12*_t409;
  const double _t477 = 8.7115100390625001e-12*_t410;
  const double _t479 = 4.2819786249999997e-6*_t204;
  const double _t481 = 2.6781493541666665e-7*_t204;
  const double _t484 = 5.4850160937500001e-6*_t214;
  const double _t486 = 1.0452815921874998e-10*_t214;
  const double _t487 = 1.1860543880208331e-5*_hc2[3]*_t404 - 0.00011860543880208331*_t414 - 0.00035581631640624995*_t418 - 5.9302719401041656e-5*_t421;
  const double _t488 = 0.00037918392624999999*_t92;
  const double _t490 = 4.8976643906250004e-8*_t204;
  const double _t491 = 0.00109969890375*_t94;
  const double _t494 = 3.484604015625e-11*_t214;
  const double _t496 = -1.8273364062499995e-5*_t405 + 0.00018273364062499996*_t414 + 0.00054820092187499994*_t418 + 9.1366820312499981e-5*_t421;
  const double _t497 = 5.5046100455729167e-6*_hc2[3]*_t404 - 5.5046100455729158e-5*_t414 - 0.00016513830136718748*_t418 - 2.7523050227864579e-5*_t421;
  const double _t498 = -5.2942244466145822e-5*_t409 - 0.00015882673339843745*_t410 + 0.00074119142252604159*_t420 + 0.00012353190375434027*_t422 + 0.0011117871337890624*_t432;
  const double _t499 = -2.2090427864583333e-6*_t405 + 2.2090427864583329e-5*_t414 + 6.6271283593749981e-5*_t418 + 1.1045213932291665e-5*_t421;
  const double _t500 = 0.0001489131825*_t92;
  const double _t501 = -5.8381475651041663e-7*_t405 + 5.8381475651041653e-6*_t414 + 1.7514442695312495e-5*_t418 + 2.9190737825520826e-6*_t421;
  const double _t503 = 0.00068589771375000006*_t94;
  const double _t507 = 1.4118526562499996e-11*_hc2[3]*_t404 - 1.41185265625e-10*_t414 - 4.2355579687499999e-10*_t418 - 7.0592632812499998e-11*_t421;
  const double _t508 = 5.9541435872395819e-5*_hc2[0]*_hc2[3]*_t404 + 0.00017862430761718745*_hc2[1]*_hc2[2]*_t404 - 0.00083358010221354167*_t420 - 0.00013893001703559028*_t422 - 0.0012503701533203124*_t432;
  const double _t509 = -4.3939460872395827e-12*_t405 + 4.3939460872395834e-11*_t414 + 1.318183826171875e-10*_t418 + 2.1969730436197917e-11*_t421;
  const double _t510 = -2.0569388932291662e-5*_t409 - 6.170816679687499e-5*_t410 + 0.00028797144505208333*_t420 + 4.7995240842013884e-5*_t422 + 0.000431957167578125*_t432;
  const double _t511 = 2.5742568587239582e-10*_hc2[0]*_hc2[3]*_t404 + 7.7227705761718742e-10*_hc2[1]*_hc2[2]*_t404 - 3.6039596022135414e-9*_t420 - 6.006599337022569e-10*_t422 - 5.4059394033203123e-9*_t432;
  const double _t513 = 0.00010276748699999999*_t92;
  const double _t515 = 0.00013164038625000001*_t94;
  const double _t516 = -6.8230426757812491e-11*_t409 - 2.0469128027343748e-10*_t410 + 9.5522597460937489e-10*_t420 + 1.5920432910156246e-10*_t422 + 1.4328389619140623e-9*_t432;
  const double _t517 = -2.9694783561197912e-11*_t409 - 8.9084350683593737e-11*_t410 + 4.157269698567708e-10*_t420 + 6.92878283094618e-11*_t422 + 6.2359045478515615e-10*_t432;
  const double _t519 = 0.00060439823281249988*_hc2[0]*_hc2[1]*_hc2[2]*_t404 + 0.00010073303880208332*_hc2[3]*_t11*_t404 + 0.00020146607760416664*_t404*_t413 - 7.195217057291667e-6*_t405 - 0.00015109955820312502*_t423 - 0.0018131946984375003*_t433 - 0.0018131946984375003*_t440;
  const double _t521 = 1.6075011881510414e-11*_hc2[0]*_hc2[3]*_t404 + 4.8225035644531244e-11*_hc2[1]*_hc2[2]*_t404 - 2.2505016634114585e-10*_t420 - 3.7508361056857641e-11*_t422 - 3.3757524951171877e-10*_t432;
  const double _t523 = 6.4275584499999999e-6*_t92;
  const double _t524 = 2.5086758212499998e-9*_t94;
  const double _t525 = 0.0012885407363281247*_hc2[0]*_hc2[1]*_hc2[2]*_t404 + 0.00021475678938802077*_hc2[3]*_t11*_t404 + 0.00042951357877604154*_t404*_t413 - 1.5339770670572914e-5*_t405 - 0.00032213518408203128*_t423 - 0.0038656222089843754*_t433 - 0.0038656222089843754*_t440;
  const double _t527 = 0.00061302732695312499*_hc2[0]*_hc2[1]*_hc2[2]*_t404 + 0.00010217122115885416*_hc2[3]*_t11*_t404 + 0.00020434244231770833*_t404*_t413 - 7.2979443684895817e-6*_t405 - 0.00015325683173828125*_t423 - 0.0018390819808593748*_t433 - 0.0018390819808593748*_t440;
  const double _t528 = 0.0019634538820312497*_hc2[0]*_t404*_t413 + 0.0029451808230468745*_hc2[1]*_hc2[2]*_t11*_t404 + 0.00032724231367187493*_hc2[3]*_t12*_t404 - 5.4540385611979152e-5*_t409 - 0.00016362115683593746*_t410 - 0.00035996654503906252*_t424 - 0.0053994981755859381*_t434 - 0.0071993309007812511*_t441;
  const double _t529 = 1.3203022542317705e-10*_t405 - 3.696846311848958e-9*_t414 - 1.1090538935546874e-8*_t418 - 1.848423155924479e-9*_t421 + 2.7726347338867186e-9*_t423 + 3.3271616806640625e-8*_t433 + 3.3271616806640625e-8*_t440;
  const double _t530 = 2.5751178837890623e-9*_hc2[0]*_hc2[1]*_hc2[2]*_t404 + 4.2918631396484371e-10*_hc2[3]*_t11*_t404 + 8.5837262792968742e-10*_t404*_t413 - 3.0656165283203122e-11*_t405 - 6.4377947094726567e-10*_t423 - 7.725353651367188e-9*_t433 - 7.725353651367188e-9*_t440;
  const double _t531 = 1.1754394537500001e-6*_t92;
  const double _t532 = 8.3630496375000001e-10*_t94;
  const double _t534 = 9.4658726367187493e-10*_hc2[0]*_hc2[1]*_hc2[2]*_t404 + 1.5776454394531247e-10*_hc2[3]*_t11*_t404 + 3.1552908789062494e-10*_t404*_t413 - 1.1268895996093749e-11*_t405 - 2.3664681591796873e-10*_t423 - 2.8397617910156248e-9*_t433 - 2.8397617910156248e-9*_t440;
  const double _t535 = 9.6731885172526009e-10*_t409 + 2.9019565551757803e-9*_t410 - 3.482347866210937e-8*_t420 - 5.8039131103515605e-9*_t422 + 6.3843044213867172e-9*_t424 - 5.2235217993164055e-8*_t432 + 9.5764566320800757e-8*_t434 + 1.2768608842773435e-7*_t441;
  const double _t536 = 6.9195344401041651e-12*_t405 - 1.9374696432291664e-10*_t414 - 5.8124089296874996e-10*_t418 - 9.6873482161458318e-11*_t421 + 1.4531022324218749e-10*_t423 + 1.7437226789062499e-9*_t433 + 1.7437226789062499e-9*_t440;
  const double _t537 = 5.436921451171875e-9*_hc2[0]*_t404*_t413 + 8.1553821767578116e-9*_hc2[1]*_hc2[2]*_t11*_t404 + 9.0615357519531236e-10*_hc2[3]*_t12*_t404 - 1.5102559586588539e-10*_t409 - 4.5307678759765618e-10*_t410 - 9.9676893271484363e-10*_t424 - 1.4951533990722657e-8*_t434 - 1.9935378654296878e-8*_t441;
  const double _t539 = 8.5393117441406253e-9*_hc2[0]*_t404*_t413 + 1.2808967616210939e-8*_hc2[1]*_hc2[2]*_t11*_t404 + 1.4232186240234375e-9*_hc2[3]*_t12*_t404 - 2.3720310400390626e-10*_t409 - 7.1160931201171877e-10*_t410 - 1.5655404864257812e-9*_t424 - 2.3483107296386725e-8*_t434 - 3.1310809728515631e-8*_t441;
  const double _t540 = 1.3466307592773437e-10*_t409 + 4.0398922778320311e-10*_t410 - 4.8478707333984379e-9*_t420 - 8.0797845556640622e-10*_t422 + 8.8877630112304695e-10*_t424 - 7.2718061000976569e-9*_t432 + 1.3331644516845704e-8*_t434 + 1.7775526022460939e-8*_t441;
  const double _t541 = 3.9561990462239579e-11*_t409 + 1.1868597138671874e-10*_t410 - 1.4242316566406248e-9*_t420 - 2.3737194277343747e-10*_t422 + 2.6110913705078124e-10*_t424 - 2.1363474849609375e-9*_t432 + 3.916637055761718e-9*_t434 + 5.222182741015624e-9*_t441;
  const double _t543 = -8.9311119642469623e-6*_t405 + 0.00048228004606933592*_t414 + 0.0014468401382080078*_t418 + 0.00024114002303466796*_t421 - 0.0008841800844604493*_t423 + 0.00076628940653238943*_t425 - 0.010610161013525393*_t433 + 0.013793209317583011*_t435 - 0.010610161013525393*_t440 + 0.022988682195971687*_t442;
  const double _t544 = 1.4183058832031249e-9*_hc2[0]*_t404*_t413 + 2.1274588248046874e-9*_hc2[1]*_hc2[2]*_t11*_t404 + 2.3638431386718748e-10*_hc2[3]*_t12*_t404 - 3.9397385644531246e-11*_t409 - 1.1819215693359374e-10*_t410 - 2.6002274525390622e-10*_t424 - 3.9003411788085936e-9*_t434 - 5.2004549050781251e-9*_t441;
  const double _t546 = 3.1190039589843745e-7*_hc2[1]*_hc2[2]*_t12*_t404 + 2.5991699658203123e-8*_hc2[3]*_t13*_t404 + 2.6254242078993043e-10*_hc2[3]*_t404 + 3.1190039589843745e-7*_t11*_t404*_t413 - 1.4177290722656246e-8*_t414 - 4.2531872167968737e-8*_t418 - 7.0886453613281228e-9*_t421 - 2.2526139703776039e-8*_t425 - 4.054705146679687e-7*_t435 - 6.7578419111328122e-7*_t442;
  const double _t547 = -4.8033926038953996e-11*_t405 + 2.5938320061035153e-9*_t414 + 7.7814960183105458e-9*_t418 + 1.2969160030517576e-9*_t421 - 4.7553586778564449e-9*_t423 + 4.1213108541422525e-9*_t425 - 5.7064304134277339e-8*_t433 + 7.4183595374560548e-8*_t435 - 5.7064304134277339e-8*_t440 + 1.236393256242676e-7*_t442;
  const double _t548 = -5.2654638685438351e-11*_t405 + 2.8433504890136719e-9*_t414 + 8.5300514670410158e-9*_t418 + 1.421675244506836e-9*_t421 - 5.2128092298583983e-9*_t423 + 4.5177679992106116e-9*_t425 - 6.2553710758300779e-8*_t433 + 8.1319823985791009e-8*_t435 - 6.2553710758300779e-8*_t440 + 1.3553303997631837e-7*_t442;
  const double _t549 = 3.8138482142578126e-8*_hc2[1]*_hc2[2]*_t12*_t404 + 3.1782068452148439e-9*_hc2[3]*_t13*_t404 + 3.2103099446614584e-11*_hc2[3]*_t404 + 3.8138482142578126e-8*_t11*_t404*_t413 - 1.7335673701171876e-9*_t414 - 5.2007021103515631e-9*_t418 - 8.6678368505859381e-10*_t421 - 2.7544459325195313e-9*_t425 - 4.9580026785351571e-8*_t435 - 8.263337797558596e-8*_t442;
  const double _t550 = 8.732713194433593e-9*_hc2[1]*_hc2[2]*_t12*_t404 + 7.2772609953613275e-10*_hc2[3]*_t13*_t404 + 7.3507686821831599e-12*_hc2[3]*_t404 + 8.7327131944335947e-9*_t11*_t404*_t413 - 3.9694150883789058e-10*_t414 - 1.1908245265136717e-9*_t418 - 1.9847075441894529e-10*_t421 - 6.3069595293131515e-10*_t425 - 1.1352527152763671e-8*_t435 - 1.8920878587939457e-8*_t442;
  const double _t551 = -8.4359791246202256e-12*_t405 + 4.5554287272949215e-10*_t414 + 1.3666286181884764e-9*_t418 + 2.2777143636474607e-10*_t421 - 8.3516193333740241e-10*_t423 + 7.2380700889241542e-10*_t425 - 1.0021943200048829e-8*_t433 + 1.3028526160063477e-8*_t435 - 1.0021943200048829e-8*_t440 + 2.1714210266772463e-8*_t442;
#endif
#if _KMAX >= 4
  const double _t562 = 0.10549089264*_hc2[0];
  const double _t708 = 0.00070361079374999999*_t212;
  const double _t742 = _hc2[4]*_t741;
  const double _t751 = _hc2[0]*_t742;
  const double _t752 = _hc2[1]*_hc2[3]*_t741;
  const double _t758 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t759 = _t741*_t758;
  const double _t760 = ((_hc2[2]) * (_hc2[2]));
  const double _t761 = _t741*_t760;
  const double _t768 = _hc2[0]*_t752;
  const double _t769 = _hc2[0]*_t759;
  const double _t770 = _hc2[0]*_t761;
  const double _t771 = _t11*_t742;
  const double _t772 = _t12*_t742;
  const double _t773 = _t13*_t742;
  const double _t774 = _t14*_t742;
  const double _t775 = _t15*_t742;
  const double _t776 = _hc2[2]*_t213*_t741;
  const double _t780 = _hc2[0]*_t776;
  const double _t781 = _t11*_t752;
  const double _t782 = _t12*_t752;
  const double _t783 = _t13*_t752;
  const double _t784 = _t14*_t752;
  const double _t787 = _t11*_t759;
  const double _t788 = _t11*_t761;
  const double _t789 = _t12*_t759;
  const double _t790 = _t12*_t761;
  const double _t791 = _t13*_t761;
  const double _t792 = _t14*_t761;
  const double _t793 = 0.00027471586624999998*_t204;
  const double _t796 = _t11*_t776;
  const double _t797 = _t12*_t776;
  const double _t798 = _t13*_t776;
  const double _t799 = 0.0014072215874999998*_t212;
  const double _t800 = 0.0014072215874999998*_t214;
#endif

  const double f = _hc1[0]*_t17 + _hc1[0]*_t20 + _hc1[0]*_t23 + _hc1[0]*_t25 + _hc1[0]*_t32 + _hc1[0]*_t35 + _hc1[0]*_t4 - 0.0043736526393718745*_hc1[0] - 0.156266500271875*_hc2[0] + 1.9735677658124998e-5*_t10 - 0.092294814328124974*_t11 + 0.49794463840937503*_t12 - 0.138056183978125*_t13 - 0.39506119958812502*_t14 + 0.080024660533125*_t15 + 0.106025815520625*_t16 + _t18*_t24 + _t18*_t28 + _t18*_t34 + _t18*_t39 + _t18*_t46 + _t18*_t50 - 0.0087909077199999994*_t19 - _t21*_t22 + _t21*_t29 + _t21*_t33 + _t21*_t40 + _t21*_t45 + _t21*_t51 + _t21*_t56 + _t26*_t27 + _t26*_t36 + _t26*_t42 + _t26*_t48 + _t26*_t52 + _t26*_t59 + _t26*_t61 + _t30*_t31 + _t30*_t41 + _t30*_t47 + _t30*_t53 + _t30*_t57 + _t30*_t62 + _t30*_t65 - _t37*_t38 + _t37*_t49 + _t37*_t55 + _t37*_t60 + _t37*_t64 + _t37*_t67 + _t37*_t68 - _t43*_t44 + _t43*_t54 + _t43*_t58 + _t43*_t63 + _t43*_t66 + _t43*_t69 + _t43*_t70 + 0.0070318268775656249*_t5 + 0.0046461028218468753*_t6 + 0.0030207156698031255*_t7 - 0.00094588310356312499*_t8 - 8.0008813355625009e-5*_t9 + 1.2243007249471218;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t17*_t71 + _t20*_t71 - _t22*_t80 + _t23*_t71 + _t24*_t79 + _t25*_t71 + _t27*_t81 + _t28*_t79 + _t29*_t80 + _t31*_t82 + _t32*_t71 + _t33*_t80 + _t34*_t79 + _t35*_t71 + _t36*_t81 - _t38*_t83 + _t39*_t79 + _t4*_t71 + _t40*_t80 + _t41*_t82 + _t42*_t81 - _t44*_t84 + _t45*_t80 + _t46*_t79 + _t47*_t82 + _t48*_t81 + _t49*_t83 + _t50*_t79 + _t51*_t80 + _t52*_t81 + _t53*_t82 + _t54*_t84 + _t55*_t83 + _t56*_t80 + _t57*_t82 + _t58*_t84 + _t59*_t81 + _t60*_t83 + _t61*_t81 + _t62*_t82 + _t63*_t84 + _t64*_t83 + _t65*_t82 + _t66*_t84 + _t67*_t83 + _t68*_t83 + _t69*_t84 + _t70*_t84 - 0.0043736526393718745*_t71 - _t72*_t73 + 0.01406365375513125*_t72 + 0.013938308465540627*_t74 + 0.012082862679212502*_t75 - 0.0047294155178156253*_t76 - 0.00048005288013375008*_t77 + 0.00013814974360687498*_t78;
  out[1] = df_dt;
  const double df_dx2 = _hc1[0]*_t111 + _hc1[0]*_t113 + _hc1[0]*_t124 + _hc1[0]*_t126 + _hc1[0]*_t138 + _hc1[0]*_t93 - _hc1[0]*_t95 + 0.02000616513328125*_t100 + 0.030924196193515625*_t101 - _t102*_t22 + _t102*_t29 + _t102*_t33 + _t102*_t40 + _t102*_t45 + _t102*_t51 + _t102*_t56 + _t103*_t27 + _t103*_t36 + _t103*_t42 + _t103*_t48 + _t103*_t52 + _t103*_t59 + _t103*_t61 - _t104*_t21 + _t105*_t21 + _t106*_t26 + _t107*_t31 + _t107*_t41 + _t107*_t47 + _t107*_t53 + _t107*_t57 + _t107*_t62 + _t107*_t65 + _t108*_t26 - _t109*_t38 + _t109*_t49 + _t109*_t55 + _t109*_t60 + _t109*_t64 + _t109*_t67 + _t109*_t68 + _t110*_t30 - _t112*_t30 - _t114*_t37 + _t115*_t37 - _t116*_t43 - _t117*_t44 + _t117*_t54 + _t117*_t58 + _t117*_t63 + _t117*_t66 + _t117*_t69 + _t117*_t70 - _t118*_t43 + _t119*_t18 + _t120*_t18 + _t121*_t21 + _t122*_t21 + _t123*_t26 + _t125*_t26 + _t127*_t30 + _t128*_t30 + _t129*_t37 + _t130*_t37 + _t131*_t18 + _t132*_t43 + _t133*_t18 + _t134*_t43 + _t135*_t21 + _t136*_t21 + _t137*_t26 + _t139*_t26 + _t140*_t30 + _t141*_t30 + _t142*_t37 + _t143*_t37 + _t144*_t18 + _t145*_t43 + _t146*_t43 + _t147*_t21 + _t148*_t26 + _t149*_t30 + _t150*_t37 + _t151*_t43 + _t17*_t85 - 0.00036628782166666664*_t18*_t92 - 0.00187629545*_t19*_t92 + _t20*_t85 + _t23*_t85 + _t24*_t96 + _t25*_t85 + _t28*_t96 + _t32*_t85 + _t34*_t96 + _t35*_t85 + _t39*_t96 + _t4*_t85 + _t46*_t96 + _t50*_t96 - _t73*_t86 - 0.0043736526393718745*_t85 + 0.01406365375513125*_t86 + 0.013938308465540627*_t87 + 0.012082862679212502*_t88 - 0.0047294155178156253*_t89 - 0.00048005288013375008*_t90 + 0.00013814974360687498*_t91 - 0.006511104177994791*_t92 - 0.0076912345273437476*_t94 + 0.062243079801171879*_t97 - 0.023009363996354164*_t98 - 0.08230441658085938*_t99;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t153*_t17 + _t153*_t20 + _t153*_t23 + _t153*_t25 + _t153*_t32 + _t153*_t35 + _t153*_t4 - 0.0043736526393718745*_t153 - _t154*_t73 + 0.01406365375513125*_t154 - _t156*_t73 + 0.01406365375513125*_t156 + 0.027876616931081254*_t157 + 0.013938308465540627*_t158 + 0.012082862679212502*_t159 - 0.0047294155178156253*_t160 - 0.00048005288013375008*_t161 + 0.00013814974360687498*_t162 + 0.036248588037637502*_t163 - 0.018917662071262501*_t164 - 0.0024002644006687504*_t165 + 0.00082889846164124986*_t166 + _t167*_t24 + _t167*_t28 + _t167*_t34 + _t167*_t39 + _t167*_t46 + _t167*_t50 + _t168*_t24 + _t168*_t28 + _t168*_t34 + _t168*_t39 + _t168*_t46 + _t168*_t50 - _t169*_t22 + _t169*_t29 + _t169*_t33 + _t169*_t40 + _t169*_t45 + _t169*_t51 + _t169*_t56 + _t170*_t27 + _t170*_t36 + _t170*_t42 + _t170*_t48 + _t170*_t52 + _t170*_t59 + _t170*_t61 + _t171*_t31 + _t171*_t41 + _t171*_t47 + _t171*_t53 + _t171*_t57 + _t171*_t62 + _t171*_t65 - _t172*_t38 + _t172*_t49 + _t172*_t55 + _t172*_t60 + _t172*_t64 + _t172*_t67 + _t172*_t68 - _t173*_t44 + _t173*_t54 + _t173*_t58 + _t173*_t63 + _t173*_t66 + _t173*_t69 + _t173*_t70;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = -_t104*_t80 + _t105*_t80 + _t106*_t81 + _t108*_t81 + _t110*_t82 + _t111*_t71 - _t112*_t82 + _t113*_t71 - _t114*_t83 + _t115*_t83 - _t116*_t84 - _t118*_t84 + _t119*_t79 + _t120*_t79 + _t121*_t80 + _t122*_t80 + _t123*_t81 + _t124*_t71 + _t125*_t81 + _t126*_t71 + _t127*_t82 + _t128*_t82 + _t129*_t83 + _t130*_t83 + _t131*_t79 + _t132*_t84 + _t133*_t79 + _t134*_t84 + _t135*_t80 + _t136*_t80 + _t137*_t81 + _t138*_t71 + _t139*_t81 + _t140*_t82 + _t141*_t82 + _t142*_t83 + _t143*_t83 + _t144*_t79 + _t145*_t84 + _t146*_t84 + _t147*_t80 + _t148*_t81 + _t149*_t82 + _t150*_t83 + _t151*_t84 + _t17*_t175 + _t175*_t20 + _t175*_t23 + _t175*_t25 + _t175*_t32 + _t175*_t35 + _t175*_t4 - 0.0043736526393718745*_t175 - _t176*_t73 + 0.01406365375513125*_t176 - _t177*_t73 + 0.01406365375513125*_t177 + 0.027876616931081254*_t178 + 0.013938308465540627*_t179 + 0.012082862679212502*_t180 - 0.0047294155178156253*_t181 - 0.00048005288013375008*_t182 + 0.00013814974360687498*_t183 + 0.036248588037637502*_t184 - 0.018917662071262501*_t185 - 0.0024002644006687504*_t186 + 0.00082889846164124986*_t187 - _t188*_t72 + _t189*_t24 + _t189*_t28 + _t189*_t34 + _t189*_t39 + _t189*_t46 + _t189*_t50 - _t190*_t72 + _t191*_t24 + _t191*_t28 + _t191*_t34 + _t191*_t39 + _t191*_t46 + _t191*_t50 - _t192*_t22 + _t192*_t29 + _t192*_t33 + _t192*_t40 + _t192*_t45 + _t192*_t51 + _t192*_t56 + _t193*_t27 + _t193*_t36 + _t193*_t42 + _t193*_t48 + _t193*_t52 + _t193*_t59 + _t193*_t61 + _t194*_t31 + _t194*_t41 + _t194*_t47 + _t194*_t53 + _t194*_t57 + _t194*_t62 + _t194*_t65 - _t195*_t38 + _t195*_t49 + _t195*_t55 + _t195*_t60 + _t195*_t64 + _t195*_t67 + _t195*_t68 - _t196*_t44 + _t196*_t54 + _t196*_t58 + _t196*_t63 + _t196*_t66 + _t196*_t69 + _t196*_t70 + _t71*_t93 - _t71*_t95;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = _hc1[0]*_t211 + _hc1[0]*_t262 + _hc1[0]*_t275 + _hc1[0]*_t283 + _hc1[0]*_t292 + _hc1[0]*_t298 - _t102*_t239 + _t102*_t242 + _t103*_t241 + _t103*_t246 + _t107*_t254 - _t107*_t258 - _t109*_t257 + _t109*_t261 + _t111*_t249 + _t113*_t249 - _t117*_t263 - _t117*_t265 + _t119*_t251 + _t120*_t251 + _t121*_t264 + _t122*_t264 + _t123*_t266 + _t124*_t249 + _t125*_t266 + _t126*_t249 + _t127*_t269 + _t128*_t269 + _t129*_t271 + _t130*_t271 + _t131*_t251 + _t132*_t276 + _t133*_t251 + _t134*_t276 + _t135*_t264 + _t136*_t264 + _t137*_t266 + _t138*_t249 + _t139*_t266 + _t140*_t269 + _t141*_t269 + _t142*_t271 + _t143*_t271 + _t144*_t251 + _t145*_t276 + _t146*_t276 + _t147*_t264 + _t148*_t266 + _t149*_t269 + _t150*_t271 + _t151*_t276 + _t17*_t198 - 1.5261992569444443e-5*_t18*_t204 - 7.8178977083333333e-5*_t18*_t214 + _t18*_t268 + _t18*_t279 + _t18*_t286 + _t18*_t295 + _t18*_t301 - 7.8178977083333333e-5*_t19*_t204 + _t198*_t20 + _t198*_t23 + _t198*_t25 + _t198*_t32 + _t198*_t35 + _t198*_t4 - 0.0043736526393718745*_t198 - _t199*_t73 + 0.01406365375513125*_t199 - _t200*_t73 + 0.01406365375513125*_t200 - 0.00027129600741644959*_t204 + 0.027876616931081254*_t205 + 0.013938308465540627*_t206 + 0.012082862679212502*_t207 - 0.0047294155178156253*_t208 - 0.00048005288013375008*_t209 - _t21*_t236 + _t21*_t237 + _t21*_t238 + _t21*_t270 + _t21*_t280 + _t21*_t289 + _t21*_t296 + _t21*_t303 + 0.00013814974360687498*_t210 - _t212*_t220 - 0.00032046810530598948*_t212 - _t214*_t220 - 0.00032046810530598948*_t214 + 0.036248588037637502*_t215 - 0.018917662071262501*_t216 - 0.0024002644006687504*_t217 + 0.00082889846164124986*_t218 + _t219*_t85 - _t22*_t253 + 0.0051869233167643226*_t221 + 0.0025934616583821613*_t222 - 0.00095872349984809009*_t223 - 0.0034293506908691408*_t224 + 0.00083359021388671871*_t225 + 0.0012885081747298177*_t226 - _t227*_t86 - _t228*_t85 - _t229*_t86 + _t230*_t24 + _t230*_t28 + _t230*_t34 + _t230*_t39 + _t230*_t46 + _t230*_t50 - 0.0028761704995442705*_t231 - 0.013717402763476563*_t232 + 0.0041679510694335939*_t233 + 0.0077310490483789062*_t234 + _t235*_t24 + _t235*_t28 + _t235*_t34 + _t235*_t39 + _t235*_t46 + _t235*_t50 + _t240*_t26 + _t243*_t26 + _t244*_t26 + _t245*_t30 - _t247*_t30 - _t248*_t30 - _t250*_t37 + _t252*_t37 + _t253*_t29 + _t253*_t33 + _t253*_t40 + _t253*_t45 + _t253*_t51 + _t253*_t56 + _t255*_t37 - _t256*_t43 - _t259*_t43 + _t26*_t272 + _t26*_t282 + _t26*_t290 + _t26*_t297 + _t26*_t304 - _t260*_t43 + _t267*_t27 + _t267*_t36 + _t267*_t42 + _t267*_t48 + _t267*_t52 + _t267*_t59 + _t267*_t61 + _t273*_t31 + _t273*_t41 + _t273*_t47 + _t273*_t53 + _t273*_t57 + _t273*_t62 + _t273*_t65 + _t274*_t30 + _t277*_t37 + _t278*_t43 - _t281*_t38 + _t281*_t49 + _t281*_t55 + _t281*_t60 + _t281*_t64 + _t281*_t67 + _t281*_t68 + _t284*_t30 + _t285*_t37 + _t287*_t43 - _t288*_t44 + _t288*_t54 + _t288*_t58 + _t288*_t63 + _t288*_t66 + _t288*_t69 + _t288*_t70 + _t291*_t30 + _t293*_t37 + _t294*_t43 + _t299*_t30 + _t30*_t305 + _t300*_t37 + _t302*_t43 + _t306*_t37 + _t307*_t43;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t17*_t309 + _t20*_t309 - _t22*_t332 + _t23*_t309 + _t24*_t330 + _t24*_t331 + _t25*_t309 + _t27*_t333 + _t28*_t330 + _t28*_t331 + _t29*_t332 + _t309*_t32 + _t309*_t35 + _t309*_t4 - 0.0043736526393718745*_t309 + _t31*_t334 - _t310*_t73 + 0.01406365375513125*_t310 - _t312*_t316 + 0.042190961265393748*_t312 + 0.027876616931081254*_t314 + 0.083629850793243754*_t315 + 0.072497176075275005*_t317 + 0.013938308465540627*_t318 + 0.012082862679212502*_t319 - 0.0047294155178156253*_t320 - 0.00048005288013375008*_t321 + 0.00013814974360687498*_t322 + 0.10874576411291251*_t323 - 0.056752986213787507*_t324 - 0.0072007932020062507*_t325 + 0.0024866953849237497*_t326 - 0.056752986213787507*_t327 - 0.0096010576026750016*_t328 + 0.0041444923082062492*_t329 + _t33*_t332 + _t330*_t34 + _t330*_t39 + _t330*_t46 + _t330*_t50 + _t331*_t34 + _t331*_t39 + _t331*_t46 + _t331*_t50 + _t332*_t40 + _t332*_t45 + _t332*_t51 + _t332*_t56 + _t333*_t36 + _t333*_t42 + _t333*_t48 + _t333*_t52 + _t333*_t59 + _t333*_t61 + _t334*_t41 + _t334*_t47 + _t334*_t53 + _t334*_t57 + _t334*_t62 + _t334*_t65 - _t336*_t38 + _t336*_t49 + _t336*_t55 + _t336*_t60 + _t336*_t64 + _t336*_t67 + _t336*_t68 - _t337*_t44 + _t337*_t54 + _t337*_t58 + _t337*_t63 + _t337*_t66 + _t337*_t69 + _t337*_t70;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = -_t104*_t169 + _t105*_t169 + _t106*_t170 + _t108*_t170 + _t110*_t171 + _t111*_t153 - _t112*_t171 + _t113*_t153 - _t114*_t172 + _t115*_t172 - _t116*_t173 - _t118*_t173 + _t119*_t167 + _t119*_t168 + _t120*_t167 + _t120*_t168 + _t121*_t169 + _t122*_t169 + _t123*_t170 + _t124*_t153 + _t125*_t170 + _t126*_t153 + _t127*_t171 + _t128*_t171 + _t129*_t172 + _t130*_t172 + _t131*_t167 + _t131*_t168 + _t132*_t173 + _t133*_t167 + _t133*_t168 + _t134*_t173 + _t135*_t169 + _t136*_t169 + _t137*_t170 + _t138*_t153 + _t139*_t170 + _t140*_t171 + _t141*_t171 + _t142*_t172 + _t143*_t172 + _t144*_t167 + _t144*_t168 + _t145*_t173 + _t146*_t173 + _t147*_t169 + _t148*_t170 + _t149*_t171 + _t150*_t172 + _t151*_t173 + _t153*_t93 - _t153*_t95 - _t154*_t188 - _t154*_t190 - _t156*_t188 - _t156*_t190 + _t17*_t339 + _t20*_t339 - _t22*_t359 + _t23*_t339 + _t24*_t357 + _t24*_t358 + _t25*_t339 + _t27*_t360 + _t28*_t357 + _t28*_t358 + _t29*_t359 + _t31*_t361 - _t316*_t341 + _t32*_t339 + _t33*_t359 + _t339*_t35 + _t339*_t4 - 0.0043736526393718745*_t339 + _t34*_t357 + _t34*_t358 - _t340*_t73 + 0.01406365375513125*_t340 + 0.042190961265393748*_t341 + 0.027876616931081254*_t342 + 0.083629850793243754*_t343 + 0.072497176075275005*_t344 + 0.013938308465540627*_t345 + 0.012082862679212502*_t346 - 0.0047294155178156253*_t347 - 0.00048005288013375008*_t348 + 0.00013814974360687498*_t349 + 0.10874576411291251*_t350 - 0.056752986213787507*_t351 - 0.0072007932020062507*_t352 + 0.0024866953849237497*_t353 - 0.056752986213787507*_t354 - 0.0096010576026750016*_t355 + 0.0041444923082062492*_t356 + _t357*_t39 + _t357*_t46 + _t357*_t50 + _t358*_t39 + _t358*_t46 + _t358*_t50 + _t359*_t40 + _t359*_t45 + _t359*_t51 + _t359*_t56 + _t36*_t360 + _t360*_t42 + _t360*_t48 + _t360*_t52 + _t360*_t59 + _t360*_t61 + _t361*_t41 + _t361*_t47 + _t361*_t53 + _t361*_t57 + _t361*_t62 + _t361*_t65 - _t362*_t38 + _t362*_t49 + _t362*_t55 + _t362*_t60 + _t362*_t64 + _t362*_t67 + _t362*_t68 - _t364*_t44 + _t364*_t54 + _t364*_t58 + _t364*_t63 + _t364*_t66 + _t364*_t69 + _t364*_t70;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = _t111*_t391 + _t113*_t391 + _t119*_t392 + _t119*_t393 + _t120*_t392 + _t120*_t393 + _t121*_t395 + _t122*_t395 + _t123*_t397 + _t124*_t391 + _t125*_t397 + _t126*_t391 + _t127*_t398 + _t128*_t398 + _t129*_t400 + _t130*_t400 + _t131*_t392 + _t131*_t393 + _t132*_t401 + _t133*_t392 + _t133*_t393 + _t134*_t401 + _t135*_t395 + _t136*_t395 + _t137*_t397 + _t138*_t391 + _t139*_t397 + _t140*_t398 + _t141*_t398 + _t142*_t400 + _t143*_t400 + _t144*_t392 + _t144*_t393 + _t145*_t401 + _t146*_t401 + _t147*_t395 + _t148*_t397 + _t149*_t398 + _t150*_t400 + _t151*_t401 + _t17*_t366 + _t175*_t219 - _t175*_t228 - _t176*_t227 - _t176*_t229 - _t177*_t227 - _t177*_t229 - _t192*_t239 + _t192*_t242 + _t193*_t241 + _t193*_t246 + _t194*_t254 - _t194*_t258 - _t195*_t257 + _t195*_t261 - _t196*_t263 - _t196*_t265 + _t20*_t366 + _t211*_t71 - _t22*_t394 + _t23*_t366 - _t236*_t80 + _t237*_t80 + _t238*_t80 + _t24*_t389 + _t24*_t390 + _t240*_t81 + _t243*_t81 + _t244*_t81 + _t245*_t82 - _t247*_t82 - _t248*_t82 + _t25*_t366 - _t250*_t83 + _t252*_t83 + _t255*_t83 - _t256*_t84 - _t259*_t84 - _t260*_t84 + _t262*_t71 + _t268*_t79 + _t27*_t396 + _t270*_t80 + _t272*_t81 + _t274*_t82 + _t275*_t71 + _t277*_t83 + _t278*_t84 + _t279*_t79 + _t28*_t389 + _t28*_t390 + _t280*_t80 + _t282*_t81 + _t283*_t71 + _t284*_t82 + _t285*_t83 + _t286*_t79 + _t287*_t84 + _t289*_t80 + _t29*_t394 + _t290*_t81 + _t291*_t82 + _t292*_t71 + _t293*_t83 + _t294*_t84 + _t295*_t79 + _t296*_t80 + _t297*_t81 + _t298*_t71 + _t299*_t82 + _t300*_t83 + _t301*_t79 + _t302*_t84 + _t303*_t80 + _t304*_t81 + _t305*_t82 + _t306*_t83 + _t307*_t84 + _t31*_t399 - _t316*_t368 + _t32*_t366 + _t33*_t394 + _t34*_t389 + _t34*_t390 + _t35*_t366 + _t36*_t396 + _t366*_t4 - 0.0043736526393718745*_t366 - _t367*_t73 + 0.01406365375513125*_t367 + 0.042190961265393748*_t368 + 0.027876616931081254*_t369 + 0.083629850793243754*_t370 + 0.072497176075275005*_t371 + 0.013938308465540627*_t372 + 0.012082862679212502*_t373 - 0.0047294155178156253*_t374 - 0.00048005288013375008*_t375 + 0.00013814974360687498*_t376 + 0.10874576411291251*_t377 - 0.056752986213787507*_t378 - 0.0072007932020062507*_t379 - _t38*_t402 + 0.0024866953849237497*_t380 - 0.056752986213787507*_t381 - 0.0096010576026750016*_t382 + 0.0041444923082062492*_t383 - _t384*_t72 - _t385*_t71 - _t386*_t71 - _t387*_t72 - _t388*_t72 + _t389*_t39 + _t389*_t46 + _t389*_t50 + _t39*_t390 + _t390*_t46 + _t390*_t50 + _t394*_t40 + _t394*_t45 + _t394*_t51 + _t394*_t56 + _t396*_t42 + _t396*_t48 + _t396*_t52 + _t396*_t59 + _t396*_t61 + _t399*_t41 + _t399*_t47 + _t399*_t53 + _t399*_t57 + _t399*_t62 + _t399*_t65 + _t402*_t49 + _t402*_t55 + _t402*_t60 + _t402*_t64 + _t402*_t67 + _t402*_t68 - _t403*_t44 + _t403*_t54 + _t403*_t58 + _t403*_t63 + _t403*_t66 + _t403*_t69 + _t403*_t70;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = _hc1[0]*_t408 - _hc1[0]*_t416 - _hc1[0]*_t417 + _hc1[0]*_t487 + _hc1[0]*_t498 + _hc1[0]*_t519 + _hc1[0]*_t528 + _hc1[0]*_t543 - _t102*_t464 + _t102*_t470 + _t103*_t467 + _t103*_t471 + _t103*_t472 + _t107*_t479 - _t107*_t484 - _t109*_t481 + _t109*_t486 + _t111*_t478 + _t113*_t478 - _t117*_t490 - _t117*_t494 + _t119*_t480 + _t119*_t483 + _t120*_t480 + _t120*_t483 + _t121*_t506 + _t122*_t506 + _t123*_t518 + _t124*_t478 + _t125*_t518 + _t126*_t478 + _t127*_t526 + _t128*_t526 + _t129*_t538 + _t130*_t538 + _t131*_t480 + _t131*_t483 + _t132*_t542 + _t133*_t480 + _t133*_t483 + _t134*_t542 + _t135*_t506 + _t136*_t506 + _t137*_t518 + _t138*_t478 + _t139*_t518 + _t140*_t526 + _t141*_t526 + _t142*_t538 + _t143*_t538 + _t144*_t480 + _t144*_t483 + _t145*_t542 + _t146*_t542 + _t147*_t506 + _t148*_t518 + _t149*_t526 + _t150*_t538 + _t151*_t542 + _t17*_t407 - 3.8154981423611109e-6*_t18*_t405 - 5.8634232812499999e-5*_t18*_t410 + _t18*_t496 + _t18*_t508 + _t18*_t525 + _t18*_t535 + _t18*_t546 - 1.9544744270833333e-5*_t19*_t405 + _t198*_t449 - _t198*_t454 - _t199*_t453 - _t199*_t457 + _t20*_t407 - _t200*_t453 - _t200*_t457 - _t21*_t456 + _t21*_t458 + _t21*_t459 + _t21*_t497 + _t21*_t510 + _t21*_t527 + _t21*_t537 + _t21*_t547 - _t212*_t448 - _t212*_t450 + _t212*_t468 - _t212*_t482 + _t212*_t485 - _t212*_t492 - _t214*_t448 - _t22*_t489 + _t23*_t407 + _t24*_t451 + _t24*_t452 + _t25*_t407 - _t253*_t488 + _t253*_t491 + _t26*_t460 + _t26*_t461 + _t26*_t462 + _t26*_t499 + _t26*_t511 + _t26*_t529 + _t26*_t539 + _t26*_t548 + _t262*_t493 + _t267*_t500 + _t267*_t503 + _t268*_t495 + _t27*_t502 + _t270*_t504 + _t272*_t505 + _t273*_t513 - _t273*_t515 + _t274*_t512 + _t275*_t493 + _t277*_t514 + _t278*_t520 + _t279*_t495 + _t28*_t451 + _t28*_t452 + _t280*_t504 - _t281*_t523 + _t281*_t524 + _t282*_t505 + _t283*_t493 + _t284*_t512 + _t285*_t514 + _t286*_t495 + _t287*_t520 - _t288*_t531 - _t288*_t532 + _t289*_t504 + _t29*_t489 + _t290*_t505 + _t291*_t512 + _t292*_t493 + _t293*_t514 + _t294*_t520 + _t295*_t495 + _t296*_t504 + _t297*_t505 + _t298*_t493 + _t299*_t512 + _t30*_t463 - _t30*_t465 - _t30*_t466 + _t30*_t501 + _t30*_t516 + _t30*_t530 + _t30*_t540 + _t30*_t549 + _t300*_t514 + _t301*_t495 + _t302*_t520 + _t303*_t504 + _t304*_t505 + _t305*_t512 + _t306*_t514 + _t307*_t520 + _t31*_t522 - _t316*_t412 + _t32*_t407 + _t33*_t489 + _t34*_t451 + _t34*_t452 + _t35*_t407 + _t36*_t502 - _t37*_t469 + _t37*_t473 + _t37*_t474 + _t37*_t507 + _t37*_t517 + _t37*_t534 + _t37*_t541 + _t37*_t550 - _t38*_t533 + _t39*_t451 + _t39*_t452 + _t4*_t407 + _t40*_t489 - 6.7824001854112397e-5*_t405 - 0.0043736526393718745*_t407 - 8.0117026326497371e-5*_t409 + _t41*_t522 - 0.00024035107897949211*_t410 - _t411*_t73 + 0.01406365375513125*_t411 + 0.042190961265393748*_t412 + 0.0012967308291910807*_t414 + 0.027876616931081254*_t415 + 0.003890192487573242*_t418 + 0.083629850793243754*_t419 + _t42*_t502 - 0.0014380852497721352*_t420 + 0.00064836541459554033*_t421 - 0.00023968087496202252*_t422 - 0.00085733767271728521*_t423 + 0.00020839755347167965*_t424 + 0.00032212704368245442*_t425 + 0.072497176075275005*_t426 + 0.013938308465540627*_t427 + 0.012082862679212502*_t428 - 0.0047294155178156253*_t429 - _t43*_t475 - _t43*_t476 - _t43*_t477 + _t43*_t509 + _t43*_t521 + _t43*_t536 + _t43*_t544 + _t43*_t551 - 0.00048005288013375008*_t430 + 0.00013814974360687498*_t431 - 0.0021571278746582026*_t432 - 0.010288052072607422*_t433 + 0.0031259633020751954*_t434 + 0.0057982867862841798*_t435 + 0.10874576411291251*_t436 - 0.056752986213787507*_t437 - 0.0072007932020062507*_t438 + 0.0024866953849237497*_t439 - _t44*_t545 - 0.010288052072607422*_t440 + 0.0041679510694335939*_t441 + 0.0096638113104736342*_t442 - 0.056752986213787507*_t443 - 0.0096010576026750016*_t444 + 0.0041444923082062492*_t445 + _t446*_t85 - _t447*_t86 + _t45*_t489 + _t451*_t46 + _t451*_t50 + _t452*_t46 + _t452*_t50 - _t455*_t86 + _t47*_t522 + _t48*_t502 + _t489*_t51 + _t489*_t56 + _t49*_t533 + _t502*_t52 + _t502*_t59 + _t502*_t61 + _t522*_t53 + _t522*_t57 + _t522*_t62 + _t522*_t65 + _t533*_t55 + _t533*_t60 + _t533*_t64 + _t533*_t67 + _t533*_t68 + _t54*_t545 + _t545*_t58 + _t545*_t63 + _t545*_t66 + _t545*_t69 + _t545*_t70;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t17*_t553 + _t20*_t553 - _t22*_t589 + _t23*_t553 + _t24*_t586 + _t24*_t587 + _t24*_t588 + _t25*_t553 + _t27*_t590 + _t28*_t586 + _t28*_t587 + _t28*_t588 + _t29*_t589 + _t31*_t591 - _t316*_t560 + _t32*_t553 + _t33*_t589 + _t34*_t586 + _t34*_t587 + _t34*_t588 + _t35*_t553 + _t36*_t590 - _t38*_t592 + _t39*_t586 + _t39*_t587 + _t39*_t588 + _t4*_t553 + _t40*_t589 + _t41*_t591 + _t42*_t590 - _t44*_t593 + _t45*_t589 + _t46*_t586 + _t46*_t587 + _t46*_t588 + _t47*_t591 + _t48*_t590 + _t49*_t592 + _t50*_t586 + _t50*_t587 + _t50*_t588 + _t51*_t589 + _t52*_t590 + _t53*_t591 + _t54*_t593 + _t55*_t592 - 0.0043736526393718745*_t553 - _t554*_t73 + 0.01406365375513125*_t554 - _t556*_t562 + 0.056254615020524999*_t556 + 0.072497176075275005*_t558 + _t56*_t589 + 0.042190961265393748*_t560 + 0.11150646772432501*_t561 - 0.11350597242757501*_t563 + 0.083629850793243754*_t564 + 0.013938308465540627*_t565 + 0.012082862679212502*_t566 - 0.0047294155178156253*_t567 - 0.00048005288013375008*_t568 + 0.00013814974360687498*_t569 + _t57*_t591 + 0.16725970158648751*_t571 + 0.43498305645165003*_t572 + 0.14499435215055001*_t573 - 0.075670648285050005*_t574 - 0.0096010576026750016*_t575 + 0.0033155938465649995*_t576 - 0.028803172808025003*_t577 + 0.10874576411291251*_t578 + 0.016577969232824997*_t579 + _t58*_t593 - 0.056752986213787507*_t580 - 0.0072007932020062507*_t581 + 0.0024866953849237497*_t582 - 0.34051791728272507*_t583 - 0.057606345616050006*_t584 + 0.024866953849237497*_t585 + _t59*_t590 + _t590*_t61 + _t591*_t62 + _t591*_t65 + _t592*_t60 + _t592*_t64 + _t592*_t67 + _t592*_t68 + _t593*_t63 + _t593*_t66 + _t593*_t69 + _t593*_t70;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = -_t104*_t332 + _t105*_t332 + _t106*_t333 + _t108*_t333 + _t110*_t334 + _t111*_t309 - _t112*_t334 + _t113*_t309 - _t114*_t336 + _t115*_t336 - _t116*_t337 - _t118*_t337 + _t119*_t330 + _t119*_t331 + _t120*_t330 + _t120*_t331 + _t121*_t332 + _t122*_t332 + _t123*_t333 + _t124*_t309 + _t125*_t333 + _t126*_t309 + _t127*_t334 + _t128*_t334 + _t129*_t336 + _t130*_t336 + _t131*_t330 + _t131*_t331 + _t132*_t337 + _t133*_t330 + _t133*_t331 + _t134*_t337 + _t135*_t332 + _t136*_t332 + _t137*_t333 + _t138*_t309 + _t139*_t333 + _t140*_t334 + _t141*_t334 + _t142*_t336 + _t143*_t336 + _t144*_t330 + _t144*_t331 + _t145*_t337 + _t146*_t337 + _t147*_t332 + _t148*_t333 + _t149*_t334 + _t150*_t336 + _t151*_t337 + _t17*_t595 - _t188*_t310 - _t190*_t310 + _t20*_t595 - _t22*_t626 + _t23*_t595 + _t24*_t623 + _t24*_t624 + _t24*_t625 + _t25*_t595 + _t27*_t627 + _t28*_t623 + _t28*_t624 + _t28*_t625 + _t29*_t626 + _t309*_t93 - _t309*_t95 + _t31*_t629 - _t312*_t453 - _t312*_t457 - _t316*_t599 + _t32*_t595 + _t33*_t626 + _t34*_t623 + _t34*_t624 + _t34*_t625 + _t35*_t595 + _t36*_t627 - _t38*_t630 + _t39*_t623 + _t39*_t624 + _t39*_t625 + _t4*_t595 + _t40*_t626 + _t41*_t629 + _t42*_t627 - _t44*_t632 + _t45*_t626 + _t46*_t623 + _t46*_t624 + _t46*_t625 + _t47*_t629 + _t48*_t627 + _t49*_t630 + _t50*_t623 + _t50*_t624 + _t50*_t625 + _t51*_t626 + _t52*_t627 + _t53*_t629 + _t54*_t632 + _t55*_t630 + _t56*_t626 - _t562*_t597 + _t57*_t629 + _t58*_t632 + _t59*_t627 - 0.0043736526393718745*_t595 - _t596*_t73 + 0.01406365375513125*_t596 + 0.056254615020524999*_t597 + 0.072497176075275005*_t598 + 0.042190961265393748*_t599 + _t60*_t630 + 0.11150646772432501*_t600 - 0.11350597242757501*_t601 + 0.083629850793243754*_t602 + 0.013938308465540627*_t603 + 0.012082862679212502*_t604 - 0.0047294155178156253*_t605 - 0.00048005288013375008*_t606 + 0.00013814974360687498*_t607 + 0.16725970158648751*_t608 + 0.43498305645165003*_t609 + _t61*_t627 + 0.14499435215055001*_t610 - 0.075670648285050005*_t611 - 0.0096010576026750016*_t612 + 0.0033155938465649995*_t613 - 0.028803172808025003*_t614 + 0.10874576411291251*_t615 + 0.016577969232824997*_t616 - 0.056752986213787507*_t617 - 0.0072007932020062507*_t618 + 0.0024866953849237497*_t619 + _t62*_t629 - 0.34051791728272507*_t620 - 0.057606345616050006*_t621 + 0.024866953849237497*_t622 + _t629*_t65 + _t63*_t632 + _t630*_t64 + _t630*_t67 + _t630*_t68 + _t632*_t66 + _t632*_t69 + _t632*_t70;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = _t111*_t665 + _t113*_t665 + _t119*_t666 + _t119*_t667 + _t120*_t666 + _t120*_t667 + _t121*_t668 + _t122*_t668 + _t123*_t670 + _t124*_t665 + _t125*_t670 + _t126*_t665 + _t127*_t671 + _t128*_t671 + _t129*_t673 + _t130*_t673 + _t131*_t666 + _t131*_t667 + _t132*_t674 + _t133*_t666 + _t133*_t667 + _t134*_t674 + _t135*_t668 + _t136*_t668 + _t137*_t670 + _t138*_t665 + _t139*_t670 + _t140*_t671 + _t141*_t671 + _t142*_t673 + _t143*_t673 + _t144*_t666 + _t144*_t667 + _t145*_t674 + _t146*_t674 + _t147*_t668 + _t148*_t670 + _t149*_t671 + _t150*_t673 + _t151*_t674 + _t153*_t211 + _t153*_t262 + _t153*_t275 + _t153*_t283 + _t153*_t292 + _t153*_t298 - _t153*_t385 - _t153*_t386 - _t154*_t384 - _t154*_t387 - _t154*_t388 - _t156*_t384 - _t156*_t387 - _t156*_t388 + _t167*_t268 + _t167*_t279 + _t167*_t286 + _t167*_t295 + _t167*_t301 + _t168*_t268 + _t168*_t279 + _t168*_t286 + _t168*_t295 + _t168*_t301 - _t169*_t236 + _t169*_t237 + _t169*_t238 + _t169*_t270 + _t169*_t280 + _t169*_t289 + _t169*_t296 + _t169*_t303 + _t17*_t634 + _t170*_t240 + _t170*_t243 + _t170*_t244 + _t170*_t272 + _t170*_t282 + _t170*_t290 + _t170*_t297 + _t170*_t304 + _t171*_t245 - _t171*_t247 - _t171*_t248 + _t171*_t274 + _t171*_t284 + _t171*_t291 + _t171*_t299 + _t171*_t305 - _t172*_t250 + _t172*_t252 + _t172*_t255 + _t172*_t277 + _t172*_t285 + _t172*_t293 + _t172*_t300 + _t172*_t306 - _t173*_t256 - _t173*_t259 - _t173*_t260 + _t173*_t278 + _t173*_t287 + _t173*_t294 + _t173*_t302 + _t173*_t307 + _t20*_t634 + _t219*_t339 - _t22*_t669 - _t227*_t340 - _t228*_t339 - _t229*_t340 + _t23*_t634 - _t239*_t359 + _t24*_t662 + _t24*_t663 + _t24*_t664 + _t241*_t360 + _t242*_t359 + _t246*_t360 + _t25*_t634 + _t254*_t361 - _t257*_t362 - _t258*_t361 + _t261*_t362 - _t263*_t364 - _t265*_t364 + _t27*_t672 + _t28*_t662 + _t28*_t663 + _t28*_t664 + _t29*_t669 + _t31*_t675 - _t316*_t638 + _t32*_t634 + _t33*_t669 + _t34*_t662 + _t34*_t663 + _t34*_t664 - 0.00659318079*_t341*_t92 - 0.033773318099999998*_t341*_t94 + _t35*_t634 + _t36*_t672 - _t38*_t676 + _t39*_t662 + _t39*_t663 + _t39*_t664 + _t4*_t634 + _t40*_t669 + _t41*_t675 + _t42*_t672 - _t44*_t677 + _t45*_t669 + _t46*_t662 + _t46*_t663 + _t46*_t664 + _t47*_t675 + _t48*_t672 + _t49*_t676 + _t50*_t662 + _t50*_t663 + _t50*_t664 + _t51*_t669 + _t52*_t672 + _t53*_t675 + _t54*_t677 + _t55*_t676 + _t56*_t669 - _t562*_t636 + _t57*_t675 + _t58*_t677 + _t59*_t672 + _t60*_t676 + _t61*_t672 + _t62*_t675 + _t63*_t677 - 0.0043736526393718745*_t634 - _t635*_t73 + 0.01406365375513125*_t635 + 0.056254615020524999*_t636 + 0.072497176075275005*_t637 + 0.042190961265393748*_t638 + 0.11150646772432501*_t639 + _t64*_t676 - 0.11350597242757501*_t640 + 0.083629850793243754*_t641 + 0.013938308465540627*_t642 + 0.012082862679212502*_t643 - 0.0047294155178156253*_t644 - 0.00048005288013375008*_t645 + 0.00013814974360687498*_t646 + 0.16725970158648751*_t647 + 0.43498305645165003*_t648 + 0.14499435215055001*_t649 + _t65*_t675 - 0.075670648285050005*_t650 - 0.0096010576026750016*_t651 + 0.0033155938465649995*_t652 - 0.028803172808025003*_t653 + 0.10874576411291251*_t654 + 0.016577969232824997*_t655 - 0.056752986213787507*_t656 - 0.0072007932020062507*_t657 + 0.0024866953849237497*_t658 - 0.34051791728272507*_t659 + _t66*_t677 - 0.057606345616050006*_t660 + 0.024866953849237497*_t661 + _t67*_t676 + _t676*_t68 + _t677*_t69 + _t677*_t70;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = _t111*_t712 + _t113*_t712 + _t119*_t713 + _t119*_t714 + _t120*_t713 + _t120*_t714 + _t121*_t720 + _t122*_t720 + _t123*_t722 + _t124*_t712 + _t125*_t722 + _t126*_t712 + _t127*_t726 + _t128*_t726 + _t129*_t728 + _t130*_t728 + _t131*_t713 + _t131*_t714 + _t132*_t730 + _t133*_t713 + _t133*_t714 + _t134*_t730 + _t135*_t720 + _t136*_t720 + _t137*_t722 + _t138*_t712 + _t139*_t722 + _t140*_t726 + _t141*_t726 + _t142*_t728 + _t143*_t728 + _t144*_t713 + _t144*_t714 + _t145*_t730 + _t146*_t730 + _t147*_t720 + _t148*_t722 + _t149*_t726 + _t150*_t728 + _t151*_t730 + _t17*_t679 + _t175*_t446 - _t176*_t447 - _t176*_t455 - _t176*_t708 - _t177*_t447 - _t177*_t455 - _t177*_t708 + 4.5820787656250002e-5*_t192*_t212 - _t192*_t464 + _t192*_t470 + _t193*_t467 + _t193*_t471 + _t193*_t472 - 5.4850160937500001e-6*_t194*_t212 + _t194*_t479 - _t194*_t484 + 1.0452815921874998e-10*_t195*_t212 - _t195*_t481 + _t195*_t486 - 3.484604015625e-11*_t196*_t212 - _t196*_t490 - _t196*_t494 + _t20*_t679 - _t212*_t707 - _t214*_t707 - _t22*_t718 + _t23*_t679 + _t24*_t709 + _t24*_t710 + _t24*_t711 + _t25*_t679 + _t262*_t715 + _t268*_t716 + _t268*_t717 + _t27*_t724 + _t270*_t719 + _t272*_t721 + _t274*_t723 + _t275*_t715 + _t277*_t725 + _t278*_t727 + _t279*_t716 + _t279*_t717 + _t28*_t709 + _t28*_t710 + _t28*_t711 + _t280*_t719 + _t282*_t721 + _t283*_t715 + _t284*_t723 + _t285*_t725 + _t286*_t716 + _t286*_t717 + _t287*_t727 + _t289*_t719 + _t29*_t718 + _t290*_t721 + _t291*_t723 + _t292*_t715 + _t293*_t725 + _t294*_t727 + _t295*_t716 + _t295*_t717 + _t296*_t719 + _t297*_t721 + _t298*_t715 + _t299*_t723 + _t300*_t725 + _t301*_t716 + _t301*_t717 + _t302*_t727 + _t303*_t719 + _t304*_t721 + _t305*_t723 + _t306*_t725 + _t307*_t727 + _t31*_t729 - _t316*_t683 + _t32*_t679 + _t33*_t718 + _t34*_t709 + _t34*_t710 + _t34*_t711 + _t35*_t679 + _t36*_t724 + _t366*_t449 - _t366*_t454 - _t367*_t453 - _t367*_t457 - 0.009889771185*_t368*_t92 - 0.050659977149999993*_t368*_t94 - _t38*_t731 + _t39*_t709 + _t39*_t710 + _t39*_t711 - _t394*_t488 + _t394*_t491 + _t396*_t500 + _t396*_t503 + _t399*_t513 - _t399*_t515 + _t4*_t679 + _t40*_t718 - _t402*_t523 + _t402*_t524 - _t403*_t531 - _t403*_t532 - 1.1446494427083333e-5*_t405*_t72 + _t408*_t71 - 5.8634232812499999e-5*_t409*_t72 + _t41*_t729 - 0.0001759026984375*_t410*_t72 - _t416*_t71 - _t417*_t71 + _t42*_t724 - _t44*_t732 + _t45*_t718 - _t456*_t80 + _t458*_t80 + _t459*_t80 + _t46*_t709 + _t46*_t710 + _t46*_t711 + _t460*_t81 + _t461*_t81 + _t462*_t81 + _t463*_t82 - _t465*_t82 - _t466*_t82 - _t469*_t83 + _t47*_t729 + _t473*_t83 + _t474*_t83 - _t475*_t84 - _t476*_t84 - _t477*_t84 + _t48*_t724 + _t487*_t71 + _t49*_t731 + _t496*_t79 + _t497*_t80 + _t498*_t71 + _t499*_t81 + _t50*_t709 + _t50*_t710 + _t50*_t711 + _t501*_t82 + _t507*_t83 + _t508*_t79 + _t509*_t84 + _t51*_t718 + _t510*_t80 + _t511*_t81 + _t516*_t82 + _t517*_t83 + _t519*_t71 + _t52*_t724 + _t521*_t84 + _t525*_t79 + _t527*_t80 + _t528*_t71 + _t529*_t81 + _t53*_t729 + _t530*_t82 + _t534*_t83 + _t535*_t79 + _t536*_t84 + _t537*_t80 + _t539*_t81 + _t54*_t732 + _t540*_t82 + _t541*_t83 + _t543*_t71 + _t544*_t84 + _t546*_t79 + _t547*_t80 + _t548*_t81 + _t549*_t82 + _t55*_t731 + _t550*_t83 + _t551*_t84 + _t56*_t718 - _t562*_t681 + _t57*_t729 + _t58*_t732 + _t59*_t724 + _t60*_t731 + _t61*_t724 + _t62*_t729 + _t63*_t732 + _t64*_t731 + _t65*_t729 + _t66*_t732 + _t67*_t731 - 0.0043736526393718745*_t679 + _t68*_t731 - _t680*_t73 + 0.01406365375513125*_t680 + 0.056254615020524999*_t681 + 0.072497176075275005*_t682 + 0.042190961265393748*_t683 + 0.11150646772432501*_t684 - 0.11350597242757501*_t685 + 0.083629850793243754*_t686 + 0.013938308465540627*_t687 + 0.012082862679212502*_t688 - 0.0047294155178156253*_t689 + _t69*_t732 - 0.00048005288013375008*_t690 + 0.00013814974360687498*_t691 + 0.16725970158648751*_t692 + 0.43498305645165003*_t693 + 0.14499435215055001*_t694 - 0.075670648285050005*_t695 - 0.0096010576026750016*_t696 + 0.0033155938465649995*_t697 - 0.028803172808025003*_t698 + 0.10874576411291251*_t699 + _t70*_t732 + 0.016577969232824997*_t700 - 0.056752986213787507*_t701 - 0.0072007932020062507*_t702 + 0.0024866953849237497*_t703 - 0.34051791728272507*_t704 - 0.057606345616050006*_t705 + 0.024866953849237497*_t706;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 1.8145834780092591e-6*_hc1[0]*_t742 - 2.3580916883680551e-6*_hc1[0]*_t751 - 9.4323667534722205e-6*_hc1[0]*_t752 - 7.0742750651041654e-6*_hc1[0]*_t761 + _hc1[0]*(4.941893283420138e-7*_hc2[4]*_t1*_t740 - 1.9767573133680552e-5*_t768 - 1.4825679850260414e-5*_t770 - 2.470946641710069e-6*_t771 - 2.9651359700520828e-5*_t776) + _hc1[0]*(-2.2059268527560759e-6*_t751 - 8.8237074110243037e-6*_t752 + 3.0882975938585066e-5*_t759 - 6.6177805582682269e-6*_t761 + 5.1471626564308438e-6*_t772 + 0.0001852978556315104*_t780 + 6.1765951877170133e-5*_t781 + 4.63244639078776e-5*_t788) + _hc1[0]*(3.3577679600694439e-5*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t740 + 2.5183259700520826e-5*_hc2[0]*_t1*_t740*_t760 + 5.0366519401041652e-5*_hc2[2]*_t1*_t213*_t740 + 4.1972099500868049e-6*_hc2[4]*_t1*_t11*_t740 - 2.9980071072048612e-7*_t742 - 0.00015109955820312502*_t769 - 6.295814925130209e-6*_t773 - 0.00010073303880208334*_t782 - 7.5549779101562512e-5*_t790 - 0.00045329867460937507*_t796) + _hc1[0]*(0.00049086347050781242*_hc2[0]*_hc2[2]*_t1*_t213*_t740 + 0.00016362115683593746*_hc2[1]*_hc2[3]*_t1*_t11*_t740 + 1.3635096402994788e-5*_hc2[4]*_t1*_t12*_t740 + 0.0001227158676269531*_t1*_t11*_t740*_t760 + 8.1810578417968732e-5*_t1*_t740*_t758 - 2.272516067165798e-6*_t751 - 9.0900642686631921e-6*_t752 - 6.817548201497394e-6*_t761 - 1.4998606043294272e-5*_t774 - 0.00029997212086588546*_t783 - 0.00089991636259765639*_t787 - 0.00022497909064941407*_t791 - 0.0017998327251953126*_t797) + _hc1[0]*(-3.7212966517695676e-7*_t742 + 8.0380007678222654e-5*_t768 - 0.0008841800844604493*_t769 + 6.0285005758666991e-5*_t770 + 1.0047500959777832e-5*_t771 - 3.6840836852518719e-5*_t773 + 3.192872527218289e-5*_t775 + 0.00012057001151733398*_t776 - 0.0005894533896402995*_t782 + 0.00076628940653238943*_t784 + 0.0038314470326619478*_t789 - 0.00044209004223022465*_t790 + 0.00057471705489929212*_t792 - 0.0026525402533813481*_t796 + 0.0057471705489929217*_t798) - 5.2664434201388885e-6*_t102*_t405 + 1.5273595885416667e-5*_t102*_t409 + 2.0682386458333333e-6*_t103*_t405 + 9.5263571354166648e-6*_t103*_t409 + 2.8579071406249995e-5*_t103*_t410 + 1.4273262083333332e-6*_t107*_t405 - 1.8283386979166667e-6*_t107*_t409 - 8.9271645138888882e-8*_t109*_t405 + 3.4842719739583328e-11*_t109*_t409 + _t111*_t801 + _t113*_t801 - 1.6325547968750001e-8*_t117*_t405 - 1.161534671875e-11*_t117*_t409 + _t119*_t802 + _t119*_t803 + _t120*_t802 + _t120*_t803 + _t121*_t817 + _t122*_t817 + _t123*_t821 + _t124*_t801 + _t125*_t821 + _t126*_t801 + _t127*_t826 + _t128*_t826 + _t129*_t829 + _t130*_t829 + _t131*_t802 + _t131*_t803 + _t132*_t831 + _t133*_t802 + _t133*_t803 + _t134*_t831 + _t135*_t817 + _t136*_t817 + _t137*_t821 + _t138*_t801 + _t139*_t821 + _t140*_t826 + _t141*_t826 + _t142*_t829 + _t143*_t829 + _t144*_t802 + _t144*_t803 + _t145*_t831 + _t146*_t831 + _t147*_t817 + _t148*_t821 + _t149*_t826 + _t150*_t829 + _t151*_t831 + _t17*_t734 - 1.5897908926504629e-7*_t18*_t742 - 3.2574573784722221e-6*_t18*_t752 - 2.4430930338541666e-6*_t18*_t761 + _t18*(-7.6139016927083312e-7*_t742 + 3.0455606770833325e-5*_t768 + 2.2841705078124995e-5*_t770 + 3.8069508463541656e-6*_t771 + 4.568341015624999e-5*_t776) + _t18*(2.4808931613498258e-6*_hc2[0]*_hc2[4]*_t1*_t740 + 9.9235726453993031e-6*_hc2[1]*_hc2[3]*_t1*_t740 + 7.4426794840494765e-6*_t1*_t740*_t760 - 3.4732504258897569e-5*_t759 - 5.7887507098162613e-6*_t772 - 0.00020839502555338542*_t780 - 6.9465008517795139e-5*_t781 - 5.2098756388346347e-5*_t788) + _t18*(7.1585596462673591e-5*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t740 + 5.3689197347005193e-5*_hc2[0]*_t1*_t740*_t760 + 0.00010737839469401039*_hc2[2]*_t1*_t213*_t740 + 8.9481995578341988e-6*_hc2[4]*_t1*_t11*_t740 - 6.3915711127387139e-7*_t742 - 0.00032213518408203128*_t769 - 1.3422299336751303e-5*_t773 - 0.00021475678938802085*_t782 - 0.00016106759204101564*_t790 - 0.00096640555224609384*_t796) + _t18*(4.030495215521917e-11*_t751 + 1.6121980862087668e-10*_t752 - 1.4509782775878903e-9*_t759 + 1.2091485646565751e-10*_t761 - 2.4182971293131502e-10*_t772 + 2.6601268422444653e-10*_t774 - 8.7058696655273424e-9*_t780 - 2.9019565551757807e-9*_t781 + 5.3202536844889305e-9*_t783 + 1.5960761053466794e-8*_t787 - 2.1764674163818356e-9*_t788 + 3.9901902633666976e-9*_t791 + 3.1921522106933581e-8*_t797) + _t18*(2.599169965820312e-8*_hc2[0]*_t1*_t740*_t758 + 1.7327799772135416e-8*_hc2[1]*_hc2[3]*_t1*_t12*_t740 + 7.7975098974609364e-8*_hc2[2]*_t1*_t11*_t213*_t740 + 1.0829874857584635e-9*_hc2[4]*_t1*_t13*_t740 + 1.0939267532913767e-11*_hc2[4]*_t1*_t740 + 1.299584982910156e-8*_t1*_t12*_t740*_t760 - 2.3628817871093743e-9*_t768 - 1.7721613403320307e-9*_t770 - 2.9536022338867178e-10*_t771 - 9.3858915432400156e-10*_t775 - 3.5443226806640614e-9*_t776 - 2.2526139703776039e-8*_t784 - 1.126306985188802e-7*_t789 - 1.6894604777832029e-8*_t792 - 1.6894604777832031e-7*_t798) - 8.1436434461805551e-7*_t19*_t742 + 0.0010452000833333333*_t198*_t204 - _t199*_t793 - _t199*_t799 - _t199*_t800 + _t20*_t734 - _t200*_t793 - _t200*_t799 - _t200*_t800 - 3.1598660520833333e-5*_t204*_t253 + 1.2409431875e-5*_t204*_t267 + 8.5639572499999994e-6*_t204*_t273 - 5.3562987083333329e-7*_t204*_t281 - 9.7953287812500009e-8*_t204*_t288 - 5.4858785626446744e-8*_t21*_t742 + 1.5909995713975693e-7*_t21*_t751 + 6.3639982855902774e-7*_t21*_t752 + 4.7729987141927085e-7*_t21*_t761 + _t21*(2.2935875189887153e-7*_hc2[4]*_t1*_t740 - 9.1743500759548586e-6*_t768 - 6.8807625569661448e-6*_t770 - 1.1467937594943573e-6*_t771 - 1.376152511393229e-5*_t776) + _t21*(-8.5705787217881923e-7*_t751 - 3.4282314887152769e-6*_t752 + 1.1998810210503471e-5*_t759 - 2.5711736165364578e-6*_t761 + 1.9998017017505784e-6*_t772 + 7.1992861263020833e-5*_t780 + 2.3997620421006942e-5*_t781 + 1.7998215315755208e-5*_t788) + _t21*(3.4057073719618052e-5*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t740 + 2.5542805289713541e-5*_hc2[0]*_t1*_t740*_t760 + 5.1085610579427082e-5*_hc2[2]*_t1*_t213*_t740 + 4.2571342149522566e-6*_hc2[4]*_t1*_t11*_t740 - 3.0408101535373254e-7*_t742 - 0.00015325683173828122*_t769 - 6.3857013224283853e-6*_t773 - 0.00010217122115885415*_t782 - 7.662841586914061e-5*_t790 - 0.00045977049521484371*_t796) + _t21*(1.3592303627929687e-9*_hc2[0]*_hc2[2]*_t1*_t213*_t740 + 4.5307678759765618e-10*_hc2[1]*_hc2[3]*_t1*_t11*_t740 + 3.7756398966471348e-11*_hc2[4]*_t1*_t12*_t740 + 3.3980759069824213e-10*_t1*_t11*_t740*_t760 + 2.2653839379882812e-10*_t1*_t740*_t758 - 6.2927331610785578e-12*_t751 - 2.5170932644314231e-11*_t752 - 1.8878199483235674e-11*_t761 - 4.153203886311848e-11*_t774 - 8.3064077726236976e-10*_t783 - 2.4919223317871097e-9*_t787 - 6.2298058294677732e-10*_t791 - 4.9838446635742186e-9*_t797) + _t21*(-2.0014135849564165e-12*_t742 + 4.3230533435058586e-10*_t768 - 4.7553586778564449e-9*_t769 + 3.2422900076293941e-10*_t770 + 5.4038166793823232e-11*_t771 - 1.9813994491068519e-10*_t773 + 1.717212855892605e-10*_t775 + 6.4845800152587881e-10*_t776 - 3.170239118570963e-9*_t782 + 4.1213108541422525e-9*_t784 + 2.0606554270711264e-8*_t789 - 2.3776793389282225e-9*_t790 + 3.0909831406066894e-9*_t792 - 1.4266076033569335e-8*_t796 + 3.0909831406066899e-8*_t798) - _t212*_t794 + _t212*_t805 + _t212*_t813 - _t212*_t816 + _t212*_t820 - _t212*_t824 - _t214*_t794 + _t214*_t805 + _t214*_t813 - _t214*_t816 + _t214*_t820 - _t214*_t824 - _t22*_t811 + _t23*_t734 + _t24*_t785 + _t24*_t786 + _t24*_t795 + _t25*_t734 + 2.1544152560763889e-8*_t26*_t742 + 9.9232886827256921e-8*_t26*_t751 + 3.9693154730902768e-7*_t26*_t752 + 2.9769866048177078e-7*_t26*_t761 + _t26*(-9.2043449435763882e-8*_t742 + 3.6817379774305543e-6*_t768 + 2.7613034830729157e-6*_t770 + 4.6021724717881934e-7*_t771 + 5.5226069661458323e-6*_t776) + _t26*(1.0726070244683159e-11*_hc2[0]*_hc2[4]*_t1*_t740 + 4.2904280978732629e-11*_hc2[1]*_hc2[3]*_t1*_t740 + 3.2178210734049471e-11*_t1*_t740*_t760 - 1.5016498342556423e-10*_t759 - 2.5027497237594037e-11*_t772 - 9.0098990055338536e-10*_t780 - 3.0032996685112845e-10*_t781 - 2.2524747513834634e-10*_t788) + _t26*(5.501259392632377e-12*_t742 - 6.1614105197482633e-10*_t768 + 2.7726347338867186e-9*_t769 - 4.6210578898111974e-10*_t770 - 7.7017631496853291e-11*_t771 + 1.1552644724527994e-10*_t773 - 9.2421157796223949e-10*_t776 + 1.848423155924479e-9*_t782 + 1.3863173669433593e-9*_t790 + 8.3179042016601561e-9*_t796) + _t26*(2.1348279360351563e-9*_hc2[0]*_hc2[2]*_t1*_t213*_t740 + 7.1160931201171877e-10*_hc2[1]*_hc2[3]*_t1*_t11*_t740 + 5.9300776000976564e-11*_hc2[4]*_t1*_t12*_t740 + 5.3370698400878908e-10*_t1*_t11*_t740*_t760 + 3.5580465600585939e-10*_t1*_t740*_t758 - 9.8834626668294269e-12*_t751 - 3.9533850667317707e-11*_t752 - 2.9650388000488282e-11*_t761 - 6.5230853601074216e-11*_t774 - 1.3046170720214846e-9*_t783 - 3.9138512160644539e-9*_t787 - 9.7846280401611347e-10*_t791 - 7.8277024321289077e-9*_t797) + _t26*(-2.193943278559931e-12*_t742 + 4.7389174816894529e-10*_t768 - 5.2128092298583983e-9*_t769 + 3.5541881112670899e-10*_t770 + 5.9236468521118161e-11*_t771 - 2.1720038457743325e-10*_t773 + 1.8824033330044215e-10*_t775 + 7.1083762225341798e-10*_t776 - 3.475206153238932e-9*_t782 + 4.5177679992106116e-9*_t784 + 2.2588839996053061e-8*_t789 - 2.6064046149291991e-9*_t790 + 3.3883259994079587e-9*_t792 - 1.5638427689575195e-8*_t796 + 3.3883259994079587e-8*_t798) + _t262*_t807 + _t268*_t808 + _t268*_t809 + _t27*_t823 + _t270*_t819 + _t272*_t822 + _t274*_t825 + _t275*_t807 + _t277*_t827 + _t278*_t830 + _t279*_t808 + _t279*_t809 + _t28*_t785 + _t28*_t786 + _t28*_t795 + _t280*_t819 + _t282*_t822 + _t283*_t807 + _t284*_t825 + _t285*_t827 + _t286*_t808 + _t286*_t809 + _t287*_t830 + _t289*_t819 + _t29*_t811 + _t290*_t822 + _t291*_t825 + _t292*_t807 + _t293*_t827 + _t294*_t830 + _t295*_t808 + _t295*_t809 + _t296*_t819 + _t297*_t822 + _t298*_t807 + _t299*_t825 + 1.4867981336805554e-8*_t30*_t742 - 1.9045194769965276e-8*_t30*_t751 - 7.6180779079861103e-8*_t30*_t752 - 5.7135584309895821e-8*_t30*_t761 + _t30*(-2.4325614854600692e-8*_t742 + 9.7302459418402755e-7*_t768 + 7.2976844563802055e-7*_t770 + 1.2162807427300344e-7*_t771 + 1.4595368912760411e-6*_t776) + _t30*(-2.8429344482421871e-12*_t751 - 1.1371737792968748e-11*_t752 + 3.9801082275390616e-11*_t759 - 8.5288033447265613e-12*_t761 + 6.6335137125651027e-12*_t772 + 2.3880649365234372e-10*_t780 + 7.9602164550781232e-11*_t781 + 5.9701623413085931e-11*_t788) + _t30*(1.430621046549479e-10*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t740 + 1.0729657849121093e-10*_hc2[0]*_t1*_t740*_t760 + 2.1459315698242186e-10*_hc2[2]*_t1*_t213*_t740 + 1.7882763081868488e-11*_hc2[4]*_t1*_t11*_t740 - 1.2773402201334634e-12*_t742 - 6.4377947094726567e-10*_t769 - 2.6824144622802735e-11*_t773 - 4.2918631396484376e-10*_t782 - 3.2188973547363283e-10*_t790 - 1.931338412841797e-9*_t796) + _t30*(5.6109614969889315e-12*_t751 + 2.2443845987955726e-11*_t752 - 2.0199461389160158e-10*_t759 + 1.6832884490966796e-11*_t761 - 3.3665768981933592e-11*_t772 + 3.7032345880126954e-11*_t774 - 1.2119676833496095e-9*_t780 - 4.0398922778320316e-10*_t781 + 7.4064691760253916e-10*_t783 + 2.2219407528076174e-9*_t787 - 3.0299192083740237e-10*_t788 + 5.5548518820190434e-10*_t791 + 4.4438815056152348e-9*_t797) + _t30*(3.1782068452148439e-9*_hc2[0]*_t1*_t740*_t758 + 2.1188045634765626e-9*_hc2[1]*_hc2[3]*_t1*_t12*_t740 + 9.5346205356445316e-9*_hc2[2]*_t1*_t11*_t213*_t740 + 1.3242528521728516e-10*_hc2[4]*_t1*_t13*_t740 + 1.337629143608941e-12*_hc2[4]*_t1*_t740 + 1.5891034226074219e-9*_t1*_t12*_t740*_t760 - 2.8892789501953127e-10*_t768 - 2.1669592126464845e-10*_t770 - 3.6115986877441409e-11*_t771 - 1.1476858052164714e-10*_t775 - 4.333918425292969e-10*_t776 - 2.7544459325195313e-9*_t784 - 1.377222966259766e-8*_t789 - 2.0658344493896485e-9*_t792 - 2.065834449389649e-8*_t798) + _t300*_t827 + _t301*_t808 + _t301*_t809 + _t302*_t830 + _t303*_t819 + _t304*_t822 + _t305*_t825 + _t306*_t827 + _t307*_t830 + _t31*_t828 - _t316*_t738 + _t32*_t734 + _t33*_t811 + _t34*_t785 + _t34*_t786 + _t34*_t795 + _t35*_t734 + _t36*_t823 - 9.2991297019675912e-10*_t37*_t742 + 3.6294499728732633e-13*_t37*_t751 + 1.4517799891493053e-12*_t37*_t752 + 1.088834991861979e-12*_t37*_t761 + _t37*(5.882719401041665e-13*_hc2[4]*_t1*_t740 - 2.3530877604166665e-11*_t768 - 1.7648158203124999e-11*_t770 - 2.9413597005208331e-12*_t771 - 3.5296316406249999e-11*_t776) + _t37*(-1.2372826483832463e-12*_t751 - 4.9491305935329851e-12*_t752 + 1.732195707736545e-11*_t759 - 3.711847945149739e-12*_t761 + 2.886992846227575e-12*_t772 + 1.039317424641927e-10*_t780 + 3.46439141547309e-11*_t781 + 2.5982935616048172e-11*_t788) + _t37*(5.2588181315104153e-11*_hc2[0]*_hc2[1]*_hc2[3]*_t1*_t740 + 3.9441135986328118e-11*_hc2[0]*_t1*_t740*_t760 + 7.8882271972656236e-11*_hc2[2]*_t1*_t213*_t740 + 6.5735226643880191e-12*_hc2[4]*_t1*_t11*_t740 - 4.6953733317057284e-13*_t742 - 2.3664681591796873e-10*_t769 - 9.8602839965820295e-12*_t773 - 1.5776454394531247e-10*_t782 - 1.1832340795898437e-10*_t790 - 7.099404477539062e-10*_t796) + _t37*(1.6484162692599823e-12*_t751 + 6.5936650770399293e-12*_t752 - 5.9342985693359368e-11*_t759 + 4.9452488077799474e-12*_t761 - 9.8904976155598947e-12*_t772 + 1.0879547377115885e-11*_t774 - 3.5605791416015621e-10*_t780 - 1.1868597138671874e-10*_t781 + 2.1759094754231768e-10*_t783 + 6.52772842626953e-10*_t787 - 8.9014478540039052e-11*_t788 + 1.6319321065673825e-10*_t791 + 1.305545685253906e-9*_t797) + _t37*(7.2772609953613286e-10*_hc2[0]*_t1*_t740*_t758 + 4.8515073302408843e-10*_hc2[1]*_hc2[3]*_t1*_t12*_t740 + 2.1831782986083987e-9*_hc2[2]*_t1*_t11*_t213*_t740 + 3.0321920814005527e-11*_hc2[4]*_t1*_t13*_t740 + 3.0628202842429831e-13*_hc2[4]*_t1*_t740 + 3.6386304976806638e-10*_t1*_t12*_t740*_t760 - 6.615691813964843e-11*_t768 - 4.9617688604736316e-11*_t770 - 8.2696147674560537e-12*_t771 - 2.6278998038804796e-11*_t775 - 9.9235377209472632e-11*_t776 - 6.3069595293131515e-10*_t784 - 3.153479764656576e-9*_t789 - 4.7302196469848631e-10*_t792 - 4.7302196469848635e-9*_t798) - _t38*_t832 + _t39*_t785 + _t39*_t786 + _t39*_t795 + _t4*_t734 + _t40*_t811 + 0.00017420001388888888*_t405*_t85 - 4.578597770833333e-5*_t405*_t86 + 0.016723201333333333*_t407*_t92 - 0.021732173*_t407*_t94 - 0.00022637680208333332*_t409*_t85 - 0.00023453693125*_t409*_t86 + _t41*_t828 - _t410*_t448 - _t410*_t450 + _t410*_t468 - _t410*_t482 + _t410*_t485 - _t410*_t492 - 0.0043954538599999997*_t411*_t92 - 0.0225155454*_t411*_t94 - 0.01318636158*_t412*_t92 - 0.067546636199999996*_t412*_t94 + _t42*_t823 - 1.7005779134114583e-10*_t43*_t742 - 1.2099319498697916e-13*_t43*_t751 - 4.8397277994791664e-13*_t43*_t752 - 3.629795849609375e-13*_t43*_t761 + _t43*(-1.8308108696831594e-13*_t742 + 7.323243478732639e-12*_t768 + 5.4924326090494792e-12*_t770 + 9.1540543484157987e-13*_t771 + 1.0984865218098958e-11*_t776) + _t43*(6.6979216172960056e-13*_hc2[0]*_hc2[4]*_t1*_t740 + 2.6791686469184023e-12*_hc2[1]*_hc2[3]*_t1*_t740 + 2.0093764851888017e-12*_t1*_t740*_t760 - 9.3770902642144103e-12*_t759 - 1.5628483773690683e-12*_t772 - 5.6262541585286462e-11*_t780 - 1.8754180528428821e-11*_t781 - 1.4065635396321615e-11*_t788) + _t43*(2.8831393500434021e-13*_t742 - 3.2291160720486104e-11*_t768 + 1.4531022324218749e-10*_t769 - 2.421837054036458e-11*_t770 - 4.036395090060763e-12*_t771 + 6.0545926350911449e-12*_t773 - 4.8436741080729159e-11*_t776 + 9.6873482161458318e-11*_t782 + 7.2655111621093745e-11*_t790 + 4.3593066972656247e-10*_t796) + _t43*(3.5457647080078122e-10*_hc2[0]*_hc2[2]*_t1*_t213*_t740 + 1.1819215693359374e-10*_hc2[1]*_hc2[3]*_t1*_t11*_t740 + 9.8493464111328116e-12*_hc2[4]*_t1*_t12*_t740 + 8.8644117700195304e-11*_t1*_t11*_t740*_t760 + 5.909607846679687e-11*_t1*_t740*_t758 - 1.6415577351888019e-12*_t751 - 6.5662309407552075e-12*_t752 - 4.9246732055664058e-12*_t761 - 1.0834281052246092e-11*_t774 - 2.1668562104492185e-10*_t783 - 6.5005686313476564e-10*_t787 - 1.6251421578369138e-10*_t791 - 1.3001137262695311e-9*_t797) + _t43*(-3.5149913019250938e-13*_t742 + 7.5923812121582016e-11*_t768 - 8.3516193333740241e-10*_t769 + 5.6942859091186518e-11*_t770 + 9.490476515197752e-12*_t771 - 3.4798413889058434e-11*_t773 + 3.0158625370517309e-11*_t775 + 1.1388571818237304e-10*_t776 - 5.5677462222493494e-10*_t782 + 7.2380700889241532e-10*_t784 + 3.6190350444620771e-9*_t789 - 4.175809666687012e-10*_t790 + 5.4285525666931146e-10*_t792 - 2.5054858000122072e-9*_t796 + 5.4285525666931159e-9*_t798) - _t44*_t833 + _t45*_t811 + _t46*_t785 + _t46*_t786 + _t46*_t795 + _t47*_t828 + _t48*_t823 + _t487*_t804 - 0.00050557856833333332*_t489*_t92 + 0.0014662652050000001*_t489*_t94 + _t49*_t832 + _t496*_t806 + _t497*_t810 + _t498*_t804 + _t499*_t812 + _t50*_t785 + _t50*_t786 + _t50*_t795 + _t501*_t814 + 0.00019855091*_t502*_t92 + 0.00091453028500000004*_t502*_t94 + _t507*_t815 + _t508*_t806 + _t509*_t818 + _t51*_t811 + _t510*_t810 + _t511*_t812 + _t516*_t814 + _t517*_t815 + _t519*_t804 + _t52*_t823 + _t521*_t818 + 0.00013702331599999999*_t522*_t92 - 0.000175520515*_t522*_t94 + _t525*_t806 + _t527*_t810 + _t528*_t804 + _t529*_t812 + _t53*_t828 + _t530*_t814 - 8.5700779333333327e-6*_t533*_t92 + 3.3449010949999995e-9*_t533*_t94 + _t534*_t815 + _t535*_t806 + _t536*_t818 + _t537*_t810 + _t539*_t812 + _t54*_t833 + _t540*_t814 + _t541*_t815 + _t543*_t804 + _t544*_t818 - 1.5672526050000001e-6*_t545*_t92 - 1.115073285e-9*_t545*_t94 + _t546*_t806 + _t547*_t810 + _t548*_t812 + _t549*_t814 + _t55*_t832 + _t550*_t815 + _t551*_t818 + _t56*_t811 - _t562*_t736 + _t57*_t828 + _t58*_t833 + _t59*_t823 + _t60*_t832 + _t61*_t823 + _t62*_t828 + _t63*_t833 + _t64*_t832 + _t65*_t828 + _t66*_t833 + _t67*_t832 + _t68*_t832 + _t69*_t833 + _t70*_t833 - _t73*_t735 - 0.0043736526393718745*_t734 + 0.01406365375513125*_t735 + 0.056254615020524999*_t736 + 0.072497176075275005*_t737 + 0.042190961265393748*_t738 + 0.11150646772432501*_t739 - 2.8260000772546832e-6*_t742 - 0.11350597242757501*_t743 + 0.083629850793243754*_t744 + 0.013938308465540627*_t745 + 0.012082862679212502*_t746 - 0.0047294155178156253*_t747 - 0.00048005288013375008*_t748 + 0.00013814974360687498*_t749 + 0.16725970158648751*_t750 - 3.3382094302707238e-6*_t751 - 1.3352837721082895e-5*_t752 + 0.43498305645165003*_t753 + 0.14499435215055001*_t754 - 0.075670648285050005*_t755 - 0.0096010576026750016*_t756 + 0.0033155938465649995*_t757 - 5.992021874050563e-5*_t759 - 1.0014628290812171e-5*_t761 - 0.028803172808025003*_t762 + 0.10874576411291251*_t763 + 0.016577969232824997*_t764 - 0.056752986213787507*_t765 - 0.0072007932020062507*_t766 + 0.0024866953849237497*_t767 + 0.00021612180486518009*_t768 - 0.00085733767271728521*_t769 + 0.00016209135364888508*_t770 + 2.7015225608147511e-5*_t771 - 9.9867031234176051e-6*_t772 - 3.5722403029886884e-5*_t773 + 8.6832313946533177e-6*_t774 + 1.34219601534356e-5*_t775 + 0.00032418270729777016*_t776 - 0.34051791728272507*_t777 - 0.057606345616050006*_t778 + 0.024866953849237497*_t779 - 0.00035952131244303381*_t780 - 0.00011984043748101126*_t781 - 0.00057155844847819014*_t782 + 0.00017366462789306639*_t783 + 0.00032212704368245442*_t784 + 0.00052099388367919924*_t787 - 8.9880328110758439e-5*_t788 + 0.0016106352184122722*_t789 - 0.0004286688363586426*_t790 + 0.00013024847091979981*_t791 + 0.00024159528276184082*_t792 - 0.0025720130181518556*_t796 + 0.0010419877673583985*_t797 + 0.0024159528276184086*_t798;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeef_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

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
  if(!(_t7)) XC_CAT(mbeef_f_pf_k, _KMAX)(p, _t5*sigma_ss, 0, _t6*tau_s, _hc1);
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