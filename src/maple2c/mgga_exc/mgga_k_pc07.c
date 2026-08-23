/*
  Generated from python/mgga_exc/mgga_k_pc07.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_k_pc07
*/

#ifndef _MGGA_K_PC07_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_K_PC07_KERNEL_BODY
#define _KMAX 0
#define _MGGA_K_PC07_HELPER_BODIES
#include "mgga_k_pc07.c"
#undef _MGGA_K_PC07_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_K_PC07_HELPER_BODIES
#include "mgga_k_pc07.c"
#undef _MGGA_K_PC07_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_K_PC07_HELPER_BODIES
#include "mgga_k_pc07.c"
#undef _MGGA_K_PC07_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_K_PC07_HELPER_BODIES
#include "mgga_k_pc07.c"
#undef _MGGA_K_PC07_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_K_PC07_HELPER_BODIES
#include "mgga_k_pc07.c"
#undef _MGGA_K_PC07_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_k_pc07.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_K_PC07_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_fab0_k, _KMAX)(const xc_func_type *p, double z, double *out) {
  const mgga_k_pc07_params *params = (const mgga_k_pc07_params *)(p->params);

  const double _t1 = (0.1e1 / z);
  const double _t2 = _t1*params->pc07_a;
  const double _t3 = exp(-_t2);
  const double _t4 = params->pc07_a - z;
  const double _t5 = (0.1e1 / _t4);
  const double _t6 = _t5*params->pc07_a;
  const double _t7 = exp(-_t6);
  const double _t8 = _t3 + _t7;
  const double _t9 = pow(_t8, -params->pc07_b);
  const double _t10 = _t7 + 0.1e1;
  const double _t11 = pow(_t10, params->pc07_b);
  const double _t12 = exp(-_t2*params->pc07_b);
  const double _t13 = _t11*_t12;
  const double _t14 = _t13*_t9;
#if _KMAX >= 1
  const double _t15 = (0.1e1 / (z * z));
  const double _t16 = (0.1e1 / (_t4 * _t4));
  const double _t17 = _t7*params->pc07_a;
  const double _t18 = _t16*_t17;
  const double _t19 = (0.1e1 / _t10);
  const double _t20 = _t14*params->pc07_b;
  const double _t21 = _t19*_t20;
  const double _t22 = -_t15*_t3*params->pc07_a + _t18;
  const double _t23 = -_t22;
  const double _t24 = (0.1e1 / _t8);
  const double _t25 = _t20*_t24;
#endif
#if _KMAX >= 2
  const double _t26 = (0.1e1 / (z * z * z));
  const double _t27 = _t20*params->pc07_a;
  const double _t28 = ((params->pc07_a) * (params->pc07_a));
  const double _t29 = ((params->pc07_b) * (params->pc07_b));
  const double _t30 = (0.1e1 / (z * z * z * z));
  const double _t31 = (0.1e1 / (_t4 * _t4 * _t4));
  const double _t32 = _t17*_t31;
  const double _t33 = 0.2e1*_t32;
  const double _t34 = (0.1e1 / (_t4 * _t4 * _t4 * _t4));
  const double _t35 = (0.1e1 / (_t10 * _t10));
  const double _t36 = exp(-0.2e1*_t6);
  const double _t37 = _t35*_t36;
  const double _t38 = _t34*_t37;
  const double _t39 = _t20*_t28;
  const double _t40 = pow(_t8, -params->pc07_b - 0.2e1);
  const double _t41 = (_t23 * _t23);
  const double _t42 = _t15*_t16;
  const double _t43 = _t28*_t7;
  const double _t44 = _t14*_t29;
  const double _t45 = _t19*_t44;
  const double _t46 = _t43*_t45;
  const double _t47 = _t23*_t44;
  const double _t48 = _t15*params->pc07_a;
  const double _t49 = _t24*_t48;
  const double _t50 = (0.1e1 / (_t8 * _t8));
  const double _t51 = _t20*_t50;
  const double _t52 = _t22*_t23;
  const double _t53 = _t3*params->pc07_a;
  const double _t54 = _t26*_t53;
  const double _t55 = _t28*_t3;
  const double _t56 = _t30*_t55;
  const double _t57 = _t34*_t43;
  const double _t58 = -_t33 - 0.2e1*_t54 + _t56 + _t57;
#endif
#if _KMAX >= 3
  const double _t59 = xc_powi(z, -5);
  const double _t60 = _t28*_t44;
  const double _t61 = 0.6e1*_t60;
  const double _t62 = ((params->pc07_a) * (params->pc07_a) * (params->pc07_a));
  const double _t63 = ((params->pc07_b) * (params->pc07_b) * (params->pc07_b));
  const double _t64 = xc_powi(z, -6);
  const double _t65 = _t17*_t34;
  const double _t66 = 0.6e1*_t65;
  const double _t67 = xc_powi(_t4, -6);
  const double _t68 = _t62*_t7;
  const double _t69 = _t67*_t68;
  const double _t70 = xc_powi(_t4, -5);
  const double _t71 = _t62*_t67;
  const double _t72 = (0.1e1 / (_t10 * _t10 * _t10));
  const double _t73 = exp(-0.3e1*_t6);
  const double _t74 = _t72*_t73;
  const double _t75 = _t20*_t74;
  const double _t76 = _t14*_t63;
  const double _t77 = _t62*_t76;
  const double _t78 = _t67*_t77;
  const double _t79 = _t74*_t78;
  const double _t80 = _t37*_t44;
  const double _t81 = _t13*_t63;
  const double _t82 = pow(_t8, -params->pc07_b - 0.3e1);
  const double _t83 = (_t23 * _t23 * _t23);
  const double _t84 = _t82*_t83;
  const double _t85 = (_t22 * _t22 * _t22);
  const double _t86 = _t15*_t31;
  const double _t87 = _t38*_t62;
  const double _t88 = 0.3e1*_t76;
  const double _t89 = _t19*_t68;
  const double _t90 = _t30*_t89;
  const double _t91 = _t16*_t90;
  const double _t92 = _t40*_t41;
  const double _t93 = pow(_t10, params->pc07_b - 0.1e1);
  const double _t94 = _t1*params->pc07_b;
  const double _t95 = exp(-params->pc07_a*(_t5 + _t94));
  const double _t96 = _t16*_t93*_t95*params->pc07_a;
  const double _t97 = _t63*_t96;
  const double _t98 = _t28*_t30;
  const double _t99 = _t23*_t24;
  const double _t100 = _t88*_t99;
  const double _t101 = -0.2e1*_t15*_t53 + 0.2e1*_t18;
  const double _t102 = 0.3e1*_t57;
  const double _t103 = _t24*_t47;
  const double _t104 = _t103*_t19;
  const double _t105 = _t28*_t38;
  const double _t106 = _t44*_t50;
  const double _t107 = _t106*_t52;
  const double _t108 = 0.3e1*_t58;
  const double _t109 = (0.1e1 / (_t8 * _t8 * _t8));
  const double _t110 = _t109*_t52;
  const double _t111 = _t110*_t20;
  const double _t112 = _t22*_t51;
  const double _t113 = 0.2e1*_t58;
  const double _t114 = -_t58;
  const double _t115 = _t23*_t51;
  const double _t116 = _t55*_t59;
  const double _t117 = 0.6e1*_t116 - 0.6e1*_t28*_t7*_t70 - 0.6e1*_t3*_t30*params->pc07_a - _t3*_t62*_t64 + _t66 + _t69;
  const double _t118 = -_t117;
  const double _t119 = -0.4e1*_t32 - 0.4e1*_t54 + 0.2e1*_t56 + 0.2e1*_t57;
#endif
#if _KMAX >= 4
  const double _t120 = 0.24e2*_t59;
  const double _t121 = ((params->pc07_a) * (params->pc07_a) * (params->pc07_a) * (params->pc07_a));
  const double _t122 = _t121/xc_powi(z, 8);
  const double _t123 = ((params->pc07_b) * (params->pc07_b) * (params->pc07_b) * (params->pc07_b));
  const double _t124 = _t123*_t14;
  const double _t125 = 0.36e2*_t64;
  const double _t126 = 0.12e2/xc_powi(z, 7);
  const double _t127 = 0.24e2*_t70;
  const double _t128 = _t127*_t17;
  const double _t129 = _t121/xc_powi(_t4, 8);
  const double _t130 = _t129*_t7;
  const double _t131 = 0.36e2*_t67;
  const double _t132 = _t131*_t37;
  const double _t133 = _t131*_t43;
  const double _t134 = xc_powi(_t4, -7);
  const double _t135 = _t134*_t62;
  const double _t136 = _t20*_t37;
  const double _t137 = 0.36e2*_t135;
  const double _t138 = 0.12e2*_t134;
  const double _t139 = _t138*_t68;
  const double _t140 = _t129*exp(-0.4e1*_t6)/(_t10 * _t10 * _t10 * _t10);
  const double _t141 = 0.7e1*_t129;
  const double _t142 = _t44*_t74;
  const double _t143 = 0.6e1*_t76;
  const double _t144 = pow(_t8, -params->pc07_b - 0.4e1);
  const double _t145 = _t144*_t81;
  const double _t146 = _t123*_t13;
  const double _t147 = 0.24e2*_t30;
  const double _t148 = _t15*_t45;
  const double _t149 = 0.12e2*_t44;
  const double _t150 = _t149*_t26;
  const double _t151 = _t34*_t89;
  const double _t152 = _t15*_t80;
  const double _t153 = _t120*_t76;
  const double _t154 = 0.12e2*_t76;
  const double _t155 = 0.12e2*_t38*_t77;
  const double _t156 = _t15*_t37;
  const double _t157 = _t121*_t67;
  const double _t158 = _t15*_t157;
  const double _t159 = 0.6e1*_t30;
  const double _t160 = _t121*_t159*_t76;
  const double _t161 = _t19*_t7;
  const double _t162 = _t154*_t157;
  const double _t163 = 0.4e1*_t124;
  const double _t164 = _t163*_t64;
  const double _t165 = _t124*_t38;
  const double _t166 = _t163*_t74;
  const double _t167 = _t26*params->pc07_a;
  const double _t168 = 0.12e2*_t92;
  const double _t169 = _t81*_t82;
  const double _t170 = 0.4e1*_t48;
  const double _t171 = 0.6e1*_t92;
  const double _t172 = _t63*_t93*_t95;
  const double _t173 = 0.4e1*_t82*_t97;
  const double _t174 = _t171*_t28*_t34;
  const double _t175 = pow(_t10, params->pc07_b - 0.2e1)*_t174*exp(-params->pc07_a*(0.2e1*_t5 + _t94));
  const double _t176 = _t28*_t99;
  const double _t177 = _t62*_t99;
  const double _t178 = _t13*_t29;
  const double _t179 = _t144*_t178*_t85;
  const double _t180 = -0.3e1*_t15*_t3*params->pc07_a + 0.3e1*_t18;
  const double _t181 = _t145*_t83;
  const double _t182 = _t169*_t41;
  const double _t183 = _t101*_t170;
  const double _t184 = 0.24e2*_t104;
  const double _t185 = _t127*_t37;
  const double _t186 = _t103*_t71;
  const double _t187 = 0.12e2*_t99;
  const double _t188 = _t101*_t41;
  const double _t189 = 0.12e2*_t107;
  const double _t190 = 0.24e2*_t19*_t43*_t76*_t99;
  const double _t191 = _t15*_t99;
  const double _t192 = _t143*_t98;
  const double _t193 = _t50*_t52;
  const double _t194 = _t24*_t58;
  const double _t195 = _t149*_t194;
  const double _t196 = -_t119;
  const double _t197 = _t19*_t32;
  const double _t198 = 0.6e1*_t57;
  const double _t199 = _t105*_t143;
  const double _t200 = _t110*_t44;
  const double _t201 = _t154*_t19*_t42*_t43;
  const double _t202 = _t106*_t58;
  const double _t203 = 0.8e1*_t202*_t22;
  const double _t204 = _t23*_t50*_t76;
  const double _t205 = _t170*_t204;
  const double _t206 = _t106*_t23;
  const double _t207 = _t114*_t206;
  const double _t208 = _t118*_t24*_t44;
  const double _t209 = _t18*_t19;
  const double _t210 = 0.4e1*_t209;
  const double _t211 = _t101*_t109;
  const double _t212 = _t20*_t211;
  const double _t213 = _t211*_t47;
  const double _t214 = _t204*_t210;
#endif

  const double f = _t14;
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = _t11*_t12*_t15*_t9*params->pc07_a*params->pc07_b - _t18*_t21 - _t23*_t25;
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = 0.2e1*_t11*_t12*_t16*_t19*_t23*_t24*_t29*_t7*_t9*params->pc07_a + _t11*_t12*_t19*_t28*_t34*_t7*_t9*params->pc07_b + _t11*_t12*_t28*_t29*_t30*_t9 + _t11*_t12*_t28*_t29*_t34*_t35*_t36*_t9 + _t11*_t12*_t29*_t40*_t41 - _t21*_t33 - _t25*_t58 - 0.2e1*_t26*_t27 - _t38*_t39 - 0.2e1*_t42*_t46 - 0.2e1*_t47*_t49 - _t51*_t52;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = -_t100*_t105 - _t100*_t98 + _t101*_t11*_t12*_t29*_t41*_t82 - _t101*_t111 - _t102*_t104 - 0.3e1*_t107*_t48 - _t108*_t44*_t49 + _t11*_t119*_t12*_t23*_t29*_t50*_t9 + 0.6e1*_t11*_t12*_t15*_t16*_t19*_t23*_t24*_t28*_t63*_t7*_t9 + 0.3e1*_t11*_t12*_t15*_t19*_t29*_t34*_t62*_t7*_t9 + 0.3e1*_t11*_t12*_t15*_t34*_t35*_t36*_t62*_t63*_t9 + 0.3e1*_t11*_t12*_t15*_t40*_t41*_t63*params->pc07_a + 0.3e1*_t11*_t12*_t16*_t19*_t22*_t23*_t29*_t50*_t7*_t9*params->pc07_a + 0.3e1*_t11*_t12*_t16*_t19*_t24*_t29*_t58*_t7*_t9*params->pc07_a + 0.6e1*_t11*_t12*_t16*_t19*_t26*_t28*_t29*_t7*_t9 + 0.6e1*_t11*_t12*_t19*_t23*_t24*_t29*_t31*_t7*_t9*params->pc07_a + 0.6e1*_t11*_t12*_t19*_t28*_t7*_t70*_t9*params->pc07_b + 0.6e1*_t11*_t12*_t23*_t24*_t26*_t29*_t9*params->pc07_a + 0.3e1*_t11*_t12*_t23*_t24*_t28*_t29*_t34*_t35*_t36*_t9 + _t11*_t12*_t23*_t29*_t50*_t58*_t9 + 0.6e1*_t11*_t12*_t28*_t29*_t35*_t36*_t70*_t9 + 0.3e1*_t11*_t12*_t29*_t62*_t67*_t72*_t73*_t9 + _t11*_t12*_t29*_t82*_t85 + 0.6e1*_t11*_t12*_t30*_t9*params->pc07_a*params->pc07_b + 0.3e1*_t11*_t12*_t35*_t36*_t62*_t67*_t9*params->pc07_b + _t11*_t12*_t62*_t63*_t64*_t9 - _t112*_t113 - _t114*_t115 - _t118*_t25 - 0.3e1*_t15*_t44*_t87 - _t21*_t66 - _t21*_t69 - 0.6e1*_t37*_t39*_t70 - 0.6e1*_t46*_t86 - _t59*_t61 - 0.2e1*_t71*_t75 - 0.3e1*_t71*_t80 - _t79 - _t81*_t84 - _t88*_t91 - 0.3e1*_t92*_t97;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t101*_t179 - _t101*_t180*_t20*_t52/(_t8 * _t8 * _t8 * _t8) - _t101*_t181 + _t101*_t200*_t210 - _t103*_t147*params->pc07_a + 0.4e1*_t104*_t69 + 0.6e1*_t105*_t107 + _t106*(_t58 * _t58) - _t107*_t19*_t198 - _t108*_t114*_t51 - _t108*_t212*_t22 - _t111*_t196 - 0.3e1*_t112*_t118 + _t113*_t200 + _t114*_t182 - 0.2e1*_t114*_t212*_t23 - _t115*_t117 + 0.2e1*_t118*_t206 + _t119*_t200 + _t119*_t202 + _t119*_t205 + 0.2e1*_t119*_t213 - _t119*_t214 - _t120*_t27 + _t121*_t159*_t165 - _t121*_t16*_t161*_t164 + _t122*_t124 - _t123*_t168*_t28*_t42*_t93*_t95 + _t123*_t175 + 0.4e1*_t123*_t84*_t96 + _t124*_t140 + _t124*_t187*_t91 + _t125*_t60 - _t126*_t77 + _t127*_t15*_t45*_t68 - _t127*_t152*_t62 + _t127*_t156*_t77 - _t128*_t21 - 0.18e2*_t129*_t142 + _t129*_t143*_t74 + 0.12e2*_t129*_t75 + _t130*_t21 - _t132*_t39 + _t132*_t60 + _t133*_t21 - 0.24e2*_t135*_t75 + _t136*_t137 - _t136*_t141 + _t137*_t142 - _t137*_t80 - _t138*_t74*_t77 - _t139*_t21 - _t140*_t143 - 0.6e1*_t140*_t20 + 0.11e2*_t140*_t44 + _t141*_t80 - 0.8e1*_t142*_t158 + _t144*_t146*(_t23 * _t23 * _t23 * _t23) + _t144*_t178*_t180*_t188 + _t145*(_t22 * _t22 * _t22 * _t22) - _t146*_t170*_t84 + _t146*_t171*_t98 - _t147*_t16*_t46 - 0.4e1*_t148*_t157*_t7 - 0.24e2*_t148*_t57 + _t15*_t162*_t74 - 0.12e2*_t15*_t165*_t177 - _t150*_t151 + _t150*_t87 - _t151*_t154*_t191 + 0.12e2*_t152*_t157 + _t153*_t16*_t89 + _t153*_t176 - _t154*_t31*_t90 + _t155*_t191 - _t155*_t26 - _t156*_t162 - _t158*_t166 - _t16*_t190*_t26 + _t160*_t161*_t34 - _t160*_t38 - _t164*_t177 + _t166*_t71*_t99 - _t167*_t168*_t81 + _t167*_t189 + _t167*_t195 - _t168*_t172*_t31*params->pc07_a + _t169*_t170*_t85 - _t170*_t207 - _t170*_t208 + _t172*_t174 - _t173*_t188 - _t173*_t85 - _t175*_t63 - _t176*_t185*_t76 + 0.2e1*_t178*_t196*_t41*_t82 + _t179*_t180 - _t180*_t181 + _t182*_t183 + _t182*_t196 + _t182*(-_t102 + 0.6e1*_t26*_t3*params->pc07_a + 0.6e1*_t31*_t7*params->pc07_a - 0.3e1*_t56) - _t183*_t200 - _t184*_t43*_t70 + _t184*_t65 + _t185*_t60*_t99 - 0.12e2*_t186*_t37 + 0.8e1*_t186*_t74 + _t187*_t37*_t78 - _t187*_t79 + _t189*_t197 + _t190*_t86 - _t192*_t193 - _t192*_t194 - _t193*_t199 + _t193*_t201 - _t194*_t198*_t45 - _t194*_t199 + _t194*_t201 + _t194*_t38*_t61 + _t195*_t197 + _t203*_t209 - _t203*_t48 + _t205*_t58 + _t206*(-0.12e2*_t116 + 0.12e2*_t28*_t7*_t70 + 0.12e2*_t3*_t30*params->pc07_a + 0.2e1*_t3*_t62*_t64 - 0.12e2*_t65 - 0.2e1*_t69) + _t207*_t210 + _t208*_t210 + _t213*_t58 - _t214*_t58 - _t25*(-_t120*_t53 + _t122*_t3 + _t125*_t55 - _t126*_t3*_t62 - _t128 + _t130 + _t133 - _t139) + 0.24e2*_t26*_t31*_t46;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_fab_k, _KMAX)(const xc_func_type *p, double z, double *out) {
  const mgga_k_pc07_params *params = (const mgga_k_pc07_params *)(p->params);

  const double _t1 = (0.39e2 / 0.40e2)*params->pc07_a;
  const double _t2 = (0.1e1 / 0.40e2)*params->pc07_a;
  const double _t3 = _t2 > z;
  const double _t4 = my_piecewise3(_t3, _t2, z);
  const double _t5 = _t1 > _t4;
  const double _t6 = z <= _t2;
  const double _t7 = z >= _t1;
#if _KMAX >= 1
  const double _t8 = my_piecewise3(_t5, my_piecewise3(_t3, 0, 0.1e1), 0);
#endif
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1] = {0.};
  if(!(_t6) && !(_t7)) XC_CAT(pc07_fab0_k, _KMAX)(p, my_piecewise3(_t5, _t4, _t1), _hc0);

  const double f = my_piecewise5(_t6, 0, _t7, 0.1e1, _hc0[0]);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise5(_t6, 0, _t7, 0, _hc0[1]*_t8);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = my_piecewise5(_t6, 0, _t7, 0, _hc0[2]*(_t8 * _t8));
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = my_piecewise5(_t6, 0, _t7, 0, _hc0[3]*(_t8 * _t8 * _t8));
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = my_piecewise5(_t6, 0, _t7, 0, _hc0[4]*(_t8 * _t8 * _t8 * _t8));
  out[4] = d4f_dz4;
#endif
}

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_f_W_pf_k, _KMAX)(const xc_func_type *p, double x2, double *out) {

  const double _t1 = (0.5e1 / 0.72e2)*xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);

  const double f = _t1*x2;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx2 = _t1;
  out[1] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_dx22 = 0;
  out[2] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_dx23 = 0;
  out[3] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_dx24 = 0;
  out[4] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_Delta_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double *out) {

  const double _t1 = xc_powr(0.6e1, 2, 3);
  const double _t2 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.5184e4)*_t3;
  const double _t5 = _t4*x2;
#if _KMAX >= 1
  const double _t6 = (0.1e1 / 0.2916e4)*_t3;
#endif

  const double f = (0.1e1 / 0.5832e4)*_t3*(u * u) + (0.1e1 / 0.17496e5)*_t3*(x2 * x2) - _t5*u;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = -_t5 + _t6*u;
  out[1] = df_du;
  const double df_dx2 = (0.1e1 / 0.8748e4)*_t1*_t2*x2 - _t4*u;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _t6;
  out[3] = d2f_du2;
  const double d2f_dx2_du = -_t4;
  out[4] = d2f_dx2_du;
  const double d2f_dx22 = (0.1e1 / 0.8748e4)*_t3;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_du3 = 0;
  out[6] = d3f_du3;
  const double d3f_dx2_du2 = 0;
  out[7] = d3f_dx2_du2;
  const double d3f_dx22_du = 0;
  out[8] = d3f_dx22_du;
  const double d3f_dx23 = 0;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_du4 = 0;
  out[10] = d4f_du4;
  const double d4f_dx2_du3 = 0;
  out[11] = d4f_dx2_du3;
  const double d4f_dx22_du2 = 0;
  out[12] = d4f_dx22_du2;
  const double d4f_dx23_du = 0;
  out[13] = d4f_dx23_du;
  const double d4f_dx24 = 0;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_S_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pc07_f_W_pf_k, _KMAX)(p, x2, _hc0);
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_Delta_pf_k, _KMAX)(p, x2, u, _hc1);
  const double _t1 = ((_hc1[0]) * (_hc1[0]));
  const double _t2 = _hc0[0] + 0.1e1;
  const double _t3 = (0.1e1 / (_t2 * _t2));
  const double _t4 = _t1*_t3 + 0.1e1;
  const double _t5 = xc_powr(_t4, 1, 2);
#if _KMAX >= 1
  const double _t6 = (0.1e1 / _t5);
  const double _t7 = _hc1[0]*_t3;
  const double _t8 = _t6*_t7;
  const double _t9 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t10 = _hc0[1]*_t9;
  const double _t11 = _t1*_t10;
  const double _t12 = -_hc1[0]*_hc1[2]*_t3 + _t11;
  const double _t13 = -_t12;
#endif
#if _KMAX >= 2
  const double _t14 = ((_hc1[1]) * (_hc1[1]));
  const double _t15 = _t14*_t3;
  const double _t16 = xc_powr(_t4, -3, 2);
  const double _t17 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t18 = _t1*_t17;
  const double _t19 = _t16*_t18;
  const double _t20 = _t13*_t16;
  const double _t21 = _t20*_t7;
  const double _t22 = _hc1[4]*_t7;
  const double _t23 = _hc1[2]*_t3;
  const double _t24 = _hc1[1]*_t23;
  const double _t25 = 0.2e1*_t10;
  const double _t26 = _hc1[0]*_t25;
  const double _t27 = -_hc1[1]*_t26 + _t22 + _t24;
  const double _t28 = _t12*_t16;
  const double _t29 = _hc1[5]*_t7;
  const double _t30 = ((_hc1[2]) * (_hc1[2]));
  const double _t31 = _t3*_t30;
  const double _t32 = _hc1[0]*_hc1[2];
  const double _t33 = 0.4e1*_t10;
  const double _t34 = ((_hc0[1]) * (_hc0[1]));
  const double _t35 = _t18*_t34;
  const double _t36 = _t29 + _t31 - _t32*_t33 + 0.3e1*_t35;
