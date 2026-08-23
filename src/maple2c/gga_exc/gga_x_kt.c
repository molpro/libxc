/*
  Generated from python/gga_exc/gga_x_kt.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_kt
*/

#ifndef _GGA_X_KT_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_KT_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_KT_HELPER_BODIES
#include "gga_x_kt.c"
#undef _GGA_X_KT_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_KT_HELPER_BODIES
#include "gga_x_kt.c"
#undef _GGA_X_KT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_KT_HELPER_BODIES
#include "gga_x_kt.c"
#undef _GGA_X_KT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_KT_HELPER_BODIES
#include "gga_x_kt.c"
#undef _GGA_X_KT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_KT_HELPER_BODIES
#include "gga_x_kt.c"
#undef _GGA_X_KT_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_kt.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_KT_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(kt_fx_k, _KMAX)(const xc_func_type *p, double rs, double z, double p_, double *out) {
  const gga_x_kt_params *params = (const gga_x_kt_params *)(p->params);

  const double _t1 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t2 = M_CBRT3;
  const double _t3 = (0.1e1 / (rs * rs * rs));
  const double _t4 = z + 0.1e1;
  const double _t5 = _t3*_t4;
  const double _t6 = xc_powr(_t5, 4, 3);
  const double _t7 = _t2*_t6;
  const double _t8 = _t1*_t7;
  const double _t9 = (0.3e1 / 0.16e2)*_t8 + params->delta;
  const double _t10 = (0.1e1 / _t9);
  const double _t11 = xc_powr(0.2e1, 2, 3);
  const double _t12 = (0.1e1 / M_CBRT3);
  const double _t13 = M_CBRTPI*_t12*params->gamma;
  const double _t14 = _t11*_t13;
  const double _t15 = _t10*_t14*_t8;
  const double _t16 = (0.1e1 / 0.8e1)*_t15;
#if _KMAX >= 1
  const double _t17 = (0.1e1 / _t4);
  const double _t18 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t19 = (0.1e1 / (_t9 * _t9));
  const double _t20 = xc_powr(0.6e1, 2, 3);
  const double _t21 = xc_powr(_t5, 8, 3);
  const double _t22 = _t13*_t20*_t21;
  const double _t23 = _t18*_t19*_t22;
  const double _t24 = _t17*_t23;
  const double _t25 = (0.1e1 / 0.32e2)*_t24;
  const double _t26 = _t15*_t17;
  const double _t27 = (0.1e1 / 0.6e1)*_t26;
  const double _t28 = (0.1e1 / rs);
  const double _t29 = (0.3e1 / 0.32e2)*_t23*_t28;
#endif
#if _KMAX >= 2
  const double _t30 = (_t4 * _t4);
  const double _t31 = xc_powi(rs, -12);
  const double _t32 = _t14*_t31;
  const double _t33 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t34 = (0.1e1 / (_t9 * _t9 * _t9));
  const double _t35 = _t33*_t34;
  const double _t36 = _t32*_t35;
  const double _t37 = (0.3e1 / 0.64e2)*_t30*_t36;
  const double _t38 = (0.1e1 / _t30);
  const double _t39 = _t15*_t38;
  const double _t40 = (0.1e1 / 0.18e2)*_t39;
  const double _t41 = (_t4 * _t4 * _t4);
  const double _t42 = xc_powi(rs, -13);
  const double _t43 = _t14*_t35;
  const double _t44 = (0.9e1 / 0.64e2)*_t41*_t42*_t43;
  const double _t45 = (0.3e1 / 0.8e1)*_t24*_t28;
  const double _t46 = (0.2e1 / 0.3e1)*_t26*_t28;
  const double _t47 = (_t4 * _t4 * _t4 * _t4);
  const double _t48 = xc_powi(rs, -14);
  const double _t49 = _t43*_t48;
  const double _t50 = (0.27e2 / 0.64e2)*_t47*_t49;
  const double _t51 = (0.1e1 / (rs * rs));
  const double _t52 = (0.5e1 / 0.2e1)*_t15*_t51;
