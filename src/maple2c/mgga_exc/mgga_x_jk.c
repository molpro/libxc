/*
  Generated from python/mgga_exc/mgga_x_jk.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_jk
*/

#ifndef _MGGA_X_JK_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_JK_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_JK_HELPER_BODIES
#include "mgga_x_jk.c"
#undef _MGGA_X_JK_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_JK_HELPER_BODIES
#include "mgga_x_jk.c"
#undef _MGGA_X_JK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_JK_HELPER_BODIES
#include "mgga_x_jk.c"
#undef _MGGA_X_JK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_JK_HELPER_BODIES
#include "mgga_x_jk.c"
#undef _MGGA_X_JK_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_JK_HELPER_BODIES
#include "mgga_x_jk.c"
#undef _MGGA_X_JK_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_jk.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_JK_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(b88_f_m1_k, _KMAX)(const xc_func_type *p, double x, double *out) {
  const mgga_x_jk_params *params = (const mgga_x_jk_params *)(p->params);

  const double _t1 = params->beta*params->gamma;
  const double _t2 = _t1*xc_asinh(x);
  const double _t3 = _t2*x + 0.1e1;
  const double _t4 = xc_powr(0.2e1, 2, 3)*M_CBRTPI*params->beta/M_CBRT3;
  const double _t5 = _t4/_t3;
  const double _t6 = (x * x);
  const double _t7 = (0.2e1 / 0.3e1)*_t6;
#if _KMAX >= 1
  const double _t8 = (0.4e1 / 0.3e1)*_t5;
  const double _t9 = _t6 + 0.1e1;
  const double _t10 = _t1/xc_powr(_t9, 1, 2);
  const double _t11 = _t10*x;
  const double _t12 = -_t11 - _t2;
  const double _t13 = _t4/(_t3 * _t3);
  const double _t14 = _t12*_t13;
#endif
#if _KMAX >= 2
  const double _t15 = xc_powr(_t9, -3, 2);
  const double _t16 = _t1*_t15;
  const double _t17 = _t16*_t6;
  const double _t18 = -0.2e1*_t10 + _t17;
  const double _t19 = _t13*_t18;
  const double _t20 = -0.2e1*_t11 - 0.2e1*_t2;
  const double _t21 = _t4/(_t3 * _t3 * _t3);
  const double _t22 = _t12*_t21;
  const double _t23 = _t20*_t22;
#endif
#if _KMAX >= 3
  const double _t24 = 0.4e1*x;
  const double _t25 = _t1/xc_powr(_t9, 5, 2);
  const double _t26 = _t25*(x * x * x);
  const double _t27 = 0.4e1*_t15*params->beta*params->gamma*x - 0.3e1*_t26;
  const double _t28 = _t13*_t7;
  const double _t29 = (0.4e1 / 0.3e1)*_t6;
  const double _t30 = _t18*_t21;
  const double _t31 = _t20*_t30;
  const double _t32 = -0.4e1*_t10 + 0.2e1*_t17;
  const double _t33 = _t22*_t7;
  const double _t34 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t35 = -0.3e1*_t11 - 0.3e1*_t2;
  const double _t36 = _t34*_t35*_t4;
  const double _t37 = _t12*_t36;
  const double _t38 = _t20*_t7;
#endif
#if _KMAX >= 4
  const double _t39 = (0.16e2 / 0.3e1)*x;
  const double _t40 = 0.2e1*_t6;
  const double _t41 = _t20*_t40;
  const double _t42 = _t12*_t38*_t4;
#endif

  const double f = _t5*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t14*_t7 + _t8*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = (0.8e1 / 0.3e1)*_t14*x + _t19*_t7 + _t23*_t7 + _t8;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.4e1*_t14 + _t19*_t24 + _t23*_t24 + _t27*_t28 + _t29*_t31 + _t32*_t33 + _t37*_t38;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t13*_t27*_t39 + _t18*_t36*_t41 + 0.8e1*_t19 + _t20*_t37*_t39 + _t21*_t27*_t41 + _t22*_t32*_t39 + 0.8e1*_t23 + _t28*(0.15e2*_t1*(x * x * x * x)/xc_powr(_t9, 7, 2) + 0.4e1*_t16 - 0.21e2*_t25*_t6) + _t29*_t32*_t37 + _t30*_t32*_t40 + (0.32e2 / 0.3e1)*_t31*x + _t33*(0.8e1*_t15*params->beta*params->gamma*x - 0.6e1*_t26) + _t34*_t42*(-0.6e1*_t10 + 0.3e1*_t17) + _t35*_t42*(-0.4e1*_t11 - 0.4e1*_t2)/xc_powi(_t3, 5);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(y_k, _KMAX)(const xc_func_type *p, double x, double u, double *out) {


  const double f = -u + (x * x);
  out[0] = f;
#if _KMAX >= 1
  const double df_du = -0.1e1;
  out[1] = df_du;
  const double df_dx = 0.2e1*x;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_du2 = 0;
  out[3] = d2f_du2;
  const double d2f_dx_du = 0;
  out[4] = d2f_dx_du;
  const double d2f_dx2 = 0.2e1;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_du3 = 0;
  out[6] = d3f_du3;
  const double d3f_dx_du2 = 0;
  out[7] = d3f_dx_du2;
  const double d3f_dx2_du = 0;
  out[8] = d3f_dx2_du;
  const double d3f_dx3 = 0;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_du4 = 0;
  out[10] = d4f_du4;
  const double d4f_dx_du3 = 0;
  out[11] = d4f_dx_du3;
  const double d4f_dx2_du2 = 0;
  out[12] = d4f_dx2_du2;
  const double d4f_dx3_du = 0;
  out[13] = d4f_dx3_du;
  const double d4f_dx4 = 0;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(jk_f_k, _KMAX)(const xc_func_type *p, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(y_k, _KMAX)(p, x, u, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(b88_f_m1_k, _KMAX)(p, x, _hc1);
  const double _t1 = (0.1e1 / (x * x));
  const double _t2 = 0.2e1*_t1;
  const double _t3 = _hc0[0]*_t2 + 0.1e1;
  const double _t4 = (0.1e1 / _t3);
#if _KMAX >= 1
  const double _t5 = (0.1e1 / (_t3 * _t3));
  const double _t6 = _hc1[0]*_t5;
  const double _t7 = _hc0[1]*_t2;
  const double _t8 = (0.1e1 / (x * x * x));
  const double _t9 = _hc0[0]*_t8;
  const double _t10 = -_hc0[2]*_t2 + 0.4e1*_t9;
#endif
#if _KMAX >= 2
  const double _t11 = ((_hc0[1]) * (_hc0[1]));
  const double _t12 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t13 = _hc1[0]*_t12;
  const double _t14 = _t11*_t13;
  const double _t15 = (0.1e1 / (x * x * x * x));
  const double _t16 = 0.8e1*_t15;
  const double _t17 = _hc1[1]*_t5;
  const double _t18 = _t10*_t13;
  const double _t19 = 0.4e1*_t1;
  const double _t20 = _hc0[1]*_t19;
  const double _t21 = 0.2e1*_t10;
  const double _t22 = _hc0[0]*_t15;
  const double _t23 = 0.8e1*_hc0[2]*_t8 - _hc0[5]*_t2 - 0.12e2*_t22;
  const double _t24 = -_hc0[2]*_t19 + 0.8e1*_t9;
  const double _t25 = _t10*_t24;
#endif
#if _KMAX >= 3
  const double _t26 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t27 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t28 = _hc1[0]*_t27;
  const double _t29 = xc_powi(x, -6);
  const double _t30 = 0.48e2*_t29;
  const double _t31 = xc_powi(x, -5);
  const double _t32 = _hc1[1]*_t12;
  const double _t33 = _t11*_t32;
  const double _t34 = 0.24e2*_t15;
  const double _t35 = _t11*_t28;
  const double _t36 = _t10*_t35;
  const double _t37 = _hc1[2]*_t5;
  const double _t38 = 0.8e1*_t1;
  const double _t39 = _t10*_t32;
  const double _t40 = _t13*_t20;
  const double _t41 = _t25*_t28;
  const double _t42 = 0.6e1*_t1;
  const double _t43 = _hc0[1]*_t42;
  const double _t44 = _t10*_t5;
  const double _t45 = _hc0[0]*_t31;
  const double _t46 = _hc0[2]*_t15;
  const double _t47 = _hc0[5]*_t8;
  const double _t48 = 0.48e2*_t45 - 0.36e2*_t46 + 0.12e2*_t47;
  const double _t49 = 0.3e1*_t23;
  const double _t50 = 0.16e2*_hc0[2]*_t8 - _hc0[5]*_t19 - 0.24e2*_t22;
  const double _t51 = _t13*_t24;
  const double _t52 = -_hc0[2]*_t42 + 0.12e2*_t9;
#endif
#if _KMAX >= 4
  const double _t53 = _hc1[0]/xc_powi(_t3, 5);
  const double _t54 = _hc1[1]*_t27;
  const double _t55 = _hc1[2]*_t12;
  const double _t56 = 0.48e2*_t11*_t15;
  const double _t57 = 0.12e2*_hc0[1]*_t1;
  const double _t58 = _t23*_t32;
  const double _t59 = _t25*_t52;
  const double _t60 = _t53*_t59;
  const double _t61 = _t28*_t52;
#endif

  const double f = _hc1[0]*_t4 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_du = -_t6*_t7;
  out[2] = df_du;
  const double df_dx = _hc1[1]*_t4 + _t10*_t6;
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = _t14*_t16;
  out[6] = d2f_du2;
  const double d2f_dx_dt = 0;
  out[7] = d2f_dx_dt;
  const double d2f_dx_du = 0.4e1*_hc0[1]*_hc1[0]*_t5*_t8 - _t17*_t7 - _t18*_t20;
  out[8] = d2f_dx_du;
  const double d2f_dx2 = _hc1[2]*_t4 + _t13*_t25 + _t17*_t21 + _t23*_t6;
  out[9] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = -_t26*_t28*_t30;
  out[13] = d3f_du3;
  const double d3f_dx_dt2 = 0;
  out[14] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[15] = d3f_dx_du_dt;
  const double d3f_dx_du2 = -0.32e2*_t14*_t31 + _t16*_t33 + _t34*_t36;
  out[16] = d3f_dx_du2;
  const double d3f_dx2_dt = 0;
  out[17] = d3f_dx2_dt;
  const double d3f_dx2_du = 0.8e1*_hc0[1]*_hc1[0]*_t10*_t12*_t8 + 0.4e1*_hc0[1]*_hc1[0]*_t12*_t24*_t8 + 0.8e1*_hc0[1]*_hc1[1]*_t5*_t8 - 0.12e2*_hc0[1]*_t15*_t6 - _hc0[1]*_t38*_t39 - _t23*_t40 - _t37*_t7 - _t41*_t43;
  out[18] = d3f_dx2_du;
  const double d3f_dx3 = 0.3e1*_hc1[2]*_t44 + _hc1[3]*_t4 + _t17*_t49 + _t18*_t50 + 0.2e1*_t23*_t51 + 0.3e1*_t25*_t32 + _t41*_t52 + _t48*_t6;
  out[19] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0.384e3*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t53/xc_powi(x, 8);
  out[24] = d4f_du4;
  const double d4f_dx_dt3 = 0;
  out[25] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[26] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[27] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0.288e3*_hc1[0]*_t26*_t27/xc_powi(x, 7) - 0.192e3*_t10*_t26*_t29*_t53 - _t26*_t30*_t54;
  out[28] = d4f_dx_du3;
  const double d4f_dx2_dt2 = 0;
  out[29] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[30] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = _t10*_t54*_t56 + _t11*_t16*_t55 + 0.160e3*_t14*_t29 + _t23*_t34*_t35 - 0.48e2*_t24*_t31*_t35 + _t25*_t53*_t56 - 0.64e2*_t31*_t33 - 0.96e2*_t31*_t36;
  out[31] = d4f_dx2_du2;
  const double d4f_dx3_dt = 0;
  out[32] = d4f_dx3_dt;
  const double d4f_dx3_du = 0.12e2*_hc0[1]*_hc1[0]*_t10*_t24*_t27*_t8 + 0.8e1*_hc0[1]*_hc1[0]*_t10*_t27*_t52*_t8 + 0.16e2*_hc0[1]*_hc1[0]*_t12*_t23*_t8 + 0.4e1*_hc0[1]*_hc1[0]*_t12*_t50*_t8 + 0.4e1*_hc0[1]*_hc1[0]*_t24*_t27*_t52*_t8 + 0.48e2*_hc0[1]*_hc1[0]*_t31*_t5 + 0.24e2*_hc0[1]*_hc1[1]*_t10*_t12*_t8 + 0.12e2*_hc0[1]*_hc1[1]*_t12*_t24*_t8 + 0.12e2*_hc0[1]*_hc1[2]*_t5*_t8 - 0.18e2*_hc0[1]*_t1*_t25*_t54 - 0.36e2*_hc0[1]*_t15*_t17 - _hc0[1]*_t18*_t34 - _hc0[1]*_t34*_t51 - _hc0[1]*_t38*_t60 - _hc1[3]*_t5*_t7 - _t10*_t28*_t43*_t50 - _t10*_t55*_t57 - _t23*_t24*_t28*_t57 - _t40*_t48 - _t57*_t58;
  out[33] = d4f_dx3_du;
  const double d4f_dx4 = 0.4e1*_hc1[3]*_t44 + _hc1[4]*_t4 + _t13*_t49*_t50 + 0.4e1*_t17*_t48 + _t18*(0.96e2*_t45 - 0.72e2*_t46 + 0.24e2*_t47) + _t21*_t50*_t61 + 0.6e1*_t23*_t37 + _t24*_t49*_t61 + 0.8e1*_t24*_t58 + 0.6e1*_t25*_t55 + 0.4e1*_t39*_t50 + _t41*(0.24e2*_hc0[2]*_t8 - _hc0[5]*_t42 - 0.36e2*_t22) + 0.3e1*_t48*_t51 + 0.4e1*_t54*_t59 + _t6*(-0.240e3*_hc0[0]*_t29 + 0.192e3*_hc0[2]*_t31 - 0.72e2*_hc0[5]*_t15) + _t60*(-_hc0[2]*_t38 + 0.16e2*_t9);
  out[34] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_jk_params *params = (const mgga_x_jk_params *)(p->params);

  const double _t1 = xc_powr(n_s, -4, 3);
  const double _t2 = xc_powr(sigma_ss, 1, 2);
  const double _t3 = xc_powr(n_s, -5, 3);
  const double _t4 = xc_powr(0.6e1, 1, 3);
  const double _t5 = (0.1e1 / (M_CBRTPI));
  const double _t6 = _t4*_t5;
  const double _t7 = (0.1e1 / 0.2e1)*_t6;
  const double _t8 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t12 = (0.1e1 / _t2);
  const double _t17 = xc_powr(n_s, -8, 3);
  const double _t18 = (0.5e1 / 0.3e1)*_t17;
  const double _t20 = (0.4e1 / 0.3e1)*_t2;
  const double _t21 = xc_powr(n_s, -7, 3);
#endif
#if _KMAX >= 2
  const double _t25 = xc_powr(n_s, -10, 3);
  const double _t27 = (0.1e1 / (n_s * n_s * n_s));
  const double _t31 = xc_powr(sigma_ss, -3, 2);
  const double _t33 = (0.1e1 / sigma_ss);
  const double _t35 = xc_powr(n_s, -13, 3);
  const double _t36 = (0.5e1 / 0.3e1)*lapl_s;
  const double _t37 = _t35*_t36;
  const double _t38 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t43 = xc_powr(n_s, -11, 3);
  const double _t44 = (0.2e1 / 0.3e1)*_t43;
  const double _t45 = (0.2e1 / 0.3e1)*_t12;
  const double _t47 = (0.5e1 / 0.6e1)*lapl_s;
  const double _t48 = _t12*_t47;
  const double _t53 = xc_powr(0.6e1, 2, 3);
  const double _t54 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t58 = (0.1e1 / 0.3e1)*_t1;
  const double _t59 = (0.40e2 / 0.9e1)*_t43;
  const double _t61 = (0.28e2 / 0.9e1)*_t2;
  const double _t67 = _t20*_t21;
#endif
#if _KMAX >= 3
  const double _t71 = xc_powi(n_s, -5);
  const double _t73 = xc_powr(n_s, -14, 3);
  const double _t82 = xc_powr(sigma_ss, -5, 2);
  const double _t86 = (0.1e1 / (sigma_ss * sigma_ss));
  const double _t88 = (0.10e2 / 0.3e1)*_t35;
  const double _t89 = xc_powi(n_s, -6);
  const double _t91 = xc_powr(n_s, -17, 3);
  const double _t96 = xc_powr(n_s, -16, 3);
  const double _t97 = (0.2e1 / 0.3e1)*_t96;
  const double _t98 = (0.3e1 / 0.2e1)*_t12;
  const double _t103 = (0.1e1 / 0.3e1)*_t12;
  const double _t104 = _t103*_t71;
  const double _t105 = (0.1e1 / 0.3e1)*_t33;
  const double _t107 = (0.5e1 / 0.12e2)*lapl_s;
  const double _t114 = (0.40e2 / 0.9e1)*lapl_s;
  const double _t117 = _t18*lapl_s;
  const double _t124 = (0.14e2 / 0.9e1)*_t73;
  const double _t125 = (0.14e2 / 0.9e1)*_t12;
  const double _t126 = (0.20e2 / 0.9e1)*lapl_s;
  const double _t127 = _t21*_t45;
  const double _t138 = (0.440e3 / 0.27e2)*_t73;
  const double _t140 = (0.280e3 / 0.27e2)*_t2;
#endif
#if _KMAX >= 4
  const double _t158 = xc_powr(n_s, -20, 3);
  const double _t159 = xc_powr(n_s, -19, 3);
  const double _t161 = (0.1e1 / 0.6e1)*_t159;
  const double _t163 = xc_powr(n_s, -22, 3);
  const double _t165 = xc_powi(n_s, -7);
  const double _t169 = _t107*_t33;
  const double _t173 = _t91*lapl_s;
  const double _t174 = (0.5e1 / 0.6e1)*_t173;
  const double _t176 = (0.4e1 / 0.3e1)*_t21;
  const double _t177 = _t105*_t43;
  const double _t185 = _t59*lapl_s;
#endif
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t8)) XC_CAT(jk_f_k, _KMAX)(p, _t1*_t2, _t3*lapl_s, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t8)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t7/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc1);
  const double _t9 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t10 = my_piecewise3(_t8, 0, _hc0[2]*_hc1[0]*_t3);
  const double _t11 = (0.1e1 / 0.2e1)*_hc1[0];
  const double _t13 = _hc0[3]*_t12;
  const double _t14 = my_piecewise3(_t8, 0, _t1*_t11*_t13);
  const double _t15 = _hc1[2]*_t6;
  const double _t16 = (0.1e1 / 0.6e1)*_t15;
  const double _t19 = _hc0[2]*_t18;
  const double _t22 = _hc0[3]*_t21;
  const double _t23 = -_t19*lapl_s - _t20*_t22;
  const double _t24 = my_piecewise3(_t8, 0, -_hc0[0]*_t1*_t16 + _hc1[0]*_t23);
