/*
  Generated from python/mgga_exc/mgga_x_ft98.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_ft98
*/

#ifndef _MGGA_X_FT98_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_FT98_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_FT98_HELPER_BODIES
#include "mgga_x_ft98.c"
#undef _MGGA_X_FT98_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_FT98_HELPER_BODIES
#include "mgga_x_ft98.c"
#undef _MGGA_X_FT98_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_FT98_HELPER_BODIES
#include "mgga_x_ft98.c"
#undef _MGGA_X_FT98_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_FT98_HELPER_BODIES
#include "mgga_x_ft98.c"
#undef _MGGA_X_FT98_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_FT98_HELPER_BODIES
#include "mgga_x_ft98.c"
#undef _MGGA_X_FT98_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_ft98.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_FT98_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_f1_k, _KMAX)(const xc_func_type *p, double xi, double *out) {
  const mgga_x_ft98_params *params = (const mgga_x_ft98_params *)(p->params);

  const double _t1 = params->a1*xi + 0.1e1;
  const double _t2 = xc_powr(_t1, 1, 2);
  const double _t3 = params->b1*xi + 0.1e1;
  const double _t4 = xc_powr(_t3, -3, 4);
#if _KMAX >= 1
  const double _t5 = params->a1/_t2;
  const double _t6 = params->b1/xc_powr(_t3, 7, 4);
  const double _t7 = (0.3e1 / 0.4e1)*_t6;
#endif
#if _KMAX >= 2
  const double _t8 = ((params->a1) * (params->a1))/xc_powr(_t1, 3, 2);
  const double _t9 = ((params->b1) * (params->b1));
  const double _t10 = xc_powr(_t3, -11, 4);
#endif
#if _KMAX >= 3
  const double _t11 = ((params->a1) * (params->a1) * (params->a1))/xc_powr(_t1, 5, 2);
  const double _t12 = ((params->b1) * (params->b1) * (params->b1))/xc_powr(_t3, 15, 4);
  const double _t13 = (0.63e2 / 0.32e2)*_t10*_t9;
#endif

  const double f = _t2*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dxi = -_t2*_t7 + (0.1e1 / 0.2e1)*_t4*_t5;
  out[1] = df_dxi;
#endif
#if _KMAX >= 2
  const double d2f_dxi2 = (0.21e2 / 0.16e2)*_t10*_t2*_t9 - 0.1e1 / 0.4e1*_t4*_t8 - _t5*_t7;
  out[2] = d2f_dxi2;
#endif
#if _KMAX >= 3
  const double d3f_dxi3 = (0.3e1 / 0.8e1)*_t11*_t4 - 0.231e3 / 0.64e2*_t12*_t2 + _t13*_t5 + (0.9e1 / 0.16e2)*_t6*_t8;
  out[3] = d3f_dxi3;
