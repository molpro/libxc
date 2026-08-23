/*
  Generated from python/gga_exc/gga_x_gg99.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_gg99
*/

#ifndef _GGA_X_GG99_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_GG99_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_GG99_HELPER_BODIES
#include "gga_x_gg99.c"
#undef _GGA_X_GG99_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_GG99_HELPER_BODIES
#include "gga_x_gg99.c"
#undef _GGA_X_GG99_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_GG99_HELPER_BODIES
#include "gga_x_gg99.c"
#undef _GGA_X_GG99_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_GG99_HELPER_BODIES
#include "gga_x_gg99.c"
#undef _GGA_X_GG99_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_GG99_HELPER_BODIES
#include "gga_x_gg99.c"
#undef _GGA_X_GG99_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_gg99.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_GG99_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(gg99_r_branch1_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (0.1e1 / 0.4e1)*x;
  const double _t2 = (x * x);
  const double _t3 = xc_powr(0.3e1, 1, 2);
  const double _t4 = (M_PI * M_PI * M_PI);
  const double _t5 = xc_powi(x, 6);
  const double _t6 = -_t5 + 0.48e2*xc_powi(M_PI, 6);
  const double _t7 = xc_powr(_t6, 1, 2);
  const double _t8 = 0.4e1*_t3*_t4 + _t7;
  const double _t9 = xc_powr(_t8, 2, 3);
  const double _t10 = _t2 + _t9;
  const double _t11 = xc_powr(_t10, 1, 2);
  const double _t12 = xc_powr(0.3e1, 1, 4)/xc_powr(M_PI, 3, 2);
  const double _t13 = xc_powr(0.2e1, 1, 2)*_t12;
  const double _t14 = _t13/xc_powr(_t8, 1, 6);
  const double _t15 = _t11*_t14;
#if _KMAX >= 1
  const double _t16 = xc_powr(_t8, -1, 3);
  const double _t17 = (0.1e1 / _t4);
  const double _t18 = _t17*_t3;
  const double _t19 = _t16*_t18;
  const double _t20 = _t10*_t19;
  const double _t21 = (0.1e1 / 0.8e1)*_t20;
  const double _t22 = _t2*_t21 + 0.1e1;
  const double _t23 = xc_powr(_t22, -1, 2);
  const double _t24 = _t12*xc_powr(0.2e1*_t2 + 0.2e1*_t9, 1, 2);
  const double _t25 = (0.1e1 / _t7);
  const double _t26 = xc_powr(_t8, -7, 6);
  const double _t27 = _t25*_t26;
  const double _t28 = _t27*_t5;
  const double _t29 = xc_powi(x, 5);
  const double _t30 = _t16*_t25;
  const double _t31 = _t29*_t30;
  const double _t32 = _t31 - x;
  const double _t33 = -_t32;
  const double _t34 = (0.1e1 / _t11);
  const double _t35 = _t14*_t34;
  const double _t36 = _t33*_t35;
  const double _t37 = _t1*_t36 + (0.1e1 / 0.4e1)*_t15 + (0.1e1 / 0.8e1)*_t24*_t28;
#endif
#if _KMAX >= 2
  const double _t38 = xc_powi(x, 7);
  const double _t39 = xc_powr(_t8, -4, 3);
  const double _t40 = (0.1e1 / 0.16e2)*_t2;
  const double _t41 = _t19*(-0.2e1*_t31 + 0.2e1*x);
  const double _t42 = _t17*_t25*_t3*_t38*_t39*(-_t40 - 0.1e1 / 0.16e2*_t9) - _t21*x - _t40*_t41;
  const double _t43 = xc_powr(_t22, -3, 2);
  const double _t44 = _t37*_t43;
  const double _t45 = _t24*_t27;
  const double _t46 = xc_powi(x, 11);
  const double _t47 = _t24*_t46;
  const double _t48 = xc_powr(_t6, -3, 2);
  const double _t49 = _t26*_t48;
  const double _t50 = (0.1e1 / _t6);
  const double _t51 = xc_powr(_t8, -13, 6);
  const double _t52 = _t50*_t51;
  const double _t53 = (0.1e1 / 0.4e1)*_t31 - 0.1e1 / 0.4e1*x;
  const double _t54 = _t13*_t34;
  const double _t55 = _t28*_t54;
  const double _t56 = xc_powr(_t10, -3, 2);
  const double _t57 = _t14*_t56;
  const double _t58 = _t33*_t57;
  const double _t59 = _t32*_t58;
  const double _t60 = xc_powi(x, 10);
  const double _t61 = _t39*_t50;
  const double _t62 = _t60*_t61;
  const double _t63 = (x * x * x * x);
  const double _t64 = _t30*_t63;
  const double _t65 = _t16*_t48;
  const double _t66 = _t60*_t65;
  const double _t67 = _t62 + 0.5e1*_t64 + 0.3e1*_t66 - 0.1e1;
  const double _t68 = -_t67;
  const double _t69 = _t35*_t68;
  const double _t70 = _t1*_t59 + _t1*_t69 + (0.7e1 / 0.8e1)*_t29*_t45 + (0.1e1 / 0.2e1)*_t36 + (0.3e1 / 0.8e1)*_t47*_t49 + (0.7e1 / 0.16e2)*_t47*_t52 - _t53*_t55;
