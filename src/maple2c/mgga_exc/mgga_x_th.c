/*
  Generated from python/mgga_exc/mgga_x_th.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_th
*/

#ifndef _MGGA_X_TH_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_TH_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_TH_HELPER_BODIES
#include "mgga_x_th.c"
#undef _MGGA_X_TH_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_TH_HELPER_BODIES
#include "mgga_x_th.c"
#undef _MGGA_X_TH_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_TH_HELPER_BODIES
#include "mgga_x_th.c"
#undef _MGGA_X_TH_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_TH_HELPER_BODIES
#include "mgga_x_th.c"
#undef _MGGA_X_TH_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_TH_HELPER_BODIES
#include "mgga_x_th.c"
#undef _MGGA_X_TH_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_th.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_TH_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(th_f0_k, _KMAX)(const xc_func_type *p, double p_, double u, double t, double *out) {

  const double _t1 = (0.1e1 / t);
  const double _t2 = xc_powr(0.6e1, 2, 3);
  const double _t3 = M_PI*((0.7e1 / 0.27e2)*(M_PI * M_CBRTPI)*_t1*_t2*p_ + 0.1e1);
  const double _t4 = (0.27e2 / 0.10e2)*_t3;
#if _KMAX >= 1
  const double _t5 = (0.1e1 / (t * t * t));
  const double _t6 = (M_PI * M_PI * M_CBRTPI)*_t2;
  const double _t7 = (0.7e1 / 0.10e2)*_t6;
  const double _t8 = (0.1e1 / (t * t));
#endif
#if _KMAX >= 2
  const double _t9 = (0.1e1 / (t * t * t * t));
  const double _t10 = _t6*_t9;
#endif
#if _KMAX >= 3
  const double _t11 = xc_powi(t, -5);
  const double _t12 = _t11*_t6;
#endif

  const double f = -_t1*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = _t4*_t8 + _t5*_t7*p_;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dp_ = -_t7*_t8;
  out[3] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -0.14e2 / 0.5e1*_t10*p_ - 0.27e2 / 0.5e1*_t3*_t5;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dp__dt = (0.7e1 / 0.5e1)*_t5*_t6;
  out[7] = d2f_dp__dt;
  const double d2f_dp__du = 0;
  out[8] = d2f_dp__du;
  const double d2f_dp_2 = 0;
  out[9] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = (0.63e2 / 0.5e1)*_t12*p_ + (0.81e2 / 0.5e1)*_t3*_t9;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dp__dt2 = -0.21e2 / 0.5e1*_t10;
  out[14] = d3f_dp__dt2;
  const double d3f_dp__du_dt = 0;
  out[15] = d3f_dp__du_dt;
  const double d3f_dp__du2 = 0;
  out[16] = d3f_dp__du2;
  const double d3f_dp_2_dt = 0;
  out[17] = d3f_dp_2_dt;
  const double d3f_dp_2_du = 0;
  out[18] = d3f_dp_2_du;
  const double d3f_dp_3 = 0;
  out[19] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = -0.324e3 / 0.5e1*_t11*_t3 - 0.336e3 / 0.5e1*_t6*p_/xc_powi(t, 6);
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dp__dt3 = (0.84e2 / 0.5e1)*_t12;
  out[25] = d4f_dp__dt3;
  const double d4f_dp__du_dt2 = 0;
  out[26] = d4f_dp__du_dt2;
  const double d4f_dp__du2_dt = 0;
  out[27] = d4f_dp__du2_dt;
  const double d4f_dp__du3 = 0;
  out[28] = d4f_dp__du3;
  const double d4f_dp_2_dt2 = 0;
  out[29] = d4f_dp_2_dt2;
  const double d4f_dp_2_du_dt = 0;
  out[30] = d4f_dp_2_du_dt;
  const double d4f_dp_2_du2 = 0;
  out[31] = d4f_dp_2_du2;
  const double d4f_dp_3_dt = 0;
  out[32] = d4f_dp_3_dt;
  const double d4f_dp_3_du = 0;
  out[33] = d4f_dp_3_du;
  const double d4f_dp_4 = 0;
  out[34] = d4f_dp_4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(th_f_k, _KMAX)(const xc_func_type *p, double p_, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1];
  XC_CAT(th_f0_k, _KMAX)(p, p_, 0, 0.2e1*t, _hc0);
  const double _t1 = xc_powr(0.2e1, 2, 3)*M_CBRTPI/M_CBRT3;
  const double _t2 = (0.2e1 / 0.3e1)*_t1;
#if _KMAX >= 1
  const double _t3 = (0.4e1 / 0.3e1)*_t1;
#endif
#if _KMAX >= 2
  const double _t4 = (0.8e1 / 0.3e1)*_t1;
#endif
#if _KMAX >= 3
  const double _t5 = (0.16e2 / 0.3e1)*_t1;
#endif

  const double f = -_hc0[0]*_t2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = -_hc0[1]*_t3;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dp_ = -_hc0[3]*_t2;
  out[3] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = -_hc0[4]*_t4;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dp__dt = -_hc0[7]*_t3;
  out[7] = d2f_dp__dt;
  const double d2f_dp__du = 0;
  out[8] = d2f_dp__du;
  const double d2f_dp_2 = 0;
  out[9] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = -_hc0[10]*_t5;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dp__dt2 = -_hc0[14]*_t4;
  out[14] = d3f_dp__dt2;
  const double d3f_dp__du_dt = 0;
  out[15] = d3f_dp__du_dt;
  const double d3f_dp__du2 = 0;
  out[16] = d3f_dp__du2;
  const double d3f_dp_2_dt = 0;
  out[17] = d3f_dp_2_dt;
  const double d3f_dp_2_du = 0;
  out[18] = d3f_dp_2_du;
  const double d3f_dp_3 = 0;
  out[19] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = -0.32e2 / 0.3e1*_hc0[20]*_t1;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dp__dt3 = -_hc0[25]*_t5;
  out[25] = d4f_dp__dt3;
  const double d4f_dp__du_dt2 = 0;
  out[26] = d4f_dp__du_dt2;
  const double d4f_dp__du2_dt = 0;
  out[27] = d4f_dp__du2_dt;
  const double d4f_dp__du3 = 0;
  out[28] = d4f_dp__du3;
  const double d4f_dp_2_dt2 = 0;
  out[29] = d4f_dp_2_dt2;
  const double d4f_dp_2_du_dt = 0;
  out[30] = d4f_dp_2_du_dt;
  const double d4f_dp_2_du2 = 0;
  out[31] = d4f_dp_2_du2;
  const double d4f_dp_3_dt = 0;
  out[32] = d4f_dp_3_dt;
  const double d4f_dp_3_du = 0;
  out[33] = d4f_dp_3_du;
  const double d4f_dp_4 = 0;
  out[34] = d4f_dp_4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t6 = _t1*_t5;
  const double _t7 = _t6*sigma_ss;
  const double _t8 = xc_powr(n_s, -8, 3);
  const double _t9 = (0.1e1 / 0.24e2)*_t8;
  const double _t10 = xc_powr(n_s, -5, 3);
  const double _t11 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t18 = xc_powr(n_s, -4, 3);
  const double _t21 = (0.5e1 / 0.3e1)*_t8;
  const double _t24 = xc_powr(n_s, -11, 3);
  const double _t25 = (0.1e1 / 0.9e1)*_t24;
  const double _t26 = _t25*_t7;