#endif
#if _KMAX >= 3
  const double _t37 = 0.3e1*_t3;
  const double _t38 = _hc1[1]*_hc1[3];
  const double _t39 = 0.3e1*_t16;
  const double _t40 = _t17*_t39;
  const double _t41 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t42 = 0.3e1*_t19;
  const double _t43 = xc_powr(_t4, -5, 2);
  const double _t44 = 0.3e1*_t43;
  const double _t45 = xc_powi(_t2, -6);
  const double _t46 = ((_hc1[0]) * (_hc1[0]) * (_hc1[0]));
  const double _t47 = _t41*_t45*_t46;
  const double _t48 = _t16*_t27;
  const double _t49 = _hc1[1]*_t7;
  const double _t50 = -0.2e1*_hc1[1]*_hc1[4]*_t3 - _hc1[2]*_hc1[3]*_t3 + _hc1[3]*_t26 + _t14*_t25;
  const double _t51 = -_t50;
  const double _t52 = _t13*_t43;
  const double _t53 = _t12*_t52;
  const double _t54 = 0.3e1*_t53;
  const double _t55 = -_t27;
  const double _t56 = _t16*_t36;
  const double _t57 = _t56*_t7;
  const double _t58 = _hc1[5]*_t3;
  const double _t59 = _hc1[2]*_t33;
  const double _t60 = _t17*_t34;
  const double _t61 = 0.6e1*_t60;
  const double _t62 = _hc1[0]*_t61;
  const double _t63 = -_hc1[0]*_hc1[4]*_t33 + _hc1[1]*_t58 - _hc1[1]*_t59 + _hc1[1]*_t62 + 0.2e1*_hc1[4]*_t23;
  const double _t64 = 0.6e1*_t10;
  const double _t65 = _hc1[5]*_t64;
  const double _t66 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]))/xc_powi(_t2, 5);
  const double _t67 = -0.18e2*_hc1[0]*_hc1[2]*_t17*_t34 + _hc1[0]*_t65 - 0.3e1*_hc1[2]*_hc1[5]*_t3 + 0.12e2*_t1*_t66 + _t30*_t64;
  const double _t68 = -_t67;
  const double _t69 = _hc1[2]*_t7;
  const double _t70 = 0.3e1*_t11 - 0.3e1*_t69;
  const double _t71 = 0.2e1*_t28;
  const double _t72 = -_t36;
#endif
#if _KMAX >= 4
  const double _t73 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t74 = ((_hc1[3]) * (_hc1[3]));
  const double _t75 = xc_powr(_t4, -7, 2);
  const double _t76 = 0.15e2*_t75;
  const double _t77 = 0.3e1*_t48;
  const double _t78 = _hc1[3]*_t7;
  const double _t79 = _t27*_t43;
  const double _t80 = 0.6e1*_t49;
  const double _t81 = _t12*_t80;
  const double _t82 = _t16*_t49;
  const double _t83 = _hc1[2]*_t10;
  const double _t84 = _t12*_t70;
  const double _t85 = _t13*_t75*_t84;
  const double _t86 = _t52*_t70;
  const double _t87 = 0.36e2*_t60;
#endif

  const double f = _t5;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _hc1[1]*_t8;
  out[1] = df_du;
  const double df_dx2 = _t13*_t6;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _hc1[3]*_t8 - _t14*_t19 + _t15*_t6;
  out[3] = d2f_du2;
  const double d2f_dx2_du = -_hc1[1]*_t21 + _t27*_t6;
  out[4] = d2f_dx2_du;
  const double d2f_dx22 = _t13*_t28 + _t36*_t6;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_du3 = -_hc1[0]*_t40*_t41 + _t37*_t38*_t6 - _t38*_t42 + _t44*_t47;
  out[6] = d3f_du3;
  const double d3f_dx2_du2 = -_hc1[3]*_t21 + 0.3e1*_t1*_t13*_t14*_t17*_t43 - _t15*_t20 - 0.2e1*_t48*_t49 + _t51*_t6;
  out[7] = d3f_dx2_du2;
  const double d3f_dx22_du = -_hc1[1]*_t57 + _t20*_t55 + _t27*_t28 - _t49*_t54 + _t6*_t63;
  out[8] = d3f_dx22_du;
  const double d3f_dx23 = _t20*_t72 + _t36*_t71 + _t53*_t70 + _t6*_t68;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_du4 = -((_hc1[0]) * (_hc1[0]) * (_hc1[0]) * (_hc1[0]))*_t73*_t76/xc_powi(_t2, 8) - 0.18e2*_hc1[0]*_hc1[3]*_t14*_t16*_t17 + 0.18e2*_hc1[3]*_t14*_t43*_t45*_t46 + 0.18e2*_t1*_t43*_t45*_t73 + 0.3e1*_t3*_t6*_t74 - _t40*_t73 - _t42*_t74;
  out[10] = d4f_du4;
  const double d4f_dx2_du3 = 0.9e1*_hc1[0]*_t13*_t17*_t41*_t43 + 0.9e1*_hc1[1]*_hc1[3]*_t1*_t13*_t17*_t43 - _hc1[1]*_hc1[3]*_t20*_t37 + 0.9e1*_t1*_t14*_t17*_t27*_t43 - _t13*_t47*_t76 - _t15*_t77 - _t39*_t49*_t51 + _t6*(0.3e1*_hc1[3]*_hc1[4]*_t3 - _t38*_t64) - _t77*_t78;
  out[11] = d4f_dx2_du3;
  const double d4f_dx22_du2 = -_hc1[3]*_t57 + 0.15e2*_t1*_t12*_t13*_t14*_t17*_t75 + 0.3e1*_t1*_t14*_t17*_t36*_t43 + _t12*_t16*_t51 + _t13*_t16*_t50 - _t15*_t54 - _t15*_t56 + 0.2e1*_t16*_t27*_t55 - _t52*_t55*_t80 - _t54*_t78 + _t6*(-0.8e1*_hc1[1]*_hc1[4]*_t10 + _hc1[3]*_t58 - _hc1[3]*_t59 + _hc1[3]*_t62 + 0.2e1*((_hc1[4]) * (_hc1[4]))*_t3 + _t14*_t61) - 0.2e1*_t63*_t82 - _t79*_t81;
  out[12] = d4f_dx22_du2;
  const double d4f_dx23_du = -_t20*_t63 - _t36*_t43*_t81 + _t48*_t72 - 0.3e1*_t49*_t52*_t72 - 0.5e1*_t49*_t85 + _t53*(0.6e1*_hc0[1]*_hc1[0]*_hc1[1]*_t9 - 0.3e1*_t22 - 0.3e1*_t24) + 0.2e1*_t55*_t56 + _t55*_t86 + _t6*(-0.24e2*_hc1[0]*_hc1[1]*_t66 + 0.18e2*_hc1[0]*_hc1[4]*_t17*_t34 + 0.18e2*_hc1[1]*_hc1[2]*_t17*_t34 - _hc1[1]*_t65 + 0.3e1*_hc1[4]*_hc1[5]*_t3 - 0.12e2*_hc1[4]*_t83) + _t63*_t71 - _t68*_t82 + _t79*_t84;
  out[13] = d4f_dx23_du;
  const double d4f_dx24 = _t20*_t67 + 0.3e1*_t28*_t68 + _t36*_t39*_t72 + _t36*_t44*_t84 + _t53*(0.12e2*_hc0[1]*_hc1[0]*_hc1[2]*_t9 - 0.3e1*_t29 - 0.3e1*_t31 - 0.9e1*_t35) + _t6*(0.60e2*((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t1*_t45 + _hc1[0]*_hc1[5]*_t87 + ((_hc1[5]) * (_hc1[5]))*_t37 - 0.24e2*_hc1[5]*_t83 + _t30*_t87 - 0.96e2*_t32*_t66) + 0.2e1*_t72*_t86 + _t85*(0.5e1*_t11 - 0.5e1*_t69);
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_GE4_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_Delta_pf_k, _KMAX)(p, x2, u, _hc0);
  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = (0.5e1 / 0.54e2)*_t1;
  const double _t3 = (0.5e1 / 0.648e3)*_t1;

  const double f = _hc0[0] + _t2*u + _t3*x2 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _hc0[1] + _t2;
  out[1] = df_du;
  const double df_dx2 = _hc0[2] + _t3;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _hc0[3];
  out[3] = d2f_du2;
  const double d2f_dx2_du = _hc0[4];
  out[4] = d2f_dx2_du;
  const double d2f_dx22 = _hc0[5];
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_du3 = 0;
  out[6] = d3f_du3;
  const double d3f_dx2_du2 = 0;
  out[7] = d3f_dx2_du2;
  const double d3f_dx22_du = 0;
  out[8] = d3f_dx22_du;
  const double d3f_dx23 = 0;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_du4 = 0;
  out[10] = d4f_du4;
  const double d4f_dx2_du3 = 0;
  out[11] = d4f_dx2_du3;
  const double d4f_dx22_du2 = 0;
  out[12] = d4f_dx22_du2;
  const double d4f_dx23_du = 0;
  out[13] = d4f_dx23_du;
  const double d4f_dx24 = 0;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_B_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double *out) {

  const double _t1 = xc_powr(0.6e1, 1, 3)/(M_PI * M_CBRTPI);
  const double _t2 = (0.5e1 / 0.54e2)*_t1;
  const double _t3 = (0.5e1 / 0.81e2)*_t1;

  const double f = _t2*u - _t3*x2 + 0.1e1;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _t2;
  out[1] = df_du;
  const double df_dx2 = -_t3;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_du2 = 0;
  out[3] = d2f_du2;
  const double d2f_dx2_du = 0;
  out[4] = d2f_dx2_du;
  const double d2f_dx22 = 0;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_du3 = 0;
  out[6] = d3f_du3;
  const double d3f_dx2_du2 = 0;
  out[7] = d3f_dx2_du2;
  const double d3f_dx22_du = 0;
  out[8] = d3f_dx22_du;
  const double d3f_dx23 = 0;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_du4 = 0;
  out[10] = d4f_du4;
  const double d4f_dx2_du3 = 0;
  out[11] = d4f_dx2_du3;
  const double d4f_dx22_du2 = 0;
  out[12] = d4f_dx22_du2;
  const double d4f_dx23_du = 0;
  out[13] = d4f_dx23_du;
  const double d4f_dx24 = 0;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_z_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_S_pf_k, _KMAX)(p, x2, u, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pc07_f_W_pf_k, _KMAX)(p, x2, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_GE4_pf_k, _KMAX)(p, x2, u, _hc2);
  double _hc3[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_B_pf_k, _KMAX)(p, x2, u, _hc3);
  double _hc4[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_Delta_pf_k, _KMAX)(p, x2, u, _hc4);
  const double _t1 = 0.2e1*_hc3[0];
  const double _t2 = _hc3[0] + _hc4[0];
  const double _t3 = 0.2e1*_hc1[0];
  const double _t4 = _t3 + 0.1e1;
  const double _t5 = ((_hc4[0]) * (_hc4[0]));
  const double _t6 = _hc1[0] + 0.1e1;
  const double _t7 = (0.1e1 / (_t6 * _t6));
  const double _t8 = _t5*_t7;
  const double _t9 = ((_hc3[0]) * (_hc3[0])) + _hc4[0]*_t1 + _t2*_t3 + _t4*_t8;
  const double _t10 = (0.1e1 / (_hc0[0]));
  const double _t11 = _hc0[0]*_hc1[0] + _hc2[0];
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = _t10*_t12;
#if _KMAX >= 1
  const double _t14 = (0.1e1 / ((_hc0[0]) * (_hc0[0])));
  const double _t15 = _t12*_t14;
  const double _t16 = _hc0[1]*_t9;
  const double _t17 = 0.2e1*_hc4[0];
  const double _t18 = _hc3[1] + _hc4[1];
  const double _t19 = _t4*_t7;
  const double _t20 = _t17*_t19;
  const double _t21 = _hc3[1]*_t1 + _hc3[1]*_t17 + _hc4[1]*_t1 + _hc4[1]*_t20 + _t18*_t3;
  const double _t22 = (0.1e1 / (_t11 * _t11));
  const double _t23 = _t10*_t22;
  const double _t24 = _hc0[1]*_hc1[0];
  const double _t25 = -_hc2[1] - _t24;
  const double _t26 = _t25*_t9;
  const double _t27 = _t15*_t9;
  const double _t28 = _hc0[0]*_hc1[1];
  const double _t29 = _hc0[2]*_hc1[0];
  const double _t30 = -_hc2[2] - _t28 - _t29;
  const double _t31 = _t23*_t9;
  const double _t32 = _hc3[2] + _hc4[2];
  const double _t33 = 0.2e1*_hc1[1];
  const double _t34 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t35 = _t34*_t4;
  const double _t36 = _hc3[2]*_t1 + _hc3[2]*_t17 + _hc4[2]*_t1 + _hc4[2]*_t20 + _t2*_t33 + _t3*_t32 - _t33*_t35*_t5 + _t33*_t8;