#endif
#if _KMAX >= 3
  const double _t71 = (0.3e1 / 0.8e1)*_t20;
  const double _t72 = (0.3e1 / 0.16e2)*_t2;
  const double _t73 = -_t72 - 0.3e1 / 0.16e2*_t9;
  const double _t74 = _t17*_t25*_t3*_t38*_t39*_t73 - _t41*_t72 - _t71*x;
  const double _t75 = xc_powr(_t22, -5, 2);
  const double _t76 = _t37*_t42*_t75;
  const double _t77 = -0.9e1 / 0.16e2*_t2 - 0.9e1 / 0.16e2*_t9;
  const double _t78 = _t18*_t39;
  const double _t79 = _t25*_t78;
  const double _t80 = _t5*_t79;
  const double _t81 = xc_powi(x, 12);
  const double _t82 = xc_powr(_t8, -7, 3);
  const double _t83 = _t18*_t82;
  const double _t84 = _t50*_t83;
  const double _t85 = _t81*_t84;
  const double _t86 = _t48*_t78;
  const double _t87 = _t81*_t86;
  const double _t88 = _t38*_t79;
  const double _t89 = _t19*(-0.2e1*_t62 - 0.10e2*_t64 - 0.6e1*_t66 + 0.2e1);
  const double _t90 = -_t1*_t41 - _t21 - _t40*_t89 + _t53*_t88 + _t73*_t87 + _t77*_t80 + _t85*(-0.1e1 / 0.4e1*_t2 - 0.1e1 / 0.4e1*_t9);
  const double _t91 = _t42*_t43;
  const double _t92 = _t24*_t60;
  const double _t93 = xc_powi(x, 16);
  const double _t94 = _t24*_t93;
  const double _t95 = xc_powr(_t6, -5, 2);
  const double _t96 = _t26*_t95;
  const double _t97 = (0.1e1 / (_t6 * _t6));
  const double _t98 = _t51*_t97;
  const double _t99 = xc_powr(_t8, -19, 6);
  const double _t100 = _t48*_t99;
  const double _t101 = _t27*_t54;
  const double _t102 = _t101*_t29;
  const double _t103 = (0.9e1 / 0.8e1)*_t31 - 0.9e1 / 0.8e1*x;
  const double _t104 = _t46*_t54;
  const double _t105 = _t104*_t49;
  const double _t106 = _t104*_t52;
  const double _t107 = (_t32 * _t32);
  const double _t108 = _t107*_t13*_t56;
  const double _t109 = xc_powr(_t10, -5, 2);
  const double _t110 = 0.3e1*_t31 - 0.3e1*x;
  const double _t111 = _t109*_t110*_t14*_t33;
  const double _t112 = _t111*_t32;
  const double _t113 = (0.3e1 / 0.8e1)*_t62 + (0.15e2 / 0.8e1)*_t64 + (0.9e1 / 0.8e1)*_t66 - 0.3e1 / 0.8e1;
  const double _t114 = _t58*_t67;
  const double _t115 = _t32*_t57;
  const double _t116 = _t115*_t68;
  const double _t117 = (0.1e1 / 0.2e1)*x;
  const double _t118 = (x * x * x);
  const double _t119 = _t118*_t30;
  const double _t120 = xc_powi(x, 9);
  const double _t121 = _t120*_t65;
  const double _t122 = _t120*_t61;
  const double _t123 = xc_powi(x, 15);
  const double _t124 = _t16*_t95;
  const double _t125 = _t123*_t124;
  const double _t126 = _t39*_t97;
  const double _t127 = _t123*_t126;
  const double _t128 = _t48*_t82;
  const double _t129 = _t123*_t128;
  const double _t130 = 0.20e2*_t119 + 0.45e2*_t121 + 0.15e2*_t122 + 0.27e2*_t125 + 0.9e1*_t127 + 0.4e1*_t129;
  const double _t131 = -_t130;
  const double _t132 = _t131*_t35;
  const double _t133 = _t1*_t112 + _t1*_t114 + _t1*_t132 + (0.91e2 / 0.32e2)*_t100*_t94 + _t102*(-0.21e2 / 0.8e1*_t31 + (0.21e2 / 0.8e1)*x) - _t103*_t105 + _t106*(-0.21e2 / 0.16e2*_t31 + (0.21e2 / 0.16e2)*x) - 0.3e1 / 0.8e1*_t108*_t28 - _t113*_t55 + _t116*_t117 + (0.35e2 / 0.8e1)*_t45*_t63 + (0.27e2 / 0.4e1)*_t49*_t92 + (0.63e2 / 0.8e1)*_t52*_t92 + (0.3e1 / 0.4e1)*_t59 + (0.3e1 / 0.4e1)*_t69 + (0.27e2 / 0.8e1)*_t94*_t96 + (0.63e2 / 0.16e2)*_t94*_t98;
#endif
#if _KMAX >= 4
  const double _t134 = (0.5e1 / 0.16e2)*_t2;
  const double _t135 = (0.3e1 / 0.4e1)*x;
  const double _t136 = -0.27e2 / 0.16e2*_t2 - 0.27e2 / 0.16e2*_t9;
  const double _t137 = _t74*_t75;
  const double _t138 = 0.3e1*_t70;
  const double _t139 = xc_powi(x, 17);
  const double _t140 = xc_powr(_t8, -10, 3);
  const double _t141 = (0.3e1 / 0.2e1)*_t31 - 0.3e1 / 0.2e1*x;
  const double _t142 = _t120*_t24;
  const double _t143 = _t123*_t24;
  const double _t144 = xc_powr(_t6, -7, 2);
  const double _t145 = _t24*xc_powi(x, 21);
  const double _t146 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t147 = _t54*_t60;
  const double _t148 = _t54*_t93;
  const double _t149 = _t108*_t46;
  const double _t150 = _t13*_t28;
  const double _t151 = _t1*_t33;
  const double _t152 = _t150*_t56;
  const double _t153 = _t109*_t14*_t32;
  const double _t154 = _t135*_t68;
  const double _t155 = xc_powi(x, 8);
  const double _t156 = xc_powi(x, 14);
  const double _t157 = xc_powi(x, 20);
#endif

  const double f = xc_asinh(_t1*_t15);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t23*_t37;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _t23*_t70 + _t42*_t44;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _t133*_t23 + _t44*_t90 + 0.2e1*_t70*_t91 + _t74*_t76;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = 0.3e1*_t133*_t91 + _t137*_t138*_t42 + 0.2e1*_t137*_t37*_t90 + _t138*_t43*_t90 + _t23*(_t1*_t130*_t58 + _t1*_t35*(-0.810e3*_t124*_t156 - 0.270e3*_t126*_t156 - 0.120e3*_t128*_t156 - 0.28e2*_t140*_t157*_t97 - 0.405e3*_t144*_t157*_t16 - 0.135e3*_t146*_t157*_t39 - 0.155e3*_t155*_t61 - 0.465e3*_t155*_t65 - 0.72e2*_t157*_t82*_t95 - 0.60e2*_t2*_t30) + (0.1547e4 / 0.16e2)*_t100*_t143 + _t100*_t148*(-0.91e2 / 0.8e1*_t31 + (0.91e2 / 0.8e1)*x) + _t101*_t63*(-0.35e2 / 0.2e1*_t31 + (0.35e2 / 0.2e1)*x) + _t102*(-0.21e2 / 0.4e1*_t62 - 0.105e3 / 0.4e1*_t64 - 0.63e2 / 0.4e1*_t66 + 0.21e2 / 0.4e1) + _t105*(-0.9e1 / 0.4e1*_t62 - 0.45e2 / 0.4e1*_t64 - 0.27e2 / 0.4e1*_t66 + 0.9e1 / 0.4e1) + _t106*(-0.21e2 / 0.8e1*_t62 - 0.105e3 / 0.8e1*_t64 - 0.63e2 / 0.8e1*_t66 + 0.21e2 / 0.8e1) - _t107*_t109*_t141*_t150 - 0.21e2 / 0.4e1*_t108*_t27*_t29 + _t110*_t153*_t154 + _t111*_t117*_t67 + _t112 + _t114 + _t115*_t131*_t135 + 0.2e1*_t116 + (0.35e2 / 0.2e1)*_t118*_t45 + _t132 + (0.645e3 / 0.8e1)*_t142*_t49 + (0.1505e4 / 0.16e2)*_t142*_t52 + (0.459e3 / 0.4e1)*_t143*_t96 + (0.1071e4 / 0.8e1)*_t143*_t98 + (0.405e3 / 0.8e1)*_t144*_t145*_t26 + (0.945e3 / 0.16e2)*_t145*_t146*_t51 + (0.819e3 / 0.16e2)*_t145*_t95*_t99 + (0.1729e4 / 0.64e2)*_t145*_t97/xc_powr(_t8, 25, 6) + _t147*_t49*(-0.27e2*_t31 + 0.27e2*x) + _t147*_t52*(-0.63e2 / 0.2e1*_t31 + (0.63e2 / 0.2e1)*x) + _t148*_t96*(-0.27e2 / 0.2e1*_t31 + (0.27e2 / 0.2e1)*x) + _t148*_t98*(-0.63e2 / 0.4e1*_t31 + (0.63e2 / 0.4e1)*x) - 0.9e1 / 0.4e1*_t149*_t49 - 0.21e2 / 0.8e1*_t149*_t52 + _t151*_t153*(0.3e1*_t62 + 0.15e2*_t64 + 0.9e1*_t66 - 0.3e1) + _t152*_t32*_t68 + (0.1e1 / 0.2e1)*_t152*_t33*_t67 + _t154*_t57*_t67 + _t55*(-0.10e2*_t119 - 0.45e2 / 0.2e1*_t121 - 0.15e2 / 0.2e1*_t122 - 0.27e2 / 0.2e1*_t125 - 0.9e1 / 0.2e1*_t127 - 0.2e1*_t129) + _t110*_t14*_t151*_t32*(0.5e1*_t31 - 0.5e1*x)/xc_powr(_t10, 7, 2)) + _t44*(_t103*_t87 + _t113*_t88 + _t136*_t139*_t78*_t95 + _t139*_t140*_t18*_t48*(-0.7e1 / 0.4e1*_t2 - 0.7e1 / 0.4e1*_t9) + _t139*_t83*_t97*(-0.9e1 / 0.4e1*_t2 - 0.9e1 / 0.4e1*_t9) + _t141*_t85 - _t19*_t40*(-0.40e2*_t119 - 0.90e2*_t121 - 0.30e2*_t122 - 0.54e2*_t125 - 0.18e2*_t127 - 0.8e1*_t129) + _t29*_t79*(-0.7e1 / 0.2e1*_t2 - 0.7e1 / 0.2e1*_t9) - 0.3e1 / 0.8e1*_t41 + _t46*_t84*(-0.21e2 / 0.4e1*_t2 - 0.21e2 / 0.4e1*_t9) + _t46*_t86*(-0.63e2 / 0.16e2*_t2 - 0.63e2 / 0.16e2*_t9) + _t80*((0.27e2 / 0.8e1)*_t31 - 0.27e2 / 0.8e1*x) - 0.3e1 / 0.8e1*_t89*x) + _t76*(-_t135*_t41 + _t136*_t80 - _t71 - _t72*_t89 + _t77*_t87 + _t85*(-0.3e1 / 0.4e1*_t2 - 0.3e1 / 0.4e1*_t9) + _t88*(-_t135 + (0.3e1 / 0.4e1)*_t31)) + _t37*_t42*_t74*(-_t134*_t41 + _t17*_t25*_t3*_t38*_t39*(-_t134 - 0.5e1 / 0.16e2*_t9) - 0.5e1 / 0.8e1*_t20*x)/xc_powr(_t22, 7, 2);
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(gg99_r_branch2_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = (x * x * x);
  const double _t2 = xc_powi(M_PI, -6);
  const double _t3 = xc_powi(x, 6);
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.48e2)*_t4 - 0.1e1;
  const double _t6 = xc_powr(_t5, 1, 2);
  const double _t7 = (0.1e1 / 0.3e1)*atan(_t6);
  const double _t8 = cos(_t7);
  const double _t9 = _t1*_t8;
  const double _t10 = xc_powr(0.3e1, 1, 4)*xc_powr(_t9, 1, 2);
  const double _t11 = _t10/xc_powr(M_PI, 3, 2);
  const double _t12 = (0.1e1 / 0.2e1)*_t11;
#if _KMAX >= 1
  const double _t13 = (0.1e1 / _t8);
  const double _t14 = _t13/_t1;
  const double _t15 = (x * x);
  const double _t16 = (0.3e1 / 0.2e1)*_t8;
  const double _t17 = sin(_t7);
  const double _t18 = (0.1e1 / _t6);
  const double _t19 = _t17*_t18;
  const double _t20 = _t15*_t16 - 0.1e1 / 0.2e1*_t15*_t19;
  const double _t21 = xc_powr(0.3e1, 1, 2);
  const double _t22 = (0.1e1 / (M_PI * M_PI * M_PI));
  const double _t23 = _t21*_t22;
  const double _t24 = (0.1e1 / 0.4e1)*_t23*_t9 + 0.1e1;
  const double _t25 = xc_powr(_t24, -1, 2);
  const double _t26 = _t12*_t25;
  const double _t27 = _t20*_t26;
#endif
#if _KMAX >= 2
  const double _t28 = (0.1e1 / (x * x * x * x));
  const double _t29 = _t20*_t28;
  const double _t30 = _t11*_t25;
  const double _t31 = _t13*_t30;
  const double _t32 = (0.3e1 / 0.2e1)*_t31;
  const double _t33 = (0.1e1 / _t3);
  const double _t34 = (_t20 * _t20);
  const double _t35 = (0.1e1 / (_t8 * _t8));
  const double _t36 = _t34*_t35;
  const double _t37 = _t33*_t36;
  const double _t38 = _t19*_t35;
  const double _t39 = 0.3e1*_t8;
  const double _t40 = (0.1e1 / _t5);
  const double _t41 = _t8*x;
  const double _t42 = _t40*_t41;
  const double _t43 = _t19*x;
  const double _t44 = xc_powi(x, 7);
  const double _t45 = xc_powr(_t5, -3, 2);
  const double _t46 = _t17*_t45;
  const double _t47 = _t2*_t46;
  const double _t48 = _t44*_t47;
  const double _t49 = _t39*x - 0.1e1 / 0.2e1*_t42 - 0.5e1 / 0.2e1*_t43 + (0.1e1 / 0.32e2)*_t48;
  const double _t50 = _t14*_t26;
  const double _t51 = xc_powr(_t24, -3, 2);
  const double _t52 = _t23*_t8;
  const double _t53 = _t15*_t52;
  const double _t54 = (0.1e1 / 0.8e1)*_t15*_t17*_t18*_t21*_t22 - 0.3e1 / 0.8e1*_t53;
  const double _t55 = _t51*_t54;
  const double _t56 = _t14*_t20;
  const double _t57 = _t12*_t56;