#endif
#if _KMAX >= 2
  const double _t29 = xc_powr(n_s, -10, 3);
  const double _t35 = xc_powr(n_s, -13, 3);
  const double _t41 = xc_powr(n_s, -16, 3);
  const double _t42 = xc_powr(0.6e1, 2, 3);
  const double _t43 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t44 = _t42*_t43;
  const double _t49 = (0.5e1 / 0.3e1)*_t35;
  const double _t52 = (0.1e1 / 0.9e1)*_t7;
  const double _t53 = _t41*_t52;
  const double _t56 = _t49*lapl_s;
  const double _t59 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t61 = _t42/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t64 = (0.5e1 / 0.72e2)*_t6;
  const double _t65 = _t41*_t64;
  const double _t67 = xc_powr(n_s, -19, 3);
  const double _t68 = (0.1e1 / 0.216e3)*sigma_ss;
  const double _t69 = _t67*_t68;
  const double _t73 = xc_powr(n_s, -7, 3);
  const double _t76 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t77 = _t42*_t76;
  const double _t81 = (0.1e1 / 0.3e1)*_t18;
  const double _t82 = (0.40e2 / 0.9e1)*_t24;
  const double _t85 = xc_powr(n_s, -14, 3);
  const double _t86 = (0.11e2 / 0.27e2)*_t85;
  const double _t87 = _t7*_t86;
#endif
#if _KMAX >= 3
  const double _t100 = xc_powi(n_s, -5);
  const double _t107 = xc_powi(n_s, -6);
  const double _t114 = xc_powi(n_s, -7);
  const double _t119 = xc_powi(n_s, -8);
  const double _t120 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t125 = (0.10e2 / 0.3e1)*_t35;
  const double _t126 = (0.5e1 / 0.3e1)*_t107;
  const double _t129 = _t114*_t52;
  const double _t135 = _t126*lapl_s;
  const double _t139 = xc_powr(n_s, -17, 3);
  const double _t141 = (0.13e2 / 0.72e2)*_t41;
  const double _t142 = _t114*tau_s;
  const double _t145 = _t114*lapl_s;
  const double _t146 = _t119*_t68;
  const double _t150 = _t145*_t64;
  const double _t153 = xc_powr(n_s, -20, 3);
  const double _t155 = (0.1e1 / (M_PI * M_PI * M_PI));
  const double _t156 = (0.1e1 / 0.576e3)*_t155;
  const double _t157 = xc_powi(n_s, -9);
  const double _t159 = (0.1e1 / 0.864e3)*sigma_ss;
  const double _t160 = (0.1e1 / 0.108e3)*_t67;
  const double _t161 = (0.5e1 / 0.1728e4)*_t119;
  const double _t163 = _t161*lapl_s;
  const double _t171 = (0.40e2 / 0.9e1)*_t41;
  const double _t173 = (0.11e2 / 0.27e2)*_t7;
  const double _t174 = _t173*_t67;
  const double _t175 = _t49*tau_s;
  const double _t177 = _t21*lapl_s;
  const double _t179 = _t21*tau_s;
  const double _t184 = _t171*lapl_s;
  const double _t189 = (0.1e1 / (M_PI * M_PI));
  const double _t192 = (0.5e1 / 0.27e2)*_t6*_t67;
  const double _t193 = xc_powr(n_s, -22, 3);
  const double _t195 = (0.11e2 / 0.648e3)*sigma_ss;
  const double _t196 = _t25*_t6;
  const double _t198 = _t65*lapl_s;
  const double _t203 = _t65*tau_s;
  const double _t213 = (0.440e3 / 0.27e2)*_t85;
  const double _t216 = (0.154e3 / 0.81e2)*_t139;
  const double _t217 = _t216*_t7;
