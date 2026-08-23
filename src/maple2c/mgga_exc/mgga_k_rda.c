/*
  Generated from python/mgga_exc/mgga_k_rda.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_k_rda
*/

#ifndef _MGGA_K_RDA_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_K_RDA_KERNEL_BODY
#define _KMAX 0
#define _MGGA_K_RDA_HELPER_BODIES
#include "mgga_k_rda.c"
#undef _MGGA_K_RDA_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_K_RDA_HELPER_BODIES
#include "mgga_k_rda.c"
#undef _MGGA_K_RDA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_K_RDA_HELPER_BODIES
#include "mgga_k_rda.c"
#undef _MGGA_K_RDA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_K_RDA_HELPER_BODIES
#include "mgga_k_rda.c"
#undef _MGGA_K_RDA_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_K_RDA_HELPER_BODIES
#include "mgga_k_rda.c"
#undef _MGGA_K_RDA_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_k_rda.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_K_RDA_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_k_rda_params *params = (const mgga_k_rda_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = -p->dens_threshold + n_s <= 0;
  const double _t2 = xc_powr(n_s, -8, 3);
  const double _t3 = xc_powr(0.6e1, 1, 3);
  const double _t4 = (M_PI * M_CBRTPI);
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t3*_t5;
  const double _t7 = _t2*_t6;
  const double _t8 = (0.5e1 / 0.72e2)*_t7;
  const double _t9 = (0.1e1 / 0.24e2)*_t7;
  const double _t10 = lapl_s*params->c;
  const double _t11 = xc_powr(n_s, -5, 3);
  const double _t12 = _t11*_t6;
  const double _t13 = (0.1e1 / 0.24e2)*_t12;
  const double _t14 = _t10*_t13 + _t9*sigma_ss;
  const double _t15 = _t14*params->beta3;
  const double _t16 = _t15 + 0.1e1;
  const double _t17 = (0.1e1 / _t16);
  const double _t18 = _t17*params->A3;
  const double _t19 = xc_powr(n_s, -16, 3);
  const double _t20 = (sigma_ss * sigma_ss);
  const double _t21 = xc_powr(0.6e1, 2, 3);
  const double _t22 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t23 = _t21*_t22;
  const double _t24 = _t20*_t23;
  const double _t25 = (0.1e1 / 0.576e3)*_t19*_t24;
  const double _t26 = (lapl_s * lapl_s);
  const double _t27 = _t23*_t26;
  const double _t28 = _t27*params->a;
  const double _t29 = xc_powr(n_s, -10, 3);
  const double _t30 = (0.1e1 / 0.576e3)*_t29;
  const double _t31 = _t25 + _t28*_t30;
  const double _t32 = xc_powr(_t31, 1, 2);
  const double _t33 = _t32*params->beta1;
  const double _t34 = _t33 + 0.1e1;
  const double _t35 = (0.1e1 / (_t34 * _t34));
  const double _t36 = _t35*params->A1;
  const double _t37 = _t27*params->b;
  const double _t38 = _t25 + _t30*_t37;
  const double _t39 = xc_powr(_t38, 1, 2);
  const double _t40 = _t39*params->beta2;
  const double _t41 = _t40 + 0.1e1;
  const double _t42 = (0.1e1 / (_t41 * _t41 * _t41 * _t41));
  const double _t43 = _t42*params->A2;
  const double _t44 = xc_powr(0.3e1, 2, 3)*_t4*(_hc0[0] + 0.1e1);
  const double _t45 = _t44*(_t14*_t18 + _t31*_t36 + (_t38 * _t38)*_t43 + _t8*sigma_ss + params->A0);
  const double _t46 = (0.3e1 / 0.20e2)*xc_powr(n_s, 2, 3);
  const double _t47 = my_piecewise3(_t1, 0, _t45*_t46);
#if _KMAX >= 1
  const double _t48 = (0.1e1 / (_t16 * _t16));
  const double _t49 = _t48*params->A3;
  const double _t50 = _t15*_t49;
  const double _t51 = _t50*params->c;
  const double _t52 = (0.1e1 / (_t34 * _t34 * _t34));
  const double _t53 = _t33*_t52*params->A1;
  const double _t54 = _t29*params->a;
  const double _t55 = (0.1e1 / 0.288e3)*_t23;
  const double _t56 = _t54*_t55;
  const double _t57 = _t53*_t56;
  const double _t58 = xc_powi(_t41, -5);
  const double _t59 = _t58*params->A2;
  const double _t60 = xc_powr(_t38, 3, 2);
  const double _t61 = _t60*params->beta2;
  const double _t62 = _t59*_t61;
  const double _t63 = _t23*_t29*params->b;
  const double _t64 = (0.1e1 / 0.144e3)*_t63;
  const double _t65 = _t62*_t64;
  const double _t66 = (0.1e1 / 0.24e2)*_t11*_t17*_t3*_t5*params->A3*params->c - _t13*_t51 + (0.1e1 / 0.288e3)*_t21*_t22*_t29*_t35*lapl_s*params->A1*params->a + (0.1e1 / 0.144e3)*_t21*_t22*_t29*_t38*_t42*lapl_s*params->A2*params->b - _t57*lapl_s - _t65*lapl_s;
  const double _t67 = _t44*_t46;
  const double _t68 = my_piecewise3(_t1, 0, _t66*_t67);
  const double _t69 = _t23*_t36;
  const double _t70 = (0.1e1 / 0.288e3)*_t69;
  const double _t71 = _t19*_t70;
  const double _t72 = _t19*_t23;
  const double _t73 = _t38*_t43;
  const double _t74 = (0.1e1 / 0.144e3)*_t73;
  const double _t75 = _t72*_t74;
  const double _t76 = (0.1e1 / 0.288e3)*_t72;
  const double _t77 = _t53*_t76;
  const double _t78 = (0.1e1 / 0.144e3)*_t72;
  const double _t79 = _t62*_t78;
  const double _t80 = _t18*_t9 - _t50*_t9 + _t71*sigma_ss + _t75*sigma_ss - _t77*sigma_ss - _t79*sigma_ss + _t8;
  const double _t81 = my_piecewise3(_t1, 0, _t67*_t80);
  const double _t82 = xc_powr(n_s, -1, 3);
  const double _t83 = (0.1e1 / 0.10e2)*_t82;
  const double _t84 = xc_powr(n_s, -11, 3);
  const double _t85 = _t6*_t84;
  const double _t86 = (0.5e1 / 0.27e2)*_t85;
  const double _t87 = (0.1e1 / 0.9e1)*_t85;
  const double _t88 = -_t10*_t8 - _t87*sigma_ss;
  const double _t89 = xc_powr(n_s, -19, 3);
  const double _t90 = _t24*_t89;
  const double _t91 = (0.1e1 / 0.108e3)*_t90;
  const double _t92 = xc_powr(n_s, -13, 3);
  const double _t93 = _t28*_t92;
  const double _t94 = _t91 + (0.5e1 / 0.864e3)*_t93;
  const double _t95 = -_t94;
  const double _t96 = _t37*_t92;
  const double _t97 = -0.1e1 / 0.54e2*_t90 - 0.5e1 / 0.432e3*_t96;
  const double _t98 = (0.1e1 / 0.216e3)*_t90;
  const double _t99 = (0.5e1 / 0.1728e4)*_t93 + _t98;
  const double _t100 = -_t99;
  const double _t101 = _t100*params->A1;
  const double _t102 = 0.2e1*_t52;
  const double _t103 = _t102*_t33;
  const double _t104 = (0.5e1 / 0.1728e4)*_t96 + _t98;
  const double _t105 = -_t104;
  const double _t106 = _t105*_t59;
  const double _t107 = 0.4e1*_t106;
  const double _t108 = -_t101*_t103 - _t107*_t61 + _t17*_t88*params->A3 + _t35*_t95*params->A1 + _t38*_t42*_t97*params->A2 - _t50*_t88 - _t86*sigma_ss;
  const double _t109 = my_piecewise3(_t1, 0, _t108*_t67 + _t45*_t83);
