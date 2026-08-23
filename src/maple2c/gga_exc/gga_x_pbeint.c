/*
  Generated from python/gga_exc/gga_x_pbeint.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_pbeint
*/

#ifndef _GGA_X_PBEINT_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_PBEINT_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_PBEINT_HELPER_BODIES
#include "gga_x_pbeint.c"
#undef _GGA_X_PBEINT_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_PBEINT_HELPER_BODIES
#include "gga_x_pbeint.c"
#undef _GGA_X_PBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_PBEINT_HELPER_BODIES
#include "gga_x_pbeint.c"
#undef _GGA_X_PBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_PBEINT_HELPER_BODIES
#include "gga_x_pbeint.c"
#undef _GGA_X_PBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_PBEINT_HELPER_BODIES
#include "gga_x_pbeint.c"
#undef _GGA_X_PBEINT_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_pbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_PBEINT_HELPER_BODIES)

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
  const gga_x_pbeint_params *params = (const gga_x_pbeint_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = -p->dens_threshold + n_s <= 0;
  const double _t6 = xc_powr(n_s, -8, 3);
  const double _t7 = (0.1e1 / (M_PI * M_CBRTPI));
  const double _t8 = _t1*_t7;
  const double _t9 = _t6*_t8;
  const double _t10 = (0.1e1 / 0.24e2)*_t9;
  const double _t11 = _t10*sigma_ss;
  const double _t12 = _t11*params->alpha;
  const double _t13 = -params->muGE + params->muPBE;
  const double _t14 = _t12 + 0.1e1;
  const double _t15 = _t13/_t14;
  const double _t16 = _t12*_t15 + params->muGE;
  const double _t17 = _t16*_t9;
  const double _t18 = (0.1e1 / 0.24e2)*_t17;
  const double _t19 = _t18*sigma_ss;
  const double _t20 = _t19 + params->kappa;
  const double _t21 = params->kappa/_t20;
  const double _t22 = _t19*_t21 + 0.1e1;
#if _KMAX >= 1
  const double _t24 = _t15*params->alpha;
  const double _t25 = xc_powr(n_s, -16, 3);
  const double _t26 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t27 = (0.1e1 / (_t14 * _t14));
  const double _t28 = ((params->alpha) * (params->alpha));
  const double _t29 = xc_powr(0.6e1, 2, 3);
  const double _t30 = _t13*_t29;
  const double _t31 = _t26*_t27*_t28*_t30;
  const double _t32 = _t25*_t31;
  const double _t33 = _t10*_t24 - 0.1e1 / 0.576e3*_t32*sigma_ss;
  const double _t34 = _t33*_t9;
  const double _t35 = _t34*sigma_ss;
  const double _t36 = (0.1e1 / 0.24e2)*_t35;
  const double _t37 = -_t18 - _t36;
  const double _t38 = params->kappa/(_t20 * _t20);
  const double _t39 = _t37*_t38;
  const double _t40 = _t18*_t21 + _t19*_t39 + _t21*_t36;
  const double _t42 = xc_powr(n_s, -4, 3);
  const double _t46 = xc_powr(n_s, -11, 3);
  const double _t47 = _t46*_t8;
  const double _t48 = _t16*_t47;
  const double _t49 = (0.1e1 / 0.9e1)*_t48;
  const double _t50 = _t49*sigma_ss;
  const double _t51 = (0.1e1 / 0.9e1)*_t47;
  const double _t52 = _t51*sigma_ss;
  const double _t53 = xc_powr(n_s, -19, 3);
  const double _t54 = (sigma_ss * sigma_ss);
  const double _t55 = (0.1e1 / 0.216e3)*_t13*_t26*_t27*_t28*_t29*_t53*_t54 - _t24*_t52;
  const double _t56 = _t10*_t55;
  const double _t57 = _t56*sigma_ss;
  const double _t58 = (0.1e1 / 0.9e1)*_t1*_t16*_t46*_t7*sigma_ss - _t57;
  const double _t59 = _t38*_t58;
  const double _t60 = _t19*_t59 - _t21*_t50 + _t21*_t57;
#endif
#if _KMAX >= 2
  const double _t62 = (0.1e1 / 0.12e2)*_t34;
  const double _t63 = _t13*((params->alpha) * (params->alpha) * (params->alpha))/((M_PI * M_PI * M_PI * M_PI)*(_t14 * _t14 * _t14));
  const double _t64 = _t63/xc_powi(n_s, 8);
  const double _t65 = -0.1e1 / 0.288e3*_t32 + (0.1e1 / 0.1152e4)*_t64*sigma_ss;
  const double _t66 = _t11*_t65;
  const double _t67 = (0.1e1 / 0.12e2)*_t17;
  const double _t68 = -_t62 - _t66;
  const double _t69 = _t38*_t68;
  const double _t70 = _t62*sigma_ss;
  const double _t71 = -_t67 - _t70;
  const double _t72 = params->kappa/(_t20 * _t20 * _t20);
  const double _t73 = _t71*_t72;
  const double _t74 = _t37*_t73;
  const double _t75 = _t19*_t69 + _t19*_t74 + _t21*_t62 + _t21*_t66 + _t39*_t67 + _t39*_t70;
  const double _t77 = _t33*sigma_ss;
  const double _t78 = _t63/xc_powi(n_s, 9);
  const double _t79 = (0.1e1 / 0.72e2)*_t13*_t26*_t27*_t28*_t29*_t53*sigma_ss - _t24*_t51 - 0.1e1 / 0.432e3*_t54*_t78;
  const double _t80 = _t11*_t79;
  const double _t81 = _t58*_t73;
  const double _t82 = (0.1e1 / 0.9e1)*_t1*_t16*_t46*_t7 + (0.1e1 / 0.9e1)*_t1*_t33*_t46*_t7*sigma_ss - _t56 - _t80;
  const double _t83 = _t38*_t82;
  const double _t84 = _t18*_t59 + _t19*_t81 + _t19*_t83 - _t21*_t49 - _t21*_t51*_t77 + _t21*_t56 + _t21*_t80 + _t36*_t59 - _t39*_t50 + _t39*_t57;
  const double _t86 = (0.2e1 / 0.9e1)*_t22;
  const double _t87 = xc_powr(n_s, -7, 3);
  const double _t89 = (0.1e1 / 0.36e2)*_t22;
  const double _t90 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t94 = xc_powr(n_s, -14, 3);
  const double _t95 = _t8*_t94;
  const double _t96 = _t16*_t95;
  const double _t97 = (0.11e2 / 0.27e2)*_t96;
  const double _t98 = _t97*sigma_ss;
  const double _t99 = (0.2e1 / 0.9e1)*_t47;
  const double _t100 = _t55*_t99;
  const double _t101 = _t100*sigma_ss;
  const double _t102 = (0.11e2 / 0.27e2)*sigma_ss;
  const double _t103 = _t102*_t95;
  const double _t104 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t105 = _t63/xc_powi(n_s, 10);
  const double _t106 = _t31/xc_powr(n_s, 22, 3);
  const double _t107 = _t103*_t24 + (0.1e1 / 0.162e3)*_t104*_t105 - 0.1e1 / 0.24e2*_t106*_t54;
  const double _t108 = _t10*_t107;
  const double _t109 = _t108*sigma_ss;
  const double _t110 = (0.2e1 / 0.9e1)*_t48;
  const double _t111 = _t110*sigma_ss;
  const double _t112 = (0.1e1 / 0.12e2)*_t9;
  const double _t113 = _t112*_t55;
  const double _t114 = _t113*sigma_ss;
  const double _t115 = (0.2e1 / 0.9e1)*_t1*_t46*_t55*_t7*sigma_ss - _t109 - _t98;
  const double _t116 = _t115*_t38;
  const double _t117 = (0.2e1 / 0.9e1)*_t1*_t16*_t46*_t7*sigma_ss - _t114;
  const double _t118 = _t58*_t72;
  const double _t119 = _t117*_t118;
  const double _t120 = -_t101*_t21 + _t109*_t21 - _t111*_t59 + _t114*_t59 + _t116*_t19 + _t119*_t19 + _t21*_t98;
#endif
#if _KMAX >= 3
  const double _t122 = _t65*_t9;
  const double _t123 = (0.1e1 / 0.8e1)*_t122;
  const double _t124 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t125 = (0.1e1 / (_t14 * _t14 * _t14 * _t14));
  const double _t126 = ((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha));
  const double _t127 = _t1*_t124*_t125*_t126*_t13;
  const double _t128 = _t127/xc_powr(n_s, 32, 3);
  const double _t129 = -0.1e1 / 0.9216e4*_t128*sigma_ss + (0.1e1 / 0.384e3)*_t64;
  const double _t130 = _t11*_t129;
  const double _t131 = (0.1e1 / 0.8e1)*_t17;
  const double _t132 = -_t123 - _t130;
  const double _t133 = _t132*_t38;
  const double _t134 = (0.1e1 / 0.4e1)*_t34;
  const double _t135 = _t123*sigma_ss;
  const double _t136 = (0.1e1 / 0.8e1)*_t35;
  const double _t137 = _t73*sigma_ss;
  const double _t138 = _t137*_t67;
  const double _t139 = (0.1e1 / 0.6e1)*_t34;
  const double _t140 = -0.1e1 / 0.12e2*_t122*sigma_ss - _t139;
  const double _t141 = _t140*_t72;
  const double _t142 = _t141*_t37;
  const double _t143 = -_t131 - _t136;
  const double _t144 = params->kappa/(_t20 * _t20 * _t20 * _t20);
  const double _t145 = _t143*_t144;
  const double _t146 = _t145*_t71;
  const double _t147 = _t146*_t37;
  const double _t148 = _t123*_t21 + _t130*_t21 + _t131*_t69 + _t131*_t74 + _t133*_t19 + _t134*_t39 + _t135*_t39 + _t136*_t69 + _t136*_t74 + _t138*_t68 + _t142*_t19 + _t147*_t19;
  const double _t150 = _t33*_t99;
  const double _t151 = _t112*_t79;
  const double _t152 = xc_powr(n_s, -35, 3);
  const double _t153 = (0.1e1 / 0.3456e4)*_t127*_t152*_t54 + (0.1e1 / 0.54e2)*_t31*_t53 - 0.5e1 / 0.432e3*_t78*sigma_ss;
  const double _t154 = _t11*_t153;
  const double _t155 = _t150*sigma_ss;
  const double _t156 = _t151*sigma_ss;
  const double _t157 = _t118*_t140;
  const double _t158 = _t146*_t58;
  const double _t159 = (0.2e1 / 0.9e1)*_t1*_t33*_t46*_t7 + (0.1e1 / 0.9e1)*_t1*_t46*_t65*_t7*sigma_ss - _t151 - _t154;
  const double _t160 = _t159*_t38;
  const double _t161 = _t67*_t82;
  const double _t162 = -_t110*_t39 + _t113*_t39 + _t137*_t161 - _t150*_t21 + _t151*_t21 + _t154*_t21 - _t155*_t39 + _t156*_t39 + _t157*_t19 + _t158*_t19 + _t160*_t19 - _t21*_t52*_t65 - _t50*_t69 - _t50*_t74 + _t57*_t69 + _t57*_t74 + _t59*_t62 + _t59*_t66 + _t67*_t81 + _t67*_t83 + _t70*_t81 + _t70*_t83;
  const double _t165 = (0.1e1 / 0.36e2)*_t40;
  const double _t166 = _t33*_t95;
  const double _t167 = _t102*_t166;
  const double _t168 = _t99*sigma_ss;
  const double _t169 = _t127/xc_powr(n_s, 38, 3);
  const double _t170 = -0.1e1 / 0.1296e4*_t104*_t169 + (0.17e2 / 0.432e3)*_t105*_t54 - 0.65e2 / 0.648e3*_t106*sigma_ss + (0.11e2 / 0.27e2)*_t24*_t95;
  const double _t171 = _t11*_t170;
  const double _t172 = _t115*_t73;
  const double _t173 = _t117*_t58;
  const double _t174 = _t145*_t173;
  const double _t175 = _t117*_t72;
  const double _t176 = _t175*_t82;
  const double _t177 = (0.2e1 / 0.9e1)*_t1*_t16*_t46*_t7 + (0.2e1 / 0.9e1)*_t1*_t33*_t46*_t7*sigma_ss - _t113 - _t156;
  const double _t178 = _t118*_t177;
  const double _t179 = (0.2e1 / 0.9e1)*_t1*_t46*_t55*_t7 + (0.2e1 / 0.9e1)*_t1*_t46*_t7*_t79*sigma_ss - _t108 - _t167 - _t171 - _t97;
  const double _t180 = _t179*_t38;
  const double _t181 = -_t100*_t21 - _t101*_t39 + _t108*_t21 + _t109*_t39 - _t110*_t59 - _t111*_t81 - _t111*_t83 + _t113*_t59 + _t114*_t81 + _t114*_t83 + _t116*_t18 + _t116*_t36 + _t119*_t18 + _t119*_t36 - _t155*_t59 + _t156*_t59 + _t167*_t21 - _t168*_t21*_t79 + _t171*_t21 + _t172*_t19 + _t174*_t19 + _t176*_t19 + _t178*_t19 + _t180*_t19 + _t21*_t97 + _t39*_t98;
  const double _t183 = (0.1e1 / M_PI);
  const double _t190 = _t16*_t8;
  const double _t191 = xc_powr(n_s, -17, 3);
  const double _t192 = (0.154e3 / 0.81e2)*_t191;
  const double _t193 = _t190*_t192;
  const double _t194 = _t193*sigma_ss;
  const double _t195 = (0.11e2 / 0.9e1)*_t95;
  const double _t196 = _t195*_t55;
  const double _t197 = _t196*sigma_ss;
  const double _t198 = (0.1e1 / 0.3e1)*_t47;
  const double _t199 = _t107*_t198;
  const double _t200 = _t199*sigma_ss;
  const double _t201 = _t192*_t8;
  const double _t202 = _t201*_t24;
  const double _t203 = _t63/xc_powi(n_s, 11);
  const double _t204 = xc_powr(n_s, -41, 3);
  const double _t205 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t206 = xc_powr(n_s, -25, 3);
  const double _t207 = (0.1e1 / 0.486e3)*_t1*_t124*_t125*_t126*_t13*_t204*_t205 - 0.19e2 / 0.162e3*_t104*_t203 + (0.341e3 / 0.972e3)*_t13*_t206*_t26*_t27*_t28*_t29*_t54 - _t202*sigma_ss;
  const double _t208 = _t10*_t207;
  const double _t209 = _t208*sigma_ss;
  const double _t210 = (0.11e2 / 0.9e1)*_t96;
  const double _t211 = _t210*sigma_ss;
  const double _t212 = _t55*sigma_ss;
  const double _t213 = (0.2e1 / 0.3e1)*_t47;
  const double _t214 = _t212*_t213;
  const double _t215 = (0.1e1 / 0.8e1)*_t9;
  const double _t216 = _t107*sigma_ss;
  const double _t217 = _t215*_t216;
  const double _t218 = (0.1e1 / 0.3e1)*_t48;
  const double _t219 = _t218*sigma_ss;
  const double _t220 = _t215*_t55;
  const double _t221 = _t220*sigma_ss;
  const double _t222 = _t115*_t67;
  const double _t223 = _t175*_t222;
  const double _t224 = (0.22e2 / 0.27e2)*_t96;
  const double _t225 = _t107*_t112;
  const double _t226 = (0.4e1 / 0.9e1)*_t1*_t46*_t55*_t7*sigma_ss - _t224*sigma_ss - _t225*sigma_ss;
  const double _t227 = _t118*_t226;
  const double _t228 = (0.1e1 / 0.3e1)*_t1*_t16*_t46*_t7*sigma_ss - _t221;
  const double _t229 = _t144*_t173;
  const double _t230 = _t228*_t229;
  const double _t231 = (0.1e1 / 0.3e1)*_t1*_t107*_t46*_t7*sigma_ss + (0.154e3 / 0.81e2)*_t1*_t16*_t191*_t7*sigma_ss - _t197 - _t209;
  const double _t232 = _t231*_t38;
  const double _t233 = -_t116*_t219 + _t116*_t221 - _t119*_t219 + _t119*_t221 + _t19*_t227 + _t19*_t230 + _t19*_t232 - _t194*_t21 + _t197*_t21 - _t200*_t21 + _t209*_t21 + _t211*_t59 - _t214*_t59 + _t217*_t59 + _t223*sigma_ss;
#endif
#if _KMAX >= 4
  const double _t235 = (0.1e1 / 0.6e1)*_t9;
  const double _t236 = _t129*_t235;
  const double _t237 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t238 = xc_powi((params->alpha), 5);
  const double _t239 = xc_powi(_t14, -5);
  const double _t240 = _t11*(-0.1e1 / 0.2304e4*_t128 + (0.1e1 / 0.55296e5)*_t13*_t237*_t238*_t239*_t29*sigma_ss/xc_powr(n_s, 40, 3));
  const double _t241 = (0.1e1 / 0.6e1)*_t17;
  const double _t242 = _t39*sigma_ss;
  const double _t243 = _t19*_t38;
  const double _t244 = (0.1e1 / 0.2e1)*_t34;
  const double _t245 = _t139*sigma_ss;
  const double _t246 = (0.1e1 / 0.4e1)*_t122;
  const double _t247 = _t246*sigma_ss;
  const double _t248 = _t17*_t73;
  const double _t249 = (0.1e1 / 0.3e1)*_t68;
  const double _t250 = _t241*_t37;
  const double _t251 = _t112*sigma_ss;
  const double _t252 = _t19*(-_t129*_t251 - _t246);
  const double _t253 = _t131*_t137;
  const double _t254 = _t131*sigma_ss;
  const double _t255 = _t141*_t254;
  const double _t256 = _t146*_t254;
  const double _t257 = _t145*_t67;
  const double _t258 = _t257*sigma_ss;
  const double _t259 = _t140*_t258;
  const double _t260 = _t37*_t71;
  const double _t261 = _t19*(-_t134 - _t135);
  const double _t262 = _t144*_t261;
  const double _t263 = _t19*params->kappa/xc_powi(_t20, 5);
  const double _t264 = _t263*(-_t241 - _t245);
  const double _t265 = _t143*_t264;
  const double _t266 = _t198*_t65;
  const double _t267 = _t153*_t215;
  const double _t268 = _t237*_t238*_t239*_t30;
  const double _t269 = _t11*((0.7e1 / 0.3456e4)*_t1*_t124*_t125*_t126*_t13*_t152*sigma_ss - 0.1e1 / 0.20736e5*_t268*_t54/xc_powr(n_s, 43, 3) - 0.1e1 / 0.48e2*_t78);
  const double _t270 = _t198*_t77;
  const double _t271 = (0.1e1 / 0.4e1)*_t9;
  const double _t272 = _t79*sigma_ss;
  const double _t273 = _t215*_t272;
  const double _t274 = _t68*_t73;
  const double _t275 = _t58*_t71;
  const double _t276 = (0.22e2 / 0.27e2)*_t166;
  const double _t277 = _t103*_t65;
  const double _t278 = (0.4e1 / 0.9e1)*_t47;
  const double _t279 = _t278*_t79;
  const double _t280 = _t112*_t170;
  const double _t281 = _t11*((0.1e1 / 0.7776e4)*_t104*_t268/xc_powr(n_s, 46, 3) + (0.167e3 / 0.1296e4)*_t105*sigma_ss - 0.19e2 / 0.162e3*_t106 - 0.25e2 / 0.3456e4*_t169*_t54);
  const double _t282 = _t276*sigma_ss;
  const double _t283 = _t278*_t33;
  const double _t284 = _t235*_t79;
  const double _t285 = _t153*_t251;
  const double _t286 = _t280*sigma_ss;
  const double _t287 = (0.4e1 / 0.9e1)*_t48;
  const double _t288 = _t81*sigma_ss;
  const double _t289 = _t235*_t55;
  const double _t290 = _t83*sigma_ss;
  const double _t291 = _t115*_t19;
  const double _t292 = _t287*sigma_ss;
  const double _t293 = _t73*_t82;
  const double _t294 = _t212*_t235;
  const double _t295 = _t118*_t19;
  const double _t296 = _t161*sigma_ss;
  const double _t297 = _t117*_t145;
  const double _t298 = _t177*_t58;
  const double _t299 = _t177*_t72;
  const double _t300 = _t195*_t272;
  const double _t301 = _t170*sigma_ss;
  const double _t302 = _t11*((0.89e2 / 0.3888e4)*_t1*_t104*_t124*_t125*_t126*_t13*_t204 + (0.253e3 / 0.324e3)*_t13*_t206*_t26*_t27*_t28*_t29*sigma_ss - _t202 - 0.1025e4 / 0.1944e4*_t203*_t54 - 0.1e1 / 0.2916e4*_t205*_t268/xc_powr(n_s, 49, 3));
  const double _t303 = _t213*_t59;
  const double _t304 = _t215*_t59;
  const double _t305 = _t115*_t175;
  const double _t306 = _t222*sigma_ss;
  const double _t307 = _t226*_t58;
  const double _t308 = _t173*_t228;
  const double _t309 = _t226*_t72;
  const double _t310 = _t19*_t82;
  const double _t311 = _t144*_t228;
  const double _t312 = _t117*_t311;
  const double _t313 = _t19*_t229;
  const double _t314 = _t67*sigma_ss;
  const double _t315 = _t190*sigma_ss;
  const double _t316 = (0.2618e4 / 0.243e3)/xc_powr(n_s, 20, 3);
  const double _t317 = _t315*_t316;
  const double _t318 = (0.616e3 / 0.81e2)*_t191;
  const double _t319 = (0.22e2 / 0.9e1)*_t95;
  const double _t320 = _t216*_t319;
  const double _t321 = _t207*sigma_ss;
  const double _t322 = _t11*((0.2563e4 / 0.1458e4)*_t104*_t63/xc_powi(n_s, 12) - 0.49e2 / 0.729e3*_t127*_t205/xc_powr(n_s, 44, 3) + _t24*_t316*_t8*sigma_ss + (0.2e1 / 0.2187e4)*_t268*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3) - 0.3047e4 / 0.972e3*_t31*_t54/xc_powr(n_s, 28, 3));
  const double _t323 = (0.4e1 / 0.3e1)*_t47;
  const double _t324 = (0.22e2 / 0.9e1)*_t96*sigma_ss;
  const double _t325 = _t212*_t323;
  const double _t326 = _t216*_t271;
  const double _t327 = _t115*_t254;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t23 = my_piecewise3(_t5, 0, _hc0[0]*_t22);
#if _KMAX >= 1
  const double _t41 = my_piecewise3(_t5, 0, _hc0[0]*_t40);
  const double _t43 = _hc0[2]*_t3;
  const double _t44 = _t42*_t43;
  const double _t45 = (0.1e1 / 0.6e1)*_t44;
  const double _t61 = my_piecewise3(_t5, 0, _hc0[0]*_t60 - _t22*_t45);
#endif
#if _KMAX >= 2
  const double _t76 = my_piecewise3(_t5, 0, _hc0[0]*_t75);
  const double _t85 = my_piecewise3(_t5, 0, _hc0[0]*_t84 - _t40*_t45);
  const double _t88 = _t43*_t87;
  const double _t91 = _hc0[5]*_t29*_t90;
  const double _t92 = _t6*_t91;
  const double _t93 = (0.1e1 / 0.3e1)*_t44;
  const double _t121 = my_piecewise3(_t5, 0, _hc0[0]*_t120 - _t60*_t93 + _t86*_t88 + _t89*_t92);
#endif
#if _KMAX >= 3
  const double _t149 = my_piecewise3(_t5, 0, _hc0[0]*_t148);
  const double _t163 = my_piecewise3(_t5, 0, _hc0[0]*_t162 - _t45*_t75);
  const double _t164 = (0.2e1 / 0.9e1)*_t88;
  const double _t182 = my_piecewise3(_t5, 0, _hc0[0]*_t181 + _t164*_t40 + _t165*_t92 - _t84*_t93);
  const double _t184 = _hc0[9]*_t183/(n_s * n_s * n_s * n_s);
  const double _t185 = _t43/xc_powr(n_s, 10, 3);
  const double _t186 = (0.14e2 / 0.27e2)*_t185;
  const double _t187 = _t46*_t91;
  const double _t188 = (0.1e1 / 0.9e1)*_t187;
  const double _t189 = _hc0[2]*_t4*_t42;
  const double _t234 = my_piecewise3(_t5, 0, _hc0[0]*_t233 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t60*_t87 + (0.1e1 / 0.12e2)*_hc0[5]*_t29*_t6*_t60*_t90 - _t120*_t189 - _t184*_t89 - _t186*_t22 - _t188*_t22);
