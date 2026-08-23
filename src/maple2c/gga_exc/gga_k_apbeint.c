/*
  Generated from python/gga_exc/gga_k_apbeint.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_k_apbeint
*/

#ifndef _GGA_K_APBEINT_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_K_APBEINT_KERNEL_BODY
#define _KMAX 0
#define _GGA_K_APBEINT_HELPER_BODIES
#include "gga_k_apbeint.c"
#undef _GGA_K_APBEINT_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_K_APBEINT_HELPER_BODIES
#include "gga_k_apbeint.c"
#undef _GGA_K_APBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_K_APBEINT_HELPER_BODIES
#include "gga_k_apbeint.c"
#undef _GGA_K_APBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_K_APBEINT_HELPER_BODIES
#include "gga_k_apbeint.c"
#undef _GGA_K_APBEINT_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_K_APBEINT_HELPER_BODIES
#include "gga_k_apbeint.c"
#undef _GGA_K_APBEINT_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_k_apbeint.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_K_APBEINT_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z - p->zeta_threshold + 0.1e1;
  const double _t2 = _t1 <= 0;
  const double _t3 = _t1 > 0;
  const double _t4 = my_piecewise3(_t3, z, p->zeta_threshold - 0.1e1);
  const double _t5 = xc_expm1((0.5e1 / 0.3e1)*xc_log1p(_t4));
#if _KMAX >= 1
  const double _t6 = my_piecewise3(_t3, 0.1e1, 0);
  const double _t7 = _t4 + 0.1e1;
  const double _t8 = _t5 + 0.1e1;