#endif
#if _KMAX >= 2
  const double _t110 = _t49*params->beta3;
  const double _t111 = _t110*_t23;
  const double _t112 = (0.1e1 / 0.288e3)*_t111;
  const double _t113 = ((params->c) * (params->c));
  const double _t114 = _t113*_t29;
  const double _t115 = xc_powr(n_s, -20, 3);
  const double _t116 = ((params->b) * (params->b));
  const double _t117 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t118 = _t117*_t3;
  const double _t119 = _t118*_t43;
  const double _t120 = _t116*_t119;
  const double _t121 = _t120*_t26;
  const double _t122 = ((params->a) * (params->a));
  const double _t123 = (0.1e1 / (_t34 * _t34 * _t34 * _t34));
  const double _t124 = ((params->beta1) * (params->beta1));
  const double _t125 = _t123*_t124;
  const double _t126 = _t125*params->A1;
  const double _t127 = _t118*_t126;
  const double _t128 = _t122*_t127;
  const double _t129 = _t115*_t128;
  const double _t130 = (0.1e1 / 0.9216e4)*_t26;
  const double _t131 = (0.1e1 / (_t16 * _t16 * _t16));
  const double _t132 = ((params->beta3) * (params->beta3));
  const double _t133 = _t131*_t132*params->A3;
  const double _t134 = _t133*_t14;
  const double _t135 = _t134*_t55;
  const double _t136 = _t115*_t118;
  const double _t137 = (0.1e1 / _t32);
  const double _t138 = _t137*params->A1;
  const double _t139 = _t52*params->beta1;
  const double _t140 = _t138*_t139;
  const double _t141 = _t122*_t140;
  const double _t142 = _t136*_t141;
  const double _t143 = _t40*_t59;
  const double _t144 = _t116*_t136;
  const double _t145 = _t143*_t144;
  const double _t146 = xc_powi(_t41, -6);
  const double _t147 = ((params->beta2) * (params->beta2));
  const double _t148 = _t146*_t147;
  const double _t149 = _t148*params->A2;
  const double _t150 = _t149*_t38;
  const double _t151 = _t144*_t150;
  const double _t152 = (0.5e1 / 0.13824e5)*_t26;
  const double _t153 = -_t112*_t114 + _t114*_t135 + (0.1e1 / 0.6912e4)*_t115*_t121 + _t129*_t130 - _t130*_t142 - 0.7e1 / 0.13824e5*_t145*_t26 + _t151*_t152 + _t54*_t70 - _t57 + _t63*_t74 - _t65;
  const double _t154 = my_piecewise3(_t1, 0, _t153*_t67);
  const double _t155 = _t92*params->c;
  const double _t156 = xc_powr(n_s, -26, 3);
  const double _t157 = _t119*params->b;
  const double _t158 = (0.1e1 / 0.6912e4)*_t156*_t157;
  const double _t159 = _t158*sigma_ss;
  const double _t160 = _t127*params->a;
  const double _t161 = (0.1e1 / 0.9216e4)*_t156;
  const double _t162 = _t160*_t161;
  const double _t163 = _t162*sigma_ss;
  const double _t164 = _t118*_t140;
  const double _t165 = _t164*params->a;
  const double _t166 = _t161*_t165;
  const double _t167 = _t166*sigma_ss;
  const double _t168 = _t118*_t143;
  const double _t169 = _t156*params->b;
  const double _t170 = (0.7e1 / 0.13824e5)*_t168*_t169;
  const double _t171 = _t170*sigma_ss;
  const double _t172 = _t118*_t150;
  const double _t173 = (0.5e1 / 0.13824e5)*_t169;
  const double _t174 = _t172*_t173;
  const double _t175 = _t174*sigma_ss;
  const double _t176 = -_t112*_t155 + _t135*_t155 + _t159*lapl_s + _t163*lapl_s - _t167*lapl_s - _t171*lapl_s + _t175*lapl_s;
  const double _t177 = my_piecewise3(_t1, 0, _t176*_t67);
  const double _t178 = xc_powr(n_s, -32, 3);
  const double _t179 = _t119*_t178;
  const double _t180 = _t126*_t20;
  const double _t181 = _t118*_t178;
  const double _t182 = (0.1e1 / 0.9216e4)*_t181;
  const double _t183 = _t140*_t20;
  const double _t184 = _t143*_t181;
  const double _t185 = _t150*_t181;
  const double _t186 = (0.5e1 / 0.13824e5)*_t20;
  const double _t187 = -_t110*_t76 + _t134*_t76 + (0.1e1 / 0.6912e4)*_t179*_t20 + _t180*_t182 - _t182*_t183 - 0.7e1 / 0.13824e5*_t184*_t20 + _t185*_t186 + _t71 + _t75 - _t77 - _t79;
  const double _t188 = my_piecewise3(_t1, 0, _t187*_t67);
  const double _t189 = _t44*_t83;
  const double _t190 = _t18*params->c;
  const double _t191 = _t69*params->a;
  const double _t192 = (0.5e1 / 0.432e3)*_t92;
  const double _t193 = _t191*_t192;
  const double _t194 = _t110*_t88;
  const double _t195 = _t12*params->c;
  const double _t196 = (0.1e1 / 0.12e2)*_t195;
  const double _t197 = _t23*_t73;
  const double _t198 = _t197*params->b;
  const double _t199 = (0.5e1 / 0.216e3)*_t92;
  const double _t200 = _t198*_t199;
  const double _t201 = _t140*_t95;
  const double _t202 = _t201*_t56;
  const double _t203 = _t101*_t137;
  const double _t204 = _t139*_t203;
  const double _t205 = _t204*_t56;
  const double _t206 = _t143*_t97;
  const double _t207 = _t206*_t64;
  const double _t208 = _t106*_t40;
  const double _t209 = (0.1e1 / 0.48e2)*_t63;
  const double _t210 = _t208*_t209;
  const double _t211 = (0.1e1 / 0.96e2)*_t100*_t123*_t124*_t21*_t22*_t29*lapl_s*params->A1*params->a + (0.5e1 / 0.144e3)*_t105*_t146*_t147*_t21*_t22*_t29*_t38*lapl_s*params->A2*params->b + (0.1e1 / 0.12e2)*_t11*_t131*_t132*_t14*_t3*_t5*_t88*params->A3*params->c + (0.5e1 / 0.72e2)*_t14*_t2*_t3*_t48*_t5*params->A3*params->beta3*params->c - _t190*_t8 - _t193*lapl_s - _t194*_t196 - _t200*lapl_s - _t202*lapl_s - _t205*lapl_s - _t207*lapl_s + (0.1e1 / 0.288e3)*_t21*_t22*_t29*_t42*_t97*lapl_s*params->A2*params->b + (0.5e1 / 0.432e3)*_t21*_t22*_t32*_t52*_t92*lapl_s*params->A1*params->a*params->beta1 + (0.5e1 / 0.216e3)*_t21*_t22*_t58*_t60*_t92*lapl_s*params->A2*params->b*params->beta2 - _t210*lapl_s;
  const double _t212 = my_piecewise3(_t1, 0, _t189*_t66 + _t211*_t67);
  const double _t213 = (0.1e1 / 0.54e2)*_t89;
  const double _t214 = _t213*_t69;
  const double _t215 = (0.1e1 / 0.12e2)*_t7;
  const double _t216 = (0.1e1 / 0.27e2)*_t89;
  const double _t217 = _t197*_t216;
  const double _t218 = _t76*sigma_ss;
  const double _t219 = _t143*_t78;
  const double _t220 = _t219*_t97;
  const double _t221 = (0.1e1 / 0.48e2)*_t72;
  const double _t222 = _t208*_t221;
  const double _t223 = (0.1e1 / 0.96e2)*_t100*_t123*_t124*_t19*_t21*_t22*params->A1*sigma_ss + (0.5e1 / 0.144e3)*_t105*_t146*_t147*_t19*_t21*_t22*_t38*params->A2*sigma_ss + (0.1e1 / 0.12e2)*_t131*_t132*_t14*_t2*_t3*_t5*_t88*params->A3 + (0.1e1 / 0.9e1)*_t14*_t3*_t48*_t5*_t84*params->A3*params->beta3 - _t18*_t87 + (0.1e1 / 0.288e3)*_t19*_t21*_t22*_t42*_t97*params->A2*sigma_ss - _t194*_t215 - _t201*_t218 - _t204*_t218 + (0.1e1 / 0.54e2)*_t21*_t22*_t32*_t52*_t89*params->A1*params->beta1*sigma_ss + (0.1e1 / 0.27e2)*_t21*_t22*_t58*_t60*_t89*params->A2*params->beta2*sigma_ss - _t214*sigma_ss - _t217*sigma_ss - _t220*sigma_ss - _t222*sigma_ss - _t86;
  const double _t224 = my_piecewise3(_t1, 0, _t189*_t80 + _t223*_t67);
  const double _t225 = xc_powr(n_s, -4, 3);
  const double _t226 = (0.1e1 / 0.30e2)*_t225;
  const double _t227 = _t108*_t44;
  const double _t228 = (0.1e1 / 0.5e1)*_t82;
  const double _t229 = _t6/xc_powr(n_s, 14, 3);
  const double _t230 = (0.55e2 / 0.81e2)*_t229;
  const double _t231 = _t229*sigma_ss;
  const double _t232 = _t10*_t86 + (0.11e2 / 0.27e2)*_t231;
  const double _t233 = (_t88 * _t88);
  const double _t234 = 0.2e1*_t233;
  const double _t235 = xc_powr(n_s, -22, 3);
  const double _t236 = _t235*_t24;
  const double _t237 = (0.19e2 / 0.324e3)*_t236;
  const double _t238 = _t19*_t28;
  const double _t239 = _t237 + (0.65e2 / 0.2592e4)*_t238;
  const double _t240 = (_t100 * _t100);
  const double _t241 = _t240*params->A1;
  const double _t242 = 0.6e1*_t125;
  const double _t243 = _t241*_t242;
  const double _t244 = _t19*_t37;
  const double _t245 = (0.19e2 / 0.162e3)*_t236 + (0.65e2 / 0.1296e4)*_t244;
  const double _t246 = -_t91 - 0.5e1 / 0.864e3*_t96;
  const double _t247 = _t43*_t97;
  const double _t248 = (0.19e2 / 0.648e3)*_t236;
  const double _t249 = (0.65e2 / 0.5184e4)*_t238 + _t248;
  const double _t250 = _t103*params->A1;
  const double _t251 = (0.65e2 / 0.5184e4)*_t244 + _t248;
  const double _t252 = _t251*_t59;
  const double _t253 = 0.4e1*_t61;
  const double _t254 = _t102*params->beta1;
  const double _t255 = _t137*_t241;
  const double _t256 = (_t105 * _t105);
  const double _t257 = _t256*params->A2;
  const double _t258 = _t148*_t257;
  const double _t259 = _t203*_t254;
  const double _t260 = _t107*_t40;
  const double _t261 = (0.1e1 / 0.72e2)*_t90;
  const double _t262 = -_t261 - 0.5e1 / 0.576e3*_t96;
  const double _t263 = -_t110*_t234 + _t134*_t234 + _t18*_t232 + _t230*sigma_ss - _t232*_t50 + _t239*_t36 + _t243 + _t245*_t73 + _t246*_t247 - _t249*_t250 - _t252*_t253 - _t254*_t255 + 0.20e2*_t258*_t38 - _t259*_t95 - _t260*_t262 - _t260*_t97;
  const double _t264 = my_piecewise3(_t1, 0, -_t226*_t45 + _t227*_t228 + _t263*_t67);