#endif

  const double f = my_piecewise3(_t5, 0, _t23*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t41*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t23 + _t61*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t76*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t41 + _t85*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, _t121*n_s + 0.2e1*_t61);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t149*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t163*n_s + _t76);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, _t182*n_s + 0.2e1*_t85);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, 0.3e1*_t121 + _t234*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*((0.1e1 / 0.2e1)*_t122*_t39 + _t132*_t253 + _t133*_t241 + _t133*_t245 + _t141*_t250 + _t142*_t245 + _t146*_t250 + _t147*_t245 + _t21*_t236 + _t21*_t240 + _t236*_t242 + _t243*(-_t236 - _t240) + _t244*_t69 + _t244*_t74 + _t247*_t69 + _t247*_t74 + _t248*_t249 + _t249*_t35*_t73 + _t252*_t37*_t72 + _t255*_t68 + _t256*_t68 + _t259*_t37 + _t260*_t262 + _t260*_t265)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t149 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t111*_t274 + _t114*_t274 + _t118*_t252 + _t123*_t59 - _t129*_t21*_t52 + _t130*_t59 + _t131*_t157 + _t131*_t158 + _t131*_t160 - _t133*_t50 + _t133*_t57 + _t134*_t137*_t82 + _t134*_t81 + _t134*_t83 + _t135*_t81 + _t135*_t83 + _t136*_t157 + _t136*_t158 + _t136*_t160 - _t142*_t50 + _t142*_t57 - _t147*_t50 + _t147*_t57 + _t159*_t253 - _t21*_t266 + _t21*_t267 + _t21*_t269 - _t213*_t33*_t39 - _t218*_t69 - _t218*_t74 + _t220*_t69 + _t220*_t74 - _t242*_t266 + _t242*_t267 + _t243*((0.1e1 / 0.9e1)*_t1*_t129*_t46*_t7*sigma_ss + (0.1e1 / 0.3e1)*_t1*_t46*_t65*_t7 - _t267 - _t269) + (0.1e1 / 0.4e1)*_t248*_t82 + _t255*_t82 + _t256*_t82 + _t259*_t58 + _t262*_t275 + _t265*_t275 - _t270*_t69 - _t270*_t74 + _t271*_t39*_t79 + _t273*_t69 + _t273*_t74) - _t148*_t45));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t163 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t101*_t69 - _t101*_t74 + _t109*_t69 + _t109*_t74 - _t111*_t157 - _t111*_t158 - _t111*_t160 + _t114*_t157 + _t114*_t158 + _t114*_t160 + _t116*_t62 + _t116*_t66 + _t119*_t62 + _t119*_t66 + _t138*_t179 + _t141*_t291 + _t146*_t291 - _t153*_t168*_t21 + _t159*_t175*_t19 + _t161*_t175 - _t168*_t59*_t65 + _t172*_t70 + _t173*_t257 + _t173*_t265 + _t174*_t70 + _t176*_t70 + _t178*_t67 + _t178*_t70 + _t180*_t67 + _t180*_t70 + _t21*_t276 + _t21*_t277 - _t21*_t279 + _t21*_t280 + _t21*_t281 + _t222*_t73 + _t224*_t39 + _t225*_t39 + _t229*_t261 + _t243*((0.2e1 / 0.9e1)*_t1*_t153*_t46*_t7*sigma_ss + (0.4e1 / 0.9e1)*_t1*_t46*_t7*_t79 - _t276 - _t277 - _t280 - _t281) + _t258*_t298 - _t278*_t39*_t55 - _t279*_t39*sigma_ss + _t282*_t39 - _t283*_t288 - _t283*_t290 - _t283*_t59 + _t284*_t288 + _t284*_t290 + _t284*_t59 + _t285*_t59 + _t286*_t39 - _t287*_t81 - _t287*_t83 + _t289*_t81 + _t289*_t83 - _t292*_t293 + _t293*_t294 + _t295*((0.4e1 / 0.9e1)*_t1*_t33*_t46*_t7 + (0.2e1 / 0.9e1)*_t1*_t46*_t65*_t7*sigma_ss - _t284 - _t285) + _t296*_t297 + _t296*_t299 + _t69*_t98 + _t74*_t98) - _t162*_t93 + _t164*_t75 + (0.1e1 / 0.36e2)*_t75*_t92));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t182 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t107*_t304 - _t116*_t218 + _t116*_t220 - _t116*_t270 + _t116*_t273 - _t119*_t218 + _t119*_t220 - _t119*_t270 + _t119*_t273 + _t145*_t19*_t307 + (0.11e2 / 0.9e1)*_t166*_t59*sigma_ss - _t172*_t219 + _t172*_t221 - _t174*_t219 + _t174*_t221 + _t175*_t179*_t314 - _t176*_t219 + _t176*_t221 - _t178*_t219 + _t178*_t221 + _t18*_t227 + _t18*_t230 + _t18*_t232 - _t180*_t219 + _t180*_t221 + _t19*_t231*_t73 + _t19*_t298*_t311 - _t193*_t21 - _t194*_t39 + _t196*_t21 + _t197*_t39 - _t198*_t21*_t301 - _t199*_t21 - _t200*_t39 - _t201*_t21*_t77 + _t208*_t21 + _t209*_t39 + _t21*_t300 + _t21*_t302 + _t210*_t59 + _t211*_t81 + _t211*_t83 - _t214*_t81 - _t214*_t83 + _t217*_t81 + _t217*_t83 + _t223 + _t227*_t36 + _t230*_t36 + _t232*_t36 + _t243*((0.1e1 / 0.3e1)*_t1*_t107*_t46*_t7 + (0.154e3 / 0.81e2)*_t1*_t16*_t191*_t7 + (0.1e1 / 0.3e1)*_t1*_t170*_t46*_t7*sigma_ss + (0.154e3 / 0.81e2)*_t1*_t191*_t33*_t7*sigma_ss - _t196 - _t208 - _t300 - _t302) + _t264*_t308 - _t272*_t303 + _t295*((0.4e1 / 0.9e1)*_t1*_t46*_t55*_t7 + (0.4e1 / 0.9e1)*_t1*_t46*_t7*_t79*sigma_ss - _t224 - _t225 - _t282 - _t286) + _t297*_t306 + _t299*_t306 + _t301*_t304 - _t303*_t55 + _t305*_t70 + _t309*_t310 + _t310*_t312 + _t313*((0.1e1 / 0.3e1)*_t1*_t16*_t46*_t7 + (0.1e1 / 0.3e1)*_t1*_t33*_t46*_t7*sigma_ss - _t220 - _t273)) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t84*_t87 + (0.1e1 / 0.12e2)*_hc0[5]*_t29*_t6*_t84*_t90 - _t165*_t184 - _t181*_t189 - _t186*_t40 - _t188*_t40));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t234 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t116*_t324 - _t116*_t325 + _t116*_t326 + _t119*_t324 - _t119*_t325 + _t119*_t326 + _t175*_t231*_t254 - _t21*_t212*_t318*_t8 - _t21*_t278*_t321 + _t21*_t317 + _t21*_t320 + _t21*_t322 + (0.1e1 / 0.3e1)*_t212*_t305*_t9 + (0.44e2 / 0.9e1)*_t212*_t59*_t95 - _t216*_t323*_t59 - _t227*_t292 + _t227*_t294 - _t230*_t292 + _t230*_t294 - _t232*_t292 + _t232*_t294 + _t235*_t321*_t59 + _t243*((0.616e3 / 0.81e2)*_t1*_t191*_t55*_t7*sigma_ss + (0.4e1 / 0.9e1)*_t1*_t207*_t46*_t7*sigma_ss - _t317 - _t320 - _t322) + _t263*_t308*((0.4e1 / 0.9e1)*_t1*_t16*_t46*_t7*sigma_ss - _t294) + _t295*((0.2e1 / 0.3e1)*_t1*_t107*_t46*_t7*sigma_ss + (0.308e3 / 0.81e2)*_t1*_t16*_t191*_t7*sigma_ss - _t207*_t251 - _t212*_t319) - 0.8e1 / 0.9e1*_t305*_t48*sigma_ss + _t307*_t311*_t314 + _t309*_t327 + _t312*_t327 + _t313*((0.2e1 / 0.3e1)*_t1*_t46*_t55*_t7*sigma_ss - _t211 - _t217) - _t315*_t318*_t59) + (0.1e1 / 0.216e3)*_hc0[14]*_t22*_t25*_t8 + _hc0[9]*_t183*_t86/xc_powi(n_s, 5) + (0.4e1 / 0.3e1)*_t120*_t88 + (0.1e1 / 0.6e1)*_t120*_t92 - 0.1e1 / 0.9e1*_t184*_t60 - 0.56e2 / 0.27e2*_t185*_t60 - 0.4e1 / 0.9e1*_t187*_t60 + (0.140e3 / 0.81e2)*_t22*_t43/xc_powr(n_s, 13, 3) + (0.40e2 / 0.81e2)*_t22*_t91*_t94 - 0.2e1 / 0.3e1*_t233*_t44));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_x_pbeint_params *params = (const gga_x_pbeint_params *)(p->params);
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