#endif
#if _KMAX >= 4
  const double d4f_dxi4 = -0.9e1 / 0.8e1*_t11*_t6 - 0.231e3 / 0.32e2*_t12*_t5 - _t13*_t8 + (0.3465e4 / 0.256e3)*_t2*((params->b1) * (params->b1) * (params->b1) * (params->b1))/xc_powr(_t3, 19, 4) - 0.15e2 / 0.16e2*_t4*((params->a1) * (params->a1) * (params->a1) * (params->a1))/xc_powr(_t1, 7, 2);
  out[4] = d4f_dxi4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_q1_k, _KMAX)(const xc_func_type *p, double xi, double chi, double *out) {

  const double _t1 = xi + 0.1e1;
  const double _t2 = (0.1e1 / (_t1 * _t1));
  const double _t3 = ((-chi + xi) * (-chi + xi));
#if _KMAX >= 1
  const double _t4 = 0.2e1*chi - 0.2e1*xi;
  const double _t5 = -_t4;
  const double _t6 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t7 = 0.2e1*_t6;
#endif
#if _KMAX >= 2
  const double _t8 = 0.2e1*_t2;
  const double _t9 = 0.4e1*_t6;
  const double _t10 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t11 = 0.6e1*_t10;
#endif
#if _KMAX >= 3
  const double _t12 = xc_powi(_t1, -5);
  const double _t13 = 0.24e2*_t12;
#endif

  const double f = _t2*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dchi = _t2*_t4;
  out[1] = df_dchi;
  const double df_dxi = _t2*_t5 - _t3*_t7;
  out[2] = df_dxi;
#endif
#if _KMAX >= 2
  const double d2f_dchi2 = _t8;
  out[3] = d2f_dchi2;
  const double d2f_dxi_dchi = -_t4*_t7 - _t8;
  out[4] = d2f_dxi_dchi;
  const double d2f_dxi2 = _t11*_t3 - _t5*_t9 + _t8;
  out[5] = d2f_dxi2;
#endif
#if _KMAX >= 3
  const double d3f_dchi3 = 0;
  out[6] = d3f_dchi3;
  const double d3f_dxi_dchi2 = -_t9;
  out[7] = d3f_dxi_dchi2;
  const double d3f_dxi2_dchi = _t11*_t4 + 0.8e1*_t6;
  out[8] = d3f_dxi2_dchi;
  const double d3f_dxi3 = 0.18e2*_t10*_t5 - _t13*_t3 - 0.12e2*_t6;
  out[9] = d3f_dxi3;
#endif
#if _KMAX >= 4
  const double d4f_dchi4 = 0;
  out[10] = d4f_dchi4;
  const double d4f_dxi_dchi3 = 0;
  out[11] = d4f_dxi_dchi3;
  const double d4f_dxi2_dchi2 = 0.12e2*_t10;
  out[12] = d4f_dxi2_dchi2;
  const double d4f_dxi3_dchi = -0.36e2*_t10 - _t13*_t4;
  out[13] = d4f_dxi3_dchi;
  const double d4f_dxi4 = 0.72e2*_t10 - 0.96e2*_t12*_t5 + 0.120e3*_t3/xc_powi(_t1, 6);
  out[14] = d4f_dxi4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_q2_orig_k, _KMAX)(const xc_func_type *p, double q3, double *out) {

  const double _t1 = (q3 * q3);
  const double _t2 = _t1 + 0.1e1;
  const double _t3 = xc_powr(_t2, 1, 2);
  const double _t4 = _t3 + q3;
#if _KMAX >= 1
  const double _t5 = (0.1e1 / (_t4 * _t4));
  const double _t6 = (0.1e1 / _t3);
  const double _t7 = _t6*q3;
  const double _t8 = -_t7 - 0.1e1;
#endif
#if _KMAX >= 2
  const double _t9 = xc_powr(_t2, -3, 2);
  const double _t10 = _t1*_t9;
  const double _t11 = _t10 - _t6;
  const double _t12 = -0.2e1*_t7 - 0.2e1;
  const double _t13 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t14 = _t13*_t8;
#endif
#if _KMAX >= 3
  const double _t15 = xc_powr(_t2, -5, 2);
  const double _t16 = _t15*(q3 * q3 * q3);
  const double _t17 = -0.3e1*_t16 + 0.3e1*_t9*q3;
  const double _t18 = _t12*_t13;
  const double _t19 = 0.2e1*_t10 - 0.2e1*_t6;
  const double _t20 = -0.3e1*_t7 - 0.3e1;
  const double _t21 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t22 = _t12*_t21*_t8;
#endif
#if _KMAX >= 4
  const double _t23 = 0.3e1*_t11;
  const double _t24 = _t20*_t21;
#endif

  const double f = (0.1e1 / _t4);
  out[0] = f;
#if _KMAX >= 1
  const double df_dq3 = _t5*_t8;
  out[1] = df_dq3;
#endif
#if _KMAX >= 2
  const double d2f_dq32 = _t11*_t5 + _t12*_t14;
  out[2] = d2f_dq32;
#endif
#if _KMAX >= 3
  const double d3f_dq33 = 0.2e1*_t11*_t18 + _t14*_t19 + _t17*_t5 + _t20*_t22;
  out[3] = d3f_dq33;
#endif
#if _KMAX >= 4
  const double d4f_dq34 = _t12*_t20*_t8*(-0.4e1*_t7 - 0.4e1)/xc_powi(_t4, 5) + _t12*_t23*_t24 + _t13*_t19*_t23 + _t14*(-0.6e1*_t16 + 0.6e1*_t9*q3) + 0.3e1*_t17*_t18 + 0.2e1*_t19*_t24*_t8 + _t22*(0.3e1*_t10 - 0.3e1*_t6) + _t5*(-0.18e2*_t1*_t15 + 0.3e1*_t9 + 0.15e2*(q3 * q3 * q3 * q3)/xc_powr(_t2, 7, 2));
  out[4] = d4f_dq34;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_q2term_smallq_k, _KMAX)(const xc_func_type *p, double q3, double *out) {

  const double _t1 = (q3 * q3);
  const double _t2 = (q3 * q3 * q3 * q3);
  const double _t3 = xc_powi(q3, 6);
#if _KMAX >= 1
  const double _t4 = (q3 * q3 * q3);
  const double _t5 = xc_powi(q3, 5);
#endif

  const double f = (0.1e1 / 0.2e1)*_t1 - 0.1e1 / 0.8e1*_t2 + (0.1e1 / 0.16e2)*_t3 - 0.5e1 / 0.128e3*xc_powi(q3, 8) - q3 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dq3 = -0.1e1 / 0.2e1*_t4 + (0.3e1 / 0.8e1)*_t5 - 0.5e1 / 0.16e2*xc_powi(q3, 7) + q3 - 0.1e1;
  out[1] = df_dq3;
#endif
#if _KMAX >= 2
  const double d2f_dq32 = -0.3e1 / 0.2e1*_t1 + (0.15e2 / 0.8e1)*_t2 - 0.35e2 / 0.16e2*_t3 + 0.1e1;
  out[2] = d2f_dq32;
#endif
#if _KMAX >= 3
  const double d3f_dq33 = (0.15e2 / 0.2e1)*_t4 - 0.105e3 / 0.8e1*_t5 - 0.3e1*q3;
  out[3] = d3f_dq33;
#endif
#if _KMAX >= 4
  const double d4f_dq34 = (0.45e2 / 0.2e1)*_t1 - 0.525e3 / 0.8e1*_t2 - 0.3e1;
  out[4] = d4f_dq34;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_q2term_minfty_k, _KMAX)(const xc_func_type *p, double q3, double *out) {

  const double _t1 = xc_powi(q3, -7);
  const double _t2 = xc_powi(q3, -5);
  const double _t3 = (0.1e1 / (q3 * q3 * q3));
#if _KMAX >= 1
  const double _t4 = xc_powi(q3, -8);
  const double _t5 = xc_powi(q3, -6);
  const double _t6 = (0.1e1 / (q3 * q3 * q3 * q3));
#endif
#if _KMAX >= 2
  const double _t7 = xc_powi(q3, -9);
#endif

  const double f = (0.5e1 / 0.128e3)*_t1 - 0.1e1 / 0.16e2*_t2 + (0.1e1 / 0.8e1)*_t3 - 0.2e1*q3 - (0.1e1 / 0.2e1)/q3;
  out[0] = f;
#if _KMAX >= 1
  const double df_dq3 = -0.35e2 / 0.128e3*_t4 + (0.5e1 / 0.16e2)*_t5 - 0.3e1 / 0.8e1*_t6 - 0.2e1 + (0.1e1 / 0.2e1)/(q3 * q3);
  out[1] = df_dq3;
#endif
#if _KMAX >= 2
  const double d2f_dq32 = -0.15e2 / 0.8e1*_t1 + (0.3e1 / 0.2e1)*_t2 - _t3 + (0.35e2 / 0.16e2)*_t7;
  out[2] = d2f_dq32;
#endif
#if _KMAX >= 3
  const double d3f_dq33 = (0.105e3 / 0.8e1)*_t4 - 0.15e2 / 0.2e1*_t5 + 0.3e1*_t6 - (0.315e3 / 0.16e2)/xc_powi(q3, 10);
  out[3] = d3f_dq33;
#endif
#if _KMAX >= 4
  const double d4f_dq34 = 0.45e2*_t1 - 0.12e2*_t2 - 0.105e3*_t7 + (0.1575e4 / 0.8e1)/xc_powi(q3, 11);
  out[4] = d4f_dq34;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_q20_k, _KMAX)(const xc_func_type *p, double q3, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ft98_q2term_minfty_k, _KMAX)(p, q3, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ft98_q2term_smallq_k, _KMAX)(p, q3, _hc1);
  const double _t1 = xc_powr(XC_EPSILON, 1, 4);
  const double _t2 = -0.1e1/_t1;
  const double _t3 = q3 > _t2;
  const double _t4 = q3 < _t2;
  const double _t5 = my_piecewise3(q3 >= 0, q3, -q3) < _t1;
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0.1e1, 0);
#endif
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t4) && !(_t5)) XC_CAT(ft98_q2_orig_k, _KMAX)(p, my_piecewise3(_t3, q3, _t2), _hc2);

  const double f = my_piecewise5(_t4, _hc0[0], _t5, _hc1[0], _hc2[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dq3 = my_piecewise5(_t4, _hc0[1], _t5, _hc1[1], _hc2[1]*_t6);
  out[1] = df_dq3;
#endif
#if _KMAX >= 2
  const double d2f_dq32 = my_piecewise5(_t4, _hc0[2], _t5, _hc1[2], _hc2[2]*(_t6 * _t6));
  out[2] = d2f_dq32;
#endif
#if _KMAX >= 3
  const double d3f_dq33 = my_piecewise5(_t4, _hc0[3], _t5, _hc1[3], _hc2[3]*(_t6 * _t6 * _t6));
  out[3] = d3f_dq33;
#endif
#if _KMAX >= 4
  const double d4f_dq34 = my_piecewise5(_t4, _hc0[4], _t5, _hc1[4], _hc2[4]*(_t6 * _t6 * _t6 * _t6));
  out[4] = d4f_dq34;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_q3_k, _KMAX)(const xc_func_type *p, double xi, double chi, double *out) {
  const mgga_x_ft98_params *params = (const mgga_x_ft98_params *)(p->params);


  const double f = -(chi * chi) - params->b2 + (xi * xi);
  out[0] = f;
#if _KMAX >= 1
  const double df_dchi = -0.2e1*chi;
  out[1] = df_dchi;
  const double df_dxi = 0.2e1*xi;
  out[2] = df_dxi;
#endif
#if _KMAX >= 2
  const double d2f_dchi2 = -0.2e1;
  out[3] = d2f_dchi2;
  const double d2f_dxi_dchi = 0;
  out[4] = d2f_dxi_dchi;
  const double d2f_dxi2 = 0.2e1;
  out[5] = d2f_dxi2;
#endif
#if _KMAX >= 3
  const double d3f_dchi3 = 0;
  out[6] = d3f_dchi3;
  const double d3f_dxi_dchi2 = 0;
  out[7] = d3f_dxi_dchi2;
  const double d3f_dxi2_dchi = 0;
  out[8] = d3f_dxi2_dchi;
  const double d3f_dxi3 = 0;
  out[9] = d3f_dxi3;
#endif
#if _KMAX >= 4
  const double d4f_dchi4 = 0;
  out[10] = d4f_dchi4;
  const double d4f_dxi_dchi3 = 0;
  out[11] = d4f_dxi_dchi3;
  const double d4f_dxi2_dchi2 = 0;
  out[12] = d4f_dxi2_dchi2;
  const double d4f_dxi3_dchi = 0;
  out[13] = d4f_dxi3_dchi;
  const double d4f_dxi4 = 0;
  out[14] = d4f_dxi4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_q2_k, _KMAX)(const xc_func_type *p, double xi, double chi, double *out) {
  const mgga_x_ft98_params *params = (const mgga_x_ft98_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(ft98_q3_k, _KMAX)(p, xi, chi, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ft98_q20_k, _KMAX)(p, _hc0[0], _hc1);
  const double _t1 = -params->b2 + xc_powr(((params->b2) * (params->b2)) + 0.1e1, 1, 2);
#if _KMAX >= 1
  const double _t2 = _hc1[1]*_t1;
#endif
#if _KMAX >= 2
  const double _t3 = ((_hc0[1]) * (_hc0[1]));
  const double _t4 = _hc1[2]*_t1;
  const double _t5 = _hc0[2]*_t4;
  const double _t6 = ((_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 3
  const double _t7 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t8 = _hc1[3]*_t1;
  const double _t9 = 0.3e1*_t4;
  const double _t10 = _hc0[1]*_hc0[3];
  const double _t11 = _t3*_t8;
  const double _t12 = _hc0[5]*_t4;
  const double _t13 = _t6*_t8;
  const double _t14 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t15 = 0.3e1*_hc0[5];
#endif
#if _KMAX >= 4
  const double _t16 = _hc1[4]*_t1;
  const double _t17 = _hc0[2]*_t8;
#endif

  const double f = _hc1[0]*_t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dchi = _hc0[1]*_t2;
  out[1] = df_dchi;
  const double df_dxi = _hc0[2]*_t2;
  out[2] = df_dxi;
#endif
#if _KMAX >= 2
  const double d2f_dchi2 = _hc0[3]*_t2 + _t3*_t4;
  out[3] = d2f_dchi2;
  const double d2f_dxi_dchi = _hc0[1]*_t5;
  out[4] = d2f_dxi_dchi;
  const double d2f_dxi2 = _hc0[5]*_t2 + _t4*_t6;
  out[5] = d2f_dxi2;
#endif
#if _KMAX >= 3
  const double d3f_dchi3 = _t10*_t9 + _t7*_t8;
  out[6] = d3f_dchi3;
  const double d3f_dxi_dchi2 = _hc0[2]*_t11 + _hc0[3]*_t5;
  out[7] = d3f_dxi_dchi2;
  const double d3f_dxi2_dchi = _hc0[1]*_t12 + _hc0[1]*_t13;
  out[8] = d3f_dxi2_dchi;
  const double d3f_dxi3 = _t14*_t8 + _t15*_t5;
  out[9] = d3f_dxi3;
#endif
#if _KMAX >= 4
  const double d4f_dchi4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t16 + ((_hc0[3]) * (_hc0[3]))*_t9 + 0.6e1*_hc0[3]*_t11;
  out[10] = d4f_dchi4;
  const double d4f_dxi_dchi3 = _hc0[2]*_t16*_t7 + 0.3e1*_t10*_t17;
  out[11] = d4f_dxi_dchi3;
  const double d4f_dxi2_dchi2 = _hc0[3]*_t12 + _hc0[3]*_t13 + _hc0[5]*_t11 + _t16*_t3*_t6;
  out[12] = d4f_dxi2_dchi2;
  const double d4f_dxi3_dchi = _hc0[1]*_t14*_t16 + _hc0[1]*_t15*_t17;
  out[13] = d4f_dxi3_dchi;
  const double d4f_dxi4 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t16 + ((_hc0[5]) * (_hc0[5]))*_t9 + 0.6e1*_hc0[5]*_t13;
  out[14] = d4f_dxi4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_f2_k, _KMAX)(const xc_func_type *p, double xi, double chi, double *out) {
  const mgga_x_ft98_params *params = (const mgga_x_ft98_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(ft98_q2_k, _KMAX)(p, xi, chi, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(ft98_q1_k, _KMAX)(p, xi, chi, _hc1);
  const double _t1 = _hc0[0] + 0.1e1;
  const double _t2 = -0.1e1 + M_CBRT2;
  const double _t3 = _hc0[0]*_t2 + 0.1e1;
  const double _t4 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t5 = _hc1[0]*params->a2;
  const double _t6 = _t5 + 0.1e1;
  const double _t7 = _t4*_t6;
#if _KMAX >= 1
  const double _t8 = _t4*params->a2;
  const double _t9 = _t1*_t8;
  const double _t10 = _t2/(_t3 * _t3 * _t3 * _t3);
  const double _t11 = _t10*_t6;
  const double _t12 = _t1*_t11;
  const double _t13 = 0.3e1*_t12;
#endif
#if _KMAX >= 2
  const double _t14 = _hc0[1]*_t8;
  const double _t15 = 0.2e1*_t14;
  const double _t16 = _hc1[1]*params->a2;
  const double _t17 = 0.6e1*_t10;
  const double _t18 = _hc0[1]*_t1;
  const double _t19 = _t17*_t18;
  const double _t20 = ((_hc0[1]) * (_hc0[1]));
  const double _t21 = _t20*_t6;
  const double _t22 = 0.3e1*_hc0[3];
  const double _t23 = xc_powi(_t3, -5);
  const double _t24 = (_t2 * _t2);
  const double _t25 = _t23*_t24;
  const double _t26 = _t21*_t25;
  const double _t27 = 0.12e2*_t1;
  const double _t28 = _hc1[2]*_t8;
  const double _t29 = _hc0[2]*_t8;
  const double _t30 = 0.3e1*_t10;
  const double _t31 = _hc1[2]*params->a2;
  const double _t32 = _t18*_t31;
  const double _t33 = _hc0[2]*_t1;
  const double _t34 = _t30*_t33;
  const double _t35 = _t17*_t6;
  const double _t36 = _hc0[2]*_t35;
  const double _t37 = 0.3e1*_hc0[4];
  const double _t38 = _hc0[1]*_hc0[2];
  const double _t39 = _t25*_t6;
  const double _t40 = _t27*_t39;
  const double _t41 = 0.2e1*_t28;
  const double _t42 = _t17*_t33;
  const double _t43 = ((_hc0[2]) * (_hc0[2]));
  const double _t44 = _t39*_t43;
#endif
#if _KMAX >= 3
  const double _t45 = 0.18e2*_t10;
  const double _t46 = _t20*params->a2;
  const double _t47 = _hc1[1]*_t46;
  const double _t48 = 0.9e1*_t10;
  const double _t49 = _hc1[3]*params->a2;
  const double _t50 = _t18*_t49;
  const double _t51 = _t1*_t16;
  const double _t52 = _hc0[3]*_t48;
  const double _t53 = 0.18e2*_t11;
  const double _t54 = _hc0[1]*_t53;
  const double _t55 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t56 = 0.36e2*_t5 + 0.36e2;
  const double _t57 = (_t2 * _t2 * _t2)/xc_powi(_t3, 6);
  const double _t58 = _t55*_t57;
  const double _t59 = _t1*_t6;
  const double _t60 = 0.60e2*_t59;
  const double _t61 = _hc1[1]*_t8;
  const double _t62 = 0.2e1*_t61;
  const double _t63 = _t10*_t16;
  const double _t64 = 0.12e2*_t38;
  const double _t65 = _t17*_t46;
  const double _t66 = _hc1[4]*params->a2;
  const double _t67 = _t10*_t31;
  const double _t68 = _t1*_t22;
  const double _t69 = _hc0[4]*_t17;
  const double _t70 = 0.12e2*_t11;
  const double _t71 = _hc0[4]*_t70;
  const double _t72 = 0.3e1*_hc0[7];
  const double _t73 = _hc0[2]*_t25;
  const double _t74 = 0.24e2*_t73;
  const double _t75 = _t16*_t18;
  const double _t76 = _t25*_t27;
  const double _t77 = _hc1[2]*_t46;
  const double _t78 = 0.36e2*_t26;
  const double _t79 = _t1*_t39;
  const double _t80 = 0.24e2*_t79;
  const double _t81 = _hc0[4]*_t80;
  const double _t82 = _hc0[2]*_hc0[3];
  const double _t83 = _t21*_t57;
  const double _t84 = 0.60e2*_t83;
  const double _t85 = _hc1[5]*_t8;
  const double _t86 = _hc0[5]*_t8;
  const double _t87 = 0.2e1*_t29;
  const double _t88 = _t43*params->a2;
  const double _t89 = _t17*_t88;
  const double _t90 = _hc1[5]*params->a2;
  const double _t91 = _t18*_t30;
  const double _t92 = _t1*_t31;
  const double _t93 = _hc0[5]*_t30;
  const double _t94 = _hc0[5]*_t35;
  const double _t95 = _t76*_t88;
  const double _t96 = 0.36e2*_t44;
  const double _t97 = _hc0[1]*_hc0[5];
  const double _t98 = _t43*_t57;
  const double _t99 = _t60*_t98;
  const double _t100 = 0.3e1*_t29;
  const double _t101 = 0.3e1*_t28;
  const double _t102 = _t45*_t88;
  const double _t103 = _t33*_t48;
  const double _t104 = _hc0[5]*_t48;
  const double _t105 = _hc0[2]*_t53;
  const double _t106 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t107 = _t1*_t25;
  const double _t108 = 0.36e2*_t107;
  const double _t109 = _t108*_t88;
  const double _t110 = 0.36e2*_t79;
  const double _t111 = _hc0[2]*_hc0[5];
  const double _t112 = _t106*_t57;
#endif
#if _KMAX >= 4
  const double _t113 = _hc1[3]*_t8;
  const double _t114 = _hc0[1]*_hc0[3];
  const double _t115 = 0.36e2*_t10;
  const double _t116 = _hc1[3]*_t46;
  const double _t117 = _hc0[3]*_t1;
  const double _t118 = _t45*_t49;
  const double _t119 = 0.24e2*_t11;
  const double _t120 = _hc0[1]*_hc0[6];
  const double _t121 = _t25*_t55;
  const double _t122 = 0.144e3*_t16;
  const double _t123 = ((_hc0[3]) * (_hc0[3]));
  const double _t124 = _hc0[3]*_t25;
  const double _t125 = _t124*_t18;
  const double _t126 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t127 = _t57*(-0.240e3*_t5 - 0.240e3);
  const double _t128 = 0.72e2*_t107;
  const double _t129 = 0.48e2*_t79;
  const double _t130 = 0.360e3*_t59;
  const double _t131 = (_t2 * _t2 * _t2 * _t2)/xc_powi(_t3, 7);
  const double _t132 = _t130*_t131;
  const double _t133 = _hc1[4]*_t8;
  const double _t134 = _t31*_t45;
  const double _t135 = _hc0[1]*_hc0[4];
  const double _t136 = _t16*_t45;
  const double _t137 = _hc1[4]*_t46;
  const double _t138 = _hc1[7]*params->a2;
  const double _t139 = _t1*_t66;
  const double _t140 = _hc0[4]*_t1;
  const double _t141 = _t140*_t48;
  const double _t142 = 0.36e2*_t31;
  const double _t143 = _hc0[4]*_t53;
  const double _t144 = 0.36e2*_t73;
  const double _t145 = 0.72e2*_t25;
  const double _t146 = _hc0[4]*_t145;
  const double _t147 = 0.36e2*_t16;
  const double _t148 = _t124*_t33;
  const double _t149 = _t38*_t39;
  const double _t150 = 0.108e3*_t149;
  const double _t151 = 0.108e3*_hc0[4];
  const double _t152 = 0.240e3*_t6;
  const double _t153 = _t33*_t57;
  const double _t154 = _hc0[4]*_t110;
  const double _t155 = 0.180e3*_t59;
  const double _t156 = _t38*_t57;
  const double _t157 = _t155*_t156;
  const double _t158 = _t10*_t66;
  const double _t159 = _hc0[2]*_hc0[4];
  const double _t160 = _hc1[8]*params->a2;
  const double _t161 = _hc0[1]*_hc0[8];
  const double _t162 = _hc0[2]*_hc0[7];
  const double _t163 = ((_hc0[4]) * (_hc0[4]));
  const double _t164 = _hc1[1]*_t88;
  const double _t165 = 0.48e2*_hc0[4]*_t25;
  const double _t166 = _hc0[5]*_t25;
  const double _t167 = _t18*_t57;
  const double _t168 = _hc0[5]*_t1;
  const double _t169 = _t45*_t90;
  const double _t170 = _hc1[9]*params->a2;
  const double _t171 = _hc0[1]*_hc0[9];
  const double _t172 = _t106*_t25;
  const double _t173 = _hc1[2]*_t88;
  const double _t174 = _t166*_t33;
  const double _t175 = _hc1[5]*_t88;
  const double _t176 = _hc0[2]*_hc0[9];
  const double _t177 = 0.144e3*_t31;
  const double _t178 = ((_hc0[5]) * (_hc0[5]));
  const double _t179 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
#endif

  const double f = _t1*_t7;
  out[0] = f;
#if _KMAX >= 1
  const double df_dchi = -_hc0[1]*_t13 + _hc0[1]*_t7 + _hc1[1]*_t9;
  out[1] = df_dchi;
  const double df_dxi = -_hc0[2]*_t13 + _hc0[2]*_t7 + _hc1[2]*_t9;
  out[2] = df_dxi;
#endif
#if _KMAX >= 2
  const double d2f_dchi2 = _hc0[3]*_t7 + _hc1[1]*_t15 + _hc1[3]*_t9 - _t12*_t22 - _t16*_t19 - _t17*_t21 + _t26*_t27;
  out[3] = d2f_dchi2;
  const double d2f_dxi_dchi = _hc0[1]*_t28 - _hc0[1]*_t36 + _hc0[4]*_t7 + _hc1[1]*_t29 + _hc1[4]*_t9 - _t12*_t37 - _t16*_t34 - _t30*_t32 + _t38*_t40;
  out[4] = d2f_dxi_dchi;
  const double d2f_dxi2 = _hc0[2]*_t41 - _hc0[5]*_t13 + _hc0[5]*_t7 + _hc1[5]*_t9 + _t27*_t44 - _t31*_t42 - _t35*_t43;
  out[5] = d2f_dxi2;
#endif
#if _KMAX >= 3
  const double d3f_dchi3 = 0.36e2*_hc0[1]*_hc0[3]*_t1*_t23*_t24*_t6 + 0.3e1*_hc0[1]*_hc1[3]*_t4*params->a2 + 0.3e1*_hc0[3]*_hc1[1]*_t4*params->a2 - _hc0[3]*_t54 - _hc0[6]*_t13 + _hc0[6]*_t4*_t6 + 0.36e2*_hc1[1]*_t1*_t20*_t23*_t24*params->a2 + _t23*_t24*_t55*_t56 - _t45*_t47 - _t48*_t50 - _t51*_t52 - _t58*_t60;
  out[6] = d3f_dchi3;
  const double d3f_dxi_dchi2 = -_hc0[1]*_t71 + _hc0[1]*_t81 + _hc0[2]*_t78 + _hc0[3]*_t28 - _hc0[3]*_t36 + _hc0[4]*_t62 + _hc0[7]*_t7 - _hc1[2]*_t65 + _hc1[3]*_t29 + _hc1[4]*_t15 + _hc1[7]*_t9 - _t12*_t72 - _t19*_t66 - _t33*_t84 - _t34*_t49 + _t40*_t82 - _t51*_t69 - _t63*_t64 - _t67*_t68 + _t74*_t75 + _t76*_t77;
  out[7] = d3f_dxi_dchi2;
  const double d3f_dxi2_dchi = _hc0[1]*_t85 - _hc0[1]*_t94 + _hc0[1]*_t96 - _hc0[1]*_t99 - _hc0[2]*_t71 + _hc0[2]*_t81 + _hc0[4]*_t41 - _hc0[8]*_t13 + _hc0[8]*_t7 + _hc1[1]*_t86 - _hc1[1]*_t89 + _hc1[1]*_t95 + _hc1[4]*_t87 + _hc1[8]*_t9 + _t32*_t74 + _t40*_t97 - _t42*_t66 - _t51*_t93 - _t64*_t67 - _t69*_t92 - _t90*_t91;
  out[8] = d3f_dxi2_dchi;
  const double d3f_dxi3 = _hc0[5]*_t101 - _hc0[5]*_t105 - _hc0[9]*_t13 + _hc0[9]*_t7 - _hc1[2]*_t102 + _hc1[2]*_t109 + _hc1[5]*_t100 + _hc1[9]*_t9 - _t103*_t90 - _t104*_t92 + _t106*_t25*_t56 + _t110*_t111 - _t112*_t60;
  out[9] = d3f_dxi3;
#endif
#if _KMAX >= 4
  const double d4f_dchi4 = -_hc0[10]*_t13 + _hc0[10]*_t7 + 0.6e1*_hc0[3]*_t113 + 0.216e3*_hc0[3]*_t26 - _hc0[6]*_t27*_t63 + 0.4e1*_hc0[6]*_t61 + _t110*_t123 - 0.72e2*_t114*_t63 - _t115*_t116 + _t116*_t128 - _t117*_t118 - 0.360e3*_t117*_t83 - _t119*_t120 + _t120*_t129 + _t121*_t122 + _t122*_t125 - _t123*_t53 + _t126*_t127 + _t126*_t132 - 0.240e3*_t51*_t58;
  out[10] = d4f_dchi4;
  const double d4f_dxi_dchi3 = _hc0[1]*_hc0[7]*_t110 - _hc0[11]*_t13 + _hc0[11]*_t7 + _hc0[2]*_hc0[6]*_t40 + _hc0[2]*_t132*_t55 - _hc0[2]*_t152*_t58 - _hc0[3]*_t143 + _hc0[3]*_t150 + _hc0[3]*_t154 - _hc0[3]*_t157 + _hc0[6]*_t28 - _hc0[6]*_t30*_t92 - _hc0[6]*_t36 - _hc0[7]*_t48*_t51 - _hc0[7]*_t54 + 0.3e1*_hc1[7]*_t14 + _t108*_t137 + _t113*_t37 - _t114*_t134 - _t115*_t135*_t16 - _t118*_t38 + _t121*_t142 + _t125*_t142 + _t133*_t22 - _t136*_t82 - _t137*_t45 - _t138*_t18*_t48 - _t139*_t52 - 0.180e3*_t140*_t83 - _t141*_t49 + _t144*_t50 + _t146*_t75 + _t147*_t148 + _t151*_t26 - 0.180e3*_t153*_t47 + 0.108e3*_t47*_t73 - 0.60e2*_t58*_t92 + _t61*_t72;
  out[11] = d4f_dxi_dchi3;
  const double d4f_dxi2_dchi2 = _hc0[1]*_t145*_t164 - _hc0[12]*_t13 + _hc0[12]*_t7 + _hc0[3]*_hc0[5]*_t40 + _hc0[3]*_t85 - _hc0[3]*_t94 + _hc0[3]*_t96 - _hc0[3]*_t99 + 0.4e1*_hc0[4]*_t133 + 0.144e3*_hc0[4]*_t149 - 0.240e3*_hc0[4]*_t156*_t59 - _hc0[4]*_t158*_t27 + _hc0[5]*_t78 - _hc0[7]*_t17*_t92 + _hc0[7]*_t41 - _hc0[8]*_t17*_t51 + _hc0[8]*_t62 + _hc1[12]*_t9 + _hc1[3]*_t86 - _hc1[3]*_t89 + _hc1[3]*_t95 + _hc1[5]*_t46*_t76 - _hc1[5]*_t65 + _hc1[7]*_t87 + _hc1[8]*_t15 + 0.360e3*_t1*_t131*_t21*_t43 - _t1*_t49*_t93 - _t10*_t68*_t90 + _t127*_t20*_t43 - 0.24e2*_t135*_t67 - _t138*_t42 + 0.24e2*_t148*_t31 - 0.120e3*_t153*_t77 - 0.24e2*_t158*_t38 - 0.24e2*_t159*_t63 + _t16*_t165*_t33 - _t160*_t19 - _t161*_t70 + _t161*_t80 - _t162*_t70 + _t162*_t80 - _t163*_t70 + _t163*_t80 - 0.120e3*_t164*_t167 + _t165*_t32 + 0.24e2*_t166*_t75 - _t168*_t84 + 0.48e2*_t18*_t66*_t73 - 0.12e2*_t63*_t97 - 0.12e2*_t67*_t82 + 0.72e2*_t73*_t77;
  out[12] = d4f_dxi2_dchi2;
  const double d4f_dxi3_dchi = _hc0[1]*_t106*_t132 - _hc0[1]*_t112*_t152 + 0.108e3*_hc0[1]*_t173*_t25 - _hc0[13]*_t13 + _hc0[13]*_t7 + _hc0[2]*_hc0[8]*_t110 - _hc0[4]*_t155*_t98 - _hc0[5]*_t143 + _hc0[5]*_t150 + _hc0[5]*_t154 - _hc0[5]*_t157 + _hc0[8]*_t101 - _hc0[8]*_t105 - _hc0[8]*_t48*_t92 - _hc0[9]*_t30*_t51 + _hc0[9]*_t61 + _hc1[13]*_t9 - _hc1[4]*_t102 + _hc1[4]*_t109 + 0.3e1*_hc1[4]*_t86 + _hc1[8]*_t100 + _hc1[9]*_t14 - _t103*_t160 - _t104*_t139 - _t111*_t136 - 0.60e2*_t112*_t51 - _t115*_t159*_t31 - _t134*_t97 - _t141*_t90 + _t142*_t166*_t18 + _t144*_t18*_t90 + _t146*_t31*_t33 + _t147*_t172 + _t147*_t174 + _t151*_t44 - 0.180e3*_t167*_t173 - _t169*_t38 - _t170*_t91 - _t171*_t35 + _t171*_t40 + _t37*_t85;
  out[13] = d4f_dxi3_dchi;
  const double d4f_dxi4 = -_hc0[14]*_t13 + _hc0[14]*_t7 - _hc0[2]*_t10*_t170*_t27 - _hc0[5]*_t130*_t98 + 0.216e3*_hc0[5]*_t44 + 0.6e1*_hc0[5]*_t85 - _hc0[9]*_t27*_t67 + 0.4e1*_hc0[9]*_t28 + _hc1[14]*_t9 + 0.4e1*_hc1[9]*_t29 + _t110*_t178 - 0.72e2*_t111*_t67 - 0.240e3*_t112*_t92 - _t115*_t175 - _t119*_t176 + _t127*_t179 + _t128*_t175 + _t129*_t176 + _t132*_t179 - _t168*_t169 + _t172*_t177 + _t174*_t177 - _t178*_t53;
  out[14] = d4f_dxi4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_f0_k, _KMAX)(const xc_func_type *p, double xi, double chi, double *out) {
  const mgga_x_ft98_params *params = (const mgga_x_ft98_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(ft98_f1_k, _KMAX)(p, xi, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(ft98_f2_k, _KMAX)(p, xi, chi, _hc1);
  const double _t1 = _hc0[0]*params->a;
  const double _t2 = _t1*xi;
  const double _t3 = ((-chi + xi) * (-chi + xi));
  const double _t4 = _hc1[0]*params->b;
  const double _t5 = _t3*_t4;
  const double _t6 = _t2 + _t5 + 0.1e1;
  const double _t7 = xc_powr(0.2e1, 2, 3);
  const double _t8 = (M_CBRT3 * M_CBRT3)*_t7*params->b/(M_CBRTPI * M_CBRTPI);
  const double _t9 = (0.81e2 / 0.4e1)*_t8;
  const double _t10 = _t9*xi + 0.1e1;
  const double _t11 = (0.1e1 / _t10);
  const double _t12 = xc_powr(_t11*_t6, 1, 2);
#if _KMAX >= 1
  const double _t13 = 0.2e1*xi;
  const double _t14 = -_t13 + 0.2e1*chi;
  const double _t15 = _t14*_t4;
  const double _t16 = _t3*params->b;
  const double _t17 = _hc1[1]*_t16;
  const double _t18 = _t15 + _t17;
  const double _t19 = _t12/_t6;
  const double _t20 = (0.1e1 / 0.2e1)*_t19;
  const double _t21 = (_t10 * _t10);
  const double _t22 = (0.1e1 / _t21);
  const double _t23 = _t22*_t8;
  const double _t24 = (0.81e2 / 0.8e1)*_t23;
  const double _t25 = _hc0[1]*params->a;
  const double _t26 = _t25*xi;
  const double _t27 = -_t14;
  const double _t28 = _t27*_t4;
  const double _t29 = _hc1[2]*_t16;
  const double _t30 = _t1 + _t26 + _t28 + _t29;
  const double _t31 = (0.1e1 / 0.2e1)*_t11*_t30 - _t24*_t6;
  const double _t32 = _t10*_t19;
#endif
#if _KMAX >= 2
  const double _t33 = (_t18 * _t18);
  const double _t34 = _t12/(_t6 * _t6);
  const double _t35 = (0.1e1 / 0.4e1)*_t34;
  const double _t36 = 0.2e1*_t4;
  const double _t37 = _hc1[3]*_t16;
  const double _t38 = _hc1[1]*params->b;
  const double _t39 = 0.2e1*_t38;
  const double _t40 = _t14*_t39 + _t36 + _t37;
  const double _t41 = -_t18;
  const double _t42 = _t34*_t41;
  const double _t43 = (0.1e1 / 0.2e1)*_t18;
  const double _t44 = _t27*_t38;
  const double _t45 = _hc1[2]*params->b;
  const double _t46 = _t14*_t45;
  const double _t47 = _hc1[4]*_t16;
  const double _t48 = -_t36 + _t44 + _t46 + _t47;
  const double _t49 = (0.1e1 / 0.2e1)*_t11*_t48 - _t18*_t24;
  const double _t50 = _t10*_t31;
  const double _t51 = _t34*_t50;
  const double _t52 = _t19*_t9;
  const double _t53 = (_t31 * _t31);
  const double _t54 = _t21*_t34;
  const double _t55 = -_t30;
  const double _t56 = (_t10 * _t10 * _t10);
  const double _t57 = (0.1e1 / _t56);
  const double _t58 = M_CBRT2;
  const double _t59 = (M_CBRT3 * M_CBRT3 * M_CBRT3 * M_CBRT3);
  const double _t60 = (0.1e1 / (M_CBRTPI * M_CBRTPI * M_CBRTPI * M_CBRTPI));
  const double _t61 = ((params->b) * (params->b));
  const double _t62 = _t58*_t59*_t60*_t61;
  const double _t63 = _t57*_t62;
  const double _t64 = (0.6561e4 / 0.8e1)*_t63;
  const double _t65 = _hc0[2]*params->a;
  const double _t66 = _t65*xi;
  const double _t67 = _hc1[5]*_t16;
  const double _t68 = 0.2e1*_t45;
  const double _t69 = 0.2e1*_t25 + _t27*_t68 + _t36 + _t66 + _t67;
  const double _t70 = _t11*_t69;
  const double _t71 = _t22*_t9;
  const double _t72 = -_t30*_t71;
  const double _t73 = _t6*_t64 + (0.1e1 / 0.2e1)*_t70 + _t72;
#endif
#if _KMAX >= 3
  const double _t74 = (_t18 * _t18 * _t18);
  const double _t75 = _t12/(_t6 * _t6 * _t6);
  const double _t76 = (0.1e1 / 0.8e1)*_t75;
  const double _t77 = 0.6e1*_t38;
  const double _t78 = _hc1[6]*_t16;
  const double _t79 = _hc1[3]*params->b;
  const double _t80 = 0.3e1*_t14*_t79 + _t77 + _t78;
  const double _t81 = -0.2e1*_t15 - 0.2e1*_t17;
  const double _t82 = _t33*_t75;
  const double _t83 = (0.1e1 / 0.4e1)*_t82;
  const double _t84 = _t18*_t35;
  const double _t85 = -_t40;
  const double _t86 = _t34*_t43;
  const double _t87 = 0.4e1*_t4;
  const double _t88 = 0.4e1*_t38;
  const double _t89 = _t14*_t88 + 0.2e1*_t37 + _t87;
  const double _t90 = _t75*_t81;
  const double _t91 = _t41*_t90;
  const double _t92 = _hc1[4]*params->b;
  const double _t93 = 0.2e1*_t92;
  const double _t94 = _hc1[7]*_t16 + _t14*_t93 + _t27*_t79 + _t68 - _t88;
  const double _t95 = (0.1e1 / 0.2e1)*_t11*_t94 - _t24*_t40;
  const double _t96 = (0.1e1 / 0.2e1)*_t51;
  const double _t97 = _t10*_t34;
  const double _t98 = _t49*_t97;
  const double _t99 = _t10*_t42;
  const double _t100 = 0.2e1*_t99;
  const double _t101 = _t43*_t90;
  const double _t102 = _t41*_t75;
  const double _t103 = _t102*_t43;
  const double _t104 = _t18*_t34;
  const double _t105 = _t31*_t8;
  const double _t106 = (0.81e2 / 0.8e1)*_t105;
  const double _t107 = _t31*_t9;
  const double _t108 = _t21*_t53;
  const double _t109 = _t108*_t75;
  const double _t110 = (0.1e1 / 0.2e1)*_t15 + (0.1e1 / 0.2e1)*_t17;
  const double _t111 = -_t48;
  const double _t112 = _t50*_t55;
  const double _t113 = _t112*_t75;
  const double _t114 = 0.4e1*_t45;
  const double _t115 = _hc1[5]*params->b;
  const double _t116 = _hc1[8]*_t16 - _t114 + _t115*_t14 + _t27*_t93 + _t39;
  const double _t117 = _t11*_t116;
  const double _t118 = (0.1e1 / 0.2e1)*_t117 + _t18*_t64 - _t48*_t71;
  const double _t119 = _t10*_t73;
  const double _t120 = _t11*_t48 - _t18*_t71;
  const double _t121 = _t31*_t54;
  const double _t122 = (_t31 * _t31 * _t31);
  const double _t123 = _t56*_t75;
  const double _t124 = (0.243e3 / 0.4e1)*_t8;
  const double _t125 = _t124*_t53;
  const double _t126 = _t34*_t55;
  const double _t127 = (0.81e2 / 0.2e1)*_t105;
  const double _t128 = -_t69;
  const double _t129 = -0.2e1*_t1 - _t13*_t25 - 0.2e1*_t28 - 0.2e1*_t29;
  const double _t130 = _t19*_t8;
  const double _t131 = (0.81e2 / 0.2e1)*_t130;
  const double _t132 = _t55*_t97;
  const double _t133 = 0.2e1*_t132;
  const double _t134 = (_t10 * _t10 * _t10 * _t10);
  const double _t135 = xc_powi(M_CBRT3, 6)*((params->b) * (params->b) * (params->b))/(xc_powi(M_CBRTPI, 6)*_t134);
  const double _t136 = (0.1594323e7 / 0.16e2)*_t135;
  const double _t137 = _hc0[3]*params->a;
  const double _t138 = 0.3e1*_t27;
  const double _t139 = _hc1[9]*_t16 + _t115*_t138 + _t137*xi + 0.6e1*_t45 + 0.3e1*_t65;
  const double _t140 = (0.243e3 / 0.8e1)*_t23;
  const double _t141 = (0.1e1 / 0.2e1)*_t11*_t139 - _t136*_t6 - _t140*_t69 + (0.19683e5 / 0.8e1)*_t30*_t57*_t58*_t59*_t60*_t61;
  const double _t142 = (0.6561e4 / 0.4e1)*_t63;
  const double _t143 = (0.81e2 / 0.2e1)*_t23;
  const double _t144 = -_t143*_t30 + _t70;
  const double _t145 = _t142*_t6 + _t144;
#endif
#if _KMAX >= 4
  const double _t146 = _t12/(_t6 * _t6 * _t6 * _t6);
  const double _t147 = _hc1[6]*params->b;
  const double _t148 = -0.3e1*_t15 - 0.3e1*_t17;
  const double _t149 = (0.1e1 / 0.8e1)*_t74;
  const double _t150 = _t146*_t149;
  const double _t151 = _t146*_t41;
  const double _t152 = -_t80;
  const double _t153 = 0.6e1*_t79;
  const double _t154 = _t33*_t76;
  const double _t155 = -_t89;
  const double _t156 = (0.3e1 / 0.2e1)*_t40;
  const double _t157 = _t34*_t85;
  const double _t158 = (0.1e1 / 0.4e1)*_t33;
  const double _t159 = _t158*_t81;
  const double _t160 = _t146*_t148;
  const double _t161 = _t148*_t151;
  const double _t162 = _t18*_t90;
  const double _t163 = (0.1e1 / 0.4e1)*_t18;
  const double _t164 = _t163*_t89;
  const double _t165 = _t161*_t81;
  const double _t166 = 0.6e1*_t92;
  const double _t167 = _t14*params->b;
  const double _t168 = _t10*_t49;
  const double _t169 = _t18*_t97;
  const double _t170 = _t158*_t50;
  const double _t171 = _t18*_t75;
  const double _t172 = _t50*_t85;
  const double _t173 = _t50*_t75;
  const double _t174 = _t50*_t90;
  const double _t175 = _t155*_t50;
  const double _t176 = _t43*_t75;
  const double _t177 = (0.1e1 / 0.2e1)*_t40;
  const double _t178 = 0.2e1*_t90;
  const double _t179 = (0.3e1 / 0.2e1)*_t168;
  const double _t180 = _t102*_t18;
  const double _t181 = _t43*_t81;
  const double _t182 = _t181*_t50;
  const double _t183 = _t108*_t146;
  const double _t184 = _t104*_t9;
  const double _t185 = (0.81e2 / 0.2e1)*_t49*_t8;
  const double _t186 = _t108*_t160;
  const double _t187 = 0.2e1*_t111;
  const double _t188 = _t112*_t146;
  const double _t189 = _t111*_t50;
  const double _t190 = _t168*_t55;
  const double _t191 = _t112*_t160;
  const double _t192 = _t73*_t97;
  const double _t193 = _t27*params->b;
  const double _t194 = (0.1e1 / 0.2e1)*_t11;
  const double _t195 = _t49*_t54;
  const double _t196 = _t21*_t31;
  const double _t197 = _t120*_t196;
  const double _t198 = _t122*_t146*_t56;
  const double _t199 = _t10*_t53;
  const double _t200 = _t199*_t8;
  const double _t201 = -0.2e1*_t44 - 0.2e1*_t46 - 0.2e1*_t47 + _t87;
  const double _t202 = _t128*_t50;
  const double _t203 = _t129*_t183;
  const double _t204 = _t183*_t55;
  const double _t205 = _t129*_t75;
  const double _t206 = _t73*_t8;
  const double _t207 = _t129*_t188;
  const double _t208 = 0.3e1*_t4;
  const double _t209 = _t123*_t53;
  const double _t210 = _t119*_t55;
  const double _t211 = _t197*_t75;
  const double _t212 = _t196*_t75;
  const double _t213 = _t145*_t212;
  const double _t214 = _t196*_t90;
  const double _t215 = _t212*_t73;
  const double _t216 = _t75*_t8;
  const double _t217 = (0.243e3 / 0.4e1)*_t105;
  const double _t218 = -0.3e1*_t1 - 0.3e1*_t26 - 0.3e1*_t28 - 0.3e1*_t29;
  const double _t219 = -_t114*_t27 - _t13*_t65 - 0.4e1*_t25 - 0.2e1*_t67 - _t87;
  const double _t220 = _t27*_t45;
  const double _t221 = (0.243e3 / 0.4e1)*_t23;
  const double _t222 = _t196*_t205;
#endif

  const double f = _t12;
  out[0] = f;
#if _KMAX >= 1
  const double df_dchi = _t18*_t20;
  out[1] = df_dchi;
  const double df_dxi = _t31*_t32;
  out[2] = df_dxi;
#endif
#if _KMAX >= 2
  const double d2f_dchi2 = _t20*_t40 + _t33*_t35 + _t42*_t43;
  out[3] = d2f_dchi2;
  const double d2f_dxi_dchi = _t32*_t49 + _t42*_t50 + _t43*_t51;
  out[4] = d2f_dxi_dchi;
  const double d2f_dxi2 = _t31*_t52 + _t32*_t73 + _t51*_t55 + _t53*_t54;
  out[5] = d2f_dxi2;
#endif
#if _KMAX >= 3
  const double d3f_dchi3 = _t20*_t80 + _t40*_t42 + _t40*_t84 + _t41*_t83 + _t43*_t91 + _t74*_t76 + _t81*_t83 + _t84*_t89 + _t85*_t86;
  out[6] = d3f_dchi3;
  const double d3f_dxi_dchi2 = _t100*_t49 + _t101*_t50 + _t103*_t50 + _t18*_t98 + _t32*_t95 + _t40*_t96 + _t50*_t83 + _t50*_t91 + _t51*_t85;
  out[7] = d3f_dxi_dchi2;
  const double d3f_dxi2_dchi = _t104*_t106 + _t107*_t42 + _t109*_t110 + _t109*_t81 + _t111*_t51 + _t112*_t90 + _t113*_t43 + _t118*_t32 + _t119*_t86 + _t120*_t121 + _t49*_t52 + _t55*_t98 + _t73*_t99;
  out[8] = d3f_dxi2_dchi;
  const double d3f_dxi3 = _t109*_t129 + _t109*_t55 + _t113*_t129 + _t121*_t145 + _t121*_t73 + _t122*_t123 + _t125*_t97 + _t126*_t127 + _t128*_t51 + _t131*_t73 + _t133*_t73 + _t141*_t32;
  out[9] = d3f_dxi3;
#endif
#if _KMAX >= 4
  const double d4f_dchi4 = _t101*_t89 + _t102*_t164 + _t103*_t155 + _t103*_t40 + (0.1e1 / 0.16e2)*_t146*(_t18 * _t18 * _t18 * _t18) + _t148*_t150 + _t149*_t151 + _t150*_t81 + _t151*_t159 + _t152*_t86 + _t154*_t40 + _t154*_t89 + _t154*(_t14*_t77 + 0.3e1*_t37 + 0.6e1*_t4) + _t155*_t83 + _t156*_t157 + _t156*_t91 + _t158*_t161 + _t159*_t160 + (0.1e1 / 0.4e1)*_t162*_t40 + _t162*_t85 + _t165*_t43 + _t20*(_hc1[10]*_t16 + 0.4e1*_t14*_t147 + 0.12e2*_t79) + _t35*(_t40 * _t40) + _t35*_t40*_t89 + (0.3e1 / 0.2e1)*_t42*_t80 + _t80*_t86 + (0.1e1 / 0.2e1)*_t82*_t85 + _t84*(_t14*_t153 + 0.12e2*_t38 + 0.2e1*_t78);
  out[10] = d4f_dchi4;
  const double d4f_dxi_dchi3 = _t102*_t175 + _t102*_t177*_t50 + _t146*_t159*_t50 + _t150*_t50 + _t151*_t170 + _t151*_t182 + _t152*_t51 + _t156*_t98 + _t160*_t170 + _t160*_t182 + _t161*_t43*_t50 + _t162*_t179 + _t163*_t173*_t40 + _t164*_t173 + _t165*_t50 + (0.3e1 / 0.4e1)*_t168*_t82 + 0.3e1*_t168*_t91 + (0.3e1 / 0.2e1)*_t169*_t95 + _t171*_t172 + _t172*_t178 + _t174*_t40 + _t175*_t176 + _t179*_t180 + _t32*((0.1e1 / 0.2e1)*_t11*(_hc1[11]*_t16 + 0.3e1*_hc1[7]*_t167 + _t147*_t27 - _t153 + _t166) - _t24*_t80) + _t80*_t96 + 0.3e1*_t85*_t98 + 0.3e1*_t95*_t99;
  out[11] = d4f_dxi_dchi3;
  const double d4f_dxi2_dchi2 = _t100*_t118 + _t101*_t119 + _t103*_t119 + (0.81e2 / 0.16e2)*_t105*_t82 + _t106*_t162 + _t106*_t180 + _t106*_t34*_t40 + _t107*_t157 + _t107*_t91 + _t109*_t155 + _t109*(_t14*_t38 + (0.1e1 / 0.2e1)*_t37 + _t4) + _t113*_t155 + _t113*_t177 + _t118*_t169 + _t119*_t83 + _t119*_t91 + _t120*_t195 + _t121*(_t11*_t94 - _t40*_t71) + _t132*_t95 + _t158*_t183 + _t158*_t188 + _t171*_t189 + _t171*_t190 + _t171*_t197 + _t174*_t187 + _t177*_t192 + _t178*_t190 + _t178*_t197 + _t181*_t183 + _t181*_t188 + _t184*_t49 + _t185*_t42 + _t186*_t43 + _t186*_t81 + _t187*_t98 + _t191*_t43 + _t191*_t81 + _t192*_t85 + _t32*(_t194*(_hc1[12]*_t16 + 0.2e1*_hc1[7]*_t193 + 0.2e1*_hc1[8]*_t167 + 0.2e1*_t115 + 0.2e1*_t79 - 0.8e1*_t92) + _t40*_t64 - _t71*_t94) - _t51*_t94 + _t52*_t95;
  out[12] = d4f_dxi2_dchi2;
  const double d4f_dxi3_dchi = _t10*_t125*_t90 + _t10*_t141*_t86 + _t107*_t171*_t55 + _t109*_t111 + _t109*_t201 + _t110*_t198 + _t111*_t127*_t34 + _t113*_t201 - _t116*_t51 + _t118*_t121 + _t118*_t131 + _t118*_t133 + _t120*_t124*_t51 + _t121*(_t117 + _t142*_t18 - _t143*_t48) + _t126*_t185 + _t127*_t55*_t90 + _t128*_t174 + _t128*_t98 + _t129*_t186 + _t129*_t191 + _t129*_t211 + _t141*_t99 + _t145*_t195 + _t145*_t214 + _t148*_t198 + (0.243e3 / 0.8e1)*_t171*_t200 + _t171*_t210 + _t176*_t202 + _t178*_t210 + _t184*_t73 + _t186*_t55 + _t187*_t192 + _t189*_t205 + _t190*_t205 + _t195*_t73 + _t203*_t43 + _t204*_t43 + (0.81e2 / 0.2e1)*_t206*_t42 + _t207*_t43 + _t209*(_t11*(-_t208 + (0.3e1 / 0.2e1)*_t44 + (0.3e1 / 0.2e1)*_t46 + (0.3e1 / 0.2e1)*_t47) - _t140*_t18) + _t211*_t55 + _t213*_t43 + _t214*_t73 + _t215*_t43 + _t32*((0.1e1 / 0.2e1)*_t11*(_hc1[13]*_t16 + _hc1[8]*_t138*params->b + _hc1[9]*_t167 - 0.6e1*_t115 + _t166) - _t116*_t140 - _t136*_t18 + (0.19683e5 / 0.8e1)*_t48*_t57*_t58*_t59*_t60*_t61);
  out[13] = d4f_dxi3_dchi;
  const double d4f_dxi4 = 0.2e1*_t109*_t219 + _t113*_t219 + 0.2e1*_t121*_t141 + _t121*(_t11*_t139 - 0.1594323e7 / 0.8e1*_t135*_t6 - _t221*_t69 + (0.19683e5 / 0.4e1)*_t30*_t57*_t58*_t59*_t60*_t61) + (0.243e3 / 0.2e1)*_t122*_t21*_t216 + (0.243e3 / 0.2e1)*_t126*_t206 + 0.3e1*_t128*_t192 + _t128*_t217*_t34 + _t129*_t198 + _t129*_t204 + (0.243e3 / 0.4e1)*_t130*_t141 + 0.3e1*_t132*_t141 + _t134*_t146*(_t31 * _t31 * _t31 * _t31) - _t139*_t51 + 0.2e1*_t145*_t222 + (0.405e3 / 0.4e1)*_t145*_t51*_t8 + _t145*_t54*_t73 + _t198*_t218 + _t198*_t55 + 0.81e2*_t199*_t216*_t55 + (0.405e3 / 0.4e1)*_t200*_t205 + 0.2e1*_t202*_t205 + _t203*_t218 + _t204*_t218 + 0.3e1*_t205*_t210 + _t205*_t217*_t55 + 0.81e2*_t206*_t51 + _t207*_t218 + _t209*(_t144 + _t63*((0.6561e4 / 0.4e1)*_t2 + (0.6561e4 / 0.4e1)*_t5 + 0.6561e4 / 0.4e1)) + _t209*(_t11*(_t208 + 0.3e1*_t220 + 0.3e1*_t25 + (0.3e1 / 0.2e1)*_t66 + (0.3e1 / 0.2e1)*_t67) - _t221*_t30 + _t63*((0.19683e5 / 0.8e1)*_t2 + (0.19683e5 / 0.8e1)*_t5 + 0.19683e5 / 0.8e1)) + _t209*(_t11*(_t220 + _t25 + _t4 + (0.1e1 / 0.2e1)*_t66 + (0.1e1 / 0.2e1)*_t67) + _t63*((0.6561e4 / 0.8e1)*_t2 + (0.6561e4 / 0.8e1)*_t5 + 0.6561e4 / 0.8e1) + _t72) + _t213*_t55 + 0.2e1*_t215*_t55 + _t222*_t73 + _t32*((0.129140163e9 / 0.16e2)*xc_powi(M_CBRT3, 8)*_t6*_t7*((params->b) * (params->b) * (params->b) * (params->b))/(xc_powi(M_CBRTPI, 8)*xc_powi(_t10, 5)) - 0.1594323e7 / 0.4e1*_t135*_t30 - _t139*_t143 + _t194*(_hc0[4]*params->a*xi + _hc1[14]*_t16 + 0.4e1*_hc1[9]*_t193 + 0.12e2*_t115 + 0.4e1*_t137) + (0.19683e5 / 0.4e1)*_t63*_t69) + (0.19683e5 / 0.8e1)*_t34*_t53*_t62 + _t54*(_t73 * _t73);
  out[14] = d4f_dxi4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(ft98_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(ft98_f0_k, _KMAX)(p, x2, u, _hc0);

  const double f = _hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0;
  out[1] = df_dt;
  const double df_du = _hc0[1];
  out[2] = df_du;
  const double df_dx2 = _hc0[2];
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = _hc0[3];
  out[6] = d2f_du2;
  const double d2f_dx2_dt = 0;
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = _hc0[4];
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = _hc0[5];
  out[9] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = _hc0[6];
  out[13] = d3f_du3;
  const double d3f_dx2_dt2 = 0;
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = 0;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = _hc0[7];
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = 0;
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = _hc0[8];
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = _hc0[9];
  out[19] = d3f_dx23;
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
  const double d4f_du4 = _hc0[10];
  out[24] = d4f_du4;
  const double d4f_dx2_dt3 = 0;
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = 0;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = 0;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = _hc0[11];
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = 0;
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = 0;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = _hc0[12];
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = 0;
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = _hc0[13];
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = _hc0[14];
  out[34] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_ft98_params *params = (const mgga_x_ft98_params *)(p->params);

  const double _t1 = xc_powr(n_s, -8, 3);
  const double _t2 = xc_powr(n_s, -5, 3);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = (0.1e1 / 0.2e1)*_t5;
  const double _t7 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t11 = xc_powr(n_s, -4, 3);
  const double _t14 = (0.5e1 / 0.3e1)*_t1;
  const double _t16 = xc_powr(n_s, -11, 3);
  const double _t17 = (0.8e1 / 0.3e1)*_t16;
#endif
#if _KMAX >= 2
  const double _t21 = xc_powr(n_s, -10, 3);
  const double _t23 = xc_powr(n_s, -13, 3);
  const double _t25 = xc_powr(n_s, -16, 3);
  const double _t27 = (0.5e1 / 0.3e1)*lapl_s;
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
  const double _t91 = (0.40e2 / 0.9e1)*lapl_s;
  const double _t93 = (0.88e2 / 0.9e1)*sigma_ss;
  const double _t94 = _t25*_t29;
  const double _t96 = _t14*lapl_s;
  const double _t101 = xc_powr(n_s, -22, 3);
  const double _t103 = _t25*_t27;
  const double _t107 = _t17*sigma_ss;
  const double _t115 = (0.440e3 / 0.27e2)*_t50;
  const double _t117 = (0.1232e4 / 0.27e2)*_t76;
#endif
#if _KMAX >= 4
  const double _t142 = xc_powr(n_s, -23, 3);
  const double _t143 = xc_powr(n_s, -26, 3);
  const double _t144 = xc_powr(n_s, -29, 3);
  const double _t145 = xc_powr(n_s, -32, 3);
  const double _t149 = xc_powr(n_s, -25, 3);
  const double _t153 = _t29*_t67;
  const double _t155 = _t29*_t69;
  const double _t160 = (0.440e3 / 0.27e2)*lapl_s;
  const double _t161 = (0.1232e4 / 0.27e2)*sigma_ss;
  const double _t163 = _t34*_t93;
  const double _t168 = _t115*lapl_s;
  const double _t169 = _t117*sigma_ss;
  const double _t170 = _t48*lapl_s;
  const double _t171 = _t51*sigma_ss;
#endif
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t7)) XC_CAT(ft98_f_pf_k, _KMAX)(p, _t1*sigma_ss, _t2*lapl_s, 0, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t7)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t6/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc1);
  const double _t8 = my_piecewise3(_t7, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t9 = my_piecewise3(_t7, 0, _hc0[2]*_hc1[0]*_t2);
  const double _t10 = my_piecewise3(_t7, 0, _hc0[3]*_hc1[0]*_t1);
  const double _t12 = _hc1[2]*_t5;
  const double _t13 = (0.1e1 / 0.6e1)*_t12;
  const double _t15 = _hc0[2]*_t14;
  const double _t18 = _hc0[3]*_t17;
  const double _t19 = -_t15*lapl_s - _t18*sigma_ss;
  const double _t20 = my_piecewise3(_t7, 0, -_hc0[0]*_t11*_t13 + _hc1[0]*_t19);
#endif
#if _KMAX >= 2
  const double _t22 = my_piecewise3(_t7, 0, _hc0[6]*_hc1[0]*_t21);
  const double _t24 = my_piecewise3(_t7, 0, _hc0[8]*_hc1[0]*_t23);
  const double _t26 = my_piecewise3(_t7, 0, _hc0[9]*_hc1[0]*_t25);
  const double _t30 = _hc0[8]*_t25;
  const double _t31 = -_hc0[6]*_t28 - _t15 - _t29*_t30;
  const double _t32 = my_piecewise3(_t7, 0, -_hc0[2]*_t13/(n_s * n_s * n_s) + _hc1[0]*_t31);
  const double _t36 = -_hc0[9]*_t35 - _t18 - _t27*_t30;
  const double _t37 = my_piecewise3(_t7, 0, -_hc0[3]*_t13*_t33 + _hc1[0]*_t36);
  const double _t38 = (0.2e1 / 0.9e1)*_hc0[0];
  const double _t40 = _t12*_t39;
  const double _t41 = (0.1e1 / 0.36e2)*_hc0[0];
  const double _t44 = _hc1[5]*_t42*_t43;
  const double _t45 = _t1*_t44;
  const double _t46 = _t12*_t19;
  const double _t49 = _hc0[2]*_t48;
  const double _t52 = _hc0[3]*_t51;
  const double _t53 = _hc0[6]*_t14;
  const double _t54 = _hc0[8]*_t17;
  const double _t55 = -_t53*lapl_s - _t54*sigma_ss;
  const double _t56 = _t14*_t55;
  const double _t57 = _hc0[8]*_t14;
  const double _t58 = _hc0[9]*_t17;
  const double _t59 = -_t57*lapl_s - _t58*sigma_ss;
  const double _t60 = _t17*_t59;
  const double _t61 = _t49*lapl_s + _t52*sigma_ss - _t56*lapl_s - _t60*sigma_ss;
  const double _t62 = my_piecewise3(_t7, 0, _hc1[0]*_t61 + _t38*_t40 + _t41*_t45 - _t46*_t47);
#endif
#if _KMAX >= 3
  const double _t64 = my_piecewise3(_t7, 0, _hc0[13]*_hc1[0]*_t63);
  const double _t66 = my_piecewise3(_t7, 0, _hc0[16]*_hc1[0]*_t65);
  const double _t68 = my_piecewise3(_t7, 0, _hc0[18]*_hc1[0]*_t67);
  const double _t70 = my_piecewise3(_t7, 0, _hc0[19]*_hc1[0]*_t69);
  const double _t72 = _hc0[13]*_t65;
  const double _t73 = _hc0[16]*_t67;
  const double _t74 = -_hc0[6]*_t71 - _t27*_t72 - _t29*_t73;
  const double _t75 = my_piecewise3(_t7, 0, -_hc0[6]*_t13*_t50 + _hc1[0]*_t74);
  const double _t78 = _hc0[18]*_t69;
  const double _t79 = -_hc0[8]*_t77 - _t27*_t73 - _t29*_t78;
  const double _t80 = my_piecewise3(_t7, 0, -_hc0[8]*_t13*_t76 + _hc1[0]*_t79);
  const double _t84 = _hc0[19]*_t83;
  const double _t85 = -_hc0[9]*_t82 - _t27*_t78 - _t29*_t84;
  const double _t86 = my_piecewise3(_t7, 0, -_hc0[9]*_t13*_t81 + _hc1[0]*_t85);
  const double _t87 = (0.2e1 / 0.9e1)*_t12;
  const double _t88 = (0.1e1 / 0.36e2)*_t44;
  const double _t89 = _t12*_t47;
  const double _t90 = _hc0[6]*_t25;
  const double _t92 = _hc0[8]*_t34;
  const double _t95 = -_hc0[13]*_t28 - _hc0[16]*_t94 - _t53;
  const double _t97 = -_hc0[16]*_t28 - _hc0[18]*_t94 - _t57;
  const double _t98 = _t17*_t97;
  const double _t99 = _t49 - _t56 + _t90*_t91 + _t92*_t93 - _t95*_t96 - _t98*sigma_ss;
  const double _t100 = my_piecewise3(_t7, 0, _hc0[2]*_t23*_t88 + _hc0[2]*_t33*_t87 + _hc1[0]*_t99 - _t31*_t89);
  const double _t102 = _hc0[9]*_t101;
  const double _t104 = -_hc0[16]*_t103 - _hc0[18]*_t35 - _t54;
  const double _t105 = _t104*_t14;
  const double _t106 = -_hc0[18]*_t103 - _hc0[19]*_t35 - _t58;
  const double _t108 = _t102*_t93 - _t105*lapl_s - _t106*_t107 + _t52 - _t60 + _t91*_t92;
  const double _t109 = my_piecewise3(_t7, 0, _hc0[3]*_t25*_t88 + _hc0[3]*_t63*_t87 + _hc1[0]*_t108 - _t36*_t89);
  const double _t110 = _hc1[9]/M_PI;
  const double _t111 = _t110*_t33;
  const double _t112 = (0.14e2 / 0.27e2)*_t12;
  const double _t113 = (0.1e1 / 0.9e1)*_t44;
  const double _t114 = _hc1[2]*_t11*_t6;
  const double _t116 = _hc0[2]*_t115;
  const double _t118 = _hc0[3]*_t117;
  const double _t119 = _hc0[6]*_t48;
  const double _t120 = _hc0[8]*_t51;
  const double _t121 = _hc0[13]*_t14;
  const double _t122 = _hc0[16]*_t17;
  const double _t123 = -_t121*lapl_s - _t122*sigma_ss;
  const double _t124 = _t123*_t14;
  const double _t125 = _hc0[16]*_t14;
  const double _t126 = _hc0[18]*_t17;
  const double _t127 = -_t125*lapl_s - _t126*sigma_ss;
  const double _t128 = _t127*_t17;
  const double _t129 = _t119*lapl_s + _t120*sigma_ss - _t124*lapl_s - _t128*sigma_ss;
  const double _t130 = _t129*_t14;
  const double _t131 = _hc0[8]*_t48;
  const double _t132 = _hc0[9]*_t51;
  const double _t133 = _t127*_t14;
  const double _t134 = _hc0[18]*_t14;
  const double _t135 = _hc0[19]*_t17;
  const double _t136 = -_t134*lapl_s - _t135*sigma_ss;
  const double _t137 = _t136*_t17;
  const double _t138 = _t131*lapl_s + _t132*sigma_ss - _t133*lapl_s - _t137*sigma_ss;
  const double _t139 = _t138*_t17;
  const double _t140 = -_t116*lapl_s - _t118*sigma_ss - _t130*lapl_s - _t139*sigma_ss + (0.80e2 / 0.9e1)*_t16*_t55*lapl_s + (0.176e3 / 0.9e1)*_t50*_t59*sigma_ss;
  const double _t141 = my_piecewise3(_t7, 0, -_hc0[0]*_t112*_t21 - _hc0[0]*_t113*_t16 + _hc1[0]*_t140 + (0.2e1 / 0.3e1)*_hc1[2]*_t19*_t3*_t39*_t4 + (0.1e1 / 0.12e2)*_hc1[5]*_t1*_t19*_t42*_t43 - _t111*_t41 - _t114*_t61);
#endif
#if _KMAX >= 4
  const double _t146 = _hc0[24]*_t27;
  const double _t147 = _hc0[28]*_t143;
  const double _t148 = _hc0[31]*_t144;
  const double _t150 = _hc0[33]*_t145;
  const double _t151 = _hc0[34]*_t29;
  const double _t152 = _hc0[13]*_t91;
  const double _t154 = _hc0[28]*_t27;
  const double _t156 = _hc0[31]*_t27;
  const double _t157 = _hc0[19]*_t93;
  const double _t158 = _hc0[2]*_t76;
  const double _t159 = (0.1e1 / 0.36e2)*_t110;
  const double _t162 = _hc0[8]*_t101;
  const double _t164 = -_hc0[28]*_t28 - _hc0[31]*_t94 - _t125;
  const double _t165 = _hc0[16]*_t91;
  const double _t166 = _hc0[3]*_t81;
  const double _t167 = -_hc0[31]*_t103 - _hc0[33]*_t35 - _t126;
  const double _t172 = -_hc0[28]*_t96 - _hc0[31]*_t107;
  const double _t173 = -_hc0[31]*_t96 - _hc0[33]*_t107;
  const double _t174 = _hc0[16]*_t170 + _hc0[18]*_t171 - _t107*_t173 - _t172*_t96;
#endif

  const double f = my_piecewise3(_t7, 0, _t8*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = 0;
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t7, 0, _t9*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t7, 0, _t10*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t7, 0, _t20*n_s + _t8);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = 0;
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t7, 0, _t22*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = 0;
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, _t24*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t7, 0, _t26*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = 0;
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t7, 0, _t32*n_s + _t9);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t7, 0, _t10 + _t37*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t7, 0, 0.2e1*_t20 + _t62*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = 0;
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t7, 0, _t64*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = 0;
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t7, 0, _t66*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = 0;
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t7, 0, _t68*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t7, 0, _t70*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = 0;
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t7, 0, _t22 + _t75*n_s);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = 0;
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, _t24 + _t80*n_s);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t7, 0, _t26 + _t86*n_s);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = 0;
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t7, 0, _t100*n_s + 0.2e1*_t32);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t7, 0, _t109*n_s + 0.2e1*_t37);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t7, 0, _t141*n_s + 0.3e1*_t62);
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
  const double d4f_dlapl_s4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[24]*_hc1[0]*_t81));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = 0;
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[28]*_hc1[0]*_t142));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = 0;
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[31]*_hc1[0]*_t143));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = 0;
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[33]*_hc1[0]*_t144));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t7, 0, n_s*my_piecewise3(_t7, 0, _hc0[34]*_hc1[0]*_t145));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = 0;
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t7, 0, _t64 + n_s*my_piecewise3(_t7, 0, -_hc0[13]*_t13*_t34 + _hc1[0]*(-_t142*_t146 - _t147*_t29 - 0.5e1*_t72)));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = 0;
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t7, 0, _t66 + n_s*my_piecewise3(_t7, 0, -_hc0[16]*_t101*_t13 + _hc1[0]*(-_t147*_t27 - _t148*_t29 - 0.6e1*_t73)));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = 0;
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t7, 0, _t68 + n_s*my_piecewise3(_t7, 0, -_hc0[18]*_t13*_t149 + _hc1[0]*(-_t148*_t27 - _t150*_t29 - 0.7e1*_t78)));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t7, 0, _t70 + n_s*my_piecewise3(_t7, 0, -_hc0[19]*_t13/xc_powr(n_s, 28, 3) + _hc1[0]*(-_t150*_t27 - _t151/xc_powr(n_s, 35, 3) - 0.8e1*_t84)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = 0;
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t7, 0, 0.2e1*_t75 + n_s*my_piecewise3(_t7, 0, _hc0[6]*_t65*_t88 + _hc0[6]*_t76*_t87 + _hc1[0]*(_hc0[16]*_t69*_t93 - 0.10e2 / 0.3e1*_t1*_t95 - _t107*(-_hc0[16]*_t71 - _hc0[31]*_t153 - _t154*_t65) + _t152*_t67 + (0.80e2 / 0.9e1)*_t90 - _t96*(-_hc0[13]*_t71 - _hc0[28]*_t153 - _t146*_t65)) - _t74*_t89));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = 0;
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t7, 0, 0.2e1*_t80 + n_s*my_piecewise3(_t7, 0, _hc0[8]*_t67*_t88 + _hc0[8]*_t81*_t87 + _hc1[0]*((0.40e2 / 0.9e1)*_hc0[16]*_t69*lapl_s + (0.88e2 / 0.9e1)*_hc0[18]*_t83*sigma_ss + (0.128e3 / 0.9e1)*_hc0[8]*_t34 - _t105 - _t107*(-_hc0[18]*_t77 - _hc0[33]*_t155 - _t156*_t67) - _t96*(-_hc0[16]*_t77 - _hc0[31]*_t155 - _t154*_t67) - _t98) - _t79*_t89));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t7, 0, 0.2e1*_t86 + n_s*my_piecewise3(_t7, 0, _hc0[9]*_t142*_t87 + _hc0[9]*_t69*_t88 + _hc1[0]*(_hc0[18]*_t83*_t91 + (0.176e3 / 0.9e1)*_t102 - 0.16e2 / 0.3e1*_t106*_t16 - _t107*(-_hc0[19]*_t82 - _hc0[33]*_t27*_t69 - _t151*_t83) + _t157/xc_powi(n_s, 10) - _t96*(-_hc0[18]*_t82 - _hc0[33]*_t29*_t83 - _t156*_t69)) - _t85*_t89));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = 0;
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t7, 0, 0.3e1*_t100 + n_s*my_piecewise3(_t7, 0, -_hc0[2]*_t112*_t63 - _hc0[2]*_t113*_t25 + _hc1[0]*(-_hc0[6]*_t160*_t34 - _t107*(_hc0[18]*_t163 - _t107*(-_hc0[31]*_t28 - _hc0[33]*_t94 - _t134) + _t131 - _t133 - _t164*_t96 + _t165*_t25) - _t116 - _t130 + (0.80e2 / 0.9e1)*_t16*_t55 + (0.80e2 / 0.9e1)*_t16*_t95*lapl_s - _t161*_t162 + (0.176e3 / 0.9e1)*_t50*_t97*sigma_ss - _t96*(_hc0[16]*_t163 - _t107*_t164 + _t119 - _t124 + _t152*_t25 - _t96*(-_hc0[24]*_t28 - _hc0[28]*_t94 - _t121))) + (0.2e1 / 0.3e1)*_hc1[2]*_t3*_t31*_t39*_t4 + (0.1e1 / 0.12e2)*_hc1[5]*_t1*_t31*_t42*_t43 - _t114*_t99 - _t158*_t159));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t7, 0, 0.3e1*_t109 + n_s*my_piecewise3(_t7, 0, -_hc0[3]*_t112*_t65 - _hc0[3]*_t113*_t34 + _hc1[0]*(-_hc0[9]*_t149*_t161 + (0.80e2 / 0.9e1)*_t104*_t16*lapl_s + (0.176e3 / 0.9e1)*_t106*_t50*sigma_ss - _t107*(_hc0[18]*_t34*_t91 + _t101*_t157 - _t107*(-_hc0[33]*_t103 - _hc0[34]*_t35 - _t135) + _t132 - _t137 - _t167*_t96) - _t118 - _t139 - _t160*_t162 + (0.176e3 / 0.9e1)*_t50*_t59 - _t96*(_hc0[18]*_t101*_t93 - _t107*_t167 + _t120 - _t128 + _t165*_t34 - _t96*(-_hc0[28]*_t103 - _hc0[31]*_t35 - _t122))) + (0.2e1 / 0.3e1)*_hc1[2]*_t3*_t36*_t39*_t4 + (0.1e1 / 0.12e2)*_hc1[5]*_t1*_t36*_t42*_t43 - _t108*_t114 - _t159*_t166));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t7, 0, 0.4e1*_t141 + n_s*my_piecewise3(_t7, 0, (0.1e1 / 0.216e3)*_hc0[0]*_hc1[14]*_t25*_t3/(M_PI * M_CBRTPI) + (0.140e3 / 0.81e2)*_hc0[0]*_t12*_t23 + (0.40e2 / 0.81e2)*_hc0[0]*_t44*_t50 + _hc1[0]*(-_t107*(-_hc0[8]*_t168 - _hc0[9]*_t169 - _t107*(_hc0[18]*_t170 + _hc0[19]*_t171 - _t107*(-_hc0[33]*_t96 - _hc0[34]*_t107) - _t173*_t96) + (0.80e2 / 0.9e1)*_t127*_t16*lapl_s + (0.176e3 / 0.9e1)*_t136*_t50*sigma_ss - _t174*_t96) + (0.40e2 / 0.3e1)*_t129*_t16*lapl_s + (0.88e2 / 0.3e1)*_t138*_t50*sigma_ss + (0.6160e4 / 0.81e2)*_t158*lapl_s + (0.20944e5 / 0.81e2)*_t166*sigma_ss - 0.440e3 / 0.9e1*_t50*_t55*lapl_s - 0.1232e4 / 0.9e1*_t59*_t76*sigma_ss - _t96*(-_hc0[6]*_t168 - _hc0[8]*_t169 - _t107*_t174 + (0.80e2 / 0.9e1)*_t123*_t16*lapl_s + (0.176e3 / 0.9e1)*_t127*_t50*sigma_ss - _t96*(_hc0[13]*_t170 + _hc0[16]*_t171 - _t107*_t172 - _t96*(-_hc0[24]*_t96 - _hc0[28]*_t107)))) - 0.2e1 / 0.3e1*_t11*_t12*_t140 + _t110*_t38*_t63 - 0.1e1 / 0.9e1*_t111*_t19 - 0.4e1 / 0.9e1*_t16*_t19*_t44 - 0.56e2 / 0.27e2*_t21*_t46 + (0.4e1 / 0.3e1)*_t40*_t61 + (0.1e1 / 0.6e1)*_t45*_t61));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_ft98_params *params = (const mgga_x_ft98_params *)(p->params);
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