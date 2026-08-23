/*
  Generated from python/mgga_exc/mgga_x_r4scan.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_r4scan
*/

#ifndef _MGGA_X_R4SCAN_KERNEL_BODY
#define maple2c_order 2
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_R4SCAN_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_R4SCAN_HELPER_BODIES
#include "mgga_x_r4scan.c"
#undef _MGGA_X_R4SCAN_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_R4SCAN_HELPER_BODIES
#include "mgga_x_r4scan.c"
#undef _MGGA_X_R4SCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_R4SCAN_HELPER_BODIES
#include "mgga_x_r4scan.c"
#undef _MGGA_X_R4SCAN_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_r4scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_r4scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_r4scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_r4scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_r4scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_r4scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_R4SCAN_HELPER_BODIES)

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
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(lda_x_spin_k, _KMAX)(const xc_func_type *p, double rs, double z, double *out) {

  double _hc0[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_4_3_k, _KMAX)(p, z, _hc0);
  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = (0.1e1 / M_CBRTPI);
  const double _t4 = (0.3e1 / 0.16e2)*M_CBRT3*_t1*_t2*_t3;
  const double _t5 = _t4/rs;
#if _KMAX >= 1
  const double _t6 = _t4/(rs * rs);
#endif

  const double f = -_hc0[0]*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = -_hc0[1]*_t5;
  out[1] = df_dz;
  const double df_drs = _hc0[0]*_t6;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = -_hc0[2]*_t5;
  out[3] = d2f_dz2;
  const double d2f_drs_dz = _hc0[1]*_t6;
  out[4] = d2f_drs_dz;
  const double d2f_drs2 = -0.3e1 / 0.8e1*M_CBRT3*_hc0[0]*_t1*_t2*_t3/(rs * rs * rs);
  out[5] = d2f_drs2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(mgga_alpha_reg_k, _KMAX)(const xc_func_type *p, double x, double t, double eta, double *out) {

  const double _t1 = (0.1e1 / 0.8e1)*(x * x);
  const double _t2 = -_t1 + t;
  const double _t3 = _t1*eta;
  const double _t4 = _t3 + (0.3e1 / 0.10e2)*xc_powr(0.6e1, 2, 3)*(M_PI * M_CBRTPI);
  const double _t5 = (0.1e1 / _t4);
#if _KMAX >= 1
  const double _t6 = (0.1e1 / (_t4 * _t4));
  const double _t7 = _t1*_t6;
  const double _t8 = (0.1e1 / 0.4e1)*_t5;
  const double _t9 = (0.1e1 / 0.4e1)*_t6*x;
  const double _t10 = _t2*_t9;
#endif
#if _KMAX >= 2
  const double _t11 = _t2/(_t4 * _t4 * _t4);
  const double _t12 = (x * x * x);
#endif

  const double f = _t2*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_deta = -_t2*_t7;
  out[1] = df_deta;
  const double df_dt = _t5;
  out[2] = df_dt;
  const double df_dx = -_t10*eta - _t8*x;
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_deta2 = (0.1e1 / 0.32e2)*_t11*(x * x * x * x);
  out[4] = d2f_deta2;
  const double d2f_dt_deta = -_t7;
  out[5] = d2f_dt_deta;
  const double d2f_dt2 = 0;
  out[6] = d2f_dt2;
  const double d2f_dx_deta = -_t10 + (0.1e1 / 0.16e2)*_t11*_t12*eta + (0.1e1 / 0.32e2)*_t12*_t6;
  out[7] = d2f_dx_deta;
  const double d2f_dx_dt = -_t9*eta;
  out[8] = d2f_dx_dt;
  const double d2f_dx2 = _t1*_t11*(eta * eta) - 0.1e1 / 0.4e1*_t2*_t6*eta + _t3*_t6 - _t8;
  out[9] = d2f_dx2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_h1x_k, _KMAX)(const xc_func_type *p, double x, double *out) {
  const mgga_x_r4scan_params *params = (const mgga_x_r4scan_params *)(p->params);

  const double _t1 = params->k1 + x;
  const double _t2 = (0.1e1 / _t1);
#if _KMAX >= 1
  const double _t3 = params->k1/(_t1 * _t1);
#endif

  const double f = _t2*params->k1*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t2*params->k1 - _t3*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.2e1*_t3 + 0.2e1*params->k1*x/(_t1 * _t1 * _t1);
  out[2] = d2f_dx2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_gx_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = xc_powr(0.3e1, 1, 6);
  const double _t3 = M_CBRTPI;
  const double _t4 = _t1*_t2*_t3;
  const double _t5 = xc_expm1(-4.9478999999999997*_t4/xc_powr(x, 1, 2));
#if _KMAX >= 1
  const double _t6 = _t5 + 0.1e1;
#endif

  const double f = -_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -2.4739499999999999*_t4*_t6/xc_powr(x, 3, 2);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 3.7109249999999996*_t1*_t2*_t3*_t6/xc_powr(x, 5, 2) - 12.240857204999999*xc_powr(0.6e1, 1, 3)*(M_CBRTPI * M_CBRTPI)*_t6/(x * x * x);
  out[2] = d2f_dx2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_f_alpha_large_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_r4scan_params *params = (const mgga_x_r4scan_params *)(p->params);

  const double _t1 = 0.1e1 - a;
  const double _t2 = params->d*exp(params->c2/_t1);
#if _KMAX >= 1
  const double _t3 = _t2*params->c2;
#endif

  const double f = -_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t3/(_t1 * _t1);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -0.2e1*_t3/(_t1 * _t1 * _t1) - _t2*((params->c2) * (params->c2))/(_t1 * _t1 * _t1 * _t1);
  out[2] = d2f_da2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_f_alpha_neg_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_r4scan_params *params = (const mgga_x_r4scan_params *)(p->params);

  const double _t1 = 0.1e1 - a;
  const double _t2 = params->c1/_t1;
  const double _t3 = exp(-_t2*a);
#if _KMAX >= 1
  const double _t4 = params->c1/(_t1 * _t1);
  const double _t5 = -_t2 - _t4*a;
#endif

  const double f = _t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t3*_t5;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t3*(_t5 * _t5) + _t3*(-0.2e1*_t4 - 0.2e1*a*params->c1/(_t1 * _t1 * _t1));
  out[2] = d2f_da2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r4scan_dFdamp_k, _KMAX)(const xc_func_type *p, double p_, double a, double *out) {
  const mgga_x_r4scan_params *params = (const mgga_x_r4scan_params *)(p->params);

  const double _t1 = (a * a);
  const double _t2 = (a * a * a * a);
  const double _t3 = _t2 + 0.1e1;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = (p_ * p_);
  const double _t6 = (0.1e1 / ((params->dp4) * (params->dp4) * (params->dp4) * (params->dp4)));
  const double _t7 = (0.1e1 / ((params->da4) * (params->da4)));
  const double _t8 = exp(-_t5*_t6 - _t7*((0.1e1 - a) * (0.1e1 - a)));
  const double _t9 = _t4*_t8;
  const double _t10 = _t1*_t9;
  const double _t11 = 0.2e1*_t10;
#if _KMAX >= 1
  const double _t12 = _t8/(_t3 * _t3);
  const double _t13 = _t12*xc_powi(a, 5);
  const double _t14 = 0.2e1*a - 0.2e1;
  const double _t15 = _t14*_t7;
  const double _t16 = 0.4e1*_t9;
  const double _t17 = _t1*_t16;
  const double _t18 = _t17*_t6;
#endif
#if _KMAX >= 2
  const double _t19 = _t17*_t7;
  const double _t20 = 0.8e1*_t9*a;
  const double _t21 = 0.16e2*_t13;
  const double _t22 = _t6*p_;
#endif

  const double f = _t11;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t11*_t15 - 0.8e1*_t13 + 0.4e1*_t4*_t8*a;
  out[1] = df_da;
  const double df_dp_ = -_t18*p_;
  out[2] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t11*(_t14 * _t14)/((params->da4) * (params->da4) * (params->da4) * (params->da4)) - 0.56e2*_t12*_t2 - _t15*_t20 + _t15*_t21 + _t16 - _t19 + 0.64e2*_t8*xc_powi(a, 8)/(_t3 * _t3 * _t3);
  out[3] = d2f_da2;
  const double d2f_dp__da = _t14*_t19*_t22 - _t20*_t22 + _t21*_t22;
  out[4] = d2f_dp__da;
  const double d2f_dp_2 = 0.8e1*_t10*_t5/xc_powi((params->dp4), 8) - _t18;
  out[5] = d2f_dp_2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r4scan_f_k, _KMAX)(const xc_func_type *p, double x, double u, double t, double *out) {
  const mgga_x_r4scan_params *params = (const mgga_x_r4scan_params *)(p->params);

  const double _t1 = 0.27123702538979005*params->eta;
  const double _t2 = (0.1e1 / ((params->dp2) * (params->dp2) * (params->dp2) * (params->dp2)));
  const double _t3 = (0.1e1 / 0.576e3)*_t2;
  const double _t4 = (x * x * x * x);
  const double _t5 = xc_powr(0.6e1, 2, 3);
  const double _t6 = _t5/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t7 = _t4*_t6;
  const double _t8 = (-_t1 - 0.1205497890621289)*exp(-_t3*_t7);
  const double _t9 = _t8 + 0.10e2 / 0.81e2;
  const double _t10 = (x * x);
  const double _t11 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t12 = _t10*_t11;
  const double _t13 = (0.1e1 / 0.24e2)*_t12;
  const double _t27 = (0.5e1 / 0.3e1)*params->eta + 0.20e2 / 0.27e2;
  const double _t28 = 0.040570770199022665 - 0.30235468026081025*params->eta;
  const double _t30 = -0.73e2 / 0.540e3*params->eta + (0.146e3 / 0.2025e4)*(((0.3e1 / 0.4e1)*params->eta + 0.2e1 / 0.3e1) * ((0.3e1 / 0.4e1)*params->eta + 0.2e1 / 0.3e1)) - 0.146e3 / 0.1215e4 + ((0.0029070010613278796 - _t1) * (0.0029070010613278796 - _t1))/params->k1;
#if _KMAX >= 1
  const double _t34 = _t13*_t28;
  const double _t46 = _t8/(M_PI * M_PI * M_PI * M_PI);
  const double _t47 = (0.1e1 / 0.12e2)*_t11;
  const double _t48 = _t47*_t9;
  const double _t49 = -_t3*_t46*xc_powi(x, 5) + _t48*x;
  const double _t51 = 0.013561851269489502*_t11*_t27;
  const double _t53 = _t30*_t6;
#endif
#if _KMAX >= 2
  const double _t67 = _t47*x;
#endif
  double _hc0[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_h1x_k, _KMAX)(p, _t13*_t9, _hc0);
  double _hc1[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(mgga_alpha_reg_k, _KMAX)(p, x, t, params->eta, _hc1);
  const double _t14 = _hc1[0] > 0;
  const double _t15 = _hc1[0] > 2.5;
  const double _t16 = 1.1739999999999999 - _hc0[0];
  const double _t17 = _hc1[0] <= 0;
  const double _t18 = _hc1[0] <= 2.5;
  const double _t19 = my_piecewise3(_t15, 2.5, _hc1[0]);
  const double _t20 = (_t19 * _t19);
  const double _t21 = (_t19 * _t19 * _t19);
  const double _t22 = (_t19 * _t19 * _t19 * _t19);
  const double _t23 = xc_powi(_t19, 5);
  const double _t24 = xc_powi(_t19, 6);
  const double _t26 = 0.1e1 - _hc1[0];
  const double _t29 = _t26*_t28;
  const double _t31 = 0.16274221523387403*_hc1[0] + 0.0067809256347447508*_t12*_t27 + _t13*_t29 - 0.059353125082804131*(_t26 * _t26) + (0.1e1 / 0.576e3)*_t30*_t7 - 0.16274221523387403;
#if _KMAX >= 1
  const double _t33 = 0.11870625016560826*_t26;
  const double _t35 = _hc1[2]*_t33 - _hc1[2]*_t34 + 0.16274221523387403*_hc1[2];
  const double _t37 = my_piecewise3(_t14, 0, _hc1[2]);
  const double _t38 = my_piecewise3(_t15, 0, _hc1[2]);
  const double _t39 = 0.88911099999999998*_t19;
  const double _t40 = 1.9892598031469999*_t20;
  const double _t41 = 4.4399902079849998*_t22;
  const double _t42 = 0.16230090325400001*_t24;
  const double _t43 = my_piecewise3(_t15, _hc1[2], 0);
  const double _t50 = _hc0[1]*_t49;
  const double _t52 = _t29*_t47;
  const double _t54 = _hc1[3]*_t33 - _hc1[3]*_t34 + 0.16274221523387403*_hc1[3] + _t51*x + _t52*x + (0.1e1 / 0.144e3)*_t53*(x * x * x);
  const double _t57 = my_piecewise3(_t14, 0, _hc1[3]);
  const double _t58 = my_piecewise3(_t15, 0, _hc1[3]);
  const double _t59 = my_piecewise3(_t15, _hc1[3], 0);
#endif
#if _KMAX >= 2
  const double _t62 = ((_hc1[2]) * (_hc1[2]));
  const double _t63 = (_t38 * _t38);
  const double _t64 = 3.9785196062939998*_t19;
  const double _t65 = 17.759960831939999*_t21;
  const double _t66 = 0.97380541952400002*_t23;
  const double _t70 = my_piecewise3(_t15, 0, _hc1[8]);
  const double _t71 = _t38*_t58;
  const double _t72 = _hc0[2]*(_t49 * _t49);
  const double _t73 = _hc0[1]*(-0.7e1 / 0.576e3*_t2*_t4*_t46 + _t48 + (0.1e1 / 0.82944e5)*_t5*_t8*xc_powi(x, 8)/((M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI)*xc_powi((params->dp2), 8)));
  const double _t74 = my_piecewise3(_t15, 0, _hc1[9]);
  const double _t75 = (_t58 * _t58);
#endif
  double _hc2[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(r2scan_f_alpha_neg_k, _KMAX)(p, my_piecewise3(_t14, 0, _hc1[0]), _hc2);
  double _hc3[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(rscan_f_alpha_large_k, _KMAX)(p, my_piecewise3(_t15, _hc1[0], 2.5), _hc3);
  double _hc4[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(r4scan_dFdamp_k, _KMAX)(p, _t13, _hc1[0], _hc4);
  double _hc5[(_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_gx_k, _KMAX)(p, x, _hc5);
  const double _t25 = my_piecewise5(_t17, _hc2[0], _t18, -0.023185843322000001*xc_powi(_t19, 7) - 0.66700000000000004*_t19 - 0.44455549999999999*_t20 - 0.66308660104899997*_t21 + 1.45129704449*_t22 - 0.88799804159700002*_t23 + 0.234528941479*_t24 + 0.1e1, _hc3[0]);
  const double _t32 = _hc0[0] + _hc4[0]*_t31 + _t16*_t25;
#if _KMAX >= 1
  const double _t36 = _hc1[2]*_hc4[1];
  const double _t44 = my_piecewise5(_t17, _hc2[1]*_t37, _t18, 5.8051881779599999*_t21*_t38 + 1.4071736488740001*_t23*_t38 - _t38*_t39 - _t38*_t40 - _t38*_t41 - _t38*_t42 - 0.66700000000000004*_t38, _hc3[1]*_t43);
  const double _t45 = _hc4[0]*_t35 + _t16*_t44 + _t31*_t36;
  const double _t55 = _hc4[2]*_t47;
  const double _t56 = _hc1[3]*_hc4[1] + _t55*x;
  const double _t60 = my_piecewise5(_t17, _hc2[1]*_t57, _t18, 5.8051881779599999*_t21*_t58 + 1.4071736488740001*_t23*_t58 - _t39*_t58 - _t40*_t58 - _t41*_t58 - _t42*_t58 - 0.66700000000000004*_t58, _hc3[1]*_t59);
  const double _t61 = _hc4[0]*_t54 + _t16*_t60 - _t25*_t50 + _t31*_t56 + _t50;
#endif
#if _KMAX >= 2
  const double _t68 = _hc1[3]*_hc4[3];
  const double _t69 = _hc4[4]*_t67;
#endif

  const double f = _hc5[0]*_t32;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc5[0]*_t45;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc5[0]*_t61 + _hc5[1]*_t32;
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc5[0]*(-0.11870625016560826*_hc4[0]*_t62 + _hc4[3]*_t31*_t62 + _t16*my_piecewise5(_t17, _hc2[2]*(_t37 * _t37), _t18, 17.415564533880001*_t20*_t63 + 7.0358682443700005*_t22*_t63 - _t63*_t64 - _t63*_t65 - _t63*_t66 - 0.88911099999999998*_t63, _hc3[2]*(_t43 * _t43)) + 0.2e1*_t35*_t36);
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx_dt = _hc5[0]*(_hc4[0]*(-0.11870625016560826*_hc1[2]*_hc1[3] - _hc1[2]*_t28*_t67 + 0.11870625016560826*_hc1[8]*_t26 - _hc1[8]*_t34 + 0.16274221523387403*_hc1[8]) + _t16*my_piecewise5(_t17, _hc2[1]*my_piecewise3(_t14, 0, _hc1[8]) + _hc2[2]*_t37*_t57, _t18, 17.415564533880001*_t20*_t38*_t58 + 5.8051881779599999*_t21*_t70 + 7.0358682443700005*_t22*_t38*_t58 + 1.4071736488740001*_t23*_t70 - _t39*_t70 - _t40*_t70 - _t41*_t70 - _t42*_t70 - _t64*_t71 - _t65*_t71 - _t66*_t71 - 0.66700000000000004*_t70 - 0.88911099999999998*_t71, _hc3[1]*my_piecewise3(_t15, _hc1[8], 0) + _hc3[2]*_t43*_t59) + _t31*(_hc1[2]*_t68 + _hc1[2]*_t69 + _hc1[8]*_hc4[1]) + _t35*_t56 + _t36*_t54 - _t44*_t50) + _hc5[1]*_t45;
  out[7] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[8] = d2f_dx_du;
  const double d2f_dx2 = _hc5[0]*(_hc4[0]*(-0.11870625016560826*((_hc1[3]) * (_hc1[3])) - 0.1e1 / 0.6e1*_hc1[3]*_t11*_t28*x + _hc1[9]*_t33 - _hc1[9]*_t34 + 0.16274221523387403*_hc1[9] + (0.1e1 / 0.48e2)*_t10*_t53 + _t51 + _t52) + _t16*my_piecewise5(_t17, _hc2[1]*my_piecewise3(_t14, 0, _hc1[9]) + _hc2[2]*(_t57 * _t57), _t18, 17.415564533880001*_t20*_t75 + 5.8051881779599999*_t21*_t74 + 7.0358682443700005*_t22*_t75 + 1.4071736488740001*_t23*_t74 - _t39*_t74 - _t40*_t74 - _t41*_t74 - _t42*_t74 - _t64*_t75 - _t65*_t75 - _t66*_t75 - 0.66700000000000004*_t74 - 0.88911099999999998*_t75, _hc3[1]*my_piecewise3(_t15, _hc1[9], 0) + _hc3[2]*(_t59 * _t59)) - _t25*_t72 - _t25*_t73 + _t31*(_hc1[3]*(_t68 + _t69) + _hc1[9]*_hc4[1] + _t55 + _t67*(_hc1[3]*_hc4[4] + _hc4[5]*_t67)) - 0.2e1*_t50*_t60 + 0.2e1*_t54*_t56 + _t72 + _t73) + 0.2e1*_hc5[1]*_t61 + _hc5[2]*_t32;
  out[9] = d2f_dx2;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_r4scan_params *params = (const mgga_x_r4scan_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3)/M_CBRTPI;
  const double _t2 = xc_powr(n_s, -4, 3);
  const double _t3 = xc_powr(sigma_ss, 1, 2);
  const double _t4 = xc_powr(n_s, -5, 3);
  const double _t5 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t8 = (0.1e1 / _t3);
  const double _t14 = xc_powr(n_s, -8, 3);
  const double _t15 = (0.5e1 / 0.3e1)*_t14;
  const double _t17 = (0.4e1 / 0.3e1)*_t3;
  const double _t18 = xc_powr(n_s, -7, 3);
#endif
#if _KMAX >= 2
  const double _t22 = xc_powr(n_s, -10, 3);
  const double _t23 = (0.1e1 / (n_s * n_s * n_s));
  const double _t26 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t28 = xc_powr(n_s, -11, 3);
  const double _t29 = _t15*tau_s;
  const double _t30 = _t17*_t18;
#endif
  double _hc0[(_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(lda_x_spin_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t1/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t5)) XC_CAT(r4scan_f_k, _KMAX)(p, _t2*_t3, 0, _t4*tau_s, _hc1);
  const double _t6 = my_piecewise3(_t5, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t7 = my_piecewise3(_t5, 0, _hc0[0]*_hc1[1]*_t4);
  const double _t9 = _hc1[3]*_t8;
  const double _t10 = (0.1e1 / 0.2e1)*_hc0[0];
  const double _t11 = my_piecewise3(_t5, 0, _t10*_t2*_t9);
  const double _t12 = _hc0[2]*_t1;
  const double _t13 = (0.1e1 / 0.6e1)*_t12;
  const double _t16 = _hc1[1]*_t15;
  const double _t19 = _hc1[3]*_t18;
  const double _t20 = -_t16*tau_s - _t17*_t19;
  const double _t21 = my_piecewise3(_t5, 0, _hc0[0]*_t20 - _hc1[0]*_t13*_t2);
#endif
#if _KMAX >= 2
  const double _t24 = _hc1[7]*_t8;
  const double _t25 = _hc1[4]*tau_s;
  const double _t27 = _hc1[7]*_t17;
#endif

  const double f = my_piecewise3(_t5, 0, _t6*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t5, 0, _t7*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t11*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t21*n_s + _t6);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*_hc1[4]*_t22));
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _t10*_t23*_t24));
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, -0.1e1 / 0.4e1*_hc0[0]*_hc1[3]*_t2/xc_powr(sigma_ss, 3, 2) + (0.1e1 / 0.4e1)*_hc0[0]*_hc1[9]*_t14/sigma_ss));
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t5, 0, _t7 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t16 - 0.5e1 / 0.3e1*_t25/xc_powr(n_s, 13, 3) - _t26*_t27) - _hc1[1]*_t13*_t23));
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t11 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-0.2e1 / 0.3e1*_hc1[9]*_t28 - 0.2e1 / 0.3e1*_t19*_t8 - 0.5e1 / 0.6e1*_t24*_t26*tau_s) - 0.1e1 / 0.12e2*_t12*_t14*_t9));
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, 0.2e1*_t21 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.40e2 / 0.9e1)*_hc1[1]*_t28*tau_s + (0.28e2 / 0.9e1)*_hc1[3]*_t22*_t3 - _t29*(-_t15*_t25 - _t18*_t27) - _t30*(-_hc1[7]*_t29 - _hc1[9]*_t30)) + (0.1e1 / 0.36e2)*xc_powr(0.6e1, 2, 3)*_hc0[5]*_hc1[0]*_t14/(M_CBRTPI * M_CBRTPI) + (0.2e1 / 0.9e1)*_hc1[0]*_t12*_t18 - 0.1e1 / 0.3e1*_t12*_t2*_t20));
  out[14] = d2f_dn_s2;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_r4scan_params *params = (const mgga_x_r4scan_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double ta = tau[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = (0.1e1 / 0.4e1)*gaa;
  const double _t3 = (0.1e1 / 0.2e1)*ta;
  double _hc0[(_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
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
  double _hc1[(_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
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
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;
  const double lb = (lapl != NULL) ? lapl[1] : 0.0;
  const double ta = tau[0];
  const double tb = tau[1];

  double _hc0[(_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, 0, ta, _hc0);
  double _hc1[(_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
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
  double _hc2[(_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, ta, _hc2);
  double _hc3[(_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
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
#endif
}
#endif