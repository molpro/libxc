/*
  Generated from python/mgga_exc/mgga_x_sa_tpss.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_sa_tpss
*/

#ifndef _MGGA_X_SA_TPSS_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_SA_TPSS_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_SA_TPSS_HELPER_BODIES
#include "mgga_x_sa_tpss.c"
#undef _MGGA_X_SA_TPSS_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_SA_TPSS_HELPER_BODIES
#include "mgga_x_sa_tpss.c"
#undef _MGGA_X_SA_TPSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_SA_TPSS_HELPER_BODIES
#include "mgga_x_sa_tpss.c"
#undef _MGGA_X_SA_TPSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_SA_TPSS_HELPER_BODIES
#include "mgga_x_sa_tpss.c"
#undef _MGGA_X_SA_TPSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_SA_TPSS_HELPER_BODIES
#include "mgga_x_sa_tpss.c"
#undef _MGGA_X_SA_TPSS_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_sa_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_SA_TPSS_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_ff_k, _KMAX)(const xc_func_type *p, double z, double *out) {


  const double f = 0.2e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = 0;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = 0;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = 0;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_fxden_pf_k, _KMAX)(const xc_func_type *p, double x2, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = 0.051656585037899834*_t1*x2 + 0.1e1;

  const double f = (_t2 * _t2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = 0.10331317007579967*_t1*_t2;
  out[1] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = 0.0053368055555555538*xc_powr(0.6e1, 2, 3)/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  out[2] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dx23 = 0;
  out[3] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dx24 = 0;
  out[4] = d4f_dx24;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_qb_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mgga_alpha_pf_k, _KMAX)(p, x2, t, _hc0);
  const double _t1 = (0.1e1 / 0.36e2)*xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = (0.9e1 / 0.20e2)*_hc0[0] - 0.9e1 / 0.20e2;
  const double _t3 = _hc0[0] - 0.1e1;
  const double _t4 = 0.40000000000000002*_hc0[0]*_t3 + 0.1e1;
  const double _t5 = xc_powr(_t4, -1, 2);
#if _KMAX >= 1
  const double _t6 = (0.9e1 / 0.20e2)*_t5;
  const double _t7 = 0.20000000000000001*_hc0[1];
  const double _t8 = -_hc0[0]*_t7 - _t3*_t7;
  const double _t9 = xc_powr(_t4, -3, 2);
  const double _t10 = _t2*_t9;
  const double _t11 = 0.20000000000000001*_hc0[2];
  const double _t12 = -_hc0[0]*_t11 - _t11*_t3;
#endif
#if _KMAX >= 2
  const double _t13 = ((_hc0[1]) * (_hc0[1]));
  const double _t14 = 0.40000000000000002*_t10;
  const double _t15 = _hc0[1]*_t9;
  const double _t16 = xc_powr(_t4, -5, 2);
  const double _t17 = _t16*_t2;
  const double _t18 = 0.60000000000000009*_hc0[1];
  const double _t19 = -_hc0[0]*_t18 - _t18*_t3;
  const double _t20 = _t19*_t8;
  const double _t21 = _hc0[1]*_hc0[2];
  const double _t22 = _hc0[2]*_t9;
  const double _t23 = _t12*_t17;
  const double _t24 = ((_hc0[2]) * (_hc0[2]));
  const double _t25 = 0.60000000000000009*_hc0[2];
  const double _t26 = -_hc0[0]*_t25 - _t25*_t3;
#endif
#if _KMAX >= 3
  const double _t27 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t28 = 0.54000000000000004*_t9;
  const double _t29 = _t13*_t17;
  const double _t30 = 0.80000000000000004*_t19;
  const double _t31 = xc_powr(_t4, -7, 2);
  const double _t32 = 1.0*_hc0[1];
  const double _t33 = -_hc0[0]*_t32 - _t3*_t32;
  const double _t34 = _hc0[2]*_t13;
  const double _t35 = _t17*_t21;
  const double _t36 = 1.2000000000000002*_t23;
  const double _t37 = _hc0[1]*_t24;
  const double _t38 = 0.40000000000000002*_t26;
  const double _t39 = _t17*_t24;
  const double _t40 = 0.40000000000000002*_t19;
  const double _t41 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t42 = 0.80000000000000004*_t26;
  const double _t43 = 1.0*_hc0[2];
  const double _t44 = -_hc0[0]*_t43 - _t3*_t43;
#endif
#if _KMAX >= 4
  const double _t45 = _t16*_t27;
  const double _t46 = 1.4400000000000002*_t19;
  const double _t47 = _t2*_t31;
  const double _t48 = _t33*_t47;
  const double _t49 = _t13*_t48;
  const double _t50 = 1.2000000000000002*_t19;
  const double _t51 = 2.0*_t13;
  const double _t52 = _t47*_t51;
  const double _t53 = xc_powr(_t4, -9, 2);
  const double _t54 = 1.4000000000000001*_hc0[1];
  const double _t55 = -_hc0[0]*_t54 - _t3*_t54;
  const double _t56 = _t16*_t34;
  const double _t57 = _t21*_t48;
  const double _t58 = _t12*_t48;
  const double _t59 = 2.4000000000000004*_t58;
  const double _t60 = _t16*_t37;
  const double _t61 = 2.1600000000000006*_t12;
  const double _t62 = _t12*_t26*_t47;
  const double _t63 = _t24*_t48;
  const double _t64 = _t16*_t41;
  const double _t65 = _t44*_t47;
  const double _t66 = _t12*_t65;
  const double _t67 = 2.0*_t62;
  const double _t68 = 1.2000000000000002*_t24;
  const double _t69 = 1.4000000000000001*_hc0[2];
#endif

  const double f = _t1*x2 + _t2*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1]*_t6 + _t10*_t8;
  out[1] = df_dt;
  const double df_dx2 = _hc0[2]*_t6 + _t1 + _t10*_t12;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_t13*_t14 + (0.9e1 / 0.10e2)*_t15*_t8 + _t17*_t20;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = (0.9e1 / 0.20e2)*_t12*_t15 - _t14*_t21 + _t19*_t23 + (0.9e1 / 0.20e2)*_t22*_t8;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = (0.9e1 / 0.10e2)*_t12*_t22 - _t14*_t24 + _t23*_t26;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = (0.27e2 / 0.20e2)*_hc0[1]*_t16*_t19*_t8 + _t19*_t2*_t31*_t33*_t8 - _t27*_t28 - _t29*_t30 - 1.2000000000000002*_t29*_t8;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = (0.9e1 / 0.10e2)*_hc0[1]*_t12*_t16*_t19 + (0.9e1 / 0.20e2)*_hc0[2]*_t16*_t19*_t8 + _t12*_t19*_t2*_t31*_t33 - _t13*_t36 - _t28*_t34 - _t30*_t35;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = (0.9e1 / 0.20e2)*_hc0[1]*_t12*_t16*_t26 + (0.9e1 / 0.10e2)*_hc0[2]*_t12*_t16*_t19 + _t12*_t2*_t26*_t31*_t33 - _t21*_t36 - _t28*_t37 - _t35*_t38 - _t39*_t40;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = (0.27e2 / 0.20e2)*_hc0[2]*_t12*_t16*_t26 + _t12*_t2*_t26*_t31*_t44 - _t24*_t36 - _t28*_t41 - _t39*_t42;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 1.4400000000000004*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t16*_t2 + (0.9e1 / 0.5e1)*_hc0[1]*_t19*_t31*_t33*_t8 + _t19*_t2*_t33*_t53*_t55*_t8 - _t20*_t52 - _t45*_t46 - 2.1600000000000006*_t45*_t8 - _t49*_t50 - 2.4000000000000004*_t49*_t8;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = (0.27e2 / 0.20e2)*_hc0[1]*_t12*_t19*_t31*_t33 + 1.4400000000000004*_hc0[2]*_t16*_t2*_t27 + (0.9e1 / 0.20e2)*_hc0[2]*_t19*_t31*_t33*_t8 + _t12*_t19*_t2*_t33*_t53*_t55 - _t12*_t19*_t52 - 1.6200000000000003*_t12*_t45 - _t13*_t59 - _t46*_t56 - _t50*_t57 - 0.54000000000000015*_t56*_t8;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = (0.9e1 / 0.10e2)*_hc0[1]*_t12*_t26*_t31*_t33 + (0.9e1 / 0.10e2)*_hc0[2]*_t12*_t19*_t31*_t33 + _t12*_t2*_t26*_t33*_t53*_t55 + 1.4400000000000004*_t13*_t16*_t2*_t24 - 1.0800000000000001*_t19*_t60 - _t21*_t59 - 0.36000000000000004*_t26*_t56 - _t40*_t63 - _t42*_t57 - _t51*_t62 - _t56*_t61;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = (0.9e1 / 0.20e2)*_hc0[1]*_t12*_t26*_t31*_t44 + 1.4400000000000004*_hc0[1]*_t16*_t2*_t41 + (0.27e2 / 0.20e2)*_hc0[2]*_t12*_t26*_t31*_t33 + _t12*_t2*_t26*_t44*_t53*_t55 - 0.54000000000000004*_t19*_t64 - _t21*_t38*_t65 - 1.2000000000000002*_t21*_t66 - _t21*_t67 - 0.90000000000000013*_t26*_t60 - _t42*_t63 - _t58*_t68 - _t60*_t61;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 1.4400000000000004*((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t16*_t2 + (0.9e1 / 0.5e1)*_hc0[2]*_t12*_t26*_t31*_t44 + _t12*_t2*_t26*_t44*_t53*(-_hc0[0]*_t69 - _t3*_t69) - 2.4000000000000004*_t24*_t66 - _t24*_t67 - 1.4400000000000002*_t26*_t64 - _t26*_t65*_t68 - _t61*_t64;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_z_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  const double _t1 = (0.1e1 / 0.8e1)/t;
#if _KMAX >= 1
  const double _t2 = (0.1e1 / 0.8e1)/(t * t);
#endif
#if _KMAX >= 2
  const double _t3 = (0.1e1 / 0.4e1)/(t * t * t);
#endif
#if _KMAX >= 3
  const double _t4 = (0.3e1 / 0.4e1)/(t * t * t * t);
#endif

  const double f = _t1*x2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_t2*x2;
  out[1] = df_dt;
  const double df_dx2 = _t1;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t3*x2;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = -_t2;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = 0;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = -_t4*x2;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = _t3;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = 0;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = 0;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.3e1*x2/xc_powi(t, 5);
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = -_t4;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = 0;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = 0;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 0;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_kappa_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mgga_alpha_pf_k, _KMAX)(p, x2, t, _hc0);
  const double _t1 = _hc0[0] + 0.34799999999999998;
  const double _t2 = log(_t1) + 2.4129999999999998;
  const double _t3 = xc_powr(0.5e1, 1, 2);
  const double _t4 = M_PI*_t3;
  const double _t5 = _t4/xc_powr(_t2, 1, 2);
  const double _t6 = _hc0[0] + 0.1e1;
  const double _t7 = xc_powr(_t6, 1, 2);
  const double _t8 = (0.2e1 / 0.15e2)*_t7;
#if _KMAX >= 1
  const double _t9 = (0.1e1 / 0.15e2)*_hc0[1];
  const double _t10 = (0.1e1 / _t7);
  const double _t11 = _t10*_t5;
  const double _t12 = _t4*_t7;
  const double _t13 = xc_powr(_t2, -3, 2);
  const double _t14 = _t13/_t1;
  const double _t15 = _t12*_t14;
  const double _t16 = (0.1e1 / 0.15e2)*_hc0[2];
#endif
#if _KMAX >= 2
  const double _t17 = ((_hc0[1]) * (_hc0[1]));
  const double _t18 = _t17*_t5;
  const double _t19 = xc_powr(_t6, -3, 2);
  const double _t20 = (0.1e1 / 0.30e2)*_t19;
  const double _t21 = (0.1e1 / (_t1 * _t1));
  const double _t22 = xc_powr(_t2, -5, 2);
  const double _t23 = _t10*_t4;
  const double _t24 = _t14*_t23;
  const double _t25 = _t20*_t5;
  const double _t26 = ((_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 3
  const double _t27 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t28 = (0.1e1 / 0.20e2)*_t27;
  const double _t29 = xc_powr(_t6, -5, 2);
  const double _t30 = _t29*_t5;
  const double _t31 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t32 = _t27*_t31;
  const double _t33 = xc_powr(_t2, -7, 2);
  const double _t34 = (0.1e1 / 0.4e1)*_t12*_t33;
  const double _t35 = (0.3e1 / 0.10e2)*_t12*_t22;
  const double _t36 = _t13*_t4;
  const double _t37 = _t36*_t8;
  const double _t38 = _t21*_t23;
  const double _t39 = (0.3e1 / 0.20e2)*_t22;
  const double _t40 = _t38*_t39;
  const double _t41 = (0.1e1 / 0.10e2)*_t27;
  const double _t42 = _t13*_t38;
  const double _t43 = _t19*_t4;
  const double _t44 = _t14*_t43;
  const double _t45 = (0.1e1 / 0.20e2)*_hc0[2];
  const double _t46 = _hc0[2]*_t31;
  const double _t47 = _t17*_t46;
  const double _t48 = _t17*_t22;
  const double _t49 = (0.3e1 / 0.20e2)*_t48;
  const double _t50 = (0.1e1 / 0.10e2)*_t42;
  const double _t51 = (0.1e1 / 0.20e2)*_t30;
  const double _t52 = _hc0[1]*_t26;
  const double _t53 = _t31*_t52;
  const double _t54 = (0.1e1 / 0.20e2)*_t44;
  const double _t55 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t56 = _t31*_t55;
#endif
#if _KMAX >= 4
  const double _t57 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t58 = (0.1e1 / 0.8e1)/xc_powr(_t6, 7, 2);
  const double _t59 = _t5*_t58;
  const double _t60 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t61 = xc_powr(_t2, -9, 2);
  const double _t62 = _t23*_t31;
  const double _t63 = _t57*_t62;
  const double _t64 = (0.1e1 / 0.2e1)*_t33;
  const double _t65 = (0.3e1 / 0.5e1)*_t22;
  const double _t66 = (0.4e1 / 0.15e2)*_t62;
  const double _t67 = _t21*_t57;
  const double _t68 = _t39*_t43;
  const double _t69 = _t19*_t36;
  const double _t70 = (0.1e1 / 0.10e2)*_t69;
  const double _t71 = _t14*_t29*_t4;
  const double _t72 = (0.1e1 / 0.10e2)*_t71;
  const double _t73 = _hc0[2]*_t27;
  const double _t74 = _hc0[2]*_t23*_t32;
  const double _t75 = (0.4e1 / 0.15e2)*_t13;
  const double _t76 = _t21*_t68;
  const double _t77 = _hc0[2]*_t41;
  const double _t78 = _t17*_t26;
  const double _t79 = _t21*_t70;
  const double _t80 = _hc0[1]*_t55;
  const double _t81 = _hc0[1]*_t23*_t56;
  const double _t82 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t83 = _t62*_t82;
  const double _t84 = _t21*_t82;
#endif

  const double f = _t5*_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t11*_t9 - _t15*_t9;
  out[1] = df_dt;
  const double df_dx2 = _t11*_t16 - _t15*_t16;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = (0.1e1 / 0.15e2)*M_PI*_t13*_t17*_t21*_t3*_t7 + (0.1e1 / 0.10e2)*M_PI*_t17*_t21*_t22*_t3*_t7 - 0.1e1 / 0.15e2*_t17*_t24 - _t18*_t20;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = (0.1e1 / 0.15e2)*M_PI*_hc0[1]*_hc0[2]*_t13*_t21*_t3*_t7 + (0.1e1 / 0.10e2)*M_PI*_hc0[1]*_hc0[2]*_t21*_t22*_t3*_t7 - _hc0[1]*_hc0[2]*_t25 - _hc0[2]*_t24*_t9;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = (0.1e1 / 0.15e2)*M_PI*_t13*_t21*_t26*_t3*_t7 + (0.1e1 / 0.10e2)*M_PI*_t21*_t22*_t26*_t3*_t7 - 0.1e1 / 0.15e2*_t24*_t26 - _t25*_t26;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t27*_t40 + _t28*_t30 + _t28*_t44 - _t32*_t34 - _t32*_t35 - _t32*_t37 + _t41*_t42;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = _hc0[2]*_t17*_t50 + _hc0[2]*_t38*_t49 - 0.3e1 / 0.10e2*_t12*_t46*_t48 + _t17*_t44*_t45 + _t18*_t29*_t45 - _t34*_t47 - _t37*_t47;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = -_t34*_t53 - _t35*_t53 - _t37*_t53 + _t40*_t52 + _t50*_t52 + _t51*_t52 + _t52*_t54;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = -_t34*_t56 - _t35*_t56 - _t37*_t56 + _t40*_t55 + _t50*_t55 + _t51*_t55 + _t54*_t55;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = (0.2e1 / 0.5e1)*M_PI*_t13*_t3*_t57*_t60*_t7 - _t13*_t57*_t66 + (0.11e2 / 0.10e2)*M_PI*_t22*_t3*_t57*_t60*_t7 + (0.3e1 / 0.2e1)*M_PI*_t3*_t33*_t57*_t60*_t7 + (0.7e1 / 0.8e1)*M_PI*_t3*_t57*_t60*_t61*_t7 - _t57*_t59 - _t57*_t72 - _t63*_t64 - _t63*_t65 - _t67*_t68 - _t67*_t70;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = (0.2e1 / 0.5e1)*M_PI*_hc0[2]*_t13*_t27*_t3*_t60*_t7 + (0.11e2 / 0.10e2)*M_PI*_hc0[2]*_t22*_t27*_t3*_t60*_t7 + (0.3e1 / 0.2e1)*M_PI*_hc0[2]*_t27*_t3*_t33*_t60*_t7 + (0.7e1 / 0.8e1)*M_PI*_hc0[2]*_t27*_t3*_t60*_t61*_t7 - _t21*_t69*_t77 - _t59*_t73 - _t64*_t74 - _t65*_t74 - _t71*_t77 - _t73*_t76 - _t74*_t75;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = (0.2e1 / 0.5e1)*M_PI*_t13*_t17*_t26*_t3*_t60*_t7 - _t13*_t66*_t78 + (0.11e2 / 0.10e2)*M_PI*_t17*_t22*_t26*_t3*_t60*_t7 + (0.3e1 / 0.2e1)*M_PI*_t17*_t26*_t3*_t33*_t60*_t7 + (0.7e1 / 0.8e1)*M_PI*_t17*_t26*_t3*_t60*_t61*_t7 - _t18*_t26*_t58 - _t21*_t26*_t43*_t49 - 0.3e1 / 0.5e1*_t26*_t48*_t62 - _t62*_t64*_t78 - _t72*_t78 - _t78*_t79;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = (0.2e1 / 0.5e1)*M_PI*_hc0[1]*_t13*_t3*_t55*_t60*_t7 + (0.11e2 / 0.10e2)*M_PI*_hc0[1]*_t22*_t3*_t55*_t60*_t7 + (0.3e1 / 0.2e1)*M_PI*_hc0[1]*_t3*_t33*_t55*_t60*_t7 + (0.7e1 / 0.8e1)*M_PI*_hc0[1]*_t3*_t55*_t60*_t61*_t7 - _t59*_t80 - _t64*_t81 - _t65*_t81 - _t72*_t80 - _t75*_t81 - _t76*_t80 - _t79*_t80;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = (0.2e1 / 0.5e1)*M_PI*_t13*_t3*_t60*_t7*_t82 - _t13*_t66*_t82 + (0.11e2 / 0.10e2)*M_PI*_t22*_t3*_t60*_t7*_t82 + (0.3e1 / 0.2e1)*M_PI*_t3*_t33*_t60*_t7*_t82 + (0.7e1 / 0.8e1)*M_PI*_t3*_t60*_t61*_t7*_t82 - _t59*_t82 - _t64*_t83 - _t65*_t83 - _t68*_t84 - _t70*_t84 - _t72*_t82;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_fxnum_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_qb_pf_k, _KMAX)(p, x2, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_z_pf_k, _KMAX)(p, x2, t, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tpss_ff_k, _KMAX)(p, 0, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_kappa_pf_k, _KMAX)(p, x2, t, _hc3);
  const double _t1 = ((_hc1[0]) * (_hc1[0]));
  const double _t2 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t3 = xc_powr(0.6e1, 2, 3);
  const double _t4 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = _t5/_hc3[0];
  const double _t7 = (x2 * x2);
  const double _t8 = (0.25e2 / 0.944784e6)*_t7;
  const double _t9 = (0.1e1 / 0.1152e4)*_t5;
  const double _t10 = (0.9e1 / 0.50e2)*_t1 + _t7*_t9;
  const double _t11 = xc_powr(_t10, 1, 2);
  const double _t12 = (0.73e2 / 0.405e3)*_t11;
  const double _t13 = pow(_hc1[0], _hc2[0]);
  const double _t14 = _t1 + 0.1e1;
  const double _t15 = (0.1e1 / (_t14 * _t14));
  const double _t16 = _t13*_t15;
  const double _t17 = 1.5909599999999999*_t16;
  const double _t18 = xc_powr(0.6e1, 1, 3);
  const double _t19 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t20 = _t18*_t19;
  const double _t21 = (0.1e1 / 0.24e2)*_t20;
  const double _t22 = _t21*(_t17 + 0.10e2 / 0.81e2);
#if _KMAX >= 1
  const double _t23 = 0.2204014294950393*_hc1[0];
  const double _t24 = (0.292e3 / 0.2025e4)*_hc0[0];
  const double _t25 = (0.1e1 / ((_hc3[0]) * (_hc3[0])));
  const double _t26 = _t25*_t5;
  const double _t27 = _t26*_t8;
  const double _t28 = _hc1[0]*_hc1[1];
  const double _t29 = (0.1e1 / _t11);
  const double _t30 = _hc0[0]*_t29;
  const double _t31 = (0.73e2 / 0.2250e4)*_t30;
  const double _t32 = (0.1e1 / (_t14 * _t14 * _t14));
  const double _t33 = _t13*_t32;
  const double _t34 = 6.3638399999999997*_t33;
  const double _t35 = (0.1e1 / (_hc1[0]));
  const double _t36 = _t21*(1.5909599999999999*_hc1[1]*_hc2[0]*_t13*_t15*_t35 - _t28*_t34);
  const double _t37 = (0.25e2 / 0.472392e6)*_t6;
  const double _t38 = (0.9e1 / 0.50e2)*_hc1[0];
  const double _t39 = _hc1[2]*_t38 + _t9*x2;
  const double _t40 = (0.73e2 / 0.405e3)*_t39;
  const double _t41 = _hc1[0]*_hc1[2];
  const double _t42 = _t34*_t41;
  const double _t43 = 1.5909599999999999*_hc1[2]*_hc2[0]*_t13*_t15*_t35 - _t42;
  const double _t44 = _t21*x2;
#endif
#if _KMAX >= 2
  const double _t45 = ((_hc1[1]) * (_hc1[1]));
  const double _t46 = ((_hc3[1]) * (_hc3[1]));
  const double _t47 = (0.1e1 / ((_hc3[0]) * (_hc3[0]) * (_hc3[0])));
  const double _t48 = _t47*_t5;
  const double _t49 = _t46*_t48;
  const double _t50 = (0.25e2 / 0.472392e6)*_t7;
  const double _t51 = _hc1[0]*_hc1[3];
  const double _t52 = _hc0[1]*_t29;
  const double _t53 = (0.73e2 / 0.1125e4)*_t28;
  const double _t54 = (0.73e2 / 0.2250e4)*_t45;
  const double _t55 = xc_powr(_t10, -3, 2);
  const double _t56 = _hc0[0]*_t55;
  const double _t57 = _t1*_t45;
  const double _t58 = (0.73e2 / 0.12500e5)*_t57;
  const double _t59 = 12.727679999999999*_t33;
  const double _t60 = _hc2[0]*_t59;
  const double _t61 = (0.1e1 / (_t14 * _t14 * _t14 * _t14));
  const double _t62 = _t13*_t61;
  const double _t63 = 38.183039999999998*_t62;
  const double _t64 = (0.1e1 / _t1);
  const double _t65 = ((_hc2[0]) * (_hc2[0]));
  const double _t66 = _t64*_t65;
  const double _t67 = _t17*_t66;
  const double _t68 = _t45*_t67;
  const double _t69 = _hc2[0]*_t35;
  const double _t70 = _hc1[3]*_t69;
  const double _t71 = _hc2[0]*_t64;
  const double _t72 = _t45*_t71;
  const double _t73 = _t70 - _t72;
  const double _t74 = _t17*_t73;
  const double _t75 = _t21*(-_t34*_t45 - _t34*_t51 - _t45*_t60 + _t57*_t63 + _t68 + _t74);
  const double _t76 = _hc1[1]*_hc1[2];
  const double _t77 = (0.292e3 / 0.2025e4)*_hc0[2];
  const double _t78 = _t5*x2;
  const double _t79 = _t25*_t78;
  const double _t80 = (0.25e2 / 0.472392e6)*_t79;
  const double _t81 = _hc3[2]*_t48;
  const double _t82 = _hc0[2]*_t29;
  const double _t83 = (0.73e2 / 0.2250e4)*_t82;
  const double _t84 = _hc1[4]*_t38 + (0.9e1 / 0.50e2)*_t76;
  const double _t85 = (0.73e2 / 0.405e3)*_t30;
  const double _t86 = (0.73e2 / 0.2250e4)*_t28;
  const double _t87 = _t39*_t56;
  const double _t88 = _hc1[0]*_t34;
  const double _t89 = _t34*_t76;
  const double _t90 = _t60*_t76;
  const double _t91 = _hc1[4]*_t69;
  const double _t92 = _t71*_t76;
  const double _t93 = _t91 - _t92;
  const double _t94 = -_hc1[4]*_t88 + _t1*_t63*_t76 + _t17*_t93 + _t67*_t76 - _t89 - _t90;
  const double _t95 = ((_hc1[2]) * (_hc1[2]));
  const double _t96 = (0.25e2 / 0.236196e6)*_t79;
  const double _t97 = _hc3[5]*_t26;
  const double _t98 = ((_hc3[2]) * (_hc3[2]));
  const double _t99 = _t9 + (0.9e1 / 0.50e2)*_t95;
  const double _t100 = (0.146e3 / 0.405e3)*_t39;
  const double _t101 = (0.1e1 / 0.12e2)*_t20;
  const double _t102 = -_t39;
  const double _t103 = _t102*_t56;
  const double _t104 = _t34*_t95;
  const double _t105 = _t60*_t95;
  const double _t106 = _t71*_t95;
  const double _t107 = 38.183039999999998*_t1*_t13*_t61*_t95 - _t104 - _t105 - _t106*_t17 + 1.5909599999999999*_t13*_t15*_t64*_t65*_t95;
#endif
#if _KMAX >= 3
  const double _t108 = 0.66120428848511792*_hc1[1];
  const double _t109 = (0.292e3 / 0.675e3)*_hc0[1];
  const double _t110 = _t48*_t7;
  const double _t111 = (0.25e2 / 0.157464e6)*_t110;
  const double _t112 = _hc3[1]*_hc3[3];
  const double _t113 = (0.1e1 / ((_hc3[0]) * (_hc3[0]) * (_hc3[0]) * (_hc3[0])));
  const double _t114 = ((_hc3[1]) * (_hc3[1]) * (_hc3[1]));
  const double _t115 = _t113*_t114;
  const double _t116 = _t5*_t7;
  const double _t117 = (0.25e2 / 0.157464e6)*_t116;
  const double _t118 = _hc1[0]*_hc1[6];
  const double _t119 = (0.73e2 / 0.750e3)*_t30;
  const double _t120 = _hc1[1]*_hc1[3];
  const double _t121 = (0.73e2 / 0.750e3)*_t51;
  const double _t122 = _hc0[3]*_t29;
  const double _t123 = (0.73e2 / 0.750e3)*_t28;
  const double _t124 = (0.73e2 / 0.750e3)*_t45;
  const double _t125 = (0.219e3 / 0.12500e5)*_t56;
  const double _t126 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t127 = _hc1[0]*_t126;
  const double _t128 = _t1*_t120;
  const double _t129 = xc_powr(_t10, -5, 2);
  const double _t130 = _hc0[0]*_t129;
  const double _t131 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t132 = _t126*_t131;
  const double _t133 = (0.1971e4 / 0.625000e6)*_t132;
  const double _t134 = _hc0[1]*_t55;
  const double _t135 = (0.219e3 / 0.12500e5)*_t57;
  const double _t136 = 19.091519999999999*_t33;
  const double _t137 = _t120*_t136;
  const double _t138 = _t13/xc_powi(_t14, 5);
  const double _t139 = 305.46431999999999*_t138;
  const double _t140 = _t126*_t136;
  const double _t141 = (0.1e1 / _t131);
  const double _t142 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t143 = _t35*_t65;
  const double _t144 = _t136*_t28;
  const double _t145 = 0.2e1*_t70 - 0.2e1*_t72;
  const double _t146 = _hc1[6]*_t69;
  const double _t147 = 0.3e1*_t71;
  const double _t148 = _hc2[0]*_t141;
  const double _t149 = _t126*_t148;
  const double _t150 = -_t120*_t147 + _t146 + 0.2e1*_t149;
  const double _t151 = _t21*(114.54911999999999*_hc1[0]*_hc2[0]*_t126*_t13*_t61 + 114.54911999999999*_hc1[0]*_t126*_t13*_t61 + 114.54911999999999*_hc1[1]*_hc1[3]*_t1*_t13*_t61 + 1.5909599999999999*_hc1[1]*_hc2[0]*_t13*_t145*_t15*_t35 + 1.5909599999999999*_hc1[1]*_hc2[0]*_t13*_t15*_t35*_t73 - _hc1[6]*_t88 - _hc2[0]*_t137 + 1.5909599999999999*_t126*_t13*_t141*_t142*_t15 + 1.5909599999999999*_t13*_t15*_t150 - _t132*_t139 - _t137 - _t140*_t143 - _t140*_t69 - _t144*_t73);
  const double _t152 = _hc1[1]*_hc1[4];
  const double _t153 = _hc1[2]*_hc1[3];
  const double _t154 = _t47*_t78;
  const double _t155 = (0.25e2 / 0.236196e6)*_t110;
  const double _t156 = _t50*_t81;
  const double _t157 = _t113*_t117;
  const double _t158 = _hc3[2]*_t46;
  const double _t159 = _hc0[4]*_t29;
  const double _t160 = _hc0[2]*_t55;
  const double _t161 = (0.146e3 / 0.405e3)*_t84;
  const double _t162 = _t56*_t84;
  const double _t163 = _hc1[7]*_t38 + (0.9e1 / 0.25e2)*_t152 + (0.9e1 / 0.50e2)*_t153;
  const double _t164 = (0.73e2 / 0.2250e4)*_t87;
  const double _t165 = _t134*_t39;
  const double _t166 = _t54*_t56;
  const double _t167 = _t130*_t39;
  const double _t168 = _t153*_t34;
  const double _t169 = _hc1[2]*_t45;
  const double _t170 = _t131*_t139;
  const double _t171 = _t136*_t143;
  const double _t172 = _t59*_t93;
  const double _t173 = _hc1[7]*_t69;
  const double _t174 = 0.2e1*_t71;
  const double _t175 = _t153*_t71;
  const double _t176 = 0.2e1*_t148*_t169 - _t152*_t174 + _t173 - _t175;
  const double _t177 = 114.54911999999999*_hc1[0]*_hc1[2]*_hc2[0]*_t13*_t45*_t61 + 114.54911999999999*_hc1[0]*_hc1[2]*_t13*_t45*_t61 + 76.366079999999997*_hc1[1]*_hc1[4]*_t1*_t13*_t61 + 3.1819199999999999*_hc1[1]*_hc2[0]*_t13*_t15*_t35*_t93 + 38.183039999999998*_hc1[2]*_hc1[3]*_t1*_t13*_t61 + 1.5909599999999999*_hc1[2]*_hc2[0]*_t13*_t15*_t35*_t73 + 1.5909599999999999*_hc1[2]*_t13*_t141*_t142*_t15*_t45 - _hc1[7]*_t88 - _hc2[0]*_t168 + 1.5909599999999999*_t13*_t15*_t176 - _t136*_t169*_t69 - _t152*_t59 - _t152*_t60 - _t168 - _t169*_t170 - _t169*_t171 - _t172*_t28 - _t42*_t73;
  const double _t178 = (0.25e2 / 0.472392e6)*_t26;
  const double _t179 = _t157*_t98;
  const double _t180 = _hc1[2]*_hc1[4];
  const double _t181 = _hc0[5]*_t29;
  const double _t182 = (0.73e2 / 0.2250e4)*_t181;
  const double _t183 = (0.73e2 / 0.405e3)*_t99;
  const double _t184 = (0.73e2 / 0.405e3)*_t103;
  const double _t185 = -_t84;
  const double _t186 = _t40*_t56;
  const double _t187 = _t102*_t134;
  const double _t188 = _hc1[1]*_t95;
  const double _t189 = _t141*_t17;
  const double _t190 = 0.2e1*_hc1[1]*_hc2[0]*_t141*_t95 - _t174*_t180;
  const double _t191 = 0.2e1*_t91 - 0.2e1*_t92;
  const double _t192 = 114.54911999999999*_hc1[0]*_hc1[1]*_hc2[0]*_t13*_t61*_t95 + 114.54911999999999*_hc1[0]*_hc1[1]*_t13*_t61*_t95 + 1.5909599999999999*_hc1[1]*_t13*_t141*_t142*_t15*_t95 + 76.366079999999997*_hc1[2]*_hc1[4]*_t1*_t13*_t61 + 1.5909599999999999*_hc1[2]*_hc2[0]*_t13*_t15*_t191*_t35 + 1.5909599999999999*_t13*_t15*_t190 - _t170*_t188 - _t171*_t188 - _t172*_t41 - _t180*_t59 - _t180*_t60 - _t188*_t189*_t65 - _t188*_t59*_t69;
  const double _t193 = (0.25e2 / 0.157464e6)*_t26;
  const double _t194 = (0.25e2 / 0.157464e6)*_t79;
  const double _t195 = ((_hc3[2]) * (_hc3[2]) * (_hc3[2]));
  const double _t196 = _t113*_t195;
  const double _t197 = (0.73e2 / 0.135e3)*_t99;
  const double _t198 = (0.73e2 / 0.135e3)*_t39;
  const double _t199 = -_t99;
  const double _t200 = (0.146e3 / 0.405e3)*_t99;
  const double _t201 = _t102*_t160;
  const double _t202 = _t102*_t40;
  const double _t203 = (0.27e2 / 0.50e2)*_hc1[0];
  const double _t204 = (0.1e1 / 0.384e3)*_t5;
  const double _t205 = -_hc1[2]*_t203 - _t204*x2;
  const double _t206 = _t130*_t205;
  const double _t207 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t208 = 114.54911999999999*_t62;
  const double _t209 = _t207*_t208;
  const double _t210 = _hc1[0]*_t209;
  const double _t211 = 3.1819199999999999*_t16;
  const double _t212 = 4.7728799999999998*_t16;
  const double _t213 = _hc2[0]*_t210 - _t141*_t207*_t212*_t65 + _t142*_t189*_t207 + _t148*_t207*_t211 - _t170*_t207 - _t171*_t207 + _t210;
#endif
#if _KMAX >= 4
  const double _t214 = _hc1[1]*_hc1[6];
  const double _t215 = ((_hc1[3]) * (_hc1[3]));
  const double _t216 = xc_powi((_hc3[0]), -5);
  const double _t217 = (0.25e2 / 0.39366e5)*_t116;
  const double _t218 = _t216*_t217;
  const double _t219 = (0.25e2 / 0.26244e5)*_t113;
  const double _t220 = _t116*_t46;
  const double _t221 = (0.146e3 / 0.1125e4)*_t52;
  const double _t222 = (0.73e2 / 0.375e3)*_t122;
  const double _t223 = _hc0[6]*_t29;
  const double _t224 = (0.146e3 / 0.1125e4)*_t28;
  const double _t225 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t226 = (0.219e3 / 0.3125e4)*_t134;
  const double _t227 = _t45*_t51;
  const double _t228 = (0.73e2 / 0.3125e4)*_t56;
  const double _t229 = _t1*_t225;
  const double _t230 = (0.5913e4 / 0.312500e6)*_t130;
  const double _t231 = _t1*_t215;
  const double _t232 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t233 = _t225*_t232;
  const double _t234 = xc_powr(_t10, -7, 2);
  const double _t235 = _hc0[0]*_t234;
  const double _t236 = _hc0[1]*_t129;
  const double _t237 = _hc0[3]*_t55;
  const double _t238 = (0.219e3 / 0.6250e4)*_t57;
  const double _t239 = _t131*_t45;
  const double _t240 = _hc1[3]*_t239;
  const double _t241 = 25.455359999999999*_t33;
  const double _t242 = _t214*_t241;
  const double _t243 = _hc2[0]*_t225;
  const double _t244 = 458.19647999999995*_t62;
  const double _t245 = 1832.7859199999998*_t138;
  const double _t246 = xc_powi(_t14, -6);
  const double _t247 = 3054.6432*_t13*_t246;
  const double _t248 = 229.09823999999998*_t62;
  const double _t249 = _t225*_t65;
  const double _t250 = 1221.8572799999999*_t138;
  const double _t251 = _t1*_t250;
  const double _t252 = ((_hc2[0]) * (_hc2[0]) * (_hc2[0]) * (_hc2[0]));
  const double _t253 = (0.1e1 / _t232);
  const double _t254 = _t17*_t253;
  const double _t255 = _t252*_t254;
  const double _t256 = 38.183039999999998*_t33;
  const double _t257 = _t142*_t241*_t64;
  const double _t258 = _t256*_t45;
  const double _t259 = _hc1[3]*_t143;
  const double _t260 = _t45*_t73;
  const double _t261 = _hc2[0]*_t241;
  const double _t262 = _t17*_t69;
  const double _t263 = 0.4e1*_t71;
  const double _t264 = 0.6e1*_t253;
  const double _t265 = _hc1[2]*_hc1[6];
  const double _t266 = _hc1[3]*_hc1[4];
  const double _t267 = (0.25e2 / 0.52488e5)*_t113;
  const double _t268 = _hc3[2]*_t116*_t267;
  const double _t269 = _hc3[4]*_t267;
  const double _t270 = (0.73e2 / 0.750e3)*_t120;
  const double _t271 = _hc0[7]*_t29;
  const double _t272 = (0.219e3 / 0.12500e5)*_t160;
  const double _t273 = _hc0[2]*_t129;
  const double _t274 = _hc0[4]*_t55;
  const double _t275 = (0.73e2 / 0.135e3)*_t84;
  const double _t276 = (0.73e2 / 0.375e3)*_t28;
  const double _t277 = (0.657e3 / 0.12500e5)*_t57;
  const double _t278 = _t130*_t84;
  const double _t279 = _hc1[1]*_hc1[7];
  const double _t280 = (0.657e3 / 0.12500e5)*_t167;
  const double _t281 = _t136*_t279;
  const double _t282 = _t265*_t34;
  const double _t283 = 916.3929599999999*_t138;
  const double _t284 = _t131*_t76;
  const double _t285 = _hc1[2]*_t126;
  const double _t286 = _t1*_t245;
  const double _t287 = _hc1[4]*_t283;
  const double _t288 = _hc2[0]*_t251;
  const double _t289 = _t256*_t66;
  const double _t290 = _hc1[4]*_t171;
  const double _t291 = _t136*_t93;
  const double _t292 = _hc1[0]*_hc1[4];
  const double _t293 = _t136*_t73;
  const double _t294 = _hc2[0]*_t264;
  const double _t295 = ((_hc1[4]) * (_hc1[4]));
  const double _t296 = _hc3[1]*_hc3[4];
  const double _t297 = _hc0[8]*_t29;
  const double _t298 = _hc0[5]*_t55;
  const double _t299 = _hc1[2]*_hc1[7];
  const double _t300 = (0.73e2 / 0.1125e4)*_t160*_t39;
  const double _t301 = _t185*_t56;
  const double _t302 = _t102*_t39;
  const double _t303 = _t130*_t302;
  const double _t304 = _t57*_t95;
  const double _t305 = _t45*_t95;
  const double _t306 = _t241*_t93;
  const double _t307 = _t219*_t98;
  const double _t308 = _hc0[9]*_t29;
  const double _t309 = _t102*_t206;
  const double _t310 = _t130*_t202;
  const double _t311 = _t202*_t205;
  const double _t312 = 343.64735999999994*_t62;
  const double _t313 = _t292*_t95;
  const double _t314 = _hc1[1]*_t207;
  const double _t315 = _hc2[0]*_t314;
  const double _t316 = _t232*_t247;
  const double _t317 = _t136*_t95;
  const double _t318 = _t253*_t65;
  const double _t319 = (0.292e3 / 0.405e3)*_t39;
  const double _t320 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t321 = _t248*_t320;
  const double _t322 = _t16*_t320;
  const double _t323 = 9.5457599999999996*_t253*_t322;
#endif

  const double f = (0.146e3 / 0.2025e4)*((_hc0[0]) * (_hc0[0])) - _hc0[0]*_t12 + 0.11020071474751965*_t1 + 0.00014643527343749998*_t2*(x2 * x2 * x2) + _t22*x2 + _t6*_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_hc0[1]*_t12 + _hc0[1]*_t24 + _hc1[1]*_t23 - _hc3[1]*_t27 - _t28*_t31 + _t36*x2;
  out[1] = df_dt;
  const double df_dx2 = -_hc0[2]*_t12 + _hc0[2]*_t24 + _hc1[2]*_t23 - _hc3[2]*_t27 + 0.00043930582031249997*_t2*_t7 + _t22 - _t30*_t40 + _t37*x2 + _t43*_t44;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = (0.292e3 / 0.2025e4)*((_hc0[1]) * (_hc0[1])) - _hc0[3]*_t12 + _hc0[3]*_t24 + _hc1[3]*_t23 - _hc3[3]*_t27 - _t30*_t54 - _t31*_t51 + 0.2204014294950393*_t45 + _t49*_t50 - _t52*_t53 + _t56*_t58 + _t75*x2;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = _hc0[1]*_t77 - _hc0[4]*_t12 + _hc0[4]*_t24 + _hc1[4]*_t23 + _hc3[1]*_t50*_t81 - _hc3[1]*_t80 - _hc3[4]*_t27 - _t28*_t83 + _t36 - _t40*_t52 + _t44*_t94 + 0.2204014294950393*_t76 - _t84*_t85 + _t86*_t87;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = (0.292e3 / 0.2025e4)*((_hc0[2]) * (_hc0[2])) - _hc0[5]*_t12 + _hc0[5]*_t24 - _hc3[2]*_t96 - _t100*_t82 + _t101*_t43 - _t103*_t40 + _t107*_t44 + 0.00087861164062499994*_t2*x2 + _t37 + _t48*_t50*_t98 - _t8*_t97 - _t85*_t99 + 0.2204014294950393*_t95;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[3]*_t109 - _hc0[6]*_t12 + _hc0[6]*_t24 + _hc1[3]*_t108 + _hc1[6]*_t23 - _hc3[6]*_t27 + _t111*_t112 - _t115*_t117 - _t118*_t31 - _t119*_t120 - _t121*_t52 - _t122*_t123 - _t124*_t52 + _t125*_t127 + _t125*_t128 - _t130*_t133 + _t134*_t135 + _t151*x2;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = (0.584e3 / 0.2025e4)*_hc0[1]*_hc0[4] + _hc0[3]*_t77 - _hc0[7]*_t12 + _hc0[7]*_t24 + _hc1[7]*_t23 + _hc3[1]*_hc3[4]*_t155 + _hc3[3]*_t156 - _hc3[3]*_t80 - _hc3[7]*_t27 - _t122*_t40 - _t135*_t167 + 0.44080285899007859*_t152 + 0.2204014294950393*_t153 + (0.25e2 / 0.236196e6)*_t154*_t46 - _t157*_t158 - _t159*_t53 + _t160*_t58 - _t161*_t52 + _t162*_t53 - _t163*_t85 + _t164*_t51 + _t165*_t53 + _t166*_t39 + _t177*_t44 - _t51*_t83 - _t54*_t82 + _t75;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = (0.292e3 / 0.2025e4)*_hc0[0]*_hc0[8] + (0.73e2 / 0.750e3)*_hc0[0]*_hc1[0]*_hc1[1]*_t102*_t129*_t39 + (0.73e2 / 0.2250e4)*_hc0[0]*_hc1[0]*_hc1[1]*_t55*_t99 + (0.292e3 / 0.2025e4)*_hc0[1]*_hc0[5] + (0.584e3 / 0.2025e4)*_hc0[2]*_hc0[4] + (0.73e2 / 0.1125e4)*_hc0[2]*_hc1[0]*_hc1[1]*_t39*_t55 - _hc0[8]*_t12 + 0.44080285899007859*_hc1[2]*_hc1[4] + (0.25e2 / 0.118098e6)*_hc3[1]*_hc3[2]*_t3*_t4*_t47*x2 + (0.25e2 / 0.472392e6)*_hc3[1]*_hc3[5]*_t3*_t4*_t47*_t7 - _hc3[1]*_t178 - _hc3[1]*_t179 + (0.25e2 / 0.236196e6)*_hc3[2]*_hc3[4]*_t3*_t4*_t47*_t7 - _hc3[4]*_t96 - _hc3[8]*_t27 - _t100*_t159 - _t161*_t82 + (0.1e1 / 0.24e2)*_t18*_t19*_t192*x2 + (0.1e1 / 0.12e2)*_t18*_t19*_t94 - 0.73e2 / 0.1125e4*_t180*_t30 - _t182*_t28 - _t183*_t52 - _t184*_t84 - _t185*_t186 - _t187*_t40;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = (0.292e3 / 0.2025e4)*_hc0[0]*_hc0[9] + (0.292e3 / 0.675e3)*_hc0[2]*_hc0[5] - _hc0[9]*_t12 + (0.25e2 / 0.157464e6)*_hc3[2]*_hc3[5]*_t3*_t4*_t47*_t7 - _hc3[2]*_t193 - _hc3[5]*_t194 - _hc3[9]*_t27 - _t103*_t200 + (0.1e1 / 0.8e1)*_t107*_t18*_t19 - _t117*_t196 + (0.1e1 / 0.24e2)*_t18*_t19*_t213*x2 - _t181*_t198 - _t186*_t199 - _t197*_t82 - _t198*_t201 + 0.00087861164062499994*_t2 - _t202*_t206 + (0.25e2 / 0.78732e5)*_t3*_t4*_t47*_t98*x2;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = (0.1168e4 / 0.2025e4)*_hc0[1]*_hc0[6] - _hc0[10]*_t12 + _hc0[10]*_t24 + (0.292e3 / 0.675e3)*((_hc0[3]) * (_hc0[3])) - _hc1[0]*_hc1[10]*_t31 + _hc1[10]*_t23 + ((_hc3[1]) * (_hc3[1]) * (_hc3[1]) * (_hc3[1]))*_t218 + (0.25e2 / 0.118098e6)*_hc3[1]*_hc3[6]*_t110 - _hc3[10]*_t27 + ((_hc3[3]) * (_hc3[3]))*_t111 - _hc3[3]*_t219*_t220 + _t1*_t214*_t228 - _t118*_t221 - _t119*_t215 - 0.146e3 / 0.375e3*_t120*_t52 + _t125*_t225 + _t125*_t231 + _t127*_t226 + _t128*_t226 - 0.1971e4 / 0.156250e6*_t132*_t236 - 0.146e3 / 0.1125e4*_t214*_t30 + 0.88160571798015719*_t214 + 0.66120428848511792*_t215 - _t222*_t45 - _t222*_t51 - _t223*_t224 + (0.657e3 / 0.6250e4)*_t227*_t56 - _t229*_t230 - _t230*_t240 + (0.17739e5 / 0.6250000e7)*_t233*_t235 + _t237*_t238 + _t44*(_hc1[1]*_t150*_t211*_t69 + _hc1[1]*_t262*(-0.6e1*_t120*_t71 + 0.2e1*_t146 + 0.4e1*_t149) - _hc1[10]*_t88 + _hc2[0]*_t227*_t244 - _hc2[0]*_t242 + 152.73215999999999*_t1*_t214*_t62 - _t136*_t215 - _t145*_t261*_t45 + _t145*_t68 + _t145*_t74 - _t150*_t241*_t28 + _t17*(_t73 * _t73) + _t17*(_hc1[10]*_hc2[0]*_t35 + 0.12e2*_hc1[3]*_hc2[0]*_t141*_t45 - _t147*_t215 - _t214*_t263 - _t243*_t264) + _t208*_t225 + _t208*_t231 + _t225*_t255 - _t225*_t257 + 687.29471999999987*_t227*_t62 - _t229*_t245 + _t233*_t247 - _t240*_t245 - _t242 + _t243*_t244 - _t243*_t251 + _t248*_t249 + _t248*_t57*_t73 - _t249*_t256*_t64 - _t256*_t260 - _t256*_t51*_t73 - _t258*_t259 - _t260*_t261 - 76.366079999999997*_t33*_t45*_t70 + _t45*_t66*_t74 + _t68*(0.3e1*_t70 - 0.3e1*_t72));
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = -_hc0[11]*_t12 + _hc0[11]*_t24 + (0.292e3 / 0.675e3)*_hc0[3]*_hc0[4] + _hc0[6]*_t77 + _hc0[7]*_t109 + _hc1[11]*_t23 + _hc1[7]*_t108 + _hc3[1]*_hc3[7]*_t111 - _hc3[11]*_t27 + _hc3[2]*_t114*_t218 + _hc3[3]*_hc3[4]*_t111 + _hc3[6]*_t156 - _hc3[6]*_t80 + (0.25e2 / 0.78732e5)*_t112*_t154 - _t112*_t268 - 0.25e2 / 0.78732e5*_t115*_t78 + _t118*_t164 - _t118*_t83 - _t121*_t159 + _t121*_t162 + _t121*_t165 - _t122*_t275 + _t123*_t163*_t56 + _t123*_t237*_t39 - _t123*_t271 - _t124*_t159 + _t124*_t162 + _t124*_t165 + _t127*_t272 - _t127*_t280 + _t128*_t272 - _t128*_t280 + (0.1971e4 / 0.125000e6)*_t132*_t235*_t39 - _t133*_t273 + _t134*_t276*_t84 + _t135*_t274 + _t151 - 0.73e2 / 0.135e3*_t163*_t52 - _t220*_t269 - _t223*_t40 - _t236*_t277*_t39 + 0.2204014294950393*_t265 + 0.66120428848511792*_t266 - _t270*_t82 + _t270*_t87 - _t277*_t278 + _t44*(229.09823999999998*_hc1[0]*_hc1[1]*_hc1[2]*_hc1[3]*_hc2[0]*_t13*_t61 + 343.64735999999999*_hc1[0]*_hc1[1]*_hc1[2]*_hc1[3]*_t13*_t61 + 229.09823999999998*_hc1[0]*_hc1[4]*_hc2[0]*_t13*_t45*_t61 + 343.64735999999994*_hc1[0]*_hc1[4]*_t13*_t45*_t61 + 114.54911999999999*_hc1[1]*_hc1[2]*_t1*_t13*_t61*_t73 + 1.5909599999999999*_hc1[1]*_hc1[2]*_t13*_t145*_t15*_t64*_t65 + 1.5909599999999999*_hc1[1]*_hc1[2]*_t13*_t15*_t64*_t65*_t73 + 114.54911999999999*_hc1[1]*_hc1[7]*_t1*_t13*_t61 + 4.7728799999999998*_hc1[1]*_hc2[0]*_t13*_t15*_t176*_t35 - _hc1[11]*_t88 + 38.183039999999998*_hc1[2]*_hc1[6]*_t1*_t13*_t61 + 458.19647999999995*_hc1[2]*_hc2[0]*_t126*_t13*_t61 + 1.5909599999999999*_hc1[2]*_hc2[0]*_t13*_t15*_t150*_t35 + 1.5909599999999999*_hc1[2]*_t126*_t13*_t15*_t252*_t253 + 3054.6432*_hc1[2]*_t126*_t13*_t232*_t246 + 229.09823999999998*_hc1[2]*_t126*_t13*_t61*_t65 + 114.54911999999999*_hc1[2]*_t126*_t13*_t61 + 114.54911999999999*_hc1[3]*_hc1[4]*_t1*_t13*_t61 - _hc1[3]*_t171*_t76 - _hc1[3]*_t283*_t284 - _hc2[0]*_t145*_t89 - _hc2[0]*_t258*_t93 - _hc2[0]*_t281 - _hc2[0]*_t282 + 114.54911999999999*_t1*_t13*_t45*_t61*_t93 + 4.7728799999999998*_t13*_t15*_t45*_t64*_t65*_t93 + 4.7728799999999998*_t13*_t15*_t73*_t93 + 1.5909599999999999*_t13*_t15*(0.6e1*_hc1[1]*_hc1[2]*_hc1[3]*_hc2[0]*_t141 + _hc1[11]*_hc2[0]*_t35 + 0.6e1*_hc1[4]*_hc2[0]*_t141*_t45 - _t147*_t266 - _t147*_t279 - _t265*_t71 - _t285*_t294) - _t136*_t266 - _t144*_t176 - _t150*_t42 - _t239*_t287 - _t256*_t70*_t76 - _t257*_t285 - _t258*_t91 - _t261*_t73*_t76 - _t281 - _t282 - _t285*_t286 - _t285*_t288 - _t285*_t289 - _t290*_t45 - _t291*_t45 - _t291*_t51 - _t292*_t293 - _t293*_t76) - _t85*(_hc1[11]*_t38 + (0.9e1 / 0.50e2)*_t265 + (0.27e2 / 0.50e2)*_t266 + (0.27e2 / 0.50e2)*_t279);
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = (0.584e3 / 0.2025e4)*_hc0[1]*_hc0[8] - _hc0[12]*_t12 + _hc0[12]*_t24 + (0.584e3 / 0.2025e4)*_hc0[2]*_hc0[7] + (0.292e3 / 0.2025e4)*_hc0[3]*_hc0[5] + (0.584e3 / 0.2025e4)*((_hc0[4]) * (_hc0[4])) + 0.44080285899007859*_hc1[2]*_hc1[7] + _hc3[1]*_hc3[8]*_t155 - _hc3[12]*_t27 + (0.25e2 / 0.118098e6)*_hc3[2]*_hc3[3]*_t154 + _hc3[2]*_hc3[7]*_t155 - _hc3[2]*_t113*_t217*_t296 + _hc3[3]*_hc3[5]*_t48*_t50 - _hc3[3]*_t178 - _hc3[3]*_t179 + ((_hc3[4]) * (_hc3[4]))*_t155 - _hc3[5]*_t157*_t46 - _hc3[7]*_t96 - _t100*_t134*_t185 - _t100*_t271 + _t101*_t177 + _t102*_t276*_t278 - 0.25e2 / 0.39366e5*_t113*_t158*_t78 + _t121*_t303 - _t122*_t183 + _t124*_t303 - _t130*_t135*_t99 + _t134*_t53*_t99 + (0.25e2 / 0.59049e5)*_t154*_t296 - 0.292e3 / 0.405e3*_t159*_t84 + _t160*_t224*_t84 - _t161*_t187 - _t161*_t301 - _t163*_t184 + _t163*_t186 - 0.146e3 / 0.405e3*_t163*_t82 + _t166*_t99 + _t167*_t185*_t276 - _t180*_t221 - _t181*_t54 - _t182*_t51 - _t202*_t237 + _t218*_t46*_t98 + _t224*_t274*_t39 + _t228*_t292*_t76 - 0.219e3 / 0.2500e4*_t235*_t302*_t57 + _t236*_t276*_t302 - _t238*_t273*_t39 + 0.44080285899007859*_t295 - _t297*_t53 + _t298*_t58 + _t300*_t45 + _t300*_t51 + _t44*(305.46431999999999*_hc1[0]*_hc1[1]*_hc1[2]*_hc1[4]*_hc2[0]*_t13*_t61 + 458.19647999999995*_hc1[0]*_hc1[1]*_hc1[2]*_hc1[4]*_t13*_t61 + 76.366079999999997*_hc1[0]*_hc1[3]*_hc2[0]*_t13*_t61*_t95 + 114.54911999999999*_hc1[0]*_hc1[3]*_t13*_t61*_t95 + 152.73215999999999*_hc1[1]*_hc1[2]*_t1*_t13*_t61*_t93 + 3.1819199999999999*_hc1[1]*_hc1[2]*_t13*_t15*_t191*_t64*_t65 + 3.1819199999999999*_hc1[1]*_hc2[0]*_t13*_t15*_t190*_t35 + 76.366079999999997*_hc1[2]*_hc1[7]*_t1*_t13*_t61 + 1.5909599999999999*_hc1[2]*_hc2[0]*_t13*_t15*_t35*(0.4e1*_t148*_t169 - _t152*_t263 + 0.2e1*_t173 - 0.2e1*_t175) - _hc1[3]*_t170*_t95 - _hc1[4]*_t143*_t241*_t76 - _hc1[4]*_t250*_t284 + 6.3638399999999997*_hc2[0]*_t13*_t32*_t45*_t64*_t95 + 420.01343999999995*_hc2[0]*_t13*_t45*_t61*_t95 - _hc2[0]*_t250*_t304 + 76.366079999999997*_t1*_t13*_t295*_t61 + 38.183039999999998*_t1*_t13*_t61*_t73*_t95 - _t104*_t259 - _t104*_t70 - _t104*_t73 - _t105*_t73 - _t106*_t74 + 1.5909599999999999*_t13*_t15*_t191*_t93 + 1.5909599999999999*_t13*_t15*_t252*_t253*_t45*_t95 + 1.5909599999999999*_t13*_t15*_t64*_t65*_t73*_t95 + 1.5909599999999999*_t13*_t15*(0.8e1*_hc1[1]*_hc1[2]*_hc1[4]*_hc2[0]*_t141 + 0.2e1*_hc1[3]*_hc2[0]*_t141*_t95 - _t174*_t295 - _t174*_t299 - _t294*_t305) + 3054.6432*_t13*_t232*_t246*_t45*_t95 + 229.09823999999998*_t13*_t45*_t61*_t65*_t95 + 114.54911999999999*_t13*_t45*_t61*_t95 - _t142*_t254*_t305 - _t176*_t41*_t59 - _t190*_t28*_t59 - _t191*_t90 - _t241*_t305*_t66 - _t245*_t304 - _t257*_t305 - _t261*_t76*_t93 - _t292*_t306 - _t295*_t59 - _t299*_t59 - _t299*_t60 - _t306*_t76 - 50.910719999999998*_t33*_t76*_t91) + (0.25e2 / 0.236196e6)*_t49 + (0.73e2 / 0.2250e4)*_t51*_t56*_t99 - _t85*((0.9e1 / 0.25e2)*_t295 + (0.9e1 / 0.25e2)*_t299);
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = (0.292e3 / 0.2025e4)*_hc0[0]*_hc0[13] + (0.73e2 / 0.375e3)*_hc0[0]*_hc1[0]*_hc1[1]*_t102*_t129*_t99 + (0.73e2 / 0.450e3)*_hc0[0]*_hc1[0]*_hc1[1]*_t102*_t205*_t234*_t39 + (0.73e2 / 0.750e3)*_hc0[0]*_hc1[0]*_hc1[1]*_t129*_t199*_t39 + (0.73e2 / 0.1125e4)*_hc0[0]*_hc1[2]*_hc1[4]*_t39*_t55 + (0.292e3 / 0.2025e4)*_hc0[1]*_hc0[9] - _hc0[13]*_t12 + (0.292e3 / 0.675e3)*_hc0[2]*_hc0[8] + (0.73e2 / 0.250e3)*_hc0[2]*_hc1[0]*_hc1[1]*_t102*_t129*_t39 + (0.73e2 / 0.750e3)*_hc0[2]*_hc1[0]*_hc1[1]*_t55*_t99 + (0.292e3 / 0.675e3)*_hc0[4]*_hc0[5] + (0.73e2 / 0.750e3)*_hc0[5]*_hc1[0]*_hc1[1]*_t39*_t55 + (0.25e2 / 0.78732e5)*_hc3[1]*_hc3[2]*_t3*_t4*_t47 - _hc3[1]*_hc3[5]*_t268 + (0.25e2 / 0.78732e5)*_hc3[1]*_hc3[5]*_t3*_t4*_t47*x2 + (0.25e2 / 0.472392e6)*_hc3[1]*_hc3[9]*_t3*_t4*_t47*_t7 + (0.25e2 / 0.39366e5)*_hc3[1]*_t195*_t216*_t3*_t4*_t7 - _hc3[1]*_t307*_t78 - _hc3[13]*_t27 + (0.25e2 / 0.39366e5)*_hc3[2]*_hc3[4]*_t3*_t4*_t47*x2 + (0.25e2 / 0.157464e6)*_hc3[2]*_hc3[8]*_t3*_t4*_t47*_t7 + (0.25e2 / 0.157464e6)*_hc3[4]*_hc3[5]*_t3*_t4*_t47*_t7 - _hc3[4]*_t193 - _hc3[8]*_t194 - _t102*_t198*_t274 - 0.146e3 / 0.1125e4*_t103*_t180 - _t116*_t269*_t98 - _t134*_t199*_t40 - _t159*_t197 - _t160*_t185*_t198 - 0.73e2 / 0.405e3*_t162*_t199 + (0.1e1 / 0.8e1)*_t18*_t19*_t192 + (0.1e1 / 0.24e2)*_t18*_t19*x2*(_hc1[1]*_t209 + _hc1[2]*_t17*_t190*_t69 + _hc1[2]*_t262*(0.4e1*_hc1[1]*_hc2[0]*_t141*_t95 - _t180*_t263) - _hc2[0]*_t191*_t317 + _hc2[0]*_t248*_t313 + _t1*_t208*_t93*_t95 - _t106*_t212*_t93 - _t131*_t287*_t95 - _t136*_t190*_t41 - _t142*_t212*_t253*_t314 + _t17*(0.6e1*_hc1[4]*_t148*_t95 - _t294*_t314) + _t211*_t314*_t318 + _t248*_t314*_t65 - _t251*_t315 + _t255*_t314 - _t257*_t314 - _t286*_t314 - _t290*_t95 - _t291*_t95 + _t312*_t313 + _t312*_t315 + _t314*_t316 + _t314*_t34*_t71 - _t317*_t91 + _t67*_t95*(0.3e1*_t91 - 0.3e1*_t92)) - 0.73e2 / 0.375e3*_t180*_t82 - _t181*_t275 - _t185*_t206*_t40 - _t187*_t200 - _t198*_t297 - _t200*_t301 - _t201*_t275 - _t236*_t311 - _t308*_t86 - 0.73e2 / 0.405e3*_t309*_t84 - _t310*(-_hc1[4]*_t203 - 0.27e2 / 0.50e2*_t76);
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = (0.292e3 / 0.2025e4)*_hc0[0]*_hc0[14] - _hc0[14]*_t12 + (0.1168e4 / 0.2025e4)*_hc0[2]*_hc0[9] + (0.292e3 / 0.675e3)*((_hc0[5]) * (_hc0[5])) - _hc3[14]*_t27 + (0.25e2 / 0.39366e5)*((_hc3[2]) * (_hc3[2]) * (_hc3[2]) * (_hc3[2]))*_t216*_t3*_t4*_t7 + (0.25e2 / 0.19683e5)*_hc3[2]*_hc3[5]*_t3*_t4*_t47*x2 + (0.25e2 / 0.118098e6)*_hc3[2]*_hc3[9]*_t3*_t4*_t47*_t7 + (0.25e2 / 0.157464e6)*((_hc3[5]) * (_hc3[5]))*_t3*_t4*_t47*_t7 - _hc3[5]*_t116*_t307 - 0.25e2 / 0.118098e6*_hc3[9]*_t79 - _t100*_t199*_t206 - _t102*_t205*_t273*_t319 - _t160*_t199*_t319 + (0.1e1 / 0.6e1)*_t18*_t19*_t213 + (0.1e1 / 0.24e2)*_t18*_t19*x2*(_hc2[0]*_t321 - _hc2[0]*_t323 - _t142*_t323 + _t208*_t320 + _t255*_t320 - _t257*_t320 - _t286*_t320 - _t288*_t320 + _t289*_t320 + _t316*_t320 + 17.50056*_t318*_t322 - _t320*_t59*_t71 + _t321*_t65) - 0.146e3 / 0.135e3*_t181*_t99 - 0.25e2 / 0.19683e5*_t196*_t78 - _t197*_t199*_t56 - _t197*_t309 - 0.584e3 / 0.405e3*_t201*_t99 - _t235*_t311*(-0.9e1 / 0.10e2*_t41 - 0.5e1 / 0.1152e4*_t78) - 0.146e3 / 0.135e3*_t298*_t302 + (0.25e2 / 0.39366e5)*_t3*_t4*_t47*_t98 - _t308*_t319 - _t310*(-_t204 - 0.27e2 / 0.50e2*_t95) - 0.25e2 / 0.78732e5*_t97;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_fx_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tpss_fxden_pf_k, _KMAX)(p, x2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_fxnum_pf_k, _KMAX)(p, x2, t, _hc1);
  const double _t1 = (0.1e1 / (_hc0[0]));
#if _KMAX >= 1
  const double _t2 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t3 = _hc0[1]*_t2;
#endif
#if _KMAX >= 2
  const double _t4 = 0.2e1*_t3;
  const double _t5 = _hc0[2]*_t2;
  const double _t6 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t7 = ((_hc0[1]) * (_hc0[1]));
  const double _t8 = _t6*_t7;
  const double _t9 = 0.2e1*_t8;
#endif
#if _KMAX >= 3
  const double _t10 = 0.3e1*_t3;
  const double _t11 = 0.3e1*_t5;
  const double _t12 = 0.6e1*_hc1[0];
  const double _t13 = _t12*_t6;
  const double _t14 = _hc0[1]*_hc0[2];
  const double _t15 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t16 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t15;
  const double _t17 = 0.6e1*_t8;
#endif
#if _KMAX >= 4
  const double _t18 = 0.6e1*_hc1[1];
  const double _t19 = _t14*_t6;
  const double _t20 = 0.24e2*_hc1[2];
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t1;
  out[1] = df_dt;
  const double df_dx2 = -_hc1[0]*_t3 + _hc1[2]*_t1;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[3]*_t1;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = -_hc1[1]*_t3 + _hc1[4]*_t1;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = -_hc1[0]*_t5 + _hc1[0]*_t9 - _hc1[2]*_t4 + _hc1[5]*_t1;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc1[6]*_t1;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = -_hc1[3]*_t3 + _hc1[7]*_t1;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = -_hc1[1]*_t5 + _hc1[1]*_t9 - _hc1[4]*_t4 + _hc1[8]*_t1;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = -_hc1[2]*_t11 + _hc1[2]*_t17 - _hc1[5]*_t10 + _hc1[9]*_t1 - _t12*_t16 + _t13*_t14;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc1[10]*_t1;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = _hc1[11]*_t1 - _hc1[6]*_t3;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = _hc1[12]*_t1 - _hc1[3]*_t5 + _hc1[3]*_t9 - _hc1[7]*_t4;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = _hc1[13]*_t1 - _hc1[4]*_t11 + _hc1[4]*_t17 - _hc1[8]*_t10 - _t16*_t18 + _t18*_t19;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = ((_hc0[2]) * (_hc0[2]))*_t13 - 0.36e2*_hc0[2]*_hc1[0]*_t15*_t7 + _hc1[14]*_t1 - 0.6e1*_hc1[5]*_t5 + 0.12e2*_hc1[5]*_t8 - 0.4e1*_hc1[9]*_t3 - _t16*_t20 + _t19*_t20 + 0.24e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[0]/xc_powi((_hc0[0]), 5);
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(sa_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_fx_pf_k, _KMAX)(p, x2, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_kappa_pf_k, _KMAX)(p, x2, t, _hc1);
  const double _t1 = _hc0[0] + _hc1[0];
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = _hc0[0]*_t2;
#if _KMAX >= 1
  const double _t4 = _hc1[0]*_t2;
  const double _t5 = (0.1e1 / (_t1 * _t1));
  const double _t6 = _hc0[0]*_t5;
  const double _t7 = -_hc0[1] - _hc1[1];
  const double _t8 = _hc1[0]*_t7;
  const double _t9 = -_hc0[2] - _hc1[2];
  const double _t10 = _hc1[0]*_t6;
#endif
#if _KMAX >= 2
  const double _t11 = 0.2e1*_hc0[1];
  const double _t12 = _hc1[1]*_t2;
  const double _t13 = -_hc0[3] - _hc1[3];
  const double _t14 = 0.2e1*_hc1[1];
  const double _t15 = _t6*_t7;
  const double _t16 = _t5*_t8;
  const double _t17 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t18 = _hc0[0]*_t17;
  const double _t19 = -_t11 - _t14;
  const double _t20 = _t19*_t8;
  const double _t21 = _hc1[2]*_t2;
  const double _t22 = _hc0[2]*_t2;
  const double _t23 = -_hc0[4] - _hc1[4];
  const double _t24 = _t6*_t9;
  const double _t25 = _hc1[2]*_t6;
  const double _t26 = _hc1[0]*_t5;
  const double _t27 = _hc0[1]*_t9;
  const double _t28 = _t18*_t19;
  const double _t29 = _hc1[0]*_t9;
  const double _t30 = 0.2e1*_hc0[2];
  const double _t31 = -_hc0[5] - _hc1[5];
  const double _t32 = 0.2e1*_hc1[2];
  const double _t33 = _t26*_t9;
  const double _t34 = -_t30 - _t32;
  const double _t35 = _t18*_t29;
#endif
#if _KMAX >= 3
  const double _t36 = 0.3e1*_hc0[1];
  const double _t37 = _hc1[3]*_t2;
  const double _t38 = 0.3e1*_hc1[1];
  const double _t39 = _t2*_t38;
  const double _t40 = -_hc0[6] - _hc1[6];
  const double _t41 = _t13*_t6;
  const double _t42 = 0.3e1*_hc1[3];
  const double _t43 = _t13*_t26;
  const double _t44 = 0.6e1*_t7;
  const double _t45 = _hc1[1]*_t5;
  const double _t46 = _hc0[1]*_t45;
  const double _t47 = 0.3e1*_hc0[3];
  const double _t48 = -0.2e1*_hc0[3] - 0.2e1*_hc1[3];
  const double _t49 = _t18*_t8;
  const double _t50 = _hc1[0]*_t28;
  const double _t51 = 0.2e1*_t50;
  const double _t52 = _t28*_t7;
  const double _t53 = _t17*_t20;
  const double _t54 = -_t36 - _t38;
  const double _t55 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t56 = _hc0[0]*_t55;
  const double _t57 = _t54*_t56;
  const double _t58 = _hc1[4]*_t2;
  const double _t59 = _hc0[4]*_t2;
  const double _t60 = -_hc0[7] - _hc1[7];
  const double _t61 = _hc0[2]*_t26;
  const double _t62 = _t23*_t6;
  const double _t63 = 0.2e1*_hc1[4];
  const double _t64 = _t23*_t26;
  const double _t65 = _t11*_t9;
  const double _t66 = _t5*_t7;
  const double _t67 = _hc1[2]*_t66;
  const double _t68 = _hc0[2]*_t14;
  const double _t69 = 0.2e1*_hc0[4];
  const double _t70 = _hc1[2]*_t7;
  const double _t71 = _hc0[2]*_t17;
  const double _t72 = _hc1[0]*_t23;
  const double _t73 = 0.2e1*_t72;
  const double _t74 = _t28*_t9;
  const double _t75 = _t19*_t29;
  const double _t76 = _t17*_t75;
  const double _t77 = _hc1[5]*_t2;
  const double _t78 = _hc0[5]*_t2;
  const double _t79 = -_hc0[8] - _hc1[8];
  const double _t80 = _t31*_t6;
  const double _t81 = _hc1[5]*_t6;
  const double _t82 = _t26*_t31;
  const double _t83 = _hc1[2]*_t5;
  const double _t84 = _t5*_t9;
  const double _t85 = _hc1[0]*_t31;
  const double _t86 = _t18*_t34;
  const double _t87 = -_t63 - _t69;
  const double _t88 = _t86*_t9;
  const double _t89 = _t17*_t34;
  const double _t90 = _hc1[0]*_t27;
  const double _t91 = _t29*_t34;
  const double _t92 = 0.3e1*_hc0[2];
  const double _t93 = 0.3e1*_hc1[2];
  const double _t94 = -_hc0[9] - _hc1[9];
  const double _t95 = 0.3e1*_hc1[5];
  const double _t96 = 0.6e1*_hc0[2];
  const double _t97 = _t83*_t9;
  const double _t98 = 0.3e1*_hc0[5];
  const double _t99 = -0.2e1*_hc0[5] - 0.2e1*_hc1[5];
  const double _t100 = 0.2e1*_t85;
  const double _t101 = _t29*_t89;
  const double _t102 = -_t92 - _t93;
  const double _t103 = _t56*_t91;
#endif
#if _KMAX >= 4
  const double _t104 = 0.4e1*_hc0[1];
  const double _t105 = 0.6e1*_hc0[3];
  const double _t106 = 0.4e1*_hc1[1];
  const double _t107 = _hc1[3]*_t66;
  const double _t108 = 0.12e2*_hc0[1];
  const double _t109 = -0.2e1*_hc0[6] - 0.2e1*_hc1[6];
  const double _t110 = _hc1[0]*_t13;
  const double _t111 = _t18*_t48;
  const double _t112 = 0.3e1*_t111;
  const double _t113 = _t13*_t28;
  const double _t114 = _t106*_t7;
  const double _t115 = _t17*_t19;
  const double _t116 = _t110*_t115;
  const double _t117 = _t48*_t8;
  const double _t118 = _t104*_t17;
  const double _t119 = _hc1[1]*_t115;
  const double _t120 = -_t42 - _t47;
  const double _t121 = _t120*_t56;
  const double _t122 = _t19*_t57;
  const double _t123 = 0.3e1*_t122;
  const double _t124 = _t20*_t54;
  const double _t125 = _t124*_t55;
  const double _t126 = _hc0[0]/xc_powi(_t1, 5);
  const double _t127 = _t126*(-_t104 - _t106);
  const double _t128 = _hc1[7]*_t2;
  const double _t129 = _t6*_t60;
  const double _t130 = 0.3e1*_hc1[4];
  const double _t131 = _t26*_t60;
  const double _t132 = 0.6e1*_t23;
  const double _t133 = _t13*_t83;
  const double _t134 = _hc1[3]*_t84;
  const double _t135 = _hc0[2]*_t5;
  const double _t136 = _t135*_t38;
  const double _t137 = _hc0[3]*_t84;
  const double _t138 = _t66*_t93;
  const double _t139 = 0.3e1*_hc0[4];
  const double _t140 = _hc1[0]*_t60;
  const double _t141 = _t111*_t9;
  const double _t142 = _t115*_t72;
  const double _t143 = _t17*_t29;
  const double _t144 = _t143*_t48;
  const double _t145 = _t115*_t70;
  const double _t146 = _t19*_t71;
  const double _t147 = _t29*_t57;
  const double _t148 = 0.2e1*_t147;
  const double _t149 = _t38*_t9;
  const double _t150 = _t54*_t75;
  const double _t151 = _t150*_t55;
  const double _t152 = _hc1[8]*_t2;
  const double _t153 = 0.4e1*_hc0[4];
  const double _t154 = _hc0[8]*_t2;
  const double _t155 = _t6*_t79;
  const double _t156 = 0.4e1*_hc1[4];
  const double _t157 = 0.2e1*_hc1[7];
  const double _t158 = 0.2e1*_hc1[8];
  const double _t159 = _t26*_t79;
  const double _t160 = _t23*_t83;
  const double _t161 = _hc1[4]*_t84;
  const double _t162 = _hc1[5]*_t66;
  const double _t163 = 0.4e1*_hc0[2];
  const double _t164 = 0.4e1*_hc1[2];
  const double _t165 = 0.2e1*_hc0[7];
  const double _t166 = 0.2e1*_hc0[8];
  const double _t167 = _t18*_t87;
  const double _t168 = _t28*_t31;
  const double _t169 = _t14*_t86;
  const double _t170 = _t167*_t9;
  const double _t171 = _t115*_t85;
  const double _t172 = _t11*_t89;
  const double _t173 = _t143*_t87;
  const double _t174 = _hc1[2]*_t9;
  const double _t175 = _t34*_t57;
  const double _t176 = _t175*_t9;
  const double _t177 = _t54*_t91;
  const double _t178 = _t177*_t55;
  const double _t179 = _hc1[9]*_t2;
  const double _t180 = _t6*_t94;
  const double _t181 = _t26*_t94;
  const double _t182 = _t31*_t83;
  const double _t183 = _hc1[5]*_t84;
  const double _t184 = _t18*_t99;
  const double _t185 = _hc1[1]*_t9;
  const double _t186 = _t17*_t99;
  const double _t187 = _hc1[0]*_t86;
  const double _t188 = _t34*_t71;
  const double _t189 = _t102*_t56;
  const double _t190 = _t189*_t34;
  const double _t191 = _t189*_t29;
  const double _t192 = _t102*_t55;
  const double _t193 = _t102*_t91;
  const double _t194 = 0.6e1*_hc0[5];
  const double _t195 = 0.6e1*_hc1[5];
  const double _t196 = 0.12e2*_hc0[2];
  const double _t197 = 0.3e1*_t85;
  const double _t198 = _t164*_t9;
#endif

  const double f = _hc1[0]*_t3 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1]*_t4 + _hc1[1]*_t3 + _t6*_t8;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx2 = _hc0[2]*_t4 + _hc1[2]*_t3 + _t10*_t9;
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[3]*_t4 + _hc1[3]*_t3 + _t10*_t13 + _t11*_t12 + _t11*_t16 + _t14*_t15 + _t18*_t20;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx2_dt = _hc0[1]*_t21 + _hc0[2]*_t16 + _hc0[4]*_t4 + _hc1[1]*_t22 + _hc1[1]*_t24 + _hc1[4]*_t3 + _t10*_t23 + _t25*_t7 + _t26*_t27 + _t28*_t29;
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = 0;
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = _hc0[5]*_t4 + _hc1[5]*_t3 + _t10*_t31 + _t21*_t30 + _t24*_t32 + _t30*_t33 + _t34*_t35;
  out[9] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[3]*_t39 + _hc0[6]*_t4 + _hc1[6]*_t3 + _t10*_t40 + _t13*_t51 + _t15*_t42 + _t16*_t47 + _t20*_t57 + _t36*_t37 + _t36*_t43 + _t36*_t53 + _t38*_t41 + _t38*_t52 + _t44*_t46 + _t48*_t49;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx2_dt2 = _hc0[3]*_t21 + _hc0[3]*_t33 + _hc0[7]*_t4 + _hc1[3]*_t22 + _hc1[3]*_t24 + _hc1[7]*_t3 + _t10*_t60 + _t11*_t58 + _t11*_t64 + _t11*_t67 + _t11*_t76 + _t13*_t25 + _t13*_t61 + _t14*_t59 + _t14*_t62 + _t14*_t74 + _t15*_t63 + _t16*_t69 + _t20*_t71 + _t28*_t70 + _t28*_t73 + _t35*_t48 + _t45*_t65 + _t57*_t75 + _t66*_t68;
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = 0;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = 0;
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = _hc0[1]*_t77 + _hc0[1]*_t82 + _hc0[5]*_t16 + _hc0[8]*_t4 + _hc1[1]*_t78 + _hc1[1]*_t80 + _hc1[1]*_t88 + _hc1[8]*_t3 + _t10*_t79 + _t24*_t63 + _t28*_t85 + _t30*_t58 + _t30*_t64 + _t30*_t67 + _t30*_t76 + _t32*_t59 + _t32*_t62 + _t32*_t74 + _t33*_t69 + _t35*_t87 + _t57*_t91 + _t65*_t83 + _t68*_t84 + _t7*_t81 + _t72*_t86 + _t89*_t90;
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = 0;
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = _hc0[9]*_t4 + _hc1[9]*_t3 + _t10*_t94 + _t100*_t86 + _t101*_t92 + _t102*_t103 + _t24*_t95 + _t33*_t98 + _t35*_t99 + _t77*_t92 + _t78*_t93 + _t80*_t93 + _t82*_t92 + _t88*_t93 + _t96*_t97;
  out[19] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.8e1*_hc0[1]*_t116 + _hc0[10]*_t4 + 0.12e2*_hc0[3]*_t45*_t7 + _hc0[6]*_t106*_t2 + 0.4e1*_hc0[6]*_t16 + 0.8e1*_hc1[1]*_t113 + _hc1[10]*_t3 + _hc1[3]*_t28*_t44 + 0.6e1*_hc1[3]*_t41 + _hc1[6]*_t104*_t2 + 0.4e1*_hc1[6]*_t15 + _t10*(-_hc0[10] - _hc1[10]) + _t104*_t125 + _t104*_t26*_t40 + _t105*_t37 + _t105*_t43 + _t105*_t53 + _t106*_t40*_t6 + _t107*_t108 + _t108*_t119*_t7 + _t109*_t49 + _t110*_t112 + _t110*_t123 + _t111*_t114 + _t114*_t122 + _t117*_t118 + 0.2e1*_t117*_t57 + _t121*_t20 + _t124*_t127 + 0.12e2*_t13*_t46 + 0.3e1*_t40*_t50;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx2_dt3 = _hc0[1]*_hc1[4]*_t44*_t5 + 0.6e1*_hc0[1]*_t142 + _hc0[11]*_t4 + _hc0[2]*_t125 + _hc0[3]*_t138 + _hc0[4]*_t44*_t45 + _hc0[6]*_t21 + _hc0[6]*_t33 + 0.3e1*_hc0[7]*_t16 + _hc0[7]*_t39 + _hc1[1]*_t132*_t28 + _hc1[11]*_t3 + _hc1[6]*_t22 + _hc1[6]*_t24 + 0.3e1*_hc1[7]*_t15 + _t10*(-_hc0[11] - _hc1[11]) + _t107*_t92 + _t109*_t35 + _t111*_t70 + _t112*_t72 + _t113*_t32 + _t116*_t30 + _t117*_t71 + 0.6e1*_t119*_t27 + _t121*_t75 + _t122*_t149 + _t122*_t70 + _t123*_t72 + _t127*_t150 + _t128*_t36 + _t129*_t38 + _t13*_t136 + _t130*_t41 + _t130*_t52 + _t131*_t36 + _t132*_t46 + _t133*_t36 + _t134*_t36 + _t137*_t38 + _t139*_t43 + _t139*_t53 + 0.3e1*_t140*_t28 + _t141*_t38 + _t144*_t36 + _t145*_t36 + _t146*_t38*_t7 + _t148*_t48 + _t151*_t36 + _t25*_t40 + _t40*_t61 + _t42*_t59 + _t42*_t62 + _t42*_t74 + _t47*_t58 + _t47*_t64 + _t47*_t76;
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = 0;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = 0;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = 0;
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = _hc0[12]*_t4 + _hc0[3]*_t101 + _hc0[3]*_t77 + _hc0[3]*_t82 + _hc0[4]*_t106*_t84 + _hc0[4]*_t164*_t66 + _hc0[5]*_t14*_t66 + _hc0[5]*_t43 + _hc0[5]*_t53 + _hc0[7]*_t2*_t32 + _hc1[1]*_t65*_t89 + _hc1[12]*_t3 + _hc1[3]*_t78 + _hc1[3]*_t80 + _hc1[3]*_t88 + _hc1[4]*_t163*_t66 + _hc1[5]*_t52 + _t10*(-_hc0[12] - _hc1[12]) + _t103*_t120 + _t104*_t160 + _t104*_t161 + _t106*_t135*_t23 + _t106*_t146*_t9 + _t11*_t152 + _t11*_t159 + _t11*_t162 + _t11*_t171 + _t11*_t173 + _t11*_t178 + _t11*_t31*_t45 + _t111*_t85 + _t118*_t174*_t19 + _t122*_t32*_t9 + _t122*_t85 + _t127*_t177 + _t128*_t30 + _t129*_t32 + _t13*_t81 + _t131*_t30 + _t133*_t30 + _t134*_t30 + _t137*_t32 + _t14*_t154 + _t14*_t155 + _t14*_t168 + _t14*_t170 + _t14*_t176 + _t140*_t86 + _t141*_t32 + _t142*_t163 + _t144*_t30 + _t145*_t30 + _t148*_t87 + _t15*_t158 + _t151*_t30 + _t153*_t58 + _t153*_t64 + _t153*_t76 + _t156*_t62 + _t156*_t74 + _t157*_t24 + _t16*_t166 + _t164*_t23*_t28 + _t165*_t33 + _t167*_t73 + _t169*_t23 + _t172*_t72 + _t175*_t73 + _t35*(-_t157 - _t165) + _t51*_t79;
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = 0;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = 0;
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = _hc0[1]*_t179 + _hc0[1]*_t181 + _hc0[13]*_t4 + 0.6e1*_hc0[4]*_t97 + _hc0[5]*_t138 + _hc0[5]*_t38*_t84 + 0.3e1*_hc0[8]*_t33 + _hc0[9]*_t12 + _hc0[9]*_t16 + _hc1[1]*_t180 + _hc1[13]*_t3 + 0.3e1*_hc1[8]*_t24 + _hc1[9]*_t15 + _t10*(-_hc0[13] - _hc1[13]) + _t100*_t167 + _t100*_t175 + _t101*_t139 + _t103*(-_t130 - _t139) + _t127*_t193 + _t130*_t78 + _t130*_t80 + _t130*_t88 + _t136*_t31 + _t139*_t77 + _t139*_t82 + 0.6e1*_t146*_t174 + _t147*_t99 + _t149*_t188 + _t152*_t92 + _t154*_t93 + _t155*_t93 + _t159*_t92 + _t160*_t96 + _t161*_t96 + _t162*_t92 + _t168*_t93 + _t169*_t31 + _t170*_t93 + _t171*_t92 + _t172*_t85 + _t173*_t92 + _t174*_t36*_t89 + _t176*_t93 + _t178*_t92 + _t182*_t36 + _t183*_t36 + _t184*_t185 + _t184*_t72 + _t185*_t190 + _t186*_t90 + 0.2e1*_t187*_t79 + _t190*_t72 + _t191*_t87 + _t192*_t34*_t90 + _t23*_t86*_t93 + _t35*(-_t158 - _t166) + _t50*_t94 + _t62*_t95 + _t64*_t98 + _t72*_t89*_t92 + _t74*_t95 + _t76*_t98;
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = 0;
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = _hc0[14]*_t4 + 0.12e2*_hc0[5]*_t97 + _hc0[9]*_t164*_t2 + 0.4e1*_hc0[9]*_t33 + _hc1[14]*_t3 + 0.8e1*_hc1[2]*_t31*_t86 + 0.4e1*_hc1[9]*_t24 + _t10*(-_hc0[14] - _hc1[14]) + _t101*_t194 + _t103*(-_t95 - _t98) + _t126*_t193*(-_t163 - _t164) + _t163*_t179 + _t163*_t181 + _t163*_t186*_t29 + _t163*_t192*_t91 + _t164*_t180 + 0.12e2*_t174*_t188 + _t182*_t196 + _t183*_t196 + _t184*_t197 + _t184*_t198 + 0.3e1*_t187*_t94 + 0.8e1*_t188*_t85 + _t190*_t197 + _t190*_t198 + 0.2e1*_t191*_t99 + _t194*_t77 + _t194*_t82 + _t195*_t80 + _t195*_t88 + _t35*(-0.2e1*_hc0[9] - 0.2e1*_hc1[9]);
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
  if(!(_t7)) XC_CAT(sa_f_pf_k, _KMAX)(p, _t5*sigma_ss, 0, _t6*tau_s, _hc1);
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