#endif
#if _KMAX >= 2
  const double _t26 = my_piecewise3(_t8, 0, _hc0[6]*_hc1[0]*_t25);
  const double _t28 = _hc0[8]*_t12;
  const double _t29 = my_piecewise3(_t8, 0, _t11*_t27*_t28);
  const double _t30 = (0.1e1 / 0.4e1)*_hc1[0];
  const double _t32 = _hc0[3]*_t31;
  const double _t34 = my_piecewise3(_t8, 0, (0.1e1 / 0.4e1)*_hc0[9]*_hc1[0]*_t17*_t33 - _t1*_t30*_t32);
  const double _t39 = _hc0[8]*_t20;
  const double _t40 = -_hc0[6]*_t37 - _t19 - _t38*_t39;
  const double _t41 = my_piecewise3(_t8, 0, -_hc0[2]*_t16*_t27 + _hc1[0]*_t40);
  const double _t42 = _t15*_t17;
  const double _t46 = _hc0[8]*_t38;
  const double _t49 = -_hc0[9]*_t44 - _t22*_t45 - _t46*_t48;
  const double _t50 = my_piecewise3(_t8, 0, _hc1[0]*_t49 - 0.1e1 / 0.12e2*_t13*_t42);
  const double _t51 = (0.2e1 / 0.9e1)*_hc0[0];
  const double _t52 = (0.1e1 / 0.36e2)*_hc0[0];
  const double _t55 = _hc1[5]*_t53*_t54;
  const double _t56 = _t17*_t55;
  const double _t57 = _t15*_t23;
  const double _t60 = _hc0[2]*_t59;
  const double _t62 = _hc0[3]*_t25;
  const double _t63 = _hc0[6]*_t18;
  const double _t64 = -_t21*_t39 - _t63*lapl_s;
  const double _t65 = _t18*_t64;
  const double _t66 = _hc0[8]*_t18;
  const double _t68 = -_hc0[9]*_t67 - _t66*lapl_s;
  const double _t69 = _t60*lapl_s + _t61*_t62 - _t65*lapl_s - _t67*_t68;
  const double _t70 = my_piecewise3(_t8, 0, _hc1[0]*_t69 + _t15*_t21*_t51 + _t52*_t56 - _t57*_t58);
