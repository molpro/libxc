/*
  Generated from python/mgga_vxc/mgga_x_tb09.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_tb09
*/

#ifndef _MGGA_X_TB09_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_TB09_KERNEL_BODY
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_TB09_HELPER_BODIES
#include "mgga_x_tb09.c"
#undef _MGGA_X_TB09_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_TB09_HELPER_BODIES
#include "mgga_x_tb09.c"
#undef _MGGA_X_TB09_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_TB09_HELPER_BODIES
#include "mgga_x_tb09.c"
#undef _MGGA_X_TB09_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_TB09_HELPER_BODIES
#include "mgga_x_tb09.c"
#undef _MGGA_X_TB09_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_tb09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_tb09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_tb09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_tb09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_tb09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_tb09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_tb09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_tb09.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_TB09_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(br89_aux_dfdx_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = 0.2e1*x;
  const double _t2 = -_t1 + (x * x) + 0.3e1;
  const double _t3 = x - 0.2e1;
  const double _t4 = (0.1e1 / (_t3 * _t3));
  const double _t5 = exp(-0.2e1 / 0.3e1*x);
  const double _t6 = _t4*_t5;
  const double _t7 = (0.2e1 / 0.3e1)*_t6;
#if _KMAX >= 1
  const double _t8 = _t1 - 0.2e1;
  const double _t9 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t10 = _t5*_t9;
  const double _t11 = _t10*_t2;
  const double _t12 = _t2*_t6;
#endif
#if _KMAX >= 2
  const double _t13 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t14 = _t13*_t5;
  const double _t15 = _t14*_t2;
  const double _t16 = (0.16e2 / 0.9e1)*_t11 - 0.8e1 / 0.9e1*_t6*_t8;
#endif
#if _KMAX >= 3
  const double _t17 = xc_powi(_t3, -5);
  const double _t18 = _t2*_t5;
  const double _t19 = _t17*_t18;
