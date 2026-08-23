/*
  Generated from python/mgga_exc/hyb_mgga_x_m05.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py hyb_mgga_x_m05
*/

#ifndef _HYB_MGGA_X_M05_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _HYB_MGGA_X_M05_KERNEL_BODY
#define _KMAX 0
#define _HYB_MGGA_X_M05_HELPER_BODIES
#include "hyb_mgga_x_m05.c"
#undef _HYB_MGGA_X_M05_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _HYB_MGGA_X_M05_HELPER_BODIES
#include "hyb_mgga_x_m05.c"
#undef _HYB_MGGA_X_M05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _HYB_MGGA_X_M05_HELPER_BODIES
#include "hyb_mgga_x_m05.c"
#undef _HYB_MGGA_X_M05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _HYB_MGGA_X_M05_HELPER_BODIES
#include "hyb_mgga_x_m05.c"
#undef _HYB_MGGA_X_M05_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _HYB_MGGA_X_M05_HELPER_BODIES
#include "hyb_mgga_x_m05.c"
#undef _HYB_MGGA_X_M05_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "hyb_mgga_x_m05.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_HYB_MGGA_X_M05_HELPER_BODIES)

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

GPU_DEVICE_FUNCTION static inline void XC_CAT(xchan_k, _KMAX)(const xc_func_type *p, double n_s, double sigma_ss, double lapl_s, double tau_s, double *out) {
  const mgga_x_m05_params *params = (const mgga_x_m05_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = _t1/M_CBRTPI;
  const double _t3 = (0.1e1 / 0.2e1)*_t2;
  const double _t4 = -p->dens_threshold + n_s <= 0;
  const double _t5 = xc_powr(n_s, -5, 3);
  const double _t6 = _t5*tau_s;
  const double _t7 = xc_powr(0.6e1, 2, 3);
  const double _t8 = (M_PI * M_CBRTPI);
  const double _t9 = (0.3e1 / 0.10e2)*_t7*_t8;
  const double _t10 = -_t6 + _t9;
  const double _t11 = _t6 + _t9;
  const double _t12 = (0.1e1 / _t11);
  const double _t13 = _t12*params->a[1];
  const double _t14 = xc_powi(_t11, -10);
  const double _t15 = xc_powi(_t10, 10);
  const double _t16 = _t15*params->a[10];
  const double _t17 = xc_powi(_t11, -11);
  const double _t18 = xc_powi(_t10, 11);
  const double _t19 = _t18*params->a[11];
  const double _t20 = (_t10 * _t10);
  const double _t21 = (0.1e1 / (_t11 * _t11));
  const double _t22 = _t21*params->a[2];
  const double _t23 = (_t10 * _t10 * _t10);
  const double _t24 = (0.1e1 / (_t11 * _t11 * _t11));
  const double _t25 = _t24*params->a[3];
  const double _t26 = (_t10 * _t10 * _t10 * _t10);
  const double _t27 = (0.1e1 / (_t11 * _t11 * _t11 * _t11));
  const double _t28 = _t27*params->a[4];
  const double _t29 = xc_powi(_t11, -5);
  const double _t30 = xc_powi(_t10, 5);
  const double _t31 = _t30*params->a[5];
  const double _t32 = xc_powi(_t11, -6);
  const double _t33 = xc_powi(_t10, 6);
  const double _t34 = _t33*params->a[6];
  const double _t35 = xc_powi(_t11, -7);
  const double _t36 = xc_powi(_t10, 7);
  const double _t37 = _t36*params->a[7];
  const double _t38 = xc_powi(_t11, -8);
  const double _t39 = xc_powi(_t10, 8);
  const double _t40 = _t39*params->a[8];
  const double _t41 = xc_powi(_t11, -9);
  const double _t42 = xc_powi(_t10, 9);
  const double _t43 = _t42*params->a[9];
  const double _t44 = _t10*_t13 + _t14*_t16 + _t17*_t19 + _t20*_t22 + _t23*_t25 + _t26*_t28 + _t29*_t31 + _t32*_t34 + _t35*_t37 + _t38*_t40 + _t41*_t43 + params->a[0];
  const double _t45 = xc_powr(n_s, -8, 3);
  const double _t46 = _t1/_t8;
  const double _t47 = _t45*_t46;
  const double _t48 = _t47*sigma_ss;
  const double _t49 = 0.009146457198521546*_t48 + 0.80400000000000005;
  const double _t50 = (0.1e1 / _t49);
  const double _t51 = 0.0073537515876113235*_t50;
  const double _t52 = _t48*_t51 + 0.1e1;
#if _KMAX >= 1
  const double _t56 = _t21*params->a[1];
  const double _t57 = _t10*_t5;
  const double _t58 = 0.10e2*_t5;
  const double _t59 = _t14*params->a[10];
  const double _t60 = _t42*_t59;
  const double _t61 = _t16*_t17;
  const double _t62 = 0.11e2*_t5;
  const double _t63 = _t17*params->a[11];
  const double _t64 = _t15*_t63;
  const double _t65 = xc_powi(_t11, -12);
  const double _t66 = _t19*_t65;
  const double _t67 = _t24*params->a[2];
  const double _t68 = _t20*_t67;
  const double _t69 = 0.3e1*_t5;
  const double _t70 = _t20*_t25;
  const double _t71 = _t27*params->a[3];
  const double _t72 = _t23*_t71;
  const double _t73 = 0.4e1*_t5;
  const double _t74 = _t23*_t28;
  const double _t75 = _t26*_t29;
  const double _t76 = _t75*params->a[4];
  const double _t77 = 0.5e1*_t5;
  const double _t78 = _t75*params->a[5];
  const double _t79 = _t31*_t32;
  const double _t80 = 0.6e1*_t5;
  const double _t81 = _t32*params->a[6];
  const double _t82 = _t30*_t81;
  const double _t83 = _t34*_t35;
  const double _t84 = 0.7e1*_t5;
  const double _t85 = _t35*params->a[7];
  const double _t86 = _t33*_t85;
  const double _t87 = _t37*_t38;
  const double _t88 = 0.8e1*_t5;
  const double _t89 = _t38*params->a[8];
  const double _t90 = _t36*_t89;
  const double _t91 = _t40*_t41;
  const double _t92 = 0.9e1*_t5;
  const double _t93 = _t41*params->a[9];
  const double _t94 = _t39*_t93;
  const double _t95 = _t14*_t43;
  const double _t96 = -_t13*_t5 - 0.2e1*_t22*_t57 - 0.2e1*_t5*_t68 - _t56*_t57 - _t58*_t60 - _t58*_t61 - _t62*_t64 - _t62*_t66 - _t69*_t70 - _t69*_t72 - _t73*_t74 - _t73*_t76 - _t77*_t78 - _t77*_t79 - _t80*_t82 - _t80*_t83 - _t84*_t86 - _t84*_t87 - _t88*_t90 - _t88*_t91 - _t92*_t94 - _t92*_t95;
  const double _t98 = xc_powr(n_s, -16, 3);
  const double _t99 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t100 = (0.1e1 / (_t49 * _t49));
  const double _t101 = _t100*_t7*_t99;
  const double _t102 = _t101*_t98;
  const double _t103 = -6.7260774144646838e-5*_t102*sigma_ss + _t47*_t51;
  const double _t106 = _t52*params->csi_HF;
  const double _t107 = _t106*_t44;
  const double _t108 = xc_powr(n_s, -4, 3);
  const double _t112 = xc_powr(n_s, -11, 3);
  const double _t113 = _t46*_t50;
  const double _t114 = 0.019610004233630196*_t112*_t113;
  const double _t115 = xc_powr(n_s, -19, 3);
  const double _t116 = (sigma_ss * sigma_ss);
  const double _t117 = 0.0001793620643857249*_t100*_t115*_t116*_t7*_t99 - _t114*sigma_ss;
  const double _t118 = (0.5e1 / 0.3e1)*_t45;
  const double _t119 = _t56*tau_s;
  const double _t120 = _t10*_t119;
  const double _t121 = (0.10e2 / 0.3e1)*_t45;
  const double _t122 = _t22*tau_s;
  const double _t123 = _t10*_t122;
  const double _t124 = (0.50e2 / 0.3e1)*_t45;
  const double _t125 = (0.55e2 / 0.3e1)*_t45;
  const double _t126 = 0.5e1*_t45;
  const double _t127 = (0.20e2 / 0.3e1)*_t45;
  const double _t128 = (0.25e2 / 0.3e1)*_t45;
  const double _t129 = 0.10e2*_t45;
  const double _t130 = (0.35e2 / 0.3e1)*_t45;
  const double _t131 = (0.40e2 / 0.3e1)*_t45;
  const double _t132 = 0.15e2*_t45;
  const double _t133 = _t118*_t120 + _t118*_t13*tau_s + _t121*_t123 + _t121*_t68*tau_s + _t124*_t60*tau_s + _t124*_t61*tau_s + _t125*_t64*tau_s + _t125*_t66*tau_s + _t126*_t70*tau_s + _t126*_t72*tau_s + _t127*_t74*tau_s + _t127*_t76*tau_s + _t128*_t78*tau_s + _t128*_t79*tau_s + _t129*_t82*tau_s + _t129*_t83*tau_s + _t130*_t86*tau_s + _t130*_t87*tau_s + _t131*_t90*tau_s + _t131*_t91*tau_s + _t132*_t94*tau_s + _t132*_t95*tau_s;
#endif
#if _KMAX >= 2
  const double _t135 = xc_powr(n_s, -10, 3);
  const double _t136 = 0.2e1*_t135;
  const double _t137 = _t24*params->a[1];
  const double _t138 = _t10*_t137;
  const double _t139 = _t10*_t135;
  const double _t140 = 0.6e1*_t25;
  const double _t141 = 0.90e2*_t135;
  const double _t142 = _t39*_t59;
  const double _t143 = _t42*params->a[10];
  const double _t144 = _t143*_t17;
  const double _t145 = 0.110e3*_t135;
  const double _t146 = _t16*_t65;
  const double _t147 = _t42*_t63;
  const double _t148 = _t15*params->a[11];
  const double _t149 = _t148*_t65;
  const double _t150 = xc_powi(_t11, -13);
  const double _t151 = _t150*_t19;
  const double _t152 = _t27*params->a[2];
  const double _t153 = _t135*_t20;
  const double _t154 = _t29*params->a[3];
  const double _t155 = _t135*_t23;
  const double _t156 = _t155*_t29;
  const double _t157 = _t135*_t26;
  const double _t158 = _t32*params->a[4];
  const double _t159 = _t32*params->a[5];
  const double _t160 = _t135*_t35;
  const double _t161 = _t30*params->a[6];
  const double _t162 = 0.42e2*_t135;
  const double _t163 = _t34*_t38;
  const double _t164 = _t30*_t85;
  const double _t165 = _t33*params->a[7];
  const double _t166 = _t165*_t38;
  const double _t167 = 0.56e2*_t135;
  const double _t168 = _t37*_t41;
  const double _t169 = _t33*_t89;
  const double _t170 = _t36*params->a[8];
  const double _t171 = _t170*_t41;
  const double _t172 = 0.72e2*_t135;
  const double _t173 = _t14*_t40;
  const double _t174 = _t36*_t93;
  const double _t175 = _t39*params->a[9];
  const double _t176 = _t14*_t175;
  const double _t177 = _t17*_t43;
  const double _t178 = 0.200e3*_t135*_t144 + 0.242e3*_t135*_t149 + 0.132e3*_t135*_t151 + 0.98e2*_t135*_t166 + 0.128e3*_t135*_t171 + 0.162e3*_t135*_t176 + _t136*_t138 + _t136*_t22 + _t136*_t56 + _t139*_t140 + 0.8e1*_t139*_t67 + _t141*_t142 + _t141*_t177 + _t145*_t146 + _t145*_t147 + 0.6e1*_t152*_t153 + 0.12e2*_t153*_t28 + 0.18e2*_t153*_t71 + 0.12e2*_t154*_t155 + 0.32e2*_t156*params->a[4] + 0.20e2*_t156*params->a[5] + 0.20e2*_t157*_t158 + 0.50e2*_t157*_t159 + 0.30e2*_t157*_t81 + 0.72e2*_t160*_t161 + 0.30e2*_t160*_t31 + _t162*_t163 + _t162*_t164 + _t167*_t168 + _t167*_t169 + _t172*_t173 + _t172*_t174;
  const double _t182 = xc_powi(n_s, -8);
  const double _t183 = 0.1e1/((M_PI * M_PI * M_PI * M_PI)*(_t49 * _t49 * _t49));
  const double _t184 = _t182*_t183;
  const double _t185 = -0.00013452154828929368*_t102 + 7.3823735022412434e-6*_t184*sigma_ss;
  const double _t187 = _t106*_t96;
  const double _t188 = xc_powr(n_s, -13, 3);
  const double _t189 = (0.10e2 / 0.3e1)*_t188;
  const double _t190 = _t138*tau_s;
  const double _t191 = _t10*_t188;
  const double _t192 = _t191*_t67;
  const double _t193 = _t191*_t25;
  const double _t194 = 0.10e2*tau_s;
  const double _t195 = _t188*tau_s;
  const double _t196 = 0.150e3*_t195;
  const double _t197 = _t144*_t188;
  const double _t198 = (0.550e3 / 0.3e1)*_t195;
  const double _t199 = _t149*_t188;
  const double _t200 = _t151*_t188;
  const double _t201 = _t188*_t20;
  const double _t202 = _t201*_t71;
  const double _t203 = _t188*_t23;
  const double _t204 = _t154*_t203;
  const double _t205 = 0.20e2*_t201;
  const double _t206 = _t28*tau_s;
  const double _t207 = _t29*params->a[4];
  const double _t208 = _t203*_t207;
  const double _t209 = _t188*_t26;
  const double _t210 = _t158*_t209;
  const double _t211 = (0.100e3 / 0.3e1)*tau_s;
  const double _t212 = _t29*params->a[5];
  const double _t213 = _t203*_t212;
  const double _t214 = _t159*_t209;
  const double _t215 = _t31*_t35;
  const double _t216 = 0.50e2*_t195;
  const double _t217 = _t26*_t81;
  const double _t218 = _t161*_t35;
  const double _t219 = 0.120e3*_t195;
  const double _t220 = 0.70e2*_t195;
  const double _t221 = _t166*_t188;
  const double _t222 = (0.280e3 / 0.3e1)*_t195;
  const double _t223 = _t171*_t188;
  const double _t224 = _t176*_t188;
  const double _t225 = (0.5e1 / 0.3e1)*_t10*_t21*_t45*params->a[1] + (0.10e2 / 0.3e1)*_t10*_t21*_t45*params->a[2] - _t119*_t189 + (0.5e1 / 0.3e1)*_t12*_t45*params->a[1] - _t122*_t189 + (0.50e2 / 0.3e1)*_t14*_t42*_t45*params->a[10] + 0.15e2*_t14*_t42*_t45*params->a[9] - _t142*_t196 - _t146*_t198 - _t147*_t198 + (0.50e2 / 0.3e1)*_t15*_t17*_t45*params->a[10] + (0.55e2 / 0.3e1)*_t15*_t17*_t45*params->a[11] - _t152*_t194*_t201 - _t163*_t220 - _t164*_t220 - _t168*_t222 - _t169*_t222 - _t173*_t219 - _t174*_t219 - _t177*_t196 + (0.55e2 / 0.3e1)*_t18*_t45*_t65*params->a[11] - _t189*_t190 - 0.40e2 / 0.3e1*_t192*tau_s - _t193*_t194 - 0.1000e4 / 0.3e1*_t197*tau_s - 0.1210e4 / 0.3e1*_t199*tau_s + (0.10e2 / 0.3e1)*_t20*_t24*_t45*params->a[2] + 0.5e1*_t20*_t24*_t45*params->a[3] - 0.220e3*_t200*tau_s - 0.30e2*_t202*tau_s - 0.20e2*_t204*tau_s - _t205*_t206 - 0.160e3 / 0.3e1*_t208*tau_s - _t210*_t211 - _t211*_t213 - 0.250e3 / 0.3e1*_t214*tau_s - _t215*_t216 - _t216*_t217 - _t218*_t219 - 0.490e3 / 0.3e1*_t221*tau_s - 0.640e3 / 0.3e1*_t223*tau_s - 0.270e3*_t224*tau_s + 0.5e1*_t23*_t27*_t45*params->a[3] + (0.20e2 / 0.3e1)*_t23*_t27*_t45*params->a[4] + (0.20e2 / 0.3e1)*_t26*_t29*_t45*params->a[4] + (0.25e2 / 0.3e1)*_t26*_t29*_t45*params->a[5] + (0.25e2 / 0.3e1)*_t30*_t32*_t45*params->a[5] + 0.10e2*_t30*_t32*_t45*params->a[6] + 0.10e2*_t33*_t35*_t45*params->a[6] + (0.35e2 / 0.3e1)*_t33*_t35*_t45*params->a[7] + (0.35e2 / 0.3e1)*_t36*_t38*_t45*params->a[7] + (0.40e2 / 0.3e1)*_t36*_t38*_t45*params->a[8] + (0.40e2 / 0.3e1)*_t39*_t41*_t45*params->a[8] + 0.15e2*_t39*_t41*_t45*params->a[9];
  const double _t227 = _t103*params->csi_HF;
  const double _t228 = _t227*_t44;
  const double _t229 = xc_powi(n_s, -9);
  const double _t230 = _t183*_t229;
  const double _t231 = 0.0005380861931571747*_t100*_t115*_t7*_t99*sigma_ss - _t114 - 1.9686329339309982e-5*_t116*_t230;
  const double _t234 = (0.2e1 / 0.9e1)*_t107;
  const double _t236 = (0.1e1 / 0.36e2)*_t107;
  const double _t239 = _t117*params->csi_HF;
  const double _t242 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t243 = _t183/xc_powi(n_s, 10);
  const double _t244 = xc_powr(n_s, -14, 3);
  const double _t245 = 0.071903348856644053*_t113*_t244;
  const double _t246 = xc_powr(n_s, -22, 3);
  const double _t247 = _t101*_t246;
  const double _t248 = -0.0016142585794715241*_t116*_t247 + 5.2496878238159953e-5*_t242*_t243 + _t245*sigma_ss;
  const double _t250 = (0.1e1 / 0.3e1)*_t106;
  const double _t253 = (0.40e2 / 0.9e1)*_t112;
  const double _t254 = _t13*_t253;
  const double _t255 = (tau_s * tau_s);
  const double _t256 = _t255*_t56;
  const double _t257 = (0.50e2 / 0.9e1)*_t98;
  const double _t258 = _t22*_t255;
  const double _t259 = (0.80e2 / 0.9e1)*_t112;
  const double _t260 = _t138*_t255;
  const double _t261 = _t10*_t98;
  const double _t262 = _t261*_t67;
  const double _t263 = _t25*_t261;
  const double _t264 = (0.50e2 / 0.3e1)*_t255;
  const double _t265 = (0.400e3 / 0.9e1)*_t112;
  const double _t266 = _t265*_t60;
  const double _t267 = _t265*_t61;
  const double _t268 = (0.440e3 / 0.9e1)*_t112;
  const double _t269 = _t268*_t64;
  const double _t270 = _t268*_t66;
  const double _t271 = _t259*_t68;
  const double _t272 = (0.40e2 / 0.3e1)*_t112;
  const double _t273 = _t272*_t70;
  const double _t274 = _t272*_t72;
  const double _t275 = (0.160e3 / 0.9e1)*_t112;
  const double _t276 = _t275*_t74;
  const double _t277 = _t275*_t76;
  const double _t278 = (0.200e3 / 0.9e1)*_t112;
  const double _t279 = _t278*_t78;
  const double _t280 = _t278*_t79;
  const double _t281 = (0.80e2 / 0.3e1)*_t112;
  const double _t282 = _t281*_t82;
  const double _t283 = _t281*_t83;
  const double _t284 = (0.280e3 / 0.9e1)*_t112;
  const double _t285 = _t284*_t86;
  const double _t286 = _t284*_t87;
  const double _t287 = (0.320e3 / 0.9e1)*_t112;
  const double _t288 = _t287*_t90;
  const double _t289 = _t287*_t91;
  const double _t290 = 0.40e2*_t112;
  const double _t291 = _t290*_t94;
  const double _t292 = _t290*_t95;
  const double _t293 = _t255*_t98;
  const double _t294 = 0.250e3*_t293;
  const double _t295 = _t144*_t98;
  const double _t296 = (0.2750e4 / 0.9e1)*_t293;
  const double _t297 = _t149*_t98;
  const double _t298 = _t151*_t98;
  const double _t299 = _t20*_t98;
  const double _t300 = _t152*_t299;
  const double _t301 = _t299*_t71;
  const double _t302 = _t23*_t98;
  const double _t303 = _t154*_t302;
  const double _t304 = (0.100e3 / 0.3e1)*_t255;
  const double _t305 = _t28*_t299;
  const double _t306 = _t207*_t302;
  const double _t307 = _t26*_t98;
  const double _t308 = _t158*_t307;
  const double _t309 = (0.500e3 / 0.9e1)*_t255;
  const double _t310 = _t212*_t302;
  const double _t311 = _t159*_t307;
  const double _t312 = (0.250e3 / 0.3e1)*_t293;
  const double _t313 = 0.200e3*_t293;
  const double _t314 = (0.350e3 / 0.3e1)*_t293;
  const double _t315 = _t166*_t98;
  const double _t316 = (0.1400e4 / 0.9e1)*_t293;
  const double _t317 = _t171*_t98;
  const double _t318 = _t176*_t98;
  const double _t319 = -_t120*_t253 - _t123*_t259 + _t142*_t294 + _t146*_t296 + _t147*_t296 + _t163*_t314 + _t164*_t314 + _t168*_t316 + _t169*_t316 + _t173*_t313 + _t174*_t313 + _t177*_t294 + _t215*_t312 + _t217*_t312 + _t218*_t313 - _t254*tau_s + (0.200e3 / 0.9e1)*_t255*_t262 + (0.5000e4 / 0.9e1)*_t255*_t295 + (0.6050e4 / 0.9e1)*_t255*_t297 + (0.1100e4 / 0.3e1)*_t255*_t298 + 0.50e2*_t255*_t301 + (0.800e3 / 0.9e1)*_t255*_t306 + (0.1250e4 / 0.9e1)*_t255*_t311 + (0.2450e4 / 0.9e1)*_t255*_t315 + (0.3200e4 / 0.9e1)*_t255*_t317 + 0.450e3*_t255*_t318 + _t256*_t257 + _t257*_t258 + _t257*_t260 + _t263*_t264 + _t264*_t300 - _t266*tau_s - _t267*tau_s - _t269*tau_s - _t270*tau_s - _t271*tau_s - _t273*tau_s - _t274*tau_s - _t276*tau_s - _t277*tau_s - _t279*tau_s - _t280*tau_s - _t282*tau_s - _t283*tau_s - _t285*tau_s - _t286*tau_s - _t288*tau_s - _t289*tau_s - _t291*tau_s - _t292*tau_s + _t303*_t304 + _t304*_t305 + _t308*_t309 + _t309*_t310;
#endif
#if _KMAX >= 3
  const double _t321 = xc_powi(n_s, -5);
  const double _t322 = _t24*_t321;
  const double _t323 = 0.6e1*params->a[1];
  const double _t324 = _t10*_t321;
  const double _t325 = _t36*_t59;
  const double _t326 = _t17*_t321;
  const double _t327 = _t39*params->a[10];
  const double _t328 = _t321*_t65;
  const double _t329 = _t150*_t321;
  const double _t330 = _t39*_t63;
  const double _t331 = _t42*params->a[11];
  const double _t332 = xc_powi(_t11, -14);
  const double _t333 = _t19*_t332;
  const double _t334 = _t20*_t321;
  const double _t335 = _t29*_t334;
  const double _t336 = _t23*_t321;
  const double _t337 = _t32*params->a[3];
  const double _t338 = _t26*_t321;
  const double _t339 = _t338*_t35;
  const double _t340 = _t321*_t38;
  const double _t341 = _t35*params->a[6];
  const double _t342 = _t321*_t41;
  const double _t343 = _t30*params->a[7];
  const double _t344 = _t14*_t321;
  const double _t345 = _t30*_t89;
  const double _t346 = _t33*params->a[8];
  const double _t347 = _t33*_t93;
  const double _t348 = _t36*params->a[9];
  const double _t349 = -_t140*_t321 - 0.3300e4*_t143*_t328 - 0.4356e4*_t148*_t329 - 0.36e2*_t152*_t324 - 0.108e3*_t154*_t334 - 0.240e3*_t158*_t336 - 0.300e3*_t159*_t336 - 0.1320e4*_t16*_t329 - 0.756e3*_t161*_t340 - 0.1176e4*_t165*_t342 - 0.1728e4*_t170*_t344 - 0.2430e4*_t175*_t326 - 0.144e3*_t207*_t334 - _t27*_t323*_t324 - 0.24e2*_t28*_t324 - 0.210e3*_t31*_t340 - 0.720e3*_t321*_t325 - 0.990e3*_t321*_t330 - 0.1716e4*_t321*_t333 - 0.336e3*_t321*_t345 - 0.504e3*_t321*_t347 - _t322*_t323 - 0.12e2*_t322*params->a[2] - 0.54e2*_t324*_t71 - 0.2700e4*_t326*_t327 - 0.720e3*_t326*_t40 - 0.3630e4*_t328*_t331 - 0.990e3*_t328*_t43 - 0.24e2*_t335*params->a[2] - 0.60e2*_t335*params->a[5] - 0.60e2*_t336*_t337 - 0.120e3*_t336*_t81 - 0.540e3*_t338*_t341 - 0.210e3*_t338*_t85 - 0.120e3*_t339*params->a[4] - 0.450e3*_t339*params->a[5] - 0.336e3*_t34*_t342 - 0.882e3*_t340*_t343 - 0.1344e4*_t342*_t346 - 0.1944e4*_t344*_t348 - 0.504e3*_t344*_t37;
  const double _t353 = xc_powr(n_s, -32, 3);
  const double _t354 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t355 = (0.1e1 / (_t49 * _t49 * _t49 * _t49));
  const double _t356 = _t1*_t354*_t355;
  const double _t357 = _t353*_t356;
  const double _t358 = 2.214712050672373e-5*_t184 - 2.0256768978524741e-7*_t357*sigma_ss;
  const double _t362 = (0.20e2 / 0.3e1)*_t188;
  const double _t363 = xc_powi(n_s, -6);
  const double _t364 = _t363*tau_s;
  const double _t365 = 0.10e2*_t364;
  const double _t366 = _t27*params->a[1];
  const double _t367 = _t10*_t366;
  const double _t368 = _t10*_t152;
  const double _t369 = _t10*_t364;
  const double _t370 = 0.40e2*_t28;
  const double _t371 = 0.300e3*_t188;
  const double _t372 = (0.1100e4 / 0.3e1)*_t188;
  const double _t373 = 0.100e3*_t188;
  const double _t374 = 0.240e3*_t188;
  const double _t375 = 0.140e3*_t188;
  const double _t376 = (0.560e3 / 0.3e1)*_t188;
  const double _t377 = 0.1200e4*_t364;
  const double _t378 = _t17*_t364;
  const double _t379 = _t364*_t65;
  const double _t380 = _t150*_t364;
  const double _t381 = 0.1650e4*_t364;
  const double _t382 = _t20*params->a[2];
  const double _t383 = _t29*_t382;
  const double _t384 = _t20*_t364;
  const double _t385 = _t23*_t337;
  const double _t386 = 0.100e3*_t364;
  const double _t387 = _t23*_t364;
  const double _t388 = _t26*params->a[4];
  const double _t389 = _t35*_t388;
  const double _t390 = 0.200e3*_t364;
  const double _t391 = _t20*_t212;
  const double _t392 = _t26*params->a[5];
  const double _t393 = _t35*_t392;
  const double _t394 = _t31*_t38;
  const double _t395 = 0.350e3*_t364;
  const double _t396 = _t23*_t81;
  const double _t397 = _t26*_t341;
  const double _t398 = _t364*_t38;
  const double _t399 = _t34*_t41;
  const double _t400 = 0.560e3*_t364;
  const double _t401 = _t26*_t85;
  const double _t402 = _t364*_t41;
  const double _t403 = _t14*_t37;
  const double _t404 = 0.840e3*_t364;
  const double _t405 = _t14*_t364;
  const double _t406 = _t17*_t40;
  const double _t407 = _t43*_t65;
  const double _t408 = _t137*_t365 - _t138*_t362 - _t142*_t371 + 0.5500e4*_t143*_t379 - _t146*_t372 - _t147*_t372 + 0.7260e4*_t148*_t380 - _t152*_t205 + 0.180e3*_t154*_t384 + 0.400e3*_t158*_t387 + 0.500e3*_t159*_t387 + 0.2200e4*_t16*_t380 + 0.1260e4*_t161*_t398 - _t163*_t375 - _t164*_t375 + 0.1960e4*_t165*_t402 - _t168*_t376 - _t169*_t376 + 0.2880e4*_t170*_t405 - _t173*_t374 - _t174*_t374 + 0.4050e4*_t175*_t378 - _t177*_t371 - 0.80e2 / 0.3e1*_t192 - 0.20e2*_t193 - 0.2000e4 / 0.3e1*_t197 - 0.2420e4 / 0.3e1*_t199 - 0.440e3*_t200 - _t201*_t370 - 0.60e2*_t202 - 0.40e2*_t204 + 0.240e3*_t207*_t384 - 0.320e3 / 0.3e1*_t208 - 0.200e3 / 0.3e1*_t210 - 0.200e3 / 0.3e1*_t213 - 0.500e3 / 0.3e1*_t214 - _t215*_t373 - _t217*_t373 - _t218*_t374 - _t22*_t362 - 0.980e3 / 0.3e1*_t221 - 0.1280e4 / 0.3e1*_t223 - 0.540e3*_t224 + _t25*_t365 + _t325*_t377 + 0.4500e4*_t327*_t378 + _t330*_t381 + 0.6050e4*_t331*_t379 + 0.2860e4*_t333*_t364 + 0.1470e4*_t343*_t398 + _t345*_t400 + 0.2240e4*_t346*_t402 + _t347*_t404 + 0.3240e4*_t348*_t405 - _t362*_t56 + 0.60e2*_t363*_t368*tau_s + 0.40e2*_t364*_t383 + 0.750e3*_t364*_t393 + 0.900e3*_t364*_t397 + 0.20e2*_t364*_t67 + _t365*_t367 + _t369*_t370 + 0.90e2*_t369*_t71 + _t377*_t406 + _t381*_t407 + _t385*_t386 + _t386*_t391 + _t389*_t390 + _t390*_t396 + _t394*_t395 + _t395*_t401 + _t399*_t400 + _t403*_t404;
  const double _t412 = _t44*params->csi_HF;
  const double _t414 = xc_powr(n_s, -35, 3);
  const double _t415 = 0.0007174482575428996*_t101*_t115 + 5.4018050609399309e-7*_t116*_t356*_t414 - 9.8431646696549911e-5*_t230*sigma_ss;
  const double _t421 = xc_powi(n_s, -7);
  const double _t422 = _t255*_t421;
  const double _t423 = (0.50e2 / 0.3e1)*_t422;
  const double _t424 = _t10*_t71;
  const double _t425 = _t10*_t28;
  const double _t426 = (0.200e3 / 0.3e1)*_t422;
  const double _t427 = 0.2000e4*_t422;
  const double _t428 = _t17*_t422;
  const double _t429 = _t422*_t65;
  const double _t430 = _t150*_t422;
  const double _t431 = 0.2750e4*_t422;
  const double _t432 = _t20*_t422;
  const double _t433 = (0.500e3 / 0.3e1)*_t422;
  const double _t434 = _t23*_t422;
  const double _t435 = (0.1000e4 / 0.3e1)*_t422;
  const double _t436 = (0.1750e4 / 0.3e1)*_t422;
  const double _t437 = _t38*_t422;
  const double _t438 = (0.2800e4 / 0.3e1)*_t422;
  const double _t439 = _t41*_t422;
  const double _t440 = 0.1400e4*_t422;
  const double _t441 = _t14*_t422;
  const double _t442 = -_t10*_t22*_t259 + 0.20e2*_t10*_t24*_t98*params->a[1]*tau_s + 0.80e2*_t10*_t24*_t98*params->a[2]*tau_s + 0.60e2*_t10*_t24*_t98*params->a[3]*tau_s - _t10*_t253*_t56 - _t137*_t423 + 0.900e3*_t14*_t39*_t98*params->a[10]*tau_s + 0.720e3*_t14*_t39*_t98*params->a[8]*tau_s + 0.1620e4*_t14*_t39*_t98*params->a[9]*tau_s - 0.27500e5 / 0.3e1*_t143*_t429 - 0.12100e5*_t148*_t430 + 0.1100e4*_t15*_t65*_t98*params->a[10]*tau_s + 0.2420e4*_t15*_t65*_t98*params->a[11]*tau_s + 0.1320e4*_t150*_t18*_t98*params->a[11]*tau_s - 0.300e3*_t154*_t432 - 0.2000e4 / 0.3e1*_t158*_t434 - 0.2500e4 / 0.3e1*_t159*_t434 - 0.11000e5 / 0.3e1*_t16*_t430 - 0.2100e4*_t161*_t437 - 0.9800e4 / 0.3e1*_t165*_t439 + 0.2000e4*_t17*_t42*_t98*params->a[10]*tau_s + 0.1100e4*_t17*_t42*_t98*params->a[11]*tau_s + 0.900e3*_t17*_t42*_t98*params->a[9]*tau_s - 0.4800e4*_t170*_t441 - 0.6750e4*_t175*_t428 + 0.60e2*_t20*_t27*_t98*params->a[2]*tau_s + 0.180e3*_t20*_t27*_t98*params->a[3]*tau_s + 0.120e3*_t20*_t27*_t98*params->a[4]*tau_s - 0.400e3*_t207*_t432 + 0.20e2*_t21*_t98*params->a[1]*tau_s + 0.20e2*_t21*_t98*params->a[2]*tau_s + 0.120e3*_t23*_t29*_t98*params->a[3]*tau_s + 0.320e3*_t23*_t29*_t98*params->a[4]*tau_s + 0.200e3*_t23*_t29*_t98*params->a[5]*tau_s - _t25*_t423 - _t254 + 0.200e3*_t26*_t32*_t98*params->a[4]*tau_s + 0.500e3*_t26*_t32*_t98*params->a[5]*tau_s + 0.300e3*_t26*_t32*_t98*params->a[6]*tau_s - _t266 - _t267 - _t269 - _t270 - _t271 - _t273 - _t274 - _t276 - _t277 - _t279 - _t280 - _t282 - _t283 - _t285 - _t286 - _t288 - _t289 - _t291 - _t292 + 0.300e3*_t30*_t35*_t98*params->a[5]*tau_s + 0.720e3*_t30*_t35*_t98*params->a[6]*tau_s + 0.420e3*_t30*_t35*_t98*params->a[7]*tau_s - _t325*_t427 - 0.7500e4*_t327*_t428 + 0.420e3*_t33*_t38*_t98*params->a[6]*tau_s + 0.980e3*_t33*_t38*_t98*params->a[7]*tau_s + 0.560e3*_t33*_t38*_t98*params->a[8]*tau_s - _t330*_t431 - 0.30250e5 / 0.3e1*_t331*_t429 - 0.14300e5 / 0.3e1*_t333*_t422 - 0.2450e4*_t343*_t437 - _t345*_t438 - 0.11200e5 / 0.3e1*_t346*_t439 - _t347*_t440 - 0.5400e4*_t348*_t441 + 0.560e3*_t36*_t41*_t98*params->a[7]*tau_s + 0.1280e4*_t36*_t41*_t98*params->a[8]*tau_s + 0.720e3*_t36*_t41*_t98*params->a[9]*tau_s - _t367*_t423 - 0.100e3*_t368*_t422 - _t383*_t426 - _t385*_t433 - _t389*_t435 - _t391*_t433 - 0.1250e4*_t393*_t422 - _t394*_t436 - _t396*_t435 - 0.1500e4*_t397*_t422 - _t399*_t438 - _t401*_t436 - _t403*_t440 - _t406*_t427 - _t407*_t431 - 0.150e3*_t422*_t424 - 0.100e3 / 0.3e1*_t422*_t67 - _t425*_t426;
  const double _t445 = _t231*params->csi_HF;
  const double _t446 = _t44*_t445;
  const double _t447 = _t356/xc_powr(n_s, 38, 3);
  const double _t448 = 0.0003346675987682697*_t116*_t243 - 1.4404813495839816e-6*_t242*_t447 + _t245 - 0.0038861780616907062*_t247*sigma_ss;
  const double _t449 = (0.1e1 / 0.3e1)*_t227;
  const double _t451 = 0.2e1*_t231;
  const double _t453 = (0.1e1 / M_PI);
  const double _t459 = _t239*_t44;
  const double _t464 = _t183/xc_powi(n_s, 11);
  const double _t465 = xc_powr(n_s, -17, 3);
  const double _t466 = 0.33554896133100558*_t113*_t465;
  const double _t467 = xc_powr(n_s, -41, 3);
  const double _t468 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t469 = xc_powr(n_s, -25, 3);
  const double _t470 = 3.8412835988906175e-6*_t1*_t354*_t355*_t467*_t468 + 0.013591658656784932*_t100*_t116*_t469*_t7*_t99 - 0.00099744068652503909*_t242*_t464 - _t466*sigma_ss;
  const double _t471 = _t106*_t133;
  const double _t472 = _t133*_t239;
  const double _t473 = 0.3e1*_t248;
  const double _t474 = _t106*_t319;
  const double _t476 = (0.440e3 / 0.27e2)*_t244;
  const double _t477 = (tau_s * tau_s * tau_s);
  const double _t478 = _t182*_t477;
  const double _t479 = (0.250e3 / 0.9e1)*_t478;
  const double _t480 = (0.400e3 / 0.9e1)*_t115;
  const double _t481 = (0.880e3 / 0.27e2)*_t244;
  const double _t482 = (0.1000e4 / 0.9e1)*_t478;
  const double _t483 = _t115*_t255;
  const double _t484 = _t10*_t483;
  const double _t485 = (0.4400e4 / 0.27e2)*_t244;
  const double _t486 = (0.4840e4 / 0.27e2)*_t244;
  const double _t487 = (0.440e3 / 0.9e1)*_t244;
  const double _t488 = (0.1760e4 / 0.27e2)*_t244;
  const double _t489 = (0.2200e4 / 0.27e2)*_t244;
  const double _t490 = (0.880e3 / 0.9e1)*_t244;
  const double _t491 = (0.3080e4 / 0.27e2)*_t244;
  const double _t492 = (0.3520e4 / 0.27e2)*_t244;
  const double _t493 = (0.440e3 / 0.3e1)*_t244;
  const double _t494 = (0.10000e5 / 0.3e1)*_t478;
  const double _t495 = _t17*_t478;
  const double _t496 = _t478*_t65;
  const double _t497 = _t150*_t478;
  const double _t498 = (0.13750e5 / 0.3e1)*_t478;
  const double _t499 = _t20*_t478;
  const double _t500 = (0.2500e4 / 0.9e1)*_t478;
  const double _t501 = _t23*_t478;
  const double _t502 = (0.5000e4 / 0.9e1)*_t478;
  const double _t503 = (0.8750e4 / 0.9e1)*_t478;
  const double _t504 = _t38*_t478;
  const double _t505 = (0.14000e5 / 0.9e1)*_t478;
  const double _t506 = _t41*_t478;
  const double _t507 = (0.7000e4 / 0.3e1)*_t478;
  const double _t508 = _t14*_t478;
  const double _t509 = 0.2000e4*_t483;
  const double _t510 = (0.22000e5 / 0.9e1)*_t483;
  const double _t511 = _t20*_t483;
  const double _t512 = _t23*_t483;
  const double _t513 = _t26*_t483;
  const double _t514 = (0.2000e4 / 0.3e1)*_t483;
  const double _t515 = 0.1600e4*_t483;
  const double _t516 = (0.2800e4 / 0.3e1)*_t483;
  const double _t517 = (0.11200e5 / 0.9e1)*_t483;
  const double _t518 = _t120*_t476 + _t123*_t481 + _t13*_t476*tau_s + _t137*_t479 - _t142*_t509 + (0.137500e6 / 0.9e1)*_t143*_t496 - 0.40000e5 / 0.9e1*_t144*_t483 - _t146*_t510 - _t147*_t510 + (0.60500e5 / 0.3e1)*_t148*_t497 - 0.48400e5 / 0.9e1*_t149*_t483 - 0.8800e4 / 0.3e1*_t151*_t483 - 0.400e3 / 0.3e1*_t152*_t511 + 0.500e3*_t154*_t499 - 0.800e3 / 0.3e1*_t154*_t512 + (0.10000e5 / 0.9e1)*_t158*_t501 - 0.4000e4 / 0.9e1*_t158*_t513 + (0.12500e5 / 0.9e1)*_t159*_t501 - 0.10000e5 / 0.9e1*_t159*_t513 + (0.55000e5 / 0.9e1)*_t16*_t497 + 0.3500e4*_t161*_t504 - _t163*_t516 - _t164*_t516 + (0.49000e5 / 0.9e1)*_t165*_t506 - 0.19600e5 / 0.9e1*_t166*_t483 - _t168*_t517 - _t169*_t517 + 0.8000e4*_t170*_t508 - 0.25600e5 / 0.9e1*_t171*_t483 - _t173*_t515 - _t174*_t515 + 0.11250e5*_t175*_t495 - 0.3600e4*_t176*_t483 - _t177*_t509 + (0.2000e4 / 0.3e1)*_t207*_t499 - 0.6400e4 / 0.9e1*_t207*_t512 - 0.4000e4 / 0.9e1*_t212*_t512 - _t215*_t514 - _t217*_t514 - _t218*_t515 + _t25*_t479 - 0.400e3 / 0.3e1*_t25*_t484 - _t256*_t480 - _t258*_t480 - _t260*_t480 - 0.800e3 / 0.3e1*_t28*_t511 + _t325*_t494 + 0.12500e5*_t327*_t495 + _t330*_t498 + (0.151250e6 / 0.9e1)*_t331*_t496 + (0.71500e5 / 0.9e1)*_t333*_t478 + (0.12250e5 / 0.3e1)*_t343*_t504 + _t345*_t505 + (0.56000e5 / 0.9e1)*_t346*_t506 + _t347*_t507 + 0.9000e4*_t348*_t508 + _t367*_t479 + (0.500e3 / 0.3e1)*_t368*_t478 + _t383*_t482 + _t385*_t500 + _t389*_t502 + _t391*_t500 + (0.6250e4 / 0.3e1)*_t393*_t478 + _t394*_t503 + _t396*_t502 + 0.2500e4*_t397*_t478 + _t399*_t505 + _t401*_t503 + _t403*_t507 + _t406*_t494 + _t407*_t498 + 0.250e3*_t424*_t478 + _t425*_t482 + (0.500e3 / 0.9e1)*_t478*_t67 + _t481*_t68*tau_s - 0.1600e4 / 0.9e1*_t484*_t67 + _t485*_t60*tau_s + _t485*_t61*tau_s + _t486*_t64*tau_s + _t486*_t66*tau_s + _t487*_t70*tau_s + _t487*_t72*tau_s + _t488*_t74*tau_s + _t488*_t76*tau_s + _t489*_t78*tau_s + _t489*_t79*tau_s + _t490*_t82*tau_s + _t490*_t83*tau_s + _t491*_t86*tau_s + _t491*_t87*tau_s + _t492*_t90*tau_s + _t492*_t91*tau_s + _t493*_t94*tau_s + _t493*_t95*tau_s - 0.400e3*_t511*_t71;
#endif
#if _KMAX >= 4
  const double _t520 = xc_powr(n_s, -20, 3);
  const double _t521 = 0.24e2*_t520;
  const double _t522 = 0.72e2*_t520;
  const double _t523 = _t10*_t29;
  const double _t524 = _t523*params->a[1];
  const double _t525 = _t523*params->a[2];
  const double _t526 = _t10*_t520;
  const double _t527 = 0.120e3*_t520;
  const double _t528 = _t10*_t212;
  const double _t529 = 0.5040e4*_t520;
  const double _t530 = _t33*_t59;
  const double _t531 = _t17*_t520;
  const double _t532 = _t36*params->a[10];
  const double _t533 = _t520*_t65;
  const double _t534 = _t150*_t520;
  const double _t535 = _t332*_t520;
  const double _t536 = 0.7920e4*_t520;
  const double _t537 = _t36*_t63;
  const double _t538 = _t39*params->a[11];
  const double _t539 = _t19/xc_powi(_t11, 15);
  const double _t540 = _t32*_t382;
  const double _t541 = _t20*_t520;
  const double _t542 = 0.360e3*_t520;
  const double _t543 = _t23*_t35;
  const double _t544 = _t543*params->a[3];
  const double _t545 = _t520*_t543;
  const double _t546 = 0.840e3*_t520;
  const double _t547 = _t38*_t388;
  const double _t548 = _t38*_t520;
  const double _t549 = 0.1680e4*_t520;
  const double _t550 = _t31*_t41;
  const double _t551 = _t20*_t81;
  const double _t552 = _t23*_t341;
  const double _t553 = _t26*_t548;
  const double _t554 = _t41*_t520;
  const double _t555 = 0.3024e4*_t520;
  const double _t556 = _t14*_t34;
  const double _t557 = _t23*_t85;
  const double _t558 = _t14*_t520;
  const double _t559 = _t17*_t37;
  const double _t560 = _t26*_t89;
  const double _t561 = _t30*params->a[8];
  const double _t562 = _t40*_t65;
  const double _t563 = _t30*_t93;
  const double _t564 = _t33*params->a[9];
  const double _t565 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t566 = xc_powi(_t49, -5);
  const double _t567 = tau_s/xc_powr(n_s, 23, 3);
  const double _t568 = 0.40e2*_t567;
  const double _t569 = 0.120e3*_t567;
  const double _t570 = _t10*_t567;
  const double _t571 = 0.200e3*_t567;
  const double _t572 = 0.8400e4*_t567;
  const double _t573 = _t17*_t567;
  const double _t574 = _t567*_t65;
  const double _t575 = _t150*_t567;
  const double _t576 = _t332*_t567;
  const double _t577 = 0.13200e5*_t567;
  const double _t578 = _t20*_t567;
  const double _t579 = 0.600e3*_t567;
  const double _t580 = _t543*_t567;
  const double _t581 = 0.1400e4*_t567;
  const double _t582 = _t38*_t567;
  const double _t583 = 0.2800e4*_t567;
  const double _t584 = _t26*_t582;
  const double _t585 = _t41*_t567;
  const double _t586 = 0.5040e4*_t567;
  const double _t587 = _t14*_t567;
  const double _t588 = _t96*params->csi_HF;
  const double _t589 = _t565*_t566*_t7;
  const double _t590 = _t106*_t178;
  const double _t591 = (0.260e3 / 0.9e1)*_t98;
  const double _t592 = _t421*tau_s;
  const double _t593 = (0.280e3 / 0.3e1)*_t592;
  const double _t594 = _t255/xc_powr(n_s, 26, 3);
  const double _t595 = (0.200e3 / 0.3e1)*_t594;
  const double _t596 = 0.200e3*_t594;
  const double _t597 = (0.1120e4 / 0.3e1)*_t592;
  const double _t598 = 0.1300e4*_t98;
  const double _t599 = (0.14300e5 / 0.9e1)*_t98;
  const double _t600 = (0.1300e4 / 0.3e1)*_t98;
  const double _t601 = 0.1040e4*_t98;
  const double _t602 = (0.1820e4 / 0.3e1)*_t98;
  const double _t603 = (0.7280e4 / 0.9e1)*_t98;
  const double _t604 = _t10*_t594;
  const double _t605 = (0.1000e4 / 0.3e1)*_t594;
  const double _t606 = 0.11200e5*_t592;
  const double _t607 = _t17*_t592;
  const double _t608 = _t592*_t65;
  const double _t609 = _t150*_t592;
  const double _t610 = 0.15400e5*_t592;
  const double _t611 = _t20*_t592;
  const double _t612 = (0.2800e4 / 0.3e1)*_t592;
  const double _t613 = _t23*_t592;
  const double _t614 = (0.5600e4 / 0.3e1)*_t592;
  const double _t615 = (0.9800e4 / 0.3e1)*_t592;
  const double _t616 = _t38*_t592;
  const double _t617 = (0.15680e5 / 0.3e1)*_t592;
  const double _t618 = _t41*_t592;
  const double _t619 = 0.7840e4*_t592;
  const double _t620 = _t14*_t592;
  const double _t621 = 0.14000e5*_t594;
  const double _t622 = _t17*_t594;
  const double _t623 = _t594*_t65;
  const double _t624 = _t150*_t594;
  const double _t625 = _t332*_t594;
  const double _t626 = 0.22000e5*_t594;
  const double _t627 = _t20*_t594;
  const double _t628 = 0.1000e4*_t594;
  const double _t629 = _t543*_t594;
  const double _t630 = (0.7000e4 / 0.3e1)*_t594;
  const double _t631 = _t38*_t594;
  const double _t632 = (0.14000e5 / 0.3e1)*_t594;
  const double _t633 = _t26*_t631;
  const double _t634 = _t41*_t594;
  const double _t635 = 0.8400e4*_t594;
  const double _t636 = _t14*_t594;
  const double _t637 = _t227*_t96;
  const double _t639 = _t185*_t412;
  const double _t642 = _t239*_t96;
  const double _t643 = _t106*_t225;
  const double _t644 = (0.3280e4 / 0.27e2)*_t115;
  const double _t645 = _t477/xc_powr(n_s, 29, 3);
  const double _t646 = (0.1000e4 / 0.9e1)*_t645;
  const double _t647 = (0.1000e4 / 0.3e1)*_t645;
  const double _t648 = _t115*tau_s;
  const double _t649 = _t10*_t648;
  const double _t650 = _t10*_t645;
  const double _t651 = (0.5000e4 / 0.9e1)*_t645;
  const double _t652 = (0.16400e5 / 0.3e1)*_t648;
  const double _t653 = (0.180400e6 / 0.27e2)*_t648;
  const double _t654 = _t20*_t648;
  const double _t655 = _t23*_t648;
  const double _t656 = _t26*_t648;
  const double _t657 = (0.16400e5 / 0.9e1)*_t648;
  const double _t658 = (0.13120e5 / 0.3e1)*_t648;
  const double _t659 = (0.22960e5 / 0.9e1)*_t648;
  const double _t660 = (0.91840e5 / 0.27e2)*_t648;
  const double _t661 = (0.70000e5 / 0.3e1)*_t645;
  const double _t662 = _t17*_t645;
  const double _t663 = _t645*_t65;
  const double _t664 = _t150*_t645;
  const double _t665 = (0.2200000e7 / 0.9e1)*_t143;
  const double _t666 = _t332*_t645;
  const double _t667 = (0.110000e6 / 0.3e1)*_t645;
  const double _t668 = _t20*_t645;
  const double _t669 = (0.5000e4 / 0.3e1)*_t645;
  const double _t670 = _t543*_t645;
  const double _t671 = (0.35000e5 / 0.9e1)*_t645;
  const double _t672 = _t38*_t645;
  const double _t673 = (0.70000e5 / 0.9e1)*_t645;
  const double _t674 = _t26*_t672;
  const double _t675 = _t41*_t645;
  const double _t676 = 0.14000e5*_t645;
  const double _t677 = (0.196000e6 / 0.3e1)*_t343;
  const double _t678 = _t14*_t645;
  const double _t679 = _t133*_t227;
  const double _t684 = _t248*_t412;
  const double _t688 = _t465*tau_s;
  const double _t689 = _t353*(tau_s * tau_s * tau_s * tau_s);
  const double _t690 = (0.5000e4 / 0.27e2)*_t689;
  const double _t691 = (0.5000e4 / 0.9e1)*_t689;
  const double _t692 = _t229*_t477;
  const double _t693 = (0.4000e4 / 0.9e1)*_t692;
  const double _t694 = (0.27200e5 / 0.81e2)*_t246;
  const double _t695 = _t10*_t689;
  const double _t696 = (0.25000e5 / 0.27e2)*_t689;
  const double _t697 = (0.16000e5 / 0.9e1)*_t692;
  const double _t698 = _t246*_t255;
  const double _t699 = _t10*_t698;
  const double _t700 = (0.61600e5 / 0.81e2)*_t688;
  const double _t701 = (0.67760e5 / 0.81e2)*_t688;
  const double _t702 = (0.6160e4 / 0.27e2)*_t688;
  const double _t703 = (0.24640e5 / 0.81e2)*_t688;
  const double _t704 = (0.30800e5 / 0.81e2)*_t688;
  const double _t705 = (0.12320e5 / 0.27e2)*_t688;
  const double _t706 = (0.43120e5 / 0.81e2)*_t688;
  const double _t707 = (0.49280e5 / 0.81e2)*_t688;
  const double _t708 = (0.6160e4 / 0.9e1)*_t688;
  const double _t709 = (0.350000e6 / 0.9e1)*_t689;
  const double _t710 = _t17*_t689;
  const double _t711 = _t65*_t689;
  const double _t712 = _t150*_t689;
  const double _t713 = _t332*_t689;
  const double _t714 = (0.550000e6 / 0.9e1)*_t689;
  const double _t715 = _t20*_t689;
  const double _t716 = (0.25000e5 / 0.9e1)*_t689;
  const double _t717 = _t543*_t689;
  const double _t718 = (0.175000e6 / 0.27e2)*_t689;
  const double _t719 = _t38*_t689;
  const double _t720 = (0.350000e6 / 0.27e2)*_t689;
  const double _t721 = _t26*_t719;
  const double _t722 = _t41*_t689;
  const double _t723 = (0.70000e5 / 0.3e1)*_t689;
  const double _t724 = _t14*_t689;
  const double _t725 = (0.160000e6 / 0.3e1)*_t692;
  const double _t726 = _t17*_t692;
  const double _t727 = _t65*_t692;
  const double _t728 = _t150*_t692;
  const double _t729 = (0.220000e6 / 0.3e1)*_t692;
  const double _t730 = _t20*_t692;
  const double _t731 = (0.40000e5 / 0.9e1)*_t692;
  const double _t732 = _t23*_t692;
  const double _t733 = (0.80000e5 / 0.9e1)*_t692;
  const double _t734 = (0.140000e6 / 0.9e1)*_t692;
  const double _t735 = _t38*_t692;
  const double _t736 = (0.224000e6 / 0.9e1)*_t692;
  const double _t737 = _t41*_t692;
  const double _t738 = (0.112000e6 / 0.3e1)*_t692;
  const double _t739 = _t14*_t692;
  const double _t740 = (0.136000e6 / 0.9e1)*_t698;
  const double _t741 = (0.1496000e7 / 0.81e2)*_t698;
  const double _t742 = _t20*_t698;
  const double _t743 = _t23*_t698;
  const double _t744 = _t26*_t698;
  const double _t745 = (0.136000e6 / 0.27e2)*_t698;
  const double _t746 = (0.108800e6 / 0.9e1)*_t698;
  const double _t747 = (0.190400e6 / 0.27e2)*_t698;
  const double _t748 = (0.761600e6 / 0.81e2)*_t698;
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t4)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t3/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t53 = _hc0[0]*params->csi_HF;
  const double _t54 = _t52*_t53;
  const double _t55 = my_piecewise3(_t4, 0, _t44*_t54);
#if _KMAX >= 1
  const double _t97 = my_piecewise3(_t4, 0, _t54*_t96);
  const double _t104 = _t44*_t53;
  const double _t105 = my_piecewise3(_t4, 0, _t103*_t104);
  const double _t109 = _hc0[2]*_t2;
  const double _t110 = _t108*_t109;
  const double _t111 = (0.1e1 / 0.6e1)*_t110;
  const double _t134 = my_piecewise3(_t4, 0, _t104*_t117 - _t107*_t111 + _t133*_t54);
#endif
#if _KMAX >= 2
  const double _t179 = my_piecewise3(_t4, 0, _t178*_t54);
  const double _t180 = _t53*_t96;
  const double _t181 = my_piecewise3(_t4, 0, _t103*_t180);
  const double _t186 = my_piecewise3(_t4, 0, _t104*_t185);
  const double _t226 = my_piecewise3(_t4, 0, -_t111*_t187 + _t117*_t180 + _t225*_t54);
  const double _t232 = _t103*_t53;
  const double _t233 = my_piecewise3(_t4, 0, _t104*_t231 - _t111*_t228 + _t133*_t232);
  const double _t235 = _t109/xc_powr(n_s, 7, 3);
  const double _t237 = _hc0[5]*_t7/(M_CBRTPI * M_CBRTPI);
  const double _t238 = _t237*_t45;
  const double _t240 = _t110*_t239;
  const double _t241 = (0.1e1 / 0.3e1)*_t240;
  const double _t249 = _t110*_t133;
  const double _t251 = _t117*_t53;
  const double _t252 = 0.2e1*_t251;
  const double _t320 = my_piecewise3(_t4, 0, _t104*_t248 + _t133*_t252 + _t234*_t235 + _t236*_t238 - _t241*_t44 - _t249*_t250 + _t319*_t54);
#endif
#if _KMAX >= 3
  const double _t350 = my_piecewise3(_t4, 0, _t349*_t54);
  const double _t351 = my_piecewise3(_t4, 0, _t178*_t232);
  const double _t352 = my_piecewise3(_t4, 0, _t180*_t185);
  const double _t359 = my_piecewise3(_t4, 0, _t104*_t358);
  const double _t360 = _t106*_t111;
  const double _t361 = _t178*_t53;
  const double _t409 = my_piecewise3(_t4, 0, _t117*_t361 - _t178*_t360 + _t408*_t54);
  const double _t410 = _t111*_t227;
  const double _t411 = my_piecewise3(_t4, 0, _t180*_t231 + _t225*_t232 - _t410*_t96);
  const double _t413 = _t111*_t185;
  const double _t416 = _t185*_t53;
  const double _t417 = my_piecewise3(_t4, 0, _t104*_t415 + _t133*_t416 - _t412*_t413);
  const double _t418 = (0.2e1 / 0.9e1)*_t235;
  const double _t419 = (0.1e1 / 0.36e2)*_t238;
  const double _t420 = _t110*_t250;
  const double _t443 = my_piecewise3(_t4, 0, _t180*_t248 + _t187*_t418 + _t187*_t419 + _t225*_t252 - _t225*_t420 - _t241*_t96 + _t442*_t54);
  const double _t444 = (0.1e1 / 0.3e1)*_t110;
  const double _t450 = _t133*_t53;
  const double _t452 = my_piecewise3(_t4, 0, _t104*_t448 + _t228*_t418 + _t228*_t419 + _t232*_t319 - _t249*_t449 - _t444*_t446 + _t450*_t451);
  const double _t454 = _hc0[9]*_t453/(n_s * n_s * n_s * n_s);
  const double _t455 = _t109*_t135;
  const double _t456 = (0.14e2 / 0.27e2)*_t455;
  const double _t457 = _t112*_t237;
  const double _t458 = (0.1e1 / 0.9e1)*_t457;
  const double _t460 = (0.2e1 / 0.3e1)*_t235;
  const double _t461 = (0.1e1 / 0.12e2)*_t238;
  const double _t462 = _hc0[2]*_t108*_t3;
  const double _t463 = _t248*_t462;
  const double _t475 = 0.3e1*_t251;
  const double _t519 = my_piecewise3(_t4, 0, _t104*_t470 - _t107*_t456 - _t107*_t458 - _t110*_t472 - _t236*_t454 + _t319*_t475 - _t412*_t463 + _t450*_t473 + _t459*_t460 + _t459*_t461 + _t460*_t471 + _t461*_t471 - _t462*_t474 + _t518*_t54);
#endif
#if _KMAX >= 4
  const double _t638 = _t225*_t53;
  const double _t640 = _t249*params->csi_HF;
  const double _t641 = (0.1e1 / 0.36e2)*_t454;
  const double _t680 = _t319*_t53;
  const double _t681 = (0.1e1 / 0.9e1)*_t454;
  const double _t682 = (0.56e2 / 0.27e2)*_t455;
  const double _t683 = (0.4e1 / 0.9e1)*_t457;
  const double _t685 = (0.4e1 / 0.3e1)*_t235;
  const double _t686 = (0.1e1 / 0.6e1)*_t238;
  const double _t687 = (0.2e1 / 0.3e1)*_t110;
#endif

  const double f = my_piecewise3(_t4, 0, _t55*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t4, 0, _t97*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t4, 0, _t105*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t4, 0, _t134*n_s + _t55);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t4, 0, _t179*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t4, 0, _t181*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t4, 0, _t186*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t4, 0, _t226*n_s + _t97);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t4, 0, _t105 + _t233*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t4, 0, 0.2e1*_t134 + _t320*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t4, 0, _t350*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t4, 0, _t351*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t4, 0, _t352*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t4, 0, _t359*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t4, 0, _t179 + _t409*n_s);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t4, 0, _t181 + _t411*n_s);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t4, 0, _t186 + _t417*n_s);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t4, 0, 0.2e1*_t226 + _t443*n_s);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t4, 0, 0.2e1*_t233 + _t452*n_s);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t4, 0, 0.3e1*_t320 + _t519*n_s);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, _t54*(0.52800e5*_t143*_t534 + 0.75504e5*_t148*_t535 + _t152*_t522 + 0.432e3*_t154*_t526 + 0.1440e4*_t158*_t541 + 0.1200e4*_t159*_t541 + 0.17160e5*_t16*_t535 + 0.8064e4*_t161*_t554 + 0.14112e5*_t165*_t558 + 0.23040e5*_t170*_t531 + 0.35640e5*_t175*_t533 + 0.384e3*_t207*_t526 + _t28*_t521 + 0.59400e5*_t327*_t533 + 0.87120e5*_t331*_t534 + 0.720e3*_t337*_t541 + 0.14112e5*_t343*_t554 + 0.24192e5*_t346*_t558 + 0.38880e5*_t348*_t531 + _t366*_t521 + 0.4200e4*_t392*_t548 + 0.11880e5*_t43*_t534 + 0.192e3*_t520*_t525 + 0.24024e5*_t520*_t539 + 0.2880e4*_t520*_t552 + _t521*_t524 + _t522*_t71 + _t527*_t528 + _t527*_t540 + _t529*_t530 + _t529*_t559 + 0.28800e5*_t531*_t532 + 0.43560e5*_t533*_t538 + _t536*_t537 + _t536*_t562 + _t542*_t544 + _t542*_t551 + 0.1920e4*_t545*params->a[4] + 0.3600e4*_t545*params->a[5] + _t546*_t547 + _t546*_t557 + _t549*_t550 + _t549*_t560 + 0.7560e4*_t553*params->a[6] + 0.5880e4*_t553*params->a[7] + 0.10752e5*_t554*_t561 + _t555*_t556 + _t555*_t563 + 0.18144e5*_t558*_t564)));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, _t232*_t349));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, _t185*_t361));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, _t180*_t358));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t4, 0, n_s*my_piecewise3(_t4, 0, _t104*(-8.1027075914098964e-7*_t357 + 7.4111068176966226e-9*_t565*_t566*_t7*sigma_ss/xc_powr(n_s, 40, 3))));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t4, 0, _t350 + n_s*my_piecewise3(_t4, 0, _t251*_t349 - _t349*_t360 + _t54*(0.30e2*_t10*_t27*_t363*params->a[1] + 0.180e3*_t10*_t27*_t363*params->a[2] + 0.270e3*_t10*_t27*_t363*params->a[3] + 0.120e3*_t10*_t27*_t363*params->a[4] + 0.3600e4*_t14*_t36*_t363*params->a[10] + 0.2520e4*_t14*_t36*_t363*params->a[7] + 0.8640e4*_t14*_t36*_t363*params->a[8] + 0.9720e4*_t14*_t36*_t363*params->a[9] - 0.88000e5*_t143*_t575 - 0.125840e6*_t148*_t576 + 0.6600e4*_t15*_t150*_t363*params->a[10] + 0.21780e5*_t15*_t150*_t363*params->a[11] - _t152*_t569 - 0.720e3*_t154*_t570 - 0.2400e4*_t158*_t578 - 0.2000e4*_t159*_t578 - 0.28600e5*_t16*_t576 - 0.13440e5*_t161*_t585 - 0.23520e5*_t165*_t587 + 0.13500e5*_t17*_t363*_t39*params->a[10] + 0.4950e4*_t17*_t363*_t39*params->a[11] + 0.3600e4*_t17*_t363*_t39*params->a[8] + 0.12150e5*_t17*_t363*_t39*params->a[9] - 0.38400e5*_t170*_t573 - 0.59400e5*_t175*_t574 + 0.8580e4*_t18*_t332*_t363*params->a[11] + 0.120e3*_t20*_t29*_t363*params->a[2] + 0.540e3*_t20*_t29*_t363*params->a[3] + 0.720e3*_t20*_t29*_t363*params->a[4] + 0.300e3*_t20*_t29*_t363*params->a[5] - 0.640e3*_t207*_t570 + 0.300e3*_t23*_t32*_t363*params->a[3] + 0.1200e4*_t23*_t32*_t363*params->a[4] + 0.1500e4*_t23*_t32*_t363*params->a[5] + 0.600e3*_t23*_t32*_t363*params->a[6] + 0.30e2*_t24*_t363*params->a[1] + 0.60e2*_t24*_t363*params->a[2] + 0.30e2*_t24*_t363*params->a[3] + 0.600e3*_t26*_t35*_t363*params->a[4] + 0.2250e4*_t26*_t35*_t363*params->a[5] + 0.2700e4*_t26*_t35*_t363*params->a[6] + 0.1050e4*_t26*_t35*_t363*params->a[7] + 0.1050e4*_t30*_t363*_t38*params->a[5] + 0.3780e4*_t30*_t363*_t38*params->a[6] + 0.4410e4*_t30*_t363*_t38*params->a[7] + 0.1680e4*_t30*_t363*_t38*params->a[8] - 0.99000e5*_t327*_t574 + 0.1680e4*_t33*_t363*_t41*params->a[6] + 0.5880e4*_t33*_t363*_t41*params->a[7] + 0.6720e4*_t33*_t363*_t41*params->a[8] + 0.2520e4*_t33*_t363*_t41*params->a[9] - 0.145200e6*_t331*_t575 - 0.1200e4*_t337*_t578 - 0.23520e5*_t343*_t585 - 0.40320e5*_t346*_t587 - 0.64800e5*_t348*_t573 + 0.16500e5*_t363*_t42*_t65*params->a[10] + 0.18150e5*_t363*_t42*_t65*params->a[11] + 0.4950e4*_t363*_t42*_t65*params->a[9] - _t366*_t568 - _t370*_t567 - 0.7000e4*_t392*_t582 - 0.19800e5*_t43*_t575 - _t524*_t568 - 0.320e3*_t525*_t567 - _t528*_t571 - _t530*_t572 - 0.48000e5*_t532*_t573 - _t537*_t577 - 0.72600e5*_t538*_t574 - 0.40040e5*_t539*_t567 - _t540*_t571 - _t544*_t579 - _t547*_t581 - _t550*_t583 - _t551*_t579 - 0.4800e4*_t552*_t567 - _t556*_t586 - _t557*_t581 - _t559*_t572 - _t560*_t583 - 0.17920e5*_t561*_t585 - _t562*_t577 - _t563*_t586 - 0.30240e5*_t564*_t587 - _t569*_t71 - 0.3200e4*_t580*params->a[4] - 0.6000e4*_t580*params->a[5] - 0.12600e5*_t584*params->a[6] - 0.9800e4*_t584*params->a[7])));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t4, 0, _t351 + n_s*my_piecewise3(_t4, 0, -_t178*_t410 + _t231*_t361 + _t232*_t408));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t4, 0, _t352 + n_s*my_piecewise3(_t4, 0, _t180*_t415 + _t225*_t416 - _t413*_t588));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t4, 0, _t359 + n_s*my_piecewise3(_t4, 0, _t104*(3.7812635426579517e-6*_t1*_t354*_t355*_t414*sigma_ss - 1.976295151385766e-8*_t116*_t589/xc_powr(n_s, 43, 3) - 0.00017717696405378984*_t230) - _t111*_t358*_t412 + _t358*_t450));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t4, 0, 0.2e1*_t409 + n_s*my_piecewise3(_t4, 0, -_t178*_t241 + _t248*_t361 + _t252*_t408 - _t408*_t420 + _t418*_t590 + _t419*_t590 + _t54*(-_t137*_t593 + _t138*_t591 + _t142*_t598 - 0.154000e6 / 0.3e1*_t143*_t608 + (0.440000e6 / 0.3e1)*_t143*_t624 + _t146*_t599 + _t147*_t599 - 0.67760e5*_t148*_t609 + (0.629200e6 / 0.3e1)*_t148*_t625 + _t152*_t596 + 0.1200e4*_t154*_t604 - 0.1680e4*_t154*_t611 - 0.11200e5 / 0.3e1*_t158*_t613 + 0.4000e4*_t158*_t627 - 0.14000e5 / 0.3e1*_t159*_t613 + (0.10000e5 / 0.3e1)*_t159*_t627 - 0.61600e5 / 0.3e1*_t16*_t609 + (0.143000e6 / 0.3e1)*_t16*_t625 - 0.11760e5*_t161*_t616 + 0.22400e5*_t161*_t634 + _t163*_t602 + _t164*_t602 - 0.54880e5 / 0.3e1*_t165*_t618 + 0.39200e5*_t165*_t636 + _t168*_t603 + _t169*_t603 - 0.26880e5*_t170*_t620 + 0.64000e5*_t170*_t622 + _t173*_t601 + _t174*_t601 - 0.37800e5*_t175*_t607 + 0.99000e5*_t175*_t623 + _t177*_t598 + (0.3200e4 / 0.3e1)*_t207*_t604 - 0.2240e4*_t207*_t611 + _t215*_t600 + _t217*_t600 + _t218*_t601 + _t22*_t591 - _t25*_t593 + (0.1040e4 / 0.9e1)*_t262 + (0.260e3 / 0.3e1)*_t263 + _t28*_t595 + (0.26000e5 / 0.9e1)*_t295 + (0.31460e5 / 0.9e1)*_t297 + (0.5720e4 / 0.3e1)*_t298 + (0.260e3 / 0.3e1)*_t300 + 0.260e3*_t301 + (0.520e3 / 0.3e1)*_t303 + (0.520e3 / 0.3e1)*_t305 + (0.4160e4 / 0.9e1)*_t306 + (0.2600e4 / 0.9e1)*_t308 + (0.2600e4 / 0.9e1)*_t310 + (0.6500e4 / 0.9e1)*_t311 + (0.12740e5 / 0.9e1)*_t315 + (0.16640e5 / 0.9e1)*_t317 + 0.2340e4*_t318 - _t325*_t606 - 0.42000e5*_t327*_t607 + 0.165000e6*_t327*_t623 - _t330*_t610 - 0.169400e6 / 0.3e1*_t331*_t608 + 0.242000e6*_t331*_t624 - 0.80080e5 / 0.3e1*_t333*_t592 + 0.2000e4*_t337*_t627 - 0.13720e5*_t343*_t616 + 0.39200e5*_t343*_t634 - _t345*_t617 - 0.62720e5 / 0.3e1*_t346*_t618 + 0.67200e5*_t346*_t636 - _t347*_t619 - 0.30240e5*_t348*_t620 + 0.108000e6*_t348*_t622 + _t366*_t595 - _t367*_t593 - 0.560e3*_t368*_t592 - _t383*_t597 - _t385*_t612 - _t389*_t614 - _t391*_t612 + (0.35000e5 / 0.3e1)*_t392*_t631 - 0.7000e4*_t393*_t592 - _t394*_t615 - _t396*_t614 - 0.8400e4*_t397*_t592 - _t399*_t617 - _t401*_t615 - _t403*_t619 - _t406*_t606 - _t407*_t610 - 0.840e3*_t424*_t592 - _t425*_t597 + 0.33000e5*_t43*_t624 + _t524*_t595 + (0.1600e4 / 0.3e1)*_t525*_t594 + _t528*_t605 + _t530*_t621 + 0.80000e5*_t532*_t622 + _t537*_t626 + 0.121000e6*_t538*_t623 + (0.200200e6 / 0.3e1)*_t539*_t594 + _t540*_t605 + _t544*_t628 + _t547*_t630 + _t550*_t632 + _t551*_t628 + 0.8000e4*_t552*_t594 + _t556*_t635 + _t557*_t630 + _t559*_t621 + _t56*_t591 + _t560*_t632 + (0.89600e5 / 0.3e1)*_t561*_t634 + _t562*_t626 + _t563*_t635 + 0.50400e5*_t564*_t636 - 0.560e3 / 0.3e1*_t592*_t67 + _t596*_t71 + (0.16000e5 / 0.3e1)*_t629*params->a[4] + 0.10000e5*_t629*params->a[5] + 0.21000e5*_t633*params->a[6] + (0.49000e5 / 0.3e1)*_t633*params->a[7])));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t4, 0, 0.2e1*_t411 + n_s*my_piecewise3(_t4, 0, -_t110*_t225*_t449 + _t180*_t448 + _t232*_t442 + _t418*_t637 + _t419*_t637 - _t444*_t445*_t96 + _t451*_t638));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t4, 0, 0.2e1*_t417 + n_s*my_piecewise3(_t4, 0, _t104*(-1.3504512652349827e-5*_t116*_t447 + 5.270120403695376e-8*_t242*_t589/xc_powr(n_s, 46, 3) + 0.001095872333221589*_t243*sigma_ss - 0.0045438389644383642*_t247) - 0.1e1 / 0.3e1*_t185*_t640 + _t319*_t416 - _t412*_t415*_t444 + 0.2e1*_t415*_t450 + _t418*_t639 + _t419*_t639));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t4, 0, 0.3e1*_t443 + n_s*my_piecewise3(_t4, 0, -_t106*_t442*_t462 + _t180*_t470 - _t187*_t456 - _t187*_t458 - _t187*_t641 - _t225*_t240 + _t442*_t475 + _t460*_t642 + _t460*_t643 + _t461*_t642 + _t461*_t643 - _t463*_t588 + _t473*_t638 + _t54*((0.650e3 / 0.3e1)*_t10*_t182*_t255*_t27*params->a[1] + 0.1300e4*_t10*_t182*_t255*_t27*params->a[2] + 0.1950e4*_t10*_t182*_t255*_t27*params->a[3] + (0.2600e4 / 0.3e1)*_t10*_t182*_t255*_t27*params->a[4] + (0.440e3 / 0.27e2)*_t10*_t21*_t244*params->a[1] + (0.880e3 / 0.27e2)*_t10*_t21*_t244*params->a[2] - 0.6560e4 / 0.9e1*_t115*_t20*_t206 - _t119*_t644 + (0.440e3 / 0.27e2)*_t12*_t244*params->a[1] - _t122*_t644 + 0.26000e5*_t14*_t182*_t255*_t36*params->a[10] + 0.18200e5*_t14*_t182*_t255*_t36*params->a[7] + 0.62400e5*_t14*_t182*_t255*_t36*params->a[8] + 0.70200e5*_t14*_t182*_t255*_t36*params->a[9] + (0.4400e4 / 0.27e2)*_t14*_t244*_t42*params->a[10] + (0.440e3 / 0.3e1)*_t14*_t244*_t42*params->a[9] - _t142*_t652 - 0.328000e6 / 0.27e2*_t144*_t648 - _t146*_t653 - _t147*_t653 - 0.3146000e7 / 0.9e1*_t148*_t666 - 0.396880e6 / 0.27e2*_t149*_t648 + (0.143000e6 / 0.3e1)*_t15*_t150*_t182*_t255*params->a[10] + 0.157300e6*_t15*_t150*_t182*_t255*params->a[11] + (0.4400e4 / 0.27e2)*_t15*_t17*_t244*params->a[10] + (0.4840e4 / 0.27e2)*_t15*_t17*_t244*params->a[11] - 0.72160e5 / 0.9e1*_t151*_t648 - _t152*_t647 - 0.3280e4 / 0.9e1*_t152*_t654 - 0.2000e4*_t154*_t650 - 0.6560e4 / 0.9e1*_t154*_t655 - 0.32800e5 / 0.27e2*_t158*_t656 - 0.20000e5 / 0.3e1*_t158*_t668 - 0.82000e5 / 0.27e2*_t159*_t656 - 0.50000e5 / 0.9e1*_t159*_t668 - 0.715000e6 / 0.9e1*_t16*_t666 - 0.112000e6 / 0.3e1*_t161*_t675 - _t163*_t659 - _t164*_t659 - 0.196000e6 / 0.3e1*_t165*_t678 - 0.160720e6 / 0.27e2*_t166*_t648 - _t168*_t660 - _t169*_t660 + 0.97500e5*_t17*_t182*_t255*_t39*params->a[10] + 0.35750e5*_t17*_t182*_t255*_t39*params->a[11] + 0.26000e5*_t17*_t182*_t255*_t39*params->a[8] + 0.87750e5*_t17*_t182*_t255*_t39*params->a[9] - 0.320000e6 / 0.3e1*_t170*_t662 - 0.209920e6 / 0.27e2*_t171*_t648 - _t173*_t658 - _t174*_t658 - 0.165000e6*_t175*_t663 - 0.9840e4*_t176*_t648 - _t177*_t652 + (0.185900e6 / 0.3e1)*_t18*_t182*_t255*_t332*params->a[11] + (0.4840e4 / 0.27e2)*_t18*_t244*_t65*params->a[11] + (0.2600e4 / 0.3e1)*_t182*_t20*_t255*_t29*params->a[2] + 0.3900e4*_t182*_t20*_t255*_t29*params->a[3] + 0.5200e4*_t182*_t20*_t255*_t29*params->a[4] + (0.6500e4 / 0.3e1)*_t182*_t20*_t255*_t29*params->a[5] + (0.6500e4 / 0.3e1)*_t182*_t23*_t255*_t32*params->a[3] + (0.26000e5 / 0.3e1)*_t182*_t23*_t255*_t32*params->a[4] + (0.32500e5 / 0.3e1)*_t182*_t23*_t255*_t32*params->a[5] + (0.13000e5 / 0.3e1)*_t182*_t23*_t255*_t32*params->a[6] + (0.650e3 / 0.3e1)*_t182*_t24*_t255*params->a[1] + (0.1300e4 / 0.3e1)*_t182*_t24*_t255*params->a[2] + (0.650e3 / 0.3e1)*_t182*_t24*_t255*params->a[3] + (0.13000e5 / 0.3e1)*_t182*_t255*_t26*_t35*params->a[4] + 0.16250e5*_t182*_t255*_t26*_t35*params->a[5] + 0.19500e5*_t182*_t255*_t26*_t35*params->a[6] + (0.22750e5 / 0.3e1)*_t182*_t255*_t26*_t35*params->a[7] + (0.22750e5 / 0.3e1)*_t182*_t255*_t30*_t38*params->a[5] + 0.27300e5*_t182*_t255*_t30*_t38*params->a[6] + 0.31850e5*_t182*_t255*_t30*_t38*params->a[7] + (0.36400e5 / 0.3e1)*_t182*_t255*_t30*_t38*params->a[8] + (0.36400e5 / 0.3e1)*_t182*_t255*_t33*_t41*params->a[6] + (0.127400e6 / 0.3e1)*_t182*_t255*_t33*_t41*params->a[7] + (0.145600e6 / 0.3e1)*_t182*_t255*_t33*_t41*params->a[8] + 0.18200e5*_t182*_t255*_t33*_t41*params->a[9] + (0.357500e6 / 0.3e1)*_t182*_t255*_t42*_t65*params->a[10] + (0.393250e6 / 0.3e1)*_t182*_t255*_t42*_t65*params->a[11] + 0.35750e5*_t182*_t255*_t42*_t65*params->a[9] - _t190*_t644 + (0.880e3 / 0.27e2)*_t20*_t24*_t244*params->a[2] + (0.440e3 / 0.9e1)*_t20*_t24*_t244*params->a[3] - 0.16000e5 / 0.9e1*_t207*_t650 - 0.52480e5 / 0.27e2*_t207*_t655 - 0.32800e5 / 0.27e2*_t212*_t655 - _t215*_t657 - _t217*_t657 - _t218*_t658 + (0.440e3 / 0.9e1)*_t23*_t244*_t27*params->a[3] + (0.1760e4 / 0.27e2)*_t23*_t244*_t27*params->a[4] + (0.1760e4 / 0.27e2)*_t244*_t26*_t29*params->a[4] + (0.2200e4 / 0.27e2)*_t244*_t26*_t29*params->a[5] + (0.2200e4 / 0.27e2)*_t244*_t30*_t32*params->a[5] + (0.880e3 / 0.9e1)*_t244*_t30*_t32*params->a[6] + (0.880e3 / 0.9e1)*_t244*_t33*_t35*params->a[6] + (0.3080e4 / 0.27e2)*_t244*_t33*_t35*params->a[7] + (0.3080e4 / 0.27e2)*_t244*_t36*_t38*params->a[7] + (0.3520e4 / 0.27e2)*_t244*_t36*_t38*params->a[8] + (0.3520e4 / 0.27e2)*_t244*_t39*_t41*params->a[8] + (0.440e3 / 0.3e1)*_t244*_t39*_t41*params->a[9] - 0.3280e4 / 0.9e1*_t25*_t649 - _t28*_t646 - 0.275000e6*_t327*_t663 - 0.1210000e7 / 0.3e1*_t331*_t664 - 0.10000e5 / 0.3e1*_t337*_t668 - 0.112000e6*_t346*_t678 - 0.180000e6*_t348*_t662 - _t366*_t646 - 0.175000e6 / 0.9e1*_t392*_t672 - 0.55000e5*_t43*_t664 - _t524*_t646 - 0.8000e4 / 0.9e1*_t525*_t645 - _t528*_t651 - _t530*_t661 - 0.400000e6 / 0.3e1*_t532*_t662 - _t537*_t667 - 0.605000e6 / 0.3e1*_t538*_t663 - 0.1001000e7 / 0.9e1*_t539*_t645 - _t540*_t651 - _t544*_t669 - _t547*_t671 - _t550*_t673 - _t551*_t669 - 0.40000e5 / 0.3e1*_t552*_t645 - _t556*_t676 - _t557*_t671 - _t559*_t661 - _t560*_t673 - 0.448000e6 / 0.9e1*_t561*_t675 - _t562*_t667 - _t563*_t676 - 0.84000e5*_t564*_t678 - _t647*_t71 - 0.13120e5 / 0.27e2*_t649*_t67 - 0.3280e4 / 0.3e1*_t654*_t71 - _t664*_t665 - 0.80000e5 / 0.9e1*_t670*params->a[4] - 0.50000e5 / 0.3e1*_t670*params->a[5] - 0.35000e5*_t674*params->a[6] - 0.245000e6 / 0.9e1*_t674*params->a[7] - _t675*_t677)));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t4, 0, 0.3e1*_t452 + n_s*my_piecewise3(_t4, 0, _t104*(4.273428003765812e-5*_t1*_t242*_t354*_t355*_t467 + 0.030252401526392267*_t100*_t469*_t7*_t99*sigma_ss - 0.0044841083495094959*_t116*_t464 - _t466 - 1.4053654409854336e-7*_t468*_t589/xc_powr(n_s, 49, 3)) - _t227*_t319*_t462 - _t228*_t456 - _t228*_t458 - _t228*_t641 + 0.3e1*_t231*_t680 + _t232*_t518 - _t249*_t445 - _t412*_t448*_t462 + _t446*_t460 + _t446*_t461 + 0.3e1*_t448*_t450 + _t460*_t679 + _t461*_t679));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t4, 0, 0.4e1*_t519 + n_s*my_piecewise3(_t4, 0, (0.1e1 / 0.216e3)*_hc0[14]*_t107*_t46*_t98 + _hc0[9]*_t234*_t321*_t453 + _t104*(-0.12144804670740084*_t101*_t116/xc_powr(n_s, 28, 3) + 1.9014441142090316*_t113*_t520*sigma_ss + 0.014949944324933773*_t183*_t242/xc_powi(n_s, 12) - 0.00012548193089709351*_t356*_t468/xc_powr(n_s, 44, 3) + 3.7476411759611562e-7*_t589*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3)) - _t106*_t518*_t687 + (0.140e3 / 0.81e2)*_t107*_t109*_t188 + (0.40e2 / 0.81e2)*_t107*_t237*_t244 + (0.8e1 / 0.3e1)*_t235*_t472 + (0.1e1 / 0.3e1)*_t238*_t472 - 0.2e1*_t240*_t319 - 0.2e1*_t248*_t640 + 0.6e1*_t248*_t680 + 0.4e1*_t251*_t518 - _t412*_t470*_t687 + 0.4e1*_t450*_t470 - _t459*_t681 - _t459*_t682 - _t459*_t683 - _t471*_t681 - _t471*_t682 - _t471*_t683 + _t474*_t685 + _t474*_t686 + _t54*(-0.6160e4 / 0.81e2*_t120*_t465 - 0.12320e5 / 0.81e2*_t123*_t465 - 0.6160e4 / 0.81e2*_t13*_t688 - _t137*_t693 + _t142*_t740 + (0.11000000e8 / 0.27e2)*_t143*_t712 + (0.2720000e7 / 0.81e2)*_t144*_t698 + _t146*_t741 + _t147*_t741 + (0.15730000e8 / 0.27e2)*_t148*_t713 - 0.968000e6 / 0.3e1*_t148*_t728 + (0.3291200e7 / 0.81e2)*_t149*_t698 + (0.598400e6 / 0.27e2)*_t151*_t698 + _t152*_t691 + (0.27200e5 / 0.27e2)*_t152*_t742 + (0.10000e5 / 0.3e1)*_t154*_t695 - 0.8000e4*_t154*_t730 + (0.54400e5 / 0.27e2)*_t154*_t743 + (0.100000e6 / 0.9e1)*_t158*_t715 - 0.160000e6 / 0.9e1*_t158*_t732 + (0.272000e6 / 0.81e2)*_t158*_t744 + (0.250000e6 / 0.27e2)*_t159*_t715 - 0.200000e6 / 0.9e1*_t159*_t732 + (0.680000e6 / 0.81e2)*_t159*_t744 + (0.3575000e7 / 0.27e2)*_t16*_t713 - 0.880000e6 / 0.9e1*_t16*_t728 + (0.560000e6 / 0.9e1)*_t161*_t722 - 0.56000e5*_t161*_t735 + _t163*_t747 + _t164*_t747 + (0.980000e6 / 0.9e1)*_t165*_t724 - 0.784000e6 / 0.9e1*_t165*_t737 + (0.1332800e7 / 0.81e2)*_t166*_t698 + _t168*_t748 + _t169*_t748 + (0.1600000e7 / 0.9e1)*_t170*_t710 - 0.128000e6*_t170*_t739 + (0.1740800e7 / 0.81e2)*_t171*_t698 + _t173*_t746 + _t174*_t746 + 0.275000e6*_t175*_t711 - 0.180000e6*_t175*_t726 + 0.27200e5*_t176*_t698 + _t177*_t740 + (0.80000e5 / 0.27e2)*_t207*_t695 - 0.32000e5 / 0.3e1*_t207*_t730 + (0.435200e6 / 0.81e2)*_t207*_t743 + (0.272000e6 / 0.81e2)*_t212*_t743 + _t215*_t745 + _t217*_t745 + _t218*_t746 - _t25*_t693 + (0.27200e5 / 0.27e2)*_t25*_t699 + _t256*_t694 + _t258*_t694 + _t260*_t694 + _t28*_t690 + (0.54400e5 / 0.27e2)*_t28*_t742 - _t325*_t725 + (0.1375000e7 / 0.3e1)*_t327*_t711 - 0.200000e6*_t327*_t726 - _t330*_t729 + (0.6050000e7 / 0.9e1)*_t331*_t712 - 0.2420000e7 / 0.9e1*_t331*_t727 - 0.1144000e7 / 0.9e1*_t333*_t692 + (0.50000e5 / 0.9e1)*_t337*_t715 + (0.980000e6 / 0.9e1)*_t343*_t722 - _t345*_t736 + (0.560000e6 / 0.3e1)*_t346*_t724 - 0.896000e6 / 0.9e1*_t346*_t737 - _t347*_t738 + 0.300000e6*_t348*_t710 - 0.144000e6*_t348*_t739 + _t366*_t690 - _t367*_t693 - 0.8000e4 / 0.3e1*_t368*_t692 - _t383*_t697 - _t385*_t731 - _t389*_t733 - _t391*_t731 + (0.875000e6 / 0.27e2)*_t392*_t719 - 0.100000e6 / 0.3e1*_t393*_t692 - _t394*_t734 - _t396*_t733 - 0.40000e5*_t397*_t692 - _t399*_t736 - _t401*_t734 - _t403*_t738 - _t406*_t725 - _t407*_t729 - 0.4000e4*_t424*_t692 - _t425*_t697 + (0.275000e6 / 0.3e1)*_t43*_t712 + _t524*_t690 + (0.40000e5 / 0.27e2)*_t525*_t689 + _t528*_t696 + _t530*_t709 + (0.2000000e7 / 0.9e1)*_t532*_t710 + _t537*_t714 + (0.3025000e7 / 0.9e1)*_t538*_t711 + (0.5005000e7 / 0.27e2)*_t539*_t689 + _t540*_t696 + _t544*_t716 + _t547*_t718 + _t550*_t720 + _t551*_t716 + (0.200000e6 / 0.9e1)*_t552*_t689 + _t556*_t723 + _t557*_t718 + _t559*_t709 + _t560*_t720 + (0.2240000e7 / 0.27e2)*_t561*_t722 + _t562*_t714 + _t563*_t723 + 0.140000e6*_t564*_t724 - _t60*_t700 - _t61*_t700 - _t64*_t701 - _t66*_t701 - _t665*_t727 - 0.8000e4 / 0.9e1*_t67*_t692 + (0.108800e6 / 0.81e2)*_t67*_t699 - _t677*_t735 - 0.12320e5 / 0.81e2*_t68*_t688 + _t691*_t71 - _t70*_t702 - _t702*_t72 - _t703*_t74 - _t703*_t76 - _t704*_t78 - _t704*_t79 - _t705*_t82 - _t705*_t83 - _t706*_t86 - _t706*_t87 - _t707*_t90 - _t707*_t91 - _t708*_t94 - _t708*_t95 + (0.27200e5 / 0.9e1)*_t71*_t742 + (0.400000e6 / 0.27e2)*_t717*params->a[4] + (0.250000e6 / 0.9e1)*_t717*params->a[5] + (0.175000e6 / 0.3e1)*_t721*params->a[6] + (0.1225000e7 / 0.27e2)*_t721*params->a[7]) + _t684*_t685 + _t684*_t686));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_m05_params *params = (const mgga_x_m05_params *)(p->params);
  (void)params;
#if _SPIN_UNPOL
  const double na = rho[0];
  const double gaa = sigma[0];
  const double ta = tau[0];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, (0.1e1 / 0.2e1)*na, (0.1e1 / 0.4e1)*gaa, 0, (0.1e1 / 0.2e1)*ta, _hc0);
  const double zk = 0.2e1*_hc0[0]/na;
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dgaa = (0.1e1 / 0.2e1)*_hc0[3];
  const double dF_dta = _hc0[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = (0.1e1 / 0.2e1)*_hc0[14];
  const double d2F_dna_dgaa = (0.1e1 / 0.4e1)*_hc0[13];
  const double d2F_dna_dta = (0.1e1 / 0.2e1)*_hc0[11];
  const double d2F_dgaa2 = (0.1e1 / 0.8e1)*_hc0[10];
  const double d2F_dgaa_dta = (0.1e1 / 0.4e1)*_hc0[8];
  const double d2F_dta2 = (0.1e1 / 0.2e1)*_hc0[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = (0.1e1 / 0.4e1)*_hc0[34];
  const double d3F_dna2_dgaa = (0.1e1 / 0.8e1)*_hc0[33];
  const double d3F_dna2_dta = (0.1e1 / 0.4e1)*_hc0[31];
  const double d3F_dna_dgaa2 = (0.1e1 / 0.16e2)*_hc0[30];
  const double d3F_dna_dgaa_dta = (0.1e1 / 0.8e1)*_hc0[28];
  const double d3F_dna_dta2 = (0.1e1 / 0.4e1)*_hc0[25];
  const double d3F_dgaa3 = (0.1e1 / 0.32e2)*_hc0[24];
  const double d3F_dgaa2_dta = (0.1e1 / 0.16e2)*_hc0[22];
  const double d3F_dgaa_dta2 = (0.1e1 / 0.8e1)*_hc0[19];
  const double d3F_dta3 = (0.1e1 / 0.4e1)*_hc0[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = (0.1e1 / 0.8e1)*_hc0[69];
  const double d4F_dna3_dgaa = (0.1e1 / 0.16e2)*_hc0[68];
  const double d4F_dna3_dta = (0.1e1 / 0.8e1)*_hc0[66];
  const double d4F_dna2_dgaa2 = (0.1e1 / 0.32e2)*_hc0[65];
  const double d4F_dna2_dgaa_dta = (0.1e1 / 0.16e2)*_hc0[63];
  const double d4F_dna2_dta2 = (0.1e1 / 0.8e1)*_hc0[60];
  const double d4F_dna_dgaa3 = (0.1e1 / 0.64e2)*_hc0[59];
  const double d4F_dna_dgaa2_dta = (0.1e1 / 0.32e2)*_hc0[57];
  const double d4F_dna_dgaa_dta2 = (0.1e1 / 0.16e2)*_hc0[54];
  const double d4F_dna_dta3 = (0.1e1 / 0.8e1)*_hc0[50];
  const double d4F_dgaa4 = (0.1e1 / 0.128e3)*_hc0[49];
  const double d4F_dgaa3_dta = (0.1e1 / 0.64e2)*_hc0[47];
  const double d4F_dgaa2_dta2 = (0.1e1 / 0.32e2)*_hc0[44];
  const double d4F_dgaa_dta3 = (0.1e1 / 0.16e2)*_hc0[40];
  const double d4F_dta4 = (0.1e1 / 0.8e1)*_hc0[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
#endif
#else
  const double na = rho[0];
  const double nb = rho[1];
  const double gaa = sigma[0];
  const double gbb = sigma[2];
  const double ta = tau[0];
  const double tb = tau[1];

  double _hc0[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, na, gaa, 0, ta, _hc0);
  double _hc1[(_KMAX) >= 4 ? 70 : (_KMAX) >= 3 ? 35 : (_KMAX) >= 2 ? 15 : (_KMAX) >= 1 ? 5 : 1];
  XC_CAT(xchan_k, _KMAX)(p, nb, gbb, 0, tb, _hc1);
  const double zk = (_hc0[0] + _hc1[0])/(na + nb);
  if(out->zk != NULL) out->zk[ip*p->dim.zk + 0] += zk;
#if _KMAX >= 1
  const double dF_dna = _hc0[4];
  const double dF_dnb = _hc1[4];
  const double dF_dgaa = _hc0[3];
  const double dF_dgbb = _hc1[3];
  const double dF_dta = _hc0[1];
  const double dF_dtb = _hc1[1];
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 0] += dF_dna;
  if(out->vrho != NULL) out->vrho[ip*p->dim.vrho + 1] += dF_dnb;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 0] += dF_dgaa;
  if(out->vsigma != NULL) out->vsigma[ip*p->dim.vsigma + 2] += dF_dgbb;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 0] += dF_dta;
  if(out->vtau != NULL) out->vtau[ip*p->dim.vtau + 1] += dF_dtb;
#endif
#if _KMAX >= 2
  const double d2F_dna2 = _hc0[14];
  const double d2F_dnb2 = _hc1[14];
  const double d2F_dna_dgaa = _hc0[13];
  const double d2F_dnb_dgbb = _hc1[13];
  const double d2F_dna_dta = _hc0[11];
  const double d2F_dnb_dtb = _hc1[11];
  const double d2F_dgaa2 = _hc0[10];
  const double d2F_dgbb2 = _hc1[10];
  const double d2F_dgaa_dta = _hc0[8];
  const double d2F_dgbb_dtb = _hc1[8];
  const double d2F_dta2 = _hc0[5];
  const double d2F_dtb2 = _hc1[5];
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 0] += d2F_dna2;
  if(out->v2rho2 != NULL) out->v2rho2[ip*p->dim.v2rho2 + 2] += d2F_dnb2;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 0] += d2F_dna_dgaa;
  if(out->v2rhosigma != NULL) out->v2rhosigma[ip*p->dim.v2rhosigma + 5] += d2F_dnb_dgbb;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 0] += d2F_dna_dta;
  if(out->v2rhotau != NULL) out->v2rhotau[ip*p->dim.v2rhotau + 3] += d2F_dnb_dtb;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 0] += d2F_dgaa2;
  if(out->v2sigma2 != NULL) out->v2sigma2[ip*p->dim.v2sigma2 + 5] += d2F_dgbb2;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 0] += d2F_dgaa_dta;
  if(out->v2sigmatau != NULL) out->v2sigmatau[ip*p->dim.v2sigmatau + 5] += d2F_dgbb_dtb;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 0] += d2F_dta2;
  if(out->v2tau2 != NULL) out->v2tau2[ip*p->dim.v2tau2 + 2] += d2F_dtb2;
#endif
#if _KMAX >= 3
  const double d3F_dna3 = _hc0[34];
  const double d3F_dnb3 = _hc1[34];
  const double d3F_dna2_dgaa = _hc0[33];
  const double d3F_dnb2_dgbb = _hc1[33];
  const double d3F_dna2_dta = _hc0[31];
  const double d3F_dnb2_dtb = _hc1[31];
  const double d3F_dna_dgaa2 = _hc0[30];
  const double d3F_dnb_dgbb2 = _hc1[30];
  const double d3F_dna_dgaa_dta = _hc0[28];
  const double d3F_dnb_dgbb_dtb = _hc1[28];
  const double d3F_dna_dta2 = _hc0[25];
  const double d3F_dnb_dtb2 = _hc1[25];
  const double d3F_dgaa3 = _hc0[24];
  const double d3F_dgbb3 = _hc1[24];
  const double d3F_dgaa2_dta = _hc0[22];
  const double d3F_dgbb2_dtb = _hc1[22];
  const double d3F_dgaa_dta2 = _hc0[19];
  const double d3F_dgbb_dtb2 = _hc1[19];
  const double d3F_dta3 = _hc0[15];
  const double d3F_dtb3 = _hc1[15];
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 0] += d3F_dna3;
  if(out->v3rho3 != NULL) out->v3rho3[ip*p->dim.v3rho3 + 3] += d3F_dnb3;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 0] += d3F_dna2_dgaa;
  if(out->v3rho2sigma != NULL) out->v3rho2sigma[ip*p->dim.v3rho2sigma + 8] += d3F_dnb2_dgbb;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 0] += d3F_dna2_dta;
  if(out->v3rho2tau != NULL) out->v3rho2tau[ip*p->dim.v3rho2tau + 5] += d3F_dnb2_dtb;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 0] += d3F_dna_dgaa2;
  if(out->v3rhosigma2 != NULL) out->v3rhosigma2[ip*p->dim.v3rhosigma2 + 11] += d3F_dnb_dgbb2;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 0] += d3F_dna_dgaa_dta;
  if(out->v3rhosigmatau != NULL) out->v3rhosigmatau[ip*p->dim.v3rhosigmatau + 11] += d3F_dnb_dgbb_dtb;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 0] += d3F_dna_dta2;
  if(out->v3rhotau2 != NULL) out->v3rhotau2[ip*p->dim.v3rhotau2 + 5] += d3F_dnb_dtb2;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 0] += d3F_dgaa3;
  if(out->v3sigma3 != NULL) out->v3sigma3[ip*p->dim.v3sigma3 + 9] += d3F_dgbb3;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 0] += d3F_dgaa2_dta;
  if(out->v3sigma2tau != NULL) out->v3sigma2tau[ip*p->dim.v3sigma2tau + 11] += d3F_dgbb2_dtb;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 0] += d3F_dgaa_dta2;
  if(out->v3sigmatau2 != NULL) out->v3sigmatau2[ip*p->dim.v3sigmatau2 + 8] += d3F_dgbb_dtb2;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 0] += d3F_dta3;
  if(out->v3tau3 != NULL) out->v3tau3[ip*p->dim.v3tau3 + 3] += d3F_dtb3;
#endif
#if _KMAX >= 4
  const double d4F_dna4 = _hc0[69];
  const double d4F_dnb4 = _hc1[69];
  const double d4F_dna3_dgaa = _hc0[68];
  const double d4F_dnb3_dgbb = _hc1[68];
  const double d4F_dna3_dta = _hc0[66];
  const double d4F_dnb3_dtb = _hc1[66];
  const double d4F_dna2_dgaa2 = _hc0[65];
  const double d4F_dnb2_dgbb2 = _hc1[65];
  const double d4F_dna2_dgaa_dta = _hc0[63];
  const double d4F_dnb2_dgbb_dtb = _hc1[63];
  const double d4F_dna2_dta2 = _hc0[60];
  const double d4F_dnb2_dtb2 = _hc1[60];
  const double d4F_dna_dgaa3 = _hc0[59];
  const double d4F_dnb_dgbb3 = _hc1[59];
  const double d4F_dna_dgaa2_dta = _hc0[57];
  const double d4F_dnb_dgbb2_dtb = _hc1[57];
  const double d4F_dna_dgaa_dta2 = _hc0[54];
  const double d4F_dnb_dgbb_dtb2 = _hc1[54];
  const double d4F_dna_dta3 = _hc0[50];
  const double d4F_dnb_dtb3 = _hc1[50];
  const double d4F_dgaa4 = _hc0[49];
  const double d4F_dgbb4 = _hc1[49];
  const double d4F_dgaa3_dta = _hc0[47];
  const double d4F_dgbb3_dtb = _hc1[47];
  const double d4F_dgaa2_dta2 = _hc0[44];
  const double d4F_dgbb2_dtb2 = _hc1[44];
  const double d4F_dgaa_dta3 = _hc0[40];
  const double d4F_dgbb_dtb3 = _hc1[40];
  const double d4F_dta4 = _hc0[35];
  const double d4F_dtb4 = _hc1[35];
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 0] += d4F_dna4;
  if(out->v4rho4 != NULL) out->v4rho4[ip*p->dim.v4rho4 + 4] += d4F_dnb4;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 0] += d4F_dna3_dgaa;
  if(out->v4rho3sigma != NULL) out->v4rho3sigma[ip*p->dim.v4rho3sigma + 11] += d4F_dnb3_dgbb;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 0] += d4F_dna3_dta;
  if(out->v4rho3tau != NULL) out->v4rho3tau[ip*p->dim.v4rho3tau + 7] += d4F_dnb3_dtb;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 0] += d4F_dna2_dgaa2;
  if(out->v4rho2sigma2 != NULL) out->v4rho2sigma2[ip*p->dim.v4rho2sigma2 + 17] += d4F_dnb2_dgbb2;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 0] += d4F_dna2_dgaa_dta;
  if(out->v4rho2sigmatau != NULL) out->v4rho2sigmatau[ip*p->dim.v4rho2sigmatau + 17] += d4F_dnb2_dgbb_dtb;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 0] += d4F_dna2_dta2;
  if(out->v4rho2tau2 != NULL) out->v4rho2tau2[ip*p->dim.v4rho2tau2 + 8] += d4F_dnb2_dtb2;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 0] += d4F_dna_dgaa3;
  if(out->v4rhosigma3 != NULL) out->v4rhosigma3[ip*p->dim.v4rhosigma3 + 19] += d4F_dnb_dgbb3;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 0] += d4F_dna_dgaa2_dta;
  if(out->v4rhosigma2tau != NULL) out->v4rhosigma2tau[ip*p->dim.v4rhosigma2tau + 23] += d4F_dnb_dgbb2_dtb;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 0] += d4F_dna_dgaa_dta2;
  if(out->v4rhosigmatau2 != NULL) out->v4rhosigmatau2[ip*p->dim.v4rhosigmatau2 + 17] += d4F_dnb_dgbb_dtb2;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 0] += d4F_dna_dta3;
  if(out->v4rhotau3 != NULL) out->v4rhotau3[ip*p->dim.v4rhotau3 + 7] += d4F_dnb_dtb3;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 0] += d4F_dgaa4;
  if(out->v4sigma4 != NULL) out->v4sigma4[ip*p->dim.v4sigma4 + 14] += d4F_dgbb4;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 0] += d4F_dgaa3_dta;
  if(out->v4sigma3tau != NULL) out->v4sigma3tau[ip*p->dim.v4sigma3tau + 19] += d4F_dgbb3_dtb;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 0] += d4F_dgaa2_dta2;
  if(out->v4sigma2tau2 != NULL) out->v4sigma2tau2[ip*p->dim.v4sigma2tau2 + 17] += d4F_dgbb2_dtb2;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 0] += d4F_dgaa_dta3;
  if(out->v4sigmatau3 != NULL) out->v4sigmatau3[ip*p->dim.v4sigmatau3 + 11] += d4F_dgbb_dtb3;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 0] += d4F_dta4;
  if(out->v4tau4 != NULL) out->v4tau4[ip*p->dim.v4tau4 + 4] += d4F_dtb4;
#endif
#endif
}
#endif