#endif
#if _KMAX >= 3
  const double _t72 = my_piecewise3(_t8, 0, _hc0[13]*_hc1[0]*_t71);
  const double _t74 = _hc0[16]*_t12;
  const double _t75 = my_piecewise3(_t8, 0, _t11*_t73*_t74);
  const double _t76 = _hc0[18]*_t33;
  const double _t77 = _t30*_t31;
  const double _t78 = _hc0[8]*_t27;
  const double _t79 = my_piecewise3(_t8, 0, _t30*_t35*_t76 - _t77*_t78);
  const double _t80 = _hc0[19]*_t38;
  const double _t81 = (0.1e1 / 0.8e1)*_hc1[0]*_t31;
  const double _t83 = (0.3e1 / 0.8e1)*_hc1[0];
  const double _t84 = _t82*_t83;
  const double _t85 = _hc0[3]*_t1;
  const double _t87 = my_piecewise3(_t8, 0, -_hc0[9]*_t17*_t83*_t86 + _t80*_t81 + _t84*_t85);
  const double _t90 = _hc0[13]*_t89;
  const double _t92 = _hc0[16]*_t20;
  const double _t93 = -_hc0[6]*_t88 - _t36*_t90 - _t91*_t92;
  const double _t94 = my_piecewise3(_t8, 0, -_hc0[6]*_t16*_t73 + _hc1[0]*_t93);
  const double _t95 = _t15*_t35;
  const double _t99 = _t74*_t91;
  const double _t100 = -_hc0[18]*_t97 - _t46*_t98 - _t47*_t99;
  const double _t101 = my_piecewise3(_t8, 0, _hc1[0]*_t100 - 0.1e1 / 0.12e2*_t28*_t95);
  const double _t102 = (0.1e1 / 0.24e2)*_t15;
  const double _t106 = _t76*_t96;
  const double _t108 = -_hc0[19]*_t104 + (0.1e1 / 0.3e1)*_hc0[3]*_t21*_t31 + (0.5e1 / 0.12e2)*_hc0[8]*_t31*_t38*lapl_s - _hc0[9]*_t105*_t43 - _t106*_t107;
  const double _t109 = my_piecewise3(_t8, 0, -_hc0[9]*_t102*_t33*_t38 + _hc1[0]*_t108 + (0.1e1 / 0.24e2)*_t32*_t42);
  const double _t110 = (0.2e1 / 0.9e1)*_t15;
  const double _t111 = (0.1e1 / 0.36e2)*_hc0[2];
  const double _t112 = _t15*_t58;
  const double _t113 = _hc0[6]*_t96;
  const double _t115 = _hc0[8]*_t61;
  const double _t116 = -_hc0[13]*_t37 - _t38*_t92 - _t63;
  const double _t118 = _hc0[18]*_t38;
  const double _t119 = -_hc0[16]*_t37 - _t118*_t20 - _t66;
  const double _t120 = _t113*_t114 + _t115*_t71 - _t116*_t117 - _t119*_t67 + _t60 - _t65;
  const double _t121 = my_piecewise3(_t8, 0, _hc0[2]*_t110*_t38 + _hc1[0]*_t120 + _t111*_t35*_t55 - _t112*_t40);
  const double _t122 = (0.1e1 / 0.9e1)*_t15;
  const double _t123 = (0.1e1 / 0.72e2)*_t55;
  const double _t128 = -_hc0[18]*_t44 - _hc0[8]*_t127 - _t38*_t47*_t74;
  const double _t129 = _t128*_t18;
  const double _t130 = -_hc0[19]*_t44 - _hc0[9]*_t127 - _t118*_t48;
  const double _t131 = _hc0[9]*_t124 + _t125*_t62 + _t126*_t28*_t71 - _t127*_t68 - _t129*lapl_s - _t130*_t67;
  const double _t132 = my_piecewise3(_t8, 0, _hc1[0]*_t131 - _t112*_t49 + _t122*_t13*_t43 + _t123*_t13*_t38);
  const double _t133 = _hc1[9]/M_PI;
  const double _t134 = _t133*_t38;
  const double _t135 = (0.14e2 / 0.27e2)*_t15;
  const double _t136 = (0.1e1 / 0.9e1)*_t55;
  const double _t137 = _hc1[2]*_t1*_t7;
  const double _t139 = _hc0[2]*_t138;
  const double _t141 = _hc0[3]*_t35;
  const double _t142 = _hc0[6]*_t59;
  const double _t143 = _hc0[13]*_t18;
  const double _t144 = -_hc0[16]*_t67 - _t143*lapl_s;
  const double _t145 = _t144*_t18;
  const double _t146 = _hc0[16]*_t18;
  const double _t147 = -_hc0[18]*_t67 - _t146*lapl_s;
  const double _t148 = _t115*_t25 + _t142*lapl_s - _t145*lapl_s - _t147*_t67;
  const double _t149 = _t148*_t18;
  const double _t150 = _hc0[8]*_t59;
  const double _t151 = _hc0[9]*_t25;
  const double _t152 = _t147*_t18;
  const double _t153 = _hc0[18]*_t18;
  const double _t154 = -_hc0[19]*_t67 - _t153*lapl_s;
  const double _t155 = _t150*lapl_s + _t151*_t61 - _t152*lapl_s - _t154*_t67;
  const double _t156 = -_t139*lapl_s - _t140*_t141 - _t149*lapl_s - _t155*_t67 + (0.56e2 / 0.9e1)*_t2*_t25*_t68 + (0.80e2 / 0.9e1)*_t43*_t64*lapl_s;
  const double _t157 = my_piecewise3(_t8, 0, -_hc0[0]*_t135*_t25 - _hc0[0]*_t136*_t43 + _hc1[0]*_t156 + (0.2e1 / 0.3e1)*_hc1[2]*_t21*_t23*_t4*_t5 + (0.1e1 / 0.12e2)*_hc1[5]*_t17*_t23*_t53*_t54 - _t134*_t52 - _t137*_t69);
