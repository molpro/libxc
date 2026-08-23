/*
  Generated from python/mgga_exc/hyb_mgga_x_wr2scan.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py hyb_mgga_x_wr2scan
*/

#ifndef _HYB_MGGA_X_WR2SCAN_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _HYB_MGGA_X_WR2SCAN_KERNEL_BODY
#define _KMAX 0
#define _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#include "hyb_mgga_x_wr2scan.c"
#undef _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#include "hyb_mgga_x_wr2scan.c"
#undef _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#include "hyb_mgga_x_wr2scan.c"
#undef _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#include "hyb_mgga_x_wr2scan.c"
#undef _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#include "hyb_mgga_x_wr2scan.c"
#undef _HYB_MGGA_X_WR2SCAN_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "hyb_mgga_x_wr2scan.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_HYB_MGGA_X_WR2SCAN_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_m1_k, _KMAX)(const xc_func_type *p, double z, double n, double *out) {

  const double _t1 = z + 0.1e1 <= p->zeta_threshold;
  const double _t2 = pow(p->zeta_threshold, n);
  const double _t3 = p->zeta_threshold - 0.1e1;
  const double _t4 = z > _t3;
  const double _t5 = my_piecewise3(_t4, z, _t3);
  const double _t6 = xc_log1p(_t5);
  const double _t7 = _t6*n;
  const double _t8 = xc_expm1(_t7);
#if _KMAX >= 1
  const double _t9 = log(p->zeta_threshold);
  const double _t10 = _t8 + 0.1e1;
  const double _t11 = _t10*_t6;
  const double _t12 = _t5 + 0.1e1;
  const double _t13 = my_piecewise3(_t4, 0.1e1, 0);
  const double _t14 = _t13/_t12;
  const double _t15 = _t10*_t14;
#endif
#if _KMAX >= 2
  const double _t16 = _t10*(_t6 * _t6);
  const double _t17 = (_t13 * _t13)/(_t12 * _t12);
  const double _t18 = _t10*_t17;
  const double _t19 = _t18*n;
  const double _t20 = (n * n);
#endif
#if _KMAX >= 3
  const double _t21 = _t10*(_t6 * _t6 * _t6);
  const double _t22 = 0.2e1*_t11;
  const double _t23 = _t14*_t16;
  const double _t24 = _t18*_t7;
  const double _t25 = _t17*_t20;
  const double _t26 = (_t13 * _t13 * _t13)/(_t12 * _t12 * _t12);
  const double _t27 = _t10*_t26;
  const double _t28 = 0.2e1*_t27;
  const double _t29 = (n * n * n);
  const double _t30 = _t10*_t29;
  const double _t31 = 0.3e1*_t20;
  const double _t32 = _t27*_t31;
#endif
#if _KMAX >= 4
  const double _t33 = 0.6e1*n;
  const double _t34 = _t11*_t26;
  const double _t35 = (_t13 * _t13 * _t13 * _t13)/(_t12 * _t12 * _t12 * _t12);
  const double _t36 = _t10*_t35;
#endif

  const double f = my_piecewise3(_t1, _t2 - 0.1e1, _t8);
  out[0] = f;