#endif
#if _KMAX >= 2
  const double _t37 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t38 = ((_hc0[1]) * (_hc0[1]));
  const double _t39 = _t37*_t38;
  const double _t40 = _t12*_t9;
  const double _t41 = 0.2e1*_t40;
  const double _t42 = _hc0[1]*_t15;
  const double _t43 = 0.2e1*_t21;
  const double _t44 = _hc0[3]*_hc1[0];
  const double _t45 = -_hc2[3] - _t44;
  const double _t46 = _t14*_t22;
  const double _t47 = _t26*_t46;
  const double _t48 = 0.2e1*_hc0[1];
  const double _t49 = _t23*_t25;
  const double _t50 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t51 = _t10*_t50;
  const double _t52 = -_hc0[1]*_t3 - 0.2e1*_hc2[1];
  const double _t53 = _t26*_t52;
  const double _t54 = 0.4e1*_hc3[1];
  const double _t55 = ((_hc4[1]) * (_hc4[1]));
  const double _t56 = _t55*_t7;
  const double _t57 = 0.2e1*_t4;
  const double _t58 = 0.2e1*((_hc3[1]) * (_hc3[1])) + _hc4[1]*_t54 + _hc4[3]*_t1 + _hc4[3]*_t20 + _hc4[3]*_t3 + _t56*_t57;
  const double _t59 = _hc0[2]*_t37;
  const double _t60 = _t12*_t16;
  const double _t61 = 0.2e1*_t60;
  const double _t62 = _hc0[2]*_t15;
  const double _t63 = _hc0[2]*_t46;
  const double _t64 = _hc0[1]*_hc1[1];
  const double _t65 = _hc0[4]*_hc1[0];
  const double _t66 = -_hc2[4] - _t64 - _t65;
  const double _t67 = _t16*_t30;
  const double _t68 = _t23*_t30;
  const double _t69 = _t51*_t52;
  const double _t70 = _t30*_t9;
  const double _t71 = _t15*_t36;
  const double _t72 = _t23*_t36;
  const double _t73 = 0.2e1*_hc3[1];
  const double _t74 = 0.2e1*_hc3[2];
  const double _t75 = _hc4[1]*_t7;
  const double _t76 = 0.4e1*_hc1[1];
  const double _t77 = _hc4[0]*_t76;
  const double _t78 = _hc4[2]*_t57;
  const double _t79 = _t35*_t77;
  const double _t80 = _hc3[2]*_t73 + _hc4[1]*_t74 - _hc4[1]*_t79 + _hc4[2]*_t73 + _hc4[4]*_t1 + _hc4[4]*_t20 + _hc4[4]*_t3 + _t18*_t33 + _t75*_t77 + _t75*_t78;
  const double _t81 = ((_hc0[2]) * (_hc0[2]));
  const double _t82 = _t37*_t81;
  const double _t83 = _hc0[5]*_hc1[0];
  const double _t84 = -_hc0[2]*_t33 - _hc2[5] - _t83;
  const double _t85 = 0.2e1*_t70;
  const double _t86 = -_hc0[2]*_t3 - 0.2e1*_hc2[2] - 0.2e1*_t28;
  const double _t87 = _t51*_t70;
  const double _t88 = 0.2e1*_t71;
  const double _t89 = 0.2e1*_t72;
  const double _t90 = 0.4e1*_hc3[2];
  const double _t91 = _hc4[0]*_hc4[2];
  const double _t92 = 0.8e1*_hc1[1];
  const double _t93 = _t7*_t92;
  const double _t94 = ((_hc1[1]) * (_hc1[1]));
  const double _t95 = _t34*_t94;
  const double _t96 = ((_hc4[2]) * (_hc4[2]));
  const double _t97 = _t7*_t96;
  const double _t98 = _t35*_t92;
  const double _t99 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t100 = _t5*_t99;
  const double _t101 = _t4*_t94;
  const double _t102 = 0.2e1*((_hc3[2]) * (_hc3[2])) + _hc4[2]*_t90 + _hc4[5]*_t1 + _hc4[5]*_t20 + _hc4[5]*_t3 + 0.6e1*_t100*_t101 + _t32*_t76 - 0.8e1*_t5*_t95 + _t57*_t97 + _t91*_t93 - _t91*_t98;
#endif
#if _KMAX >= 3
  const double _t103 = 0.6e1*_hc4[3];
  const double _t104 = _t103*_t19;
  const double _t105 = _hc3[1]*_t103 + _hc4[1]*_t104;
  const double _t106 = _t37*_t60;
  const double _t107 = 0.6e1*_hc0[3];
  const double _t108 = (0.1e1 / ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0])));
  const double _t109 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t110 = _t108*_t109;
  const double _t111 = 0.6e1*_t40;
  const double _t112 = _t15*_t21;
  const double _t113 = 0.3e1*_hc0[3];
  const double _t114 = -_hc0[6]*_hc1[0] - _hc2[6];
  const double _t115 = _t12*_t39;
  const double _t116 = 0.6e1*_t21;
  const double _t117 = 0.3e1*_t45;
  const double _t118 = _t16*_t46;
  const double _t119 = _t22*_t39;
  const double _t120 = 0.6e1*_t119;
  const double _t121 = _t21*_t23;
  const double _t122 = _hc0[1]*_t46;
  const double _t123 = _t122*_t25;
  const double _t124 = -_hc0[3]*_t3 - 0.2e1*_hc2[3];
  const double _t125 = _t26*_t51;
  const double _t126 = _t45*_t9;
  const double _t127 = 0.2e1*_t69;
  const double _t128 = _t14*_t50;
  const double _t129 = _t128*_t53;
  const double _t130 = 0.3e1*_t58;
  const double _t131 = _t25*_t69;
  const double _t132 = 0.3e1*_t21;
  const double _t133 = -0.3e1*_hc2[1] - 0.3e1*_t24;
  const double _t134 = (0.1e1 / (_t11 * _t11 * _t11 * _t11));
  const double _t135 = _t10*_t134;
  const double _t136 = _t133*_t135;
  const double _t137 = 0.4e1*_hc0[4];
  const double _t138 = _t41*_t59;
  const double _t139 = _t108*_t38;
  const double _t140 = _hc0[2]*_t139;
  const double _t141 = 0.2e1*_t112;
  const double _t142 = 0.4e1*_t37;
  const double _t143 = _hc0[2]*_t142;
  const double _t144 = _hc0[1]*_t12;
  const double _t145 = _t144*_t21;
  const double _t146 = _t63*_t9;
  const double _t147 = 0.2e1*_hc0[4];
  const double _t148 = _t143*_t22;
  const double _t149 = _hc0[1]*_t26;
  const double _t150 = _hc0[3]*_hc1[1];
  const double _t151 = -_hc0[7]*_hc1[0] - _hc2[7] - _t150;
  const double _t152 = 0.2e1*_t66;
  const double _t153 = _t46*_t70;
  const double _t154 = _t25*_t63;
  const double _t155 = 0.2e1*_t121;
  const double _t156 = _hc0[2]*_t128;
  const double _t157 = _t30*_t43;
  const double _t158 = _t69*_t9;
  const double _t159 = _t128*_t67;
  const double _t160 = 0.2e1*_t52;
  const double _t161 = _t136*_t70;
  const double _t162 = 0.2e1*_t115;
  const double _t163 = _t25*_t36;
  const double _t164 = _t46*_t48;
  const double _t165 = 0.2e1*_t80;
  const double _t166 = _hc4[3]*_t7;
  const double _t167 = 0.4e1*_t19;
  const double _t168 = _hc4[4]*_t167;
  const double _t169 = _hc4[1]*_t168 + _hc4[3]*_t33 + _hc4[3]*_t74 - _hc4[3]*_t79 + _hc4[4]*_t54 + _t166*_t77 + _t166*_t78 - _t35*_t55*_t76 + _t56*_t76;
  const double _t170 = _hc0[5]*_t37;
  const double _t171 = _t40*_t59;
  const double _t172 = _t108*_t81;
  const double _t173 = _hc0[5]*_t15;
  const double _t174 = _t12*_t82;
  const double _t175 = _hc0[5]*_t46;
  const double _t176 = -_hc0[4]*_t33 - _hc0[8]*_hc1[0] - _hc2[8];
  const double _t177 = _t22*_t82;
  const double _t178 = 0.2e1*_t26;
  const double _t179 = _t23*_t84;
  const double _t180 = _t84*_t9;
  const double _t181 = _t156*_t52;
  const double _t182 = _t51*_t86;
  const double _t183 = _t182*_t9;
  const double _t184 = -_hc0[4]*_t3 - 0.2e1*_hc2[4] - 0.2e1*_t64;
  const double _t185 = _t128*_t86;
  const double _t186 = _t21*_t30;
  const double _t187 = _t143*_t36;
  const double _t188 = 0.2e1*_t63;
  const double _t189 = _t30*_t36;
  const double _t190 = _t102*_t15;
  const double _t191 = _t102*_t23;
  const double _t192 = _hc4[0]*_hc4[4];
  const double _t193 = _hc4[2]*_t92;
  const double _t194 = 0.16e2*_t95;
  const double _t195 = _hc4[0]*_t194;
  const double _t196 = _hc4[5]*_t57;
  const double _t197 = _hc4[1]*_t35;
  const double _t198 = _t101*_t99;
  const double _t199 = 0.12e2*_t198;
  const double _t200 = _hc4[0]*_hc4[1];
  const double _t201 = -_hc4[1]*_t195 + _hc4[2]*_t168 + _hc4[4]*_t76 + _hc4[4]*_t90 + _hc4[5]*_t73 + _t192*_t93 - _t192*_t98 - _t193*_t197 + _t193*_t75 + _t196*_t75 + _t199*_t200;
  const double _t202 = _t111*_t37;
  const double _t203 = _hc0[2]*_t202;
  const double _t204 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t205 = _t108*_t204;
  const double _t206 = 0.3e1*_hc1[1];
  const double _t207 = -_hc0[5]*_t206 - _hc0[9]*_hc1[0] - _hc2[9];
  const double _t208 = 0.3e1*_t84;
  const double _t209 = 0.3e1*_t153;
  const double _t210 = 0.6e1*_t70;
  const double _t211 = -_hc0[2]*_t76 - _hc0[5]*_t3 - 0.2e1*_hc2[5];
  const double _t212 = 0.2e1*_t180;
  const double _t213 = _t70*_t86;
  const double _t214 = 0.3e1*_t156;
  const double _t215 = _t135*_t70;
  const double _t216 = -0.3e1*_hc2[2] - 0.3e1*_t28 - 0.3e1*_t29;
  const double _t217 = _t216*_t86;
  const double _t218 = 0.3e1*_t71;
  const double _t219 = 0.6e1*_t36;
  const double _t220 = 0.3e1*_t72;
  const double _t221 = _t30*_t63;
  const double _t222 = _t182*_t30;
  const double _t223 = 0.3e1*_t102;
  const double _t224 = 0.6e1*_hc4[5];
  const double _t225 = 0.12e2*_hc1[1];
  const double _t226 = _hc4[5]*_t225;
  const double _t227 = 0.48e2*_t95;
  const double _t228 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t229 = _t19*_t224;
  const double _t230 = _t225*_t35;
  const double _t231 = _hc4[0]*_hc4[5];
  const double _t232 = 0.36e2*_t198;
  const double _t233 = xc_powi(_t6, -5);
  const double _t234 = _t233*_t5;
  const double _t235 = _t228*_t4;
  const double _t236 = _hc1[1]*_t224 + _hc3[2]*_t224 + _hc4[0]*_t226*_t7 + _hc4[2]*_t229 + 0.36e2*_t100*_t228 + _t225*_t97 - _t227*_t91 - _t230*_t231 - _t230*_t96 + _t232*_t91 - 0.24e2*_t234*_t235;
