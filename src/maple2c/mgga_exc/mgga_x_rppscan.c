/*
  Generated from python/mgga_exc/mgga_x_rppscan.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_rppscan
*/

#ifndef _MGGA_X_RPPSCAN_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_RPPSCAN_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_RPPSCAN_HELPER_BODIES
#include "mgga_x_rppscan.c"
#undef _MGGA_X_RPPSCAN_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_RPPSCAN_HELPER_BODIES
#include "mgga_x_rppscan.c"
#undef _MGGA_X_RPPSCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_RPPSCAN_HELPER_BODIES
#include "mgga_x_rppscan.c"
#undef _MGGA_X_RPPSCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_RPPSCAN_HELPER_BODIES
#include "mgga_x_rppscan.c"
#undef _MGGA_X_RPPSCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_RPPSCAN_HELPER_BODIES
#include "mgga_x_rppscan.c"
#undef _MGGA_X_RPPSCAN_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_rppscan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_RPPSCAN_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(z_thr_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z + 0.1e1 <= p->zeta_threshold;
  const double _t2 = p->zeta_threshold - 0.1e1;
  const double _t3 = 0.1e1 - z <= p->zeta_threshold;
#if _KMAX >= 2
  const double _t4 = my_piecewise5(_t1, 0, _t3, 0, 0);
#endif

  const double f = my_piecewise5(_t1, _t2, _t3, -_t2, z);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise5(_t1, 0, _t3, 0, 0.1e1);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t4;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t4;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t4;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(mgga_alpha_reg_k, _KMAX)(const xc_func_type *p, double x, double t, double eta, double *out) {

  const double _t1 = (x * x);
  const double _t2 = (0.1e1 / 0.8e1)*_t1;
  const double _t3 = -_t2 + t;
  const double _t4 = _t2*eta;
  const double _t5 = _t4 + (0.3e1 / 0.10e2)*xc_powr(0.6e1, 2, 3)*(M_PI * M_CBRTPI);
  const double _t6 = (0.1e1 / _t5);
#if _KMAX >= 1
  const double _t7 = (0.1e1 / (_t5 * _t5));
  const double _t8 = _t2*_t7;
  const double _t9 = (0.1e1 / 0.4e1)*_t6;
  const double _t10 = (0.1e1 / 0.4e1)*_t7;
  const double _t11 = _t10*x;
  const double _t12 = _t11*_t3;
#endif
#if _KMAX >= 2
  const double _t13 = (x * x * x * x);
  const double _t14 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t15 = _t13*_t14;
  const double _t16 = (0.1e1 / 0.32e2)*_t15;
  const double _t17 = (x * x * x);
  const double _t18 = _t14*_t17;
  const double _t19 = _t18*eta;
  const double _t20 = (0.1e1 / 0.16e2)*_t19;
  const double _t21 = _t10*_t3;
  const double _t22 = (eta * eta);
  const double _t23 = _t14*_t22;
  const double _t24 = _t2*_t23;
#endif
#if _KMAX >= 3
  const double _t25 = xc_powi(x, 6);
  const double _t26 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t27 = (0.3e1 / 0.256e3)*_t25*_t26;
  const double _t28 = xc_powi(x, 5);
  const double _t29 = _t26*_t28;
  const double _t30 = _t29*_t3;
  const double _t31 = (0.3e1 / 0.128e3)*eta;
  const double _t32 = _t13*_t26;
  const double _t33 = (0.3e1 / 0.64e2)*_t22*_t32;
  const double _t34 = (eta * eta * eta);
  const double _t35 = (0.3e1 / 0.32e2)*_t34;
  const double _t36 = _t17*_t26;
  const double _t37 = _t35*_t36;
#endif
#if _KMAX >= 4
  const double _t38 = _t3/xc_powi(_t5, 5);
  const double _t39 = xc_powi(x, 7);
  const double _t40 = (0.3e1 / 0.8e1)*_t3;
  const double _t41 = _t3*eta;
  const double _t42 = (0.3e1 / 0.8e1)*_t7;
  const double _t43 = (0.9e1 / 0.16e2)*_t1;
#endif

  const double f = _t3*_t6;
  out[0] = f;
#if _KMAX >= 1
  const double df_deta = -_t3*_t8;
  out[1] = df_deta;
  const double df_dt = _t6;
  out[2] = df_dt;
  const double df_dx = -_t12*eta - _t9*x;
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_deta2 = _t16*_t3;
  out[4] = d2f_deta2;
  const double d2f_dt_deta = -_t8;
  out[5] = d2f_dt_deta;
  const double d2f_dt2 = 0;
  out[6] = d2f_dt2;
  const double d2f_dx_deta = -_t12 + (0.1e1 / 0.32e2)*_t17*_t7 + _t20*_t3;
  out[7] = d2f_dx_deta;
  const double d2f_dx_dt = -_t11*eta;
  out[8] = d2f_dx_dt;
  const double d2f_dx2 = -_t21*eta + _t24*_t3 + _t4*_t7 - _t9;
  out[9] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_deta3 = -_t27*_t3;
  out[10] = d3f_deta3;
  const double d3f_dt_deta2 = _t16;
  out[11] = d3f_dt_deta2;
  const double d3f_dt2_deta = 0;
  out[12] = d3f_dt2_deta;
  const double d3f_dt3 = 0;
  out[13] = d3f_dt3;
  const double d3f_dx_deta2 = (0.1e1 / 0.8e1)*_t14*_t17*_t3 - 0.1e1 / 0.128e3*_t14*_t28 - _t30*_t31;
  out[14] = d3f_dx_deta2;
  const double d3f_dx_dt_deta = -_t11 + _t20;
  out[15] = d3f_dx_dt_deta;
  const double d3f_dx_dt2 = 0;
  out[16] = d3f_dx_dt2;
  const double d3f_dx2_deta = (0.5e1 / 0.16e2)*_t1*_t14*_t3*eta + (0.5e1 / 0.32e2)*_t1*_t7 - _t16*eta - _t21 - _t3*_t33;
  out[17] = d3f_dx2_deta;
  const double d3f_dx2_dt = -_t10*eta + _t24;
  out[18] = d3f_dx2_dt;
  const double d3f_dx3 = (0.3e1 / 0.8e1)*_t14*_t22*_t3*x - 0.3e1 / 0.32e2*_t18*_t22 - _t3*_t37 + (0.3e1 / 0.8e1)*_t7*eta*x;
  out[19] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_deta4 = (0.3e1 / 0.512e3)*_t38*xc_powi(x, 8);
  out[20] = d4f_deta4;
  const double d4f_dt_deta3 = -_t27;
  out[21] = d4f_dt_deta3;
  const double d4f_dt2_deta2 = 0;
  out[22] = d4f_dt2_deta2;
  const double d4f_dt3_deta = 0;
  out[23] = d4f_dt3_deta;
  const double d4f_dt4 = 0;
  out[24] = d4f_dt4;
  const double d4f_dx_deta3 = (0.3e1 / 0.1024e4)*_t26*_t39 - 0.9e1 / 0.128e3*_t30 + (0.3e1 / 0.256e3)*_t38*_t39*eta;
  out[25] = d4f_dx_deta3;
  const double d4f_dx_dt_deta2 = (0.1e1 / 0.8e1)*_t14*_t17 - _t29*_t31;
  out[26] = d4f_dx_dt_deta2;
  const double d4f_dx_dt2_deta = 0;
  out[27] = d4f_dx_dt2_deta;
  const double d4f_dx_dt3 = 0;
  out[28] = d4f_dx_dt3;
  const double d4f_dx2_deta2 = _t1*_t14*_t40 - 0.9e1 / 0.128e3*_t15 + (0.3e1 / 0.128e3)*_t22*_t25*_t38 + _t27*eta - 0.27e2 / 0.128e3*_t32*_t41;
  out[29] = d4f_dx2_deta2;
  const double d4f_dx2_dt_deta = (0.5e1 / 0.16e2)*_t1*_t14*eta - _t10 - _t33;
  out[30] = d4f_dx2_dt_deta;
  const double d4f_dx2_dt2 = 0;
  out[31] = d4f_dx2_dt2;
  const double d4f_dx3_deta = (0.3e1 / 0.4e1)*_t14*_t41*x - 0.9e1 / 0.32e2*_t19 + (0.9e1 / 0.256e3)*_t22*_t29 - 0.27e2 / 0.64e2*_t22*_t3*_t36 + (0.3e1 / 0.64e2)*_t28*_t34*_t38 + _t42*x;
  out[32] = d4f_dx3_deta;
  const double d4f_dx3_dt = (0.3e1 / 0.8e1)*_t14*_t22*x - _t37;
  out[33] = d4f_dx3_dt;
  const double d4f_dx4 = (0.3e1 / 0.32e2)*_t13*_t38*(eta * eta * eta * eta) + _t23*_t40 - _t23*_t43 - _t26*_t3*_t34*_t43 + _t32*_t35 + _t42*eta;
  out[34] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_h1x_k, _KMAX)(const xc_func_type *p, double x, double *out) {
  const mgga_x_rppscan_params *params = (const mgga_x_rppscan_params *)(p->params);

  const double _t1 = params->k1 + x;
  const double _t2 = (0.1e1 / _t1);
#if _KMAX >= 1
  const double _t3 = params->k1/(_t1 * _t1);
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (_t1 * _t1 * _t1));
#endif
#if _KMAX >= 3
  const double _t5 = params->k1/(_t1 * _t1 * _t1 * _t1);