#endif
#if _KMAX >= 3
  const double _t265 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t266 = _t133*_t265;
  const double _t267 = (0.1e1 / 0.384e3)*_t266;
  const double _t268 = ((params->c) * (params->c) * (params->c));
  const double _t269 = _t268/xc_powi(n_s, 5);
  const double _t270 = (0.1e1 / 0.2304e4)*_t115;
  const double _t271 = _t120*_t270;
  const double _t272 = xc_powi(M_PI, -8);
  const double _t273 = _t149*_t272;
  const double _t274 = (0.5e1 / 0.147456e6)*_t273;
  const double _t275 = ((params->b) * (params->b) * (params->b));
  const double _t276 = (lapl_s * lapl_s * lapl_s);
  const double _t277 = xc_powi(n_s, -10);
  const double _t278 = _t276*_t277;
  const double _t279 = _t275*_t278;
  const double _t280 = (0.1e1 / 0.3072e4)*_t129;
  const double _t281 = ((params->beta3) * (params->beta3) * (params->beta3))/(_t16 * _t16 * _t16 * _t16);
  const double _t282 = _t14*_t281;
  const double _t283 = _t282*params->A3;
  const double _t284 = (0.1e1 / 0.384e3)*_t283;
  const double _t285 = _t265*_t284;
  const double _t286 = xc_powr(_t31, -3, 2);
  const double _t287 = _t286*params->A1;
  const double _t288 = _t139*_t287;
  const double _t289 = (0.1e1 / 0.884736e6)*_t288;
  const double _t290 = ((params->a) * (params->a) * (params->a));
  const double _t291 = _t272*_t290;
  const double _t292 = _t278*_t291;
  const double _t293 = (0.1e1 / _t39);
  const double _t294 = _t293*params->beta2;
  const double _t295 = _t294*_t59;
  const double _t296 = (0.5e1 / 0.442368e6)*_t295;
  const double _t297 = _t272*_t279;
  const double _t298 = (0.1e1 / 0.3072e4)*_t142;
  const double _t299 = (0.7e1 / 0.4608e4)*_t145;
  const double _t300 = (0.5e1 / 0.4608e4)*_t151;
  const double _t301 = (0.1e1 / _t31);
  const double _t302 = _t301*params->A1;
  const double _t303 = _t125*_t302;
  const double _t304 = (0.1e1 / 0.294912e6)*_t303;
  const double _t305 = xc_powi(_t34, -5);
  const double _t306 = ((params->beta1) * (params->beta1) * (params->beta1));
  const double _t307 = _t305*_t306;
  const double _t308 = _t138*_t307;
  const double _t309 = (0.1e1 / 0.221184e6)*_t308;
  const double _t310 = ((params->beta2) * (params->beta2) * (params->beta2))/xc_powi(_t41, 7);
  const double _t311 = _t310*params->A2;
  const double _t312 = _t311*_t39;
  const double _t313 = (0.5e1 / 0.221184e6)*_t312;
  const double _t314 = _t267*_t269 - _t269*_t285 + _t271*lapl_s + _t274*_t279 + _t280*lapl_s + _t289*_t292 + _t292*_t304 - _t292*_t309 - _t296*_t297 - _t297*_t313 - _t298*lapl_s - _t299*lapl_s + _t300*lapl_s;
  const double _t315 = my_piecewise3(_t1, 0, _t314*_t67);
  const double _t316 = xc_powi(n_s, -6);
  const double _t317 = _t113*_t316;
  const double _t318 = xc_powi(n_s, -12);
  const double _t319 = _t116*_t318;
  const double _t320 = _t26*_t319;
  const double _t321 = _t274*_t320;
  const double _t322 = _t122*_t26;
  const double _t323 = _t318*_t322;
  const double _t324 = _t272*_t289;
  const double _t325 = _t323*_t324;
  const double _t326 = _t272*_t296;
  const double _t327 = _t320*_t326;
  const double _t328 = _t272*_t304;
  const double _t329 = _t323*_t328;
  const double _t330 = _t272*_t309;
  const double _t331 = _t323*_t330;
  const double _t332 = _t272*_t313;
  const double _t333 = _t320*_t332;
  const double _t334 = _t159 + _t163 - _t167 - _t171 + _t175 + _t267*_t317 - _t285*_t317 + _t321*sigma_ss + _t325*sigma_ss - _t327*sigma_ss + _t329*sigma_ss - _t331*sigma_ss - _t333*sigma_ss;
  const double _t335 = my_piecewise3(_t1, 0, _t334*_t67);
  const double _t336 = xc_powi(n_s, -7);
  const double _t337 = _t336*params->c;
  const double _t338 = xc_powi(n_s, -14);
  const double _t339 = _t20*_t338;
  const double _t340 = _t339*params->b;
  const double _t341 = _t274*_t340;
  const double _t342 = _t339*params->a;
  const double _t343 = _t324*_t342;
  const double _t344 = _t326*_t340;
  const double _t345 = _t328*_t342;
  const double _t346 = _t330*_t342;
  const double _t347 = _t332*_t340;
  const double _t348 = _t158*lapl_s + _t162*lapl_s - _t166*lapl_s - _t170*lapl_s + _t174*lapl_s + _t267*_t337 - _t285*_t337 + _t341*lapl_s + _t343*lapl_s - _t344*lapl_s + _t345*lapl_s - _t346*lapl_s - _t347*lapl_s;
  const double _t349 = my_piecewise3(_t1, 0, _t348*_t67);
  const double _t350 = xc_powi(n_s, -8);
  const double _t351 = (0.1e1 / 0.2304e4)*_t179;
  const double _t352 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t353 = xc_powi(n_s, -16);
  const double _t354 = _t273*_t353;
  const double _t355 = _t352*_t354;
  const double _t356 = (0.1e1 / 0.3072e4)*_t181;
  const double _t357 = _t126*_t356;
  const double _t358 = _t265*_t350;
  const double _t359 = _t272*_t353;
  const double _t360 = _t352*_t359;
  const double _t361 = _t140*_t356;
  const double _t362 = (0.7e1 / 0.4608e4)*_t184;
  const double _t363 = (0.5e1 / 0.4608e4)*_t185;
  const double _t364 = (0.1e1 / 0.294912e6)*_t360;
  const double _t365 = (0.5e1 / 0.221184e6)*_t360;
  const double _t366 = _t267*_t350 - _t284*_t358 + _t289*_t360 - _t296*_t360 + _t303*_t364 - _t309*_t360 - _t312*_t365 + _t351*sigma_ss + (0.5e1 / 0.147456e6)*_t355 + _t357*sigma_ss - _t361*sigma_ss - _t362*sigma_ss + _t363*sigma_ss;
  const double _t367 = my_piecewise3(_t1, 0, _t366*_t67);
  const double _t368 = xc_powr(n_s, -23, 3);
  const double _t369 = (0.5e1 / 0.5184e4)*_t368;
  const double _t370 = _t128*_t26;
  const double _t371 = (0.5e1 / 0.6912e4)*_t368;
  const double _t372 = _t134*_t23;
  const double _t373 = _t116*_t26;
  const double _t374 = _t368*_t373;
  const double _t375 = (0.25e2 / 0.10368e5)*_t374;
  const double _t376 = (0.1e1 / 0.96e2)*_t88;
  const double _t377 = _t283*_t376;
  const double _t378 = _t114*_t23;
  const double _t379 = _t295*_t97;
  const double _t380 = _t144*_t26;
  const double _t381 = (0.1e1 / 0.4608e4)*_t380;
  const double _t382 = _t106*_t294;
  const double _t383 = _t203*_t307;
  const double _t384 = _t118*_t322;
  const double _t385 = _t270*_t384;
  const double _t386 = _t105*_t312;
  const double _t387 = (0.5e1 / 0.2304e4)*_t386;
  const double _t388 = (0.1e1 / 0.9216e4)*_t100*_t115*_t117*_t122*_t123*_t124*_t26*_t3*_t301*params->A1 + (0.1e1 / 0.27648e5)*_t100*_t115*_t117*_t122*_t26*_t286*_t3*_t52*params->A1*params->beta1 + (0.1e1 / 0.96e2)*_t100*_t123*_t124*_t21*_t22*_t29*params->A1*params->a + (0.25e2 / 0.13824e5)*_t105*_t115*_t116*_t117*_t146*_t147*_t26*_t3*params->A2 + (0.5e1 / 0.144e3)*_t105*_t146*_t147*_t21*_t22*_t29*_t38*params->A2*params->b + (0.1e1 / 0.96e2)*_t113*_t131*_t132*_t21*_t22*_t29*_t88*params->A3 - _t113*_t192*_t372 + (0.5e1 / 0.432e3)*_t113*_t21*_t22*_t48*_t92*params->A3*params->beta3 + (0.5e1 / 0.13824e5)*_t115*_t116*_t117*_t146*_t147*_t26*_t3*_t97*params->A2 + (0.1e1 / 0.9216e4)*_t115*_t117*_t122*_t123*_t124*_t26*_t3*_t301*_t95*params->A1 + (0.1e1 / 0.27648e5)*_t115*_t117*_t122*_t26*_t286*_t3*_t52*_t95*params->A1*params->beta1 + (0.35e2 / 0.10368e5)*_t116*_t117*_t26*_t3*_t368*_t39*_t58*params->A2*params->beta2 + (0.5e1 / 0.6912e4)*_t117*_t122*_t137*_t26*_t3*_t368*_t52*params->A1*params->beta1 - _t121*_t369 - _t172*_t375 - _t193 - _t200 - _t202 - _t205 - _t207 + (0.1e1 / 0.288e3)*_t21*_t22*_t29*_t42*_t97*params->A2*params->b + (0.5e1 / 0.432e3)*_t21*_t22*_t32*_t52*_t92*params->A1*params->a*params->beta1 + (0.5e1 / 0.216e3)*_t21*_t22*_t58*_t60*_t92*params->A2*params->b*params->beta2 - _t210 - _t370*_t371 - _t377*_t378 - _t379*_t381 - _t380*_t387 - _t381*_t382 - _t383*_t385;
  const double _t389 = my_piecewise3(_t1, 0, _t153*_t189 + _t388*_t67);
  const double _t390 = _t110*_t72;
  const double _t391 = (0.13e2 / 0.864e3)*params->c;
  const double _t392 = xc_powr(n_s, -29, 3);
  const double _t393 = _t392*sigma_ss;
  const double _t394 = (0.13e2 / 0.10368e5)*_t157;
  const double _t395 = _t393*_t394;
  const double _t396 = (0.13e2 / 0.13824e5)*_t160;
  const double _t397 = _t393*_t396;
  const double _t398 = _t134*_t72;
  const double _t399 = _t133*_t376;
  const double _t400 = (0.13e2 / 0.13824e5)*_t165;
  const double _t401 = _t393*_t400;
  const double _t402 = (0.91e2 / 0.20736e5)*_t168;
  const double _t403 = lapl_s*params->b;
  const double _t404 = _t393*_t403;
  const double _t405 = (0.65e2 / 0.20736e5)*_t172;
  const double _t406 = _t149*_t97;
  const double _t407 = _t406*lapl_s;
  const double _t408 = _t118*sigma_ss;
  const double _t409 = _t173*_t408;
  const double _t410 = _t169*_t408;
  const double _t411 = _t105*_t149;
  const double _t412 = (0.25e2 / 0.13824e5)*_t411;
  const double _t413 = _t410*_t412;
  const double _t414 = _t155*_t23;
  const double _t415 = _t287*_t95;
  const double _t416 = _t139*_t415;
  const double _t417 = (0.1e1 / 0.27648e5)*_t416;
  const double _t418 = lapl_s*params->a;
  const double _t419 = _t408*_t418;
  const double _t420 = _t156*_t419;
  const double _t421 = _t139*_t286;
  const double _t422 = _t101*_t421;
  const double _t423 = (0.1e1 / 0.27648e5)*_t422;
  const double _t424 = (0.1e1 / 0.4608e4)*_t410;
  const double _t425 = _t379*_t424;
  const double _t426 = _t382*_t424;
  const double _t427 = _t303*_t95;
  const double _t428 = _t161*_t419;
  const double _t429 = _t125*_t301;
  const double _t430 = _t101*_t429;
  const double _t431 = (0.1e1 / 0.2304e4)*_t383;
  const double _t432 = _t156*_t431;
  const double _t433 = _t387*_t410;
  const double _t434 = _t155*_t23*_t399 - _t377*_t414 + _t390*_t391 - _t391*_t398 - _t395*lapl_s - _t397*lapl_s + _t401*lapl_s + _t402*_t404 - _t404*_t405 + _t407*_t409 + _t413*lapl_s + _t417*_t420 - _t419*_t432 + _t420*_t423 - _t425*lapl_s - _t426*lapl_s + _t427*_t428 + _t428*_t430 - _t433*lapl_s;
  const double _t435 = my_piecewise3(_t1, 0, _t176*_t189 + _t434*_t67);
  const double _t436 = xc_powr(n_s, -35, 3);
  const double _t437 = _t119*_t436;
  const double _t438 = (0.1e1 / 0.648e3)*_t20;
  const double _t439 = _t118*_t436;
  const double _t440 = (0.1e1 / 0.864e3)*_t439;
  const double _t441 = _t213*_t23;
  const double _t442 = _t216*_t23;
  const double _t443 = _t101*_t125;
  const double _t444 = (0.1e1 / 0.96e2)*_t72;
  const double _t445 = _t443*_t444;
  const double _t446 = _t20*_t439;
  const double _t447 = (0.7e1 / 0.1296e4)*_t446;
  const double _t448 = (0.5e1 / 0.1296e4)*_t446;
  const double _t449 = _t149*_t181;
  const double _t450 = _t449*_t97;
  const double _t451 = _t105*_t449;
  const double _t452 = (0.25e2 / 0.13824e5)*_t20;
  const double _t453 = _t140*_t76;
  const double _t454 = _t105*_t150;
  const double _t455 = (0.5e1 / 0.144e3)*_t72;
  const double _t456 = _t181*_t20;
  const double _t457 = (0.1e1 / 0.27648e5)*_t456;
  const double _t458 = (0.1e1 / 0.4608e4)*_t456;
  const double _t459 = _t182*_t20;
  const double _t460 = (0.1e1 / 0.2304e4)*_t181;
  const double _t461 = _t20*_t460;
  const double _t462 = (0.5e1 / 0.2304e4)*_t456;
  const double _t463 = _t111*_t213 - _t134*_t441 + _t143*_t447 - _t150*_t448 - _t180*_t440 + _t183*_t440 + _t186*_t450 - _t204*_t76 - _t214 - _t217 - _t220 - _t222 + _t247*_t76 - _t377*_t72 - _t379*_t458 - _t382*_t458 - _t383*_t461 - _t386*_t462 + _t399*_t72 + _t416*_t457 + _t422*_t457 + _t427*_t459 + _t430*_t459 - _t437*_t438 + _t441*_t53 + _t442*_t62 + _t445 + _t451*_t452 - _t453*_t95 + _t454*_t455;
  const double _t464 = my_piecewise3(_t1, 0, _t187*_t189 + _t463*_t67);
  const double _t465 = _t226*_t44;
  const double _t466 = _t228*_t44;
  const double _t467 = (0.65e2 / 0.1296e4)*_t19*_t191;
  const double _t468 = _t194*params->c;
  const double _t469 = (0.5e1 / 0.18e2)*_t7;
  const double _t470 = _t110*_t232;
  const double _t471 = (0.1e1 / 0.4e1)*_t233;
  const double _t472 = _t133*_t471;
  const double _t473 = _t72*params->b;
  const double _t474 = (0.65e2 / 0.648e3)*_t473;
  const double _t475 = _t474*_t73;
  const double _t476 = _t23*_t247;
  const double _t477 = _t192*_t476*params->b;
  const double _t478 = _t246*_t43;
  const double _t479 = _t23*_t478;
  const double _t480 = _t199*params->b;
  const double _t481 = _t479*_t480;
  const double _t482 = _t245*_t43;
  const double _t483 = (0.1e1 / 0.288e3)*_t63;
  const double _t484 = _t482*_t483;
  const double _t485 = _t53*params->a;
  const double _t486 = (0.65e2 / 0.1296e4)*_t72;
  const double _t487 = _t485*_t486;
  const double _t488 = _t474*_t62;
  const double _t489 = _t23*_t443;
  const double _t490 = (0.5e1 / 0.72e2)*_t92;
  const double _t491 = _t490*params->a;
  const double _t492 = _t489*_t491;
  const double _t493 = (0.1e1 / 0.96e2)*_t54;
  const double _t494 = _t23*_t249;
  const double _t495 = _t126*_t494;
  const double _t496 = _t493*_t495;
  const double _t497 = (0.5e1 / 0.72e2)*_t258;
  const double _t498 = _t497*_t63;
  const double _t499 = _t134*_t88;
  const double _t500 = _t499*params->c;
  const double _t501 = _t134*_t232;
  const double _t502 = _t283*_t471;
  const double _t503 = _t192*_t23;
  const double _t504 = _t201*params->a;
  const double _t505 = _t503*_t504;
  const double _t506 = _t23*_t92;
  const double _t507 = _t506*params->a;
  const double _t508 = (0.5e1 / 0.108e3)*_t507;
  const double _t509 = _t204*_t508;
  const double _t510 = _t23*_t480;
  const double _t511 = _t510*lapl_s;
  const double _t512 = _t262*_t59;
  const double _t513 = _t40*_t512;
  const double _t514 = (0.35e2 / 0.216e3)*_t208;
  const double _t515 = _t403*_t506;
  const double _t516 = (0.25e2 / 0.108e3)*_t454;
  const double _t517 = _t140*_t56;
  const double _t518 = _t249*_t517;
  const double _t519 = _t239*_t517;
  const double _t520 = _t252*_t40;
  const double _t521 = _t209*_t520;
  const double _t522 = _t143*_t245;
  const double _t523 = _t522*_t64;
  const double _t524 = _t150*_t251;
  const double _t525 = (0.5e1 / 0.144e3)*_t63;
  const double _t526 = _t524*_t525;
  const double _t527 = _t411*_t525;
  const double _t528 = _t527*_t97;
  const double _t529 = _t262*_t527;
  const double _t530 = _t241*_t421;
  const double _t531 = _t530*_t56;
  const double _t532 = _t241*_t429;
  const double _t533 = _t23*_t493;
  const double _t534 = _t532*_t533;
  const double _t535 = _t255*_t307;
  const double _t536 = _t23*_t54;
  const double _t537 = (0.1e1 / 0.24e2)*_t536;
  const double _t538 = _t535*_t537;
  const double _t539 = _t257*_t310;
  const double _t540 = _t39*_t539;
  const double _t541 = (0.5e1 / 0.24e2)*_t63;
  const double _t542 = _t540*_t541;
  const double _t543 = _t101*_t95;
  const double _t544 = _t421*_t543;
  const double _t545 = _t544*_t56;
  const double _t546 = _t246*_t379;
  const double _t547 = _t546*_t64;
  const double _t548 = _t382*_t64;
  const double _t549 = _t548*_t97;
  const double _t550 = _t262*_t548;
  const double _t551 = _t429*_t543;
  const double _t552 = _t533*_t551;
  const double _t553 = _t190*_t86 + _t195*_t472 - _t195*_t502 - _t196*_t470 + _t196*_t501 + _t206*_t511 + _t467*lapl_s + _t468*_t469 - _t469*_t500 + _t475*lapl_s - _t477*lapl_s - _t481*lapl_s + _t484*lapl_s - _t487*lapl_s - _t488*lapl_s - _t492*lapl_s + _t496*lapl_s + _t498*lapl_s + _t505*lapl_s + _t509*lapl_s - _t51*_t86 + _t511*_t513 + _t514*_t515 - _t515*_t516 - _t518*lapl_s - _t519*lapl_s - _t521*lapl_s - _t523*lapl_s + _t526*lapl_s + _t528*lapl_s + _t529*lapl_s + _t531*lapl_s + _t534*lapl_s - _t538*lapl_s - _t542*lapl_s + _t545*lapl_s - _t547*lapl_s - _t549*lapl_s - _t550*lapl_s + _t552*lapl_s;
  const double _t554 = my_piecewise3(_t1, 0, _t211*_t466 - _t465*_t66 + _t553*_t67);
  const double _t555 = (0.11e2 / 0.27e2)*_t229;
  const double _t556 = (0.19e2 / 0.162e3)*_t235;
  const double _t557 = _t556*_t69;
  const double _t558 = (0.4e1 / 0.9e1)*_t85;
  const double _t559 = _t110*_t215;
  const double _t560 = (0.19e2 / 0.81e2)*_t235;
  const double _t561 = _t197*_t560;
  const double _t562 = _t213*_t476;
  const double _t563 = _t442*_t478;
  const double _t564 = _t482*_t76;
  const double _t565 = _t23*_t556;
  const double _t566 = _t53*_t565;
  const double _t567 = _t23*_t62;
  const double _t568 = _t560*_t567;
  const double _t569 = (0.1e1 / 0.9e1)*_t89;
  const double _t570 = _t489*_t569;
  const double _t571 = _t126*sigma_ss;
  const double _t572 = _t249*_t444;
  const double _t573 = _t497*_t72;
  const double _t574 = _t140*sigma_ss;
  const double _t575 = _t574*_t95;
  const double _t576 = _t23*_t89;
  const double _t577 = (0.2e1 / 0.27e2)*_t576;
  const double _t578 = _t204*_t577;
  const double _t579 = _t442*sigma_ss;
  const double _t580 = (0.7e1 / 0.27e2)*_t576;
  const double _t581 = _t208*_t580;
  const double _t582 = (0.10e2 / 0.27e2)*_t576;
  const double _t583 = _t454*_t582;
  const double _t584 = _t140*_t218;
  const double _t585 = _t221*_t520;
  const double _t586 = _t219*_t245;
  const double _t587 = _t455*_t524;
  const double _t588 = _t411*_t455;
  const double _t589 = _t588*_t97;
  const double _t590 = _t262*_t588;
  const double _t591 = _t444*_t532;
  const double _t592 = (0.1e1 / 0.24e2)*_t72;
  const double _t593 = _t535*_t592;
  const double _t594 = (0.5e1 / 0.24e2)*_t72;
  const double _t595 = _t540*_t594;
  const double _t596 = _t546*_t78;
  const double _t597 = _t382*_t78;
  const double _t598 = _t597*_t97;
  const double _t599 = _t262*_t597;
  const double _t600 = _t444*_t551;
  const double _t601 = _t18*_t555 + _t194*_t558 + _t206*_t579 + _t215*_t501 + _t218*_t530 + _t218*_t544 + _t230 - _t232*_t559 - _t239*_t584 - _t249*_t584 + _t441*_t575 + _t472*_t7 - _t499*_t558 - _t50*_t555 - _t502*_t7 + _t513*_t579 + _t557*sigma_ss + _t561*sigma_ss - _t562*sigma_ss - _t563*sigma_ss + _t564*sigma_ss - _t566*sigma_ss - _t568*sigma_ss - _t570*sigma_ss + _t571*_t572 + _t573*sigma_ss + _t578*sigma_ss + _t581*sigma_ss - _t583*sigma_ss - _t585*sigma_ss - _t586*sigma_ss + _t587*sigma_ss + _t589*sigma_ss + _t590*sigma_ss + _t591*sigma_ss - _t593*sigma_ss - _t595*sigma_ss - _t596*sigma_ss - _t598*sigma_ss - _t599*sigma_ss + _t600*sigma_ss;
  const double _t602 = my_piecewise3(_t1, 0, _t223*_t466 - _t465*_t80 + _t601*_t67);
  const double _t603 = xc_powr(n_s, -7, 3);
  const double _t604 = (0.2e1 / 0.45e2)*_t603;
  const double _t605 = (0.1e1 / 0.10e2)*_t225;
  const double _t606 = _t263*_t44;
  const double _t607 = (0.3e1 / 0.10e2)*_t82;
  const double _t608 = _t6/xc_powr(n_s, 17, 3);
  const double _t609 = (0.770e3 / 0.243e3)*_t608;
  const double _t610 = _t608*sigma_ss;
  const double _t611 = -_t10*_t230 - 0.154e3 / 0.81e2*_t610;
  const double _t612 = (_t88 * _t88 * _t88);
  const double _t613 = xc_powr(n_s, -25, 3);
  const double _t614 = _t24*_t613;
  const double _t615 = (0.209e3 / 0.486e3)*_t614;
  const double _t616 = _t28*_t89;
  const double _t617 = -_t615 - 0.65e2 / 0.486e3*_t616;
  const double _t618 = 0.2e1*_t110;
  const double _t619 = _t618*_t88;
  const double _t620 = _t10*_t85;
  const double _t621 = (0.22e2 / 0.27e2)*_t231 + (0.10e2 / 0.27e2)*_t620;
  const double _t622 = _t612*params->A3;
  const double _t623 = _t37*_t89;
  const double _t624 = -0.209e3 / 0.243e3*_t614 - 0.65e2 / 0.243e3*_t623;
  const double _t625 = _t237 + (0.65e2 / 0.2592e4)*_t244;
  const double _t626 = (0.209e3 / 0.972e3)*_t614;
  const double _t627 = -0.65e2 / 0.972e3*_t616 - _t626;
  const double _t628 = -0.65e2 / 0.972e3*_t623 - _t626;
  const double _t629 = _t253*_t59;
  const double _t630 = (_t99 * _t99 * _t99);
  const double _t631 = _t254*_t630;
  const double _t632 = (_t100 * _t100 * _t100);
  const double _t633 = 0.24e2*_t307;
  const double _t634 = _t632*_t633;
  const double _t635 = (_t105 * _t105 * _t105);
  const double _t636 = _t635*params->A2;
  const double _t637 = 0.120e3*_t310;
  const double _t638 = _t39*_t637;
  const double _t639 = _t138*_t254;
  const double _t640 = _t639*_t95;
  const double _t641 = _t203*_t239;
  const double _t642 = 0.4e1*_t97;
  const double _t643 = 0.8e1*_t40;
  const double _t644 = _t252*_t262;
  const double _t645 = (0.19e2 / 0.216e3)*_t236;
  const double _t646 = (0.65e2 / 0.1728e4)*_t244 + _t645;
  const double _t647 = _t106*_t245;
  const double _t648 = _t59*_t642;
  const double _t649 = _t256*_t294;
  const double _t650 = _t59*_t649;
  const double _t651 = 0.4e1*_t262;
  const double _t652 = _t254*_t286;
  const double _t653 = _t101*_t99;
  const double _t654 = _t652*_t653;
  const double _t655 = _t246*_t294;
  const double _t656 = _t107*_t97;
  const double _t657 = 0.6e1*_t100*_t123*_t124*_t239*params->A1 + 0.6e1*_t100*_t123*_t124*_t249*params->A1 + 0.20e2*_t105*_t146*_t147*_t251*_t38*params->A2 + 0.20e2*_t105*_t146*_t147*_t38*_t625*params->A2 + 0.6e1*_t123*_t124*_t240*_t301*_t95*params->A1 + 0.6e1*_t123*_t124*_t301*_t632*params->A1 + 0.2e1*_t131*_t132*_t14*_t232*_t88*params->A3 + 0.2e1*_t131*_t132*_t14*_t621*_t88*params->A3 + 0.6e1*_t131*_t132*_t612*params->A3 - _t138*_t634 - 0.6e1*_t139*_t641 + 0.20e2*_t146*_t147*_t246*_t256*params->A2 + 0.20e2*_t146*_t147*_t256*_t262*params->A2 + 0.20e2*_t146*_t147*_t256*_t97*params->A2 + _t17*_t611*params->A3 - _t232*_t619 + 0.2e1*_t245*_t246*_t42*params->A2 - _t249*_t259 - _t249*_t640 - _t250*_t627 - _t260*_t646 - 0.6e1*_t282*_t622 - _t287*_t631 + _t35*_t617*params->A1 + _t38*_t42*_t624*params->A2 + _t42*_t625*_t97*params->A2 - _t50*_t611 - _t520*_t642 - _t609*sigma_ss - _t619*_t621 - _t628*_t629 - _t636*_t638 - _t643*_t644 - _t643*_t647 - _t648*_t649 - _t650*_t651 - _t654*_t95 - _t655*_t656;
  const double _t658 = my_piecewise3(_t1, 0, -_t227*_t605 + _t45*_t604 + _t606*_t607 + _t657*_t67);