#endif
#if _KMAX >= 3
  const double _t58 = xc_powi(x, 5);
  const double _t59 = (0.1e1 / _t58);
  const double _t60 = _t20*_t31;
  const double _t61 = 0.6e1*_t60;
  const double _t62 = (_t20 * _t20 * _t20);
  const double _t63 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t64 = _t62*_t63;
  const double _t65 = xc_powi(x, -9);
  const double _t66 = _t26*_t65;
  const double _t67 = _t30*_t36;
  const double _t68 = (0.1e1 / _t44);
  const double _t69 = (0.9e1 / 0.2e1)*_t68;
  const double _t70 = _t40*_t59;
  const double _t71 = xc_powr(M_PI, -15, 2);
  const double _t72 = _t10*_t25*_t71;
  const double _t73 = _t20*_t72;
  const double _t74 = _t35*_t46;
  const double _t75 = _t74*x;
  const double _t76 = _t20*_t30;
  const double _t77 = _t38*_t59;
  const double _t78 = (_t17 * _t17);
  const double _t79 = _t63*_t78;
  const double _t80 = _t76*_t79;
  const double _t81 = _t19*_t30;
  const double _t82 = _t34*_t63;
  const double _t83 = _t81*_t82;
  const double _t84 = _t31*_t49;
  const double _t85 = 0.3e1*_t28;
  const double _t86 = _t13*_t29;
  const double _t87 = _t11*_t55;
  const double _t88 = 0.3e1*_t87;
  const double _t89 = _t35*_t49;
  const double _t90 = _t81*_t89;
  const double _t91 = _t29*_t38;
  const double _t92 = _t33*_t35;
  const double _t93 = _t27*_t92;
  const double _t94 = 0.6e1*_t8;
  const double _t95 = -_t42 - 0.5e1*_t43 + (0.1e1 / 0.16e2)*_t48 + _t94*x;
  const double _t96 = _t49*_t87;
  const double _t97 = xc_powr(_t24, -5, 2);
  const double _t98 = (0.3e1 / 0.8e1)*_t15*_t17*_t18*_t21*_t22 - 0.9e1 / 0.8e1*_t53;
  const double _t99 = _t97*_t98;
  const double _t100 = _t54*_t57;
  const double _t101 = _t23*_t41;
  const double _t102 = _t21/xc_powi(M_PI, 9);
  const double _t103 = _t102*_t46;
  const double _t104 = _t103*_t44;
  const double _t105 = -0.3e1 / 0.4e1*_t101 - 0.1e1 / 0.128e3*_t104 + (0.5e1 / 0.8e1)*_t17*_t18*_t21*_t22*x + (0.1e1 / 0.8e1)*_t21*_t22*_t40*_t8*x;
  const double _t106 = _t51*_t57;
  const double _t107 = xc_powi(x, 12);
  const double _t108 = xc_powi(M_PI, -12);
  const double _t109 = xc_powr(_t5, -5, 2);
  const double _t110 = _t109*_t17;
  const double _t111 = _t108*_t110;
  const double _t112 = _t107*_t111;
  const double _t113 = (0.1e1 / (_t5 * _t5));
  const double _t114 = _t113*_t8;
  const double _t115 = _t114*_t4;
  const double _t116 = _t4*_t46;
  const double _t117 = -0.3e1 / 0.512e3*_t112 + (0.3e1 / 0.32e2)*_t115 + (0.3e1 / 0.8e1)*_t116 - 0.11e2 / 0.2e1*_t19 - _t39*_t40 + _t39 + (0.1e1 / 0.2e1)*_t46;
#endif
#if _KMAX >= 4
  const double _t118 = (0.1e1 / (_t8 * _t8 * _t8 * _t8));
  const double _t119 = _t30/xc_powi(x, 10);
  const double _t120 = xc_powi(x, -8);
  const double _t121 = _t120*_t67;
  const double _t122 = _t13*_t20;
  const double _t123 = (0.3e1 / 0.32e2)*_t72;
  const double _t124 = _t33*_t40;
  const double _t125 = (0.3e1 / 0.16e2)*_t73;
  const double _t126 = _t10*_t20;
  const double _t127 = _t76*_t92;
  const double _t128 = 0.3e1*_t118;
  const double _t129 = (0.11e2 / 0.2e1)*_t40;
  const double _t130 = 0.18e2*_t59;
  const double _t131 = _t26*_t92;
  const double _t132 = _t122*_t87;
  const double _t133 = (0.3e1 / 0.2e1)*_t87;
  const double _t134 = _t49*_t70;
  const double _t135 = _t68*_t76;
  const double _t136 = _t135*_t95;
  const double _t137 = _t66*_t82;
  const double _t138 = (0.9e1 / 0.2e1)*_t86;
  const double _t139 = _t11*_t54*_t99;
  const double _t140 = (0.3e1 / 0.2e1)*_t139;
  const double _t141 = _t105*_t11;
  const double _t142 = _t141*_t51;
  const double _t143 = (0.3e1 / 0.2e1)*_t142;
  const double _t144 = _t19*_t63;
  const double _t145 = _t117*_t28;
  const double _t146 = _t20*_t92;
  const double _t147 = _t14*_t49;
  const double _t148 = (0.1e1 / x);
  const double _t149 = _t148*_t8;
  const double _t150 = 0.3e1*_t148;
  const double _t151 = xc_powi(x, 11);
  const double _t152 = _t2*_t58;
