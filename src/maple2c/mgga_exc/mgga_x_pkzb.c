/*
  Generated from python/mgga_exc/mgga_x_pkzb.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_pkzb
*/

#ifndef _MGGA_X_PKZB_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_PKZB_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_PKZB_HELPER_BODIES
#include "mgga_x_pkzb.c"
#undef _MGGA_X_PKZB_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_PKZB_HELPER_BODIES
#include "mgga_x_pkzb.c"
#undef _MGGA_X_PKZB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_PKZB_HELPER_BODIES
#include "mgga_x_pkzb.c"
#undef _MGGA_X_PKZB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_PKZB_HELPER_BODIES
#include "mgga_x_pkzb.c"
#undef _MGGA_X_PKZB_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_PKZB_HELPER_BODIES
#include "mgga_x_pkzb.c"
#undef _MGGA_X_PKZB_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_pkzb.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_PKZB_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pkzb_xx_k, _KMAX)(const xc_func_type *p, double p_, double qt, double *out) {


  const double f = 0.019302866857603463*(p_ * p_) + (0.10e2 / 0.81e2)*p_ + (0.146e3 / 0.2025e4)*((-0.5e1 / 0.4e1*p_ + qt) * (-0.5e1 / 0.4e1*p_ + qt));
  out[0] = f;
#if _KMAX >= 1
  const double df_dqt = -0.73e2 / 0.405e3*p_ + (0.292e3 / 0.2025e4)*qt;
  out[1] = df_dqt;
  const double df_dp_ = 0.26391437569051557*p_ - 0.73e2 / 0.405e3*qt + 0.10e2 / 0.81e2;
  out[2] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_dqt2 = 0.292e3 / 0.2025e4;
  out[3] = d2f_dqt2;
  const double d2f_dp__dqt = -0.73e2 / 0.405e3;
  out[4] = d2f_dp__dqt;
  const double d2f_dp_2 = 0.26391437569051557;
  out[5] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_dqt3 = 0;
  out[6] = d3f_dqt3;
  const double d3f_dp__dqt2 = 0;
  out[7] = d3f_dp__dqt2;
  const double d3f_dp_2_dqt = 0;
  out[8] = d3f_dp_2_dqt;
  const double d3f_dp_3 = 0;
  out[9] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_dqt4 = 0;
  out[10] = d4f_dqt4;
  const double d4f_dp__dqt3 = 0;
  out[11] = d4f_dp__dqt3;
  const double d4f_dp_2_dqt2 = 0;
  out[12] = d4f_dp_2_dqt2;
  const double d4f_dp_3_dqt = 0;
  out[13] = d4f_dp_3_dqt;
  const double d4f_dp_4 = 0;
  out[14] = d4f_dp_4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pkzb_qt_k, _KMAX)(const xc_func_type *p, double p_, double t, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_PI * M_CBRTPI));

  const double f = (0.1e1 / 0.4e1)*_t1*_t2*t - 0.1e1 / 0.12e2*p_ - 0.9e1 / 0.20e2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = (0.1e1 / 0.4e1)*_t1*_t2;
  out[1] = df_dt;
  const double df_dp_ = -0.1e1 / 0.12e2;
  out[2] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = 0;
  out[3] = d2f_dt2;
  const double d2f_dp__dt = 0;
  out[4] = d2f_dp__dt;
  const double d2f_dp_2 = 0;
  out[5] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 0;
  out[6] = d3f_dt3;
  const double d3f_dp__dt2 = 0;
  out[7] = d3f_dp__dt2;
  const double d3f_dp_2_dt = 0;
  out[8] = d3f_dp_2_dt;
  const double d3f_dp_3 = 0;
  out[9] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = 0;
  out[10] = d4f_dt4;
  const double d4f_dp__dt3 = 0;
  out[11] = d4f_dp__dt3;
  const double d4f_dp_2_dt2 = 0;
  out[12] = d4f_dp_2_dt2;
  const double d4f_dp_3_dt = 0;
  out[13] = d4f_dp_3_dt;
  const double d4f_dp_4 = 0;
  out[14] = d4f_dp_4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pkzb_f_k, _KMAX)(const xc_func_type *p, double p_, double u, double t, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pkzb_qt_k, _KMAX)(p, p_, t, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pkzb_xx_k, _KMAX)(p, p_, _hc0[0], _hc1);
  const double _t1 = _hc1[0] + 0.80400000000000005;
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = 0.80400000000000005*_t2;
#if _KMAX >= 1
  const double _t4 = _hc0[1]*_hc1[1];
  const double _t5 = (0.1e1 / (_t1 * _t1));
  const double _t6 = 0.80400000000000005*_hc1[0];
  const double _t7 = _t5*_t6;
  const double _t8 = _hc0[2]*_hc1[1];
  const double _t9 = _hc1[2] + _t8;
  const double _t10 = -_t9;
  const double _t11 = _t10*_t5;