#endif
#if _KMAX >= 4
  const double _t659 = _t281*params->A3;
  const double _t660 = _t118*_t659;
  const double _t661 = _t270*((params->c) * (params->c) * (params->c) * (params->c));
  const double _t662 = _t273*_t275;
  const double _t663 = _t26*_t277;
  const double _t664 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t665 = _t21*_t664;
  const double _t666 = xc_powi(_t41, -8);
  const double _t667 = ((params->beta2) * (params->beta2) * (params->beta2) * (params->beta2));
  const double _t668 = _t666*_t667;
  const double _t669 = _t668*params->A2;
  const double _t670 = (0.35e2 / 0.127401984e9)*_t669;
  const double _t671 = _t665*_t670;
  const double _t672 = (lapl_s * lapl_s * lapl_s * lapl_s)/xc_powr(n_s, 40, 3);
  const double _t673 = _t672*((params->b) * (params->b) * (params->b) * (params->b));
  const double _t674 = xc_powi(_t16, -5);
  const double _t675 = ((params->beta3) * (params->beta3) * (params->beta3) * (params->beta3));
  const double _t676 = _t14*_t674*_t675;
  const double _t677 = _t676*params->A3;
  const double _t678 = _t118*_t677;
  const double _t679 = (0.1e1 / 0.147456e6)*_t288;
  const double _t680 = _t291*_t663;
  const double _t681 = (0.5e1 / 0.73728e5)*_t295;
  const double _t682 = _t272*_t275;
  const double _t683 = _t663*_t682;
  const double _t684 = (0.1e1 / 0.49152e5)*_t303;
  const double _t685 = (0.1e1 / 0.36864e5)*_t308;
  const double _t686 = (0.5e1 / 0.36864e5)*_t312;
  const double _t687 = xc_powr(_t31, -5, 2);
  const double _t688 = _t687*params->A1;
  const double _t689 = _t139*_t688;
  const double _t690 = (0.1e1 / 0.169869312e9)*_t689;
  const double _t691 = _t672*((params->a) * (params->a) * (params->a) * (params->a));
  const double _t692 = _t665*_t691;
  const double _t693 = (0.1e1 / _t60);
  const double _t694 = _t693*params->beta2;
  const double _t695 = _t59*_t694;
  const double _t696 = (0.5e1 / 0.254803968e9)*_t695;
  const double _t697 = _t665*_t673;
  const double _t698 = (0.1e1 / (_t31 * _t31));
  const double _t699 = _t126*_t698;
  const double _t700 = (0.1e1 / 0.56623104e8)*_t699;
  const double _t701 = _t665*_t700;
  const double _t702 = (0.1e1 / 0.63700992e8)*_t287*_t307;
  const double _t703 = xc_powi(_t34, -6);
  const double _t704 = ((params->beta1) * (params->beta1) * (params->beta1) * (params->beta1));
  const double _t705 = _t703*_t704;
  const double _t706 = _t302*_t705;
  const double _t707 = (0.5e1 / 0.127401984e9)*_t706;
  const double _t708 = (0.1e1 / _t38);
  const double _t709 = (0.25e2 / 0.254803968e9)*_t149*_t708;
  const double _t710 = _t293*_t311;
  const double _t711 = (0.25e2 / 0.63700992e8)*_t710;
  const double _t712 = (0.1e1 / 0.2304e4)*_t660;
  const double _t713 = _t268*_t368;
  const double _t714 = _t319*lapl_s;
  const double _t715 = _t273*sigma_ss;
  const double _t716 = _t276/xc_powr(n_s, 46, 3);
  const double _t717 = _t716*sigma_ss;
  const double _t718 = _t275*_t717;
  const double _t719 = (0.1e1 / 0.2304e4)*_t678;
  const double _t720 = _t272*sigma_ss;
  const double _t721 = _t720*lapl_s;
  const double _t722 = _t122*_t318*_t721;
  const double _t723 = _t714*_t720;
  const double _t724 = (0.5e1 / 0.147456e6)*_t295;
  const double _t725 = (0.1e1 / 0.73728e5)*_t308;
  const double _t726 = (0.5e1 / 0.73728e5)*_t312;
  const double _t727 = _t290*_t665;
  const double _t728 = _t717*_t727;
  const double _t729 = _t665*_t718;
  const double _t730 = _t571*_t698;
  const double _t731 = _t113*_t156;
  const double _t732 = xc_powr(n_s, -52, 3);
  const double _t733 = _t20*_t732;
  const double _t734 = _t373*_t733;
  const double _t735 = _t322*_t665;
  const double _t736 = _t733*_t735;
  const double _t737 = _t665*_t734;
  const double _t738 = _t180*_t698;
  const double _t739 = xc_powr(n_s, -58, 3);
  const double _t740 = _t338*_t403*_t720;
  const double _t741 = _t338*params->a;
  const double _t742 = _t352*_t739;
  const double _t743 = _t418*_t742;
  const double _t744 = _t665*_t743;
  const double _t745 = _t665*(sigma_ss * sigma_ss * sigma_ss * sigma_ss)/xc_powr(n_s, 64, 3);
  const double _t746 = _t20*_t359;
  const double _t747 = (0.5e1 / 0.384e3)*_t268*_t316;
  const double _t748 = _t368*lapl_s;
  const double _t749 = _t276/xc_powi(n_s, 11);
  const double _t750 = (0.5e1 / 0.2304e4)*_t748;
  const double _t751 = _t265*_t283;
  const double _t752 = _t376*_t659;
  const double _t753 = _t265*_t752;
  const double _t754 = _t291*_t749;
  const double _t755 = _t682*_t749;
  const double _t756 = (0.35e2 / 0.221184e6)*_t669;
  const double _t757 = _t105*_t297;
  const double _t758 = _t118*_t141;
  const double _t759 = _t116*_t748;
  const double _t760 = _t376*_t677;
  const double _t761 = _t265*_t760;
  const double _t762 = _t689*_t95;
  const double _t763 = (0.1e1 / 0.884736e6)*_t292;
  const double _t764 = _t139*_t687;
  const double _t765 = _t101*_t764;
  const double _t766 = _t695*_t97;
  const double _t767 = (0.1e1 / 0.442368e6)*_t297;
  const double _t768 = _t106*_t694;
  const double _t769 = _t122*_t136;
  const double _t770 = _t769*lapl_s;
  const double _t771 = (0.1e1 / 0.9216e4)*_t770;
  const double _t772 = _t144*lapl_s;
  const double _t773 = (0.1e1 / 0.1536e4)*_t772;
  const double _t774 = _t699*_t95;
  const double _t775 = (0.1e1 / 0.294912e6)*_t292;
  const double _t776 = _t443*_t698;
  const double _t777 = (0.1e1 / 0.221184e6)*_t307*_t415;
  const double _t778 = _t301*_t705;
  const double _t779 = _t101*_t778;
  const double _t780 = (0.5e1 / 0.221184e6)*_t779;
  const double _t781 = _t708*_t97;
  const double _t782 = (0.5e1 / 0.442368e6)*_t781;
  const double _t783 = _t273*_t279;
  const double _t784 = _t105*_t708;
  const double _t785 = (0.5e1 / 0.442368e6)*_t784;
  const double _t786 = _t710*_t97;
  const double _t787 = (0.5e1 / 0.221184e6)*_t786;
  const double _t788 = (0.5e1 / 0.36864e5)*_t710;
  const double _t789 = (0.1e1 / 0.3072e4)*_t770;
  const double _t790 = (0.1e1 / 0.768e3)*_t383;
  const double _t791 = (0.5e1 / 0.768e3)*_t386;
  const double _t792 = (0.1e1 / 0.64e2)*_t113*_t336;
  const double _t793 = xc_powi(n_s, -13);
  const double _t794 = _t373*_t793;
  const double _t795 = _t393*params->b;
  const double _t796 = _t322*_t720*_t793;
  const double _t797 = _t720*_t794;
  const double _t798 = _t105*_t756;
  const double _t799 = _t320*_t720;
  const double _t800 = _t408*params->a;
  const double _t801 = _t156*_t800;
  const double _t802 = _t161*_t800;
  const double _t803 = _t323*_t720;
  const double _t804 = (0.1e1 / 0.884736e6)*_t803;
  const double _t805 = (0.1e1 / 0.442368e6)*_t799;
  const double _t806 = (0.1e1 / 0.294912e6)*_t95;
  const double _t807 = (0.1e1 / 0.294912e6)*_t776;
  const double _t808 = _t320*_t715;
  const double _t809 = _t105*_t788;
  const double _t810 = (0.7e1 / 0.384e3)*params->c;
  const double _t811 = _t392*lapl_s;
  const double _t812 = _t20/xc_powi(n_s, 15);
  const double _t813 = _t403*_t812;
  const double _t814 = _t811*params->b;
  const double _t815 = _t118*lapl_s;
  const double _t816 = _t169*_t815;
  const double _t817 = _t272*lapl_s;
  const double _t818 = _t812*_t817;
  const double _t819 = _t818*params->a;
  const double _t820 = _t272*_t813;
  const double _t821 = _t340*_t817;
  const double _t822 = _t303*params->a;
  const double _t823 = _t815*params->a;
  const double _t824 = _t156*_t823;
  const double _t825 = (0.1e1 / 0.4608e4)*_t816;
  const double _t826 = _t342*_t817;
  const double _t827 = (0.1e1 / 0.884736e6)*_t826;
  const double _t828 = (0.1e1 / 0.442368e6)*_t821;
  const double _t829 = _t161*_t823;
  const double _t830 = _t273*_t340*lapl_s;
  const double _t831 = (0.1e1 / 0.48e2)/xc_powi(n_s, 9);
  const double _t832 = _t352/xc_powi(n_s, 17);
  const double _t833 = (0.1e1 / 0.288e3)*_t439;
  const double _t834 = _t272*_t832;
  const double _t835 = _t105*_t360;
  const double _t836 = _t439*sigma_ss;
  const double _t837 = (0.1e1 / 0.884736e6)*_t360;
  const double _t838 = (0.1e1 / 0.442368e6)*_t360;
  const double _t839 = _t182*sigma_ss;
  const double _t840 = _t181*sigma_ss;
  const double _t841 = (0.1e1 / 0.1536e4)*_t840;
  const double _t842 = (0.5e1 / 0.442368e6)*_t355;
  const double _t843 = _t356*sigma_ss;
  const double _t844 = (0.65e2 / 0.1296e4)*_t113;
  const double _t845 = (0.115e3 / 0.20736e5)*_t156;
  const double _t846 = _t133*_t23;
  const double _t847 = _t846*_t88;
  const double _t848 = _t113*_t490;
  const double _t849 = (0.1e1 / 0.96e2)*_t232;
  const double _t850 = _t846*_t849;
  const double _t851 = _t233*_t659;
  const double _t852 = (0.1e1 / 0.24e2)*_t851;
  const double _t853 = _t156*_t373;
  const double _t854 = _t118*_t375;
  const double _t855 = _t149*_t262;
  const double _t856 = _t118*_t374;
  const double _t857 = _t144*_t251;
  const double _t858 = _t144*_t152;
  const double _t859 = _t149*_t245;
  const double _t860 = (0.35e2 / 0.2304e4)*_t257*_t668;
  const double _t861 = _t283*_t88;
  const double _t862 = _t283*_t849;
  const double _t863 = _t233*_t677;
  const double _t864 = (0.1e1 / 0.24e2)*_t863;
  const double _t865 = _t506*params->b;
  const double _t866 = _t368*_t384;
  const double _t867 = _t294*_t512;
  const double _t868 = _t246*_t295;
  const double _t869 = _t118*_t382;
  const double _t870 = _t136*_t322;
  const double _t871 = (0.1e1 / 0.27648e5)*_t288;
  const double _t872 = _t870*_t871;
  const double _t873 = _t252*_t294;
  const double _t874 = _t245*_t295;
  const double _t875 = _t241*_t764;
  const double _t876 = _t130*_t769;
  const double _t877 = _t303*_t876;
  const double _t878 = _t249*_t308;
  const double _t879 = _t125*_t241*_t698;
  const double _t880 = (0.1e1 / 0.3072e4)*_t870;
  const double _t881 = _t241*_t778;
  const double _t882 = (0.5e1 / 0.2304e4)*_t881;
  const double _t883 = _t293*_t539;
  const double _t884 = (0.5e1 / 0.768e3)*_t883;
  const double _t885 = _t543*_t764;
  const double _t886 = _t246*_t766;
  const double _t887 = (0.1e1 / 0.13824e5)*_t380;
  const double _t888 = _t768*_t887;
  const double _t889 = _t776*_t95;
  const double _t890 = _t286*_t307;
  const double _t891 = _t543*_t890;
  const double _t892 = _t246*_t781;
  const double _t893 = _t149*_t892;
  const double _t894 = _t411*_t858;
  const double _t895 = _t262*_t708;
  const double _t896 = (0.5e1 / 0.2304e4)*_t105;
  const double _t897 = _t380*_t896;
  const double _t898 = _t262*_t710;
  const double _t899 = (0.13e2 / 0.162e3)*_t89*params->c;
  const double _t900 = _t403*sigma_ss;
  const double _t901 = (0.377e3 / 0.41472e5)*_t181*_t418;
  const double _t902 = _t133*params->c;
  const double _t903 = (0.13e2 / 0.144e3)*_t72*_t88;
  const double _t904 = _t118*_t404;
  const double _t905 = (0.65e2 / 0.20736e5)*_t904;
  const double _t906 = _t410*lapl_s;
  const double _t907 = _t409*lapl_s;
  const double _t908 = _t283*params->c;
  const double _t909 = _t393*_t823;
  const double _t910 = _t420*_t871;
  const double _t911 = _t424*lapl_s;
  const double _t912 = _t161*_t408*_t822*lapl_s;
  const double _t913 = (0.1e1 / 0.2304e4)*_t420;
  const double _t914 = _t251*_t312;
  const double _t915 = (0.1e1 / 0.3072e4)*_t420;
  const double _t916 = (0.1e1 / 0.13824e5)*_t906;
  const double _t917 = _t768*_t97;
  const double _t918 = _t411*_t907;
  const double _t919 = _t896*_t906;
  const double _t920 = _t20/xc_powr(n_s, 38, 3);
  const double _t921 = (0.35e2 / 0.2592e4)*_t920;
  const double _t922 = _t232*_t444;
  const double _t923 = _t149*_t448;
  const double _t924 = _t186*_t449;
  const double _t925 = _t23*_t569;
  const double _t926 = _t288*_t457;
  const double _t927 = _t303*_t459;
  const double _t928 = _t20*_t356;
  const double _t929 = (0.1e1 / 0.13824e5)*_t456;
  const double _t930 = _t768*_t929;
  const double _t931 = _t186*_t451;
  const double _t932 = _t105*_t462;
  const double _t933 = _t44*_t604;
  const double _t934 = _t44*_t605;
  const double _t935 = _t44*_t607;
  const double _t936 = _t89*lapl_s;
  const double _t937 = (0.65e2 / 0.243e3)*_t936;
  const double _t938 = (0.10e2 / 0.9e1)*_t85;
  const double _t939 = (0.5e1 / 0.36e2)*_t7*params->c;
  const double _t940 = _t110*_t621;
  const double _t941 = _t196*_t611;
  const double _t942 = (0.5e1 / 0.4e1)*_t233*_t7;
  const double _t943 = _t281*_t622;
  const double _t944 = (0.130e3 / 0.243e3)*_t936;
  const double _t945 = _t473*lapl_s;
  const double _t946 = (0.65e2 / 0.324e3)*_t945;
  const double _t947 = _t43*_t625;
  const double _t948 = _t43*_t624;
  const double _t949 = _t418*_t72;
  const double _t950 = (0.5e1 / 0.144e3)*_t418*_t92;
  const double _t951 = _t126*lapl_s;
  const double _t952 = (0.5e1 / 0.144e3)*_t239*_t507;
  const double _t953 = (0.35e2 / 0.24e2)*_t668;
  const double _t954 = _t636*lapl_s;
  const double _t955 = _t134*_t621;
  const double _t956 = _t133*_t88;
  const double _t957 = (0.1e1 / 0.4e1)*_t195;
  const double _t958 = _t232*_t957;
  const double _t959 = _t621*_t956;
  const double _t960 = _t622*_t676;
  const double _t961 = (0.25e2 / 0.108e3)*_t515;
  const double _t962 = _t143*_t646;
  const double _t963 = (0.5e1 / 0.108e3)*_t515;
  const double _t964 = (0.25e2 / 0.216e3)*_t515;
  const double _t965 = _t150*_t625;
  const double _t966 = _t411*_t961;
  const double _t967 = _t517*lapl_s;
  const double _t968 = _t64*lapl_s;
  const double _t969 = _t40*_t628;
  const double _t970 = _t59*_t969;
  const double _t971 = _t150*_t628;
  const double _t972 = _t525*lapl_s;
  const double _t973 = _t251*_t262;
  const double _t974 = _t149*_t973;
  const double _t975 = _t63*lapl_s;
  const double _t976 = (0.5e1 / 0.72e2)*_t975;
  const double _t977 = _t411*_t976;
  const double _t978 = _t646*lapl_s;
  const double _t979 = _t418*_t503;
  const double _t980 = _t630*_t689;
  const double _t981 = _t533*lapl_s;
  const double _t982 = _t507*lapl_s;
  const double _t983 = _t699*lapl_s;
  const double _t984 = (0.1e1 / 0.48e2)*_t536;
  const double _t985 = _t632*_t706;
  const double _t986 = _t536*lapl_s;
  const double _t987 = _t293*_t310;
  const double _t988 = _t621*_t861;
  const double _t989 = _t415*_t99;
  const double _t990 = _t139*_t989;
  const double _t991 = _t421*_t653;
  const double _t992 = _t382*_t97;
  const double _t993 = (0.5e1 / 0.54e2)*_t515;
  const double _t994 = _t262*_t382;
  const double _t995 = _t106*_t655;
  const double _t996 = _t249*_t56*lapl_s;
  const double _t997 = _t239*_t421;
  const double _t998 = _t101*_t997;
  const double _t999 = _t873*_t97;
  const double _t1000 = (0.1e1 / 0.72e2)*_t294;
  const double _t1001 = _t1000*_t644;
  const double _t1002 = _t625*_t97;
  const double _t1003 = _t1002*_t295;
  const double _t1004 = (0.1e1 / 0.72e2)*_t246*_t874;
  const double _t1005 = _t1000*_t647;
  const double _t1006 = _t494*lapl_s;
  const double _t1007 = _t1006*_t493;
  const double _t1008 = (0.1e1 / 0.32e2)*_t239*_t430;
  const double _t1009 = _t307*_t641;
  const double _t1010 = _t537*lapl_s;
  const double _t1011 = _t256*_t968;
  const double _t1012 = _t512*_t694;
  const double _t1013 = _t541*lapl_s;
  const double _t1014 = _t1013*_t386;
  const double _t1015 = _t879*_t95;
  const double _t1016 = _t241*_t890*_t95;
  const double _t1017 = _t258*_t972;
  const double _t1018 = _t1013*_t883;
  const double _t1019 = _t653*_t95;
  const double _t1020 = _t1019*_t764;
  const double _t1021 = _t246*_t917;
  const double _t1022 = _t698*_t95*_t99;
  const double _t1023 = (0.154e3 / 0.81e2)*_t608;
  const double _t1024 = _t613*sigma_ss;
  const double _t1025 = (0.209e3 / 0.243e3)*_t1024;
  const double _t1026 = (0.22e2 / 0.9e1)*_t229;
  const double _t1027 = (0.2e1 / 0.9e1)*_t85;
  const double _t1028 = _t234*_t85;
  const double _t1029 = (0.418e3 / 0.243e3)*_t1024;
  const double _t1030 = _t235*sigma_ss;
  const double _t1031 = (0.38e2 / 0.81e2)*_t1030;
  const double _t1032 = (0.1e1 / 0.18e2)*_t571;
  const double _t1033 = _t494*_t89;
  const double _t1034 = _t239*_t576;
  const double _t1035 = _t444*_t571;
  const double _t1036 = _t576*sigma_ss;
  const double _t1037 = _t636*sigma_ss;
  const double _t1038 = (0.1e1 / 0.4e1)*_t7;
  const double _t1039 = _t1038*_t232;
  const double _t1040 = _t1030*_t23;
  const double _t1041 = (0.1e1 / 0.18e2)*_t574;
  const double _t1042 = _t577*sigma_ss;
  const double _t1043 = (0.5e1 / 0.27e2)*_t1036;
  const double _t1044 = _t411*sigma_ss;
  const double _t1045 = _t1044*_t582;
  const double _t1046 = _t221*sigma_ss;
  const double _t1047 = _t455*sigma_ss;
  const double _t1048 = (0.5e1 / 0.72e2)*_t72;
  const double _t1049 = _t1044*_t1048;
  const double _t1050 = _t646*sigma_ss;
  const double _t1051 = _t441*sigma_ss;
  const double _t1052 = _t444*sigma_ss;
  const double _t1053 = _t594*sigma_ss;
  const double _t1054 = (0.4e1 / 0.27e2)*_t1036;
  const double _t1055 = _t218*_t249;
  const double _t1056 = _t78*sigma_ss;
  const double _t1057 = _t72*sigma_ss;
  const double _t1058 = _t572*sigma_ss;
  const double _t1059 = _t592*sigma_ss;
  const double _t1060 = _t1056*_t256;
  const double _t1061 = _t1053*_t386;
  const double _t1062 = _t1047*_t258;
  const double _t1063 = _t1053*_t883;
  const double _t1064 = _t10*_t609 + (0.2618e4 / 0.243e3)*_t115*_t6*sigma_ss;
  const double _t1065 = (_t232 * _t232);
  const double _t1066 = (_t88 * _t88 * _t88 * _t88);
  const double _t1067 = _t24/xc_powr(n_s, 28, 3);
  const double _t1068 = _t235*_t28;
  const double _t1069 = (_t249 * _t249);
  const double _t1070 = (_t105 * _t105 * _t105 * _t105);
  const double _t1071 = -0.110e3 / 0.81e2*_t10*_t229 - 0.308e3 / 0.81e2*_t610;
  const double _t1072 = (0.11e2 / 0.9e1)*_t231 + (0.5e1 / 0.9e1)*_t620;
  const double _t1073 = _t235*_t37;
  const double _t1074 = -_t615 - 0.65e2 / 0.486e3*_t623;
  const double _t1075 = (0.5225e4 / 0.2916e4)*_t1067;
  const double _t1076 = (_t99 * _t99 * _t99 * _t99);
  const double _t1077 = (_t100 * _t100 * _t100 * _t100);
  const double _t1078 = _t293*_t637;
  const double _t1079 = 0.6e1*_t233*_t283;
  const double _t1080 = 0.8e1*_t139;
  const double _t1081 = 0.4e1*_t139;
  const double _t1082 = 0.12e2*_t40;
  const double _t1083 = 0.12e2*_t245;
  const double _t1084 = -_t249*_t652;
  const double _t1085 = _t261 + (0.5e1 / 0.576e3)*_t93;
  const double _t1086 = (_t104 * _t104 * _t104)*_t694;
  const double _t1087 = (0.65e2 / 0.1728e4)*_t238 + _t645;
  const double _t1088 = _t255*_t633;
  const double _t1089 = _t257*_t638;
  const double _t1090 = _t1078*_t636;
