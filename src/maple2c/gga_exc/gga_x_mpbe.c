/*
  Generated from python/gga_exc/gga_x_mpbe.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_mpbe
*/

#ifndef _GGA_X_MPBE_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_MPBE_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_MPBE_HELPER_BODIES
#include "gga_x_mpbe.c"
#undef _GGA_X_MPBE_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_MPBE_HELPER_BODIES
#include "gga_x_mpbe.c"
#undef _GGA_X_MPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_MPBE_HELPER_BODIES
#include "gga_x_mpbe.c"
#undef _GGA_X_MPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_MPBE_HELPER_BODIES
#include "gga_x_mpbe.c"
#undef _GGA_X_MPBE_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_MPBE_HELPER_BODIES
#include "gga_x_mpbe.c"
#undef _GGA_X_MPBE_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_mpbe.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_MPBE_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {
  const gga_x_mpbe_params *params = (const gga_x_mpbe_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = -p->dens_threshold + n_s <= 0;
  const double _t6 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t7 = xc_powi(n_s, -8);
  const double _t8 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t9 = (0.1e1 / 0.24e2)*params->a;
  const double _t10 = xc_powr(n_s, -8, 3);
  const double _t11 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t12 = _t1*_t11;
  const double _t13 = _t12*sigma_ss;
  const double _t14 = _t10*_t13;
  const double _t15 = _t14*_t9 + 0.1e1;
  const double _t16 = (0.1e1 / (_t15 * _t15 * _t15));
  const double _t17 = _t16*_t8;
  const double _t18 = _t17*params->c3;
  const double _t19 = _t18*_t7;
  const double _t20 = (0.1e1 / _t15);
  const double _t21 = _t20*params->c1;
  const double _t22 = (sigma_ss * sigma_ss);
  const double _t23 = _t22*params->c2;
  const double _t24 = xc_powr(n_s, -16, 3);
  const double _t25 = xc_powr(0.6e1, 2, 3);
  const double _t26 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t27 = (0.1e1 / (_t15 * _t15));
  const double _t28 = _t25*_t26*_t27;
  const double _t29 = _t24*_t28;
  const double _t30 = (0.1e1 / 0.576e3)*_t29;
  const double _t31 = (0.1e1 / 0.24e2)*_t14*_t21 + (0.1e1 / 0.2304e4)*_t19*_t6 + _t23*_t30 + 0.1e1;
#if _KMAX >= 1
  const double _t33 = _t17*_t7;
  const double _t34 = params->a*params->c2;
  const double _t35 = _t33*_t34;
  const double _t36 = params->a*sigma_ss;
  const double _t37 = _t36*params->c1;
  const double _t38 = _t6*params->c3;
  const double _t39 = xc_powr(n_s, -32, 3);
  const double _t40 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t41 = (0.1e1 / (_t15 * _t15 * _t15 * _t15));
  const double _t42 = _t40*_t41;
  const double _t43 = _t39*_t42;
  const double _t44 = _t1*_t43;
  const double _t45 = _t44*params->a;
  const double _t46 = (0.1e1 / 0.24e2)*_t1*_t10*_t11*_t20*params->c1 + (0.1e1 / 0.768e3)*_t16*_t22*_t7*_t8*params->c3 - 0.1e1 / 0.1152e4*_t22*_t35 + (0.1e1 / 0.288e3)*_t24*_t25*_t26*_t27*params->c2*sigma_ss - _t30*_t37 - 0.1e1 / 0.18432e5*_t38*_t45;
  const double _t48 = xc_powr(n_s, -4, 3);
  const double _t52 = xc_powi(n_s, -9);
  const double _t53 = _t18*_t52;
  const double _t54 = xc_powr(n_s, -11, 3);
  const double _t55 = (0.1e1 / 0.9e1)*_t54;
  const double _t56 = _t13*_t21;
  const double _t57 = _t17*_t52;
  const double _t58 = _t34*_t57;
  const double _t59 = xc_powr(n_s, -19, 3);
  const double _t60 = _t28*params->c2;
  const double _t61 = _t59*_t60;
  const double _t62 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t63 = _t62*params->c3;
  const double _t64 = _t1*_t63;
  const double _t65 = xc_powr(n_s, -35, 3);
  const double _t66 = _t42*_t65;
  const double _t67 = _t66*params->a;
  const double _t68 = params->a*params->c1;
  const double _t69 = _t28*_t68;
  const double _t70 = _t59*_t69;
  const double _t71 = -0.1e1 / 0.108e3*_t22*_t61 + (0.1e1 / 0.216e3)*_t22*_t70 - 0.1e1 / 0.288e3*_t53*_t6 - _t55*_t56 + (0.1e1 / 0.432e3)*_t58*_t6 + (0.1e1 / 0.6912e4)*_t64*_t67;
#endif
#if _KMAX >= 2
  const double _t73 = (0.1e1 / 0.288e3)*params->c2;
  const double _t74 = ((params->a) * (params->a));
  const double _t75 = _t74*params->c1;
  const double _t76 = _t22*params->c3;
  const double _t77 = _t23*_t74;
  const double _t78 = xc_powr(n_s, -40, 3);
  const double _t79 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t80 = xc_powi(_t15, -5);
  const double _t81 = _t25*_t79*_t80;
  const double _t82 = _t74*_t81;
  const double _t83 = _t78*_t82;
  const double _t84 = (0.1e1 / 0.384e3)*_t19*sigma_ss - 0.1e1 / 0.288e3*_t29*_t68 + _t29*_t73 - _t33*_t36*_t73 + (0.1e1 / 0.1152e4)*_t33*_t75*sigma_ss + (0.1e1 / 0.110592e6)*_t38*_t83 + (0.1e1 / 0.9216e4)*_t44*_t77 - 0.1e1 / 0.3072e4*_t45*_t76;
  const double _t86 = _t12*_t21;
  const double _t87 = (0.1e1 / 0.54e2)*_t61;
  const double _t88 = _t57*_t75;
  const double _t89 = (0.1e1 / 0.3456e4)*_t66;
  const double _t90 = _t1*_t74*params->c2;
  const double _t91 = _t6*_t90;
  const double _t92 = xc_powr(n_s, -43, 3);
  const double _t93 = _t82*_t92;
  const double _t94 = (0.7e1 / 0.6912e4)*_t1*_t40*_t41*_t6*_t65*params->a*params->c3 + (0.5e1 / 0.432e3)*_t16*_t22*_t52*_t8*params->a*params->c2 - 0.1e1 / 0.96e2*_t22*_t53 - 0.1e1 / 0.432e3*_t22*_t88 + (0.1e1 / 0.72e2)*_t25*_t26*_t27*_t59*params->a*params->c1*sigma_ss - _t55*_t86 - 0.1e1 / 0.41472e5*_t63*_t93 - _t87*sigma_ss - _t89*_t91;
  const double _t96 = (0.2e1 / 0.9e1)*_t31;
  const double _t97 = xc_powr(n_s, -7, 3);
  const double _t99 = (0.1e1 / 0.36e2)*_t31;
  const double _t100 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t104 = xc_powi(n_s, -10);
  const double _t105 = _t104*_t18;
  const double _t106 = xc_powr(n_s, -14, 3);
  const double _t107 = (0.11e2 / 0.27e2)*_t106;
  const double _t108 = _t104*_t17;
  const double _t109 = _t108*_t6;
  const double _t110 = xc_powr(n_s, -22, 3);
  const double _t111 = _t110*_t60;
  const double _t112 = _t42/xc_powr(n_s, 38, 3);
  const double _t113 = _t112*params->a;
  const double _t114 = _t22*params->c1;
  const double _t115 = (0.1e1 / 0.1296e4)*_t112;
  const double _t116 = _t62*_t90;
  const double _t117 = xc_powi(sigma_ss, 5);
  const double _t118 = _t117*params->c3;
  const double _t119 = xc_powr(n_s, -46, 3);
  const double _t120 = _t119*_t82;
  const double _t121 = (0.1e1 / 0.32e2)*_t105*_t6 + _t107*_t56 - 0.43e2 / 0.1296e4*_t109*_t34 + (0.1e1 / 0.162e3)*_t109*_t75 - _t110*_t114*_t28*_t9 + (0.19e2 / 0.324e3)*_t111*_t22 - 0.59e2 / 0.20736e5*_t113*_t64 + _t115*_t116 + (0.1e1 / 0.15552e5)*_t118*_t120;
#endif
#if _KMAX >= 3
  const double _t123 = _t1*params->c3;
  const double _t124 = ((params->a) * (params->a) * (params->a));
  const double _t125 = xc_powi(M_PI, -8);
  const double _t126 = xc_powi(_t15, -6);
  const double _t127 = _t125*_t126;
  const double _t128 = _t127/xc_powi(n_s, 16);
  const double _t129 = _t124*_t128;
  const double _t130 = _t124*params->c1;
  const double _t131 = _t130*_t44;
  const double _t132 = _t124*_t81;
  const double _t133 = _t132*_t78;
  const double _t134 = (0.1e1 / 0.1536e4)*_t1*_t39*_t40*_t41*_t74*params->c2*sigma_ss - 0.1e1 / 0.1024e4*_t123*_t36*_t43 - 0.5e1 / 0.442368e6*_t129*_t38 - 0.1e1 / 0.9216e4*_t131*sigma_ss - 0.1e1 / 0.55296e5*_t133*_t23 + (0.1e1 / 0.384e3)*_t16*_t7*_t74*_t8*params->c1 + (0.1e1 / 0.384e3)*_t16*_t7*_t8*params->c3 + (0.1e1 / 0.12288e5)*_t22*_t25*_t74*_t78*_t79*_t80*params->c3 - 0.1e1 / 0.192e3*_t35;
  const double _t136 = (0.1e1 / 0.48e2)*_t53;
  const double _t137 = xc_powi(n_s, -17);
  const double _t138 = _t127*_t137;
  const double _t139 = _t1*_t130;
  const double _t140 = _t139*_t22;
  const double _t141 = (0.1e1 / 0.20736e5)*_t92;
  const double _t142 = _t132*params->c2;
  const double _t143 = _t142*_t6;
  const double _t144 = -0.1e1 / 0.432e3*_t1*_t66*_t77 + (0.5e1 / 0.1152e4)*_t1*_t67*_t76 + (0.5e1 / 0.165888e6)*_t124*_t138*_t63 - _t136*sigma_ss + _t140*_t89 + _t141*_t143 - 0.11e2 / 0.41472e5*_t38*_t93 + (0.7e1 / 0.216e3)*_t58*sigma_ss + (0.1e1 / 0.54e2)*_t70 - _t87 - 0.5e1 / 0.432e3*_t88*sigma_ss;
  const double _t147 = (0.1e1 / 0.36e2)*_t46;
  const double _t148 = (0.19e2 / 0.162e3)*_t111;
  const double _t149 = _t108*_t22;
  const double _t150 = _t127/xc_powi(n_s, 18);
  const double _t151 = _t124*_t150;
  const double _t152 = _t1*_t38;
  const double _t153 = (0.25e2 / 0.3456e4)*_t112;
  const double _t154 = (0.1e1 / 0.7776e4)*_t119;
  const double _t155 = (0.3e1 / 0.32e2)*_t105*_t22 + _t107*_t86 - 0.65e2 / 0.648e3*_t110*_t28*_t37 - 0.317e3 / 0.20736e5*_t113*_t152 - _t115*_t139*_t6 - 0.5e1 / 0.62208e5*_t118*_t151 + (0.11e2 / 0.13824e5)*_t120*_t63 - _t142*_t154*_t62 + _t148*sigma_ss - 0.167e3 / 0.1296e4*_t149*_t34 + (0.17e2 / 0.432e3)*_t149*_t75 + _t153*_t91;
  const double _t157 = (0.1e1 / M_PI);
  const double _t163 = xc_powi(n_s, -11);
  const double _t164 = _t163*_t18;
  const double _t165 = (0.154e3 / 0.81e2)/xc_powr(n_s, 17, 3);
  const double _t166 = xc_powr(n_s, -25, 3);
  const double _t167 = _t166*_t60;
  const double _t168 = xc_powi(n_s, -19);
  const double _t169 = xc_powi(sigma_ss, 6);
  const double _t170 = _t163*_t17;
  const double _t171 = xc_powr(n_s, -41, 3);
  const double _t172 = _t171*_t42;
  const double _t173 = xc_powr(n_s, -49, 3);
  const double _t174 = _t173*_t82;
  const double _t175 = (0.1e1 / 0.486e3)*_t1*_t124*_t171*_t40*_t41*_t62*params->c1 + (0.1445e4 / 0.31104e5)*_t1*_t171*_t40*_t41*_t62*params->a*params->c3 - 0.1e1 / 0.48e2*_t116*_t172 + (0.1e1 / 0.2916e4)*_t117*_t124*_t173*_t25*_t79*_t80*params->c2 - 0.35e2 / 0.15552e5*_t118*_t174 + (0.5e1 / 0.23328e5)*_t124*_t125*_t126*_t168*_t169*params->c3 + (0.797e3 / 0.1944e4)*_t16*_t163*_t6*_t8*params->a*params->c2 - 0.5e1 / 0.16e2*_t164*_t6 - _t165*_t56 + (0.341e3 / 0.972e3)*_t166*_t22*_t25*_t26*_t27*params->a*params->c1 - 0.209e3 / 0.486e3*_t167*_t22 - 0.19e2 / 0.162e3*_t170*_t6*_t75;
#endif
#if _KMAX >= 4
  const double _t177 = (0.1e1 / 0.768e3)*_t43;
  const double _t178 = ((params->a) * (params->a) * (params->a) * (params->a));
  const double _t179 = _t178*_t81;
  const double _t180 = _t179*params->c1;
  const double _t181 = _t178/((M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI)*xc_powi(_t15, 7));
  const double _t182 = _t178*params->c2;
  const double _t183 = _t108*sigma_ss;
  const double _t184 = _t1*_t181;
  const double _t185 = _t169*params->c3;
  const double _t186 = _t6/xc_powi(n_s, 12);
  const double _t187 = _t17*_t186;
  const double _t188 = _t22/xc_powr(n_s, 28, 3);
  const double _t189 = _t127/xc_powi(n_s, 20);
  const double _t190 = _t42/xc_powr(n_s, 44, 3);
  const double _t191 = xc_powr(n_s, -52, 3);
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t32 = my_piecewise3(_t5, 0, _hc0[0]*_t31);
#if _KMAX >= 1
  const double _t47 = my_piecewise3(_t5, 0, _hc0[0]*_t46);
  const double _t49 = _hc0[2]*_t3;
  const double _t50 = _t48*_t49;
  const double _t51 = (0.1e1 / 0.6e1)*_t50;
  const double _t72 = my_piecewise3(_t5, 0, _hc0[0]*_t71 - _t31*_t51);
#endif
#if _KMAX >= 2
  const double _t85 = my_piecewise3(_t5, 0, _hc0[0]*_t84);
  const double _t95 = my_piecewise3(_t5, 0, _hc0[0]*_t94 - _t46*_t51);
  const double _t98 = _t49*_t97;
  const double _t101 = _hc0[5]*_t100*_t25;
  const double _t102 = _t10*_t101;
  const double _t103 = (0.1e1 / 0.3e1)*_t50;
  const double _t122 = my_piecewise3(_t5, 0, _hc0[0]*_t121 + _t102*_t99 - _t103*_t71 + _t96*_t98);
#endif
#if _KMAX >= 3
  const double _t135 = my_piecewise3(_t5, 0, _hc0[0]*_t134);
  const double _t145 = my_piecewise3(_t5, 0, _hc0[0]*_t144 - _t51*_t84);
  const double _t146 = (0.2e1 / 0.9e1)*_t98;
  const double _t156 = my_piecewise3(_t5, 0, _hc0[0]*_t155 + _t102*_t147 - _t103*_t94 + _t146*_t46);
  const double _t158 = _hc0[9]*_t157/(n_s * n_s * n_s * n_s);
  const double _t159 = _t49/xc_powr(n_s, 10, 3);
  const double _t160 = (0.14e2 / 0.27e2)*_t159;
  const double _t161 = _t101*_t55;
  const double _t162 = _hc0[2]*_t4*_t48;
  const double _t176 = my_piecewise3(_t5, 0, _hc0[0]*_t175 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t71*_t97 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t100*_t25*_t71 - _t121*_t162 - _t158*_t99 - _t160*_t31 - _t161*_t31);
#endif

  const double f = my_piecewise3(_t5, 0, _t32*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t47*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t32 + _t72*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t85*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t47 + _t95*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, _t122*n_s + 0.2e1*_t72);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t135*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t145*n_s + _t85);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, _t156*n_s + 0.2e1*_t95);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, 0.3e1*_t122 + _t176*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t123*_t177*params->a + (0.5e1 / 0.221184e6)*_t128*_t178*_t23 - 0.5e1 / 0.36864e5*_t129*_t76 - 0.1e1 / 0.2304e4*_t131 - 0.1e1 / 0.6912e4*_t133*params->c2*sigma_ss + (0.5e1 / 0.1769472e7)*_t152*_t181/xc_powr(n_s, 56, 3) + _t177*_t90 + (0.1e1 / 0.55296e5)*_t180*_t78*sigma_ss + (0.1e1 / 0.3072e4)*_t83*params->c3*sigma_ss)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t135 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.7e1 / 0.3456e4)*_t1*_t124*_t40*_t41*_t65*params->c1*sigma_ss + (0.13e2 / 0.1152e4)*_t1*_t40*_t41*_t65*params->a*params->c3*sigma_ss - _t114*_t141*_t179 + (0.25e2 / 0.55296e5)*_t124*_t125*_t126*_t137*_t6*params->c3 + (0.11e2 / 0.20736e5)*_t124*_t22*_t25*_t79*_t80*_t92*params->c2 - _t136 - 0.5e1 / 0.82944e5*_t138*_t182*_t6 + (0.1e1 / 0.24e2)*_t16*_t52*_t8*params->a*params->c2 - 0.5e1 / 0.663552e6*_t181*_t64/xc_powr(n_s, 59, 3) - 0.5e1 / 0.576e3*_t66*_t90*sigma_ss - 0.7e1 / 0.4608e4*_t76*_t93 - 0.1e1 / 0.48e2*_t88) - _t134*_t51));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t145 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.49e2 / 0.1296e4)*_t1*_t112*_t77 - 0.199e3 / 0.3456e4*_t1*_t113*_t76 + (0.3e1 / 0.16e2)*_t105*sigma_ss - 0.19e2 / 0.162e3*_t110*_t69 + (0.5e1 / 0.248832e6)*_t118*_t184/xc_powr(n_s, 62, 3) - 0.107e3 / 0.62208e5*_t119*_t143 + (0.713e3 / 0.124416e6)*_t120*_t38 - _t140*_t153 + _t148 + (0.5e1 / 0.31104e5)*_t150*_t182*_t62 - 0.695e3 / 0.497664e6*_t151*_t63 + _t154*_t180*_t6 - 0.205e3 / 0.648e3*_t183*_t34 + (0.167e3 / 0.1296e4)*_t183*_t75) + (0.1e1 / 0.36e2)*_t102*_t84 - _t103*_t144 + _t146*_t84));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t156 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.89e2 / 0.3888e4)*_t1*_t124*_t171*_t40*_t41*_t6*params->c1 + (0.6995e4 / 0.31104e5)*_t1*_t171*_t40*_t41*_t6*params->a*params->c3 + (0.85e2 / 0.20736e5)*_t117*_t124*_t125*_t126*_t168*params->c3 - 0.5e1 / 0.11664e5*_t117*_t127*_t168*_t182 + (0.121e3 / 0.23328e5)*_t124*_t173*_t25*_t62*_t79*_t80*params->c2 + (0.2809e4 / 0.1944e4)*_t16*_t163*_t22*_t8*params->a*params->c2 - 0.15e2 / 0.16e2*_t164*_t22 - _t165*_t86 + (0.253e3 / 0.324e3)*_t166*_t25*_t26*_t27*params->a*params->c1*sigma_ss - 0.209e3 / 0.243e3*_t167*sigma_ss - 0.1025e4 / 0.1944e4*_t170*_t22*_t75 - 0.2093e4 / 0.15552e5*_t172*_t91 - 0.1e1 / 0.2916e4*_t173*_t180*_t62 - 0.3545e4 / 0.186624e6*_t174*_t63 - 0.5e1 / 0.93312e5*_t184*_t185/xc_powr(n_s, 65, 3)) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t94*_t97 + (0.1e1 / 0.12e2)*_hc0[5]*_t10*_t100*_t25*_t94 - _t147*_t158 - _t155*_t162 - _t160*_t46 - _t161*_t46));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t176 + n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.4915e4 / 0.11664e5)*_t116*_t190 - 0.65e2 / 0.4374e4*_t117*_t142*_t191 + (0.2e1 / 0.2187e4)*_t117*_t180*_t191 + (0.8035e4 / 0.139968e6)*_t118*_t191*_t82 + (0.5e1 / 0.34992e5)*_t123*_t181*xc_powi(sigma_ss, 7)/xc_powr(n_s, 68, 3) - 0.5e1 / 0.432e3*_t124*_t185*_t189 - 0.49e2 / 0.729e3*_t139*_t190*_t62 + (0.5e1 / 0.4374e4)*_t169*_t182*_t189 + (0.55e2 / 0.16e2)*_t18*_t186 - 0.29645e5 / 0.5832e4*_t187*_t34 + (0.2563e4 / 0.1458e4)*_t187*_t75 + (0.5225e4 / 0.1458e4)*_t188*_t60 - 0.3047e4 / 0.972e3*_t188*_t69 - 0.68965e5 / 0.93312e5*_t190*_t64*params->a + (0.2618e4 / 0.243e3)*_t56/xc_powr(n_s, 20, 3)) + (0.1e1 / 0.216e3)*_hc0[14]*_t12*_t24*_t31 + _hc0[9]*_t157*_t96/xc_powi(n_s, 5) + (0.40e2 / 0.81e2)*_t101*_t106*_t31 - 0.4e1 / 0.9e1*_t101*_t54*_t71 + (0.1e1 / 0.6e1)*_t102*_t121 + (0.4e1 / 0.3e1)*_t121*_t98 - 0.1e1 / 0.9e1*_t158*_t71 - 0.56e2 / 0.27e2*_t159*_t71 - 0.2e1 / 0.3e1*_t175*_t50 + (0.140e3 / 0.81e2)*_t31*_t49/xc_powr(n_s, 13, 3)));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_mpbe_params *params = (const gga_x_mpbe_params *)(p->params);
  (void)params;
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