#endif
#if _KMAX >= 4
  const double _t160 = _hc0[28]*_t12;
  const double _t162 = _hc0[24]*_t36;
  const double _t164 = _hc0[28]*_t20;
  const double _t166 = _hc0[31]*_t165;
  const double _t167 = _hc0[28]*_t48;
  const double _t168 = _hc0[33]*_t158;
  const double _t170 = _hc0[13]*_t114;
  const double _t171 = _hc0[16]*_t61;
  const double _t172 = _hc0[31]*_t20;
  const double _t175 = _hc0[8]*lapl_s;
  const double _t178 = _hc0[6]*lapl_s;
  const double _t179 = _hc0[8]*_t140;
  const double _t180 = -_hc0[28]*_t37 - _t146 - _t172*_t38;
  const double _t181 = _hc0[18]*_t61;
  const double _t182 = _hc0[33]*_t38;
  const double _t183 = _hc0[3]*_t96;
  const double _t184 = -_hc0[18]*_t127 - _hc0[31]*_t38*_t48 - _hc0[33]*_t44;
  const double _t186 = -_hc0[28]*_t117 - _hc0[31]*_t67;
  const double _t187 = -_hc0[31]*_t117 - _hc0[33]*_t67;
  const double _t188 = _hc0[16]*_t185 - _t117*_t186 + _t181*_t25 - _t187*_t67;