#endif
#if _KMAX >= 4
  const double _t237 = 0.6e1*_t19;
  const double _t238 = 0.4e1*_t105;
  const double _t239 = 0.24e2/xc_powi((_hc0[0]), 5);
  const double _t240 = _t239*_t40;
  const double _t241 = _t139*_t40;
  const double _t242 = 0.4e1*_hc0[6];
  const double _t243 = 0.24e2*_t21;
  const double _t244 = _t144*_t37;
  const double _t245 = _hc0[3]*_t244;
  const double _t246 = _t110*_t12;
  const double _t247 = 0.4e1*_t114;
  const double _t248 = _hc0[3]*_t46;
  const double _t249 = 0.24e2*_t26;
  const double _t250 = _t22*_t37;
  const double _t251 = _t110*_t22;
  const double _t252 = 0.12e2*_t21;
  const double _t253 = _t25*_t252;
  const double _t254 = -_hc0[6]*_t3 - 0.2e1*_hc2[6];
  const double _t255 = _t124*_t51;
  const double _t256 = _t117*_t9;
  const double _t257 = _t128*_t52;
  const double _t258 = _t16*_t257;
  const double _t259 = _t124*_t26;
  const double _t260 = 0.4e1*_hc0[1];
  const double _t261 = _t39*_t50;
  const double _t262 = 0.6e1*_t58;
  const double _t263 = 0.8e1*_t21;
  const double _t264 = 0.4e1*_t21*_t25;
  const double _t265 = 0.12e2*_t58;
  const double _t266 = _hc0[1]*_t253;
  const double _t267 = -0.3e1*_hc2[3] - 0.3e1*_t44;
  const double _t268 = _t136*_t52;
  const double _t269 = _t124*_t136;
  const double _t270 = _t133*_t53;
  const double _t271 = _t134*_t14;
  const double _t272 = _t270*_t271;
  const double _t273 = _t10/xc_powi(_t11, 5);
  const double _t274 = _t273*(-0.4e1*_hc2[1] - 0.4e1*_t24);
  const double _t275 = _hc0[4]*_t202;
  const double _t276 = _hc0[2]*_t108*_t60;
  const double _t277 = 0.18e2*_t276;
  const double _t278 = 0.18e2*_hc0[4];
  const double _t279 = 0.3e1*_hc0[7];
  const double _t280 = 0.12e2*_t145;
  const double _t281 = _hc0[4]*_t37;
  const double _t282 = _hc0[3]*_t12;
  const double _t283 = _t116*_t59;
  const double _t284 = _t12*_t140;
  const double _t285 = _hc0[4]*_t46;
  const double _t286 = _t22*_t59;
  const double _t287 = _t16*_t286;
  const double _t288 = 0.12e2*_t22;
  const double _t289 = _t149*_t288;
  const double _t290 = _t22*_t26;
  const double _t291 = _t290*_t59;
  const double _t292 = _hc4[1]*_t230;
  const double _t293 = 0.3e1*_t151;
  const double _t294 = _t66*_t9;
  const double _t295 = _t113*_t46;
  const double _t296 = _t21*_t63;
  const double _t297 = _t250*_t67;
  const double _t298 = 0.2e1*_t126;
  const double _t299 = 0.3e1*_hc0[4];
  const double _t300 = _t116*_t66;
  const double _t301 = _t50*_t59;
  const double _t302 = 0.6e1*_t301;
  const double _t303 = _t116*_t30;
  const double _t304 = 0.3e1*_t66;
  const double _t305 = _t304*_t9;
  const double _t306 = _t144*_t59;
  const double _t307 = _t257*_t70;
  const double _t308 = _t210*_t52;
  const double _t309 = 0.3e1*_t186;
  const double _t310 = _hc0[1]*_t257;
  const double _t311 = _t215*_t267;
  const double _t312 = _t271*_t67;
  const double _t313 = _t133*_t312;
  const double _t314 = _t130*_t30;
  const double _t315 = _t133*_t274;
  const double _t316 = _t122*_t36;
  const double _t317 = _t15*_t80;
  const double _t318 = _t36*_t45;
  const double _t319 = 0.6e1*_t80;
  const double _t320 = 0.3e1*_t163;
  const double _t321 = _t23*_t80;
  const double _t322 = 0.3e1*_t169;
  const double _t323 = 0.3e1*_t80;
  const double _t324 = _t142*_t40;
  const double _t325 = _hc0[5]*_t142;
  const double _t326 = _t12*_t59;
  const double _t327 = _hc0[4]*_t326;
  const double _t328 = 0.2e1*_t176;
  const double _t329 = _t137*_t46;
  const double _t330 = _t22*_t67;
  const double _t331 = _hc0[3]*_t70;
  const double _t332 = _t43*_t84;
  const double _t333 = 0.4e1*_t66;
  const double _t334 = _hc0[1]*_t286;
  const double _t335 = 0.8e1*_t334;
  const double _t336 = _t50*_t82;
  const double _t337 = _t16*_t84;
  const double _t338 = 0.2e1*_t58;
  const double _t339 = _t184*_t51;
  const double _t340 = 0.2e1*_t294;
  const double _t341 = _hc0[2]*_t271;
  const double _t342 = _t133*_t341;
  const double _t343 = _hc0[1]*_t185;
  const double _t344 = _t136*_t86;
  const double _t345 = 0.8e1*_t36;
  const double _t346 = 0.12e2*_t36;
  const double _t347 = 0.2e1*_t189;
  const double _t348 = 0.4e1*_t189;
  const double _t349 = _t36*_t69;
  const double _t350 = 0.4e1*_t80;
  const double _t351 = _t122*_t30;
  const double _t352 = 0.2e1*_t169;
  const double _t353 = _t30*_t69;
  const double _t354 = 0.2e1*_t201;
  const double _t355 = _hc1[1]*_hc4[4];
  const double _t356 = 0.16e2*_t355;
  const double _t357 = _t172*_t40;
  const double _t358 = _t12*_t205;
  const double _t359 = 0.6e1*_hc0[5];
  const double _t360 = _t205*_t22;
  const double _t361 = 0.6e1*_t84;
  const double _t362 = 0.6e1*_t177;
  const double _t363 = 0.18e2*_t172;
  const double _t364 = _t63*_t84;
  const double _t365 = 0.3e1*_t180;
  const double _t366 = _t211*_t51;
  const double _t367 = _t156*_t86;
  const double _t368 = _t185*_t70;
  const double _t369 = _t135*_t217;
  const double _t370 = _t215*_t86;
  const double _t371 = _t217*_t70;
  const double _t372 = _t219*_t30;
  const double _t373 = 0.12e2*_t189;
  const double _t374 = 0.3e1*_t189;
  const double _t375 = 0.6e1*_t102;
  const double _t376 = 0.3e1*_t201;
  const double _t377 = _hc4[2]*_t7;
  const double _t378 = 0.24e2*_t355;
  const double _t379 = _hc4[1]*_hc4[2];
  const double _t380 = _t228*_t99;
  const double _t381 = _hc4[2]*_t35;
  const double _t382 = _t233*_t235;
  const double _t383 = 0.4e1*_t207;
  const double _t384 = 0.4e1*_hc0[9];
  const double _t385 = 0.24e2*_t70;
  const double _t386 = 0.6e1*_hc1[1];
  const double _t387 = 0.24e2*_t36;
  const double _t388 = 0.12e2*_t102;
  const double _t389 = 0.4e1*_t236;
  const double _t390 = 0.48e2*_hc1[1]*_hc4[5];
  const double _t391 = 0.96e2*_t95;
  const double _t392 = ((_hc1[1]) * (_hc1[1]) * (_hc1[1]) * (_hc1[1]));
  const double _t393 = 0.72e2*_t198;
#endif

  const double f = _t13*_t9;
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _t13*_t21 - _t15*_t16 + _t23*_t26;
  out[1] = df_du;
  const double df_dx2 = -_hc0[2]*_t27 + _t13*_t36 + _t30*_t31;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_du2 = -_hc0[3]*_t27 + _t13*_t58 + _t31*_t45 + _t39*_t41 - _t42*_t43 + _t43*_t49 - _t47*_t48 + _t51*_t53;
  out[3] = d2f_du2;
  const double d2f_dx2_du = -_hc0[1]*_t71 - _hc0[4]*_t27 + _t13*_t80 - _t21*_t62 + _t21*_t68 + _t25*_t72 - _t26*_t63 + _t31*_t66 - _t46*_t67 + _t59*_t61 + _t69*_t70;
  out[4] = d2f_dx2_du;
  const double d2f_dx22 = -_hc0[2]*_t88 - _hc0[5]*_t27 + _t102*_t13 + _t30*_t89 + _t31*_t84 + _t41*_t82 - _t63*_t85 + _t86*_t87;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_du3 = -0.3e1*_hc0[1]*_t129 - _hc0[6]*_t27 + _t105*_t13 + _t106*_t107 - _t110*_t111 - _t112*_t113 - _t113*_t47 + _t114*_t31 + _t115*_t116 - _t116*_t123 - _t117*_t118 + _t117*_t121 + _t120*_t26 + _t124*_t125 + _t126*_t127 - _t130*_t42 + _t130*_t49 + _t131*_t132 + _t136*_t53;
  out[6] = d3f_du3;
  const double d3f_dx2_du2 = _hc0[3]*_t138 - _hc0[3]*_t153 - _hc0[3]*_t71 - _hc0[4]*_t141 - _hc0[7]*_t27 + _t106*_t137 - _t111*_t140 - _t118*_t152 + _t119*_t85 - _t122*_t157 + _t124*_t87 + _t13*_t169 + _t143*_t145 - _t146*_t45 - _t147*_t47 + _t148*_t149 + _t151*_t31 + _t152*_t158 - _t154*_t43 + _t155*_t66 - _t156*_t53 + _t157*_t69 - _t159*_t160 + _t161*_t52 + _t162*_t36 - _t163*_t164 + _t163*_t69 - _t165*_t42 + _t165*_t49 + _t45*_t72 - _t58*_t62 + _t58*_t68;
  out[7] = d3f_dx2_du2;
  const double d3f_dx22_du = -_hc0[1]*_t190 - _hc0[4]*_t88 - _hc0[8]*_t27 - _t118*_t84 + _t127*_t189 + _t13*_t201 + _t137*_t171 + _t144*_t187 - _t146*_t152 - _t147*_t153 + _t148*_t67 - _t157*_t63 + _t161*_t86 - _t163*_t188 - _t164*_t189 - _t165*_t62 + _t165*_t68 + _t170*_t61 - 0.6e1*_t172*_t60 - _t173*_t21 + _t174*_t43 - _t175*_t26 + _t176*_t31 + _t177*_t178 + _t179*_t21 + _t180*_t69 - _t181*_t85 + _t182*_t186 + _t183*_t66 + _t184*_t87 - _t185*_t67 + _t191*_t25 + _t66*_t89;
  out[8] = d3f_dx22_du;
  const double d3f_dx23 = _hc0[5]*_t203 - _hc0[5]*_t209 - _hc0[5]*_t218 - _hc0[9]*_t27 - _t111*_t205 + _t13*_t236 - _t146*_t208 + _t174*_t219 + _t177*_t210 + _t182*_t212 + _t207*_t31 + _t211*_t87 - _t213*_t214 + _t215*_t217 - _t219*_t221 + _t220*_t84 + 0.3e1*_t222*_t36 - _t223*_t62 + _t223*_t68;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_du4 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t240 + _hc0[1]*_hc0[3]*_t249*_t250 - _hc0[10]*_t27 + ((_hc0[3]) * (_hc0[3]))*_t202 - _hc0[3]*_t15*_t262 - 0.36e2*_hc0[3]*_t241 + 0.8e1*_hc0[6]*_t106 + ((_hc4[3]) * (_hc4[3]))*_t13*_t237 - _t107*_t129 - _t112*_t242 + 0.3e1*_t114*_t158 + _t115*_t265 - _t118*_t247 + 0.12e2*_t119*_t126 + _t119*_t243*_t25 + _t121*_t247 - _t122*_t252*_t45 - _t123*_t265 + _t125*_t254 - 0.6e1*_t126*_t248 - _t128*_t259*_t260 + _t131*_t262 + _t135*_t267*_t53 + _t178*_t269 + _t23*_t262*_t45 - _t238*_t42 + _t238*_t49 - _t242*_t47 + _t243*_t245 - _t243*_t246 - _t248*_t253 - _t249*_t251 + _t255*_t256 + _t255*_t264 + _t256*_t268 - _t257*_t266 - 0.8e1*_t258*_t45 - _t260*_t272 + 0.12e2*_t261*_t53 + _t263*_t45*_t69 + _t264*_t268 + _t270*_t274 + _t31*(-_hc0[10]*_hc1[0] - _hc2[10]);
  out[10] = d4f_du4;
  const double d4f_dx2_du3 = _hc0[1]*_t302*_t53 - _hc0[11]*_t27 + _hc0[2]*_t109*_t240 - _hc0[2]*_t272 + _hc0[3]*_t275 - _hc0[3]*_t277 - _hc0[4]*_t130*_t15 + _hc0[6]*_t138 - _hc0[6]*_t153 - _hc0[6]*_t71 + 0.6e1*_hc0[7]*_t106 - _t105*_t62 + _t105*_t68 + _t107*_t291 + _t107*_t297 - _t112*_t279 - _t113*_t307 - _t113*_t317 - _t114*_t146 + _t114*_t72 + _t115*_t319 - _t116*_t25*_t285 - _t117*_t296 - _t117*_t316 + _t117*_t321 - _t118*_t293 + _t119*_t303 + _t120*_t163 + _t120*_t294 + _t121*_t293 - _t122*_t300 - _t122*_t314 - _t123*_t319 - 0.3e1*_t124*_t159 + _t127*_t318 - _t129*_t299 + _t13*(_hc4[3]*_t225*_t75 - _hc4[3]*_t292 + _hc4[4]*_t104) - _t130*_t154 + _t130*_t23*_t66 + _t131*_t323 - _t132*_t181*_t25 - 0.18e2*_t140*_t290 - _t156*_t259 + _t158*_t293 + _t163*_t255 + _t163*_t268 - _t163*_t295 - _t181*_t298 - _t186*_t295 - 0.18e2*_t21*_t284 - _t210*_t251 + _t219*_t245 - _t219*_t246 - _t241*_t278 + _t254*_t87 + _t255*_t305 + _t255*_t309 - _t256*_t285 - 0.6e1*_t258*_t66 + _t261*_t308 + _t262*_t306 + _t266*_t286 + _t268*_t305 + _t268*_t309 + _t269*_t85 - _t279*_t47 + _t280*_t281 + _t281*_t289 + _t282*_t283 + 0.6e1*_t287*_t45 - _t294*_t295 + _t300*_t69 - _t303*_t310 + _t31*(-_hc0[11]*_hc1[0] - _hc0[6]*_hc1[1] - _hc2[11]) - _t310*_t320 + _t311*_t52 - 0.3e1*_t313*_t52 + _t314*_t69 + _t315*_t52*_t70 - _t322*_t42 + _t322*_t49;
  out[11] = d4f_dx2_du3;
  const double d4f_dx22_du2 = -_hc0[12]*_t27 + _hc0[2]*_hc0[7]*_t324 - _hc0[3]*_t111*_t172 + _hc0[3]*_t170*_t41 - _hc0[3]*_t190 + ((_hc0[4]) * (_hc0[4]))*_t324 + _hc0[4]*_t244*_t345 - 0.24e2*_hc0[4]*_t276 + 0.8e1*_hc0[4]*_t291 - _hc0[5]*_t111*_t139 - _hc0[5]*_t129 - 0.2e1*_hc0[7]*_t153 - _hc0[7]*_t88 - _hc0[8]*_t141 + _hc0[8]*_t142*_t60 - 0.2e1*_hc0[8]*_t47 + _t102*_t131 + _t102*_t162 - _t102*_t164*_t25 - _t118*_t328 + _t119*_t212 + _t119*_t348 - _t122*_t332 - _t124*_t156*_t85 - _t126*_t175 - _t128*_t160*_t337 + _t13*(_hc4[0]*_hc4[3]*_t199 + _hc4[2]*_hc4[3]*_t93 - _hc4[3]*_t193*_t35 - _hc4[3]*_t195 + ((_hc4[4]) * (_hc4[4]))*_t167 + _t166*_t196 - _t194*_t55 - _t197*_t356 + _t199*_t55 + _t356*_t75) + _t136*_t184*_t85 - _t137*_t307 - _t137*_t317 - _t140*_t288*_t70 + _t145*_t325 - 0.2e1*_t146*_t151 + _t148*_t331 + _t149*_t22*_t325 + _t151*_t183 + _t151*_t89 - _t152*_t16*_t185 - _t154*_t350 + _t155*_t176 - _t156*_t160*_t163 + _t157*_t339 - _t157*_t343 + _t157*_t344 + _t158*_t328 - 0.2e1*_t159*_t184 - _t163*_t329 + _t163*_t335 - _t172*_t280 - _t172*_t289 - _t173*_t58 + _t174*_t338 - _t175*_t25*_t43 + _t177*_t264 + _t177*_t298 + _t179*_t58 - _t180*_t248 + _t180*_t255 + _t180*_t268 - 0.4e1*_t181*_t186 - _t181*_t333*_t9 + _t182*_t43*_t66 - _t185*_t331 - _t186*_t329 + _t186*_t335 + _t187*_t282 - _t188*_t318 + _t191*_t45 + _t213*_t315 - _t221*_t338 + _t222*_t58 + _t240*_t38*_t81 - _t248*_t347 + _t255*_t347 + _t261*_t85*_t86 + _t263*_t327 + _t268*_t347 + 0.8e1*_t281*_t330 - _t284*_t346 + 0.8e1*_t287*_t66 - _t294*_t329 - _t296*_t333 + 0.8e1*_t301*_t52*_t67 + 0.8e1*_t306*_t80 + _t31*(-_hc0[12]*_hc1[0] - _hc0[7]*_t33 - _hc2[12]) - _t310*_t348 + _t311*_t86 - 0.2e1*_t313*_t86 - _t316*_t333 + _t321*_t333 + _t332*_t69 + _t333*_t349 + 0.2e1*_t336*_t53 + _t339*_t340 + _t340*_t344 - _t342*_t52*_t85 - _t350*_t351 + _t350*_t353 - _t352*_t62 + _t352*_t68 - _t354*_t42 + _t354*_t49 + _t87*(-_hc0[7]*_t3 - 0.2e1*_hc2[7] - 0.2e1*_t150);
  out[12] = d4f_dx22_du2;
  const double d4f_dx23_du = -_hc0[13]*_t27 + 0.12e2*_hc0[4]*_t286*_t70 + _hc0[5]*_t12*_t283 + _hc0[5]*_t275 - _hc0[5]*_t277 - 0.3e1*_hc0[5]*_t307 + _hc0[8]*_t203 - _hc0[8]*_t209 - _hc0[8]*_t218 - _hc0[9]*_t112 + _hc0[9]*_t37*_t61 - _hc0[9]*_t47 - _t116*_t358 - _t118*_t207 + _t121*_t207 + _t13*(_hc4[4]*_t229 - _hc4[5]*_t292 - _t192*_t227 + _t192*_t232 + 0.72e2*_t200*_t380 - 0.48e2*_t200*_t382 + _t226*_t75 - _t227*_t379 + _t232*_t379 + _t377*_t378 - _t378*_t381) - _t132*_t364 + _t144*_t170*_t219 - _t144*_t36*_t363 - 0.3e1*_t146*_t176 - _t154*_t223 + _t158*_t207 - _t159*_t211 + _t161*_t211 + _t163*_t362 - _t173*_t323 + _t174*_t319 - _t175*_t305 - _t175*_t309 - _t175*_t320 + _t176*_t220 + _t177*_t303 + _t179*_t323 - _t180*_t299*_t46 - _t181*_t365 - _t181*_t372 + _t182*_t304*_t36 + _t182*_t332 + _t183*_t328 - _t184*_t214*_t70 + _t184*_t215*_t216 - 0.2e1*_t185*_t337 + _t186*_t366 + _t186*_t369 - _t190*_t299 + _t191*_t304 + _t204*_t239*_t60 - _t208*_t316 + _t208*_t349 + _t212*_t339 + _t212*_t344 - 0.3e1*_t213*_t342 - _t217*_t312 - _t219*_t63*_t66 - _t221*_t319 + _t222*_t323 - _t223*_t351 + _t223*_t353 - _t236*_t42 + _t236*_t49 - 0.6e1*_t26*_t360 + _t274*_t371 - _t278*_t357 - _t285*_t372 + _t287*_t361 + _t291*_t359 + _t294*_t362 + _t294*_t366 + _t294*_t369 + _t297*_t359 - _t299*_t368 + _t302*_t67*_t86 - _t305*_t367 + _t306*_t375 + _t308*_t336 - _t309*_t367 + _t31*(-_hc0[13]*_hc1[0] - _hc0[8]*_t206 - _hc2[13]) + _t327*_t346 - _t330*_t363 + _t334*_t373 + _t339*_t374 - _t343*_t374 + _t344*_t374 + _t370*(-0.3e1*_hc2[4] - 0.3e1*_t64 - 0.3e1*_t65) - _t376*_t62 + _t376*_t68 + _t87*(-_hc0[4]*_t76 - _hc0[8]*_t3 - 0.2e1*_hc2[8]);
  out[13] = d4f_dx23_du;
  const double d4f_dx24 = -_hc0[14]*_t27 + ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t240 + ((_hc0[5]) * (_hc0[5]))*_t202 + _hc0[5]*_t286*_t385 + _hc0[5]*_t326*_t387 - 0.36e2*_hc0[5]*_t357 + 0.8e1*_hc0[9]*_t171 + _t13*(((_hc4[5]) * (_hc4[5]))*_t237 - _t231*_t391 + _t231*_t393 - 0.192e3*_t234*_t392 + _t377*_t390 + 0.288e3*_t380*_t91 - _t381*_t390 - 0.192e3*_t382*_t91 - _t391*_t96 + 0.120e3*_t392*_t4*_t5/xc_powi(_t6, 6) + _t393*_t96) + _t135*_t211*_t216*_t85 - _t146*_t383 - _t153*_t384 - 0.4e1*_t156*_t211*_t70 + _t174*_t388 - 0.6e1*_t175*_t180 - _t175*_t373 + 0.12e2*_t177*_t180 + _t177*_t30*_t387 - 0.8e1*_t180*_t367 + _t182*_t345*_t84 + 0.3e1*_t183*_t207 - _t190*_t359 + _t191*_t361 + 0.12e2*_t213*_t336 - _t221*_t388 + _t222*_t375 + _t273*_t371*(-0.4e1*_hc2[2] - 0.4e1*_t28 - 0.4e1*_t29) + _t31*(-_hc0[14]*_hc1[0] - _hc0[9]*_t76 - _hc2[14]) - 0.4e1*_t341*_t371 - _t346*_t364 + _t348*_t366 + _t348*_t369 - _t358*_t387 - _t359*_t368 - _t360*_t385 + _t365*_t366 + _t365*_t369 - _t367*_t373 + _t370*(-_hc0[2]*_t386 - 0.3e1*_hc2[5] - 0.3e1*_t83) + _t383*_t72 - _t384*_t71 - _t389*_t62 + _t389*_t68 + _t87*(-_hc0[5]*_t386 - _hc0[9]*_t3 - 0.2e1*_hc2[9]);
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_alpha_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_z_pf_k, _KMAX)(p, x2, u, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pc07_fab_k, _KMAX)(p, _hc0[0], _hc1);
#if _KMAX >= 1
  const double _t1 = _hc0[0]*_hc1[1];
#endif
#if _KMAX >= 2
  const double _t2 = ((_hc0[1]) * (_hc0[1]));
  const double _t3 = 0.2e1*_hc1[1];
  const double _t4 = _hc0[0]*_hc1[2];
  const double _t5 = _hc0[1]*_hc0[2];
  const double _t6 = ((_hc0[2]) * (_hc0[2]));
#endif
#if _KMAX >= 3
  const double _t7 = 0.6e1*_hc1[1];
  const double _t8 = _hc0[1]*_t7;
  const double _t9 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t10 = 0.3e1*_hc1[2];
  const double _t11 = _hc0[0]*_hc1[3];
  const double _t12 = 0.3e1*_t4;
  const double _t13 = _hc0[1]*_t12;
  const double _t14 = 0.4e1*_hc1[1];
  const double _t15 = _hc0[4]*_t14;
  const double _t16 = _hc0[2]*_hc0[3];
  const double _t17 = 0.2e1*_t4;
  const double _t18 = _hc0[4]*_t17;
  const double _t19 = _hc0[2]*_t2;
  const double _t20 = _hc0[1]*_hc0[5];
  const double _t21 = _hc0[1]*_t6;
  const double _t22 = _hc0[2]*_t7;
  const double _t23 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t24 = _hc0[2]*_t12;
#endif
#if _KMAX >= 4
  const double _t25 = 0.8e1*_hc1[1];
  const double _t26 = _hc0[1]*_hc0[6];
  const double _t27 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t28 = 0.4e1*_hc1[3];
  const double _t29 = ((_hc0[3]) * (_hc0[3]));
  const double _t30 = _hc0[0]*_hc1[4];
  const double _t31 = 0.4e1*_t4;
  const double _t32 = _hc1[2]*_t2;
  const double _t33 = _t11*_t2;
  const double _t34 = _hc0[2]*_hc0[6];
  const double _t35 = _hc0[4]*_t7;
  const double _t36 = _hc0[4]*_t12;
  const double _t37 = _hc1[2]*_t5;
  const double _t38 = 0.9e1*_t37;
  const double _t39 = 0.9e1*_hc0[4];
  const double _t40 = _hc0[2]*_t9;
  const double _t41 = _t11*_t5;
  const double _t42 = 0.3e1*_t41;
  const double _t43 = 0.3e1*_hc0[4];
  const double _t44 = _hc0[1]*_hc0[8];
  const double _t45 = _hc0[2]*_hc0[7];
  const double _t46 = _hc0[3]*_hc0[5];
  const double _t47 = ((_hc0[4]) * (_hc0[4]));
  const double _t48 = _hc0[5]*_t2;
  const double _t49 = _hc0[3]*_t6;
  const double _t50 = _t2*_t6;
  const double _t51 = _hc0[1]*_hc0[9];
  const double _t52 = _hc0[1]*_t23;
  const double _t53 = _hc1[2]*_t6;
  const double _t54 = _t11*_t6;
  const double _t55 = _hc0[2]*_hc0[9];
  const double _t56 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t57 = ((_hc0[5]) * (_hc0[5]));