#endif
#if _KMAX >= 4
  const double _t252 = xc_powr(n_s, -23, 3);
  const double _t255 = xc_powr(n_s, -26, 3);
  const double _t259 = xc_powr(n_s, -29, 3);
  const double _t262 = xc_powr(n_s, -32, 3);
  const double _t265 = 0.5e1*_t107;
  const double _t266 = (0.5e1 / 0.3e1)*_t252;
  const double _t269 = _t255*_t52;
  const double _t273 = (0.1e1 / 0.4e1)*_t114;
  const double _t274 = _t255*_t64;
  const double _t275 = _t274*tau_s;
  const double _t276 = _t274*lapl_s;
  const double _t277 = _t259*_t68;
  const double _t278 = _t273*_t6;
  const double _t279 = _t277*_t44;
  const double _t280 = xc_powr(n_s, -25, 3);
  const double _t282 = _t159*_t262;
  const double _t283 = (0.7e1 / 0.576e3)*_t119;
  const double _t284 = (0.5e1 / 0.1728e4)*_t259;
  const double _t289 = (0.5e1 / 0.6912e4)*_t262;
  const double _t292 = (0.80e2 / 0.9e1)*_t41;
  const double _t293 = (0.40e2 / 0.9e1)*_t114;
  const double _t295 = _t119*_t173;
  const double _t296 = (0.10e2 / 0.3e1)*_t8;
  const double _t297 = _t126*tau_s;
  const double _t305 = _t141*_t6;
  const double _t306 = _t142*_t64;
  const double _t308 = _t146*_t44;
  const double _t309 = (0.5e1 / 0.648e3)*_t157;
  const double _t310 = _t157*_t159;
  const double _t311 = _t161*tau_s;
  const double _t317 = (0.440e3 / 0.27e2)*_t67;
  const double _t319 = (0.154e3 / 0.81e2)*_t193*_t7;
  const double _t320 = _t171*tau_s;
  const double _t329 = (0.55e2 / 0.81e2)*_t193*_t6;
  const double _t331 = _t192*lapl_s;
  const double _t332 = _t193*_t195;
  const double _t336 = (0.6160e4 / 0.81e2)*_t139;
  const double _t337 = (0.440e3 / 0.9e1)*_t85;
  const double _t338 = (0.40e2 / 0.3e1)*_t24;
  const double _t340 = _t82*tau_s;
  const double _t343 = _t82*lapl_s;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t11)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t11)) XC_CAT(th_f_k, _KMAX)(p, _t7*_t9, _t10*lapl_s, _t10*tau_s, _hc1);
  const double _t12 = my_piecewise3(_t11, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t13 = _hc0[0]*_t10;
  const double _t14 = my_piecewise3(_t11, 0, _hc1[1]*_t13);
  const double _t15 = my_piecewise3(_t11, 0, _hc1[2]*_t13);
  const double _t16 = _hc1[3]*_t6;
  const double _t17 = my_piecewise3(_t11, 0, _hc0[0]*_t16*_t9);
  const double _t19 = _hc0[2]*_t3;
  const double _t20 = (0.1e1 / 0.6e1)*_t19;
  const double _t22 = _hc1[1]*_t21;
  const double _t23 = _hc1[2]*_t21;
  const double _t27 = -_hc1[3]*_t26 - _t22*tau_s - _t23*lapl_s;
  const double _t28 = my_piecewise3(_t11, 0, _hc0[0]*_t27 - _hc1[0]*_t18*_t20);
#endif
#if _KMAX >= 2
  const double _t30 = _hc0[0]*_t29;
  const double _t31 = my_piecewise3(_t11, 0, _hc1[4]*_t30);
  const double _t32 = my_piecewise3(_t11, 0, _hc1[5]*_t30);
  const double _t33 = my_piecewise3(_t11, 0, _hc1[6]*_t30);
  const double _t34 = _hc1[7]*_t6;
  const double _t36 = (0.1e1 / 0.24e2)*_hc0[0];
  const double _t37 = _t35*_t36;
  const double _t38 = my_piecewise3(_t11, 0, _t34*_t37);
  const double _t39 = _hc1[8]*_t6;
  const double _t40 = my_piecewise3(_t11, 0, _t37*_t39);
  const double _t45 = _hc1[9]*_t44;
  const double _t46 = (0.1e1 / 0.576e3)*_hc0[0];
  const double _t47 = my_piecewise3(_t11, 0, _t41*_t45*_t46);
  const double _t48 = _t20/(n_s * n_s * n_s);
  const double _t50 = _hc1[4]*tau_s;
  const double _t51 = _hc1[5]*_t49;
  const double _t54 = -_hc1[7]*_t53 - _t22 - _t49*_t50 - _t51*lapl_s;
  const double _t55 = my_piecewise3(_t11, 0, _hc0[0]*_t54 - _hc1[1]*_t48);
  const double _t57 = -_hc1[6]*_t56 - _hc1[8]*_t53 - _t23 - _t51*tau_s;
  const double _t58 = my_piecewise3(_t11, 0, _hc0[0]*_t57 - _hc1[2]*_t48);
  const double _t60 = (0.1e1 / 0.144e3)*_hc1[3];
  const double _t62 = _hc0[2]*_t61;
  const double _t63 = _hc1[7]*tau_s;
  const double _t66 = _hc1[8]*lapl_s;
  const double _t70 = -_t16*_t25 - _t45*_t69 - _t63*_t65 - _t65*_t66;
  const double _t71 = my_piecewise3(_t11, 0, _hc0[0]*_t70 - _t59*_t60*_t62);
  const double _t72 = (0.2e1 / 0.9e1)*_hc1[0];
  const double _t74 = _t19*_t73;
  const double _t75 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t78 = _hc0[5]*_t77;
  const double _t79 = _t78*_t8;
  const double _t80 = _t19*_t27;
  const double _t83 = _hc1[1]*_t82;
  const double _t84 = _hc1[2]*_t82;
  const double _t88 = _hc1[5]*_t21;
  const double _t89 = _hc1[6]*_t21;
  const double _t90 = -_hc1[8]*_t26 - _t88*tau_s - _t89*lapl_s;
  const double _t91 = _t21*_t90;
  const double _t92 = _hc1[4]*_t21;
  const double _t93 = -_hc1[7]*_t26 - _t88*lapl_s - _t92*tau_s;
  const double _t94 = _t21*_t93;
  const double _t95 = _hc1[7]*_t21;
  const double _t96 = _hc1[8]*_t21;
  const double _t97 = -_hc1[9]*_t26 - _t95*tau_s - _t96*lapl_s;
  const double _t98 = _hc1[3]*_t87 - _t26*_t97 + _t83*tau_s + _t84*lapl_s - _t91*lapl_s - _t94*tau_s;
  const double _t99 = my_piecewise3(_t11, 0, _hc0[0]*_t98 + _t72*_t74 + _t75*_t79 - _t80*_t81);
#endif
#if _KMAX >= 3
  const double _t101 = _hc0[0]*_t100;
  const double _t102 = my_piecewise3(_t11, 0, _hc1[10]*_t101);
  const double _t103 = my_piecewise3(_t11, 0, _hc1[11]*_t101);
  const double _t104 = my_piecewise3(_t11, 0, _hc1[12]*_t101);
  const double _t105 = my_piecewise3(_t11, 0, _hc1[13]*_t101);
  const double _t106 = _hc1[14]*_t6;
  const double _t108 = _t107*_t36;
  const double _t109 = my_piecewise3(_t11, 0, _t106*_t108);
  const double _t110 = _t108*_t6;
  const double _t111 = my_piecewise3(_t11, 0, _hc1[15]*_t110);
  const double _t112 = my_piecewise3(_t11, 0, _hc1[16]*_t110);
  const double _t113 = _hc1[17]*_t44;
  const double _t115 = _t114*_t46;
  const double _t116 = my_piecewise3(_t11, 0, _t113*_t115);
  const double _t117 = _hc1[18]*_t44;
  const double _t118 = my_piecewise3(_t11, 0, _t115*_t117);
  const double _t121 = _hc1[19]*_t120;
  const double _t122 = (0.1e1 / 0.2304e4)*_hc0[0];
  const double _t123 = my_piecewise3(_t11, 0, _t119*_t121*_t122);
  const double _t124 = _t20*_t85;
  const double _t127 = _hc1[10]*tau_s;
  const double _t128 = _hc1[11]*_t126;
  const double _t130 = -_hc1[14]*_t129 - _hc1[4]*_t125 - _t126*_t127 - _t128*lapl_s;
  const double _t131 = my_piecewise3(_t11, 0, _hc0[0]*_t130 - _hc1[4]*_t124);
  const double _t132 = _hc1[12]*_t126;
  const double _t133 = -_hc1[15]*_t129 - _hc1[5]*_t125 - _t128*tau_s - _t132*lapl_s;
  const double _t134 = my_piecewise3(_t11, 0, _hc0[0]*_t133 - _hc1[5]*_t124);
  const double _t136 = -_hc1[13]*_t135 - _hc1[16]*_t129 - _hc1[6]*_t125 - _t132*tau_s;
  const double _t137 = my_piecewise3(_t11, 0, _hc0[0]*_t136 - _hc1[6]*_t124);
  const double _t138 = (0.1e1 / 0.144e3)*_hc1[7];
  const double _t140 = _t139*_t62;
  const double _t143 = (0.5e1 / 0.72e2)*_t106;
  const double _t144 = _hc1[15]*_t64;
  const double _t147 = -_t113*_t146 - _t141*_t34 - _t142*_t143 - _t144*_t145;
  const double _t148 = my_piecewise3(_t11, 0, _hc0[0]*_t147 - _t138*_t140);
  const double _t149 = (0.1e1 / 0.144e3)*_hc1[8];
  const double _t151 = -_hc1[16]*_t150 - _t117*_t146 - _t141*_t39 - _t142*_t144;
  const double _t152 = my_piecewise3(_t11, 0, _hc0[0]*_t151 - _t140*_t149);
  const double _t154 = _hc0[2]*_t153;
  const double _t158 = _t121*_t157;
  const double _t162 = _t113*tau_s;
  const double _t164 = -_t117*_t163 - _t158*_t159 - _t160*_t45 - _t161*_t162;
  const double _t165 = my_piecewise3(_t11, 0, _hc0[0]*_t164 - _hc1[9]*_t154*_t156);
  const double _t166 = (0.2e1 / 0.9e1)*_t19;
  const double _t167 = _t166*_t59;
  const double _t168 = (0.1e1 / 0.36e2)*_hc1[1];
  const double _t169 = _t35*_t78;
  const double _t170 = _t19*_t81;
  const double _t172 = _hc1[5]*_t171;
  const double _t176 = -_hc1[11]*_t175 - _hc1[12]*_t56 - _hc1[15]*_t53 - _t88;
  const double _t178 = -_hc1[11]*_t56 - _hc1[14]*_t53 - _t127*_t49 - _t92;
  const double _t180 = -_hc1[14]*_t175 - _hc1[15]*_t56 - _hc1[17]*_t53 - _t95;
  const double _t181 = _hc1[7]*_t174 + _t171*_t50 + _t172*lapl_s - _t176*_t177 - _t178*_t179 - _t180*_t26 + _t83 - _t94;
  const double _t182 = my_piecewise3(_t11, 0, _hc0[0]*_t181 + _hc1[1]*_t167 + _t168*_t169 - _t170*_t54);
  const double _t183 = (0.1e1 / 0.36e2)*_hc1[2];
  const double _t185 = -_hc1[12]*_t175 - _hc1[13]*_t56 - _hc1[16]*_t53 - _t89;
  const double _t186 = -_hc1[15]*_t175 - _hc1[16]*_t56 - _hc1[18]*_t53 - _t96;
  const double _t187 = _hc1[6]*_t184 + _hc1[8]*_t174 + _t172*tau_s - _t176*_t179 - _t177*_t185 - _t186*_t26 + _t84 - _t91;
  const double _t188 = my_piecewise3(_t11, 0, _hc0[0]*_t187 + _hc1[2]*_t167 + _t169*_t183 - _t170*_t57);
  const double _t190 = _hc0[5]*_t41;
  const double _t191 = _hc1[3]*_t62;
  const double _t194 = _t193*_t45;
  const double _t197 = _hc1[15]*_t65;
  const double _t199 = -_hc1[16]*_t198 - _t117*_t69 - _t197*tau_s - _t25*_t39;
  const double _t200 = _t199*_t21;
  const double _t201 = -_t113*_t69 - _t143*_t41*tau_s - _t197*lapl_s - _t25*_t34;
  const double _t202 = _t201*_t21;
  const double _t204 = _hc1[19]*_t44;
  const double _t205 = -_hc1[17]*_t203 - _hc1[18]*_t198 - _hc1[9]*_t196 - _t204*_t69;
  const double _t206 = _t16*_t86 + _t192*_t63 + _t192*_t66 + _t194*_t195 - _t196*_t97 - _t200*lapl_s - _t202*tau_s - _t205*_t26;
  const double _t207 = my_piecewise3(_t11, 0, _hc0[0]*_t206 + (0.1e1 / 0.108e3)*_t100*_t191 - _t170*_t70 + _t189*_t190*_t60);
  const double _t208 = _hc0[9]/M_PI;
  const double _t209 = _t208*_t59;
  const double _t210 = (0.14e2 / 0.27e2)*_t19;
  const double _t211 = _hc1[0]*_t78;
  const double _t212 = _hc0[2]*_t18*_t4;
  const double _t214 = _hc1[1]*_t213;
  const double _t215 = _hc1[2]*_t213;
  const double _t218 = _hc1[5]*_t82;
  const double _t219 = _hc1[6]*_t82;
  const double _t220 = _hc1[12]*_t21;
  const double _t221 = _hc1[13]*_t21;
  const double _t222 = -_hc1[16]*_t26 - _t220*tau_s - _t221*lapl_s;
  const double _t223 = _t21*_t222;
  const double _t224 = _hc1[11]*_t21;
  const double _t225 = -_hc1[15]*_t26 - _t220*lapl_s - _t224*tau_s;
  const double _t226 = _t21*_t225;
  const double _t227 = _hc1[15]*_t21;
  const double _t228 = _hc1[16]*_t21;
  const double _t229 = -_hc1[18]*_t26 - _t227*tau_s - _t228*lapl_s;
  const double _t230 = _hc1[8]*_t87 + _t218*tau_s + _t219*lapl_s - _t223*lapl_s - _t226*tau_s - _t229*_t26;
  const double _t231 = _t21*_t230;
  const double _t232 = _hc1[4]*_t82;
  const double _t233 = _hc1[10]*_t21;
  const double _t234 = -_hc1[14]*_t26 - _t224*lapl_s - _t233*tau_s;
  const double _t235 = _t21*_t234;
  const double _t236 = _hc1[14]*_t21;
  const double _t237 = -_hc1[17]*_t26 - _t227*lapl_s - _t236*tau_s;
  const double _t238 = _hc1[7]*_t87 + _t218*lapl_s - _t226*lapl_s + _t232*tau_s - _t235*tau_s - _t237*_t26;
  const double _t239 = _t21*_t238;
  const double _t240 = _hc1[7]*_t82;
  const double _t241 = _hc1[8]*_t82;
  const double _t242 = _hc1[9]*_t86;
  const double _t243 = _t21*_t229;
  const double _t244 = _t21*_t237;
  const double _t245 = _hc1[17]*_t21;
  const double _t246 = _hc1[18]*_t21;
  const double _t247 = -_hc1[19]*_t26 - _t245*tau_s - _t246*lapl_s;
  const double _t248 = _t240*tau_s + _t241*lapl_s + _t242*_t7 - _t243*lapl_s - _t244*tau_s - _t247*_t26;
  const double _t249 = -_hc1[3]*_t217 + (0.22e2 / 0.27e2)*_t1*_t5*_t85*_t97*sigma_ss - _t214*tau_s - _t215*lapl_s - _t231*lapl_s - _t239*tau_s + (0.80e2 / 0.9e1)*_t24*_t90*lapl_s + (0.80e2 / 0.9e1)*_t24*_t93*tau_s - _t248*_t26;
  const double _t250 = my_piecewise3(_t11, 0, _hc0[0]*_t249 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t27*_t73 + (0.1e1 / 0.12e2)*_hc0[5]*_t27*_t42*_t76*_t8 - _hc1[0]*_t210*_t29 - _t209*_t75 - _t211*_t25 - _t212*_t98);
#endif
#if _KMAX >= 4
  const double _t251 = _hc0[0]*_t153;
  const double _t253 = _t252*_t36*_t6;
  const double _t254 = _hc1[29]*_t44;
  const double _t256 = _t255*_t46;
  const double _t257 = _t256*_t44;
  const double _t258 = _hc1[32]*_t120;
  const double _t260 = _t122*_t259;
  const double _t261 = _hc1[33]*_t120;
  const double _t263 = _hc1[34]*_t1/(M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t264 = _t20*_t67;
  const double _t267 = _hc1[20]*tau_s;
  const double _t268 = _hc1[21]*_t266;
  const double _t270 = _hc1[22]*_t266;
  const double _t271 = _hc1[23]*_t266;
  const double _t272 = (0.1e1 / 0.144e3)*_t193*_t62;
  const double _t281 = _hc0[2]*_t156*_t280;
  const double _t285 = _t254*tau_s;
  const double _t286 = _hc1[30]*_t44;
  const double _t287 = _t284*_t286;
  const double _t288 = _hc1[31]*_t44;
  const double _t290 = _t139*_t166;
  const double _t291 = (0.1e1 / 0.36e2)*_t107*_t78;
  const double _t294 = _hc1[11]*_t293;
  const double _t298 = -_hc1[11]*_t125 - _hc1[21]*_t297 - _hc1[22]*_t135 - _hc1[26]*_t129;
  const double _t299 = _hc1[12]*_t293;
  const double _t300 = -_hc1[12]*_t125 - _hc1[22]*_t297 - _hc1[23]*_t135 - _hc1[27]*_t129;
  const double _t301 = _hc1[13]*lapl_s;
  const double _t302 = _hc0[5]*_t189;
  const double _t303 = _t114*_t302;
  const double _t304 = (0.1e1 / 0.108e3)*_t154*_t61;
  const double _t307 = -_hc1[15]*_t305 - _hc1[26]*_t306 - _hc1[27]*_t150 - _t146*_t286;
  const double _t312 = _hc1[32]*_t44;
  const double _t313 = _hc1[33]*_t44;
  const double _t314 = _t139*_t208;
  const double _t315 = _t100*_t210;
  const double _t316 = (0.1e1 / 0.9e1)*_t190*_t77;
  const double _t318 = _hc1[5]*_t317;
  const double _t321 = -_hc1[22]*_t175 - _hc1[23]*_t56 - _hc1[27]*_t53 - _t220;
  const double _t322 = -_hc1[21]*_t175 - _hc1[22]*_t56 - _hc1[26]*_t53 - _t224;
  const double _t323 = -_hc1[26]*_t175 - _hc1[27]*_t56 - _hc1[30]*_t53 - _t227;
  const double _t324 = _hc1[11]*_t320 + _hc1[12]*_t184 + _hc1[15]*_t174 - _t177*_t321 - _t179*_t322 + _t218 - _t226 - _t26*_t323;
  const double _t325 = -_hc1[25]*_t175 - _hc1[26]*_t56 - _hc1[29]*_t53 - _t236;
  const double _t326 = _hc1[6]*lapl_s;
  const double _t327 = -_hc1[27]*_t175 - _hc1[28]*_t56 - _hc1[31]*_t53 - _t228;
  const double _t328 = _hc1[3]*_t153;
  const double _t330 = _hc1[15]*_t192;
  const double _t333 = -_hc1[15]*_t196 - _hc1[26]*_t203 - _hc1[27]*_t198 - _t286*_t69;
  const double _t334 = -_hc1[18]*_t196 - _hc1[30]*_t203 - _hc1[31]*_t198 - _t313*_t69;
  const double _t335 = -_hc1[17]*_t196 - _hc1[29]*_t203 - _hc1[30]*_t198 - _t312*_t69;
  const double _t339 = _hc1[5]*_t213;
  const double _t341 = -_hc1[22]*_t179 - _hc1[23]*_t177 - _hc1[27]*_t26;
  const double _t342 = -_hc1[27]*_t179 - _hc1[28]*_t177 - _hc1[31]*_t26;
  const double _t344 = -_hc1[21]*_t179 - _hc1[22]*_t177 - _hc1[26]*_t26;
  const double _t345 = -_hc1[26]*_t179 - _hc1[27]*_t177 - _hc1[30]*_t26;
  const double _t346 = _hc1[11]*_t340 + _hc1[12]*_t343 + _hc1[15]*_t87 - _t177*_t341 - _t179*_t344 - _t26*_t345;
  const double _t347 = -_hc1[30]*_t179 - _hc1[31]*_t177 - _hc1[33]*_t26;
  const double _t348 = _hc1[15]*_t340 + _hc1[16]*_t343 + _hc1[18]*_t87 - _t177*_t342 - _t179*_t345 - _t26*_t347;
  const double _t349 = -_hc1[25]*_t179 - _hc1[26]*_t177 - _hc1[29]*_t26;
  const double _t350 = -_hc1[29]*_t179 - _hc1[30]*_t177 - _hc1[32]*_t26;
  const double _t351 = _hc1[14]*_t340 + _hc1[15]*_t343 + _hc1[17]*_t87 - _t177*_t345 - _t179*_t349 - _t26*_t350;
#endif

  const double f = my_piecewise3(_t11, 0, _t12*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t11, 0, _t14*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t11, 0, _t15*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t11, 0, _t17*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t11, 0, _t12 + _t28*n_s);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t11, 0, _t31*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = my_piecewise3(_t11, 0, _t32*n_s);
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t11, 0, _t33*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t11, 0, _t38*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t11, 0, _t40*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t11, 0, _t47*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t11, 0, _t14 + _t55*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t11, 0, _t15 + _t58*n_s);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t11, 0, _t17 + _t71*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t11, 0, 0.2e1*_t28 + _t99*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t11, 0, _t102*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = my_piecewise3(_t11, 0, _t103*n_s);
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = my_piecewise3(_t11, 0, _t104*n_s);
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t11, 0, _t105*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t11, 0, _t109*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = my_piecewise3(_t11, 0, _t111*n_s);
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t11, 0, _t112*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t11, 0, _t116*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t11, 0, _t118*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t11, 0, _t123*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t11, 0, _t131*n_s + _t31);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = my_piecewise3(_t11, 0, _t134*n_s + _t32);
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t11, 0, _t137*n_s + _t33);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t11, 0, _t148*n_s + _t38);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t11, 0, _t152*n_s + _t40);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t11, 0, _t165*n_s + _t47);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t11, 0, _t182*n_s + 0.2e1*_t55);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t11, 0, _t188*n_s + 0.2e1*_t58);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t11, 0, _t207*n_s + 0.2e1*_t71);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t11, 0, _t250*n_s + 0.3e1*_t99);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[20]*_t251));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[21]*_t251));
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[22]*_t251));
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[23]*_t251));
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[24]*_t251));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[25]*_t253));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[26]*_t253));
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[27]*_t253));
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[28]*_t253));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _t254*_t256));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[30]*_t257));
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc1[31]*_t257));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _t258*_t260));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _t260*_t261));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, (0.1e1 / 0.55296e5)*_hc0[0]*_t262*_t263));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t11, 0, _t102 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[10]*_t265 - _hc1[25]*_t269 - _t266*_t267 - _t268*lapl_s) - _hc1[10]*_t264));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = my_piecewise3(_t11, 0, _t103 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[11]*_t265 - _hc1[26]*_t269 - _t268*tau_s - _t270*lapl_s) - _hc1[11]*_t264));
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = my_piecewise3(_t11, 0, _t104 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[12]*_t265 - _hc1[27]*_t269 - _t270*tau_s - _t271*lapl_s) - _hc1[12]*_t264));
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t11, 0, _t105 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[13]*_t265 - _hc1[24]*_t266*lapl_s - _hc1[28]*_t269 - _t271*tau_s) - _hc1[13]*_t264));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t11, 0, _t109 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[25]*_t275 - _hc1[26]*_t276 - _t106*_t273 - _t254*_t277) - _hc1[14]*_t272));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = my_piecewise3(_t11, 0, _t111 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[15]*_t278 - _hc1[26]*_t275 - _hc1[27]*_t276 - _hc1[30]*_t279) - _hc1[15]*_t272));
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t11, 0, _t112 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[16]*_t278 - _hc1[27]*_t275 - _hc1[28]*_t276 - _hc1[31]*_t279) - _hc1[16]*_t272));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t11, 0, _t116 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_t113*_t283 - _t258*_t282 - _t284*_t285 - _t287*lapl_s) - _hc1[17]*_t281));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t11, 0, _t118 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_t117*_t283 - _t261*_t282 - _t284*_t288*lapl_s - _t287*tau_s) - _hc1[18]*_t281));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t11, 0, _t123 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-0.1e1 / 0.288e3*_t158 - _t258*_t289*tau_s - _t261*_t289*lapl_s - 0.1e1 / 0.20736e5*_t263*sigma_ss/xc_powr(n_s, 35, 3)) - 0.1e1 / 0.13824e5*_hc0[2]*_hc1[19]*_t1/((M_PI * M_PI * M_PI * M_PI * M_CBRTPI)*xc_powr(n_s, 28, 3))));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t11, 0, 0.2e1*_t131 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(_hc1[14]*_t295 + _hc1[4]*_t292 + _t127*_t293 - _t177*_t298 - _t178*_t296 - _t179*(-_hc1[10]*_t125 - _hc1[21]*_t135 - _hc1[25]*_t129 - _t126*_t267) - _t26*(-_hc1[14]*_t125 - _hc1[25]*_t297 - _hc1[26]*_t135 - _hc1[29]*_t129) + _t294*lapl_s) + _hc1[4]*_t290 + _hc1[4]*_t291 - _t130*_t170));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = my_piecewise3(_t11, 0, 0.2e1*_t134 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(_hc1[15]*_t295 + _hc1[5]*_t292 - _t176*_t296 - _t177*_t300 - _t179*_t298 - _t26*(-_hc1[15]*_t125 - _hc1[26]*_t297 - _hc1[27]*_t135 - _hc1[30]*_t129) + _t294*tau_s + _t299*lapl_s) + _hc1[5]*_t290 + _hc1[5]*_t291 - _t133*_t170));
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t11, 0, 0.2e1*_t137 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(_hc1[16]*_t295 + _hc1[6]*_t292 - _t177*(-_hc1[13]*_t125 - _hc1[23]*_t297 - _hc1[24]*_t135 - _hc1[28]*_t129) - _t179*_t300 - _t185*_t296 - _t26*(-_hc1[16]*_t125 - _hc1[27]*_t297 - _hc1[28]*_t135 - _hc1[31]*_t129) + _t293*_t301 + _t299*tau_s) + _hc1[6]*_t290 + _hc1[6]*_t291 - _t136*_t170));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t11, 0, 0.2e1*_t148 + n_s*my_piecewise3(_t11, 0, _hc0[0]*((0.5e1 / 0.27e2)*_hc1[14]*_t1*_t119*_t5*tau_s + (0.5e1 / 0.27e2)*_hc1[15]*_t1*_t119*_t5*lapl_s + (0.11e2 / 0.648e3)*_hc1[17]*_t157*_t42*_t43*sigma_ss + (0.16e2 / 0.27e2)*_hc1[7]*_t1*_t5*_t67 - _t177*_t307 - _t179*(-_hc1[25]*_t306 - _hc1[26]*_t150 - _t106*_t141 - _t146*_t254) - _t180*_t196 - _t202 - _t26*(-_hc1[17]*_t305 - _hc1[29]*_t306 - _hc1[30]*_t150 - _hc1[32]*_t308)) + _hc1[7]*_t304 + _t138*_t303 - _t147*_t170));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t11, 0, 0.2e1*_t152 + n_s*my_piecewise3(_t11, 0, _hc0[0]*((0.5e1 / 0.27e2)*_hc1[15]*_t1*_t119*_t5*tau_s + (0.5e1 / 0.27e2)*_hc1[16]*_t1*_t119*_t5*lapl_s + (0.11e2 / 0.648e3)*_hc1[18]*_t157*_t42*_t43*sigma_ss + (0.16e2 / 0.27e2)*_hc1[8]*_t1*_t5*_t67 - _t177*(-_hc1[16]*_t305 - _hc1[27]*_t306 - _hc1[28]*_t150 - _t146*_t288) - _t179*_t307 - _t186*_t196 - _t200 - _t26*(-_hc1[18]*_t305 - _hc1[30]*_t306 - _hc1[31]*_t150 - _hc1[33]*_t308)) + _hc1[8]*_t304 + _t149*_t303 - _t151*_t170));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t11, 0, 0.2e1*_t165 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(_t117*_t309*lapl_s + (0.11e2 / 0.2592e4)*_t121*sigma_ss/xc_powi(n_s, 10) + _t162*_t309 - _t177*(-_t117*_t160 - _t163*_t288 - _t261*_t310 - _t286*_t311) - _t179*(-_t113*_t160 - _t161*_t285 - _t163*_t286 - _t258*_t310) + (0.11e2 / 0.324e3)*_t194 - 0.2e1 / 0.9e1*_t205*_t24*_t6 - _t26*(-_hc1[34]*_t120*_t310 - _t160*_t204 - _t163*_t313 - _t311*_t312)) + (0.1e1 / 0.432e3)*_hc0[2]*_hc1[9]*_t155*_t252 + (0.1e1 / 0.3456e4)*_hc0[5]*_hc1[9]*_t1*_t119/(M_PI * M_PI * M_PI * M_CBRTPI) - _t164*_t170));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t11, 0, 0.3e1*_t182 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[7]*_t319 + (0.22e2 / 0.27e2)*_t1*_t180*_t5*_t85*sigma_ss + (0.80e2 / 0.9e1)*_t176*_t24*lapl_s - _t177*_t324 + (0.80e2 / 0.9e1)*_t178*_t24*tau_s - _t179*(_hc1[11]*_t184 + _hc1[14]*_t174 + _t127*_t171 - _t177*_t322 - _t179*(-_hc1[20]*_t175 - _hc1[21]*_t56 - _hc1[25]*_t53 - _t233) + _t232 - _t235 - _t26*_t325) - _t214 - _t239 + (0.80e2 / 0.9e1)*_t24*_t93 - _t26*(_hc1[14]*_t320 + _hc1[15]*_t184 + _hc1[17]*_t174 - _t177*_t323 - _t179*_t325 + _t240 - _t244 - _t26*(-_hc1[29]*_t175 - _hc1[30]*_t56 - _hc1[32]*_t53 - _t245)) - _t317*_t50 - _t318*lapl_s) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t54*_t73 + (0.1e1 / 0.12e2)*_hc0[5]*_t42*_t54*_t76*_t8 - _hc1[1]*_t315 - _hc1[1]*_t316 - _t168*_t314 - _t181*_t212));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t11, 0, 0.3e1*_t188 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[8]*_t319 + (0.22e2 / 0.27e2)*_t1*_t186*_t5*_t85*sigma_ss + (0.80e2 / 0.9e1)*_t176*_t24*tau_s - _t177*(_hc1[12]*_t320 + _hc1[13]*_t184 + _hc1[16]*_t174 - _t177*(-_hc1[23]*_t175 - _hc1[24]*_t56 - _hc1[28]*_t53 - _t221) - _t179*_t321 + _t219 - _t223 - _t26*_t327) - _t179*_t324 + (0.80e2 / 0.9e1)*_t185*_t24*lapl_s - _t215 - _t231 + (0.80e2 / 0.9e1)*_t24*_t90 - _t26*(_hc1[15]*_t320 + _hc1[16]*_t184 + _hc1[18]*_t174 - _t177*_t327 - _t179*_t323 + _t241 - _t243 - _t26*(-_hc1[30]*_t175 - _hc1[31]*_t56 - _hc1[33]*_t53 - _t246)) - _t317*_t326 - _t318*tau_s) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t57*_t73 + (0.1e1 / 0.12e2)*_hc0[5]*_t42*_t57*_t76*_t8 - _hc1[2]*_t315 - _hc1[2]*_t316 - _t183*_t314 - _t187*_t212));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t11, 0, 0.3e1*_t207 + n_s*my_piecewise3(_t11, 0, _hc0[0]*((0.22e2 / 0.27e2)*_t1*_t205*_t5*_t85*sigma_ss + (0.22e2 / 0.27e2)*_t1*_t5*_t85*_t97 - _t16*_t216 - _t177*(_hc1[16]*_t331 + _t117*_t332 - _t177*(-_hc1[16]*_t196 - _hc1[27]*_t203 - _hc1[28]*_t198 - _t288*_t69) - _t179*_t333 - _t196*_t229 - _t26*_t334 + _t330*tau_s + _t39*_t86) - _t179*((0.5e1 / 0.27e2)*_t106*_t67*tau_s + _t113*_t332 - _t177*_t333 - _t179*(-_hc1[14]*_t196 - _hc1[25]*_t203 - _hc1[26]*_t198 - _t254*_t69) - _t196*_t237 - _t26*_t335 + _t330*lapl_s + _t34*_t86) - _t196*_t248 + (0.80e2 / 0.9e1)*_t199*_t24*lapl_s + (0.80e2 / 0.9e1)*_t201*_t24*tau_s - _t26*(_hc1[17]*_t192*tau_s + _hc1[18]*_t331 - _t177*_t334 - _t179*_t335 - _t196*_t247 + _t204*_t332 + _t242*_t6 - _t26*(-_hc1[19]*_t196 - _hc1[32]*_t203 - _hc1[33]*_t198 - _hc1[34]*_t44*_t69)) - 0.77e2 / 0.972e3*_t280*_t45*sigma_ss - _t329*_t63 - _t329*_t66) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t70*_t73 + (0.1e1 / 0.12e2)*_hc0[5]*_t42*_t70*_t76*_t8 - 0.1e1 / 0.864e3*_hc0[9]*_t1*_t328/(M_PI * M_PI * M_CBRTPI) - 0.1e1 / 0.36e2*_hc1[3]*_t302*_t67 - 0.7e1 / 0.324e3*_t107*_t191 - _t206*_t212));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t11, 0, 0.4e1*_t250 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(_hc1[1]*_t336*tau_s + _hc1[2]*_t336*lapl_s - 0.154e3 / 0.27e2*_t139*_t7*_t97 - _t177*(-_hc1[8]*_t217 + (0.22e2 / 0.27e2)*_t1*_t229*_t5*_t85*sigma_ss - _t177*(_hc1[12]*_t340 + _hc1[16]*_t87 - _t177*(-_hc1[23]*_t179 - _hc1[24]*_t177 - _hc1[28]*_t26) - _t179*_t341 - _t26*_t342 + _t301*_t82) - _t179*_t346 - _t213*_t326 + (0.80e2 / 0.9e1)*_t222*_t24*lapl_s + (0.80e2 / 0.9e1)*_t225*_t24*tau_s - _t26*_t348 - _t339*tau_s) - _t179*(-_hc1[7]*_t217 + (0.22e2 / 0.27e2)*_t1*_t237*_t5*_t85*sigma_ss - _t177*_t346 - _t179*(_hc1[11]*_t343 + _hc1[14]*_t87 + _t127*_t82 - _t177*_t344 - _t179*(-_hc1[20]*_t179 - _hc1[21]*_t177 - _hc1[25]*_t26) - _t26*_t349) - _t213*_t50 + (0.80e2 / 0.9e1)*_t225*_t24*lapl_s + (0.80e2 / 0.9e1)*_t234*_t24*tau_s - _t26*_t351 - _t339*lapl_s) + _t230*_t338*lapl_s + _t238*_t338*tau_s + (0.11e2 / 0.9e1)*_t248*_t7*_t85 - _t26*(-_hc1[9]*_t217 + (0.22e2 / 0.27e2)*_t1*_t247*_t5*_t85*sigma_ss - _t177*_t348 - _t179*_t351 - _t213*_t63 - _t213*_t66 + (0.80e2 / 0.9e1)*_t229*_t24*lapl_s + (0.80e2 / 0.9e1)*_t237*_t24*tau_s - _t26*(_hc1[17]*_t340 + _hc1[18]*_t343 + _hc1[19]*_t87 - _t177*_t347 - _t179*_t350 - _t26*(-_hc1[32]*_t179 - _hc1[33]*_t177 - _hc1[34]*_t26))) + (0.2618e4 / 0.243e3)*_t328*_t7 - _t337*_t90*lapl_s - _t337*_t93*tau_s) + (0.1e1 / 0.216e3)*_hc0[14]*_hc1[0]*_t41*_t6 + (0.140e3 / 0.81e2)*_hc1[0]*_t19*_t35 + _t100*_t208*_t72 - 0.2e1 / 0.3e1*_t18*_t19*_t249 - 0.1e1 / 0.9e1*_t209*_t27 + (0.40e2 / 0.81e2)*_t211*_t85 - 0.4e1 / 0.9e1*_t24*_t27*_t78 - 0.56e2 / 0.27e2*_t29*_t80 + (0.4e1 / 0.3e1)*_t74*_t98 + (0.1e1 / 0.6e1)*_t79*_t98));
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
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, 0, 0, _t3, _hc1);
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc1[3];
  const double dF_dta = _hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, _t2, (0.1e1 / 0.2e1)*la, _t3, _hc2);
  double _hc3[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, 0, 0, 0, _hc3);
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc2[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dta = (0.1e1 / 0.2e1)*_hc0[11];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc3[10];
  const double d2F_dgaa_dta = (0.1e1 / 0.4e1)*_hc1[8];
  const double d2F_dta2 = (0.1e1 / 0.2e1)*_hc0[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc2[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc2[33];
  const double d3F_dna2_dta = (0.1e1 / 0.4e1)*_hc2[31];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dta = (0.1e1 / 0.8e1)*_hc0[28];
  const double d3F_dna_dta2 = (0.1e1 / 0.4e1)*_hc0[25];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc3[24];
  const double d3F_dgaa2_dta = (0.1e1 / 0.16e2)*_hc3[22];
  const double d3F_dgaa_dta2 = (0.1e1 / 0.8e1)*_hc1[19];
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
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc2[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc2[68];
  const double d4F_dna3_dta = (0.1e1 / 0.8e1)*_hc2[66];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc2[65];
  const double d4F_dna2_dgaa_dta = (0.1e1 / 0.16e2)*_hc2[63];
  const double d4F_dna2_dta2 = (0.1e1 / 0.8e1)*_hc2[60];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dta = (0.1e1 / 0.32e2)*_hc0[57];
  const double d4F_dna_dgaa_dta2 = (0.1e1 / 0.16e2)*_hc0[54];
  const double d4F_dna_dta3 = (0.1e1 / 0.8e1)*_hc0[50];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc3[49];
  const double d4F_dgaa3_dta = (0.1e1 / 0.64e2)*_hc3[47];
  const double d4F_dgaa2_dta2 = (0.1e1 / 0.32e2)*_hc3[44];
  const double d4F_dgaa_dta3 = (0.1e1 / 0.16e2)*_hc1[40];
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
  double _hc2[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, 0, 0, ta, _hc2);
  double _hc3[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, 0, 0, tb, _hc3);
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc2[3];
  const double dF_dgbb = _hc3[3];
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
  double _hc4[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, la, ta, _hc4);
  double _hc5[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, lb, tb, _hc5);
  double _hc6[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, 0, 0, 0, _hc6);
  double _hc7[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, 0, 0, 0, _hc7);
  const double d2F_dna2 = _hc4[14];
  const double d2F_dnb2 = _hc5[14];
  const double d2F_dna_dgaa = _hc0[13];
  const double d2F_dnb_dgbb = _hc1[13];
  const double d2F_dna_dta = _hc0[11];
  const double d2F_dnb_dtb = _hc1[11];
  const double d2F_dgaa2 = _hc6[10];
  const double d2F_dgbb2 = _hc7[10];
  const double d2F_dgaa_dta = _hc2[8];
  const double d2F_dgbb_dtb = _hc3[8];
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
  const double d3F_dna3 = _hc4[34];
  const double d3F_dnb3 = _hc5[34];
  const double d3F_dna2_dgaa = _hc4[33];
  const double d3F_dnb2_dgbb = _hc5[33];
  const double d3F_dna2_dta = _hc4[31];
  const double d3F_dnb2_dtb = _hc5[31];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dta = _hc0[28];
  const double d3F_dnb_dgbb_dtb = _hc1[28];
  const double d3F_dna_dta2 = _hc0[25];
  const double d3F_dnb_dtb2 = _hc1[25];
  const double d3F_dgaa3 = _hc6[24];
  const double d3F_dgbb3 = _hc7[24];
  const double d3F_dgaa2_dta = _hc6[22];
  const double d3F_dgbb2_dtb = _hc7[22];
  const double d3F_dgaa_dta2 = _hc2[19];
  const double d3F_dgbb_dtb2 = _hc3[19];
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
  const double d4F_dna4 = _hc4[69];
  const double d4F_dnb4 = _hc5[69];
  const double d4F_dna3_dgaa = _hc4[68];
  const double d4F_dnb3_dgbb = _hc5[68];
  const double d4F_dna3_dta = _hc4[66];
  const double d4F_dnb3_dtb = _hc5[66];
  const double d4F_dna2_dgaa2 = _hc4[65];
  const double d4F_dnb2_dgbb2 = _hc5[65];
  const double d4F_dna2_dgaa_dta = _hc4[63];
  const double d4F_dnb2_dgbb_dtb = _hc5[63];
  const double d4F_dna2_dta2 = _hc4[60];
  const double d4F_dnb2_dtb2 = _hc5[60];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dta = _hc0[57];
  const double d4F_dnb_dgbb2_dtb = _hc1[57];
  const double d4F_dna_dgaa_dta2 = _hc0[54];
  const double d4F_dnb_dgbb_dtb2 = _hc1[54];
  const double d4F_dna_dta3 = _hc0[50];
  const double d4F_dnb_dtb3 = _hc1[50];
  const double d4F_dgaa4 = _hc6[49];
  const double d4F_dgbb4 = _hc7[49];
  const double d4F_dgaa3_dta = _hc6[47];
  const double d4F_dgbb3_dtb = _hc7[47];
  const double d4F_dgaa2_dta2 = _hc6[44];
  const double d4F_dgbb2_dtb2 = _hc7[44];
  const double d4F_dgaa_dta3 = _hc2[40];
  const double d4F_dgbb_dtb3 = _hc3[40];
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