#endif
#if _KMAX >= 2
  const double _t12 = ((_hc0[1]) * (_hc0[1]));
  const double _t13 = _hc1[3]*_t12;
  const double _t14 = 1.6080000000000001*_t5;
  const double _t15 = ((_hc1[1]) * (_hc1[1]));
  const double _t16 = _t12*_t15;
  const double _t17 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t18 = _t16*_t17;
  const double _t19 = 1.6080000000000001*_hc1[0];
  const double _t20 = 0.80400000000000005*_t4;
  const double _t21 = _t5*_t9;
  const double _t22 = _hc0[1]*_hc1[4];
  const double _t23 = _hc0[2]*_hc1[3];
  const double _t24 = _hc0[1]*_t23;
  const double _t25 = _t22 + _t24;
  const double _t26 = -_t25;
  const double _t27 = _t17*_t4;
  const double _t28 = _t10*_t19;
  const double _t29 = _hc0[2]*_hc1[4];
  const double _t30 = _hc0[2]*(_hc1[4] + _t23);
  const double _t31 = _hc1[5] + _t29 + _t30;
  const double _t32 = 1.6080000000000001*_t11;
  const double _t33 = -_t31;
  const double _t34 = -0.2e1*_hc1[2] - 0.2e1*_t8;
  const double _t35 = _t17*_t34;
  const double _t36 = _t10*_t6;
#endif
#if _KMAX >= 3
  const double _t37 = 4.8240000000000007*_t5;
  const double _t38 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t39 = _hc1[1]*_hc1[3]*_t38;
  const double _t40 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t41 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t42 = _t38*_t40;
  const double _t43 = 4.8239999999999998*_t41*_t42;
  const double _t44 = 0.80400000000000005*_t13;
  const double _t45 = _t25*_t4;
  const double _t46 = 3.2160000000000002*_t26;
  const double _t47 = _t13*_t17;
  const double _t48 = 3.2160000000000002*_t18;
  const double _t49 = _t31*_t5;
  const double _t50 = _t10*_t9;
  const double _t51 = 3.2160000000000002*_t50;
  const double _t52 = _t33*_t5;
  const double _t53 = _t10*_t35;
  const double _t54 = _t26*_t35;
  const double _t55 = -0.2e1*_t22 - 0.2e1*_t24;
  const double _t56 = _t17*_t36;
  const double _t57 = _t19*_t33;
  const double _t58 = _t10*_t34;
  const double _t59 = _t4*_t58;
  const double _t60 = _hc1[0]*_t41;
  const double _t61 = 2.4119999999999999*_t60;
  const double _t62 = 2.4119999999999999*_t5;
  const double _t63 = _t33*_t9;
  const double _t64 = 2.4119999999999999*_t9;
  const double _t65 = -0.2e1*_hc1[5] - 0.2e1*_t29 - 0.2e1*_t30;
  const double _t66 = -0.3e1*_hc1[2] - 0.3e1*_t8;
  const double _t67 = _t41*_t66;
  const double _t68 = _t36*_t67;
