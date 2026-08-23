/*
  Generated from python/mgga_exc/mgga_x_mbeefvdw.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_mbeefvdw
*/

#ifndef _MGGA_X_MBEEFVDW_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_MBEEFVDW_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_MBEEFVDW_HELPER_BODIES
#include "mgga_x_mbeefvdw.c"
#undef _MGGA_X_MBEEFVDW_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_MBEEFVDW_HELPER_BODIES
#include "mgga_x_mbeefvdw.c"
#undef _MGGA_X_MBEEFVDW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_MBEEFVDW_HELPER_BODIES
#include "mgga_x_mbeefvdw.c"
#undef _MGGA_X_MBEEFVDW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_MBEEFVDW_HELPER_BODIES
#include "mgga_x_mbeefvdw.c"
#undef _MGGA_X_MBEEFVDW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_MBEEFVDW_HELPER_BODIES
#include "mgga_x_mbeefvdw.c"
#undef _MGGA_X_MBEEFVDW_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_mbeefvdw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_MBEEFVDW_HELPER_BODIES)

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
  const double _t12 = (0.3e1 / 0.2e1)*_t5 - 0.1e1 / 0.2e1;
  const double _t15 = -0.3e1 / 0.2e1*_hc1[0] + (0.5e1 / 0.2e1)*_t6;
  const double _t19 = -0.15e2 / 0.4e1*_t5 + (0.35e2 / 0.8e1)*_t7 + 0.3e1 / 0.8e1;
#if _KMAX >= 1
  const double _t29 = _hc0[1]*_hc1[1];
  const double _t30 = 0.043536371955*_hc1[0];
  const double _t32 = _hc1[0]*_t29;
  const double _t33 = 0.010559560650000001*_t5;
  const double _t34 = _t29*_t6;
  const double _t36 = 0.3e1*_t32;
  const double _t37 = (0.15e2 / 0.2e1)*_t29;
  const double _t38 = -0.3e1 / 0.2e1*_t29 + _t37*_t5;
  const double _t39 = -_hc1[0]*_t37 + (0.35e2 / 0.2e1)*_t34;
  const double _t40 = _hc0[2]*_hc1[1];
  const double _t42 = _t40*_t6;
  const double _t47 = 0.3e1*_t40;
  const double _t48 = _hc1[0]*_t47;
  const double _t51 = (0.15e2 / 0.2e1)*_t40;
  const double _t52 = -0.3e1 / 0.2e1*_t40 + _t5*_t51;
  const double _t53 = -_hc1[0]*_t51 + (0.35e2 / 0.2e1)*_t42;
#endif
#if _KMAX >= 2
  const double _t66 = ((_hc0[1]) * (_hc0[1]));
  const double _t67 = _hc1[2]*_t66;
  const double _t68 = ((_hc1[1]) * (_hc1[1]));
  const double _t69 = _t66*_t68;
  const double _t70 = _hc1[0]*_t69;
  const double _t71 = _t6*_t67;
  const double _t72 = _t5*_t69;
  const double _t73 = _hc1[0]*_t67;
  const double _t74 = 0.3e1*_t69;
  const double _t75 = 0.3e1*_t73;
  const double _t76 = (0.15e2 / 0.2e1)*_t67;
  const double _t77 = _t5*_t76 - 0.3e1 / 0.2e1*_t67 + 0.15e2*_t70;
  const double _t78 = -_hc1[0]*_t76 - 0.15e2 / 0.2e1*_t69 + (0.35e2 / 0.2e1)*_t71 + (0.105e3 / 0.2e1)*_t72;
  const double _t79 = _hc0[1]*_hc0[2];
  const double _t80 = _hc1[2]*_t79;
  const double _t81 = _t68*_t79;
  const double _t82 = _hc1[0]*_t81;
  const double _t83 = _t6*_t80;
  const double _t84 = _t5*_t81;
  const double _t88 = 0.3e1*_t80;
  const double _t89 = _hc1[0]*_t88;
  const double _t90 = 0.3e1*_t81;
  const double _t91 = (0.15e2 / 0.2e1)*_t80;
  const double _t92 = _t5*_t91 - 0.3e1 / 0.2e1*_t80 + 0.15e2*_t82;
  const double _t93 = -_hc1[0]*_t91 - 0.15e2 / 0.2e1*_t81 + (0.35e2 / 0.2e1)*_t83 + (0.105e3 / 0.2e1)*_t84;
  const double _t94 = ((_hc0[2]) * (_hc0[2]));
  const double _t95 = _hc1[2]*_t94;
  const double _t96 = _t68*_t94;
  const double _t97 = xc_powr(0.6e1, 2, 3);
  const double _t98 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t99 = _t97*_t98;
  const double _t101 = _hc1[0]*_t96;
  const double _t102 = _t6*_t95;
  const double _t107 = _t5*_t96;
  const double _t109 = 0.00011596361406249999*_hc1[0];
  const double _t113 = _hc1[0]*_t40;
  const double _t117 = 0.3e1*_t95;
  const double _t118 = _hc1[0]*_t117;
  const double _t120 = 0.3e1*_t96;
  const double _t131 = 0.2e1*_t40;
  const double _t134 = (0.15e2 / 0.2e1)*_t95;
  const double _t135 = 0.15e2*_t101 + _t134*_t5 - 0.3e1 / 0.2e1*_t95;
  const double _t137 = 0.2e1*_t52;
  const double _t138 = 0.2e1*_t53;
  const double _t139 = -_hc1[0]*_t134 + (0.35e2 / 0.2e1)*_t102 + (0.105e3 / 0.2e1)*_t107 - 0.15e2 / 0.2e1*_t96;
#endif
#if _KMAX >= 3
  const double _t147 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t148 = _hc1[3]*_t147;
  const double _t149 = _hc1[1]*_hc1[2];
  const double _t150 = 0.13060911586500001*_t149;
  const double _t151 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t152 = _t147*_t151;
  const double _t153 = _t147*_t149;
  const double _t154 = 0.063357363900000005*_hc1[0];
  const double _t156 = _hc1[0]*_t152;
  const double _t157 = _t148*_t6;
  const double _t158 = _t153*_t5;
  const double _t159 = _hc1[0]*_t148;
  const double _t160 = 0.9e1*_t153;
  const double _t161 = 0.3e1*_t159;
  const double _t162 = 0.45e2*_hc1[0];
  const double _t163 = (0.15e2 / 0.2e1)*_t148;
  const double _t164 = -0.3e1 / 0.2e1*_t148 + 0.15e2*_t152 + _t153*_t162 + _t163*_t5;
  const double _t165 = (0.45e2 / 0.2e1)*_t147;
  const double _t166 = -_hc1[0]*_t163 - _t149*_t165 + 0.105e3*_t156 + (0.35e2 / 0.2e1)*_t157 + (0.315e3 / 0.2e1)*_t158;
  const double _t167 = _hc0[2]*_t66;
  const double _t168 = _hc1[3]*_t167;
  const double _t169 = _t40*_t67;
  const double _t170 = 0.021119121300000002*_t151;
  const double _t171 = _t40*_t73;
  const double _t172 = _hc1[0]*_t151;
  const double _t173 = _t167*_t172;
  const double _t174 = _t168*_t6;
  const double _t175 = _t169*_t5;
  const double _t176 = 0.9e1*_t169;
  const double _t178 = 0.3e1*_t168;
  const double _t180 = 0.15e2*_t151;
  const double _t181 = (0.15e2 / 0.2e1)*_t168;
  const double _t182 = _t167*_t180 - 0.3e1 / 0.2e1*_t168 + 0.45e2*_t171 + _t181*_t5;
  const double _t183 = -_hc1[0]*_t181 - 0.45e2 / 0.2e1*_t169 + 0.105e3*_t173 + (0.35e2 / 0.2e1)*_t174 + (0.315e3 / 0.2e1)*_t175;
  const double _t184 = _hc0[1]*_t94;
  const double _t185 = _hc1[3]*_t184;
  const double _t186 = _t29*_t95;
  const double _t187 = _t32*_t95;
  const double _t188 = _t172*_t184;
  const double _t189 = _t185*_t6;
  const double _t190 = _t186*_t5;
  const double _t194 = _hc1[0]*_t80;
  const double _t197 = 0.9e1*_t186;
  const double _t198 = 0.3e1*_t185;
  const double _t199 = 0.2e1*_t80;
  const double _t200 = (0.15e2 / 0.2e1)*_t185;
  const double _t201 = _t180*_t184 - 0.3e1 / 0.2e1*_t185 + 0.45e2*_t187 + _t200*_t5;
  const double _t202 = 0.2e1*_t92;
  const double _t203 = -_hc1[0]*_t200 - 0.45e2 / 0.2e1*_t186 + 0.105e3*_t188 + (0.35e2 / 0.2e1)*_t189 + (0.315e3 / 0.2e1)*_t190;
  const double _t204 = 0.2e1*_t93;
  const double _t205 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t207 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t208 = _hc1[3]*_t207;
  const double _t213 = _t151*_t207;
  const double _t217 = _t149*_t207;
  const double _t221 = _hc1[0]*_t213;
  const double _t222 = _t208*_t6;
  const double _t224 = _t217*_t5;
  const double _t227 = 0.00034789084218749997*_t40;
  const double _t229 = 0.00024460222453125*_t113;
  const double _t230 = _hc1[0]*_t208;
  const double _t231 = 0.9e1*_t217;
  const double _t232 = _hc1[0]*_t95;
  const double _t238 = 0.3e1*_t230;
  const double _t246 = 1.0280457093749997e-8*_t52;
  const double _t248 = 3.1546209218749996e-9*_t53;
  const double _t250 = 0.9e1*_t232;
  const double _t251 = 0.9e1*_t96;
  const double _t254 = (0.15e2 / 0.2e1)*_t208;
  const double _t255 = _t162*_t217 - 0.3e1 / 0.2e1*_t208 + 0.15e2*_t213 + _t254*_t5;
  const double _t257 = 0.9e1*_t113;
  const double _t263 = (0.45e2 / 0.2e1)*_t207;
  const double _t264 = -_hc1[0]*_t254 - _t149*_t263 + 0.105e3*_t221 + (0.35e2 / 0.2e1)*_t222 + (0.315e3 / 0.2e1)*_t224;
  const double _t266 = 0.3e1*_t52;
  const double _t267 = 0.3e1*_t53;
  const double _t268 = 0.3e1*_t135;
  const double _t272 = 0.3e1*_t139;