#endif
#if _KMAX >= 3
  const double _t53 = (0.15e2 / 0.64e2)*_t36*_t4;
  const double _t54 = (0.1e1 / _t41);
  const double _t55 = _t23*_t54;
  const double _t56 = (0.11e2 / 0.144e3)*_t55;
  const double _t57 = (0.1e1 / 0.27e2)*_t15*_t54;
  const double _t58 = (0.9e1 / 0.256e3)*p_;
  const double _t59 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t60 = (0.1e1 / (_t9 * _t9 * _t9 * _t9));
  const double _t61 = _t59*_t60*_t7;
  const double _t62 = _t32*_t4*_t61;
  const double _t63 = _t23*p_;
  const double _t64 = (0.19e2 / 0.24e2)*_t28*_t38;
  const double _t65 = _t30*p_;
  const double _t66 = _t14*_t61;
  const double _t67 = (0.27e2 / 0.256e3)*_t42*_t66;
  const double _t68 = (0.225e3 / 0.64e2)*_t41*_t49;
  const double _t69 = (0.31e2 / 0.8e1)*_t24*_t51;
  const double _t70 = _t41*p_;
  const double _t71 = (0.81e2 / 0.256e3)*_t48;
  const double _t72 = _t66*_t71;
  const double _t73 = (0.10e2 / 0.3e1)*_t26*_t51;
  const double _t74 = xc_powi(rs, -15);
  const double _t75 = (0.225e3 / 0.16e2)*_t23*_t3;
  const double _t76 = _t47*p_;
  const double _t77 = (0.243e3 / 0.256e3)*_t74;
  const double _t78 = _t66*_t77;
#endif
#if _KMAX >= 4
  const double _t79 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t80 = xc_powi(_t9, -5);
  const double _t81 = _t22*_t79*_t80;
  const double _t82 = (0.1e1 / _t47);
  const double _t83 = _t15*p_;
  const double _t84 = 0.2e1*z + 0.2e1;
  const double _t85 = _t3*p_;
  const double _t86 = xc_powi(rs, -16);
  const double _t87 = _t76*_t86;
  const double _t88 = (0.1e1 / (rs * rs * rs * rs));