#endif

  const double f = my_piecewise3(_t8, 0, _t9*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = 0;
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t8, 0, _t10*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t8, 0, _t14*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t8, 0, _t24*n_s + _t9);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = 0;
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t8, 0, _t26*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = 0;
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t8, 0, _t29*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t8, 0, _t34*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = 0;
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t8, 0, _t10 + _t41*n_s);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t8, 0, _t14 + _t50*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t8, 0, 0.2e1*_t24 + _t70*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = 0;
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t8, 0, _t72*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = 0;
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t8, 0, _t75*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = 0;
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t8, 0, _t79*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t8, 0, _t87*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = 0;
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t8, 0, _t26 + _t94*n_s);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = 0;
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t8, 0, _t101*n_s + _t29);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t8, 0, _t109*n_s + _t34);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = 0;
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t8, 0, _t121*n_s + 0.2e1*_t41);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t8, 0, _t132*n_s + 0.2e1*_t50);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t8, 0, _t157*n_s + 0.3e1*_t70);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = 0;
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, _hc0[24]*_hc1[0]*_t158));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = 0;
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, _t11*_t159*_t160));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = 0;
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, -_hc0[16]*_t73*_t77 + (0.1e1 / 0.4e1)*_hc0[31]*_hc1[0]*_t33*_t89));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = 0;
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, -_hc0[18]*_t35*_t83*_t86 + _hc0[33]*_t81*_t91 + _t78*_t84));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t8, 0, n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.16e2)*_hc0[34]*_hc1[0]*_t86*_t96 + (0.15e2 / 0.16e2)*_hc0[9]*_hc1[0]*_t17/(sigma_ss * sigma_ss * sigma_ss) - 0.15e2 / 0.16e2*_hc1[0]*_t85/xc_powr(sigma_ss, 7, 2) - _t80*_t84));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = 0;
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t8, 0, _t72 + n_s*my_piecewise3(_t8, 0, -_hc0[13]*_t15*_t161 + _hc1[0]*(-_t162/xc_powr(n_s, 23, 3) - _t163*_t164 - 0.5e1*_t90)));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = 0;
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t8, 0, _t75 + n_s*my_piecewise3(_t8, 0, _hc1[0]*(-_t163*_t167 - 0.2e1 / 0.3e1*_t166 - 0.7e1 / 0.3e1*_t99) - 0.1e1 / 0.12e2*_t15*_t74*_t89));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = 0;
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t8, 0, _t79 + n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.24e2)*_hc0[8]*_t31*_t95 + _hc1[0]*((0.5e1 / 0.12e2)*_hc0[16]*_t31*_t91*lapl_s + (0.3e1 / 0.4e1)*_hc0[8]*_t31*_t38 - _t103*_t168 - 0.3e1 / 0.4e1*_t106 - _t166*_t169) - _t102*_t76*_t91));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t8, 0, _t87 + n_s*my_piecewise3(_t8, 0, -0.1e1 / 0.48e2*_hc0[19]*_t15*_t31*_t96 - 0.1e1 / 0.16e2*_hc0[3]*_t42*_t82 + (0.1e1 / 0.16e2)*_hc0[9]*_hc1[2]*_t38*_t4*_t5*_t86 + _hc1[0]*((0.5e1 / 0.8e1)*_hc0[18]*_t86*_t96*lapl_s - _hc0[34]*_t161*_t33 + (0.1e1 / 0.2e1)*_hc0[9]*_t43*_t86 - 0.5e1 / 0.24e2*_t168*_t31*lapl_s - 0.1e1 / 0.2e1*_t22*_t82 - 0.5e1 / 0.8e1*_t46*_t82*lapl_s)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = 0;
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t8, 0, 0.2e1*_t94 + n_s*my_piecewise3(_t8, 0, _hc0[6]*_t110*_t91 + (0.1e1 / 0.36e2)*_hc0[6]*_t55*_t89 + _hc1[0]*((0.80e2 / 0.9e1)*_t113 - 0.10e2 / 0.3e1*_t116*_t17 - _t117*(-_hc0[13]*_t88 - _t162*_t89 - _t164*_t91) + _t158*_t171 + _t165*_t170 - _t67*(-_hc0[16]*_t88 - _hc0[28]*_t36*_t89 - _t172*_t91)) - _t112*_t93));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = 0;
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t8, 0, 0.2e1*_t101 + n_s*my_piecewise3(_t8, 0, _hc1[0]*((0.20e2 / 0.9e1)*_hc0[16]*_t12*_t158*lapl_s + (0.14e2 / 0.9e1)*_hc0[18]*_t159 + (0.34e2 / 0.9e1)*_hc0[8]*_t12*_t71 - _t117*(-_hc0[16]*_t38*_t98 - _hc0[31]*_t97 - _t160*_t174) - _t119*_t127 - _t129 - _t67*(-_hc0[31]*_t12*_t174 - _hc0[33]*_t97 - _t118*_t98)) - _t100*_t112 + _t122*_t28*_t96 + _t123*_t28*_t91));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t8, 0, 0.2e1*_t109 + n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.18e2)*_hc0[9]*_hc1[2]*_t33*_t4*_t5*_t71 + (0.1e1 / 0.144e3)*_hc0[9]*_hc1[5]*_t33*_t53*_t54*_t96 + _hc1[0]*((0.10e2 / 0.9e1)*_hc0[18]*_t159*_t33*lapl_s + (0.7e1 / 0.9e1)*_hc0[19]*_t12*_t89 + (0.7e1 / 0.9e1)*_hc0[9]*_t33*_t73 - _t117*((0.5e1 / 0.12e2)*_hc0[16]*_t31*_t38*lapl_s - _hc0[18]*_t177 - _hc0[31]*_t107*_t33*_t96 - _hc0[33]*_t104 + (0.1e1 / 0.3e1)*_hc0[8]*_t21*_t31) - _t12*_t130*_t176 - 0.10e2 / 0.9e1*_t175*_t31*_t71 + (0.1e1 / 0.3e1)*_t21*_t31*_t68 - 0.7e1 / 0.9e1*_t31*_t62 - _t67*((0.5e1 / 0.12e2)*_hc0[18]*_t31*_t38*lapl_s - _hc0[19]*_t177 - _hc0[33]*_t169*_t96 - _hc0[34]*_t104 + (0.1e1 / 0.3e1)*_hc0[9]*_t21*_t31)) - _t108*_t112 - 0.1e1 / 0.18e2*_t15*_t32*_t43 - 0.1e1 / 0.144e3*_t32*_t38*_t55));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = 0;
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t8, 0, 0.3e1*_t121 + n_s*my_piecewise3(_t8, 0, -_hc0[2]*_t135*_t71 - _hc0[2]*_t136*_t96 + _hc1[0]*((0.80e2 / 0.9e1)*_t116*_t43*lapl_s - _t117*(-_t117*(-_hc0[24]*_t37 - _t143 - _t164*_t38) + _t142 - _t145 + _t170*_t96 + _t171*_t71 - _t180*_t67) + (0.56e2 / 0.9e1)*_t119*_t2*_t25 - _t139 - _t149 - 0.440e3 / 0.27e2*_t159*_t178 - _t179*_t89 + (0.80e2 / 0.9e1)*_t43*_t64 - _t67*(_hc0[16]*_t114*_t96 - _t117*_t180 + _t150 - _t152 + _t181*_t71 - _t67*(-_hc0[31]*_t37 - _t153 - _t182*_t20))) + (0.2e1 / 0.3e1)*_hc1[2]*_t21*_t4*_t40*_t5 + (0.1e1 / 0.12e2)*_hc1[5]*_t17*_t40*_t53*_t54 - _t111*_t133*_t91 - _t120*_t137));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t8, 0, 0.3e1*_t132 + n_s*my_piecewise3(_t8, 0, _hc1[0]*(-0.140e3 / 0.27e2*_hc0[9]*_t91 - _t117*(_hc0[18]*_t124 + _hc0[8]*_t125*_t25 - _t117*(-_hc0[16]*_t127 - _hc0[31]*_t44 - _t167*_t38) + _t126*_t71*_t74 - _t127*_t147 - _t184*_t67) - 0.140e3 / 0.27e2*_t12*_t141 + (0.28e2 / 0.9e1)*_t12*_t25*_t68 - _t127*_t155 + (0.80e2 / 0.9e1)*_t128*_t43*lapl_s + (0.56e2 / 0.9e1)*_t130*_t2*_t25 - 0.220e3 / 0.27e2*_t28*_t89*lapl_s - _t67*(_hc0[18]*_t12*_t126*_t71 + _hc0[19]*_t124 - _t117*_t184 + _t125*_t151 - _t127*_t154 - _t67*(-_hc0[19]*_t127 - _hc0[34]*_t44 - _t182*_t48))) + (0.2e1 / 0.3e1)*_hc1[2]*_t21*_t4*_t49*_t5 + (0.1e1 / 0.12e2)*_hc1[5]*_t17*_t49*_t53*_t54 - 0.1e1 / 0.72e2*_t12*_t133*_t183 - 0.7e1 / 0.27e2*_t13*_t15*_t73 - 0.1e1 / 0.18e2*_t13*_t55*_t71 - _t131*_t137));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t8, 0, 0.4e1*_t157 + n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.216e3)*_hc0[0]*_hc1[14]*_t4*_t96/(M_PI * M_CBRTPI) + (0.40e2 / 0.81e2)*_hc0[0]*_t55*_t73 + (0.140e3 / 0.81e2)*_hc0[0]*_t95 + _hc1[0]*((0.6160e4 / 0.81e2)*_hc0[2]*_t173 - _t117*(-_t117*(_hc0[13]*_t185 - _t117*(-_hc0[24]*_t117 - _hc0[28]*_t67) + _t171*_t25 - _t186*_t67) - _t138*_t178 + (0.80e2 / 0.9e1)*_t144*_t43*lapl_s + (0.56e2 / 0.9e1)*_t147*_t2*_t25 - _t179*_t35 - _t188*_t67) + (0.40e2 / 0.3e1)*_t148*_t43*lapl_s + (0.28e2 / 0.3e1)*_t155*_t2*_t25 + (0.3640e4 / 0.81e2)*_t183*_t2 - 0.280e3 / 0.9e1*_t2*_t35*_t68 - 0.440e3 / 0.9e1*_t64*_t73*lapl_s - _t67*(-_hc0[9]*_t140*_t35 - _t117*_t188 - _t138*_t175 + (0.80e2 / 0.9e1)*_t147*_t43*lapl_s + (0.56e2 / 0.9e1)*_t154*_t2*_t25 - _t67*(_hc0[18]*_t185 + _hc0[19]*_t25*_t61 - _t117*_t187 - _t67*(-_hc0[33]*_t117 - _hc0[34]*_t67)))) - 0.2e1 / 0.3e1*_t1*_t15*_t156 + _t133*_t51*_t71 - 0.1e1 / 0.9e1*_t134*_t23 + _t15*_t176*_t69 - 0.4e1 / 0.9e1*_t23*_t43*_t55 - 0.56e2 / 0.27e2*_t25*_t57 + (0.1e1 / 0.6e1)*_t56*_t69));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_jk_params *params = (const mgga_x_jk_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double ta = tau[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / 0.4e1)*gaa;
  const double _t3 = (0.1e1 / 0.2e1)*la;
  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, _t3, 0, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[3];
  const double dF_dla = _hc0[2];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
#endif
#if _KMAX >= 2
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, _t3, (0.1e1 / 0.2e1)*ta, _hc1);
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc1[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dla = (0.1e1 / 0.2e1)*_hc0[12];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[10];
  const double d2F_dgaa_dla = (0.1e1 / 0.4e1)*_hc0[9];
  const double d2F_dla2 = (0.1e1 / 0.2e1)*_hc0[7];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc1[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc1[33];
  const double d3F_dna2_dla = (0.1e1 / 0.4e1)*_hc1[32];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dla = (0.1e1 / 0.8e1)*_hc0[29];
  const double d3F_dna_dla2 = (0.1e1 / 0.4e1)*_hc0[27];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[24];
  const double d3F_dgaa2_dla = (0.1e1 / 0.16e2)*_hc0[23];
  const double d3F_dgaa_dla2 = (0.1e1 / 0.8e1)*_hc0[21];
  const double d3F_dla3 = (0.1e1 / 0.4e1)*_hc0[18];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc1[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc1[68];
  const double d4F_dna3_dla = (0.1e1 / 0.8e1)*_hc1[67];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc1[65];
  const double d4F_dna2_dgaa_dla = (0.1e1 / 0.16e2)*_hc1[64];
  const double d4F_dna2_dla2 = (0.1e1 / 0.8e1)*_hc1[62];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dla = (0.1e1 / 0.32e2)*_hc0[58];
  const double d4F_dna_dgaa_dla2 = (0.1e1 / 0.16e2)*_hc0[56];
  const double d4F_dna_dla3 = (0.1e1 / 0.8e1)*_hc0[53];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[49];
  const double d4F_dgaa3_dla = (0.1e1 / 0.64e2)*_hc0[48];
  const double d4F_dgaa2_dla2 = (0.1e1 / 0.32e2)*_hc0[46];
  const double d4F_dgaa_dla3 = (0.1e1 / 0.16e2)*_hc0[43];
  const double d4F_dla4 = (0.1e1 / 0.8e1)*_hc0[39];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
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
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, lb, 0, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc0[3];
  const double dF_dgbb = _hc1[3];
  const double dF_dla = _hc0[2];
  const double dF_dlb = _hc1[2];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 0] += dF_dla;
  if(out->vlapl != NULL) out->vlapl[ip*p->dim.vlapl + 1] += dF_dlb;
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
  const double d2F_dna_dla = _hc0[12];
  const double d2F_dnb_dlb = _hc1[12];
  const double d2F_dgaa2 = _hc0[10];
  const double d2F_dgbb2 = _hc1[10];
  const double d2F_dgaa_dla = _hc0[9];
  const double d2F_dgbb_dlb = _hc1[9];
  const double d2F_dla2 = _hc0[7];
  const double d2F_dlb2 = _hc1[7];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += d2F_dna_dla;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += d2F_dnb_dlb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 0] += d2F_dgaa_dla;
  if(out->v2sigmalapl != NULL) out->v2sigmalapl[ip*p->dim.v2sigmalapl + 5] += d2F_dgbb_dlb;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 0] += d2F_dla2;
  if(out->v2lapl2 != NULL) out->v2lapl2[ip*p->dim.v2lapl2 + 2] += d2F_dlb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc2[34];
  const double d3F_dnb3 = _hc3[34];
  const double d3F_dna2_dgaa = _hc2[33];
  const double d3F_dnb2_dgbb = _hc3[33];
  const double d3F_dna2_dla = _hc2[32];
  const double d3F_dnb2_dlb = _hc3[32];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dla = _hc0[29];
  const double d3F_dnb_dgbb_dlb = _hc1[29];
  const double d3F_dna_dla2 = _hc0[27];
  const double d3F_dnb_dlb2 = _hc1[27];
  const double d3F_dgaa3 = _hc0[24];
  const double d3F_dgbb3 = _hc1[24];
  const double d3F_dgaa2_dla = _hc0[23];
  const double d3F_dgbb2_dlb = _hc1[23];
  const double d3F_dgaa_dla2 = _hc0[21];
  const double d3F_dgbb_dlb2 = _hc1[21];
  const double d3F_dla3 = _hc0[18];
  const double d3F_dlb3 = _hc1[18];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += d3F_dna2_dla;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += d3F_dnb2_dlb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += d3F_dna_dgaa_dla;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 11] += d3F_dnb_dgbb_dlb;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += d3F_dna_dla2;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += d3F_dnb_dlb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 0] += d3F_dgaa2_dla;
  if(out->v3sigma2lapl != NULL) out->v3sigma2lapl[ip*p->dim.v3sigma2lapl + 11] += d3F_dgbb2_dlb;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 0] += d3F_dgaa_dla2;
  if(out->v3sigmalapl2 != NULL) out->v3sigmalapl2[ip*p->dim.v3sigmalapl2 + 8] += d3F_dgbb_dlb2;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 0] += d3F_dla3;
  if(out->v3lapl3 != NULL) out->v3lapl3[ip*p->dim.v3lapl3 + 3] += d3F_dlb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc2[69];
  const double d4F_dnb4 = _hc3[69];
  const double d4F_dna3_dgaa = _hc2[68];
  const double d4F_dnb3_dgbb = _hc3[68];
  const double d4F_dna3_dla = _hc2[67];
  const double d4F_dnb3_dlb = _hc3[67];
  const double d4F_dna2_dgaa2 = _hc2[65];
  const double d4F_dnb2_dgbb2 = _hc3[65];
  const double d4F_dna2_dgaa_dla = _hc2[64];
  const double d4F_dnb2_dgbb_dlb = _hc3[64];
  const double d4F_dna2_dla2 = _hc2[62];
  const double d4F_dnb2_dlb2 = _hc3[62];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dla = _hc0[58];
  const double d4F_dnb_dgbb2_dlb = _hc1[58];
  const double d4F_dna_dgaa_dla2 = _hc0[56];
  const double d4F_dnb_dgbb_dlb2 = _hc1[56];
  const double d4F_dna_dla3 = _hc0[53];
  const double d4F_dnb_dlb3 = _hc1[53];
  const double d4F_dgaa4 = _hc0[49];
  const double d4F_dgbb4 = _hc1[49];
  const double d4F_dgaa3_dla = _hc0[48];
  const double d4F_dgbb3_dlb = _hc1[48];
  const double d4F_dgaa2_dla2 = _hc0[46];
  const double d4F_dgbb2_dlb2 = _hc1[46];
  const double d4F_dgaa_dla3 = _hc0[43];
  const double d4F_dgbb_dlb3 = _hc1[43];
  const double d4F_dla4 = _hc0[39];
  const double d4F_dlb4 = _hc1[39];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += d4F_dna3_dla;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += d4F_dnb3_dlb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += d4F_dna2_dgaa_dla;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 17] += d4F_dnb2_dgbb_dlb;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += d4F_dna2_dla2;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += d4F_dnb2_dlb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += d4F_dna_dgaa2_dla;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 23] += d4F_dnb_dgbb2_dlb;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += d4F_dna_dgaa_dla2;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 17] += d4F_dnb_dgbb_dlb2;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += d4F_dna_dla3;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += d4F_dnb_dlb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 0] += d4F_dgaa3_dla;
  if(out->v4sigma3lapl != NULL) out->v4sigma3lapl[ip*p->dim.v4sigma3lapl + 19] += d4F_dgbb3_dlb;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 0] += d4F_dgaa2_dla2;
  if(out->v4sigma2lapl2 != NULL) out->v4sigma2lapl2[ip*p->dim.v4sigma2lapl2 + 17] += d4F_dgbb2_dlb2;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 0] += d4F_dgaa_dla3;
  if(out->v4sigmalapl3 != NULL) out->v4sigmalapl3[ip*p->dim.v4sigmalapl3 + 11] += d4F_dgbb_dlb3;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 0] += d4F_dla4;
  if(out->v4lapl4 != NULL) out->v4lapl4[ip*p->dim.v4lapl4 + 4] += d4F_dlb4;
#endif
#endif
}
#endif