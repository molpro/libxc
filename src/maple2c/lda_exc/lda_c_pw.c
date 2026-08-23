/*
  Generated from python/lda_exc/lda_c_pw.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_pw
*/

#ifndef _LDA_C_PW_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_PW_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_PW_HELPER_BODIES
#include "lda_c_pw.c"
#undef _LDA_C_PW_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_PW_HELPER_BODIES
#include "lda_c_pw.c"
#undef _LDA_C_PW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_PW_HELPER_BODIES
#include "lda_c_pw.c"
#undef _LDA_C_PW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_PW_HELPER_BODIES
#include "lda_c_pw.c"
#undef _LDA_C_PW_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_PW_HELPER_BODIES
#include "lda_c_pw.c"
#undef _LDA_C_PW_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_pw.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_PW_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_zeta_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = (0.1e1 / (-0.2e1 + 0.2e1*M_CBRT2));
  const double _t2 = z + 0.1e1 <= p->zeta_threshold;
  const double _t3 = xc_powr(p->zeta_threshold, 4, 3) - 0.1e1;
  const double _t4 = p->zeta_threshold - 0.1e1;
  const double _t5 = z > _t4;
  const double _t6 = my_piecewise3(_t5, z, _t4);
  const double _t7 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t6));
  const double _t8 = 0.1e1 - z <= p->zeta_threshold;
  const double _t9 = -z;
  const double _t10 = _t9 > _t4;
  const double _t11 = my_piecewise3(_t10, _t9, _t4);
  const double _t12 = xc_expm1((0.4e1 / 0.3e1)*xc_log1p(_t11));
#if _KMAX >= 1
  const double _t13 = my_piecewise3(_t5, 0.1e1, 0);
  const double _t14 = _t6 + 0.1e1;
  const double _t15 = _t7 + 0.1e1;
  const double _t16 = my_piecewise3(_t10, -0.1e1, 0);
  const double _t17 = _t11 + 0.1e1;
  const double _t18 = _t12 + 0.1e1;