#endif

  const double f = _hc0[0]*_hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _hc0[1]*_hc1[0] + _hc0[1]*_t1;
  out[1] = df_du;
  const double df_dx2 = _hc0[2]*_hc1[0] + _hc0[2]*_t1;
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _hc0[3]*_hc1[0] + _hc0[3]*_t1 + _t2*_t3 + _t2*_t4;
  out[3] = d2f_du2;
  const double d2f_dx2_du = _hc0[4]*_hc1[0] + _hc0[4]*_t1 + _t3*_t5 + _t4*_t5;
  out[4] = d2f_dx2_du;
  const double d2f_dx22 = _hc0[5]*_hc1[0] + _hc0[5]*_t1 + _t3*_t6 + _t4*_t6;
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_du3 = _hc0[3]*_t13 + _hc0[3]*_t8 + _hc0[6]*_hc1[0] + _hc0[6]*_t1 + _t10*_t9 + _t11*_t9;
  out[6] = d3f_du3;
  const double d3f_dx2_du2 = _hc0[1]*_t15 + _hc0[1]*_t18 + _hc0[7]*_hc1[0] + _hc0[7]*_t1 + _t10*_t19 + _t11*_t19 + _t16*_t3 + _t16*_t4;
  out[7] = d3f_dx2_du2;
  const double d3f_dx22_du = _hc0[2]*_t15 + _hc0[2]*_t18 + _hc0[8]*_hc1[0] + _hc0[8]*_t1 + _t10*_t21 + _t11*_t21 + _t20*_t3 + _t20*_t4;
  out[8] = d3f_dx22_du;
  const double d3f_dx23 = _hc0[5]*_t22 + _hc0[5]*_t24 + _hc0[9]*_hc1[0] + _hc0[9]*_t1 + _t10*_t23 + _t11*_t23;
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_du4 = _hc0[10]*_hc1[0] + _hc0[10]*_t1 + 0.18e2*_hc0[3]*_t32 + 0.6e1*_hc0[3]*_t33 + _t12*_t29 + _t25*_t26 + _t26*_t31 + _t27*_t28 + _t27*_t30 + _t29*_t7;
  out[10] = d4f_du4;
  const double d4f_dx2_du3 = _hc0[11]*_hc1[0] + _hc0[11]*_t1 + _hc0[3]*_t35 + _hc0[3]*_t36 + _hc0[3]*_t38 + _hc0[3]*_t42 + _hc0[7]*_t13 + _hc0[7]*_t8 + _t28*_t40 + _t3*_t34 + _t30*_t40 + _t32*_t39 + _t33*_t43 + _t34*_t4;
  out[11] = d4f_dx2_du3;
  const double d4f_dx22_du2 = _hc0[12]*_hc1[0] + _hc0[12]*_t1 + 0.12e2*_hc0[4]*_t37 + 0.4e1*_hc0[4]*_t41 + _t10*_t48 + _t10*_t49 + _t11*_t48 + _t11*_t49 + _t14*_t44 + _t14*_t45 + _t14*_t47 + _t17*_t44 + _t17*_t45 + _t17*_t47 + _t28*_t50 + _t3*_t46 + _t30*_t50 + _t4*_t46;
  out[12] = d4f_dx22_du2;
  const double d4f_dx23_du = _hc0[13]*_hc1[0] + _hc0[13]*_t1 + _hc0[5]*_t35 + _hc0[5]*_t36 + _hc0[5]*_t38 + _hc0[5]*_t42 + _hc0[8]*_t22 + _hc0[8]*_t24 + _t28*_t52 + _t3*_t51 + _t30*_t52 + _t39*_t53 + _t4*_t51 + _t43*_t54;
  out[13] = d4f_dx23_du;
  const double d4f_dx24 = _hc0[14]*_hc1[0] + _hc0[14]*_t1 + 0.18e2*_hc0[5]*_t53 + 0.6e1*_hc0[5]*_t54 + _t12*_t57 + _t25*_t55 + _t28*_t56 + _t30*_t56 + _t31*_t55 + _t57*_t7;
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(pc07_f_pf_k, _KMAX)(const xc_func_type *p, double x2, double u, double *out) {

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(pc07_alpha_pf_k, _KMAX)(p, x2, u, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(pc07_f_W_pf_k, _KMAX)(p, x2, _hc1);

  const double f = _hc0[0] + _hc1[0];
  out[0] = f;
#if _KMAX >= 1
  const double df_du = _hc0[1];
  out[1] = df_du;
  const double df_dx2 = _hc0[2] + _hc1[1];
  out[2] = df_dx2;
#endif
#if _KMAX >= 2
  const double d2f_du2 = _hc0[3];
  out[3] = d2f_du2;
  const double d2f_dx2_du = _hc0[4];
  out[4] = d2f_dx2_du;
  const double d2f_dx22 = _hc0[5];
  out[5] = d2f_dx22;
#endif
#if _KMAX >= 3
  const double d3f_du3 = _hc0[6];
  out[6] = d3f_du3;
  const double d3f_dx2_du2 = _hc0[7];
  out[7] = d3f_dx2_du2;
  const double d3f_dx22_du = _hc0[8];
  out[8] = d3f_dx22_du;
  const double d3f_dx23 = _hc0[9];
  out[9] = d3f_dx23;
#endif
#if _KMAX >= 4
  const double d4f_du4 = _hc0[10];
  out[10] = d4f_du4;
  const double d4f_dx2_du3 = _hc0[11];
  out[11] = d4f_dx2_du3;
  const double d4f_dx22_du2 = _hc0[12];
  out[12] = d4f_dx22_du2;
  const double d4f_dx23_du = _hc0[13];
  out[13] = d4f_dx23_du;
  const double d4f_dx24 = _hc0[14];
  out[14] = d4f_dx24;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_k_pc07_params *params = (const mgga_k_pc07_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(opz_pow_n_m1_n5_3_k, _KMAX)(p, 0.1e1 - p->zeta_threshold, _hc0);
  const double _t1 = xc_powr(n_s, -8, 3);
  const double _t2 = -p->dens_threshold + n_s <= 0;
  const double _t3 = xc_powr(0.3e1, 2, 3)*(M_PI * M_CBRTPI)*(_hc0[0] + 0.1e1);
  const double _t4 = (0.3e1 / 0.20e2)*_t3;
  const double _t5 = _t4*xc_powr(n_s, 2, 3);
#if _KMAX >= 1
  const double _t8 = (0.1e1 / (n_s * n_s));
  const double _t10 = xc_powr(n_s, -1, 3);
  const double _t11 = (0.1e1 / 0.10e2)*_t3;
  const double _t12 = (0.5e1 / 0.3e1)*_t1;
  const double _t14 = xc_powr(n_s, -11, 3);
  const double _t15 = (0.8e1 / 0.3e1)*_t14;
#endif
#if _KMAX >= 2
  const double _t21 = xc_powr(n_s, -14, 3);
  const double _t23 = xc_powr(n_s, -13, 3);
  const double _t24 = (0.5e1 / 0.3e1)*lapl_s;
  const double _t25 = _t23*_t24;
  const double _t26 = (0.8e1 / 0.3e1)*sigma_ss;
  const double _t27 = xc_powr(n_s, -16, 3);
  const double _t31 = (0.1e1 / (n_s * n_s * n_s));
  const double _t32 = xc_powr(n_s, -19, 3);
  const double _t33 = _t26*_t32;
  const double _t36 = xc_powr(n_s, -4, 3);
  const double _t37 = (0.1e1 / 0.30e2)*_t3;
  const double _t38 = _t10*_t3;
  const double _t39 = (0.1e1 / 0.5e1)*_t38;
  const double _t40 = (0.40e2 / 0.9e1)*_t14;
  const double _t42 = (0.88e2 / 0.9e1)*_t21;
#endif
#if _KMAX >= 3
  const double _t58 = xc_powr(n_s, -22, 3);
  const double _t60 = (0.10e2 / 0.3e1)*_t23;
  const double _t61 = xc_powi(n_s, -6);
  const double _t63 = xc_powi(n_s, -7);
  const double _t67 = (0.13e2 / 0.3e1)*_t27;
  const double _t68 = xc_powi(n_s, -8);
  const double _t72 = xc_powr(n_s, -17, 3);
  const double _t73 = (0.16e2 / 0.3e1)*_t32;
  const double _t74 = xc_powi(n_s, -9);
  const double _t79 = (0.40e2 / 0.9e1)*lapl_s;
  const double _t81 = (0.88e2 / 0.9e1)*sigma_ss;
  const double _t82 = _t26*_t27;
  const double _t84 = _t12*lapl_s;
  const double _t89 = (0.1e1 / (n_s * n_s * n_s * n_s));
  const double _t91 = _t24*_t27;
  const double _t95 = _t15*sigma_ss;
  const double _t98 = xc_powr(n_s, -7, 3);
  const double _t99 = (0.2e1 / 0.45e2)*_t3;
  const double _t100 = _t11*_t36;
  const double _t101 = (0.3e1 / 0.10e2)*_t38;
  const double _t102 = (0.440e3 / 0.27e2)*_t21;
  const double _t104 = (0.1232e4 / 0.27e2)*_t72;
#endif
#if _KMAX >= 4
  const double _t130 = xc_powi(n_s, -10);
  const double _t136 = xc_powr(n_s, -25, 3);
  const double _t139 = _t26*_t63;
  const double _t141 = _t26*_t68;
  const double _t143 = xc_powr(n_s, -20, 3);
  const double _t145 = (0.440e3 / 0.27e2)*lapl_s;
  const double _t146 = (0.1232e4 / 0.27e2)*sigma_ss;
  const double _t148 = _t32*_t81;
  const double _t152 = _t102*lapl_s;
  const double _t153 = _t104*sigma_ss;
  const double _t154 = _t40*lapl_s;
  const double _t155 = _t42*sigma_ss;
#endif
  double _hc1[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t2)) XC_CAT(pc07_f_pf_k, _KMAX)(p, _t1*sigma_ss, lapl_s/xc_powr(n_s, 5, 3), _hc1);
  const double _t6 = my_piecewise3(_t2, 0, _hc1[0]*_t5);
#if _KMAX >= 1
  const double _t7 = my_piecewise3(_t2, 0, _hc1[1]*_t4/n_s);
  const double _t9 = my_piecewise3(_t2, 0, _hc1[2]*_t4*_t8);
  const double _t13 = _hc1[1]*_t12;
  const double _t16 = _hc1[2]*_t15;
  const double _t17 = -_t13*lapl_s - _t16*sigma_ss;
  const double _t18 = my_piecewise3(_t2, 0, _hc1[0]*_t10*_t11 + _t17*_t5);
#endif
#if _KMAX >= 2
  const double _t19 = my_piecewise3(_t2, 0, _hc1[3]*_t1*_t4);
  const double _t20 = my_piecewise3(_t2, 0, _hc1[4]*_t14*_t4);
  const double _t22 = my_piecewise3(_t2, 0, _hc1[5]*_t21*_t4);
  const double _t28 = _hc1[4]*_t27;
  const double _t29 = -_hc1[3]*_t25 - _t13 - _t26*_t28;
  const double _t30 = my_piecewise3(_t2, 0, _hc1[1]*_t11*_t8 + _t29*_t5);
  const double _t34 = -_hc1[5]*_t33 - _t16 - _t24*_t28;
  const double _t35 = my_piecewise3(_t2, 0, _hc1[2]*_t11*_t31 + _t34*_t5);
  const double _t41 = _hc1[1]*_t40;
  const double _t43 = _hc1[2]*_t42;
  const double _t44 = _hc1[3]*_t12;
  const double _t45 = _hc1[4]*_t15;
  const double _t46 = -_t44*lapl_s - _t45*sigma_ss;
  const double _t47 = _t12*_t46;
  const double _t48 = _hc1[4]*_t12;
  const double _t49 = _hc1[5]*_t15;
  const double _t50 = -_t48*lapl_s - _t49*sigma_ss;
  const double _t51 = _t15*_t50;
  const double _t52 = _t41*lapl_s + _t43*sigma_ss - _t47*lapl_s - _t51*sigma_ss;
  const double _t53 = my_piecewise3(_t2, 0, -_hc1[0]*_t36*_t37 + _t17*_t39 + _t5*_t52);
#endif
#if _KMAX >= 3
  const double _t54 = my_piecewise3(_t2, 0, _hc1[6]*_t23*_t4);
  const double _t55 = my_piecewise3(_t2, 0, _hc1[7]*_t27*_t4);
  const double _t56 = _hc1[8]*_t32;
  const double _t57 = my_piecewise3(_t2, 0, _t4*_t56);
  const double _t59 = my_piecewise3(_t2, 0, _hc1[9]*_t4*_t58);
  const double _t62 = _hc1[6]*_t61;
  const double _t64 = _hc1[7]*_t63;
  const double _t65 = -_hc1[3]*_t60 - _t24*_t62 - _t26*_t64;
  const double _t66 = my_piecewise3(_t2, 0, _hc1[3]*_t11*_t14 + _t5*_t65);
  const double _t69 = _hc1[8]*_t68;
  const double _t70 = -_hc1[4]*_t67 - _t24*_t64 - _t26*_t69;
  const double _t71 = my_piecewise3(_t2, 0, _hc1[4]*_t11*_t21 + _t5*_t70);
  const double _t75 = _hc1[9]*_t74;
  const double _t76 = -_hc1[5]*_t73 - _t24*_t69 - _t26*_t75;
  const double _t77 = my_piecewise3(_t2, 0, _hc1[5]*_t11*_t72 + _t5*_t76);
  const double _t78 = _hc1[3]*_t27;
  const double _t80 = _hc1[4]*_t32;
  const double _t83 = -_hc1[6]*_t25 - _hc1[7]*_t82 - _t44;
  const double _t85 = -_hc1[7]*_t25 - _hc1[8]*_t82 - _t48;
  const double _t86 = _t15*_t85;
  const double _t87 = _t41 - _t47 + _t78*_t79 + _t80*_t81 - _t83*_t84 - _t86*sigma_ss;
  const double _t88 = my_piecewise3(_t2, 0, -_hc1[1]*_t31*_t37 + _t29*_t39 + _t5*_t87);
  const double _t90 = _hc1[5]*_t58;
  const double _t92 = -_hc1[7]*_t91 - _hc1[8]*_t33 - _t45;
  const double _t93 = _t12*_t92;
  const double _t94 = -_hc1[8]*_t91 - _hc1[9]*_t33 - _t49;
  const double _t96 = _t43 - _t51 + _t79*_t80 + _t81*_t90 - _t93*lapl_s - _t94*_t95;
  const double _t97 = my_piecewise3(_t2, 0, -_hc1[2]*_t37*_t89 + _t34*_t39 + _t5*_t96);
  const double _t103 = _hc1[1]*_t102;
  const double _t105 = _hc1[2]*_t104;
  const double _t106 = _hc1[3]*_t40;
  const double _t107 = _hc1[4]*_t42;
  const double _t108 = _hc1[6]*_t12;
  const double _t109 = _hc1[7]*_t15;
  const double _t110 = -_t108*lapl_s - _t109*sigma_ss;
  const double _t111 = _t110*_t12;
  const double _t112 = _hc1[7]*_t12;
  const double _t113 = _hc1[8]*_t15;
  const double _t114 = -_t112*lapl_s - _t113*sigma_ss;
  const double _t115 = _t114*_t15;
  const double _t116 = _t106*lapl_s + _t107*sigma_ss - _t111*lapl_s - _t115*sigma_ss;
  const double _t117 = _t116*_t12;
  const double _t118 = _hc1[4]*_t40;
  const double _t119 = _hc1[5]*_t42;
  const double _t120 = _t114*_t12;
  const double _t121 = _hc1[8]*_t12;
  const double _t122 = _hc1[9]*_t15;
  const double _t123 = -_t121*lapl_s - _t122*sigma_ss;
  const double _t124 = _t123*_t15;
  const double _t125 = _t118*lapl_s + _t119*sigma_ss - _t120*lapl_s - _t124*sigma_ss;
  const double _t126 = _t125*_t15;
  const double _t127 = -_t103*lapl_s - _t105*sigma_ss - _t117*lapl_s - _t126*sigma_ss + (0.80e2 / 0.9e1)*_t14*_t46*lapl_s + (0.176e3 / 0.9e1)*_t21*_t50*sigma_ss;
  const double _t128 = my_piecewise3(_t2, 0, _hc1[0]*_t98*_t99 - _t100*_t17 + _t101*_t52 + _t127*_t5);
#endif
#if _KMAX >= 4
  const double _t129 = _hc1[13]*_t74;
  const double _t131 = _hc1[10]*_t24;
  const double _t132 = _hc1[11]/xc_powr(n_s, 26, 3);
  const double _t133 = _hc1[12]/xc_powr(n_s, 29, 3);
  const double _t134 = _hc1[8]*_t58;
  const double _t135 = _hc1[13]/xc_powr(n_s, 32, 3);
  const double _t137 = _hc1[14]*_t26;
  const double _t138 = _hc1[6]*_t79;
  const double _t140 = _hc1[11]*_t24;
  const double _t142 = _hc1[12]*_t24;
  const double _t144 = _hc1[9]*_t81;
  const double _t147 = _hc1[4]*_t58;
  const double _t149 = -_hc1[11]*_t25 - _hc1[12]*_t82 - _t112;
  const double _t150 = _hc1[7]*_t79;
  const double _t151 = -_hc1[12]*_t91 - _hc1[13]*_t33 - _t113;
  const double _t156 = -_hc1[11]*_t84 - _hc1[12]*_t95;
  const double _t157 = -_hc1[12]*_t84 - _hc1[13]*_t95;
  const double _t158 = _hc1[7]*_t154 + _hc1[8]*_t155 - _t156*_t84 - _t157*_t95;
#endif

  const double f = my_piecewise3(_t2, 0, _t6*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = 0;
  out[1] = df_dtau_s;
  const double df_dlapl_s = my_piecewise3(_t2, 0, _t7*n_s);
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t2, 0, _t9*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t2, 0, _t18*n_s + _t6);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = 0;
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = my_piecewise3(_t2, 0, _t19*n_s);
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = 0;
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = my_piecewise3(_t2, 0, _t20*n_s);
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t2, 0, _t22*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = 0;
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = my_piecewise3(_t2, 0, _t30*n_s + _t7);
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t2, 0, _t35*n_s + _t9);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t2, 0, 0.2e1*_t18 + _t53*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = 0;
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = my_piecewise3(_t2, 0, _t54*n_s);
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = 0;
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = my_piecewise3(_t2, 0, _t55*n_s);
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = 0;
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = my_piecewise3(_t2, 0, _t57*n_s);
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t2, 0, _t59*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = 0;
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = my_piecewise3(_t2, 0, _t19 + _t66*n_s);
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = 0;
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = my_piecewise3(_t2, 0, _t20 + _t71*n_s);
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t2, 0, _t22 + _t77*n_s);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = 0;
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = my_piecewise3(_t2, 0, 0.2e1*_t30 + _t88*n_s);
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t2, 0, 0.2e1*_t35 + _t97*n_s);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t2, 0, _t128*n_s + 0.3e1*_t53);
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
  const double d4f_dlapl_s4 = my_piecewise3(_t2, 0, n_s*my_piecewise3(_t2, 0, _hc1[10]*_t4*_t61));
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = 0;
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = my_piecewise3(_t2, 0, n_s*my_piecewise3(_t2, 0, _hc1[11]*_t4*_t63));
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = 0;
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = my_piecewise3(_t2, 0, n_s*my_piecewise3(_t2, 0, _hc1[12]*_t4*_t68));
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = 0;
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = my_piecewise3(_t2, 0, n_s*my_piecewise3(_t2, 0, _t129*_t4));
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t2, 0, n_s*my_piecewise3(_t2, 0, _hc1[14]*_t130*_t4));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = 0;
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = my_piecewise3(_t2, 0, _t54 + n_s*my_piecewise3(_t2, 0, _hc1[6]*_t11*_t27 + _t5*(-_t131/xc_powr(n_s, 23, 3) - _t132*_t26 - 0.5e1*_t62)));
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = 0;
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = my_piecewise3(_t2, 0, _t55 + n_s*my_piecewise3(_t2, 0, _hc1[7]*_t11*_t32 + _t5*(-_t132*_t24 - _t133*_t26 - 0.6e1*_t64)));
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = 0;
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = my_piecewise3(_t2, 0, _t57 + n_s*my_piecewise3(_t2, 0, _t11*_t134 + _t5*(-_t133*_t24 - _t135*_t26 - 0.7e1*_t69)));
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t2, 0, _t59 + n_s*my_piecewise3(_t2, 0, _hc1[9]*_t11*_t136 + _t5*(-_t135*_t24 - _t137/xc_powr(n_s, 35, 3) - 0.8e1*_t75)));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = 0;
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = my_piecewise3(_t2, 0, 0.2e1*_t66 + n_s*my_piecewise3(_t2, 0, -_hc1[3]*_t21*_t37 + _t39*_t65 + _t5*(_hc1[7]*_t68*_t81 - 0.10e2 / 0.3e1*_t1*_t83 + _t138*_t63 + (0.80e2 / 0.9e1)*_t78 - _t84*(-_hc1[11]*_t139 - _hc1[6]*_t60 - _t131*_t61) - _t95*(-_hc1[12]*_t139 - _hc1[7]*_t60 - _t140*_t61))));
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = 0;
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = my_piecewise3(_t2, 0, 0.2e1*_t71 + n_s*my_piecewise3(_t2, 0, -_hc1[4]*_t37*_t72 + _t39*_t70 + _t5*((0.128e3 / 0.9e1)*_hc1[4]*_t32 + (0.40e2 / 0.9e1)*_hc1[7]*_t68*lapl_s + (0.88e2 / 0.9e1)*_hc1[8]*_t74*sigma_ss - _t84*(-_hc1[12]*_t141 - _hc1[7]*_t67 - _t140*_t63) - _t86 - _t93 - _t95*(-_hc1[13]*_t141 - _hc1[8]*_t67 - _t142*_t63))));
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t2, 0, 0.2e1*_t77 + n_s*my_piecewise3(_t2, 0, -_hc1[5]*_t143*_t37 + _t39*_t76 + _t5*(_hc1[8]*_t74*_t79 + _t130*_t144 - 0.16e2 / 0.3e1*_t14*_t94 - _t84*(-_hc1[8]*_t73 - _t129*_t26 - _t142*_t68) + (0.176e3 / 0.9e1)*_t90 - _t95*(-_hc1[13]*_t24*_t68 - _hc1[9]*_t73 - _t137*_t74))));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = 0;
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = my_piecewise3(_t2, 0, 0.3e1*_t88 + n_s*my_piecewise3(_t2, 0, _hc1[1]*_t89*_t99 - _t100*_t29 + _t101*_t87 + _t5*(-_hc1[3]*_t145*_t32 - _t103 - _t117 + (0.80e2 / 0.9e1)*_t14*_t46 + (0.80e2 / 0.9e1)*_t14*_t83*lapl_s - _t146*_t147 + (0.176e3 / 0.9e1)*_t21*_t85*sigma_ss - _t84*(_hc1[7]*_t148 + _t106 - _t111 + _t138*_t27 - _t149*_t95 - _t84*(-_hc1[10]*_t25 - _hc1[11]*_t82 - _t108)) - _t95*(_hc1[8]*_t148 + _t118 - _t120 - _t149*_t84 + _t150*_t27 - _t95*(-_hc1[12]*_t25 - _hc1[13]*_t82 - _t121)))));
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t2, 0, 0.3e1*_t97 + n_s*my_piecewise3(_t2, 0, _hc1[2]*_t99/xc_powi(n_s, 5) - _t100*_t34 + _t101*_t96 + _t5*(-_hc1[5]*_t136*_t146 - _t105 - _t126 + (0.80e2 / 0.9e1)*_t14*_t92*lapl_s - _t145*_t147 + (0.176e3 / 0.9e1)*_t21*_t50 + (0.176e3 / 0.9e1)*_t21*_t94*sigma_ss - _t84*(_t107 - _t115 + _t134*_t81 + _t150*_t32 - _t151*_t95 - _t84*(-_hc1[11]*_t91 - _hc1[12]*_t33 - _t109)) - _t95*(_t119 - _t124 + _t144*_t58 - _t151*_t84 + _t56*_t79 - _t95*(-_hc1[13]*_t91 - _hc1[14]*_t33 - _t122)))));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t2, 0, 0.4e1*_t128 + n_s*my_piecewise3(_t2, 0, -0.14e2 / 0.135e3*_hc1[0]*_t3/xc_powr(n_s, 10, 3) + (0.2e1 / 0.5e1)*_t127*_t38 + (0.8e1 / 0.45e2)*_t17*_t3*_t98 - 0.1e1 / 0.5e1*_t3*_t36*_t52 + _t5*((0.6160e4 / 0.81e2)*_hc1[1]*_t72*lapl_s + (0.20944e5 / 0.81e2)*_hc1[2]*_t143*sigma_ss + (0.40e2 / 0.3e1)*_t116*_t14*lapl_s + (0.88e2 / 0.3e1)*_t125*_t21*sigma_ss - 0.440e3 / 0.9e1*_t21*_t46*lapl_s - 0.1232e4 / 0.9e1*_t50*_t72*sigma_ss - _t84*(-_hc1[3]*_t152 - _hc1[4]*_t153 + (0.80e2 / 0.9e1)*_t110*_t14*lapl_s + (0.176e3 / 0.9e1)*_t114*_t21*sigma_ss - _t158*_t95 - _t84*(_hc1[6]*_t154 + _hc1[7]*_t155 - _t156*_t95 - _t84*(-_hc1[10]*_t84 - _hc1[11]*_t95))) - _t95*(-_hc1[4]*_t152 - _hc1[5]*_t153 + (0.80e2 / 0.9e1)*_t114*_t14*lapl_s + (0.176e3 / 0.9e1)*_t123*_t21*sigma_ss - _t158*_t84 - _t95*(_hc1[8]*_t154 + _hc1[9]*_t155 - _t157*_t84 - _t95*(-_hc1[13]*_t84 - _hc1[14]*_t95))))));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_k_pc07_params *params = (const mgga_k_pc07_params *)(p->params);
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