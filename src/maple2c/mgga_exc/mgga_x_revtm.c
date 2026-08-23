/*
  Generated from python/mgga_exc/mgga_x_revtm.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_revtm
*/

#ifndef _MGGA_X_REVTM_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_REVTM_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_REVTM_HELPER_BODIES
#include "mgga_x_revtm.c"
#undef _MGGA_X_REVTM_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_REVTM_HELPER_BODIES
#include "mgga_x_revtm.c"
#undef _MGGA_X_REVTM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_REVTM_HELPER_BODIES
#include "mgga_x_revtm.c"
#undef _MGGA_X_REVTM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_REVTM_HELPER_BODIES
#include "mgga_x_revtm.c"
#undef _MGGA_X_REVTM_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_REVTM_HELPER_BODIES
#include "mgga_x_revtm.c"
#undef _MGGA_X_REVTM_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_revtm.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_REVTM_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_p_pf_k, _KMAX)(const xc_func_type *p, double x2, double *out) {

  const double _t1 = (0.1e1 / 0.24e2)*xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);

  const double f = _t1*x2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = _t1;
  out[1] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = 0;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_y_pf_k, _KMAX)(const xc_func_type *p, double x2, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_p_pf_k, _KMAX)(p, x2, _hc0);

  const double f = 0.13927823999999997*_hc0[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = 0.13927823999999997*_hc0[1];
  out[1] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = 0;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_f0_pf_k, _KMAX)(const xc_func_type *p, double x2, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_y_pf_k, _KMAX)(p, x2, _hc0);
  const double _t1 = 79.873000000000005*((_hc0[0]) * (_hc0[0])) + (0.700e3 / 0.27e2)*_hc0[0] + 0.1e1;
#if _KMAX >= 1
  const double _t2 = 15.974600000000002*_hc0[0];
  const double _t3 = _hc0[1]*_t2 + (0.70e2 / 0.27e2)*_hc0[1];
  const double _t4 = pow(_t1, -0.9e1 / 0.10e2);
#endif
#if _KMAX >= 2
  const double _t5 = ((_hc0[1]) * (_hc0[1]));
  const double _t6 = _hc0[2]*_t2 + (0.70e2 / 0.27e2)*_hc0[2] + 15.974600000000002*_t5;
  const double _t7 = 143.7714*_hc0[0];
  const double _t8 = -_hc0[1]*_t7 - 0.70e2 / 0.3e1*_hc0[1];
  const double _t9 = pow(_t1, -0.19e2 / 0.10e2);
  const double _t10 = _t3*_t9;
#endif
#if _KMAX >= 3
  const double _t11 = _hc0[1]*_hc0[2];
  const double _t12 = _hc0[3]*_t2 + (0.70e2 / 0.27e2)*_hc0[3] + 47.923800000000007*_t11;
  const double _t13 = -_hc0[2]*_t7 - 0.70e2 / 0.3e1*_hc0[2] - 143.7714*_t5;
  const double _t14 = _t8*_t9;
  const double _t15 = 303.51740000000001*_hc0[0];
  const double _t16 = -_hc0[1]*_t15 - 0.1330e4 / 0.27e2*_hc0[1];
  const double _t17 = pow(_t1, -0.29e2 / 0.10e2);
  const double _t18 = _t17*_t3*_t8;
#endif
#if _KMAX >= 4
  const double _t19 = 0.3e1*_t6;
  const double _t20 = _t16*_t17;
#endif

  const double f = pow(_t1, 0.1e1 / 0.10e2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = _t3*_t4;
  out[1] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = _t10*_t8 + _t4*_t6;
  out[2] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dx23 = _t10*_t13 + _t12*_t4 + 0.2e1*_t14*_t6 + _t16*_t18;
  out[3] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dx24 = _t10*(-_hc0[3]*_t7 - 0.70e2 / 0.3e1*_hc0[3] - 431.31420000000003*_t11) + 0.3e1*_t12*_t14 + _t13*_t19*_t9 + 0.2e1*_t13*_t20*_t3 + _t18*(-_hc0[2]*_t15 - 0.1330e4 / 0.27e2*_hc0[2] - 303.51740000000001*_t5) + _t19*_t20*_t8 + _t4*(63.898400000000009*_hc0[1]*_hc0[3] + 47.923800000000007*((_hc0[2]) * (_hc0[2])) + _hc0[4]*_t2 + (0.70e2 / 0.27e2)*_hc0[4]) + _t16*_t3*_t8*(-463.26339999999999*_hc0[0]*_hc0[1] - 0.2030e4 / 0.27e2*_hc0[1])/pow(_t1, 0.39e2 / 0.10e2);
  out[4] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_R_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_p_pf_k, _KMAX)(p, x2, _hc0);
  const double _t1 = (M_PI * M_CBRTPI);
  const double _t2 = xc_powr(0.6e1, 1, 3)/_t1;
  const double _t3 = 0.0065930453703703694*_t2;

  const double f = 1.5346398666666663*_hc0[0] + (0.5e1 / 0.9e1)*_t2*(0.043662396000000027*xc_powr(0.6e1, 2, 3)*_t1 - 0.14554132000000009*t) - _t3*x2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -0.080856288888888933*_t2;
  out[1] = df_dt;
  const double df_dx2 = 1.5346398666666663*_hc0[1] - _t3;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_fx_DME_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_f0_pf_k, _KMAX)(p, x2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_R_pf_k, _KMAX)(p, x2, t, _hc1);
  const double _t1 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t2 = (0.7e1 / 0.9e1)*_t1;