#endif

  const double f = -_t16*p_ + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_dp_ = -_t16;
  out[1] = df_dp_;
  const double df_dz = _t25*p_ - _t27*p_;
  out[2] = df_dz;
  const double df_drs = (0.1e1 / 0.2e1)*M_CBRTPI*_t1*_t10*_t11*_t12*_t2*_t28*_t6*p_*params->gamma - _t29*p_;
  out[3] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dp_2 = 0;
  out[4] = d2f_dp_2;
  const double d2f_dz_dp_ = _t25 - _t27;
  out[5] = d2f_dz_dp_;
  const double d2f_dz2 = (0.3e1 / 0.32e2)*M_CBRTPI*_t12*_t18*_t19*_t20*_t21*_t38*p_*params->gamma - _t37*p_ - _t40*p_;
  out[6] = d2f_dz2;
  const double d2f_drs_dp_ = (0.1e1 / 0.2e1)*M_CBRTPI*_t1*_t10*_t11*_t12*_t2*_t28*_t6*params->gamma - _t29;
  out[7] = d2f_drs_dp_;
  const double d2f_drs_dz = _t44*p_ - _t45*p_ + _t46*p_;
  out[8] = d2f_drs_dz;
  const double d2f_drs2 = (0.39e2 / 0.32e2)*M_CBRTPI*_t12*_t18*_t19*_t20*_t21*_t51*p_*params->gamma - _t50*p_ - _t52*p_;
  out[9] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dp_3 = 0;
  out[10] = d3f_dp_3;
  const double d3f_dz_dp_2 = 0;
  out[11] = d3f_dz_dp_2;
  const double d3f_dz2_dp_ = (0.3e1 / 0.32e2)*M_CBRTPI*_t12*_t18*_t19*_t20*_t21*_t38*params->gamma - _t37 - _t40;
  out[12] = d3f_dz2_dp_;
  const double d3f_dz3 = -_t53*p_ + _t56*p_ + _t57*p_ + _t58*_t62;
  out[13] = d3f_dz3;
  const double d3f_drs_dp_2 = 0;
  out[14] = d3f_drs_dp_2;
  const double d3f_drs_dz_dp_ = _t44 - _t45 + _t46;
  out[15] = d3f_drs_dz_dp_;
  const double d3f_drs_dz2 = (0.2e1 / 0.9e1)*M_CBRTPI*_t1*_t10*_t11*_t12*_t2*_t28*_t38*_t6*p_*params->gamma + (0.63e2 / 0.64e2)*M_CBRTPI*_t11*_t12*_t30*_t33*_t34*_t42*p_*params->gamma - _t63*_t64 - _t65*_t67;
  out[16] = d3f_drs_dz2;
  const double d3f_drs2_dp_ = (0.39e2 / 0.32e2)*M_CBRTPI*_t12*_t18*_t19*_t20*_t21*_t51*params->gamma - _t50 - _t52;
  out[17] = d3f_drs2_dp_;
  const double d3f_drs2_dz = -_t68*p_ + _t69*p_ + _t70*_t72 - _t73*p_;
  out[18] = d3f_drs2_dz;
  const double d3f_drs3 = 0.15e2*M_CBRTPI*_t1*_t10*_t11*_t12*_t2*_t3*_t6*p_*params->gamma + (0.729e3 / 0.64e2)*M_CBRTPI*_t11*_t12*_t33*_t34*_t47*_t74*p_*params->gamma - _t75*p_ - _t76*_t78;
  out[19] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dp_4 = 0;
  out[20] = d4f_dp_4;
  const double d4f_dz_dp_3 = 0;
  out[21] = d4f_dz_dp_3;
  const double d4f_dz2_dp_2 = 0;
  out[22] = d4f_dz2_dp_2;
  const double d4f_dz3_dp_ = -_t53 + _t56 + _t57 + (0.9e1 / 0.256e3)*_t62;
  out[23] = d4f_dz3_dp_;
  const double d4f_dz4 = (0.33e2 / 0.128e3)*M_CBRTPI*_t11*_t12*_t2*_t31*_t59*_t6*_t60*p_*params->gamma - _t31*_t58*_t81 - 0.67e2 / 0.192e3*_t36*p_ - 0.5e1 / 0.144e3*_t63*_t82 - 0.5e1 / 0.81e2*_t82*_t83;
  out[24] = d4f_dz4;
  const double d4f_drs_dp_3 = 0;
  out[25] = d4f_drs_dp_3;
  const double d4f_drs_dz_dp_2 = 0;
  out[26] = d4f_drs_dz_dp_2;
  const double d4f_drs_dz2_dp_ = (0.2e1 / 0.9e1)*M_CBRTPI*_t1*_t10*_t11*_t12*_t2*_t28*_t38*_t6*params->gamma + (0.63e2 / 0.64e2)*M_CBRTPI*_t11*_t12*_t30*_t33*_t34*_t42*params->gamma - _t23*_t64 - _t30*_t67;
  out[27] = d4f_drs_dz2_dp_;
  const double d4f_drs_dz3 = (0.37e2 / 0.16e2)*M_CBRTPI*_t11*_t12*_t33*_t34*_t4*_t42*p_*params->gamma + (0.27e2 / 0.64e2)*M_CBRTPI*_t11*_t12*_t33*_t34*_t42*_t84*p_*params->gamma + (0.27e2 / 0.256e3)*M_CBRTPI*_t12*_t20*_t21*_t4*_t42*_t79*_t80*p_*params->gamma - 0.4e1 / 0.27e2*_t15*_t28*_t54*p_ - 0.7e1 / 0.12e2*_t28*_t55*p_ - 0.225e3 / 0.256e3*_t4*_t42*_t66*p_ - _t67*_t84*p_;
  out[28] = d4f_drs_dz3;
  const double d4f_drs2_dp_2 = 0;
  out[29] = d4f_drs2_dp_2;
  const double d4f_drs2_dz_dp_ = _t41*_t72 - _t68 + _t69 - _t73;
  out[30] = d4f_drs2_dz_dp_;
  const double d4f_drs2_dz2 = (0.513e3 / 0.128e3)*M_CBRTPI*_t11*_t12*_t2*_t30*_t48*_t59*_t6*_t60*p_*params->gamma + (0.175e3 / 0.24e2)*M_CBRTPI*_t12*_t18*_t19*_t20*_t21*_t38*_t51*p_*params->gamma - 0.10e2 / 0.9e1*_t39*_t51*p_ - 0.1047e4 / 0.64e2*_t49*_t65 - _t65*_t71*_t81;
  out[31] = d4f_drs2_dz2;
  const double d4f_drs3_dp_ = 0.15e2*M_CBRTPI*_t1*_t10*_t11*_t12*_t2*_t3*_t6*params->gamma + (0.729e3 / 0.64e2)*M_CBRTPI*_t11*_t12*_t33*_t34*_t47*_t74*params->gamma - _t47*_t78 - _t75;
  out[32] = d4f_drs3_dp_;
  const double d4f_drs3_dz = -0.165e3 / 0.4e1*_t24*_t85 + 0.20e2*_t26*_t85 + (0.2133e4 / 0.32e2)*_t43*_t70*_t74 - 0.3483e4 / 0.256e3*_t66*_t70*_t74 + _t70*_t77*_t81;
  out[33] = d4f_drs3_dz;
  const double d4f_drs4 = (0.5589e4 / 0.128e3)*M_CBRTPI*_t11*_t12*_t2*_t47*_t59*_t6*_t60*_t86*p_*params->gamma + (0.2655e4 / 0.16e2)*M_CBRTPI*_t12*_t18*_t19*_t20*_t21*_t88*p_*params->gamma - 0.14985e5 / 0.64e2*_t43*_t87 - 0.729e3 / 0.256e3*_t81*_t87 - 0.105e3*_t83*_t88;
  out[34] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {
  const gga_x_kt_params *params = (const gga_x_kt_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = _t4/xc_powr(n_s, 1, 3);
  const double _t6 = 0.1e1 - p->zeta_threshold;
  const double _t7 = xc_powr(n_s, -8, 3);
  const double _t8 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t11 = xc_powr(n_s, -4, 3);
  const double _t12 = (0.1e1 / 0.6e1)*_t3;
  const double _t13 = _t11*_t12;
  const double _t15 = xc_powr(n_s, -11, 3);
  const double _t16 = (0.8e1 / 0.3e1)*_t15;
#endif
#if _KMAX >= 2
  const double _t20 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t21 = _t12*_t20;
  const double _t25 = xc_powr(n_s, -7, 3);
  const double _t26 = (0.2e1 / 0.9e1)*_t25;
  const double _t27 = _t26*_t3;
  const double _t28 = xc_powr(0.6e1, 2, 3);
  const double _t29 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t30 = _t28*_t29;
  const double _t31 = (0.1e1 / 0.36e2)*_t7;
  const double _t32 = _t30*_t31;
  const double _t37 = xc_powr(n_s, -14, 3);
  const double _t38 = (0.88e2 / 0.9e1)*_t37;
  const double _t43 = xc_powi(n_s, -5);
  const double _t44 = (0.4e1 / 0.9e1)*_t43;
#endif
#if _KMAX >= 3
  const double _t49 = (0.2e1 / 0.9e1)*_t43;
  const double _t51 = xc_powr(n_s, -16, 3);
  const double _t55 = (0.2e1 / 0.3e1)*_t43;
  const double _t59 = (0.1e1 / M_PI);
  const double _t61 = xc_powr(n_s, -10, 3);
  const double _t62 = (0.14e2 / 0.27e2)*_t61;
  const double _t63 = _t3*_t62;
  const double _t66 = (0.1232e4 / 0.27e2)/xc_powr(n_s, 17, 3);
  const double _t68 = xc_powi(n_s, -6);
  const double _t69 = (0.88e2 / 0.27e2)*_t68;
  const double _t75 = _t3*_t44;
#endif
#if _KMAX >= 4
  const double _t83 = (0.140e3 / 0.81e2)/xc_powr(n_s, 13, 3);
  const double _t84 = (0.2e1 / 0.3e1)*_t3;
  const double _t86 = _t16*sigma_ss;
#endif
  double _hc0[(_KMAX) >= 4 ? 35 : (_KMAX) >= 3 ? 20 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 4 : 1] = {0.};
  if(!(_t8)) XC_CAT(kt_fx_k, _KMAX)(p, _t5, _t6, _t7*sigma_ss, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t8)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t5, _t6, _hc1);
  const double _t9 = my_piecewise3(_t8, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t10 = my_piecewise3(_t8, 0, _hc0[1]*_hc1[0]*_t7);
  const double _t14 = _hc0[0]*_hc1[2];
  const double _t17 = _hc0[1]*_t16;
  const double _t18 = -_hc0[3]*_t13 - _t17*sigma_ss;
  const double _t19 = my_piecewise3(_t8, 0, _hc1[0]*_t18 - _t13*_t14);
#endif
#if _KMAX >= 2
  const double _t22 = _hc0[1]*_hc1[2];
  const double _t23 = -_hc0[7]*_t21 - _t17;
  const double _t24 = my_piecewise3(_t8, 0, _hc1[0]*_t23 - _t21*_t22);
  const double _t33 = _hc0[0]*_hc1[5];
  const double _t34 = _t18*_t3;
  const double _t35 = _hc1[2]*_t11;
  const double _t36 = (0.1e1 / 0.3e1)*_t35;
  const double _t39 = _hc0[1]*_t38;
  const double _t40 = _hc0[3]*_t3;
  const double _t41 = _hc0[7]*sigma_ss;
  const double _t42 = _t3*_t41;
  const double _t45 = _hc0[7]*_t16;
  const double _t46 = -_hc0[9]*_t13 - _t45*sigma_ss;
  const double _t47 = -_t13*_t46 + _t26*_t40 + _t39*sigma_ss + _t42*_t44;
  const double _t48 = my_piecewise3(_t8, 0, _hc1[0]*_t47 + _t14*_t27 + _t32*_t33 - _t34*_t36);
#endif
#if _KMAX >= 3
  const double _t50 = _t22*_t3;
  const double _t52 = _hc1[5]*_t30;
  const double _t53 = _hc0[1]*_t52;
  const double _t54 = _hc0[7]*_t3;
  const double _t56 = -_hc0[17]*_t21 - _t45;
  const double _t57 = -_t13*_t56 + _t39 + _t54*_t55;
  const double _t58 = my_piecewise3(_t8, 0, _hc1[0]*_t57 - _t23*_t3*_t36 + _t49*_t50 + (0.1e1 / 0.36e2)*_t51*_t53);
  const double _t60 = (0.1e1 / 0.36e2)*_hc1[9]*_t59;
  const double _t64 = _t30*_t33;
  const double _t65 = _t35*_t4;
  const double _t67 = _hc0[1]*_t66;
  const double _t70 = _hc0[17]*_t30;
  const double _t71 = _t26*_t54 + _t31*_t70;
  const double _t72 = _t16*_t71;
  const double _t73 = _hc0[7]*_t38;
  const double _t74 = _hc0[17]*sigma_ss;
  const double _t76 = _hc0[17]*_t16;
  const double _t77 = -_hc0[19]*_t13 - _t76*sigma_ss;
  const double _t78 = _hc0[9]*_t27 - _t13*_t77 + _t73*sigma_ss + _t74*_t75;
  const double _t79 = (0.4e1 / 0.9e1)*_t1*_t2*_t25*_t46 - _t13*_t78 - _t40*_t62 - _t42*_t69 - _t67*sigma_ss - _t72*sigma_ss;
  const double _t80 = my_piecewise3(_t8, 0, -_hc0[0]*_t20*_t60 + _hc1[0]*_t79 + (0.2e1 / 0.3e1)*_hc1[2]*_t1*_t18*_t2*_t25 + (0.1e1 / 0.12e2)*_hc1[5]*_t18*_t28*_t29*_t7 - _t14*_t63 - 0.1e1 / 0.9e1*_t15*_t64 - _t47*_t65);
#endif
#if _KMAX >= 4
  const double _t81 = _hc0[1]/xc_powr(n_s, 20, 3);
  const double _t82 = _hc1[9]*_t59;
  const double _t85 = _hc0[17]*_t27 + _hc0[32]*_t32;
#endif

  const double f = my_piecewise3(_t8, 0, _t9*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t8, 0, _t10*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t8, 0, _t19*n_s + _t9);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = 0;
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t8, 0, _t10 + _t24*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t8, 0, 0.2e1*_t19 + _t48*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = 0;
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = 0;
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t8, 0, 0.2e1*_t24 + _t58*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t8, 0, 0.3e1*_t48 + _t80*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = 0;
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = 0;
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = 0;
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t8, 0, 0.3e1*_t58 + n_s*my_piecewise3(_t8, 0, _hc1[0]*((0.4e1 / 0.9e1)*_t1*_t2*_t25*_t56 - _t13*(_hc0[17]*_t3*_t55 - _t13*(-_hc0[32]*_t21 - _t76) + _t73) - 0.34e2 / 0.9e1*_t54*_t68 - _t67 - _t72) + (0.2e1 / 0.3e1)*_hc1[2]*_t1*_t2*_t23*_t25 + (0.1e1 / 0.12e2)*_hc1[5]*_t23*_t28*_t29*_t7 - 0.14e2 / 0.27e2*_t50*_t68 - 0.1e1 / 0.9e1*_t53/xc_powr(n_s, 19, 3) - _t57*_t65 - _t60*_t81));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t8, 0, 0.4e1*_t80 + n_s*my_piecewise3(_t8, 0, (0.1e1 / 0.216e3)*_hc0[0]*_hc1[14]*_t1*_t51/(M_PI * M_CBRTPI) + _hc0[0]*_t49*_t82 + _hc1[0]*(-_t13*(-_hc0[9]*_t63 + (0.4e1 / 0.9e1)*_t1*_t2*_t25*_t77 - _t13*(_hc0[19]*_t27 + _hc0[32]*_t75*sigma_ss - _t13*(-_hc0[32]*_t86 - _hc0[34]*_t13) + _t38*_t74) - _t3*_t69*_t74 - _t41*_t66 - _t85*_t86) + _t25*_t78*_t84 - 0.14e2 / 0.9e1*_t3*_t46*_t61 + (0.88e2 / 0.3e1)*_t37*_t71*sigma_ss + _t40*_t83 + (0.616e3 / 0.27e2)*_t42/xc_powi(n_s, 7) + (0.20944e5 / 0.81e2)*_t81*sigma_ss - _t86*(-_t13*_t85 - 0.2e1 / 0.27e2*_t15*_t70 - _t54*_t62)) + (0.4e1 / 0.3e1)*_hc1[2]*_t25*_t3*_t47 - 0.56e2 / 0.27e2*_hc1[2]*_t34*_t61 + _t14*_t3*_t83 - 0.4e1 / 0.9e1*_t15*_t18*_t52 - 0.1e1 / 0.9e1*_t18*_t20*_t82 - _t35*_t79*_t84 + (0.40e2 / 0.81e2)*_t37*_t64 + (0.1e1 / 0.6e1)*_t47*_t52*_t7));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_kt_params *params = (const gga_x_kt_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, (0.1e1 / 0.4e1)*gaa, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, _t1, 0, _hc1);
  const double dF_dna = _hc0[2];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[5];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[4];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc1[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[9];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[8];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[7];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc1[6];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[14];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[13];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[12];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[11];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc1[10];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, 0, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, 0, _hc3);
  const double dF_dna = _hc0[2];
  const double dF_dnb = _hc1[2];
  const double dF_dgaa = _hc2[1];
  const double dF_dgbb = _hc3[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = _hc0[5];
  const double d2F_dnb2 = _hc1[5];
  const double d2F_dna_dgaa = _hc0[4];
  const double d2F_dnb_dgbb = _hc1[4];
  const double d2F_dgaa2 = _hc2[3];
  const double d2F_dgbb2 = _hc3[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc0[9];
  const double d3F_dnb3 = _hc1[9];
  const double d3F_dna2_dgaa = _hc0[8];
  const double d3F_dnb2_dgbb = _hc1[8];
  const double d3F_dna_dgaa2 = _hc0[7];
  const double d3F_dnb_dgbb2 = _hc1[7];
  const double d3F_dgaa3 = _hc2[6];
  const double d3F_dgbb3 = _hc3[6];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc0[14];
  const double d4F_dnb4 = _hc1[14];
  const double d4F_dna3_dgaa = _hc0[13];
  const double d4F_dnb3_dgbb = _hc1[13];
  const double d4F_dna2_dgaa2 = _hc0[12];
  const double d4F_dnb2_dgbb2 = _hc1[12];
  const double d4F_dna_dgaa3 = _hc0[11];
  const double d4F_dnb_dgbb3 = _hc1[11];
  const double d4F_dgaa4 = _hc2[10];
  const double d4F_dgbb4 = _hc3[10];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
#endif
#endif
}
#endif