#endif

  const double f = _t2*params->k1*x + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t2*params->k1 - _t3*x;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -0.2e1*_t3 + 0.2e1*_t4*params->k1*x;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = 0.6e1*_t4*params->k1 - 0.6e1*_t5*x;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = -0.24e2*_t5 + 0.24e2*params->k1*x/xc_powi(_t1, 5);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_y_k, _KMAX)(const xc_func_type *p, double x, double a, double *out) {
  const mgga_x_rppscan_params *params = (const mgga_x_rppscan_params *)(p->params);

  const double _t1 = (x * x);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = _t1*_t4;
  const double _t6 = (x * x * x * x);
  const double _t7 = xc_powr(0.6e1, 2, 3);
  const double _t8 = _t7/(M_PI * M_PI * M_CBRTPI * M_CBRTPI);
  const double _t9 = 0.73e2 / 0.648e3 - (0.100e3 / 0.6561e4)/params->k1;
  const double _t10 = (0.27e2 / 0.80e2)*_t9;
  const double _t11 = -_t9*exp(_t10*_t5);
  const double _t12 = _t11*_t8;
  const double _t13 = xc_powr(0.2e1, 5, 6)*M_CBRT3*xc_powr(0.73e2, 1, 2)*_t3;
  const double _t14 = 0.1e1 - a;
  const double _t15 = (_t14 * _t14);
  const double _t16 = xc_powr(0.146e3, 1, 2)*exp(-0.1e1 / 0.2e1*_t15);
  const double _t17 = (0.1e1 / 0.100e3)*_t16;
  const double _t18 = _t14*_t17;
  const double _t19 = (0.7e1 / 0.12960e5)*_t1*_t13 + _t18;
#if _KMAX >= 1
  const double _t20 = (0.1e1 / 0.50e2)*_t16;
  const double _t21 = _t15*_t20 - _t20;
  const double _t22 = (0.5e1 / 0.486e3)*_t4;
  const double _t23 = (x * x * x);
  const double _t24 = xc_powi(x, 5);
  const double _t25 = _t11/(M_PI * M_PI * M_PI * M_PI);
  const double _t26 = _t25*_t9;
  const double _t27 = (0.7e1 / 0.3240e4)*_t13;
  const double _t28 = _t19*_t27;
#endif
#if _KMAX >= 2
  const double _t29 = _t15*_t17 - _t17;
  const double _t30 = _t14*_t20;
  const double _t31 = 0.2e1*a - 0.2e1;
  const double _t32 = (_t14 * _t14 * _t14);
  const double _t33 = _t20*_t31 + _t20*_t32 - _t30;
  const double _t34 = _t27*_t29;
  const double _t35 = _t1*_t8;
  const double _t36 = _t11*xc_powi(x, 6);
  const double _t37 = _t2*(_t9 * _t9)/(M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
#endif
#if _KMAX >= 3
  const double _t38 = _t17*_t31 + _t17*_t32 - _t18;
  const double _t39 = _t15*_t16;
  const double _t40 = (_t14 * _t14 * _t14 * _t14);
  const double _t41 = (0.3e1 / 0.50e2)*_t16 + _t20*_t40 + _t30*_t31 - 0.2e1 / 0.25e2*_t39;
  const double _t42 = _t27*_t38;
  const double _t43 = (0.3577e4 / 0.3499200e7)*_t8;
  const double _t44 = (0.1e1 / 0.24e2)*_t12;
  const double _t45 = _t11*_t37;
  const double _t46 = _t7*(_t9 * _t9 * _t9)/(M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI);
#endif
#if _KMAX >= 4
  const double _t47 = (0.3e1 / 0.100e3)*_t16 + _t17*_t40 + _t18*_t31 - 0.1e1 / 0.25e2*_t39;
  const double _t48 = (0.1e1 / 0.10e2)*_t16;
#endif

  const double f = (0.1e1 / 0.576e3)*_t12*_t6 + (_t19 * _t19) + (0.5e1 / 0.972e3)*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t19*_t21;
  out[1] = df_da;
  const double df_dx = (0.1e1 / 0.144e3)*_t12*_t23 + _t22*x + (0.9e1 / 0.1280e4)*_t24*_t26 + _t28*x;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t19*_t33 + _t21*_t29;
  out[3] = d2f_da2;
  const double d2f_dx_da = _t34*x;
  out[4] = d2f_dx_da;
  const double d2f_dx2 = (0.1e1 / 0.48e2)*_t11*_t35 + _t22 + (0.81e2 / 0.1280e4)*_t26*_t6 + _t28 + (0.3577e4 / 0.10497600e8)*_t35 + (0.243e3 / 0.51200e5)*_t36*_t37;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _t19*_t41 + _t21*_t38 + 0.2e1*_t29*_t33;
  out[6] = d3f_da3;
  const double d3f_dx_da2 = _t42*x;
  out[7] = d3f_dx_da2;
  const double d3f_dx2_da = _t34;
  out[8] = d3f_dx2_da;
  const double d3f_dx3 = _t10*_t23*_t25 + (0.6561e4 / 0.2048000e7)*_t11*_t46*xc_powi(x, 7) + (0.729e3 / 0.10240e5)*_t24*_t45 + _t43*x + _t44*x;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = _t19*(xc_powi(_t14, 5)*_t20 + _t14*_t48 - 0.4e1 / 0.25e2*_t16*_t32 - _t31*_t48 + _t39*((0.1e1 / 0.25e2)*a - 0.1e1 / 0.25e2)) + _t21*_t47 + 0.3e1*_t29*_t41 + 0.3e1*_t33*_t38;
  out[10] = d4f_da4;
  const double d4f_dx_da3 = _t27*_t47*x;
  out[11] = d4f_dx_da3;
  const double d4f_dx2_da2 = _t42;
  out[12] = d4f_dx2_da2;
  const double d4f_dx3_da = 0;
  out[13] = d4f_dx3_da;
  const double d4f_dx4 = (0.189e3 / 0.160e3)*_t1*_t26 + (0.531441e6 / 0.40960000e8)*_t11*(_t9 * _t9 * _t9 * _t9)*xc_powi(x, 8)/xc_powi(M_PI, 8) + (0.72171e5 / 0.1024000e7)*_t36*_t46 + _t43 + _t44 + (0.29889e5 / 0.51200e5)*_t45*_t6;
  out[14] = d4f_dx4;
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
  const double _t7 = _t4*_t6;
#endif
#if _KMAX >= 2
  const double _t8 = xc_powr(0.6e1, 1, 3);
  const double _t9 = (M_CBRTPI * M_CBRTPI);
  const double _t10 = _t6*_t8*_t9;
#endif
#if _KMAX >= 3
  const double _t11 = xc_powr(x, -9, 2);
  const double _t12 = xc_powr(0.3e1, 1, 2);
#endif

  const double f = -_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -2.4739499999999999*_t7/xc_powr(x, 3, 2);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = 3.7109249999999996*_t1*_t2*_t3*_t6/xc_powr(x, 5, 2) - 12.240857204999999*_t10/(x * x * x);
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -60.566537364619492*M_PI*_t11*_t12*_t6 + 55.083857422499996*_t6*_t8*_t9/(x * x * x * x) - 9.277312499999999*_t7/xc_powr(x, 7, 2);
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 32.470593749999999*_t1*_t11*_t2*_t3*_t6 - 266.23864420874997*_t10/xc_powi(x, 5) + 545.09883628157547*M_PI*_t12*_t6/xc_powr(x, 11, 2) - 149.83858511320039*xc_powr(0.6e1, 2, 3)*(M_PI * M_CBRTPI)*_t6/xc_powi(x, 6);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_alpha_k, _KMAX)(const xc_func_type *p, double rs, double z, double x, double t, double *out) {
  const mgga_x_rppscan_params *params = (const mgga_x_rppscan_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(mgga_alpha_reg_k, _KMAX)(p, x, t, params->eta, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[2];
  out[1] = df_dt;
  const double df_dx = _hc0[3];
  out[2] = df_dx;
  const double df_dz = 0;
  out[3] = df_dz;
  const double df_drs = 0;
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[5] = d2f_dt2;
  const double d2f_dx_dt = _hc0[8];
  out[6] = d2f_dx_dt;
  const double d2f_dx2 = _hc0[9];
  out[7] = d2f_dx2;
  const double d2f_dz_dt = 0;
  out[8] = d2f_dz_dt;
  const double d2f_dz_dx = 0;
  out[9] = d2f_dz_dx;
  const double d2f_dz2 = 0;
  out[10] = d2f_dz2;
  const double d2f_drs_dt = 0;
  out[11] = d2f_drs_dt;
  const double d2f_drs_dx = 0;
  out[12] = d2f_drs_dx;
  const double d2f_drs_dz = 0;
  out[13] = d2f_drs_dz;
  const double d2f_drs2 = 0;
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[15] = d3f_dt3;
  const double d3f_dx_dt2 = 0;
  out[16] = d3f_dx_dt2;
  const double d3f_dx2_dt = _hc0[18];
  out[17] = d3f_dx2_dt;
  const double d3f_dx3 = _hc0[19];
  out[18] = d3f_dx3;
  const double d3f_dz_dt2 = 0;
  out[19] = d3f_dz_dt2;
  const double d3f_dz_dx_dt = 0;
  out[20] = d3f_dz_dx_dt;
  const double d3f_dz_dx2 = 0;
  out[21] = d3f_dz_dx2;
  const double d3f_dz2_dt = 0;
  out[22] = d3f_dz2_dt;
  const double d3f_dz2_dx = 0;
  out[23] = d3f_dz2_dx;
  const double d3f_dz3 = 0;
  out[24] = d3f_dz3;
  const double d3f_drs_dt2 = 0;
  out[25] = d3f_drs_dt2;
  const double d3f_drs_dx_dt = 0;
  out[26] = d3f_drs_dx_dt;
  const double d3f_drs_dx2 = 0;
  out[27] = d3f_drs_dx2;
  const double d3f_drs_dz_dt = 0;
  out[28] = d3f_drs_dz_dt;
  const double d3f_drs_dz_dx = 0;
  out[29] = d3f_drs_dz_dx;
  const double d3f_drs_dz2 = 0;
  out[30] = d3f_drs_dz2;
  const double d3f_drs2_dt = 0;
  out[31] = d3f_drs2_dt;
  const double d3f_drs2_dx = 0;
  out[32] = d3f_drs2_dx;
  const double d3f_drs2_dz = 0;
  out[33] = d3f_drs2_dz;
  const double d3f_drs3 = 0;
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[35] = d4f_dt4;
  const double d4f_dx_dt3 = 0;
  out[36] = d4f_dx_dt3;
  const double d4f_dx2_dt2 = 0;
  out[37] = d4f_dx2_dt2;
  const double d4f_dx3_dt = _hc0[33];
  out[38] = d4f_dx3_dt;
  const double d4f_dx4 = _hc0[34];
  out[39] = d4f_dx4;
  const double d4f_dz_dt3 = 0;
  out[40] = d4f_dz_dt3;
  const double d4f_dz_dx_dt2 = 0;
  out[41] = d4f_dz_dx_dt2;
  const double d4f_dz_dx2_dt = 0;
  out[42] = d4f_dz_dx2_dt;
  const double d4f_dz_dx3 = 0;
  out[43] = d4f_dz_dx3;
  const double d4f_dz2_dt2 = 0;
  out[44] = d4f_dz2_dt2;
  const double d4f_dz2_dx_dt = 0;
  out[45] = d4f_dz2_dx_dt;
  const double d4f_dz2_dx2 = 0;
  out[46] = d4f_dz2_dx2;
  const double d4f_dz3_dt = 0;
  out[47] = d4f_dz3_dt;
  const double d4f_dz3_dx = 0;
  out[48] = d4f_dz3_dx;
  const double d4f_dz4 = 0;
  out[49] = d4f_dz4;
  const double d4f_drs_dt3 = 0;
  out[50] = d4f_drs_dt3;
  const double d4f_drs_dx_dt2 = 0;
  out[51] = d4f_drs_dx_dt2;
  const double d4f_drs_dx2_dt = 0;
  out[52] = d4f_drs_dx2_dt;
  const double d4f_drs_dx3 = 0;
  out[53] = d4f_drs_dx3;
  const double d4f_drs_dz_dt2 = 0;
  out[54] = d4f_drs_dz_dt2;
  const double d4f_drs_dz_dx_dt = 0;
  out[55] = d4f_drs_dz_dx_dt;
  const double d4f_drs_dz_dx2 = 0;
  out[56] = d4f_drs_dz_dx2;
  const double d4f_drs_dz2_dt = 0;
  out[57] = d4f_drs_dz2_dt;
  const double d4f_drs_dz2_dx = 0;
  out[58] = d4f_drs_dz2_dx;
  const double d4f_drs_dz3 = 0;
  out[59] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = 0;
  out[60] = d4f_drs2_dt2;
  const double d4f_drs2_dx_dt = 0;
  out[61] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx2 = 0;
  out[62] = d4f_drs2_dx2;
  const double d4f_drs2_dz_dt = 0;
  out[63] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz_dx = 0;
  out[64] = d4f_drs2_dz_dx;
  const double d4f_drs2_dz2 = 0;
  out[65] = d4f_drs2_dz2;
  const double d4f_drs3_dt = 0;
  out[66] = d4f_drs3_dt;
  const double d4f_drs3_dx = 0;
  out[67] = d4f_drs3_dx;
  const double d4f_drs3_dz = 0;
  out[68] = d4f_drs3_dz;
  const double d4f_drs4 = 0;
  out[69] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_f_alpha_large_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_rppscan_params *params = (const mgga_x_rppscan_params *)(p->params);

  const double _t1 = 0.1e1 - a;
  const double _t2 = params->d*exp(params->c2/_t1);
#if _KMAX >= 1
  const double _t3 = _t2*params->c2;
#endif
#if _KMAX >= 2
  const double _t4 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t5 = _t2*((params->c2) * (params->c2));
#endif
#if _KMAX >= 3
  const double _t6 = xc_powi(_t1, -6);
  const double _t7 = _t2*((params->c2) * (params->c2) * (params->c2));
  const double _t8 = xc_powi(_t1, -5);
#endif

  const double f = -_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t3/(_t1 * _t1);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = -_t4*_t5 - 0.2e1*_t3/(_t1 * _t1 * _t1);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -0.6e1*_t3*_t4 - 0.6e1*_t5*_t8 - _t6*_t7;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.24e2*_t3*_t8 - 0.36e2*_t5*_t6 - 0.12e2*_t7/xc_powi(_t1, 7) - _t2*((params->c2) * (params->c2) * (params->c2) * (params->c2))/xc_powi(_t1, 8);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_f_k, _KMAX)(const xc_func_type *p, double rs, double z, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(rscan_alpha_k, _KMAX)(p, 0, 0, x, t, _hc0);
  const double _t1 = _hc0[0] > 2.5;
  const double _t2 = _hc0[0] <= 2.5;
  const double _t3 = my_piecewise3(_t1, 2.5, _hc0[0]);
  const double _t4 = (_t3 * _t3);
  const double _t5 = (_t3 * _t3 * _t3);
  const double _t6 = (_t3 * _t3 * _t3 * _t3);
  const double _t7 = xc_powi(_t3, 5);
  const double _t8 = xc_powi(_t3, 6);
#if _KMAX >= 1
  const double _t14 = my_piecewise3(_t1, 0, _hc0[1]);
  const double _t15 = 0.88911099999999998*_t3;
  const double _t16 = 1.9892598031469999*_t4;
  const double _t17 = 4.4399902079849998*_t6;
  const double _t18 = 0.16230090325400001*_t8;
  const double _t19 = my_piecewise3(_t1, _hc0[1], 0);
  const double _t23 = my_piecewise3(_t1, 0, _hc0[2]);
  const double _t24 = my_piecewise3(_t1, _hc0[2], 0);
#endif
#if _KMAX >= 2
  const double _t27 = ((_hc0[1]) * (_hc0[1]));
  const double _t35 = my_piecewise3(_t1, 0, _hc0[5]);
  const double _t36 = (_t14 * _t14);
  const double _t37 = 3.9785196062939998*_t3;
  const double _t38 = 17.759960831939999*_t5;
  const double _t39 = 0.97380541952400002*_t7;
  const double _t40 = my_piecewise3(_t1, _hc0[5], 0);
  const double _t41 = (_t19 * _t19);
  const double _t51 = my_piecewise3(_t1, 0, _hc0[6]);
  const double _t52 = 0.88911099999999998*_t23;
  const double _t53 = _t14*_t23;
  const double _t54 = my_piecewise3(_t1, _hc0[6], 0);
  const double _t67 = my_piecewise3(_t1, 0, _hc0[7]);
  const double _t68 = (_t23 * _t23);
  const double _t69 = my_piecewise3(_t1, _hc0[7], 0);
  const double _t70 = (_t24 * _t24);
#endif
#if _KMAX >= 3
  const double _t73 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t76 = 0.3e1*_hc0[1];
  const double _t77 = _hc0[5]*_t76;
  const double _t84 = 0.3e1*_hc0[5];
  const double _t91 = my_piecewise3(_t1, 0, _hc0[15]);
  const double _t92 = (_t14 * _t14 * _t14);
  const double _t93 = 2.6673330000000002*_t14;
  const double _t94 = 53.279882495819997*_t4;
  const double _t95 = 4.8690270976200001*_t6;
  const double _t96 = 11.935558818881999*_t3;
  const double _t97 = _t14*_t35;
  const double _t98 = 53.279882495819997*_t5;
  const double _t99 = 2.921416258572*_t7;
  const double _t100 = my_piecewise3(_t1, _hc0[15], 0);
  const double _t101 = (_t19 * _t19 * _t19);
  const double _t111 = 0.2e1*_hc0[1];
  const double _t121 = my_piecewise3(_t1, 0, _hc0[16]);
  const double _t122 = 1.778222*_t51;
  const double _t123 = 3.9785196062939998*_t36;
  const double _t124 = 7.9570392125879996*_t3;
  const double _t125 = _t14*_t51;
  const double _t126 = _t23*_t35;
  const double _t127 = 35.519921663879998*_t5;
  const double _t128 = 1.947610839048*_t7;
  const double _t129 = _t23*_t36;
  const double _t130 = my_piecewise3(_t1, _hc0[16], 0);
  const double _t153 = my_piecewise3(_t1, 0, _hc0[17]);
  const double _t154 = 0.88911099999999998*_t67;
  const double _t155 = 3.9785196062939998*_t68;
  const double _t156 = _t14*_t67;
  const double _t157 = _t23*_t51;
  const double _t158 = _t14*_t68;
  const double _t159 = my_piecewise3(_t1, _hc0[17], 0);
  const double _t184 = my_piecewise3(_t1, 0, _hc0[18]);
  const double _t185 = (_t23 * _t23 * _t23);
  const double _t186 = 2.6673330000000002*_t23;
  const double _t187 = _t23*_t67;
  const double _t188 = my_piecewise3(_t1, _hc0[18], 0);
  const double _t189 = (_t24 * _t24 * _t24);
#endif
#if _KMAX >= 4
  const double _t193 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t194 = 0.4e1*_hc0[1];
  const double _t195 = _hc0[15]*_t194;
  const double _t196 = 0.3e1*((_hc0[5]) * (_hc0[5]));
  const double _t198 = 0.6e1*_hc0[5]*_t27;
  const double _t200 = _hc0[1]*_hc0[5];
  const double _t201 = 0.12e2*_t200;
  const double _t206 = my_piecewise3(_t1, 0, _hc0[35]);
  const double _t207 = (_t14 * _t14 * _t14 * _t14);
  const double _t208 = (_t35 * _t35);
  const double _t209 = _t14*_t91;
  const double _t210 = 106.55976499163999*_t3;
  const double _t211 = _t35*_t36;
  const double _t212 = 19.47610839048*_t5;
  const double _t213 = 15.914078425175999*_t3;
  const double _t214 = 71.039843327759996*_t5;
  const double _t215 = 3.8952216780960001*_t7;
  const double _t216 = 319.67929497491997*_t4;
  const double _t217 = 29.21416258572*_t6;
  const double _t229 = my_piecewise3(_t1, 0, _hc0[36]);
  const double _t230 = 2.6673330000000002*_t51;
  const double _t231 = 11.935558818881999*_t51;
  const double _t232 = _t121*_t14;
  const double _t233 = _t23*_t91;
  const double _t234 = _t35*_t51;
  const double _t235 = 11.935558818881999*_t53;
  const double _t236 = _t23*_t92;
  const double _t237 = _t4*_t51;
  const double _t238 = 159.83964748745998*_t237;
  const double _t239 = 14.60708129286*_t6;
  const double _t240 = _t35*_t53;
  const double _t241 = 159.83964748745998*_t4;
  const double _t242 = 0.3e1*_t54;
  const double _t255 = my_piecewise3(_t1, 0, _hc0[37]);
  const double _t256 = (_t51 * _t51);
  const double _t257 = _t14*_t153;
  const double _t258 = _t121*_t23;
  const double _t259 = _t35*_t67;
  const double _t260 = _t51*_t53;
  const double _t261 = _t36*_t68;
  const double _t262 = _t36*_t67;
  const double _t263 = _t35*_t68;
  const double _t269 = my_piecewise3(_t1, 0, _hc0[38]);
  const double _t270 = _t14*_t184;
  const double _t271 = _t153*_t23;
  const double _t272 = _t51*_t67;
  const double _t273 = _t14*_t185;
  const double _t274 = _t53*_t67;
  const double _t278 = 0.2e1*_hc0[7];
  const double _t282 = my_piecewise3(_t1, 0, _hc0[39]);
  const double _t283 = (_t23 * _t23 * _t23 * _t23);
  const double _t284 = (_t67 * _t67);
  const double _t285 = _t184*_t23;
  const double _t286 = _t67*_t68;
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(rscan_f_alpha_large_k, _KMAX)(p, my_piecewise3(_t1, _hc0[0], 2.5), _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_y_k, _KMAX)(p, x, _hc0[0], _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_h1x_k, _KMAX)(p, _hc2[0], _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_gx_k, _KMAX)(p, x, _hc4);
  const double _t9 = my_piecewise3(_t2, -0.023185843322000001*xc_powi(_t3, 7) - 0.66700000000000004*_t3 - 0.44455549999999999*_t4 - 0.66308660104899997*_t5 + 1.45129704449*_t6 - 0.88799804159700002*_t7 + 0.234528941479*_t8 + 0.1e1, _hc1[0]);
  const double _t10 = 0.1e1 - _t9;
  const double _t11 = _hc3[0]*_t10 + 1.1739999999999999*_t9;
#if _KMAX >= 1
  const double _t12 = _hc3[1]*_t10;
  const double _t13 = _hc2[1]*_t12;
  const double _t20 = my_piecewise3(_t2, -_t14*_t15 - _t14*_t16 - _t14*_t17 - _t14*_t18 + 5.8051881779599999*_t14*_t5 + 1.4071736488740001*_t14*_t7 - 0.66700000000000004*_t14, _hc1[1]*_t19);
  const double _t21 = _hc0[1]*_t13 - _hc3[0]*_t20 + 1.1739999999999999*_t20;
  const double _t22 = _hc0[2]*_hc2[1] + _hc2[2];
  const double _t25 = my_piecewise3(_t2, -_t15*_t23 - _t16*_t23 - _t17*_t23 - _t18*_t23 + 5.8051881779599999*_t23*_t5 + 1.4071736488740001*_t23*_t7 - 0.66700000000000004*_t23, _hc1[1]*_t24);
  const double _t26 = -_hc3[0]*_t25 + _t12*_t22 + 1.1739999999999999*_t25;
#endif
#if _KMAX >= 2
  const double _t28 = _hc2[3]*_t27;
  const double _t29 = _hc3[2]*_t10;
  const double _t30 = ((_hc2[1]) * (_hc2[1]));
  const double _t31 = _t27*_t30;
  const double _t32 = _hc0[1]*_hc2[1];
  const double _t33 = _hc3[1]*_t20;
  const double _t34 = 0.2e1*_t33;
  const double _t42 = my_piecewise3(_t2, -_t15*_t35 - _t16*_t35 - _t17*_t35 - _t18*_t35 + 5.8051881779599999*_t35*_t5 + 1.4071736488740001*_t35*_t7 - 0.66700000000000004*_t35 - _t36*_t37 - _t36*_t38 - _t36*_t39 + 17.415564533880001*_t36*_t4 + 7.0358682443700005*_t36*_t6 - 0.88911099999999998*_t36, _hc1[1]*_t40 + _hc1[2]*_t41);
  const double _t43 = _hc0[5]*_t13 - _hc3[0]*_t42 + _t12*_t28 + _t29*_t31 - _t32*_t34 + 1.1739999999999999*_t42;
  const double _t44 = _hc0[1]*_hc2[4];
  const double _t45 = _hc0[6]*_hc2[1];
  const double _t46 = _hc0[2]*_hc2[3];
  const double _t47 = _hc0[1]*_t46;
  const double _t48 = _t44 + _t45 + _t47;
  const double _t49 = _hc3[1]*_t25;
  const double _t50 = _hc3[1]*_t22;
  const double _t55 = _hc1[2]*_t24;
  const double _t56 = my_piecewise3(_t2, 17.415564533880001*_t14*_t23*_t4 + 7.0358682443700005*_t14*_t23*_t6 - _t14*_t52 - _t15*_t51 - _t16*_t51 - _t17*_t51 - _t18*_t51 - _t37*_t53 - _t38*_t53 - _t39*_t53 + 5.8051881779599999*_t5*_t51 + 1.4071736488740001*_t51*_t7 - 0.66700000000000004*_t51, _hc1[1]*_t54 + _t19*_t55);
  const double _t57 = _hc0[1]*_hc2[1]*_hc3[2]*_t10*_t22 - _hc3[0]*_t56 + _hc3[1]*_t10*_t48 - _t20*_t50 - _t32*_t49 + 1.1739999999999999*_t56;
  const double _t58 = 0.2e1*_hc4[1];
  const double _t59 = (_t22 * _t22);
  const double _t60 = _hc3[2]*_t59;
  const double _t61 = _hc0[2]*_hc2[4];
  const double _t62 = _hc0[7]*_hc2[1];
  const double _t63 = _hc2[4] + _t46;
  const double _t64 = _hc0[2]*_t63;
  const double _t65 = _hc2[5] + _t61 + _t62 + _t64;
  const double _t66 = 0.2e1*_t50;
  const double _t71 = my_piecewise3(_t2, -_t15*_t67 - _t16*_t67 - _t17*_t67 - _t18*_t67 - _t37*_t68 - _t38*_t68 - _t39*_t68 + 17.415564533880001*_t4*_t68 + 5.8051881779599999*_t5*_t67 + 7.0358682443700005*_t6*_t68 + 1.4071736488740001*_t67*_t7 - 0.66700000000000004*_t67 - 0.88911099999999998*_t68, _hc1[1]*_t69 + _hc1[2]*_t70);
  const double _t72 = -_hc3[0]*_t71 + _t10*_t60 + _t12*_t65 - _t25*_t66 + 1.1739999999999999*_t71;
#endif
#if _KMAX >= 3
  const double _t74 = _hc2[6]*_t73;
  const double _t75 = _hc2[3]*_t12;
  const double _t78 = _hc3[3]*_t10;
  const double _t79 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t80 = _t73*_t79;
  const double _t81 = _t29*_t30;
  const double _t82 = 0.3e1*_t29;
  const double _t83 = _hc2[1]*_hc2[3]*_t73;
  const double _t85 = _hc2[1]*_t33;
  const double _t86 = 0.3e1*_t33;
  const double _t87 = _hc3[2]*_t31;
  const double _t88 = 0.3e1*_t20;
  const double _t89 = 0.3e1*_t42;
  const double _t90 = _hc3[1]*_t32;
  const double _t102 = 0.3e1*_hc1[2];
  const double _t103 = _t102*_t19;
  const double _t104 = my_piecewise3(_t2, 52.246693601640004*_t14*_t35*_t4 + 21.107604733110001*_t14*_t35*_t6 - _t15*_t91 - _t16*_t91 - _t17*_t91 - _t18*_t91 + 34.831129067760003*_t3*_t92 - _t35*_t93 + 5.8051881779599999*_t5*_t91 + 28.143472977480002*_t5*_t92 + 1.4071736488740001*_t7*_t91 - 0.66700000000000004*_t91 - _t92*_t94 - _t92*_t95 - 3.9785196062939998*_t92 - _t96*_t97 - _t97*_t98 - _t97*_t99, _hc1[1]*_t100 + _hc1[3]*_t101 + _t103*_t40);
  const double _t105 = _hc0[15]*_t13 - _hc3[0]*_t104 + 1.1739999999999999*_t104 + _t12*_t74 - _t28*_t86 + _t75*_t77 + _t77*_t81 + _t78*_t80 + _t82*_t83 - _t84*_t85 - _t87*_t88 - _t89*_t90;
  const double _t106 = _hc0[16]*_hc2[1];
  const double _t107 = _hc0[5]*_hc2[4];
  const double _t108 = _hc0[5]*_t46;
  const double _t109 = _hc2[7]*_t27;
  const double _t110 = _hc0[6]*_hc2[3];
  const double _t112 = _hc0[2]*_hc2[6];
  const double _t113 = _t112*_t27;
  const double _t114 = _t106 + _t107 + _t108 + _t109 + _t110*_t111 + _t113;
  const double _t115 = _hc2[1]*_t49;
  const double _t116 = _hc3[2]*_t22;
  const double _t117 = _t116*_t20;
  const double _t118 = 0.2e1*_t117;
  const double _t119 = 0.2e1*_t48;
  const double _t120 = 0.2e1*_t90;
  const double _t131 = 0.2e1*_hc1[2];
  const double _t132 = _t131*_t19;
  const double _t133 = _hc1[3]*_t41;
  const double _t134 = my_piecewise3(_t2, -_t121*_t15 - _t121*_t16 - _t121*_t17 - _t121*_t18 + 5.8051881779599999*_t121*_t5 + 1.4071736488740001*_t121*_t7 - 0.66700000000000004*_t121 - _t122*_t14 - _t123*_t23 - _t124*_t125 - _t125*_t127 - _t125*_t128 - _t126*_t37 - _t126*_t38 - _t126*_t39 - _t129*_t94 - _t129*_t95 + 34.831129067760003*_t14*_t4*_t51 + 14.071736488740001*_t14*_t51*_t6 + 34.831129067760003*_t23*_t3*_t36 + 17.415564533880001*_t23*_t35*_t4 + 7.0358682443700005*_t23*_t35*_t6 + 28.143472977480002*_t23*_t36*_t5 - _t35*_t52, _hc1[1]*_t130 + _t132*_t54 + _t133*_t24 + _t40*_t55);
  const double _t135 = 0.2e1*_hc0[1]*_hc2[1]*_hc3[2]*_t10*_t48 + _hc0[5]*_hc2[1]*_hc3[2]*_t10*_t22 - _hc0[5]*_t115 + _hc2[3]*_hc3[2]*_t10*_t22*_t27 - _hc3[0]*_t134 + _hc3[1]*_t10*_t114 + _hc3[3]*_t10*_t22*_t27*_t30 - _t118*_t32 - _t119*_t33 - _t120*_t56 + 1.1739999999999999*_t134 - _t25*_t87 - _t28*_t49 - _t42*_t50;
  const double _t136 = 0.2e1*_t44 + 0.2e1*_t45 + 0.2e1*_t47;
  const double _t137 = _hc0[1]*_hc2[8];
  const double _t138 = _hc0[17]*_hc2[1];
  const double _t139 = _hc0[6]*_hc2[4];
  const double _t140 = _hc0[1]*_hc2[7];
  const double _t141 = _hc0[2]*_t140;
  const double _t142 = _hc0[7]*_hc2[3];
  const double _t143 = _hc0[1]*_t142;
  const double _t144 = _hc0[6]*_t63;
  const double _t145 = _hc0[1]*_t112;
  const double _t146 = _t110 + _t140 + _t145;
  const double _t147 = _hc0[2]*_t146;
  const double _t148 = _t137 + _t138 + _t139 + _t141 + _t143 + _t144 + _t147;
  const double _t149 = _t116*_t32;
  const double _t150 = 0.2e1*_t25;
  const double _t151 = _hc3[1]*_t65;
  const double _t152 = _hc3[1]*_t71;
  const double _t160 = _hc1[2]*_t69;
  const double _t161 = 0.2e1*_t55;
  const double _t162 = _hc1[3]*_t70;
  const double _t163 = my_piecewise3(_t2, -_t122*_t23 - _t124*_t157 - _t127*_t157 - _t128*_t157 - _t14*_t154 - _t14*_t155 + 34.831129067760003*_t14*_t3*_t68 + 17.415564533880001*_t14*_t4*_t67 + 28.143472977480002*_t14*_t5*_t68 + 7.0358682443700005*_t14*_t6*_t67 - _t15*_t153 - _t153*_t16 - _t153*_t17 - _t153*_t18 + 5.8051881779599999*_t153*_t5 + 1.4071736488740001*_t153*_t7 - 0.66700000000000004*_t153 - _t156*_t37 - _t156*_t38 - _t156*_t39 - _t158*_t94 - _t158*_t95 + 34.831129067760003*_t23*_t4*_t51 + 14.071736488740001*_t23*_t51*_t6, _hc1[1]*_t159 + _t160*_t19 + _t161*_t54 + _t162*_t19);
  const double _t164 = _hc0[1]*_hc2[1]*_hc3[2]*_t10*_t65 + _hc0[1]*_hc2[1]*_hc3[3]*_t10*_t59 - _hc3[0]*_t163 + _hc3[1]*_t10*_t148 + _hc3[2]*_t10*_t136*_t22 - _t119*_t49 - _t149*_t150 - _t151*_t20 - _t152*_t32 + 1.1739999999999999*_t163 - _t20*_t60 - _t56*_t66;
  const double _t165 = 0.3e1*_hc4[2];
  const double _t166 = 0.3e1*_hc4[1];
  const double _t167 = (_t22 * _t22 * _t22);
  const double _t168 = _hc3[3]*_t167;
  const double _t169 = _t22*_t29;
  const double _t170 = 0.2e1*_hc2[5] + 0.2e1*_t61 + 0.2e1*_t62 + 0.2e1*_t64;
  const double _t171 = 0.3e1*_t25;
  const double _t172 = _hc0[18]*_hc2[1];
  const double _t173 = _hc0[2]*_hc2[8];
  const double _t174 = _hc0[7]*_hc2[4];
  const double _t175 = _hc0[2]*_hc2[7];
  const double _t176 = _hc2[8] + _t175;
  const double _t177 = _hc0[2]*_t176;
  const double _t178 = 0.2e1*_t63;
  const double _t179 = _hc2[7] + _t112;
  const double _t180 = _hc0[2]*_t179 + _t142 + _t176;
  const double _t181 = _hc0[2]*_t180;
  const double _t182 = _hc0[7]*_t178 + _hc2[9] + _t172 + _t173 + _t174 + _t177 + _t181;
  const double _t183 = 0.3e1*_t50;
  const double _t190 = 0.3e1*_t55;
  const double _t191 = my_piecewise3(_t2, -_t15*_t184 - _t16*_t184 - _t17*_t184 - _t18*_t184 + 5.8051881779599999*_t184*_t5 + 1.4071736488740001*_t184*_t7 - 0.66700000000000004*_t184 + 34.831129067760003*_t185*_t3 + 28.143472977480002*_t185*_t5 - _t185*_t94 - _t185*_t95 - 3.9785196062939998*_t185 - _t186*_t67 - _t187*_t96 - _t187*_t98 - _t187*_t99 + 52.246693601640004*_t23*_t4*_t67 + 21.107604733110001*_t23*_t6*_t67, _hc1[1]*_t188 + _hc1[3]*_t189 + _t190*_t69);
  const double _t192 = -_hc3[0]*_t191 + _t10*_t168 + _t12*_t182 - _t151*_t171 + _t169*_t170 + _t169*_t65 - _t171*_t60 - _t183*_t71 + 1.1739999999999999*_t191;
#endif
#if _KMAX >= 4
  const double _t197 = _hc3[4]*_t10;
  const double _t199 = _hc0[5]*_hc2[1];
  const double _t202 = _hc3[2]*_t20;
  const double _t203 = _hc3[3]*_t80;
  const double _t204 = 0.6e1*_t42;
  const double _t205 = _hc3[1]*_t204;
  const double _t218 = _hc1[2]*_t19;
  const double _t219 = my_piecewise3(_t2, 69.662258135520005*_t14*_t4*_t91 + 28.143472977480002*_t14*_t6*_t91 - _t15*_t206 - _t16*_t206 - _t17*_t206 - _t18*_t206 + 5.8051881779599999*_t206*_t5 + 1.4071736488740001*_t206*_t7 - 0.66700000000000004*_t206 - _t207*_t210 - _t207*_t212 + 84.430418932440006*_t207*_t4 + 34.831129067760003*_t207 + 52.246693601640004*_t208*_t4 + 21.107604733110001*_t208*_t6 - _t208*_t96 - _t208*_t98 - _t208*_t99 - 2.6673330000000002*_t208 - _t209*_t213 - _t209*_t214 - _t209*_t215 - 3.5564439999999999*_t209 - _t211*_t216 - _t211*_t217 - 23.871117637763998*_t211 + 208.98677440656002*_t3*_t35*_t36 + 168.86083786488001*_t35*_t36*_t5, _hc1[1]*my_piecewise3(_t1, _hc0[35], 0) + _hc1[4]*(_t19 * _t19 * _t19 * _t19) + 0.4e1*_t100*_t218 + _t102*(_t40 * _t40) + 0.6e1*_t133*_t40);
  const double _t220 = _hc3[2]*_t171;
  const double _t221 = _hc2[1]*_t84;
  const double _t222 = _hc3[3]*_t22*_t31;
  const double _t223 = _t32*_t48;
  const double _t224 = _hc0[16]*_hc2[3];
  const double _t225 = _hc0[2]*_hc2[10];
  const double _t226 = _hc0[6]*_hc2[6];
  const double _t227 = _hc3[1]*_t48;
  const double _t228 = 0.3e1*_t56;
  const double _t243 = _hc1[3]*_t19*_t24;
  const double _t244 = 0.3e1*_t243;
  const double _t245 = my_piecewise3(_t2, 52.246693601640004*_t121*_t14*_t4 + 21.107604733110001*_t121*_t14*_t6 - _t121*_t93 + 104.49338720328001*_t14*_t23*_t3*_t35 + 84.430418932440006*_t14*_t23*_t35*_t5 - _t15*_t229 - _t16*_t229 - _t17*_t229 - _t18*_t229 - _t210*_t236 - _t212*_t236 + 5.8051881779599999*_t229*_t5 + 1.4071736488740001*_t229*_t7 - 0.66700000000000004*_t229 + 17.415564533880001*_t23*_t4*_t91 + 84.430418932440006*_t23*_t4*_t92 + 7.0358682443700005*_t23*_t6*_t91 + 34.831129067760003*_t23*_t92 - _t230*_t35 - _t231*_t36 - _t232*_t96 - _t232*_t98 - _t232*_t99 - _t233*_t37 - _t233*_t38 - _t233*_t39 - _t234*_t96 - _t234*_t98 - _t234*_t99 - _t235*_t35 - _t238*_t36 - _t239*_t240 - _t239*_t36*_t51 - _t240*_t241 + 104.49338720328001*_t3*_t36*_t51 + 52.246693601640004*_t35*_t4*_t51 + 21.107604733110001*_t35*_t51*_t6 + 84.430418932440006*_t36*_t5*_t51 - _t52*_t91, _hc1[1]*my_piecewise3(_t1, _hc0[36], 0) + _hc1[4]*_t101*_t24 + _t100*_t55 + _t102*_t40*_t54 + _t103*_t130 + _t133*_t242 + _t244*_t40);
  const double _t246 = _t116*_t150;
  const double _t247 = 0.2e1*_t32;
  const double _t248 = _hc3[3]*_t59;
  const double _t249 = 0.4e1*_t25;
  const double _t250 = _hc0[17]*_hc2[3];
  const double _t251 = _hc2[11]*_t27;
  const double _t252 = _hc0[7]*_hc2[6];
  const double _t253 = 0.2e1*_t146;
  const double _t254 = 0.4e1*_t56;
  const double _t264 = my_piecewise3(_t2, 34.831129067760003*_t121*_t23*_t4 + 14.071736488740001*_t121*_t23*_t6 - _t123*_t67 - _t124*_t256 - _t124*_t257 - _t124*_t258 - _t127*_t256 - _t127*_t257 - _t127*_t258 - _t128*_t256 - _t128*_t257 - _t128*_t258 + 34.831129067760003*_t14*_t153*_t4 + 14.071736488740001*_t14*_t153*_t6 + 139.32451627104001*_t14*_t23*_t3*_t51 + 112.57389190992001*_t14*_t23*_t5*_t51 - _t15*_t255 - _t154*_t35 - _t155*_t35 - _t16*_t255 - _t17*_t255 - _t18*_t255 - _t210*_t261 - _t212*_t261 - 213.11952998327999*_t237*_t53 + 5.8051881779599999*_t255*_t5 + 1.4071736488740001*_t255*_t7 - 0.66700000000000004*_t255 + 34.831129067760003*_t256*_t4 + 14.071736488740001*_t256*_t6 - 1.778222*_t256 - 1.778222*_t257 - 1.778222*_t258 - _t259*_t37 - _t259*_t38 - _t259*_t39 - 19.47610839048*_t260*_t6 - 15.914078425175999*_t260 - _t262*_t94 - _t262*_t95 - _t263*_t94 - _t263*_t95 + 34.831129067760003*_t3*_t35*_t68 + 34.831129067760003*_t3*_t36*_t67 + 17.415564533880001*_t35*_t4*_t67 + 28.143472977480002*_t35*_t5*_t68 + 7.0358682443700005*_t35*_t6*_t67 + 84.430418932440006*_t36*_t4*_t68 + 28.143472977480002*_t36*_t5*_t67 + 34.831129067760003*_t36*_t68, _hc1[1]*my_piecewise3(_t1, _hc0[37], 0) + _hc1[4]*_t41*_t70 + _t130*_t161 + _t131*(_t54 * _t54) + _t132*_t159 + _t133*_t69 + _t160*_t40 + _t162*_t40 + 0.4e1*_t243*_t54);
  const double _t265 = _hc0[18]*_hc2[3];
  const double _t266 = _hc0[1]*_hc2[12];
  const double _t267 = _hc0[1]*_hc2[11];
  const double _t268 = _hc0[2]*_t267 + _hc0[6]*_hc2[7] + _t266;
  const double _t275 = my_piecewise3(_t2, 17.415564533880001*_t14*_t184*_t4 + 7.0358682443700005*_t14*_t184*_t6 + 84.430418932440006*_t14*_t185*_t4 + 34.831129067760003*_t14*_t185 + 104.49338720328001*_t14*_t23*_t3*_t67 + 84.430418932440006*_t14*_t23*_t5*_t67 - _t15*_t269 - _t153*_t186 + 52.246693601640004*_t153*_t23*_t4 + 21.107604733110001*_t153*_t23*_t6 - _t16*_t269 - _t17*_t269 - _t18*_t269 - _t210*_t273 - _t212*_t273 - _t230*_t67 - _t231*_t68 - _t235*_t67 - _t238*_t68 - _t239*_t274 - _t239*_t51*_t68 - _t241*_t274 + 5.8051881779599999*_t269*_t5 + 1.4071736488740001*_t269*_t7 - 0.66700000000000004*_t269 - _t270*_t37 - _t270*_t38 - _t270*_t39 - 0.88911099999999998*_t270 - _t271*_t96 - _t271*_t98 - _t271*_t99 - _t272*_t96 - _t272*_t98 - _t272*_t99 + 104.49338720328001*_t3*_t51*_t68 + 52.246693601640004*_t4*_t51*_t67 + 84.430418932440006*_t5*_t51*_t68 + 21.107604733110001*_t51*_t6*_t67, _hc1[1]*my_piecewise3(_t1, _hc0[38], 0) + _hc1[4]*_t189*_t19 + _t159*_t190 + _t160*_t242 + _t162*_t242 + _t188*_t218 + _t244*_t69);
  const double _t276 = _t59*_t78;
  const double _t277 = _t116*_t249;
  const double _t279 = _hc0[2]*_hc2[11] + _hc2[12];
  const double _t280 = _hc0[2]*_hc2[12] + _hc0[2]*_t279 + _hc0[7]*_hc2[7];
  const double _t281 = 0.6e1*_t71;
  const double _t287 = my_piecewise3(_t2, -_t15*_t282 - _t16*_t282 - _t17*_t282 - _t18*_t282 + 69.662258135520005*_t184*_t23*_t4 + 28.143472977480002*_t184*_t23*_t6 - _t210*_t283 - _t212*_t283 - _t213*_t285 - _t214*_t285 - _t215*_t285 - _t216*_t286 - _t217*_t286 + 5.8051881779599999*_t282*_t5 + 1.4071736488740001*_t282*_t7 - 0.66700000000000004*_t282 + 84.430418932440006*_t283*_t4 + 34.831129067760003*_t283 + 52.246693601640004*_t284*_t4 + 21.107604733110001*_t284*_t6 - _t284*_t96 - _t284*_t98 - _t284*_t99 - 2.6673330000000002*_t284 - 3.5564439999999999*_t285 - 23.871117637763998*_t286 + 208.98677440656002*_t3*_t67*_t68 + 168.86083786488001*_t5*_t67*_t68, _hc1[1]*my_piecewise3(_t1, _hc0[39], 0) + _hc1[4]*(_t24 * _t24 * _t24 * _t24) + _t102*(_t69 * _t69) + 0.6e1*_t162*_t69 + 0.4e1*_t188*_t55);
#endif

  const double f = _hc4[0]*_t11;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc4[0]*_t21;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc4[0]*_t26 + _hc4[1]*_t11;
  out[3] = df_dx;
  const double df_dz = 0;
  out[4] = df_dz;
  const double df_drs = 0;
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc4[0]*_t43;
  out[6] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[7] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[8] = d2f_du2;
  const double d2f_dx_dt = _hc4[0]*_t57 + _hc4[1]*_t21;
  out[9] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[10] = d2f_dx_du;
  const double d2f_dx2 = _hc4[0]*_t72 + _hc4[2]*_t11 + _t26*_t58;
  out[11] = d2f_dx2;
  const double d2f_dz_dt = 0;
  out[12] = d2f_dz_dt;
  const double d2f_dz_du = 0;
  out[13] = d2f_dz_du;
  const double d2f_dz_dx = 0;
  out[14] = d2f_dz_dx;
  const double d2f_dz2 = 0;
  out[15] = d2f_dz2;
  const double d2f_drs_dt = 0;
  out[16] = d2f_drs_dt;
  const double d2f_drs_du = 0;
  out[17] = d2f_drs_du;
  const double d2f_drs_dx = 0;
  out[18] = d2f_drs_dx;
  const double d2f_drs_dz = 0;
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = 0;
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc4[0]*_t105;
  out[21] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[22] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[23] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[24] = d3f_du3;
  const double d3f_dx_dt2 = _hc4[0]*_t135 + _hc4[1]*_t43;
  out[25] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[26] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[27] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc4[0]*_t164 + _hc4[2]*_t21 + _t57*_t58;
  out[28] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[29] = d3f_dx2_du;
  const double d3f_dx3 = _hc4[0]*_t192 + _hc4[3]*_t11 + _t165*_t26 + _t166*_t72;
  out[30] = d3f_dx3;
  const double d3f_dz_dt2 = 0;
  out[31] = d3f_dz_dt2;
  const double d3f_dz_du_dt = 0;
  out[32] = d3f_dz_du_dt;
  const double d3f_dz_du2 = 0;
  out[33] = d3f_dz_du2;
  const double d3f_dz_dx_dt = 0;
  out[34] = d3f_dz_dx_dt;
  const double d3f_dz_dx_du = 0;
  out[35] = d3f_dz_dx_du;
  const double d3f_dz_dx2 = 0;
  out[36] = d3f_dz_dx2;
  const double d3f_dz2_dt = 0;
  out[37] = d3f_dz2_dt;
  const double d3f_dz2_du = 0;
  out[38] = d3f_dz2_du;
  const double d3f_dz2_dx = 0;
  out[39] = d3f_dz2_dx;
  const double d3f_dz3 = 0;
  out[40] = d3f_dz3;
  const double d3f_drs_dt2 = 0;
  out[41] = d3f_drs_dt2;
  const double d3f_drs_du_dt = 0;
  out[42] = d3f_drs_du_dt;
  const double d3f_drs_du2 = 0;
  out[43] = d3f_drs_du2;
  const double d3f_drs_dx_dt = 0;
  out[44] = d3f_drs_dx_dt;
  const double d3f_drs_dx_du = 0;
  out[45] = d3f_drs_dx_du;
  const double d3f_drs_dx2 = 0;
  out[46] = d3f_drs_dx2;
  const double d3f_drs_dz_dt = 0;
  out[47] = d3f_drs_dz_dt;
  const double d3f_drs_dz_du = 0;
  out[48] = d3f_drs_dz_du;
  const double d3f_drs_dz_dx = 0;
  out[49] = d3f_drs_dz_dx;
  const double d3f_drs_dz2 = 0;
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dt = 0;
  out[51] = d3f_drs2_dt;
  const double d3f_drs2_du = 0;
  out[52] = d3f_drs2_du;
  const double d3f_drs2_dx = 0;
  out[53] = d3f_drs2_dx;
  const double d3f_drs2_dz = 0;
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = 0;
  out[55] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc4[0]*(-0.4e1*_hc0[15]*_t85 + _hc0[35]*_t13 + ((_hc2[1]) * (_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t193*_t197 + 0.4e1*_hc2[1]*_hc2[6]*_t193*_t29 + _hc2[10]*_t12*_t193 + ((_hc2[3]) * (_hc2[3]))*_t193*_t82 + 0.6e1*_hc2[3]*_t193*_t30*_t78 - _hc2[3]*_t201*_t33 + _hc2[6]*_t12*_t198 - _hc3[0]*_t219 - 0.4e1*_t104*_t90 + _t195*_t75 + _t195*_t81 + _t196*_t75 + _t196*_t81 + _t198*_t78*_t79 - _t199*_t205 + 0.18e2*_t199*_t28*_t29 - 0.4e1*_t20*_t203 - _t201*_t202*_t30 - 0.12e2*_t202*_t83 - _t204*_t87 - _t205*_t28 + 1.1739999999999999*_t219 - 0.4e1*_t33*_t74);
  out[56] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[57] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[58] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[59] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[60] = d4f_du4;
  const double d4f_dx_dt3 = _hc4[0]*(0.3e1*_hc0[1]*_hc0[5]*_hc2[3]*_hc3[2]*_t10*_t22 + 0.3e1*_hc0[1]*_hc0[5]*_hc3[3]*_t10*_t22*_t30 + 0.3e1*_hc0[1]*_hc2[1]*_hc3[2]*_t10*_t114 + _hc0[15]*_hc2[1]*_hc3[2]*_t10*_t22 - _hc0[15]*_t115 + 0.3e1*_hc0[5]*_hc2[1]*_hc3[2]*_t10*_t48 + 0.3e1*_hc2[1]*_hc2[3]*_hc3[3]*_t10*_t22*_t73 + 0.3e1*_hc2[3]*_hc3[2]*_t10*_t27*_t48 - _hc2[3]*_t49*_t77 + _hc2[6]*_hc3[2]*_t10*_t22*_t73 - _hc3[0]*_t245 + _hc3[1]*_t10*(_hc0[15]*_hc2[4] + _hc0[15]*_t46 + _hc0[36]*_hc2[1] + _hc2[11]*_t73 + _t110*_t84 + _t140*_t84 + _t145*_t84 + _t224*_t76 + _t225*_t73 + 0.3e1*_t226*_t27) - _hc3[1]*_t221*_t56 - _hc3[1]*_t228*_t28 + 0.3e1*_hc3[3]*_t10*_t27*_t30*_t48 + _hc3[4]*_t10*_t22*_t73*_t79 - _t104*_t50 - _t114*_t86 - _t117*_t221 - 0.3e1*_t117*_t28 - 0.3e1*_t134*_t90 - _t149*_t89 - _t200*_t220*_t30 - 0.6e1*_t202*_t223 - _t203*_t25 - _t220*_t83 - _t222*_t88 - _t227*_t89 - _t228*_t87 + 1.1739999999999999*_t245 - _t49*_t74) + _hc4[1]*_t105;
  out[61] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[62] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[63] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[64] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc4[0]*(0.2e1*_hc0[1]*_hc2[1]*_hc3[2]*_t10*_t148 + 0.2e1*_hc0[1]*_hc2[1]*_hc3[3]*_t10*_t136*_t22 + _hc0[5]*_hc2[1]*_hc3[2]*_t10*_t65 + _hc0[5]*_hc2[1]*_hc3[3]*_t10*_t59 + _hc2[3]*_hc3[2]*_t10*_t27*_t65 + _hc2[3]*_hc3[3]*_t10*_t27*_t59 - _hc3[0]*_t264 + _hc3[1]*_t10*(_hc0[16]*_hc2[4] + _hc0[16]*_t63 + _hc0[2]*_t251 + _hc0[2]*(_hc0[5]*_hc2[7] + _hc0[5]*_t112 + _t111*_t226 + _t224 + _t225*_t27 + _t251) + _hc0[37]*_hc2[1] + _hc0[5]*_hc2[8] + _hc0[5]*_t142 + _hc0[5]*_t175 + 0.2e1*_hc0[6]*_t140 + _hc0[6]*_t253 + _hc2[12]*_t27 + _t111*_t250 + _t252*_t27) + _hc3[2]*_t10*_t136*_t48 + _hc3[2]*_t10*_t22*(0.2e1*_t106 + 0.2e1*_t107 + 0.2e1*_t108 + 0.2e1*_t109 + _t110*_t194 + 0.2e1*_t113) - _hc3[2]*_t223*_t249 + _hc3[3]*_t10*_t27*_t30*_t65 + _hc3[4]*_t10*_t27*_t30*_t59 - 0.2e1*_t114*_t49 - _t118*_t136 - _t120*_t163 - _t134*_t66 - _t148*_t34 - _t149*_t254 - _t150*_t222 - _t151*_t42 - _t152*_t199 - _t152*_t28 - _t199*_t246 - _t20*_t247*_t248 - _t202*_t247*_t65 - _t227*_t254 - _t246*_t28 + 1.1739999999999999*_t264 - _t42*_t60 - _t71*_t87) + _hc4[2]*_t43 + _t135*_t58;
  out[65] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[66] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[67] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc4[0]*(_hc0[1]*_hc2[1]*_hc3[2]*_t10*_t182 + _hc0[1]*_hc2[1]*_hc3[3]*_t10*_t170*_t22 + _hc0[1]*_hc2[1]*_hc3[3]*_t10*_t22*_t65 + _hc0[1]*_hc2[1]*_hc3[4]*_t10*_t167 - _hc3[0]*_t275 + _hc3[1]*_t10*(_hc0[1]*_t265 + _hc0[17]*_hc2[4] + _hc0[17]*_t178 + _hc0[2]*_t266 + _hc0[2]*_t268 + _hc0[2]*(_hc0[1]*_t252 + _hc0[2]*(_hc0[1]*_t225 + _t226 + _t267) + _hc0[6]*_t179 + _t250 + _t268) + _hc0[38]*_hc2[1] + _hc0[6]*_hc2[8] + _hc0[6]*_t176 + _hc0[6]*_t180 + _hc0[7]*_t140 + _hc0[7]*_t253) + _hc3[2]*_t10*_t148*_t22 + _hc3[2]*_t10*_t170*_t48 + _hc3[2]*_t10*_t22*(0.2e1*_t137 + 0.2e1*_t138 + 0.2e1*_t139 + 0.2e1*_t141 + 0.2e1*_t143 + 0.2e1*_t144 + 0.2e1*_t147) + _hc3[2]*_t10*_t48*_t65 + _hc3[3]*_t10*_t59*(0.3e1*_t44 + 0.3e1*_t45 + 0.3e1*_t47) - _t116*_t136*_t171 - _t117*_t170 - _t117*_t65 - 0.3e1*_t148*_t49 - 0.3e1*_t149*_t71 - _t151*_t228 - 0.3e1*_t152*_t48 - _t163*_t183 - _t168*_t20 - _t171*_t248*_t32 - _t182*_t33 - _t191*_t90 - _t220*_t32*_t65 - _t228*_t60 + 1.1739999999999999*_t275) + _hc4[3]*_t21 + _t164*_t166 + _t165*_t57;
  out[68] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[69] = d4f_dx3_du;
  const double d4f_dx4 = _hc4[0]*(-_hc3[0]*_t287 + _t12*(_hc0[18]*_hc2[4] + 0.3e1*_hc0[18]*_t63 + ((_hc0[2]) * (_hc0[2]))*_hc2[12] + _hc0[2]*_t280 + _hc0[2]*(_hc0[2]*(_hc0[2]*(_hc2[11] + _t225) + _t252 + _t279) + _t179*_t278 + _t265 + _t280) + _hc0[39]*_hc2[1] + _hc0[7]*_hc2[8] + 0.3e1*_hc0[7]*_t180 + _hc2[14] + _t176*_t278) - _t151*_t281 - _t168*_t249 + 0.2e1*_t169*_t182 + _t169*(0.4e1*_hc0[7]*_t63 + 0.2e1*_hc2[9] + 0.2e1*_t172 + 0.2e1*_t173 + 0.2e1*_t174 + 0.2e1*_t177 + 0.2e1*_t181) + _t170*_t276 - _t170*_t277 + _t170*_t29*_t65 - 0.4e1*_t182*_t49 - 0.4e1*_t191*_t50 + _t197*(_t22 * _t22 * _t22 * _t22) + _t276*_t65 + _t276*(0.3e1*_hc2[5] + 0.3e1*_t61 + 0.3e1*_t62 + 0.3e1*_t64) - _t277*_t65 - _t281*_t60 + 1.1739999999999999*_t287 + _t29*(_t65 * _t65)) + 0.4e1*_hc4[1]*_t192 + 0.6e1*_hc4[2]*_t72 + 0.4e1*_hc4[3]*_t26 + _hc4[4]*_t11;
  out[70] = d4f_dx4;
  const double d4f_dz_dt3 = 0;
  out[71] = d4f_dz_dt3;
  const double d4f_dz_du_dt2 = 0;
  out[72] = d4f_dz_du_dt2;
  const double d4f_dz_du2_dt = 0;
  out[73] = d4f_dz_du2_dt;
  const double d4f_dz_du3 = 0;
  out[74] = d4f_dz_du3;
  const double d4f_dz_dx_dt2 = 0;
  out[75] = d4f_dz_dx_dt2;
  const double d4f_dz_dx_du_dt = 0;
  out[76] = d4f_dz_dx_du_dt;
  const double d4f_dz_dx_du2 = 0;
  out[77] = d4f_dz_dx_du2;
  const double d4f_dz_dx2_dt = 0;
  out[78] = d4f_dz_dx2_dt;
  const double d4f_dz_dx2_du = 0;
  out[79] = d4f_dz_dx2_du;
  const double d4f_dz_dx3 = 0;
  out[80] = d4f_dz_dx3;
  const double d4f_dz2_dt2 = 0;
  out[81] = d4f_dz2_dt2;
  const double d4f_dz2_du_dt = 0;
  out[82] = d4f_dz2_du_dt;
  const double d4f_dz2_du2 = 0;
  out[83] = d4f_dz2_du2;
  const double d4f_dz2_dx_dt = 0;
  out[84] = d4f_dz2_dx_dt;
  const double d4f_dz2_dx_du = 0;
  out[85] = d4f_dz2_dx_du;
  const double d4f_dz2_dx2 = 0;
  out[86] = d4f_dz2_dx2;
  const double d4f_dz3_dt = 0;
  out[87] = d4f_dz3_dt;
  const double d4f_dz3_du = 0;
  out[88] = d4f_dz3_du;
  const double d4f_dz3_dx = 0;
  out[89] = d4f_dz3_dx;
  const double d4f_dz4 = 0;
  out[90] = d4f_dz4;
  const double d4f_drs_dt3 = 0;
  out[91] = d4f_drs_dt3;
  const double d4f_drs_du_dt2 = 0;
  out[92] = d4f_drs_du_dt2;
  const double d4f_drs_du2_dt = 0;
  out[93] = d4f_drs_du2_dt;
  const double d4f_drs_du3 = 0;
  out[94] = d4f_drs_du3;
  const double d4f_drs_dx_dt2 = 0;
  out[95] = d4f_drs_dx_dt2;
  const double d4f_drs_dx_du_dt = 0;
  out[96] = d4f_drs_dx_du_dt;
  const double d4f_drs_dx_du2 = 0;
  out[97] = d4f_drs_dx_du2;
  const double d4f_drs_dx2_dt = 0;
  out[98] = d4f_drs_dx2_dt;
  const double d4f_drs_dx2_du = 0;
  out[99] = d4f_drs_dx2_du;
  const double d4f_drs_dx3 = 0;
  out[100] = d4f_drs_dx3;
  const double d4f_drs_dz_dt2 = 0;
  out[101] = d4f_drs_dz_dt2;
  const double d4f_drs_dz_du_dt = 0;
  out[102] = d4f_drs_dz_du_dt;
  const double d4f_drs_dz_du2 = 0;
  out[103] = d4f_drs_dz_du2;
  const double d4f_drs_dz_dx_dt = 0;
  out[104] = d4f_drs_dz_dx_dt;
  const double d4f_drs_dz_dx_du = 0;
  out[105] = d4f_drs_dz_dx_du;
  const double d4f_drs_dz_dx2 = 0;
  out[106] = d4f_drs_dz_dx2;
  const double d4f_drs_dz2_dt = 0;
  out[107] = d4f_drs_dz2_dt;
  const double d4f_drs_dz2_du = 0;
  out[108] = d4f_drs_dz2_du;
  const double d4f_drs_dz2_dx = 0;
  out[109] = d4f_drs_dz2_dx;
  const double d4f_drs_dz3 = 0;
  out[110] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = 0;
  out[111] = d4f_drs2_dt2;
  const double d4f_drs2_du_dt = 0;
  out[112] = d4f_drs2_du_dt;
  const double d4f_drs2_du2 = 0;
  out[113] = d4f_drs2_du2;
  const double d4f_drs2_dx_dt = 0;
  out[114] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx_du = 0;
  out[115] = d4f_drs2_dx_du;
  const double d4f_drs2_dx2 = 0;
  out[116] = d4f_drs2_dx2;
  const double d4f_drs2_dz_dt = 0;
  out[117] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz_du = 0;
  out[118] = d4f_drs2_dz_du;
  const double d4f_drs2_dz_dx = 0;
  out[119] = d4f_drs2_dz_dx;
  const double d4f_drs2_dz2 = 0;
  out[120] = d4f_drs2_dz2;
  const double d4f_drs3_dt = 0;
  out[121] = d4f_drs3_dt;
  const double d4f_drs3_du = 0;
  out[122] = d4f_drs3_du;
  const double d4f_drs3_dx = 0;
  out[123] = d4f_drs3_dx;
  const double d4f_drs3_dz = 0;
  out[124] = d4f_drs3_dz;
  const double d4f_drs4 = 0;
  out[125] = d4f_drs4;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_alpha_z0_k, _KMAX)(const xc_func_type *p, double rs, double x, double t, double *out) {
  const mgga_x_rppscan_params *params = (const mgga_x_rppscan_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(mgga_alpha_reg_k, _KMAX)(p, x, t, params->eta, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[2];
  out[1] = df_dt;
  const double df_dx = _hc0[3];
  out[2] = df_dx;
  const double df_drs = 0;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_dx_dt = _hc0[8];
  out[5] = d2f_dx_dt;
  const double d2f_dx2 = _hc0[9];
  out[6] = d2f_dx2;
  const double d2f_drs_dt = 0;
  out[7] = d2f_drs_dt;
  const double d2f_drs_dx = 0;
  out[8] = d2f_drs_dx;
  const double d2f_drs2 = 0;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_dx_dt2 = 0;
  out[11] = d3f_dx_dt2;
  const double d3f_dx2_dt = _hc0[18];
  out[12] = d3f_dx2_dt;
  const double d3f_dx3 = _hc0[19];
  out[13] = d3f_dx3;
  const double d3f_drs_dt2 = 0;
  out[14] = d3f_drs_dt2;
  const double d3f_drs_dx_dt = 0;
  out[15] = d3f_drs_dx_dt;
  const double d3f_drs_dx2 = 0;
  out[16] = d3f_drs_dx2;
  const double d3f_drs2_dt = 0;
  out[17] = d3f_drs2_dt;
  const double d3f_drs2_dx = 0;
  out[18] = d3f_drs2_dx;
  const double d3f_drs3 = 0;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[20] = d4f_dt4;
  const double d4f_dx_dt3 = 0;
  out[21] = d4f_dx_dt3;
  const double d4f_dx2_dt2 = 0;
  out[22] = d4f_dx2_dt2;
  const double d4f_dx3_dt = _hc0[33];
  out[23] = d4f_dx3_dt;
  const double d4f_dx4 = _hc0[34];
  out[24] = d4f_dx4;
  const double d4f_drs_dt3 = 0;
  out[25] = d4f_drs_dt3;
  const double d4f_drs_dx_dt2 = 0;
  out[26] = d4f_drs_dx_dt2;
  const double d4f_drs_dx2_dt = 0;
  out[27] = d4f_drs_dx2_dt;
  const double d4f_drs_dx3 = 0;
  out[28] = d4f_drs_dx3;
  const double d4f_drs2_dt2 = 0;
  out[29] = d4f_drs2_dt2;
  const double d4f_drs2_dx_dt = 0;
  out[30] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx2 = 0;
  out[31] = d4f_drs2_dx2;
  const double d4f_drs3_dt = 0;
  out[32] = d4f_drs3_dt;
  const double d4f_drs3_dx = 0;
  out[33] = d4f_drs3_dx;
  const double d4f_drs4 = 0;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_f_z0_k, _KMAX)(const xc_func_type *p, double rs, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(rscan_alpha_z0_k, _KMAX)(p, 0, x, t, _hc0);
  const double _t1 = 1.0*_hc0[0] - 2.5;
  const double _t2 = _t1 > 0;
  const double _t3 = _t1 <= 0;
  const double _t4 = my_piecewise3(_t2, 2.5, _hc0[0]);
  const double _t5 = (_t4 * _t4);
  const double _t6 = (_t4 * _t4 * _t4);
  const double _t7 = (_t4 * _t4 * _t4 * _t4);
  const double _t8 = xc_powi(_t4, 5);
  const double _t9 = xc_powi(_t4, 6);
#if _KMAX >= 1
  const double _t15 = my_piecewise3(_t2, 0, _hc0[1]);
  const double _t16 = 0.88911099999999998*_t4;
  const double _t17 = 1.9892598031469999*_t5;
  const double _t18 = 4.4399902079849998*_t7;
  const double _t19 = 0.16230090325400001*_t9;
  const double _t20 = my_piecewise3(_t2, _hc0[1], 0);
  const double _t24 = my_piecewise3(_t2, 0, _hc0[2]);
  const double _t25 = my_piecewise3(_t2, _hc0[2], 0);
#endif
#if _KMAX >= 2
  const double _t28 = ((_hc0[1]) * (_hc0[1]));
  const double _t36 = my_piecewise3(_t2, 0, _hc0[4]);
  const double _t37 = (_t15 * _t15);
  const double _t38 = 3.9785196062939998*_t4;
  const double _t39 = 17.759960831939999*_t6;
  const double _t40 = 0.97380541952400002*_t8;
  const double _t41 = my_piecewise3(_t2, _hc0[4], 0);
  const double _t42 = (_t20 * _t20);
  const double _t52 = my_piecewise3(_t2, 0, _hc0[5]);
  const double _t53 = 0.88911099999999998*_t24;
  const double _t54 = _t15*_t24;
  const double _t55 = my_piecewise3(_t2, _hc0[5], 0);
  const double _t68 = my_piecewise3(_t2, 0, _hc0[6]);
  const double _t69 = (_t24 * _t24);
  const double _t70 = my_piecewise3(_t2, _hc0[6], 0);
  const double _t71 = (_t25 * _t25);
#endif
#if _KMAX >= 3
  const double _t74 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t77 = 0.3e1*_hc0[1];
  const double _t78 = _hc0[4]*_t77;
  const double _t85 = 0.3e1*_hc0[4];
  const double _t92 = my_piecewise3(_t2, 0, _hc0[10]);
  const double _t93 = (_t15 * _t15 * _t15);
  const double _t94 = 2.6673330000000002*_t15;
  const double _t95 = 53.279882495819997*_t5;
  const double _t96 = 4.8690270976200001*_t7;
  const double _t97 = 11.935558818881999*_t4;
  const double _t98 = _t15*_t36;
  const double _t99 = 53.279882495819997*_t6;
  const double _t100 = 2.921416258572*_t8;
  const double _t101 = my_piecewise3(_t2, _hc0[10], 0);
  const double _t102 = (_t20 * _t20 * _t20);
  const double _t112 = 0.2e1*_hc0[1];
  const double _t122 = my_piecewise3(_t2, 0, _hc0[11]);
  const double _t123 = 1.778222*_t52;
  const double _t124 = 3.9785196062939998*_t37;
  const double _t125 = 7.9570392125879996*_t4;
  const double _t126 = _t15*_t52;
  const double _t127 = _t24*_t36;
  const double _t128 = 35.519921663879998*_t6;
  const double _t129 = 1.947610839048*_t8;
  const double _t130 = _t24*_t37;
  const double _t131 = my_piecewise3(_t2, _hc0[11], 0);
  const double _t154 = my_piecewise3(_t2, 0, _hc0[12]);
  const double _t155 = 0.88911099999999998*_t68;
  const double _t156 = 3.9785196062939998*_t69;
  const double _t157 = _t15*_t68;
  const double _t158 = _t24*_t52;
  const double _t159 = _t15*_t69;
  const double _t160 = my_piecewise3(_t2, _hc0[12], 0);
  const double _t185 = my_piecewise3(_t2, 0, _hc0[13]);
  const double _t186 = (_t24 * _t24 * _t24);
  const double _t187 = 2.6673330000000002*_t24;
  const double _t188 = _t24*_t68;
  const double _t189 = my_piecewise3(_t2, _hc0[13], 0);
  const double _t190 = (_t25 * _t25 * _t25);
#endif
#if _KMAX >= 4
  const double _t194 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t195 = 0.4e1*_hc0[1];
  const double _t196 = _hc0[10]*_t195;
  const double _t197 = 0.3e1*((_hc0[4]) * (_hc0[4]));
  const double _t199 = 0.6e1*_hc0[4]*_t28;
  const double _t201 = _hc0[1]*_hc0[4];
  const double _t202 = 0.12e2*_t201;
  const double _t207 = my_piecewise3(_t2, 0, _hc0[20]);
  const double _t208 = (_t15 * _t15 * _t15 * _t15);
  const double _t209 = (_t36 * _t36);
  const double _t210 = _t15*_t92;
  const double _t211 = 106.55976499163999*_t4;
  const double _t212 = _t36*_t37;
  const double _t213 = 19.47610839048*_t6;
  const double _t214 = 15.914078425175999*_t4;
  const double _t215 = 71.039843327759996*_t6;
  const double _t216 = 3.8952216780960001*_t8;
  const double _t217 = 319.67929497491997*_t5;
  const double _t218 = 29.21416258572*_t7;
  const double _t230 = my_piecewise3(_t2, 0, _hc0[21]);
  const double _t231 = 2.6673330000000002*_t52;
  const double _t232 = 11.935558818881999*_t52;
  const double _t233 = _t122*_t15;
  const double _t234 = _t24*_t92;
  const double _t235 = _t36*_t52;
  const double _t236 = 11.935558818881999*_t54;
  const double _t237 = _t24*_t93;
  const double _t238 = _t5*_t52;
  const double _t239 = 159.83964748745998*_t238;
  const double _t240 = 14.60708129286*_t7;
  const double _t241 = _t36*_t54;
  const double _t242 = 159.83964748745998*_t5;
  const double _t243 = 0.3e1*_t55;
  const double _t256 = my_piecewise3(_t2, 0, _hc0[22]);
  const double _t257 = (_t52 * _t52);
  const double _t258 = _t15*_t154;
  const double _t259 = _t122*_t24;
  const double _t260 = _t36*_t68;
  const double _t261 = _t52*_t54;
  const double _t262 = _t37*_t69;
  const double _t263 = _t37*_t68;
  const double _t264 = _t36*_t69;
  const double _t270 = my_piecewise3(_t2, 0, _hc0[23]);
  const double _t271 = _t15*_t185;
  const double _t272 = _t154*_t24;
  const double _t273 = _t52*_t68;
  const double _t274 = _t15*_t186;
  const double _t275 = _t54*_t68;
  const double _t279 = 0.2e1*_hc0[6];
  const double _t283 = my_piecewise3(_t2, 0, _hc0[24]);
  const double _t284 = (_t24 * _t24 * _t24 * _t24);
  const double _t285 = (_t68 * _t68);
  const double _t286 = _t185*_t24;
  const double _t287 = _t68*_t69;
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(rscan_f_alpha_large_k, _KMAX)(p, my_piecewise3(_t2, _hc0[0], 2.5), _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(scan_y_k, _KMAX)(p, x, _hc0[0], _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_h1x_k, _KMAX)(p, _hc2[0], _hc3);
  double _hc4[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_gx_k, _KMAX)(p, x, _hc4);
  const double _t10 = my_piecewise3(_t3, -0.023185843322000001*xc_powi(_t4, 7) - 0.66700000000000004*_t4 - 0.44455549999999999*_t5 - 0.66308660104899997*_t6 + 1.45129704449*_t7 - 0.88799804159700002*_t8 + 0.234528941479*_t9 + 0.1e1, _hc1[0]);
  const double _t11 = 0.1e1 - _t10;
  const double _t12 = _hc3[0]*_t11 + 1.1739999999999999*_t10;
#if _KMAX >= 1
  const double _t13 = _hc3[1]*_t11;
  const double _t14 = _hc2[1]*_t13;
  const double _t21 = my_piecewise3(_t3, -_t15*_t16 - _t15*_t17 - _t15*_t18 - _t15*_t19 + 5.8051881779599999*_t15*_t6 + 1.4071736488740001*_t15*_t8 - 0.66700000000000004*_t15, _hc1[1]*_t20);
  const double _t22 = _hc0[1]*_t14 - _hc3[0]*_t21 + 1.1739999999999999*_t21;
  const double _t23 = _hc0[2]*_hc2[1] + _hc2[2];
  const double _t26 = my_piecewise3(_t3, -_t16*_t24 - _t17*_t24 - _t18*_t24 - _t19*_t24 + 5.8051881779599999*_t24*_t6 + 1.4071736488740001*_t24*_t8 - 0.66700000000000004*_t24, _hc1[1]*_t25);
  const double _t27 = -_hc3[0]*_t26 + _t13*_t23 + 1.1739999999999999*_t26;
#endif
#if _KMAX >= 2
  const double _t29 = _hc2[3]*_t28;
  const double _t30 = _hc3[2]*_t11;
  const double _t31 = ((_hc2[1]) * (_hc2[1]));
  const double _t32 = _t28*_t31;
  const double _t33 = _hc0[1]*_hc2[1];
  const double _t34 = _hc3[1]*_t21;
  const double _t35 = 0.2e1*_t34;
  const double _t43 = my_piecewise3(_t3, -_t16*_t36 - _t17*_t36 - _t18*_t36 - _t19*_t36 + 5.8051881779599999*_t36*_t6 + 1.4071736488740001*_t36*_t8 - 0.66700000000000004*_t36 - _t37*_t38 - _t37*_t39 - _t37*_t40 + 17.415564533880001*_t37*_t5 + 7.0358682443700005*_t37*_t7 - 0.88911099999999998*_t37, _hc1[1]*_t41 + _hc1[2]*_t42);
  const double _t44 = _hc0[4]*_t14 - _hc3[0]*_t43 + _t13*_t29 + _t30*_t32 - _t33*_t35 + 1.1739999999999999*_t43;
  const double _t45 = _hc0[1]*_hc2[4];
  const double _t46 = _hc0[5]*_hc2[1];
  const double _t47 = _hc0[2]*_hc2[3];
  const double _t48 = _hc0[1]*_t47;
  const double _t49 = _t45 + _t46 + _t48;
  const double _t50 = _hc3[1]*_t26;
  const double _t51 = _hc3[1]*_t23;
  const double _t56 = _hc1[2]*_t25;
  const double _t57 = my_piecewise3(_t3, 17.415564533880001*_t15*_t24*_t5 + 7.0358682443700005*_t15*_t24*_t7 - _t15*_t53 - _t16*_t52 - _t17*_t52 - _t18*_t52 - _t19*_t52 - _t38*_t54 - _t39*_t54 - _t40*_t54 + 5.8051881779599999*_t52*_t6 + 1.4071736488740001*_t52*_t8 - 0.66700000000000004*_t52, _hc1[1]*_t55 + _t20*_t56);
  const double _t58 = _hc0[1]*_hc2[1]*_hc3[2]*_t11*_t23 - _hc3[0]*_t57 + _hc3[1]*_t11*_t49 - _t21*_t51 - _t33*_t50 + 1.1739999999999999*_t57;
  const double _t59 = 0.2e1*_hc4[1];
  const double _t60 = (_t23 * _t23);
  const double _t61 = _hc3[2]*_t60;
  const double _t62 = _hc0[2]*_hc2[4];
  const double _t63 = _hc0[6]*_hc2[1];
  const double _t64 = _hc2[4] + _t47;
  const double _t65 = _hc0[2]*_t64;
  const double _t66 = _hc2[5] + _t62 + _t63 + _t65;
  const double _t67 = 0.2e1*_t51;
  const double _t72 = my_piecewise3(_t3, -_t16*_t68 - _t17*_t68 - _t18*_t68 - _t19*_t68 - _t38*_t69 - _t39*_t69 - _t40*_t69 + 17.415564533880001*_t5*_t69 + 5.8051881779599999*_t6*_t68 + 1.4071736488740001*_t68*_t8 - 0.66700000000000004*_t68 + 7.0358682443700005*_t69*_t7 - 0.88911099999999998*_t69, _hc1[1]*_t70 + _hc1[2]*_t71);
  const double _t73 = -_hc3[0]*_t72 + _t11*_t61 + _t13*_t66 - _t26*_t67 + 1.1739999999999999*_t72;
#endif
#if _KMAX >= 3
  const double _t75 = _hc2[6]*_t74;
  const double _t76 = _hc2[3]*_t13;
  const double _t79 = _hc3[3]*_t11;
  const double _t80 = ((_hc2[1]) * (_hc2[1]) * (_hc2[1]));
  const double _t81 = _t74*_t80;
  const double _t82 = _t30*_t31;
  const double _t83 = 0.3e1*_t30;
  const double _t84 = _hc2[1]*_hc2[3]*_t74;
  const double _t86 = _hc2[1]*_t34;
  const double _t87 = 0.3e1*_t34;
  const double _t88 = _hc3[2]*_t32;
  const double _t89 = 0.3e1*_t21;
  const double _t90 = 0.3e1*_t43;
  const double _t91 = _hc3[1]*_t33;
  const double _t103 = 0.3e1*_hc1[2];
  const double _t104 = _t103*_t20;
  const double _t105 = my_piecewise3(_t3, -_t100*_t98 + 52.246693601640004*_t15*_t36*_t5 + 21.107604733110001*_t15*_t36*_t7 - _t16*_t92 - _t17*_t92 - _t18*_t92 - _t19*_t92 - _t36*_t94 + 34.831129067760003*_t4*_t93 + 5.8051881779599999*_t6*_t92 + 28.143472977480002*_t6*_t93 + 1.4071736488740001*_t8*_t92 - 0.66700000000000004*_t92 - _t93*_t95 - _t93*_t96 - 3.9785196062939998*_t93 - _t97*_t98 - _t98*_t99, _hc1[1]*_t101 + _hc1[3]*_t102 + _t104*_t41);
  const double _t106 = _hc0[10]*_t14 - _hc3[0]*_t105 + 1.1739999999999999*_t105 + _t13*_t75 - _t29*_t87 + _t76*_t78 + _t78*_t82 + _t79*_t81 + _t83*_t84 - _t85*_t86 - _t88*_t89 - _t90*_t91;
  const double _t107 = _hc0[11]*_hc2[1];
  const double _t108 = _hc0[4]*_hc2[4];
  const double _t109 = _hc0[4]*_t47;
  const double _t110 = _hc2[7]*_t28;
  const double _t111 = _hc0[5]*_hc2[3];
  const double _t113 = _hc0[2]*_hc2[6];
  const double _t114 = _t113*_t28;
  const double _t115 = _t107 + _t108 + _t109 + _t110 + _t111*_t112 + _t114;
  const double _t116 = _hc2[1]*_t50;
  const double _t117 = _hc3[2]*_t23;
  const double _t118 = _t117*_t21;
  const double _t119 = 0.2e1*_t118;
  const double _t120 = 0.2e1*_t49;
  const double _t121 = 0.2e1*_t91;
  const double _t132 = 0.2e1*_hc1[2];
  const double _t133 = _t132*_t20;
  const double _t134 = _hc1[3]*_t42;
  const double _t135 = my_piecewise3(_t3, -_t122*_t16 - _t122*_t17 - _t122*_t18 - _t122*_t19 + 5.8051881779599999*_t122*_t6 + 1.4071736488740001*_t122*_t8 - 0.66700000000000004*_t122 - _t123*_t15 - _t124*_t24 - _t125*_t126 - _t126*_t128 - _t126*_t129 - _t127*_t38 - _t127*_t39 - _t127*_t40 - _t130*_t95 - _t130*_t96 + 34.831129067760003*_t15*_t5*_t52 + 14.071736488740001*_t15*_t52*_t7 + 17.415564533880001*_t24*_t36*_t5 + 7.0358682443700005*_t24*_t36*_t7 + 34.831129067760003*_t24*_t37*_t4 + 28.143472977480002*_t24*_t37*_t6 - _t36*_t53, _hc1[1]*_t131 + _t133*_t55 + _t134*_t25 + _t41*_t56);
  const double _t136 = 0.2e1*_hc0[1]*_hc2[1]*_hc3[2]*_t11*_t49 + _hc0[4]*_hc2[1]*_hc3[2]*_t11*_t23 - _hc0[4]*_t116 + _hc2[3]*_hc3[2]*_t11*_t23*_t28 - _hc3[0]*_t135 + _hc3[1]*_t11*_t115 + _hc3[3]*_t11*_t23*_t28*_t31 - _t119*_t33 - _t120*_t34 - _t121*_t57 + 1.1739999999999999*_t135 - _t26*_t88 - _t29*_t50 - _t43*_t51;
  const double _t137 = 0.2e1*_t45 + 0.2e1*_t46 + 0.2e1*_t48;
  const double _t138 = _hc0[1]*_hc2[8];
  const double _t139 = _hc0[12]*_hc2[1];
  const double _t140 = _hc0[5]*_hc2[4];
  const double _t141 = _hc0[1]*_hc2[7];
  const double _t142 = _hc0[2]*_t141;
  const double _t143 = _hc0[6]*_hc2[3];
  const double _t144 = _hc0[1]*_t143;
  const double _t145 = _hc0[5]*_t64;
  const double _t146 = _hc0[1]*_t113;
  const double _t147 = _t111 + _t141 + _t146;
  const double _t148 = _hc0[2]*_t147;
  const double _t149 = _t138 + _t139 + _t140 + _t142 + _t144 + _t145 + _t148;
  const double _t150 = _t117*_t33;
  const double _t151 = 0.2e1*_t26;
  const double _t152 = _hc3[1]*_t66;
  const double _t153 = _hc3[1]*_t72;
  const double _t161 = _hc1[2]*_t70;
  const double _t162 = 0.2e1*_t56;
  const double _t163 = _hc1[3]*_t71;
  const double _t164 = my_piecewise3(_t3, -_t123*_t24 - _t125*_t158 - _t128*_t158 - _t129*_t158 - _t15*_t155 - _t15*_t156 + 34.831129067760003*_t15*_t4*_t69 + 17.415564533880001*_t15*_t5*_t68 + 28.143472977480002*_t15*_t6*_t69 + 7.0358682443700005*_t15*_t68*_t7 - _t154*_t16 - _t154*_t17 - _t154*_t18 - _t154*_t19 + 5.8051881779599999*_t154*_t6 + 1.4071736488740001*_t154*_t8 - 0.66700000000000004*_t154 - _t157*_t38 - _t157*_t39 - _t157*_t40 - _t159*_t95 - _t159*_t96 + 34.831129067760003*_t24*_t5*_t52 + 14.071736488740001*_t24*_t52*_t7, _hc1[1]*_t160 + _t161*_t20 + _t162*_t55 + _t163*_t20);
  const double _t165 = _hc0[1]*_hc2[1]*_hc3[2]*_t11*_t66 + _hc0[1]*_hc2[1]*_hc3[3]*_t11*_t60 - _hc3[0]*_t164 + _hc3[1]*_t11*_t149 + _hc3[2]*_t11*_t137*_t23 - _t120*_t50 - _t150*_t151 - _t152*_t21 - _t153*_t33 + 1.1739999999999999*_t164 - _t21*_t61 - _t57*_t67;
  const double _t166 = 0.3e1*_hc4[2];
  const double _t167 = 0.3e1*_hc4[1];
  const double _t168 = (_t23 * _t23 * _t23);
  const double _t169 = _hc3[3]*_t168;
  const double _t170 = _t23*_t30;
  const double _t171 = 0.2e1*_hc2[5] + 0.2e1*_t62 + 0.2e1*_t63 + 0.2e1*_t65;
  const double _t172 = _hc0[13]*_hc2[1];
  const double _t173 = _hc0[2]*_hc2[8];
  const double _t174 = _hc0[6]*_hc2[4];
  const double _t175 = _hc0[2]*_hc2[7];
  const double _t176 = _hc2[8] + _t175;
  const double _t177 = _hc0[2]*_t176;
  const double _t178 = 0.2e1*_t64;
  const double _t179 = _hc2[7] + _t113;
  const double _t180 = _hc0[2]*_t179 + _t143 + _t176;
  const double _t181 = _hc0[2]*_t180;
  const double _t182 = _hc0[6]*_t178 + _hc2[9] + _t172 + _t173 + _t174 + _t177 + _t181;
  const double _t183 = 0.3e1*_t26;
  const double _t184 = 0.3e1*_t51;
  const double _t191 = 0.3e1*_t56;
  const double _t192 = my_piecewise3(_t3, -_t100*_t188 - _t16*_t185 - _t17*_t185 - _t18*_t185 - _t185*_t19 + 5.8051881779599999*_t185*_t6 + 1.4071736488740001*_t185*_t8 - 0.66700000000000004*_t185 + 34.831129067760003*_t186*_t4 + 28.143472977480002*_t186*_t6 - _t186*_t95 - _t186*_t96 - 3.9785196062939998*_t186 - _t187*_t68 - _t188*_t97 - _t188*_t99 + 52.246693601640004*_t24*_t5*_t68 + 21.107604733110001*_t24*_t68*_t7, _hc1[1]*_t189 + _hc1[3]*_t190 + _t191*_t70);
  const double _t193 = -_hc3[0]*_t192 + _t11*_t169 + _t13*_t182 - _t152*_t183 + _t170*_t171 + _t170*_t66 - _t183*_t61 - _t184*_t72 + 1.1739999999999999*_t192;
#endif
#if _KMAX >= 4
  const double _t198 = _hc3[4]*_t11;
  const double _t200 = _hc0[4]*_hc2[1];
  const double _t203 = _hc3[2]*_t21;
  const double _t204 = _hc3[3]*_t81;
  const double _t205 = 0.6e1*_t43;
  const double _t206 = _hc3[1]*_t205;
  const double _t219 = _hc1[2]*_t20;
  const double _t220 = my_piecewise3(_t3, -_t100*_t209 + 69.662258135520005*_t15*_t5*_t92 + 28.143472977480002*_t15*_t7*_t92 - _t16*_t207 - _t17*_t207 - _t18*_t207 - _t19*_t207 + 5.8051881779599999*_t207*_t6 + 1.4071736488740001*_t207*_t8 - 0.66700000000000004*_t207 - _t208*_t211 - _t208*_t213 + 84.430418932440006*_t208*_t5 + 34.831129067760003*_t208 + 52.246693601640004*_t209*_t5 + 21.107604733110001*_t209*_t7 - _t209*_t97 - _t209*_t99 - 2.6673330000000002*_t209 - _t210*_t214 - _t210*_t215 - _t210*_t216 - 3.5564439999999999*_t210 - _t212*_t217 - _t212*_t218 - 23.871117637763998*_t212 + 208.98677440656002*_t36*_t37*_t4 + 168.86083786488001*_t36*_t37*_t6, _hc1[1]*my_piecewise3(_t2, _hc0[20], 0) + _hc1[4]*(_t20 * _t20 * _t20 * _t20) + 0.4e1*_t101*_t219 + _t103*(_t41 * _t41) + 0.6e1*_t134*_t41);
  const double _t221 = _hc0[11]*_hc2[3];
  const double _t222 = _hc0[2]*_hc2[10];
  const double _t223 = _hc0[5]*_hc2[6];
  const double _t224 = _hc3[2]*_t183;
  const double _t225 = _hc2[1]*_t85;
  const double _t226 = _hc3[3]*_t23*_t32;
  const double _t227 = _t33*_t49;
  const double _t228 = _hc3[1]*_t49;
  const double _t229 = 0.3e1*_t57;
  const double _t244 = _hc1[3]*_t20*_t25;
  const double _t245 = 0.3e1*_t244;
  const double _t246 = my_piecewise3(_t3, -_t100*_t233 - _t100*_t235 + 52.246693601640004*_t122*_t15*_t5 + 21.107604733110001*_t122*_t15*_t7 - _t122*_t94 + 104.49338720328001*_t15*_t24*_t36*_t4 + 84.430418932440006*_t15*_t24*_t36*_t6 - _t16*_t230 - _t17*_t230 - _t18*_t230 - _t19*_t230 - _t211*_t237 - _t213*_t237 + 5.8051881779599999*_t230*_t6 + 1.4071736488740001*_t230*_t8 - 0.66700000000000004*_t230 - _t231*_t36 - _t232*_t37 - _t233*_t97 - _t233*_t99 - _t234*_t38 - _t234*_t39 - _t234*_t40 - _t235*_t97 - _t235*_t99 - _t236*_t36 - _t239*_t37 + 17.415564533880001*_t24*_t5*_t92 + 84.430418932440006*_t24*_t5*_t93 + 7.0358682443700005*_t24*_t7*_t92 + 34.831129067760003*_t24*_t93 - _t240*_t241 - _t240*_t37*_t52 - _t241*_t242 + 52.246693601640004*_t36*_t5*_t52 + 21.107604733110001*_t36*_t52*_t7 + 104.49338720328001*_t37*_t4*_t52 + 84.430418932440006*_t37*_t52*_t6 - _t53*_t92, _hc1[1]*my_piecewise3(_t2, _hc0[21], 0) + _hc1[4]*_t102*_t25 + _t101*_t56 + _t103*_t41*_t55 + _t104*_t131 + _t134*_t243 + _t245*_t41);
  const double _t247 = _t117*_t151;
  const double _t248 = 0.2e1*_t33;
  const double _t249 = _hc3[3]*_t60;
  const double _t250 = 0.4e1*_t26;
  const double _t251 = _hc0[12]*_hc2[3];
  const double _t252 = _hc2[11]*_t28;
  const double _t253 = _hc0[6]*_hc2[6];
  const double _t254 = 0.2e1*_t147;
  const double _t255 = 0.4e1*_t57;
  const double _t265 = my_piecewise3(_t3, 34.831129067760003*_t122*_t24*_t5 + 14.071736488740001*_t122*_t24*_t7 - _t124*_t68 - _t125*_t257 - _t125*_t258 - _t125*_t259 - _t128*_t257 - _t128*_t258 - _t128*_t259 - _t129*_t257 - _t129*_t258 - _t129*_t259 + 34.831129067760003*_t15*_t154*_t5 + 14.071736488740001*_t15*_t154*_t7 + 139.32451627104001*_t15*_t24*_t4*_t52 + 112.57389190992001*_t15*_t24*_t52*_t6 - _t155*_t36 - _t156*_t36 - _t16*_t256 - _t17*_t256 - _t18*_t256 - _t19*_t256 - _t211*_t262 - _t213*_t262 - 213.11952998327999*_t238*_t54 + 5.8051881779599999*_t256*_t6 + 1.4071736488740001*_t256*_t8 - 0.66700000000000004*_t256 + 34.831129067760003*_t257*_t5 + 14.071736488740001*_t257*_t7 - 1.778222*_t257 - 1.778222*_t258 - 1.778222*_t259 - _t260*_t38 - _t260*_t39 - _t260*_t40 - 19.47610839048*_t261*_t7 - 15.914078425175999*_t261 - _t263*_t95 - _t263*_t96 - _t264*_t95 - _t264*_t96 + 34.831129067760003*_t36*_t4*_t69 + 17.415564533880001*_t36*_t5*_t68 + 28.143472977480002*_t36*_t6*_t69 + 7.0358682443700005*_t36*_t68*_t7 + 34.831129067760003*_t37*_t4*_t68 + 84.430418932440006*_t37*_t5*_t69 + 28.143472977480002*_t37*_t6*_t68 + 34.831129067760003*_t37*_t69, _hc1[1]*my_piecewise3(_t2, _hc0[22], 0) + _hc1[4]*_t42*_t71 + _t131*_t162 + _t132*(_t55 * _t55) + _t133*_t160 + _t134*_t70 + _t161*_t41 + _t163*_t41 + 0.4e1*_t244*_t55);
  const double _t266 = _hc0[13]*_hc2[3];
  const double _t267 = _hc0[1]*_hc2[12];
  const double _t268 = _hc0[1]*_hc2[11];
  const double _t269 = _hc0[2]*_t268 + _hc0[5]*_hc2[7] + _t267;
  const double _t276 = my_piecewise3(_t3, -_t100*_t272 - _t100*_t273 + 17.415564533880001*_t15*_t185*_t5 + 7.0358682443700005*_t15*_t185*_t7 + 84.430418932440006*_t15*_t186*_t5 + 34.831129067760003*_t15*_t186 + 104.49338720328001*_t15*_t24*_t4*_t68 + 84.430418932440006*_t15*_t24*_t6*_t68 - _t154*_t187 + 52.246693601640004*_t154*_t24*_t5 + 21.107604733110001*_t154*_t24*_t7 - _t16*_t270 - _t17*_t270 - _t18*_t270 - _t19*_t270 - _t211*_t274 - _t213*_t274 - _t231*_t68 - _t232*_t69 - _t236*_t68 - _t239*_t69 - _t240*_t275 - _t240*_t52*_t69 - _t242*_t275 + 5.8051881779599999*_t270*_t6 + 1.4071736488740001*_t270*_t8 - 0.66700000000000004*_t270 - _t271*_t38 - _t271*_t39 - _t271*_t40 - 0.88911099999999998*_t271 - _t272*_t97 - _t272*_t99 - _t273*_t97 - _t273*_t99 + 104.49338720328001*_t4*_t52*_t69 + 52.246693601640004*_t5*_t52*_t68 + 84.430418932440006*_t52*_t6*_t69 + 21.107604733110001*_t52*_t68*_t7, _hc1[1]*my_piecewise3(_t2, _hc0[23], 0) + _hc1[4]*_t190*_t20 + _t160*_t191 + _t161*_t243 + _t163*_t243 + _t189*_t219 + _t245*_t70);
  const double _t277 = _t60*_t79;
  const double _t278 = _t117*_t250;
  const double _t280 = _hc0[2]*_hc2[11] + _hc2[12];
  const double _t281 = _hc0[2]*_hc2[12] + _hc0[2]*_t280 + _hc0[6]*_hc2[7];
  const double _t282 = 0.6e1*_t72;
  const double _t288 = my_piecewise3(_t3, -_t100*_t285 - _t16*_t283 - _t17*_t283 - _t18*_t283 + 69.662258135520005*_t185*_t24*_t5 + 28.143472977480002*_t185*_t24*_t7 - _t19*_t283 - _t211*_t284 - _t213*_t284 - _t214*_t286 - _t215*_t286 - _t216*_t286 - _t217*_t287 - _t218*_t287 + 5.8051881779599999*_t283*_t6 + 1.4071736488740001*_t283*_t8 - 0.66700000000000004*_t283 + 84.430418932440006*_t284*_t5 + 34.831129067760003*_t284 + 52.246693601640004*_t285*_t5 + 21.107604733110001*_t285*_t7 - _t285*_t97 - _t285*_t99 - 2.6673330000000002*_t285 - 3.5564439999999999*_t286 - 23.871117637763998*_t287 + 208.98677440656002*_t4*_t68*_t69 + 168.86083786488001*_t6*_t68*_t69, _hc1[1]*my_piecewise3(_t2, _hc0[24], 0) + _hc1[4]*(_t25 * _t25 * _t25 * _t25) + _t103*(_t70 * _t70) + 0.6e1*_t163*_t70 + 0.4e1*_t189*_t56);
#endif

  const double f = _hc4[0]*_t12;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc4[0]*_t22;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc4[0]*_t27 + _hc4[1]*_t12;
  out[3] = df_dx;
  const double df_drs = 0;
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc4[0]*_t44;
  out[5] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[6] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[7] = d2f_du2;
  const double d2f_dx_dt = _hc4[0]*_t58 + _hc4[1]*_t22;
  out[8] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[9] = d2f_dx_du;
  const double d2f_dx2 = _hc4[0]*_t73 + _hc4[2]*_t12 + _t27*_t59;
  out[10] = d2f_dx2;
  const double d2f_drs_dt = 0;
  out[11] = d2f_drs_dt;
  const double d2f_drs_du = 0;
  out[12] = d2f_drs_du;
  const double d2f_drs_dx = 0;
  out[13] = d2f_drs_dx;
  const double d2f_drs2 = 0;
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc4[0]*_t106;
  out[15] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[16] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[17] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[18] = d3f_du3;
  const double d3f_dx_dt2 = _hc4[0]*_t136 + _hc4[1]*_t44;
  out[19] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[20] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[21] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc4[0]*_t165 + _hc4[2]*_t22 + _t58*_t59;
  out[22] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[23] = d3f_dx2_du;
  const double d3f_dx3 = _hc4[0]*_t193 + _hc4[3]*_t12 + _t166*_t27 + _t167*_t73;
  out[24] = d3f_dx3;
  const double d3f_drs_dt2 = 0;
  out[25] = d3f_drs_dt2;
  const double d3f_drs_du_dt = 0;
  out[26] = d3f_drs_du_dt;
  const double d3f_drs_du2 = 0;
  out[27] = d3f_drs_du2;
  const double d3f_drs_dx_dt = 0;
  out[28] = d3f_drs_dx_dt;
  const double d3f_drs_dx_du = 0;
  out[29] = d3f_drs_dx_du;
  const double d3f_drs_dx2 = 0;
  out[30] = d3f_drs_dx2;
  const double d3f_drs2_dt = 0;
  out[31] = d3f_drs2_dt;
  const double d3f_drs2_du = 0;
  out[32] = d3f_drs2_du;
  const double d3f_drs2_dx = 0;
  out[33] = d3f_drs2_dx;
  const double d3f_drs3 = 0;
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc4[0]*(-0.4e1*_hc0[10]*_t86 + _hc0[20]*_t14 + ((_hc2[1]) * (_hc2[1]) * (_hc2[1]) * (_hc2[1]))*_t194*_t198 + 0.4e1*_hc2[1]*_hc2[6]*_t194*_t30 + _hc2[10]*_t13*_t194 + ((_hc2[3]) * (_hc2[3]))*_t194*_t83 + 0.6e1*_hc2[3]*_t194*_t31*_t79 - _hc2[3]*_t202*_t34 + _hc2[6]*_t13*_t199 - _hc3[0]*_t220 - 0.4e1*_t105*_t91 + _t196*_t76 + _t196*_t82 + _t197*_t76 + _t197*_t82 + _t199*_t79*_t80 - _t200*_t206 + 0.18e2*_t200*_t29*_t30 - _t202*_t203*_t31 - 0.12e2*_t203*_t84 - 0.4e1*_t204*_t21 - _t205*_t88 - _t206*_t29 + 1.1739999999999999*_t220 - 0.4e1*_t34*_t75);
  out[35] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[36] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[37] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[38] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[39] = d4f_du4;
  const double d4f_dx_dt3 = _hc4[0]*(0.3e1*_hc0[1]*_hc0[4]*_hc2[3]*_hc3[2]*_t11*_t23 + 0.3e1*_hc0[1]*_hc0[4]*_hc3[3]*_t11*_t23*_t31 + 0.3e1*_hc0[1]*_hc2[1]*_hc3[2]*_t11*_t115 + _hc0[10]*_hc2[1]*_hc3[2]*_t11*_t23 - _hc0[10]*_t116 + 0.3e1*_hc0[4]*_hc2[1]*_hc3[2]*_t11*_t49 + 0.3e1*_hc2[1]*_hc2[3]*_hc3[3]*_t11*_t23*_t74 + 0.3e1*_hc2[3]*_hc3[2]*_t11*_t28*_t49 - _hc2[3]*_t50*_t78 + _hc2[6]*_hc3[2]*_t11*_t23*_t74 - _hc3[0]*_t246 + _hc3[1]*_t11*(_hc0[10]*_hc2[4] + _hc0[10]*_t47 + _hc0[21]*_hc2[1] + _hc2[11]*_t74 + _t111*_t85 + _t141*_t85 + _t146*_t85 + _t221*_t77 + _t222*_t74 + 0.3e1*_t223*_t28) - _hc3[1]*_t225*_t57 - _hc3[1]*_t229*_t29 + 0.3e1*_hc3[3]*_t11*_t28*_t31*_t49 + _hc3[4]*_t11*_t23*_t74*_t80 - _t105*_t51 - _t115*_t87 - _t118*_t225 - 0.3e1*_t118*_t29 - 0.3e1*_t135*_t91 - _t150*_t90 - _t201*_t224*_t31 - 0.6e1*_t203*_t227 - _t204*_t26 - _t224*_t84 - _t226*_t89 - _t228*_t90 - _t229*_t88 + 1.1739999999999999*_t246 - _t50*_t75) + _hc4[1]*_t106;
  out[40] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[41] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[42] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[43] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc4[0]*(0.2e1*_hc0[1]*_hc2[1]*_hc3[2]*_t11*_t149 + 0.2e1*_hc0[1]*_hc2[1]*_hc3[3]*_t11*_t137*_t23 + _hc0[4]*_hc2[1]*_hc3[2]*_t11*_t66 + _hc0[4]*_hc2[1]*_hc3[3]*_t11*_t60 + _hc2[3]*_hc3[2]*_t11*_t28*_t66 + _hc2[3]*_hc3[3]*_t11*_t28*_t60 - _hc3[0]*_t265 + _hc3[1]*_t11*(_hc0[11]*_hc2[4] + _hc0[11]*_t64 + _hc0[2]*_t252 + _hc0[2]*(_hc0[4]*_hc2[7] + _hc0[4]*_t113 + _t112*_t223 + _t221 + _t222*_t28 + _t252) + _hc0[22]*_hc2[1] + _hc0[4]*_hc2[8] + _hc0[4]*_t143 + _hc0[4]*_t175 + 0.2e1*_hc0[5]*_t141 + _hc0[5]*_t254 + _hc2[12]*_t28 + _t112*_t251 + _t253*_t28) + _hc3[2]*_t11*_t137*_t49 + _hc3[2]*_t11*_t23*(0.2e1*_t107 + 0.2e1*_t108 + 0.2e1*_t109 + 0.2e1*_t110 + _t111*_t195 + 0.2e1*_t114) - _hc3[2]*_t227*_t250 + _hc3[3]*_t11*_t28*_t31*_t66 + _hc3[4]*_t11*_t28*_t31*_t60 - 0.2e1*_t115*_t50 - _t119*_t137 - _t121*_t164 - _t135*_t67 - _t149*_t35 - _t150*_t255 - _t151*_t226 - _t152*_t43 - _t153*_t200 - _t153*_t29 - _t200*_t247 - _t203*_t248*_t66 - _t21*_t248*_t249 - _t228*_t255 - _t247*_t29 + 1.1739999999999999*_t265 - _t43*_t61 - _t72*_t88) + _hc4[2]*_t44 + _t136*_t59;
  out[44] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[45] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[46] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc4[0]*(_hc0[1]*_hc2[1]*_hc3[2]*_t11*_t182 + _hc0[1]*_hc2[1]*_hc3[3]*_t11*_t171*_t23 + _hc0[1]*_hc2[1]*_hc3[3]*_t11*_t23*_t66 + _hc0[1]*_hc2[1]*_hc3[4]*_t11*_t168 - _hc3[0]*_t276 + _hc3[1]*_t11*(_hc0[1]*_t266 + _hc0[12]*_hc2[4] + _hc0[12]*_t178 + _hc0[2]*_t267 + _hc0[2]*_t269 + _hc0[2]*(_hc0[1]*_t253 + _hc0[2]*(_hc0[1]*_t222 + _t223 + _t268) + _hc0[5]*_t179 + _t251 + _t269) + _hc0[23]*_hc2[1] + _hc0[5]*_hc2[8] + _hc0[5]*_t176 + _hc0[5]*_t180 + _hc0[6]*_t141 + _hc0[6]*_t254) + _hc3[2]*_t11*_t149*_t23 + _hc3[2]*_t11*_t171*_t49 + _hc3[2]*_t11*_t23*(0.2e1*_t138 + 0.2e1*_t139 + 0.2e1*_t140 + 0.2e1*_t142 + 0.2e1*_t144 + 0.2e1*_t145 + 0.2e1*_t148) + _hc3[2]*_t11*_t49*_t66 + _hc3[3]*_t11*_t60*(0.3e1*_t45 + 0.3e1*_t46 + 0.3e1*_t48) - _t117*_t137*_t183 - _t118*_t171 - _t118*_t66 - 0.3e1*_t149*_t50 - 0.3e1*_t150*_t72 - _t152*_t229 - 0.3e1*_t153*_t49 - _t164*_t184 - _t169*_t21 - _t182*_t34 - _t183*_t249*_t33 - _t192*_t91 - _t224*_t33*_t66 - _t229*_t61 + 1.1739999999999999*_t276) + _hc4[3]*_t22 + _t165*_t167 + _t166*_t58;
  out[47] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[48] = d4f_dx3_du;
  const double d4f_dx4 = _hc4[0]*(-_hc3[0]*_t288 + _t13*(_hc0[13]*_hc2[4] + 0.3e1*_hc0[13]*_t64 + ((_hc0[2]) * (_hc0[2]))*_hc2[12] + _hc0[2]*_t281 + _hc0[2]*(_hc0[2]*(_hc0[2]*(_hc2[11] + _t222) + _t253 + _t280) + _t179*_t279 + _t266 + _t281) + _hc0[24]*_hc2[1] + _hc0[6]*_hc2[8] + 0.3e1*_hc0[6]*_t180 + _hc2[14] + _t176*_t279) - _t152*_t282 - _t169*_t250 + 0.2e1*_t170*_t182 + _t170*(0.4e1*_hc0[6]*_t64 + 0.2e1*_hc2[9] + 0.2e1*_t172 + 0.2e1*_t173 + 0.2e1*_t174 + 0.2e1*_t177 + 0.2e1*_t181) + _t171*_t277 - _t171*_t278 + _t171*_t30*_t66 - 0.4e1*_t182*_t50 - 0.4e1*_t192*_t51 + _t198*(_t23 * _t23 * _t23 * _t23) + _t277*_t66 + _t277*(0.3e1*_hc2[5] + 0.3e1*_t62 + 0.3e1*_t63 + 0.3e1*_t65) - _t278*_t66 - _t282*_t61 + 1.1739999999999999*_t288 + _t30*(_t66 * _t66)) + 0.4e1*_hc4[1]*_t193 + 0.6e1*_hc4[2]*_t73 + 0.4e1*_hc4[3]*_t27 + _hc4[4]*_t12;
  out[49] = d4f_dx4;
  const double d4f_drs_dt3 = 0;
  out[50] = d4f_drs_dt3;
  const double d4f_drs_du_dt2 = 0;
  out[51] = d4f_drs_du_dt2;
  const double d4f_drs_du2_dt = 0;
  out[52] = d4f_drs_du2_dt;
  const double d4f_drs_du3 = 0;
  out[53] = d4f_drs_du3;
  const double d4f_drs_dx_dt2 = 0;
  out[54] = d4f_drs_dx_dt2;
  const double d4f_drs_dx_du_dt = 0;
  out[55] = d4f_drs_dx_du_dt;
  const double d4f_drs_dx_du2 = 0;
  out[56] = d4f_drs_dx_du2;
  const double d4f_drs_dx2_dt = 0;
  out[57] = d4f_drs_dx2_dt;
  const double d4f_drs_dx2_du = 0;
  out[58] = d4f_drs_dx2_du;
  const double d4f_drs_dx3 = 0;
  out[59] = d4f_drs_dx3;
  const double d4f_drs2_dt2 = 0;
  out[60] = d4f_drs2_dt2;
  const double d4f_drs2_du_dt = 0;
  out[61] = d4f_drs2_du_dt;
  const double d4f_drs2_du2 = 0;
  out[62] = d4f_drs2_du2;
  const double d4f_drs2_dx_dt = 0;
  out[63] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx_du = 0;
  out[64] = d4f_drs2_dx_du;
  const double d4f_drs2_dx2 = 0;
  out[65] = d4f_drs2_dx2;
  const double d4f_drs3_dt = 0;
  out[66] = d4f_drs3_dt;
  const double d4f_drs3_du = 0;
  out[67] = d4f_drs3_du;
  const double d4f_drs3_dx = 0;
  out[68] = d4f_drs3_dx;
  const double d4f_drs4 = 0;
  out[69] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_rppscan_params *params = (const mgga_x_rppscan_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double ta = tau[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = xc_powr(na, -4, 3);
  const double _t6 = M_CBRT2;
  const double _t7 = xc_powr(gaa, 1, 2);
  const double _t8 = _t6*_t7;
  const double _t9 = xc_powr(0.2e1, 2, 3);
  const double _t10 = _t9/xc_powr(na, 5, 3);
  const double _t11 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_spin_z0_k, _KMAX)(p, _t4/xc_powr(na, 1, 3), _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1] = {0.};
  if(!(_t11)) XC_CAT(rscan_f_z0_k, _KMAX)(p, 0, _t5*_t8, 0, _t10*ta, _hc1);
  const double _t12 = 0.2e1*my_piecewise3(_t11, 0, _hc0[0]*_hc1[0]);
  const double zk = _t12;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t16 = xc_powr(na, -8, 3);
  const double _t17 = (0.5e1 / 0.3e1)*_t16;
  const double _t20 = xc_powr(na, -7, 3);
  const double _t21 = (0.4e1 / 0.3e1)*_t20;
  const double _t24 = 0.2e1*na;
  const double _t25 = (0.1e1 / _t7);
  const double _t26 = _t25*_t6;
  const double _t13 = _hc0[1]*_t3;
  const double _t14 = _t13*_t5;
  const double _t15 = _hc1[1]*_t9;
  const double _t18 = _t15*_t17;
  const double _t19 = _hc1[3]*_t8;
  const double _t22 = -_t18*ta - _t19*_t21;
  const double _t23 = my_piecewise3(_t11, 0, _hc0[0]*_t22 - 0.1e1 / 0.6e1*_hc1[0]*_t14);
  const double _t27 = _hc1[3]*_t26;
  const double _t28 = _hc0[0]*_t5;
  const double _t29 = 0.2e1*my_piecewise3(_t11, 0, (0.1e1 / 0.2e1)*_t27*_t28);
  const double _t30 = 0.2e1*my_piecewise3(_t11, 0, _hc0[0]*_hc1[1]*_t10);
  const double dF_dna = _t12 + _t23*_t24;
  const double dF_dgaa = _t29*na;
  const double dF_dta = _t30*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double _t33 = xc_powr(0.6e1, 2, 3);
  const double _t34 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t39 = xc_powr(na, -11, 3);
  const double _t40 = (0.40e2 / 0.9e1)*_t39;
  const double _t42 = xc_powr(na, -10, 3);
  const double _t43 = (0.28e2 / 0.9e1)*_t42;
  const double _t44 = _t17*_t9;
  const double _t46 = _t21*_t8;
  const double _t58 = (0.2e1 / 0.3e1)*_t39;
  const double _t61 = (0.1e1 / (na * na * na * na));
  const double _t62 = (0.5e1 / 0.3e1)*_t61;
  const double _t63 = (0.2e1 / 0.3e1)*_t20;
  const double _t66 = (0.1e1 / (na * na * na));
  const double _t70 = (0.8e1 / 0.3e1)*_t61;
  const double _t71 = xc_powr(na, -13, 3);
  const double _t72 = (0.10e2 / 0.3e1)*_t71;
  const double _t77 = xc_powr(gaa, -3, 2);
  const double _t80 = (0.1e1 / gaa);
  const double _t31 = (0.2e1 / 0.9e1)*_hc1[0];
  const double _t32 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t35 = _hc0[2]*_t34;
  const double _t36 = _t33*_t35;
  const double _t37 = _t16*_t36;
  const double _t38 = (0.1e1 / 0.3e1)*_t14;
  const double _t41 = _t15*_t40;
  const double _t45 = _hc1[5]*_t44;
  const double _t47 = -_hc1[8]*_t46 - _t45*ta;
  const double _t48 = _t44*_t47;
  const double _t49 = _hc1[8]*_t44;
  const double _t50 = -_hc1[10]*_t46 - _t49*ta;
  const double _t51 = _t19*_t43 + _t41*ta - _t46*_t50 - _t48*ta;
  const double _t52 = my_piecewise3(_t11, 0, _hc0[0]*_t51 + _t13*_t20*_t31 - _t22*_t38 + _t32*_t37);
  const double _t53 = _hc1[3]*_t25;
  const double _t54 = _hc0[1]*_t2;
  const double _t55 = xc_powr(0.12e2, 1, 3)*_t54;
  const double _t56 = _t16*_t55;
  const double _t57 = _hc1[10]*_t9;
  const double _t59 = _hc1[8]*_t25;
  const double _t60 = _t59*ta;
  const double _t64 = -_t27*_t63 - _t57*_t58 - _t60*_t62;
  const double _t65 = my_piecewise3(_t11, 0, _hc0[0]*_t64 - 0.1e1 / 0.12e2*_t53*_t56);
  const double _t67 = M_CBRT3*_t54;
  const double _t68 = _hc1[1]*_t67;
  const double _t69 = _hc1[8]*_t7;
  const double _t73 = _hc1[5]*_t6;
  const double _t74 = _t73*ta;
  const double _t75 = -_t18 - _t69*_t70 - _t72*_t74;
  const double _t76 = my_piecewise3(_t11, 0, _hc0[0]*_t75 - 0.1e1 / 0.3e1*_t66*_t68);
  const double _t78 = _hc1[3]*_t77;
  const double _t79 = _t6*_t78;
  const double _t81 = _t57*_t80;
  const double _t82 = _hc0[0]*_t16;
  const double _t83 = 0.2e1*my_piecewise3(_t11, 0, -0.1e1 / 0.4e1*_t28*_t79 + (0.1e1 / 0.4e1)*_t81*_t82);
  const double _t84 = _hc0[0]*_t66;
  const double _t85 = 0.2e1*my_piecewise3(_t11, 0, _t59*_t84);
  const double _t86 = 0.2e1*_hc0[0];
  const double _t87 = 0.2e1*my_piecewise3(_t11, 0, _t42*_t73*_t86);
  const double d2F_dna2 = 0.4e1*_t23 + _t24*_t52;
  const double d2F_dna_dgaa = _t24*_t65 + _t29;
  const double d2F_dna_dta = _t24*_t76 + _t30;
  const double d2F_dgaa2 = _t83*na;
  const double d2F_dgaa_dta = _t85*na;
  const double d2F_dta2 = _t87*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double _t93 = xc_powr(na, -14, 3);
  const double _t94 = (0.440e3 / 0.27e2)*_t93;
  const double _t96 = (0.280e3 / 0.27e2)*_t71;
  const double _t97 = _t40*_t9;
  const double _t99 = _t43*_t8;
  const double _t116 = (0.14e2 / 0.9e1)*_t93;
  const double _t117 = xc_powi(na, -5);
  const double _t118 = (0.14e2 / 0.9e1)*_t42;
  const double _t119 = _t26*_t63;
  const double _t120 = _t58*_t9;
  const double _t122 = _t25*_t62;
  const double _t131 = (0.56e2 / 0.9e1)*_t117;
  const double _t132 = xc_powr(na, -16, 3);
  const double _t134 = _t7*_t70;
  const double _t136 = _t6*_t72;
  const double _t138 = _t44*ta;
  const double _t145 = (0.2e1 / 0.3e1)*_t117;
  const double _t146 = (0.1e1 / 0.3e1)*_t39;
  const double _t147 = (0.5e1 / 0.6e1)*ta;
  const double _t154 = (0.4e1 / 0.3e1)*_t132;
  const double _t155 = 0.3e1*_t61;
  const double _t157 = xc_powr(na, -17, 3);
  const double _t158 = _t157*_t9;
  const double _t162 = xc_powi(na, -6);
  const double _t164 = (0.20e2 / 0.3e1)*ta;
  const double _t165 = (0.20e2 / 0.3e1)*_t71;
  const double _t168 = (0.8e1 / 0.3e1)*_t157;
  const double _t171 = _t61*_t77;
  const double _t173 = xc_powr(gaa, -5, 2);
  const double _t176 = (0.1e1 / (gaa * gaa));
  const double _t88 = _hc0[3]/M_PI;
  const double _t89 = _t61*_t88;
  const double _t90 = _t13*_t42;
  const double _t91 = _t36*_t39;
  const double _t92 = _hc0[1]*_t4*_t5;
  const double _t95 = _t15*_t94;
  const double _t98 = _hc1[5]*_t97;
  const double _t100 = _hc1[15]*_t44;
  const double _t101 = -_hc1[19]*_t46 - _t100*ta;
  const double _t102 = _t101*_t44;
  const double _t103 = _hc1[19]*_t44;
  const double _t104 = -_hc1[22]*_t46 - _t103*ta;
  const double _t105 = _hc1[8]*_t99 - _t102*ta - _t104*_t46 + _t98*ta;
  const double _t106 = _t105*_t44;
  const double _t107 = _hc1[8]*_t97;
  const double _t108 = _t104*_t44;
  const double _t109 = _hc1[22]*_t44;
  const double _t110 = -_hc1[24]*_t46 - _t109*ta;
  const double _t111 = _hc1[10]*_t99 + _t107*ta - _t108*ta - _t110*_t46;
  const double _t112 = -_t106*ta - _t111*_t46 - _t19*_t96 + (0.80e2 / 0.9e1)*_t39*_t47*_t9*ta + (0.56e2 / 0.9e1)*_t42*_t50*_t6*_t7 - _t95*ta;
  const double _t113 = my_piecewise3(_t11, 0, _hc0[0]*_t112 + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t20*_t22 + (0.1e1 / 0.12e2)*_hc0[2]*_t16*_t22*_t33*_t34 - 0.14e2 / 0.27e2*_hc1[0]*_t90 - 0.1e1 / 0.9e1*_hc1[0]*_t91 - _t32*_t89 - _t51*_t92);
  const double _t114 = _t53*_t55;
  const double _t115 = xc_powr(0.3e1, 2, 3)*_t35;
  const double _t121 = _hc1[19]*ta;
  const double _t123 = _t59*_t6;
  const double _t124 = -_hc1[22]*_t120 - _t121*_t122 - _t123*_t63;
  const double _t125 = _t124*_t44;
  const double _t126 = _hc1[22]*ta;
  const double _t127 = -_hc1[10]*_t119 - _hc1[24]*_t120 - _t122*_t126;
  const double _t128 = _t116*_t57 + (0.40e2 / 0.9e1)*_t117*_t59*ta + _t118*_t27 - _t119*_t50 - _t125*ta - _t127*_t46;
  const double _t129 = my_piecewise3(_t11, 0, _hc0[0]*_t128 + (0.1e1 / 0.9e1)*_t114*_t39 + (0.1e1 / 0.36e2)*_t115*_t53*_t61 - _t38*_t64);
  const double _t130 = xc_powr(0.18e2, 1, 3)*_hc1[1]*_t35;
  const double _t133 = _t132*_t73;
  const double _t135 = _hc1[15]*ta;
  const double _t137 = -_hc1[19]*_t134 - _t135*_t136 - _t45;
  const double _t139 = -_hc1[22]*_t134 - _t121*_t136 - _t49;
  const double _t140 = _t131*_t69 + (0.80e2 / 0.9e1)*_t133*ta - _t137*_t138 - _t139*_t46 + _t41 - _t48;
  const double _t141 = my_piecewise3(_t11, 0, _hc0[0]*_t140 + (0.1e1 / 0.18e2)*_t130*_t71 - _t38*_t75 + (0.4e1 / 0.9e1)*_t61*_t68);
  const double _t142 = _hc1[10]*_t80;
  const double _t143 = _t142*_t67;
  const double _t144 = _hc1[24]*_t25;
  const double _t148 = _hc1[22]*_t6;
  const double _t149 = _t148*_t80;
  const double _t150 = _t132*_t149;
  const double _t151 = (0.1e1 / 0.3e1)*_hc1[3]*_t20*_t6*_t77 + (0.5e1 / 0.6e1)*_hc1[8]*_t61*_t77*ta - _t144*_t145 - _t146*_t81 - _t147*_t150;
  const double _t152 = my_piecewise3(_t11, 0, _hc0[0]*_t151 - 0.1e1 / 0.12e2*_t143*_t61 + (0.1e1 / 0.24e2)*_t56*_t78);
  const double _t153 = _t13*_t71;
  const double _t156 = _t121*_t25;
  const double _t159 = -_t148*_t154 - _t155*_t59 - 0.5e1 / 0.3e1*_t156*_t158;
  const double _t160 = my_piecewise3(_t11, 0, _hc0[0]*_t159 - 0.1e1 / 0.6e1*_t153*_t59);
  const double _t161 = _hc1[5]*_t67;
  const double _t163 = _hc1[15]*_t162;
  const double _t166 = _hc1[19]*_t9;
  const double _t167 = _t166*_t7;
  const double _t169 = -_t163*_t164 - _t165*_t73 - _t167*_t168;
  const double _t170 = my_piecewise3(_t11, 0, _hc0[0]*_t169 - 0.1e1 / 0.3e1*_t161*_t9*_t93);
  const double _t172 = _hc0[0]*_hc1[24];
  const double _t174 = _hc1[3]*_t6;
  const double _t175 = _t173*_t174;
  const double _t177 = 0.2e1*my_piecewise3(_t11, 0, (0.1e1 / 0.4e1)*_t171*_t172 + (0.3e1 / 0.8e1)*_t175*_t28 - 0.3e1 / 0.8e1*_t176*_t57*_t82);
  const double _t178 = _hc1[8]*_t77;
  const double _t179 = _hc0[0]*_t71;
  const double _t180 = 0.2e1*my_piecewise3(_t11, 0, (0.1e1 / 0.2e1)*_t149*_t179 - 0.1e1 / 0.2e1*_t178*_t84);
  const double _t181 = _t166*_t25;
  const double _t182 = _hc0[0]*_t93;
  const double _t183 = 0.2e1*my_piecewise3(_t11, 0, _t181*_t182);
  const double _t184 = 0.4e1*_hc0[0];
  const double _t185 = 0.2e1*my_piecewise3(_t11, 0, _hc1[15]*_t117*_t184);
  const double d3F_dna3 = _t113*_t24 + 0.6e1*_t52;
  const double d3F_dna2_dgaa = _t129*_t24 + 0.4e1*_t65;
  const double d3F_dna2_dta = _t141*_t24 + 0.4e1*_t76;
  const double d3F_dna_dgaa2 = _t152*_t24 + _t83;
  const double d3F_dna_dgaa_dta = _t160*_t24 + _t85;
  const double d3F_dna_dta2 = _t170*_t24 + _t87;
  const double d3F_dgaa3 = _t177*na;
  const double d3F_dgaa2_dta = _t180*na;
  const double d3F_dgaa_dta2 = _t183*na;
  const double d3F_dta3 = _t185*na;
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
  const double _t187 = _t9*ta;
  const double _t188 = _t187*_t94;
  const double _t189 = _t8*_t96;
  const double _t194 = _t116*_t9;
  const double _t195 = (0.40e2 / 0.9e1)*_t117;
  const double _t196 = _t122*ta;
  const double _t198 = (0.2e1 / 0.9e1)*_t132;
  const double _t199 = xc_powr(na, -19, 3);
  const double _t200 = _t131*_t7;
  const double _t201 = _t132*_t6;
  const double _t202 = (0.80e2 / 0.9e1)*_t201;
  const double _t203 = _t136*ta;
  const double _t208 = _t145*_t25;
  const double _t209 = _t146*_t80*_t9;
  const double _t211 = _t147*_t201;
  const double _t212 = xc_powr(na, -20, 3);
  const double _t213 = _t154*_t6;
  const double _t214 = _t155*_t25;
  const double _t215 = (0.5e1 / 0.3e1)*_t157*_t187*_t25;
  const double _t216 = xc_powi(na, -7);
  const double _t217 = _t162*_t164;
  const double _t218 = _t165*_t6;
  const double _t219 = (0.1e1 / 0.8e1)*_t176;
  const double _t220 = _t173*_t61;
  const double _t222 = _t212*_t9;
  const double _t186 = _t15*_t157;
  const double _t190 = -_hc1[40]*_t138 - _hc1[44]*_t46;
  const double _t191 = -_hc1[44]*_t138 - _hc1[47]*_t46;
  const double _t192 = _hc1[22]*_t99 + _t121*_t97 - _t138*_t190 - _t191*_t46;
  const double _t193 = (0.1e1 / 0.9e1)*_t115;
  const double _t197 = -_hc1[44]*_t196 - _hc1[47]*_t120 - _t148*_t25*_t63;
  const double _t204 = (0.8e1 / 0.3e1)*_hc1[44];
  const double _t205 = _t204*_t7;
  const double _t206 = -_hc1[40]*_t203 - _t103 - _t205*_t61;
  const double _t207 = (0.1e1 / 0.72e2)*_t115;
  const double _t210 = _hc1[44]*_t80;
  const double _t221 = _hc1[47]*_t77;
  const double _t223 = _hc1[40]/xc_powr(na, 22, 3);
  const double d4F_dna4 = 0.8e1*_t113 + _t24*my_piecewise3(_t11, 0, _hc0[0]*((0.40e2 / 0.3e1)*_t105*_t187*_t39 + (0.28e2 / 0.3e1)*_t111*_t42*_t8 + (0.3640e4 / 0.81e2)*_t132*_t19 - _t138*(-_hc1[5]*_t188 - _hc1[8]*_t189 + (0.80e2 / 0.9e1)*_t101*_t39*_t9*ta + (0.56e2 / 0.9e1)*_t104*_t42*_t6*_t7 - _t138*(_hc1[19]*_t99 + _t135*_t97 - _t138*(-_hc1[35]*_t138 - _hc1[40]*_t46) - _t190*_t46) - _t192*_t46) + (0.6160e4 / 0.81e2)*_t186*ta - _t46*(-_hc1[10]*_t189 - _hc1[8]*_t188 + (0.80e2 / 0.9e1)*_t104*_t39*_t9*ta + (0.56e2 / 0.9e1)*_t110*_t42*_t6*_t7 - _t138*_t192 - _t46*(_hc1[24]*_t99 + _t126*_t97 - _t138*_t191 - _t46*(-_hc1[47]*_t138 - _hc1[49]*_t46))) - 0.440e3 / 0.9e1*_t47*_t9*_t93*ta - 0.280e3 / 0.9e1*_t50*_t71*_t8) + (0.1e1 / 0.216e3)*_hc0[4]*_hc1[0]*_t1*_t132/(M_PI * M_CBRTPI) + (0.140e3 / 0.81e2)*_hc1[0]*_t153 + (0.40e2 / 0.81e2)*_hc1[0]*_t36*_t93 - 0.2e1 / 0.3e1*_t112*_t14 + _t117*_t31*_t88 + _t13*_t21*_t51 - 0.1e1 / 0.9e1*_t22*_t89 - 0.56e2 / 0.27e2*_t22*_t90 - 0.4e1 / 0.9e1*_t22*_t91 + (0.1e1 / 0.6e1)*_t37*_t51);
  const double d4F_dna3_dgaa = 0.6e1*_t129 + _t24*my_piecewise3(_t11, 0, _hc0[0]*(-_t111*_t119 + (0.80e2 / 0.9e1)*_t124*_t39*_t9*ta + (0.56e2 / 0.9e1)*_t127*_t42*_t6*_t7 - _t138*(_hc1[22]*_t194 - _t104*_t119 + _t118*_t123 - _t138*(-_hc1[19]*_t119 - _hc1[40]*_t196 - _hc1[44]*_t120) + _t156*_t195 - _t197*_t46) - 0.140e3 / 0.27e2*_t157*_t57 - 0.440e3 / 0.27e2*_t162*_t60 + (0.28e2 / 0.9e1)*_t25*_t42*_t50*_t6 - 0.140e3 / 0.27e2*_t27*_t71 - _t46*(_hc1[10]*_t118*_t26 + _hc1[24]*_t194 - _t110*_t119 + _t126*_t195*_t25 - _t138*_t197 - _t46*(-_hc1[47]*_t196 - _hc1[49]*_t120 - _t144*_t6*_t63))) + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t20*_t64 + (0.1e1 / 0.12e2)*_hc0[2]*_t16*_t33*_t34*_t64 - 0.7e1 / 0.27e2*_t114*_t93 - _t117*_t193*_t53 - _t128*_t92 - 0.1e1 / 0.72e2*_t132*_t27*_t88);
  const double d4F_dna3_dta = 0.6e1*_t141 + _t24*my_piecewise3(_t11, 0, _hc0[0]*(-_t106 + (0.80e2 / 0.9e1)*_t137*_t39*_t9*ta - _t138*(_hc1[19]*_t200 - _t102 + _t135*_t202 - _t138*(-_hc1[35]*_t203 - _hc1[40]*_t134 - _t100) - _t206*_t46 + _t98) + (0.56e2 / 0.9e1)*_t139*_t42*_t6*_t7 - 0.560e3 / 0.27e2*_t162*_t69 - 0.880e3 / 0.27e2*_t199*_t74 + (0.80e2 / 0.9e1)*_t39*_t47*_t9 - _t46*(_hc1[22]*_t200 + _t107 - _t108 + _t121*_t202 - _t138*_t206 - _t46*(-_hc1[44]*_t203 - _hc1[47]*_t134 - _t109)) - _t95) + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t20*_t75 + (0.1e1 / 0.12e2)*_hc0[2]*_t16*_t33*_t34*_t75 - 0.28e2 / 0.27e2*_t117*_t68 - _t130*_t198 - _t140*_t92 - 0.1e1 / 0.36e2*_t186*_t88);
  const double d4F_dna2_dgaa2 = 0.4e1*_t152 + _t24*my_piecewise3(_t11, 0, _hc0[0]*((0.7e1 / 0.9e1)*_hc1[10]*_t80*_t9*_t93 + (0.20e2 / 0.9e1)*_hc1[22]*_t199*_t6*_t80*ta + (0.14e2 / 0.9e1)*_hc1[24]*_t162*_t25 - 0.20e2 / 0.9e1*_t117*_t178*ta - _t127*_t21*_t26 - _t138*((0.5e1 / 0.6e1)*_hc1[19]*_t61*_t77*ta - _hc1[22]*_t209 - _hc1[47]*_t208 + (0.1e1 / 0.3e1)*_hc1[8]*_t20*_t6*_t77 - _t210*_t211) + (0.1e1 / 0.3e1)*_t20*_t50*_t6*_t77 - 0.7e1 / 0.9e1*_t42*_t79 - _t46*((0.1e1 / 0.3e1)*_hc1[10]*_t20*_t6*_t77 + (0.5e1 / 0.6e1)*_hc1[22]*_t61*_t77*ta - _hc1[24]*_t209 - _hc1[47]*_t211*_t80 - _hc1[49]*_t208)) - _hc1[3]*_t171*_t207 + (0.1e1 / 0.9e1)*_t117*_t143 + _t142*_t201*_t207 - _t151*_t38 - 0.1e1 / 0.18e2*_t39*_t55*_t78);
  const double d4F_dna2_dgaa_dta = 0.4e1*_t160 + _t24*my_piecewise3(_t11, 0, _hc0[0]*((0.40e2 / 0.9e1)*_hc1[19]*_t212*_t25*_t9*ta + (0.28e2 / 0.9e1)*_hc1[22]*_t199*_t6 + (0.68e2 / 0.9e1)*_hc1[8]*_t117*_t25 - _t119*_t139 - _t125 - _t138*(-_hc1[19]*_t214 - _hc1[40]*_t215 - _hc1[44]*_t213) - _t46*(-_hc1[22]*_t214 - _hc1[44]*_t215 - _hc1[47]*_t213)) + _t13*_t198*_t59 + (0.1e1 / 0.36e2)*_t157*_t36*_t59 - _t159*_t38);
  const double d4F_dna2_dta2 = 0.4e1*_t170 + _t24*my_piecewise3(_t11, 0, _hc0[0]*((0.160e3 / 0.9e1)*_t133 + (0.160e3 / 0.9e1)*_t135*_t216 - 0.10e2 / 0.3e1*_t137*_t16*_t9 - _t138*(-_hc1[15]*_t218 - _hc1[35]*_t217 - _hc1[40]*_t168*_t7*_t9) + (0.56e2 / 0.9e1)*_t167*_t212 - _t46*(-_hc1[19]*_t218 - _hc1[40]*_t217 - _t158*_t205)) + _hc1[5]*_t162*_t193 + (0.4e1 / 0.9e1)*_t158*_t161 - _t169*_t38);
  const double d4F_dna_dgaa3 = _t177 + _t24*my_piecewise3(_t11, 0, _hc0[0]*((0.1e1 / 0.2e1)*_hc1[10]*_t176*_t39*_t9 + (0.5e1 / 0.4e1)*_hc1[22]*_t132*_t176*_t6*ta - 0.1e1 / 0.3e1*_hc1[49]*_t199*_t6*_t80 - 0.5e1 / 0.4e1*_hc1[8]*_t220*ta - 0.1e1 / 0.2e1*_t175*_t20 - 0.5e1 / 0.12e2*_t187*_t212*_t221) + _hc1[10]*_t219*_t61*_t67 - 0.1e1 / 0.24e2*_hc1[24]*_t13*_t132*_t77 - 0.1e1 / 0.16e2*_hc1[3]*_t173*_t56);
  const double d4F_dna_dgaa2_dta = _t180 + _t24*my_piecewise3(_t11, 0, _hc0[0]*((0.5e1 / 0.6e1)*_hc1[19]*_t157*_t77*_t9*ta - 0.2e1 / 0.3e1*_hc1[47]*_t222*_t25 + (0.3e1 / 0.2e1)*_hc1[8]*_t61*_t77 - 0.3e1 / 0.2e1*_t150 - 0.5e1 / 0.3e1*_t210*_t216*ta) - 0.1e1 / 0.12e2*_hc1[22]*_t158*_t67*_t80 + (0.1e1 / 0.12e2)*_t153*_t178);
  const double d4F_dna_dgaa_dta2 = _t183 + _t24*my_piecewise3(_t11, 0, _hc0[0]*(-0.14e2 / 0.3e1*_t157*_t181 - _t204*_t216 - 0.10e2 / 0.3e1*_t223*_t26*ta) - 0.1e1 / 0.3e1*_hc1[19]*_t162*_t25*_t67);
  const double d4F_dna_dta3 = _t185 + _t24*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[35]*_t164*_t9/xc_powr(na, 23, 3) - 0.20e2*_t163 - 0.16e2 / 0.3e1*_t223*_t8) - 0.2e1 / 0.3e1*_hc1[15]*_t13*_t199);
  const double d4F_dgaa4 = _t24*my_piecewise3(_t11, 0, _hc0[0]*_hc1[49]*_t201*_t219 - 0.3e1 / 0.4e1*_t172*_t220 - 0.15e2 / 0.16e2*_t174*_t28/xc_powr(gaa, 7, 2) + (0.15e2 / 0.16e2)*_t57*_t82/(gaa * gaa * gaa));
  const double d4F_dgaa3_dta = _t24*my_piecewise3(_t11, 0, (0.1e1 / 0.4e1)*_hc0[0]*_t158*_t221 + (0.3e1 / 0.4e1)*_hc1[8]*_t173*_t84 - 0.3e1 / 0.4e1*_t148*_t176*_t179);
  const double d4F_dgaa2_dta2 = _t24*my_piecewise3(_t11, 0, _hc0[0]*_hc1[44]*_t162*_t80 - 0.1e1 / 0.2e1*_t166*_t182*_t77);
  const double d4F_dgaa_dta3 = _t24*my_piecewise3(_t11, 0, _hc1[40]*_t199*_t26*_t86);
  const double d4F_dta4 = _t24*my_piecewise3(_t11, 0, _hc1[35]*_t184*_t222);
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
  const double ta = tau[0];
  const double tb = tau[1];

  const double _t1 = -nb;
  const double _t2 = _t1 + na;
  const double _t3 = na + nb;
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = xc_powr(0.6e1, 1, 3);
  const double _t7 = (0.1e1 / (M_CBRTPI));
  const double _t8 = _t6*_t7;
  const double _t9 = (0.1e1 / 0.2e1)*_t8/xc_powr(_t3, 1, 3);
  const double _t10 = xc_powr(gaa, 1, 2);
  const double _t11 = xc_powr(na, -4, 3);
  const double _t12 = xc_powr(na, -5, 3);
  const double _t13 = xc_powr(gbb, 1, 2);
  const double _t14 = xc_powr(nb, -4, 3);
  const double _t15 = xc_powr(nb, -5, 3);
  const double _t16 = -p->dens_threshold + na <= 0;
  const double _t17 = -_t1 - p->dens_threshold <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t16)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t9, _hc0[0], _hc1);
  double _hc2[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1] = {0.};
  if(!(_t16)) XC_CAT(rscan_f_k, _KMAX)(p, 0, 0, _t10*_t11, 0, _t12*ta, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t5, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t17)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t9, _hc3[0], _hc4);
  double _hc5[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1] = {0.};
  if(!(_t17)) XC_CAT(rscan_f_k, _KMAX)(p, 0, 0, _t13*_t14, 0, _t15*tb, _hc5);
  const double _t18 = my_piecewise3(_t16, 0, _hc1[0]*_hc2[0]) + my_piecewise3(_t17, 0, _hc4[0]*_hc5[0]);
  const double zk = _t18;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t19 = xc_powr(_t3, -4, 3);
  const double _t20 = _t19*_t8;
  const double _t21 = (0.1e1 / 0.6e1)*_t20;
  const double _t23 = -_t4;
  const double _t24 = (0.1e1 / (_t3 * _t3));
  const double _t25 = _t2*_t24;
  const double _t26 = _t23 + _t25;
  const double _t30 = xc_powr(na, -8, 3);
  const double _t31 = (0.5e1 / 0.3e1)*_t30;
  const double _t34 = xc_powr(na, -7, 3);
  const double _t35 = (0.4e1 / 0.3e1)*_t34;
  const double _t38 = -_t26;
  const double _t43 = _t25 + _t4;
  const double _t44 = -_t43;
  const double _t47 = xc_powr(nb, -8, 3);
  const double _t48 = (0.5e1 / 0.3e1)*_t47;
  const double _t51 = xc_powr(nb, -7, 3);
  const double _t52 = (0.4e1 / 0.3e1)*_t51;
  const double _t58 = (0.1e1 / _t10);
  const double _t63 = (0.1e1 / _t13);
  const double _t22 = -_hc4[2]*_t21;
  const double _t27 = _hc3[1]*_hc4[1];
  const double _t28 = _t22 + _t26*_t27;
  const double _t29 = my_piecewise3(_t17, 0, _hc5[0]*_t28);
  const double _t32 = _hc2[1]*_t31;
  const double _t33 = _hc2[3]*_t10;
  const double _t36 = -_t32*ta - _t33*_t35;
  const double _t37 = -_hc1[2]*_t21;
  const double _t39 = _hc0[1]*_hc1[1];
  const double _t40 = _t37 + _t38*_t39;
  const double _t41 = my_piecewise3(_t16, 0, _hc1[0]*_t36 + _hc2[0]*_t40);
  const double _t42 = _t29 + _t41;
  const double _t45 = _t37 + _t39*_t44;
  const double _t46 = my_piecewise3(_t16, 0, _hc2[0]*_t45);
  const double _t49 = _hc5[1]*_t48;
  const double _t50 = _hc5[3]*_t13;
  const double _t53 = -_t49*tb - _t50*_t52;
  const double _t54 = _t22 + _t27*_t43;
  const double _t55 = my_piecewise3(_t17, 0, _hc4[0]*_t53 + _hc5[0]*_t54);
  const double _t56 = _t46 + _t55;
  const double _t57 = _hc1[0]*_t11;
  const double _t59 = _hc2[3]*_t58;
  const double _t60 = (0.1e1 / 0.2e1)*_t59;
  const double _t61 = my_piecewise3(_t16, 0, _t57*_t60);
  const double _t62 = _hc4[0]*_t14;
  const double _t64 = _hc5[3]*_t63;
  const double _t65 = (0.1e1 / 0.2e1)*_t64;
  const double _t66 = my_piecewise3(_t17, 0, _t62*_t65);
  const double _t67 = _hc2[1]*_t12;
  const double _t68 = my_piecewise3(_t16, 0, _hc1[0]*_t67);
  const double _t69 = _hc5[1]*_t15;
  const double _t70 = my_piecewise3(_t17, 0, _hc4[0]*_t69);
  const double dF_dna = _t18 + _t3*_t42;
  const double dF_dnb = _t18 + _t3*_t56;
  const double dF_dgaa = _t3*_t61;
  const double dF_dgbb = _t3*_t66;
  const double dF_dta = _t3*_t68;
  const double dF_dtb = _t3*_t70;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double _t71 = xc_powr(_t3, -7, 3);
  const double _t72 = (0.2e1 / 0.9e1)*_t71;
  const double _t73 = _t72*_t8;
  const double _t75 = 0.2e1*_t24;
  const double _t76 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t77 = 0.2e1*_t76;
  const double _t78 = _t2*_t77;
  const double _t79 = -_t75 + _t78;
  const double _t80 = -_t79;
  const double _t81 = (_t26 * _t26);
  const double _t91 = xc_powr(na, -11, 3);
  const double _t92 = (0.40e2 / 0.9e1)*_t91;
  const double _t94 = xc_powr(na, -10, 3);
  const double _t95 = (0.28e2 / 0.9e1)*_t94;
  const double _t97 = _t10*_t35;
  const double _t105 = (_t38 * _t38);
  const double _t129 = _t75 + _t78;
  const double _t130 = (_t44 * _t44);
  const double _t134 = xc_powr(nb, -11, 3);
  const double _t135 = (0.40e2 / 0.9e1)*_t134;
  const double _t137 = xc_powr(nb, -10, 3);
  const double _t138 = (0.28e2 / 0.9e1)*_t137;
  const double _t140 = _t13*_t52;
  const double _t146 = -_t129;
  const double _t147 = (_t43 * _t43);
  const double _t151 = (0.2e1 / 0.3e1)*_t91;
  const double _t152 = (0.2e1 / 0.3e1)*_t34;
  const double _t155 = (0.1e1 / (na * na * na * na));
  const double _t156 = (0.5e1 / 0.6e1)*_t155;
  const double _t163 = (0.2e1 / 0.3e1)*_t134;
  const double _t164 = (0.2e1 / 0.3e1)*_t51;
  const double _t167 = (0.1e1 / (nb * nb * nb * nb));
  const double _t168 = (0.5e1 / 0.6e1)*_t167;
  const double _t171 = xc_powr(na, -13, 3);
  const double _t172 = (0.5e1 / 0.3e1)*ta;
  const double _t173 = _t171*_t172;
  const double _t175 = (0.4e1 / 0.3e1)*_t155;
  const double _t180 = xc_powr(nb, -13, 3);
  const double _t181 = (0.5e1 / 0.3e1)*tb;
  const double _t182 = _t180*_t181;
  const double _t184 = (0.4e1 / 0.3e1)*_t167;
  const double _t188 = (0.1e1 / gaa);
  const double _t190 = xc_powr(gaa, -3, 2);
  const double _t195 = (0.1e1 / gbb);
  const double _t197 = xc_powr(gbb, -3, 2);
  const double _t201 = (0.1e1 / (na * na * na));
  const double _t205 = (0.1e1 / (nb * nb * nb));
  const double _t74 = _hc4[2]*_t73;
  const double _t82 = _hc3[2]*_hc4[1];
  const double _t83 = -_hc4[5]*_t21;
  const double _t84 = _hc3[1]*_t26;
  const double _t85 = _hc4[4]*_t84 + _t83;
  const double _t86 = -_hc4[4]*_t21;
  const double _t87 = _hc4[3]*_t84 + _t86;
  const double _t88 = -_t21*_t85 + _t27*_t80 + _t74 + _t81*_t82 + _t84*_t87;
  const double _t89 = my_piecewise3(_t17, 0, _hc5[0]*_t88);
  const double _t90 = 0.2e1*_t36;
  const double _t93 = _hc2[1]*_t92;
  const double _t96 = _hc2[6]*_t31;
  const double _t98 = -_hc2[9]*_t97 - _t96*ta;
  const double _t99 = _t31*_t98;
  const double _t100 = _hc2[9]*_t31;
  const double _t101 = -_hc2[11]*_t97 - _t100*ta;
  const double _t102 = -_t101*_t97 + _t33*_t95 + _t93*ta - _t99*ta;
  const double _t103 = _hc1[2]*_t8;
  const double _t104 = _t103*_t72;
  const double _t106 = _hc0[2]*_hc1[1];
  const double _t107 = -_hc1[5]*_t21;
  const double _t108 = _hc0[1]*_t38;
  const double _t109 = _hc1[4]*_t108 + _t107;
  const double _t110 = -_hc1[4]*_t21;
  const double _t111 = _hc1[3]*_t108 + _t110;
  const double _t112 = _t104 + _t105*_t106 + _t108*_t111 - _t109*_t21 + _t39*_t79;
  const double _t113 = my_piecewise3(_t16, 0, _hc1[0]*_t102 + _hc2[0]*_t112 + _t40*_t90);
  const double _t114 = _t113 + _t89;
  const double _t115 = _hc3[1]*_t43;
  const double _t116 = _hc4[3]*_t115 + _t86;
  const double _t117 = _t26*_t82;
  const double _t118 = _hc4[4]*_t115 + _t83;
  const double _t119 = -_t118*_t21 + _t74;
  const double _t120 = _t116*_t84 + _t117*_t43 + _t119 - _t27*_t78;
  const double _t121 = my_piecewise3(_t17, 0, _hc5[0]*_t120 + _t28*_t53);
  const double _t122 = _hc0[1]*_t44;
  const double _t123 = _hc1[3]*_t122 + _t110;
  const double _t124 = _t106*_t38;
  const double _t125 = _hc1[4]*_t122 + _t107;
  const double _t126 = _t104 - _t125*_t21;
  const double _t127 = _t108*_t123 + _t124*_t44 + _t126 + _t39*_t78;
  const double _t128 = my_piecewise3(_t16, 0, _hc2[0]*_t127 + _t36*_t45);
  const double _t131 = _t106*_t130 + _t122*_t123 + _t126 + _t129*_t39;
  const double _t132 = my_piecewise3(_t16, 0, _hc2[0]*_t131);
  const double _t133 = 0.2e1*_t53;
  const double _t136 = _hc5[1]*_t135;
  const double _t139 = _hc5[6]*_t48;
  const double _t141 = -_hc5[9]*_t140 - _t139*tb;
  const double _t142 = _t141*_t48;
  const double _t143 = _hc5[9]*_t48;
  const double _t144 = -_hc5[11]*_t140 - _t143*tb;
  const double _t145 = _t136*tb + _t138*_t50 - _t140*_t144 - _t142*tb;
  const double _t148 = _t115*_t116 + _t119 + _t146*_t27 + _t147*_t82;
  const double _t149 = my_piecewise3(_t17, 0, _hc4[0]*_t145 + _hc5[0]*_t148 + _t133*_t54);
  const double _t150 = _t132 + _t149;
  const double _t153 = _hc2[9]*_t58;
  const double _t154 = _t153*ta;
  const double _t157 = -_hc2[11]*_t151 - _t152*_t59 - _t154*_t156;
  const double _t158 = _t11*_t60;
  const double _t159 = my_piecewise3(_t16, 0, _hc1[0]*_t157 + _t158*_t40);
  const double _t160 = _t14*_t65;
  const double _t161 = my_piecewise3(_t17, 0, _t160*_t28);
  const double _t162 = my_piecewise3(_t16, 0, _t158*_t45);
  const double _t165 = _hc5[9]*_t63;
  const double _t166 = _t165*tb;
  const double _t169 = -_hc5[11]*_t163 - _t164*_t64 - _t166*_t168;
  const double _t170 = my_piecewise3(_t17, 0, _hc4[0]*_t169 + _t160*_t54);
  const double _t174 = _hc2[9]*_t10;
  const double _t176 = -_hc2[6]*_t173 - _t174*_t175 - _t32;
  const double _t177 = my_piecewise3(_t16, 0, _hc1[0]*_t176 + _t40*_t67);
  const double _t178 = my_piecewise3(_t17, 0, _t28*_t69);
  const double _t179 = my_piecewise3(_t16, 0, _t45*_t67);
  const double _t183 = _hc5[9]*_t13;
  const double _t185 = -_hc5[6]*_t182 - _t183*_t184 - _t49;
  const double _t186 = my_piecewise3(_t17, 0, _hc4[0]*_t185 + _t54*_t69);
  const double _t187 = _hc1[0]*_t30;
  const double _t189 = (0.1e1 / 0.4e1)*_hc2[11]*_t188;
  const double _t191 = _hc2[3]*_t190;
  const double _t192 = (0.1e1 / 0.4e1)*_t191;
  const double _t193 = my_piecewise3(_t16, 0, _t187*_t189 - _t192*_t57);
  const double _t194 = _hc4[0]*_t47;
  const double _t196 = (0.1e1 / 0.4e1)*_hc5[11]*_t195;
  const double _t198 = _hc5[3]*_t197;
  const double _t199 = (0.1e1 / 0.4e1)*_t198;
  const double _t200 = my_piecewise3(_t17, 0, _t194*_t196 - _t199*_t62);
  const double _t202 = _hc1[0]*_t201;
  const double _t203 = (0.1e1 / 0.2e1)*_t153;
  const double _t204 = my_piecewise3(_t16, 0, _t202*_t203);
  const double _t206 = _hc4[0]*_t205;
  const double _t207 = (0.1e1 / 0.2e1)*_t165;
  const double _t208 = my_piecewise3(_t17, 0, _t206*_t207);
  const double _t209 = _hc2[6]*_t94;
  const double _t210 = my_piecewise3(_t16, 0, _hc1[0]*_t209);
  const double _t211 = _hc5[6]*_t137;
  const double _t212 = my_piecewise3(_t17, 0, _hc4[0]*_t211);
  const double d2F_dna2 = _t114*_t3 + 0.2e1*_t29 + 0.2e1*_t41;
  const double d2F_dna_dnb = _t3*(_t121 + _t128) + _t42 + _t56;
  const double d2F_dnb2 = _t150*_t3 + 0.2e1*_t46 + 0.2e1*_t55;
  const double d2F_dna_dgaa = _t159*_t3 + _t61;
  const double d2F_dna_dgbb = _t161*_t3 + _t66;
  const double d2F_dnb_dgaa = _t162*_t3 + _t61;
  const double d2F_dnb_dgbb = _t170*_t3 + _t66;
  const double d2F_dna_dta = _t177*_t3 + _t68;
  const double d2F_dna_dtb = _t178*_t3 + _t70;
  const double d2F_dnb_dta = _t179*_t3 + _t68;
  const double d2F_dnb_dtb = _t186*_t3 + _t70;
  const double d2F_dgaa2 = _t193*_t3;
  const double d2F_dgbb2 = _t200*_t3;
  const double d2F_dgaa_dta = _t204*_t3;
  const double d2F_dgbb_dtb = _t208*_t3;
  const double d2F_dta2 = _t210*_t3;
  const double d2F_dtb2 = _t212*_t3;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 2] += d2F_dna_dgbb;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 3] += d2F_dnb_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 1] += d2F_dna_dtb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 2] += d2F_dnb_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 5] += d2F_dgbb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double _t213 = xc_powr(_t3, -10, 3);
  const double _t214 = (0.14e2 / 0.27e2)*_t213;
  const double _t215 = _t214*_t8;
  const double _t217 = 0.6e1*_t76;
  const double _t218 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t219 = _t2*_t218;
  const double _t220 = 0.6e1*_t219;
  const double _t221 = -_t217 + _t220;
  const double _t222 = (_t26 * _t26 * _t26);
  const double _t224 = 0.4e1*_t24;
  const double _t225 = 0.4e1*_t76;
  const double _t226 = _t2*_t225;
  const double _t227 = -_t224 + _t226;
  const double _t228 = -_t227;
  const double _t229 = (0.4e1 / 0.9e1)*_t71;
  const double _t230 = _t229*_t8;
  const double _t248 = xc_powr(na, -14, 3);
  const double _t249 = (0.440e3 / 0.27e2)*_t248;
  const double _t251 = (0.280e3 / 0.27e2)*_t171;
  const double _t261 = _t10*_t95;
  const double _t268 = -_t221;
  const double _t269 = (_t38 * _t38 * _t38);
  const double _t272 = -_t2*_t24;
  const double _t273 = _t272 + _t4;
  const double _t294 = _t220 - 0.2e1*_t76;
  const double _t310 = -_t294;
  const double _t311 = _t23 + _t272;
  const double _t333 = _t130*_t273;
  const double _t343 = _t147*_t26;
  const double _t350 = _t217 + _t220;
  const double _t351 = -_t350;
  const double _t352 = (_t44 * _t44 * _t44);
  const double _t355 = _t224 + _t226;
  const double _t360 = xc_powr(nb, -14, 3);
  const double _t361 = (0.440e3 / 0.27e2)*_t360;
  const double _t363 = (0.280e3 / 0.27e2)*_t180;
  const double _t373 = _t13*_t138;
  const double _t379 = (_t43 * _t43 * _t43);
  const double _t380 = -_t355;
  const double _t385 = (0.14e2 / 0.9e1)*_t248;
  const double _t386 = (0.14e2 / 0.9e1)*_t94;
  const double _t387 = xc_powi(na, -5);
  const double _t388 = _t387*_t58;
  const double _t389 = (0.20e2 / 0.9e1)*ta;
  const double _t390 = _t152*_t58;
  const double _t392 = _t156*ta;
  const double _t395 = _t392*_t58;
  const double _t404 = (0.14e2 / 0.9e1)*_t360;
  const double _t405 = (0.14e2 / 0.9e1)*_t137;
  const double _t406 = xc_powi(nb, -5);
  const double _t407 = _t406*_t63;
  const double _t408 = (0.20e2 / 0.9e1)*tb;
  const double _t409 = _t164*_t63;
  const double _t411 = _t168*tb;
  const double _t414 = _t411*_t63;
  const double _t418 = xc_powr(na, -16, 3);
  const double _t420 = (0.40e2 / 0.9e1)*ta;
  const double _t421 = (0.28e2 / 0.9e1)*_t387;
  const double _t422 = _t10*_t175;
  const double _t424 = _t31*ta;
  const double _t432 = xc_powr(nb, -16, 3);
  const double _t434 = (0.40e2 / 0.9e1)*tb;
  const double _t435 = (0.28e2 / 0.9e1)*_t406;
  const double _t436 = _t13*_t184;
  const double _t438 = _t48*tb;
  const double _t444 = _t188*_t91;
  const double _t448 = (0.5e1 / 0.12e2)*ta;
  const double _t455 = _t134*_t195;
  const double _t459 = (0.5e1 / 0.12e2)*tb;
  const double _t462 = (0.2e1 / 0.3e1)*_t418;
  const double _t463 = (0.3e1 / 0.2e1)*_t155;
  const double _t464 = xc_powr(na, -17, 3);
  const double _t465 = _t464*ta;
  const double _t466 = (0.5e1 / 0.6e1)*_t465;
  const double _t473 = (0.2e1 / 0.3e1)*_t432;
  const double _t474 = (0.3e1 / 0.2e1)*_t167;
  const double _t475 = xc_powr(nb, -17, 3);
  const double _t476 = _t475*tb;
  const double _t477 = (0.5e1 / 0.6e1)*_t476;
  const double _t480 = (0.10e2 / 0.3e1)*_t171;
  const double _t481 = xc_powi(na, -6);
  const double _t484 = (0.4e1 / 0.3e1)*_t464;
  const double _t489 = (0.10e2 / 0.3e1)*_t180;
  const double _t490 = xc_powi(nb, -6);
  const double _t493 = (0.4e1 / 0.3e1)*_t475;
  const double _t496 = (0.1e1 / (gaa * gaa));
  const double _t498 = xc_powr(gaa, -5, 2);
  const double _t502 = (0.1e1 / 0.8e1)*_t155*_t190;
  const double _t504 = (0.1e1 / (gbb * gbb));
  const double _t506 = xc_powr(gbb, -5, 2);
  const double _t510 = (0.1e1 / 0.8e1)*_t167*_t197;
  const double _t216 = -_hc4[2]*_t215;
  const double _t223 = _hc3[3]*_hc4[1];
  const double _t231 = _hc3[1]*_t80;
  const double _t232 = 0.2e1*_t87;
  const double _t233 = _hc3[2]*_t81;
  const double _t234 = _hc4[5]*_t73;
  const double _t235 = -_hc4[9]*_t21;
  const double _t236 = _hc4[8]*_t84 + _t235;
  const double _t237 = -_hc4[8]*_t21;
  const double _t238 = _hc4[7]*_t84 + _t237;
  const double _t239 = _hc4[4]*_t231 + _hc4[4]*_t233 - _t21*_t236 + _t234 + _t238*_t84;
  const double _t240 = _hc4[4]*_t73;
  const double _t241 = -_hc4[7]*_t21;
  const double _t242 = _hc4[6]*_t84 + _t241;
  const double _t243 = _hc4[3]*_t231 + _hc4[3]*_t233 - _t21*_t238 + _t240 + _t242*_t84;
  const double _t244 = _t117*_t228 + _t117*_t80 - _t21*_t239 + _t216 + _t221*_t27 + _t222*_t223 + _t230*_t85 + _t231*_t232 + _t232*_t233 + _t243*_t84;
  const double _t245 = my_piecewise3(_t17, 0, _hc5[0]*_t244);
  const double _t246 = 0.3e1*_t102;
  const double _t247 = 0.3e1*_t36;
  const double _t250 = _hc2[1]*_t249;
  const double _t252 = _hc2[6]*_t92;
  const double _t253 = _hc2[21]*_t31;
  const double _t254 = -_hc2[25]*_t97 - _t253*ta;
  const double _t255 = _t254*_t31;
  const double _t256 = _hc2[25]*_t31;
  const double _t257 = -_hc2[28]*_t97 - _t256*ta;
  const double _t258 = _t174*_t95 + _t252*ta - _t255*ta - _t257*_t97;
  const double _t259 = _t258*_t31;
  const double _t260 = _hc2[9]*_t92;
  const double _t262 = _t257*_t31;
  const double _t263 = _hc2[28]*_t31;
  const double _t264 = -_hc2[30]*_t97 - _t263*ta;
  const double _t265 = _hc2[11]*_t261 + _t260*ta - _t262*ta - _t264*_t97;
  const double _t266 = (0.56e2 / 0.9e1)*_t10*_t101*_t94 - _t250*ta - _t251*_t33 - _t259*ta - _t265*_t97 + (0.80e2 / 0.9e1)*_t91*_t98*ta;
  const double _t267 = -_t103*_t214;
  const double _t270 = _hc0[3]*_hc1[1];
  const double _t271 = _t109*_t8;
  const double _t274 = _hc0[1]*_hc1[3];
  const double _t275 = _t110 + _t273*_t274;
  const double _t276 = _hc0[2]*_t105;
  const double _t277 = 0.2e1*_t276;
  const double _t278 = _hc0[1]*_t79;
  const double _t279 = 0.2e1*_t278;
  const double _t280 = _hc1[5]*_t73;
  const double _t281 = -_hc1[9]*_t21;
  const double _t282 = _hc1[8]*_t108 + _t281;
  const double _t283 = -_hc1[8]*_t21;
  const double _t284 = _hc1[7]*_t108 + _t283;
  const double _t285 = _hc1[4]*_t276 + _hc1[4]*_t278 + _t108*_t284 - _t21*_t282 + _t280;
  const double _t286 = -_hc1[7]*_t21;
  const double _t287 = _hc1[6]*_t108 + _t286;
  const double _t288 = _hc1[4]*_t73;
  const double _t289 = _hc1[3]*_t276 + _t288;
  const double _t290 = _t108*_t287 - _t21*_t284 + _t274*_t79 + _t289;
  const double _t291 = _t108*_t290 + _t111*_t279 + _t124*_t227 + _t124*_t79 - _t21*_t285 + _t229*_t271 + _t267 + _t268*_t39 + _t269*_t270 + _t275*_t277;
  const double _t292 = my_piecewise3(_t16, 0, _hc1[0]*_t266 + _hc2[0]*_t291 + _t112*_t247 + _t246*_t40);
  const double _t293 = _t245 + _t292;
  const double _t295 = _t43*_t82;
  const double _t296 = _t223*_t81;
  const double _t297 = _hc3[1]*_t78;
  const double _t298 = _hc3[2]*_t26;
  const double _t299 = _t298*_t43;
  const double _t300 = _hc4[7]*_t115 + _t237;
  const double _t301 = _hc4[8]*_t115 + _t235;
  const double _t302 = -_t21*_t301 + _t234;
  const double _t303 = -_hc4[4]*_t297 + _hc4[4]*_t299 + _t300*_t84 + _t302;
  const double _t304 = _hc4[6]*_t115 + _t241;
  const double _t305 = _hc4[3]*_t43;
  const double _t306 = -_t21*_t300 + _t240;
  const double _t307 = -_hc4[3]*_t297 + _t298*_t305 + _t304*_t84 + _t306;
  const double _t308 = _t116*_t231 + _t116*_t233 - _t117*_t226 + _t118*_t73 - _t21*_t303 + _t216 + _t27*_t294 + _t295*_t80 + _t296*_t43 - _t297*_t87 + _t299*_t87 + _t307*_t84 + _t73*_t85;
  const double _t309 = my_piecewise3(_t17, 0, _hc5[0]*_t308 + _t53*_t88);
  const double _t312 = _t105*_t270;
  const double _t313 = _t106*_t44;
  const double _t314 = _hc0[1]*_t111;
  const double _t315 = _t110 + _t274*_t311;
  const double _t316 = _hc0[2]*_t38;
  const double _t317 = _t316*_t44;
  const double _t318 = _hc1[7]*_t122 + _t283;
  const double _t319 = _hc0[1]*_hc1[4];
  const double _t320 = _hc1[8]*_t122 + _t281;
  const double _t321 = -_t21*_t320 + _t280;
  const double _t322 = _hc1[4]*_t317 + _t108*_t318 + _t319*_t78 + _t321;
  const double _t323 = _hc1[6]*_t122 + _t286;
  const double _t324 = _t274*_t78;
  const double _t325 = -_t21*_t318 + _t288;
  const double _t326 = _hc1[3]*_t317 + _t108*_t323 + _t324 + _t325;
  const double _t327 = _t108*_t326 + _t109*_t73 + _t111*_t317 + _t123*_t278 + _t124*_t226 + _t125*_t73 - _t21*_t322 + _t267 + _t276*_t315 + _t310*_t39 + _t311*_t312 + _t313*_t79 + _t314*_t78;
  const double _t328 = my_piecewise3(_t16, 0, _hc2[0]*_t327 + _t102*_t45 + _t127*_t90);
  const double _t329 = 0.2e1*_t121 + 0.2e1*_t128;
  const double _t330 = _hc0[2]*_t130;
  const double _t331 = _hc1[3]*_t330;
  const double _t332 = _t122*_t323 + _t129*_t274 + _t325 + _t331;
  const double _t334 = 0.2e1*_t317;
  const double _t335 = _hc0[1]*_t123;
  const double _t336 = _hc1[4]*_t330 + _t122*_t318 + _t129*_t319 + _t321;
  const double _t337 = _t125*_t230 - _t21*_t336 + _t267;
  const double _t338 = _t108*_t332 + _t123*_t334 + _t124*_t129 - _t220*_t39 + _t226*_t313 + _t226*_t335 + _t270*_t333 + _t337 - _t39*_t77;
  const double _t339 = my_piecewise3(_t16, 0, _hc2[0]*_t338 + _t131*_t36);
  const double _t340 = _hc3[1]*_t146;
  const double _t341 = _hc3[2]*_t147;
  const double _t342 = _hc4[3]*_t340 + _hc4[3]*_t341 + _t115*_t304 + _t306;
  const double _t344 = _hc3[1]*_t116;
  const double _t345 = 0.2e1*_t116;
  const double _t346 = _hc4[4]*_t340 + _hc4[4]*_t341 + _t115*_t300 + _t302;
  const double _t347 = _t118*_t230 - _t21*_t346 + _t216;
  const double _t348 = _t117*_t146 + _t220*_t27 + _t223*_t343 - _t226*_t295 - _t226*_t344 + _t27*_t77 + _t299*_t345 + _t342*_t84 + _t347;
  const double _t349 = my_piecewise3(_t17, 0, _hc5[0]*_t348 + _t120*_t133 + _t145*_t28);
  const double _t353 = 0.2e1*_t335;
  const double _t354 = 0.2e1*_t330;
  const double _t356 = _t122*_t332 + _t129*_t313 + _t129*_t353 + _t270*_t352 + _t313*_t355 + _t315*_t354 + _t337 + _t351*_t39;
  const double _t357 = my_piecewise3(_t16, 0, _hc2[0]*_t356);
  const double _t358 = 0.3e1*_t145;
  const double _t359 = 0.3e1*_t53;
  const double _t362 = _hc5[1]*_t361;
  const double _t364 = _hc5[6]*_t135;
  const double _t365 = _hc5[21]*_t48;
  const double _t366 = -_hc5[25]*_t140 - _t365*tb;
  const double _t367 = _t366*_t48;
  const double _t368 = _hc5[25]*_t48;
  const double _t369 = -_hc5[28]*_t140 - _t368*tb;
  const double _t370 = _t138*_t183 - _t140*_t369 + _t364*tb - _t367*tb;
  const double _t371 = _t370*_t48;
  const double _t372 = _hc5[9]*_t135;
  const double _t374 = _t369*_t48;
  const double _t375 = _hc5[28]*_t48;
  const double _t376 = -_hc5[30]*_t140 - _t375*tb;
  const double _t377 = _hc5[11]*_t373 - _t140*_t376 + _t372*tb - _t374*tb;
  const double _t378 = (0.56e2 / 0.9e1)*_t13*_t137*_t144 + (0.80e2 / 0.9e1)*_t134*_t141*tb - _t140*_t377 - _t362*tb - _t363*_t50 - _t371*tb;
  const double _t381 = _t115*_t342 + _t146*_t295 + _t223*_t379 + _t27*_t350 + _t295*_t380 + _t340*_t345 + _t341*_t345 + _t347;
  const double _t382 = my_piecewise3(_t17, 0, _hc4[0]*_t378 + _hc5[0]*_t381 + _t148*_t359 + _t358*_t54);
  const double _t383 = _t357 + _t382;
  const double _t384 = 0.2e1*_t40;
  const double _t391 = _hc2[25]*_t58;
  const double _t393 = -_hc2[28]*_t151 - _hc2[9]*_t390 - _t391*_t392;
  const double _t394 = _t31*_t393;
  const double _t396 = -_hc2[11]*_t390 - _hc2[28]*_t395 - _hc2[30]*_t151;
  const double _t397 = _hc2[11]*_t385 + _hc2[9]*_t388*_t389 - _t101*_t390 + _t386*_t59 - _t394*ta - _t396*_t97;
  const double _t398 = my_piecewise3(_t16, 0, _hc1[0]*_t397 + _t112*_t158 + _t157*_t384);
  const double _t399 = my_piecewise3(_t17, 0, _t160*_t88);
  const double _t400 = my_piecewise3(_t16, 0, _t127*_t158 + _t157*_t45);
  const double _t401 = my_piecewise3(_t17, 0, _t120*_t160 + _t169*_t28);
  const double _t402 = my_piecewise3(_t16, 0, _t131*_t158);
  const double _t403 = 0.2e1*_t54;
  const double _t410 = _hc5[25]*_t63;
  const double _t412 = -_hc5[28]*_t163 - _hc5[9]*_t409 - _t410*_t411;
  const double _t413 = _t412*_t48;
  const double _t415 = -_hc5[11]*_t409 - _hc5[28]*_t414 - _hc5[30]*_t163;
  const double _t416 = _hc5[11]*_t404 + _hc5[9]*_t407*_t408 - _t140*_t415 - _t144*_t409 + _t405*_t64 - _t413*tb;
  const double _t417 = my_piecewise3(_t17, 0, _hc4[0]*_t416 + _t148*_t160 + _t169*_t403);
  const double _t419 = _hc2[6]*_t418;
  const double _t423 = -_hc2[21]*_t173 - _hc2[25]*_t422 - _t96;
  const double _t425 = -_hc2[25]*_t173 - _hc2[28]*_t422 - _t100;
  const double _t426 = _t174*_t421 + _t419*_t420 - _t423*_t424 - _t425*_t97 + _t93 - _t99;
  const double _t427 = my_piecewise3(_t16, 0, _hc1[0]*_t426 + _t112*_t67 + _t176*_t384);
  const double _t428 = my_piecewise3(_t17, 0, _t69*_t88);
  const double _t429 = my_piecewise3(_t16, 0, _t127*_t67 + _t176*_t45);
  const double _t430 = my_piecewise3(_t17, 0, _t120*_t69 + _t185*_t28);
  const double _t431 = my_piecewise3(_t16, 0, _t131*_t67);
  const double _t433 = _hc5[6]*_t432;
  const double _t437 = -_hc5[21]*_t182 - _hc5[25]*_t436 - _t139;
  const double _t439 = -_hc5[25]*_t182 - _hc5[28]*_t436 - _t143;
  const double _t440 = _t136 - _t140*_t439 - _t142 + _t183*_t435 + _t433*_t434 - _t437*_t438;
  const double _t441 = my_piecewise3(_t17, 0, _hc4[0]*_t440 + _t148*_t69 + _t185*_t403);
  const double _t442 = _t189*_t30;
  const double _t443 = _t11*_t192;
  const double _t445 = (0.1e1 / 0.3e1)*_hc2[30];
  const double _t446 = _hc2[28]*_t188;
  const double _t447 = _t418*_t446;
  const double _t449 = -0.1e1 / 0.3e1*_hc2[11]*_t444 + (0.1e1 / 0.3e1)*_hc2[3]*_t190*_t34 + (0.5e1 / 0.12e2)*_hc2[9]*_t155*_t190*ta - _t388*_t445 - _t447*_t448;
  const double _t450 = my_piecewise3(_t16, 0, _hc1[0]*_t449 + _t40*_t442 - _t40*_t443);
  const double _t451 = _t196*_t47;
  const double _t452 = _t14*_t199;
  const double _t453 = my_piecewise3(_t17, 0, _t28*_t451 - _t28*_t452);
  const double _t454 = my_piecewise3(_t16, 0, _t442*_t45 - _t443*_t45);
  const double _t456 = (0.1e1 / 0.3e1)*_hc5[30];
  const double _t457 = _hc5[28]*_t195;
  const double _t458 = _t432*_t457;
  const double _t460 = -0.1e1 / 0.3e1*_hc5[11]*_t455 + (0.1e1 / 0.3e1)*_hc5[3]*_t197*_t51 + (0.5e1 / 0.12e2)*_hc5[9]*_t167*_t197*tb - _t407*_t456 - _t458*_t459;
  const double _t461 = my_piecewise3(_t17, 0, _hc4[0]*_t460 + _t451*_t54 - _t452*_t54);
  const double _t467 = -_hc2[28]*_t462 - _t153*_t463 - _t391*_t466;
  const double _t468 = _t201*_t203;
  const double _t469 = my_piecewise3(_t16, 0, _hc1[0]*_t467 + _t40*_t468);
  const double _t470 = _t205*_t207;
  const double _t471 = my_piecewise3(_t17, 0, _t28*_t470);
  const double _t472 = my_piecewise3(_t16, 0, _t45*_t468);
  const double _t478 = -_hc5[28]*_t473 - _t165*_t474 - _t410*_t477;
  const double _t479 = my_piecewise3(_t17, 0, _hc4[0]*_t478 + _t470*_t54);
  const double _t482 = _hc2[21]*_t481;
  const double _t483 = _hc2[25]*_t10;
  const double _t485 = -_hc2[6]*_t480 - _t172*_t482 - _t483*_t484;
  const double _t486 = my_piecewise3(_t16, 0, _hc1[0]*_t485 + _t209*_t40);
  const double _t487 = my_piecewise3(_t17, 0, _t211*_t28);
  const double _t488 = my_piecewise3(_t16, 0, _t209*_t45);
  const double _t491 = _hc5[21]*_t490;
  const double _t492 = _hc5[25]*_t13;
  const double _t494 = -_hc5[6]*_t489 - _t181*_t491 - _t492*_t493;
  const double _t495 = my_piecewise3(_t17, 0, _hc4[0]*_t494 + _t211*_t54);
  const double _t497 = (0.3e1 / 0.8e1)*_hc2[11]*_t496;
  const double _t499 = _hc2[3]*_t498;
  const double _t500 = (0.3e1 / 0.8e1)*_t499;
  const double _t501 = _hc1[0]*_hc2[30];
  const double _t503 = my_piecewise3(_t16, 0, -_t187*_t497 + _t500*_t57 + _t501*_t502);
  const double _t505 = (0.3e1 / 0.8e1)*_hc5[11]*_t504;
  const double _t507 = _hc5[3]*_t506;
  const double _t508 = (0.3e1 / 0.8e1)*_t507;
  const double _t509 = _hc4[0]*_hc5[30];
  const double _t511 = my_piecewise3(_t17, 0, -_t194*_t505 + _t508*_t62 + _t509*_t510);
  const double _t512 = _hc1[0]*_t171;
  const double _t513 = (0.1e1 / 0.4e1)*_t446;
  const double _t514 = _hc2[9]*_t190;
  const double _t515 = (0.1e1 / 0.4e1)*_t514;
  const double _t516 = my_piecewise3(_t16, 0, -_t202*_t515 + _t512*_t513);
  const double _t517 = _hc4[0]*_t180;
  const double _t518 = (0.1e1 / 0.4e1)*_t457;
  const double _t519 = _hc5[9]*_t197;
  const double _t520 = (0.1e1 / 0.4e1)*_t519;
  const double _t521 = my_piecewise3(_t17, 0, -_t206*_t520 + _t517*_t518);
  const double _t522 = _hc1[0]*_t248;
  const double _t523 = (0.1e1 / 0.2e1)*_t391;
  const double _t524 = my_piecewise3(_t16, 0, _t522*_t523);
  const double _t525 = _hc4[0]*_t360;
  const double _t526 = (0.1e1 / 0.2e1)*_t410;
  const double _t527 = my_piecewise3(_t17, 0, _t525*_t526);
  const double _t528 = _hc2[21]*_t387;
  const double _t529 = my_piecewise3(_t16, 0, _hc1[0]*_t528);
  const double _t530 = _hc5[21]*_t406;
  const double _t531 = my_piecewise3(_t17, 0, _hc4[0]*_t530);
  const double d3F_dna3 = 0.3e1*_t113 + _t293*_t3 + 0.3e1*_t89;
  const double d3F_dna2_dnb = _t114 + _t3*(_t309 + _t328) + _t329;
  const double d3F_dna_dnb2 = _t150 + _t3*(_t339 + _t349) + _t329;
  const double d3F_dnb3 = 0.3e1*_t132 + 0.3e1*_t149 + _t3*_t383;
  const double d3F_dna2_dgaa = 0.2e1*_t159 + _t3*_t398;
  const double d3F_dna2_dgbb = 0.2e1*_t161 + _t3*_t399;
  const double d3F_dna_dnb_dgaa = _t159 + _t162 + _t3*_t400;
  const double d3F_dna_dnb_dgbb = _t161 + _t170 + _t3*_t401;
  const double d3F_dnb2_dgaa = 0.2e1*_t162 + _t3*_t402;
  const double d3F_dnb2_dgbb = 0.2e1*_t170 + _t3*_t417;
  const double d3F_dna2_dta = 0.2e1*_t177 + _t3*_t427;
  const double d3F_dna2_dtb = 0.2e1*_t178 + _t3*_t428;
  const double d3F_dna_dnb_dta = _t177 + _t179 + _t3*_t429;
  const double d3F_dna_dnb_dtb = _t178 + _t186 + _t3*_t430;
  const double d3F_dnb2_dta = 0.2e1*_t179 + _t3*_t431;
  const double d3F_dnb2_dtb = 0.2e1*_t186 + _t3*_t441;
  const double d3F_dna_dgaa2 = _t193 + _t3*_t450;
  const double d3F_dna_dgbb2 = _t200 + _t3*_t453;
  const double d3F_dnb_dgaa2 = _t193 + _t3*_t454;
  const double d3F_dnb_dgbb2 = _t200 + _t3*_t461;
  const double d3F_dna_dgaa_dta = _t204 + _t3*_t469;
  const double d3F_dna_dgbb_dtb = _t208 + _t3*_t471;
  const double d3F_dnb_dgaa_dta = _t204 + _t3*_t472;
  const double d3F_dnb_dgbb_dtb = _t208 + _t3*_t479;
  const double d3F_dna_dta2 = _t210 + _t3*_t486;
  const double d3F_dna_dtb2 = _t212 + _t3*_t487;
  const double d3F_dnb_dta2 = _t210 + _t3*_t488;
  const double d3F_dnb_dtb2 = _t212 + _t3*_t495;
  const double d3F_dgaa3 = _t3*_t503;
  const double d3F_dgbb3 = _t3*_t511;
  const double d3F_dgaa2_dta = _t3*_t516;
  const double d3F_dgbb2_dtb = _t3*_t521;
  const double d3F_dgaa_dta2 = _t3*_t524;
  const double d3F_dgbb_dtb2 = _t3*_t527;
  const double d3F_dta3 = _t3*_t529;
  const double d3F_dtb3 = _t3*_t531;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 2] += d3F_dna2_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 3] += d3F_dna_dnb_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 5] += d3F_dna_dnb_dgbb;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 6] += d3F_dnb2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 1] += d3F_dna2_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 2] += d3F_dna_dnb_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 3] += d3F_dna_dnb_dtb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 4] += d3F_dnb2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 5] += d3F_dna_dgbb2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 6] += d3F_dnb_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 5] += d3F_dna_dgbb_dtb;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 6] += d3F_dnb_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += d3F_dnb_dgbb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 2] += d3F_dna_dtb2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 3] += d3F_dnb_dta2;
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
  const double _t532 = (0.140e3 / 0.81e2)/xc_powr(_t3, 13, 3);
  const double _t534 = 0.24e2*_t218;
  const double _t535 = 0.24e2*_t2/xc_powi(_t3, 5);
  const double _t536 = -_t534 + _t535;
  const double _t538 = 0.12e2*_t76;
  const double _t539 = 0.12e2*_t218;
  const double _t540 = _t2*_t539;
  const double _t541 = -_t538 + _t540;
  const double _t543 = 0.6e1*_t24;
  const double _t544 = _t2*_t217;
  const double _t545 = (0.14e2 / 0.9e1)*_t213;
  const double _t551 = (0.2e1 / 0.3e1)*_t71*_t8;
  const double _t569 = _t249*ta;
  const double _t570 = _t92*ta;
  const double _t577 = 0.6e1*na - 0.6e1*nb;
  const double _t578 = 0.4e1*na - 0.4e1*nb;
  const double _t579 = 0.2e1*na - 0.2e1*nb;
  const double _t580 = _t579*_t76 - _t75;
  const double _t602 = _t535 - _t539;
  const double _t613 = _t540 - 0.4e1*_t76;
  const double _t616 = (0.28e2 / 0.27e2)*_t213;
  const double _t621 = 0.8e1*_t2*_t76;
  const double _t624 = _t105*_t311;
  const double _t626 = _t44*_t79;
  const double _t636 = 0.2e1*_t310;
  const double _t641 = 0.2e1*_t626;
  const double _t643 = 0.2e1*_t624;
  const double _t664 = 0.8e1*(_t2 * _t2)/xc_powi(_t3, 6);
  const double _t665 = _t616*_t8;
  const double _t677 = _t579*_t76 + _t75;
  const double _t686 = 0.18e2*_t219;
  const double _t688 = 0.3e1*_t129;
  const double _t692 = _t2*_t538;
  const double _t693 = _t545*_t8;
  const double _t702 = _t534 + _t535;
  const double _t703 = _t538 + _t540;
  const double _t704 = _t361*tb;
  const double _t705 = _t135*tb;
  const double _t712 = _t388*_t389;
  const double _t721 = _t407*_t408;
  const double _t724 = xc_powr(na, -19, 3);
  const double _t725 = _t418*_t420;
  const double _t729 = xc_powr(nb, -19, 3);
  const double _t730 = _t432*_t434;
  const double _t732 = (0.1e1 / 0.3e1)*_t388;
  const double _t733 = _t188*_t448;
  const double _t734 = _t418*_t733;
  const double _t735 = (0.1e1 / 0.3e1)*_t407;
  const double _t736 = _t195*_t459;
  const double _t737 = _t432*_t736;
  const double _t738 = xc_powr(na, -20, 3);
  const double _t739 = _t463*_t58;
  const double _t740 = _t466*_t58;
  const double _t741 = xc_powr(nb, -20, 3);
  const double _t742 = _t474*_t63;
  const double _t743 = _t477*_t63;
  const double _t744 = xc_powi(na, -7);
  const double _t745 = _t172*_t481;
  const double _t746 = _t10*_t484;
  const double _t747 = xc_powi(nb, -7);
  const double _t748 = _t181*_t490;
  const double _t749 = _t13*_t493;
  const double _t754 = _t155*_t498;
  const double _t759 = _t167*_t506;
  const double _t533 = _hc4[2]*_t532*_t8;
  const double _t537 = _hc3[4]*_hc4[1];
  const double _t542 = _t80*_t82;
  const double _t546 = _t8*_t85;
  const double _t547 = _hc3[1]*_t221;
  const double _t548 = 0.3e1*_t87;
  const double _t549 = _hc3[3]*_t222;
  const double _t550 = _t298*_t548;
  const double _t552 = 0.3e1*_t243;
  const double _t553 = -_hc4[5]*_t215;
  const double _t554 = _hc4[4]*_t298;
  const double _t555 = 0.2e1*_t238;
  const double _t556 = _hc4[9]*_t73;
  const double _t557 = -_hc4[14]*_t21;
  const double _t558 = -_hc4[13]*_t21;
  const double _t559 = _hc4[12]*_t84 + _t558;
  const double _t560 = _hc4[8]*_t73;
  const double _t561 = -_hc4[12]*_t21;
  const double _t562 = _hc4[11]*_t84 + _t561;
  const double _t563 = _hc4[7]*_t231 + _hc4[7]*_t233 - _t21*_t559 + _t560 + _t562*_t84;
  const double _t564 = -_hc4[4]*_t215;
  const double _t565 = _hc4[3]*_t298;
  const double _t566 = 0.2e1*_t242;
  const double _t567 = _hc4[7]*_t73;
  const double _t568 = -_hc4[11]*_t21;
  const double _t571 = -_hc2[61]*_t424 - _hc2[65]*_t97;
  const double _t572 = -_hc2[65]*_t424 - _hc2[68]*_t97;
  const double _t573 = _hc2[25]*_t570 + _hc2[28]*_t261 - _t424*_t571 - _t572*_t97;
  const double _t574 = _t103*_t532;
  const double _t575 = _hc0[4]*_hc1[1];
  const double _t576 = _t106*_t79;
  const double _t581 = _hc0[3]*_t269;
  const double _t582 = _t111*_t316;
  const double _t583 = 0.3e1*_t582;
  const double _t584 = _hc0[1]*_t273;
  const double _t585 = _hc1[6]*_t584 + _t286;
  const double _t586 = -0.1e1 / 0.36e2*_hc1[8]*_t19*_t6*_t7;
  const double _t587 = _hc1[7]*_t584;
  const double _t588 = -_hc1[5]*_t215;
  const double _t589 = _hc1[4]*_t316;
  const double _t590 = _hc1[9]*_t73;
  const double _t591 = -_hc1[14]*_t21;
  const double _t592 = -_hc1[13]*_t21;
  const double _t593 = _hc1[12]*_t108 + _t592;
  const double _t594 = _hc1[8]*_t73;
  const double _t595 = -_hc1[12]*_t21;
  const double _t596 = _hc1[11]*_t108 + _t595;
  const double _t597 = _hc1[7]*_t276 + _hc1[7]*_t278 + _t108*_t596 - _t21*_t593 + _t594;
  const double _t598 = -_hc1[4]*_t215;
  const double _t599 = _hc1[3]*_t316;
  const double _t600 = _hc1[7]*_t73;
  const double _t601 = -_hc1[11]*_t21;
  const double _t603 = _hc3[1]*_t294;
  const double _t604 = _hc3[2]*_t80;
  const double _t605 = _hc3[3]*_t81;
  const double _t606 = _hc4[11]*_t115 + _t561;
  const double _t607 = _hc4[12]*_t115 + _t558;
  const double _t608 = -_t21*_t607 + _t560;
  const double _t609 = -_hc4[7]*_t297 + _hc4[7]*_t299 + _t606*_t84 + _t608;
  const double _t610 = _hc4[10]*_t115 + _t568;
  const double _t611 = -_t21*_t606 + _t567;
  const double _t612 = 0.2e1*_t307;
  const double _t614 = _t116*_t298;
  const double _t615 = _t232*_t43;
  const double _t617 = _hc4[4]*_t43;
  const double _t618 = -_t21*(_hc4[13]*_t115 + _t557) + _t556;
  const double _t619 = _t223*_t26*_t43;
  const double _t620 = _t298*_t87;
  const double _t622 = _t230*_t303 + _t533;
  const double _t623 = _hc0[3]*_hc1[3];
  const double _t625 = _hc0[2]*_hc1[3];
  const double _t627 = _hc0[1]*_t78;
  const double _t628 = _hc0[1]*_t311;
  const double _t629 = _hc1[6]*_t628 + _t286;
  const double _t630 = _hc1[11]*_t122 + _t595;
  const double _t631 = _hc1[12]*_t122 + _t592;
  const double _t632 = -_t21*_t631 + _t594;
  const double _t633 = _hc1[7]*_t317 + _hc1[7]*_t627 + _t108*_t630 + _t632;
  const double _t634 = _hc1[10]*_t122 + _t601;
  const double _t635 = -_t21*_t630 + _t600;
  const double _t637 = _hc1[7]*_t628;
  const double _t638 = _t20*(-_t586 - 0.1e1 / 0.6e1*_t637) + _t288;
  const double _t639 = _t123*_t316;
  const double _t640 = _hc0[2]*_t111;
  const double _t642 = _hc0[3]*_t275;
  const double _t644 = _hc0[3]*_hc1[4];
  const double _t645 = _hc0[2]*_hc1[4];
  const double _t646 = _t283 + _t637;
  const double _t647 = -_t21*(_hc1[13]*_t122 + _t591) + _t590;
  const double _t648 = _t270*_t38;
  const double _t649 = _t44*_t648;
  const double _t650 = _t230*_t322 + _t574;
  const double _t651 = -_t27*_t535;
  const double _t652 = _hc4[6]*_t340 + _hc4[6]*_t341 + _t115*_t610 + _t611;
  const double _t653 = _hc3[1]*_t77;
  const double _t654 = _hc3[3]*_t343;
  const double _t655 = _hc3[1]*_t226;
  const double _t656 = 0.2e1*_t304;
  const double _t657 = _hc3[1]*_t220;
  const double _t658 = _hc3[2]*_t305;
  const double _t659 = _hc4[7]*_t340 + _hc4[7]*_t341 + _t115*_t606 + _t608;
  const double _t660 = -_t21*_t659 + _t230*_t300 + _t564;
  const double _t661 = _t147*_t223;
  const double _t662 = 0.2e1*_t295;
  const double _t663 = _t345*_t43;
  const double _t666 = 0.2e1*_t300;
  const double _t667 = _hc3[2]*_t617;
  const double _t668 = -_t21*(_hc4[8]*_t340 + _hc4[8]*_t341 + _t115*_t607 + _t618) + _t230*_t301 + _t553;
  const double _t669 = _hc3[2]*_t43;
  const double _t670 = _t39*_t535;
  const double _t671 = _hc0[1]*_t129;
  const double _t672 = _hc1[6]*_t330 + _hc1[6]*_t671 + _t122*_t634 + _t635;
  const double _t673 = _hc0[1]*_t226;
  const double _t674 = _t44*_t625;
  const double _t675 = _hc1[7]*_t330 + _hc1[7]*_t671 + _t122*_t630 + _t632;
  const double _t676 = -_t21*_t675 + _t230*_t318 + _t598;
  const double _t678 = _t274*_t677 + _t331 + _t628*_t629 + _t638;
  const double _t679 = _t130*_t270;
  const double _t680 = _hc0[2]*_t123;
  const double _t681 = _t44*_t645;
  const double _t682 = -_t21*(_hc1[8]*_t330 + _hc1[8]*_t671 + _t122*_t631 + _t647) + _t230*_t320 + _t588;
  const double _t683 = _hc0[3]*_t352;
  const double _t684 = 0.2e1*_t671;
  const double _t685 = _hc1[3]*_t683 + _t122*_t672 + _t129*_t674 + _t274*_t351 + _t323*_t684 + _t354*_t629 + _t355*_t674 + _t676;
  const double _t687 = 0.3e1*_t332;
  const double _t689 = 0.3e1*_t315;
  const double _t690 = _t106*_t129;
  const double _t691 = _t44*_t680;
  const double _t694 = -_t125*_t693 - _t21*(_hc1[4]*_t683 + _t122*_t675 + _t129*_t681 + _t318*_t684 + _t319*_t351 + _t354*_t646 + _t355*_t681 + _t682) + _t336*_t551 + _t574;
  const double _t695 = _hc3[1]*_t350;
  const double _t696 = _hc3[3]*_t379;
  const double _t697 = _hc4[3]*_t695 + _hc4[3]*_t696 + _t115*_t652 + _t146*_t658 + _t340*_t656 + _t341*_t656 + _t380*_t658 + _t660;
  const double _t698 = 0.3e1*_t342;
  const double _t699 = 0.3e1*_t116;
  const double _t700 = _t146*_t82;
  const double _t701 = -_t118*_t693 - _t21*(_hc4[4]*_t695 + _hc4[4]*_t696 + _t115*_t659 + _t146*_t667 + _t340*_t666 + _t341*_t666 + _t380*_t667 + _t668) + _t346*_t551 + _t533;
  const double _t706 = -_hc5[61]*_t438 - _hc5[65]*_t140;
  const double _t707 = -_hc5[65]*_t438 - _hc5[68]*_t140;
  const double _t708 = _hc5[25]*_t705 + _hc5[28]*_t373 - _t140*_t707 - _t438*_t706;
  const double _t709 = _t669*_t699;
  const double _t710 = 0.3e1*_t40;
  const double _t711 = 0.3e1*_t112;
  const double _t713 = -_hc2[28]*_t390 - _hc2[65]*_t395 - _hc2[68]*_t151;
  const double _t714 = _hc2[68]*_t58;
  const double _t715 = 0.2e1*_t400;
  const double _t716 = 0.2e1*_t127;
  const double _t717 = 0.2e1*_t401;
  const double _t718 = 0.2e1*_t120;
  const double _t719 = 0.3e1*_t54;
  const double _t720 = 0.3e1*_t148;
  const double _t722 = -_hc5[28]*_t409 - _hc5[65]*_t414 - _hc5[68]*_t163;
  const double _t723 = _hc5[68]*_t63;
  const double _t726 = -_hc2[61]*_t173 - _hc2[65]*_t422 - _t256;
  const double _t727 = 0.2e1*_t429;
  const double _t728 = 0.2e1*_t430;
  const double _t731 = -_hc5[61]*_t182 - _hc5[65]*_t436 - _t368;
  const double _t750 = _t30*_t497;
  const double _t751 = _t11*_t500;
  const double _t752 = _hc2[30]*_t502;
  const double _t753 = _hc2[68]*_t190;
  const double _t755 = _t47*_t505;
  const double _t756 = _t14*_t508;
  const double _t757 = _hc5[30]*_t510;
  const double _t758 = _hc5[68]*_t197;
  const double _t760 = _t171*_t513;
  const double _t761 = _t201*_t515;
  const double _t762 = _hc2[65]*_t744;
  const double _t763 = _t180*_t518;
  const double _t764 = _t205*_t520;
  const double _t765 = _hc5[65]*_t747;
  const double _t766 = _hc2[61]/xc_powr(na, 22, 3);
  const double _t767 = _t248*_t523;
  const double _t768 = _t360*_t526;
  const double _t769 = _hc5[61]/xc_powr(nb, 22, 3);
  const double d4F_dna4 = 0.4e1*_t245 + 0.4e1*_t292 + _t3*(my_piecewise3(_t16, 0, _hc1[0]*((0.6160e4 / 0.81e2)*_hc2[1]*_t465 - 0.280e3 / 0.9e1*_t10*_t101*_t171 + (0.28e2 / 0.3e1)*_t10*_t265*_t94 - 0.440e3 / 0.9e1*_t248*_t98*ta + (0.40e2 / 0.3e1)*_t258*_t91*ta + (0.3640e4 / 0.81e2)*_t33*_t418 - _t424*(-_hc2[6]*_t569 + (0.56e2 / 0.9e1)*_t10*_t257*_t94 - _t174*_t251 + (0.80e2 / 0.9e1)*_t254*_t91*ta - _t424*(_hc2[21]*_t570 + _hc2[25]*_t261 - _t424*(-_hc2[56]*_t424 - _hc2[61]*_t97) - _t571*_t97) - _t573*_t97) - _t97*(-_hc2[11]*_t10*_t251 - _hc2[9]*_t569 + (0.56e2 / 0.9e1)*_t10*_t264*_t94 + (0.80e2 / 0.9e1)*_t257*_t91*ta - _t424*_t573 - _t97*(_hc2[28]*_t570 + _hc2[30]*_t261 - _t424*_t572 - _t97*(-_hc2[68]*_t424 - _hc2[70]*_t97)))) + _hc2[0]*(_t106*(_t79 * _t79) + _t108*(_hc1[3]*_t581 + _t108*(_hc1[6]*_t276 + _hc1[6]*_t278 + _t108*(_hc1[10]*_t108 + _t601) - _t21*_t596 + _t600) - _t21*_t597 + _t227*_t599 + _t230*_t284 + _t268*_t274 + _t277*_t585 + _t279*_t287 + _t598 + _t599*_t79) + 0.2e1*_t124*_t268 - _t124*_t541 - _t21*(_hc1[4]*_t581 + _t108*_t597 - _t21*(_hc1[8]*_t276 + _hc1[8]*_t278 + _t108*_t593 - _t21*(_hc1[13]*_t108 + _t591) + _t590) + _t227*_t589 + _t230*_t282 + _t268*_t319 + _t277*(_t283 + _t587) + _t279*_t284 + _t588 + _t589*_t79) + _t227*_t576 + _t227*_t583 + 0.3e1*_t268*_t314 - _t271*_t545 + 0.3e1*_t275*_t581 + 0.3e1*_t276*(_t20*(-_t586 - 0.1e1 / 0.6e1*_t587) + _t274*_t580 + _t289 + _t584*_t585) + 0.3e1*_t278*_t290 + _t285*_t551 + _t312*_t580 + _t312*(-_t224 + _t578*_t76) + _t312*(-_t543 + _t577*_t76) + (_t38 * _t38 * _t38 * _t38)*_t575 + _t39*_t536 + _t574 + _t583*_t79) + 0.6e1*_t102*_t112 + 0.4e1*_t266*_t40 + 0.4e1*_t291*_t36) + my_piecewise3(_t17, 0, _hc5[0]*(0.2e1*_t117*_t221 + _t117*_t541 - _t21*(_hc4[4]*_t547 + _hc4[4]*_t549 - _t21*(_hc4[8]*_t231 + _hc4[8]*_t233 - _t21*(_hc4[13]*_t84 + _t557) + _t556 + _t559*_t84) + _t228*_t554 + _t230*_t236 + _t231*_t555 + _t233*_t555 + _t553 + _t554*_t80 + _t563*_t84) + _t228*_t296 + _t228*_t542 + _t228*_t550 + _t231*_t552 + _t233*_t552 + _t239*_t551 + (_t26 * _t26 * _t26 * _t26)*_t537 - _t27*_t536 + _t296*_t80 + _t296*(_t543 - _t544) + _t533 - _t545*_t546 + _t547*_t548 + _t548*_t549 + _t550*_t80 + (_t80 * _t80)*_t82 + _t84*(_hc4[3]*_t547 + _hc4[3]*_t549 - _t21*_t563 + _t228*_t565 + _t230*_t238 + _t231*_t566 + _t233*_t566 + _t564 + _t565*_t80 + _t84*(_hc4[6]*_t231 + _hc4[6]*_t233 - _t21*_t562 + _t567 + _t84*(_hc4[10]*_t84 + _t568))))));
  const double d4F_dna3_dnb = _t293 + _t3*(my_piecewise3(_t16, 0, _hc2[0]*(_t106*_t227*_t78 + _t108*(_t108*(_hc1[6]*_t317 + _hc1[6]*_t627 + _t108*_t634 + _t635) - _t21*_t633 + _t226*_t599 + _t274*_t310 + _t276*_t629 + _t278*_t323 + _t284*_t73 + _t287*_t317 + _t287*_t627 + _t318*_t73 + _t598 + _t623*_t624 + _t625*_t626) + _t124*_t310 - _t124*_t613 - _t125*_t215 - _t21*(_t108*_t633 - _t21*(_hc1[8]*_t317 + _hc1[8]*_t627 + _t108*_t631 + _t647) + _t226*_t589 + _t276*_t646 + _t278*_t318 + _t282*_t73 + _t284*_t317 + _t284*_t627 + _t310*_t319 + _t320*_t73 + _t588 + _t624*_t644 + _t626*_t645) + _t227*_t639 + _t227*_t649 + _t268*_t313 + _t268*_t335 + _t269*_t311*_t575 - _t271*_t616 + _t277*(_t273*_t311*_t625 + _t324 + _t584*_t629 + _t638) + _t279*_t326 + _t285*_t73 + _t290*_t317 + _t290*_t627 + _t312*_t544 + _t314*_t636 + _t315*_t581 + _t39*_t602 + _t576*_t78 + _t582*_t621 + _t626*_t648 + _t639*_t79 + _t640*_t641 + _t642*_t643 + _t650) + _t127*_t246 + _t247*_t327 + _t266*_t45) + my_piecewise3(_t17, 0, _hc5[0]*(_t116*_t547 + _t116*_t549 + _t117*_t294 + _t117*_t613 - _t118*_t215 - _t21*(_hc4[4]*_t603 - _t21*(-_hc4[8]*_t297 + _hc4[8]*_t299 + _t607*_t84 + _t618) - _t226*_t554 + _t231*_t300 + _t233*_t300 + _t236*_t73 - _t238*_t297 + _t238*_t299 + _t301*_t73 + _t553 + _t604*_t617 + _t605*_t617 + _t609*_t84) + _t221*_t295 + _t222*_t43*_t537 + _t228*_t614 + _t228*_t619 - _t228*_t78*_t82 + _t231*_t612 + _t232*_t603 + _t233*_t612 + _t239*_t73 - _t243*_t297 + _t243*_t299 - _t27*_t602 - _t296*_t544 - _t542*_t78 - _t546*_t616 + _t604*_t615 + _t605*_t615 + _t614*_t80 + _t619*_t80 - _t620*_t621 + _t622 + _t84*(_hc4[3]*_t603 - _t21*_t609 - _t226*_t565 + _t231*_t304 + _t233*_t304 + _t238*_t73 - _t242*_t297 + _t242*_t299 + _t300*_t73 + _t305*_t604 + _t305*_t605 + _t564 + _t84*(-_hc4[6]*_t297 + _hc4[6]*_t299 + _t610*_t84 + _t611))) + _t244*_t53)) + 0.3e1*_t309 + 0.3e1*_t328;
  const double d4F_dna2_dnb2 = _t3*(my_piecewise3(_t16, 0, _hc2[0]*(_hc0[3]*_t315*_t643 + _t105*_t130*_t575 + _t106*_t664 + _t108*(_t108*_t672 + _t129*_t599 - _t220*_t274 + _t226*_t674 - _t274*_t77 + _t323*_t334 + _t323*_t673 + _t333*_t623 + _t676) - _t124*_t225 - _t124*_t540 - _t125*_t665 + _t129*_t576 + _t129*_t582 - _t21*(_t108*_t675 + _t129*_t589 - _t220*_t319 + _t226*_t681 + _t318*_t334 + _t318*_t673 - _t319*_t77 + _t333*_t644 + _t682) - _t214*_t271 - _t220*_t314 + _t226*_t44*_t640 + _t276*_t678 + _t278*_t332 + _t310*_t353 + _t312*_t677 + _t313*_t636 - _t314*_t77 + _t326*_t334 + _t326*_t673 + _t333*_t642 + _t336*_t73 + _t580*_t679 + _t621*_t639 + _t621*_t649 + _t641*_t680 + _t650 + _t670) + _t102*_t131 + _t338*_t90) + my_piecewise3(_t17, 0, _hc5[0]*(_t117*_t225 + _t117*_t540 - _t118*_t665 + _t146*_t296 + _t146*_t542 + _t146*_t620 + _t147*_t537*_t81 - _t21*(_hc4[4]*_t653 + _hc4[4]*_t654 + _hc4[4]*_t657 + _t146*_t554 - _t226*_t667 + _t299*_t666 - _t300*_t655 + _t659*_t84 + _t668) - _t215*_t85 - _t226*_t669*_t87 + _t231*_t342 + _t233*_t342 + _t294*_t662 + _t299*_t612 - _t307*_t655 + _t345*_t603 + _t346*_t73 + _t604*_t663 + _t605*_t663 - _t614*_t621 - _t619*_t621 + _t622 + _t651 + _t653*_t87 + _t654*_t87 + _t657*_t87 + _t661*_t80 + _t664*_t82 + _t84*(_hc4[3]*_t653 + _hc4[3]*_t654 + _hc4[3]*_t657 + _t146*_t565 - _t226*_t658 + _t299*_t656 - _t304*_t655 + _t652*_t84 + _t660)) + _t133*_t308 + _t145*_t88)) + 0.2e1*_t309 + 0.2e1*_t328 + 0.2e1*_t339 + 0.2e1*_t349;
  const double d4F_dna_dnb3 = _t3*(my_piecewise3(_t16, 0, _hc2[0]*(_hc0[1]*_t332*_t544 + _hc0[3]*_t333*_t689 + _t108*_t685 + _t124*_t351 + _t129*_t649 - _t217*_t313 - _t217*_t335 + _t273*_t352*_t575 - _t313*_t686 + _t317*_t687 - _t335*_t686 + _t355*_t649 + _t39*_t539 + _t544*_t679 + _t544*_t690 + _t639*_t688 + _t670 + _t691*_t692 + _t694) + _t356*_t36) + my_piecewise3(_t17, 0, _hc5[0]*(-_hc3[1]*_t342*_t544 - _t116*_t669*_t692 + _t117*_t350 + 0.3e1*_t146*_t614 + _t146*_t619 + _t217*_t295 + _t217*_t344 + _t26*_t379*_t537 - _t27*_t539 + _t295*_t686 + _t299*_t698 + _t344*_t686 + _t380*_t619 - _t544*_t661 - _t544*_t700 + _t651 + _t654*_t699 + _t697*_t84 + _t701) + _t120*_t358 + _t28*_t378 + _t348*_t359)) + 0.3e1*_t339 + 0.3e1*_t349 + _t383;
  const double d4F_dnb4 = _t3*(my_piecewise3(_t16, 0, _hc2[0]*(_t106*(_t129 * _t129) + _t122*_t685 + 0.2e1*_t313*_t351 - _t313*_t703 + 0.3e1*_t330*_t678 + 0.3e1*_t335*_t351 + _t355*_t690 + 0.3e1*_t355*_t691 + _t39*_t702 + (_t44 * _t44 * _t44 * _t44)*_t575 + _t671*_t687 + _t677*_t679 + _t679*(_t224 + _t578*_t76) + _t679*(_t543 + _t577*_t76) + _t683*_t689 + _t688*_t691 + _t694)) + my_piecewise3(_t17, 0, _hc4[0]*((0.6160e4 / 0.81e2)*_hc5[1]*_t476 + (0.28e2 / 0.3e1)*_t13*_t137*_t377 - 0.280e3 / 0.9e1*_t13*_t144*_t180 + (0.40e2 / 0.3e1)*_t134*_t370*tb - _t140*(-_hc5[11]*_t13*_t363 - _hc5[9]*_t704 + (0.56e2 / 0.9e1)*_t13*_t137*_t376 + (0.80e2 / 0.9e1)*_t134*_t369*tb - _t140*(_hc5[28]*_t705 + _hc5[30]*_t373 - _t140*(-_hc5[68]*_t438 - _hc5[70]*_t140) - _t438*_t707) - _t438*_t708) - 0.440e3 / 0.9e1*_t141*_t360*tb + (0.3640e4 / 0.81e2)*_t432*_t50 - _t438*(-_hc5[6]*_t704 + (0.56e2 / 0.9e1)*_t13*_t137*_t369 + (0.80e2 / 0.9e1)*_t134*_t366*tb - _t140*_t708 - _t183*_t363 - _t438*(_hc5[21]*_t705 + _hc5[25]*_t373 - _t140*_t706 - _t438*(-_hc5[56]*_t438 - _hc5[61]*_t140)))) + _hc5[0]*(_t115*_t697 + (_t146 * _t146)*_t82 + _t146*_t661 + _t146*_t709 - _t27*_t702 + _t295*_t703 + _t340*_t698 + _t341*_t698 + _t350*_t662 + _t380*_t661 + _t380*_t700 + _t380*_t709 + (_t43 * _t43 * _t43 * _t43)*_t537 + _t661*(-_t543 - _t544) + _t695*_t699 + _t696*_t699 + _t701) + 0.6e1*_t145*_t148 + 0.4e1*_t378*_t54 + 0.4e1*_t381*_t53)) + 0.4e1*_t357 + 0.4e1*_t382;
  const double d4F_dna3_dgaa = _t3*my_piecewise3(_t16, 0, _hc1[0]*(-0.140e3 / 0.27e2*_hc2[11]*_t464 + (0.56e2 / 0.9e1)*_t10*_t396*_t94 + (0.28e2 / 0.9e1)*_t101*_t58*_t94 - 0.220e3 / 0.27e2*_t154*_t481 - 0.140e3 / 0.27e2*_t171*_t59 - _t265*_t390 + (0.80e2 / 0.9e1)*_t393*_t91*ta - _t424*(_hc2[25]*_t712 + _hc2[28]*_t385 + _t153*_t386 - _t257*_t390 - _t424*(-_hc2[25]*_t390 - _hc2[61]*_t395 - _hc2[65]*_t151) - _t713*_t97) - _t97*(_hc2[11]*_t386*_t58 + _hc2[28]*_t712 + _hc2[30]*_t385 - _t264*_t390 - _t424*_t713 - _t97*(-_hc2[30]*_t390 - _hc2[70]*_t151 - _t392*_t714))) + _t157*_t711 + _t158*_t291 + _t397*_t710) + 0.3e1*_t398;
  const double d4F_dna3_dgbb = _t3*my_piecewise3(_t17, 0, _t160*_t244) + 0.3e1*_t399;
  const double d4F_dna2_dnb_dgaa = _t3*my_piecewise3(_t16, 0, _t157*_t716 + _t158*_t327 + _t397*_t45) + _t398 + _t715;
  const double d4F_dna2_dnb_dgbb = _t3*my_piecewise3(_t17, 0, _t160*_t308 + _t169*_t88) + _t399 + _t717;
  const double d4F_dna_dnb2_dgaa = _t3*my_piecewise3(_t16, 0, _t131*_t157 + _t158*_t338) + _t402 + _t715;
  const double d4F_dna_dnb2_dgbb = _t3*my_piecewise3(_t17, 0, _t160*_t348 + _t169*_t718 + _t28*_t416) + _t417 + _t717;
  const double d4F_dnb3_dgaa = _t3*my_piecewise3(_t16, 0, _t158*_t356) + 0.3e1*_t402;
  const double d4F_dnb3_dgbb = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-0.140e3 / 0.27e2*_hc5[11]*_t475 + (0.56e2 / 0.9e1)*_t13*_t137*_t415 + (0.80e2 / 0.9e1)*_t134*_t412*tb + (0.28e2 / 0.9e1)*_t137*_t144*_t63 - _t140*(_hc5[11]*_t405*_t63 + _hc5[28]*_t721 + _hc5[30]*_t404 - _t140*(-_hc5[30]*_t409 - _hc5[70]*_t163 - _t411*_t723) - _t376*_t409 - _t438*_t722) - 0.220e3 / 0.27e2*_t166*_t490 - 0.140e3 / 0.27e2*_t180*_t64 - _t377*_t409 - _t438*(_hc5[25]*_t721 + _hc5[28]*_t404 - _t140*_t722 + _t165*_t405 - _t369*_t409 - _t438*(-_hc5[25]*_t409 - _hc5[61]*_t414 - _hc5[65]*_t163))) + _t160*_t381 + _t169*_t720 + _t416*_t719) + 0.3e1*_t417;
  const double d4F_dna3_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*(-0.440e3 / 0.27e2*_hc2[6]*_t724*ta + (0.56e2 / 0.9e1)*_t10*_t425*_t94 - 0.280e3 / 0.27e2*_t174*_t481 - _t250 - _t259 + (0.80e2 / 0.9e1)*_t423*_t91*ta - _t424*(_hc2[21]*_t725 + _t252 - _t255 + _t421*_t483 - _t424*(-_hc2[56]*_t173 - _hc2[61]*_t422 - _t253) - _t726*_t97) + (0.80e2 / 0.9e1)*_t91*_t98 - _t97*(_hc2[25]*_t725 + _hc2[28]*_t10*_t421 + _t260 - _t262 - _t424*_t726 - _t97*(-_hc2[65]*_t173 - _hc2[68]*_t422 - _t263))) + _t176*_t711 + _t291*_t67 + _t426*_t710) + 0.3e1*_t427;
  const double d4F_dna3_dtb = _t3*my_piecewise3(_t17, 0, _t244*_t69) + 0.3e1*_t428;
  const double d4F_dna2_dnb_dta = _t3*my_piecewise3(_t16, 0, _t176*_t716 + _t327*_t67 + _t426*_t45) + _t427 + _t727;
  const double d4F_dna2_dnb_dtb = _t3*my_piecewise3(_t17, 0, _t185*_t88 + _t308*_t69) + _t428 + _t728;
  const double d4F_dna_dnb2_dta = _t3*my_piecewise3(_t16, 0, _t131*_t176 + _t338*_t67) + _t431 + _t727;
  const double d4F_dna_dnb2_dtb = _t3*my_piecewise3(_t17, 0, _t185*_t718 + _t28*_t440 + _t348*_t69) + _t441 + _t728;
  const double d4F_dnb3_dta = _t3*my_piecewise3(_t16, 0, _t356*_t67) + 0.3e1*_t431;
  const double d4F_dnb3_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-0.440e3 / 0.27e2*_hc5[6]*_t729*tb + (0.56e2 / 0.9e1)*_t13*_t137*_t439 + (0.80e2 / 0.9e1)*_t134*_t141 + (0.80e2 / 0.9e1)*_t134*_t437*tb - _t140*(_hc5[25]*_t730 + _hc5[28]*_t13*_t435 - _t140*(-_hc5[65]*_t182 - _hc5[68]*_t436 - _t375) + _t372 - _t374 - _t438*_t731) - 0.280e3 / 0.27e2*_t183*_t490 - _t362 - _t371 - _t438*(_hc5[21]*_t730 - _t140*_t731 + _t364 - _t367 + _t435*_t492 - _t438*(-_hc5[56]*_t182 - _hc5[61]*_t436 - _t365))) + _t185*_t720 + _t381*_t69 + _t440*_t719) + 0.3e1*_t441;
  const double d4F_dna2_dgaa2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.7e1 / 0.9e1)*_hc2[11]*_t188*_t248 + (0.10e2 / 0.9e1)*_hc2[28]*_t188*_t724*ta + (0.7e1 / 0.9e1)*_hc2[30]*_t481*_t58 + (0.1e1 / 0.3e1)*_t101*_t190*_t34 - 0.7e1 / 0.9e1*_t191*_t94 - _t35*_t396*_t58 - 0.10e2 / 0.9e1*_t387*_t514*ta - _t424*((0.5e1 / 0.12e2)*_hc2[25]*_t155*_t190*ta - 0.1e1 / 0.3e1*_hc2[28]*_t444 - _hc2[65]*_t734 - _hc2[68]*_t732 + (0.1e1 / 0.3e1)*_hc2[9]*_t190*_t34) - _t97*((0.1e1 / 0.3e1)*_hc2[11]*_t190*_t34 + (0.5e1 / 0.12e2)*_hc2[28]*_t155*_t190*ta - _hc2[68]*_t734 - _hc2[70]*_t732 - _t444*_t445)) + _t112*_t442 - _t112*_t443 + _t384*_t449) + 0.2e1*_t450;
  const double d4F_dna2_dgbb2 = _t3*my_piecewise3(_t17, 0, _t451*_t88 - _t452*_t88) + 0.2e1*_t453;
  const double d4F_dna_dnb_dgaa2 = _t3*my_piecewise3(_t16, 0, _t127*_t442 - _t127*_t443 + _t449*_t45) + _t450 + _t454;
  const double d4F_dna_dnb_dgbb2 = _t3*my_piecewise3(_t17, 0, _t120*_t451 - _t120*_t452 + _t28*_t460) + _t453 + _t461;
  const double d4F_dnb2_dgaa2 = _t3*my_piecewise3(_t16, 0, _t131*_t442 - _t131*_t443) + 0.2e1*_t454;
  const double d4F_dnb2_dgbb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.7e1 / 0.9e1)*_hc5[11]*_t195*_t360 + (0.10e2 / 0.9e1)*_hc5[28]*_t195*_t729*tb + (0.7e1 / 0.9e1)*_hc5[30]*_t490*_t63 - 0.7e1 / 0.9e1*_t137*_t198 - _t140*((0.1e1 / 0.3e1)*_hc5[11]*_t197*_t51 + (0.5e1 / 0.12e2)*_hc5[28]*_t167*_t197*tb - _hc5[68]*_t737 - _hc5[70]*_t735 - _t455*_t456) + (0.1e1 / 0.3e1)*_t144*_t197*_t51 - 0.10e2 / 0.9e1*_t406*_t519*tb - _t415*_t52*_t63 - _t438*((0.5e1 / 0.12e2)*_hc5[25]*_t167*_t197*tb - 0.1e1 / 0.3e1*_hc5[28]*_t455 - _hc5[65]*_t737 - _hc5[68]*_t735 + (0.1e1 / 0.3e1)*_hc5[9]*_t197*_t51)) + _t148*_t451 - _t148*_t452 + _t403*_t460) + 0.2e1*_t461;
  const double d4F_dna2_dgaa_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.20e2 / 0.9e1)*_hc2[25]*_t58*_t738*ta + (0.14e2 / 0.9e1)*_hc2[28]*_t724 + (0.34e2 / 0.9e1)*_hc2[9]*_t387*_t58 - _t390*_t425 - _t394 - _t424*(-_hc2[25]*_t739 - _hc2[61]*_t740 - _hc2[65]*_t462) - _t97*(-_hc2[28]*_t739 - _hc2[65]*_t740 - _hc2[68]*_t462)) + _t112*_t468 + _t384*_t467) + 0.2e1*_t469;
  const double d4F_dna2_dgbb_dtb = _t3*my_piecewise3(_t17, 0, _t470*_t88) + 0.2e1*_t471;
  const double d4F_dna_dnb_dgaa_dta = _t3*my_piecewise3(_t16, 0, _t127*_t468 + _t45*_t467) + _t469 + _t472;
  const double d4F_dna_dnb_dgbb_dtb = _t3*my_piecewise3(_t17, 0, _t120*_t470 + _t28*_t478) + _t471 + _t479;
  const double d4F_dnb2_dgaa_dta = _t3*my_piecewise3(_t16, 0, _t131*_t468) + 0.2e1*_t472;
  const double d4F_dnb2_dgbb_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.20e2 / 0.9e1)*_hc5[25]*_t63*_t741*tb + (0.14e2 / 0.9e1)*_hc5[28]*_t729 + (0.34e2 / 0.9e1)*_hc5[9]*_t406*_t63 - _t140*(-_hc5[28]*_t742 - _hc5[65]*_t743 - _hc5[68]*_t473) - _t409*_t439 - _t413 - _t438*(-_hc5[25]*_t742 - _hc5[61]*_t743 - _hc5[65]*_t473)) + _t148*_t470 + _t403*_t478) + 0.2e1*_t479;
  const double d4F_dna2_dta2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_hc2[21]*_t420*_t744 - 0.10e2 / 0.3e1*_t30*_t423 + (0.80e2 / 0.9e1)*_t419 - _t424*(-_hc2[21]*_t480 - _hc2[56]*_t745 - _hc2[61]*_t746) + (0.28e2 / 0.9e1)*_t483*_t738 - _t97*(-_hc2[25]*_t480 - _hc2[61]*_t745 - _hc2[65]*_t746)) + _t112*_t209 + _t384*_t485) + 0.2e1*_t486;
  const double d4F_dna2_dtb2 = _t3*my_piecewise3(_t17, 0, _t211*_t88) + 0.2e1*_t487;
  const double d4F_dna_dnb_dta2 = _t3*my_piecewise3(_t16, 0, _t127*_t209 + _t45*_t485) + _t486 + _t488;
  const double d4F_dna_dnb_dtb2 = _t3*my_piecewise3(_t17, 0, _t120*_t211 + _t28*_t494) + _t487 + _t495;
  const double d4F_dnb2_dta2 = _t3*my_piecewise3(_t16, 0, _t131*_t209) + 0.2e1*_t488;
  const double d4F_dnb2_dtb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_hc5[21]*_t434*_t747 - _t140*(-_hc5[25]*_t489 - _hc5[61]*_t748 - _hc5[65]*_t749) + (0.80e2 / 0.9e1)*_t433 - 0.10e2 / 0.3e1*_t437*_t47 - _t438*(-_hc5[21]*_t489 - _hc5[56]*_t748 - _hc5[61]*_t749) + (0.28e2 / 0.9e1)*_t492*_t741) + _t148*_t211 + _t403*_t494) + 0.2e1*_t495;
  const double d4F_dna_dgaa3 = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.1e1 / 0.2e1)*_hc2[11]*_t496*_t91 + (0.5e1 / 0.8e1)*_hc2[28]*_t418*_t496*ta - 0.1e1 / 0.6e1*_hc2[70]*_t188*_t724 - 0.5e1 / 0.8e1*_hc2[9]*_t754*ta - 0.1e1 / 0.2e1*_t34*_t499 - 0.5e1 / 0.24e2*_t738*_t753*ta) - _t40*_t750 + _t40*_t751 + _t40*_t752) + _t503;
  const double d4F_dna_dgbb3 = _t3*my_piecewise3(_t17, 0, -_t28*_t755 + _t28*_t756 + _t28*_t757) + _t511;
  const double d4F_dnb_dgaa3 = _t3*my_piecewise3(_t16, 0, -_t45*_t750 + _t45*_t751 + _t45*_t752) + _t503;
  const double d4F_dnb_dgbb3 = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.1e1 / 0.2e1)*_hc5[11]*_t134*_t504 + (0.5e1 / 0.8e1)*_hc5[28]*_t432*_t504*tb - 0.1e1 / 0.6e1*_hc5[70]*_t195*_t729 - 0.5e1 / 0.8e1*_hc5[9]*_t759*tb - 0.1e1 / 0.2e1*_t507*_t51 - 0.5e1 / 0.24e2*_t741*_t758*tb) - _t54*_t755 + _t54*_t756 + _t54*_t757) + _t511;
  const double d4F_dna_dgaa2_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.5e1 / 0.12e2)*_hc2[25]*_t190*_t464*ta + (0.3e1 / 0.4e1)*_hc2[9]*_t155*_t190 - 0.3e1 / 0.4e1*_t447 - 0.1e1 / 0.3e1*_t714*_t738 - _t733*_t762) + _t40*_t760 - _t40*_t761) + _t516;
  const double d4F_dna_dgbb2_dtb = _t3*my_piecewise3(_t17, 0, _t28*_t763 - _t28*_t764) + _t521;
  const double d4F_dnb_dgaa2_dta = _t3*my_piecewise3(_t16, 0, _t45*_t760 - _t45*_t761) + _t516;
  const double d4F_dnb_dgbb2_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.5e1 / 0.12e2)*_hc5[25]*_t197*_t475*tb + (0.3e1 / 0.4e1)*_hc5[9]*_t167*_t197 - 0.3e1 / 0.4e1*_t458 - 0.1e1 / 0.3e1*_t723*_t741 - _t736*_t765) + _t54*_t763 - _t54*_t764) + _t521;
  const double d4F_dna_dgaa_dta2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(-0.7e1 / 0.3e1*_t391*_t464 - 0.5e1 / 0.6e1*_t58*_t766*ta - 0.2e1 / 0.3e1*_t762) + _t40*_t767) + _t524;
  const double d4F_dna_dgbb_dtb2 = _t3*my_piecewise3(_t17, 0, _t28*_t768) + _t527;
  const double d4F_dnb_dgaa_dta2 = _t3*my_piecewise3(_t16, 0, _t45*_t767) + _t524;
  const double d4F_dnb_dgbb_dtb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-0.7e1 / 0.3e1*_t410*_t475 - 0.5e1 / 0.6e1*_t63*_t769*tb - 0.2e1 / 0.3e1*_t765) + _t54*_t768) + _t527;
  const double d4F_dna_dta3 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(-_hc2[56]*_t172/xc_powr(na, 23, 3) - 0.4e1 / 0.3e1*_t10*_t766 - 0.5e1*_t482) + _t40*_t528) + _t529;
  const double d4F_dna_dtb3 = _t3*my_piecewise3(_t17, 0, _t28*_t530) + _t531;
  const double d4F_dnb_dta3 = _t3*my_piecewise3(_t16, 0, _t45*_t528) + _t529;
  const double d4F_dnb_dtb3 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-_hc5[56]*_t181/xc_powr(nb, 23, 3) - 0.4e1 / 0.3e1*_t13*_t769 - 0.5e1*_t491) + _t530*_t54) + _t531;
  const double d4F_dgaa4 = _t3*my_piecewise3(_t16, 0, (0.1e1 / 0.16e2)*_hc1[0]*_hc2[70]*_t418*_t496 + (0.15e2 / 0.16e2)*_hc2[11]*_t187/(gaa * gaa * gaa) - 0.15e2 / 0.16e2*_hc2[3]*_t57/xc_powr(gaa, 7, 2) - 0.3e1 / 0.8e1*_t501*_t754);
  const double d4F_dgbb4 = _t3*my_piecewise3(_t17, 0, (0.1e1 / 0.16e2)*_hc4[0]*_hc5[70]*_t432*_t504 + (0.15e2 / 0.16e2)*_hc5[11]*_t194/(gbb * gbb * gbb) - 0.15e2 / 0.16e2*_hc5[3]*_t62/xc_powr(gbb, 7, 2) - 0.3e1 / 0.8e1*_t509*_t759);
  const double d4F_dgaa3_dta = _t3*my_piecewise3(_t16, 0, (0.1e1 / 0.8e1)*_hc1[0]*_t464*_t753 - 0.3e1 / 0.8e1*_hc2[28]*_t496*_t512 + (0.3e1 / 0.8e1)*_hc2[9]*_t202*_t498);
  const double d4F_dgbb3_dtb = _t3*my_piecewise3(_t17, 0, (0.1e1 / 0.8e1)*_hc4[0]*_t475*_t758 - 0.3e1 / 0.8e1*_hc5[28]*_t504*_t517 + (0.3e1 / 0.8e1)*_hc5[9]*_t206*_t506);
  const double d4F_dgaa2_dta2 = _t3*my_piecewise3(_t16, 0, (0.1e1 / 0.4e1)*_hc1[0]*_hc2[65]*_t188*_t481 - 0.1e1 / 0.4e1*_hc2[25]*_t190*_t522);
  const double d4F_dgbb2_dtb2 = _t3*my_piecewise3(_t17, 0, (0.1e1 / 0.4e1)*_hc4[0]*_hc5[65]*_t195*_t490 - 0.1e1 / 0.4e1*_hc5[25]*_t197*_t525);
  const double d4F_dgaa_dta3 = _t3*my_piecewise3(_t16, 0, (0.1e1 / 0.2e1)*_hc1[0]*_hc2[61]*_t58*_t724);
  const double d4F_dgbb_dtb3 = _t3*my_piecewise3(_t17, 0, (0.1e1 / 0.2e1)*_hc4[0]*_hc5[61]*_t63*_t729);
  const double d4F_dta4 = _t3*my_piecewise3(_t16, 0, _hc1[0]*_hc2[56]*_t738);
  const double d4F_dtb4 = _t3*my_piecewise3(_t17, 0, _hc4[0]*_hc5[56]*_t741);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 2] += d4F_dna3_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 3] += d4F_dna2_dnb_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 5] += d4F_dna2_dnb_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 6] += d4F_dna_dnb2_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 8] += d4F_dna_dnb2_dgbb;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 9] += d4F_dnb3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 1] += d4F_dna3_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 2] += d4F_dna2_dnb_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 3] += d4F_dna2_dnb_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 4] += d4F_dna_dnb2_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 5] += d4F_dna_dnb2_dtb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 6] += d4F_dnb3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 5] += d4F_dna2_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 6] += d4F_dna_dnb_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 11] += d4F_dna_dnb_dgbb2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 12] += d4F_dnb2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 5] += d4F_dna2_dgbb_dtb;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 6] += d4F_dna_dnb_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 11] += d4F_dna_dnb_dgbb_dtb;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 12] += d4F_dnb2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += d4F_dnb2_dgbb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 2] += d4F_dna2_dtb2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 3] += d4F_dna_dnb_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 5] += d4F_dna_dnb_dtb2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 6] += d4F_dnb2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 9] += d4F_dna_dgbb3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 10] += d4F_dnb_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 11] += d4F_dna_dgbb2_dtb;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 12] += d4F_dnb_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += d4F_dnb_dgbb2_dtb;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 8] += d4F_dna_dgbb_dtb2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 9] += d4F_dnb_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += d4F_dnb_dgbb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 3] += d4F_dna_dtb3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 4] += d4F_dnb_dta3;
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