#if _KMAX >= 1
  const double _t3 = 0.2e1/((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t4 = xc_powi((_hc0[0]), -5);
  const double _t5 = _hc0[1]*_t4;
  const double _t6 = (0.28e2 / 0.9e1)*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = _hc0[2]*_t4;
  const double _t8 = (0.28e2 / 0.9e1)*_t7;
  const double _t9 = ((_hc0[1]) * (_hc0[1]));
  const double _t10 = xc_powi((_hc0[0]), -6);
#endif
#if _KMAX >= 3
  const double _t11 = _hc0[3]*_t4;
  const double _t12 = (0.28e2 / 0.9e1)*_t11;
  const double _t13 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t14 = xc_powi((_hc0[0]), -7);
  const double _t15 = _t13*_t14;
  const double _t16 = (0.280e3 / 0.3e1)*_t15;
#endif
#if _KMAX >= 4
  const double _t17 = _hc0[1]*_hc0[3];
  const double _t18 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t19 = ((_hc0[2]) * (_hc0[2]));
#endif

  const double f = _hc1[0]*_t2 + (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t2;
  out[1] = df_dt;
  const double df_dx2 = -_hc0[1]*_t3 - _hc1[0]*_t6 + (0.7e1 / 0.9e1)*_hc1[2]*_t1;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = -_hc1[1]*_t6;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = -_hc0[2]*_t3 + (0.140e3 / 0.9e1)*_hc1[0]*_t10*_t9 - _hc1[0]*_t8 - 0.56e2 / 0.9e1*_hc1[2]*_t5 + (0.7e1 / 0.9e1)*_hc1[5]*_t1 + 0.6e1*_t1*_t9;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = 0;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = (0.140e3 / 0.9e1)*_hc1[1]*_t10*_t9 - _hc1[1]*_t8;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = (0.140e3 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[0]*_t10 + 0.18e2*_hc0[1]*_hc0[2]*_t1 - _hc0[3]*_t3 - _hc1[0]*_t12 - _hc1[0]*_t16 + (0.140e3 / 0.3e1)*_hc1[2]*_t10*_t9 - 0.28e2 / 0.3e1*_hc1[2]*_t7 - 0.28e2 / 0.3e1*_hc1[5]*_t5 + (0.7e1 / 0.9e1)*_hc1[9]*_t1 - 0.24e2*_t13*_t4;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = 0;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = 0;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = (0.140e3 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[1]*_t10 - _hc1[1]*_t12 - _hc1[1]*_t16;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = (0.560e3 / 0.3e1)*_hc0[1]*_hc0[2]*_hc1[2]*_t10 - 0.560e3*_hc0[2]*_hc1[0]*_t14*_t9 - 0.28e2 / 0.9e1*_hc0[4]*_hc1[0]*_t4 - _hc0[4]*_t3 + (0.560e3 / 0.9e1)*_hc1[0]*_t10*_t17 + (0.140e3 / 0.3e1)*_hc1[0]*_t10*_t19 + _hc1[14]*_t2 - 0.112e3 / 0.9e1*_hc1[2]*_t11 - 0.1120e4 / 0.3e1*_hc1[2]*_t15 + (0.280e3 / 0.3e1)*_hc1[5]*_t10*_t9 - 0.56e2 / 0.3e1*_hc1[5]*_t7 - 0.112e3 / 0.9e1*_hc1[9]*_t5 + 0.24e2*_t1*_t17 + 0.18e2*_t1*_t19 + 0.120e3*_t10*_t18 - 0.144e3*_t7*_t9 + (0.1960e4 / 0.3e1)*_hc1[0]*_t18/xc_powi((_hc0[0]), 8);
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_tratio_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  const double _t1 = (0.1e1 / 0.8e1)/t;
  const double _t2 = _t1*x2;
  const double _t3 = 1.0 > _t2;
#if _KMAX >= 1
  const double _t4 = (0.1e1 / 0.8e1)/(t * t);
#endif
#if _KMAX >= 2
  const double _t5 = (0.1e1 / 0.4e1)/(t * t * t);
#endif
#if _KMAX >= 3
  const double _t6 = (0.3e1 / 0.4e1)/(t * t * t * t);
#endif

  const double f = my_piecewise3(_t3, _t2, 1.0);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = my_piecewise3(_t3, -_t4*x2, 0);
  out[1] = df_dt;
  const double df_dx2 = my_piecewise3(_t3, _t1, 0);
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = my_piecewise3(_t3, _t5*x2, 0);
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = my_piecewise3(_t3, -_t4, 0);
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = 0;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = my_piecewise3(_t3, -_t6*x2, 0);
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = my_piecewise3(_t3, _t5, 0);
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = 0;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = 0;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = my_piecewise3(_t3, 0.3e1*x2/xc_powi(t, 5), 0);
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = my_piecewise3(_t3, -_t6, 0);
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = 0;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = 0;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 0;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_w_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_tratio_pf_k, _KMAX)(p, x2, t, _hc0);
  const double _t1 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t2 = _t1 + 0.1e1;
  const double _t3 = (0.1e1 / (_t2 * _t2));
  const double _t4 = ((_hc0[0]) * (_hc0[0]));
  const double _t5 = 0.3e1*_t1 + _t4;
#if _KMAX >= 1
  const double _t6 = 0.2e1*_hc0[0];
  const double _t7 = 0.9e1*_t4;
  const double _t8 = _hc0[1]*_t6 + _hc0[1]*_t7;
  const double _t9 = 0.6e1*_hc0[1];
  const double _t10 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t11 = _t10*_t4;
  const double _t12 = _t11*_t5;
  const double _t13 = _hc0[2]*_t6 + _hc0[2]*_t7;
  const double _t14 = 0.6e1*_t12;
#endif
#if _KMAX >= 2
  const double _t15 = ((_hc0[1]) * (_hc0[1]));
  const double _t16 = _t10*_t15;
  const double _t17 = 0.12e2*_t5;
  const double _t18 = _hc0[0]*_t17;
  const double _t19 = 0.12e2*_t8;
  const double _t20 = _hc0[1]*_t11;
  const double _t21 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t22 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t23 = 0.18e2*_hc0[0];
  const double _t24 = _hc0[3]*_t6 + _hc0[3]*_t7 + _t15*_t23 + 0.2e1*_t15;
  const double _t25 = _hc0[1]*_hc0[2];
  const double _t26 = _t10*_t25;
  const double _t27 = _t11*_t13;
  const double _t28 = _hc0[2]*_t11;
  const double _t29 = 0.6e1*_t28;
  const double _t30 = 0.2e1*_hc0[2];
  const double _t31 = _hc0[2]*_t23;
  const double _t32 = _hc0[1]*_t30 + _hc0[1]*_t31 + _hc0[4]*_t6 + _hc0[4]*_t7;
  const double _t33 = ((_hc0[2]) * (_hc0[2]));
  const double _t34 = _t23*_t33 + 0.2e1*_t33;
  const double _t35 = _t10*_t33;
  const double _t36 = 0.12e2*_t13;
#endif
#if _KMAX >= 3
  const double _t37 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t38 = _t10*_t37;
  const double _t39 = 0.36e2*_hc0[0];
  const double _t40 = _t10*_t5;
  const double _t41 = _t39*_t40;
  const double _t42 = _hc0[1]*_hc0[3];
  const double _t43 = _t16*_t39;
  const double _t44 = _hc0[3]*_t11;
  const double _t45 = 0.18e2*_t44;
  const double _t46 = xc_powi((_hc0[0]), 6);
  const double _t47 = _t37*_t46;
  const double _t48 = xc_powi(_t2, -5);
  const double _t49 = _t48*_t5;
  const double _t50 = 0.648e3*_t49;
  const double _t51 = 0.54e2*_hc0[0];
  const double _t52 = _hc0[1]*_t51;
  const double _t53 = _hc0[3]*_t52 + _hc0[3]*_t9 + _hc0[6]*_t6 + _hc0[6]*_t7 + 0.18e2*_t37;
  const double _t54 = 0.18e2*_t20;
  const double _t55 = 0.24e2*_hc0[0];
  const double _t56 = _t40*_t55;
  const double _t57 = _hc0[1]*_hc0[4];
  const double _t58 = _hc0[2]*_hc0[3]*_t10;
  const double _t59 = _hc0[2]*_t15;
  const double _t60 = _t10*_t59;
  const double _t61 = _t26*_t55;
  const double _t62 = _hc0[0]*_t16;
  const double _t63 = 0.6e1*_t27;
  const double _t64 = _hc0[4]*_t11;
  const double _t65 = _t46*_t50;
  const double _t66 = 0.12e2*_t32;
  const double _t67 = 0.4e1*_hc0[4];
  const double _t68 = _hc0[4]*_t39;
  const double _t69 = _hc0[1]*_t67 + _hc0[1]*_t68 + _hc0[3]*_t30 + _hc0[3]*_t31 + _hc0[7]*_t6 + _hc0[7]*_t7 + 0.18e2*_t59;
  const double _t70 = _hc0[2]*_hc0[4];
  const double _t71 = _hc0[1]*_t35;
  const double _t72 = _hc0[0]*_t35;
  const double _t73 = 0.18e2*_t33;
  const double _t74 = _hc0[1]*_t73 + _hc0[2]*_t67 + _hc0[2]*_t68;
  const double _t75 = _hc0[1]*_t33;
  const double _t76 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t77 = _t10*_t76;
  const double _t78 = _t35*_t39;
  const double _t79 = _t46*_t76;
  const double _t80 = 0.18e2*_t28;
#endif
#if _KMAX >= 4
  const double _t81 = _hc0[1]*_hc0[6];
  const double _t82 = 0.48e2*_hc0[0];
  const double _t83 = ((_hc0[3]) * (_hc0[3]));
  const double _t84 = _hc0[3]*_t15;
  const double _t85 = 0.48e2*_t8;
  const double _t86 = _t10*_t8;
  const double _t87 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t88 = _t11*_t8;
  const double _t89 = 0.7776e4*xc_powi((_hc0[0]), 5)*_t49;
  const double _t90 = xc_powi((_hc0[0]), 8);
  const double _t91 = xc_powi(_t2, -6);
  const double _t92 = _t46*_t49;
  const double _t93 = _t47*_t48;
  const double _t94 = 0.72e2*_hc0[0];
  const double _t95 = _hc0[3]*_hc0[4];
  const double _t96 = _hc0[3]*_t25;
  const double _t97 = 0.36e2*_hc0[4]*_t5;
  const double _t98 = _t10*_t13;
  const double _t99 = 0.1944e4*_t92;
  const double _t100 = _t46*_t48;
  const double _t101 = 0.1944e4*_t100;
  const double _t102 = _t26*_t39;
  const double _t103 = 0.18e2*_t64;
  const double _t104 = _hc0[2]*_hc0[7];
  const double _t105 = _hc0[4]*_t25;
  const double _t106 = ((_hc0[4]) * (_hc0[4]));
  const double _t107 = 0.48e2*_t13;
  const double _t108 = _hc0[0]*_t10;
  const double _t109 = _t48*_t79;
  const double _t110 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
#endif

  const double f = _t3*_t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_t12*_t9 + _t3*_t8;
  out[1] = df_dt;
  const double df_dx2 = -_hc0[2]*_t14 + _t13*_t3;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_hc0[3]*_t14 + 0.54e2*_t15*_t21*_t22*_t5 - _t16*_t18 - _t19*_t20 + _t24*_t3;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = 0.54e2*_hc0[1]*_hc0[2]*_t21*_t22*_t5 - _hc0[4]*_t14 - _t18*_t26 - _t27*_t9 - _t29*_t8 + _t3*_t32;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = -_t18*_t35 + 0.54e2*_t21*_t22*_t33*_t5 - _t28*_t36 + _t3*_t34;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0.162e3*_hc0[1]*_hc0[3]*_t21*_t22*_t5 - _hc0[6]*_t14 + 0.324e3*_t1*_t22*_t37*_t5 + 0.162e3*_t15*_t21*_t22*_t8 - _t17*_t38 - _t24*_t54 + _t3*_t53 - _t41*_t42 - _t43*_t8 - _t45*_t8 - _t47*_t50;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = 0.108e3*_hc0[1]*_hc0[2]*_t21*_t22*_t8 + 0.108e3*_hc0[1]*_hc0[4]*_t21*_t22*_t5 + 0.54e2*_hc0[2]*_hc0[3]*_t21*_t22*_t5 + 0.324e3*_hc0[2]*_t1*_t15*_t22*_t5 - _hc0[3]*_t63 - _hc0[7]*_t14 + 0.54e2*_t13*_t15*_t21*_t22 - _t17*_t60 - _t18*_t58 - _t19*_t64 - _t20*_t66 - _t24*_t29 + _t3*_t69 - _t36*_t62 - _t56*_t57 - _t59*_t65 - _t61*_t8;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = 0.108e3*_hc0[1]*_hc0[2]*_t13*_t21*_t22 + 0.324e3*_hc0[1]*_t1*_t22*_t33*_t5 + 0.108e3*_hc0[2]*_hc0[4]*_t21*_t22*_t5 - _t11*_t34*_t9 - _t13*_t61 - _t17*_t71 - _t19*_t72 + 0.54e2*_t21*_t22*_t33*_t8 - _t28*_t66 + _t3*_t74 - _t36*_t64 - _t56*_t70 - _t65*_t75;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = 0.324e3*_t1*_t22*_t5*_t76 + 0.162e3*_t13*_t21*_t22*_t33 - _t13*_t78 - _t17*_t77 + 0.18e2*_t3*_t76 - _t34*_t80 - _t50*_t79;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = -0.144e3*_hc0[0]*_t42*_t86 + 0.648e3*_hc0[1]*_hc0[3]*_t21*_t22*_t8 + 0.216e3*_hc0[1]*_hc0[6]*_t21*_t22*_t5 - _hc0[10]*_t14 + 0.1944e4*_hc0[3]*_t1*_t15*_t22*_t5 - 0.24e2*_hc0[6]*_t88 + 0.1296e4*_t1*_t22*_t37*_t8 + 0.324e3*_t15*_t21*_t22*_t24 - _t16*_t24*_t94 - 0.24e2*_t20*_t53 + 0.162e3*_t21*_t22*_t5*_t83 + 0.1080e4*_t22*_t4*_t5*_t87 - 0.36e2*_t24*_t44 + _t3*(_hc0[10]*_t6 + _hc0[10]*_t7 + _t51*_t83 + _t81*_t94 + 0.8e1*_t81 + 0.6e1*_t83 + 0.108e3*_t84) - _t38*_t85 - _t40*_t81*_t82 - 0.72e2*_t40*_t84 - _t41*_t83 + 0.9720e4*_t5*_t87*_t90*_t91 - 0.2592e4*_t8*_t93 - 0.3888e4*_t84*_t92 - _t87*_t89;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = 0.972e3*_hc0[1]*_hc0[2]*_hc0[3]*_t1*_t22*_t5 + 0.162e3*_hc0[1]*_hc0[2]*_t21*_t22*_t24 + 0.162e3*_hc0[1]*_hc0[3]*_t13*_t21*_t22 + 0.324e3*_hc0[1]*_hc0[4]*_t21*_t22*_t8 + 0.162e3*_hc0[1]*_hc0[7]*_t21*_t22*_t5 - _hc0[1]*_hc0[7]*_t41 - _hc0[11]*_t14 + 0.162e3*_hc0[2]*_hc0[3]*_t21*_t22*_t8 - _hc0[2]*_hc0[6]*_t10*_t18 + 0.54e2*_hc0[2]*_hc0[6]*_t21*_t22*_t5 + 0.972e3*_hc0[2]*_t1*_t15*_t22*_t8 + 0.1080e4*_hc0[2]*_t22*_t37*_t4*_t5 + 0.9720e4*_hc0[2]*_t37*_t5*_t90*_t91 - _hc0[2]*_t37*_t89 + 0.162e3*_hc0[3]*_hc0[4]*_t21*_t22*_t5 + 0.972e3*_hc0[4]*_t1*_t15*_t22*_t5 - _hc0[4]*_t15*_t99 - _hc0[6]*_t63 - 0.18e2*_hc0[7]*_t88 + 0.324e3*_t1*_t13*_t22*_t37 - _t101*_t59*_t8 - _t102*_t24 - _t103*_t24 - 0.648e3*_t13*_t93 + 0.162e3*_t15*_t21*_t22*_t32 - _t16*_t97 - _t29*_t53 + _t3*(_hc0[11]*_t6 + _hc0[11]*_t7 + 0.54e2*_hc0[3]*_t25 + 0.54e2*_hc0[4]*_t15 + _hc0[6]*_t30 + _hc0[6]*_t31 + _hc0[7]*_t52 + _hc0[7]*_t9 + _t51*_t95 + 0.6e1*_t95) - _t32*_t43 - _t32*_t45 - _t36*_t38 - _t39*_t42*_t98 - _t39*_t58*_t8 - 0.36e2*_t40*_t96 - _t41*_t95 - _t54*_t69 - _t57*_t86*_t94 - 0.36e2*_t60*_t8 - _t96*_t99;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = 0.1296e4*_hc0[1]*_hc0[2]*_hc0[4]*_t1*_t22*_t5 + 0.216e3*_hc0[1]*_hc0[2]*_t21*_t22*_t32 + 0.216e3*_hc0[1]*_hc0[4]*_t13*_t21*_t22 + 0.648e3*_hc0[1]*_t1*_t22*_t33*_t8 + 0.108e3*_hc0[2]*_hc0[3]*_t13*_t21*_t22 + 0.216e3*_hc0[2]*_hc0[4]*_t21*_t22*_t8 + 0.108e3*_hc0[2]*_hc0[7]*_t21*_t22*_t5 + 0.648e3*_hc0[2]*_t1*_t13*_t15*_t22 + 0.324e3*_hc0[3]*_t1*_t22*_t33*_t5 - _hc0[3]*_t17*_t35 - _hc0[3]*_t33*_t65 - _hc0[7]*_t11*_t36 - 0.1296e4*_t100*_t13*_t59 - 0.1296e4*_t100*_t75*_t8 - _t104*_t56 - 0.48e2*_t105*_t40 - 0.2592e4*_t105*_t92 + 0.108e3*_t106*_t21*_t22*_t5 - _t106*_t56 - _t107*_t108*_t57 - _t108*_t70*_t85 - _t13*_t55*_t58 - 0.24e2*_t13*_t60 + 0.54e2*_t15*_t21*_t22*_t34 + 0.1080e4*_t15*_t22*_t33*_t4*_t5 + 0.9720e4*_t15*_t33*_t5*_t90*_t91 - _t15*_t33*_t89 - 0.12e2*_t20*_t74 + 0.54e2*_t21*_t22*_t24*_t33 - 0.12e2*_t24*_t72 - _t26*_t32*_t82 - 0.12e2*_t28*_t69 + _t3*(_hc0[3]*_t73 + _t104*_t39 + 0.4e1*_t104 + 0.72e2*_t105 + _t106*_t39 + 0.4e1*_t106) - 0.24e2*_t32*_t64 - 0.6e1*_t34*_t44 - 0.12e2*_t34*_t62 - 0.24e2*_t71*_t8;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = 0.162e3*_hc0[1]*_hc0[2]*_t21*_t22*_t34 + 0.972e3*_hc0[1]*_t1*_t13*_t22*_t33 + 0.1080e4*_hc0[1]*_t22*_t4*_t5*_t76 - 0.108e3*_hc0[1]*_t4*_t77 + 0.9720e4*_hc0[1]*_t5*_t76*_t90*_t91 - _hc0[1]*_t76*_t89 + 0.324e3*_hc0[2]*_hc0[4]*_t13*_t21*_t22 + 0.972e3*_hc0[4]*_t1*_t22*_t33*_t5 + 0.54e2*_hc0[4]*_t3*_t33 - _hc0[4]*_t33*_t99 + 0.324e3*_t1*_t22*_t76*_t8 - _t101*_t13*_t75 - _t102*_t34 - _t103*_t34 - 0.648e3*_t109*_t8 - 0.36e2*_t13*_t71 - _t19*_t77 + 0.162e3*_t21*_t22*_t32*_t33 - _t32*_t78 - _t35*_t97 - _t70*_t94*_t98 - _t74*_t80;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 0.1296e4*_t1*_t13*_t22*_t76 - _t107*_t77 - 0.2592e4*_t109*_t13 - 0.432e3*_t11*_t110 + 0.1080e4*_t110*_t22*_t4*_t5 + 0.9720e4*_t110*_t5*_t90*_t91 - _t110*_t89 + 0.324e3*_t21*_t22*_t33*_t34 - _t34*_t35*_t94;
  out[14] = d4f_dx24;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_qtilde_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_p_pf_k, _KMAX)(p, x2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(mgga_alpha_pf_k, _KMAX)(p, x2, t, _hc1);
  const double _t1 = (0.9e1 / 0.20e2)*_hc1[0] - 0.9e1 / 0.20e2;
  const double _t2 = _hc1[0] - 0.1e1;
  const double _t3 = 0.40000000000000002*_hc1[0]*_t2 + 0.1e1;
  const double _t4 = xc_powr(_t3, -1, 2);
#if _KMAX >= 1
  const double _t5 = (0.9e1 / 0.20e2)*_t4;
  const double _t6 = 0.20000000000000001*_hc1[1];
  const double _t7 = -_hc1[0]*_t6 - _t2*_t6;
  const double _t8 = xc_powr(_t3, -3, 2);
  const double _t9 = _t1*_t8;
  const double _t10 = 0.20000000000000001*_hc1[2];
  const double _t11 = -_hc1[0]*_t10 - _t10*_t2;
#endif
#if _KMAX >= 2
  const double _t12 = ((_hc1[1]) * (_hc1[1]));
  const double _t13 = 0.40000000000000002*_t9;
  const double _t14 = _hc1[1]*_t8;
  const double _t15 = xc_powr(_t3, -5, 2);
  const double _t16 = _t1*_t15;
  const double _t17 = 0.60000000000000009*_hc1[1];
  const double _t18 = -_hc1[0]*_t17 - _t17*_t2;
  const double _t19 = _t18*_t7;
  const double _t20 = _hc1[1]*_hc1[2];
  const double _t21 = _hc1[2]*_t8;
  const double _t22 = _t11*_t16;
  const double _t23 = ((_hc1[2]) * (_hc1[2]));
  const double _t24 = 0.60000000000000009*_hc1[2];
  const double _t25 = -_hc1[0]*_t24 - _t2*_t24;
#endif
#if _KMAX >= 3
  const double _t26 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t27 = 0.54000000000000004*_t8;
  const double _t28 = _t12*_t16;
  const double _t29 = 0.80000000000000004*_t18;
  const double _t30 = xc_powr(_t3, -7, 2);
  const double _t31 = 1.0*_hc1[1];
  const double _t32 = -_hc1[0]*_t31 - _t2*_t31;
  const double _t33 = _hc1[2]*_t12;
  const double _t34 = _t16*_t20;
  const double _t35 = 1.2000000000000002*_t22;
  const double _t36 = _hc1[1]*_t23;
  const double _t37 = 0.40000000000000002*_t25;
  const double _t38 = _t16*_t23;
  const double _t39 = 0.40000000000000002*_t18;
  const double _t40 = ((_hc1[2]) * (_hc1[2]) * (_hc1[2]));
  const double _t41 = 0.80000000000000004*_t25;
  const double _t42 = 1.0*_hc1[2];
  const double _t43 = -_hc1[0]*_t42 - _t2*_t42;
#endif
#if _KMAX >= 4
  const double _t44 = _t15*_t26;
  const double _t45 = 1.4400000000000002*_t18;
  const double _t46 = _t1*_t30;
  const double _t47 = _t32*_t46;
  const double _t48 = _t12*_t47;
  const double _t49 = 1.2000000000000002*_t18;
  const double _t50 = 2.0*_t12;
  const double _t51 = _t46*_t50;
  const double _t52 = xc_powr(_t3, -9, 2);
  const double _t53 = 1.4000000000000001*_hc1[1];
  const double _t54 = -_hc1[0]*_t53 - _t2*_t53;
  const double _t55 = _t15*_t33;
  const double _t56 = _t20*_t47;
  const double _t57 = _t11*_t47;
  const double _t58 = 2.4000000000000004*_t57;
  const double _t59 = _t15*_t36;
  const double _t60 = 2.1600000000000006*_t11;
  const double _t61 = _t11*_t25*_t46;
  const double _t62 = _t23*_t47;
  const double _t63 = _t15*_t40;
  const double _t64 = _t43*_t46;
  const double _t65 = _t11*_t64;
  const double _t66 = 2.0*_t61;
  const double _t67 = 1.2000000000000002*_t23;
  const double _t68 = 1.4000000000000001*_hc1[2];
#endif

  const double f = (0.2e1 / 0.3e1)*_hc0[0] + _t1*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t5 + _t7*_t9;
  out[1] = df_dt;
  const double df_dx2 = (0.2e1 / 0.3e1)*_hc0[1] + _hc1[2]*_t5 + _t11*_t9;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_t12*_t13 + (0.9e1 / 0.10e2)*_t14*_t7 + _t16*_t19;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = (0.9e1 / 0.20e2)*_t11*_t14 - _t13*_t20 + _t18*_t22 + (0.9e1 / 0.20e2)*_t21*_t7;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = (0.9e1 / 0.10e2)*_t11*_t21 - _t13*_t23 + _t22*_t25;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = (0.27e2 / 0.20e2)*_hc1[1]*_t15*_t18*_t7 + _t1*_t18*_t30*_t32*_t7 - _t26*_t27 - _t28*_t29 - 1.2000000000000002*_t28*_t7;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = (0.9e1 / 0.10e2)*_hc1[1]*_t11*_t15*_t18 + (0.9e1 / 0.20e2)*_hc1[2]*_t15*_t18*_t7 + _t1*_t11*_t18*_t30*_t32 - _t12*_t35 - _t27*_t33 - _t29*_t34;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = (0.9e1 / 0.20e2)*_hc1[1]*_t11*_t15*_t25 + (0.9e1 / 0.10e2)*_hc1[2]*_t11*_t15*_t18 + _t1*_t11*_t25*_t30*_t32 - _t20*_t35 - _t27*_t36 - _t34*_t37 - _t38*_t39;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = (0.27e2 / 0.20e2)*_hc1[2]*_t11*_t15*_t25 + _t1*_t11*_t25*_t30*_t43 - _t23*_t35 - _t27*_t40 - _t38*_t41;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 1.4400000000000004*((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]))*_t1*_t15 + (0.9e1 / 0.5e1)*_hc1[1]*_t18*_t30*_t32*_t7 + _t1*_t18*_t32*_t52*_t54*_t7 - _t19*_t51 - _t44*_t45 - 2.1600000000000006*_t44*_t7 - _t48*_t49 - 2.4000000000000004*_t48*_t7;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = (0.27e2 / 0.20e2)*_hc1[1]*_t11*_t18*_t30*_t32 + 1.4400000000000004*_hc1[2]*_t1*_t15*_t26 + (0.9e1 / 0.20e2)*_hc1[2]*_t18*_t30*_t32*_t7 + _t1*_t11*_t18*_t32*_t52*_t54 - _t11*_t18*_t51 - 1.6200000000000003*_t11*_t44 - _t12*_t58 - _t45*_t55 - _t49*_t56 - 0.54000000000000015*_t55*_t7;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = (0.9e1 / 0.10e2)*_hc1[1]*_t11*_t25*_t30*_t32 + (0.9e1 / 0.10e2)*_hc1[2]*_t11*_t18*_t30*_t32 + _t1*_t11*_t25*_t32*_t52*_t54 + 1.4400000000000004*_t1*_t12*_t15*_t23 - 1.0800000000000001*_t18*_t59 - _t20*_t58 - 0.36000000000000004*_t25*_t55 - _t39*_t62 - _t41*_t56 - _t50*_t61 - _t55*_t60;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = 1.4400000000000004*_hc1[1]*_t1*_t15*_t40 + (0.9e1 / 0.20e2)*_hc1[1]*_t11*_t25*_t30*_t43 + (0.27e2 / 0.20e2)*_hc1[2]*_t11*_t25*_t30*_t32 + _t1*_t11*_t25*_t43*_t52*_t54 - 0.54000000000000004*_t18*_t63 - _t20*_t37*_t64 - 1.2000000000000002*_t20*_t65 - _t20*_t66 - 0.90000000000000013*_t25*_t59 - _t41*_t62 - _t57*_t67 - _t59*_t60;
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 1.4400000000000004*((_hc1[2]) * (_hc1[2]) * (_hc1[2]) * (_hc1[2]))*_t1*_t15 + (0.9e1 / 0.5e1)*_hc1[2]*_t11*_t25*_t30*_t43 + _t1*_t11*_t25*_t43*_t52*(-_hc1[0]*_t68 - _t2*_t68) - 2.4000000000000004*_t23*_t65 - _t23*_t66 - 1.4400000000000002*_t25*_t63 - _t25*_t64*_t67 - _t60*_t63;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_fx_SC_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_qtilde_pf_k, _KMAX)(p, x2, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(tm_p_pf_k, _KMAX)(p, x2, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_tratio_pf_k, _KMAX)(p, x2, t, _hc2);
  const double _t1 = (0.50e2 / 0.729e3)*_hc1[0];
  const double _t2 = _t1 + 0.10e2 / 0.81e2;
  const double _t3 = 0.1e1 - _hc2[0];
  const double _t4 = _hc0[0]*_t3;
  const double _t5 = (0.292e3 / 0.405e3)*((_hc0[0]) * (_hc0[0])) + 0.10e2*_hc1[0]*_t2 - 0.146e3 / 0.135e3*_hc2[0]*_t4 + 0.1e1;
#if _KMAX >= 1
  const double _t6 = pow(_t5, -0.9e1 / 0.10e2);
  const double _t7 = (0.292e3 / 0.2025e4)*_hc0[0];
  const double _t8 = (0.73e2 / 0.675e3)*_hc2[1];
  const double _t9 = _hc0[0]*_hc2[0];
  const double _t10 = (0.73e2 / 0.675e3)*_hc2[0];
  const double _t11 = _hc0[1]*_t3;
  const double _t12 = _hc0[1]*_t7 - _t10*_t11 - _t4*_t8 + _t8*_t9;
  const double _t13 = _hc0[0]*_t10;
  const double _t14 = _hc1[1]*_t2;
  const double _t15 = (0.73e2 / 0.675e3)*_t4;
  const double _t16 = _t10*_t3;
  const double _t17 = -_hc0[2]*_t16 + _hc0[2]*_t7 + _hc1[1]*_t1 + _hc2[2]*_t13 - _hc2[2]*_t15 + _t14;
#endif
#if _KMAX >= 2
  const double _t18 = ((_hc0[1]) * (_hc0[1]));
  const double _t19 = (0.146e3 / 0.675e3)*_hc2[1];
  const double _t20 = _hc0[1]*_hc2[0];
  const double _t21 = ((_hc2[1]) * (_hc2[1]));
  const double _t22 = (0.146e3 / 0.675e3)*_hc0[0];
  const double _t23 = -_hc0[3]*_t16 + _hc0[3]*_t7 + _hc2[3]*_t13 - _hc2[3]*_t15 - _t11*_t19 + (0.292e3 / 0.2025e4)*_t18 + _t19*_t20 + _t21*_t22;
  const double _t24 = pow(_t5, -0.19e2 / 0.10e2);
  const double _t25 = (0.292e3 / 0.225e3)*_hc0[0];
  const double _t26 = (0.73e2 / 0.75e2)*_hc2[1];
  const double _t27 = (0.73e2 / 0.75e2)*_hc0[0]*_hc2[1]*_t3 + (0.73e2 / 0.75e2)*_hc0[1]*_hc2[0]*_t3 - _hc0[1]*_t25 - _t26*_t9;
  const double _t28 = _t24*_t27;
  const double _t29 = (0.292e3 / 0.2025e4)*_hc0[2];
  const double _t30 = _hc2[2]*_t22;
  const double _t31 = _hc2[2]*_t10;
  const double _t32 = _hc0[2]*_t8;
  const double _t33 = (0.73e2 / 0.675e3)*_hc2[2];
  const double _t34 = _hc0[1]*_t29 + _hc0[1]*_t31 - _hc0[4]*_t16 + _hc0[4]*_t7 + _hc2[0]*_t32 + _hc2[1]*_t30 + _hc2[4]*_t13 - _hc2[4]*_t15 - _t11*_t33 - _t3*_t32;
  const double _t35 = ((_hc0[2]) * (_hc0[2]));
  const double _t36 = ((_hc1[1]) * (_hc1[1]));
  const double _t37 = (0.146e3 / 0.675e3)*_hc2[2];
  const double _t38 = _hc0[2]*_hc2[0];
  const double _t39 = ((_hc2[2]) * (_hc2[2]));
  const double _t40 = _hc0[2]*_t3;
  const double _t41 = -_hc0[5]*_t16 + _hc0[5]*_t7 + _t22*_t39 + (0.292e3 / 0.2025e4)*_t35 + (0.100e3 / 0.729e3)*_t36 + _t37*_t38 - _t37*_t40;
  const double _t42 = _hc1[0]*_hc1[1];
  const double _t43 = (0.73e2 / 0.75e2)*_hc2[2];
  const double _t44 = (0.73e2 / 0.75e2)*_hc0[0]*_hc2[2]*_t3 + (0.73e2 / 0.75e2)*_hc0[2]*_hc2[0]*_t3 - _hc0[2]*_t25 - 0.9e1*_t14 - 0.50e2 / 0.81e2*_t42 - _t43*_t9;
  const double _t45 = _t17*_t24;
#endif
#if _KMAX >= 3
  const double _t46 = _hc0[1]*_hc0[3];
  const double _t47 = (0.146e3 / 0.225e3)*_hc0[0];
  const double _t48 = _hc2[1]*_hc2[3];
  const double _t49 = (0.73e2 / 0.225e3)*_hc2[3];
  const double _t50 = (0.73e2 / 0.225e3)*_hc2[1];
  const double _t51 = _hc0[3]*_hc2[0];
  const double _t52 = _hc0[1]*_t21;
  const double _t53 = _hc0[3]*_t3;
  const double _t54 = -_hc0[6]*_t16 + _hc0[6]*_t7 + _hc2[6]*_t13 - _hc2[6]*_t15 - _t11*_t49 + _t20*_t49 + (0.292e3 / 0.675e3)*_t46 + _t47*_t48 + _t50*_t51 - _t50*_t53 + (0.146e3 / 0.225e3)*_t52;
  const double _t55 = (0.146e3 / 0.75e2)*_hc0[1];
  const double _t56 = (0.146e3 / 0.75e2)*_hc0[0];
  const double _t57 = (0.73e2 / 0.75e2)*_hc0[0]*_hc2[3]*_t3 + (0.146e3 / 0.75e2)*_hc0[1]*_hc2[1]*_t3 + (0.73e2 / 0.75e2)*_hc0[3]*_hc2[0]*_t3 - _hc0[3]*_t25 - _hc2[0]*_hc2[1]*_t55 - 0.73e2 / 0.75e2*_hc2[3]*_t9 - 0.292e3 / 0.225e3*_t18 - _t21*_t56;
  const double _t58 = _t12*_t24;
  const double _t59 = 0.2e1*_t28;
  const double _t60 = pow(_t5, -0.29e2 / 0.10e2);
  const double _t61 = (0.5548e4 / 0.2025e4)*_hc0[0];
  const double _t62 = (0.1387e4 / 0.675e3)*_hc2[1];
  const double _t63 = (0.1387e4 / 0.675e3)*_hc0[0]*_hc2[1]*_t3 + (0.1387e4 / 0.675e3)*_hc0[1]*_hc2[0]*_t3 - _hc0[1]*_t61 - _t62*_t9;
  const double _t64 = _t60*_t63;
  const double _t65 = _t27*_t64;
  const double _t66 = (0.584e3 / 0.2025e4)*_hc0[4];
  const double _t67 = (0.292e3 / 0.675e3)*_hc0[0];
  const double _t68 = _hc2[4]*_t67;
  const double _t69 = (0.146e3 / 0.675e3)*_hc2[4];
  const double _t70 = (0.292e3 / 0.675e3)*_hc0[1];
  const double _t71 = _hc2[1]*_hc2[2];
  const double _t72 = _hc0[2]*_t10;
  const double _t73 = _hc0[4]*_t19;
  const double _t74 = (0.146e3 / 0.675e3)*_t21;
  const double _t75 = (0.73e2 / 0.675e3)*_t40;
  const double _t76 = _hc0[1]*_t66 + _hc0[2]*_t74 + _hc0[3]*_t29 + _hc0[3]*_t31 - _hc0[7]*_t16 + _hc0[7]*_t7 + _hc2[0]*_t73 + _hc2[1]*_t68 + _hc2[3]*_t30 + _hc2[3]*_t72 - _hc2[3]*_t75 + _hc2[7]*_t13 - _hc2[7]*_t15 - _t11*_t69 + _t20*_t69 - _t3*_t73 - _t33*_t53 + _t70*_t71;
  const double _t77 = (0.292e3 / 0.2025e4)*_hc0[5];
  const double _t78 = (0.292e3 / 0.675e3)*_hc0[2];
  const double _t79 = _hc0[4]*_t37;
  const double _t80 = _hc0[5]*_t8;
  const double _t81 = (0.146e3 / 0.675e3)*_t39;
  const double _t82 = _hc0[1]*_t77 + _hc0[1]*_t81 + _hc0[2]*_t66 - _hc0[8]*_t16 + _hc0[8]*_t7 + _hc2[0]*_t79 + _hc2[0]*_t80 + _hc2[2]*_t68 - _t3*_t79 - _t3*_t80 + _t38*_t69 - _t40*_t69 + _t71*_t78;
  const double _t83 = (0.292e3 / 0.225e3)*_hc0[2];
  const double _t84 = (0.73e2 / 0.75e2)*_hc0[0]*_hc2[4]*_t3 + (0.73e2 / 0.75e2)*_hc0[1]*_hc2[2]*_t3 - _hc0[1]*_t83 + (0.73e2 / 0.75e2)*_hc0[2]*_hc2[1]*_t3 + (0.73e2 / 0.75e2)*_hc0[4]*_hc2[0]*_t3 - _hc0[4]*_t25 - 0.73e2 / 0.75e2*_hc2[4]*_t9 - _t20*_t43 - _t26*_t38 - _t56*_t71;
  const double _t85 = _t24*_t44;
  const double _t86 = _t17*_t44;
  const double _t87 = (0.73e2 / 0.225e3)*_hc0[5];
  const double _t88 = _hc2[0]*_hc2[2];
  const double _t89 = (0.146e3 / 0.225e3)*_t39;
  const double _t90 = _hc2[2]*_t3;
  const double _t91 = _hc0[2]*_t89 + _hc0[5]*_t78 - _hc0[9]*_t16 + _hc0[9]*_t7 + _t87*_t88 - _t87*_t90;
  const double _t92 = (0.146e3 / 0.75e2)*_hc0[2];
  const double _t93 = (0.146e3 / 0.75e2)*_hc0[2]*_hc2[2]*_t3 + (0.73e2 / 0.75e2)*_hc0[5]*_hc2[0]*_t3 - _hc0[5]*_t25 - 0.292e3 / 0.225e3*_t35 - 0.100e3 / 0.81e2*_t36 - _t39*_t56 - _t88*_t92;
  const double _t94 = 0.2e1*_t85;
  const double _t95 = (0.1387e4 / 0.675e3)*_hc2[2];
  const double _t96 = (0.1387e4 / 0.675e3)*_hc0[0]*_hc2[2]*_t3 + (0.1387e4 / 0.675e3)*_hc0[2]*_hc2[0]*_t3 - _hc0[2]*_t61 - 0.19e2*_t14 - 0.950e3 / 0.729e3*_t42 - _t9*_t95;
  const double _t97 = _t60*_t86;
#endif
#if _KMAX >= 4
  const double _t98 = (0.73e2 / 0.75e2)*_hc0[0]*_hc2[6]*_t3 - 0.146e3 / 0.25e2*_hc0[0]*_t48 + (0.73e2 / 0.25e2)*_hc0[1]*_hc2[3]*_t3 + (0.73e2 / 0.25e2)*_hc0[3]*_hc2[1]*_t3 + (0.73e2 / 0.75e2)*_hc0[6]*_hc2[0]*_t3 - _hc0[6]*_t25 - 0.73e2 / 0.25e2*_hc2[1]*_t51 - 0.73e2 / 0.25e2*_hc2[3]*_t20 - 0.73e2 / 0.75e2*_hc2[6]*_t9 - 0.292e3 / 0.75e2*_t46 - 0.146e3 / 0.25e2*_t52;
  const double _t99 = 0.3e1*_t28;
  const double _t100 = (0.584e3 / 0.675e3)*_hc2[1];
  const double _t101 = _hc2[6]*_t70;
  const double _t102 = (0.146e3 / 0.225e3)*_hc2[3];
  const double _t103 = (0.292e3 / 0.675e3)*_hc2[1];
  const double _t104 = _hc0[6]*_t3;
  const double _t105 = _t24*_t57;
  const double _t106 = 0.3e1*_t105;
  const double _t107 = _t12*_t27;
  const double _t108 = (0.2774e4 / 0.675e3)*_hc0[0];
  const double _t109 = (0.1387e4 / 0.675e3)*_hc0[0]*_hc2[3]*_t3 + (0.2774e4 / 0.675e3)*_hc0[1]*_hc2[1]*_t3 + (0.1387e4 / 0.675e3)*_hc0[3]*_hc2[0]*_t3 - _hc0[3]*_t61 - 0.2774e4 / 0.675e3*_hc2[1]*_t20 - 0.1387e4 / 0.675e3*_hc2[3]*_t9 - _t108*_t21 - 0.5548e4 / 0.2025e4*_t18;
  const double _t110 = _t109*_t60;
  const double _t111 = 0.3e1*_t65;
  const double _t112 = 0.2e1*_t57;
  const double _t113 = pow(_t5, -0.39e2 / 0.10e2);
  const double _t114 = (0.8468e4 / 0.2025e4)*_hc0[0];
  const double _t115 = _t113*((0.2117e4 / 0.675e3)*_hc0[0]*_hc2[1]*_t3 + (0.2117e4 / 0.675e3)*_hc0[1]*_hc2[0]*_t3 - _hc0[1]*_t114 - 0.2117e4 / 0.675e3*_hc2[1]*_t9);
  const double _t116 = _t115*_t63;
  const double _t117 = _t17*_t27;
  const double _t118 = _t17*_t64;
  const double _t119 = (0.292e3 / 0.675e3)*_hc0[4];
  const double _t120 = (0.73e2 / 0.225e3)*_hc2[7];
  const double _t121 = _hc2[1]*_hc2[4];
  const double _t122 = _hc0[1]*_hc2[2];
  const double _t123 = (0.73e2 / 0.225e3)*_hc2[4];
  const double _t124 = (0.146e3 / 0.225e3)*_t71;
  const double _t125 = _hc0[4]*_t49;
  const double _t126 = _hc0[7]*_t50;
  const double _t127 = _t24*_t34;
  const double _t128 = 0.2e1*_t84;
  const double _t129 = _t34*_t44;
  const double _t130 = 0.2e1*_t64;
  const double _t131 = (0.146e3 / 0.675e3)*_hc2[7];
  const double _t132 = _hc2[2]*_hc2[3];
  const double _t133 = _hc2[4]*_t119;
  const double _t134 = _hc0[5]*_hc2[3];
  const double _t135 = _hc0[7]*_t37;
  const double _t136 = _hc0[8]*_t19;
  const double _t137 = (0.584e3 / 0.225e3)*_hc0[4];
  const double _t138 = (0.292e3 / 0.75e2)*_hc0[0];
  const double _t139 = (0.73e2 / 0.75e2)*_hc2[0];
  const double _t140 = (0.146e3 / 0.75e2)*_hc0[4];
  const double _t141 = _hc2[2]*_hc2[4];
  const double _t142 = _hc2[4]*_t87;
  const double _t143 = (0.73e2 / 0.225e3)*_hc0[8];
  const double _t144 = _hc0[9]*_t8;
  const double _t145 = _t24*_t41;
  const double _t146 = _t41*_t44;
  const double _t147 = (0.292e3 / 0.225e3)*_hc0[5];
  const double _t148 = (0.292e3 / 0.75e2)*_hc0[2];
  const double _t149 = _t60*_t96;
  const double _t150 = _t149*_t17;
  const double _t151 = _t86*_t96;
  const double _t152 = (0.292e3 / 0.675e3)*_hc0[9];
#endif

  const double f = pow(_t5, 0.1e1 / 0.10e2);
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t12*_t6;
  out[1] = df_dt;
  const double df_dx2 = _t17*_t6;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t12*_t28 + _t23*_t6;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = _t17*_t28 + _t34*_t6;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = _t41*_t6 + _t44*_t45;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _t12*_t65 + _t23*_t59 + _t54*_t6 + _t57*_t58;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = _t17*_t65 + _t34*_t59 + _t45*_t57 + _t6*_t76;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = _t28*_t41 + _t34*_t85 + _t45*_t84 + _t6*_t82 + _t64*_t86;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = _t41*_t94 + _t45*_t93 + _t6*_t91 + _t96*_t97;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _t106*_t23 + _t107*_t110 + _t107*_t116 + _t111*_t23 + _t112*_t12*_t64 + _t54*_t99 + _t58*_t98 + _t6*(_hc0[0]*_hc2[6]*_t100 + (0.1168e4 / 0.2025e4)*_hc0[1]*_hc0[6] + (0.584e3 / 0.225e3)*_hc0[1]*_t48 - _hc0[10]*_t16 + _hc0[10]*_t7 + (0.292e3 / 0.675e3)*((_hc0[3]) * (_hc0[3])) + (0.292e3 / 0.225e3)*_hc0[3]*_t21 + _hc0[6]*_hc2[0]*_t103 + _hc2[0]*_t101 + _hc2[10]*_t13 - _hc2[10]*_t15 + ((_hc2[3]) * (_hc2[3]))*_t47 - _t101*_t3 + _t102*_t51 - _t102*_t53 - _t103*_t104);
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = _t106*_t34 + _t110*_t117 + _t111*_t34 + _t112*_t118 + _t116*_t117 + _t45*_t98 + _t6*((0.292e3 / 0.225e3)*_hc0[1]*_t121 - _hc0[11]*_t16 + _hc0[11]*_t7 + (0.146e3 / 0.225e3)*_hc0[2]*_t48 + _hc0[3]*_t119 + _hc0[3]*_t124 + (0.146e3 / 0.225e3)*_hc0[4]*_t21 + _hc0[6]*_t29 + _hc0[6]*_t31 + _hc0[7]*_t70 + _hc2[0]*_t125 + _hc2[0]*_t126 + _hc2[1]*_hc2[7]*_t47 + _hc2[11]*_t13 - _hc2[11]*_t15 + _hc2[3]*_hc2[4]*_t47 + _hc2[6]*_t30 + _hc2[6]*_t72 - _hc2[6]*_t75 + _t102*_t122 - _t104*_t33 - _t11*_t120 + _t120*_t20 + _t123*_t51 - _t123*_t53 - _t125*_t3 - _t126*_t3) + _t76*_t99;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = _t105*_t41 + _t109*_t97 + _t116*_t86 + _t118*_t128 + _t127*_t128 + _t129*_t130 + _t41*_t65 + _t45*((0.73e2 / 0.75e2)*_hc0[0]*_hc2[7]*_t3 + (0.146e3 / 0.75e2)*_hc0[1]*_hc2[4]*_t3 - _hc0[1]*_t137 - 0.292e3 / 0.75e2*_hc0[1]*_t71 - _hc0[2]*_hc2[3]*_t139 + (0.73e2 / 0.75e2)*_hc0[2]*_hc2[3]*_t3 - _hc0[3]*_hc2[2]*_t139 + (0.73e2 / 0.75e2)*_hc0[3]*_hc2[2]*_t3 - _hc0[3]*_t83 + (0.146e3 / 0.75e2)*_hc0[4]*_hc2[1]*_t3 + (0.73e2 / 0.75e2)*_hc0[7]*_hc2[0]*_t3 - _hc0[7]*_t25 - _hc2[0]*_hc2[1]*_t140 - _hc2[0]*_hc2[4]*_t55 - 0.73e2 / 0.75e2*_hc2[7]*_t9 - _t121*_t138 - _t132*_t56 - _t21*_t92) + _t59*_t82 + _t6*((0.584e3 / 0.2025e4)*_hc0[1]*_hc0[8] - _hc0[12]*_t16 + _hc0[12]*_t7 + (0.584e3 / 0.2025e4)*_hc0[2]*_hc0[7] + _hc0[2]*_hc2[4]*_t100 + _hc0[3]*_t77 + _hc0[3]*_t81 + (0.584e3 / 0.2025e4)*((_hc0[4]) * (_hc0[4])) + (0.584e3 / 0.675e3)*_hc0[4]*_t71 + _hc0[5]*_t74 + _hc2[0]*_t133 + _hc2[0]*_t135 + _hc2[0]*_t136 + _hc2[2]*_hc2[7]*_t67 + ((_hc2[4]) * (_hc2[4]))*_t67 + (0.584e3 / 0.675e3)*_hc2[4]*_t122 + _t10*_t134 + _t131*_t38 - _t131*_t40 + _t132*_t78 - _t133*_t3 - 0.73e2 / 0.675e3*_t134*_t3 - _t135*_t3 - _t136*_t3) + _t76*_t85;
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = _t115*_t151 + _t118*_t93 + _t127*_t93 + _t128*_t145 + _t129*_t149 + _t130*_t146 + _t150*_t84 + _t28*_t91 + _t45*(-_hc0[1]*_t147 + (0.146e3 / 0.75e2)*_hc0[2]*_hc2[4]*_t3 - _hc0[2]*_t137 + (0.146e3 / 0.75e2)*_hc0[4]*_hc2[2]*_t3 - _hc0[5]*_hc2[0]*_t26 + (0.73e2 / 0.75e2)*_hc0[5]*_hc2[1]*_t3 + (0.73e2 / 0.75e2)*_hc0[8]*_hc2[0]*_t3 - _hc0[8]*_t25 - _hc2[0]*_hc2[4]*_t92 - _t138*_t141 - _t140*_t88 - _t148*_t71 - _t39*_t55) + _t6*((0.292e3 / 0.2025e4)*_hc0[1]*_hc0[9] - _hc0[13]*_t16 + _hc0[13]*_t7 + _hc0[4]*_t89 + _hc0[5]*_t119 + _hc0[5]*_t124 + _hc0[8]*_t78 + _hc2[0]*_t142 + _hc2[0]*_t144 + _t141*_t83 - _t142*_t3 + _t143*_t88 - _t143*_t90 - _t144*_t3) + _t82*_t94 + _t97*((0.1387e4 / 0.675e3)*_hc0[0]*_hc2[4]*_t3 - 0.5548e4 / 0.2025e4*_hc0[1]*_hc0[2] + (0.1387e4 / 0.675e3)*_hc0[1]*_hc2[2]*_t3 + (0.1387e4 / 0.675e3)*_hc0[2]*_hc2[1]*_t3 + (0.1387e4 / 0.675e3)*_hc0[4]*_hc2[0]*_t3 - _hc0[4]*_t61 - 0.1387e4 / 0.675e3*_hc2[4]*_t9 - _t108*_t71 - _t20*_t95 - _t38*_t62);
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = _t113*_t151*((0.2117e4 / 0.675e3)*_hc0[0]*_hc2[2]*_t3 + (0.2117e4 / 0.675e3)*_hc0[2]*_hc2[0]*_t3 - _hc0[2]*_t114 - 0.2117e4 / 0.675e3*_hc2[2]*_t9 - 0.29e2*_t14 - 0.1450e4 / 0.729e3*_t42) + 0.3e1*_t145*_t93 + 0.3e1*_t146*_t149 + 0.2e1*_t150*_t93 + _t45*(-0.146e3 / 0.25e2*_hc0[2]*_t39 + (0.73e2 / 0.25e2)*_hc0[5]*_hc2[2]*_t3 - _hc0[5]*_t148 - 0.73e2 / 0.25e2*_hc0[5]*_t88 + (0.73e2 / 0.75e2)*_hc0[9]*_hc2[0]*_t3 - _hc0[9]*_t25) + _t6*(-_hc0[14]*_t16 + _hc0[14]*_t7 + (0.1168e4 / 0.2025e4)*_hc0[2]*_hc0[9] + (0.292e3 / 0.675e3)*((_hc0[5]) * (_hc0[5])) + _t147*_t39 + _t152*_t88 - _t152*_t90) + 0.3e1*_t85*_t91 + _t97*((0.2774e4 / 0.675e3)*_hc0[2]*_hc2[2]*_t3 + (0.1387e4 / 0.675e3)*_hc0[5]*_hc2[0]*_t3 - _hc0[5]*_t61 - 0.2774e4 / 0.675e3*_hc2[2]*_t38 - _t108*_t39 - 0.5548e4 / 0.2025e4*_t35 - 0.1900e4 / 0.729e3*_t36);
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_one_minus_w_pf_k, _KMAX)(const xc_func_type *p, double x2, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_tratio_pf_k, _KMAX)(p, x2, t, _hc0);
  const double _t1 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t2 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t3 = xc_powi((_hc0[0]), 5);
  const double _t4 = _hc0[0] - _t1 - _t2 - _t3 + 0.1e1;
  const double _t5 = _t1 + 0.1e1;
  const double _t6 = (0.1e1 / (_t5 * _t5));
  const double _t7 = 0.1e1 - _hc0[0];
  const double _t8 = _t6*_t7;
#if _KMAX >= 1
  const double _t9 = _t4*_t6;
  const double _t10 = ((_hc0[0]) * (_hc0[0]));
  const double _t11 = 0.3e1*_t10;
  const double _t12 = 0.4e1*_t1;
  const double _t13 = 0.5e1*_t2;
  const double _t14 = -_hc0[1]*_t11 - _hc0[1]*_t12 - _hc0[1]*_t13 + _hc0[1];
  const double _t15 = _hc0[1]*_t10;
  const double _t16 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t17 = _t16*_t4;
  const double _t18 = _t17*_t7;
  const double _t19 = 0.6e1*_t18;
  const double _t20 = -_hc0[2]*_t11 - _hc0[2]*_t12 - _hc0[2]*_t13 + _hc0[2];
  const double _t21 = _hc0[2]*_t10;
#endif
#if _KMAX >= 2
  const double _t22 = _hc0[1]*_t6;
  const double _t23 = 0.2e1*_t22;
  const double _t24 = ((_hc0[1]) * (_hc0[1]));
  const double _t25 = 0.12e2*_hc0[0];
  const double _t26 = _t18*_t25;
  const double _t27 = 0.6e1*_hc0[3];
  const double _t28 = _t10*_t27;
  const double _t29 = _t14*_t16;
  const double _t30 = _t29*_t7;
  const double _t31 = 0.12e2*_t10;
  const double _t32 = _hc0[1]*_t31;
  const double _t33 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t34 = 0.6e1*_hc0[0];
  const double _t35 = 0.20e2*_t1;
  const double _t36 = -_hc0[3]*_t11 - _hc0[3]*_t12 - _hc0[3]*_t13 + _hc0[3] - _t24*_t31 - _t24*_t34 - _t24*_t35;
  const double _t37 = _t20*_t6;
  const double _t38 = _hc0[2]*_t6;
  const double _t39 = _hc0[1]*_hc0[2];
  const double _t40 = _hc0[4]*_t10;
  const double _t41 = _t16*_t20;
  const double _t42 = _t41*_t7;
  const double _t43 = 0.6e1*_t15;
  const double _t44 = 0.6e1*_t21;
  const double _t45 = -_hc0[4]*_t11 - _hc0[4]*_t12 - _hc0[4]*_t13 + _hc0[4] - _t31*_t39 - _t34*_t39 - _t35*_t39;
  const double _t46 = 0.2e1*_t37;
  const double _t47 = ((_hc0[2]) * (_hc0[2]));
  const double _t48 = _t31*_t47;
  const double _t49 = -_t34*_t47 - _t35*_t47 - _t48;
  const double _t50 = _hc0[2]*_t31;
  const double _t51 = _t33*_t4;
  const double _t52 = _t2*_t51;
  const double _t53 = _t47*_t7;
#endif
#if _KMAX >= 3
  const double _t54 = _t14*_t6;
  const double _t55 = 0.3e1*_hc0[3];
  const double _t56 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t57 = _t2*_t56;
  const double _t58 = 0.162e3*_t51;
  const double _t59 = 0.12e2*_t7;
  const double _t60 = 0.36e2*_hc0[3];
  const double _t61 = _hc0[0]*_t60;
  const double _t62 = _hc0[1]*_t61;
  const double _t63 = _t10*_t19;
  const double _t64 = 0.36e2*_hc0[0];
  const double _t65 = _hc0[3]*_t10;
  const double _t66 = 0.18e2*_t30;
  const double _t67 = _t56*_t7;
  const double _t68 = xc_powi((_hc0[0]), 6);
  const double _t69 = xc_powi(_t5, -5);
  const double _t70 = _t68*_t69;
  const double _t71 = _t4*_t70;
  const double _t72 = 0.648e3*_t71;
  const double _t73 = 0.3e1*_t22;
  const double _t74 = _t16*_t36;
  const double _t75 = 0.18e2*_t7;
  const double _t76 = _t15*_t75;
  const double _t77 = 0.18e2*_hc0[0];
  const double _t78 = _hc0[1]*_hc0[3];
  const double _t79 = 0.24e2*_hc0[0];
  const double _t80 = 0.60e2*_t1;
  const double _t81 = 0.60e2*_t10;
  const double _t82 = -_hc0[6]*_t11 - _hc0[6]*_t12 - _hc0[6]*_t13 + _hc0[6] - _t15*_t60 - _t56*_t79 - _t56*_t81 - 0.6e1*_t56 - _t77*_t78 - _t78*_t80;
  const double _t83 = _hc0[2]*_t24;
  const double _t84 = _t2*_t58;
  const double _t85 = _hc0[1]*_hc0[4];
  const double _t86 = _t18*_t79;
  const double _t87 = _hc0[2]*_hc0[3];
  const double _t88 = _hc0[7]*_t10;
  const double _t89 = _t39*_t79;
  const double _t90 = _t24*_t7;
  const double _t91 = _t25*_t90;
  const double _t92 = _hc0[4]*_t31;
  const double _t93 = _t7*_t83;
  const double _t94 = _t16*_t45;
  const double _t95 = _t7*_t94;
  const double _t96 = _t10*_t7*_t74;
  const double _t97 = 0.24e2*_t10;
  const double _t98 = 0.40e2*_t1;
  const double _t99 = -_hc0[7]*_t11 - _hc0[7]*_t12 - _hc0[7]*_t13 + _hc0[7] - _t25*_t85 - _t31*_t87 - _t34*_t87 - _t35*_t87 - _t79*_t83 - _t81*_t83 - 0.6e1*_t83 - _t85*_t97 - _t85*_t98;
  const double _t100 = _t49*_t6;
  const double _t101 = _hc0[1]*_t47;
  const double _t102 = _hc0[2]*_hc0[4];
  const double _t103 = _t101*_t7;
  const double _t104 = _t16*_t49;
  const double _t105 = _t43*_t7;
  const double _t106 = 0.2e1*_t38;
  const double _t107 = 0.6e1*_t47;
  const double _t108 = 0.24e2*_hc0[2];
  const double _t109 = -_hc0[1]*_t107 - _t101*_t79 - _t101*_t81 - _t102*_t25 - _t102*_t98 - _t108*_t40;
  const double _t110 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t111 = 0.3e1*_t38;
  const double _t112 = _t110*_t2;
  const double _t113 = -_t110*_t79 - _t110*_t81 - 0.6e1*_t110;
  const double _t114 = _t110*_t7;
  const double _t115 = _t10*_t104;
#endif
#if _KMAX >= 4
  const double _t116 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t117 = ((_hc0[3]) * (_hc0[3]));
  const double _t118 = 0.1296e4*_t1*_t51;
  const double _t119 = _hc0[3]*_t24;
  const double _t120 = _t33*_t57;
  const double _t121 = 0.648e3*_t14;
  const double _t122 = _hc0[1]*_hc0[6];
  const double _t123 = 0.48e2*_t17;
  const double _t124 = _hc0[0]*_t7;
  const double _t125 = _t18*_t64;
  const double _t126 = 0.48e2*_t7;
  const double _t127 = 0.144e3*_hc0[0];
  const double _t128 = 0.7776e4*_t3*_t69;
  const double _t129 = xc_powi((_hc0[0]), 8);
  const double _t130 = xc_powi(_t5, -6);
  const double _t131 = 0.2592e4*_t70;
  const double _t132 = _t36*_t6;
  const double _t133 = 0.72e2*_t24;
  const double _t134 = _t16*_t7;
  const double _t135 = _t134*_t82;
  const double _t136 = 0.120e3*_hc0[0];
  const double _t137 = 0.36e2*_t10;
  const double _t138 = _hc0[3]*_t39;
  const double _t139 = 0.486e3*_t52;
  const double _t140 = _hc0[2]*_t56;
  const double _t141 = _hc0[4]*_t24;
  const double _t142 = _hc0[1]*_hc0[7];
  const double _t143 = _hc0[2]*_hc0[6];
  const double _t144 = _hc0[0]*_hc0[4];
  const double _t145 = _t18*_t60;
  const double _t146 = _t2*_t33;
  const double _t147 = _t14*_t146;
  const double _t148 = 0.36e2*_t18;
  const double _t149 = 0.72e2*_hc0[0];
  const double _t150 = 0.1944e4*_t71;
  const double _t151 = _t4*_t7;
  const double _t152 = 0.648e3*_t20;
  const double _t153 = _t14*_t70;
  const double _t154 = _t45*_t6;
  const double _t155 = 0.3e1*_hc0[4];
  const double _t156 = _t64*_t94;
  const double _t157 = _t39*_t7;
  const double _t158 = _t157*_t64;
  const double _t159 = 0.18e2*_hc0[4];
  const double _t160 = _hc0[3]*_hc0[4];
  const double _t161 = 0.180e3*_t40;
  const double _t162 = ((_hc0[4]) * (_hc0[4]));
  const double _t163 = _hc0[3]*_t47;
  const double _t164 = _hc0[2]*_hc0[7];
  const double _t165 = _hc0[4]*_t157;
  const double _t166 = _t24*_t47;
  const double _t167 = _hc0[0]*_t126;
  const double _t168 = _t131*_t4;
  const double _t169 = _t115*_t7;
  const double _t170 = _t20*_t70;
  const double _t171 = _hc0[1]*_t110;
  const double _t172 = _hc0[4]*_t47;
  const double _t173 = _t112*_t33;
  const double _t174 = 0.72e2*_t47;
  const double _t175 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t176 = _t110*_t41;
  const double _t177 = _t151*_t175;
  const double _t178 = _t114*_t20;
#endif

  const double f = _t4*_t8;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_hc0[1]*_t9 + _t14*_t6*_t7 - _t15*_t19;
  out[1] = df_dt;
  const double df_dx2 = -_hc0[2]*_t9 - _t19*_t21 + _t20*_t6*_t7;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_hc0[3]*_t9 + 0.12e2*_t10*_t16*_t24*_t4 - _t14*_t23 - _t18*_t28 + 0.54e2*_t2*_t24*_t33*_t4*_t7 - _t24*_t26 - _t30*_t32 + _t36*_t6*_t7;
  out[3] = d2f_dt2;
  const double d2f_dx2_dt = 0.12e2*_hc0[1]*_hc0[2]*_t10*_t16*_t4 + 0.54e2*_hc0[1]*_hc0[2]*_t2*_t33*_t4*_t7 - _hc0[1]*_t37 - _hc0[4]*_t9 - _t14*_t38 - _t19*_t40 - _t26*_t39 - _t30*_t44 - _t42*_t43 + _t45*_t6*_t7;
  out[4] = d2f_dx2_dt;
  const double d2f_dx22 = -_hc0[2]*_t46 + _t17*_t48 - _t26*_t47 - _t42*_t50 + _t49*_t8 + 0.54e2*_t52*_t53;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0.36e2*_hc0[0]*_t16*_t4*_t56 + 0.36e2*_hc0[1]*_hc0[3]*_t10*_t16*_t4 + 0.162e3*_hc0[1]*_hc0[3]*_t2*_t33*_t4*_t7 - _hc0[6]*_t63 - _hc0[6]*_t9 + 0.324e3*_t1*_t33*_t4*_t56*_t7 + 0.36e2*_t10*_t14*_t16*_t24 + 0.162e3*_t14*_t2*_t24*_t33*_t7 - _t17*_t56*_t59 - _t18*_t62 - _t24*_t30*_t64 - _t36*_t73 - _t54*_t55 - _t57*_t58 + _t6*_t7*_t82 - _t65*_t66 - _t67*_t72 - _t74*_t76;
  out[6] = d3f_dt3;
  const double d3f_dx2_dt2 = 0.36e2*_hc0[0]*_hc0[2]*_t16*_t24*_t4 + 0.24e2*_hc0[1]*_hc0[2]*_t10*_t14*_t16 + 0.108e3*_hc0[1]*_hc0[2]*_t14*_t2*_t33*_t7 + 0.24e2*_hc0[1]*_hc0[4]*_t10*_t16*_t4 + 0.108e3*_hc0[1]*_hc0[4]*_t2*_t33*_t4*_t7 + 0.12e2*_hc0[2]*_hc0[3]*_t10*_t16*_t4 + 0.54e2*_hc0[2]*_hc0[3]*_t2*_t33*_t4*_t7 + 0.324e3*_hc0[2]*_t1*_t24*_t33*_t4*_t7 - 0.6e1*_hc0[2]*_t96 - _hc0[3]*_t37 - 0.2e1*_hc0[4]*_t54 - _hc0[7]*_t9 + 0.12e2*_t10*_t16*_t20*_t24 - _t17*_t59*_t83 - _t19*_t88 + 0.54e2*_t2*_t20*_t24*_t33*_t7 - _t23*_t45 - _t26*_t87 - _t28*_t42 - _t30*_t89 - _t30*_t92 - _t32*_t95 - _t36*_t38 - _t41*_t91 + _t6*_t7*_t99 - _t72*_t93 - _t83*_t84 - _t85*_t86;
  out[7] = d3f_dx2_dt2;
  const double d3f_dx22_dt = 0.36e2*_hc0[0]*_hc0[1]*_t16*_t4*_t47 + 0.24e2*_hc0[1]*_hc0[2]*_t10*_t16*_t20 + 0.108e3*_hc0[1]*_hc0[2]*_t2*_t20*_t33*_t7 + 0.324e3*_hc0[1]*_t1*_t33*_t4*_t47*_t7 - _hc0[1]*_t100 + 0.24e2*_hc0[2]*_hc0[4]*_t10*_t16*_t4 + 0.108e3*_hc0[2]*_hc0[4]*_t2*_t33*_t4*_t7 - _hc0[4]*_t46 + 0.12e2*_t10*_t14*_t16*_t47 - _t101*_t17*_t59 - _t101*_t84 - _t102*_t86 - _t103*_t72 - _t104*_t105 - _t106*_t45 + _t109*_t6*_t7 + 0.54e2*_t14*_t2*_t33*_t47*_t7 - _t25*_t30*_t47 - _t42*_t89 - _t42*_t92 - _t50*_t95;
  out[8] = d3f_dx22_dt;
  const double d3f_dx23 = 0.36e2*_hc0[0]*_t110*_t16*_t4 - _hc0[2]*_t115*_t75 + 0.324e3*_t1*_t110*_t33*_t4*_t7 + 0.36e2*_t10*_t16*_t20*_t47 - _t110*_t17*_t59 - _t111*_t49 - _t112*_t58 + _t113*_t6*_t7 - _t114*_t72 + 0.162e3*_t2*_t20*_t33*_t47*_t7 - _t42*_t47*_t64;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0.216e3*_hc0[0]*_hc0[3]*_t16*_t24*_t4 + 0.144e3*_hc0[0]*_t14*_t16*_t56 + 0.144e3*_hc0[1]*_hc0[3]*_t10*_t14*_t16 + 0.648e3*_hc0[1]*_hc0[3]*_t14*_t2*_t33*_t7 + 0.48e2*_hc0[1]*_hc0[6]*_t10*_t16*_t4 + 0.216e3*_hc0[1]*_hc0[6]*_t2*_t33*_t4*_t7 - _hc0[1]*_t135*_t97 - _hc0[10]*_t63 - _hc0[10]*_t9 + 0.1944e4*_hc0[3]*_t1*_t24*_t33*_t4*_t7 - _hc0[6]*_t30*_t97 - 0.4e1*_hc0[6]*_t54 + 0.1296e4*_t1*_t14*_t33*_t56*_t7 + 0.1080e4*_t10*_t116*_t33*_t4*_t7 + 0.36e2*_t10*_t117*_t16*_t4 + 0.72e2*_t10*_t16*_t24*_t36 - _t116*_t118 - _t116*_t128*_t4*_t7 + 0.9720e4*_t116*_t129*_t130*_t4*_t7 + 0.48e2*_t116*_t16*_t4 + 0.2592e4*_t116*_t4*_t68*_t69 - _t117*_t125 + 0.162e3*_t117*_t2*_t33*_t4*_t7 - 0.72e2*_t119*_t18 - 0.972e3*_t119*_t52 - 0.3888e4*_t119*_t7*_t71 - _t120*_t121 - _t122*_t123*_t124 - _t124*_t133*_t74 - _t126*_t29*_t56 - _t127*_t30*_t78 - _t131*_t14*_t67 - _t132*_t27 + 0.324e3*_t2*_t24*_t33*_t36*_t7 - 0.4e1*_t22*_t82 + _t6*_t7*(-_hc0[10]*_t11 - _hc0[10]*_t12 - _hc0[10]*_t13 + _hc0[10] - 0.48e2*_hc0[6]*_t15 - 0.80e2*_t1*_t122 - 0.360e3*_t10*_t119 - _t116*_t136 - 0.24e2*_t116 - _t117*_t137 - _t117*_t77 - _t117*_t80 - _t119*_t127 - _t122*_t79 - _t24*_t60) - _t60*_t96;
  out[10] = d4f_dt4;
  const double d4f_dx2_dt3 = 0.108e3*_hc0[0]*_hc0[1]*_hc0[2]*_hc0[3]*_t16*_t4 + 0.108e3*_hc0[0]*_hc0[2]*_t14*_t16*_t24 + 0.108e3*_hc0[0]*_hc0[4]*_t16*_t24*_t4 + 0.36e2*_hc0[0]*_t16*_t20*_t56 + 0.972e3*_hc0[1]*_hc0[2]*_hc0[3]*_t1*_t33*_t4*_t7 + 0.36e2*_hc0[1]*_hc0[2]*_t10*_t16*_t36 + 0.162e3*_hc0[1]*_hc0[2]*_t2*_t33*_t36*_t7 + 0.36e2*_hc0[1]*_hc0[3]*_t10*_t16*_t20 + 0.162e3*_hc0[1]*_hc0[3]*_t2*_t20*_t33*_t7 + 0.72e2*_hc0[1]*_hc0[4]*_t10*_t14*_t16 + 0.324e3*_hc0[1]*_hc0[4]*_t14*_t2*_t33*_t7 + 0.36e2*_hc0[1]*_hc0[7]*_t10*_t16*_t4 + 0.162e3*_hc0[1]*_hc0[7]*_t2*_t33*_t4*_t7 - _hc0[11]*_t63 - _hc0[11]*_t9 + 0.36e2*_hc0[2]*_hc0[3]*_t10*_t14*_t16 + 0.162e3*_hc0[2]*_hc0[3]*_t14*_t2*_t33*_t7 + 0.12e2*_hc0[2]*_hc0[6]*_t10*_t16*_t4 + 0.54e2*_hc0[2]*_hc0[6]*_t2*_t33*_t4*_t7 + 0.972e3*_hc0[2]*_t1*_t14*_t24*_t33*_t7 + 0.1080e4*_hc0[2]*_t10*_t33*_t4*_t56*_t7 + 0.9720e4*_hc0[2]*_t129*_t130*_t4*_t56*_t7 + 0.48e2*_hc0[2]*_t16*_t4*_t56 - _hc0[2]*_t30*_t61 + 0.2592e4*_hc0[2]*_t4*_t56*_t68*_t69 + 0.36e2*_hc0[3]*_hc0[4]*_t10*_t16*_t4 + 0.162e3*_hc0[3]*_hc0[4]*_t2*_t33*_t4*_t7 + 0.972e3*_hc0[4]*_t1*_t24*_t33*_t4*_t7 - _hc0[4]*_t150*_t90 - 0.6e1*_hc0[6]*_t10*_t42 - _hc0[6]*_t37 - 0.3e1*_hc0[7]*_t54 + 0.324e3*_t1*_t20*_t33*_t56*_t7 + 0.36e2*_t10*_t16*_t24*_t45 - _t118*_t140 - 0.162e3*_t120*_t20 - _t125*_t142 - _t128*_t140*_t151 - _t132*_t155 - _t135*_t44 - _t138*_t139 - _t138*_t150*_t7 - _t139*_t141 - _t141*_t148 - _t143*_t26 - _t144*_t145 - _t145*_t39 - 0.486e3*_t147*_t83 - _t149*_t30*_t85 - _t152*_t67*_t70 - 0.1944e4*_t153*_t93 - _t154*_t55 - _t156*_t90 - _t158*_t74 - _t159*_t96 - _t16*_t76*_t99 + 0.162e3*_t2*_t24*_t33*_t45*_t7 - 0.36e2*_t30*_t83 - _t38*_t82 - _t41*_t56*_t59 - _t42*_t62 + _t6*_t7*(-_hc0[11]*_t11 - _hc0[11]*_t12 - _hc0[11]*_t13 + _hc0[11] - 0.180e3*_t10*_t138 - _t108*_t56 - _t133*_t144 - _t136*_t140 - _t137*_t142 - _t138*_t149 - 0.18e2*_t138 - _t142*_t77 - _t142*_t80 - _t143*_t31 - _t143*_t34 - _t143*_t35 - _t159*_t24 - _t160*_t77 - _t160*_t80 - _t161*_t24 - _t40*_t60) - _t65*_t75*_t94 - _t66*_t88 - _t73*_t99;
  out[11] = d4f_dx2_dt3;
  const double d4f_dx22_dt2 = 0.144e3*_hc0[0]*_hc0[1]*_hc0[2]*_hc0[4]*_t16*_t4 + 0.72e2*_hc0[0]*_hc0[1]*_t14*_t16*_t47 + 0.72e2*_hc0[0]*_hc0[2]*_t16*_t20*_t24 + 0.36e2*_hc0[0]*_hc0[3]*_t16*_t4*_t47 + 0.1296e4*_hc0[1]*_hc0[2]*_hc0[4]*_t1*_t33*_t4*_t7 + 0.48e2*_hc0[1]*_hc0[2]*_t10*_t16*_t45 + 0.216e3*_hc0[1]*_hc0[2]*_t2*_t33*_t45*_t7 + 0.48e2*_hc0[1]*_hc0[4]*_t10*_t16*_t20 + 0.216e3*_hc0[1]*_hc0[4]*_t2*_t20*_t33*_t7 + 0.648e3*_hc0[1]*_t1*_t14*_t33*_t47*_t7 + 0.24e2*_hc0[2]*_hc0[3]*_t10*_t16*_t20 + 0.108e3*_hc0[2]*_hc0[3]*_t2*_t20*_t33*_t7 + 0.48e2*_hc0[2]*_hc0[4]*_t10*_t14*_t16 + 0.216e3*_hc0[2]*_hc0[4]*_t14*_t2*_t33*_t7 + 0.24e2*_hc0[2]*_hc0[7]*_t10*_t16*_t4 + 0.108e3*_hc0[2]*_hc0[7]*_t2*_t33*_t4*_t7 + 0.648e3*_hc0[2]*_t1*_t20*_t24*_t33*_t7 + 0.324e3*_hc0[3]*_t1*_t33*_t4*_t47*_t7 - _hc0[3]*_t100 - 0.4e1*_hc0[4]*_t154 - 0.648e3*_hc0[4]*_t39*_t52 - _hc0[4]*_t95*_t97 - _hc0[7]*_t31*_t42 - _hc0[7]*_t46 + 0.24e2*_t10*_t16*_t162*_t4 + 0.12e2*_t10*_t16*_t24*_t49 + 0.12e2*_t10*_t16*_t36*_t47 + 0.1080e4*_t10*_t24*_t33*_t4*_t47*_t7 - 0.324e3*_t101*_t147 - 0.24e2*_t101*_t30 - _t102*_t167*_t29 - 0.1296e4*_t103*_t153 - _t104*_t91 - _t106*_t99 - _t109*_t134*_t32 - _t109*_t23 - _t118*_t166 - _t123*_t165 - _t128*_t151*_t166 + 0.9720e4*_t129*_t130*_t24*_t4*_t47*_t7 - _t134*_t50*_t99 - 0.324e3*_t146*_t20*_t83 + 0.48e2*_t16*_t24*_t4*_t47 + 0.108e3*_t162*_t2*_t33*_t4*_t7 - _t162*_t86 - _t163*_t17*_t59 - _t163*_t7*_t72 - _t163*_t84 - _t164*_t86 - _t165*_t168 - _t167*_t39*_t94 - _t167*_t41*_t85 - _t169*_t27 - 0.1296e4*_t170*_t93 + 0.54e2*_t2*_t24*_t33*_t49*_t7 + 0.54e2*_t2*_t33*_t36*_t47*_t7 + 0.2592e4*_t24*_t4*_t47*_t68*_t69 - _t25*_t53*_t74 - _t42*_t79*_t87 - 0.24e2*_t42*_t83 + _t6*_t7*(-_hc0[3]*_t107 - _t108*_t85 - _t108*_t88 - _t136*_t166 - 0.96e2*_t144*_t39 - _t162*_t25 - _t162*_t97 - _t162*_t98 - _t163*_t79 - _t163*_t81 - _t164*_t25 - _t164*_t98 - 0.24e2*_t166 - 0.240e3*_t39*_t40);
  out[12] = d4f_dx22_dt2;
  const double d4f_dx23_dt = 0.108e3*_hc0[0]*_hc0[1]*_t16*_t20*_t47 + 0.108e3*_hc0[0]*_hc0[4]*_t16*_t4*_t47 + 0.36e2*_hc0[0]*_t110*_t14*_t16 + 0.36e2*_hc0[1]*_hc0[2]*_t10*_t16*_t49 + 0.162e3*_hc0[1]*_hc0[2]*_t2*_t33*_t49*_t7 + 0.972e3*_hc0[1]*_t1*_t20*_t33*_t47*_t7 + 0.1080e4*_hc0[1]*_t10*_t110*_t33*_t4*_t7 + 0.9720e4*_hc0[1]*_t110*_t129*_t130*_t4*_t7 + 0.48e2*_hc0[1]*_t110*_t16*_t4 + 0.2592e4*_hc0[1]*_t110*_t4*_t68*_t69 + 0.72e2*_hc0[2]*_hc0[4]*_t10*_t16*_t20 + 0.324e3*_hc0[2]*_hc0[4]*_t2*_t20*_t33*_t7 + 0.972e3*_hc0[4]*_t1*_t33*_t4*_t47*_t7 - _hc0[4]*_t150*_t53 + 0.324e3*_t1*_t110*_t14*_t33*_t7 + 0.36e2*_t10*_t16*_t45*_t47 - _t100*_t155 - 0.486e3*_t101*_t146*_t20 - 0.36e2*_t101*_t42 - _t102*_t149*_t42 - 0.1944e4*_t103*_t170 - _t104*_t158 - _t105*_t113*_t16 - _t109*_t111 - _t109*_t16*_t21*_t75 - _t110*_t29*_t59 - _t113*_t22 - _t114*_t121*_t70 - _t118*_t171 - _t128*_t151*_t171 - _t139*_t172 - 0.162e3*_t14*_t173 - _t148*_t172 - _t156*_t53 - _t159*_t169 + 0.162e3*_t2*_t33*_t45*_t47*_t7 + _t6*_t7*(-_t136*_t171 - _t144*_t174 - _t159*_t47 - _t161*_t47 - 0.24e2*_t171);
  out[13] = d4f_dx23_dt;
  const double d4f_dx24 = 0.1296e4*_t1*_t178*_t33 - _t10*_t108*_t113*_t134 + 0.1080e4*_t10*_t175*_t51*_t7 - _t104*_t124*_t174 - 0.4e1*_t113*_t38 + _t115*_t174 - _t118*_t175 + _t123*_t175 - _t126*_t176 + _t127*_t176 - _t128*_t177 + 0.9720e4*_t129*_t130*_t177 - _t131*_t178 + 0.324e3*_t146*_t49*_t53 - _t152*_t173 + _t168*_t175 + _t8*(-_t136*_t175 - 0.24e2*_t175);
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(tm_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_fx_DME_pf_k, _KMAX)(p, x2, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_w_pf_k, _KMAX)(p, x2, t, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_fx_SC_pf_k, _KMAX)(p, x2, t, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(tm_one_minus_w_pf_k, _KMAX)(p, x2, t, _hc3);
#if _KMAX >= 2
  const double _t1 = 0.2e1*_hc0[1];
  const double _t2 = 0.2e1*_hc2[1];
  const double _t3 = 0.2e1*_hc0[2];
  const double _t4 = 0.2e1*_hc2[2];
#endif
#if _KMAX >= 3
  const double _t5 = 0.3e1*_hc0[1];
  const double _t6 = 0.3e1*_hc0[3];
  const double _t7 = 0.3e1*_hc2[1];
  const double _t8 = 0.3e1*_hc2[3];
  const double _t9 = 0.2e1*_hc0[4];
  const double _t10 = 0.2e1*_hc2[4];
  const double _t11 = 0.3e1*_hc0[2];
  const double _t12 = 0.3e1*_hc0[5];
  const double _t13 = 0.3e1*_hc2[2];
  const double _t14 = 0.3e1*_hc2[5];
#endif
#if _KMAX >= 4
  const double _t15 = 0.3e1*_hc0[4];
  const double _t16 = 0.3e1*_hc2[4];
#endif

  const double f = _hc0[0]*_hc1[0] + _hc2[0]*_hc3[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[0]*_hc1[1] + _hc0[1]*_hc1[0] + _hc2[0]*_hc3[1] + _hc2[1]*_hc3[0];
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx2 = _hc0[0]*_hc1[2] + _hc0[2]*_hc1[0] + _hc2[0]*_hc3[2] + _hc2[2]*_hc3[0];
  out[3] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc0[0]*_hc1[3] + _hc0[3]*_hc1[0] + _hc1[1]*_t1 + _hc2[0]*_hc3[3] + _hc2[3]*_hc3[0] + _hc3[1]*_t2;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx2_dt = _hc0[0]*_hc1[4] + _hc0[1]*_hc1[2] + _hc0[2]*_hc1[1] + _hc0[4]*_hc1[0] + _hc2[0]*_hc3[4] + _hc2[1]*_hc3[2] + _hc2[2]*_hc3[1] + _hc2[4]*_hc3[0];
  out[7] = d2f_dx2_dt;
  const double d2f_dx2_du = 0;
  out[8] = d2f_dx2_du;
  const double d2f_dx22 = _hc0[0]*_hc1[5] + _hc0[5]*_hc1[0] + _hc1[2]*_t3 + _hc2[0]*_hc3[5] + _hc2[5]*_hc3[0] + _hc3[2]*_t4;
  out[9] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc0[0]*_hc1[6] + _hc0[6]*_hc1[0] + _hc1[1]*_t6 + _hc1[3]*_t5 + _hc2[0]*_hc3[6] + _hc2[6]*_hc3[0] + _hc3[1]*_t8 + _hc3[3]*_t7;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx2_dt2 = _hc0[0]*_hc1[7] + _hc0[2]*_hc1[3] + _hc0[3]*_hc1[2] + _hc0[7]*_hc1[0] + _hc1[1]*_t9 + _hc1[4]*_t1 + _hc2[0]*_hc3[7] + _hc2[2]*_hc3[3] + _hc2[3]*_hc3[2] + _hc2[7]*_hc3[0] + _hc3[1]*_t10 + _hc3[4]*_t2;
  out[14] = d3f_dx2_dt2;
  const double d3f_dx2_du_dt = 0;
  out[15] = d3f_dx2_du_dt;
  const double d3f_dx2_du2 = 0;
  out[16] = d3f_dx2_du2;
  const double d3f_dx22_dt = _hc0[0]*_hc1[8] + _hc0[1]*_hc1[5] + _hc0[5]*_hc1[1] + _hc0[8]*_hc1[0] + _hc1[2]*_t9 + _hc1[4]*_t3 + _hc2[0]*_hc3[8] + _hc2[1]*_hc3[5] + _hc2[5]*_hc3[1] + _hc2[8]*_hc3[0] + _hc3[2]*_t10 + _hc3[4]*_t4;
  out[17] = d3f_dx22_dt;
  const double d3f_dx22_du = 0;
  out[18] = d3f_dx22_du;
  const double d3f_dx23 = _hc0[0]*_hc1[9] + _hc0[9]*_hc1[0] + _hc1[2]*_t12 + _hc1[5]*_t11 + _hc2[0]*_hc3[9] + _hc2[9]*_hc3[0] + _hc3[2]*_t14 + _hc3[5]*_t13;
  out[19] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc0[0]*_hc1[10] + 0.4e1*_hc0[1]*_hc1[6] + _hc0[10]*_hc1[0] + 0.6e1*_hc0[3]*_hc1[3] + 0.4e1*_hc0[6]*_hc1[1] + _hc2[0]*_hc3[10] + 0.4e1*_hc2[1]*_hc3[6] + _hc2[10]*_hc3[0] + 0.6e1*_hc2[3]*_hc3[3] + 0.4e1*_hc2[6]*_hc3[1];
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx2_dt3 = _hc0[0]*_hc1[11] + _hc0[11]*_hc1[0] + _hc0[2]*_hc1[6] + _hc0[6]*_hc1[2] + 0.3e1*_hc0[7]*_hc1[1] + _hc1[3]*_t15 + _hc1[4]*_t6 + _hc1[7]*_t5 + _hc2[0]*_hc3[11] + _hc2[11]*_hc3[0] + _hc2[2]*_hc3[6] + _hc2[6]*_hc3[2] + 0.3e1*_hc2[7]*_hc3[1] + _hc3[3]*_t16 + _hc3[4]*_t8 + _hc3[7]*_t7;
  out[25] = d4f_dx2_dt3;
  const double d4f_dx2_du_dt2 = 0;
  out[26] = d4f_dx2_du_dt2;
  const double d4f_dx2_du2_dt = 0;
  out[27] = d4f_dx2_du2_dt;
  const double d4f_dx2_du3 = 0;
  out[28] = d4f_dx2_du3;
  const double d4f_dx22_dt2 = _hc0[0]*_hc1[12] + _hc0[12]*_hc1[0] + _hc0[3]*_hc1[5] + 0.4e1*_hc0[4]*_hc1[4] + _hc0[5]*_hc1[3] + 0.2e1*_hc0[7]*_hc1[2] + 0.2e1*_hc0[8]*_hc1[1] + _hc1[7]*_t3 + _hc1[8]*_t1 + _hc2[0]*_hc3[12] + _hc2[12]*_hc3[0] + _hc2[3]*_hc3[5] + 0.4e1*_hc2[4]*_hc3[4] + _hc2[5]*_hc3[3] + 0.2e1*_hc2[7]*_hc3[2] + 0.2e1*_hc2[8]*_hc3[1] + _hc3[7]*_t4 + _hc3[8]*_t2;
  out[29] = d4f_dx22_dt2;
  const double d4f_dx22_du_dt = 0;
  out[30] = d4f_dx22_du_dt;
  const double d4f_dx22_du2 = 0;
  out[31] = d4f_dx22_du2;
  const double d4f_dx23_dt = _hc0[0]*_hc1[13] + _hc0[1]*_hc1[9] + _hc0[13]*_hc1[0] + 0.3e1*_hc0[8]*_hc1[2] + _hc0[9]*_hc1[1] + _hc1[4]*_t12 + _hc1[5]*_t15 + _hc1[8]*_t11 + _hc2[0]*_hc3[13] + _hc2[1]*_hc3[9] + _hc2[13]*_hc3[0] + 0.3e1*_hc2[8]*_hc3[2] + _hc2[9]*_hc3[1] + _hc3[4]*_t14 + _hc3[5]*_t16 + _hc3[8]*_t13;
  out[32] = d4f_dx23_dt;
  const double d4f_dx23_du = 0;
  out[33] = d4f_dx23_du;
  const double d4f_dx24 = _hc0[0]*_hc1[14] + _hc0[14]*_hc1[0] + 0.4e1*_hc0[2]*_hc1[9] + 0.6e1*_hc0[5]*_hc1[5] + 0.4e1*_hc0[9]*_hc1[2] + _hc2[0]*_hc3[14] + _hc2[14]*_hc3[0] + 0.4e1*_hc2[2]*_hc3[9] + 0.6e1*_hc2[5]*_hc3[5] + 0.4e1*_hc2[9]*_hc3[2];
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
  if(!(_t7)) XC_CAT(tm_f_pf_k, _KMAX)(p, _t5*sigma_ss, 0, _t6*tau_s, _hc1);
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