#endif
#if _KMAX >= 4
  const double _t69 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t70 = _t41*_t69;
  const double _t71 = 19.295999999999999*((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t72 = ((_hc1[3]) * (_hc1[3]))*_t69;
  const double _t73 = xc_powi(_t1, -5);
  const double _t74 = _hc1[0]*_t73;
  const double _t75 = 4.8239999999999998*_t17;
  const double _t76 = _hc1[0]*_t75;
  const double _t77 = _hc1[3]*_t15;
  const double _t78 = _t25*_t62;
  const double _t79 = _t10*_t17;
  const double _t80 = _t16*_t41;
  const double _t81 = 1.6080000000000001*_t4;
  const double _t82 = _t17*_t55;
  const double _t83 = _t10*_t82;
  const double _t84 = _t34*_t41;
  const double _t85 = 4.8239999999999998*_t4*_t84;
  const double _t86 = 4.8239999999999998*_t80;
  const double _t87 = _hc1[0]*_t33;
  const double _t88 = _t31*_t75;
  const double _t89 = _t10*_t4;
  const double _t90 = _t17*_t65;
  const double _t91 = _t58*_t67;
  const double _t92 = _t26*_t6;
  const double _t93 = _t34*_t67;
  const double _t94 = _t36*_t84;
  const double _t95 = 2.4119999999999999*_t87;
#endif

  const double f = _hc1[0]*_t3 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dt = 0.80400000000000005*_hc0[1]*_hc1[1]*_t2 - _t4*_t7;
  out[1] = df_dt;
  const double df_du = 0;
  out[2] = df_du;
  const double df_dp_ = _t11*_t6 + _t3*_t9;
  out[3] = df_dp_;
#endif
#if _KMAX >= 2
  const double d2f_dt2 = _t13*_t3 - _t13*_t7 - _t14*_t16 + _t18*_t19;
  out[4] = d2f_dt2;
  const double d2f_du_dt = 0;
  out[5] = d2f_du_dt;
  const double d2f_du2 = 0;
  out[6] = d2f_du2;
  const double d2f_dp__dt = _t11*_t20 - _t20*_t21 + _t25*_t3 + _t26*_t7 - _t27*_t28;
  out[7] = d2f_dp__dt;
  const double d2f_dp__du = 0;
  out[8] = d2f_dp__du;
  const double d2f_dp_2 = _t3*_t31 + _t32*_t9 + _t33*_t7 + _t35*_t36;
  out[9] = d2f_dp_2;
#endif
#if _KMAX >= 3
  const double d3f_dt3 = 4.8239999999999998*_hc1[0]*_hc1[1]*_hc1[3]*_t17*_t38 - _hc1[0]*_t43 + 4.8239999999999998*_t17*_t38*_t40 - _t37*_t39;
  out[10] = d3f_dt3;
  const double d3f_du_dt2 = 0;
  out[11] = d3f_du_dt2;
  const double d3f_du2_dt = 0;
  out[12] = d3f_du2_dt;
  const double d3f_du3 = 0;
  out[13] = d3f_du3;
  const double d3f_dp__dt2 = 1.6080000000000001*_hc0[1]*_hc1[1]*_t26*_t5 + 4.8239999999999998*_hc1[0]*_t10*_t12*_t15*_t41 - _hc1[0]*_t27*_t46 + 0.80400000000000005*_hc1[3]*_t10*_t12*_t5 - _t10*_t48 + 1.6080000000000001*_t12*_t15*_t17*_t9 - _t14*_t45 - _t21*_t44 - _t28*_t47;
  out[14] = d3f_dp__dt2;
  const double d3f_dp__du_dt = 0;
  out[15] = d3f_dp__du_dt;
  const double d3f_dp__du2 = 0;
  out[16] = d3f_dp__du2;
  const double d3f_dp_2_dt = _t14*_t26*_t9 - _t20*_t49 + _t20*_t52 + _t20*_t53 + _t25*_t32 - _t27*_t51 - _t27*_t57 + _t54*_t6 + _t55*_t56 - _t59*_t61;
  out[17] = d3f_dp_2_dt;
  const double d3f_dp_2_du = 0;
  out[18] = d3f_dp_2_du;
  const double d3f_dp_3 = 2.4119999999999999*_t11*_t31 + _t34*_t68 + _t35*_t57 + _t53*_t64 + _t56*_t65 + _t62*_t63;
  out[19] = d3f_dp_3;
#endif
#if _KMAX >= 4
  const double d4f_dt4 = -28.943999999999999*_hc1[0]*_t70*_t77 + 28.944000000000003*_t17*_t69*_t77 - _t37*_t72 + _t69*_t71*_t74 - _t70*_t71 + _t72*_t76;
  out[20] = d4f_dt4;
  const double d4f_du_dt3 = 0;
  out[21] = d4f_du_dt3;
  const double d4f_du2_dt2 = 0;
  out[22] = d4f_du2_dt2;
  const double d4f_du3_dt = 0;
  out[23] = d4f_du3_dt;
  const double d4f_du4 = 0;
  out[24] = d4f_du4;
  const double d4f_dp__dt3 = 14.472*_hc1[0]*_hc1[1]*_hc1[3]*_t10*_t38*_t41 + 14.472*_hc1[0]*_t12*_t15*_t26*_t41 + 4.8239999999999998*_hc1[1]*_hc1[3]*_t17*_t38*_t9 + 2.4119999999999999*_hc1[3]*_t12*_t26*_t5 + 14.472*_t10*_t38*_t40*_t41 - 19.295999999999999*_t10*_t42*_t74 + 4.8239999999999998*_t12*_t15*_t17*_t25 - _t13*_t26*_t76 - _t13*_t78 - 9.6479999999999997*_t18*_t26 - 9.6480000000000015*_t39*_t79 - _t43*_t9;
  out[25] = d4f_dp__dt3;
  const double d4f_dp__du_dt2 = 0;
  out[26] = d4f_dp__du_dt2;
  const double d4f_dp__du2_dt = 0;
  out[27] = d4f_dp__du2_dt;
  const double d4f_dp__du3 = 0;
  out[28] = d4f_dp__du3;
  const double d4f_dp_2_dt2 = -_hc1[0]*_t26*_t85 - 4.8239999999999998*_t10*_t4*_t55*_t60 - _t13*_t58*_t61 + 9.6479999999999997*_t16*_t58*_t74 + 1.6080000000000001*_t18*_t31 + _t19*_t26*_t82 + _t25*_t46*_t5 - 6.4320000000000004*_t26*_t27*_t9 - _t33*_t48 - _t44*_t49 + _t44*_t52 + _t44*_t53 - 6.4320000000000004*_t45*_t79 - _t47*_t51 - _t47*_t57 + 9.6479999999999997*_t50*_t80 + _t54*_t81 - _t58*_t86 + _t81*_t83 + _t86*_t87;
  out[29] = d4f_dp_2_dt2;
  const double d4f_dp_2_du_dt = 0;
  out[30] = d4f_dp_2_du_dt;
  const double d4f_dp_2_du2 = 0;
  out[31] = d4f_dp_2_du2;
  const double d4f_dp_3_dt = _t10*_t20*_t90 + _t20*_t91 + 2.4119999999999999*_t25*_t53 + _t26*_t31*_t62 + _t33*_t35*_t81 + _t33*_t78 - _t4*_t63*_t75 - 7.2359999999999998*_t41*_t59*_t9 + _t54*_t64 + _t55*_t68 + _t57*_t82 - 3.2160000000000002*_t59*_t66*_t74 - _t61*_t65*_t89 + _t64*_t83 - _t85*_t87 - _t88*_t89 + _t90*_t92 + _t92*_t93 + _t94*(-0.3e1*_t22 - 0.3e1*_t24);
  out[32] = d4f_dp_3_dt;
  const double d4f_dp_3_du = 0;
  out[33] = d4f_dp_3_du;
  const double d4f_dp_4 = _t28*_t65*_t67 + 4.8239999999999998*_t31*_t52 + _t34*_t36*_t66*_t73*(-0.4e1*_hc1[2] - 0.4e1*_t8) + 6.4320000000000004*_t35*_t63 + _t51*_t90 + _t58*_t88 + 3.2160000000000002*_t9*_t91 + _t90*_t95 + _t93*_t95 + _t94*(-0.3e1*_hc1[5] - 0.3e1*_t29 - 0.3e1*_t30);
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
  const double _t16 = xc_powr(n_s, -4, 3);
  const double _t19 = (0.5e1 / 0.3e1)*_t8;
  const double _t21 = xc_powr(n_s, -11, 3);
  const double _t22 = (0.1e1 / 0.9e1)*_t21;
  const double _t23 = _t22*_t7;
#endif
#if _KMAX >= 2
  const double _t26 = xc_powr(n_s, -10, 3);
  const double _t28 = xc_powr(n_s, -13, 3);
  const double _t32 = xc_powr(n_s, -16, 3);
  const double _t33 = xc_powr(0.6e1, 2, 3);
  const double _t34 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t35 = _t33*_t34;
  const double _t39 = (0.5e1 / 0.3e1)*tau_s;
  const double _t40 = _t28*_t39;
  const double _t41 = (0.1e1 / 0.9e1)*_t7;
  const double _t42 = _t32*_t41;
  const double _t45 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t47 = _t33/(M_PI * M_CBRTPI * M_CBRTPI);
  const double _t49 = (0.5e1 / 0.72e2)*_t32;
  const double _t52 = xc_powr(n_s, -19, 3);
  const double _t53 = (0.1e1 / 0.216e3)*sigma_ss;
  const double _t54 = _t52*_t53;
  const double _t58 = xc_powr(n_s, -7, 3);
  const double _t61 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t62 = _t33*_t61;
  const double _t66 = (0.1e1 / 0.3e1)*_t16;
  const double _t67 = (0.40e2 / 0.9e1)*_t21;
  const double _t69 = xc_powr(n_s, -14, 3);
  const double _t70 = (0.11e2 / 0.27e2)*_t69;
  const double _t71 = _t7*_t70;
#endif
#if _KMAX >= 3
  const double _t79 = xc_powi(n_s, -5);
  const double _t81 = xc_powi(n_s, -6);
  const double _t84 = xc_powi(n_s, -7);
  const double _t87 = xc_powi(n_s, -8);
  const double _t88 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t92 = (0.10e2 / 0.3e1)*_t28;
  const double _t94 = _t41*_t84;
  const double _t97 = xc_powr(n_s, -17, 3);
  const double _t99 = (0.13e2 / 0.72e2)*_t32;
  const double _t101 = (0.5e1 / 0.72e2)*tau_s;
  const double _t105 = xc_powr(n_s, -20, 3);
  const double _t107 = (0.1e1 / (M_PI * M_PI * M_PI));
  const double _t108 = (0.1e1 / 0.576e3)*_t107;
  const double _t109 = xc_powi(n_s, -9);
  const double _t111 = (0.1e1 / 0.864e3)*sigma_ss;
  const double _t112 = (0.1e1 / 0.108e3)*_t52;
  const double _t113 = (0.5e1 / 0.1728e4)*tau_s;
  const double _t120 = (0.40e2 / 0.9e1)*tau_s;
  const double _t121 = (0.11e2 / 0.27e2)*_t7;
  const double _t122 = _t121*_t52;
  const double _t125 = _t19*tau_s;
  const double _t129 = (0.1e1 / (M_PI * M_PI));
  const double _t132 = (0.5e1 / 0.27e2)*_t52;
  const double _t133 = xc_powr(n_s, -22, 3);
  const double _t135 = (0.11e2 / 0.648e3)*sigma_ss;
  const double _t136 = _t22*_t6;
  const double _t141 = _t49*tau_s;
  const double _t151 = (0.440e3 / 0.27e2)*_t69;
  const double _t153 = (0.154e3 / 0.81e2)*_t97;
  const double _t154 = _t153*_t7;
#endif
#if _KMAX >= 4
  const double _t171 = xc_powr(n_s, -23, 3);
  const double _t173 = xc_powr(n_s, -26, 3);
  const double _t175 = xc_powr(n_s, -29, 3);
  const double _t177 = xc_powr(n_s, -32, 3);
  const double _t182 = xc_powr(n_s, -25, 3);
  const double _t186 = _t53*_t87;
  const double _t189 = _t109*_t111;
  const double _t190 = _t113*_t87;
  const double _t195 = _t133*_t135;
  const double _t197 = _t67*tau_s;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t11)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  double _hc1[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t11)) XC_CAT(pkzb_f_k, _KMAX)(p, _t7*_t9, 0, _t10*tau_s, _hc1);
  const double _t12 = my_piecewise3(_t11, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t13 = my_piecewise3(_t11, 0, _hc0[0]*_hc1[1]*_t10);
  const double _t14 = _hc1[3]*_t6;
  const double _t15 = my_piecewise3(_t11, 0, _hc0[0]*_t14*_t9);
  const double _t17 = _hc0[2]*_t3;
  const double _t18 = (0.1e1 / 0.6e1)*_t17;
  const double _t20 = _hc1[1]*_t19;
  const double _t24 = -_hc1[3]*_t23 - _t20*tau_s;
  const double _t25 = my_piecewise3(_t11, 0, _hc0[0]*_t24 - _hc1[0]*_t16*_t18);
#endif
#if _KMAX >= 2
  const double _t27 = my_piecewise3(_t11, 0, _hc0[0]*_hc1[4]*_t26);
  const double _t29 = _hc1[7]*_t6;
  const double _t30 = (0.1e1 / 0.24e2)*_hc0[0];
  const double _t31 = my_piecewise3(_t11, 0, _t28*_t29*_t30);
  const double _t36 = _hc1[9]*_t35;
  const double _t37 = (0.1e1 / 0.576e3)*_hc0[0];
  const double _t38 = my_piecewise3(_t11, 0, _t32*_t36*_t37);
  const double _t43 = -_hc1[4]*_t40 - _hc1[7]*_t42 - _t20;
  const double _t44 = my_piecewise3(_t11, 0, _hc0[0]*_t43 - _hc1[1]*_t18/(n_s * n_s * n_s));
  const double _t46 = (0.1e1 / 0.144e3)*_hc1[3];
  const double _t48 = _hc0[2]*_t47;
  const double _t50 = _hc1[7]*tau_s;
  const double _t51 = _t50*_t6;
  const double _t55 = -_t14*_t22 - _t36*_t54 - _t49*_t51;
  const double _t56 = my_piecewise3(_t11, 0, _hc0[0]*_t55 - _t45*_t46*_t48);
  const double _t57 = (0.2e1 / 0.9e1)*_hc1[0];
  const double _t59 = _t17*_t58;
  const double _t60 = (0.1e1 / 0.36e2)*_hc1[0];
  const double _t63 = _hc0[5]*_t62;
  const double _t64 = _t63*_t8;
  const double _t65 = _t17*_t24;
  const double _t68 = _hc1[1]*_t67;
  const double _t72 = _hc1[4]*_t19;
  const double _t73 = -_hc1[7]*_t23 - _t72*tau_s;
  const double _t74 = _t19*_t73;
  const double _t75 = _hc1[7]*_t19;
  const double _t76 = -_hc1[9]*_t23 - _t75*tau_s;
  const double _t77 = _hc1[3]*_t71 - _t23*_t76 + _t68*tau_s - _t74*tau_s;
  const double _t78 = my_piecewise3(_t11, 0, _hc0[0]*_t77 + _t57*_t59 + _t60*_t64 - _t65*_t66);
#endif
#if _KMAX >= 3
  const double _t80 = my_piecewise3(_t11, 0, _hc0[0]*_hc1[10]*_t79);
  const double _t82 = _hc1[14]*_t6;
  const double _t83 = my_piecewise3(_t11, 0, _t30*_t81*_t82);
  const double _t85 = _hc1[17]*_t35;
  const double _t86 = my_piecewise3(_t11, 0, _t37*_t84*_t85);
  const double _t89 = _hc1[19]*_t88;
  const double _t90 = (0.1e1 / 0.2304e4)*_hc0[0];
  const double _t91 = my_piecewise3(_t11, 0, _t87*_t89*_t90);
  const double _t93 = _hc1[10]*_t81;
  const double _t95 = -_hc1[14]*_t94 - _hc1[4]*_t92 - _t39*_t93;
  const double _t96 = my_piecewise3(_t11, 0, _hc0[0]*_t95 - _hc1[4]*_t18*_t69);
  const double _t98 = (0.1e1 / 0.144e3)*_hc1[7];
  const double _t100 = _t82*_t84;
  const double _t102 = _t85*_t87;
  const double _t103 = -_t100*_t101 - _t102*_t53 - _t29*_t99;
  const double _t104 = my_piecewise3(_t11, 0, _hc0[0]*_t103 - _t48*_t97*_t98);
  const double _t106 = _hc0[2]*_t105;
  const double _t110 = _t109*_t89;
  const double _t114 = -_t102*_t113 - _t110*_t111 - _t112*_t36;
  const double _t115 = my_piecewise3(_t11, 0, _hc0[0]*_t114 - _hc1[9]*_t106*_t108);
  const double _t116 = (0.2e1 / 0.9e1)*_t17;
  const double _t117 = (0.1e1 / 0.36e2)*_t63;
  const double _t118 = _t17*_t66;
  const double _t119 = _hc1[4]*_t32;
  const double _t123 = _hc1[14]*_t32;
  const double _t124 = -_hc1[10]*_t40 - _t123*_t41 - _t72;
  const double _t126 = -_hc1[14]*_t40 - _hc1[17]*_t42 - _t75;
  const double _t127 = _hc1[7]*_t122 + _t119*_t120 - _t124*_t125 - _t126*_t23 + _t68 - _t74;
  const double _t128 = my_piecewise3(_t11, 0, _hc0[0]*_t127 + _hc1[1]*_t116*_t45 + _hc1[1]*_t117*_t28 - _t118*_t43);
  const double _t130 = _hc0[5]*_t32;
  const double _t131 = _hc1[3]*_t48;
  const double _t134 = _t133*_t36;
  const double _t137 = _t123*_t6;
  const double _t138 = -_t101*_t137 - _t22*_t29 - _t54*_t85;
  const double _t139 = _t138*_t19;
  const double _t140 = _hc1[17]*_t6;
  const double _t142 = _hc1[19]*_t35;
  const double _t143 = -_hc1[9]*_t136 - _t140*_t141 - _t142*_t54;
  const double _t144 = _t132*_t51 + _t134*_t135 - _t136*_t76 - _t139*tau_s + _t14*_t70 - _t143*_t23;
  const double _t145 = my_piecewise3(_t11, 0, _hc0[0]*_t144 - _t118*_t55 + _t129*_t130*_t46 + (0.1e1 / 0.108e3)*_t131*_t79);
  const double _t146 = _hc0[9]/M_PI;
  const double _t147 = _t146*_t45;
  const double _t148 = (0.14e2 / 0.27e2)*_t17;
  const double _t149 = _hc1[0]*_t63;
  const double _t150 = _hc0[2]*_t16*_t4;
  const double _t152 = _hc1[1]*_t151;
  const double _t155 = _hc1[4]*_t67;
  const double _t156 = _hc1[10]*_t19;
  const double _t157 = -_hc1[14]*_t23 - _t156*tau_s;
  const double _t158 = _t157*_t19;
  const double _t159 = _hc1[14]*_t19;
  const double _t160 = -_hc1[17]*_t23 - _t159*tau_s;
  const double _t161 = _hc1[7]*_t71 + _t155*tau_s - _t158*tau_s - _t160*_t23;
  const double _t162 = _t161*_t19;
  const double _t163 = _hc1[7]*_t67;
  const double _t164 = _hc1[9]*_t70;
  const double _t165 = _t160*_t19;
  const double _t166 = _hc1[17]*_t19;
  const double _t167 = -_hc1[19]*_t23 - _t166*tau_s;
  const double _t168 = _t163*tau_s + _t164*_t7 - _t165*tau_s - _t167*_t23;
  const double _t169 = -_hc1[3]*_t154 + (0.22e2 / 0.27e2)*_t1*_t5*_t69*_t76*sigma_ss - _t152*tau_s - _t162*tau_s - _t168*_t23 + (0.80e2 / 0.9e1)*_t21*_t73*tau_s;
  const double _t170 = my_piecewise3(_t11, 0, _hc0[0]*_t169 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t24*_t58 + (0.1e1 / 0.12e2)*_hc0[5]*_t24*_t33*_t61*_t8 - _hc1[0]*_t148*_t26 - _t147*_t60 - _t149*_t22 - _t150*_t77);
#endif
#if _KMAX >= 4
  const double _t172 = _hc1[25]*_t6;
  const double _t174 = _hc1[29]*_t35;
  const double _t176 = _hc1[32]*_t88;
  const double _t178 = _hc1[34]*_t1/(M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI);
  const double _t179 = _hc1[20]*_t39;
  const double _t180 = _t101*_t172;
  const double _t181 = _t174*_t175;
  const double _t183 = _t176*_t177;
  const double _t184 = _hc1[10]*_t120;
  const double _t185 = _hc0[5]*_t129;
  const double _t187 = _hc1[29]*_t6;
  const double _t188 = _hc1[32]*_t35;
  const double _t191 = _hc1[1]*_t97;
  const double _t192 = _hc1[4]*tau_s;
  const double _t193 = -_hc1[25]*_t40 - _hc1[29]*_t42 - _t159;
  const double _t194 = _hc1[3]*_t105;
  const double _t196 = -_hc1[17]*_t136 - _t141*_t187 - _t188*_t54;
  const double _t198 = -_hc1[25]*_t125 - _hc1[29]*_t23;
  const double _t199 = -_hc1[29]*_t125 - _hc1[32]*_t23;
  const double _t200 = _hc1[14]*_t197 + _hc1[17]*_t71 - _t125*_t198 - _t199*_t23;
#endif

  const double f = my_piecewise3(_t11, 0, _t12*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t11, 0, _t13*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t11, 0, _t15*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t11, 0, _t12 + _t25*n_s);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t11, 0, _t27*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t11, 0, _t31*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t11, 0, _t38*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t11, 0, _t13 + _t44*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t11, 0, _t15 + _t56*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t11, 0, 0.2e1*_t25 + _t78*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t11, 0, _t80*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t11, 0, _t83*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t11, 0, _t86*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t11, 0, _t91*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t11, 0, _t27 + _t96*n_s);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t11, 0, _t104*n_s + _t31);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t11, 0, _t115*n_s + _t38);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t11, 0, _t128*n_s + 0.2e1*_t44);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t11, 0, _t145*n_s + 0.2e1*_t56);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t11, 0, _t170*n_s + 0.3e1*_t78);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _hc0[0]*_hc1[20]*_t105));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _t171*_t172*_t30));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _t173*_t174*_t37));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, _t175*_t176*_t90));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t11, 0, n_s*my_piecewise3(_t11, 0, (0.1e1 / 0.55296e5)*_hc0[0]*_t177*_t178));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t11, 0, _t80 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_hc1[25]*_t173*_t41 - _t171*_t179 - 0.5e1*_t93) - _hc1[10]*_t18*_t52));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t11, 0, _t83 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-0.1e1 / 0.4e1*_t100 - _t173*_t180 - _t181*_t53) - 0.1e1 / 0.144e3*_hc1[14]*_t133*_t48));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t11, 0, _t86 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-0.7e1 / 0.576e3*_t102 - _t111*_t183 - _t113*_t181) - _hc0[2]*_hc1[17]*_t108*_t182));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t11, 0, _t91 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-0.1e1 / 0.288e3*_t110 - 0.1e1 / 0.20736e5*_t178*sigma_ss/xc_powr(n_s, 35, 3) - 0.5e1 / 0.6912e4*_t183*tau_s) - 0.1e1 / 0.13824e5*_hc0[2]*_hc1[19]*_t1/((M_PI * M_PI * M_PI * M_PI * M_CBRTPI)*xc_powr(n_s, 28, 3))));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t11, 0, 0.2e1*_t96 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(_hc1[14]*_t121*_t87 + (0.80e2 / 0.9e1)*_t119 - 0.10e2 / 0.3e1*_t124*_t8 - _t125*(-_hc1[10]*_t92 - _hc1[25]*_t94 - _t179*_t81) + _t184*_t84 - _t23*(-_hc1[14]*_t92 - _hc1[25]*_t39*_t81 - _hc1[29]*_t94)) + _hc1[4]*_t116*_t97 + _hc1[4]*_t117*_t81 - _t118*_t95));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t11, 0, 0.2e1*_t104 + n_s*my_piecewise3(_t11, 0, _hc0[0]*((0.5e1 / 0.27e2)*_hc1[14]*_t1*_t5*_t87*tau_s + (0.11e2 / 0.648e3)*_hc1[17]*_t109*_t33*_t34*sigma_ss + (0.16e2 / 0.27e2)*_hc1[7]*_t1*_t5*_t52 - _t125*(-0.13e2 / 0.72e2*_t137 - _t174*_t186 - _t180*_t84) - _t126*_t136 - _t139 - _t23*(-_t101*_t187*_t84 - _t140*_t99 - _t186*_t188)) + (0.1e1 / 0.108e3)*_hc1[7]*_t106*_t47 - _t103*_t118 + _t185*_t84*_t98));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t11, 0, 0.2e1*_t115 + n_s*my_piecewise3(_t11, 0, _hc0[0]*((0.5e1 / 0.648e3)*_t109*_t85*tau_s - _t125*(-_t112*_t85 - _t174*_t190 - _t176*_t189) + (0.11e2 / 0.324e3)*_t134 - 0.2e1 / 0.9e1*_t143*_t21*_t6 - _t23*(-_hc1[34]*_t189*_t88 - _t112*_t142 - _t188*_t190) + (0.11e2 / 0.2592e4)*_t89*sigma_ss/xc_powi(n_s, 10)) + (0.1e1 / 0.432e3)*_hc0[2]*_hc1[9]*_t107*_t171 + (0.1e1 / 0.3456e4)*_hc0[5]*_hc1[9]*_t1*_t87/(M_PI * M_PI * M_PI * M_CBRTPI) - _t114*_t118));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t11, 0, 0.3e1*_t128 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-0.154e3 / 0.81e2*_hc1[7]*_t133*_t7 + (0.22e2 / 0.27e2)*_t1*_t126*_t5*_t69*sigma_ss + (0.80e2 / 0.9e1)*_t124*_t21*tau_s - _t125*(_hc1[14]*_t122 - _t125*(-_hc1[20]*_t40 - _hc1[25]*_t42 - _t156) + _t155 - _t158 + _t184*_t32 - _t193*_t23) - _t152 - _t162 - 0.440e3 / 0.27e2*_t192*_t52 + (0.80e2 / 0.9e1)*_t21*_t73 - _t23*(_hc1[17]*_t122 + _t120*_t123 - _t125*_t193 + _t163 - _t165 - _t23*(-_hc1[29]*_t40 - _hc1[32]*_t42 - _t166))) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t43*_t58 + (0.1e1 / 0.12e2)*_hc0[5]*_t33*_t43*_t61*_t8 - 0.1e1 / 0.9e1*_hc1[1]*_t130*_t62 - _hc1[1]*_t148*_t79 - _t127*_t150 - 0.1e1 / 0.36e2*_t146*_t191));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t11, 0, 0.3e1*_t145 + n_s*my_piecewise3(_t11, 0, _hc0[0]*((0.22e2 / 0.27e2)*_t1*_t143*_t5*_t69*sigma_ss + (0.22e2 / 0.27e2)*_t1*_t5*_t69*_t76 - _t125*(-_t125*(-_hc1[14]*_t136 - _t141*_t172 - _t174*_t54) + _t132*_t82*tau_s - _t136*_t160 + _t195*_t85 - _t196*_t23 + _t29*_t70) - 0.55e2 / 0.81e2*_t133*_t51 - _t136*_t168 + (0.80e2 / 0.9e1)*_t138*_t21*tau_s - _t14*_t153 - 0.77e2 / 0.972e3*_t182*_t36*sigma_ss - _t23*(-_t125*_t196 + _t132*_t140*tau_s - _t136*_t167 + _t142*_t195 + _t164*_t6 - _t23*(-_hc1[19]*_t136 - _hc1[32]*_t141*_t6 - _hc1[34]*_t35*_t54))) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t55*_t58 + (0.1e1 / 0.12e2)*_hc0[5]*_t33*_t55*_t61*_t8 - 0.1e1 / 0.864e3*_hc0[9]*_t1*_t194/(M_PI * M_PI * M_CBRTPI) - 0.1e1 / 0.36e2*_hc1[3]*_t185*_t52 - 0.7e1 / 0.324e3*_t131*_t81 - _t144*_t150));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t11, 0, 0.4e1*_t170 + n_s*my_piecewise3(_t11, 0, _hc0[0]*(-_t125*(-_hc1[7]*_t154 + (0.22e2 / 0.27e2)*_t1*_t160*_t5*_t69*sigma_ss - _t125*(_hc1[10]*_t197 + _hc1[14]*_t71 - _t125*(-_hc1[20]*_t125 - _hc1[25]*_t23) - _t198*_t23) - _t151*_t192 + (0.80e2 / 0.9e1)*_t157*_t21*tau_s - _t200*_t23) + (0.40e2 / 0.3e1)*_t161*_t21*tau_s + (0.11e2 / 0.9e1)*_t168*_t69*_t7 + (0.6160e4 / 0.81e2)*_t191*tau_s + (0.2618e4 / 0.243e3)*_t194*_t7 - _t23*(-_hc1[9]*_t154 + (0.22e2 / 0.27e2)*_t1*_t167*_t5*_t69*sigma_ss - _t125*_t200 - _t151*_t50 + (0.80e2 / 0.9e1)*_t160*_t21*tau_s - _t23*(_hc1[17]*_t197 + _hc1[19]*_t71 - _t125*_t199 - _t23*(-_hc1[32]*_t125 - _hc1[34]*_t23))) - 0.440e3 / 0.9e1*_t69*_t73*tau_s - 0.154e3 / 0.27e2*_t7*_t76*_t97) + (0.1e1 / 0.216e3)*_hc0[14]*_hc1[0]*_t32*_t6 + (0.140e3 / 0.81e2)*_hc1[0]*_t17*_t28 + _t146*_t57*_t79 - 0.1e1 / 0.9e1*_t147*_t24 + (0.40e2 / 0.81e2)*_t149*_t69 - 0.2e1 / 0.3e1*_t16*_t169*_t17 - 0.4e1 / 0.9e1*_t21*_t24*_t63 - 0.56e2 / 0.27e2*_t26*_t65 + (0.4e1 / 0.3e1)*_t59*_t77 + (0.1e1 / 0.6e1)*_t64*_t77));
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