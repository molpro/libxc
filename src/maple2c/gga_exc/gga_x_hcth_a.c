/*
  Generated from python/gga_exc/gga_x_hcth_a.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py gga_x_hcth_a
*/

#ifndef _GGA_X_HCTH_A_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _GGA_X_HCTH_A_KERNEL_BODY
#define _KMAX 0
#define _GGA_X_HCTH_A_HELPER_BODIES
#include "gga_x_hcth_a.c"
#undef _GGA_X_HCTH_A_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _GGA_X_HCTH_A_HELPER_BODIES
#include "gga_x_hcth_a.c"
#undef _GGA_X_HCTH_A_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _GGA_X_HCTH_A_HELPER_BODIES
#include "gga_x_hcth_a.c"
#undef _GGA_X_HCTH_A_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _GGA_X_HCTH_A_HELPER_BODIES
#include "gga_x_hcth_a.c"
#undef _GGA_X_HCTH_A_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _GGA_X_HCTH_A_HELPER_BODIES
#include "gga_x_hcth_a.c"
#undef _GGA_X_HCTH_A_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "gga_x_hcth_a.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_GGA_X_HCTH_A_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(hcth_b88x_k, _KMAX)(const xc_func_type *p, double beta, double x, double *out) {
  const gga_x_hcth_a_params *params = (const gga_x_hcth_a_params *)(p->params);

  const double _t1 = (x * x);
  const double _t2 = xc_asinh(x);
  const double _t3 = beta*params->gamma;
  const double _t4 = _t2*_t3;
  const double _t5 = _t4*x;
  const double _t6 = _t5 + 0.1e1;
  const double _t7 = (0.1e1 / _t6);
  const double _t8 = 0.2e1*_t7*beta;
  const double _t9 = _t1 + 0.1e1;
  const double _t10 = xc_powr(_t9, -1, 2);
  const double _t11 = _t10*_t3;
  const double _t12 = _t11*x;
  const double _t13 = -_t12 - _t4;
  const double _t14 = (0.1e1 / (_t6 * _t6));
  const double _t15 = _t1*_t14;
  const double _t16 = (x * x * x);
  const double _t17 = _t14*_t16;
#if _KMAX >= 1
  const double _t18 = _t13*_t14;
  const double _t19 = 0.2e1*_t11;
  const double _t20 = xc_powr(_t9, -3, 2);
  const double _t21 = _t20*_t3;
  const double _t22 = _t1*_t21;
  const double _t23 = -_t19 + _t22;
  const double _t24 = (0.1e1 / (_t6 * _t6 * _t6));
  const double _t25 = _t13*_t24;
  const double _t26 = 0.2e1*_t4;
  const double _t27 = -0.2e1*_t12 - _t26;
  const double _t28 = _t1*_t27;
  const double _t29 = 0.3e1*_t4;
  const double _t30 = _t24*_t27;
  const double _t31 = _t16*_t4;
  const double _t32 = _t2*params->gamma;
  const double _t33 = _t14*_t32;
  const double _t34 = 0.2e1*_t16;
  const double _t35 = ((params->gamma) * (params->gamma));
  const double _t36 = (_t2 * _t2);
  const double _t37 = _t35*_t36;
  const double _t38 = _t24*_t37;
  const double _t39 = _t38*beta;
  const double _t40 = (x * x * x * x);
  const double _t41 = 0.2e1*_t40;
#endif
#if _KMAX >= 2
  const double _t42 = _t14*_t23;
  const double _t43 = 0.6e1*x;
  const double _t44 = xc_powr(_t9, -5, 2);
  const double _t45 = _t3*_t44;
  const double _t46 = 0.3e1*_t16;
  const double _t47 = 0.4e1*_t20*beta*params->gamma*x - _t45*_t46;
  const double _t48 = _t25*_t27;
  const double _t49 = _t23*_t24;
  const double _t50 = 0.2e1*_t28;
  const double _t51 = 0.4e1*_t11;
  const double _t52 = 0.2e1*_t22 - _t51;
  const double _t53 = _t1*_t25;
  const double _t54 = (0.1e1 / (_t6 * _t6 * _t6 * _t6));
  const double _t55 = -0.3e1*_t12 - _t29;
  const double _t56 = _t54*_t55;
  const double _t57 = _t13*_t28;
  const double _t58 = 0.6e1*_t14;
  const double _t59 = 0.6e1*_t11;
  const double _t60 = 0.6e1*_t24;
  const double _t61 = _t28*_t4;
  const double _t62 = _t24*_t31;
  const double _t63 = _t27*_t31;
  const double _t64 = _t10*params->gamma;
  const double _t65 = 0.8e1*beta;
  const double _t66 = _t10*_t40;
  const double _t67 = _t24*_t35;
  const double _t68 = 0.4e1*beta;
  const double _t69 = _t67*_t68;
  const double _t70 = _t2*_t69;
  const double _t71 = _t32*_t34;
  const double _t72 = _t37*_t56;
  const double _t73 = _t72*beta;
  const double _t74 = _t54*beta;
  const double _t75 = xc_powi(x, 5);
  const double _t76 = ((params->gamma) * (params->gamma) * (params->gamma));
  const double _t77 = (_t2 * _t2 * _t2);
  const double _t78 = _t76*_t77;
  const double _t79 = _t75*_t78;
  const double _t80 = 0.6e1*_t79;
#endif
#if _KMAX >= 3
  const double _t81 = _t14*_t47;
  const double _t82 = 0.8e1*x;
  const double _t83 = _t1*_t45;
  const double _t84 = xc_powr(_t9, -7, 2);
  const double _t85 = _t3*_t40*_t84;
  const double _t86 = 0.4e1*_t21 - 0.21e2*_t83 + 0.15e2*_t85;
  const double _t87 = _t27*_t49*beta;
  const double _t88 = _t25*_t52;
  const double _t89 = _t16*_t45;
  const double _t90 = 0.8e1*_t20*beta*params->gamma*x - 0.6e1*_t89;
  const double _t91 = _t24*_t28;
  const double _t92 = _t1*_t49;
  const double _t93 = 0.3e1*_t52;
  const double _t94 = _t13*_t56;
  const double _t95 = _t27*_t94;
  const double _t96 = _t23*_t28;
  const double _t97 = 0.3e1*_t22 - _t59;
  const double _t98 = _t54*_t57;
  const double _t99 = _t1*_t52;
  const double _t100 = xc_powi(_t6, -5);
  const double _t101 = -0.4e1*_t12 - 0.4e1*_t4;
  const double _t102 = _t100*_t101;
  const double _t103 = _t55*_t57;
  const double _t104 = _t45*_t75;
  const double _t105 = _t24*_t52;
  const double _t106 = _t1*_t105;
  const double _t107 = _t11*_t46;
  const double _t108 = _t27*_t56;
  const double _t109 = _t54*_t63;
  const double _t110 = _t16*_t52;
  const double _t111 = _t110*_t56;
  const double _t112 = _t102*_t55;
  const double _t113 = 0.12e2*_t33;
  const double _t114 = _t14*_t40;
  const double _t115 = _t20*params->gamma;
  const double _t116 = _t1*_t38;
  const double _t117 = 0.24e2*beta;
  const double _t118 = (0.1e1 / _t9);
  const double _t119 = _t118*_t40;
  const double _t120 = _t67*beta;
  const double _t121 = _t10*_t2;
  const double _t122 = _t121*_t16;
  const double _t123 = _t20*_t75;
  const double _t124 = _t16*_t64;
  const double _t125 = _t121*_t35*_t40*_t56;
  const double _t126 = 0.2e1*_t37;
  const double _t127 = _t40*_t54;
  const double _t128 = _t127*_t97;
  const double _t129 = _t128*beta;
  const double _t130 = _t102*beta;
  const double _t131 = _t130*_t55;
  const double _t132 = _t37*_t41;
  const double _t133 = _t127*_t78;
  const double _t134 = 0.30e2*beta;
  const double _t135 = _t75*_t76;
  const double _t136 = _t10*_t36;
  const double _t137 = _t135*_t136;
  const double _t138 = 0.18e2*_t74;
  const double _t139 = 0.24e2*_t54;
  const double _t140 = xc_powi(x, 6);
  const double _t141 = ((params->gamma) * (params->gamma) * (params->gamma) * (params->gamma));
  const double _t142 = (_t2 * _t2 * _t2 * _t2);
  const double _t143 = _t100*_t141*_t142;
#endif
#if _KMAX >= 4
  const double _t144 = 0.20e2*beta;
  const double _t145 = _t14*x;
  const double _t146 = _t86*beta;
  const double _t147 = _t134*x;
  const double _t148 = _t90*beta;
  const double _t149 = 0.10e2*x;
  const double _t150 = _t47*beta;
  const double _t151 = 0.8e1*_t21 - 0.42e2*_t83 + 0.30e2*_t85;
  const double _t152 = _t74*_t97;
  const double _t153 = _t13*_t152;
  const double _t154 = _t149*_t27;
  const double _t155 = 0.12e2*_t20*beta*params->gamma*x - 0.9e1*_t89;
  const double _t156 = _t155*beta;
  const double _t157 = _t28*_t56;
  const double _t158 = _t56*_t99;
  const double _t159 = _t1*_t93;
  const double _t160 = _t13*_t131;
  const double _t161 = 0.8e1*_t11;
  const double _t162 = -_t161 + 0.4e1*_t22;
  const double _t163 = _t100*beta;
  const double _t164 = _t162*_t163;
  const double _t165 = -0.5e1*_t12 - 0.5e1*_t4;
  const double _t166 = xc_powi(_t6, -6);
  const double _t167 = _t166*beta;
  const double _t168 = _t101*_t165*_t167;
  const double _t169 = 0.24e2*_t4;
  const double _t170 = 0.36e2*_t5;
  const double _t171 = _t24*_t90;
  const double _t172 = 0.36e2*_t11;
  const double _t173 = _t16*_t51;
  const double _t174 = _t54*_t97;
  const double _t175 = 0.12e2*_t61;
  const double _t176 = _t173*_t27;
  const double _t177 = _t110*_t29;
  const double _t178 = _t55*_t63;
  const double _t179 = _t165*_t166;
  const double _t180 = 0.36e2*_t64;
  const double _t181 = 0.48e2*_t16;
  const double _t182 = 0.12e2*_t67;
  const double _t183 = _t75*beta;
  const double _t184 = _t2*_t20;
  const double _t185 = _t182*_t2;
  const double _t186 = 0.18e2*_t32;
  const double _t187 = 0.12e2*_t35;
  const double _t188 = _t187*_t56;
  const double _t189 = 0.96e2*_t122;
  const double _t190 = _t37*_t97;
  const double _t191 = _t27*_t71;
  const double _t192 = _t132*_t55;
  const double _t193 = _t136*_t76;
  const double _t194 = 0.6e1*_t37;
  const double _t195 = _t140*_t141;
#endif

  const double f = _t1*_t7*beta;
  out[0] = f;
  const double df_dx = _t13*_t15*beta + _t8*x;
  out[1] = df_dx;
  const double df_dbeta = _t1*_t7 - _t17*_t4;
  out[2] = df_dbeta;
#if _KMAX >= 1
  const double d2f_dx2 = _t15*_t23*beta + 0.4e1*_t18*beta*x + _t25*_t28*beta + _t8;
  out[3] = d2f_dx2;
  const double d2f_dbeta_dx = _t1*_t13*_t14 - _t11*_t17 - _t15*_t29 - _t30*_t31 + 0.2e1*_t7*x;
  out[4] = d2f_dbeta_dx;
  const double d2f_dbeta2 = -_t33*_t34 + _t39*_t41;
  out[5] = d2f_dbeta2;
#endif
#if _KMAX >= 2
  const double d3f_dx3 = _t15*_t47*beta + 0.6e1*_t18*beta + _t42*_t43*beta + _t43*_t48*beta + _t49*_t50*beta + _t52*_t53*beta + _t56*_t57*beta;
  out[6] = d3f_dx3;
  const double d3f_dbeta_dx2 = _t1*_t13*_t24*_t27 + _t1*_t14*_t23 + 0.4e1*_t13*_t14*x + _t14*_t20*_t40*beta*params->gamma - _t15*_t59 - _t16*_t19*_t30 - _t5*_t58 - _t52*_t62 - _t56*_t63 - _t60*_t61 + 0.2e1*_t7;
  out[7] = d3f_dbeta_dx2;
  const double d3f_dbeta2_dx = -0.6e1*_t15*_t32 + _t16*_t38*_t65 - 0.2e1*_t17*_t64 - _t30*_t71 + _t41*_t73 + _t66*_t70;
  out[8] = d3f_dbeta2_dx;
  const double d3f_dbeta3 = 0.6e1*_t24*_t35*_t36*_t40 - _t74*_t80;
  out[9] = d3f_dbeta3;
#endif
#if _KMAX >= 3
  const double d4f_dx4 = _t102*_t103*beta + _t15*_t86*beta + 0.12e2*_t42*beta + 0.3e1*_t47*_t91*beta + 0.12e2*_t48*beta + _t53*_t90*beta + 0.3e1*_t56*_t96*beta + _t81*_t82*beta + _t82*_t88*beta + _t82*_t95*beta + 0.16e2*_t87*x + _t92*_t93*beta + 0.2e1*_t94*_t99*beta + _t97*_t98*beta;
  out[10] = d4f_dx4;
  const double d4f_dbeta_dx3 = _t1*_t13*_t24*_t52 + _t1*_t13*_t27*_t54*_t55 + _t1*_t14*_t47 + 0.2e1*_t1*_t23*_t24*_t27 - 0.3e1*_t104*_t14 - _t105*_t107 - 0.9e1*_t106*_t4 - _t107*_t108 - _t109*_t97 - 0.18e2*_t11*_t91 - _t111*_t26 - _t112*_t63 - 0.18e2*_t12*_t14 + 0.6e1*_t13*_t14 + 0.6e1*_t13*_t24*_t27*x + 0.10e2*_t14*_t16*_t20*beta*params->gamma + 0.6e1*_t14*_t23*x + 0.3e1*_t20*_t24*_t27*_t40*beta*params->gamma - 0.18e2*_t30*_t5 - _t4*_t58 - 0.9e1*_t56*_t61 - _t62*_t90;
  out[11] = d4f_dbeta_dx3;
  const double d4f_dbeta2_dx2 = -_t105*_t71 - _t108*_t71 - _t113*x + 0.2e1*_t114*_t115 + _t116*_t117 + _t119*_t69 + 0.32e2*_t120*_t122 - _t123*_t70 - 0.4e1*_t124*_t30 + _t125*_t65 + _t126*_t129 + _t131*_t132 - 0.12e2*_t15*_t64 + 0.16e2*_t16*_t73 - 0.12e2*_t32*_t91;
  out[12] = d4f_dbeta2_dx2;
  const double d4f_dbeta3_dx = 0.12e2*_t10*_t2*_t24*_t35*_t40 - _t130*_t80 - _t133*_t134 - _t137*_t138 + 0.24e2*_t16*_t24*_t35*_t36 + 0.6e1*_t35*_t36*_t40*_t54*_t55;
  out[13] = d4f_dbeta3_dx;
  const double d4f_dbeta4 = _t117*_t140*_t143 - _t139*_t79;
  out[14] = d4f_dbeta4;
#endif
#if _KMAX >= 4
  const double d5f_dx5 = 0.3e1*_t1*_t148*_t94 + _t103*_t164 + _t103*_t168 + _t108*_t147*_t23 + _t112*_t68*_t96 + _t13*_t130*_t50*_t97 + _t144*_t52*_t94*x + _t144*_t81 + _t144*_t88 + _t144*_t95 + 0.10e2*_t145*_t146 + 0.4e1*_t146*_t91 + _t147*_t30*_t47 + _t147*_t49*_t52 + _t148*_t149*_t25 + _t15*beta*(0.165e3*_t16*_t84*beta*params->gamma - 0.105e3*_t3*_t75/xc_powr(_t9, 9, 2) - 0.54e2*_t45*x) + 0.6e1*_t150*_t157 + _t150*_t60*_t99 + _t151*_t53*beta + 0.4e1*_t152*_t96 + _t153*_t154 + _t153*_t159 + _t154*_t160 + _t156*_t98 + _t158*_t23*_t65 + _t159*_t160 + _t68*_t90*_t92 + 0.40e2*_t87;
  out[15] = d5f_dx5;
  const double d5f_dbeta_dx4 = _t1*_t100*_t101*_t13*_t27*_t55 + _t1*_t13*_t24*_t90 + _t1*_t13*_t27*_t54*_t97 + 0.2e1*_t1*_t13*_t52*_t54*_t55 + 0.48e2*_t1*_t14*_t20*beta*params->gamma + _t1*_t14*_t86 - 0.12e2*_t1*_t171*_t4 + 0.3e1*_t1*_t23*_t24*_t52 + 0.3e1*_t1*_t23*_t27*_t54*_t55 + 0.3e1*_t1*_t24*_t27*_t47 - _t100*_t162*_t178 - _t101*_t178*_t179 - _t102*_t16*_t26*_t27*_t97 - 0.12e2*_t104*_t30 - _t105*_t170 - _t106*_t172 - _t108*_t170 - _t109*_t155 - 0.24e2*_t11*_t14 - _t111*_t161 - _t112*_t175 - _t112*_t176 - _t112*_t177 - 0.45e2*_t114*_t45 - 0.72e2*_t12*_t30 + 0.12e2*_t13*_t24*_t27 + 0.8e1*_t13*_t24*_t52*x + 0.8e1*_t13*_t27*_t54*_t55*x + 0.15e2*_t14*_t140*_t84*beta*params->gamma + 0.12e2*_t14*_t23 + 0.8e1*_t14*_t47*x - _t151*_t62 - _t157*_t172 - _t158*_t169 + 0.40e2*_t16*_t20*_t24*_t27*beta*params->gamma - _t16*_t29*_t56*_t90 - _t169*_t30 - _t171*_t173 - _t174*_t175 - _t174*_t176 - _t174*_t177 + 0.6e1*_t20*_t24*_t40*_t52*beta*params->gamma + 0.6e1*_t20*_t27*_t40*_t54*_t55*beta*params->gamma + 0.16e2*_t23*_t24*_t27*x;
  out[16] = d5f_dbeta_dx4;
  const double d5f_dbeta2_dx3 = 0.144e3*_t1*_t120*_t121 + 0.72e2*_t1*_t73 + _t102*_t190*_t40*_t68 - _t106*_t186 - 0.6e1*_t108*_t124 - 0.4e1*_t111*_t32 + _t112*_t117*_t16*_t37 - _t112*_t191 - _t113 + 0.20e2*_t115*_t17 + _t115*_t27*_t40*_t60 + _t118*_t120*_t181 + _t119*_t188*beta - 0.52e2*_t120*_t184*_t40 + _t121*_t129*_t187 - _t124*_t52*_t60 + _t126*_t127*_t156 + _t131*_t187*_t2*_t66 + _t139*_t16*_t190*beta + _t140*_t185*_t44*beta - _t145*_t180 - _t157*_t186 + _t164*_t192 + _t168*_t192 - _t171*_t71 - _t174*_t191 - _t180*_t91 - _t182*_t183/(_t9 * _t9) - _t183*_t184*_t188 + _t189*_t35*_t56*beta - 0.36e2*_t30*_t32*x + 0.48e2*_t39*x - _t44*_t58*_t75*params->gamma;
  out[17] = d5f_dbeta2_dx3;
  const double d5f_dbeta3_dx2 = -0.36e2*_t102*_t183*_t193 + _t112*_t194*_t40 + 0.72e2*_t116 - 0.36e2*_t118*_t135*_t2*_t74 + _t119*_t182 - _t123*_t185 + 0.24e2*_t125 - 0.180e3*_t127*_t193*beta + _t128*_t194 - 0.60e2*_t130*_t40*_t78 + _t138*_t140*_t20*_t36*_t76 - 0.120e3*_t16*_t74*_t78 - _t164*_t80 - _t168*_t80 + _t181*_t72 + _t189*_t67;
  out[18] = d5f_dbeta3_dx2;
  const double d5f_dbeta4_dx = 0.96e2*_t10*_t163*_t195*_t77 - 0.24e2*_t102*_t79 + _t117*_t142*_t179*_t195 - 0.120e3*_t133 - 0.72e2*_t137*_t54 + 0.144e3*_t143*_t183;
  out[19] = d5f_dbeta4_dx;
  const double d5f_dbeta5 = 0.120e3*_t100*_t140*_t141*_t142 - 0.120e3*_t167*xc_powi(_t2, 5)*xc_powi((params->gamma), 5)*xc_powi(x, 7);
  out[20] = d5f_dbeta5;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(hcth_a_f_k, _KMAX)(const xc_func_type *p, double x, double *out) {
  const gga_x_hcth_a_params *params = (const gga_x_hcth_a_params *)(p->params);

  double _hc0[(_KMAX) >= 4 ? 21 : (_KMAX) >= 3 ? 15 : (_KMAX) >= 2 ? 10 : (_KMAX) >= 1 ? 6 : 3];
  XC_CAT(hcth_b88x_k, _KMAX)(p, params->beta, x, _hc0);
  const double _t1 = (0.2e1 / 0.3e1)*xc_powr(0.2e1, 2, 3)*M_CBRTPI/M_CBRT3;
  const double _t2 = _t1*params->c1;
  const double _t3 = _t1*params->c2;

  const double f = -_hc0[0]*_t2 - _hc0[2]*_t3 + params->c0;
  out[0] = f;
#if _KMAX >= 1
  const double df_dx = -_hc0[1]*_t2 - _hc0[4]*_t3;
  out[1] = df_dx;
#endif
#if _KMAX >= 2
  const double d2f_dx2 = -_hc0[3]*_t2 - _hc0[7]*_t3;
  out[2] = d2f_dx2;
#endif
#if _KMAX >= 3
  const double d3f_dx3 = -_hc0[11]*_t3 - _hc0[6]*_t2;
  out[3] = d3f_dx3;
#endif
#if _KMAX >= 4
  const double d4f_dx4 = -_hc0[10]*_t2 - _hc0[16]*_t3;
  out[4] = d4f_dx4;
#endif
}

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double *out) {
  const gga_x_hcth_a_params *params = (const gga_x_hcth_a_params *)(p->params);

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
  if(!(_t6)) XC_CAT(hcth_a_f_k, _KMAX)(p, _t1*_t2, _hc0);
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
  assert(p->params != NULL);
  const gga_x_hcth_a_params *params = (const gga_x_hcth_a_params *)(p->params);
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