#endif
#if _KMAX >= 4
  const double _t273 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t274 = _hc1[4]*_t273;
  const double _t275 = _hc1[1]*_hc1[3];
  const double _t276 = _t273*_t275;
  const double _t277 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t278 = _t273*_t277;
  const double _t279 = ((_hc1[2]) * (_hc1[2]));
  const double _t280 = _t273*_t279;
  const double _t281 = _hc1[0]*_t276;
  const double _t283 = _hc1[0]*_t280;
  const double _t284 = _t274*_t6;
  const double _t285 = _hc1[2]*_t68;
  const double _t286 = _t273*_t285;
  const double _t287 = _hc1[0]*_t286;
  const double _t288 = _t276*_t5;
  const double _t289 = _t280*_t5;
  const double _t290 = _hc1[0]*_t274;
  const double _t291 = 0.12e2*_t276;
  const double _t292 = 0.9e1*_t280;
  const double _t293 = 0.3e1*_t290;
  const double _t294 = (0.15e2 / 0.2e1)*_t274;
  const double _t295 = -0.3e1 / 0.2e1*_t274 + 0.60e2*_t281 + 0.45e2*_t283 + 0.90e2*_t286 + _t294*_t5;
  const double _t296 = -_hc1[0]*_t294 - 0.30e2*_t276 + 0.105e3*_t278 - 0.45e2 / 0.2e1*_t280 + (0.35e2 / 0.2e1)*_t284 + 0.630e3*_t287 + 0.210e3*_t288 + (0.315e3 / 0.2e1)*_t289;
  const double _t297 = _hc0[2]*_t147;
  const double _t298 = _hc1[4]*_t297;
  const double _t299 = _t148*_t40;
  const double _t300 = _t277*_t297;
  const double _t301 = 0.13060911586500001*_t279;
  const double _t302 = _t113*_t148;
  const double _t303 = _t279*_t297;
  const double _t304 = _t298*_t6;
  const double _t305 = _t285*_t297;
  const double _t306 = _hc1[0]*_t305;
  const double _t307 = _t299*_t5;
  const double _t308 = _t303*_t5;
  const double _t309 = 0.12e2*_t299;
  const double _t310 = 0.9e1*_t303;
  const double _t311 = 0.3e1*_t298;
  const double _t312 = (0.3e1 / 0.2e1)*_hc1[4];
  const double _t313 = (0.15e2 / 0.2e1)*_t298;
  const double _t314 = _t162*_t303 - _t297*_t312 + 0.60e2*_t302 + 0.90e2*_t305 + _t313*_t5;
  const double _t315 = -_hc0[2]*_t165*_t279 - _hc1[0]*_t313 - 0.30e2*_t299 + 0.105e3*_t300 + (0.35e2 / 0.2e1)*_t304 + 0.630e3*_t306 + 0.210e3*_t307 + (0.315e3 / 0.2e1)*_t308;
  const double _t316 = _t66*_t94;
  const double _t317 = _hc1[4]*_t316;
  const double _t318 = _t275*_t316;
  const double _t319 = _t277*_t316;
  const double _t320 = _hc1[0]*_t318;
  const double _t321 = _t279*_t316;
  const double _t322 = _t317*_t6;
  const double _t323 = _t67*_t96;
  const double _t324 = _t101*_t67;
  const double _t325 = _t318*_t5;
  const double _t326 = _t321*_t5;
  const double _t327 = _hc1[0]*_t168;
  const double _t328 = 0.12e2*_t318;
  const double _t329 = 0.9e1*_t321;
  const double _t330 = 0.3e1*_t317;
  const double _t331 = 0.2e1*_t168;
  const double _t332 = 0.18e2*_t169;
  const double _t333 = 0.2e1*_t182;
  const double _t334 = (0.15e2 / 0.2e1)*_t317;
  const double _t335 = _t162*_t321 - _t312*_t316 + 0.60e2*_t320 + 0.90e2*_t323 + _t334*_t5;
  const double _t336 = 0.2e1*_t183;
  const double _t337 = -_hc1[0]*_t334 - 0.30e2*_t318 + 0.105e3*_t319 - 0.45e2 / 0.2e1*_t321 + (0.35e2 / 0.2e1)*_t322 + 0.630e3*_t324 + 0.210e3*_t325 + (0.315e3 / 0.2e1)*_t326;
  const double _t338 = _hc0[1]*_t207;
  const double _t339 = _hc1[4]*_t338;
  const double _t340 = _t208*_t29;
  const double _t341 = _t277*_t338;
  const double _t342 = _t208*_t32;
  const double _t343 = _t279*_t338;
  const double _t344 = _t339*_t6;
  const double _t345 = _t285*_t338;
  const double _t346 = _hc1[0]*_t345;
  const double _t347 = _t340*_t5;
  const double _t348 = _t343*_t5;
  const double _t349 = 0.00034789084218749997*_t80;
  const double _t351 = 0.12e2*_t340;
  const double _t352 = _hc1[0]*_t185;
  const double _t353 = 0.9e1*_t343;
  const double _t354 = 0.3e1*_t339;
  const double _t355 = 0.9e1*_t352;
  const double _t356 = 0.27e2*_t186;
  const double _t357 = 0.9e1*_t194;
  const double _t358 = 0.9e1*_t81;
  const double _t359 = (0.15e2 / 0.2e1)*_t339;
  const double _t360 = _t162*_t343 - _t312*_t338 + 0.60e2*_t342 + 0.90e2*_t345 + _t359*_t5;
  const double _t361 = 0.3e1*_t92;
  const double _t362 = 0.3e1*_t201;
  const double _t363 = 0.3e1*_t93;
  const double _t364 = 0.3e1*_t203;
  const double _t365 = -_hc0[1]*_t263*_t279 - _hc1[0]*_t359 - 0.30e2*_t340 + 0.105e3*_t341 + (0.35e2 / 0.2e1)*_t344 + 0.630e3*_t346 + 0.210e3*_t347 + (0.315e3 / 0.2e1)*_t348;
  const double _t366 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t367 = _hc1[4]*_t366;
  const double _t368 = _t275*_t366;
  const double _t369 = _t277*_t366;
  const double _t370 = _t279*_t366;
  const double _t371 = _hc1[0]*_t368;
  const double _t372 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t373 = _t1*_t372;
  const double _t375 = _hc1[0]*_t370;
  const double _t376 = _t367*_t6;
  const double _t377 = _t285*_t366;
  const double _t380 = _hc1[0]*_t377;
  const double _t381 = _t368*_t5;
  const double _t385 = _t370*_t5;
  const double _t393 = _hc1[0]*_t367;
  const double _t394 = 0.12e2*_t368;
  const double _t397 = 0.00069578168437499995*_t95;
  const double _t398 = 0.9e1*_t370;
  const double _t400 = 0.3e1*_t393;
  const double _t402 = 0.4e1*_t208;
  const double _t403 = 0.12e2*_t230;
  const double _t404 = 0.36e2*_t217;
  const double _t405 = 0.4e1*_t40;
  const double _t406 = 2.0560914187499994e-8*_t135;
  const double _t407 = 0.12e2*_t113;
  const double _t408 = 0.6e1*_t95;
  const double _t409 = 0.18e2*_t232;
  const double _t410 = 0.18e2*_t96;
  const double _t411 = 0.4e1*_t52;
  const double _t412 = (0.15e2 / 0.2e1)*_t367;
  const double _t413 = -0.3e1 / 0.2e1*_t367 + 0.60e2*_t371 + 0.45e2*_t375 + 0.90e2*_t377 + _t412*_t5;
  const double _t414 = 0.4e1*_t53;
  const double _t415 = 6.3092418437499993e-9*_t139;
  const double _t416 = 0.4e1*_t255;
  const double _t417 = 0.6e1*_t135;
  const double _t418 = 0.4e1*_t264;
  const double _t419 = 0.6e1*_t139;
  const double _t420 = -_hc1[0]*_t412 - 0.30e2*_t368 + 0.105e3*_t369 - 0.45e2 / 0.2e1*_t370 + (0.35e2 / 0.2e1)*_t376 + 0.630e3*_t380 + 0.210e3*_t381 + (0.315e3 / 0.2e1)*_t385;
#endif
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(mbeef_xi_k, _KMAX)(p, (0.1e1 / 0.24e2)*_t3*x2, _hc2);
  const double _t4 = 0.045383724600000001*_hc2[0];
  const double _t8 = ((_hc2[0]) * (_hc2[0]));
  const double _t9 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t10 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t11 = 0.011132506949999999 - 0.033397520850000001*_t8;
  const double _t13 = _hc2[0]*_t12;
  const double _t14 = -0.028856183099999998*_hc2[0] + 0.048093638499999994*_t9;
  const double _t16 = 0.0060833826400000001*_hc2[0];
  const double _t17 = 4.0220120237500001e-6*_t10 - 3.4474388774999999e-6*_t8 + 3.4474388775e-7;
  const double _t18 = 0.0026090903949999998 - 0.0078272711849999999*_t8;
  const double _t20 = 1.00478906e-7*_hc2[0];
  const double _t21 = 3.2897462700000002e-7 - 9.8692388099999994e-7*_t8;
  const double _t22 = -2.005611045e-7*_hc2[0] + 3.3426850749999997e-7*_t9;
  const double _t23 = 8.2486411950000003e-8*_hc2[0] - 1.3747735324999999e-7*_t9;
  const double _t24 = -2.1907783974999999e-6*_t10 + 1.877810055e-6*_t8 - 1.877810055e-7;
  const double _t25 = 3.0284360849999999e-7*_t8 - 1.009478695e-7;
  const double _t26 = 2.5126407643749999e-7*_t10 - 2.15369208375e-7*_t8 + 2.1536920837499999e-8;
  const double _t27 = -5.9598715200000002e-9*_hc2[0] + 9.9331192000000003e-9*_t9;
  const double _t28 = -1.4906598787500001e-8*_t10 + 1.2777084675000001e-8*_t8 - 1.2777084675e-9;
#if _KMAX >= 1
  const double _t31 = 0.095407228799999994*_hc2[0];
  const double _t35 = 0.3e1*_t18;
  const double _t41 = _hc1[0]*_t31;
  const double _t43 = _hc2[1]*_t3;
  const double _t44 = 0.001890988525*_t43;
  const double _t45 = _hc2[0]*_t43;
  const double _t46 = 0.0027831267374999998*_t45;
  const double _t49 = _t43*_t8;
  const double _t50 = _t43*_t9;
  const double _t54 = 0.00025347427666666663*_t43;
  const double _t55 = 8.2243656749999991e-8*_t45;
  const double _t56 = 4.1866210833333327e-9*_t43;
  const double _t57 = 2.5236967374999997e-8*_t45;
  const double _t58 = -0.0012023409624999999*_t43 + 0.0060117048124999992*_t49;
  const double _t59 = -2.8728657312499997e-7*_t45 + 6.7033533729166662e-7*_t50;
  const double _t60 = -8.3567126875e-9*_t43 + 4.1783563437499997e-8*_t49;
  const double _t61 = 1.5648417125e-7*_hc2[0]*_hc2[1]*_t1*_t2 - 3.6512973291666665e-7*_t50;
  const double _t62 = 3.4369338312500001e-9*_hc2[1]*_t1*_t2 - 1.7184669156249999e-8*_t49;
  const double _t63 = -1.7947434031249998e-8*_t45 + 4.1877346072916662e-8*_t50;
  const double _t64 = -2.4832798000000001e-10*_t43 + 1.2416399e-9*_t49;
  const double _t65 = 1.0647570562499999e-9*_hc2[0]*_hc2[1]*_t1*_t2 - 2.4844331312500001e-9*_t50;
#endif
#if _KMAX >= 2
  const double _t85 = 0.0039753011999999997*_t43;
  const double _t86 = _hc1[0]*_t35;
  const double _t87 = 0.00195681779625*_t45;
  const double _t100 = _hc2[2]*_t99;
  const double _t103 = 7.8791188541666666e-5*_t100;
  const double _t104 = _hc2[0]*_t100;
  const double _t105 = ((_hc2[1]) * (_hc2[1]));
  const double _t106 = _t105*_t99;
  const double _t108 = 0.00378197705*_t43;
  const double _t110 = _hc2[0]*_t106;
  const double _t111 = _t100*_t8;
  const double _t112 = _t100*_t9;
  const double _t114 = 0.0079506023999999995*_t43;
  const double _t115 = 0.0055662534749999996*_t45;
  const double _t116 = 0.0039136355925*_t45;
  const double _t119 = _t106*_t8;
  const double _t121 = 1.0561428194444443e-5*_t100;
  const double _t122 = 3.4268190312499993e-9*_t104;
  const double _t123 = 3.4268190312499993e-9*_t106;
  const double _t124 = 0.00050694855333333327*_t43;
  const double _t125 = 1.7444254513888886e-10*_t100;
  const double _t126 = 8.3732421666666655e-9*_t43;
  const double _t127 = 1.6448731349999998e-7*_t45;
  const double _t128 = 1.0515403072916665e-9*_t104;
  const double _t129 = 1.0515403072916665e-9*_t106;
  const double _t130 = 5.0473934749999994e-8*_t45;
  const double _t132 = 0.6e1*_t60;
  const double _t133 = 0.6e1*_t61;
  const double _t136 = -5.0097540104166664e-5*_t100 + 0.00050097540104166653*_t110 + 0.00025048770052083327*_t111;
  const double _t140 = -3.4819636197916663e-10*_t100 + 3.4819636197916661e-9*_t110 + 1.7409818098958331e-9*_t111;
  const double _t141 = 1.4320557630208333e-10*_hc2[2]*_t97*_t98 - 1.4320557630208332e-9*_t110 - 7.1602788151041662e-10*_t111;
  const double _t142 = -1.0346999166666666e-11*_t100 + 1.0346999166666666e-10*_t110 + 5.1734995833333331e-11*_t111;
  const double _t143 = -1.1970273880208331e-8*_t104 - 1.1970273880208331e-8*_t106 + 2.7930639053819442e-8*_t112 + 8.3791917161458327e-8*_t119;
  const double _t144 = 6.5201738020833328e-9*_hc2[0]*_hc2[2]*_t97*_t98 + 6.5201738020833328e-9*_t105*_t97*_t98 - 1.5213738871527776e-8*_t112 - 4.5641216614583331e-8*_t119;
  const double _t145 = -7.4780975130208325e-10*_t104 - 7.4780975130208325e-10*_t106 + 1.7448894197048608e-9*_t112 + 5.2346682591145828e-9*_t119;
  const double _t146 = 4.4364877343749993e-11*_hc2[0]*_hc2[2]*_t97*_t98 + 4.4364877343749993e-11*_t105*_t97*_t98 - 1.0351804713541666e-10*_t112 - 3.1055414140625002e-10*_t119;
#endif
#if _KMAX >= 3
  const double _t155 = 0.28622168640000001*_hc2[0];
  const double _t177 = _hc1[0]*_t22;
  const double _t179 = _hc1[0]*_t24;
  const double _t191 = 0.00016563754999999997*_t100;
  const double _t192 = 0.00011596361406249999*_t104;
  const double _t193 = 0.00011596361406249999*_t106;
  const double _t195 = 8.1534074843749995e-5*_t104;
  const double _t196 = 8.1534074843749995e-5*_t106;
  const double _t206 = _hc2[3]*_t205;
  const double _t209 = 1.9697797135416667e-5*_t206;
  const double _t210 = _hc2[0]*_t206;
  const double _t211 = _hc2[1]*_hc2[2]*_t205;
  const double _t212 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t205;
  const double _t214 = 2.8990903515624997e-5*_t210;
  const double _t215 = 8.6972710546874993e-5*_t211;
  const double _t216 = _hc2[0]*_t211;
  const double _t218 = _hc2[0]*_t212;
  const double _t219 = _t206*_t8;
  const double _t220 = _t206*_t9;
  const double _t223 = _t211*_t8;
  const double _t225 = 0.000236373565625*_t100;
  const double _t226 = 0.00049691264999999997*_t100;
  const double _t228 = 0.0056729655750000002*_t43;
  const double _t233 = 0.011925903599999999*_t43;
  const double _t234 = 0.0083493802125000002*_t45;
  const double _t235 = 0.00024460222453125*_t106;
  const double _t236 = 2.6403570486111108e-6*_t206;
  const double _t237 = 0.0058704533887500004*_t45;
  const double _t239 = 8.5670475781249984e-10*_t210;
  const double _t240 = 2.5701142734374993e-9*_t211;
  const double _t241 = 4.3610636284722214e-11*_t206;
  const double _t242 = 2.6288507682291664e-10*_t210;
  const double _t243 = 7.8865523046874991e-10*_t211;
  const double _t244 = 3.1684284583333329e-5*_t100;
  const double _t245 = 5.2332763541666659e-10*_t100;
  const double _t247 = 1.0280457093749997e-8*_t106;
  const double _t249 = 3.1546209218749996e-9*_t106;
  const double _t252 = -1.2524385026041666e-5*_t206 + 0.00012524385026041663*_t212 + 0.0003757315507812499*_t216 + 6.2621925130208316e-5*_t219;
  const double _t253 = 0.0007604228299999999*_t43;
  const double _t256 = 2.4673097024999999e-7*_t45;
  const double _t258 = -8.7049090494791658e-11*_t206 + 8.7049090494791653e-10*_t212 + 2.6114727148437498e-9*_t216 + 4.3524545247395827e-10*_t219;
  const double _t259 = 3.5801394075520826e-11*_hc2[3]*_t205 - 3.5801394075520831e-10*_t212 - 1.0740418222656249e-9*_t216 - 1.7900697037760416e-10*_t219;
  const double _t260 = -2.9925684700520827e-9*_t210 - 8.9777054101562474e-9*_t211 + 4.1895958580729163e-8*_t218 + 6.9826597634548606e-9*_t220 + 6.2843937871093752e-8*_t223;
  const double _t261 = -2.5867497916666662e-12*_t206 + 2.5867497916666665e-11*_t212 + 7.7602493749999989e-11*_t216 + 1.2933748958333333e-11*_t219;
  const double _t262 = 1.2559863249999998e-8*_t43;
  const double _t265 = 7.5710902124999985e-8*_t45;
  const double _t269 = 1.6300434505208332e-9*_hc2[0]*_hc2[3]*_t205 + 4.8901303515625e-9*_hc2[1]*_hc2[2]*_t205 - 2.2820608307291665e-8*_t218 - 3.803434717881944e-9*_t220 - 3.4230912460937498e-8*_t223;
  const double _t270 = -1.8695243782552079e-10*_t210 - 5.6085731347656233e-10*_t211 + 2.617334129557291e-9*_t218 + 4.3622235492621519e-10*_t220 + 3.9260011943359364e-9*_t223;
  const double _t271 = 1.1091219335937498e-11*_hc2[0]*_hc2[3]*_t205 + 3.3273658007812498e-11*_hc2[1]*_hc2[2]*_t205 - 1.5527707070312501e-10*_t218 - 2.5879511783854163e-11*_t220 - 2.3291560605468751e-10*_t223;
#endif
#if _KMAX >= 4
  const double _t282 = 0.38162891519999997*_hc2[0];
  const double _t350 = 0.00024460222453125*_t104;
  const double _t374 = _hc2[4]*_t373;
  const double _t378 = _hc2[0]*_t374;
  const double _t379 = _hc2[1]*_hc2[3]*_t373;
  const double _t382 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t373;
  const double _t383 = ((_hc2[2]) * (_hc2[2]));
  const double _t384 = _t373*_t383;
  const double _t386 = _hc2[0]*_t379;
  const double _t387 = _hc2[0]*_t384;
  const double _t388 = _t374*_t8;
  const double _t389 = _t374*_t9;
  const double _t390 = _hc2[2]*_t105*_t373;
  const double _t391 = _hc2[0]*_t390;
  const double _t392 = _t379*_t8;
  const double _t395 = _t384*_t8;
  const double _t396 = 0.00099382529999999993*_t100;
  const double _t399 = 0.0004892044490625*_t104;
  const double _t401 = 0.0004892044490625*_t106;
#endif

  const double f = _hc1[0]*_t11 + _hc1[0]*_t14 + _hc1[0]*_t17 + _hc1[0]*_t4 - 0.069727705930000008*_hc1[0] + 0.14576411820000001*_hc2[0] + 0.0061869984312500001*_t10 + _t12*_t18 + _t12*_t22 + _t12*_t24 + 0.031802409599999998*_t13 - _t15*_t16 + _t15*_t21 + _t15*_t23 + _t15*_t26 - _t19*_t20 + _t19*_t25 + _t19*_t27 + _t19*_t28 + 0.0217681859775*_t5 + 0.0035198535500000003*_t6 + 0.00061919587624999998*_t7 - 0.085128253912499993*_t8 - 0.050282911999999999*_t9 + 1.1909080137835;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t11*_t29 + _t14*_t29 - _t16*_t38 + _t17*_t29 - _t20*_t39 + _t21*_t38 + _t22*_t36 + _t23*_t38 + _t24*_t36 + _t25*_t39 + _t26*_t38 + _t27*_t39 + _t28*_t39 + _t29*_t30 + _t29*_t33 + _t29*_t4 - 0.069727705930000008*_t29 + _t31*_t32 + _t32*_t35 + 0.0024767835049999999*_t34;
  out[1] = df_dt;
  const double df_dx2 = _hc1[0]*_t44 - _hc1[0]*_t46 + _hc1[0]*_t58 + _hc1[0]*_t59 + _t11*_t40 + 0.0013251003999999998*_t12*_t43 + _t12*_t60 + _t12*_t61 - 0.00065227259874999996*_t13*_t43 + _t14*_t40 - _t15*_t54 - _t15*_t55 + _t15*_t62 + _t15*_t63 - _t16*_t52 + _t17*_t40 + _t18*_t48 - _t19*_t56 + _t19*_t57 + _t19*_t64 + _t19*_t65 - _t20*_t53 + _t21*_t52 + _t22*_t48 + _t23*_t52 + _t24*_t48 + _t25*_t53 + _t26*_t52 + _t27*_t53 + _t28*_t53 + _t30*_t40 + _t33*_t40 + _t4*_t40 + _t40*_t41 - 0.069727705930000008*_t40 + 0.0024767835049999999*_t42 + 0.0060735049250000006*_t43 - 0.0070940211593749991*_t45 - 0.0062853639999999999*_t49 + 0.0010311664052083333*_t50;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t11*_t67 + _t14*_t67 - _t16*_t77 + _t17*_t67 + _t18*_t74 - _t20*_t78 + _t21*_t77 + _t22*_t74 + _t22*_t75 + _t23*_t77 + _t24*_t74 + _t24*_t75 + _t25*_t78 + _t26*_t77 + _t27*_t78 + _t28*_t78 + _t30*_t67 + _t31*_t69 + _t33*_t67 + _t35*_t73 + _t4*_t67 + _t41*_t67 - 0.069727705930000008*_t67 + 0.043536371955*_t69 + 0.021119121300000002*_t70 + 0.0024767835049999999*_t71 + 0.0074303505149999997*_t72;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = _t11*_t80 + _t14*_t80 - _t16*_t92 + _t17*_t80 - _t20*_t93 + _t21*_t92 + _t22*_t89 + _t22*_t90 + _t23*_t92 + _t24*_t89 + _t24*_t90 + _t25*_t93 + _t26*_t92 + _t27*_t93 + _t28*_t93 + _t29*_t44 - _t29*_t46 + _t29*_t58 + _t29*_t59 + _t30*_t80 + _t31*_t81 + _t32*_t85 - _t32*_t87 + _t33*_t80 + _t35*_t81 + _t36*_t60 + _t36*_t61 - _t38*_t54 - _t38*_t55 + _t38*_t62 + _t38*_t63 - _t39*_t56 + _t39*_t57 + _t39*_t64 + _t39*_t65 + _t4*_t80 + _t41*_t80 + _t80*_t86 - 0.069727705930000008*_t80 + 0.043536371955*_t81 + 0.021119121300000002*_t82 + 0.0024767835049999999*_t83 + 0.0074303505149999997*_t84;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = _hc1[0]*_t103 + _hc1[0]*_t136 + _hc1[0]*_t143 + 5.5212516666666657e-5*_t100*_t12 - 2.7178024947916664e-5*_t100*_t13 + 0.00025306270520833332*_t100 + 0.021119121300000002*_t101 + 0.0024767835049999999*_t102 - _t104*_t109 - 0.00029558421497395828*_t104 - _t106*_t109 - 2.7178024947916664e-5*_t106*_t12 - 0.00029558421497395828*_t106 + 0.0074303505149999997*_t107 + _t108*_t40 + _t11*_t95 - 0.00052378033333333332*_t110 - 0.00026189016666666666*_t111 + 4.2965266883680553e-5*_t112 + _t113*_t114 - _t113*_t116 + _t113*_t132 + _t113*_t133 - _t115*_t40 + _t118*_t18 + _t118*_t22 + _t118*_t24 + 0.00012889580065104166*_t119 + _t12*_t140 + _t12*_t144 + _t120*_t18 + _t120*_t22 + _t120*_t24 - _t121*_t15 - _t122*_t15 - _t123*_t15 - _t124*_t52 - _t125*_t19 - _t126*_t53 - _t127*_t52 + _t128*_t19 + _t129*_t19 + _t130*_t53 + _t131*_t58 + _t131*_t59 - _t135*_t16 + _t135*_t21 + _t135*_t23 + _t135*_t26 + _t137*_t62 + _t137*_t63 + _t138*_t64 + _t138*_t65 - _t139*_t20 + _t139*_t25 + _t139*_t27 + _t139*_t28 + _t14*_t95 + _t141*_t15 + _t142*_t19 + _t145*_t15 + _t146*_t19 + _t17*_t95 + _t30*_t95 + _t31*_t96 + _t33*_t95 + _t4*_t95 + _t41*_t95 - 0.069727705930000008*_t95 + 0.043536371955*_t96;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t11*_t148 + _t14*_t148 + _t147*_t150 + _t148*_t17 + _t148*_t30 + _t148*_t33 + _t148*_t4 + _t148*_t41 - 0.069727705930000008*_t148 + 0.021119121300000002*_t152 + _t153*_t154 + _t153*_t155 + 0.014860701029999999*_t156 + 0.0024767835049999999*_t157 + 0.022291051544999999*_t158 + _t159*_t35 - _t16*_t164 + _t160*_t18 + _t160*_t22 + _t160*_t24 + _t161*_t22 + _t161*_t24 + _t164*_t21 + _t164*_t23 + _t164*_t26 - _t166*_t20 + _t166*_t25 + _t166*_t27 + _t166*_t28;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = _t11*_t168 + _t14*_t168 + _t155*_t169 - _t16*_t182 + _t167*_t170 + _t168*_t17 + _t168*_t30 + _t168*_t33 + _t168*_t4 + _t168*_t41 + _t168*_t86 - 0.069727705930000008*_t168 + 0.13060911586500001*_t169 + 0.063357363900000005*_t171 + 0.014860701029999999*_t173 + 0.0024767835049999999*_t174 + 0.022291051544999999*_t175 + _t176*_t18 + _t176*_t22 + _t176*_t24 + _t177*_t178 + _t178*_t179 + _t182*_t21 + _t182*_t23 + _t182*_t26 - _t183*_t20 + _t183*_t25 + _t183*_t27 + _t183*_t28 + _t44*_t67 - _t46*_t67 - _t54*_t77 - _t55*_t77 - _t56*_t78 + _t57*_t78 + _t58*_t67 + _t59*_t67 + _t60*_t74 + _t60*_t75 + _t61*_t74 + _t61*_t75 + _t62*_t77 + _t63*_t77 + _t64*_t78 + _t65*_t78 + _t69*_t85 - _t69*_t87 + _t73*_t85 - _t73*_t87;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = _t103*_t29 + _t108*_t80 + _t11*_t185 + _t114*_t194 + _t114*_t81 - _t115*_t80 - _t116*_t194 - _t116*_t81 - _t121*_t38 - _t122*_t38 - _t123*_t38 - _t124*_t92 - _t125*_t39 - _t126*_t93 - _t127*_t92 + _t128*_t39 + _t129*_t39 + _t130*_t93 + _t132*_t194 + _t132*_t81 + _t133*_t194 + _t133*_t81 + _t136*_t29 + _t14*_t185 + _t140*_t36 + _t141*_t38 + _t142*_t39 + _t143*_t29 + _t144*_t36 + _t145*_t38 + _t146*_t39 + _t155*_t186 - _t16*_t201 + _t17*_t185 + _t170*_t184 + _t177*_t198 + _t179*_t198 + _t18*_t197 + _t185*_t30 + _t185*_t33 + _t185*_t4 + _t185*_t41 + _t185*_t86 - 0.069727705930000008*_t185 + 0.13060911586500001*_t186 + 0.063357363900000005*_t187 + 0.014860701029999999*_t188 + 0.0024767835049999999*_t189 + 0.022291051544999999*_t190 + _t191*_t32 - _t192*_t29 - _t193*_t29 - _t195*_t32 - _t196*_t32 + _t197*_t22 + _t197*_t24 + _t199*_t58 + _t199*_t59 - _t20*_t203 + _t201*_t21 + _t201*_t23 + _t201*_t26 + _t202*_t62 + _t202*_t63 + _t203*_t25 + _t203*_t27 + _t203*_t28 + _t204*_t64 + _t204*_t65;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = _hc1[0]*_t209 - _hc1[0]*_t214 - _hc1[0]*_t215 + _hc1[0]*_t252 + _hc1[0]*_t260 - _t104*_t227 - _t104*_t229 - _t104*_t246 + _t104*_t248 - _t106*_t227 + _t11*_t208 + _t113*_t226 - _t113*_t235 + _t117*_t58 + _t117*_t59 + 1.3803129166666663e-5*_t12*_t206 - 2.0383518710937495e-5*_t12*_t211 + _t12*_t258 + _t12*_t269 - 6.7945062369791651e-6*_t13*_t206 - _t135*_t253 - _t135*_t256 + _t136*_t47 - _t139*_t262 + _t139*_t265 + _t14*_t208 + _t140*_t257 + _t141*_t266 + _t142*_t267 + _t143*_t47 + _t144*_t257 + _t145*_t266 + _t146*_t267 - _t15*_t236 - _t15*_t239 - _t15*_t240 + _t15*_t259 + _t15*_t270 + _t150*_t207 + _t154*_t217 + _t155*_t217 - _t16*_t255 + _t17*_t208 + _t18*_t231 - _t19*_t241 + _t19*_t242 + _t19*_t243 + _t19*_t261 + _t19*_t271 - _t20*_t264 + 6.3265676302083331e-5*_t206 + _t208*_t30 + _t208*_t33 + _t208*_t4 + _t208*_t41 - 0.069727705930000008*_t208 + _t21*_t255 - 7.389605374348957e-5*_t210 - 0.0002216881612304687*_t211 - 0.00013094508333333333*_t212 + 0.021119121300000002*_t213 - 0.00039283524999999999*_t216 + 6.444790032552083e-5*_t218 - 6.5472541666666665e-5*_t219 + _t22*_t231 + _t22*_t238 + 1.0741316720920138e-5*_t220 + 0.014860701029999999*_t221 + 0.0024767835049999999*_t222 + 9.6671850488281252e-5*_t223 + 0.022291051544999999*_t224 + _t225*_t40 + _t228*_t95 + _t23*_t255 + _t230*_t35 + _t231*_t24 + _t232*_t233 - _t232*_t237 + _t233*_t96 - _t234*_t95 - _t237*_t96 + _t238*_t24 - _t244*_t52 - _t245*_t53 - _t247*_t52 + _t249*_t53 + _t25*_t264 + _t250*_t60 + _t250*_t61 + _t251*_t60 + _t251*_t61 + _t255*_t26 + _t264*_t27 + _t264*_t28 + _t268*_t62 + _t268*_t63 + _t272*_t64 + _t272*_t65;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t11*_t274 + _t14*_t274 + _t155*_t280 - _t16*_t295 + _t17*_t274 + _t18*_t291 + _t18*_t292 - _t20*_t296 + _t21*_t295 + _t22*_t291 + _t22*_t292 + _t22*_t293 + _t23*_t295 + _t24*_t291 + _t24*_t292 + _t24*_t293 + _t25*_t296 + _t26*_t295 + _t27*_t296 + _t274*_t30 + _t274*_t33 + _t274*_t4 + _t274*_t41 - 0.069727705930000008*_t274 + _t276*_t282 + 0.17414548782*_t276 + 0.014860701029999999*_t278 + _t28*_t296 + 0.13060911586500001*_t280 + 0.084476485200000007*_t281 + 0.063357363900000005*_t283 + 0.0024767835049999999*_t284 + 0.12671472780000001*_t286 + 0.089164206179999997*_t287 + 0.029721402059999999*_t288 + 0.022291051544999999*_t289 + _t290*_t35;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = _t11*_t298 + _t14*_t298 + _t148*_t44 - _t148*_t46 + _t148*_t58 + _t148*_t59 + _t153*_t233 - _t153*_t237 + _t154*_t303 + _t155*_t303 + _t159*_t85 - _t159*_t87 - _t16*_t314 + _t160*_t60 + _t160*_t61 + _t161*_t60 + _t161*_t61 - _t164*_t54 - _t164*_t55 + _t164*_t62 + _t164*_t63 - _t166*_t56 + _t166*_t57 + _t166*_t64 + _t166*_t65 + _t17*_t298 + _t177*_t311 + _t179*_t311 + _t18*_t309 + _t18*_t310 - _t20*_t315 + _t21*_t314 + _t22*_t309 + _t22*_t310 + _t23*_t314 + _t24*_t309 + _t24*_t310 + _t25*_t315 + _t26*_t314 + _t27*_t315 + _t28*_t315 + _t282*_t299 + _t297*_t301 + _t298*_t30 + _t298*_t33 + _t298*_t4 + _t298*_t41 + _t298*_t86 - 0.069727705930000008*_t298 + 0.17414548782*_t299 + 0.014860701029999999*_t300 + 0.084476485200000007*_t302 + 0.0024767835049999999*_t304 + 0.12671472780000001*_t305 + 0.089164206179999997*_t306 + 0.029721402059999999*_t307 + 0.022291051544999999*_t308;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = _t103*_t67 + _t108*_t168 + _t11*_t317 + _t114*_t327 - _t115*_t168 - _t116*_t327 - _t121*_t77 - _t122*_t77 - _t123*_t77 - _t124*_t182 - _t125*_t78 - _t126*_t183 - _t127*_t182 + _t128*_t78 + _t129*_t78 + _t130*_t183 + _t132*_t327 + _t133*_t327 + _t136*_t67 + _t14*_t317 + _t140*_t74 + _t140*_t75 + _t141*_t77 + _t142*_t78 + _t143*_t67 + _t144*_t74 + _t144*_t75 + _t145*_t77 + _t146*_t78 + _t154*_t321 + _t155*_t321 - _t16*_t335 + 0.023851807199999998*_t169*_t43 - 0.011740906777500001*_t169*_t45 + _t17*_t317 + _t177*_t330 + _t179*_t330 + _t18*_t328 + _t18*_t329 + _t191*_t69 + _t191*_t73 - _t192*_t67 - _t193*_t67 - _t195*_t69 - _t195*_t73 - _t196*_t69 - _t196*_t73 - _t20*_t337 + _t21*_t335 + _t22*_t328 + _t22*_t329 + _t23*_t335 + _t24*_t328 + _t24*_t329 + _t25*_t337 + _t26*_t335 + _t27*_t337 + _t28*_t337 + _t282*_t318 + _t30*_t317 + _t301*_t316 + _t317*_t33 + _t317*_t4 + _t317*_t41 + _t317*_t86 - 0.069727705930000008*_t317 + 0.17414548782*_t318 + 0.014860701029999999*_t319 + 0.084476485200000007*_t320 + 0.0024767835049999999*_t322 + 0.12671472780000001*_t323 + 0.089164206179999997*_t324 + 0.029721402059999999*_t325 + 0.022291051544999999*_t326 + _t331*_t58 + _t331*_t59 + _t332*_t60 + _t332*_t61 + _t333*_t62 + _t333*_t63 + _t336*_t64 + _t336*_t65;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = -_t104*_t349 - 1.0280457093749997e-8*_t104*_t92 + 3.1546209218749996e-9*_t104*_t93 - _t106*_t349 + _t11*_t339 + _t136*_t88 + _t14*_t339 + _t140*_t357 + _t140*_t358 + _t141*_t361 + _t142*_t363 + _t143*_t88 + _t144*_t357 + _t144*_t358 + _t145*_t361 + _t146*_t363 + _t154*_t343 + _t155*_t343 - _t16*_t360 + _t17*_t339 + _t177*_t354 + _t179*_t354 + _t18*_t351 + _t18*_t353 + _t185*_t228 - _t185*_t234 + 0.035777710800000001*_t186*_t43 - 0.017611360166249999*_t186*_t45 + _t194*_t226 - _t194*_t235 - _t194*_t350 + _t198*_t58 + _t198*_t59 - _t20*_t365 - _t201*_t253 - _t201*_t256 - _t203*_t262 + _t203*_t265 + 4.1409387499999986e-5*_t206*_t32 + _t209*_t29 + _t21*_t360 - 2.0383518710937495e-5*_t210*_t32 - 6.1150556132812486e-5*_t211*_t32 - _t214*_t29 - _t215*_t29 + _t22*_t351 + _t22*_t353 + _t225*_t80 + _t226*_t81 + _t23*_t360 + _t233*_t352 - _t235*_t81 - _t236*_t38 - _t237*_t352 - _t239*_t38 + _t24*_t351 + _t24*_t353 - _t240*_t38 - _t241*_t39 + _t242*_t39 + _t243*_t39 - _t244*_t92 - _t245*_t93 - _t247*_t92 + _t249*_t93 + _t25*_t365 + _t252*_t29 + _t258*_t36 + _t259*_t38 + _t26*_t360 + _t260*_t29 + _t261*_t39 + _t269*_t36 + _t27*_t365 + _t270*_t38 + _t271*_t39 + _t28*_t365 + _t282*_t340 + _t30*_t339 + _t301*_t338 + _t33*_t339 + _t339*_t4 + _t339*_t41 + _t339*_t86 - 0.069727705930000008*_t339 + 0.17414548782*_t340 + 0.014860701029999999*_t341 + 0.084476485200000007*_t342 + 0.0024767835049999999*_t344 + 0.12671472780000001*_t345 + 0.089164206179999997*_t346 + 0.029721402059999999*_t347 + 0.022291051544999999*_t348 - _t350*_t81 + _t355*_t60 + _t355*_t61 + _t356*_t60 + _t356*_t61 + _t362*_t62 + _t362*_t63 + _t364*_t64 + _t364*_t65;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 8.2074154730902777e-7*_hc1[0]*_t374 - 1.2079543131510415e-6*_hc1[0]*_t378 - 4.8318172526041661e-6*_hc1[0]*_t379 - 3.6238629394531246e-6*_hc1[0]*_t384 + _hc1[0]*(-5.2184937608506942e-7*_t374 + 2.087397504340277e-5*_t386 + 1.5655481282552079e-5*_t387 + 2.6092468804253462e-6*_t388 + 3.1310962565104158e-5*_t390) + _hc1[0]*(-1.2469035291883678e-10*_t378 - 4.9876141167534712e-10*_t379 + 1.7456649408637151e-9*_t382 - 3.7407105875651029e-10*_t384 + 2.9094415681061919e-10*_t389 + 1.0473989645182291e-8*_t391 + 3.4913298817274303e-9*_t392 + 2.6184974112955727e-9*_t395) - 6.3368569166666658e-5*_t100*_t135 - 1.0466552708333332e-9*_t100*_t139 + 0.00047274713125*_t100*_t95 - _t104*_t397 - _t104*_t406 + _t104*_t415 - _t106*_t397 - _t106*_t406 + _t106*_t415 + _t11*_t367 + 0.00016563754999999997*_t113*_t206 - 8.1534074843749995e-5*_t113*_t210 + 5.7513038194444427e-7*_t12*_t374 - 1.132417706163194e-6*_t12*_t379 - 8.4931327962239564e-7*_t12*_t384 + _t12*(-3.6270454372829856e-12*_t374 + 1.4508181749131942e-10*_t386 + 1.0881136311848957e-10*_t387 + 1.8135227186414928e-11*_t388 + 2.1762272623697913e-10*_t390) + _t12*(6.7918477105034712e-11*_hc2[0]*_hc2[4]*_t1*_t372 + 2.7167390842013885e-10*_hc2[1]*_hc2[3]*_t1*_t372 + 2.0375543131510415e-10*_t1*_t372*_t383 - 9.5085867947048599e-10*_t382 - 1.5847644657841432e-10*_t389 - 5.7051520768229164e-9*_t391 - 1.901717358940972e-9*_t392 - 1.4262880192057291e-9*_t395) - 2.8310442654079851e-7*_t13*_t374 + _t136*_t408 + _t14*_t367 + _t140*_t409 + _t140*_t410 + _t141*_t417 + _t142*_t419 + _t143*_t408 + _t144*_t409 + _t144*_t410 + _t145*_t417 + _t146*_t419 - 1.1001487702546295e-7*_t15*_t374 - 3.5696031575520824e-11*_t15*_t378 - 1.427841263020833e-10*_t15*_t379 - 1.0708809472656247e-10*_t15*_t384 + _t15*(1.491724753146701e-12*_hc2[4]*_t1*_t372 - 5.9668990125868052e-11*_t386 - 4.4751742594401039e-11*_t387 - 7.4586237657335065e-12*_t388 - 8.9503485188802078e-11*_t390) + _t15*(-7.7896849093966994e-12*_t378 - 3.1158739637586798e-11*_t379 + 1.0905558873155379e-10*_t382 - 2.3369054728190095e-11*_t384 + 1.8175931455258966e-11*_t389 + 6.5433353238932274e-10*_t391 + 2.181111774631076e-10*_t392 + 1.6358338309733069e-10*_t395) + _t155*_t370 - _t16*_t413 + _t17*_t367 + _t18*_t394 + _t18*_t398 - 1.8171098451967589e-12*_t19*_t374 + 1.0953544867621527e-11*_t19*_t378 + 4.3814179470486106e-11*_t19*_t379 + 3.286063460286458e-11*_t19*_t384 + _t19*(-1.0778124131944442e-13*_t374 + 4.3112496527777775e-12*_t386 + 3.2334372395833328e-12*_t387 + 5.3890620659722219e-13*_t388 + 6.4668744791666663e-12*_t390) + _t19*(4.6213413899739576e-13*_hc2[0]*_hc2[4]*_t1*_t372 + 1.8485365559895831e-12*_hc2[1]*_hc2[3]*_t1*_t372 + 1.3864024169921873e-12*_t1*_t372*_t383 - 6.4698779459635415e-12*_t382 - 1.0783129909939234e-12*_t389 - 3.8819267675781252e-11*_t391 - 1.2939755891927083e-11*_t392 - 9.7048169189453131e-12*_t395) - _t20*_t420 + 7.8791188541666666e-5*_t206*_t40 - 1.0561428194444443e-5*_t206*_t52 - 1.7444254513888886e-10*_t206*_t53 + 0.0075639540999999999*_t208*_t43 - 0.011132506949999999*_t208*_t45 + _t21*_t413 - 0.00011596361406249999*_t210*_t40 - 3.4268190312499993e-9*_t210*_t52 + 1.0515403072916665e-9*_t210*_t53 - _t211*_t227 - _t211*_t229 - _t211*_t246 + _t211*_t248 + 0.047703614399999997*_t217*_t43 - 0.023481813555000002*_t217*_t45 + _t22*_t394 + _t22*_t398 + _t22*_t400 + _t23*_t413 + 0.015901204799999999*_t230*_t43 - 0.0078272711849999999*_t230*_t45 + _t232*_t396 - _t232*_t399 - _t232*_t401 + _t24*_t394 + _t24*_t398 + _t24*_t400 + _t25*_t420 + _t252*_t405 - 0.0010138971066666665*_t255*_t43 - 3.2897462699999996e-7*_t255*_t45 + _t258*_t407 + _t259*_t411 + _t26*_t413 + _t260*_t405 + _t261*_t414 - 1.6746484333333331e-8*_t264*_t43 + 1.0094786949999999e-7*_t264*_t45 + _t269*_t407 + _t27*_t420 + _t270*_t411 + _t271*_t414 + _t28*_t420 + _t282*_t368 + _t30*_t367 + _t33*_t367 + _t35*_t393 + _t367*_t4 + _t367*_t41 - 0.069727705930000008*_t367 + 0.17414548782*_t368 + 0.014860701029999999*_t369 + 0.13060911586500001*_t370 + 0.084476485200000007*_t371 + 2.6360698459201385e-6*_t374 + 0.063357363900000005*_t375 + 0.0024767835049999999*_t376 + 0.12671472780000001*_t377 - 3.0790022393120654e-6*_t378 - 1.231600895724826e-5*_t379 + 0.089164206179999997*_t380 + 0.029721402059999999*_t381 + 2.6853291802300346e-6*_t382 - 9.2370067179361945e-6*_t384 + 0.022291051544999999*_t385 - 2.1824180555555553e-5*_t386 - 1.6368135416666666e-5*_t387 - 2.7280225694444441e-6*_t388 + 4.4755486337167241e-7*_t389 - 3.2736270833333333e-5*_t390 + 1.6111975081380207e-5*_t391 + 5.3706583604600692e-6*_t392 + 4.0279937703450519e-6*_t395 + _t396*_t96 - _t399*_t96 - _t401*_t96 + _t402*_t58 + _t402*_t59 + _t403*_t60 + _t403*_t61 + _t404*_t60 + _t404*_t61 + _t416*_t62 + _t416*_t63 + _t418*_t64 + _t418*_t65;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mbeefvdw_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

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
  if(!(_t7)) XC_CAT(mbeefvdw_f_pf_k, _KMAX)(p, _t5*sigma_ss, 0, _t6*tau_s, _hc1);
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