#endif

  const double f = -_t2*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = (0.4e1 / 0.3e1)*_t11 + (0.4e1 / 0.9e1)*_t12 - _t7*_t8;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.8e1 / 0.27e2*_t12 - 0.4e1*_t15 - _t16 + (0.8e1 / 0.3e1)*_t5*_t8*_t9 - 0.4e1 / 0.3e1*_t6;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -0.16e2 / 0.3e1*_t10*_t8 + 0.8e1*_t10 + (0.16e2 / 0.81e2)*_t12 - 0.12e2*_t14*_t8 + 0.8e1*_t15 + _t16 + 0.16e2*_t19 + (0.8e1 / 0.3e1)*_t6;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = -0.64e2 / 0.3e1*_t10 - 0.128e3 / 0.81e2*_t11 - 0.32e2 / 0.243e3*_t12 + 0.32e2*_t13*_t5*_t8 - 0.48e2*_t14 - 0.32e2 / 0.3e1*_t15 + 0.64e2*_t17*_t5*_t8 - 0.80e2*_t18/xc_powi(_t3, 6) - 0.128e3 / 0.3e1*_t19 + (0.64e2 / 0.81e2)*_t4*_t5*_t8 + (0.64e2 / 0.9e1)*_t5*_t8*_t9 - 0.32e2 / 0.9e1*_t6;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(br89_Q_k, _KMAX)(const xc_func_type *p, double x, double u, double t, double *out) {


  const double f = -0.53333333333333333*t + (0.1e1 / 0.6e1)*u + 0.066666666666666666*(x * x);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -0.53333333333333333;
  out[1] = df_dt;
  const double df_du = 0.1e1 / 0.6e1;
  out[2] = df_du;
  const double df_dx = 0.13333333333333333*x;
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx_dt = 0;
  out[7] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[8] = d2f_dx_du;
  const double d2f_dx2 = 0.13333333333333333;
  out[9] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx_dt2 = 0;
  out[14] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[15] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[16] = d3f_dx_du2;
  const double d3f_dx2_dt = 0;
  out[17] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[18] = d3f_dx2_du;
  const double d3f_dx3 = 0;
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
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx_dt3 = 0;
  out[25] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[26] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[27] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[28] = d4f_dx_du3;
  const double d4f_dx2_dt2 = 0;
  out[29] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[30] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[31] = d4f_dx2_du2;
  const double d4f_dx3_dt = 0;
  out[32] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[33] = d4f_dx3_du;
  const double d4f_dx4 = 0;
  out[34] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(br89_cQ_k, _KMAX)(const xc_func_type *p, double Q, double *out) {

  const double _t1 = my_piecewise3(Q >= 0, Q, -Q) < 4.9999999999999999e-13;

  const double f = my_piecewise3(_t1, my_piecewise3(Q > 0, 4.9999999999999999e-13, -4.9999999999999999e-13), Q);
  out[0] = f;
#if _KMAX >= 1
  const double df_dQ = my_piecewise3(_t1, 0, 0.1e1);
  out[1] = df_dQ;
#endif
#if _KMAX >= 2
  const double d2f_dQ2 = 0;
  out[2] = d2f_dQ2;
#endif
#if _KMAX >= 3
  const double d3f_dQ3 = 0;
  out[3] = d3f_dQ3;
#endif
#if _KMAX >= 4
  const double d4f_dQ4 = 0;
  out[4] = d4f_dQ4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(br89_v_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (0.1e1 / 0.2e1)*x + 0.1e1;
  const double _t2 = xc_expm1(-x);
  const double _t3 = (0.1e1 / x);
  const double _t4 = _t2*_t3;
  const double _t5 = -_t1*_t4 - 0.1e1 / 0.2e1;
  const double _t6 = xc_powr(0.2e1, 2, 3)*M_CBRTPI*M_CBRTPI*exp((0.1e1 / 0.3e1)*x)/M_CBRT3;
  const double _t7 = (0.4e1 / 0.3e1)*_t6;
#if _KMAX >= 1
  const double _t8 = _t5*_t6;
  const double _t9 = (0.1e1 / (x * x));
  const double _t10 = _t2 + 0.1e1;
  const double _t11 = -_t10;
  const double _t12 = _t11*_t3;
  const double _t13 = _t1*_t12;
  const double _t14 = _t1*_t2*_t9 - _t13 - 0.1e1 / 0.2e1*_t4;
#endif
#if _KMAX >= 2
  const double _t15 = _t14*_t6;
  const double _t16 = (0.1e1 / (x * x * x));
  const double _t17 = _t16*_t2;
  const double _t18 = _t10*_t3;
  const double _t19 = _t1*_t18;
  const double _t20 = 0.2e1*_t1*_t11*_t9 - 0.2e1*_t1*_t17 - _t12 - _t19 + _t2*_t9;
  const double _t21 = _t20*_t7;
#endif
#if _KMAX >= 3
  const double _t22 = (0.1e1 / (x * x * x * x));
  const double _t23 = _t11*_t16;
  const double _t24 = 0.3e1*_t1*_t10*_t9 + 0.6e1*_t1*_t2*_t22 - 0.6e1*_t1*_t23 + 0.3e1*_t11*_t9 - _t13 - 0.3e1*_t17 - 0.3e1 / 0.2e1*_t18;
#endif

  const double f = -_t5*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -_t14*_t7 - 0.4e1 / 0.9e1*_t8;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.8e1 / 0.9e1*_t15 - _t21 - 0.4e1 / 0.27e2*_t8;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -0.4e1 / 0.9e1*_t15 - _t21 - _t24*_t7 - 0.4e1 / 0.81e2*_t8;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = -0.16e2 / 0.81e2*_t15 - 0.8e1 / 0.9e1*_t20*_t6 - 0.16e2 / 0.9e1*_t24*_t6 - _t7*(-0.12e2*_t1*_t10*_t16 + 0.24e2*_t1*_t11*_t22 + 0.4e1*_t1*_t11*_t9 - 0.24e2*_t1*_t2/xc_powi(x, 5) + 0.6e1*_t10*_t9 - 0.2e1*_t12 - _t19 + 0.12e2*_t2*_t22 - 0.12e2*_t23) - 0.4e1 / 0.243e3*_t8;
  out[4] = d4f_dx4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_tb09_params *params = (const mgga_x_tb09_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = lapl[0];
  const double ta = tau[0];

  const double _t1 = xc_powr(na, -4, 3);
  const double _t2 = M_CBRT2;
  const double _t3 = xc_powr(gaa, 1, 2);
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
  const double _t6 = xc_powr(0.2e1, 2, 3);
  const double _t7 = xc_powr(na, -5, 3);
  const double _t8 = _t6*_t7;
  const double _t10 = (0.1e1 / M_CBRTPI);
  const double _t11 = M_CBRT3*_t10;
  const double _t12 = _t11*params->c;
  const double _t13 = _t12*_t2;
  const double _t14 = (0.3e1 / 0.4e1)*_t13;
  const double _t15 = _t6*params->alpha;
  const double _t16 = _t15*gaa;
  const double _t17 = xc_powr(XC_EPSILON, 2, 3);
  const double _t18 = xc_powr(na, 8, 3);
  const double _t19 = (0.1e1 / _t18);
  const double _t20 = (0.1e1 / 0.8e1)*_t19;
  const double _t21 = _t20*(-_t16 - 0.8e1*_t17*_t18 + 0.8e1*_t6*na*ta) > 0;
  const double _t22 = my_piecewise3(_t21, -_t16*_t20 + _t6*_t7*ta, _t17);
  const double _t23 = xc_powr(_t22, 1, 2);
  const double _t24 = xc_powr(0.30e2, 1, 2);
  const double _t25 = (0.1e1 / M_PI);
  const double _t26 = 0.3e1*params->c;
  const double _t27 = _t26 - 0.2e1;
  const double _t28 = _t24*_t25*_t27;
  const double _t31 = xc_powr(na, 1, 3);
  const double _t32 = (0.1e1 / 0.2e1)*_t31;
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(br89_Q_k, _KMAX)(p, _t5, _t8*la, _t8*ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_cQ_k, _KMAX)(p, _hc0[0], _hc1);
  const double _t9 = xc_mgga_x_br89_get_x(_hc1[0]);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_v_k, _KMAX)(p, _t9, _hc2);
  const double _t29 = _hc2[0]*_t14 + (0.1e1 / 0.6e1)*_t23*_t28;
  const double _t30 = _t29*_t6;
  const double vrho_0 = _t30*_t32;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += vrho_0;
#if _KMAX >= 2
  const double _t33 = xc_powr(na, -2, 3);
  const double _t34 = (0.1e1 / 0.6e1)*_t33;
  const double _t35 = _t19*_t6;
  const double _t36 = (0.5e1 / 0.3e1)*_t35;
  const double _t37 = _t36*ta;
  const double _t40 = xc_powr(na, -7, 3);
  const double _t41 = (0.4e1 / 0.3e1)*_t40;
  const double _t45 = (M_CBRTPI * M_CBRTPI);
  const double _t51 = xc_powr(na, -11, 3);
  const double _t52 = (0.1e1 / 0.3e1)*_t51;
  const double _t53 = my_piecewise3(_t21, _t16*_t52 - _t37, 0);
  const double _t54 = (0.1e1 / _t23);
  const double _t56 = _t32*_t6;
  const double _t57 = (0.1e1 / _t3);
  const double _t64 = my_piecewise3(_t21, -_t15*_t20, 0);
  const double _t69 = my_piecewise3(_t21, _t8, 0);
  const double _t43 = (0.1e1 / ((_hc1[0]) * (_hc1[0])));
  const double _t44 = _hc1[1]*_t43;
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_aux_dfdx_k, _KMAX)(p, _t9, _hc3);
  double _hc4[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(br89_Q_k, _KMAX)(p, 0, 0, 0, _hc4);
  double _hc5[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(br89_Q_k, _KMAX)(p, _t5, 0, 0, _hc5);
  const double _t38 = _hc4[2]*la;
  const double _t39 = _hc5[3]*_t4;
  const double _t42 = -_hc4[1]*_t37 - _t36*_t38 - _t39*_t41;
  const double _t46 = (0.1e1 / (_hc3[0]));
  const double _t47 = _t45*_t46;
  const double _t48 = _hc2[1]*_t47;
  const double _t49 = _t13*_t48;
  const double _t50 = _t44*_t49;
  const double _t55 = (0.1e1 / 0.12e2)*_t24*_t25*_t27*_t53*_t54 - 0.1e1 / 0.2e1*_t42*_t50;
  const double _t58 = _hc5[3]*_t57;
  const double _t59 = _t58*_t6;
  const double _t60 = _hc2[1]*_t12;
  const double _t61 = _t47*_t60;
  const double _t62 = _t44*_t61;
  const double _t63 = _t1*_t62;
  const double _t65 = (0.1e1 / 0.12e2)*_t24*_t25*_t27*_t54*_t64 - 0.1e1 / 0.4e1*_t59*_t63;
  const double _t66 = _hc4[2]*_t62;
  const double _t67 = _t6*_t66;
  const double _t68 = _hc4[1]*_t7;
  const double _t70 = (0.1e1 / 0.12e2)*_t24*_t25*_t27*_t54*_t69 - _t62*_t68;
  const double v2rho2_0 = _t30*_t34 + _t55*_t56;
  const double v2rhosigma_0 = _t56*_t65;
  const double v2rholapl_0 = -0.1e1 / 0.2e1*_t1*_t67;
  const double v2rhotau_0 = _t56*_t70;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += v2rho2_0;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += v2rhosigma_0;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += v2rholapl_0;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += v2rhotau_0;
#endif
#if _KMAX >= 3
  const double _t71 = (0.1e1 / 0.9e1)*_t8;
  const double _t72 = _t33*_t6;
  const double _t77 = (M_PI * M_CBRTPI);
  const double _t85 = _t51*_t6;
  const double _t86 = (0.40e2 / 0.9e1)*_t85;
  const double _t87 = xc_powr(na, -14, 3);
  const double _t91 = xc_powr(na, -10, 3);
  const double _t95 = (0.11e2 / 0.9e1)*_t87;
  const double _t96 = my_piecewise3(_t21, -_t16*_t95 + (0.40e2 / 0.9e1)*_t51*_t6*ta, 0);
  const double _t97 = xc_powr(_t22, -3, 2);
  const double _t98 = (0.1e1 / 0.24e2)*_t97;
  const double _t99 = (_t53 * _t53);
  const double _t101 = _t34*_t6;
  const double _t103 = (0.2e1 / 0.3e1)*_t2;
  const double _t110 = my_piecewise3(_t21, _t15*_t52, 0);
  const double _t111 = _t28*_t53;
  const double _t112 = _t111*_t98;
  const double _t114 = (0.5e1 / 0.3e1)*_t19;
  const double _t127 = my_piecewise3(_t21, -_t36, 0);
  const double _t128 = (0.1e1 / 0.12e2)*_t28*_t54;
  const double _t130 = (0.1e1 / gaa);
  const double _t131 = _t130*_t19;
  const double _t133 = xc_powr(gaa, -3, 2);
  const double _t138 = (_t64 * _t64);
  const double _t139 = _t28*_t98;
  const double _t141 = (0.1e1 / (na * na * na));
  const double _t153 = _t139*_t64;
  const double _t166 = (_t69 * _t69);
  const double _t74 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t75 = ((_hc1[1]) * (_hc1[1]));
  const double _t78 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t80 = _t77*_t78;
  const double _t81 = (0.1e1 / 0.3e1)*_t2*_t80;
  const double _t136 = _t75*_t80;
  const double _t73 = (0.1e1 / 0.3e1)*_t55;
  const double _t76 = (_t42 * _t42);
  const double _t79 = (0.1e1 / ((_hc3[0]) * (_hc3[0])));
  const double _t82 = (0.1e1 / ((_hc3[0]) * (_hc3[0]) * (_hc3[0])));
  const double _t83 = _hc3[1]*_t82;
  const double _t84 = _t60*_t83;
  const double _t88 = _hc4[9]*_t6;
  const double _t89 = _t87*_t88;
  const double _t90 = _t89*gaa;
  const double _t92 = _t39*_t91;
  const double _t93 = _hc4[1]*_t86*ta + _t38*_t86 + (0.16e2 / 0.9e1)*_t90 + (0.28e2 / 0.9e1)*_t92;
  const double _t94 = (0.1e1 / 0.2e1)*_t50;
  const double _t100 = M_CBRT3*_hc2[1]*_t10*_t2*_t45*_t46*_t74*_t75*_t76*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_t10*_t2*_t75*_t76*_t77*_t78*_t79*params->c + (0.1e1 / 0.12e2)*_t24*_t25*_t27*_t54*_t96 - _t28*_t98*_t99 - _t75*_t76*_t81*_t84 - _t93*_t94;
  const double _t102 = _hc4[9]*_t85;
  const double _t104 = _t103*_t58;
  const double _t105 = -0.2e1 / 0.3e1*_t102 - _t104*_t40;
  const double _t106 = _t1*_t59;
  const double _t107 = _t42*_t75;
  const double _t108 = _t80*_t84;
  const double _t109 = (0.1e1 / 0.6e1)*_t107*_t108;
  const double _t113 = (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_hc5[3]*_t1*_t10*_t42*_t45*_t46*_t57*_t6*_t74*_t75*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_hc5[3]*_t1*_t10*_t42*_t57*_t6*_t75*_t77*_t78*_t79*params->c - _t105*_t94 - _t106*_t109 + (0.1e1 / 0.12e2)*_t110*_t24*_t25*_t27*_t54 - _t112*_t64;
  const double _t115 = _hc4[2]*_t7;
  const double _t116 = _t107*_t115;
  const double _t117 = _t61*_t74;
  const double _t118 = 0.2e1*_t117;
  const double _t119 = _hc2[2]*_t12;
  const double _t120 = _t119*_t79;
  const double _t121 = _t120*_t80;
  const double _t122 = (0.2e1 / 0.3e1)*_t121;
  const double _t123 = (0.2e1 / 0.3e1)*_t108;
  const double _t124 = _t114*_t66 + _t116*_t118 + _t116*_t122 - _t116*_t123;
  const double _t125 = _hc4[1]*_t62;
  const double _t126 = _t107*_t68;
  const double _t129 = -_t112*_t69 + _t114*_t125 + _t118*_t126 + _t122*_t126 - _t123*_t126 + _t127*_t128;
  const double _t132 = _hc4[9]*_t62;
  const double _t134 = ((_hc5[3]) * (_hc5[3]));
  const double _t135 = _t131*_t134;
  const double _t137 = _t136*_t84;
  const double _t140 = (0.1e1 / 0.8e1)*M_CBRT3*_hc1[1]*_hc2[1]*_hc5[3]*_t1*_t10*_t133*_t43*_t45*_t46*_t6*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_t10*_t130*_t134*_t19*_t45*_t46*_t74*_t75*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_t10*_t130*_t134*_t19*_t75*_t77*_t78*_t79*params->c - 0.1e1 / 0.4e1*_t131*_t132 - 0.1e1 / 0.6e1*_t135*_t137 - _t138*_t139;
  const double _t142 = _hc4[2]*_t141;
  const double _t143 = _t2*_t58;
  const double _t144 = _t117*_t75;
  const double _t145 = _t143*_t144;
  const double _t146 = _t121*_t75;
  const double _t147 = (0.1e1 / 0.3e1)*_t146;
  const double _t148 = _t142*_t143;
  const double _t149 = (0.1e1 / 0.3e1)*_t137;
  const double _t150 = _t142*_t145 + _t147*_t148 - _t148*_t149;
  const double _t151 = _hc4[1]*_t141;
  const double _t152 = _t143*_t151;
  const double _t154 = _t145*_t151 + _t147*_t152 - _t149*_t152 - _t153*_t69;
  const double _t155 = ((_hc4[2]) * (_hc4[2]));
  const double _t156 = _t141*_t155;
  const double _t157 = _t156*_t75;
  const double _t158 = _t49*_t74;
  const double _t159 = 0.2e1*_t158;
  const double _t160 = _t103*_t146;
  const double _t161 = _hc4[1]*_t142;
  const double _t162 = ((_hc4[1]) * (_hc4[1]));
  const double _t163 = _t162*_t6;
  const double _t164 = _t163*_t91;
  const double _t165 = (0.2e1 / 0.3e1)*_t137;
  const double _t167 = _t118*_t164*_t75 + _t122*_t164*_t75 - _t139*_t166 - _t164*_t165;
  const double v3rho3_0 = _t100*_t56 - _t29*_t71 + _t72*_t73;
  const double v3rho2sigma_0 = _t101*_t65 + _t113*_t56;
  const double v3rho2lapl_0 = (0.1e1 / 0.2e1)*_t124*_t31*_t6 - 0.1e1 / 0.6e1*_t40*_t67;
  const double v3rho2tau_0 = _t101*_t70 + _t129*_t56;
  const double v3rhosigma2_0 = _t140*_t56;
  const double v3rhosigmalapl_0 = _t150*_t56;
  const double v3rhosigmatau_0 = _t154*_t56;
  const double v3rholapl2_0 = -_t103*_t108*_t157 + _t156*_t160 + _t157*_t159;
  const double v3rholapltau_0 = -_t103*_t137*_t161 + _t159*_t161*_t75 + _t160*_t161;
  const double v3rhotau2_0 = _t167*_t56;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += v3rho3_0;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += v3rho2sigma_0;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += v3rho2lapl_0;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += v3rho2tau_0;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += v3rhosigma2_0;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += v3rhosigmalapl_0;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += v3rhosigmatau_0;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += v3rholapl2_0;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += v3rholapltau_0;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += v3rhotau2_0;
#endif
#if _KMAX >= 4
  const double _t179 = (M_PI * M_PI);
  const double _t194 = (0.440e3 / 0.27e2)*_t87;
  const double _t195 = _t194*_t6*ta;
  const double _t196 = xc_powr(na, -17, 3);
  const double _t197 = xc_powr(na, -13, 3);
  const double _t199 = (0.80e2 / 0.9e1)*_t85;
  const double _t204 = xc_powr(_t22, -5, 2);
  const double _t205 = (0.1e1 / 0.16e2)*_t204*_t28;
  const double _t206 = _t111*_t97;
  const double _t207 = (0.1e1 / 0.3e1)*_t72;
  const double _t218 = (0.1e1 / 0.12e2)*_t206;
  const double _t219 = (0.40e2 / 0.9e1)*_t51;
  const double _t229 = _t139*_t69;
  const double _t230 = (0.1e1 / 0.3e1)*_t130;
  const double _t235 = _t1*_t6;
  const double _t237 = (0.1e1 / 0.12e2)*_t28*_t97;
  const double _t238 = (0.1e1 / (na * na * na * na));
  const double _t248 = _t103*_t238;
  const double _t256 = _t197*_t6;
  const double _t259 = _t6*_t91;
  const double _t269 = _t19/(gaa * gaa);
  const double _t272 = _t14*_t238;
  const double _t313 = xc_powi(na, -5);
  const double _t168 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t174 = xc_powi((_hc1[0]), -5);
  const double _t175 = _t174*_t77;
  const double _t176 = 0.2e1*_t175;
  const double _t180 = xc_powi((_hc1[0]), -6);
  const double _t181 = _t179*_t180;
  const double _t297 = _t168*_t87;
  const double _t169 = _t168*(_t42 * _t42 * _t42);
  const double _t170 = _t48*_t78;
  const double _t171 = _t11*_t170*_t26;
  const double _t172 = _hc2[2]*_t79;
  const double _t173 = _t13*_t169;
  const double _t177 = _t173*_t176;
  const double _t178 = (0.2e1 / 0.9e1)*_t82;
  const double _t182 = _hc2[3]*_t181;
  const double _t183 = _t178*_t182;
  const double _t184 = _hc2[1]*_t83;
  const double _t185 = (0.1e1 / ((_hc3[0]) * (_hc3[0]) * (_hc3[0]) * (_hc3[0])));
  const double _t186 = _t181*_t185;
  const double _t187 = _hc2[1]*_t186;
  const double _t188 = _t103*_t169;
  const double _t189 = _hc3[1]*_t186;
  const double _t190 = _t119*_t189;
  const double _t191 = _t181*_t60;
  const double _t192 = ((_hc3[1]) * (_hc3[1]))/xc_powi((_hc3[0]), 5);
  const double _t193 = _t191*_t192;
  const double _t198 = _t107*_t158;
  const double _t200 = _hc4[1]*_t199*ta + _t199*_t38 + (0.32e2 / 0.9e1)*_t90 + (0.56e2 / 0.9e1)*_t92;
  const double _t201 = _t107*_t81;
  const double _t202 = _t120*_t201;
  const double _t203 = _t201*_t84;
  const double _t208 = _t120*_t175;
  const double _t209 = _t168*_t76;
  const double _t210 = _t106*_t209;
  const double _t211 = _t61*_t78;
  const double _t212 = (0.3e1 / 0.2e1)*_t211;
  const double _t213 = _t182*_t82;
  const double _t214 = _t12*_t213;
  const double _t215 = (0.1e1 / 0.9e1)*_t214;
  const double _t216 = (0.1e1 / 0.6e1)*_t137;
  const double _t217 = -0.4e1 / 0.3e1*_t102 - _t143*_t41;
  const double _t220 = (0.20e2 / 0.3e1)*_hc4[2];
  const double _t221 = _t107*_t19;
  const double _t222 = _t117*_t221;
  const double _t223 = (0.20e2 / 0.9e1)*_t121*_t221;
  const double _t224 = 0.6e1*_t211;
  const double _t225 = _t115*_t209;
  const double _t226 = 0.4e1*_t208;
  const double _t227 = (0.4e1 / 0.9e1)*_t214;
  const double _t228 = _t209*_t68;
  const double _t231 = _t168*_t42;
  const double _t232 = _t135*_t231;
  const double _t233 = _hc5[3]*_t133;
  const double _t234 = (0.1e1 / 0.4e1)*_t233;
  const double _t236 = _t193*_t231;
  const double _t239 = _hc4[2]*_t238;
  const double _t240 = (0.5e1 / 0.3e1)*_t145;
  const double _t241 = (0.5e1 / 0.9e1)*_t143*_t146;
  const double _t242 = _t148*_t231;
  const double _t243 = _t120*_t176;
  const double _t244 = _t12*_t183;
  const double _t245 = _hc4[1]*_t238;
  const double _t246 = _t152*_t231;
  const double _t247 = _t144*_t155;
  const double _t249 = _t136*_t155;
  const double _t250 = _t13*_t172;
  const double _t251 = _t238*_t250;
  const double _t252 = (0.2e1 / 0.9e1)*_t251;
  const double _t253 = _hc2[1]*_t13;
  const double _t254 = _t238*_t253;
  const double _t255 = _hc3[1]*_t178*_t254;
  const double _t257 = (0.20e2 / 0.9e1)*_t146;
  const double _t258 = _t224*_t231;
  const double _t260 = _t155*_t259;
  const double _t261 = _t231*_t260;
  const double _t262 = _hc4[1]*_hc4[2];
  const double _t263 = _t136*_t262;
  const double _t264 = _hc4[1]*_t256;
  const double _t265 = _t259*_t262;
  const double _t266 = _t231*_t265;
  const double _t267 = _t163*_t197;
  const double _t268 = _t164*_t231;
  const double _t270 = _t134*_t269;
  const double _t271 = (0.1e1 / 0.4e1)*_t270;
  const double _t273 = _t233*_t75;
  const double _t274 = _hc4[9]*_t136*_t234;
  const double _t275 = ((_hc5[3]) * (_hc5[3]) * (_hc5[3]))*_t133*_t168;
  const double _t276 = (0.1e1 / 0.2e1)*_t175*_t275;
  const double _t277 = _t13*_t213;
  const double _t278 = _t238*_t275;
  const double _t279 = (0.1e1 / 0.18e2)*_t278;
  const double _t280 = _t13*_t184;
  const double _t281 = _t238*_t280;
  const double _t282 = _t181*_t192;
  const double _t283 = (0.1e1 / 0.2e1)*_t158*_t273;
  const double _t284 = (0.1e1 / 0.6e1)*_t136*_t233;
  const double _t285 = _t250*_t284;
  const double _t286 = _t134*_t168;
  const double _t287 = _t208*_t286;
  const double _t288 = _hc4[2]*_t130;
  const double _t289 = _t256*_t288;
  const double _t290 = _t197*_t88;
  const double _t291 = _t286*_t289;
  const double _t292 = _t230*_t286;
  const double _t293 = _t193*_t292;
  const double _t294 = _hc4[1]*_t130*_t290;
  const double _t295 = _t130*_t264;
  const double _t296 = _t286*_t295;
  const double _t298 = _t297*_t58;
  const double _t299 = _t155*_t298;
  const double _t300 = _t262*_t298;
  const double _t301 = _t162*_t298;
  const double _t302 = ((_hc4[2]) * (_hc4[2]) * (_hc4[2]));
  const double _t303 = _t297*_t302;
  const double _t304 = 0.12e2*_t211;
  const double _t305 = _t297*_t304;
  const double _t306 = _hc4[1]*_t155;
  const double _t307 = _t297*_t306;
  const double _t308 = 0.8e1*_t208;
  const double _t309 = (0.8e1 / 0.9e1)*_t214;
  const double _t310 = _hc4[2]*_t162;
  const double _t311 = _t297*_t310;
  const double _t312 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]));
  const double _t314 = _t168*_t312*_t313;
  const double v4rho4_0 = (0.1e1 / 0.2e1)*_t100*_t72 + (0.5e1 / 0.27e2)*_t29*_t35 + _t56*((0.2e1 / 0.9e1)*_hc3[2]*_t173*_t187 + _t128*my_piecewise3(_t21, (0.154e3 / 0.27e2)*_t16*_t196 - _t195, 0) - _t169*_t171*_t2 - _t172*_t177 - _t173*_t183 + _t177*_t184 + _t188*_t190 - _t188*_t193 + _t198*_t200 + _t198*_t93 + _t200*_t202 - _t200*_t203 + _t202*_t93 - _t203*_t93 + _t205*(_t53 * _t53 * _t53) - 0.1e1 / 0.8e1*_t206*_t96 - _t94*(-_hc4[1]*_t195 - _t194*_t38*_t6 - 0.112e3 / 0.9e1*_t196*_t88*gaa - 0.280e3 / 0.27e2*_t197*_t39)) - _t73*_t8;
  const double v4rho3sigma_0 = _t113*_t207 + _t56*(M_CBRT3*_hc2[1]*_hc3[1]*_hc5[3]*_t1*_t10*_t168*_t174*_t57*_t6*_t76*_t77*_t82*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc5[3]*_t1*_t10*_t168*_t179*_t180*_t185*_t57*_t6*_t76*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_hc5[3]*_t1*_t10*_t45*_t46*_t57*_t6*_t74*_t75*_t93*params->c + M_CBRT3*_hc2[1]*_t10*_t2*_t217*_t42*_t45*_t46*_t74*_t75*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc5[3]*_t1*_t10*_t168*_t179*_t180*_t185*_t57*_t6*_t76*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_hc5[3]*_t1*_t10*_t57*_t6*_t75*_t77*_t78*_t79*_t93*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_t10*_t2*_t217*_t42*_t75*_t77*_t78*_t79*params->c - _t106*_t216*_t93 - _t110*_t218 - _t153*_t96 - 0.1e1 / 0.3e1*_t193*_t210 - _t203*_t217 + (0.1e1 / 0.16e2)*_t204*_t24*_t25*_t27*_t64*_t99 - _t208*_t210 - _t210*_t212 - _t210*_t215 + (0.1e1 / 0.12e2)*_t24*_t25*_t27*_t54*my_piecewise3(_t21, -_t15*_t95, 0) - _t94*((0.14e2 / 0.9e1)*_t143*_t91 + (0.10e2 / 0.3e1)*_t89)) - _t65*_t71;
  const double v4rho3lapl_0 = _t124*_t207 + _t56*(0.4e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[2]*_t10*_t168*_t174*_t7*_t76*_t77*_t82*params->c + (0.20e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[2]*_t10*_t19*_t42*_t75*_t77*_t78*_t82*params->c + (0.4e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[2]*_t10*_t168*_t179*_t180*_t185*_t7*_t76*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc4[2]*_t10*_t45*_t46*_t7*_t74*_t75*_t93*params->c + (0.4e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[2]*_t10*_t168*_t179*_t180*_t185*_t7*_t76*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc4[2]*_t10*_t7*_t75*_t77*_t78*_t79*_t93*params->c - _hc4[2]*_t223 - _t115*_t165*_t93 - 0.4e1 / 0.3e1*_t193*_t225 - _t219*_t66 - _t220*_t222 - _t224*_t225 - _t225*_t226 - _t225*_t227) + (0.1e1 / 0.9e1)*_t67*_t91;
  const double v4rho3tau_0 = _t129*_t207 + _t56*(0.4e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[1]*_t10*_t168*_t174*_t7*_t76*_t77*_t82*params->c + (0.20e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[1]*_t10*_t19*_t42*_t75*_t77*_t78*_t82*params->c + (0.4e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[1]*_t10*_t168*_t179*_t180*_t185*_t7*_t76*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc4[1]*_t10*_t45*_t46*_t7*_t74*_t75*_t93*params->c + (0.4e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[1]*_t10*_t168*_t179*_t180*_t185*_t7*_t76*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc4[1]*_t10*_t7*_t75*_t77*_t78*_t79*_t93*params->c - 0.20e2 / 0.3e1*_hc4[1]*_t222 - _hc4[1]*_t223 - _t125*_t219 - _t127*_t218 - _t165*_t68*_t93 - 0.4e1 / 0.3e1*_t193*_t228 + (0.1e1 / 0.16e2)*_t204*_t24*_t25*_t27*_t69*_t99 - _t224*_t228 - _t226*_t228 - _t227*_t228 - _t229*_t96 + (0.1e1 / 0.12e2)*_t24*_t25*_t27*_t54*my_piecewise3(_t21, _t86, 0)) - _t70*_t71;
  const double v4rho2sigma2_0 = _t101*_t140 + _t56*((0.1e1 / 0.12e2)*M_CBRT3*_hc2[1]*_hc3[1]*_hc5[3]*_t1*_t10*_t133*_t42*_t6*_t75*_t77*_t78*_t82*params->c + M_CBRT3*_hc2[1]*_hc3[1]*_t10*_t130*_t134*_t168*_t174*_t19*_t42*_t77*_t82*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_t10*_t130*_t134*_t168*_t179*_t180*_t185*_t19*_t42*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_hc4[9]*_t10*_t130*_t19*_t42*_t45*_t46*_t74*_t75*params->c + M_CBRT3*_hc2[1]*_hc5[3]*_t1*_t10*_t105*_t45*_t46*_t57*_t6*_t74*_t75*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_t10*_t130*_t134*_t168*_t179*_t180*_t185*_t19*_t42*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_hc4[9]*_t10*_t130*_t19*_t42*_t75*_t77*_t78*_t79*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc5[3]*_t1*_t10*_t105*_t57*_t6*_t75*_t77*_t78*_t79*params->c - _hc4[9]*_t109*_t131 - _t105*_t106*_t149 - _t107*_t117*_t234*_t235 - 0.1e1 / 0.12e2*_t107*_t121*_t233*_t235 - _t110*_t237*_t64 - _t134*_t19*_t230*_t236 + (0.1e1 / 0.16e2)*_t138*_t204*_t24*_t25*_t27*_t53 - _t208*_t232 - _t212*_t232 - _t215*_t232 - _t94*((0.1e1 / 0.3e1)*_hc5[3]*_t133*_t2*_t40 - _t102*_t230));
  const double v4rho2sigmalapl_0 = _t101*_t150 + _t56*(0.2e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[2]*_hc5[3]*_t10*_t141*_t168*_t174*_t2*_t42*_t57*_t77*_t82*params->c + (0.5e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[2]*_hc5[3]*_t10*_t2*_t238*_t57*_t75*_t77*_t78*_t82*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[2]*_hc5[3]*_t10*_t141*_t168*_t179*_t180*_t185*_t2*_t42*_t57*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc4[2]*_t10*_t105*_t45*_t46*_t7*_t74*_t75*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[2]*_hc5[3]*_t10*_t141*_t168*_t179*_t180*_t185*_t2*_t42*_t57*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc4[2]*_t10*_t105*_t7*_t75*_t77*_t78*_t79*params->c - _t104*_t142*_t236 - _t105*_t115*_t165 - _t171*_t242 - _t239*_t240 - _t239*_t241 - _t242*_t243 - _t242*_t244);
  const double v4rho2sigmatau_0 = _t101*_t154 + _t56*(0.2e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[1]*_hc5[3]*_t10*_t141*_t168*_t174*_t2*_t42*_t57*_t77*_t82*params->c + (0.5e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[1]*_hc5[3]*_t10*_t2*_t238*_t57*_t75*_t77*_t78*_t82*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[1]*_hc5[3]*_t10*_t141*_t168*_t179*_t180*_t185*_t2*_t42*_t57*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc4[1]*_t10*_t105*_t45*_t46*_t7*_t74*_t75*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[1]*_hc5[3]*_t10*_t141*_t168*_t179*_t180*_t185*_t2*_t42*_t57*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc4[1]*_t10*_t105*_t7*_t75*_t77*_t78*_t79*params->c - _t104*_t151*_t236 - _t105*_t165*_t68 - _t110*_t229 - _t127*_t153 - _t171*_t246 + (0.1e1 / 0.16e2)*_t204*_t24*_t25*_t27*_t53*_t64*_t69 - _t240*_t245 - _t241*_t245 - _t243*_t246 - _t244*_t246);
  const double v4rho2lapl2_0 = _t247*_t248 + _t249*_t252 - _t249*_t255 + _t56*(0.4e1*M_CBRT3*_hc2[1]*_hc3[1]*_t10*_t155*_t168*_t174*_t42*_t6*_t77*_t82*_t91*params->c + (0.20e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[1]*_t10*_t155*_t197*_t6*_t75*_t77*_t78*_t82*params->c + (0.4e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_t10*_t155*_t168*_t179*_t180*_t185*_t42*_t6*_t91*params->c + (0.4e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_t10*_t155*_t168*_t179*_t180*_t185*_t42*_t6*_t91*params->c - _t155*_t256*_t257 - 0.4e1 / 0.3e1*_t193*_t261 - _t226*_t261 - _t227*_t261 - 0.20e2 / 0.3e1*_t247*_t256 - _t258*_t260);
  const double v4rho2lapltau_0 = _t144*_t248*_t262 + _t252*_t263 - _t255*_t263 + _t56*(0.4e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[1]*_hc4[2]*_t10*_t168*_t174*_t42*_t6*_t77*_t82*_t91*params->c + (0.20e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[1]*_hc4[2]*_t10*_t197*_t6*_t75*_t77*_t78*_t82*params->c + (0.4e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[1]*_hc4[2]*_t10*_t168*_t179*_t180*_t185*_t42*_t6*_t91*params->c + (0.4e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[1]*_hc4[2]*_t10*_t168*_t179*_t180*_t185*_t42*_t6*_t91*params->c - _hc4[2]*_t257*_t264 - _t144*_t220*_t264 - _t226*_t266 - _t227*_t266 - 0.4e1 / 0.3e1*_t236*_t265 - _t258*_t265);
  const double v4rho2tau2_0 = _t101*_t167 + _t56*(0.4e1*M_CBRT3*_hc2[1]*_hc3[1]*_t10*_t162*_t168*_t174*_t42*_t6*_t77*_t82*_t91*params->c + (0.20e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[1]*_t10*_t162*_t197*_t6*_t75*_t77*_t78*_t82*params->c + (0.4e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_t10*_t162*_t168*_t179*_t180*_t185*_t42*_t6*_t91*params->c + (0.4e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_t10*_t162*_t168*_t179*_t180*_t185*_t42*_t6*_t91*params->c - _t127*_t237*_t69 - 0.20e2 / 0.3e1*_t144*_t267 - _t164*_t258 + (0.1e1 / 0.16e2)*_t166*_t204*_t24*_t25*_t27*_t53 - 0.4e1 / 0.3e1*_t193*_t268 - _t226*_t268 - _t227*_t268 - _t257*_t267);
  const double v4rhosigma3_0 = _t56*((0.1e1 / 0.6e1)*_hc2[2]*_t13*_t189*_t278 + _hc3[2]*_t13*_t187*_t279 + _hc4[9]*_t272*_t273*_t48*_t74 - 0.3e1 / 0.16e2*_hc5[3]*_t6*_t63/xc_powr(gaa, 5, 2) + (0.3e1 / 0.8e1)*_t132*_t269 + _t137*_t271 - 0.3e1 / 0.4e1*_t144*_t270 - _t146*_t271 - _t170*_t272*_t275 + _t205*(_t64 * _t64 * _t64) + _t251*_t274 - _t251*_t276 - 0.1e1 / 0.6e1*_t254*_t275*_t282 - _t274*_t281 + _t276*_t281 - _t277*_t279);
  const double v4rhosigma2lapl_0 = _t56*((0.1e1 / 0.6e1)*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[2]*_hc5[3]*_t10*_t133*_t141*_t2*_t75*_t77*_t78*_t82*params->c + M_CBRT3*_hc2[1]*_hc3[1]*_hc4[2]*_t10*_t130*_t134*_t168*_t174*_t197*_t6*_t77*_t82*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[2]*_t10*_t130*_t134*_t168*_t179*_t180*_t185*_t197*_t6*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_hc4[2]*_hc4[9]*_t10*_t130*_t197*_t45*_t46*_t6*_t74*_t75*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[2]*_t10*_t130*_t134*_t168*_t179*_t180*_t185*_t197*_t6*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_hc4[2]*_hc4[9]*_t10*_t130*_t197*_t6*_t75*_t77*_t78*_t79*params->c - _hc4[2]*_t256*_t293 - _t142*_t283 - _t142*_t285 - _t212*_t291 - _t215*_t291 - _t216*_t288*_t290 - _t287*_t289);
  const double v4rhosigma2tau_0 = _t56*((0.1e1 / 0.9e1)*_hc3[2]*_t185*_t191*_t296 + _t138*_t205*_t69 + (0.1e1 / 0.2e1)*_t144*_t294 + (0.1e1 / 0.6e1)*_t146*_t294 + _t151*_t280*_t284 - _t151*_t283 - _t151*_t285 + _t175*_t296*_t84 + _t190*_t264*_t292 - _t212*_t296 - _t215*_t296 - _t216*_t294 - _t264*_t293 - _t287*_t295);
  const double v4rhosigmalapl2_0 = _t56*(0.4e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc5[3]*_t10*_t155*_t168*_t174*_t57*_t77*_t82*_t87*params->c + (0.4e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc5[3]*_t10*_t155*_t168*_t179*_t180*_t185*_t57*_t87*params->c + (0.4e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc5[3]*_t10*_t155*_t168*_t179*_t180*_t185*_t57*_t87*params->c - 0.4e1 / 0.3e1*_t193*_t299 - _t224*_t299 - _t226*_t299 - _t227*_t299);
  const double v4rhosigmalapltau_0 = _t56*(0.4e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[1]*_hc4[2]*_hc5[3]*_t10*_t168*_t174*_t57*_t77*_t82*_t87*params->c + (0.4e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[1]*_hc4[2]*_hc5[3]*_t10*_t168*_t179*_t180*_t185*_t57*_t87*params->c + (0.4e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[1]*_hc4[2]*_hc5[3]*_t10*_t168*_t179*_t180*_t185*_t57*_t87*params->c - 0.4e1 / 0.3e1*_t193*_t300 - _t224*_t300 - _t226*_t300 - _t227*_t300);
  const double v4rhosigmatau2_0 = _t56*(0.4e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc5[3]*_t10*_t162*_t168*_t174*_t57*_t77*_t82*_t87*params->c + (0.4e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc5[3]*_t10*_t162*_t168*_t179*_t180*_t185*_t57*_t87*params->c + (0.4e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc5[3]*_t10*_t162*_t168*_t179*_t180*_t185*_t57*_t87*params->c + (0.1e1 / 0.16e2)*_t166*_t204*_t24*_t25*_t27*_t64 - 0.4e1 / 0.3e1*_t193*_t301 - _t224*_t301 - _t226*_t301 - _t227*_t301);
  const double v4rholapl3_0 = 0.8e1*M_CBRT3*_hc2[1]*_hc3[1]*_t10*_t168*_t174*_t302*_t77*_t82*_t87*params->c + (0.8e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_t10*_t168*_t179*_t180*_t185*_t302*_t87*params->c + (0.8e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_t10*_t168*_t179*_t180*_t185*_t302*_t87*params->c - 0.8e1 / 0.3e1*_t193*_t303 - 0.8e1*_t208*_t303 - 0.8e1 / 0.9e1*_t214*_t303 - _t303*_t304;
  const double v4rholapl2tau_0 = 0.8e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[1]*_t10*_t155*_t168*_t174*_t77*_t82*_t87*params->c + (0.8e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[1]*_t10*_t155*_t168*_t179*_t180*_t185*_t87*params->c + (0.8e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[1]*_t10*_t155*_t168*_t179*_t180*_t185*_t87*params->c - 0.8e1 / 0.3e1*_t193*_t307 - _t305*_t306 - _t307*_t308 - _t307*_t309;
  const double v4rholapltau2_0 = 0.8e1*M_CBRT3*_hc2[1]*_hc3[1]*_hc4[2]*_t10*_t162*_t168*_t174*_t77*_t82*_t87*params->c + (0.8e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_hc4[2]*_t10*_t162*_t168*_t179*_t180*_t185*_t87*params->c + (0.8e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_hc4[2]*_t10*_t162*_t168*_t179*_t180*_t185*_t87*params->c - 0.8e1 / 0.3e1*_t193*_t311 - _t305*_t310 - _t308*_t311 - _t309*_t311;
  const double v4rhotau3_0 = _t56*(0.8e1*M_CBRT3*_hc2[1]*_hc3[1]*_t10*_t168*_t174*_t2*_t312*_t313*_t77*_t82*params->c + (0.8e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc3[2]*_t10*_t168*_t179*_t180*_t185*_t2*_t312*_t313*params->c + (0.8e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc3[1]*_t10*_t168*_t179*_t180*_t185*_t2*_t312*_t313*params->c - 0.8e1*_t175*_t250*_t314 + (0.1e1 / 0.16e2)*_t204*_t24*_t25*_t27*(_t69 * _t69 * _t69) - 0.8e1 / 0.3e1*_t253*_t282*_t314 - 0.8e1 / 0.9e1*_t277*_t314 - 0.12e2*_t314*_t49*_t78);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += v4rho4_0;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += v4rho3sigma_0;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += v4rho3lapl_0;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += v4rho3tau_0;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += v4rho2sigma2_0;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += v4rho2sigmalapl_0;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += v4rho2sigmatau_0;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += v4rho2lapl2_0;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += v4rho2lapltau_0;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += v4rho2tau2_0;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += v4rhosigma3_0;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += v4rhosigma2lapl_0;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += v4rhosigma2tau_0;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += v4rhosigmalapl2_0;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 0] += v4rhosigmalapltau_0;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += v4rhosigmatau2_0;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += v4rholapl3_0;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += v4rholapl2tau_0;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += v4rholapltau2_0;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += v4rhotau3_0;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double la = lapl[0];
  const double lb = lapl[1];
  const double ta = tau[0];
  const double tb = tau[1];

  const double _t1 = xc_powr(gaa, 1, 2);
  const double _t2 = xc_powr(na, -4, 3);
  const double _t3 = _t1*_t2;
  const double _t4 = xc_powr(na, -5, 3);
  const double _t6 = xc_powr(gbb, 1, 2);
  const double _t7 = xc_powr(nb, -4, 3);
  const double _t8 = _t6*_t7;
  const double _t9 = xc_powr(nb, -5, 3);
  const double _t11 = xc_powr(na, 1, 3);
  const double _t12 = M_CBRT2;
  const double _t13 = (0.1e1 / M_CBRTPI);
  const double _t14 = M_CBRT3*_t12*_t13;
  const double _t15 = _t14*params->c;
  const double _t16 = (0.3e1 / 0.4e1)*_t15;
  const double _t17 = gaa*params->alpha;
  const double _t18 = xc_powr(na, 8, 3);
  const double _t19 = xc_powr(XC_EPSILON, 2, 3);
  const double _t20 = 0.8e1*_t19;
  const double _t21 = (0.1e1 / _t18);
  const double _t22 = (0.1e1 / 0.8e1)*_t21;
  const double _t23 = _t22*(-_t17 - _t18*_t20 + 0.8e1*na*ta) > 0;
  const double _t24 = my_piecewise3(_t23, -_t17*_t22 + _t4*ta, _t19);
  const double _t25 = xc_powr(_t24, 1, 2);
  const double _t26 = xc_powr(0.30e2, 1, 2);
  const double _t27 = (0.1e1 / M_PI);
  const double _t28 = 0.3e1*params->c;
  const double _t29 = _t28 - 0.2e1;
  const double _t30 = _t26*_t27*_t29;
  const double _t31 = (0.1e1 / 0.6e1)*_t30;
  const double _t33 = xc_powr(nb, 1, 3);
  const double _t34 = gbb*params->alpha;
  const double _t35 = xc_powr(nb, 8, 3);
  const double _t36 = (0.1e1 / _t35);
  const double _t37 = (0.1e1 / 0.8e1)*_t36;
  const double _t38 = _t37*(-_t20*_t35 - _t34 + 0.8e1*nb*tb) > 0;
  const double _t39 = my_piecewise3(_t38, -_t34*_t37 + _t9*tb, _t19);
  const double _t40 = xc_powr(_t39, 1, 2);
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(br89_Q_k, _KMAX)(p, _t3, _t4*la, _t4*ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_cQ_k, _KMAX)(p, _hc0[0], _hc1);
  const double _t5 = xc_mgga_x_br89_get_x(_hc1[0]);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_v_k, _KMAX)(p, _t5, _hc2);
  double _hc3[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(br89_Q_k, _KMAX)(p, _t8, _t9*lb, _t9*tb, _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_cQ_k, _KMAX)(p, _hc3[0], _hc4);
  const double _t10 = xc_mgga_x_br89_get_x(_hc4[0]);
  const double _t32 = _hc2[0]*_t16 + _t25*_t31;
  double _hc5[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_v_k, _KMAX)(p, _t10, _hc5);
  const double _t41 = _hc5[0]*_t16 + _t31*_t40;
  const double vrho_0 = _t11*_t32;
  const double vrho_1 = _t33*_t41;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += vrho_0;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += vrho_1;
#if _KMAX >= 2
  const double _t42 = xc_powr(na, -2, 3);
  const double _t43 = (0.1e1 / 0.3e1)*_t42;
  const double _t44 = (0.5e1 / 0.3e1)*_t21;
  const double _t45 = _t44*ta;
  const double _t48 = xc_powr(na, -7, 3);
  const double _t49 = (0.4e1 / 0.3e1)*_t48;
  const double _t53 = (M_CBRTPI * M_CBRTPI);
  const double _t54 = _t15*_t53;
  const double _t59 = xc_powr(na, -11, 3);
  const double _t60 = (0.1e1 / 0.3e1)*_t59;
  const double _t61 = my_piecewise3(_t23, _t17*_t60 - _t45, 0);
  const double _t62 = (0.1e1 / _t25);
  const double _t64 = xc_powr(nb, -2, 3);
  const double _t65 = (0.1e1 / 0.3e1)*_t64;
  const double _t66 = (0.5e1 / 0.3e1)*_t36;
  const double _t67 = _t66*tb;
  const double _t70 = xc_powr(nb, -7, 3);
  const double _t71 = (0.4e1 / 0.3e1)*_t70;
  const double _t79 = xc_powr(nb, -11, 3);
  const double _t80 = (0.1e1 / 0.3e1)*_t79;
  const double _t81 = my_piecewise3(_t38, _t34*_t80 - _t67, 0);
  const double _t82 = (0.1e1 / _t40);
  const double _t84 = (0.1e1 / _t1);
  const double _t87 = my_piecewise3(_t23, -_t22*params->alpha, 0);
  const double _t89 = (0.1e1 / _t6);
  const double _t92 = my_piecewise3(_t38, -_t37*params->alpha, 0);
  const double _t97 = my_piecewise3(_t23, _t4, 0);
  const double _t100 = my_piecewise3(_t38, _t9, 0);
  const double _t52 = (0.1e1 / ((_hc1[0]) * (_hc1[0])));
  const double _t74 = (0.1e1 / ((_hc4[0]) * (_hc4[0])));
  double _hc6[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_aux_dfdx_k, _KMAX)(p, _t5, _hc6);
  double _hc7[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(br89_Q_k, _KMAX)(p, 0, 0, 0, _hc7);
  double _hc8[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(br89_Q_k, _KMAX)(p, _t3, 0, 0, _hc8);
  double _hc9[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(br89_aux_dfdx_k, _KMAX)(p, _t10, _hc9);
  double _hc10[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(br89_Q_k, _KMAX)(p, _t8, 0, 0, _hc10);
  const double _t46 = _hc7[2]*la;
  const double _t47 = _hc8[3]*_t1;
  const double _t50 = -_hc7[1]*_t45 - _t44*_t46 - _t47*_t49;
  const double _t51 = (0.1e1 / 0.2e1)*_t50;
  const double _t55 = (0.1e1 / (_hc6[0]));
  const double _t56 = _hc2[1]*_t55;
  const double _t57 = _t54*_t56;
  const double _t58 = _hc1[1]*_t52*_t57;
  const double _t63 = (0.1e1 / 0.12e2)*_t26*_t27*_t29*_t61*_t62 - _t51*_t58;
  const double _t68 = _hc7[2]*lb;
  const double _t69 = _hc10[3]*_t6;
  const double _t72 = -_hc7[1]*_t67 - _t66*_t68 - _t69*_t71;
  const double _t73 = (0.1e1 / 0.2e1)*_t72;
  const double _t75 = (0.1e1 / (_hc9[0]));
  const double _t76 = _hc5[1]*_t75;
  const double _t77 = _t54*_t76;
  const double _t78 = _hc4[1]*_t74*_t77;
  const double _t83 = (0.1e1 / 0.12e2)*_t26*_t27*_t29*_t81*_t82 - _t73*_t78;
  const double _t85 = _hc8[3]*_t84;
  const double _t86 = _t2*_t58;
  const double _t88 = (0.1e1 / 0.12e2)*_t26*_t27*_t29*_t62*_t87 - 0.1e1 / 0.4e1*_t85*_t86;
  const double _t90 = _hc10[3]*_t89;
  const double _t91 = _t7*_t78;
  const double _t93 = (0.1e1 / 0.12e2)*_t26*_t27*_t29*_t82*_t92 - 0.1e1 / 0.4e1*_t90*_t91;
  const double _t94 = (0.1e1 / 0.2e1)*_t58;
  const double _t95 = (0.1e1 / 0.2e1)*_t78;
  const double _t96 = _hc7[1]*_t4;
  const double _t98 = (0.1e1 / 0.12e2)*_t26*_t27*_t29*_t62*_t97 - _t94*_t96;
  const double _t99 = _hc7[1]*_t9;
  const double _t101 = (0.1e1 / 0.12e2)*_t100*_t26*_t27*_t29*_t82 - _t95*_t99;
  const double v2rho2_0 = _t11*_t63 + _t32*_t43;
  const double v2rho2_2 = _t33*_t83 + _t41*_t65;
  const double v2rhosigma_0 = _t11*_t88;
  const double v2rhosigma_5 = _t33*_t93;
  const double v2rholapl_0 = -_hc7[2]*_t2*_t94;
  const double v2rholapl_3 = -_hc7[2]*_t7*_t95;
  const double v2rhotau_0 = _t11*_t98;
  const double v2rhotau_3 = _t101*_t33;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += v2rho2_0;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += v2rho2_2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += v2rhosigma_0;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += v2rhosigma_5;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 0] += v2rholapl_0;
  if(out->v2rholapl != NULL) out->v2rholapl[ip*p->dim.v2rholapl + 3] += v2rholapl_3;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += v2rhotau_0;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += v2rhotau_3;
#endif
#if _KMAX >= 3
  const double _t102 = (0.2e1 / 0.9e1)*_t4;
  const double _t107 = (M_PI * M_CBRTPI);
  const double _t110 = _t107*_t15;
  const double _t111 = (0.1e1 / 0.3e1)*_t110;
  const double _t115 = (0.40e2 / 0.9e1)*_t59;
  const double _t117 = xc_powr(na, -14, 3);
  const double _t118 = _t117*gaa;
  const double _t119 = xc_powr(na, -10, 3);
  const double _t122 = my_piecewise3(_t23, -0.11e2 / 0.9e1*_t117*_t17 + (0.40e2 / 0.9e1)*_t59*ta, 0);
  const double _t123 = (_t61 * _t61);
  const double _t124 = xc_powr(_t24, -3, 2);
  const double _t125 = (0.1e1 / 0.24e2)*_t30;
  const double _t126 = _t124*_t125;
  const double _t128 = (0.2e1 / 0.9e1)*_t9;
  const double _t138 = (0.40e2 / 0.9e1)*_t79;
  const double _t139 = xc_powr(nb, -14, 3);
  const double _t140 = _t139*gbb;
  const double _t141 = xc_powr(nb, -10, 3);
  const double _t144 = my_piecewise3(_t38, -0.11e2 / 0.9e1*_t139*_t34 + (0.40e2 / 0.9e1)*_t79*tb, 0);
  const double _t145 = (_t81 * _t81);
  const double _t146 = xc_powr(_t39, -3, 2);
  const double _t147 = _t125*_t146;
  const double _t157 = (0.1e1 / 0.3e1)*params->alpha;
  const double _t158 = my_piecewise3(_t23, _t157*_t59, 0);
  const double _t159 = _t126*_t61;
  const double _t175 = my_piecewise3(_t38, _t157*_t79, 0);
  const double _t176 = (0.1e1 / 0.12e2)*_t30;
  const double _t177 = _t176*_t82;
  const double _t178 = _t147*_t81;
  const double _t181 = (0.5e1 / 0.6e1)*_t21;
  const double _t193 = (0.5e1 / 0.6e1)*_t36;
  const double _t202 = my_piecewise3(_t23, -_t44, 0);
  const double _t203 = _t176*_t62;
  const double _t206 = my_piecewise3(_t38, -_t66, 0);
  const double _t208 = (0.1e1 / gaa);
  const double _t210 = xc_powr(gaa, -3, 2);
  const double _t214 = (0.1e1 / 0.12e2)*_t110;
  const double _t216 = (_t87 * _t87);
  const double _t218 = xc_powr(gbb, -3, 2);
  const double _t221 = (0.1e1 / gbb);
  const double _t228 = (_t92 * _t92);
  const double _t231 = (0.1e1 / (na * na * na));
  const double _t239 = (0.1e1 / (nb * nb * nb));
  const double _t247 = _t126*_t87;
  const double _t250 = _t147*_t92;
  const double _t260 = (_t97 * _t97);
  const double _t263 = (_t100 * _t100);
  const double _t104 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t105 = ((_hc1[1]) * (_hc1[1]));
  const double _t108 = (0.1e1 / ((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0])));
  const double _t112 = _t108*_t111;
  const double _t130 = (0.1e1 / ((_hc4[0]) * (_hc4[0]) * (_hc4[0])));
  const double _t131 = ((_hc4[1]) * (_hc4[1]));
  const double _t133 = (0.1e1 / ((_hc4[0]) * (_hc4[0]) * (_hc4[0]) * (_hc4[0])));
  const double _t135 = _t111*_t133;
  const double _t103 = (0.2e1 / 0.3e1)*_t63;
  const double _t106 = (_t50 * _t50);
  const double _t109 = (0.1e1 / ((_hc6[0]) * (_hc6[0])));
  const double _t113 = (0.1e1 / ((_hc6[0]) * (_hc6[0]) * (_hc6[0])));
  const double _t114 = _hc2[1]*_hc6[1]*_t113;
  const double _t116 = (0.16e2 / 0.9e1)*_hc7[9];
  const double _t120 = _t119*_t47;
  const double _t121 = _hc7[1]*_t115*ta + _t115*_t46 + _t116*_t118 + (0.28e2 / 0.9e1)*_t120;
  const double _t127 = M_CBRT3*_hc2[1]*_t104*_t105*_t106*_t12*_t13*_t53*_t55*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_t105*_t106*_t107*_t108*_t109*_t12*_t13*params->c - _t105*_t106*_t112*_t114 - _t121*_t94 + (0.1e1 / 0.12e2)*_t122*_t26*_t27*_t29*_t62 - _t123*_t126;
  const double _t129 = (0.2e1 / 0.3e1)*_t83;
  const double _t132 = (_t72 * _t72);
  const double _t134 = (0.1e1 / ((_hc9[0]) * (_hc9[0])));
  const double _t136 = (0.1e1 / ((_hc9[0]) * (_hc9[0]) * (_hc9[0])));
  const double _t137 = _hc5[1]*_hc9[1]*_t136;
  const double _t142 = _t141*_t69;
  const double _t143 = _hc7[1]*_t138*tb + _t116*_t140 + _t138*_t68 + (0.28e2 / 0.9e1)*_t142;
  const double _t148 = M_CBRT3*_hc5[1]*_t12*_t13*_t130*_t131*_t132*_t53*_t75*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc5[2]*_t107*_t12*_t13*_t131*_t132*_t133*_t134*params->c - _t131*_t132*_t135*_t137 - _t143*_t95 + (0.1e1 / 0.12e2)*_t144*_t26*_t27*_t29*_t82 - _t145*_t147;
  const double _t149 = (0.2e1 / 0.3e1)*_hc7[9];
  const double _t150 = -_t149*_t59 - 0.2e1 / 0.3e1*_t48*_t85;
  const double _t151 = _t2*_t85;
  const double _t152 = _t105*_t114;
  const double _t153 = _t108*_t152;
  const double _t154 = _t110*_t153;
  const double _t155 = (0.1e1 / 0.6e1)*_t154;
  const double _t156 = _t151*_t155;
  const double _t160 = (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_hc8[3]*_t104*_t105*_t12*_t13*_t2*_t50*_t53*_t55*_t84*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_hc8[3]*_t105*_t107*_t108*_t109*_t12*_t13*_t2*_t50*_t84*params->c - _t150*_t94 - _t156*_t50 + (0.1e1 / 0.12e2)*_t158*_t26*_t27*_t29*_t62 - _t159*_t87;
  const double _t161 = -_t149*_t79 - 0.2e1 / 0.3e1*_t70*_t90;
  const double _t162 = _t130*_t131*_t77;
  const double _t163 = _t7*_t90;
  const double _t164 = _hc5[2]*_t134;
  const double _t165 = _t131*_t164;
  const double _t166 = _t133*_t165;
  const double _t167 = _t110*_t166;
  const double _t168 = (0.1e1 / 0.6e1)*_t167;
  const double _t169 = _t163*_t168;
  const double _t170 = _t131*_t137;
  const double _t171 = _t133*_t170;
  const double _t172 = _t110*_t171;
  const double _t173 = (0.1e1 / 0.6e1)*_t172;
  const double _t174 = _t163*_t173;
  const double _t179 = -_t161*_t95 + _t162*_t163*_t73 + _t169*_t72 - _t174*_t72 + _t175*_t177 - _t178*_t92;
  const double _t180 = _hc7[2]*_t58;
  const double _t182 = _t104*_t105*_t57;
  const double _t183 = _t182*_t50;
  const double _t184 = _hc7[2]*_t4;
  const double _t185 = _hc2[2]*_t109;
  const double _t186 = _t105*_t185;
  const double _t187 = _t112*_t186;
  const double _t188 = _t187*_t50;
  const double _t189 = _t112*_t152;
  const double _t190 = _t189*_t50;
  const double _t191 = _t180*_t181 + _t183*_t184 + _t184*_t188 - _t184*_t190;
  const double _t192 = _hc7[2]*_t78;
  const double _t194 = _t162*_t72;
  const double _t195 = _hc7[2]*_t9;
  const double _t196 = _t135*_t165;
  const double _t197 = _t196*_t72;
  const double _t198 = _t135*_t170;
  const double _t199 = _t198*_t72;
  const double _t200 = _t192*_t193 + _t194*_t195 + _t195*_t197 - _t195*_t199;
  const double _t201 = _hc7[1]*_t58;
  const double _t204 = -_t159*_t97 + _t181*_t201 + _t183*_t96 + _t188*_t96 - _t190*_t96 + _t202*_t203;
  const double _t205 = _hc7[1]*_t78;
  const double _t207 = -_t100*_t178 + _t177*_t206 + _t193*_t205 + _t194*_t99 + _t197*_t99 - _t199*_t99;
  const double _t209 = _hc7[9]*_t208;
  const double _t211 = ((_hc8[3]) * (_hc8[3]));
  const double _t212 = _t208*_t211;
  const double _t213 = _t21*_t212;
  const double _t215 = _t153*_t214;
  const double _t217 = (0.1e1 / 0.8e1)*M_CBRT3*_hc1[1]*_hc2[1]*_hc8[3]*_t12*_t13*_t2*_t210*_t52*_t53*_t55*params->c + (0.1e1 / 0.4e1)*M_CBRT3*_hc2[1]*_t104*_t105*_t12*_t13*_t208*_t21*_t211*_t53*_t55*params->c + (0.1e1 / 0.12e2)*M_CBRT3*_hc2[2]*_t105*_t107*_t108*_t109*_t12*_t13*_t208*_t21*_t211*params->c - _t126*_t216 - _t209*_t22*_t58 - _t213*_t215;
  const double _t219 = _hc10[3]*_t218;
  const double _t220 = (0.1e1 / 0.8e1)*_t219;
  const double _t222 = _hc7[9]*_t221;
  const double _t223 = ((_hc10[3]) * (_hc10[3]));
  const double _t224 = _t221*_t223;
  const double _t225 = _t224*_t36;
  const double _t226 = _t166*_t214;
  const double _t227 = _t171*_t214;
  const double _t229 = -_t147*_t228 + (0.1e1 / 0.4e1)*_t162*_t224*_t36 + _t220*_t91 - _t222*_t37*_t78 + _t225*_t226 - _t225*_t227;
  const double _t230 = (0.1e1 / 0.2e1)*_hc7[2];
  const double _t232 = _t231*_t85;
  const double _t233 = _t182*_t232;
  const double _t234 = _t108*_t186;
  const double _t235 = _t110*_t234;
  const double _t236 = (0.1e1 / 0.6e1)*_t232*_t235;
  const double _t237 = _hc7[2]*_t232;
  const double _t238 = _hc7[2]*_t236 - _t155*_t237 + _t230*_t233;
  const double _t240 = _t239*_t90;
  const double _t241 = _t162*_t240;
  const double _t242 = _t168*_t240;
  const double _t243 = _hc7[2]*_t240;
  const double _t244 = _hc7[2]*_t242 - _t173*_t243 + _t230*_t241;
  const double _t245 = (0.1e1 / 0.2e1)*_hc7[1];
  const double _t246 = _hc7[1]*_t232;
  const double _t248 = _hc7[1]*_t236 - _t155*_t246 + _t233*_t245 - _t247*_t97;
  const double _t249 = _hc7[1]*_t240;
  const double _t251 = _hc7[1]*_t242 - _t100*_t250 - _t173*_t249 + _t241*_t245;
  const double _t252 = ((_hc7[2]) * (_hc7[2]));
  const double _t253 = _t231*_t252;
  const double _t254 = _t239*_t252;
  const double _t255 = _hc7[1]*_hc7[2];
  const double _t256 = _t231*_t255;
  const double _t257 = _t239*_t255;
  const double _t258 = ((_hc7[1]) * (_hc7[1]));
  const double _t259 = _t119*_t258;
  const double _t261 = -_t126*_t260 + _t182*_t259 + _t187*_t259 - _t189*_t259;
  const double _t262 = _t141*_t258;
  const double _t264 = -_t147*_t263 + _t162*_t262 + _t196*_t262 - _t198*_t262;
  const double v3rho3_0 = -_t102*_t32 + _t103*_t42 + _t11*_t127;
  const double v3rho3_3 = -_t128*_t41 + _t129*_t64 + _t148*_t33;
  const double v3rho2sigma_0 = _t11*_t160 + _t43*_t88;
  const double v3rho2sigma_8 = _t179*_t33 + _t65*_t93;
  const double v3rho2lapl_0 = _t11*_t191 - 0.1e1 / 0.6e1*_t180*_t48;
  const double v3rho2lapl_5 = -0.1e1 / 0.6e1*_t192*_t70 + _t200*_t33;
  const double v3rho2tau_0 = _t11*_t204 + _t43*_t98;
  const double v3rho2tau_5 = _t101*_t65 + _t207*_t33;
  const double v3rhosigma2_0 = _t11*_t217;
  const double v3rhosigma2_11 = _t229*_t33;
  const double v3rhosigmalapl_0 = _t11*_t238;
  const double v3rhosigmalapl_11 = _t244*_t33;
  const double v3rhosigmatau_0 = _t11*_t248;
  const double v3rhosigmatau_11 = _t251*_t33;
  const double v3rholapl2_0 = _t182*_t253 + _t187*_t253 - _t189*_t253;
  const double v3rholapl2_5 = _t162*_t254 + _t196*_t254 - _t198*_t254;
  const double v3rholapltau_0 = _t182*_t256 + _t187*_t256 - _t189*_t256;
  const double v3rholapltau_7 = _t162*_t257 + _t196*_t257 - _t198*_t257;
  const double v3rhotau2_0 = _t11*_t261;
  const double v3rhotau2_5 = _t264*_t33;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += v3rho3_0;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += v3rho3_3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += v3rho2sigma_0;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += v3rho2sigma_8;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 0] += v3rho2lapl_0;
  if(out->v3rho2lapl != NULL) out->v3rho2lapl[ip*p->dim.v3rho2lapl + 5] += v3rho2lapl_5;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += v3rho2tau_0;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += v3rho2tau_5;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += v3rhosigma2_0;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += v3rhosigma2_11;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 0] += v3rhosigmalapl_0;
  if(out->v3rhosigmalapl != NULL) out->v3rhosigmalapl[ip*p->dim.v3rhosigmalapl + 11] += v3rhosigmalapl_11;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += v3rhosigmatau_0;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += v3rhosigmatau_11;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 0] += v3rholapl2_0;
  if(out->v3rholapl2 != NULL) out->v3rholapl2[ip*p->dim.v3rholapl2 + 5] += v3rholapl2_5;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 0] += v3rholapltau_0;
  if(out->v3rholapltau != NULL) out->v3rholapltau[ip*p->dim.v3rholapltau + 7] += v3rholapltau_7;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += v3rhotau2_0;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += v3rhotau2_5;
#endif
#if _KMAX >= 4
  const double _t267 = _t14*_t28*_t53;
  const double _t272 = 0.2e1*_t110;
  const double _t274 = (M_PI * M_PI);
  const double _t275 = _t15*_t274;
  const double _t276 = (0.2e1 / 0.9e1)*_t275;
  const double _t284 = (0.2e1 / 0.3e1)*_t275;
  const double _t287 = (0.440e3 / 0.27e2)*_t117;
  const double _t288 = _t287*ta;
  const double _t289 = xc_powr(na, -17, 3);
  const double _t291 = xc_powr(na, -13, 3);
  const double _t293 = (0.80e2 / 0.9e1)*_t59;
  const double _t296 = xc_powr(_t24, -5, 2);
  const double _t297 = (0.1e1 / 0.16e2)*_t30;
  const double _t298 = _t296*_t297;
  const double _t299 = (0.1e1 / 0.8e1)*_t30;
  const double _t300 = _t124*_t61;
  const double _t317 = (0.440e3 / 0.27e2)*_t139;
  const double _t318 = _t317*tb;
  const double _t319 = xc_powr(nb, -17, 3);
  const double _t320 = xc_powr(nb, -13, 3);
  const double _t322 = (0.80e2 / 0.9e1)*_t79;
  const double _t324 = xc_powr(_t39, -5, 2);
  const double _t325 = _t297*_t324;
  const double _t326 = _t146*_t81;
  const double _t327 = (0.2e1 / 0.3e1)*_t42;
  const double _t335 = (0.1e1 / 0.9e1)*_t275;
  const double _t337 = (0.1e1 / 0.3e1)*_t275;
  const double _t340 = (0.11e2 / 0.9e1)*params->alpha;
  const double _t341 = _t176*_t300;
  const double _t342 = (0.2e1 / 0.3e1)*_t64;
  const double _t353 = _t176*_t326;
  const double _t354 = (0.20e2 / 0.9e1)*_t59;
  const double _t357 = (0.10e2 / 0.9e1)*_t110;
  const double _t369 = (0.20e2 / 0.9e1)*_t79;
  const double _t384 = _t126*_t97;
  const double _t386 = _t100*_t147;
  const double _t393 = _t16*_t53;
  const double _t396 = (0.1e1 / 0.18e2)*_t275;
  const double _t397 = (0.1e1 / 0.6e1)*_t275;
  const double _t398 = _t124*_t176;
  const double _t405 = _t146*_t176;
  const double _t407 = (0.1e1 / (na * na * na * na));
  const double _t416 = (0.1e1 / (nb * nb * nb * nb));
  const double _t429 = (0.1e1 / 0.9e1)*_t110;
  const double _t460 = (0.1e1 / (gaa * gaa));
  const double _t461 = (0.3e1 / 0.8e1)*_t407;
  const double _t471 = (0.1e1 / 0.36e2)*_t275;
  const double _t475 = (0.1e1 / 0.12e2)*_t275;
  const double _t480 = (0.1e1 / (gbb * gbb));
  const double _t542 = xc_powi(na, -5);
  const double _t545 = xc_powi(nb, -5);
  const double _t265 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t270 = xc_powi((_hc1[0]), -5);
  const double _t277 = xc_powi((_hc1[0]), -6);
  const double _t367 = _t277*_t284;
  const double _t477 = _t265*_t277;
  const double _t301 = ((_hc4[1]) * (_hc4[1]) * (_hc4[1]));
  const double _t305 = xc_powi((_hc4[0]), -5);
  const double _t308 = xc_powi((_hc4[0]), -6);
  const double _t380 = _t284*_t308;
  const double _t266 = _t265*(_t50 * _t50 * _t50);
  const double _t268 = _t108*_t56;
  const double _t269 = _t267*_t268;
  const double _t271 = _t185*_t270;
  const double _t273 = _t266*_t272;
  const double _t278 = _t266*_t277;
  const double _t279 = _t276*_t278;
  const double _t280 = _hc2[3]*_t113;
  const double _t281 = _t114*_t270;
  const double _t282 = (0.1e1 / ((_hc6[0]) * (_hc6[0]) * (_hc6[0]) * (_hc6[0])));
  const double _t283 = _hc2[1]*_hc6[2]*_t282;
  const double _t285 = _t278*_t284;
  const double _t286 = _hc2[2]*_hc6[1]*_t282;
  const double _t290 = (0.112e3 / 0.9e1)*_hc7[9];
  const double _t292 = _hc2[1]*((_hc6[1]) * (_hc6[1]))/xc_powi((_hc6[0]), 5);
  const double _t294 = (0.32e2 / 0.9e1)*_hc7[9];
  const double _t295 = _hc7[1]*_t293*ta + _t118*_t294 + (0.56e2 / 0.9e1)*_t120 + _t293*_t46;
  const double _t302 = _t301*(_t72 * _t72 * _t72);
  const double _t303 = _t133*_t76;
  const double _t304 = _t267*_t303;
  const double _t306 = _t164*_t305;
  const double _t307 = _t272*_t302;
  const double _t309 = _t302*_t308;
  const double _t310 = _t276*_t309;
  const double _t311 = _hc5[3]*_t136;
  const double _t312 = _t137*_t305;
  const double _t313 = (0.1e1 / ((_hc9[0]) * (_hc9[0]) * (_hc9[0]) * (_hc9[0])));
  const double _t314 = _hc5[1]*_hc9[2]*_t313;
  const double _t315 = _t284*_t309;
  const double _t316 = _hc5[2]*_hc9[1]*_t313;
  const double _t321 = _hc5[1]*((_hc9[1]) * (_hc9[1]))/xc_powi((_hc9[0]), 5);
  const double _t323 = _hc7[1]*_t322*tb + _t140*_t294 + (0.56e2 / 0.9e1)*_t142 + _t322*_t68;
  const double _t328 = (0.10e2 / 0.3e1)*_hc7[9];
  const double _t329 = _t110*_t271;
  const double _t330 = _t106*_t265;
  const double _t331 = _t151*_t330;
  const double _t332 = _t108*_t57;
  const double _t333 = (0.3e1 / 0.2e1)*_t332;
  const double _t334 = _t277*_t280;
  const double _t336 = _t277*_t292;
  const double _t338 = (0.4e1 / 0.3e1)*_hc7[9];
  const double _t339 = -_t338*_t59 - _t49*_t85;
  const double _t343 = _t132*_t301;
  const double _t344 = _t163*_t343;
  const double _t345 = _t133*_t77;
  const double _t346 = (0.3e1 / 0.2e1)*_t345;
  const double _t347 = _t110*_t306;
  const double _t348 = _t308*_t311;
  const double _t349 = _t335*_t348;
  const double _t350 = _t337*_t344;
  const double _t351 = _t308*_t321;
  const double _t352 = -_t338*_t79 - _t71*_t90;
  const double _t355 = _hc7[2]*_t21;
  const double _t356 = (0.10e2 / 0.3e1)*_t183;
  const double _t358 = _t234*_t357;
  const double _t359 = _t358*_t50;
  const double _t360 = _t265*_t269;
  const double _t361 = _t106*_t360;
  const double _t362 = _t271*_t272;
  const double _t363 = _t330*_t362;
  const double _t364 = _t102*_t330;
  const double _t365 = _hc7[2]*_t275;
  const double _t366 = _t334*_t365;
  const double _t368 = _t121*_t189;
  const double _t370 = _hc7[2]*_t36;
  const double _t371 = (0.10e2 / 0.3e1)*_t194;
  const double _t372 = _t166*_t357;
  const double _t373 = _t372*_t72;
  const double _t374 = _t301*_t304;
  const double _t375 = _t132*_t374;
  const double _t376 = _t272*_t306;
  const double _t377 = _t343*_t376;
  const double _t378 = _t128*_t343;
  const double _t379 = _t348*_t365;
  const double _t381 = _t143*_t198;
  const double _t382 = _hc7[1]*_t21;
  const double _t383 = _hc7[1]*_t275;
  const double _t385 = _hc7[1]*_t36;
  const double _t387 = _t150*_t189;
  const double _t388 = _hc8[3]*_t210;
  const double _t389 = _t2*_t388;
  const double _t390 = _t214*_t234;
  const double _t391 = _t265*_t50;
  const double _t392 = _t213*_t391;
  const double _t394 = _t268*_t393;
  const double _t395 = _t265*_t329;
  const double _t399 = _t161*_t198;
  const double _t400 = _t219*_t7;
  const double _t401 = _t301*_t72;
  const double _t402 = _t225*_t401;
  const double _t403 = _t303*_t393;
  const double _t404 = _t301*_t347;
  const double _t406 = (0.5e1 / 0.6e1)*_hc7[2];
  const double _t408 = _t407*_t85;
  const double _t409 = _t182*_t408;
  const double _t410 = (0.5e1 / 0.18e2)*_hc7[2];
  const double _t411 = _t235*_t408;
  const double _t412 = _t329*_t391;
  const double _t413 = _t232*_t391;
  const double _t414 = (0.1e1 / 0.9e1)*_t413;
  const double _t415 = (0.1e1 / 0.3e1)*_t365;
  const double _t417 = _t416*_t90;
  const double _t418 = _t162*_t417;
  const double _t419 = _t167*_t417;
  const double _t420 = _t347*_t401;
  const double _t421 = _t240*_t401;
  const double _t422 = (0.1e1 / 0.9e1)*_t421;
  const double _t423 = (0.5e1 / 0.6e1)*_hc7[1];
  const double _t424 = (0.5e1 / 0.18e2)*_hc7[1];
  const double _t425 = _t348*_t383;
  const double _t426 = _t351*_t383;
  const double _t427 = _t252*_t407;
  const double _t428 = (0.1e1 / 0.3e1)*_t182;
  const double _t430 = _t427*_t429;
  const double _t431 = _t252*_t291;
  const double _t432 = (0.10e2 / 0.3e1)*_t182;
  const double _t433 = _t360*_t50;
  const double _t434 = _t119*_t252;
  const double _t435 = _t391*_t434;
  const double _t436 = _t276*_t334;
  const double _t437 = _t252*_t416;
  const double _t438 = (0.1e1 / 0.3e1)*_t162;
  const double _t439 = _t429*_t437;
  const double _t440 = _t252*_t320;
  const double _t441 = (0.10e2 / 0.3e1)*_t162;
  const double _t442 = _t374*_t72;
  const double _t443 = _t141*_t252;
  const double _t444 = _t401*_t443;
  const double _t445 = _t276*_t348;
  const double _t446 = _t255*_t407;
  const double _t447 = _t429*_t446;
  const double _t448 = _t255*_t291;
  const double _t449 = _t119*_t255;
  const double _t450 = _t391*_t449;
  const double _t451 = _t255*_t416;
  const double _t452 = _t429*_t451;
  const double _t453 = _t255*_t320;
  const double _t454 = _t141*_t255;
  const double _t455 = _t401*_t454;
  const double _t456 = _t258*_t291;
  const double _t457 = _t259*_t391;
  const double _t458 = _t258*_t320;
  const double _t459 = _t262*_t401;
  const double _t462 = _t182*_t388;
  const double _t463 = (0.1e1 / 0.8e1)*_hc7[9]*_t388*_t407;
  const double _t464 = _t265*_t332;
  const double _t465 = ((_hc8[3]) * (_hc8[3]) * (_hc8[3]))*_t210;
  const double _t466 = _t211*_t460;
  const double _t467 = _t407*_t465;
  const double _t468 = (0.1e1 / 0.4e1)*_t467;
  const double _t469 = _t22*_t466;
  const double _t470 = _t265*_t334;
  const double _t472 = _t467*_t471;
  const double _t473 = _t110*_t265*_t281;
  const double _t474 = _t265*_t277*_t283;
  const double _t476 = _t467*_t475;
  const double _t478 = _t286*_t477;
  const double _t479 = _t292*_t477;
  const double _t481 = _t223*_t480;
  const double _t482 = _t301*_t345;
  const double _t483 = ((_hc10[3]) * (_hc10[3]) * (_hc10[3]));
  const double _t484 = _t218*_t416*_t483;
  const double _t485 = _t301*_t484;
  const double _t486 = _hc7[2]*_t231;
  const double _t487 = (0.1e1 / 0.4e1)*_t462;
  const double _t488 = _t388*_t390;
  const double _t489 = _t209*_t291;
  const double _t490 = _t215*_t489;
  const double _t491 = _t212*_t291;
  const double _t492 = _t265*_t491;
  const double _t493 = _t394*_t492;
  const double _t494 = _t395*_t491;
  const double _t495 = (0.1e1 / 0.6e1)*_t365;
  const double _t496 = _t219*_t239;
  const double _t497 = _t222*_t320;
  const double _t498 = _t224*_t320;
  const double _t499 = _t301*_t498;
  const double _t500 = _t403*_t499;
  const double _t501 = _t404*_t498;
  const double _t502 = (0.1e1 / 0.18e2)*_t499;
  const double _t503 = (0.1e1 / 0.4e1)*_hc7[1];
  const double _t504 = _hc7[1]*_t231;
  const double _t505 = _t383*_t491;
  const double _t506 = (0.1e1 / 0.18e2)*_t505;
  const double _t507 = (0.1e1 / 0.6e1)*_t505;
  const double _t508 = _t117*_t252;
  const double _t509 = _t395*_t85;
  const double _t510 = _t508*_t85;
  const double _t511 = (0.3e1 / 0.2e1)*_t464;
  const double _t512 = _t335*_t470;
  const double _t513 = _t139*_t252;
  const double _t514 = _t513*_t90;
  const double _t515 = (0.3e1 / 0.2e1)*_t482;
  const double _t516 = _t301*_t514;
  const double _t517 = _t117*_t255;
  const double _t518 = _t517*_t85;
  const double _t519 = _t404*_t90;
  const double _t520 = _t139*_t255;
  const double _t521 = _t520*_t90;
  const double _t522 = _t301*_t521;
  const double _t523 = _t117*_t258;
  const double _t524 = _t523*_t85;
  const double _t525 = _t139*_t258;
  const double _t526 = _t525*_t90;
  const double _t527 = _t301*_t526;
  const double _t528 = ((_hc7[2]) * (_hc7[2]) * (_hc7[2]));
  const double _t529 = _t117*_t528;
  const double _t530 = _t265*_t529;
  const double _t531 = _t139*_t528;
  const double _t532 = _t301*_t531;
  const double _t533 = _hc7[1]*_t508;
  const double _t534 = _t265*_t533;
  const double _t535 = _hc7[1]*_t513;
  const double _t536 = _t301*_t535;
  const double _t537 = _hc7[2]*_t523;
  const double _t538 = _t265*_t537;
  const double _t539 = _hc7[2]*_t525;
  const double _t540 = _t301*_t539;
  const double _t541 = ((_hc7[1]) * (_hc7[1]) * (_hc7[1]));
  const double _t543 = _t541*_t542;
  const double _t544 = _t265*_t543;
  const double _t546 = _t541*_t545;
  const double _t547 = _t301*_t546;
  const double v4rho4_0 = -_t103*_t4 + _t11*(_t121*_t183 + _t121*_t188 - _t121*_t190 - _t122*_t299*_t300 + _t183*_t295 + _t188*_t295 - _t190*_t295 + _t203*my_piecewise3(_t23, (0.154e3 / 0.27e2)*_t17*_t289 - _t288, 0) - _t266*_t269 - _t271*_t273 + _t273*_t281 - _t279*_t280 + _t279*_t283 + _t285*_t286 - _t285*_t292 + _t298*(_t61 * _t61 * _t61) - _t94*(-_hc7[1]*_t288 - _t287*_t46 - _t289*_t290*gaa - 0.280e3 / 0.27e2*_t291*_t47)) + _t127*_t42 + (0.10e2 / 0.27e2)*_t21*_t32;
  const double v4rho4_4 = -_t129*_t9 + _t148*_t64 + _t33*(_t143*_t194 + _t143*_t197 - _t143*_t199 - _t144*_t299*_t326 + _t177*my_piecewise3(_t38, -_t318 + (0.154e3 / 0.27e2)*_t319*_t34, 0) + _t194*_t323 + _t197*_t323 - _t199*_t323 - _t302*_t304 - _t306*_t307 + _t307*_t312 - _t310*_t311 + _t310*_t314 + _t315*_t316 - _t315*_t321 + _t325*(_t81 * _t81 * _t81) - _t95*(-_hc7[1]*_t318 - _t290*_t319*gbb - _t317*_t68 - 0.280e3 / 0.27e2*_t320*_t69)) + (0.10e2 / 0.27e2)*_t36*_t41;
  const double v4rho3sigma_0 = -_t102*_t88 + _t11*(M_CBRT3*_hc2[1]*_hc6[1]*_hc8[3]*_t106*_t107*_t113*_t12*_t13*_t2*_t265*_t270*_t84*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc8[3]*_t106*_t12*_t13*_t2*_t265*_t274*_t277*_t282*_t84*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_hc8[3]*_t104*_t105*_t12*_t121*_t13*_t2*_t53*_t55*_t84*params->c + M_CBRT3*_hc2[1]*_t104*_t105*_t12*_t13*_t339*_t50*_t53*_t55*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc8[3]*_t106*_t12*_t13*_t2*_t265*_t274*_t277*_t282*_t84*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_hc8[3]*_t105*_t107*_t108*_t109*_t12*_t121*_t13*_t2*_t84*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_t105*_t107*_t108*_t109*_t12*_t13*_t339*_t50*params->c - _t121*_t156 - _t122*_t247 + (0.1e1 / 0.16e2)*_t123*_t26*_t27*_t29*_t296*_t87 - _t158*_t341 - _t190*_t339 + (0.1e1 / 0.12e2)*_t26*_t27*_t29*_t62*my_piecewise3(_t23, -_t117*_t340, 0) - _t329*_t331 - _t331*_t333 - _t331*_t334*_t335 - _t331*_t336*_t337 - _t94*(_t117*_t328 + (0.14e2 / 0.9e1)*_t119*_t85)) + _t160*_t327;
  const double v4rho3sigma_11 = -_t128*_t93 + _t179*_t342 + _t33*(_t110*_t312*_t344 + (0.1e1 / 0.2e1)*_t143*_t162*_t163 + _t143*_t169 - _t143*_t174 - _t144*_t250 + _t145*_t325*_t92 - _t175*_t353 + _t177*my_piecewise3(_t38, -_t139*_t340, 0) + _t194*_t352 + _t197*_t352 - _t199*_t352 + _t308*_t314*_t335*_t344 + _t308*_t316*_t350 - _t344*_t346 - _t344*_t347 - _t344*_t349 - _t350*_t351 - _t95*(_t139*_t328 + (0.14e2 / 0.9e1)*_t141*_t90));
  const double v4rho3lapl_0 = _t11*((0.10e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[2]*_t105*_t107*_t108*_t113*_t12*_t13*_t21*_t50*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[2]*_t106*_t107*_t113*_t12*_t13*_t265*_t270*_t4*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[2]*_t106*_t12*_t13*_t265*_t274*_t277*_t282*_t4*params->c + M_CBRT3*_hc2[1]*_hc7[2]*_t104*_t105*_t12*_t121*_t13*_t4*_t53*_t55*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[2]*_t106*_t12*_t13*_t265*_t274*_t277*_t282*_t4*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc7[2]*_t105*_t107*_t108*_t109*_t12*_t121*_t13*_t4*params->c - _t180*_t354 - _t184*_t292*_t330*_t367 - _t184*_t361 - _t184*_t363 - _t184*_t368 - _t355*_t356 - _t355*_t359 - _t364*_t366) + (0.1e1 / 0.9e1)*_t119*_t180 + _t191*_t327;
  const double v4rho3lapl_7 = (0.1e1 / 0.9e1)*_t141*_t192 + _t200*_t342 + _t33*((0.10e2 / 0.9e1)*M_CBRT3*_hc5[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t36*_t72*params->c + 0.2e1*M_CBRT3*_hc5[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t132*_t136*_t301*_t305*_t9*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc7[2]*_hc9[2]*_t12*_t13*_t132*_t274*_t301*_t308*_t313*_t9*params->c + M_CBRT3*_hc5[1]*_hc7[2]*_t12*_t13*_t130*_t131*_t143*_t53*_t75*_t9*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[2]*_hc9[1]*_t12*_t13*_t132*_t274*_t301*_t308*_t313*_t9*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[2]*_t107*_t12*_t13*_t131*_t133*_t134*_t143*_t9*params->c - _t192*_t369 - _t195*_t321*_t343*_t380 - _t195*_t375 - _t195*_t377 - _t195*_t381 - _t370*_t371 - _t370*_t373 - _t378*_t379);
  const double v4rho3tau_0 = -_t102*_t98 + _t11*((0.10e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[1]*_t105*_t107*_t108*_t113*_t12*_t13*_t21*_t50*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[1]*_t106*_t107*_t113*_t12*_t13*_t265*_t270*_t4*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[1]*_t106*_t12*_t13*_t265*_t274*_t277*_t282*_t4*params->c + M_CBRT3*_hc2[1]*_hc7[1]*_t104*_t105*_t12*_t121*_t13*_t4*_t53*_t55*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[1]*_t106*_t12*_t13*_t265*_t274*_t277*_t282*_t4*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc7[1]*_t105*_t107*_t108*_t109*_t12*_t121*_t13*_t4*params->c - _t122*_t384 + (0.1e1 / 0.16e2)*_t123*_t26*_t27*_t29*_t296*_t97 - _t201*_t354 - _t202*_t341 + (0.1e1 / 0.12e2)*_t26*_t27*_t29*_t62*my_piecewise3(_t23, _t115, 0) - _t292*_t330*_t367*_t96 - _t334*_t364*_t383 - _t356*_t382 - _t359*_t382 - _t361*_t96 - _t363*_t96 - _t368*_t96) + _t204*_t327;
  const double v4rho3tau_7 = -_t101*_t128 + _t207*_t342 + _t33*((0.10e2 / 0.9e1)*M_CBRT3*_hc5[1]*_hc7[1]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t36*_t72*params->c + 0.2e1*M_CBRT3*_hc5[1]*_hc7[1]*_hc9[1]*_t107*_t12*_t13*_t132*_t136*_t301*_t305*_t9*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc7[1]*_hc9[2]*_t12*_t13*_t132*_t274*_t301*_t308*_t313*_t9*params->c + M_CBRT3*_hc5[1]*_hc7[1]*_t12*_t13*_t130*_t131*_t143*_t53*_t75*_t9*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[1]*_hc9[1]*_t12*_t13*_t132*_t274*_t301*_t308*_t313*_t9*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[1]*_t107*_t12*_t13*_t131*_t133*_t134*_t143*_t9*params->c + (0.1e1 / 0.16e2)*_t100*_t145*_t26*_t27*_t29*_t324 - _t144*_t386 - _t205*_t369 - _t206*_t353 + (0.1e1 / 0.12e2)*_t26*_t27*_t29*_t82*my_piecewise3(_t38, _t138, 0) - _t321*_t343*_t380*_t99 - _t348*_t378*_t383 - _t371*_t385 - _t373*_t385 - _t375*_t99 - _t377*_t99 - _t381*_t99);
  const double v4rho2sigma2_0 = _t11*((0.1e1 / 0.12e2)*M_CBRT3*_hc2[1]*_hc6[1]*_hc8[3]*_t105*_t107*_t108*_t113*_t12*_t13*_t2*_t210*_t50*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_hc6[1]*_t107*_t113*_t12*_t13*_t208*_t21*_t211*_t265*_t270*_t50*params->c + (0.1e1 / 0.18e2)*M_CBRT3*_hc2[1]*_hc6[2]*_t12*_t13*_t208*_t21*_t211*_t265*_t274*_t277*_t282*_t50*params->c + (0.1e1 / 0.4e1)*M_CBRT3*_hc2[1]*_hc7[9]*_t104*_t105*_t12*_t13*_t208*_t21*_t50*_t53*_t55*params->c + M_CBRT3*_hc2[1]*_hc8[3]*_t104*_t105*_t12*_t13*_t150*_t2*_t53*_t55*_t84*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_hc6[1]*_t12*_t13*_t208*_t21*_t211*_t265*_t274*_t277*_t282*_t50*params->c + (0.1e1 / 0.12e2)*M_CBRT3*_hc2[2]*_hc7[9]*_t105*_t107*_t108*_t109*_t12*_t13*_t208*_t21*_t50*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc8[3]*_t105*_t107*_t108*_t109*_t12*_t13*_t150*_t2*_t84*params->c - _t151*_t387 - _t158*_t398*_t87 - 0.1e1 / 0.4e1*_t183*_t389 - _t209*_t21*_t215*_t50 - _t213*_t395*_t51 + (0.1e1 / 0.16e2)*_t216*_t26*_t27*_t29*_t296*_t61 - _t334*_t392*_t396 - _t336*_t392*_t397 - _t389*_t390*_t50 - _t392*_t394 - _t94*((0.1e1 / 0.3e1)*_hc8[3]*_t210*_t48 - _t209*_t60)) + _t217*_t43;
  const double v4rho2sigma2_17 = _t229*_t65 + _t33*((0.1e1 / 0.12e2)*M_CBRT3*_hc10[3]*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t218*_t7*_t72*params->c + M_CBRT3*_hc10[3]*_hc5[1]*_t12*_t13*_t130*_t131*_t161*_t53*_t7*_t75*_t89*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc10[3]*_hc5[2]*_t107*_t12*_t13*_t131*_t133*_t134*_t161*_t7*_t89*params->c + (0.1e1 / 0.4e1)*M_CBRT3*_hc5[1]*_hc7[9]*_t12*_t13*_t130*_t131*_t221*_t36*_t53*_t72*_t75*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t221*_t223*_t301*_t305*_t36*_t72*params->c + (0.1e1 / 0.18e2)*M_CBRT3*_hc5[1]*_hc9[2]*_t12*_t13*_t221*_t223*_t274*_t301*_t308*_t313*_t36*_t72*params->c + (0.1e1 / 0.12e2)*M_CBRT3*_hc5[2]*_hc7[9]*_t107*_t12*_t13*_t131*_t133*_t134*_t221*_t36*_t72*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc5[2]*_hc9[1]*_t12*_t13*_t221*_t223*_t274*_t301*_t308*_t313*_t36*_t72*params->c - _t163*_t399 - _t175*_t405*_t92 - 0.1e1 / 0.4e1*_t194*_t400 - _t222*_t227*_t36*_t72 - _t225*_t404*_t73 - _t226*_t400*_t72 + (0.1e1 / 0.16e2)*_t228*_t26*_t27*_t29*_t324*_t81 - _t348*_t396*_t402 - _t351*_t397*_t402 - _t402*_t403 - _t95*((0.1e1 / 0.3e1)*_t219*_t70 - _t222*_t80));
  const double v4rho2sigmalapl_0 = _t11*((0.5e1 / 0.18e2)*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[2]*_hc8[3]*_t105*_t107*_t108*_t113*_t12*_t13*_t407*_t84*params->c + M_CBRT3*_hc2[1]*_hc6[1]*_hc7[2]*_hc8[3]*_t107*_t113*_t12*_t13*_t231*_t265*_t270*_t50*_t84*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[2]*_hc8[3]*_t12*_t13*_t231*_t265*_t274*_t277*_t282*_t50*_t84*params->c + M_CBRT3*_hc2[1]*_hc7[2]*_t104*_t105*_t12*_t13*_t150*_t4*_t53*_t55*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[2]*_hc8[3]*_t12*_t13*_t231*_t265*_t274*_t277*_t282*_t50*_t84*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc7[2]*_t105*_t107*_t108*_t109*_t12*_t13*_t150*_t4*params->c - _t184*_t387 - _t237*_t333*_t391 - _t237*_t412 - _t336*_t413*_t415 - _t366*_t414 - _t406*_t409 - _t410*_t411) + _t238*_t43;
  const double v4rho2sigmalapl_17 = _t244*_t65 + _t33*((0.5e1 / 0.18e2)*M_CBRT3*_hc10[3]*_hc5[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t416*_t89*params->c + M_CBRT3*_hc10[3]*_hc5[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t136*_t239*_t301*_t305*_t72*_t89*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc10[3]*_hc5[1]*_hc7[2]*_hc9[2]*_t12*_t13*_t239*_t274*_t301*_t308*_t313*_t72*_t89*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc10[3]*_hc5[2]*_hc7[2]*_hc9[1]*_t12*_t13*_t239*_t274*_t301*_t308*_t313*_t72*_t89*params->c + M_CBRT3*_hc5[1]*_hc7[2]*_t12*_t13*_t130*_t131*_t161*_t53*_t75*_t9*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[2]*_t107*_t12*_t13*_t131*_t133*_t134*_t161*_t9*params->c - _t195*_t399 - _t243*_t346*_t401 - _t243*_t420 - _t351*_t415*_t421 - _t379*_t422 - _t406*_t418 - _t410*_t419);
  const double v4rho2sigmatau_0 = _t11*((0.5e1 / 0.18e2)*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[1]*_hc8[3]*_t105*_t107*_t108*_t113*_t12*_t13*_t407*_t84*params->c + M_CBRT3*_hc2[1]*_hc6[1]*_hc7[1]*_hc8[3]*_t107*_t113*_t12*_t13*_t231*_t265*_t270*_t50*_t84*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[1]*_hc8[3]*_t12*_t13*_t231*_t265*_t274*_t277*_t282*_t50*_t84*params->c + M_CBRT3*_hc2[1]*_hc7[1]*_t104*_t105*_t12*_t13*_t150*_t4*_t53*_t55*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[1]*_hc8[3]*_t12*_t13*_t231*_t265*_t274*_t277*_t282*_t50*_t84*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc7[1]*_t105*_t107*_t108*_t109*_t12*_t13*_t150*_t4*params->c - _t158*_t384 - _t202*_t247 - _t246*_t333*_t391 - _t246*_t412 + (0.1e1 / 0.16e2)*_t26*_t27*_t29*_t296*_t61*_t87*_t97 - _t334*_t383*_t414 - 0.1e1 / 0.3e1*_t336*_t383*_t413 - _t387*_t96 - _t409*_t423 - _t411*_t424) + _t248*_t43;
  const double v4rho2sigmatau_17 = _t251*_t65 + _t33*((0.5e1 / 0.18e2)*M_CBRT3*_hc10[3]*_hc5[1]*_hc7[1]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t416*_t89*params->c + M_CBRT3*_hc10[3]*_hc5[1]*_hc7[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t239*_t301*_t305*_t72*_t89*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc10[3]*_hc5[1]*_hc7[1]*_hc9[2]*_t12*_t13*_t239*_t274*_t301*_t308*_t313*_t72*_t89*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc10[3]*_hc5[2]*_hc7[1]*_hc9[1]*_t12*_t13*_t239*_t274*_t301*_t308*_t313*_t72*_t89*params->c + M_CBRT3*_hc5[1]*_hc7[1]*_t12*_t13*_t130*_t131*_t161*_t53*_t75*_t9*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[1]*_t107*_t12*_t13*_t131*_t133*_t134*_t161*_t9*params->c + (0.1e1 / 0.16e2)*_t100*_t26*_t27*_t29*_t324*_t81*_t92 - _t175*_t386 - _t206*_t250 - _t249*_t346*_t401 - _t249*_t420 - _t399*_t99 - _t418*_t423 - _t419*_t424 - 0.1e1 / 0.3e1*_t421*_t426 - _t422*_t425);
  const double v4rho2lapl2_0 = _t11*((0.10e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[1]*_t105*_t107*_t108*_t113*_t12*_t13*_t252*_t291*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_t107*_t113*_t119*_t12*_t13*_t252*_t265*_t270*_t50*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_t119*_t12*_t13*_t252*_t265*_t274*_t277*_t282*_t50*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_t119*_t12*_t13*_t252*_t265*_t274*_t277*_t282*_t50*params->c - _t292*_t367*_t435 - _t358*_t431 - _t362*_t435 - _t431*_t432 - _t433*_t434 - _t435*_t436) - _t153*_t430 + _t234*_t430 + _t427*_t428;
  const double v4rho2lapl2_8 = _t166*_t439 - _t171*_t439 + _t33*((0.10e2 / 0.9e1)*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t252*_t320*params->c + 0.2e1*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t141*_t252*_t301*_t305*_t72*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc9[2]*_t12*_t13*_t141*_t252*_t274*_t301*_t308*_t313*_t72*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc9[1]*_t12*_t13*_t141*_t252*_t274*_t301*_t308*_t313*_t72*params->c - _t321*_t380*_t444 - _t372*_t440 - _t376*_t444 - _t440*_t441 - _t442*_t443 - _t444*_t445) + _t437*_t438;
  const double v4rho2lapltau_0 = _t11*((0.10e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[1]*_hc7[2]*_t105*_t107*_t108*_t113*_t12*_t13*_t291*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[1]*_hc7[2]*_t107*_t113*_t119*_t12*_t13*_t265*_t270*_t50*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[1]*_hc7[2]*_t119*_t12*_t13*_t265*_t274*_t277*_t282*_t50*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[1]*_hc7[2]*_t119*_t12*_t13*_t265*_t274*_t277*_t282*_t50*params->c - _t292*_t367*_t450 - _t358*_t448 - _t362*_t450 - _t432*_t448 - _t433*_t449 - _t436*_t450) - _t153*_t447 + _t234*_t447 + _t428*_t446;
  const double v4rho2lapltau_11 = _t166*_t452 - _t171*_t452 + _t33*((0.10e2 / 0.9e1)*M_CBRT3*_hc5[1]*_hc7[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t320*params->c + 0.2e1*M_CBRT3*_hc5[1]*_hc7[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t136*_t141*_t301*_t305*_t72*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc7[1]*_hc7[2]*_hc9[2]*_t12*_t13*_t141*_t274*_t301*_t308*_t313*_t72*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[1]*_hc7[2]*_hc9[1]*_t12*_t13*_t141*_t274*_t301*_t308*_t313*_t72*params->c - _t321*_t380*_t455 - _t372*_t453 - _t376*_t455 - _t441*_t453 - _t442*_t454 - _t445*_t455) + _t438*_t451;
  const double v4rho2tau2_0 = _t11*((0.10e2 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[1]*_t105*_t107*_t108*_t113*_t12*_t13*_t258*_t291*params->c + 0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_t107*_t113*_t119*_t12*_t13*_t258*_t265*_t270*_t50*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_t119*_t12*_t13*_t258*_t265*_t274*_t277*_t282*_t50*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_t119*_t12*_t13*_t258*_t265*_t274*_t277*_t282*_t50*params->c - _t202*_t398*_t97 - _t259*_t433 + (0.1e1 / 0.16e2)*_t26*_t260*_t27*_t29*_t296*_t61 - _t292*_t367*_t457 - _t358*_t456 - _t362*_t457 - _t432*_t456 - _t436*_t457) + _t261*_t43;
  const double v4rho2tau2_8 = _t264*_t65 + _t33*((0.10e2 / 0.9e1)*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t258*_t320*params->c + 0.2e1*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t141*_t258*_t301*_t305*_t72*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc9[2]*_t12*_t13*_t141*_t258*_t274*_t301*_t308*_t313*_t72*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc9[1]*_t12*_t13*_t141*_t258*_t274*_t301*_t308*_t313*_t72*params->c - _t100*_t206*_t405 + (0.1e1 / 0.16e2)*_t26*_t263*_t27*_t29*_t324*_t81 - _t262*_t442 - _t321*_t380*_t459 - _t372*_t458 - _t376*_t459 - _t441*_t458 - _t445*_t459);
  const double v4rhosigma3_0 = _t11*((0.3e1 / 0.16e2)*_hc7[9]*_t21*_t460*_t58 + _hc7[9]*_t461*_t462 - 0.3e1 / 0.16e2*_hc8[3]*_t86/xc_powr(gaa, 5, 2) - _t154*_t463 + _t154*_t469 - 0.3e1 / 0.8e1*_t182*_t21*_t466 + _t235*_t463 - _t235*_t469 + _t298*(_t87 * _t87 * _t87) - _t395*_t468 - _t461*_t464*_t465 + _t468*_t473 - _t470*_t472 + _t472*_t474 + _t476*_t478 - _t476*_t479);
  const double v4rhosigma3_19 = _t33*((0.3e1 / 0.8e1)*M_CBRT3*_hc10[3]*_hc5[1]*_hc7[9]*_t12*_t13*_t130*_t131*_t218*_t416*_t53*_t75*params->c + (0.1e1 / 0.8e1)*M_CBRT3*_hc10[3]*_hc5[2]*_hc7[9]*_t107*_t12*_t13*_t131*_t133*_t134*_t218*_t416*params->c + (0.3e1 / 0.16e2)*M_CBRT3*_hc4[1]*_hc5[1]*_hc7[9]*_t12*_t13*_t36*_t480*_t53*_t74*_t75*params->c + (0.1e1 / 0.8e1)*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t223*_t36*_t480*params->c + (0.1e1 / 0.4e1)*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t218*_t301*_t305*_t416*_t483*params->c + (0.1e1 / 0.36e2)*M_CBRT3*_hc5[1]*_hc9[2]*_t12*_t13*_t218*_t274*_t301*_t308*_t313*_t416*_t483*params->c + (0.1e1 / 0.12e2)*M_CBRT3*_hc5[2]*_hc9[1]*_t12*_t13*_t218*_t274*_t301*_t308*_t313*_t416*_t483*params->c - 0.3e1 / 0.16e2*_hc10[3]*_t91/xc_powr(gbb, 5, 2) - _hc7[9]*_t172*_t220*_t416 - 0.3e1 / 0.8e1*_t162*_t36*_t481 - _t167*_t37*_t481 + (0.1e1 / 0.16e2)*_t26*_t27*_t29*_t324*(_t92 * _t92 * _t92) - 0.1e1 / 0.4e1*_t347*_t485 - _t348*_t471*_t485 - _t351*_t475*_t485 - 0.3e1 / 0.8e1*_t482*_t484);
  const double v4rhosigma2lapl_0 = _t11*((0.1e1 / 0.12e2)*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[2]*_hc8[3]*_t105*_t107*_t108*_t113*_t12*_t13*_t210*_t231*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[2]*_t107*_t113*_t12*_t13*_t208*_t211*_t265*_t270*_t291*params->c + (0.1e1 / 0.18e2)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[2]*_t12*_t13*_t208*_t211*_t265*_t274*_t277*_t282*_t291*params->c + (0.1e1 / 0.4e1)*M_CBRT3*_hc2[1]*_hc7[2]*_hc7[9]*_t104*_t105*_t12*_t13*_t208*_t291*_t53*_t55*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[2]*_t12*_t13*_t208*_t211*_t265*_t274*_t277*_t282*_t291*params->c + (0.1e1 / 0.12e2)*M_CBRT3*_hc2[2]*_hc7[2]*_hc7[9]*_t105*_t107*_t108*_t109*_t12*_t13*_t208*_t291*params->c - _hc7[2]*_t490 - _hc7[2]*_t493 - _t230*_t494 - 0.1e1 / 0.18e2*_t366*_t492 - _t479*_t491*_t495 - _t486*_t487 - _t486*_t488);
  const double v4rhosigma2lapl_23 = _t33*((0.1e1 / 0.12e2)*M_CBRT3*_hc10[3]*_hc5[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t218*_t239*params->c + (0.1e1 / 0.4e1)*M_CBRT3*_hc5[1]*_hc7[2]*_hc7[9]*_t12*_t13*_t130*_t131*_t221*_t320*_t53*_t75*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc5[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t136*_t221*_t223*_t301*_t305*_t320*params->c + (0.1e1 / 0.18e2)*M_CBRT3*_hc5[1]*_hc7[2]*_hc9[2]*_t12*_t13*_t221*_t223*_t274*_t301*_t308*_t313*_t320*params->c + (0.1e1 / 0.12e2)*M_CBRT3*_hc5[2]*_hc7[2]*_hc7[9]*_t107*_t12*_t13*_t131*_t133*_t134*_t221*_t320*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc5[2]*_hc7[2]*_hc9[1]*_t12*_t13*_t221*_t223*_t274*_t301*_t308*_t313*_t320*params->c - 0.1e1 / 0.4e1*_hc7[2]*_t162*_t496 - _hc7[2]*_t226*_t496 - _hc7[2]*_t227*_t497 - _hc7[2]*_t500 - _t230*_t501 - _t351*_t495*_t499 - _t379*_t502);
  const double v4rhosigma2tau_0 = _t11*(_hc7[1]*_t390*_t489 - _hc7[1]*_t490 - _hc7[1]*_t493 + _t182*_t489*_t503 + _t215*_t388*_t504 + _t216*_t298*_t97 + _t245*_t473*_t491 - _t245*_t494 - _t470*_t506 + _t474*_t506 + _t478*_t507 - _t479*_t507 - _t487*_t504 - _t488*_t504);
  const double v4rhosigma2tau_23 = _t33*((0.1e1 / 0.12e2)*M_CBRT3*_hc10[3]*_hc5[1]*_hc7[1]*_hc9[1]*_t107*_t12*_t13*_t131*_t133*_t136*_t218*_t239*params->c + (0.1e1 / 0.4e1)*M_CBRT3*_hc5[1]*_hc7[1]*_hc7[9]*_t12*_t13*_t130*_t131*_t221*_t320*_t53*_t75*params->c + (0.1e1 / 0.2e1)*M_CBRT3*_hc5[1]*_hc7[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t221*_t223*_t301*_t305*_t320*params->c + (0.1e1 / 0.18e2)*M_CBRT3*_hc5[1]*_hc7[1]*_hc9[2]*_t12*_t13*_t221*_t223*_t274*_t301*_t308*_t313*_t320*params->c + (0.1e1 / 0.12e2)*M_CBRT3*_hc5[2]*_hc7[1]*_hc7[9]*_t107*_t12*_t13*_t131*_t133*_t134*_t221*_t320*params->c + (0.1e1 / 0.6e1)*M_CBRT3*_hc5[2]*_hc7[1]*_hc9[1]*_t12*_t13*_t221*_t223*_t274*_t301*_t308*_t313*_t320*params->c - _hc7[1]*_t226*_t496 - _hc7[1]*_t227*_t497 - _hc7[1]*_t500 + (0.1e1 / 0.16e2)*_t100*_t228*_t26*_t27*_t29*_t324 - _t162*_t496*_t503 - _t245*_t501 - _t425*_t502 - 0.1e1 / 0.6e1*_t426*_t499);
  const double v4rhosigmalapl2_0 = _t11*(M_CBRT3*_hc2[1]*_hc6[1]*_hc8[3]*_t107*_t113*_t117*_t12*_t13*_t252*_t265*_t270*_t84*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc8[3]*_t117*_t12*_t13*_t252*_t265*_t274*_t277*_t282*_t84*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc8[3]*_t117*_t12*_t13*_t252*_t265*_t274*_t277*_t282*_t84*params->c - _t337*_t479*_t510 - _t508*_t509 - _t510*_t511 - _t510*_t512);
  const double v4rhosigmalapl2_17 = _t33*(M_CBRT3*_hc10[3]*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t139*_t252*_t301*_t305*_t89*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc10[3]*_hc5[1]*_hc9[2]*_t12*_t13*_t139*_t252*_t274*_t301*_t308*_t313*_t89*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc10[3]*_hc5[2]*_hc9[1]*_t12*_t13*_t139*_t252*_t274*_t301*_t308*_t313*_t89*params->c - _t337*_t351*_t516 - _t349*_t516 - _t404*_t514 - _t514*_t515);
  const double v4rhosigmalapltau_0 = _t11*(M_CBRT3*_hc2[1]*_hc6[1]*_hc7[1]*_hc7[2]*_hc8[3]*_t107*_t113*_t117*_t12*_t13*_t265*_t270*_t84*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[1]*_hc7[2]*_hc8[3]*_t117*_t12*_t13*_t265*_t274*_t277*_t282*_t84*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[1]*_hc7[2]*_hc8[3]*_t117*_t12*_t13*_t265*_t274*_t277*_t282*_t84*params->c - _t337*_t479*_t518 - _t509*_t517 - _t511*_t518 - _t512*_t518);
  const double v4rhosigmalapltau_23 = _t33*(M_CBRT3*_hc10[3]*_hc5[1]*_hc7[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t136*_t139*_t301*_t305*_t89*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc10[3]*_hc5[1]*_hc7[1]*_hc7[2]*_hc9[2]*_t12*_t13*_t139*_t274*_t301*_t308*_t313*_t89*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc10[3]*_hc5[2]*_hc7[1]*_hc7[2]*_hc9[1]*_t12*_t13*_t139*_t274*_t301*_t308*_t313*_t89*params->c - _t337*_t351*_t522 - _t349*_t522 - _t515*_t521 - _t519*_t520);
  const double v4rhosigmatau2_0 = _t11*(M_CBRT3*_hc2[1]*_hc6[1]*_hc8[3]*_t107*_t113*_t117*_t12*_t13*_t258*_t265*_t270*_t84*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc8[3]*_t117*_t12*_t13*_t258*_t265*_t274*_t277*_t282*_t84*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc8[3]*_t117*_t12*_t13*_t258*_t265*_t274*_t277*_t282*_t84*params->c + (0.1e1 / 0.16e2)*_t26*_t260*_t27*_t29*_t296*_t87 - _t337*_t479*_t524 - _t509*_t523 - _t511*_t524 - _t512*_t524);
  const double v4rhosigmatau2_17 = _t33*(M_CBRT3*_hc10[3]*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t139*_t258*_t301*_t305*_t89*params->c + (0.1e1 / 0.9e1)*M_CBRT3*_hc10[3]*_hc5[1]*_hc9[2]*_t12*_t13*_t139*_t258*_t274*_t301*_t308*_t313*_t89*params->c + (0.1e1 / 0.3e1)*M_CBRT3*_hc10[3]*_hc5[2]*_hc9[1]*_t12*_t13*_t139*_t258*_t274*_t301*_t308*_t313*_t89*params->c + (0.1e1 / 0.16e2)*_t26*_t263*_t27*_t29*_t324*_t92 - _t337*_t351*_t527 - _t349*_t527 - _t515*_t526 - _t519*_t525);
  const double v4rholapl3_0 = 0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_t107*_t113*_t117*_t12*_t13*_t265*_t270*_t528*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_t117*_t12*_t13*_t265*_t274*_t277*_t282*_t528*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_t117*_t12*_t13*_t265*_t274*_t277*_t282*_t528*params->c - _t277*_t284*_t292*_t530 - _t360*_t529 - _t362*_t530 - _t436*_t530;
  const double v4rholapl3_7 = 0.2e1*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t139*_t301*_t305*_t528*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc9[2]*_t12*_t13*_t139*_t274*_t301*_t308*_t313*_t528*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc9[1]*_t12*_t13*_t139*_t274*_t301*_t308*_t313*_t528*params->c - _t284*_t308*_t321*_t532 - _t374*_t531 - _t376*_t532 - _t445*_t532;
  const double v4rholapl2tau_0 = 0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[1]*_t107*_t113*_t117*_t12*_t13*_t252*_t265*_t270*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[1]*_t117*_t12*_t13*_t252*_t265*_t274*_t277*_t282*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[1]*_t117*_t12*_t13*_t252*_t265*_t274*_t277*_t282*params->c - _t292*_t367*_t534 - _t360*_t533 - _t362*_t534 - _t436*_t534;
  const double v4rholapl2tau_11 = 0.2e1*M_CBRT3*_hc5[1]*_hc7[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t139*_t252*_t301*_t305*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc7[1]*_hc9[2]*_t12*_t13*_t139*_t252*_t274*_t301*_t308*_t313*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[1]*_hc9[1]*_t12*_t13*_t139*_t252*_t274*_t301*_t308*_t313*params->c - _t321*_t380*_t536 - _t374*_t535 - _t376*_t536 - _t445*_t536;
  const double v4rholapltau2_0 = 0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_hc7[2]*_t107*_t113*_t117*_t12*_t13*_t258*_t265*_t270*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_hc7[2]*_t117*_t12*_t13*_t258*_t265*_t274*_t277*_t282*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_hc7[2]*_t117*_t12*_t13*_t258*_t265*_t274*_t277*_t282*params->c - _t292*_t367*_t538 - _t360*_t537 - _t362*_t538 - _t436*_t538;
  const double v4rholapltau2_11 = 0.2e1*M_CBRT3*_hc5[1]*_hc7[2]*_hc9[1]*_t107*_t12*_t13*_t136*_t139*_t258*_t301*_t305*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc7[2]*_hc9[2]*_t12*_t13*_t139*_t258*_t274*_t301*_t308*_t313*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc7[2]*_hc9[1]*_t12*_t13*_t139*_t258*_t274*_t301*_t308*_t313*params->c - _t321*_t380*_t540 - _t374*_t539 - _t376*_t540 - _t445*_t540;
  const double v4rhotau3_0 = _t11*(0.2e1*M_CBRT3*_hc2[1]*_hc6[1]*_t107*_t113*_t12*_t13*_t265*_t270*_t541*_t542*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc2[1]*_hc6[2]*_t12*_t13*_t265*_t274*_t277*_t282*_t541*_t542*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc2[2]*_hc6[1]*_t12*_t13*_t265*_t274*_t277*_t282*_t541*_t542*params->c + (0.1e1 / 0.16e2)*_t26*_t27*_t29*_t296*(_t97 * _t97 * _t97) - _t277*_t284*_t292*_t544 - _t360*_t543 - _t362*_t544 - _t436*_t544);
  const double v4rhotau3_7 = _t33*(0.2e1*M_CBRT3*_hc5[1]*_hc9[1]*_t107*_t12*_t13*_t136*_t301*_t305*_t541*_t545*params->c + (0.2e1 / 0.9e1)*M_CBRT3*_hc5[1]*_hc9[2]*_t12*_t13*_t274*_t301*_t308*_t313*_t541*_t545*params->c + (0.2e1 / 0.3e1)*M_CBRT3*_hc5[2]*_hc9[1]*_t12*_t13*_t274*_t301*_t308*_t313*_t541*_t545*params->c + (0.1e1 / 0.16e2)*(_t100 * _t100 * _t100)*_t26*_t27*_t29*_t324 - _t284*_t308*_t321*_t547 - _t374*_t546 - _t376*_t547 - _t445*_t547);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += v4rho4_0;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += v4rho4_4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += v4rho3sigma_0;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += v4rho3sigma_11;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 0] += v4rho3lapl_0;
  if(out->v4rho3lapl != NULL) out->v4rho3lapl[ip*p->dim.v4rho3lapl + 7] += v4rho3lapl_7;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += v4rho3tau_0;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += v4rho3tau_7;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += v4rho2sigma2_0;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += v4rho2sigma2_17;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 0] += v4rho2sigmalapl_0;
  if(out->v4rho2sigmalapl != NULL) out->v4rho2sigmalapl[ip*p->dim.v4rho2sigmalapl + 17] += v4rho2sigmalapl_17;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += v4rho2sigmatau_0;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += v4rho2sigmatau_17;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 0] += v4rho2lapl2_0;
  if(out->v4rho2lapl2 != NULL) out->v4rho2lapl2[ip*p->dim.v4rho2lapl2 + 8] += v4rho2lapl2_8;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 0] += v4rho2lapltau_0;
  if(out->v4rho2lapltau != NULL) out->v4rho2lapltau[ip*p->dim.v4rho2lapltau + 11] += v4rho2lapltau_11;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += v4rho2tau2_0;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += v4rho2tau2_8;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += v4rhosigma3_0;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += v4rhosigma3_19;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 0] += v4rhosigma2lapl_0;
  if(out->v4rhosigma2lapl != NULL) out->v4rhosigma2lapl[ip*p->dim.v4rhosigma2lapl + 23] += v4rhosigma2lapl_23;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += v4rhosigma2tau_0;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += v4rhosigma2tau_23;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 0] += v4rhosigmalapl2_0;
  if(out->v4rhosigmalapl2 != NULL) out->v4rhosigmalapl2[ip*p->dim.v4rhosigmalapl2 + 17] += v4rhosigmalapl2_17;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 0] += v4rhosigmalapltau_0;
  if(out->v4rhosigmalapltau != NULL) out->v4rhosigmalapltau[ip*p->dim.v4rhosigmalapltau + 23] += v4rhosigmalapltau_23;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += v4rhosigmatau2_0;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += v4rhosigmatau2_17;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 0] += v4rholapl3_0;
  if(out->v4rholapl3 != NULL) out->v4rholapl3[ip*p->dim.v4rholapl3 + 7] += v4rholapl3_7;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 0] += v4rholapl2tau_0;
  if(out->v4rholapl2tau != NULL) out->v4rholapl2tau[ip*p->dim.v4rholapl2tau + 11] += v4rholapl2tau_11;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 0] += v4rholapltau2_0;
  if(out->v4rholapltau2 != NULL) out->v4rholapltau2[ip*p->dim.v4rholapltau2 + 11] += v4rholapltau2_11;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += v4rhotau3_0;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += v4rhotau3_7;
#endif
#endif
}
#endif