#endif

  const double f = xc_asinh(_t12);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _t14*_t27;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _t26*_t37 + _t27*_t28*_t38 - _t29*_t32 + _t49*_t50 + _t55*_t57;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = _t100*_t99 + _t105*_t106 + _t117*_t50 + _t13*_t27*_t70 + _t14*_t96 + _t28*_t90 + _t37*_t87 + _t49*_t93 + _t59*_t61 + _t64*_t66 - _t67*_t69 + (0.3e1 / 0.2e1)*_t68*_t83 + _t70*_t80 - 0.1e1 / 0.32e2*_t73*_t75 - 0.7e1 / 0.2e1*_t76*_t77 - _t84*_t85 - _t86*_t88 + _t87*_t91 + _t93*_t95;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = _t100*_t97*(-0.9e1 / 0.4e1*_t101 - 0.3e1 / 0.128e3*_t104 + (0.15e2 / 0.8e1)*_t17*_t18*_t21*_t22*x + (0.3e1 / 0.8e1)*_t21*_t22*_t40*_t8*x) + _t100*_t98*((0.5e1 / 0.8e1)*_t15*_t17*_t18*_t21*_t22 - 0.15e2 / 0.8e1*_t53)/xc_powr(_t24, 7, 2) + _t106*(-0.3e1 / 0.128e3*_t102*_t114*_t3 - 0.3e1 / 0.32e2*_t103*_t3 + (0.3e1 / 0.2048e4)*_t107*_t109*_t17*_t21/xc_powi(M_PI, 15) + (0.11e2 / 0.8e1)*_t17*_t18*_t21*_t22 + (0.3e1 / 0.4e1)*_t21*_t22*_t40*_t8 - 0.1e1 / 0.8e1*_t23*_t46 - 0.3e1 / 0.4e1*_t52) + (0.3e1 / 0.512e3)*_t110*_t126*_t25*_t3*_t35/xc_powr(M_PI, 27, 2) - _t113*_t122*_t123 - _t113*_t125*_t79 + _t117*_t127 + _t117*_t133*_t14 + _t118*_t120*_t129*_t30*_t34*_t78 + _t119*_t128*_t19*_t62 - 0.9e1*_t119*_t64 - 0.23e2*_t120*_t83 + 0.2e1*_t121*_t40 + (0.75e2 / 0.2e1)*_t121 - _t123*_t46*_t89*x - _t124*_t61 - 0.12e2*_t124*_t80 + _t125*_t74 - 0.3e1 / 0.32e2*_t126*_t55*_t71*_t75 + (0.47e2 / 0.2e1)*_t127*_t19 + (0.5e1 / 0.2e1)*_t127*_t46 + _t128*(_t17 * _t17 * _t17)*_t33*_t45*_t76 - 0.9e1*_t13*_t28*_t96 + _t130*_t132 + _t130*_t84 + _t131*(_t49 * _t49) + _t131*_t49*_t95 + (0.3e1 / 0.2e1)*_t132*_t70 + _t133*_t146*_t95 + _t133*_t64*_t65 + 0.3e1*_t134*_t30*_t79 + _t134*_t32 + 0.2e1*_t135*_t144*_t49 - 0.6e1*_t135*_t89 + (0.5e1 / 0.2e1)*_t136*_t144 - 0.15e2 / 0.2e1*_t136*_t35 + _t137*_t49 + _t137*_t95 + _t137*(-_t16*_t40*x + 0.9e1*_t41 - 0.15e2 / 0.2e1*_t43 + (0.3e1 / 0.32e2)*_t48) - _t138*_t139 - _t138*_t142 + _t140*_t147 + _t140*_t37 + _t140*_t91 + _t141*_t56*_t99 + _t143*_t147 + _t143*_t37 + _t143*_t91 - 0.9e1 / 0.2e1*_t145*_t31 + (0.3e1 / 0.2e1)*_t145*_t35*_t81 + (0.3e1 / 0.2e1)*_t146*_t96 + _t19*_t69*_t82*_t87 + _t20*_t70*_t79*_t88 - 0.21e2 / 0.2e1*_t20*_t77*_t87 - 0.30e2*_t33*_t60 - 0.27e2 / 0.2e1*_t36*_t68*_t87 + _t38*_t85*_t96 + _t50*(-0.15e2 / 0.512e3*_t108*_t151*_t8/(_t5 * _t5 * _t5) - 0.3e1 / 0.16e2*_t110*_t152 - 0.9e1 / 0.64e2*_t111*_t151 + (0.1e1 / 0.2e1)*_t113*_t149 + (0.21e2 / 0.16e2)*_t114*_t152 - _t129*_t149 - _t150*_t19 + _t150*_t46 + (0.15e2 / 0.8192e4)*_t17*xc_powi(x, 17)/(xc_powi(M_PI, 18)*xc_powr(_t5, 7, 2)) + (0.83e2 / 0.32e2)*_t47*_t58) - 0.21e2 / 0.2e1*_t59*_t90 + _t93*(-0.3e1 / 0.256e3*_t112 + (0.3e1 / 0.16e2)*_t115 + (0.3e1 / 0.4e1)*_t116 - 0.11e2*_t19 - _t40*_t94 + _t46 + _t94) - 0.1e1 / 0.8e1*_t46*_t72*_t82/_t15 + _t118*(_t20 * _t20 * _t20 * _t20)*_t26/_t107;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(gg99_r_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  const double _t1 = xc_powr(0.2e1, 2, 3);
  const double _t2 = xc_powr(0.3e1, 1, 6);
  const double _t3 = M_PI*_t1*_t2 - 1.0e-10;
  const double _t4 = x > _t3;
  const double _t5 = M_PI*_t1*_t2;
  const double _t6 = _t5 + 1.0e-10;
  const double _t7 = x > _t6;
  const double _t8 = x < _t5;
#if _KMAX >= 1
  const double _t9 = my_piecewise3(_t4, 0, 0.1e1);
  const double _t10 = my_piecewise3(_t7, 0.1e1, 0);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(_t8) XC_CAT(gg99_r_branch1_k, _KMAX)(p, my_piecewise3(_t4, _t3, x), _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t8)) XC_CAT(gg99_r_branch2_k, _KMAX)(p, my_piecewise3(_t7, x, _t6), _hc1);

  const double f = my_piecewise3(_t8, _hc0[0], _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = my_piecewise3(_t8, _hc0[1]*_t9, _hc1[1]*_t10);
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = my_piecewise3(_t8, _hc0[2]*(_t9 * _t9), _hc1[2]*(_t10 * _t10));
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = my_piecewise3(_t8, _hc0[3]*(_t9 * _t9 * _t9), _hc1[3]*(_t10 * _t10 * _t10));
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = my_piecewise3(_t8, _hc0[4]*(_t9 * _t9 * _t9 * _t9), _hc1[4]*(_t10 * _t10 * _t10 * _t10));
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(gg99_f0_num_orig_k, _KMAX)(const xc_func_type *p, double r, double *out) {

  const double _t1 = exp(-0.2e1*r);
  const double _t2 = 0.12e2*xc_log1p(_t1);
#if _KMAX >= 1
  const double _t3 = _t1 + 0.1e1;
  const double _t4 = _t1/_t3;
  const double _t5 = _t4*r;
#endif
#if _KMAX >= 2
  const double _t6 = exp(-0.4e1*r);
  const double _t7 = (0.1e1 / (_t3 * _t3));
  const double _t8 = 0.48e2*_t4;
#endif
#if _KMAX >= 3
  const double _t9 = _t6*_t7;
  const double _t10 = exp(-0.6e1*r)/(_t3 * _t3 * _t3);
  const double _t11 = _t10*r;
  const double _t12 = _t9*r;
#endif
#if _KMAX >= 4
  const double _t13 = 0.192e3*_t4;
#endif

  const double f = -_t2*r + 0.12e2*xc_dilogarithm(-_t1) + (M_PI * M_PI);
  out[0] = f;
#if _KMAX >= 1
  const double df_dr = _t2 + 0.24e2*_t5;
  out[1] = df_dr;
#endif
#if _KMAX >= 2
  const double d2f_dr2 = 0.48e2*_t6*_t7*r - _t8*r;
  out[2] = d2f_dr2;
#endif
#if _KMAX >= 3
  const double d3f_dr3 = 0.192e3*_t11 - 0.288e3*_t12 + 0.96e2*_t5 - _t8 + 0.48e2*_t9;
  out[3] = d3f_dr3;
#endif
#if _KMAX >= 4
  const double d4f_dr4 = 0.384e3*_t10 - 0.2304e4*_t11 + 0.1344e4*_t12 - _t13*r + _t13 - 0.576e3*_t9 + 0.1152e4*r*exp(-0.8e1*r)/(_t3 * _t3 * _t3 * _t3);
  out[4] = d4f_dr4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(gg99_f0_num_taylor_k, _KMAX)(const xc_func_type *p, double r, double *out) {

  const double _t1 = (r * r * r);
  const double _t2 = xc_powi(r, 5);
  const double _t3 = xc_powi(r, 7);
  const double _t4 = xc_powi(r, 9);
  const double _t5 = xc_powi(r, 11);
  const double _t6 = xc_powi(r, 13);
  const double _t7 = xc_log1p(0.1e1);
#if _KMAX >= 1
  const double _t8 = (r * r);
  const double _t9 = (r * r * r * r);
  const double _t10 = xc_powi(r, 6);
  const double _t11 = xc_powi(r, 8);
  const double _t12 = xc_powi(r, 10);
  const double _t13 = xc_powi(r, 12);
#endif

  const double f = -0.2e1*_t1 + (0.3e1 / 0.5e1)*_t2 - 0.4e1 / 0.21e2*_t3 + (0.17e2 / 0.270e3)*_t4 - 0.124e3 / 0.5775e4*_t5 + (0.1382e4 / 0.184275e6)*_t6 + 0.12e2*_t7*r - 0.43688e5 / 0.16372125e8*xc_powi(r, 15) + 0.12e2*xc_dilogarithm(-0.1e1) + (M_PI * M_PI);
  out[0] = f;
#if _KMAX >= 1
  const double df_dr = -0.4e1 / 0.3e1*_t10 + (0.17e2 / 0.30e2)*_t11 - 0.124e3 / 0.525e3*_t12 + (0.1382e4 / 0.14175e5)*_t13 + 0.12e2*_t7 - 0.6e1*_t8 + 0.3e1*_t9 - 0.43688e5 / 0.1091475e7*xc_powi(r, 14);
  out[1] = df_dr;
#endif
#if _KMAX >= 2
  const double d2f_dr2 = 0.12e2*_t1 - 0.8e1*_t2 + (0.68e2 / 0.15e2)*_t3 - 0.248e3 / 0.105e3*_t4 + (0.5528e4 / 0.4725e4)*_t5 - 0.87376e5 / 0.155925e6*_t6 - 0.12e2*r;
  out[2] = d2f_dr2;
#endif
#if _KMAX >= 3
  const double d3f_dr3 = (0.476e3 / 0.15e2)*_t10 - 0.744e3 / 0.35e2*_t11 + (0.60808e5 / 0.4725e4)*_t12 - 0.1135888e7 / 0.155925e6*_t13 + 0.36e2*_t8 - 0.40e2*_t9 - 0.12e2;
  out[3] = d3f_dr3;
#endif
#if _KMAX >= 4
  const double d4f_dr4 = -0.160e3*_t1 + (0.952e3 / 0.5e1)*_t2 - 0.5952e4 / 0.35e2*_t3 + (0.121616e6 / 0.945e3)*_t4 - 0.4543552e7 / 0.51975e5*_t5 + 0.72e2*r;
  out[4] = d4f_dr4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(gg99_f0_num_k, _KMAX)(const xc_func_type *p, double r, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(gg99_f0_num_taylor_k, _KMAX)(p, r, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(gg99_f0_num_orig_k, _KMAX)(p, r, _hc1);
  const double _t1 = r < 0.1e1 / 0.4e1;

  const double f = my_piecewise3(_t1, _hc0[0], _hc1[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dr = my_piecewise3(_t1, _hc0[1], _hc1[1]);
  out[1] = df_dr;
#endif
#if _KMAX >= 2
  const double d2f_dr2 = my_piecewise3(_t1, _hc0[2], _hc1[2]);
  out[2] = d2f_dr2;
#endif
#if _KMAX >= 3
  const double d3f_dr3 = my_piecewise3(_t1, _hc0[3], _hc1[3]);
  out[3] = d3f_dr3;
#endif
#if _KMAX >= 4
  const double d4f_dr4 = my_piecewise3(_t1, _hc0[4], _hc1[4]);
  out[4] = d4f_dr4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(gg99_f0_k, _KMAX)(const xc_func_type *p, double r, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(gg99_f0_num_k, _KMAX)(p, r, _hc0);
  const double _t1 = (0.1e1 / r);
  const double _t2 = xc_powr(0.6e1, 2, 3)*M_CBRTPI/(M_PI*M_CBRT3*xc_powr(((0.1e1 / ((0.1e1 / 0.2e1)*exp(r) + (0.1e1 / 0.2e1)*exp(-r)))), 2, 3));
  const double _t3 = _hc0[0]*_t2;
  const double _t4 = (0.1e1 / 0.9e1)*_t3;
#if _KMAX >= 1
  const double _t5 = (0.1e1 / (r * r));
  const double _t6 = _hc0[1]*_t2;
  const double _t7 = (0.1e1 / 0.9e1)*_t1;
  const double _t8 = tanh(r);
  const double _t9 = _t3*_t8;
  const double _t10 = (0.2e1 / 0.27e2)*_t1;
#endif
#if _KMAX >= 2
  const double _t11 = (0.1e1 / (r * r * r));
  const double _t12 = (0.2e1 / 0.9e1)*_t3;
  const double _t13 = _t5*_t6;
  const double _t14 = _hc0[2]*_t2;
  const double _t15 = (0.4e1 / 0.27e2)*_t5;
  const double _t16 = _t1*_t6;
  const double _t17 = (0.4e1 / 0.27e2)*_t16;
  const double _t18 = (_t8 * _t8);
  const double _t19 = _t18*_t3;
  const double _t20 = (0.4e1 / 0.81e2)*_t1;
  const double _t21 = 0.1e1 - _t18;
  const double _t22 = _t21*_t3;
#endif
#if _KMAX >= 3
  const double _t23 = (0.1e1 / (r * r * r * r));
  const double _t24 = _t23*_t3;
  const double _t25 = _t11*_t6;
  const double _t26 = _t14*_t5;
  const double _t27 = _hc0[3]*_t2;
  const double _t28 = _t1*_t14;
  const double _t29 = (_t8 * _t8 * _t8);
  const double _t30 = _t29*_t3;
  const double _t31 = (0.8e1 / 0.243e3)*_t1;
  const double _t32 = _t21*_t5;
  const double _t33 = _t16*_t21;
  const double _t34 = 0.2e1 - 0.2e1*_t18;
  const double _t35 = _t1*_t34;
  const double _t36 = (0.2e1 / 0.81e2)*_t35;
#endif
#if _KMAX >= 4
  const double _t37 = (0.16e2 / 0.9e1)*_t8;
  const double _t38 = (0.8e1 / 0.81e2)*_t34;
#endif

  const double f = _t1*_t4;
  out[0] = f;
#if _KMAX >= 1
  const double df_dr = _t10*_t9 - _t4*_t5 + _t6*_t7;
  out[1] = df_dr;
#endif
#if _KMAX >= 2
  const double d2f_dr2 = _t10*_t22 + _t11*_t12 - 0.2e1 / 0.9e1*_t13 + _t14*_t7 - _t15*_t9 + _t17*_t8 + _t19*_t20;
  out[2] = d2f_dr2;
#endif
#if _KMAX >= 3
  const double d3f_dr3 = (0.4e1 / 0.9e1)*_t11*_t9 - _t12*_t32 - 0.4e1 / 0.9e1*_t13*_t8 - _t15*_t19 + _t17*_t18 + _t20*_t21*_t9 - 0.2e1 / 0.3e1*_t24 + (0.2e1 / 0.3e1)*_t25 - 0.1e1 / 0.3e1*_t26 + _t27*_t7 + (0.2e1 / 0.9e1)*_t28*_t8 + _t30*_t31 + (0.2e1 / 0.9e1)*_t33 - _t36*_t9;
  out[3] = d3f_dr3;
#endif
#if _KMAX >= 4
  const double d4f_dr4 = _hc0[4]*_t2*_t7 + (0.8e1 / 0.27e2)*_t1*_t27*_t8 + (0.16e2 / 0.729e3)*_t1*_t3*(_t8 * _t8 * _t8 * _t8) + (0.4e1 / 0.3e1)*_t11*_t14 + (0.16e2 / 0.27e2)*_t11*_t19 + (0.8e1 / 0.9e1)*_t11*_t22 - 0.16e2 / 0.27e2*_t13*_t18 - 0.8e1 / 0.9e1*_t13*_t21 + (0.32e2 / 0.243e3)*_t16*_t29 - _t16*_t38*_t8 + _t18*_t22*_t31 + (0.8e1 / 0.27e2)*_t18*_t28 + _t19*_t31*(0.3e1 - 0.3e1*_t18) - 0.4e1 / 0.243e3*_t19*_t35 + _t20*(_t21 * _t21)*_t3 + (0.4e1 / 0.9e1)*_t21*_t28 - _t22*_t36 - 0.8e1 / 0.3e1*_t23*_t6 - _t24*_t37 + _t25*_t37 - 0.8e1 / 0.9e1*_t26*_t8 - 0.4e1 / 0.9e1*_t27*_t5 + (0.8e1 / 0.3e1)*_t3/xc_powi(r, 5) - 0.32e2 / 0.243e3*_t30*_t5 - 0.16e2 / 0.81e2*_t32*_t9 + (0.16e2 / 0.81e2)*_t33*_t8 + _t38*_t5*_t9;
  out[4] = d4f_dr4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(gg99_f_k, _KMAX)(const xc_func_type *p, double x, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(gg99_r_k, _KMAX)(p, x, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(gg99_f0_k, _KMAX)(p, _hc0[0], _hc1);
#if _KMAX >= 2
  const double _t1 = ((_hc0[1]) * (_hc0[1]));
#endif
#if _KMAX >= 3
  const double _t2 = 0.3e1*_hc1[2];
#endif

  const double f = _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = _hc0[1]*_hc1[1];
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = _hc0[2]*_hc1[1] + _hc1[2]*_t1;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[3] + _hc0[1]*_hc0[2]*_t2 + _hc0[3]*_hc1[1];
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_hc1[4] + 0.4e1*_hc0[1]*_hc0[3]*_hc1[2] + ((_hc0[2]) * (_hc0[2]))*_t2 + 0.6e1*_hc0[2]*_hc1[3]*_t1 + _hc0[4]*_hc1[1];
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {

  const double _t1 = xc_powr(n_s, -4, 3);
  const double _t2 = xc_powr(sigma_ss, 1, 2);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (0.1e1 / (M_CBRTPI));
  const double _t5 = _t3*_t4;
  const double _t6 = -p->dens_threshold + n_s <= 0;
#if _KMAX >= 1
  const double _t8 = (0.1e1 / _t2);
  const double _t12 = xc_powr(n_s, -7, 3);
#endif
#if _KMAX >= 2
  const double _t17 = xc_powr(sigma_ss, 3, 2);
  const double _t18 = (0.1e1 / _t17);
  const double _t19 = xc_powr(n_s, -8, 3);
  const double _t20 = (0.1e1 / sigma_ss);
  const double _t22 = xc_powr(n_s, -11, 3);
  const double _t28 = xc_powr(n_s, -14, 3);
  const double _t30 = xc_powr(n_s, -10, 3);
#endif
#if _KMAX >= 3
  const double _t37 = xc_powr(sigma_ss, -5, 2);
  const double _t38 = (0.3e1 / 0.8e1)*_t37;
  const double _t39 = (sigma_ss * sigma_ss);
  const double _t40 = (0.1e1 / _t39);
  const double _t42 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t43 = _t18*_t42;
  const double _t45 = xc_powi(n_s, -5);
  const double _t50 = xc_powi(n_s, -6);
  const double _t51 = (0.8e1 / 0.9e1)*_t50;
  const double _t53 = (0.1e1 / 0.72e2)*_t8;
  const double _t56 = xc_powr(n_s, -17, 3);
  const double _t59 = xc_powr(n_s, -13, 3);
  const double _t61 = xc_powi(n_s, -7);
  const double _t67 = (0.1e1 / 0.9e1)*_t45;
#endif
#if _KMAX >= 4
  const double _t69 = xc_powr(n_s, -16, 3);
  const double _t70 = xc_powr(n_s, -19, 3);
  const double _t72 = (0.1e1 / 0.6e1)*_t20;
  const double _t74 = xc_powr(n_s, -22, 3);
  const double _t75 = (0.4e1 / 0.9e1)*_t74;
  const double _t76 = (0.19e2 / 0.9e1)*_t50;
  const double _t78 = xc_powr(n_s, -25, 3);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t6)) XC_CAT(gg99_f_k, _KMAX)(p, _t1*_t2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t6)) XC_CAT(lda_x_spin_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t5/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc1);
  const double _t7 = my_piecewise3(_t6, 0, _hc0[0]*_hc1[0]);
#if _KMAX >= 1
  const double _t9 = _hc0[1]*_hc1[0];
  const double _t10 = _t1*_t9;
  const double _t11 = my_piecewise3(_t6, 0, (0.1e1 / 0.2e1)*_t10*_t8);
  const double _t13 = _t12*_t9;
  const double _t14 = _hc1[2]*_t5;
  const double _t15 = _hc0[0]*_t14;
  const double _t16 = my_piecewise3(_t6, 0, -0.1e1 / 0.6e1*_t1*_t15 - 0.4e1 / 0.3e1*_t13*_t2);
#endif
#if _KMAX >= 2
  const double _t21 = my_piecewise3(_t6, 0, (0.1e1 / 0.4e1)*_hc0[2]*_hc1[0]*_t19*_t20 - 0.1e1 / 0.4e1*_t10*_t18);
  const double _t23 = _hc0[2]*_hc1[0];
  const double _t24 = _t22*_t23;
  const double _t25 = _hc0[1]*_t14;
  const double _t26 = _t19*_t25;
  const double _t27 = my_piecewise3(_t6, 0, -0.2e1 / 0.3e1*_t13*_t8 - 0.2e1 / 0.3e1*_t24 - 0.1e1 / 0.12e2*_t26*_t8);
  const double _t29 = _t23*_t28;
  const double _t31 = _t30*_t9;
  const double _t32 = (0.2e1 / 0.9e1)*_hc0[0];
  const double _t33 = (0.1e1 / 0.36e2)*_hc0[0];
  const double _t34 = xc_powr(0.6e1, 2, 3)*_hc1[5]/(M_CBRTPI * M_CBRTPI);
  const double _t35 = _t22*_t25;
  const double _t36 = my_piecewise3(_t6, 0, _t12*_t14*_t32 + _t19*_t33*_t34 + (0.28e2 / 0.9e1)*_t2*_t31 + (0.4e1 / 0.9e1)*_t2*_t35 + (0.16e2 / 0.9e1)*_t29*sigma_ss);
#endif
#if _KMAX >= 3
  const double _t41 = _hc0[3]*_hc1[0];
  const double _t44 = my_piecewise3(_t6, 0, _t10*_t38 - 0.3e1 / 0.8e1*_t19*_t23*_t40 + (0.1e1 / 0.8e1)*_t41*_t43);
  const double _t46 = _t41*_t8;
  const double _t47 = _hc0[2]*_t14;
  const double _t48 = my_piecewise3(_t6, 0, (0.1e1 / 0.3e1)*_hc0[1]*_hc1[0]*_t12*_t18 + (0.1e1 / 0.24e2)*_hc0[1]*_hc1[2]*_t18*_t19*_t3*_t4 - 0.1e1 / 0.3e1*_t20*_t24 - 0.1e1 / 0.24e2*_t20*_t42*_t47 - 0.1e1 / 0.3e1*_t45*_t46);
  const double _t49 = _t2*_t41;
  const double _t52 = _t45*_t47;
  const double _t54 = _hc0[1]*_t34;
  const double _t55 = my_piecewise3(_t6, 0, (0.10e2 / 0.3e1)*_t29 + (0.14e2 / 0.9e1)*_t31*_t8 + (0.1e1 / 0.3e1)*_t35*_t8 + _t42*_t53*_t54 + _t49*_t51 + (0.2e1 / 0.9e1)*_t52);
  const double _t57 = _t23*_t56;
  const double _t58 = _hc1[9]/M_PI;
  const double _t60 = _t59*_t9;
  const double _t62 = _t17*_t41;
  const double _t63 = _hc0[0]*_t34;
  const double _t64 = _t47*sigma_ss;
  const double _t65 = _t25*_t28;
  const double _t66 = _t2*_t54;
  const double _t68 = my_piecewise3(_t6, 0, -0.14e2 / 0.27e2*_t15*_t30 - 0.280e3 / 0.27e2*_t2*_t60 - 0.22e2 / 0.9e1*_t2*_t65 - 0.1e1 / 0.9e1*_t22*_t63 - _t33*_t42*_t58 - _t51*_t64 - 0.112e3 / 0.9e1*_t57*sigma_ss - 0.64e2 / 0.27e2*_t61*_t62 - _t66*_t67);
#endif
#if _KMAX >= 4
  const double _t71 = _hc0[4]*_hc1[0];
  const double _t73 = _hc0[3]*_t14;
  const double _t77 = _hc0[2]*_t34;
  const double _t79 = _hc0[1]*_t58;
#endif

  const double f = my_piecewise3(_t6, 0, _t7*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t6, 0, _t11*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t6, 0, _t16*n_s + _t7);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t6, 0, _t21*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t6, 0, _t11 + _t27*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t6, 0, 0.2e1*_t16 + _t36*n_s);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t6, 0, _t44*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t6, 0, _t21 + _t48*n_s);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t6, 0, 0.2e1*_t27 + _t55*n_s);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t6, 0, 0.3e1*_t36 + _t68*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t6, 0, n_s*my_piecewise3(_t6, 0, (0.15e2 / 0.16e2)*_hc0[2]*_hc1[0]*_t19/(sigma_ss * sigma_ss * sigma_ss) + (0.1e1 / 0.16e2)*_hc0[4]*_hc1[0]*_t40*_t69 - 0.15e2 / 0.16e2*_t10/xc_powr(sigma_ss, 7, 2) - _t38*_t41*_t42));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t6, 0, _t44 + n_s*my_piecewise3(_t6, 0, (0.1e1 / 0.2e1)*_hc0[2]*_hc1[0]*_t22*_t40 + (0.1e1 / 0.16e2)*_hc0[2]*_hc1[2]*_t3*_t4*_t40*_t42 - 0.1e1 / 0.2e1*_t13*_t37 - 0.1e1 / 0.48e2*_t18*_t69*_t73 - 0.1e1 / 0.16e2*_t26*_t37 - _t70*_t71*_t72));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t6, 0, 0.2e1*_t48 + n_s*my_piecewise3(_t6, 0, -0.7e1 / 0.9e1*_t18*_t31 - 0.1e1 / 0.6e1*_t18*_t35 + (0.7e1 / 0.9e1)*_t20*_t29 + (0.1e1 / 0.144e3)*_t20*_t69*_t77 - 0.1e1 / 0.144e3*_t43*_t54 + _t46*_t76 + _t52*_t72 + (0.1e1 / 0.9e1)*_t70*_t73*_t8 + _t71*_t75));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t6, 0, 0.3e1*_t55 + n_s*my_piecewise3(_t6, 0, -_t2*_t73*_t75 - _t47*_t76 - 0.88e2 / 0.9e1*_t49*_t61 - _t53*_t69*_t79 - _t54*_t67*_t8 - 0.476e3 / 0.27e2*_t57 - 0.140e3 / 0.27e2*_t60*_t8 - 0.40e2 / 0.27e2*_t65*_t8 - 0.1e1 / 0.18e2*_t70*_t77 - 0.32e2 / 0.27e2*_t71*_t78*sigma_ss));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t6, 0, 0.4e1*_t68 + n_s*my_piecewise3(_t6, 0, (0.1e1 / 0.216e3)*_hc0[0]*_hc1[14]*_t3*_t69/(M_PI * M_CBRTPI) + (0.140e3 / 0.81e2)*_t15*_t59 + (0.128e3 / 0.81e2)*_t17*_t73*_t78 + (0.1120e4 / 0.81e2)*_t2*_t25*_t56 + (0.3640e4 / 0.81e2)*_t2*_t69*_t9 + (0.4e1 / 0.27e2)*_t2*_t70*_t79 + (0.6832e4 / 0.81e2)*_t23*sigma_ss/xc_powr(n_s, 20, 3) + (0.40e2 / 0.81e2)*_t28*_t63 + _t32*_t45*_t58 + (0.256e3 / 0.81e2)*_t39*_t71/xc_powr(n_s, 28, 3) + (0.10e2 / 0.9e1)*_t50*_t66 + (0.32e2 / 0.3e1)*_t61*_t64 + (0.896e3 / 0.27e2)*_t62/xc_powi(n_s, 8) + (0.8e1 / 0.27e2)*_t74*_t77*sigma_ss));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(xchan_k, _KMAX)(p, (0.1e1 / 0.2e1)*na, (0.1e1 / 0.4e1)*gaa, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[2];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[5];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[4];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[3];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[9];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[8];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[7];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[6];
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
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[10];
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
  const double dF_dna = _hc0[2];
  const double dF_dnb = _hc1[2];
  const double dF_dgaa = _hc0[1];
  const double dF_dgbb = _hc1[1];
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
  const double d2F_dgaa2 = _hc0[3];
  const double d2F_dgbb2 = _hc1[3];
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
  const double d3F_dgaa3 = _hc0[6];
  const double d3F_dgbb3 = _hc1[6];
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
  const double d4F_dgaa4 = _hc0[10];
  const double d4F_dgbb4 = _hc1[10];
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