#endif

  const double f = my_piecewise3(_t1, 0, _t47*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = 0;
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t1, 0, _t68*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t1, 0, _t81*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t1, 0, _t109*n_s + _t47);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = 0;
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t1, 0, _t154*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = 0;
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t1, 0, _t177*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t1, 0, _t188*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = 0;
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t1, 0, _t212*n_s + _t68);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t1, 0, _t224*n_s + _t81);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t1, 0, 0.2e1*_t109 + _t264*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = 0;
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t1, 0, _t315*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = 0;
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t1, 0, _t335*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = 0;
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t1, 0, _t349*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t1, 0, _t367*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = 0;
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t1, 0, _t154 + _t389*n_s);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = 0;
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t1, 0, _t177 + _t435*n_s);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t1, 0, _t188 + _t464*n_s);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = 0;
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t1, 0, 0.2e1*_t212 + _t554*n_s);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t1, 0, 0.2e1*_t224 + _t602*n_s);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t1, 0, 0.3e1*_t264 + _t658*n_s);
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
  const double d4f_dlapl_s4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t67*(_t271 + _t280 - _t298 - _t299 + _t300 - _t660*_t661 + _t661*_t678 + (0.5e1 / 0.24576e5)*_t662*_t663 + _t671*_t673 + _t679*_t680 + _t680*_t684 - _t680*_t685 - _t681*_t683 - _t683*_t686 - _t690*_t692 - _t691*_t701 - _t692*_t702 + _t692*_t707 + _t696*_t697 + _t697*_t709 - _t697*_t711)));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = 0;
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t67*((0.1e1 / 0.294912e6)*_t288*_t722 + (0.1e1 / 0.98304e5)*_t303*_t722 + _t671*_t718 - _t690*_t728 + _t696*_t729 - _t702*_t728 + _t707*_t728 + _t709*_t729 - _t711*_t729 - _t712*_t713 + _t713*_t719 + (0.5e1 / 0.49152e5)*_t714*_t715 - 0.1e1 / 0.56623104e8*_t716*_t727*_t730 - _t722*_t725 - _t723*_t724 - _t723*_t726)));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = 0;
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t67*(_t158 + _t162 - _t166 - _t170 + _t174 + _t321 + _t325 - _t327 + _t329 - _t331 - _t333 + _t341 + _t343 - _t344 + _t345 - _t346 - _t347 + _t671*_t734 - _t690*_t736 + _t696*_t737 - _t702*_t736 + _t707*_t736 + _t709*_t737 - _t711*_t737 - _t712*_t731 + _t719*_t731 - 0.1e1 / 0.56623104e8*_t732*_t735*_t738)));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = 0;
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t67*((0.1e1 / 0.2304e4)*_t117*_t14*_t3*_t392*_t674*_t675*params->A3*params->c + (0.1e1 / 0.98304e5)*_t123*_t124*_t272*_t301*_t338*lapl_s*params->A1*params->a*sigma_ss + (0.25e2 / 0.254803968e9)*_t146*_t147*_t21*_t352*_t664*_t708*_t739*lapl_s*params->A2*params->b + (0.5e1 / 0.49152e5)*_t146*_t147*_t272*_t338*lapl_s*params->A2*params->b*sigma_ss + (0.5e1 / 0.127401984e9)*_t21*_t301*_t352*_t664*_t703*_t704*_t739*lapl_s*params->A1*params->a + (0.5e1 / 0.254803968e9)*_t21*_t352*_t58*_t664*_t693*_t739*lapl_s*params->A2*params->b*params->beta2 + (0.35e2 / 0.127401984e9)*_t21*_t352*_t664*_t666*_t667*_t739*lapl_s*params->A2*params->b + (0.1e1 / 0.294912e6)*_t272*_t286*_t338*_t52*lapl_s*params->A1*params->a*params->beta1*sigma_ss - _t392*_t712*params->c - _t403*_t665*_t711*_t742 - _t690*_t744 - _t701*_t743 - _t702*_t744 - _t721*_t725*_t741 - _t724*_t740 - _t726*_t740)));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t1, 0, n_s*my_piecewise3(_t1, 0, _t67*((0.5e1 / 0.24576e5)*_t20*_t354 + _t351 + _t357 - _t361 - _t362 + _t363 - _t460*_t659 + _t460*_t677 + _t670*_t745 + _t679*_t746 - _t681*_t746 + _t684*_t746 - _t685*_t746 - _t686*_t746 - _t690*_t745 + _t696*_t745 - _t700*_t745 - _t702*_t745 + _t707*_t745 + _t709*_t745 - _t711*_t745)));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = 0;
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t1, 0, _t315 + n_s*my_piecewise3(_t1, 0, _t189*_t314 + _t67*(-0.5e1 / 0.1728e4*_t120*_t748 - _t128*_t750 + (0.5e1 / 0.4608e4)*_t144*_t407 + (0.25e2 / 0.4608e4)*_t144*_t411*lapl_s + (0.35e2 / 0.3456e4)*_t168*_t759 - 0.25e2 / 0.3456e4*_t172*_t759 - _t266*_t747 - _t269*_t753 + _t269*_t761 - 0.5e1 / 0.442368e6*_t288*_t754 - _t292*_t777 + _t292*_t780 + (0.25e2 / 0.221184e6)*_t295*_t755 - _t297*_t787 - 0.5e1 / 0.147456e6*_t303*_t754 + (0.5e1 / 0.110592e6)*_t308*_t754 + (0.25e2 / 0.110592e6)*_t312*_t755 - _t379*_t773 - _t382*_t773 + _t416*_t771 + _t422*_t771 + _t427*_t789 + _t430*_t789 - 0.25e2 / 0.73728e5*_t662*_t749 + _t747*_t751 + _t750*_t758 + _t756*_t757 - _t757*_t788 - _t762*_t763 - _t763*_t765 + _t766*_t767 + _t767*_t768 - _t770*_t790 - _t772*_t791 - _t774*_t775 - _t775*_t776 + _t782*_t783 + _t783*_t785)));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = 0;
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t1, 0, _t335 + n_s*my_piecewise3(_t1, 0, _t189*_t334 + _t67*(-_t266*_t792 - _t272*_t323*_t730*_t806 - 0.1e1 / 0.73728e5*_t288*_t796 + (0.5e1 / 0.36864e5)*_t295*_t797 - 0.1e1 / 0.24576e5*_t303*_t796 + (0.1e1 / 0.18432e5)*_t308*_t796 + (0.5e1 / 0.18432e5)*_t312*_t797 - _t317*_t753 + _t317*_t761 - _t395 - _t397 + _t401 + _t402*_t795 - _t405*_t795 + _t406*_t409 + _t413 + _t417*_t801 + _t423*_t801 - _t425 - _t426 + _t427*_t802 + _t430*_t802 - _t431*_t801 - _t433 - 0.5e1 / 0.12288e5*_t715*_t794 + _t751*_t792 - _t762*_t804 - _t765*_t804 + _t766*_t805 + _t768*_t805 - _t777*_t803 + _t780*_t803 + _t782*_t808 + _t785*_t808 - _t787*_t799 + _t798*_t799 - _t799*_t809 - _t803*_t807)));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = 0;
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t1, 0, _t349 + n_s*my_piecewise3(_t1, 0, _t189*_t348 + _t67*(_t118*_t173*_t407 - _t266*_t350*_t810 - 0.35e2 / 0.73728e5*_t273*_t813 + _t283*_t358*_t810 - 0.7e1 / 0.442368e6*_t288*_t819 + (0.35e2 / 0.221184e6)*_t295*_t820 + (0.7e1 / 0.110592e6)*_t308*_t819 + (0.35e2 / 0.110592e6)*_t312*_t820 - _t337*_t753 + _t337*_t761 - _t379*_t825 - _t382*_t825 - _t387*_t816 - _t394*_t811 - _t396*_t811 + _t400*_t811 + _t402*_t814 - _t405*_t814 + _t412*_t816 + _t417*_t824 + _t423*_t824 + _t427*_t829 + _t430*_t829 - _t432*_t823 - _t738*_t741*_t806*_t817 - _t762*_t827 - _t765*_t827 + _t766*_t828 + _t768*_t828 - _t777*_t826 + _t780*_t826 + _t782*_t830 + _t785*_t830 - _t787*_t821 + _t798*_t821 - _t807*_t826 - _t809*_t821 - 0.7e1 / 0.147456e6*_t818*_t822)));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t1, 0, _t367 + n_s*my_piecewise3(_t1, 0, _t189*_t366 + _t67*((0.7e1 / 0.432e3)*_t143*_t836 - 0.5e1 / 0.432e3*_t150*_t836 - _t266*_t831 - 0.5e1 / 0.9216e4*_t273*_t832 - 0.1e1 / 0.55296e5*_t288*_t834 + (0.5e1 / 0.27648e5)*_t295*_t834 - 0.1e1 / 0.18432e5*_t303*_t834 + (0.1e1 / 0.13824e5)*_t308*_t834 + (0.5e1 / 0.13824e5)*_t312*_t834 - _t358*_t752 + _t358*_t760 - _t360*_t777 - _t364*_t774 - _t364*_t776 + _t365*_t779 - _t365*_t786 - _t379*_t841 - _t382*_t841 + _t416*_t839 + _t422*_t839 + _t427*_t843 + _t430*_t843 - 0.1e1 / 0.216e3*_t437*sigma_ss + (0.5e1 / 0.4608e4)*_t450*sigma_ss + (0.25e2 / 0.4608e4)*_t451*sigma_ss - _t571*_t833 + _t574*_t833 + _t751*_t831 + _t756*_t835 - _t762*_t837 - _t765*_t837 + _t766*_t838 + _t768*_t838 + _t781*_t842 + _t784*_t842 - _t788*_t835 - _t790*_t840 - _t791*_t840)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = 0;
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t1, 0, 0.2e1*_t389 + n_s*my_piecewise3(_t1, 0, -_t153*_t465 + _t388*_t466 + _t67*(_t114*_t850 + (0.115e3 / 0.15552e5)*_t121*_t156 + (0.25e2 / 0.13824e5)*_t149*_t26*_t857 - 0.805e3 / 0.31104e5*_t168*_t853 + (0.575e3 / 0.31104e5)*_t172*_t853 + _t206*_t510 + _t23*_t848*_t861 + _t239*_t872 + _t239*_t877 + _t249*_t872 + _t249*_t877 - 0.5e1 / 0.2304e4*_t26*_t312*_t857 - _t26*_t758*_t845 + _t262*_t888 - _t369*_t384*_t422 + _t370*_t845 - _t371*_t384*_t427 + (0.35e2 / 0.10368e5)*_t374*_t869 - _t378*_t852 - _t378*_t862 + _t378*_t864 + (0.5e1 / 0.3456e4)*_t379*_t856 + _t380*_t860 - _t380*_t884 - _t381*_t873 - _t381*_t874 + (0.5e1 / 0.864e3)*_t383*_t866 - _t385*_t878 - _t385*_t891 + (0.25e2 / 0.864e3)*_t386*_t856 - _t390*_t844 + _t398*_t844 - _t406*_t854 - 0.275e3 / 0.10368e5*_t411*_t856 - 0.5e1 / 0.20736e5*_t416*_t866 - 0.5e1 / 0.1728e4*_t430*_t866 + _t467 + _t475 - _t477 - _t481 + _t484 - _t487 - _t488 - _t492 + _t496 + _t498 + _t505 + _t509 + _t510*_t513 + _t514*_t865 - _t516*_t865 - _t518 - _t519 - _t521 - _t523 + _t526 + _t528 + _t529 + _t531 + _t534 - _t538 - _t542 + _t545 - _t547 - _t549 - _t550 + _t552 + _t781*_t894 - _t786*_t897 - _t847*_t848 - _t854*_t855 + (0.5e1 / 0.10368e5)*_t856*_t867 + (0.5e1 / 0.2592e4)*_t856*_t868 + _t858*_t859 + _t858*_t893 + _t870*_t882 - _t875*_t876 - _t876*_t885 - _t879*_t880 - _t880*_t889 + _t886*_t887 + _t888*_t97 + _t894*_t895 - _t897*_t898)));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = 0;
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t1, 0, 0.2e1*_t435 + n_s*my_piecewise3(_t1, 0, -_t176*_t465 + _t434*_t466 + _t67*(-_t111*_t899 + (0.25e2 / 0.13824e5)*_t149*_t251*_t906 + _t155*_t850 + (0.377e3 / 0.31104e5)*_t179*_t900 - 0.2639e4 / 0.62208e5*_t184*_t900 + (0.1885e4 / 0.62208e5)*_t185*_t900 + _t239*_t910 + _t239*_t912 + _t249*_t910 + _t249*_t912 + _t262*_t768*_t916 + _t372*_t899 + (0.13e2 / 0.6912e4)*_t379*_t904 + (0.13e2 / 0.1728e4)*_t383*_t909 + (0.65e2 / 0.1728e4)*_t386*_t904 + (0.91e2 / 0.20736e5)*_t404*_t869 - _t406*_t905 - 0.715e3 / 0.20736e5*_t411*_t904 - _t414*_t852 - _t414*_t862 + _t414*_t864 - 0.13e2 / 0.41472e5*_t416*_t909 + _t420*_t882 - 0.13e2 / 0.10368e5*_t422*_t909 - 0.13e2 / 0.13824e5*_t427*_t909 - _t428*_t875 - _t428*_t885 - 0.13e2 / 0.3456e4*_t430*_t909 + _t571*_t901 - _t574*_t901 + _t781*_t918 - _t786*_t919 - _t855*_t905 + _t859*_t907 + _t860*_t906 + (0.13e2 / 0.20736e5)*_t867*_t904 + (0.13e2 / 0.5184e4)*_t868*_t904 - _t873*_t911 - _t874*_t911 - _t878*_t913 - _t879*_t915 - _t884*_t906 + _t886*_t916 - _t889*_t915 - _t891*_t913 + _t893*_t907 + _t895*_t918 - _t898*_t919 - _t902*_t903 + _t903*_t908 - 0.5e1 / 0.2304e4*_t906*_t914 + _t916*_t917)));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t1, 0, 0.2e1*_t464 + n_s*my_piecewise3(_t1, 0, -_t187*_t465 + _t463*_t466 + _t67*(-_t111*_t556 + (0.35e2 / 0.1944e4)*_t119*_t920 + _t126*_t572 + _t127*_t921 + _t133*_t922 + _t134*_t565 - _t164*_t921 - 0.245e3 / 0.3888e4*_t168*_t920 + (0.175e3 / 0.3888e4)*_t172*_t920 - _t20*_t427*_t440 + _t201*_t441 + _t206*_t442 - _t239*_t453 + _t239*_t926 + _t239*_t927 + _t245*_t924 - _t249*_t453 + _t249*_t926 + _t249*_t927 + _t251*_t449*_t452 - _t262*_t923 + _t262*_t930 - _t283*_t922 + (0.1e1 / 0.432e3)*_t379*_t446 + _t382*_t447 + (0.1e1 / 0.108e3)*_t383*_t446 + (0.5e1 / 0.108e3)*_t386*_t446 - 0.55e2 / 0.1296e4*_t411*_t446 - 0.1e1 / 0.2592e4*_t416*_t446 - _t422*_t438*_t439 - 0.1e1 / 0.216e3*_t430*_t446 + _t442*_t513 + (0.1e1 / 0.1296e4)*_t446*_t867 + (0.1e1 / 0.324e3)*_t446*_t868 + _t456*_t860 - _t456*_t884 - _t458*_t873 - _t458*_t874 - _t459*_t875 - _t459*_t885 - _t461*_t878 - _t461*_t891 + _t462*_t881 - _t462*_t914 + _t530*_t76 + _t544*_t76 + _t557 + _t561 - _t562 - _t563 + _t564 - _t566 - _t568 - _t569*_t847 - _t570 + _t573 + _t578 + _t581 - _t583 - _t585 - _t586 + _t587 + _t589 + _t590 + _t591 - _t592*_t851 + _t592*_t863 - _t593 - _t595 - _t596 - _t598 - _t599 + _t600 + _t781*_t931 - _t786*_t932 + _t861*_t925 - _t879*_t928 + _t886*_t929 - _t889*_t928 + _t892*_t924 + _t895*_t931 - _t898*_t932 - _t923*_t97 + _t930*_t97)));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = 0;
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t1, 0, 0.3e1*_t554 + n_s*my_piecewise3(_t1, 0, -_t211*_t934 + _t553*_t935 + _t66*_t933 + _t67*(-_t1001*_t975 - _t1003*_t968 - _t1004*_t975 - _t1005*_t975 - 0.1e1 / 0.24e2*_t1006*_t383*_t54 + _t1007*_t427 + _t1007*_t430 + _t1008*_t986 - _t1009*_t1010 - _t1010*_t1016 + _t1011*_t1012 + _t1011*_t766 - _t1014*_t251 - _t1014*_t625 - _t1015*_t984*lapl_s + _t1017*_t781 + _t1017*_t895 - _t1018*_t246 - _t1018*_t262 - _t1018*_t97 + _t1020*_t981 + _t1021*_t968 + _t1022*_t489*_t493*lapl_s - _t110*_t941 + _t134*_t941 + _t140*_t494*_t950 + _t140*_t952*lapl_s - _t143*_t624*_t968 - _t190*_t230 - _t191*_t937 - _t195*_t943 + _t195*_t960 - _t198*_t944 - 0.455e3 / 0.1296e4*_t204*_t949 - _t206*_t474*lapl_s - 0.715e3 / 0.648e3*_t208*_t945 - _t209*_t970*lapl_s + _t23*_t485*_t937 - _t23*_t491*_t551*lapl_s + _t230*_t51 + _t245*_t977 - _t246*_t966 + (0.65e2 / 0.1296e4)*_t247*_t945 + _t251*_t407*_t525 + _t251*_t977 - 0.25e2 / 0.24e2*_t258*_t515 - _t262*_t966 + _t416*_t996 + _t422*_t996 + (0.65e2 / 0.144e3)*_t443*_t949 + (0.325e3 / 0.216e3)*_t454*_t945 - _t468*_t938 + _t470*_t939 + _t478*_t946 - _t482*_t511 + _t483*_t948*lapl_s - _t486*_t504*lapl_s - _t495*_t950 + _t500*_t938 - _t501*_t939 + _t508*_t991*lapl_s + _t511*_t546 - _t511*_t947 + _t511*_t962 - _t513*_t946 + (0.25e2 / 0.12e2)*_t515*_t540 + (0.35e2 / 0.216e3)*_t515*_t650 + _t520*_t961 + _t522*_t963 - _t524*_t964 + _t527*_t892*lapl_s + _t527*_t978 - _t530*_t979 - 0.25e2 / 0.144e3*_t532*_t982 + _t533*_t627*_t951 + _t533*_t630*_t983 + (0.5e1 / 0.12e2)*_t535*_t982 - _t541*_t954*_t987 - _t544*_t979 - _t548*_t978 + _t567*_t944*params->b - _t617*_t967 + _t625*_t977 - _t627*_t967 + _t63*_t953*_t954 - _t632*_t983*_t984 - _t861*_t958 - _t902*_t942 + _t908*_t942 + _t939*_t940 - _t939*_t955 - _t951*_t952 + _t956*_t958 + _t957*_t959 - _t957*_t988 + _t963*_t994 - _t964*_t965 - _t966*_t97 - _t968*_t999 + _t971*_t972 + _t974*_t976 + _t979*_t990 + _t980*_t981 + _t981*_t998 + (0.5e1 / 0.24e2)*_t985*_t986 + _t992*_t993 + _t993*_t995)));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t1, 0, 0.3e1*_t602 + n_s*my_piecewise3(_t1, 0, -_t223*_t934 + _t601*_t935 + _t67*(-_t1001*_t1057 - _t1003*_t1056 - _t1004*_t1057 - _t1005*_t1057 + _t1008*_t1057 - _t1009*_t1059 + _t1012*_t1060 - _t1015*_t1046 - _t1016*_t1059 + _t1020*_t1052 + _t1021*_t1056 + _t1022*_t445*sigma_ss - _t1023*_t18 + _t1023*_t50 + _t1025*_t23*_t53 - _t1025*_t69 - _t1026*_t194 + _t1026*_t499 + _t1027*_t470 - _t1027*_t501 + _t1027*_t940 - _t1027*_t955 - _t1028*_t133 + _t1028*_t283 - _t1029*_t197 + _t1029*_t567 + (0.19e2 / 0.18e2)*_t1030*_t489 - _t1031*_t23*_t513 + _t1031*_t479 - _t1032*_t1033 - _t1032*_t1034 + _t1033*_t1041 + _t1034*_t1041 + _t1035*_t627 + _t1035*_t630*_t698 - 0.5e1 / 0.3e1*_t1036*_t258 - 0.5e1 / 0.18e2*_t1036*_t532 + (0.2e1 / 0.3e1)*_t1036*_t535 + (0.10e2 / 0.3e1)*_t1036*_t540 - _t1037*_t594*_t987 + _t1037*_t72*_t953 + _t1038*_t959 - _t1038*_t988 - _t1039*_t861 + _t1039*_t956 - 0.133e3 / 0.162e3*_t1040*_t204 - 0.209e3 / 0.81e2*_t1040*_t208 + (0.95e2 / 0.27e2)*_t1040*_t454 + _t1042*_t522 + _t1042*_t991 + _t1042*_t994 - _t1043*_t524 - _t1043*_t965 - _t1045*_t246 - _t1045*_t262 - _t1045*_t97 - _t1046*_t970 + _t1047*_t251*_t406 + _t1047*_t971 + _t1048*_t974*sigma_ss + _t1049*_t245 + _t1049*_t251 + _t1049*_t625 + _t1050*_t588 - _t1050*_t597 - _t1051*_t530 - _t1051*_t544 + _t1051*_t990 + _t1052*_t980 + _t1052*_t998 + _t1053*_t985 + _t1054*_t992 + _t1054*_t995 + _t1055*_t416 + _t1055*_t422 - _t1056*_t999 + _t1058*_t427 + _t1058*_t430 - _t1059*_t249*_t383 + _t1060*_t766 - _t1061*_t251 - _t1061*_t625 + _t1062*_t781 + _t1062*_t895 - _t1063*_t246 - _t1063*_t262 - _t1063*_t97 + _t134*_t215*_t611 - _t206*_t23*_t560*sigma_ss + _t218*_t948 - _t219*_t624*sigma_ss - _t221*_t632*_t730 + _t476*_t556*sigma_ss - _t482*_t579 + _t520*_t582*sigma_ss + _t546*_t579 - _t551*_t925*sigma_ss - _t559*_t611 - _t565*_t575 - _t579*_t947 + _t579*_t962 + _t580*_t650*sigma_ss - _t584*_t617 - _t584*_t627 + _t588*_t892*sigma_ss - _t609 - _t7*_t943 + _t7*_t960) + _t80*_t933));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t1, 0, 0.4e1*_t658 + n_s*my_piecewise3(_t1, 0, -0.1e1 / 0.5e1*_t225*_t606 + (0.8e1 / 0.45e2)*_t227*_t603 - 0.14e2 / 0.135e3*_t29*_t45 + (0.2e1 / 0.5e1)*_t44*_t657*_t82 + _t67*(0.6e1*_t100*_t123*_t124*_t239*_t301*_t95*params->A1 + 0.6e1*_t100*_t123*_t124*_t249*_t301*_t95*params->A1 + 0.6e1*_t100*_t123*_t124*_t617*params->A1 + 0.12e2*_t100*_t123*_t124*_t627*params->A1 - 0.12e2*_t1002*_t382 - _t101*_t1081*_t137*_t627 - _t1019*_t1085*_t254*_t687 - _t104*_t246*_t656*_t694 + 0.20e2*_t105*_t1074*_t146*_t147*_t38*params->A2 + 0.20e2*_t105*_t146*_t147*_t246*_t251*params->A2 + 0.40e2*_t105*_t146*_t147*_t246*_t625*params->A2 + 0.40e2*_t105*_t146*_t147*_t251*_t262*params->A2 + 0.20e2*_t105*_t146*_t147*_t251*_t97*params->A2 + 0.20e2*_t105*_t146*_t147*_t262*_t625*params->A2 + 0.40e2*_t105*_t146*_t147*_t38*_t628*params->A2 + 0.20e2*_t105*_t146*_t147*_t625*_t97*params->A2 - _t106*_t1082*_t624 + _t1064*_t17*params->A3 - _t1064*_t50 + 0.2e1*_t1065*_t131*_t132*_t14*params->A3 - _t1065*_t618 + 0.24e2*_t1066*_t14*_t674*_t675*params->A3 - 0.24e2*_t1066*_t281*params->A3 + 0.6e1*_t1069*_t123*_t124*params->A1 - _t1069*_t639 - _t107*_t262*_t294*_t625 - _t1070*_t1078*params->A2 + 0.840e3*_t1070*_t666*_t667*params->A2 + 0.2e1*_t1071*_t131*_t132*_t14*_t88*params->A3 - _t1071*_t619 - _t1072*_t1079 + 0.6e1*_t1072*_t131*_t132*_t233*params->A3 + _t1074*_t42*_t97*params->A2 - _t1076*_t242*_t698*params->A1 + 0.24e2*_t1076*_t286*_t305*_t306*params->A1 - _t1077*_t287*_t633 + 0.120e3*_t1077*_t301*_t703*_t704*params->A1 - _t1079*_t232 - _t1079*_t621 - _t1080*_t138*_t239*_t249 - _t1080*_t203*_t617 - _t1081*_t249*_t989 - _t1082*_t512*_t628 - _t1083*_t520 - _t1083*_t650 - _t1084*_t241 - _t1084*_t543 - _t1085*_t631*_t688 - _t1086*_t59*_t651 - _t1086*_t648 - _t1087*_t1088 + 0.6e1*_t1087*_t123*_t124*_t240*_t301*params->A1 - _t1088*_t239 - _t1088*_t249 - _t1089*_t251 - _t1089*_t625 - _t1089*_t646 - _t1090*_t246 - _t1090*_t262 - _t1090*_t97 + (0.13090e5 / 0.729e3)*_t115*_t3*_t5*sigma_ss + 0.24e2*_t123*_t124*_t239*_t240*_t301*params->A1 + 0.6e1*_t123*_t124*_t239*_t249*params->A1 + 0.6e1*_t123*_t124*_t240*_t249*_t301*params->A1 + 0.6e1*_t123*_t124*_t630*_t698*_t95*params->A1 + 0.6e1*_t123*_t124*_t632*_t698*_t94*params->A1 + 0.2e1*_t131*_t132*_t14*_t232*_t621*params->A3 + 0.4e1*_t131*_t132*_t14*_t611*_t88*params->A3 + 0.6e1*_t131*_t132*_t232*_t233*params->A3 + 0.6e1*_t131*_t132*_t233*_t621*params->A3 + 0.60e2*_t146*_t147*_t245*_t256*params->A2 + 0.20e2*_t146*_t147*_t246*_t256*_t708*_t97*params->A2 + 0.20e2*_t146*_t147*(_t251 * _t251)*_t38*params->A2 + 0.20e2*_t146*_t147*_t251*_t38*_t625*params->A2 + 0.20e2*_t146*_t147*_t256*_t625*params->A2 + 0.40e2*_t146*_t147*_t256*_t646*params->A2 + 0.20e2*_t146*_t147*_t262*_t635*_t708*params->A2 + 0.20e2*_t146*_t147*_t635*_t708*_t97*params->A2 - 0.4e1*_t194*_t611 - _t232*_t618*_t621 - _t243*_t698*(_t94 * _t94) + 0.3e1*_t245*_t42*_t625*params->A2 + 0.3e1*_t246*_t42*_t624*params->A2 - _t249*_t654 - _t250*((0.1235e4 / 0.2916e4)*_t1068 + _t1075) - _t251*_t294*_t656 - _t252*_t642*_t655 - _t260*(-0.209e3 / 0.324e3*_t614 - 0.65e2 / 0.324e3*_t623) + _t35*params->A1*((0.5225e4 / 0.1458e4)*_t1067 + (0.1235e4 / 0.1458e4)*_t1068) + _t38*_t42*params->A2*((0.5225e4 / 0.729e3)*_t1067 + (0.1235e4 / 0.729e3)*_t1073) - 0.8e1*_t382*_t973 - _t415*_t634 - 0.12e2*_t520*_t646 - _t627*_t640 - _t629*((0.1235e4 / 0.2916e4)*_t1073 + _t1075) - 0.8e1*_t646*_t650 - 0.12e2*_t647*_t655 - _t648*_t969 - 0.10e2*_t653*_t997)));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_k_rda_params *params = (const mgga_k_rda_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double la = (lapl != NULL) ? lapl[0] : 0.0;

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, (0.1e1 / 0.2e1)*na, (0.1e1 / 0.4e1)*gaa, (0.1e1 / 0.2e1)*la, 0, _hc0);
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
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[14];
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
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[33];
  const double d3F_dna2_dla = (0.1e1 / 0.4e1)*_hc0[32];
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
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[68];
  const double d4F_dna3_dla = (0.1e1 / 0.8e1)*_hc0[67];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[65];
  const double d4F_dna2_dgaa_dla = (0.1e1 / 0.16e2)*_hc0[64];
  const double d4F_dna2_dla2 = (0.1e1 / 0.8e1)*_hc0[62];
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
  const double d2F_dna2 = _hc0[14];
  const double d2F_dnb2 = _hc1[14];
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
  const double d3F_dna3 = _hc0[34];
  const double d3F_dnb3 = _hc1[34];
  const double d3F_dna2_dgaa = _hc0[33];
  const double d3F_dnb2_dgbb = _hc1[33];
  const double d3F_dna2_dla = _hc0[32];
  const double d3F_dnb2_dlb = _hc1[32];
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
  const double d4F_dna4 = _hc0[69];
  const double d4F_dnb4 = _hc1[69];
  const double d4F_dna3_dgaa = _hc0[68];
  const double d4F_dnb3_dgbb = _hc1[68];
  const double d4F_dna3_dla = _hc0[67];
  const double d4F_dnb3_dlb = _hc1[67];
  const double d4F_dna2_dgaa2 = _hc0[65];
  const double d4F_dnb2_dgbb2 = _hc1[65];
  const double d4F_dna2_dgaa_dla = _hc0[64];
  const double d4F_dnb2_dgbb_dlb = _hc1[64];
  const double d4F_dna2_dla2 = _hc0[62];
  const double d4F_dnb2_dlb2 = _hc1[62];
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