#if _KMAX >= 1
  const double df_dn = my_piecewise3(_t1, _t2*_t9, _t11);
  out[1] = df_dn;
  const double df_dz = my_piecewise3(_t1, 0, _t15*n);
  out[2] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dn2 = my_piecewise3(_t1, _t2*(_t9 * _t9), _t16);
  out[3] = d2f_dn2;
  const double d2f_dz_dn = my_piecewise3(_t1, 0, _t15*_t7 + _t15);
  out[4] = d2f_dz_dn;
  const double d2f_dz2 = my_piecewise3(_t1, 0, _t18*_t20 - _t19);
  out[5] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dn3 = my_piecewise3(_t1, _t2*(_t9 * _t9 * _t9), _t21);
  out[6] = d3f_dn3;
  const double d3f_dz_dn2 = my_piecewise3(_t1, 0, _t14*_t22 + _t23*n);
  out[7] = d3f_dz_dn2;
  const double d3f_dz2_dn = my_piecewise3(_t1, 0, _t11*_t25 - _t18 + 0.2e1*_t19 - _t24);
  out[8] = d3f_dz2_dn;
  const double d3f_dz3 = my_piecewise3(_t1, 0, _t26*_t30 + _t28*n - _t32);
  out[9] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dn4 = my_piecewise3(_t1, _t2*(_t9 * _t9 * _t9 * _t9), _t10*(_t6 * _t6 * _t6 * _t6));
  out[10] = d4f_dn4;
  const double d4f_dz_dn3 = my_piecewise3(_t1, 0, _t14*_t21*n + 0.3e1*_t23);
  out[11] = d4f_dz_dn3;
  const double d4f_dz2_dn2 = my_piecewise3(_t1, 0, -_t16*_t17*n + _t16*_t25 - _t17*_t22 + 0.2e1*_t18 + 0.4e1*_t24);
  out[12] = d4f_dz2_dn2;
  const double d4f_dz3_dn = my_piecewise3(_t1, 0, -_t27*_t33 + _t28*_t7 + _t28 + _t29*_t34 - _t31*_t34 + _t32);
  out[13] = d4f_dz3_dn;
  const double d4f_dz4 = my_piecewise3(_t1, 0, 0.11e2*_t20*_t36 - 0.6e1*_t30*_t35 - _t33*_t36 + _t36*(n * n * n * n));
  out[14] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux1_k, _KMAX)(const xc_func_type *p, double a, double *out) {

#if _KMAX >= 1
  const double _t1 = (0.1e1 / (a * a));
  const double _t2 = exp(-0.1e1 / 0.4e1*_t1);
#endif
#if _KMAX >= 2
  const double _t3 = _t2/xc_powi(a, 5);
#endif

  const double f = xc_powr(M_PI, 1, 2)*erf((0.1e1 / 0.2e1)/a);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -_t1*_t2;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.2e1*_t2/(a * a * a) - 0.1e1 / 0.2e1*_t3;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = -0.6e1*_t2/(a * a * a * a) + (0.7e1 / 0.2e1)*_t2/xc_powi(a, 6) - 0.1e1 / 0.4e1*_t2/xc_powi(a, 8);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.24e2*_t2/xc_powi(a, 7) + (0.15e2 / 0.4e1)*_t2/xc_powi(a, 9) - 0.1e1 / 0.8e1*_t2/xc_powi(a, 11) + 0.24e2*_t3;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux2_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = xc_expm1(-(0.1e1 / 0.4e1)/(a * a));
#if _KMAX >= 1
  const double _t2 = _t1 + 0.1e1;
#endif
#if _KMAX >= 2
  const double _t3 = xc_powi(a, -6);
#endif
#if _KMAX >= 3
  const double _t4 = (0.9e1 / 0.4e1)*_t2;
#endif

  const double f = _t1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = (0.1e1 / 0.2e1)*_t2/(a * a * a);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = (0.1e1 / 0.4e1)*_t2*_t3 - 0.3e1 / 0.2e1*_t2/(a * a * a * a);
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.6e1*_t2/xc_powi(a, 5) + (0.1e1 / 0.8e1)*_t2/xc_powi(a, 9) - _t4/xc_powi(a, 7);
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = -0.30e2*_t2*_t3 + (0.75e2 / 0.4e1)*_t2/xc_powi(a, 8) + (0.1e1 / 0.16e2)*_t2/xc_powi(a, 12) - _t4/xc_powi(a, 10);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(att_erf_aux3_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux2_k, _KMAX)(p, a, _hc0);
  const double _t1 = 0.2e1*(a * a);
#if _KMAX >= 1
  const double _t2 = 0.4e1*_hc0[0];
#endif

  const double f = _hc0[0]*_t1 + 0.1e1 / 0.2e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _hc0[1]*_t1 + _t2*a;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = 0.8e1*_hc0[1]*a + _hc0[2]*_t1 + _t2;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.12e2*_hc0[1] + 0.12e2*_hc0[2]*a + _hc0[3]*_t1;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.24e2*_hc0[2] + 0.16e2*_hc0[3]*a + _hc0[4]*_t1;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf0_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux3_k, _KMAX)(p, a, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux2_k, _KMAX)(p, a, _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(att_erf_aux1_k, _KMAX)(p, a, _hc2);
  const double _t1 = a*(-_hc0[0] + _hc1[0]);
  const double _t2 = (0.8e1 / 0.3e1)*a;
#if _KMAX >= 1
  const double _t3 = a*(-_hc0[1] + _hc1[1]);
#endif
#if _KMAX >= 2
  const double _t4 = a*(-_hc0[2] + _hc1[2]);
#endif
#if _KMAX >= 3
  const double _t5 = a*(-_hc0[3] + _hc1[3]);
#endif

  const double f = -_t2*(_hc2[0] + 0.2e1*_t1) + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = -0.8e1 / 0.3e1*_hc2[0] - 0.16e2 / 0.3e1*_t1 - _t2*(-0.2e1*_hc0[0] + 0.2e1*_hc1[0] + _hc2[1] + 0.2e1*_t3);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = (0.32e2 / 0.3e1)*_hc0[0] - 0.32e2 / 0.3e1*_hc1[0] - 0.16e2 / 0.3e1*_hc2[1] - _t2*(-0.4e1*_hc0[1] + 0.4e1*_hc1[1] + _hc2[2] + 0.2e1*_t4) - 0.32e2 / 0.3e1*_t3;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = 0.32e2*_hc0[1] - 0.32e2*_hc1[1] - 0.8e1*_hc2[2] - _t2*(-0.6e1*_hc0[2] + 0.6e1*_hc1[2] + _hc2[3] + 0.2e1*_t5) - 0.16e2*_t4;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = 0.64e2*_hc0[2] - 0.64e2*_hc1[2] - 0.32e2 / 0.3e1*_hc2[3] - _t2*(-0.8e1*_hc0[3] + 0.8e1*_hc1[3] + _hc2[4] + 0.2e1*a*(-_hc0[4] + _hc1[4])) - 0.64e2 / 0.3e1*_t5;
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(attenuation_erf_k, _KMAX)(const xc_func_type *p, double a, double *out) {

  const double _t1 = a > 1.3500000000000001;
  const double _t2 = a >= 1.3500000000000001;
  const double _t3 = my_piecewise3(_t1, a, 1.3500000000000001);
  const double _t4 = xc_powi(_t3, -14);
  const double _t5 = xc_powi(_t3, -12);
  const double _t6 = xc_powi(_t3, -10);
  const double _t7 = xc_powi(_t3, -8);
  const double _t8 = xc_powi(_t3, -6);
  const double _t9 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
#if _KMAX >= 1
  const double _t10 = my_piecewise3(_t1, 0.1e1, 0);
  const double _t11 = xc_powi(_t3, -15);
  const double _t12 = xc_powi(_t3, -13);
  const double _t13 = xc_powi(_t3, -11);
  const double _t14 = xc_powi(_t3, -9);
  const double _t15 = xc_powi(_t3, -7);
  const double _t16 = xc_powi(_t3, -5);
  const double _t17 = my_piecewise3(_t1, 0, 0.1e1);
#endif
#if _KMAX >= 2
  const double _t18 = xc_powi(_t3, -16);
  const double _t19 = (_t10 * _t10);
#endif
#if _KMAX >= 3
  const double _t20 = (_t10 * _t10 * _t10);
#endif
#if _KMAX >= 4
  const double _t21 = (_t10 * _t10 * _t10 * _t10);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t2)) XC_CAT(attenuation_erf0_k, _KMAX)(p, my_piecewise3(_t1, 1.3500000000000001, a), _hc0);

  const double f = my_piecewise3(_t2, (0.1e1 / 0.44590694400e11)*_t4 - 0.1e1 / 0.1073479680e10*_t5 + (0.1e1 / 0.28385280e8)*_t6 - 0.1e1 / 0.829440e6*_t7 + (0.1e1 / 0.26880e5)*_t8 - 0.1e1 / 0.960e3*_t9 + (0.1e1 / 0.36e2)/(_t3 * _t3), _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_da = my_piecewise3(_t2, -0.1e1 / 0.3185049600e10*_t10*_t11 + (0.1e1 / 0.89456640e8)*_t10*_t12 - 0.1e1 / 0.2838528e7*_t10*_t13 + (0.1e1 / 0.103680e6)*_t10*_t14 - 0.1e1 / 0.4480e4*_t10*_t15 + (0.1e1 / 0.240e3)*_t10*_t16 - 0.1e1 / 0.18e2*_t10/(_t3 * _t3 * _t3), _hc0[1]*_t17);
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = my_piecewise3(_t2, (0.1e1 / 0.212336640e9)*_t18*_t19 - 0.1e1 / 0.6881280e7*_t19*_t4 + (0.1e1 / 0.258048e6)*_t19*_t5 - 0.1e1 / 0.11520e5*_t19*_t6 + (0.1e1 / 0.640e3)*_t19*_t7 - 0.1e1 / 0.48e2*_t19*_t8 + (0.1e1 / 0.6e1)*_t19*_t9, _hc0[2]*(_t17 * _t17));
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = my_piecewise3(_t2, (0.1e1 / 0.491520e6)*_t11*_t20 - 0.1e1 / 0.21504e5*_t12*_t20 + (0.1e1 / 0.1152e4)*_t13*_t20 - 0.1e1 / 0.80e2*_t14*_t20 + (0.1e1 / 0.8e1)*_t15*_t20 - 0.2e1 / 0.3e1*_t16*_t20 - 0.1e1 / 0.13271040e8*_t20/xc_powi(_t3, 17), _hc0[3]*(_t17 * _t17 * _t17));
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = my_piecewise3(_t2, -0.1e1 / 0.32768e5*_t18*_t21 + (0.13e2 / 0.21504e5)*_t21*_t4 - 0.11e2 / 0.1152e4*_t21*_t5 + (0.9e1 / 0.80e2)*_t21*_t6 - 0.7e1 / 0.8e1*_t21*_t7 + (0.10e2 / 0.3e1)*_t21*_t8 + (0.17e2 / 0.13271040e8)*_t21/xc_powi(_t3, 18), _hc0[4]*(_t17 * _t17 * _t17 * _t17));
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(scan_h1x_k, _KMAX)(const xc_func_type *p, double x, double *out) {
  const mgga_x_wr2scan_params *params = (const mgga_x_wr2scan_params *)(p->params);

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(rscan_f_alpha_large_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_wr2scan_params *params = (const mgga_x_wr2scan_params *)(p->params);

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_f_alpha_neg_k, _KMAX)(const xc_func_type *p, double a, double *out) {
  const mgga_x_wr2scan_params *params = (const mgga_x_wr2scan_params *)(p->params);

  const double _t1 = 0.1e1 - a;
  const double _t2 = params->c1/_t1;
  const double _t3 = exp(-_t2*a);
#if _KMAX >= 1
  const double _t4 = params->c1/(_t1 * _t1);
  const double _t5 = -_t2 - _t4*a;
  const double _t6 = _t3*_t5;
#endif
#if _KMAX >= 2
  const double _t7 = params->c1/(_t1 * _t1 * _t1);
  const double _t8 = _t7*a;
  const double _t9 = -0.2e1*_t4 - 0.2e1*_t8;
  const double _t10 = _t3*_t9;
  const double _t11 = _t3*(_t5 * _t5);
#endif
#if _KMAX >= 3
  const double _t12 = 0.6e1*_t7;
  const double _t13 = params->c1/(_t1 * _t1 * _t1 * _t1);
  const double _t14 = _t13*a;
  const double _t15 = -_t12 - 0.6e1*_t14;
  const double _t16 = -0.4e1*_t4 - 0.4e1*_t8;
#endif

  const double f = _t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t6;
  out[1] = df_da;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t10 + _t11;
  out[2] = d2f_da2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _t15*_t3 + _t16*_t6 + _t3*(_t5 * _t5 * _t5) + _t6*_t9;
  out[3] = d3f_da3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = _t10*_t16 + _t11*_t16 + _t11*_t9 + _t11*(-_t12*a - 0.6e1*_t4) + 0.2e1*_t15*_t6 + _t3*(_t5 * _t5 * _t5 * _t5) + _t3*(_t9 * _t9) + _t3*(-0.24e2*_t13 - 0.24e2*a*params->c1/xc_powi(_t1, 5)) + _t6*(-0.12e2*_t14 - 0.12e2*_t7);
  out[4] = d4f_da4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_f_a_k, _KMAX)(const xc_func_type *p, double x, double a, double *out) {
  const mgga_x_wr2scan_params *params = (const mgga_x_wr2scan_params *)(p->params);

  const double _t1 = (x * x);
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = -0.27123702538979005*params->eta - 0.1205497890621289;
  const double _t4 = xc_powr(0.6e1, 2, 3);
  const double _t5 = (x * x * x * x);
  const double _t6 = (0.1e1 / ((params->dp2) * (params->dp2) * (params->dp2) * (params->dp2)));
  const double _t7 = (0.1e1 / 0.576e3)*_t6;
  const double _t8 = exp(-_t4*_t5*_t7/(M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t9 = _t3*_t8;
  const double _t10 = _t2*(_t9 + 0.10e2 / 0.81e2)/(M_PI * M_CBRTPI);
  const double _t11 = a > 0;
  const double _t12 = a > 2.5;
  const double _t14 = a <= 0;
  const double _t15 = a <= 2.5;
  const double _t16 = my_piecewise3(_t12, 2.5, a);
  const double _t17 = (_t16 * _t16);
  const double _t18 = (_t16 * _t16 * _t16);
  const double _t19 = (_t16 * _t16 * _t16 * _t16);
  const double _t20 = xc_powi(_t16, 5);
  const double _t21 = xc_powi(_t16, 6);
#if _KMAX >= 1
  const double _t24 = my_piecewise3(_t11, 0, 0.1e1);
  const double _t25 = my_piecewise3(_t12, 0, 0.1e1);
  const double _t26 = my_piecewise3(_t12, 0.1e1, 0);
  const double _t29 = _t9/(M_PI * M_PI * M_PI * M_PI);
  const double _t30 = (0.1e1 / 0.12e2)*_t10;
  const double _t31 = -_t29*_t7*xc_powi(x, 5) + _t30*x;
#endif
#if _KMAX >= 2
  const double _t34 = (_t25 * _t25);
  const double _t38 = (_t31 * _t31);
  const double _t39 = _t29*_t6;
  const double _t40 = _t39*_t5;
  const double _t41 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t42 = xc_powi((params->dp2), -8);
  const double _t43 = _t4*_t41*_t42*_t9*xc_powi(x, 8);
  const double _t44 = _t30 - 0.7e1 / 0.576e3*_t40 + (0.1e1 / 0.82944e5)*_t43;
#endif
#if _KMAX >= 3
  const double _t48 = (_t25 * _t25 * _t25);
  const double _t55 = (_t31 * _t31 * _t31);
  const double _t56 = _t39*(x * x * x);
  const double _t57 = _t2*_t9/((M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI)*xc_powi((params->dp2), 12));
  const double _t58 = _t57*xc_powi(x, 11);
  const double _t59 = xc_powi(x, 7);
  const double _t60 = (0.5e1 / 0.27648e5)*_t3*_t4*_t41*_t42*_t59*_t8 - 0.5e1 / 0.96e2*_t56 - 0.1e1 / 0.1990656e7*_t58;
  const double _t62 = (0.1e1 / 0.6e1)*_t10 - 0.7e1 / 0.288e3*_t40 + (0.1e1 / 0.41472e5)*_t43;
#endif
#if _KMAX >= 4
  const double _t68 = (_t25 * _t25 * _t25 * _t25);
  const double _t69 = (_t31 * _t31 * _t31 * _t31);
  const double _t70 = (_t44 * _t44);
  const double _t71 = -0.5e1 / 0.32e2*_t1*_t39 + (0.5e1 / 0.3072e4)*_t3*_t4*_t41*_t42*_t8*xc_powi(x, 6) + (0.1e1 / 0.47775744e8)*_t3*_t8*xc_powi(x, 14)/(xc_powi(M_PI, 12)*xc_powi((params->dp2), 16)) - 0.13e2 / 0.995328e6*_t57*xc_powi(x, 10);
  const double _t72 = (0.1e1 / 0.4e1)*_t10 - 0.7e1 / 0.192e3*_t40 + (0.1e1 / 0.27648e5)*_t43;
  const double _t73 = (0.5e1 / 0.13824e5)*_t3*_t4*_t41*_t42*_t59*_t8 - 0.5e1 / 0.48e2*_t56 - 0.1e1 / 0.995328e6*_t58;
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_h1x_k, _KMAX)(p, (0.1e1 / 0.24e2)*_t1*_t10, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(_t14) XC_CAT(r2scan_f_alpha_neg_k, _KMAX)(p, my_piecewise3(_t11, 0, a), _hc1);
  double _hc2[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(rscan_f_alpha_large_k, _KMAX)(p, my_piecewise3(_t12, a, 2.5), _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(scan_gx_k, _KMAX)(p, x, _hc3);
  const double _t13 = 1.1739999999999999 - _hc0[0];
  const double _t22 = my_piecewise5(_t14, _hc1[0], _t15, -0.023185843322000001*xc_powi(_t16, 7) - 0.66700000000000004*_t16 - 0.44455549999999999*_t17 - 0.66308660104899997*_t18 + 1.45129704449*_t19 - 0.88799804159700002*_t20 + 0.234528941479*_t21 + 0.1e1, _hc2[0]);
  const double _t23 = _hc0[0] + _t13*_t22;
#if _KMAX >= 1
  const double _t27 = my_piecewise5(_t14, _hc1[1]*_t24, _t15, -0.88911099999999998*_t16*_t25 - 1.9892598031469999*_t17*_t25 + 5.8051881779599999*_t18*_t25 - 4.4399902079849998*_t19*_t25 + 1.4071736488740001*_t20*_t25 - 0.16230090325400001*_t21*_t25 - 0.66700000000000004*_t25, _hc2[1]*_t26);
  const double _t28 = _hc3[0]*_t13;
  const double _t32 = _hc0[1]*_t31;
  const double _t33 = _hc0[1]*_t31 - _t22*_t32;
#endif
#if _KMAX >= 2
  const double _t35 = my_piecewise5(_t14, _hc1[2]*(_t24 * _t24), _t15, -3.9785196062939998*_t16*_t34 + 17.415564533880001*_t17*_t34 - 17.759960831939999*_t18*_t34 + 7.0358682443700005*_t19*_t34 - 0.97380541952400002*_t20*_t34 - 0.88911099999999998*_t34, _hc2[2]*(_t26 * _t26));
  const double _t36 = _hc3[0]*_t32;
  const double _t37 = 0.2e1*_hc3[1];
  const double _t45 = _hc0[2]*_t38;
  const double _t46 = _hc0[1]*_t44;
  const double _t47 = _hc0[1]*_t44 + _hc0[2]*_t38 - _t22*_t45 - _t22*_t46;
#endif
#if _KMAX >= 3
  const double _t49 = my_piecewise5(_t14, _hc1[3]*(_t24 * _t24 * _t24), _t15, 34.831129067760003*_t16*_t48 - 53.279882495819997*_t17*_t48 + 28.143472977480002*_t18*_t48 - 4.8690270976200001*_t19*_t48 - 3.9785196062939998*_t48, _hc2[3]*(_t26 * _t26 * _t26));
  const double _t50 = _hc3[2]*_t13;
  const double _t51 = _t32*_t37;
  const double _t52 = -_t27*_t45 - _t27*_t46;
  const double _t53 = 0.3e1*_hc3[2];
  const double _t54 = 0.3e1*_hc3[1];
  const double _t61 = _hc0[3]*_t55;
  const double _t63 = _hc0[1]*_t60;
  const double _t64 = _hc0[2]*_t31;
  const double _t65 = _t44*_t64;
  const double _t66 = _t62*_t64;
  const double _t67 = _hc0[1]*_t60 + _hc0[2]*_t31*_t44 + _hc0[2]*_t31*_t62 + _hc0[3]*_t55 - _t22*_t61 - _t22*_t63 - _t22*_t65 - _t22*_t66;
#endif
#if _KMAX >= 4
  const double _t74 = _hc0[3]*_t38;
#endif

  const double f = _hc3[0]*_t23;
  out[0] = f;
#if _KMAX >= 1
  const double df_da = _t27*_t28;
  out[1] = df_da;
  const double df_dx = _hc3[0]*_t33 + _hc3[1]*_t23;
  out[2] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_da2 = _t28*_t35;
  out[3] = d2f_da2;
  const double d2f_dx_da = _hc3[1]*_t13*_t27 - _t27*_t36;
  out[4] = d2f_dx_da;
  const double d2f_dx2 = _hc3[0]*_t47 + _hc3[2]*_t23 + _t33*_t37;
  out[5] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_da3 = _t28*_t49;
  out[6] = d3f_da3;
  const double d3f_dx_da2 = _hc3[1]*_t13*_t35 - _t35*_t36;
  out[7] = d3f_dx_da2;
  const double d3f_dx2_da = _hc3[0]*_t52 + _t27*_t50 - _t27*_t51;
  out[8] = d3f_dx2_da;
  const double d3f_dx3 = _hc3[0]*_t67 + _hc3[3]*_t23 + _t33*_t53 + _t47*_t54;
  out[9] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_da4 = _t28*my_piecewise5(_t14, _hc1[4]*(_t24 * _t24 * _t24 * _t24), _t15, -106.55976499163999*_t16*_t68 + 84.430418932440006*_t17*_t68 - 19.47610839048*_t18*_t68 + 34.831129067760003*_t68, _hc2[4]*(_t26 * _t26 * _t26 * _t26));
  out[10] = d4f_da4;
  const double d4f_dx_da3 = _hc3[1]*_t13*_t49 - _t36*_t49;
  out[11] = d4f_dx_da3;
  const double d4f_dx2_da2 = _hc3[0]*(-_t35*_t45 - _t35*_t46) + _t35*_t50 - _t35*_t51;
  out[12] = d4f_dx2_da2;
  const double d4f_dx3_da = _hc3[0]*(-_t27*_t61 - _t27*_t63 - _t27*_t65 - _t27*_t66) + _hc3[3]*_t13*_t27 - _t27*_t32*_t53 + _t52*_t54;
  out[13] = d4f_dx3_da;
  const double d4f_dx4 = _hc3[0]*(-_hc0[1]*_t22*_t71 + _hc0[1]*_t71 - _hc0[2]*_t22*_t44*_t62 - _hc0[2]*_t22*_t70 + 0.2e1*_hc0[2]*_t31*_t60 + _hc0[2]*_t31*_t73 + _hc0[2]*_t44*_t62 + _hc0[2]*_t70 + _hc0[3]*_t38*_t44 + _hc0[3]*_t38*_t62 + _hc0[3]*_t38*_t72 - _hc0[4]*_t22*_t69 + _hc0[4]*_t69 - _t22*_t44*_t74 - 0.2e1*_t22*_t60*_t64 - _t22*_t62*_t74 - _t22*_t64*_t73 - _t22*_t72*_t74) + 0.4e1*_hc3[1]*_t67 + 0.6e1*_hc3[2]*_t47 + 0.4e1*_hc3[3]*_t33 + _hc3[4]*_t23;
  out[14] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(r2scan_f_k, _KMAX)(const xc_func_type *p, double x, double u, double t, double *out) {
  const mgga_x_wr2scan_params *params = (const mgga_x_wr2scan_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(mgga_alpha_reg_k, _KMAX)(p, x, t, params->eta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(r2scan_f_a_k, _KMAX)(p, x, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = ((_hc0[2]) * (_hc0[2]));
  const double _t2 = _hc0[3]*_hc1[3];
  const double _t3 = _hc1[4] + _t2;
#endif
#if _KMAX >= 3
  const double _t4 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t5 = _hc0[8]*_hc1[3];
  const double _t6 = 0.2e1*_hc0[2];
  const double _t7 = _hc0[3]*_hc1[6];
  const double _t8 = _hc0[2]*_hc1[7];
  const double _t9 = _hc0[9]*_hc1[3];
  const double _t10 = _hc0[2]*_t7 + _t5 + _t8;
  const double _t11 = _hc0[3]*_hc1[7] + _hc1[8];
  const double _t12 = 0.2e1*_t3;
  const double _t13 = _hc1[7] + _t7;
  const double _t14 = _hc0[3]*_t13 + _t11 + _t9;
#endif
#if _KMAX >= 4
  const double _t15 = _hc0[3]*_hc1[10];
  const double _t16 = _hc0[8]*_hc1[6];
  const double _t17 = _hc0[18]*_hc1[3];
  const double _t18 = _hc1[11]*_t1;
  const double _t19 = _hc0[9]*_hc1[6];
  const double _t20 = 0.2e1*_t10;
  const double _t21 = _hc0[19]*_hc1[3];
  const double _t22 = _hc0[2]*_hc1[12];
  const double _t23 = _hc0[2]*_hc1[11];
  const double _t24 = _hc0[3]*_t23 + _hc0[8]*_hc1[7] + _t22;
  const double _t25 = _hc0[3]*_hc1[12] + _hc1[13];
  const double _t26 = 0.2e1*_hc0[9];
  const double _t27 = _hc0[3]*_hc1[11] + _hc1[12];
  const double _t28 = _hc0[3]*_t27 + _hc0[9]*_hc1[7] + _t25;
#endif

  const double f = _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc0[2]*_hc1[1];
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc0[3]*_hc1[1] + _hc1[2];
  out[3] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[3]*_t1;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dx_dt = _hc0[2]*_hc1[4] + _hc0[2]*_t2 + _hc0[8]*_hc1[1];
  out[7] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[8] = d2f_dx_du;
  const double d2f_dx2 = _hc0[3]*_hc1[4] + _hc0[3]*_t3 + _hc0[9]*_hc1[1] + _hc1[5];
  out[9] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc1[6]*_t4;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dx_dt2 = _hc1[7]*_t1 + _t1*_t7 + _t5*_t6;
  out[14] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[15] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[16] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc0[18]*_hc1[1] + _hc0[2]*_hc1[8] + _hc0[2]*_t9 + _hc0[3]*_t10 + _hc0[3]*_t8 + _hc0[8]*_hc1[4] + _hc0[8]*_t3;
  out[17] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[18] = d3f_dx2_du;
  const double d3f_dx3 = _hc0[19]*_hc1[1] + _hc0[3]*_hc1[8] + _hc0[3]*_t11 + _hc0[3]*_t14 + _hc0[9]*_hc1[4] + _hc0[9]*_t12 + _hc1[9];
  out[19] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_hc1[10];
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dx_dt3 = _hc1[11]*_t4 + 0.3e1*_t1*_t16 + _t15*_t4;
  out[25] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[26] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[27] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[28] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc0[3]*_t18 + _hc0[3]*(_t1*_t15 + _t16*_t6 + _t18) + _hc0[8]*_t20 + 0.2e1*_hc0[8]*_t8 + _hc1[12]*_t1 + _t1*_t19 + _t17*_t6;
  out[29] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[30] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[31] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc0[18]*_hc1[4] + _hc0[18]*_t12 + _hc0[2]*_hc1[13] + _hc0[2]*_t21 + _hc0[3]*_t22 + _hc0[3]*_t24 + _hc0[3]*(_hc0[2]*_t19 + _hc0[3]*(_hc0[2]*_t15 + _t16 + _t23) + _hc0[8]*_t13 + _t17 + _t24) + _hc0[33]*_hc1[1] + _hc0[8]*_hc1[8] + _hc0[8]*_t11 + _hc0[8]*_t14 + _hc0[9]*_t20 + _hc0[9]*_t8;
  out[32] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[33] = d4f_dx3_du;
  const double d4f_dx4 = _hc0[19]*_hc1[4] + 0.3e1*_hc0[19]*_t3 + _hc0[3]*_hc1[13] + _hc0[3]*_t25 + _hc0[3]*_t28 + _hc0[3]*(_hc0[3]*(_hc0[3]*(_hc1[11] + _t15) + _t19 + _t27) + _t13*_t26 + _t21 + _t28) + _hc0[34]*_hc1[1] + _hc0[9]*_hc1[8] + 0.3e1*_hc0[9]*_t14 + _hc1[14] + _t11*_t26;
  out[34] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(wr2scan_f_k, _KMAX)(const xc_func_type *p, double rs, double z, double x, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(opz_pow_n_m1_k, _KMAX)(p, z, 0.1e1 / 0.3e1, _hc0);
  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = M_CBRT3;
  const double _t3 = _t1*_t2;
  const double _t4 = _t3*rs;
  const double _t5 = _hc0[0] + 0.1e1;
  const double _t6 = (0.1e1 / (M_CBRTPI));
  const double _t7 = _t6*p->cam_omega;
  const double _t8 = (0.1e1 / 0.6e1)*_t7;
  const double _t9 = _t8/_t5;
  const double _t10 = -p->cam_alpha - p->cam_beta + 1.0;
#if _KMAX >= 1
  const double _t14 = (0.1e1 / (_t5 * _t5));
#endif
#if _KMAX >= 2
  const double _t23 = ((_hc0[2]) * (_hc0[2]));
  const double _t24 = (0.1e1 / 0.3e1)*_t23;
  const double _t25 = (0.1e1 / (_t5 * _t5 * _t5));
  const double _t30 = (0.1e1 / (_t5 * _t5 * _t5 * _t5));
  const double _t31 = _t23*_t30;
  const double _t32 = (rs * rs);
  const double _t33 = M_CBRT2;
  const double _t34 = xc_powr(0.3e1, 2, 3);
  const double _t35 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t36 = ((p->cam_omega) * (p->cam_omega));
#endif
#if _KMAX >= 3
  const double _t51 = (0.1e1 / M_PI);
  const double _t52 = ((p->cam_omega) * (p->cam_omega) * (p->cam_omega));
  const double _t55 = (rs * rs * rs);
  const double _t56 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t57 = xc_powi(_t5, -6);
  const double _t58 = _t56*_t57;
  const double _t59 = _t55*_t58;
  const double _t63 = xc_powi(_t5, -5);
  const double _t64 = _t56*_t63;
  const double _t65 = (0.1e1 / 0.3e1)*_t64;
  const double _t70 = _hc0[2]*_t25;
  const double _t73 = _t23*_t63;
  const double _t74 = _t32*_t73;
  const double _t75 = _hc0[5]*rs;
  const double _t78 = (0.2e1 / 0.9e1)*_t31;
  const double _t79 = _hc0[2]*_t30;
  const double _t80 = _t79*rs;
  const double _t81 = (0.1e1 / 0.9e1)*_t70;
#endif
#if _KMAX >= 4
  const double _t91 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t92 = xc_powi(_t5, -7);
  const double _t95 = ((_hc0[5]) * (_hc0[5]));
#endif
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_k, _KMAX)(p, _t4*_t9, _hc1);
  double _hc2[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(r2scan_f_k, _KMAX)(p, x, 0, t, _hc2);
  const double _t11 = _hc1[0]*_t10;
#if _KMAX >= 1
  const double _t12 = _hc2[0]*_t10;
  const double _t13 = _t12*_t4;
  const double _t15 = _hc1[1]*_t14*_t8;
  const double _t16 = _hc0[2]*_t15;
  const double _t17 = _t12*_t3;
  const double _t18 = _hc1[1]*_t9;
#endif
#if _KMAX >= 2
  const double _t19 = _hc2[1]*_t10;
  const double _t20 = _t16*_t4;
  const double _t21 = _hc2[3]*_t10;
  const double _t22 = _hc0[5]*_t15;
  const double _t26 = _hc1[1]*_t7;
  const double _t27 = _t25*_t26;
  const double _t28 = _t24*_t27;
  const double _t29 = (0.1e1 / 0.18e2)*_t12;
  const double _t37 = _hc1[2]*_t33*_t34*_t35*_t36;
  const double _t38 = _t32*_t37;
  const double _t39 = _t31*_t38;
  const double _t40 = _t18*_t3;
  const double _t41 = _t25*_t29;
  const double _t42 = _t37*rs;
  const double _t43 = _t41*_t42;
  const double _t44 = _t14*_t37;
#endif
#if _KMAX >= 3
  const double _t45 = _hc2[4]*_t10;
  const double _t46 = _t10*_t20;
  const double _t47 = _t19*_t4;
  const double _t48 = (0.1e1 / 0.18e2)*_t19;
  const double _t49 = _t21*_t4;
  const double _t50 = (0.1e1 / 0.18e2)*_t21;
  const double _t53 = _hc1[3]*_t51*_t52;
  const double _t54 = _t29*_t53;
  const double _t60 = _hc0[9]*_t15;
  const double _t61 = _t26*_t56;
  const double _t62 = _t30*_t61;
  const double _t66 = _t12*_t37;
  const double _t67 = _t32*_t66;
  const double _t68 = _t10*_t40;
  const double _t69 = _t19*_t3;
  const double _t71 = _t42*_t70;
  const double _t72 = _t16*_t3;
  const double _t76 = _t37*_t75;
  const double _t77 = _t66*rs;
#endif
#if _KMAX >= 4
  const double _t82 = _t4*_t45;
  const double _t83 = (0.1e1 / 0.18e2)*_t39;
  const double _t84 = _hc2[7]*_t10;
  const double _t85 = _t4*_t84;
  const double _t86 = _hc2[9]*_t10;
  const double _t87 = _t4*_t86;
  const double _t88 = _t53*_t59;
  const double _t89 = _t4*_t62;
  const double _t90 = _t38*_t65;
  const double _t93 = _t12*_t53;
  const double _t94 = _t55*_t93;
  const double _t96 = _t13*_t27;
  const double _t97 = _t13*_t63;
  const double _t98 = _t30*_t66;
  const double _t99 = (0.1e1 / 0.108e3)*_hc1[4]*((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega))/(M_PI * M_CBRTPI);
  const double _t100 = _t17*_t99;
  const double _t101 = _hc0[5]*_t66;
  const double _t102 = (0.1e1 / 0.18e2)*_t71;
  const double _t103 = _t10*_t72;
  const double _t104 = _t53*_t74;
  const double _t105 = _t25*_t76;
  const double _t106 = _t42*_t78;
  const double _t107 = _t21*_t3;
  const double _t108 = _t17*_t30;
  const double _t109 = (0.1e1 / 0.18e2)*_t44;
  const double _t110 = _t10*_t109;
  const double _t111 = _t53*_t80;
  const double _t112 = _t37*_t81;
  const double _t113 = _t25*_t53;
#endif

  const double f = _hc2[0]*_t11;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc2[1]*_t11;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc2[3]*_t11;
  out[3] = df_dx;
  const double df_dz = -_t13*_t16;
  out[4] = df_dz;
  const double df_drs = _t17*_t18;
  out[5] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc2[4]*_t11;
  out[6] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[7] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[8] = d2f_du2;
  const double d2f_dx_dt = _hc2[7]*_t11;
  out[9] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[10] = d2f_dx_du;
  const double d2f_dx2 = _hc2[9]*_t11;
  out[11] = d2f_dx2;
  const double d2f_dz_dt = -_t19*_t20;
  out[12] = d2f_dz_dt;
  const double d2f_dz_du = 0;
  out[13] = d2f_dz_du;
  const double d2f_dz_dx = -_t20*_t21;
  out[14] = d2f_dz_dx;
  const double d2f_dz2 = -_t13*_t22 + _t13*_t28 + _t29*_t39;
  out[15] = d2f_dz2;
  const double d2f_drs_dt = _t19*_t40;
  out[16] = d2f_drs_dt;
  const double d2f_drs_du = 0;
  out[17] = d2f_drs_du;
  const double d2f_drs_dx = _t21*_t40;
  out[18] = d2f_drs_dx;
  const double d2f_drs_dz = -_hc0[2]*_t15*_t17 - _hc0[2]*_t43;
  out[19] = d2f_drs_dz;
  const double d2f_drs2 = _t29*_t44;
  out[20] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc2[10]*_t11;
  out[21] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[22] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[23] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[24] = d3f_du3;
  const double d3f_dx_dt2 = _hc2[14]*_t11;
  out[25] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[26] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[27] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc2[17]*_t11;
  out[28] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[29] = d3f_dx2_du;
  const double d3f_dx3 = _hc2[19]*_t11;
  out[30] = d3f_dx3;
  const double d3f_dz_dt2 = -_t20*_t45;
  out[31] = d3f_dz_dt2;
  const double d3f_dz_du_dt = 0;
  out[32] = d3f_dz_du_dt;
  const double d3f_dz_du2 = 0;
  out[33] = d3f_dz_du2;
  const double d3f_dz_dx_dt = -_hc2[7]*_t46;
  out[34] = d3f_dz_dx_dt;
  const double d3f_dz_dx_du = 0;
  out[35] = d3f_dz_dx_du;
  const double d3f_dz_dx2 = -_hc2[9]*_t46;
  out[36] = d3f_dz_dx2;
  const double d3f_dz2_dt = -_t22*_t47 + _t28*_t47 + _t39*_t48;
  out[37] = d3f_dz2_dt;
  const double d3f_dz2_du = 0;
  out[38] = d3f_dz2_du;
  const double d3f_dz2_dx = -_t22*_t49 + _t28*_t49 + _t39*_t50;
  out[39] = d3f_dz2_dx;
  const double d3f_dz3 = _hc0[2]*_hc0[5]*_hc1[1]*_hc2[0]*_t1*_t10*_t2*_t25*_t6*p->cam_omega*rs + (0.1e1 / 0.6e1)*_hc0[2]*_hc0[5]*_hc1[2]*_hc2[0]*_t10*_t30*_t32*_t33*_t34*_t35*_t36 - _t13*_t60 - _t13*_t62 - _t54*_t59 - _t65*_t67;
  out[40] = d3f_dz3;
  const double d3f_drs_dt2 = _hc2[4]*_t68;
  out[41] = d3f_drs_dt2;
  const double d3f_drs_du_dt = 0;
  out[42] = d3f_drs_du_dt;
  const double d3f_drs_du2 = 0;
  out[43] = d3f_drs_du2;
  const double d3f_drs_dx_dt = _hc2[7]*_t68;
  out[44] = d3f_drs_dx_dt;
  const double d3f_drs_dx_du = 0;
  out[45] = d3f_drs_dx_du;
  const double d3f_drs_dx2 = _hc2[9]*_t68;
  out[46] = d3f_drs_dx2;
  const double d3f_drs_dz_dt = -_t16*_t69 - _t48*_t71;
  out[47] = d3f_drs_dz_dt;
  const double d3f_drs_dz_du = 0;
  out[48] = d3f_drs_dz_du;
  const double d3f_drs_dz_dx = -_t21*_t72 - _t50*_t71;
  out[49] = d3f_drs_dz_dx;
  const double d3f_drs_dz2 = -_t17*_t22 + _t17*_t28 - _t41*_t76 + _t54*_t74 + _t77*_t78;
  out[50] = d3f_drs_dz2;
  const double d3f_drs2_dt = _t44*_t48;
  out[51] = d3f_drs2_dt;
  const double d3f_drs2_du = 0;
  out[52] = d3f_drs2_du;
  const double d3f_drs2_dx = _t44*_t50;
  out[53] = d3f_drs2_dx;
  const double d3f_drs2_dz = -_t54*_t80 - _t66*_t81;
  out[54] = d3f_drs2_dz;
  const double d3f_drs3 = _t41*_t53;
  out[55] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc2[20]*_t11;
  out[56] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[57] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[58] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[59] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[60] = d4f_du4;
  const double d4f_dx_dt3 = _hc2[25]*_t11;
  out[61] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[62] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[63] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[64] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc2[29]*_t11;
  out[65] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[66] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[67] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc2[32]*_t11;
  out[68] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[69] = d4f_dx3_du;
  const double d4f_dx4 = _hc2[34]*_t11;
  out[70] = d4f_dx4;
  const double d4f_dz_dt3 = -_hc2[10]*_t46;
  out[71] = d4f_dz_dt3;
  const double d4f_dz_du_dt2 = 0;
  out[72] = d4f_dz_du_dt2;
  const double d4f_dz_du2_dt = 0;
  out[73] = d4f_dz_du2_dt;
  const double d4f_dz_du3 = 0;
  out[74] = d4f_dz_du3;
  const double d4f_dz_dx_dt2 = -_hc2[14]*_t46;
  out[75] = d4f_dz_dx_dt2;
  const double d4f_dz_dx_du_dt = 0;
  out[76] = d4f_dz_dx_du_dt;
  const double d4f_dz_dx_du2 = 0;
  out[77] = d4f_dz_dx_du2;
  const double d4f_dz_dx2_dt = -_hc2[17]*_t46;
  out[78] = d4f_dz_dx2_dt;
  const double d4f_dz_dx2_du = 0;
  out[79] = d4f_dz_dx2_du;
  const double d4f_dz_dx3 = -_hc2[19]*_t46;
  out[80] = d4f_dz_dx3;
  const double d4f_dz2_dt2 = -_t22*_t82 + _t28*_t82 + _t45*_t83;
  out[81] = d4f_dz2_dt2;
  const double d4f_dz2_du_dt = 0;
  out[82] = d4f_dz2_du_dt;
  const double d4f_dz2_du2 = 0;
  out[83] = d4f_dz2_du2;
  const double d4f_dz2_dx_dt = -_t22*_t85 + _t28*_t85 + _t83*_t84;
  out[84] = d4f_dz2_dx_dt;
  const double d4f_dz2_dx_du = 0;
  out[85] = d4f_dz2_dx_du;
  const double d4f_dz2_dx2 = -_t22*_t87 + _t28*_t87 + _t83*_t86;
  out[86] = d4f_dz2_dx2;
  const double d4f_dz3_dt = _hc0[2]*_hc0[5]*_hc1[1]*_hc2[1]*_t1*_t10*_t2*_t25*_t6*p->cam_omega*rs + (0.1e1 / 0.6e1)*_hc0[2]*_hc0[5]*_hc1[2]*_hc2[1]*_t10*_t30*_t32*_t33*_t34*_t35*_t36 - _t19*_t89 - _t19*_t90 - _t47*_t60 - _t48*_t88;
  out[87] = d4f_dz3_dt;
  const double d4f_dz3_du = 0;
  out[88] = d4f_dz3_du;
  const double d4f_dz3_dx = _hc0[2]*_hc0[5]*_hc1[1]*_hc2[3]*_t1*_t10*_t2*_t25*_t6*p->cam_omega*rs + (0.1e1 / 0.6e1)*_hc0[2]*_hc0[5]*_hc1[2]*_hc2[3]*_t10*_t30*_t32*_t33*_t34*_t35*_t36 - _t21*_t89 - _t21*_t90 - _t49*_t60 - _t50*_t88;
  out[89] = d4f_dz3_dx;
  const double d4f_dz4 = -_hc0[14]*_t13*_t15 + (0.4e1 / 0.3e1)*_hc0[2]*_hc0[9]*_t96 - 0.6e1*_hc0[5]*_t13*_t26*_t31 - _hc0[5]*_t24*_t57*_t94 + (0.2e1 / 0.9e1)*_hc0[9]*_t67*_t79 + _t100*_t91*(rs * rs * rs * rs)/xc_powi(_t5, 8) - 0.2e1*_t101*_t74 + 0.4e1*_t26*_t91*_t97 + (0.1e1 / 0.6e1)*_t32*_t95*_t98 + 0.2e1*_t57*_t67*_t91 + (0.2e1 / 0.3e1)*_t91*_t92*_t94 + _t95*_t96;
  out[90] = d4f_dz4;
  const double d4f_drs_dt3 = _hc2[10]*_t68;
  out[91] = d4f_drs_dt3;
  const double d4f_drs_du_dt2 = 0;
  out[92] = d4f_drs_du_dt2;
  const double d4f_drs_du2_dt = 0;
  out[93] = d4f_drs_du2_dt;
  const double d4f_drs_du3 = 0;
  out[94] = d4f_drs_du3;
  const double d4f_drs_dx_dt2 = _hc2[14]*_t68;
  out[95] = d4f_drs_dx_dt2;
  const double d4f_drs_dx_du_dt = 0;
  out[96] = d4f_drs_dx_du_dt;
  const double d4f_drs_dx_du2 = 0;
  out[97] = d4f_drs_dx_du2;
  const double d4f_drs_dx2_dt = _hc2[17]*_t68;
  out[98] = d4f_drs_dx2_dt;
  const double d4f_drs_dx2_du = 0;
  out[99] = d4f_drs_dx2_du;
  const double d4f_drs_dx3 = _hc2[19]*_t68;
  out[100] = d4f_drs_dx3;
  const double d4f_drs_dz_dt2 = -_t102*_t45 - _t45*_t72;
  out[101] = d4f_drs_dz_dt2;
  const double d4f_drs_dz_du_dt = 0;
  out[102] = d4f_drs_dz_du_dt;
  const double d4f_drs_dz_du2 = 0;
  out[103] = d4f_drs_dz_du2;
  const double d4f_drs_dz_dx_dt = -_hc2[7]*_t103 - _t102*_t84;
  out[104] = d4f_drs_dz_dx_dt;
  const double d4f_drs_dz_dx_du = 0;
  out[105] = d4f_drs_dz_dx_du;
  const double d4f_drs_dz_dx2 = -_hc2[9]*_t103 - _t102*_t86;
  out[106] = d4f_drs_dz_dx2;
  const double d4f_drs_dz2_dt = _t104*_t48 - _t105*_t48 + _t106*_t19 - _t22*_t69 + _t28*_t69;
  out[107] = d4f_drs_dz2_dt;
  const double d4f_drs_dz2_du = 0;
  out[108] = d4f_drs_dz2_du;
  const double d4f_drs_dz2_dx = _t104*_t50 - _t105*_t50 + _t106*_t21 - _t107*_t22 + _t107*_t28;
  out[109] = d4f_drs_dz2_dx;
  const double d4f_drs_dz3 = _hc0[2]*_hc0[5]*_hc1[1]*_hc2[0]*_t1*_t10*_t2*_t25*_t6*p->cam_omega + (0.2e1 / 0.3e1)*_hc0[2]*_hc0[5]*_hc1[2]*_hc2[0]*_t10*_t30*_t33*_t34*_t35*_t36*rs + (0.1e1 / 0.6e1)*_hc0[2]*_hc0[5]*_hc1[3]*_hc2[0]*_t10*_t32*_t51*_t52*_t63 - _hc0[9]*_t43 - _t100*_t55*_t56*_t92 - _t108*_t61 - _t17*_t60 - 0.1e1 / 0.2e1*_t32*_t58*_t93 - _t64*_t77;
  out[110] = d4f_drs_dz3;
  const double d4f_drs2_dt2 = _t109*_t45;
  out[111] = d4f_drs2_dt2;
  const double d4f_drs2_du_dt = 0;
  out[112] = d4f_drs2_du_dt;
  const double d4f_drs2_du2 = 0;
  out[113] = d4f_drs2_du2;
  const double d4f_drs2_dx_dt = _hc2[7]*_t110;
  out[114] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx_du = 0;
  out[115] = d4f_drs2_dx_du;
  const double d4f_drs2_dx2 = _hc2[9]*_t110;
  out[116] = d4f_drs2_dx2;
  const double d4f_drs2_dz_dt = -_t111*_t48 - _t112*_t19;
  out[117] = d4f_drs2_dz_dt;
  const double d4f_drs2_dz_du = 0;
  out[118] = d4f_drs2_dz_du;
  const double d4f_drs2_dz_dx = -_t111*_t50 - _t112*_t21;
  out[119] = d4f_drs2_dz_dx;
  const double d4f_drs2_dz2 = _t100*_t23*_t32*_t57 - 0.1e1 / 0.9e1*_t101*_t25 + _t24*_t98 - _t30*_t54*_t75 + (0.1e1 / 0.3e1)*_t73*_t93*rs;
  out[120] = d4f_drs2_dz2;
  const double d4f_drs3_dt = _t113*_t48;
  out[121] = d4f_drs3_dt;
  const double d4f_drs3_du = 0;
  out[122] = d4f_drs3_du;
  const double d4f_drs3_dx = _t113*_t50;
  out[123] = d4f_drs3_dx;
  const double d4f_drs3_dz = -_hc0[2]*_t97*_t99 - 0.1e1 / 0.6e1*_t79*_t93;
  out[124] = d4f_drs3_dz;
  const double d4f_drs4 = _t108*_t99;
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

GPU_DEVICE_FUNCTION static inline void XC_CAT(wr2scan_f_z0_k, _KMAX)(const xc_func_type *p, double rs, double x, double u, double t, double *out) {

  const double _t1 = xc_powr(0.2e1, 2, 3)*M_CBRT3;
  const double _t2 = (0.1e1 / 0.6e1)*_t1*p->cam_omega/M_CBRTPI;
  const double _t3 = -p->cam_alpha - p->cam_beta + 1.0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(attenuation_erf_k, _KMAX)(p, _t2*rs, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(r2scan_f_k, _KMAX)(p, x, 0, t, _hc1);
  const double _t4 = _hc0[0]*_t3;
#if _KMAX >= 1
  const double _t5 = _hc1[0]*_t3;
  const double _t6 = _hc0[1]*_t2;
#endif
#if _KMAX >= 2
  const double _t7 = _hc1[1]*_t3;
  const double _t8 = _hc1[3]*_t3;
  const double _t9 = (0.1e1 / 0.18e2)*_t5;
  const double _t10 = M_CBRT2*xc_powr(0.3e1, 2, 3)*_hc0[2]*((p->cam_omega) * (p->cam_omega))/(M_CBRTPI * M_CBRTPI);
#endif
#if _KMAX >= 3
  const double _t11 = _t3*_t6;
  const double _t12 = (0.1e1 / 0.18e2)*_t10;
  const double _t13 = _hc0[3]*((p->cam_omega) * (p->cam_omega) * (p->cam_omega))/M_PI;
#endif
#if _KMAX >= 4
  const double _t14 = _t12*_t3;
  const double _t15 = (0.1e1 / 0.18e2)*_t13;
#endif

  const double f = _hc1[0]*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _hc1[1]*_t4;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dx = _hc1[3]*_t4;
  out[3] = df_dx;
  const double df_drs = _t5*_t6;
  out[4] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _hc1[4]*_t4;
  out[5] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[6] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[7] = d2f_du2;
  const double d2f_dx_dt = _hc1[7]*_t4;
  out[8] = d2f_dx_dt;
  const double d2f_dx_du = 0;
  out[9] = d2f_dx_du;
  const double d2f_dx2 = _hc1[9]*_t4;
  out[10] = d2f_dx2;
  const double d2f_drs_dt = _t6*_t7;
  out[11] = d2f_drs_dt;
  const double d2f_drs_du = 0;
  out[12] = d2f_drs_du;
  const double d2f_drs_dx = _t6*_t8;
  out[13] = d2f_drs_dx;
  const double d2f_drs2 = _t10*_t9;
  out[14] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = _hc1[10]*_t4;
  out[15] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[16] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[17] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[18] = d3f_du3;
  const double d3f_dx_dt2 = _hc1[14]*_t4;
  out[19] = d3f_dx_dt2;
  const double d3f_dx_du_dt = 0;
  out[20] = d3f_dx_du_dt;
  const double d3f_dx_du2 = 0;
  out[21] = d3f_dx_du2;
  const double d3f_dx2_dt = _hc1[17]*_t4;
  out[22] = d3f_dx2_dt;
  const double d3f_dx2_du = 0;
  out[23] = d3f_dx2_du;
  const double d3f_dx3 = _hc1[19]*_t4;
  out[24] = d3f_dx3;
  const double d3f_drs_dt2 = _hc1[4]*_t11;
  out[25] = d3f_drs_dt2;
  const double d3f_drs_du_dt = 0;
  out[26] = d3f_drs_du_dt;
  const double d3f_drs_du2 = 0;
  out[27] = d3f_drs_du2;
  const double d3f_drs_dx_dt = _hc1[7]*_t11;
  out[28] = d3f_drs_dx_dt;
  const double d3f_drs_dx_du = 0;
  out[29] = d3f_drs_dx_du;
  const double d3f_drs_dx2 = _hc1[9]*_t11;
  out[30] = d3f_drs_dx2;
  const double d3f_drs2_dt = _t12*_t7;
  out[31] = d3f_drs2_dt;
  const double d3f_drs2_du = 0;
  out[32] = d3f_drs2_du;
  const double d3f_drs2_dx = _t12*_t8;
  out[33] = d3f_drs2_dx;
  const double d3f_drs3 = _t13*_t9;
  out[34] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = _hc1[20]*_t4;
  out[35] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[36] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[37] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[38] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[39] = d4f_du4;
  const double d4f_dx_dt3 = _hc1[25]*_t4;
  out[40] = d4f_dx_dt3;
  const double d4f_dx_du_dt2 = 0;
  out[41] = d4f_dx_du_dt2;
  const double d4f_dx_du2_dt = 0;
  out[42] = d4f_dx_du2_dt;
  const double d4f_dx_du3 = 0;
  out[43] = d4f_dx_du3;
  const double d4f_dx2_dt2 = _hc1[29]*_t4;
  out[44] = d4f_dx2_dt2;
  const double d4f_dx2_du_dt = 0;
  out[45] = d4f_dx2_du_dt;
  const double d4f_dx2_du2 = 0;
  out[46] = d4f_dx2_du2;
  const double d4f_dx3_dt = _hc1[32]*_t4;
  out[47] = d4f_dx3_dt;
  const double d4f_dx3_du = 0;
  out[48] = d4f_dx3_du;
  const double d4f_dx4 = _hc1[34]*_t4;
  out[49] = d4f_dx4;
  const double d4f_drs_dt3 = _hc1[10]*_t11;
  out[50] = d4f_drs_dt3;
  const double d4f_drs_du_dt2 = 0;
  out[51] = d4f_drs_du_dt2;
  const double d4f_drs_du2_dt = 0;
  out[52] = d4f_drs_du2_dt;
  const double d4f_drs_du3 = 0;
  out[53] = d4f_drs_du3;
  const double d4f_drs_dx_dt2 = _hc1[14]*_t11;
  out[54] = d4f_drs_dx_dt2;
  const double d4f_drs_dx_du_dt = 0;
  out[55] = d4f_drs_dx_du_dt;
  const double d4f_drs_dx_du2 = 0;
  out[56] = d4f_drs_dx_du2;
  const double d4f_drs_dx2_dt = _hc1[17]*_t11;
  out[57] = d4f_drs_dx2_dt;
  const double d4f_drs_dx2_du = 0;
  out[58] = d4f_drs_dx2_du;
  const double d4f_drs_dx3 = _hc1[19]*_t11;
  out[59] = d4f_drs_dx3;
  const double d4f_drs2_dt2 = _hc1[4]*_t14;
  out[60] = d4f_drs2_dt2;
  const double d4f_drs2_du_dt = 0;
  out[61] = d4f_drs2_du_dt;
  const double d4f_drs2_du2 = 0;
  out[62] = d4f_drs2_du2;
  const double d4f_drs2_dx_dt = _hc1[7]*_t14;
  out[63] = d4f_drs2_dx_dt;
  const double d4f_drs2_dx_du = 0;
  out[64] = d4f_drs2_dx_du;
  const double d4f_drs2_dx2 = _hc1[9]*_t14;
  out[65] = d4f_drs2_dx2;
  const double d4f_drs3_dt = _t15*_t7;
  out[66] = d4f_drs3_dt;
  const double d4f_drs3_du = 0;
  out[67] = d4f_drs3_du;
  const double d4f_drs3_dx = _t15*_t8;
  out[68] = d4f_drs3_dx;
  const double d4f_drs4 = (0.1e1 / 0.108e3)*_hc0[4]*_t1*_t5*((p->cam_omega) * (p->cam_omega) * (p->cam_omega) * (p->cam_omega))/(M_PI * M_CBRTPI);
  out[69] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_wr2scan_params *params = (const mgga_x_wr2scan_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double ta = tau[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = _t4/xc_powr(na, 1, 3);
  const double _t6 = xc_powr(na, -4, 3);
  const double _t7 = M_CBRT2;
  const double _t8 = xc_powr(gaa, 1, 2);
  const double _t9 = _t7*_t8;
  const double _t10 = xc_powr(0.2e1, 2, 3);
  const double _t11 = _t10/xc_powr(na, 5, 3);
  const double _t12 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(lda_x_spin_z0_k, _KMAX)(p, _t5, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1] = {0.};
  if(!(_t12)) XC_CAT(wr2scan_f_z0_k, _KMAX)(p, _t5, _t6*_t9, 0, _t11*ta, _hc1);
  const double _t13 = 0.2e1*my_piecewise3(_t12, 0, _hc0[0]*_hc1[0]);
  const double zk = _t13;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t14 = (0.1e1 / 0.6e1)*_t6;
  const double _t15 = _t14*_t3;
  const double _t18 = xc_powr(na, -8, 3);
  const double _t19 = (0.5e1 / 0.3e1)*_t18;
  const double _t22 = xc_powr(na, -7, 3);
  const double _t23 = (0.4e1 / 0.3e1)*_t22;
  const double _t27 = 0.2e1*na;
  const double _t28 = (0.1e1 / _t8);
  const double _t29 = _t28*_t7;
  const double _t16 = _hc0[1]*_hc1[0];
  const double _t17 = _hc1[1]*_t10;
  const double _t20 = _t17*_t19;
  const double _t21 = _hc1[3]*_t9;
  const double _t24 = _hc1[4]*_t3;
  const double _t25 = -_t14*_t24 - _t20*ta - _t21*_t23;
  const double _t26 = my_piecewise3(_t12, 0, _hc0[0]*_t25 - _t15*_t16);
  const double _t30 = _hc1[3]*_t29;
  const double _t31 = _hc0[0]*_t6;
  const double _t32 = 0.2e1*my_piecewise3(_t12, 0, (0.1e1 / 0.2e1)*_t30*_t31);
  const double _t33 = 0.2e1*my_piecewise3(_t12, 0, _hc0[0]*_hc1[1]*_t11);
  const double dF_dna = _t13 + _t26*_t27;
  const double dF_dgaa = _t32*na;
  const double dF_dta = _t33*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double _t34 = (0.2e1 / 0.9e1)*_t22;
  const double _t35 = _t3*_t34;
  const double _t37 = xc_powr(0.6e1, 2, 3);
  const double _t38 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t45 = xc_powr(na, -11, 3);
  const double _t46 = (0.40e2 / 0.9e1)*_t45;
  const double _t48 = xc_powr(na, -10, 3);
  const double _t49 = (0.28e2 / 0.9e1)*_t48;
  const double _t50 = _t10*_t19;
  const double _t52 = _t23*_t9;
  const double _t61 = xc_powr(0.12e2, 1, 3);
  const double _t62 = _t2*_t61;
  const double _t63 = _t28*_t62;
  const double _t64 = (0.1e1 / 0.12e2)*_t18;
  const double _t65 = _t63*_t64;
  const double _t68 = (0.2e1 / 0.3e1)*_t45;
  const double _t71 = (0.1e1 / (na * na * na * na));
  const double _t72 = (0.5e1 / 0.3e1)*_t71;
  const double _t73 = (0.2e1 / 0.3e1)*_t22;
  const double _t77 = M_CBRT3;
  const double _t78 = _t2*_t77;
  const double _t79 = (0.1e1 / (na * na * na));
  const double _t80 = (0.1e1 / 0.3e1)*_t79;
  const double _t81 = _t78*_t80;
  const double _t84 = (0.8e1 / 0.3e1)*_t71;
  const double _t85 = xc_powr(na, -13, 3);
  const double _t86 = (0.10e2 / 0.3e1)*_t85;
  const double _t92 = xc_powr(gaa, -3, 2);
  const double _t95 = (0.1e1 / gaa);
  const double _t36 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t39 = _hc0[2]*_t38;
  const double _t40 = _t37*_t39;
  const double _t41 = _t18*_t40;
  const double _t42 = _t25*_t3;
  const double _t43 = _hc0[1]*_t6;
  const double _t44 = (0.1e1 / 0.3e1)*_t43;
  const double _t47 = _t17*_t46;
  const double _t51 = _hc1[5]*_t50;
  const double _t53 = -_hc1[11]*_t15 - _hc1[8]*_t52 - _t51*ta;
  const double _t54 = _t50*_t53;
  const double _t55 = _hc1[8]*_t50;
  const double _t56 = -_hc1[10]*_t52 - _hc1[13]*_t15 - _t55*ta;
  const double _t57 = _hc1[11]*_t50;
  const double _t58 = -_hc1[13]*_t52 - _hc1[14]*_t15 - _t57*ta;
  const double _t59 = -_t15*_t58 + _t21*_t49 + _t24*_t34 + _t47*ta - _t52*_t56 - _t54*ta;
  const double _t60 = my_piecewise3(_t12, 0, _hc0[0]*_t59 + _t16*_t35 + _t36*_t41 - _t42*_t44);
  const double _t66 = _hc0[1]*_hc1[3];
  const double _t67 = _hc1[10]*_t10;
  const double _t69 = _hc1[8]*_t28;
  const double _t70 = _t69*ta;
  const double _t74 = _hc1[13]*_t63;
  const double _t75 = -_t30*_t73 - _t64*_t74 - _t67*_t68 - _t70*_t72;
  const double _t76 = my_piecewise3(_t12, 0, _hc0[0]*_t75 - _t65*_t66);
  const double _t82 = _hc0[1]*_hc1[1];
  const double _t83 = _hc1[8]*_t8;
  const double _t87 = _hc1[5]*_t7;
  const double _t88 = _t87*ta;
  const double _t89 = _hc1[11]*_t78;
  const double _t90 = -_t20 - _t80*_t89 - _t83*_t84 - _t86*_t88;
  const double _t91 = my_piecewise3(_t12, 0, _hc0[0]*_t90 - _t81*_t82);
  const double _t93 = _hc1[3]*_t92;
  const double _t94 = _t7*_t93;
  const double _t96 = _t67*_t95;
  const double _t97 = _hc0[0]*_t18;
  const double _t98 = 0.2e1*my_piecewise3(_t12, 0, -0.1e1 / 0.4e1*_t31*_t94 + (0.1e1 / 0.4e1)*_t96*_t97);
  const double _t99 = _hc0[0]*_t79;
  const double _t100 = 0.2e1*my_piecewise3(_t12, 0, _t69*_t99);
  const double _t101 = 0.2e1*_hc0[0];
  const double _t102 = 0.2e1*my_piecewise3(_t12, 0, _t101*_t48*_t87);
  const double d2F_dna2 = 0.4e1*_t26 + _t27*_t60;
  const double d2F_dna_dgaa = _t27*_t76 + _t32;
  const double d2F_dna_dta = _t27*_t91 + _t33;
  const double d2F_dgaa2 = _t98*na;
  const double d2F_dgaa_dta = _t100*na;
  const double d2F_dta2 = _t102*na;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double _t105 = (0.14e2 / 0.27e2)*_t48;
  const double _t106 = _t105*_t3;
  const double _t107 = (0.1e1 / 0.9e1)*_t45;
  const double _t110 = xc_powr(na, -14, 3);
  const double _t111 = (0.440e3 / 0.27e2)*_t110;
  const double _t113 = (0.280e3 / 0.27e2)*_t85;
  const double _t114 = _t10*_t46;
  const double _t116 = _t49*_t9;
  const double _t140 = _t107*_t63;
  const double _t144 = (0.14e2 / 0.9e1)*_t110;
  const double _t145 = xc_powi(na, -5);
  const double _t146 = (0.40e2 / 0.9e1)*ta;
  const double _t147 = (0.14e2 / 0.9e1)*_t48;
  const double _t148 = _t29*_t73;
  const double _t149 = _t10*_t68;
  const double _t151 = _t28*_t72;
  const double _t155 = _t151*ta;
  const double _t161 = (0.4e1 / 0.9e1)*_t71;
  const double _t162 = _t161*_t78;
  const double _t163 = (0.56e2 / 0.9e1)*_t145;
  const double _t164 = xc_powr(na, -16, 3);
  const double _t166 = _t8*_t84;
  const double _t168 = _t7*_t86;
  const double _t170 = _t50*ta;
  const double _t176 = _t18*_t62;
  const double _t178 = _t78*_t95;
  const double _t179 = (0.1e1 / 0.12e2)*_t71;
  const double _t180 = _t178*_t179;
  const double _t183 = (0.2e1 / 0.3e1)*_t145;
  const double _t184 = (0.1e1 / 0.3e1)*_t45;
  const double _t185 = (0.5e1 / 0.6e1)*ta;
  const double _t191 = _t3*_t85;
  const double _t192 = (0.1e1 / 0.6e1)*_t191;
  const double _t193 = (0.4e1 / 0.3e1)*_t164;
  const double _t194 = 0.3e1*_t71;
  const double _t195 = xc_powr(na, -17, 3);
  const double _t196 = _t10*_t195;
  const double _t197 = (0.5e1 / 0.3e1)*_t28;
  const double _t200 = (0.1e1 / 0.3e1)*_t10*_t110;
  const double _t201 = _t200*_t78;
  const double _t203 = xc_powi(na, -6);
  const double _t205 = (0.20e2 / 0.3e1)*ta;
  const double _t206 = (0.20e2 / 0.3e1)*_t85;
  const double _t209 = (0.8e1 / 0.3e1)*_t195;
  const double _t213 = _t71*_t92;
  const double _t215 = xc_powr(gaa, -5, 2);
  const double _t218 = (0.1e1 / (gaa * gaa));
  const double _t103 = _hc0[3]/M_PI;
  const double _t104 = _t103*_t71;
  const double _t108 = _hc1[0]*_t40;
  const double _t109 = _t4*_t43;
  const double _t112 = _t111*_t17;
  const double _t115 = _hc1[5]*_t114;
  const double _t117 = _hc1[15]*_t50;
  const double _t118 = -_hc1[19]*_t52 - _hc1[25]*_t15 - _t117*ta;
  const double _t119 = _t118*_t50;
  const double _t120 = _hc1[19]*_t50;
  const double _t121 = -_hc1[22]*_t52 - _hc1[28]*_t15 - _t120*ta;
  const double _t122 = _hc1[25]*_t50;
  const double _t123 = -_hc1[28]*_t52 - _hc1[31]*_t15 - _t122*ta;
  const double _t124 = _hc1[11]*_t35 + _hc1[8]*_t116 + _t115*ta - _t119*ta - _t121*_t52 - _t123*_t15;
  const double _t125 = _t124*_t50;
  const double _t126 = _hc1[8]*_t114;
  const double _t127 = _t121*_t50;
  const double _t128 = _hc1[22]*_t50;
  const double _t129 = -_hc1[24]*_t52 - _hc1[30]*_t15 - _t128*ta;
  const double _t130 = _hc1[28]*_t50;
  const double _t131 = -_hc1[30]*_t52 - _hc1[33]*_t15 - _t130*ta;
  const double _t132 = _hc1[10]*_t116 + _hc1[13]*_t35 + _t126*ta - _t127*ta - _t129*_t52 - _t131*_t15;
  const double _t133 = _hc1[11]*_t114;
  const double _t134 = _t123*_t50;
  const double _t135 = _hc1[31]*_t50;
  const double _t136 = -_hc1[33]*_t52 - _hc1[34]*_t15 - _t135*ta;
  const double _t137 = _hc1[13]*_t116 + _hc1[14]*_t35 - _t131*_t52 + _t133*ta - _t134*ta - _t136*_t15;
  const double _t138 = (0.4e1 / 0.9e1)*_t1*_t2*_t22*_t58 + (0.80e2 / 0.9e1)*_t10*_t45*_t53*ta - _t105*_t24 - _t112*ta - _t113*_t21 - _t125*ta - _t132*_t52 - _t137*_t15 + (0.56e2 / 0.9e1)*_t48*_t56*_t7*_t8;
  const double _t139 = my_piecewise3(_t12, 0, _hc0[0]*_t138 + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t22*_t25 + (0.1e1 / 0.12e2)*_hc0[2]*_t18*_t25*_t37*_t38 - _t104*_t36 - _t106*_t16 - _t107*_t108 - _t109*_t59);
  const double _t141 = xc_powr(0.3e1, 2, 3)*_t39;
  const double _t142 = _hc1[3]*_t141;
  const double _t143 = _t3*_t44;
  const double _t150 = _hc1[19]*ta;
  const double _t152 = _t69*_t7;
  const double _t153 = -_hc1[22]*_t149 - _hc1[28]*_t65 - _t150*_t151 - _t152*_t73;
  const double _t154 = _t153*_t50;
  const double _t156 = -_hc1[10]*_t148 - _hc1[22]*_t155 - _hc1[24]*_t149 - _hc1[30]*_t65;
  const double _t157 = -_hc1[13]*_t148 - _hc1[28]*_t155 - _hc1[30]*_t149 - _hc1[33]*_t65;
  const double _t158 = _t107*_t74 + _t144*_t67 + _t145*_t146*_t69 + _t147*_t30 - _t148*_t56 - _t15*_t157 - _t154*ta - _t156*_t52;
  const double _t159 = my_piecewise3(_t12, 0, _hc0[0]*_t158 + _t140*_t66 + (0.1e1 / 0.36e2)*_t142*_t28*_t71 - _t143*_t75);
  const double _t160 = xc_powr(0.18e2, 1, 3)*_hc1[1]*_t39;
  const double _t165 = _t164*_t87;
  const double _t167 = _hc1[15]*ta;
  const double _t169 = -_hc1[19]*_t166 - _hc1[25]*_t81 - _t167*_t168 - _t51;
  const double _t171 = -_hc1[22]*_t166 - _hc1[28]*_t81 - _t150*_t168 - _t55;
  const double _t172 = _hc1[25]*ta;
  const double _t173 = -_hc1[28]*_t166 - _hc1[31]*_t81 - _t168*_t172 - _t57;
  const double _t174 = -_t15*_t173 + _t161*_t89 + _t163*_t83 + (0.80e2 / 0.9e1)*_t165*ta - _t169*_t170 - _t171*_t52 + _t47 - _t54;
  const double _t175 = my_piecewise3(_t12, 0, _hc0[0]*_t174 - _t143*_t90 + (0.1e1 / 0.18e2)*_t160*_t85 + _t162*_t82);
  const double _t177 = _hc0[1]*_t93;
  const double _t181 = _hc0[1]*_hc1[10];
  const double _t182 = _hc1[24]*_t28;
  const double _t186 = _hc1[22]*_t7;
  const double _t187 = _t186*_t95;
  const double _t188 = _t164*_t187;
  const double _t189 = (0.1e1 / 0.24e2)*_hc1[13]*_t18*_t2*_t61*_t92 + (0.1e1 / 0.3e1)*_hc1[3]*_t22*_t7*_t92 - _hc1[30]*_t178*_t179 + (0.5e1 / 0.6e1)*_hc1[8]*_t71*_t92*ta - _t182*_t183 - _t184*_t96 - _t185*_t188;
  const double _t190 = my_piecewise3(_t12, 0, _hc0[0]*_t189 + (0.1e1 / 0.24e2)*_t176*_t177 - _t180*_t181);
  const double _t198 = -_hc1[28]*_t192*_t28 - _t150*_t196*_t197 - _t186*_t193 - _t194*_t69;
  const double _t199 = my_piecewise3(_t12, 0, _hc0[0]*_t198 - _hc0[1]*_t192*_t69);
  const double _t202 = _hc0[1]*_hc1[5];
  const double _t204 = _hc1[15]*_t203;
  const double _t207 = _hc1[19]*_t10;
  const double _t208 = _t207*_t8;
  const double _t210 = _hc1[25]*_t78;
  const double _t211 = -_t200*_t210 - _t204*_t205 - _t206*_t87 - _t208*_t209;
  const double _t212 = my_piecewise3(_t12, 0, _hc0[0]*_t211 - _t201*_t202);
  const double _t214 = _hc0[0]*_hc1[24];
  const double _t216 = _hc1[3]*_t7;
  const double _t217 = _t215*_t216;
  const double _t219 = 0.2e1*my_piecewise3(_t12, 0, (0.1e1 / 0.4e1)*_t213*_t214 + (0.3e1 / 0.8e1)*_t217*_t31 - 0.3e1 / 0.8e1*_t218*_t67*_t97);
  const double _t220 = _hc1[8]*_t92;
  const double _t221 = _hc0[0]*_t85;
  const double _t222 = 0.2e1*my_piecewise3(_t12, 0, (0.1e1 / 0.2e1)*_t187*_t221 - 0.1e1 / 0.2e1*_t220*_t99);
  const double _t223 = _t207*_t28;
  const double _t224 = _hc0[0]*_t110;
  const double _t225 = 0.2e1*my_piecewise3(_t12, 0, _t223*_t224);
  const double _t226 = 0.4e1*_hc0[0];
  const double _t227 = 0.2e1*my_piecewise3(_t12, 0, _hc1[15]*_t145*_t226);
  const double d3F_dna3 = _t139*_t27 + 0.6e1*_t60;
  const double d3F_dna2_dgaa = _t159*_t27 + 0.4e1*_t76;
  const double d3F_dna2_dta = _t175*_t27 + 0.4e1*_t91;
  const double d3F_dna_dgaa2 = _t190*_t27 + _t98;
  const double d3F_dna_dgaa_dta = _t100 + _t199*_t27;
  const double d3F_dna_dta2 = _t102 + _t212*_t27;
  const double d3F_dgaa3 = _t219*na;
  const double d3F_dgaa2_dta = _t222*na;
  const double d3F_dgaa_dta2 = _t225*na;
  const double d3F_dta3 = _t227*na;
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
  const double _t228 = (0.140e3 / 0.81e2)*_t85;
  const double _t230 = (0.2e1 / 0.3e1)*_t3;
  const double _t232 = _t10*ta;
  const double _t233 = _t111*_t232;
  const double _t234 = _t113*_t9;
  const double _t242 = _t114*ta;
  const double _t246 = (0.7e1 / 0.27e2)*_t110;
  const double _t247 = _t145*_t28;
  const double _t249 = _t10*_t144;
  const double _t252 = _t146*_t247;
  const double _t253 = _t147*_t29;
  const double _t255 = (0.2e1 / 0.9e1)*_t164;
  const double _t256 = (0.28e2 / 0.27e2)*_t145;
  const double _t257 = xc_powr(na, -19, 3);
  const double _t258 = _t163*_t8;
  const double _t259 = _t164*_t7;
  const double _t260 = (0.80e2 / 0.9e1)*_t259;
  const double _t261 = _t168*ta;
  const double _t267 = (0.1e1 / 0.18e2)*_t45*_t62;
  const double _t268 = _t183*_t28;
  const double _t269 = _t10*_t95;
  const double _t270 = _t184*_t269;
  const double _t272 = _t185*_t259;
  const double _t273 = _t272*_t95;
  const double _t274 = xc_powr(na, -20, 3);
  const double _t275 = _t193*_t7;
  const double _t276 = _t194*_t28;
  const double _t277 = _t195*_t197*_t232;
  const double _t278 = _t192*_t28;
  const double _t279 = (0.4e1 / 0.9e1)*_t196;
  const double _t280 = xc_powi(na, -7);
  const double _t281 = _t203*_t205;
  const double _t282 = _t206*_t7;
  const double _t283 = _t10*_t209*_t8;
  const double _t284 = (0.1e1 / 0.16e2)*_t215;
  const double _t285 = (0.1e1 / 0.8e1)*_t218;
  const double _t286 = (0.1e1 / 0.24e2)*_t164*_t92;
  const double _t287 = _t215*_t71;
  const double _t289 = (0.1e1 / 0.12e2)*_t195*_t269*_t78;
  const double _t290 = _t10*_t274;
  const double _t291 = (0.1e1 / 0.3e1)*_t203*_t28*_t78;
  const double _t293 = _t230*_t257;
  const double _t229 = _hc0[1]*_t3;
  const double _t231 = _t17*_t195;
  const double _t235 = -_hc1[40]*_t170 - _hc1[44]*_t52 - _hc1[54]*_t15;
  const double _t236 = -_hc1[50]*_t170 - _hc1[54]*_t52 - _hc1[60]*_t15;
  const double _t237 = -_hc1[44]*_t170 - _hc1[47]*_t52 - _hc1[57]*_t15;
  const double _t238 = -_hc1[54]*_t170 - _hc1[57]*_t52 - _hc1[63]*_t15;
  const double _t239 = _hc1[22]*_t116 + _hc1[28]*_t35 + _t114*_t150 - _t15*_t238 - _t170*_t235 - _t237*_t52;
  const double _t240 = -_hc1[60]*_t170 - _hc1[63]*_t52 - _hc1[66]*_t15;
  const double _t241 = _hc1[28]*_t116 + _hc1[31]*_t35 + _t114*_t172 - _t15*_t240 - _t170*_t236 - _t238*_t52;
  const double _t243 = -_hc1[57]*_t170 - _hc1[59]*_t52 - _hc1[65]*_t15;
  const double _t244 = -_hc1[63]*_t170 - _hc1[65]*_t52 - _hc1[68]*_t15;
  const double _t245 = _hc1[28]*_t242 + _hc1[30]*_t116 + _hc1[33]*_t35 - _t15*_t244 - _t170*_t238 - _t243*_t52;
  const double _t248 = (0.1e1 / 0.9e1)*_t141;
  const double _t250 = -_hc1[44]*_t155 - _hc1[47]*_t149 - _hc1[57]*_t65 - _t186*_t28*_t73;
  const double _t251 = -_hc1[28]*_t148 - _hc1[54]*_t155 - _hc1[57]*_t149 - _hc1[63]*_t65;
  const double _t254 = -_hc1[30]*_t148 - _hc1[57]*_t155 - _hc1[59]*_t149 - _hc1[65]*_t65;
  const double _t262 = (0.8e1 / 0.3e1)*_hc1[44];
  const double _t263 = _t262*_t8;
  const double _t264 = -_hc1[40]*_t261 - _hc1[54]*_t81 - _t120 - _t263*_t71;
  const double _t265 = -_hc1[50]*_t261 - _hc1[54]*_t166 - _hc1[60]*_t81 - _t122;
  const double _t266 = -_hc1[54]*_t261 - _hc1[57]*_t166 - _hc1[63]*_t81 - _t130;
  const double _t271 = _hc1[44]*_t95;
  const double _t288 = _hc1[47]*_t92;
  const double _t292 = _hc1[40]/xc_powr(na, 22, 3);
  const double d4F_dna4 = 0.8e1*_t139 + _t27*my_piecewise3(_t12, 0, _hc0[0]*(-0.440e3 / 0.9e1*_t10*_t110*_t53*ta + (0.40e2 / 0.3e1)*_t124*_t232*_t45 + (0.28e2 / 0.3e1)*_t132*_t48*_t9 + _t137*_t3*_t73 - _t147*_t3*_t58 - _t15*(-_hc1[11]*_t233 - _hc1[13]*_t234 - _hc1[14]*_t106 + (0.4e1 / 0.9e1)*_t1*_t136*_t2*_t22 + (0.80e2 / 0.9e1)*_t10*_t123*_t45*ta + (0.56e2 / 0.9e1)*_t131*_t48*_t7*_t8 - _t15*(_hc1[31]*_t242 + _hc1[33]*_t116 + _hc1[34]*_t35 - _t15*(-_hc1[66]*_t170 - _hc1[68]*_t52 - _hc1[69]*_t15) - _t170*_t240 - _t244*_t52) - _t170*_t241 - _t245*_t52) + (0.3640e4 / 0.81e2)*_t164*_t21 - _t170*(-_hc1[11]*_t106 - _hc1[5]*_t233 - _hc1[8]*_t234 + (0.4e1 / 0.9e1)*_t1*_t123*_t2*_t22 + (0.80e2 / 0.9e1)*_t10*_t118*_t45*ta + (0.56e2 / 0.9e1)*_t121*_t48*_t7*_t8 - _t15*_t241 - _t170*(_hc1[19]*_t116 + _hc1[25]*_t35 + _t114*_t167 - _t15*_t236 - _t170*(-_hc1[35]*_t170 - _hc1[40]*_t52 - _hc1[50]*_t15) - _t235*_t52) - _t239*_t52) + _t228*_t24 + (0.6160e4 / 0.81e2)*_t231*ta - _t52*(-_hc1[10]*_t234 - _hc1[13]*_t106 - _hc1[8]*_t233 + (0.4e1 / 0.9e1)*_t1*_t131*_t2*_t22 + (0.80e2 / 0.9e1)*_t10*_t121*_t45*ta + (0.56e2 / 0.9e1)*_t129*_t48*_t7*_t8 - _t15*_t245 - _t170*_t239 - _t52*(_hc1[22]*_t242 + _hc1[24]*_t116 + _hc1[30]*_t35 - _t15*_t243 - _t170*_t237 - _t52*(-_hc1[47]*_t170 - _hc1[49]*_t52 - _hc1[59]*_t15))) - 0.280e3 / 0.9e1*_t56*_t85*_t9) - 0.56e2 / 0.27e2*_hc0[1]*_t42*_t48 + (0.1e1 / 0.216e3)*_hc0[4]*_hc1[0]*_t1*_t164/(M_PI * M_CBRTPI) + (0.2e1 / 0.9e1)*_hc1[0]*_t103*_t145 - 0.1e1 / 0.9e1*_t104*_t25 + (0.40e2 / 0.81e2)*_t108*_t110 - _t138*_t230*_t43 + _t16*_t228*_t3 + _t229*_t23*_t59 - 0.4e1 / 0.9e1*_t25*_t40*_t45 + (0.1e1 / 0.6e1)*_t41*_t59);
  const double d4F_dna3_dgaa = 0.6e1*_t159 + _t27*my_piecewise3(_t12, 0, _hc0[0]*((0.4e1 / 0.9e1)*_t1*_t157*_t2*_t22 + (0.80e2 / 0.9e1)*_t10*_t153*_t45*ta - _t132*_t148 - _t15*(_hc1[13]*_t253 + _hc1[28]*_t252 + _hc1[30]*_t249 + _hc1[33]*_t140 - _t131*_t148 - _t15*(-_hc1[33]*_t148 - _hc1[63]*_t155 - _hc1[65]*_t149 - _hc1[68]*_t65) - _t170*_t251 - _t254*_t52) + (0.56e2 / 0.9e1)*_t156*_t48*_t7*_t8 - _t170*(_hc1[22]*_t249 + _hc1[28]*_t140 - _t121*_t148 + _t147*_t152 - _t15*_t251 + (0.40e2 / 0.9e1)*_t150*_t247 - _t170*(-_hc1[19]*_t148 - _hc1[40]*_t155 - _hc1[44]*_t149 - _hc1[54]*_t65) - _t250*_t52) - 0.140e3 / 0.27e2*_t195*_t67 - 0.440e3 / 0.27e2*_t203*_t70 - _t246*_t74 + (0.28e2 / 0.9e1)*_t28*_t48*_t56*_t7 - 0.140e3 / 0.27e2*_t30*_t85 - _t52*(_hc1[10]*_t253 + _hc1[22]*_t252 + _hc1[24]*_t249 + _hc1[30]*_t140 - _t129*_t148 - _t15*_t254 - _t170*_t250 - _t52*(-_hc1[47]*_t155 - _hc1[49]*_t149 - _hc1[59]*_t65 - _t182*_t7*_t73))) + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t22*_t75 + (0.1e1 / 0.12e2)*_hc0[2]*_t18*_t37*_t38*_t75 - _hc1[3]*_t247*_t248 - 0.1e1 / 0.72e2*_t103*_t164*_t30 - _t109*_t158 - _t246*_t63*_t66);
  const double d4F_dna3_dta = 0.6e1*_t175 + _t27*my_piecewise3(_t12, 0, _hc0[0]*((0.4e1 / 0.9e1)*_t1*_t173*_t2*_t22 + (0.80e2 / 0.9e1)*_t10*_t169*_t45*ta + (0.80e2 / 0.9e1)*_t10*_t45*_t53 - _t112 - _t125 - _t15*(_hc1[28]*_t258 + _hc1[31]*_t162 + _t133 - _t134 - _t15*(-_hc1[60]*_t261 - _hc1[63]*_t166 - _hc1[66]*_t81 - _t135) - _t170*_t265 + _t172*_t260 - _t266*_t52) - _t170*(_hc1[19]*_t258 + _hc1[25]*_t162 + _t115 - _t119 - _t15*_t265 + _t167*_t260 - _t170*(-_hc1[35]*_t261 - _hc1[40]*_t166 - _hc1[50]*_t81 - _t117) - _t264*_t52) + (0.56e2 / 0.9e1)*_t171*_t48*_t7*_t8 - 0.560e3 / 0.27e2*_t203*_t83 - _t256*_t89 - 0.880e3 / 0.27e2*_t257*_t88 - _t52*(_hc1[22]*_t258 + _hc1[28]*_t162 + _t126 - _t127 - _t15*_t266 + _t150*_t260 - _t170*_t264 - _t52*(-_hc1[44]*_t261 - _hc1[47]*_t166 - _hc1[57]*_t81 - _t128))) + (0.2e1 / 0.3e1)*_hc0[1]*_t1*_t2*_t22*_t90 + (0.1e1 / 0.12e2)*_hc0[2]*_t18*_t37*_t38*_t90 - 0.1e1 / 0.36e2*_t103*_t231 - _t109*_t174 - _t160*_t255 - _t256*_t78*_t82);
  const double d4F_dna2_dgaa2 = 0.4e1*_t190 + _t27*my_piecewise3(_t12, 0, _hc0[0]*((0.7e1 / 0.9e1)*_hc1[10]*_t10*_t110*_t95 - _hc1[13]*_t267*_t92 + (0.20e2 / 0.9e1)*_hc1[22]*_t257*_t7*_t95*ta + (0.14e2 / 0.9e1)*_hc1[24]*_t203*_t28 + (0.1e1 / 0.9e1)*_hc1[30]*_t145*_t2*_t77*_t95 - 0.20e2 / 0.9e1*_t145*_t220*ta - _t15*((0.1e1 / 0.3e1)*_hc1[13]*_t22*_t7*_t92 + (0.5e1 / 0.6e1)*_hc1[28]*_t71*_t92*ta - _hc1[30]*_t270 + (0.1e1 / 0.24e2)*_hc1[33]*_t18*_t2*_t61*_t92 - _hc1[57]*_t273 - _hc1[59]*_t268 - _hc1[65]*_t180) - _t156*_t23*_t29 - _t170*((0.5e1 / 0.6e1)*_hc1[19]*_t71*_t92*ta - _hc1[22]*_t270 + (0.1e1 / 0.24e2)*_hc1[28]*_t18*_t2*_t61*_t92 - _hc1[47]*_t268 - _hc1[57]*_t180 + (0.1e1 / 0.3e1)*_hc1[8]*_t22*_t7*_t92 - _t271*_t272) + (0.1e1 / 0.3e1)*_t22*_t56*_t7*_t92 - 0.7e1 / 0.9e1*_t48*_t94 - _t52*((0.1e1 / 0.3e1)*_hc1[10]*_t22*_t7*_t92 + (0.5e1 / 0.6e1)*_hc1[22]*_t71*_t92*ta - _hc1[24]*_t270 + (0.1e1 / 0.24e2)*_hc1[30]*_t18*_t2*_t61*_t92 - _hc1[47]*_t273 - _hc1[49]*_t268 - _hc1[59]*_t180)) + (0.1e1 / 0.72e2)*_hc1[10]*_t141*_t259*_t95 - 0.1e1 / 0.72e2*_t142*_t213 - _t143*_t189 + (0.1e1 / 0.9e1)*_t145*_t178*_t181 - _t177*_t267);
  const double d4F_dna2_dgaa_dta = 0.4e1*_t199 + _t27*my_piecewise3(_t12, 0, _hc0[0]*((0.40e2 / 0.9e1)*_hc1[19]*_t10*_t274*_t28*ta + (0.28e2 / 0.9e1)*_hc1[22]*_t257*_t7 + (0.2e1 / 0.9e1)*_hc1[28]*_t1*_t164*_t2*_t28 + (0.68e2 / 0.9e1)*_hc1[8]*_t145*_t28 - _t148*_t171 - _t15*(-_hc1[28]*_t276 - _hc1[54]*_t277 - _hc1[57]*_t275 - _hc1[63]*_t278) - _t154 - _t170*(-_hc1[19]*_t276 - _hc1[40]*_t277 - _hc1[44]*_t275 - _hc1[54]*_t278) - _t52*(-_hc1[22]*_t276 - _hc1[44]*_t277 - _hc1[47]*_t275 - _hc1[57]*_t278)) - _t143*_t198 + (0.1e1 / 0.36e2)*_t195*_t40*_t69 + _t229*_t255*_t69);
  const double d4F_dna2_dta2 = 0.4e1*_t212 + _t27*my_piecewise3(_t12, 0, _hc0[0]*(-0.10e2 / 0.3e1*_t10*_t169*_t18 - _t15*(-_hc1[25]*_t282 - _hc1[50]*_t281 - _hc1[54]*_t283 - _hc1[60]*_t201) + (0.160e3 / 0.9e1)*_t165 + (0.160e3 / 0.9e1)*_t167*_t280 - _t170*(-_hc1[15]*_t282 - _hc1[35]*_t281 - _hc1[40]*_t283 - _hc1[50]*_t201) + (0.56e2 / 0.9e1)*_t208*_t274 + _t210*_t279 - _t52*(-_hc1[19]*_t282 - _hc1[40]*_t281 - _hc1[54]*_t201 - _t196*_t263)) + _hc1[5]*_t203*_t248 - _t143*_t211 + _t202*_t279*_t78);
  const double d4F_dna_dgaa3 = _t219 + _t27*my_piecewise3(_t12, 0, _hc0[0]*((0.1e1 / 0.2e1)*_hc1[10]*_t10*_t218*_t45 - _hc1[13]*_t176*_t284 + (0.5e1 / 0.4e1)*_hc1[22]*_t164*_t218*_t7*ta + (0.1e1 / 0.8e1)*_hc1[30]*_t2*_t218*_t71*_t77 - 0.1e1 / 0.3e1*_hc1[49]*_t257*_t7*_t95 - _hc1[59]*_t286*_t3 - 0.5e1 / 0.4e1*_hc1[8]*_t287*ta - 0.1e1 / 0.2e1*_t217*_t22 - 0.5e1 / 0.12e2*_t232*_t274*_t288) - _hc1[24]*_t229*_t286 - _t176*_t284*_t66 + _t181*_t285*_t71*_t78);
  const double d4F_dna_dgaa2_dta = _t222 + _t27*my_piecewise3(_t12, 0, _hc0[0]*((0.5e1 / 0.6e1)*_hc1[19]*_t10*_t195*_t92*ta + (0.1e1 / 0.12e2)*_hc1[28]*_t1*_t2*_t85*_t92 - 0.2e1 / 0.3e1*_hc1[47]*_t28*_t290 - _hc1[57]*_t289 + (0.3e1 / 0.2e1)*_hc1[8]*_t71*_t92 - 0.3e1 / 0.2e1*_t188 - 0.5e1 / 0.3e1*_t271*_t280*ta) - _hc0[1]*_hc1[22]*_t289 + (0.1e1 / 0.12e2)*_hc0[1]*_t191*_t220);
  const double d4F_dna_dgaa_dta2 = _t225 + _t27*my_piecewise3(_t12, 0, _hc0[0]*(-_hc1[54]*_t291 - 0.14e2 / 0.3e1*_t195*_t223 - _t262*_t280 - 0.10e2 / 0.3e1*_t29*_t292*ta) - _hc0[1]*_hc1[19]*_t291);
  const double d4F_dna_dta3 = _t227 + _t27*my_piecewise3(_t12, 0, _hc0[0]*(-_hc1[35]*_t10*_t205/xc_powr(na, 23, 3) - _hc1[50]*_t293 - 0.20e2*_t204 - 0.16e2 / 0.3e1*_t292*_t9) - _hc0[1]*_hc1[15]*_t293);
  const double d4F_dgaa4 = _t27*my_piecewise3(_t12, 0, _hc0[0]*_hc1[49]*_t259*_t285 - 0.3e1 / 0.4e1*_t214*_t287 - 0.15e2 / 0.16e2*_t216*_t31/xc_powr(gaa, 7, 2) + (0.15e2 / 0.16e2)*_t67*_t97/(gaa * gaa * gaa));
  const double d4F_dgaa3_dta = _t27*my_piecewise3(_t12, 0, (0.1e1 / 0.4e1)*_hc0[0]*_t196*_t288 + (0.3e1 / 0.4e1)*_hc1[8]*_t215*_t99 - 0.3e1 / 0.4e1*_t186*_t218*_t221);
  const double d4F_dgaa2_dta2 = _t27*my_piecewise3(_t12, 0, _hc0[0]*_hc1[44]*_t203*_t95 - 0.1e1 / 0.2e1*_t207*_t224*_t92);
  const double d4F_dgaa_dta3 = _t27*my_piecewise3(_t12, 0, _hc1[40]*_t101*_t257*_t29);
  const double d4F_dta4 = _t27*my_piecewise3(_t12, 0, _hc1[35]*_t226*_t290);
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
  if(!(_t16)) XC_CAT(wr2scan_f_k, _KMAX)(p, _t9, _hc0[0], _t10*_t11, 0, _t12*ta, _hc2);
  double _hc3[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t5, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t17)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t9, _hc3[0], _hc4);
  double _hc5[(_KMAX) >= 4 ? 126 : (_KMAX) >= 3 ? 56 : (_KMAX) >= 2 ? 21 : (_KMAX) >= 1 ? 6 : 1] = {0.};
  if(!(_t17)) XC_CAT(wr2scan_f_k, _KMAX)(p, _t9, _hc3[0], _t13*_t14, 0, _t15*tb, _hc5);
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
  const double _t33 = -_t26;
  const double _t36 = xc_powr(na, -8, 3);
  const double _t37 = (0.5e1 / 0.3e1)*_t36;
  const double _t39 = xc_powr(na, -7, 3);
  const double _t40 = _t10*_t39;
  const double _t41 = (0.4e1 / 0.3e1)*_t40;
  const double _t46 = _t25 + _t4;
  const double _t47 = -_t46;
  const double _t54 = xc_powr(nb, -8, 3);
  const double _t55 = (0.5e1 / 0.3e1)*_t54;
  const double _t58 = xc_powr(nb, -7, 3);
  const double _t59 = (0.4e1 / 0.3e1)*_t58;
  const double _t64 = (0.1e1 / _t10);
  const double _t69 = (0.1e1 / _t13);
  const double _t22 = _hc5[5]*_t21;
  const double _t27 = _hc3[1]*_t26;
  const double _t28 = _hc5[4]*_t27 - _t22;
  const double _t29 = -_hc4[2]*_t21;
  const double _t30 = _hc4[1]*_t27 + _t29;
  const double _t31 = my_piecewise3(_t17, 0, _hc4[0]*_t28 + _hc5[0]*_t30);
  const double _t32 = -_hc1[2]*_t21;
  const double _t34 = _hc0[1]*_t33;
  const double _t35 = _hc1[1]*_t34 + _t32;
  const double _t38 = _hc2[1]*_t37;
  const double _t42 = _hc2[5]*_t21;
  const double _t43 = _hc0[1]*_hc2[4]*_t33 - _hc2[3]*_t41 - _t38*ta - _t42;
  const double _t44 = my_piecewise3(_t16, 0, _hc1[0]*_t43 + _hc2[0]*_t35);
  const double _t45 = _t31 + _t44;
  const double _t48 = _hc0[1]*_t47;
  const double _t49 = _hc2[4]*_t48 - _t42;
  const double _t50 = _hc1[1]*_t48 + _t32;
  const double _t51 = my_piecewise3(_t16, 0, _hc1[0]*_t49 + _hc2[0]*_t50);
  const double _t52 = _hc3[1]*_t46;
  const double _t53 = _hc4[1]*_t52 + _t29;
  const double _t56 = _hc5[1]*_t55;
  const double _t57 = _hc5[3]*_t13;
  const double _t60 = _hc3[1]*_hc5[4]*_t46 - _t22 - _t56*tb - _t57*_t59;
  const double _t61 = my_piecewise3(_t17, 0, _hc4[0]*_t60 + _hc5[0]*_t53);
  const double _t62 = _t51 + _t61;
  const double _t63 = _hc1[0]*_t11;
  const double _t65 = _hc2[3]*_t64;
  const double _t66 = (0.1e1 / 0.2e1)*_t65;
  const double _t67 = my_piecewise3(_t16, 0, _t63*_t66);
  const double _t68 = _hc4[0]*_t14;
  const double _t70 = _hc5[3]*_t69;
  const double _t71 = (0.1e1 / 0.2e1)*_t70;
  const double _t72 = my_piecewise3(_t17, 0, _t68*_t71);
  const double _t73 = _hc2[1]*_t12;
  const double _t74 = my_piecewise3(_t16, 0, _hc1[0]*_t73);
  const double _t75 = _hc5[1]*_t15;
  const double _t76 = my_piecewise3(_t17, 0, _hc4[0]*_t75);
  const double dF_dna = _t18 + _t3*_t45;
  const double dF_dnb = _t18 + _t3*_t62;
  const double dF_dgaa = _t3*_t67;
  const double dF_dgbb = _t3*_t72;
  const double dF_dta = _t3*_t74;
  const double dF_dtb = _t3*_t76;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double _t78 = xc_powr(_t3, -7, 3);
  const double _t79 = (0.2e1 / 0.9e1)*_t78;
  const double _t80 = _t79*_t8;
  const double _t82 = 0.2e1*_t24;
  const double _t83 = (0.1e1 / (_t3 * _t3 * _t3));
  const double _t84 = 0.2e1*_t83;
  const double _t85 = _t2*_t84;
  const double _t86 = -_t82 + _t85;
  const double _t87 = -_t86;
  const double _t89 = (_t26 * _t26);
  const double _t106 = (_t33 * _t33);
  const double _t113 = xc_powr(na, -11, 3);
  const double _t114 = (0.40e2 / 0.9e1)*_t113;
  const double _t117 = xc_powr(na, -10, 3);
  const double _t118 = (0.28e2 / 0.9e1)*_t117;
  const double _t146 = _t13*_t59;
  const double _t173 = _t82 + _t85;
  const double _t175 = (_t47 * _t47);
  const double _t181 = -_t173;
  const double _t183 = (_t46 * _t46);
  const double _t192 = xc_powr(nb, -10, 3);
  const double _t193 = (0.28e2 / 0.9e1)*_t192;
  const double _t194 = xc_powr(nb, -11, 3);
  const double _t195 = (0.40e2 / 0.9e1)*_t194;
  const double _t201 = (0.2e1 / 0.3e1)*_t113;
  const double _t202 = (0.2e1 / 0.3e1)*_t39;
  const double _t205 = (0.1e1 / (na * na * na * na));
  const double _t206 = (0.5e1 / 0.6e1)*_t205;
  const double _t207 = (0.1e1 / 0.12e2)*_t20;
  const double _t208 = _t11*_t64;
  const double _t214 = _t14*_t69;
  const double _t215 = _t207*_t214;
  const double _t221 = (0.1e1 / 0.2e1)*_t208;
  const double _t224 = (0.2e1 / 0.3e1)*_t194;
  const double _t225 = (0.2e1 / 0.3e1)*_t58;
  const double _t228 = (0.1e1 / (nb * nb * nb * nb));
  const double _t229 = (0.5e1 / 0.6e1)*_t228;
  const double _t232 = xc_powr(na, -13, 3);
  const double _t233 = (0.5e1 / 0.3e1)*ta;
  const double _t234 = _t232*_t233;
  const double _t236 = (0.4e1 / 0.3e1)*_t205;
  const double _t246 = xc_powr(nb, -13, 3);
  const double _t247 = (0.5e1 / 0.3e1)*tb;
  const double _t248 = _t246*_t247;
  const double _t250 = (0.4e1 / 0.3e1)*_t228;
  const double _t254 = (0.1e1 / gaa);
  const double _t256 = xc_powr(gaa, -3, 2);
  const double _t261 = (0.1e1 / gbb);
  const double _t263 = xc_powr(gbb, -3, 2);
  const double _t267 = (0.1e1 / (na * na * na));
  const double _t271 = (0.1e1 / (nb * nb * nb));
  const double _t77 = 0.2e1*_t30;
  const double _t81 = _hc5[5]*_t80;
  const double _t88 = _hc3[1]*_t87;
  const double _t90 = _hc3[2]*_t89;
  const double _t91 = _hc5[20]*_t21;
  const double _t92 = _hc5[19]*_t27 - _t91;
  const double _t93 = _hc5[19]*_t21;
  const double _t94 = _hc5[15]*_t27 - _t93;
  const double _t95 = _hc5[4]*_t88 + _hc5[4]*_t90 - _t21*_t92 + _t27*_t94 + _t81;
  const double _t96 = _hc4[2]*_t80;
  const double _t97 = -_hc4[5]*_t21;
  const double _t98 = _hc4[4]*_t27 + _t97;
  const double _t99 = -_hc4[4]*_t21;
  const double _t100 = _hc4[3]*_t27 + _t99;
  const double _t101 = _hc4[1]*_t88 + _hc4[1]*_t90 + _t100*_t27 - _t21*_t98 + _t96;
  const double _t102 = my_piecewise3(_t17, 0, _hc4[0]*_t95 + _hc5[0]*_t101 + _t28*_t77);
  const double _t103 = 0.2e1*_t35;
  const double _t104 = _hc1[2]*_t80;
  const double _t105 = _hc0[1]*_t86;
  const double _t107 = _hc0[2]*_t106;
  const double _t108 = -_hc1[5]*_t21;
  const double _t109 = _hc1[4]*_t34 + _t108;
  const double _t110 = -_hc1[4]*_t21;
  const double _t111 = _hc1[3]*_t34 + _t110;
  const double _t112 = _hc1[1]*_t105 + _hc1[1]*_t107 + _t104 - _t109*_t21 + _t111*_t34;
  const double _t115 = _hc2[1]*_t114;
  const double _t116 = _hc2[3]*_t10;
  const double _t119 = _hc2[5]*_t8;
  const double _t120 = _t119*_t79;
  const double _t121 = _hc2[6]*_t37;
  const double _t122 = _hc2[16]*_t21;
  const double _t123 = _hc0[1]*_hc2[12]*_t33 - _hc2[9]*_t41 - _t121*ta - _t122;
  const double _t124 = _t123*_t37;
  const double _t125 = _hc2[9]*_t37;
  const double _t126 = _hc2[18]*_t21;
  const double _t127 = _hc0[1]*_hc2[14]*_t33 - _hc2[11]*_t41 - _t125*ta - _t126;
  const double _t128 = _hc2[16]*_t37;
  const double _t129 = _hc2[20]*_t21;
  const double _t130 = _hc0[1]*_hc2[19]*_t33 - _hc2[18]*_t41 - _t128*ta - _t129;
  const double _t131 = _hc2[12]*_t37;
  const double _t132 = _hc2[19]*_t21;
  const double _t133 = _hc2[14]*_t41 + _t131*ta + _t132;
  const double _t134 = _hc0[1]*_hc2[15]*_t33 - _t133;
  const double _t135 = _hc2[4]*_t105 + _hc2[4]*_t107 + _t115*ta + _t116*_t118 + _t120 - _t124*ta - _t127*_t41 - _t130*_t21 + _t134*_t34;
  const double _t136 = my_piecewise3(_t16, 0, _hc1[0]*_t135 + _hc2[0]*_t112 + _t103*_t43);
  const double _t137 = _t102 + _t136;
  const double _t138 = _hc4[3]*_t52 + _t99;
  const double _t139 = _hc3[2]*_t26;
  const double _t140 = _hc4[1]*_t139;
  const double _t141 = _hc3[1]*_t85;
  const double _t142 = _hc4[4]*_t52 + _t97;
  const double _t143 = -_t142*_t21 + _t96;
  const double _t144 = -_hc4[1]*_t141 + _t138*_t27 + _t140*_t46 + _t143;
  const double _t145 = _hc5[12]*_t55;
  const double _t147 = _hc3[1]*_hc5[15]*_t46 - _hc5[14]*_t146 - _t145*tb - _t93;
  const double _t148 = _hc5[4]*_t46;
  const double _t149 = _hc5[16]*_t55;
  const double _t150 = _hc3[1]*_hc5[19]*_t46 - _hc5[18]*_t146 - _t149*tb - _t91;
  const double _t151 = -_t150*_t21 + _t81;
  const double _t152 = -_hc5[4]*_t141 + _t139*_t148 + _t147*_t27 + _t151;
  const double _t153 = my_piecewise3(_t17, 0, _hc4[0]*_t152 + _hc5[0]*_t144 + _t28*_t53 + _t30*_t60);
  const double _t154 = _hc1[3]*_t48 + _t110;
  const double _t155 = _hc0[2]*_t33;
  const double _t156 = _t155*_t47;
  const double _t157 = _hc0[1]*_t85;
  const double _t158 = _hc1[4]*_t48 + _t108;
  const double _t159 = _t104 - _t158*_t21;
  const double _t160 = _hc1[1]*_t156 + _hc1[1]*_t157 + _t154*_t34 + _t159;
  const double _t161 = -_t132;
  const double _t162 = _hc2[15]*_t48 + _t161;
  const double _t163 = _hc2[12]*_t48;
  const double _t164 = -_t122 + _t163;
  const double _t165 = _t164*_t37;
  const double _t166 = _hc2[14]*_t48;
  const double _t167 = -_t126 + _t166;
  const double _t168 = _hc2[19]*_t48 - _t129;
  const double _t169 = _t120 - _t168*_t21;
  const double _t170 = _hc2[4]*_t156 + _hc2[4]*_t157 + _t162*_t34 - _t165*ta - _t167*_t41 + _t169;
  const double _t171 = my_piecewise3(_t16, 0, _hc1[0]*_t170 + _hc2[0]*_t160 + _t35*_t49 + _t43*_t50);
  const double _t172 = 0.2e1*_t50;
  const double _t174 = _hc0[1]*_t173;
  const double _t176 = _hc0[2]*_t175;
  const double _t177 = _hc2[4]*_t174 + _hc2[4]*_t176 + _t162*_t48 + _t169;
  const double _t178 = _hc1[1]*_t174 + _hc1[1]*_t176 + _t154*_t48 + _t159;
  const double _t179 = my_piecewise3(_t16, 0, _hc1[0]*_t177 + _hc2[0]*_t178 + _t172*_t49);
  const double _t180 = 0.2e1*_t53;
  const double _t182 = _hc3[1]*_t181;
  const double _t184 = _hc3[2]*_t183;
  const double _t185 = _hc4[1]*_t182 + _hc4[1]*_t184 + _t138*_t52 + _t143;
  const double _t186 = _hc5[6]*_t55;
  const double _t187 = _hc5[16]*_t21;
  const double _t188 = _hc3[1]*_hc5[12]*_t46 - _hc5[9]*_t146 - _t186*tb - _t187;
  const double _t189 = _t188*_t55;
  const double _t190 = _hc5[9]*_t55;
  const double _t191 = _hc3[1]*_hc5[14]*_t46 - _hc5[11]*_t146 - _hc5[18]*_t21 - _t190*tb;
  const double _t196 = _hc5[1]*_t195;
  const double _t197 = _hc5[4]*_t182 + _hc5[4]*_t184 - _t146*_t191 + _t147*_t52 + _t151 - _t189*tb + _t193*_t57 + _t196*tb;
  const double _t198 = my_piecewise3(_t17, 0, _hc4[0]*_t197 + _hc5[0]*_t185 + _t180*_t60);
  const double _t199 = _t179 + _t198;
  const double _t200 = _t11*_t66;
  const double _t203 = _hc2[9]*_t64;
  const double _t204 = _t203*ta;
  const double _t209 = _hc2[18]*_t208;
  const double _t210 = _t207*_t209;
  const double _t211 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[14]*_t11*_t33*_t64 - _hc2[11]*_t201 - _t202*_t65 - _t204*_t206 - _t210;
  const double _t212 = my_piecewise3(_t16, 0, _hc1[0]*_t211 + _t200*_t35);
  const double _t213 = _t14*_t71;
  const double _t216 = _hc5[18]*_t215;
  const double _t217 = _hc5[14]*_t214;
  const double _t218 = (0.1e1 / 0.2e1)*_t27;
  const double _t219 = -_t216 + _t217*_t218;
  const double _t220 = my_piecewise3(_t17, 0, _hc4[0]*_t219 + _t213*_t30);
  const double _t222 = _t166*_t221 - _t210;
  const double _t223 = my_piecewise3(_t16, 0, _hc1[0]*_t222 + _t200*_t50);
  const double _t226 = _hc5[9]*_t69;
  const double _t227 = _t226*tb;
  const double _t230 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[14]*_t14*_t46*_t69 - _hc5[11]*_t224 - _t216 - _t225*_t70 - _t227*_t229;
  const double _t231 = my_piecewise3(_t17, 0, _hc4[0]*_t230 + _t213*_t53);
  const double _t235 = _hc2[9]*_t10;
  const double _t237 = _t12*_t122;
  const double _t238 = _hc0[1]*_hc2[12]*_t12*_t33 - _hc2[6]*_t234 - _t235*_t236 - _t237 - _t38;
  const double _t239 = my_piecewise3(_t16, 0, _hc1[0]*_t238 + _t35*_t73);
  const double _t240 = _t15*_t187;
  const double _t241 = _t15*_t27;
  const double _t242 = _hc5[12]*_t241 - _t240;
  const double _t243 = my_piecewise3(_t17, 0, _hc4[0]*_t242 + _t30*_t75);
  const double _t244 = _t12*_t163 - _t237;
  const double _t245 = my_piecewise3(_t16, 0, _hc1[0]*_t244 + _t50*_t73);
  const double _t249 = _hc5[9]*_t13;
  const double _t251 = _hc3[1]*_hc5[12]*_t15*_t46 - _hc5[6]*_t248 - _t240 - _t249*_t250 - _t56;
  const double _t252 = my_piecewise3(_t17, 0, _hc4[0]*_t251 + _t53*_t75);
  const double _t253 = _hc1[0]*_t36;
  const double _t255 = (0.1e1 / 0.4e1)*_hc2[11]*_t254;
  const double _t257 = _hc2[3]*_t256;
  const double _t258 = (0.1e1 / 0.4e1)*_t257;
  const double _t259 = my_piecewise3(_t16, 0, _t253*_t255 - _t258*_t63);
  const double _t260 = _hc4[0]*_t54;
  const double _t262 = (0.1e1 / 0.4e1)*_hc5[11]*_t261;
  const double _t264 = _hc5[3]*_t263;
  const double _t265 = (0.1e1 / 0.4e1)*_t264;
  const double _t266 = my_piecewise3(_t17, 0, _t260*_t262 - _t265*_t68);
  const double _t268 = _hc1[0]*_t267;
  const double _t269 = (0.1e1 / 0.2e1)*_t203;
  const double _t270 = my_piecewise3(_t16, 0, _t268*_t269);
  const double _t272 = _hc4[0]*_t271;
  const double _t273 = (0.1e1 / 0.2e1)*_t226;
  const double _t274 = my_piecewise3(_t17, 0, _t272*_t273);
  const double _t275 = _hc2[6]*_t117;
  const double _t276 = my_piecewise3(_t16, 0, _hc1[0]*_t275);
  const double _t277 = _hc5[6]*_t192;
  const double _t278 = my_piecewise3(_t17, 0, _hc4[0]*_t277);
  const double d2F_dna2 = _t137*_t3 + 0.2e1*_t31 + 0.2e1*_t44;
  const double d2F_dna_dnb = _t3*(_t153 + _t171) + _t45 + _t62;
  const double d2F_dnb2 = _t199*_t3 + 0.2e1*_t51 + 0.2e1*_t61;
  const double d2F_dna_dgaa = _t212*_t3 + _t67;
  const double d2F_dna_dgbb = _t220*_t3 + _t72;
  const double d2F_dnb_dgaa = _t223*_t3 + _t67;
  const double d2F_dnb_dgbb = _t231*_t3 + _t72;
  const double d2F_dna_dta = _t239*_t3 + _t74;
  const double d2F_dna_dtb = _t243*_t3 + _t76;
  const double d2F_dnb_dta = _t245*_t3 + _t74;
  const double d2F_dnb_dtb = _t252*_t3 + _t76;
  const double d2F_dgaa2 = _t259*_t3;
  const double d2F_dgbb2 = _t266*_t3;
  const double d2F_dgaa_dta = _t270*_t3;
  const double d2F_dgbb_dtb = _t274*_t3;
  const double d2F_dta2 = _t276*_t3;
  const double d2F_dtb2 = _t278*_t3;
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
  const double _t281 = xc_powr(_t3, -10, 3);
  const double _t282 = (0.14e2 / 0.27e2)*_t281;
  const double _t283 = _t282*_t8;
  const double _t285 = 0.6e1*_t83;
  const double _t286 = (0.1e1 / (_t3 * _t3 * _t3 * _t3));
  const double _t287 = _t2*_t286;
  const double _t288 = 0.6e1*_t287;
  const double _t289 = -_t285 + _t288;
  const double _t291 = (_t26 * _t26 * _t26);
  const double _t293 = 0.4e1*_t24;
  const double _t294 = 0.4e1*_t83;
  const double _t295 = _t2*_t294;
  const double _t296 = -_t293 + _t295;
  const double _t297 = -_t296;
  const double _t299 = _t78*_t8;
  const double _t300 = (0.4e1 / 0.9e1)*_t299;
  const double _t330 = -_t289;
  const double _t332 = (_t33 * _t33 * _t33);
  const double _t335 = -_t2*_t24;
  const double _t336 = _t335 + _t4;
  const double _t353 = xc_powr(na, -14, 3);
  const double _t354 = (0.440e3 / 0.27e2)*_t353;
  const double _t356 = (0.280e3 / 0.27e2)*_t232;
  const double _t359 = (0.80e2 / 0.9e1)*_t113;
  const double _t362 = (0.56e2 / 0.9e1)*_t117;
  const double _t385 = _t10*_t118;
  const double _t425 = _t288 - 0.2e1*_t83;
  const double _t452 = -_t425;
  const double _t454 = _t23 + _t335;
  const double _t455 = _t106*_t454;
  const double _t517 = _t175*_t336;
  const double _t555 = _t13*_t193;
  const double _t574 = _t285 + _t288;
  const double _t575 = -_t574;
  const double _t577 = (_t47 * _t47 * _t47);
  const double _t581 = _t293 + _t295;
  const double _t588 = (_t46 * _t46 * _t46);
  const double _t590 = -_t581;
  const double _t592 = xc_powr(nb, -14, 3);
  const double _t593 = (0.440e3 / 0.27e2)*_t592;
  const double _t595 = (0.280e3 / 0.27e2)*_t246;
  const double _t617 = (0.56e2 / 0.9e1)*_t192;
  const double _t618 = (0.80e2 / 0.9e1)*_t194;
  const double _t623 = (0.14e2 / 0.9e1)*_t353;
  const double _t624 = (0.14e2 / 0.9e1)*_t117;
  const double _t625 = xc_powi(na, -5);
  const double _t626 = _t625*_t64;
  const double _t628 = (0.20e2 / 0.9e1)*ta;
  const double _t629 = (0.1e1 / 0.9e1)*_t299;
  const double _t631 = _t202*_t64;
  const double _t633 = _t206*ta;
  const double _t634 = _t207*_t208;
  const double _t638 = _t633*_t64;
  const double _t649 = _t214*_t629;
  const double _t671 = _t225*_t69;
  const double _t672 = _t229*tb;
  const double _t677 = _t672*_t69;
  const double _t684 = (0.14e2 / 0.9e1)*_t592;
  const double _t689 = (0.14e2 / 0.9e1)*_t192;
  const double _t690 = xc_powi(nb, -5);
  const double _t691 = _t69*_t690;
  const double _t693 = (0.20e2 / 0.9e1)*tb;
  const double _t694 = (0.1e1 / 0.2e1)*_t214;
  const double _t697 = xc_powr(na, -16, 3);
  const double _t699 = (0.40e2 / 0.9e1)*ta;
  const double _t700 = (0.28e2 / 0.9e1)*_t625;
  const double _t702 = _t10*_t236;
  const double _t705 = _t37*ta;
  const double _t732 = _t13*_t250;
  const double _t741 = _t55*tb;
  const double _t743 = (0.28e2 / 0.9e1)*_t690;
  const double _t744 = xc_powr(nb, -16, 3);
  const double _t746 = (0.40e2 / 0.9e1)*tb;
  const double _t751 = _t113*_t254;
  const double _t755 = (0.5e1 / 0.12e2)*ta;
  const double _t756 = (0.1e1 / 0.4e1)*_t256;
  const double _t757 = _t254*_t36;
  const double _t758 = (0.1e1 / 0.24e2)*_t20;
  const double _t764 = (0.1e1 / 0.4e1)*_t263;
  const double _t765 = _t14*_t764;
  const double _t767 = _t261*_t54;
  const double _t771 = _t11*_t756;
  const double _t774 = _t194*_t261;
  const double _t778 = (0.5e1 / 0.12e2)*tb;
  const double _t782 = (0.2e1 / 0.3e1)*_t697;
  const double _t783 = (0.3e1 / 0.2e1)*_t205;
  const double _t784 = xc_powr(na, -17, 3);
  const double _t785 = _t784*ta;
  const double _t786 = (0.5e1 / 0.6e1)*_t785;
  const double _t788 = _t207*_t64;
  const double _t794 = _t207*_t69;
  const double _t799 = (0.1e1 / 0.2e1)*_t64;
  const double _t800 = _t267*_t799;
  const double _t803 = (0.2e1 / 0.3e1)*_t744;
  const double _t804 = (0.3e1 / 0.2e1)*_t228;
  const double _t805 = xc_powr(nb, -17, 3);
  const double _t806 = _t805*tb;
  const double _t807 = (0.5e1 / 0.6e1)*_t806;
  const double _t810 = (0.10e2 / 0.3e1)*_t232;
  const double _t811 = xc_powi(na, -6);
  const double _t814 = (0.4e1 / 0.3e1)*_t784;
  const double _t824 = (0.10e2 / 0.3e1)*_t246;
  const double _t825 = xc_powi(nb, -6);
  const double _t828 = (0.4e1 / 0.3e1)*_t805;
  const double _t831 = (0.1e1 / (gaa * gaa));
  const double _t833 = xc_powr(gaa, -5, 2);
  const double _t837 = _t205*_t256;
  const double _t838 = (0.1e1 / 0.8e1)*_t837;
  const double _t840 = (0.1e1 / (gbb * gbb));
  const double _t842 = xc_powr(gbb, -5, 2);
  const double _t846 = _t228*_t263;
  const double _t847 = (0.1e1 / 0.8e1)*_t846;
  const double _t279 = 0.3e1*_t30;
  const double _t280 = 0.3e1*_t28;
  const double _t284 = -_hc5[5]*_t283;
  const double _t290 = _hc3[1]*_t289;
  const double _t292 = _hc3[3]*_t291;
  const double _t298 = _hc5[4]*_t139;
  const double _t301 = 0.2e1*_t94;
  const double _t302 = _hc5[20]*_t80;
  const double _t303 = _hc5[55]*_t21;
  const double _t304 = _hc5[54]*_t27 - _t303;
  const double _t305 = _hc5[54]*_t21;
  const double _t306 = _hc5[50]*_t27 - _t305;
  const double _t307 = _hc5[19]*_t88 + _hc5[19]*_t90 - _t21*_t304 + _t27*_t306 + _t302;
  const double _t308 = _hc5[19]*_t80;
  const double _t309 = _hc5[50]*_t21;
  const double _t310 = _hc5[40]*_t27 - _t309;
  const double _t311 = _hc5[15]*_t88 + _hc5[15]*_t90 - _t21*_t306 + _t27*_t310 + _t308;
  const double _t312 = _hc5[4]*_t290 + _hc5[4]*_t292 - _t21*_t307 + _t27*_t311 + _t284 + _t297*_t298 + _t298*_t87 + _t300*_t92 + _t301*_t88 + _t301*_t90;
  const double _t313 = -_hc4[2]*_t283;
  const double _t314 = 0.2e1*_t100;
  const double _t315 = _hc4[5]*_t80;
  const double _t316 = -_hc4[9]*_t21;
  const double _t317 = _hc4[8]*_t27 + _t316;
  const double _t318 = -_hc4[8]*_t21;
  const double _t319 = _hc4[7]*_t27 + _t318;
  const double _t320 = _hc4[4]*_t88 + _hc4[4]*_t90 - _t21*_t317 + _t27*_t319 + _t315;
  const double _t321 = _hc4[4]*_t80;
  const double _t322 = -_hc4[7]*_t21;
  const double _t323 = _hc4[6]*_t27 + _t322;
  const double _t324 = _hc4[3]*_t88 + _hc4[3]*_t90 - _t21*_t319 + _t27*_t323 + _t321;
  const double _t325 = _hc4[1]*_t290 + _hc4[1]*_t292 + _t140*_t297 + _t140*_t87 - _t21*_t320 + _t27*_t324 + _t300*_t98 + _t313 + _t314*_t88 + _t314*_t90;
  const double _t326 = my_piecewise3(_t17, 0, _hc4[0]*_t312 + _hc5[0]*_t325 + _t101*_t280 + _t279*_t95);
  const double _t327 = 0.3e1*_t43;
  const double _t328 = 0.3e1*_t35;
  const double _t329 = -_hc1[2]*_t283;
  const double _t331 = _hc0[1]*_t330;
  const double _t333 = _hc0[3]*_t332;
  const double _t334 = _hc1[1]*_t155;
  const double _t337 = _hc0[1]*_t336;
  const double _t338 = _hc1[3]*_t337 + _t110;
  const double _t339 = 0.2e1*_t107;
  const double _t340 = 0.2e1*_t105;
  const double _t341 = _hc1[5]*_t80;
  const double _t342 = -_hc1[9]*_t21;
  const double _t343 = _hc1[8]*_t34 + _t342;
  const double _t344 = -_hc1[8]*_t21;
  const double _t345 = _hc1[7]*_t34 + _t344;
  const double _t346 = _hc1[4]*_t105 + _hc1[4]*_t107 - _t21*_t343 + _t34*_t345 + _t341;
  const double _t347 = -_hc1[7]*_t21;
  const double _t348 = _hc1[6]*_t34 + _t347;
  const double _t349 = _hc1[4]*_t80;
  const double _t350 = _hc1[3]*_t107 + _t349;
  const double _t351 = _hc1[3]*_t105 - _t21*_t345 + _t34*_t348 + _t350;
  const double _t352 = _hc1[1]*_t331 + _hc1[1]*_t333 + _t109*_t300 + _t111*_t340 - _t21*_t346 + _t296*_t334 + _t329 + _t334*_t86 + _t338*_t339 + _t34*_t351;
  const double _t355 = _hc2[1]*_t354;
  const double _t357 = -_t119*_t282;
  const double _t358 = _hc2[4]*_t155;
  const double _t360 = _t123*_t359;
  const double _t361 = _t10*_t127;
  const double _t363 = _hc0[1]*_hc2[15]*_t336 - _t133;
  const double _t364 = _hc2[6]*_t114;
  const double _t365 = _hc2[16]*_t80;
  const double _t366 = _hc2[12]*_t105;
  const double _t367 = _hc2[12]*_t107;
  const double _t368 = _hc2[21]*_t37;
  const double _t369 = _hc2[41]*_t21;
  const double _t370 = _hc0[1]*_hc2[31]*_t33 - _hc2[25]*_t41 - _t368*ta - _t369;
  const double _t371 = _t37*_t370;
  const double _t372 = _hc2[25]*_t37;
  const double _t373 = _hc2[44]*_t21;
  const double _t374 = _hc0[1]*_hc2[34]*_t33 - _hc2[28]*_t41 - _t372*ta - _t373;
  const double _t375 = _hc2[41]*_t37;
  const double _t376 = _hc2[51]*_t21;
  const double _t377 = _hc0[1]*_hc2[47]*_t33 - _hc2[44]*_t41 - _t375*ta - _t376;
  const double _t378 = _hc2[31]*_t37;
  const double _t379 = _hc2[47]*_t21;
  const double _t380 = _hc2[34]*_t41 + _t378*ta + _t379;
  const double _t381 = _hc0[1]*_hc2[37]*_t33 - _t380;
  const double _t382 = _t118*_t235 - _t21*_t377 + _t34*_t381 + _t364*ta + _t365 + _t366 + _t367 - _t371*ta - _t374*_t41;
  const double _t383 = _t37*_t382;
  const double _t384 = _hc2[9]*_t114;
  const double _t386 = _hc2[18]*_t80;
  const double _t387 = _hc2[14]*_t105;
  const double _t388 = _hc2[14]*_t107;
  const double _t389 = _t37*_t374;
  const double _t390 = _hc2[28]*_t37;
  const double _t391 = _hc2[46]*_t21;
  const double _t392 = _hc0[1]*_hc2[36]*_t33 - _hc2[30]*_t41 - _t390*ta - _t391;
  const double _t393 = _hc2[44]*_t37;
  const double _t394 = _hc2[53]*_t21;
  const double _t395 = _hc0[1]*_hc2[49]*_t33 - _hc2[46]*_t41 - _t393*ta - _t394;
  const double _t396 = _hc2[34]*_t37;
  const double _t397 = _hc2[49]*_t21;
  const double _t398 = _hc2[36]*_t41 + _t396*ta + _t397;
  const double _t399 = _hc0[1]*_hc2[39]*_t33 - _t398;
  const double _t400 = _hc2[11]*_t385 - _t21*_t395 + _t34*_t399 + _t384*ta + _t386 + _t387 + _t388 - _t389*ta - _t392*_t41;
  const double _t401 = _hc2[16]*_t114;
  const double _t402 = _hc2[20]*_t80;
  const double _t403 = _t37*_t377;
  const double _t404 = _hc2[51]*_t37;
  const double _t405 = _hc2[55]*_t21;
  const double _t406 = _hc0[1]*_hc2[54]*_t33 - _hc2[53]*_t41 - _t404*ta - _t405;
  const double _t407 = _hc2[47]*_t37;
  const double _t408 = _hc2[54]*_t21;
  const double _t409 = _hc2[49]*_t41 + _t407*ta + _t408;
  const double _t410 = _hc0[1]*_hc2[50]*_t33 - _t409;
  const double _t411 = _hc2[18]*_t385 + _hc2[19]*_t105 + _hc2[19]*_t107 - _t21*_t406 + _t34*_t410 - _t395*_t41 + _t401*ta + _t402 - _t403*ta;
  const double _t412 = _hc2[37]*_t37;
  const double _t413 = _hc2[50]*_t21;
  const double _t414 = _hc2[39]*_t41 + _t412*ta + _t413;
  const double _t415 = _hc0[1]*_hc2[40]*_t33 - _t414;
  const double _t416 = _t37*_t381;
  const double _t417 = _hc2[19]*_t80;
  const double _t418 = _hc2[12]*_t114;
  const double _t419 = _hc2[14]*_t385 + _hc2[15]*_t107 + _t417 + _t418*ta;
  const double _t420 = _hc2[15]*_t105 - _t21*_t410 + _t34*_t415 - _t399*_t41 - _t416*ta + _t419;
  const double _t421 = _hc2[4]*_t331 + _hc2[4]*_t333 - _t116*_t356 + _t130*_t300 + _t134*_t340 - _t21*_t411 + _t296*_t358 + _t339*_t363 + _t34*_t420 - _t355*ta + _t357 + _t358*_t86 + _t360*ta + _t361*_t362 - _t383*ta - _t400*_t41;
  const double _t422 = my_piecewise3(_t16, 0, _hc1[0]*_t421 + _hc2[0]*_t352 + _t112*_t327 + _t135*_t328);
  const double _t423 = _t326 + _t422;
  const double _t424 = 0.2e1*_t144;
  const double _t426 = _hc3[1]*_t425;
  const double _t427 = _hc3[2]*_t87;
  const double _t428 = _hc4[1]*_t46;
  const double _t429 = _hc3[3]*_t89;
  const double _t430 = _t139*_t46;
  const double _t431 = _hc4[7]*_t52 + _t318;
  const double _t432 = _hc4[8]*_t52 + _t316;
  const double _t433 = -_t21*_t432 + _t315;
  const double _t434 = -_hc4[4]*_t141 + _hc4[4]*_t430 + _t27*_t431 + _t433;
  const double _t435 = _hc4[6]*_t52 + _t322;
  const double _t436 = -_t21*_t431 + _t321;
  const double _t437 = -_hc4[3]*_t141 + _hc4[3]*_t430 + _t27*_t435 + _t436;
  const double _t438 = _hc4[1]*_t426 - _t100*_t141 + _t100*_t430 + _t138*_t88 + _t138*_t90 - _t140*_t295 + _t142*_t80 - _t21*_t434 + _t27*_t437 + _t313 + _t427*_t428 + _t428*_t429 + _t80*_t98;
  const double _t439 = _hc5[47]*_t55;
  const double _t440 = _hc3[1]*_hc5[50]*_t46 - _hc5[49]*_t146 - _t305 - _t439*tb;
  const double _t441 = _hc5[51]*_t55;
  const double _t442 = _hc3[1]*_hc5[54]*_t46 - _hc5[53]*_t146 - _t303 - _t441*tb;
  const double _t443 = -_t21*_t442 + _t302;
  const double _t444 = -_hc5[19]*_t141 + _hc5[19]*_t430 + _t27*_t440 + _t443;
  const double _t445 = _hc5[37]*_t55;
  const double _t446 = _hc3[1]*_hc5[40]*_t46 - _hc5[39]*_t146 - _t309 - _t445*tb;
  const double _t447 = -_t21*_t440 + _t308;
  const double _t448 = -_hc5[15]*_t141 + _hc5[15]*_t430 + _t27*_t446 + _t447;
  const double _t449 = _hc5[4]*_t426 - _t141*_t94 + _t147*_t88 + _t147*_t90 + _t148*_t427 + _t148*_t429 + _t150*_t80 - _t21*_t444 + _t27*_t448 + _t284 - _t295*_t298 + _t430*_t94 + _t80*_t92;
  const double _t450 = my_piecewise3(_t17, 0, _hc4[0]*_t449 + _hc5[0]*_t438 + _t101*_t60 + _t152*_t77 + _t28*_t424 + _t53*_t95);
  const double _t451 = 0.2e1*_t160;
  const double _t453 = _hc0[1]*_t452;
  const double _t456 = _hc0[3]*_hc1[1];
  const double _t457 = _hc0[2]*_t47;
  const double _t458 = _t457*_t86;
  const double _t459 = _hc0[1]*_t454;
  const double _t460 = _hc1[3]*_t459 + _t110;
  const double _t461 = _hc1[7]*_t48 + _t344;
  const double _t462 = _hc1[8]*_t48 + _t342;
  const double _t463 = -_t21*_t462 + _t341;
  const double _t464 = _hc1[4]*_t156 + _hc1[4]*_t157 + _t34*_t461 + _t463;
  const double _t465 = _hc1[6]*_t48 + _t347;
  const double _t466 = _hc1[3]*_t157;
  const double _t467 = -_t21*_t461 + _t349;
  const double _t468 = _hc1[3]*_t156 + _t34*_t465 + _t466 + _t467;
  const double _t469 = _hc1[1]*_t453 + _hc1[1]*_t458 + _t105*_t154 + _t107*_t460 + _t109*_t80 + _t111*_t156 + _t111*_t157 + _t158*_t80 - _t21*_t464 + _t295*_t334 + _t329 + _t34*_t468 + _t455*_t456;
  const double _t470 = _hc0[3]*_hc2[4];
  const double _t471 = _t114*_t164;
  const double _t472 = _hc2[15]*_t459 + _t161;
  const double _t473 = -_t379;
  const double _t474 = _hc2[37]*_t48;
  const double _t475 = _t473 + _t474;
  const double _t476 = _hc2[31]*_t48;
  const double _t477 = -_t369 + _t476;
  const double _t478 = _t37*_t477;
  const double _t479 = _hc2[34]*_t48;
  const double _t480 = -_t373 + _t479;
  const double _t481 = _hc2[12]*_t156;
  const double _t482 = _hc2[12]*_t157;
  const double _t483 = _hc2[47]*_t48;
  const double _t484 = -_t376 + _t483;
  const double _t485 = -_t21*_t484 + _t365;
  const double _t486 = _t34*_t475 - _t41*_t480 - _t478*ta + _t481 + _t482 + _t485;
  const double _t487 = _t37*_t486;
  const double _t488 = -_t397;
  const double _t489 = _hc2[39]*_t48;
  const double _t490 = _t488 + _t489;
  const double _t491 = _t37*_t480;
  const double _t492 = _hc2[36]*_t48;
  const double _t493 = -_t391 + _t492;
  const double _t494 = _hc2[14]*_t156;
  const double _t495 = _hc2[49]*_t48;
  const double _t496 = -_t394 + _t495;
  const double _t497 = -_t21*_t496 + _t386;
  const double _t498 = _hc2[14]*_t157 + _t34*_t490 - _t41*_t493 - _t491*ta + _t494 + _t497;
  const double _t499 = -_t408;
  const double _t500 = _hc2[50]*_t48 + _t499;
  const double _t501 = _t37*_t484;
  const double _t502 = _hc2[54]*_t48 - _t405;
  const double _t503 = -_t21*_t502 + _t402;
  const double _t504 = _hc2[19]*_t156 + _hc2[19]*_t157 + _t34*_t500 - _t41*_t496 - _t501*ta + _t503;
  const double _t505 = -_t21*_t500;
  const double _t506 = -_t413;
  const double _t507 = _hc2[40]*_t48 + _t506;
  const double _t508 = _t37*_t475;
  const double _t509 = _hc2[15]*_t157 + _t417;
  const double _t510 = _hc2[15]*_t156 + _t34*_t507 - _t41*_t490 + _t505 - _t508*ta + _t509;
  const double _t511 = _hc2[4]*_t453 + _hc2[4]*_t458 + _t105*_t162 + _t107*_t472 + _t130*_t80 + _t134*_t156 + _t134*_t157 + _t167*_t385 + _t168*_t80 - _t21*_t504 + _t295*_t358 + _t34*_t510 + _t357 - _t41*_t498 + _t455*_t470 + _t471*ta - _t487*ta;
  const double _t512 = my_piecewise3(_t16, 0, _hc1[0]*_t511 + _hc2[0]*_t469 + _t103*_t170 + _t112*_t49 + _t135*_t50 + _t43*_t451);
  const double _t513 = 0.2e1*_t153 + 0.2e1*_t171;
  const double _t514 = _hc1[3]*_t176;
  const double _t515 = _hc1[3]*_t174 + _t465*_t48 + _t467 + _t514;
  const double _t516 = _hc0[1]*_t84;
  const double _t518 = _hc0[1]*_t288;
  const double _t519 = 0.2e1*_t156;
  const double _t520 = _hc0[1]*_t295;
  const double _t521 = _hc1[1]*_t457;
  const double _t522 = _hc1[4]*_t174 + _hc1[4]*_t176 + _t461*_t48 + _t463;
  const double _t523 = _t158*_t300 - _t21*_t522 + _t329;
  const double _t524 = -_hc1[1]*_t516 - _hc1[1]*_t518 + _t154*_t519 + _t154*_t520 + _t173*_t334 + _t295*_t521 + _t34*_t515 + _t456*_t517 + _t523;
  const double _t525 = _hc2[15]*_t176 + _t417;
  const double _t526 = _hc2[15]*_t174 + _t48*_t507 + _t505 + _t525;
  const double _t527 = _hc2[12]*_t174;
  const double _t528 = _hc2[12]*_t176;
  const double _t529 = _t475*_t48 + _t485 + _t527 + _t528;
  const double _t530 = _t37*_t529;
  const double _t531 = _hc2[14]*_t174;
  const double _t532 = _hc2[14]*_t176;
  const double _t533 = _t48*_t490 + _t497 + _t531 + _t532;
  const double _t534 = _hc2[4]*_t457;
  const double _t535 = _hc2[19]*_t174 + _hc2[19]*_t176 + _t48*_t500 + _t503;
  const double _t536 = _t168*_t300 - _t21*_t535 + _t357;
  const double _t537 = -_hc2[4]*_t516 - _hc2[4]*_t518 + _t162*_t519 + _t162*_t520 + _t173*_t358 + _t295*_t534 + _t34*_t526 - _t41*_t533 + _t470*_t517 - _t530*ta + _t536;
  const double _t538 = my_piecewise3(_t16, 0, _hc1[0]*_t537 + _hc2[0]*_t524 + _t170*_t172 + _t177*_t35 + _t178*_t43 + _t451*_t49);
  const double _t539 = _hc4[3]*_t182 + _hc4[3]*_t184 + _t435*_t52 + _t436;
  const double _t540 = _hc3[1]*_t84;
  const double _t541 = _hc3[3]*_t26;
  const double _t542 = _t183*_t541;
  const double _t543 = _hc3[1]*_t295;
  const double _t544 = 0.2e1*_t138;
  const double _t545 = _hc3[1]*_t288;
  const double _t546 = _hc3[2]*_t428;
  const double _t547 = _hc4[4]*_t182 + _hc4[4]*_t184 + _t431*_t52 + _t433;
  const double _t548 = _t142*_t300 - _t21*_t547 + _t313;
  const double _t549 = _hc4[1]*_t540 + _hc4[1]*_t542 + _hc4[1]*_t545 - _t138*_t543 + _t140*_t181 + _t27*_t539 - _t295*_t546 + _t430*_t544 + _t548;
  const double _t550 = _hc5[31]*_t55;
  const double _t551 = _hc3[1]*_hc5[37]*_t46 - _hc5[34]*_t146 - _hc5[47]*_t21 - _t550*tb;
  const double _t552 = _t55*_t551;
  const double _t553 = _hc5[34]*_t55;
  const double _t554 = _hc3[1]*_hc5[39]*_t46 - _hc5[36]*_t146 - _hc5[49]*_t21 - _t553*tb;
  const double _t556 = _hc5[12]*_t195;
  const double _t557 = _hc5[14]*_t555 + _hc5[15]*_t182 + _hc5[15]*_t184 - _t146*_t554 + _t446*_t52 + _t447 - _t552*tb + _t556*tb;
  const double _t558 = _hc5[4]*_t183;
  const double _t559 = 0.2e1*_t147;
  const double _t560 = _hc3[2]*_t148;
  const double _t561 = _hc5[41]*_t55;
  const double _t562 = _hc5[51]*_t21;
  const double _t563 = _hc3[1]*_hc5[47]*_t46 - _hc5[44]*_t146 - _t561*tb - _t562;
  const double _t564 = _t55*_t563;
  const double _t565 = _hc5[44]*_t55;
  const double _t566 = _hc3[1]*_hc5[49]*_t46 - _hc5[46]*_t146 - _hc5[53]*_t21 - _t565*tb;
  const double _t567 = _hc5[16]*_t195;
  const double _t568 = _hc5[18]*_t555 + _hc5[19]*_t182 + _hc5[19]*_t184 - _t146*_t566 + _t440*_t52 + _t443 - _t564*tb + _t567*tb;
  const double _t569 = _t150*_t300 - _t21*_t568 + _t284;
  const double _t570 = _hc5[4]*_t540 + _hc5[4]*_t545 - _t147*_t543 + _t181*_t298 + _t27*_t557 - _t295*_t560 + _t430*_t559 + _t541*_t558 + _t569;
  const double _t571 = my_piecewise3(_t17, 0, _hc4[0]*_t570 + _hc5[0]*_t549 + _t152*_t180 + _t185*_t28 + _t197*_t30 + _t424*_t60);
  const double _t572 = 0.3e1*_t50;
  const double _t573 = 0.3e1*_t49;
  const double _t576 = _hc0[1]*_t575;
  const double _t578 = _hc0[3]*_t577;
  const double _t579 = 0.2e1*_t174;
  const double _t580 = 0.2e1*_t176;
  const double _t582 = _hc2[4]*_t576 + _hc2[4]*_t578 + _t162*_t579 + _t173*_t534 + _t472*_t580 + _t48*_t526 + _t534*_t581 + _t536;
  const double _t583 = _hc1[1]*_t576 + _hc1[1]*_t578 + _t154*_t579 + _t173*_t521 + _t460*_t580 + _t48*_t515 + _t521*_t581 + _t523;
  const double _t584 = my_piecewise3(_t16, 0, _hc1[0]*_t582 + _hc2[0]*_t583 + _t177*_t572 + _t178*_t573);
  const double _t585 = 0.3e1*_t60;
  const double _t586 = 0.3e1*_t53;
  const double _t587 = _hc3[1]*_t574;
  const double _t589 = _hc3[3]*_t588;
  const double _t591 = _hc4[1]*_t587 + _hc4[1]*_t589 + _t181*_t546 + _t182*_t544 + _t184*_t544 + _t52*_t539 + _t546*_t590 + _t548;
  const double _t594 = _hc5[1]*_t593;
  const double _t596 = _hc5[6]*_t195;
  const double _t597 = _hc5[16]*_t80;
  const double _t598 = _hc5[12]*_t184;
  const double _t599 = _hc5[12]*_t182;
  const double _t600 = _hc5[21]*_t55;
  const double _t601 = _hc5[41]*_t21;
  const double _t602 = _hc3[1]*_hc5[31]*_t46 - _hc5[25]*_t146 - _t600*tb - _t601;
  const double _t603 = _t55*_t602;
  const double _t604 = _hc5[25]*_t55;
  const double _t605 = _hc5[44]*_t21;
  const double _t606 = _hc3[1]*_hc5[34]*_t46 - _hc5[28]*_t146 - _t604*tb - _t605;
  const double _t607 = -_t146*_t606 + _t193*_t249 - _t21*_t563 + _t52*_t551 + _t596*tb + _t597 + _t598 + _t599 - _t603*tb;
  const double _t608 = _t55*_t607;
  const double _t609 = _hc5[9]*_t195;
  const double _t610 = _hc5[14]*_t184;
  const double _t611 = _hc5[14]*_t182;
  const double _t612 = _t55*_t606;
  const double _t613 = _hc5[28]*_t55;
  const double _t614 = _hc3[1]*_hc5[36]*_t46 - _hc5[30]*_t146 - _hc5[46]*_t21 - _t613*tb;
  const double _t615 = _hc5[11]*_t555 + _hc5[18]*_t80 - _t146*_t614 - _t21*_t566 + _t52*_t554 + _t609*tb + _t610 + _t611 - _t612*tb;
  const double _t616 = _t13*_t191;
  const double _t619 = _t188*_t618;
  const double _t620 = _hc5[4]*_t587 + _hc5[4]*_t589 - _t146*_t615 + _t181*_t560 + _t182*_t559 + _t184*_t559 + _t52*_t557 + _t560*_t590 + _t569 - _t57*_t595 - _t594*tb - _t608*tb + _t616*_t617 + _t619*tb;
  const double _t621 = my_piecewise3(_t17, 0, _hc4[0]*_t620 + _hc5[0]*_t591 + _t185*_t585 + _t197*_t586);
  const double _t622 = _t584 + _t621;
  const double _t627 = _hc2[9]*_t626;
  const double _t630 = _t209*_t629;
  const double _t632 = _hc2[25]*_t64;
  const double _t635 = _hc2[44]*_t634;
  const double _t636 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[34]*_t11*_t33*_t64 - _hc2[28]*_t201 - _hc2[9]*_t631 - _t632*_t633 - _t635;
  const double _t637 = _t37*_t636;
  const double _t639 = _hc2[46]*_t634;
  const double _t640 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[36]*_t11*_t33*_t64 - _hc2[11]*_t631 - _hc2[28]*_t638 - _hc2[30]*_t201 - _t639;
  const double _t641 = _hc2[53]*_t634;
  const double _t642 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[49]*_t11*_t33*_t64 - _hc2[18]*_t631 - _hc2[44]*_t638 - _hc2[46]*_t201 - _t641;
  const double _t643 = _hc2[34]*_t64;
  const double _t644 = _hc2[49]*_t634;
  const double _t645 = _hc2[14]*_t631 + _hc2[36]*_t201 + _t633*_t643 + _t644;
  const double _t646 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[39]*_t11*_t33*_t64 - _t645;
  const double _t647 = _hc2[11]*_t623 - _t127*_t631 - _t21*_t642 + _t221*_t387 + _t221*_t388 + _t34*_t646 - _t41*_t640 + _t624*_t65 + _t627*_t628 + _t630 - _t637*ta;
  const double _t648 = my_piecewise3(_t16, 0, _hc1[0]*_t647 + _t103*_t211 + _t112*_t200);
  const double _t650 = _hc5[18]*_t649;
  const double _t651 = (0.1e1 / 0.2e1)*_t217;
  const double _t652 = _hc5[53]*_t215;
  const double _t653 = _t214*_t218;
  const double _t654 = _hc5[49]*_t653 - _t652;
  const double _t655 = _hc5[49]*_t215;
  const double _t656 = _hc5[39]*_t653 - _t655;
  const double _t657 = -_t21*_t654 + _t27*_t656 + _t650 + _t651*_t88 + _t651*_t90;
  const double _t658 = my_piecewise3(_t17, 0, _hc4[0]*_t657 + _t101*_t213 + _t219*_t77);
  const double _t659 = -_t644;
  const double _t660 = _t221*_t489 + _t659;
  const double _t661 = _t221*_t479 - _t635;
  const double _t662 = _t37*_t661;
  const double _t663 = _t221*_t492 - _t639;
  const double _t664 = _hc0[1]*_t83;
  const double _t665 = _t208*_t664;
  const double _t666 = _hc2[14]*_t665;
  const double _t667 = _t221*_t495 - _t641;
  const double _t668 = -_t21*_t667 + _t630;
  const double _t669 = -_t167*_t631 + _t2*_t666 + _t221*_t494 + _t34*_t660 - _t41*_t663 - _t662*ta + _t668;
  const double _t670 = my_piecewise3(_t16, 0, _hc1[0]*_t669 + _t160*_t200 + _t211*_t50 + _t222*_t35);
  const double _t673 = _hc5[34]*_t69;
  const double _t674 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[39]*_t14*_t46*_t69 - _hc5[14]*_t671 - _hc5[36]*_t224 - _t655 - _t672*_t673;
  const double _t675 = _hc3[1]*_t83;
  const double _t676 = _t217*_t675;
  const double _t678 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[49]*_t14*_t46*_t69 - _hc5[18]*_t671 - _hc5[44]*_t677 - _hc5[46]*_t224 - _t652;
  const double _t679 = -_t21*_t678 + _t650;
  const double _t680 = -_t2*_t676 + _t27*_t674 + _t430*_t651 + _t679;
  const double _t681 = my_piecewise3(_t17, 0, _hc4[0]*_t680 + _t144*_t213 + _t219*_t53 + _t230*_t30);
  const double _t682 = _t221*_t531 + _t221*_t532 + _t48*_t660 + _t668;
  const double _t683 = my_piecewise3(_t16, 0, _hc1[0]*_t682 + _t172*_t222 + _t178*_t200);
  const double _t685 = _hc5[25]*_t69;
  const double _t686 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[34]*_t14*_t46*_t69 - _hc5[28]*_t224 - _hc5[44]*_t215 - _hc5[9]*_t671 - _t672*_t685;
  const double _t687 = _t55*_t686;
  const double _t688 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[36]*_t14*_t46*_t69 - _hc5[11]*_t671 - _hc5[28]*_t677 - _hc5[30]*_t224 - _hc5[46]*_t215;
  const double _t692 = _hc5[9]*_t691;
  const double _t695 = _hc5[11]*_t684 - _t146*_t688 - _t191*_t671 + _t52*_t674 + _t610*_t694 + _t611*_t694 + _t679 - _t687*tb + _t689*_t70 + _t692*_t693;
  const double _t696 = my_piecewise3(_t17, 0, _hc4[0]*_t695 + _t180*_t230 + _t185*_t213);
  const double _t698 = _hc2[6]*_t697;
  const double _t701 = _t12*_t365;
  const double _t703 = _t12*_t369;
  const double _t704 = _hc0[1]*_hc2[31]*_t12*_t33 - _hc2[21]*_t234 - _hc2[25]*_t702 - _t121 - _t703;
  const double _t706 = _t12*_t373;
  const double _t707 = _hc0[1]*_hc2[34]*_t12*_t33 - _hc2[25]*_t234 - _hc2[28]*_t702 - _t125 - _t706;
  const double _t708 = _t12*_t376;
  const double _t709 = _hc0[1]*_hc2[47]*_t12*_t33 - _hc2[41]*_t234 - _hc2[44]*_t702 - _t128 - _t708;
  const double _t710 = _t12*_t379;
  const double _t711 = _hc2[31]*_t234 + _hc2[34]*_t702 + _t131 + _t710;
  const double _t712 = _hc0[1]*_hc2[37]*_t12*_t33 - _t711;
  const double _t713 = _t115 + _t12*_t366 + _t12*_t367 - _t124 - _t21*_t709 + _t235*_t700 + _t34*_t712 - _t41*_t707 + _t698*_t699 + _t701 - _t704*_t705;
  const double _t714 = my_piecewise3(_t16, 0, _hc1[0]*_t713 + _t103*_t238 + _t112*_t73);
  const double _t715 = _t15*_t597;
  const double _t716 = _hc5[12]*_t15;
  const double _t717 = _t15*_t562;
  const double _t718 = _hc5[47]*_t241 - _t717;
  const double _t719 = _hc5[47]*_t15;
  const double _t720 = _t21*_t719;
  const double _t721 = _hc5[37]*_t241 - _t720;
  const double _t722 = -_t21*_t718 + _t27*_t721 + _t715 + _t716*_t88 + _t716*_t90;
  const double _t723 = my_piecewise3(_t17, 0, _hc4[0]*_t722 + _t101*_t75 + _t242*_t77);
  const double _t724 = -_t710;
  const double _t725 = _t12*_t474 + _t724;
  const double _t726 = _t12*_t476 - _t703;
  const double _t727 = _t12*_t479 - _t706;
  const double _t728 = _t12*_t483 - _t708;
  const double _t729 = -_t21*_t728 + _t701;
  const double _t730 = _t12*_t481 + _t12*_t482 - _t165 + _t34*_t725 - _t41*_t727 - _t705*_t726 + _t729;
  const double _t731 = my_piecewise3(_t16, 0, _hc1[0]*_t730 + _t160*_t73 + _t238*_t50 + _t244*_t35);
  const double _t733 = _hc3[1]*_hc5[37]*_t15*_t46 - _hc5[31]*_t248 - _hc5[34]*_t732 - _t145 - _t720;
  const double _t734 = _hc3[1]*_hc5[47]*_t15*_t46 - _hc5[41]*_t248 - _hc5[44]*_t732 - _t149 - _t717;
  const double _t735 = -_t21*_t734 + _t715;
  const double _t736 = -_t141*_t716 + _t27*_t733 + _t430*_t716 + _t735;
  const double _t737 = my_piecewise3(_t17, 0, _hc4[0]*_t736 + _t144*_t75 + _t242*_t53 + _t251*_t30);
  const double _t738 = _t12*_t527 + _t12*_t528 + _t48*_t725 + _t729;
  const double _t739 = my_piecewise3(_t16, 0, _hc1[0]*_t738 + _t172*_t244 + _t178*_t73);
  const double _t740 = _hc3[1]*_hc5[31]*_t15*_t46 - _hc5[21]*_t248 - _hc5[25]*_t732 - _t15*_t601 - _t186;
  const double _t742 = _hc3[1]*_hc5[34]*_t15*_t46 - _hc5[25]*_t248 - _hc5[28]*_t732 - _t15*_t605 - _t190;
  const double _t745 = _hc5[6]*_t744;
  const double _t747 = -_t146*_t742 + _t15*_t598 + _t15*_t599 - _t189 + _t196 + _t249*_t743 + _t52*_t733 + _t735 - _t740*_t741 + _t745*_t746;
  const double _t748 = my_piecewise3(_t17, 0, _hc4[0]*_t747 + _t180*_t251 + _t185*_t75);
  const double _t749 = _t255*_t36;
  const double _t750 = _t11*_t258;
  const double _t752 = (0.1e1 / 0.3e1)*_hc2[30];
  const double _t753 = _hc2[28]*_t254;
  const double _t754 = _t697*_t753;
  const double _t759 = -0.1e1 / 0.24e2*_hc2[18]*_t11*_t19*_t256*_t6*_t7 + _hc2[46]*_t757*_t758;
  const double _t760 = (0.1e1 / 0.4e1)*_hc0[1]*_hc2[36]*_t254*_t33*_t36 - 0.1e1 / 0.3e1*_hc2[11]*_t751 - _hc2[14]*_t11*_t34*_t756 + (0.1e1 / 0.3e1)*_hc2[3]*_t256*_t39 + (0.5e1 / 0.12e2)*_hc2[9]*_t205*_t256*ta - _t626*_t752 - _t754*_t755 - _t759;
  const double _t761 = my_piecewise3(_t16, 0, _hc1[0]*_t760 + _t35*_t749 - _t35*_t750);
  const double _t762 = _t262*_t54;
  const double _t763 = _t14*_t265;
  const double _t766 = _hc5[14]*_t27;
  const double _t768 = -0.1e1 / 0.24e2*_hc5[18]*_t14*_t19*_t263*_t6*_t7 + _hc5[46]*_t758*_t767;
  const double _t769 = (0.1e1 / 0.4e1)*_hc3[1]*_hc5[36]*_t26*_t261*_t54 - _t765*_t766 - _t768;
  const double _t770 = my_piecewise3(_t17, 0, _hc4[0]*_t769 + _t30*_t762 - _t30*_t763);
  const double _t772 = (0.1e1 / 0.4e1)*_hc0[1]*_hc2[36]*_t254*_t36*_t47 - _t166*_t771 - _t759;
  const double _t773 = my_piecewise3(_t16, 0, _hc1[0]*_t772 + _t50*_t749 - _t50*_t750);
  const double _t775 = (0.1e1 / 0.3e1)*_hc5[30];
  const double _t776 = _hc5[28]*_t261;
  const double _t777 = _t744*_t776;
  const double _t779 = (0.1e1 / 0.4e1)*_hc3[1]*_hc5[36]*_t261*_t46*_t54 - 0.1e1 / 0.3e1*_hc5[11]*_t774 - _hc5[14]*_t52*_t765 + (0.1e1 / 0.3e1)*_hc5[3]*_t263*_t58 + (0.5e1 / 0.12e2)*_hc5[9]*_t228*_t263*tb - _t691*_t775 - _t768 - _t777*_t778;
  const double _t780 = my_piecewise3(_t17, 0, _hc4[0]*_t779 + _t53*_t762 - _t53*_t763);
  const double _t781 = _t267*_t269;
  const double _t787 = _hc2[44]*_t267;
  const double _t789 = _t787*_t788;
  const double _t790 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[34]*_t267*_t33*_t64 - _hc2[28]*_t782 - _t203*_t783 - _t632*_t786 - _t789;
  const double _t791 = my_piecewise3(_t16, 0, _hc1[0]*_t790 + _t35*_t781);
  const double _t792 = _t271*_t273;
  const double _t793 = _hc5[44]*_t271;
  const double _t795 = _t793*_t794;
  const double _t796 = _t271*_t673;
  const double _t797 = _t218*_t796 - _t795;
  const double _t798 = my_piecewise3(_t17, 0, _hc4[0]*_t797 + _t30*_t792);
  const double _t801 = _t479*_t800 - _t789;
  const double _t802 = my_piecewise3(_t16, 0, _hc1[0]*_t801 + _t50*_t781);
  const double _t808 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[34]*_t271*_t46*_t69 - _hc5[28]*_t803 - _t226*_t804 - _t685*_t807 - _t795;
  const double _t809 = my_piecewise3(_t17, 0, _hc4[0]*_t808 + _t53*_t792);
  const double _t812 = _hc2[21]*_t811;
  const double _t813 = _hc2[25]*_t10;
  const double _t815 = _t117*_t369;
  const double _t816 = _hc0[1]*_hc2[31]*_t117*_t33 - _hc2[6]*_t810 - _t233*_t812 - _t813*_t814 - _t815;
  const double _t817 = my_piecewise3(_t16, 0, _hc1[0]*_t816 + _t275*_t35);
  const double _t818 = _t192*_t601;
  const double _t819 = _t192*_t27;
  const double _t820 = _hc5[31]*_t819 - _t818;
  const double _t821 = my_piecewise3(_t17, 0, _hc4[0]*_t820 + _t277*_t30);
  const double _t822 = _t117*_t476 - _t815;
  const double _t823 = my_piecewise3(_t16, 0, _hc1[0]*_t822 + _t275*_t50);
  const double _t826 = _hc5[21]*_t825;
  const double _t827 = _hc5[25]*_t13;
  const double _t829 = _hc3[1]*_hc5[31]*_t192*_t46 - _hc5[6]*_t824 - _t247*_t826 - _t818 - _t827*_t828;
  const double _t830 = my_piecewise3(_t17, 0, _hc4[0]*_t829 + _t277*_t53);
  const double _t832 = (0.3e1 / 0.8e1)*_hc2[11]*_t831;
  const double _t834 = _hc2[3]*_t833;
  const double _t835 = (0.3e1 / 0.8e1)*_t834;
  const double _t836 = _hc1[0]*_hc2[30];
  const double _t839 = my_piecewise3(_t16, 0, -_t253*_t832 + _t63*_t835 + _t836*_t838);
  const double _t841 = (0.3e1 / 0.8e1)*_hc5[11]*_t840;
  const double _t843 = _hc5[3]*_t842;
  const double _t844 = (0.3e1 / 0.8e1)*_t843;
  const double _t845 = _hc4[0]*_hc5[30];
  const double _t848 = my_piecewise3(_t17, 0, -_t260*_t841 + _t68*_t844 + _t845*_t847);
  const double _t849 = _hc1[0]*_t232;
  const double _t850 = (0.1e1 / 0.4e1)*_t753;
  const double _t851 = _hc2[9]*_t256;
  const double _t852 = (0.1e1 / 0.4e1)*_t851;
  const double _t853 = my_piecewise3(_t16, 0, -_t268*_t852 + _t849*_t850);
  const double _t854 = _hc4[0]*_t246;
  const double _t855 = (0.1e1 / 0.4e1)*_t776;
  const double _t856 = _hc5[9]*_t263;
  const double _t857 = (0.1e1 / 0.4e1)*_t856;
  const double _t858 = my_piecewise3(_t17, 0, -_t272*_t857 + _t854*_t855);
  const double _t859 = _hc1[0]*_t353;
  const double _t860 = (0.1e1 / 0.2e1)*_t632;
  const double _t861 = my_piecewise3(_t16, 0, _t859*_t860);
  const double _t862 = _hc4[0]*_t592;
  const double _t863 = (0.1e1 / 0.2e1)*_t685;
  const double _t864 = my_piecewise3(_t17, 0, _t862*_t863);
  const double _t865 = _hc2[21]*_t625;
  const double _t866 = my_piecewise3(_t16, 0, _hc1[0]*_t865);
  const double _t867 = _hc5[21]*_t690;
  const double _t868 = my_piecewise3(_t17, 0, _hc4[0]*_t867);
  const double d3F_dna3 = 0.3e1*_t102 + 0.3e1*_t136 + _t3*_t423;
  const double d3F_dna2_dnb = _t137 + _t3*(_t450 + _t512) + _t513;
  const double d3F_dna_dnb2 = _t199 + _t3*(_t538 + _t571) + _t513;
  const double d3F_dnb3 = 0.3e1*_t179 + 0.3e1*_t198 + _t3*_t622;
  const double d3F_dna2_dgaa = 0.2e1*_t212 + _t3*_t648;
  const double d3F_dna2_dgbb = 0.2e1*_t220 + _t3*_t658;
  const double d3F_dna_dnb_dgaa = _t212 + _t223 + _t3*_t670;
  const double d3F_dna_dnb_dgbb = _t220 + _t231 + _t3*_t681;
  const double d3F_dnb2_dgaa = 0.2e1*_t223 + _t3*_t683;
  const double d3F_dnb2_dgbb = 0.2e1*_t231 + _t3*_t696;
  const double d3F_dna2_dta = 0.2e1*_t239 + _t3*_t714;
  const double d3F_dna2_dtb = 0.2e1*_t243 + _t3*_t723;
  const double d3F_dna_dnb_dta = _t239 + _t245 + _t3*_t731;
  const double d3F_dna_dnb_dtb = _t243 + _t252 + _t3*_t737;
  const double d3F_dnb2_dta = 0.2e1*_t245 + _t3*_t739;
  const double d3F_dnb2_dtb = 0.2e1*_t252 + _t3*_t748;
  const double d3F_dna_dgaa2 = _t259 + _t3*_t761;
  const double d3F_dna_dgbb2 = _t266 + _t3*_t770;
  const double d3F_dnb_dgaa2 = _t259 + _t3*_t773;
  const double d3F_dnb_dgbb2 = _t266 + _t3*_t780;
  const double d3F_dna_dgaa_dta = _t270 + _t3*_t791;
  const double d3F_dna_dgbb_dtb = _t274 + _t3*_t798;
  const double d3F_dnb_dgaa_dta = _t270 + _t3*_t802;
  const double d3F_dnb_dgbb_dtb = _t274 + _t3*_t809;
  const double d3F_dna_dta2 = _t276 + _t3*_t817;
  const double d3F_dna_dtb2 = _t278 + _t3*_t821;
  const double d3F_dnb_dta2 = _t276 + _t3*_t823;
  const double d3F_dnb_dtb2 = _t278 + _t3*_t830;
  const double d3F_dgaa3 = _t3*_t839;
  const double d3F_dgbb3 = _t3*_t848;
  const double d3F_dgaa2_dta = _t3*_t853;
  const double d3F_dgbb2_dtb = _t3*_t858;
  const double d3F_dgaa_dta2 = _t3*_t861;
  const double d3F_dgbb_dtb2 = _t3*_t864;
  const double d3F_dta3 = _t3*_t866;
  const double d3F_dtb3 = _t3*_t868;
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
  const double _t869 = (0.140e3 / 0.81e2)/xc_powr(_t3, 13, 3);
  const double _t870 = _t8*_t869;
  const double _t872 = 0.24e2*_t286;
  const double _t873 = 0.24e2*_t2/xc_powi(_t3, 5);
  const double _t874 = -_t872 + _t873;
  const double _t878 = 0.12e2*_t83;
  const double _t879 = 0.12e2*_t286;
  const double _t880 = _t2*_t879;
  const double _t881 = -_t878 + _t880;
  const double _t882 = 0.2e1*_t289;
  const double _t884 = 0.6e1*_t24;
  const double _t885 = _t2*_t285;
  const double _t886 = _t884 - _t885;
  const double _t888 = _t281*_t8;
  const double _t889 = (0.14e2 / 0.9e1)*_t888;
  const double _t892 = (0.2e1 / 0.3e1)*_t299;
  const double _t936 = -_t881;
  const double _t937 = 0.2e1*_t330;
  const double _t940 = 0.6e1*na - 0.6e1*nb;
  const double _t941 = _t83*_t940 - _t884;
  const double _t943 = 0.4e1*na - 0.4e1*nb;
  const double _t944 = -_t293 + _t83*_t943;
  const double _t945 = 0.2e1*na - 0.2e1*nb;
  const double _t946 = -_t82 + _t83*_t945;
  const double _t975 = _t36*ta;
  const double _t979 = _t354*ta;
  const double _t987 = _t359*ta;
  const double _t988 = _t10*_t362;
  const double _t989 = _t114*ta;
  const double _t1024 = _t10*_t356;
  const double _t1069 = _t873 - _t879;
  const double _t1079 = -0.4e1*_t83 + _t880;
  const double _t1083 = (0.28e2 / 0.27e2)*_t888;
  const double _t1087 = 0.8e1*_t2*_t83;
  const double _t1121 = -_t1079;
  const double _t1123 = _t332*_t454;
  const double _t1129 = _t33*_t47;
  const double _t1132 = _t296*_t85;
  const double _t1228 = 0.2e1*_t425;
  const double _t1231 = 0.8e1*(_t2 * _t2)/xc_powi(_t3, 6);
  const double _t1240 = _t195*tb;
  const double _t1265 = _t82 + _t83*_t945;
  const double _t1270 = _t175*_t946;
  const double _t1271 = _t106*_t175;
  const double _t1272 = 0.2e1*_t452;
  const double _t1312 = _t336*_t577;
  const double _t1313 = 0.18e2*_t287;
  const double _t1316 = 0.3e1*_t173;
  const double _t1319 = _t173*_t885;
  const double _t1322 = _t2*_t878;
  const double _t1342 = 0.3e1*_t181;
  const double _t1346 = _t181*_t885;
  const double _t1349 = _t593*tb;
  const double _t1350 = _t13*_t595;
  const double _t1362 = _t13*_t617;
  const double _t1363 = _t618*tb;
  const double _t1381 = _t872 + _t873;
  const double _t1389 = _t878 + _t880;
  const double _t1390 = -_t1389;
  const double _t1391 = _t173*_t581;
  const double _t1392 = _t293 + _t83*_t943;
  const double _t1393 = _t83*_t940 + _t884;
  const double _t1394 = 0.2e1*_t575;
  const double _t1395 = 0.3e1*_t581;
  const double _t1399 = _t181*_t590;
  const double _t1400 = -_t884 - _t885;
  const double _t1401 = 0.2e1*_t574;
  const double _t1430 = (0.7e1 / 0.27e2)*_t888;
  const double _t1433 = _t626*_t628;
  const double _t1434 = _t208*_t629;
  const double _t1443 = _t624*_t64;
  const double _t1492 = 0.3e1*_t287;
  const double _t1497 = _t689*_t69;
  const double _t1498 = _t691*_t693;
  const double _t1508 = xc_powr(na, -19, 3);
  const double _t1511 = _t697*_t699;
  const double _t1520 = _t10*_t700;
  const double _t1566 = _t13*_t743;
  const double _t1567 = _t744*_t746;
  const double _t1574 = xc_powr(nb, -19, 3);
  const double _t1576 = (0.1e1 / 0.3e1)*_t751;
  const double _t1577 = (0.1e1 / 0.3e1)*_t626;
  const double _t1578 = _t254*_t755;
  const double _t1579 = _t1578*_t697;
  const double _t1580 = _t757*_t758;
  const double _t1584 = (0.4e1 / 0.3e1)*_t39*_t64;
  const double _t1588 = _t11*_t256;
  const double _t1589 = (0.1e1 / 0.18e2)*_t299;
  const double _t1592 = _t758*_t767;
  const double _t1595 = _t14*_t263;
  const double _t1596 = (0.1e1 / 0.4e1)*_t261*_t54;
  const double _t1603 = (0.1e1 / 0.3e1)*_t691;
  const double _t1604 = (0.1e1 / 0.3e1)*_t774;
  const double _t1605 = _t261*_t778;
  const double _t1606 = _t1605*_t744;
  const double _t1611 = xc_powr(na, -20, 3);
  const double _t1613 = _t64*_t783;
  const double _t1614 = _t64*_t786;
  const double _t1615 = _t267*_t788;
  const double _t1622 = _t271*_t794;
  const double _t1624 = (0.1e1 / 0.2e1)*_t69;
  const double _t1625 = _t1624*_t271;
  const double _t1630 = _t69*_t804;
  const double _t1631 = _t69*_t807;
  const double _t1634 = xc_powr(nb, -20, 3);
  const double _t1635 = xc_powi(na, -7);
  const double _t1637 = (0.10e2 / 0.3e1)*_t36;
  const double _t1638 = _t233*_t811;
  const double _t1639 = _t10*_t814;
  const double _t1650 = _t247*_t825;
  const double _t1651 = _t13*_t828;
  const double _t1654 = xc_powi(nb, -7);
  const double _t1659 = _t205*_t833;
  const double _t1660 = (0.1e1 / 0.48e2)*_t20;
  const double _t1662 = (0.1e1 / 0.16e2)*_t20;
  const double _t1664 = (0.3e1 / 0.8e1)*_t831;
  const double _t1665 = _t1664*_t36;
  const double _t1671 = (0.3e1 / 0.8e1)*_t842;
  const double _t1672 = (0.3e1 / 0.8e1)*_t840;
  const double _t1673 = _t1672*_t54;
  const double _t1674 = (0.3e1 / 0.8e1)*_t833;
  const double _t1676 = _t228*_t842;
  const double _t1680 = _t267*_t756;
  const double _t1684 = _t271*_t764;
  const double _t871 = _hc5[5]*_t870;
  const double _t875 = -_hc3[1]*_t874;
  const double _t876 = _hc3[4]*(_t26 * _t26 * _t26 * _t26);
  const double _t877 = _hc3[2]*(_t87 * _t87);
  const double _t883 = _hc5[4]*_t297;
  const double _t887 = _hc5[4]*_t429;
  const double _t890 = 0.3e1*_t94;
  const double _t891 = _t139*_t890;
  const double _t893 = 0.3e1*_t311;
  const double _t894 = -_hc5[20]*_t283;
  const double _t895 = _hc5[19]*_t139;
  const double _t896 = 0.2e1*_t306;
  const double _t897 = _hc5[55]*_t80;
  const double _t898 = _hc5[125]*_t21;
  const double _t899 = _hc5[124]*_t21;
  const double _t900 = _hc5[120]*_t27 - _t899;
  const double _t901 = _hc5[54]*_t80;
  const double _t902 = _hc5[120]*_t21;
  const double _t903 = _hc5[110]*_t27 - _t902;
  const double _t904 = _hc5[50]*_t88 + _hc5[50]*_t90 - _t21*_t900 + _t27*_t903 + _t901;
  const double _t905 = -_hc5[19]*_t283;
  const double _t906 = _hc5[15]*_t139;
  const double _t907 = 0.2e1*_t310;
  const double _t908 = _hc5[50]*_t80;
  const double _t909 = _hc5[110]*_t21;
  const double _t910 = _hc4[2]*_t870;
  const double _t911 = _hc4[1]*_t297;
  const double _t912 = _hc4[1]*_t429;
  const double _t913 = 0.3e1*_t100;
  const double _t914 = _t139*_t913;
  const double _t915 = 0.3e1*_t324;
  const double _t916 = -_hc4[5]*_t283;
  const double _t917 = _hc4[4]*_t139;
  const double _t918 = 0.2e1*_t319;
  const double _t919 = _hc4[9]*_t80;
  const double _t920 = -_hc4[14]*_t21;
  const double _t921 = -_hc4[13]*_t21;
  const double _t922 = _hc4[12]*_t27 + _t921;
  const double _t923 = _hc4[8]*_t80;
  const double _t924 = -_hc4[12]*_t21;
  const double _t925 = _hc4[11]*_t27 + _t924;
  const double _t926 = _hc4[7]*_t88 + _hc4[7]*_t90 - _t21*_t922 + _t27*_t925 + _t923;
  const double _t927 = -_hc4[4]*_t283;
  const double _t928 = _hc4[3]*_t139;
  const double _t929 = 0.2e1*_t323;
  const double _t930 = _hc4[7]*_t80;
  const double _t931 = -_hc4[11]*_t21;
  const double _t932 = _hc1[2]*_t870;
  const double _t933 = _hc0[1]*_t874;
  const double _t934 = _hc0[4]*(_t33 * _t33 * _t33 * _t33);
  const double _t935 = _hc0[2]*(_t86 * _t86);
  const double _t938 = _hc0[2]*_t86;
  const double _t939 = _t296*_t938;
  const double _t942 = _t106*_t456;
  const double _t947 = 0.3e1*_t333;
  const double _t948 = 0.3e1*_t331;
  const double _t949 = 0.3e1*_t155;
  const double _t950 = _t111*_t949;
  const double _t951 = _hc0[1]*_t946;
  const double _t952 = _hc1[6]*_t337 + _t347;
  const double _t953 = -0.1e1 / 0.36e2*_hc1[8]*_t19*_t6*_t7;
  const double _t954 = _hc1[7]*_t337;
  const double _t955 = 0.3e1*_t107;
  const double _t956 = 0.3e1*_t105;
  const double _t957 = -_hc1[5]*_t283;
  const double _t958 = _hc1[4]*_t155;
  const double _t959 = _hc1[9]*_t80;
  const double _t960 = -_hc1[14]*_t21;
  const double _t961 = -_hc1[13]*_t21;
  const double _t962 = _hc1[12]*_t34 + _t961;
  const double _t963 = _hc1[8]*_t80;
  const double _t964 = -_hc1[12]*_t21;
  const double _t965 = _hc1[11]*_t34 + _t964;
  const double _t966 = _hc1[7]*_t105 + _hc1[7]*_t107 - _t21*_t962 + _t34*_t965 + _t963;
  const double _t967 = -_hc1[4]*_t283;
  const double _t968 = _hc1[3]*_t155;
  const double _t969 = _hc1[7]*_t80;
  const double _t970 = -_hc1[11]*_t21;
  const double _t971 = _t119*_t869;
  const double _t972 = _t106*_t470;
  const double _t973 = _t134*_t949;
  const double _t974 = _hc0[1]*_hc2[40]*_t336 - _t414;
  const double _t976 = (0.20e2 / 0.9e1)*_hc2[34];
  const double _t977 = (0.2e1 / 0.9e1)*_hc2[49];
  const double _t978 = _hc0[1]*_hc2[37]*_t336 - _t380;
  const double _t980 = _hc2[16]*_t283;
  const double _t981 = -_t980;
  const double _t982 = _hc2[12]*_t331;
  const double _t983 = _hc2[12]*_t333;
  const double _t984 = _hc2[12]*_t155;
  const double _t985 = _t86*_t984;
  const double _t986 = _t296*_t984;
  const double _t990 = _hc2[41]*_t80;
  const double _t991 = _hc2[31]*_t105;
  const double _t992 = _hc2[31]*_t107;
  const double _t993 = _hc2[91]*_t21;
  const double _t994 = _hc2[95]*_t21;
  const double _t995 = _hc0[1]*_hc2[75]*_t33 - _hc2[61]*_t705 - _hc2[65]*_t41 - _t994;
  const double _t996 = _hc2[111]*_t21;
  const double _t997 = _hc0[1]*_hc2[101]*_t33 - _hc2[91]*_t705 - _hc2[95]*_t41 - _t996;
  const double _t998 = _hc2[101]*_t21;
  const double _t999 = _hc0[1]*_hc2[81]*_t33 - _hc2[71]*_t705 - _hc2[75]*_t41 - _t998;
  const double _t1000 = _hc2[44]*_t80;
  const double _t1001 = _hc2[34]*_t105;
  const double _t1002 = _hc2[34]*_t107;
  const double _t1003 = _hc2[98]*_t21;
  const double _t1004 = _hc0[1]*_hc2[78]*_t33 - _hc2[65]*_t705 - _hc2[68]*_t41 - _t1003;
  const double _t1005 = _hc2[114]*_t21;
  const double _t1006 = _hc0[1]*_hc2[104]*_t33 - _hc2[95]*_t705 - _hc2[98]*_t41 - _t1005;
  const double _t1007 = _hc2[104]*_t21;
  const double _t1008 = _hc0[1]*_hc2[84]*_t33 - _hc2[75]*_t705 - _hc2[78]*_t41 - _t1007;
  const double _t1009 = _hc2[25]*_t989 + _hc2[28]*_t385 + _t1000 + _t1001 + _t1002 - _t1004*_t41 - _t1006*_t21 + _t1008*_t34 - _t705*_t995;
  const double _t1010 = _hc2[51]*_t80;
  const double _t1011 = _hc2[47]*_t105;
  const double _t1012 = _hc2[47]*_t107;
  const double _t1013 = _hc2[121]*_t21;
  const double _t1014 = _hc0[1]*_hc2[117]*_t33 - _hc2[111]*_t705 - _hc2[114]*_t41 - _t1013;
  const double _t1015 = _hc2[117]*_t21;
  const double _t1016 = _hc0[1]*_hc2[107]*_t33 - _hc2[101]*_t705 - _hc2[104]*_t41 - _t1015;
  const double _t1017 = _hc2[41]*_t989 + _hc2[44]*_t385 - _t1006*_t41 + _t1010 + _t1011 + _t1012 - _t1014*_t21 + _t1016*_t34 - _t705*_t997;
  const double _t1018 = _hc2[47]*_t80;
  const double _t1019 = _hc2[37]*_t105;
  const double _t1020 = _hc2[37]*_t107;
  const double _t1021 = _hc2[107]*_t21;
  const double _t1022 = _hc0[1]*_hc2[87]*_t33 - _hc2[81]*_t705 - _hc2[84]*_t41 - _t1021;
  const double _t1023 = _hc2[31]*_t989 + _hc2[34]*_t385 - _t1008*_t41 - _t1016*_t21 + _t1018 + _t1019 + _t1020 + _t1022*_t34 - _t705*_t999;
  const double _t1025 = -_hc2[18]*_t283;
  const double _t1026 = _hc2[14]*_t331;
  const double _t1027 = _hc2[14]*_t333;
  const double _t1028 = _hc2[14]*_t155;
  const double _t1029 = _t1028*_t86;
  const double _t1030 = _t1028*_t296;
  const double _t1031 = _hc2[46]*_t80;
  const double _t1032 = _hc2[36]*_t105;
  const double _t1033 = _hc2[36]*_t107;
  const double _t1034 = _hc2[100]*_t21;
  const double _t1035 = _hc2[116]*_t21;
  const double _t1036 = _hc0[1]*_hc2[106]*_t33 - _hc2[100]*_t41 - _hc2[98]*_t705 - _t1035;
  const double _t1037 = _hc2[106]*_t21;
  const double _t1038 = _hc0[1]*_hc2[86]*_t33 - _hc2[78]*_t705 - _hc2[80]*_t41 - _t1037;
  const double _t1039 = _hc2[53]*_t80;
  const double _t1040 = _hc2[49]*_t105;
  const double _t1041 = _hc2[49]*_t107;
  const double _t1042 = _hc2[123]*_t21;
  const double _t1043 = _hc0[1]*_hc2[119]*_t33 - _hc2[114]*_t705 - _hc2[116]*_t41 - _t1042;
  const double _t1044 = _hc2[119]*_t21;
  const double _t1045 = _hc0[1]*_hc2[109]*_t33 - _hc2[104]*_t705 - _hc2[106]*_t41 - _t1044;
  const double _t1046 = _hc2[44]*_t989 + _hc2[46]*_t385 - _t1006*_t705 - _t1036*_t41 + _t1039 + _t1040 + _t1041 - _t1043*_t21 + _t1045*_t34;
  const double _t1047 = _t299*_t977;
  const double _t1048 = _hc2[39]*_t105;
  const double _t1049 = _hc2[39]*_t107;
  const double _t1050 = _hc2[109]*_t21;
  const double _t1051 = _hc0[1]*_hc2[89]*_t33 - _hc2[84]*_t705 - _hc2[86]*_t41 - _t1050;
  const double _t1052 = _hc2[34]*_t989 + _hc2[36]*_t385 - _t1008*_t705 - _t1038*_t41 - _t1045*_t21 + _t1047 + _t1048 + _t1049 + _t1051*_t34;
  const double _t1053 = -_hc2[20]*_t283;
  const double _t1054 = _hc2[19]*_t155;
  const double _t1055 = _hc2[55]*_t80;
  const double _t1056 = _hc2[125]*_t21;
  const double _t1057 = _hc2[124]*_t21;
  const double _t1058 = _hc0[1]*_hc2[120]*_t33 - _hc2[117]*_t705 - _hc2[119]*_t41 - _t1057;
  const double _t1059 = _hc2[54]*_t80;
  const double _t1060 = _hc2[120]*_t21;
  const double _t1061 = _hc0[1]*_hc2[110]*_t33 - _hc2[107]*_t705 - _hc2[109]*_t41 - _t1060;
  const double _t1062 = _hc2[47]*_t989 + _hc2[49]*_t385 + _hc2[50]*_t105 + _hc2[50]*_t107 - _t1016*_t705 - _t1045*_t41 - _t1058*_t21 + _t1059 + _t1061*_t34;
  const double _t1063 = -_hc2[19]*_t283;
  const double _t1064 = _hc2[15]*_t155;
  const double _t1065 = _hc2[50]*_t80;
  const double _t1066 = _hc2[110]*_t21;
  const double _t1067 = 0.3e1*_t144;
  const double _t1068 = 0.3e1*_t152;
  const double _t1070 = -_hc3[1]*_t1069;
  const double _t1071 = _hc4[3]*_t46;
  const double _t1072 = _hc4[11]*_t52 + _t924;
  const double _t1073 = _hc4[12]*_t52 + _t921;
  const double _t1074 = -_t1073*_t21 + _t923;
  const double _t1075 = -_hc4[7]*_t141 + _hc4[7]*_t430 + _t1072*_t27 + _t1074;
  const double _t1076 = _hc4[10]*_t52 + _t931;
  const double _t1077 = -_t1072*_t21 + _t930;
  const double _t1078 = 0.2e1*_t437;
  const double _t1080 = _t138*_t139;
  const double _t1081 = _hc3[4]*_t291;
  const double _t1082 = _t314*_t46;
  const double _t1084 = _hc4[4]*_t46;
  const double _t1085 = -_t21*(_hc4[13]*_t52 + _t920) + _t919;
  const double _t1086 = _t428*_t541;
  const double _t1088 = _t1087*_t139;
  const double _t1089 = _t427*_t85;
  const double _t1090 = _hc3[2]*_t85;
  const double _t1091 = _t300*_t434 + _t910;
  const double _t1092 = _t148*_t541;
  const double _t1093 = _t301*_t46;
  const double _t1094 = _t139*_t147;
  const double _t1095 = _t300*_t444;
  const double _t1096 = 0.2e1*_t448;
  const double _t1097 = _hc5[19]*_t46;
  const double _t1098 = _hc3[1]*_hc5[120]*_t46 - _hc5[117]*_t741 - _hc5[119]*_t146 - _t899;
  const double _t1099 = -_t21*(_hc3[1]*_hc5[124]*_t46 - _hc5[121]*_t741 - _hc5[123]*_t146 - _t898) + _t897;
  const double _t1100 = _hc3[1]*_hc5[110]*_t46 - _hc5[107]*_t741 - _hc5[109]*_t146 - _t902;
  const double _t1101 = -_t1098*_t21 + _t901;
  const double _t1102 = -_hc5[50]*_t141 + _hc5[50]*_t430 + _t1100*_t27 + _t1101;
  const double _t1103 = _hc5[15]*_t46;
  const double _t1104 = _hc3[1]*_hc5[90]*_t46 - _hc5[87]*_t741 - _hc5[89]*_t146 - _t909;
  const double _t1105 = -_t1100*_t21 + _t908;
  const double _t1106 = 0.3e1*_t170;
  const double _t1107 = 0.3e1*_t160;
  const double _t1108 = _hc0[1]*_t1069;
  const double _t1109 = _hc0[3]*_t455;
  const double _t1110 = _hc1[6]*_t459 + _t347;
  const double _t1111 = _hc1[11]*_t48 + _t964;
  const double _t1112 = _hc1[12]*_t48 + _t961;
  const double _t1113 = -_t1112*_t21 + _t963;
  const double _t1114 = _hc1[7]*_t156 + _hc1[7]*_t157 + _t1111*_t34 + _t1113;
  const double _t1115 = _hc1[10]*_t48 + _t970;
  const double _t1116 = -_t1111*_t21 + _t969;
  const double _t1117 = 0.2e1*_t453;
  const double _t1118 = _hc0[2]*_t336*_t454;
  const double _t1119 = _hc1[7]*_t459;
  const double _t1120 = _t20*(-0.1e1 / 0.6e1*_t1119 - _t953) + _t349;
  const double _t1122 = _t154*_t155;
  const double _t1124 = _hc0[4]*_hc1[1];
  const double _t1125 = 0.2e1*_t458;
  const double _t1126 = 0.2e1*_t1109;
  const double _t1127 = _t1119 + _t344;
  const double _t1128 = -_t21*(_hc1[13]*_t48 + _t960) + _t959;
  const double _t1130 = _t1129*_t456;
  const double _t1131 = _hc0[2]*_hc1[1];
  const double _t1133 = _t85*_t938;
  const double _t1134 = _t1087*_t155;
  const double _t1135 = _t300*_t464 + _t932;
  const double _t1136 = _hc2[40]*_t459 + _t506;
  const double _t1137 = _hc2[87]*_t48;
  const double _t1138 = -_t1021 + _t1137;
  const double _t1139 = _hc2[81]*_t48;
  const double _t1140 = _t1139 - _t998;
  const double _t1141 = _hc2[84]*_t48;
  const double _t1142 = -_t1007 + _t1141;
  const double _t1143 = _hc2[37]*_t156;
  const double _t1144 = _hc2[37]*_t157;
  const double _t1145 = _hc2[107]*_t48;
  const double _t1146 = -_t1015 + _t1145;
  const double _t1147 = _t1018 - _t1146*_t21;
  const double _t1148 = _t1138*_t34 - _t1140*_t705 - _t1142*_t41 + _t1143 + _t1144 + _t1147;
  const double _t1149 = _hc2[89]*_t48;
  const double _t1150 = -_t1050 + _t1149;
  const double _t1151 = _hc2[86]*_t48;
  const double _t1152 = -_t1037 + _t1151;
  const double _t1153 = _hc2[39]*_t156;
  const double _t1154 = _hc2[109]*_t48;
  const double _t1155 = -_t1044 + _t1154;
  const double _t1156 = _t1047 - _t1155*_t21;
  const double _t1157 = _hc2[39]*_t157 - _t1142*_t705 + _t1150*_t34 - _t1152*_t41 + _t1153 + _t1156;
  const double _t1158 = _hc2[110]*_t48 - _t1060;
  const double _t1159 = _hc2[120]*_t48 - _t1057;
  const double _t1160 = _t1059 - _t1159*_t21;
  const double _t1161 = _hc2[50]*_t156 + _hc2[50]*_t157 - _t1146*_t705 - _t1155*_t41 + _t1158*_t34 + _t1160;
  const double _t1162 = _hc2[90]*_t48 - _t1066;
  const double _t1163 = _t1065 - _t1158*_t21;
  const double _t1164 = _hc2[50]*_t459;
  const double _t1165 = _t20*((0.1e1 / 0.36e2)*_hc2[54]*_t19*_t6*_t7 - 0.1e1 / 0.6e1*_t1164);
  const double _t1166 = _hc2[39]*_t459;
  const double _t1167 = _hc2[37]*_t459;
  const double _t1168 = _t1167 + _t473;
  const double _t1169 = _hc2[12]*_t453;
  const double _t1170 = _t295*_t984;
  const double _t1171 = _hc2[12]*_t1109;
  const double _t1172 = _hc2[12]*_t458;
  const double _t1173 = _hc2[71]*_t48;
  const double _t1174 = _hc2[75]*_t48;
  const double _t1175 = _t1174 - _t994;
  const double _t1176 = _hc2[31]*_t156;
  const double _t1177 = _hc2[31]*_t157;
  const double _t1178 = _hc2[101]*_t48;
  const double _t1179 = _t1178 - _t996;
  const double _t1180 = -_t1179*_t21 + _t990;
  const double _t1181 = _hc2[78]*_t48;
  const double _t1182 = -_t1003 + _t1181;
  const double _t1183 = _hc2[34]*_t156;
  const double _t1184 = _hc2[34]*_t157;
  const double _t1185 = _hc2[104]*_t48;
  const double _t1186 = -_t1005 + _t1185;
  const double _t1187 = _t1000 - _t1186*_t21;
  const double _t1188 = _t1142*_t34 - _t1175*_t705 - _t1182*_t41 + _t1183 + _t1184 + _t1187;
  const double _t1189 = _hc2[47]*_t156;
  const double _t1190 = _hc2[47]*_t157;
  const double _t1191 = _hc2[117]*_t48;
  const double _t1192 = -_t1013 + _t1191;
  const double _t1193 = _t1010 - _t1192*_t21;
  const double _t1194 = _t1146*_t34 - _t1179*_t705 - _t1186*_t41 + _t1189 + _t1190 + _t1193;
  const double _t1195 = _hc2[14]*_t453;
  const double _t1196 = _hc2[14]*_t1109;
  const double _t1197 = _hc2[14]*_t458;
  const double _t1198 = _t1166 + _t488;
  const double _t1199 = _hc2[80]*_t48;
  const double _t1200 = _hc2[36]*_t156;
  const double _t1201 = _hc2[106]*_t48;
  const double _t1202 = -_t1035 + _t1201;
  const double _t1203 = _t1031 - _t1202*_t21;
  const double _t1204 = _hc2[49]*_t156;
  const double _t1205 = _hc2[119]*_t48;
  const double _t1206 = -_t1042 + _t1205;
  const double _t1207 = _t1039 - _t1206*_t21;
  const double _t1208 = _hc2[49]*_t157 + _t1155*_t34 - _t1186*_t705 - _t1202*_t41 + _t1204 + _t1207;
  const double _t1209 = _t155*_t162;
  const double _t1210 = _hc0[4]*_hc2[4];
  const double _t1211 = _t1164 + _t499;
  const double _t1212 = _t1055 - _t21*(_hc2[124]*_t48 - _t1056);
  const double _t1213 = _t1129*_t470;
  const double _t1214 = _hc0[2]*_hc2[4];
  const double _t1215 = _t300*_t504 + _t971;
  const double _t1216 = _hc3[1]*_t873;
  const double _t1217 = -_hc4[1]*_t1216;
  const double _t1218 = _hc4[6]*_t182 + _hc4[6]*_t184 + _t1076*_t52 + _t1077;
  const double _t1219 = 0.2e1*_t435;
  const double _t1220 = _hc3[2]*_t1071;
  const double _t1221 = _hc4[7]*_t182 + _hc4[7]*_t184 + _t1072*_t52 + _t1074;
  const double _t1222 = -_t1221*_t21 + _t300*_t431 + _t927;
  const double _t1223 = _t181*_t427;
  const double _t1224 = _t139*_t181;
  const double _t1225 = _hc3[3]*_t87;
  const double _t1226 = _hc4[1]*_t183;
  const double _t1227 = _hc3[4]*_t89;
  const double _t1229 = _t46*_t544;
  const double _t1230 = _hc3[2]*_hc4[1];
  const double _t1232 = 0.2e1*_t431;
  const double _t1233 = _hc3[2]*_t1084;
  const double _t1234 = -_t21*(_hc4[8]*_t182 + _hc4[8]*_t184 + _t1073*_t52 + _t1085) + _t300*_t432 + _t916;
  const double _t1235 = _hc3[2]*_t46;
  const double _t1236 = _t1235*_t295;
  const double _t1237 = _hc5[107]*_t21;
  const double _t1238 = _hc3[1]*_hc5[87]*_t46 - _hc5[81]*_t741 - _hc5[84]*_t146 - _t1237;
  const double _t1239 = _hc3[1]*_hc5[89]*_t46 - _hc5[109]*_t21 - _hc5[84]*_t741 - _hc5[86]*_t146;
  const double _t1241 = _hc5[37]*_t1240 + _hc5[39]*_t555 + _hc5[40]*_t182 + _hc5[40]*_t184 + _t1104*_t52 + _t1105 - _t1238*_t741 - _t1239*_t146;
  const double _t1242 = 0.2e1*_t446;
  const double _t1243 = _hc3[2]*_t1103;
  const double _t1244 = _hc5[117]*_t21;
  const double _t1245 = _hc3[1]*_hc5[107]*_t46 - _hc5[101]*_t741 - _hc5[104]*_t146 - _t1244;
  const double _t1246 = _hc3[1]*_hc5[109]*_t46 - _hc5[104]*_t741 - _hc5[106]*_t146 - _hc5[119]*_t21;
  const double _t1247 = _hc5[47]*_t1240 + _hc5[49]*_t555 + _hc5[50]*_t182 + _hc5[50]*_t184 + _t1100*_t52 + _t1101 - _t1245*_t741 - _t1246*_t146;
  const double _t1248 = -_t1247*_t21 + _t300*_t440 + _t905;
  const double _t1249 = _t46*_t559;
  const double _t1250 = _hc3[2]*_hc5[4];
  const double _t1251 = 0.2e1*_t440;
  const double _t1252 = _hc3[2]*_t1097;
  const double _t1253 = _hc5[121]*_t21;
  const double _t1254 = _hc3[1]*_hc5[117]*_t46 - _hc5[111]*_t741 - _hc5[114]*_t146 - _t1253;
  const double _t1255 = _hc3[1]*_hc5[119]*_t46 - _hc5[114]*_t741 - _hc5[116]*_t146 - _hc5[123]*_t21;
  const double _t1256 = -_t21*(_hc5[51]*_t1240 + _hc5[53]*_t555 + _hc5[54]*_t182 + _hc5[54]*_t184 + _t1098*_t52 + _t1099 - _t1254*_t741 - _t1255*_t146) + _t300*_t442 + _t894;
  const double _t1257 = -_hc5[4]*_t1216 + _t871;
  const double _t1258 = _hc0[1]*_t873;
  const double _t1259 = _hc1[1]*_t1258;
  const double _t1260 = _hc1[6]*_t174 + _hc1[6]*_t176 + _t1115*_t48 + _t1116;
  const double _t1261 = _hc0[3]*_t517;
  const double _t1262 = _hc1[3]*_t457;
  const double _t1263 = _hc1[7]*_t174 + _hc1[7]*_t176 + _t1111*_t48 + _t1113;
  const double _t1264 = -_t1263*_t21 + _t300*_t461 + _t967;
  const double _t1266 = _hc0[1]*_t1265;
  const double _t1267 = _hc1[3]*_t1266 + _t1110*_t459 + _t1120 + _t514;
  const double _t1268 = _t173*_t938;
  const double _t1269 = _t155*_t173;
  const double _t1273 = _hc1[4]*_t457;
  const double _t1274 = -_t21*(_hc1[8]*_t174 + _hc1[8]*_t176 + _t1112*_t48 + _t1128) + _t300*_t462 + _t957;
  const double _t1275 = _t295*_t457;
  const double _t1276 = _hc2[4]*_t1258;
  const double _t1277 = _hc2[40]*_t174 + _hc2[40]*_t176 + _t1162*_t48 + _t1163;
  const double _t1278 = _hc2[37]*_t174;
  const double _t1279 = _hc2[37]*_t176;
  const double _t1280 = _t1138*_t48 + _t1147 + _t1278 + _t1279;
  const double _t1281 = _hc2[39]*_t174;
  const double _t1282 = _hc2[39]*_t176;
  const double _t1283 = _t1150*_t48 + _t1156 + _t1281 + _t1282;
  const double _t1284 = _hc2[15]*_t457;
  const double _t1285 = _hc2[50]*_t174 + _hc2[50]*_t176 + _t1158*_t48 + _t1160;
  const double _t1286 = _t1063 - _t1285*_t21 + _t300*_t500;
  const double _t1287 = _hc2[15]*_t1266 + _t1136*_t459 + _t1165 + _t525;
  const double _t1288 = _hc2[12]*_t516;
  const double _t1289 = _hc2[31]*_t174;
  const double _t1290 = _hc2[31]*_t176;
  const double _t1291 = _hc2[34]*_t174;
  const double _t1292 = _hc2[34]*_t176;
  const double _t1293 = _t1142*_t48 + _t1187 + _t1291 + _t1292;
  const double _t1294 = _hc2[12]*_t518;
  const double _t1295 = _hc2[12]*_t457;
  const double _t1296 = _hc2[47]*_t174;
  const double _t1297 = _hc2[47]*_t176;
  const double _t1298 = _t1146*_t48 + _t1193 + _t1296 + _t1297;
  const double _t1299 = -_t1298*_t21 + _t300*_t484 + _t981;
  const double _t1300 = _hc2[36]*_t174;
  const double _t1301 = _hc2[36]*_t176;
  const double _t1302 = _hc2[14]*_t457;
  const double _t1303 = _hc2[49]*_t174;
  const double _t1304 = _hc2[49]*_t176;
  const double _t1305 = _t1155*_t48 + _t1207 + _t1303 + _t1304;
  const double _t1306 = _t1025 - _t1305*_t21 + _t300*_t496;
  const double _t1307 = _hc2[19]*_t457;
  const double _t1308 = _t1053 - _t21*(_hc2[54]*_t174 + _hc2[54]*_t176 + _t1159*_t48 + _t1212) + _t300*_t502;
  const double _t1309 = _hc1[3]*_t576 + _hc1[3]*_t578 + _t1110*_t580 + _t1260*_t48 + _t1262*_t173 + _t1262*_t581 + _t1264 + _t465*_t579;
  const double _t1310 = _hc0[1]*_t285;
  const double _t1311 = _hc0[1]*_t879;
  const double _t1314 = _hc0[1]*_t1313;
  const double _t1315 = 0.3e1*_t156;
  const double _t1317 = 0.3e1*_t1261;
  const double _t1318 = _hc0[1]*_t885;
  const double _t1320 = _t175*_t456;
  const double _t1321 = _t154*_t457;
  const double _t1323 = -_t158*_t889 - _t21*(_hc1[4]*_t576 + _hc1[4]*_t578 + _t1127*_t580 + _t1263*_t48 + _t1273*_t173 + _t1273*_t581 + _t1274 + _t461*_t579) + _t522*_t892 + _t932;
  const double _t1324 = _hc2[15]*_t576 + _hc2[15]*_t578 + _t1136*_t580 + _t1277*_t48 + _t1284*_t173 + _t1284*_t581 + _t1286 + _t507*_t579;
  const double _t1325 = _hc2[12]*_t576;
  const double _t1326 = _hc2[12]*_t578;
  const double _t1327 = _t1295*_t173;
  const double _t1328 = _t1295*_t581;
  const double _t1329 = _hc2[14]*_t576;
  const double _t1330 = _hc2[14]*_t578;
  const double _t1331 = _t1302*_t173;
  const double _t1332 = _t1302*_t581;
  const double _t1333 = _t175*_t470;
  const double _t1334 = _t162*_t457;
  const double _t1335 = -_t168*_t889 - _t21*(_hc2[19]*_t576 + _hc2[19]*_t578 + _t1211*_t580 + _t1285*_t48 + _t1307*_t173 + _t1307*_t581 + _t1308 + _t500*_t579) + _t535*_t892 + _t971;
  const double _t1336 = _hc4[3]*_t587 + _hc4[3]*_t589 + _t1218*_t52 + _t1219*_t182 + _t1219*_t184 + _t1220*_t181 + _t1220*_t590 + _t1222;
  const double _t1337 = _hc3[1]*_t879;
  const double _t1338 = _hc3[1]*_t285;
  const double _t1339 = _hc3[4]*_t26*_t588;
  const double _t1340 = _hc3[1]*_t885;
  const double _t1341 = 0.3e1*_t539;
  const double _t1343 = 0.3e1*_t138;
  const double _t1344 = _hc3[1]*_t1313;
  const double _t1345 = _t1235*_t1322;
  const double _t1347 = _hc3[3]*_t1226;
  const double _t1348 = -_t142*_t889 - _t21*(_hc4[4]*_t587 + _hc4[4]*_t589 + _t1221*_t52 + _t1232*_t182 + _t1232*_t184 + _t1233*_t181 + _t1233*_t590 + _t1234) + _t547*_t892 + _t910;
  const double _t1351 = _hc5[37]*_t184;
  const double _t1352 = _hc5[37]*_t182;
  const double _t1353 = _hc5[101]*_t21;
  const double _t1354 = _hc3[1]*_hc5[81]*_t46 - _hc5[71]*_t741 - _hc5[75]*_t146 - _t1353;
  const double _t1355 = _hc5[104]*_t21;
  const double _t1356 = _hc3[1]*_hc5[84]*_t46 - _hc5[75]*_t741 - _hc5[78]*_t146 - _t1355;
  const double _t1357 = _hc5[31]*_t1240 + _hc5[34]*_t555 + _hc5[47]*_t80 + _t1238*_t52 - _t1245*_t21 + _t1351 + _t1352 - _t1354*_t741 - _t1356*_t146;
  const double _t1358 = _hc5[39]*_t184;
  const double _t1359 = _hc5[39]*_t182;
  const double _t1360 = _hc3[1]*_hc5[86]*_t46 - _hc5[106]*_t21 - _hc5[78]*_t741 - _hc5[80]*_t146;
  const double _t1361 = _hc5[34]*_t1240 + _hc5[36]*_t555 + _hc5[49]*_t80 + _t1239*_t52 - _t1246*_t21 - _t1356*_t741 + _t1358 + _t1359 - _t1360*_t146;
  const double _t1364 = -_hc5[12]*_t1349 - _hc5[14]*_t1350 + _hc5[15]*_t587 + _hc5[15]*_t589 + _t1241*_t52 + _t1242*_t182 + _t1242*_t184 + _t1243*_t181 + _t1243*_t590 + _t1248 - _t1357*_t741 - _t1361*_t146 + _t1362*_t554 + _t1363*_t551;
  const double _t1365 = 0.3e1*_t557;
  const double _t1366 = 0.3e1*_t147;
  const double _t1367 = _hc3[3]*_t558;
  const double _t1368 = _hc5[51]*_t80;
  const double _t1369 = _hc5[47]*_t184;
  const double _t1370 = _hc5[47]*_t182;
  const double _t1371 = _hc5[111]*_t21;
  const double _t1372 = _hc3[1]*_hc5[101]*_t46 - _hc5[91]*_t741 - _hc5[95]*_t146 - _t1371;
  const double _t1373 = _hc5[114]*_t21;
  const double _t1374 = _hc3[1]*_hc5[104]*_t46 - _hc5[95]*_t741 - _hc5[98]*_t146 - _t1373;
  const double _t1375 = _hc5[41]*_t1240 + _hc5[44]*_t555 + _t1245*_t52 - _t1254*_t21 + _t1368 + _t1369 + _t1370 - _t1372*_t741 - _t1374*_t146;
  const double _t1376 = _hc5[49]*_t184;
  const double _t1377 = _hc5[49]*_t182;
  const double _t1378 = _hc3[1]*_hc5[106]*_t46 - _hc5[100]*_t146 - _hc5[116]*_t21 - _hc5[98]*_t741;
  const double _t1379 = _hc5[44]*_t1240 + _hc5[46]*_t555 + _hc5[53]*_t80 + _t1246*_t52 - _t1255*_t21 - _t1374*_t741 + _t1376 + _t1377 - _t1378*_t146;
  const double _t1380 = -_t150*_t889 - _t21*(-_hc5[16]*_t1349 - _hc5[18]*_t1350 + _hc5[19]*_t587 + _hc5[19]*_t589 + _t1247*_t52 + _t1251*_t182 + _t1251*_t184 + _t1252*_t181 + _t1252*_t590 + _t1256 + _t1362*_t566 + _t1363*_t563 - _t1375*_t741 - _t1379*_t146) + _t568*_t892;
  const double _t1382 = _hc0[1]*_t1381;
  const double _t1383 = _hc0[2]*(_t173 * _t173);
  const double _t1384 = _hc0[4]*(_t47 * _t47 * _t47 * _t47);
  const double _t1385 = 0.3e1*_t576;
  const double _t1386 = 0.3e1*_t174;
  const double _t1387 = 0.3e1*_t176;
  const double _t1388 = 0.3e1*_t578;
  const double _t1396 = -_hc3[1]*_t1381;
  const double _t1397 = _hc3[2]*(_t181 * _t181);
  const double _t1398 = _hc3[4]*(_t46 * _t46 * _t46 * _t46);
  const double _t1402 = _t1235*_t1343;
  const double _t1403 = _hc5[16]*_t283;
  const double _t1404 = _hc5[12]*_t589;
  const double _t1405 = _hc5[12]*_t587;
  const double _t1406 = _hc5[12]*_t1235;
  const double _t1407 = 0.2e1*_t551;
  const double _t1408 = _hc5[41]*_t80;
  const double _t1409 = _hc5[31]*_t184;
  const double _t1410 = _hc5[31]*_t182;
  const double _t1411 = _hc5[91]*_t21;
  const double _t1412 = _hc5[95]*_t21;
  const double _t1413 = _hc3[1]*_hc5[75]*_t46 - _hc5[61]*_t741 - _hc5[65]*_t146 - _t1412;
  const double _t1414 = _hc5[44]*_t80;
  const double _t1415 = _hc5[34]*_t184;
  const double _t1416 = _hc5[34]*_t182;
  const double _t1417 = _hc5[98]*_t21;
  const double _t1418 = _hc3[1]*_hc5[78]*_t46 - _hc5[65]*_t741 - _hc5[68]*_t146 - _t1417;
  const double _t1419 = _hc5[25]*_t1240 + _hc5[28]*_t555 + _t1356*_t52 - _t1374*_t21 - _t1413*_t741 + _t1414 + _t1415 + _t1416 - _t1418*_t146;
  const double _t1420 = _hc5[14]*_t589;
  const double _t1421 = _hc5[14]*_t587;
  const double _t1422 = _hc5[14]*_t1235;
  const double _t1423 = _t1422*_t590;
  const double _t1424 = _t1422*_t181;
  const double _t1425 = 0.2e1*_t554;
  const double _t1426 = _hc5[36]*_t184;
  const double _t1427 = _hc5[36]*_t182;
  const double _t1428 = _t1235*_t1366;
  const double _t1429 = 0.3e1*_t112;
  const double _t1431 = _t1430*_t209;
  const double _t1432 = -_t1431;
  const double _t1435 = _hc2[44]*_t1434;
  const double _t1436 = _hc2[95]*_t634;
  const double _t1437 = _hc2[98]*_t634;
  const double _t1438 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[78]*_t11*_t33*_t64 - _hc2[28]*_t631 - _hc2[65]*_t638 - _hc2[68]*_t201 - _t1437;
  const double _t1439 = _hc2[114]*_t634;
  const double _t1440 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[104]*_t11*_t33*_t64 - _hc2[44]*_t631 - _hc2[95]*_t638 - _hc2[98]*_t201 - _t1439;
  const double _t1441 = _hc2[104]*_t634;
  const double _t1442 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[84]*_t11*_t33*_t64 - _hc2[34]*_t631 - _hc2[75]*_t638 - _hc2[78]*_t201 - _t1441;
  const double _t1444 = _hc2[46]*_t1434;
  const double _t1445 = _hc2[68]*_t64;
  const double _t1446 = _hc2[100]*_t634;
  const double _t1447 = _hc2[116]*_t634;
  const double _t1448 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[106]*_t11*_t33*_t64 - _hc2[100]*_t201 - _hc2[46]*_t631 - _hc2[98]*_t638 - _t1447;
  const double _t1449 = _hc2[106]*_t634;
  const double _t1450 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[86]*_t11*_t33*_t64 - _hc2[36]*_t631 - _hc2[78]*_t638 - _hc2[80]*_t201 - _t1449;
  const double _t1451 = _hc2[53]*_t1434;
  const double _t1452 = _hc2[123]*_t634;
  const double _t1453 = _hc2[119]*_t634;
  const double _t1454 = (0.1e1 / 0.2e1)*_hc0[1]*_hc2[109]*_t11*_t33*_t64 - _hc2[104]*_t638 - _hc2[106]*_t201 - _hc2[49]*_t631 - _t1453;
  const double _t1455 = _hc2[49]*_t1434;
  const double _t1456 = _hc2[109]*_t634;
  const double _t1457 = 0.3e1*_t101;
  const double _t1458 = -_hc5[18]*_t1430*_t214;
  const double _t1459 = _t139*_t651;
  const double _t1460 = 0.2e1*_t656;
  const double _t1461 = _hc5[53]*_t649;
  const double _t1462 = _hc5[49]*_t694;
  const double _t1463 = _hc5[123]*_t215;
  const double _t1464 = _hc5[119]*_t215;
  const double _t1465 = _hc5[109]*_t653 - _t1464;
  const double _t1466 = _hc5[49]*_t649;
  const double _t1467 = _hc5[39]*_t694;
  const double _t1468 = _hc5[109]*_t215;
  const double _t1469 = 0.2e1*_t670;
  const double _t1470 = _t1166*_t221 + _t659;
  const double _t1471 = _t1141*_t221 - _t1441;
  const double _t1472 = _t1181*_t221 - _t1437;
  const double _t1473 = _t2*_t664;
  const double _t1474 = _t1185*_t221 - _t1439;
  const double _t1475 = _t1435 - _t1474*_t21;
  const double _t1476 = _t1151*_t221 - _t1449;
  const double _t1477 = _t2*_t665;
  const double _t1478 = _t1201*_t221 - _t1447;
  const double _t1479 = _t1444 - _t1478*_t21;
  const double _t1480 = _t1154*_t221 - _t1453;
  const double _t1481 = _t1451 - _t21*(_t1205*_t221 - _t1452);
  const double _t1482 = _t1149*_t221 - _t1456;
  const double _t1483 = _t1455 - _t1480*_t21;
  const double _t1484 = 0.2e1*_t681;
  const double _t1485 = _t46*_t651;
  const double _t1486 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[109]*_t14*_t46*_t69 - _hc5[104]*_t677 - _hc5[106]*_t224 - _hc5[49]*_t671 - _t1464;
  const double _t1487 = _t2*_t675;
  const double _t1488 = _t1487*_t214;
  const double _t1489 = _t1461 - _t21*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[119]*_t14*_t46*_t69 - _hc5[114]*_t677 - _hc5[116]*_t224 - _hc5[53]*_t671 - _t1463);
  const double _t1490 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[89]*_t14*_t46*_t69 - _hc5[39]*_t671 - _hc5[84]*_t677 - _hc5[86]*_t224 - _t1468;
  const double _t1491 = _t1466 - _t1486*_t21;
  const double _t1493 = _t21*(_t1303*_t221 + _t1304*_t221 + _t1480*_t48 + _t1481);
  const double _t1494 = _t1281*_t221 + _t1282*_t221 + _t1482*_t48 + _t1483;
  const double _t1495 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[84]*_t14*_t46*_t69 - _hc5[104]*_t215 - _hc5[34]*_t671 - _hc5[75]*_t677 - _hc5[78]*_t224;
  const double _t1496 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[86]*_t14*_t46*_t69 - _hc5[106]*_t215 - _hc5[36]*_t671 - _hc5[78]*_t677 - _hc5[80]*_t224;
  const double _t1499 = _hc5[14]*_t1497 + _hc5[34]*_t1498 + _hc5[36]*_t684 + _t1358*_t694 + _t1359*_t694 - _t146*_t1496 + _t1490*_t52 + _t1491 - _t1495*_t741 - _t554*_t671;
  const double _t1500 = 0.2e1*_t674;
  const double _t1501 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[104]*_t14*_t46*_t69 - _hc5[114]*_t215 - _hc5[44]*_t671 - _hc5[95]*_t677 - _hc5[98]*_t224;
  const double _t1502 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[106]*_t14*_t46*_t69 - _hc5[100]*_t224 - _hc5[116]*_t215 - _hc5[46]*_t671 - _hc5[98]*_t677;
  const double _t1503 = _t1458 - _t21*(_hc5[18]*_t1497 + _hc5[44]*_t1498 + _hc5[46]*_t684 + _t1376*_t694 + _t1377*_t694 - _t146*_t1502 + _t1486*_t52 + _t1489 - _t1501*_t741 - _t566*_t671) + _t300*_t678;
  const double _t1504 = 0.3e1*_t178;
  const double _t1505 = 0.3e1*_t185;
  const double _t1506 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[78]*_t14*_t46*_t69 - _hc5[28]*_t671 - _hc5[65]*_t677 - _hc5[68]*_t224 - _hc5[98]*_t215;
  const double _t1507 = _hc5[68]*_t69;
  const double _t1509 = _t12*_t980;
  const double _t1510 = -_t1509;
  const double _t1512 = _t12*_t990;
  const double _t1513 = _t12*_t993;
  const double _t1514 = _t12*_t994;
  const double _t1515 = _hc0[1]*_hc2[75]*_t12*_t33 - _hc2[61]*_t234 - _hc2[65]*_t702 - _t1514 - _t372;
  const double _t1516 = _t12*_t996;
  const double _t1517 = _hc0[1]*_hc2[101]*_t12*_t33 - _hc2[91]*_t234 - _hc2[95]*_t702 - _t1516 - _t375;
  const double _t1518 = _t12*_t998;
  const double _t1519 = _hc0[1]*_hc2[81]*_t12*_t33 - _hc2[71]*_t234 - _hc2[75]*_t702 - _t1518 - _t378;
  const double _t1521 = _t1000*_t12;
  const double _t1522 = _t1003*_t12;
  const double _t1523 = _t1005*_t12;
  const double _t1524 = _hc0[1]*_hc2[104]*_t12*_t33 - _hc2[95]*_t234 - _hc2[98]*_t702 - _t1523 - _t393;
  const double _t1525 = _t1007*_t12;
  const double _t1526 = _hc0[1]*_hc2[84]*_t12*_t33 - _hc2[75]*_t234 - _hc2[78]*_t702 - _t1525 - _t396;
  const double _t1527 = _t1010*_t12;
  const double _t1528 = _t1013*_t12;
  const double _t1529 = _t1015*_t12;
  const double _t1530 = _hc0[1]*_hc2[107]*_t12*_t33 - _hc2[101]*_t234 - _hc2[104]*_t702 - _t1529 - _t407;
  const double _t1531 = _t1018*_t12;
  const double _t1532 = _t1021*_t12;
  const double _t1533 = -_t1403*_t15;
  const double _t1534 = _t139*_t716;
  const double _t1535 = 0.2e1*_t721;
  const double _t1536 = _t1368*_t15;
  const double _t1537 = _t1253*_t15;
  const double _t1538 = _t1244*_t15;
  const double _t1539 = _hc5[107]*_t241 - _t1538;
  const double _t1540 = _t719*_t80;
  const double _t1541 = _hc5[37]*_t15;
  const double _t1542 = _t1237*_t15;
  const double _t1543 = 0.2e1*_t731;
  const double _t1544 = _t1167*_t12 + _t724;
  const double _t1545 = _t1139*_t12 - _t1518;
  const double _t1546 = _t1174*_t12 - _t1514;
  const double _t1547 = _t1178*_t12 - _t1516;
  const double _t1548 = _t1512 - _t1547*_t21;
  const double _t1549 = _t1141*_t12 - _t1525;
  const double _t1550 = _t1185*_t12 - _t1523;
  const double _t1551 = _t1521 - _t1550*_t21;
  const double _t1552 = _t1145*_t12 - _t1529;
  const double _t1553 = _t1527 - _t21*(_t1191*_t12 - _t1528);
  const double _t1554 = _t1137*_t12 - _t1532;
  const double _t1555 = _t1531 - _t1552*_t21;
  const double _t1556 = 0.2e1*_t737;
  const double _t1557 = _t46*_t716;
  const double _t1558 = _hc3[1]*_hc5[107]*_t15*_t46 - _hc5[101]*_t248 - _hc5[104]*_t732 - _t1538 - _t439;
  const double _t1559 = _t1536 - _t21*(_hc3[1]*_hc5[117]*_t15*_t46 - _hc5[111]*_t248 - _hc5[114]*_t732 - _t1537 - _t441);
  const double _t1560 = _hc3[1]*_hc5[87]*_t15*_t46 - _hc5[81]*_t248 - _hc5[84]*_t732 - _t1542 - _t445;
  const double _t1561 = _t1540 - _t1558*_t21;
  const double _t1562 = _t21*(_t12*_t1296 + _t12*_t1297 + _t1552*_t48 + _t1553);
  const double _t1563 = _t12*_t1278 + _t12*_t1279 + _t1554*_t48 + _t1555;
  const double _t1564 = _hc3[1]*_hc5[81]*_t15*_t46 - _hc5[71]*_t248 - _hc5[75]*_t732 - _t1353*_t15 - _t550;
  const double _t1565 = _hc3[1]*_hc5[84]*_t15*_t46 - _hc5[75]*_t248 - _hc5[78]*_t732 - _t1355*_t15 - _t553;
  const double _t1568 = _hc5[31]*_t1567 + _hc5[34]*_t1566 + _t1351*_t15 + _t1352*_t15 - _t146*_t1565 + _t1560*_t52 + _t1561 - _t1564*_t741 - _t552 + _t556;
  const double _t1569 = 0.2e1*_t733;
  const double _t1570 = _t1235*_t716;
  const double _t1571 = _hc3[1]*_hc5[101]*_t15*_t46 - _hc5[91]*_t248 - _hc5[95]*_t732 - _t1371*_t15 - _t561;
  const double _t1572 = _hc3[1]*_hc5[104]*_t15*_t46 - _hc5[95]*_t248 - _hc5[98]*_t732 - _t1373*_t15 - _t565;
  const double _t1573 = _t1533 - _t21*(_hc5[41]*_t1567 + _hc5[44]*_t1566 + _t1369*_t15 + _t1370*_t15 - _t146*_t1572 + _t1558*_t52 + _t1559 - _t1571*_t741 - _t564 + _t567) + _t300*_t734;
  const double _t1575 = _hc3[1]*_hc5[75]*_t15*_t46 - _hc5[61]*_t248 - _hc5[65]*_t732 - _t1412*_t15 - _t604;
  const double _t1581 = _hc2[106]*_t1580 - 0.1e1 / 0.24e2*_hc2[49]*_t11*_t19*_t256*_t6*_t7;
  const double _t1582 = _hc2[36]*_t34;
  const double _t1583 = _hc2[100]*_t1580 - 0.1e1 / 0.24e2*_hc2[46]*_t11*_t19*_t256*_t6*_t7;
  const double _t1585 = _hc2[34]*_t34;
  const double _t1586 = -0.1e1 / 0.24e2*_hc2[44]*_t11*_t19*_t256*_t6*_t7 + _hc2[98]*_t1580;
  const double _t1587 = _hc2[116]*_t1580;
  const double _t1590 = _hc2[18]*_t1588*_t1589 - 0.1e1 / 0.18e2*_hc2[46]*_t254*_t36*_t6*_t7*_t78;
  const double _t1591 = _t27*_t765;
  const double _t1593 = _hc5[106]*_t1592 - 0.1e1 / 0.24e2*_hc5[49]*_t14*_t19*_t263*_t6*_t7;
  const double _t1594 = _hc5[116]*_t1592;
  const double _t1597 = _hc5[14]*_t765;
  const double _t1598 = _hc5[18]*_t1589*_t1595;
  const double _t1599 = -0.1e1 / 0.18e2*_hc5[46]*_t261*_t54*_t6*_t7*_t78 + _t1598;
  const double _t1600 = (0.1e1 / 0.4e1)*_hc0[1]*_hc2[86]*_t254*_t36*_t47 - _t1581 - _t489*_t771;
  const double _t1601 = _t1590 + _t21*(_hc2[53]*_t1588*_t758 + (0.1e1 / 0.4e1)*_t1201*_t254*_t36 - _t1587 - _t495*_t771);
  const double _t1602 = (0.1e1 / 0.2e1)*_t1487;
  const double _t1607 = _t21*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[106]*_t261*_t46*_t54 - _hc5[100]*_t1603 + (0.1e1 / 0.3e1)*_hc5[18]*_t263*_t58 + (0.5e1 / 0.12e2)*_hc5[44]*_t228*_t263*tb - _hc5[46]*_t1604 - _hc5[49]*_t52*_t765 + (0.1e1 / 0.24e2)*_hc5[53]*_t14*_t19*_t263*_t6*_t7 - _hc5[98]*_t1606 - _t1594);
  const double _t1608 = (0.1e1 / 0.4e1)*_hc3[1]*_hc5[86]*_t261*_t46*_t54 + (0.1e1 / 0.3e1)*_hc5[14]*_t263*_t58 + (0.5e1 / 0.12e2)*_hc5[34]*_t228*_t263*tb - _hc5[36]*_t1604 - _hc5[39]*_t52*_t765 - _hc5[78]*_t1606 - _hc5[80]*_t1603 - _t1593;
  const double _t1609 = _hc5[36]*_t52;
  const double _t1610 = _hc5[34]*_t52;
  const double _t1612 = _t629*_t64*_t787;
  const double _t1616 = _hc2[95]*_t1615;
  const double _t1617 = _hc2[98]*_t1615;
  const double _t1618 = _hc2[114]*_t1615;
  const double _t1619 = _hc2[104]*_t1615;
  const double _t1620 = _t629*_t69*_t793;
  const double _t1621 = (0.1e1 / 0.2e1)*_t796;
  const double _t1623 = _hc5[114]*_t1622;
  const double _t1626 = _t1625*_t27;
  const double _t1627 = _hc5[104]*_t1622;
  const double _t1628 = _t21*(_t1185*_t800 - _t1618);
  const double _t1629 = _t1141*_t800 - _t1619;
  const double _t1632 = (0.1e1 / 0.2e1)*_hc3[1]*_hc5[84]*_t271*_t46*_t69 - _hc5[34]*_t1630 - _hc5[75]*_t1631 - _hc5[78]*_t803 - _t1627;
  const double _t1633 = _t1620 - _t21*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[104]*_t271*_t46*_t69 - _hc5[44]*_t1630 - _hc5[95]*_t1631 - _hc5[98]*_t803 - _t1623);
  const double _t1636 = _t117*_t990;
  const double _t1640 = _t117*_t993;
  const double _t1641 = _t117*_t994;
  const double _t1642 = _t117*_t996;
  const double _t1643 = _t117*_t998;
  const double _t1644 = _t1408*_t192;
  const double _t1645 = _hc5[31]*_t192;
  const double _t1646 = _t1371*_t192;
  const double _t1647 = _t1353*_t192;
  const double _t1648 = _t1139*_t117 - _t1643;
  const double _t1649 = _t1636 - _t21*(_t117*_t1178 - _t1642);
  const double _t1652 = _hc3[1]*_hc5[81]*_t192*_t46 - _hc5[31]*_t824 - _hc5[71]*_t1650 - _hc5[75]*_t1651 - _t1647;
  const double _t1653 = _t1644 - _t21*(_hc3[1]*_hc5[101]*_t192*_t46 - _hc5[41]*_t824 - _hc5[91]*_t1650 - _hc5[95]*_t1651 - _t1646);
  const double _t1655 = _t36*_t832;
  const double _t1656 = _t11*_t835;
  const double _t1657 = _hc2[30]*_t838;
  const double _t1658 = _hc2[68]*_t256;
  const double _t1661 = _hc2[100]*_t1660*_t837;
  const double _t1663 = _hc2[18]*_t11*_t1662*_t833;
  const double _t1666 = _t54*_t841;
  const double _t1667 = _t14*_t844;
  const double _t1668 = _hc5[30]*_t847;
  const double _t1669 = _hc5[100]*_t1660*_t846;
  const double _t1670 = _hc5[18]*_t14*_t1662*_t842;
  const double _t1675 = _hc5[68]*_t263;
  const double _t1677 = _t232*_t850;
  const double _t1678 = _t267*_t852;
  const double _t1679 = _hc2[65]*_t1635;
  const double _t1681 = -0.1e1 / 0.24e2*_hc2[44]*_t19*_t256*_t267*_t6*_t7 + _hc2[98]*_t232*_t254*_t758;
  const double _t1682 = _t246*_t855;
  const double _t1683 = _t271*_t857;
  const double _t1685 = -0.1e1 / 0.24e2*_hc5[44]*_t19*_t263*_t271*_t6*_t7 + _hc5[98]*_t246*_t261*_t758;
  const double _t1686 = _hc5[65]*_t1654;
  const double _t1687 = _t353*_t860;
  const double _t1688 = _hc2[61]/xc_powr(na, 22, 3);
  const double _t1689 = _hc2[95]*_t353*_t788;
  const double _t1690 = _t592*_t863;
  const double _t1691 = _hc5[95]*_t592*_t794;
  const double _t1692 = _hc5[61]/xc_powr(nb, 22, 3);
  const double _t1693 = _t625*_t993;
  const double _t1694 = _t1411*_t690;
  const double d4F_dna4 = _t3*(my_piecewise3(_t16, 0, _hc1[0]*((0.6160e4 / 0.81e2)*_hc2[1]*_t785 + _hc2[4]*_t933 + _hc2[4]*_t934 + _hc2[4]*_t935 + _hc2[4]*_t939 + (0.28e2 / 0.3e1)*_t10*_t117*_t400 + (0.40e2 / 0.3e1)*_t113*_t382*ta + (0.3640e4 / 0.81e2)*_t116*_t697 - 0.440e3 / 0.9e1*_t123*_t353*ta - _t130*_t889 + _t134*_t948 - _t21*(-_hc2[16]*_t979 - _hc2[18]*_t1024 + _hc2[19]*_t331 + _hc2[19]*_t333 - _t1017*_t705 - _t1046*_t41 + _t1053 + _t1054*_t296 + _t1054*_t86 + _t1062*_t34 - _t21*(_hc2[51]*_t989 + _hc2[53]*_t385 + _hc2[54]*_t105 + _hc2[54]*_t107 - _t1014*_t705 - _t1043*_t41 + _t1055 + _t1058*_t34 - _t21*(_hc0[1]*_hc2[124]*_t33 - _hc2[121]*_t705 - _hc2[123]*_t41 - _t1056)) + _t300*_t406 + _t339*(_hc0[1]*_hc2[50]*_t336 - _t409) + _t340*_t410 + _t377*_t987 + _t395*_t988) - 0.280e3 / 0.9e1*_t232*_t361 + _t296*_t973 + _t34*(-_hc2[12]*_t979 - _hc2[14]*_t1024 + _hc2[15]*_t331 + _hc2[15]*_t333 - _t1023*_t705 - _t1052*_t41 - _t1062*_t21 + _t1063 + _t1064*_t296 + _t1064*_t86 + _t300*_t410 + _t339*_t974 + _t34*(_hc2[37]*_t989 + _hc2[39]*_t385 + _hc2[40]*_t105 + _hc2[40]*_t107 - _t1022*_t705 - _t1051*_t41 - _t1061*_t21 + _t1065 + _t34*(_hc0[1]*_hc2[90]*_t33 - _hc2[87]*_t705 - _hc2[89]*_t41 - _t1066)) + _t340*_t415 + _t381*_t987 + _t399*_t988) + _t358*_t936 + _t358*_t937 + _t363*_t947 - _t41*(-_hc2[11]*_t1024 - _hc2[9]*_t979 - _t1009*_t705 + _t1025 + _t1026 + _t1027 + _t1029 + _t1030 - _t1046*_t21 + _t1052*_t34 + _t300*_t395 + _t339*(_hc0[1]*_hc2[39]*_t336 - _t398) + _t340*_t399 + _t374*_t987 + _t392*_t988 - _t41*(_hc2[28]*_t989 + _hc2[30]*_t385 - _t1004*_t705 + _t1031 + _t1032 + _t1033 - _t1036*_t21 + _t1038*_t34 - _t41*(_hc0[1]*_hc2[80]*_t33 - _hc2[68]*_t705 - _hc2[70]*_t41 - _t1034))) + _t411*_t892 + _t420*_t956 - _t705*(-_hc2[6]*_t979 - _t1009*_t41 - _t1017*_t21 + _t1023*_t34 - _t235*_t356 + _t300*_t377 + _t339*_t978 + _t340*_t381 + _t370*_t987 + _t374*_t988 - _t705*(_hc2[21]*_t989 + _hc2[25]*_t385 - _t21*_t997 + _t34*_t999 - _t41*_t995 - _t705*(_hc0[1]*_hc2[71]*_t33 - _hc2[56]*_t705 - _hc2[61]*_t41 - _t993) + _t990 + _t991 + _t992) + _t981 + _t982 + _t983 + _t985 + _t986) + _t86*_t973 + _t941*_t972 + _t944*_t972 + _t946*_t972 + _t955*(_hc2[15]*_t951 + _t20*((0.5e1 / 0.18e2)*_hc2[47]*_t975 - 0.1e1 / 0.6e1*_hc2[50]*_t337 + (0.1e1 / 0.36e2)*_hc2[54]*_t20 + _t40*_t977) + _t337*_t974 + _t40*((0.16e2 / 0.9e1)*_hc2[36]*_t40 - 0.4e1 / 0.3e1*_hc2[39]*_t337 + _t20*_t977 + _t975*_t976) + _t419 - _t705*_t978) + _t971) + _hc2[0]*(_hc1[1]*_t933 + _hc1[1]*_t934 + _hc1[1]*_t935 + _hc1[1]*_t939 - _t109*_t889 + _t111*_t948 - _t21*(_hc1[4]*_t331 + _hc1[4]*_t333 - _t21*(_hc1[8]*_t105 + _hc1[8]*_t107 - _t21*(_hc1[13]*_t34 + _t960) + _t34*_t962 + _t959) + _t296*_t958 + _t300*_t343 + _t339*(_t344 + _t954) + _t34*_t966 + _t340*_t345 + _t86*_t958 + _t957) + _t296*_t950 + _t334*_t936 + _t334*_t937 + _t338*_t947 + _t34*(_hc1[3]*_t331 + _hc1[3]*_t333 - _t21*_t966 + _t296*_t968 + _t300*_t345 + _t339*_t952 + _t34*(_hc1[6]*_t105 + _hc1[6]*_t107 - _t21*_t965 + _t34*(_hc1[10]*_t34 + _t970) + _t969) + _t340*_t348 + _t86*_t968 + _t967) + _t346*_t892 + _t351*_t956 + _t86*_t950 + _t932 + _t941*_t942 + _t942*_t944 + _t942*_t946 + _t955*(_hc1[3]*_t951 + _t20*(-_t953 - 0.1e1 / 0.6e1*_t954) + _t337*_t952 + _t350)) + 0.6e1*_t112*_t135 + 0.4e1*_t35*_t421 + 0.4e1*_t352*_t43) + my_piecewise3(_t17, 0, _hc4[0]*(_hc5[4]*_t875 + _hc5[4]*_t876 + _hc5[4]*_t877 - _t21*(_hc5[19]*_t290 + _hc5[19]*_t292 - _t21*(_hc5[54]*_t88 + _hc5[54]*_t90 - _t21*(_hc5[124]*_t27 - _t898) + _t27*_t900 + _t897) + _t27*_t904 + _t297*_t895 + _t300*_t304 + _t87*_t895 + _t88*_t896 + _t894 + _t896*_t90) + _t27*(_hc5[15]*_t290 + _hc5[15]*_t292 - _t21*_t904 + _t27*(_hc5[40]*_t88 + _hc5[40]*_t90 - _t21*_t903 + _t27*(_hc5[90]*_t27 - _t909) + _t908) + _t297*_t906 + _t300*_t306 + _t87*_t906 + _t88*_t907 + _t90*_t907 + _t905) + _t290*_t890 + _t292*_t890 + _t297*_t891 + _t298*_t881 + _t298*_t882 + _t307*_t892 + _t427*_t883 + _t429*_t883 + _t87*_t887 + _t87*_t891 + _t871 + _t88*_t893 + _t886*_t887 - _t889*_t92 + _t893*_t90) + _hc5[0]*(_hc4[1]*_t875 + _hc4[1]*_t876 + _hc4[1]*_t877 + _t140*_t881 + _t140*_t882 - _t21*(_hc4[4]*_t290 + _hc4[4]*_t292 - _t21*(_hc4[8]*_t88 + _hc4[8]*_t90 - _t21*(_hc4[13]*_t27 + _t920) + _t27*_t922 + _t919) + _t27*_t926 + _t297*_t917 + _t300*_t317 + _t87*_t917 + _t88*_t918 + _t90*_t918 + _t916) + _t27*(_hc4[3]*_t290 + _hc4[3]*_t292 - _t21*_t926 + _t27*(_hc4[6]*_t88 + _hc4[6]*_t90 - _t21*_t925 + _t27*(_hc4[10]*_t27 + _t931) + _t930) + _t297*_t928 + _t300*_t319 + _t87*_t928 + _t88*_t929 + _t90*_t929 + _t927) + _t290*_t913 + _t292*_t913 + _t297*_t914 + _t320*_t892 + _t427*_t911 + _t429*_t911 + _t87*_t912 + _t87*_t914 + _t88*_t915 + _t886*_t912 - _t889*_t98 + _t90*_t915 + _t910) + 0.6e1*_t101*_t95 + 0.4e1*_t28*_t325 + 0.4e1*_t30*_t312)) + 0.4e1*_t326 + 0.4e1*_t422;
  const double d4F_dna3_dnb = _t3*(my_piecewise3(_t16, 0, _hc1[0]*(_hc2[4]*_t1108 + _hc2[4]*_t1133 - _t1024*_t167 - _t1083*_t130 + _t1117*_t134 + _t1121*_t358 + _t1123*_t1210 + _t1125*_t134 + _t1126*_t363 + _t1132*_t1214 + _t1134*_t134 + _t1209*_t296 + _t1209*_t86 + _t1213*_t296 + _t1213*_t86 + _t1215 + _t156*_t420 + _t157*_t420 + _t162*_t331 - _t164*_t979 - _t168*_t283 - _t21*(_hc2[19]*_t1109 + _hc2[19]*_t453 + _hc2[19]*_t458 + _t105*_t500 + _t1053 + _t1054*_t295 + _t107*_t1211 + _t1161*_t34 - _t1194*_t705 - _t1208*_t41 + _t156*_t410 + _t157*_t410 - _t21*(_hc2[54]*_t156 + _hc2[54]*_t157 + _t1159*_t34 - _t1192*_t705 - _t1206*_t41 + _t1212) + _t385*_t496 + _t406*_t80 + _t484*_t989 + _t502*_t80) + _t330*_t534 + _t333*_t472 + _t339*(_hc2[15]*_t1118 + _t1136*_t337 + _t1165 - _t1168*_t705 + _t40*((0.2e1 / 0.9e1)*_hc2[49]*_t19*_t6*_t7 - 0.4e1 / 0.3e1*_t1166) + _t509) + _t34*(_hc2[15]*_t1109 + _hc2[15]*_t453 + _hc2[15]*_t458 + _t105*_t507 + _t1063 + _t1064*_t295 + _t107*_t1136 - _t1148*_t705 - _t1157*_t41 - _t1161*_t21 + _t156*_t415 + _t157*_t415 + _t34*(_hc2[40]*_t156 + _hc2[40]*_t157 - _t1138*_t705 - _t1150*_t41 + _t1162*_t34 + _t1163) + _t385*_t490 + _t410*_t80 + _t475*_t989 + _t500*_t80) + _t340*_t510 + _t358*_t452 - _t41*(_t1025 + _t1028*_t295 + _t105*_t490 + _t107*_t1198 + _t1157*_t34 - _t1188*_t705 + _t1195 + _t1196 + _t1197 - _t1208*_t21 + _t156*_t399 + _t157*_t399 + _t385*_t493 + _t395*_t80 - _t41*(_hc2[36]*_t157 + _t1152*_t34 - _t1182*_t705 + _t1200 + _t1203 - _t41*(-_t1034 + _t1199)) + _t480*_t989 + _t496*_t80) + _t411*_t80 + _t486*_t987 + _t498*_t988 - _t705*(_t105*_t475 + _t107*_t1168 + _t1148*_t34 + _t1169 + _t1170 + _t1171 + _t1172 - _t1188*_t41 - _t1194*_t21 + _t156*_t381 + _t157*_t381 + _t377*_t80 + _t385*_t480 + _t477*_t989 + _t484*_t80 - _t705*(_t1140*_t34 - _t1175*_t41 + _t1176 + _t1177 + _t1180 - _t705*(_t1173 - _t993)) + _t981) + _t885*_t972) + _hc2[0]*(_hc1[1]*_t1108 + _hc1[1]*_t1133 - _t1083*_t109 + _t111*_t1117 + _t111*_t1125 + _t111*_t1134 + _t1121*_t334 + _t1122*_t296 + _t1122*_t86 + _t1123*_t1124 + _t1126*_t338 + _t1130*_t296 + _t1130*_t86 + _t1131*_t1132 + _t1135 + _t154*_t331 + _t156*_t351 + _t157*_t351 - _t158*_t283 - _t21*(_hc1[4]*_t1109 + _hc1[4]*_t453 + _hc1[4]*_t458 + _t105*_t461 + _t107*_t1127 + _t1114*_t34 + _t156*_t345 + _t157*_t345 - _t21*(_hc1[8]*_t156 + _hc1[8]*_t157 + _t1112*_t34 + _t1128) + _t295*_t958 + _t343*_t80 + _t462*_t80 + _t957) + _t330*_t521 + _t333*_t460 + _t334*_t452 + _t339*(_hc1[3]*_t1118 + _t1110*_t337 + _t1120 + _t466) + _t34*(_hc1[3]*_t1109 + _hc1[3]*_t453 + _hc1[3]*_t458 + _t105*_t465 + _t107*_t1110 - _t1114*_t21 + _t156*_t348 + _t157*_t348 + _t295*_t968 + _t34*(_hc1[6]*_t156 + _hc1[6]*_t157 + _t1115*_t34 + _t1116) + _t345*_t80 + _t461*_t80 + _t967) + _t340*_t468 + _t346*_t80 + _t885*_t942) + _t1106*_t112 + _t1107*_t135 + _t327*_t469 + _t328*_t511 + _t352*_t49 + _t421*_t50) + my_piecewise3(_t17, 0, _hc4[0]*(_hc5[4]*_t1070 - _hc5[4]*_t1089 + _t1079*_t298 + _t1081*_t148 - _t1083*_t92 - _t1088*_t94 - _t1090*_t883 + _t1092*_t297 + _t1092*_t87 + _t1093*_t427 + _t1093*_t429 + _t1094*_t297 + _t1094*_t87 + _t1095 + _t1096*_t88 + _t1096*_t90 - _t141*_t311 + _t147*_t290 + _t147*_t292 - _t150*_t283 - _t21*(_hc5[19]*_t426 + _t1097*_t427 + _t1097*_t429 + _t1102*_t27 - _t141*_t306 - _t21*(-_hc5[54]*_t141 + _hc5[54]*_t430 + _t1098*_t27 + _t1099) - _t295*_t895 + _t304*_t80 + _t306*_t430 + _t440*_t88 + _t440*_t90 + _t442*_t80 + _t894) + _t27*(_hc5[15]*_t426 - _t1102*_t21 + _t1103*_t427 + _t1103*_t429 - _t141*_t310 + _t27*(-_hc5[40]*_t141 + _hc5[40]*_t430 + _t1104*_t27 + _t1105) - _t295*_t906 + _t306*_t80 + _t310*_t430 + _t440*_t80 + _t446*_t88 + _t446*_t90 + _t905) + _t289*_t560 + _t298*_t425 + _t301*_t426 + _t307*_t80 + _t311*_t430 + _t871 - _t885*_t887) + _hc5[0]*(_hc4[1]*_t1070 - _hc4[1]*_t1089 - _t100*_t1088 + _t1078*_t88 + _t1078*_t90 + _t1079*_t140 + _t1080*_t297 + _t1080*_t87 + _t1081*_t428 + _t1082*_t427 + _t1082*_t429 - _t1083*_t98 + _t1086*_t297 + _t1086*_t87 - _t1090*_t911 + _t1091 + _t138*_t290 + _t138*_t292 + _t140*_t425 - _t141*_t324 - _t142*_t283 - _t21*(_hc4[4]*_t426 + _t1075*_t27 + _t1084*_t427 + _t1084*_t429 - _t141*_t319 - _t21*(-_hc4[8]*_t141 + _hc4[8]*_t430 + _t1073*_t27 + _t1085) - _t295*_t917 + _t317*_t80 + _t319*_t430 + _t431*_t88 + _t431*_t90 + _t432*_t80 + _t916) + _t27*(_hc4[3]*_t426 + _t1071*_t427 + _t1071*_t429 - _t1075*_t21 - _t141*_t323 + _t27*(-_hc4[6]*_t141 + _hc4[6]*_t430 + _t1076*_t27 + _t1077) - _t295*_t928 + _t319*_t80 + _t323*_t430 + _t431*_t80 + _t435*_t88 + _t435*_t90 + _t927) + _t289*_t546 + _t314*_t426 + _t320*_t80 + _t324*_t430 - _t885*_t912) + _t101*_t1068 + _t1067*_t95 + _t279*_t449 + _t280*_t438 + _t312*_t53 + _t325*_t60)) + _t423 + 0.3e1*_t450 + 0.3e1*_t512;
  const double d4F_dna2_dnb2 = _t3*(my_piecewise3(_t16, 0, _hc1[0]*(_hc2[4]*_t1268 + _t105*_t526 + _t107*_t1287 - _t1083*_t168 + _t1087*_t1209 + _t1087*_t1213 + _t1117*_t162 + _t1125*_t162 + _t1126*_t472 + _t1210*_t1271 + _t1214*_t1231 + _t1215 + _t1261*_t363 + _t1265*_t972 + _t1269*_t134 + _t1270*_t470 + _t1272*_t534 + _t1275*_t134 + _t1276 - _t130*_t283 - _t134*_t516 - _t134*_t518 - _t21*(_hc2[19]*_t1261 - _hc2[19]*_t516 - _hc2[19]*_t518 + _t1054*_t173 + _t1285*_t34 - _t1298*_t705 - _t1305*_t41 + _t1307*_t295 + _t1308 + _t500*_t519 + _t500*_t520) - _t294*_t358 + _t34*(_hc2[15]*_t1261 - _hc2[15]*_t516 - _hc2[15]*_t518 + _t1064*_t173 + _t1277*_t34 - _t1280*_t705 - _t1283*_t41 + _t1284*_t295 + _t1286 + _t507*_t519 + _t507*_t520) - _t358*_t880 + _t385*_t533 - _t41*(_hc2[14]*_t1261 - _hc2[14]*_t516 - _hc2[14]*_t518 + _t1028*_t173 + _t1283*_t34 - _t1293*_t705 + _t1302*_t295 + _t1306 - _t41*(_t1152*_t48 + _t1203 + _t1300 + _t1301) + _t490*_t519 + _t490*_t520) + _t510*_t519 + _t510*_t520 + _t529*_t989 + _t535*_t80 - _t705*(_hc2[12]*_t1261 + _t1280*_t34 - _t1288 - _t1293*_t41 - _t1294 + _t1295*_t295 + _t1299 + _t173*_t984 + _t475*_t519 + _t475*_t520 - _t705*(_t1140*_t48 + _t1180 + _t1289 + _t1290))) + _hc2[0]*(_hc1[1]*_t1268 + _t105*_t515 + _t107*_t1267 - _t1083*_t158 + _t1087*_t1122 + _t1087*_t1130 - _t109*_t283 + _t111*_t1269 + _t111*_t1275 - _t111*_t516 - _t111*_t518 + _t1117*_t154 + _t1124*_t1271 + _t1125*_t154 + _t1126*_t460 + _t1131*_t1231 + _t1135 + _t1259 + _t1261*_t338 + _t1265*_t942 + _t1270*_t456 + _t1272*_t521 - _t21*(_hc1[4]*_t1261 - _hc1[4]*_t516 - _hc1[4]*_t518 + _t1263*_t34 + _t1273*_t295 + _t1274 + _t173*_t958 + _t461*_t519 + _t461*_t520) - _t294*_t334 - _t334*_t880 + _t34*(_hc1[3]*_t1261 - _hc1[3]*_t516 - _hc1[3]*_t518 + _t1260*_t34 + _t1262*_t295 + _t1264 + _t173*_t968 + _t465*_t519 + _t465*_t520) + _t468*_t519 + _t468*_t520 + _t522*_t80) + _t103*_t537 + _t112*_t177 + _t135*_t178 + 0.4e1*_t160*_t170 + _t172*_t511 + 0.2e1*_t43*_t524 + 0.2e1*_t469*_t49) + my_piecewise3(_t17, 0, _hc4[0]*(_hc5[4]*_t1223 - _t1083*_t150 - _t1087*_t1092 - _t1087*_t1094 + _t1095 + _t1096*_t430 + _t1224*_t94 + _t1225*_t558 + _t1227*_t558 + _t1228*_t560 + _t1231*_t1250 - _t1236*_t94 + _t1249*_t427 + _t1249*_t429 + _t1257 + _t181*_t887 - _t21*(_hc5[19]*_t540 + _hc5[19]*_t542 + _hc5[19]*_t545 + _t1247*_t27 + _t1251*_t430 - _t1252*_t295 + _t1256 + _t181*_t895 - _t440*_t543) + _t27*(_hc5[15]*_t540 + _hc5[15]*_t542 + _hc5[15]*_t545 + _t1241*_t27 + _t1242*_t430 - _t1243*_t295 + _t1248 + _t181*_t906 - _t446*_t543) - _t283*_t92 + _t294*_t298 + _t298*_t880 + _t426*_t559 - _t448*_t543 + _t540*_t94 + _t542*_t94 + _t545*_t94 + _t557*_t88 + _t557*_t90 + _t568*_t80) + _hc5[0]*(_hc4[1]*_t1223 + _t100*_t1224 - _t100*_t1236 + _t100*_t540 + _t100*_t542 + _t100*_t545 + _t1078*_t430 - _t1080*_t1087 - _t1083*_t142 - _t1086*_t1087 + _t1091 + _t1217 + _t1225*_t1226 + _t1226*_t1227 + _t1228*_t546 + _t1229*_t427 + _t1229*_t429 + _t1230*_t1231 + _t140*_t294 + _t140*_t880 + _t181*_t912 - _t21*(_hc4[4]*_t540 + _hc4[4]*_t542 + _hc4[4]*_t545 + _t1221*_t27 + _t1232*_t430 - _t1233*_t295 + _t1234 + _t181*_t917 - _t431*_t543) + _t27*(_hc4[3]*_t540 + _hc4[3]*_t542 + _hc4[3]*_t545 + _t1218*_t27 + _t1219*_t430 - _t1220*_t295 + _t1222 + _t181*_t928 - _t435*_t543) - _t283*_t98 + _t426*_t544 - _t437*_t543 + _t539*_t88 + _t539*_t90 + _t547*_t80) + _t101*_t197 + 0.4e1*_t144*_t152 + _t180*_t449 + _t185*_t95 + 0.2e1*_t28*_t549 + 0.2e1*_t438*_t60 + _t570*_t77)) + 0.2e1*_t450 + 0.2e1*_t512 + 0.2e1*_t538 + 0.2e1*_t571;
  const double d4F_dna_dnb3 = _t3*(my_piecewise3(_t16, 0, _hc1[0]*(_hc2[4]*_t1311 + _t1209*_t1316 + _t1210*_t1312 + _t1213*_t173 + _t1213*_t581 + _t1214*_t1319 + _t1276 - _t1310*_t162 - _t1313*_t534 - _t1314*_t162 + _t1315*_t526 + _t1317*_t472 + _t1318*_t526 + _t1322*_t1334 + _t1324*_t34 + _t1333*_t885 + _t1335 - _t285*_t534 + _t358*_t575 - _t41*(_t1198*_t580 + _t1283*_t48 + _t1306 + _t1329 + _t1330 + _t1331 + _t1332 + _t490*_t579) - _t705*(_t1168*_t580 + _t1280*_t48 + _t1299 + _t1325 + _t1326 + _t1327 + _t1328 + _t475*_t579)) + _hc2[0]*(_hc1[1]*_t1311 + _t1122*_t1316 + _t1124*_t1312 + _t1130*_t173 + _t1130*_t581 + _t1131*_t1319 + _t1259 + _t1309*_t34 - _t1310*_t154 - _t1313*_t521 - _t1314*_t154 + _t1315*_t515 + _t1317*_t460 + _t1318*_t515 + _t1320*_t885 + _t1321*_t1322 + _t1323 - _t285*_t521 + _t334*_t575) + _t1106*_t178 + _t1107*_t177 + _t35*_t582 + _t43*_t583 + _t524*_t573 + _t537*_t572) + my_piecewise3(_t17, 0, _hc4[0]*(-_hc5[4]*_t1337 + _hc5[4]*_t1339 + _t1092*_t181 + _t1092*_t590 + _t1094*_t1342 - _t1250*_t1346 + _t1257 + _t1313*_t560 + _t1338*_t147 - _t1340*_t557 + _t1344*_t147 - _t1345*_t147 + _t1364*_t27 + _t1365*_t430 + _t1366*_t542 - _t1367*_t885 + _t1380 + _t285*_t560 + _t298*_t574) + _hc5[0]*(-_hc4[1]*_t1337 + _hc4[1]*_t1339 + _t1080*_t1342 + _t1086*_t181 + _t1086*_t590 + _t1217 - _t1230*_t1346 + _t1313*_t546 + _t1336*_t27 + _t1338*_t138 - _t1340*_t539 + _t1341*_t430 + _t1343*_t542 + _t1344*_t138 - _t1345*_t138 - _t1347*_t885 + _t1348 + _t140*_t574 + _t285*_t546) + _t1067*_t197 + _t1068*_t185 + _t28*_t591 + _t30*_t620 + _t549*_t585 + _t570*_t586)) + 0.3e1*_t538 + 0.3e1*_t571 + _t622;
  const double d4F_dnb4 = _t3*(my_piecewise3(_t16, 0, _hc1[0]*(_hc2[4]*_t1382 + _hc2[4]*_t1383 + _hc2[4]*_t1384 + _t1214*_t1391 + _t1265*_t1333 + _t1287*_t1387 + _t1316*_t1334 + _t1324*_t48 + _t1333*_t1392 + _t1333*_t1393 + _t1334*_t1395 + _t1335 + _t1385*_t162 + _t1386*_t526 + _t1388*_t472 + _t1390*_t534 + _t1394*_t534) + _hc2[0]*(_hc1[1]*_t1382 + _hc1[1]*_t1383 + _hc1[1]*_t1384 + _t1131*_t1391 + _t1265*_t1320 + _t1267*_t1387 + _t1309*_t48 + _t1316*_t1321 + _t1320*_t1392 + _t1320*_t1393 + _t1321*_t1395 + _t1323 + _t1385*_t154 + _t1386*_t515 + _t1388*_t460 + _t1390*_t521 + _t1394*_t521) + 0.6e1*_t177*_t178 + 0.4e1*_t49*_t583 + 0.4e1*_t50*_t582) + my_piecewise3(_t17, 0, _hc4[0]*((0.6160e4 / 0.81e2)*_hc5[1]*_t806 + _hc5[4]*_t1396 + _hc5[4]*_t1397 + _hc5[4]*_t1398 + _t1250*_t1399 + (0.28e2 / 0.3e1)*_t13*_t192*_t615 + _t1364*_t52 + _t1365*_t182 + _t1365*_t184 + _t1366*_t587 + _t1366*_t589 + _t1367*_t1400 + _t1367*_t181 + _t1367*_t590 + _t1380 + _t1389*_t560 + _t1401*_t560 + _t1428*_t181 + _t1428*_t590 - _t146*(-_hc5[11]*_t1350 - _hc5[18]*_t283 - _hc5[9]*_t1349 + _t1361*_t52 + _t1362*_t614 + _t1363*_t606 - _t1379*_t21 - _t1419*_t741 + _t1420 + _t1421 + _t1423 + _t1424 + _t1425*_t182 + _t1425*_t184 - _t146*(_hc5[28]*_t1240 + _hc5[30]*_t555 + _hc5[46]*_t80 + _t1360*_t52 - _t1378*_t21 - _t1418*_t741 + _t1426 + _t1427 - _t146*(_hc3[1]*_hc5[80]*_t46 - _hc5[100]*_t21 - _hc5[68]*_t741 - _hc5[70]*_t146)) + _t300*_t566) - 0.440e3 / 0.9e1*_t188*_t592*tb + (0.40e2 / 0.3e1)*_t194*_t607*tb - 0.280e3 / 0.9e1*_t246*_t616 + (0.3640e4 / 0.81e2)*_t57*_t744 - _t741*(-_hc5[6]*_t1349 + _t1357*_t52 + _t1362*_t606 + _t1363*_t602 - _t1375*_t21 - _t1403 + _t1404 + _t1405 + _t1406*_t181 + _t1406*_t590 + _t1407*_t182 + _t1407*_t184 - _t1419*_t146 - _t249*_t595 + _t300*_t563 - _t741*(_hc5[21]*_t1240 + _hc5[25]*_t555 + _t1354*_t52 - _t1372*_t21 + _t1408 + _t1409 + _t1410 - _t1413*_t146 - _t741*(_hc3[1]*_hc5[71]*_t46 - _hc5[56]*_t741 - _hc5[61]*_t146 - _t1411))) + _t871) + _hc5[0]*(_hc4[1]*_t1396 + _hc4[1]*_t1397 + _hc4[1]*_t1398 + _t1230*_t1399 + _t1336*_t52 + _t1341*_t182 + _t1341*_t184 + _t1343*_t587 + _t1343*_t589 + _t1347*_t1400 + _t1347*_t181 + _t1347*_t590 + _t1348 + _t1389*_t546 + _t1401*_t546 + _t1402*_t181 + _t1402*_t590) + 0.6e1*_t185*_t197 + 0.4e1*_t53*_t620 + 0.4e1*_t591*_t60)) + 0.4e1*_t584 + 0.4e1*_t621;
  const double d4F_dna3_dgaa = _t3*my_piecewise3(_t16, 0, _hc1[0]*(-0.140e3 / 0.27e2*_hc2[11]*_t784 + _t1026*_t221 + _t1027*_t221 + _t1029*_t221 + _t1030*_t221 + _t118*_t127*_t64 + _t1432 - 0.220e3 / 0.27e2*_t204*_t811 - _t21*(_hc2[18]*_t1443 + _hc2[44]*_t1433 + _hc2[46]*_t623 + _t1040*_t221 + _t1041*_t221 - _t1440*_t705 - _t1448*_t41 + _t1451 + _t1454*_t34 - _t21*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[119]*_t11*_t33*_t64 - _hc2[114]*_t638 - _hc2[116]*_t201 - _hc2[53]*_t631 - _t1452) - _t395*_t631) - 0.140e3 / 0.27e2*_t232*_t65 + _t300*_t642 + _t339*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[39]*_t11*_t336*_t64 - _t645) + _t34*(_hc2[14]*_t1443 + _hc2[36]*_t623 + _t1048*_t221 + _t1049*_t221 - _t1442*_t705 - _t1450*_t41 - _t1454*_t21 + _t1455 + _t34*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[89]*_t11*_t33*_t64 - _hc2[39]*_t631 - _hc2[84]*_t638 - _hc2[86]*_t201 - _t1456) - _t399*_t631 + _t626*_t976*ta) + _t340*_t646 - _t400*_t631 - _t41*(_hc2[11]*_t1443 + _hc2[28]*_t1433 + _hc2[30]*_t623 + _t1032*_t221 + _t1033*_t221 - _t1438*_t705 + _t1444 - _t1448*_t21 + _t1450*_t34 - _t392*_t631 - _t41*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[80]*_t11*_t33*_t64 - _hc2[30]*_t631 - _hc2[70]*_t201 - _t1445*_t633 - _t1446)) + _t636*_t987 + _t640*_t988 - _t705*(_hc2[25]*_t1433 + _hc2[28]*_t623 + _t1001*_t221 + _t1002*_t221 + _t1435 - _t1438*_t41 - _t1440*_t21 + _t1442*_t34 + _t203*_t624 - _t374*_t631 - _t705*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[75]*_t11*_t33*_t64 - _hc2[25]*_t631 - _hc2[61]*_t638 - _hc2[65]*_t201 - _t1436))) + _t1429*_t211 + _t200*_t352 + _t328*_t647) + 0.3e1*_t648;
  const double d4F_dna3_dgbb = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_t1458 + _t1459*_t297 + _t1459*_t87 + _t1460*_t88 + _t1460*_t90 - _t21*(_t1461 + _t1462*_t88 + _t1462*_t90 + _t1465*_t27 - _t21*(_hc5[119]*_t653 - _t1463)) + _t27*(-_t1465*_t21 + _t1466 + _t1467*_t88 + _t1467*_t90 + _t27*(_hc5[89]*_t653 - _t1468)) + _t290*_t651 + _t292*_t651 + _t300*_t654) + _t1457*_t219 + _t213*_t325 + _t279*_t657) + 0.3e1*_t658;
  const double d4F_dna2_dnb_dgaa = _t1469 + _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t1028*_t208*_t85 + _t105*_t660 + _t107*_t1470 + _t1195*_t221 + _t1196*_t221 + _t1197*_t221 + _t1432 + _t1443*_t167 + _t156*_t646 + _t157*_t646 - _t21*(_hc2[49]*_t1477 + _t1204*_t221 - _t1474*_t705 - _t1478*_t41 + _t1480*_t34 + _t1481 - _t496*_t631) + _t34*(_hc2[39]*_t1477 + _t1153*_t221 - _t1471*_t705 - _t1476*_t41 + _t1482*_t34 + _t1483 - _t490*_t631) + _t385*_t663 - _t41*(_hc2[36]*_t1477 + _t1200*_t221 - _t1472*_t705 + _t1476*_t34 + _t1479 - _t41*(_t1199*_t221 - _t1446) - _t493*_t631) - _t498*_t631 + _t642*_t80 + _t661*_t989 + _t667*_t80 - _t705*(_t11*_t1473*_t643 + _t1183*_t221 + _t1471*_t34 - _t1472*_t41 + _t1475 - _t480*_t631 - _t705*(_t1174*_t221 - _t1436))) + _t103*_t669 + _t112*_t222 + _t200*_t469 + _t211*_t451 + _t50*_t647) + _t648;
  const double d4F_dna2_dnb_dgbb = _t1484 + _t3*my_piecewise3(_t17, 0, _hc4[0]*(-_t139*_t217*_t85 - _t141*_t656 + _t1458 + _t1485*_t427 + _t1485*_t429 - _t21*(-_hc5[49]*_t1488 + _t1462*_t430 + _t1486*_t27 + _t1489) + _t27*(-_hc5[39]*_t1488 + _t1467*_t430 + _t1490*_t27 + _t1491) + _t426*_t651 + _t430*_t656 + _t654*_t80 + _t674*_t88 + _t674*_t90 + _t678*_t80) + _t101*_t230 + _t213*_t438 + _t219*_t424 + _t53*_t657 + _t680*_t77) + _t658;
  const double d4F_dna_dnb2_dgaa = _t1469 + _t3*my_piecewise3(_t16, 0, _hc1[0]*(-_hc0[1]*_hc2[14]*_t1492*_t208 + _hc0[1]*_t1494*_t33 + 0.4e1*_hc0[1]*_t2*_t660*_t83 + (0.1e1 / 0.2e1)*_hc0[2]*_hc2[14]*_t11*_t173*_t33*_t64 + 0.2e1*_hc0[2]*_hc2[14]*_t11*_t2*_t47*_t64*_t83 + 0.2e1*_hc0[2]*_t33*_t47*_t660 + (0.1e1 / 0.2e1)*_hc0[3]*_hc2[14]*_t11*_t175*_t336*_t64 - _t1431 - _t1493 - _t41*(_t1300*_t221 + _t1301*_t221 + _t1476*_t48 + _t1479) - _t533*_t631 + (0.4e1 / 0.9e1)*_t6*_t667*_t7*_t78 - _t666 - _t705*(_t1291*_t221 + _t1292*_t221 + _t1471*_t48 + _t1475)) + _t172*_t669 + _t178*_t211 + _t200*_t524 + _t222*_t451 + _t35*_t682) + _t683;
  const double d4F_dna_dnb2_dgbb = _t1484 + _t3*my_piecewise3(_t17, 0, _hc4[0]*(_hc3[1]*_t1492*_t217 + _t1224*_t651 - _t1422*_t214*_t85 + _t1499*_t27 + _t1500*_t430 + _t1503 + _t542*_t651 - _t543*_t674 + _t676) + _t180*_t680 + _t185*_t219 + _t213*_t549 + _t230*_t424 + _t30*_t695) + _t696;
  const double d4F_dnb3_dgaa = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t1329*_t221 + _t1330*_t221 + _t1331*_t221 + _t1332*_t221 + _t1432 + _t1470*_t580 - _t1493 + _t1494*_t48 + _t300*_t667 + _t579*_t660) + _t1504*_t222 + _t200*_t583 + _t572*_t682) + 0.3e1*_t683;
  const double d4F_dnb3_dgbb = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-0.140e3 / 0.27e2*_hc5[11]*_t805 + _t1362*_t688 + _t1363*_t686 + _t1420*_t694 + _t1421*_t694 + _t1423*_t694 + _t1424*_t694 - _t146*(_hc5[11]*_t1497 + _hc5[28]*_t1498 + _hc5[30]*_t684 + _hc5[46]*_t649 + _t1426*_t694 + _t1427*_t694 - _t146*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[80]*_t14*_t46*_t69 - _hc5[100]*_t215 - _hc5[30]*_t671 - _hc5[70]*_t224 - _t1507*_t672) + _t1496*_t52 - _t1502*_t21 - _t1506*_t741 - _t614*_t671) + _t1499*_t52 + _t1500*_t182 + _t1500*_t184 + _t1503 + _t191*_t193*_t69 - 0.220e3 / 0.27e2*_t227*_t825 - 0.140e3 / 0.27e2*_t246*_t70 - _t615*_t671 - _t741*(_hc5[25]*_t1498 + _hc5[28]*_t684 + _hc5[44]*_t649 + _t1415*_t694 + _t1416*_t694 - _t146*_t1506 + _t1495*_t52 - _t1501*_t21 + _t226*_t689 - _t606*_t671 - _t741*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[75]*_t14*_t46*_t69 - _hc5[25]*_t671 - _hc5[61]*_t677 - _hc5[65]*_t224 - _hc5[95]*_t215))) + _t1505*_t230 + _t213*_t591 + _t586*_t695) + 0.3e1*_t696;
  const double d4F_dna3_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*(-0.440e3 / 0.27e2*_hc2[6]*_t1508*ta + _t12*_t982 + _t12*_t983 + _t12*_t985 + _t12*_t986 + _t1510 - _t21*(_hc2[41]*_t1511 + _hc2[44]*_t1520 + _t1011*_t12 + _t1012*_t12 - _t1517*_t705 - _t1524*_t41 + _t1527 + _t1530*_t34 - _t21*(_hc0[1]*_hc2[117]*_t12*_t33 - _hc2[111]*_t234 - _hc2[114]*_t702 - _t1528 - _t404) + _t401 - _t403) - 0.280e3 / 0.27e2*_t235*_t811 + _t300*_t709 + _t339*(_hc0[1]*_hc2[37]*_t12*_t336 - _t711) + _t34*(_hc2[31]*_t1511 + _hc2[34]*_t1520 + _t1019*_t12 + _t1020*_t12 - _t1519*_t705 - _t1526*_t41 - _t1530*_t21 + _t1531 + _t34*(_hc0[1]*_hc2[87]*_t12*_t33 - _hc2[81]*_t234 - _hc2[84]*_t702 - _t1532 - _t412) - _t416 + _t418) + _t340*_t712 - _t355 + _t360 - _t383 - _t41*(_hc2[25]*_t1511 + _hc2[28]*_t1520 + _t1001*_t12 + _t1002*_t12 - _t1515*_t705 + _t1521 - _t1524*_t21 + _t1526*_t34 + _t384 - _t389 - _t41*(_hc0[1]*_hc2[78]*_t12*_t33 - _hc2[65]*_t234 - _hc2[68]*_t702 - _t1522 - _t390)) + _t704*_t987 - _t705*(_hc2[21]*_t1511 + _t12*_t991 + _t12*_t992 + _t1512 - _t1515*_t41 - _t1517*_t21 + _t1519*_t34 + _t364 - _t371 + _t700*_t813 - _t705*(_hc0[1]*_hc2[71]*_t12*_t33 - _hc2[56]*_t234 - _hc2[61]*_t702 - _t1513 - _t368)) + _t707*_t988) + _t1429*_t238 + _t328*_t713 + _t352*_t73) + 0.3e1*_t714;
  const double d4F_dna3_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_t1533 + _t1534*_t297 + _t1534*_t87 + _t1535*_t88 + _t1535*_t90 - _t21*(_t1536 + _t1539*_t27 - _t21*(_hc5[117]*_t241 - _t1537) + _t719*_t88 + _t719*_t90) + _t27*(-_t1539*_t21 + _t1540 + _t1541*_t88 + _t1541*_t90 + _t27*(_hc5[87]*_t241 - _t1542)) + _t290*_t716 + _t292*_t716 + _t300*_t718) + _t1457*_t242 + _t279*_t722 + _t325*_t75) + 0.3e1*_t723;
  const double d4F_dna2_dnb_dta = _t1543 + _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t105*_t725 + _t107*_t1544 + _t1169*_t12 + _t1170*_t12 + _t1171*_t12 + _t1172*_t12 + _t1510 + _t156*_t712 + _t157*_t712 - _t21*(_t1189*_t12 + _t1190*_t12 - _t1547*_t705 - _t1550*_t41 + _t1552*_t34 + _t1553 - _t501) + _t34*(_t1143*_t12 + _t1144*_t12 - _t1545*_t705 - _t1549*_t41 + _t1554*_t34 + _t1555 - _t508) + _t385*_t727 - _t41*(_t1183*_t12 + _t1184*_t12 - _t1546*_t705 + _t1549*_t34 + _t1551 - _t41*(_t1181*_t12 - _t1522) - _t491) + _t471 - _t487 - _t705*(_t1176*_t12 + _t1177*_t12 + _t1545*_t34 - _t1546*_t41 + _t1548 - _t478 - _t705*(_t1173*_t12 - _t1513)) + _t709*_t80 + _t726*_t989 + _t728*_t80) + _t103*_t730 + _t112*_t244 + _t238*_t451 + _t469*_t73 + _t50*_t713) + _t714;
  const double d4F_dna2_dnb_dtb = _t1556 + _t3*my_piecewise3(_t17, 0, _hc4[0]*(-_t141*_t721 + _t1533 - _t1534*_t295 + _t1557*_t427 + _t1557*_t429 - _t21*(-_t141*_t719 + _t1558*_t27 + _t1559 + _t430*_t719) + _t27*(-_t141*_t1541 + _t1541*_t430 + _t1560*_t27 + _t1561) + _t426*_t716 + _t430*_t721 + _t718*_t80 + _t733*_t88 + _t733*_t90 + _t734*_t80) + _t101*_t251 + _t242*_t424 + _t438*_t75 + _t53*_t722 + _t736*_t77) + _t723;
  const double d4F_dna_dnb2_dta = _t1543 + _t3*my_piecewise3(_t16, 0, _hc1[0]*(_hc0[1]*_t1563*_t33 + 0.4e1*_hc0[1]*_t2*_t725*_t83 + _hc0[2]*_hc2[12]*_t12*_t173*_t33 + 0.4e1*_hc0[2]*_hc2[12]*_t12*_t2*_t47*_t83 + 0.2e1*_hc0[2]*_t33*_t47*_t725 + _hc0[3]*_hc2[12]*_t12*_t175*_t336 - _t12*_t1288 - _t12*_t1294 - _t1509 - _t1562 - _t41*(_t12*_t1291 + _t12*_t1292 + _t1549*_t48 + _t1551) - _t530 + (0.4e1 / 0.9e1)*_t6*_t7*_t728*_t78 - _t705*(_t12*_t1289 + _t12*_t1290 + _t1545*_t48 + _t1548)) + _t172*_t730 + _t178*_t238 + _t244*_t451 + _t35*_t738 + _t524*_t73) + _t739;
  const double d4F_dna_dnb2_dtb = _t1556 + _t3*my_piecewise3(_t17, 0, _hc4[0]*(_t1224*_t716 + _t1568*_t27 + _t1569*_t430 - _t1570*_t295 + _t1573 + _t540*_t716 + _t542*_t716 - _t543*_t733 + _t545*_t716) + _t180*_t736 + _t185*_t242 + _t251*_t424 + _t30*_t747 + _t549*_t75) + _t748;
  const double d4F_dnb3_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t12*_t1325 + _t12*_t1326 + _t12*_t1327 + _t12*_t1328 + _t1510 + _t1544*_t580 - _t1562 + _t1563*_t48 + _t300*_t728 + _t579*_t725) + _t1504*_t244 + _t572*_t738 + _t583*_t73) + 0.3e1*_t739;
  const double d4F_dnb3_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-0.440e3 / 0.27e2*_hc5[6]*_t1574*tb + _t1362*_t742 + _t1363*_t740 + _t1404*_t15 + _t1405*_t15 - _t146*(_hc5[25]*_t1567 + _hc5[28]*_t1566 + _t1414*_t15 + _t1415*_t15 + _t1416*_t15 - _t146*(_hc3[1]*_hc5[78]*_t15*_t46 - _hc5[65]*_t248 - _hc5[68]*_t732 - _t1417*_t15 - _t613) + _t1565*_t52 - _t1572*_t21 - _t1575*_t741 + _t609 - _t612) + _t1568*_t52 + _t1569*_t182 + _t1569*_t184 + _t1570*_t181 + _t1570*_t590 + _t1573 - 0.280e3 / 0.27e2*_t249*_t825 - _t594 - _t608 + _t619 - _t741*(_hc5[21]*_t1567 + _t1408*_t15 + _t1409*_t15 + _t1410*_t15 - _t146*_t1575 + _t1564*_t52 - _t1571*_t21 + _t596 - _t603 - _t741*(_hc3[1]*_hc5[71]*_t15*_t46 - _hc5[56]*_t248 - _hc5[61]*_t732 - _t1411*_t15 - _t600) + _t743*_t827)) + _t1505*_t251 + _t586*_t747 + _t591*_t75) + 0.3e1*_t748;
  const double d4F_dna2_dgaa2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[36]*_t254*_t36*_t86 + _hc0[1]*_t33*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[86]*_t254*_t33*_t36 + (0.1e1 / 0.3e1)*_hc2[14]*_t256*_t39 + (0.5e1 / 0.12e2)*_hc2[34]*_t205*_t256*ta - _hc2[36]*_t1576 - _hc2[39]*_t34*_t771 - _hc2[78]*_t1579 - _hc2[80]*_t1577 - _t1581) + (0.1e1 / 0.4e1)*_hc0[2]*_hc2[36]*_t106*_t254*_t36 + (0.7e1 / 0.9e1)*_hc2[11]*_t254*_t353 + (0.10e2 / 0.9e1)*_hc2[28]*_t1508*_t254*ta + (0.7e1 / 0.9e1)*_hc2[30]*_t64*_t811 - 0.7e1 / 0.9e1*_t117*_t257 + (0.1e1 / 0.3e1)*_t127*_t256*_t39 - _t1584*_t640 - _t1590 - _t21*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[106]*_t254*_t33*_t36 - _hc2[100]*_t1577 + (0.1e1 / 0.3e1)*_hc2[18]*_t256*_t39 + (0.5e1 / 0.12e2)*_hc2[44]*_t205*_t256*ta - _hc2[46]*_t1576 - _hc2[49]*_t34*_t771 + (0.1e1 / 0.24e2)*_hc2[53]*_t11*_t19*_t256*_t6*_t7 - _hc2[98]*_t1579 - _t1587) - _t387*_t771 - _t388*_t771 - _t41*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[80]*_t254*_t33*_t36 + (0.1e1 / 0.3e1)*_hc2[11]*_t256*_t39 + (0.5e1 / 0.12e2)*_hc2[28]*_t205*_t256*ta - _hc2[68]*_t1579 - _hc2[70]*_t1577 - _t1582*_t771 - _t1583 - _t751*_t752) - 0.10e2 / 0.9e1*_t625*_t851*ta - _t705*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[78]*_t254*_t33*_t36 + (0.5e1 / 0.12e2)*_hc2[25]*_t205*_t256*ta - _hc2[28]*_t1576 - _hc2[65]*_t1579 - _hc2[68]*_t1577 + (0.1e1 / 0.3e1)*_hc2[9]*_t256*_t39 - _t1585*_t771 - _t1586)) + _t103*_t760 + _t112*_t749 - _t112*_t750) + 0.2e1*_t761;
  const double d4F_dna2_dgbb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[36]*_t261*_t54*_t87 + _hc3[1]*_t26*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[86]*_t26*_t261*_t54 - _hc5[39]*_t1591 - _t1593) + (0.1e1 / 0.4e1)*_hc3[2]*_hc5[36]*_t261*_t54*_t89 - _t1597*_t88 - _t1597*_t90 - _t1599 - _t21*(_hc5[106]*_t1596*_t27 - _hc5[49]*_t1591 + _hc5[53]*_t1595*_t758 - _t1594)) + _t101*_t762 - _t101*_t763 + _t769*_t77) + 0.2e1*_t770;
  const double d4F_dna_dnb_dgaa2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[36]*_t2*_t254*_t36*_t83 + _hc0[1]*_t1600*_t33 + (0.1e1 / 0.4e1)*_hc0[2]*_hc2[36]*_t254*_t33*_t36*_t47 - 0.1e1 / 0.2e1*_hc2[14]*_t1473*_t1588 - _t1584*_t663 - _t1601 + (0.1e1 / 0.3e1)*_t167*_t256*_t39 - _t41*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[80]*_t254*_t36*_t47 - _t1583 - _t492*_t771) - _t494*_t771 - _t705*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[78]*_t254*_t36*_t47 - _t1586 - _t479*_t771)) + _t160*_t749 - _t160*_t750 + _t35*_t772 + _t50*_t760) + _t761 + _t773;
  const double d4F_dna_dnb_dgbb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_hc5[14]*_t1595*_t1602 + _hc5[36]*_t1596*_t430 - _hc5[36]*_t1602*_t767 + _hc5[46]*_t1589*_t767 - _t1597*_t430 - _t1598 - _t1607 + _t1608*_t27) + _t144*_t762 - _t144*_t763 + _t30*_t779 + _t53*_t769) + _t770 + _t780;
  const double d4F_dnb2_dgaa2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[36]*_t173*_t254*_t36 + _hc0[1]*_t1600*_t47 + (0.1e1 / 0.4e1)*_hc0[2]*_hc2[36]*_t175*_t254*_t36 - _t1601 - _t531*_t771 - _t532*_t771) + _t172*_t772 + _t178*_t749 - _t178*_t750) + 0.2e1*_t773;
  const double d4F_dnb2_dgbb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[36]*_t181*_t261*_t54 + _hc3[1]*_t1608*_t46 + (0.1e1 / 0.4e1)*_hc3[2]*_hc5[36]*_t183*_t261*_t54 + (0.7e1 / 0.9e1)*_hc5[11]*_t261*_t592 + (0.10e2 / 0.9e1)*_hc5[28]*_t1574*_t261*tb + (0.7e1 / 0.9e1)*_hc5[30]*_t69*_t825 - _t146*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[80]*_t261*_t46*_t54 - _hc5[100]*_t1592 + (0.1e1 / 0.3e1)*_hc5[11]*_t263*_t58 + (0.5e1 / 0.12e2)*_hc5[28]*_t228*_t263*tb + (0.1e1 / 0.24e2)*_hc5[46]*_t14*_t19*_t263*_t6*_t7 - _hc5[68]*_t1606 - _hc5[70]*_t1603 - _t1609*_t765 - _t774*_t775) - _t1599 - _t1607 + (0.1e1 / 0.3e1)*_t191*_t263*_t58 - 0.7e1 / 0.9e1*_t192*_t264 - _t59*_t688*_t69 - _t610*_t765 - _t611*_t765 - 0.10e2 / 0.9e1*_t690*_t856*tb - _t741*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[78]*_t261*_t46*_t54 + (0.5e1 / 0.12e2)*_hc5[25]*_t228*_t263*tb - _hc5[28]*_t1604 + (0.1e1 / 0.24e2)*_hc5[44]*_t14*_t19*_t263*_t6*_t7 - _hc5[65]*_t1606 - _hc5[68]*_t1603 + (0.1e1 / 0.3e1)*_hc5[9]*_t263*_t58 - _hc5[98]*_t1592 - _t1610*_t765)) + _t180*_t779 + _t185*_t762 - _t185*_t763) + 0.2e1*_t780;
  const double d4F_dna2_dgaa_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.14e2 / 0.9e1)*_hc2[28]*_t1508 + _t1001*_t800 + _t1002*_t800 + _t1611*_t628*_t632 + _t1612 - _t21*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[104]*_t267*_t33*_t64 - _hc2[44]*_t1613 - _hc2[95]*_t1614 - _hc2[98]*_t782 - _t1618) + _t34*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[84]*_t267*_t33*_t64 - _hc2[34]*_t1613 - _hc2[75]*_t1614 - _hc2[78]*_t782 - _t1619) - _t41*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[78]*_t267*_t33*_t64 - _hc2[28]*_t1613 - _hc2[65]*_t1614 - _hc2[68]*_t782 - _t1617) + (0.34e2 / 0.9e1)*_t627 - _t631*_t707 - _t637 - _t705*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[75]*_t267*_t33*_t64 - _hc2[25]*_t1613 - _hc2[61]*_t1614 - _hc2[65]*_t782 - _t1616)) + _t103*_t790 + _t112*_t781) + 0.2e1*_t791;
  const double d4F_dna2_dgbb_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_t1620 + _t1621*_t88 + _t1621*_t90 - _t21*(_hc5[104]*_t1626 - _t1623) + _t27*(_hc5[84]*_t1626 - _t1627)) + _t101*_t792 + _t77*_t797) + 0.2e1*_t798;
  const double d4F_dna_dnb_dgaa_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_hc0[1]*_hc2[34]*_t2*_t267*_t64*_t83 + _hc0[1]*_t1629*_t33 + (0.1e1 / 0.2e1)*_hc0[2]*_hc2[34]*_t267*_t33*_t47*_t64 + (0.1e1 / 0.9e1)*_hc2[44]*_t267*_t6*_t64*_t7*_t78 - _t1628 - _t41*(_t1181*_t800 - _t1617) - _t631*_t727 - _t662 - _t705*(_t1174*_t800 - _t1616)) + _t160*_t781 + _t35*_t801 + _t50*_t790) + _t791 + _t802;
  const double d4F_dna_dnb_dgbb_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-_t1487*_t796 + _t1621*_t430 + _t1632*_t27 + _t1633) + _t144*_t792 + _t30*_t808 + _t53*_t797) + _t798 + _t809;
  const double d4F_dnb2_dgaa_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t1291*_t800 + _t1292*_t800 + _t1612 - _t1628 + _t1629*_t48) + _t172*_t801 + _t178*_t781) + 0.2e1*_t802;
  const double d4F_dnb2_dgbb_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.14e2 / 0.9e1)*_hc5[28]*_t1574 + _t1415*_t1625 + _t1416*_t1625 - _t146*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[78]*_t271*_t46*_t69 - _hc5[28]*_t1630 - _hc5[65]*_t1631 - _hc5[68]*_t803 - _hc5[98]*_t1622) + _t1632*_t52 + _t1633 + _t1634*_t685*_t693 - _t671*_t742 - _t687 + (0.34e2 / 0.9e1)*_t692 - _t741*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[75]*_t271*_t46*_t69 - _hc5[25]*_t1630 - _hc5[61]*_t1631 - _hc5[65]*_t803 - _hc5[95]*_t1622)) + _t180*_t808 + _t185*_t792) + 0.2e1*_t809;
  const double d4F_dna2_dta2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_hc2[21]*_t1635*_t699 + _t117*_t991 + _t117*_t992 + (0.28e2 / 0.9e1)*_t1611*_t813 + _t1636 - _t1637*_t704 - _t21*(_hc0[1]*_hc2[101]*_t117*_t33 - _hc2[41]*_t810 - _hc2[91]*_t1638 - _hc2[95]*_t1639 - _t1642) + _t34*(_hc0[1]*_hc2[81]*_t117*_t33 - _hc2[31]*_t810 - _hc2[71]*_t1638 - _hc2[75]*_t1639 - _t1643) - _t41*(_hc0[1]*_hc2[75]*_t117*_t33 - _hc2[25]*_t810 - _hc2[61]*_t1638 - _hc2[65]*_t1639 - _t1641) + (0.80e2 / 0.9e1)*_t698 - _t705*(_hc0[1]*_hc2[71]*_t117*_t33 - _hc2[21]*_t810 - _hc2[56]*_t1638 - _hc2[61]*_t1639 - _t1640)) + _t103*_t816 + _t112*_t275) + 0.2e1*_t817;
  const double d4F_dna2_dtb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_t1644 + _t1645*_t88 + _t1645*_t90 - _t21*(_hc5[101]*_t819 - _t1646) + _t27*(_hc5[81]*_t819 - _t1647)) + _t101*_t277 + _t77*_t820) + 0.2e1*_t821;
  const double d4F_dna_dnb_dta2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t117*_t1176 + _t117*_t1177 - _t1637*_t726 + _t1648*_t34 + _t1649 - _t41*(_t117*_t1174 - _t1641) - _t705*(_t117*_t1173 - _t1640)) + _t160*_t275 + _t35*_t822 + _t50*_t816) + _t817 + _t823;
  const double d4F_dna_dnb_dtb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-_t141*_t1645 + _t1645*_t430 + _t1652*_t27 + _t1653) + _t144*_t277 + _t30*_t829 + _t53*_t820) + _t821 + _t830;
  const double d4F_dnb2_dta2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t117*_t1289 + _t117*_t1290 + _t1648*_t48 + _t1649) + _t172*_t822 + _t178*_t275) + 0.2e1*_t823;
  const double d4F_dnb2_dtb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_hc5[21]*_t1654*_t746 + _t1409*_t192 + _t1410*_t192 - _t146*(_hc3[1]*_hc5[75]*_t192*_t46 - _hc5[25]*_t824 - _hc5[61]*_t1650 - _hc5[65]*_t1651 - _t1412*_t192) + (0.28e2 / 0.9e1)*_t1634*_t827 + _t1652*_t52 + _t1653 - 0.10e2 / 0.3e1*_t54*_t740 - _t741*(_hc3[1]*_hc5[71]*_t192*_t46 - _hc5[21]*_t824 - _hc5[56]*_t1650 - _hc5[61]*_t1651 - _t1411*_t192) + (0.80e2 / 0.9e1)*_t745) + _t180*_t829 + _t185*_t277) + 0.2e1*_t830;
  const double d4F_dna_dgaa3 = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.3e1 / 0.8e1)*_hc0[1]*_hc2[14]*_t11*_t33*_t833 + (0.1e1 / 0.8e1)*_hc0[1]*_hc2[80]*_t205*_t256*_t33 + (0.1e1 / 0.2e1)*_hc2[11]*_t113*_t831 + (0.5e1 / 0.8e1)*_hc2[28]*_t697*_t831*ta + (0.1e1 / 0.16e2)*_hc2[46]*_t19*_t36*_t6*_t7*_t831 - 0.1e1 / 0.6e1*_hc2[70]*_t1508*_t254 - 0.5e1 / 0.8e1*_hc2[9]*_t1659*ta - _t1582*_t1665 - 0.5e1 / 0.24e2*_t1611*_t1658*ta - _t1661 - _t1663 - 0.1e1 / 0.2e1*_t39*_t834) - _t1655*_t35 + _t1656*_t35 + _t1657*_t35) + _t839;
  const double d4F_dna_dgbb3 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(-_hc5[36]*_t1673*_t27 + _hc5[46]*_t1662*_t54*_t840 + _hc5[80]*_t27*_t847 + _t14*_t1671*_t766 - _t1669 - _t1670) - _t1666*_t30 + _t1667*_t30 + _t1668*_t30) + _t848;
  const double d4F_dnb_dgaa3 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_hc2[46]*_t1662*_t36*_t831 + _t11*_t166*_t1674 + _t1199*_t838 - _t1661 - _t1663 - _t1665*_t492) - _t1655*_t50 + _t1656*_t50 + _t1657*_t50) + _t839;
  const double d4F_dnb_dgbb3 = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.3e1 / 0.8e1)*_hc3[1]*_hc5[14]*_t14*_t46*_t842 + (0.1e1 / 0.8e1)*_hc3[1]*_hc5[80]*_t228*_t263*_t46 + (0.1e1 / 0.2e1)*_hc5[11]*_t194*_t840 + (0.5e1 / 0.8e1)*_hc5[28]*_t744*_t840*tb + (0.1e1 / 0.16e2)*_hc5[46]*_t19*_t54*_t6*_t7*_t840 - 0.1e1 / 0.6e1*_hc5[70]*_t1574*_t261 - 0.5e1 / 0.8e1*_hc5[9]*_t1676*tb - _t1609*_t1673 - 0.5e1 / 0.24e2*_t1634*_t1675*tb - _t1669 - _t1670 - 0.1e1 / 0.2e1*_t58*_t843) - _t1666*_t53 + _t1667*_t53 + _t1668*_t53) + _t848;
  const double d4F_dna_dgaa2_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[78]*_t232*_t254*_t33 + (0.5e1 / 0.12e2)*_hc2[25]*_t256*_t784*ta + (0.3e1 / 0.4e1)*_hc2[9]*_t205*_t256 - 0.1e1 / 0.3e1*_t1445*_t1611 - _t1578*_t1679 - _t1585*_t1680 - _t1681 - 0.3e1 / 0.4e1*_t754) + _t1677*_t35 - _t1678*_t35) + _t853;
  const double d4F_dna_dgbb2_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[78]*_t246*_t26*_t261 - _hc5[34]*_t1684*_t27 - _t1685) + _t1682*_t30 - _t1683*_t30) + _t858;
  const double d4F_dnb_dgaa2_dta = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.1e1 / 0.4e1)*_hc0[1]*_hc2[78]*_t232*_t254*_t47 - _t1680*_t479 - _t1681) + _t1677*_t50 - _t1678*_t50) + _t853;
  const double d4F_dnb_dgbb2_dtb = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.1e1 / 0.4e1)*_hc3[1]*_hc5[78]*_t246*_t261*_t46 + (0.5e1 / 0.12e2)*_hc5[25]*_t263*_t805*tb + (0.3e1 / 0.4e1)*_hc5[9]*_t228*_t263 - 0.1e1 / 0.3e1*_t1507*_t1634 - _t1605*_t1686 - _t1610*_t1684 - _t1685 - 0.3e1 / 0.4e1*_t777) + _t1682*_t53 - _t1683*_t53) + _t858;
  const double d4F_dna_dgaa_dta2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*((0.1e1 / 0.2e1)*_hc0[1]*_hc2[75]*_t33*_t353*_t64 - 0.2e1 / 0.3e1*_t1679 - 0.5e1 / 0.6e1*_t1688*_t64*ta - _t1689 - 0.7e1 / 0.3e1*_t632*_t784) + _t1687*_t35) + _t861;
  const double d4F_dna_dgbb_dtb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_hc5[75]*_t1624*_t27*_t592 - _t1691) + _t1690*_t30) + _t864;
  const double d4F_dnb_dgaa_dta2 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t1174*_t353*_t799 - _t1689) + _t1687*_t50) + _t861;
  const double d4F_dnb_dgbb_dtb2 = _t3*my_piecewise3(_t17, 0, _hc4[0]*((0.1e1 / 0.2e1)*_hc3[1]*_hc5[75]*_t46*_t592*_t69 - 0.2e1 / 0.3e1*_t1686 - _t1691 - 0.5e1 / 0.6e1*_t1692*_t69*tb - 0.7e1 / 0.3e1*_t685*_t805) + _t1690*_t53) + _t864;
  const double d4F_dna_dta3 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_hc0[1]*_hc2[71]*_t33*_t625 - _hc2[56]*_t233/xc_powr(na, 23, 3) - 0.4e1 / 0.3e1*_t10*_t1688 - _t1693 - 0.5e1*_t812) + _t35*_t865) + _t866;
  const double d4F_dna_dtb3 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_hc5[71]*_t27*_t690 - _t1694) + _t30*_t867) + _t868;
  const double d4F_dnb_dta3 = _t3*my_piecewise3(_t16, 0, _hc1[0]*(_t1173*_t625 - _t1693) + _t50*_t865) + _t866;
  const double d4F_dnb_dtb3 = _t3*my_piecewise3(_t17, 0, _hc4[0]*(_hc3[1]*_hc5[71]*_t46*_t690 - _hc5[56]*_t247/xc_powr(nb, 23, 3) - 0.4e1 / 0.3e1*_t13*_t1692 - _t1694 - 0.5e1*_t826) + _t53*_t867) + _t868;
  const double d4F_dgaa4 = _t3*my_piecewise3(_t16, 0, (0.1e1 / 0.16e2)*_hc1[0]*_hc2[70]*_t697*_t831 + (0.15e2 / 0.16e2)*_hc2[11]*_t253/(gaa * gaa * gaa) - 0.15e2 / 0.16e2*_hc2[3]*_t63/xc_powr(gaa, 7, 2) - 0.3e1 / 0.8e1*_t1659*_t836);
  const double d4F_dgbb4 = _t3*my_piecewise3(_t17, 0, (0.1e1 / 0.16e2)*_hc4[0]*_hc5[70]*_t744*_t840 + (0.15e2 / 0.16e2)*_hc5[11]*_t260/(gbb * gbb * gbb) - 0.15e2 / 0.16e2*_hc5[3]*_t68/xc_powr(gbb, 7, 2) - 0.3e1 / 0.8e1*_t1676*_t845);
  const double d4F_dgaa3_dta = _t3*my_piecewise3(_t16, 0, (0.1e1 / 0.8e1)*_hc1[0]*_t1658*_t784 - _hc2[28]*_t1664*_t849 + _hc2[9]*_t1674*_t268);
  const double d4F_dgbb3_dtb = _t3*my_piecewise3(_t17, 0, (0.1e1 / 0.8e1)*_hc4[0]*_t1675*_t805 - _hc5[28]*_t1672*_t854 + _hc5[9]*_t1671*_t272);
  const double d4F_dgaa2_dta2 = _t3*my_piecewise3(_t16, 0, (0.1e1 / 0.4e1)*_hc1[0]*_hc2[65]*_t254*_t811 - 0.1e1 / 0.4e1*_hc2[25]*_t256*_t859);
  const double d4F_dgbb2_dtb2 = _t3*my_piecewise3(_t17, 0, (0.1e1 / 0.4e1)*_hc4[0]*_hc5[65]*_t261*_t825 - 0.1e1 / 0.4e1*_hc5[25]*_t263*_t862);
  const double d4F_dgaa_dta3 = _t3*my_piecewise3(_t16, 0, _hc1[0]*_hc2[61]*_t1508*_t799);
  const double d4F_dgbb_dtb3 = _t3*my_piecewise3(_t17, 0, _hc4[0]*_hc5[61]*_t1574*_t1624);
  const double d4F_dta4 = _t3*my_piecewise3(_t16, 0, _hc1[0]*_hc2[56]*_t1611);
  const double d4F_dtb4 = _t3*my_piecewise3(_t17, 0, _hc4[0]*_hc5[56]*_t1634);
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