#endif

  const double f = my_piecewise3(_t2, xc_powr(p->zeta_threshold, 5, 3) - 0.1e1, _t5);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise3(_t2, 0, (0.5e1 / 0.3e1)*_t6*_t8/_t7);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise3(_t2, 0, (0.10e2 / 0.9e1)*(_t6 * _t6)*_t8/(_t7 * _t7));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise3(_t2, 0, -0.10e2 / 0.27e2*(_t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)*(_t6 * _t6 * _t6 * _t6)*_t8/(_t7 * _t7 * _t7 * _t7));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {
  const gga_k_apbeint_params *params = (const gga_k_apbeint_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (M_PI * M_CBRTPI);
  const double _t4 = (0.1e1 / _t3);
  const double _t5 = _t2*_t4;
  const double _t6 = _t5/xc_powr(n_s, 8, 3);
  const double _t7 = (0.1e1 / 0.24e2)*_t6;
  const double _t8 = _t7*sigma_ss;
  const double _t9 = _t8*params->alpha;
  const double _t10 = -params->muGE + params->muPBE;
  const double _t11 = _t9 + 0.1e1;
  const double _t12 = _t10/_t11;
  const double _t13 = _t12*_t9 + params->muGE;
  const double _t14 = _t13*_t6;
  const double _t15 = (0.1e1 / 0.24e2)*_t14;
  const double _t16 = _t15*sigma_ss;
  const double _t17 = _t16 + params->kappa;
  const double _t18 = params->kappa/_t17;
  const double _t19 = xc_powr(0.3e1, 2, 3)*_t3*(_hc0[0] + 0.1e1);
  const double _t20 = _t19*(_t16*_t18 + 0.1e1);
  const double _t21 = (0.3e1 / 0.20e2)*xc_powr(n_s, 2, 3);
  const double _t22 = my_piecewise3(_t1, 0, _t20*_t21);
#if _KMAX >= 1
  const double _t23 = _t12*params->alpha;
  const double _t24 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t25 = (0.1e1 / (_t11 * _t11));
  const double _t26 = ((params->alpha) * (params->alpha));
  const double _t27 = xc_powr(0.6e1, 2, 3);
  const double _t28 = _t10*_t27;
  const double _t29 = _t24*_t25*_t26*_t28;
  const double _t30 = _t29/xc_powr(n_s, 16, 3);
  const double _t31 = _t23*_t7 - 0.1e1 / 0.576e3*_t30*sigma_ss;
  const double _t32 = _t31*_t6;
  const double _t33 = _t32*sigma_ss;
  const double _t34 = (0.1e1 / 0.24e2)*_t33;
  const double _t35 = -_t15 - _t34;
  const double _t36 = params->kappa/(_t17 * _t17);
  const double _t37 = _t35*_t36;
  const double _t38 = _t15*_t18 + _t16*_t37 + _t18*_t34;
  const double _t39 = _t19*_t21;
  const double _t40 = my_piecewise3(_t1, 0, _t38*_t39);
  const double _t41 = xc_powr(n_s, -1, 3);
  const double _t42 = (0.1e1 / 0.10e2)*_t41;
  const double _t43 = xc_powr(n_s, -11, 3);
  const double _t44 = _t43*_t5;
  const double _t45 = _t13*_t44;
  const double _t46 = (0.1e1 / 0.9e1)*_t45;
  const double _t47 = _t46*sigma_ss;
  const double _t48 = (0.1e1 / 0.9e1)*_t44;
  const double _t49 = _t48*sigma_ss;
  const double _t50 = xc_powr(n_s, -19, 3);
  const double _t51 = (sigma_ss * sigma_ss);
  const double _t52 = (0.1e1 / 0.216e3)*_t10*_t24*_t25*_t26*_t27*_t50*_t51 - _t23*_t49;
  const double _t53 = _t52*_t7;
  const double _t54 = _t53*sigma_ss;
  const double _t55 = (0.1e1 / 0.9e1)*_t13*_t2*_t4*_t43*sigma_ss - _t54;
  const double _t56 = _t36*_t55;
  const double _t57 = _t16*_t56 - _t18*_t47 + _t18*_t54;
  const double _t58 = my_piecewise3(_t1, 0, _t20*_t42 + _t39*_t57);
#endif
#if _KMAX >= 2
  const double _t59 = (0.1e1 / 0.12e2)*_t32;
  const double _t60 = _t10*((params->alpha) * (params->alpha) * (params->alpha))/((M_PI * M_PI * M_PI * M_PI)*(_t11 * _t11 * _t11));
  const double _t61 = _t60/xc_powi(n_s, 8);
  const double _t62 = -0.1e1 / 0.288e3*_t30 + (0.1e1 / 0.1152e4)*_t61*sigma_ss;
  const double _t63 = _t62*_t8;
  const double _t64 = (0.1e1 / 0.12e2)*_t14;
  const double _t65 = -_t59 - _t63;
  const double _t66 = _t36*_t65;
  const double _t67 = _t59*sigma_ss;
  const double _t68 = -_t64 - _t67;
  const double _t69 = params->kappa/(_t17 * _t17 * _t17);
  const double _t70 = _t68*_t69;
  const double _t71 = _t35*_t70;
  const double _t72 = _t16*_t66 + _t16*_t71 + _t18*_t59 + _t18*_t63 + _t37*_t64 + _t37*_t67;
  const double _t73 = my_piecewise3(_t1, 0, _t39*_t72);
  const double _t74 = _t19*_t42;
  const double _t75 = _t31*sigma_ss;
  const double _t76 = _t60/xc_powi(n_s, 9);
  const double _t77 = (0.1e1 / 0.72e2)*_t10*_t24*_t25*_t26*_t27*_t50*sigma_ss - _t23*_t48 - 0.1e1 / 0.432e3*_t51*_t76;
  const double _t78 = _t77*_t8;
  const double _t79 = _t55*_t70;
  const double _t80 = (0.1e1 / 0.9e1)*_t13*_t2*_t4*_t43 + (0.1e1 / 0.9e1)*_t2*_t31*_t4*_t43*sigma_ss - _t53 - _t78;
  const double _t81 = _t36*_t80;
  const double _t82 = _t15*_t56 + _t16*_t79 + _t16*_t81 - _t18*_t46 - _t18*_t48*_t75 + _t18*_t53 + _t18*_t78 + _t34*_t56 - _t37*_t47 + _t37*_t54;
  const double _t83 = my_piecewise3(_t1, 0, _t38*_t74 + _t39*_t82);
  const double _t84 = xc_powr(n_s, -4, 3);
  const double _t85 = (0.1e1 / 0.30e2)*_t84;
  const double _t86 = _t19*_t57;
  const double _t87 = (0.1e1 / 0.5e1)*_t41;
  const double _t88 = _t5/xc_powr(n_s, 14, 3);
  const double _t89 = _t13*_t88;
  const double _t90 = (0.11e2 / 0.27e2)*_t89;
  const double _t91 = _t90*sigma_ss;
  const double _t92 = (0.2e1 / 0.9e1)*_t44;
  const double _t93 = _t52*_t92;
  const double _t94 = _t93*sigma_ss;
  const double _t95 = (0.11e2 / 0.27e2)*sigma_ss;
  const double _t96 = _t88*_t95;
  const double _t97 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t98 = _t60/xc_powi(n_s, 10);
  const double _t99 = _t29/xc_powr(n_s, 22, 3);
  const double _t100 = _t23*_t96 - 0.1e1 / 0.24e2*_t51*_t99 + (0.1e1 / 0.162e3)*_t97*_t98;
  const double _t101 = _t100*_t7;
  const double _t102 = _t101*sigma_ss;
  const double _t103 = (0.2e1 / 0.9e1)*_t45;
  const double _t104 = _t103*sigma_ss;
  const double _t105 = (0.1e1 / 0.12e2)*_t6;
  const double _t106 = _t105*_t52;
  const double _t107 = _t106*sigma_ss;
  const double _t108 = -_t102 + (0.2e1 / 0.9e1)*_t2*_t4*_t43*_t52*sigma_ss - _t91;
  const double _t109 = _t108*_t36;
  const double _t110 = -_t107 + (0.2e1 / 0.9e1)*_t13*_t2*_t4*_t43*sigma_ss;
  const double _t111 = _t55*_t69;
  const double _t112 = _t110*_t111;
  const double _t113 = _t102*_t18 - _t104*_t56 + _t107*_t56 + _t109*_t16 + _t112*_t16 + _t18*_t91 - _t18*_t94;
  const double _t114 = my_piecewise3(_t1, 0, _t113*_t39 - _t20*_t85 + _t86*_t87);
#endif
#if _KMAX >= 3
  const double _t115 = _t6*_t62;
  const double _t116 = (0.1e1 / 0.8e1)*_t115;
  const double _t117 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t118 = (0.1e1 / (_t11 * _t11 * _t11 * _t11));
  const double _t119 = ((params->alpha) * (params->alpha) * (params->alpha) * (params->alpha));
  const double _t120 = _t10*_t117*_t118*_t119*_t2;
  const double _t121 = _t120/xc_powr(n_s, 32, 3);
  const double _t122 = -0.1e1 / 0.9216e4*_t121*sigma_ss + (0.1e1 / 0.384e3)*_t61;
  const double _t123 = _t122*_t8;
  const double _t124 = (0.1e1 / 0.8e1)*_t14;
  const double _t125 = -_t116 - _t123;
  const double _t126 = _t125*_t36;
  const double _t127 = (0.1e1 / 0.4e1)*_t32;
  const double _t128 = _t116*sigma_ss;
  const double _t129 = (0.1e1 / 0.8e1)*_t33;
  const double _t130 = _t70*sigma_ss;
  const double _t131 = _t130*_t64;
  const double _t132 = (0.1e1 / 0.6e1)*_t32;
  const double _t133 = -0.1e1 / 0.12e2*_t115*sigma_ss - _t132;
  const double _t134 = _t133*_t69;
  const double _t135 = _t134*_t35;
  const double _t136 = -_t124 - _t129;
  const double _t137 = params->kappa/(_t17 * _t17 * _t17 * _t17);
  const double _t138 = _t136*_t137;
  const double _t139 = _t138*_t68;
  const double _t140 = _t139*_t35;
  const double _t141 = _t116*_t18 + _t123*_t18 + _t124*_t66 + _t124*_t71 + _t126*_t16 + _t127*_t37 + _t128*_t37 + _t129*_t66 + _t129*_t71 + _t131*_t65 + _t135*_t16 + _t140*_t16;
  const double _t142 = my_piecewise3(_t1, 0, _t141*_t39);
  const double _t143 = _t31*_t92;
  const double _t144 = _t105*_t77;
  const double _t145 = xc_powr(n_s, -35, 3);
  const double _t146 = (0.1e1 / 0.3456e4)*_t120*_t145*_t51 + (0.1e1 / 0.54e2)*_t29*_t50 - 0.5e1 / 0.432e3*_t76*sigma_ss;
  const double _t147 = _t146*_t8;
  const double _t148 = _t143*sigma_ss;
  const double _t149 = _t144*sigma_ss;
  const double _t150 = _t111*_t133;
  const double _t151 = _t139*_t55;
  const double _t152 = -_t144 - _t147 + (0.2e1 / 0.9e1)*_t2*_t31*_t4*_t43 + (0.1e1 / 0.9e1)*_t2*_t4*_t43*_t62*sigma_ss;
  const double _t153 = _t152*_t36;
  const double _t154 = _t64*_t80;
  const double _t155 = -_t103*_t37 + _t106*_t37 + _t130*_t154 - _t143*_t18 + _t144*_t18 + _t147*_t18 - _t148*_t37 + _t149*_t37 + _t150*_t16 + _t151*_t16 + _t153*_t16 - _t18*_t49*_t62 - _t47*_t66 - _t47*_t71 + _t54*_t66 + _t54*_t71 + _t56*_t59 + _t56*_t63 + _t64*_t79 + _t64*_t81 + _t67*_t79 + _t67*_t81;
  const double _t156 = my_piecewise3(_t1, 0, _t155*_t39 + _t72*_t74);
  const double _t157 = _t19*_t85;
  const double _t158 = _t19*_t87;
  const double _t159 = _t31*_t88;
  const double _t160 = _t159*_t95;
  const double _t161 = _t92*sigma_ss;
  const double _t162 = _t120/xc_powr(n_s, 38, 3);
  const double _t163 = -0.1e1 / 0.1296e4*_t162*_t97 + (0.11e2 / 0.27e2)*_t23*_t88 + (0.17e2 / 0.432e3)*_t51*_t98 - 0.65e2 / 0.648e3*_t99*sigma_ss;
  const double _t164 = _t163*_t8;
  const double _t165 = _t108*_t70;
  const double _t166 = _t110*_t55;
  const double _t167 = _t138*_t166;
  const double _t168 = _t110*_t69;
  const double _t169 = _t168*_t80;
  const double _t170 = -_t106 + (0.2e1 / 0.9e1)*_t13*_t2*_t4*_t43 - _t149 + (0.2e1 / 0.9e1)*_t2*_t31*_t4*_t43*sigma_ss;
  const double _t171 = _t111*_t170;
  const double _t172 = -_t101 - _t160 - _t164 + (0.2e1 / 0.9e1)*_t2*_t4*_t43*_t52 + (0.2e1 / 0.9e1)*_t2*_t4*_t43*_t77*sigma_ss - _t90;
  const double _t173 = _t172*_t36;
  const double _t174 = _t101*_t18 + _t102*_t37 - _t103*_t56 - _t104*_t79 - _t104*_t81 + _t106*_t56 + _t107*_t79 + _t107*_t81 + _t109*_t15 + _t109*_t34 + _t112*_t15 + _t112*_t34 - _t148*_t56 + _t149*_t56 + _t16*_t165 + _t16*_t167 + _t16*_t169 + _t16*_t171 + _t16*_t173 + _t160*_t18 - _t161*_t18*_t77 + _t164*_t18 + _t18*_t90 - _t18*_t93 + _t37*_t91 - _t37*_t94;
  const double _t175 = my_piecewise3(_t1, 0, -_t157*_t38 + _t158*_t82 + _t174*_t39);
  const double _t176 = xc_powr(n_s, -7, 3);
  const double _t177 = (0.2e1 / 0.45e2)*_t176;
  const double _t178 = (0.1e1 / 0.10e2)*_t84;
  const double _t179 = _t113*_t19;
  const double _t180 = (0.3e1 / 0.10e2)*_t41;
  const double _t181 = _t13*_t5;
  const double _t182 = xc_powr(n_s, -17, 3);
  const double _t183 = (0.154e3 / 0.81e2)*_t182;
  const double _t184 = _t181*_t183;
  const double _t185 = _t184*sigma_ss;
  const double _t186 = (0.11e2 / 0.9e1)*_t88;
  const double _t187 = _t186*_t52;
  const double _t188 = _t187*sigma_ss;
  const double _t189 = (0.1e1 / 0.3e1)*_t44;
  const double _t190 = _t100*_t189;
  const double _t191 = _t190*sigma_ss;
  const double _t192 = _t183*_t5;
  const double _t193 = _t192*_t23;
  const double _t194 = _t60/xc_powi(n_s, 11);
  const double _t195 = xc_powr(n_s, -41, 3);
  const double _t196 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t197 = xc_powr(n_s, -25, 3);
  const double _t198 = (0.1e1 / 0.486e3)*_t10*_t117*_t118*_t119*_t195*_t196*_t2 + (0.341e3 / 0.972e3)*_t10*_t197*_t24*_t25*_t26*_t27*_t51 - _t193*sigma_ss - 0.19e2 / 0.162e3*_t194*_t97;
  const double _t199 = _t198*_t7;
  const double _t200 = _t199*sigma_ss;
  const double _t201 = (0.11e2 / 0.9e1)*_t89;
  const double _t202 = _t201*sigma_ss;
  const double _t203 = _t52*sigma_ss;
  const double _t204 = (0.2e1 / 0.3e1)*_t44;
  const double _t205 = _t203*_t204;
  const double _t206 = (0.1e1 / 0.8e1)*_t6;
  const double _t207 = _t100*sigma_ss;
  const double _t208 = _t206*_t207;
  const double _t209 = (0.1e1 / 0.3e1)*_t45;
  const double _t210 = _t209*sigma_ss;
  const double _t211 = _t206*_t52;
  const double _t212 = _t211*sigma_ss;
  const double _t213 = _t108*_t64;
  const double _t214 = _t168*_t213;
  const double _t215 = (0.22e2 / 0.27e2)*_t89;
  const double _t216 = _t100*_t105;
  const double _t217 = (0.4e1 / 0.9e1)*_t2*_t4*_t43*_t52*sigma_ss - _t215*sigma_ss - _t216*sigma_ss;
  const double _t218 = _t111*_t217;
  const double _t219 = (0.1e1 / 0.3e1)*_t13*_t2*_t4*_t43*sigma_ss - _t212;
  const double _t220 = _t137*_t166;
  const double _t221 = _t219*_t220;
  const double _t222 = (0.1e1 / 0.3e1)*_t100*_t2*_t4*_t43*sigma_ss + (0.154e3 / 0.81e2)*_t13*_t182*_t2*_t4*sigma_ss - _t188 - _t200;
  const double _t223 = _t222*_t36;
  const double _t224 = -_t109*_t210 + _t109*_t212 - _t112*_t210 + _t112*_t212 + _t16*_t218 + _t16*_t221 + _t16*_t223 - _t18*_t185 + _t18*_t188 - _t18*_t191 + _t18*_t200 + _t202*_t56 - _t205*_t56 + _t208*_t56 + _t214*sigma_ss;
  const double _t225 = my_piecewise3(_t1, 0, _t177*_t20 - _t178*_t86 + _t179*_t180 + _t224*_t39);
#endif
#if _KMAX >= 4
  const double _t226 = (0.1e1 / 0.6e1)*_t6;
  const double _t227 = _t122*_t226;
  const double _t228 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t229 = xc_powi((params->alpha), 5);
  const double _t230 = xc_powi(_t11, -5);
  const double _t231 = _t8*((0.1e1 / 0.55296e5)*_t10*_t228*_t229*_t230*_t27*sigma_ss/xc_powr(n_s, 40, 3) - 0.1e1 / 0.2304e4*_t121);
  const double _t232 = (0.1e1 / 0.6e1)*_t14;
  const double _t233 = _t37*sigma_ss;
  const double _t234 = _t16*_t36;
  const double _t235 = (0.1e1 / 0.2e1)*_t32;
  const double _t236 = _t132*sigma_ss;
  const double _t237 = (0.1e1 / 0.4e1)*_t115;
  const double _t238 = _t237*sigma_ss;
  const double _t239 = _t14*_t70;
  const double _t240 = (0.1e1 / 0.3e1)*_t65;
  const double _t241 = _t232*_t35;
  const double _t242 = _t105*sigma_ss;
  const double _t243 = _t16*(-_t122*_t242 - _t237);
  const double _t244 = _t124*_t130;
  const double _t245 = _t124*sigma_ss;
  const double _t246 = _t134*_t245;
  const double _t247 = _t139*_t245;
  const double _t248 = _t138*_t64;
  const double _t249 = _t248*sigma_ss;
  const double _t250 = _t133*_t249;
  const double _t251 = _t35*_t68;
  const double _t252 = _t16*(-_t127 - _t128);
  const double _t253 = _t137*_t252;
  const double _t254 = _t16*params->kappa/xc_powi(_t17, 5);
  const double _t255 = _t254*(-_t232 - _t236);
  const double _t256 = _t136*_t255;
  const double _t257 = _t189*_t62;
  const double _t258 = _t146*_t206;
  const double _t259 = _t228*_t229*_t230*_t28;
  const double _t260 = _t8*((0.7e1 / 0.3456e4)*_t10*_t117*_t118*_t119*_t145*_t2*sigma_ss - 0.1e1 / 0.20736e5*_t259*_t51/xc_powr(n_s, 43, 3) - 0.1e1 / 0.48e2*_t76);
  const double _t261 = _t189*_t75;
  const double _t262 = (0.1e1 / 0.4e1)*_t6;
  const double _t263 = _t77*sigma_ss;
  const double _t264 = _t206*_t263;
  const double _t265 = _t65*_t70;
  const double _t266 = _t55*_t68;
  const double _t267 = (0.22e2 / 0.27e2)*_t159;
  const double _t268 = _t62*_t96;
  const double _t269 = (0.4e1 / 0.9e1)*_t44;
  const double _t270 = _t269*_t77;
  const double _t271 = _t105*_t163;
  const double _t272 = _t8*(-0.25e2 / 0.3456e4*_t162*_t51 + (0.1e1 / 0.7776e4)*_t259*_t97/xc_powr(n_s, 46, 3) + (0.167e3 / 0.1296e4)*_t98*sigma_ss - 0.19e2 / 0.162e3*_t99);
  const double _t273 = _t267*sigma_ss;
  const double _t274 = _t269*_t31;
  const double _t275 = _t226*_t77;
  const double _t276 = _t146*_t242;
  const double _t277 = _t271*sigma_ss;
  const double _t278 = (0.4e1 / 0.9e1)*_t45;
  const double _t279 = _t79*sigma_ss;
  const double _t280 = _t226*_t52;
  const double _t281 = _t81*sigma_ss;
  const double _t282 = _t108*_t16;
  const double _t283 = _t278*sigma_ss;
  const double _t284 = _t70*_t80;
  const double _t285 = _t203*_t226;
  const double _t286 = _t111*_t16;
  const double _t287 = _t154*sigma_ss;
  const double _t288 = _t110*_t138;
  const double _t289 = _t170*_t55;
  const double _t290 = _t170*_t69;
  const double _t291 = _t186*_t263;
  const double _t292 = _t163*sigma_ss;
  const double _t293 = _t8*((0.89e2 / 0.3888e4)*_t10*_t117*_t118*_t119*_t195*_t2*_t97 + (0.253e3 / 0.324e3)*_t10*_t197*_t24*_t25*_t26*_t27*sigma_ss - _t193 - 0.1025e4 / 0.1944e4*_t194*_t51 - 0.1e1 / 0.2916e4*_t196*_t259/xc_powr(n_s, 49, 3));
  const double _t294 = _t204*_t56;
  const double _t295 = _t206*_t56;
  const double _t296 = _t108*_t168;
  const double _t297 = _t213*sigma_ss;
  const double _t298 = _t217*_t55;
  const double _t299 = _t166*_t219;
  const double _t300 = _t217*_t69;
  const double _t301 = _t16*_t80;
  const double _t302 = _t137*_t219;
  const double _t303 = _t110*_t302;
  const double _t304 = _t16*_t220;
  const double _t305 = _t64*sigma_ss;
  const double _t306 = _t181*sigma_ss;
  const double _t307 = (0.2618e4 / 0.243e3)/xc_powr(n_s, 20, 3);
  const double _t308 = _t306*_t307;
  const double _t309 = (0.616e3 / 0.81e2)*_t182;
  const double _t310 = (0.22e2 / 0.9e1)*_t88;
  const double _t311 = _t207*_t310;
  const double _t312 = _t198*sigma_ss;
  const double _t313 = _t8*(-0.49e2 / 0.729e3*_t120*_t196/xc_powr(n_s, 44, 3) + _t23*_t307*_t5*sigma_ss + (0.2e1 / 0.2187e4)*_t259*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3) - 0.3047e4 / 0.972e3*_t29*_t51/xc_powr(n_s, 28, 3) + (0.2563e4 / 0.1458e4)*_t60*_t97/xc_powi(n_s, 12));
  const double _t314 = (0.4e1 / 0.3e1)*_t44;
  const double _t315 = (0.22e2 / 0.9e1)*_t89*sigma_ss;
  const double _t316 = _t203*_t314;
  const double _t317 = _t207*_t262;
  const double _t318 = _t108*_t245;
#endif

  const double f = my_piecewise3(_t1, 0, _t22*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t40*n_s);
  out[1] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t22 + _t58*n_s);
  out[2] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t73*n_s);
  out[3] = d2f_dsigma_ss2;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t40 + _t83*n_s);
  out[4] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, _t114*n_s + 0.2e1*_t58);
  out[5] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t142*n_s);
  out[6] = d3f_dsigma_ss3;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t156*n_s + _t73);
  out[7] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, _t175*n_s + 0.2e1*_t83);
  out[8] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t114 + _t225*n_s);
  out[9] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t39*((0.1e1 / 0.2e1)*_t115*_t37 + _t125*_t244 + _t126*_t232 + _t126*_t236 + _t134*_t241 + _t135*_t236 + _t139*_t241 + _t140*_t236 + _t18*_t227 + _t18*_t231 + _t227*_t233 + _t234*(-_t227 - _t231) + _t235*_t66 + _t235*_t71 + _t238*_t66 + _t238*_t71 + _t239*_t240 + _t240*_t33*_t70 + _t243*_t35*_t69 + _t246*_t65 + _t247*_t65 + _t250*_t35 + _t251*_t253 + _t251*_t256)));
  out[10] = d4f_dsigma_ss4;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t142 + n_s*my_piecewise3(_t1, 0, _t141*_t74 + _t39*(-_t104*_t265 + _t107*_t265 + _t111*_t243 + _t116*_t56 - _t122*_t18*_t49 + _t123*_t56 + _t124*_t150 + _t124*_t151 + _t124*_t153 - _t126*_t47 + _t126*_t54 + _t127*_t130*_t80 + _t127*_t79 + _t127*_t81 + _t128*_t79 + _t128*_t81 + _t129*_t150 + _t129*_t151 + _t129*_t153 - _t135*_t47 + _t135*_t54 - _t140*_t47 + _t140*_t54 + _t152*_t244 - _t18*_t257 + _t18*_t258 + _t18*_t260 - _t204*_t31*_t37 - _t209*_t66 - _t209*_t71 + _t211*_t66 + _t211*_t71 - _t233*_t257 + _t233*_t258 + _t234*((0.1e1 / 0.9e1)*_t122*_t2*_t4*_t43*sigma_ss + (0.1e1 / 0.3e1)*_t2*_t4*_t43*_t62 - _t258 - _t260) + (0.1e1 / 0.4e1)*_t239*_t80 + _t246*_t80 + _t247*_t80 + _t250*_t55 + _t253*_t266 + _t256*_t266 - _t261*_t66 - _t261*_t71 + _t262*_t37*_t77 + _t264*_t66 + _t264*_t71)));
  out[11] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t156 + n_s*my_piecewise3(_t1, 0, _t155*_t158 - _t157*_t72 + _t39*(_t102*_t66 + _t102*_t71 - _t104*_t150 - _t104*_t151 - _t104*_t153 + _t107*_t150 + _t107*_t151 + _t107*_t153 + _t109*_t59 + _t109*_t63 + _t112*_t59 + _t112*_t63 + _t131*_t172 + _t134*_t282 + _t139*_t282 - _t146*_t161*_t18 + _t152*_t16*_t168 + _t154*_t168 - _t161*_t56*_t62 + _t165*_t67 + _t166*_t248 + _t166*_t256 + _t167*_t67 + _t169*_t67 + _t171*_t64 + _t171*_t67 + _t173*_t64 + _t173*_t67 + _t18*_t267 + _t18*_t268 - _t18*_t270 + _t18*_t271 + _t18*_t272 + _t213*_t70 + _t215*_t37 + _t216*_t37 + _t220*_t252 + _t234*((0.2e1 / 0.9e1)*_t146*_t2*_t4*_t43*sigma_ss + (0.4e1 / 0.9e1)*_t2*_t4*_t43*_t77 - _t267 - _t268 - _t271 - _t272) + _t249*_t289 - _t269*_t37*_t52 - _t270*_t37*sigma_ss + _t273*_t37 - _t274*_t279 - _t274*_t281 - _t274*_t56 + _t275*_t279 + _t275*_t281 + _t275*_t56 + _t276*_t56 + _t277*_t37 - _t278*_t79 - _t278*_t81 + _t280*_t79 + _t280*_t81 - _t283*_t284 + _t284*_t285 + _t286*((0.4e1 / 0.9e1)*_t2*_t31*_t4*_t43 + (0.2e1 / 0.9e1)*_t2*_t4*_t43*_t62*sigma_ss - _t275 - _t276) + _t287*_t288 + _t287*_t290 + _t66*_t91 - _t66*_t94 + _t71*_t91 - _t71*_t94)));
  out[12] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t175 + n_s*my_piecewise3(_t1, 0, _t174*_t180*_t19 + _t177*_t19*_t38 - _t178*_t19*_t82 + _t39*(_t100*_t295 - _t109*_t209 + _t109*_t211 - _t109*_t261 + _t109*_t264 - _t112*_t209 + _t112*_t211 - _t112*_t261 + _t112*_t264 + _t138*_t16*_t298 + _t15*_t218 + _t15*_t221 + _t15*_t223 + (0.11e2 / 0.9e1)*_t159*_t56*sigma_ss + _t16*_t222*_t70 + _t16*_t289*_t302 - _t165*_t210 + _t165*_t212 - _t167*_t210 + _t167*_t212 + _t168*_t172*_t305 - _t169*_t210 + _t169*_t212 - _t171*_t210 + _t171*_t212 - _t173*_t210 + _t173*_t212 - _t18*_t184 + _t18*_t187 - _t18*_t189*_t292 - _t18*_t190 - _t18*_t192*_t75 + _t18*_t199 + _t18*_t291 + _t18*_t293 - _t185*_t37 + _t188*_t37 - _t191*_t37 + _t200*_t37 + _t201*_t56 + _t202*_t79 + _t202*_t81 - _t205*_t79 - _t205*_t81 + _t208*_t79 + _t208*_t81 + _t214 + _t218*_t34 + _t221*_t34 + _t223*_t34 + _t234*((0.1e1 / 0.3e1)*_t100*_t2*_t4*_t43 + (0.154e3 / 0.81e2)*_t13*_t182*_t2*_t4 + (0.1e1 / 0.3e1)*_t163*_t2*_t4*_t43*sigma_ss + (0.154e3 / 0.81e2)*_t182*_t2*_t31*_t4*sigma_ss - _t187 - _t199 - _t291 - _t293) + _t255*_t299 - _t263*_t294 + _t286*((0.4e1 / 0.9e1)*_t2*_t4*_t43*_t52 + (0.4e1 / 0.9e1)*_t2*_t4*_t43*_t77*sigma_ss - _t215 - _t216 - _t273 - _t277) + _t288*_t297 + _t290*_t297 + _t292*_t295 - _t294*_t52 + _t296*_t67 + _t300*_t301 + _t301*_t303 + _t304*((0.1e1 / 0.3e1)*_t13*_t2*_t4*_t43 + (0.1e1 / 0.3e1)*_t2*_t31*_t4*_t43*sigma_ss - _t211 - _t264))));
  out[13] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t225 + n_s*my_piecewise3(_t1, 0, (0.8e1 / 0.45e2)*_t176*_t86 - 0.1e1 / 0.5e1*_t179*_t84 + (0.2e1 / 0.5e1)*_t19*_t224*_t41 - 0.14e2 / 0.135e3*_t20/xc_powr(n_s, 10, 3) + _t39*(_t109*_t315 - _t109*_t316 + _t109*_t317 + _t112*_t315 - _t112*_t316 + _t112*_t317 + _t168*_t222*_t245 - _t18*_t203*_t309*_t5 - _t18*_t269*_t312 + _t18*_t308 + _t18*_t311 + _t18*_t313 + (0.1e1 / 0.3e1)*_t203*_t296*_t6 + (0.44e2 / 0.9e1)*_t203*_t56*_t88 - _t207*_t314*_t56 - _t218*_t283 + _t218*_t285 - _t221*_t283 + _t221*_t285 - _t223*_t283 + _t223*_t285 + _t226*_t312*_t56 + _t234*((0.616e3 / 0.81e2)*_t182*_t2*_t4*_t52*sigma_ss + (0.4e1 / 0.9e1)*_t198*_t2*_t4*_t43*sigma_ss - _t308 - _t311 - _t313) + _t254*_t299*((0.4e1 / 0.9e1)*_t13*_t2*_t4*_t43*sigma_ss - _t285) + _t286*((0.2e1 / 0.3e1)*_t100*_t2*_t4*_t43*sigma_ss + (0.308e3 / 0.81e2)*_t13*_t182*_t2*_t4*sigma_ss - _t198*_t242 - _t203*_t310) - 0.8e1 / 0.9e1*_t296*_t45*sigma_ss + _t298*_t302*_t305 + _t300*_t318 + _t303*_t318 + _t304*((0.2e1 / 0.3e1)*_t2*_t4*_t43*_t52*sigma_ss - _t202 - _t208) - _t306*_t309*_t56)));
  out[14] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, xc_gga_out_params *out)
{
  assert(p->params != NULL);
  const gga_k_apbeint_params *params = (const gga_k_apbeint_params *)(p->params);
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