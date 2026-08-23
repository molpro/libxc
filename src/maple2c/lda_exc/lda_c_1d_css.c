/*
  Generated from python/lda_exc/lda_c_1d_css.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_1d_css
*/

#ifndef _LDA_C_1D_CSS_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_1D_CSS_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_1D_CSS_HELPER_BODIES
#include "lda_c_1d_css.c"
#undef _LDA_C_1D_CSS_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_1D_CSS_HELPER_BODIES
#include "lda_c_1d_css.c"
#undef _LDA_C_1D_CSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_1D_CSS_HELPER_BODIES
#include "lda_c_1d_css.c"
#undef _LDA_C_1D_CSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_1D_CSS_HELPER_BODIES
#include "lda_c_1d_css.c"
#undef _LDA_C_1D_CSS_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_1D_CSS_HELPER_BODIES
#include "lda_c_1d_css.c"
#undef _LDA_C_1D_CSS_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_1d_css.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_1D_CSS_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_c_1d_css_params *params = (const lda_c_1d_css_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = (0.1e1 / na);
  const double _t2 = (0.1e1 / 0.2e1)*_t1;
  const double _t3 = (0.1e1 / (na * na));
  const double _t4 = -_t2 - 0.1e1 / 0.4e1*_t3*params->para[4];
  const double _t5 = pow(_t2, params->para[5])*params->para[2];
  const double _t6 = 0.2e1*_t5;
  const double _t7 = pow(_t2, params->para[6])*params->para[3];
  const double _t8 = 0.2e1*_t7;
  const double _t9 = _t1*params->para[1] + _t6 + _t8 + 0.2e1*params->para[0];
  const double _t10 = (0.1e1 / _t9);
  const double _t11 = pow(_t2, params->para[9])*params->para[8];
  const double _t12 = _t11 + _t2*params->para[7];
  const double _t13 = xc_log1p(_t12);
  const double _t14 = _t10*_t13;
  const double _t15 = _t14*_t4;
  const double zk = _t15;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t16 = (0.1e1 / 0.2e1)*_t3;
  const double _t17 = (0.1e1 / (na * na * na));
  const double _t18 = _t16 + (0.1e1 / 0.2e1)*_t17*params->para[4];
  const double _t19 = _t14*_t18;
  const double _t20 = _t4*na;
  const double _t21 = _t11*params->para[9];
  const double _t22 = _t1*_t21;
  const double _t23 = _t16*params->para[7] + _t22;
  const double _t24 = -_t23;
  const double _t25 = _t12 + 0.1e1;
  const double _t26 = (0.1e1 / _t25);
  const double _t27 = _t10*_t26;
  const double _t28 = _t24*_t27;
  const double _t29 = (0.1e1 / (_t9 * _t9));
  const double _t30 = _t13*_t29;
  const double _t31 = _t3*params->para[1];
  const double _t32 = _t6*params->para[5];
  const double _t33 = _t8*params->para[6];
  const double _t34 = _t1*_t32 + _t1*_t33 + _t31;
  const double _t35 = _t20*_t34;
  const double dF_dna = _t15 + _t19*na + _t20*_t28 + _t30*_t35;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t36 = (0.1e1 / (na * na * na * na));
  const double _t37 = -_t17 - 0.3e1 / 0.2e1*_t36*params->para[4];
  const double _t38 = _t14*_t37;
  const double _t39 = 0.2e1*_t4;
  const double _t40 = _t18*na;
  const double _t41 = 0.2e1*_t40;
  const double _t42 = _t30*_t34;
  const double _t43 = _t17*params->para[7];
  const double _t44 = _t21*_t3;
  const double _t45 = _t11*((params->para[9]) * (params->para[9]));
  const double _t46 = _t3*_t45;
  const double _t47 = _t43 + _t44 + _t46;
  const double _t48 = _t27*_t47;
  const double _t49 = _t20*_t24;
  const double _t50 = (0.1e1 / (_t25 * _t25));
  const double _t51 = _t23*_t50;
  const double _t52 = _t10*_t51;
  const double _t53 = _t26*_t29;
  const double _t54 = _t24*_t53;
  const double _t55 = 0.2e1*_t35;
  const double _t56 = _t17*params->para[1];
  const double _t57 = ((params->para[5]) * (params->para[5]));
  const double _t58 = _t3*_t57;
  const double _t59 = ((params->para[6]) * (params->para[6]));
  const double _t60 = _t3*_t59;
  const double _t61 = -_t3*_t32 - _t3*_t33 - 0.2e1*_t56 - _t58*_t6 - _t60*_t8;
  const double _t62 = _t30*_t61;
  const double _t63 = (0.1e1 / (_t9 * _t9 * _t9));
  const double _t64 = _t13*_t63;
  const double _t65 = 0.4e1*_t1;
  const double _t66 = _t5*params->para[5];
  const double _t67 = _t7*params->para[6];
  const double _t68 = 0.2e1*_t31 + _t65*_t66 + _t65*_t67;
  const double _t69 = _t35*_t68;
  const double d2F_dna2 = 0.2e1*_t19 + _t20*_t48 + _t20*_t62 + _t28*_t39 + _t28*_t41 + _t38*na + _t39*_t42 + _t41*_t42 + _t49*_t52 + _t54*_t55 + _t64*_t69;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t70 = 0.3e1*_t36;
  const double _t71 = xc_powi(na, -5);
  const double _t72 = _t70 + 0.6e1*_t71*params->para[4];
  const double _t73 = _t14*_t72;
  const double _t74 = 0.6e1*_t18;
  const double _t75 = _t28*na;
  const double _t76 = 0.3e1*_t37;
  const double _t77 = _t42*na;
  const double _t78 = 0.3e1*_t4;
  const double _t79 = 0.3e1*_t40;
  const double _t80 = _t24*_t52;
  const double _t81 = _t11*((params->para[9]) * (params->para[9]) * (params->para[9]));
  const double _t82 = 0.2e1*_t17*_t21 + 0.3e1*_t17*_t45 + _t17*_t81 + _t70*params->para[7];
  const double _t83 = -_t82;
  const double _t84 = _t27*_t83;
  const double _t85 = 0.6e1*_t24;
  const double _t86 = _t34*_t53;
  const double _t87 = _t4*_t86;
  const double _t88 = _t47*_t52;
  const double _t89 = 0.2e1*_t20;
  const double _t90 = _t24*_t86;
  const double _t91 = _t90*na;
  const double _t92 = _t10*_t49;
  const double _t93 = -_t47;
  const double _t94 = _t50*_t93;
  const double _t95 = (0.1e1 / (_t25 * _t25 * _t25));
  const double _t96 = _t3*params->para[7];
  const double _t97 = 0.2e1*_t22 + _t96;
  const double _t98 = _t23*_t95*_t97;
  const double _t99 = _t34*_t64;
  const double _t100 = _t68*_t99;
  const double _t101 = 0.3e1*_t53;
  const double _t102 = _t35*_t47;
  const double _t103 = _t29*_t51;
  const double _t104 = 0.3e1*_t24;
  const double _t105 = _t49*_t61;
  const double _t106 = _t26*_t63;
  const double _t107 = _t106*_t69;
  const double _t108 = _t36*params->para[1];
  const double _t109 = 0.4e1*_t17;
  const double _t110 = 0.6e1*_t17;
  const double _t111 = _t5*_t57;
  const double _t112 = ((params->para[5]) * (params->para[5]) * (params->para[5]));
  const double _t113 = _t112*_t17;
  const double _t114 = _t59*_t7;
  const double _t115 = ((params->para[6]) * (params->para[6]) * (params->para[6]));
  const double _t116 = _t115*_t17;
  const double _t117 = 0.6e1*_t108 + _t109*_t66 + _t109*_t67 + _t110*_t111 + _t110*_t114 + _t113*_t6 + _t116*_t8;
  const double _t118 = _t117*_t30;
  const double _t119 = 0.4e1*_t3;
  const double _t120 = 0.4e1*_t5;
  const double _t121 = 0.4e1*_t7;
  const double _t122 = -_t119*_t66 - _t119*_t67 - _t120*_t58 - _t121*_t60 - 0.4e1*_t56;
  const double _t123 = _t35*_t64;
  const double _t124 = _t64*_t68;
  const double _t125 = _t124*_t61;
  const double _t126 = (0.1e1 / (_t9 * _t9 * _t9 * _t9));
  const double _t127 = 0.6e1*_t1;
  const double _t128 = _t127*_t66 + _t127*_t67 + 0.3e1*_t31;
  const double _t129 = _t126*_t128*_t13;
  const double d3F_dna3 = _t100*_t78 + _t100*_t79 + _t101*_t102 + _t101*_t105 + _t103*_t104*_t35 + _t104*_t107 + _t118*_t20 + _t122*_t123 + _t125*_t89 + _t129*_t69 + _t20*_t84 + _t28*_t74 + 0.3e1*_t38 + _t42*_t74 + _t48*_t78 + _t48*_t79 + _t62*_t78 + _t62*_t79 + _t73*na + _t74*_t91 + _t75*_t76 + _t76*_t77 + _t78*_t80 + _t79*_t80 + _t85*_t87 + _t88*_t89 + _t92*_t94 + _t92*_t98;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double _t130 = 0.12e2*_t71;
  const double _t131 = 0.12e2*_t37;
  const double _t132 = 0.4e1*_t72;
  const double _t133 = 0.12e2*_t18;
  const double _t134 = 0.6e1*_t37*na;
  const double _t135 = 0.4e1*_t4;
  const double _t136 = 0.4e1*_t40;
  const double _t137 = 0.8e1*_t4;
  const double _t138 = 0.8e1*_t40;
  const double _t139 = _t10*_t94;
  const double _t140 = _t139*_t24;
  const double _t141 = _t10*_t98;
  const double _t142 = _t141*_t24;
  const double _t143 = 0.6e1*_t36;
  const double _t144 = _t133*na;
  const double _t145 = 0.3e1*_t20;
  const double _t146 = _t145*_t47;
  const double _t147 = 0.12e2*_t4;
  const double _t148 = _t147*_t24;
  const double _t149 = _t103*_t34;
  const double _t150 = _t144*_t24;
  const double _t151 = _t92*_t95;
  const double _t152 = _t54*_t61;
  const double _t153 = 0.4e1*_t53;
  const double _t154 = _t34*_t68;
  const double _t155 = _t106*_t154;
  const double _t156 = 0.4e1*_t24;
  const double _t157 = _t156*_t35;
  const double _t158 = _t157*_t29;
  const double _t159 = _t122*_t99;
  const double _t160 = 0.6e1*_t47;
  const double _t161 = _t129*_t154;
  const double _t162 = 0.12e2*_t36;
  const double _t163 = 0.22e2*_t36;
  const double _t164 = 0.8e1*_t17;
  const double _t165 = 0.12e2*_t17;
  const double _t166 = _t145*_t61;
  const double _t167 = 0.6e1*_t3;
  const double _t168 = _t13*_t69;
  const double _t169 = 0.8e1*_t1;
  const double d4F_dna4 = _t100*_t133 + _t100*_t134 + 0.8e1*_t102*_t103 + 0.6e1*_t103*_t105 + 0.8e1*_t105*_t106*_t68 + _t106*_t122*_t157 + _t107*_t160 + _t117*_t124*_t145 + _t117*_t153*_t49 + _t118*_t135 + _t118*_t136 + _t122*_t129*_t55 + _t122*_t166*_t64 + _t123*(0.12e2*_t108 + _t111*_t165 + _t113*_t120 + _t114*_t165 + _t116*_t121 + _t164*_t66 + _t164*_t67) + _t125*_t137 + _t125*_t138 + _t126*_t128*_t156*_t26*_t69 + _t126*_t168*(-_t167*_t66 - _t167*_t67 - 0.6e1*_t5*_t58 - 0.6e1*_t56 - 0.6e1*_t60*_t7) + _t128*_t168*(_t169*_t66 + _t169*_t67 + 0.4e1*_t31)/xc_powi(_t9, 5) + _t129*_t166*_t68 + _t131*_t28 + _t131*_t42 + _t131*_t91 + _t132*_t75 + _t132*_t77 + _t133*_t48 + _t133*_t62 + _t133*_t80 + _t134*_t48 + _t134*_t62 + _t134*_t80 + _t135*_t140 + _t135*_t142 + _t135*_t159 + _t135*_t161 + _t135*_t84 + _t136*_t140 + _t136*_t142 + _t136*_t159 + _t136*_t161 + _t136*_t84 + _t137*_t88 + _t138*_t88 + _t139*_t146 + _t14*na*(-_t130 - 0.30e2*params->para[4]/xc_powi(na, 6)) + _t141*_t146 + _t144*_t152 + _t144*_t47*_t86 + _t145*_t52*_t83 + _t147*_t152 + _t148*_t149 + _t148*_t155 + _t149*_t150 + _t150*_t155 + _t151*_t23*(-0.2e1*_t43 - 0.2e1*_t44 - 0.2e1*_t46) + 0.2e1*_t151*_t93*_t97 + _t153*_t35*_t83 + _t158*_t94 + _t158*_t98 + _t160*_t20*_t53*_t61 + 0.24e2*_t18*_t90 + _t20*_t27*(_t11*_t36*((params->para[9]) * (params->para[9]) * (params->para[9]) * (params->para[9])) + _t130*params->para[7] + _t143*_t21 + _t143*_t81 + 0.11e2*_t36*_t45) + _t20*_t30*(-_t111*_t163 - _t112*_t162*_t5 - _t114*_t163 - _t115*_t162*_t7 - _t162*_t66 - _t162*_t67 - _t36*_t6*((params->para[5]) * (params->para[5]) * (params->para[5]) * (params->para[5])) - _t36*_t8*((params->para[6]) * (params->para[6]) * (params->para[6]) * (params->para[6])) - 0.24e2*_t71*params->para[1]) + _t23*_t92*_t97*(0.3e1*_t22 + (0.3e1 / 0.2e1)*_t96)/(_t25 * _t25 * _t25 * _t25) + 0.12e2*_t47*_t87 + _t50*_t82*_t92 + _t51*_t63*_t69*_t85 + 0.4e1*_t73;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na + nb;
  const double _t2 = (0.1e1 / _t1);
  const double _t3 = (0.1e1 / 0.2e1)*_t2;
  const double _t4 = (0.1e1 / (_t1 * _t1));
  const double _t5 = (0.1e1 / 0.4e1)*_t4;
  const double _t6 = -_t3 - _t5*params->para[4];
  const double _t7 = pow(_t3, params->para[5]);
  const double _t8 = _t7*params->para[2];
  const double _t9 = 0.2e1*_t8;
  const double _t10 = pow(_t3, params->para[6]);
  const double _t11 = _t10*params->para[3];
  const double _t12 = 0.2e1*_t11;
  const double _t13 = _t12 + _t2*params->para[1] + _t9 + 0.2e1*params->para[0];
  const double _t14 = (0.1e1 / _t13);
  const double _t15 = pow(_t3, params->para[9]);
  const double _t16 = _t15*params->para[8];
  const double _t17 = _t16 + _t3*params->para[7];
  const double _t18 = xc_log1p(_t17);
  const double _t19 = _t14*_t18;
  const double _t20 = _t19*_t6;
  const double _t21 = -_t3 - _t5*params->ferro[4];
  const double _t22 = pow(_t3, params->ferro[5]);
  const double _t23 = _t22*params->ferro[2];
  const double _t24 = 0.2e1*_t23;
  const double _t25 = pow(_t3, params->ferro[6]);
  const double _t26 = _t25*params->ferro[3];
  const double _t27 = 0.2e1*_t26;
  const double _t28 = _t2*params->ferro[1] + _t24 + _t27 + 0.2e1*params->ferro[0];
  const double _t29 = (0.1e1 / _t28);
  const double _t30 = pow(_t3, params->ferro[9]);
  const double _t31 = _t30*params->ferro[8];
  const double _t32 = _t3*params->ferro[7] + _t31;
  const double _t33 = xc_log1p(_t32);
  const double _t34 = _t29*_t33;
  const double _t35 = -_t20 + _t21*_t34;
  const double _t36 = ((na - nb) * (na - nb));
  const double _t37 = _t36*_t4;
  const double _t38 = _t20 + _t35*_t37;
  const double zk = _t38;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t39 = 0.2e1*na;
  const double _t40 = 0.2e1*nb;
  const double _t41 = _t39 - _t40;
  const double _t42 = _t35*_t4;
  const double _t43 = _t41*_t42;
  const double _t44 = (0.1e1 / 0.2e1)*_t4;
  const double _t45 = (0.1e1 / (_t1 * _t1 * _t1));
  const double _t46 = (0.1e1 / 0.2e1)*_t45;
  const double _t47 = _t44 + _t46*params->ferro[4];
  const double _t48 = _t44 + _t46*params->para[4];
  const double _t49 = _t19*_t48;
  const double _t50 = _t32 + 0.1e1;
  const double _t51 = (0.1e1 / _t50);
  const double _t52 = _t29*_t51;
  const double _t53 = _t31*params->ferro[9];
  const double _t54 = _t39 + _t40;
  const double _t55 = _t44*_t54;
  const double _t56 = _t44*params->ferro[7] + _t53*_t55;
  const double _t57 = -_t56;
  const double _t58 = _t21*_t57;
  const double _t59 = _t17 + 0.1e1;
  const double _t60 = (0.1e1 / _t59);
  const double _t61 = _t14*_t60;
  const double _t62 = _t16*params->para[9];
  const double _t63 = _t44*params->para[7] + _t55*_t62;
  const double _t64 = -_t63;
  const double _t65 = _t6*_t64;
  const double _t66 = _t61*_t65;
  const double _t67 = (0.1e1 / (_t28 * _t28));
  const double _t68 = _t33*_t67;
  const double _t69 = _t4*params->ferro[1];
  const double _t70 = _t4*_t54;
  const double _t71 = _t23*params->ferro[5];
  const double _t72 = _t70*_t71;
  const double _t73 = _t26*params->ferro[6];
  const double _t74 = _t70*_t73;
  const double _t75 = _t69 + _t72 + _t74;
  const double _t76 = _t21*_t75;
  const double _t77 = (0.1e1 / (_t13 * _t13));
  const double _t78 = _t18*_t77;
  const double _t79 = _t4*params->para[1];
  const double _t80 = _t8*params->para[5];
  const double _t81 = _t70*_t80;
  const double _t82 = _t11*params->para[6];
  const double _t83 = _t70*_t82;
  const double _t84 = _t79 + _t81 + _t83;
  const double _t85 = _t6*_t84;
  const double _t86 = _t78*_t85;
  const double _t87 = _t34*_t47 - _t49 + _t52*_t58 - _t66 + _t68*_t76 - _t86;
  const double _t88 = _t37*_t87;
  const double _t89 = 0.2e1*_t45;
  const double _t90 = _t35*_t36;
  const double _t91 = _t49 + _t66 + _t86 + _t88 - _t89*_t90;
  const double _t92 = -_t41;
  const double _t93 = _t42*_t92;
  const double dF_dna = _t1*(_t43 + _t91) + _t38;
  const double dF_dnb = _t1*(_t91 + _t93) + _t38;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t94 = _t35*_t45;
  const double _t95 = 0.4e1*_t94;
  const double _t96 = _t4*_t87;
  const double _t97 = _t41*_t96;
  const double _t98 = -_t41*_t95 + 0.2e1*_t97;
  const double _t99 = 0.2e1*_t42;
  const double _t100 = (0.1e1 / (_t1 * _t1 * _t1 * _t1));
  const double _t101 = (0.3e1 / 0.2e1)*_t100;
  const double _t102 = -_t101*params->ferro[4] - _t45;
  const double _t103 = -_t101*params->para[4] - _t45;
  const double _t104 = _t103*_t19;
  const double _t105 = 0.2e1*_t47;
  const double _t106 = _t52*_t57;
  const double _t107 = 0.2e1*_t48;
  const double _t108 = _t61*_t64;
  const double _t109 = _t107*_t108;
  const double _t110 = _t68*_t75;
  const double _t111 = _t78*_t84;
  const double _t112 = _t107*_t111;
  const double _t113 = (0.1e1 / (_t50 * _t50));
  const double _t114 = _t113*_t29;
  const double _t115 = _t56*_t58;
  const double _t116 = (0.1e1 / (_t59 * _t59));
  const double _t117 = _t116*_t14;
  const double _t118 = _t63*_t65;
  const double _t119 = _t117*_t118;
  const double _t120 = _t45*params->ferro[7];
  const double _t121 = _t4*_t53;
  const double _t122 = _t45*_t54;
  const double _t123 = ((params->ferro[9]) * (params->ferro[9]));
  const double _t124 = _t123*_t31;
  const double _t125 = (_t54 * _t54);
  const double _t126 = _t100*_t125;
  const double _t127 = (0.1e1 / 0.4e1)*_t126;
  const double _t128 = _t120 - _t121 + _t122*_t53 + _t124*_t127;
  const double _t129 = _t21*_t52;
  const double _t130 = _t45*params->para[7];
  const double _t131 = _t4*_t62;
  const double _t132 = ((params->para[9]) * (params->para[9]));
  const double _t133 = _t132*_t16;
  const double _t134 = _t122*_t62 + _t127*_t133 + _t130 - _t131;
  const double _t135 = _t6*_t61;
  const double _t136 = _t134*_t135;
  const double _t137 = 0.2e1*_t58;
  const double _t138 = _t51*_t67;
  const double _t139 = _t138*_t75;
  const double _t140 = 0.2e1*_t65;
  const double _t141 = _t60*_t77;
  const double _t142 = _t141*_t84;
  const double _t143 = _t140*_t142;
  const double _t144 = _t24*params->ferro[5];
  const double _t145 = _t27*params->ferro[6];
  const double _t146 = _t144*_t70 + _t145*_t70 + 0.2e1*_t69;
  const double _t147 = (0.1e1 / (_t28 * _t28 * _t28));
  const double _t148 = _t147*_t33;
  const double _t149 = _t148*_t76;
  const double _t150 = _t9*params->para[5];
  const double _t151 = _t12*params->para[6];
  const double _t152 = _t150*_t70 + _t151*_t70 + 0.2e1*_t79;
  const double _t153 = (0.1e1 / (_t13 * _t13 * _t13));
  const double _t154 = _t153*_t18;
  const double _t155 = _t154*_t85;
  const double _t156 = _t152*_t155;
  const double _t157 = ((params->ferro[5]) * (params->ferro[5]));
  const double _t158 = _t157*_t23;
  const double _t159 = _t126*_t158;
  const double _t160 = ((params->ferro[6]) * (params->ferro[6]));
  const double _t161 = _t160*_t26;
  const double _t162 = _t126*_t161;
  const double _t163 = -_t122*_t144 - _t122*_t145 - 0.1e1 / 0.2e1*_t159 - 0.1e1 / 0.2e1*_t162 + 0.2e1*_t22*_t4*params->ferro[2]*params->ferro[5] + 0.2e1*_t25*_t4*params->ferro[3]*params->ferro[6] - _t89*params->ferro[1];
  const double _t164 = _t21*_t68;
  const double _t165 = ((params->para[5]) * (params->para[5]));
  const double _t166 = _t165*_t8;
  const double _t167 = _t126*_t166;
  const double _t168 = ((params->para[6]) * (params->para[6]));
  const double _t169 = _t11*_t168;
  const double _t170 = _t126*_t169;
  const double _t171 = 0.2e1*_t10*_t4*params->para[3]*params->para[6] - _t122*_t150 - _t122*_t151 - 0.1e1 / 0.2e1*_t167 - 0.1e1 / 0.2e1*_t170 + 0.2e1*_t4*_t7*params->para[2]*params->para[5] - _t89*params->para[1];
  const double _t172 = _t6*_t78;
  const double _t173 = _t171*_t172;
  const double _t174 = _t102*_t34 - _t104 + _t105*_t106 + _t105*_t110 - _t109 - _t112 + _t114*_t115 - _t119 + _t128*_t129 - _t136 + _t137*_t139 - _t143 + _t146*_t149 - _t156 + _t163*_t164 - _t173;
  const double _t175 = _t174*_t37;
  const double _t176 = 0.4e1*_t45;
  const double _t177 = _t36*_t87;
  const double _t178 = 0.6e1*_t100;
  const double _t179 = _t104 + _t109 + _t112 + _t119 + _t136 + _t143 + _t156 + _t173 + _t175 - _t176*_t177 + _t178*_t90;
  const double _t180 = _t179 + _t99;
  const double _t181 = -_t36*_t95 + 0.2e1*_t49 + 0.2e1*_t66 + 0.2e1*_t86 + 0.2e1*_t88;
  const double _t182 = -_t99;
  const double _t183 = _t92*_t96;
  const double _t184 = _t35*_t89;
  const double _t185 = 0.2e1*_t183 - _t92*_t95;
  const double d2F_dna2 = _t1*(_t180 + _t98) + _t181 + 0.2e1*_t43;
  const double d2F_dna_dnb = _t1*(_t179 + _t182 + _t183 - _t184*_t41 - _t184*_t92 + _t97) + _t181 + _t43 + _t93;
  const double d2F_dnb2 = _t1*(_t180 + _t185) + _t181 + 0.2e1*_t93;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t186 = _t45*_t87;
  const double _t187 = 0.12e2*_t186;
  const double _t188 = _t174*_t4;
  const double _t189 = _t188*_t41;
  const double _t190 = _t100*_t35;
  const double _t191 = 0.18e2*_t190;
  const double _t192 = -_t187*_t41 + 0.3e1*_t189 + _t191*_t41;
  const double _t193 = 0.12e2*_t94;
  const double _t194 = 0.3e1*_t100;
  const double _t195 = xc_powi(_t1, -5);
  const double _t196 = 0.6e1*_t195;
  const double _t197 = _t194 + _t196*params->ferro[4];
  const double _t198 = _t194 + _t196*params->para[4];
  const double _t199 = _t19*_t198;
  const double _t200 = 0.3e1*_t102;
  const double _t201 = 0.3e1*_t103;
  const double _t202 = _t108*_t201;
  const double _t203 = _t111*_t201;
  const double _t204 = 0.3e1*_t47;
  const double _t205 = _t114*_t56;
  const double _t206 = _t205*_t57;
  const double _t207 = 0.3e1*_t48;
  const double _t208 = _t117*_t63;
  const double _t209 = _t208*_t64;
  const double _t210 = _t207*_t209;
  const double _t211 = _t128*_t52;
  const double _t212 = _t134*_t61;
  const double _t213 = _t207*_t212;
  const double _t214 = _t47*_t57;
  const double _t215 = 0.6e1*_t48;
  const double _t216 = _t142*_t64;
  const double _t217 = _t215*_t216;
  const double _t218 = _t4*params->ferro[7];
  const double _t219 = _t121*_t54;
  const double _t220 = _t218 + _t219;
  const double _t221 = (0.1e1 / (_t50 * _t50 * _t50));
  const double _t222 = _t115*_t221*_t29;
  const double _t223 = _t4*params->para[7];
  const double _t224 = _t131*_t54;
  const double _t225 = _t223 + _t224;
  const double _t226 = (0.1e1 / (_t59 * _t59 * _t59));
  const double _t227 = _t118*_t14*_t226;
  const double _t228 = _t225*_t227;
  const double _t229 = _t146*_t148;
  const double _t230 = _t229*_t75;
  const double _t231 = -_t128;
  const double _t232 = _t114*_t58;
  const double _t233 = 0.2e1*_t21;
  const double _t234 = _t128*_t205;
  const double _t235 = _t152*_t154;
  const double _t236 = _t235*_t84;
  const double _t237 = _t207*_t236;
  const double _t238 = 0.2e1*_t6;
  const double _t239 = _t134*_t208;
  const double _t240 = _t238*_t239;
  const double _t241 = -_t134;
  const double _t242 = _t117*_t65;
  const double _t243 = _t241*_t242;
  const double _t244 = 0.3e1*_t75;
  const double _t245 = _t113*_t67;
  const double _t246 = _t115*_t245;
  const double _t247 = 0.3e1*_t84;
  const double _t248 = _t116*_t77;
  const double _t249 = _t118*_t248;
  const double _t250 = _t247*_t249;
  const double _t251 = 0.3e1*_t138;
  const double _t252 = _t128*_t76;
  const double _t253 = 0.3e1*_t141;
  const double _t254 = _t134*_t85;
  const double _t255 = _t253*_t254;
  const double _t256 = _t146*_t147*_t51;
  const double _t257 = _t152*_t153*_t60;
  const double _t258 = _t257*_t65;
  const double _t259 = _t247*_t258;
  const double _t260 = _t163*_t68;
  const double _t261 = _t171*_t78;
  const double _t262 = _t207*_t261;
  const double _t263 = _t194*_t54;
  const double _t264 = 0.8e1*na + 0.8e1*nb;
  const double _t265 = _t125*_t195;
  const double _t266 = (0.3e1 / 0.2e1)*_t265;
  const double _t267 = _t31*((params->ferro[9]) * (params->ferro[9]) * (params->ferro[9]));
  const double _t268 = xc_powi(_t1, -6);
  const double _t269 = (_t54 * _t54 * _t54);
  const double _t270 = _t268*_t269;
  const double _t271 = (0.1e1 / 0.8e1)*_t270;
  const double _t272 = -0.1e1 / 0.4e1*_t100*_t123*_t264*_t30*params->ferro[8] - 0.1e1 / 0.2e1*_t100*_t123*_t30*_t54*params->ferro[8] + _t124*_t266 + _t194*params->ferro[7] + _t263*_t53 + _t267*_t271 - 0.4e1*_t30*_t45*params->ferro[8]*params->ferro[9];
  const double _t273 = -_t272;
  const double _t274 = _t16*((params->para[9]) * (params->para[9]) * (params->para[9]));
  const double _t275 = -0.1e1 / 0.4e1*_t100*_t132*_t15*_t264*params->para[8] - 0.1e1 / 0.2e1*_t100*_t132*_t15*_t54*params->para[8] + _t133*_t266 - 0.4e1*_t15*_t45*params->para[8]*params->para[9] + _t194*params->para[7] + _t263*_t62 + _t271*_t274;
  const double _t276 = -_t275;
  const double _t277 = _t135*_t276;
  const double _t278 = (0.1e1 / (_t28 * _t28 * _t28 * _t28));
  const double _t279 = 0.3e1*_t69 + 0.3e1*_t72 + 0.3e1*_t74;
  const double _t280 = _t146*_t278*_t279;
  const double _t281 = _t33*_t76;
  const double _t282 = (0.1e1 / (_t13 * _t13 * _t13 * _t13));
  const double _t283 = 0.3e1*_t79 + 0.3e1*_t81 + 0.3e1*_t83;
  const double _t284 = _t152*_t282*_t283;
  const double _t285 = _t18*_t85;
  const double _t286 = _t284*_t285;
  const double _t287 = _t163*_t58;
  const double _t288 = _t171*_t65;
  const double _t289 = _t253*_t288;
  const double _t290 = _t176*_t54;
  const double _t291 = -_t159 - _t162 - _t176*params->ferro[1] + 0.4e1*_t22*_t4*params->ferro[2]*params->ferro[5] + 0.4e1*_t25*_t4*params->ferro[3]*params->ferro[6] - _t290*_t71 - _t290*_t73;
  const double _t292 = 0.4e1*_t10*_t4*params->para[3]*params->para[6] - _t167 - _t170 - _t176*params->para[1] - _t290*_t80 - _t290*_t82 + 0.4e1*_t4*_t7*params->para[2]*params->para[5];
  const double _t293 = _t155*_t292;
  const double _t294 = _t163*_t229;
  const double _t295 = _t171*_t235;
  const double _t296 = _t238*_t295;
  const double _t297 = 0.8e1*_t45;
  const double _t298 = _t178*_t54;
  const double _t299 = _t100*_t54;
  const double _t300 = _t100*_t264;
  const double _t301 = _t158*_t300;
  const double _t302 = _t161*_t300;
  const double _t303 = 0.3e1*_t265;
  const double _t304 = (0.1e1 / 0.4e1)*_t270;
  const double _t305 = ((params->ferro[5]) * (params->ferro[5]) * (params->ferro[5]));
  const double _t306 = _t23*_t305;
  const double _t307 = ((params->ferro[6]) * (params->ferro[6]) * (params->ferro[6]));
  const double _t308 = _t26*_t307;
  const double _t309 = -_t158*_t299 + _t158*_t303 - _t161*_t299 + _t161*_t303 + _t178*params->ferro[1] - _t297*_t71 - _t297*_t73 + _t298*_t71 + _t298*_t73 - 0.1e1 / 0.2e1*_t301 - 0.1e1 / 0.2e1*_t302 + _t304*_t306 + _t304*_t308;
  const double _t310 = _t166*_t300;
  const double _t311 = _t169*_t300;
  const double _t312 = ((params->para[5]) * (params->para[5]) * (params->para[5]));
  const double _t313 = _t312*_t8;
  const double _t314 = ((params->para[6]) * (params->para[6]) * (params->para[6]));
  const double _t315 = _t11*_t314;
  const double _t316 = -_t166*_t299 + _t166*_t303 - _t169*_t299 + _t169*_t303 + _t178*params->para[1] - _t297*_t80 - _t297*_t82 + _t298*_t80 + _t298*_t82 + _t304*_t313 + _t304*_t315 - 0.1e1 / 0.2e1*_t310 - 0.1e1 / 0.2e1*_t311;
  const double _t317 = _t172*_t316;
  const double _t318 = _t106*_t200 + _t110*_t200 + _t129*_t273 + 0.6e1*_t139*_t214 + _t149*_t291 + _t164*_t309 + _t197*_t34 - _t199 - _t202 - _t203 + _t204*_t206 + _t204*_t211 + _t204*_t230 + _t204*_t260 - _t210 - _t213 - _t217 + _t220*_t222 - _t228 + _t231*_t232 + _t233*_t234 + _t233*_t294 - _t237 - _t240 - _t243 + _t244*_t246 + _t244*_t256*_t58 - _t250 + _t251*_t252 + _t251*_t287 - _t255 - _t259 - _t262 - _t277 + _t280*_t281 - _t286 - _t289 - _t293 - _t296 - _t317;
  const double _t319 = _t318*_t37;
  const double _t320 = 0.24e2*_t195;
  const double _t321 = 0.6e1*_t45;
  const double _t322 = _t174*_t36;
  const double _t323 = _t100*_t177;
  const double _t324 = _t199 + _t202 + _t203 + _t210 + _t213 + _t217 + _t228 + _t237 + _t240 + _t243 + _t250 + _t255 + _t259 + _t262 + _t277 + _t286 + _t289 + _t293 + _t296 + _t317 + _t319 - _t320*_t90 - _t321*_t322 + 0.18e2*_t323;
  const double _t325 = -_t193 + _t324 + 0.6e1*_t96;
  const double _t326 = 0.3e1*_t104 + _t108*_t215 + _t111*_t215 + 0.3e1*_t119 + 0.3e1*_t136 + 0.6e1*_t142*_t65 + 0.3e1*_t156 + 0.3e1*_t173 + 0.3e1*_t175 - _t187*_t36 + _t191*_t36;
  const double _t327 = _t326 + 0.6e1*_t42;
  const double _t328 = _t188*_t92;
  const double _t329 = 0.8e1*_t41;
  const double _t330 = _t176*_t87;
  const double _t331 = _t178*_t35;
  const double _t332 = 0.12e2*_t190;
  const double _t333 = _t324 + _t95 - 0.2e1*_t96;
  const double _t334 = _t182 + _t326;
  const double _t335 = 0.8e1*_t92;
  const double _t336 = -_t187*_t92 + _t191*_t92 + 0.3e1*_t328;
  const double d3F_dna3 = _t1*(_t192 + _t325) - _t193*_t41 + _t327 + 0.6e1*_t97;
  const double d3F_dna2_dnb = _t1*(-_t186*_t329 + 0.2e1*_t189 + _t328 - _t330*_t92 + _t331*_t92 + _t332*_t41 + _t333) + _t185 - _t329*_t94 + _t334 + 0.4e1*_t97;
  const double d3F_dna_dnb2 = _t1*(-_t186*_t335 + _t189 + 0.2e1*_t328 - _t330*_t41 + _t331*_t41 + _t332*_t92 + _t333) + 0.4e1*_t183 + _t334 - _t335*_t94 + _t98;
  const double d3F_dnb3 = _t1*(_t325 + _t336) + 0.6e1*_t183 - _t193*_t92 + _t327;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t337 = 0.96e2*_t195;
  const double _t338 = _t35*_t41;
  const double _t339 = 0.24e2*_t45;
  const double _t340 = _t174*_t41;
  const double _t341 = _t318*_t4;
  const double _t342 = _t341*_t41;
  const double _t343 = _t100*_t87;
  const double _t344 = _t343*_t41;
  const double _t345 = 0.48e2*_t186;
  const double _t346 = 0.72e2*_t190;
  const double _t347 = 0.12e2*_t195;
  const double _t348 = 0.30e2*_t268;
  const double _t349 = _t19*(-_t347 - _t348*params->para[4]);
  const double _t350 = 0.4e1*_t197;
  const double _t351 = 0.4e1*_t198;
  const double _t352 = _t108*_t351;
  const double _t353 = _t111*_t351;
  const double _t354 = 0.6e1*_t102;
  const double _t355 = 0.6e1*_t103;
  const double _t356 = _t209*_t355;
  const double _t357 = _t212*_t355;
  const double _t358 = 0.12e2*_t139;
  const double _t359 = 0.12e2*_t103;
  const double _t360 = _t216*_t359;
  const double _t361 = 0.4e1*_t47;
  const double _t362 = _t361*_t57;
  const double _t363 = _t220*_t29;
  const double _t364 = _t221*_t363;
  const double _t365 = _t364*_t56;
  const double _t366 = 0.4e1*_t48;
  const double _t367 = _t366*_t64;
  const double _t368 = _t14*_t225;
  const double _t369 = _t226*_t368;
  const double _t370 = _t369*_t63;
  const double _t371 = _t367*_t370;
  const double _t372 = 0.8e1*_t47;
  const double _t373 = _t236*_t355;
  const double _t374 = 0.8e1*_t48;
  const double _t375 = _t239*_t374;
  const double _t376 = _t114*_t231;
  const double _t377 = _t117*_t241;
  const double _t378 = _t367*_t377;
  const double _t379 = _t245*_t56;
  const double _t380 = 0.12e2*_t214;
  const double _t381 = _t380*_t75;
  const double _t382 = 0.12e2*_t48;
  const double _t383 = _t382*_t64;
  const double _t384 = _t383*_t84;
  const double _t385 = _t248*_t63;
  const double _t386 = _t384*_t385;
  const double _t387 = _t118*_t368*((0.3e1 / 0.2e1)*_t223 + (0.3e1 / 0.2e1)*_t224)/(_t59 * _t59 * _t59 * _t59);
  const double _t388 = _t134*_t142*_t382;
  const double _t389 = 0.3e1*_t21;
  const double _t390 = _t128*_t389;
  const double _t391 = _t134*_t6;
  const double _t392 = 0.3e1*_t391;
  const double _t393 = _t370*_t392;
  const double _t394 = _t140*_t241*_t369;
  const double _t395 = _t54*_t89;
  const double _t396 = (0.1e1 / 0.2e1)*_t126;
  const double _t397 = _t257*_t384;
  const double _t398 = _t227*(-0.2e1*_t130 - _t133*_t396 + 0.2e1*_t15*_t4*params->para[8]*params->para[9] - _t395*_t62);
  const double _t399 = _t261*_t355;
  const double _t400 = 0.4e1*_t75;
  const double _t401 = 0.4e1*_t118*_t225*_t226*_t77*_t84;
  const double _t402 = _t377*_t392;
  const double _t403 = _t276*_t366*_t61;
  const double _t404 = 0.8e1*_t254*_t385;
  const double _t405 = _t400*_t58;
  const double _t406 = 0.4e1*_t65;
  const double _t407 = _t241*_t248*_t406*_t84;
  const double _t408 = _t361*_t75;
  const double _t409 = _t280*_t33;
  const double _t410 = _t366*_t84;
  const double _t411 = _t18*_t284;
  const double _t412 = _t410*_t411;
  const double _t413 = _t153*_t84;
  const double _t414 = 0.6e1*_t116*_t118*_t152*_t413;
  const double _t415 = _t138*_t163;
  const double _t416 = _t141*_t171;
  const double _t417 = _t383*_t416;
  const double _t418 = 0.6e1*_t254*_t257;
  const double _t419 = _t242*_t275;
  const double _t420 = 0.3e1*_t6;
  const double _t421 = _t208*_t276*_t420;
  const double _t422 = _t148*_t291;
  const double _t423 = _t154*_t292;
  const double _t424 = _t410*_t423;
  const double _t425 = _t405*_t51;
  const double _t426 = _t406*_t60;
  const double _t427 = _t284*_t426*_t84;
  const double _t428 = _t295*_t374;
  const double _t429 = 0.4e1*_t138;
  const double _t430 = 0.4e1*_t141;
  const double _t431 = _t276*_t430*_t85;
  const double _t432 = 0.6e1*_t171*_t249;
  const double _t433 = _t152*_t283*_t285*(0.4e1*_t79 + 0.4e1*_t81 + 0.4e1*_t83)/xc_powi(_t13, 5);
  const double _t434 = 0.6e1*_t391*_t416;
  const double _t435 = _t292*_t413*_t426;
  const double _t436 = 0.8e1*_t257*_t288;
  const double _t437 = _t321*_t54;
  const double _t438 = _t101*_t125;
  const double _t439 = _t278*_t281;
  const double _t440 = _t282*_t285;
  const double _t441 = _t152*_t440*(0.6e1*_t10*_t4*params->para[3]*params->para[6] - _t166*_t438 - _t169*_t438 - _t321*params->para[1] + 0.6e1*_t4*_t7*params->para[2]*params->para[5] - _t437*_t80 - _t437*_t82);
  const double _t442 = 0.2e1*_t283*_t292*_t440;
  const double _t443 = _t163*_t389;
  const double _t444 = _t171*_t420;
  const double _t445 = _t411*_t444;
  const double _t446 = 0.18e2*_t100;
  const double _t447 = _t347*_t54;
  const double _t448 = _t124*_t195;
  const double _t449 = 0.4e1*_t54;
  const double _t450 = (0.5e1 / 0.2e1)*_t264;
  const double _t451 = _t125*_t268;
  const double _t452 = 0.9e1*_t451;
  const double _t453 = _t269/xc_powi(_t1, 7);
  const double _t454 = (0.3e1 / 0.2e1)*_t453;
  const double _t455 = (_t54 * _t54 * _t54 * _t54)/xc_powi(_t1, 8);
  const double _t456 = (0.1e1 / 0.16e2)*_t455;
  const double _t457 = (0.1e1 / 0.8e1)*_t264*_t268*_t54;
  const double _t458 = _t133*_t195;
  const double _t459 = _t135*(_t133*_t194 + _t133*_t452 + _t16*_t456*((params->para[9]) * (params->para[9]) * (params->para[9]) * (params->para[9])) - _t274*_t451 + _t274*_t454 - _t274*_t457 + _t347*params->para[7] - _t446*_t62 + _t447*_t62 - _t449*_t458 - _t450*_t458);
  const double _t460 = _t423*_t444;
  const double _t461 = _t316*_t366*_t78;
  const double _t462 = _t316*_t430*_t65;
  const double _t463 = 0.12e2*_t100;
  const double _t464 = 0.16e2*_t45;
  const double _t465 = _t463*_t54;
  const double _t466 = _t125*_t196;
  const double _t467 = (0.1e1 / 0.2e1)*_t270;
  const double _t468 = _t155*(-_t12*_t168*_t299 - _t165*_t299*_t9 + _t166*_t466 + _t169*_t466 - _t310 - _t311 + _t313*_t467 + _t315*_t467 + _t463*params->para[1] - _t464*_t80 - _t464*_t82 + _t465*_t80 + _t465*_t82);
  const double _t469 = _t235*_t316*_t420;
  const double _t470 = _t320*_t54;
  const double _t471 = 0.18e2*_t451;
  const double _t472 = 0.3e1*_t453;
  const double _t473 = (0.1e1 / 0.8e1)*_t455;
  const double _t474 = _t172*(0.36e2*_t10*_t100*params->para[3]*params->para[6] + 0.2e1*_t10*_t125*_t268*_t314*params->para[3] + 0.5e1*_t10*_t168*_t195*_t264*params->para[3] + 0.8e1*_t10*_t168*_t195*_t54*params->para[3] + (0.1e1 / 0.4e1)*_t10*_t264*_t268*_t314*_t54*params->para[3] + 0.36e2*_t100*_t7*params->para[2]*params->para[5] - _t11*_t473*((params->para[6]) * (params->para[6]) * (params->para[6]) * (params->para[6])) + 0.2e1*_t125*_t268*_t312*_t7*params->para[2] + 0.5e1*_t165*_t195*_t264*_t7*params->para[2] + 0.8e1*_t165*_t195*_t54*_t7*params->para[2] - _t166*_t178 - _t166*_t471 - _t169*_t178 - _t169*_t471 + (0.1e1 / 0.4e1)*_t264*_t268*_t312*_t54*_t7*params->para[2] - _t313*_t472 - _t315*_t472 - _t320*params->para[1] - _t470*_t80 - _t470*_t82 - _t473*_t8*((params->para[5]) * (params->para[5]) * (params->para[5]) * (params->para[5])));
  const double _t475 = 0.36e2*_t100;
  const double _t476 = -_t177*_t337 + 0.120e3*_t268*_t90 - _t297*_t318*_t36 + _t322*_t475 + _t349 + _t352 + _t353 + _t356 + _t357 + _t360 + _t37*(_t102*_t358*_t57 + _t106*_t350 + _t110*_t350 + 0.6e1*_t113*_t115*_t146*_t147*_t75 + _t115*_t220*_t221*_t400*_t67 + _t115*_t363*((0.3e1 / 0.2e1)*_t218 + (0.3e1 / 0.2e1)*_t219)/(_t50 * _t50 * _t50 * _t50) + 0.6e1*_t128*_t21*_t415 + _t128*_t358*_t47 + _t129*(_t124*_t194 + _t124*_t452 - _t267*_t451 + _t267*_t454 - _t267*_t457 + _t31*_t456*((params->ferro[9]) * (params->ferro[9]) * (params->ferro[9]) * (params->ferro[9])) + _t347*params->ferro[7] - _t446*_t53 + _t447*_t53 - _t448*_t449 - _t448*_t450) + _t137*_t231*_t364 + _t146*_t279*_t281*(0.4e1*_t69 + 0.4e1*_t72 + 0.4e1*_t74)/xc_powi(_t28, 5) + _t146*_t439*(-_t158*_t438 - _t161*_t438 + 0.6e1*_t22*_t4*params->ferro[2]*params->ferro[5] + 0.6e1*_t25*_t4*params->ferro[3]*params->ferro[6] - _t321*params->ferro[1] - _t437*_t71 - _t437*_t73) + _t147*_t291*_t425 + _t149*(-_t157*_t24*_t299 + _t158*_t466 - _t160*_t27*_t299 + _t161*_t466 - _t301 - _t302 + _t306*_t467 + _t308*_t467 + _t463*params->ferro[1] - _t464*_t71 - _t464*_t73 + _t465*_t71 + _t465*_t73) + 0.6e1*_t163*_t246 + _t164*(0.36e2*_t100*_t22*params->ferro[2]*params->ferro[5] + 0.36e2*_t100*_t25*params->ferro[3]*params->ferro[6] + 0.2e1*_t125*_t22*_t268*_t305*params->ferro[2] + 0.2e1*_t125*_t25*_t268*_t307*params->ferro[3] + 0.5e1*_t157*_t195*_t22*_t264*params->ferro[2] + 0.8e1*_t157*_t195*_t22*_t54*params->ferro[2] - _t158*_t178 - _t158*_t471 + 0.5e1*_t160*_t195*_t25*_t264*params->ferro[3] + 0.8e1*_t160*_t195*_t25*_t54*params->ferro[3] - _t161*_t178 - _t161*_t471 + (0.1e1 / 0.4e1)*_t22*_t264*_t268*_t305*_t54*params->ferro[2] - _t23*_t473*((params->ferro[5]) * (params->ferro[5]) * (params->ferro[5]) * (params->ferro[5])) + (0.1e1 / 0.4e1)*_t25*_t264*_t268*_t307*_t54*params->ferro[3] - _t26*_t473*((params->ferro[6]) * (params->ferro[6]) * (params->ferro[6]) * (params->ferro[6])) - _t306*_t472 - _t308*_t472 - _t320*params->ferro[1] - _t470*_t71 - _t470*_t73) + _t205*_t273*_t389 + _t206*_t354 + _t211*_t354 + _t222*(-0.2e1*_t120 - _t124*_t396 + 0.2e1*_t30*_t4*params->ferro[8]*params->ferro[9] - _t395*_t53) + _t229*_t309*_t389 + _t230*_t354 + _t231*_t245*_t405 + _t232*_t272 + _t234*_t372 + 0.6e1*_t252*_t256 + 0.8e1*_t252*_t379 + 0.8e1*_t256*_t287 + _t256*_t381 + _t260*_t354 + _t273*_t361*_t52 + _t273*_t429*_t76 + 0.2e1*_t279*_t291*_t439 + _t280*_t425 + _t294*_t372 + _t309*_t361*_t68 + _t309*_t429*_t58 + _t34*(-_t347 - _t348*params->ferro[4]) - _t349 - _t352 - _t353 - _t356 - _t357 - _t360 + _t362*_t365 + _t362*_t376 + _t365*_t390 - _t371 - _t373 - _t375 + _t376*_t390 - _t378 + _t379*_t381 + _t380*_t415 - _t386 - _t387 - _t388 - _t393 - _t394 - _t397 - _t398 - _t399 - _t401 - _t402 - _t403 - _t404 - _t407 + _t408*_t409 + _t408*_t422 + _t409*_t443 - _t412 - _t414 - _t417 - _t418 - _t419 - _t421 + _t422*_t443 - _t424 - _t427 - _t428 - _t431 - _t432 - _t433 - _t434 - _t435 - _t436 - _t441 - _t442 - _t445 - _t459 - _t460 - _t461 - _t462 - _t468 - _t469 - _t474) + _t371 + _t373 + _t375 + _t378 + _t386 + _t387 + _t388 + _t393 + _t394 + _t397 + _t398 + _t399 + _t401 + _t402 + _t403 + _t404 + _t407 + _t412 + _t414 + _t417 + _t418 + _t419 + _t421 + _t424 + _t427 + _t428 + _t431 + _t432 + _t433 + _t434 + _t435 + _t436 + _t441 + _t442 + _t445 + _t459 + _t460 + _t461 + _t462 + _t468 + _t469 + _t474;
  const double _t477 = 0.12e2*_t188 - _t345 + _t346 + _t476;
  const double _t478 = 0.8e1*_t6;
  const double _t479 = 0.12e2*_t141;
  const double _t480 = 0.12e2*_t84;
  const double _t481 = _t108*_t359 + _t111*_t359 + 0.4e1*_t199 + _t209*_t382 + _t212*_t382 + 0.24e2*_t216*_t48 + 0.4e1*_t228 + _t236*_t382 + _t239*_t478 + 0.4e1*_t243 + _t249*_t480 + _t254*_t479 + _t258*_t480 + _t261*_t382 + 0.4e1*_t277 + 0.4e1*_t286 + _t288*_t479 + 0.4e1*_t293 + _t295*_t478 + 0.4e1*_t317 + 0.4e1*_t319 - _t322*_t339 + 0.72e2*_t323 - _t337*_t90;
  const double _t482 = _t481 - 0.48e2*_t94 + 0.24e2*_t96;
  const double _t483 = _t341*_t92;
  const double _t484 = _t195*_t338;
  const double _t485 = _t35*_t92;
  const double _t486 = _t340*_t45;
  const double _t487 = _t174*_t92;
  const double _t488 = _t343*_t92;
  const double _t489 = _t186*_t41;
  const double _t490 = _t190*_t41;
  const double _t491 = _t195*_t485;
  const double _t492 = _t45*_t487;
  const double _t493 = _t475*_t87;
  const double _t494 = _t186*_t92;
  const double _t495 = _t190*_t92;
  const double d4F_dna4 = _t1*(-_t337*_t338 - _t339*_t340 + 0.4e1*_t342 + 0.72e2*_t344 + _t477) + 0.12e2*_t189 - _t345*_t41 + _t346*_t41 + _t482;
  const double d4F_dna3_dnb = _t1*(-_t320*_t485 - _t321*_t487 + 0.3e1*_t342 + 0.54e2*_t344 + _t476 + _t483 - 0.72e2*_t484 - 0.18e2*_t486 + 0.18e2*_t488) + 0.9e1*_t189 + _t336 + _t481 - 0.36e2*_t489 + 0.54e2*_t490;
  const double d4F_dna2_dnb2 = _t1*(0.16e2*_t186 - 0.4e1*_t188 - 0.24e2*_t190 + 0.2e1*_t342 + _t41*_t493 + _t476 + 0.2e1*_t483 - 0.48e2*_t484 - 0.12e2*_t486 - 0.48e2*_t491 - 0.12e2*_t492 + _t493*_t92) + 0.6e1*_t189 + 0.6e1*_t328 + _t481 - 0.24e2*_t489 + 0.36e2*_t490 - 0.24e2*_t494 + 0.36e2*_t495 + 0.16e2*_t94 - 0.8e1*_t96;
  const double d4F_dna_dnb3 = _t1*(-_t320*_t338 - _t321*_t340 + _t342 + 0.18e2*_t344 + _t476 + 0.3e1*_t483 + 0.54e2*_t488 - 0.72e2*_t491 - 0.18e2*_t492) + _t192 + 0.9e1*_t328 + _t481 - 0.36e2*_t494 + 0.54e2*_t495;
  const double d4F_dnb4 = _t1*(-_t337*_t485 - _t339*_t487 + _t477 + 0.4e1*_t483 + 0.72e2*_t488) + 0.12e2*_t328 - _t345*_t92 + _t346*_t92 + _t482;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif