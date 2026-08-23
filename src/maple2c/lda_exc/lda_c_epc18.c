/*
  Generated from python/lda_exc/lda_c_epc18.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py lda_c_epc18
*/

#ifndef _LDA_C_EPC18_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _LDA_C_EPC18_KERNEL_BODY
#define _KMAX 0
#define _LDA_C_EPC18_HELPER_BODIES
#include "lda_c_epc18.c"
#undef _LDA_C_EPC18_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _LDA_C_EPC18_HELPER_BODIES
#include "lda_c_epc18.c"
#undef _LDA_C_EPC18_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _LDA_C_EPC18_HELPER_BODIES
#include "lda_c_epc18.c"
#undef _LDA_C_EPC18_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _LDA_C_EPC18_HELPER_BODIES
#include "lda_c_epc18.c"
#undef _LDA_C_EPC18_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _LDA_C_EPC18_HELPER_BODIES
#include "lda_c_epc18.c"
#undef _LDA_C_EPC18_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "lda_c_epc18.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_LDA_C_EPC18_HELPER_BODIES)

/* ---- helpers (one graded body -> <name>_k<order>) ---- */

GPU_DEVICE_FUNCTION static inline void XC_CAT(z_thr_k, _KMAX)(const xc_func_type *p, double z, double *out) {

  const double _t1 = z + 0.1e1 <= p->zeta_threshold;
  const double _t2 = p->zeta_threshold - 0.1e1;
  const double _t3 = 0.1e1 - z <= p->zeta_threshold;
#if _KMAX >= 2
  const double _t4 = my_piecewise5(_t1, 0, _t3, 0, 0);
#endif

  const double f = my_piecewise5(_t1, _t2, _t3, -_t2, z);
  out[0] = f;
#if _KMAX >= 1
  const double df_dz = my_piecewise5(_t1, 0, _t3, 0, 0.1e1);
  out[1] = df_dz;
#endif
#if _KMAX >= 2
  const double d2f_dz2 = _t4;
  out[2] = d2f_dz2;
#endif
#if _KMAX >= 3
  const double d3f_dz3 = _t4;
  out[3] = d3f_dz3;
#endif
#if _KMAX >= 4
  const double d4f_dz4 = _t4;
  out[4] = d4f_dz4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(epc18_beta_k, _KMAX)(const xc_func_type *p, double rho_e, double rho_p, double *out) {


  const double f = xc_powr(rho_e, 1, 3) + xc_powr(rho_p, 1, 3);
  out[0] = f;
#if _KMAX >= 1
  const double df_drho_p = (0.1e1 / 0.3e1)/xc_powr(rho_p, 2, 3);
  out[1] = df_drho_p;
  const double df_drho_e = (0.1e1 / 0.3e1)/xc_powr(rho_e, 2, 3);
  out[2] = df_drho_e;
#endif
#if _KMAX >= 2
  const double d2f_drho_p2 = -(0.2e1 / 0.9e1)/xc_powr(rho_p, 5, 3);
  out[3] = d2f_drho_p2;
  const double d2f_drho_e_drho_p = 0;
  out[4] = d2f_drho_e_drho_p;
  const double d2f_drho_e2 = -(0.2e1 / 0.9e1)/xc_powr(rho_e, 5, 3);
  out[5] = d2f_drho_e2;
#endif
#if _KMAX >= 3
  const double d3f_drho_p3 = (0.10e2 / 0.27e2)/xc_powr(rho_p, 8, 3);
  out[6] = d3f_drho_p3;
  const double d3f_drho_e_drho_p2 = 0;
  out[7] = d3f_drho_e_drho_p2;
  const double d3f_drho_e2_drho_p = 0;
  out[8] = d3f_drho_e2_drho_p;
  const double d3f_drho_e3 = (0.10e2 / 0.27e2)/xc_powr(rho_e, 8, 3);
  out[9] = d3f_drho_e3;
#endif
#if _KMAX >= 4
  const double d4f_drho_p4 = -(0.80e2 / 0.81e2)/xc_powr(rho_p, 11, 3);
  out[10] = d4f_drho_p4;
  const double d4f_drho_e_drho_p3 = 0;
  out[11] = d4f_drho_e_drho_p3;
  const double d4f_drho_e2_drho_p2 = 0;
  out[12] = d4f_drho_e2_drho_p2;
  const double d4f_drho_e3_drho_p = 0;
  out[13] = d4f_drho_e3_drho_p;
  const double d4f_drho_e4 = -(0.80e2 / 0.81e2)/xc_powr(rho_e, 11, 3);
  out[14] = d4f_drho_e4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(epc18_E_k, _KMAX)(const xc_func_type *p, double rho_e, double rho_p, double *out) {
  const lda_c_epc18_params *params = (const lda_c_epc18_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1];
  XC_CAT(epc18_beta_k, _KMAX)(p, rho_e, rho_p, _hc0);
  const double _t1 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]));
  const double _t2 = xc_powi((_hc0[0]), 6)*params->c - _t1*params->b + params->a;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t3*rho_e;
#if _KMAX >= 1
  const double _t5 = (0.1e1 / (_t2 * _t2));
  const double _t6 = ((_hc0[0]) * (_hc0[0]));
  const double _t7 = xc_powi((_hc0[0]), 5)*params->c;
  const double _t8 = 0.6e1*_t7;
  const double _t9 = 0.3e1*_hc0[1]*_t6*params->b - _hc0[1]*_t8;
  const double _t10 = _t5*_t9;
  const double _t11 = _t10*rho_p;
  const double _t12 = 0.3e1*_hc0[2]*_t6*params->b - _hc0[2]*_t8;
  const double _t13 = _t12*_t5;
  const double _t14 = _t13*rho_e;
#endif
#if _KMAX >= 2
  const double _t15 = 0.2e1*_t10;
  const double _t16 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t17 = 0.12e2*_t7;
  const double _t18 = -_hc0[1]*_t17 + 0.6e1*_hc0[1]*_t6*params->b;
  const double _t19 = _t16*_t18;
  const double _t20 = _t9*rho_p;
  const double _t21 = _t19*_t20;
  const double _t22 = ((_hc0[1]) * (_hc0[1]));
  const double _t23 = ((_hc0[0]) * (_hc0[0]) * (_hc0[0]) * (_hc0[0]))*params->c;
  const double _t24 = 0.30e2*_t23;
  const double _t25 = 0.6e1*_hc0[0]*_t22*params->b + 0.3e1*_hc0[3]*_t6*params->b - _hc0[3]*_t8 - _t22*_t24;
  const double _t26 = _t25*_t5;
  const double _t27 = _t26*rho_p;
  const double _t28 = _hc0[1]*_hc0[2];
  const double _t29 = 0.6e1*_hc0[0]*_hc0[1]*_hc0[2]*params->b - _t24*_t28;
  const double _t30 = _t5*rho_p;
  const double _t31 = _t30*rho_e;
  const double _t32 = _t12*rho_e;
  const double _t33 = _t32*rho_p;
  const double _t34 = 0.2e1*_t13;
  const double _t35 = -_hc0[2]*_t17 + 0.6e1*_hc0[2]*_t6*params->b;
  const double _t36 = _t16*_t35;
  const double _t37 = _t32*_t36;
  const double _t38 = ((_hc0[2]) * (_hc0[2]));
  const double _t39 = 0.6e1*_hc0[0]*_t38*params->b + 0.3e1*_hc0[5]*_t6*params->b - _hc0[5]*_t8 - _t24*_t38;
  const double _t40 = _t39*_t5;
  const double _t41 = _t40*rho_e;
#endif
#if _KMAX >= 3
  const double _t42 = 0.3e1*_t19;
  const double _t43 = _t42*_t9;
  const double _t44 = 0.3e1*_t26;
  const double _t45 = ((_hc0[1]) * (_hc0[1]) * (_hc0[1]));
  const double _t46 = 0.90e2*_t23;
  const double _t47 = _hc0[1]*_hc0[3];
  const double _t48 = _t1*params->c;
  const double _t49 = 0.120e3*_t48;
  const double _t50 = 0.18e2*_hc0[0]*_hc0[1]*_hc0[3]*params->b + 0.3e1*_hc0[6]*_t6*params->b - _hc0[6]*_t8 - _t45*_t49 + 0.6e1*_t45*params->b - _t46*_t47;
  const double _t51 = _t30*_t50;
  const double _t52 = _t20*rho_e;
  const double _t53 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t54 = 0.18e2*_t7;
  const double _t55 = -_hc0[1]*_t54 + 0.9e1*_hc0[1]*_t6*params->b;
  const double _t56 = _t53*_t55;
  const double _t57 = _t18*_t56;
  const double _t58 = 0.60e2*_t23;
  const double _t59 = 0.12e2*_hc0[0]*_t22*params->b - _hc0[3]*_t17 + 0.6e1*_hc0[3]*_t6*params->b - _t22*_t58;
  const double _t60 = _t16*_t59;
  const double _t61 = _t20*_t60;
  const double _t62 = _t19*_t25;
  const double _t63 = 0.2e1*rho_e;
  const double _t64 = _t63*rho_p;
  const double _t65 = _t29*_t5;
  const double _t66 = _t12*_t19;
  const double _t67 = _t29*rho_p;
  const double _t68 = _t19*_t67;
  const double _t69 = _hc0[2]*_hc0[3];
  const double _t70 = _t22*_t49;
  const double _t71 = 0.6e1*_hc0[0]*_hc0[2]*_hc0[3]*params->b + 0.6e1*_hc0[2]*_t22*params->b - _hc0[2]*_t70 - _t24*_t69;
  const double _t72 = 0.2e1*_t30;
  const double _t73 = 0.2e1*rho_p;
  const double _t74 = rho_e*rho_p;
  const double _t75 = _t29*_t36;
  const double _t76 = 0.12e2*_hc0[0]*_hc0[1]*_hc0[2]*params->b - _t28*_t58;
  const double _t77 = _t16*_t32;
  const double _t78 = _t77*rho_p;
  const double _t79 = _hc0[1]*_hc0[5];
  const double _t80 = _hc0[1]*_t38;
  const double _t81 = 0.6e1*_hc0[0]*_hc0[1]*_hc0[5]*params->b + 0.6e1*_hc0[1]*_t38*params->b - _t24*_t79 - _t49*_t80;
  const double _t82 = _t35*_t56;
  const double _t83 = _t19*_t39;
  const double _t84 = 0.3e1*_t36;
  const double _t85 = _t12*_t84;
  const double _t86 = 0.3e1*_t40;
  const double _t87 = ((_hc0[2]) * (_hc0[2]) * (_hc0[2]));
  const double _t88 = _hc0[2]*_hc0[5];
  const double _t89 = 0.18e2*_hc0[0]*_hc0[2]*_hc0[5]*params->b + 0.3e1*_hc0[9]*_t6*params->b - _hc0[9]*_t8 - _t46*_t88 - _t49*_t87 + 0.6e1*_t87*params->b;
  const double _t90 = _t89*rho_e;
  const double _t91 = -_hc0[2]*_t54 + 0.9e1*_hc0[2]*_t6*params->b;
  const double _t92 = _t35*_t53;
  const double _t93 = _t91*_t92;
  const double _t94 = 0.12e2*_hc0[0]*_t38*params->b - _hc0[5]*_t17 + 0.6e1*_hc0[5]*_t6*params->b - _t38*_t58;
  const double _t95 = _t77*_t94;
  const double _t96 = _t39*rho_p;
  const double _t97 = _t36*_t63;
#endif
#if _KMAX >= 4
  const double _t98 = _t5*rho_e;
  const double _t99 = 0.4e1*_t9*rho_e;
  const double _t100 = _t19*rho_e;
  const double _t101 = 0.180e3*_t23;
  const double _t102 = 0.240e3*_t48;
  const double _t103 = 0.36e2*_hc0[0]*_hc0[1]*_hc0[3]*params->b - _hc0[6]*_t17 + 0.6e1*_hc0[6]*_t6*params->b - _t101*_t47 - _t102*_t45 + 0.12e2*_t45*params->b;
  const double _t104 = _t18*_t52;
  const double _t105 = xc_powi(_t2, -5);
  const double _t106 = 0.24e2*_t7;
  const double _t107 = _t105*(-_hc0[1]*_t106 + 0.12e2*_hc0[1]*_t6*params->b);
  const double _t108 = _t107*_t55;
  const double _t109 = 0.18e2*_hc0[0]*_t22*params->b - _hc0[3]*_t54 + 0.9e1*_hc0[3]*_t6*params->b - _t22*_t46;
  const double _t110 = _t109*_t53;
  const double _t111 = _t25*_t74;
  const double _t112 = 0.3e1*_t57;
  const double _t113 = _t56*_t59;
  const double _t114 = 0.3e1*_t60;
  const double _t115 = ((_hc0[3]) * (_hc0[3]));
  const double _t116 = 0.120e3*_t23;
  const double _t117 = 0.360e3*params->c;
  const double _t118 = _t117*_t6;
  const double _t119 = 0.720e3*_t48;
  const double _t120 = 0.3e1*_t71;
  const double _t121 = 0.360e3*_t48;
  const double _t122 = _t29*_t74;
  const double _t123 = _t18*_t33;
  const double _t124 = _t12*_t64;
  const double _t125 = _t12*_t16;
  const double _t126 = _t125*_t76;
  const double _t127 = _t63*_t67;
  const double _t128 = _t16*_t76;
  const double _t129 = _t63*_t81;
  const double _t130 = _t12*_t82;
  const double _t131 = _t12*_t73;
  const double _t132 = _t19*rho_p;
  const double _t133 = _t39*_t74;
  const double _t134 = _t33*_t92;
  const double _t135 = 0.3e1*rho_p;
  const double _t136 = _t33*_t91;
  const double _t137 = _t16*_t94;
  const double _t138 = _t63*_t96;
  const double _t139 = _t136*_t35;
  const double _t140 = 0.4e1*rho_p;
  const double _t141 = 0.3e1*_t133;
  const double _t142 = ((_hc0[5]) * (_hc0[5]));
#endif

  const double f = -_t4*rho_p;
  out[0] = f;
#if _KMAX >= 1
  const double df_drho_p = -_t11*rho_e - _t4;
  out[1] = df_drho_p;
  const double df_drho_e = -_t14*rho_p - _t3*rho_p;
  out[2] = df_drho_e;
#endif
#if _KMAX >= 2
  const double d2f_drho_p2 = -_t15*rho_e - _t21*rho_e - _t27*rho_e;
  out[3] = d2f_drho_p2;
  const double d2f_drho_e_drho_p = -_t11 - _t14 - _t19*_t33 - _t29*_t31 - _t3;
  out[4] = d2f_drho_e_drho_p;
  const double d2f_drho_e2 = -_t34*rho_p - _t37*rho_p - _t41*rho_p;
  out[5] = d2f_drho_e2;
#endif
#if _KMAX >= 3
  const double d3f_drho_p3 = -_t43*rho_e - _t44*rho_e - _t51*rho_e - _t52*_t57 - _t61*rho_e - _t62*_t64;
  out[6] = d3f_drho_p3;
  const double d3f_drho_e_drho_p2 = -_t15 - _t21 - _t27 - _t31*_t71 - _t33*_t57 - _t33*_t60 - _t63*_t65 - _t63*_t66 - _t63*_t68;
  out[7] = d3f_drho_e_drho_p2;
  const double d3f_drho_e2_drho_p = -_t29*_t72 - _t31*_t81 - _t33*_t82 - _t34 - _t37 - _t41 - _t66*_t73 - _t74*_t75 - _t74*_t83 - _t76*_t78;
  out[8] = d3f_drho_e2_drho_p;
  const double d3f_drho_e3 = -_t30*_t90 - _t33*_t93 - _t85*rho_p - _t86*rho_p - _t95*rho_p - _t96*_t97;
  out[9] = d3f_drho_e3;
#endif
#if _KMAX >= 4
  const double d4f_drho_p4 = -0.8e1*_t100*_t25 - _t103*_t16*_t52 - _t104*_t108 - _t104*_t110 - _t111*_t112 - _t111*_t114 - _t113*_t20*_t63 - _t31*(0.24e2*_hc0[0]*_hc0[1]*_hc0[6]*params->b + 0.18e2*_hc0[0]*_t115*params->b - ((_hc0[1]) * (_hc0[1]) * (_hc0[1]) * (_hc0[1]))*_t118 - _hc0[1]*_hc0[6]*_t116 + 0.3e1*_hc0[10]*_t6*params->b - _hc0[10]*_t8 - _hc0[3]*_t119*_t22 + 0.36e2*_hc0[3]*_t22*params->b - _t115*_t46) - _t42*_t50*_t74 - 0.4e1*_t50*_t98 - _t57*_t99 - _t60*_t99;
  out[10] = d4f_drho_p4;
  const double d4f_drho_e_drho_p3 = -0.6e1*_t100*_t29 - _t103*_t78 - _t108*_t123 - _t110*_t123 - _t112*_t122 - _t112*_t32 - _t113*_t124 - _t114*_t122 - _t114*_t32 - _t120*_t19*_t74 - _t120*_t98 - _t20*_t57 - _t31*(0.6e1*_hc0[0]*_hc0[2]*_hc0[6]*params->b + 0.18e2*_hc0[1]*_hc0[2]*_hc0[3]*params->b - _hc0[2]*_hc0[6]*_t24 - _hc0[2]*_t118*_t45 - _hc0[3]*_t121*_t28) - _t43 - _t44 - _t51 - _t61 - _t62*_t73;
  out[11] = d4f_drho_e_drho_p3;
  const double d4f_drho_e2_drho_p2 = -_t108*_t33*_t35 - _t109*_t134 - _t124*_t56*_t76 - _t126*_t63 - _t127*_t128 - _t127*_t82 - _t129*_t132 - _t129*_t5 - _t130*_t63 - _t131*_t57 - _t131*_t60 - _t133*_t57 - _t133*_t60 - _t31*(0.6e1*_hc0[0]*_hc0[3]*_hc0[5]*params->b - _hc0[3]*_hc0[5]*_t24 - _hc0[3]*_t38*_t49 + 0.6e1*_hc0[3]*_t38*params->b + 0.6e1*_hc0[5]*_t22*params->b - _hc0[5]*_t70 - _t118*_t22*_t38) - _t36*_t71*_t74 - _t63*_t75 - _t63*_t83 - 0.4e1*_t65 - 0.4e1*_t66 - 0.4e1*_t68 - _t71*_t72 - _t78*(0.12e2*_hc0[0]*_hc0[2]*_hc0[3]*params->b - _hc0[2]*_t102*_t22 + 0.12e2*_hc0[2]*_t22*params->b - _t58*_t69);
  out[12] = d4f_drho_e2_drho_p2;
  const double d4f_drho_e3_drho_p = -_t107*_t139 - _t122*_t137 - _t122*_t93 - _t126*_t135 - _t128*_t138 - _t129*_t36*rho_p - _t130*_t135 - _t132*_t90 - _t134*(0.18e2*_hc0[0]*_hc0[1]*_hc0[2]*params->b - _t28*_t46) - _t136*_t53*_t76 - _t138*_t82 - 0.3e1*_t30*_t81 - _t31*(0.6e1*_hc0[0]*_hc0[1]*_hc0[9]*params->b + 0.18e2*_hc0[1]*_hc0[2]*_hc0[5]*params->b - _hc0[1]*_hc0[9]*_t24 - _hc0[1]*_t117*_t6*_t87 - _hc0[5]*_t121*_t28) - _t32*_t93 - _t33*_t56*_t94 - _t39*_t97 - _t42*_t96 - _t5*_t90 - _t67*_t84 - _t78*(0.12e2*_hc0[0]*_hc0[1]*_hc0[5]*params->b + 0.12e2*_hc0[1]*_t38*params->b - _t102*_t80 - _t58*_t79) - _t85 - _t86 - _t95;
  out[13] = d4f_drho_e3_drho_p;
  const double d4f_drho_e4 = -_t105*_t139*(-_hc0[2]*_t106 + 0.12e2*_hc0[2]*_t6*params->b) - _t12*_t140*_t93 - _t124*_t53*_t91*_t94 - _t125*_t140*_t94 - _t134*(0.18e2*_hc0[0]*_t38*params->b - _hc0[5]*_t54 + 0.9e1*_hc0[5]*_t6*params->b - _t38*_t46) - _t137*_t141 - _t141*_t93 - 0.4e1*_t30*_t89 - _t31*(0.24e2*_hc0[0]*_hc0[2]*_hc0[9]*params->b + 0.18e2*_hc0[0]*_t142*params->b + 0.3e1*_hc0[14]*_t6*params->b - _hc0[14]*_t8 - ((_hc0[2]) * (_hc0[2]) * (_hc0[2]) * (_hc0[2]))*_t118 - _hc0[2]*_hc0[9]*_t116 - _hc0[5]*_t119*_t38 + 0.36e2*_hc0[5]*_t38*params->b - _t142*_t46) - 0.8e1*_t36*_t96 - _t78*(0.36e2*_hc0[0]*_hc0[2]*_hc0[5]*params->b - _hc0[9]*_t17 + 0.6e1*_hc0[9]*_t6*params->b - _t101*_t88 - _t102*_t87 + 0.12e2*_t87*params->b) - _t84*_t90*rho_p;
  out[14] = d4f_drho_e4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, xc_lda_out_params *out)
{
  assert(p->params != NULL);
  const lda_c_epc18_params *params = (const lda_c_epc18_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];

  const double _t1 = (0.1e1 / 0.2e1)*na;
  const double _t2 = -p->dens_threshold + (0.1e1 / 0.2e1)*na <= 0;
  const double _t3 = (0.1e1 / na);
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t2)) XC_CAT(epc18_E_k, _KMAX)(p, _t1, _t1, _hc0);
  const double _t4 = my_piecewise3(_t2, 0, _hc0[0]*_t3);
  const double zk = _t4;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t5 = (0.1e1 / (na * na));
  const double _t6 = (0.1e1 / 0.2e1)*_hc0[1] + (0.1e1 / 0.2e1)*_hc0[2];
  const double _t7 = my_piecewise3(_t2, 0, -_hc0[0]*_t5 + _t3*_t6);
  const double dF_dna = _t4 + _t7*na;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
#endif
#if _KMAX >= 2
  const double _t8 = (0.1e1 / (na * na * na));
  const double _t9 = (0.1e1 / 0.4e1)*_hc0[3] + (0.1e1 / 0.2e1)*_hc0[4] + (0.1e1 / 0.4e1)*_hc0[5];
  const double _t10 = my_piecewise3(_t2, 0, 0.2e1*_hc0[0]*_t8 + _t3*_t9 - 0.2e1*_t5*_t6);
  const double d2F_dna2 = _t10*na + 0.2e1*_t7;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
#endif
#if _KMAX >= 3
  const double _t11 = (0.1e1 / (na * na * na * na));
  const double _t12 = (0.1e1 / 0.8e1)*_hc0[6] + (0.3e1 / 0.8e1)*_hc0[7] + (0.3e1 / 0.8e1)*_hc0[8] + (0.1e1 / 0.8e1)*_hc0[9];
  const double _t13 = my_piecewise3(_t2, 0, -0.6e1*_hc0[0]*_t11 + _t12*_t3 - 0.3e1*_t5*_t9 + 0.6e1*_t6*_t8);
  const double d3F_dna3 = 0.3e1*_t10 + _t13*na;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = 0.4e1*_t13 + na*my_piecewise3(_t2, 0, 0.24e2*_hc0[0]/xc_powi(na, 5) - 0.24e2*_t11*_t6 - 0.4e1*_t12*_t5 + _t3*((0.1e1 / 0.16e2)*_hc0[10] + (0.1e1 / 0.4e1)*_hc0[11] + (0.3e1 / 0.8e1)*_hc0[12] + (0.1e1 / 0.4e1)*_hc0[13] + (0.1e1 / 0.16e2)*_hc0[14]) + 0.12e2*_t8*_t9);
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];

  const double _t1 = na - nb;
  const double _t2 = na + nb;
  const double _t3 = (0.1e1 / _t2);
  const double _t4 = _t1*_t3;
  const double _t5 = (0.1e1 / 0.2e1)*_t2;
  const double _t6 = na <= p->dens_threshold && nb <= p->dens_threshold;
  double _hc0[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, _t4, _hc0);
  double _hc1[(_KMAX) >= 4 ? 5 : (_KMAX) >= 3 ? 4 : (_KMAX) >= 2 ? 3 : (_KMAX) >= 1 ? 2 : 1];
  XC_CAT(z_thr_k, _KMAX)(p, -_t4, _hc1);
  double _hc2[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t6)) XC_CAT(epc18_E_k, _KMAX)(p, _t5*(_hc0[0] + 0.1e1), _t5*(_hc1[0] + 0.1e1), _hc2);
  const double _t7 = my_piecewise3(_t6, 0, _hc2[0]*_t3);
  const double zk = _t7;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double _t8 = (0.1e1 / (_t2 * _t2));
  const double _t10 = -_t3;
  const double _t11 = _t1*_t8;
  const double _t12 = _t10 + _t11;
  const double _t13 = -_t12;
  const double _t22 = _t11 + _t3;
  const double _t25 = -_t22;
  const double _t9 = _hc2[0]*_t8;
  const double _t14 = _hc0[1]*_t13;
  const double _t15 = (0.1e1 / 0.2e1)*_hc0[0] + 0.1e1 / 0.2e1;
  const double _t16 = _t14*_t5 + _t15;
  const double _t17 = _hc1[1]*_t12;
  const double _t18 = (0.1e1 / 0.2e1)*_hc1[0] + 0.1e1 / 0.2e1;
  const double _t19 = _t17*_t5 + _t18;
  const double _t20 = _hc2[1]*_t19 + _hc2[2]*_t16;
  const double _t21 = my_piecewise3(_t6, 0, _t20*_t3 - _t9);
  const double _t23 = _hc1[1]*_t22;
  const double _t24 = _t18 + _t23*_t5;
  const double _t26 = _hc0[1]*_t25;
  const double _t27 = _t15 + _t26*_t5;
  const double _t28 = _hc2[1]*_t24 + _hc2[2]*_t27;
  const double _t29 = my_piecewise3(_t6, 0, _t28*_t3 - _t9);
  const double dF_dna = _t2*_t21 + _t7;
  const double dF_dnb = _t2*_t29 + _t7;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
#endif
#if _KMAX >= 2
  const double _t30 = (0.1e1 / (_t2 * _t2 * _t2));
  const double _t31 = 0.2e1*_t30;
  const double _t33 = 0.2e1*_t8;
  const double _t34 = _t1*_t31;
  const double _t35 = -_t33 + _t34;
  const double _t37 = (_t13 * _t13);
  const double _t40 = -_t35;
  const double _t42 = (_t12 * _t12);
  const double _t59 = (_t22 * _t22);
  const double _t61 = _t33 + _t34;
  const double _t62 = -_t61;
  const double _t66 = (_t25 * _t25);
  const double _t32 = _hc2[0]*_t31;
  const double _t36 = _hc0[1]*_t35;
  const double _t38 = _hc0[2]*_t37;
  const double _t39 = _t14 + _t36*_t5 + _t38*_t5;
  const double _t41 = _hc1[1]*_t40;
  const double _t43 = _hc1[2]*_t42;
  const double _t44 = _t17 + _t41*_t5 + _t43*_t5;
  const double _t45 = _hc2[4]*_t19 + _hc2[5]*_t16;
  const double _t46 = _hc2[3]*_t19 + _hc2[4]*_t16;
  const double _t47 = _hc2[1]*_t44 + _hc2[2]*_t39 + _t16*_t45 + _t19*_t46;
  const double _t48 = my_piecewise3(_t6, 0, -_t20*_t33 + _t3*_t47 + _t32);
  const double _t49 = _hc2[4]*_t24 + _hc2[5]*_t27;
  const double _t50 = _hc2[3]*_t24 + _hc2[4]*_t27;
  const double _t51 = _hc1[2]*_t22;
  const double _t52 = _t12*_t51;
  const double _t53 = -_hc1[1]*_t11 + (0.1e1 / 0.2e1)*_t17 + (0.1e1 / 0.2e1)*_t23 + _t5*_t52;
  const double _t54 = _hc0[2]*_t13;
  const double _t55 = _t25*_t54;
  const double _t56 = _hc0[1]*_t11 + (0.1e1 / 0.2e1)*_t14 + (0.1e1 / 0.2e1)*_t26 + _t5*_t55;
  const double _t57 = _hc2[1]*_t53 + _hc2[2]*_t56 + _t16*_t49 + _t19*_t50;
  const double _t58 = my_piecewise3(_t6, 0, -_t20*_t8 - _t28*_t8 + _t3*_t57 + _t32);
  const double _t60 = _hc1[2]*_t59;
  const double _t63 = _hc1[1]*_t62;
  const double _t64 = _t23 + _t5*_t60 + _t5*_t63;
  const double _t65 = _hc0[1]*_t61;
  const double _t67 = _hc0[2]*_t66;
  const double _t68 = _t26 + _t5*_t65 + _t5*_t67;
  const double _t69 = _hc2[1]*_t64 + _hc2[2]*_t68 + _t24*_t50 + _t27*_t49;
  const double _t70 = my_piecewise3(_t6, 0, -_t28*_t33 + _t3*_t69 + _t32);
  const double d2F_dna2 = _t2*_t48 + 0.2e1*_t21;
  const double d2F_dna_dnb = _t2*_t58 + _t21 + _t29;
  const double d2F_dnb2 = _t2*_t70 + 0.2e1*_t29;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 1] += d2F_dna_dnb;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
#endif
#if _KMAX >= 3
  const double _t71 = (0.1e1 / (_t2 * _t2 * _t2 * _t2));
  const double _t72 = 0.6e1*_t71;
  const double _t77 = 0.6e1*_t30;
  const double _t78 = _t1*_t72;
  const double _t79 = -_t77 + _t78;
  const double _t80 = -_t79;
  const double _t82 = (_t13 * _t13 * _t13);
  const double _t85 = 0.4e1*_t8;
  const double _t86 = 0.4e1*_t30;
  const double _t87 = _t1*_t86;
  const double _t88 = -_t85 + _t87;
  const double _t91 = (_t12 * _t12 * _t12);
  const double _t93 = -_t88;
  const double _t105 = -_t31 + _t78;
  const double _t112 = -_t105;
  const double _t115 = -_t1*_t8;
  const double _t116 = _t10 + _t115;
  const double _t133 = _t1*_t30;
  const double _t141 = _t115 + _t3;
  const double _t149 = (_t22 * _t22 * _t22);
  const double _t151 = _t77 + _t78;
  const double _t153 = _t85 + _t87;
  const double _t154 = -_t153;
  const double _t157 = -_t151;
  const double _t159 = (_t25 * _t25 * _t25);
  const double _t73 = _hc2[0]*_t72;
  const double _t74 = _t47*_t8;
  const double _t75 = 0.2e1*_t39;
  const double _t76 = 0.2e1*_t44;
  const double _t81 = _hc0[1]*_t80;
  const double _t83 = _hc0[3]*_t82;
  const double _t84 = _t5*_t54;
  const double _t89 = _t35*_t84 + (0.3e1 / 0.2e1)*_t36 + (0.3e1 / 0.2e1)*_t38 + _t5*_t81 + _t5*_t83 + _t84*_t88;
  const double _t90 = _hc1[1]*_t79;
  const double _t92 = _hc1[3]*_t91;
  const double _t94 = _hc1[2]*_t12;
  const double _t95 = _t5*_t94;
  const double _t96 = _t40*_t95 + (0.3e1 / 0.2e1)*_t41 + (0.3e1 / 0.2e1)*_t43 + _t5*_t90 + _t5*_t92 + _t93*_t95;
  const double _t97 = _hc2[8]*_t19 + _hc2[9]*_t16;
  const double _t98 = _hc2[7]*_t19 + _hc2[8]*_t16;
  const double _t99 = _hc2[4]*_t44 + _hc2[5]*_t39 + _t16*_t97 + _t19*_t98;
  const double _t100 = _hc2[6]*_t19 + _hc2[7]*_t16;
  const double _t101 = _hc2[3]*_t44 + _hc2[4]*_t39 + _t100*_t19 + _t16*_t98;
  const double _t102 = _hc2[1]*_t96 + _hc2[2]*_t89 + _t101*_t19 + _t16*_t99 + _t45*_t75 + _t46*_t76;
  const double _t103 = my_piecewise3(_t6, 0, _t102*_t3 + 0.6e1*_t20*_t30 - _t73 - 0.3e1*_t74);
  const double _t104 = 0.2e1*_t58;
  const double _t106 = _hc1[1]*_t105;
  const double _t107 = 0.2e1*_t94;
  const double _t108 = _t40*_t51;
  const double _t109 = _hc1[3]*_t42;
  const double _t110 = _t109*_t22;
  const double _t111 = -_hc1[1]*_t34 + _t106*_t5 - _t107*_t11 + _t108*_t5 + _t110*_t5 + (0.1e1 / 0.2e1)*_t41 + (0.1e1 / 0.2e1)*_t43 + _t52;
  const double _t113 = _hc0[1]*_t112;
  const double _t114 = 0.2e1*_t54;
  const double _t117 = _hc0[3]*_t37;
  const double _t118 = _t116*_t117;
  const double _t119 = _hc0[2]*_t35;
  const double _t120 = _t119*_t25;
  const double _t121 = _hc0[1]*_t34 + _t11*_t114 + _t113*_t5 + _t118*_t5 + _t120*_t5 + (0.1e1 / 0.2e1)*_t36 + (0.1e1 / 0.2e1)*_t38 + _t55;
  const double _t122 = _hc2[8]*_t24 + _hc2[9]*_t27;
  const double _t123 = _hc2[7]*_t24 + _hc2[8]*_t27;
  const double _t124 = _hc2[4]*_t53 + _hc2[5]*_t56 + _t122*_t16 + _t123*_t19;
  const double _t125 = _hc2[6]*_t24 + _hc2[7]*_t27;
  const double _t126 = _hc2[3]*_t53 + _hc2[4]*_t56 + _t123*_t16 + _t125*_t19;
  const double _t127 = _hc2[1]*_t111 + _hc2[2]*_t121 + _t124*_t16 + _t126*_t19 + _t39*_t49 + _t44*_t50 + _t45*_t56 + _t46*_t53;
  const double _t128 = _t33*_t57 + _t73;
  const double _t129 = my_piecewise3(_t6, 0, _t127*_t3 - _t128 + 0.4e1*_t20*_t30 + 0.2e1*_t28*_t30 - _t74);
  const double _t130 = _t69*_t8;
  const double _t131 = 0.2e1*_t50;
  const double _t132 = 0.2e1*_t49;
  const double _t134 = 0.2e1*_t51;
  const double _t135 = _hc1[3]*_t59;
  const double _t136 = _t12*_t135;
  const double _t137 = _t62*_t94;
  const double _t138 = _hc1[1]*_t133 + _hc1[1]*_t8 - _t11*_t134 + _t136*_t5 + _t137*_t5 + _t52 + (0.1e1 / 0.2e1)*_t60 + (0.1e1 / 0.2e1)*_t63;
  const double _t139 = _hc0[2]*_t11;
  const double _t140 = _t54*_t61;
  const double _t142 = _hc0[3]*_t66;
  const double _t143 = _t141*_t142;
  const double _t144 = -_hc0[1]*_t133 - _hc0[1]*_t8 + 0.2e1*_t139*_t25 + _t140*_t5 + _t143*_t5 + _t55 + (0.1e1 / 0.2e1)*_t65 + (0.1e1 / 0.2e1)*_t67;
  const double _t145 = _hc2[4]*_t64 + _hc2[5]*_t68 + _t122*_t27 + _t123*_t24;
  const double _t146 = _hc2[3]*_t64 + _hc2[4]*_t68 + _t123*_t27 + _t125*_t24;
  const double _t147 = _hc2[1]*_t138 + _hc2[2]*_t144 + _t131*_t53 + _t132*_t56 + _t145*_t16 + _t146*_t19;
  const double _t148 = my_piecewise3(_t6, 0, -_t128 - _t130 + _t147*_t3 + 0.2e1*_t20*_t30 + 0.4e1*_t28*_t30);
  const double _t150 = _hc1[3]*_t149;
  const double _t152 = _hc1[1]*_t151;
  const double _t155 = _t5*_t51;
  const double _t156 = _t150*_t5 + _t152*_t5 + _t154*_t155 + _t155*_t62 + (0.3e1 / 0.2e1)*_t60 + (0.3e1 / 0.2e1)*_t63;
  const double _t158 = _hc0[1]*_t157;
  const double _t160 = _hc0[3]*_t159;
  const double _t161 = _hc0[2]*_t5;
  const double _t162 = _t161*_t25;
  const double _t163 = _t153*_t162 + _t158*_t5 + _t160*_t5 + _t162*_t61 + (0.3e1 / 0.2e1)*_t65 + (0.3e1 / 0.2e1)*_t67;
  const double _t164 = _hc2[1]*_t156 + _hc2[2]*_t163 + _t131*_t64 + _t132*_t68 + _t145*_t27 + _t146*_t24;
  const double _t165 = my_piecewise3(_t6, 0, -0.3e1*_t130 + _t164*_t3 + 0.6e1*_t28*_t30 - _t73);
  const double d3F_dna3 = _t103*_t2 + 0.3e1*_t48;
  const double d3F_dna2_dnb = _t104 + _t129*_t2 + _t48;
  const double d3F_dna_dnb2 = _t104 + _t148*_t2 + _t70;
  const double d3F_dnb3 = _t165*_t2 + 0.3e1*_t70;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 1] += d3F_dna2_dnb;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 2] += d3F_dna_dnb2;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
#endif
#if _KMAX >= 4
  const double _t166 = xc_powi(_t2, -5);
  const double _t167 = 0.24e2*_t166;
  const double _t169 = 0.24e2*_t71;
  const double _t170 = 0.12e2*_t30;
  const double _t171 = _t1*_t167;
  const double _t172 = -_t169 + _t171;
  const double _t175 = 0.12e2*_t71;
  const double _t176 = _t1*_t175;
  const double _t177 = -_t170 + _t176;
  const double _t179 = 0.6e1*_t8;
  const double _t180 = 0.6e1*na - 0.6e1*nb;
  const double _t182 = 0.4e1*na - 0.4e1*nb;
  const double _t183 = 0.2e1*na - 0.2e1*nb;
  const double _t184 = _t183*_t30 - _t33;
  const double _t189 = _t1*_t77;
  const double _t194 = _t171 - 0.12e2*_t71;
  const double _t196 = 0.3e1*_t11;
  const double _t198 = _t176 - _t86;
  const double _t209 = 0.18e2*_t71;
  const double _t210 = 0.3e1*_t8;
  const double _t214 = 0.4e1*(_t1 * _t1)*_t166;
  const double _t217 = 0.4e1*_t11;
  const double _t220 = _t183*_t30 + _t33;
  const double _t229 = 0.3e1*_t30;
  const double _t230 = 0.3e1*_t1*_t71;
  const double _t231 = 0.3e1*_t133;
  const double _t238 = _t169 + _t171;
  const double _t239 = _t170 + _t176;
  const double _t168 = _hc2[0]*_t167;
  const double _t173 = _hc0[1]*_t5;
  const double _t174 = _hc0[4]*_t5;
  const double _t178 = _t119*_t5;
  const double _t181 = _t117*_t5;
  const double _t185 = _hc1[1]*_t5;
  const double _t186 = _hc1[4]*_t5;
  const double _t187 = _hc1[2]*_t5;
  const double _t188 = _t187*_t40;
  const double _t190 = _t109*_t5;
  const double _t191 = _hc2[12]*_t19 + _hc2[13]*_t16;
  const double _t192 = _hc2[11]*_t19 + _hc2[12]*_t16;
  const double _t193 = _hc2[7]*_t44 + _hc2[8]*_t39 + _t16*_t191 + _t19*_t192;
  const double _t195 = _hc1[2]*_t11;
  const double _t197 = (0.1e1 / 0.2e1)*_t94;
  const double _t199 = _hc1[3]*_t12*_t22;
  const double _t200 = _t199*_t5;
  const double _t201 = (0.1e1 / 0.2e1)*_t54;
  const double _t202 = _hc0[3]*_t13*_t25;
  const double _t203 = _t202*_t5;
  const double _t204 = _hc2[13]*_t24 + _hc2[14]*_t27;
  const double _t205 = _hc2[12]*_t24 + _hc2[13]*_t27;
  const double _t206 = _hc2[11]*_t24 + _hc2[12]*_t27;
  const double _t207 = _hc2[7]*_t53 + _hc2[8]*_t56 + _t16*_t205 + _t19*_t206;
  const double _t208 = _hc2[10]*_t24 + _hc2[11]*_t27;
  const double _t211 = _t168 + _t57*_t77;
  const double _t212 = 0.2e1*_t53;
  const double _t213 = 0.2e1*_t56;
  const double _t215 = _t2*_t51;
  const double _t216 = _t135*_t5;
  const double _t218 = _hc0[2]*_t25;
  const double _t219 = _t2*_t218;
  const double _t221 = _t142*_t5;
  const double _t222 = _hc2[8]*_t64 + _hc2[9]*_t68 + _t204*_t27 + _t205*_t24;
  const double _t223 = _hc2[7]*_t64 + _hc2[8]*_t68 + _t205*_t27 + _t206*_t24;
  const double _t224 = _hc2[6]*_t64 + _hc2[7]*_t68 + _t206*_t27 + _t208*_t24;
  const double _t225 = 0.3e1*_t50;
  const double _t226 = 0.3e1*_t49;
  const double _t227 = 0.3e1*_t146;
  const double _t228 = 0.3e1*_t145;
  const double _t232 = (0.1e1 / 0.2e1)*_t51;
  const double _t233 = (0.1e1 / 0.2e1)*_t218;
  const double _t234 = 0.2e1*_t64;
  const double _t235 = 0.2e1*_t68;
  const double _t236 = _hc2[4]*_t156 + _hc2[5]*_t163 + _t122*_t235 + _t123*_t234 + _t222*_t27 + _t223*_t24;
  const double _t237 = _hc2[3]*_t156 + _hc2[4]*_t163 + _t123*_t235 + _t125*_t234 + _t223*_t27 + _t224*_t24;
  const double _t240 = 0.2e1*_t218;
  const double d4F_dna4 = 0.4e1*_t103 + _t2*my_piecewise3(_t6, 0, -_t102*_t85 + _t168 - _t169*_t20 + _t170*_t47 + _t3*(_hc2[1]*(_t107*_t40 + _t107*_t93 + (_t12 * _t12 * _t12 * _t12)*_t186 - _t172*_t185 + _t177*_t95 + _t187*(_t40 * _t40) + _t188*_t93 + _t190*_t40 + _t190*_t93 + _t190*(_t179 - _t189) + _t2*_t79*_t94 + 0.2e1*_t90 + 0.2e1*_t92) + _hc2[2]*(_t114*_t35 + _t114*_t88 + (_t13 * _t13 * _t13 * _t13)*_t174 + _t161*(_t35 * _t35) + _t172*_t173 - _t177*_t84 + _t178*_t88 + _t181*_t184 + _t181*(-_t179 + _t180*_t30) + _t181*(_t182*_t30 - _t85) + _t2*_t54*_t80 + 0.2e1*_t81 + 0.2e1*_t83) + 0.3e1*_t101*_t44 + _t16*(_hc2[4]*_t96 + _hc2[5]*_t89 + _t16*(_hc2[8]*_t44 + _hc2[9]*_t39 + _t16*(_hc2[13]*_t19 + _hc2[14]*_t16) + _t19*_t191) + _t19*_t193 + _t75*_t97 + _t76*_t98) + _t19*(_hc2[3]*_t96 + _hc2[4]*_t89 + _t100*_t76 + _t16*_t193 + _t19*(_hc2[6]*_t44 + _hc2[7]*_t39 + _t16*_t192 + _t19*(_hc2[10]*_t19 + _hc2[11]*_t16)) + _t75*_t98) + 0.3e1*_t39*_t99 + 0.3e1*_t45*_t89 + 0.3e1*_t46*_t96));
  const double d4F_dna3_dnb = _t103 + 0.3e1*_t129 + _t2*my_piecewise3(_t6, 0, -_t102*_t8 - _t127*_t210 - _t20*_t209 + _t211 - _t28*_t72 + _t3*(_hc2[1]*(_t105*_t95 + (0.3e1 / 0.2e1)*_t106 + (0.3e1 / 0.2e1)*_t108 - _t109*_t196 + (0.3e1 / 0.2e1)*_t110 + _t155*_t79 - _t185*_t194 + _t186*_t22*_t91 - _t189*_t94 - _t195*_t40 - _t195*_t93 + _t197*_t40 + _t197*_t93 + _t198*_t95 + _t200*_t40 + _t200*_t93 + (0.1e1 / 0.2e1)*_t90 + (0.1e1 / 0.2e1)*_t92) + _hc2[2]*(_t11*_t119 + _t112*_t84 + (0.3e1 / 0.2e1)*_t113 + _t116*_t174*_t82 + _t117*_t196 + (0.3e1 / 0.2e1)*_t118 + (0.3e1 / 0.2e1)*_t120 + _t139*_t88 + _t162*_t80 + _t173*_t194 + _t189*_t54 - _t198*_t84 + _t201*_t35 + _t201*_t88 + _t203*_t35 + _t203*_t88 + (0.1e1 / 0.2e1)*_t81 + (0.1e1 / 0.2e1)*_t83) + _t101*_t53 + 0.2e1*_t111*_t46 + 0.2e1*_t121*_t45 + _t124*_t75 + _t126*_t76 + _t16*(_hc2[4]*_t111 + _hc2[5]*_t121 + _t122*_t39 + _t123*_t44 + _t16*(_hc2[8]*_t53 + _hc2[9]*_t56 + _t16*_t204 + _t19*_t205) + _t19*_t207 + _t53*_t98 + _t56*_t97) + _t19*(_hc2[3]*_t111 + _hc2[4]*_t121 + _t100*_t53 + _t123*_t39 + _t125*_t44 + _t16*_t207 + _t19*(_hc2[6]*_t53 + _hc2[7]*_t56 + _t16*_t206 + _t19*_t208) + _t56*_t98) + _t49*_t89 + _t50*_t96 + _t56*_t99) + _t47*_t77);
  const double d4F_dna2_dnb2 = 0.2e1*_t129 + 0.2e1*_t148 + _t2*my_piecewise3(_t6, 0, -_t127*_t33 - _t147*_t33 + _t168 - _t175*_t20 - _t175*_t28 + _t3*(_hc2[1]*(_hc1[1]*_t31 - _hc1[1]*_t78 + _hc1[2]*_t214 + _t105*_t215 + _t106 + _t108 + _t110 + _t136 + _t137 + _t186*_t42*_t59 + _t188*_t62 + _t190*_t62 - _t199*_t217 + _t216*_t40 + _t33*_t94 + _t34*_t94 - _t51*_t87) + _hc2[2]*(-_hc0[1]*_t31 + _hc0[1]*_t78 + _hc0[2]*_t214 + _t112*_t219 + _t113 + _t118 + _t120 + _t140 + _t143 + _t174*_t37*_t66 + _t178*_t61 + _t181*_t220 + _t184*_t221 + _t202*_t217 + _t218*_t87 - _t33*_t54 - _t34*_t54) + _t111*_t131 + _t121*_t132 + _t124*_t213 + _t126*_t212 + _t138*_t46 + _t144*_t45 + _t145*_t39 + _t146*_t44 + _t16*(_hc2[4]*_t138 + _hc2[5]*_t144 + _t122*_t213 + _t123*_t212 + _t16*_t222 + _t19*_t223) + _t19*(_hc2[3]*_t138 + _hc2[4]*_t144 + _t123*_t213 + _t125*_t212 + _t16*_t223 + _t19*_t224)) + 0.8e1*_t30*_t57 + _t31*_t47 + _t31*_t69);
  const double d4F_dna_dnb3 = 0.3e1*_t148 + _t165 + _t2*my_piecewise3(_t6, 0, -_t147*_t210 - _t164*_t8 - _t20*_t72 - _t209*_t28 + _t211 + _t3*(_hc2[1]*(-_hc1[1]*_t229 - _hc1[1]*_t230 + _t12*_t149*_t186 - _t135*_t196 + (0.3e1 / 0.2e1)*_t136 + (0.3e1 / 0.2e1)*_t137 + (0.1e1 / 0.2e1)*_t150 + _t151*_t95 + (0.1e1 / 0.2e1)*_t152 + _t154*_t200 + _t154*_t232 - 0.3e1*_t195*_t62 + _t200*_t62 + _t210*_t51 + _t231*_t51 + _t232*_t62) + _hc2[2]*(_hc0[1]*_t229 + _hc0[1]*_t230 + 0.3e1*_t139*_t61 + (0.3e1 / 0.2e1)*_t140 + _t141*_t159*_t174 + _t142*_t196 + (0.3e1 / 0.2e1)*_t143 + _t153*_t203 + _t153*_t233 + _t157*_t84 + (0.1e1 / 0.2e1)*_t158 + (0.1e1 / 0.2e1)*_t160 + _t203*_t61 - _t210*_t218 - _t218*_t231 + _t233*_t61) + _t138*_t225 + _t144*_t226 + _t16*_t236 + _t19*_t237 + _t227*_t53 + _t228*_t56) + _t69*_t77);
  const double d4F_dnb4 = 0.4e1*_t165 + _t2*my_piecewise3(_t6, 0, -_t164*_t85 + _t168 - _t169*_t28 + _t170*_t69 + _t3*(_hc2[1]*(_t134*_t154 + _t134*_t62 + 0.2e1*_t150 + _t151*_t215 + 0.2e1*_t152 + _t154*_t187*_t62 + _t154*_t216 + _t155*_t239 - _t185*_t238 + _t186*(_t22 * _t22 * _t22 * _t22) + _t187*(_t62 * _t62) + _t216*_t62 + _t216*(-_t179 - _t189)) + _hc2[2]*(_t153*_t161*_t61 + _t153*_t240 + _t157*_t219 + 0.2e1*_t158 + 0.2e1*_t160 + _t161*(_t61 * _t61) - _t162*_t239 + _t173*_t238 + _t174*(_t25 * _t25 * _t25 * _t25) + _t220*_t221 + _t221*(_t179 + _t180*_t30) + _t221*(_t182*_t30 + _t85) + _t240*_t61) + _t156*_t225 + _t163*_t226 + _t227*_t64 + _t228*_t68 + _t236*_t27 + _t237*_t24));
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 1] += d4F_dna3_dnb;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 2] += d4F_dna2_dnb2;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 3] += d4F_dna_dnb3;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
#endif
#endif
}
#endif