#endif

  const double f = _t1*(my_piecewise3(_t2, _t3, _t7) + my_piecewise3(_t8, _t3, _t12));
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.3e1)*_t13*_t15/_t14) + my_piecewise3(_t8, 0, (0.4e1 / 0.3e1)*_t16*_t18/_t17));
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t1*(my_piecewise3(_t2, 0, (0.4e1 / 0.9e1)*(_t13 * _t13)*_t15/(_t14 * _t14)) + my_piecewise3(_t8, 0, (0.4e1 / 0.9e1)*(_t16 * _t16)*_t18/(_t17 * _t17)));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t1*(my_piecewise3(_t2, 0, -0.8e1 / 0.27e2*(_t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, -0.8e1 / 0.27e2*(_t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17)));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t1*(my_piecewise3(_t2, 0, (0.40e2 / 0.81e2)*(_t13 * _t13 * _t13 * _t13)*_t15/(_t14 * _t14 * _t14 * _t14)) + my_piecewise3(_t8, 0, (0.40e2 / 0.81e2)*(_t16 * _t16 * _t16 * _t16)*_t18/(_t17 * _t17 * _t17 * _t17)));
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_k, _KMAX)(const xc_func_type *p, double rs, double zeta, double *out) {
  const lda_c_pw_params *params = (const lda_c_pw_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_zeta_k, _KMAX)(p, zeta, _hc0);
  const double _t1 = params->alpha1[0]*rs;
  const double _t2 = _t1 + 0.1e1;
  const double _t3 = 0.2e1*_t2;
  const double _t4 = pow(rs, 1.5);
  const double _t5 = xc_powr(rs, 1, 2);
  const double _t6 = params->pp[0] + 0.1e1;
  const double _t7 = pow(rs, _t6);
  const double _t8 = _t7*params->beta4[0];
  const double _t9 = _t4*params->beta3[0] + _t5*params->beta1[0] + _t8 + params->beta2[0]*rs;
  const double _t10 = (0.1e1 / (params->a[0]));
  const double _t11 = (0.1e1 / 0.2e1)*_t10;
  const double _t12 = _t11/_t9;
  const double _t13 = params->a[0]*xc_log1p(_t12);
  const double _t14 = -_t13*_t3;
  const double _t15 = (0.1e1 / (params->fz20));
  const double _t16 = params->alpha1[2]*rs;
  const double _t17 = _t15*(_t16 + 0.1e1);
  const double _t18 = 0.2e1*_t17;
  const double _t19 = params->pp[2] + 0.1e1;
  const double _t20 = pow(rs, _t19);
  const double _t21 = _t20*params->beta4[2];
  const double _t22 = _t21 + _t4*params->beta3[2] + _t5*params->beta1[2] + params->beta2[2]*rs;
  const double _t23 = (0.1e1 / (params->a[2]));
  const double _t24 = (0.1e1 / 0.2e1)*_t23;
  const double _t25 = _t24/_t22;
  const double _t26 = params->a[2]*xc_log1p(_t25);
  const double _t27 = _t18*_t26;
  const double _t28 = (zeta * zeta * zeta * zeta);
  const double _t29 = params->alpha1[1]*rs;
  const double _t30 = _t29 + 0.1e1;
  const double _t31 = 0.2e1*_t30;
  const double _t32 = params->pp[1] + 0.1e1;
  const double _t33 = pow(rs, _t32);
  const double _t34 = _t33*params->beta4[1];
  const double _t35 = _t34 + _t4*params->beta3[1] + _t5*params->beta1[1] + params->beta2[1]*rs;
  const double _t36 = (0.1e1 / (params->a[1]));
  const double _t37 = (0.1e1 / 0.2e1)*_t36;
  const double _t38 = _t37/_t35;
  const double _t39 = params->a[1]*xc_log1p(_t38);
  const double _t40 = -_t14 - _t27 - _t31*_t39;
  const double _t41 = _t28*_t40;
#if _KMAX >= 1
  const double _t42 = _hc0[0]*_t40;
  const double _t43 = (zeta * zeta * zeta);
  const double _t44 = 0.4e1*_t43;
  const double _t45 = 0.2e1*params->alpha1[1];
  const double _t46 = _t38 + 0.1e1;
  const double _t47 = (0.1e1 / _t46);
  const double _t48 = _t47/(_t35 * _t35);
  const double _t49 = sqrt(rs);
  const double _t50 = 1.5*_t49;
  const double _t51 = (0.1e1 / _t5);
  const double _t52 = _t51*params->beta1[1];
  const double _t53 = (0.1e1 / rs);
  const double _t54 = _t32*_t34;
  const double _t55 = _t53*_t54;
  const double _t56 = -_t50*params->beta3[1] - 0.1e1 / 0.2e1*_t52 - _t55 - params->beta2[1];
  const double _t57 = _t30*_t56;
  const double _t58 = _t15*params->alpha1[2];
  const double _t59 = 0.2e1*_t58;
  const double _t60 = _t26*_t59;
  const double _t61 = _t25 + 0.1e1;
  const double _t62 = (0.1e1 / _t61);
  const double _t63 = _t62/(_t22 * _t22);
  const double _t64 = _t51*params->beta1[2];
  const double _t65 = _t19*_t21;
  const double _t66 = _t53*_t65;
  const double _t67 = -_t50*params->beta3[2] - 0.1e1 / 0.2e1*_t64 - _t66 - params->beta2[2];
  const double _t68 = _t17*_t67;
  const double _t69 = _t63*_t68;
  const double _t70 = 0.2e1*params->alpha1[0];
  const double _t71 = _t12 + 0.1e1;
  const double _t72 = (0.1e1 / _t71);
  const double _t73 = _t72/(_t9 * _t9);
  const double _t74 = _t51*params->beta1[0];
  const double _t75 = _t6*_t8;
  const double _t76 = _t53*_t75;
  const double _t77 = -_t50*params->beta3[0] - 0.1e1 / 0.2e1*_t74 - _t76 - params->beta2[0];
  const double _t78 = _t2*_t77;
  const double _t79 = -_t13*_t70 - _t73*_t78;
  const double _t80 = -_t39*_t45 - _t48*_t57 - _t60 - _t69 - _t79;
  const double _t81 = _t28*_t80;
#endif
#if _KMAX >= 2
  const double _t82 = (zeta * zeta);
  const double _t83 = 0.12e2*_t82;
  const double _t84 = _t40*_t43;
  const double _t85 = 0.8e1*_hc0[1];
  const double _t86 = _hc0[0]*_t80;
  const double _t87 = _t70*_t77;
  const double _t88 = _t73*_t87;
  const double _t89 = _t59*_t67;
  const double _t90 = _t63*_t89;
  const double _t91 = (0.1e1 / 0.2e1)*_t1 + 0.1e1 / 0.2e1;
  const double _t92 = (0.1e1 / (_t71 * _t71));
  const double _t93 = (0.1e1 / (_t9 * _t9 * _t9 * _t9));
  const double _t94 = _t92*_t93;
  const double _t95 = (_t77 * _t77);
  const double _t96 = _t10*_t95;
  const double _t97 = _t94*_t96;
  const double _t98 = (_t67 * _t67);
  const double _t99 = (0.1e1 / (_t61 * _t61));
  const double _t100 = (0.1e1 / (_t22 * _t22 * _t22 * _t22));
  const double _t101 = _t100*_t99;
  const double _t102 = _t17*_t24;
  const double _t103 = _t101*_t102;
  const double _t104 = _t103*_t98;
  const double _t105 = (0.1e1 / (rs * rs));
  const double _t106 = _t105*_t75;
  const double _t107 = (_t6 * _t6);
  const double _t108 = _t107*_t8;
  const double _t109 = _t105*_t108;
  const double _t110 = xc_powr(rs, -3, 2);
  const double _t111 = _t110*params->beta1[0];
  const double _t112 = (0.1e1 / _t49);
  const double _t113 = 0.75*_t112;
  const double _t114 = (0.1e1 / 0.4e1)*_t111 - _t113*params->beta3[0];
  const double _t115 = _t106 - _t109 + _t114;
  const double _t116 = _t2*_t73;
  const double _t117 = _t115*_t116;
  const double _t118 = _t105*_t65;
  const double _t119 = (_t19 * _t19);
  const double _t120 = _t119*_t21;
  const double _t121 = _t105*_t120;
  const double _t122 = _t110*params->beta1[2];
  const double _t123 = -_t113*params->beta3[2] + (0.1e1 / 0.4e1)*_t122;
  const double _t124 = _t118 - _t121 + _t123;
  const double _t125 = _t17*_t63;
  const double _t126 = _t124*_t125;
  const double _t127 = _t72/(_t9 * _t9 * _t9);
  const double _t128 = 3.0*_t49;
  const double _t129 = _t128*params->beta3[0] + _t74 + 0.2e1*params->beta2[0];
  const double _t130 = -_t129 - 0.2e1*_t76;
  const double _t131 = _t130*_t78;
  const double _t132 = _t127*_t131;
  const double _t133 = _t62/(_t22 * _t22 * _t22);
  const double _t134 = _t128*params->beta3[2] + _t64 + 0.2e1*params->beta2[2];
  const double _t135 = -_t134 - 0.2e1*_t66;
  const double _t136 = _t135*_t68;
  const double _t137 = _t133*_t136;
  const double _t138 = _t45*_t56;
  const double _t139 = -_t91;
  const double _t140 = (0.1e1 / 0.2e1)*_t29 + 0.1e1 / 0.2e1;
  const double _t141 = (0.1e1 / (_t46 * _t46));
  const double _t142 = (0.1e1 / (_t35 * _t35 * _t35 * _t35));
  const double _t143 = _t141*_t142;
  const double _t144 = (_t56 * _t56);
  const double _t145 = _t144*_t36;
  const double _t146 = _t143*_t145;
  const double _t147 = (0.1e1 / 0.2e1)*_t16 + 0.1e1 / 0.2e1;
  const double _t148 = _t23*_t98;
  const double _t149 = _t101*_t148;
  const double _t150 = _t105*_t54;
  const double _t151 = (_t32 * _t32);
  const double _t152 = _t151*_t34;
  const double _t153 = _t105*_t152;
  const double _t154 = _t110*params->beta1[1];
  const double _t155 = -_t113*params->beta3[1] + (0.1e1 / 0.4e1)*_t154;
  const double _t156 = _t150 - _t153 + _t155;
  const double _t157 = _t30*_t48;
  const double _t158 = _t47/(_t35 * _t35 * _t35);
  const double _t159 = _t128*params->beta3[1] + _t52 + 0.2e1*params->beta2[1];
  const double _t160 = -_t159 - 0.2e1*_t55;
  const double _t161 = _t160*_t57;
  const double _t162 = _t117 - _t126 + _t132 - _t137 - _t138*_t48 + _t139*_t97 + _t140*_t146 + _t147*_t149*_t15 - _t156*_t157 - _t158*_t161 + _t88 - _t90;
  const double _t163 = _t162*_t28;
#endif
#if _KMAX >= 3
  const double _t164 = 0.24e2*_t42;
  const double _t165 = _t40*_t82;
  const double _t166 = 0.36e2*_hc0[1];
  const double _t167 = 0.12e2*_hc0[2];
  const double _t168 = _t43*_t80;
  const double _t169 = _hc0[0]*_t162;
  const double _t170 = (0.3e1 / 0.2e1)*_t97*params->alpha1[0];
  const double _t171 = (_t77 * _t77 * _t77);
  const double _t172 = (0.1e1 / ((params->a[0]) * (params->a[0])));
  const double _t173 = (0.1e1 / (_t71 * _t71 * _t71));
  const double _t174 = xc_powi(_t9, -6);
  const double _t175 = _t172*_t173*_t174;
  const double _t176 = _t171*_t175;
  const double _t177 = (0.3e1 / 0.2e1)*_t149*_t58;
  const double _t178 = _t73*params->alpha1[0];
  const double _t179 = 0.3e1*_t115;
  const double _t180 = _t178*_t179;
  const double _t181 = (_t67 * _t67 * _t67);
  const double _t182 = (0.1e1 / ((params->a[2]) * (params->a[2])));
  const double _t183 = (0.1e1 / (_t61 * _t61 * _t61));
  const double _t184 = xc_powi(_t22, -6);
  const double _t185 = _t182*_t183*_t184;
  const double _t186 = _t181*_t185;
  const double _t187 = (0.1e1 / 0.2e1)*_t17;
  const double _t188 = _t186*_t187;
  const double _t189 = _t58*_t63;
  const double _t190 = 0.3e1*_t124;
  const double _t191 = _t189*_t190;
  const double _t192 = _t127*_t130;
  const double _t193 = 0.3e1*_t192;
  const double _t194 = _t77*params->alpha1[0];
  const double _t195 = _t193*_t194;
  const double _t196 = (0.1e1 / _t4);
  const double _t197 = xc_powr(rs, -5, 2);
  const double _t198 = (0.3e1 / 0.8e1)*_t197;
  const double _t199 = (0.1e1 / (rs * rs * rs));
  const double _t200 = 0.2e1*_t199;
  const double _t201 = (_t6 * _t6 * _t6)*_t8;
  const double _t202 = _t199*_t201;
  const double _t203 = 0.3e1*_t107*_t199*_t7*params->beta4[0] + 0.375*_t196*params->beta3[0] - _t198*params->beta1[0] - _t200*_t75 - _t202;
  const double _t204 = _t116*_t203;
  const double _t205 = _t6*params->beta4[0]*pow(rs, params->pp[0]);
  const double _t206 = 6.0*_t49;
  const double _t207 = _t206*params->beta3[0] + 0.2e1*_t74 + 0.4e1*params->beta2[0];
  const double _t208 = -0.4e1*_t205 - _t207;
  const double _t209 = xc_powi(_t9, -5);
  const double _t210 = _t209*_t92;
  const double _t211 = _t11*_t2;
  const double _t212 = _t211*_t95;
  const double _t213 = _t210*_t212;
  const double _t214 = _t208*_t213;
  const double _t215 = -_t129 - 0.2e1*_t205;
  const double _t216 = _t213*_t215;
  const double _t217 = _t133*_t135;
  const double _t218 = _t217*_t58;
  const double _t219 = 0.3e1*_t218*_t67;
  const double _t220 = (_t19 * _t19 * _t19)*_t21;
  const double _t221 = _t199*_t220;
  const double _t222 = 0.3e1*_t119*_t199*_t20*params->beta4[2] + 0.375*_t196*params->beta3[2] - _t198*params->beta1[2] - _t200*_t65 - _t221;
  const double _t223 = _t125*_t222;
  const double _t224 = _t19*params->beta4[2]*pow(rs, params->pp[2]);
  const double _t225 = _t206*params->beta3[2] + 0.2e1*_t64 + 0.4e1*params->beta2[2];
  const double _t226 = -0.4e1*_t224 - _t225;
  const double _t227 = xc_powi(_t22, -5);
  const double _t228 = _t227*_t99;
  const double _t229 = _t102*_t98;
  const double _t230 = _t228*_t229;
  const double _t231 = _t226*_t230;
  const double _t232 = -_t134 - 0.2e1*_t224;
  const double _t233 = _t230*_t232;
  const double _t234 = _t115*_t192;
  const double _t235 = _t234*_t3;
  const double _t236 = 1.5*_t112;
  const double _t237 = (0.1e1 / 0.2e1)*_t111 - _t236*params->beta3[0];
  const double _t238 = 0.2e1*_t106 - 0.2e1*_t109 + _t237;
  const double _t239 = _t127*_t78;
  const double _t240 = _t238*_t239;
  const double _t241 = _t78*_t94;
  const double _t242 = _t11*_t241;
  const double _t243 = _t115*_t242;
  const double _t244 = _t238*_t242;
  const double _t245 = _t124*_t18*_t217;
  const double _t246 = (0.1e1 / 0.2e1)*_t122 - _t236*params->beta3[2];
  const double _t247 = 0.2e1*_t118 - 0.2e1*_t121 + _t246;
  const double _t248 = _t133*_t68;
  const double _t249 = _t247*_t248;
  const double _t250 = _t101*_t68;
  const double _t251 = _t24*_t250;
  const double _t252 = _t124*_t251;
  const double _t253 = _t247*_t251;
  const double _t254 = 4.5*_t49;
  const double _t255 = _t254*params->beta3[0] + (0.3e1 / 0.2e1)*_t74 + 0.3e1*params->beta2[0];
  const double _t256 = -_t255 - 0.3e1*_t76;
  const double _t257 = _t131*_t72*_t93;
  const double _t258 = _t256*_t257;
  const double _t259 = _t254*params->beta3[2] + (0.3e1 / 0.2e1)*_t64 + 0.3e1*params->beta2[2];
  const double _t260 = -_t259 - 0.3e1*_t66;
  const double _t261 = _t100*_t136*_t62;
  const double _t262 = _t260*_t261;
  const double _t263 = (_t56 * _t56 * _t56);
  const double _t264 = (0.1e1 / ((params->a[1]) * (params->a[1])));
  const double _t265 = (0.1e1 / (_t46 * _t46 * _t46));
  const double _t266 = xc_powi(_t35, -6);
  const double _t267 = _t264*_t265*_t266;
  const double _t268 = _t263*_t267;
  const double _t269 = _t48*params->alpha1[1];
  const double _t270 = 0.3e1*_t156;
  const double _t271 = _t158*_t160;
  const double _t272 = _t271*params->alpha1[1];
  const double _t273 = (_t32 * _t32 * _t32)*_t34;
  const double _t274 = _t199*_t273;
  const double _t275 = 0.3e1*_t151*_t199*_t33*params->beta4[1] + 0.375*_t196*params->beta3[1] - _t198*params->beta1[1] - _t200*_t54 - _t274;
  const double _t276 = _t32*params->beta4[1]*pow(rs, params->pp[1]);
  const double _t277 = _t206*params->beta3[1] + 0.2e1*_t52 + 0.4e1*params->beta2[1];
  const double _t278 = -0.4e1*_t276 - _t277;
  const double _t279 = xc_powi(_t35, -5);
  const double _t280 = _t141*_t279;
  const double _t281 = _t30*_t37;
  const double _t282 = _t144*_t281;
  const double _t283 = _t280*_t282;
  const double _t284 = -_t159 - 0.2e1*_t276;
  const double _t285 = (0.1e1 / 0.2e1)*_t154 - _t236*params->beta3[1];
  const double _t286 = 0.2e1*_t150 - 0.2e1*_t153 + _t285;
  const double _t287 = _t158*_t57;
  const double _t288 = _t143*_t57;
  const double _t289 = _t288*_t37;
  const double _t290 = _t254*params->beta3[1] + (0.3e1 / 0.2e1)*_t52 + 0.3e1*params->beta2[1];
  const double _t291 = -_t290 - 0.3e1*_t55;
  const double _t292 = _t142*_t161*_t47;
  const double _t293 = -_t140*_t268 + (0.3e1 / 0.2e1)*_t146*params->alpha1[1] - _t147*_t15*_t186 - _t156*_t271*_t31 + _t156*_t289 - _t157*_t275 - _t170 + _t176*_t91 + _t177 + _t180 - _t191 + _t195 + _t204 - _t214 - _t216 - _t219 - _t223 + _t231 + _t233 + _t235 + _t240 - _t243 - _t244 - _t245 - _t249 + _t252 + _t253 + _t258 - _t262 - _t269*_t270 - 0.3e1*_t272*_t56 + _t278*_t283 + _t283*_t284 - _t286*_t287 + _t286*_t289 - _t291*_t292;
  const double _t294 = _t28*_t293;
#endif
#if _KMAX >= 4
  const double _t295 = _t176*_t70;
  const double _t296 = (0.3e1 / 0.4e1)*_t1 + 0.3e1 / 0.4e1;
  const double _t297 = (_t77 * _t77 * _t77 * _t77)/((_t71 * _t71 * _t71 * _t71)*xc_powi(_t9, 8)*((params->a[0]) * (params->a[0]) * (params->a[0])));
  const double _t298 = _t186*_t59;
  const double _t299 = (_t67 * _t67 * _t67 * _t67)/(xc_powi(_t22, 8)*(_t61 * _t61 * _t61 * _t61)*((params->a[2]) * (params->a[2]) * (params->a[2])));
  const double _t300 = _t211*_t94;
  const double _t301 = (_t115 * _t115)*_t300;
  const double _t302 = _t103*(_t124 * _t124);
  const double _t303 = 0.4e1*_t178*_t203;
  const double _t304 = _t210*_t96;
  const double _t305 = _t304*_t70;
  const double _t306 = _t208*_t305;
  const double _t307 = _t215*_t305;
  const double _t308 = 0.4e1*_t189*_t222;
  const double _t309 = 9.0*_t49;
  const double _t310 = (0.1e1 / 0.2e1)*_t171*_t172*_t173*_t2/xc_powi(_t9, 7);
  const double _t311 = _t310*(-0.6e1*_t205 - _t309*params->beta3[0] - 0.3e1*_t74 - 0.6e1*params->beta2[0]);
  const double _t312 = _t208*_t310;
  const double _t313 = _t215*_t310;
  const double _t314 = _t148*_t228;
  const double _t315 = _t314*_t59;
  const double _t316 = _t226*_t315;
  const double _t317 = _t232*_t315;
  const double _t318 = _t181*_t182*_t183*_t187/xc_powi(_t22, 7);
  const double _t319 = _t318*(-0.6e1*_t224 - _t309*params->beta3[2] - 0.3e1*_t64 - 0.6e1*params->beta2[2]);
  const double _t320 = _t226*_t318;
  const double _t321 = _t232*_t318;
  const double _t322 = 0.8e1*_t234*params->alpha1[0];
  const double _t323 = _t127*_t238;
  const double _t324 = 0.4e1*_t194;
  const double _t325 = _t323*_t324;
  const double _t326 = params->beta4[0]*pow(rs, params->pp[0] - 0.1e1);
  const double _t327 = _t326*_t6;
  const double _t328 = _t107*_t326;
  const double _t329 = (0.1e1 / 0.2e1)*_t175*_t95;
  const double _t330 = _t2*_t329;
  const double _t331 = _t330*(_t114 + _t327 - _t328);
  const double _t332 = _t87*_t94;
  const double _t333 = _t10*_t115;
  const double _t334 = _t332*_t333;
  const double _t335 = _t2*(_t237 + 0.2e1*_t327 - 0.2e1*_t328);
  const double _t336 = _t304*_t335;
  const double _t337 = 3.0*_t112;
  const double _t338 = _t213*(_t111 + 0.4e1*_t327 - 0.4e1*_t328 - _t337*params->beta3[0]);
  const double _t339 = _t329*_t335;
  const double _t340 = 2.25*_t112;
  const double _t341 = (0.3e1 / 0.4e1)*_t111 - _t340*params->beta3[0];
  const double _t342 = _t330*(0.3e1*_t327 - 0.3e1*_t328 + _t341);
  const double _t343 = _t10*_t238;
  const double _t344 = _t332*_t343;
  const double _t345 = 0.8e1*_t124*_t218;
  const double _t346 = _t133*_t247;
  const double _t347 = 0.4e1*_t58*_t67;
  const double _t348 = _t346*_t347;
  const double _t349 = params->beta4[2]*pow(rs, params->pp[2] - 0.1e1);
  const double _t350 = _t19*_t349;
  const double _t351 = _t119*_t349;
  const double _t352 = _t185*_t98;
  const double _t353 = _t187*_t352;
  const double _t354 = _t353*(_t123 + _t350 - _t351);
  const double _t355 = _t101*_t89;
  const double _t356 = _t124*_t23;
  const double _t357 = _t355*_t356;
  const double _t358 = _t230*(_t122 - _t337*params->beta3[2] + 0.4e1*_t350 - 0.4e1*_t351);
  const double _t359 = 0.5625*pow(rs, -2.5);
  const double _t360 = (0.15e2 / 0.16e2)/xc_powr(rs, 7, 2);
  const double _t361 = (0.1e1 / (rs * rs * rs * rs));
  const double _t362 = 0.6e1*_t361;
  const double _t363 = 0.11e2*_t361;
  const double _t364 = _t116*(-_t108*_t363 + _t201*_t362 - _t359*params->beta3[0] + _t360*params->beta1[0] - _t361*(_t6 * _t6 * _t6 * _t6)*_t8 + _t362*_t75);
  const double _t365 = _t17*(_t246 + 0.2e1*_t350 - 0.2e1*_t351);
  const double _t366 = (0.1e1 / 0.2e1)*_t352*_t365;
  const double _t367 = (0.3e1 / 0.4e1)*_t122 - _t340*params->beta3[2];
  const double _t368 = _t353*(0.3e1*_t350 - 0.3e1*_t351 + _t367);
  const double _t369 = _t23*_t247;
  const double _t370 = _t355*_t369;
  const double _t371 = _t314*_t365;
  const double _t372 = _t125*(-_t120*_t363 - (_t19 * _t19 * _t19 * _t19)*_t21*_t361 + _t220*_t362 - _t359*params->beta3[2] + _t360*params->beta1[2] + _t362*_t65);
  const double _t373 = 7.5*_t49;
  const double _t374 = _t174*_t212*_t92;
  const double _t375 = _t374*(-0.5e1*_t205 - _t373*params->beta3[0] - 0.5e1 / 0.2e1*_t74 - 0.5e1*params->beta2[0]);
  const double _t376 = _t208*_t375;
  const double _t377 = _t215*_t375;
  const double _t378 = _t215*_t374*(-0.3e1*_t205 - _t255);
  const double _t379 = _t179*_t2;
  const double _t380 = _t323*_t379;
  const double _t381 = _t256*_t72;
  const double _t382 = _t381*_t93;
  const double _t383 = _t130*_t382;
  const double _t384 = _t324*_t383;
  const double _t385 = _t115*_t238*_t300;
  const double _t386 = _t184*_t229*_t99;
  const double _t387 = _t386*(-0.5e1*_t224 - _t373*params->beta3[2] - 0.5e1 / 0.2e1*_t64 - 0.5e1*params->beta2[2]);
  const double _t388 = _t226*_t387;
  const double _t389 = _t232*_t387;
  const double _t390 = _t232*_t386*(-0.3e1*_t224 - _t259);
  const double _t391 = _t193*_t2*_t203;
  const double _t392 = (0.3e1 / 0.4e1)*_t197;
  const double _t393 = 0.4e1*_t199;
  const double _t394 = 0.6e1*_t107*_t199*_t7*params->beta4[0] + 0.75*_t196*params->beta3[0] - 0.2e1*_t202 - _t392*params->beta1[0] - _t393*_t75;
  const double _t395 = _t239*_t394;
  const double _t396 = _t17*_t190;
  const double _t397 = _t346*_t396;
  const double _t398 = _t260*_t62;
  const double _t399 = _t100*_t398;
  const double _t400 = _t135*_t399;
  const double _t401 = _t347*_t400;
  const double _t402 = _t10*_t203*_t241;
  const double _t403 = _t242*_t394;
  const double _t404 = 0.6e1*_t119*_t199*_t20*params->beta4[2] + 0.75*_t196*params->beta3[2] - 0.2e1*_t221 - _t392*params->beta1[2] - _t393*_t65;
  const double _t405 = _t248*_t404;
  const double _t406 = _t103*_t124*_t247;
  const double _t407 = 0.3e1*_t17*_t217*_t222;
  const double _t408 = _t251*_t404;
  const double _t409 = _t222*_t23*_t250;
  const double _t410 = _t379*_t383;
  const double _t411 = _t238*_t3*_t382*_t77;
  const double _t412 = _t257*(0.3e1*_t106 - 0.3e1*_t109 + _t341);
  const double _t413 = _t131*_t210;
  const double _t414 = _t333*_t413;
  const double _t415 = -_t207 - 0.4e1*_t76;
  const double _t416 = _t210*_t415*_t78;
  const double _t417 = _t11*_t115*_t416;
  const double _t418 = _t343*_t416;
  const double _t419 = _t11*_t238*_t413;
  const double _t420 = _t396*_t400;
  const double _t421 = _t261*(0.3e1*_t118 - 0.3e1*_t121 + _t367);
  const double _t422 = _t18*_t247*_t399*_t67;
  const double _t423 = -_t225 - 0.4e1*_t66;
  const double _t424 = _t228*_t423*_t68;
  const double _t425 = _t124*_t24*_t424;
  const double _t426 = _t136*_t228;
  const double _t427 = _t356*_t426;
  const double _t428 = _t369*_t424;
  const double _t429 = _t24*_t247*_t426;
  const double _t430 = _t131*_t209*_t381*_t415;
  const double _t431 = _t136*_t227*_t398*_t423;
  const double _t432 = _t143*_t281;
  const double _t433 = _t145*_t280;
  const double _t434 = _t433*_t45;
  const double _t435 = (0.1e1 / 0.2e1)*_t263*_t264*_t265*_t30/xc_powi(_t35, 7);
  const double _t436 = _t158*_t286;
  const double _t437 = 0.4e1*_t56*params->alpha1[1];
  const double _t438 = params->beta4[1]*pow(rs, params->pp[1] - 0.1e1);
  const double _t439 = _t32*_t438;
  const double _t440 = _t151*_t438;
  const double _t441 = (0.1e1 / 0.2e1)*_t144*_t267;
  const double _t442 = _t30*_t441;
  const double _t443 = _t138*_t143;
  const double _t444 = _t156*_t36;
  const double _t445 = _t30*(_t285 + 0.2e1*_t439 - 0.2e1*_t440);
  const double _t446 = (0.3e1 / 0.4e1)*_t154 - _t340*params->beta3[1];
  const double _t447 = _t286*_t36;
  const double _t448 = _t141*_t266*_t282;
  const double _t449 = _t448*(-0.5e1*_t276 - _t373*params->beta3[1] - 0.5e1 / 0.2e1*_t52 - 0.5e1*params->beta2[1]);
  const double _t450 = _t270*_t30;
  const double _t451 = _t291*_t47;
  const double _t452 = _t142*_t451;
  const double _t453 = _t160*_t452;
  const double _t454 = 0.6e1*_t151*_t199*_t33*params->beta4[1] + 0.75*_t196*params->beta3[1] - 0.2e1*_t274 - _t392*params->beta1[1] - _t393*_t54;
  const double _t455 = _t161*_t280;
  const double _t456 = -_t277 - 0.4e1*_t55;
  const double _t457 = _t280*_t456*_t57;
#endif

  const double f = _hc0[0]*_t27 + _hc0[0]*_t41 + _t14;
  out[0] = f;
#if _KMAX >= 1
  const double df_dzeta = _hc0[1]*_t27 + _hc0[1]*_t41 + _t42*_t44;
  out[1] = df_dzeta;
  const double df_drs = _hc0[0]*_t60 + _hc0[0]*_t69 + _hc0[0]*_t81 + _t79;
  out[2] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_dzeta2 = _hc0[2]*_t27 + _hc0[2]*_t41 + _t42*_t83 + _t84*_t85;
  out[3] = d2f_dzeta2;
  const double d2f_drs_dzeta = _hc0[1]*_t60 + _hc0[1]*_t69 + _hc0[1]*_t81 + _t44*_t86;
  out[4] = d2f_drs_dzeta;
  const double d2f_drs2 = -_hc0[0]*_t104 + _hc0[0]*_t126 + _hc0[0]*_t137 + _hc0[0]*_t163 + _hc0[0]*_t90 - _t117 - _t132 - _t88 + _t91*_t97;
  out[5] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_dzeta3 = _hc0[3]*_t27 + _hc0[3]*_t41 + _t164*zeta + _t165*_t166 + _t167*_t84;
  out[6] = d3f_dzeta3;
  const double d3f_drs_dzeta2 = _hc0[2]*_t60 + _hc0[2]*_t69 + _hc0[2]*_t81 + _t168*_t85 + _t83*_t86;
  out[7] = d3f_drs_dzeta2;
  const double d3f_drs2_dzeta = -_hc0[1]*_t104 + _hc0[1]*_t126 + _hc0[1]*_t137 + _hc0[1]*_t163 + _hc0[1]*_t90 + _t169*_t44;
  out[8] = d3f_drs2_dzeta;
  const double d3f_drs3 = -_hc0[0]*_t177 + _hc0[0]*_t188 + _hc0[0]*_t191 + _hc0[0]*_t219 + _hc0[0]*_t223 - _hc0[0]*_t231 - _hc0[0]*_t233 + _hc0[0]*_t245 + _hc0[0]*_t249 - _hc0[0]*_t252 - _hc0[0]*_t253 + _hc0[0]*_t262 + _hc0[0]*_t294 + _t139*_t176 + _t170 - _t180 - _t195 - _t204 + _t214 + _t216 - _t235 - _t240 + _t243 + _t244 - _t258;
  out[9] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_dzeta4 = 0.96e2*_hc0[1]*_t40*zeta + 0.72e2*_hc0[2]*_t165 + 0.16e2*_hc0[3]*_t84 + _hc0[4]*_t27 + _hc0[4]*_t41 + _t164;
  out[10] = d4f_dzeta4;
  const double d4f_drs_dzeta3 = _hc0[3]*_t60 + _hc0[3]*_t69 + _hc0[3]*_t81 + _t166*_t80*_t82 + _t167*_t168 + 0.24e2*_t86*zeta;
  out[11] = d4f_drs_dzeta3;
  const double d4f_drs2_dzeta2 = -_hc0[2]*_t104 + _hc0[2]*_t126 + _hc0[2]*_t137 + _hc0[2]*_t163 + _hc0[2]*_t90 + _t162*_t43*_t85 + _t169*_t83;
  out[12] = d4f_drs2_dzeta2;
  const double d4f_drs3_dzeta = _hc0[0]*_t293*_t44 - _hc0[1]*_t177 + _hc0[1]*_t188 + _hc0[1]*_t191 + _hc0[1]*_t219 + _hc0[1]*_t223 - _hc0[1]*_t231 - _hc0[1]*_t233 + _hc0[1]*_t245 + _hc0[1]*_t249 - _hc0[1]*_t252 - _hc0[1]*_t253 + _hc0[1]*_t262 + _hc0[1]*_t294;
  out[13] = d4f_drs3_dzeta;
  const double d4f_drs4 = -0.3e1 / 0.4e1*_hc0[0]*_t17*_t299 + _hc0[0]*_t28*(_t15*_t299*((0.3e1 / 0.4e1)*_t16 + 0.3e1 / 0.4e1) + (_t156 * _t156)*_t432 - 0.8e1*_t156*_t272 + _t156*_t286*_t432 + _t156*_t37*_t457 - _t157*(-_t152*_t363 + _t273*_t362 - (_t32 * _t32 * _t32 * _t32)*_t34*_t361 - _t359*params->beta3[1] + _t360*params->beta1[1] + _t362*_t54) - _t161*_t279*_t451*_t456 - _t268*_t45 - 0.4e1*_t269*_t275 - 0.3e1*_t271*_t275*_t30 + _t275*_t288*_t36 + _t278*_t434 - _t278*_t435 + _t278*_t449 + _t283*(_t154 - _t337*params->beta3[1] + 0.4e1*_t439 - 0.4e1*_t440) + _t284*_t434 - _t284*_t435 + _t284*_t448*(-0.3e1*_t276 - _t290) + _t284*_t449 - _t286*_t31*_t452*_t56 + _t286*_t37*_t455 - _t287*_t454 + _t289*_t454 - _t292*(0.3e1*_t150 - 0.3e1*_t153 + _t446) + _t295 - _t296*_t297 - _t298 - _t301 + _t302 + _t303 - _t306 - _t307 - _t308 + _t311 + _t312 + _t313 + _t316 + _t317 - _t319 - _t320 - _t321 + _t322 + _t325 + _t331 - _t334 - _t336 - _t338 + _t339 + _t342 - _t344 - _t345 - _t348 - _t354 + _t357 + _t358 + _t364 - _t366 - _t368 + _t370 + _t371 - _t372 - _t376 - _t377 - _t378 + _t380 + _t384 - _t385 + _t388 + _t389 + _t390 + _t391 + _t395 - _t397 - _t401 - _t402 - _t403 - _t405 + _t406 - _t407 + _t408 + _t409 + _t410 + _t411 + _t412 - _t414 - _t417 - _t418 - _t419 - _t420 - _t421 - _t422 + _t425 + _t427 + _t428 + _t429 + _t430 - _t431 + _t433*_t445 - _t435*(-0.6e1*_t276 - _t309*params->beta3[1] - 0.3e1*_t52 - 0.6e1*params->beta2[1]) - _t436*_t437 - _t436*_t450 - _t437*_t453 - _t441*_t445 - _t442*(_t155 + _t439 - _t440) - _t442*(0.3e1*_t439 - 0.3e1*_t440 + _t446) + _t443*_t444 + _t443*_t447 + _t444*_t455 + _t447*_t457 - _t450*_t453 + (_t56 * _t56 * _t56 * _t56)*((0.3e1 / 0.4e1)*_t29 + 0.3e1 / 0.4e1)/(xc_powi(_t35, 8)*(_t46 * _t46 * _t46 * _t46)*((params->a[1]) * (params->a[1]) * (params->a[1])))) + _hc0[0]*_t298 - _hc0[0]*_t302 + _hc0[0]*_t308 - _hc0[0]*_t316 - _hc0[0]*_t317 + _hc0[0]*_t319 + _hc0[0]*_t320 + _hc0[0]*_t321 + _hc0[0]*_t345 + _hc0[0]*_t348 + _hc0[0]*_t354 - _hc0[0]*_t357 - _hc0[0]*_t358 + _hc0[0]*_t366 + _hc0[0]*_t368 - _hc0[0]*_t370 - _hc0[0]*_t371 + _hc0[0]*_t372 - _hc0[0]*_t388 - _hc0[0]*_t389 - _hc0[0]*_t390 + _hc0[0]*_t397 + _hc0[0]*_t401 + _hc0[0]*_t405 - _hc0[0]*_t406 + _hc0[0]*_t407 - _hc0[0]*_t408 - _hc0[0]*_t409 + _hc0[0]*_t420 + _hc0[0]*_t421 + _hc0[0]*_t422 - _hc0[0]*_t425 - _hc0[0]*_t427 - _hc0[0]*_t428 - _hc0[0]*_t429 + _hc0[0]*_t431 - _t295 + _t296*_t297 + _t301 - _t303 + _t306 + _t307 - _t311 - _t312 - _t313 - _t322 - _t325 - _t331 + _t334 + _t336 + _t338 - _t339 - _t342 + _t344 - _t364 + _t376 + _t377 + _t378 - _t380 - _t384 + _t385 - _t391 - _t395 + _t402 + _t403 - _t410 - _t411 - _t412 + _t414 + _t417 + _t418 + _t419 - _t430;
  out[14] = d4f_drs4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(f_pw_zeta0_k, _KMAX)(const xc_func_type *p, double rs, double *out) {
  const lda_c_pw_params *params = (const lda_c_pw_params *)(p->params);

  const double _t1 = params->alpha1[0]*rs;
  const double _t2 = _t1 + 0.1e1;
  const double _t3 = 0.2e1*_t2;
  const double _t4 = pow(rs, 1.5);
  const double _t5 = xc_powr(rs, 1, 2);
  const double _t6 = params->pp[0] + 0.1e1;
  const double _t7 = pow(rs, _t6);
  const double _t8 = _t7*params->beta4[0];
  const double _t9 = _t4*params->beta3[0] + _t5*params->beta1[0] + _t8 + params->beta2[0]*rs;
  const double _t10 = (0.1e1 / (params->a[0]));
  const double _t11 = (0.1e1 / 0.2e1)*_t10/_t9;
  const double _t12 = params->a[0]*xc_log1p(_t11);
#if _KMAX >= 1
  const double _t13 = 0.2e1*params->alpha1[0];
  const double _t14 = _t11 + 0.1e1;
  const double _t15 = (0.1e1 / _t14);
  const double _t16 = _t15/(_t9 * _t9);
  const double _t17 = sqrt(rs);
  const double _t18 = _t17*params->beta3[0];
  const double _t19 = params->beta1[0]/_t5;
  const double _t20 = _t6*_t8;
  const double _t21 = _t20/rs;
  const double _t22 = -1.5*_t18 - 0.1e1 / 0.2e1*_t19 - _t21 - params->beta2[0];
  const double _t23 = _t2*_t22;
#endif
#if _KMAX >= 2
  const double _t24 = (0.1e1 / 0.2e1)*_t1 + 0.1e1 / 0.2e1;
  const double _t25 = (0.1e1 / (_t9 * _t9 * _t9 * _t9));
  const double _t26 = (_t22 * _t22);
  const double _t27 = (0.1e1 / (_t14 * _t14));
  const double _t28 = (0.1e1 / (rs * rs));
  const double _t29 = _t20*_t28;
  const double _t30 = (_t6 * _t6);
  const double _t31 = _t30*_t8;
  const double _t32 = _t28*_t31;
  const double _t33 = params->beta1[0]/xc_powr(rs, 3, 2);
  const double _t34 = params->beta3[0]/_t17;
  const double _t35 = (0.1e1 / 0.4e1)*_t33 - 0.75*_t34;
  const double _t36 = _t29 - _t32 + _t35;
  const double _t37 = _t16*_t2;
  const double _t38 = _t15/(_t9 * _t9 * _t9);
  const double _t39 = 3.0*_t18 + _t19 + 0.2e1*params->beta2[0];
  const double _t40 = -0.2e1*_t21 - _t39;
  const double _t41 = _t23*_t40;
#endif
#if _KMAX >= 3
  const double _t42 = (0.1e1 / ((params->a[0]) * (params->a[0])));
  const double _t43 = xc_powi(_t9, -6);
  const double _t44 = (_t22 * _t22 * _t22);
  const double _t45 = (0.1e1 / (_t14 * _t14 * _t14));
  const double _t46 = _t16*params->alpha1[0];
  const double _t47 = 0.3e1*_t36;
  const double _t48 = _t38*_t40;
  const double _t49 = _t48*params->alpha1[0];
  const double _t50 = (0.1e1 / _t4);
  const double _t51 = params->beta1[0]/xc_powr(rs, 5, 2);
  const double _t52 = (0.1e1 / (rs * rs * rs));
  const double _t53 = _t20*_t52;
  const double _t54 = (_t6 * _t6 * _t6)*_t8;
  const double _t55 = _t52*_t54;
  const double _t56 = 0.3e1*_t30*_t52*_t7*params->beta4[0] + 0.375*_t50*params->beta3[0] - 0.3e1 / 0.8e1*_t51 - 0.2e1*_t53 - _t55;
  const double _t57 = xc_powi(_t9, -5);
  const double _t58 = _t6*params->beta4[0]*pow(rs, params->pp[0]);
  const double _t59 = 6.0*_t18 + 0.2e1*_t19 + 0.4e1*params->beta2[0];
  const double _t60 = -0.4e1*_t58 - _t59;
  const double _t61 = -_t39 - 0.2e1*_t58;
  const double _t62 = (0.1e1 / 0.2e1)*_t33 - 1.5*_t34;
  const double _t63 = 0.2e1*_t29 - 0.2e1*_t32 + _t62;
  const double _t64 = _t23*_t38;
  const double _t65 = 4.5*_t18 + (0.3e1 / 0.2e1)*_t19 + 0.3e1*params->beta2[0];
  const double _t66 = -0.3e1*_t21 - _t65;
  const double _t67 = _t15*_t25*_t41;
#endif
#if _KMAX >= 4
  const double _t68 = _t42*_t43*_t45;
  const double _t69 = (0.1e1 / 0.2e1)*_t2*_t42*_t44*_t45/xc_powi(_t9, 7);
  const double _t70 = _t38*_t63;
  const double _t71 = 0.4e1*_t22*params->alpha1[0];
  const double _t72 = params->beta4[0]*pow(rs, params->pp[0] - 0.1e1);
  const double _t73 = _t6*_t72;
  const double _t74 = _t30*_t72;
  const double _t75 = (0.1e1 / 0.2e1)*_t26*_t68;
  const double _t76 = _t2*_t75;
  const double _t77 = _t62 + 0.2e1*_t73 - 0.2e1*_t74;
  const double _t78 = (0.3e1 / 0.4e1)*_t33 - 2.25*_t34;
  const double _t79 = (0.1e1 / (rs * rs * rs * rs));
  const double _t80 = 0.6e1*_t79;
  const double _t81 = -7.5*_t18 - 0.5e1 / 0.2e1*_t19 - 0.5e1*_t58 - 0.5e1*params->beta2[0];
  const double _t82 = _t2*_t47;
  const double _t83 = _t15*_t66;
  const double _t84 = _t25*_t83;
  const double _t85 = _t40*_t84;
  const double _t86 = 0.6e1*_t30*_t52*_t7*params->beta4[0] + 0.75*_t50*params->beta3[0] - 0.3e1 / 0.4e1*_t51 - 0.4e1*_t53 - 0.2e1*_t55;
  const double _t87 = -0.4e1*_t21 - _t59;
#endif

  const double f = -_t12*_t3;
  out[0] = f;
#if _KMAX >= 1
  const double df_drs = -_t12*_t13 - _t16*_t23;
  out[1] = df_drs;
#endif
#if _KMAX >= 2
  const double d2f_drs2 = _t10*_t24*_t25*_t26*_t27 - _t13*_t16*_t22 - _t36*_t37 - _t38*_t41;
  out[2] = d2f_drs2;
#endif
#if _KMAX >= 3
  const double d3f_drs3 = (0.1e1 / 0.2e1)*_t10*_t2*_t22*_t25*_t27*_t36 + (0.1e1 / 0.2e1)*_t10*_t2*_t22*_t25*_t27*_t63 + (0.1e1 / 0.2e1)*_t10*_t2*_t26*_t27*_t57*_t60 + (0.1e1 / 0.2e1)*_t10*_t2*_t26*_t27*_t57*_t61 + (0.3e1 / 0.2e1)*_t10*_t25*_t26*_t27*params->alpha1[0] - 0.3e1*_t22*_t49 - _t24*_t42*_t43*_t44*_t45 - _t3*_t36*_t48 - _t37*_t56 - _t46*_t47 - _t63*_t64 - _t66*_t67;
  out[3] = d3f_drs3;
#endif
#if _KMAX >= 4
  const double d4f_drs4 = _t10*_t2*_t22*_t25*_t27*_t56 + (0.1e1 / 0.2e1)*_t10*_t2*_t22*_t25*_t27*_t86 + _t10*_t2*_t22*_t27*_t36*_t40*_t57 + (0.1e1 / 0.2e1)*_t10*_t2*_t22*_t27*_t36*_t57*_t87 + (0.1e1 / 0.2e1)*_t10*_t2*_t22*_t27*_t40*_t57*_t63 + _t10*_t2*_t22*_t27*_t57*_t63*_t87 + (0.1e1 / 0.2e1)*_t10*_t2*_t25*_t27*(_t36 * _t36) + (0.1e1 / 0.2e1)*_t10*_t2*_t25*_t27*_t36*_t63 + (0.1e1 / 0.2e1)*_t10*_t2*_t26*_t27*_t43*_t60*_t81 + (0.1e1 / 0.2e1)*_t10*_t2*_t26*_t27*_t43*_t61*_t81 + (0.1e1 / 0.2e1)*_t10*_t2*_t26*_t27*_t43*_t61*(-0.3e1*_t58 - _t65) + _t10*_t2*_t26*_t27*_t57*_t77 + (0.1e1 / 0.2e1)*_t10*_t2*_t26*_t27*_t57*(_t33 - 3.0*_t34 + 0.4e1*_t73 - 0.4e1*_t74) + 0.2e1*_t10*_t22*_t25*_t27*_t36*params->alpha1[0] + 0.2e1*_t10*_t22*_t25*_t27*_t63*params->alpha1[0] + 0.2e1*_t10*_t26*_t27*_t57*_t60*params->alpha1[0] + 0.2e1*_t10*_t26*_t27*_t57*_t61*params->alpha1[0] - _t13*_t44*_t68 - 0.3e1*_t2*_t48*_t56 - _t2*_t75*_t77 - _t22*_t3*_t63*_t84 - 0.8e1*_t36*_t49 - _t37*(_t20*_t80 - 0.11e2*_t31*_t79 + _t54*_t80 - (_t6 * _t6 * _t6 * _t6)*_t79*_t8 + (0.15e2 / 0.16e2)*params->beta1[0]/xc_powr(rs, 7, 2) - 0.5625*params->beta3[0]*pow(rs, -2.5)) - _t41*_t57*_t83*_t87 - 0.4e1*_t46*_t56 - _t60*_t69 - _t61*_t69 - _t64*_t86 - _t67*(0.3e1*_t29 - 0.3e1*_t32 + _t78) - _t69*(-9.0*_t18 - 0.3e1*_t19 - 0.6e1*_t58 - 0.6e1*params->beta2[0]) - _t70*_t71 - _t70*_t82 - _t71*_t85 - _t76*(_t35 + _t73 - _t74) - _t76*(0.3e1*_t73 - 0.3e1*_t74 + _t78) - _t82*_t85 + (_t22 * _t22 * _t22 * _t22)*((0.3e1 / 0.4e1)*_t1 + 0.3e1 / 0.4e1)/((_t14 * _t14 * _t14 * _t14)*xc_powi(_t9, 8)*((params->a[0]) * (params->a[0]) * (params->a[0])));
  out[4] = d4f_drs4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_c_pw_params *params = (const lda_c_pw_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = _t3/xc_powr(na, 1, 3);
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(f_pw_zeta0_k, _KMAX)(p, (0.1e1 / 0.2e1)*_t4, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[0] - 0.1e1 / 0.6e1*_hc0[1]*_t4;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t6 = xc_powr(0.6e1, 2, 3);
  const double _t7 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t5 = _hc0[1]*_t3;
  const double d2F_dna2 = (0.1e1 / 0.36e2)*_hc0[2]*_t6*_t7/xc_powr(na, 5, 3) - 0.1e1 / 0.9e1*_t5/xc_powr(na, 4, 3);
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t8 = _hc0[3]/M_PI;
  const double _t9 = _hc0[2]*_t6*_t7;
  const double d3F_dna3 = (0.4e1 / 0.27e2)*_hc0[1]*_t1*_t2/xc_powr(na, 7, 3) - 0.1e1 / 0.36e2*_t8/(na * na * na) - 0.1e1 / 0.36e2*_t9/xc_powr(na, 8, 3);
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.216e3)*_hc0[4]*_t1/((M_PI * M_CBRTPI)*xc_powr(na, 13, 3)) - 0.28e2 / 0.81e2*_t5/xc_powr(na, 10, 3) + (0.1e1 / 0.9e1)*_t8/(na * na * na * na) + (0.4e1 / 0.81e2)*_t9/xc_powr(na, 11, 3);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = xc_powr(0.6e1, 1, 3);
  const double _t3 = (0.1e1 / (M_CBRTPI));
  const double _t4 = _t2*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t4;
  const double _t6 = na - nb;
  const double _t7 = (0.1e1 / _t1);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(f_pw_k, _KMAX)(p, _t5/xc_powr(_t1, 1, 3), _t6*_t7, _hc0);
  const double zk = _hc0[0];
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t9 = xc_powr(_t1, -4, 3);
  const double _t10 = (0.1e1 / 0.6e1)*_t9;
  const double _t12 = (0.1e1 / (_t1 * _t1));
  const double _t13 = _t12*_t6;
  const double _t14 = -_t13 + _t7;
  const double _t16 = -_t13 - _t7;
  const double _t8 = _hc0[2]*_t4;
  const double _t11 = -_t10*_t8;
  const double _t15 = _hc0[1]*_t14;
  const double _t17 = _hc0[1]*_t16;
  const double dF_dna = _hc0[0] + _t1*(_t11 + _t15);
  const double dF_dnb = _hc0[0] + _t1*(_t11 + _t17);
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t18 = (0.1e1 / 0.3e1)*_t9;
  const double _t20 = xc_powr(_t1, -7, 3);
  const double _t21 = (0.2e1 / 0.9e1)*_t20;
  const double _t23 = 0.2e1*_t12;
  const double _t24 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t25 = 0.2e1*_t24;
  const double _t26 = _t25*_t6;
  const double _t27 = -_t23 + _t26;
  const double _t29 = _t10*_t4;
  const double _t40 = _t23 + _t26;
  const double _t19 = -_t18*_t8;
  const double _t22 = _t21*_t8;
  const double _t28 = _hc0[1]*_t27;
  const double _t30 = -_hc0[4]*_t29;
  const double _t31 = _hc0[3]*_t14 + _t30;
  const double _t32 = _t14*_t31;
  const double _t33 = -_hc0[5]*_t29;
  const double _t34 = _hc0[4]*_t14 + _t33;
  const double _t35 = _t28 - _t29*_t34 + _t32;
  const double _t36 = _hc0[3]*_t16 + _t30;
  const double _t37 = _t14*_t36;
  const double _t38 = _hc0[4]*_t16 + _t33;
  const double _t39 = _t22 - _t29*_t38;
  const double _t41 = _hc0[1]*_t40;
  const double _t42 = _t16*_t36;
  const double _t43 = _t41 + _t42;
  const double d2F_dna2 = _t1*(_t22 + _t35) + 0.2e1*_t15 + _t19;
  const double d2F_dna_dnb = _t1*(_hc0[1]*_t26 + _t37 + _t39) + _t15 + _t17 + _t19;
  const double d2F_dnb2 = _t1*(_t39 + _t43) + 0.2e1*_t17 + _t19;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t44 = (0.2e1 / 0.3e1)*_t20;
  const double _t46 = _t5*_t9;
  const double _t47 = xc_powr(_t1, -10, 3);
  const double _t48 = (0.14e2 / 0.27e2)*_t47;
  const double _t52 = (0.4e1 / 0.9e1)*_t20;
  const double _t54 = 0.6e1*_t24;
  const double _t55 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t56 = _t55*_t6;
  const double _t57 = 0.6e1*_t56;
  const double _t58 = _t54 - _t57;
  const double _t60 = _t21*_t4;
  const double _t68 = 0.2e1*_t27;
  const double _t74 = 0.2e1*_t24 - _t57;
  const double _t86 = 0.4e1*_t24;
  const double _t93 = -_t54 - _t57;
  const double _t45 = _t44*_t8;
  const double _t49 = _t48*_t8;
  const double _t50 = -_t49;
  const double _t51 = _t34*_t4;
  const double _t53 = _t51*_t52;
  const double _t59 = _hc0[1]*_t58;
  const double _t61 = _hc0[4]*_t60;
  const double _t62 = -_hc0[8]*_t29;
  const double _t63 = _hc0[7]*_t14 + _t62;
  const double _t64 = -_hc0[7]*_t29;
  const double _t65 = _hc0[6]*_t14 + _t64;
  const double _t66 = _hc0[3]*_t27 + _t14*_t65 - _t29*_t63 + _t61;
  const double _t67 = _t14*_t66;
  const double _t69 = _hc0[5]*_t60;
  const double _t70 = -_hc0[9]*_t29;
  const double _t71 = _hc0[8]*_t14 + _t70;
  const double _t72 = _hc0[4]*_t27 + _t14*_t63 - _t29*_t71 + _t69;
  const double _t73 = -_t29*_t72 + _t31*_t68 + _t59 + _t67;
  const double _t75 = _hc0[1]*_t74;
  const double _t76 = _t27*_t36;
  const double _t77 = _hc0[7]*_t16 + _t62;
  const double _t78 = _hc0[8]*_t16 + _t70;
  const double _t79 = -_t29*_t78 + _t69;
  const double _t80 = _hc0[4]*_t26 + _t14*_t77 + _t79;
  const double _t81 = _hc0[6]*_t16 + _t64;
  const double _t82 = -_t29*_t77 + _t61;
  const double _t83 = _hc0[3]*_t26 + _t14*_t81 + _t82;
  const double _t84 = _t14*_t83;
  const double _t85 = _t38*_t4;
  const double _t87 = _hc0[1]*_t86;
  const double _t88 = 0.2e1*_t37 + _t6*_t87;
  const double _t89 = _hc0[4]*_t40 + _t16*_t77 + _t79;
  const double _t90 = _t29*_t89;
  const double _t91 = _hc0[3]*_t40 + _t16*_t81 + _t82;
  const double _t92 = -_t38*_t46 + _t45;
  const double _t94 = _hc0[1]*_t93;
  const double _t95 = _t16*_t91;
  const double _t96 = 0.2e1*_t36;
  const double _t97 = _t40*_t96 + _t94 + _t95;
  const double d3F_dna3 = _t1*(_t50 + _t53 + _t73) + 0.3e1*_t28 + 0.3e1*_t32 - _t34*_t46 + _t45;
  const double d3F_dna2_dnb = _t1*(_t26*_t31 - _t29*_t80 + _t34*_t60 + _t38*_t60 + _t50 + _t75 + _t76 + _t84) - _t18*_t85 + _t35 + _t45 + _t88;
  const double d3F_dna_dnb2 = _t1*(-_hc0[1]*_t25 - _hc0[1]*_t57 + _t14*_t91 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t38 + 0.4e1*_t24*_t36*_t6 - _t49 - _t90) + _t43 + _t88 + _t92;
  const double d3F_dnb3 = _t1*(_t50 + _t52*_t85 - _t90 + _t97) + 0.3e1*_t41 + 0.3e1*_t42 + _t92;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t101 = (0.2e1 / 0.3e1)*_t9;
  const double _t103 = 0.24e2*_t55;
  const double _t104 = 0.24e2*_t6/xc_powi(_t1, 5);
  const double _t106 = _t4*_t48;
  const double _t109 = _t4*_t52;
  const double _t122 = 0.12e2*_t55;
  const double _t131 = _t54*_t6;
  const double _t133 = _t6*_t86;
  const double _t135 = _t24*_t6;
  const double _t137 = _t18*_t4;
  const double _t145 = 0.2e1*_t40;
  const double _t147 = 0.18e2*_t56;
  const double _t98 = -0.56e2 / 0.27e2*_t47*_t8;
  const double _t99 = _t20*_t51;
  const double _t100 = _t4*_t72;
  const double _t102 = (0.140e3 / 0.81e2)*_t8/xc_powr(_t1, 13, 3);
  const double _t105 = _t47*_t51;
  const double _t107 = _hc0[5]*_t106;
  const double _t108 = -_t107;
  const double _t110 = _hc0[9]*_t60;
  const double _t111 = -_hc0[14]*_t29;
  const double _t112 = -_hc0[13]*_t29;
  const double _t113 = _hc0[12]*_t14 + _t112;
  const double _t114 = _hc0[8]*_t60;
  const double _t115 = -_hc0[12]*_t29;
  const double _t116 = _hc0[11]*_t14 + _t115;
  const double _t117 = _hc0[7]*_t27 - _t113*_t29 + _t114 + _t116*_t14;
  const double _t118 = _hc0[4]*_t106;
  const double _t119 = -_t118;
  const double _t120 = _hc0[7]*_t60;
  const double _t121 = -_hc0[11]*_t29;
  const double _t123 = _hc0[11]*_t16 + _t115;
  const double _t124 = _hc0[12]*_t16 + _t112;
  const double _t125 = _t114 - _t124*_t29;
  const double _t126 = _hc0[7]*_t26 + _t123*_t14 + _t125;
  const double _t127 = _hc0[10]*_t16 + _t121;
  const double _t128 = _t120 - _t123*_t29;
  const double _t129 = _t110 - _t29*(_hc0[13]*_t16 + _t111);
  const double _t130 = _t102 + _t109*_t80;
  const double _t132 = _hc0[1]*_t122;
  const double _t134 = 0.8e1*_t36;
  const double _t136 = _t20*_t85;
  const double _t138 = _t14*_t91;
  const double _t139 = _hc0[1]*_t104;
  const double _t140 = _hc0[7]*_t40 + _t123*_t16 + _t125;
  const double _t141 = _t140*_t29;
  const double _t142 = _hc0[6]*_t40 + _t127*_t16 + _t128;
  const double _t143 = _t47*_t85;
  const double _t144 = _t29*(_hc0[8]*_t40 + _t124*_t16 + _t129);
  const double _t146 = _hc0[3]*_t93 + _t109*_t77 + _t119 - _t141 + _t142*_t16 + _t145*_t81;
  const double _t148 = _t4*_t89;
  const double _t149 = _t102 - 0.14e2 / 0.9e1*_t143 + _t148*_t44 - _t29*(_hc0[4]*_t93 + _t108 + _t109*_t78 + _t140*_t16 - _t144 + _t145*_t77);
  const double _t150 = -_t101*_t148 + (0.16e2 / 0.9e1)*_t136 + _t98;
  const double d4F_dna4 = _t1*(_hc0[1]*(-_t103 + _t104) + _t100*_t44 + _t102 - 0.14e2 / 0.9e1*_t105 + _t14*(_hc0[3]*_t58 + _t109*_t63 - _t117*_t29 + _t119 + _t14*(_hc0[6]*_t27 - _t116*_t29 + _t120 + _t14*(_hc0[10]*_t14 + _t121)) + _t65*_t68) + 0.3e1*_t27*_t66 - _t29*(_hc0[4]*_t58 + _t108 + _t109*_t71 + _t117*_t14 - _t29*(_hc0[8]*_t27 + _t110 + _t113*_t14 - _t29*(_hc0[13]*_t14 + _t111)) + _t63*_t68) + 0.3e1*_t31*_t58) - _t100*_t101 + 0.8e1*_t27*_t31 + 0.4e1*_t59 + 0.4e1*_t67 + _t98 + (0.16e2 / 0.9e1)*_t99;
  const double d4F_dna3_dnb = _t1*(_hc0[1]*(_t104 - _t122) - 0.28e2 / 0.27e2*_t105 + _t130 + _t14*(_hc0[3]*_t74 + _t119 - _t126*_t29 + _t14*(_hc0[6]*_t26 + _t127*_t14 + _t128) + _t26*_t65 + _t27*_t81 + _t60*_t63 + _t60*_t77) + _t26*_t66 - _t29*(_hc0[4]*_t74 + _t108 + _t126*_t14 + _t26*_t63 + _t27*_t77 - _t29*(_hc0[8]*_t26 + _t124*_t14 + _t129) + _t60*_t71 + _t60*_t78) + 0.2e1*_t31*_t74 + _t36*_t58 - _t48*_t85 + _t60*_t72 + _t68*_t83) + _t131*_t31 + _t44*_t85 - _t46*_t80 + _t73 + 0.3e1*_t75 + 0.3e1*_t76 + 0.3e1*_t84 + _t98 + (0.10e2 / 0.9e1)*_t99;
  const double d4F_dna2_dnb2 = _t1*(_t130 + _t133*_t83 + _t139 + _t14*(-_hc0[3]*_t25 - _hc0[3]*_t57 - _t118 + _t14*_t142 - _t141 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t77 + 0.4e1*_t24*_t6*_t81) - 0.28e2 / 0.27e2*_t143 - _t25*_t31 + _t27*_t91 - _t29*(-_hc0[4]*_t25 - _hc0[4]*_t57 - _t107 + _t14*_t140 - _t144 + (0.4e1 / 0.9e1)*_t2*_t20*_t3*_t78 + 0.4e1*_t24*_t6*_t77) - _t31*_t57 - _t48*_t51 + _t60*_t89 + _t74*_t96) - _t132*_t6 + _t133*_t31 + _t134*_t135 + (0.4e1 / 0.3e1)*_t136 - _t137*_t80 - _t137*_t89 + 0.2e1*_t138 + _t53 + 0.2e1*_t75 + 0.2e1*_t76 + 0.2e1*_t84 - _t87 + _t98;
  const double d4F_dna_dnb3 = -_hc0[1]*_t147 - _hc0[1]*_t54 + _t1*(_t131*_t91 + _t132 + _t139 + _t14*_t146 - _t147*_t36 + _t149 - _t36*_t54) + 0.12e2*_t135*_t36 + 0.3e1*_t138 + _t150 + _t97;
  const double d4F_dnb4 = _t1*(_hc0[1]*(_t103 + _t104) + _t146*_t16 + _t149 + 0.3e1*_t36*_t93 + 0.3e1*_t40*_t91) + _t134*_t40 + _t150 + 0.4e1*_t94 + 0.4e1*_t95;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif