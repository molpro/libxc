/*
  Generated from python/mgga_exc/mgga_x_m08.py via
  python/libxc_codegen.py with Python 3.9.25, SymPy 1.14.0.
  Do not edit -- regenerate via
  scripts/sympy2c/compile.py mgga_x_m08
*/

#ifndef _MGGA_X_M08_KERNEL_BODY
#define maple2c_order 4
#define MAPLE2C_FLAGS (XC_FLAGS_I_HAVE_EXC | XC_FLAGS_I_HAVE_VXC | XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC | XC_FLAGS_I_HAVE_LXC)

/* ---- top-level dispatch ---- */

#define _MGGA_X_M08_KERNEL_BODY
#define _KMAX 0
#define _MGGA_X_M08_HELPER_BODIES
#include "mgga_x_m08.c"
#undef _MGGA_X_M08_HELPER_BODIES
#undef _KMAX
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _MGGA_X_M08_HELPER_BODIES
#include "mgga_x_m08.c"
#undef _MGGA_X_M08_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _MGGA_X_M08_HELPER_BODIES
#include "mgga_x_m08.c"
#undef _MGGA_X_M08_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _MGGA_X_M08_HELPER_BODIES
#include "mgga_x_m08.c"
#undef _MGGA_X_M08_HELPER_BODIES
#undef _KMAX
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _MGGA_X_M08_HELPER_BODIES
#include "mgga_x_m08.c"
#undef _MGGA_X_M08_HELPER_BODIES
#undef _KMAX
#endif
#define _KMAX 0
#define _SPIN_UNPOL 1
#define FUNC_NAME func_exc_unpol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#define _KMAX 0
#define _SPIN_UNPOL 0
#define FUNC_NAME func_exc_pol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 1
#define FUNC_NAME func_vxc_unpol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 1
#define _KMAX 1
#define _SPIN_UNPOL 0
#define FUNC_NAME func_vxc_pol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 1
#define FUNC_NAME func_fxc_unpol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 2
#define _KMAX 2
#define _SPIN_UNPOL 0
#define FUNC_NAME func_fxc_pol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 1
#define FUNC_NAME func_kxc_unpol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 3
#define _KMAX 3
#define _SPIN_UNPOL 0
#define FUNC_NAME func_kxc_pol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 1
#define FUNC_NAME func_lxc_unpol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#if XC_MAXORDER >= 4
#define _KMAX 4
#define _SPIN_UNPOL 0
#define FUNC_NAME func_lxc_pol
#include "mgga_x_m08.c"
#undef _KMAX
#undef _SPIN_UNPOL
#undef FUNC_NAME
#endif
#elif defined(_MGGA_X_M08_HELPER_BODIES)

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
  const mgga_x_m08_params *params = (const mgga_x_m08_params *)(p->params);

  const double _t1 = xc_powr(0.6e1, 1, 3);
  const double _t2 = (0.1e1 / (M_CBRTPI));
  const double _t3 = _t1*_t2;
  const double _t4 = (0.1e1 / 0.2e1)*_t3;
  const double _t5 = -p->dens_threshold + n_s <= 0;
  const double _t6 = xc_powr(n_s, -8, 3);
  const double _t7 = (M_PI * M_CBRTPI);
  const double _t8 = _t1/_t7;
  const double _t9 = _t6*_t8;
  const double _t10 = _t9*sigma_ss;
  const double _t11 = xc_expm1(-0.0093189002206715554*_t10);
  const double _t12 = 0.1e1 - 0.55200000000000005*_t11;
  const double _t13 = xc_powr(n_s, -5, 3);
  const double _t14 = _t13*tau_s;
  const double _t15 = xc_powr(0.6e1, 2, 3);
  const double _t16 = (0.3e1 / 0.10e2)*_t15*_t7;
  const double _t17 = _t14 + _t16;
  const double _t18 = (0.1e1 / _t17);
  const double _t19 = -_t14 + _t16;
  const double _t20 = _t18*_t19;
  const double _t21 = xc_powi(_t17, -10);
  const double _t22 = xc_powi(_t19, 10);
  const double _t23 = _t21*_t22;
  const double _t24 = xc_powi(_t17, -11);
  const double _t25 = xc_powi(_t19, 11);
  const double _t26 = _t24*_t25;
  const double _t27 = (0.1e1 / (_t17 * _t17));
  const double _t28 = (_t19 * _t19);
  const double _t29 = _t27*_t28;
  const double _t30 = (0.1e1 / (_t17 * _t17 * _t17));
  const double _t31 = (_t19 * _t19 * _t19);
  const double _t32 = _t30*_t31;
  const double _t33 = (0.1e1 / (_t17 * _t17 * _t17 * _t17));
  const double _t34 = (_t19 * _t19 * _t19 * _t19);
  const double _t35 = _t33*_t34;
  const double _t36 = xc_powi(_t17, -5);
  const double _t37 = xc_powi(_t19, 5);
  const double _t38 = _t36*_t37;
  const double _t39 = xc_powi(_t17, -6);
  const double _t40 = xc_powi(_t19, 6);
  const double _t41 = _t39*_t40;
  const double _t42 = xc_powi(_t17, -7);
  const double _t43 = xc_powi(_t19, 7);
  const double _t44 = _t42*_t43;
  const double _t45 = xc_powi(_t17, -8);
  const double _t46 = xc_powi(_t19, 8);
  const double _t47 = _t45*_t46;
  const double _t48 = xc_powi(_t17, -9);
  const double _t49 = xc_powi(_t19, 9);
  const double _t50 = _t48*_t49;
  const double _t51 = _t20*params->b[1] + _t23*params->b[10] + _t26*params->b[11] + _t29*params->b[2] + _t32*params->b[3] + _t35*params->b[4] + _t38*params->b[5] + _t41*params->b[6] + _t44*params->b[7] + _t47*params->b[8] + _t50*params->b[9] + params->b[0];
  const double _t52 = 0.0091462499999999999*_t10 + 0.80400000000000005;
  const double _t53 = (0.1e1 / _t52);
  const double _t54 = 0.0073535850000000002*_t53;
  const double _t55 = _t10*_t54 + 0.1e1;
  const double _t56 = _t20*params->a[1] + _t23*params->a[10] + _t26*params->a[11] + _t29*params->a[2] + _t32*params->a[3] + _t35*params->a[4] + _t38*params->a[5] + _t41*params->a[6] + _t44*params->a[7] + _t47*params->a[8] + _t50*params->a[9] + params->a[0];
  const double _t57 = _t12*_t51 + _t55*_t56;
#if _KMAX >= 1
  const double _t59 = _t13*_t18;
  const double _t60 = _t27*params->b[1];
  const double _t61 = _t13*_t19;
  const double _t62 = 0.2e1*params->b[2];
  const double _t63 = _t27*_t61;
  const double _t64 = 0.10e2*_t13;
  const double _t65 = _t21*_t49;
  const double _t66 = _t64*_t65;
  const double _t67 = _t22*_t24;
  const double _t68 = _t67*params->b[10];
  const double _t69 = 0.11e2*_t13;
  const double _t70 = _t67*_t69;
  const double _t71 = xc_powi(_t17, -12);
  const double _t72 = _t25*params->b[11];
  const double _t73 = _t71*_t72;
  const double _t74 = _t28*_t30;
  const double _t75 = _t13*_t74;
  const double _t76 = 0.3e1*_t13;
  const double _t77 = _t74*_t76;
  const double _t78 = _t31*_t33;
  const double _t79 = _t78*params->b[3];
  const double _t80 = 0.4e1*_t13;
  const double _t81 = _t78*_t80;
  const double _t82 = _t34*_t36;
  const double _t83 = _t82*params->b[4];
  const double _t84 = 0.5e1*_t13;
  const double _t85 = _t82*_t84;
  const double _t86 = _t37*_t39;
  const double _t87 = _t86*params->b[5];
  const double _t88 = 0.6e1*_t13;
  const double _t89 = _t86*_t88;
  const double _t90 = _t40*_t42;
  const double _t91 = _t90*params->b[6];
  const double _t92 = 0.7e1*_t13;
  const double _t93 = _t90*_t92;
  const double _t94 = _t43*_t45;
  const double _t95 = _t94*params->b[7];
  const double _t96 = 0.8e1*_t13;
  const double _t97 = _t94*_t96;
  const double _t98 = _t46*_t48;
  const double _t99 = _t98*params->b[8];
  const double _t100 = 0.9e1*_t13;
  const double _t101 = _t100*_t98;
  const double _t102 = _t65*params->b[9];
  const double _t103 = -_t100*_t102 - _t101*params->b[9] - _t59*params->b[1] - _t60*_t61 - _t62*_t63 - _t62*_t75 - _t64*_t68 - _t66*params->b[10] - _t69*_t73 - _t70*params->b[11] - _t76*_t79 - _t77*params->b[3] - _t80*_t83 - _t81*params->b[4] - _t84*_t87 - _t85*params->b[5] - _t88*_t91 - _t89*params->b[6] - _t92*_t95 - _t93*params->b[7] - _t96*_t99 - _t97*params->b[8];
  const double _t104 = _t27*params->a[1];
  const double _t105 = 0.2e1*params->a[2];
  const double _t106 = _t67*params->a[10];
  const double _t107 = _t25*params->a[11];
  const double _t108 = _t107*_t71;
  const double _t109 = _t78*params->a[3];
  const double _t110 = _t82*params->a[4];
  const double _t111 = _t86*params->a[5];
  const double _t112 = _t90*params->a[6];
  const double _t113 = _t94*params->a[7];
  const double _t114 = _t98*params->a[8];
  const double _t115 = _t65*params->a[9];
  const double _t116 = -_t100*_t115 - _t101*params->a[9] - _t104*_t61 - _t105*_t63 - _t105*_t75 - _t106*_t64 - _t108*_t69 - _t109*_t76 - _t110*_t80 - _t111*_t84 - _t112*_t88 - _t113*_t92 - _t114*_t96 - _t59*params->a[1] - _t66*params->a[10] - _t70*params->a[11] - _t77*params->a[3] - _t81*params->a[4] - _t85*params->a[5] - _t89*params->a[6] - _t93*params->a[7] - _t97*params->a[8];
  const double _t117 = _t103*_t12 + _t116*_t55;
  const double _t119 = _t11 + 0.1e1;
  const double _t120 = _t119*_t51;
  const double _t121 = 0.0051440329218106987*_t9;
  const double _t122 = xc_powr(n_s, -16, 3);
  const double _t123 = (0.1e1 / (_t52 * _t52));
  const double _t124 = (0.1e1 / (M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t125 = _t124*_t15;
  const double _t126 = _t123*_t125;
  const double _t127 = _t122*_t126;
  const double _t128 = -6.7257726806250001e-5*_t127*sigma_ss + _t54*_t9;
  const double _t129 = _t120*_t121 + _t128*_t56;
  const double _t131 = xc_powr(n_s, -4, 3);
  const double _t135 = _t120*_t8;
  const double _t136 = xc_powr(n_s, -11, 3);
  const double _t137 = 0.01371742112482853*_t136;
  const double _t138 = _t135*_t137;
  const double _t139 = _t53*_t8;
  const double _t140 = 0.019609559999999998*_t136*_t139;
  const double _t141 = xc_powr(n_s, -19, 3);
  const double _t142 = (sigma_ss * sigma_ss);
  const double _t143 = 0.00017935393815*_t123*_t124*_t141*_t142*_t15 - _t140*sigma_ss;
  const double _t144 = _t18*params->b[1];
  const double _t145 = (0.5e1 / 0.3e1)*_t6;
  const double _t146 = _t60*tau_s;
  const double _t147 = _t145*_t19;
  const double _t148 = _t27*params->b[2];
  const double _t149 = (0.10e2 / 0.3e1)*_t6;
  const double _t150 = _t149*_t19;
  const double _t151 = (0.50e2 / 0.3e1)*_t6;
  const double _t152 = _t151*_t65;
  const double _t153 = (0.55e2 / 0.3e1)*_t6;
  const double _t154 = _t153*_t67;
  const double _t155 = _t74*params->b[2];
  const double _t156 = 0.5e1*_t6;
  const double _t157 = _t156*_t74;
  const double _t158 = (0.20e2 / 0.3e1)*_t6;
  const double _t159 = _t158*_t78;
  const double _t160 = (0.25e2 / 0.3e1)*_t6;
  const double _t161 = _t160*_t82;
  const double _t162 = 0.10e2*_t6;
  const double _t163 = _t162*_t86;
  const double _t164 = (0.35e2 / 0.3e1)*_t6;
  const double _t165 = _t164*_t90;
  const double _t166 = (0.40e2 / 0.3e1)*_t6;
  const double _t167 = _t166*_t94;
  const double _t168 = 0.15e2*_t6;
  const double _t169 = _t168*_t98;
  const double _t170 = _t102*_t168*tau_s + _t144*_t145*tau_s + _t146*_t147 + _t148*_t150*tau_s + _t149*_t155*tau_s + _t151*_t68*tau_s + _t152*params->b[10]*tau_s + _t153*_t73*tau_s + _t154*params->b[11]*tau_s + _t156*_t79*tau_s + _t157*params->b[3]*tau_s + _t158*_t83*tau_s + _t159*params->b[4]*tau_s + _t160*_t87*tau_s + _t161*params->b[5]*tau_s + _t162*_t91*tau_s + _t163*params->b[6]*tau_s + _t164*_t95*tau_s + _t165*params->b[7]*tau_s + _t166*_t99*tau_s + _t167*params->b[8]*tau_s + _t169*params->b[9]*tau_s;
  const double _t171 = _t18*params->a[1];
  const double _t172 = _t27*params->a[2];
  const double _t173 = _t74*params->a[2];
  const double _t174 = _t104*_t147*tau_s + _t106*_t151*tau_s + _t108*_t153*tau_s + _t109*_t156*tau_s + _t110*_t158*tau_s + _t111*_t160*tau_s + _t112*_t162*tau_s + _t113*_t164*tau_s + _t114*_t166*tau_s + _t115*_t168*tau_s + _t145*_t171*tau_s + _t149*_t173*tau_s + _t150*_t172*tau_s + _t152*params->a[10]*tau_s + _t154*params->a[11]*tau_s + _t157*params->a[3]*tau_s + _t159*params->a[4]*tau_s + _t161*params->a[5]*tau_s + _t163*params->a[6]*tau_s + _t165*params->a[7]*tau_s + _t167*params->a[8]*tau_s + _t169*params->a[9]*tau_s;
  const double _t175 = _t12*_t170 - _t138*sigma_ss + _t143*_t56 + _t174*_t55;
#endif
#if _KMAX >= 2
  const double _t177 = xc_powr(n_s, -10, 3);
  const double _t178 = 0.2e1*_t177;
  const double _t179 = _t178*_t27;
  const double _t180 = _t19*_t30;
  const double _t181 = _t178*_t180;
  const double _t182 = _t180*params->b[2];
  const double _t183 = 0.8e1*_t177;
  const double _t184 = 0.6e1*_t177;
  const double _t185 = _t180*_t184;
  const double _t186 = 0.90e2*_t177;
  const double _t187 = _t21*_t46;
  const double _t188 = _t187*params->b[10];
  const double _t189 = _t24*_t49;
  const double _t190 = _t189*params->b[10];
  const double _t191 = 0.200e3*_t177;
  const double _t192 = 0.110e3*_t177;
  const double _t193 = _t71*params->b[10];
  const double _t194 = _t193*_t22;
  const double _t195 = _t189*_t192;
  const double _t196 = _t22*_t71;
  const double _t197 = _t196*params->b[11];
  const double _t198 = 0.242e3*_t177;
  const double _t199 = xc_powi(_t17, -13);
  const double _t200 = _t199*_t72;
  const double _t201 = 0.132e3*_t177;
  const double _t202 = _t33*params->b[2];
  const double _t203 = _t202*_t28;
  const double _t204 = _t28*_t33;
  const double _t205 = _t204*params->b[3];
  const double _t206 = 0.18e2*_t177;
  const double _t207 = 0.12e2*_t177;
  const double _t208 = _t36*params->b[3];
  const double _t209 = _t208*_t31;
  const double _t210 = _t204*_t207;
  const double _t211 = _t31*_t36;
  const double _t212 = _t211*params->b[4];
  const double _t213 = 0.32e2*_t177;
  const double _t214 = 0.20e2*_t177;
  const double _t215 = _t39*params->b[4];
  const double _t216 = _t215*_t34;
  const double _t217 = _t211*_t214;
  const double _t218 = _t34*_t39;
  const double _t219 = _t218*params->b[5];
  const double _t220 = 0.50e2*_t177;
  const double _t221 = 0.30e2*_t177;
  const double _t222 = _t42*params->b[5];
  const double _t223 = _t222*_t37;
  const double _t224 = _t218*_t221;
  const double _t225 = 0.72e2*_t177;
  const double _t226 = _t37*_t42;
  const double _t227 = _t226*params->b[6];
  const double _t228 = 0.42e2*_t177;
  const double _t229 = _t45*params->b[6];
  const double _t230 = _t229*_t40;
  const double _t231 = _t226*_t228;
  const double _t232 = _t40*_t45;
  const double _t233 = _t232*params->b[7];
  const double _t234 = 0.98e2*_t177;
  const double _t235 = 0.56e2*_t177;
  const double _t236 = _t48*params->b[7];
  const double _t237 = _t236*_t43;
  const double _t238 = _t232*_t235;
  const double _t239 = _t43*_t48;
  const double _t240 = _t239*params->b[8];
  const double _t241 = 0.128e3*_t177;
  const double _t242 = _t187*_t225;
  const double _t243 = _t225*_t239;
  const double _t244 = _t187*params->b[9];
  const double _t245 = 0.162e3*_t177;
  const double _t246 = _t186*_t189;
  const double _t247 = _t178*_t60 + _t179*params->b[2] + _t181*params->b[1] + _t182*_t183 + _t184*_t203 + _t185*params->b[3] + _t186*_t188 + _t190*_t191 + _t192*_t194 + _t195*params->b[11] + _t197*_t198 + _t200*_t201 + _t205*_t206 + _t207*_t209 + _t210*params->b[4] + _t212*_t213 + _t214*_t216 + _t217*params->b[5] + _t219*_t220 + _t221*_t223 + _t224*params->b[6] + _t225*_t227 + _t228*_t230 + _t231*params->b[7] + _t233*_t234 + _t235*_t237 + _t238*params->b[8] + _t240*_t241 + _t242*params->b[8] + _t243*params->b[9] + _t244*_t245 + _t246*params->b[9];
  const double _t248 = _t180*params->a[2];
  const double _t249 = _t187*params->a[10];
  const double _t250 = _t189*params->a[10];
  const double _t251 = _t196*params->a[10];
  const double _t252 = _t196*params->a[11];
  const double _t253 = _t107*_t199;
  const double _t254 = _t204*params->a[2];
  const double _t255 = _t204*params->a[3];
  const double _t256 = _t211*params->a[3];
  const double _t257 = _t211*params->a[4];
  const double _t258 = _t218*params->a[4];
  const double _t259 = _t218*params->a[5];
  const double _t260 = _t226*params->a[5];
  const double _t261 = _t226*params->a[6];
  const double _t262 = _t232*params->a[6];
  const double _t263 = _t232*params->a[7];
  const double _t264 = _t239*params->a[7];
  const double _t265 = _t239*params->a[8];
  const double _t266 = _t187*params->a[9];
  const double _t267 = _t104*_t178 + _t179*params->a[2] + _t181*params->a[1] + _t183*_t248 + _t184*_t254 + _t185*params->a[3] + _t186*_t249 + _t191*_t250 + _t192*_t251 + _t195*params->a[11] + _t198*_t252 + _t201*_t253 + _t206*_t255 + _t207*_t256 + _t210*params->a[4] + _t213*_t257 + _t214*_t258 + _t217*params->a[5] + _t220*_t259 + _t221*_t260 + _t224*params->a[6] + _t225*_t261 + _t228*_t262 + _t231*params->a[7] + _t234*_t263 + _t235*_t264 + _t238*params->a[8] + _t241*_t265 + _t242*params->a[8] + _t243*params->a[9] + _t245*_t266 + _t246*params->a[9];
  const double _t268 = _t12*_t247 + _t267*_t55;
  const double _t270 = _t103*_t119;
  const double _t271 = _t116*_t128 + _t121*_t270;
  const double _t273 = _t120*_t125;
  const double _t274 = 4.7936729530203469e-5*_t122;
  const double _t275 = xc_powi(n_s, -8);
  const double _t276 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI));
  const double _t277 = _t276/(_t52 * _t52 * _t52);
  const double _t278 = _t275*_t277;
  const double _t279 = -0.0001345154536125*_t127 + 7.3818718056199694e-6*_t278*sigma_ss;
  const double _t280 = -_t273*_t274 + _t279*_t56;
  const double _t282 = _t137*_t8;
  const double _t283 = _t270*_t282;
  const double _t284 = xc_powr(n_s, -13, 3);
  const double _t285 = (0.10e2 / 0.3e1)*_t284;
  const double _t286 = _t285*tau_s;
  const double _t287 = _t180*_t286;
  const double _t288 = _t284*tau_s;
  const double _t289 = (0.40e2 / 0.3e1)*_t288;
  const double _t290 = 0.10e2*_t288;
  const double _t291 = _t180*_t290;
  const double _t292 = 0.150e3*_t288;
  const double _t293 = (0.1000e4 / 0.3e1)*_t288;
  const double _t294 = (0.550e3 / 0.3e1)*_t288;
  const double _t295 = _t189*_t294;
  const double _t296 = (0.1210e4 / 0.3e1)*_t288;
  const double _t297 = 0.220e3*_t288;
  const double _t298 = 0.30e2*_t288;
  const double _t299 = 0.20e2*_t284;
  const double _t300 = _t299*tau_s;
  const double _t301 = _t204*_t300;
  const double _t302 = (0.160e3 / 0.3e1)*_t288;
  const double _t303 = (0.100e3 / 0.3e1)*_t288;
  const double _t304 = _t211*_t303;
  const double _t305 = (0.250e3 / 0.3e1)*_t288;
  const double _t306 = 0.50e2*_t288;
  const double _t307 = _t218*_t306;
  const double _t308 = 0.120e3*_t288;
  const double _t309 = 0.70e2*_t288;
  const double _t310 = _t226*_t309;
  const double _t311 = (0.490e3 / 0.3e1)*_t288;
  const double _t312 = (0.280e3 / 0.3e1)*tau_s;
  const double _t313 = _t284*_t312;
  const double _t314 = _t232*_t313;
  const double _t315 = (0.640e3 / 0.3e1)*_t288;
  const double _t316 = _t187*_t308;
  const double _t317 = _t239*_t308;
  const double _t318 = 0.270e3*_t288;
  const double _t319 = _t189*_t292;
  const double _t320 = -_t146*_t285 - _t148*_t286 + (0.5e1 / 0.3e1)*_t18*_t6*params->b[1] - _t182*_t289 - _t188*_t292 + (0.5e1 / 0.3e1)*_t19*_t27*_t6*params->b[1] + (0.10e2 / 0.3e1)*_t19*_t27*_t6*params->b[2] - _t190*_t293 - _t194*_t294 - _t197*_t296 - _t200*_t297 - _t203*_t290 - _t205*_t298 - _t209*_t300 + (0.50e2 / 0.3e1)*_t21*_t49*_t6*params->b[10] + 0.15e2*_t21*_t49*_t6*params->b[9] - _t212*_t302 - _t216*_t303 - _t219*_t305 + (0.50e2 / 0.3e1)*_t22*_t24*_t6*params->b[10] + (0.55e2 / 0.3e1)*_t22*_t24*_t6*params->b[11] - _t223*_t306 - _t227*_t308 - _t230*_t309 - _t233*_t311 - _t237*_t313 - _t240*_t315 - _t244*_t318 + (0.55e2 / 0.3e1)*_t25*_t6*_t71*params->b[11] + (0.10e2 / 0.3e1)*_t28*_t30*_t6*params->b[2] + 0.5e1*_t28*_t30*_t6*params->b[3] - _t287*params->b[1] - _t291*params->b[3] - _t295*params->b[11] - _t301*params->b[4] - _t304*params->b[5] - _t307*params->b[6] + 0.5e1*_t31*_t33*_t6*params->b[3] + (0.20e2 / 0.3e1)*_t31*_t33*_t6*params->b[4] - _t310*params->b[7] - _t314*params->b[8] - _t316*params->b[8] - _t317*params->b[9] - _t319*params->b[9] + (0.20e2 / 0.3e1)*_t34*_t36*_t6*params->b[4] + (0.25e2 / 0.3e1)*_t34*_t36*_t6*params->b[5] + (0.25e2 / 0.3e1)*_t37*_t39*_t6*params->b[5] + 0.10e2*_t37*_t39*_t6*params->b[6] + 0.10e2*_t40*_t42*_t6*params->b[6] + (0.35e2 / 0.3e1)*_t40*_t42*_t6*params->b[7] + (0.35e2 / 0.3e1)*_t43*_t45*_t6*params->b[7] + (0.40e2 / 0.3e1)*_t43*_t45*_t6*params->b[8] + (0.40e2 / 0.3e1)*_t46*_t48*_t6*params->b[8] + 0.15e2*_t46*_t48*_t6*params->b[9];
  const double _t321 = -_t104*_t286 - _t172*_t286 + (0.5e1 / 0.3e1)*_t18*_t6*params->a[1] + (0.5e1 / 0.3e1)*_t19*_t27*_t6*params->a[1] + (0.10e2 / 0.3e1)*_t19*_t27*_t6*params->a[2] + (0.50e2 / 0.3e1)*_t21*_t49*_t6*params->a[10] + 0.15e2*_t21*_t49*_t6*params->a[9] + (0.50e2 / 0.3e1)*_t22*_t24*_t6*params->a[10] + (0.55e2 / 0.3e1)*_t22*_t24*_t6*params->a[11] - _t248*_t289 - _t249*_t292 + (0.55e2 / 0.3e1)*_t25*_t6*_t71*params->a[11] - _t250*_t293 - _t251*_t294 - _t252*_t296 - _t253*_t297 - _t254*_t290 - _t255*_t298 - _t256*_t300 - _t257*_t302 - _t258*_t303 - _t259*_t305 - _t260*_t306 - _t261*_t308 - _t262*_t309 - _t263*_t311 - _t264*_t313 - _t265*_t315 - _t266*_t318 + (0.10e2 / 0.3e1)*_t28*_t30*_t6*params->a[2] + 0.5e1*_t28*_t30*_t6*params->a[3] - _t287*params->a[1] - _t291*params->a[3] - _t295*params->a[11] - _t301*params->a[4] - _t304*params->a[5] - _t307*params->a[6] + 0.5e1*_t31*_t33*_t6*params->a[3] + (0.20e2 / 0.3e1)*_t31*_t33*_t6*params->a[4] - _t310*params->a[7] - _t314*params->a[8] - _t316*params->a[8] - _t317*params->a[9] - _t319*params->a[9] + (0.20e2 / 0.3e1)*_t34*_t36*_t6*params->a[4] + (0.25e2 / 0.3e1)*_t34*_t36*_t6*params->a[5] + (0.25e2 / 0.3e1)*_t37*_t39*_t6*params->a[5] + 0.10e2*_t37*_t39*_t6*params->a[6] + 0.10e2*_t40*_t42*_t6*params->a[6] + (0.35e2 / 0.3e1)*_t40*_t42*_t6*params->a[7] + (0.35e2 / 0.3e1)*_t43*_t45*_t6*params->a[7] + (0.40e2 / 0.3e1)*_t43*_t45*_t6*params->a[8] + (0.40e2 / 0.3e1)*_t46*_t48*_t6*params->a[8] + 0.15e2*_t46*_t48*_t6*params->a[9];
  const double _t322 = _t116*_t143 + _t12*_t320 - _t283*sigma_ss + _t321*_t55;
  const double _t324 = _t141*sigma_ss;
  const double _t325 = 0.00012783127874720925*_t324;
  const double _t326 = xc_powi(n_s, -9);
  const double _t327 = _t277*_t326;
  const double _t328 = 0.00053806181445000001*_t123*_t124*_t141*_t15*sigma_ss - _t140 - 1.9684991481653248e-5*_t142*_t327;
  const double _t329 = _t119*_t170;
  const double _t330 = _t121*_t329 + _t128*_t174 - _t138 + _t273*_t325 + _t328*_t56;
  const double _t332 = (0.2e1 / 0.9e1)*_t57;
  const double _t333 = xc_powr(n_s, -7, 3);
  const double _t335 = (0.1e1 / 0.36e2)*_t57;
  const double _t336 = (0.1e1 / (M_CBRTPI * M_CBRTPI));
  const double _t340 = xc_powr(n_s, -14, 3);
  const double _t341 = 0.050297210791037938*_t340;
  const double _t342 = _t135*_t341;
  const double _t343 = xc_powr(n_s, -22, 3);
  const double _t344 = _t273*_t343;
  const double _t345 = 0.00034088340999255797*_t142;
  const double _t346 = (sigma_ss * sigma_ss * sigma_ss);
  const double _t347 = xc_powi(n_s, -10);
  const double _t348 = _t277*_t347;
  const double _t349 = 0.071901719999999988*_t139*_t340;
  const double _t350 = _t126*_t343;
  const double _t351 = -0.0016141854433499999*_t142*_t350 + 5.2493310617741998e-5*_t346*_t348 + _t349*sigma_ss;
  const double _t352 = _t329*_t8;
  const double _t353 = 0.02743484224965706*_t136;
  const double _t354 = _t352*_t353;
  const double _t355 = 0.2e1*_t143;
  const double _t356 = (0.40e2 / 0.9e1)*_t136;
  const double _t357 = _t144*_t356;
  const double _t358 = (tau_s * tau_s);
  const double _t359 = _t358*_t60;
  const double _t360 = (0.50e2 / 0.9e1)*_t122;
  const double _t361 = _t358*_t360;
  const double _t362 = _t19*_t356;
  const double _t363 = (0.80e2 / 0.9e1)*_t136;
  const double _t364 = _t19*_t363;
  const double _t365 = _t148*_t364;
  const double _t366 = _t180*_t361;
  const double _t367 = _t122*_t358;
  const double _t368 = (0.200e3 / 0.9e1)*_t367;
  const double _t369 = (0.50e2 / 0.3e1)*_t367;
  const double _t370 = _t180*_t369;
  const double _t371 = (0.400e3 / 0.9e1)*_t136;
  const double _t372 = _t371*_t65;
  const double _t373 = _t372*params->b[10];
  const double _t374 = _t371*_t68;
  const double _t375 = (0.440e3 / 0.9e1)*_t136;
  const double _t376 = _t375*_t67;
  const double _t377 = _t376*params->b[11];
  const double _t378 = _t375*_t73;
  const double _t379 = _t155*_t363;
  const double _t380 = (0.40e2 / 0.3e1)*_t136;
  const double _t381 = _t380*_t74;
  const double _t382 = _t381*params->b[3];
  const double _t383 = _t380*_t79;
  const double _t384 = (0.160e3 / 0.9e1)*_t136;
  const double _t385 = _t384*_t78;
  const double _t386 = _t385*params->b[4];
  const double _t387 = _t384*_t83;
  const double _t388 = (0.200e3 / 0.9e1)*_t136;
  const double _t389 = _t388*_t82;
  const double _t390 = _t389*params->b[5];
  const double _t391 = _t388*_t87;
  const double _t392 = (0.80e2 / 0.3e1)*_t136;
  const double _t393 = _t392*_t86;
  const double _t394 = _t393*params->b[6];
  const double _t395 = _t392*_t91;
  const double _t396 = (0.280e3 / 0.9e1)*_t136;
  const double _t397 = _t396*_t90;
  const double _t398 = _t397*params->b[7];
  const double _t399 = _t396*_t95;
  const double _t400 = (0.320e3 / 0.9e1)*_t136;
  const double _t401 = _t400*_t94;
  const double _t402 = _t401*params->b[8];
  const double _t403 = _t400*_t99;
  const double _t404 = 0.40e2*_t136;
  const double _t405 = _t404*_t98;
  const double _t406 = _t405*params->b[9];
  const double _t407 = _t102*_t404;
  const double _t408 = 0.250e3*_t367;
  const double _t409 = (0.5000e4 / 0.9e1)*_t367;
  const double _t410 = (0.2750e4 / 0.9e1)*_t367;
  const double _t411 = _t189*_t410;
  const double _t412 = (0.6050e4 / 0.9e1)*_t367;
  const double _t413 = (0.1100e4 / 0.3e1)*_t367;
  const double _t414 = 0.50e2*_t367;
  const double _t415 = (0.100e3 / 0.3e1)*_t358;
  const double _t416 = _t122*_t415;
  const double _t417 = _t204*_t416;
  const double _t418 = (0.800e3 / 0.9e1)*_t367;
  const double _t419 = (0.500e3 / 0.9e1)*_t367;
  const double _t420 = _t211*_t419;
  const double _t421 = (0.1250e4 / 0.9e1)*_t367;
  const double _t422 = (0.250e3 / 0.3e1)*_t367;
  const double _t423 = _t218*_t422;
  const double _t424 = 0.200e3*_t367;
  const double _t425 = (0.350e3 / 0.3e1)*_t367;
  const double _t426 = _t226*_t425;
  const double _t427 = (0.2450e4 / 0.9e1)*_t367;
  const double _t428 = (0.1400e4 / 0.9e1)*_t367;
  const double _t429 = _t232*_t428;
  const double _t430 = (0.3200e4 / 0.9e1)*_t367;
  const double _t431 = _t187*_t424;
  const double _t432 = _t239*_t424;
  const double _t433 = 0.450e3*_t367;
  const double _t434 = _t189*_t408;
  const double _t435 = -_t146*_t362 + _t148*_t361 + _t182*_t368 + _t188*_t408 + _t190*_t409 + _t194*_t410 + _t197*_t412 + _t200*_t413 + _t203*_t369 + _t205*_t414 + _t209*_t416 + _t212*_t418 + _t216*_t419 + _t219*_t421 + _t223*_t422 + _t227*_t424 + _t230*_t425 + _t233*_t427 + _t237*_t428 + _t240*_t430 + _t244*_t433 - _t357*tau_s + _t359*_t360 - _t365*tau_s + _t366*params->b[1] + _t370*params->b[3] - _t373*tau_s - _t374*tau_s - _t377*tau_s - _t378*tau_s - _t379*tau_s - _t382*tau_s - _t383*tau_s - _t386*tau_s - _t387*tau_s - _t390*tau_s - _t391*tau_s - _t394*tau_s - _t395*tau_s - _t398*tau_s - _t399*tau_s - _t402*tau_s - _t403*tau_s - _t406*tau_s - _t407*tau_s + _t411*params->b[11] + _t417*params->b[4] + _t420*params->b[5] + _t423*params->b[6] + _t426*params->b[7] + _t429*params->b[8] + _t431*params->b[8] + _t432*params->b[9] + _t434*params->b[9];
  const double _t436 = _t171*_t356;
  const double _t437 = _t104*_t362;
  const double _t438 = _t172*_t364;
  const double _t439 = _t372*params->a[10];
  const double _t440 = _t106*_t371;
  const double _t441 = _t376*params->a[11];
  const double _t442 = _t108*_t375;
  const double _t443 = _t173*_t363;
  const double _t444 = _t381*params->a[3];
  const double _t445 = _t109*_t380;
  const double _t446 = _t385*params->a[4];
  const double _t447 = _t110*_t384;
  const double _t448 = _t389*params->a[5];
  const double _t449 = _t111*_t388;
  const double _t450 = _t393*params->a[6];
  const double _t451 = _t112*_t392;
  const double _t452 = _t397*params->a[7];
  const double _t453 = _t113*_t396;
  const double _t454 = _t401*params->a[8];
  const double _t455 = _t114*_t400;
  const double _t456 = _t405*params->a[9];
  const double _t457 = _t115*_t404;
  const double _t458 = _t104*_t361 + _t172*_t361 + _t248*_t368 + _t249*_t408 + _t250*_t409 + _t251*_t410 + _t252*_t412 + _t253*_t413 + _t254*_t369 + _t255*_t414 + _t256*_t416 + _t257*_t418 + _t258*_t419 + _t259*_t421 + _t260*_t422 + _t261*_t424 + _t262*_t425 + _t263*_t427 + _t264*_t428 + _t265*_t430 + _t266*_t433 + _t366*params->a[1] + _t370*params->a[3] + _t411*params->a[11] + _t417*params->a[4] + _t420*params->a[5] + _t423*params->a[6] + _t426*params->a[7] + _t429*params->a[8] + _t431*params->a[8] + _t432*params->a[9] + _t434*params->a[9] - _t436*tau_s - _t437*tau_s - _t438*tau_s - _t439*tau_s - _t440*tau_s - _t441*tau_s - _t442*tau_s - _t443*tau_s - _t444*tau_s - _t445*tau_s - _t446*tau_s - _t447*tau_s - _t448*tau_s - _t449*tau_s - _t450*tau_s - _t451*tau_s - _t452*tau_s - _t453*tau_s - _t454*tau_s - _t455*tau_s - _t456*tau_s - _t457*tau_s;
  const double _t459 = _t12*_t435 + _t174*_t355 + _t342*sigma_ss - _t344*_t345 + _t351*_t56 - _t354*sigma_ss + _t458*_t55;
#endif
#if _KMAX >= 3
  const double _t461 = xc_powi(n_s, -5);
  const double _t462 = _t30*_t461;
  const double _t463 = 0.6e1*_t462;
  const double _t464 = 0.12e2*_t462;
  const double _t465 = _t19*_t461;
  const double _t466 = _t33*_t465;
  const double _t467 = 0.6e1*_t466;
  const double _t468 = 0.36e2*_t465;
  const double _t469 = _t33*params->b[3];
  const double _t470 = 0.54e2*_t465;
  const double _t471 = 0.24e2*_t466;
  const double _t472 = _t461*params->b[10];
  const double _t473 = _t21*_t43;
  const double _t474 = 0.720e3*_t473;
  const double _t475 = _t24*_t46;
  const double _t476 = 0.2700e4*_t475;
  const double _t477 = 0.3300e4*_t461;
  const double _t478 = _t193*_t49;
  const double _t479 = _t199*_t22;
  const double _t480 = 0.1320e4*_t479;
  const double _t481 = _t461*params->b[11];
  const double _t482 = 0.990e3*_t475;
  const double _t483 = _t49*_t71;
  const double _t484 = 0.3630e4*_t483;
  const double _t485 = 0.4356e4*_t479;
  const double _t486 = xc_powi(_t17, -14);
  const double _t487 = _t486*_t72;
  const double _t488 = 0.1716e4*_t461;
  const double _t489 = _t28*_t461;
  const double _t490 = _t36*_t489;
  const double _t491 = 0.24e2*_t490;
  const double _t492 = 0.108e3*_t489;
  const double _t493 = _t39*params->b[3];
  const double _t494 = _t31*_t461;
  const double _t495 = 0.60e2*_t494;
  const double _t496 = _t36*params->b[4];
  const double _t497 = 0.144e3*_t489;
  const double _t498 = 0.240e3*_t494;
  const double _t499 = _t34*_t461;
  const double _t500 = _t42*_t499;
  const double _t501 = 0.120e3*_t500;
  const double _t502 = 0.60e2*_t490;
  const double _t503 = _t39*params->b[5];
  const double _t504 = 0.300e3*_t494;
  const double _t505 = 0.450e3*_t499;
  const double _t506 = _t45*params->b[5];
  const double _t507 = _t37*_t461;
  const double _t508 = 0.210e3*_t507;
  const double _t509 = _t461*params->b[6];
  const double _t510 = 0.120e3*_t39;
  const double _t511 = _t42*params->b[6];
  const double _t512 = 0.540e3*_t499;
  const double _t513 = 0.756e3*_t507;
  const double _t514 = _t40*_t48;
  const double _t515 = 0.336e3*_t514;
  const double _t516 = 0.210e3*_t500;
  const double _t517 = _t45*params->b[7];
  const double _t518 = 0.882e3*_t507;
  const double _t519 = 0.1176e4*_t461;
  const double _t520 = _t236*_t40;
  const double _t521 = 0.504e3*_t461;
  const double _t522 = _t473*params->b[7];
  const double _t523 = _t461*params->b[8];
  const double _t524 = 0.336e3*_t45;
  const double _t525 = 0.1344e4*_t514;
  const double _t526 = 0.1728e4*_t473;
  const double _t527 = 0.720e3*_t475;
  const double _t528 = _t461*params->b[9];
  const double _t529 = 0.1944e4*_t473;
  const double _t530 = 0.2430e4*_t475;
  const double _t531 = 0.990e3*_t483;
  const double _t532 = -_t202*_t468 - _t208*_t492 - _t215*_t498 - _t222*_t505 - _t229*_t513 - _t31*_t509*_t510 - _t37*_t523*_t524 - _t463*params->b[1] - _t463*params->b[3] - _t464*params->b[2] - _t467*params->b[1] - _t469*_t470 - _t471*params->b[4] - _t472*_t474 - _t472*_t476 - _t472*_t480 - _t477*_t478 - _t481*_t482 - _t481*_t484 - _t481*_t485 - _t487*_t488 - _t491*params->b[2] - _t493*_t495 - _t496*_t497 - _t501*params->b[4] - _t502*params->b[5] - _t503*_t504 - _t506*_t508 - _t509*_t515 - _t511*_t512 - 0.504e3*_t514*_t528 - _t516*params->b[7] - _t517*_t518 - _t519*_t520 - _t521*_t522 - _t523*_t525 - _t523*_t526 - _t523*_t527 - _t528*_t529 - _t528*_t530 - _t528*_t531;
  const double _t533 = _t33*params->a[2];
  const double _t534 = _t33*params->a[3];
  const double _t535 = _t461*params->a[10];
  const double _t536 = _t483*params->a[10];
  const double _t537 = _t461*params->a[11];
  const double _t538 = _t107*_t486;
  const double _t539 = _t36*params->a[3];
  const double _t540 = _t39*params->a[3];
  const double _t541 = _t36*params->a[4];
  const double _t542 = _t39*params->a[4];
  const double _t543 = _t39*params->a[5];
  const double _t544 = _t42*params->a[5];
  const double _t545 = _t45*params->a[5];
  const double _t546 = _t42*params->a[6];
  const double _t547 = _t45*params->a[6];
  const double _t548 = _t45*params->a[7];
  const double _t549 = _t514*params->a[7];
  const double _t550 = _t473*params->a[7];
  const double _t551 = _t461*params->a[8];
  const double _t552 = _t514*params->a[9];
  const double _t553 = _t461*params->a[9];
  const double _t554 = -_t461*_t515*params->a[6] - _t463*params->a[1] - _t463*params->a[3] - _t464*params->a[2] - _t467*params->a[1] - _t468*_t533 - _t470*_t534 - _t471*params->a[4] - _t474*_t535 - _t476*_t535 - _t477*_t536 - _t480*_t535 - _t482*_t537 - _t484*_t537 - _t485*_t537 - _t488*_t538 - _t491*params->a[2] - _t492*_t539 - _t494*_t510*params->a[6] - _t495*_t540 - _t497*_t541 - _t498*_t542 - _t501*params->a[4] - _t502*params->a[5] - _t504*_t543 - _t505*_t544 - _t507*_t524*params->a[8] - _t508*_t545 - _t512*_t546 - _t513*_t547 - _t516*params->a[7] - _t518*_t548 - _t519*_t549 - _t521*_t550 - _t521*_t552 - _t525*_t551 - _t526*_t551 - _t527*_t551 - _t529*_t553 - _t530*_t553 - _t531*_t553;
  const double _t555 = _t12*_t532 + _t55*_t554;
  const double _t557 = _t119*_t121;
  const double _t558 = _t128*_t267 + _t247*_t557;
  const double _t560 = _t125*_t274;
  const double _t561 = _t116*_t279 - _t270*_t560;
  const double _t563 = _t120*_t276;
  const double _t564 = 2.6803055963837144e-6*_t275;
  const double _t565 = xc_powr(n_s, -32, 3);
  const double _t566 = (0.1e1 / (_t52 * _t52 * _t52 * _t52));
  const double _t567 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI));
  const double _t568 = _t1*_t567;
  const double _t569 = _t566*_t568;
  const double _t570 = _t565*_t569;
  const double _t571 = 2.2145615416859907e-5*_t278 - 2.0254933500645491e-7*_t570*sigma_ss;
  const double _t572 = _t56*_t571 + _t563*_t564;
  const double _t574 = _t119*_t247;
  const double _t575 = _t282*_t574;
  const double _t576 = (0.20e2 / 0.3e1)*_t284;
  const double _t577 = _t27*_t576;
  const double _t578 = xc_powi(n_s, -6);
  const double _t579 = _t30*_t578*tau_s;
  const double _t580 = 0.10e2*_t579;
  const double _t581 = 0.20e2*_t579;
  const double _t582 = _t180*_t576;
  const double _t583 = (0.80e2 / 0.3e1)*_t284;
  const double _t584 = _t180*_t299;
  const double _t585 = _t33*params->b[1];
  const double _t586 = _t19*_t578*tau_s;
  const double _t587 = 0.10e2*_t586;
  const double _t588 = 0.60e2*_t586;
  const double _t589 = 0.90e2*_t586;
  const double _t590 = _t33*params->b[4];
  const double _t591 = 0.40e2*_t586;
  const double _t592 = 0.300e3*_t284;
  const double _t593 = (0.2000e4 / 0.3e1)*_t284;
  const double _t594 = (0.1100e4 / 0.3e1)*_t284;
  const double _t595 = _t189*_t594;
  const double _t596 = (0.2420e4 / 0.3e1)*_t284;
  const double _t597 = 0.440e3*_t284;
  const double _t598 = 0.60e2*_t284;
  const double _t599 = 0.40e2*_t284;
  const double _t600 = _t204*_t599;
  const double _t601 = (0.320e3 / 0.3e1)*_t284;
  const double _t602 = (0.200e3 / 0.3e1)*_t284;
  const double _t603 = _t211*_t602;
  const double _t604 = (0.500e3 / 0.3e1)*_t284;
  const double _t605 = 0.100e3*_t284;
  const double _t606 = _t218*_t605;
  const double _t607 = 0.240e3*_t284;
  const double _t608 = 0.140e3*_t284;
  const double _t609 = _t226*_t608;
  const double _t610 = (0.980e3 / 0.3e1)*_t284;
  const double _t611 = (0.560e3 / 0.3e1)*_t284;
  const double _t612 = _t232*_t611;
  const double _t613 = (0.1280e4 / 0.3e1)*_t284;
  const double _t614 = _t187*_t607;
  const double _t615 = _t239*_t607;
  const double _t616 = 0.540e3*_t284;
  const double _t617 = _t189*_t592;
  const double _t618 = _t473*params->b[10];
  const double _t619 = 0.1200e4*tau_s;
  const double _t620 = _t578*params->b[10];
  const double _t621 = 0.4500e4*tau_s;
  const double _t622 = _t578*tau_s;
  const double _t623 = 0.5500e4*_t622;
  const double _t624 = _t479*tau_s;
  const double _t625 = 0.2200e4*_t624;
  const double _t626 = _t475*params->b[11];
  const double _t627 = 0.1650e4*_t622;
  const double _t628 = _t578*params->b[11];
  const double _t629 = _t483*tau_s;
  const double _t630 = 0.6050e4*_t629;
  const double _t631 = 0.7260e4*_t624;
  const double _t632 = 0.2860e4*_t622;
  const double _t633 = _t36*params->b[2];
  const double _t634 = _t28*_t578;
  const double _t635 = _t634*tau_s;
  const double _t636 = 0.180e3*_t635;
  const double _t637 = _t31*_t578;
  const double _t638 = 0.100e3*tau_s;
  const double _t639 = _t637*_t638;
  const double _t640 = 0.240e3*_t635;
  const double _t641 = _t637*tau_s;
  const double _t642 = 0.400e3*_t641;
  const double _t643 = _t34*_t578;
  const double _t644 = _t42*params->b[4];
  const double _t645 = 0.200e3*tau_s;
  const double _t646 = _t36*_t634;
  const double _t647 = _t638*_t646;
  const double _t648 = 0.500e3*_t641;
  const double _t649 = _t643*tau_s;
  const double _t650 = 0.750e3*_t649;
  const double _t651 = _t37*_t578;
  const double _t652 = 0.350e3*tau_s;
  const double _t653 = _t651*_t652;
  const double _t654 = _t39*params->b[6];
  const double _t655 = _t637*_t645;
  const double _t656 = 0.900e3*_t649;
  const double _t657 = _t651*tau_s;
  const double _t658 = 0.1260e4*_t657;
  const double _t659 = _t514*_t578;
  const double _t660 = 0.560e3*tau_s;
  const double _t661 = _t659*_t660;
  const double _t662 = _t42*_t643;
  const double _t663 = _t652*_t662;
  const double _t664 = 0.1470e4*_t657;
  const double _t665 = 0.1960e4*_t622;
  const double _t666 = 0.840e3*tau_s;
  const double _t667 = _t578*_t666;
  const double _t668 = _t45*_t651*_t660;
  const double _t669 = params->b[8]*tau_s;
  const double _t670 = 0.2240e4*_t659;
  const double _t671 = _t473*_t578;
  const double _t672 = 0.2880e4*_t671;
  const double _t673 = _t475*_t578;
  const double _t674 = _t619*_t673;
  const double _t675 = params->b[9]*tau_s;
  const double _t676 = 0.3240e4*_t671;
  const double _t677 = 0.4050e4*_t673;
  const double _t678 = _t483*_t627;
  const double _t679 = -_t182*_t583 - _t188*_t592 - _t190*_t593 - _t194*_t594 - _t197*_t596 - _t200*_t597 + _t202*_t588 - _t203*_t299 - _t205*_t598 + _t208*_t636 - _t209*_t599 - _t212*_t601 + _t215*_t642 - _t216*_t602 - _t219*_t604 + _t222*_t650 - _t223*_t605 - _t227*_t607 + _t229*_t658 - _t230*_t608 - _t233*_t610 - _t237*_t611 - _t240*_t613 - _t244*_t616 + _t469*_t589 + _t475*_t620*_t621 + _t478*_t623 + _t487*_t632 + _t493*_t639 + _t496*_t640 + _t503*_t648 + _t506*_t653 + _t511*_t656 + _t517*_t664 + _t520*_t665 + _t522*_t667 - _t576*_t60 - _t577*params->b[2] + _t578*_t618*_t619 + _t580*params->b[1] + _t580*params->b[3] + _t581*params->b[2] - _t582*params->b[1] - _t584*params->b[3] + _t585*_t587 + _t590*_t591 - _t595*params->b[11] - _t600*params->b[4] - _t603*params->b[5] - _t606*params->b[6] - _t609*params->b[7] - _t612*params->b[8] - _t614*params->b[8] - _t615*params->b[9] - _t617*params->b[9] + _t620*_t625 + _t626*_t627 + _t628*_t630 + _t628*_t631 + 0.40e2*_t633*_t635 + _t643*_t644*_t645 + _t647*params->b[5] + _t654*_t655 + _t659*_t666*params->b[9] + _t661*params->b[6] + _t663*params->b[7] + _t668*params->b[8] + _t669*_t670 + _t669*_t672 + _t674*params->b[8] + _t675*_t676 + _t675*_t677 + _t678*params->b[9];
  const double _t680 = _t33*params->a[1];
  const double _t681 = _t33*params->a[4];
  const double _t682 = params->a[11]*tau_s;
  const double _t683 = _t578*params->a[11];
  const double _t684 = _t39*params->a[6];
  const double _t685 = params->a[8]*tau_s;
  const double _t686 = params->a[9]*tau_s;
  const double _t687 = -_t104*_t576 - _t248*_t583 - _t249*_t592 - _t250*_t593 - _t251*_t594 - _t252*_t596 - _t253*_t597 - _t254*_t299 - _t255*_t598 - _t256*_t599 - _t257*_t601 - _t258*_t602 - _t259*_t604 - _t260*_t605 - _t261*_t607 - _t262*_t608 - _t263*_t610 - _t264*_t611 - _t265*_t613 - _t266*_t616 + _t533*_t588 + _t534*_t589 + _t536*_t623 + _t538*_t632 + _t539*_t636 + _t540*_t639 + _t541*_t640 + _t542*_t642 + _t543*_t648 + _t544*_t650 + _t545*_t653 + _t546*_t656 + _t547*_t658 + _t548*_t664 + _t549*_t665 + _t550*_t667 + _t552*_t667 - _t577*params->a[2] + _t578*_t625*params->a[10] + _t580*params->a[1] + _t580*params->a[3] + _t581*params->a[2] - _t582*params->a[1] - _t584*params->a[3] + _t587*_t680 + _t591*_t681 - _t595*params->a[11] - _t600*params->a[4] - _t603*params->a[5] - _t606*params->a[6] - _t609*params->a[7] - _t612*params->a[8] - _t614*params->a[8] - _t615*params->a[9] - _t617*params->a[9] + _t619*_t671*params->a[10] + _t621*_t673*params->a[10] + _t630*_t683 + _t631*_t683 + _t645*_t662*params->a[4] + 0.40e2*_t646*params->a[2]*tau_s + _t647*params->a[5] + _t655*_t684 + _t661*params->a[6] + _t663*params->a[7] + _t668*params->a[8] + _t670*_t685 + _t672*_t685 + 0.1650e4*_t673*_t682 + _t674*params->a[8] + _t676*_t686 + _t677*_t686 + _t678*params->a[9];
  const double _t688 = _t12*_t679 + _t143*_t267 + _t55*_t687 - _t575*sigma_ss;
  const double _t690 = _t125*_t270;
  const double _t691 = _t116*_t328 + _t128*_t321 - _t283 + _t320*_t557 + _t325*_t690;
  const double _t693 = _t326*_t563;
  const double _t694 = 7.147481590356573e-6*sigma_ss;
  const double _t695 = 0.0002556625574944185*_t141;
  const double _t696 = xc_powr(n_s, -35, 3);
  const double _t697 = 0.00071741575260000001*_t126*_t141 + 5.4013156001721303e-7*_t142*_t569*_t696 - 9.8424957408266251e-5*_t327*sigma_ss;
  const double _t698 = _t174*_t279 + _t273*_t695 - _t329*_t560 + _t56*_t697 - _t693*_t694;
  const double _t702 = _t341*_t8;
  const double _t703 = _t270*_t702;
  const double _t704 = _t343*_t345;
  const double _t705 = _t119*_t320;
  const double _t706 = _t353*_t8;
  const double _t707 = _t705*_t706;
  const double _t708 = _t358*params->b[1];
  const double _t709 = xc_powi(n_s, -7);
  const double _t710 = _t30*_t709;
  const double _t711 = (0.50e2 / 0.3e1)*_t710;
  const double _t712 = _t30*params->b[2];
  const double _t713 = _t709*_t712;
  const double _t714 = _t358*_t711;
  const double _t715 = _t33*_t708;
  const double _t716 = _t19*_t709;
  const double _t717 = _t358*_t709;
  const double _t718 = _t19*_t717;
  const double _t719 = 0.100e3*_t718;
  const double _t720 = 0.150e3*_t718;
  const double _t721 = (0.200e3 / 0.3e1)*_t718;
  const double _t722 = 0.2000e4*_t717;
  const double _t723 = _t475*_t717;
  const double _t724 = 0.7500e4*_t723;
  const double _t725 = (0.27500e5 / 0.3e1)*_t717;
  const double _t726 = _t479*params->b[10];
  const double _t727 = (0.11000e5 / 0.3e1)*_t717;
  const double _t728 = 0.2750e4*_t717;
  const double _t729 = _t483*params->b[11];
  const double _t730 = (0.30250e5 / 0.3e1)*_t717;
  const double _t731 = _t479*params->b[11];
  const double _t732 = 0.12100e5*_t717;
  const double _t733 = (0.14300e5 / 0.3e1)*_t717;
  const double _t734 = _t28*_t717;
  const double _t735 = (0.200e3 / 0.3e1)*_t734;
  const double _t736 = 0.300e3*_t734;
  const double _t737 = _t31*_t717;
  const double _t738 = (0.500e3 / 0.3e1)*_t737;
  const double _t739 = 0.400e3*_t734;
  const double _t740 = (0.2000e4 / 0.3e1)*_t737;
  const double _t741 = _t34*_t717;
  const double _t742 = (0.1000e4 / 0.3e1)*_t741;
  const double _t743 = _t36*params->b[5];
  const double _t744 = (0.500e3 / 0.3e1)*_t734;
  const double _t745 = (0.2500e4 / 0.3e1)*_t737;
  const double _t746 = 0.1250e4*_t741;
  const double _t747 = _t37*_t717;
  const double _t748 = (0.1750e4 / 0.3e1)*_t747;
  const double _t749 = (0.1000e4 / 0.3e1)*_t737;
  const double _t750 = 0.1500e4*_t741;
  const double _t751 = 0.2100e4*_t747;
  const double _t752 = _t514*_t717;
  const double _t753 = (0.2800e4 / 0.3e1)*_t752;
  const double _t754 = _t42*params->b[7];
  const double _t755 = (0.1750e4 / 0.3e1)*_t741;
  const double _t756 = 0.2450e4*_t747;
  const double _t757 = (0.9800e4 / 0.3e1)*_t717;
  const double _t758 = 0.1400e4*_t717;
  const double _t759 = _t45*params->b[8];
  const double _t760 = (0.2800e4 / 0.3e1)*_t747;
  const double _t761 = (0.11200e5 / 0.3e1)*_t752;
  const double _t762 = _t473*_t717;
  const double _t763 = 0.4800e4*_t762;
  const double _t764 = 0.2000e4*_t723;
  const double _t765 = _t514*params->b[9];
  const double _t766 = 0.5400e4*_t762;
  const double _t767 = 0.6750e4*_t723;
  const double _t768 = _t483*_t728;
  const double _t769 = 0.20e2*_t122*_t19*_t30*params->b[1]*tau_s + 0.80e2*_t122*_t19*_t30*params->b[2]*tau_s + 0.60e2*_t122*_t19*_t30*params->b[3]*tau_s + 0.1320e4*_t122*_t199*_t25*params->b[11]*tau_s + 0.900e3*_t122*_t21*_t46*params->b[10]*tau_s + 0.720e3*_t122*_t21*_t46*params->b[8]*tau_s + 0.1620e4*_t122*_t21*_t46*params->b[9]*tau_s + 0.1100e4*_t122*_t22*_t71*params->b[10]*tau_s + 0.2420e4*_t122*_t22*_t71*params->b[11]*tau_s + 0.2000e4*_t122*_t24*_t49*params->b[10]*tau_s + 0.1100e4*_t122*_t24*_t49*params->b[11]*tau_s + 0.900e3*_t122*_t24*_t49*params->b[9]*tau_s + 0.20e2*_t122*_t27*params->b[1]*tau_s + 0.20e2*_t122*_t27*params->b[2]*tau_s + 0.60e2*_t122*_t28*_t33*params->b[2]*tau_s + 0.180e3*_t122*_t28*_t33*params->b[3]*tau_s + 0.120e3*_t122*_t28*_t33*params->b[4]*tau_s + 0.120e3*_t122*_t31*_t36*params->b[3]*tau_s + 0.320e3*_t122*_t31*_t36*params->b[4]*tau_s + 0.200e3*_t122*_t31*_t36*params->b[5]*tau_s + 0.200e3*_t122*_t34*_t39*params->b[4]*tau_s + 0.500e3*_t122*_t34*_t39*params->b[5]*tau_s + 0.300e3*_t122*_t34*_t39*params->b[6]*tau_s + 0.300e3*_t122*_t37*_t42*params->b[5]*tau_s + 0.720e3*_t122*_t37*_t42*params->b[6]*tau_s + 0.420e3*_t122*_t37*_t42*params->b[7]*tau_s + 0.420e3*_t122*_t40*_t45*params->b[6]*tau_s + 0.980e3*_t122*_t40*_t45*params->b[7]*tau_s + 0.560e3*_t122*_t40*_t45*params->b[8]*tau_s + 0.560e3*_t122*_t43*_t48*params->b[7]*tau_s + 0.1280e4*_t122*_t43*_t48*params->b[8]*tau_s + 0.720e3*_t122*_t43*_t48*params->b[9]*tau_s - _t202*_t719 - _t208*_t736 - _t215*_t740 - _t222*_t746 - _t229*_t751 - _t357 - _t362*_t60 - _t365 - _t373 - _t374 - _t377 - _t378 - _t379 - _t382 - _t383 - _t386 - _t387 - _t390 - _t391 - _t394 - _t395 - _t398 - _t399 - _t402 - _t403 - _t406 - _t407 - _t415*_t713 - _t469*_t720 - _t478*_t725 - _t487*_t733 - _t493*_t738 - _t496*_t739 - _t503*_t745 - _t506*_t748 - _t511*_t750 - _t517*_t756 - _t520*_t757 - _t522*_t758 - _t590*_t721 - _t618*_t722 - _t626*_t728 - _t633*_t735 - _t644*_t742 - _t654*_t749 - _t708*_t711 - _t714*params->b[3] - 0.50e2 / 0.3e1*_t715*_t716 - _t724*params->b[10] - _t726*_t727 - _t729*_t730 - _t731*_t732 - _t743*_t744 - _t753*params->b[6] - _t754*_t755 - _t758*_t765 - _t759*_t760 - _t761*params->b[8] - _t763*params->b[8] - _t764*params->b[8] - _t766*params->b[9] - _t767*params->b[9] - _t768*params->b[9];
  const double _t770 = _t710*params->a[2];
  const double _t771 = _t473*params->a[10];
  const double _t772 = _t479*params->a[10];
  const double _t773 = _t475*params->a[11];
  const double _t774 = _t483*params->a[11];
  const double _t775 = _t479*params->a[11];
  const double _t776 = _t36*params->a[2];
  const double _t777 = _t42*params->a[4];
  const double _t778 = _t36*params->a[5];
  const double _t779 = _t42*params->a[7];
  const double _t780 = _t45*params->a[8];
  const double _t781 = 0.20e2*_t122*_t19*_t30*params->a[1]*tau_s + 0.80e2*_t122*_t19*_t30*params->a[2]*tau_s + 0.60e2*_t122*_t19*_t30*params->a[3]*tau_s + 0.1320e4*_t122*_t199*_t25*params->a[11]*tau_s + 0.900e3*_t122*_t21*_t46*params->a[10]*tau_s + 0.720e3*_t122*_t21*_t46*params->a[8]*tau_s + 0.1620e4*_t122*_t21*_t46*params->a[9]*tau_s + 0.1100e4*_t122*_t22*_t71*params->a[10]*tau_s + 0.2420e4*_t122*_t22*_t71*params->a[11]*tau_s + 0.2000e4*_t122*_t24*_t49*params->a[10]*tau_s + 0.1100e4*_t122*_t24*_t49*params->a[11]*tau_s + 0.900e3*_t122*_t24*_t49*params->a[9]*tau_s + 0.20e2*_t122*_t27*params->a[1]*tau_s + 0.20e2*_t122*_t27*params->a[2]*tau_s + 0.60e2*_t122*_t28*_t33*params->a[2]*tau_s + 0.180e3*_t122*_t28*_t33*params->a[3]*tau_s + 0.120e3*_t122*_t28*_t33*params->a[4]*tau_s + 0.120e3*_t122*_t31*_t36*params->a[3]*tau_s + 0.320e3*_t122*_t31*_t36*params->a[4]*tau_s + 0.200e3*_t122*_t31*_t36*params->a[5]*tau_s + 0.200e3*_t122*_t34*_t39*params->a[4]*tau_s + 0.500e3*_t122*_t34*_t39*params->a[5]*tau_s + 0.300e3*_t122*_t34*_t39*params->a[6]*tau_s + 0.300e3*_t122*_t37*_t42*params->a[5]*tau_s + 0.720e3*_t122*_t37*_t42*params->a[6]*tau_s + 0.420e3*_t122*_t37*_t42*params->a[7]*tau_s + 0.420e3*_t122*_t40*_t45*params->a[6]*tau_s + 0.980e3*_t122*_t40*_t45*params->a[7]*tau_s + 0.560e3*_t122*_t40*_t45*params->a[8]*tau_s + 0.560e3*_t122*_t43*_t48*params->a[7]*tau_s + 0.1280e4*_t122*_t43*_t48*params->a[8]*tau_s + 0.720e3*_t122*_t43*_t48*params->a[9]*tau_s - _t415*_t770 - _t436 - _t437 - _t438 - _t439 - _t440 - _t441 - _t442 - _t443 - _t444 - _t445 - _t446 - _t447 - _t448 - _t449 - _t450 - _t451 - _t452 - _t453 - _t454 - _t455 - _t456 - _t457 - _t533*_t719 - _t534*_t720 - _t536*_t725 - _t538*_t733 - _t539*_t736 - _t540*_t738 - _t541*_t739 - _t542*_t740 - _t543*_t745 - _t544*_t746 - _t545*_t748 - _t546*_t750 - _t547*_t751 - _t548*_t756 - _t549*_t757 - _t550*_t758 - _t552*_t758 - 0.50e2 / 0.3e1*_t680*_t718 - _t681*_t721 - _t684*_t749 - _t714*params->a[1] - _t714*params->a[3] - _t722*_t771 - _t724*params->a[10] - _t727*_t772 - _t728*_t773 - _t730*_t774 - _t732*_t775 - _t735*_t776 - _t742*_t777 - _t744*_t778 - _t753*params->a[6] - _t755*_t779 - _t760*_t780 - _t761*params->a[8] - _t763*params->a[8] - _t764*params->a[8] - _t766*params->a[9] - _t767*params->a[9] - _t768*params->a[9];
  const double _t782 = _t116*_t351 + _t12*_t769 + _t321*_t355 + _t55*_t781 - _t690*_t704 + _t703*sigma_ss - _t707*sigma_ss;
  const double _t784 = _t347*_t563;
  const double _t785 = 1.9059950907617525e-5*_t142;
  const double _t786 = 0.001150481508724883*sigma_ss;
  const double _t787 = xc_powr(n_s, -38, 3);
  const double _t788 = _t569*_t787;
  const double _t789 = 0.00033464485518810527*_t142*_t348 - 1.4403508267125681e-6*_t346*_t788 + _t349 - 0.0038860019932499996*_t350*sigma_ss;
  const double _t790 = _t125*_t329;
  const double _t791 = _t695*sigma_ss;
  const double _t792 = 0.2e1*_t328;
  const double _t793 = _t128*_t458 + _t174*_t792 + _t342 - _t344*_t786 - _t354 + _t435*_t557 + _t56*_t789 + _t784*_t785 + _t790*_t791;
  const double _t795 = (0.1e1 / M_PI);
  const double _t802 = xc_powi(n_s, -11);
  const double _t803 = _t563*_t802;
  const double _t804 = 5.0826535753646719e-5*_t346;
  const double _t805 = xc_powr(n_s, -17, 3);
  const double _t806 = 0.23472031702484372*_t805;
  const double _t807 = _t135*_t806;
  const double _t808 = xc_powr(n_s, -25, 3);
  const double _t809 = _t273*_t808;
  const double _t810 = 0.0037497175099181377*_t142;
  const double _t811 = _t277*_t802;
  const double _t812 = 0.33554135999999996*_t139*_t805;
  const double _t813 = xc_powr(n_s, -41, 3);
  const double _t814 = (sigma_ss * sigma_ss * sigma_ss * sigma_ss);
  const double _t815 = 3.8409355379001821e-6*_t1*_t566*_t567*_t813*_t814 + 0.013591042868699998*_t123*_t124*_t142*_t15*_t808 - 0.00099737290173709803*_t346*_t811 - _t812*sigma_ss;
  const double _t816 = 0.15089163237311382*_t340;
  const double _t817 = _t352*_t816;
  const double _t818 = _t343*_t790;
  const double _t819 = 0.001022650229977674*_t142;
  const double _t820 = 0.3e1*_t351;
  const double _t821 = _t119*_t435;
  const double _t822 = _t8*_t821;
  const double _t823 = 0.04115226337448559*_t136;
  const double _t824 = _t822*_t823;
  const double _t825 = 0.3e1*_t143;
  const double _t826 = (0.440e3 / 0.27e2)*_t340;
  const double _t827 = (tau_s * tau_s * tau_s);
  const double _t828 = _t275*_t827;
  const double _t829 = _t30*_t828;
  const double _t830 = (0.250e3 / 0.9e1)*_t829;
  const double _t831 = (0.400e3 / 0.9e1)*_t141;
  const double _t832 = _t358*_t831;
  const double _t833 = _t19*_t826;
  const double _t834 = (0.880e3 / 0.27e2)*_t340;
  const double _t835 = _t19*_t834;
  const double _t836 = _t19*_t828;
  const double _t837 = (0.250e3 / 0.9e1)*_t836;
  const double _t838 = (0.500e3 / 0.3e1)*_t836;
  const double _t839 = 0.250e3*_t836;
  const double _t840 = (0.1000e4 / 0.9e1)*_t836;
  const double _t841 = _t180*_t708;
  const double _t842 = _t141*_t358;
  const double _t843 = (0.1600e4 / 0.9e1)*_t842;
  const double _t844 = (0.400e3 / 0.3e1)*_t842;
  const double _t845 = _t180*_t844;
  const double _t846 = (0.4400e4 / 0.27e2)*_t340;
  const double _t847 = _t65*_t846;
  const double _t848 = (0.4840e4 / 0.27e2)*_t340;
  const double _t849 = _t67*_t848;
  const double _t850 = (0.440e3 / 0.9e1)*_t340;
  const double _t851 = _t74*_t850;
  const double _t852 = (0.1760e4 / 0.27e2)*_t340;
  const double _t853 = _t78*_t852;
  const double _t854 = (0.2200e4 / 0.27e2)*_t340;
  const double _t855 = _t82*_t854;
  const double _t856 = (0.880e3 / 0.9e1)*_t340;
  const double _t857 = _t856*_t86;
  const double _t858 = (0.3080e4 / 0.27e2)*_t340;
  const double _t859 = _t858*_t90;
  const double _t860 = (0.3520e4 / 0.27e2)*_t340;
  const double _t861 = _t860*_t94;
  const double _t862 = (0.440e3 / 0.3e1)*_t340;
  const double _t863 = _t862*_t98;
  const double _t864 = (0.10000e5 / 0.3e1)*_t828;
  const double _t865 = _t475*_t828;
  const double _t866 = 0.12500e5*_t865;
  const double _t867 = (0.137500e6 / 0.9e1)*_t828;
  const double _t868 = (0.55000e5 / 0.9e1)*_t828;
  const double _t869 = (0.13750e5 / 0.3e1)*_t828;
  const double _t870 = (0.151250e6 / 0.9e1)*_t828;
  const double _t871 = (0.60500e5 / 0.3e1)*_t828;
  const double _t872 = (0.71500e5 / 0.9e1)*_t828;
  const double _t873 = _t28*_t828;
  const double _t874 = (0.1000e4 / 0.9e1)*_t873;
  const double _t875 = 0.500e3*_t873;
  const double _t876 = _t31*_t828;
  const double _t877 = (0.2500e4 / 0.9e1)*_t876;
  const double _t878 = (0.2000e4 / 0.3e1)*_t873;
  const double _t879 = (0.10000e5 / 0.9e1)*_t876;
  const double _t880 = _t34*_t828;
  const double _t881 = (0.5000e4 / 0.9e1)*_t880;
  const double _t882 = (0.2500e4 / 0.9e1)*_t873;
  const double _t883 = (0.12500e5 / 0.9e1)*_t876;
  const double _t884 = (0.6250e4 / 0.3e1)*_t880;
  const double _t885 = _t37*_t828;
  const double _t886 = (0.8750e4 / 0.9e1)*_t885;
  const double _t887 = (0.5000e4 / 0.9e1)*_t876;
  const double _t888 = 0.2500e4*_t880;
  const double _t889 = 0.3500e4*_t885;
  const double _t890 = _t514*_t828;
  const double _t891 = (0.14000e5 / 0.9e1)*_t890;
  const double _t892 = (0.8750e4 / 0.9e1)*_t880;
  const double _t893 = (0.12250e5 / 0.3e1)*_t885;
  const double _t894 = (0.49000e5 / 0.9e1)*_t828;
  const double _t895 = (0.7000e4 / 0.3e1)*_t828;
  const double _t896 = (0.14000e5 / 0.9e1)*_t885;
  const double _t897 = (0.56000e5 / 0.9e1)*_t890;
  const double _t898 = _t473*_t828;
  const double _t899 = 0.8000e4*_t898;
  const double _t900 = (0.10000e5 / 0.3e1)*_t865;
  const double _t901 = 0.9000e4*_t898;
  const double _t902 = 0.11250e5*_t865;
  const double _t903 = _t483*_t869;
  const double _t904 = 0.2000e4*_t842;
  const double _t905 = (0.40000e5 / 0.9e1)*_t842;
  const double _t906 = (0.22000e5 / 0.9e1)*_t842;
  const double _t907 = _t189*params->b[11];
  const double _t908 = (0.48400e5 / 0.9e1)*_t842;
  const double _t909 = (0.8800e4 / 0.3e1)*_t842;
  const double _t910 = 0.400e3*_t842;
  const double _t911 = (0.800e3 / 0.3e1)*_t842;
  const double _t912 = _t204*_t911;
  const double _t913 = (0.6400e4 / 0.9e1)*_t842;
  const double _t914 = (0.4000e4 / 0.9e1)*_t842;
  const double _t915 = _t211*_t914;
  const double _t916 = (0.10000e5 / 0.9e1)*_t842;
  const double _t917 = (0.2000e4 / 0.3e1)*_t842;
  const double _t918 = _t218*_t917;
  const double _t919 = 0.1600e4*_t842;
  const double _t920 = (0.2800e4 / 0.3e1)*_t842;
  const double _t921 = _t226*_t920;
  const double _t922 = (0.19600e5 / 0.9e1)*_t842;
  const double _t923 = (0.11200e5 / 0.9e1)*_t842;
  const double _t924 = _t232*_t923;
  const double _t925 = (0.25600e5 / 0.9e1)*_t842;
  const double _t926 = _t187*_t919;
  const double _t927 = _t239*_t919;
  const double _t928 = 0.3600e4*_t842;
  const double _t929 = _t189*_t904;
  const double _t930 = _t102*_t862*tau_s + _t144*_t826*tau_s + _t146*_t833 - _t148*_t832 + _t148*_t835*tau_s + _t155*_t834*tau_s - _t182*_t843 - _t188*_t904 - _t190*_t905 - _t194*_t906 - _t197*_t908 - _t200*_t909 + _t202*_t838 - _t203*_t844 - _t205*_t910 + _t208*_t875 - _t209*_t911 - _t212*_t913 + _t215*_t879 - _t216*_t914 - _t219*_t916 + _t222*_t884 - _t223*_t917 - _t227*_t919 + _t229*_t889 - _t230*_t920 - _t233*_t922 - _t237*_t923 - _t240*_t925 - _t244*_t928 - _t359*_t831 + _t469*_t839 + _t478*_t867 + _t487*_t872 + _t493*_t877 + _t496*_t878 + _t503*_t883 + _t506*_t886 + _t511*_t888 + _t517*_t893 + _t520*_t894 + _t522*_t895 + _t585*_t837 + _t590*_t840 + _t618*_t864 + _t626*_t869 + _t633*_t874 + _t644*_t881 + _t654*_t887 + _t68*_t846*tau_s + (0.500e3 / 0.9e1)*_t712*_t828 + _t726*_t868 + _t729*_t870 + _t73*_t848*tau_s + _t731*_t871 + _t743*_t882 + _t754*_t892 + _t759*_t896 + _t765*_t895 + _t79*_t850*tau_s + _t83*_t852*tau_s + _t830*params->b[1] + _t830*params->b[3] - _t831*_t841 - _t845*params->b[3] + _t847*params->b[10]*tau_s + _t849*params->b[11]*tau_s + _t851*params->b[3]*tau_s + _t853*params->b[4]*tau_s + _t854*_t87*tau_s + _t855*params->b[5]*tau_s + _t856*_t91*tau_s + _t857*params->b[6]*tau_s + _t858*_t95*tau_s + _t859*params->b[7]*tau_s + _t860*_t99*tau_s + _t861*params->b[8]*tau_s + _t863*params->b[9]*tau_s + _t866*params->b[10] + _t891*params->b[6] + _t897*params->b[8] + _t899*params->b[8] + _t900*params->b[8] + _t901*params->b[9] + _t902*params->b[9] + _t903*params->b[9] - _t906*_t907 - _t912*params->b[4] - _t915*params->b[5] - _t918*params->b[6] - _t921*params->b[7] - _t924*params->b[8] - _t926*params->b[8] - _t927*params->b[9] - _t929*params->b[9];
  const double _t931 = _t180*params->a[1];
  const double _t932 = _t189*params->a[11];
  const double _t933 = -_t104*_t832 + _t104*_t833*tau_s + _t106*_t846*tau_s + _t108*_t848*tau_s + _t109*_t850*tau_s + _t110*_t852*tau_s + _t111*_t854*tau_s + _t112*_t856*tau_s + _t113*_t858*tau_s + _t114*_t860*tau_s + _t115*_t862*tau_s + _t171*_t826*tau_s - _t172*_t832 + _t172*_t835*tau_s + _t173*_t834*tau_s - _t248*_t843 - _t249*_t904 - _t250*_t905 - _t251*_t906 - _t252*_t908 - _t253*_t909 - _t254*_t844 - _t255*_t910 - _t256*_t911 - _t257*_t913 - _t258*_t914 - _t259*_t916 - _t260*_t917 - _t261*_t919 - _t262*_t920 - _t263*_t922 - _t264*_t923 - _t265*_t925 - _t266*_t928 + _t533*_t838 + _t534*_t839 + _t536*_t867 + _t538*_t872 + _t539*_t875 + _t540*_t877 + _t541*_t878 + _t542*_t879 + _t543*_t883 + _t544*_t884 + _t545*_t886 + _t546*_t888 + _t547*_t889 + _t548*_t893 + _t549*_t894 + _t550*_t895 + _t552*_t895 + _t680*_t837 + _t681*_t840 + _t684*_t887 + _t771*_t864 + _t772*_t868 + _t773*_t869 + _t774*_t870 + _t775*_t871 + _t776*_t874 + _t777*_t881 + _t778*_t882 + _t779*_t892 + _t780*_t896 + (0.500e3 / 0.9e1)*_t829*params->a[2] + _t830*params->a[1] + _t830*params->a[3] - _t832*_t931 - _t845*params->a[3] + _t847*params->a[10]*tau_s + _t849*params->a[11]*tau_s + _t851*params->a[3]*tau_s + _t853*params->a[4]*tau_s + _t855*params->a[5]*tau_s + _t857*params->a[6]*tau_s + _t859*params->a[7]*tau_s + _t861*params->a[8]*tau_s + _t863*params->a[9]*tau_s + _t866*params->a[10] + _t891*params->a[6] + _t897*params->a[8] + _t899*params->a[8] + _t900*params->a[8] + _t901*params->a[9] + _t902*params->a[9] + _t903*params->a[9] - _t906*_t932 - _t912*params->a[4] - _t915*params->a[5] - _t918*params->a[6] - _t921*params->a[7] - _t924*params->a[8] - _t926*params->a[8] - _t927*params->a[9] - _t929*params->a[9];
  const double _t934 = _t12*_t930 + _t174*_t820 + _t458*_t825 + _t55*_t933 + _t56*_t815 - _t803*_t804 - _t807*sigma_ss + _t809*_t810 + _t817*sigma_ss - _t818*_t819 - _t824*sigma_ss;
#endif
#if _KMAX >= 4
  const double _t936 = xc_powr(n_s, -20, 3);
  const double _t937 = _t33*_t936;
  const double _t938 = 0.24e2*_t937;
  const double _t939 = 0.72e2*_t937;
  const double _t940 = _t19*_t936;
  const double _t941 = _t36*_t940;
  const double _t942 = 0.24e2*_t941;
  const double _t943 = 0.192e3*_t941;
  const double _t944 = 0.432e3*_t940;
  const double _t945 = 0.384e3*_t940;
  const double _t946 = 0.120e3*_t941;
  const double _t947 = _t21*_t40;
  const double _t948 = _t936*_t947;
  const double _t949 = 0.5040e4*_t948;
  const double _t950 = _t24*_t43;
  const double _t951 = _t936*_t950;
  const double _t952 = 0.28800e5*_t951;
  const double _t953 = _t46*_t936;
  const double _t954 = _t199*_t49;
  const double _t955 = _t936*_t954;
  const double _t956 = 0.52800e5*_t955;
  const double _t957 = _t22*_t486;
  const double _t958 = _t936*_t957;
  const double _t959 = 0.17160e5*_t958;
  const double _t960 = 0.7920e4*_t951;
  const double _t961 = _t71*_t953;
  const double _t962 = 0.43560e5*_t961;
  const double _t963 = 0.87120e5*_t955;
  const double _t964 = 0.75504e5*_t958;
  const double _t965 = xc_powi(_t17, -15);
  const double _t966 = _t72*_t965;
  const double _t967 = 0.24024e5*_t936;
  const double _t968 = _t28*_t936;
  const double _t969 = _t510*_t968;
  const double _t970 = 0.720e3*_t968;
  const double _t971 = _t31*_t936;
  const double _t972 = _t42*_t971;
  const double _t973 = 0.360e3*_t972;
  const double _t974 = 0.1440e4*_t968;
  const double _t975 = 0.1920e4*_t972;
  const double _t976 = _t34*_t936;
  const double _t977 = _t45*_t976;
  const double _t978 = 0.840e3*_t977;
  const double _t979 = 0.1200e4*_t968;
  const double _t980 = 0.3600e4*_t971;
  const double _t981 = 0.4200e4*_t976;
  const double _t982 = _t37*_t936;
  const double _t983 = _t48*_t982;
  const double _t984 = 0.1680e4*_t983;
  const double _t985 = 0.360e3*_t968;
  const double _t986 = 0.2880e4*_t971;
  const double _t987 = 0.7560e4*_t976;
  const double _t988 = 0.8064e4*_t983;
  const double _t989 = 0.3024e4*_t948;
  const double _t990 = 0.840e3*_t972;
  const double _t991 = 0.5880e4*_t976;
  const double _t992 = 0.14112e5*_t948;
  const double _t993 = 0.5040e4*_t951;
  const double _t994 = 0.1680e4*_t977;
  const double _t995 = 0.10752e5*_t983;
  const double _t996 = 0.24192e5*_t948;
  const double _t997 = 0.23040e5*_t951;
  const double _t998 = 0.7920e4*_t961;
  const double _t999 = 0.3024e4*_t983;
  const double _t1000 = 0.18144e5*_t948;
  const double _t1001 = 0.38880e5*_t951;
  const double _t1002 = 0.35640e5*_t961;
  const double _t1003 = 0.11880e5*_t955;
  const double _t1004 = _t107*_t965;
  const double _t1005 = _t276*_t564;
  const double _t1006 = _t120*_t568;
  const double _t1007 = (0.1e1 / (M_PI * M_PI * M_PI * M_PI * M_PI * M_PI * M_CBRTPI * M_CBRTPI));
  const double _t1008 = xc_powi(_t52, -5);
  const double _t1009 = _t119*sigma_ss;
  const double _t1010 = tau_s/xc_powr(n_s, 23, 3);
  const double _t1011 = 0.40e2*_t1010;
  const double _t1012 = 0.120e3*_t1010;
  const double _t1013 = _t19*_t36;
  const double _t1014 = _t1011*_t1013;
  const double _t1015 = _t1010*_t19;
  const double _t1016 = 0.320e3*_t1015;
  const double _t1017 = 0.720e3*_t1015;
  const double _t1018 = 0.640e3*_t1015;
  const double _t1019 = 0.200e3*_t1015;
  const double _t1020 = _t1010*params->b[10];
  const double _t1021 = 0.8400e4*_t947;
  const double _t1022 = _t1010*_t46;
  const double _t1023 = 0.99000e5*_t1022;
  const double _t1024 = 0.88000e5*_t954;
  const double _t1025 = 0.28600e5*_t957;
  const double _t1026 = _t1010*params->b[11];
  const double _t1027 = 0.72600e5*_t71;
  const double _t1028 = 0.145200e6*_t954;
  const double _t1029 = 0.125840e6*_t957;
  const double _t1030 = 0.40040e5*_t1010;
  const double _t1031 = _t39*params->b[2];
  const double _t1032 = _t1010*_t28;
  const double _t1033 = 0.200e3*_t1032;
  const double _t1034 = 0.1200e4*_t1032;
  const double _t1035 = _t42*params->b[3];
  const double _t1036 = _t1010*_t31;
  const double _t1037 = 0.600e3*_t1036;
  const double _t1038 = 0.2400e4*_t1032;
  const double _t1039 = 0.3200e4*_t1036;
  const double _t1040 = _t45*params->b[4];
  const double _t1041 = _t1010*_t34;
  const double _t1042 = 0.1400e4*_t1041;
  const double _t1043 = 0.2000e4*_t1032;
  const double _t1044 = 0.6000e4*_t1036;
  const double _t1045 = 0.7000e4*_t1041;
  const double _t1046 = _t1010*_t37;
  const double _t1047 = _t1046*_t48;
  const double _t1048 = 0.2800e4*_t1047;
  const double _t1049 = 0.600e3*_t1032;
  const double _t1050 = 0.4800e4*_t1036;
  const double _t1051 = 0.12600e5*_t1041;
  const double _t1052 = 0.13440e5*_t1047;
  const double _t1053 = _t1010*_t947;
  const double _t1054 = 0.5040e4*_t1053;
  const double _t1055 = 0.1400e4*_t1036;
  const double _t1056 = 0.9800e4*_t1041;
  const double _t1057 = 0.23520e5*_t1046;
  const double _t1058 = 0.23520e5*_t1053;
  const double _t1059 = _t1010*_t950;
  const double _t1060 = 0.8400e4*_t1059;
  const double _t1061 = 0.2800e4*_t1041;
  const double _t1062 = 0.17920e5*_t1047;
  const double _t1063 = 0.40320e5*_t1053;
  const double _t1064 = 0.38400e5*_t1059;
  const double _t1065 = _t1022*_t71;
  const double _t1066 = 0.13200e5*_t1065;
  const double _t1067 = 0.5040e4*_t1047;
  const double _t1068 = 0.30240e5*_t1053;
  const double _t1069 = 0.64800e5*_t1059;
  const double _t1070 = 0.59400e5*_t1065;
  const double _t1071 = _t954*params->b[9];
  const double _t1072 = 0.19800e5*_t1010;
  const double _t1073 = _t1011*_t33;
  const double _t1074 = _t71*params->a[10];
  const double _t1075 = _t1010*params->a[10];
  const double _t1076 = _t1010*params->a[11];
  const double _t1077 = _t39*params->a[2];
  const double _t1078 = _t42*params->a[3];
  const double _t1079 = _t45*params->a[4];
  const double _t1080 = _t48*params->a[7];
  const double _t1081 = _t954*params->a[9];
  const double _t1082 = _t125*_t574;
  const double _t1083 = _t270*_t276;
  const double _t1084 = _t1007*_t1008*_t15;
  const double _t1085 = (0.260e3 / 0.9e1)*_t122;
  const double _t1086 = _t1085*_t27;
  const double _t1087 = _t312*_t710;
  const double _t1088 = (0.560e3 / 0.3e1)*tau_s;
  const double _t1089 = xc_powr(n_s, -26, 3);
  const double _t1090 = (0.200e3 / 0.3e1)*_t1089;
  const double _t1091 = _t1089*_t358;
  const double _t1092 = 0.200e3*_t1091;
  const double _t1093 = (0.200e3 / 0.3e1)*_t1091;
  const double _t1094 = _t1085*_t180;
  const double _t1095 = (0.1040e4 / 0.9e1)*_t122;
  const double _t1096 = (0.260e3 / 0.3e1)*_t122;
  const double _t1097 = _t1096*_t180;
  const double _t1098 = _t312*_t716;
  const double _t1099 = _t660*_t716;
  const double _t1100 = _t666*_t716;
  const double _t1101 = (0.1120e4 / 0.3e1)*_t716*tau_s;
  const double _t1102 = 0.1300e4*_t122;
  const double _t1103 = (0.26000e5 / 0.9e1)*_t122;
  const double _t1104 = (0.14300e5 / 0.9e1)*_t122;
  const double _t1105 = _t1104*_t189;
  const double _t1106 = (0.31460e5 / 0.9e1)*_t122;
  const double _t1107 = (0.5720e4 / 0.3e1)*_t122;
  const double _t1108 = 0.260e3*_t122;
  const double _t1109 = (0.520e3 / 0.3e1)*_t122;
  const double _t1110 = _t1109*_t204;
  const double _t1111 = (0.4160e4 / 0.9e1)*_t122;
  const double _t1112 = (0.2600e4 / 0.9e1)*_t122;
  const double _t1113 = _t1112*_t211;
  const double _t1114 = (0.6500e4 / 0.9e1)*_t122;
  const double _t1115 = (0.1300e4 / 0.3e1)*_t122;
  const double _t1116 = _t1115*_t218;
  const double _t1117 = 0.1040e4*_t122;
  const double _t1118 = (0.1820e4 / 0.3e1)*_t122;
  const double _t1119 = _t1118*_t226;
  const double _t1120 = (0.12740e5 / 0.9e1)*_t122;
  const double _t1121 = (0.7280e4 / 0.9e1)*_t122;
  const double _t1122 = _t1121*_t232;
  const double _t1123 = (0.16640e5 / 0.9e1)*_t122;
  const double _t1124 = _t1117*_t187;
  const double _t1125 = _t1117*_t239;
  const double _t1126 = 0.2340e4*_t122;
  const double _t1127 = _t1102*_t189;
  const double _t1128 = _t1091*_t19;
  const double _t1129 = (0.1600e4 / 0.3e1)*_t1128;
  const double _t1130 = 0.1200e4*_t1128;
  const double _t1131 = (0.3200e4 / 0.3e1)*_t1128;
  const double _t1132 = (0.1000e4 / 0.3e1)*_t1128;
  const double _t1133 = _t709*tau_s;
  const double _t1134 = 0.11200e5*_t1133;
  const double _t1135 = _t475*_t709;
  const double _t1136 = 0.42000e5*_t1135*tau_s;
  const double _t1137 = (0.154000e6 / 0.3e1)*_t1133;
  const double _t1138 = (0.61600e5 / 0.3e1)*_t624*_t709;
  const double _t1139 = 0.15400e5*_t709;
  const double _t1140 = _t1139*tau_s;
  const double _t1141 = _t709*params->b[11];
  const double _t1142 = (0.169400e6 / 0.3e1)*_t629;
  const double _t1143 = 0.67760e5*_t624;
  const double _t1144 = (0.80080e5 / 0.3e1)*_t1133;
  const double _t1145 = _t1133*_t28;
  const double _t1146 = (0.1120e4 / 0.3e1)*_t1145;
  const double _t1147 = 0.1680e4*_t1145;
  const double _t1148 = _t1133*_t31;
  const double _t1149 = (0.2800e4 / 0.3e1)*_t1148;
  const double _t1150 = 0.2240e4*_t1145;
  const double _t1151 = (0.11200e5 / 0.3e1)*_t1148;
  const double _t1152 = _t1133*_t34;
  const double _t1153 = (0.5600e4 / 0.3e1)*_t1152;
  const double _t1154 = (0.2800e4 / 0.3e1)*_t1145;
  const double _t1155 = (0.14000e5 / 0.3e1)*_t1148;
  const double _t1156 = 0.7000e4*_t1152;
  const double _t1157 = _t1133*_t37;
  const double _t1158 = (0.9800e4 / 0.3e1)*_t1157;
  const double _t1159 = (0.5600e4 / 0.3e1)*_t1148;
  const double _t1160 = 0.8400e4*_t1152;
  const double _t1161 = 0.11760e5*_t1157;
  const double _t1162 = _t514*params->b[6];
  const double _t1163 = (0.15680e5 / 0.3e1)*_t1133;
  const double _t1164 = (0.9800e4 / 0.3e1)*_t1152;
  const double _t1165 = _t37*_t517;
  const double _t1166 = 0.13720e5*_t1133;
  const double _t1167 = (0.54880e5 / 0.3e1)*_t1133;
  const double _t1168 = 0.7840e4*_t1133;
  const double _t1169 = (0.15680e5 / 0.3e1)*_t37*_t45*_t709;
  const double _t1170 = _t514*_t709;
  const double _t1171 = (0.62720e5 / 0.3e1)*_t1170;
  const double _t1172 = _t473*_t709;
  const double _t1173 = 0.26880e5*_t1172;
  const double _t1174 = 0.11200e5*_t1135;
  const double _t1175 = 0.30240e5*_t1172;
  const double _t1176 = 0.37800e5*_t1135;
  const double _t1177 = 0.14000e5*_t1091;
  const double _t1178 = _t947*params->b[10];
  const double _t1179 = _t1091*params->b[10];
  const double _t1180 = 0.80000e5*_t950;
  const double _t1181 = _t193*_t46;
  const double _t1182 = 0.165000e6*_t1091;
  const double _t1183 = (0.440000e6 / 0.3e1)*_t954;
  const double _t1184 = (0.143000e6 / 0.3e1)*_t957;
  const double _t1185 = 0.22000e5*_t1091;
  const double _t1186 = _t950*params->b[11];
  const double _t1187 = _t1091*params->b[11];
  const double _t1188 = _t46*_t71;
  const double _t1189 = 0.121000e6*_t1188;
  const double _t1190 = 0.242000e6*_t954;
  const double _t1191 = (0.629200e6 / 0.3e1)*_t957;
  const double _t1192 = (0.200200e6 / 0.3e1)*_t1091;
  const double _t1193 = _t1091*_t28;
  const double _t1194 = (0.1000e4 / 0.3e1)*_t1193;
  const double _t1195 = 0.2000e4*_t1193;
  const double _t1196 = 0.1000e4*_t1091;
  const double _t1197 = _t1035*_t31;
  const double _t1198 = 0.4000e4*_t1193;
  const double _t1199 = _t1091*_t31;
  const double _t1200 = (0.16000e5 / 0.3e1)*_t1199;
  const double _t1201 = _t1091*_t34;
  const double _t1202 = (0.7000e4 / 0.3e1)*_t1201;
  const double _t1203 = (0.10000e5 / 0.3e1)*_t1193;
  const double _t1204 = 0.10000e5*_t1199;
  const double _t1205 = (0.35000e5 / 0.3e1)*_t1201;
  const double _t1206 = _t37*_t48;
  const double _t1207 = _t1091*_t1206;
  const double _t1208 = (0.14000e5 / 0.3e1)*_t1207;
  const double _t1209 = _t1196*_t28;
  const double _t1210 = 0.8000e4*_t1199;
  const double _t1211 = 0.21000e5*_t1201;
  const double _t1212 = _t1091*params->b[6];
  const double _t1213 = 0.22400e5*_t1206;
  const double _t1214 = (0.7000e4 / 0.3e1)*_t1199;
  const double _t1215 = (0.49000e5 / 0.3e1)*_t1201;
  const double _t1216 = 0.39200e5*_t1091;
  const double _t1217 = _t1216*_t37;
  const double _t1218 = _t947*params->b[7];
  const double _t1219 = _t1177*_t950;
  const double _t1220 = (0.14000e5 / 0.3e1)*_t1201;
  const double _t1221 = _t1091*params->b[8];
  const double _t1222 = 0.67200e5*_t947;
  const double _t1223 = 0.64000e5*_t950;
  const double _t1224 = _t1185*_t1188;
  const double _t1225 = _t1091*params->b[9];
  const double _t1226 = 0.8400e4*_t1206;
  const double _t1227 = 0.50400e5*_t947;
  const double _t1228 = 0.108000e6*_t950;
  const double _t1229 = 0.99000e5*_t1188;
  const double _t1230 = 0.33000e5*_t1091;
  const double _t1231 = _t1013*params->a[1];
  const double _t1232 = _t709*params->a[11];
  const double _t1233 = _t514*params->a[6];
  const double _t1234 = _t37*_t548;
  const double _t1235 = _t947*params->a[10];
  const double _t1236 = _t1091*params->a[10];
  const double _t1237 = _t1074*_t46;
  const double _t1238 = _t950*params->a[11];
  const double _t1239 = _t1091*params->a[11];
  const double _t1240 = _t1078*_t31;
  const double _t1241 = _t1091*params->a[6];
  const double _t1242 = _t947*params->a[7];
  const double _t1243 = _t1091*params->a[8];
  const double _t1244 = _t1091*params->a[9];
  const double _t1245 = _t125*_t705;
  const double _t1246 = _t276*_t329;
  const double _t1248 = _t8*sigma_ss;
  const double _t1249 = _t1009*_t8;
  const double _t1250 = (0.3280e4 / 0.27e2)*_t141;
  const double _t1251 = _t1250*tau_s;
  const double _t1252 = _t827/xc_powr(n_s, 29, 3);
  const double _t1253 = (0.1000e4 / 0.9e1)*_t1252;
  const double _t1254 = (0.1000e4 / 0.3e1)*_t1252;
  const double _t1255 = _t141*tau_s;
  const double _t1256 = (0.13120e5 / 0.27e2)*_t1255;
  const double _t1257 = (0.3280e4 / 0.9e1)*_t1255;
  const double _t1258 = _t1257*_t180;
  const double _t1259 = _t1013*params->b[1];
  const double _t1260 = _t1252*_t19;
  const double _t1261 = (0.8000e4 / 0.9e1)*_t1260;
  const double _t1262 = 0.2000e4*_t1260;
  const double _t1263 = (0.16000e5 / 0.9e1)*_t1260;
  const double _t1264 = (0.5000e4 / 0.9e1)*_t1260;
  const double _t1265 = (0.16400e5 / 0.3e1)*_t1255;
  const double _t1266 = (0.328000e6 / 0.27e2)*_t1255;
  const double _t1267 = (0.180400e6 / 0.27e2)*_t1255;
  const double _t1268 = (0.396880e6 / 0.27e2)*_t1255;
  const double _t1269 = (0.72160e5 / 0.9e1)*_t1255;
  const double _t1270 = (0.3280e4 / 0.3e1)*_t1255;
  const double _t1271 = (0.6560e4 / 0.9e1)*_t1255;
  const double _t1272 = _t1271*_t204;
  const double _t1273 = (0.52480e5 / 0.27e2)*_t1255;
  const double _t1274 = (0.32800e5 / 0.27e2)*_t1255;
  const double _t1275 = _t1274*_t211;
  const double _t1276 = (0.82000e5 / 0.27e2)*_t1255;
  const double _t1277 = (0.16400e5 / 0.9e1)*_t1255;
  const double _t1278 = _t1277*_t218;
  const double _t1279 = (0.13120e5 / 0.3e1)*_t1255;
  const double _t1280 = (0.22960e5 / 0.9e1)*_t1255;
  const double _t1281 = _t1280*_t226;
  const double _t1282 = (0.160720e6 / 0.27e2)*_t1255;
  const double _t1283 = (0.91840e5 / 0.27e2)*_t1255;
  const double _t1284 = (0.91840e5 / 0.27e2)*_t141*_t232;
  const double _t1285 = (0.209920e6 / 0.27e2)*_t1255;
  const double _t1286 = (0.13120e5 / 0.3e1)*_t141;
  const double _t1287 = _t141*_t675;
  const double _t1288 = 0.9840e4*_t1255;
  const double _t1289 = (0.16400e5 / 0.3e1)*_t189;
  const double _t1290 = (0.70000e5 / 0.3e1)*_t1252;
  const double _t1291 = _t1252*params->b[10];
  const double _t1292 = (0.400000e6 / 0.3e1)*_t950;
  const double _t1293 = 0.275000e6*_t1252;
  const double _t1294 = (0.2200000e7 / 0.9e1)*_t954;
  const double _t1295 = (0.715000e6 / 0.9e1)*_t957;
  const double _t1296 = (0.110000e6 / 0.3e1)*_t1252;
  const double _t1297 = _t1252*params->b[11];
  const double _t1298 = (0.605000e6 / 0.3e1)*_t1188;
  const double _t1299 = (0.1210000e7 / 0.3e1)*_t954;
  const double _t1300 = (0.3146000e7 / 0.9e1)*_t957;
  const double _t1301 = (0.1001000e7 / 0.9e1)*_t1252;
  const double _t1302 = _t1252*_t28;
  const double _t1303 = (0.5000e4 / 0.9e1)*_t1302;
  const double _t1304 = (0.10000e5 / 0.3e1)*_t1302;
  const double _t1305 = (0.5000e4 / 0.3e1)*_t1252;
  const double _t1306 = (0.20000e5 / 0.3e1)*_t1302;
  const double _t1307 = _t1252*_t31;
  const double _t1308 = (0.80000e5 / 0.9e1)*_t644;
  const double _t1309 = _t1252*_t34;
  const double _t1310 = (0.35000e5 / 0.9e1)*_t1309;
  const double _t1311 = (0.50000e5 / 0.9e1)*_t1302;
  const double _t1312 = (0.50000e5 / 0.3e1)*_t1307;
  const double _t1313 = (0.175000e6 / 0.9e1)*_t1309;
  const double _t1314 = _t1206*_t1252;
  const double _t1315 = (0.70000e5 / 0.9e1)*_t1314;
  const double _t1316 = (0.5000e4 / 0.3e1)*_t1302;
  const double _t1317 = (0.40000e5 / 0.3e1)*_t1307;
  const double _t1318 = 0.35000e5*_t1309;
  const double _t1319 = (0.112000e6 / 0.3e1)*_t1314;
  const double _t1320 = _t1252*_t947;
  const double _t1321 = 0.14000e5*_t1320;
  const double _t1322 = (0.35000e5 / 0.9e1)*_t1307;
  const double _t1323 = (0.245000e6 / 0.9e1)*_t1309;
  const double _t1324 = (0.196000e6 / 0.3e1)*_t1252;
  const double _t1325 = _t1324*_t37;
  const double _t1326 = _t1290*_t950;
  const double _t1327 = (0.70000e5 / 0.9e1)*_t1309;
  const double _t1328 = _t1252*params->b[8];
  const double _t1329 = (0.448000e6 / 0.9e1)*_t1206;
  const double _t1330 = 0.112000e6*_t1320;
  const double _t1331 = (0.320000e6 / 0.3e1)*_t950;
  const double _t1332 = _t1252*params->b[9];
  const double _t1333 = 0.14000e5*_t1206;
  const double _t1334 = 0.180000e6*_t950;
  const double _t1335 = 0.165000e6*_t1188;
  const double _t1336 = 0.55000e5*_t1252;
  const double _t1337 = _t1252*params->a[10];
  const double _t1338 = _t1252*params->a[11];
  const double _t1339 = (0.80000e5 / 0.9e1)*_t777;
  const double _t1340 = _t1252*params->a[8];
  const double _t1341 = _t1188*params->a[8];
  const double _t1342 = _t1252*params->a[9];
  const double _t1343 = _t125*_t821;
  const double _t1344 = _t346/xc_powi(n_s, 12);
  const double _t1345 = _t936*sigma_ss;
  const double _t1346 = _t814/xc_powr(n_s, 44, 3);
  const double _t1347 = _t142/xc_powr(n_s, 28, 3);
  const double _t1348 = _t805*tau_s;
  const double _t1349 = (0.6160e4 / 0.81e2)*_t1348;
  const double _t1350 = _t565*(tau_s * tau_s * tau_s * tau_s);
  const double _t1351 = (0.5000e4 / 0.27e2)*_t1350;
  const double _t1352 = (0.5000e4 / 0.9e1)*_t1350;
  const double _t1353 = _t326*_t827;
  const double _t1354 = (0.4000e4 / 0.9e1)*_t1353;
  const double _t1355 = _t1354*_t30;
  const double _t1356 = (0.8000e4 / 0.9e1)*_t1353;
  const double _t1357 = (0.27200e5 / 0.81e2)*_t343;
  const double _t1358 = _t1357*_t358;
  const double _t1359 = (0.12320e5 / 0.81e2)*_t1348;
  const double _t1360 = _t1359*_t19;
  const double _t1361 = _t1350*_t19;
  const double _t1362 = (0.40000e5 / 0.27e2)*_t1361;
  const double _t1363 = (0.10000e5 / 0.3e1)*_t1361;
  const double _t1364 = (0.80000e5 / 0.27e2)*_t1361;
  const double _t1365 = (0.25000e5 / 0.27e2)*_t1361;
  const double _t1366 = _t1354*_t19;
  const double _t1367 = (0.8000e4 / 0.3e1)*_t1353;
  const double _t1368 = _t1353*_t19;
  const double _t1369 = 0.4000e4*_t1368;
  const double _t1370 = (0.16000e5 / 0.9e1)*_t1368;
  const double _t1371 = _t343*_t358;
  const double _t1372 = (0.108800e6 / 0.81e2)*_t1371;
  const double _t1373 = (0.27200e5 / 0.27e2)*_t1371;
  const double _t1374 = _t1373*_t180;
  const double _t1375 = (0.61600e5 / 0.81e2)*_t1348;
  const double _t1376 = _t1375*_t65;
  const double _t1377 = (0.67760e5 / 0.81e2)*_t1348;
  const double _t1378 = _t1377*_t67;
  const double _t1379 = (0.6160e4 / 0.27e2)*_t1348;
  const double _t1380 = _t1379*_t74;
  const double _t1381 = (0.24640e5 / 0.81e2)*_t1348;
  const double _t1382 = _t1381*_t78;
  const double _t1383 = (0.30800e5 / 0.81e2)*_t1348;
  const double _t1384 = _t1383*_t82;
  const double _t1385 = (0.12320e5 / 0.27e2)*_t1348;
  const double _t1386 = _t1385*_t86;
  const double _t1387 = (0.43120e5 / 0.81e2)*_t1348;
  const double _t1388 = _t1387*_t90;
  const double _t1389 = (0.49280e5 / 0.81e2)*_t1348;
  const double _t1390 = _t1389*_t94;
  const double _t1391 = (0.6160e4 / 0.9e1)*_t1348;
  const double _t1392 = _t1391*_t98;
  const double _t1393 = (0.350000e6 / 0.9e1)*_t1350;
  const double _t1394 = _t1350*_t950;
  const double _t1395 = (0.2000000e7 / 0.9e1)*_t1394;
  const double _t1396 = (0.1375000e7 / 0.3e1)*_t1350;
  const double _t1397 = _t1350*params->b[10];
  const double _t1398 = (0.11000000e8 / 0.27e2)*_t954;
  const double _t1399 = (0.3575000e7 / 0.27e2)*_t957;
  const double _t1400 = (0.550000e6 / 0.9e1)*_t1350;
  const double _t1401 = _t1350*params->b[11];
  const double _t1402 = (0.3025000e7 / 0.9e1)*_t1188;
  const double _t1403 = (0.6050000e7 / 0.9e1)*_t954;
  const double _t1404 = (0.15730000e8 / 0.27e2)*_t957;
  const double _t1405 = (0.5005000e7 / 0.27e2)*_t1350;
  const double _t1406 = _t1350*_t28;
  const double _t1407 = (0.25000e5 / 0.27e2)*_t1406;
  const double _t1408 = (0.50000e5 / 0.9e1)*_t1406;
  const double _t1409 = (0.25000e5 / 0.9e1)*_t1350;
  const double _t1410 = (0.100000e6 / 0.9e1)*_t1406;
  const double _t1411 = _t1350*_t31;
  const double _t1412 = (0.400000e6 / 0.27e2)*_t1411;
  const double _t1413 = _t1350*_t34;
  const double _t1414 = (0.175000e6 / 0.27e2)*_t1413;
  const double _t1415 = (0.250000e6 / 0.27e2)*_t1406;
  const double _t1416 = (0.250000e6 / 0.9e1)*_t1411;
  const double _t1417 = (0.875000e6 / 0.27e2)*_t1413;
  const double _t1418 = _t1206*_t1350;
  const double _t1419 = (0.350000e6 / 0.27e2)*_t1418;
  const double _t1420 = _t1409*_t28;
  const double _t1421 = (0.200000e6 / 0.9e1)*_t1411;
  const double _t1422 = (0.175000e6 / 0.3e1)*_t1413;
  const double _t1423 = (0.560000e6 / 0.9e1)*_t1418;
  const double _t1424 = _t1350*_t947;
  const double _t1425 = (0.70000e5 / 0.3e1)*_t1424;
  const double _t1426 = (0.175000e6 / 0.27e2)*_t1411;
  const double _t1427 = (0.1225000e7 / 0.27e2)*_t1413;
  const double _t1428 = (0.980000e6 / 0.9e1)*_t1350;
  const double _t1429 = _t1428*_t37;
  const double _t1430 = _t1393*_t950;
  const double _t1431 = (0.350000e6 / 0.27e2)*_t1413;
  const double _t1432 = (0.2240000e7 / 0.27e2)*_t1418;
  const double _t1433 = (0.560000e6 / 0.3e1)*_t1424;
  const double _t1434 = (0.1600000e7 / 0.9e1)*_t1394;
  const double _t1435 = _t1350*params->b[9];
  const double _t1436 = (0.70000e5 / 0.3e1)*_t1206;
  const double _t1437 = 0.140000e6*_t947;
  const double _t1438 = 0.300000e6*_t950;
  const double _t1439 = 0.275000e6*_t1188;
  const double _t1440 = (0.275000e6 / 0.3e1)*_t1350;
  const double _t1441 = (0.160000e6 / 0.3e1)*_t1353;
  const double _t1442 = _t1353*_t475;
  const double _t1443 = 0.200000e6*_t1442;
  const double _t1444 = (0.2200000e7 / 0.9e1)*_t1353;
  const double _t1445 = (0.880000e6 / 0.9e1)*_t1353;
  const double _t1446 = (0.220000e6 / 0.3e1)*_t1353;
  const double _t1447 = (0.2420000e7 / 0.9e1)*_t1353;
  const double _t1448 = (0.968000e6 / 0.3e1)*_t1353;
  const double _t1449 = (0.1144000e7 / 0.9e1)*_t1353;
  const double _t1450 = _t1353*_t28;
  const double _t1451 = (0.16000e5 / 0.9e1)*_t1450;
  const double _t1452 = 0.8000e4*_t1450;
  const double _t1453 = _t1353*_t31;
  const double _t1454 = (0.40000e5 / 0.9e1)*_t1453;
  const double _t1455 = (0.32000e5 / 0.3e1)*_t1450;
  const double _t1456 = (0.160000e6 / 0.9e1)*_t1453;
  const double _t1457 = _t1353*_t34;
  const double _t1458 = (0.40000e5 / 0.9e1)*_t1450;
  const double _t1459 = (0.200000e6 / 0.9e1)*_t1453;
  const double _t1460 = (0.100000e6 / 0.3e1)*_t1457;
  const double _t1461 = _t1353*_t37;
  const double _t1462 = (0.140000e6 / 0.9e1)*_t1461;
  const double _t1463 = (0.80000e5 / 0.9e1)*_t1453;
  const double _t1464 = 0.40000e5*_t1457;
  const double _t1465 = 0.56000e5*_t1461;
  const double _t1466 = (0.224000e6 / 0.9e1)*_t1353;
  const double _t1467 = (0.140000e6 / 0.9e1)*_t1457;
  const double _t1468 = (0.196000e6 / 0.3e1)*_t1353;
  const double _t1469 = (0.784000e6 / 0.9e1)*_t1353;
  const double _t1470 = (0.112000e6 / 0.3e1)*_t1353;
  const double _t1471 = (0.224000e6 / 0.9e1)*_t1461;
  const double _t1472 = (0.896000e6 / 0.9e1)*_t1353;
  const double _t1473 = _t1353*_t473;
  const double _t1474 = 0.128000e6*_t1473;
  const double _t1475 = (0.160000e6 / 0.3e1)*_t1442;
  const double _t1476 = 0.144000e6*_t1473;
  const double _t1477 = 0.180000e6*_t1442;
  const double _t1478 = _t1446*_t483;
  const double _t1479 = (0.136000e6 / 0.9e1)*_t1371;
  const double _t1480 = (0.2720000e7 / 0.81e2)*_t1371;
  const double _t1481 = (0.1496000e7 / 0.81e2)*_t1371;
  const double _t1482 = (0.3291200e7 / 0.81e2)*_t1371;
  const double _t1483 = (0.598400e6 / 0.27e2)*_t1371;
  const double _t1484 = (0.27200e5 / 0.9e1)*_t1371;
  const double _t1485 = (0.54400e5 / 0.27e2)*_t1371;
  const double _t1486 = _t1485*_t204;
  const double _t1487 = (0.435200e6 / 0.81e2)*_t1371;
  const double _t1488 = (0.272000e6 / 0.81e2)*_t1371;
  const double _t1489 = _t1488*_t211;
  const double _t1490 = (0.680000e6 / 0.81e2)*_t1371;
  const double _t1491 = (0.136000e6 / 0.27e2)*_t1371;
  const double _t1492 = _t1491*_t218;
  const double _t1493 = (0.108800e6 / 0.9e1)*_t1371;
  const double _t1494 = (0.190400e6 / 0.27e2)*_t1371;
  const double _t1495 = _t1494*_t226;
  const double _t1496 = (0.1332800e7 / 0.81e2)*_t1371;
  const double _t1497 = (0.761600e6 / 0.81e2)*_t1371;
  const double _t1498 = _t1497*_t232;
  const double _t1499 = (0.1740800e7 / 0.81e2)*_t1371;
  const double _t1500 = _t1493*_t187;
  const double _t1501 = _t1493*_t239;
  const double _t1502 = 0.27200e5*_t1371;
  const double _t1503 = _t1479*_t189;
  const double _t1504 = _t1350*params->a[10];
  const double _t1505 = _t1350*params->a[11];
  const double _t1506 = _t1350*params->a[9];
#endif
  double _hc0[(_KMAX) >= 4 ? 15 : (_KMAX) >= 3 ? 10 : (_KMAX) >= 2 ? 6 : (_KMAX) >= 1 ? 3 : 1] = {0.};
  if(!(_t5)) XC_CAT(lda_x_spin_k, _KMAX)(p, _t4/xc_powr(n_s, 1, 3), 0.1e1 - p->zeta_threshold, _hc0);
  const double _t58 = my_piecewise3(_t5, 0, _hc0[0]*_t57);
#if _KMAX >= 1
  const double _t118 = my_piecewise3(_t5, 0, _hc0[0]*_t117);
  const double _t130 = my_piecewise3(_t5, 0, _hc0[0]*_t129);
  const double _t132 = _hc0[2]*_t3;
  const double _t133 = _t131*_t132;
  const double _t134 = (0.1e1 / 0.6e1)*_t133;
  const double _t176 = my_piecewise3(_t5, 0, _hc0[0]*_t175 - _t134*_t57);
#endif
#if _KMAX >= 2
  const double _t269 = my_piecewise3(_t5, 0, _hc0[0]*_t268);
  const double _t272 = my_piecewise3(_t5, 0, _hc0[0]*_t271);
  const double _t281 = my_piecewise3(_t5, 0, _hc0[0]*_t280);
  const double _t323 = my_piecewise3(_t5, 0, _hc0[0]*_t322 - _t117*_t134);
  const double _t331 = my_piecewise3(_t5, 0, _hc0[0]*_t330 - _t129*_t134);
  const double _t334 = _t132*_t333;
  const double _t337 = _hc0[5]*_t15*_t336;
  const double _t338 = _t337*_t6;
  const double _t339 = (0.1e1 / 0.3e1)*_t133;
  const double _t460 = my_piecewise3(_t5, 0, _hc0[0]*_t459 - _t175*_t339 + _t332*_t334 + _t335*_t338);
#endif
#if _KMAX >= 3
  const double _t556 = my_piecewise3(_t5, 0, _hc0[0]*_t555);
  const double _t559 = my_piecewise3(_t5, 0, _hc0[0]*_t558);
  const double _t562 = my_piecewise3(_t5, 0, _hc0[0]*_t561);
  const double _t573 = my_piecewise3(_t5, 0, _hc0[0]*_t572);
  const double _t689 = my_piecewise3(_t5, 0, _hc0[0]*_t688 - _t134*_t268);
  const double _t692 = my_piecewise3(_t5, 0, _hc0[0]*_t691 - _t134*_t271);
  const double _t699 = my_piecewise3(_t5, 0, _hc0[0]*_t698 - _t134*_t280);
  const double _t700 = (0.2e1 / 0.9e1)*_t334;
  const double _t701 = (0.1e1 / 0.36e2)*_t338;
  const double _t783 = my_piecewise3(_t5, 0, _hc0[0]*_t782 + _t117*_t700 + _t117*_t701 - _t322*_t339);
  const double _t794 = my_piecewise3(_t5, 0, _hc0[0]*_t793 + _t129*_t700 + _t129*_t701 - _t330*_t339);
  const double _t796 = _hc0[9]*_t795/(n_s * n_s * n_s * n_s);
  const double _t797 = _t132*_t177;
  const double _t798 = (0.14e2 / 0.27e2)*_t797;
  const double _t799 = _t136*_t337;
  const double _t800 = (0.1e1 / 0.9e1)*_t799;
  const double _t801 = _hc0[2]*_t131*_t4;
  const double _t935 = my_piecewise3(_t5, 0, _hc0[0]*_t934 + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t175*_t2*_t333 + (0.1e1 / 0.12e2)*_hc0[5]*_t15*_t175*_t336*_t6 - _t335*_t796 - _t459*_t801 - _t57*_t798 - _t57*_t800);
#endif
#if _KMAX >= 4
  const double _t1247 = (0.1e1 / 0.36e2)*_t796;
#endif

  const double f = my_piecewise3(_t5, 0, _t58*n_s);
  out[0] = f;
#if _KMAX >= 1
  const double df_dtau_s = my_piecewise3(_t5, 0, _t118*n_s);
  out[1] = df_dtau_s;
  const double df_dlapl_s = 0;
  out[2] = df_dlapl_s;
  const double df_dsigma_ss = my_piecewise3(_t5, 0, _t130*n_s);
  out[3] = df_dsigma_ss;
  const double df_dn_s = my_piecewise3(_t5, 0, _t176*n_s + _t58);
  out[4] = df_dn_s;
#endif
#if _KMAX >= 2
  const double d2f_dtau_s2 = my_piecewise3(_t5, 0, _t269*n_s);
  out[5] = d2f_dtau_s2;
  const double d2f_dlapl_s_dtau_s = 0;
  out[6] = d2f_dlapl_s_dtau_s;
  const double d2f_dlapl_s2 = 0;
  out[7] = d2f_dlapl_s2;
  const double d2f_dsigma_ss_dtau_s = my_piecewise3(_t5, 0, _t272*n_s);
  out[8] = d2f_dsigma_ss_dtau_s;
  const double d2f_dsigma_ss_dlapl_s = 0;
  out[9] = d2f_dsigma_ss_dlapl_s;
  const double d2f_dsigma_ss2 = my_piecewise3(_t5, 0, _t281*n_s);
  out[10] = d2f_dsigma_ss2;
  const double d2f_dn_s_dtau_s = my_piecewise3(_t5, 0, _t118 + _t323*n_s);
  out[11] = d2f_dn_s_dtau_s;
  const double d2f_dn_s_dlapl_s = 0;
  out[12] = d2f_dn_s_dlapl_s;
  const double d2f_dn_s_dsigma_ss = my_piecewise3(_t5, 0, _t130 + _t331*n_s);
  out[13] = d2f_dn_s_dsigma_ss;
  const double d2f_dn_s2 = my_piecewise3(_t5, 0, 0.2e1*_t176 + _t460*n_s);
  out[14] = d2f_dn_s2;
#endif
#if _KMAX >= 3
  const double d3f_dtau_s3 = my_piecewise3(_t5, 0, _t556*n_s);
  out[15] = d3f_dtau_s3;
  const double d3f_dlapl_s_dtau_s2 = 0;
  out[16] = d3f_dlapl_s_dtau_s2;
  const double d3f_dlapl_s2_dtau_s = 0;
  out[17] = d3f_dlapl_s2_dtau_s;
  const double d3f_dlapl_s3 = 0;
  out[18] = d3f_dlapl_s3;
  const double d3f_dsigma_ss_dtau_s2 = my_piecewise3(_t5, 0, _t559*n_s);
  out[19] = d3f_dsigma_ss_dtau_s2;
  const double d3f_dsigma_ss_dlapl_s_dtau_s = 0;
  out[20] = d3f_dsigma_ss_dlapl_s_dtau_s;
  const double d3f_dsigma_ss_dlapl_s2 = 0;
  out[21] = d3f_dsigma_ss_dlapl_s2;
  const double d3f_dsigma_ss2_dtau_s = my_piecewise3(_t5, 0, _t562*n_s);
  out[22] = d3f_dsigma_ss2_dtau_s;
  const double d3f_dsigma_ss2_dlapl_s = 0;
  out[23] = d3f_dsigma_ss2_dlapl_s;
  const double d3f_dsigma_ss3 = my_piecewise3(_t5, 0, _t573*n_s);
  out[24] = d3f_dsigma_ss3;
  const double d3f_dn_s_dtau_s2 = my_piecewise3(_t5, 0, _t269 + _t689*n_s);
  out[25] = d3f_dn_s_dtau_s2;
  const double d3f_dn_s_dlapl_s_dtau_s = 0;
  out[26] = d3f_dn_s_dlapl_s_dtau_s;
  const double d3f_dn_s_dlapl_s2 = 0;
  out[27] = d3f_dn_s_dlapl_s2;
  const double d3f_dn_s_dsigma_ss_dtau_s = my_piecewise3(_t5, 0, _t272 + _t692*n_s);
  out[28] = d3f_dn_s_dsigma_ss_dtau_s;
  const double d3f_dn_s_dsigma_ss_dlapl_s = 0;
  out[29] = d3f_dn_s_dsigma_ss_dlapl_s;
  const double d3f_dn_s_dsigma_ss2 = my_piecewise3(_t5, 0, _t281 + _t699*n_s);
  out[30] = d3f_dn_s_dsigma_ss2;
  const double d3f_dn_s2_dtau_s = my_piecewise3(_t5, 0, 0.2e1*_t323 + _t783*n_s);
  out[31] = d3f_dn_s2_dtau_s;
  const double d3f_dn_s2_dlapl_s = 0;
  out[32] = d3f_dn_s2_dlapl_s;
  const double d3f_dn_s2_dsigma_ss = my_piecewise3(_t5, 0, 0.2e1*_t331 + _t794*n_s);
  out[33] = d3f_dn_s2_dsigma_ss;
  const double d3f_dn_s3 = my_piecewise3(_t5, 0, 0.3e1*_t460 + _t935*n_s);
  out[34] = d3f_dn_s3;
#endif
#if _KMAX >= 4
  const double d4f_dtau_s4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t12*(_t1000*params->b[9] + _t1001*params->b[9] + _t1002*params->b[9] + _t1003*params->b[9] + 0.59400e5*_t193*_t953 + _t208*_t944 + _t215*_t974 + _t222*_t980 + _t229*_t987 + 0.14112e5*_t236*_t982 + _t493*_t970 + _t496*_t945 + _t503*_t979 + _t506*_t981 + _t511*_t986 + _t517*_t991 + _t654*_t985 + _t938*params->b[1] + _t938*params->b[4] + _t939*params->b[2] + _t939*params->b[3] + _t942*params->b[1] + _t943*params->b[2] + _t946*params->b[5] + _t949*params->b[10] + _t952*params->b[10] + _t956*params->b[10] + _t959*params->b[10] + _t960*params->b[11] + _t962*params->b[11] + _t963*params->b[11] + _t964*params->b[11] + _t966*_t967 + _t969*params->b[2] + _t973*params->b[3] + _t975*params->b[4] + _t978*params->b[4] + _t984*params->b[5] + _t988*params->b[6] + _t989*params->b[6] + _t990*params->b[7] + _t992*params->b[7] + _t993*params->b[7] + _t994*params->b[8] + _t995*params->b[8] + _t996*params->b[8] + _t997*params->b[8] + _t998*params->b[8] + _t999*params->b[9]) + _t55*(_t1000*params->a[9] + _t1001*params->a[9] + _t1002*params->a[9] + _t1003*params->a[9] + _t1004*_t967 + _t539*_t944 + _t540*_t970 + _t541*_t945 + _t542*_t974 + _t543*_t979 + _t544*_t980 + _t545*_t981 + _t546*_t986 + _t547*_t987 + _t548*_t991 + _t684*_t985 + _t938*params->a[1] + _t938*params->a[4] + _t939*params->a[2] + _t939*params->a[3] + _t942*params->a[1] + _t943*params->a[2] + _t946*params->a[5] + _t949*params->a[10] + _t952*params->a[10] + _t956*params->a[10] + _t959*params->a[10] + _t960*params->a[11] + 0.59400e5*_t961*params->a[10] + _t962*params->a[11] + _t963*params->a[11] + _t964*params->a[11] + _t969*params->a[2] + _t973*params->a[3] + _t975*params->a[4] + _t978*params->a[4] + 0.14112e5*_t983*params->a[7] + _t984*params->a[5] + _t988*params->a[6] + _t989*params->a[6] + _t990*params->a[7] + _t992*params->a[7] + _t993*params->a[7] + _t994*params->a[8] + _t995*params->a[8] + _t996*params->a[8] + _t997*params->a[8] + _t998*params->a[8] + _t999*params->a[9]))));
  out[35] = d4f_dtau_s4;
  const double d4f_dlapl_s_dtau_s3 = 0;
  out[36] = d4f_dlapl_s_dtau_s3;
  const double d4f_dlapl_s2_dtau_s2 = 0;
  out[37] = d4f_dlapl_s2_dtau_s2;
  const double d4f_dlapl_s3_dtau_s = 0;
  out[38] = d4f_dlapl_s3_dtau_s;
  const double d4f_dlapl_s4 = 0;
  out[39] = d4f_dlapl_s4;
  const double d4f_dsigma_ss_dtau_s3 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t128*_t554 + _t532*_t557)));
  out[40] = d4f_dsigma_ss_dtau_s3;
  const double d4f_dsigma_ss_dlapl_s_dtau_s2 = 0;
  out[41] = d4f_dsigma_ss_dlapl_s_dtau_s2;
  const double d4f_dsigma_ss_dlapl_s2_dtau_s = 0;
  out[42] = d4f_dsigma_ss_dlapl_s2_dtau_s;
  const double d4f_dsigma_ss_dlapl_s3 = 0;
  out[43] = d4f_dsigma_ss_dlapl_s3;
  const double d4f_dsigma_ss2_dtau_s2 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t267*_t279 - _t560*_t574)));
  out[44] = d4f_dsigma_ss2_dtau_s2;
  const double d4f_dsigma_ss2_dlapl_s_dtau_s = 0;
  out[45] = d4f_dsigma_ss2_dlapl_s_dtau_s;
  const double d4f_dsigma_ss2_dlapl_s2 = 0;
  out[46] = d4f_dsigma_ss2_dlapl_s2;
  const double d4f_dsigma_ss3_dtau_s = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t1005*_t270 + _t116*_t571)));
  out[47] = d4f_dsigma_ss3_dtau_s;
  const double d4f_dsigma_ss3_dlapl_s = 0;
  out[48] = d4f_dsigma_ss3_dlapl_s;
  const double d4f_dsigma_ss4 = my_piecewise3(_t5, 0, n_s*my_piecewise3(_t5, 0, _hc0[0]*(-2.4977500413607402e-8*_t1006*_t565 + _t56*(7.4102674212111533e-9*_t1007*_t1008*_t15*sigma_ss/xc_powr(n_s, 40, 3) - 8.1019734002581966e-7*_t570))));
  out[49] = d4f_dsigma_ss4;
  const double d4f_dn_s_dtau_s3 = my_piecewise3(_t5, 0, _t556 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t1009*_t282*_t532 + _t12*(-_t1011*_t585 - _t1011*_t590 - _t1012*_t202 - _t1012*_t469 - _t1014*params->b[1] - _t1016*_t633 - _t1017*_t208 - _t1018*_t496 - _t1019*_t743 - _t1020*_t1021 - _t1020*_t1024 - _t1020*_t1025 - 0.48000e5*_t1020*_t950 - _t1023*_t193 - _t1026*_t1027*_t46 - _t1026*_t1028 - _t1026*_t1029 - 0.13200e5*_t1026*_t950 - _t1030*_t966 - _t1031*_t1033 - _t1034*_t493 - _t1035*_t1037 - _t1038*_t215 - _t1039*_t644 - _t1040*_t1042 - _t1043*_t503 - _t1044*_t222 - _t1045*_t506 - _t1048*params->b[5] - _t1049*_t654 - _t1050*_t511 - _t1051*_t229 - _t1052*params->b[6] - _t1054*params->b[6] - _t1055*_t754 - _t1056*_t517 - _t1057*_t236 - _t1058*params->b[7] - _t1060*params->b[7] - _t1061*_t759 - _t1062*params->b[8] - _t1063*params->b[8] - _t1064*params->b[8] - _t1066*params->b[8] - _t1067*params->b[9] - _t1068*params->b[9] - _t1069*params->b[9] - _t1070*params->b[9] - _t1071*_t1072 + 0.30e2*_t19*_t33*_t578*params->b[1] + 0.180e3*_t19*_t33*_t578*params->b[2] + 0.270e3*_t19*_t33*_t578*params->b[3] + 0.120e3*_t19*_t33*_t578*params->b[4] + 0.6600e4*_t199*_t22*_t578*params->b[10] + 0.21780e5*_t199*_t22*_t578*params->b[11] + 0.3600e4*_t21*_t43*_t578*params->b[10] + 0.2520e4*_t21*_t43*_t578*params->b[7] + 0.8640e4*_t21*_t43*_t578*params->b[8] + 0.9720e4*_t21*_t43*_t578*params->b[9] + 0.13500e5*_t24*_t46*_t578*params->b[10] + 0.4950e4*_t24*_t46*_t578*params->b[11] + 0.3600e4*_t24*_t46*_t578*params->b[8] + 0.12150e5*_t24*_t46*_t578*params->b[9] + 0.8580e4*_t25*_t486*_t578*params->b[11] + 0.120e3*_t28*_t36*_t578*params->b[2] + 0.540e3*_t28*_t36*_t578*params->b[3] + 0.720e3*_t28*_t36*_t578*params->b[4] + 0.300e3*_t28*_t36*_t578*params->b[5] + 0.30e2*_t30*_t578*params->b[1] + 0.60e2*_t30*_t578*params->b[2] + 0.30e2*_t30*_t578*params->b[3] + 0.300e3*_t31*_t39*_t578*params->b[3] + 0.1200e4*_t31*_t39*_t578*params->b[4] + 0.1500e4*_t31*_t39*_t578*params->b[5] + 0.600e3*_t31*_t39*_t578*params->b[6] + 0.600e3*_t34*_t42*_t578*params->b[4] + 0.2250e4*_t34*_t42*_t578*params->b[5] + 0.2700e4*_t34*_t42*_t578*params->b[6] + 0.1050e4*_t34*_t42*_t578*params->b[7] + 0.1050e4*_t37*_t45*_t578*params->b[5] + 0.3780e4*_t37*_t45*_t578*params->b[6] + 0.4410e4*_t37*_t45*_t578*params->b[7] + 0.1680e4*_t37*_t45*_t578*params->b[8] + 0.1680e4*_t40*_t48*_t578*params->b[6] + 0.5880e4*_t40*_t48*_t578*params->b[7] + 0.6720e4*_t40*_t48*_t578*params->b[8] + 0.2520e4*_t40*_t48*_t578*params->b[9] + 0.16500e5*_t49*_t578*_t71*params->b[10] + 0.18150e5*_t49*_t578*_t71*params->b[11] + 0.4950e4*_t49*_t578*_t71*params->b[9]) + _t143*_t554 + _t55*(-_t1004*_t1030 - _t1012*_t533 - _t1012*_t534 - _t1014*params->a[1] - _t1016*_t776 - _t1017*_t539 - _t1018*_t541 - _t1019*_t778 - _t1022*_t1027*params->a[11] - _t1023*_t1074 - _t1024*_t1075 - _t1025*_t1075 - _t1028*_t1076 - _t1029*_t1076 - _t1033*_t1077 - _t1034*_t540 - _t1037*_t1078 - _t1038*_t542 - _t1039*_t777 - _t1042*_t1079 - _t1043*_t543 - _t1044*_t544 - _t1045*_t545 - _t1048*params->a[5] - _t1049*_t684 - _t1050*_t546 - _t1051*_t547 - _t1052*params->a[6] - 0.8400e4*_t1053*params->a[10] - _t1054*params->a[6] - _t1055*_t779 - _t1056*_t548 - _t1057*_t1080 - _t1058*params->a[7] - 0.48000e5*_t1059*params->a[10] - 0.13200e5*_t1059*params->a[11] - _t1060*params->a[7] - _t1061*_t780 - _t1062*params->a[8] - _t1063*params->a[8] - _t1064*params->a[8] - _t1066*params->a[8] - _t1067*params->a[9] - _t1068*params->a[9] - _t1069*params->a[9] - _t1070*params->a[9] - _t1072*_t1081 - _t1073*params->a[1] - _t1073*params->a[4] + 0.30e2*_t19*_t33*_t578*params->a[1] + 0.180e3*_t19*_t33*_t578*params->a[2] + 0.270e3*_t19*_t33*_t578*params->a[3] + 0.120e3*_t19*_t33*_t578*params->a[4] + 0.6600e4*_t199*_t22*_t578*params->a[10] + 0.21780e5*_t199*_t22*_t578*params->a[11] + 0.3600e4*_t21*_t43*_t578*params->a[10] + 0.2520e4*_t21*_t43*_t578*params->a[7] + 0.8640e4*_t21*_t43*_t578*params->a[8] + 0.9720e4*_t21*_t43*_t578*params->a[9] + 0.13500e5*_t24*_t46*_t578*params->a[10] + 0.4950e4*_t24*_t46*_t578*params->a[11] + 0.3600e4*_t24*_t46*_t578*params->a[8] + 0.12150e5*_t24*_t46*_t578*params->a[9] + 0.8580e4*_t25*_t486*_t578*params->a[11] + 0.120e3*_t28*_t36*_t578*params->a[2] + 0.540e3*_t28*_t36*_t578*params->a[3] + 0.720e3*_t28*_t36*_t578*params->a[4] + 0.300e3*_t28*_t36*_t578*params->a[5] + 0.30e2*_t30*_t578*params->a[1] + 0.60e2*_t30*_t578*params->a[2] + 0.30e2*_t30*_t578*params->a[3] + 0.300e3*_t31*_t39*_t578*params->a[3] + 0.1200e4*_t31*_t39*_t578*params->a[4] + 0.1500e4*_t31*_t39*_t578*params->a[5] + 0.600e3*_t31*_t39*_t578*params->a[6] + 0.600e3*_t34*_t42*_t578*params->a[4] + 0.2250e4*_t34*_t42*_t578*params->a[5] + 0.2700e4*_t34*_t42*_t578*params->a[6] + 0.1050e4*_t34*_t42*_t578*params->a[7] + 0.1050e4*_t37*_t45*_t578*params->a[5] + 0.3780e4*_t37*_t45*_t578*params->a[6] + 0.4410e4*_t37*_t45*_t578*params->a[7] + 0.1680e4*_t37*_t45*_t578*params->a[8] + 0.1680e4*_t40*_t48*_t578*params->a[6] + 0.5880e4*_t40*_t48*_t578*params->a[7] + 0.6720e4*_t40*_t48*_t578*params->a[8] + 0.2520e4*_t40*_t48*_t578*params->a[9] + 0.16500e5*_t49*_t578*_t71*params->a[10] + 0.18150e5*_t49*_t578*_t71*params->a[11] + 0.4950e4*_t49*_t578*_t71*params->a[9])) - _t134*_t555));
  out[50] = d4f_dn_s_dtau_s3;
  const double d4f_dn_s_dlapl_s_dtau_s2 = 0;
  out[51] = d4f_dn_s_dlapl_s_dtau_s2;
  const double d4f_dn_s_dlapl_s2_dtau_s = 0;
  out[52] = d4f_dn_s_dlapl_s2_dtau_s;
  const double d4f_dn_s_dlapl_s3 = 0;
  out[53] = d4f_dn_s_dlapl_s3;
  const double d4f_dn_s_dsigma_ss_dtau_s2 = my_piecewise3(_t5, 0, _t559 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t1082*_t325 + _t128*_t687 + _t267*_t328 + _t557*_t679 - _t575) - _t134*_t558));
  out[54] = d4f_dn_s_dsigma_ss_dtau_s2;
  const double d4f_dn_s_dsigma_ss_dlapl_s_dtau_s = 0;
  out[55] = d4f_dn_s_dsigma_ss_dlapl_s_dtau_s;
  const double d4f_dn_s_dsigma_ss_dlapl_s2 = 0;
  out[56] = d4f_dn_s_dsigma_ss_dlapl_s2;
  const double d4f_dn_s_dsigma_ss2_dtau_s = my_piecewise3(_t5, 0, _t562 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t1083*_t326*_t694 + _t116*_t697 + _t279*_t321 - _t560*_t705 + _t690*_t695) - _t134*_t561));
  out[57] = d4f_dn_s_dsigma_ss2_dtau_s;
  const double d4f_dn_s_dsigma_ss2_dlapl_s = 0;
  out[58] = d4f_dn_s_dsigma_ss2_dlapl_s;
  const double d4f_dn_s_dsigma_ss3 = my_piecewise3(_t5, 0, _t573 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t1005*_t329 + 6.6606667769619753e-8*_t1006*_t696*sigma_ss + _t174*_t571 + _t56*(3.7809209201204914e-6*_t1*_t566*_t567*_t696*sigma_ss - 1.976071312322974e-8*_t1084*_t142/xc_powr(n_s, 43, 3) - 0.00017716492333487926*_t327) - 2.1442444771069718e-5*_t693) - _t134*_t572));
  out[59] = d4f_dn_s_dsigma_ss3;
  const double d4f_dn_s2_dtau_s2 = my_piecewise3(_t5, 0, 0.2e1*_t689 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t1009*_t679*_t706 - _t1082*_t704 + _t12*(_t1013*_t1090*_t708 + _t1021*_t1212 + _t1031*_t1194 + _t1040*_t1202 + _t1071*_t1230 + _t1085*_t60 + _t1086*params->b[2] - _t1087*params->b[1] - _t1087*params->b[3] - _t1088*_t713 + _t1090*_t715 + _t1092*_t202 + _t1092*_t469 + _t1093*_t590 + _t1094*params->b[1] + _t1095*_t182 + _t1096*_t203 + _t1097*params->b[3] - _t1098*_t585 - _t1099*_t202 - _t1100*_t469 - _t1101*_t590 + _t1102*_t188 + _t1103*_t190 + _t1104*_t194 + _t1105*params->b[11] + _t1106*_t197 + _t1107*_t200 + _t1108*_t205 + _t1109*_t209 + _t1110*params->b[4] + _t1111*_t212 + _t1112*_t216 + _t1113*params->b[5] + _t1114*_t219 + _t1115*_t223 + _t1116*params->b[6] + _t1117*_t227 + _t1118*_t230 + _t1119*params->b[7] + _t1120*_t233 + _t1121*_t237 + _t1122*params->b[8] + _t1123*_t240 + _t1124*params->b[8] + _t1125*params->b[9] + _t1126*_t244 + _t1127*params->b[9] + _t1129*_t633 + _t1130*_t208 + _t1131*_t496 + _t1132*_t743 - _t1134*_t618 - _t1136*params->b[10] - _t1137*_t478 - _t1138*params->b[10] - _t1139*_t483*_t675 - _t1140*_t626 - _t1141*_t1142 - _t1141*_t1143 - _t1144*_t487 - _t1146*_t633 - _t1147*_t208 - _t1149*_t493 - _t1150*_t496 - _t1151*_t215 - _t1153*_t644 - _t1154*_t743 - _t1155*_t503 - _t1156*_t222 - _t1158*_t506 - _t1159*_t654 - _t1160*_t511 - _t1161*_t229 - _t1162*_t1163 - _t1164*_t754 - _t1165*_t1166 - _t1167*_t520 - _t1168*_t522 - _t1169*_t669 - 0.7840e4*_t1170*_t675 - _t1171*_t669 - _t1173*_t669 - _t1174*_t669 - _t1175*_t675 - _t1176*_t675 + _t1177*_t1178 + _t1179*_t1180 + _t1179*_t1183 + _t1179*_t1184 + _t1181*_t1182 + _t1185*_t1186 + _t1187*_t1189 + _t1187*_t1190 + _t1187*_t1191 + _t1192*_t966 + _t1195*_t493 + _t1196*_t1197 + _t1198*_t215 + _t1200*_t644 + _t1203*_t503 + _t1204*_t222 + _t1205*_t506 + (0.89600e5 / 0.3e1)*_t1206*_t1221 + _t1208*params->b[5] + _t1209*_t654 + _t1210*_t511 + _t1211*_t229 + _t1212*_t1213 + _t1214*_t754 + _t1215*_t517 + _t1216*_t1218 + _t1217*_t236 + _t1219*params->b[7] + _t1220*_t759 + _t1221*_t1222 + _t1221*_t1223 + _t1224*params->b[8] + _t1225*_t1226 + _t1225*_t1227 + _t1225*_t1228 + _t1225*_t1229) + _t267*_t351 + _t355*_t687 + _t55*(_t1004*_t1192 + _t1021*_t1241 + _t104*_t1085 + _t1077*_t1194 + _t1079*_t1202 + _t1080*_t1217 + _t1081*_t1230 + _t1086*params->a[2] - _t1087*params->a[1] - _t1087*params->a[3] - _t1088*_t770 + _t1092*_t533 + _t1092*_t534 + _t1093*_t1231 + _t1093*_t680 + _t1093*_t681 + _t1094*params->a[1] + _t1095*_t248 + _t1096*_t254 + _t1097*params->a[3] - _t1098*_t680 - _t1099*_t533 - _t1100*_t534 - _t1101*_t681 + _t1102*_t249 + _t1103*_t250 + _t1104*_t251 + _t1105*params->a[11] + _t1106*_t252 + _t1107*_t253 + _t1108*_t255 + _t1109*_t256 + _t1110*params->a[4] + _t1111*_t257 + _t1112*_t258 + _t1113*params->a[5] + _t1114*_t259 + _t1115*_t260 + _t1116*params->a[6] + _t1117*_t261 + _t1118*_t262 + _t1119*params->a[7] + _t1120*_t263 + _t1121*_t264 + _t1122*params->a[8] + _t1123*_t265 + _t1124*params->a[8] + _t1125*params->a[9] + _t1126*_t266 + _t1127*params->a[9] + _t1129*_t776 + _t1130*_t539 + _t1131*_t541 + _t1132*_t778 - _t1134*_t771 - _t1136*params->a[10] - _t1137*_t536 - _t1138*params->a[10] - _t1139*_t629*params->a[9] - _t1140*_t773 - _t1142*_t1232 - _t1143*_t1232 - _t1144*_t538 - _t1146*_t776 - _t1147*_t539 - _t1149*_t540 - _t1150*_t541 - _t1151*_t542 - _t1153*_t777 - _t1154*_t778 - _t1155*_t543 - _t1156*_t544 - _t1158*_t545 - _t1159*_t684 - _t1160*_t546 - _t1161*_t547 - _t1163*_t1233 - _t1164*_t779 - _t1166*_t1234 - _t1167*_t549 - _t1168*_t550 - _t1168*_t552 - _t1169*_t685 - _t1171*_t685 - _t1173*_t685 - _t1174*_t685 - _t1175*_t686 - _t1176*_t686 + _t1177*_t1235 + _t1180*_t1236 + _t1182*_t1237 + _t1183*_t1236 + _t1184*_t1236 + _t1185*_t1238 + _t1189*_t1239 + _t1190*_t1239 + _t1191*_t1239 + _t1195*_t540 + _t1196*_t1240 + _t1198*_t542 + _t1200*_t777 + _t1203*_t543 + _t1204*_t544 + _t1205*_t545 + (0.89600e5 / 0.3e1)*_t1207*params->a[8] + _t1208*params->a[5] + _t1209*_t684 + _t1210*_t546 + _t1211*_t547 + _t1213*_t1241 + _t1214*_t779 + _t1215*_t548 + _t1216*_t1242 + _t1219*params->a[7] + _t1220*_t780 + _t1222*_t1243 + _t1223*_t1243 + _t1224*params->a[8] + _t1226*_t1244 + _t1227*_t1244 + _t1228*_t1244 + _t1229*_t1244) + _t574*_t702*sigma_ss) + _t268*_t700 + _t268*_t701 - _t339*_t688));
  out[60] = d4f_dn_s2_dtau_s2;
  const double d4f_dn_s2_dlapl_s_dtau_s = 0;
  out[61] = d4f_dn_s2_dlapl_s_dtau_s;
  const double d4f_dn_s2_dlapl_s2 = 0;
  out[62] = d4f_dn_s2_dlapl_s2;
  const double d4f_dn_s2_dsigma_ss_dtau_s = my_piecewise3(_t5, 0, 0.2e1*_t692 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(_t1083*_t347*_t785 + _t116*_t789 + _t1245*_t791 + _t128*_t781 + _t321*_t792 - _t343*_t690*_t786 + _t557*_t769 + _t703 - _t707) + _t271*_t700 + _t271*_t701 - _t339*_t691));
  out[63] = d4f_dn_s2_dsigma_ss_dtau_s;
  const double d4f_dn_s2_dsigma_ss_dlapl_s = 0;
  out[64] = d4f_dn_s2_dsigma_ss_dlapl_s;
  const double d4f_dn_s2_dsigma_ss2 = my_piecewise3(_t5, 0, 0.2e1*_t699 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-1.7761778071898596e-7*_t1006*_t142*_t787 - 1.4294963180713146e-5*_t1246*_t326*sigma_ss + 0.000511325114988837*_t141*_t790 + 0.2e1*_t174*_t697 + _t279*_t458 - 0.0016191961974646501*_t344 + _t56*(5.2695234995279302e-8*_t1084*_t346/xc_powr(n_s, 46, 3) - 1.3503289000430326e-5*_t142*_t788 + 0.0010957978591453641*_t348*sigma_ss - 0.0045436330997999999*_t350) - _t560*_t821 + 0.00010244723612844419*_t784*sigma_ss) + _t280*_t700 + _t280*_t701 - _t339*_t698));
  out[65] = d4f_dn_s2_dsigma_ss2;
  const double d4f_dn_s3_dtau_s = my_piecewise3(_t5, 0, 0.3e1*_t783 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-_t1083*_t802*_t804 + _t116*_t815 + _t12*(-_t1031*_t1303 - _t1040*_t1310 - _t1071*_t1336 - _t1178*_t1290 - _t1181*_t1293 - _t1186*_t1296 - 0.110000e6 / 0.3e1*_t1188*_t1328 - _t1197*_t1305 - _t1218*_t1324 - _t1250*_t146 - _t1251*_t148 - _t1251*_t180*params->b[1] - _t1253*_t1259 - _t1253*_t585 - _t1253*_t590 - _t1254*_t202 - _t1254*_t469 - _t1256*_t182 - _t1257*_t203 - _t1258*params->b[3] - _t1261*_t633 - _t1262*_t208 - _t1263*_t496 - _t1264*_t743 - _t1265*_t188 - _t1266*_t190 - _t1267*_t194 - _t1267*_t907 - _t1268*_t197 - _t1269*_t200 - _t1270*_t205 - _t1271*_t209 - _t1272*params->b[4] - _t1273*_t212 - _t1274*_t216 - _t1275*params->b[5] - _t1276*_t219 - _t1277*_t223 - _t1278*params->b[6] - _t1279*_t227 - _t1280*_t230 - _t1281*params->b[7] - _t1282*_t233 - _t1283*_t237 - _t1284*_t669 - _t1285*_t240 - _t1286*_t187*_t669 - _t1287*_t1289 - 0.13120e5 / 0.3e1*_t1287*_t239 - _t1288*_t244 - _t1291*_t1292 - _t1291*_t1294 - _t1291*_t1295 - _t1297*_t1298 - _t1297*_t1299 - _t1297*_t1300 - _t1301*_t966 - _t1304*_t493 - _t1306*_t215 - _t1307*_t1308 - _t1311*_t503 - _t1312*_t222 - _t1313*_t506 - _t1315*params->b[5] - _t1316*_t654 - _t1317*_t511 - _t1318*_t229 - _t1319*params->b[6] - _t1321*params->b[6] - _t1322*_t754 - _t1323*_t517 - _t1325*_t236 - _t1326*params->b[7] - _t1327*_t759 - _t1328*_t1329 - _t1328*_t1331 - _t1330*params->b[8] - _t1332*_t1333 - _t1332*_t1334 - _t1332*_t1335 - 0.84000e5*_t1332*_t947 + (0.440e3 / 0.27e2)*_t18*_t340*params->b[1] + (0.440e3 / 0.27e2)*_t19*_t27*_t340*params->b[1] + (0.880e3 / 0.27e2)*_t19*_t27*_t340*params->b[2] + (0.650e3 / 0.3e1)*_t19*_t275*_t33*_t358*params->b[1] + 0.1300e4*_t19*_t275*_t33*_t358*params->b[2] + 0.1950e4*_t19*_t275*_t33*_t358*params->b[3] + (0.2600e4 / 0.3e1)*_t19*_t275*_t33*_t358*params->b[4] + (0.143000e6 / 0.3e1)*_t199*_t22*_t275*_t358*params->b[10] + 0.157300e6*_t199*_t22*_t275*_t358*params->b[11] + 0.26000e5*_t21*_t275*_t358*_t43*params->b[10] + 0.18200e5*_t21*_t275*_t358*_t43*params->b[7] + 0.62400e5*_t21*_t275*_t358*_t43*params->b[8] + 0.70200e5*_t21*_t275*_t358*_t43*params->b[9] + (0.4400e4 / 0.27e2)*_t21*_t340*_t49*params->b[10] + (0.440e3 / 0.3e1)*_t21*_t340*_t49*params->b[9] + (0.4400e4 / 0.27e2)*_t22*_t24*_t340*params->b[10] + (0.4840e4 / 0.27e2)*_t22*_t24*_t340*params->b[11] + 0.97500e5*_t24*_t275*_t358*_t46*params->b[10] + 0.35750e5*_t24*_t275*_t358*_t46*params->b[11] + 0.26000e5*_t24*_t275*_t358*_t46*params->b[8] + 0.87750e5*_t24*_t275*_t358*_t46*params->b[9] + (0.185900e6 / 0.3e1)*_t25*_t275*_t358*_t486*params->b[11] + (0.4840e4 / 0.27e2)*_t25*_t340*_t71*params->b[11] + (0.2600e4 / 0.3e1)*_t275*_t28*_t358*_t36*params->b[2] + 0.3900e4*_t275*_t28*_t358*_t36*params->b[3] + 0.5200e4*_t275*_t28*_t358*_t36*params->b[4] + (0.6500e4 / 0.3e1)*_t275*_t28*_t358*_t36*params->b[5] + (0.650e3 / 0.3e1)*_t275*_t30*_t358*params->b[1] + (0.1300e4 / 0.3e1)*_t275*_t30*_t358*params->b[2] + (0.650e3 / 0.3e1)*_t275*_t30*_t358*params->b[3] + (0.6500e4 / 0.3e1)*_t275*_t31*_t358*_t39*params->b[3] + (0.26000e5 / 0.3e1)*_t275*_t31*_t358*_t39*params->b[4] + (0.32500e5 / 0.3e1)*_t275*_t31*_t358*_t39*params->b[5] + (0.13000e5 / 0.3e1)*_t275*_t31*_t358*_t39*params->b[6] + (0.13000e5 / 0.3e1)*_t275*_t34*_t358*_t42*params->b[4] + 0.16250e5*_t275*_t34*_t358*_t42*params->b[5] + 0.19500e5*_t275*_t34*_t358*_t42*params->b[6] + (0.22750e5 / 0.3e1)*_t275*_t34*_t358*_t42*params->b[7] + (0.22750e5 / 0.3e1)*_t275*_t358*_t37*_t45*params->b[5] + 0.27300e5*_t275*_t358*_t37*_t45*params->b[6] + 0.31850e5*_t275*_t358*_t37*_t45*params->b[7] + (0.36400e5 / 0.3e1)*_t275*_t358*_t37*_t45*params->b[8] + (0.36400e5 / 0.3e1)*_t275*_t358*_t40*_t48*params->b[6] + (0.127400e6 / 0.3e1)*_t275*_t358*_t40*_t48*params->b[7] + (0.145600e6 / 0.3e1)*_t275*_t358*_t40*_t48*params->b[8] + 0.18200e5*_t275*_t358*_t40*_t48*params->b[9] + (0.357500e6 / 0.3e1)*_t275*_t358*_t49*_t71*params->b[10] + (0.393250e6 / 0.3e1)*_t275*_t358*_t49*_t71*params->b[11] + 0.35750e5*_t275*_t358*_t49*_t71*params->b[9] + (0.880e3 / 0.27e2)*_t28*_t30*_t340*params->b[2] + (0.440e3 / 0.9e1)*_t28*_t30*_t340*params->b[3] + (0.440e3 / 0.9e1)*_t31*_t33*_t340*params->b[3] + (0.1760e4 / 0.27e2)*_t31*_t33*_t340*params->b[4] + (0.1760e4 / 0.27e2)*_t34*_t340*_t36*params->b[4] + (0.2200e4 / 0.27e2)*_t34*_t340*_t36*params->b[5] + (0.2200e4 / 0.27e2)*_t340*_t37*_t39*params->b[5] + (0.880e3 / 0.9e1)*_t340*_t37*_t39*params->b[6] + (0.880e3 / 0.9e1)*_t340*_t40*_t42*params->b[6] + (0.3080e4 / 0.27e2)*_t340*_t40*_t42*params->b[7] + (0.3080e4 / 0.27e2)*_t340*_t43*_t45*params->b[7] + (0.3520e4 / 0.27e2)*_t340*_t43*_t45*params->b[8] + (0.3520e4 / 0.27e2)*_t340*_t46*_t48*params->b[8] + (0.440e3 / 0.3e1)*_t340*_t46*_t48*params->b[9]) - _t1245*_t343*_t819 - _t1248*_t270*_t806 + _t1248*_t705*_t816 - _t1249*_t769*_t823 + _t321*_t820 + _t55*(-_t1004*_t1301 - _t104*_t1251 - _t1077*_t1303 - _t1079*_t1310 - _t1080*_t1325 - _t1081*_t1336 - _t1231*_t1253 - _t1235*_t1290 - _t1237*_t1293 - _t1238*_t1296 - _t1240*_t1305 - _t1242*_t1324 - _t1251*_t172 - _t1251*_t931 - _t1253*_t680 - _t1253*_t681 - _t1254*_t533 - _t1254*_t534 - _t1256*_t248 - _t1257*_t254 - _t1258*params->a[3] - _t1261*_t776 - _t1262*_t539 - _t1263*_t541 - _t1264*_t778 - _t1265*_t249 - _t1266*_t250 - _t1267*_t251 - _t1268*_t252 - _t1269*_t253 - _t1270*_t255 - _t1271*_t256 - _t1272*params->a[4] - _t1273*_t257 - _t1274*_t258 - _t1275*params->a[5] - _t1276*_t259 - _t1277*_t260 - _t1278*params->a[6] - _t1279*_t261 - _t1280*_t262 - _t1281*params->a[7] - _t1282*_t263 - _t1283*_t264 - _t1284*_t685 - _t1285*_t265 - _t1286*_t187*_t685 - _t1286*_t239*_t686 - _t1288*_t266 - _t1289*_t141*_t686 - _t1292*_t1337 - _t1294*_t1337 - _t1295*_t1337 - _t1296*_t1341 - _t1298*_t1338 - _t1299*_t1338 - _t1300*_t1338 - _t1304*_t540 - _t1306*_t542 - _t1307*_t1339 - _t1311*_t543 - _t1312*_t544 - _t1313*_t545 - _t1315*params->a[5] - _t1316*_t684 - _t1317*_t546 - _t1318*_t547 - _t1319*params->a[6] - 0.84000e5*_t1320*params->a[9] - _t1321*params->a[6] - _t1322*_t779 - _t1323*_t548 - _t1326*params->a[7] - _t1327*_t780 - _t1329*_t1340 - _t1330*params->a[8] - _t1331*_t1340 - _t1333*_t1342 - _t1334*_t1342 - _t1335*_t1342 - 0.180400e6 / 0.27e2*_t141*_t189*_t682 + (0.440e3 / 0.27e2)*_t18*_t340*params->a[1] + (0.440e3 / 0.27e2)*_t19*_t27*_t340*params->a[1] + (0.880e3 / 0.27e2)*_t19*_t27*_t340*params->a[2] + (0.650e3 / 0.3e1)*_t19*_t275*_t33*_t358*params->a[1] + 0.1300e4*_t19*_t275*_t33*_t358*params->a[2] + 0.1950e4*_t19*_t275*_t33*_t358*params->a[3] + (0.2600e4 / 0.3e1)*_t19*_t275*_t33*_t358*params->a[4] + (0.143000e6 / 0.3e1)*_t199*_t22*_t275*_t358*params->a[10] + 0.157300e6*_t199*_t22*_t275*_t358*params->a[11] + 0.26000e5*_t21*_t275*_t358*_t43*params->a[10] + 0.18200e5*_t21*_t275*_t358*_t43*params->a[7] + 0.62400e5*_t21*_t275*_t358*_t43*params->a[8] + 0.70200e5*_t21*_t275*_t358*_t43*params->a[9] + (0.4400e4 / 0.27e2)*_t21*_t340*_t49*params->a[10] + (0.440e3 / 0.3e1)*_t21*_t340*_t49*params->a[9] + (0.4400e4 / 0.27e2)*_t22*_t24*_t340*params->a[10] + (0.4840e4 / 0.27e2)*_t22*_t24*_t340*params->a[11] + 0.97500e5*_t24*_t275*_t358*_t46*params->a[10] + 0.35750e5*_t24*_t275*_t358*_t46*params->a[11] + 0.26000e5*_t24*_t275*_t358*_t46*params->a[8] + 0.87750e5*_t24*_t275*_t358*_t46*params->a[9] + (0.185900e6 / 0.3e1)*_t25*_t275*_t358*_t486*params->a[11] + (0.4840e4 / 0.27e2)*_t25*_t340*_t71*params->a[11] + (0.2600e4 / 0.3e1)*_t275*_t28*_t358*_t36*params->a[2] + 0.3900e4*_t275*_t28*_t358*_t36*params->a[3] + 0.5200e4*_t275*_t28*_t358*_t36*params->a[4] + (0.6500e4 / 0.3e1)*_t275*_t28*_t358*_t36*params->a[5] + (0.650e3 / 0.3e1)*_t275*_t30*_t358*params->a[1] + (0.1300e4 / 0.3e1)*_t275*_t30*_t358*params->a[2] + (0.650e3 / 0.3e1)*_t275*_t30*_t358*params->a[3] + (0.6500e4 / 0.3e1)*_t275*_t31*_t358*_t39*params->a[3] + (0.26000e5 / 0.3e1)*_t275*_t31*_t358*_t39*params->a[4] + (0.32500e5 / 0.3e1)*_t275*_t31*_t358*_t39*params->a[5] + (0.13000e5 / 0.3e1)*_t275*_t31*_t358*_t39*params->a[6] + (0.13000e5 / 0.3e1)*_t275*_t34*_t358*_t42*params->a[4] + 0.16250e5*_t275*_t34*_t358*_t42*params->a[5] + 0.19500e5*_t275*_t34*_t358*_t42*params->a[6] + (0.22750e5 / 0.3e1)*_t275*_t34*_t358*_t42*params->a[7] + (0.22750e5 / 0.3e1)*_t275*_t358*_t37*_t45*params->a[5] + 0.27300e5*_t275*_t358*_t37*_t45*params->a[6] + 0.31850e5*_t275*_t358*_t37*_t45*params->a[7] + (0.36400e5 / 0.3e1)*_t275*_t358*_t37*_t45*params->a[8] + (0.36400e5 / 0.3e1)*_t275*_t358*_t40*_t48*params->a[6] + (0.127400e6 / 0.3e1)*_t275*_t358*_t40*_t48*params->a[7] + (0.145600e6 / 0.3e1)*_t275*_t358*_t40*_t48*params->a[8] + 0.18200e5*_t275*_t358*_t40*_t48*params->a[9] + (0.357500e6 / 0.3e1)*_t275*_t358*_t49*_t71*params->a[10] + (0.393250e6 / 0.3e1)*_t275*_t358*_t49*_t71*params->a[11] + 0.35750e5*_t275*_t358*_t49*_t71*params->a[9] + (0.880e3 / 0.27e2)*_t28*_t30*_t340*params->a[2] + (0.440e3 / 0.9e1)*_t28*_t30*_t340*params->a[3] + (0.440e3 / 0.9e1)*_t31*_t33*_t340*params->a[3] + (0.1760e4 / 0.27e2)*_t31*_t33*_t340*params->a[4] + (0.1760e4 / 0.27e2)*_t34*_t340*_t36*params->a[4] + (0.2200e4 / 0.27e2)*_t34*_t340*_t36*params->a[5] + (0.2200e4 / 0.27e2)*_t340*_t37*_t39*params->a[5] + (0.880e3 / 0.9e1)*_t340*_t37*_t39*params->a[6] + (0.880e3 / 0.9e1)*_t340*_t40*_t42*params->a[6] + (0.3080e4 / 0.27e2)*_t340*_t40*_t42*params->a[7] + (0.3080e4 / 0.27e2)*_t340*_t43*_t45*params->a[7] + (0.3520e4 / 0.27e2)*_t340*_t43*_t45*params->a[8] + (0.3520e4 / 0.27e2)*_t340*_t46*_t48*params->a[8] + (0.440e3 / 0.3e1)*_t340*_t46*_t48*params->a[9]) + _t690*_t808*_t810 + _t781*_t825) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t322*_t333 + (0.1e1 / 0.12e2)*_hc0[5]*_t15*_t322*_t336*_t6 - _t117*_t1247 - _t117*_t798 - _t117*_t800 - _t782*_t801));
  out[66] = d4f_dn_s3_dtau_s;
  const double d4f_dn_s3_dlapl_s = 0;
  out[67] = d4f_dn_s3_dlapl_s;
  const double d4f_dn_s3_dsigma_ss = my_piecewise3(_t5, 0, 0.3e1*_t794 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(4.7364741525062911e-7*_t1006*_t346*_t813 + 5.7179852722852584e-5*_t1246*_t142*_t347 + _t128*_t933 + 0.00038349383624162775*_t1343*_t324 - 0.00036213906724473293*_t142*_t803 + 0.3e1*_t174*_t789 + 0.3e1*_t328*_t458 + _t557*_t930 + _t56*(4.2730407859139521e-5*_t1*_t346*_t566*_t567*_t813 - 1.4052062665407816e-7*_t1084*_t814/xc_powr(n_s, 49, 3) + 0.030251030901299998*_t123*_t124*_t15*_t808*sigma_ss - 0.0044838036152654625*_t142*_t811 - _t812) - _t807 + 0.0096867702339551894*_t809*sigma_ss + _t817 - 0.0034514445261746496*_t818*sigma_ss - _t824) + (0.2e1 / 0.3e1)*_hc0[2]*_t1*_t2*_t330*_t333 + (0.1e1 / 0.12e2)*_hc0[5]*_t15*_t330*_t336*_t6 - _t1247*_t129 - _t129*_t798 - _t129*_t800 - _t793*_t801));
  out[68] = d4f_dn_s3_dsigma_ss;
  const double d4f_dn_s4 = my_piecewise3(_t5, 0, 0.4e1*_t935 + n_s*my_piecewise3(_t5, 0, _hc0[0]*(-1.2630597740016776e-6*_t1006*_t1346 + _t12*(-_t102*_t1391 + _t1031*_t1407 + _t1040*_t1414 + _t1071*_t1440 - _t1162*_t1466 - _t1165*_t1468 + _t1178*_t1393 + _t1181*_t1396 + _t1186*_t1400 + _t1188*_t1400*params->b[8] + _t1197*_t1409 + _t1218*_t1428 + _t1259*_t1351 - _t1308*_t1457 - _t1349*_t144 + _t1351*_t585 + _t1351*_t590 + _t1352*_t202 + _t1352*_t469 - _t1355*params->b[1] - _t1355*params->b[3] - _t1356*_t712 + _t1357*_t359 + _t1357*_t841 + _t1358*_t148 - _t1359*_t155 - _t1360*_t148 + _t1362*_t633 + _t1363*_t208 + _t1364*_t496 + _t1365*_t743 - _t1366*_t585 - _t1367*_t19*_t202 - _t1369*_t469 - _t1370*_t590 + _t1372*_t182 + _t1373*_t203 + _t1374*params->b[3] - _t1375*_t68 - _t1376*params->b[10] - _t1377*_t73 - _t1378*params->b[11] - _t1379*_t79 - _t1380*params->b[3] - _t1381*_t83 - _t1382*params->b[4] - _t1383*_t87 - _t1384*params->b[5] - _t1385*_t91 - _t1386*params->b[6] - _t1387*_t95 - _t1388*params->b[7] - _t1389*_t99 - _t1390*params->b[8] - _t1392*params->b[9] + _t1395*params->b[10] + _t1397*_t1398 + _t1397*_t1399 + _t1401*_t1402 + _t1401*_t1403 + _t1401*_t1404 + _t1405*_t966 + _t1408*_t493 + _t1410*_t215 + _t1412*_t644 + _t1415*_t503 + _t1416*_t222 + _t1417*_t506 + _t1419*params->b[5] + _t1420*_t654 + _t1421*_t511 + _t1422*_t229 + _t1423*params->b[6] + _t1425*params->b[6] + _t1426*_t754 + _t1427*_t517 + _t1429*_t236 + _t1430*params->b[7] + _t1431*_t759 + _t1432*params->b[8] + _t1433*params->b[8] + _t1434*params->b[8] + _t1435*_t1436 + _t1435*_t1437 + _t1435*_t1438 + _t1435*_t1439 - _t1441*_t618 - _t1443*params->b[10] - _t1444*_t478 - _t1445*_t726 - _t1446*_t626 - _t1447*_t729 - _t1448*_t731 - _t1449*_t487 - _t1451*_t633 - _t1452*_t208 - _t1454*_t493 - _t1455*_t496 - _t1456*_t215 - _t1458*_t743 - _t1459*_t503 - 0.6160e4 / 0.81e2*_t146*_t19*_t805 - _t1460*_t222 - _t1462*_t506 - _t1463*_t654 - _t1464*_t511 - _t1465*_t229 - _t1467*_t754 - _t1469*_t520 - _t1470*_t522 - _t1470*_t765 - _t1471*_t759 - _t1472*_t514*params->b[8] - _t1474*params->b[8] - _t1475*params->b[8] - _t1476*params->b[9] - _t1477*params->b[9] - _t1478*params->b[9] + _t1479*_t188 + _t1480*_t190 + _t1481*_t194 + _t1481*_t907 + _t1482*_t197 + _t1483*_t200 + _t1484*_t205 + _t1485*_t209 + _t1486*params->b[4] + _t1487*_t212 + _t1488*_t216 + _t1489*params->b[5] + _t1490*_t219 + _t1491*_t223 + _t1492*params->b[6] + _t1493*_t227 + _t1494*_t230 + _t1495*params->b[7] + _t1496*_t233 + _t1497*_t237 + _t1498*params->b[8] + _t1499*_t240 + _t1500*params->b[8] + _t1501*params->b[9] + _t1502*_t244 + _t1503*params->b[9]) - 0.00020330614301458693*_t1246*_t346*_t802 - 0.05486968449931412*_t1249*_t136*_t930 - 0.002045300459955348*_t1343*_t142*_t343 + 0.0011181837865802281*_t1344*_t563 + 1.3300817964741145*_t1345*_t135 - 0.037080539820301586*_t1347*_t273 + 0.014998870039672551*_t142*_t790*_t808 + 0.4e1*_t143*_t933 + 0.4e1*_t174*_t815 + 0.30178326474622763*_t340*_t822*sigma_ss + 0.6e1*_t351*_t458 - 0.93888126809937489*_t352*_t805*sigma_ss + _t55*(_t1004*_t1405 - _t104*_t1349*_t19 + _t104*_t1358 - _t106*_t1375 + _t1077*_t1407 + _t1079*_t1414 - _t108*_t1377 + _t1080*_t1429 + _t1081*_t1440 - _t109*_t1379 - _t110*_t1381 - _t111*_t1383 - _t112*_t1385 - _t113*_t1387 - _t114*_t1389 - _t115*_t1391 + _t1231*_t1351 - _t1233*_t1466 - _t1234*_t1468 + _t1235*_t1393 + _t1237*_t1396 + _t1238*_t1400 + _t1240*_t1409 + _t1242*_t1428 - _t1339*_t1457 + _t1341*_t1400 - _t1349*_t171 + _t1351*_t680 + _t1351*_t681 + _t1352*_t533 + _t1352*_t534 - _t1355*params->a[1] - _t1355*params->a[3] - _t1356*_t30*params->a[2] + _t1358*_t172 + _t1358*_t931 - _t1359*_t173 - _t1360*_t172 + _t1362*_t776 + _t1363*_t539 + _t1364*_t541 + _t1365*_t778 - _t1366*_t680 - _t1367*_t19*_t533 - _t1369*_t534 - _t1370*_t681 + _t1372*_t248 + _t1373*_t254 + _t1374*params->a[3] - _t1376*params->a[10] - _t1378*params->a[11] - _t1380*params->a[3] - _t1382*params->a[4] - _t1384*params->a[5] - _t1386*params->a[6] - _t1388*params->a[7] - _t1390*params->a[8] - _t1392*params->a[9] + _t1395*params->a[10] + _t1398*_t1504 + _t1399*_t1504 + _t1402*_t1505 + _t1403*_t1505 + _t1404*_t1505 + _t1408*_t540 + _t1410*_t542 + _t1412*_t777 + _t1415*_t543 + _t1416*_t544 + _t1417*_t545 + _t1419*params->a[5] + _t1420*_t684 + _t1421*_t546 + _t1422*_t547 + _t1423*params->a[6] + _t1425*params->a[6] + _t1426*_t779 + _t1427*_t548 + _t1430*params->a[7] + _t1431*_t780 + _t1432*params->a[8] + _t1433*params->a[8] + _t1434*params->a[8] + _t1436*_t1506 + _t1437*_t1506 + _t1438*_t1506 + _t1439*_t1506 - _t1441*_t771 - _t1443*params->a[10] - _t1444*_t536 - _t1445*_t772 - _t1446*_t773 - _t1447*_t774 - _t1448*_t775 - _t1449*_t538 - _t1451*_t776 - _t1452*_t539 - _t1454*_t540 - _t1455*_t541 - _t1456*_t542 - _t1458*_t778 - _t1459*_t543 - _t1460*_t544 - _t1462*_t545 - _t1463*_t684 - _t1464*_t546 - _t1465*_t547 - _t1467*_t779 - _t1469*_t549 - _t1470*_t550 - _t1470*_t552 - _t1471*_t780 - _t1472*_t514*params->a[8] - _t1474*params->a[8] - _t1475*params->a[8] - _t1476*params->a[9] - _t1477*params->a[9] - _t1478*params->a[9] + _t1479*_t249 + _t1480*_t250 + _t1481*_t251 + _t1481*_t932 + _t1482*_t252 + _t1483*_t253 + _t1484*_t255 + _t1485*_t256 + _t1486*params->a[4] + _t1487*_t257 + _t1488*_t258 + _t1489*params->a[5] + _t1490*_t259 + _t1491*_t260 + _t1492*params->a[6] + _t1493*_t261 + _t1494*_t262 + _t1495*params->a[7] + _t1496*_t263 + _t1497*_t264 + _t1498*params->a[8] + _t1499*_t265 + _t1500*params->a[8] + _t1501*params->a[9] + _t1502*_t266 + _t1503*params->a[9]) + _t56*(3.7472167107754172e-7*_t1084*xc_powi(sigma_ss, 5)/xc_powr(n_s, 52, 3) - 0.1214425443429*_t126*_t1347 + 0.014948928345919193*_t1344*_t277 + 1.9014010399999999*_t1345*_t139 - 0.00012547056090473927*_t1346*_t569)) + (0.1e1 / 0.216e3)*_hc0[14]*_t122*_t57*_t8 + _hc0[9]*_t332*_t461*_t795 + (0.140e3 / 0.81e2)*_t132*_t284*_t57 - 0.2e1 / 0.3e1*_t133*_t934 - 0.1e1 / 0.9e1*_t175*_t796 - 0.56e2 / 0.27e2*_t175*_t797 - 0.4e1 / 0.9e1*_t175*_t799 + (0.4e1 / 0.3e1)*_t334*_t459 + (0.40e2 / 0.81e2)*_t337*_t340*_t57 + (0.1e1 / 0.6e1)*_t338*_t459));
  out[69] = d4f_dn_s4;
#endif
}

#else  /* re-inclusion: one graded body -> func_<order>_<spin> */
GPU_DEVICE_FUNCTION static inline void
FUNC_NAME(const xc_func_type *p, size_t ip, const double *rho, const double *sigma, const double *lapl, const double *tau, xc_mgga_out_params *out)
{
  assert(p->params != NULL);
  const mgga_x_m08_params *params = (const mgga_x_m08_params *)(p->params);
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