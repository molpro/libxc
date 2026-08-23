/*
  Generated from python/mgga_exc/mgga_x_tpss.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_tpss
*/

#ifndef _MGGA_X_TPSS_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_TPSS_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_TPSS_HELPER_BODIES
#include "mgga_x_tpss.c"
#undef _MGGA_X_TPSS_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_TPSS_HELPER_BODIES
#include "mgga_x_tpss.c"
#undef _MGGA_X_TPSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_TPSS_HELPER_BODIES
#include "mgga_x_tpss.c"
#undef _MGGA_X_TPSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_TPSS_HELPER_BODIES
#include "mgga_x_tpss.c"
#undef _MGGA_X_TPSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_TPSS_HELPER_BODIES
#include "mgga_x_tpss.c"
#undef _MGGA_X_TPSS_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_tpss.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_TPSS_HELPER_BODIES)

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
  const mgga_x_tpss_params *params = (const mgga_x_tpss_params *)(p->params);


  const double f = params->BLOC_a + params->BLOC_b*z;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = params->BLOC_b;
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
  const mgga_x_tpss_params *params = (const mgga_x_tpss_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3)*xc_powr(params->e, 1, 2)/(M_PI * M_CBRTPI);
  const double _t2 = (0.1e1 / 0.24e2)*_t1*x2 + 0.1e1;

  const double f = (_t2 * _t2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = (0.1e1 / 0.12e2)*_t1*_t2;
  out[1] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = (0.1e1 / 0.288e3)*xc_powr(0.6e1, 2, 3)*params->e/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
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
  const mgga_x_tpss_params *params = (const mgga_x_tpss_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mgga_alpha_pf_k, _KMAX)(p, x2, t, _hc0);
  const double _t1 = (0.1e1 / 0.36e2)*xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = (0.9e1 / 0.20e2)*_hc0[0] - 0.9e1 / 0.20e2;
  const double _t3 = _hc0[0] - 0.1e1;
  const double _t4 = _hc0[0]*params->b;
  const double _t5 = _t3*_t4 + 0.1e1;
  const double _t6 = xc_powr(_t5, -1, 2);
#if _KMAX >= 1
  const double _t7 = (0.9e1 / 0.20e2)*_t6;
  const double _t8 = (0.1e1 / 0.2e1)*_hc0[1];
  const double _t9 = _t3*params->b;
  const double _t10 = -_t4*_t8 - _t8*_t9;
  const double _t11 = xc_powr(_t5, -3, 2);
  const double _t12 = _t11*_t2;
  const double _t13 = (0.1e1 / 0.2e1)*_hc0[2];
  const double _t14 = -_t13*_t4 - _t13*_t9;
#endif
#if _KMAX >= 2
  const double _t15 = ((_hc0[1]) * (_hc0[1]));
  const double _t16 = _t12*params->b;
  const double _t17 = _hc0[1]*_t11;
  const double _t18 = xc_powr(_t5, -5, 2);
  const double _t19 = _t18*_t2;
  const double _t20 = (0.3e1 / 0.2e1)*_hc0[1];
  const double _t21 = -_t20*_t4 - _t20*_t9;
  const double _t22 = _t10*_t21;
  const double _t23 = _hc0[1]*_hc0[2];
  const double _t24 = _hc0[2]*_t11;
  const double _t25 = _t14*_t19;
  const double _t26 = ((_hc0[2]) * (_hc0[2]));
  const double _t27 = (0.3e1 / 0.2e1)*_hc0[2];
  const double _t28 = -_t27*_t4 - _t27*_t9;
#endif
#if _KMAX >= 3
  const double _t29 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t30 = (0.27e2 / 0.20e2)*params->b;
  const double _t31 = _t11*_t30;
  const double _t32 = _t15*_t19;
  const double _t33 = _t21*params->b;
  const double _t34 = 0.2e1*_t33;
  const double _t35 = _t10*params->b;
  const double _t36 = xc_powr(_t5, -7, 2);
  const double _t37 = (0.5e1 / 0.2e1)*_hc0[1];
  const double _t38 = -_t37*_t4 - _t37*_t9;
  const double _t39 = _t15*_t30;
  const double _t40 = _t19*_t23;
  const double _t41 = _t15*params->b;
  const double _t42 = 0.3e1*_t25;
  const double _t43 = _t28*params->b;
  const double _t44 = _t19*_t26;
  const double _t45 = _t23*params->b;
  const double _t46 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t47 = 0.2e1*_t43;
  const double _t48 = _t26*params->b;
  const double _t49 = (0.5e1 / 0.2e1)*_hc0[2];
  const double _t50 = -_t4*_t49 - _t49*_t9;
#endif
#if _KMAX >= 4
  const double _t51 = ((params->b) * (params->b));
  const double _t52 = _t18*_t29;
  const double _t53 = (0.18e2 / 0.5e1)*_t33;
  const double _t54 = _t2*_t36;
  const double _t55 = _t38*_t54;
  const double _t56 = _t15*_t55;
  const double _t57 = 0.3e1*_t33;
  const double _t58 = 0.5e1*_t54;
  const double _t59 = _t41*_t58;
  const double _t60 = xc_powr(_t5, -9, 2);
  const double _t61 = (0.7e1 / 0.2e1)*_hc0[1];
  const double _t62 = -_t4*_t61 - _t61*_t9;
  const double _t63 = _t14*params->b;
  const double _t64 = _hc0[2]*_t18;
  const double _t65 = _t15*_t64;
  const double _t66 = _t14*_t55;
  const double _t67 = 0.6e1*_t66;
  const double _t68 = _hc0[1]*_t18;
  const double _t69 = _t26*_t33;
  const double _t70 = (0.27e2 / 0.5e1)*_t63;
  const double _t71 = _t47*_t55;
  const double _t72 = _t14*_t28;
  const double _t73 = _t18*_t46;
  const double _t74 = _t50*_t54;
  const double _t75 = _t43*_t74;
  const double _t76 = _t63*_t74;
  const double _t77 = _t58*_t72;
  const double _t78 = (0.7e1 / 0.2e1)*_hc0[2];
#endif

  const double f = _t1*x2 + _t2*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1]*_t7 + _t10*_t12;
  out[1] = df_dt;
  const double df_dx2 = _hc0[2]*_t7 + _t1 + _t12*_t14;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = (0.9e1 / 0.10e2)*_t10*_t17 - _t15*_t16 + _t19*_t22;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = (0.9e1 / 0.20e2)*_t10*_t24 + (0.9e1 / 0.20e2)*_t14*_t17 - _t16*_t23 + _t21*_t25;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = (0.9e1 / 0.10e2)*_t14*_t24 - _t16*_t26 + _t25*_t28;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = (0.27e2 / 0.20e2)*_hc0[1]*_t10*_t18*_t21 + _t10*_t2*_t21*_t36*_t38 - _t29*_t31 - _t32*_t34 - 0.3e1*_t32*_t35;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = (0.9e1 / 0.10e2)*_hc0[1]*_t14*_t18*_t21 + (0.9e1 / 0.20e2)*_hc0[2]*_t10*_t18*_t21 + _t14*_t2*_t21*_t36*_t38 - _t24*_t39 - _t34*_t40 - _t41*_t42;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = (0.9e1 / 0.20e2)*_hc0[1]*_t14*_t18*_t28 + (0.9e1 / 0.10e2)*_hc0[2]*_t14*_t18*_t21 + _t14*_t2*_t28*_t36*_t38 - _t17*_t26*_t30 - _t33*_t44 - _t40*_t43 - _t42*_t45;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = (0.27e2 / 0.20e2)*_hc0[2]*_t14*_t18*_t28 + _t14*_t2*_t28*_t36*_t50 - _t31*_t46 - _t42*_t48 - _t44*_t47;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.9e1*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t18*_t2*_t51 + (0.9e1 / 0.5e1)*_hc0[1]*_t10*_t21*_t36*_t38 + _t10*_t2*_t21*_t38*_t60*_t62 - _t22*_t59 - 0.27e2 / 0.5e1*_t35*_t52 - 0.6e1*_t35*_t56 - _t52*_t53 - _t56*_t57;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = (0.27e2 / 0.20e2)*_hc0[1]*_t14*_t21*_t36*_t38 + (0.9e1 / 0.20e2)*_hc0[2]*_t10*_t21*_t36*_t38 + 0.9e1*_hc0[2]*_t18*_t2*_t29*_t51 - _t10*_t39*_t64 - _t14*_t15*_t33*_t58 + _t14*_t2*_t21*_t38*_t60*_t62 - _t23*_t55*_t57 - _t41*_t67 - 0.81e2 / 0.20e2*_t52*_t63 - _t53*_t65;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = (0.9e1 / 0.10e2)*_hc0[1]*_t14*_t28*_t36*_t38 + (0.9e1 / 0.10e2)*_hc0[2]*_t14*_t21*_t36*_t38 + _t14*_t2*_t28*_t38*_t60*_t62 + 0.9e1*_t15*_t18*_t2*_t26*_t51 - _t23*_t71 - 0.9e1 / 0.10e2*_t43*_t65 - _t45*_t67 - _t55*_t69 - _t59*_t72 - _t65*_t70 - 0.27e2 / 0.10e2*_t68*_t69;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = (0.9e1 / 0.20e2)*_hc0[1]*_t14*_t28*_t36*_t50 + 0.9e1*_hc0[1]*_t18*_t2*_t46*_t51 + (0.27e2 / 0.20e2)*_hc0[2]*_t14*_t28*_t36*_t38 + _t14*_t2*_t28*_t50*_t60*_t62 - _t21*_t30*_t73 - _t23*_t75 - 0.3e1*_t23*_t76 - _t26*_t68*_t70 - _t26*_t71 - 0.9e1 / 0.4e1*_t28*_t48*_t68 - _t45*_t77 - 0.3e1*_t48*_t66;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 0.9e1*((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t18*_t2*_t51 + (0.9e1 / 0.5e1)*_hc0[2]*_t14*_t28*_t36*_t50 + _t14*_t2*_t28*_t50*_t60*(-_t4*_t78 - _t78*_t9) - 0.3e1*_t26*_t75 - 0.6e1*_t26*_t76 - 0.18e2 / 0.5e1*_t43*_t73 - _t48*_t77 - _t70*_t73;
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
  const mgga_x_tpss_params *params = (const mgga_x_tpss_params *)(p->params);


  const double f = params->kappa;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_dx2 = 0;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_fxnum_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {
  const mgga_x_tpss_params *params = (const mgga_x_tpss_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_qb_pf_k, _KMAX)(p, x2, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_z_pf_k, _KMAX)(p, x2, t, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tpss_ff_k, _KMAX)(p, _hc1[0], _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_kappa_pf_k, _KMAX)(p, 0, 0, _hc3);
  const double _t1 = ((_hc1[0]) * (_hc1[0]));
  const double _t2 = xc_powr(params->e, 1, 2);
  const double _t3 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t4 = _t3*params->e*params->mu;
  const double _t5 = (x2 * x2);
  const double _t6 = xc_powr(0.6e1, 2, 3)/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t7 = _t6/_hc3[0];
  const double _t8 = (0.1e1 / 0.1152e4)*_t6;
  const double _t9 = (0.9e1 / 0.50e2)*_t1 + _t5*_t8;
  const double _t10 = xc_powr(_t9, 1, 2);
  const double _t11 = (0.73e2 / 0.405e3)*_t10;
  const double _t12 = _t1 + 0.1e1;
  const double _t13 = (0.1e1 / (_t12 * _t12));
  const double _t14 = pow(_hc1[0], _hc2[0]);
  const double _t15 = _t14*params->c;
  const double _t16 = _t13*_t15;
  const double _t17 = xc_powr(0.6e1, 1, 3);
  const double _t18 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t19 = _t17*_t18;
  const double _t20 = (0.1e1 / 0.24e2)*_t19;
  const double _t21 = _t20*(_t16 + 0.10e2 / 0.81e2);
#if _KMAX >= 1
  const double _t22 = (0.292e3 / 0.2025e4)*_hc0[0];
  const double _t23 = (0.8e1 / 0.45e2)*_t2;
  const double _t24 = _hc1[0]*_t23;
  const double _t25 = _hc1[0]*_hc1[1];
  const double _t26 = (0.1e1 / _t10);
  const double _t27 = _hc0[0]*_t26;
  const double _t28 = (0.73e2 / 0.2250e4)*_t27;
  const double _t29 = _t15/(_t12 * _t12 * _t12);
  const double _t30 = 0.4e1*_t29;
  const double _t31 = _t25*_t30;
  const double _t32 = _hc2[1]*log(_hc1[0]);
  const double _t33 = (0.1e1 / (_hc1[0]));
  const double _t34 = _hc2[0]*_t33;
  const double _t35 = _hc1[1]*_t32 + _hc1[1]*_t34;
  const double _t36 = _t20*(_t13*_t14*_t35*params->c - _t31);
  const double _t37 = _hc1[0]*_hc1[2];
  const double _t38 = (0.25e2 / 0.472392e6)*_t7;
  const double _t39 = (0.9e1 / 0.50e2)*_hc1[0];
  const double _t40 = _hc1[2]*_t39 + _t8*x2;
  const double _t41 = (0.73e2 / 0.405e3)*_t40;
  const double _t42 = _t30*_t37;
  const double _t43 = _hc1[2]*_t32 + _hc1[2]*_t34;
  const double _t44 = _t13*_t14*_t43*params->c - _t42;
  const double _t45 = _t20*x2;
#endif
#if _KMAX >= 2
  const double _t46 = ((_hc1[1]) * (_hc1[1]));
  const double _t47 = _hc1[0]*_hc1[3];
  const double _t48 = _hc0[1]*_t26;
  const double _t49 = (0.73e2 / 0.1125e4)*_t25;
  const double _t50 = (0.73e2 / 0.2250e4)*_t46;
  const double _t51 = xc_powr(_t9, -3, 2);
  const double _t52 = _hc0[0]*_t51;
  const double _t53 = _t1*_t46;
  const double _t54 = (0.73e2 / 0.12500e5)*_t53;
  const double _t55 = _t30*_t47;
  const double _t56 = _t30*_t46;
  const double _t57 = (0.1e1 / (_t12 * _t12 * _t12 * _t12));
  const double _t58 = _t15*_t57;
  const double _t59 = 0.24e2*_t58;
  const double _t60 = (_t35 * _t35);
  const double _t61 = _t16*_t60;
  const double _t62 = 0.8e1*_t29;
  const double _t63 = _t25*_t62;
  const double _t64 = _t35*_t63;
  const double _t65 = _hc1[3]*_t32;
  const double _t66 = _hc1[3]*_t34;
  const double _t67 = (0.1e1 / _t1);
  const double _t68 = _hc2[0]*_t67;
  const double _t69 = _t46*_t68;
  const double _t70 = _hc2[1]*_t33;
  const double _t71 = 0.2e1*_t46;
  const double _t72 = _t65 + _t66 - _t69 + _t70*_t71;
  const double _t73 = _t16*_t72;
  const double _t74 = _t20*(_t53*_t59 - _t55 - _t56 + _t61 - _t64 + _t73);
  const double _t75 = (0.292e3 / 0.2025e4)*_hc0[2];
  const double _t76 = _hc1[1]*_hc1[2];
  const double _t77 = _hc0[2]*_t26;
  const double _t78 = (0.73e2 / 0.2250e4)*_t77;
  const double _t79 = (0.9e1 / 0.50e2)*_hc1[2];
  const double _t80 = _hc1[1]*_t79 + _hc1[4]*_t39;
  const double _t81 = (0.73e2 / 0.405e3)*_t27;
  const double _t82 = (0.73e2 / 0.2250e4)*_t25;
  const double _t83 = _t40*_t52;
  const double _t84 = _hc1[0]*_t30;
  const double _t85 = _t31*_t43;
  const double _t86 = _t35*_t42;
  const double _t87 = _hc1[4]*_t32;
  const double _t88 = _hc1[4]*_t34;
  const double _t89 = _t68*_t76;
  const double _t90 = 0.2e1*_t70;
  const double _t91 = _t76*_t90 + _t87 + _t88 - _t89;
  const double _t92 = 0.24e2*_hc1[1]*_hc1[2]*_t1*_t14*_t57*params->c - _hc1[4]*_t84 + _t13*_t14*_t35*_t43*params->c + _t13*_t14*_t91*params->c - _t30*_t76 - _t85 - _t86;
  const double _t93 = ((_hc1[2]) * (_hc1[2]));
  const double _t94 = _t8 + (0.9e1 / 0.50e2)*_t93;
  const double _t95 = (0.146e3 / 0.405e3)*_t40;
  const double _t96 = (0.1e1 / 0.12e2)*_t19;
  const double _t97 = -_t40;
  const double _t98 = _t52*_t97;
  const double _t99 = _t30*_t93;
  const double _t100 = (_t43 * _t43);
  const double _t101 = _t100*_t16;
  const double _t102 = _t37*_t62;
  const double _t103 = _t102*_t43;
  const double _t104 = _t68*_t93;
  const double _t105 = _t70*_t93;
  const double _t106 = -_t104 + 0.2e1*_t105;
  const double _t107 = _t106*_t16;
  const double _t108 = _t1*_t59*_t93 + _t101 - _t103 + _t107 - _t99;
#endif
#if _KMAX >= 3
  const double _t109 = (0.292e3 / 0.675e3)*_hc0[1];
  const double _t110 = (0.8e1 / 0.15e2)*_t2;
  const double _t111 = _hc1[1]*_t110;
  const double _t112 = _hc1[0]*_hc1[6];
  const double _t113 = (0.73e2 / 0.750e3)*_t27;
  const double _t114 = _hc1[1]*_hc1[3];
  const double _t115 = (0.73e2 / 0.750e3)*_t47;
  const double _t116 = _hc0[3]*_t26;
  const double _t117 = (0.73e2 / 0.750e3)*_t25;
  const double _t118 = (0.73e2 / 0.750e3)*_t46;
  const double _t119 = (0.219e3 / 0.12500e5)*_t52;
  const double _t120 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t121 = _hc1[0]*_t120;
  const double _t122 = _t1*_t119;
  const double _t123 = xc_powr(_t9, -5, 2);
  const double _t124 = _hc0[0]*_t123;
  const double _t125 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t126 = _t120*_t125;
  const double _t127 = (0.1971e4 / 0.625000e6)*_t126;
  const double _t128 = _hc0[1]*_t51;
  const double _t129 = (0.219e3 / 0.12500e5)*_t53;
  const double _t130 = _t112*_t30;
  const double _t131 = 0.12e2*_t29;
  const double _t132 = _t114*_t131;
  const double _t133 = _t15/xc_powi(_t12, 5);
  const double _t134 = 0.192e3*_t133;
  const double _t135 = _t126*_t134;
  const double _t136 = (_t35 * _t35 * _t35);
  const double _t137 = _t131*_t47;
  const double _t138 = _t137*_t35;
  const double _t139 = _t131*_t46;
  const double _t140 = _t139*_t35;
  const double _t141 = _t131*_t25;
  const double _t142 = _t141*_t60;
  const double _t143 = _t141*_t72;
  const double _t144 = _t46*_t70;
  const double _t145 = 0.4e1*_t144 + 0.2e1*_t65 + 0.2e1*_t66 - 0.2e1*_t69;
  const double _t146 = _hc1[6]*_t32;
  const double _t147 = _hc1[6]*_t34;
  const double _t148 = 0.3e1*_t68;
  const double _t149 = 0.6e1*_t70;
  const double _t150 = (0.1e1 / _t125);
  const double _t151 = _hc2[0]*_t150;
  const double _t152 = 0.2e1*_t151;
  const double _t153 = _hc2[1]*_t67;
  const double _t154 = 0.3e1*_t153;
  const double _t155 = -_t114*_t148 + _t114*_t149 + _t120*_t152 - _t120*_t154 + _t146 + _t147;
  const double _t156 = _t20*(0.72e2*_hc1[0]*_t120*_t14*_t57*params->c + 0.72e2*_hc1[1]*_hc1[3]*_t1*_t14*_t57*params->c + 0.72e2*_t1*_t14*_t35*_t46*_t57*params->c + _t13*_t136*_t14*params->c + _t13*_t14*_t145*_t35*params->c + _t13*_t14*_t155*params->c + _t13*_t14*_t35*_t72*params->c - _t130 - _t132 - _t135 - _t138 - _t140 - _t142 - _t143);
  const double _t157 = (0.584e3 / 0.2025e4)*_hc0[4];
  const double _t158 = _hc1[1]*_hc1[4];
  const double _t159 = (0.16e2 / 0.45e2)*_t2;
  const double _t160 = _hc1[2]*_hc1[3];
  const double _t161 = _hc0[4]*_t26;
  const double _t162 = _hc0[2]*_t51;
  const double _t163 = (0.146e3 / 0.405e3)*_t80;
  const double _t164 = _t52*_t80;
  const double _t165 = _hc1[3]*_t79 + _hc1[7]*_t39 + (0.9e1 / 0.25e2)*_t158;
  const double _t166 = (0.73e2 / 0.2250e4)*_t83;
  const double _t167 = _t128*_t40;
  const double _t168 = _t50*_t52;
  const double _t169 = _t124*_t40;
  const double _t170 = _hc1[2]*_t46;
  const double _t171 = _t125*_t134;
  const double _t172 = _t35*_t62;
  const double _t173 = _hc1[0]*_hc1[4];
  const double _t174 = _hc1[7]*_t32;
  const double _t175 = _hc1[7]*_t34;
  const double _t176 = 0.2e1*_t68;
  const double _t177 = _t160*_t68;
  const double _t178 = 0.4e1*_t70;
  const double _t179 = _hc1[2]*_t151;
  const double _t180 = -_t154*_t170 - _t158*_t176 + _t158*_t178 + _t160*_t90 + _t174 + _t175 - _t177 + _t179*_t71;
  const double _t181 = 0.72e2*_hc1[0]*_hc1[2]*_t14*_t46*_t57*params->c + 0.48e2*_hc1[1]*_hc1[2]*_t1*_t14*_t35*_t57*params->c + 0.48e2*_hc1[1]*_hc1[4]*_t1*_t14*_t57*params->c + 0.24e2*_hc1[2]*_hc1[3]*_t1*_t14*_t57*params->c - _hc1[7]*_t84 + 0.24e2*_t1*_t14*_t43*_t46*_t57*params->c + _t13*_t14*_t180*params->c + 0.2e1*_t13*_t14*_t35*_t91*params->c + _t13*_t14*_t43*_t60*params->c + _t13*_t14*_t43*_t72*params->c - _t158*_t62 - _t160*_t30 - _t170*_t171 - _t172*_t173 - _t172*_t76 - _t42*_t60 - _t42*_t72 - _t43*_t55 - _t43*_t56 - _t43*_t64 - _t63*_t91;
  const double _t182 = (0.292e3 / 0.2025e4)*_hc0[5];
  const double _t183 = _hc1[2]*_hc1[4];
  const double _t184 = _hc0[5]*_t26;
  const double _t185 = (0.73e2 / 0.2250e4)*_t184;
  const double _t186 = (0.73e2 / 0.405e3)*_t94;
  const double _t187 = _t52*_t94;
  const double _t188 = _t162*_t40;
  const double _t189 = (0.73e2 / 0.405e3)*_t98;
  const double _t190 = -_t80;
  const double _t191 = _t41*_t52;
  const double _t192 = _t128*_t97;
  const double _t193 = _t40*_t97;
  const double _t194 = _t124*_t193;
  const double _t195 = _hc1[1]*_t93;
  const double _t196 = _t43*_t62;
  const double _t197 = _t152*_t195 - _t154*_t195 - _t176*_t183 + _t178*_t183;
  const double _t198 = _t178*_t76 + 0.2e1*_t87 + 0.2e1*_t88 - 0.2e1*_t89;
  const double _t199 = 0.72e2*_hc1[0]*_hc1[1]*_t14*_t57*_t93*params->c + 0.48e2*_hc1[1]*_hc1[2]*_t1*_t14*_t43*_t57*params->c + 0.48e2*_hc1[2]*_hc1[4]*_t1*_t14*_t57*params->c + 0.24e2*_t1*_t14*_t35*_t57*_t93*params->c + _t100*_t13*_t14*_t35*params->c - _t100*_t31 - _t102*_t91 - _t103*_t35 + _t106*_t13*_t14*_t35*params->c - _t106*_t31 + _t13*_t14*_t197*params->c + _t13*_t14*_t198*_t43*params->c - _t171*_t195 - _t173*_t196 - _t183*_t62 - _t196*_t76 - _t35*_t99;
  const double _t200 = (0.73e2 / 0.135e3)*_t94;
  const double _t201 = (0.73e2 / 0.135e3)*_t40;
  const double _t202 = -_t94;
  const double _t203 = (0.146e3 / 0.405e3)*_t94;
  const double _t204 = _t162*_t97;
  const double _t205 = _t41*_t97;
  const double _t206 = (0.27e2 / 0.50e2)*_hc1[0];
  const double _t207 = (0.1e1 / 0.384e3)*_t6;
  const double _t208 = -_hc1[2]*_t206 - _t207*x2;
  const double _t209 = _t124*_t208;
  const double _t210 = 0.72e2*_t58;
  const double _t211 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t212 = _hc1[0]*_t211;
  const double _t213 = _t210*_t212;
  const double _t214 = _t171*_t211;
  const double _t215 = (_t43 * _t43 * _t43);
  const double _t216 = _t131*_t93;
  const double _t217 = _t216*_t43;
  const double _t218 = _t131*_t37;
  const double _t219 = _t100*_t218;
  const double _t220 = 0.2e1*_hc2[0]*_t150*_t211 - _t154*_t211;
  const double _t221 = _t1*_t210;
  const double _t222 = _t221*_t93;
  const double _t223 = _t222*_t43;
  const double _t224 = _t106*_t218;
  const double _t225 = _t16*_t43;
  const double _t226 = -0.2e1*_t104 + 0.4e1*_t105;
  const double _t227 = _t106*_t225 + _t16*_t215 + _t16*_t220 + _t213 - _t214 - _t217 - _t219 + _t223 - _t224 + _t225*_t226;
#endif
#if _KMAX >= 4
  const double _t228 = _hc1[1]*_hc1[6];
  const double _t229 = ((_hc1[3]) * (_hc1[3]));
  const double _t230 = _hc1[0]*_hc1[10];
  const double _t231 = (0.146e3 / 0.1125e4)*_t48;
  const double _t232 = (0.73e2 / 0.375e3)*_t116;
  const double _t233 = _hc0[6]*_t26;
  const double _t234 = (0.146e3 / 0.1125e4)*_t25;
  const double _t235 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t236 = (0.219e3 / 0.3125e4)*_t128;
  const double _t237 = _t46*_t47;
  const double _t238 = _t1*_t228;
  const double _t239 = (0.73e2 / 0.3125e4)*_t52;
  const double _t240 = _t1*_t114;
  const double _t241 = _t1*_t235;
  const double _t242 = (0.5913e4 / 0.312500e6)*_t124;
  const double _t243 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t244 = _t235*_t243;
  const double _t245 = xc_powr(_t9, -7, 2);
  const double _t246 = _hc0[0]*_t245;
  const double _t247 = _hc0[1]*_t123;
  const double _t248 = _hc0[3]*_t51;
  const double _t249 = (0.219e3 / 0.6250e4)*_t53;
  const double _t250 = _hc1[3]*_t46;
  const double _t251 = _t125*_t250;
  const double _t252 = 0.16e2*_t29;
  const double _t253 = 0.1152e4*_t133;
  const double _t254 = xc_powi(_t12, -6);
  const double _t255 = 0.1920e4*_t15*_t254;
  const double _t256 = _t252*_t35;
  const double _t257 = _t25*_t252;
  const double _t258 = 0.288e3*_t58;
  const double _t259 = _t258*_t35;
  const double _t260 = 0.24e2*_t29;
  const double _t261 = _t260*_t47;
  const double _t262 = _t260*_t46;
  const double _t263 = 0.768e3*_t133;
  const double _t264 = 0.144e3*_t53*_t58;
  const double _t265 = _t257*_t35;
  const double _t266 = _t16*_t35;
  const double _t267 = 0.4e1*_t151;
  const double _t268 = 0.6e1*_t153;
  const double _t269 = 0.4e1*_t68;
  const double _t270 = 0.8e1*_t70;
  const double _t271 = 0.6e1*_hc2[0]/_t243;
  const double _t272 = 0.8e1*_hc2[1]*_t150;
  const double _t273 = _hc1[2]*_hc1[6];
  const double _t274 = _hc1[3]*_hc1[4];
  const double _t275 = (0.73e2 / 0.750e3)*_t114;
  const double _t276 = _hc0[7]*_t26;
  const double _t277 = (0.219e3 / 0.12500e5)*_t162;
  const double _t278 = _hc0[2]*_t123;
  const double _t279 = _hc0[4]*_t51;
  const double _t280 = (0.73e2 / 0.135e3)*_t80;
  const double _t281 = (0.73e2 / 0.375e3)*_t25;
  const double _t282 = (0.657e3 / 0.12500e5)*_t53;
  const double _t283 = _t124*_t80;
  const double _t284 = (0.27e2 / 0.50e2)*_hc1[1];
  const double _t285 = (0.657e3 / 0.12500e5)*_t169;
  const double _t286 = _hc1[1]*_hc1[7];
  const double _t287 = _hc1[3]*_t76;
  const double _t288 = _t125*_t133;
  const double _t289 = 0.576e3*_t288;
  const double _t290 = _hc1[2]*_t120;
  const double _t291 = _t1*_t253;
  const double _t292 = _hc1[4]*_t46;
  const double _t293 = _t131*_t35;
  const double _t294 = _hc1[0]*_hc1[7];
  const double _t295 = _t260*_t35;
  const double _t296 = _t131*_t173;
  const double _t297 = _t131*_t76;
  const double _t298 = 0.6e1*_t151;
  const double _t299 = 0.9e1*_t153;
  const double _t300 = _hc1[2]*_hc1[7];
  const double _t301 = ((_hc1[4]) * (_hc1[4]));
  const double _t302 = _hc0[8]*_t26;
  const double _t303 = _hc0[5]*_t51;
  const double _t304 = (0.73e2 / 0.1125e4)*_t188;
  const double _t305 = _t190*_t52;
  const double _t306 = _hc1[2]*_t158;
  const double _t307 = _t125*_t263;
  const double _t308 = _hc1[3]*_t93;
  const double _t309 = 0.384e3*_t288;
  const double _t310 = _t256*_t43;
  const double _t311 = _t252*_t91;
  const double _t312 = _t198*_t43;
  const double _t313 = _t46*_t93;
  const double _t314 = _hc0[9]*_t26;
  const double _t315 = _t209*_t97;
  const double _t316 = _t124*_t205;
  const double _t317 = _t205*_t208;
  const double _t318 = _hc1[1]*_t211;
  const double _t319 = _hc1[4]*_t93;
  const double _t320 = 0.216e3*_t58;
  const double _t321 = _t243*_t255;
  const double _t322 = _t183*_t43;
  const double _t323 = 0.144e3*_t1*_t58;
  const double _t324 = _t221*_t76;
  const double _t325 = _t266*_t43;
  const double _t326 = _t16*_t91;
  const double _t327 = (0.292e3 / 0.405e3)*_t40;
  const double _t328 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t329 = _t252*_t37;
  const double _t330 = _t260*_t93;
  const double _t331 = _t323*_t93;
  const double _t332 = _t329*_t43;
#endif

  const double f = (0.146e3 / 0.2025e4)*((_hc0[0]) * (_hc0[0])) - _hc0[0]*_t11 + (0.4e1 / 0.45e2)*_t1*_t2 + _t21*x2 + (0.1e1 / 0.2304e4)*_t4*(x2 * x2 * x2) + (0.25e2 / 0.944784e6)*_t5*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_hc0[1]*_t11 + _hc0[1]*_t22 + _hc1[1]*_t24 - _t25*_t28 + _t36*x2;
  out[1] = df_dt;
  const double df_dx2 = -_hc0[2]*_t11 + _hc0[2]*_t22 + _t21 + _t23*_t37 - _t27*_t41 + _t38*x2 + (0.1e1 / 0.768e3)*_t4*_t5 + _t44*_t45;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = (0.292e3 / 0.2025e4)*((_hc0[1]) * (_hc0[1])) - _hc0[3]*_t11 + _hc0[3]*_t22 + _hc1[3]*_t24 + _t23*_t46 - _t27*_t50 - _t28*_t47 - _t48*_t49 + _t52*_t54 + _t74*x2;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = _hc0[1]*_t75 - _hc0[4]*_t11 + _hc0[4]*_t22 + _hc1[4]*_t24 + _t23*_t76 - _t25*_t78 + _t36 - _t41*_t48 + _t45*_t92 - _t80*_t81 + _t82*_t83;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = (0.292e3 / 0.2025e4)*((_hc0[2]) * (_hc0[2])) - _hc0[5]*_t11 + _hc0[5]*_t22 + _t108*_t45 + _t23*_t93 + _t38 + (0.1e1 / 0.384e3)*_t4*x2 - _t41*_t98 + _t44*_t96 - _t77*_t95 - _t81*_t94;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[3]*_t109 - _hc0[6]*_t11 + _hc0[6]*_t22 + _hc1[3]*_t111 + _hc1[6]*_t24 - _t112*_t28 - _t113*_t114 + _t114*_t122 - _t115*_t48 - _t116*_t117 - _t118*_t48 + _t119*_t121 - _t124*_t127 + _t128*_t129 + _t156*x2;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = _hc0[1]*_t157 + _hc0[3]*_t75 - _hc0[7]*_t11 + _hc0[7]*_t22 + _hc1[7]*_t24 - _t116*_t41 - _t129*_t169 + _t158*_t159 + _t160*_t23 - _t161*_t49 + _t162*_t54 - _t163*_t48 + _t164*_t49 - _t165*_t81 + _t166*_t47 + _t167*_t49 + _t168*_t40 + _t181*_t45 - _t47*_t78 - _t50*_t77 + _t74;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = _hc0[1]*_t182 + _hc0[2]*_t157 - _hc0[8]*_t11 + _hc0[8]*_t22 + _t117*_t194 + _t159*_t183 - _t161*_t95 - _t163*_t77 - 0.73e2 / 0.1125e4*_t183*_t27 - _t185*_t25 - _t186*_t48 + _t187*_t82 + _t188*_t49 - _t189*_t80 - _t190*_t191 - _t192*_t41 + _t199*_t45 + _t92*_t96;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = (0.292e3 / 0.2025e4)*_hc0[0]*_hc0[9] + (0.292e3 / 0.675e3)*_hc0[2]*_hc0[5] - _hc0[9]*_t11 + (0.1e1 / 0.8e1)*_t108*_t17*_t18 + (0.1e1 / 0.24e2)*_t17*_t18*_t227*x2 - _t184*_t201 - _t191*_t202 - _t200*_t77 - _t201*_t204 - _t203*_t98 - _t205*_t209 + (0.1e1 / 0.384e3)*_t3*params->e*params->mu;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = (0.1168e4 / 0.2025e4)*_hc0[1]*_hc0[6] - _hc0[10]*_t11 + _hc0[10]*_t22 + (0.292e3 / 0.675e3)*((_hc0[3]) * (_hc0[3])) + _hc1[10]*_t24 + _t110*_t229 - _t112*_t231 - _t113*_t229 - 0.146e3 / 0.375e3*_t114*_t48 + _t119*_t235 + _t121*_t236 + _t122*_t229 - 0.1971e4 / 0.156250e6*_t126*_t247 + (0.32e2 / 0.45e2)*_t2*_t228 - 0.146e3 / 0.1125e4*_t228*_t27 - _t230*_t28 - _t232*_t46 - _t232*_t47 - _t233*_t234 + _t236*_t240 + (0.657e3 / 0.6250e4)*_t237*_t52 + _t238*_t239 - _t241*_t242 - _t242*_t251 + (0.17739e5 / 0.6250000e7)*_t244*_t246 + _t248*_t249 + _t45*(-_t112*_t256 - 0.48e2*_t114*_t29*_t35 + _t121*_t259 - _t126*_t263*_t35 - _t131*_t229 - _t136*_t257 - _t145*_t265 + _t145*_t61 + _t145*_t73 - _t155*_t257 + 0.2e1*_t155*_t266 + _t16*(_t35 * _t35 * _t35 * _t35) + _t16*(_t72 * _t72) + _t16*(_hc1[10]*_t32 + _hc1[10]*_t34 - _t148*_t229 + _t149*_t229 + 0.12e2*_t151*_t250 - 0.18e2*_t153*_t250 - _t228*_t269 + _t228*_t270 - _t235*_t271 + _t235*_t272) + _t210*_t235 + _t221*_t229 - _t228*_t252 - _t230*_t30 + 0.432e3*_t237*_t58 + 0.96e2*_t238*_t58 + _t240*_t259 - _t241*_t253 + _t244*_t255 - _t251*_t253 - _t261*_t60 - _t261*_t72 - _t262*_t60 - _t262*_t72 + _t264*_t60 + _t264*_t72 - _t265*_t72 + _t266*(-0.6e1*_t114*_t68 + 0.12e2*_t114*_t70 + _t120*_t267 - _t120*_t268 + 0.2e1*_t146 + 0.2e1*_t147) + _t61*_t72 + _t61*(0.6e1*_t144 + 0.3e1*_t65 + 0.3e1*_t66 - 0.3e1*_t69));
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = -_hc0[11]*_t11 + _hc0[11]*_t22 + (0.292e3 / 0.675e3)*_hc0[3]*_hc0[4] + _hc0[6]*_t75 + _hc0[7]*_t109 + _hc1[11]*_t24 + _hc1[7]*_t111 + _t110*_t274 + _t112*_t166 - _t112*_t78 - _t115*_t161 + _t115*_t164 + _t115*_t167 - _t116*_t280 + _t117*_t165*_t52 + _t117*_t248*_t40 - _t117*_t276 - _t118*_t161 + _t118*_t164 + _t118*_t167 + _t121*_t277 - _t121*_t285 + (0.1971e4 / 0.125000e6)*_t126*_t246*_t40 - _t127*_t278 + _t128*_t281*_t80 + _t129*_t279 + _t156 - 0.73e2 / 0.135e3*_t165*_t48 + _t23*_t273 - _t233*_t41 + _t240*_t277 - _t240*_t285 - _t247*_t282*_t40 - _t275*_t77 + _t275*_t83 - _t282*_t283 + _t45*(0.216e3*_hc1[0]*_hc1[1]*_hc1[2]*_hc1[3]*_t14*_t57*params->c + 0.216e3*_hc1[0]*_hc1[2]*_t14*_t35*_t46*_t57*params->c + 0.216e3*_hc1[0]*_hc1[4]*_t14*_t46*_t57*params->c + 0.72e2*_hc1[0]*_t120*_t14*_t43*_t57*params->c + 0.72e2*_hc1[1]*_hc1[2]*_t1*_t14*_t57*_t60*params->c + 0.72e2*_hc1[1]*_hc1[2]*_t1*_t14*_t57*_t72*params->c + 0.72e2*_hc1[1]*_hc1[3]*_t1*_t14*_t43*_t57*params->c + 0.144e3*_hc1[1]*_hc1[4]*_t1*_t14*_t35*_t57*params->c + 0.72e2*_hc1[1]*_hc1[7]*_t1*_t14*_t57*params->c - _hc1[11]*_t84 + 0.72e2*_hc1[2]*_hc1[3]*_t1*_t14*_t35*_t57*params->c + 0.24e2*_hc1[2]*_hc1[6]*_t1*_t14*_t57*params->c + 0.1920e4*_hc1[2]*_t120*_t14*_t243*_t254*params->c + 0.72e2*_hc1[2]*_t120*_t14*_t57*params->c + 0.72e2*_hc1[3]*_hc1[4]*_t1*_t14*_t57*params->c + 0.72e2*_t1*_t14*_t35*_t43*_t46*_t57*params->c + 0.72e2*_t1*_t14*_t46*_t57*_t91*params->c + _t13*_t136*_t14*_t43*params->c + _t13*_t14*_t145*_t35*_t43*params->c + _t13*_t14*_t155*_t43*params->c + 0.3e1*_t13*_t14*_t180*_t35*params->c + _t13*_t14*_t35*_t43*_t72*params->c + 0.3e1*_t13*_t14*_t60*_t91*params->c + 0.3e1*_t13*_t14*_t72*_t91*params->c + _t13*_t14*params->c*(_hc1[11]*_t32 + _hc1[11]*_t34 - _t148*_t274 - _t148*_t286 + _t149*_t274 + _t149*_t286 - _t271*_t290 + _t272*_t290 - _t273*_t68 + _t273*_t90 + _t287*_t298 - _t287*_t299 + _t292*_t298 - _t292*_t299) - _t130*_t43 - _t131*_t274 - _t131*_t286 - _t132*_t43 - _t135*_t43 - _t136*_t42 - _t137*_t91 - _t138*_t43 - _t139*_t91 - _t140*_t43 - _t141*_t180 - _t142*_t43 - _t143*_t43 - _t145*_t86 - _t155*_t42 - _t158*_t295 - _t160*_t293 - _t170*_t289*_t35 - _t25*_t295*_t91 - _t273*_t30 - _t287*_t289 - _t289*_t292 - _t290*_t291 - _t293*_t294 - _t296*_t60 - _t296*_t72 - _t297*_t60 - _t297*_t72 - _t72*_t86) - _t81*(_hc1[11]*_t39 + _hc1[6]*_t79 + _hc1[7]*_t284 + (0.27e2 / 0.50e2)*_t274);
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = (0.584e3 / 0.2025e4)*_hc0[1]*_hc0[8] - _hc0[12]*_t11 + _hc0[12]*_t22 + (0.584e3 / 0.2025e4)*_hc0[2]*_hc0[7] + _hc0[3]*_t182 + (0.584e3 / 0.2025e4)*((_hc0[4]) * (_hc0[4])) + _t115*_t194 - _t116*_t186 + _t118*_t194 - _t124*_t129*_t94 - _t128*_t190*_t95 + _t128*_t49*_t94 + _t158*_t239*_t37 + _t159*_t300 + _t159*_t301 - 0.292e3 / 0.405e3*_t161*_t80 + _t162*_t234*_t80 - _t163*_t192 - _t163*_t305 - _t165*_t189 + _t165*_t191 - 0.146e3 / 0.405e3*_t165*_t77 + _t168*_t94 + _t169*_t190*_t281 + _t181*_t96 - _t183*_t231 - _t184*_t50 - _t185*_t47 + (0.73e2 / 0.2250e4)*_t187*_t47 - 0.219e3 / 0.2500e4*_t193*_t246*_t53 + _t193*_t247*_t281 - _t205*_t248 + _t234*_t279*_t40 - _t249*_t278*_t40 - _t276*_t95 + _t281*_t283*_t97 - _t302*_t49 + _t303*_t54 + _t304*_t46 + _t304*_t47 + _t45*(0.288e3*_hc1[0]*_hc1[1]*_hc1[2]*_hc1[4]*_t14*_t57*params->c + 0.144e3*_hc1[0]*_hc1[1]*_t14*_t35*_t57*_t93*params->c + 0.144e3*_hc1[0]*_hc1[2]*_t14*_t43*_t46*_t57*params->c + 0.72e2*_hc1[0]*_hc1[3]*_t14*_t57*_t93*params->c + 0.96e2*_hc1[1]*_hc1[2]*_t1*_t14*_t35*_t43*_t57*params->c + 0.96e2*_hc1[1]*_hc1[2]*_t1*_t14*_t57*_t91*params->c + 0.96e2*_hc1[1]*_hc1[4]*_t1*_t14*_t43*_t57*params->c + 0.48e2*_hc1[2]*_hc1[3]*_t1*_t14*_t43*_t57*params->c + 0.96e2*_hc1[2]*_hc1[4]*_t1*_t14*_t35*_t57*params->c + 0.48e2*_hc1[2]*_hc1[7]*_t1*_t14*_t57*params->c + 0.24e2*_t1*_t100*_t14*_t46*_t57*params->c + 0.24e2*_t1*_t106*_t14*_t46*_t57*params->c + 0.48e2*_t1*_t14*_t301*_t57*params->c + 0.24e2*_t1*_t14*_t57*_t60*_t93*params->c + 0.24e2*_t1*_t14*_t57*_t72*_t93*params->c + _t100*_t13*_t14*_t60*params->c + _t100*_t13*_t14*_t72*params->c - _t100*_t55 - _t100*_t56 - _t100*_t64 - _t102*_t180 - _t103*_t60 - _t103*_t72 + _t106*_t13*_t14*_t60*params->c + _t106*_t13*_t14*_t72*params->c - _t106*_t55 - _t106*_t56 - _t106*_t64 + 0.2e1*_t13*_t14*_t197*_t35*params->c + 0.2e1*_t13*_t14*_t198*_t35*_t43*params->c + _t13*_t14*_t198*_t91*params->c + _t13*_t14*_t43*params->c*(-_t158*_t269 + _t158*_t270 + _t160*_t178 + _t170*_t267 - _t170*_t268 + 0.2e1*_t174 + 0.2e1*_t175 - 0.2e1*_t177) + _t13*_t14*params->c*(_t152*_t308 - 0.12e2*_t153*_t306 - _t154*_t308 + 0.8e1*_t158*_t179 - _t176*_t300 - _t176*_t301 + _t178*_t300 + _t178*_t301 - _t271*_t313 + _t272*_t313) + 0.1920e4*_t14*_t243*_t254*_t46*_t93*params->c + 0.72e2*_t14*_t46*_t57*_t93*params->c - _t158*_t252*_t43 - _t160*_t196 - _t170*_t309*_t43 - _t171*_t308 - _t173*_t310 - _t173*_t311 - _t183*_t256 - _t195*_t309*_t35 - _t196*_t294 - _t197*_t63 - _t253*_t53*_t93 - _t256*_t37*_t91 - _t300*_t62 - _t301*_t62 - _t306*_t307 - _t310*_t76 - _t311*_t76 - _t312*_t63 - _t60*_t99 - _t72*_t99) - _t81*((0.9e1 / 0.25e2)*_t300 + (0.9e1 / 0.25e2)*_t301);
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = (0.292e3 / 0.2025e4)*_hc0[0]*_hc0[13] + (0.73e2 / 0.750e3)*_hc0[0]*_hc1[0]*_hc1[1]*_t123*_t202*_t40 + (0.73e2 / 0.375e3)*_hc0[0]*_hc1[0]*_hc1[1]*_t123*_t94*_t97 + (0.73e2 / 0.450e3)*_hc0[0]*_hc1[0]*_hc1[1]*_t208*_t245*_t40*_t97 + (0.73e2 / 0.1125e4)*_hc0[0]*_hc1[2]*_hc1[4]*_t40*_t51 + (0.292e3 / 0.2025e4)*_hc0[1]*_hc0[9] - _hc0[13]*_t11 + (0.292e3 / 0.675e3)*_hc0[2]*_hc0[8] + (0.73e2 / 0.250e3)*_hc0[2]*_hc1[0]*_hc1[1]*_t123*_t40*_t97 + (0.73e2 / 0.750e3)*_hc0[2]*_hc1[0]*_hc1[1]*_t51*_t94 + (0.292e3 / 0.675e3)*_hc0[4]*_hc0[5] + (0.73e2 / 0.750e3)*_hc0[5]*_hc1[0]*_hc1[1]*_t40*_t51 - _t128*_t202*_t41 - _t161*_t200 - _t162*_t190*_t201 - 0.73e2 / 0.405e3*_t164*_t202 + (0.1e1 / 0.8e1)*_t17*_t18*_t199 + (0.1e1 / 0.24e2)*_t17*_t18*x2*(_hc1[0]*_t319*_t320 - _t100*_t296 - _t100*_t297 + _t100*_t324 + _t101*(_t149*_t76 + 0.3e1*_t87 + 0.3e1*_t88 - 0.3e1*_t89) - _t106*_t296 - _t106*_t297 + _t106*_t324 + _t106*_t325 + _t106*_t326 - _t106*_t85 + _t16*(0.8e1*_hc1[1]*_hc2[1]*_t150*_t211 + 0.6e1*_hc1[4]*_hc2[0]*_t150*_t93 - _t271*_t318 - _t299*_t319) - _t195*_t289*_t43 - _t197*_t218 + _t197*_t225 + _t210*_t318 + _t213*_t35 - _t214*_t35 + _t215*_t266 - _t215*_t31 - _t216*_t91 - _t217*_t35 - _t218*_t312 - _t219*_t35 + _t220*_t266 - _t220*_t31 + _t222*_t91 + _t223*_t35 - _t224*_t35 + _t225*(-_t183*_t269 + _t183*_t270 + _t195*_t267 - _t195*_t268) + _t226*_t325 + _t226*_t326 - _t226*_t85 + _t25*_t320*_t43*_t93 - _t260*_t322 - _t289*_t319 - _t291*_t318 + _t318*_t321 + _t322*_t323) - 0.73e2 / 0.375e3*_t183*_t77 - 0.146e3 / 0.1125e4*_t183*_t98 - _t184*_t280 - _t190*_t209*_t41 - _t192*_t203 - _t201*_t279*_t97 - _t201*_t302 - _t203*_t305 - _t204*_t280 - _t247*_t317 - _t314*_t82 - 0.73e2 / 0.405e3*_t315*_t80 - _t316*(-_hc1[2]*_t284 - _hc1[4]*_t206);
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = (0.292e3 / 0.2025e4)*_hc0[0]*_hc0[14] - _hc0[14]*_t11 + (0.1168e4 / 0.2025e4)*_hc0[2]*_hc0[9] + (0.292e3 / 0.675e3)*((_hc0[5]) * (_hc0[5])) - _t162*_t202*_t327 + (0.1e1 / 0.6e1)*_t17*_t18*_t227 + (0.1e1 / 0.24e2)*_t17*_t18*x2*(-_t100*_t330 + _t100*_t331 + _t101*_t106 + _t101*_t226 + _t101*(-0.3e1*_t104 + 0.6e1*_t105) + (_t106 * _t106)*_t16 - _t106*_t330 + _t106*_t331 - _t106*_t332 + _t107*_t226 + _t16*(_t43 * _t43 * _t43 * _t43) + _t16*(-_t271*_t328 + _t272*_t328) + _t210*_t328 - _t211*_t307*_t43 + _t212*_t258*_t43 - _t215*_t329 + 0.2e1*_t220*_t225 - _t220*_t329 + _t225*(0.4e1*_hc2[0]*_t150*_t211 - _t211*_t268) - _t226*_t332 - _t291*_t328 + _t321*_t328) - 0.146e3 / 0.135e3*_t184*_t94 - 0.146e3 / 0.135e3*_t193*_t303 - _t200*_t202*_t52 - _t200*_t315 - _t202*_t209*_t95 - 0.584e3 / 0.405e3*_t204*_t94 - _t208*_t278*_t327*_t97 - _t246*_t317*(-0.9e1 / 0.10e2*_t37 - 0.5e1 / 0.1152e4*_t6*x2) - _t314*_t327 - _t316*(-_t207 - 0.27e2 / 0.50e2*_t93);
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tpss_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_fx_pf_k, _KMAX)(p, x2, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tpss_kappa_pf_k, _KMAX)(p, 0, 0, _hc1);
  const double _t1 = _hc0[0] + _hc1[0];
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = _hc1[0]*_t2;
#if _KMAX >= 1
  const double _t4 = _hc1[0]/(_t1 * _t1);
  const double _t5 = _hc0[0]*_t4;
#endif
#if _KMAX >= 2
  const double _t6 = ((_hc0[1]) * (_hc0[1]));
  const double _t7 = 0.2e1*_t4;
  const double _t8 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t9 = _hc1[0]*_t8;
  const double _t10 = _t6*_t9;
  const double _t11 = 0.2e1*_hc0[0];
  const double _t12 = _hc0[2]*_t7;
  const double _t13 = _t11*_t9;
  const double _t14 = _hc0[1]*_hc0[2];
  const double _t15 = ((_hc0[2]) * (_hc0[2]));
  const double _t16 = _t15*_t9;
#endif
#if _KMAX >= 3
  const double _t17 = 0.6e1*_t4;
  const double _t18 = _hc0[1]*_t17;
  const double _t19 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t20 = _hc1[0]/(_t1 * _t1 * _t1 * _t1);
  const double _t21 = _hc0[0]*_t20;
  const double _t22 = 0.6e1*_t21;
  const double _t23 = 0.4e1*_t4;
  const double _t24 = _hc0[4]*_t23;
  const double _t25 = _t22*_t6;
  const double _t26 = _hc0[5]*_t7;
  const double _t27 = _t15*_t22;
  const double _t28 = _hc0[2]*_t17;
  const double _t29 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 4
  const double _t30 = 0.8e1*_t4;
  const double _t31 = _hc0[1]*_hc0[6];
  const double _t32 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t33 = 0.24e2*_t20;
  const double _t34 = ((_hc0[3]) * (_hc0[3]));
  const double _t35 = _hc0[0]*_t9;
  const double _t36 = xc_powi(_t1, -5);
  const double _t37 = 0.24e2*_hc0[0]*_hc1[0]*_t36;
  const double _t38 = 0.6e1*_t9;
  const double _t39 = _hc0[0]*_t38;
  const double _t40 = 0.36e2*_hc0[3];
  const double _t41 = _t21*_t6;
  const double _t42 = _hc0[4]*_t17;
  const double _t43 = _hc0[4]*_t39;
  const double _t44 = _t14*_t9;
  const double _t45 = 0.18e2*_t44;
  const double _t46 = 0.18e2*_hc0[4];
  const double _t47 = _hc0[2]*_t19;
  const double _t48 = 0.18e2*_t14*_t21;
  const double _t49 = _hc0[1]*_hc0[8];
  const double _t50 = _hc0[2]*_hc0[7];
  const double _t51 = ((_hc0[4]) * (_hc0[4]));
  const double _t52 = 0.4e1*_t35;
  const double _t53 = _t15*_t6;
  const double _t54 = _hc0[1]*_hc0[9];
  const double _t55 = _hc0[1]*_t29;
  const double _t56 = _t15*_t21;
  const double _t57 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t58 = ((_hc0[5]) * (_hc0[5]));
#endif

  const double f = _hc0[0]*_t3 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[1]*_hc1[0]*_t2 - _hc0[1]*_t5;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx2 = _hc0[2]*_hc1[0]*_t2 - _hc0[2]*_t5;
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[3]*_t3 - _hc0[3]*_t5 + _t10*_t11 - _t6*_t7;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx2_dt = -_hc0[1]*_t12 + _hc0[4]*_t3 - _hc0[4]*_t5 + _t13*_t14;
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = 0;
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = _hc0[5]*_t3 - _hc0[5]*_t5 + _t11*_t16 - _t15*_t7;
  out[9] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0.6e1*_hc0[0]*_hc0[1]*_hc0[3]*_hc1[0]*_t8 - _hc0[3]*_t18 + _hc0[6]*_hc1[0]*_t2 - _hc0[6]*_t5 + 0.6e1*_hc1[0]*_t19*_t8 - _t19*_t22;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx2_dt2 = 0.4e1*_hc0[0]*_hc0[1]*_hc0[4]*_hc1[0]*_t8 + 0.2e1*_hc0[0]*_hc0[2]*_hc0[3]*_hc1[0]*_t8 - _hc0[1]*_t24 + 0.6e1*_hc0[2]*_hc1[0]*_t6*_t8 - _hc0[2]*_t25 - _hc0[3]*_t12 + _hc0[7]*_hc1[0]*_t2 - _hc0[7]*_t5;
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = 0;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = 0;
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = 0.2e1*_hc0[0]*_hc0[1]*_hc0[5]*_hc1[0]*_t8 + 0.4e1*_hc0[0]*_hc0[2]*_hc0[4]*_hc1[0]*_t8 + 0.6e1*_hc0[1]*_hc1[0]*_t15*_t8 - _hc0[1]*_t26 - _hc0[1]*_t27 - _hc0[2]*_t24 + _hc0[8]*_hc1[0]*_t2 - _hc0[8]*_t5;
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = 0;
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = 0.6e1*_hc0[0]*_hc0[2]*_hc0[5]*_hc1[0]*_t8 - _hc0[5]*_t28 + _hc0[9]*_hc1[0]*_t2 - _hc0[9]*_t5 + 0.6e1*_hc1[0]*_t29*_t8 - _t22*_t29;
  out[19] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc0[10]*_t3 - _hc0[10]*_t5 + _t10*_t40 - _t17*_t34 - _t30*_t31 + 0.8e1*_t31*_t35 - _t32*_t33 + _t32*_t37 + _t34*_t39 - _t40*_t41;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx2_dt3 = _hc0[1]*_hc0[7]*_t39 + _hc0[11]*_t3 - _hc0[11]*_t5 + _hc0[2]*_hc0[6]*_t13 - _hc0[3]*_t42 + _hc0[3]*_t43 + _hc0[3]*_t45 - _hc0[3]*_t48 - _hc0[6]*_t12 - _hc0[7]*_t18 + _t10*_t46 - _t33*_t47 + _t37*_t47 - _t41*_t46;
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = 0;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = 0;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = 0;
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = -_hc0[0]*_hc0[4]*_t14*_t33 + _hc0[12]*_t3 - _hc0[12]*_t5 + _hc0[3]*_hc0[5]*_t13 + _hc0[3]*_t15*_t38 - _hc0[3]*_t26 - _hc0[3]*_t27 + 0.24e2*_hc0[4]*_t44 - _hc0[5]*_t25 + _hc0[5]*_t38*_t6 - _t23*_t49 - _t23*_t50 - _t23*_t51 - _t33*_t53 + _t37*_t53 + _t49*_t52 + _t50*_t52 + _t51*_t52;
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = 0;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = 0;
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = _hc0[13]*_t3 - _hc0[13]*_t5 + _hc0[2]*_hc0[8]*_t39 - _hc0[5]*_t42 + _hc0[5]*_t43 + _hc0[5]*_t45 - _hc0[5]*_t48 - _hc0[8]*_t28 + _t13*_t54 + _t16*_t46 - _t33*_t55 + _t37*_t55 - _t46*_t56 - _t54*_t7;
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = 0;
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = 0.8e1*_hc0[0]*_hc0[2]*_hc0[9]*_hc1[0]*_t8 + 0.24e2*_hc0[0]*_hc1[0]*_t36*_t57 + 0.6e1*_hc0[0]*_hc1[0]*_t58*_t8 + _hc0[14]*_hc1[0]*_t2 - _hc0[14]*_t5 - _hc0[2]*_hc0[9]*_t30 + 0.36e2*_hc0[5]*_hc1[0]*_t15*_t8 - 0.36e2*_hc0[5]*_t56 - _t17*_t58 - _t33*_t57;
  out[34] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_tpss_params *params = (const mgga_x_tpss_params *)(p->params);

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
  if(!(_t7)) XC_CAT(tpss_f_pf_k, _KMAX)(p, _t5*sigma_ss, 0, _t6*tau_s, _hc1);
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
  assert(p->params != NULL);
  const mgga_x_tpss_params *params = (const mgga_x_tpss_params *)(p->params);
  (void)params;
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